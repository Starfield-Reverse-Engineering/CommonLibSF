#pragma once

#include "RE/B/BGSKeyword.h"

namespace RE
{
	enum class KeywordType
	{
		kNone,
		kComponentTechLevel,
		kAttachPoint,
		kComponentProperty,
		kInstantiationFilter,
		kModAssociation,
		kSound,
		kAnimArchetype,
		kFunctionCall,
		kRecipeFilter,
		kAttractionType,
		kDialogueSubtype,
		kQuestTarget,
		kAnimFlavor,
		kAnimGender,
		kAnimFaceArchetype,
		kQuestGroup,
		kAnimInjured,
		kDispelEffect,

		kTotal
	};

	template <KeywordType TYPE>
	class BGSTypedKeywordValue
	{
	public:
		// members
		std::uint16_t keywordIndex;  // 0
	};

	namespace detail
	{
		[[nodiscard]] BGSKeyword* BGSKeywordGetTypedKeywordByIndex(KeywordType a_type, std::uint16_t a_index);
	}

	template <KeywordType TYPE>
	class BGSTypedKeywordValueArray
	{
	public:
		[[nodiscard]] bool HasKeyword(BGSKeyword* a_keyword)
		{
			for (std::uint32_t i = 0; i < size; ++i) {
				const auto kywd = detail::BGSKeywordGetTypedKeywordByIndex(TYPE, array[i].keywordIndex);
				if (kywd == a_keyword) {
					return true;
				}
			}
			return false;
		}

		// members
		BGSTypedKeywordValue<TYPE>* array;  // 00
		std::uint32_t               size;   // 08
		std::uint64_t               unk10;  // 10
	};
	static_assert(sizeof(BGSTypedKeywordValueArray<KeywordType::kNone>) == 0x18);
}
