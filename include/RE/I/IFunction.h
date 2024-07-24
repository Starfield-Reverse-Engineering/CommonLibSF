#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE::BSScript
{
	namespace Internal
	{
		class VirtualMachine;
	}

	class VMClassInfo;
	class VMClassRegistry;
	class VMState;
	class VMValue;

	class IFunction
	{
	public:
		IFunction() {}
		virtual ~IFunction() {}

		struct Unk13
		{
			std::uint64_t unk00;
			std::uint32_t unk08;
		};

		virtual BSFixedString* GetName(void) = 0;
		virtual BSFixedString* GetClassName(void) = 0;
		virtual BSFixedString* GetStateName(void) = 0;
		virtual std::uint64_t* GetReturnType(std::uint64_t* a_dst) = 0;
		virtual std::uint64_t  GetNumParams(void) = 0;
		virtual std::uint64_t* GetParam(std::uint32_t a_idx, BSFixedString* a_nameOut, std::uint64_t* a_typeOut) = 0;
		virtual std::uint64_t  GetNumParams2(void) = 0;
		virtual bool           IsNative(void) = 0;
		virtual bool           IsStatic(void) = 0;
		virtual bool           Unk_0A(void) = 0;
		virtual std::uint32_t  Unk_0B(void) = 0;
		virtual std::uint32_t  GetUserFlags(void) = 0;
		virtual BSFixedString* GetDocString(void) = 0;
		virtual void           Unk_0E(std::uint32_t a_unk) = 0;
		virtual std::uint32_t  Invoke(std::uint64_t a_unk0, std::uint64_t a_unk1, VMClassRegistry* a_registry, VMState* a_unk3) = 0;
		virtual BSFixedString* Unk_10(void) = 0;  // file/line number?
		virtual bool           TranslateIPToLineNumber(std::uint32_t a_instructionPointer, std::uint32_t* r_lineNumber) = 0;
		virtual std::uint64_t* Unk_12(std::uint64_t* a_out) = 0;                        // new, might be type reflection
		virtual Unk13          Unk_13(Unk13* a_out) = 0;                                // new, might be type reflection
		virtual bool           GetParamInfo(std::uint32_t a_idx, void* a_out) = 0;      // param list stuff
		virtual void*          Unk_15(std::uint64_t a_arg0, std::uint64_t a_arg1) = 0;  // param list stuff, loop
		virtual bool           GetUnk41(void) = 0;
		virtual void           SetUnk41(bool a_arg) = 0;

		// members
		BSIntrusiveRefCounted refCount;  // 08
	};
	static_assert(sizeof(IFunction) == 0x10);
}
