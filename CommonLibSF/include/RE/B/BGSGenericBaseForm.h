#pragma once

#include "RE/B/BGSEditorID.h"
#include "RE/B/BGSNavmeshableObject.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class BGSGenericBaseFormTemplate;

	class BGSGenericBaseForm :
		public TESBoundObject,       // 000
		public BGSNavmeshableObject  // 118
	{
	public:
		SF_RTTI_VTABLE(BGSGenericBaseForm);
		SF_FORMTYPE(GBFM);

		// members
		BGSEditorID                 formEditorID;             // 120
		BGSGenericBaseFormTemplate* genericBaseFormTemplate;  // 130
	};
	static_assert(sizeof(BGSGenericBaseForm) == 0x138);
}
