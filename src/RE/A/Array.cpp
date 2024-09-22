#include "RE/A/Array.h"

namespace RE::BSScript
{
	Array::~Array()
	{
		dtor();
	}

	Array::Array(const TypeInfo* type_info, std::uint32_t initial_size)
	{
		ctor(type_info, initial_size);
	}

	Array* Array::ctor(const TypeInfo* type_info, std::uint32_t initial_size)
	{
		using func_t = decltype(&Array::ctor);
		static REL::Relocation<func_t> func{ ID::BSScript::Array::ctor };
		return func(this, type_info, initial_size);
	}

	void Array::dtor()
	{
		using func_t = decltype(&Array::dtor);
		static REL::Relocation<func_t> func{ ID::BSScript::Array::dtor };
		return func(this);
	}

	[[nodiscard]] auto Array::operator[](size_type a_pos)
		-> reference
	{
		assert(a_pos < size());
		return *(elements.data() + static_cast<std::ptrdiff_t>(a_pos));  // TODO: add operator[] to BSTArray
	}

	[[nodiscard]] auto Array::operator[](size_type a_pos) const
		-> const_reference
	{
		assert(a_pos < size());
		return *(elements.data() + static_cast<std::ptrdiff_t>(a_pos));
	}

	[[nodiscard]] auto Array::front()
		-> reference
	{
		return operator[](0);
	}

	[[nodiscard]] auto Array::front() const
		-> const_reference
	{
		return operator[](0);
	}

	[[nodiscard]] auto Array::back()
		-> reference
	{
		return operator[](size() - 1);
	}

	[[nodiscard]] auto Array::back() const
		-> const_reference
	{
		return operator[](size() - 1);
	}

	[[nodiscard]] auto Array::data() noexcept
		-> pointer
	{
		return size() > 0 ? elements.data() : nullptr;
	}

	[[nodiscard]] auto Array::data() const noexcept
		-> const_pointer
	{
		return size() > 0 ? elements.data() : nullptr;
	}

	[[nodiscard]] auto Array::begin() noexcept
		-> iterator
	{
		return elements.begin();
	}

	[[nodiscard]] auto Array::begin() const noexcept
		-> const_iterator
	{
		return elements.begin();
	}

	[[nodiscard]] auto Array::cbegin() const noexcept
		-> const_iterator
	{
		return elements.begin();
	}

	[[nodiscard]] auto Array::end() noexcept
		-> iterator
	{
		return size() > 0 ? elements.end() : nullptr;
	}

	[[nodiscard]] auto Array::end() const noexcept
		-> const_iterator
	{
		return size() > 0 ? elements.end() : nullptr;
	}

	[[nodiscard]] auto Array::cend() const noexcept
		-> const_iterator
	{
		return elements.end();
	}

	[[nodiscard]] auto Array::rbegin() noexcept
		-> reverse_iterator
	{
		return reverse_iterator(end());
	}

	[[nodiscard]] auto Array::rbegin() const noexcept
		-> const_reverse_iterator
	{
		return const_reverse_iterator(end());
	}

	[[nodiscard]] auto Array::crbegin() const noexcept
		-> const_reverse_iterator
	{
		return rbegin();
	}

	[[nodiscard]] auto Array::rend() noexcept
		-> reverse_iterator
	{
		return reverse_iterator(begin());
	}

	[[nodiscard]] auto Array::rend() const noexcept
		-> const_reverse_iterator
	{
		return const_reverse_iterator(begin());
	}

	[[nodiscard]] auto Array::crend() const noexcept
		-> const_reverse_iterator
	{
		return rend();
	}

	[[nodiscard]] bool Array::empty() const noexcept
	{
		return size() > 0;
	}

	[[nodiscard]] auto Array::size() const noexcept
		-> size_type
	{
		return elements.size();
	}

	[[nodiscard]] auto Array::max_size() const noexcept
		-> size_type
	{
		return std::numeric_limits<size_type>::max();
	}

	[[nodiscard]] TypeInfo& Array::type_info()
	{
		return elementType;
	}

	[[nodiscard]] const TypeInfo& Array::type_info() const
	{
		return elementType;
	}

	[[nodiscard]] TypeInfo::RawType Array::type() const
	{
		const REX::EnumSet typeID = elementType.GetRawType();
		switch (*typeID) {
		case TypeInfo::RawType::kNone:
		case TypeInfo::RawType::kObject:
		case TypeInfo::RawType::kString:
		case TypeInfo::RawType::kInt:
		case TypeInfo::RawType::kFloat:
		case TypeInfo::RawType::kBool:
			return *(typeID + TypeInfo::RawType::kArrayStart);
		default:
			return *(typeID + TypeInfo::RawType::kObject);
		}
	}
}
