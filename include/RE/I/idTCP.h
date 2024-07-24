#pragma once

namespace RE
{
	enum class netadrtype_t
	{
		NA_BAD,  // an address lookup failed
		NA_LOOPBACK,
		NA_BROADCAST,
		NA_IP
	};

	struct netadr_t
	{
		netadrtype_t  type;   // 00
		std::byte     ip[4];  // 04
		std::uint32_t port;   // 08
	};
	static_assert(sizeof(netadr_t) == 0xC);

	const char* NET_ErrorString(void);
	void        Net_SockadrToNetadr(WinAPI::sockaddr* s, netadr_t* a);  // They violated the naming convention here :(
	bool        NET_WaitForData(std::uintptr_t socket, std::uint32_t timeoutMs);
	void        Sys_InitNetworking();

	class idTCP
	{
	public:
		SF_RTTI_VTABLE(idTCP);

		virtual ~idTCP();  // 00

		bool         Listen(std::uint16_t port, bool blocking);  // 'blocking' is ignored
		bool         Accept(const idTCP& listener);
		std::int32_t Close();
		std::int32_t Read(void* buffer, std::uint32_t size);
		std::int32_t Write(const void* buffer, std::uint32_t size, std::uint32_t timeoutMs);

		// members
		netadr_t       address;  // 08
		std::uintptr_t socket;   // 18
	};
	static_assert(sizeof(idTCP) == 0x20);

}
