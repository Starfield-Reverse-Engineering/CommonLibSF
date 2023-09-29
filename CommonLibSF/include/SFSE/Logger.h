#pragma once

#define SFSE_MAKE_SOURCE_LOGGER(a_func, a_type)                                                                                                                                       \
                                                                                                                                                                                      \
	template <class... Args>                                                                                                                                                          \
	struct [[maybe_unused]] a_func                                                                                                                                                    \
	{                                                                                                                                                                                 \
		a_func() = delete;                                                                                                                                                            \
                                                                                                                                                                                      \
		explicit a_func(spdlog::format_string_t<Args...> a_fmt, Args&&... a_args, std::source_location a_loc = std::source_location::current())                                       \
		{                                                                                                                                                                             \
			spdlog::log(spdlog::source_loc{ a_loc.file_name(), static_cast<int>(a_loc.line()), a_loc.function_name() }, spdlog::level::a_type, a_fmt, std::forward<Args>(a_args)...); \
		}                                                                                                                                                                             \
	};                                                                                                                                                                                \
                                                                                                                                                                                      \
	template <class... Args>                                                                                                                                                          \
	a_func(spdlog::format_string_t<Args...>, Args&&...) -> a_func<Args...>;

namespace SFSE::log
{
	SFSE_MAKE_SOURCE_LOGGER(trace, trace);
	SFSE_MAKE_SOURCE_LOGGER(debug, debug);
	SFSE_MAKE_SOURCE_LOGGER(info, info);
	SFSE_MAKE_SOURCE_LOGGER(warn, warn);
	SFSE_MAKE_SOURCE_LOGGER(error, err);
	SFSE_MAKE_SOURCE_LOGGER(critical, critical);

	[[nodiscard]] std::optional<std::filesystem::path> log_directory();
	void                                               init();
}

#undef SFSE_MAKE_SOURCE_LOGGER
