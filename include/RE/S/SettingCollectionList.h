#pragma once

#include "RE/B/BSTList.h"
#include "RE/S/SettingCollection.h"

namespace RE
{
	template <class T>
	class SettingCollectionList :
		public SettingCollection<T>  // 000
	{
	public:
		virtual ~SettingCollectionList();  // 000

		// members
		BSSimpleList<T*> settings;  // 118
		std::uint64_t    unk128;    // 128
		std::uint64_t    unk130;    // 130
	};
	static_assert(sizeof(SettingCollectionList<Setting>) == 0x138);

	extern template class SettingCollectionList<Setting>;
}
