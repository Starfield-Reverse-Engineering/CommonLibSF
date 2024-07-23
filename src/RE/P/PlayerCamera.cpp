#include "RE/P/PlayerCamera.h"

namespace RE
{
	PlayerCamera* PlayerCamera::GetSingleton()
	{
		REL::Relocation<PlayerCamera**> singleton{ ID::PlayerCamera::singleton };
		return *singleton;
	}

	void PlayerCamera::ForceFirstPerson()
	{
		using func_t = decltype(&PlayerCamera::ForceFirstPerson);
		REL::Relocation<func_t> func{ ID::PlayerCamera::ForceFirstPerson };
		return func(this);
	}

	void PlayerCamera::ForceThirdPerson()
	{
		using func_t = decltype(&PlayerCamera::ForceThirdPerson);
		REL::Relocation<func_t> func{ ID::PlayerCamera::ForceThirdPerson };
		return func(this);
	}

	bool PlayerCamera::IsInFirstPerson() const
	{
		return QCameraEquals(CameraState::kFirstPerson);
	}

	bool PlayerCamera::IsInThirdPerson() const
	{
		return QCameraEquals(CameraState::kThirdPerson);
	}

	void PlayerCamera::SetCameraState(CameraState a_cameraState)
	{
		using func_t = decltype(&PlayerCamera::SetCameraState);
		REL::Relocation<func_t> func{ ID::PlayerCamera::SetCameraState };
		return func(this, a_cameraState);
	}

	bool PlayerCamera::QCameraEquals(CameraState a_cameraState) const
	{
		using func_t = decltype(&PlayerCamera::QCameraEquals);
		REL::Relocation<func_t> func{ ID::PlayerCamera::QCameraEquals };
		return func(this, a_cameraState);
	}
}
