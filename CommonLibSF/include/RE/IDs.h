#pragma once

namespace RE::ID
{
	namespace Actor
	{
		inline constexpr REL::ID IsHostileToActor{ 150777 };
	}

	namespace ActorValue
	{
		inline constexpr REL::ID GetSingleton{ 36266 };
	}

	namespace ActorEquipManager
	{
		inline constexpr REL::ID singleton{ 879425 };
		inline constexpr REL::ID EquipObject{ 151991 };
		inline constexpr REL::ID UnequipObject{ 152007 };
	}
	//Extradatalist.h
	namespace BaseExtraList
	{
		inline constexpr REL::ID AddExtra{ 83084 };
		inline constexpr REL::ID GetByType{ 83208 };
	}

	namespace BGSObjectInstance
	{
		inline constexpr REL::ID ctor{ 101725 };
	}

	namespace BSNonReentrantSpinLock
	{
		inline constexpr REL::ID lock{ 73879 };
		inline constexpr REL::ID try_lock{ 74235 };
		inline constexpr REL::ID unlock{ 73895 };
	}

	namespace BSReadWriteLock
	{
		inline constexpr REL::ID lock_read{ 178605 };
		inline constexpr REL::ID lock_write{ 34125 };
		inline constexpr REL::ID unlock_read{ 178609 };
		inline constexpr REL::ID unlock_write{ 34257 };

	}

	namespace BSScript
	{
		namespace Array
		{
			inline constexpr REL::ID ctor{ 196577 };
			inline constexpr REL::ID dtor{ 196579 };
		}

		namespace Object
		{
			inline constexpr REL::ID ctor{ 196025 };
			inline constexpr REL::ID dtor{ 196032 };
			inline constexpr REL::ID GetHandle{ 196069 };
			inline constexpr REL::ID SetHandle{ 196079 };
			inline constexpr REL::ID IncRef{ 37879 };
			inline constexpr REL::ID DecRef{ 196057 };
		}

		namespace ObjectTypeInfo
		{
			inline constexpr REL::ID ctor{ 197047 };
			inline constexpr REL::ID dtor{ 196202 };
			inline constexpr REL::ID Clear{ 196218 };
			inline constexpr REL::ID CopyFromLinkedData{ 196219 };
			inline constexpr REL::ID GetProperty{ 196241 };
		}

		namespace Internal
		{
			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::ID Invoke{ 196401 };
					inline constexpr REL::ID GetParam{ 196404 };
					inline constexpr REL::ID Unk_10{ 196407 };
					inline constexpr REL::ID GetParamInfo{ 196409 };
					inline constexpr REL::ID Unk_15{ 196408 };
				}
			}
		}
	}

	namespace BSSpinLock
	{
		inline constexpr REL::ID lock{ 178543 };
		inline constexpr REL::ID try_lock{ 178545 };
		inline constexpr REL::ID unlock{ 178544 };
	}

	namespace BSStringPool
	{
		namespace Entry
		{
			inline constexpr REL::ID release{ 36754 };
		}
		namespace BucketTable
		{
			inline constexpr REL::ID GetSingleton{ 198241 };
		}

		inline constexpr REL::ID GetEntry_char_{ 198219 };
		inline constexpr REL::ID GetEntry_wchar_t_{ 198220 };

	}

	namespace BSTEventSource
	{
		inline constexpr REL::ID Notify{ 178573 };
		inline constexpr REL::ID RegisterSink{ 34452 };
		inline constexpr REL::ID UnregisterSink{ 34451 };
	}

	namespace BSTHeapSTLAllocatorBase
	{
		inline constexpr REL::ID allocate{ 34039 };
		inline constexpr REL::ID deallocate{ 34440 };
	}

	namespace ConsoleLog
	{
		inline constexpr REL::ID singleton{ 879277 };
		inline constexpr REL::ID VPrint{ 166358 };
	}

	namespace ExtraDataList
	{
		inline constexpr REL::ID HasType{ 83208 };
	}

	namespace MemoryManager
	{
		inline constexpr REL::ID GetSingleton{ 33961 };
		inline constexpr REL::ID Allocate{ 33962 };
		inline constexpr REL::ID Free{ 34032 };
	}

	namespace Misc
	{
		inline constexpr REL::ID DebugNotification{ 138728 };
		inline constexpr REL::ID PlayMenuSound{ 167344 };
	}

	namespace ObjectBindPolicy
	{
		inline constexpr REL::ID BindObject{ 195981 };
	}

	namespace PlayerCamera
	{
		inline constexpr REL::ID singleton{ 878523 };
		inline constexpr REL::ID ForceFirstPerson{ 166029 };
		inline constexpr REL::ID ForceThirdPerson{ 166031 };
		inline constexpr REL::ID SetCameraState{ 166078 };
		inline constexpr REL::ID QCameraEquals{ 166081 };
	}

	namespace PlayerCharacter
	{
		inline constexpr REL::ID singleton{ 865059 };
	}

	namespace RegSettingCollection
	{
		inline constexpr REL::ID singleton{ 885510 };
	}

	namespace Scaleform
	{
		namespace ObjectInterface
		{
			inline constexpr REL::ID ObjectAddRef{ 57288 };
			inline constexpr REL::ID ObjectRelease{ 57289 };
			inline constexpr REL::ID HasMember{ 57290 };
			inline constexpr REL::ID GetMember{ 57291 };
			inline constexpr REL::ID SetMember{ 57292 };
			inline constexpr REL::ID Invoke{ 57293 };
			inline constexpr REL::ID VisitMembers{ 57296 };
			inline constexpr REL::ID GetArraySize{ 57297 };
			inline constexpr REL::ID SetArraySize{ 57298 };
			inline constexpr REL::ID GetElement{ 57299 };
			inline constexpr REL::ID SetElement{ 57300 };
			inline constexpr REL::ID VisitElements{ 57301 };
			inline constexpr REL::ID PushBack{ 57303 };
			inline constexpr REL::ID PopBack{ 57304 };
			inline constexpr REL::ID RemoveElements{ 57305 };
			inline constexpr REL::ID GetParent{ 57314 };
			inline constexpr REL::ID GetText{ 57324 };
			inline constexpr REL::ID SetText{ 57325 };
			inline constexpr REL::ID SetTextW{ 57326 };
			inline constexpr REL::ID CreateEmptyMovieClip{ 57327 };
			inline constexpr REL::ID GotoAndPlayL{ 57329 };
			inline constexpr REL::ID GotoAndPlay{ 57330 };
		}
	}

	namespace Script
	{
		inline constexpr REL::ID GetConsoleCommands{ 841465 };
		inline constexpr REL::ID GetScriptCommands{ 841467 };
	}

	namespace TESCellFullyLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 107143 };
	}

	namespace TESContainerChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 107155 };
	}

	namespace TESDataHandler
	{
		inline constexpr REL::ID singleton{ 825890 };
	}

	namespace TESDeathEvent
	{
		inline constexpr REL::ID GetEventSource{ 107156 };
	}

	namespace TESForm
	{
		inline constexpr REL::ID DecRefCount{ 35164 };
		inline constexpr REL::ID LookupByID{ 86125 };
		inline constexpr REL::ID LookupByEditorID{ 86127 };
	}

	namespace TESObjectLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 107177 };
	}

	namespace TESObjectREFR
	{
		inline constexpr REL::ID GetCurrentLocation{ 106554 };
		inline constexpr REL::ID GetLinkedRef{ 107578 };
		inline constexpr REL::ID GetParentWorldSpace{ 106696 };
		inline constexpr REL::ID GetSpaceship{ 173851 };
		inline constexpr REL::ID GetSpaceshipParentDock{ 174134 };
		inline constexpr REL::ID GetSpaceshipPilot{ 173834 };
		inline constexpr REL::ID GetValue{ 107605 };
		inline constexpr REL::ID HasKeyword{ 80343 };
		inline constexpr REL::ID IsCrimeToActivate{ 106755 };
		inline constexpr REL::ID IsInSpace{ 106767 };
		inline constexpr REL::ID IsSpaceshipDocked{ 174146 };
		inline constexpr REL::ID IsSpaceshipLanded{ 173880 };
	}

	namespace TESWorldSpace
	{
		inline constexpr REL::ID GetLocationFromCoordinates{ 107914 };
	}

	namespace UI
	{
		inline constexpr REL::ID singleton{ 878339 };
		inline constexpr REL::ID IsMenuOpen{ 187049 };
	}

	// global functions/ ids

	inline constexpr REL::ID RTDynamicCast{ 211916 };

}
