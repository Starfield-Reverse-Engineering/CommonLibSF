#pragma once

#include "RE/B/BSReflection.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/T/TESFile.h"

namespace RE
{
	class TESObjectREFR;

	class TESForm :
		public BaseFormComponent,     // 00
		public TESFormRefCount,       // 08
		public BSReflection::IObject  // 10
	{
	public:
		SF_RTTI_VTABLE(TESForm);

		virtual ~TESForm();  // 00

		struct ACTIVATE_DATA
		{
			TESObjectREFR* activatedRef;
			TESObjectREFR* actionRef;
			TESForm*       objectToGet;
			std::int32_t   count;
			bool           unk1C;
		};

		// add
		virtual void          Unk_08();                                                         // 08
		virtual void          Unk_09();                                                         // 09
		virtual void          Unk_0A();                                                         // 0A
		virtual void          Unk_0B();                                                         // 0B
		virtual void          Unk_0C();                                                         // 0C
		virtual void          Unk_0D();                                                         // 0D
		virtual void          Unk_0E();                                                         // 0E
		virtual void          Unk_0F();                                                         // 0F
		virtual void          Unk_10();                                                         // 10
		virtual void          Unk_11();                                                         // 11
		virtual void          Unk_12();                                                         // 12
		virtual void          Unk_13();                                                         // 13
		virtual void          Unk_14();                                                         // 14
		virtual void          Unk_15();                                                         // 15
		virtual void          Unk_16();                                                         // 16
		virtual bool          AddChange(std::uint32_t a_changeFlags);                           // 17
		virtual void          RemoveChange(std::uint32_t a_changeFlags);                        // 18
		virtual void          Unk_19();                                                         // 19
		virtual void          Unk_1A();                                                         // 1A
		virtual void          Unk_1B();                                                         // 1B
		virtual void          Unk_1C();                                                         // 1C
		virtual void          Unk_1D();                                                         // 1D
		virtual void          Unk_1E();                                                         // 1E
		virtual void          InitItemImpl();                                                   // 1F
		virtual TESFile*      GetRevertFile() const;                                            // 20
		virtual TESFile*      GetDescriptionOwnerFile() const;                                  // 21
		virtual std::uint8_t  GetSavedFormType();                                               // 22
		virtual void          GetFormDetailedString(char* a_dest, std::uint32_t a_size) const;  // 23
		virtual bool          GetKnown() const;                                                 // 24
		virtual bool          GetRandomAnim() const;                                            // 25
		virtual bool          GetPlayable() const;                                              // 26
		virtual void          SetPlayable(bool a_set);                                          // 27
		virtual void          Unk_28();                                                         // 28
		virtual void          Unk_29();                                                         // 29
		virtual bool          GetDangerous() const;                                             // 2A
		virtual bool          QHasCurrents() const;                                             // 2B
		virtual bool          GetObstacle() const;                                              // 2C
		virtual void          Unk_2D();                                                         // 2D
		virtual bool          GetOnLocalMap() const;                                            // 2E
		virtual bool          GetMustUpdate() const;                                            // 2F
		virtual void          SetOnLocalMap(bool a_val);                                        // 30
		virtual void          Unk_31();                                                         // 31 - new?
		virtual void          Unk_32();                                                         // 32 - GetIgnoredBySandbox()?
		virtual void          SetDelete(bool a_deleted);                                        // 33
		virtual void          SetAltered(bool a_altered);                                       // 34
		virtual void          Unk_35();                                                         // 35
		virtual void          Unk_36();                                                         // 36
		virtual void          Unk_37();                                                         // 37
		virtual void          Unk_38();                                                         // 38
		virtual void          Unk_39();                                                         // 39
		virtual void          Unk_3A();                                                         // 3A
		virtual void          Unk_3B();                                                         // 3B
		virtual void          Unk_3C();                                                         // 3C
		virtual void          Unk_3D();                                                         // 3D
		virtual void          Unk_3E();                                                         // 3E
		virtual void          Unk_3F();                                                         // 3F
		virtual bool          IsFurniture();                                                    // 40 - new
		virtual void          Unk_41();                                                         // 41
		virtual void          Unk_42();                                                         // 42
		virtual void          Unk_43();                                                         // 43
		virtual void          Unk_44();                                                         // 44
		virtual void          Unk_45();                                                         // 45
		virtual void          Unk_46();                                                         // 46
		virtual void          Unk_47();                                                         // 47
		virtual void          Unk_48();                                                         // 48
		virtual void          Unk_49();                                                         // 49
		virtual void          Unk_4A();                                                         // 4A
		virtual void          Unk_4B();                                                         // 4B
		virtual std::uint32_t GetFullNameLength() const;                                        // 4C - new
		virtual const char*   GetFullName() const;                                              // 4D - new
		virtual void          Unk_4E();                                                         // 4E
		virtual void          Unk_4F();                                                         // 4F
		virtual void          Unk_50();                                                         // 50
		virtual void          Unk_51();                                                         // 51
		virtual void          Unk_52();                                                         // 52
		virtual void          Unk_53();                                                         // 53
		virtual bool          Activate(const ACTIVATE_DATA& a_activateData);                    // 54
		virtual void          Unk_55();                                                         // 55
		virtual void          Unk_56();                                                         // 56
		virtual void          Unk_57();                                                         // 57
		virtual void          Unk_58();                                                         // 58
		virtual void          Unk_59();                                                         // 59
		virtual void          Unk_5A();                                                         // 5A
		virtual void          Unk_5B();                                                         // 5B
		virtual void          Unk_5C();                                                         // 5C
		virtual std::uint32_t GetFilledSlots() const;                                           // 5D
		virtual std::uint32_t GetFilledSlotsImpl() const;                                       // 5E
		virtual float         GetDesirability() const;                                          // 5F
		virtual void          Unk_60();                                                         // 60
		virtual void          Unk_61();                                                         // 61

		// members
		std::uint64_t sourceFiles;  // 18 - TESFileContainer
		std::uint32_t unk20;        // 20
		std::uint32_t unk24;        // 24
		std::uint32_t formFlags;    // 28
		std::uint32_t unk2C;        // 2C
		std::uint32_t formID;       // 30
		std::uint8_t  unk34;        // 34 - also flag
		std::uint8_t  unk35;        // 35
		std::uint8_t  formType;     // 36
	};
	static_assert(sizeof(TESForm) == 0x38);
}
