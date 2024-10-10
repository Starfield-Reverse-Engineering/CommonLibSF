#pragma once

#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTList.h"
#include "RE/F/FormTypes.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class TESFile;
	class TESForm;
	class TESRegionDataManager;

	struct BGSHotloadCompletedEvent;
	struct TESRegionList;

	struct TESFileCollection
	{
	public:
		// members
		BSTArray<TESFile*> files;       // 00
		BSTArray<TESFile*> smallFiles;  // 10
	};
	static_assert(sizeof(TESFileCollection) == 0x20);

	class TESDataHandler :
		public BSTEventSource<BGSHotloadCompletedEvent>  // 0000
	{
	public:
		SF_RTTI_VTABLE(TESDataHandler);

		struct FormArray
		{
			mutable BSReadWriteLock      lock;       // 00
			BSTArray<NiPointer<TESForm>> formArray;  // 08
		};
		static_assert(sizeof(FormArray) == 0x18);

		[[nodiscard]] static TESDataHandler* GetSingleton()
		{
			static REL::Relocation<TESDataHandler**> singleton{ ID::TESDataHandler::Singleton };
			return *singleton;
		}

		// members
		void*                  unk0028;                                           // 0028 - BSService::Detail::TService<BSService::Detail::TServiceTraits<TESDataHandler,BSService::Detail::ReferenceGetterDefaultPointer<TESDataHandler *>>>
		std::uint64_t          unk0030;                                           // 0030
		std::uint64_t          unk0038;                                           // 0038
		std::uint64_t          unk0040;                                           // 0040
		std::uint64_t          unk0048;                                           // 0048
		std::uint64_t          unk0050;                                           // 0050
		std::uint64_t          unk0058;                                           // 0058
		std::uint64_t          unk0060;                                           // 0060
		std::uint64_t          unk0068;                                           // 0068
		FormArray              formArrays[std::to_underlying(FormType::kTotal)];  // 0070
		TESRegionList*         regionList;                                        // 1498
		std::uint64_t          unk14A0;                                           // 14A0
		std::uint64_t          unk14A8;                                           // 14A8
		std::uint64_t          unk14B0;                                           // 14B0
		std::uint64_t          unk14B8;                                           // 14B8
		std::uint64_t          unk14C0;                                           // 14C0
		std::uint64_t          unk14C8;                                           // 14C8
		std::uint64_t          unk14D0;                                           // 14D0
		std::uint64_t          unk14D8;                                           // 14D8
		std::uint64_t          unk14E0;                                           // 14E0
		std::uint64_t          unk14E8;                                           // 14E8
		BSSimpleList<TESFile*> files;                                             // 14F0
		TESFileCollection      compiledFileCollection;                            // 1500
		std::uint64_t          unk1520;                                           // 1520
		std::uint64_t          unk1528;                                           // 1528
		std::uint64_t          unk1530;                                           // 1530
		std::uint64_t          unk1538;                                           // 1538
		std::uint64_t          unk1540;                                           // 1540
		std::uint64_t          unk1548;                                           // 1548
		std::uint64_t          unk1550;                                           // 1550
		std::uint64_t          unk1558;                                           // 1558
		std::uint64_t          unk1560;                                           // 1560
		std::uint64_t          unk1568;                                           // 1568
		std::uint64_t          unk1570;                                           // 1570
		std::uint64_t          unk1578;                                           // 1578
		std::uint64_t          unk1580;                                           // 1580
		std::uint64_t          unk1588;                                           // 1588
		std::uint64_t          unk1590;                                           // 1590
		std::uint64_t          unk1598;                                           // 1598
		std::uint64_t          unk15A0;                                           // 15A0
		std::uint64_t          unk15A8;                                           // 15A8
		std::uint64_t          unk15B0;                                           // 15B0
		std::uint64_t          unk15B8;                                           // 15B8
		std::uint64_t          unk15C0;                                           // 15C0
		std::uint64_t          unk15C8;                                           // 15C8
		std::uint64_t          unk15D0;                                           // 15D0
		std::uint64_t          unk15D8;                                           // 15D8
		std::uint64_t          unk15E0;                                           // 15E0
		std::uint64_t          unk15E8;                                           // 15E8
		std::uint64_t          unk15F0;                                           // 15F0
		std::uint64_t          unk15F8;                                           // 15F8
		std::uint64_t          unk1600;                                           // 1600
		std::uint64_t          unk1608;                                           // 1608
		std::uint64_t          unk1610;                                           // 1610
		std::uint64_t          unk1618;                                           // 1618
		std::uint64_t          unk1620;                                           // 1620
		std::uint64_t          unk1628;                                           // 1628
		std::uint64_t          unk1630;                                           // 1630
		std::uint64_t          unk1638;                                           // 1638
		std::uint64_t          unk1640;                                           // 1640
		std::uint64_t          unk1648;                                           // 1648
		std::uint64_t          unk1650;                                           // 1650
		std::uint64_t          unk1658;                                           // 1658
		std::uint64_t          unk1660;                                           // 1660
		std::uint64_t          unk1668;                                           // 1668
		std::uint64_t          unk1670;                                           // 1670
		std::uint64_t          unk1678;                                           // 1678
		std::uint64_t          unk1680;                                           // 1680
		std::uint64_t          unk1688;                                           // 1688
		std::uint64_t          unk1690;                                           // 1690
		std::uint64_t          unk1698;                                           // 1698
		std::uint64_t          unk16A0;                                           // 16A0
		std::uint64_t          unk16A8;                                           // 16A8
		std::uint64_t          unk16B0;                                           // 16B0
		std::uint64_t          unk16B8;                                           // 16B8
		std::uint64_t          unk16C0;                                           // 16C0
		std::uint64_t          unk16C8;                                           // 16C8
		std::uint64_t          unk16D0;                                           // 16D0
		std::uint64_t          unk16D8;                                           // 16D8
		std::uint64_t          unk16E0;                                           // 16E0
		std::uint64_t          unk16E8;                                           // 16E8
		std::uint64_t          unk16F0;                                           // 16F0
		std::uint64_t          unk16F8;                                           // 16F8
		std::uint64_t          unk1700;                                           // 1700
		std::uint64_t          unk1708;                                           // 1708
		TESRegionDataManager*  regionDataManager;                                 // 1710
		std::uint64_t          unk1718;                                           // 1718
		std::uint64_t          unk1720;                                           // 1720
		std::uint64_t          unk1728;                                           // 1728
		std::uint64_t          unk1730;                                           // 1730
		std::uint64_t          unk1738;                                           // 1738
	};
	static_assert(sizeof(TESDataHandler) == 0x1740);
}
