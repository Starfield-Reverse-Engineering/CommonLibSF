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
			REL::Relocation<BSInputEnableManager**> singleton{ REL::ID(878792) };
			return *singleton;
		}

		bool CreateLayer(InputEnableLayer* a_layer, const char* a_layerName)
		{
			using func_t = decltype(&BSInputEnableManager::CreateLayer);
			REL::Relocation<func_t> func(REL::ID(179101));
			return func(this, a_layer, a_layerName); 
		}
	};
}
