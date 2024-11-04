#pragma once

#include "RE/T/TESForm.h"

namespace RE
{
	class TESPackageData;

	struct PACKAGE_DATA
	{
		// members
		std::uint32_t packageFlags;           // 0
		std::int8_t   packageType;            // 4
		std::int8_t   interruptOverrideType;  // 5
		std::int8_t   maxSpeed;               // 6
		std::uint16_t foBehaviorFlags;        // 8
		std::uint16_t packageSpecificFlags;   // A
	};
	static_assert(sizeof(PACKAGE_DATA) == 0xC);

	struct PackageLocation
	{
	};

	struct PackageTarget
	{
		// members
		std::uint8_t type;
		// TODO: warning C4624: 'PackageTarget': destructor was implicitly defined as deleted
		/*
		union
		{
			BSPointerHandle<TESObjectREFR> refHandle;
			TESForm*                       object;
		};
		std::int32_t value;
		*/
	};
	//static_assert(sizeof(PackageTarget) == 0x18);

	class __declspec(novtable) TESPackage :
		public TESForm  // 00
	{
	public:
		SF_RTTI_VTABLE(TESPackage);
		SF_FORMTYPE(PACK);

		~TESPackage() override;  // 00

		// members
		PACKAGE_DATA     packageData;      // 38
		TESPackageData*  packageData2;     // 48
		PackageLocation* packageLocation;  // 50
		PackageTarget*   packageTarget;    // 58
	};
	static_assert(offsetof(TESPackage, packageData2) == 0x48);
}
