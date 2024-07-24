#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/IVirtualMachine.h"
#include "RE/V/VirtualMachine.h"
#include "RE/B/BSTScatterTable.h"
#include "RE/T/TESForm.h"
#include "RE/G/GameVM.h"
#include "SFSE/Logger.h"
#include "SFSE/SFSE.h"
#include "RE/O/ObjectTypeInfo.h"
#include "RE/O/Object.h"
#include "RE/S/StackFrame.h"
#include "RE/N/NativeFunctionBase.h"

namespace RE::BSScript
{
	namespace detail
	{
		struct wrapper_accessor;

		template <class T>
		using decay_t =
			std::conditional_t<
				std::is_pointer_v<T>,
				std::remove_cv_t<std::remove_pointer_t<T>>,
				std::remove_cvref_t<T>>;

		template <class T>
		[[nodiscard]] std::optional<TypeInfo> GetTypeInfo();

		template <class T>
		void PackVariable(Variable& a_var, T&& a_val);

		template <class T>
		[[nodiscard]] T UnpackVariable(const Variable& a_var);

		template <class CharT, std::size_t N1, std::size_t N2>
		[[nodiscard]] consteval auto make_structure_tag(
			stl::nttp::string<CharT, N1> a_lhs,
			stl::nttp::string<CharT, N2> a_rhs) noexcept
			-> stl::nttp::string<CharT, N1 + 1 + N2>
		{
			char buf[a_lhs.length() + 1 + a_rhs.length() + 1]{ '\0' };
			std::copy_n(a_lhs.data(), a_lhs.length(), buf);
			buf[a_lhs.length()] = '#';
			std::copy_n(a_rhs.data(), a_rhs.length(), buf + a_lhs.length() + 1);
			return { static_cast<const char(&)[N1 + 1 + N2 + 1]>(buf) };
		}
	}

	template <
		stl::nttp::string Object,
		stl::nttp::string Structure>
	class structure_wrapper
	{
	private:
		static constexpr stl::nttp::string _full = detail::make_structure_tag(Object, Structure);

	public:
		static constexpr std::string_view name{ _full.data(), _full.length() };

		structure_wrapper()
		{
			if (!_proxy) {
				const auto game = GameVM::GetSingleton();
				const auto vm = game ? game->GetVM() : nullptr;
				if (!vm ||
					!vm->CreateStruct(name, _proxy) ||
					!_proxy) {
					SFSE::log::error(
						FMT_STRING("failed to create structure of type \"{}\""),
						name);
					assert(false);
				}
			}
		}

		template <class T>
		std::optional<T> find(std::string_view a_name, bool a_quiet = false) const
		{
			if (_proxy && _proxy->type) {
				const auto& mappings = _proxy->type->varNameIndexMap;
				const auto it = mappings.find(a_name);
				if (it != mappings.end()) {
					const auto& var = _proxy->variables[it->Value];
					return detail::UnpackVariable<T>(var);
				}
			}

			if (!a_quiet) {
				SFSE::log::warn(
					FMT_STRING("failed to find var \"{}\" on structure \"{}\""),
					a_name,
					name);
			}

			return std::nullopt;
		}

		template <class T>
		bool insert(std::string_view a_name, T&& a_val)
		{
			if (_proxy && _proxy->type) {
				auto& mappings = _proxy->type->varNameIndexMap;
				const auto it = mappings.find(a_name);
				if (it != mappings.end()) {
					auto& var = _proxy->variables[it->Value];
					detail::PackVariable(var, std::forward<T>(a_val));
					return true;
				}
			}

			SFSE::log::warn(
				FMT_STRING("failed to pack var \"{}\" on structure \"{}\""),
				a_name,
				name);
			return false;
		}

	protected:
		friend struct detail::wrapper_accessor;

		explicit structure_wrapper(BSTSmartPointer<Struct> a_proxy) noexcept :
			_proxy(std::move(a_proxy))
		{
			assert(_proxy != nullptr);
		}

		[[nodiscard]] BSTSmartPointer<Struct> get_proxy() const& { return _proxy; }
		[[nodiscard]] BSTSmartPointer<Struct> get_proxy() && { return std::move(_proxy); }

	private:
		BSTSmartPointer<Struct> _proxy;
	};

	template <class>
	struct script_traits final
	{
		using is_array = std::false_type;
		using is_string = std::false_type;
		using is_nullable = std::false_type;
	};

	template <
		class T,
		class Allocator>
	struct script_traits<
		std::vector<T, Allocator>>
		final
	{
		using is_array = std::true_type;
	};

	template <class Traits>
	struct script_traits<
		std::basic_string_view<char, Traits>>
		final
	{
		using is_string = std::true_type;
	};

	template <
		class Traits,
		class Allocator>
	struct script_traits<
		std::basic_string<char, Traits, Allocator>>
		final
	{
		using is_string = std::true_type;
	};

	template <class T>
	struct script_traits<
		std::optional<T>>
		final
	{
		using is_nullable = std::true_type;
	};

	namespace detail
	{
		template <class>
		struct _is_bstsmartptr :
			std::false_type
		{};

		template <class T, template <class> class R>
		struct _is_bstsmartptr<BSTSmartPointer<T, R>> :
			std::true_type
		{};

		template <class T>
		using is_bstsmartptr = _is_bstsmartptr<std::remove_cv_t<T>>;

		template <class T>
		inline constexpr bool is_bstsmartptr_v = is_bstsmartptr<T>::value;

		template <class>
		struct _is_structure_wrapper :
			std::false_type
		{};

		template <stl::nttp::string O, stl::nttp::string S>
		struct _is_structure_wrapper<structure_wrapper<O, S>> :
			std::true_type
		{};

		template <class T>
		using is_structure_wrapper = _is_structure_wrapper<std::remove_cv_t<T>>;

		template <class T>
		inline constexpr bool is_structure_wrapper_v = is_structure_wrapper<T>::value;

		// clang-format off
		template <class F, class R, class... Args>
		concept invocable_r = requires(F&& a_func, Args&&... a_args)
		{
			{ std::invoke(std::forward<F>(a_func), std::forward<Args>(a_args)...) } -> std::same_as<R>;
		};
		// clang-format on

		template <class From, class To>
		concept decays_to = std::same_as<std::decay_t<From>, To>;

		template <class T>
		concept static_tag = std::same_as<T, std::monostate>;

		// clang-format off
		template <class T>
		concept object =
			std::derived_from<std::remove_cv_t<T>, TESForm> &&
			requires { std::remove_cv_t<T>::FORMTYPE; };
		// clang-format on

		template <class T>
		concept vmobject = std::same_as<std::remove_cv_t<T>, Object>;

		template <class T>
		concept vmobject_ptr =
			is_bstsmartptr_v<T> &&
			vmobject<typename std::remove_cv_t<T>::element_type>;

		template <class T>
		concept vmvariable = std::same_as<std::remove_cv_t<T>, Variable>;

		template <class T>
		concept string =
			std::same_as<
				typename script_traits<std::remove_cv_t<T>>::is_string,
				std::true_type> &&
			std::convertible_to<T, std::string_view> &&
			std::constructible_from<T, std::string_view>;

		template <class T>
		concept integral =
			(std::integral<T> && !std::same_as<std::remove_cv_t<T>, bool>) ||
			std::is_enum_v<T>;

		template <class T>
		concept signed_integral =
			(std::signed_integral<T> && !std::same_as<std::remove_cv_t<T>, bool>) ||
			(std::is_enum_v<T> && std::signed_integral<std::underlying_type_t<T>>);

		template <class T>
		concept unsigned_integral =
			(std::unsigned_integral<T> && !std::same_as<std::remove_cv_t<T>, bool>) ||
			(std::is_enum_v<T> && std::unsigned_integral<std::underlying_type_t<T>>);

		template <class T>
		concept floating_point = std::floating_point<T>;

		// clang-format off
		template <class T>
		concept boolean = std::same_as<std::remove_cv_t<T>, bool>;
		// clang-format on

		// clang-format off
		template <class T>
		concept array =
			std::same_as<
				typename script_traits<std::remove_cv_t<T>>::is_array,
				std::true_type> &&
			std::is_default_constructible_v<T> &&
			requires(T a_array, typename T::value_type a_value)
		{
			{ a_array.begin() } -> std::same_as<typename T::iterator>;
			{ a_array.end() } -> std::same_as<typename T::iterator>;
			{ a_array.size() } -> std::same_as<typename T::size_type>;
			a_array.push_back(static_cast<typename T::value_type&&>(a_value));
		};
		// clang-format on

		template <class T>
		concept wrapper = is_structure_wrapper_v<T>;

		template <class T>
		concept nullable =
			std::same_as<
				typename script_traits<std::remove_cv_t<T>>::is_nullable,
				std::true_type> &&
			std::is_default_constructible_v<T> &&
			((array<typename T::value_type> || wrapper<typename T::value_type>)) &&  //
			requires(T a_nullable)
		{
			// clang-format off
			static_cast<bool>(a_nullable);
			{ *static_cast<T&&>(a_nullable) } -> decays_to<typename T::value_type>;
			// clang-format on
		};

		template <class T>
		concept valid_self =
			static_tag<T> ||
			((std::is_lvalue_reference_v<T> &&
				(object<std::remove_reference_t<T>> || vmobject<std::remove_reference_t<T>>)));

		template <class T>
		concept valid_parameter =
			(std::is_pointer_v<T> &&
				(object<std::remove_pointer_t<T>> ||
					(std::is_const_v<std::remove_pointer_t<T>> && vmvariable<std::remove_pointer_t<T>>))) ||
			(!std::is_reference_v<T> &&
				(vmobject_ptr<T> ||
					string<T> ||
					integral<T> ||
					floating_point<T> ||
					boolean<T> ||
					array<T> ||
					wrapper<T> ||
					nullable<T>));

		template <class T>
		concept valid_return =
			valid_parameter<T> ||
			std::same_as<T, void>;

		struct wrapper_accessor
		{
			template <class T>
			[[nodiscard]] static T construct(const Variable& a_var)  //
				requires(is_structure_wrapper_v<T>)
			{
				return T(get<Struct>(a_var));
			}

			template <class T>
			[[nodiscard]] static auto get_proxy(T&& a_wrapper)  //
				requires(wrapper<std::remove_reference_t<T>>)
			{
				return std::forward<T>(a_wrapper).get_proxy();
			}
		};
	}

	template <detail::object T>
	[[nodiscard]] constexpr std::uint32_t GetVMTypeID() noexcept
	{
		return static_cast<std::uint32_t>(T::FORMTYPE);
	}

	template <class T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()  //
		requires(std::same_as<T, void>)
	{
		return TypeInfo::RawType::kNone;
	}

	template <detail::static_tag T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		return TypeInfo::RawType::kNone;
	}

	template <detail::object T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		const auto game = GameVM::GetSingleton();
		const auto vm = game ? game->GetVM() : nullptr;
		BSTSmartPointer<ObjectTypeInfo> typeInfo;
		if (!vm ||
			!vm->GetScriptObjectType(GetVMTypeID<T>(), typeInfo) ||
			!typeInfo) {
			assert(false);
			SFSE::log::error("failed to get type info for object"sv);
			return std::nullopt;
		} else {
			return typeInfo.get();
		}
	}

	template <detail::vmobject T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		const auto game = GameVM::GetSingleton();
		const auto vm = game ? game->GetVM() : nullptr;
		REL::Relocation<RE::BSFixedString*> baseObjectName{ REL::ID(648543) };
		BSTSmartPointer<ObjectTypeInfo> typeInfo;
		if (!vm ||
			!vm->GetScriptObjectType(*baseObjectName, typeInfo) ||
			!typeInfo) {
			assert(false);
			SFSE::log::error("failed to get type info for vm object"sv);
			return std::nullopt;
		} else {
			return typeInfo.get();
		}
	}

	template <detail::vmvariable T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		return TypeInfo::RawType::kVar;
	}

	template <detail::string T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		return TypeInfo::RawType::kString;
	}

	template <detail::integral T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		return TypeInfo::RawType::kInt;
	}

	template <detail::floating_point T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		return TypeInfo::RawType::kFloat;
	}

	template <detail::boolean T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		return TypeInfo::RawType::kBool;
	}

	template <detail::array T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		using value_type = detail::decay_t<typename std::remove_cv_t<T>::value_type>;

		auto typeInfo = detail::GetTypeInfo<value_type>();
		if (typeInfo) {
			typeInfo->SetArray(true);
		}

		return typeInfo;
	}

	template <detail::wrapper T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		const auto game = GameVM::GetSingleton();
		const auto vm = game ? game->GetVM() : nullptr;
		if constexpr (detail::is_structure_wrapper_v<T>) {
			BSTSmartPointer<StructTypeInfo> typeInfo;
			if (!vm ||
				!vm->GetScriptStructType(T::name, typeInfo) ||
				!typeInfo) {
				assert(false);
				SFSE::log::error("failed to get type info for structure"sv);
				return std::nullopt;
			} else {
				return typeInfo.get();
			}
		} else {
			static_assert(false && sizeof(T));
		}
	}

	template <detail::nullable T>
	[[nodiscard]] std::optional<TypeInfo> GetTypeInfo()
	{
		using value_type = typename std::remove_cv_t<T>::value_type;
		return detail::GetTypeInfo<value_type>();
	}

	namespace detail
	{
		template <class T>
		__forceinline std::optional<TypeInfo> GetTypeInfo()
		{
			return BSScript::GetTypeInfo<T>();
		}
	}

	template <detail::object T>
	void PackVariable(Variable& a_var, const volatile T* a_val)
	{
		if (!a_val) {
			a_var = nullptr;
			return;
		}

		const auto success = [&]() {
			const auto game = GameVM::GetSingleton();
			const auto vm = game ? game->GetVM() : nullptr;
			BSTSmartPointer<ObjectTypeInfo> typeInfo;
			if (!vm ||
				!vm->GetScriptObjectType(GetVMTypeID<T>(), typeInfo) ||
				!typeInfo) {
				return false;
			}

			const auto& handles = vm->GetObjectHandlePolicy();
			const auto handle = handles.GetHandleForObject(
				GetVMTypeID<T>(),
				const_cast<const void*>(
					static_cast<const volatile void*>(a_val)));
			if (handle == handles.EmptyHandle()) {
				return false;
			}

			BSTSmartPointer<Object> object;
			if (!vm->FindBoundObject(handle, typeInfo->name.c_str(), false, object, false) &&
				vm->CreateObject(typeInfo->name, object) &&
				object) {
				auto& binding = vm->GetObjectBindPolicy();
				binding.BindObject(object, handle);
			}

			if (!object) {
				return false;
			}

			a_var = std::move(object);
			return true;
		}();

		if (!success) {
			assert(false);
			SFSE::log::error("failed to pack variable"sv);
			a_var = nullptr;
		}
	}

	template <detail::vmobject_ptr T>
	void PackVariable(Variable& a_var, T a_val)
	{
		a_var = a_val ? std::move(a_val) : nullptr;
	}

	template <detail::vmvariable T>
	void PackVariable(Variable& a_var, const volatile T* a_val)
	{
		a_var = a_val ? const_cast<T*>(a_val) : nullptr;
	}

	template <class T>
	void PackVariable(Variable& a_var, T&& a_val)  //
		requires(detail::string<std::remove_reference_t<T>>)
	{
		a_var = BSFixedString(std::forward<T>(a_val));
	}

	template <detail::signed_integral T>
	void PackVariable(Variable& a_var, T a_val)
	{
		a_var = static_cast<std::int32_t>(a_val);
	}

	template <detail::unsigned_integral T>
	void PackVariable(Variable& a_var, T a_val)
	{
		a_var = static_cast<std::uint32_t>(a_val);
	}

	template <detail::floating_point T>
	void PackVariable(Variable& a_var, T a_val)
	{
		a_var = static_cast<float>(a_val);
	}

	template <detail::boolean T>
	void PackVariable(Variable& a_var, T a_val)
	{
		a_var = static_cast<bool>(a_val);
	}

	template <class T>
	void PackVariable(Variable& a_var, T&& a_val)  //
		requires(detail::array<std::remove_reference_t<T>>)
	{
		using value_type = detail::decay_t<typename std::remove_cvref_t<T>::value_type>;
		using reference_type =
			std::conditional_t<
				std::is_lvalue_reference_v<T>,
				typename std::remove_cvref_t<T>::value_type&,
				typename std::remove_cvref_t<T>::value_type&&>;

		const auto success = [&]() {
			const auto game = GameVM::GetSingleton();
			const auto vm = game ? game->GetVM() : nullptr;
			const auto typeInfo = GetTypeInfo<std::remove_cvref_t<T>>();
			const auto size = a_val.size();
			BSTSmartPointer<Array> out;
			if (!typeInfo ||
				!vm ||
				!vm->CreateArray(*typeInfo, static_cast<std::uint32_t>(size), out) ||
				!out) {
				return false;
			}

			std::uint32_t i = 0;
			for (auto&& elem : std::forward<T>(a_val)) {
				detail::PackVariable(out->elements[i++], static_cast<reference_type>(elem));
			}

			a_var = std::move(out);
			return true;
		}();

		if (!success) {
			assert(false);
			SFSE::log::error("failed to pack array"sv);
			a_var = nullptr;
		}
	}

	template <class T>
	void PackVariable(Variable& a_var, T&& a_val)  //
		requires(detail::wrapper<std::remove_reference_t<T>>)
	{
		a_var = detail::wrapper_accessor::get_proxy(std::forward<T>(a_val));
	}

	template <class T>
	void PackVariable(Variable& a_var, T&& a_val)  //
		requires(detail::nullable<std::remove_reference_t<T>>)
	{
		if (a_val) {
			detail::PackVariable(a_var, *std::forward<T>(a_val));
		} else {
			a_var = nullptr;
		}
	}

	namespace detail
	{
		template <class T>
		__forceinline void PackVariable(Variable & a_var, T && a_val)
		{
			BSScript::PackVariable(a_var, std::forward<T>(a_val));
		}
	}

	template <detail::static_tag T>
	[[nodiscard]] std::monostate UnpackVariable([[maybe_unused]] const Variable& a_var)
	{
		assert(a_var.is<std::nullptr_t>());
		return {};
	}

	template <detail::object T>
	[[nodiscard]] T* UnpackVariable(const Variable& a_var)
	{
		if (a_var.is<Object>() && get<Object>(a_var) == nullptr) {
			return nullptr;
		}

		const auto result = [&]() -> void* {
			if (!a_var.is<Object>()) {
				assert(false);
				return nullptr;
			}

			const auto game = GameVM::GetSingleton();
			const auto vm = game ? game->GetVM() : nullptr;
			const auto object = get<Object>(a_var);
			if (!vm || !object) {
				return nullptr;
			}

			const auto& handles = vm->GetObjectHandlePolicy();
			const auto handle = object->GetHandle();
			if (!handles.IsHandleLoaded(handle)) {
				return nullptr;
			}

			return handles.GetObjectForHandle(GetVMTypeID<T>(), handle);
		}();

		if (!result) {
			assert(false);
			SFSE::log::error("failed to get object from variable"sv);
		}

		return static_cast<T*>(result);
	}

	template <detail::vmobject_ptr T>
	[[nodiscard]] T UnpackVariable(const Variable& a_var)
	{
		return get<Object>(a_var);
	}

	template <detail::vmvariable T>
	[[nodiscard]] const T* UnpackVariable(const Variable& a_var)
	{
		return get<Variable>(a_var);
	}

	template <detail::string T>
	[[nodiscard]] T UnpackVariable(const Variable& a_var)
	{
		if (!a_var.is<BSFixedString>()) {
			assert(false);
			return T();
		}

		if constexpr (std::same_as<T, BSFixedString> ||
					  std::same_as<T, BSFixedStringCS>) {
			return get<BSFixedString>(a_var);
		} else {
			const auto str = get<BSFixedString>(a_var);
			return T(static_cast<std::string_view>(str));
		}
	}

	template <detail::signed_integral T>
	[[nodiscard]] T UnpackVariable(const Variable& a_var)
	{
		if (!a_var.is<std::int32_t>()) {
			assert(false);
			return T();
		}

		return static_cast<T>(get<std::int32_t>(a_var));
	}

	template <detail::unsigned_integral T>
	[[nodiscard]] T UnpackVariable(const Variable& a_var)
	{
		if (!a_var.is<std::uint32_t>()) {
			assert(false);
			return T();
		}

		return static_cast<T>(get<std::uint32_t>(a_var));
	}

	template <detail::floating_point T>
	[[nodiscard]] T UnpackVariable(const Variable& a_var)
	{
		if (!a_var.is<float>()) {
			assert(false);
			return T();
		}

		return static_cast<T>(get<float>(a_var));
	}

	template <detail::boolean T>
	[[nodiscard]] T UnpackVariable(const Variable& a_var)
	{
		if (!a_var.is<bool>()) {
			assert(false);
			return T();
		}

		return static_cast<T>(get<bool>(a_var));
	}

	template <detail::array T>
	[[nodiscard]] T UnpackVariable(const Variable& a_var)
	{
		if (!a_var.is<Array>()) {
			assert(false);
			return T();
		}

		using value_type = typename T::value_type;

		T out;
		const auto in = get<Array>(a_var);
		for (const auto& var : in->elements) {
			out.push_back(detail::UnpackVariable<value_type>(var));
		}

		return out;
	}

	template <detail::wrapper T>
	[[nodiscard]] T UnpackVariable(const Variable& a_var)
	{
		return detail::wrapper_accessor::construct<T>(a_var);
	}

	template <detail::nullable T>
	[[nodiscard]] T UnpackVariable(const Variable& a_var)
	{
		if (a_var.is<std::nullptr_t>()) {
			return T();
		} else {
			using value_type = typename T::value_type;
			return T(detail::UnpackVariable<value_type>(a_var));
		}
	}

	namespace detail
	{
		template <class T>
		[[nodiscard]] __forceinline T UnpackVariable(const Variable& a_var)
		{
			return BSScript::UnpackVariable<decay_t<T>>(a_var);
		}

		template <class T>
		consteval bool ValidateParameter() noexcept
		{
			// Must be one of (optionally cv-qualified):
			//	* A pointer to one of:
			//		* (optionally cv-qualified) `RE::TESForm` or any subclass thereof
			//		* (optionally volatile) `const RE::BSScript::Variable`
			//	* `RE::BSTSmartPointer<RE::BSScript::Object>`
			//	* A string type which is one of:
			//		* std::string
			//		* std::string_view
			//		* RE::BSFixedString
			//		* RE::BSFixedStringCS
			//		* A custom type which implements:
			//			* A specialization of `RE::BSScript::script_traits` which provides a typedef `is_string` as `std::true_type`
			//			* A conversion to `std::string_view`
			//	* An integral type which is one of (optionally signed/unsigned):
			//		* `char`
			//		* `short`
			//		* `int`
			//		* `long`
			//		* `long long`
			//	* An enumeration type
			//	* A floating point type which is one of:
			//		* `float`
			//		* `double`
			//		* `long double`
			//	* `bool`
			//	* An array type which is one of:
			//		* std::vector
			//		* RE::BSTArray
			//		* A custom type which implements:
			//			* A specialization of `RE::BSScript::script_traits` which provides a typedef `is_array` as `std::true_type`
			// 			* A default constructor
			//			* The following typedefs:
			//				* `iterator`
			//				* `size_type`
			//				* `value_type`
			//			* The following methods:
			//				* `begin`
			//					* Callable with no arguments
			//					* Returns a type of `iterator`
			//				* `end`
			//					* Callable with no arguments
			//					* Returns a type of `iterator`
			//				* `size`
			//					* Callable with no arguments
			//					* Returns a type of `size_type`
			//				* `push_back`
			//					* Callable with an rvalue reference of type `value_type`
			//		* Additionally, the array's `value_type` must be a valid parameter type
			//	* A wrapper type which is one of:
			//		* `RE::BSScript::structure_wrapper`
			//	* A nullable type which is one of:
			//		* std::optional
			//		* A custom type which implements:
			//			* A specialization of `RE::BSScript::script_traits` which provides a typedef `is_nullable` as `std::true_type`
			//			* A default constructor
			//			* The following typedefs:
			//				* `value_type`
			//			* The following methods:
			//				* operator bool
			//				* operator *
			//					* Returns type of `value_type`
			//		* Additionally, the nullable's `value_type` must be one of:
			//			* An array type
			//			* A structure type
			static_assert(detail::valid_parameter<T>, "invalid parameter type");
			if constexpr (detail::array<T> || detail::nullable<T>) {
				return detail::ValidateParameter<typename std::remove_cv_t<T>::value_type>();
			} else {
				return true;
			}
		}

		template <class T>
		consteval bool ValidateReturn() noexcept
		{
			// Must be one of:
			//	* `void`
			//	* A valid parameter type
			if constexpr (std::same_as<T, void>) {
				return true;
			} else {
				return ValidateParameter<T>();
			}
		}

		template <
			bool LONG,
			class S,
			class... Args,
			class F,
			std::size_t... I>
		decltype(auto) DispatchHelper(
			Variable& a_self,
			Internal::VirtualMachine& a_vm,
			std::uint32_t a_stackID,
			const StackFrame& a_stackFrame,
			Stack& a_stack,
			const std::function<F>& a_callback,
			std::index_sequence<I...>)
		{
			const auto self = [&]() -> S {
				// super::Call should guarantee the self parameter is not none
				if constexpr (detail::static_tag<S>) {
					return std::monostate{};
				} else if constexpr (detail::object<std::remove_cvref_t<S>>) {
					auto* const ptr = BSScript::UnpackVariable<std::remove_cvref_t<S>>(a_self);
					assert(ptr != nullptr);
					return *ptr;
				} else if constexpr (detail::vmobject<std::remove_cvref_t<S>>) {
					const auto obj = get<Object>(a_self);
					assert(obj != nullptr);
					return *obj;
				} else {
					static_assert(false && sizeof(S), "unhandled case");
				}
			};

			const auto pframe = std::addressof(a_stackFrame);
			const auto page = a_stack.GetPageForFrame(pframe);
			const auto args = [&]<class T>(std::in_place_type_t<T>, std::size_t a_index) {
				if (a_stackFrame.size > a_index) {
					return UnpackVariable<detail::decay_t<T>>(
						a_stack.GetStackFrameVariable(
							pframe,
							static_cast<std::uint32_t>(a_index),
							page));
				} else {
					assert(false);
					return T();
				}
			};

			if constexpr (LONG) {
				return a_callback(
					reinterpret_cast<IVirtualMachine&>(a_vm),  // TODO: static_cast
					a_stackID,
					self(),
					args(std::in_place_type_t<Args>{}, I)...);
			} else {
				return a_callback(
					self(),
					args(std::in_place_type_t<Args>{}, I)...);
			}
		}
	}

	template <
		class F,
		bool LONG,
		class R,
		class S,
		class... Args>
	class NativeFunction :
		public NF_util::NativeFunctionBase
	{
	private:
		using super = NF_util::NativeFunctionBase;

	public:
		// A function which takes a self parameter must be one of (optionally cv-qualified):
		//	* An lvalue reference to one of:
		//		* `RE::TESForm` or any subclass thereof
		//		* `RE::BSScript::Object`
		//	* `RE::GameScript::RefrOrInventoryObj`
		// A function which does not take a self parameter (a global function) must tag the self slot with `std::monostate`
		static_assert(detail::valid_self<S>, "invalid self type");

		static_assert(detail::ValidateReturn<R>());
		static_assert(((detail::ValidateParameter<Args>(), ...), true));

		template <class Fn>
		NativeFunction(std::string_view a_object, std::string_view a_function, Fn a_func, bool a_isLatent)  //
			requires(detail::invocable_r<Fn, R, S, Args...> ||
					 detail::invocable_r<Fn, R, IVirtualMachine&, std::uint32_t, S, Args...>) :
			super(a_object, a_function, sizeof...(Args), detail::static_tag<S>, a_isLatent),
			_stub(std::move(a_func))
		{
			assert(super::_params.paramCount == sizeof...(Args));
			std::size_t i = 0;
			((super::_params.entries[i++].second = GetTypeInfo<detail::decay_t<Args>>().value_or(nullptr)), ...);
			super::_retType = GetTypeInfo<detail::decay_t<R>>().value_or(nullptr);
		}

		// override (NF_util::NativeFunctionBase)
		bool HasStub() const override { return static_cast<bool>(_stub); }  // 15

		bool MarshallAndDispatch(Variable& a_self, Internal::VirtualMachine& a_vm, std::uint32_t a_stackID, Variable& a_retVal, const StackFrame& a_stackFrame) const override  // 16
		{
			a_retVal = nullptr;

			const auto stack = a_stackFrame.parent;
			if (!stack) {
				assert(false);
				SFSE::log::error("native function called without relevant stack"sv);
				return false;
			}

			const auto invoke = [&]() {
				return detail::DispatchHelper<LONG, S, Args...>(
					a_self,
					a_vm,
					a_stackID,
					a_stackFrame,
					*stack,
					_stub,
					std::index_sequence_for<Args...>{});
			};

			if constexpr (!std::same_as<R, void>) {
				PackVariable(a_retVal, invoke());
			} else {
				invoke();
			}

			return true;
		}

	private:
		std::function<F> _stub;
	};

	template <
		class R,
		class S,
		class... Args>
	NativeFunction(std::string_view, std::string_view, R (*)(S, Args...), bool)
		-> NativeFunction<
			R(S, Args...),
			false,
			R,
			S,
			Args...>;

	template <
		class R,
		class S,
		class... Args>
	NativeFunction(std::string_view, std::string_view, R (*)(IVirtualMachine&, std::uint32_t, S, Args...), bool)
		-> NativeFunction<
			R(IVirtualMachine&, std::uint32_t, S, Args...),
			true,
			R,
			S,
			Args...>;

	template <class F>
	void IVirtualMachine::BindNativeMethod(
		stl::zstring a_object,
		stl::zstring a_function,
		F a_func,
		std::optional<bool> a_taskletCallable,
		bool a_isLatent)
	{
		NF_util::NativeFunctionBase* func = new NativeFunction(
			a_object,
			a_function,
			std::move(a_func),
			a_isLatent);

		const auto success =
			BindNativeMethod(func);

		if (!success) {
			SFSE::log::warn(
				FMT_STRING("failed to register method \"{}\" on object \"{}\""),
				a_function,
				a_object);
		}

		if (success && a_taskletCallable) {
			SetCallableFromTasklets(a_object.data(), a_function.data(), *a_taskletCallable);
		}
	}
}
