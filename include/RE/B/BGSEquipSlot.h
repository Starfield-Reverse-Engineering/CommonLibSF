#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class ActorValueInfo;

	class BGSEquipSlot : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSEquipSlot);
		SF_FORMTYPE(EQUP);

		enum class Flag  // DATA
		{
			kNone = 0,
			kUseAllParents = 1 << 0,
			kParentsOptional = 1 << 1,
			kItemSlot = 1 << 2
		};

		~BGSEquipSlot() override;  // 00

		// members
		BGSEditorID                       formEditorID;         // 30
		BSTArray<BGSEquipSlot*>           parentSlots;          // 40
		ActorValueInfo*                   conditionActorValue;  // 50
		REX::EnumSet<Flag, std::uint32_t> flags;                // 58
	};
	static_assert(sizeof(BGSEquipSlot) == 0x68);
}
