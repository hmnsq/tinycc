/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WS2TCPIP_H
#define _WS2TCPIP_H

#ಯದಿ __GNUC__ >=3
#pragma GCC system_header
#endif

#ಅನ್ತರ್ಭಾವ <ws2ipdef.h>

ಸಂರಚನಾ ip_msfilter {
  ಸಂರಚನಾ in_addr imsf_multiaddr;
  ಸಂರಚನಾ in_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  ಸಂರಚನಾ in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) (ಪರಿಮಾಣ(ಸಂರಚನಾ ip_msfilter)-ಪರಿಮಾಣ(ಸಂರಚನಾ in_addr) + (numsrc)*ಪರಿಮಾಣ(ಸಂರಚನಾ in_addr))

#define MCAST_INCLUDE 0
#define MCAST_EXCLUDE 1

#define SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#define SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#define SIO_SET_MULTICAST_FILTER _IOW('t',125,u_long)
#define SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_IN,u_long)

#define IP_OPTIONS 1
#define IP_HDRINCL 2
#define IP_TOS 3
#define IP_TTL 4
#define IP_MULTICAST_IF 9
#define IP_MULTICAST_TTL 10
#define IP_MULTICAST_LOOP 11
#define IP_ADD_MEMBERSHIP 12
#define IP_DROP_MEMBERSHIP 13
#define IP_DONTFRAGMENT 14
#define IP_ADD_SOURCE_MEMBERSHIP 15
#define IP_DROP_SOURCE_MEMBERSHIP 16
#define IP_BLOCK_SOURCE 17
#define IP_UNBLOCK_SOURCE 18
#define IP_PKTINFO 19
#define IP_RECEIVE_BROADCAST 22

#define IPV6_HDRINCL 2
#define IPV6_UNICAST_HOPS 4
#define IPV6_MULTICAST_IF 9
#define IPV6_MULTICAST_HOPS 10
#define IPV6_MULTICAST_LOOP 11
#define IPV6_ADD_MEMBERSHIP 12
#define IPV6_DROP_MEMBERSHIP 13
#define IPV6_JOIN_GROUP IPV6_ADD_MEMBERSHIP
#define IPV6_LEAVE_GROUP IPV6_DROP_MEMBERSHIP
#define IPV6_PKTINFO 19
#define IPV6_HOPLIMIT 21
#define IPV6_PROTECTION_LEVEL 23

#define PROTECTION_LEVEL_UNRESTRICTED 10
#define PROTECTION_LEVEL_DEFAULT 20
#define PROTECTION_LEVEL_RESTRICTED 30

#define UDP_NOCHECKSUM 1
#define UDP_CHECKSUM_COVERAGE 20

#define TCP_EXPEDITED_1122 0x0002

#ifndef s6_addr

ಸಂರಚನಾ in6_addr {
  __MINGW_EXTENSION ಸಙ್ಘ {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#define in_addr6 in6_addr

#define _S6_un u
#define _S6_u8 Byte
#define s6_addr _S6_un._S6_u8

#define s6_bytes u.Byte
#define s6_ಪದಗಳು u.Word
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ ipv6_mreq {
  ಸಂರಚನಾ in6_addr ipv6mr_multiaddr;
  unsigned ಪೂರ್ಣಾಙ್ಕ ipv6mr_interface;
} IPV6_MREQ;

ಸಂರಚನಾ sockaddr_in6_old {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  ಸಂರಚನಾ in6_addr sin6_addr;
};

ಸಂರಚನಾ sockaddr_in6 {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  ಸಂರಚನಾ in6_addr sin6_addr;
  u_long sin6_scope_id;
};

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ in6_addr IN6_ADDR;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ in6_addr *PIN6_ADDR;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ in6_addr *LPIN6_ADDR;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ sockaddr_in6 SOCKADDR_IN6;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ sockaddr_in6 *PSOCKADDR_IN6;
ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ sockaddr_in6 *LPSOCKADDR_IN6;

#define SS_PORT(ssp) (((ಸಂರಚನಾ sockaddr_in*)(ssp))->sin_port)

#define IN6ADDR_ANY_INIT { 0 }
#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

  ಬಾಹ್ಯ ಧ್ರುವ ಸಂರಚನಾ in6_addr in6addr_any;
  ಬಾಹ್ಯ ಧ್ರುವ ಸಂರಚನಾ in6_addr in6addr_loopback;

#ifdef __cplusplus
}
#endif

#define WS2TCPIP_INLINE __CRT_INLINE

ಪೂರ್ಣಾಙ್ಕ IN6_ADDR_EQUAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *,ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_UNSPECIFIED(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_LOOPBACK(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MULTICAST(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_LINKLOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_SITELOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_V4MAPPED(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_V4COMPAT(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_NODELOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_LINKLOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_SITELOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_ORGLOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_GLOBAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *);
ಪೂರ್ಣಾಙ್ಕ IN6ADDR_ISANY(ಧ್ರುವ ಸಂರಚನಾ sockaddr_in6 *);
ಪೂರ್ಣಾಙ್ಕ IN6ADDR_ISLOOPBACK(ಧ್ರುವ ಸಂರಚನಾ sockaddr_in6 *);
ಶೂನ್ಯ IN6_SET_ADDR_UNSPECIFIED(ಸಂರಚನಾ in6_addr *);
ಶೂನ್ಯ IN6_SET_ADDR_LOOPBACK(ಸಂರಚನಾ in6_addr *);
ಶೂನ್ಯ IN6ADDR_SETANY(ಸಂರಚನಾ sockaddr_in6 *);
ಶೂನ್ಯ IN6ADDR_SETLOOPBACK(ಸಂರಚನಾ sockaddr_in6 *);

#ifndef __CRT__NO_INLINE
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_ADDR_EQUAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a,ಧ್ರುವ ಸಂರಚನಾ in6_addr *b) { ಪ್ರತ್ಯಾಗಮ (memcmp(a,b,ಪರಿಮಾಣ(ಸಂರಚನಾ in6_addr))==0); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_UNSPECIFIED(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ ((a->s6_ಪದಗಳು[0]==0) && (a->s6_ಪದಗಳು[1]==0) && (a->s6_ಪದಗಳು[2]==0) && (a->s6_ಪದಗಳು[3]==0) && (a->s6_ಪದಗಳು[4]==0) && (a->s6_ಪದಗಳು[5]==0) && (a->s6_ಪದಗಳು[6]==0) && (a->s6_ಪದಗಳು[7]==0)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_LOOPBACK(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ ((a->s6_ಪದಗಳು[0]==0) && (a->s6_ಪದಗಳು[1]==0) && (a->s6_ಪದಗಳು[2]==0) && (a->s6_ಪದಗಳು[3]==0) && (a->s6_ಪದಗಳು[4]==0) && (a->s6_ಪದಗಳು[5]==0) && (a->s6_ಪದಗಳು[6]==0) && (a->s6_ಪದಗಳು[7]==0x0100)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MULTICAST(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ (a->s6_bytes[0]==0xff); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_LINKLOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_SITELOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_V4MAPPED(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ ((a->s6_ಪದಗಳು[0]==0) && (a->s6_ಪದಗಳು[1]==0) && (a->s6_ಪದಗಳು[2]==0) && (a->s6_ಪದಗಳು[3]==0) && (a->s6_ಪದಗಳು[4]==0) && (a->s6_ಪದಗಳು[5]==0xffff)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_V4COMPAT(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ ((a->s6_ಪದಗಳು[0]==0) && (a->s6_ಪದಗಳು[1]==0) && (a->s6_ಪದಗಳು[2]==0) && (a->s6_ಪದಗಳು[3]==0) && (a->s6_ಪದಗಳು[4]==0) && (a->s6_ಪದಗಳು[5]==0) && !((a->s6_ಪದಗಳು[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_NODELOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_LINKLOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_SITELOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_ORGLOCAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6_IS_ADDR_MC_GLOBAL(ಧ್ರುವ ಸಂರಚನಾ in6_addr *a) { ಪ್ರತ್ಯಾಗಮ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6ADDR_ISANY(ಧ್ರುವ ಸಂರಚನಾ sockaddr_in6 *a) { ಪ್ರತ್ಯಾಗಮ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಙ್ಕ IN6ADDR_ISLOOPBACK(ಧ್ರುವ ಸಂರಚನಾ sockaddr_in6 *a) { ಪ್ರತ್ಯಾಗಮ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE ಶೂನ್ಯ IN6_SET_ADDR_UNSPECIFIED(ಸಂರಚನಾ in6_addr *a) { memset(a->s6_bytes,0,ಪರಿಮಾಣ(ಸಂರಚನಾ in6_addr)); }
WS2TCPIP_INLINE ಶೂನ್ಯ IN6_SET_ADDR_LOOPBACK(ಸಂರಚನಾ in6_addr *a) {
  memset(a->s6_bytes,0,ಪರಿಮಾಣ(ಸಂರಚನಾ in6_addr));
  a->s6_bytes[15] = 1;
}
WS2TCPIP_INLINE ಶೂನ್ಯ IN6ADDR_SETANY(ಸಂರಚನಾ sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE ಶೂನ್ಯ IN6ADDR_SETLOOPBACK(ಸಂರಚನಾ sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#endif /* !__CRT__NO_INLINE */

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಙ್ಘ sockaddr_gen {
  ಸಂರಚನಾ sockaddr Address;
  ಸಂರಚನಾ sockaddr_in AddressIn;
  ಸಂರಚನಾ sockaddr_in6_old AddressIn6;
} sockaddr_gen;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_ADDRESS iiAddress;
  SOCKET_ADDRESS iiBroadcastAddress;
  SOCKET_ADDRESS iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#define IFF_UP 0x00000001
#define IFF_BROADCAST 0x00000002
#define IFF_LOOPBACK 0x00000004
#define IFF_POINTTOPOINT 0x00000008
#define IFF_MULTICAST 0x00000010

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ in_pktinfo {
  IN_ADDR ipi_addr;
  UINT ipi_ifindex;
} IN_PKTINFO;

C_ASSERT(ಪರಿಮಾಣ(IN_PKTINFO)==8);

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(ಪರಿಮಾಣ(IN6_PKTINFO)==20);

#define EAI_AGAIN WSATRY_AGAIN
#define EAI_BADFLAGS WSAEINVAL
#define EAI_FAIL WSANO_RECOVERY
#define EAI_FAMILY WSAEAFNOSUPPORT
#define EAI_MEMORY WSA_NOT_ENOUGH_MEMORY

#define EAI_NONAME WSAHOST_NOT_FOUND
#define EAI_SERVICE WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#define EAI_NODATA EAI_NONAME

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ addrinfo {
  ಪೂರ್ಣಾಙ್ಕ ai_flags;
  ಪೂರ್ಣಾಙ್ಕ ai_family;
  ಪೂರ್ಣಾಙ್ಕ ai_socktype;
  ಪೂರ್ಣಾಙ್ಕ ai_protocol;
  size_t ai_addrlen;
  ವರ್ಣ *ai_canonname;
  ಸಂರಚನಾ sockaddr *ai_addr;
  ಸಂರಚನಾ addrinfo *ai_next;
} ADDRINFOA,*PADDRINFOA;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ addrinfoW {
  ಪೂರ್ಣಾಙ್ಕ ai_flags;
  ಪೂರ್ಣಾಙ್ಕ ai_family;
  ಪೂರ್ಣಾಙ್ಕ ai_socktype;
  ಪೂರ್ಣಾಙ್ಕ ai_protocol;
  size_t ai_addrlen;
  PWSTR ai_canonname;
  ಸಂರಚನಾ sockaddr *ai_addr;
  ಸಂರಚನಾ addrinfoW *ai_next;
} ADDRINFOW,*PADDRINFOW;

#ifdef UNICODE
ಪ್ರಕಾರನಿರ್ದೇಶ ADDRINFOW ADDRINFOT,*PADDRINFOT;
#ಅನ್ಯಥಾ
ಪ್ರಕಾರನಿರ್ದೇಶ ADDRINFOA ADDRINFOT,*PADDRINFOT;
#endif

ಪ್ರಕಾರನಿರ್ದೇಶ ADDRINFOA ADDRINFO,*LPADDRINFO;

#define AI_PASSIVE 0x1
#define AI_CANONNAME 0x2
#define AI_NUMERICHOST 0x4

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifdef UNICODE
#define GetAddrInfo GetAddrInfoW
#ಅನ್ಯಥಾ
#define GetAddrInfo GetAddrInfoA
#endif

  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಙ್ಕ WSAAPI getaddrinfo(ಧ್ರುವ ವರ್ಣ *nodename,ಧ್ರುವ ವರ್ಣ *servname,ಧ್ರುವ ಸಂರಚನಾ addrinfo *hints,ಸಂರಚನಾ addrinfo **res);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಙ್ಕ WSAAPI GetAddrInfoW(PCWSTR p_ಗಂಟು_Name,PCWSTR pServiceName,ಧ್ರುವ ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define GetAddrInfoA getaddrinfo

#ಯದಿ INCL_WINSOCK_API_TYPEDEFS
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (WSAAPI *LPFN_GETADDRINFO)(ಧ್ರುವ ವರ್ಣ *nodename,ಧ್ರುವ ವರ್ಣ *servname,ಧ್ರುವ ಸಂರಚನಾ addrinfo *hints,ಸಂರಚನಾ addrinfo **res);
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_ಗಂಟು_Name,PCWSTR pServiceName,ಧ್ರುವ ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ifdef UNICODE
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#ಅನ್ಯಥಾ
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#endif
#endif

#ifdef UNICODE
#define FreeAddrInfo FreeAddrInfoW
#ಅನ್ಯಥಾ
#define FreeAddrInfo FreeAddrInfoA
#endif

  WINSOCK_API_LINKAGE ಶೂನ್ಯ WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE ಶೂನ್ಯ WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#define FreeAddrInfoA freeaddrinfo

#ಯದಿ INCL_WINSOCK_API_TYPEDEFS
  ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (WSAAPI *LPFN_FREEADDRINFO)(ಸಂರಚನಾ addrinfo *ai);
  ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ifdef UNICODE
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#ಅನ್ಯಥಾ
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#endif
#endif

#pragma ತಳ್ಳು_macro("socklen_t")
#undef socklen_t

  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ socklen_t;

#ifdef UNICODE
#define GetNameInfo GetNameInfoW
#ಅನ್ಯಥಾ
#define GetNameInfo GetNameInfoA
#endif

  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಙ್ಕ WSAAPI getnameinfo(ಧ್ರುವ ಸಂರಚನಾ sockaddr *sa,socklen_t salen,ವರ್ಣ *host,DWORD hostlen,ವರ್ಣ *serv,DWORD servlen,ಪೂರ್ಣಾಙ್ಕ flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ಧ್ರುವ SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_ಗಂಟು_Buffer,DWORD ಗಂಟು_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define GetNameInfoA getnameinfo

#ಯದಿ INCL_WINSOCK_API_TYPEDEFS
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (WSAAPI *LPFN_GETNAMEINFO)(ಧ್ರುವ ಸಂರಚನಾ sockaddr *sa,socklen_t salen,ವರ್ಣ *host,DWORD hostlen,ವರ್ಣ *serv,DWORD servlen,ಪೂರ್ಣಾಙ್ಕ flags);
  ಪ್ರಕಾರನಿರ್ದೇಶ INT (WSAAPI *LPFN_GETNAMEINFOW)(ಧ್ರುವ SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_ಗಂಟು_Buffer,DWORD ಗಂಟು_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ifdef UNICODE
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#ಅನ್ಯಥಾ
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#endif
#endif

#pragma ತೆಗೆ_macro("socklen_t")

#ifdef UNICODE
#define gai_strerror gai_strerrorW
#ಅನ್ಯಥಾ
#define gai_strerror gai_strerrorA
#endif

#define GAI_STRERROR_BUFFER_SIZE 1024

ವರ್ಣ *gai_strerrorA (ಪೂರ್ಣಾಙ್ಕ);
WCHAR *gai_strerrorW(ಪೂರ್ಣಾಙ್ಕ);

#define NI_MAXHOST 1025
#define NI_MAXSERV 32

#define INET_ADDRSTRLEN 22
#define INET6_ADDRSTRLEN 65

#define NI_NOFQDN 0x01
#define NI_NUMERICHOST 0x02
#define NI_NAMEREQD 0x04
#define NI_NUMERICSERV 0x08
#define NI_DGRAM 0x10

#ifdef __cplusplus
}
#endif

#endif
