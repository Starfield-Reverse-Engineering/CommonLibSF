#include "REL/Version.h"

namespace REL
{
	constexpr Version::Version(const std::string_view a_version)
	{
		std::array<value_type, 4> powers{ 1, 1, 1, 1 };
		std::size_t               position{};
		for (const auto& c : a_version) {
			if (c == '.') {
				if (++position == powers.size()) {
					throw std::invalid_argument("Too many parts in version number.");
				}
			} else {
				powers[position] *= 10;
			}
		}
		position = 0;
		for (const auto& c : a_version) {
			if (c == '.') {
				++position;
			} else if (c < '0' || c > '9') {
				throw std::invalid_argument("Invalid character in version number.");
			} else {
				powers[position] /= 10;
				_impl[position] += static_cast<value_type>((c - '0') * powers[position]);
			}
		}
	}

	[[nodiscard]] std::optional<Version> get_file_version(const stl::zwstring a_filename)
	{
		std::uint32_t     dummy{};
		std::vector<char> buf(WinAPI::GetFileVersionInfoSize(a_filename.data(), std::addressof(dummy)));
		if (buf.empty()) {
			return std::nullopt;
		}

		if (!WinAPI::GetFileVersionInfo(a_filename.data(), 0, buf.size(), buf.data())) {
			return std::nullopt;
		}

		void*         verBuf{};
		std::uint32_t verLen{};
		if (!WinAPI::VerQueryValue(buf.data(), L"\\StringFileInfo\\040904B0\\ProductVersion", std::addressof(verBuf), std::addressof(verLen))) {
			return std::nullopt;
		}

		Version             version;
		std::wistringstream ss(std::wstring(static_cast<const wchar_t*>(verBuf), verLen));
		std::wstring        token;
		for (std::size_t i = 0; i < 4 && std::getline(ss, token, L'.'); ++i) {
			version[i] = static_cast<std::uint16_t>(std::stoi(token));
		}

		return version;
	}
}
