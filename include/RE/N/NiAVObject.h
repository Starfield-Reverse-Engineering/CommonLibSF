#pragma once
#include "RE/B/BSFixedString.h"
#include "RE/N/NiTransform.h"
#include "RE/N/NiBound.h"

namespace RE
{
	class NiRTTI;
	class NiNode;
	class BSLight;

	struct NiUpdateData
	{
		float     delta = 0;
		float     unk04 = 0;
		float     unk08 = 0;
		uint32_t  unk0C = 0;
		NiPoint4* unk10 = nullptr;
		NiPoint4* unk18 = nullptr;
		uint64_t  unk20 = 0;
		uint64_t  unk28 = 0;
		uint64_t  unk30 = 0;
		uint32_t  flags = 0x10;
		uint32_t  flags2 = 1;
		uint32_t  flags3 = 1;
		uint32_t  unk44 = 0;
		float     unk48 = 0;
		uint32_t  unk4C = 0;
		float     unk50 = 0;
		float     unk54 = 0;
		float     unk58 = 0;
		uint32_t  unk5C = 0;
	};

	class NiObject
	{
	public:
		virtual ~NiObject() = default;
		virtual void*       DeleteThis();
		virtual NiRTTI*     GetRTTI();
		virtual NiNode*     GetAsNiNode();
		virtual NiNode*     GetAsNiSwitchNode();
		virtual void*       Unk5() { return nullptr; }
		virtual void*       Unk6() { return nullptr; }
		virtual void*       Unk7() { return nullptr; }
		virtual void*       Unk8() { return nullptr; }
		virtual NiAVObject* GetAsBSGeometry() { return nullptr; }
		virtual void*       Unk10() { return nullptr; }
		virtual void*       Unk11() { return nullptr; }
		virtual void*       Unk12() { return nullptr; }
		virtual void*       Unk13() { return nullptr; }
		virtual void*       Unk14() { return nullptr; }
		virtual void*       Unk15() { return nullptr; }
		virtual void*       Unk16() { return nullptr; }
		virtual void*       Unk17() { return nullptr; }
		virtual void*       Unk18() { return nullptr; }
		virtual void*       Unk19() { return nullptr; }
		virtual void*       Unk20() { return nullptr; }
		virtual void*       Unk21() { return nullptr; }
		virtual void*       Unk22() { return nullptr; }
		virtual void*       Unk23() { return nullptr; }
		virtual void*       Unk24() { return nullptr; }
		virtual void*       Unk25() { return nullptr; }
		virtual void*       Unk26() { return nullptr; }
		virtual void*       Unk27() { return nullptr; }
		virtual void*       Unk28() { return nullptr; }
		virtual void*       Unk29() { return nullptr; }
		virtual void*       Unk30() { return nullptr; }
		virtual BSLight*    GetAsBSLight() { return nullptr; }
		virtual void*       Unk32() { return nullptr; }
		virtual void*       Unk33() { return nullptr; }
		virtual void*       Unk34() { return nullptr; }
		virtual void*       Unk35() { return nullptr; }
		virtual void*       Unk36() { return nullptr; }
		virtual void*       Unk37() { return nullptr; }
		virtual void*       Unk38() { return nullptr; }
		virtual void*       Unk39() { return nullptr; }
		virtual void*       Unk40() { return nullptr; }
		virtual void*       Unk41();
		virtual void*       Unk42();
		virtual void*       Unk43();
		virtual void*       Unk44();
		virtual void*       Unk45();
		virtual void*       Unk46();
		virtual void*       Unk47();
		virtual void*       Unk48();
		virtual void*       Unk49();
		virtual void*       Unk50();
		virtual void*       Unk51();
		virtual void*       Unk52();
		virtual void*       Unk53();
		virtual void*       Unk54();
	};

	class NiAVObject : public NiObject
	{
	public:
		virtual ~NiAVObject() = default;
		virtual void*   Unk55();
		virtual void*   Unk56();
		virtual void*   Unk57();
		virtual void*   Unk58();
		virtual void*   Unk59();
		virtual void*   Unk60();
		virtual void*   Unk61();
		virtual NiNode* GetObjectByName(const BSFixedString& name);
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
		virtual void*   Update(NiUpdateData* data);
		virtual void*   Unk74();
		virtual void*   Unk75();
		virtual void*   Unk76();
		virtual void*   Unk77();
		virtual void*   Unk78();
		virtual void*   UpdateWorldData(NiUpdateData* data);
		virtual void*   UpdateTransformAndBounds(NiUpdateData* data);
		virtual void*   UpdateTransforms(NiUpdateData* data);
		virtual void*   Unk82();
		virtual void*   Unk83();

		void IncRefCount()
		{
			_InterlockedExchangeAdd(&refcount, 1);
		}
		
		void DecRefCount()
		{
			if (_InterlockedExchangeAdd(&refcount, -1) == 1)
				DeleteThis();
		}

		volatile long refcount;
		uint32_t      pad0C;
		BSFixedString name;
		void*         controller;
		void*         unk28;
		void*         unk30;
		void*         unk38;
		NiNode*       parent;         //38
		NiTransform   local;          //40
		NiTransform   world;          //80
		NiTransform   previousWorld;  //C0
		NiBound       worldBound;     //100
		void*         collisionObject;
		uint64_t      flags;  //118
		void*         unk120;
		void*         unk128;
	};
	static_assert(sizeof(NiAVObject) == 0x130);
	static_assert(offsetof(NiAVObject, NiAVObject::parent) == 0x38);
	static_assert(offsetof(NiAVObject, NiAVObject::local) == 0x40);
	static_assert(offsetof(NiAVObject, NiAVObject::world) == 0x80);
}
