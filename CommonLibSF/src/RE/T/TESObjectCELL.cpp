#include "RE/T/TESObjectCELL.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	void TESObjectCELL::ForEachReference(std::function<BSContainer::ForEachResult(const NiPointer<TESObjectREFR>&)> a_callback) const
	{
		const BSAutoReadLock locker(lock);
		for (const auto& ref : references) {
			if (ref && a_callback(ref) == BSContainer::ForEachResult::kStop) {
				break;
			}
		}
	}

	void TESObjectCELL::ForEachReferenceInRange(const NiPoint3A& a_origin, float a_radius, std::function<BSContainer::ForEachResult(const NiPointer<TESObjectREFR>&)> a_callback) const
	{
		const float squaredRadius = a_radius * a_radius;
		ForEachReference([&](const NiPointer<TESObjectREFR>& ref) {
			const auto distance = a_origin.GetSquaredDistance(ref->GetPosition());
			return distance <= squaredRadius ?
			           a_callback(ref) :
			           BSContainer::ForEachResult::kContinue;
		});
	}
}
