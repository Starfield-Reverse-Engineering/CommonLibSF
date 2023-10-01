#pragma once

namespace RE
{
	struct ActorPackageData;
	class TESPackage;

	class ActorPackage
	{
	public:
		// members
		void*             packageLock;            // 00
		TESPackage*       package;                // 08
		ActorPackageData* data;                   // 10
		void*             target;                 // 18
		std::int32_t      currentProcedureIndex;  // 1C
		float             packageStartTime;       // 20
		std::uint32_t     modifiedPackageFlag;    // 24
		std::uint16_t     modifiedInterruptFlag;  // 28
		std::int8_t       actorPackageFlags;      // 2A
		std::int8_t       preferredSpeed;         // 2B
	};
	static_assert(sizeof(ActorPackage) == 0x30);
}
