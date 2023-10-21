#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class TESKey;
	class TESObjectREFR;

	enum class LOCK_LEVEL
	{
		kUnlocked = static_cast<std::underlying_type_t<LOCK_LEVEL>>(-1),
		kEasy = 0,
		kAverage = 1,
		kHard = 2,
		kVeryHard = 3,
		kRequiresKey = 4,
		kInaccessible = 5,
		kTerminal = 6,
		kBarred = 7,
		kChained = 8,
	};

	struct REFR_LOCK
	{
		enum class Flag
		{
			kNone = 0,
			kLocked = 1 << 0,
			kLeveled = 1 << 2
		};

		[[nodiscard]] LOCK_LEVEL     GetLockLevel(const TESObjectREFR* a_owner) const;
		[[nodiscard]] constexpr bool IsLocked() const noexcept { return flags.all(Flag::kLocked); }
		void                         SetLocked(bool a_locked);

		// members
		TESKey*                              key;        // 00
		std::uint32_t                        numTries;   // 08
		stl::enumeration<Flag, std::uint8_t> flags;      // 0C
		std::int8_t                          baseLevel;  // 0D
	};
	static_assert(sizeof(REFR_LOCK) == 0x10);

	class ExtraLock : public BSExtraData
	{
	public:
		SF_RTTI_VTABLE(ExtraLock);
		SF_EXTRADATATYPE(Lock);

		~ExtraLock() override;  // 00

		// members
		REFR_LOCK* lock;  // 18
	};
	static_assert(sizeof(ExtraLock) == 0x20);
}
