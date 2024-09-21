#include "SFSE/Logger.h"
#include "SFSE/API.h"

#include "REX/W32/OLE32.h"
#include "REX/W32/SHELL32.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>

namespace SFSE::log
{
	std::optional<std::filesystem::path> log_directory()
	{
		wchar_t*                                                             buffer{};
		const auto                                                           result = REX::W32::SHGetKnownFolderPath(REX::W32::FOLDERID_Documents, REX::W32::KF_FLAG_DEFAULT, nullptr, std::addressof(buffer));
		const std::unique_ptr<wchar_t[], decltype(&REX::W32::CoTaskMemFree)> knownPath(buffer, REX::W32::CoTaskMemFree);
		if (!knownPath || result != 0) {
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

		*path /= std::format("{}.log", SFSE::GetPluginName());

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
}
