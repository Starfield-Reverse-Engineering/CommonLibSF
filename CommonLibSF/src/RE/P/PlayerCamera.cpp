#include "RE/P/PlayerCamera.h"

namespace RE
{
	PlayerCamera* PlayerCamera::GetSingleton()
	{
		REL::Relocation<PlayerCamera**> singleton{ REL::ID(878523) };
		return *singleton;
	}

	void PlayerCamera::ForceFirstPerson()
	{
		using func_t = decltype(&PlayerCamera::ForceFirstPerson);
		REL::Relocation<func_t> func{ REL::ID(166029) };
		return func(this);
	}

	void PlayerCamera::ForceThirdPerson()
	{
		using func_t = decltype(&PlayerCamera::ForceThirdPerson);
		REL::Relocation<func_t> func{ REL::ID(166031) };
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
		REL::Relocation<func_t> func{ REL::ID(166078) };
		return func(this, a_cameraState);
	}

	bool PlayerCamera::QCameraEquals(CameraState a_cameraState) const
	{
		using func_t = decltype(&PlayerCamera::QCameraEquals);
		REL::Relocation<func_t> func{ REL::ID(166081) };
		return func(this, a_cameraState);
	}
}
