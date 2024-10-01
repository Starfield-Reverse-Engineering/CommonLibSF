#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BGSBlockBashData.h"
#include "RE/B/BGSDestructibleObjectForm.h"
#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSEquipType.h"
#include "RE/B/BGSInstanceNamingRulesForm.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BGSPreloadable.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/T/TESBoundObject.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESEnchantableForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class TESObjectWEAPInstanceData;

	namespace BGSMod::Attachment
	{
		class Mod;
	}

	class TESObjectWEAP :
		public TESBoundObject,             // 000
		public TESFullName,                // 0E0
		public BGSModelMaterialSwap,       // 0F0
		public TESEnchantableForm,         // 118
		public BGSDestructibleObjectForm,  // 130
		public BGSEquipType,               // 140
		public BGSPreloadable,             // 150
		public BGSPickupPutdownSounds,     // 158
		public BGSBlockBashData,           // 1C0
		public BGSKeywordForm,             // 1D8
		public TESDescription,             // 208
		public BGSInstanceNamingRulesForm  // 220
	{
	public:
		SF_RTTI_VTABLE(TESObjectWEAP);
		SF_FORMTYPE(WEAP);

		~TESObjectWEAP() override;  // 00

		// members
		BGSEditorID                                formEditorID;       // 230
		BSTSmartPointer<TESObjectWEAPInstanceData> weaponData;         // 240
		BGSAttachParentArray                       attachParents;      // 248
		BGSMod::Attachment::Mod*                   embeddedWeaponMod;  // 268
		std::uint8_t                               unk270;             // 270
	};
	static_assert(sizeof(TESObjectWEAP) == 0x280);
}
