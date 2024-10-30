#pragma once

namespace RE
{
	class NiRefObject
	{
	public:
		SF_RTTI_VTABLE(NiRefObject);

		virtual ~NiRefObject();

		// members
		std::uint32_t refCount;  // 08
	};
}
