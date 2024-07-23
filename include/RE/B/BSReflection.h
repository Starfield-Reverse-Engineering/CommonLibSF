#pragma once

namespace RE::BSReflection
{
	class IObject
	{
	public:
		SF_RTTI_VTABLE(BSReflection__IObject);

		virtual void Unk_00();  // 00
		virtual ~IObject();     // 01
	};

	struct TypedData;

	class IType
	{
	public:
		SF_RTTI(BSReflection__IType);

		// add
		virtual TypedData*  GetZeroed(TypedData* a_dst, void* a_buf) = 0;
		virtual TypedData*  Copy(TypedData* a_dst, void* a_buf, TypedData* a_src) = 0;
		virtual TypedData*  Copy2(TypedData* a_dst, void* a_buf, TypedData* a_src) = 0;
		virtual void        Unk03() = 0;
		virtual const char* GetName() = 0;
	};
	static_assert(sizeof(IType) == 0x08);

	class BasicType : public IType
	{
	public:
		SF_RTTI_VTABLE(BSReflection__BasicType);

		// members
		std::uint32_t size;      // 08
		std::uint16_t size2;     // 0C - repeat of size field?
		std::uint8_t  unk0E;     // 0E - 00
		std::uint8_t  unk0F;     // 0F - FF
		const char*   name;      // 10
		std::uint8_t  id;        // 18
		std::uint8_t  isSigned;  // 19
		std::uint16_t unk1A;     // 1A
		std::uint32_t unk1C;     // 1C
	};
	static_assert(sizeof(BasicType) == 0x20);

	struct TypedData
	{
	public:
		// members
		IType* type;  // 00
		void*  data;  // 08
	};
	static_assert(sizeof(TypedData) == 0x10);
}
