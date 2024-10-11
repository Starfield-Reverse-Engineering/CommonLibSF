#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/IDs.h"

namespace RE
{
	class BSStorage;

	namespace BSScript
	{
		class BoundScript;  // stub
		class IVirtualMachine;
		class Object;
		class Variable;
		class MergedBoundScript
		{
		public:
			// members
			BSTSmartPointer<BoundScript> childScript;   // 00
			BSTSmartPointer<BoundScript> parentScript;  // 08
		};
		static_assert(sizeof(MergedBoundScript) == 0x10);

		struct IHandleReaderWriter;
		struct IVMObjectBindInterface;

		namespace UnlinkedTypes
		{
			struct Object;  // stub
		}

		class ObjectBindPolicy
		{
		public:
			SF_RTTI_VTABLE(BSScript__ObjectBindPolicy);

			virtual ~ObjectBindPolicy();  // 00

			// add
			virtual void          EnsureBaseDataLoaded(std::size_t a_objHandle) = 0;                                                                                                                                                                                     // 01
			virtual void          ObjectNoLongerNeeded(std::size_t a_objHandle) = 0;                                                                                                                                                                                     // 02
			virtual void          AddBoundInfoImpl(std::size_t a_objHandle) = 0;                                                                                                                                                                                         // 03
			virtual void          ClearBoundInfoImpl(std::size_t a_objHandle) = 0;                                                                                                                                                                                       // 04
			virtual void          ClearDiskLoadedBoundInfoImpl(std::size_t a_objHandle) = 0;                                                                                                                                                                             // 05
			virtual void          ClearAllBoundInfoImpl() = 0;                                                                                                                                                                                                           // 06
			virtual void          PostBindObject(std::size_t a_objHandle) = 0;                                                                                                                                                                                           // 07
			virtual std::uint32_t GetExtraInfoSize(std::size_t) const = 0;                                                                                                                                                                                               // 08
			virtual void          WriteExtraInfo(std::size_t, const IHandleReaderWriter&, BSStorage&) const = 0;                                                                                                                                                         // 09
			virtual void          ReadExtraInfo(std::size_t a_objHandle, std::uint16_t a_handleVersion, const IHandleReaderWriter& a_handleReaderWriter, const BSStorage& a_storage) = 0;                                                                                // 0A
			virtual bool          IsIgnoringClear() const = 0;                                                                                                                                                                                                           // 0B
			virtual void          ResolveProperties(std::size_t a_objTarget, const BSTSmartPointer<Object>& a_object, const MergedBoundScript& a_boundScript, bool a_postSaveConstOnly) = 0;                                                                             // 0C
			virtual void          ResolveProperties(std::size_t a_objTarget, const BSTSmartPointer<Object>& a_object, const BSTSmartPointer<BoundScript>& a_boundScript, bool a_postSaveConstOnly) = 0;                                                                  // 0D
			virtual void          ConvertProperties(std::size_t a_objTarget, const MergedBoundScript& a_mergedScript, bool a_constOnly, /*BSTScrapHashMap<BSFixedString, Variable>&*/ void* a_properties, std::uint32_t& a_nonConvertedProperties) const = 0;            // 0E
			virtual void          ConvertProperties(std::size_t a_objTarget, const BSTSmartPointer<BoundScript>& a_boundScript, bool a_constOnly, /*BSTScrapHashMap<BSFixedString, Variable>&*/ void* a_properties, std::uint32_t& a_nonConvertedProperties) const = 0;  // 0F

			void BindObject(const BSTSmartPointer<Object>& a_obj, std::size_t a_objHandle)
			{
				using func_t = decltype(&ObjectBindPolicy::BindObject);
				static REL::Relocation<func_t> func{ ID::BSScript::ObjectBindPolicy::BindObject };
				return func(this, a_obj, a_objHandle);
			}

			// TODO: Need to find UnbindObject(), all usages may be inlined

			// members
			IVirtualMachine*        vm;                   // 08
			IVMObjectBindInterface* bindInterface;        // 10
			BSSpinLock              attachedScriptsLock;  // 18
			uint64_t                unk20;                // 20
			std::byte               unk28[0x30];          // 28
			std::uint64_t           unk58;                // 58

			// TODO: unk28 is likely `BSTHashMap<std::size_t, BSTSmallSharedArray<BSTSmartPointer<BoundScript>>> attachedScripts`, but unsure where exactly it starts
		};
		static_assert(sizeof(ObjectBindPolicy) == 0x60);
	}

	namespace GameScript
	{
		class ObjectBindPolicy :
			public BSScript::ObjectBindPolicy  // 00
		{
		public:
			SF_RTTI_VTABLE(GameScript__ObjectBindPolicy);

			struct QueuedObject
			{
			public:
				// members
				BSTSmartPointer<BSScript::Object> createdObject;  // 00
				BSScript::MergedBoundScript       boundInfo;      // 08
			};
			static_assert(sizeof(QueuedObject) == 0x18);

			// override (BSScript::ObjectBindPolicy)
			void          EnsureBaseDataLoaded(std::size_t a_objHandle) override;                                                                                                                                                                                               // 01
			void          ObjectNoLongerNeeded(std::size_t a_objHandle) override;                                                                                                                                                                                               // 02
			void          AddBoundInfoImpl(std::size_t a_objHandle) override;                                                                                                                                                                                                   // 03
			void          ClearBoundInfoImpl(std::size_t a_objHandle) override;                                                                                                                                                                                                 // 04
			void          ClearDiskLoadedBoundInfoImpl(std::size_t a_objHandle) override;                                                                                                                                                                                       // 05
			void          ClearAllBoundInfoImpl() override;                                                                                                                                                                                                                     // 06
			void          PostBindObject(std::size_t a_objHandle) override;                                                                                                                                                                                                     // 07
			std::uint32_t GetExtraInfoSize(std::size_t) const override { return 0; }                                                                                                                                                                                            // 08
			void          WriteExtraInfo(std::size_t, const BSScript::IHandleReaderWriter&, BSStorage&) const override { return; }                                                                                                                                              // 09
			void          ReadExtraInfo(std::size_t a_objHandle, std::uint16_t a_handleVersion, const BSScript::IHandleReaderWriter& a_handleReaderWriter, const BSStorage& a_storage) override;                                                                                // 0A
			bool          IsIgnoringClear() const override;                                                                                                                                                                                                                     // 0B
			void          ResolveProperties(std::size_t a_objTarget, const BSTSmartPointer<BSScript::Object>& a_object, const BSTSmartPointer<BSScript::BoundScript>& a_boundScript, bool a_postSaveConstOnly) override;                                                        // 0D
			void          ResolveProperties(std::size_t a_objTarget, const BSTSmartPointer<BSScript::Object>& a_object, const BSScript::MergedBoundScript& a_boundScript, bool a_postSaveConstOnly) override;                                                                   // 0C
			void          ConvertProperties(std::size_t a_objTarget, const BSScript::MergedBoundScript& a_mergedScript, bool a_constOnly, /*BSTScrapHashMap<BSFixedString, Variable>&*/ void* a_properties, std::uint32_t& a_nonConvertedProperties) const override;            // 0E
			void          ConvertProperties(std::size_t a_objTarget, const BSTSmartPointer<BSScript::BoundScript>& a_boundScript, bool a_constOnly, /*BSTScrapHashMap<BSFixedString, Variable>&*/ void* a_properties, std::uint32_t& a_nonConvertedProperties) const override;  // 0F

			// members
			BSSpinLock                                                          queueLock;            // 60
			bool                                                                resolveCalled;        // 68
			bool                                                                ignoringClear;        // 69
			bool                                                                initialLoadDone;      // 6A
			std::uint8_t                                                        pad6B;                // 6B
			std::uint32_t                                                       pad6C;                // 6C
			/*BSTHashMap<std::size_t, BSTSmallSharedArray<QueuedObject>>*/ char queuedObjects[0x30];  // 70
			std::uint64_t                                                       unkA0;                // A0
			std::uint64_t                                                       unkA8;                // A8
			std::uint64_t                                                       unkB0;                // B0
			std::uint64_t                                                       unkB8;                // B8
			std::uint64_t                                                       unkC0;                // C0
			std::uint64_t                                                       unkC8;                // C8
			std::uint64_t                                                       unkD0;                // D0
			std::uint64_t                                                       unkD8;                // D8
			std::uint64_t                                                       unkE0;                // E0
			std::uint64_t                                                       unkE8;                // E8
			std::uint64_t                                                       unkF0;                // F0
			std::uint64_t                                                       unkF8;                // F8

			//TODO:BSTArray<std::size_t> queuedAliases and BSTSet<std::size_t> initiallyLoadedObjects is somewhere up there...
		};
		static_assert(sizeof(ObjectBindPolicy) == 0x100);
	}
}
