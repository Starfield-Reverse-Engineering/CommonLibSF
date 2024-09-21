#include "REL/ID.h"

#include "REX/W32/KERNEL32.h"

namespace REL
{
	namespace database
	{
		constexpr auto LookUpDir = "Data\\SFSE\\Plugins"sv;

		[[nodiscard]] std::uint64_t Offset2ID::operator()(std::size_t a_offset) const
		{
			const mapping_t elem{ 0, a_offset };
			const auto      it = std::ranges::lower_bound(
                _offset2id,
                elem,
                [](auto&& a_lhs, auto&& a_rhs) {
                    return a_lhs.offset < a_rhs.offset;
                });

			stl_assert(it != _offset2id.end(),
				"Failed to find the offset within the database: 0x{:08X}\n"
				"Compiled IDDatabase version: {}"sv,
				a_offset, std::to_underlying(kDatabaseVersion));

			return it->id;
		}

		bool memory_map::open(const stl::zwstring a_name, const std::size_t a_size)
		{
			close();

			REX::W32::ULARGE_INTEGER bytes;
			bytes.value = a_size;

			_mapping = REX::W32::OpenFileMappingW(
				REX::W32::FILE_MAP_READ | REX::W32::FILE_MAP_WRITE,
				false,
				a_name.data());

			if (!_mapping) {
				close();
				return false;
			}

			_view = REX::W32::MapViewOfFile(
				_mapping,
				REX::W32::FILE_MAP_READ | REX::W32::FILE_MAP_WRITE,
				0,
				0,
				bytes.value);

			if (!_view) {
				close();
				return false;
			}

			return true;
		}

		bool memory_map::create(const stl::zwstring a_name, const std::size_t a_size)
		{
			close();

			REX::W32::ULARGE_INTEGER bytes;
			bytes.value = a_size;

			_mapping = REX::W32::OpenFileMappingW(
				REX::W32::FILE_MAP_READ | REX::W32::FILE_MAP_WRITE,
				false,
				a_name.data());

			if (!_mapping) {
				_mapping = REX::W32::CreateFileMappingW(
					REX::W32::INVALID_HANDLE_VALUE,
					nullptr,
					REX::W32::PAGE_READWRITE,
					bytes.hi,
					bytes.lo,
					a_name.data());

				if (!_mapping) {
					return false;
				}
			}

			_view = REX::W32::MapViewOfFile(
				_mapping,
				REX::W32::FILE_MAP_READ | REX::W32::FILE_MAP_WRITE,
				0,
				0,
				bytes.value);

			if (!_view) {
				return false;
			}

			return true;
		}

		constexpr void memory_map::close()
		{
			if (_view) {
				REX::W32::UnmapViewOfFile(_view);
				_view = nullptr;
			}

			if (_mapping) {
				REX::W32::CloseHandle(_mapping);
				_mapping = nullptr;
			}
		}

		void header_t::read(istream_t& a_in)
		{
			std::uint32_t format{};
			a_in.readin(format);

			stl_assert(format == database::kDatabaseVersion,
				"Unsupported address library format: {}\n"
				"Compiled IDDatabase version: {}\n"
				"This means this script extender plugin is incompatible with the address "
				"library available for this version of the game, and thus does not support it."sv,
				format, std::to_underlying(database::kDatabaseVersion));

			std::uint32_t version[4]{};
			std::uint32_t nameLen{};
			a_in.readin(version);
			a_in.readin(nameLen);

			for (std::uint32_t i = 0; i < nameLen; ++i) {
				a_in.readin(_name[i]);
			}
			_name[nameLen] = '\0';

			a_in.readin(_pointerSize);
			a_in.readin(_addressCount);

			for (std::size_t i = 0; i < std::extent_v<decltype(version)>; ++i) {
				_version[i] = static_cast<std::uint16_t>(version[i]);
			}
		}
	}

	[[nodiscard]] std::size_t IDDatabase::id2offset(std::uint64_t a_id) const
	{
		const database::mapping_t elem{ a_id, 0 };
		const auto                it = std::ranges::lower_bound(
            _id2offset,
            elem,
            [](auto&& a_lhs, auto&& a_rhs) {
                return a_lhs.id < a_rhs.id;
            });

		stl_assert(it != _id2offset.end(),
			"Failed to find the id within the address library: {}\n"
			"Compiled IDDatabase version: {}\n"
			"This means this script extender plugin is incompatible with the address "
			"library for this version of the game, and thus does not support it."sv,
			a_id, std::to_underlying(database::kDatabaseVersion));

		return it->offset;
	}

	std::wstring IDDatabase::addresslib_filename()
	{
		const auto version = Module::get().version();
		// sfse only loads plugins from { runtimeDirectory + "Data\\SFSE\\Plugins" }
		auto file = std::filesystem::current_path();

		file /= std::format("{}\\versionlib-{}", database::LookUpDir, version.string("-"));

		_platform = Platform::kUnknown;
		if (REX::W32::GetModuleHandleW(L"steam_api64")) {
			_platform = Platform::kSteam;
			_is_steam = true;
		} else {
			_platform = Platform::kMsStore;
		}

		stl_assert(_platform != Platform::kUnknown,
			"Failed to identify game runtime platform,"
			"This means the address library is incompatible for this platform."sv);

		// steam version omits the suffix
		if (_platform != Platform::kSteam) {
			file += std::format("-{}", std::to_underlying(_platform));
		}
		file += ".bin";

		stl_assert(std::filesystem::exists(file),
			"Failed to find address library file: \n{}", file.string());

		return file.wstring();
	}

	void IDDatabase::load()
	{
		const auto version = Module::get().version();
		const auto file = addresslib_filename();
		load_file(file, version, true);
	}

	bool IDDatabase::load_file(const stl::zwstring a_filename, const Version a_version, const bool a_failOnError)
	{
		try {
			database::istream_t in(a_filename.data(), std::ios::in | std::ios::binary);
			database::header_t  header;
			header.read(in);

			if (header.version() != a_version) {
				stl::report_and_error(
					std::format(
						"Address library version mismatch.\n"
						"Read-in: {}"sv,
						header.version().string()),
					a_failOnError);
			}

			const auto mapname = stl::utf8_to_utf16(std::format(
				// kDatabaseVersion, runtimeVersion, runtimePlatform
				"CommonLibSF-Offsets-v{}-{}-{}",
				std::to_underlying(database::kDatabaseVersion),
				a_version.string("-"),
				std::to_underlying(_platform)));

			stl_assert(mapname.has_value(),
				"Failed to generate memory map name.");

			const auto byteSize = header.address_count() * sizeof(database::mapping_t);
			if (_mmap.open(mapname.value(), byteSize)) {
				_id2offset = { static_cast<database::mapping_t*>(_mmap.data()), header.address_count() };
			} else if (_mmap.create(mapname.value(), byteSize)) {
				_id2offset = { static_cast<database::mapping_t*>(_mmap.data()), header.address_count() };
				unpack_file(in, header, a_failOnError);
				std::ranges::sort(
					_id2offset,
					[](auto&& a_lhs, auto&& a_rhs) {
						return a_lhs.id < a_rhs.id;
					});
			} else {
				return stl::report_and_error("failed to create shared mapping"sv, a_failOnError);
			}
		} catch (const std::system_error&) {
			return stl::report_and_error(
				std::format(
					"Failed to locate an appropriate address library with the path: {}\n"
					"This means you are either missing the address library for this "
					"specific version of the game or running on unsupported platform.\n"
					"Please continue to the mod page for address library to download "
					"an appropriate version or platform. \nIf one is not available, "
					"then it is likely that address library has not yet added support "
					"for this version of the game or this platform.\n"
					"Current version: {}\n"
					"Current platform: {}"sv,
					stl::utf16_to_utf8(a_filename).value_or("<unknown filename>"s),
					a_version.string(),
					_is_steam ? "Steam" : "Microsoft Store"),
				a_failOnError);
		}
		return true;
	}

	bool IDDatabase::unpack_file(database::istream_t& a_in, const database::header_t& a_header, const bool a_failOnError)
	{
		std::uint8_t  type = 0;
		std::uint64_t id = 0;
		std::uint64_t offset = 0;
		std::uint64_t prevID = 0;
		std::uint64_t prevOffset = 0;
		for (auto& mapping : _id2offset) {
			a_in.readin(type);
			const auto lo = static_cast<std::uint8_t>(type & 0xF);
			const auto hi = static_cast<std::uint8_t>(type >> 4);

			switch (lo) {
			case 0:
				a_in.readin(id);
				break;
			case 1:
				id = prevID + 1;
				break;
			case 2:
				id = prevID + a_in.readout<std::uint8_t>();
				break;
			case 3:
				id = prevID - a_in.readout<std::uint8_t>();
				break;
			case 4:
				id = prevID + a_in.readout<std::uint16_t>();
				break;
			case 5:
				id = prevID - a_in.readout<std::uint16_t>();
				break;
			case 6:
				id = a_in.readout<std::uint16_t>();
				break;
			case 7:
				id = a_in.readout<std::uint32_t>();
				break;
			default:
				return stl::report_and_error("unhandled type"sv, a_failOnError);
			}

			const std::uint64_t tmp = (hi & 8) != 0 ? (prevOffset / a_header.pointer_size()) : prevOffset;

			switch (hi & 7) {
			case 0:
				a_in.readin(offset);
				break;
			case 1:
				offset = tmp + 1;
				break;
			case 2:
				offset = tmp + a_in.readout<std::uint8_t>();
				break;
			case 3:
				offset = tmp - a_in.readout<std::uint8_t>();
				break;
			case 4:
				offset = tmp + a_in.readout<std::uint16_t>();
				break;
			case 5:
				offset = tmp - a_in.readout<std::uint16_t>();
				break;
			case 6:
				offset = a_in.readout<std::uint16_t>();
				break;
			case 7:
				offset = a_in.readout<std::uint32_t>();
				break;
			default:
				return stl::report_and_error("unhandled type"sv, a_failOnError);
			}

			if ((hi & 8) != 0) {
				offset *= a_header.pointer_size();
			}

			mapping = { id, offset };

			prevOffset = offset;
			prevID = id;
		}
		return true;
	}

	IDDatabase IDDatabase::_instance;
}
