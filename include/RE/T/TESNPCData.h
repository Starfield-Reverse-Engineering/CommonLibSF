#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/I/IDataModel.h"

namespace RE
{
	class MenuActor;
}

namespace RE::TESNPCData
{
	class ChargenDataModel :
		public IDataModel,
		public BSTSingletonSDM<ChargenDataModel>
	{
	public:
		SF_RTTI_VTABLE(TESNPCData__ChargenDataModel);

		virtual ~ChargenDataModel() override;

		[[nodiscard]] static ChargenDataModel* GetSingleton()
		{
			static REL::Relocation<ChargenDataModel**> singleton{ ID::TESNPCData::ChargenDataModel::Singleton };
			return *singleton;
		}

		void Update(MenuActor* a_menuActor)
		{
			using func_t = decltype(&ChargenDataModel::Update);
			static REL::Relocation<func_t> func{ ID::TESNPCData::ChargenDataModel::Update };
			return func(this, a_menuActor);
		}
	};
}
