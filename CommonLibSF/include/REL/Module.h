#pragma once

#include "REL/Version.h"

namespace REL
{
	class Segment
	{
	public:
		enum Name : std::size_t
		{
			textx,
			idata,
			rdata,
			data,
			pdata,
			tls,
			textw,
			gfids,
			total
		};

		constexpr Segment() noexcept = default;

		constexpr Segment(const std::uintptr_t a_proxyBase, const std::uintptr_t a_address, const std::uintptr_t a_size) noexcept :
			_proxyBase(a_proxyBase), _address(a_address), _size(a_size)
		{}

		[[nodiscard]] constexpr std::uintptr_t address() const noexcept { return _address; }
		[[nodiscard]] constexpr std::size_t    offset() const noexcept { return address() - _proxyBase; }
		[[nodiscard]] constexpr std::size_t    size() const noexcept { return _size; }

		[[nodiscard]] constexpr void* pointer() const noexcept
		{
			return std::bit_cast<void*>(address());
		}

		template <class T>
		[[nodiscard]] constexpr T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

	private:
		friend class Module;

		std::uintptr_t _proxyBase{};
		std::uintptr_t _address{};
		std::size_t    _size{};
	};

	class Module
	{
	public:
		constexpr Module() = delete;
		explicit Module(std::uintptr_t a_base);
		explicit constexpr Module(std::string_view a_filePath);

		[[nodiscard]] constexpr auto base() const noexcept { return _base; }

		template <typename T = void>
		[[nodiscard]] constexpr auto pointer() const noexcept
		{
			return std::bit_cast<T*>(base());
		}

		[[nodiscard]] constexpr auto segment(const Segment::Name a_segment) const noexcept { return _segments[a_segment]; }

		[[nodiscard]] constexpr auto version() const noexcept { return _version; }

		[[nodiscard]] static Module& get(std::uintptr_t a_address) noexcept;

		[[nodiscard]] static Module& get(std::string_view a_filePath = {}) noexcept;

	private:
		static constexpr std::array SEGMENTS{
			std::make_pair(".text"sv, WinAPI::IMAGE_SCN_MEM_EXECUTE),
			std::make_pair(".idata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".rdata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".data"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".pdata"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".tls"sv, static_cast<std::uint32_t>(0)),
			std::make_pair(".text"sv, WinAPI::IMAGE_SCN_MEM_WRITE),
			std::make_pair(".gfids"sv, static_cast<std::uint32_t>(0))
		};

		std::uintptr_t                      _base;
		std::array<Segment, Segment::total> _segments;
		Version                             _version;
		std::wstring                        _file;
	};
}
