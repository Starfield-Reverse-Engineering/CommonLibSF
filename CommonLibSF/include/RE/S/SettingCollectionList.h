#pragma once

#include "RE/S/SettingCollection.h"

namespace RE
{
	template <typename T>
	class SettingCollectionList : public SettingCollection<T>
	{
	public:
		virtual ~SettingCollectionList();

		// members
		BSSimpleList<T*> settings;  // 118
	};
	extern template class SettingCollectionList<Setting>;
}
