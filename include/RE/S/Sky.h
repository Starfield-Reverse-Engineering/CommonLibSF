#pragma once

#include "RE/B/BSTSingleton.h"

namespace RE
{
	class IExternalEmittanceManager
	{
	public:
		SF_RTTI(IExternalEmittanceManager);
	};

	class ILightEmittanceManager
	{
	public:
		SF_RTTI(ILightEmittanceManager);
	};

	class __declspec(novtable) Sky :
		public BSTSingletonSDM<Sky>,
		public IExternalEmittanceManager,
		public ILightEmittanceManager
	{
	public:
		SF_RTTI_VTABLE(Sky);

		virtual ~Sky();  // 00

		// members
		std::byte pad[0xEB8];  // 00?
		float     windSpeed;   // EC4
	};
	static_assert(offsetof(Sky, windSpeed) == 0xEC4);
}
