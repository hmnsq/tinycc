/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WS2TCPIP_H
#define _WS2TCPIP_H

#यदि __GNUC__ >=3
#pragma GCC system_header
#endif

#अन्तर्भाव <ws2ipdef.h>

संरचना ip_msfilter {
  संरचना in_addr imsf_multiaddr;
  संरचना in_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  संरचना in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) (परिमाण(संरचना ip_msfilter)-परिमाण(संरचना in_addr) + (numsrc)*परिमाण(संरचना in_addr))

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

संरचना in6_addr {
  __MINGW_EXTENSION सङ्घ {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#define in_addr6 in6_addr

#define _S6_un u
#define _S6_u8 Byte
#define s6_addr _S6_un._S6_u8

#define s6_bytes u.Byte
#define s6_शब्दगण u.Word
#endif

प्रकारनिर्देश संरचना ipv6_mreq {
  संरचना in6_addr ipv6mr_multiaddr;
  unsigned पूर्णाङ्क ipv6mr_interface;
} IPV6_MREQ;

संरचना sockaddr_in6_old {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  संरचना in6_addr sin6_addr;
};

संरचना sockaddr_in6 {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  संरचना in6_addr sin6_addr;
  u_long sin6_scope_id;
};

प्रकारनिर्देश संरचना in6_addr IN6_ADDR;
प्रकारनिर्देश संरचना in6_addr *PIN6_ADDR;
प्रकारनिर्देश संरचना in6_addr *LPIN6_ADDR;

प्रकारनिर्देश संरचना sockaddr_in6 SOCKADDR_IN6;
प्रकारनिर्देश संरचना sockaddr_in6 *PSOCKADDR_IN6;
प्रकारनिर्देश संरचना sockaddr_in6 *LPSOCKADDR_IN6;

#define SS_PORT(ssp) (((संरचना sockaddr_in*)(ssp))->sin_port)

#define IN6ADDR_ANY_INIT { 0 }
#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ifdef __cplusplus
बाह्य "C" {
#endif

  बाह्य ध्रुव संरचना in6_addr in6addr_any;
  बाह्य ध्रुव संरचना in6_addr in6addr_loopback;

#ifdef __cplusplus
}
#endif

#define WS2TCPIP_INLINE __CRT_INLINE

पूर्णाङ्क IN6_ADDR_EQUAL(ध्रुव संरचना in6_addr *,ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_UNSPECIFIED(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_LOOPBACK(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_MULTICAST(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_LINKLOCAL(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_SITELOCAL(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_V4MAPPED(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_V4COMPAT(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_MC_NODELOCAL(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_MC_LINKLOCAL(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_MC_SITELOCAL(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_MC_ORGLOCAL(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6_IS_ADDR_MC_GLOBAL(ध्रुव संरचना in6_addr *);
पूर्णाङ्क IN6ADDR_ISANY(ध्रुव संरचना sockaddr_in6 *);
पूर्णाङ्क IN6ADDR_ISLOOPBACK(ध्रुव संरचना sockaddr_in6 *);
शून्य IN6_SET_ADDR_UNSPECIFIED(संरचना in6_addr *);
शून्य IN6_SET_ADDR_LOOPBACK(संरचना in6_addr *);
शून्य IN6ADDR_SETANY(संरचना sockaddr_in6 *);
शून्य IN6ADDR_SETLOOPBACK(संरचना sockaddr_in6 *);

#ifndef __CRT__NO_INLINE
WS2TCPIP_INLINE पूर्णाङ्क IN6_ADDR_EQUAL(ध्रुव संरचना in6_addr *a,ध्रुव संरचना in6_addr *b) { प्रत्यागम (memcmp(a,b,परिमाण(संरचना in6_addr))==0); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_UNSPECIFIED(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_शब्दगण[0]==0) && (a->s6_शब्दगण[1]==0) && (a->s6_शब्दगण[2]==0) && (a->s6_शब्दगण[3]==0) && (a->s6_शब्दगण[4]==0) && (a->s6_शब्दगण[5]==0) && (a->s6_शब्दगण[6]==0) && (a->s6_शब्दगण[7]==0)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_LOOPBACK(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_शब्दगण[0]==0) && (a->s6_शब्दगण[1]==0) && (a->s6_शब्दगण[2]==0) && (a->s6_शब्दगण[3]==0) && (a->s6_शब्दगण[4]==0) && (a->s6_शब्दगण[5]==0) && (a->s6_शब्दगण[6]==0) && (a->s6_शब्दगण[7]==0x0100)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MULTICAST(ध्रुव संरचना in6_addr *a) { प्रत्यागम (a->s6_bytes[0]==0xff); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_LINKLOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_SITELOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_V4MAPPED(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_शब्दगण[0]==0) && (a->s6_शब्दगण[1]==0) && (a->s6_शब्दगण[2]==0) && (a->s6_शब्दगण[3]==0) && (a->s6_शब्दगण[4]==0) && (a->s6_शब्दगण[5]==0xffff)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_V4COMPAT(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_शब्दगण[0]==0) && (a->s6_शब्दगण[1]==0) && (a->s6_शब्दगण[2]==0) && (a->s6_शब्दगण[3]==0) && (a->s6_शब्दगण[4]==0) && (a->s6_शब्दगण[5]==0) && !((a->s6_शब्दगण[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_NODELOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_LINKLOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_SITELOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_ORGLOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_GLOBAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
WS2TCPIP_INLINE पूर्णाङ्क IN6ADDR_ISANY(ध्रुव संरचना sockaddr_in6 *a) { प्रत्यागम ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6ADDR_ISLOOPBACK(ध्रुव संरचना sockaddr_in6 *a) { प्रत्यागम ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE शून्य IN6_SET_ADDR_UNSPECIFIED(संरचना in6_addr *a) { memset(a->s6_bytes,0,परिमाण(संरचना in6_addr)); }
WS2TCPIP_INLINE शून्य IN6_SET_ADDR_LOOPBACK(संरचना in6_addr *a) {
  memset(a->s6_bytes,0,परिमाण(संरचना in6_addr));
  a->s6_bytes[15] = 1;
}
WS2TCPIP_INLINE शून्य IN6ADDR_SETANY(संरचना sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE शून्य IN6ADDR_SETLOOPBACK(संरचना sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#endif /* !__CRT__NO_INLINE */

प्रकारनिर्देश सङ्घ sockaddr_gen {
  संरचना sockaddr Address;
  संरचना sockaddr_in AddressIn;
  संरचना sockaddr_in6_old AddressIn6;
} sockaddr_gen;

प्रकारनिर्देश संरचना _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

प्रकारनिर्देश संरचना _INTERFACE_INFO_EX {
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

प्रकारनिर्देश संरचना in_pktinfo {
  IN_ADDR ipi_addr;
  UINT ipi_ifindex;
} IN_PKTINFO;

C_ASSERT(परिमाण(IN_PKTINFO)==8);

प्रकारनिर्देश संरचना in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(परिमाण(IN6_PKTINFO)==20);

#define EAI_AGAIN WSATRY_AGAIN
#define EAI_BADFLAGS WSAEINVAL
#define EAI_FAIL WSANO_RECOVERY
#define EAI_FAMILY WSAEAFNOSUPPORT
#define EAI_MEMORY WSA_NOT_ENOUGH_MEMORY

#define EAI_NONAME WSAHOST_NOT_FOUND
#define EAI_SERVICE WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#define EAI_NODATA EAI_NONAME

प्रकारनिर्देश संरचना addrinfo {
  पूर्णाङ्क ai_flags;
  पूर्णाङ्क ai_family;
  पूर्णाङ्क ai_socktype;
  पूर्णाङ्क ai_protocol;
  size_t ai_addrlen;
  वर्ण *ai_canonname;
  संरचना sockaddr *ai_addr;
  संरचना addrinfo *ai_next;
} ADDRINFOA,*PADDRINFOA;

प्रकारनिर्देश संरचना addrinfoW {
  पूर्णाङ्क ai_flags;
  पूर्णाङ्क ai_family;
  पूर्णाङ्क ai_socktype;
  पूर्णाङ्क ai_protocol;
  size_t ai_addrlen;
  PWSTR ai_canonname;
  संरचना sockaddr *ai_addr;
  संरचना addrinfoW *ai_next;
} ADDRINFOW,*PADDRINFOW;

#ifdef UNICODE
प्रकारनिर्देश ADDRINFOW ADDRINFOT,*PADDRINFOT;
#अन्यथा
प्रकारनिर्देश ADDRINFOA ADDRINFOT,*PADDRINFOT;
#endif

प्रकारनिर्देश ADDRINFOA ADDRINFO,*LPADDRINFO;

#define AI_PASSIVE 0x1
#define AI_CANONNAME 0x2
#define AI_NUMERICHOST 0x4

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifdef UNICODE
#define GetAddrInfo GetAddrInfoW
#अन्यथा
#define GetAddrInfo GetAddrInfoA
#endif

  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI getaddrinfo(ध्रुव वर्ण *nodename,ध्रुव वर्ण *servname,ध्रुव संरचना addrinfo *hints,संरचना addrinfo **res);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI GetAddrInfoW(PCWSTR p_गाँठ_Name,PCWSTR pServiceName,ध्रुव ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define GetAddrInfoA getaddrinfo

#यदि INCL_WINSOCK_API_TYPEDEFS
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETADDRINFO)(ध्रुव वर्ण *nodename,ध्रुव वर्ण *servname,ध्रुव संरचना addrinfo *hints,संरचना addrinfo **res);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_गाँठ_Name,PCWSTR pServiceName,ध्रुव ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ifdef UNICODE
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#अन्यथा
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#endif
#endif

#ifdef UNICODE
#define FreeAddrInfo FreeAddrInfoW
#अन्यथा
#define FreeAddrInfo FreeAddrInfoA
#endif

  WINSOCK_API_LINKAGE शून्य WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE शून्य WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#define FreeAddrInfoA freeaddrinfo

#यदि INCL_WINSOCK_API_TYPEDEFS
  प्रकारनिर्देश शून्य (WSAAPI *LPFN_FREEADDRINFO)(संरचना addrinfo *ai);
  प्रकारनिर्देश शून्य (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ifdef UNICODE
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#अन्यथा
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#endif
#endif

#pragma धकेलो_macro("socklen_t")
#undef socklen_t

  प्रकारनिर्देश पूर्णाङ्क socklen_t;

#ifdef UNICODE
#define GetNameInfo GetNameInfoW
#अन्यथा
#define GetNameInfo GetNameInfoA
#endif

  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI getnameinfo(ध्रुव संरचना sockaddr *sa,socklen_t salen,वर्ण *host,DWORD hostlen,वर्ण *serv,DWORD servlen,पूर्णाङ्क flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ध्रुव SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_गाँठ_Buffer,DWORD गाँठ_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define GetNameInfoA getnameinfo

#यदि INCL_WINSOCK_API_TYPEDEFS
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETNAMEINFO)(ध्रुव संरचना sockaddr *sa,socklen_t salen,वर्ण *host,DWORD hostlen,वर्ण *serv,DWORD servlen,पूर्णाङ्क flags);
  प्रकारनिर्देश INT (WSAAPI *LPFN_GETNAMEINFOW)(ध्रुव SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_गाँठ_Buffer,DWORD गाँठ_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ifdef UNICODE
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#अन्यथा
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#endif
#endif

#pragma निकालो_macro("socklen_t")

#ifdef UNICODE
#define gai_strerror gai_strerrorW
#अन्यथा
#define gai_strerror gai_strerrorA
#endif

#define GAI_STRERROR_BUFFER_SIZE 1024

वर्ण *gai_strerrorA (पूर्णाङ्क);
WCHAR *gai_strerrorW(पूर्णाङ्क);

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
