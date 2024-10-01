#pragma once

#include "RE/B/BGSCraftableForm.h"

namespace RE
{
	class BGSResearchProjectForm : public BGSCraftableForm
	{
	public:
		SF_RTTI_VTABLE(BGSResearchProjectForm);
		SF_FORMTYPE(RSPJ);

		~BGSResearchProjectForm() override;  // 00

		// members
		BGSKeyword*                       category;          // 98
		BSTArray<BGSResearchProjectForm*> requiredProjects;  // A0
	};
	static_assert(sizeof(BGSResearchProjectForm) == 0xB8);
}
