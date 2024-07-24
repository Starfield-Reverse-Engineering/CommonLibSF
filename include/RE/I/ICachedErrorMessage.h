#pragma once

#include "RE/B/BSFixedString.h"

namespace RE::BSScript
{
	class __declspec(novtable) ICachedErrorMessage
	{
	public:
		SF_RTTI_VTABLE(BSScript__ICachedErrorMessage);

		virtual ~ICachedErrorMessage() = default;  // 00

		// add
		virtual void GetErrorMsg(BSFixedString& a_message) const = 0;  // 01
	};
	static_assert(sizeof(ICachedErrorMessage) == 0x8);
}
