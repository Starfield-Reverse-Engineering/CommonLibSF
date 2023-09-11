#pragma once

#include "RE/S/SettingCollectionList.h"

namespace RE
{
	class RegSettingCollection : public SettingCollectionList<Setting>
	{
	public:
		SF_RTTI_VTABLE(RegSettingCollection);

		virtual ~RegSettingCollection();
	};
	static_assert(sizeof(RegSettingCollection) == 0x160);
}
