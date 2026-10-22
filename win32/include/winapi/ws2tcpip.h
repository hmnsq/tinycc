/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WS2TCPIP_H
#define _WS2TCPIP_H

#જો __GNUC__ >=3
#pragma GCC system_header
#endif

#અન્તર્ભાવ <ws2ipdef.h>

સંરચના ip_msfilter {
  સંરચના in_addr imsf_multiaddr;
  સંરચના in_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  સંરચના in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) (કદ(સંરચના ip_msfilter)-કદ(સંરચના in_addr) + (numsrc)*કદ(સંરચના in_addr))

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

સંરચના in6_addr {
  __MINGW_EXTENSION સંઘ {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#define in_addr6 in6_addr

#define _S6_un u
#define _S6_u8 Byte
#define s6_addr _S6_un._S6_u8

#define s6_bytes u.Byte
#define s6_શબ્દો u.Word
#endif

પ્રકારવ્યાખ્યા સંરચના ipv6_mreq {
  સંરચના in6_addr ipv6mr_multiaddr;
  unsigned પૂર્ણાંક ipv6mr_interface;
} IPV6_MREQ;

સંરચના sockaddr_in6_old {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  સંરચના in6_addr sin6_addr;
};

સંરચના sockaddr_in6 {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  સંરચના in6_addr sin6_addr;
  u_long sin6_scope_id;
};

પ્રકારવ્યાખ્યા સંરચના in6_addr IN6_ADDR;
પ્રકારવ્યાખ્યા સંરચના in6_addr *PIN6_ADDR;
પ્રકારવ્યાખ્યા સંરચના in6_addr *LPIN6_ADDR;

પ્રકારવ્યાખ્યા સંરચના sockaddr_in6 SOCKADDR_IN6;
પ્રકારવ્યાખ્યા સંરચના sockaddr_in6 *PSOCKADDR_IN6;
પ્રકારવ્યાખ્યા સંરચના sockaddr_in6 *LPSOCKADDR_IN6;

#define SS_PORT(ssp) (((સંરચના sockaddr_in*)(ssp))->sin_port)

#define IN6ADDR_ANY_INIT { 0 }
#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ifdef __cplusplus
બાહ્ય "C" {
#endif

  બાહ્ય અચલ સંરચના in6_addr in6addr_any;
  બાહ્ય અચલ સંરચના in6_addr in6addr_loopback;

#ifdef __cplusplus
}
#endif

#define WS2TCPIP_INLINE __CRT_INLINE

પૂર્ણાંક IN6_ADDR_EQUAL(અચલ સંરચના in6_addr *,અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_UNSPECIFIED(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_LOOPBACK(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_MULTICAST(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_LINKLOCAL(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_SITELOCAL(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_V4MAPPED(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_V4COMPAT(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_MC_NODELOCAL(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_MC_LINKLOCAL(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_MC_SITELOCAL(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_MC_ORGLOCAL(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6_IS_ADDR_MC_GLOBAL(અચલ સંરચના in6_addr *);
પૂર્ણાંક IN6ADDR_ISANY(અચલ સંરચના sockaddr_in6 *);
પૂર્ણાંક IN6ADDR_ISLOOPBACK(અચલ સંરચના sockaddr_in6 *);
શૂન્ય IN6_SET_ADDR_UNSPECIFIED(સંરચના in6_addr *);
શૂન્ય IN6_SET_ADDR_LOOPBACK(સંરચના in6_addr *);
શૂન્ય IN6ADDR_SETANY(સંરચના sockaddr_in6 *);
શૂન્ય IN6ADDR_SETLOOPBACK(સંરચના sockaddr_in6 *);

#ifndef __CRT__NO_INLINE
WS2TCPIP_INLINE પૂર્ણાંક IN6_ADDR_EQUAL(અચલ સંરચના in6_addr *a,અચલ સંરચના in6_addr *b) { પાછા (memcmp(a,b,કદ(સંરચના in6_addr))==0); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_UNSPECIFIED(અચલ સંરચના in6_addr *a) { પાછા ((a->s6_શબ્દો[0]==0) && (a->s6_શબ્દો[1]==0) && (a->s6_શબ્દો[2]==0) && (a->s6_શબ્દો[3]==0) && (a->s6_શબ્દો[4]==0) && (a->s6_શબ્દો[5]==0) && (a->s6_શબ્દો[6]==0) && (a->s6_શબ્દો[7]==0)); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_LOOPBACK(અચલ સંરચના in6_addr *a) { પાછા ((a->s6_શબ્દો[0]==0) && (a->s6_શબ્દો[1]==0) && (a->s6_શબ્દો[2]==0) && (a->s6_શબ્દો[3]==0) && (a->s6_શબ્દો[4]==0) && (a->s6_શબ્દો[5]==0) && (a->s6_શબ્દો[6]==0) && (a->s6_શબ્દો[7]==0x0100)); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_MULTICAST(અચલ સંરચના in6_addr *a) { પાછા (a->s6_bytes[0]==0xff); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_LINKLOCAL(અચલ સંરચના in6_addr *a) { પાછા ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_SITELOCAL(અચલ સંરચના in6_addr *a) { પાછા ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_V4MAPPED(અચલ સંરચના in6_addr *a) { પાછા ((a->s6_શબ્દો[0]==0) && (a->s6_શબ્દો[1]==0) && (a->s6_શબ્દો[2]==0) && (a->s6_શબ્દો[3]==0) && (a->s6_શબ્દો[4]==0) && (a->s6_શબ્દો[5]==0xffff)); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_V4COMPAT(અચલ સંરચના in6_addr *a) { પાછા ((a->s6_શબ્દો[0]==0) && (a->s6_શબ્દો[1]==0) && (a->s6_શબ્દો[2]==0) && (a->s6_શબ્દો[3]==0) && (a->s6_શબ્દો[4]==0) && (a->s6_શબ્દો[5]==0) && !((a->s6_શબ્દો[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_MC_NODELOCAL(અચલ સંરચના in6_addr *a) { પાછા IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_MC_LINKLOCAL(અચલ સંરચના in6_addr *a) { પાછા IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_MC_SITELOCAL(અચલ સંરચના in6_addr *a) { પાછા IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_MC_ORGLOCAL(અચલ સંરચના in6_addr *a) { પાછા IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
WS2TCPIP_INLINE પૂર્ણાંક IN6_IS_ADDR_MC_GLOBAL(અચલ સંરચના in6_addr *a) { પાછા IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
WS2TCPIP_INLINE પૂર્ણાંક IN6ADDR_ISANY(અચલ સંરચના sockaddr_in6 *a) { પાછા ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE પૂર્ણાંક IN6ADDR_ISLOOPBACK(અચલ સંરચના sockaddr_in6 *a) { પાછા ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE શૂન્ય IN6_SET_ADDR_UNSPECIFIED(સંરચના in6_addr *a) { memset(a->s6_bytes,0,કદ(સંરચના in6_addr)); }
WS2TCPIP_INLINE શૂન્ય IN6_SET_ADDR_LOOPBACK(સંરચના in6_addr *a) {
  memset(a->s6_bytes,0,કદ(સંરચના in6_addr));
  a->s6_bytes[15] = 1;
}
WS2TCPIP_INLINE શૂન્ય IN6ADDR_SETANY(સંરચના sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE શૂન્ય IN6ADDR_SETLOOPBACK(સંરચના sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#endif /* !__CRT__NO_INLINE */

પ્રકારવ્યાખ્યા સંઘ sockaddr_gen {
  સંરચના sockaddr Address;
  સંરચના sockaddr_in AddressIn;
  સંરચના sockaddr_in6_old AddressIn6;
} sockaddr_gen;

પ્રકારવ્યાખ્યા સંરચના _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

પ્રકારવ્યાખ્યા સંરચના _INTERFACE_INFO_EX {
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

પ્રકારવ્યાખ્યા સંરચના in_pktinfo {
  IN_ADDR ipi_addr;
  UINT ipi_ifindex;
} IN_PKTINFO;

C_ASSERT(કદ(IN_PKTINFO)==8);

પ્રકારવ્યાખ્યા સંરચના in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(કદ(IN6_PKTINFO)==20);

#define EAI_AGAIN WSATRY_AGAIN
#define EAI_BADFLAGS WSAEINVAL
#define EAI_FAIL WSANO_RECOVERY
#define EAI_FAMILY WSAEAFNOSUPPORT
#define EAI_MEMORY WSA_NOT_ENOUGH_MEMORY

#define EAI_NONAME WSAHOST_NOT_FOUND
#define EAI_SERVICE WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#define EAI_NODATA EAI_NONAME

પ્રકારવ્યાખ્યા સંરચના addrinfo {
  પૂર્ણાંક ai_flags;
  પૂર્ણાંક ai_family;
  પૂર્ણાંક ai_socktype;
  પૂર્ણાંક ai_protocol;
  size_t ai_addrlen;
  અક્ષર *ai_canonname;
  સંરચના sockaddr *ai_addr;
  સંરચના addrinfo *ai_next;
} ADDRINFOA,*PADDRINFOA;

પ્રકારવ્યાખ્યા સંરચના addrinfoW {
  પૂર્ણાંક ai_flags;
  પૂર્ણાંક ai_family;
  પૂર્ણાંક ai_socktype;
  પૂર્ણાંક ai_protocol;
  size_t ai_addrlen;
  PWSTR ai_canonname;
  સંરચના sockaddr *ai_addr;
  સંરચના addrinfoW *ai_next;
} ADDRINFOW,*PADDRINFOW;

#ifdef UNICODE
પ્રકારવ્યાખ્યા ADDRINFOW ADDRINFOT,*PADDRINFOT;
#નહીંતર
પ્રકારવ્યાખ્યા ADDRINFOA ADDRINFOT,*PADDRINFOT;
#endif

પ્રકારવ્યાખ્યા ADDRINFOA ADDRINFO,*LPADDRINFO;

#define AI_PASSIVE 0x1
#define AI_CANONNAME 0x2
#define AI_NUMERICHOST 0x4

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifdef UNICODE
#define GetAddrInfo GetAddrInfoW
#નહીંતર
#define GetAddrInfo GetAddrInfoA
#endif

  WINSOCK_API_LINKAGE પૂર્ણાંક WSAAPI getaddrinfo(અચલ અક્ષર *nodename,અચલ અક્ષર *servname,અચલ સંરચના addrinfo *hints,સંરચના addrinfo **res);
  WINSOCK_API_LINKAGE પૂર્ણાંક WSAAPI GetAddrInfoW(PCWSTR p_ગાંઠ_Name,PCWSTR pServiceName,અચલ ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define GetAddrInfoA getaddrinfo

#જો INCL_WINSOCK_API_TYPEDEFS
  પ્રકારવ્યાખ્યા પૂર્ણાંક (WSAAPI *LPFN_GETADDRINFO)(અચલ અક્ષર *nodename,અચલ અક્ષર *servname,અચલ સંરચના addrinfo *hints,સંરચના addrinfo **res);
  પ્રકારવ્યાખ્યા પૂર્ણાંક (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_ગાંઠ_Name,PCWSTR pServiceName,અચલ ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ifdef UNICODE
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#નહીંતર
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#endif
#endif

#ifdef UNICODE
#define FreeAddrInfo FreeAddrInfoW
#નહીંતર
#define FreeAddrInfo FreeAddrInfoA
#endif

  WINSOCK_API_LINKAGE શૂન્ય WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE શૂન્ય WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#define FreeAddrInfoA freeaddrinfo

#જો INCL_WINSOCK_API_TYPEDEFS
  પ્રકારવ્યાખ્યા શૂન્ય (WSAAPI *LPFN_FREEADDRINFO)(સંરચના addrinfo *ai);
  પ્રકારવ્યાખ્યા શૂન્ય (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ifdef UNICODE
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#નહીંતર
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#endif
#endif

#pragma ધકેલો_macro("socklen_t")
#undef socklen_t

  પ્રકારવ્યાખ્યા પૂર્ણાંક socklen_t;

#ifdef UNICODE
#define GetNameInfo GetNameInfoW
#નહીંતર
#define GetNameInfo GetNameInfoA
#endif

  WINSOCK_API_LINKAGE પૂર્ણાંક WSAAPI getnameinfo(અચલ સંરચના sockaddr *sa,socklen_t salen,અક્ષર *host,DWORD hostlen,અક્ષર *serv,DWORD servlen,પૂર્ણાંક flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(અચલ SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_ગાંઠ_Buffer,DWORD ગાંઠ_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define GetNameInfoA getnameinfo

#જો INCL_WINSOCK_API_TYPEDEFS
  પ્રકારવ્યાખ્યા પૂર્ણાંક (WSAAPI *LPFN_GETNAMEINFO)(અચલ સંરચના sockaddr *sa,socklen_t salen,અક્ષર *host,DWORD hostlen,અક્ષર *serv,DWORD servlen,પૂર્ણાંક flags);
  પ્રકારવ્યાખ્યા INT (WSAAPI *LPFN_GETNAMEINFOW)(અચલ SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_ગાંઠ_Buffer,DWORD ગાંઠ_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ifdef UNICODE
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#નહીંતર
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#endif
#endif

#pragma કાઢો_macro("socklen_t")

#ifdef UNICODE
#define gai_strerror gai_strerrorW
#નહીંતર
#define gai_strerror gai_strerrorA
#endif

#define GAI_STRERROR_BUFFER_SIZE 1024

અક્ષર *gai_strerrorA (પૂર્ણાંક);
WCHAR *gai_strerrorW(પૂર્ણાંક);

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
