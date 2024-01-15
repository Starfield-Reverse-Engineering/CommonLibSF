#pragma once

namespace RE
{
	struct DECAL_DATA_DATA
	{
	public:
		// members
		float decalMinWidth;   // 00
		float decalMaxWidth;   // 04
		float decalMinHeight;  // 08
		float decalMaxHeight;  // 0C
		float depth;           // 10
		float shininess;       // 14
	};
	static_assert(sizeof(DECAL_DATA_DATA) == 0x18);

	struct DecalData
	{
	public:
		// members
		DECAL_DATA_DATA data;  // 00
	};
	static_assert(sizeof(DecalData) == 0x18);
}
