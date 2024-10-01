#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESModel.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class BGSEffectSequenceForm;

	struct EffectShaderData  // DATA
	{
	public:
		// members
		std::uint32_t            unk00;         // 00
		std::uint32_t            unk04;         // 04
		std::uint32_t            unk08;         // 08
		std::uint32_t            unk0C;         // 0C
		std::uint32_t            unk10;         // 10
		std::uint32_t            unk14;         // 14
		std::uint32_t            unk18;         // 18
		std::uint32_t            unk1C;         // 1C
		std::uint32_t            unk20;         // 20
		std::uint32_t            unk24;         // 24
		std::uint32_t            unk28;         // 28
		std::uint32_t            unk2C;         // 2C
		std::uint32_t            unk30;         // 30
		std::uint32_t            unk34;         // 34
		BGSAudio::WwiseSoundHook ambientSound;  // 38
		std::uint32_t            unk68;         // 68
		std::uint32_t            unk6C;         // 6C
	};
	static_assert(sizeof(EffectShaderData) == 0x70);

	class TESEffectShader :
		public TESForm,  // 00
		public TESModel  // 30
	{
	public:
		SF_RTTI_VTABLE(TESEffectShader);
		SF_FORMTYPE(EFSH);

		~TESEffectShader() override;  // 00

		// members
		BGSEffectSequenceForm* effectSequence;  // 50
		EffectShaderData       data;            // 58
		std::uint32_t          unkC8;           // C8
	};
	static_assert(sizeof(TESEffectShader) == 0xD8);
}
