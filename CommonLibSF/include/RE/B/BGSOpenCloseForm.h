#pragma once

namespace RE
{
	class TESObjectREFR;

	class BGSOpenCloseForm
	{
	public:
		SF_RTTI(BGSOpenCloseForm);

		virtual ~BGSOpenCloseForm();  // 00

		// add
		virtual void HandleOpenStart(TESObjectREFR* a_target, TESObjectREFR* a_activator, bool a_arg3);   // 01
		virtual void HandleCloseStart(TESObjectREFR* a_target, TESObjectREFR* a_activator, bool a_arg3);  // 02
		virtual void HandleOpenFinish(TESObjectREFR* a_target, TESObjectREFR* a_activator);               // 03
		virtual void HandleCloseFinish(TESObjectREFR* a_target, TESObjectREFR* a_activator);              // 04
	};
	static_assert(sizeof(BGSOpenCloseForm) == 0x8);
}
