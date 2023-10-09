#pragma once

#include "RE/B/BGSMod.h"
#include "RE/B/BGSObjectPlacementDefaults.h"
#include "RE/B/BGSPreviewTransform.h"
#include "RE/B/BGSSnapTemplateComponent.h"
#include "RE/N/NiPoint3.h"
#include "RE/T/TESObject.h"

namespace RE
{
	class BGSVoiceType;

	class TESBoundObject : public TESObject
	{
	public:
		SF_RTTI_VTABLE(TESBoundObject);

		~TESBoundObject() override;

		// add
		virtual void          Unk_6C();                    // 6C
		virtual void          Unk_6D();                    // 6D
		virtual void          Unk_6E();                    // 6E
		virtual void          Unk_6F();                    // 6F
		virtual void          Unk_70();                    // 70
		virtual void          Unk_71();                    // 71
		virtual void          Unk_72();                    // 72
		virtual void          Unk_73();                    // 73
		virtual void          Unk_74();                    // 74
		virtual void          Unk_75();                    // 75
		virtual void          Unk_76();                    // 76
		virtual BGSVoiceType* GetObjectVoiceType() const;  // 77
		virtual void          Unk_78();                    // 78
		virtual void          Unk_79();                    // 79
		virtual void          Unk_7A();                    // 7A
		virtual void          Unk_7B();                    // 7B
		virtual void          Unk_7C();                    // 7C
		virtual void          Unk_7D();                    // 7D
		virtual void          Unk_7E();                    // 7E
		virtual void          Unk_7F();                    // 7F

		// members
		BGSSnapTemplateComponent   snapTemplate;       // 038
		NiPoint3                   boundMin;           // 050
		NiPoint3                   boundMax;           // 05C
		BGSMod::Template::Items    templateItems;      // 068
		BGSPreviewTransform        previewTransform;   // 088
		BGSObjectPlacementDefaults placementDefaults;  // 0D0
		std::uint32_t              unk0F0;             // 0F0
		std::uint64_t              unk0F8;             // 0F8
		std::uint64_t              unk100;             // 100
		std::uint64_t              unk108;             // 108
		std::uint64_t              unk110;             // 110
	};
	static_assert(sizeof(TESBoundObject) == 0x118);
}
