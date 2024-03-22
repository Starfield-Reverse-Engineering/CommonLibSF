#pragma once
#include "RE/N/NiPoint3.h"

namespace RE
{
	template <class T>
	class NiRect
	{
	public:
		T left;    // 00
		T right;   // ??
		T top;     // ??
		T bottom;  // ??
	};

	class NiFrustum
	{
	public:
		float left;    // 00
		float right;   // 04
		float top;     // 08
		float bottom;  // 0C
		float _near;   // 10
		float _far;    // 14
		bool  ortho;   // 18
	};
	static_assert(sizeof(NiFrustum) == 0x1C);

	class NiCamera : public NiAVObject
	{
	public:
		virtual ~NiCamera() = default;
		//leftBoundary and rightBoundary are outputted based on the W (radius) component of worldPt.
		//If the W component is small enough, they are essentially equal, and point to the exact
		//XYZ location provided.
		//The returned NiPoint2 does not contain any world-to-screen information and can be ignored.
		NiPoint2 WorldToScreenInternal(const NiPoint4* worldPt, NiPoint3* leftBoundary, NiPoint3* rightBoundary)
		{
			using func_t = decltype(&NiCamera::WorldToScreenInternal);
			REL::Relocation<func_t> func{ REL::ID(210415) };
			return func(this, worldPt, leftBoundary, rightBoundary);
		}

		//The returned X and Y are in the range -1 to 1, with 1 being top right and -1 being bottom left.
		//The returned Z is the distance from the camera to the worldPt, with negative values meaning the
		//camera is facing away from the worldPt.
		//Note: The Z component is very small due to Starfield's unit scale.
		//i.e. distance from player to camera when the camera is close is ~0.0004
		NiPoint3 WorldToScreen(const NiPoint3& worldPt)
		{
			NiPoint3 result{ 0.0f, 0.0f, -1.0f };
			float worldDiffRotated = (
				((worldPt.y - world.translate.y) * world.rotate[0][1]) +
				((worldPt.x - world.translate.x) * world.rotate[0][0]) +
				((worldPt.z - world.translate.z) * world.rotate[0][2])
			) - viewFrustum._near;

			result.z = worldDiffRotated * (1.0f / (viewFrustum._far - viewFrustum._near));

			float trace = (worldPt.x * worldToCam[3][0]) + (worldPt.y * worldToCam[3][1]) + ((worldPt.z * worldToCam[3][2]) + worldToCam[3][3]);
			if (trace <= 0.00001f) {
				return result;
			}

			float traceInv = 1.0f / trace;
			result.x = (((worldPt.y * worldToCam[0][1]) + (worldPt.x * worldToCam[0][0])) + ((worldPt.z * worldToCam[0][2]) + worldToCam[0][3])) * traceInv;
			result.y = (((worldPt.y * worldToCam[1][1]) + (worldPt.x * worldToCam[1][0])) + ((worldPt.z * worldToCam[1][2]) + worldToCam[1][3])) * traceInv;
			return result;
		}

		//Same as WorldToScreen, but normalizes X and Y to the 0 to 1 range,
		//and flips the Y component so that 0 is top left and 1 is bottom right.
		NiPoint3 WorldToScreenNormalized(const NiPoint3& worldPt)
		{
			auto result = WorldToScreen(worldPt);
			result.x = (result.x + 1.0f) * 0.5f;
			result.y = -result.y;
			result.y = (result.y + 1.0f) * 0.5f;
			return result;
		}

		float         unk[20];
		float         worldToCam[4][4];
		NiFrustum     viewFrustum;
		float         minNearPlaneDist;
		float         maxFarNearRatio;
		NiRect<float> port;
		float         lodAdjust;
		float         unk2[24];
	};
	static_assert(offsetof(NiCamera, NiCamera::worldToCam) == 384);
}
