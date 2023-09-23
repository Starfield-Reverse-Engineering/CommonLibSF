#pragma once

#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

class TESWorldSpace : public RE::TESForm,    // 00
    public RE::TESFullName // 20
{
public:
    SF_FORMTYPE(WRLD);
};
