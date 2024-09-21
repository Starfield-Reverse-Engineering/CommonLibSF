#pragma once

#include "REX/W32/WS2_32.h"

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
	void        Net_SockadrToNetadr(REX::W32::sockaddr* a_socket, netadr_t* a_addr);  // They violated the naming convention here :(
	bool        NET_WaitForData(std::uintptr_t a_socket, std::uint32_t a_timeoutMs);
	void        Sys_InitNetworking();

	class idTCP
	{
	public:
		SF_RTTI_VTABLE(idTCP);

		virtual ~idTCP();  // 00

		bool         Listen(std::uint16_t a_port, bool a_blocking);  // 'blocking' is ignored
		bool         Accept(const idTCP& a_listener);
		std::int32_t Close();
		std::int32_t Read(void* a_buffer, std::uint32_t a_size);
		std::int32_t Write(const void* a_buffer, std::uint32_t a_size, std::uint32_t a_timeoutMs);

		// members
		netadr_t       address;  // 08
		std::uintptr_t socket;   // 18
	};
	static_assert(sizeof(idTCP) == 0x20);
}
