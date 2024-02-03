#pragma once

namespace RE::BSBind
{
	class IAddressControllerStore
	{
	public:
		virtual ~IAddressControllerStore();  // 00

		// add
		virtual void Unk_01();  // 01
		virtual void Unk_02();  // 02
		virtual void Unk_03();  // 03
		virtual void Unk_04();  // 04
		virtual void Unk_05();  // 05
	};
	static_assert(sizeof(IAddressControllerStore) == 0x8);
}
