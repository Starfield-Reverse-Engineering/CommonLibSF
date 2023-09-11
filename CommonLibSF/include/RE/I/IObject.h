#pragma once

namespace RE
{
	namespace BSReflection
	{
		class IObject
		{
		public:
			TES_RTTI_VTABLE(BSReflection__IObject);

			virtual void Unk_00();  // 00
			virtual ~IObject();     // 01
		};
	}
}
