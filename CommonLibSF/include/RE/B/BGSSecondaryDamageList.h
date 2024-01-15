#pragma once

#include "RE/B/BSTList.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class ActorValueInfo;
	class BGSDamageType;

	struct SECONDARY_DAMAGE
	{
	public:
		// members
		BGSDamageType*  damageType;  // 00
		ActorValueInfo* actorValue;  // 08
	};
	static_assert(sizeof(SECONDARY_DAMAGE) == 0x10);

	class BGSSecondaryDamageList : public TESForm
	{
	public:
		SF_RTTI_VTABLE(BGSSecondaryDamageList);
		SF_FORMTYPE(SDLT);

		~BGSSecondaryDamageList() override;  // 00

		// members
		BSSimpleList<SECONDARY_DAMAGE> secondaryDamages;  // 30
	};
	static_assert(sizeof(BGSSecondaryDamageList) == 0x48);
}
