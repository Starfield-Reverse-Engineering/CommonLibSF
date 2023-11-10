#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	namespace BSScript
	{
		namespace Internal
		{
			class ReadableTypeTable
			{
			public:
				struct SaveTypeInfo :
					public BSIntrusiveRefCounted  // 00
				{
				public:
					// members
					BSFixedString               parentType;        // 08
					BSScrapArray<std::uint32_t> variableIndicies;  // 10
				};
				static_assert(sizeof(SaveTypeInfo) == 0x28);

				// members
				/*BSTScrapHashMap<BSFixedString, BSTSmartPointer<SaveTypeInfo>>* */ void* saveTypeInfo;  // 00
			};
			static_assert(sizeof(ReadableTypeTable) == 0x08);
		}
	}
}
