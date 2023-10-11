#pragma once

namespace RE
{
	class BGSPreloadable
	{
	public:
		SF_RTTI(BGSPreloadable);

		virtual ~BGSPreloadable();  // 00

		// add
		virtual void Unk_01();  // 01
	};
	static_assert(sizeof(BGSPreloadable) == 0x08);
}
