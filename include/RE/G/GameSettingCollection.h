#pragma once

#include "RE/S/SettingCollectionMap.h"

namespace RE
{
	class GameSettingCollection :
		public SettingCollectionMap<Setting>  // 000
	{
	public:
		SF_RTTI_VTABLE(GameSettingCollection);

		virtual ~GameSettingCollection();  // 000

		[[nodiscard]] static GameSettingCollection* GetSingleton()
		{
			REL::Relocation<GameSettingCollection**> singleton{ REL::ID(879099) };
			return *singleton;
		}
	};
}
