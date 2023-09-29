#pragma once

#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class NiNode;

	class TESCamera
	{
	public:
		SF_RTTI(TESCamera);

		virtual ~TESCamera();  // 00

		// add
		virtual void SetCameraRoot(NiNode* a_cameraRoot);  // 01
		virtual void SetEnabled(bool a_enabled);           // 02
		virtual void Update();                             // 03
		virtual void Unk_04();                             // 04

		// members
		NiPointer<NiNode> cameraRoot;    // 08
		void*             currentState;  // 10 - BSTSmartPointer<TESCameraState>
		std::uint64_t     unk18;         // 18
		bool              enabled;       // 20
		float             unk24;         // 24
		float             unk28;         // 28
		float             unk2C;         // 2C
		float             unk30;         // 30
		float             unk34;         // 34
		float             unk38;         // 38
		float             unk3C;         // 3C
		float             unk40;         // 40
		std::uint32_t     pad44;         // 44
	};
	static_assert(sizeof(TESCamera) == 0x48);
}
