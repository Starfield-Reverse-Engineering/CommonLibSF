#pragma once

#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSTEvent.h"
#include "RE/T/TESCamera.h"

namespace RE
{
	class BSWorldOriginShiftEvent;
	class OtherEventEnabledEvent;
	class UserEventEnabledEvent;
	struct IdleInputEvent;

	namespace Spaceship
	{
		struct TakeOffEvent;
		struct DockEvent;
		struct LandedSetEvent;
	}

	struct CameraStates
	{
		enum CameraState : std::uint32_t
		{
			kFirstPerson = 0,
			kAutoVanity,
			kVATS,
			kIronSights,
			kPCTransition,
			kTween,
			kUnk06,
			kFlightCamera,
			kShipFarTravel,
			kShipAction,
			kShipTargeting,
			kShipCombatOrbit,
			kFreeWalk,
			kFreeAdvanced,
			kFreeFly,
			kFreeTethered,
			kDialogue,
			kWorkshopIsometric,
			kPhotoMode,
			kThirdPerson,
			kFurniture,
			kHorse,
			kBleedout
		};
	};
	using CameraState = CameraStates::CameraState;

	class PlayerCamera :
		public TESCamera,                                // 00
		public BSInputEventReceiver,                     // 48
		public BSTEventSink<IdleInputEvent>,             // 58
		public BSTEventSink<UserEventEnabledEvent>,      // 60
		public BSTEventSink<OtherEventEnabledEvent>,     // 68
		public BSTEventSink<Spaceship::TakeOffEvent>,    // 70
		public BSTEventSink<Spaceship::DockEvent>,       // 78
		public BSTEventSink<Spaceship::LandedSetEvent>,  // 80
		public BSTEventSink<BSWorldOriginShiftEvent>     // 88
	{
	public:
		SF_RTTI_VTABLE(PlayerCamera);

		~PlayerCamera() override;  // 00

		// override (TESCamera)
		void SetCameraRoot(NiNode* a_root) override;  // 01
		void SetEnabled(bool a_enabled) override;     // 02
		void Unk_04() override;                       // 04

		static PlayerCamera* GetSingleton();

		void ForceFirstPerson();
		void ForceThirdPerson();
		bool IsInFirstPerson() const;
		bool IsInThirdPerson() const;
		void SetCameraState(CameraState a_cameraState);

		// More...

	private:
		bool QCameraEquals(CameraState a_cameraState) const;
	};
}
