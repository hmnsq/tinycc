/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WS2TCPIP_H
#define _WS2TCPIP_H

#اگر __GNUC__ >=3
#pragma GCC system_header
#endif

#شامل <ws2ipdef.h>

ساختار ip_msfilter {
  ساختار in_addr imsf_multiaddr;
  ساختار in_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  ساختار in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) (اندازه(ساختار ip_msfilter)-اندازه(ساختار in_addr) + (numsrc)*اندازه(ساختار in_addr))

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

ساختار in6_addr {
  __MINGW_EXTENSION اجتماع {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#define in_addr6 in6_addr

#define _S6_un u
#define _S6_u8 Byte
#define s6_addr _S6_un._S6_u8

#define s6_bytes u.Byte
#define s6_واژگان u.Word
#endif

تعریفنوع ساختار ipv6_mreq {
  ساختار in6_addr ipv6mr_multiaddr;
  unsigned صحیح ipv6mr_interface;
} IPV6_MREQ;

ساختار sockaddr_in6_old {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  ساختار in6_addr sin6_addr;
};

ساختار sockaddr_in6 {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  ساختار in6_addr sin6_addr;
  u_long sin6_scope_id;
};

تعریفنوع ساختار in6_addr IN6_ADDR;
تعریفنوع ساختار in6_addr *PIN6_ADDR;
تعریفنوع ساختار in6_addr *LPIN6_ADDR;

تعریفنوع ساختار sockaddr_in6 SOCKADDR_IN6;
تعریفنوع ساختار sockaddr_in6 *PSOCKADDR_IN6;
تعریفنوع ساختار sockaddr_in6 *LPSOCKADDR_IN6;

#define SS_PORT(ssp) (((ساختار sockaddr_in*)(ssp))->sin_port)

#define IN6ADDR_ANY_INIT { 0 }
#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ifdef __cplusplus
بیرونی "C" {
#endif

  بیرونی ثابت ساختار in6_addr in6addr_any;
  بیرونی ثابت ساختار in6_addr in6addr_loopback;

#ifdef __cplusplus
}
#endif

#define WS2TCPIP_INLINE __CRT_INLINE

صحیح IN6_ADDR_EQUAL(ثابت ساختار in6_addr *,ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_UNSPECIFIED(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_LOOPBACK(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_MULTICAST(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_LINKLOCAL(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_SITELOCAL(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_V4MAPPED(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_V4COMPAT(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_MC_NODELOCAL(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_MC_LINKLOCAL(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_MC_SITELOCAL(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_MC_ORGLOCAL(ثابت ساختار in6_addr *);
صحیح IN6_IS_ADDR_MC_GLOBAL(ثابت ساختار in6_addr *);
صحیح IN6ADDR_ISANY(ثابت ساختار sockaddr_in6 *);
صحیح IN6ADDR_ISLOOPBACK(ثابت ساختار sockaddr_in6 *);
تهی IN6_SET_ADDR_UNSPECIFIED(ساختار in6_addr *);
تهی IN6_SET_ADDR_LOOPBACK(ساختار in6_addr *);
تهی IN6ADDR_SETANY(ساختار sockaddr_in6 *);
تهی IN6ADDR_SETLOOPBACK(ساختار sockaddr_in6 *);

#ifndef __CRT__NO_INLINE
WS2TCPIP_INLINE صحیح IN6_ADDR_EQUAL(ثابت ساختار in6_addr *a,ثابت ساختار in6_addr *b) { بازگشت (memcmp(a,b,اندازه(ساختار in6_addr))==0); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_UNSPECIFIED(ثابت ساختار in6_addr *a) { بازگشت ((a->s6_واژگان[0]==0) && (a->s6_واژگان[1]==0) && (a->s6_واژگان[2]==0) && (a->s6_واژگان[3]==0) && (a->s6_واژگان[4]==0) && (a->s6_واژگان[5]==0) && (a->s6_واژگان[6]==0) && (a->s6_واژگان[7]==0)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_LOOPBACK(ثابت ساختار in6_addr *a) { بازگشت ((a->s6_واژگان[0]==0) && (a->s6_واژگان[1]==0) && (a->s6_واژگان[2]==0) && (a->s6_واژگان[3]==0) && (a->s6_واژگان[4]==0) && (a->s6_واژگان[5]==0) && (a->s6_واژگان[6]==0) && (a->s6_واژگان[7]==0x0100)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MULTICAST(ثابت ساختار in6_addr *a) { بازگشت (a->s6_bytes[0]==0xff); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_LINKLOCAL(ثابت ساختار in6_addr *a) { بازگشت ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_SITELOCAL(ثابت ساختار in6_addr *a) { بازگشت ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_V4MAPPED(ثابت ساختار in6_addr *a) { بازگشت ((a->s6_واژگان[0]==0) && (a->s6_واژگان[1]==0) && (a->s6_واژگان[2]==0) && (a->s6_واژگان[3]==0) && (a->s6_واژگان[4]==0) && (a->s6_واژگان[5]==0xffff)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_V4COMPAT(ثابت ساختار in6_addr *a) { بازگشت ((a->s6_واژگان[0]==0) && (a->s6_واژگان[1]==0) && (a->s6_واژگان[2]==0) && (a->s6_واژگان[3]==0) && (a->s6_واژگان[4]==0) && (a->s6_واژگان[5]==0) && !((a->s6_واژگان[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_NODELOCAL(ثابت ساختار in6_addr *a) { بازگشت IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_LINKLOCAL(ثابت ساختار in6_addr *a) { بازگشت IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_SITELOCAL(ثابت ساختار in6_addr *a) { بازگشت IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_ORGLOCAL(ثابت ساختار in6_addr *a) { بازگشت IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_GLOBAL(ثابت ساختار in6_addr *a) { بازگشت IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
WS2TCPIP_INLINE صحیح IN6ADDR_ISANY(ثابت ساختار sockaddr_in6 *a) { بازگشت ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE صحیح IN6ADDR_ISLOOPBACK(ثابت ساختار sockaddr_in6 *a) { بازگشت ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE تهی IN6_SET_ADDR_UNSPECIFIED(ساختار in6_addr *a) { memset(a->s6_bytes,0,اندازه(ساختار in6_addr)); }
WS2TCPIP_INLINE تهی IN6_SET_ADDR_LOOPBACK(ساختار in6_addr *a) {
  memset(a->s6_bytes,0,اندازه(ساختار in6_addr));
  a->s6_bytes[15] = 1;
}
WS2TCPIP_INLINE تهی IN6ADDR_SETANY(ساختار sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE تهی IN6ADDR_SETLOOPBACK(ساختار sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#endif /* !__CRT__NO_INLINE */

تعریفنوع اجتماع sockaddr_gen {
  ساختار sockaddr Address;
  ساختار sockaddr_in AddressIn;
  ساختار sockaddr_in6_old AddressIn6;
} sockaddr_gen;

تعریفنوع ساختار _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

تعریفنوع ساختار _INTERFACE_INFO_EX {
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

تعریفنوع ساختار in_pktinfo {
  IN_ADDR ipi_addr;
  UINT ipi_ifindex;
} IN_PKTINFO;

C_ASSERT(اندازه(IN_PKTINFO)==8);

تعریفنوع ساختار in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(اندازه(IN6_PKTINFO)==20);

#define EAI_AGAIN WSATRY_AGAIN
#define EAI_BADFLAGS WSAEINVAL
#define EAI_FAIL WSANO_RECOVERY
#define EAI_FAMILY WSAEAFNOSUPPORT
#define EAI_MEMORY WSA_NOT_ENOUGH_MEMORY

#define EAI_NONAME WSAHOST_NOT_FOUND
#define EAI_SERVICE WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#define EAI_NODATA EAI_NONAME

تعریفنوع ساختار addrinfo {
  صحیح ai_flags;
  صحیح ai_family;
  صحیح ai_socktype;
  صحیح ai_protocol;
  size_t ai_addrlen;
  نویسه *ai_canonname;
  ساختار sockaddr *ai_addr;
  ساختار addrinfo *ai_next;
} ADDRINFOA,*PADDRINFOA;

تعریفنوع ساختار addrinfoW {
  صحیح ai_flags;
  صحیح ai_family;
  صحیح ai_socktype;
  صحیح ai_protocol;
  size_t ai_addrlen;
  PWSTR ai_canonname;
  ساختار sockaddr *ai_addr;
  ساختار addrinfoW *ai_next;
} ADDRINFOW,*PADDRINFOW;

#ifdef UNICODE
تعریفنوع ADDRINFOW ADDRINFOT,*PADDRINFOT;
#وگرنه
تعریفنوع ADDRINFOA ADDRINFOT,*PADDRINFOT;
#endif

تعریفنوع ADDRINFOA ADDRINFO,*LPADDRINFO;

#define AI_PASSIVE 0x1
#define AI_CANONNAME 0x2
#define AI_NUMERICHOST 0x4

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifdef UNICODE
#define GetAddrInfo GetAddrInfoW
#وگرنه
#define GetAddrInfo GetAddrInfoA
#endif

  WINSOCK_API_LINKAGE صحیح WSAAPI getaddrinfo(ثابت نویسه *nodename,ثابت نویسه *servname,ثابت ساختار addrinfo *hints,ساختار addrinfo **res);
  WINSOCK_API_LINKAGE صحیح WSAAPI GetAddrInfoW(PCWSTR p_گره_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define GetAddrInfoA getaddrinfo

#اگر INCL_WINSOCK_API_TYPEDEFS
  تعریفنوع صحیح (WSAAPI *LPFN_GETADDRINFO)(ثابت نویسه *nodename,ثابت نویسه *servname,ثابت ساختار addrinfo *hints,ساختار addrinfo **res);
  تعریفنوع صحیح (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_گره_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ifdef UNICODE
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#وگرنه
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#endif
#endif

#ifdef UNICODE
#define FreeAddrInfo FreeAddrInfoW
#وگرنه
#define FreeAddrInfo FreeAddrInfoA
#endif

  WINSOCK_API_LINKAGE تهی WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE تهی WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#define FreeAddrInfoA freeaddrinfo

#اگر INCL_WINSOCK_API_TYPEDEFS
  تعریفنوع تهی (WSAAPI *LPFN_FREEADDRINFO)(ساختار addrinfo *ai);
  تعریفنوع تهی (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ifdef UNICODE
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#وگرنه
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#endif
#endif

#pragma افزودن_macro("socklen_t")
#undef socklen_t

  تعریفنوع صحیح socklen_t;

#ifdef UNICODE
#define GetNameInfo GetNameInfoW
#وگرنه
#define GetNameInfo GetNameInfoA
#endif

  WINSOCK_API_LINKAGE صحیح WSAAPI getnameinfo(ثابت ساختار sockaddr *sa,socklen_t salen,نویسه *host,DWORD hostlen,نویسه *serv,DWORD servlen,صحیح flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ثابت SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_گره_Buffer,DWORD گره_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define GetNameInfoA getnameinfo

#اگر INCL_WINSOCK_API_TYPEDEFS
  تعریفنوع صحیح (WSAAPI *LPFN_GETNAMEINFO)(ثابت ساختار sockaddr *sa,socklen_t salen,نویسه *host,DWORD hostlen,نویسه *serv,DWORD servlen,صحیح flags);
  تعریفنوع INT (WSAAPI *LPFN_GETNAMEINFOW)(ثابت SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_گره_Buffer,DWORD گره_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ifdef UNICODE
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#وگرنه
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#endif
#endif

#pragma برداشت_macro("socklen_t")

#ifdef UNICODE
#define gai_strerror gai_strerrorW
#وگرنه
#define gai_strerror gai_strerrorA
#endif

#define GAI_STRERROR_BUFFER_SIZE 1024

نویسه *gai_strerrorA (صحیح);
WCHAR *gai_strerrorW(صحیح);

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
