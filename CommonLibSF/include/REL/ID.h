#pragma once

#include "REL/Module.h"

namespace REL
{
	namespace database
	{
		enum : std::uint32_t
		{
			kDatabaseVersion = 2
		};

		struct mapping_t
		{
			std::uint64_t id;
			std::uint64_t offset;
		};

		class memory_map
		{
		public:
			memory_map() noexcept = default;

			memory_map(const memory_map&) = delete;

			memory_map(memory_map&& a_rhs) noexcept :
				_mapping(a_rhs._mapping),
				_view(a_rhs._view)
			{
				a_rhs._mapping = nullptr;
				a_rhs._view = nullptr;
			}

			~memory_map() { close(); }

			memory_map& operator=(const memory_map&) = delete;

			memory_map& operator=(memory_map&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_mapping = a_rhs._mapping;
					a_rhs._mapping = nullptr;

					_view = a_rhs._view;
					a_rhs._view = nullptr;
				}
				return *this;
			}

			[[nodiscard]] void* data() noexcept { return _view; }

			bool open(stl::zwstring a_name, std::size_t a_size);

			bool create(stl::zwstring a_name, std::size_t a_size);

			void close();

		private:
			void* _mapping{ nullptr };
			void* _view{ nullptr };
		};

		class Offset2ID
		{
		public:
			using value_type = mapping_t;
			using container_type = std::vector<value_type>;
			using size_type = typename container_type::size_type;
			using const_iterator = typename container_type::const_iterator;
			using const_reverse_iterator = typename container_type::const_reverse_iterator;

			template <class ExecutionPolicy>
			explicit Offset2ID(ExecutionPolicy&& a_policy)  //
				requires(std::is_execution_policy_v<std::decay_t<ExecutionPolicy>>);

			Offset2ID() :
				Offset2ID(std::execution::sequenced_policy{})
			{}

			[[nodiscard]] std::uint64_t operator()(std::size_t a_offset) const;

			[[nodiscard]] const_iterator begin() const noexcept { return _offset2id.begin(); }

			[[nodiscard]] const_iterator cbegin() const noexcept { return _offset2id.cbegin(); }

			[[nodiscard]] const_iterator end() const noexcept { return _offset2id.end(); }

			[[nodiscard]] const_iterator cend() const noexcept { return _offset2id.cend(); }

			[[nodiscard]] const_reverse_iterator rbegin() const noexcept { return _offset2id.rbegin(); }

			[[nodiscard]] const_reverse_iterator crbegin() const noexcept { return _offset2id.crbegin(); }

			[[nodiscard]] const_reverse_iterator rend() const noexcept { return _offset2id.rend(); }

			[[nodiscard]] const_reverse_iterator crend() const noexcept { return _offset2id.crend(); }

			[[nodiscard]] size_type size() const noexcept { return _offset2id.size(); }

		private:
			container_type _offset2id;
		};

		class istream_t
		{
		public:
			using stream_type = std::ifstream;
			using pointer = stream_type*;
			using const_pointer = const stream_type*;
			using reference = stream_type&;
			using const_reference = const stream_type&;

			istream_t(stl::zwstring a_filename, std::ios_base::openmode a_mode) :
				_stream(a_filename.data(), a_mode)
			{
				stl_assert(_stream.is_open(),
					"failed to open address library file");

				_stream.exceptions(std::ios::badbit | std::ios::failbit | std::ios::eofbit);
			}

			void ignore(std::streamsize a_count)
			{
				_stream.ignore(a_count);
			}

			template <class T>
			void readin(T& a_val)
			{
				_stream.read(std::bit_cast<char*>(std::addressof(a_val)), sizeof(T));
			}

			template <class T>
				requires(std::is_arithmetic_v<T>)
			T readout()
			{
				T val{};
				readin(val);
				return val;
			}

		private:
			stream_type _stream;
		};

		class header_t
		{
		public:
			void read(istream_t& a_in);

			[[nodiscard]] std::size_t address_count() const noexcept
			{
				return static_cast<std::size_t>(_addressCount);
			}

			[[nodiscard]] std::uint64_t pointer_size() const noexcept
			{
				return static_cast<std::uint64_t>(_pointerSize);
			}

			[[nodiscard]] std::string_view name() const noexcept
			{
				return _name;
			}

			[[nodiscard]] Version version() const noexcept
			{
				return _version;
			}

		private:
			char          _name[20]{};
			Version       _version;
			std::uint32_t _pointerSize{ 0 };
			std::uint32_t _addressCount{ 0 };
		};
	}  // namespace database

	class IDDatabase
	{
	public:
		enum class Platform
		{
			kUnknown = -1,
			kSteam,
			kMsStore,
		};

		[[nodiscard]] static IDDatabase& get()
		{
			if (_initialized.load(std::memory_order_relaxed)) {
				return _instance;
			}
			[[maybe_unused]] std::unique_lock lock(_initLock);
			_instance.load();
			_initialized.store(true, std::memory_order_relaxed);
			return _instance;
		}

		[[nodiscard]] std::size_t id2offset(std::uint64_t a_id) const;

	private:
		friend class Module;

		friend class database::Offset2ID;

		IDDatabase() = default;

		IDDatabase(const IDDatabase&) = delete;

		IDDatabase(IDDatabase&&) = delete;

		~IDDatabase() = default;

		IDDatabase& operator=(const IDDatabase&) = delete;

		IDDatabase& operator=(IDDatabase&&) = delete;

		std::wstring addresslib_filename();

		void load();

		bool load_file(stl::zwstring a_filename, Version a_version, bool a_failOnError);

		bool unpack_file(database::istream_t& a_in, database::header_t a_header, bool a_failOnError);

		void clear()
		{
			_mmap.close();
			_id2offset = {};
		}

		static IDDatabase              _instance;
		inline static std::atomic_bool _initialized{ false };
		inline static std::mutex       _initLock;
		database::memory_map           _mmap;
		std::span<database::mapping_t> _id2offset;
		Platform                       _platform{ Platform::kUnknown };
	};

	class ID
	{
	public:
		constexpr ID() noexcept = default;

		explicit constexpr ID(std::uint64_t a_id) noexcept :
			_id(a_id)
		{}

		constexpr ID& operator=(std::uint64_t a_id) noexcept
		{
			_id = a_id;
			return *this;
		}

		[[nodiscard]] std::uintptr_t address() const
		{
			return base() + offset();
		}

		[[nodiscard]] constexpr std::uint64_t id() const noexcept
		{
			return _id;
		}

		[[nodiscard]] std::size_t offset() const
		{
			return IDDatabase::get().id2offset(_id);
		}

	private:
		[[nodiscard]] static std::uintptr_t base()
		{
			return Module::get().base();
		}

		std::uint64_t _id{ 0 };
	};

	template <class ExecutionPolicy>
	database::Offset2ID::Offset2ID(ExecutionPolicy&& a_policy)  //
		requires(std::is_execution_policy_v<std::decay_t<ExecutionPolicy>>)
	{
		const std::span<const mapping_t> id2offset = IDDatabase::get()._id2offset;
		_offset2id.reserve(id2offset.size());
		_offset2id.insert(_offset2id.begin(), id2offset.begin(), id2offset.end());
		std::sort(
			a_policy,
			_offset2id.begin(),
			_offset2id.end(),
			[](auto&& a_lhs, auto&& a_rhs) {
				return a_lhs.offset < a_rhs.offset;
			});
	}
}  // namespace REL
