#pragma once

#include "RE/S/SettingCollection.h"

namespace RE
{
	namespace detail
	{
		/*
		struct SettingCollectionMapCompare
		{
			[[nodiscard]] bool operator()(const RE::BSFixedString& a_lhs, const RE::BSFixedString& a_rhs) const noexcept
			{
				return a_lhs.c_str() < a_rhs.c_str();
			}
		};
		*/
	}

	template <class T>
	class SettingCollectionMap :
		public SettingCollection<T>  // 000
	{
	public:
		virtual ~SettingCollectionMap();  // 000

		// members
		void* /* BSTBTree<BSFixedString, T*, detail::SettingCollectionMapCompare> */ settings;  // 118
	};

	extern template class SettingCollectionMap<Setting>;
}
