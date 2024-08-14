#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/T/TESObjectCELL.h"

namespace RE
{
	enum class BSEventNotifyControl : std::uint32_t
	{
		kContinue,
		kStop
	};
	using EventResult = BSEventNotifyControl;

	namespace BSTEventDetail
	{
		class SinkBase
		{
		public:
			virtual ~SinkBase() = 0;
		};

		class SourceBase
		{
		public:
			virtual ~SourceBase() = 0;
		};

		inline SinkBase::~SinkBase() = default;
		inline SourceBase::~SourceBase() = default;
	}

	template <class>
	class BSTEventSource;

	template <class Event>
	class BSTEventSink : public BSTEventDetail::SinkBase
	{
	public:
		~BSTEventSink() override = default;  // 00

		// add
		virtual BSEventNotifyControl ProcessEvent(const Event& a_event, BSTEventSource<Event>* a_source) = 0;  // 01
	};
	static_assert(sizeof(BSTEventSink<void*>) == 0x8);

	template <class Event>
	class BSTEventSource : public BSTEventDetail::SourceBase
	{
	public:
		~BSTEventSource() override = default;  // 00

		void Notify(void* a_event)
		{
			using func_t = decltype(&BSTEventSource::Notify);
			REL::Relocation<func_t> func{ ID::BSTEventSource::Notify };
			return func(this, a_event);
		}
		void RegisterSink(BSTEventSink<Event>* a_sink)
		{
			using func_t = decltype(&BSTEventSource::RegisterSink);
			REL::Relocation<func_t> func{ ID::BSTEventSource::RegisterSink };
			return func(this, a_sink);
		}
		void UnregisterSink(BSTEventSink<Event>* a_sink)
		{
			using func_t = decltype(&BSTEventSource::UnregisterSink);
			REL::Relocation<func_t> func{ ID::BSTEventSource::UnregisterSink };
			return func(this, a_sink);
		}

		// members
		BSTArray<BSTEventSink<Event>> sinks;  // 08
		std::uint32_t                 unk18;  // 18
		std::uint32_t                 unk1C;  // 1C
		std::uint32_t                 unk20;  // 20
		std::uint32_t                 unk24;  // 24
	};
	static_assert(sizeof(BSTEventSource<void*>) == 0x28);

	class BSTGlobalEvent
	{
	public:
		template <class Event>
		class EventSource :
			public BSTSingletonImplicit<EventSource<Event>>,
			public BSTEventSource<Event>
		{
		public:
			~EventSource() override;  // 00

			virtual BSEventNotifyControl ProcessEvent(const Event& a_event, BSTEventSource<Event>* a_source);  // 01
		};

		virtual ~BSTGlobalEvent();  // 00
	};
	static_assert(sizeof(BSTGlobalEvent) == 0x08);

	template <class Event>
	class BSTEventSourceLazyInit
	{
	public:
		// members
		BSTEventSource<Event>* eventSource;  // 00
		std::uint64_t          unk08;        // 08
	};
	static_assert(sizeof(BSTEventSourceLazyInit<void*>) == 0x10);




	namespace Events
	{
		struct TESLoadGameEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESLoadGameEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(1868757) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESLoadGameEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESPlayerFollowerWarpEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESPlayerFollowerWarpEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107186) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESPlayerFollowerWarpEvent>* (*)()>(addr);
				return func();
			}
		};
		struct DataMenu_Reopened
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DataMenu_Reopened>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141474) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DataMenu_Reopened>* (*)()>(addr);
				return func();
			}
		};
		struct PhotoMode_RefineSetting
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PhotoMode_RefineSetting>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(1536789) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PhotoMode_RefineSetting>* (*)()>(addr);
				return func();
			}
		};
		struct PhotoMode_StepperChanged
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PhotoMode_StepperChanged>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139739) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PhotoMode_StepperChanged>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_Initialize
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_Initialize>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139644) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_Initialize>* (*)()>(addr);
				return func();
			}
		};
		struct SaveLoadEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SaveLoadEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(129747) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SaveLoadEvent>* (*)()>(addr);
				return func();
			}
		};
		struct PlayerSetWeaponStateEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PlayerSetWeaponStateEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138719) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerSetWeaponStateEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESEquipEvent
		{
		public:
			RE::Actor*                                              actor;
			uint32_t                                                itemBaseFormID;
			uint32_t                                                unk01;
			std::uint16_t                                           unk02;
			bool                                                    bEquipped;
			[[nodiscard]] static RE::BSTEventSource<TESEquipEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107161) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESEquipEvent>* (*)()>(addr);
				return func();
			}
		};
		struct RuntimeComponentDBFactory
		{
			struct ReferenceDetach
			{
			public:
				RE::TESObjectREFR*                                                                   referece;
				[[nodiscard]] static RE::BSTEventSource<RuntimeComponentDBFactory::ReferenceDetach>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(77128) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<RuntimeComponentDBFactory::ReferenceDetach>* (*)()>(addr);
					return func();
				}
			};
			struct ReferenceSet3d
			{
			public:
				RE::TESObjectREFR*                                                                  referece;
				[[nodiscard]] static RE::BSTEventSource<RuntimeComponentDBFactory::ReferenceSet3d>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(88599) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<RuntimeComponentDBFactory::ReferenceSet3d>* (*)()>(addr);
					return func();
				}
			};
		};
		struct PlayerFastTravel
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<PlayerFastTravel::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(153668) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerFastTravel::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct PlayerSneakingChangeEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PlayerSneakingChangeEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(129185) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerSneakingChangeEvent>* (*)()>(addr);
				return func();
			}
		};
		struct HUDRolloverActivationButtonEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<HUDRolloverActivationButtonEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(133042) };
				uintptr_t                  addr = funcPtr.address();
				const auto func = reinterpret_cast<RE::BSTEventSource<HUDRolloverActivationButtonEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESCombatEvent
		{
		public:
			RE::TESObjectREFR*                                       source;
			RE::TESObjectREFR*                                       target;
			uint32_t                                                 state;
			[[nodiscard]] static RE::BSTEventSource<TESCombatEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107148) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESCombatEvent>* (*)()>(addr);
				return func();
			}
		};
		struct UpdateActivateListenerEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<UpdateActivateListenerEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132635) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<UpdateActivateListenerEvent>* (*)()>(addr);
				return func();
			}
		};
		struct HUDModeEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<HUDModeEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(133039) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<HUDModeEvent>* (*)()>(addr);
				return func();
			}
		};
		struct FirstThirdPersonSwitch
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<FirstThirdPersonSwitch::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(34458) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<FirstThirdPersonSwitch::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct HideSubtitleEvent
		{
		public:
			struct Event
			{
				[[nodiscard]] static RE::BSTEventSource<HideSubtitleEvent::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(133630) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<HideSubtitleEvent::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct ShowSubtitleEvent
		{
		public:
			struct Event
			{
				[[nodiscard]] static RE::BSTEventSource<ShowSubtitleEvent::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(133631) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<ShowSubtitleEvent::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct LocationTextEvent
		{
		public:
			struct Event
			{
				[[nodiscard]] static RE::BSTEventSource<LocationTextEvent::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(138717) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<LocationTextEvent::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct TraitDiscoveryTextEvent
		{
		public:
			struct Event
			{
				[[nodiscard]] static RE::BSTEventSource<TraitDiscoveryTextEvent::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(138718) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<TraitDiscoveryTextEvent::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct TESHarvestEvent
		{
		public:
			struct ItemHarvested
			{
				[[nodiscard]] static RE::BSTEventSource<TESHarvestEvent::ItemHarvested>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(86518) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<TESHarvestEvent::ItemHarvested>* (*)()>(addr);
					return func();
				}
			};
		};
		struct HUDNotification_MissionActiveWidgetUpdate
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<HUDNotification_MissionActiveWidgetUpdate>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138666) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<HUDNotification_MissionActiveWidgetUpdate>* (*)()>(addr);
				return func();
			}
		};
		struct LevelUp_OnWidgetShown
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<LevelUp_OnWidgetShown>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138448) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<LevelUp_OnWidgetShown>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_PhotoMode
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_PhotoMode>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139646) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_PhotoMode>* (*)()>(addr);
				return func();
			}
		};
		struct ShipEditor_SystemSelected
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipEditor_SystemSelected>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(75542) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipEditor_SystemSelected>* (*)()>(addr);
				return func();
			}
		};
		struct CellAttachDetachEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CellAttachDetachEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(84784) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CellAttachDetachEvent>* (*)()>(addr);
				return func();
			}
		};
		struct BGSPlanet
		{
			struct PlayerKnowledgeFlagSetEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<BGSPlanet::PlayerKnowledgeFlagSetEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(92501) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<BGSPlanet::PlayerKnowledgeFlagSetEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct StarMap
		{
			struct PlanetTraitKnownEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<StarMap::PlanetTraitKnownEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(92502) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMap::PlanetTraitKnownEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct TESQuestRewardEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESQuestRewardEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(95698) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESQuestRewardEvent>* (*)()>(addr);
				return func();
			}
		};
		struct BGSSceneActionPlayerDialogue
		{
			struct ActionEndEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<BGSSceneActionPlayerDialogue::ActionEndEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(100215) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<BGSSceneActionPlayerDialogue::ActionEndEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct AutoLoadDoorRolloverEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<AutoLoadDoorRolloverEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(103703) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<AutoLoadDoorRolloverEvent>* (*)()>(addr);
				return func();
			}
		};
		struct ClearQuickContainerEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ClearQuickContainerEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(103704) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ClearQuickContainerEvent>* (*)()>(addr);
				return func();
			}
		};
		struct PickRefUpdateEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PickRefUpdateEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(119433) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PickRefUpdateEvent>* (*)()>(addr);
				return func();
			}
		};
		struct Workshop
		{
			struct CargoLinkAddedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::CargoLinkAddedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119421) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::CargoLinkAddedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct CargoLinkTargetChangedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::CargoLinkTargetChangedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119422) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::CargoLinkTargetChangedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct EnterOutpostBeaconModeEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::EnterOutpostBeaconModeEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119423) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::EnterOutpostBeaconModeEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ItemGrabbedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::ItemGrabbedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119424) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::ItemGrabbedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ItemMovedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::ItemMovedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119425) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::ItemMovedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ItemPlacedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::ItemPlacedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119426) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::ItemPlacedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ItemProducedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::ItemProducedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119427) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::ItemProducedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ItemRemovedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::ItemRemovedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119428) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::ItemRemovedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ItemRepairedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::ItemRepairedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119429) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::ItemRepairedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ItemScrappedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::ItemScrappedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119430) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::ItemScrappedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct OutpostNameChangedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::OutpostNameChangedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119431) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::OutpostNameChangedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct OutpostPlacedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::OutpostPlacedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119432) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::OutpostPlacedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct PlacementStatusEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::PlacementStatusEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119434) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::PlacementStatusEvent>* (*)()>(addr);
					return func();
				}
			};
			struct PowerOffEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::PowerOffEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119435) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::PowerOffEvent>* (*)()>(addr);
					return func();
				}
			};
			struct PowerOnEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::PowerOnEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119436) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::PowerOnEvent>* (*)()>(addr);
					return func();
				}
			};
			struct SnapBehaviorCycledEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::SnapBehaviorCycledEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119437) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::SnapBehaviorCycledEvent>* (*)()>(addr);
					return func();
				}
			};
			struct WorkshopFlyCameraEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::WorkshopFlyCameraEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119438) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::WorkshopFlyCameraEvent>* (*)()>(addr);
					return func();
				}
			};
			struct WorkshopItemPlacedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::WorkshopItemPlacedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119439) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::WorkshopItemPlacedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct WorkshopModeEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::WorkshopModeEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119440) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::WorkshopModeEvent>* (*)()>(addr);
					return func();
				}
			};
			struct WorkshopOutputLinkEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::WorkshopOutputLinkEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119441) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::WorkshopOutputLinkEvent>* (*)()>(addr);
					return func();
				}
			};
			struct WorkshopStatsChangedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::WorkshopStatsChangedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119442) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::WorkshopStatsChangedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct WorkshopUpdateStatsEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Workshop::WorkshopUpdateStatsEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(119443) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Workshop::WorkshopUpdateStatsEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct ShipCameraStateToggled
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipCameraStateToggled>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(120266) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipCameraStateToggled>* (*)()>(addr);
				return func();
			}
		};
		struct PlayerControls
		{
			struct PlayerJumpPressEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<PlayerControls::PlayerJumpPressEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(129146) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerControls::PlayerJumpPressEvent>* (*)()>(addr);
					return func();
				}
			};
			struct PlayerJumpReleaseEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<PlayerControls::PlayerJumpReleaseEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(129147) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerControls::PlayerJumpReleaseEvent>* (*)()>(addr);
					return func();
				}
			};
			struct PlayerZeroGSprintJustPressedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<PlayerControls::PlayerZeroGSprintJustPressedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(129188) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerControls::PlayerZeroGSprintJustPressedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct PlayerIronSightsEndEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<PlayerControls::PlayerIronSightsEndEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(129341) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerControls::PlayerIronSightsEndEvent>* (*)()>(addr);
					return func();
				}
			};
			struct PlayerIronSightsStartEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<PlayerControls::PlayerIronSightsStartEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(129342) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerControls::PlayerIronSightsStartEvent>* (*)()>(addr);
					return func();
				}
			};
			struct PlayerZeroGSprintReleasedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<PlayerControls::PlayerZeroGSprintReleasedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(129189) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerControls::PlayerZeroGSprintReleasedEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct SpaceshipWeaponBinding
		{
			struct SpaceshipWeaponBindingChangedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<SpaceshipWeaponBinding::SpaceshipWeaponBindingChangedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(130322) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<SpaceshipWeaponBinding::SpaceshipWeaponBindingChangedEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct PhotoGallery_DeletePhoto
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PhotoGallery_DeletePhoto>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(130819) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PhotoGallery_DeletePhoto>* (*)()>(addr);
				return func();
			}
		};
		struct PowersMenu_ActivateEssence
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PowersMenu_ActivateEssence>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(130908) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PowersMenu_ActivateEssence>* (*)()>(addr);
				return func();
			}
		};
		struct PowersMenu_EquipPower
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PowersMenu_EquipPower>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(130909) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PowersMenu_EquipPower>* (*)()>(addr);
				return func();
			}
		};
		struct PowersMenu_FavoritePower
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PowersMenu_FavoritePower>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(130910) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PowersMenu_FavoritePower>* (*)()>(addr);
				return func();
			}
		};
		struct ContainerMenuClosed
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<ContainerMenuClosed::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(131197) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<ContainerMenuClosed::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct BinkMovieStoppedPlayingEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BinkMovieStoppedPlayingEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(131237) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BinkMovieStoppedPlayingEvent>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_CraftItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_CraftItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132096) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_CraftItem>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_ExitBench
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_ExitBench>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132097) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_ExitBench>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_InstallMod
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_InstallMod>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132098) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_InstallMod>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_RenameItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_RenameItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132099) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_RenameItem>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_RevertedModdedItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_RevertedModdedItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132100) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_RevertedModdedItem>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_SelectedMod
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_SelectedMod>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132101) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_SelectedMod>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_SelectedModSlot
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_SelectedModSlot>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132102) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_SelectedModSlot>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_SelectedModdableItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_SelectedModdableItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132103) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_SelectedModdableItem>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_SelectedRecipe
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_SelectedRecipe>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132104) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_SelectedRecipe>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_ToggleTracking
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_ToggleTracking>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132106) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_ToggleTracking>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_ViewingModdableItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_ViewingModdableItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132107) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_ViewingModdableItem>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_CloseMenu
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_CloseMenu>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132468) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_CloseMenu>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_Change3DView
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_Change3DView>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132470) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_Change3DView>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_PaperDollTryOn
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_PaperDollTryOn>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132471) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_PaperDollTryOn>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_ResetPaperDollInv
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_ResetPaperDollInv>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(132472) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_ResetPaperDollInv>* (*)()>(addr);
				return func();
			}
		};
		struct ShowingQuestMarketTextEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShowingQuestMarketTextEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(133279) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShowingQuestMarketTextEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TargetHitEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TargetHitEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(133346) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TargetHitEvent>* (*)()>(addr);
				return func();
			}
		};
		struct ClearHUDMessagesEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ClearHUDMessagesEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(133511) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ClearHUDMessagesEvent>* (*)()>(addr);
				return func();
			}
		};
		struct ShowHUDMessageEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShowHUDMessageEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(133512) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShowHUDMessageEvent>* (*)()>(addr);
				return func();
			}
		};
		struct PlayerDetectionLevelChangeEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PlayerDetectionLevelChangeEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(133601) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerDetectionLevelChangeEvent>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_ToggleHelmet
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_ToggleHelmet>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(134925) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_ToggleHelmet>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_ToggleSuit
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_ToggleSuit>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(134926) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_ToggleSuit>* (*)()>(addr);
				return func();
			}
		};
		struct ControlsRemappedEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ControlsRemappedEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(136133) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ControlsRemappedEvent>* (*)()>(addr);
				return func();
			}
		};
		struct ShowLongShipBootup
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShowLongShipBootup>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137014) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShowLongShipBootup>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHudQuickContainer_TransferMenu
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHudQuickContainer_TransferMenu>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137015) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHudQuickContainer_TransferMenu>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_Activate
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_Activate>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137016) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_Activate>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_BodyViewMarkerDimensions
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_BodyViewMarkerDimensions>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137017) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_BodyViewMarkerDimensions>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_ChangeComponentSelection
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_ChangeComponentSelection>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137018) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_ChangeComponentSelection>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_Deselect
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_Deselect>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137020) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_Deselect>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_FarTravel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_FarTravel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137021) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_FarTravel>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_HailAccepted
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_HailAccepted>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137022) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_HailAccepted>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_HailCancelled
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_HailCancelled>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137023) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_HailCancelled>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_JumpToQuestMarker
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_JumpToQuestMarker>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137023) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_JumpToQuestMarker>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_Land
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_Land>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137025) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_Land>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_LandingMarkerMap
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_LandingMarkerMap>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137026) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_LandingMarkerMap>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_Map
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_Map>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137027) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_Map>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_OpenPhotoMode
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_OpenPhotoMode>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137029) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_OpenPhotoMode>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_Repair
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_Repair>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137030) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_Repair>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_SetTargetMode
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_SetTargetMode>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137031) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_SetTargetMode>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_Target
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_Target>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137032) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_Target>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_TargetShipSystem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_TargetShipSystem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137033) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_TargetShipSystem>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_UntargetShipSystem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_UntargetShipSystem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137034) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_UntargetShipSystem>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_UpdateComponentPower
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_UpdateComponentPower>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(137035) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_UpdateComponentPower>* (*)()>(addr);
				return func();
			}
		};
		struct BGSScannerGuideEffectStatusUpdateEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BGSScannerGuideEffectStatusUpdateEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138080) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BGSScannerGuideEffectStatusUpdateEvent>* (*)()>(addr);
				return func();
			}
		};
		struct ExperienceMeterDisplayData
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ExperienceMeterDisplayData>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138446) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ExperienceMeterDisplayData>* (*)()>(addr);
				return func();
			}
		};
		struct LevelUp_AnimFinished
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<LevelUp_AnimFinished>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138447) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<LevelUp_AnimFinished>* (*)()>(addr);
				return func();
			}
		};
		struct LocationTextWidget_FinishedQueue
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<LocationTextWidget_FinishedQueue>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138451) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<LocationTextWidget_FinishedQueue>* (*)()>(addr);
				return func();
			}
		};
		struct PlayerCrosshairModeEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PlayerCrosshairModeEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(133336) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerCrosshairModeEvent>* (*)()>(addr);
				return func();
			}
		};
		struct HUDNotificationEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<HUDNotificationEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138665) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<HUDNotificationEvent>* (*)()>(addr);
				return func();
			}
		};
		struct HUDNotification_SetMissionActive
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<HUDNotification_SetMissionActive>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138669) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<HUDNotification_SetMissionActive>* (*)()>(addr);
				return func();
			}
		};
		struct BarterMenu_BuyItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BarterMenu_BuyItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138993) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BarterMenu_BuyItem>* (*)()>(addr);
				return func();
			}
		};
		struct BarterMenu_CloseMenu
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BarterMenu_CloseMenu>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138994) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BarterMenu_CloseMenu>* (*)()>(addr);
				return func();
			}
		};
		struct BarterMenu_HideModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BarterMenu_HideModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138995) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BarterMenu_HideModel>* (*)()>(addr);
				return func();
			}
		};
		struct BarterMenu_LoadModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BarterMenu_LoadModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138996) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BarterMenu_LoadModel>* (*)()>(addr);
				return func();
			}
		};
		struct BarterMenu_SellItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BarterMenu_SellItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138997) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BarterMenu_SellItem>* (*)()>(addr);
				return func();
			}
		};
		struct BarterMenu_SetMouseOverModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BarterMenu_SetMouseOverModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(138998) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BarterMenu_SetMouseOverModel>* (*)()>(addr);
				return func();
			}
		};
		struct BarterMenu_ViewedItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BarterMenu_ViewedItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139000) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BarterMenu_ViewedItem>* (*)()>(addr);
				return func();
			}
		};
		struct MissionMenu_ClearState
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MissionMenu_ClearState>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139095) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MissionMenu_ClearState>* (*)()>(addr);
				return func();
			}
		};
		struct MissionMenu_PlotToLocation
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MissionMenu_PlotToLocation>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139096) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MissionMenu_PlotToLocation>* (*)()>(addr);
				return func();
			}
		};
		struct MissionMenu_RejectQuest
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MissionMenu_RejectQuest>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139097) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MissionMenu_RejectQuest>* (*)()>(addr);
				return func();
			}
		};
		struct MissionMenu_ShowItemLocation
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MissionMenu_ShowItemLocation>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139100) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MissionMenu_ShowItemLocation>* (*)()>(addr);
				return func();
			}
		};
		struct MissionMenu_ToggleTrackingQuest
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MissionMenu_ToggleTrackingQuest>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139102) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MissionMenu_ToggleTrackingQuest>* (*)()>(addr);
				return func();
			}
		};
		struct DataSlateMenu_playSFX
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DataSlateMenu_playSFX>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139188) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DataSlateMenu_playSFX>* (*)()>(addr);
				return func();
			}
		};
		struct DataSlateMenu_toggleAudio
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DataSlateMenu_toggleAudio>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139189) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DataSlateMenu_toggleAudio>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_HideModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_HideModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139340) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_HideModel>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_LoadModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_LoadModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139341) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_LoadModel>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_OnEnterCategory
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_OnEnterCategory>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139342) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_OnEnterCategory>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_OpenCargoHold
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_OpenCargoHold>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139343) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_OpenCargoHold>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_SelectItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_SelectItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139344) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_SelectItem>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_SetMouseOverModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_SetMouseOverModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139345) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_SetMouseOverModel>* (*)()>(addr);
				return func();
			}
		};
		struct InventoryMenu_ToggleFavorite
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InventoryMenu_ToggleFavorite>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139347) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryMenu_ToggleFavorite>* (*)()>(addr);
				return func();
			}
		};
		struct MissionBoard_MissionEntryChanged
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MissionBoard_MissionEntryChanged>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139500) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MissionBoard_MissionEntryChanged>* (*)()>(addr);
				return func();
			}
		};
		struct MissionBoard_MissionEntryPressed
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MissionBoard_MissionEntryPressed>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139501) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MissionBoard_MissionEntryPressed>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_Bioscan
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_Bioscan>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139641) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_Bioscan>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_FastTravel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_FastTravel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139642) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_FastTravel>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_Harvest
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_Harvest>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139643) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_Harvest>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_Outpost
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_Outpost>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139645) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_Outpost>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_SocialSpell
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_SocialSpell>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139648) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_SocialSpell>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_SurfaceMap
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_SurfaceMap>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139651) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_SurfaceMap>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_ZoomIn
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_ZoomIn>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139653) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_ZoomIn>* (*)()>(addr);
				return func();
			}
		};
		struct MonocleMenu_ZoomOut
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MonocleMenu_ZoomOut>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139654) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MonocleMenu_ZoomOut>* (*)()>(addr);
				return func();
			}
		};
		struct PhotoMode_InitializeCategory
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PhotoMode_InitializeCategory>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139736) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PhotoMode_InitializeCategory>* (*)()>(addr);
				return func();
			}
		};
		struct PhotoMode_ResetToDefaults
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PhotoMode_ResetToDefaults>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139737) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PhotoMode_ResetToDefaults>* (*)()>(addr);
				return func();
			}
		};
		struct PhotoMode_SliderChanged
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PhotoMode_SliderChanged>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139738) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PhotoMode_SliderChanged>* (*)()>(addr);
				return func();
			}
		};
		struct PhotoMode_TakeSnapshot
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PhotoMode_TakeSnapshot>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139740) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PhotoMode_TakeSnapshot>* (*)()>(addr);
				return func();
			}
		};
		struct PhotoMode_ToggleHelmet
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PhotoMode_ToggleHelmet>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139741) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PhotoMode_ToggleHelmet>* (*)()>(addr);
				return func();
			}
		};
		struct PhotoMode_ToggleUI
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PhotoMode_ToggleUI>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139742) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PhotoMode_ToggleUI>* (*)()>(addr);
				return func();
			}
		};
		struct PickpocketMenu_OnItemSelect
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PickpocketMenu_OnItemSelect>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(139918) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PickpocketMenu_OnItemSelect>* (*)()>(addr);
				return func();
			}
		};
		struct ResearchMenu_AddMaterial
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ResearchMenu_AddMaterial>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140018) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ResearchMenu_AddMaterial>* (*)()>(addr);
				return func();
			}
		};
		struct ResearchMenu_CategorySelected
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ResearchMenu_CategorySelected>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140019) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ResearchMenu_CategorySelected>* (*)()>(addr);
				return func();
			}
		};
		struct ResearchMenu_HideModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ResearchMenu_HideModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140021) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ResearchMenu_HideModel>* (*)()>(addr);
				return func();
			}
		};
		struct ResearchMenu_PreviewProject
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ResearchMenu_PreviewProject>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140022) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ResearchMenu_PreviewProject>* (*)()>(addr);
				return func();
			}
		};
		struct ResearchMenu_ProjectViewed
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ResearchMenu_ProjectViewed>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140023) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ResearchMenu_ProjectViewed>* (*)()>(addr);
				return func();
			}
		};
		struct ResearchMenu_ToggleTrackingProject
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ResearchMenu_ToggleTrackingProject>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140025) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ResearchMenu_ToggleTrackingProject>* (*)()>(addr);
				return func();
			}
		};
		struct UnlockedTerminalElementEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<UnlockedTerminalElementEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140243) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<UnlockedTerminalElementEvent>* (*)()>(addr);
				return func();
			}
		};
		struct SecurityMenu_BackOutKey
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SecurityMenu_BackOutKey>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140244) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SecurityMenu_BackOutKey>* (*)()>(addr);
				return func();
			}
		};
		struct SecurityMenu_ConfirmExit
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SecurityMenu_ConfirmExit>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140246) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SecurityMenu_ConfirmExit>* (*)()>(addr);
				return func();
			}
		};
		struct SecurityMenu_EliminateUnusedKeys
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SecurityMenu_EliminateUnusedKeys>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140247) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SecurityMenu_EliminateUnusedKeys>* (*)()>(addr);
				return func();
			}
		};
		struct SecurityMenu_GetRingHint
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SecurityMenu_GetRingHint>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140248) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SecurityMenu_GetRingHint>* (*)()>(addr);
				return func();
			}
		};
		struct SecurityMenu_SelectNewKey
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SecurityMenu_SelectNewKey>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140249) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SecurityMenu_SelectNewKey>* (*)()>(addr);
				return func();
			}
		};
		struct SecurityMenu_TryUseKey
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SecurityMenu_TryUseKey>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140250) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SecurityMenu_TryUseKey>* (*)()>(addr);
				return func();
			}
		};
		struct Refuel_Accept
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<Refuel_Accept>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140363) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<Refuel_Accept>* (*)()>(addr);
				return func();
			}
		};
		struct Refuel_Cancel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<Refuel_Cancel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140364) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<Refuel_Cancel>* (*)()>(addr);
				return func();
			}
		};
		struct SkillsMenu_Accept
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SkillsMenu_Accept>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(140522) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SkillsMenu_Accept>* (*)()>(addr);
				return func();
			}
		};
		struct BSChargenAPI
		{
			struct BIDataUtils
			{
				struct PresetNPCChangedEvent
				{
				public:
					[[nodiscard]] static RE::BSTEventSource<BSChargenAPI::BIDataUtils::PresetNPCChangedEvent>* GetEventSource()
					{
						REL::Relocation<uintptr_t> funcPtr{ REL::ID(141184) };
						uintptr_t                  addr = funcPtr.address();
						const auto                 func = reinterpret_cast<RE::BSTEventSource<BSChargenAPI::BIDataUtils::PresetNPCChangedEvent>* (*)()>(addr);
						return func();
					}
				};
			};
		};
		struct CharGen_BrowChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_BrowChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141185) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_BrowChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_BrowColorChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_BrowColorChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141186) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_BrowColorChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_CancelTextEntry
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_CancelTextEntry>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141187) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_CancelTextEntry>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_CloseMenu
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_CloseMenu>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141188) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_CloseMenu>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_CyclePronoun
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_CyclePronoun>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141189) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_CyclePronoun>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_DirtScarsEtcChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_DirtScarsEtcChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141190) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_DirtScarsEtcChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_EndBodyChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_EndBodyChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141191) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_EndBodyChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_EndTextEntry
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_EndTextEntry>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141192) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_EndTextEntry>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_EyeColorChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_EyeColorChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141193) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_EyeColorChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_FacialHairChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_FacialHairChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141194) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_FacialHairChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_FacialHairColorChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_FacialHairColorChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141195) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_FacialHairColorChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_HairChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_HairChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141196) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_HairChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_HairColorChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_HairColorChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141197) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_HairColorChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_HeadpartPlusSelectorChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_HeadpartPlusSelectorChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141198) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_HeadpartPlusSelectorChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_HeadpartPresetChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_HeadpartPresetChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141199) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_HeadpartPresetChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_JewelryChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_JewelryChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141200) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_JewelryChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_JewelryColorChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_JewelryColorChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141201) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_JewelryColorChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_MakeupChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_MakeupChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141202) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_MakeupChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_MarkingsChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_MarkingsChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141203) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_MarkingsChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_PostBlendColorOptionChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_PostBlendColorOptionChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141204) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_PostBlendColorOptionChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_PostBlendFaceChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_PostBlendFaceChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141205) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_PostBlendFaceChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_PostBlendIntensityChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_PostBlendIntensityChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141206) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_PostBlendIntensityChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_PresetChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_PresetChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141207) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_PresetChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_RotatePaperdoll
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_RotatePaperdoll>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141210) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_RotatePaperdoll>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SetAdditionalSlider
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SetAdditionalSlider>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141211) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SetAdditionalSlider>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SetBackground
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SetBackground>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141212) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SetBackground>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SetBodyValues
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SetBodyValues>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141214) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SetBodyValues>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SetCameraPosition
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SetCameraPosition>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141215) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SetCameraPosition>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SetPronoun
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SetPronoun>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141216) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SetPronoun>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SetSex
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SetSex>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141217) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SetSex>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SetSlider
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SetSlider>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141218) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SetSlider>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SetTrait
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SetTrait>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141219) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SetTrait>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_ShowChooseBackgroundMessage
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_ShowChooseBackgroundMessage>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141220) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_ShowChooseBackgroundMessage>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_ShowPlayerRenameMessage
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_ShowPlayerRenameMessage>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141221) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_ShowPlayerRenameMessage>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SkintoneChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SkintoneChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141222) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SkintoneChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_StartBodyChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_StartBodyChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141223) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_StartBodyChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_StartTextEntry
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_StartTextEntry>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141224) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_StartTextEntry>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_SwitchBodyType
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_SwitchBodyType>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141225) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_SwitchBodyType>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_TeethChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_TeethChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141227) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_TeethChange>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_TeethRollOff
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_TeethRollOff>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141228) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_TeethRollOff>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_TeethRollOn
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_TeethRollOn>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141229) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_TeethRollOn>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_ToggleMarking
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_ToggleMarking>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141230) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_ToggleMarking>* (*)()>(addr);
				return func();
			}
		};
		struct CharGen_TogglePreviewHabSuit
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CharGen_TogglePreviewHabSuit>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141231) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CharGen_TogglePreviewHabSuit>* (*)()>(addr);
				return func();
			}
		};
		struct UIMenuChargenMenuDisablePaperdoll
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<UIMenuChargenMenuDisablePaperdoll>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141232) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<UIMenuChargenMenuDisablePaperdoll>* (*)()>(addr);
				return func();
			}
		};
		struct DataMenu_Missions
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DataMenu_Missions>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141471) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DataMenu_Missions>* (*)()>(addr);
				return func();
			}
		};
		struct DataMenu_PlotToLocation
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DataMenu_PlotToLocation>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141473) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DataMenu_PlotToLocation>* (*)()>(addr);
				return func();
			}
		};
		struct DataMenu_SetPaperDollActive
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DataMenu_SetPaperDollActive>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141482) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DataMenu_SetPaperDollActive>* (*)()>(addr);
				return func();
			}
		};
		struct PauseMenu_ActionCanceled
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PauseMenu_ActionCanceled>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141614) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PauseMenu_ActionCanceled>* (*)()>(addr);
				return func();
			}
		};
		struct PauseMenu_ConfirmAction
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PauseMenu_ConfirmAction>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141615) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PauseMenu_ConfirmAction>* (*)()>(addr);
				return func();
			}
		};
		struct PauseMenu_ConfirmLoad
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PauseMenu_ConfirmLoad>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141615) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PauseMenu_ConfirmLoad>* (*)()>(addr);
				return func();
			}
		};
		struct PauseMenu_ConfirmSave
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PauseMenu_ConfirmSave>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141617) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PauseMenu_ConfirmSave>* (*)()>(addr);
				return func();
			}
		};
		struct PauseMenu_DeleteSave
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PauseMenu_DeleteSave>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141618) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PauseMenu_DeleteSave>* (*)()>(addr);
				return func();
			}
		};
		struct PauseMenu_QuitToDesktop
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PauseMenu_QuitToDesktop>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141619) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PauseMenu_QuitToDesktop>* (*)()>(addr);
				return func();
			}
		};
		struct PauseMenu_SetCharacter
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PauseMenu_SetCharacter>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141620) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PauseMenu_SetCharacter>* (*)()>(addr);
				return func();
			}
		};
		struct PauseMenu_StartAction
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PauseMenu_StartAction>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141621) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PauseMenu_StartAction>* (*)()>(addr);
				return func();
			}
		};
		struct PauseMenu_StartLoad
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PauseMenu_StartLoad>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141622) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PauseMenu_StartLoad>* (*)()>(addr);
				return func();
			}
		};
		struct PlayBink_CloseMenu
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<PlayBink_CloseMenu>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141653) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayBink_CloseMenu>* (*)()>(addr);
				return func();
			}
		};
		struct Reticle_OnLongAnimFinished
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<Reticle_OnLongAnimFinished>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141816) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<Reticle_OnLongAnimFinished>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHudQuickContainer_TransferItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHudQuickContainer_TransferItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141817) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHudQuickContainer_TransferItem>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_AbortJump
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_AbortJump>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141818) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_AbortJump>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_DockRequested
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_DockRequested>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141819) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_DockRequested>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_HailShip
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_HailShip>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141820) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_HailShip>* (*)()>(addr);
				return func();
			}
		};
		struct ShipHud_UpdateTargetPanelRect
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ShipHud_UpdateTargetPanelRect>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141821) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ShipHud_UpdateTargetPanelRect>* (*)()>(addr);
				return func();
			}
		};
		struct TakeoffMenu_ExitShip
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TakeoffMenu_ExitShip>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141823) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TakeoffMenu_ExitShip>* (*)()>(addr);
				return func();
			}
		};
		struct TakeoffMenu_Launch
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TakeoffMenu_Launch>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(141824) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TakeoffMenu_Launch>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_LandingInputInProgress
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_LandingInputInProgress>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142192) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_LandingInputInProgress>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_MarkerGroupContainerVisibilityChanged
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_MarkerGroupContainerVisibilityChanged>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142193) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_MarkerGroupContainerVisibilityChanged>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_MarkerGroupEntryClicked
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_MarkerGroupEntryClicked>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142194) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_MarkerGroupEntryClicked>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_MarkerGroupEntryHoverChanged
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_MarkerGroupEntryHoverChanged>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142195) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_MarkerGroupEntryHoverChanged>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_ScanPlanet
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_ScanPlanet>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142196) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_ScanPlanet>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_SelectedLandingSite
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_SelectedLandingSite>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142197) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_SelectedLandingSite>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_SelectedLandingSiteFailed
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_SelectedLandingSiteFailed>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142198) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_SelectedLandingSiteFailed>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_ShowRealCursor
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_ShowRealCursor>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142199) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_ShowRealCursor>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_QuickSelectChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_QuickSelectChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142493) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_QuickSelectChange>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_Galaxy_FocusSystem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_Galaxy_FocusSystem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142763) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_Galaxy_FocusSystem>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_OnGalaxyViewInitialized
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_OnGalaxyViewInitialized>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142764) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_OnGalaxyViewInitialized>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_ExecuteRoute
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_ExecuteRoute>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142945) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_ExecuteRoute>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_OnCancel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_OnCancel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142946) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_OnCancel>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_OnClearRoute
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_OnClearRoute>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142947) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_OnClearRoute>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_OnExitStarMap
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_OnExitStarMap>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142948) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_OnExitStarMap>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_OnHintButtonClicked
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_OnHintButtonClicked>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142949) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_OnHintButtonClicked>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_OnOutpostEntrySelected
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_OnOutpostEntrySelected>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142950) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_OnOutpostEntrySelected>* (*)()>(addr);
				return func();
			}
		};
		struct StarMapMenu_ReadyToClose
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<StarMapMenu_ReadyToClose>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(142951) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<StarMapMenu_ReadyToClose>* (*)()>(addr);
				return func();
			}
		};
		struct SurfaceMapMenu_MarkerClicked
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SurfaceMapMenu_MarkerClicked>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(143330) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SurfaceMapMenu_MarkerClicked>* (*)()>(addr);
				return func();
			}
		};
		struct SurfaceMapMenu_TryPlaceCustomMarker
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SurfaceMapMenu_TryPlaceCustomMarker>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(143331) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SurfaceMapMenu_TryPlaceCustomMarker>* (*)()>(addr);
				return func();
			}
		};
		struct TerminalMenu_CancelEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TerminalMenu_CancelEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(143771) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TerminalMenu_CancelEvent>* (*)()>(addr);
				return func();
			}
		};
		struct Terminal_CloseAllViews
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<Terminal_CloseAllViews>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(143772) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<Terminal_CloseAllViews>* (*)()>(addr);
				return func();
			}
		};
		struct Terminal_CloseTopView
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<Terminal_CloseTopView>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(143773) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<Terminal_CloseTopView>* (*)()>(addr);
				return func();
			}
		};
		struct Terminal_CloseView
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<Terminal_CloseView>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(143773) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<Terminal_CloseView>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_Highlight3D
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_Highlight3D>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144186) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_Highlight3D>* (*)()>(addr);
				return func();
			}
		};
		struct CraftingMenu_RevertHighlight
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<CraftingMenu_RevertHighlight>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144187) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<CraftingMenu_RevertHighlight>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopBuilderMenu_ChangeBuildItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopBuilderMenu_ChangeBuildItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144229) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopBuilderMenu_ChangeBuildItem>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopBuilderMenu_SelectedItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopBuilderMenu_SelectedItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144230) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopBuilderMenu_SelectedItem>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopBuilderMenu_ToggleTracking
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopBuilderMenu_ToggleTracking>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144231) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopBuilderMenu_ToggleTracking>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_AttemptBuild
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_AttemptBuild>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144358) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_AttemptBuild>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_ChangeVariant
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_ChangeVariant>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144360) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_ChangeVariant>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_ConnectionEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_ConnectionEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144361) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_ConnectionEvent>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_SelectedCategory
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_SelectedCategory>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144364) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_SelectedCategory>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_SelectedGridObject
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_SelectedGridObject>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144365) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_SelectedGridObject>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_ShowExtras
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_ShowExtras>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144366) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_ShowExtras>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_SwitchMode
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_SwitchMode>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144367) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_SwitchMode>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_ToggleDistance
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_ToggleDistance>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144368) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_ToggleDistance>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_ToggleTracking
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_ToggleTracking>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144369) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_ToggleTracking>* (*)()>(addr);
				return func();
			}
		};
		struct WorkshopMenu_ToggleView
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<WorkshopMenu_ToggleView>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(144370) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<WorkshopMenu_ToggleView>* (*)()>(addr);
				return func();
			}
		};
		struct ModelReferenceEffectEvents
		{
			struct ReferenceEffectFinished
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<ModelReferenceEffectEvents::ReferenceEffectFinished>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(145389) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<ModelReferenceEffectEvents::ReferenceEffectFinished>* (*)()>(addr);
					return func();
				}
			};
		};
		struct BGSAcousticSpaceListener
		{
			struct StackChangedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<BGSAcousticSpaceListener::StackChangedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(145815) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<BGSAcousticSpaceListener::StackChangedEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct SpaceshipBIEvents
		{
			struct ShipPowerAllocationBIEventSent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<SpaceshipBIEvents::ShipPowerAllocationBIEventSent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(146094) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<SpaceshipBIEvents::ShipPowerAllocationBIEventSent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct Research
		{
			struct ResearchProgressEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Research::ResearchProgressEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(147163) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Research::ResearchProgressEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct ContainerMenu_HideModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ContainerMenu_HideModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166510) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ContainerMenu_HideModel>* (*)()>(addr);
				return func();
			}
		};
		struct ContainerMenu_Jettison
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ContainerMenu_Jettison>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166511) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ContainerMenu_Jettison>* (*)()>(addr);
				return func();
			}
		};
		struct ContainerMenu_LoadModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ContainerMenu_LoadModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166512) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ContainerMenu_LoadModel>* (*)()>(addr);
				return func();
			}
		};
		struct ContainerMenu_OpenRefuelMenu
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ContainerMenu_OpenRefuelMenu>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166513) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ContainerMenu_OpenRefuelMenu>* (*)()>(addr);
				return func();
			}
		};
		struct ContainerMenu_SetMouseOverModel
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ContainerMenu_SetMouseOverModel>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166514) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ContainerMenu_SetMouseOverModel>* (*)()>(addr);
				return func();
			}
		};
		struct ContainerMenu_TakeAll
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ContainerMenu_TakeAll>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166515) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ContainerMenu_TakeAll>* (*)()>(addr);
				return func();
			}
		};
		struct ContainerMenu_ToggleEquip
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ContainerMenu_ToggleEquip>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166516) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ContainerMenu_ToggleEquip>* (*)()>(addr);
				return func();
			}
		};
		struct ContainerMenu_TransferItem
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<ContainerMenu_TransferItem>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166518) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<ContainerMenu_TransferItem>* (*)()>(addr);
				return func();
			}
		};
		struct DialogueMenu_OnDialogueSelect
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DialogueMenu_OnDialogueSelect>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166594) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DialogueMenu_OnDialogueSelect>* (*)()>(addr);
				return func();
			}
		};
		struct DialogueMenu_OnListVisibilityChange
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DialogueMenu_OnListVisibilityChange>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166595) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DialogueMenu_OnListVisibilityChange>* (*)()>(addr);
				return func();
			}
		};
		struct DialogueMenu_OnPersuasionAutoWin
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DialogueMenu_OnPersuasionAutoWin>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166596) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DialogueMenu_OnPersuasionAutoWin>* (*)()>(addr);
				return func();
			}
		};
		struct DialogueMenu_RequestExit
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DialogueMenu_RequestExit>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166598) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DialogueMenu_RequestExit>* (*)()>(addr);
				return func();
			}
		};
		struct DialogueMenu_RequestSkipDialogue
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<DialogueMenu_RequestSkipDialogue>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166599) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<DialogueMenu_RequestSkipDialogue>* (*)()>(addr);
				return func();
			}
		};
		struct FavoritesMenu_AssignQuickkey
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<FavoritesMenu_AssignQuickkey>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166789) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<FavoritesMenu_AssignQuickkey>* (*)()>(addr);
				return func();
			}
		};
		struct FavoritesMenu_UseQuickkey
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<FavoritesMenu_UseQuickkey>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(166790) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<FavoritesMenu_UseQuickkey>* (*)()>(addr);
				return func();
			}
		};
		struct MessageBoxMenu_OnBackOut
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MessageBoxMenu_OnBackOut>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(167116) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MessageBoxMenu_OnBackOut>* (*)()>(addr);
				return func();
			}
		};
		struct MessageBoxMenu_OnButtonPress
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MessageBoxMenu_OnButtonPress>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(167117) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MessageBoxMenu_OnButtonPress>* (*)()>(addr);
				return func();
			}
		};
		struct MessageBoxMenu_OnScriptedButtonPress
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<MessageBoxMenu_OnScriptedButtonPress>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(167118) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<MessageBoxMenu_OnScriptedButtonPress>* (*)()>(addr);
				return func();
			}
		};
		struct SleepWaitMenu_InterruptRest
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SleepWaitMenu_InterruptRest>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(167219) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SleepWaitMenu_InterruptRest>* (*)()>(addr);
				return func();
			}
		};
		struct SleepWaitMenu_StartRest
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<SleepWaitMenu_StartRest>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(167220) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<SleepWaitMenu_StartRest>* (*)()>(addr);
				return func();
			}
		};
		struct Spaceship
		{
			struct TakeOffEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::TakeOffEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(37523) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::TakeOffEvent>* (*)()>(addr);
					return func();
				}
			};
			struct GravJumpEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::GravJumpEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(141814) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::GravJumpEvent>* (*)()>(addr);
					return func();
				}
			};
			struct LandedSetEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::LandedSetEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(141815) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::LandedSetEvent>* (*)()>(addr);
					return func();
				}
			};
			struct BoughtEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::BoughtEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174575) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::BoughtEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ContrabandScanWarningEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::ContrabandScanWarningEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174576) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::ContrabandScanWarningEvent>* (*)()>(addr);
					return func();
				}
			};
			struct DockEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::DockEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174577) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::DockEvent>* (*)()>(addr);
					return func();
				}
			};
			struct DynamicNavmeshCompleted
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::DynamicNavmeshCompleted>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174578) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::DynamicNavmeshCompleted>* (*)()>(addr);
					return func();
				}
			};
			struct FarTravelEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::FarTravelEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174579) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::FarTravelEvent>* (*)()>(addr);
					return func();
				}
			};
			struct LandingEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::LandingEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174580) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::LandingEvent>* (*)()>(addr);
					return func();
				}
			};
			struct PlanetScanEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::PlanetScanEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174581) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::PlanetScanEvent>* (*)()>(addr);
					return func();
				}
			};
			struct RampDownEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::RampDownEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174582) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::RampDownEvent>* (*)()>(addr);
					return func();
				}
			};
			struct RefueledEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::RefueledEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174583) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::RefueledEvent>* (*)()>(addr);
					return func();
				}
			};
			struct RegisteredEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::RegisteredEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174584) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::RegisteredEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ShieldEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::ShieldEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174585) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::ShieldEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ShipAddedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::ShipAddedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174586) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::ShipAddedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ShipCollisionEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::ShipCollisionEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174587) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::ShipCollisionEvent>* (*)()>(addr);
					return func();
				}
			};
			struct ShipCustomizedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::ShipCustomizedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174588) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::ShipCustomizedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct SoldEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::SoldEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174589) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::SoldEvent>* (*)()>(addr);
					return func();
				}
			};
			struct SystemDamagedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::SystemDamagedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174590) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::SystemDamagedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct SystemPowerAllocationEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::SystemPowerAllocationEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174591) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::SystemPowerAllocationEvent>* (*)()>(addr);
					return func();
				}
			};
			struct SystemPowerChangeEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::SystemPowerChangeEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174592) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::SystemPowerChangeEvent>* (*)()>(addr);
					return func();
				}
			};
			struct SystemRepairedBIEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::SystemRepairedBIEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174593) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::SystemRepairedBIEvent>* (*)()>(addr);
					return func();
				}
			};
			struct SystemRepairedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::SystemRepairedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174594) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::SystemRepairedEvent>* (*)()>(addr);
					return func();
				}
			};
			struct TakeDamagEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Spaceship::TakeDamagEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(174595) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Spaceship::TakeDamagEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct UpdateSceneRectEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<UpdateSceneRectEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(187249) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<UpdateSceneRectEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESCellNavmeshGeneratedEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESCellNavmeshGeneratedEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(34446) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESCellNavmeshGeneratedEvent>* (*)()>(addr);
				return func();
			}
		};
		struct PerkChanged
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<PerkChanged::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(76533) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<PerkChanged::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct ActivityEvents
		{
			struct ActivityCompletedEvent
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<ActivityEvents::ActivityCompletedEvent>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(86737) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<ActivityEvents::ActivityCompletedEvent>* (*)()>(addr);
					return func();
				}
			};
		};
		struct ChallengeCompletedEvent
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<ChallengeCompletedEvent::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(86781) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<ChallengeCompletedEvent::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct InventoryItemEvent
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<InventoryItemEvent::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(87526) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<InventoryItemEvent::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct BooksRead
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<BooksRead::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(103540) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<BooksRead::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct LocationLinked
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<LocationLinked::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(104623) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<LocationLinked::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct Activation
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Activation::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(106834) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Activation::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct ActorCellChangeEvent
		{
			struct Event
			{
			public:
				RE::Actor*                                                    actor;
				[[nodiscard]] static RE::BSTEventSource<ActorCellChangeEvent::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(107081) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<ActorCellChangeEvent::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct BGSAffinityEventEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BGSAffinityEventEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107086) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BGSAffinityEventEvent>* (*)()>(addr);
				return func();
			}
		};
		struct BGSCellGridLoadEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BGSCellGridLoadEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107087) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BGSCellGridLoadEvent>* (*)()>(addr);
				return func();
			}
		};
		struct BGSRadiationDamageEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<BGSRadiationDamageEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107106) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<BGSRadiationDamageEvent>* (*)()>(addr);
				return func();
			}
		};
		struct InstantReferenceInteractionEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<InstantReferenceInteractionEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107112) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<InstantReferenceInteractionEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESActivateEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESActivateEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107136) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESActivateEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESBookReadEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESBookReadEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107141) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESBookReadEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESCellFullyLoadedEvent
		{
		public:
			RE::TESObjectCELL*                                                cell;
			[[nodiscard]] static RE::BSTEventSource<TESCellFullyLoadedEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107143) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESCellFullyLoadedEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESContainerChangedEvent
		{
		public:
			std::uint32_t                                                      sourceContainerFormID;  // 00
			std::uint32_t                                                      targetContainerFormID;  // 04
			std::uint32_t                                                      itemFormID;             // 08
			std::uint32_t                                                      itemCount;              // 0C
			std::uint32_t                                                      itemRefID;              // 10
			[[nodiscard]] static RE::BSTEventSource<TESContainerChangedEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107155) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESContainerChangedEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESFormDeleteEvent
		{
		public:
			std::uint32_t                                                deletedFormID;
			[[nodiscard]] static RE::BSTEventSource<TESFormDeleteEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107166) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESFormDeleteEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESFormIDRemapEvent
		{
		public:
			std::uint32_t                                                 oldFormID;
			std::uint32_t                                                 newFormID;
			[[nodiscard]] static RE::BSTEventSource<TESFormIDRemapEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107167) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESFormIDRemapEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESFurnitureEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESFurnitureEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107168) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESFurnitureEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESGrabReleaseEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESGrabReleaseEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107169) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESGrabReleaseEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESMissionAcceptedEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESMissionAcceptedEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107176) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESMissionAcceptedEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESObjectLoadedEvent
		{
		public:
			std::uint32_t                                                  loadedRefID;
			bool                                                           loadedState;
			[[nodiscard]] static RE::BSTEventSource<TESObjectLoadedEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107177) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESObjectLoadedEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESPickNewIdleEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESPickNewIdleEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107183) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESPickNewIdleEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESResetEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESResetEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107193) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESResetEvent>* (*)()>(addr);
				return func();
			}
		};
		struct TESResolveNPCTemplatesEvent
		{
		public:
			[[nodiscard]] static RE::BSTEventSource<TESResolveNPCTemplatesEvent>* GetEventSource()
			{
				REL::Relocation<uintptr_t> funcPtr{ REL::ID(107194) };
				uintptr_t                  addr = funcPtr.address();
				const auto                 func = reinterpret_cast<RE::BSTEventSource<TESResolveNPCTemplatesEvent>* (*)()>(addr);
				return func();
			}
		};
		struct ClearShipHudTarget
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<ClearShipHudTarget::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(137011) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<ClearShipHudTarget::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct TryUpdateShipHudTarget
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<TryUpdateShipHudTarget::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(137012) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<TryUpdateShipHudTarget::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct ActorItemEquipped
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<ActorItemEquipped::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(151162) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<ActorItemEquipped::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct ReloadWeaponEvent
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<ReloadWeaponEvent::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(151744) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<ReloadWeaponEvent::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct Bounty
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<Bounty::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(153651) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<Bounty::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct CriticalHitEvent
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<CriticalHitEvent::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(153653) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<CriticalHitEvent::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct CustomMarkerUpdate
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<CustomMarkerUpdate::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(153654) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<CustomMarkerUpdate::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct EnteredUnity
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<EnteredUnity::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(153656) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<EnteredUnity::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct LevelIncrease
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<LevelIncrease::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(153662) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<LevelIncrease::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct PlayerAmmoChanged
		{
			struct Event
			{
			public:
				uint32_t                                                           clipAmmoCount;
				uint32_t                                                           reserveAmmoCount;
				[[nodiscard]] static RE::BSTEventSource<PlayerAmmoChanged::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(153665) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<PlayerAmmoChanged::Event>* (*)()>(addr);
					return func();
				}
			};
		};
		struct TerminalHacked
		{
			struct Event
			{
			public:
				[[nodiscard]] static RE::BSTEventSource<TerminalHacked::Event>* GetEventSource()
				{
					REL::Relocation<uintptr_t> funcPtr{ REL::ID(153673) };
					uintptr_t                  addr = funcPtr.address();
					const auto                 func = reinterpret_cast<RE::BSTEventSource<TerminalHacked::Event>* (*)()>(addr);
					return func();
				}
			};
		};
	}
}
