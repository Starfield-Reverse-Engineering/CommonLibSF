#pragma once

#include "RE/G/GameMenuBase.h"
#include "RE/I/IDataModel.h"

namespace RE
{
	class MenuPaperDoll;
	class TESNPC;

	struct CharGen_CloseMenu;
	struct CharGen_PresetChange;
	struct CharGen_HeadpartPresetChange;
	struct CharGen_SetSex;
	struct CharGen_SetSlider;
	struct CharGen_StartTextEntry;
	struct CharGen_EndTextEntry;
	struct CharGen_CancelTextEntry;
	struct CharGen_ShowPlayerRenameMessage;
	struct CharGen_ShowChooseBackgroundMessage;
	struct CharGen_SetBodyValues;
	struct CharGen_SetCameraPosition;
	struct CharGen_HeadpartPlusSelectorChange;
	struct CharGen_SkintoneChange;
	struct CharGen_DirtScarsEtcChange;
	struct CharGen_ToggleMarking;
	struct CharGen_SetTrait;
	struct CharGen_SetBackground;
	struct CharGen_EyeColorChange;
	struct CharGen_BrowChange;
	struct CharGen_HairChange;
	struct CharGen_HairColorChange;
	struct CharGen_FacialHairChange;
	struct CharGen_FacialHairColorChange;
	struct CharGen_BrowColorChange;
	struct CharGen_TeethChange;
	struct CharGen_CyclePronoun;
	struct CharGen_SetPronoun;
	struct CharGen_TogglePreviewHabSuit;
	struct CharGen_SwitchLocomotion;
	struct CharGen_SwitchBodyType;
	struct CharGen_RotatePaperdoll;
	struct CharGen_RollOnLocomotion;
	struct CharGen_RollOffLocomotion;
	struct CharGen_TeethRollOn;
	struct CharGen_TeethRollOff;
	struct CharGen_JewelryChange;
	struct CharGen_JewelryColorChange;
	struct CharGen_StartBodyChange;
	struct CharGen_EndBodyChange;
	struct CharGen_SetAdditionalSlider;
	struct CharGen_SetBlockInputUnderPopup;
	struct CharGen_PostBlendFaceChange;
	struct CharGen_PostBlendColorOptionChange;
	struct CharGen_PostBlendIntensityChange;
	struct CharGen_MakeupChange;
	struct CharGen_MarkingsChange;
	struct UIMenuChargenMenuDisablePaperdoll;

	class ChargenMenu :
		public GameMenuBase,                                       // 000
		public IDataModel,                                         // 138
		public BSTEventSink<CharGen_CloseMenu>,                    // 140
		public BSTEventSink<CharGen_PresetChange>,                 // 148
		public BSTEventSink<CharGen_HeadpartPresetChange>,         // 150
		public BSTEventSink<CharGen_SetSex>,                       // 158
		public BSTEventSink<CharGen_SetSlider>,                    // 160
		public BSTEventSink<CharGen_StartTextEntry>,               // 168
		public BSTEventSink<CharGen_EndTextEntry>,                 // 170
		public BSTEventSink<CharGen_CancelTextEntry>,              // 178
		public BSTEventSink<CharGen_ShowPlayerRenameMessage>,      // 180
		public BSTEventSink<CharGen_ShowChooseBackgroundMessage>,  // 188
		public BSTEventSink<CharGen_SetBodyValues>,                // 190
		public BSTEventSink<CharGen_SetCameraPosition>,            // 198
		public BSTEventSink<CharGen_HeadpartPlusSelectorChange>,   // 1A0
		public BSTEventSink<CharGen_SkintoneChange>,               // 1A8
		public BSTEventSink<CharGen_DirtScarsEtcChange>,           // 1B0
		public BSTEventSink<CharGen_ToggleMarking>,                // 1B8
		public BSTEventSink<CharGen_SetTrait>,                     // 1C0
		public BSTEventSink<CharGen_SetBackground>,                // 1C8
		public BSTEventSink<CharGen_EyeColorChange>,               // 1D0
		public BSTEventSink<CharGen_BrowChange>,                   // 1D8
		public BSTEventSink<CharGen_HairChange>,                   // 1E0
		public BSTEventSink<CharGen_HairColorChange>,              // 1E8
		public BSTEventSink<CharGen_FacialHairChange>,             // 1F0
		public BSTEventSink<CharGen_FacialHairColorChange>,        // 1F8
		public BSTEventSink<CharGen_BrowColorChange>,              // 200
		public BSTEventSink<CharGen_TeethChange>,                  // 208
		public BSTEventSink<CharGen_CyclePronoun>,                 // 210
		public BSTEventSink<CharGen_SetPronoun>,                   // 218
		public BSTEventSink<CharGen_TogglePreviewHabSuit>,         // 220
		public BSTEventSink<CharGen_SwitchLocomotion>,             // 228
		public BSTEventSink<CharGen_SwitchBodyType>,               // 230
		public BSTEventSink<CharGen_RotatePaperdoll>,              // 238
		public BSTEventSink<CharGen_RollOnLocomotion>,             // 240
		public BSTEventSink<CharGen_RollOffLocomotion>,            // 248
		public BSTEventSink<CharGen_TeethRollOn>,                  // 250
		public BSTEventSink<CharGen_TeethRollOff>,                 // 258
		public BSTEventSink<CharGen_JewelryChange>,                // 260
		public BSTEventSink<CharGen_JewelryColorChange>,           // 268
		public BSTEventSink<CharGen_StartBodyChange>,              // 270
		public BSTEventSink<CharGen_EndBodyChange>,                // 278
		public BSTEventSink<CharGen_SetAdditionalSlider>,          // 280
		public BSTEventSink<CharGen_SetBlockInputUnderPopup>,      // 288
		public BSTEventSink<CharGen_PostBlendFaceChange>,          // 290
		public BSTEventSink<CharGen_PostBlendColorOptionChange>,   // 298
		public BSTEventSink<CharGen_PostBlendIntensityChange>,     // 2A0
		public BSTEventSink<CharGen_MakeupChange>,                 // 2A8
		public BSTEventSink<CharGen_MarkingsChange>,               // 2B0
		public BSTEventSink<UIMenuChargenMenuDisablePaperdoll>     // 2B8
	{
	public:
		SF_RTTI_VTABLE(ChargenMenu);
		SF_MENU_NAME("ChargenMenu");

		virtual ~ChargenMenu();  // 00

		// members
		MenuPaperDoll* paperDoll;                // 2C8
		TESNPC*        npc;                      // 2D0
		std::byte      pad2D8[(0x5B8 - 0x2D8)];  // 2D8
		std::uint32_t  cameraPosition;           // 5B8
		std::uint32_t  unk5BC;                   // 5BC
		std::byte      pad5C0[(0x650 - 0x5C0)];  // 5C0
	};
	static_assert(sizeof(ChargenMenu) == 0x650);
}
