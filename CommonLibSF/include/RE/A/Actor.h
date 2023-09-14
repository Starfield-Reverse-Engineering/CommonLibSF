#pragma once

#include "RE/C/CombatGroup.h"
#include "RE/T/TESObjectREFR.h"

namespace RE
{
	class Actor : public TESObjectREFR
	{
	public:
		SF_RTTI_VTABLE(Actor);
		SF_FORMTYPE(ACHR);

		~Actor() override;  // 00

		inline static Actor* PlayerCharacter()
		{
			static REL::Relocation<Actor**> singleton{ REL::Offset(0x05595BA8) };
			return *singleton;
		}

		// add
		virtual void         Unk_130();                                     // 130
		virtual void         Unk_131();                                     // 131
		virtual void         Unk_132();                                     // 132
		virtual void         Unk_133();                                     // 133
		virtual void         Unk_134();                                     // 134
		virtual void         Unk_135();                                     // 135
		virtual void         Unk_136();                                     // 136
		virtual void         Unk_137();                                     // 137
		virtual void         Unk_138();                                     // 138
		virtual void         Unk_139();                                     // 139
		virtual void         Unk_13A();                                     // 13A
		virtual void         Unk_13B();                                     // 13B
		virtual void         Unk_13C();                                     // 13C
		virtual void         Unk_13D();                                     // 13D
		virtual void         Unk_13E();                                     // 13E
		virtual void         Update(float a_delta);                         // 13F
		virtual void         Unk_140();                                     // 140
		virtual void         Unk_141();                                     // 141
		virtual void         Unk_142();                                     // 142
		virtual void         Unk_143();                                     // 143
		virtual void         Unk_144();                                     // 144
		virtual void         Unk_145();                                     // 145
		virtual void         Unk_146();                                     // 146
		virtual void         Unk_147();                                     // 147
		virtual void         Unk_148();                                     // 148
		virtual void         Unk_149();                                     // 149
		virtual void         Unk_14A();                                     // 14A
		virtual void         Unk_14B();                                     // 14B
		virtual void         Unk_14C();                                     // 14C
		virtual void         Unk_14D();                                     // 14D
		virtual void         Unk_14E();                                     // 14E
		virtual void         Unk_14F();                                     // 14F
		virtual void         Unk_150();                                     // 150
		virtual void         Unk_151();                                     // 151
		virtual void         Unk_152();                                     // 152
		virtual void         Unk_153();                                     // 153
		virtual void         Unk_154();                                     // 154
		virtual void         Unk_155();                                     // 155
		virtual void         Unk_156();                                     // 156
		virtual void         Unk_157();                                     // 157
		virtual void         Unk_158();                                     // 158
		virtual void         Unk_159();                                     // 159
		virtual void         Unk_15A();                                     // 15A
		virtual void         Unk_15B();                                     // 15B
		virtual void         Unk_15C();                                     // 15C
		virtual void         Unk_15D();                                     // 15D
		virtual void         Unk_15E();                                     // 15E
		virtual void         Unk_15F();                                     // 15F
		virtual CombatGroup* GetCombatGroup();                              // 160
		virtual void         SetCombatGroup(CombatGroup* a_group);          // 161
		virtual bool         CheckValidTarget(TESObjectREFR& a_ref) const;  // 162
		virtual void         Unk_163();                                     // 163
		virtual void         Unk_164();                                     // 164
		virtual void         Unk_165();                                     // 165
		virtual void         Unk_166();                                     // 166
		virtual void         Unk_167();                                     // 167
		virtual void         Unk_168();                                     // 168
		virtual void         Unk_169();                                     // 169
		virtual void         Unk_16A();                                     // 16A
		virtual void         Unk_16B();                                     // 16B
		virtual bool         IsInCombat() const;                            // 16C
		virtual void         Unk_16D();                                     // 16D
		virtual void         Unk_16E();                                     // 16E
		virtual void         Unk_16F();                                     // 16F
		virtual void         SetLifeState(std::uint32_t a_state);           // 170
		virtual void         Unk_171();                                     // 171
		virtual void         Unk_172();                                     // 172
		virtual void         Unk_173();                                     // 173
		virtual void         Unk_174();                                     // 174
		virtual void         Unk_175();                                     // 175
		virtual void         Unk_176();                                     // 176
		virtual void         Unk_177();                                     // 177
		virtual void         Unk_178();                                     // 178
		virtual void         Unk_179();                                     // 179
		virtual void         Unk_17A();                                     // 17A
		virtual void         Unk_17B();                                     // 17B
		virtual void         Unk_17C();                                     // 17C
		virtual void         Unk_17D();                                     // 17D
		virtual void         Unk_17E();                                     // 17E
		virtual void         Unk_17F();                                     // 17F
		virtual void         Unk_180();                                     // 180
		virtual void         Unk_181();                                     // 181
		virtual void         Unk_182();                                     // 182
		virtual void         Unk_183();                                     // 183
		virtual void         Unk_184();                                     // 184
		virtual void         Unk_185();                                     // 185
		virtual void         Unk_186();                                     // 186
		virtual void         Unk_187();                                     // 187
		virtual void         Unk_188();                                     // 188
		virtual void         Unk_189();                                     // 189
		virtual void         Unk_18A();                                     // 18A
		virtual void         Unk_18B();                                     // 18B
		virtual void         Unk_18C();                                     // 18C
		virtual void         Unk_18D();                                     // 18D
		virtual void         Unk_18E();                                     // 18E
		virtual void         Unk_18F();                                     // 18F
		virtual void         Unk_190();                                     // 190
		virtual void         Unk_191();                                     // 191
		virtual void         Unk_192();                                     // 192
		virtual void         Unk_193();                                     // 193
		virtual void         Unk_194();                                     // 194
		virtual void         Unk_195();                                     // 195
		virtual void         Unk_196();                                     // 196
		virtual void         Unk_197();                                     // 197
		virtual void         Unk_198();                                     // 198
		virtual void         Unk_199();                                     // 199
		virtual void         Unk_19A();                                     // 19A
		virtual void         Unk_19B();                                     // 19B
		virtual void         Unk_19C();                                     // 19C
		virtual void         Unk_19D();                                     // 19D
		virtual void         Unk_19E();                                     // 19E
		virtual void         Unk_19F();                                     // 19F
		virtual void         Unk_1A0();                                     // 1A0
		virtual void         Unk_1A1();                                     // 1A1

		// More...
	};
}
