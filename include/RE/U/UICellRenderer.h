#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class TESObjectCELL;

	class UICellRenderer :
		public BSIntrusiveRefCounted
	{
	public:
		SF_RTTI_VTABLE(UICellRenderer);

		virtual ~UICellRenderer();  // 00

		// members
		TESObjectCELL* unk10;     // 10
		void*          unk18;     // 18 - const BSResource2::TEntryType<0,LoadedCellDB::DBTraits, BSResource2::DBDefaultStreamPolicy>
		float          unk20;     // 20
		float          unk24;     // 24
		std::uint64_t  unk28;     // 28
		void*          unk30[4];  // 30 - const BSResource2::TEntryType<0,TextureDB::DBTraits, BSResource2::DBDefaultStreamPolicy>
		std::uint64_t  unk50;     // 50
		std::uint8_t   unk58[8];  // 58
		std::uint64_t  unk60;     // 60
		std::uint64_t  unk68;     // 68 - BSMenu3D::Scene
	};
}
