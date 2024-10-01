#pragma once

#include "RE/B/BGSReflectedForm.h"

#include "REX/W32/D3D.h"

namespace RE::BSGalaxy
{
	class BGSSunPresetForm : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BSGalaxy__BGSSunPresetForm);
		SF_FORMTYPE(SUNP);

		struct alignas(4) DawnDuskSettings
		{
			REX::W32::XMFLOAT4 directionalColor;      // 00
			float              transitionStartAngle;  // 10
			float              transitionEndAngle;    // 14
		};
		static_assert(sizeof(DawnDuskSettings) == 0x18);

		struct alignas(4) NightSettings
		{
			REX::W32::XMFLOAT4 directionalColor;        // 00
			float              directionalIlluminance;  // 10
			REX::W32::XMFLOAT4 glareColor;              // 14
		};
		static_assert(sizeof(NightSettings) == 0x24);

		~BGSSunPresetForm() override;  // 00

		// members
		BGSSunPresetForm*  parent;          // 30
		REX::W32::XMFLOAT4 sunColor;        // 38
		float              sunIlluminance;  // 48
		REX::W32::XMFLOAT4 sunGlareColor;   // 4C
		DawnDuskSettings   dawnDuskPreset;  // 5C
		NightSettings      nightPreset;     // 74
		std::uint64_t      unk98;           // 98
	};
	static_assert(sizeof(BGSSunPresetForm) == 0xA8);
}
