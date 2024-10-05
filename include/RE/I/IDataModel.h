#pragma once

namespace RE
{
	class IDataModel
	{
	public:
		SF_RTTI_VTABLE(IDataModel);

		virtual ~IDataModel();

		virtual void Unk01();
		virtual void Unk02();
		virtual void Unk03();

		// members
		void* unk08;  // 08 - model object?
	};
}
