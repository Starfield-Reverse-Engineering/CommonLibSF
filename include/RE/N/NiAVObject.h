#pragma once

#include "RE/N/NiBound.h"
#include "RE/N/NiObjectNET.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/N/NiTransform.h"

namespace RE
{
	class NiCollisionObject;
	class NiNode;
	class NiUpdateData;

	class __declspec(novtable) NiAVObject :
		public NiObjectNET
	{
	public:
		SF_RTTI_VTABLE(NiAVObject);

		virtual ~NiAVObject() = default;

		// add
		virtual void*   Unk55();
		virtual void*   Unk56();
		virtual void*   Unk57();
		virtual void*   Unk58();
		virtual void*   Unk59();
		virtual void*   Unk60();
		virtual void*   Unk61();
		virtual NiNode* GetObjectByName(const BSFixedString& a_name);
		virtual void*   SetSelectiveUpdateFlags();
		virtual void*   Unk64();
		virtual void*   Unk65();
		virtual void*   Unk66();
		virtual void*   Unk67();
		virtual void*   Unk68();
		virtual void*   Unk69();
		virtual void*   Unk70();
		virtual void*   Unk71();
		virtual void*   Unk72();
		virtual void*   Update(NiUpdateData* a_data);
		virtual void*   Unk74();
		virtual void*   Unk75();
		virtual void*   Unk76();
		virtual void*   Unk77();
		virtual void*   Unk78();
		virtual void*   UpdateWorldData(NiUpdateData* a_data);
		virtual void*   UpdateTransformAndBounds(NiUpdateData* a_data);
		virtual void*   UpdateTransforms(NiUpdateData* a_data);
		virtual void*   Unk82();
		virtual void*   Unk83();

		// members
		NiNode*                      parent;           // 038
		NiTransform                  local;            // 040
		NiTransform                  world;            // 080
		NiTransform                  previousWorld;    // 0C0
		NiBound                      worldBound;       // 100
		NiPointer<NiCollisionObject> collisionObject;  // 110
		std::uint64_t                flags;            // 118
		void*                        unk120;           // 120
		void*                        unk128;           // 128
	};
	static_assert(sizeof(NiAVObject) == 0x130);
	static_assert(offsetof(NiAVObject, parent) == 0x38);
	static_assert(offsetof(NiAVObject, local) == 0x40);
	static_assert(offsetof(NiAVObject, world) == 0x80);
	static_assert(offsetof(NiAVObject, collisionObject) == 0x110);
	static_assert(offsetof(NiAVObject, flags) == 0x118);
}
