#pragma once

namespace RE
{
	enum class FormType
	{
		kNONE = 0,  // 00
		kTES4,      // 01
		kGRUP,      // 02
		kGMST,      // 03
		kKYWD,      // 04 BGSKeyword
		kFFKW,      // 05 BGSFormFolderKeywordList
		kLCRT,      // 06 BGSLocationRefType
		kAACT,      // 07 BGSAction
		kTRNS,      // 08 BGSTransform
		kTXST,      // 09 BGSTextureSet
		kGLOB,      // 0A TESGlobal
		kDMGT,      // 0B BGSDamageType
		kCLAS,      // 0C TESClass
		kFACT,      // 0D TESFaction
		kAFFE,      // 0E BGSAffinityEvent
		kHDPT,      // 0F BGSHeadPart
		kEYES,      // 10 TESEyes
		kRACE,      // 11 TESRace
		kSOUN,      // 12 TESSound
		kSECH,      // 13 BGSSoundEcho
		kASPC,      // 14 BGSAcousticSpace
		kAOPF,      // 15 BGSAudioOcclusionPrimitive
		kSKIL,      // 16
		kMGEF,      // 17 EffectSetting
		kSCPT,      // 18 Script
		kLTEX,      // 19 TESLandTexture
		kPDCL,      // 1A BGSProjectedDecal
		kENCH,      // 1B EnchantmentItem
		kSPEL,      // 1C SpellItem
		kSCRL,      // 1D ScrollItem
		kACTI,      // 1E TESObjectACTI
		kTACT,      // 1F BGSTalkingActivator
		kCURV,      // 20 BGSCurveForm
		kCUR3,      // 21 BGSCurve3DForm
		kARMO,      // 22 TESObjectARMO
		kBOOK,      // 23 TESObjectBOOK
		kCONT,      // 24 TESObjectCONT
		kDOOR,      // 25 TESObjectDOOR
		kINGR,      // 26 IngredientItem
		kLIGH,      // 27 TESObjectLIGH
		kMISC,      // 28 TESObjectMISC
		kSTAT,      // 29 TESObjectSTAT
		kSCOL,      // 2A BGSStaticCollection
		kPKIN,      // 2B BGSPackIn
		kMSTT,      // 2C BGSMovableStatic
		kGRAS,      // 2D TESGrass
		kFLOR,      // 2E TESFlora
		kFURN,      // 2F TESFurniture
		kWEAP,      // 30 TESObjectWEAP
		kAMMO,      // 31 TESAmmo
		kNPC_,      // 32 TESNPC
		kLVLN,      // 33 TESLevCharacter
		kLVLP,      // 34 BGSLevPackIn
		kKEYM,      // 35 TESKey
		kALCH,      // 36 AlchemyItem
		kIDLM,      // 37 BGSIdleMarker
		kBMMO,      // 38 BGSBiomeMarkerObject
		kNOTE,      // 39 BGSNote
		kPROJ,      // 3A BGSProjectile
		kHAZD,      // 3B BGSHazard
		kBNDS,      // 3C BGSBendableSpline
		kSLGM,      // 3D TESSoulGem
		kTERM,      // 3E BGSTerminal
		kLVLI,      // 3F TESLevItem
		kGBFT,      // 40 BGSGenericBaseFormTemplate
		kGBFM,      // 41 BGSGenericBaseForm
		kLVLB,      // 42 BGSLevGenericBaseForm
		kWTHR,      // 43 TESWeather
		kWTHS,      // 44 BGSWeatherSettingsForm
		kCLMT,      // 45 TESClimate
		kSPGD,      // 46 BGSShaderParticleGeometryData
		kREGN,      // 47 TESRegion
		kNAVI,      // 48 NavMeshInfoMap
		kCELL,      // 49 TESObjectCELL
		kREFR,      // 4A TESObjectREFR
		kACHR,      // 4B Actor
		kPMIS,      // 4C MissileProjectile
		kPARW,      // 4D ArrowProjectile
		kPGRE,      // 4E GrenadeProjectile
		kPBEA,      // 4F BeamProjectile
		kPFLA,      // 50 FlameProjectile
		kPCON,      // 51 ConeProjectile
		kPPLA,      // 52 PlasmaProjectile
		kPBAR,      // 53 BarrierProjectile
		kPEMI,      // 54 EmitterProjectile
		kPHZD,      // 55 Hazard
		kWRLD,      // 56 TESWorldSpace
		kNAVM,      // 57 NavMesh
		kTLOD,      // 58
		kDIAL,      // 59 TESTopic
		kINFO,      // 5A TESTopicInfo
		kQUST,      // 5B TESQuest
		kIDLE,      // 5C TESIdleForm
		kPACK,      // 5D TESPackage
		kCSTY,      // 5E TESCombatStyle
		kLSCR,      // 5F TESLoadScreen
		kLVSP,      // 60 TESLevSpell
		kANIO,      // 61 TESObjectANIO
		kWATR,      // 62 TESWaterForm
		kEFSH,      // 63 TESEffectShader
		kTOFT,      // 64
		kEXPL,      // 65 BGSExplosion
		kDEBR,      // 66 BGSDebris
		kIMGS,      // 67 TESImageSpace
		kIMAD,      // 68 TESImageSpaceModifier
		kFLST,      // 69 BGSListForm
		kPERK,      // 6A BGSPerk
		kBPTD,      // 6B BGSBodyPartData
		kADDN,      // 6C BGSAddonNode
		kAVIF,      // 6D ActorValueInfo
		kCAMS,      // 6E BGSCameraShot
		kCPTH,      // 6F BGSCameraPath
		kVTYP,      // 70 BGSVoiceType
		kMATT,      // 71 BGSMaterialType
		kIPCT,      // 72 BGSImpactData
		kIPDS,      // 73 BGSImpactDataSet
		kARMA,      // 74 TESObjectARMA
		kLCTN,      // 75 BGSLocation
		kMESG,      // 76 BGSMessage
		kRGDL,      // 77
		kDOBJ,      // 78 BGSDefaultObjectManager
		kDFOB,      // 79 BGSDefaultObject
		kLGTM,      // 7A BGSLightingTemplate
		kMUSC,      // 7B BGSMusicType
		kFSTP,      // 7C BGSFootstep
		kFSTS,      // 7D BGSFootstepSet
		kSMBN,      // 7E BGSStoryManagerBranchNode
		kSMQN,      // 7F BGSStoryManagerQuestNode
		kSMEN,      // 80 BGSStoryManagerEventNode
		kDLBR,      // 81 BGSDialogueBranch
		kMUST,      // 82 BGSMusicTrackFormWrapper
		kDLVW,      // 83
		kWOOP,      // 84 TESWordOfPower
		kSHOU,      // 85 TESShout
		kEQUP,      // 86 BGSEquipSlot
		kRELA,      // 87 BGSRelationship
		kSCEN,      // 88 BGSScene
		kASTP,      // 89 BGSAssociationType
		kOTFT,      // 8A BGSOutfit
		kARTO,      // 8B BGSArtObject
		kMATO,      // 8C BGSMaterialObject
		kMOVT,      // 8D BGSMovementType
		kDUAL,      // 8E BGSDualCastData
		kCOLL,      // 8F BGSCollisionLayer
		kCLFM,      // 90 BGSColorForm
		kREVB,      // 91 BGSReverbParameters
		kRFGP,      // 92 BGSReferenceGroup
		kAMDL,      // 93 BGSAimModel
		kAAMD,      // 94 BGSAimAssistModel
		kMAAM,      // 95 BGSMeleeAimAssistModel
		kLAYR,      // 96
		kCOBJ,      // 97 BGSConstructibleObject
		kOMOD,      // 98 BGSMod::Attachment::Mod
		kZOOM,      // 99 BGSAimDownSightModel
		kINNR,      // 9A BGSInstanceNamingRules
		kKSSM,      // 9B BGSSoundKeywordMapping
		kSCCO,      // 9C
		kAORU,      // 9D BGSAttractionRule
		kSTAG,      // 9E BGSSoundTagSet
		kIRES,      // 9F BGSResource
		kBIOM,      // A0 BGSBiome
		kNOCM,      // A1 NavMeshObstacleCoverManager
		kLENS,      // A2 BGSLensFlare
		kLSPR,      // A3
		kOVIS,      // A4 BGSObjectVisibilityManager
		kDLYR,      // A5
		kSTND,      // A6 BGSSnapTemplateNode
		kSTMP,      // A7 BGSSnapTemplate
		kGCVR,      // A8 BGSGroundCover
		kMRPH,      // A9 BGSMorphableObject
		kTRAV,      // AA BGSTraversal
		kRSGD,      // AB BGSResourceGenerationData
		kOSWP,      // AC BGSObjectSwap
		kATMO,      // AD BGSAtmosphere
		kLVSC,      // AE BGSLevSpaceCell
		kSPCH,      // AF BGSSpeechChallengeObject
		kRESO,      // B0
		kAAPD,      // B1 BGSAimAssistPoseData
		kVOLI,      // B2 BGSVolumetricLighting
		kSFBK,      // B3 BGSSurface::Block
		kSFPC,      // B4
		kSFPT,      // B5 BGSSurface::Pattern
		kSFTR,      // B6 BGSSurface::Tree
		kPCMT,      // B7 BGSPlanetContentManagerTree
		kBMOD,      // B8 BGSBoneModifier
		kSTBH,      // B9 BGSSnapBehavior
		kPNDT,      // BA BGSPlanet::PlanetData
		kIUTF,      // BB
		kCNDF,      // BC BGSConditionForm
		kPCBN,      // BD BGSPlanetContentManagerBranchNode
		kPCCN,      // BE BGSPlanetContentManagerContentNode
		kSTDT,      // BF BSGalaxy::BGSStar
		kWWED,      // C0 BGSWwiseEventForm
		kRSPJ,      // C1 BGSResearchProjectForm
		kAOPS,      // C2 BGSAimOpticalSightModel
		kAMBS,      // C3 BGSAmbienceSet
		kWBAR,      // C4 BGSWeaponBarrelModel
		kPTST,      // C5 BGSSurface::PatternStyle
		kLMSW,      // C6 BGSLayeredMaterialSwap
		kFORC,      // C7 BGSForceData
		kTMLM,      // C8 BGSTerminalMenu
		kEFSQ,      // C9 BGSEffectSequenceForm
		kSDLT,      // CA BGSSecondaryDamageList
		kMTPT,      // CB BGSMaterialPathForm
		kCLDF,      // CC BGSCloudForm
		kFOGV,      // CD BGSFogVolumeForm
		kWKMF,      // CE BGSWwiseKeywordMapping
		kLGDI,      // CF BGSLegendaryItem
		kPSDC,      // D0 BGSParticleSystemDefineCollection
		kSUNP,      // D1 BSGalaxy::BGSSunPresetForm
		kPMFT,      // D2 BGSPhotoModeFeature
		kTODD,      // D3 BGSTimeOfDayData
		kAVMD,      // D4 BGSAVMData
		kPERS,      // D5 TESDataHandlerPersistentCreatedUtil::BGSPersistentIDsForm
		kCHAL,      // D6 BGSChallengeForm

		kTotal  // D7
	};

	[[nodiscard]] const char* FormTypeToString(FormType a_formType);
	[[nodiscard]] FormType    StringToFormType(std::string_view a_formType);
}

namespace std
{
	[[nodiscard]] inline std::string to_string(RE::FormType a_formType)
	{
		return FormTypeToString(a_formType);
	}
}

#ifdef FMT_VERSION
namespace fmt
{
	template <>
	struct formatter<RE::FormType>
	{
		template <class ParseContext>
		constexpr auto parse(ParseContext& a_ctx)
		{
			return a_ctx.begin();
		}

		template <class FormatContext>
		auto format(const RE::FormType& a_formType, FormatContext& a_ctx)
		{
			return fmt::format_to(a_ctx.out(), "{}", FormTypeToString(a_formType));
		}
	};
}
#endif

#ifdef __cpp_lib_format
namespace std
{
	template <class CharT>
	struct formatter<RE::FormType, CharT> : std::formatter<std::string_view, CharT>
	{
		template <class FormatContext>
		auto format(RE::FormType a_formType, FormatContext& a_ctx)
		{
			return formatter<std::string_view, CharT>::format(FormTypeToString(a_formType), a_ctx);
		}
	};
}
#endif

#define SF_FORMTYPE(TYPE) \
	inline static constexpr auto FORMTYPE = RE::FormType::k##TYPE
