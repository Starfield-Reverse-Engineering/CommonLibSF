#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSLock.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BaseExtraList
	{
	public:
		void AddExtra(BSExtraData* a_extra)
		{
			using func_t = decltype(&BaseExtraList::AddExtra);
			static REL::Relocation<func_t> func{ ID::BaseExtraList::AddExtra };
			return func(this, a_extra);
		}

		[[nodiscard]] BSExtraData* GetByType(ExtraDataType a_type) const noexcept
		{
			using func_t = decltype(&BaseExtraList::GetByType);
			static REL::Relocation<func_t> func{ ID::BaseExtraList::GetByType };
			return func(this, a_type);
		}

	private:
		// members
		BSExtraData*  _head{};                         // 00
		BSExtraData** _tail{ std::addressof(_head) };  // 08
		std::uint8_t* _flags{};                        // 10
	};
	static_assert(sizeof(BaseExtraList) == 0x18);

	namespace detail
	{
		template <class T>
		concept ExtraDataListConstraint =
			std::derived_from<T, BSExtraData> &&
			!std::is_pointer_v<T> &&
			!std::is_reference_v<T>;
	}

	class ExtraDataList :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		void AddExtra(BSExtraData* a_extra)
		{
			const BSAutoWriteLock l{ _extraRWLock };
			_extraData.AddExtra(a_extra);
		}

		[[nodiscard]] BSExtraData* GetByType(ExtraDataType a_type) const noexcept
		{
			const BSAutoReadLock l{ _extraRWLock };
			return _extraData.GetByType(a_type);
		}

		template <detail::ExtraDataListConstraint T>
		[[nodiscard]] T* GetByType() const noexcept
		{
			return static_cast<T*>(GetByType(T::EXTRADATATYPE));
		}

		[[nodiscard]] bool HasQuestObjectAlias() const
		{
			using func_t = decltype(&ExtraDataList::HasQuestObjectAlias);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::HasQuestObjectAlias };
			return func(this);
		}

		[[nodiscard]] bool HasType(ExtraDataType a_type) const noexcept
		{
			using func_t = bool (*)(const ExtraDataList*, ExtraDataType);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::HasType };
			return func(this, a_type);
		}

		template <detail::ExtraDataListConstraint T>
		[[nodiscard]] bool HasType() const noexcept
		{
			return HasType(T::EXTRADATATYPE);
		}

	private:
		// members
		BaseExtraList           _extraData;    // 08
		mutable BSReadWriteLock _extraRWLock;  // 20
	};
	static_assert(sizeof(ExtraDataList) == 0x28);
}
