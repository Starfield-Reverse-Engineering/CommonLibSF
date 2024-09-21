#pragma once

#include "REX/W32/BASE.h"

namespace REX::W32
{
	// winsock2 values
	inline constexpr auto INADDR_ANY{ 0x00000000u };
	inline constexpr auto INADDR_LOOPBACK{ 0x7f000001u };
	inline constexpr auto INADDR_BROADCAST{ 0xffffffffu };
	inline constexpr auto INADDR_NONE{ 0xffffffffu };
}

namespace REX::W32
{
	enum ADDRESS_FAMILY : std::uint16_t
	{
		AF_UNSPEC = 0,
		AF_UNIX = 1,
		AF_INET = 2,
		AF_IMPLINK = 3,
		AF_PUP = 4,
		AF_CHAOS = 5,
		AF_NS = 6,
		AF_IPX = AF_NS,
		AF_ISO = 7,
		AF_OSI = AF_ISO,
		AF_ECMA = 8,
		AF_DATAKIT = 9,
		AF_CCITT = 10,
		AF_SNA = 11,
		AF_DECnet = 12,
		AF_DLI = 13,
		AF_LAT = 14,
		AF_HYLINK = 15,
		AF_APPLETALK = 16,
		AF_NETBIOS = 17,
		AF_VOICEVIEW = 18,
		AF_FIREFOX = 19,
		AF_UNKNOWN1 = 20,
		AF_BAN = 21,
		AF_ATM = 22,
		AF_INET6 = 23,
		AF_CLUSTER = 24,
		AF_12844 = 25,
		AF_IRDA = 26,
		AF_NETDES = 28,
	};

	enum WSA_ERROR : std::int32_t
	{
		WSABASEERR = 10000L,
		WSAEINTR = 10004L,
		WSAEBADF = 10009L,
		WSAEACCES = 10013L,
		WSAEFAULT = 10014L,
		WSAEINVAL = 10022L,
		WSAEMFILE = 10024L,
		WSAEWOULDBLOCK = 10035L,
		WSAEINPROGRESS = 10036L,
		WSAEALREADY = 10037L,
		WSAENOTSOCK = 10038L,
		WSAEDESTADDRREQ = 10039L,
		WSAEMSGSIZE = 10040L,
		WSAEPROTOTYPE = 10041L,
		WSAENOPROTOOPT = 10042L,
		WSAEPROTONOSUPPORT = 10043L,
		WSAESOCKTNOSUPPORT = 10044L,
		WSAEOPNOTSUPP = 10045L,
		WSAEPFNOSUPPORT = 10046L,
		WSAEAFNOSUPPORT = 10047L,
		WSAEADDRINUSE = 10048L,
		WSAEADDRNOTAVAIL = 10049L,
		WSAENETDOWN = 10050L,
		WSAENETUNREACH = 10051L,
		WSAENETRESET = 10052L,
		WSAECONNABORTED = 10053L,
		WSAECONNRESET = 10054L,
		WSAENOBUFS = 10055L,
		WSAEISCONN = 10056L,
		WSAENOTCONN = 10057L,
		WSAESHUTDOWN = 10058L,
		WSAETOOMANYREFS = 10059L,
		WSAETIMEDOUT = 10060L,
		WSAECONNREFUSED = 10061L,
		WSAELOOP = 10062L,
		WSAENAMETOOLONG = 10063L,
		WSAEHOSTDOWN = 10064L,
		WSAEHOSTUNREACH = 10065L,
		WSAENOTEMPTY = 10066L,
		WSAEPROCLIM = 10067L,
		WSAEUSERS = 10068L,
		WSAEDQUOT = 10069L,
		WSAESTALE = 10070L,
		WSAEREMOTE = 10071L,
		WSASYSNOTREADY = 10091L,
		WSAVERNOTSUPPORTED = 10092L,
		WSANOTINITIALISED = 10093L,
		WSAEDISCON = 10101L,
		WSAENOMORE = 10102L,
		WSAECANCELLED = 10103L,
		WSAEINVALIDPROCTABLE = 10104L,
		WSAEINVALIDPROVIDER = 10105L,
		WSAEPROVIDERFAILEDINIT = 10106L,
		WSASYSCALLFAILURE = 10107L,
		WSASERVICE_NOT_FOUND = 10108L,
		WSATYPE_NOT_FOUND = 10109L,
		WSA_E_NO_MORE = 10110L,
		WSA_E_CANCELLED = 10111L,
		WSAEREFUSED = 10112L,
		WSAHOST_NOT_FOUND = 11001L,
		WSATRY_AGAIN = 11002L,
		WSANO_RECOVERY = 11003L,
		WSANO_DATA = 11004L,
		WSA_QOS_RECEIVERS = 11005L,
		WSA_QOS_SENDERS = 11006L,
		WSA_QOS_NO_SENDERS = 11007L,
		WSA_QOS_NO_RECEIVERS = 11008L,
		WSA_QOS_REQUEST_CONFIRMED = 11009L,
		WSA_QOS_ADMISSION_FAILURE = 11010L,
		WSA_QOS_POLICY_FAILURE = 11011L,
		WSA_QOS_BAD_STYLE = 11012L,
		WSA_QOS_BAD_OBJECT = 11013L,
		WSA_QOS_TRAFFIC_CTRL_ERROR = 11014L,
		WSA_QOS_GENERIC_ERROR = 11015L,
		WSA_QOS_ESERVICETYPE = 11016L,
		WSA_QOS_EFLOWSPEC = 11017L,
		WSA_QOS_EPROVSPECBUF = 11018L,
		WSA_QOS_EFILTERSTYLE = 11019L,
		WSA_QOS_EFILTERTYPE = 11020L,
		WSA_QOS_EFILTERCOUNT = 11021L,
		WSA_QOS_EOBJLENGTH = 11022L,
		WSA_QOS_EFLOWCOUNT = 11023L,
		WSA_QOS_EUNKOWNPSOBJ = 11024L,
		WSA_QOS_EPOLICYOBJ = 11025L,
		WSA_QOS_EFLOWDESC = 11026L,
		WSA_QOS_EPSFLOWSPEC = 11027L,
		WSA_QOS_EPSFILTERSPEC = 11028L,
		WSA_QOS_ESDMODEOBJ = 11029L,
		WSA_QOS_ESHAPERATEOBJ = 11030L,
		WSA_QOS_RESERVED_PETYPE = 11031L,
		WSA_SECURE_HOST_NOT_FOUND = 11032L,
		WSA_IPSEC_NAME_POLICY_ERROR = 11033L,
	};

	using SOCKET = std::uintptr_t;

	struct sockaddr
	{
		ADDRESS_FAMILY sa_family;
		char           sa_data[14];
	};

	// Originally a struct with several #defines that served as aliases to members
	// The defines screwed a lot of things up, so it was made a union.
	// This means it won't have compatibility with code that uses in_addrs directly and
	// also refers to it by its full type identifier (i.e. `struct in_addr`).
	union in_addr
	{
		union in_addr_D
		{
			struct
			{
				std::uint8_t s_b1, s_b2, s_b3, s_b4;
			} S_un_b;

			struct
			{
				std::uint16_t s_w1, s_w2;
			} S_un_w;

			std::uint32_t S_addr;
		} S_un;

		// getting around the #DEFINEs in inaddr.h
		struct
		{
			std::uint8_t s_net;
			std::uint8_t s_host;
			std::uint8_t s_lh;
			std::uint8_t s_impno;
		};

		struct
		{
			std::uint16_t _s_w1, s_imp;
		};

		std::uint32_t s_addr;
	};

	struct sockaddr_in
	{
		ADDRESS_FAMILY sin_family;
		std::uint16_t  sin_port;
		in_addr        sin_addr;
		char           sin_zero[8];
	};
}

namespace REX::W32
{
	std::uint16_t htons(std::uint16_t a_host) noexcept;
	std::uint32_t ntohl(std::uint32_t a_net) noexcept;
	std::int32_t  WSAGetLastError() noexcept;
}
