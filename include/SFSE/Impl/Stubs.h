#pragma once

namespace SFSE
{
	using PluginHandle = std::uint32_t;

	enum : PluginHandle
	{
		kInvalidPluginHandle = static_cast<PluginHandle>(-1)
	};

	namespace detail
	{
		struct PluginInfo
		{
			std::uint32_t infoVersion;
			const char*   name;
			std::uint32_t version;
		};

		struct SFSEInterface
		{
			std::uint32_t sfseVersion;
			std::uint32_t runtimeVersion;
			std::uint32_t interfaceVersion;
			void* (*QueryInterface)(std::uint32_t);
			PluginHandle (*GetPluginHandle)();
			const void* (*GetPluginInfo)(const char*);
		};

		struct SFSEMessagingInterface
		{
			std::uint32_t interfaceVersion;
			bool (*RegisterListener)(PluginHandle, const char*, void*);
			bool (*Dispatch)(PluginHandle, std::uint32_t, void*, std::uint32_t, const char*);
		};

		struct SFSETrampolineInterface
		{
			std::uint32_t interfaceVersion;
			void* (*AllocateFromBranchPool)(PluginHandle, std::size_t);
			void* (*AllocateFromLocalPool)(PluginHandle, std::size_t);
		};

		struct SFSEMenuInterface
		{
			std::uint32_t interfaceVersion;
			void (*Register)(void*);
		};

		struct SFSETaskInterface
		{
			std::uint32_t interfaceVersion;
			void (*AddTask)(void*);
			void (*AddPermanentTask)(void*);
		};
	}

	class ITaskDelegate
	{
	public:
		virtual void Run() = 0;
		virtual void Destroy() = 0;
	};
}
