#include "RE/P/PlayerCharacter.h"
#include "RE/Offsets.h"

namespace RE
{
	PlayerCharacter* PlayerCharacter::GetSingleton()
	{
		static REL::Relocation<PlayerCharacter**> singleton{ Offset::PlayerCharacter::singleton };
		return *singleton;
	}

	bool PlayerCharacter::IsInChargen()
	{
		return *(stl::adjust_pointer<bool>(this, 0xF24));
	}
}
