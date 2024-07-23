#pragma once

#include "RE/B/BSInputEnableManager.h"

namespace RE
{
	struct BSInputEnableLayer
	{
		enum UserFlag
		{
			Walking = (1 << 0),
			Looking = (1 << 1),
			Activation = (1 << 2),    //Unconfirmed
			TabMenuMaybe = (1 << 3),  //Unconfirmed
			Console = (1 << 4),       //Unconfirmed
			POVSwitch = (1 << 5),     //Unconfirmed
			Fighting = (1 << 6),
			Sneaking = (1 << 7),
			Menu = (1 << 8),
			WheelZoom = (1 << 9),  //Unconfirmed
			Jumping = (1 << 10),
			Movement = Walking | Jumping,
		};

		enum OtherFlag
		{
			Journal = (1 << 0),
			Activate = (1 << 1),
			FastTravel = (1 << 2),
			CamSwitch = (1 << 3),
			VATS = (1 << 4),
			Favorites = (1 << 5),
			PipboyLight = (1 << 6),  //Unconfirmed
			ZKey = (1 << 7),
			Running = (1 << 8),
			Unk = (1 << 9),  //??
			Sprinting = (1 << 10),
			HandScanner = (1 << 11),
			Takeoff = (1 << 12),
			Inventory = (1 << 13),
			Gravjump = (1 << 14),
			FarTravel = (1 << 15),
			LocationDiscovery = (1 << 16),
			Others = HandScanner | Takeoff | Inventory | Gravjump | FarTravel,
		};

		uint32_t index;
		uint32_t state;
		uint64_t unk08;
		uint64_t unk10;
		uint64_t unk18;

		uint64_t SetUserFlags(uint64_t flags, bool enabled)
		{
			using func_t = decltype(&BSInputEnableLayer::SetUserFlags);
			REL::Relocation<func_t> func(REL::ID(106486));
			return func(this, flags, enabled);
		}

		uint64_t SetOtherFlags(uint64_t flags, bool enabled)
		{
			using func_t = decltype(&BSInputEnableLayer::SetOtherFlags);
			REL::Relocation<func_t> func(REL::ID(109447));
			return func(this, flags, enabled);
		}
	};

	class InputEnableLayer
	{
	public:
		InputEnableLayer() {}

		InputEnableLayer(const char* layerName)
		{
			Create(layerName);
		}

		~InputEnableLayer()
		{
			Free();
		}

		bool Create(const char* layerName)
		{
			bool result = true;
			if (!data) {
				result = BSInputEnableManager::GetSingleton()->CreateLayer(this, layerName);
				if (!result)
					data = nullptr;
			}
			return result;
		}

		bool Free()
		{
			bool result = true;
			if (data) {
				using func_t = decltype(&InputEnableLayer::Free);
				REL::Relocation<func_t> func(REL::ID(36626));
				result = func(this);
				data = nullptr;
			}
			return result;
		}

		void SetUserFlags(uint64_t flags, bool enabled)
		{
			if (data)
				data->SetUserFlags(flags, enabled);
		}

		void SetOtherFlags(uint64_t flags, bool enabled)
		{
			if (data)
				data->SetOtherFlags(flags, enabled);
		}

		BSInputEnableLayer* data{ nullptr };
	};
}
