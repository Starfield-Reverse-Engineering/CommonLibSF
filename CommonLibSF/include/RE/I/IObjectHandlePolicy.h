#pragma once

#include "RE/B/BSFixedString.h"

namespace RE::BSScript
{
	struct IObjectHandlePolicy
	{
	public:
		SF_RTTI_VTABLE(BSScript__IObjectHandlePolicy);

		virtual ~IObjectHandlePolicy() = default;  // 00

		// add
		virtual bool        HandleIsType(std::uint32_t a_type, std::size_t a_handle) const = 0;              // 01
		virtual bool        GetHandleType(std::size_t a_handle, std::uint32_t& a_type) const = 0;            // 02
		virtual bool        IsHandleLoaded(std::size_t a_handle) const = 0;                                  // 03
		virtual bool        IsHandleObjectAvailable(std::size_t a_handle) const = 0;                         // 04
		virtual bool        ShouldAttemptToCleanHandle(std::size_t a_handle) const = 0;                      // 05
		virtual std::size_t EmptyHandle() const = 0;                                                         // 06
		virtual std::size_t GetHandleForObject(std::uint32_t a_type, const void* a_object) const = 0;        // 07
		virtual bool        HasParent(std::size_t a_childHandle) const = 0;                                  // 08
		virtual std::size_t GetParentHandle(std::size_t a_childHandle) const = 0;                            // 09
		virtual std::size_t GetHandleScriptsMovedFrom(std::size_t a_newHandle) const = 0;                    // 0A
		virtual std::size_t GetSaveRemappedHandle(std::size_t a_saveHandle) const = 0;                       // 0B
		virtual void*       GetObjectForHandle(std::uint32_t a_type, std::size_t a_handle) const = 0;        // 0C
		virtual void        PersistHandle(std::size_t a_handle) = 0;                                         // 0D
		virtual void        ReleaseHandle(std::size_t a_handle) = 0;                                         // 0E
		virtual void        ConvertHandleToString(std::size_t a_handle, BSFixedString& a_string) const = 0;  // 0F
	};
	static_assert(sizeof(IObjectHandlePolicy) == 0x8);
}
