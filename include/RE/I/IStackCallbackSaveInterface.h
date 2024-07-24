#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSStorage;

	namespace BSScript
	{
		class IStackCallbackFunctor;

		class __declspec(novtable) IStackCallbackSaveInterface
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IStackCallbackSaveInterface };
			static constexpr auto VTABLE{ VTABLE::BSScript__IStackCallbackSaveInterface };

			virtual ~IStackCallbackSaveInterface() = default;  // 00

			// add
			virtual bool SaveStackCallback(BSStorage& a_buffer, const BSTSmartPointer<IStackCallbackFunctor>& a_callback) const = 0;         // 01
			virtual bool LoadStackCallback(const BSStorage& a_buffer, bool&, BSTSmartPointer<IStackCallbackFunctor>& a_callback) const = 0;  // 02
		};
		static_assert(sizeof(IStackCallbackSaveInterface) == 0x8);
	}
}
