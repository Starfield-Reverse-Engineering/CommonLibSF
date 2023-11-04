#pragma once

namespace RE
{
	class BGSConditionForm;
	class BGSWwiseEventForm;

	class BGSSoundReference
	{
	public:
		// members
		std::uint64_t      unk00;       // 00 - WWise GUID 1
		std::uint64_t      unk08;       // 08
		std::uint64_t      unk10;       // 10 - WWise GUID 2
		std::uint64_t      unk18;       // 18
		BGSConditionForm*  conditions;  // 20
		BGSWwiseEventForm* eventData;   // 28
	};
	static_assert(sizeof(BGSSoundReference) == 0x30);
}
