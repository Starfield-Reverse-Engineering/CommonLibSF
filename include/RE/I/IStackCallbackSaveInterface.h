#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class BSStorage;

	namespace BSScript
	{
		class Variable;

		class __declspec(novtable) alignas(0x08) IStackCallbackFunctor :
			public BSIntrusiveRefCounted
		{
		public:
			virtual ~IStackCallbackFunctor(){};  // 00

			// add
			virtual void CallQueued() = 0;                        // 01
			virtual void CallCanceled() = 0;                      // 02
			virtual void StartMultiDispatch() = 0;                // 03
			virtual void EndMultiDispatch() = 0;                  // 04
			virtual void operator()(Variable) = 0;				  // 05
			virtual bool CanSave() { return false; };             // 06
		};
		static_assert(sizeof(IStackCallbackFunctor) == 0x10);

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
