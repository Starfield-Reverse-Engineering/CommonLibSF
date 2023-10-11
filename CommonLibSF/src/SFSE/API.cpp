#include "SFSE/API.h"

#include "SFSE/Logger.h"

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

			PluginHandle pluginHandle{ static_cast<PluginHandle>(-1) };

			TrampolineInterface* trampolineInterface{};
			MessagingInterface*  messagingInterface{};
			MenuInterface*       menuInterface{};

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

		if (a_log)
			log::init();

		(void)REL::Module::get();

		auto&       storage = detail::APIStorage::get();
		const auto& intfc = *a_intfc;

		const std::scoped_lock l(storage.apiLock);
		if (!storage.apiInit) {
			storage.pluginHandle = intfc.GetPluginHandle();

			storage.messagingInterface = detail::QueryInterface<MessagingInterface>(a_intfc, LoadInterface::kMessaging);
			storage.trampolineInterface = detail::QueryInterface<TrampolineInterface>(a_intfc, LoadInterface::kTrampoline);
			storage.menuInterface = detail::QueryInterface<MenuInterface>(a_intfc, LoadInterface::kMenu);

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

	Trampoline& GetTrampoline()
	{
		static Trampoline trampoline;
		return trampoline;
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
}
