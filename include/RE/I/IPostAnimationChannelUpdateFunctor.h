#pragma once

namespace RE
{
	class IPostAnimationChannelUpdateFunctor
	{
	public:
		SF_RTTI_VTABLE(IPostAnimationChannelUpdateFunctor);

		virtual ~IPostAnimationChannelUpdateFunctor();  // 00

		// add
		virtual void DoPostAnimationChannelUpdate() = 0;  // 01
	};
	static_assert(sizeof(IPostAnimationChannelUpdateFunctor) == 0x8);
}
