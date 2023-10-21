#pragma once

#include "RE/B/BSReflection.h"
#include "RE/T/TESFile.h"
#include "RE/T/TESFormRefCount.h"

namespace RE
{
	class BGSLoadFormBuffer;
	class BGSPreviewTransform;
	class BGSSaveFormBuffer;
	class BGSSnapTemplateComponent;
	class TESObjectREFR;

	namespace BGSMod::Template
	{
		class Items;
	}

	struct FORM;
	struct FORM_GROUP;

	class TESForm :
		public TESFormRefCount,       // 00
		public BSReflection::IObject  // 10
	{
	public:
		SF_RTTI_VTABLE(TESForm);
		SF_FORMTYPE(NONE);

		struct ActivateData
		{
			TESObjectREFR* activatedRef;  // 00
			TESObjectREFR* actionRef;     // 08
			TESForm*       objectToGet;   // 10
			std::int32_t   count;         // 18
			bool           unk1C;         // 1C
			bool           unk1D;         // 1D
			bool           unk1E;         // 1E
			bool           unk1F;         // 1F
		};
		static_assert(sizeof(ActivateData) == 0x20);

		~TESForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return ""; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// add
		virtual void                               Unk_0B();                                                                         // 0B
		virtual void                               Unk_0C();                                                                         // 0C
		virtual void                               Unk_0D();                                                                         // 0D
		virtual void                               Unk_0E();                                                                         // 0E
		virtual void                               Unk_0F();                                                                         // 0F
		virtual void                               Unk_10();                                                                         // 10
		virtual void                               Unk_11();                                                                         // 11
		virtual void                               Unk_12();                                                                         // 12
		virtual void                               Unk_13();                                                                         // 13
		virtual void                               Unk_14();                                                                         // 14
		virtual void                               Unk_15();                                                                         // 15
		virtual void                               Unk_16();                                                                         // 16
		virtual bool                               AddChange(std::uint32_t a_changeFlags);                                           // 17
		virtual void                               RemoveChange(std::uint32_t a_changeFlags);                                        // 18
		virtual bool                               CheckSaveGame(BGSSaveFormBuffer* a_saveGameBuffer);                               // 19
		virtual void                               SaveGame(BGSSaveFormBuffer* a_saveGameBuffer);                                    // 1A
		virtual void                               LoadGame(BGSLoadFormBuffer* a_loadGameBuffer);                                    // 1B
		virtual void                               InitLoadGame(BGSLoadFormBuffer* a_loadGameBuffer);                                // 1C
		virtual void                               FinishLoadGame(BGSLoadFormBuffer* a_loadGameBuffer);                              // 1D
		virtual void                               Revert(BGSLoadFormBuffer* a_loadGameBuffer);                                      // 1E
		virtual void                               InitItemImpl();                                                                   // 1F
		virtual TESFile*                           GetRevertFile() const;                                                            // 20
		virtual TESFile*                           GetDescriptionOwnerFile() const;                                                  // 21
		virtual std::uint8_t                       GetSavedFormType();                                                               // 22
		virtual void                               GetFormDetailedString(char* a_dest, std::uint32_t a_size) const;                  // 23
		virtual bool                               GetKnown() const;                                                                 // 24
		virtual bool                               GetRandomAnim() const;                                                            // 25
		virtual bool                               GetPlayable() const;                                                              // 26
		virtual void                               SetPlayable(bool a_set);                                                          // 27
		virtual void                               Unk_28();                                                                         // 28
		virtual void                               Unk_29();                                                                         // 29
		virtual bool                               GetDangerous() const;                                                             // 2A
		virtual bool                               QHasCurrents() const;                                                             // 2B
		virtual bool                               GetObstacle() const;                                                              // 2C
		virtual void                               Unk_2D();                                                                         // 2D
		virtual bool                               GetOnLocalMap() const;                                                            // 2E
		virtual bool                               GetMustUpdate() const;                                                            // 2F
		virtual void                               SetOnLocalMap(bool a_val);                                                        // 30
		virtual void                               Unk_31();                                                                         // 31 - new?
		virtual void                               Unk_32();                                                                         // 32 - GetIgnoredBySandbox()?
		virtual void                               SetDelete(bool a_deleted);                                                        // 33
		virtual void                               SetAltered(bool a_altered);                                                       // 34
		virtual void                               Unk_35();                                                                         // 35
		virtual void                               Unk_36();                                                                         // 36
		virtual void                               Unk_37();                                                                         // 37
		virtual void                               Unk_38();                                                                         // 38
		virtual void                               Unk_39();                                                                         // 39
		virtual void                               Unk_3A();                                                                         // 3A
		virtual void                               Unk_3B();                                                                         // 3B
		virtual void                               Unk_3C();                                                                         // 3C
		virtual bool                               IsBoundObject() const;                                                            // 3D
		virtual void                               Unk_3E();                                                                         // 3E
		virtual void                               Unk_3F();                                                                         // 3F
		virtual bool                               IsFurniture();                                                                    // 40 - new
		virtual void                               Unk_41();                                                                         // 41
		virtual void                               Unk_42();                                                                         // 42
		virtual void                               Unk_43();                                                                         // 43
		virtual void                               Unk_44();                                                                         // 44
		virtual TESObjectREFR*                     AsReference1();                                                                   // 45
		[[nodiscard]] virtual const TESObjectREFR* AsReference2() const;                                                             // 46
		virtual void                               Unk_47();                                                                         // 47
		virtual const char*                        GetTextForParsedSubTag(const BSFixedString& a_subTag) const;                      // 48
		virtual void                               Copy(TESForm* a_copy);                                                            // 49
		virtual bool                               BelongsInGroup(FORM* a_groupFORM, bool a_allowParentGroups, bool a_currentOnly);  // 4A
		virtual void                               CreateGroupData(FORM* a_outGroupFORM, FORM_GROUP* a_parentGroup);                 // 4B
		virtual std::uint32_t                      GetFormEditorIDLength() const;                                                    // 4C
		virtual const char*                        GetFormEditorID() const;                                                          // 4D
		virtual bool                               SetFormEditorID(const char* a_editorID);                                          // 4E
		virtual void                               Unk_4F();                                                                         // 4F
		virtual void                               Unk_50();                                                                         // 50
		virtual void                               Unk_51();                                                                         // 51
		virtual void                               Unk_52();                                                                         // 52
		virtual bool                               LoopingActivate(TESObjectREFR* a_itemActivated, TESObjectREFR* a_actionRef);      // 53
		virtual bool                               Activate(const ActivateData& a_activateData);                                     // 54
		virtual const char*                        GetObjectTypeName() const;                                                        // 55
		virtual void                               Unk_56();                                                                         // 56
		virtual void                               Unk_57();                                                                         // 57
		virtual BGSMod::Template::Items*           AsObjectTemplate1();                                                              // 58
		virtual const BGSMod::Template::Items*     AsObjectTemplate2() const;                                                        // 59
		virtual BGSPreviewTransform*               AsPreviewTransform1();                                                            // 5A
		virtual const BGSPreviewTransform*         AsPreviewTransform2() const;                                                      // 5B
		virtual BGSSnapTemplateComponent*          AsSnapTemplate();                                                                 // 5C
		virtual std::uint32_t                      GetFilledSlots() const;                                                           // 5D
		virtual std::uint32_t                      GetFilledSlotsImpl() const;                                                       // 5E
		virtual float                              GetDesirability() const;                                                          // 5F
		virtual void                               Unk_60();                                                                         // 60
		virtual void                               Unk_61();                                                                         // 61

		std::uint64_t DecRefCount() const
		{
			using func_t = decltype(&TESForm::DecRefCount);
			REL::Relocation<func_t> func{ ID::TESForm::DecRefCount };
			return func(this);
		}

		[[nodiscard]] static TESForm* LookupByID(std::uint32_t a_formID)
		{
			using func_t = decltype(&TESForm::LookupByID);
			REL::Relocation<func_t> func{ ID::TESForm::LookupByID };
			return func(a_formID);
		}

		[[nodiscard]] static TESForm* LookupByEditorID(const char* a_editorID)
		{
			using func_t = decltype(&TESForm::LookupByEditorID);
			REL::Relocation<func_t> func{ ID::TESForm::LookupByEditorID };
			return func(a_editorID);
		}

		[[nodiscard]] TESObjectREFR*       AsReference() { return AsReference1(); }
		[[nodiscard]] const TESObjectREFR* AsReference() const { return AsReference2(); }

		[[nodiscard]] std::uint32_t GetFormFlags() const noexcept { return formFlags; }
		[[nodiscard]] std::uint32_t GetFormID() const noexcept { return formID; }
		[[nodiscard]] FormType      GetFormType() const noexcept { return *formType; }

		[[nodiscard]] bool Is(FormType a_type) const noexcept { return GetFormType() == a_type; }

		template <class... Args>
		[[nodiscard]] bool Is(Args... a_args) const noexcept
			requires(std::same_as<Args, FormType> && ...)
		{
			return (Is(a_args) || ...);
		}

		template <class T>
		[[nodiscard]] bool Is() const noexcept
			requires(std::derived_from<T, TESForm> &&
					 !std::is_pointer_v<T> &&
					 !std::is_reference_v<T>)
		{
			return Is(T::FORMTYPE);
		}

		[[nodiscard]] bool IsActor() const noexcept { return Is(FormType::kACHR); }
		[[nodiscard]] bool IsAmmo() const noexcept { return Is(FormType::kAMMO); }
		[[nodiscard]] bool IsArmor() const noexcept { return Is(FormType::kARMO); }
		[[nodiscard]] bool IsBook() const noexcept { return Is(FormType::kBOOK); }
		[[nodiscard]] bool IsCreated() const noexcept { return (GetFormID() + 0x1000000) <= 0xFFFFFE; }
		[[nodiscard]] bool IsCredits() const noexcept { return GetFormID() == 0x0000000F; }
		[[nodiscard]] bool IsDeleted() const noexcept { return (GetFormFlags() & 0x20) != 0; }
		[[nodiscard]] bool IsDigiPick() const noexcept { return GetFormID() == 0x0000000A; }

		[[nodiscard]] bool IsNot(FormType a_type) const noexcept { return !Is(a_type); }

		template <class... Args>
		[[nodiscard]] bool IsNot(Args... a_args) const noexcept
			requires(std::same_as<Args, FormType> && ...)
		{
			return (IsNot(a_args) && ...);
		}

		[[nodiscard]] bool IsPlayer() const noexcept { return GetFormID() == 0x00000007; }
		[[nodiscard]] bool IsPlayerRef() const noexcept { return GetFormID() == 0x00000014; }
		[[nodiscard]] bool IsWeapon() const noexcept { return Is(FormType::kWEAP); }

		// members
		std::uint64_t                            sourceFiles;  // 18 - TESFileContainer
		std::uint32_t                            unk20;        // 20
		std::uint32_t                            unk24;        // 24
		std::uint32_t                            formFlags;    // 28
		std::uint32_t                            unk2C;        // 2C
		std::uint32_t                            formID;       // 30
		std::uint8_t                             unk34;        // 34 - also flag
		std::uint8_t                             unk35;        // 35
		stl::enumeration<FormType, std::uint8_t> formType;     // 36
	};
	static_assert(sizeof(TESForm) == 0x38);
}
