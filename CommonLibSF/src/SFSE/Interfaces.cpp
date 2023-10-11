#include "SFSE/Interfaces.h"

#include "SFSE/API.h"
#include "SFSE/Logger.h"

namespace SFSE
{
	REL::Version QueryInterface::RuntimeVersion() const
	{
		const auto packed = GetProxy()->runtimeVersion;
		const auto major = static_cast<std::uint16_t>((packed & 0xFF000000) >> 24);
		const auto minor = static_cast<std::uint16_t>((packed & 0x00FF0000) >> 16);
		const auto revision = static_cast<std::uint16_t>((packed & 0x0000FFF0) >> 4);
		const auto build = static_cast<std::uint16_t>((packed & 0x0000000F) >> 0);
		return { major, minor, revision, build };
	}

	std::uint32_t QueryInterface::SFSEVersion() const
	{
		return GetProxy()->sfseVersion;
	}

	const detail::SFSEInterface* QueryInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SFSEInterface*>(this);
	}

	PluginHandle LoadInterface::GetPluginHandle() const
	{
		return GetProxy()->GetPluginHandle();
	}

	const PluginInfo* LoadInterface::GetPluginInfo(const char* a_name) const
	{
		return static_cast<const PluginInfo*>(GetProxy()->GetPluginInfo(a_name));
	}

	void* LoadInterface::QueryInterface(const std::uint32_t a_id) const
	{
		return GetProxy()->QueryInterface(a_id);
	}

	std::uint32_t MessagingInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}

	bool MessagingInterface::Dispatch(const std::uint32_t a_messageType, void* a_data, const std::uint32_t a_dataLen, const char* a_receiver) const
	{
		const auto result = GetProxy()->Dispatch(GetPluginHandle(), a_messageType, a_data, a_dataLen, a_receiver);
		if (!result) {
			log::error("Failed to dispatch message to {}", (a_receiver ? a_receiver : "all listeners"));
		}

		return result;
	}

	bool MessagingInterface::RegisterListener(const EventCallback a_callback) const
	{
		return RegisterListener("SFSE", a_callback);
	}

	bool MessagingInterface::RegisterListener(const char* a_sender, const EventCallback a_callback) const
	{
		const auto result = GetProxy()->RegisterListener(GetPluginHandle(), a_sender, std::bit_cast<void*>(a_callback));
		if (!result) {
			log::error("Failed to register messaging listener for {}", a_sender);
		}
		return result;
	}

	const detail::SFSEMessagingInterface* MessagingInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SFSEMessagingInterface*>(this);
	}

	std::uint32_t TrampolineInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}

	void* TrampolineInterface::AllocateFromBranchPool(const std::size_t a_size) const
	{
		return GetProxy()->AllocateFromBranchPool(GetPluginHandle(), a_size);
	}

	void* TrampolineInterface::AllocateFromLocalPool(const std::size_t a_size) const
	{
		return GetProxy()->AllocateFromLocalPool(GetPluginHandle(), a_size);
	}

	const detail::SFSETrampolineInterface* TrampolineInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SFSETrampolineInterface*>(this);
	}

	std::uint32_t MenuInterface::Version() const
	{
		return GetProxy()->interfaceVersion;
	}

	void MenuInterface::Register(RegCallback* a_callback) const
	{
		return GetProxy()->Register(reinterpret_cast<void*>(a_callback));
	}

	const detail::SFSEMenuInterface* MenuInterface::GetProxy() const
	{
		assert(this);
		return reinterpret_cast<const detail::SFSEMenuInterface*>(this);
	}

	const PluginVersionData* PluginVersionData::GetSingleton() noexcept
	{
		return reinterpret_cast<const PluginVersionData*>(WinAPI::GetProcAddress(WinAPI::GetCurrentModule(), "SFSEPlugin_Version"));
	}
}
