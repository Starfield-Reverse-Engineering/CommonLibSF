#include "RE/T/TESNPC.h"
#include "RE/T/TESRace.h"

namespace RE
{
	bool TESNPC::ContainsKeyword(std::string_view a_editorID)
	{
		if (ContainsKeywordString(a_editorID)) {
			return true;
		}
		if (const auto npcRace = GetRace(); npcRace && npcRace->ContainsKeywordString(a_editorID)) {
			return true;
		}
		return false;
	}

	SEX TESNPC::GetSex() const
	{
		return IsFemale() ? SEX::kFemale : SEX::kMale;
	}

	bool TESNPC::HasKeyword(std::string_view a_editorID)
	{
		if (HasKeywordString(a_editorID)) {
			return true;
		}
		if (const auto npcRace = GetRace(); npcRace && npcRace->HasKeywordString(a_editorID)) {
			return true;
		}
		return false;
	}

	bool TESNPC::IsInFaction(TESFaction* a_faction) const
	{
		return std::ranges::any_of(factions, [&](const auto& faction) {
			return faction.faction == a_faction && faction.rank > -1;
		});
	}
}
