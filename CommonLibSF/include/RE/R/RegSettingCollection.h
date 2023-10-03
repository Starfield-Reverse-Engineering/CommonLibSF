#pragma once

#include "RE/S/SettingCollectionList.h"

namespace RE
{
	class RegSettingCollection :
		public SettingCollectionList<Setting>  // 000
	{
	public:
		SF_RTTI_VTABLE(RegSettingCollection);

		virtual ~RegSettingCollection();  // 000
	};
}
