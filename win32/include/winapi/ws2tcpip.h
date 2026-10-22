/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _WS2TCPIP_H
#تعریف_کړه _WS2TCPIP_H

#إذا __GNUC__ >=3
#لارښوونه GCC system_سرلیک
#د_که_پای

#ضمن <ws2ipdef.h>

بنية ip_msfilter {
  بنية دننه_addr imsf_multiaddr;
  بنية دننه_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  بنية دننه_addr imsf_slist[1];
};

#تعریف_کړه IP_MSFILTER_اندازه(numsrc) (حجم(بنية ip_msfilter)-حجم(بنية دننه_addr) + (numsrc)*حجم(بنية دننه_addr))

#تعریف_کړه MCAST_INCLUDE 0
#تعریف_کړه MCAST_EXCLUDE 1

#تعریف_کړه SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#تعریف_کړه SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#تعریف_کړه SIO_سېټ_MULTICAST_FILTER _IOW('t',125,u_long)
#تعریف_کړه SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_دننه,u_long)

#تعریف_کړه IP_OPTIONS 1
#تعریف_کړه IP_HDRINCL 2
#تعریف_کړه IP_TOS 3
#تعریف_کړه IP_TTL 4
#تعریف_کړه IP_MULTICAST_IF 9
#تعریف_کړه IP_MULTICAST_TTL 10
#تعریف_کړه IP_MULTICAST_LOOP 11
#تعریف_کړه IP_جمع_کړه_MEMBERSHIP 12
#تعریف_کړه IP_DROP_MEMBERSHIP 13
#تعریف_کړه IP_DONTFRAGMENT 14
#تعریف_کړه IP_جمع_کړه_سرچینه_MEMBERSHIP 15
#تعریف_کړه IP_DROP_سرچینه_MEMBERSHIP 16
#تعریف_کړه IP_بلاک_سرچینه 17
#تعریف_کړه IP_UNBLOCK_سرچینه 18
#تعریف_کړه IP_PKTINFO 19
#تعریف_کړه IP_RECEIVE_خپرونه 22

#تعریف_کړه IPV6_HDRINCL 2
#تعریف_کړه IPV6_UNICAST_HOPS 4
#تعریف_کړه IPV6_MULTICAST_IF 9
#تعریف_کړه IPV6_MULTICAST_HOPS 10
#تعریف_کړه IPV6_MULTICAST_LOOP 11
#تعریف_کړه IPV6_جمع_کړه_MEMBERSHIP 12
#تعریف_کړه IPV6_DROP_MEMBERSHIP 13
#تعریف_کړه IPV6_JOIN_ډله IPV6_جمع_کړه_MEMBERSHIP
#تعریف_کړه IPV6_LEAVE_ډله IPV6_DROP_MEMBERSHIP
#تعریف_کړه IPV6_PKTINFO 19
#تعریف_کړه IPV6_HOPLIMIT 21
#تعریف_کړه IPV6_PROTECTION_LEVEL 23

#تعریف_کړه PROTECTION_LEVEL_UNRESTRICTED 10
#تعریف_کړه PROTECTION_LEVEL_DEFAULT 20
#تعریف_کړه PROTECTION_LEVEL_RESTRICTED 30

#تعریف_کړه UDP_NOCHECKSUM 1
#تعریف_کړه UDP_CHECKSUM_COVERAGE 20

#تعریف_کړه TCP_EXPEDITED_1122 0x0002

#که_نه_تعریف_شوی s6_addr

بنية in6_addr {
  __MINGW_EXTENSION اتحاد {
    u_char Byte[16];
    u_short کلمه_2[8];
  } u;
};

#تعریف_کړه دننه_addr6 in6_addr

#تعریف_کړه _S6_un u
#تعریف_کړه _S6_u8 Byte
#تعریف_کړه s6_addr _S6_un._S6_u8

#تعریف_کړه s6_بایټونه u.Byte
#تعریف_کړه s6_ټکي u.کلمه_2
#د_که_پای

تعريفنوع بنية ipv6_mreq {
  بنية in6_addr ipv6mr_multiaddr;
  بینښه صحيح ipv6mr_interface;
} IPV6_MREQ;

بنية sockaddr_in6_old {
  لنډ sin6_family;
  u_short sin6_پورټ;
  u_long sin6_flowinfo;
  بنية in6_addr sin6_addr;
};

بنية sockaddr_in6 {
  لنډ sin6_family;
  u_short sin6_پورټ;
  u_long sin6_flowinfo;
  بنية in6_addr sin6_addr;
  u_long sin6_scope_id;
};

تعريفنوع بنية in6_addr IN6_ADDR;
تعريفنوع بنية in6_addr *PIN6_ADDR;
تعريفنوع بنية in6_addr *LPIN6_ADDR;

تعريفنوع بنية sockaddr_in6 SOCKADDR_IN6;
تعريفنوع بنية sockaddr_in6 *PSOCKADDR_IN6;
تعريفنوع بنية sockaddr_in6 *LPSOCKADDR_IN6;

#تعریف_کړه SS_پورټ(ssp) (((بنية sockaddr_دننه*)(ssp))->sin_پورټ)

#تعریف_کړه IN6ADDR_ANY_INIT { 0 }
#تعریف_کړه IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

  خارجي ثابت بنية in6_addr in6addr_any;
  خارجي ثابت بنية in6_addr in6addr_loopback;

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#تعریف_کړه WS2TCPIP_INLINE __CRT_INLINE

صحيح IN6_ADDR_EQUAL(ثابت بنية in6_addr *,ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_UNSPECIFIED(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_LOOPBACK(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_MULTICAST(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_LINKLOCAL(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_SITELOCAL(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_V4MAPPED(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_V4COMPAT(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_MC_NODELOCAL(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_MC_LINKLOCAL(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_MC_SITELOCAL(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_MC_ORGLOCAL(ثابت بنية in6_addr *);
صحيح IN6_IS_ADDR_MC_GLOBAL(ثابت بنية in6_addr *);
صحيح IN6ADDR_ISANY(ثابت بنية sockaddr_in6 *);
صحيح IN6ADDR_ISLOOPBACK(ثابت بنية sockaddr_in6 *);
فراغ IN6_سېټ_ADDR_UNSPECIFIED(بنية in6_addr *);
فراغ IN6_سېټ_ADDR_LOOPBACK(بنية in6_addr *);
فراغ IN6ADDR_SETANY(بنية sockaddr_in6 *);
فراغ IN6ADDR_SETLOOPBACK(بنية sockaddr_in6 *);

#که_نه_تعریف_شوی __CRT__NO_INLINE
WS2TCPIP_INLINE صحيح IN6_ADDR_EQUAL(ثابت بنية in6_addr *a,ثابت بنية in6_addr *b) { أرجع (memcmp(a,b,حجم(بنية in6_addr))==0); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_UNSPECIFIED(ثابت بنية in6_addr *a) { أرجع ((a->s6_ټکي[0]==0) && (a->s6_ټکي[1]==0) && (a->s6_ټکي[2]==0) && (a->s6_ټکي[3]==0) && (a->s6_ټکي[4]==0) && (a->s6_ټکي[5]==0) && (a->s6_ټکي[6]==0) && (a->s6_ټکي[7]==0)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_LOOPBACK(ثابت بنية in6_addr *a) { أرجع ((a->s6_ټکي[0]==0) && (a->s6_ټکي[1]==0) && (a->s6_ټکي[2]==0) && (a->s6_ټکي[3]==0) && (a->s6_ټکي[4]==0) && (a->s6_ټکي[5]==0) && (a->s6_ټکي[6]==0) && (a->s6_ټکي[7]==0x0100)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MULTICAST(ثابت بنية in6_addr *a) { أرجع (a->s6_بایټونه[0]==0xff); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_LINKLOCAL(ثابت بنية in6_addr *a) { أرجع ((a->s6_بایټونه[0]==0xfe) && ((a->s6_بایټونه[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_SITELOCAL(ثابت بنية in6_addr *a) { أرجع ((a->s6_بایټونه[0]==0xfe) && ((a->s6_بایټونه[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_V4MAPPED(ثابت بنية in6_addr *a) { أرجع ((a->s6_ټکي[0]==0) && (a->s6_ټکي[1]==0) && (a->s6_ټکي[2]==0) && (a->s6_ټکي[3]==0) && (a->s6_ټکي[4]==0) && (a->s6_ټکي[5]==0xffff)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_V4COMPAT(ثابت بنية in6_addr *a) { أرجع ((a->s6_ټکي[0]==0) && (a->s6_ټکي[1]==0) && (a->s6_ټکي[2]==0) && (a->s6_ټکي[3]==0) && (a->s6_ټکي[4]==0) && (a->s6_ټکي[5]==0) && !((a->s6_ټکي[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_NODELOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایټونه[1] & 0xf)==1); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_LINKLOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایټونه[1] & 0xf)==2); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_SITELOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایټونه[1] & 0xf)==5); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_ORGLOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایټونه[1] & 0xf)==8); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_GLOBAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایټونه[1] & 0xf)==0xe); }
WS2TCPIP_INLINE صحيح IN6ADDR_ISANY(ثابت بنية sockaddr_in6 *a) { أرجع ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE صحيح IN6ADDR_ISLOOPBACK(ثابت بنية sockaddr_in6 *a) { أرجع ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE فراغ IN6_سېټ_ADDR_UNSPECIFIED(بنية in6_addr *a) { memset(a->s6_بایټونه,0,حجم(بنية in6_addr)); }
WS2TCPIP_INLINE فراغ IN6_سېټ_ADDR_LOOPBACK(بنية in6_addr *a) {
  memset(a->s6_بایټونه,0,حجم(بنية in6_addr));
  a->s6_بایټونه[15] = 1;
}
WS2TCPIP_INLINE فراغ IN6ADDR_SETANY(بنية sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورټ = 0;
  a->sin6_flowinfo = 0;
  IN6_سېټ_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE فراغ IN6ADDR_SETLOOPBACK(بنية sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورټ = 0;
  a->sin6_flowinfo = 0;
  IN6_سېټ_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#د_که_پای /* !__CRT__NO_INLINE */

تعريفنوع اتحاد sockaddr_gen {
  بنية sockaddr پته_2;
  بنية sockaddr_دننه پته_دننه;
  بنية sockaddr_in6_old پته_In6;
} sockaddr_gen;

تعريفنوع بنية _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen ii_پته;
  sockaddr_gen ii_خپرونه_پته;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

تعريفنوع بنية _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_پته_2 ii_پته;
  SOCKET_پته_2 ii_خپرونه_پته;
  SOCKET_پته_2 iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#تعریف_کړه IFF_پورته 0x00000001
#تعریف_کړه IFF_خپرونه 0x00000002
#تعریف_کړه IFF_LOOPBACK 0x00000004
#تعریف_کړه IFF_POINTTOPOINT 0x00000008
#تعریف_کړه IFF_MULTICAST 0x00000010

تعريفنوع بنية دننه_pktinfo {
  دننه_ADDR ipi_addr;
  UINT ipi_ifindex;
} دننه_PKTINFO;

C_ASSERT(حجم(دننه_PKTINFO)==8);

تعريفنوع بنية in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(حجم(IN6_PKTINFO)==20);

#تعریف_کړه EAI_AGAIN WSATRY_AGAIN
#تعریف_کړه EAI_BADFLAGS WSAEINVAL
#تعریف_کړه EAI_FAIL WSANO_RECOVERY
#تعریف_کړه EAI_FAMILY WSAEAFNOSUPPORT
#تعریف_کړه EAI_حافظه WSA_NOT_ENOUGH_حافظه

#تعریف_کړه EAI_NONAME WSAHOST_NOT_وموندل
#تعریف_کړه EAI_SERVICE WSATYPE_NOT_وموندل
#تعریف_کړه EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#تعریف_کړه EAI_NODATA EAI_NONAME

تعريفنوع بنية addrinfo {
  صحيح ai_flags;
  صحيح ai_family;
  صحيح ai_socktype;
  صحيح ai_protocol;
  اندازه_t ai_addrlen;
  حرف *ai_canonname;
  بنية sockaddr *ai_addr;
  بنية addrinfo *ai_بل;
} ADDRINFOA,*PADDRINFOA;

تعريفنوع بنية addrinfoW {
  صحيح ai_flags;
  صحيح ai_family;
  صحيح ai_socktype;
  صحيح ai_protocol;
  اندازه_t ai_addrlen;
  PWSTR ai_canonname;
  بنية sockaddr *ai_addr;
  بنية addrinfoW *ai_بل;
} ADDRINFOW,*PADDRINFOW;

#که_تعریف_شوی UNICODE
تعريفنوع ADDRINFOW ADDRINFOT,*PADDRINFOT;
#وإلا
تعريفنوع ADDRINFOA ADDRINFOT,*PADDRINFOT;
#د_که_پای

تعريفنوع ADDRINFOA ADDRINFO,*LPADDRINFO;

#تعریف_کړه AI_PASSIVE 0x1
#تعریف_کړه AI_CANONNAME 0x2
#تعریف_کړه AI_NUMERICHOST 0x4

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه GetAddrInfo GetAddrInfoW
#وإلا
#تعریف_کړه GetAddrInfo GetAddrInfoA
#د_که_پای

  WINSOCK_API_LINKAGE صحيح WSAAPI getaddrinfo(ثابت حرف *nodename,ثابت حرف *servname,ثابت بنية addrinfo *hints,بنية addrinfo **res);
  WINSOCK_API_LINKAGE صحيح WSAAPI GetAddrInfoW(PCWSTR p_غوټه_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_پایله);

#تعریف_کړه GetAddrInfoA getaddrinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع صحيح (WSAAPI *LPFN_GETADDRINFO)(ثابت حرف *nodename,ثابت حرف *servname,ثابت بنية addrinfo *hints,بنية addrinfo **res);
  تعريفنوع صحيح (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_غوټه_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_پایله);

#تعریف_کړه LPFN_GETADDRINFOA LPFN_GETADDRINFO

#که_تعریف_شوی UNICODE
#تعریف_کړه LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#وإلا
#تعریف_کړه LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#د_که_پای
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه FreeAddrInfo FreeAddrInfoW
#وإلا
#تعریف_کړه FreeAddrInfo FreeAddrInfoA
#د_که_پای

  WINSOCK_API_LINKAGE فراغ WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE فراغ WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#تعریف_کړه FreeAddrInfoA freeaddrinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع فراغ (WSAAPI *LPFN_FREEADDRINFO)(بنية addrinfo *ai);
  تعريفنوع فراغ (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#تعریف_کړه LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#که_تعریف_شوی UNICODE
#تعریف_کړه LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#وإلا
#تعریف_کړه LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#د_که_پای
#د_که_پای

#لارښوونه ټېل_macro("socklen_t")
#تعریف_لغوه socklen_t

  تعريفنوع صحيح socklen_t;

#که_تعریف_شوی UNICODE
#تعریف_کړه GetNameInfo GetNameInfoW
#وإلا
#تعریف_کړه GetNameInfo GetNameInfoA
#د_که_پای

  WINSOCK_API_LINKAGE صحيح WSAAPI getnameinfo(ثابت بنية sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحيح flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_اوږدتیا,PWCHAR p_غوټه_بفر,DWORD غوټه_بفر_اندازه,PWCHAR p_Service_بفر,DWORD Service_بفر_اندازه,INT Flags);

#تعریف_کړه GetNameInfoA getnameinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع صحيح (WSAAPI *LPFN_GETNAMEINFO)(ثابت بنية sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحيح flags);
  تعريفنوع INT (WSAAPI *LPFN_GETNAMEINFOW)(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_اوږدتیا,PWCHAR p_غوټه_بفر,DWORD غوټه_بفر_اندازه,PWCHAR p_Service_بفر,DWORD Service_بفر_اندازه,INT Flags);

#تعریف_کړه LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#که_تعریف_شوی UNICODE
#تعریف_کړه LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#وإلا
#تعریف_کړه LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#د_که_پای
#د_که_پای

#لارښوونه راوباسه_macro("socklen_t")

#که_تعریف_شوی UNICODE
#تعریف_کړه gai_strerror gai_strerrorW
#وإلا
#تعریف_کړه gai_strerror gai_strerrorA
#د_که_پای

#تعریف_کړه GAI_STRERROR_بفر_اندازه 1024

حرف *gai_strerrorA (صحيح);
WCHAR *gai_strerrorW(صحيح);

#تعریف_کړه NI_MAXHOST 1025
#تعریف_کړه NI_MAXSERV 32

#تعریف_کړه INET_ADDRSTRLEN 22
#تعریف_کړه INET6_ADDRSTRLEN 65

#تعریف_کړه NI_NOFQDN 0x01
#تعریف_کړه NI_NUMERICHOST 0x02
#تعریف_کړه NI_NAMEREQD 0x04
#تعریف_کړه NI_NUMERICSERV 0x08
#تعریف_کړه NI_DGRAM 0x10

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#د_که_پای
