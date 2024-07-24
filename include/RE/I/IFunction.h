#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/E/ErrorLogger.h"
#include "RE/S/StackFrame.h"
#include "RE/T/TypeInfo.h"

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

	class IFunction :
		public BSIntrusiveRefCounted
	{
	public:
		IFunction() {}
		virtual ~IFunction() {}

		enum class CallResult : std::uint32_t
		{
			kCompleted,
			kSetupForVM,
			kInProgress,
			kFailedRetry,
			kFailedAbort
		};

		enum class FunctionType : std::uint32_t
		{
			kNormal,
			kPropertyGetter,
			kPropertySetter
		};

		struct Unk13
		{
			std::uint64_t unk00;
			std::uint32_t unk08;
		};

		virtual BSFixedString& GetName() = 0;
		virtual BSFixedString& GetObjectTypeName() = 0;
		virtual BSFixedString& GetStateName() = 0;
		virtual TypeInfo*      GetReturnType(TypeInfo* a_dst) = 0;
		virtual std::uint64_t  GetParamCount() = 0;
		virtual TypeInfo*      GetParam(std::uint32_t a_idx, BSFixedString* a_nameOut, TypeInfo* a_typeOut) = 0;
		virtual std::uint64_t  GetStackFrameSize() = 0;
		virtual bool           GetIsNative() = 0;
		virtual bool           GetIsStatic() = 0;
		virtual bool           GetIsEmpty() = 0;
		virtual FunctionType   GetFunctionType() = 0;
		virtual std::uint32_t  GetUserFlags() = 0;
		virtual BSFixedString& GetDocString() = 0;
		virtual void           InsertLocals(std::uint32_t a_frame) = 0;
		virtual CallResult     Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger& a_errorLogger, Internal::VirtualMachine& a_vm, StackFrame* a_frame) = 0;
		virtual BSFixedString& GetSourceFilename() = 0;
		virtual bool           TranslateIPToLineNumber(std::uint32_t a_instructionPointer, std::uint32_t* r_lineNumber) = 0;
		virtual std::uint64_t* Unk_12(std::uint64_t* a_out) = 0;  // new, might be type reflection
		virtual Unk13*         Unk_13(Unk13* a_out) = 0;          // new, might be type reflection
		virtual bool           GetVarNameForStackIndex(std::uint32_t a_idx, BSFixedString& a_variableName) = 0;
		virtual void*          Unk_15(std::uint64_t a_arg0, std::uint64_t a_arg1) = 0;  // param list stuff, loop
		virtual bool           CanBeCalledFromTasklets() = 0;
		virtual void           SetCallableFromTasklets(bool a_taskletCallable) = 0;
	};
	static_assert(sizeof(IFunction) == 0x10);
}
