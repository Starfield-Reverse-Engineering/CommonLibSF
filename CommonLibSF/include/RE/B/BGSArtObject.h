#pragma once

#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSModelMaterialSwap.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class TESEffectShader;

	class BGSArtObject :
		public TESBoundObject,       // 000
		public BGSKeywordForm,       // 0E0
		public BGSModelMaterialSwap  // 110
	{
	public:
		SF_RTTI_VTABLE(BGSArtObject);
		SF_FORMTYPE(ARTO);

		enum class ArtType
		{
			kMagicCastingArt = 0,
			kMagicHitEffect = 1,
			kMagicEnchantEffect = 2
		};

		struct Data  // DNAM
		{
		public:
			// members
			stl::enumeration<ArtType, std::uint32_t> artType;  // 0
			std::uint32_t                            unk04;    // 4
		};
		static_assert(sizeof(Data) == 0x8);

		~BGSArtObject() override;  // 00

		// members
		Data             data;          // 138
		TESEffectShader* effectShader;  // 140
	};
	static_assert(sizeof(BGSArtObject) == 0x148);
}
