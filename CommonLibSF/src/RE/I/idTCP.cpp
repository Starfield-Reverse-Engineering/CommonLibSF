#include "RE/I/idTCP.h"

namespace RE
{
	const char* NET_ErrorString()
	{
		using WSAError = WinAPI::WSAError;

		const auto code = static_cast<WSAError>(WinAPI::WSAGetLastError());
		switch (code) {
		case WSAError::WSAEINTR:
			return "WSAEINTR";
		case WSAError::WSAEBADF:
			return "WSAEBADF";
		case WSAError::WSAEACCES:
			return "WSAEACCES";
		case WSAError::WSAEDISCON:
			return "WSAEDISCON";
		case WSAError::WSAEFAULT:
			return "WSAEFAULT";
		case WSAError::WSAEINVAL:
			return "WSAEINVAL";
		case WSAError::WSAEMFILE:
			return "WSAEMFILE";
		case WSAError::WSAEWOULDBLOCK:
			return "WSAEWOULDBLOCK";
		case WSAError::WSAEINPROGRESS:
			return "WSAEINPROGRESS";
		case WSAError::WSAEALREADY:
			return "WSAEALREADY";
		case WSAError::WSAENOTSOCK:
			return "WSAENOTSOCK";
		case WSAError::WSAEDESTADDRREQ:
			return "WSAEDESTADDRREQ";
		case WSAError::WSAEMSGSIZE:
			return "WSAEMSGSIZE";
		case WSAError::WSAEPROTOTYPE:
			return "WSAEPROTOTYPE";
		case WSAError::WSAENOPROTOOPT:
			return "WSAENOPROTOOPT";
		case WSAError::WSAEPROTONOSUPPORT:
			return "WSAEPROTONOSUPPORT";
		case WSAError::WSAESOCKTNOSUPPORT:
			return "WSAESOCKTNOSUPPORT";
		case WSAError::WSAEOPNOTSUPP:
			return "WSAEOPNOTSUPP";
		case WSAError::WSAEPFNOSUPPORT:
			return "WSAEPFNOSUPPORT";
		case WSAError::WSAEAFNOSUPPORT:
			return "WSAEAFNOSUPPORT";
		case WSAError::WSAEADDRINUSE:
			return "WSAEADDRINUSE";
		case WSAError::WSAEADDRNOTAVAIL:
			return "WSAEADDRNOTAVAIL";
		case WSAError::WSAENETDOWN:
			return "WSAENETDOWN";
		case WSAError::WSAENETUNREACH:
			return "WSAENETUNREACH";
		case WSAError::WSAENETRESET:
			return "WSAENETRESET";
		case WSAError::WSAECONNABORTED:
			return "WSWSAECONNABORTEDAEINTR";
		case WSAError::WSAECONNRESET:
			return "WSAECONNRESET";
		case WSAError::WSAENOBUFS:
			return "WSAENOBUFS";
		case WSAError::WSAEISCONN:
			return "WSAEISCONN";
		case WSAError::WSAENOTCONN:
			return "WSAENOTCONN";
		case WSAError::WSAESHUTDOWN:
			return "WSAESHUTDOWN";
		case WSAError::WSAETOOMANYREFS:
			return "WSAETOOMANYREFS";
		case WSAError::WSAETIMEDOUT:
			return "WSAETIMEDOUT";
		case WSAError::WSAECONNREFUSED:
			return "WSAECONNREFUSED";
		case WSAError::WSAELOOP:
			return "WSAELOOP";
		case WSAError::WSAENAMETOOLONG:
			return "WSAENAMETOOLONG";
		case WSAError::WSAEHOSTDOWN:
			return "WSAEHOSTDOWN";
		case WSAError::WSASYSNOTREADY:
			return "WSASYSNOTREADY";
		case WSAError::WSAVERNOTSUPPORTED:
			return "WSAVERNOTSUPPORTED";
		case WSAError::WSANOTINITIALISED:
			return "WSANOTINITIALISED";
		case WSAError::WSAHOST_NOT_FOUND:
			return "WSAHOST_NOT_FOUND";
		case WSAError::WSATRY_AGAIN:
			return "WSATRY_AGAIN";
		case WSAError::WSANO_RECOVERY:
			return "WSANO_RECOVERY";
		case WSAError::WSANO_DATA:
			return "WSANO_DATA";
		default:
			return "NO ERROR";
		}
	}

	void Net_SockadrToNetadr(WinAPI::sockaddr* s, netadr_t* a)
	{
		using AFType = WinAPI::AFType;
		using sockaddr_in = WinAPI::sockaddr_in;

		if (s->sa_family == AFType::AF_INET) {
			const auto sin = reinterpret_cast<sockaddr_in*>(s);
			auto ip = sin->sin_addr.s_addr;
			*reinterpret_cast<unsigned int*>(&a->ip) = ip;
			a->port = WinAPI::htons(sin->sin_port);
			ip = WinAPI::ntohl(ip);

			if (ip == WinAPI::INADDR_LOOPBACK) {
				a->type = netadrtype_t::NA_LOOPBACK;
			} else {
				a->type = netadrtype_t::NA_IP;
			}
		}
	}

	bool NET_WaitForData(std::uintptr_t socket, std::uint32_t timeoutMs)
	{
		using func_t = decltype(&NET_WaitForData);
		REL::Relocation<func_t> func{ ID::NET_WaitForData };
		return func(socket, timeoutMs);
	}

	void Sys_InitNetworking()
	{
		using func_t = decltype(&Sys_InitNetworking);
		REL::Relocation<func_t> func{ ID::Sys_InitNetworking };
		return func();
	}

	bool idTCP::Listen(std::uint16_t port, bool blocking)
	{
		using func_t = decltype(&idTCP::Listen);
		REL::Relocation<func_t> func{ ID::idTCP::Listen };
		return func(this, port, blocking);
	}

	bool idTCP::Accept(const idTCP& listener)
	{
		using func_t = decltype(&idTCP::Accept);
		REL::Relocation<func_t> func{ ID::idTCP::Accept };
		return func(this, listener);
	}

	std::int32_t idTCP::Close()
	{
		using func_t = decltype(&idTCP::Close);
		REL::Relocation<func_t> func{ ID::idTCP::Close };
		return func(this);
	}

	std::int32_t idTCP::Read(void* buffer, std::uint32_t size)
	{
		using func_t = decltype(&idTCP::Read);
		REL::Relocation<func_t> func{ ID::idTCP::Read };
		return func(this, buffer, size);
	}

	std::int32_t idTCP::Write(const void* buffer, std::uint32_t size, std::uint32_t timeoutMs)
	{
		using func_t = decltype(&idTCP::Write);
		REL::Relocation<func_t> func{ ID::idTCP::Write };
		return func(this, buffer, size, timeoutMs);
	}
}
