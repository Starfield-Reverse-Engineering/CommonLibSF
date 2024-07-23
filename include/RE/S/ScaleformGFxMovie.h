#pragma once

#include "RE/S/ScaleformGFxStateBag.h"
#include "RE/S/ScaleformPtr.h"

namespace RE::Scaleform::GFx
{
	class ASMovieRootBase;

	class Movie :
		public RefCountBase<Movie, 327>,  // 00
		public StateBag                   // 10
	{
	public:
		SF_RTTI_VTABLE(Scaleform__GFx__Movie);

		enum class SetVarType : std::uint32_t
		{
			kNormal,
			kSticky,
			kPermanent
		};

		enum class SetArrayType : std::uint32_t
		{
			kInt,
			kDouble,
			kFloat,
			kString,
			kStringW,
			kValue
		};

		virtual ~Movie() = default;  // 01

		// members
		Ptr<ASMovieRootBase> asMovieRoot;
	};

	class MovieImpl :
		public Movie  // 00
	{
	public:
		SF_RTTI_VTABLE(Scaleform__GFx__MovieImpl);

		virtual ~MovieImpl() = default;  // 00
	};
}
