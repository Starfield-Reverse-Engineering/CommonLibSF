#pragma once

#include "RE/B/BSTSingleton.h"

namespace RE
{
	class MenuActor;

	class IDataModel
	{
	public:
		SF_RTTI_VTABLE(IDataModel);

		virtual ~IDataModel();

		virtual void Unk01();
		virtual void Unk02();
		virtual void Unk03();

		// members
		void* unk08;  // 08 - model object?
	};
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
