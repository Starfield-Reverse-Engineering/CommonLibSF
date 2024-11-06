#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/E/ExtraDataList.h"
#include "RE/I/InteriorData.h"
#include "RE/N/NiPoint.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESHandleForm.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class TESWorldSpace;

	struct EXTERIOR_DATA
	{
		// members
		std::int32_t  cellX;  // 00
		std::int32_t  cellY;  // 04
		std::uint32_t unk08;  // 08
		std::uint32_t unk0C;  // 0C
		std::uint64_t unk10;  // 10
		std::uint64_t unk18;  // 18
		std::uint64_t unk20;  // 20
		std::uint32_t unk28;  // 28
		std::uint32_t unk2C;  // 2C
		std::uint32_t unk30;  // 30
		std::uint8_t  unk34;  // 34
	};
	static_assert(sizeof(EXTERIOR_DATA) == 0x38);

	class TESObjectCELL :
		public TESHandleForm,  // 00
		public TESFullName     // 30
	{
	public:
		SF_RTTI_VTABLE(TESObjectCELL);
		SF_FORMTYPE(CELL);

		enum class Flag
		{
			kInterior = 1 << 0,
			kCanFastTravel = 1 << 2,
			kPublic = 1 << 5,
			kUsePlanetGravity = 1 << 17,
		};

		enum class CELL_STATE
		{
			kNotLoaded,
			kUnloading,
			kUnloadingData,
			kLoadingData,
			kLoadedData,
			kLoading,
			kLoaded,
			kDetaching,
			kAttachQueued,
			kAttaching,
			kAttached
		};

		struct ChangeFlags
		{
			enum ChangeFlag : std::uint32_t
			{
				kFlags = 1 << 1,
				kFullName = 1 << 2,
				kOwnership = 1 << 3,
				kExteriorShort = 1 << 28,
				kExteriorChar = 1 << 29,
				kDetachTime = 1 << 30,
				kSeenData = static_cast<std::uint32_t>(1) << 31
			};
		};

		union CellData
		{
			EXTERIOR_DATA* exterior;
			INTERIOR_DATA* interior;
		};
		static_assert(sizeof(CellData) == 0x8);

		~TESObjectCELL() override;  // 00

		[[nodiscard]] bool IsAttached() const noexcept { return cellState == CELL_STATE::kAttached; }
		[[nodiscard]] bool IsExterior() const noexcept { return !IsInterior(); }
		[[nodiscard]] bool IsInterior() const noexcept { return cellFlags.any(Flag::kInterior); }
		[[nodiscard]] bool UsesPlanetGravity() const noexcept { return cellFlags.any(Flag::kUsePlanetGravity); }

		void ForEachReference(std::function<BSContainer::ForEachResult(const NiPointer<TESObjectREFR>&)> a_callback) const
		{
			const BSAutoReadLock locker(lock);
			for (const auto& ref : references) {
				if (ref && a_callback(ref) == BSContainer::ForEachResult::kStop) {
					break;
				}
			}
		}

		void ForEachReferenceInRange(const NiPoint3A& a_origin, float a_radius, std::function<BSContainer::ForEachResult(const NiPointer<TESObjectREFR>&)> a_callback) const
		{
			const float squaredRadius = a_radius * a_radius;
			ForEachReference([&](const NiPointer<TESObjectREFR>& ref) {
				const auto distance = a_origin.GetSquaredDistance(ref->GetPosition());
				return distance <= squaredRadius ?
				           a_callback(ref) :
				           BSContainer::ForEachResult::kContinue;
			});
		}

		// members
		REX::EnumSet<Flag, std::uint32_t>   cellFlags;       // 040
		std::uint16_t                       cellGameFlags;   // 044
		std::uint8_t                        unk04E;          // 046
		REX::Enum<CELL_STATE, std::uint8_t> cellState;       // 047
		std::uint64_t                       unk050;          // 048
		BSTSmartPointer<ExtraDataList>      extraDataList;   // 050
		CellData                            cellData;        // 058
		std::uint32_t                       unk060;          // 060
		float                               unk064;          // 064
		float                               unk068;          // 068
		float                               unk06C;          // 06C
		std::uint8_t                        unk070;          // 070
		std::uint8_t                        pad071;          // 071
		std::uint16_t                       pad072;          // 072
		std::uint32_t                       pad074;          // 074
		std::uint64_t                       unk078;          // 078
		BSTArray<NiPointer<TESObjectREFR>>  references;      // 080
		std::uint64_t                       unk090;          // 090
		std::uint64_t                       unk098;          // 098
		std::uint64_t                       unk0A0;          // 0A0
		std::uint64_t                       unk0A8;          // 0A8
		std::uint64_t                       unk0B0;          // 0B0
		std::uint64_t                       unk0B8;          // 0B8
		std::uint64_t                       unk0C0;          // 0C0
		std::uint64_t                       unk0C8;          // 0C8
		std::uint64_t                       unk0D0;          // 0D0
		std::uint64_t                       unk0D8;          // 0D8
		std::uint64_t                       unk0E0;          // 0E0
		std::uint8_t                        unk0E8;          // 0E8
		std::uint8_t                        pad0E9;          // 0E9
		std::uint16_t                       pad0EA;          // 0EA
		std::uint32_t                       pad0EC;          // 0EC
		std::uint64_t                       unk0F0;          // 0F0
		std::uint64_t                       unk0F8;          // 0F8
		std::uint64_t                       unk100;          // 100
		std::uint64_t                       unk108;          // 108
		std::uint64_t                       unk110;          // 110
		TESWorldSpace*                      cellWorldspace;  // 118
		mutable BSReadWriteLock             lock;            // 120
		std::uint64_t                       unk128;          // 128
		std::uint64_t                       unk130;          // 130
		std::uint32_t                       unk138;          // 138
		std::uint64_t                       unk140;          // 140
	};
	static_assert(sizeof(TESObjectCELL) == 0x150);
}
