#pragma once

namespace RE
{
	class Setting
	{
	public:
		TES_RTTI_VTABLE(Setting);

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
}

