#pragma once




inline static bool SetTemporaryReference(RE::TESObjectREFR* theRef, bool bSet)
{
	if (!theRef)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(106946) };  // 0x1A3E588 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<void (*)(RE::TESObjectREFR*, bool)>(addr);
	int64_t                    unk = 0;
	func(theRef, bSet);
	return true;
}

inline static bool AddKeyword(RE::TESObjectREFR* akRef, RE::BGSKeyword* keyword)
{
	if (!akRef || !keyword)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(104525) };  // Starfield.exe + 196CB40 v1.12.30
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<void (*)(RE::TESObjectREFR*, RE::BGSKeyword*)>(addr);
	func(akRef, keyword);
	return true;
}

inline static bool AddPerk(RE::Actor* theActor, RE::BGSPerk* thePerk, bool bNotify = false)
{
	if (!theActor || !thePerk)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(170403) };  // 0x2B18A40 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(uintptr_t, uint32_t, RE::Actor*, RE::BGSPerk*, bool)>(addr);
	func(0, 0, theActor, thePerk, bNotify);
	return true;
}

inline static bool HasPerk(RE::Actor* theActor, RE::BGSPerk* thePerk)
{
	if (!theActor || !thePerk)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(170461) };  // 0x2B1FA10 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(uintptr_t, uint32_t, RE::Actor*, RE::BGSPerk*)>(addr);
	return func(0, 0, theActor, thePerk);
}

inline static bool RemovePerk(RE::Actor* theActor, RE::BGSPerk* thePerk)
{
	if (!theActor || !thePerk)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(151200) };  // 0x25EDE84 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(RE::Actor*, RE::BGSPerk*, uint8_t)>(addr);
	func(theActor, thePerk, 5);
	return true;
}

inline static int AddPerkToAll(std::vector<RE::Actor*> theActors, RE::BGSPerk* thePerk)
{
	if (theActors.empty() || !thePerk)
		return -1;
	int Result = 0;
	for (auto& it : theActors) {
		if (it && !HasPerk(it, thePerk)) {
			AddPerk(it, thePerk);
			Result = Result + 1;
		}
	}
	return Result;
}

inline static int RemovePerkFromAll(std::vector<RE::Actor*> theActors, RE::BGSPerk* thePerk)
{
	if (theActors.empty() || !thePerk)
		return -1;
	int Result = 0;
	for (auto& it : theActors) {
		if (it && HasPerk(it, thePerk)) {
			RemovePerk(it, thePerk);
			Result = Result + 1;
		}
	}
	return Result;
}

inline static bool SetReferenceName(RE::TESObjectREFR* theRef, std::string sName)
{
	if (!theRef)
		return false;
	auto extraList = theRef->extraDataList.get();
	if (!extraList)
		return false;
	if (sName.empty()) {
		auto baseForm = theRef->GetBaseObject();
		if (!baseForm)
			return false;
		auto fullName = Runtime_DynamicCast<RE::TESForm, RE::TESFullName>(baseForm);
		if (!fullName)
			return false;
		theRef->SetDisplayName(fullName->GetFullName());
	} else {
		theRef->SetDisplayName(sName.c_str());
	}
	return true;
}

inline static void DumpPapyrusStacks()
{
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(110456) };  // 0x1AFC448 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<char (*)()>(addr);
	func();
}

inline static bool IsStageDone(RE::TESQuest* theQuest, uint16_t uStage)
{
	if (!theQuest)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(112585) };  // 0x1B07BFC in v1.10.32.
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(RE::TESQuest*, uint16_t)>(addr);
	auto                       result = func(theQuest, uStage);
	return result;
}

inline static bool IsSneaking(RE::Actor* theActor)
{
	if (!theActor)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(151014) };  // 0x247EDB8 in v1.10.32.
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(RE::Actor*)>(addr);
	return func(theActor);
}

inline static float GetActorValuePercent(RE::Actor* theActor, RE::ActorValueInfo* actorValue)
{
	if (!theActor || !actorValue)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(108598) };  // 0x1A94008 in v1.12.32.
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<char (*)(RE::Actor**, RE::ActorValueInfo*, int64_t, float*)>(addr);
	int64_t                    unk = 0;
	float                      out = 0;
	auto                       Result = func(&theActor, actorValue, unk, &out);
	if (!out)
		return 0;
	return out;
}

inline static void EnableMenus(bool bEnable)
{
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(170823) };  //     Starfield.exe + 2B40160 (v1.12.32)
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<uintptr_t (*)(int64_t, int64_t, int64_t, char)>(addr);
	int64_t                    unk = 0;
	auto                       Result = func(unk, unk, unk, bEnable);
}

inline static bool ClearAllAliases(RE::TESQuest* theQuest)
{
	if (!theQuest)
		return false;
	REL::Relocation<uintptr_t> bQueuePtr{ REL::ID(881136) };  // 0x6889230 in v1.12.36
	uintptr_t                  bQueueAddr = bQueuePtr.address();
	auto                       bQueue = reinterpret_cast<int*>(bQueueAddr);
	if (bQueue)
		*bQueue = 1;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(112476) };  // 0x1B7331C in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<uintptr_t (*)(RE::TESQuest*)>(addr);
	auto                       result = func(theQuest);
	return true;
}

inline static bool IsTalking(RE::Actor* theActor)
{
	if (!theActor)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(170285) };  // 0x2B09E60 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(int64_t, int64_t, RE::Actor*)>(addr);
	int64_t                    unk = 0;
	auto                       result = func(unk, unk, theActor);
	return (result != 0);
}

inline static bool UpdateAppearance(RE::Actor* theActor, bool param02, uint32_t flags, bool bRace)
{
	if (!theActor)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(151216) };  // 0x25EEA00 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<void (*)(RE::Actor*, bool, uint32_t, bool)>(addr);
	func(theActor, param02, flags, bRace);
	return true;
}

inline static bool UpdateChargenAppearance(RE::Actor* theActor)
{
	if (!theActor)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(146273) };  // 0x243B804 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<void (*)(RE::Actor*)>(addr);
	func(theActor);
	return true;
}

inline static bool SetSkinTone(RE::Actor* theActor, uint32_t skinToneIndex)
{
	if (!theActor || skinToneIndex > 8)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(146270) };  // 0x243B3CC in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<void (*)(RE::Actor*, uint32_t)>(addr);
	func(theActor, skinToneIndex);
	return true;
}

inline static bool DrawWeapon(RE::Actor* theActor)
{
	if (!theActor)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(170420) };  // 0x2B1B830 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<uintptr_t (*)(int64_t, int64_t, RE::Actor*)>(addr);
	int64_t                    unk = 0;
	func(unk, unk, theActor);
	return true;
}

inline static bool EvaluatePackage(RE::Actor* theActor, bool bResetAI)
{
	if (!theActor || theActor->formID == 0x14)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(150640) };  // 0x25C39BC in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<void (*)(RE::Actor*, bool, bool)>(addr);
	func(theActor, false, bResetAI);
	return true;
}

inline static int EvaluatePackageForAll(std::vector<RE::Actor*> theActors, bool bResetAI)
{
	if (theActors.empty())
		return -1;
	int Result = 0;
	for (auto& it : theActors) {
		if (!it)
			continue;
		if (EvaluatePackage(it, bResetAI))
			Result = Result + 1;
	}
	return Result;
}

inline static bool IsDetectedBy(RE::Actor* theDetected, RE::Actor* theDetecter)
{
	if (!theDetected || !theDetecter)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(170476) };  // 0x2B1FCF0 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(uintptr_t, uint32_t, RE::Actor*, RE::Actor*)>(addr);
	return func(0, 0, theDetected, theDetecter);
}

inline static bool HasDetectionLOS(RE::Actor* theDetected, RE::Actor* theDetecter)
{
	if (!theDetected || !theDetecter)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(170456) };  // 0x2B1F260 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(uintptr_t, uint32_t, RE::Actor*, RE::Actor*)>(addr);
	return func(0, 0, theDetected, theDetecter);
}

inline static float GetKnockStateEnum(RE::Actor* theActor)
{
	if (!theActor)
		return -1.0f;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(108758) };  // 0x1A9B9F0 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(RE::Actor**, int64_t, int64_t, float*)>(addr);
	float                      fOut = 0.0f;
	float*                     fOutPtr = &fOut;
	auto                       result = func(&theActor, 0, 0, fOutPtr);
	if (fOutPtr)
		return *fOutPtr;
	return 0.0f;
}

inline static float GetActorGunState(RE::Actor* theActor)
{
	if (!theActor)
		return -1.0f;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(108590) };  // 0x1A93B54 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(RE::Actor**, int64_t, int64_t, float*)>(addr);
	float                      fOut = 0.0f;
	float*                     fOutPtr = &fOut;
	auto                       result = func(&theActor, 0, 0, fOutPtr);
	if (fOutPtr)
		return *fOutPtr;
	return 0.0f;
}

inline static bool IsMovingForward(RE::Actor* theActor)
{
	if (theActor && static_cast<bool>(theActor->actorState1.movingForward))
		return true;
	return false;
}

inline static bool IsMovingBackward(RE::Actor* theActor)
{
	if (theActor && static_cast<bool>(theActor->actorState1.movingBack))
		return true;
	return false;
}

inline static bool IsMovingLeft(RE::Actor* theActor)
{
	if (theActor && static_cast<bool>(theActor->actorState1.movingLeft))
		return true;
	return false;
}

inline static bool IsMovingRight(RE::Actor* theActor)
{
	if (theActor && static_cast<bool>(theActor->actorState1.movingRight))
		return true;
	return false;
}

inline static bool IsJumping(RE::Actor* theActor)
{
	if (!theActor)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(150985) };  // Starfield.exe + 0x25DAD1C v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(RE::Actor*)>(addr);
	return func(theActor);
}

inline static bool IsOverencumbered(RE::Actor* theActor)
{
	if (!theActor)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(150999) };  // Starfield.exe + 0x25DB580 v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(RE::Actor*)>(addr);
	return func(theActor);
}

inline static bool AreHostileActorsNear()
{
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(171035) };  // 0x29ECFC0 in v1.10.32
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)()>(addr);
	return func();
}

inline static bool IsSwimming(RE::Actor* theActor)
{
	if (theActor && static_cast<bool>(theActor->actorState1.swimming))
		return true;
	return false;
}

inline static bool IsInWater(RE::Actor* theActor)
{
	if (theActor && theActor->boolBits.any(RE::Actor::BOOL_BITS::kInWater))
		return true;
	return false;
}

inline static bool IsInCombatSearch(RE::Actor* theActor)
{
	if (theActor && theActor->boolBits.any(RE::Actor::BOOL_BITS::kSearchingInCombat))
		return true;
	return false;
}

inline static bool DoesAffectStealthMeter(RE::Actor* theActor)
{
	if (theActor && theActor->formID != 0x14 && !theActor->boolFlags.any(RE::Actor::BOOL_FLAGS::kDoNotShowOnStealthMeter))
		return true;
	return false;
}

inline static bool IsWalking(RE::Actor* theActor)
{
	if (theActor && static_cast<bool>(theActor->actorState1.walking))
		return true;
	return false;
}

inline static bool IsWeaponDrawn(RE::Actor* theActor)
{
	if (!theActor)
		return false;
	unsigned long long theActorAddr = reinterpret_cast<unsigned long long>(theActor);
	uint32_t*          WeaponStatePtr = reinterpret_cast<uint32_t*>(theActorAddr + 0xF4);  // since v1.10.31.
	if (!WeaponStatePtr)
		return false;
	auto WeaponState = static_cast<int>(*WeaponStatePtr & 7);
	return (WeaponState <= 3 && WeaponState >= 1);
}

inline static bool IsInDialogueWithPlayer(RE::TESObjectREFR* theRef)
{
	if (!theRef)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(108949) };  // 0x1A891C4 in v1.12.32
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(RE::TESObjectREFR**, int64_t, int64_t, uint32_t*)>(addr);
	uint32_t                   out = 0;
	auto                       result = func(&theRef, 0, 0, &out);
	return (out != 0);
}

inline static bool GetGraphVariableBool(RE::TESObjectREFR* theRef, std::string sVar)
{
	if (!theRef || sVar.empty())
		return -1;
	auto                       graphManager = (RE::IAnimationGraphManagerHolder*)theRef;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(118424) };  // 0x1D30930 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<bool (*)(RE::IAnimationGraphManagerHolder*, RE::BSFixedString*, bool*)>(addr);
	RE::BSFixedString          bsVar(sVar);
	bool                       out = 0;
	auto                       result = func(graphManager, &bsVar, &out);
	return out;
}

inline static bool WornHasKeyword(RE::Actor* theActor, RE::BGSKeyword* theKeyword)  // v1.3
{
	if (!theActor || !theKeyword)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(106992) };
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<int (*)(RE::Actor*, RE::BGSKeyword*)>(addr);
	auto                       result = func(theActor, theKeyword);
	return result;
}

inline static float GetDistance(RE::TESObjectREFR* theRef01, RE::TESObjectREFR* theRef02)  // v1.9
{
	if (!theRef01 || !theRef02)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(106562) };  // 0x1A245C8 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<float (*)(RE::TESObjectREFR*, RE::TESObjectREFR*, bool)>(addr);
	auto                       result = func(theRef01, theRef02, false);
	return result;
}

inline static bool ChangeAnimArchetype(RE::Actor* theActor, RE::BGSKeyword* animKeyword)
{
	if (!theActor || !animKeyword)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(150497) };  // 0x25BA0DC in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<uintptr_t (*)(RE::Actor*, RE::BGSKeyword*)>(addr);
	int64_t                    unk = 0;
	auto                       result = func(theActor, animKeyword);
	return (result != 0);
}

inline static float GetScale(RE::TESObjectREFR* theRef)  // v1.1
{
	if (!theRef)
		return 0;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(106658) };  // 0x1A27A6C in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<float (*)(RE::TESObjectREFR*)>(addr);
	int64_t                    unk = 0;
	auto                       result = func(theRef);
	return result;
}

inline static float GetAngle(RE::TESObjectREFR* theRef, char chAxis)  // v1.9
{
	if (!theRef)
		return 0;
	std::string sAxis = std::string(1, chAxis);
	float       angle = 0.0f;
	float       result = 0.0f;
	int         axis = 0;
	if (chAxis == 'x' || chAxis == 'X')
		angle = theRef->data.angle.x;
	else if (chAxis == 'y' || chAxis == 'Y')
		angle = theRef->data.angle.y;
	else if (chAxis == 'z' || chAxis == 'Z')
		angle = theRef->data.angle.z;
	else {
		return 0.00f;
	}
	try {
		result = angle / static_cast<float>(0.0174532925);
	} catch (...) {
		return 0.00f;
	}
	return result;
}

inline static RE::TESClass* GetClass(RE::TESNPC* theActor)
{
	if (!theActor)
		return nullptr;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(171597) };  // 0x2B8C070 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<RE::TESClass* (*)(int64_t, int64_t, RE::TESNPC*)>(addr);
	int64_t                    unk = 0;
	auto                       result = func(unk, unk, theActor);
	return result;
}

inline static RE::TESRace* GetRace(RE::TESNPC* theActorBase)
{
	if (!theActorBase)
		return nullptr;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(171601) };  // 0x2B8C0C0 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<RE::TESRace* (*)(int64_t, int64_t, RE::TESNPC*)>(addr);
	int64_t                    unk = 0;
	auto                       result = func(unk, unk, theActorBase);
	return result;
}

inline static bool IsFlashlightOn()
{                                                                    // v1.1     // returns whether the player's flashlight is supposed to be on/off, not whether the light node actually exists
	const REL::Relocation<std::uintptr_t> reloc{ REL::ID(881141) };  // 0x6889242 in v1.12.36
	uintptr_t                             addr = reloc.address();
	const auto                            uint8_tPtr = reinterpret_cast<uint8_t*>(addr);
	bool                                  result = (uint8_tPtr && *uint8_tPtr == 1);
	return result;
}

inline static bool SetFlashlightState(RE::TESObjectREFR* akRef, bool bOn)  // v1.1
{
	if (!akRef)
		return false;
	REL::Relocation<uintptr_t> funcPtr{ REL::ID(153762) };  // 0x26D3A34 in v1.12.36
	uintptr_t                  addr = funcPtr.address();
	const auto                 func = reinterpret_cast<uintptr_t (*)(RE::TESObjectREFR*, bool)>(addr);
	int64_t                    unk = 0;
	auto                       result = func(akRef, bOn);
	return true;
}

inline static bool IsSpacesuitHelmetVisible(RE::Actor* theActor)
{
	if (theActor && GetGraphVariableBool(theActor, "bHelmetIsVisible"))
		return true;
	return false;
}

inline static void ShowDebugMessageBox(std::string Message)
{
	REL::Relocation<uintptr_t> ptr{ REL::ID(170828) };  // 0x2B403A0 in v1.12.36
	uintptr_t                  addr = ptr.address();
	const auto                 func = reinterpret_cast<void (*)(uintptr_t, uintptr_t, uintptr_t, RE::BSFixedString*)>(addr);
	RE::BSFixedString          msg(Message.c_str());
	func(0, 0, 0, &msg);
}
