#pragma once

#include "SFSE/Impl/Stubs.h"

namespace RE
{
	class IMenu;
}

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
		enum InterfaceType : std::uint32_t
		{
			kInvalid = 0,
			kMessaging,
			kTrampoline,
			kMenu,

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

		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		enum MessageType : std::uint32_t
		{
			kPostLoad,
			kPostPostLoad,
			kPostDataLoad,
			kPostPostDataLoad,
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
		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t Version() const;

		[[nodiscard]] void* AllocateFromBranchPool(std::size_t a_size) const;
		[[nodiscard]] void* AllocateFromLocalPool(std::size_t a_size) const;

	private:
		[[nodiscard]] const detail::SFSETrampolineInterface* GetProxy() const;
	};

	class MenuInterface
	{
	public:
		using RegCallback = void(RE::IMenu* a_menu);

		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t Version() const;

		void Register(RegCallback* a_callback) const;

	private:
		[[nodiscard]] const detail::SFSEMenuInterface* GetProxy() const;
	};

	struct PluginInfo
	{
		enum Version : std::uint32_t
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
		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		constexpr void PluginVersion(const REL::Version a_version) noexcept { pluginVersion = a_version.pack(); }

		[[nodiscard]] constexpr REL::Version GetPluginVersion() const noexcept { return REL::Version::unpack(pluginVersion); }

		constexpr void PluginName(const std::string_view a_plugin) noexcept { SetCharBuffer(a_plugin, std::span{ pluginName }); }

		[[nodiscard]] constexpr std::string_view GetPluginName() const noexcept { return std::string_view{ pluginName }; }

		constexpr void AuthorName(const std::string_view a_name) noexcept { SetCharBuffer(a_name, std::span{ author }); }

		[[nodiscard]] constexpr std::string_view GetAuthorName() const noexcept { return std::string_view{ author }; }

		constexpr void UsesSigScanning(const bool a_value) noexcept { SetOrClearBit(addressIndependence, 1 << 0, a_value); }

		constexpr void UsesAddressLibrary(const bool a_value) noexcept { SetOrClearBit(addressIndependence, 1 << 1, a_value); }

		constexpr void HasNoStructUse(const bool a_value) noexcept { SetOrClearBit(structureCompatibility, 1 << 0, a_value); }

		constexpr void IsLayoutDependent(const bool a_value) noexcept { SetOrClearBit(structureCompatibility, 1 << 1, a_value); }

		constexpr void CompatibleVersions(std::initializer_list<REL::Version> a_versions) noexcept
		{
			// must be zero-terminated
			assert(a_versions.size() < std::size(compatibleVersions) - 1);
			std::ranges::transform(a_versions, std::begin(compatibleVersions), [](const REL::Version& a_version) noexcept {
				return a_version.pack();
			});
		}

		constexpr void MinimumRequiredXSEVersion(const REL::Version a_version) noexcept { xseMinimum = a_version.pack(); }

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

		static constexpr void SetOrClearBit(std::uint32_t& a_data, const std::uint32_t a_bit, const bool a_set) noexcept
		{
			if (a_set)
				a_data |= a_bit;
			else
				a_data &= ~a_bit;
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
}

#define SFSEPluginPreload(...) extern "C" [[maybe_unused]] __declspec(dllexport) bool SFSEPlugin_Preload(__VA_ARGS__)
#define SFSEPluginLoad(...) extern "C" [[maybe_unused]] __declspec(dllexport) bool SFSEPlugin_Load(__VA_ARGS__)
#define SFSEPluginVersion extern "C" [[maybe_unused]] __declspec(dllexport) constinit SFSE::PluginVersionData SFSEPlugin_Version
