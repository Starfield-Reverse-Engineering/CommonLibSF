#pragma once

#include "RE/B/BGSMod.h"
#include "RE/B/BGSObjectPlacementDefaults.h"
#include "RE/B/BGSPreviewTransform.h"
#include "RE/B/BGSSnapTemplateComponent.h"
#include "RE/T/TESObject.h"

namespace RE
{
	class TESBoundObject :
		public TESObject  // 00
	{
	public:
		SF_RTTI_VTABLE(TESBoundObject);

		// add
		virtual void Unk_6C();  // 6C
		virtual void Unk_6D();  // 6D
		virtual void Unk_6E();  // 6E
		virtual void Unk_6F();  // 6F
		virtual void Unk_70();  // 70
		virtual void Unk_71();  // 71
		virtual void Unk_72();  // 72
		virtual void Unk_73();  // 73
		virtual void Unk_74();  // 74
		virtual void Unk_75();  // 75
		virtual void Unk_76();  // 76
		virtual void Unk_77();  // 77
		virtual void Unk_78();  // 78
		virtual void Unk_79();  // 79
		virtual void Unk_7A();  // 7A
		virtual void Unk_7B();  // 7B
		virtual void Unk_7C();  // 7C
		virtual void Unk_7D();  // 7D
		virtual void Unk_7E();  // 7E
		virtual void Unk_7F();  // 7F

		// members
		BGSSnapTemplateComponent   snapTemplate;       // 38
		std::uint64_t              unk50;              // 50
		std::uint32_t              unk58;              // 58
		std::uint32_t              unk5C;              // 5C
		std::uint64_t              unk60;              // 60
		BGSMod::Template::Items    templateItems;      // 68
		BGSPreviewTransform        previewTransform;   // 88
		BGSObjectPlacementDefaults placementDefaults;  // D0
	};
	static_assert(offsetof(TESBoundObject, templateItems) == 0x68);
	static_assert(offsetof(TESBoundObject, previewTransform) == 0x88);
	static_assert(offsetof(TESBoundObject, placementDefaults) == 0xD0);
	static_assert(sizeof(TESBoundObject) == 0xF0);
}
