#include "RE/T/TESObjectREFR.h"

namespace RE
{
	BGSLocation* TESObjectREFR::GetCurrentLocation()
	{
		using func_t = decltype(&TESObjectREFR::GetCurrentLocation);
		REL::Relocation<func_t> func{ REL::ID(106554) };
		return func(this);
	}

	TESObjectREFR* TESObjectREFR::GetLinkedRef(BGSKeyword* a_keyword)
	{
		using func_t = decltype(&TESObjectREFR::GetLinkedRef);
		REL::Relocation<func_t> func{ REL::ID(107578) };
		return func(this, a_keyword);
	}

	TESWorldSpace* TESObjectREFR::GetParentWorldSpace()
	{
		using func_t = decltype(&TESObjectREFR::GetParentWorldSpace);
		REL::Relocation<func_t> func{ REL::ID(106696) };
		return func(this);
	}

	TESObjectREFR* TESObjectREFR::GetSpaceship(bool a_arg1)
	{
		using func_t = decltype(&TESObjectREFR::GetSpaceship);
		REL::Relocation<func_t> func{ REL::ID(173851) };
		return func(this, a_arg1);
	}

	TESObjectREFR* TESObjectREFR::GetSpaceshipParentDock()
	{
		using func_t = decltype(&TESObjectREFR::GetSpaceshipParentDock);
		REL::Relocation<func_t> func{ REL::ID(174134) };
		return func(this);
	}

	Actor* TESObjectREFR::GetSpaceshipPilot()
	{
		using func_t = decltype(&TESObjectREFR::GetSpaceshipPilot);
		REL::Relocation<func_t> func{ REL::ID(173834) };
		return func(this);
	}

	std::int32_t TESObjectREFR::GetValue()
	{
		using func_t = decltype(&TESObjectREFR::GetValue);
		REL::Relocation<func_t> func{ REL::ID(107605) };
		return func(this);
	}

	bool TESObjectREFR::HasKeyword(BGSKeyword* a_keyword)
	{
		using func_t = decltype(&TESObjectREFR::HasKeyword);
		REL::Relocation<func_t> func{ REL::ID(80343) };
		return func(this, a_keyword);
	}

	bool TESObjectREFR::IsCrimeToActivate()
	{
		using func_t = decltype(&TESObjectREFR::IsCrimeToActivate);
		REL::Relocation<func_t> func{ REL::ID(106755) };
		return func(this);
	}

	bool TESObjectREFR::IsInSpace(bool a_arg1)
	{
		using func_t = decltype(&TESObjectREFR::IsInSpace);
		REL::Relocation<func_t> func{ REL::ID(106767) };
		return func(this, a_arg1);
	}

	bool TESObjectREFR::IsSpaceshipDocked()
	{
		using func_t = decltype(&TESObjectREFR::IsSpaceshipDocked);
		REL::Relocation<func_t> func{ REL::ID(174146) };
		return func(this);
	}

	bool TESObjectREFR::IsSpaceshipLanded()
	{
		using func_t = decltype(&TESObjectREFR::IsSpaceshipLanded);
		REL::Relocation<func_t> func{ REL::ID(173880) };
		return func(this);
	}

}
