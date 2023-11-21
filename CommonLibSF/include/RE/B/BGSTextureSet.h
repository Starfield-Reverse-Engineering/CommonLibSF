#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESTexture.h"

namespace RE
{
	class DecalData;

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
		public TESBoundObject,             // 000
		public TextureUtils::TextureIdSet  // 118
	{
	public:
		SF_RTTI_VTABLE(BGSTextureSet);
		SF_FORMTYPE(TXST);

		~BGSTextureSet() override;  // 00

		// members
		BSFixedString materialName;  // 290
		TESTexture    textures[19];  // 298
		DecalData*    decalData;     // 3C8
		std::uint16_t flags;         // 3D0
	};
	static_assert(sizeof(BGSTextureSet) == 0x3D8);
}
