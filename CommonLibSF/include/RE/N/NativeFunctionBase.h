#pragma once

#include "RE/I/IFunction.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class VirtualMachine;
		}

		class StackFrame;
		class Variable;

		namespace NF_util
		{
			class NativeFunctionBase : public IFunction
			{
			public:
				SF_RTTI_VTABLE(BSScript__NF_util__NativeFunctionBase);

				NativeFunctionBase() {}
				virtual ~NativeFunctionBase() {}

				struct alignas(0x10) ParameterInfo
				{
				public:
					struct Entry
					{
					public:
						// members
						BSFixedString name;  // 00

						union
						{
							std::uint64_t type;     // 08 - shared with VMValue::type
							VMClassInfo*  typePtr;  // 08
						};
					};

					// members
					Entry*        data;       // 00 length = numParams + unk0A
					std::uint16_t numParams;  // 08
					std::uint16_t unk0A;      // 0A
				};
				static_assert(sizeof(ParameterInfo) == 0x10);

				virtual BSFixedString* GetName(void) override { return &_name; }
				virtual BSFixedString* GetClassName(void) override { return &_className; }
				virtual BSFixedString* GetStateName(void) override { return &_stateName; }
				virtual std::uint64_t* GetReturnType(std::uint64_t* a_dst) override
				{
					*a_dst = _retType;
					return a_dst;
				}
				virtual std::uint64_t  GetNumParams(void) override { return _params.numParams; }
				virtual std::uint64_t* GetParam(std::uint32_t a_idx, BSFixedString* a_nameOut, std::uint64_t* a_typeOut)
				{
					using func_t = std::add_pointer_t<std::uint64_t*(ParameterInfo*, std::uint32_t, BSFixedString*, std::uint64_t*)>;
					REL::Relocation<func_t> func{ REL::ID(196404) };
					return func(&_params, a_idx, a_nameOut, a_typeOut);
				}
				virtual std::uint64_t  GetNumParams2(void) override { return _params.unk0A; }
				virtual bool           IsNative(void) override { return true; }
				virtual bool           IsStatic(void) override { return _isStatic; }
				virtual bool           Unk_0A(void) override { return false; }
				virtual std::uint32_t  Unk_0B(void) override { return 0; }
				virtual std::uint32_t  GetUserFlags(void) override { return _userFlags; }
				virtual BSFixedString* GetDocString(void) override { return &_docString; }
				virtual void           Unk_0E(std::uint32_t a_unk) override { (void)a_unk; }  // always nop?
				virtual std::uint32_t  Invoke(std::uint64_t a_unk0, std::uint64_t a_unk1, VMClassRegistry* a_registry, VMState* a_unk3) override
				{
					using func_t = decltype(&NativeFunctionBase::Invoke);
					REL::Relocation<func_t> func{ REL::ID(196401) };
					return func(this, a_unk0, a_unk1, a_registry, a_unk3);
				}
				virtual BSFixedString* Unk_10(void) override
				{
					using func_t = decltype(&NativeFunctionBase::Unk_10);
					REL::Relocation<func_t> func{ REL::ID(196407) };
					return func(this);
				}
				virtual bool Unk_11(std::uint32_t a_unk0, std::uint32_t* a_unk1) override
				{
					(void)a_unk0;
					*a_unk1 = 0;
					return false;
				}
				virtual std::uint64_t* Unk_12(std::uint64_t* a_out) override
				{
					*a_out = 0;
					// a_out[4] = 0; // as std::uint8_t?

					return a_out;
				}
				virtual Unk13 Unk_13(Unk13* a_out) override
				{
					a_out->unk00 = 0;
					a_out->unk08 = 0;
					// a_out[8] = 0; // as std::uint8_t?
				}
				virtual bool GetParamInfo(std::uint32_t a_idx, void* a_out) override
				{
					using func_t = decltype(&NativeFunctionBase::GetParamInfo);
					REL::Relocation<func_t> func{ REL::ID(196409) };
					return func(this, a_idx, a_out);
				}
				virtual void* Unk_15(std::uint64_t a_arg0, std::uint64_t a_arg1)
				{
					using func_t = decltype(&NativeFunctionBase::Unk_15);
					REL::Relocation<func_t> func{ REL::ID(196408) };
					return func(this, a_arg0, a_arg1);
				}
				virtual bool GetUnk41(void) override { return _isCallableFromTasklet; }
				virtual void SetUnk41(bool a_arg) override { _isCallableFromTasklet = a_arg; }
				virtual bool HasCallback() = 0;
				virtual void Run() = 0;

			protected:
				BSFixedString _name;                     // 10
				BSFixedString _className;                // 18
				BSFixedString _stateName{ "" };          // 20
				std::uint64_t _retType;                  // 28 TypeInfo
				ParameterInfo _params;                   // 30
				bool          _isStatic;                 // 40
				bool          _isCallableFromTasklet{};  // 41
				bool          _isLatent{};               // 42
				std::uint8_t  _pad43;                    // 43
				std::uint32_t _userFlags{};              // 44
				BSFixedString _docString;                // 48
			};
			static_assert(sizeof(NativeFunctionBase) == 0x50);
		}
	}
}
