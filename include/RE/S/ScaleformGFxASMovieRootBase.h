#pragma once

namespace RE::Scaleform
{
	template <class>
	class ArrayPOD;

	class Log;
	class String;

	namespace Render::Text
	{
		class Allocator;
	}
}

namespace RE::Scaleform::GFx
{
	class AccelerometerEvent;
	class AmpMovieObjectDesc;
	class AppLifecycleEvent;
	class ASString;
	class ASStringManager;
	class DisplayObjContainer;
	class DisplayObject;
	class EventId;
	class GeolocationEvent;
	class InputEventsQueueEntry;
	class InteractiveObject;
	class LoadStates;
	class LoadQueueEntry;
	class MemoryContext;
	class MemoryHeap;
	class MouseState;
	class MovieDefImpl;
	class MovieDefRootNode;
	class MovieImpl;
	class OrientationEvent;

	struct ProcessFocusKeyInfo;

	enum class FocusMovedType;

	class ASMovieRootBase
	{
	public:
		SF_RTTI_VTABLE(Scaleform__GFx__ASMovieRootBase);

		virtual ~ASMovieRootBase() = default;  // 00

		// add
		virtual void                     SetMovie(MovieImpl* a_movie);                                                                                                                                                                           // 01
		virtual void                     AdvanceFrame(bool a_nextFrame) = 0;                                                                                                                                                                     // 02
		virtual void                     ChangeMouseCursorType(std::uint32_t a_mouseIndex, std::uint32_t a_newCursorType) = 0;                                                                                                                   // 03
		virtual bool                     CheckAvm() = 0;                                                                                                                                                                                         // 04
		virtual void                     ClearDisplayList() = 0;                                                                                                                                                                                 // 05
		virtual MovieDefRootNode*        CreateMovieDefRootNode(MemoryHeap* a_heap, MovieDefImpl* a_defImpl, bool a_importFlag) = 0;                                                                                                             // 06
		virtual void                     DoActions() = 0;                                                                                                                                                                                        // 07
		virtual InteractiveObject*       FindTarget(const ASString& a_path) const = 0;                                                                                                                                                           // 08
		virtual void                     ForceCollect() = 0;                                                                                                                                                                                     // 09
		virtual void                     ForceEmergencyCollect() = 0;                                                                                                                                                                            // 0A
		virtual void                     SuspendGC() = 0;                                                                                                                                                                                        // 0B
		virtual void                     ScheduleGC() = 0;                                                                                                                                                                                       // 0C
		virtual void                     GenerateMouseEvents(std::uint32_t a_mouseIndex) = 0;                                                                                                                                                    // 0D
		virtual void                     GenerateTouchEvents(std::uint32_t a_mouseStateIndex);                                                                                                                                                   // 0E
		virtual void                     GenerateGestureEvents(void);                                                                                                                                                                            // 0F
		virtual DisplayObjContainer*     GetRootMovie(DisplayObject* a_dobj = nullptr) const = 0;                                                                                                                                                // 10
		virtual bool                     Init(MovieDefImpl* a_movieDef) = 0;                                                                                                                                                                     // 11
		virtual void                     NotifyMouseEvent(const InputEventsQueueEntry* a_qe, const MouseState& a_ms, std::int32_t a_mi) = 0;                                                                                                     // 12
		virtual void                     NotifyOnResize() = 0;                                                                                                                                                                                   // 13
		virtual void                     NotifyQueueSetFocus(InteractiveObject* a_ch, std::uint32_t a_controllerIndex, FocusMovedType a_fmt) = 0;                                                                                                // 14
		virtual void                     NotifyTransferFocus(InteractiveObject* a_curFocused, InteractiveObject* a_newFocus, std::uint32_t a_controllerIndex) = 0;                                                                               // 15
		virtual bool                     NotifyOnFocusChange(InteractiveObject* a_curFocused, InteractiveObject* a_toBeFocused, std::uint32_t a_controllerIndex, FocusMovedType a_fmt, ProcessFocusKeyInfo* a_focusKeyInfo = nullptr) = 0;       // 16
		virtual void                     NotifyGamePadAnalogEvent(const EventId* a_id);                                                                                                                                                          // 17
		virtual void                     NotifyStatusEvent(const EventId* a_id);                                                                                                                                                                 // 18
		virtual void                     NotifyAccelerometerEvent(const EventId* a_id, std::int32_t a_evtIDAcc);                                                                                                                                 // 19
		virtual void                     NotifyGeolocationEvent(const EventId* a_id, std::int32_t a_evtIDGeo);                                                                                                                                   // 1A
		virtual void                     OnMovieFocus(bool a_set) = 0;                                                                                                                                                                           // 1B
		virtual void                     OnNextFrame() = 0;                                                                                                                                                                                      // 1C
		virtual void                     OnDeviceOrientationChanged(const OrientationEvent&);                                                                                                                                                    // 1D
		virtual void                     OnAppLifecycleEvent(const AppLifecycleEvent&);                                                                                                                                                          // 1E
		virtual void                     OnAccelerometerEvent(const AccelerometerEvent&);                                                                                                                                                        // 1F
		virtual void                     OnGeolocationEvent(const GeolocationEvent&);                                                                                                                                                            // 20
		virtual void                     PrintObjectsReport(std::uint32_t a_flags = 0, Log* a_log = nullptr, const char* a_swfName = nullptr);                                                                                                   // 21
		virtual void                     GetObjectsTree(/* Array<Ptr<AmpMovieObjectDesc>>* */ void* a_rootObjects, MemoryHeap* a_heap);                                                                                                          // 22
		virtual AmpMovieObjectDesc*      GetDisplayObjectsTree(MemoryHeap* a_heap);                                                                                                                                                              // 23
		virtual void                     ProcessLoadQueueEntry(LoadQueueEntry* a_entry, LoadStates* a_ls) = 0;                                                                                                                                   // 24
		virtual void                     ProcessLoadVarsMT(LoadQueueEntry* a_entry, LoadStates* a_ls, const String& a_data, std::size_t a_fileLen, bool a_succeeded) = 0;                                                                        // 25
		virtual void                     ProcessLoadBinaryMT(LoadQueueEntry* a_entry, LoadStates* a_ls, const ArrayPOD<std::byte>& a_data, std::size_t a_fileLen, bool a_succeeded);                                                             // 26
		virtual void                     RegisterAuxASClasses() = 0;                                                                                                                                                                             // 27
		virtual void                     ResolveStickyVariables(InteractiveObject* a_character) = 0;                                                                                                                                             // 28
		virtual void                     SetExternalInterfaceRetVal(const Value&) = 0;                                                                                                                                                           // 29
		virtual void                     SetMemoryParams(std::uint32_t a_frameBetweenCollections, std::uint32_t a_maxRootCount) = 0;                                                                                                             // 2A
		virtual void                     Shutdown() = 0;                                                                                                                                                                                         // 2B
		virtual void                     CreateString(Value* a_value, const char* a_string) = 0;                                                                                                                                                 // 2C
		virtual void                     CreateStringW(Value* a_value, const wchar_t* a_string) = 0;                                                                                                                                             // 2D
		virtual void                     CreateObject(Value* a_value, const char* a_className = nullptr, const Value* a_args = nullptr, std::uint32_t a_numArgs = 0) = 0;                                                                        // 2E
		virtual void                     CreateArray(Value* a_value) = 0;                                                                                                                                                                        // 2F
		virtual void                     CreateFunction(Value* a_value, FunctionHandler* a_fc, void* a_userData = nullptr) = 0;                                                                                                                  // 30
		virtual bool                     SetVariable(const char* a_pathToVar, const Value& a_value, Movie::SetVarType a_setType = Movie::SetVarType::kSticky) = 0;                                                                               // 31
		virtual bool                     GetVariable(Value* a_val, const char* a_pathToVar) const = 0;                                                                                                                                           // 32
		virtual bool                     SetVariableArray(Movie::SetArrayType a_type, const char* a_pathToVar, std::uint32_t a_index, const void* a_data, std::uint32_t a_count, Movie::SetVarType a_setType = Movie::SetVarType::kSticky) = 0;  // 33
		virtual bool                     SetVariableArraySize(const char* a_pathToVar, std::uint32_t a_count, Movie::SetVarType a_setType = Movie::SetVarType::kSticky) = 0;                                                                     // 35
		virtual std::uint32_t            GetVariableArraySize(const char* a_pathToVar) = 0;                                                                                                                                                      // 34
		virtual bool                     GetVariableArray(Movie::SetArrayType a_type, const char* a_pathToVar, std::uint32_t a_index, void* a_data, std::uint32_t a_count) = 0;                                                                  // 36
		virtual bool                     IsAvailable(const char* a_pathToVar) const = 0;                                                                                                                                                         // 37
		virtual bool                     Invoke(const char* a_pathToMethod, Value* a_result, const Value* a_args, std::uint32_t a_numArgs) = 0;                                                                                                  // 39
		virtual bool                     Invoke(const char* a_pathToMethod, Value* a_result, const char* a_argFmt, ...) = 0;                                                                                                                     // 38
		virtual bool                     InvokeArgs(const char* a_pathToMethod, Value* a_result, const char* a_argFmt, std::va_list a_args) = 0;                                                                                                 // 3A
		virtual MemoryContext*           GetMemoryContext() const = 0;                                                                                                                                                                           // 3B
		virtual ASStringManager*         GetStringManager() const = 0;                                                                                                                                                                           // 3C
		virtual Render::Text::Allocator* GetTextAllocator() = 0;                                                                                                                                                                                 // 3D
		virtual void                     BroadcastGeolocationStatusEvent(const EventId* a_id) = 0;                                                                                                                                               // 3E
	};
}
