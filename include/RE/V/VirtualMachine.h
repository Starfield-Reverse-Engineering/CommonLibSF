#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTEvent.h"
#include "RE/E/ErrorLogger.h"
#include "RE/I/IClientVM.h"
#include "RE/I/IVMDebugInterface.h"
#include "RE/I/IVMFunctionMessageDispatch.h"
#include "RE/I/IVMObjectBindInterface.h"
#include "RE/I/IVMRemoteDebuggerInterface.h"
#include "RE/I/IVMSaveLoadInterface.h"
#include "RE/I/IVirtualMachine.h"
#include "RE/L/LinkerProcessor.h"
#include "RE/R/ReadableStringTable.h"
#include "RE/R/ReadableTypeTable.h"
#include "RE/S/SuspendedStack.h"
#include "RE/W/WritableStringTable.h"
#include "RE/W/WritableTypeTable.h"

namespace RE
{
	namespace BSScript
	{
		class Array;
		class ErrorLogger;
		class IFreezeQuery;
		class IProfilePolicy;
		class ISavePatcherInterface;
		class IStackCallbackFunctor;
		class IStackCallbackSaveInterface;
		class ObjectBindPolicy;
		class Stack;
		class IRemoteDebugger;

		struct IMemoryPagePolicy;
		struct IObjectHandlePolicy;
		struct StatsEvent;

		namespace Internal
		{
			class CodeTasklet;

			class VirtualMachine :
				public IVirtualMachine,                    // 0000
				/* IVM -> public BSIntrusiveRefCounted */  // 0008
				public IVMObjectBindInterface,             // 0010
				public IVMSaveLoadInterface,               // 0018
				public IVMDebugInterface,                  // 0020
				public IVMRemoteDebuggerInterface,         // 0028
				public IVMFunctionMessageDispatch,         // 0030
				public BSTEventSource<StatsEvent>          // 0038
			{
			public:
				static constexpr auto RTTI{ RTTI::BSScript__Internal__VirtualMachine };
				static constexpr auto VTABLE{ VTABLE::BSScript__Internal__VirtualMachine };

				enum class FreezeState
				{
					kNotFrozen = 0,
					kFreezing,
					kFrozen
				};

				struct LoadedArrayEntry
				{
				public:
					// members
					BSTSmartPointer<Array> array;      // 00
					std::uint32_t          arraySize;  // 08
				};
				static_assert(sizeof(LoadedArrayEntry) == 0x10);

				struct PendingLatentReturn
				{
				public:
					// members
					std::uint32_t stackID;      // 00
					Variable      returnValue;  // 08
				};
				static_assert(sizeof(PendingLatentReturn) == 0x18);

				struct QueuedUnbindRefs
				{
				public:
					// members
					BSTSmartPointer<Object> obj;       // 00
					std::uint32_t           refCount;  // 08
					std::uint32_t           pad0C;     // 0C
				};
				static_assert(sizeof(QueuedUnbindRefs) == 0x10);

				~VirtualMachine() override;  // 00

				using RE::BSScript::IVirtualMachine::SendEvent;
				//using RE::BSTEventSource<RE::BSScript::StatsEvent>::SendEvent;

			public:
				// override (IVirtualMachine)
				// add
				virtual void                                     SetLoader(ILoader* a_newLoader) override;                                                                                                                                                                                                                                                                       // 01
				virtual void                                     SetLinkedCallback(ITypeLinkedCallback* a_typeLinkedCallback) override;                                                                                                                                                                                                                                          // 02
				virtual void                                     Update(float a_updateBudget) override;                                                                                                                                                                                                                                                                          // 03
				virtual void                                     UpdateTasklets(float a_updateBudget) override;                                                                                                                                                                                                                                                                  // 04
				virtual void                                     Unk_05(void) override;                                                                                                                                                                                                                                                                                          // 05
				virtual void                                     SetOverstressed(bool a_overstressed) override;                                                                                                                                                                                                                                                                  // 06
				virtual void                                     Unk_07(void) override;                                                                                                                                                                                                                                                                                          // 07
				virtual bool                                     IsCompletelyFrozen() const override;                                                                                                                                                                                                                                                                            // 08
				virtual void                                     Unk_09(void) override;                                                                                                                                                                                                                                                                                          // 09
				virtual bool                                     RegisterObjectType(std::uint32_t a_typeID, const char* a_objectTypeName) override;                                                                                                                                                                                                                              // 0A
				virtual bool                                     GetScriptObjectType(std::uint32_t a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_objType) override;                                                                                                                                                                                                               // 0B
				virtual bool                                     GetScriptObjectType(const BSFixedString& a_name, BSTSmartPointer<ObjectTypeInfo>& a_objType) override;                                                                                                                                                                                                          // 0C
				virtual bool                                     GetScriptObjectTypeNoLoad(std::uint32_t a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_objType) const override;                                                                                                                                                                                                   // 0D
				virtual bool                                     GetScriptObjectTypeNoLoad(const BSFixedString& a_objectTypeName, BSTSmartPointer<ObjectTypeInfo>& a_objType) const override;                                                                                                                                                                                    // 0E
				virtual bool                                     GetTypeIDForScriptObject(const BSFixedString& a_objectTypeName, std::uint32_t& a_typeID) const override;                                                                                                                                                                                                        // 0F
				virtual void                                     GetScriptObjectsWithATypeID(BSScrapArray<BSFixedString>& a_objectTypeList) const override;                                                                                                                                                                                                                      // 10
				virtual bool                                     GetParentNativeType(const BSFixedString& a_childTypeName, BSTSmartPointer<ObjectTypeInfo>& a_parentType) override;                                                                                                                                                                                              // 11
				virtual bool                                     TypeIsValid(const BSFixedString& a_objectTypeName) override;                                                                                                                                                                                                                                                    // 12
				virtual bool                                     ReloadType(const char* a_objectTypeName) override;                                                                                                                                                                                                                                                              // 13
				virtual void                                     TasksToJobs(JobList& a_jobList) override;                                                                                                                                                                                                                                                                       // 14
				virtual void                                     CalculateFullReloadList(const /*BSTSet<BSFixedString>&*/ void* a_scriptSet, /*BSTObjectArena<BSFixedString>&*/ void* a_scriptList) const override;                                                                                                                                                              // 15
				virtual bool                                     GetScriptStructType(const BSFixedString& a_structTypeName, BSTSmartPointer<StructTypeInfo>& a_structType) override;                                                                                                                                                                                             // 16
				virtual bool                                     GetScriptStructTypeNoLoad(const BSFixedString& a_structTypeName, BSTSmartPointer<StructTypeInfo>& a_structType) const override;                                                                                                                                                                                 // 17
				virtual bool                                     GetChildStructTypes(const BSFixedString& a_parentObjectName, /*BSTObjectArena<BSFixedString>&*/ void* a_structTypes) const override;                                                                                                                                                                            // 18
				virtual bool                                     CreateObject(const BSFixedString& a_objectTypeName, const /*BSTScrapHashMap<BSFixedString, Variable>&*/ void* a_properties, BSTSmartPointer<Object>& a_newObj) override;                                                                                                                                        // 19
				virtual bool                                     CreateObject(const BSFixedString& a_objectTypeName, BSTSmartPointer<Object>& a_newObj) override;                                                                                                                                                                                                                // 1A
				virtual bool                                     CreateStruct(const BSFixedString& a_structTypeName, BSTSmartPointer<Struct>& a_newStruct) override;                                                                                                                                                                                                             // 1B
				virtual bool                                     CreateArray(TypeInfo::RawType a_elementType, const BSFixedString& a_elementObjectTypeName, std::uint32_t a_elementCount, BSTSmartPointer<Array>& a_newArray) override;                                                                                                                                          // 1C
				virtual bool                                     CreateArray(const TypeInfo& a_type, std::uint32_t a_elementCount, BSTSmartPointer<Array>& a_newArray) override;                                                                                                                                                                                                 // 1D
				virtual bool                                     BindNativeMethod(IFunction* a_function) override;                                                                                                                                                                                                                                                               // 1E
				virtual void                                     SetCallableFromTasklets(const char* a_objectName, const char* a_functionName, bool a_taskletCallable) override;                                                                                                                                                                                                 // 1F
				virtual void                                     SetCallableFromTasklets(const char* a_objectName, const char* a_stateName, const char* a_functionName, bool a_taskletCallable) override;                                                                                                                                                                        // 20
				virtual void                                     ForEachBoundObject(std::uint64_t a_objHandle, const BSTThreadScrapFunction<BSContainer::ForEachResult(Object*)>& a_functor) override;                                                                                                                                                                           // 21
				virtual bool                                     FindBoundObject(std::uint64_t a_objHandle, const char* a_objectTypeName, bool a_allowConst, BSTSmartPointer<Object>& a_attachedObj, bool a_exactMatch) const override;                                                                                                                                          // 22
				virtual void                                     MoveBoundObjects(std::uint64_t a_sourceHandle, std::uint64_t a_destHandle) override;                                                                                                                                                                                                                            // 23
				virtual void                                     ResetAllBoundObjects(std::uint64_t a_objHandle) override;                                                                                                                                                                                                                                                       // 24
				virtual bool                                     CastObject(const BSTSmartPointer<Object>& a_sourceObj, const BSTSmartPointer<ObjectTypeInfo>& a_targetType, BSTSmartPointer<Object>& a_castedObj) override;                                                                                                                                                     // 25
				virtual bool                                     SetPropertyValue(const BSTSmartPointer<Object>& a_self, ...) override;                                                                                                                                                                                                                                          // 26 -- unknown VA args
				virtual bool                                     GetPropertyValue(const BSTSmartPointer<Object>& a_self, const char* a_propName, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) override;                                                                                                                                                 // 27
				virtual bool                                     GetVariableValue(std::uint64_t a_objHandle, const BSFixedString& a_scriptName, std::uint32_t a_varIndex, Variable& a_var) const override;                                                                                                                                                                       // 28
				virtual bool                                     GetVariableValue(const BSTSmartPointer<Object>& a_obj, std::uint32_t a_varIndex, Variable& a_var) const override;                                                                                                                                                                                               // 29
				virtual bool                                     HandleImplementsEvent(std::uint64_t a_object, const BSFixedString& a_eventName) const override;                                                                                                                                                                                                                 // 2A
				virtual bool                                     AddEventRelay(std::uint64_t a_sourceObject, const BSFixedString& a_eventName, const BSTSmartPointer<Object>& a_destObj) override;                                                                                                                                                                               // 2B
				virtual void                                     RemoveEventRelay(std::uint64_t a_sourceObject, const BSFixedString& a_eventName, const BSTSmartPointer<Object>& a_destObj) override;                                                                                                                                                                            // 2C
				virtual void                                     RemoveAllEventRelays(const BSTSmartPointer<Object>& a_destObj) override;                                                                                                                                                                                                                                        // 2D
				virtual void                                     SendEvent(std::uint64_t a_objHandle, const BSFixedString& a_eventName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTThreadScrapFunction<bool(const BSTSmartPointer<Object>&)>& a_filter, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) override;  // 2E
				virtual bool                                     DispatchStaticCall(const BSFixedString& a_objName, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) override;                                                                   // 2F
				virtual bool                                     DispatchMethodCall(std::uint64_t a_objHandle, const BSFixedString& a_objName, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) override;                                        // 30
				virtual bool                                     DispatchMethodCall(const BSTSmartPointer<Object>& a_self, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) override;                                                            // 31
				virtual bool                                     DispatchUnboundMethodCall(std::uint64_t a_objHandle, const BSTSmartPointer<BoundScript>& a_script, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) override;                   // 32
				virtual void                                     ReturnFromLatent(std::uint32_t a_stackID, const Variable& a_retValue) override;                                                                                                                                                                                                                                 // 33 -- IsWaitingOnLatent was removed
				virtual void                                     ReattemptGuardLock(std::uint32_t a_stackID) override;                                                                                                                                                                                                                                                           // 34
				[[nodiscard]] virtual ErrorLogger&               GetErrorLogger() const override;                                                                                                                                                                                                                                                                                // 35
				[[nodiscard]] virtual const IObjectHandlePolicy& GetObjectHandlePolicy() const override;                                                                                                                                                                                                                                                                         // 36
				[[nodiscard]] virtual IObjectHandlePolicy&       GetObjectHandlePolicy() override;                                                                                                                                                                                                                                                                               // 37
				[[nodiscard]] virtual const ObjectBindPolicy&    GetObjectBindPolicy() const override;                                                                                                                                                                                                                                                                           // 38
				[[nodiscard]] virtual ObjectBindPolicy&          GetObjectBindPolicy() override;                                                                                                                                                                                                                                                                                 // 39
				[[nodiscard]] virtual ISavePatcherInterface&     GetSavePatcherInterface() override;                                                                                                                                                                                                                                                                             // 3A
				[[nodiscard]] virtual const GuardDataIFace       GetGlobalGuardDataInterface() const override;                                                                                                                                                                                                                                                                   // 3B
				[[nodiscard]] virtual GuardDataIFace             GetGlobalGuardDataInterface() override;                                                                                                                                                                                                                                                                         // 3C
				virtual void                                     RegisterForLogEvent(BSTEventSink<LogEvent>* a_sink) override;                                                                                                                                                                                                                                                   // 3D
				virtual void                                     UnregisterForLogEvent(BSTEventSink<LogEvent>* a_sink) override;                                                                                                                                                                                                                                                 // 3E
				virtual void                                     RegisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) override;                                                                                                                                                                                                                                               // 3F
				virtual void                                     UnregisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) override;                                                                                                                                                                                                                                             // 40
				virtual void                                     PostCachedErrorToLogger(const ICachedErrorMessage& a_errorFunctor, ErrorLogger::Severity a_severity) const override;                                                                                                                                                                                            // 41
				virtual void                                     PostCachedErrorToLogger(const ICachedErrorMessage& a_errorFunctor, std::uint32_t a_stackID, ErrorLogger::Severity a_severity) const override;                                                                                                                                                                   // 42

				// override (IVMObjectBindInterface)
				[[nodiscard]] virtual std::uint64_t GetBoundHandle(const BSTSmartPointer<Object>& a_objPtr) const override;                                                                   // 01
				virtual void                        TypeCanBeBound(const BSFixedString& a_className, std::uint64_t a_handle) override;                                                        // 02
				virtual void                        BindObject(BSTSmartPointer<Object>& a_objPtr, std::uint64_t a_handle, bool a_conditional) override;                                       // 03
				virtual void                        HandleLoadedBinding(BSTSmartPointer<Object>& a_objPtr, std::uint64_t a_handle, bool a_conditional) override;                              // 04
				virtual void                        RemoveAllBoundObjects(std::uint64_t a_handle) override;                                                                                   // 05
				virtual void                        RemoveAllDiskLoadedBoundObjects(std::uint64_t a_handle) override;                                                                         // 06
				virtual void                        HandleCObjectDeletion(std::uint64_t a_handle) override;                                                                                   // 07
				virtual void                        UnbindObject(const BSTSmartPointer<Object>& a_objPtr) override;                                                                           // 08
				virtual bool                        CreateObjectWithProperties(const BSFixedString& a_className, std::uint32_t a_numProperties, BSTSmartPointer<Object>& a_objPtr) override;  // 09
				virtual bool                        InitObjectProperties(BSTSmartPointer<Object>& a_objPtr, void* a_property, bool a_arg3) override;                                          // 0A

				// override (IVMSaveLoadInterface)
				virtual bool                                 SaveGame(BSStorage& a_storage, IHandleReaderWriter const& a_HandleReaderWriter, bool a_flag) override;                                                         // 01
				virtual bool                                 LoadGame(BSStorage const& a_storage, IHandleReaderWriter const& a_HandleReaderWriter, bool& a_flag, bool& b_flag) override;                                    // 02
				virtual void                                 MarkSaveInvalid(BSStorage& a_storage) override;                                                                                                                // 03
				virtual unsigned short                       GetSaveGameVersion() const override;                                                                                                                           // 04
				virtual void                                 CleanupSave() override;                                                                                                                                        // 05
				virtual void                                 CleanupLoad() override;                                                                                                                                        // 06
				virtual void                                 DropAllRunningData() override;                                                                                                                                 // 07
				virtual std::uint64_t                        GetSaveHandleForObject(const Object* a_Object) const override;                                                                                                 // 08
				virtual void                                 SetSaveHandleForObject(const Object* a_Object, std::uint64_t) override;                                                                                        // 09
				virtual bool                                 GetObjectBySaveHandle(std::uint64_t, const TypeInfo& a_TypeInfo, BSTSmartPointer<Object, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const override;  // 0A
				virtual bool                                 GetObjectBySaveHandle(std::uint64_t, BSTSmartPointer<Object, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const override;                              // 0B
				virtual void                                 unk_0C(void) override;                                                                                                                                         // 0C
				virtual void                                 unk_0D(void) override;                                                                                                                                         // 0D
				virtual std::uint64_t                        GetSaveHandleForStruct(const Struct* a_Struct) const override;                                                                                                 // 0E
				virtual void                                 SetSaveHandleForStruct(const Struct* a_Struct, std::uint64_t) override;                                                                                        // 0F
				virtual bool                                 GetStructBySaveHandle(std::uint64_t, BSTSmartPointer<Struct, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const override;                              // 10
				virtual void                                 unk_11(void) override;                                                                                                                                         // 11
				virtual void                                 unk_12(void) override;                                                                                                                                         // 12
				virtual std::uint64_t                        GetSaveHandleForArray(const Array* a_Array) const override;                                                                                                    // 13
				virtual void                                 SetSaveHandleForArray(const Array* a_Array, std::uint64_t) override;                                                                                           // 14
				virtual bool                                 GetArrayBySaveHandle(std::uint64_t handle, BSTSmartPointer<Array, BSTSmartPointerIntrusiveRefCount>& a_array_pointer) const override;                          // 15
				virtual bool                                 GetStackByID(unsigned int, BSTSmartPointer<Stack, BSTSmartPointerIntrusiveRefCount>& a_stack_pointer) const override;                                          // 16
				virtual bool                                 IsStackRunning(std::uint32_t a_stackid) override;                                                                                                              // 17
				virtual const Internal::WritableStringTable& GetWritableStringTable() const override;                                                                                                                       // 18
				virtual const Internal::WritableStringTable& GetWritableStringTable() override;                                                                                                                             // 19
				virtual Internal::ReadableStringTable&       GetReadableStringTable() const override;                                                                                                                       // 1A
				virtual const Internal::WritableTypeTable&   GetWritableTypeTable() const override;                                                                                                                         // 1B
				virtual Internal::WritableTypeTable&         GetWritableTypeTable() override;                                                                                                                               // 1C
				virtual const Internal::ReadableTypeTable&   GetReadableTypeTable() const override;                                                                                                                         // 1D
				virtual void                                 unk_1E(void) override;                                                                                                                                         // 1E
				virtual bool                                 CreateEmptyTasklet(Stack* a_Stack, BSTSmartPointer<Internal::CodeTasklet, BSTSmartPointerIntrusiveRefCount>& a_tasklet_pointer) override;                      // 1F

				// override (IVMDebugInterface)
				virtual void DumpRunningStacksToLog() override;                                                                                // 01
				virtual void DumpStackFrameToLog(unsigned int a_v, unsigned int b_v, bool a_flag) override;                                    // 02
				virtual void GetStackFrame(unsigned int a_v, unsigned int b_v, bool a_flag, BSFixedString& a_identifier) override;             // 03
				virtual void DumpPersistenceInformationToLog(char const* logfile, uint64_t a_v) const override;                                // 04
				virtual void DumpEventRelayInformationToLog(char const* logfile, uint64_t a_v, BSFixedString const& a_string) const override;  // 05

				// override (IVMRemoteDebuggerInterface)
				virtual bool IsCompletelyFrozen() override;  // 00
				virtual void Unk01() override;               // 01
				virtual void Unk02() override;               // 02

				// override (IVMFunctionMessageDispatch)
				virtual void Unk00() override;  // 00

				static VirtualMachine* GetSingleton();

				//bool StackExists(std::uint32_t stack_id);

				// members
				ErrorLogger*                                                                      errorLogger;                 // 0060
				IMemoryPagePolicy*                                                                memoryPagePolicy;            // 0068
				IObjectHandlePolicy*                                                              handlePolicy;                // 0070
				ObjectBindPolicy*                                                                 objectBindPolicy;            // 0078
				IClientVM*                                                                        clientVM;                    // 0080
				IStackCallbackSaveInterface*                                                      stackCallbackSaveInterface;  // 0088
				IProfilePolicy*                                                                   profilePolicy;               // 0090
				IRemoteDebugger*                                                                  remoteDebugger;              // 0098
				ISavePatcherInterface*                                                            savePatcherInterface;        // 00A0
				GuardDataIFace                                                                    globalGuardDataInterface;    // 00A8
				std::uint64_t                                                                     unk01C0;                     // 01C0 -- 2nd param passed into constructor + 0x10
				mutable BSSpinLock                                                                typeInfoLock;                // 01C8
				LinkerProcessor                                                                   linker;                      // 01D0
				/*BSTHashMap<BSFixedString, BSTSmartPointer<ObjectTypeInfo>>*/ std::byte          objectTypeMap[0x38];         // 0258
				/*BSTHashMap<BSFixedString, BSTSmartPointer<StructTypeInfo>>*/ std::byte          structTypeMap[0x38];         // 0290
				/*BSTHashMap<std::uint32_t, BSFixedString>*/ std::byte                            typeIDToObjectType[0x38];    // 02C8
				/*BSTHashMap<BSFixedString, std::uint32_t>*/ std::byte                            objectTypeToTypeID[0x38];    // 0300
				BSTArray<BSTSmartPointer<ObjectTypeInfo>>                                         typesToUnload;               // 0338
				std::byte                                                                         gap_0348[0x380 - 0x348];     // 0348
				/*BSScript::Internal::FunctionMessageProcessor*/ std::byte                        funcMsgProcessor[0x3C0];     // 0380
				BSTArray<CodeTasklet*>                                                            vmTasks;                     // 0740
				BSNonReentrantSpinLock                                                            vmTasksLock;                 // 0750
				std::uint32_t                                                                     gap_754;                     // 0754
				bool                                                                              overstressed;                // 0758
				std::byte                                                                         gap0759[0x780 - 0x759];      // 0759
				/*BSTCommonStaticMessageQueue<BSScript::Internal::SuspendedStack,128>*/ std::byte suspendQueue1[0x1A80];       // 0780
				/*BSTCommonStaticMessageQueue<BSScript::Internal::SuspendedStack,128>*/ std::byte suspendQueue2[0x1A80];       // 2200
				BSTArray<SuspendedStack>                                                          overflowSuspendArray1;       // 3C80
				BSTArray<SuspendedStack>                                                          overflowSuspendArray2;       // 3C90
				mutable BSSpinLock                                                                suspendQueueLock;            // 3CA0
				/*BSTCommonStaticMessageQueue<BSScript::Internal::SuspendedStack,128>* */ void*   stacksToResume;              // 3CA8 - ref to suspendQueue1
				BSTArray<SuspendedStack>*                                                         stacksToResumeOverflow;      // 3CB0 - ref to overflowSuspendArray1
				/*BSTCommonStaticMessageQueue<BSScript::Internal::SuspendedStack,128>* */ void*   stacksToSuspend;             // 3CB8 - ref to suspendQueue2
				BSTArray<SuspendedStack>*                                                         stacksToSuspendOverflow;     // 3CC0 - ref to overflowSuspendArray2
				mutable BSReadWriteLock                                                           runningStacksLock;           // 3CC8
				/*BSTHashMap<std::uint32_t, BSTSmartPointer<Stack>>*/ std::byte                   allRunningStacks[0x38];      // 3CD0
				BSTArray<uint32_t>                                                                waitingLatentReturns;        // 3D08
				std::uint32_t                                                                     nextStackID;                 // 3D18
				mutable BSSpinLock                                                                frozenStacksLock;            // 3D1C
				std::uint32_t                                                                     gap3D24;                     // 3D24
				BSTArray<msvc::unique_ptr<PendingLatentReturn>>                                   pendingLatentReturns;        // 3D28
				BSTArray<uint32_t>                                                                stacksWaitingOnGuard;        // 3D38
				BSTSmartPointer<BSScript::Stack>                                                  frozenStacksHead;            // 3D48
				std::uint32_t                                                                     frozenStacksCount;           // 3D50
				stl::enumeration<FreezeState, std::uint32_t>                                      freezeState;                 // 3D54
				mutable BSSpinLock                                                                attachedScriptsLock;         // 3D58
				/*BSTHashMap<uint64_t, BSTSmallSharedArray<AttachedScript>>*/ std::byte           attachedScripts[0x38];       // 3D60
				std::uint64_t                                                                     unk3D98;                     // 3D98
				std::uint32_t                                                                     nextObjectToClean;           // 3DA0
				std::uint32_t                                                                     gap3DA4;                     // 3DA4
				std::uint64_t                                                                     nextAttachedObjectToClean;   // 3DA8
				BSTArray<BSTSmartPointer<Object>>                                                 detachedScripts;             // 3DB0
				mutable BSSpinLock                                                                structsLock;                 // 3DC0
				std::uint32_t                                                                     nextStructToClean;           // 3DC8
				BSTArray<BSTSmartPointer<Struct>>                                                 allStructs;                  // 3DD0
				mutable BSSpinLock                                                                arraysLock;                  // 3DE0
				std::uint32_t                                                                     nextArrayToClean;            // 3DE8
				BSTArray<BSTSmartPointer<Array>>                                                  arrays;                      // 3DF0
				mutable BSSpinLock                                                                objectResetLock;             // 3E00
				BSTArray<BSTSmartPointer<Object>>                                                 objectsAwaitingReset;        // 3E08
				mutable BSSpinLock                                                                loadTableLock;               // 3E18
				/*BSTHashMap<std::uint64_t, BSTSmartPointer<Object>>*/ std::byte                  loadTable[0x38];             // 3E20
				/*BSTHashMap<std::uint64_t, std::uint64_t>           */ std::byte                 loadHandlesTable[0x38];      // 3E58
				/*BSTHashMap<std::uint64_t, BSTSmartPointer<Struct>>*/ std::byte                  structLoadTable[0x38];       // 3E90
				/*BSTHashMap<std::uint64_t, LoadedArrayEntry>       */ std::byte                  arrayLoadTable[0x38];        // 3EC8
				std::uint64_t                                                                     unk3F00;                     // 3F00
				mutable BSSpinLock                                                                queuedUnbindLock;            // 3F08
				BSTArray<QueuedUnbindRefs>                                                        queuedUnbinds;               // 3F10
				mutable BSSpinLock                                                                eventRelayLock;              // 3F20
				/* BSTHashMap<std::uint64_t, BSTSmartPointer<EventRelay>>*/ std::byte             eventRelays[0x38];           // 3F28
				std::uint64_t                                                                     unk3F60;                     // 3F60
				std::uint64_t                                                                     unk3F68;                     // 3F68
				std::uint64_t                                                                     unk3F70;                     // 3F70
				std::uint64_t                                                                     unk3F78;                     // 3F78
				std::uint16_t                                                                     currentSaveGameVersion;      // 3F80
				std::uint16_t                                                                     gap3F82;                     // 3F82
				std::uint32_t                                                                     saveObjectCount;             // 3F84
				std::uint32_t                                                                     saveObjectDataCount;         // 3F88
				std::uint32_t                                                                     saveStructCount;             // 3F8C
				std::uint32_t                                                                     saveArrayCount;              // 3F90
				std::uint32_t                                                                     gap3F94;                     // 3F94
				WritableStringTable                                                               writableStringTable;         // 3F98
				ReadableStringTable                                                               readableStringTable;         // 3FB0
				WritableTypeTable                                                                 writableTypeTable;           // 3FC8
				ReadableTypeTable                                                                 readableTypeTable;           // 3FD8
				std::byte                                                                         pad3FE0[0x4040 - 0x3FE0];    // 3FE0
			};
			static_assert(sizeof(VirtualMachine) == 0x4040);
			static_assert(offsetof(VirtualMachine, writableStringTable) == 0x3F98);
			static_assert(offsetof(VirtualMachine, frozenStacksLock) == 0x3D1C);
		}
	}
}
