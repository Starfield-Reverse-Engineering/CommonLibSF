#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/E/ErrorLogger.h"
#include "RE/T/TypeInfo.h"

namespace RE
{
	template <class F>
	using BSTThreadScrapFunction = std::function<F>;

	namespace BSScript
	{
		class Array;
		class BoundScript;
		class ErrorLogger;
		class ICachedErrorMessage;
		class IFunction;
		class ISavePatcherInterface;
		class IStackCallbackFunctor;
		class ITypeLinkedCallback;
		class JobList;
		class Object;
		class ObjectBindPolicy;
		class ObjectTypeInfo;
		class Struct;
		class StructTypeInfo;
		class TypeInfo;
		class Variable;

		struct ILoader;
		struct IObjectHandlePolicy;
		struct LogEvent;
		struct StatsEvent;

		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		class __declspec(novtable) IVirtualMachine :
			public BSIntrusiveRefCounted  // 08
		{
		public:
			SF_RTTI_VTABLE(BSScript__IVirtualMachine);

			struct GlobalGuardData
			{
				std::byte              unk00[0x108];  // 00
				BSNonReentrantSpinLock guardlock;     // 108
			};

			struct GuardDataIFace
			{
				IVirtualMachine* thisVMInterface;  // 000
				GlobalGuardData  globalGuardData;  // 008
			};
			static_assert(sizeof(GuardDataIFace) == 0x118);

			virtual ~IVirtualMachine() = default;  // 00

			// add
			virtual void                                     SetLoader(ILoader* a_newLoader) = 0;                                                                                                                                                                                                                                                                       // 01
			virtual void                                     SetLinkedCallback(ITypeLinkedCallback* a_typeLinkedCallback) = 0;                                                                                                                                                                                                                                          // 02
			virtual void                                     Update(float a_updateBudget) = 0;                                                                                                                                                                                                                                                                          // 03
			virtual void                                     UpdateTasklets(float a_updateBudget) = 0;                                                                                                                                                                                                                                                                  // 04
			virtual void                                     Unk_05(void) = 0;                                                                                                                                                                                                                                                                                          // 05
			virtual void                                     SetOverstressed(bool a_overstressed) = 0;                                                                                                                                                                                                                                                                  // 06
			virtual void                                     Unk_07(void) = 0;                                                                                                                                                                                                                                                                                          // 07
			virtual bool                                     IsCompletelyFrozen() const = 0;                                                                                                                                                                                                                                                                            // 08
			virtual void                                     Unk_09(void) = 0;                                                                                                                                                                                                                                                                                          // 09
			virtual bool                                     RegisterObjectType(std::uint32_t a_typeID, const char* a_objectTypeName) = 0;                                                                                                                                                                                                                              // 0A
			virtual bool                                     GetScriptObjectType(std::uint32_t a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_objType) = 0;                                                                                                                                                                                                               // 0B
			virtual bool                                     GetScriptObjectType(const BSFixedString& a_name, BSTSmartPointer<ObjectTypeInfo>& a_objType) = 0;                                                                                                                                                                                                          // 0C
			virtual bool                                     GetScriptObjectTypeNoLoad(std::uint32_t a_typeID, BSTSmartPointer<ObjectTypeInfo>& a_objType) const = 0;                                                                                                                                                                                                   // 0D
			virtual bool                                     GetScriptObjectTypeNoLoad(const BSFixedString& a_objectTypeName, BSTSmartPointer<ObjectTypeInfo>& a_objType) const = 0;                                                                                                                                                                                    // 0E
			virtual bool                                     GetTypeIDForScriptObject(const BSFixedString& a_objectTypeName, std::uint32_t& a_typeID) const = 0;                                                                                                                                                                                                        // 0F
			virtual void                                     GetScriptObjectsWithATypeID(BSScrapArray<BSFixedString>& a_objectTypeList) const = 0;                                                                                                                                                                                                                      // 10
			virtual bool                                     GetParentNativeType(const BSFixedString& a_childTypeName, BSTSmartPointer<ObjectTypeInfo>& a_parentType) = 0;                                                                                                                                                                                              // 11
			virtual bool                                     TypeIsValid(const BSFixedString& a_objectTypeName) = 0;                                                                                                                                                                                                                                                    // 12
			virtual bool                                     ReloadType(const char* a_objectTypeName) = 0;                                                                                                                                                                                                                                                              // 13
			virtual void                                     TasksToJobs(JobList& a_jobList) = 0;                                                                                                                                                                                                                                                                       // 14
			virtual void                                     CalculateFullReloadList(const /*BSTSet<BSFixedString>&*/ void* a_scriptSet, /*BSTObjectArena<BSFixedString>&*/ void* a_scriptList) const = 0;                                                                                                                                                              // 15
			virtual bool                                     GetScriptStructType(const BSFixedString& a_structTypeName, BSTSmartPointer<StructTypeInfo>& a_structType) = 0;                                                                                                                                                                                             // 16
			virtual bool                                     GetScriptStructTypeNoLoad(const BSFixedString& a_structTypeName, BSTSmartPointer<StructTypeInfo>& a_structType) const = 0;                                                                                                                                                                                 // 17
			virtual bool                                     GetChildStructTypes(const BSFixedString& a_parentObjectName, /*BSTObjectArena<BSFixedString>&*/ void* a_structTypes) const = 0;                                                                                                                                                                            // 18
			virtual bool                                     CreateObject(const BSFixedString& a_objectTypeName, BSTSmartPointer<Object>& a_newObj) = 0;                                                                                                                                                                                                                // 1A
			virtual bool                                     CreateObject(const BSFixedString& a_objectTypeName, const /*BSTScrapHashMap<BSFixedString, Variable>&*/ void* a_properties, BSTSmartPointer<Object>& a_newObj) = 0;                                                                                                                                        // 19 -- this is intended; not the right order, but the compiler appears to swap the two for some reason
			virtual bool                                     CreateStruct(const BSFixedString& a_structTypeName, BSTSmartPointer<Struct>& a_newStruct) = 0;                                                                                                                                                                                                             // 1B
			virtual bool                                     CreateArray(TypeInfo::RawType a_elementType, const BSFixedString& a_elementObjectTypeName, std::uint32_t a_elementCount, BSTSmartPointer<Array>& a_newArray) = 0;                                                                                                                                          // 1C
			virtual bool                                     CreateArray(const TypeInfo& a_type, std::uint32_t a_elementCount, BSTSmartPointer<Array>& a_newArray) = 0;                                                                                                                                                                                                 // 1D
			virtual bool                                     BindNativeMethod(IFunction* a_function) = 0;                                                                                                                                                                                                                                                               // 1E
			virtual void                                     SetCallableFromTasklets(const char* a_objectName, const char* a_functionName, bool a_taskletCallable) = 0;                                                                                                                                                                                                 // 1F
			virtual void                                     SetCallableFromTasklets(const char* a_objectName, const char* a_stateName, const char* a_functionName, bool a_taskletCallable) = 0;                                                                                                                                                                        // 20
			virtual void                                     ForEachBoundObject(std::uint64_t a_objHandle, const BSTThreadScrapFunction<BSContainer::ForEachResult(Object*)>& a_functor) = 0;                                                                                                                                                                           // 21
			virtual bool                                     FindBoundObject(std::uint64_t a_objHandle, const char* a_objectTypeName, bool a_allowConst, BSTSmartPointer<Object>& a_attachedObj, bool a_exactMatch) const = 0;                                                                                                                                          // 22
			virtual void                                     MoveBoundObjects(std::uint64_t a_sourceHandle, std::uint64_t a_destHandle) = 0;                                                                                                                                                                                                                            // 23
			virtual void                                     ResetAllBoundObjects(std::uint64_t a_objHandle) = 0;                                                                                                                                                                                                                                                       // 24
			virtual bool                                     CastObject(const BSTSmartPointer<Object>& a_sourceObj, const BSTSmartPointer<ObjectTypeInfo>& a_targetType, BSTSmartPointer<Object>& a_castedObj) = 0;                                                                                                                                                     // 25
			virtual bool                                     SetPropertyValue(const BSTSmartPointer<Object>& a_self, ...) = 0;                                                                                                                                                                                                                                          // 26 -- unknown VA args
			virtual bool                                     GetPropertyValue(const BSTSmartPointer<Object>& a_self, const char* a_propName, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) = 0;                                                                                                                                                 // 27
			virtual bool                                     GetVariableValue(std::uint64_t a_objHandle, const BSFixedString& a_scriptName, std::uint32_t a_varIndex, Variable& a_var) const = 0;                                                                                                                                                                       // 28
			virtual bool                                     GetVariableValue(const BSTSmartPointer<Object>& a_obj, std::uint32_t a_varIndex, Variable& a_var) const = 0;                                                                                                                                                                                               // 29
			virtual bool                                     HandleImplementsEvent(std::uint64_t a_object, const BSFixedString& a_eventName) const = 0;                                                                                                                                                                                                                 // 2A
			virtual bool                                     AddEventRelay(std::uint64_t a_sourceObject, const BSFixedString& a_eventName, const BSTSmartPointer<Object>& a_destObj) = 0;                                                                                                                                                                               // 2B
			virtual void                                     RemoveEventRelay(std::uint64_t a_sourceObject, const BSFixedString& a_eventName, const BSTSmartPointer<Object>& a_destObj) = 0;                                                                                                                                                                            // 2C
			virtual void                                     RemoveAllEventRelays(const BSTSmartPointer<Object>& a_destObj) = 0;                                                                                                                                                                                                                                        // 2D
			virtual void                                     SendEvent(std::uint64_t a_objHandle, const BSFixedString& a_eventName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTThreadScrapFunction<bool(const BSTSmartPointer<Object>&)>& a_filter, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) = 0;  // 2E
			virtual bool                                     DispatchStaticCall(const BSFixedString& a_objName, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) = 0;                                                                   // 2F
			virtual bool                                     DispatchMethodCall(std::uint64_t a_objHandle, const BSFixedString& a_objName, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) = 0;                                        // 30
			virtual bool                                     DispatchMethodCall(const BSTSmartPointer<Object>& a_self, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) = 0;                                                            // 31
			virtual bool                                     DispatchUnboundMethodCall(std::uint64_t a_objHandle, const BSTSmartPointer<BoundScript>& a_script, const BSFixedString& a_funcName, const BSTThreadScrapFunction<bool(BSScrapArray<Variable>&)>& a_arguments, const BSTSmartPointer<IStackCallbackFunctor>& a_callback, int a_unk0) = 0;                   // 32
			virtual void                                     ReturnFromLatent(std::uint32_t a_stackID, const Variable& a_retValue) = 0;                                                                                                                                                                                                                                 // 33 -- IsWaitingOnLatent was removed
			virtual void                                     ReattemptGuardLock(std::uint32_t a_stackID) = 0;                                                                                                                                                                                                                                                           // 34
			[[nodiscard]] virtual ErrorLogger&               GetErrorLogger() const = 0;                                                                                                                                                                                                                                                                                // 35
			[[nodiscard]] virtual const IObjectHandlePolicy& GetObjectHandlePolicy() const = 0;                                                                                                                                                                                                                                                                         // 36
			[[nodiscard]] virtual IObjectHandlePolicy&       GetObjectHandlePolicy() = 0;                                                                                                                                                                                                                                                                               // 37
			[[nodiscard]] virtual const ObjectBindPolicy&    GetObjectBindPolicy() const = 0;                                                                                                                                                                                                                                                                           // 38
			[[nodiscard]] virtual ObjectBindPolicy&          GetObjectBindPolicy() = 0;                                                                                                                                                                                                                                                                                 // 39
			[[nodiscard]] virtual ISavePatcherInterface&     GetSavePatcherInterface() = 0;                                                                                                                                                                                                                                                                             // 3A
			[[nodiscard]] virtual const GuardDataIFace       GetGlobalGuardDataInterface() const = 0;                                                                                                                                                                                                                                                                   // 3B
			[[nodiscard]] virtual GuardDataIFace             GetGlobalGuardDataInterface() = 0;                                                                                                                                                                                                                                                                         // 3C
			virtual void                                     RegisterForLogEvent(BSTEventSink<LogEvent>* a_sink) = 0;                                                                                                                                                                                                                                                   // 3D
			virtual void                                     UnregisterForLogEvent(BSTEventSink<LogEvent>* a_sink) = 0;                                                                                                                                                                                                                                                 // 3E
			virtual void                                     RegisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) = 0;                                                                                                                                                                                                                                               // 3F
			virtual void                                     UnregisterForStatsEvent(BSTEventSink<StatsEvent>* a_sink) = 0;                                                                                                                                                                                                                                             // 40
			virtual void                                     PostCachedErrorToLogger(const ICachedErrorMessage& a_errorFunctor, ErrorLogger::Severity a_severity) const = 0;                                                                                                                                                                                            // 41
			virtual void                                     PostCachedErrorToLogger(const ICachedErrorMessage& a_errorFunctor, std::uint32_t a_stackID, ErrorLogger::Severity a_severity) const = 0;                                                                                                                                                                   // 42

			template <class F>
			void BindNativeMethod(
				stl::zstring        a_object,
				stl::zstring        a_function,
				F                   a_func,
				std::optional<bool> a_taskletCallable,
				bool                a_isLatent);

			void PostError(std::string_view a_msg, std::uint32_t a_stackID, ErrorLogger::Severity a_severity)
			{
				class ErrorImpl :
					public ICachedErrorMessage
				{
				public:
					ErrorImpl(std::string_view a_message) noexcept :
						_message(a_message)
					{}

					void GetErrorMsg(BSFixedString& a_message) const override { a_message = _message; }

				private:
					std::string_view _message;
				};

				const ErrorImpl e{ a_msg };
				PostCachedErrorToLogger(e, a_stackID, a_severity);
			}
		};
		static_assert(sizeof(IVirtualMachine) == 0x10);
	}
}
