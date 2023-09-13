#include "SFSE/Logger.h"
#include "SFSE/API.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

#include <ShlObj.h>

namespace SFSE
{
	namespace log
	{
		std::optional<std::filesystem::path> log_directory()
		{
			wchar_t*                                               buffer{ nullptr };
			const auto                                             result = ::SHGetKnownFolderPath(::FOLDERID_Documents, ::KNOWN_FOLDER_FLAG::KF_FLAG_DEFAULT, nullptr, std::addressof(buffer));
			std::unique_ptr<wchar_t[], decltype(&::CoTaskMemFree)> knownPath(buffer, ::CoTaskMemFree);
			if (!knownPath || result != S_OK) {
				error("failed to get known folder path"sv);
				return std::nullopt;
			}

			std::filesystem::path path = knownPath.get();
			path /= "My Games\\Starfield\\SFSE\\Logs";
			return path;
		}

		void init()
		{
			auto path = log_directory();
			if (!path)
				return;
			
			const auto data = PluginVersionData::GetSingleton();
			*path /= std::format("{}.log", data->GetPluginName());

			std::vector<spdlog::sink_ptr> sinks{
				std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true), 
				std::make_shared<spdlog::sinks::msvc_sink_mt>()
			};

			auto logger = std::make_shared<spdlog::logger>("global", sinks.begin(), sinks.end());
#ifndef NDEBUG
			logger->set_level(spdlog::level::debug);
			logger->flush_on(spdlog::level::debug);
#else
			logger->set_level(spdlog::level::info);
			logger->flush_on(spdlog::level::info);
#endif
			spdlog::set_default_logger(std::move(logger));
			spdlog::set_pattern("[%T.%e] [%=5t] [%L] %v");
		}
	}  // namespace log
}  // namespace SFSE
