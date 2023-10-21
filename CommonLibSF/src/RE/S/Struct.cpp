#include "RE/S/Struct.h"
#include "RE/V/Variable.h"

namespace RE::BSScript
{
	Struct::~Struct()
	{
		if (constructed) {
			const std::uint32_t size = type ? type->variables.size() : 0;
			for (std::uint32_t i = 0; i < size; ++i) {
				variables[i].reset();
			}

			constructed = false;
		}
	}
}