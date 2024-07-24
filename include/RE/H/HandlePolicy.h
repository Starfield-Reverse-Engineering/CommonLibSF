#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSLock.h"
#include "RE/I/IObjectHandlePolicy.h"

namespace RE::GameScript
{
	struct HandlePolicy :
		public BSScript::IObjectHandlePolicy  // 00
	{
	public:
		SF_RTTI_VTABLE(GameScript__HandlePolicy);

		// override (BSScript::IObjectHandlePolicy)
		bool        HandleIsType(std::uint32_t a_type, std::size_t a_handle) const override;              // 01
		bool        GetHandleType(std::size_t a_handle, std::uint32_t& a_type) const override;            // 02
		bool        IsHandleLoaded(std::size_t a_handle) const override;                                  // 03
		bool        IsHandleObjectAvailable(std::size_t a_handle) const override;                         // 04
		bool        ShouldAttemptToCleanHandle(std::size_t a_handle) const override;                      // 05
		std::size_t EmptyHandle() const override { return 0xFFFF00000000; }                               // 06
		std::size_t GetHandleForObject(std::uint32_t a_type, const void* a_object) const override;        // 07
		bool        HasParent(std::size_t a_childHandle) const override;                                  // 08
		std::size_t GetParentHandle(std::size_t a_childHandle) const override;                            // 09
		std::size_t GetHandleScriptsMovedFrom(std::size_t a_newHandle) const override;                    // 0A
		std::size_t GetSaveRemappedHandle(std::size_t a_saveHandle) const override;                       // 0B
		void*       GetObjectForHandle(std::uint32_t a_type, std::size_t a_handle) const override;        // 0C
		void        PersistHandle(std::size_t a_handle) override;                                         // 0D
		void        ReleaseHandle(std::size_t a_handle) override;                                         // 0E
		void        ConvertHandleToString(std::size_t a_handle, BSFixedString& a_string) const override;  // 0F

		// members
		uint64_t                                               unk08;                  // 08
		BSSpinLock                                             persistLock;            // 10
		/*BSTHashMap<std::size_t, std::uint32_t>*/ std::byte   persistRefCount[0x30];  // 18
		uint64_t                                               unk48;                  // 48
		/*BSTHashMap<std::size_t, bool>*/ std::byte            queuedPromotes[0x30];   // 50
		uint64_t                                               unk80;                  // 80
		BSSpinLock                                             remapLock;              // 88
		/*BSTHashMap<std::uint32_t, std::uint32_t>*/ std::byte changedFormIDs[0x30];   // 90
	};
	static_assert(sizeof(HandlePolicy) == 0xC0);
}
