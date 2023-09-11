#pragma once

namespace RE
{
	class Setting
	{
	public:
		SF_RTTI_VTABLE(Setting);

		enum class Type
		{
			kUnknown = 0,
			kInteger,
			kFloat,
			kString,
			kBool,
			kID6,
			kID
		};

		virtual ~Setting();

		union Data
		{
			std::uint32_t u32;
			std::int32_t  s32;
			float         f32;
			std::uint8_t  u8;  // used for bool
			char*         s;
		};
		static_assert(sizeof(Data) == 0x8);

		stl::enumeration<Type, std::uint32_t> GetType(void) const;
		bool                                  GetDouble(double* a_out) const;
		bool                                  SetDouble(double a_value);
		bool                                  SetString(const char* a_value);

		// member
		Data  data;         // 08
		Data  defaultData;  // 10
		char* name;         // 18
	};
	static_assert(sizeof(Setting) == 0x20);

	template <typename T>
	class SettingT :
		public Setting
	{
	public:
		virtual ~SettingT();

		static REL::Relocation<T*> collection;
	};

	class GameSettingCollection;
	class INIPrefSettingCollection;
	class INISettingCollection;
	class RegSettingCollection;

	extern template class SettingT<GameSettingCollection>;
	extern template class SettingT<INIPrefSettingCollection>;
	extern template class SettingT<INISettingCollection>;
	extern template class SettingT<RegSettingCollection>;
}
