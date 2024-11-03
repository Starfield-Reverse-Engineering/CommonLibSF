#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSPauseRequester.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTScatterTable.h"

namespace RE
{
	namespace PlayerNameEvent
	{
		struct NameChangedEvent;
	}

	class BGSSaveLoadFile
	{
	public:
	};

	class BGSSaveLoadFileEntry
	{
	public:
		[[nodiscard]] char* GetFileName() const
		{
			return fileName;
		}

		[[nodiscard]] char* GetPlayerName()
		{
			if (playerName)
				return playerName;

			LoadData();
			return playerName;
		}

		[[nodiscard]] bool IsAutoSave() const
		{
			return fileName && !_strnicmp(fileName, "AutoSave", 8);
		}

		[[nodiscard]] bool IsExitSave() const
		{
			return fileName && !_strnicmp(fileName, "ExitSave", 8);
		}

		[[nodiscard]] bool IsGenerated() const
		{
			return fileName && !_strnicmp(fileName, "Save", 4);
		}

		[[nodiscard]] bool IsQuickSave() const
		{
			return fileName && !_strnicmp(fileName, "QuickSave", 9);
		}

		void LoadData()
		{
			using func_t = decltype(&BGSSaveLoadFileEntry::LoadData);
			static REL::Relocation<func_t> func{ ID::BGSSaveLoadFileEntry::LoadData };
			func(this);
		}

		// members
		char* fileName;    // 00
		char* playerName;  // 08
	};

	class BGSSaveLoadThread
	{
	public:
		SF_RTTI_VTABLE(BGSSaveLoadThread);

		struct AsyncRequest
		{
			using TaskFinishedCallback_t = std::add_pointer_t<void(bool a_result)>;
		};
	};

	class BGSSaveLoadManager :
		public BSTEventSink<PlayerNameEvent::NameChangedEvent>,  // 000
		public BSPauseRequester                                  // 008
	{
	public:
		SF_RTTI_VTABLE(BGSSaveLoadManager);

		enum class SaveFileCategory : std::uint32_t
		{
			kUser = 0,
			kAuto = 1,
			kQuick = 2,
			kExit = 3
		};

		enum class QueuedTask : std::uint32_t
		{
			kAutoSave = 0x1,
			kForceSave = 0x2,
			kQuickSave = 0x8,
			kQuickLoad = 0x10,
			kLoadGame = 0x40,
			kAutoSaveCommit = 0x200,
			kQuickSaveCommit = 0x400,
			kBuildSaveGameList = 0x1000,
			kSaveAndQuit = 0x4000,
		};

		virtual ~BGSSaveLoadManager();  // 00

		// override (BSTEventSink)
		BSEventNotifyControl ProcessEvent(const PlayerNameEvent::NameChangedEvent& a_event, BSTEventSource<PlayerNameEvent::NameChangedEvent>* a_source) override;  // 01

		[[nodiscard]] static auto GetSingleton()
		{
			static REL::Relocation<BGSSaveLoadManager**> singleton{ ID::BGSSaveLoadManager::Singleton };
			return *singleton;
		}

		[[nodiscard]] static bool IsSaveFileNameAutoSave(const char* a_name)
		{
			return a_name && !_strnicmp(a_name, "AutoSave", 8);
		}

		[[nodiscard]] static bool IsSaveFileNameExitSave(const char* a_name)
		{
			return a_name && !_strnicmp(a_name, "ExitSave", 8);
		}

		[[nodiscard]] static bool IsSaveFileNameGenerated(const char* a_name)
		{
			return a_name && !_strnicmp(a_name, "Save", 4);
		}

		[[nodiscard]] static bool IsSaveFileNameQuickSave(const char* a_name)
		{
			return a_name && !_strnicmp(a_name, "QuickSave", 9);
		}

		bool DeleteSaveFile(const char* a_filename, void* a_unk1, bool a_skipRemainingSavesCheck)
		{
			using func_t = decltype(&BGSSaveLoadManager::DeleteSaveFile);
			static REL::Relocation<func_t> func{ ID::BGSSaveLoadManager::DeleteSaveFile };
			return func(this, a_filename, a_unk1, a_skipRemainingSavesCheck);
		}

		void QueueBuildSaveGameList(BGSSaveLoadThread::AsyncRequest::TaskFinishedCallback_t a_taskFinished = nullptr)
		{
			using func_t = decltype(&BGSSaveLoadManager::QueueBuildSaveGameList);
			static REL::Relocation<func_t> func{ ID::BGSSaveLoadManager::QueueBuildSaveGameList };
			func(this, a_taskFinished);
		}

		void QueueLoadGame(BGSSaveLoadFileEntry* a_entry)
		{
			queuedEntryToLoad = a_entry;
			queuedTasks.set(QueuedTask::kLoadGame);
		}

		void QueueLoadMostRecentSaveGame()
		{
			if (!saveGameListBuilt) {
				return QueueBuildSaveGameList([](bool a_result) {
					if (a_result)
						GetSingleton()->QueueLoadMostRecentSaveGame();
				});
			}

			if (saveGameCount > 0)
				QueueLoadGame(saveGameList.back());
		}

		void QueueSaveLoadTask(QueuedTask a_task)
		{
			using func_t = decltype(&BGSSaveLoadManager::QueueSaveLoadTask);
			static REL::Relocation<func_t> func{ ID::BGSSaveLoadManager::QueueSaveLoadTask };
			func(this, a_task);
		}

		[[nodiscard]] bool IsSaveGameListBuilt() const
		{
			return saveGameListBuilt;
		}

		// members
		std::byte                                pad010[0x008];               // 010
		BSTArray<BGSSaveLoadFileEntry*>          saveGameList;                // 018
		std::byte                                pad028[0x008];               // 028
		bool                                     saveGameListBuilt;           // 030
		std::uint32_t                            saveGameCount;               // 034
		std::uint32_t                            currentSaveGameNumber;       // 038
		std::byte                                pad03C[0x004];               // 03C
		std::uint64_t                            saveGameListBuildID;         // 040
		std::uint32_t                            currentAutoSaveNumber;       // 048
		std::byte                                pad04C[0x004];               // 04C
		REX::EnumSet<QueuedTask>                 queuedTasks;                 // 050
		std::byte                                pad054[0x004];               // 054
		BGSSaveLoadFileEntry*                    queuedEntryToLoad;           // 058
		std::byte                                pad060[0x010];               // 060
		char*                                    mostRecentSaveGame;          // 070
		std::int32_t                             mostRecentSaveGameDeviceID;  // 078
		std::byte                                pad07C[0x08C];               // 07C
		std::uint64_t                            currentPlayerID;             // 108
		std::uint64_t                            displayPlayerID;             // 110
		BSFixedString                            saveFileNameToDelete;        // 118
		BSTHashMap<std::uint32_t, BSFixedString> autoSaveFileNames;           // 120
		BSFixedString                            quickSaveFileName;           // 158
		BSFixedString                            exitSaveFileName;            // 160
		std::byte                                pad168[0x010];               // 168
		BGSSaveLoadFile*                         saveLoadFile;                // 178
		bool                                     returnedFromSysUtil;         // 180
		bool                                     sysUtilLoadDataComplete;     // 181
	};
	static_assert(offsetof(BGSSaveLoadManager, saveGameList) == 0x018);
	static_assert(offsetof(BGSSaveLoadManager, saveGameListBuilt) == 0x030);
	static_assert(offsetof(BGSSaveLoadManager, saveGameCount) == 0x034);
	static_assert(offsetof(BGSSaveLoadManager, saveGameListBuildID) == 0x040);
	static_assert(offsetof(BGSSaveLoadManager, queuedTasks) == 0x050);
	static_assert(offsetof(BGSSaveLoadManager, mostRecentSaveGame) == 0x070);
	static_assert(offsetof(BGSSaveLoadManager, currentPlayerID) == 0x108);
	static_assert(offsetof(BGSSaveLoadManager, quickSaveFileName) == 0x158);
	static_assert(offsetof(BGSSaveLoadManager, saveLoadFile) == 0x178);
	static_assert(offsetof(BGSSaveLoadManager, sysUtilLoadDataComplete) == 0x181);
}
