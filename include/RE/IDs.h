#pragma once

namespace RE::ID
{
	namespace Actor
	{
		inline constexpr REL::ID EvaluatePackage{ 150640 };
		inline constexpr REL::ID GetActorKnowledge{ 150669 };
		inline constexpr REL::ID IsHostileToActor{ 150777 };
		inline constexpr REL::ID IsJumping{ 150985 };
		inline constexpr REL::ID IsOverEncumbered{ 150999 };
		inline constexpr REL::ID IsSneaking{ 151014 };
		inline constexpr REL::ID SetSkinTone{ 146270 };
		inline constexpr REL::ID UpdateAppearance{ 151216 };
		inline constexpr REL::ID UpdateChargenAppearance{ 146273 };
	}

	namespace ActorUtils
	{
		inline constexpr REL::ID ChangeAnimArchetype{ 150497 };
	}

	namespace ActorValue
	{
		inline constexpr REL::ID GetSingleton{ 36266 };
	}

	namespace ActorEquipManager
	{
		inline constexpr REL::ID Singleton{ 879425 };
		inline constexpr REL::ID EquipObject{ 151991 };
		inline constexpr REL::ID UnequipObject{ 152007 };
	}

	namespace BaseExtraList
	{
		inline constexpr REL::ID AddExtra{ 83084 };
		inline constexpr REL::ID GetByType{ 83208 };
	}

	namespace BGSDefaultObjectManager
	{
		inline constexpr REL::ID DefaultObjectData{ 761776 };
		inline constexpr REL::ID GetSingleton{ 82283 };
	}

	namespace BGSEditorID
	{
		inline constexpr REL::ID Register{ 86172 };
	}

	namespace BGSEntryPoint
	{
		inline constexpr REL::ID HandleEntryPoint{ 110912 };
	}

	namespace BGSInventoryInterface
	{
		inline constexpr REL::ID Singleton{ 825787 };
		inline constexpr REL::ID GetInventoryObject{ 87520 };
	}

	namespace BGSObjectInstance
	{
		inline constexpr REL::ID ctor{ 101725 };
	}

	namespace BGSSaveLoadFileEntry
	{
		inline constexpr REL::ID LoadData{ 147331 };
	}

	namespace BGSSaveLoadGame
	{
		inline constexpr REL::ID SaveGame{ 147515 };
		inline constexpr REL::ID LoadGame{ 147564 };
	}

	namespace BGSSaveLoadManager
	{
		inline constexpr REL::ID DeleteSaveFile{ 147844 };
		inline constexpr REL::ID QueueBuildSaveGameList{ 147900 };
		inline constexpr REL::ID QueueSaveLoadTask{ 1536882 };
		inline constexpr REL::ID Singleton{ 880997 };
	}

	namespace BGSStoryTeller
	{
		inline constexpr REL::ID Singleton{ 878850 };
	}

	namespace BSInputEnableLayer
	{
		inline constexpr REL::ID SetUserFlags{ 106486 };
		inline constexpr REL::ID SetOtherFlags{ 109447 };
	}

	namespace BSInputEnableManager
	{
		inline constexpr REL::ID CreateLayer{ 179101 };
		inline constexpr REL::ID Singleton{ 878792 };
	}

	namespace BSLog
	{
		inline constexpr REL::ID ctor{ 184813 };
		inline constexpr REL::ID dtor{ 184816 };
		inline constexpr REL::ID CycleLog{ 184822 };
		inline constexpr REL::ID FlushBuffer{ 184823 };
		inline constexpr REL::ID FlushBufferToFile{ 184824 };
		inline constexpr REL::ID GenerateTimeStamp{ 184825 };
		inline constexpr REL::ID MakeLogFilename{ 184826 };
		inline constexpr REL::ID WriteData{ 184832 };
		inline constexpr REL::ID WriteEntry{ 184833 };
	}

	namespace BSNonReentrantSpinLock
	{
		inline constexpr REL::ID lock{ 73879 };
		inline constexpr REL::ID try_lock{ 74235 };
		inline constexpr REL::ID unlock{ 73895 };
	}

	namespace BSPointerHandleManagerInterface
	{
		inline constexpr REL::ID GetSmartPointer{ 72432 };
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

		namespace ObjectBindPolicy
		{
			inline constexpr REL::ID BindObject{ 195981 };
		}

		namespace ObjectTypeInfo
		{
			inline constexpr REL::ID ctor{ 197047 };
			inline constexpr REL::ID dtor{ 196202 };
			inline constexpr REL::ID Clear{ 196218 };
			inline constexpr REL::ID CopyFromLinkedData{ 196219 };
			inline constexpr REL::ID GetProperty{ 196241 };
		}

		namespace Stack
		{
			inline constexpr REL::ID ctor{ 196325 };
			inline constexpr REL::ID dtor{ 196333 };
			inline constexpr REL::ID GetStackFrameVariable{ 196367 };
			inline constexpr REL::ID GetPageForFrame{ 196366 };
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

	namespace BSStorage
	{
		inline constexpr REL::ID FlushStreamBuffer{ 72433 };
		inline constexpr REL::ID PrepareStreamBuffer{ 72461 };
		inline constexpr REL::ID WriteString{ 87863 };
	}

	namespace BSSystemFile
	{
		inline constexpr REL::ID ctor{ 198445 };
		inline constexpr REL::ID dtor{ 198446 };
		inline constexpr REL::ID DoClose{ 198452 };
		inline constexpr REL::ID DeleteFileA{ 198451 };
		inline constexpr REL::ID DoOpen{ 198454 };
		inline constexpr REL::ID DoSeek{ 198456 };
		inline constexpr REL::ID DoSetEndOfFile{ 198457 };
		inline constexpr REL::ID Flush{ 78151 };
		inline constexpr REL::ID GetSize{ 85176 };
		inline constexpr REL::ID Read{ 75362 };
		inline constexpr REL::ID RenameFile{ 198459 };
		inline constexpr REL::ID Truncate{ 195959 };
		inline constexpr REL::ID Write{ 75363 };
		inline constexpr REL::ID operatorEqCopy{ 198448 };
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
		inline constexpr REL::ID Singleton{ 879277 };
		inline constexpr REL::ID AddString{ 166357 };
		inline constexpr REL::ID Print{ 166358 };
	}

	namespace ExtraDataList
	{
		inline constexpr REL::ID HasQuestObjectAlias{ 83336 };
		inline constexpr REL::ID HasType{ 83208 };
	}

	namespace FORM_ENUM_STRING
	{
		inline constexpr REL::ID FormEnumString{ 761416 };
	}

	namespace GameMenuBase
	{
		inline constexpr REL::ID Ctor{ 130577 };
	}

	namespace GameScript
	{
		namespace RemoteDebugger
		{
			inline constexpr REL::ID HandleContinueRequest{ 167579 };
			inline constexpr REL::ID HandleDisconnectRequest{ 167580 };
			inline constexpr REL::ID HandlePauseRequest{ 167581 };
			inline constexpr REL::ID HandleSetBreakpointsRequest{ 167582 };
			inline constexpr REL::ID HandleStackTraceRequest{ 167583 };
			inline constexpr REL::ID HandleThreadsRequest{ 167584 };
			inline constexpr REL::ID HandleValueRequest{ 167585 };
			inline constexpr REL::ID HandleVariablesRequest{ 167586 };
			inline constexpr REL::ID HandleStepRequest{ 167587 };
		}
	}

	namespace GameSettingCollection
	{
		inline constexpr REL::ID Singleton{ 879099 };
		inline constexpr REL::ID GetSetting{ 88638 };
	}

	namespace GameVM
	{
		inline constexpr REL::ID Singleton{ 878371 };
		inline constexpr REL::ID BindEverythingToScript{ 171438 };
	}

	namespace idLogging
	{
		inline constexpr REL::ID Singleton{ 895197 };
	}

	namespace idTCP
	{
		inline constexpr REL::ID Accept{ 211257 };
		inline constexpr REL::ID Close{ 211258 };
		inline constexpr REL::ID Listen{ 211259 };
		inline constexpr REL::ID Read{ 211264 };
		inline constexpr REL::ID Write{ 211266 };
	}

	namespace INIPrefSettingCollection
	{
		inline constexpr REL::ID Singleton{ 885866 };
	}

	namespace INISettingCollection
	{
		inline constexpr REL::ID Singleton{ 885862 };
	}

	namespace InputEnableLayer
	{
		inline constexpr REL::ID Free{ 36626 };
	}

	namespace LockPickedEvent
	{
		inline constexpr REL::ID GetEventSource{ 107115 };
		inline constexpr REL::ID Notify{ 107339 };
	}

	namespace Main
	{
		inline constexpr REL::ID Singleton{ 881027 };
		inline constexpr REL::ID WorldRoot{ 887308 };
	}

	namespace msvc
	{
		namespace type_info
		{
			inline constexpr REL::ID name{ 248847 };
			inline constexpr REL::ID _RootNode{ 824582 };
			inline constexpr REL::ID compare{ 248848 };
		}
	}

	namespace MemoryManager
	{
		namespace AutoScrapBuffer
		{
			inline constexpr REL::ID ctor{ 178513 };
			inline constexpr REL::ID dtor{ 178516 };
		}

		inline constexpr REL::ID GetSingleton{ 33961 };
		inline constexpr REL::ID Allocate{ 33962 };
		inline constexpr REL::ID Free{ 34032 };
		inline constexpr REL::ID GetThreadScrapHeap{ 36848 };
	}

	namespace MenuTopicManager
	{
		inline constexpr REL::ID Singleton{ 879316 };
	}

	namespace Misc
	{
		inline constexpr REL::ID DebugNotification{ 138728 };
		inline constexpr REL::ID LookupReferenceByHandle{ 72986 };
		inline constexpr REL::ID PlayMenuSound{ 167344 };
	}

	namespace NiCamera
	{
		inline constexpr REL::ID WorldToScreenInternal{ 210415 };
	}

	namespace NiMatrix3
	{
		inline constexpr REL::ID ToEulerAnglesXYZ{ 210095 };
	}

	namespace PlayerCamera
	{
		inline constexpr REL::ID Singleton{ 878523 };
		inline constexpr REL::ID ForceFirstPerson{ 166029 };
		inline constexpr REL::ID ForceThirdPerson{ 166031 };
		inline constexpr REL::ID SetCameraState{ 166078 };
		inline constexpr REL::ID QCameraEquals{ 166081 };
	}

	namespace PlayerCharacter
	{
		inline constexpr REL::ID Singleton{ 865059 };
	}

	namespace ProcessLists
	{
		inline constexpr REL::ID AreHostileActorsNear{ 154040 };
		inline constexpr REL::ID Singleton{ 878338 };
		inline constexpr REL::ID ToggleAI{ 154056 };
	}

	namespace REFR_LOCK
	{
		inline constexpr REL::ID GetLockLevel{ 84103 };
	}

	namespace RegSettingCollection
	{
		inline constexpr REL::ID Singleton{ 885510 };
	}

	namespace Scaleform
	{
		namespace GFx
		{
			namespace Value
			{
				namespace ObjectInterface
				{
					inline constexpr REL::ID ObjectAddRef{ 57288 };
					inline constexpr REL::ID ObjectRelease{ 57289 };
					inline constexpr REL::ID HasMember{ 57290 };
					inline constexpr REL::ID GetMember{ 57291 };
					inline constexpr REL::ID SetMember{ 1867815 };
					inline constexpr REL::ID Invoke{ 1867816 };
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
		}

		namespace MemoryHeapPT
		{
			inline constexpr REL::ID Singleton{ 820297 };
		}
	}

	namespace ScrapHeap
	{
		inline constexpr REL::ID Allocate{ 34432 };
		inline constexpr REL::ID Deallocate{ 37624 };
	}

	namespace Script
	{
		inline constexpr REL::ID GetConsoleCommands{ 841465 };
		inline constexpr REL::ID GetScriptCommands{ 841467 };
	}

	namespace SWFToCodeFunctionHandler
	{
		inline constexpr REL::ID RegisterNativeFunction{ 187274 };
	}

	namespace TES
	{
		inline constexpr REL::ID Singleton{ 881024 };
	}

	namespace TESActorBaseData
	{
		inline constexpr REL::ID GetLevel{ 85868 };
		inline constexpr REL::ID GetUsesLeveledTemplate{ 85873 };
	}

	namespace TESCellFullyLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 107143 };
	}

	namespace TESCondition
	{
		inline constexpr REL::ID CheckValue{ 116112 };
	}

	namespace TESConditionItem
	{
		inline constexpr REL::ID IsTrue{ 116127 };
	}

	namespace TESContainer
	{
		inline constexpr REL::ID AddObjectToContainer{ 85991 };
	}

	namespace TESContainerChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 107155 };
	}

	namespace TESDataHandler
	{
		inline constexpr REL::ID Singleton{ 825890 };
	}

	namespace TESDeathEvent
	{
		inline constexpr REL::ID GetEventSource{ 107156 };
	}

	namespace TESForm
	{
		inline constexpr REL::ID DecExternalRefCount{ 34165 };
		inline constexpr REL::ID DecRefCount{ 35164 };
		inline constexpr REL::ID LookupByID{ 86125 };
		inline constexpr REL::ID LookupByEditorID{ 86123 };
	}

	namespace TESNPC
	{
		inline constexpr REL::ID CopyAppearance{ 111992 };
		inline constexpr REL::ID DeriveGeneticParentAppearance{ 112005 };
	}

	namespace TESNPCData
	{
		namespace ChargenDataModel
		{
			inline constexpr REL::ID Singleton{ 879332 };
			inline constexpr REL::ID Update{ 100686 };
		}
	}

	namespace TESObjectARMO
	{
		inline constexpr REL::ID CanUseArmor{ 103501 };
	}

	namespace TESObjectLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 107177 };
	}

	namespace TESObjectREFR
	{
		inline constexpr REL::ID ActivateRef{ 106374 };
		inline constexpr REL::ID AddLockChange{ 106386 };
		inline constexpr REL::ID GetCalcLevel{ 107531 };
		inline constexpr REL::ID GetCurrentLocation{ 106554 };
		inline constexpr REL::ID GetDistance{ 106562 };
		inline constexpr REL::ID GetLinkedRef{ 107578 };
		inline constexpr REL::ID GetLock{ 107581 };
		inline constexpr REL::ID GetParentWorldSpace{ 106696 };
		inline constexpr REL::ID GetScale{ 106658 };
		inline constexpr REL::ID GetSpaceship{ 173851 };
		inline constexpr REL::ID GetSpaceshipParentDock{ 174134 };
		inline constexpr REL::ID GetSpaceshipPilot{ 173834 };
		inline constexpr REL::ID GetValue{ 107605 };
		inline constexpr REL::ID HasKeyword{ 80343 };
		inline constexpr REL::ID IsCrimeToActivate{ 106755 };
		inline constexpr REL::ID IsInSpace{ 106767 };
		inline constexpr REL::ID IsObjectEquipped{ 106991 };
		inline constexpr REL::ID IsSpaceshipDocked{ 174146 };
		inline constexpr REL::ID IsSpaceshipLanded{ 173880 };
		inline constexpr REL::ID WornHasKeyword{ 106992 };
	}

	namespace TESQuest
	{
		inline constexpr REL::ID IsStageDone{ 112585 };
	}

	namespace TESWorldSpace
	{
		inline constexpr REL::ID GetLocationFromCoordinates{ 107914 };
	}

	namespace UI
	{
		inline constexpr REL::ID Singleton{ 878339 };
		inline constexpr REL::ID IsMenuOpen{ 1870208 };
	}

	namespace UIMessageQueue
	{
		inline constexpr REL::ID Singleton{ 878637 };
		inline constexpr REL::ID AddMessage{ 187268 };
	}

	// global functions/ ids

	inline constexpr REL::ID RTDynamicCast{ 211916 };

	// idCoreSocket functions
	inline constexpr REL::ID NET_ErrorString{ 211261 };
	inline constexpr REL::ID Net_SockadrToNetadr{ 211262 };
	inline constexpr REL::ID NET_WaitForData{ 211263 };
	inline constexpr REL::ID Sys_InitNetworking{ 211265 };
}
