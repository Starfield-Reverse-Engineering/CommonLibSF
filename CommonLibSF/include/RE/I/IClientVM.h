#pragma once

namespace RE
{
	namespace BSScript
	{
		class __declspec(novtable) IClientVM
		{
		public:
			static constexpr auto RTTI{ RTTI::BSScript__IClientVM };
			static constexpr auto VTABLE{ VTABLE::BSScript__IClientVM };

			virtual ~IClientVM() = default;  // 00

			// add
			virtual bool IsVMFrozen() const = 0;  // 01
			virtual void PreSave() = 0;           // 02
			virtual void Unk_03(void) = 0;        // 03
		};
		static_assert(sizeof(IClientVM) == 0x8);
	}
}
