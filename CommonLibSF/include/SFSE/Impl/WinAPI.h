#pragma once

#undef CP_UTF8
#undef IMAGE_SCN_MEM_EXECUTE
#undef IMAGE_SCN_MEM_WRITE
#undef INVALID_HANDLE_VALUE
#undef MAX_PATH
#undef MEM_COMMIT
#undef MEM_RESERVE
#undef MEM_RELEASE
#undef PAGE_EXECUTE_READWRITE
#undef HKEY_LOCAL_MACHINE

#undef GetEnvironmentVariable
#undef GetFileVersionInfoSize
#undef GetModuleFileName
#undef VerQueryValue
#undef GetFileVersionInfo
#undef GetModuleHandle
#undef LoadLibrary
#undef MessageBox
#undef OutputDebugString

namespace SFSE::WinAPI
{
	inline constexpr auto CP_UTF8{ 65001u };
	inline constexpr auto FILE_ATTRIBUTE_READONLY{ 0x00000001u };
	inline constexpr auto FILE_ATTRIBUTE_HIDDEN{ 0x00000002u };
	inline constexpr auto FILE_ATTRIBUTE_SYSTEM{ 0x00000004u };
	inline constexpr auto FILE_ATTRIBUTE_DIRECTORY{ 0x00000010u };
	inline constexpr auto FILE_ATTRIBUTE_ARCHIVE{ 0x00000020u };
	inline constexpr auto IMAGE_SCN_MEM_EXECUTE{ 0x20000000u };
	inline constexpr auto IMAGE_SCN_MEM_WRITE{ 0x80000000u };
	inline const auto     INVALID_HANDLE_VALUE{ reinterpret_cast<void*>(static_cast<std::intptr_t>(-1)) };
	inline constexpr auto MAX_PATH{ 260u };
	inline constexpr auto MEM_COMMIT{ 0x00001000u };
	inline constexpr auto MEM_RESERVE{ 0x00002000u };
	inline constexpr auto MEM_RELEASE{ 0x00008000u };
	inline constexpr auto PAGE_EXECUTE_READWRITE{ 0x40u };

	struct CRITICAL_SECTION
	{
	public:
		// members
		void*          DebugInfo;       // 00
		std::int32_t   LockCount;       // 08
		std::int32_t   RecursionCount;  // 0C
		void*          OwningThread;    // 10
		void*          LockSemaphore;   // 18
		std::uint64_t* SpinCount;       // 20
	};

	static_assert(sizeof(CRITICAL_SECTION) == 0x28);

	struct _FILETIME
	{
	public:
		// members
		std::uint32_t dwLowDateTime;   // 00
		std::uint32_t dwHighDateTime;  // 04
	};

	static_assert(sizeof(_FILETIME) == 0x8);
	using FILETIME = _FILETIME;

	struct _GUID
	{
		std::uint32_t Data1;
		std::uint16_t Data2;
		std::uint16_t Data3;
		std::uint8_t  Data4[8];
	};

	static_assert(sizeof(_GUID) == 0x10);
	using GUID = _GUID;

	struct HWND__;
	using HWND = HWND__*;

	struct HINSTANCE__;
	using HINSTANCE = HINSTANCE__*;
	using HMODULE = HINSTANCE;

	struct HKEY__;
	using HKEY = HKEY__*;

	inline auto HKEY_LOCAL_MACHINE = reinterpret_cast<HKEY>(static_cast<uintptr_t>(0x80000002));

	struct _WIN32_FIND_DATAA
	{
	public:
		// members
		std::uint32_t dwFileAttributes;
		FILETIME      ftCreationTime;
		FILETIME      ftLastAccessTime;
		FILETIME      ftLastWriteTime;
		std::uint32_t nFileSizeHigh;
		std::uint32_t nFileSizeLow;
		std::uint32_t dwReserved0;
		std::uint32_t dwReserved1;
		char          cFileName[MAX_PATH];
		char          cAlternateFileName[14];
	};

	static_assert(sizeof(_WIN32_FIND_DATAA) == 0x140);
	using WIN32_FIND_DATAA = _WIN32_FIND_DATAA;

	struct _WIN32_FIND_DATAW
	{
	public:
		// members
		std::uint32_t dwFileAttributes;
		FILETIME      ftCreationTime;
		FILETIME      ftLastAccessTime;
		FILETIME      ftLastWriteTime;
		std::uint32_t nFileSizeHigh;
		std::uint32_t nFileSizeLow;
		std::uint32_t dwReserved0;
		std::uint32_t dwReserved1;
		wchar_t       cFileName[MAX_PATH];
		wchar_t       cAlternateFileName[14];
	};

	static_assert(sizeof(_WIN32_FIND_DATAW) == 0x250);
	using WIN32_FIND_DATAW = _WIN32_FIND_DATAW;

	struct tagRECT
	{
		std::int32_t left;
		std::int32_t top;
		std::int32_t right;
		std::int32_t bottom;
	};

	using RECT = tagRECT;

	struct tagPOINT
	{
		std::int32_t x;
		std::int32_t y;
	};

	using POINT = tagPOINT;

	using HRESULT = std::int32_t;

	enum VKEnum : std::uint32_t
	{
		VK_LBUTTON = 0x1,
		VK_RBUTTON = 0x2,
		VK_CANCEL = 0x3,
		VK_MBUTTON = 0x4,
		VK_XBUTTON1 = 0x5,
		VK_XBUTTON2 = 0x6,
		VK_BACK = 0x8,
		VK_TAB = 0x9,
		VK_RESERVED_0A = 0xA,
		VK_RESERVED_0B = 0xB,
		VK_CLEAR = 0xC,
		VK_RETURN = 0xD,
		VK_SHIFT = 0x10,
		VK_CONTROL = 0x11,
		VK_MENU = 0x12,
		VK_PAUSE = 0x13,
		VK_CAPITAL = 0x14,
		VK_KANA = 0x15,
		VK_HANGUEL = 0x15,
		VK_HANGUL = 0x15,
		VK_IME_ON = 0x16,
		VK_JUNJA = 0x17,
		VK_FINAL = 0x18,
		VK_HANJA = 0x19,
		VK_KANJI = VK_HANJA,
		VK_IME_OFF = 0x1A,
		VK_ESCAPE = 0x1B,
		VK_CONVERT = 0x1C,
		VK_NONCONVERT = 0x1D,
		VK_ACCEPT = 0x1E,
		VK_MODECHANGE = 0x1F,
		VK_SPACE = 0x20,
		VK_PRIOR = 0x21,
		VK_NEXT = 0x22,
		VK_END = 0x23,
		VK_HOME = 0x24,
		VK_LEFT = 0x25,
		VK_UP = 0x26,
		VK_RIGHT = 0x27,
		VK_DOWN = 0x28,
		VK_SELECT = 0x29,
		VK_PRINT = 0x2A,
		VK_EXECUTE = 0x2B,
		VK_SNAPSHOT = 0x2C,
		VK_INSERT = 0x2D,
		VK_DELETE = 0x2E,
		VK_HELP = 0x2F,
		VK_0 = 0x30,
		VK_1 = 0x31,
		VK_2 = 0x32,
		VK_3 = 0x33,
		VK_4 = 0x34,
		VK_5 = 0x35,
		VK_6 = 0x36,
		VK_7 = 0x37,
		VK_8 = 0x38,
		VK_9 = 0x39,
		VK_A = 0x41,
		VK_B = 0x42,
		VK_C = 0x43,
		VK_D = 0x44,
		VK_E = 0x45,
		VK_F = 0x46,
		VK_G = 0x47,
		VK_H = 0x48,
		VK_I = 0x49,
		VK_J = 0x4A,
		VK_K = 0x4B,
		VK_L = 0x4C,
		VK_M = 0x4D,
		VK_N = 0x4E,
		VK_O = 0x4F,
		VK_P = 0x50,
		VK_Q = 0x51,
		VK_R = 0x52,
		VK_S = 0x53,
		VK_T = 0x54,
		VK_U = 0x55,
		VK_V = 0x56,
		VK_W = 0x57,
		VK_X = 0x58,
		VK_Y = 0x59,
		VK_Z = 0x5A,
		VK_LWIN = 0x5B,
		VK_RWIN = 0x5C,
		VK_APPS = 0x5D,
		VK_RESERVED_5E = 0x5E,
		VK_SLEEP = 0x5F,
		VK_NUMPAD0 = 0x60,
		VK_NUMPAD1 = 0x61,
		VK_NUMPAD2 = 0x62,
		VK_NUMPAD3 = 0x63,
		VK_NUMPAD4 = 0x64,
		VK_NUMPAD5 = 0x65,
		VK_NUMPAD6 = 0x66,
		VK_NUMPAD7 = 0x67,
		VK_NUMPAD8 = 0x68,
		VK_NUMPAD9 = 0x69,
		VK_MULTIPLY = 0x6A,
		VK_ADD = 0x6B,
		VK_SEPARATOR = 0x6C,
		VK_SUBTRACT = 0x6D,
		VK_DECIMAL = 0x6E,
		VK_DIVIDE = 0x6F,
		VK_F1 = 0x70,
		VK_F2 = 0x71,
		VK_F3 = 0x72,
		VK_F4 = 0x73,
		VK_F5 = 0x74,
		VK_F6 = 0x75,
		VK_F7 = 0x76,
		VK_F8 = 0x77,
		VK_F9 = 0x78,
		VK_F10 = 0x79,
		VK_F11 = 0x7A,
		VK_F12 = 0x7B,
		VK_F13 = 0x7C,
		VK_F14 = 0x7D,
		VK_F15 = 0x7E,
		VK_F16 = 0x7F,
		VK_F17 = 0x80,
		VK_F18 = 0x81,
		VK_F19 = 0x82,
		VK_F20 = 0x83,
		VK_F21 = 0x84,
		VK_F22 = 0x85,
		VK_F23 = 0x86,
		VK_F24 = 0x87,
		VK_NUMLOCK = 0x90,
		VK_SCROLL = 0x91,
		VK_OEMSPECIFIC_92 = 0x92,
		VK_OEMSPECIFIC_93 = 0x93,
		VK_OEMSPECIFIC_94 = 0x94,
		VK_OEMSPECIFIC_95 = 0x95,
		VK_OEMSPECIFIC_96 = 0x96,
		VK_LSHIFT = 0xA0,
		VK_RSHIFT = 0xA1,
		VK_LCONTROL = 0xA2,
		VK_RCONTROL = 0xA3,
		VK_LMENU = 0xA4,
		VK_RMENU = 0xA5,
		VK_BROWSER_BACK = 0xA6,
		VK_BROWSER_FORWARD = 0xA7,
		VK_BROWSER_REFRESH = 0xA8,
		VK_BROWSER_STOP = 0xA9,
		VK_BROWSER_SEARCH = 0xAA,
		VK_BROWSER_FAVORITES = 0xAB,
		VK_BROWSER_HOME = 0xAC,
		VK_VOLUME_MUTE = 0xAD,
		VK_VOLUME_DOWN = 0xAE,
		VK_VOLUME_UP = 0xAF,
		VK_MEDIA_NEXT_TRACK = 0xB0,
		VK_MEDIA_PREV_TRACK = 0xB1,
		VK_MEDIA_STOP = 0xB2,
		VK_MEDIA_PLAY_PAUSE = 0xB3,
		VK_LAUNCH_MAIL = 0xB4,
		VK_LAUNCH_MEDIA_SELECT = 0xB5,
		VK_LAUNCH_APP1 = 0xB6,
		VK_LAUNCH_APP2 = 0xB7,
		VK_RESERVED_B8 = 0xB8,
		VK_RESERVED_B9 = 0xB9,
		VK_OEM_1 = 0xBA,
		VK_OEM_PLUS = 0xBB,
		VK_OEM_COMMA = 0xBC,
		VK_OEM_MINUS = 0xBD,
		VK_OEM_PERIOD = 0xBE,
		VK_OEM_2 = 0xBF,
		VK_OEM_3 = 0xC0,
		VK_RESERVED_C1 = 0xC1,
		VK_RESERVED_C2 = 0xC2,
		VK_RESERVED_C3 = 0xC3,
		VK_RESERVED_C4 = 0xC4,
		VK_RESERVED_C5 = 0xC5,
		VK_RESERVED_C6 = 0xC6,
		VK_RESERVED_C7 = 0xC7,
		VK_RESERVED_C8 = 0xC8,
		VK_RESERVED_C9 = 0xC9,
		VK_RESERVED_CA = 0xCA,
		VK_RESERVED_CB = 0xCB,
		VK_RESERVED_CC = 0xCC,
		VK_RESERVED_CD = 0xCD,
		VK_RESERVED_CE = 0xCE,
		VK_RESERVED_CF = 0xCF,
		VK_RESERVED_D0 = 0xD0,
		VK_RESERVED_D1 = 0xD1,
		VK_RESERVED_D2 = 0xD2,
		VK_RESERVED_D3 = 0xD3,
		VK_RESERVED_D4 = 0xD4,
		VK_RESERVED_D5 = 0xD5,
		VK_RESERVED_D6 = 0xD6,
		VK_RESERVED_D7 = 0xD7,
		VK_OEM_4 = 0xDB,
		VK_OEM_5 = 0xDC,
		VK_OEM_6 = 0xDD,
		VK_OEM_7 = 0xDE,
		VK_OEM_8 = 0xDF,
		VK_RESERVED_E0 = 0xE0,
		VK_OEMSPECIFIC_E1 = 0xE1,
		VK_OEM_102 = 0xE2,
		VK_OEMSPECIFIC_E3 = 0xE3,
		VK_OEMSPECIFIC_E4 = 0xE4,
		VK_PROCESSKEY = 0xE5,
		VK_OEMSPECIFIC_E6 = 0xE6,
		VK_PACKET = 0xE7,
		VK_OEMSPECIFIC_E9 = 0xE9,
		VK_OEMSPECIFIC_EA = 0xEA,
		VK_OEMSPECIFIC_EB = 0xEB,
		VK_OEMSPECIFIC_EC = 0xEC,
		VK_OEMSPECIFIC_ED = 0xED,
		VK_OEMSPECIFIC_EE = 0xEE,
		VK_OEMSPECIFIC_EF = 0xEF,
		VK_OEMSPECIFIC_F0 = 0xF0,
		VK_OEMSPECIFIC_F1 = 0xF1,
		VK_OEMSPECIFIC_F2 = 0xF2,
		VK_OEMSPECIFIC_F3 = 0xF3,
		VK_OEMSPECIFIC_F4 = 0xF4,
		VK_OEMSPECIFIC_F5 = 0xF5,
		VK_ATTN = 0xF6,
		VK_CRSEL = 0xF7,
		VK_EXSEL = 0xF8,
		VK_EREOF = 0xF9,
		VK_PLAY = 0xFA,
		VK_ZOOM = 0xFB,
		VK_NONAME = 0xFC,
		VK_PA1 = 0xFD,
		VK_OEM_CLEAR = 0xFE,
		VK_RESERVED_FF = 0xFF
	};

	[[nodiscard]] bool FindClose(void* a_findFile) noexcept;

	[[nodiscard]] void* FindFirstFile(const char* a_fileName, WIN32_FIND_DATAA* a_findFileData) noexcept;

	[[nodiscard]] void* FindFirstFile(const wchar_t* a_fileName, WIN32_FIND_DATAW* a_findFileData) noexcept;

	[[nodiscard]] bool FindNextFile(void* a_findFile, WIN32_FIND_DATAA* a_findFileData) noexcept;

	[[nodiscard]] bool FindNextFile(void* a_findFile, WIN32_FIND_DATAW* a_findFileData) noexcept;

	bool FreeLibrary(HMODULE a_module) noexcept;

	[[nodiscard]] void* GetCurrentModule() noexcept;

	[[nodiscard]] void* GetCurrentProcess() noexcept;

	[[nodiscard]] std::uint32_t GetCurrentThreadID() noexcept;

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(const char* a_name, char* a_buffer, std::uint32_t a_size) noexcept;

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(const wchar_t* a_name, wchar_t* a_buffer, std::uint32_t a_size) noexcept;

	[[nodiscard]] bool GetFileVersionInfo(const char* a_filename, std::uint32_t a_handle, std::uint32_t a_len, void* a_data) noexcept;

	[[nodiscard]] bool GetFileVersionInfo(const wchar_t* a_filename, std::uint32_t a_handle, std::uint32_t a_len, void* a_data) noexcept;

	[[nodiscard]] std::uint32_t GetFileVersionInfoSize(const char* a_filename, std::uint32_t* a_handle) noexcept;

	[[nodiscard]] std::uint32_t GetFileVersionInfoSize(const wchar_t* a_filename, std::uint32_t* a_handle) noexcept;

	[[nodiscard]] int GetKeyNameText(std::int32_t a_lParam, char* a_buffer, int a_size) noexcept;

	[[nodiscard]] int GetKeyNameText(std::int32_t a_lParam, wchar_t* a_buffer, int a_size) noexcept;

	[[nodiscard]] std::int16_t GetKeyState(int nVirtKey) noexcept;

	[[nodiscard]] std::size_t GetMaxPath() noexcept;

	[[nodiscard]] std::uint32_t GetModuleFileName(void* a_module, char* a_filename, std::uint32_t a_size) noexcept;

	[[nodiscard]] std::uint32_t GetModuleFileName(void* a_module, wchar_t* a_filename, std::uint32_t a_size) noexcept;

	[[nodiscard]] HMODULE GetModuleHandle(const char* a_moduleName) noexcept;

	[[nodiscard]] HMODULE GetModuleHandle(const wchar_t* a_moduleName) noexcept;

	[[nodiscard]] std::uint32_t GetPrivateProfileString(const char* a_appName, const char* a_keyName, const char* a_default, char* a_outString,
		std::uint32_t a_size, const char* a_fileName) noexcept;

	[[nodiscard]] std::uint32_t GetPrivateProfileString(const wchar_t* a_appName, const wchar_t* a_keyName, const wchar_t* a_default,
		wchar_t* a_outString, std::uint32_t a_size, const wchar_t* a_fileName) noexcept;

	[[nodiscard]] void* GetProcAddress(void* a_module, const char* a_procName) noexcept;

	[[nodiscard]] std::string_view GetProcPath(HMODULE a_handle = 0) noexcept;

	[[nodiscard]] bool IsDebuggerPresent() noexcept;

	[[nodiscard]] HMODULE LoadLibrary(const char* a_libFileName) noexcept;

	[[nodiscard]] HMODULE LoadLibrary(const wchar_t* a_libFileName) noexcept;

	std::int32_t MessageBox(void* a_wnd, const char* a_text, const char* a_caption, unsigned int a_type) noexcept;

	std::int32_t MessageBox(void* a_wnd, const wchar_t* a_text, const wchar_t* a_caption, unsigned int a_type) noexcept;

	[[nodiscard]] int MultiByteToWideChar(unsigned int a_codePage, std::uint32_t a_flags, const char* a_multiByteStr, int a_multiByte,
		wchar_t* a_wideCharStr, int a_wideChar);

	void OutputDebugString(const char* a_outputString) noexcept;

	void OutputDebugString(const wchar_t* a_outputString) noexcept;

	long RegGetValueW(HKEY hkey, const char* subKey, const char* value, unsigned long flags, unsigned long* type, void* data, unsigned long* length);

	long RegGetValueW(HKEY hkey, const wchar_t* subKey, const wchar_t* value, unsigned long flags, unsigned long* type, void* data,
		unsigned long* length);

	[[nodiscard]] int ShowCursor(bool bShow) noexcept;

	[[noreturn]] void TerminateProcess(void* a_process, unsigned int a_exitCode) noexcept;

	[[nodiscard]] void* TlsGetValue(std::uint32_t a_tlsIndex) noexcept;

	bool TlsSetValue(std::uint32_t a_tlsIndex, void* a_tlsValue) noexcept;

	bool VirtualFree(void* a_address, std::size_t a_size, std::uint32_t a_freeType) noexcept;

	[[nodiscard]] bool VerQueryValue(const void* a_block, const char* a_subBlock, void** a_buffer, unsigned int* a_len) noexcept;

	[[nodiscard]] bool VerQueryValue(const void* a_block, const wchar_t* a_subBlock, void** a_buffer, unsigned int* a_len) noexcept;

	[[nodiscard]] bool VirtualProtect(void* a_address, std::size_t a_size, std::uint32_t a_newProtect, std::uint32_t* a_oldProtect) noexcept;

	[[nodiscard]] int WideCharToMultiByte(unsigned int a_codePage, std::uint32_t a_flags, const wchar_t* a_wideCharStr, int a_wideChar,
		char* a_multiByteStr, int a_multiByte, const char* a_defaultChar, int* a_usedDefaultChar);
}  // namespace SFSE::WinAPI

namespace RE::DirectX
{
	struct XMFLOAT4X4
	{
	public:
		// members
		float m[4][4];
	};

	static_assert(sizeof(XMFLOAT4X4) == 0x40);
}  // namespace RE::DirectX

#define CP_UTF8 ::SFSE::WinAPI::CP_UTF8
#define IMAGE_SCN_MEM_EXECUTE ::SFSE::WinAPI::IMAGE_SCN_MEM_EXECUTE
#define IMAGE_SCN_MEM_WRITE ::SFSE::WinAPI::IMAGE_SCN_MEM_WRITE
#define INVALID_HANDLE_VALUE ::SFSE::WinAPI::INVALID_HANDLE_VALUE
#define MAX_PATH ::SFSE::WinAPI::MAX_PATH
#define MEM_COMMIT ::SFSE::WinAPI::MEM_COMMIT
#define MEM_RESERVE ::SFSE::WinAPI::MEM_RESERVE
#define MEM_RELEASE ::SFSE::WinAPI::MEM_RELEASE
#define PAGE_EXECUTE_READWRITE ::SFSE::WinAPI::PAGE_EXECUTE_READWRITE

#define GetEnvironmentVariable ::SFSE::WinAPI::GetEnvironmentVariable
#define GetFileVersionInfoSize ::SFSE::WinAPI::GetFileVersionInfoSize
#define GetModuleFileName ::SFSE::WinAPI::GetModuleFileName
#define VerQueryValue ::SFSE::WinAPI::VerQueryValue
#define GetFileVersionInfo ::SFSE::WinAPI::GetFileVersionInfo
#define GetModuleHandle ::SFSE::WinAPI::GetModuleHandle
#define LoadLibrary ::SFSE::WinAPI::LoadLibrary
#define MessageBox ::SFSE::WinAPI::MessageBox
#define OutputDebugString ::SFSE::WinAPI::OutputDebugString
