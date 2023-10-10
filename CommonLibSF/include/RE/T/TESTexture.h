#pragma once

#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class TESTexture : public BaseFormComponent
	{
	public:
		SF_RTTI_VTABLE(TESTexture);

		~TESTexture() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "TESTexture_Component"; }
		void                 InitializeDataComponent() override;     // 02

		// add
		virtual const char* GetAsNormalFile(void* a_outFilename) const;  // 0B
		virtual const char* GetDefaultPath() const;                      // 0C - { return "Textures\\"; }

		// members
		BSFixedString textureName;  // 08
	};
	static_assert(sizeof(TESTexture) == 0x10);
}
