#pragma once

namespace RE
{
	class UI
	{
	public:
		inline static UI* GetSingleton()
		{
			static REL::Relocation<UI**> singleton{ REL::ID(878339) };
			return *singleton;
		}

		bool IsMenuOpen(const BSFixedString& a_name)
		{
			using func_t = decltype(&UI::IsMenuOpen);
			REL::Relocation<func_t> func{ REL::ID(187049) };
			return func(this, a_name);
		}
	};
}
