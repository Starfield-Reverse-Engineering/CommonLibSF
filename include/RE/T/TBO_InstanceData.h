#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class BGSBlockBashData;
	class BGSKeywordForm;

	class TBO_InstanceData :
		public BSIntrusiveRefCounted  // 08
	{
	public:
		SF_RTTI_VTABLE(TBO_InstanceData);

		virtual ~TBO_InstanceData();  // 00

		// add
		virtual BGSKeywordForm*   GetKeywordData() const;          // 01
		virtual void              DeleteKeywordData();             // 02
		virtual void              CreateKeywordData();             // 03
		virtual BGSBlockBashData* GetBlockBashData();              // 04
		virtual void              DeleteBlockBashData();           // 05
		virtual void              CreateBlockBashData();           // 06
		virtual float             GetWeight();                     // 07
		virtual std::int32_t      GetValue() const;                // 08
		virtual std::uint32_t     GetHealth() const;               // 09
		virtual float             GetColorRemappingIndex() const;  // 0A
		virtual void              Unk_0B();                        // 0B
		virtual void              Unk_0C();                        // 0C
		virtual void              Unk_0D();                        // 0D
		virtual void              Unk_0E();                        // 0E
		virtual void              Unk_0F();                        // 0F
		virtual void              Unk_10();                        // 10

		// members
		std::uint64_t unk10;  // 10
	};
	static_assert(sizeof(TBO_InstanceData) == 0x18);
}
