#include "RE/T/TESObjectREFR.h"

namespace RE
{
	BGSLocation* TESObjectREFR::GetCurrentLocation()
	{
		using func_t = decltype(&TESObjectREFR::GetCurrentLocation);
		REL::Relocation<func_t> func{ REL::Offset(0x01A0505C) };
		return func(this);
	}

	TESObjectREFR* TESObjectREFR::GetLinkedRef(BGSKeyword* a_keyword)
	{
		using func_t = decltype(&TESObjectREFR::GetLinkedRef);
		REL::Relocation<func_t> func{ REL::Offset(0x1A379E4) };
		return func(this, a_keyword);
	}

	TESWorldSpace* TESObjectREFR::GetParentWorldSpace()
	{
		using func_t = decltype(&TESObjectREFR::GetParentWorldSpace);
		REL::Relocation<func_t> func{ REL::Offset(0x01A093BC) };
		return func(this);
	}

	TESObjectREFR* TESObjectREFR::GetSpaceship(bool a_arg1)
	{
		using func_t = decltype(&TESObjectREFR::GetSpaceship);
		REL::Relocation<func_t> func{ REL::Offset(0x02B3A714) };
		return func(this, a_arg1);
	}

	TESObjectREFR* TESObjectREFR::GetSpaceshipParentDock()
	{
		using func_t = decltype(&TESObjectREFR::GetSpaceshipParentDock);
		REL::Relocation<func_t> func{ REL::Offset(0x02B53DC0) };
		return func(this);
	}

	Actor* TESObjectREFR::GetSpaceshipPilot()
	{
		using func_t = decltype(&TESObjectREFR::GetSpaceshipPilot);
		REL::Relocation<func_t> func{ REL::Offset(0x02B39D74) };
		return func(this);
	}

	std::int32_t TESObjectREFR::GetValue()
	{
		using func_t = decltype(&TESObjectREFR::GetValue);
		REL::Relocation<func_t> func{ REL::Offset(0x01A38790) };
		return func(this);
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

	bool TESObjectREFR::IsInSpace(bool a_arg1)
	{
		using func_t = decltype(&TESObjectREFR::IsInSpace);
		REL::Relocation<func_t> func{ REL::Offset(0x01A0E1C8) };
		return func(this, a_arg1);
	}
}
