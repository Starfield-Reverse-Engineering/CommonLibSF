#pragma once

#include "RE/T/TESModel.h"

namespace RE
{
	class BGSTextureModel : public TESModel
	{
	public:
		SF_RTTI_VTABLE(BGSTextureModel);

		~BGSTextureModel() override;  // 00
	};
	static_assert(sizeof(BGSTextureModel) == 0x20);
}
