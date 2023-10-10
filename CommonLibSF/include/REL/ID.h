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
			constexpr memory_map() noexcept = default;

			constexpr memory_map(const memory_map&) = delete;

			constexpr memory_map(memory_map&& a_rhs) noexcept :
				_mapping(a_rhs._mapping),
				_view(a_rhs._view)
			{
				a_rhs._mapping = nullptr;
				a_rhs._view = nullptr;
			}

			~memory_map() { close(); }

			constexpr memory_map& operator=(const memory_map&) = delete;

			constexpr memory_map& operator=(memory_map&& a_rhs) noexcept
			{
				if (this != std::addressof(a_rhs)) {
					_mapping = a_rhs._mapping;
					a_rhs._mapping = nullptr;

					_view = a_rhs._view;
					a_rhs._view = nullptr;
				}
				return *this;
			}

			[[nodiscard]] constexpr void* data() const noexcept { return _view; }

			bool open(stl::zwstring a_name, std::size_t a_size);

			bool create(stl::zwstring a_name, std::size_t a_size);

			constexpr void close();

		private:
			void* _mapping{};
			void* _view{};
		};

		class Offset2ID
		{
		public:
			using value_type = mapping_t;
			using container_type = std::vector<value_type>;
			using size_type = container_type::size_type;
			using const_iterator = container_type::const_iterator;
			using const_reverse_iterator = container_type::const_reverse_iterator;

			template <class ExecutionPolicy>
			explicit Offset2ID(ExecutionPolicy&& a_policy)
				requires(std::is_execution_policy_v<std::decay_t<ExecutionPolicy>>);

			Offset2ID() :
				Offset2ID(std::execution::sequenced_policy{})
			{}

			[[nodiscard]] std::uint64_t operator()(std::size_t a_offset) const;

			[[nodiscard]] constexpr const_iterator begin() const noexcept { return _offset2id.begin(); }

			[[nodiscard]] constexpr const_iterator cbegin() const noexcept { return _offset2id.cbegin(); }

			[[nodiscard]] constexpr const_iterator end() const noexcept { return _offset2id.end(); }

			[[nodiscard]] constexpr const_iterator cend() const noexcept { return _offset2id.cend(); }

			[[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept { return _offset2id.rbegin(); }

			[[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept { return _offset2id.crbegin(); }

			[[nodiscard]] constexpr const_reverse_iterator rend() const noexcept { return _offset2id.rend(); }

			[[nodiscard]] constexpr const_reverse_iterator crend() const noexcept { return _offset2id.crend(); }

			[[nodiscard]] constexpr size_type size() const noexcept { return _offset2id.size(); }

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

			istream_t(const stl::zwstring a_filename, const std::ios_base::openmode a_mode) :
				_stream(a_filename.data(), a_mode)
			{
				stl_assert(_stream.is_open(),
					"failed to open address library file");

				_stream.exceptions(std::ios::badbit | std::ios::failbit | std::ios::eofbit);
			}

			void ignore(const std::streamsize a_count)
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

			[[nodiscard]] constexpr std::size_t address_count() const noexcept
			{
				return _addressCount;
			}

			[[nodiscard]] constexpr std::uint64_t pointer_size() const noexcept
			{
				return _pointerSize;
			}

			[[nodiscard]] constexpr std::string_view name() const noexcept
			{
				return _name;
			}

			[[nodiscard]] constexpr Version version() const noexcept
			{
				return _version;
			}

		private:
			char          _name[20]{};
			Version       _version;
			std::uint32_t _pointerSize{};
			std::uint32_t _addressCount{};
		};
	}

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

		constexpr IDDatabase() = default;

		~IDDatabase() = default;

		constexpr IDDatabase(const IDDatabase&) = delete;

		constexpr IDDatabase(IDDatabase&&) = delete;

		constexpr IDDatabase& operator=(const IDDatabase&) = delete;

		constexpr IDDatabase& operator=(IDDatabase&&) = delete;

		std::wstring addresslib_filename();

		void load();

		bool load_file(stl::zwstring a_filename, Version a_version, bool a_failOnError);

		bool unpack_file(database::istream_t& a_in, const database::header_t& a_header, bool a_failOnError);

		void clear()
		{
			_mmap.close();
			_id2offset = {};
		}

		static IDDatabase              _instance;
		inline static std::atomic_bool _initialized{};
		inline static std::mutex       _initLock;
		inline static bool             _is_steam{};
		database::memory_map           _mmap;
		std::span<database::mapping_t> _id2offset;
		Platform                       _platform{ Platform::kUnknown };
	};

	class ID
	{
	public:
		constexpr ID() noexcept = default;

		explicit constexpr ID(const std::uint64_t a_id) noexcept :
			_id(a_id)
		{}

		constexpr ID& operator=(const std::uint64_t a_id) noexcept
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
		[[nodiscard]] static constexpr std::uintptr_t base()
		{
			return Module::get().base();
		}

		std::uint64_t _id{};
	};

	template <class ExecutionPolicy>
	database::Offset2ID::Offset2ID(ExecutionPolicy&& a_policy)
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
}
