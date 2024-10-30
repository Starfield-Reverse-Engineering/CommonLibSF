#pragma once

namespace RE
{
	class InputEnableLayer;

	class BSInputEnableManager
	{
	public:
		virtual ~BSInputEnableManager() = 0;

		static BSInputEnableManager* GetSingleton()
		{
			static REL::Relocation<BSInputEnableManager**> singleton{ ID::BSInputEnableManager::Singleton };
			return *singleton;
		}

		bool CreateLayer(InputEnableLayer* a_layer, const char* a_layerName)
		{
			using func_t = decltype(&BSInputEnableManager::CreateLayer);
			static REL::Relocation<func_t> func{ ID::BSInputEnableManager::CreateLayer };
			return func(this, a_layer, a_layerName);
		}
	};
}
