/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WS2TCPIP_H
#define _WS2TCPIP_H

#ଯଦି __GNUC__ >=3
#pragma GCC system_header
#endif

#ଅନ୍ତର୍ଭାଵ <ws2ipdef.h>

ସଂରଚନା ip_msfilter {
  ସଂରଚନା in_addr imsf_multiaddr;
  ସଂରଚନା in_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  ସଂରଚନା in_addr imsf_slist[1];
};

#define IP_MSFILTER_SIZE(numsrc) (ଆକାର(ସଂରଚନା ip_msfilter)-ଆକାର(ସଂରଚନା in_addr) + (numsrc)*ଆକାର(ସଂରଚନା in_addr))

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

ସଂରଚନା in6_addr {
  __MINGW_EXTENSION ସଂଘ {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#define in_addr6 in6_addr

#define _S6_un u
#define _S6_u8 Byte
#define s6_addr _S6_un._S6_u8

#define s6_bytes u.Byte
#define s6_ଶବ୍ଦଗୁଡ଼ିକ u.Word
#endif

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା ipv6_mreq {
  ସଂରଚନା in6_addr ipv6mr_multiaddr;
  unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା ipv6mr_interface;
} IPV6_MREQ;

ସଂରଚନା sockaddr_in6_old {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  ସଂରଚନା in6_addr sin6_addr;
};

ସଂରଚନା sockaddr_in6 {
  short sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  ସଂରଚନା in6_addr sin6_addr;
  u_long sin6_scope_id;
};

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା in6_addr IN6_ADDR;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା in6_addr *PIN6_ADDR;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା in6_addr *LPIN6_ADDR;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା sockaddr_in6 SOCKADDR_IN6;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା sockaddr_in6 *PSOCKADDR_IN6;
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା sockaddr_in6 *LPSOCKADDR_IN6;

#define SS_PORT(ssp) (((ସଂରଚନା sockaddr_in*)(ssp))->sin_port)

#define IN6ADDR_ANY_INIT { 0 }
#define IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

  ବାହ୍ୟ ଅଚଳ ସଂରଚନା in6_addr in6addr_any;
  ବାହ୍ୟ ଅଚଳ ସଂରଚନା in6_addr in6addr_loopback;

#ifdef __cplusplus
}
#endif

#define WS2TCPIP_INLINE __CRT_INLINE

ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_ADDR_EQUAL(ଅଚଳ ସଂରଚନା in6_addr *,ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_UNSPECIFIED(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_LOOPBACK(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MULTICAST(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_LINKLOCAL(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_SITELOCAL(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_V4MAPPED(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_V4COMPAT(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_NODELOCAL(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_LINKLOCAL(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_SITELOCAL(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_ORGLOCAL(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_GLOBAL(ଅଚଳ ସଂରଚନା in6_addr *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6ADDR_ISANY(ଅଚଳ ସଂରଚନା sockaddr_in6 *);
ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6ADDR_ISLOOPBACK(ଅଚଳ ସଂରଚନା sockaddr_in6 *);
ଶୂନ୍ୟ IN6_SET_ADDR_UNSPECIFIED(ସଂରଚନା in6_addr *);
ଶୂନ୍ୟ IN6_SET_ADDR_LOOPBACK(ସଂରଚନା in6_addr *);
ଶୂନ୍ୟ IN6ADDR_SETANY(ସଂରଚନା sockaddr_in6 *);
ଶୂନ୍ୟ IN6ADDR_SETLOOPBACK(ସଂରଚନା sockaddr_in6 *);

#ifndef __CRT__NO_INLINE
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_ADDR_EQUAL(ଅଚଳ ସଂରଚନା in6_addr *a,ଅଚଳ ସଂରଚନା in6_addr *b) { ଫେରନ୍ତୁ (memcmp(a,b,ଆକାର(ସଂରଚନା in6_addr))==0); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_UNSPECIFIED(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ ((a->s6_ଶବ୍ଦଗୁଡ଼ିକ[0]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[1]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[2]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[3]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[4]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[5]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[6]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[7]==0)); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_LOOPBACK(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ ((a->s6_ଶବ୍ଦଗୁଡ଼ିକ[0]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[1]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[2]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[3]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[4]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[5]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[6]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[7]==0x0100)); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MULTICAST(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ (a->s6_bytes[0]==0xff); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_LINKLOCAL(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_SITELOCAL(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_V4MAPPED(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ ((a->s6_ଶବ୍ଦଗୁଡ଼ିକ[0]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[1]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[2]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[3]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[4]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[5]==0xffff)); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_V4COMPAT(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ ((a->s6_ଶବ୍ଦଗୁଡ଼ିକ[0]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[1]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[2]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[3]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[4]==0) && (a->s6_ଶବ୍ଦଗୁଡ଼ିକ[5]==0) && !((a->s6_ଶବ୍ଦଗୁଡ଼ିକ[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_NODELOCAL(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_LINKLOCAL(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_SITELOCAL(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_ORGLOCAL(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6_IS_ADDR_MC_GLOBAL(ଅଚଳ ସଂରଚନା in6_addr *a) { ଫେରନ୍ତୁ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6ADDR_ISANY(ଅଚଳ ସଂରଚନା sockaddr_in6 *a) { ଫେରନ୍ତୁ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE ପୂର୍ଣ୍ଣସଂଖ୍ୟା IN6ADDR_ISLOOPBACK(ଅଚଳ ସଂରଚନା sockaddr_in6 *a) { ଫେରନ୍ତୁ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE ଶୂନ୍ୟ IN6_SET_ADDR_UNSPECIFIED(ସଂରଚନା in6_addr *a) { memset(a->s6_bytes,0,ଆକାର(ସଂରଚନା in6_addr)); }
WS2TCPIP_INLINE ଶୂନ୍ୟ IN6_SET_ADDR_LOOPBACK(ସଂରଚନା in6_addr *a) {
  memset(a->s6_bytes,0,ଆକାର(ସଂରଚନା in6_addr));
  a->s6_bytes[15] = 1;
}
WS2TCPIP_INLINE ଶୂନ୍ୟ IN6ADDR_SETANY(ସଂରଚନା sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE ଶୂନ୍ୟ IN6ADDR_SETLOOPBACK(ସଂରଚନା sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#endif /* !__CRT__NO_INLINE */

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂଘ sockaddr_gen {
  ସଂରଚନା sockaddr Address;
  ସଂରଚନା sockaddr_in AddressIn;
  ସଂରଚନା sockaddr_in6_old AddressIn6;
} sockaddr_gen;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _INTERFACE_INFO_EX {
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

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା in_pktinfo {
  IN_ADDR ipi_addr;
  UINT ipi_ifindex;
} IN_PKTINFO;

C_ASSERT(ଆକାର(IN_PKTINFO)==8);

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(ଆକାର(IN6_PKTINFO)==20);

#define EAI_AGAIN WSATRY_AGAIN
#define EAI_BADFLAGS WSAEINVAL
#define EAI_FAIL WSANO_RECOVERY
#define EAI_FAMILY WSAEAFNOSUPPORT
#define EAI_MEMORY WSA_NOT_ENOUGH_MEMORY

#define EAI_NONAME WSAHOST_NOT_FOUND
#define EAI_SERVICE WSATYPE_NOT_FOUND
#define EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#define EAI_NODATA EAI_NONAME

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା addrinfo {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ai_flags;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ai_family;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ai_socktype;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ai_protocol;
  size_t ai_addrlen;
  ଅକ୍ଷର *ai_canonname;
  ସଂରଚନା sockaddr *ai_addr;
  ସଂରଚନା addrinfo *ai_next;
} ADDRINFOA,*PADDRINFOA;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା addrinfoW {
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ai_flags;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ai_family;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ai_socktype;
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା ai_protocol;
  size_t ai_addrlen;
  PWSTR ai_canonname;
  ସଂରଚନା sockaddr *ai_addr;
  ସଂରଚନା addrinfoW *ai_next;
} ADDRINFOW,*PADDRINFOW;

#ifdef UNICODE
ପ୍ରକାରବ୍ୟାଖ୍ୟା ADDRINFOW ADDRINFOT,*PADDRINFOT;
#ଅନ୍ୟଥା
ପ୍ରକାରବ୍ୟାଖ୍ୟା ADDRINFOA ADDRINFOT,*PADDRINFOT;
#endif

ପ୍ରକାରବ୍ୟାଖ୍ୟା ADDRINFOA ADDRINFO,*LPADDRINFO;

#define AI_PASSIVE 0x1
#define AI_CANONNAME 0x2
#define AI_NUMERICHOST 0x4

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifdef UNICODE
#define GetAddrInfo GetAddrInfoW
#ଅନ୍ୟଥା
#define GetAddrInfo GetAddrInfoA
#endif

  WINSOCK_API_LINKAGE ପୂର୍ଣ୍ଣସଂଖ୍ୟା WSAAPI getaddrinfo(ଅଚଳ ଅକ୍ଷର *nodename,ଅଚଳ ଅକ୍ଷର *servname,ଅଚଳ ସଂରଚନା addrinfo *hints,ସଂରଚନା addrinfo **res);
  WINSOCK_API_LINKAGE ପୂର୍ଣ୍ଣସଂଖ୍ୟା WSAAPI GetAddrInfoW(PCWSTR p_ଗଣ୍ଠି_Name,PCWSTR pServiceName,ଅଚଳ ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define GetAddrInfoA getaddrinfo

#ଯଦି INCL_WINSOCK_API_TYPEDEFS
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା (WSAAPI *LPFN_GETADDRINFO)(ଅଚଳ ଅକ୍ଷର *nodename,ଅଚଳ ଅକ୍ଷର *servname,ଅଚଳ ସଂରଚନା addrinfo *hints,ସଂରଚନା addrinfo **res);
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_ଗଣ୍ଠି_Name,PCWSTR pServiceName,ଅଚଳ ADDRINFOW *pHints,PADDRINFOW *ppResult);

#define LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ifdef UNICODE
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#ଅନ୍ୟଥା
#define LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#endif
#endif

#ifdef UNICODE
#define FreeAddrInfo FreeAddrInfoW
#ଅନ୍ୟଥା
#define FreeAddrInfo FreeAddrInfoA
#endif

  WINSOCK_API_LINKAGE ଶୂନ୍ୟ WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE ଶୂନ୍ୟ WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#define FreeAddrInfoA freeaddrinfo

#ଯଦି INCL_WINSOCK_API_TYPEDEFS
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ (WSAAPI *LPFN_FREEADDRINFO)(ସଂରଚନା addrinfo *ai);
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#define LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ifdef UNICODE
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#ଅନ୍ୟଥା
#define LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#endif
#endif

#pragma ଠେଲ_macro("socklen_t")
#undef socklen_t

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା socklen_t;

#ifdef UNICODE
#define GetNameInfo GetNameInfoW
#ଅନ୍ୟଥା
#define GetNameInfo GetNameInfoA
#endif

  WINSOCK_API_LINKAGE ପୂର୍ଣ୍ଣସଂଖ୍ୟା WSAAPI getnameinfo(ଅଚଳ ସଂରଚନା sockaddr *sa,socklen_t salen,ଅକ୍ଷର *host,DWORD hostlen,ଅକ୍ଷର *serv,DWORD servlen,ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ଅଚଳ SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_ଗଣ୍ଠି_Buffer,DWORD ଗଣ୍ଠି_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define GetNameInfoA getnameinfo

#ଯଦି INCL_WINSOCK_API_TYPEDEFS
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା (WSAAPI *LPFN_GETNAMEINFO)(ଅଚଳ ସଂରଚନା sockaddr *sa,socklen_t salen,ଅକ୍ଷର *host,DWORD hostlen,ଅକ୍ଷର *serv,DWORD servlen,ପୂର୍ଣ୍ଣସଂଖ୍ୟା flags);
  ପ୍ରକାରବ୍ୟାଖ୍ୟା INT (WSAAPI *LPFN_GETNAMEINFOW)(ଅଚଳ SOCKADDR *pSockaddr,socklen_t SockaddrLength,PWCHAR p_ଗଣ୍ଠି_Buffer,DWORD ଗଣ୍ଠି_Buffer_Size,PWCHAR pServiceBuffer,DWORD ServiceBufferSize,INT Flags);

#define LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ifdef UNICODE
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#ଅନ୍ୟଥା
#define LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#endif
#endif

#pragma କାଢ଼_macro("socklen_t")

#ifdef UNICODE
#define gai_strerror gai_strerrorW
#ଅନ୍ୟଥା
#define gai_strerror gai_strerrorA
#endif

#define GAI_STRERROR_BUFFER_SIZE 1024

ଅକ୍ଷର *gai_strerrorA (ପୂର୍ଣ୍ଣସଂଖ୍ୟା);
WCHAR *gai_strerrorW(ପୂର୍ଣ୍ଣସଂଖ୍ୟା);

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
