#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/M/MemoryManager.h"
#include "RE/T/TypeInfo.h"

namespace RE
{
	namespace BSScript
	{
		class Array;
		class Object;
		class Struct;
		class TypeInfo;
		class Variable;

		namespace detail
		{
			struct variable_raw_accessor;
		}

		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		class Variable
		{
		public:
			Variable() noexcept = default;
			Variable(const Variable& a_rhs) { copy(a_rhs); }
			Variable(Variable&&) noexcept = default;

			~Variable() { reset(); }

			Variable& operator=(const Variable& a_rhs)
			{
				if (this != std::addressof(a_rhs)) {
					reset();
					copy(a_rhs);
				}
				return *this;
			}

			Variable& operator=(Variable&&) noexcept = default;

			Variable& operator=(std::nullptr_t)
			{
				reset();
				assert(is<std::nullptr_t>());
				return *this;
			}

			Variable& operator=(BSTSmartPointer<Object> a_object);

			Variable& operator=(BSFixedString a_string)
			{
				reset();
				value.s = std::move(a_string);
				varType = RawType::kString;

				assert(is<BSFixedString>());
				return *this;
			}

			Variable& operator=(std::uint32_t a_unsigned)
			{
				reset();
				value.u = a_unsigned;
				varType = RawType::kInt;

				assert(is<std::uint32_t>());
				return *this;
			}

			Variable& operator=(std::int32_t a_signed)
			{
				reset();
				value.i = a_signed;
				varType = RawType::kInt;

				assert(is<std::int32_t>());
				return *this;
			}

			Variable& operator=(float a_float)
			{
				reset();
				value.f = a_float;
				varType = RawType::kFloat;

				assert(is<float>());
				return *this;
			}

			Variable& operator=(bool a_boolean)
			{
				reset();
				value.b = a_boolean;
				varType = RawType::kBool;

				assert(is<bool>());
				return *this;
			}

			Variable& operator=(stl::owner<Variable*> a_variable)
			{
				assert(a_variable != nullptr);
				assert(a_variable->varType.GetRawType() != RawType::kVar);

				reset();
				value.v = a_variable;
				varType = RawType::kVar;
				return *this;
			}

			Variable& operator=(BSTSmartPointer<Struct> a_struct);
			Variable& operator=(BSTSmartPointer<Array> a_array);

			SF_HEAP_REDEFINE_NEW(Variable);

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, std::nullptr_t>)
			{
				return varType.GetRawType() == RawType::kNone;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, Object>)
			{
				return varType.GetRawType() == RawType::kObject;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, BSFixedString>)
			{
				return varType.GetRawType() == RawType::kString;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, std::uint32_t> ||
						 std::same_as<T, std::int32_t>)
			{
				return varType.GetRawType() == RawType::kInt;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, float>)
			{
				return varType.GetRawType() == RawType::kFloat;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, bool>)
			{
				return varType.GetRawType() == RawType::kBool;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, Variable>)
			{
				return varType.GetRawType() == RawType::kVar;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, Struct>)
			{
				return varType.GetRawType() == RawType::kStruct;
			}

			template <class T>
			[[nodiscard]] bool is() const  //
				requires(std::same_as<T, Array>)
			{
				return varType.IsArray();
			}

			TypeInfo GetType() const
			{
				return varType;
			}

			void reset();

		private:
			friend detail::variable_raw_accessor;

			using RawType = TypeInfo::RawType;

			void copy(const Variable& a_rhs);

			// members
			TypeInfo varType;  // 00
			union V
			{
				// NOLINTNEXTLINE(modernize-use-equals-default)
				V() :
					v(nullptr)
				{}

				V(V&& a_rhs) noexcept :
					v(std::exchange(a_rhs.v, nullptr))
				{}

				~V() {}  // NOLINT(modernize-use-equals-default)

				V& operator=(V&& a_rhs) noexcept
				{
					if (this != std::addressof(a_rhs)) {
						v = std::exchange(a_rhs.v, nullptr);
					}
					return *this;
				}

				BSTSmartPointer<Object> o;
				BSFixedString           s;
				std::uint32_t           u;
				std::int32_t            i;
				float                   f;
				bool                    b;
				stl::owner<Variable*>   v;
				BSTSmartPointer<Struct> t;
				BSTSmartPointer<Array>  a;
			} value;  // 08
		};
		static_assert(sizeof(Variable) == 0x10);

		namespace detail
		{
			struct variable_raw_accessor
			{
			public:
				template <class T>
				[[nodiscard]] static auto&& get_raw(T&& a_var)  //
					requires(std::same_as<std::remove_cvref_t<T>, Variable>)
				{
					return std::forward<T>(a_var).value;
				}
			};
		}

		template <class T>
		[[nodiscard]] BSTSmartPointer<Object> get(const Variable& a_var)  //
			requires(std::same_as<T, Object>)
		{
			assert(a_var.is<Object>());
			return detail::variable_raw_accessor::get_raw(a_var).o;
		}

		template <class T>
		[[nodiscard]] BSFixedString get(const Variable& a_var)  //
			requires(std::same_as<T, BSFixedString>)
		{
			assert(a_var.is<BSFixedString>());
			return detail::variable_raw_accessor::get_raw(a_var).s;
		}

		template <class T>
		[[nodiscard]] std::uint32_t get(const Variable& a_var)  //
			requires(std::same_as<T, std::uint32_t>)
		{
			assert(a_var.is<std::uint32_t>());
			return detail::variable_raw_accessor::get_raw(a_var).u;
		}

		template <class T>
		[[nodiscard]] std::int32_t get(const Variable& a_var)  //
			requires(std::same_as<T, std::int32_t>)
		{
			assert(a_var.is<std::int32_t>());
			return detail::variable_raw_accessor::get_raw(a_var).i;
		}

		template <class T>
		[[nodiscard]] float get(const Variable& a_var)  //
			requires(std::same_as<T, float>)
		{
			assert(a_var.is<float>());
			return detail::variable_raw_accessor::get_raw(a_var).f;
		}

		template <class T>
		[[nodiscard]] bool get(const Variable& a_var)  //
			requires(std::same_as<T, bool>)
		{
			assert(a_var.is<bool>());
			return detail::variable_raw_accessor::get_raw(a_var).b;
		}

		template <class T>
		[[nodiscard]] stl::observer<Variable*> get(const Variable& a_var)  //
			requires(std::same_as<T, Variable>)
		{
			assert(a_var.is<Variable>());
			return detail::variable_raw_accessor::get_raw(a_var).v;
		}

		template <class T>
		[[nodiscard]] BSTSmartPointer<Struct> get(const Variable& a_var)  //
			requires(std::same_as<T, Struct>)
		{
			assert(a_var.is<Struct>());
			return detail::variable_raw_accessor::get_raw(a_var).t;
		}

		template <class T>
		[[nodiscard]] BSTSmartPointer<Array> get(const Variable& a_var)  //
			requires(std::same_as<T, Array>)
		{
			assert(a_var.is<Array>());
			return detail::variable_raw_accessor::get_raw(a_var).a;
		}
	}
}
