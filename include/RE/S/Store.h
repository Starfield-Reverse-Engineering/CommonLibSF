#pragma once

#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IStore.h"
#include "RE/S/Stream.h"

namespace RE::GameScript
{
	class Store : public BSScript::IStore
	{
	public:
		SF_RTTI_VTABLE(GameScript__Store);

		virtual ~Store() override;  // 00

		// override (BSScript::IStore)
		virtual bool                 Open(const char* a_fileName) override;  // 06
		virtual bool                 Close() override;                       // 07
		virtual const BSFixedString& StoreName() const override;             // 08
		virtual bool                 GetIsOpen() const override;             // 09
		virtual bool                 GetIsGood() const override;             // 0A
		virtual bool                 GetIsEOS() const override;              // 0B

		// members
		size_t                              streamPos;    // 20
		BSTSmartPointer<BSResource::Stream> stream;       // 28
		BSFixedString                       relPath;      // 30
		bool                                hasOpenFile;  // 38
		bool                                fileIsGood;   // 39
	};
	static_assert(sizeof(Store) == 0x40);
}
