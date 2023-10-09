#pragma once

#include "RE/A/ActorValueOwner.h"
#include "RE/B/BGSInventoryList.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTEvent.h"
#include "RE/I/IAnimationGraphManagerHolder.h"
#include "RE/I/IKeywordFormBase.h"
#include "RE/I/IMovementInterface.h"
#include "RE/I/IPostAnimationChannelUpdateFunctor.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESHandleForm.h"

namespace RE
{
	class Actor;
	class BGSLocation;
	class BGSScene;
	class BSAnimationGraphEvent;
	class BSTransformDeltaEvent;
	class NiAVObject;
	class TESBoundObject;
	class TESModel;
	class TESObjectCELL;
	class TESRace;
	class TESTopicInfo;
	class TESWorldSpace;
	class TESWaterForm;

	namespace ActorValueEvents
	{
		struct ActorValueChangedEvent;
	}

	class IMovementProcessMessageInterface :
		public IMovementInterface  // 00
	{
	public:
		~IMovementProcessMessageInterface() override;

		// add
		virtual void Unk_01();  // 01
	};
	static_assert(sizeof(IMovementProcessMessageInterface) == 0x8);

	struct OBJ_REFR
	{
	public:
		// members
		NiPoint3A                 angle;            // 00
		NiPoint3A                 location;         // 10
		NiPointer<TESBoundObject> objectReference;  // 20 - ref counted in SetObjectReference vfunc
	};
	static_assert(sizeof(OBJ_REFR) == 0x30);

	struct LOADED_REF_DATA
	{
	public:
		// members
		void*                 handleList;           // 00 - TODO
		NiPointer<NiAVObject> data3D;               // 08
		TESWaterForm*         currentWaterType;     // 10
		float                 relevantWaterHeight;  // 18
		float                 cachedRadius;         // 1C
		std::uint32_t         flags;                // 20
		std::uint16_t         underwaterCount;      // 24
	};
	static_assert(sizeof(LOADED_REF_DATA) == 0x28);

	class TESObjectREFR :
		public TESHandleForm,                                            // 00
		public BSTEventSink<BSTransformDeltaEvent>,                      // 38
		public IMovementProcessMessageInterface,                         // 40
		public IPostAnimationChannelUpdateFunctor,                       // 48
		public BSTEventSink<BSAnimationGraphEvent>,                      // 50
		public BSTEventSink<BGSInventoryListEvent::Event>,               // 58
		public IAnimationGraphManagerHolder,                             // 60
		public IKeywordFormBase,                                         // 68
		public ActorValueOwner,                                          // 70
		public BSTEventSource<ActorValueEvents::ActorValueChangedEvent>  // 78
	{
	public:
		SF_RTTI_VTABLE(TESObjectREFR);
		SF_FORMTYPE(REFR);

		~TESObjectREFR() override;  // 00

		// override (TESForm)
		virtual void         Predestroy();                                                                                                                      // 062
		virtual bool         Unk_63();                                                                                                                          // 063 - { return extraList.HasExtraData(14);};
		virtual bool         GetEditorLocation(NiPoint3& a_originalLocation, NiPoint3& a_originalAngle, TESForm*& a_locationFormOut);                           // 064 - new
		virtual void         Unk_65();                                                                                                                          // 065
		virtual BGSLocation* GetEditorLocation() const;                                                                                                         // 066
		virtual bool         GetEditorLocation(NiPoint3& a_originalLocation, NiPoint3& a_originalAngle, TESForm*& a_locationFormOut, TESForm* a_locationForm);  // 067
		virtual bool         IsTalking() const;                                                                                                                 // 068
		virtual void         ForceEditorLocation(BGSLocation* a_location);                                                                                      // 069
		virtual void         Unk_6A();                                                                                                                          // 06A
		virtual void         UpdateSoundCallBack(bool a_endSceneAction);                                                                                        // 06B
		virtual bool         SetDialoguewithPlayer(bool a_flag, bool a_forceGreet, TESTopicInfo* a_topicInfo);                                                  // 06C
		virtual void         Unk_6D();                                                                                                                          // 06D
		virtual void         Unk_6E();                                                                                                                          // 06E
		virtual void         Unk_6F();                                                                                                                          // 06F
		virtual void         Unk_70();                                                                                                                          // 070
		virtual void         Unk_71();                                                                                                                          // 071
		virtual void         Unk_72();                                                                                                                          // 072
		virtual void         Unk_73();                                                                                                                          // 073
		virtual void         Unk_74();                                                                                                                          // 074
		virtual void         Unk_75();                                                                                                                          // 075
		virtual void         Unk_76();                                                                                                                          // 076
		virtual void         Unk_77();                                                                                                                          // 077
		virtual bool         IsInZeroGravity();                                                                                                                 // 078
		virtual void         Unk_79();                                                                                                                          // 079
		virtual BGSScene*    GetCurrentScene() const;                                                                                                           // 07A
		virtual void         Unk_7B();                                                                                                                          // 07B
		virtual void         Unk_7C();                                                                                                                          // 07C
		virtual void         Unk_7D();                                                                                                                          // 07D
		virtual void         Unk_7E();                                                                                                                          // 07E
		virtual void         Unk_7F();                                                                                                                          // 07F
		virtual void         Unk_80();                                                                                                                          // 080
		virtual void         Unk_81();                                                                                                                          // 081
		virtual void         Unk_82();                                                                                                                          // 082
		virtual void         Unk_83();                                                                                                                          // 083
		virtual void         Unk_84();                                                                                                                          // 084
		virtual void         Unk_85();                                                                                                                          // 085
		virtual void         Unk_86();                                                                                                                          // 086
		virtual void         Unk_87();                                                                                                                          // 087
		virtual void         Unk_88();                                                                                                                          // 088
		virtual void         Unk_89();                                                                                                                          // 089
		virtual void         Unk_8A();                                                                                                                          // 08A
		virtual void         Unk_8B();                                                                                                                          // 08B
		virtual void         Unk_8C();                                                                                                                          // 08C
		virtual void         Unk_8D();                                                                                                                          // 08D
		virtual void         Unk_8E();                                                                                                                          // 08E
		virtual void         Unk_8F();                                                                                                                          // 08F
		virtual void         Unk_90();                                                                                                                          // 090
		virtual void         Unk_91();                                                                                                                          // 091
		virtual void         Unk_92();                                                                                                                          // 092
		virtual void         Unk_93();                                                                                                                          // 093
		virtual void         Unk_94();                                                                                                                          // 094
		virtual void         Unk_95();                                                                                                                          // 095
		virtual void         Unk_96();                                                                                                                          // 096
		virtual void         Unk_97();                                                                                                                          // 097
		virtual float        GetGravityScale();                                                                                                                 // 098 - new
		virtual void         Unk_99();                                                                                                                          // 099
		virtual void         Unk_9A();                                                                                                                          // 09A
		virtual void         Unk_9B();                                                                                                                          // 09B
		virtual void         Unk_9C();                                                                                                                          // 09C
		virtual void         Unk_9D();                                                                                                                          // 09D
		virtual void         Unk_9E();                                                                                                                          // 09E
		virtual bool         IsChild() const;                                                                                                                   // 09F
		virtual void         Unk_A0();                                                                                                                          // 0A0
		virtual void         Unk_A1();                                                                                                                          // 0A1
		virtual void         Unk_A2();                                                                                                                          // 0A2
		virtual void         Unk_A3();                                                                                                                          // 0A3
		virtual void         Unk_A4();                                                                                                                          // 0A4
		virtual void         Unk_A5();                                                                                                                          // 0A5
		virtual void         Unk_A6();                                                                                                                          // 0A6
		virtual void         Unk_A7();                                                                                                                          // 0A7
		virtual void         Unk_A8();                                                                                                                          // 0A8
		virtual void         Unk_A9();                                                                                                                          // 0A9
		virtual void         Unk_AA();                                                                                                                          // 0AA
		virtual void         Unk_AB();                                                                                                                          // 0AB - { return Get3D(a_objectOut) };?
		virtual void         Unk_AC();                                                                                                                          // 0AC - Get3D(NiPointer<NiAVObject>&)?
		virtual void         Unk_AD();                                                                                                                          // 0AD
		virtual void         Unk_AE();                                                                                                                          // 0AE
		virtual TESModel*    GetTESModel() const;                                                                                                               // 0AF
		virtual TESRace*     GetVisualsRace() const;                                                                                                            // 0B0
		virtual void         Unk_B1();                                                                                                                          // 0B1
		virtual void         Unk_B2();                                                                                                                          // 0B2
		virtual void         Unk_B3();                                                                                                                          // 0B3
		virtual NiPoint3     GetBoundMin() const;                                                                                                               // 0B4
		virtual NiPoint3     GetBoundMax() const;                                                                                                               // 0B5
		virtual void         Unk_B6();                                                                                                                          // 0B6
		virtual void         Unk_B7();                                                                                                                          // 0B7
		virtual void         Unk_B8();                                                                                                                          // 0B8
		virtual void         Unk_B9();                                                                                                                          // 0B9
		virtual void         Unk_BA();                                                                                                                          // 0BA
		virtual void         Unk_BB();                                                                                                                          // 0BB
		virtual void         Unk_BC();                                                                                                                          // 0BC
		virtual void         Unk_BD();                                                                                                                          // 0BD
		virtual void         Unk_BE();                                                                                                                          // 0BE
		virtual void         Unk_BF();                                                                                                                          // 0BF
		virtual void         Unk_C0();                                                                                                                          // 0C0
		virtual void         Unk_C1();                                                                                                                          // 0C1
		virtual void         Unk_C2();                                                                                                                          // 0C2
		virtual void         Unk_C3();                                                                                                                          // 0C3
		virtual void         Unk_C4();                                                                                                                          // 0C4
		virtual void         Unk_C5();                                                                                                                          // 0C5
		virtual void         Unk_C6();                                                                                                                          // 0C6
		virtual void         Unk_C7();                                                                                                                          // 0C7
		virtual void         Unk_C8();                                                                                                                          // 0C8
		virtual void         Unk_C9();                                                                                                                          // 0C9
		virtual void         Unk_CA();                                                                                                                          // 0CA
		virtual void         Unk_CB();                                                                                                                          // 0CB
		virtual void         Unk_CC();                                                                                                                          // 0CC
		virtual void         Unk_CD();                                                                                                                          // 0CD
		virtual void         Unk_CE();                                                                                                                          // 0CE
		virtual void         Unk_CF();                                                                                                                          // 0CF
		virtual void         Unk_D0();                                                                                                                          // 0D0
		virtual void         Unk_D1();                                                                                                                          // 0D1
		virtual void         Unk_D2();                                                                                                                          // 0D2
		virtual void         Unk_D3();                                                                                                                          // 0D3
		virtual void         Unk_D4();                                                                                                                          // 0D4
		virtual void         Unk_D5();                                                                                                                          // 0D5
		virtual void         Unk_D6();                                                                                                                          // 0D6
		virtual void         Unk_D7();                                                                                                                          // 0D7
		virtual void         Unk_D8();                                                                                                                          // 0D8
		virtual void         Unk_D9();                                                                                                                          // 0D9
		virtual void         Unk_DA();                                                                                                                          // 0DA
		virtual void         Unk_DB();                                                                                                                          // 0DB
		virtual void         Unk_DC();                                                                                                                          // 0DC
		virtual void         Unk_DD();                                                                                                                          // 0DD
		virtual void         Unk_DE();                                                                                                                          // 0DE
		virtual void         Unk_DF();                                                                                                                          // 0DF
		virtual void         Unk_E0();                                                                                                                          // 0E0
		virtual void         Unk_E1();                                                                                                                          // 0E1
		virtual void         Unk_E2();                                                                                                                          // 0E2
		virtual void         Unk_E3();                                                                                                                          // 0E3
		virtual void         Unk_E4();                                                                                                                          // 0E4
		virtual void         Unk_E5();                                                                                                                          // 0E5
		virtual void         Unk_E6();                                                                                                                          // 0E6
		virtual void         Unk_E7();                                                                                                                          // 0E7
		virtual void         Unk_E8();                                                                                                                          // 0E8
		virtual void         Unk_E9();                                                                                                                          // 0E9
		virtual void         Unk_EA();                                                                                                                          // 0EA
		virtual void         Unk_EB();                                                                                                                          // 0EB
		virtual void         Unk_EC();                                                                                                                          // 0EC
		virtual void         Unk_ED();                                                                                                                          // 0ED
		virtual void         Unk_EE();                                                                                                                          // 0EE
		virtual void         Unk_EF();                                                                                                                          // 0EF
		virtual void         Unk_F0();                                                                                                                          // 0F0
		virtual void         Unk_F1();                                                                                                                          // 0F1
		virtual const char*  GetDisplayFullName();                                                                                                              // 0F2
		virtual void         Unk_F3();                                                                                                                          // 0F3
		virtual void         Unk_F4();                                                                                                                          // 0F4
		virtual void         Unk_F5();                                                                                                                          // 0F5
		virtual void         Unk_F6();                                                                                                                          // 0F6
		virtual void         SetObjectReference(TESBoundObject* a_object, bool a_clearData);                                                                    // 0F7
		virtual void         Unk_F8();                                                                                                                          // 0F8
		virtual void         Unk_F9();                                                                                                                          // 0F9
		virtual void         Unk_FA();                                                                                                                          // 0FA
		virtual void         Unk_FB();                                                                                                                          // 0FB
		virtual void         Unk_FC();                                                                                                                          // 0FC
		virtual void         Unk_FD();                                                                                                                          // 0FD
		virtual void         Unk_FE();                                                                                                                          // 0FE
		virtual void         Unk_FF();                                                                                                                          // 0FF
		virtual void         Unk_100();                                                                                                                         // 100
		virtual void         Unk_101();                                                                                                                         // 101
		virtual void         Unk_102();                                                                                                                         // 102
		virtual void         Unk_103();                                                                                                                         // 103
		virtual void         Unk_104();                                                                                                                         // 104
		virtual void         Unk_105();                                                                                                                         // 105
		virtual void         Unk_106();                                                                                                                         // 106
		virtual void         Unk_107();                                                                                                                         // 107
		virtual void         Unk_108();                                                                                                                         // 108
		virtual void         Unk_109();                                                                                                                         // 109
		virtual void         Unk_10A();                                                                                                                         // 10A
		virtual void         Unk_10B();                                                                                                                         // 10B
		virtual void         SetParentCell(TESObjectCELL* a_cell);                                                                                              // 10C
		virtual bool         IsDead(bool a_notEssential) const;                                                                                                 // 10D
		virtual bool         ProcessInWater(std::uint32_t a_bodyID, float a_waterHeight, float a_deltaTime);                                                    // 10E
		virtual void         Unk_10F();                                                                                                                         // 10F
		virtual void         Unk_110();                                                                                                                         // 110
		virtual void         Unk_111();                                                                                                                         // 111
		virtual void         Unk_112();                                                                                                                         // 112
		virtual void         Unk_113();                                                                                                                         // 113
		virtual void         Unk_114();                                                                                                                         // 114
		virtual void         Unk_115();                                                                                                                         // 115
		virtual void         Unk_116();                                                                                                                         // 116
		virtual void         Unk_117();                                                                                                                         // 117
		virtual void         Unk_118();                                                                                                                         // 118
		virtual void         Unk_119();                                                                                                                         // 119
		virtual void         Unk_11A();                                                                                                                         // 11A
		virtual void         Unk_11B();                                                                                                                         // 11B
		virtual void         Unk_11C();                                                                                                                         // 11C
		virtual void         Unk_11D();                                                                                                                         // 11D
		virtual void         Unk_11E();                                                                                                                         // 11E
		virtual void         Unk_11F();                                                                                                                         // 11F
		virtual void         Unk_120();                                                                                                                         // 120
		virtual void         Unk_121();                                                                                                                         // 121
		virtual void         Unk_122();                                                                                                                         // 122
		virtual void         Unk_123();                                                                                                                         // 123
		virtual void         Unk_124();                                                                                                                         // 124
		virtual void         Unk_125();                                                                                                                         // 125
		virtual void         Unk_126();                                                                                                                         // 126
		virtual void         Unk_127();                                                                                                                         // 127
		virtual void         Unk_128();                                                                                                                         // 128
		virtual void         Unk_129();                                                                                                                         // 129
		virtual void         Unk_12A();                                                                                                                         // 12A
		virtual void         Unk_12B();                                                                                                                         // 12B
		virtual void         Unk_12C();                                                                                                                         // 12C
		virtual void         Unk_12D();                                                                                                                         // 12D
		virtual void         Unk_12E();                                                                                                                         // 12E
		virtual void         Unk_12F();                                                                                                                         // 12F

		[[nodiscard]] constexpr NiPoint3A   GetAngle() const { return data.angle; }
		[[nodiscard]] constexpr float       GetAngleX() const { return data.angle.x; }
		[[nodiscard]] constexpr float       GetAngleY() const { return data.angle.y; }
		[[nodiscard]] constexpr float       GetAngleZ() const { return data.angle.z; }
		[[nodiscard]] TESBoundObject*       GetBaseObject() { return data.objectReference.get(); }
		[[nodiscard]] const TESBoundObject* GetBaseObject() const { return data.objectReference.get(); }
		[[nodiscard]] BGSLocation*          GetCurrentLocation();
		[[nodiscard]] TESObjectREFR*        GetLinkedRef(BGSKeyword* a_keyword);
		[[nodiscard]] TESWorldSpace*        GetParentWorldSpace();
		[[nodiscard]] constexpr NiPoint3A   GetPosition() const noexcept { return data.location; }
		[[nodiscard]] constexpr float       GetPositionX() const noexcept { return data.location.x; }
		[[nodiscard]] constexpr float       GetPositionY() const noexcept { return data.location.y; }
		[[nodiscard]] constexpr float       GetPositionZ() const noexcept { return data.location.z; }
		[[nodiscard]] TESObjectREFR*        GetSpaceship(bool a_arg1 = true);
		[[nodiscard]] TESObjectREFR*        GetSpaceshipParentDock();
		[[nodiscard]] Actor*                GetSpaceshipPilot();
		[[nodiscard]] std::int32_t          GetValue();
		[[nodiscard]] bool                  HasKeyword(BGSKeyword* a_keyword);
		[[nodiscard]] bool                  IsCrimeToActivate();
		[[nodiscard]] bool                  IsInSpace(bool a_arg1);
		[[nodiscard]] bool                  IsSpaceshipDocked();
		[[nodiscard]] bool                  IsSpaceshipLanded();

		// members
		OBJ_REFR                data;               // 0A0
		BGSInventoryList*       inventoryList;      // 0D0 - this + lock is one struct?
		mutable BSReadWriteLock inventoryListLock;  // 0D8
		TESObjectCELL*          parentCell;         // 0E0
		LOADED_REF_DATA*        loadedData;         // 0E8 - same as above
		mutable BSReadWriteLock loadedDataLock;     // 0F0
		std::uint64_t           extraDataList;      // 0F8
		BGSLocalizedString      unk100;             // 100 - empty?
		std::uint16_t           scale;              // 108
		bool                    unk10A;             // 10A
		std::uint8_t            flags;              // 10B
	};
	static_assert(sizeof(TESObjectREFR) == 0x110);
}
