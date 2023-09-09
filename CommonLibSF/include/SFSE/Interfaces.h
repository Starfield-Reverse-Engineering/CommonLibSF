#pragma once

#include "SFSE/Impl/Stubs.h"
#include "SFSE/Version.h"

namespace SFSE
{
	struct PluginInfo;

	class QueryInterface
	{
	public:
		[[nodiscard]] REL::Version  RuntimeVersion() const;
		[[nodiscard]] std::uint32_t SFSEVersion() const;

	protected:
		[[nodiscard]] const detail::SFSEInterface* GetProxy() const;
	};

	class LoadInterface : public QueryInterface
	{
	public:
		enum : std::uint32_t
		{
			kInvalid = 0,
			kMessaging,
			kTrampoline,

			kTotal
		};

		[[nodiscard]] PluginHandle GetPluginHandle() const;
		const PluginInfo*          GetPluginInfo(const char* a_name) const;
		[[nodiscard]] void*        QueryInterface(std::uint32_t a_id) const;
	};

	class MessagingInterface
	{
	public:
		struct Message
		{
			const char*   sender;
			std::uint32_t type;
			std::uint32_t dataLen;
			void*         data;
		};

		using EventCallback = std::add_pointer_t<void(Message* a_msg)>;

		enum
		{
			kVersion = 2
		};

		enum : std::uint32_t
		{
			kPostLoad,
			kPostPostLoad,
		};

		[[nodiscard]] std::uint32_t Version() const;

		bool Dispatch(std::uint32_t a_messageType, void* a_data, std::uint32_t a_dataLen, const char* a_receiver) const;
		bool RegisterListener(EventCallback a_callback) const;
		bool RegisterListener(const char* a_sender, EventCallback a_callback) const;

	protected:
		[[nodiscard]] const detail::SFSEMessagingInterface* GetProxy() const;
	};

	class TrampolineInterface
	{
	public:
		enum
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t Version() const;

		[[nodiscard]] void* AllocateFromBranchPool(std::size_t a_size) const;
		[[nodiscard]] void* AllocateFromLocalPool(std::size_t a_size) const;

	private:
		[[nodiscard]] const detail::SFSETrampolineInterface* GetProxy() const;
	};

	struct PluginInfo
	{
		enum
		{
			kVersion = 1
		};

		std::uint32_t infoVersion;
		const char*   name;
		std::uint32_t version;
	};

	//struct PluginVersionData
	//{
	//public:
	//	enum
	//	{
	//		kVersion = 1,
	//	};

	//	constexpr void PluginVersion(std::uint32_t a_version) noexcept
	//	{
	//		pluginVersion = a_version;
	//	}

	//	constexpr void PluginName(std::string_view a_plugin) noexcept
	//	{
	//		SetCharBuffer(a_plugin, std::span{ pluginName });
	//	}

	//	constexpr void AuthorName(std::string_view a_name) noexcept
	//	{
	//		SetCharBuffer(a_name, std::span{ author });
	//	}

	//	constexpr void UsesSigScanning(bool a_value) noexcept
	//	{
	//		addressIndependence = !a_value;
	//	}

	//	constexpr void UsesAddressLibrary(bool a_value) noexcept
	//	{
	//		addressIndependence = a_value;
	//	}

	//	constexpr void HasNoStructUse(bool a_value) noexcept
	//	{
	//		structureCompatibility = !a_value;
	//	}

	//	constexpr void IsLayoutDependent(bool a_value) noexcept
	//	{
	//		structureCompatibility = a_value;
	//	}

	//	constexpr void CompatibleVersions(std::initializer_list<REL::Version> a_versions) noexcept
	//	{
	//		// must be zero-terminated
	//		assert(a_versions.size() < std::size(compatibleVersions) - 1);
	//		std::ranges::transform(a_versions, std::begin(compatibleVersions),
	//		                       [](const REL::Version& a_version) noexcept { return a_version.pack(); });
	//	}

	//	constexpr void MinimumRequiredXSEVersion(REL::Version a_version) noexcept
	//	{
	//		xseMinimum = a_version.pack();
	//	}

	//	const std::uint32_t dataVersion{ kVersion };
	//	std::uint32_t       pluginVersion   = 0;
	//	char                pluginName[256] = {};
	//	char                author[256]     = {};
	//	std::uint32_t       addressIndependence;
	//	std::uint32_t       structureCompatibility;
	//	std::uint32_t       compatibleVersions[16] = {};
	//	std::uint32_t       xseMinimum             = 0;
	//	const std::uint32_t reservedNonBreaking    = 0;
	//	const std::uint32_t reservedBreaking       = 0;

	//private:
	//	static constexpr void SetCharBuffer(std::string_view a_src, std::span<char> a_dst) noexcept
	//	{
	//		assert(a_src.size() < a_dst.size());
	//		std::ranges::fill(a_dst, '\0');
	//		std::ranges::copy(a_src, a_dst.begin());
	//	}
	//};

	//static_assert(offsetof(PluginVersionData, dataVersion) == 0x000);
	//static_assert(offsetof(PluginVersionData, pluginVersion) == 0x004);
	//static_assert(offsetof(PluginVersionData, pluginName) == 0x008);
	//static_assert(offsetof(PluginVersionData, author) == 0x108);
	//static_assert(offsetof(PluginVersionData, addressIndependence) == 0x208);
	//static_assert(offsetof(PluginVersionData, structureCompatibility) == 0x20C);
	//static_assert(offsetof(PluginVersionData, compatibleVersions) == 0x210);
	//static_assert(offsetof(PluginVersionData, xseMinimum) == 0x250);
	//static_assert(offsetof(PluginVersionData, reservedNonBreaking) == 0x254);
	//static_assert(offsetof(PluginVersionData, reservedBreaking) == 0x258);
	//static_assert(sizeof(PluginVersionData) == 0x25C);

	struct PluginDeclaration
	{
	public:
		template <std::size_t N>
		class String
		{
		public:
			constexpr String() = default;

			constexpr String(std::string_view a_string) noexcept
			{
				std::span<char> buffer(_buffer, N);
				std::fill(buffer.begin(), buffer.end(), '\0');
				std::copy(a_string.begin(), a_string.end(), buffer.begin());
			}

			constexpr String(const char* a_string) noexcept
			{
				std::string_view string(a_string);
				std::span<char>  buffer(_buffer, N);
				std::fill(buffer.begin(), buffer.end(), '\0');
				std::copy(string.begin(), string.end(), buffer.begin());
			}

			[[nodiscard]] constexpr operator const char*() const noexcept
			{
				return _buffer;
			}

			[[nodiscard]] constexpr operator std::string_view() const noexcept
			{
				return _buffer;
			}

		private:
			char _buffer[N]{};
		};

		class VersionNumber
		{
		public:
			using value_type = typename REL::Version::value_type;

			constexpr VersionNumber(value_type a_major = 1, value_type a_minor = 0, value_type a_patch = 0, value_type a_build = 0) noexcept
				: _packed(REL::Version{ a_major, a_minor, a_patch, a_build }.pack())
			{}

			constexpr VersionNumber(REL::Version a_version) noexcept : _packed(a_version.pack())
			{}

			constexpr VersionNumber& operator=(REL::Version a_version) noexcept
			{
				_packed = a_version.pack();
				return *this;
			}

			[[nodiscard]] constexpr operator REL::Version() const noexcept
			{
				return REL::Version::unpack(_packed);
			}

			[[nodiscard]] constexpr explicit operator std::uint32_t() const noexcept
			{
				return _packed;
			}

		private:
			std::uint32_t _packed{};
		};

		struct PluginDeclarationInfo
		{
			/**
			 * The version number of the plugin.
			 */
			const VersionNumber Version{ 1, 0, 0, 0 };

			/**
			 * The plugin's name (maximum of 256 characters).
			 */
			const String<256> Name{};

			/**
			 * The name of the plugin's author (maximum of 256 characters).
			 */
			const String<256> Author{};

			/**
			 * A support email address for the plugin (maximum of 256 characters).
			 */
			const String<252> SupportEmail{};

			/**
			 * The minimum SFSE version required for the plugin; this should almost always be left <code>0</code>.
			 */
			const VersionNumber MinimumSFSEVersion{ 0 };
		};

		static_assert(offsetof(PluginDeclarationInfo, Version) == 0x000);
		static_assert(offsetof(PluginDeclarationInfo, Name) == 0x004);
		static_assert(offsetof(PluginDeclarationInfo, Author) == 0x104);
		static_assert(offsetof(PluginDeclarationInfo, SupportEmail) == 0x204);
		static_assert(offsetof(PluginDeclarationInfo, MinimumSFSEVersion) == 0x300);

		constexpr PluginDeclaration(PluginDeclarationInfo info) noexcept : _data(std::move(info))
		{}

		[[nodiscard]] constexpr REL::Version GetVersion() const noexcept
		{
			return _data.Version;
		}

		[[nodiscard]] constexpr std::string_view GetName() const noexcept
		{
			return _data.Name;
		}

		[[nodiscard]] constexpr std::string_view GetAuthor() const noexcept
		{
			return _data.Author;
		}

		[[nodiscard]] constexpr std::string_view GetSupportEmail() const noexcept
		{
			return _data.SupportEmail;
		}

		[[nodiscard]] constexpr REL::Version GetMinimumSFSEVersion() const noexcept
		{
			return _data.MinimumSFSEVersion;
		}

		[[nodiscard]] static const PluginDeclaration* GetSingleton() noexcept;

	private:
		enum
		{
			kVersion = 1,
		};

		[[maybe_unused]] const std::uint32_t         _dataVersion{ kVersion };
		[[maybe_unused]] const PluginDeclarationInfo _data;
	};

	static_assert(sizeof(PluginDeclaration) == 0x308);
} // namespace SFSE

#define SFSEPluginInfo(...)                                                                                                          \
	extern "C" [[maybe_unused]] __declspec(dllexport) constinit ::SFSE::PluginDeclaration SFSEPlugin_Version({ __VA_ARGS__ });       \
	extern "C" [[maybe_unused]] __declspec(dllexport) bool SFSEPlugin_Query(::SFSE::QueryInterface*, ::SFSE::PluginInfo* pluginInfo) \
	{                                                                                                                                \
		pluginInfo->infoVersion = ::SFSE::PluginInfo::kVersion;                                                                      \
		pluginInfo->name        = SFSEPlugin_Version.GetName().data();                                                               \
		pluginInfo->version     = static_cast<std::uint32_t>(SFSEPlugin_Version.GetVersion().pack());                                \
		return true;                                                                                                                 \
	}

#define SFSEPluginLoad(...) extern "C" [[maybe_unused]] __declspec(dllexport) bool SFSEPlugin_Load(__VA_ARGS__)
