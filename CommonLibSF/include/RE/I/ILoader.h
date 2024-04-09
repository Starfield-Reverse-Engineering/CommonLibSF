#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		class IStore;  // stub
		class Object;

		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		struct __declspec(novtable) ILoader
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__ILoader };
			static constexpr auto VTABLE{ VTABLE::BSScript__ILoader };

			virtual ~ILoader() = default;  // 00

			// add
			virtual ILoader* Clone() const = 0;                                                         // 01
			virtual void     SetScriptStore(const BSTSmartPointer<IStore>& a_newStore) = 0;             // 02
			virtual bool     GetClass(const char* a_name, UnlinkedTypes::Object& a_unlinkedClass) = 0;  // 03
		};
		static_assert(sizeof(ILoader) == 0x8);
	}
}
