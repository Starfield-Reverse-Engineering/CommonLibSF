#include "RE/I/IFuncCallQuery.h"

namespace RE::BSScript
{
	class ErrorLogger;
	class Stack;       // stub
	class StackFrame;  // stub

	namespace Internal
	{
		class VirtualMachine;

		class CodeTasklet :
			public IFuncCallQuery  // 00
		{
		public:
			SF_RTTI_VTABLE(BSScript__Internal__CodeTasklet);

			enum class OpCode : std::uint32_t
			{
				kNOP,
				kIADD,
				kFADD,
				kISUB,
				kFSUB,
				kIMUL,
				kFMUL,
				kIDIV,
				kFDIV,
				kIMOD,
				kNOT,
				kINEG,
				kFNEG,
				kASSIGN,
				kCAST,
				kCMP_EQ,
				kCMP_LT,
				kCMP_LTE,
				kCMP_GT,
				kCMP_GTE,
				kJMP,
				kJMPT,
				kJMPF,
				kCALLMETHOD,
				kCALLPARENT,
				kCALLSTATIC,
				kRETURN,
				kSTRCAT,
				kPROPGET,
				kPROPSET,
				kARRAY_CREATE,
				kARRAY_LENGTH,
				kARRAY_GETELEMENT,
				kARRAY_SETELEMENT,
				kARRAY_FINDELEMENT,
				kARRAY_RFINDELEMENT,
				kIS,
				kSTRUCT_CREATE,
				kSTRUCT_GET,
				kSTRUCT_SET,
				kARRAY_FINDSTRUCT,
				kARRAY_RFINDSTRUCT,
				kARRAY_ADD,
				kARRAY_INSERT,
				kARRAY_REMOVELAST,
				kARRAY_REMOVE,
				kARRAY_CLEAR,
				// added in Fallout 76
				kARRAY_GETALLMATCHINGSTRUCTS,
				// New in Starfield
				kLOCK_GUARDS,
				kUNLOCK_GUARDS,
				kTRY_LOCK_GUARDS,
			};

			enum class ResumeReason : std::uint32_t
			{
				kNotResuming = 0,
				kNotResumingNoIncrement = 1,
				kInitialStart = 2,
				kFunctionReturn = 3,
				kRetryInstruction = 4,
				kFunctionCall = 5
			};

			virtual ~CodeTasklet();  // 00

			// override (IFuncCallQuery)
			virtual bool GetFunctionCallInfo(
				CallType&                           a_callType,
				BSTSmartPointer<ObjectTypeInfo>&    a_objectTypeInfo,
				BSFixedString&                      a_name,
				Variable&                           a_self,
				void* /* BSScrapArray<Variable>& */ a_args) const override;  // 01

			virtual BSTSmartPointer<Object> GetSelfAsObject() const override;  // 02

			// members
			Stack*          stack;                    // 10
			VirtualMachine* vm;                       // 18
			ErrorLogger*    errorLogger;              // 20
			ResumeReason    resumeReason;             // 28
			std::uint32_t   pad2C;                    // 2C
			const void*     instructionDataStart;     // 30
			StackFrame*     topFrame;                 // 38
			std::uint32_t   frameMemoryPage;          // 40
			std::uint32_t   instructionDataBitCount;  // 44
			std::int8_t     jumpBitCount;             // 48
			std::int8_t     localVarBitCount;         // 49
			std::int8_t     memberVarBitCount;        // 4A
			std::int8_t     unk4B;                    // 4B
			std::uint32_t   pad4C;                    // 4C
		};
		static_assert(sizeof(CodeTasklet) == 0x50);
	}
}
