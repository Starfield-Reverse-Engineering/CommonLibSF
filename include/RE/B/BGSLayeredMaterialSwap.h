#pragma once

#include "RE/B/BGSKeyword.h"
#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BSTArray.h"

namespace RE
{
	class BGSLayeredMaterialSwap :
		public BGSReflectedForm,                         // 00
		public BSTEventSink<BGSKeyword::OnDestroyEvent>  // 30
	{
	public:
		SF_RTTI_VTABLE(BGSLayeredMaterialSwap);
		SF_FORMTYPE(LMSW);

		enum class SOURCE
		{
			kNone = 0,
			kModelOnly = 1,
			kRefDefined = 2,
			kBiome = 3,
			kObjectTemplate = 4,
			kSkin = 5,
			kPackin = 6
		};

		struct Entry;

		~BGSLayeredMaterialSwap() override;  // 00

		// members
		BSTArray<BGSKeyword*> keywords;        // 38
		BSTArray<Entry>       entries;         // 48
		BSTArray<void*>       swapCollection;  // 58
	};
	static_assert(sizeof(BGSLayeredMaterialSwap) == 0x70);
}
