#include "RE/T/TESObjectREFR.h"

namespace RE
{
	TESObjectREFR* TESObjectREFR::GetAttachedSpaceship()
	{
		using func_t = decltype(&TESObjectREFR::GetAttachedSpaceship);
		REL::Relocation<func_t> func{ REL::Offset(0x02B3A714) };
		return func(this);
	}

	bool GetItemCount_Int(TESObjectREFR** this_ref, TESForm* a_Form, std::uint64_t pad, float* item_count);

	float TESObjectREFR::GetItemCount(TESForm* a_Form)
	{
		using func_t = decltype(&GetItemCount_Int);
		REL::Relocation<func_t> func{ REL::Offset(0x01A7A6DC) };
		TESObjectREFR* this_ref = this;
		float item_count = 0;
		func((&this_ref), a_Form, 0, &item_count);
		return item_count;
	}

	bool TESObjectREFR::HasKeyword(BGSKeyword* a_keyword)
	{
		using func_t = decltype(&TESObjectREFR::HasKeyword);
		REL::Relocation<func_t> func{ REL::Offset(0x0139EDB8) };
		return func(this, a_keyword);
	}

	bool TESObjectREFR::IsCrimeToActivate()
	{
		using func_t = decltype(&TESObjectREFR::IsCrimeToActivate);
		REL::Relocation<func_t> func{ REL::Offset(0x01A0DC60) };
		return func(this);
	}

	bool TESObjectREFR::IsInSpace()
	{
		using func_t = decltype(&TESObjectREFR::IsInSpace);
		REL::Relocation<func_t> func{ REL::Offset(0x01A0E1C8) };
		return func(this);
	}
}
