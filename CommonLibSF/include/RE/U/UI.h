namespace RE
{
	class UI
	{
	public:
		inline static UI* GetSingleton()
		{
			static REL::Relocation<UI**> singleton{ REL::Offset(0x056EE0D0) };
			return *singleton;
		}

		bool IsMenuOpen(const BSFixedString& a_name)
		{
			using func_t = decltype(&UI::IsMenuOpen);
			REL::Relocation<func_t> func{ REL::Offset(0x02E7095C) };
			return func(this, a_name);
		}
	};

}
