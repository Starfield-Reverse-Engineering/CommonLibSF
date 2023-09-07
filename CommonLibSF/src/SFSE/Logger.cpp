#include "SFSE/Logger.h"
#include "SFSE/API.h"

#include <ShlObj.h>

namespace SFSE
{
	namespace log
	{
		std::optional<std::filesystem::path> log_directory()
		{
			wchar_t*   buffer{ nullptr };
			const auto result = ::SHGetKnownFolderPath(::FOLDERID_Documents, ::KNOWN_FOLDER_FLAG::KF_FLAG_DEFAULT, nullptr, std::addressof(buffer));
			std::unique_ptr<wchar_t[], decltype(&::CoTaskMemFree)> knownPath(buffer, ::CoTaskMemFree);
			if (!knownPath || result != S_OK)
			{
				error("failed to get known folder path"sv);
				return std::nullopt;
			}

			std::filesystem::path path = knownPath.get();
			path /= "My Games\\Starfield\\SFSE\\Logs";
			return path;
		}
	} // namespace log
} // namespace SFSE
