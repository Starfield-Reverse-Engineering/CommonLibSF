#include "SFSE/API.h"
#include "SFSE/Logger.h"

namespace SFSE
{
	namespace detail
	{
		class APIStorage : public Singleton<APIStorage>
		{
		public:
			PluginHandle                       pluginHandle{ static_cast<PluginHandle>(-1) };
			std::uint32_t                      releaseIndex{};
			TrampolineInterface*               trampolineInterface{};
			MessagingInterface*                messagingInterface{};
			std::mutex                         apiLock;
			std::vector<std::function<void()>> apiInitRegs;
			bool                               apiInit{};
		};

		template <class T>
		T* QueryInterface(const LoadInterface* a_intfc, const std::uint32_t a_id)
		{
			auto result = static_cast<T*>(a_intfc->QueryInterface(a_id));
			if (result && result->Version() > T::kVersion)
				log::warn("{} interface definition is out of date"sv, typeid(T).name());

			return result;
		}
	}  // namespace detail

	void Init(const LoadInterface* a_intfc, const bool a_log) noexcept
	{
		stl_assert(a_intfc, "interface is null"sv);

		if (a_log)
			log::init();

		(void)REL::Module::get();

		const auto  storage = detail::APIStorage::GetSingleton();
		const auto& intfc = *a_intfc;

		const std::scoped_lock l{ storage->apiLock };
		if (!storage->apiInit) {
			storage->pluginHandle = intfc.GetPluginHandle();

			storage->messagingInterface = detail::QueryInterface<MessagingInterface>(a_intfc, LoadInterface::kMessaging);
			storage->trampolineInterface = detail::QueryInterface<TrampolineInterface>(a_intfc, LoadInterface::kTrampoline);

			storage->apiInit = true;
			auto& regs = storage->apiInitRegs;
			for (const auto& reg : regs)
				reg();

			regs.clear();
			regs.shrink_to_fit();
		}
	}

	void RegisterForAPIInitEvent(const std::function<void()> a_fn)
	{
		{
			const auto             storage = detail::APIStorage::GetSingleton();
			const std::scoped_lock l{ storage->apiLock };
			if (!storage->apiInit) {
				storage->apiInitRegs.push_back(a_fn);
				return;
			}
		}
		a_fn();
	}

	PluginHandle GetPluginHandle() noexcept { return detail::APIStorage::GetSingleton()->pluginHandle; }

	std::uint32_t GetReleaseIndex() noexcept { return detail::APIStorage::GetSingleton()->releaseIndex; }

	const TrampolineInterface* GetTrampolineInterface() noexcept { return detail::APIStorage::GetSingleton()->trampolineInterface; }

	const MessagingInterface* GetMessagingInterface() noexcept { return detail::APIStorage::GetSingleton()->messagingInterface; }

	Trampoline* GetTrampoline()
	{
		static Trampoline trampoline;
		return std::addressof(trampoline);
	}

	void AllocTrampoline(const std::size_t a_size, const bool a_trySFSEReserve)
	{
		const auto trampoline = GetTrampoline();
		if (const auto intfc = GetTrampolineInterface(); intfc && a_trySFSEReserve) {
			if (const auto memory = intfc->AllocateFromBranchPool(a_size)) {
				trampoline->set_trampoline(memory, a_size);
				return;
			}
		}
		trampoline->create(a_size);
	}
}  // namespace SFSE
