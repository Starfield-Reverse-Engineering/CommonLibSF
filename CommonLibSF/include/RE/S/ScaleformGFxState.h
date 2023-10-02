#pragma once

#include "RE/S/ScaleformRefCount.h"

namespace RE::Scaleform::GFx
{
	class State :
		public RefCountBase<State, 2>  // 00
	{
	public:
		SF_RTTI_VTABLE(Scaleform__GFx__State);

		virtual ~State() = default;  // 00

		enum class StateType : std::int32_t
		{
			kNone,
			kTranslator,
			kLog,
			kActionControl,
			kUserEventHandler,
			kFSCommandHandler,
			kExternalInterface,
			//kMultitouchInterface, ?
			//kVirtualKeyboardInterface, ?
			kFileOpener,
			kURLBuilder,
			kImageCreator,
			kImageFileHandlerRegistry,
			kParseControl,
			kProgressHandler,
			kImportVisitor,
			kFontPackParams,
			kFontLib,
			kFontProvider,
			kFontMap,
			kTaskManager,
			kTextClipboard,
			kTextKeyMap,
			kIMEManager,
			kXMLSupport,
			kZlibSupport,
			kFontCompactorParams,
			kImagePackerParams,
			kAudio,
			kVideo,
			kTestStream,
			kSharedObject,
			kLocSupport,
			kAS2Support,
			kAS3Support
		};

		[[nodiscard]] constexpr auto GetStateType() const noexcept
		{
			return *stateType;
		}

	protected:
		// members
		stl::enumeration<StateType, std::int32_t> stateType;
	};
	static_assert(sizeof(State) == 0x18);
}
