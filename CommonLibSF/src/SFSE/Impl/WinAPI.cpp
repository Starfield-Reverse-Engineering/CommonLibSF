#include "SFSE/Impl/WinAPI.h"

#include <Windows.h>

#undef FindFirstFile
#undef FindNextFile
#undef GetEnvironmentVariable
#undef GetFileVersionInfo
#undef GetFileVersionInfoSize
#undef GetKeyNameText
#undef GetModuleFileName
#undef GetModuleHandle
#undef GetPrivateProfileString
#undef LoadLibrary
#undef MessageBox
#undef OutputDebugString
#undef RegQueryValueEx
#undef VerQueryValue

extern "C" IMAGE_DOS_HEADER __ImageBase;

namespace SFSE::WinAPI
{
	bool FreeLibrary(HMODULE a_module) noexcept
	{
		return ::FreeLibrary(reinterpret_cast<::HMODULE>(a_module));
	}

	[[nodiscard]] bool FindClose(void* a_findFile) noexcept
	{
		return static_cast<bool>(::FindClose(static_cast<::HMODULE>(a_findFile)));
	}

	[[nodiscard]] void* FindFirstFile(const char* a_fileName, WIN32_FIND_DATAA* a_findFileData) noexcept
	{
		return static_cast<void*>(::FindFirstFileA(static_cast<::LPCSTR>(a_fileName), reinterpret_cast<::LPWIN32_FIND_DATAA>(a_findFileData)));
	}

	[[nodiscard]] void* FindFirstFile(const wchar_t* a_fileName, WIN32_FIND_DATAW* a_findFileData) noexcept
	{
		return static_cast<void*>(::FindFirstFileW(static_cast<::LPCWSTR>(a_fileName), reinterpret_cast<::LPWIN32_FIND_DATAW>(a_findFileData)));
	}

	[[nodiscard]] bool FindNextFile(void* a_findFile, WIN32_FIND_DATAA* a_findFileData) noexcept
	{
		return static_cast<bool>(::FindNextFileA(static_cast<::HANDLE>(a_findFile), reinterpret_cast<::LPWIN32_FIND_DATAA>(a_findFileData)));
	}

	[[nodiscard]] bool FindNextFile(void* a_findFile, WIN32_FIND_DATAW* a_findFileData) noexcept
	{
		return static_cast<bool>(::FindNextFileW(static_cast<::HANDLE>(a_findFile), reinterpret_cast<::LPWIN32_FIND_DATAW>(a_findFileData)));
	}

	void* GetCurrentModule() noexcept
	{
		return static_cast<void*>(std::addressof(__ImageBase));
	}

	void* GetCurrentProcess() noexcept
	{
		return static_cast<void*>(::GetCurrentProcess());
	}

	std::uint32_t GetCurrentThreadID() noexcept
	{
		return static_cast<std::uint32_t>(::GetCurrentThreadId());
	}

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(const char* a_name, char* a_buffer, std::uint32_t a_size) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetEnvironmentVariableA(static_cast<::LPCSTR>(a_name), static_cast<::LPSTR>(a_buffer), static_cast<::DWORD>(a_size)));
	}

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(const wchar_t* a_name, wchar_t* a_buffer, std::uint32_t a_size) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetEnvironmentVariableW(static_cast<::LPCWSTR>(a_name), static_cast<::LPWSTR>(a_buffer), static_cast<::DWORD>(a_size)));
	}

	bool GetFileVersionInfo(const char* a_filename, std::uint32_t a_handle, std::uint32_t a_len, void* a_data) noexcept
	{
		return static_cast<bool>(::GetFileVersionInfoA(static_cast<::LPCSTR>(a_filename), static_cast<::DWORD>(a_handle), static_cast<::DWORD>(a_len),
		                                               static_cast<::LPVOID>(a_data)));
	}

	bool GetFileVersionInfo(const wchar_t* a_filename, std::uint32_t a_handle, std::uint32_t a_len, void* a_data) noexcept
	{
		return static_cast<bool>(::GetFileVersionInfoW(static_cast<::LPCWSTR>(a_filename), static_cast<::DWORD>(a_handle),
		                                               static_cast<::DWORD>(a_len), static_cast<::LPVOID>(a_data)));
	}

	std::uint32_t GetFileVersionInfoSize(const char* a_filename, std::uint32_t* a_handle) noexcept
	{
		return static_cast<std::uint32_t>(::GetFileVersionInfoSizeA(static_cast<::LPCSTR>(a_filename), reinterpret_cast<::LPDWORD>(a_handle)));
	}

	std::uint32_t GetFileVersionInfoSize(const wchar_t* a_filename, std::uint32_t* a_handle) noexcept
	{
		return static_cast<std::uint32_t>(::GetFileVersionInfoSizeW(static_cast<::LPCWSTR>(a_filename), reinterpret_cast<::LPDWORD>(a_handle)));
	}

	int GetKeyNameText(std::int32_t a_lParam, wchar_t* a_buffer, int a_size) noexcept
	{
		return ::GetKeyNameTextW(static_cast<::LONG>(a_lParam), static_cast<::LPWSTR>(a_buffer), a_size);
	}

	int GetKeyNameText(std::int32_t a_lParam, char* a_buffer, int a_size) noexcept
	{
		return ::GetKeyNameTextA(static_cast<::LONG>(a_lParam), static_cast<::LPSTR>(a_buffer), a_size);
	}

	std::int16_t GetKeyState(int nVirtKey) noexcept
	{
		return ::GetKeyState(nVirtKey);
	}

	std::size_t GetMaxPath() noexcept
	{
		return static_cast<std::size_t>(MAX_PATH);
	}

	std::uint32_t GetModuleFileName(void* a_module, char* a_filename, std::uint32_t a_size) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetModuleFileNameA(static_cast<::HMODULE>(a_module), static_cast<::LPSTR>(a_filename), static_cast<::DWORD>(a_size)));
	}

	std::uint32_t GetModuleFileName(void* a_module, wchar_t* a_filename, std::uint32_t a_size) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetModuleFileNameW(static_cast<::HMODULE>(a_module), static_cast<::LPWSTR>(a_filename), static_cast<::DWORD>(a_size)));
	}

	HMODULE GetModuleHandle(const char* a_moduleName) noexcept
	{
		return reinterpret_cast<HMODULE>(::GetModuleHandleA(static_cast<::LPCSTR>(a_moduleName)));
	}

	HMODULE GetModuleHandle(const wchar_t* a_moduleName) noexcept
	{
		return reinterpret_cast<HMODULE>(::GetModuleHandleW(static_cast<::LPCWSTR>(a_moduleName)));
	}

	std::uint32_t GetPrivateProfileString(const char* a_appName, const char* a_keyName, const char* a_default, char* a_outString,
	                                      std::uint32_t a_size, const char* a_fileName) noexcept
	{
		return static_cast<std::uint32_t>(::GetPrivateProfileStringA(static_cast<::LPCSTR>(a_appName), static_cast<::LPCSTR>(a_keyName),
		                                                             static_cast<::LPCSTR>(a_default), static_cast<::LPSTR>(a_outString),
		                                                             static_cast<::DWORD>(a_size), static_cast<::LPCSTR>(a_fileName)));
	}

	std::uint32_t GetPrivateProfileString(const wchar_t* a_appName, const wchar_t* a_keyName, const wchar_t* a_default, wchar_t* a_outString,
	                                      std::uint32_t a_size, const wchar_t* a_fileName) noexcept
	{
		return static_cast<std::uint32_t>(::GetPrivateProfileStringW(static_cast<::LPCWSTR>(a_appName), static_cast<::LPCWSTR>(a_keyName),
		                                                             static_cast<::LPCWSTR>(a_default), static_cast<::LPWSTR>(a_outString),
		                                                             static_cast<::DWORD>(a_size), static_cast<::LPCWSTR>(a_fileName)));
	}

	void* GetProcAddress(void* a_module, const char* a_procName) noexcept
	{
		return reinterpret_cast<void*>(::GetProcAddress(static_cast<::HMODULE>(a_module), static_cast<::LPCSTR>(a_procName)));
	}

	std::string_view GetProcPath(HMODULE a_handle) noexcept
	{
		static std::string fileName(MAX_PATH + 1, ' ');
		auto               res = GetModuleFileName(a_handle, fileName.data(), MAX_PATH + 1);
		if (res == 0)
		{
			fileName = "[ProcessHost]";
			res      = 13;
		}

		return { fileName.c_str(), res };
	}

	bool IsDebuggerPresent() noexcept
	{
		return static_cast<bool>(::IsDebuggerPresent());
	}

	HMODULE LoadLibrary(const char* a_libFileName) noexcept
	{
		return reinterpret_cast<HMODULE>(::LoadLibraryA(static_cast<::LPCSTR>(a_libFileName)));
	}

	HMODULE LoadLibrary(const wchar_t* a_libFileName) noexcept
	{
		return reinterpret_cast<HMODULE>(::LoadLibraryW(static_cast<::LPCWSTR>(a_libFileName)));
	}

	std::int32_t MessageBox(void* a_wnd, const char* a_text, const char* a_caption, unsigned int a_type) noexcept
	{
		return static_cast<std::int32_t>(
			::MessageBoxA(static_cast<::HWND>(a_wnd), static_cast<::LPCSTR>(a_text), static_cast<::LPCSTR>(a_caption), static_cast<::UINT>(a_type)));
	}

	std::int32_t MessageBox(void* a_wnd, const wchar_t* a_text, const wchar_t* a_caption, unsigned int a_type) noexcept
	{
		return static_cast<std::int32_t>(::MessageBoxW(static_cast<::HWND>(a_wnd), static_cast<::LPCWSTR>(a_text), static_cast<::LPCWSTR>(a_caption),
		                                               static_cast<::UINT>(a_type)));
	}

	int MultiByteToWideChar(unsigned int a_codePage, std::uint32_t a_flags, const char* a_multiByteStr, int a_multiByte, wchar_t* a_wideCharStr,
	                        int a_wideChar)
	{
		return ::MultiByteToWideChar(static_cast<::UINT>(a_codePage), static_cast<::DWORD>(a_flags), static_cast<::LPCCH>(a_multiByteStr),
		                             a_multiByte, static_cast<::LPWSTR>(a_wideCharStr), a_wideChar);
	}

	void OutputDebugString(const char* a_outputString) noexcept
	{
		::OutputDebugStringA(static_cast<::LPCSTR>(a_outputString));
	}

	void OutputDebugString(const wchar_t* a_outputString) noexcept
	{
		::OutputDebugStringW(static_cast<::LPCWSTR>(a_outputString));
	}

	long RegGetValueW(HKEY hkey, const char* subKey, const char* value, unsigned long flags, unsigned long* type, void* data, unsigned long* length)
	{
		return ::RegGetValueA(reinterpret_cast<::HKEY>(hkey), subKey, value, flags, type, data, length);
	}

	long RegGetValueW(HKEY hkey, const wchar_t* subKey, const wchar_t* value, unsigned long flags, unsigned long* type, void* data,
	                  unsigned long* length)
	{
		return ::RegGetValueW(reinterpret_cast<::HKEY>(hkey), subKey, value, flags, type, data, length);
	}

	int ShowCursor(bool bShow) noexcept
	{
		return ::ShowCursor(static_cast<::BOOL>(bShow));
	}

	void TerminateProcess(void* a_process, unsigned int a_exitCode) noexcept
	{
		::TerminateProcess(static_cast<::HANDLE>(a_process), static_cast<::UINT>(a_exitCode));
#if defined(__clang__) || defined(__GNUC__)
		__builtin_unreachable();
#elif defined(_MSC_VER)
		__assume(false);
#endif
	}

	void* TlsGetValue(std::uint32_t a_tlsIndex) noexcept
	{
		return static_cast<void*>(::TlsGetValue(static_cast<::DWORD>(a_tlsIndex)));
	}

	bool TlsSetValue(std::uint32_t a_tlsIndex, void* a_tlsValue) noexcept
	{
		return static_cast<bool>(::TlsSetValue(static_cast<::DWORD>(a_tlsIndex), static_cast<::LPVOID>(a_tlsValue)));
	}

	bool VirtualFree(void* a_address, std::size_t a_size, std::uint32_t a_freeType) noexcept
	{
		return static_cast<bool>(::VirtualFree(static_cast<::LPVOID>(a_address), static_cast<::SIZE_T>(a_size), static_cast<::DWORD>(a_freeType)));
	}

	bool VerQueryValue(const void* a_block, const char* a_subBlock, void** a_buffer, unsigned int* a_len) noexcept
	{
		return static_cast<bool>(::VerQueryValueA(static_cast<::LPCVOID>(a_block), static_cast<::LPCSTR>(a_subBlock),
		                                          static_cast<::LPVOID*>(a_buffer), static_cast<::PUINT>(a_len)));
	}

	bool VerQueryValue(const void* a_block, const wchar_t* a_subBlock, void** a_buffer, unsigned int* a_len) noexcept
	{
		return static_cast<bool>(::VerQueryValueW(static_cast<::LPCVOID>(a_block), static_cast<::LPCWSTR>(a_subBlock),
		                                          static_cast<::LPVOID*>(a_buffer), static_cast<::PUINT>(a_len)));
	}

	bool VirtualProtect(void* a_address, std::size_t a_size, std::uint32_t a_newProtect, std::uint32_t* a_oldProtect) noexcept
	{
		return static_cast<bool>(::VirtualProtect(static_cast<::LPVOID>(a_address), static_cast<::SIZE_T>(a_size), static_cast<::DWORD>(a_newProtect),
		                                          reinterpret_cast<::PDWORD>(a_oldProtect)));
	}

	int WideCharToMultiByte(unsigned int a_codePage, std::uint32_t a_flags, const wchar_t* a_wideCharStr, int a_wideChar, char* a_multiByteStr,
	                        int a_multiByte, const char* a_defaultChar, int* a_usedDefaultChar)
	{
		return ::WideCharToMultiByte(static_cast<::UINT>(a_codePage), static_cast<::DWORD>(a_flags), static_cast<::LPCWCH>(a_wideCharStr), a_wideChar,
		                             static_cast<::LPSTR>(a_multiByteStr), a_multiByte, static_cast<::LPCCH>(a_defaultChar),
		                             static_cast<::LPBOOL>(a_usedDefaultChar));
	}

} // namespace SFSE::WinAPI
