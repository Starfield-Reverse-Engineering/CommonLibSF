#include "SFSE/Impl/WinAPI.h"

#define WIN32_LEAN_AND_MEAN

// clang-format off
#include <Windows.h>
#include <DbgHelp.h>
#include <objbase.h>
#include <ShlObj.h>
// clang-format on

#undef CreateFileMapping
#undef CreateProcess
#undef ExpandEnvironmentStrings
#undef FindFirstFile
#undef FindNextFile
#undef GetEnvironmentVariable
#undef GetFileVersionInfo
#undef GetFileVersionInfoSize
#undef GetKeyNameText
#undef GetModuleFileName
#undef GetModuleHandle
#undef GetPrivateProfileString
#undef IMAGE_FIRST_SECTION
#undef IMAGE_SNAP_BY_ORDINAL64
#undef LoadLibrary
#undef MessageBox
#undef OpenFileMapping
#undef OutputDebugString
#undef RegGetValue
#undef RegQueryValueEx
#undef SetEnvironmentVariable
#undef VerQueryValue

extern "C" IMAGE_DOS_HEADER __ImageBase;

namespace SFSE::WinAPI
{
	bool CloseHandle(
		void* a_handle) noexcept
	{
		return static_cast<bool>(
			::CloseHandle(
				static_cast<::HANDLE>(a_handle)));
	}

	void CoTaskMemFree(
		void* a_block) noexcept
	{
		::CoTaskMemFree(
			static_cast<::LPVOID>(a_block));
	}

	void* CreateFileMapping(
		void*                a_file,
		SECURITY_ATTRIBUTES* a_attributes,
		std::uint32_t        a_protect,
		std::uint32_t        a_maxSizeHigh,
		std::uint32_t        a_maxSizeLow,
		const char*          a_name) noexcept
	{
		return static_cast<void*>(
			::CreateFileMappingA(
				static_cast<::HANDLE>(a_file),
				reinterpret_cast<::LPSECURITY_ATTRIBUTES>(a_attributes),
				static_cast<::DWORD>(a_protect),
				static_cast<::DWORD>(a_maxSizeHigh),
				static_cast<::DWORD>(a_maxSizeLow),
				static_cast<::LPCSTR>(a_name)));
	}

	void* CreateFileMapping(
		void*                a_file,
		SECURITY_ATTRIBUTES* a_attributes,
		std::uint32_t        a_protect,
		std::uint32_t        a_maxSizeHigh,
		std::uint32_t        a_maxSizeLow,
		const wchar_t*       a_name) noexcept
	{
		return static_cast<void*>(
			::CreateFileMappingW(
				static_cast<::HANDLE>(a_file),
				reinterpret_cast<::LPSECURITY_ATTRIBUTES>(a_attributes),
				static_cast<::DWORD>(a_protect),
				static_cast<::DWORD>(a_maxSizeHigh),
				static_cast<::DWORD>(a_maxSizeLow),
				static_cast<::LPCWSTR>(a_name)));
	}

	bool CreateProcess(
		const char*          a_name,
		char*                a_cmd,
		SECURITY_ATTRIBUTES* a_procAttr,
		SECURITY_ATTRIBUTES* a_threadAttr,
		bool                 a_inherit,
		std::uint32_t        a_flags,
		void*                a_env,
		const char*          a_curDir,
		STARTUPINFOA*        a_startInfo,
		PROCESS_INFORMATION* a_procInfo) noexcept
	{
		return static_cast<bool>(
			::CreateProcessA(
				static_cast<::LPCSTR>(a_name),
				static_cast<::LPSTR>(a_cmd),
				reinterpret_cast<::LPSECURITY_ATTRIBUTES>(a_procAttr),
				reinterpret_cast<::LPSECURITY_ATTRIBUTES>(a_threadAttr),
				static_cast<::BOOL>(a_inherit),
				static_cast<::DWORD>(a_flags),
				static_cast<::LPVOID>(a_env),
				static_cast<::LPCSTR>(a_curDir),
				reinterpret_cast<::LPSTARTUPINFOA>(a_startInfo),
				reinterpret_cast<::LPPROCESS_INFORMATION>(a_procInfo)));
	}

	bool CreateProcess(
		const wchar_t*       a_name,
		wchar_t*             a_cmd,
		SECURITY_ATTRIBUTES* a_procAttr,
		SECURITY_ATTRIBUTES* a_threadAttr,
		bool                 a_inherit,
		std::uint32_t        a_flags,
		void*                a_env,
		const wchar_t*       a_curDir,
		STARTUPINFOW*        a_startInfo,
		PROCESS_INFORMATION* a_procInfo) noexcept
	{
		return static_cast<bool>(
			::CreateProcessW(
				static_cast<::LPCWSTR>(a_name),
				static_cast<::LPWSTR>(a_cmd),
				reinterpret_cast<::LPSECURITY_ATTRIBUTES>(a_procAttr),
				reinterpret_cast<::LPSECURITY_ATTRIBUTES>(a_threadAttr),
				static_cast<::BOOL>(a_inherit),
				static_cast<::DWORD>(a_flags),
				static_cast<::LPVOID>(a_env),
				static_cast<::LPCWSTR>(a_curDir),
				reinterpret_cast<::LPSTARTUPINFOW>(a_startInfo),
				reinterpret_cast<::LPPROCESS_INFORMATION>(a_procInfo)));
	}

	void* CreateRemoteThread(
		void*                a_process,
		SECURITY_ATTRIBUTES* a_threadAttr,
		std::size_t          a_stackSize,
		std::uint32_t (*a_startAddr)(void*),
		void*          a_param,
		std::uint32_t  a_flags,
		std::uint32_t* a_threadId) noexcept
	{
		return static_cast<void*>(
			::CreateRemoteThread(
				static_cast<::HANDLE>(a_process),
				reinterpret_cast<::LPSECURITY_ATTRIBUTES>(a_threadAttr),
				static_cast<::SIZE_T>(a_stackSize),
				reinterpret_cast<::LPTHREAD_START_ROUTINE>(a_startAddr),
				static_cast<::LPVOID>(a_param),
				static_cast<::DWORD>(a_flags),
				reinterpret_cast<::LPDWORD>(a_threadId)));
	}

	std::uint32_t ExpandEnvironmentStrings(
		const char*   a_src,
		char*         a_dst,
		std::uint32_t a_dstLen) noexcept
	{
		return static_cast<std::uint32_t>(
			::ExpandEnvironmentStringsA(
				static_cast<::LPCSTR>(a_src),
				static_cast<::LPSTR>(a_dst),
				static_cast<::DWORD>(a_dstLen)));
	}

	std::uint32_t ExpandEnvironmentStrings(
		const wchar_t* a_src,
		wchar_t*       a_dst,
		std::uint32_t  a_dstLen) noexcept
	{
		return static_cast<std::uint32_t>(
			::ExpandEnvironmentStringsW(
				static_cast<::LPCWSTR>(a_src),
				static_cast<::LPWSTR>(a_dst),
				static_cast<::DWORD>(a_dstLen)));
	}

	bool FindClose(
		void* a_file) noexcept
	{
		return static_cast<bool>(
			::FindClose(
				static_cast<::HMODULE>(a_file)));
	}

	void* FindFirstFile(
		const char*       a_name,
		WIN32_FIND_DATAA* a_data) noexcept
	{
		return static_cast<void*>(
			::FindFirstFileA(
				static_cast<::LPCSTR>(a_name),
				reinterpret_cast<::LPWIN32_FIND_DATAA>(a_data)));
	}

	void* FindFirstFile(
		const wchar_t*    a_name,
		WIN32_FIND_DATAW* a_data) noexcept
	{
		return static_cast<void*>(
			::FindFirstFileW(
				static_cast<::LPCWSTR>(a_name),
				reinterpret_cast<::LPWIN32_FIND_DATAW>(a_data)));
	}

	bool FindNextFile(
		void*             a_file,
		WIN32_FIND_DATAA* a_data) noexcept
	{
		return static_cast<bool>(
			::FindNextFileA(
				static_cast<::HANDLE>(a_file),
				reinterpret_cast<::LPWIN32_FIND_DATAA>(a_data)));
	}

	bool FindNextFile(
		void*             a_file,
		WIN32_FIND_DATAW* a_data) noexcept
	{
		return static_cast<bool>(
			::FindNextFileW(
				static_cast<::HANDLE>(a_file),
				reinterpret_cast<::LPWIN32_FIND_DATAW>(a_data)));
	}

	bool FlushInstructionCache(
		void*       a_process,
		const void* a_baseAddr,
		std::size_t a_size) noexcept
	{
		return static_cast<bool>(
			::FlushInstructionCache(
				static_cast<::HANDLE>(a_process),
				static_cast<::LPCVOID>(a_baseAddr),
				static_cast<::SIZE_T>(a_size)));
	}

	bool FreeLibrary(
		HMODULE a_module) noexcept
	{
		return static_cast<bool>(
			::FreeLibrary(
				reinterpret_cast<::HMODULE>(a_module)));
	}

	void* GetCurrentModule() noexcept
	{
		return static_cast<void*>(
			std::addressof(__ImageBase));
	}

	void* GetCurrentProcess() noexcept
	{
		return static_cast<void*>(
			::GetCurrentProcess());
	}

	std::uint32_t GetCurrentThreadID() noexcept
	{
		return static_cast<std::uint32_t>(
			::GetCurrentThreadId());
	}

	std::uint32_t GetEnvironmentVariable(
		const char*   a_name,
		char*         a_buffer,
		std::uint32_t a_bufferLen) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetEnvironmentVariableA(
				static_cast<::LPCSTR>(a_name),
				static_cast<::LPSTR>(a_buffer),
				static_cast<::DWORD>(a_bufferLen)));
	}

	std::uint32_t GetEnvironmentVariable(
		const wchar_t* a_name,
		wchar_t*       a_buffer,
		std::uint32_t  a_bufferLen) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetEnvironmentVariableW(
				static_cast<::LPCWSTR>(a_name),
				static_cast<::LPWSTR>(a_buffer),
				static_cast<::DWORD>(a_bufferLen)));
	}

	bool GetFileVersionInfo(
		const char*   a_name,
		std::uint32_t a_handle,
		std::uint32_t a_dataLen,
		void*         a_data) noexcept
	{
		return static_cast<bool>(
			::GetFileVersionInfoA(
				static_cast<::LPCSTR>(a_name),
				static_cast<::DWORD>(a_handle),
				static_cast<::DWORD>(a_dataLen),
				static_cast<::LPVOID>(a_data)));
	}

	bool GetFileVersionInfo(
		const wchar_t* a_name,
		std::uint32_t  a_handle,
		std::uint32_t  a_dataLen,
		void*          a_data) noexcept
	{
		return static_cast<bool>(
			::GetFileVersionInfoW(
				static_cast<::LPCWSTR>(a_name),
				static_cast<::DWORD>(a_handle),
				static_cast<::DWORD>(a_dataLen),
				static_cast<::LPVOID>(a_data)));
	}

	std::uint32_t GetFileVersionInfoSize(
		const char*    a_name,
		std::uint32_t* a_handle) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetFileVersionInfoSizeA(
				static_cast<::LPCSTR>(a_name),
				reinterpret_cast<::LPDWORD>(a_handle)));
	}

	std::uint32_t GetFileVersionInfoSize(
		const wchar_t* a_name,
		std::uint32_t* a_handle) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetFileVersionInfoSizeW(
				static_cast<::LPCWSTR>(a_name),
				reinterpret_cast<::LPDWORD>(a_handle)));
	}

	std::int32_t GetKeyNameText(
		std::int32_t a_param,
		wchar_t*     a_buffer,
		std::int32_t a_bufferLen) noexcept
	{
		return ::GetKeyNameTextW(
			static_cast<::LONG>(a_param),
			static_cast<::LPWSTR>(a_buffer),
			a_bufferLen);
	}

	std::int32_t GetKeyNameText(
		std::int32_t a_param,
		char*        a_buffer,
		std::int32_t a_bufferLen) noexcept
	{
		return ::GetKeyNameTextA(
			static_cast<::LONG>(a_param),
			static_cast<::LPSTR>(a_buffer),
			a_bufferLen);
	}

	std::int16_t GetKeyState(
		std::int32_t a_key) noexcept
	{
		return ::GetKeyState(a_key);
	}

	std::uint32_t GetLastError() noexcept
	{
		return static_cast<std::uint32_t>(
			::GetLastError());
	}

	std::size_t GetMaxPath() noexcept
	{
		return static_cast<std::size_t>(MAX_PATH);
	}

	std::uint32_t GetModuleFileName(
		void*         a_module,
		char*         a_name,
		std::uint32_t a_nameLen) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetModuleFileNameA(
				static_cast<::HMODULE>(a_module),
				static_cast<::LPSTR>(a_name),
				static_cast<::DWORD>(a_nameLen)));
	}

	std::uint32_t GetModuleFileName(
		void*         a_module,
		wchar_t*      a_name,
		std::uint32_t a_nameLen) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetModuleFileNameW(
				static_cast<::HMODULE>(a_module),
				static_cast<::LPWSTR>(a_name),
				static_cast<::DWORD>(a_nameLen)));
	}

	HMODULE GetModuleHandle(
		const char* a_name) noexcept
	{
		return reinterpret_cast<HMODULE>(
			::GetModuleHandleA(
				static_cast<::LPCSTR>(a_name)));
	}

	HMODULE GetModuleHandle(
		const wchar_t* a_name) noexcept
	{
		return reinterpret_cast<HMODULE>(
			::GetModuleHandleW(static_cast<::LPCWSTR>(a_name)));
	}

	std::uint32_t GetPrivateProfileString(
		const char*   a_app,
		const char*   a_key,
		const char*   a_default,
		char*         a_out,
		std::uint32_t a_outLen,
		const char*   a_name) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetPrivateProfileStringA(
				static_cast<::LPCSTR>(a_app),
				static_cast<::LPCSTR>(a_key),
				static_cast<::LPCSTR>(a_default),
				static_cast<::LPSTR>(a_out),
				static_cast<::DWORD>(a_outLen),
				static_cast<::LPCSTR>(a_name)));
	}

	std::uint32_t GetPrivateProfileString(
		const wchar_t* a_app,
		const wchar_t* a_key,
		const wchar_t* a_default,
		wchar_t*       a_out,
		std::uint32_t  a_outLen,
		const wchar_t* a_name) noexcept
	{
		return static_cast<std::uint32_t>(
			::GetPrivateProfileStringW(
				static_cast<::LPCWSTR>(a_app),
				static_cast<::LPCWSTR>(a_key),
				static_cast<::LPCWSTR>(a_default),
				static_cast<::LPWSTR>(a_out),
				static_cast<::DWORD>(a_outLen),
				static_cast<::LPCWSTR>(a_name)));
	}

	void* GetProcAddress(
		void*       a_module,
		const char* a_name) noexcept
	{
		return reinterpret_cast<void*>(
			::GetProcAddress(
				static_cast<::HMODULE>(a_module),
				static_cast<::LPCSTR>(a_name)));
	}

	std::string_view GetProcPath(
		HMODULE a_handle) noexcept
	{
		static std::string fileName(MAX_PATH + 1, ' ');
		auto               res = GetModuleFileName(a_handle, fileName.data(), MAX_PATH + 1);
		if (res == 0) {
			fileName = "[ProcessHost]";
			res = 13;
		}

		return { fileName.c_str(), res };
	}

	void GetSystemInfo(
		SYSTEM_INFO* a_info) noexcept
	{
		::GetSystemInfo(
			reinterpret_cast<::LPSYSTEM_INFO>(a_info));
	}

	bool IMAGE_SNAP_BY_ORDINAL64(
		std::uint64_t a_ordinal) noexcept
	{
		return (a_ordinal & IMAGE_ORDINAL_FLAG64) != 0;
	}

	IMAGE_SECTION_HEADER* IMAGE_FIRST_SECTION(
		const IMAGE_NT_HEADERS64* a_header) noexcept
	{
		constexpr auto opt = __builtin_offsetof(IMAGE_NT_HEADERS64, optionalHeader);
		const auto     optSize = a_header->fileHeader.optionalHeaderSize;
		const auto     section = reinterpret_cast<std::uintptr_t>(a_header) + opt + optSize;
		return reinterpret_cast<IMAGE_SECTION_HEADER*>(section);
	}

	bool IsDebuggerPresent() noexcept
	{
		return static_cast<bool>(
			::IsDebuggerPresent());
	}

	std::int32_t LCMapStringEx(
		const wchar_t*  a_locale,
		std::uint32_t   a_flags,
		const wchar_t*  a_src,
		std::int32_t    a_srcLen,
		wchar_t*        a_dest,
		std::int32_t    a_destLen,
		NLSVERSIONINFO* a_info,
		void*           a_reserved,
		std::intptr_t   a_sortHandle) noexcept
	{
		return ::LCMapStringEx(
			static_cast<::LPCWSTR>(a_locale),
			static_cast<::DWORD>(a_flags),
			static_cast<::LPCWSTR>(a_src),
			a_srcLen,
			static_cast<::LPWSTR>(a_dest),
			a_destLen,
			reinterpret_cast<::LPNLSVERSIONINFO>(a_info),
			static_cast<::LPVOID>(a_reserved),
			static_cast<::LPARAM>(a_sortHandle));
	}

	HMODULE LoadLibrary(
		const char* a_name) noexcept
	{
		return reinterpret_cast<HMODULE>(
			::LoadLibraryA(
				static_cast<::LPCSTR>(a_name)));
	}

	HMODULE LoadLibrary(
		const wchar_t* a_name) noexcept
	{
		return reinterpret_cast<HMODULE>(
			::LoadLibraryW(static_cast<::LPCWSTR>(a_name)));
	}

	void* MapViewOfFile(
		void*         a_object,
		std::uint32_t a_desiredAccess,
		std::uint32_t a_fileOffsetHigh,
		std::uint32_t a_fileOffsetLow,
		std::size_t   a_numBytesToMap) noexcept
	{
		return static_cast<void*>(
			::MapViewOfFile(
				static_cast<::LPVOID>(a_object),
				static_cast<::DWORD>(a_desiredAccess),
				static_cast<::DWORD>(a_fileOffsetHigh),
				static_cast<::DWORD>(a_fileOffsetLow),
				static_cast<::SIZE_T>(a_numBytesToMap)));
	}

	void* MapViewOfFileEx(
		void*         a_object,
		std::uint32_t a_desiredAccess,
		std::uint32_t a_fileOffsetHigh,
		std::uint32_t a_fileOffsetLow,
		std::size_t   a_numBytesToMap,
		void*         a_baseAddress) noexcept
	{
		return static_cast<void*>(
			::MapViewOfFileEx(
				static_cast<::LPVOID>(a_object),
				static_cast<::DWORD>(a_desiredAccess),
				static_cast<::DWORD>(a_fileOffsetHigh),
				static_cast<::DWORD>(a_fileOffsetLow),
				static_cast<::SIZE_T>(a_numBytesToMap),
				static_cast<::LPVOID>(a_baseAddress)));
	}

	std::int32_t MessageBox(
		void*         a_wnd,
		const char*   a_text,
		const char*   a_caption,
		std::uint32_t a_type) noexcept
	{
		return static_cast<std::int32_t>(
			::MessageBoxA(
				static_cast<::HWND>(a_wnd),
				static_cast<::LPCSTR>(a_text),
				static_cast<::LPCSTR>(a_caption),
				static_cast<::UINT>(a_type)));
	}

	std::int32_t MessageBox(
		void*          a_wnd,
		const wchar_t* a_text,
		const wchar_t* a_caption,
		std::uint32_t  a_type) noexcept
	{
		return static_cast<std::int32_t>(
			::MessageBoxW(
				static_cast<::HWND>(a_wnd),
				static_cast<::LPCWSTR>(a_text),
				static_cast<::LPCWSTR>(a_caption),
				static_cast<::UINT>(a_type)));
	}

	std::int32_t MultiByteToWideChar(
		std::uint32_t a_codePage,
		std::uint32_t a_flags,
		const char*   a_str,
		std::int32_t  a_strLen,
		wchar_t*      a_wstr,
		std::int32_t  a_wstrLen)
	{
		return ::MultiByteToWideChar(
			static_cast<::UINT>(a_codePage),
			static_cast<::DWORD>(a_flags),
			static_cast<::LPCCH>(a_str),
			a_strLen,
			static_cast<::LPWSTR>(a_wstr),
			a_wstrLen);
	}

	std::int32_t NormalizeString(
		std::int32_t   a_normForm,
		const wchar_t* a_src,
		std::int32_t   a_srcLen,
		wchar_t*       a_dest,
		std::int32_t   a_destLen)
	{
		return ::NormalizeString(
			static_cast<::NORM_FORM>(a_normForm),
			static_cast<::LPCWSTR>(a_src),
			a_srcLen,
			static_cast<::LPWSTR>(a_dest),
			a_destLen);
	}

	void* OpenFileMapping(
		std::uint32_t a_desiredAccess,
		bool          a_inheritHandle,
		const char*   a_name) noexcept
	{
		return static_cast<void*>(
			::OpenFileMappingA(
				static_cast<::DWORD>(a_desiredAccess),
				static_cast<::BOOL>(a_inheritHandle),
				static_cast<::LPCSTR>(a_name)));
	}

	void* OpenFileMapping(
		std::uint32_t  a_desiredAccess,
		bool           a_inheritHandle,
		const wchar_t* a_name) noexcept
	{
		return static_cast<void*>(
			::OpenFileMappingW(
				static_cast<::DWORD>(a_desiredAccess),
				static_cast<::BOOL>(a_inheritHandle),
				static_cast<::LPCWSTR>(a_name)));
	}

	void OutputDebugString(
		const char* a_out) noexcept
	{
		::OutputDebugStringA(
			static_cast<::LPCSTR>(a_out));
	}

	void OutputDebugString(
		const wchar_t* a_out) noexcept
	{
		::OutputDebugStringW(
			static_cast<::LPCWSTR>(a_out));
	}

	std::int32_t RegGetValue(
		HKEY           a_key,
		const char*    a_subKey,
		const char*    a_value,
		std::uint32_t  a_flags,
		std::uint32_t* a_type,
		void*          a_data,
		std::uint32_t* a_dataLen)
	{
		return ::RegGetValueA(
			reinterpret_cast<::HKEY>(a_key),
			a_subKey,
			a_value,
			a_flags,
			reinterpret_cast<::LPDWORD>(a_type),
			a_data,
			reinterpret_cast<::LPDWORD>(a_dataLen));
	}

	std::int32_t RegGetValue(
		HKEY           a_key,
		const wchar_t* a_subKey,
		const wchar_t* a_value,
		std::uint32_t  a_flags,
		std::uint32_t* a_type,
		void*          a_data,
		std::uint32_t* a_dataLen)
	{
		return ::RegGetValueW(
			reinterpret_cast<::HKEY>(a_key),
			a_subKey,
			a_value,
			a_flags,
			reinterpret_cast<::LPDWORD>(a_type),
			a_data,
			reinterpret_cast<::LPDWORD>(a_dataLen));
	}

	std::uint32_t ResumeThread(
		void* a_handle) noexcept
	{
		return static_cast<std::uint32_t>(
			::ResumeThread(
				static_cast<::HANDLE>(a_handle)));
	}

	bool SetEnvironmentVariable(
		const char* a_name,
		const char* a_value) noexcept
	{
		return static_cast<bool>(
			::SetEnvironmentVariableA(
				static_cast<::LPCSTR>(a_name),
				static_cast<::LPCSTR>(a_value)));
	}

	bool SetEnvironmentVariable(
		const wchar_t* a_name,
		const wchar_t* a_value) noexcept
	{
		return static_cast<bool>(
			::SetEnvironmentVariableW(
				static_cast<::LPCWSTR>(a_name),
				static_cast<::LPCWSTR>(a_value)));
	}

	std::int32_t SHGetKnownFolderPath(
		const GUID&   a_id,
		std::uint32_t a_flags,
		void*         a_token,
		wchar_t**     a_path) noexcept
	{
		return static_cast<std::int32_t>(
			::SHGetKnownFolderPath(
				reinterpret_cast<const ::KNOWNFOLDERID&>(a_id),
				static_cast<::DWORD>(a_flags),
				static_cast<::HANDLE>(a_token),
				static_cast<::PWSTR*>(a_path)));
	}

	std::int32_t ShowCursor(
		bool a_show) noexcept
	{
		return ::ShowCursor(
			static_cast<::BOOL>(a_show));
	}

	bool TerminateProcess(
		void*         a_process,
		std::uint32_t a_exitCode) noexcept
	{
		return static_cast<bool>(
			::TerminateProcess(
				static_cast<::HANDLE>(a_process),
				static_cast<::UINT>(a_exitCode)));
	}

	void* TlsGetValue(
		std::uint32_t a_index) noexcept
	{
		return static_cast<void*>(
			::TlsGetValue(
				static_cast<::DWORD>(a_index)));
	}

	bool TlsSetValue(
		std::uint32_t a_index,
		void*         a_value) noexcept
	{
		return static_cast<bool>(
			::TlsSetValue(
				static_cast<::DWORD>(a_index),
				static_cast<::LPVOID>(a_value)));
	}

	std::uint32_t UnDecorateSymbolName(
		const char*   a_name,
		char*         a_out,
		std::uint32_t a_outLenMax,
		std::uint32_t a_flags) noexcept
	{
		return static_cast<std::uint32_t>(
			::UnDecorateSymbolName(
				static_cast<::PCSTR>(a_name),
				static_cast<::PSTR>(a_out),
				static_cast<::DWORD>(a_outLenMax),
				static_cast<::DWORD>(a_flags)));
	}

	std::uint32_t UnDecorateSymbolName(
		const wchar_t* a_name,
		wchar_t*       a_out,
		std::uint32_t  a_outLenMax,
		std::uint32_t  a_flags) noexcept
	{
		return static_cast<std::uint32_t>(
			::UnDecorateSymbolNameW(
				static_cast<::PCWSTR>(a_name),
				static_cast<::PWSTR>(a_out),
				static_cast<::DWORD>(a_outLenMax),
				static_cast<::DWORD>(a_flags)));
	}

	bool UnmapViewOfFile(
		const void* a_baseAddress) noexcept
	{
		return static_cast<bool>(
			::UnmapViewOfFile(
				static_cast<::LPCVOID>(a_baseAddress)));
	}

	bool VerQueryValue(
		const void*    a_block,
		const char*    a_subBlock,
		void**         a_buffer,
		std::uint32_t* a_bufferLen) noexcept
	{
		return static_cast<bool>(
			::VerQueryValueA(static_cast<::LPCVOID>(a_block),
				static_cast<::LPCSTR>(a_subBlock),
				static_cast<::LPVOID*>(a_buffer),
				static_cast<::PUINT>(a_bufferLen)));
	}

	bool VerQueryValue(
		const void*    a_block,
		const wchar_t* a_subBlock,
		void**         a_buffer,
		std::uint32_t* a_bufferLen) noexcept
	{
		return static_cast<bool>(
			::VerQueryValueW(
				static_cast<::LPCVOID>(a_block),
				static_cast<::LPCWSTR>(a_subBlock),
				static_cast<::LPVOID*>(a_buffer),
				static_cast<::PUINT>(a_bufferLen)));
	}

	void* VirtualAlloc(
		void*         a_address,
		std::size_t   a_size,
		std::uint32_t a_type,
		std::uint32_t a_protect) noexcept
	{
		return static_cast<void*>(
			::VirtualAlloc(
				static_cast<::LPVOID>(a_address),
				static_cast<::SIZE_T>(a_size),
				static_cast<::DWORD>(a_type),
				static_cast<::DWORD>(a_protect)));
	}

	void* VirtualAllocEx(
		void*         a_process,
		void*         a_address,
		std::size_t   a_size,
		std::uint32_t a_type,
		std::uint32_t a_protect) noexcept
	{
		return static_cast<void*>(
			::VirtualAllocEx(
				static_cast<::HANDLE>(a_process),
				static_cast<::LPVOID>(a_address),
				static_cast<::SIZE_T>(a_size),
				static_cast<::DWORD>(a_type),
				static_cast<::DWORD>(a_protect)));
	}

	bool VirtualFree(
		void*         a_address,
		std::size_t   a_size,
		std::uint32_t a_type) noexcept
	{
		return static_cast<bool>(
			::VirtualFree(
				static_cast<::LPVOID>(a_address),
				static_cast<::SIZE_T>(a_size),
				static_cast<::DWORD>(a_type)));
	}

	bool VirtualFreeEx(
		void*         a_process,
		void*         a_address,
		std::size_t   a_size,
		std::uint32_t a_type) noexcept
	{
		return static_cast<bool>(
			::VirtualFreeEx(
				static_cast<::HANDLE>(a_process),
				static_cast<::LPVOID>(a_address),
				static_cast<::SIZE_T>(a_size),
				static_cast<::DWORD>(a_type)));
	}

	bool VirtualProtect(
		void*          a_address,
		std::size_t    a_size,
		std::uint32_t  a_newProtect,
		std::uint32_t* a_oldProtect) noexcept
	{
		return static_cast<bool>(
			::VirtualProtect(
				static_cast<::LPVOID>(a_address),
				static_cast<::SIZE_T>(a_size),
				static_cast<::DWORD>(a_newProtect),
				reinterpret_cast<::PDWORD>(a_oldProtect)));
	}

	bool VirtualProtectEx(
		void*          a_process,
		void*          a_address,
		std::size_t    a_size,
		std::uint32_t  a_newProtect,
		std::uint32_t* a_oldProtect) noexcept
	{
		return static_cast<bool>(
			::VirtualProtectEx(
				static_cast<::HANDLE>(a_process),
				static_cast<::LPVOID>(a_address),
				static_cast<::SIZE_T>(a_size),
				static_cast<::DWORD>(a_newProtect),
				reinterpret_cast<::PDWORD>(a_oldProtect)));
	}

	std::size_t VirtualQuery(
		const void*               a_address,
		MEMORY_BASIC_INFORMATION* a_buffer,
		std::size_t               a_bufferLen) noexcept
	{
		return static_cast<std::size_t>(
			::VirtualQuery(
				static_cast<::LPCVOID>(a_address),
				reinterpret_cast<::PMEMORY_BASIC_INFORMATION>(a_buffer),
				static_cast<::SIZE_T>(a_bufferLen)));
	}

	std::size_t VirtualQueryEx(
		void*                     a_process,
		const void*               a_address,
		MEMORY_BASIC_INFORMATION* a_buffer,
		std::size_t               a_bufferLen) noexcept
	{
		return static_cast<std::size_t>(
			::VirtualQueryEx(
				static_cast<::HANDLE>(a_process),
				static_cast<::LPCVOID>(a_address),
				reinterpret_cast<::PMEMORY_BASIC_INFORMATION>(a_buffer),
				static_cast<::SIZE_T>(a_bufferLen)));
	}

	std::uint32_t WaitForSingleObject(
		void*         a_handle,
		std::uint32_t a_milliseconds) noexcept
	{
		return static_cast<std::uint32_t>(
			::WaitForSingleObject(
				static_cast<::HANDLE>(a_handle),
				static_cast<::DWORD>(a_milliseconds)));
	}

	std::uint32_t WaitForSingleObjectEx(
		void*         a_handle,
		std::uint32_t a_milliseconds,
		bool          a_alertable) noexcept
	{
		return static_cast<std::uint32_t>(
			::WaitForSingleObjectEx(
				static_cast<::HANDLE>(a_handle),
				static_cast<::DWORD>(a_milliseconds),
				static_cast<::BOOL>(a_alertable)));
	}

	std::int32_t WideCharToMultiByte(
		std::uint32_t  a_codePage,
		std::uint32_t  a_flags,
		const wchar_t* a_wstr,
		std::int32_t   a_wstrLen,
		char*          a_str,
		std::int32_t   a_strLen,
		const char*    a_default,
		std::int32_t*  a_defaultLen)
	{
		return ::WideCharToMultiByte(
			static_cast<::UINT>(a_codePage),
			static_cast<::DWORD>(a_flags),
			static_cast<::LPCWCH>(a_wstr),
			a_wstrLen,
			static_cast<::LPSTR>(a_str),
			a_strLen,
			static_cast<::LPCCH>(a_default),
			static_cast<::LPBOOL>(a_defaultLen));
	}

	bool WriteProcessMemory(
		void*        a_process,
		void*        a_address,
		const void*  a_buffer,
		std::size_t  a_bufferLen,
		std::size_t* a_bufferWritten) noexcept
	{
		return static_cast<bool>(
			::WriteProcessMemory(
				static_cast<::HANDLE>(a_process),
				static_cast<::LPVOID>(a_address),
				static_cast<::LPCVOID>(a_buffer),
				static_cast<::SIZE_T>(a_bufferLen),
				static_cast<::SIZE_T*>(a_bufferWritten)));
	}
}  // namespace SFSE::WinAPI
