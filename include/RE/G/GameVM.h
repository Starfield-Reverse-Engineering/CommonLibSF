#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTFreeList.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/C/CompiledScriptLoader.h"
#include "RE/H/HandlePolicy.h"
#include "RE/I/IClientVM.h"
#include "RE/I/IStackCallbackSaveInterface.h"
#include "RE/I/IVirtualMachine.h"
#include "RE/L/Logger.h"
#include "RE/O/ObjectBindPolicy.h"
#include "RE/P/Profiler.h"
#include "RE/R/RemoteDebugger.h"
#include "RE/S/SavePatcher.h"
#include "RE/S/SimpleAllocMemoryPagePolicy.h"

namespace RE
{
	struct InputEnableLayerDestroyedEvent;
	struct PositionPlayerEvent;
	struct TESFormDeleteEvent;
	struct TESFormIDRemapEvent;
	struct TESInitScriptEvent;
	struct TESResolveNPCTemplatesEvent;
	struct TESUniqueIDChangeEvent;

	namespace ModelReferenceEffectEvents
	{
		struct ReferenceEffectFinished;
	}

	namespace BSScript
	{
		struct StatsEvent;
		class IVMSaveLoadInterface;
		class IVMDebugInterface;
	}

	namespace GameScript
	{
		struct StatsEvent;
		struct UserLogEvent;

		class __declspec(novtable) DelayFunctor :
			public BSIntrusiveRefCounted  // 08
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__DelayFunctor };
			static constexpr auto VTABLE{ VTABLE::GameScript__DelayFunctor };

			enum class FunctorType
			{
				kMoveTo = 0,
				kMoveToOwnEditorLoc = 1,
				kDamageObject = 2,
				kEnable = 3,
				kDisable = 4,
				kDelete = 5,
				kSetPosition = 6,
				kSetAngle = 7,
				kSetMotionType = 8,
				kNonLatentDelete = 9,
				kMoveToPackLoc = 10,
				kSetScale = 11,
				kDropObject = 12,
				kAttachAshPile = 13,
				kForceAddRemoveRagdoll = 15,
				kApplyHavokImpulse = 16,
				kReset = 17,
				kSendPlayerToJail = 18,
				kAddItem = 19,
				kResurrect = 20,
				kCast = 21,
				kScrollCast = 22,
				kRemoveItem = 23,
				kWaitFor3D = 24,
				kPlayBink = 25,
				kMoveToNearestNavmeshLoc = 26,
				kClearDestruction = 27,
				//kWaitForResourceRecalc -- appears to have been removed
				kRemoveComponent = 29,
				kDropRef = 30,
				kPopPlayerTo = 31,
			};

			virtual ~DelayFunctor();  // 00

			// add
			[[nodiscard]] virtual BSScript::Variable operator()() = 0;                                                                                // 01
			[[nodiscard]] virtual bool               IsLatent() const = 0;                                                                            // 02
			[[nodiscard]] virtual bool               WantsRequeue() const { return false; }                                                           // 03
			[[nodiscard]] virtual FunctorType        GetType() const = 0;                                                                             // 04
			virtual bool                             SaveImpl(BSStorage& a_storage) const = 0;                                                        // 05
			virtual bool                             LoadImpl(const BSStorage& a_storage, std::uint32_t a_scriptSaveVersion, bool& a_dataValid) = 0;  // 06

			SF_HEAP_REDEFINE_NEW(DelayFunctor);

			// members
			std::uint32_t stackID;  // 0C
		};
		static_assert(sizeof(DelayFunctor) == 0x10);
	}

	class GameVM :
		public BSScript::IClientVM,                                                // 0000
		public BSScript::IStackCallbackSaveInterface,                              // 0008
		public BSTEventSink<BSScript::StatsEvent>,                                 // 0010
		public BSTEventSink<InputEnableLayerDestroyedEvent>,                       // 0018
		public BSTEventSink<PositionPlayerEvent>,                                  // 0020
		public BSTEventSink<TESFormDeleteEvent>,                                   // 0028
		public BSTEventSink<TESFormIDRemapEvent>,                                  // 0030
		public BSTEventSink<TESInitScriptEvent>,                                   // 0038
		public BSTEventSink<TESResolveNPCTemplatesEvent>,                          // 0040
		public BSTEventSink<TESUniqueIDChangeEvent>,                               // 0048
		public BSTEventSource<GameScript::StatsEvent>,                             // 0050
		public BSTEventSource<GameScript::UserLogEvent>,                           // 0078
		public BSTEventSink<ModelReferenceEffectEvents::ReferenceEffectFinished>,  // 00A0
		public BSTSingletonSDM<GameVM>                                             // 00A8
	{
	public:
		SF_RTTI_VTABLE(GameVM);

		~GameVM() override;  // 00

		// override (BSScript::IClientVM)
		bool IsVMFrozen() const override;    // 01
		void PreSave() override;             // 02
		void Unk_03() override { return; };  // 03

		// override (BSScript::IStackCallbackSaveInterface)
		bool SaveStackCallback(BSStorage& a_buffer, const BSTSmartPointer<BSScript::IStackCallbackFunctor>& a_callback) const override;                // 01
		bool LoadStackCallback(const BSStorage& a_buffer, bool& a_arg2, BSTSmartPointer<BSScript::IStackCallbackFunctor>& a_callback) const override;  // 02

		// override (BSTEventSink<BSScript::StatsEvent>)
		BSEventNotifyControl ProcessEvent(const BSScript::StatsEvent& a_event, BSTEventSource<BSScript::StatsEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<InputEnableLayerDestroyedEvent>)
		BSEventNotifyControl ProcessEvent(const InputEnableLayerDestroyedEvent& a_event, BSTEventSource<InputEnableLayerDestroyedEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<PositionPlayerEvent>)
		BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESFormDeleteEvent>)
		BSEventNotifyControl ProcessEvent(const TESFormDeleteEvent& a_event, BSTEventSource<TESFormDeleteEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESFormIDRemapEvent>)
		BSEventNotifyControl ProcessEvent(const TESFormIDRemapEvent& a_event, BSTEventSource<TESFormIDRemapEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESInitScriptEvent>)
		BSEventNotifyControl ProcessEvent(const TESInitScriptEvent& a_event, BSTEventSource<TESInitScriptEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESResolveNPCTemplatesEvent>)
		BSEventNotifyControl ProcessEvent(const TESResolveNPCTemplatesEvent& a_event, BSTEventSource<TESResolveNPCTemplatesEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESUniqueIDChangeEvent>)
		BSEventNotifyControl ProcessEvent(const TESUniqueIDChangeEvent& a_event, BSTEventSource<TESUniqueIDChangeEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<ModelReferenceEffectEvents::ReferenceEffectFinished>)
		BSEventNotifyControl ProcessEvent(const ModelReferenceEffectEvents::ReferenceEffectFinished& a_event, BSTEventSource<ModelReferenceEffectEvents::ReferenceEffectFinished>* a_dispatcher) override;  // 01

		[[nodiscard]] static GameVM* GetSingleton()
		{
			static REL::Relocation<GameVM**> singleton{ ID::GameVM::Singleton };
			return *singleton;
		}

		inline BSScript::IVirtualMachine* GetVM() const
		{
			return impl.get();
		}

		static void BindEverythingToScript(BSScript::IVirtualMachine** a_vm)
		{
			using func_t = decltype(&BindEverythingToScript);
			static REL::Relocation<func_t> func{ ID::GameVM::BindEverythingToScript };
			return func(a_vm);
		}

		// members
		std::uint64_t                                                                    unkB0;                          // 00B0
		std::uint64_t                                                                    unkB8;                          // 00B8
		std::uint64_t                                                                    unkC0;                          // 00C0
		std::uint64_t                                                                    unkC8;                          // 00C8
		std::uint64_t                                                                    unkD0;                          // 00D0
		BSTSmartPointer<BSScript::IVirtualMachine>                                       impl;                           // 00D8
		BSScript::IVMSaveLoadInterface*                                                  saveLoadInterface;              // 00E0
		BSScript::IVMDebugInterface*                                                     debugInterface;                 // 00E8
		BSScript::SimpleAllocMemoryPagePolicy                                            memoryPagePolicy;               // 00F0
		BSScript::CompiledScriptLoader                                                   scriptLoader;                   // 0120
		GameScript::Logger                                                               logger;                         // 0158
		GameScript::HandlePolicy                                                         handlePolicy;                   // 01E0
		GameScript::ObjectBindPolicy                                                     objectBindPolicy;               // 02A0
		BSTSmartPointer<BSScript::IStore>                                                scriptStore;                    // 03A0
		/*GameScript::FragmentSystem*/ std::byte                                         fragmentSystem[0x200];          // 03A8
		GameScript::Profiler                                                             profiler;                       // 05A8
		GameScript::RemoteDebugger                                                       remoteDebugger;                 // 06D8
		GameScript::SavePatcher                                                          savePatcher;                    // 07B0
		BSSpinLock                                                                       freezeLock;                     // 07B8
		bool                                                                             frozen;                         // 07C0
		BSSpinLock                                                                       vmTimeLock;                     // 07C4
		std::uint32_t                                                                    currentTime;                    // 07CC
		std::uint32_t                                                                    currentMenuModeTime;            // 07D0
		std::uint32_t                                                                    currentGameTime;                // 07D4
		bool                                                                             updateHasBeenRun;               // 07D8
		bool                                                                             saveLoad;                       // 07D9
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>                renderSafeFunctorPool1;         // 07E0
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>*/ std::byte renderSafeFunctorQueue1[0x28];  // 27F8
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>                renderSafeFunctorPool2;         // 2820
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>*/ std::byte renderSafeFunctorQueue2[0x28];  // 4838
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>                postRenderFunctorPool1;         // 4860
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>*/ std::byte postRenderFunctorQueue1[0x28];  // 6878
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>                postRenderFunctorPool2;         // 68A0
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>*/ std::byte postRenderFunctorQueue2[0x28];  // 88B8
		BSSpinLock                                                                       renderSafeQueueLock;            // 88E0
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* */ void*   renderSafeQueueToReadFrom;      // 88E8
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* */ void*   renderSafeQueueToWriteTo;       // 88F0
		BSSpinLock                                                                       postRenderQueueLock;            // 88F8
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* */ void*   postRenderQueueToReadFrom;      // 8900
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* */ void*   postRenderQueueToWriteTo;       // 8908
		BSSpinLock                                                                       userLogLock;                    // 8910
		/*BSTHashMap<BSFixedString, BSScript::ErrorLogger*>*/ std::byte                  userLogs[0x38];                 // 8918
		BSSpinLock                                                                       statsWarningLock;               // 8950
		std::uint32_t                                                                    initialSuspendOverageTime;      // 8958
		std::uint32_t                                                                    initialRunningOverageTime;      // 895C
		std::uint32_t                                                                    initialStackMemoryOverageTime;  // 8960
		std::uint32_t                                                                    lastWarningTime;                // 8964
		std::uint32_t                                                                    overflowFlags;                  // 8968
	};
	static_assert(sizeof(GameVM) == 0x8970);
}
