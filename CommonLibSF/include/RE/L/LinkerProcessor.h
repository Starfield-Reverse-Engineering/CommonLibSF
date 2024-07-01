#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IObjectProcessor.h"

namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;

		namespace Internal
		{
			class VirtualMachine;
		}

		class __declspec(novtable) LinkerProcessor :
			public IObjectProcessor
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__LinkerProcessor };
			static constexpr auto VTABLE{ VTABLE::BSScript__LinkerProcessor };

			virtual ~LinkerProcessor();  // 00

			// override (IObjectProcessor)
			virtual IObjectProcessor* Clone() override;                                    // 01
			virtual void              SetLoader(ILoader* a_loader) override;               // 02 - { loader = a_loader; }
			virtual bool              Process(const BSFixedString& a_className) override;  // 03

			// members
			Internal::VirtualMachine*                                             virtualMachine;      // 08
			ErrorLogger*                                                          errorLogger;         // 10
			ILoader*                                                              loader;              // 18
			std::uint64_t                                                         unk20;               // 20
			char*                                                                 unk28;               // 28
			BSScrapArray<BSFixedString>                                           loadedParents;       // 30
			BSScrapArray<BSFixedString>                                           objectsToTypecheck;  // 48
			BSScrapArray<BSFixedString>                                           processQueue;        // 60
			/*BSTHashMap<BSFixedString, BSTSmartPointer<ObjectTypeInfo>>**/ void* objectTypeInfoMap;   // 78
			/*BSTHashMap<BSFixedString, BSTSmartPointer<StructTypeInfo>>**/ void* structTypeInfoMap;   // 80
		};
		static_assert(sizeof(LinkerProcessor) == 0x88);
	}
}
