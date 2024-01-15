#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSMaterialType;

	struct TEXTURE_HAVOK_DATA  // HNAM
	{
	public:
		// members
		std::int8_t friction;     // 0
		std::int8_t restitution;  // 1
	};
	static_assert(sizeof(TEXTURE_HAVOK_DATA) == 0x2);

	class TESLandTexture : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESLandTexture);
		SF_FORMTYPE(LTEX);

		~TESLandTexture() override;  // 00

		// members
		BGSEditorID        formEditorID;  // 30
		BSFixedString      materialPath;  // 38
		TEXTURE_HAVOK_DATA havokData;     // 48
		BGSMaterialType*   materialType;  // 50
		float              unk58;         // 58
		std::int32_t       unk5C;         // 5C
	};
	static_assert(sizeof(TESLandTexture) == 0x60);
}
