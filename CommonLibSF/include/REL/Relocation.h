#pragma once

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_nopropQual, a_propQual, ...)              \
	template <class R, class Cls, class... Args>                                                  \
	struct member_function_pod_type<R (Cls::*)(Args...) __VA_ARGS__ a_nopropQual a_propQual>      \
	{                                                                                             \
		using type = R(__VA_ARGS__ Cls*, Args...) a_propQual;                                     \
	};                                                                                            \
                                                                                                  \
	template <class R, class Cls, class... Args>                                                  \
	struct member_function_pod_type<R (Cls::*)(Args..., ...) __VA_ARGS__ a_nopropQual a_propQual> \
	{                                                                                             \
		using type = R(__VA_ARGS__ Cls*, Args..., ...) a_propQual;                                \
	};

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(a_qualifer, ...)              \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_qualifer, , ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER_IMPL(a_qualifer, noexcept, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_POD_TYPE(...)                 \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(, __VA_ARGS__)    \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(&, ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_POD_TYPE_HELPER(&&, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_nopropQual, a_propQual, ...)              \
	template <class R, class Cls, class... Args>                                                      \
	struct member_function_non_pod_type<R (Cls::*)(Args...) __VA_ARGS__ a_nopropQual a_propQual>      \
	{                                                                                                 \
		using type = R&(__VA_ARGS__ Cls*, void*, Args...)a_propQual;                                  \
	};                                                                                                \
                                                                                                      \
	template <class R, class Cls, class... Args>                                                      \
	struct member_function_non_pod_type<R (Cls::*)(Args..., ...) __VA_ARGS__ a_nopropQual a_propQual> \
	{                                                                                                 \
		using type = R&(__VA_ARGS__ Cls*, void*, Args..., ...)a_propQual;                             \
	};

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(a_qualifer, ...)              \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_qualifer, , ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER_IMPL(a_qualifer, noexcept, ##__VA_ARGS__)

#define REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(...)                 \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(, __VA_ARGS__)    \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(&, ##__VA_ARGS__) \
	REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE_HELPER(&&, ##__VA_ARGS__)

#define SF_RTTI(TYPE) \
	inline static constexpr auto RTTI = RTTI::TYPE
#define SF_VTABLE(VTBL) \
	inline static constexpr auto VTABLE = VTABLE::VTBL
#define SF_RTTI_VTABLE(ENTRY) \
	SF_RTTI(ENTRY);           \
	SF_VTABLE(ENTRY)

namespace REL
{
	namespace detail
	{
		template <class>
		struct member_function_pod_type;

		REL_MAKE_MEMBER_FUNCTION_POD_TYPE();
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(const);
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(volatile);
		REL_MAKE_MEMBER_FUNCTION_POD_TYPE(const volatile);

		template <class F>
		using member_function_pod_type_t = typename member_function_pod_type<F>::type;

		template <class>
		struct member_function_non_pod_type;

		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE();
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(const);
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(volatile);
		REL_MAKE_MEMBER_FUNCTION_NON_POD_TYPE(const volatile);

		template <class F>
		using member_function_non_pod_type_t = typename member_function_non_pod_type<F>::type;

		// https://docs.microsoft.com/en-us/cpp/build/x64-calling-convention

		template <class T>
		struct meets_length_req : std::disjunction<std::bool_constant<sizeof(T) == 1>, std::bool_constant<sizeof(T) == 2>, std::bool_constant<sizeof(T) == 4>, std::bool_constant<sizeof(T) == 8>>
		{};

		template <class T>
		struct meets_function_req : std::conjunction<std::is_trivially_constructible<T>, std::is_trivially_destructible<T>, std::is_trivially_copy_assignable<T>, std::negation<std::is_polymorphic<T>>>
		{};

		template <class T>
		struct meets_member_req : std::is_standard_layout<T>
		{};

		template <class T, class = void>
		struct is_x64_pod : std::true_type
		{};

		template <class T>
		struct is_x64_pod<T, std::enable_if_t<std::is_union_v<T>>> : std::false_type
		{};

		template <class T>
		struct is_x64_pod<T, std::enable_if_t<std::is_class_v<T>>> : std::conjunction<meets_length_req<T>, meets_function_req<T>, meets_member_req<T>>
		{};

		template <class T>
		static constexpr bool is_x64_pod_v = is_x64_pod<T>::value;

		template <class F, class First, class... Rest>
		decltype(auto) invoke_member_function_non_pod(F&& a_func, First&& a_first, Rest&&... a_rest)  //
			noexcept(std::is_nothrow_invocable_v<F, First, Rest...>)
		{
			using result_t = std::invoke_result_t<F, First, Rest...>;
			alignas(result_t) std::byte result[sizeof(result_t)]{};

			using func_t = member_function_non_pod_type_t<F>;
			auto func = std::bit_cast<func_t*>(std::forward<F>(a_func));

			return func(std::forward<First>(a_first), std::addressof(result), std::forward<Rest>(a_rest)...);
		}
	}  // namespace detail

	inline constexpr std::uint8_t NOP = 0x90;
	inline constexpr std::uint8_t NOP2[] = { 0x66, 0x90 };
	inline constexpr std::uint8_t NOP3[] = { 0x0F, 0x1F, 0x00 };
	inline constexpr std::uint8_t NOP4[] = { 0x0F, 0x1F, 0x40, 0x00 };
	inline constexpr std::uint8_t NOP5[] = { 0x0F, 0x1F, 0x44, 0x00, 0x00 };
	inline constexpr std::uint8_t NOP6[] = { 0x66, 0x0F, 0x1F, 0x44, 0x00, 0x00 };
	inline constexpr std::uint8_t NOP7[] = { 0x0F, 0x1F, 0x80, 0x00, 0x00, 0x00, 0x00 };
	inline constexpr std::uint8_t NOP8[] = { 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };
	inline constexpr std::uint8_t NOP9[] = { 0x66, 0x0F, 0x1F, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00 };

	inline constexpr std::uint8_t JMP8 = 0xEB;
	inline constexpr std::uint8_t JMP32 = 0xE9;
	inline constexpr std::uint8_t RET = 0xC3;
	inline constexpr std::uint8_t INT3 = 0xCC;

	template <class F, class... Args>
	std::invoke_result_t<F, Args...> invoke(F&& a_func, Args&&... a_args)  //
		noexcept(std::is_nothrow_invocable_v<F, Args...>)                  //
		requires(std::invocable<F, Args...>)
	{
		if constexpr (std::is_member_function_pointer_v<std::decay_t<F>>) {
			if constexpr (detail::is_x64_pod_v<std::invoke_result_t<F, Args...>>) {  // member functions == free functions in x64
				using func_t = detail::member_function_pod_type_t<std::decay_t<F>>;
				auto func = stl::unrestricted_cast<func_t*>(std::forward<F>(a_func));
				return func(std::forward<Args>(a_args)...);
			} else {  // shift args to insert result
				return detail::invoke_member_function_non_pod(std::forward<F>(a_func), std::forward<Args>(a_args)...);
			}
		} else {
			return std::forward<F>(a_func)(std::forward<Args>(a_args)...);
		}
	}

	inline void safe_write(std::uintptr_t a_dst, const void* a_src, std::size_t a_count)
	{
		std::uint32_t old{ 0 };
		auto          success = WinAPI::VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, WinAPI::PAGE_EXECUTE_READWRITE, std::addressof(old));
		if (success != 0) {
			std::memcpy(reinterpret_cast<void*>(a_dst), a_src, a_count);
			success = WinAPI::VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, old, std::addressof(old));
		}

		assert(success != 0);
	}

	template <std::integral T>
	void safe_write(std::uintptr_t a_dst, const T& a_data)
	{
		safe_write(a_dst, std::addressof(a_data), sizeof(T));
	}

	template <class T>
	void safe_write(std::uintptr_t a_dst, std::span<T> a_data)
	{
		safe_write(a_dst, a_data.data(), a_data.size_bytes());
	}

	inline void safe_fill(std::uintptr_t a_dst, std::uint8_t a_value, std::size_t a_count)
	{
		std::uint32_t old{ 0 };
		auto          success = WinAPI::VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, WinAPI::PAGE_EXECUTE_READWRITE, std::addressof(old));
		if (success != 0) {
			std::fill_n(reinterpret_cast<std::uint8_t*>(a_dst), a_count, a_value);
			success = WinAPI::VirtualProtect(reinterpret_cast<void*>(a_dst), a_count, old, std::addressof(old));
		}

		assert(success != 0);
	};

	class Version
	{
	public:
		using value_type = std::uint16_t;
		using reference = value_type&;
		using const_reference = const value_type&;

		constexpr Version() noexcept = default;

		explicit constexpr Version(std::array<value_type, 4> a_version) noexcept :
			_impl(a_version) {}

		constexpr Version(value_type a_v1, value_type a_v2 = 0, value_type a_v3 = 0, value_type a_v4 = 0) noexcept :
			_impl{ a_v1, a_v2, a_v3, a_v4 } {}

		explicit constexpr Version(std::string_view a_version)
		{
			std::array<value_type, 4> powers{ 1, 1, 1, 1 };
			std::size_t               position = 0;
			for (std::size_t i = 0; i < a_version.size(); ++i) {
				if (a_version[i] == '.') {
					if (++position == powers.size()) {
						throw std::invalid_argument("Too many parts in version number.");
					}
				} else {
					powers[position] *= 10;
				}
			}
			position = 0;
			for (std::size_t i = 0; i < a_version.size(); ++i) {
				if (a_version[i] == '.') {
					++position;
				} else if (a_version[i] < '0' || a_version[i] > '9') {
					throw std::invalid_argument("Invalid character in version number.");
				} else {
					powers[position] /= 10;
					_impl[position] += static_cast<value_type>((a_version[i] - '0') * powers[position]);
				}
			}
		}

		[[nodiscard]] constexpr reference operator[](std::size_t a_idx) noexcept { return _impl[a_idx]; }

		[[nodiscard]] constexpr const_reference operator[](std::size_t a_idx) const noexcept { return _impl[a_idx]; }

		[[nodiscard]] constexpr decltype(auto) begin() const noexcept { return _impl.begin(); }

		[[nodiscard]] constexpr decltype(auto) cbegin() const noexcept { return _impl.cbegin(); }

		[[nodiscard]] constexpr decltype(auto) end() const noexcept { return _impl.end(); }

		[[nodiscard]] constexpr decltype(auto) cend() const noexcept { return _impl.cend(); }

		[[nodiscard]] std::strong_ordering constexpr compare(const Version& a_rhs) const noexcept
		{
			for (std::size_t i = 0; i < _impl.size(); ++i) {
				if ((*this)[i] != a_rhs[i]) {
					return (*this)[i] < a_rhs[i] ? std::strong_ordering::less : std::strong_ordering::greater;
				}
			}
			return std::strong_ordering::equal;
		}

		[[nodiscard]] constexpr std::uint32_t pack() const noexcept { return static_cast<std::uint32_t>((_impl[0] & 0x0FF) << 24u | (_impl[1] & 0x0FF) << 16u | (_impl[2] & 0xFFF) << 4u | (_impl[3] & 0x00F) << 0u); }

		[[nodiscard]] constexpr value_type major() const noexcept { return _impl[0]; }

		[[nodiscard]] constexpr value_type minor() const noexcept { return _impl[1]; }

		[[nodiscard]] constexpr value_type patch() const noexcept { return _impl[2]; }

		[[nodiscard]] constexpr value_type build() const noexcept { return _impl[3]; }

		[[nodiscard]] std::string string(std::string_view a_separator = "-"sv) const
		{
			std::string result;
			for (auto&& ver : _impl) {
				result += std::to_string(ver);
				result.append(a_separator.data(), a_separator.size());
			}
			result.erase(result.size() - a_separator.size(), a_separator.size());
			return result;
		}

		[[nodiscard]] std::wstring wstring(std::wstring_view a_separator = L"-"sv) const
		{
			std::wstring result;
			for (auto&& ver : _impl) {
				result += std::to_wstring(ver);
				result.append(a_separator.data(), a_separator.size());
			}
			result.erase(result.size() - a_separator.size(), a_separator.size());
			return result;
		}

		[[nodiscard]] static constexpr Version unpack(std::uint32_t a_packedVersion) noexcept { return REL::Version{ static_cast<value_type>((a_packedVersion >> 24) & 0x0FF), static_cast<value_type>((a_packedVersion >> 16) & 0x0FF), static_cast<value_type>((a_packedVersion >> 4) & 0xFFF), static_cast<value_type>(a_packedVersion & 0x0F) }; }

	private:
		std::array<value_type, 4> _impl{ 0, 0, 0, 0 };
	};

	[[nodiscard]] constexpr bool operator==(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs) == std::strong_ordering::equal; }

	[[nodiscard]] constexpr std::strong_ordering operator<=>(const Version& a_lhs, const Version& a_rhs) noexcept { return a_lhs.compare(a_rhs); }

	namespace literals
	{
		namespace detail
		{
			template <std::size_t Index, char C>
			constexpr uint8_t read_version(std::array<typename REL::Version::value_type, 4>& result)
			{
				static_assert(C >= '0' && C <= '9', "Invalid character in semantic version literal.");
				static_assert(Index < 4, "Too many components in semantic version literal.");
				result[Index] += (C - '0');
				return 10;
			}

			template <std::size_t Index, char C, char... Rest>
				requires(sizeof...(Rest) > 0)
			constexpr uint8_t read_version(std::array<typename REL::Version::value_type, 4>& result)
			{
				static_assert(C == '.' || (C >= '0' && C <= '9'), "Invalid character in semantic version literal.");
				static_assert(Index < 4, "Too many components in semantic version literal.");
				if constexpr (C == '.') {
					read_version<Index + 1, Rest...>(result);
					return 1;
				} else {
					auto position = read_version<Index, Rest...>(result);
					result[Index] += (C - '0') * position;
					return position * 10;
				}
			}
		}  // namespace detail

		template <char... C>
		[[nodiscard]] constexpr REL::Version operator""_v() noexcept
		{
			std::array<typename REL::Version::value_type, 4> result{ 0, 0, 0, 0 };
			detail::read_version<0, C...>(result);
			return REL::Version(result);
		}

		[[nodiscard]] constexpr REL::Version operator""_v(const char* str, std::size_t len) { return Version(std::string_view(str, len)); }
	}  // namespace literals

	[[nodiscard]] inline std::optional<Version> get_file_version(stl::zwstring a_filename)
	{
		std::uint32_t     dummy{ 0 };
		std::vector<char> buf(WinAPI::GetFileVersionInfoSize(a_filename.data(), std::addressof(dummy)));
		if (buf.empty()) {
			return std::nullopt;
		}

		if (!WinAPI::GetFileVersionInfo(a_filename.data(), 0, static_cast<std::uint32_t>(buf.size()), buf.data())) {
			return std::nullopt;
		}

		void*         verBuf{ nullptr };
		std::uint32_t verLen{ 0 };
		if (!WinAPI::VerQueryValue(buf.data(), L"\\StringFileInfo\\040904B0\\ProductVersion", std::addressof(verBuf), std::addressof(verLen))) {
			return std::nullopt;
		}

		Version             version;
		std::wistringstream ss(std::wstring(static_cast<const wchar_t*>(verBuf), verLen));
		std::wstring        token;
		for (std::size_t i = 0; i < 4 && std::getline(ss, token, L'.'); ++i) {
			version[i] = static_cast<std::uint16_t>(std::stoi(token));
		}

		return version;
	}

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

		Segment() noexcept = default;

		Segment(std::uintptr_t a_proxyBase, std::uintptr_t a_address, std::uintptr_t a_size) noexcept :
			_proxyBase(a_proxyBase), _address(a_address), _size(a_size) {}

		[[nodiscard]] std::uintptr_t address() const noexcept { return _address; }

		[[nodiscard]] std::size_t offset() const noexcept { return address() - _proxyBase; }

		[[nodiscard]] std::size_t size() const noexcept { return _size; }

		[[nodiscard]] void* pointer() const noexcept { return reinterpret_cast<void*>(address()); }

		template <class T>
		[[nodiscard]] T* pointer() const noexcept
		{
			return static_cast<T*>(pointer());
		}

	private:
		friend class Module;

		std::uintptr_t _proxyBase{ 0 };
		std::uintptr_t _address{ 0 };
		std::size_t    _size{ 0 };
	};

	class Module
	{
	public:
		constexpr Module() = delete;
		explicit Module(std::uintptr_t a_base);
		explicit Module(std::string_view a_filePath);

		[[nodiscard]] constexpr auto base() const noexcept { return _base; }

		template <typename T = void>
		[[nodiscard]] constexpr auto* pointer() const noexcept
		{
			return std::bit_cast<T*>(base());
		}

		[[nodiscard]] constexpr auto segment(Segment::Name a_segment) noexcept { return _segments[a_segment]; }

		[[nodiscard]] static Module& get(const std::uintptr_t a_address) noexcept
		{
			static std::unordered_map<std::uintptr_t, Module> managed;

			const auto base = AsAddress(a_address) & ~3;
			if (!managed.contains(base)) {
				managed.try_emplace(base, base);
			}

			return managed.at(base);
		}

		[[nodiscard]] static Module& get(std::string_view a_filePath = {}) noexcept
		{
			const auto base = AsAddress(WinAPI::GetModuleHandle(a_filePath.empty() ? WinAPI::GetProcPath(nullptr).data() : a_filePath.data()));
			return get(base);
		}

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
	};

	class Offset
	{
	public:
		constexpr Offset() = default;

		constexpr Offset(std::ptrdiff_t a_offset) :
			_offset(a_offset) {}

		[[nodiscard]] constexpr std::uintptr_t offset() const noexcept { return _offset; }

		[[nodiscard]] constexpr std::uintptr_t address() const noexcept { return Module::get().base() + _offset; }

	private:
		std::ptrdiff_t _offset{ 0 };
	};

	template <typename T = std::uintptr_t>
	class Relocation
	{
	public:
		using value_type = std::conditional_t<std::is_member_pointer_v<T> || std::is_function_v<std::remove_pointer_t<T>>, std::decay_t<T>, T>;

		constexpr Relocation() noexcept = default;

		constexpr Relocation(const std::uintptr_t a_addr) noexcept :
			_address(a_addr) {}

		constexpr Relocation(Offset a_rva) noexcept :
			_address(a_rva.address()) {}

		constexpr Relocation(Offset a_rva, std::ptrdiff_t a_offset) noexcept :
			_address(a_rva.address() + a_offset) {}

		[[nodiscard]] constexpr value_type get() const  //
			noexcept(std::is_nothrow_copy_constructible_v<value_type>)
		{
			return stl::unrestricted_cast<value_type>(_address);
		}

		[[nodiscard]] constexpr decltype(auto) address() const noexcept { return _address; }

		[[nodiscard]] std::size_t offset() const noexcept { return _address - base(); }

		[[nodiscard]] constexpr decltype(auto) operator*() const noexcept
			requires(std::is_pointer_v<value_type>)
		{
			return *get();
		}

		[[nodiscard]] constexpr auto operator->() const noexcept  //
			requires(std::is_pointer_v<value_type>)
		{
			return get();
		}

		template <class... Args>
		std::invoke_result_t<const value_type&, Args...> operator()(Args&&... a_args) const  //
			noexcept(std::is_nothrow_invocable_v<const value_type&, Args...>)                //
			requires(std::invocable<const value_type&, Args...>)
		{
			return invoke(get(), std::forward<Args>(a_args)...);
		}

		std::uintptr_t write_vfunc(std::size_t a_idx, std::uintptr_t a_newFunc)  //
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			const auto addr = address() + (sizeof(void*) * a_idx);
			const auto result = *std::bit_cast<std::uintptr_t*>(addr);
			safe_write(addr, a_newFunc);
			return result;
		}

		template <class F>
		std::uintptr_t write_vfunc(std::size_t a_idx, F a_newFunc)  //
			requires(std::same_as<value_type, std::uintptr_t>)
		{
			return write_vfunc(a_idx, stl::unrestricted_cast<std::uintptr_t>(a_newFunc));
		}

	private:
		[[nodiscard]] static std::uintptr_t base() { return Module::get().base(); }

		std::uintptr_t _address{ 0 };
	};
}  // namespace REL
