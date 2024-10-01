#pragma once

#include "RE/B/BSTList.h"
#include "RE/T/TESForm.h"

namespace RE
{
	class BGSWeatherSettingsForm;
	class TESWeather;
	class TESGlobal;

	struct WeatherEntry
	{
	public:
		// members
		TESGlobal*    chanceVar;  // 00
		TESWeather*   weather;    // 08
		std::uint32_t chance;     // 10
	};
	static_assert(sizeof(WeatherEntry) == 0x18);

	struct WeatherSettings
	{
	public:
		// members
		BGSWeatherSettingsForm* weatherSettings;  // 00
		TESGlobal*              chanceVar;        // 08
		std::uint32_t           chance;           // 10
	};
	static_assert(sizeof(WeatherSettings) == 0x18);

	struct Timing
	{
	public:
		struct Interval
		{
		public:
			// members
			std::uint8_t begin;  // 0
			std::uint8_t end;    // 1
		};
		static_assert(sizeof(Interval) == 0x2);

		// members
		Interval     sunrise;     // 0
		Interval     sunset;      // 2
		std::uint8_t volatility;  // 4
	};
	static_assert(sizeof(Timing) == 0x5);

	class TESClimate : public TESForm
	{
	public:
		SF_RTTI_VTABLE(TESClimate);
		SF_FORMTYPE(CLMT);

		~TESClimate() override;  // 00

		// members
		std::vector<WeatherEntry*>     weatherTypes;     // 30
		BSSimpleList<WeatherSettings*> weatherSettings;  // 48
		Timing                         timing;           // 58
	};
	static_assert(sizeof(TESClimate) == 0x68);
}
