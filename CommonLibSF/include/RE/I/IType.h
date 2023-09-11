#pragma once

namespace RE
{
	namespace BSReflection
	{
		struct TypedData;

		class IType
		{
		public:
			TES_RTTI(BSReflection__IType);

			// add
			virtual TypedData*  GetZeroed(TypedData* a_dst, void* a_buf) = 0;
			virtual TypedData*  Copy(TypedData* a_dst, void* a_buf, TypedData* a_src) = 0;
			virtual TypedData*  Copy2(TypedData* a_dst, void* a_buf, TypedData* a_src) = 0;
			virtual void        Unk03() = 0;
			virtual const char* GetName() = 0;
		};
		static_assert(sizeof(IType) == 0x08);
	}
}
