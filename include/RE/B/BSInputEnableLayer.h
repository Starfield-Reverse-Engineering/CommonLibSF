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

		std::uint64_t SetUserFlags(std::uint64_t a_flags, bool a_enabled)
		{
			using func_t = decltype(&BSInputEnableLayer::SetUserFlags);
			static REL::Relocation<func_t> func{ ID::BSInputEnableLayer::SetUserFlags };
			return func(this, a_flags, a_enabled);
		}

		std::uint64_t SetOtherFlags(std::uint64_t a_flags, bool a_enabled)
		{
			using func_t = decltype(&BSInputEnableLayer::SetOtherFlags);
			static REL::Relocation<func_t> func{ ID::BSInputEnableLayer::SetOtherFlags };
			return func(this, a_flags, a_enabled);
		}

		// members
		std::uint32_t index;
		std::uint32_t state;
		std::uint64_t unk08;
		std::uint64_t unk10;
		std::uint64_t unk18;
	};

	class InputEnableLayer
	{
	public:
		InputEnableLayer() = default;

		InputEnableLayer(const char* a_layerName)
		{
			Create(a_layerName);
		}

		~InputEnableLayer()
		{
			Free();
		}

		bool Create(const char* a_layerName)
		{
			bool result = true;
			if (!data) {
				result = BSInputEnableManager::GetSingleton()->CreateLayer(this, a_layerName);
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
				static REL::Relocation<func_t> func{ ID::InputEnableLayer::Free };
				result = func(this);
				data = nullptr;
			}

			return result;
		}

		void SetUserFlags(std::uint64_t a_flags, bool a_enabled)
		{
			if (data)
				data->SetUserFlags(a_flags, a_enabled);
		}

		void SetOtherFlags(std::uint64_t a_flags, bool a_enabled)
		{
			if (data)
				data->SetOtherFlags(a_flags, a_enabled);
		}

		// members
		BSInputEnableLayer* data{ nullptr };
	};
}
