/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WS2TCPIP_H
#define _WS2TCPIP_H

#എങ്കിൽ __GNUC__ >=3
#pragma GCC system_header
#endif

#അന്തര്ഭാവ <ws2ipdef.h>

ഘടന ip_msfilter {
  ഘടന in_addr imsf_multiaddr;
  ഘടന in_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  ഘടന in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) (വലുപ്പം(ഘടന ip_msfilter)-വലുപ്പം(ഘടന in_addr) + (numsrc)*വലുപ്പം(ഘടന in_addr))

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

ഘടന in6_addr {
  __MINGW_EXTENSION സംഘം {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#define in_addr6 in6_addr

#define _S6_un u
#define _S6_u8 Byte
#define s6_addr _S6_un._S6_u8

#define s6_bytes u.Byte
#define s6_വാക്കുകൾ u.Word
#endif

തരനിർവചനം ഘടന ipv6_mreq {
  ഘടന in6_addr ipv6mr_multiaddr;
  unsigned പൂർണ്ണസംഖ്യ ipv6mr_interface;
} IPV6_MREQ;

ഘടന sockaddr_in6_old {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  ഘടന in6_addr sin6_addr;
};

ഘടന sockaddr_in6 {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  ഘടന in6_addr sin6_addr;
  u_long sin6_scope_id;
};

തരനിർവചനം ഘടന in6_addr IN6_ADDR;
തരനിർവചനം ഘടന in6_addr *PIN6_ADDR;
തരനിർവചനം ഘടന in6_addr *LPIN6_ADDR;

തരനിർവചനം ഘടന sockaddr_in6 SOCKADDR_IN6;
തരനിർവചനം ഘടന sockaddr_in6 *PSOCKADDR_IN6;
തരനിർവചനം ഘടന sockaddr_in6 *LPSOCKADDR_IN6;

#define SS_PORT(ssp) (((ഘടന sockaddr_in*)(ssp))->sin_port)

#define IN6ADDR_ANY_INIT { 0 }
#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

  ബാഹ്യ സ്ഥിരം ഘടന in6_addr in6addr_any;
  ബാഹ്യ സ്ഥിരം ഘടന in6_addr in6addr_loopback;

#ifdef __cplusplus
}
#endif

#define WS2TCPIP_INLINE __CRT_INLINE

പൂർണ്ണസംഖ്യ IN6_ADDR_EQUAL(സ്ഥിരം ഘടന in6_addr *,സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_UNSPECIFIED(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_LOOPBACK(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MULTICAST(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_LINKLOCAL(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_SITELOCAL(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_V4MAPPED(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_V4COMPAT(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_NODELOCAL(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_LINKLOCAL(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_SITELOCAL(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_ORGLOCAL(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_GLOBAL(സ്ഥിരം ഘടന in6_addr *);
പൂർണ്ണസംഖ്യ IN6ADDR_ISANY(സ്ഥിരം ഘടന sockaddr_in6 *);
പൂർണ്ണസംഖ്യ IN6ADDR_ISLOOPBACK(സ്ഥിരം ഘടന sockaddr_in6 *);
ശൂന്യം IN6_SET_ADDR_UNSPECIFIED(ഘടന in6_addr *);
ശൂന്യം IN6_SET_ADDR_LOOPBACK(ഘടന in6_addr *);
ശൂന്യം IN6ADDR_SETANY(ഘടന sockaddr_in6 *);
ശൂന്യം IN6ADDR_SETLOOPBACK(ഘടന sockaddr_in6 *);

#ifndef __CRT__NO_INLINE
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_ADDR_EQUAL(സ്ഥിരം ഘടന in6_addr *a,സ്ഥിരം ഘടന in6_addr *b) { തിരികെ (memcmp(a,b,വലുപ്പം(ഘടന in6_addr))==0); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_UNSPECIFIED(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ ((a->s6_വാക്കുകൾ[0]==0) && (a->s6_വാക്കുകൾ[1]==0) && (a->s6_വാക്കുകൾ[2]==0) && (a->s6_വാക്കുകൾ[3]==0) && (a->s6_വാക്കുകൾ[4]==0) && (a->s6_വാക്കുകൾ[5]==0) && (a->s6_വാക്കുകൾ[6]==0) && (a->s6_വാക്കുകൾ[7]==0)); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_LOOPBACK(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ ((a->s6_വാക്കുകൾ[0]==0) && (a->s6_വാക്കുകൾ[1]==0) && (a->s6_വാക്കുകൾ[2]==0) && (a->s6_വാക്കുകൾ[3]==0) && (a->s6_വാക്കുകൾ[4]==0) && (a->s6_വാക്കുകൾ[5]==0) && (a->s6_വാക്കുകൾ[6]==0) && (a->s6_വാക്കുകൾ[7]==0x0100)); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MULTICAST(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ (a->s6_bytes[0]==0xff); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_LINKLOCAL(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_SITELOCAL(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_V4MAPPED(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ ((a->s6_വാക്കുകൾ[0]==0) && (a->s6_വാക്കുകൾ[1]==0) && (a->s6_വാക്കുകൾ[2]==0) && (a->s6_വാക്കുകൾ[3]==0) && (a->s6_വാക്കുകൾ[4]==0) && (a->s6_വാക്കുകൾ[5]==0xffff)); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_V4COMPAT(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ ((a->s6_വാക്കുകൾ[0]==0) && (a->s6_വാക്കുകൾ[1]==0) && (a->s6_വാക്കുകൾ[2]==0) && (a->s6_വാക്കുകൾ[3]==0) && (a->s6_വാക്കുകൾ[4]==0) && (a->s6_വാക്കുകൾ[5]==0) && !((a->s6_വാക്കുകൾ[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_NODELOCAL(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_LINKLOCAL(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_SITELOCAL(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_ORGLOCAL(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6_IS_ADDR_MC_GLOBAL(സ്ഥിരം ഘടന in6_addr *a) { തിരികെ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6ADDR_ISANY(സ്ഥിരം ഘടന sockaddr_in6 *a) { തിരികെ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE പൂർണ്ണസംഖ്യ IN6ADDR_ISLOOPBACK(സ്ഥിരം ഘടന sockaddr_in6 *a) { തിരികെ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE ശൂന്യം IN6_SET_ADDR_UNSPECIFIED(ഘടന in6_addr *a) { memset(a->s6_bytes,0,വലുപ്പം(ഘടന in6_addr)); }
WS2TCPIP_INLINE ശൂന്യം IN6_SET_ADDR_LOOPBACK(ഘടന in6_addr *a) {
  memset(a->s6_bytes,0,വലുപ്പം(ഘടന in6_addr));
  a->s6_bytes[15] = 1;
}
WS2TCPIP_INLINE ശൂന്യം IN6ADDR_SETANY(ഘടന sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE ശൂന്യം IN6ADDR_SETLOOPBACK(ഘടന sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#endif /* !__CRT__NO_INLINE */

തരനിർവചനം സംഘം sockaddr_gen {
  ഘടന sockaddr Address;
  ഘടന sockaddr_in AddressIn;
  ഘടന sockaddr_in6_old AddressIn6;
} sockaddr_gen;

തരനിർവചനം ഘടന _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

തരനിർവചനം ഘടന _INTERFACE_INFO_EX {
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

തരനിർവചനം ഘടന in_pktinfo {
  IN_ADDR ipi_addr;
  UINT ipi_ifindex;
} IN_PKTINFO;

C_ASSERT(വലുപ്പം(IN_PKTINFO)==8);

തരനിർവചനം ഘടന in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(വലുപ്പം(IN6_PKTINFO)==20);

#define EAI_AGAIN WSATRY_AGAIN
#define EAI_BADFLAGS WSAEINVAL
#define EAI_FAIL WSANO_RECOVERY
#define EAI_FAMILY WSAEAFNOSUPPORT
#define EAI_MEMORY WSA_NOT_ENOUGH_MEMORY

#define EAI_NONAME WSAHOST_NOT_FOUND
#define EAI_SERVICE WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#define EAI_NODATA EAI_NONAME

തരനിർവചനം ഘടന addrinfo {
  പൂർണ്ണസംഖ്യ ai_flags;
  പൂർണ്ണസംഖ്യ ai_family;
  പൂർണ്ണസംഖ്യ ai_socktype;
  പൂർണ്ണസംഖ്യ ai_protocol;
  size_t ai_addrlen;
  അക്ഷരം *ai_canonname;
  ഘടന sockaddr *ai_addr;
  ഘടന addrinfo *ai_next;
} ADDRINFOA,*PADDRINFOA;

തരനിർവചനം ഘടന addrinfoW {
  പൂർണ്ണസംഖ്യ ai_flags;
  പൂർണ്ണസംഖ്യ ai_family;
  പൂർണ്ണസംഖ്യ ai_socktype;
  പൂർണ്ണസംഖ്യ ai_protocol;
  size_t ai_addrlen;
  PWSTR ai_canonname;
  ഘടന sockaddr *ai_addr;
  ഘടന addrinfoW *ai_next;
} ADDRINFOW,*PADDRINFOW;

#ifdef UNICODE
തരനിർവചനം ADDRINFOW ADDRINFOT,*PADDRINFOT;
#അല്ലെങ്കിൽ
തരനിർവചനം ADDRINFOA ADDRINFOT,*PADDRINFOT;
#endif

തരനിർവചനം ADDRINFOA ADDRINFO,*LPADDRINFO;

#define AI_PASSIVE 0x1
#define AI_CANONNAME 0x2
#define AI_NUMERICHOST 0x4

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifdef UNICODE
#define GetAddrInfo GetAddrInfoW
#അല്ലെങ്കിൽ
#define GetAddrInfo GetAddrInfoA
#endif

  WINSOCK_API_LINKAGE പൂർണ്ണസംഖ്യ WSAAPI getaddrinfo(സ്ഥിരം അക്ഷരം *nodename,സ്ഥിരം അക്ഷരം *servname,സ്ഥിരം ഘടന addrinfo *hints,ഘടന addrinfo **res);
  WINSOCK_API_LINKAGE പൂർണ്ണസംഖ്യ WSAAPI GetAddrInfoW(PCWSTR p_കണ്ണി_Name,PCWSTR pServiceName,സ്ഥിരം ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define GetAddrInfoA getaddrinfo

#എങ്കിൽ INCL_WINSOCK_API_TYPEDEFS
  തരനിർവചനം പൂർണ്ണസംഖ്യ (WSAAPI *LPFN_GETADDRINFO)(സ്ഥിരം അക്ഷരം *nodename,സ്ഥിരം അക്ഷരം *servname,സ്ഥിരം ഘടന addrinfo *hints,ഘടന addrinfo **res);
  തരനിർവചനം പൂർണ്ണസംഖ്യ (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_കണ്ണി_Name,PCWSTR pServiceName,സ്ഥിരം ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ifdef UNICODE
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#അല്ലെങ്കിൽ
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#endif
#endif

#ifdef UNICODE
#define FreeAddrInfo FreeAddrInfoW
#അല്ലെങ്കിൽ
#define FreeAddrInfo FreeAddrInfoA
#endif

  WINSOCK_API_LINKAGE ശൂന്യം WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE ശൂന്യം WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#define FreeAddrInfoA freeaddrinfo

#എങ്കിൽ INCL_WINSOCK_API_TYPEDEFS
  തരനിർവചനം ശൂന്യം (WSAAPI *LPFN_FREEADDRINFO)(ഘടന addrinfo *ai);
  തരനിർവചനം ശൂന്യം (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ifdef UNICODE
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#അല്ലെങ്കിൽ
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#endif
#endif

#pragma തള്ളുക_macro("socklen_t")
#undef socklen_t

  തരനിർവചനം പൂർണ്ണസംഖ്യ socklen_t;

#ifdef UNICODE
#define GetNameInfo GetNameInfoW
#അല്ലെങ്കിൽ
#define GetNameInfo GetNameInfoA
#endif

  WINSOCK_API_LINKAGE പൂർണ്ണസംഖ്യ WSAAPI getnameinfo(സ്ഥിരം ഘടന sockaddr *sa,socklen_t salen,അക്ഷരം *host,DWORD hostlen,അക്ഷരം *serv,DWORD servlen,പൂർണ്ണസംഖ്യ flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(സ്ഥിരം SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_കണ്ണി_Buffer,DWORD കണ്ണി_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define GetNameInfoA getnameinfo

#എങ്കിൽ INCL_WINSOCK_API_TYPEDEFS
  തരനിർവചനം പൂർണ്ണസംഖ്യ (WSAAPI *LPFN_GETNAMEINFO)(സ്ഥിരം ഘടന sockaddr *sa,socklen_t salen,അക്ഷരം *host,DWORD hostlen,അക്ഷരം *serv,DWORD servlen,പൂർണ്ണസംഖ്യ flags);
  തരനിർവചനം INT (WSAAPI *LPFN_GETNAMEINFOW)(സ്ഥിരം SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_കണ്ണി_Buffer,DWORD കണ്ണി_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ifdef UNICODE
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#അല്ലെങ്കിൽ
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#endif
#endif

#pragma എടുക്കുക_macro("socklen_t")

#ifdef UNICODE
#define gai_strerror gai_strerrorW
#അല്ലെങ്കിൽ
#define gai_strerror gai_strerrorA
#endif

#define GAI_STRERROR_BUFFER_SIZE 1024

അക്ഷരം *gai_strerrorA (പൂർണ്ണസംഖ്യ);
WCHAR *gai_strerrorW(പൂർണ്ണസംഖ്യ);

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
