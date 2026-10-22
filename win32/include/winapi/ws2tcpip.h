/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _WS2TCPIP_H
#تعریف_کرو _WS2TCPIP_H

#إذا __GNUC__ >=3
#ہدایت GCC system_سرخی
#جے_انت

#ضمن <ws2ipdef.h>

بنية ip_msfilter {
  بنية وچ_addr imsf_multiaddr;
  بنية وچ_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  بنية وچ_addr imsf_slist[1];
};

#تعریف_کرو IP_MSFILTER_ناپ(numsrc) (حجم(بنية ip_msfilter)-حجم(بنية وچ_addr) + (numsrc)*حجم(بنية وچ_addr))

#تعریف_کرو MCAST_INCLUDE 0
#تعریف_کرو MCAST_EXCLUDE 1

#تعریف_کرو SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#تعریف_کرو SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#تعریف_کرو SIO_سیٹ_MULTICAST_FILTER _IOW('t',125,u_long)
#تعریف_کرو SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_وچ,u_long)

#تعریف_کرو IP_OPTIONS 1
#تعریف_کرو IP_HDRINCL 2
#تعریف_کرو IP_TOS 3
#تعریف_کرو IP_TTL 4
#تعریف_کرو IP_MULTICAST_IF 9
#تعریف_کرو IP_MULTICAST_TTL 10
#تعریف_کرو IP_MULTICAST_LOOP 11
#تعریف_کرو IP_جوڑو_MEMBERSHIP 12
#تعریف_کرو IP_DROP_MEMBERSHIP 13
#تعریف_کرو IP_DONTFRAGMENT 14
#تعریف_کرو IP_جوڑو_سروت_MEMBERSHIP 15
#تعریف_کرو IP_DROP_سروت_MEMBERSHIP 16
#تعریف_کرو IP_بلاک_سروت 17
#تعریف_کرو IP_UNBLOCK_سروت 18
#تعریف_کرو IP_PKTINFO 19
#تعریف_کرو IP_RECEIVE_نشر 22

#تعریف_کرو IPV6_HDRINCL 2
#تعریف_کرو IPV6_UNICAST_HOPS 4
#تعریف_کرو IPV6_MULTICAST_IF 9
#تعریف_کرو IPV6_MULTICAST_HOPS 10
#تعریف_کرو IPV6_MULTICAST_LOOP 11
#تعریف_کرو IPV6_جوڑو_MEMBERSHIP 12
#تعریف_کرو IPV6_DROP_MEMBERSHIP 13
#تعریف_کرو IPV6_JOIN_گروہ IPV6_جوڑو_MEMBERSHIP
#تعریف_کرو IPV6_LEAVE_گروہ IPV6_DROP_MEMBERSHIP
#تعریف_کرو IPV6_PKTINFO 19
#تعریف_کرو IPV6_HOPLIMIT 21
#تعریف_کرو IPV6_PROTECTION_LEVEL 23

#تعریف_کرو PROTECTION_LEVEL_UNRESTRICTED 10
#تعریف_کرو PROTECTION_LEVEL_DEFAULT 20
#تعریف_کرو PROTECTION_LEVEL_RESTRICTED 30

#تعریف_کرو UDP_NOCHECKSUM 1
#تعریف_کرو UDP_CHECKSUM_COVERAGE 20

#تعریف_کرو TCP_EXPEDITED_1122 0x0002

#جے_بنا_تعریف s6_addr

بنية in6_addr {
  __MINGW_EXTENSION اتحاد {
    u_char Byte[16];
    u_short لفظ_2[8];
  } u;
};

#تعریف_کرو وچ_addr6 in6_addr

#تعریف_کرو _S6_un u
#تعریف_کرو _S6_u8 Byte
#تعریف_کرو s6_addr _S6_un._S6_u8

#تعریف_کرو s6_بائٹاں u.Byte
#تعریف_کرو s6_الفاظ u.لفظ_2
#جے_انت

تعريفنوع بنية ipv6_mreq {
  بنية in6_addr ipv6mr_multiaddr;
  بنانشانی صحيح ipv6mr_interface;
} IPV6_MREQ;

بنية sockaddr_in6_old {
  چھوٹا sin6_family;
  u_short sin6_پورٹ;
  u_long sin6_flowinfo;
  بنية in6_addr sin6_addr;
};

بنية sockaddr_in6 {
  چھوٹا sin6_family;
  u_short sin6_پورٹ;
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

#تعریف_کرو SS_پورٹ(ssp) (((بنية sockaddr_وچ*)(ssp))->sin_پورٹ)

#تعریف_کرو IN6ADDR_ANY_INIT { 0 }
#تعریف_کرو IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  خارجي ثابت بنية in6_addr in6addr_any;
  خارجي ثابت بنية in6_addr in6addr_loopback;

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#تعریف_کرو WS2TCPIP_INLINE __CRT_INLINE

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
فراغ IN6_سیٹ_ADDR_UNSPECIFIED(بنية in6_addr *);
فراغ IN6_سیٹ_ADDR_LOOPBACK(بنية in6_addr *);
فراغ IN6ADDR_SETANY(بنية sockaddr_in6 *);
فراغ IN6ADDR_SETLOOPBACK(بنية sockaddr_in6 *);

#جے_بنا_تعریف __CRT__NO_INLINE
WS2TCPIP_INLINE صحيح IN6_ADDR_EQUAL(ثابت بنية in6_addr *a,ثابت بنية in6_addr *b) { أرجع (memcmp(a,b,حجم(بنية in6_addr))==0); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_UNSPECIFIED(ثابت بنية in6_addr *a) { أرجع ((a->s6_الفاظ[0]==0) && (a->s6_الفاظ[1]==0) && (a->s6_الفاظ[2]==0) && (a->s6_الفاظ[3]==0) && (a->s6_الفاظ[4]==0) && (a->s6_الفاظ[5]==0) && (a->s6_الفاظ[6]==0) && (a->s6_الفاظ[7]==0)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_LOOPBACK(ثابت بنية in6_addr *a) { أرجع ((a->s6_الفاظ[0]==0) && (a->s6_الفاظ[1]==0) && (a->s6_الفاظ[2]==0) && (a->s6_الفاظ[3]==0) && (a->s6_الفاظ[4]==0) && (a->s6_الفاظ[5]==0) && (a->s6_الفاظ[6]==0) && (a->s6_الفاظ[7]==0x0100)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MULTICAST(ثابت بنية in6_addr *a) { أرجع (a->s6_بائٹاں[0]==0xff); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_LINKLOCAL(ثابت بنية in6_addr *a) { أرجع ((a->s6_بائٹاں[0]==0xfe) && ((a->s6_بائٹاں[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_SITELOCAL(ثابت بنية in6_addr *a) { أرجع ((a->s6_بائٹاں[0]==0xfe) && ((a->s6_بائٹاں[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_V4MAPPED(ثابت بنية in6_addr *a) { أرجع ((a->s6_الفاظ[0]==0) && (a->s6_الفاظ[1]==0) && (a->s6_الفاظ[2]==0) && (a->s6_الفاظ[3]==0) && (a->s6_الفاظ[4]==0) && (a->s6_الفاظ[5]==0xffff)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_V4COMPAT(ثابت بنية in6_addr *a) { أرجع ((a->s6_الفاظ[0]==0) && (a->s6_الفاظ[1]==0) && (a->s6_الفاظ[2]==0) && (a->s6_الفاظ[3]==0) && (a->s6_الفاظ[4]==0) && (a->s6_الفاظ[5]==0) && !((a->s6_الفاظ[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_NODELOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹاں[1] & 0xf)==1); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_LINKLOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹاں[1] & 0xf)==2); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_SITELOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹاں[1] & 0xf)==5); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_ORGLOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹاں[1] & 0xf)==8); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_GLOBAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹاں[1] & 0xf)==0xe); }
WS2TCPIP_INLINE صحيح IN6ADDR_ISANY(ثابت بنية sockaddr_in6 *a) { أرجع ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE صحيح IN6ADDR_ISLOOPBACK(ثابت بنية sockaddr_in6 *a) { أرجع ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE فراغ IN6_سیٹ_ADDR_UNSPECIFIED(بنية in6_addr *a) { memset(a->s6_بائٹاں,0,حجم(بنية in6_addr)); }
WS2TCPIP_INLINE فراغ IN6_سیٹ_ADDR_LOOPBACK(بنية in6_addr *a) {
  memset(a->s6_بائٹاں,0,حجم(بنية in6_addr));
  a->s6_بائٹاں[15] = 1;
}
WS2TCPIP_INLINE فراغ IN6ADDR_SETANY(بنية sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورٹ = 0;
  a->sin6_flowinfo = 0;
  IN6_سیٹ_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE فراغ IN6ADDR_SETLOOPBACK(بنية sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورٹ = 0;
  a->sin6_flowinfo = 0;
  IN6_سیٹ_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#جے_انت /* !__CRT__NO_INLINE */

تعريفنوع اتحاد sockaddr_gen {
  بنية sockaddr پتہ_2;
  بنية sockaddr_وچ پتہ_وچ;
  بنية sockaddr_in6_old پتہ_In6;
} sockaddr_gen;

تعريفنوع بنية _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen ii_پتہ;
  sockaddr_gen ii_نشر_پتہ;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

تعريفنوع بنية _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_پتہ_2 ii_پتہ;
  SOCKET_پتہ_2 ii_نشر_پتہ;
  SOCKET_پتہ_2 iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#تعریف_کرو IFF_اتے 0x00000001
#تعریف_کرو IFF_نشر 0x00000002
#تعریف_کرو IFF_LOOPBACK 0x00000004
#تعریف_کرو IFF_POINTTOPOINT 0x00000008
#تعریف_کرو IFF_MULTICAST 0x00000010

تعريفنوع بنية وچ_pktinfo {
  وچ_ADDR ipi_addr;
  UINT ipi_ifindex;
} وچ_PKTINFO;

C_ASSERT(حجم(وچ_PKTINFO)==8);

تعريفنوع بنية in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(حجم(IN6_PKTINFO)==20);

#تعریف_کرو EAI_AGAIN WSATRY_AGAIN
#تعریف_کرو EAI_BADFLAGS WSAEINVAL
#تعریف_کرو EAI_FAIL WSANO_RECOVERY
#تعریف_کرو EAI_FAMILY WSAEAFNOSUPPORT
#تعریف_کرو EAI_حافظہ WSA_NOT_ENOUGH_حافظہ

#تعریف_کرو EAI_NONAME WSAHOST_NOT_لبھیا
#تعریف_کرو EAI_SERVICE WSATYPE_NOT_لبھیا
#تعریف_کرو EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#تعریف_کرو EAI_NODATA EAI_NONAME

تعريفنوع بنية addrinfo {
  صحيح ai_flags;
  صحيح ai_family;
  صحيح ai_socktype;
  صحيح ai_protocol;
  ناپ_t ai_addrlen;
  حرف *ai_canonname;
  بنية sockaddr *ai_addr;
  بنية addrinfo *ai_اگلا;
} ADDRINFOA,*PADDRINFOA;

تعريفنوع بنية addrinfoW {
  صحيح ai_flags;
  صحيح ai_family;
  صحيح ai_socktype;
  صحيح ai_protocol;
  ناپ_t ai_addrlen;
  PWSTR ai_canonname;
  بنية sockaddr *ai_addr;
  بنية addrinfoW *ai_اگلا;
} ADDRINFOW,*PADDRINFOW;

#جے_تعریف_شدہ UNICODE
تعريفنوع ADDRINFOW ADDRINFOT,*PADDRINFOT;
#وإلا
تعريفنوع ADDRINFOA ADDRINFOT,*PADDRINFOT;
#جے_انت

تعريفنوع ADDRINFOA ADDRINFO,*LPADDRINFO;

#تعریف_کرو AI_PASSIVE 0x1
#تعریف_کرو AI_CANONNAME 0x2
#تعریف_کرو AI_NUMERICHOST 0x4

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو GetAddrInfo GetAddrInfoW
#وإلا
#تعریف_کرو GetAddrInfo GetAddrInfoA
#جے_انت

  WINSOCK_API_LINKAGE صحيح WSAAPI getaddrinfo(ثابت حرف *nodename,ثابت حرف *servname,ثابت بنية addrinfo *hints,بنية addrinfo **res);
  WINSOCK_API_LINKAGE صحيح WSAAPI GetAddrInfoW(PCWSTR p_گرہ_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_نتیجہ);

#تعریف_کرو GetAddrInfoA getaddrinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع صحيح (WSAAPI *LPFN_GETADDRINFO)(ثابت حرف *nodename,ثابت حرف *servname,ثابت بنية addrinfo *hints,بنية addrinfo **res);
  تعريفنوع صحيح (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_گرہ_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_نتیجہ);

#تعریف_کرو LPFN_GETADDRINFOA LPFN_GETADDRINFO

#جے_تعریف_شدہ UNICODE
#تعریف_کرو LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#وإلا
#تعریف_کرو LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#جے_انت
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو FreeAddrInfo FreeAddrInfoW
#وإلا
#تعریف_کرو FreeAddrInfo FreeAddrInfoA
#جے_انت

  WINSOCK_API_LINKAGE فراغ WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE فراغ WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#تعریف_کرو FreeAddrInfoA freeaddrinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع فراغ (WSAAPI *LPFN_FREEADDRINFO)(بنية addrinfo *ai);
  تعريفنوع فراغ (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#تعریف_کرو LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#جے_تعریف_شدہ UNICODE
#تعریف_کرو LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#وإلا
#تعریف_کرو LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#جے_انت
#جے_انت

#ہدایت ڈالو_macro("socklen_t")
#تعریف_رد socklen_t

  تعريفنوع صحيح socklen_t;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو GetNameInfo GetNameInfoW
#وإلا
#تعریف_کرو GetNameInfo GetNameInfoA
#جے_انت

  WINSOCK_API_LINKAGE صحيح WSAAPI getnameinfo(ثابت بنية sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحيح flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_لمائی,PWCHAR p_گرہ_بفر,DWORD گرہ_بفر_ناپ,PWCHAR p_Service_بفر,DWORD Service_بفر_ناپ,INT Flags);

#تعریف_کرو GetNameInfoA getnameinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع صحيح (WSAAPI *LPFN_GETNAMEINFO)(ثابت بنية sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحيح flags);
  تعريفنوع INT (WSAAPI *LPFN_GETNAMEINFOW)(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_لمائی,PWCHAR p_گرہ_بفر,DWORD گرہ_بفر_ناپ,PWCHAR p_Service_بفر,DWORD Service_بفر_ناپ,INT Flags);

#تعریف_کرو LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#جے_تعریف_شدہ UNICODE
#تعریف_کرو LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#وإلا
#تعریف_کرو LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#جے_انت
#جے_انت

#ہدایت نکالو_macro("socklen_t")

#جے_تعریف_شدہ UNICODE
#تعریف_کرو gai_strerror gai_strerrorW
#وإلا
#تعریف_کرو gai_strerror gai_strerrorA
#جے_انت

#تعریف_کرو GAI_STRERROR_بفر_ناپ 1024

حرف *gai_strerrorA (صحيح);
WCHAR *gai_strerrorW(صحيح);

#تعریف_کرو NI_MAXHOST 1025
#تعریف_کرو NI_MAXSERV 32

#تعریف_کرو INET_ADDRSTRLEN 22
#تعریف_کرو INET6_ADDRSTRLEN 65

#تعریف_کرو NI_NOFQDN 0x01
#تعریف_کرو NI_NUMERICHOST 0x02
#تعریف_کرو NI_NAMEREQD 0x04
#تعریف_کرو NI_NUMERICSERV 0x08
#تعریف_کرو NI_DGRAM 0x10

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_انت
