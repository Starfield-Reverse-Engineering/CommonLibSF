#include "RE/I/idTCP.h"

namespace RE
{
	const char* NET_ErrorString()
	{
		switch (REX::W32::WSAGetLastError()) {
		case REX::W32::WSAEINTR:
			return "WSAEINTR";
		case REX::W32::WSAEBADF:
			return "WSAEBADF";
		case REX::W32::WSAEACCES:
			return "WSAEACCES";
		case REX::W32::WSAEDISCON:
			return "WSAEDISCON";
		case REX::W32::WSAEFAULT:
			return "WSAEFAULT";
		case REX::W32::WSAEINVAL:
			return "WSAEINVAL";
		case REX::W32::WSAEMFILE:
			return "WSAEMFILE";
		case REX::W32::WSAEWOULDBLOCK:
			return "WSAEWOULDBLOCK";
		case REX::W32::WSAEINPROGRESS:
			return "WSAEINPROGRESS";
		case REX::W32::WSAEALREADY:
			return "WSAEALREADY";
		case REX::W32::WSAENOTSOCK:
			return "WSAENOTSOCK";
		case REX::W32::WSAEDESTADDRREQ:
			return "WSAEDESTADDRREQ";
		case REX::W32::WSAEMSGSIZE:
			return "WSAEMSGSIZE";
		case REX::W32::WSAEPROTOTYPE:
			return "WSAEPROTOTYPE";
		case REX::W32::WSAENOPROTOOPT:
			return "WSAENOPROTOOPT";
		case REX::W32::WSAEPROTONOSUPPORT:
			return "WSAEPROTONOSUPPORT";
		case REX::W32::WSAESOCKTNOSUPPORT:
			return "WSAESOCKTNOSUPPORT";
		case REX::W32::WSAEOPNOTSUPP:
			return "WSAEOPNOTSUPP";
		case REX::W32::WSAEPFNOSUPPORT:
			return "WSAEPFNOSUPPORT";
		case REX::W32::WSAEAFNOSUPPORT:
			return "WSAEAFNOSUPPORT";
		case REX::W32::WSAEADDRINUSE:
			return "WSAEADDRINUSE";
		case REX::W32::WSAEADDRNOTAVAIL:
			return "WSAEADDRNOTAVAIL";
		case REX::W32::WSAENETDOWN:
			return "WSAENETDOWN";
		case REX::W32::WSAENETUNREACH:
			return "WSAENETUNREACH";
		case REX::W32::WSAENETRESET:
			return "WSAENETRESET";
		case REX::W32::WSAECONNABORTED:
			return "WSWSAECONNABORTEDAEINTR";
		case REX::W32::WSAECONNRESET:
			return "WSAECONNRESET";
		case REX::W32::WSAENOBUFS:
			return "WSAENOBUFS";
		case REX::W32::WSAEISCONN:
			return "WSAEISCONN";
		case REX::W32::WSAENOTCONN:
			return "WSAENOTCONN";
		case REX::W32::WSAESHUTDOWN:
			return "WSAESHUTDOWN";
		case REX::W32::WSAETOOMANYREFS:
			return "WSAETOOMANYREFS";
		case REX::W32::WSAETIMEDOUT:
			return "WSAETIMEDOUT";
		case REX::W32::WSAECONNREFUSED:
			return "WSAECONNREFUSED";
		case REX::W32::WSAELOOP:
			return "WSAELOOP";
		case REX::W32::WSAENAMETOOLONG:
			return "WSAENAMETOOLONG";
		case REX::W32::WSAEHOSTDOWN:
			return "WSAEHOSTDOWN";
		case REX::W32::WSASYSNOTREADY:
			return "WSASYSNOTREADY";
		case REX::W32::WSAVERNOTSUPPORTED:
			return "WSAVERNOTSUPPORTED";
		case REX::W32::WSANOTINITIALISED:
			return "WSANOTINITIALISED";
		case REX::W32::WSAHOST_NOT_FOUND:
			return "WSAHOST_NOT_FOUND";
		case REX::W32::WSATRY_AGAIN:
			return "WSATRY_AGAIN";
		case REX::W32::WSANO_RECOVERY:
			return "WSANO_RECOVERY";
		case REX::W32::WSANO_DATA:
			return "WSANO_DATA";
		default:
			return "NO ERROR";
		}
	}

	void Net_SockadrToNetadr(REX::W32::sockaddr* a_saddr, netadr_t* a_naddr)
	{
		if (a_saddr->sa_family == REX::W32::AF_INET) {
			const auto sin = reinterpret_cast<REX::W32::sockaddr_in*>(a_saddr);
			auto       ip = sin->sin_addr.s_addr;
			*reinterpret_cast<unsigned int*>(&a_naddr->ip) = ip;
			a_naddr->port = REX::W32::htons(sin->sin_port);
			ip = REX::W32::ntohl(ip);

			if (ip == REX::W32::INADDR_LOOPBACK) {
				a_naddr->type = netadrtype_t::NA_LOOPBACK;
			} else {
				a_naddr->type = netadrtype_t::NA_IP;
			}
		}
	}

	bool NET_WaitForData(std::uintptr_t socket, std::uint32_t timeoutMs)
	{
		using func_t = decltype(&NET_WaitForData);
		static REL::Relocation<func_t> func{ ID::NET_WaitForData };
		return func(socket, timeoutMs);
	}

	void Sys_InitNetworking()
	{
		using func_t = decltype(&Sys_InitNetworking);
		static REL::Relocation<func_t> func{ ID::Sys_InitNetworking };
		return func();
	}

	bool idTCP::Listen(std::uint16_t port, bool blocking)
	{
		using func_t = decltype(&idTCP::Listen);
		static REL::Relocation<func_t> func{ ID::idTCP::Listen };
		return func(this, port, blocking);
	}

	bool idTCP::Accept(const idTCP& listener)
	{
		using func_t = decltype(&idTCP::Accept);
		static REL::Relocation<func_t> func{ ID::idTCP::Accept };
		return func(this, listener);
	}

	std::int32_t idTCP::Close()
	{
		using func_t = decltype(&idTCP::Close);
		static REL::Relocation<func_t> func{ ID::idTCP::Close };
		return func(this);
	}

	std::int32_t idTCP::Read(void* buffer, std::uint32_t size)
	{
		using func_t = decltype(&idTCP::Read);
		static REL::Relocation<func_t> func{ ID::idTCP::Read };
		return func(this, buffer, size);
	}

	std::int32_t idTCP::Write(const void* buffer, std::uint32_t size, std::uint32_t timeoutMs)
	{
		using func_t = decltype(&idTCP::Write);
		static REL::Relocation<func_t> func{ ID::idTCP::Write };
		return func(this, buffer, size, timeoutMs);
	}
}
