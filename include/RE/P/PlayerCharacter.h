#pragma once

#include "RE/A/Actor.h"
#include "RE/I/IMovementPlayerControlsFilter.h"

namespace RE
{
	class MenuModeChangeEvent;
	class MenuOpenCloseEvent;
	class OtherEventEnabledEvent;
	struct TESFormDeleteEvent;
	class TESHitEvent;
	class UserEventEnabledEvent;

	struct AnimationGraphDependentEvent;
	struct BGSActorCellEvent;
	struct BGSActorDeathEvent;
	struct PickRefUpdateEvent;
	struct PositionPlayerEvent;
	struct TargetHitEvent;

	struct QuestStatus
	{
		struct Event;
	};

	struct TESQuestEvent
	{
		struct Event;
	};

	namespace PerkValueEvents
	{
		struct PerkEntryUpdatedEvent;
	}

	class PlayerCharacter :
		public Actor,                                                 // 000
		public BSTEventSource<BGSActorCellEvent>,                     // 530
		public BSTEventSource<BGSActorDeathEvent>,                    // 558
		public BSTEventSource<PositionPlayerEvent>,                   // 580
		public BSTEventSource<PickRefUpdateEvent>,                    // 5A8
		public BSTEventSource<TargetHitEvent>,                        // 5D0
		public BSTEventSink<MenuOpenCloseEvent>,                      // 5F8
		public BSTEventSink<MenuModeChangeEvent>,                     // 600
		public BSTEventSink<UserEventEnabledEvent>,                   // 608
		public BSTEventSink<OtherEventEnabledEvent>,                  // 610
		public BSTEventSink<TESFormDeleteEvent>,                      // 618
		public BSTEventSink<TESHitEvent>,                             // 620
		public BSTEventSink<PerkValueEvents::PerkEntryUpdatedEvent>,  // 628
		public BSTEventSink<AnimationGraphDependentEvent>,            // 630
		public BSTEventSink<TESQuestEvent::Event>,                    // 638
		public BSTEventSink<QuestStatus::Event>,                      // 640
		public IMovementPlayerControlsFilter                          // 648
	{
	public:
		SF_RTTI_VTABLE(PlayerCharacter);
		SF_FORMTYPE(ACHR);

		~PlayerCharacter() override;  // 00

		// 0Add
		virtual void Unk_1A2();  // 1A2
		virtual void Unk_1A3();  // 1A3
		virtual void Unk_1A4();  // 1A4
		virtual void Unk_1A5();  // 1A5

		[[nodiscard]] static PlayerCharacter* GetSingleton();

		bool IsInChargen();

		// members
		std::uint64_t  unk0650;          // 0650
		std::uint64_t  unk0658;          // 0658
		std::uint64_t  unk0660;          // 0660
		std::uint64_t  unk0668;          // 0668
		std::uint64_t  unk0670;          // 0670
		std::uint64_t  unk0678;          // 0678
		std::uint64_t  unk0680;          // 0680
		std::uint64_t  unk0688;          // 0688
		std::uint64_t  unk0690;          // 0690
		std::uint64_t  unk0698;          // 0698
		std::uint64_t  unk06A0;          // 06A0
		std::uint64_t  unk06A8;          // 06A8
		std::uint64_t  unk06B0;          // 06B0
		std::uint64_t  unk06B8;          // 06B8
		std::uint64_t  unk06C0;          // 06C0
		std::uint64_t  unk06C8;          // 06C8
		std::uint64_t  unk06D0;          // 06D0
		std::uint64_t  unk06D8;          // 06D8
		std::uint64_t  unk06E0;          // 06E0
		std::uint64_t  unk06E8;          // 06E8
		std::uint64_t  unk06F0;          // 06F0
		std::uint64_t  unk06F8;          // 06F8
		std::uint64_t  unk0700;          // 0700
		std::uint64_t  unk0708;          // 0708
		std::uint64_t  unk0710;          // 0710
		std::uint64_t  unk0718;          // 0718
		std::uint64_t  unk0720;          // 0720
		std::uint64_t  unk0728;          // 0728
		std::uint64_t  unk0730;          // 0730
		std::uint64_t  unk0738;          // 0738
		std::uint64_t  unk0740;          // 0740
		std::uint64_t  unk0748;          // 0748
		std::uint64_t  unk0750;          // 0750
		std::uint64_t  unk0758;          // 0758
		std::uint64_t  unk0760;          // 0760
		std::uint64_t  unk0768;          // 0768
		std::uint64_t  unk0770;          // 0770
		std::uint64_t  unk0778;          // 0778
		std::uint64_t  unk0780;          // 0780
		std::uint64_t  unk0788;          // 0788
		std::uint64_t  unk0790;          // 0790
		std::uint64_t  unk0798;          // 0798
		std::uint64_t  unk07A0;          // 07A0
		std::uint64_t  unk07A8;          // 07A8
		std::uint64_t  unk07B0;          // 07B0
		std::uint64_t  unk07B8;          // 07B8
		std::uint64_t  unk07C0;          // 07C0
		std::uint64_t  unk07C8;          // 07C8
		std::uint64_t  unk07D0;          // 07D0
		std::uint64_t  unk07D8;          // 07D8
		std::uint64_t  unk07E0;          // 07E0
		std::uint64_t  unk07E8;          // 07E8
		std::uint64_t  unk07F0;          // 07F0
		std::uint64_t  unk07F8;          // 07F8
		std::uint64_t  unk0800;          // 0800
		std::uint64_t  unk0808;          // 0808
		std::uint64_t  unk0810;          // 0810
		std::uint64_t  unk0818;          // 0818
		std::uint64_t  unk0820;          // 0820
		std::uint64_t  unk0828;          // 0828
		std::uint64_t  unk0830;          // 0830
		std::uint64_t  unk0838;          // 0838
		std::uint64_t  unk0840;          // 0840
		std::uint64_t  unk0848;          // 0848
		std::uint64_t  unk0850;          // 0850
		std::uint64_t  unk0858;          // 0858
		std::uint64_t  unk0860;          // 0860
		std::uint64_t  unk0868;          // 0868
		std::uint64_t  unk0870;          // 0870
		std::uint64_t  unk0878;          // 0878
		std::uint64_t  unk0880;          // 0880
		std::uint64_t  unk0888;          // 0888
		std::uint64_t  unk0890;          // 0890
		std::uint64_t  unk0898;          // 0898
		std::uint64_t  unk08A0;          // 08A0
		std::uint64_t  unk08A8;          // 08A8
		std::uint64_t  unk08B0;          // 08B0
		std::uint64_t  unk08B8;          // 08B8
		std::uint64_t  unk08C0;          // 08C0
		std::uint64_t  unk08C8;          // 08C8
		std::uint64_t  unk08D0;          // 08D0
		std::uint64_t  unk08D8;          // 08D8
		std::uint64_t  unk08E0;          // 08E0
		std::uint64_t  unk08E8;          // 08E8
		std::uint64_t  unk08F0;          // 08F0
		std::uint64_t  unk08F8;          // 08F8
		std::uint64_t  unk0900;          // 0900
		std::uint64_t  unk0908;          // 0908
		std::uint64_t  unk0910;          // 0910
		std::uint64_t  unk0918;          // 0918
		std::uint64_t  unk0920;          // 0920
		std::uint64_t  unk0928;          // 0928
		std::uint64_t  unk0930;          // 0930
		std::uint64_t  unk0938;          // 0938
		std::uint64_t  unk0940;          // 0940
		std::uint64_t  unk0948;          // 0948
		std::uint64_t  unk0950;          // 0950
		std::uint64_t  unk0958;          // 0958
		std::uint64_t  unk0960;          // 0960
		std::uint64_t  unk0968;          // 0968
		std::uint64_t  unk0970;          // 0970
		std::uint64_t  unk0978;          // 0978
		std::uint64_t  unk0980;          // 0980
		std::uint64_t  unk0988;          // 0988
		std::uint64_t  unk0990;          // 0990
		std::uint64_t  unk0998;          // 0998
		std::uint64_t  unk09A0;          // 09A0
		std::uint64_t  unk09A8;          // 09A8
		std::uint64_t  unk09B0;          // 09B0
		std::uint64_t  unk09B8;          // 09B8
		std::uint64_t  unk09C0;          // 09C0
		std::uint64_t  unk09C8;          // 09C8
		std::uint64_t  unk09D0;          // 09D0
		std::uint64_t  unk09D8;          // 09D8
		std::uint64_t  unk09E0;          // 09E0
		std::uint64_t  unk09E8;          // 09E8
		std::uint64_t  unk09F0;          // 09F0
		std::uint64_t  unk09F8;          // 09F8
		std::uint64_t  unk0A00;          // 0A00
		std::uint64_t  unk0A08;          // 0A08
		std::uint64_t  unk0A10;          // 0A10
		std::uint64_t  unk0A18;          // 0A18
		std::uint64_t  unk0A20;          // 0A20
		std::uint64_t  unk0A28;          // 0A28
		std::uint64_t  unk0A30;          // 0A30
		std::uint64_t  unk0A38;          // 0A38
		std::uint64_t  unk0A40;          // 0A40
		std::uint64_t  unk0A48;          // 0A48
		std::uint64_t  unk0A50;          // 0A50
		std::uint64_t  unk0A58;          // 0A58
		std::uint64_t  unk0A60;          // 0A60
		std::uint64_t  unk0A68;          // 0A68
		std::uint64_t  unk0A70;          // 0A70
		std::uint64_t  unk0A78;          // 0A78
		std::uint64_t  unk0A80;          // 0A80
		std::uint64_t  unk0A88;          // 0A88
		std::uint64_t  unk0A90;          // 0A90
		std::uint64_t  unk0A98;          // 0A98
		std::uint64_t  unk0AA0;          // 0AA0
		std::uint64_t  unk0AA8;          // 0AA8
		std::uint64_t  unk0AB0;          // 0AB0
		std::uint64_t  unk0AB8;          // 0AB8
		std::uint64_t  unk0AC0;          // 0AC0
		std::uint64_t  unk0AC8;          // 0AC8
		std::uint64_t  unk0AD0;          // 0AD0
		std::uint64_t  unk0AD8;          // 0AD8
		std::uint64_t  unk0AE0;          // 0AE0
		std::uint64_t  unk0AE8;          // 0AE8
		std::uint64_t  unk0AF0;          // 0AF0
		std::uint64_t  unk0AF8;          // 0AF8
		std::uint64_t  unk0B00;          // 0B00
		std::uint64_t  unk0B08;          // 0B08
		std::uint64_t  unk0B10;          // 0B10
		std::uint64_t  unk0B18;          // 0B18
		std::uint64_t  unk0B20;          // 0B20
		std::uint64_t  unk0B28;          // 0B28
		std::uint64_t  unk0B30;          // 0B30
		std::uint64_t  unk0B38;          // 0B38
		std::uint64_t  unk0B40;          // 0B40
		std::uint64_t  unk0B48;          // 0B48
		std::uint64_t  unk0B50;          // 0B50
		std::uint64_t  unk0B58;          // 0B58
		std::uint64_t  unk0B60;          // 0B60
		std::uint64_t  unk0B68;          // 0B68
		std::uint64_t  unk0B70;          // 0B70
		std::uint64_t  unk0B78;          // 0B78
		std::uint64_t  unk0B80;          // 0B80
		std::uint64_t  unk0B88;          // 0B88
		std::uint64_t  unk0B90;          // 0B90
		std::uint64_t  unk0B98;          // 0B98
		std::uint64_t  unk0BA0;          // 0BA0
		std::uint64_t  unk0BA8;          // 0BA8
		std::uint64_t  unk0BB0;          // 0BB0
		std::uint64_t  unk0BB8;          // 0BB8
		std::uint64_t  unk0BC0;          // 0BC0
		std::uint64_t  unk0BC8;          // 0BC8
		std::uint64_t  unk0BD0;          // 0BD0
		std::uint64_t  unk0BD8;          // 0BD8
		std::uint64_t  unk0BE0;          // 0BE0
		std::uint64_t  unk0BE8;          // 0BE8
		std::uint64_t  unk0BF0;          // 0BF0
		std::uint64_t  unk0BF8;          // 0BF8
		std::uint64_t  unk0C00;          // 0C00
		std::uint64_t  unk0C08;          // 0C08
		std::uint64_t  unk0C10;          // 0C10
		std::uint64_t  unk0C18;          // 0C18
		std::uint64_t  unk0C20;          // 0C20
		std::uint64_t  unk0C28;          // 0C28
		std::uint64_t  unk0C30;          // 0C30
		std::uint64_t  unk0C38;          // 0C38
		std::uint64_t  unk0C40;          // 0C40
		std::uint64_t  unk0C48;          // 0C48
		std::uint64_t  unk0C50;          // 0C50
		std::uint64_t  unk0C58;          // 0C58
		std::uint64_t  unk0C60;          // 0C60
		std::uint64_t  unk0C68;          // 0C68
		std::uint64_t  unk0C70;          // 0C70
		std::uint64_t  unk0C78;          // 0C78
		std::uint64_t  unk0C80;          // 0C80
		std::uint64_t  unk0C88;          // 0C88
		std::uint64_t  unk0C90;          // 0C90
		std::uint64_t  unk0C98;          // 0C98
		std::uint64_t  unk0CA0;          // 0CA0
		std::uint64_t  unk0CA8;          // 0CA8
		std::uint64_t  unk0CB0;          // 0CB0
		std::uint64_t  unk0CB8;          // 0CB8
		std::uint64_t  unk0CC0;          // 0CC0
		std::uint64_t  unk0CC8;          // 0CC8
		std::uint64_t  unk0CD0;          // 0CD0
		std::uint64_t  unk0CD8;          // 0CD8
		std::uint64_t  unk0CE0;          // 0CE0
		std::uint64_t  unk0CE8;          // 0CE8
		std::uint64_t  unk0CF0;          // 0CF0
		std::uint64_t  unk0CF8;          // 0CF8
		std::uint64_t  unk0D00;          // 0D00
		std::uint64_t  unk0D08;          // 0D08
		std::uint64_t  unk0D10;          // 0D10
		std::uint64_t  unk0D18;          // 0D18
		std::uint64_t  unk0D20;          // 0D20
		std::uint64_t  unk0D28;          // 0D28
		std::uint64_t  unk0D30;          // 0D30
		std::uint64_t  unk0D38;          // 0D38
		std::uint64_t  unk0D40;          // 0D40
		std::uint64_t  unk0D48;          // 0D48
		std::uint64_t  unk0D50;          // 0D50
		std::uint64_t  unk0D58;          // 0D58
		std::uint64_t  unk0D60;          // 0D60
		std::uint64_t  unk0D68;          // 0D68
		std::uint64_t  unk0D70;          // 0D70
		std::uint64_t  unk0D78;          // 0D78
		std::uint64_t  unk0D80;          // 0D80
		std::uint64_t  unk0D88;          // 0D88
		std::uint64_t  unk0D90;          // 0D90
		std::uint64_t  unk0D98;          // 0D98
		std::uint64_t  unk0DA0;          // 0DA0
		std::uint64_t  unk0DA8;          // 0DA8
		std::uint64_t  unk0DB0;          // 0DB0
		std::uint64_t  unk0DB8;          // 0DB8
		std::uint64_t  unk0DC0;          // 0DC0
		std::uint64_t  unk0DC8;          // 0DC8
		std::uint64_t  unk0DD0;          // 0DD0
		std::uint64_t  unk0DD8;          // 0DD8
		std::uint64_t  unk0DE0;          // 0DE0
		std::uint64_t  unk0DE8;          // 0DE8
		std::uint64_t  unk0DF0;          // 0DF0
		std::uint64_t  unk0DF8;          // 0DF8
		std::uint64_t  unk0E00;          // 0E00
		std::uint64_t  unk0E08;          // 0E08
		std::uint64_t  unk0E10;          // 0E10
		std::uint64_t  unk0E18;          // 0E18
		std::uint64_t  unk0E20;          // 0E20
		std::uint64_t  unk0E28;          // 0E28
		std::uint64_t  unk0E30;          // 0E30
		std::uint64_t  unk0E38;          // 0E38
		std::uint64_t  unk0E40;          // 0E40
		std::uint64_t  unk0E48;          // 0E48
		std::uint64_t  unk0E50;          // 0E50
		std::uint64_t  unk0E58;          // 0E58
		std::uint64_t  unk0E60;          // 0E60
		std::uint64_t  unk0E68;          // 0E68
		std::uint64_t  unk0E70;          // 0E70
		std::uint64_t  unk0E78;          // 0E78
		std::uint64_t  unk0E80;          // 0E80
		std::uint64_t  unk0E88;          // 0E88
		std::uint64_t  unk0E90;          // 0E90
		std::uint64_t  unk0E98;          // 0E98
		std::uint64_t  unk0EA0;          // 0EA0
		std::uint64_t  unk0EA8;          // 0EA8
		std::uint64_t  unk0EB0;          // 0EB0
		std::uint64_t  unk0EB8;          // 0EB8
		std::uint64_t  unk0EC0;          // 0EC0
		std::uint64_t  unk0EC8;          // 0EC8
		std::uint64_t  unk0ED0;          // 0ED0
		BGSLocation*   currentLocation;  // 0ED8
		std::uint64_t  unk0EE0;          // 0EE0
		std::uint64_t  unk0EE8;          // 0EE8
		std::uint64_t  unk0EF0;          // 0EF0
		std::uint64_t  unk0EF8;          // 0EF8
		std::uint64_t  unk0F00;          // 0F00
		std::uint64_t  unk0F08;          // 0F08
		std::uint64_t  unk0F10;          // 0F10
		std::uint64_t  unk0F18;          // 0F18
		std::uint64_t  unk0F20;          // 0F20
		std::uint64_t  unk0F28;          // 0F28
		TESObjectREFR* crosshairRef;     // 0F30 - NiPointer?
		std::uint64_t  unk0F38;          // 0F38
		std::uint64_t  unk0F40;          // 0F40
		std::uint64_t  unk0F48;          // 0F48
		std::uint64_t  unk0F50;          // 0F50
		std::uint64_t  unk0F58;          // 0F58
		std::uint64_t  unk0F60;          // 0F60
		std::uint64_t  unk0F68;          // 0F68
		std::uint64_t  unk0F70;          // 0F70
		std::uint64_t  unk0F78;          // 0F78
		std::uint64_t  unk0F80;          // 0F80
		std::uint64_t  unk0F88;          // 0F88
		std::uint64_t  unk0F90;          // 0F90
		std::uint64_t  unk0F98;          // 0F98
		std::uint64_t  unk0FA0;          // 0FA0
		std::uint64_t  unk0FA8;          // 0FA8
		std::uint64_t  unk0FB0;          // 0FB0
		std::uint64_t  unk0FB8;          // 0FB8
		std::uint64_t  unk0FC0;          // 0FC0
		std::uint64_t  unk0FC8;          // 0FC8
		std::uint64_t  unk0FD0;          // 0FD0
		std::uint64_t  unk0FD8;          // 0FD8
		std::uint64_t  unk0FE0;          // 0FE0
		std::uint64_t  unk0FE8;          // 0FE8
		std::uint64_t  unk0FF0;          // 0FF0
		std::uint64_t  unk0FF8;          // 0FF8
		std::uint64_t  unk1000;          // 1000
		std::uint64_t  unk1008;          // 1008
		std::uint64_t  unk1010;          // 1010
		std::uint64_t  unk1018;          // 1018
		std::uint64_t  unk1020;          // 1020
		std::uint64_t  unk1028;          // 1028
		std::uint64_t  unk1030;          // 1030
		std::uint64_t  unk1038;          // 1038
		std::uint64_t  unk1040;          // 1040
		std::uint64_t  unk1048;          // 1048
		std::uint64_t  unk1050;          // 1050
		std::uint64_t  unk1058;          // 1058
		std::uint64_t  unk1060;          // 1060
		std::uint64_t  unk1068;          // 1068
		std::uint64_t  unk1070;          // 1070
		std::uint64_t  unk1078;          // 1078
		std::uint64_t  unk1080;          // 1080
		std::uint64_t  unk1088;          // 1088
		std::uint64_t  unk1090;          // 1090
		std::uint64_t  unk1098;          // 1098
		std::uint64_t  unk10A0;          // 10A0
		std::uint64_t  unk10A8;          // 10A8
		std::uint64_t  unk10B0;          // 10B0
		std::uint64_t  unk10B8;          // 10B8
		std::uint64_t  unk10C0;          // 10C0
		std::uint64_t  unk10C8;          // 10C8
		float          playerGravity;    // 10D0
		std::uint32_t  unk10D4;          // 10D4
		std::uint64_t  unk10D8;          // 10D8
	};
	static_assert(sizeof(PlayerCharacter) == 0x1120);
}
