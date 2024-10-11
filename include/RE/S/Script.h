#pragma once

#include "RE/B/BSStringT.h"
#include "RE/B/BSTList.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class BGSPackageDataList;
	class BGSStoryEvent;
	class Script;
	class TESForm;
	class TESObjectREFR;
	class TESQuest;

	namespace BGSMod::Template
	{
		class Item;
	}

	struct ScriptLocals;
	struct SCRIPT_PARAMETER;

	enum class SCRIPT_OUTPUT : std::int32_t;

	struct ACTION_OBJECT
	{
		// members
		TESForm*      form;   // 00
		std::uint32_t flags;  // 08
	};
	static_assert(sizeof(ACTION_OBJECT) == 0x10);

	struct ConditionCheckParams
	{
		// members
		NiPointer<TESObjectREFR> actionRef;           // 00
		NiPointer<TESObjectREFR> targetRef;           // 08
		TESQuest*                scopeQuest;          // 10
		BGSStoryEvent*           scopeEvent;          // 18
		NiPointer<Actor>         scopeActor;          // 20
		BGSPackageDataList*      runningPackageData;  // 28
		BGSMod::Template::Item*  objectTemplateItem;  // 30
		TESForm*                 extraForms[5];       // 38
		std::uint32_t            extraFormCount;      // 60
		bool                     outDispFailure;      // 64
	};
	static_assert(sizeof(ConditionCheckParams) == 0x68);

	struct SCRIPT_EFFECT_DATA
	{
		// members
		bool  scriptEffectStart;   // 0
		bool  scriptEffectFinish;  // 1
		float secondsElapsed;      // 4
	};
	static_assert(sizeof(SCRIPT_EFFECT_DATA) == 0x8);

	struct SCRIPT_FUNCTION
	{
		using ConditionFunction_t = bool (*)(ConditionCheckParams& a_data, void* a_param2, void* a_param1, float& a_returnValue);
		using ExecuteFunction_t = bool (*)(const SCRIPT_PARAMETER* a_paramInfo, const char*, TESObjectREFR* a_object, TESObjectREFR* a_objectContainer, Script* a_script, ScriptLocals* a_scriptLocals, float* a_result, std::uint32_t* a_opcodeOffsetPtr);

		// members
		const char*         functionName;         // 00
		const char*         shortName;            // 08
		std::uint32_t       output;               // 10
		std::uint32_t       pad14;                // 14
		const char*         helpString;           // 18
		std::uint8_t        referenceFunction;    // 20
		std::uint8_t        pad21;                // 21
		std::uint16_t       numParams;            // 22
		std::uint32_t       pad24;                // 24
		SCRIPT_PARAMETER*   params;               // 28
		ExecuteFunction_t   executeFunction;      // 30
		void*               compileFunction;      // 38
		ConditionFunction_t conditionFunction;    // 40
		std::uint8_t        editorFilter;         // 48
		std::uint8_t        invalidatesCellList;  // 49
		std::uint8_t        unk4A;                // 4A
		std::uint8_t        unk4B;                // 4B
		std::uint8_t        unk4C;                // 4C
		std::uint8_t        unk4E;                // 4D
		std::uint8_t        unk4F;                // 4F
		std::uint8_t        unk50;                // 50
		std::uint8_t        unk51;                // 51
	};
	static_assert(sizeof(SCRIPT_FUNCTION) == 0x58);

	struct alignas(4) SCRIPT_HEADER
	{
		// members
		std::uint32_t variableCount;        // 00
		std::uint32_t refObjectCount;       // 04
		std::uint32_t dataSize;             // 08
		std::uint32_t lastID;               // 0C
		bool          isQuestScript;        // 10
		bool          isMagicEffectScript;  // 11
		bool          isCompiled;           // 12
	};
	static_assert(sizeof(SCRIPT_HEADER) == 0x14);

	struct alignas(4) SCRIPT_LOCAL
	{
		// members
		std::uint32_t id;         // 00
		float         value;      // 04
		bool          isInteger;  // 08
	};
	static_assert(sizeof(SCRIPT_LOCAL) == 0x0C);

	struct SCRIPT_OPERATOR
	{
		// members
		std::uint32_t code;        // 00
		std::uint8_t  precedence;  // 04
		std::uint8_t  op;          // 05
	};
	static_assert(sizeof(SCRIPT_OPERATOR) == 0x8);

	struct SCRIPT_PARAMETER
	{
		// members
		const char*   paramName{ "" };  // 00
		std::uint32_t paramType;        // 08 enumeration
		bool          optional{};       // 0C
	};
	static_assert(sizeof(SCRIPT_PARAMETER) == 0x10);

	struct SCRIPT_PARAMETER_DEF
	{
		// members
		std::uint32_t paramType;         // 00
		std::uint8_t  canBeVariable;     // 04
		std::uint8_t  referencedObject;  // 05
	};
	static_assert(sizeof(SCRIPT_PARAMETER_DEF) == 0x8);

	struct SCRIPT_REFERENCED_OBJECT
	{
		// members
		BSStringT<char> editorID;
		TESForm*        form;
		std::uint32_t   variableID;
	};
	static_assert(sizeof(SCRIPT_REFERENCED_OBJECT) == 0x20);

	struct SCRIPT_WORD
	{
		// members
		char          text[512];       // 000
		std::uint32_t refObjectIndex;  // 200
		char          variableType;    // 204
		SCRIPT_OUTPUT functionCode;    // 208
		std::uint32_t variableID;      // 20C
		TESForm*      form;            // 210
	};
	static_assert(sizeof(SCRIPT_WORD) == 0x218);

	struct ScriptLocals
	{
		// members
		Script*                       masterScript;      // 00
		std::uint8_t                  flags;             // 08
		std::uint8_t                  pad09[7];          // 09
		BSSimpleList<ACTION_OBJECT*>* actionList;        // 10
		BSSimpleList<SCRIPT_LOCAL*>*  localList;         // 20
		SCRIPT_EFFECT_DATA*           scriptEffectData;  // 38
	};
	static_assert(sizeof(ScriptLocals) == 0x28);

	struct ScriptVariable
	{
		// members
		SCRIPT_LOCAL    data;  // 00
		BSStringT<char> name;  // 10
	};
	static_assert(sizeof(ScriptVariable) == 0x20);

	class Script
	{
	public:
		SF_RTTI_VTABLE(Script);

		enum
		{
			kNumConsoleCommands = 0x0244,
			kNumScriptCommands = 0x03C1,

			kConsoleOpBase = 0x0100,
			kScriptOpBase = 0x1000,
		};

		inline static const auto GetConsoleCommands()
		{
			static REL::Relocation<SCRIPT_FUNCTION(*)[kNumConsoleCommands]> chunk{ ID::Script::GetConsoleCommands };
			return std::span{ *chunk };
		}

		inline static const auto GetScriptCommands()
		{
			static REL::Relocation<SCRIPT_FUNCTION(*)[kNumScriptCommands]> chunk{ ID::Script::GetScriptCommands };
			return std::span{ *chunk };
		}

		inline static SCRIPT_FUNCTION* LocateConsoleCommand(const std::string_view a_longName)
		{
			for (auto& command : GetConsoleCommands()) {
				if (command.functionName && std::strlen(command.functionName) == a_longName.size())
					if (_strnicmp(command.functionName, a_longName.data(), a_longName.size()) == 0)
						return std::addressof(command);
			}

			return nullptr;
		}

		inline static SCRIPT_FUNCTION* LocateScriptCommand(const std::string_view a_longName)
		{
			for (auto& command : GetScriptCommands()) {
				if (command.functionName && std::strlen(command.functionName) == a_longName.size())
					if (_strnicmp(command.functionName, a_longName.data(), a_longName.size()) == 0)
						return std::addressof(command);
			}

			return nullptr;
		}

		// members
		SCRIPT_HEADER                           header;                       // 00
		char*                                   text;                         // 14
		char*                                   data;                         // 1C
		float                                   profilerTimer;                // 20
		float                                   questScriptDelay;             // 24
		float                                   questScriptGetSecondsBuffer;  // 28
		TESQuest*                               parentQuest;                  // 30
		BSSimpleList<SCRIPT_REFERENCED_OBJECT*> refObjects;                   // 38
		BSSimpleList<ScriptVariable*>           variables;                    // 4C
	};
	static_assert(sizeof(Script) == 0x60);
}
