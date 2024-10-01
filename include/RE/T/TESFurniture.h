#pragma once

#include "RE/B/BGSAttachParentArray.h"
#include "RE/B/BSTArray.h"
#include "RE/T/TESObjectACTI.h"

namespace RE
{
	struct WorkbenchData
	{
	public:
		enum class Type : std::uint8_t
		{
			kNone = 0,
			kCreateObject = 1,
			kWeapons = 2,
			kEnchanting = 3,
			kEnchantingExperiment = 4,
			kAlchemy = 5,
			kAlchemyExperiment = 6,
			kArmor = 7,
			kPowerArmor = 8,
			kRobotMod = 9,
			kUnknown10 = 10,
			kResearch = 11
		};

		// members
		Type type;  // 0
	};
	static_assert(sizeof(WorkbenchData) == 0x1);

	class BSFurnitureMarker
	{
	public:
		// members
		NiPoint3      position;              // 00
		float         rotationZ;             // 0C
		BGSKeyword*   actorMustHaveKeyword;  // 10
		float         heading;               // 18
		std::uint32_t allowedAnimations;     // 1C
		std::uint64_t unk20;                 // 20
	};
	static_assert(sizeof(BSFurnitureMarker) == 0x28);

	class TESFurniture : public TESObjectACTI
	{
	public:
		SF_RTTI_VTABLE(TESFurniture);
		SF_FORMTYPE(FURN);

		struct EntryPointData
		{
		public:
			// members
			std::uint32_t entryPoint;  // 0
			std::uint32_t flags;       // 4
		};
		static_assert(sizeof(EntryPointData) == 0x8);

		~TESFurniture() override;  // 00

		// add
		virtual bool AllowZeroGravityUse() const;  // 82

		// members
		TESFurniture*               furnitureTemplate;    // 220
		BSTArray<EntryPointData>    entryPointDataArray;  // 228
		BGSAttachParentArray        attachParents;        // 248
		WorkbenchData               workBenchData;        // 258
		std::uint32_t               furnFlags;            // 25C
		TESForm*                    associatedForm;       // 260
		BSTArray<BSFurnitureMarker> markersArray;         // 268
		std::uint32_t               unk278;               // 278
	};
	static_assert(sizeof(TESFurniture) == 0x288);
}
