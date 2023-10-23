#pragma once

namespace SFSE
{
	[[nodiscard]] std::uintptr_t GetIATAddr(std::string_view a_dll, std::string_view a_function);

	[[nodiscard]] std::uintptr_t GetIATAddr(void* a_module, std::string_view a_dll, std::string_view a_function);

	[[nodiscard]] constexpr void* GetIATPtr(std::string_view a_dll, std::string_view a_function);

	template <class T>
	[[nodiscard]] constexpr T* GetIATPtr(const std::string_view a_dll, const std::string_view a_function)
	{
		return static_cast<T*>(GetIATPtr(a_dll, a_function));
	}

	[[nodiscard]] constexpr void* GetIATPtr(void* a_module, std::string_view a_dll, std::string_view a_function);

	template <class T>
	[[nodiscard]] T* GetIATPtr(void* a_module, const std::string_view a_dll, const std::string_view a_function)
	{
		return static_cast<T*>(GetIATPtr(a_module, a_dll, a_function));
	}

	std::uintptr_t PatchIAT(std::uintptr_t a_newFunc, std::string_view a_dll, std::string_view a_function);

	template <class F>
	constexpr std::uintptr_t PatchIAT(F a_newFunc, const std::string_view a_dll, const std::string_view a_function)
	{
		return PatchIAT(stl::unrestricted_cast<std::uintptr_t>(a_newFunc), a_dll, a_function);
	}
}
