#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	struct DecalData;

	namespace TextureUtils
	{
		struct TextureId
		{
		public:
			// members
			std::uint32_t unk0;  // 0
			std::uint32_t unk4;  // 4
			std::uint32_t unk8;  // 8
		};
		static_assert(sizeof(TextureId) == 0xC);

		struct TextureIdSet
		{
		public:
			// members
			TextureId textureIDs[31];  // 00
		};
		static_assert(sizeof(TextureIdSet) == 0x174);
	}

	class BGSTextureSet :
		public TESBoundObject,             // 00
		public TextureUtils::TextureIdSet  // E0
	{
	public:
		SF_RTTI_VTABLE(BGSTextureSet);
		SF_FORMTYPE(TXST);

		~BGSTextureSet() override;  // 00

		// members
		BSFixedString materialName;  // 258
		TESTexture    textures[19];  // 260
		DecalData*    decalData;     // 390
		std::uint16_t flags;         // 398
	};
	static_assert(sizeof(BGSTextureSet) == 0x3A8);
}
