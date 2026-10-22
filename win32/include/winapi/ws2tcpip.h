/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WS2TCPIP_H
#define _WS2TCPIP_H

#যদি __GNUC__ >=3
#pragma GCC system_header
#endif

#অন্তর্ভাব <ws2ipdef.h>

সংরচনা ip_msfilter {
  সংরচনা in_addr imsf_multiaddr;
  সংরচনা in_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  সংরচনা in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) (পরিমাণ(সংরচনা ip_msfilter)-পরিমাণ(সংরচনা in_addr) + (numsrc)*পরিমাণ(সংরচনা in_addr))

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

সংরচনা in6_addr {
  __MINGW_EXTENSION সঙ্ঘ {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#define in_addr6 in6_addr

#define _S6_un u
#define _S6_u8 Byte
#define s6_addr _S6_un._S6_u8

#define s6_bytes u.Byte
#define s6_শব্দগুলি u.Word
#endif

প্রকারনির্দেশ সংরচনা ipv6_mreq {
  সংরচনা in6_addr ipv6mr_multiaddr;
  unsigned পূর্ণাঙ্ক ipv6mr_interface;
} IPV6_MREQ;

সংরচনা sockaddr_in6_old {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  সংরচনা in6_addr sin6_addr;
};

সংরচনা sockaddr_in6 {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  সংরচনা in6_addr sin6_addr;
  u_long sin6_scope_id;
};

প্রকারনির্দেশ সংরচনা in6_addr IN6_ADDR;
প্রকারনির্দেশ সংরচনা in6_addr *PIN6_ADDR;
প্রকারনির্দেশ সংরচনা in6_addr *LPIN6_ADDR;

প্রকারনির্দেশ সংরচনা sockaddr_in6 SOCKADDR_IN6;
প্রকারনির্দেশ সংরচনা sockaddr_in6 *PSOCKADDR_IN6;
প্রকারনির্দেশ সংরচনা sockaddr_in6 *LPSOCKADDR_IN6;

#define SS_PORT(ssp) (((সংরচনা sockaddr_in*)(ssp))->sin_port)

#define IN6ADDR_ANY_INIT { 0 }
#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ifdef __cplusplus
বাহ্য "C" {
#endif

  বাহ্য ধ্রুব সংরচনা in6_addr in6addr_any;
  বাহ্য ধ্রুব সংরচনা in6_addr in6addr_loopback;

#ifdef __cplusplus
}
#endif

#define WS2TCPIP_INLINE __CRT_INLINE

পূর্ণাঙ্ক IN6_ADDR_EQUAL(ধ্রুব সংরচনা in6_addr *,ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_UNSPECIFIED(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_LOOPBACK(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_MULTICAST(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_LINKLOCAL(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_SITELOCAL(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_V4MAPPED(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_V4COMPAT(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_MC_NODELOCAL(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_MC_LINKLOCAL(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_MC_SITELOCAL(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_MC_ORGLOCAL(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6_IS_ADDR_MC_GLOBAL(ধ্রুব সংরচনা in6_addr *);
পূর্ণাঙ্ক IN6ADDR_ISANY(ধ্রুব সংরচনা sockaddr_in6 *);
পূর্ণাঙ্ক IN6ADDR_ISLOOPBACK(ধ্রুব সংরচনা sockaddr_in6 *);
শূন্য IN6_SET_ADDR_UNSPECIFIED(সংরচনা in6_addr *);
শূন্য IN6_SET_ADDR_LOOPBACK(সংরচনা in6_addr *);
শূন্য IN6ADDR_SETANY(সংরচনা sockaddr_in6 *);
শূন্য IN6ADDR_SETLOOPBACK(সংরচনা sockaddr_in6 *);

#ifndef __CRT__NO_INLINE
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_ADDR_EQUAL(ধ্রুব সংরচনা in6_addr *a,ধ্রুব সংরচনা in6_addr *b) { প্রত্যাগম (memcmp(a,b,পরিমাণ(সংরচনা in6_addr))==0); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_UNSPECIFIED(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম ((a->s6_শব্দগুলি[0]==0) && (a->s6_শব্দগুলি[1]==0) && (a->s6_শব্দগুলি[2]==0) && (a->s6_শব্দগুলি[3]==0) && (a->s6_শব্দগুলি[4]==0) && (a->s6_শব্দগুলি[5]==0) && (a->s6_শব্দগুলি[6]==0) && (a->s6_শব্দগুলি[7]==0)); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_LOOPBACK(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম ((a->s6_শব্দগুলি[0]==0) && (a->s6_শব্দগুলি[1]==0) && (a->s6_শব্দগুলি[2]==0) && (a->s6_শব্দগুলি[3]==0) && (a->s6_শব্দগুলি[4]==0) && (a->s6_শব্দগুলি[5]==0) && (a->s6_শব্দগুলি[6]==0) && (a->s6_শব্দগুলি[7]==0x0100)); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_MULTICAST(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম (a->s6_bytes[0]==0xff); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_LINKLOCAL(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_SITELOCAL(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_V4MAPPED(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম ((a->s6_শব্দগুলি[0]==0) && (a->s6_শব্দগুলি[1]==0) && (a->s6_শব্দগুলি[2]==0) && (a->s6_শব্দগুলি[3]==0) && (a->s6_শব্দগুলি[4]==0) && (a->s6_শব্দগুলি[5]==0xffff)); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_V4COMPAT(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম ((a->s6_শব্দগুলি[0]==0) && (a->s6_শব্দগুলি[1]==0) && (a->s6_শব্দগুলি[2]==0) && (a->s6_শব্দগুলি[3]==0) && (a->s6_শব্দগুলি[4]==0) && (a->s6_শব্দগুলি[5]==0) && !((a->s6_শব্দগুলি[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_MC_NODELOCAL(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_MC_LINKLOCAL(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_MC_SITELOCAL(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_MC_ORGLOCAL(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6_IS_ADDR_MC_GLOBAL(ধ্রুব সংরচনা in6_addr *a) { প্রত্যাগম IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6ADDR_ISANY(ধ্রুব সংরচনা sockaddr_in6 *a) { প্রত্যাগম ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE পূর্ণাঙ্ক IN6ADDR_ISLOOPBACK(ধ্রুব সংরচনা sockaddr_in6 *a) { প্রত্যাগম ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE শূন্য IN6_SET_ADDR_UNSPECIFIED(সংরচনা in6_addr *a) { memset(a->s6_bytes,0,পরিমাণ(সংরচনা in6_addr)); }
WS2TCPIP_INLINE শূন্য IN6_SET_ADDR_LOOPBACK(সংরচনা in6_addr *a) {
  memset(a->s6_bytes,0,পরিমাণ(সংরচনা in6_addr));
  a->s6_bytes[15] = 1;
}
WS2TCPIP_INLINE শূন্য IN6ADDR_SETANY(সংরচনা sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE শূন্য IN6ADDR_SETLOOPBACK(সংরচনা sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#endif /* !__CRT__NO_INLINE */

প্রকারনির্দেশ সঙ্ঘ sockaddr_gen {
  সংরচনা sockaddr Address;
  সংরচনা sockaddr_in AddressIn;
  সংরচনা sockaddr_in6_old AddressIn6;
} sockaddr_gen;

প্রকারনির্দেশ সংরচনা _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

প্রকারনির্দেশ সংরচনা _INTERFACE_INFO_EX {
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

প্রকারনির্দেশ সংরচনা in_pktinfo {
  IN_ADDR ipi_addr;
  UINT ipi_ifindex;
} IN_PKTINFO;

C_ASSERT(পরিমাণ(IN_PKTINFO)==8);

প্রকারনির্দেশ সংরচনা in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(পরিমাণ(IN6_PKTINFO)==20);

#define EAI_AGAIN WSATRY_AGAIN
#define EAI_BADFLAGS WSAEINVAL
#define EAI_FAIL WSANO_RECOVERY
#define EAI_FAMILY WSAEAFNOSUPPORT
#define EAI_MEMORY WSA_NOT_ENOUGH_MEMORY

#define EAI_NONAME WSAHOST_NOT_FOUND
#define EAI_SERVICE WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#define EAI_NODATA EAI_NONAME

প্রকারনির্দেশ সংরচনা addrinfo {
  পূর্ণাঙ্ক ai_flags;
  পূর্ণাঙ্ক ai_family;
  পূর্ণাঙ্ক ai_socktype;
  পূর্ণাঙ্ক ai_protocol;
  size_t ai_addrlen;
  বর্ণ *ai_canonname;
  সংরচনা sockaddr *ai_addr;
  সংরচনা addrinfo *ai_next;
} ADDRINFOA,*PADDRINFOA;

প্রকারনির্দেশ সংরচনা addrinfoW {
  পূর্ণাঙ্ক ai_flags;
  পূর্ণাঙ্ক ai_family;
  পূর্ণাঙ্ক ai_socktype;
  পূর্ণাঙ্ক ai_protocol;
  size_t ai_addrlen;
  PWSTR ai_canonname;
  সংরচনা sockaddr *ai_addr;
  সংরচনা addrinfoW *ai_next;
} ADDRINFOW,*PADDRINFOW;

#ifdef UNICODE
প্রকারনির্দেশ ADDRINFOW ADDRINFOT,*PADDRINFOT;
#অন্যথা
প্রকারনির্দেশ ADDRINFOA ADDRINFOT,*PADDRINFOT;
#endif

প্রকারনির্দেশ ADDRINFOA ADDRINFO,*LPADDRINFO;

#define AI_PASSIVE 0x1
#define AI_CANONNAME 0x2
#define AI_NUMERICHOST 0x4

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifdef UNICODE
#define GetAddrInfo GetAddrInfoW
#অন্যথা
#define GetAddrInfo GetAddrInfoA
#endif

  WINSOCK_API_LINKAGE পূর্ণাঙ্ক WSAAPI getaddrinfo(ধ্রুব বর্ণ *nodename,ধ্রুব বর্ণ *servname,ধ্রুব সংরচনা addrinfo *hints,সংরচনা addrinfo **res);
  WINSOCK_API_LINKAGE পূর্ণাঙ্ক WSAAPI GetAddrInfoW(PCWSTR p_গ্রন্থি_Name,PCWSTR pServiceName,ধ্রুব ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define GetAddrInfoA getaddrinfo

#যদি INCL_WINSOCK_API_TYPEDEFS
  প্রকারনির্দেশ পূর্ণাঙ্ক (WSAAPI *LPFN_GETADDRINFO)(ধ্রুব বর্ণ *nodename,ধ্রুব বর্ণ *servname,ধ্রুব সংরচনা addrinfo *hints,সংরচনা addrinfo **res);
  প্রকারনির্দেশ পূর্ণাঙ্ক (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_গ্রন্থি_Name,PCWSTR pServiceName,ধ্রুব ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ifdef UNICODE
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#অন্যথা
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#endif
#endif

#ifdef UNICODE
#define FreeAddrInfo FreeAddrInfoW
#অন্যথা
#define FreeAddrInfo FreeAddrInfoA
#endif

  WINSOCK_API_LINKAGE শূন্য WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE শূন্য WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#define FreeAddrInfoA freeaddrinfo

#যদি INCL_WINSOCK_API_TYPEDEFS
  প্রকারনির্দেশ শূন্য (WSAAPI *LPFN_FREEADDRINFO)(সংরচনা addrinfo *ai);
  প্রকারনির্দেশ শূন্য (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ifdef UNICODE
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#অন্যথা
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#endif
#endif

#pragma ঠেলো_macro("socklen_t")
#undef socklen_t

  প্রকারনির্দেশ পূর্ণাঙ্ক socklen_t;

#ifdef UNICODE
#define GetNameInfo GetNameInfoW
#অন্যথা
#define GetNameInfo GetNameInfoA
#endif

  WINSOCK_API_LINKAGE পূর্ণাঙ্ক WSAAPI getnameinfo(ধ্রুব সংরচনা sockaddr *sa,socklen_t salen,বর্ণ *host,DWORD hostlen,বর্ণ *serv,DWORD servlen,পূর্ণাঙ্ক flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ধ্রুব SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_গ্রন্থি_Buffer,DWORD গ্রন্থি_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define GetNameInfoA getnameinfo

#যদি INCL_WINSOCK_API_TYPEDEFS
  প্রকারনির্দেশ পূর্ণাঙ্ক (WSAAPI *LPFN_GETNAMEINFO)(ধ্রুব সংরচনা sockaddr *sa,socklen_t salen,বর্ণ *host,DWORD hostlen,বর্ণ *serv,DWORD servlen,পূর্ণাঙ্ক flags);
  প্রকারনির্দেশ INT (WSAAPI *LPFN_GETNAMEINFOW)(ধ্রুব SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_গ্রন্থি_Buffer,DWORD গ্রন্থি_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ifdef UNICODE
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#অন্যথা
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#endif
#endif

#pragma বের_করো_macro("socklen_t")

#ifdef UNICODE
#define gai_strerror gai_strerrorW
#অন্যথা
#define gai_strerror gai_strerrorA
#endif

#define GAI_STRERROR_BUFFER_SIZE 1024

বর্ণ *gai_strerrorA (পূর্ণাঙ্ক);
WCHAR *gai_strerrorW(পূর্ণাঙ্ক);

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
