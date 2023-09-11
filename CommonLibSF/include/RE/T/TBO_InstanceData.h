#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class TBO_InstanceData :
		public BSIntrusiveRefCounted  // 08
	{
	public:
		TES_RTTI_VTABLE(TBO_InstanceData);

		virtual ~TBO_InstanceData() = default;  // 00
	};
}
