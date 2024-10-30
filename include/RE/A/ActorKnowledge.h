#pragma once

#include "RE/A/AITimeStamp.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/N/NiRefObject.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class DetectionState;

	class __declspec(novtable) ActorKnowledge :
		public NiRefObject
	{
	public:
		SF_RTTI_VTABLE(ActorKnowledge);

		// members
		BSPointerHandle<Actor>    owner;                        // 10
		BSPointerHandle<Actor>    target;                       // 14
		AITimeStamp               factionFightReaction;         // 18
		float                     shouldAttackTargetTimeStamp;  // 1C
		float                     damagePerSecond;              // 20
		NiPointer<DetectionState> detectionState;               // 28
	};
}
