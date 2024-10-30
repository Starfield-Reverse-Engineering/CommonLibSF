#pragma once

#include "RE/I/IMenu.h"
#include "RE/S/ScaleformGFxASMovieRootBase.h"

namespace RE
{
	class HUDModeType
	{
	public:
		HUDModeType(const char* a_str) :
			str(a_str)
		{}

		// members
		BSFixedString str;
	};

	class GameMenuBase :
		public IMenu  // 00
	{
	public:
		static constexpr const char* CODE_OBJ_NAME{ "BGSCodeObj" };
		static constexpr const char* ON_CODE_OBJ_CREATED_FUNC{ "onCodeObjCreate" };

		SF_RTTI_VTABLE(GameMenuBase);

		GameMenuBase()
		{
			using func_t = GameMenuBase* (*)(GameMenuBase*);
			static REL::Relocation<func_t> func{ ID::GameMenuBase::Ctor };
			func(this);
		}

		virtual ~GameMenuBase() = default;  // 00

		//override
		virtual std::uint64_t Unk10() override
		{
			using func_t = decltype(&GameMenuBase::Unk10);
			static REL::Relocation<func_t> func(REL::ID(141505));
			return func(this);
		};

		virtual std::uint64_t Unk11() override
		{
			using func_t = decltype(&GameMenuBase::Unk11);
			static REL::Relocation<func_t> func(REL::ID(141506));
			return func(this);
		};

		//add
		virtual bool Unk1B() { return true; }  //1B

		//custom add

		//Do not set this to true unless your menu SWF has Beth's AS3 event backend.
		//Otherwise, it will cause a CTD.
		virtual bool UseEventDispatcher()
		{
			return false;
		}

		//custom override
		virtual bool LoadMovie(bool a_addEventDispatcher, bool a_arg2) override
		{
			a_addEventDispatcher = UseEventDispatcher();
			bool result = IMenu::LoadMovie(a_addEventDispatcher, a_arg2);
			if (result && !a_addEventDispatcher && uiMovie && uiMovie->asMovieRoot) {
				uiMovie->asMovieRoot->GetVariable(&menuObj, GetRootPath());
				if (menuObj.IsObject() && menuObj.HasMember(CODE_OBJ_NAME)) {
					MapCodeObjectFunctions();
					menuObj.Invoke(ON_CODE_OBJ_CREATED_FUNC);
				}
			}
			return result;
		}

		void RegisterNativeFunction(const char* a_name, std::uint64_t a_idx)
		{
			if (!uiMovie) {
				return;
			}

			RE::Scaleform::GFx::Value codeObjVal;
			menuObj.GetMember(CODE_OBJ_NAME, &codeObjVal);
			if (!codeObjVal.IsObject()) {
				return;
			}

			RE::Scaleform::GFx::Value funcVal;
			uiMovie->asMovieRoot->CreateFunction(&funcVal, this, reinterpret_cast<void*>(a_idx));
			codeObjVal.SetMember(a_name, funcVal);
		}
	};
}
