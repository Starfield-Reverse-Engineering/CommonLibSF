#pragma once

#include "RE/B/BGSKeyword.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/T/TBO_InstanceData.h"

namespace RE
{
	class IKeywordFormBase
	{
	public:
		SF_RTTI(IKeywordFormBase);

		virtual ~IKeywordFormBase();

		// add
		virtual bool HasKeyword(const BGSKeyword* a_keyword, const TBO_InstanceData* a_data);
		virtual void CollectAllKeywords(void* /* BSScrapArray<const BGSKeyword> */ a_refOutKeywordA, const TBO_InstanceData* a_data);
	};
}
