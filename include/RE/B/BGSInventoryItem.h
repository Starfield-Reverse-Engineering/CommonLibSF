#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class ExtraDataList;
	class TBO_InstanceData;
	class TESBoundObject;

	class BGSInventoryItem
	{
	public:
		struct Stack
		{
		public:
			// members
			BSTSmartPointer<ExtraDataList> extra;  // 00
			std::uint32_t                  count;  // 10
		};
		static_assert(sizeof(Stack) == 0x10);

		enum class Flag
		{
			kSlotIndex1 = 1 << 0,
			kSlotIndex2 = 1 << 1,
			kSlotIndex3 = 1 << 2,
			kEquipStateLocked = 1 << 3,
			kInvShouldEquip = 1 << 4,
			kTemporary = 1 << 5,
			kSlotMask = kSlotIndex1 | kSlotIndex2 | kSlotIndex3
		};

		[[nodiscard]] bool IsEquipped() const noexcept { return flags.any(Flag::kSlotMask); }

		// members
		TESBoundObject*                   object;        // 00
		BSTSmartPointer<TBO_InstanceData> instanceData;  // 08
		BSTArray<Stack>                   stacks;        // 10
		REX::EnumSet<Flag, std::uint32_t> flags;         // 20
		std::int8_t                       unk24;         // 24
	};
	static_assert(sizeof(BGSInventoryItem) == 0x28);
}
