#pragma once

#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BGSInventoryItem;
	class TESBoundObject;

	namespace InventoryInterface
	{
		struct FavoriteChangedEvent
		{
		public:
			~FavoriteChangedEvent() noexcept {}  // intentional

			// members
			BGSInventoryItem* itemAffected;  // 0
		};
		static_assert(sizeof(FavoriteChangedEvent) == 0x8);

		struct Handle
		{
		public:
			~Handle() noexcept {}  // intentional

			// members
			std::uint32_t id;  // 0
		};
		static_assert(sizeof(Handle) == 0x4);
	}

	class alignas(0x08) BGSInventoryInterface :
		BSTSingletonSDM<BGSInventoryInterface>,                   // 00
		BSTEventSource<InventoryInterface::FavoriteChangedEvent>  // 08
	{
	public:
		struct Agent
		{
		public:
			// members
			std::uint32_t handleID;   // 0
			std::uint32_t itemOwner;  // 4 - TESPointerHandle
			std::uint16_t listIndex;  // 8
			std::uint16_t refCount;   // A
		};
		static_assert(sizeof(Agent) == 0xC);

		[[nodiscard]] static BGSInventoryInterface* GetSingleton()
		{
			static REL::Relocation<BGSInventoryInterface**> singleton{ ID::BGSInventoryInterface::Singleton };
			return *singleton;
		}

		[[nodiscard]] TESBoundObject* GetInventoryObject(const std::uint32_t& a_handleID) const
		{
			using func_t = decltype(&BGSInventoryInterface::GetInventoryObject);
			static REL::Relocation<func_t> func{ ID::BGSInventoryInterface::GetInventoryObject };
			return func(this, a_handleID);
		}

		virtual ~BGSInventoryInterface();  // 00

		// members
		BSTArray<Agent> agentArray;  // 30
	};
	//static_assert(sizeof(BGSInventoryInterface) == 0x48);
}
