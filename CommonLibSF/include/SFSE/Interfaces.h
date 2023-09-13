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

	struct PluginVersionData
	{
	public:
		enum
		{
			kVersion = 1,
		};

		constexpr void PluginVersion(std::uint32_t a_version) noexcept { pluginVersion = a_version; }

		[[nodiscard]] constexpr std::uint32_t GetPluginVersion() const noexcept { return pluginVersion; }

		constexpr void PluginName(std::string_view a_plugin) noexcept { SetCharBuffer(a_plugin, std::span{ pluginName }); }

		[[nodiscard]] constexpr std::string_view GetPluginName() const noexcept { return std::string_view{ pluginName }; }

		constexpr void AuthorName(std::string_view a_name) noexcept { SetCharBuffer(a_name, std::span{ author }); }

		[[nodiscard]] constexpr std::string_view GetAuthorName() const noexcept { return std::string_view{ author }; }

		constexpr void UsesSigScanning(bool a_value) noexcept { addressIndependence = !a_value; }

		constexpr void UsesAddressLibrary(bool a_value) noexcept { addressIndependence = a_value; }

		constexpr void HasNoStructUse(bool a_value) noexcept { structureCompatibility = !a_value; }

		constexpr void IsLayoutDependent(bool a_value) noexcept { structureCompatibility = a_value; }

		constexpr void CompatibleVersions(std::initializer_list<REL::Version> a_versions) noexcept
		{
			// must be zero-terminated
			assert(a_versions.size() < std::size(compatibleVersions) - 1);
			std::ranges::transform(a_versions, std::begin(compatibleVersions), [](const REL::Version& a_version) noexcept { return a_version.pack(); });
		}

		constexpr void MinimumRequiredXSEVersion(REL::Version a_version) noexcept { xseMinimum = a_version.pack(); }

		[[nodiscard]] static const PluginVersionData* GetSingleton() noexcept;

		const std::uint32_t dataVersion{ kVersion };
		std::uint32_t       pluginVersion = 0;
		char                pluginName[256] = {};
		char                author[256] = {};
		std::uint32_t       addressIndependence;
		std::uint32_t       structureCompatibility;
		std::uint32_t       compatibleVersions[16] = {};
		std::uint32_t       xseMinimum = 0;
		const std::uint32_t reservedNonBreaking = 0;
		const std::uint32_t reservedBreaking = 0;

	private:
		static constexpr void SetCharBuffer(std::string_view a_src, std::span<char> a_dst) noexcept
		{
			assert(a_src.size() < a_dst.size());
			std::ranges::fill(a_dst, '\0');
			std::ranges::copy(a_src, a_dst.begin());
		}
	};

	static_assert(offsetof(PluginVersionData, dataVersion) == 0x000);
	static_assert(offsetof(PluginVersionData, pluginVersion) == 0x004);
	static_assert(offsetof(PluginVersionData, pluginName) == 0x008);
	static_assert(offsetof(PluginVersionData, author) == 0x108);
	static_assert(offsetof(PluginVersionData, addressIndependence) == 0x208);
	static_assert(offsetof(PluginVersionData, structureCompatibility) == 0x20C);
	static_assert(offsetof(PluginVersionData, compatibleVersions) == 0x210);
	static_assert(offsetof(PluginVersionData, xseMinimum) == 0x250);
	static_assert(offsetof(PluginVersionData, reservedNonBreaking) == 0x254);
	static_assert(offsetof(PluginVersionData, reservedBreaking) == 0x258);
	static_assert(sizeof(PluginVersionData) == 0x25C);
}  // namespace SFSE

#define SFSEPluginLoad(...) extern "C" [[maybe_unused]] __declspec(dllexport) bool SFSEPlugin_Load(__VA_ARGS__)
