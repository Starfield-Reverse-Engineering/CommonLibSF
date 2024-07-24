#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/I/ILoader.h"
#include "RE/R/ReadableStringTable.h"

namespace RE
{
	namespace BSScript
	{
		class ErrorLogger;
		class IStore;  // stub
		class Object;

		namespace Internal
		{
			class ReadableStringTable;
		}

		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		class __declspec(novtable) CompiledScriptLoader :
			public ILoader  // 00
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__CompiledScriptLoader };
			static constexpr auto VTABLE{ VTABLE::BSScript__CompiledScriptLoader };

			// override (ILoader)
			ILoader* Clone() const override;                                                         // 01
			void     SetScriptStore(const BSTSmartPointer<IStore>& a_newStore) override;             // 02
			bool     GetClass(const char* a_name, UnlinkedTypes::Object& a_unlinkedClass) override;  // 03

			// members
			ErrorLogger*                  errorHandler;      // 08
			BSTSmartPointer<IStore>       scriptStore;       // 10
			Internal::ReadableStringTable stringTable;       // 18
			std::int8_t                   fileMajorVersion;  // 30
			std::int8_t                   fileMinorVersion;  // 31
			std::int8_t                   loadFlags;         // 32
		};
		static_assert(sizeof(CompiledScriptLoader) == 0x38);
	}
}
