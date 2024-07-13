#pragma once

namespace RE::Scaleform::GFx
{
	class MovieImpl;

	class Value
	{
	public:
		enum class ValueType : std::int32_t
		{
			kUndefined,
			kNull,
			kBoolean,
			kInt,
			kUInt,
			kNumber,
			kString,
			kStringW,
			kObject,
			kArray,
			kDisplayObject,
			kClosure,

			kOrphanedBit = 1 << 5,
			kManagedBit = 1 << 6,
			kConvertBit = 1 << 7,

			kTypeMask = kConvertBit | 0x0F,

			kConvertBoolean = kConvertBit | kBoolean,
			kConvertInt = kConvertBit | kInt,
			kConvertUInt = kConvertBit | kUInt,
			kConvertNumber = kConvertBit | kNumber,
			kConvertString = kConvertBit | kString,
			kConvertStringW = kConvertBit | kStringW
		};

		union ValueUnion
		{
			ValueUnion() noexcept :
				data(nullptr)
			{}

			ValueUnion(const ValueUnion& a_rhs) noexcept :
				data(a_rhs.data)
			{}

			ValueUnion(ValueUnion&& a_rhs) noexcept :
				data(a_rhs.data)
			{
				a_rhs.data = nullptr;
			}

			explicit ValueUnion(const std::int32_t a_rhs) noexcept :
				int32(a_rhs)
			{}

			explicit ValueUnion(const std::uint32_t a_rhs) noexcept :
				uint32(a_rhs)
			{}

			explicit ValueUnion(const double a_rhs) noexcept :
				number(a_rhs)
			{}

			explicit ValueUnion(const bool a_rhs) noexcept :
				boolean(a_rhs)
			{}

			explicit ValueUnion(const char* a_rhs) noexcept :
				string(a_rhs)
			{}

			explicit ValueUnion(const wchar_t* a_rhs) noexcept :
				wstring(a_rhs)
			{}

			ValueUnion& operator=(const ValueUnion& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					data = a_rhs.data;
				}
				return *this;
			}

			ValueUnion& operator=(ValueUnion&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					data = a_rhs.data;
					a_rhs.data = nullptr;
				}
				return *this;
			}

			ValueUnion& operator=(const std::int32_t a_rhs) noexcept
			{
				int32 = a_rhs;
				return *this;
			}

			ValueUnion& operator=(const std::uint32_t a_rhs) noexcept
			{
				uint32 = a_rhs;
				return *this;
			}

			ValueUnion& operator=(const double a_rhs) noexcept
			{
				number = a_rhs;
				return *this;
			}

			ValueUnion& operator=(const bool a_rhs) noexcept
			{
				boolean = a_rhs;
				return *this;
			}

			ValueUnion& operator=(const char* a_rhs) noexcept
			{
				string = a_rhs;
				return *this;
			}

			ValueUnion& operator=(const wchar_t* a_rhs) noexcept
			{
				wstring = a_rhs;
				return *this;
			}

			std::int32_t   int32;
			std::uint32_t  uint32;
			double         number;
			bool           boolean;
			const char*    string;
			const char**   mstring;
			const wchar_t* wstring;
			void*          data;
		};
		static_assert(sizeof(ValueUnion) == 0x8);

		class ObjectInterface
		{
		public:
			class ArrVisitor
			{
			public:
				virtual ~ArrVisitor() = default;  // 00

				// add
				virtual void Visit(std::uint32_t a_idx, const Value& a_val) = 0;  // 00
			};
			static_assert(sizeof(ArrVisitor) == 0x8);

			class ObjVisitor
			{
			public:
				virtual ~ObjVisitor() = default;  // 00

				// add
				virtual bool IncludeAS3PublicMembers() const { return false; }   // 01
				virtual void Visit(const char* a_name, const Value& a_val) = 0;  // 02
			};
			static_assert(sizeof(ObjVisitor) == 0x8);

			virtual ~ObjectInterface() = default;  // 00

			void ObjectAddRef(Value* a_val, void* a_obj)
			{
				using func_t = decltype(&ObjectInterface::ObjectAddRef);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::ObjectAddRef };
				return func(this, a_val, a_obj);
			}

			void ObjectRelease(Value* a_val, void* a_obj)
			{
				using func_t = decltype(&ObjectInterface::ObjectRelease);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::ObjectRelease };
				return func(this, a_val, a_obj);
			}

			bool HasMember(void* a_data, const char* a_name, bool a_isdobj) const
			{
				using func_t = decltype(&ObjectInterface::HasMember);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::HasMember };
				return func(this, a_data, a_name, a_isdobj);
			}

			bool GetMember(void* a_data, const char* a_name, Value* a_val, bool a_isdobj) const
			{
				using func_t = decltype(&ObjectInterface::GetMember);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::GetMember };
				return func(this, a_data, a_name, a_val, a_isdobj);
			}

			bool SetMember(void* a_data, const char* a_name, const Value& a_value, bool a_isdobj)
			{
				using func_t = decltype(&ObjectInterface::SetMember);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::SetMember };
				return func(this, a_data, a_name, a_value, a_isdobj);
			}

			bool Invoke(void* a_data, Value* a_result, const char* a_name, const Value* a_args, std::size_t a_numArgs, bool a_isdobj)
			{
				using func_t = decltype(&ObjectInterface::Invoke);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::Invoke };
				return func(this, a_data, a_result, a_name, a_args, a_numArgs, a_isdobj);
			}

			void VisitMembers(void* a_data, ObjVisitor* a_visitor, bool a_isdobj)
			{
				using func_t = decltype(&ObjectInterface::VisitMembers);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::VisitMembers };
				return func(this, a_data, a_visitor, a_isdobj);
			}

			std::uint32_t GetArraySize(void* a_data)
			{
				using func_t = decltype(&ObjectInterface::GetArraySize);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::GetArraySize };
				return func(this, a_data);
			}

			bool SetArraySize(void* a_data, std::uint32_t a_size)
			{
				using func_t = decltype(&ObjectInterface::SetArraySize);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::SetArraySize };
				return func(this, a_data, a_size);
			}

			bool GetElement(void* a_data, std::uint32_t a_index, Value* a_value)
			{
				using func_t = decltype(&ObjectInterface::GetElement);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::GetElement };
				return func(this, a_data, a_index, a_value);
			}

			bool SetElement(void* a_data, std::uint32_t a_index, const Value& a_value)
			{
				using func_t = decltype(&ObjectInterface::SetElement);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::SetElement };
				return func(this, a_data, a_index, a_value);
			}

			void VisitElements(void* a_data, ArrVisitor* a_visitor, std::uint32_t a_index, std::int32_t a_count)
			{
				using func_t = decltype(&ObjectInterface::VisitElements);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::VisitElements };
				return func(this, a_data, a_visitor, a_index, a_count);
			}

			bool PushBack(void* a_data, const Value& a_value)
			{
				using func_t = decltype(&ObjectInterface::PushBack);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::PushBack };
				return func(this, a_data, a_value);
			}

			bool PopBack(void* a_data, Value* a_value)
			{
				using func_t = decltype(&ObjectInterface::PopBack);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::PopBack };
				return func(this, a_data, a_value);
			}

			bool RemoveElements(void* a_data, std::uint32_t a_index, std::int32_t a_count)
			{
				using func_t = decltype(&ObjectInterface::RemoveElements);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::RemoveElements };
				return func(this, a_data, a_index, a_count);
			}

			bool GetParent(void* a_data, Value* a_value)
			{
				using func_t = decltype(&ObjectInterface::GetParent);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::GetParent };
				return func(this, a_data, a_value);
			}

			bool GetText(void* a_data, Value* a_value, bool a_html)
			{
				using func_t = decltype(&ObjectInterface::GetText);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::GetText };
				return func(this, a_data, a_value, a_html);
			}

			bool SetText(void* a_data, const char* a_text, bool a_html)
			{
				using func_t = decltype(&ObjectInterface::SetText);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::SetText };
				return func(this, a_data, a_text, a_html);
			}

			bool SetTextW(void* a_data, const wchar_t* a_text, bool a_html)
			{
				using func_t = decltype(&ObjectInterface::SetTextW);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::SetTextW };
				return func(this, a_data, a_text, a_html);
			}

			bool CreateEmptyMovieClip(void* a_data, Value* a_value, const char* a_name, std::int32_t a_depth)
			{
				using func_t = decltype(&ObjectInterface::CreateEmptyMovieClip);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::CreateEmptyMovieClip };
				return func(this, a_data, a_value, a_name, a_depth);
			}

			bool GotoAndPlayL(void* a_data, const char* a_frame, bool a_stop)
			{
				using func_t = decltype(&ObjectInterface::GotoAndPlayL);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::GotoAndPlayL };
				return func(this, a_data, a_frame, a_stop);
			}

			bool GotoAndPlay(void* a_data, std::uint32_t a_frame, bool a_stop)
			{
				using func_t = decltype(&ObjectInterface::GotoAndPlay);
				REL::Relocation<func_t> func{ ID::Scaleform::ObjectInterface::GotoAndPlay };
				return func(this, a_data, a_frame, a_stop);
			}

			// members
			MovieImpl* movieRoot;  // 08
			Value* lastValue;
		};
		static_assert(sizeof(ObjectInterface) == 0x18);

		using ArrayVisitor = ObjectInterface::ArrVisitor;
		using ObjectVisitor = ObjectInterface::ObjVisitor;

		Value() noexcept = default;

		Value(const Value& a_rhs) :
			_type(a_rhs._type),
			_value(a_rhs._value),
			_dataAux(a_rhs._dataAux)
		{
			if (a_rhs.IsManagedValue()) {
				AcquireManagedValue(a_rhs);
			}
		}

		Value(Value&& a_rhs) noexcept
		{
			_type = a_rhs._type;
			_value = a_rhs._value;
			_dataAux = a_rhs._dataAux;

			if (a_rhs.IsManagedValue()) {
				AcquireManagedValue(a_rhs);
				a_rhs.ReleaseManagedValue();
			}

			a_rhs._type = ValueType::kUndefined;
			a_rhs._value = 0;
			a_rhs._dataAux = 0;
		}

		Value(const std::nullptr_t) noexcept :
			_type(ValueType::kNull)
		{}

		Value(const std::int32_t a_rhs) noexcept :
			_type(ValueType::kInt),
			_value(a_rhs)
		{}

		Value(const std::uint32_t a_rhs) noexcept :
			_type(ValueType::kUInt),
			_value(a_rhs)
		{}

		Value(const double a_rhs) noexcept :
			_type(ValueType::kNumber),
			_value(a_rhs)
		{}

		Value(const bool a_rhs) noexcept :
			_type(ValueType::kBoolean),
			_value(a_rhs)
		{}

		Value(const char* a_rhs) noexcept :
			_type(ValueType::kString),
			_value(a_rhs)
		{}

		Value(const wchar_t* a_rhs) noexcept :
			_type(ValueType::kStringW),
			_value(a_rhs)
		{}

		~Value()
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kUndefined;
		}

		Value& operator=(const Value& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				if (IsManagedValue()) {
					ReleaseManagedValue();
				}

				_type = a_rhs._type;
				_value = a_rhs._value;
				_dataAux = a_rhs._dataAux;

				if (a_rhs.IsManagedValue()) {
					AcquireManagedValue(a_rhs);
				}
			}
			return *this;
		}

		Value& operator=(Value&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				if (IsManagedValue()) {
					ReleaseManagedValue();
				}

				_type = a_rhs._type;
				_value = a_rhs._value;
				_dataAux = a_rhs._dataAux;

				if (a_rhs.IsManagedValue()) {
					AcquireManagedValue(a_rhs);
					a_rhs.ReleaseManagedValue();
				}

				a_rhs._type = ValueType::kUndefined;
				a_rhs._value = 0;
				a_rhs._dataAux = 0;
			}
			return *this;
		}

		Value& operator=(const std::nullptr_t) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kNull;
			return *this;
		}

		Value& operator=(const std::int32_t a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kInt;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(const std::uint32_t a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kUInt;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(const double a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kNumber;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(const bool a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kBoolean;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(const char* a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kString;
			_value = a_rhs;
			return *this;
		}

		Value& operator=(const wchar_t* a_rhs) noexcept
		{
			if (IsManagedValue()) {
				ReleaseManagedValue();
			}

			_type = ValueType::kStringW;
			_value = a_rhs;
			return *this;
		}

		[[nodiscard]] ValueType GetType() const noexcept { return *(_type & ValueType::kTypeMask); }

		[[nodiscard]] bool IsArray() const noexcept { return GetType() == ValueType::kArray; }
		[[nodiscard]] bool IsBoolean() const noexcept { return GetType() == ValueType::kBoolean; }
		[[nodiscard]] bool IsDisplayObject() const noexcept { return GetType() == ValueType::kDisplayObject; }
		[[nodiscard]] bool IsInt() const noexcept { return GetType() == ValueType::kInt; }
		[[nodiscard]] bool IsNumber() const noexcept { return GetType() == ValueType::kNumber; }
		[[nodiscard]] bool IsString() const noexcept { return GetType() == ValueType::kString; }
		[[nodiscard]] bool IsStringW() const noexcept { return GetType() == ValueType::kStringW; }
		[[nodiscard]] bool IsUndefined() const noexcept { return GetType() == ValueType::kUndefined; }
		[[nodiscard]] bool IsUInt() const noexcept { return GetType() == ValueType::kUInt; }

		[[nodiscard]] bool IsObject() const noexcept
		{
			switch (GetType()) {
			case ValueType::kObject:
			case ValueType::kArray:
			case ValueType::kDisplayObject:
				return true;
			}

			return false;
		}

		[[nodiscard]] bool GetBoolean() const
		{
			assert(IsBoolean());
			return _value.boolean;
		}

		[[nodiscard]] std::int32_t GetInt() const
		{
			assert(IsInt());
			return _value.int32;
		}

		[[nodiscard]] double GetNumber() const
		{
			assert(IsNumber());
			return _value.number;
		}

		[[nodiscard]] const char* GetString() const
		{
			assert(IsString());
			return IsManagedValue() ? *_value.mstring : _value.string;
		}

		[[nodiscard]] const wchar_t* GetStringW() const
		{
			assert(IsStringW());
			return _value.wstring;
		}

		[[nodiscard]] std::uint32_t GetUInt() const
		{
			assert(IsUInt());
			return _value.uint32;
		}

		bool CreateEmptyMovieClip(Value* a_value, const char* a_name, std::int32_t a_depth = -1)
		{
			return _objectInterface->CreateEmptyMovieClip(_value.data, a_value, a_name, a_depth);
		}

		bool GetMember(stl::zstring a_name, Value* a_value) const
		{
			assert(IsObject());
			return _objectInterface->GetMember(_value.data, a_name.data(), a_value, IsDisplayObject());
		}

		[[nodiscard]] Movie* GetMovie() const
		{
			assert(_objectInterface && _objectInterface->movieRoot);
			return reinterpret_cast<Movie*>(_objectInterface->movieRoot);
		}

		bool GetParent(Value* a_value) const
		{
			return _objectInterface->GetParent(_value.data, a_value);
		}

		bool GetText(Value* a_value) const
		{
			assert(IsString());
			return _objectInterface->GetText(_value.data, a_value, false);
		}

		bool GetTextHTML(Value* a_value) const
		{
			assert(IsString());
			return _objectInterface->GetText(_value.data, a_value, true);
		}

		bool GotoAndPlay(stl::zstring a_frame)
		{
			assert(IsDisplayObject());
			return _objectInterface->GotoAndPlayL(_value.data, a_frame.data(), false);
		}

		bool GotoAndPlay(std::uint32_t a_frame)
		{
			assert(IsDisplayObject());
			return _objectInterface->GotoAndPlay(_value.data, a_frame, false);
		}

		bool GotoAndStop(stl::zstring a_frame)
		{
			assert(IsDisplayObject());
			return _objectInterface->GotoAndPlayL(_value.data, a_frame.data(), true);
		}

		bool GotoAndStop(std::uint32_t a_frame)
		{
			assert(IsDisplayObject());
			return _objectInterface->GotoAndPlay(_value.data, a_frame, true);
		}

		[[nodiscard]] bool HasMember(stl::zstring a_name) const
		{
			assert(IsObject());
			return _objectInterface->HasMember(_value.data, a_name.data(), IsDisplayObject());
		}

		bool Invoke(const char* a_name, Value* a_result, const Value* a_args, std::size_t a_numArgs)
		{
			assert(IsObject());
			return _objectInterface->Invoke(_value.data, a_result, a_name, a_args, a_numArgs, IsDisplayObject());
		}

		bool Invoke(const char* a_name, Value* a_result = nullptr)
		{
			return Invoke(a_name, a_result, nullptr, 0);
		}

		bool PopBack(Value* a_value = nullptr)
		{
			assert(IsArray());
			return _objectInterface->PopBack(_value.data, a_value);
		}

		bool PushBack(const Value& a_value)
		{
			assert(IsArray());
			return _objectInterface->PushBack(_value.data, a_value);
		}

		bool RemoveElements(std::uint32_t a_index, std::int32_t a_count = -1)
		{
			assert(IsArray());
			return _objectInterface->RemoveElements(_value.data, a_index, a_count);
		}

		bool RemoveElement(std::uint32_t a_index)
		{
			assert(IsArray());
			return RemoveElements(a_index, 1);
		}

		bool SetArraySize(std::uint32_t a_size)
		{
			assert(IsArray());
			return _objectInterface->SetArraySize(_value.data, a_size);
		}

		bool SetMember(stl::zstring a_name, const Value& a_value)
		{
			assert(IsObject());
			return _objectInterface->SetMember(_value.data, a_name.data(), a_value, IsDisplayObject());
		}

		bool SetText(stl::zstring a_text)
		{
			assert(IsDisplayObject());
			return _objectInterface->SetText(_value.data, a_text.data(), false);
		}

		bool SetTextHTML(stl::zstring a_text)
		{
			assert(IsDisplayObject());
			return _objectInterface->SetText(_value.data, a_text.data(), true);
		}

		void VisitElements(ArrayVisitor* a_visitor, std::uint32_t a_index, std::int32_t a_count = -1)
		{
			assert(IsArray());
			_objectInterface->VisitElements(_value.data, a_visitor, a_index, a_count);
		}

		void VisitElements(ArrayVisitor* a_visitor)
		{
			assert(IsArray());
			VisitElements(a_visitor, 0);
		}

		void VisitMembers(ObjectVisitor* a_visitor)
		{
			assert(IsObject());
			_objectInterface->VisitMembers(_value.data, a_visitor, IsDisplayObject());
		}

	private:
		void AcquireManagedValue(const Value& a_rhs)
		{
			assert(a_rhs._value.data && a_rhs._objectInterface);
			_objectInterface = a_rhs._objectInterface;
			_objectInterface->ObjectAddRef(this, _value.data);
		}

		[[nodiscard]] bool IsManagedValue() const noexcept
		{
			const auto managed = _type.all(ValueType::kManagedBit);
			assert(managed ? _objectInterface != nullptr : true);
			return managed;
		}

		void ReleaseManagedValue()
		{
			assert(_value.data && _objectInterface);
			_objectInterface->ObjectRelease(this, _value.data);
			_objectInterface = nullptr;
		}

		// members
		Value*                                    _prev{};                         // 00
		Value*                                    _next{};                         // 08
		ObjectInterface*                          _objectInterface{};              // 10
		stl::enumeration<ValueType, std::int32_t> _type{ ValueType::kUndefined };  // 18
		ValueUnion                                _value{};                        // 20
		std::size_t                               _dataAux{};                      // 28
	};
	static_assert(sizeof(Value) == 0x30);
}
