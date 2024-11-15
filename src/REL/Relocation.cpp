#include "REL/Relocation.h"

#ifdef SFSE_SUPPORT_XBYAK
#	include <xbyak/xbyak.h>

namespace REL
{
	struct write_func_impl : Xbyak::CodeGenerator
	{
		write_func_impl(std::uintptr_t a_dst)
		{
			Xbyak::Label dst;
			jmp(ptr[rip + dst]);
			L(dst);
			dq(a_dst);
		}
	};

	template <class T>
	void Relocation<T>::write_func(const std::size_t a_count, const std::uintptr_t a_dst)
		requires(std::same_as<value_type, std::uintptr_t>)
	{
		safe_fill(address(), INT3, a_count);
		auto patch = write_func_impl{ a_dst };
		patch.ready();
		assert(patch.getSize() <= a_count);
		safe_write(address(), std::span{ patch.getCode<const std::byte*>(), patch.getSize() });
	}

	template void Relocation<std::uintptr_t>::write_func(const std::size_t, const std::uintptr_t);
}
#endif
