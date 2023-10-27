#include "RE/E/ErrorLogger.h"

namespace RE::GameScript
{

	class BSLog;

	class __declspec(novtable) Logger :
		public BSScript::ErrorLogger  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::GameScript__Logger };
		static constexpr auto VTABLE{ VTABLE::GameScript__Logger };

		// override (BSScript::ErrorLogger)
		void PostErrorImpl(const BSScript::ICachedErrorMessage* a_errMsg, Severity a_severity) override;  // 01

		// members
		BSFixedString logFolder;  // 70
		BSLog*        log;        // 78
		std::uint64_t unk80;      // 80
	};
	static_assert(sizeof(Logger) == 0x88);
}