#pragma once

#include "RE/B/BSTTuple.h"
#include "RE/I/IFunction.h"
#include "RE/T/TypeInfo.h"

namespace RE::BSScript
{
	namespace Internal
	{
		class VirtualMachine;

		class VDescTable
		{
		public:
			using value_type = BSTTuple<BSFixedString, TypeInfo>;
			using size_type = std::uint16_t;

			VDescTable(size_type a_params, size_type a_locals) :
				paramCount(a_params),
				totalEntries(a_params + a_locals)
			{
				const auto total = paramCount + totalEntries;
				if (total > 0) {
					entries = new value_type[total];
				}
			}

			~VDescTable() { delete[] entries; }

			// members
			value_type* entries{ nullptr };  // 00
			size_type   paramCount{ 0 };     // 08
			size_type   totalEntries{ 0 };   // 0A
		};
		static_assert(sizeof(VDescTable) == 0x10);
	}

	class StackFrame;
	class Variable;

	namespace NF_util
	{
		class NativeFunctionBase : public IFunction
		{
		public:
			SF_RTTI_VTABLE(BSScript__NF_util__NativeFunctionBase);

			NativeFunctionBase(
				std::string_view a_object,
				std::string_view a_function,
				std::uint16_t    a_paramCount,
				bool             a_isStatic,
				bool             a_isLatent) :
				_name(a_function),
				_className(a_object),
				_params(a_paramCount, 0),
				_isStatic(a_isStatic),
				_isLatent(a_isLatent)
			{
				for (std::size_t i = 0; i < _params.paramCount; ++i) {
					_params.entries[i].first = std::format("param{}", i + 1);
				}
			}
			virtual ~NativeFunctionBase() {}

			virtual BSFixedString& GetName() override { return _name; }
			virtual BSFixedString& GetObjectTypeName() override { return _className; }
			virtual BSFixedString& GetStateName() override { return _stateName; }

			virtual TypeInfo* GetReturnType(TypeInfo* a_dst) override
			{
				*a_dst = _retType;
				return a_dst;
			}

			virtual std::uint64_t GetParamCount() override { return _params.paramCount; }

			virtual TypeInfo* GetParam(std::uint32_t a_idx, BSFixedString* a_nameOut, TypeInfo* a_typeOut) override
			{
				using func_t = std::add_pointer_t<TypeInfo*(Internal::VDescTable*, std::uint32_t, BSFixedString*, TypeInfo*)>;
				static REL::Relocation<func_t> func{ ID::BSScript::Internal::NF_util::NativeFunctionBase::GetParam };
				return func(&_params, a_idx, a_nameOut, a_typeOut);
			}

			virtual std::uint64_t  GetStackFrameSize() override { return _params.totalEntries; }
			virtual bool           GetIsNative() override { return true; }
			virtual bool           GetIsStatic() override { return _isStatic; }
			virtual bool           GetIsEmpty() override { return false; }
			virtual FunctionType   GetFunctionType() override { return FunctionType::kNormal; }
			virtual std::uint32_t  GetUserFlags() override { return _userFlags; }
			virtual BSFixedString& GetDocString() override { return _docString; }
			virtual void           InsertLocals(std::uint32_t a_frame) override { (void)a_frame; }

			virtual CallResult Call(const BSTSmartPointer<Stack>& a_stack, ErrorLogger& a_errorLogger, Internal::VirtualMachine& a_vm, StackFrame* a_frame) override
			{
				using func_t = decltype(&NativeFunctionBase::Call);
				static REL::Relocation<func_t> func{ ID::BSScript::Internal::NF_util::NativeFunctionBase::Invoke };
				return func(this, a_stack, a_errorLogger, a_vm, a_frame);
			}

			virtual BSFixedString& GetSourceFilename() override
			{
				using func_t = decltype(&NativeFunctionBase::GetSourceFilename);
				static REL::Relocation<func_t> func{ ID::BSScript::Internal::NF_util::NativeFunctionBase::Unk_10 };
				return func(this);
			}

			virtual bool TranslateIPToLineNumber(std::uint32_t a_IP, std::uint32_t* r_lineNumber) override
			{
				(void)a_IP;
				*r_lineNumber = 0;
				return false;
			}

			virtual std::uint64_t* Unk_12(std::uint64_t* a_out) override
			{
				*a_out = 0;
				// a_out[4] = 0; // as std::uint8_t?
				return a_out;
			}

			virtual Unk13* Unk_13(Unk13* a_out) override
			{
				a_out->unk00 = 0;
				a_out->unk08 = 0;
				// a_out[8] = 0; // as std::uint8_t?
				return a_out;
			}

			virtual bool GetVarNameForStackIndex(std::uint32_t a_idx, BSFixedString& a_variableName) override
			{
				using func_t = decltype(&NativeFunctionBase::GetVarNameForStackIndex);
				static REL::Relocation<func_t> func{ ID::BSScript::Internal::NF_util::NativeFunctionBase::GetParamInfo };
				return func(this, a_idx, a_variableName);
			}

			virtual void* Unk_15(std::uint64_t a_arg0, std::uint64_t a_arg1) override
			{
				using func_t = decltype(&NativeFunctionBase::Unk_15);
				static REL::Relocation<func_t> func{ ID::BSScript::Internal::NF_util::NativeFunctionBase::Unk_15 };
				return func(this, a_arg0, a_arg1);
			}

			virtual bool CanBeCalledFromTasklets() override { return _isCallableFromTasklet; }
			virtual void SetCallableFromTasklets(bool a_taskletCallable) override { _isCallableFromTasklet = a_taskletCallable; }

			// add
			virtual bool HasStub() const = 0;
			virtual bool MarshallAndDispatch(Variable& a_self, Internal::VirtualMachine& a_vm, std::uint32_t a_stackID, Variable& a_resultValue, const StackFrame& a_stackFrame) const = 0;

		protected:
			BSFixedString        _name;                     // 10
			BSFixedString        _className;                // 18
			BSFixedString        _stateName{ "" };          // 20
			TypeInfo             _retType;                  // 28
			Internal::VDescTable _params;                   // 30
			bool                 _isStatic;                 // 40
			bool                 _isCallableFromTasklet{};  // 41
			bool                 _isLatent{};               // 42
			std::uint32_t        _userFlags{};              // 44
			BSFixedString        _docString;                // 48
		};
		static_assert(sizeof(NativeFunctionBase) == 0x50);
	}
}
