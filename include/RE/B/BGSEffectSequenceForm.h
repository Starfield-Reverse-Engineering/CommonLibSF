#pragma once

#include "RE/B/BGSReflectedForm.h"

namespace RE
{
	namespace BSSequence
	{
		class Sequence;

		class NamedSequenceMap
		{
		public:
			virtual ~NamedSequenceMap();  // 00

			// add
			virtual void Unk_01();  // 01
			virtual void Unk_02();  // 02

			// members
			/*std::set<std::pair<BSFixedString, std::unique_ptr<Sequence>>>*/ std::uint8_t sequences[0x30];  // 08
		};
		static_assert(sizeof(NamedSequenceMap) == 0x38);
	}

	class EffectSequenceMap : public BSSequence::NamedSequenceMap
	{
	public:
		~EffectSequenceMap() override;  // 00

		// members
		BGSEffectSequenceForm* parent;  // 38
		BSTArray<void*>        unk40;   // 40
		std::uint8_t           unk50;   // 50
	};
	static_assert(sizeof(EffectSequenceMap) == 0x58);

	class BGSEffectSequenceForm : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSEffectSequenceForm);
		SF_FORMTYPE(EFSQ);

		~BGSEffectSequenceForm() override;  // 00

		// members
		EffectSequenceMap map;  // 30
	};
	static_assert(sizeof(BGSEffectSequenceForm) == 0x88);
}
