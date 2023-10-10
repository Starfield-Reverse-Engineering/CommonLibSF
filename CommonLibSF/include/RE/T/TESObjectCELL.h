#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiPoint3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/TESFullName.h"
#include "RE/T/TESHandleForm.h"

namespace RE
{
	class TESObjectREFR;
	class TESWorldSpace;

	struct INTERIOR_DATA
	{
	public:
		// members
		std::uint64_t unk00;         // 00
		std::uint32_t fogColorNear;  // 08
		float         fogPlaneNear;  // 0C
		float         fogPlaneFar;   // 10
		std::uint32_t unk14;         // 14
		std::uint32_t unk18;         // 18
		float         gravity;       // 1C
		std::uint32_t unk20;         // 20
		std::uint32_t fogPower;      // 24
		std::uint32_t fogColorFar;   // 28
		std::uint32_t unk2C;         // 2C
		std::uint32_t unk30;         // 30
		std::uint32_t unk34;         // 34
		float         unk38;         // 38
		std::uint32_t unk3C;         // 3C
		float         unk40;         // 40
		std::uint32_t unk44;         // 44
		std::uint32_t unk48;         // 48
		float         unk50;         // 50
		float         unk54;         // 54
		float         unk58;         // 58
		float         unk5C;         // 5C
		std::uint32_t unk60;         // 60
		std::uint32_t unk64;         // 64
		std::int8_t   unk68;         // 68
		std::uint32_t unk6C;         // 6C
		std::uint64_t unk70;         // 70
	};
	static_assert(sizeof(INTERIOR_DATA) == 0x78);

	struct EXTERIOR_DATA
	{
	public:
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
		public TESFullName     // 20
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
				kSeenData = (std::uint32_t)1 << 31
			};
		};

		union CellData
		{
			EXTERIOR_DATA* exterior;
			INTERIOR_DATA* interior;
		};
		static_assert(sizeof(CellData) == 0x8);

		~TESObjectCELL() override;  // 00

		[[nodiscard]] bool IsAttached() const noexcept { return cellState.all(CELL_STATE::kAttached); }
		[[nodiscard]] bool IsExterior() const noexcept { return !IsInterior(); }
		[[nodiscard]] bool IsInterior() const noexcept { return cellFlags.any(Flag::kInterior); }
		[[nodiscard]] bool UsesPlanetGravity() const noexcept { return cellFlags.any(Flag::kUsePlanetGravity); }

		void ForEachReference(std::function<BSContainer::ForEachResult(const NiPointer<TESObjectREFR>&)> a_callback) const;
		void ForEachReferenceInRange(const NiPoint3A& a_origin, float a_radius, std::function<BSContainer::ForEachResult(const NiPointer<TESObjectREFR>&)> a_callback) const;

		// members
		stl::enumeration<Flag, std::uint32_t>      cellFlags;       // 048
		std::uint16_t                              cellGameFlags;   // 04C
		std::uint8_t                               unk4E;           // 04E
		stl::enumeration<CELL_STATE, std::uint8_t> cellState;       // 04F
		std::uint64_t                              unk50;           // 050
		void*                                      extraDataList;   // 058 - smart ptr
		CellData                                   cellData;        // 060
		std::uint32_t                              unk068;          // 068
		float                                      unk06C;          // 06C
		float                                      unk070;          // 070
		float                                      unk074;          // 074
		std::uint8_t                               unk078;          // 078
		std::uint8_t                               pad079;          // 079
		std::uint16_t                              pad07A;          // 07A
		std::uint32_t                              pad07C;          // 07C
		std::uint64_t                              unk080;          // 080
		BSTArray<NiPointer<TESObjectREFR>>         references;      // 088
		std::uint64_t                              unk098;          // 098
		std::uint64_t                              unk0A0;          // 0A0
		std::uint64_t                              unk0A8;          // 0A8
		std::uint64_t                              unk0B0;          // 0B0
		std::uint64_t                              unk0B8;          // 0B8
		std::uint64_t                              unk0C0;          // 0C0
		std::uint64_t                              unk0C8;          // 0C8
		std::uint64_t                              unk0D0;          // 0D0
		std::uint64_t                              unk0D8;          // 0D8
		std::uint64_t                              unk0E0;          // 0E0
		std::uint64_t                              unk0E8;          // 0E8
		std::uint8_t                               unk0F0;          // 0F0
		std::uint8_t                               pad0F1;          // 0F1
		std::uint16_t                              pad0F2;          // 0F2
		std::uint32_t                              pad0F4;          // 0F4
		std::uint64_t                              unk0F8;          // 0F8
		std::uint64_t                              unk100;          // 100
		std::uint64_t                              unk108;          // 108
		std::uint64_t                              unk110;          // 110
		std::uint64_t                              unk118;          // 118
		TESWorldSpace*                             cellWorldspace;  // 120
		mutable BSReadWriteLock                    lock;            // 128
		std::uint64_t                              unk130;          // 130
		std::uint64_t                              unk138;          // 138
		std::uint32_t                              unk140;          // 140
		std::uint64_t                              unk148;          // 148
	};
	static_assert(sizeof(TESObjectCELL) == 0x150);
}
