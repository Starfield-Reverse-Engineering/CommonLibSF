#pragma once

#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSStorage;

	namespace BSScript
	{
		class Object;
		class Array;
		class TypeInfo;
		class Stack;
		class Struct;

		struct IHandleReaderWriter;

		namespace Internal
		{
			class ReadableStringTable;
			class ReadableTypeTable;
			class WritableStringTable;
			class WritableTypeTable;
			class CodeTasklet;
		}

		class __declspec(novtable) IVMSaveLoadInterface
		{
		public:
			SF_RTTI_VTABLE(BSScript__IVMSaveLoadInterface);

			virtual ~IVMSaveLoadInterface();  // 00

			virtual bool                                 SaveGame(BSStorage& a_storage, IHandleReaderWriter const& a_HandleReaderWriter, bool a_flag) = 0;                                                         // 01
			virtual bool                                 LoadGame(BSStorage const& a_storage, IHandleReaderWriter const& a_HandleReaderWriter, bool& a_flag, bool& b_flag) = 0;                                    // 02
			virtual void                                 MarkSaveInvalid(BSStorage& a_storage) = 0;                                                                                                                // 03
			virtual unsigned short                       GetSaveGameVersion() const = 0;                                                                                                                           // 04
			virtual void                                 CleanupSave() = 0;                                                                                                                                        // 05
			virtual void                                 CleanupLoad() = 0;                                                                                                                                        // 06
			virtual void*                                DropAllRunningData() = 0;                                                                                                                                 // 07
			virtual std::uint64_t                        GetSaveHandleForObject(const Object* a_Object) const = 0;                                                                                                 // 08
			virtual void                                 SetSaveHandleForObject(const Object* a_Object, std::uint64_t) = 0;                                                                                        // 09
			virtual bool                                 GetObjectBySaveHandle(std::uint64_t, const TypeInfo& a_TypeInfo, BSTSmartPointer<Object, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const = 0;  // 0A
			virtual bool                                 GetObjectBySaveHandle(std::uint64_t, BSTSmartPointer<Object, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const = 0;                              // 0B
			virtual void                                 unk_0C(void) = 0;                                                                                                                                         // 0C
			virtual void                                 unk_0D(void) = 0;                                                                                                                                         // 0D
			virtual std::uint64_t                        GetSaveHandleForStruct(const Struct* a_Struct) const = 0;                                                                                                 // 0E
			virtual void                                 SetSaveHandleForStruct(const Struct* a_Struct, std::uint64_t) = 0;                                                                                        // 0F
			virtual bool                                 GetStructBySaveHandle(std::uint64_t, BSTSmartPointer<Struct, BSTSmartPointerIntrusiveRefCount>& a_object_pointer) const = 0;                              // 10
			virtual void                                 unk_11(void) = 0;                                                                                                                                         // 11
			virtual void                                 unk_12(void) = 0;                                                                                                                                         // 12
			virtual std::uint64_t                        GetSaveHandleForArray(const Array* a_Array) const = 0;                                                                                                    // 13
			virtual void                                 SetSaveHandleForArray(const Array* a_Array, std::uint64_t) = 0;                                                                                           // 14
			virtual bool                                 GetArrayBySaveHandle(std::uint64_t handle, BSTSmartPointer<Array, BSTSmartPointerIntrusiveRefCount>& a_array_pointer) const = 0;                          // 15
			virtual bool                                 GetStackByID(unsigned int, BSTSmartPointer<Stack, BSTSmartPointerIntrusiveRefCount>& a_stack_pointer) const = 0;                                          // 16
			virtual bool                                 IsStackRunning(std::uint32_t a_stackid) = 0;                                                                                                              // 17
			virtual const Internal::WritableStringTable& GetWritableStringTable() const = 0;                                                                                                                       // 18
			virtual const Internal::WritableStringTable& GetWritableStringTable() = 0;                                                                                                                             // 19
			virtual Internal::ReadableStringTable&       GetReadableStringTable() const = 0;                                                                                                                       // 1A
			virtual const Internal::WritableTypeTable&   GetWritableTypeTable() const = 0;                                                                                                                         // 1B
			virtual Internal::WritableTypeTable&         GetWritableTypeTable() = 0;                                                                                                                               // 1C
			virtual const Internal::ReadableTypeTable&   GetReadableTypeTable() const = 0;                                                                                                                         // 1D
			virtual void                                 unk_1E(void) = 0;                                                                                                                                         // 1E
			virtual bool                                 CreateEmptyTasklet(Stack* a_Stack, BSTSmartPointer<Internal::CodeTasklet, BSTSmartPointerIntrusiveRefCount>& a_tasklet_pointer) = 0;                      // 1F
		};
		static_assert(sizeof(IVMSaveLoadInterface) == 0x8);
	}
}
