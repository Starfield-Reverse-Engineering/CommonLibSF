#pragma once

#include "RE/T/TESBoundObject.h"

namespace RE
{
	class BGSMaterialPathForm;

	class BGSProjectedDecal : public TESBoundObject
	{
	public:
		SF_RTTI_VTABLE(BGSProjectedDecal);
		SF_FORMTYPE(PDCL);

		struct Data
		{
		public:
			// members
			float unk00;  // 00
			float unk04;  // 04
			float unk08;  // 08
			float unk0C;  // 0C
			float unk10;  // 10
			float unk14;  // 14
		};
		static_assert(sizeof(Data) == 0x18);

		~BGSProjectedDecal() override;  // 00

		// members
		BGSMaterialPathForm* material;  // E8
		Data                 data;      // F0
	};
	static_assert(sizeof(BGSProjectedDecal) == 0x108);
}
