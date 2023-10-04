#pragma once

namespace RE
{
	class BGSKeyword;
	class TBO_InstanceData;

	class IKeywordFormBase
	{
	public:
		SF_RTTI(IKeywordFormBase);

		virtual ~IKeywordFormBase();  // 00

		// add
		virtual bool HasKeyword(const BGSKeyword* a_keyword, const TBO_InstanceData* a_data);
		virtual void CollectAllKeywords(void* /* BSScrapArray<const BGSKeyword> */ a_refOutKeywordA, const TBO_InstanceData* a_data);
	};
}
