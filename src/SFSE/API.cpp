#include "SFSE/API.h"

#include "SFSE/Logger.h"
#include "SFSE/Trampoline.h"

namespace SFSE
{
	namespace detail
	{
		struct APIStorage
		{
		public:
			[[nodiscard]] static APIStorage& get() noexcept
			{
				static APIStorage singleton;
				return singleton;
			}

			std::string_view pluginName{};
			std::string_view pluginAuthor{};
			REL::Version     pluginVersion{};

			PluginHandle pluginHandle{ static_cast<PluginHandle>(-1) };

			TrampolineInterface* trampolineInterface{};
			MessagingInterface*  messagingInterface{};
			MenuInterface*       menuInterface{};
			TaskInterface*       taskInterface{};

			std::mutex                         apiLock;
			std::vector<std::function<void()>> apiInitRegs;
			bool                               apiInit{};

		private:
			APIStorage() noexcept = default;

			~APIStorage() noexcept = default;

			constexpr APIStorage(const APIStorage&) = delete;

			constexpr APIStorage(APIStorage&&) = delete;

			constexpr APIStorage& operator=(const APIStorage&) = delete;

			constexpr APIStorage& operator=(APIStorage&&) = delete;
		};

		template <class T>
		constexpr T* QueryInterface(const LoadInterface* a_intfc, const std::uint32_t a_id)
		{
			auto result = static_cast<T*>(a_intfc->QueryInterface(a_id));
			if (result && result->Version() > T::kVersion) {
				log::warn("interface definition is out of date"sv);
			}
			return result;
		}
	}

	void Init(const LoadInterface* a_intfc, const bool a_log) noexcept
	{
		stl_assert(a_intfc, "interface is null"sv);

		(void)REL::Module::get();
		(void)REL::IDDatabase::get();

		auto&       storage = detail::APIStorage::get();
		const auto& intfc = *a_intfc;

		const std::scoped_lock l(storage.apiLock);
		if (const auto pluginVersionData = PluginVersionData::GetSingleton()) {
			storage.pluginName = pluginVersionData->GetPluginName();
			storage.pluginAuthor = pluginVersionData->GetAuthorName();
			storage.pluginVersion = pluginVersionData->GetPluginVersion();
		}

		if (a_log) {
			log::init();
			log::info("{} v{}"sv, GetPluginName(), GetPluginVersion());
		}

		if (!storage.apiInit) {
			storage.pluginHandle = intfc.GetPluginHandle();

			storage.messagingInterface = detail::QueryInterface<MessagingInterface>(a_intfc, LoadInterface::kMessaging);
			storage.trampolineInterface = detail::QueryInterface<TrampolineInterface>(a_intfc, LoadInterface::kTrampoline);
			storage.menuInterface = detail::QueryInterface<MenuInterface>(a_intfc, LoadInterface::kMenu);
			storage.taskInterface = detail::QueryInterface<TaskInterface>(a_intfc, LoadInterface::kTask);

			storage.apiInit = true;
			auto& regs = storage.apiInitRegs;
			for (const auto& reg : regs) {
				reg();
			}
			regs.clear();
			regs.shrink_to_fit();
		}
	}

	void RegisterForAPIInitEvent(const std::function<void()>& a_fn)
	{
		{
			auto&                  storage = detail::APIStorage::get();
			const std::scoped_lock l(storage.apiLock);
			if (!storage.apiInit) {
				storage.apiInitRegs.push_back(a_fn);
				return;
			}
		}

		a_fn();
	}

	std::string_view GetPluginName() noexcept
	{
		return detail::APIStorage::get().pluginName;
	}

	std::string_view GetPluginAuthor() noexcept
	{
		return detail::APIStorage::get().pluginAuthor;
	}

	REL::Version GetPluginVersion() noexcept
	{
		return detail::APIStorage::get().pluginVersion;
	}

	PluginHandle GetPluginHandle() noexcept
	{
		return detail::APIStorage::get().pluginHandle;
	}

	const TrampolineInterface* GetTrampolineInterface() noexcept
	{
		return detail::APIStorage::get().trampolineInterface;
	}

	const MessagingInterface* GetMessagingInterface() noexcept
	{
		return detail::APIStorage::get().messagingInterface;
	}

	const MenuInterface* GetMenuInterface() noexcept
	{
		return detail::APIStorage::get().menuInterface;
	}

	const TaskInterface* GetTaskInterface() noexcept
	{
		return detail::APIStorage::get().taskInterface;
	}

	void AllocTrampoline(const std::size_t a_size, const bool a_trySFSEReserve)
	{
		auto& trampoline = GetTrampoline();
		if (const auto intfc = GetTrampolineInterface(); intfc && a_trySFSEReserve) {
			const auto memory = intfc->AllocateFromBranchPool(a_size);
			if (memory) {
				trampoline.set_trampoline(memory, a_size);
				return;
			}
		}

		trampoline.create(a_size);
	}

	struct PapyrusRegistrationHook
	{
		typedef void (*call_t)(RE::BSScript::IVirtualMachine**);

		PapyrusRegistrationHook(bool a_trySFSEReserve)
		{
			static constexpr size_t hookSize{ 14 };

			if (allocated) {
				return;
			}

			if (const auto intfc = GetTrampolineInterface(); intfc && a_trySFSEReserve) {
				const auto memory = intfc->AllocateFromBranchPool(hookSize);
				if (memory) {
					trampoline.set_trampoline(memory, hookSize);
					allocated = true;
				}
			}

			if (!allocated) {
				trampoline.create(hookSize);
			}

			// Call to GameVM::BindEverythingToScript(IVirtualMachine**) from GameVM::GameVM()
			static REL::Relocation<uintptr_t> hookLoc{ REL::ID(169912), 0x514 };
			func = reinterpret_cast<call_t>(trampoline.write_call<5>(hookLoc.address(), &thunk));
		}

		static void thunk(RE::BSScript::IVirtualMachine** a_vm)
		{
			func(a_vm);
			if (callback != nullptr) {
				callback(a_vm);
			}
		}

		inline static bool                                                 allocated{ false };
		inline static call_t                                               func;
		inline static std::function<void(RE::BSScript::IVirtualMachine**)> callback;
		Trampoline                                                         trampoline;
	};

	void SetPapyrusCallback(const std::function<void(RE::BSScript::IVirtualMachine**)> a_callback, bool a_trySFSEReserve)
	{
		static PapyrusRegistrationHook hook{ a_trySFSEReserve };
		PapyrusRegistrationHook::callback = a_callback;
	}
}
