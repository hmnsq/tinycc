/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WS2TCPIP_H
#define _WS2TCPIP_H

#ပေႃး __GNUC__ >=3
#pragma GCC system_header
#endif

#include <ws2ipdef.h>

sa_nracanaa ip_msfilter {
  sa_nracanaa in_addr imsf_multiaddr;
  sa_nracanaa in_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  sa_nracanaa in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) (parimaa_na(sa_nracanaa ip_msfilter)-parimaa_na(sa_nracanaa in_addr) + (numsrc)*parimaa_na(sa_nracanaa in_addr))

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

sa_nracanaa in6_addr {
  __MINGW_EXTENSION sa_ngha {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#define in_addr6 in6_addr

#define _S6_un u
#define _S6_u8 Byte
#define s6_addr _S6_un._S6_u8

#define s6_bytes u.Byte
#define s6_words u.Word
#endif

typedef sa_nracanaa ipv6_mreq {
  sa_nracanaa in6_addr ipv6mr_multiaddr;
  unsigned puur_naa_nka ipv6mr_interface;
} IPV6_MREQ;

sa_nracanaa sockaddr_in6_old {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  sa_nracanaa in6_addr sin6_addr;
};

sa_nracanaa sockaddr_in6 {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  sa_nracanaa in6_addr sin6_addr;
  u_long sin6_scope_id;
};

typedef sa_nracanaa in6_addr IN6_ADDR;
typedef sa_nracanaa in6_addr *PIN6_ADDR;
typedef sa_nracanaa in6_addr *LPIN6_ADDR;

typedef sa_nracanaa sockaddr_in6 SOCKADDR_IN6;
typedef sa_nracanaa sockaddr_in6 *PSOCKADDR_IN6;
typedef sa_nracanaa sockaddr_in6 *LPSOCKADDR_IN6;

#define SS_PORT(ssp) (((sa_nracanaa sockaddr_in*)(ssp))->sin_port)

#define IN6ADDR_ANY_INIT { 0 }
#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ifdef __cplusplus
extern "C" {
#endif

  extern const sa_nracanaa in6_addr in6addr_any;
  extern const sa_nracanaa in6_addr in6addr_loopback;

#ifdef __cplusplus
}
#endif

#define WS2TCPIP_INLINE __CRT_INLINE

puur_naa_nka IN6_ADDR_EQUAL(const sa_nracanaa in6_addr *,const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_UNSPECIFIED(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_LOOPBACK(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_MULTICAST(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_LINKLOCAL(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_SITELOCAL(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_V4MAPPED(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_V4COMPAT(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_MC_NODELOCAL(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_MC_LINKLOCAL(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_MC_SITELOCAL(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_MC_ORGLOCAL(const sa_nracanaa in6_addr *);
puur_naa_nka IN6_IS_ADDR_MC_GLOBAL(const sa_nracanaa in6_addr *);
puur_naa_nka IN6ADDR_ISANY(const sa_nracanaa sockaddr_in6 *);
puur_naa_nka IN6ADDR_ISLOOPBACK(const sa_nracanaa sockaddr_in6 *);
void IN6_SET_ADDR_UNSPECIFIED(sa_nracanaa in6_addr *);
void IN6_SET_ADDR_LOOPBACK(sa_nracanaa in6_addr *);
void IN6ADDR_SETANY(sa_nracanaa sockaddr_in6 *);
void IN6ADDR_SETLOOPBACK(sa_nracanaa sockaddr_in6 *);

#ifndef __CRT__NO_INLINE
WS2TCPIP_INLINE puur_naa_nka IN6_ADDR_EQUAL(const sa_nracanaa in6_addr *a,const sa_nracanaa in6_addr *b) { ပွၵ်ႈ (memcmp(a,b,parimaa_na(sa_nracanaa in6_addr))==0); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_UNSPECIFIED(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ ((a->s6_words[0]==0) && (a->s6_words[1]==0) && (a->s6_words[2]==0) && (a->s6_words[3]==0) && (a->s6_words[4]==0) && (a->s6_words[5]==0) && (a->s6_words[6]==0) && (a->s6_words[7]==0)); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_LOOPBACK(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ ((a->s6_words[0]==0) && (a->s6_words[1]==0) && (a->s6_words[2]==0) && (a->s6_words[3]==0) && (a->s6_words[4]==0) && (a->s6_words[5]==0) && (a->s6_words[6]==0) && (a->s6_words[7]==0x0100)); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_MULTICAST(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ (a->s6_bytes[0]==0xff); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_LINKLOCAL(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_SITELOCAL(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_V4MAPPED(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ ((a->s6_words[0]==0) && (a->s6_words[1]==0) && (a->s6_words[2]==0) && (a->s6_words[3]==0) && (a->s6_words[4]==0) && (a->s6_words[5]==0xffff)); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_V4COMPAT(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ ((a->s6_words[0]==0) && (a->s6_words[1]==0) && (a->s6_words[2]==0) && (a->s6_words[3]==0) && (a->s6_words[4]==0) && (a->s6_words[5]==0) && !((a->s6_words[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_MC_NODELOCAL(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_MC_LINKLOCAL(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_MC_SITELOCAL(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_MC_ORGLOCAL(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
WS2TCPIP_INLINE puur_naa_nka IN6_IS_ADDR_MC_GLOBAL(const sa_nracanaa in6_addr *a) { ပွၵ်ႈ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
WS2TCPIP_INLINE puur_naa_nka IN6ADDR_ISANY(const sa_nracanaa sockaddr_in6 *a) { ပွၵ်ႈ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE puur_naa_nka IN6ADDR_ISLOOPBACK(const sa_nracanaa sockaddr_in6 *a) { ပွၵ်ႈ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE void IN6_SET_ADDR_UNSPECIFIED(sa_nracanaa in6_addr *a) { memset(a->s6_bytes,0,parimaa_na(sa_nracanaa in6_addr)); }
WS2TCPIP_INLINE void IN6_SET_ADDR_LOOPBACK(sa_nracanaa in6_addr *a) {
  memset(a->s6_bytes,0,parimaa_na(sa_nracanaa in6_addr));
  a->s6_bytes[15] = 1;
}
WS2TCPIP_INLINE void IN6ADDR_SETANY(sa_nracanaa sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE void IN6ADDR_SETLOOPBACK(sa_nracanaa sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#endif /* !__CRT__NO_INLINE */

typedef sa_ngha sockaddr_gen {
  sa_nracanaa sockaddr Address;
  sa_nracanaa sockaddr_in AddressIn;
  sa_nracanaa sockaddr_in6_old AddressIn6;
} sockaddr_gen;

typedef sa_nracanaa _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

typedef sa_nracanaa _INTERFACE_INFO_EX {
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

typedef sa_nracanaa in_pktinfo {
  IN_ADDR ipi_addr;
  UINT ipi_ifindex;
} IN_PKTINFO;

C_ASSERT(parimaa_na(IN_PKTINFO)==8);

typedef sa_nracanaa in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(parimaa_na(IN6_PKTINFO)==20);

#define EAI_AGAIN WSATRY_AGAIN
#define EAI_BADFLAGS WSAEINVAL
#define EAI_FAIL WSANO_RECOVERY
#define EAI_FAMILY WSAEAFNOSUPPORT
#define EAI_MEMORY WSA_NOT_ENOUGH_MEMORY

#define EAI_NONAME WSAHOST_NOT_FOUND
#define EAI_SERVICE WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#define EAI_NODATA EAI_NONAME

typedef sa_nracanaa addrinfo {
  puur_naa_nka ai_flags;
  puur_naa_nka ai_family;
  puur_naa_nka ai_socktype;
  puur_naa_nka ai_protocol;
  size_t ai_addrlen;
  var_na *ai_canonname;
  sa_nracanaa sockaddr *ai_addr;
  sa_nracanaa addrinfo *ai_next;
} ADDRINFOA,*PADDRINFOA;

typedef sa_nracanaa addrinfoW {
  puur_naa_nka ai_flags;
  puur_naa_nka ai_family;
  puur_naa_nka ai_socktype;
  puur_naa_nka ai_protocol;
  size_t ai_addrlen;
  PWSTR ai_canonname;
  sa_nracanaa sockaddr *ai_addr;
  sa_nracanaa addrinfoW *ai_next;
} ADDRINFOW,*PADDRINFOW;

#ifdef UNICODE
typedef ADDRINFOW ADDRINFOT,*PADDRINFOT;
#ပေႃးဢမ်ႇ
typedef ADDRINFOA ADDRINFOT,*PADDRINFOT;
#endif

typedef ADDRINFOA ADDRINFO,*LPADDRINFO;

#define AI_PASSIVE 0x1
#define AI_CANONNAME 0x2
#define AI_NUMERICHOST 0x4

#ifdef __cplusplus
extern "C" {
#endif

#ifdef UNICODE
#define GetAddrInfo GetAddrInfoW
#ပေႃးဢမ်ႇ
#define GetAddrInfo GetAddrInfoA
#endif

  WINSOCK_API_LINKAGE puur_naa_nka WSAAPI getaddrinfo(const var_na *nodename,const var_na *servname,const sa_nracanaa addrinfo *hints,sa_nracanaa addrinfo **res);
  WINSOCK_API_LINKAGE puur_naa_nka WSAAPI GetAddrInfoW(PCWSTR pNodeName,PCWSTR pServiceName,const ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define GetAddrInfoA getaddrinfo

#ပေႃး INCL_WINSOCK_API_TYPEDEFS
  typedef puur_naa_nka (WSAAPI *LPFN_GETADDRINFO)(const var_na *nodename,const var_na *servname,const sa_nracanaa addrinfo *hints,sa_nracanaa addrinfo **res);
  typedef puur_naa_nka (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR pNodeName,PCWSTR pServiceName,const ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ifdef UNICODE
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#ပေႃးဢမ်ႇ
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#endif
#endif

#ifdef UNICODE
#define FreeAddrInfo FreeAddrInfoW
#ပေႃးဢမ်ႇ
#define FreeAddrInfo FreeAddrInfoA
#endif

  WINSOCK_API_LINKAGE void WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE void WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#define FreeAddrInfoA freeaddrinfo

#ပေႃး INCL_WINSOCK_API_TYPEDEFS
  typedef void (WSAAPI *LPFN_FREEADDRINFO)(sa_nracanaa addrinfo *ai);
  typedef void (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ifdef UNICODE
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#ပေႃးဢမ်ႇ
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#endif
#endif

#pragma push_macro("socklen_t")
#undef socklen_t

  typedef puur_naa_nka socklen_t;

#ifdef UNICODE
#define GetNameInfo GetNameInfoW
#ပေႃးဢမ်ႇ
#define GetNameInfo GetNameInfoA
#endif

  WINSOCK_API_LINKAGE puur_naa_nka WSAAPI getnameinfo(const sa_nracanaa sockaddr *sa,socklen_t salen,var_na *host,DWORD hostlen,var_na *serv,DWORD servlen,puur_naa_nka flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(const SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR pNodeBuffer,DWORD NodeBufferSize,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define GetNameInfoA getnameinfo

#ပေႃး INCL_WINSOCK_API_TYPEDEFS
  typedef puur_naa_nka (WSAAPI *LPFN_GETNAMEINFO)(const sa_nracanaa sockaddr *sa,socklen_t salen,var_na *host,DWORD hostlen,var_na *serv,DWORD servlen,puur_naa_nka flags);
  typedef INT (WSAAPI *LPFN_GETNAMEINFOW)(const SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR pNodeBuffer,DWORD NodeBufferSize,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ifdef UNICODE
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#ပေႃးဢမ်ႇ
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#endif
#endif

#pragma pop_macro("socklen_t")

#ifdef UNICODE
#define gai_strerror gai_strerrorW
#ပေႃးဢမ်ႇ
#define gai_strerror gai_strerrorA
#endif

#define GAI_STRERROR_BUFFER_SIZE 1024

var_na *gai_strerrorA (puur_naa_nka);
WCHAR *gai_strerrorW(puur_naa_nka);

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
