#pragma once

/* +++++++++++++++++++++++++ C++23 Standard Library +++++++++++++++++++++++++ */
#include <algorithm>
#include <any>
#include <array>
#include <atomic>
#include <barrier>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <charconv>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <clocale>
#include <cmath>
#include <compare>
#include <complex>
#include <concepts>
#include <condition_variable>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cuchar>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <execution>
#include <expected>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <latch>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <memory_resource>
#include <mutex>
#include <new>
#include <numbers>
#include <numeric>
#include <optional>
#include <ostream>
#include <print>
#include <queue>
#include <random>
#include <ranges>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <semaphore>
#include <set>
#include <shared_mutex>
#include <source_location>
#include <span>
#include <spanstream>
#include <sstream>
#include <stack>
#include <stacktrace>
#include <stdexcept>
#include <stdfloat>
#include <stop_token>
#include <streambuf>
#include <string>
#include <string_view>
#include <strstream>
#include <syncstream>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>
#include <version>

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */

static_assert(std::is_integral_v<std::time_t> && sizeof(std::time_t) == sizeof(std::size_t), "wrap std::time_t instead");

#include "REX/REX/Enum.h"
#include "REX/REX/EnumSet.h"
#include "REX/W32/KERNEL32.h"
#include "REX/W32/USER32.h"

#pragma warning(push)
#include <spdlog/spdlog.h>
#pragma warning(pop)

#define AsAddress(ptr) std::bit_cast<std::uintptr_t>(ptr)
#define AsPointer(addr) std::bit_cast<void*>(addr)
#define stl_assert(cond, ...)                                     \
	{                                                             \
		if (!((cond))) {                                          \
			SFSE::stl::report_and_fail(std::format(__VA_ARGS__)); \
		}                                                         \
	}

namespace SFSE
{
	using namespace std::literals;

	namespace stl
	{
		template <class CharT>
		using basic_zstring = std::basic_string_view<CharT>;

		using zstring = basic_zstring<char>;
		using zwstring = basic_zstring<wchar_t>;

		// owning pointer
		template <class T, class = std::enable_if_t<std::is_pointer_v<T>>>
		using owner = T;

		// non-owning pointer
		template <class T, class = std::enable_if_t<std::is_pointer_v<T>>>
		using observer = T;

		// non-null pointer
		template <class T, class = std::enable_if_t<std::is_pointer_v<T>>>
		using not_null = T;

		namespace nttp
		{
			template <class CharT, std::size_t N>
			struct string
			{
				using char_type = CharT;
				using pointer = char_type*;
				using const_pointer = const char_type*;
				using reference = char_type&;
				using const_reference = const char_type&;
				using size_type = std::size_t;

				static constexpr auto npos = static_cast<std::size_t>(-1);

				consteval string(const_pointer a_string) noexcept
				{
					for (size_type i = 0; i < N; ++i) {
						c[i] = a_string[i];
					}
				}

				[[nodiscard]] consteval const_reference operator[](size_type a_pos) const noexcept
				{
					assert(a_pos < N);
					return c[a_pos];
				}

				[[nodiscard]] consteval char_type value_at(size_type a_pos) const noexcept
				{
					assert(a_pos < N);
					return c[a_pos];
				}

				[[nodiscard]] consteval const_reference back() const noexcept { return (*this)[size() - 1]; }

				[[nodiscard]] consteval const_pointer data() const noexcept { return c; }

				[[nodiscard]] consteval bool empty() const noexcept { return this->size() == 0; }

				[[nodiscard]] consteval const_reference front() const noexcept { return (*this)[0]; }

				[[nodiscard]] static consteval size_type length() noexcept { return N; }

				[[nodiscard]] static consteval size_type size() noexcept { return length(); }

				template <std::size_t POS = 0, std::size_t COUNT = npos>
				[[nodiscard]] consteval auto substr() const noexcept
				{
					return string < CharT, COUNT != npos ? COUNT : N - POS > (this->data() + POS);
				}

				char_type c[N] = {};
			};

			template <class CharT, std::size_t N>
			string(const CharT (&)[N]) -> string<CharT, N - 1>;
		}

		// backwards compat
		template <
			class E,
			class U = std::underlying_type_t<E>>
		class enumeration : public REX::EnumSet<E, U>
		{
			using super = REX::EnumSet<E, U>;

		public:
			using enum_type = E;
			using underlying_type = U;

			using super::super;
			using super::operator=;
			using super::operator*;
		};

		template <class... Args>
		enumeration(Args...) -> enumeration<
								 std::common_type_t<Args...>,
								 std::underlying_type_t<
									 std::common_type_t<Args...>>>;
	}
}

namespace SFSE::stl
{
	template <class T>
	class atomic_ref : public std::atomic_ref<T>
	{
	private:
		using super = std::atomic_ref<T>;

	public:
		using value_type = typename super::value_type;

		explicit atomic_ref(volatile T& a_obj) noexcept(std::is_nothrow_constructible_v<super, value_type&>) :
			super(const_cast<value_type&>(a_obj)) {}

		using super::super;
		using super::operator=;
	};

	template <class T>
	atomic_ref(volatile T&) -> atomic_ref<T>;

	template class atomic_ref<std::int8_t>;
	template class atomic_ref<std::uint8_t>;
	template class atomic_ref<std::int16_t>;
	template class atomic_ref<std::uint16_t>;
	template class atomic_ref<std::int32_t>;
	template class atomic_ref<std::uint32_t>;
	template class atomic_ref<std::int64_t>;
	template class atomic_ref<std::uint64_t>;

	static_assert(atomic_ref<std::int8_t>::is_always_lock_free);
	static_assert(atomic_ref<std::uint8_t>::is_always_lock_free);
	static_assert(atomic_ref<std::int16_t>::is_always_lock_free);
	static_assert(atomic_ref<std::uint16_t>::is_always_lock_free);
	static_assert(atomic_ref<std::int32_t>::is_always_lock_free);
	static_assert(atomic_ref<std::uint32_t>::is_always_lock_free);
	static_assert(atomic_ref<std::int64_t>::is_always_lock_free);
	static_assert(atomic_ref<std::uint64_t>::is_always_lock_free);

	template <class T>
	struct ssizeof
	{
		[[nodiscard]] constexpr operator std::ptrdiff_t() const noexcept { return value; }

		[[nodiscard]] constexpr std::ptrdiff_t operator()() const noexcept { return value; }

		static constexpr auto value = static_cast<std::ptrdiff_t>(sizeof(T));
	};

	template <class T>
	inline constexpr auto ssizeof_v = ssizeof<T>::value;

	template <class T, class U>
	[[nodiscard]] auto adjust_pointer(U* a_ptr, const std::ptrdiff_t a_adjust) noexcept
	{
		auto addr = a_ptr ? reinterpret_cast<std::uintptr_t>(a_ptr) + a_adjust : 0;
		if constexpr (std::is_const_v<U> && std::is_volatile_v<U>) {
			return reinterpret_cast<std::add_cv_t<T>*>(addr);
		} else if constexpr (std::is_const_v<U>) {
			return reinterpret_cast<std::add_const_t<T>*>(addr);
		} else if constexpr (std::is_volatile_v<U>) {
			return reinterpret_cast<std::add_volatile_t<T>*>(addr);
		} else {
			return reinterpret_cast<T*>(addr);
		}
	}

	template <class T>
	void memzero(volatile T* a_ptr, const std::size_t a_size = sizeof(T))
	{
		const auto     begin = reinterpret_cast<volatile char*>(a_ptr);
		constexpr char val{};
		std::fill_n(begin, a_size, val);
	}

	template <class... Args>
	[[nodiscard]] auto pun_bits(Args... a_args)
		requires(std::same_as<std::remove_cv_t<Args>, bool> && ...)
	{
		constexpr auto ARGC = sizeof...(Args);

		std::bitset<ARGC> bits;
		std::size_t       i = 0;
		((bits[i++] = a_args), ...);

		if constexpr (ARGC <= std::numeric_limits<unsigned long>::digits) {
			return bits.to_ulong();
		} else if constexpr (ARGC <= std::numeric_limits<unsigned long long>::digits) {
			return bits.to_ullong();
		} else {
			static_assert(false && sizeof...(Args));
		}
	}

	[[nodiscard]] inline auto utf8_to_utf16(const std::string_view a_in) noexcept -> std::optional<std::wstring>
	{
		const auto cvt = [&](wchar_t* a_dst, const std::size_t a_length) {
			return REX::W32::MultiByteToWideChar(
				REX::W32::CP_UTF8, 0, a_in.data(), static_cast<int>(a_in.length()), a_dst, static_cast<int>(a_length));
		};

		const auto len = cvt(nullptr, 0);
		if (len == 0) {
			return std::nullopt;
		}

		std::wstring out(len, '\0');
		if (cvt(out.data(), out.length()) == 0) {
			return std::nullopt;
		}

		return out;
	}

	[[nodiscard]] inline auto utf16_to_utf8(const std::wstring_view a_in) noexcept -> std::optional<std::string>
	{
		const auto cvt = [&](char* a_dst, const std::size_t a_length) {
			return REX::W32::WideCharToMultiByte(
				REX::W32::CP_UTF8, 0, a_in.data(), static_cast<int>(a_in.length()), a_dst, static_cast<int>(a_length), nullptr, nullptr);
		};

		const auto len = cvt(nullptr, 0);
		if (len == 0) {
			return std::nullopt;
		}

		std::string out(len, '\0');
		if (cvt(out.data(), out.length()) == 0) {
			return std::nullopt;
		}

		return out;
	}

	inline bool report_and_error(std::string_view a_msg, const bool a_fail = true, const std::source_location& a_loc = std::source_location::current())
	{
		const auto body = [&]() -> std::wstring {
			const std::filesystem::path p = a_loc.file_name();
			auto                        filename = p.lexically_normal().generic_string();

			const std::regex r{ R"((?:^|[\\\/])(?:include|src)[\\\/](.*)$)" };
			std::smatch      matches;
			if (std::regex_search(filename, matches, r)) {
				filename = matches[1].str();
			}

			return utf8_to_utf16(std::format("{}({}): {}"sv, filename, a_loc.line(), a_msg)).value_or(L"<character encoding error>"s);
		}();

		const auto caption = []() {
			std::vector<wchar_t> buf;
			buf.reserve(REX::W32::MAX_PATH);
			buf.resize(REX::W32::MAX_PATH / 2);
			std::uint32_t result;
			do {
				buf.resize(buf.size() * 2);
				result = REX::W32::GetModuleFileNameW(REX::W32::GetCurrentModule(), buf.data(), static_cast<std::uint32_t>(buf.size()));
			} while (result && result == buf.size() && buf.size() <= (std::numeric_limits<std::uint32_t>::max)());

			if (result && result != buf.size()) {
				const std::filesystem::path p(buf.begin(), buf.begin() + result);
				return p.filename().native();
			}
			return L""s;
		}();

		spdlog::log(spdlog::source_loc{ a_loc.file_name(), static_cast<int>(a_loc.line()), a_loc.function_name() }, spdlog::level::critical, a_msg);

		if (a_fail) {
			REX::W32::MessageBoxW(nullptr, body.c_str(), (caption.empty() ? nullptr : caption.c_str()), 0);
			REX::W32::TerminateProcess(REX::W32::GetCurrentProcess(), EXIT_FAILURE);
		}
		return true;
	}

	[[noreturn]] inline void report_and_fail(const std::string_view a_msg, const std::source_location& a_loc = std::source_location::current())
	{
		report_and_error(a_msg, true, a_loc);
		std::unreachable();
	}

	template <class To, class From>
	[[nodiscard]] To unrestricted_cast(From a_from) noexcept
	{
		if constexpr (std::is_same_v<std::remove_cv_t<From>, std::remove_cv_t<To>>) {
			return To{ a_from };

			// From != To
		} else if constexpr (std::is_reference_v<From>) {
			return stl::unrestricted_cast<To>(std::addressof(a_from));

			// From: NOT reference
		} else if constexpr (std::is_reference_v<To>) {
			return *stl::unrestricted_cast<std::add_pointer_t<std::remove_reference_t<To>>>(a_from);

			// To: NOT reference
		} else if constexpr (std::is_pointer_v<From> && std::is_pointer_v<To>) {
			return static_cast<To>(const_cast<void*>(static_cast<const volatile void*>(a_from)));
		} else if constexpr ((std::is_pointer_v<From> && std::is_integral_v<To>) || (std::is_integral_v<From> && std::is_pointer_v<To>)) {
			return reinterpret_cast<To>(a_from);
		} else {
			union
			{
				std::remove_cv_t<std::remove_reference_t<From>> from;
				std::remove_cv_t<std::remove_reference_t<To>>   to;
			};

			from = std::forward<From>(a_from);
			return to;
		}
	}
}

namespace RE
{
	using namespace std::literals;
	namespace stl = SFSE::stl;
}

namespace REL
{
	using namespace std::literals;
	namespace stl = SFSE::stl;
}

#include "REL/REL.h"

#include "RE/IDs.h"
#include "RE/IDs_NiRTTI.h"
#include "RE/IDs_RTTI.h"
#include "RE/IDs_VTABLE.h"

#include "RE/M/msvc.h"

#undef cdecl  // Workaround for Clang.
