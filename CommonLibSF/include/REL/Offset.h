#pragma once

#include "REL/Module.h"

namespace REL
{
	class Offset
	{
	public:
		constexpr Offset() = default;

		constexpr Offset(const std::ptrdiff_t a_offset) :
			_offset(a_offset)
		{}

		[[nodiscard]] constexpr std::uintptr_t offset() const noexcept
		{
			return _offset;
		}

		[[nodiscard]] constexpr std::uintptr_t address() const noexcept
		{
			return Module::get().base() + _offset;
		}

	private:
		std::ptrdiff_t _offset{};
	};
}
