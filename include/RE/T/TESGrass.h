#pragma once

#include "RE/T/TESBoundObject.h"
#include "RE/T/TESModel.h"

namespace RE
{
	class TESGrass :
		public TESBoundObject,  // 00
		public TESModel         // E0
	{
	public:
		SF_RTTI_VTABLE(TESGrass);
		SF_FORMTYPE(GRAS);

		struct GRASS_DATA  // DATA
		{
			enum class Flag
			{
				kNone = 0,
				kVertexLighting = 1 << 0,
				kUniformScale = 1 << 1,
				kFitSlope = 1 << 2
			};

			std::uint32_t                    unk00;       // 00
			float                            unk04;       // 04 - heightRange?
			float                            unk08;       // 08 - positionRange?
			float                            wavePeriod;  // 0C
			std::uint32_t                    unk10;       // 10
			std::uint32_t                    unk14;       // 14
			std::uint32_t                    unk18;       // 18
			std::uint32_t                    unk1C;       // 1C
			std::uint8_t                     density;     // 20
			std::uint8_t                     minSlope;    // 21
			std::uint8_t                     maxSlope;    // 22
			REX::EnumSet<Flag, std::uint8_t> flags;       // 23
			std::uint8_t                     unk24;       // 24
			std::uint8_t                     unk25;       // 25
		};
		static_assert(sizeof(GRASS_DATA) == 0x28);

		~TESGrass() override;  // 00

		// add
		virtual std::uint8_t GetDensity() const;                           // 82
		virtual bool         SetDensity(std::uint8_t a_density);           // 83
		virtual std::uint8_t GetMinSlopeDegrees() const;                   // 84
		virtual bool         SetMinSlopeDegrees(std::uint8_t a_minSlope);  // 85
		virtual std::uint8_t GetMaxSlopeDegrees() const;                   // 86
		virtual bool         SetMaxSlopeDegrees(std::uint8_t a_maxSlope);  // 87
		virtual float        GetMinSlope() const;                          // 88
		virtual float        GetMaxSlope() const;                          // 89
		virtual void         Unk_8A();                                     // 8A
		virtual void         Unk_8B();                                     // 8B
		virtual void         Unk_8C();                                     // 8C
		virtual void         Unk_8D();                                     // 8D
		virtual float        GetWavePeriod() const;                        // 8E
		virtual bool         SetWavePeriod(float a_wavePeriod);            // 8F
		virtual void         Unk_90();                                     // 90
		virtual void         Unk_91();                                     // 91
		virtual void         Unk_92();                                     // 92
		virtual void         Unk_93();                                     // 93
		virtual bool         GetVertexLighting() const;                    // 94
		virtual void         SetVertexLighting(bool a_set);                // 95
		virtual bool         GetUniformScaling() const;                    // 96
		virtual void         SetUniformScaling(bool a_set);                // 97
		virtual bool         GetFitToSlope() const;                        // 98
		virtual void         SetFitToSlope(bool a_set);                    // 99

		// members
		GRASS_DATA data;  // 100 - DATA
	};
	static_assert(sizeof(TESGrass) == 0x130);
}
