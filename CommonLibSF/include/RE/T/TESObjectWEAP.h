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
		public TESFullName,                // 118
		public BGSModelMaterialSwap,       // 128
		public TESEnchantableForm,         // 150
		public BGSDestructibleObjectForm,  // 168
		public BGSEquipType,               // 178
		public BGSPreloadable,             // 188
		public BGSPickupPutdownSounds,     // 190
		public BGSBlockBashData,           // 1F8
		public BGSKeywordForm,             // 210
		public TESDescription,             // 240
		public BGSInstanceNamingRulesForm  // 258
	{
	public:
		SF_RTTI_VTABLE(TESObjectWEAP);
		SF_FORMTYPE(WEAP);

		~TESObjectWEAP() override;  // 00

		// members
		BGSEditorID                                formEditorID;       // 268
		BSTSmartPointer<TESObjectWEAPInstanceData> weaponData;         // 278
		BGSAttachParentArray                       attachParents;      // 280
		BGSMod::Attachment::Mod*                   embeddedWeaponMod;  // 2A0
		std::uint8_t                               unk2A8;             // 2A8
	};
	static_assert(sizeof(TESObjectWEAP) == 0x2B0);
}
