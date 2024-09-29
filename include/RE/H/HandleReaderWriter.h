#pragma once

#include "RE/B/BSCoreTypes.h"
#include "RE/I/IHandleReaderWriter.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/T/TESFile.h"

namespace RE::GameScript
{
	class __declspec(novtable) BaseHandleReaderWriter :
		public RE::BSScript::IHandleReaderWriter
	{
	public:
		SF_RTTI(GameScript__BaseHandleReaderWriter);

		~BaseHandleReaderWriter() override;  // 0

		// override (BSScript::IHandleReaderWriter)
		virtual std::uint16_t GetHandleVersion() const override;                                           // 1
		virtual bool          WriteHandle(BSStorage& storage, std::uint64_t) const override;               // 2
		virtual bool          ReadHandle(BSStorage const& storage, std::uint64_t&) const override;         // 3
		virtual bool          ReadHandleNoRemap(BSStorage const& storage, std::uint64_t&) const override;  // 4

		// add
		virtual bool WriteFormID(BSStorage& storage, TESFormID) const = 0;        // 5
		virtual bool ReadFormID(const BSStorage& storage, TESFormID&) const = 0;  // 6

		// members
		BSScript::IObjectHandlePolicy* objectHandlePolicy;  //08
	};
	static_assert(sizeof(BaseHandleReaderWriter) == 0x10);

	class SaveFileHandleReaderWriter :
		public BaseHandleReaderWriter
	{
	public:
		SF_RTTI_VTABLE(GameScript__SaveFileHandleReaderWriter);

		~SaveFileHandleReaderWriter() override;  // 0
		//SaveFileHandleReaderWriter(BSScript::IObjectHandlePolicy * objectHandlePolicy);

		// override (GameScript::BaseHandleReaderWriter)
		virtual bool WriteFormID(BSStorage& storage, TESFormID) const override;        // 5
		virtual bool ReadFormID(const BSStorage& storage, TESFormID&) const override;  // 6
	};
	static_assert(sizeof(SaveFileHandleReaderWriter) == 0x10);

	class DataFileHandleReaderWriter :
		public BaseHandleReaderWriter
	{
	public:
		SF_RTTI_VTABLE(GameScript__DataFileHandleReaderWriter);

		~DataFileHandleReaderWriter() override;  // 0
		//DataFileHandleReaderWriter(TESFile *f, BSScript::IObjectHandlePolicy * objectHandlePolicy);

		// override (GameScript::BaseHandleReaderWriter)
		virtual bool WriteFormID(BSStorage& storage, TESFormID) const override;        // 5
		virtual bool ReadFormID(const BSStorage& storage, TESFormID&) const override;  // 6

		// members
		TESFile* file;  //10
	};
	static_assert(sizeof(DataFileHandleReaderWriter) == 0x18);
}
