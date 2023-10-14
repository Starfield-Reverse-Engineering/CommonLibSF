#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSTEvent.h"
#include "RE/S/SWFToCodeFunctionHandler.h"
#include "RE/S/ScaleformGFxMovie.h"
#include "RE/S/ScaleformGFxValue.h"

namespace RE
{
	struct UpdateSceneRectEvent;

	class IMenu :
		public SWFToCodeFunctionHandler,           // 00
		public BSInputEventUser,                   // 10
		public BSTEventSink<UpdateSceneRectEvent>  // 50
	{
	public:
		SF_RTTI_VTABLE(IMenu);

		virtual ~IMenu() = default;  // 00

		// add
		virtual const char* GetName() const;                                    // 03
		virtual const char* GetRootPath() const;                                // 04
		virtual void        Unk_05(void);                                       // 05
		virtual void        Unk_06(void);                                       // 06
		virtual bool        LoadMovie(bool a_addEventDispatcher, bool a_arg2);  // 07
		virtual void        Unk_08(void);                                       // 08
		virtual void        Unk_09(void);                                       // 09
		virtual void        Unk_0A(void);                                       // 0A
		virtual void        Unk_0B(void);                                       // 0B
		virtual void        Unk_0C(void);                                       // 0C
		virtual void        Unk_0D(void);                                       // 0D
		virtual void        Unk_0E(void);                                       // 0E
		virtual void        Unk_0F(void);                                       // 0F
		virtual void        Unk_10(void);                                       // 10
		virtual void        Unk_11(void);                                       // 11
		virtual void        Unk_12(void);                                       // 12
		virtual void        Unk_13(void);                                       // 13
		virtual void        Unk_14(void);                                       // 14
		virtual void        Unk_15(void);                                       // 15
		virtual void        Unk_16(void);                                       // 16
		virtual void        Unk_17(void);                                       // 17
		virtual void        Unk_18(void);                                       // 18
		virtual void        Unk_19(void);                                       // 19
		virtual void        Unk_1A(void);                                       // 1A

		Scaleform::GFx::Value                 menuObj;   // 058
		Scaleform::Ptr<Scaleform::GFx::Movie> uiMovie;   // 088
		std::uint64_t                         unk090;    // 090
		std::uint64_t                         unk098;    // 098
		std::uint64_t                         unk0A0;    // 0A0
		std::uint32_t                         unk0A8;    // 0A8
		std::uint32_t                         unk0AC;    // 0AC
		BSFixedString                         menuName;  // 0B0
		BSFixedString                         unk0B8;    // 0B8
		std::uint64_t                         unk0C0;    // 0C0
		std::uint32_t                         unk0C8;    // 0C8
		std::uint32_t                         unk0CC;    // 0CC
		std::uint32_t                         unk0D0;    // 0D0
		std::uint32_t                         unk0D4;    // 0D4
		std::uint64_t                         unk0D8;    // 0D8
		std::uint64_t                         unk0E0;    // 0E0
		std::uint64_t                         unk0E8;    // 0E8
		std::uint64_t                         unk0F0;    // 0F0
		std::uint64_t                         unk0F8;    // 0F8
		std::uint64_t                         unk100;    // 100
		std::uint32_t                         unk108;    // 108
		std::uint32_t                         unk10C;    // 10C
		std::uint64_t                         unk110;    // 110
		std::uint64_t                         unk118;    // 118
		std::uint64_t                         unk120;    // 120
		std::uint64_t                         unk128;    // 128
	};
	static_assert(offsetof(IMenu, uiMovie) == 0x088);
	static_assert(offsetof(IMenu, menuName) == 0x0B0);
}
