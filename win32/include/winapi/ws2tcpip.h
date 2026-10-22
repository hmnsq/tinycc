/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _WS2TCPIP_H
#وصف_ڪريو _WS2TCPIP_H

#إذا __GNUC__ >=3
#هدايت GCC system_سرو
#جيڪڏهن_پورو

#ضمن <ws2ipdef.h>

بنية ip_msfilter {
  بنية اندريون_addr imsf_multiaddr;
  بنية اندريون_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  بنية اندريون_addr imsf_slist[1];
};

#وصف_ڪريو IP_MSFILTER_سائيز(numsrc) (حجم(بنية ip_msfilter)-حجم(بنية اندريون_addr) + (numsrc)*حجم(بنية اندريون_addr))

#وصف_ڪريو MCAST_INCLUDE 0
#وصف_ڪريو MCAST_EXCLUDE 1

#وصف_ڪريو SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#وصف_ڪريو SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#وصف_ڪريو SIO_سيٽ_MULTICAST_FILTER _IOW('t',125,u_long)
#وصف_ڪريو SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_اندريون,u_long)

#وصف_ڪريو IP_OPTIONS 1
#وصف_ڪريو IP_HDRINCL 2
#وصف_ڪريو IP_TOS 3
#وصف_ڪريو IP_TTL 4
#وصف_ڪريو IP_MULTICAST_IF 9
#وصف_ڪريو IP_MULTICAST_TTL 10
#وصف_ڪريو IP_MULTICAST_LOOP 11
#وصف_ڪريو IP_جوڙيو_MEMBERSHIP 12
#وصف_ڪريو IP_DROP_MEMBERSHIP 13
#وصف_ڪريو IP_DONTFRAGMENT 14
#وصف_ڪريو IP_جوڙيو_ذريعو_MEMBERSHIP 15
#وصف_ڪريو IP_DROP_ذريعو_MEMBERSHIP 16
#وصف_ڪريو IP_بلاڪ_ذريعو 17
#وصف_ڪريو IP_UNBLOCK_ذريعو 18
#وصف_ڪريو IP_PKTINFO 19
#وصف_ڪريو IP_RECEIVE_نشر 22

#وصف_ڪريو IPV6_HDRINCL 2
#وصف_ڪريو IPV6_UNICAST_HOPS 4
#وصف_ڪريو IPV6_MULTICAST_IF 9
#وصف_ڪريو IPV6_MULTICAST_HOPS 10
#وصف_ڪريو IPV6_MULTICAST_LOOP 11
#وصف_ڪريو IPV6_جوڙيو_MEMBERSHIP 12
#وصف_ڪريو IPV6_DROP_MEMBERSHIP 13
#وصف_ڪريو IPV6_JOIN_گروهه IPV6_جوڙيو_MEMBERSHIP
#وصف_ڪريو IPV6_LEAVE_گروهه IPV6_DROP_MEMBERSHIP
#وصف_ڪريو IPV6_PKTINFO 19
#وصف_ڪريو IPV6_HOPLIMIT 21
#وصف_ڪريو IPV6_PROTECTION_LEVEL 23

#وصف_ڪريو PROTECTION_LEVEL_UNRESTRICTED 10
#وصف_ڪريو PROTECTION_LEVEL_DEFAULT 20
#وصف_ڪريو PROTECTION_LEVEL_RESTRICTED 30

#وصف_ڪريو UDP_NOCHECKSUM 1
#وصف_ڪريو UDP_CHECKSUM_COVERAGE 20

#وصف_ڪريو TCP_EXPEDITED_1122 0x0002

#جيڪڏهن_وصف_نه_ٿيل s6_addr

بنية in6_addr {
  __MINGW_EXTENSION اتحاد {
    u_char Byte[16];
    u_short لفظ_2[8];
  } u;
};

#وصف_ڪريو اندريون_addr6 in6_addr

#وصف_ڪريو _S6_un u
#وصف_ڪريو _S6_u8 Byte
#وصف_ڪريو s6_addr _S6_un._S6_u8

#وصف_ڪريو s6_بائيٽون u.Byte
#وصف_ڪريو s6_لفظ u.لفظ_2
#جيڪڏهن_پورو

تعريفنوع بنية ipv6_mreq {
  بنية in6_addr ipv6mr_multiaddr;
  بنانشان صحيح ipv6mr_interface;
} IPV6_MREQ;

بنية sockaddr_in6_old {
  ننڍو sin6_family;
  u_short sin6_پورٽ;
  u_long sin6_flowinfo;
  بنية in6_addr sin6_addr;
};

بنية sockaddr_in6 {
  ننڍو sin6_family;
  u_short sin6_پورٽ;
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

#وصف_ڪريو SS_پورٽ(ssp) (((بنية sockaddr_اندريون*)(ssp))->sin_پورٽ)

#وصف_ڪريو IN6ADDR_ANY_INIT { 0 }
#وصف_ڪريو IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  خارجي ثابت بنية in6_addr in6addr_any;
  خارجي ثابت بنية in6_addr in6addr_loopback;

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#وصف_ڪريو WS2TCPIP_INLINE __CRT_INLINE

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
فراغ IN6_سيٽ_ADDR_UNSPECIFIED(بنية in6_addr *);
فراغ IN6_سيٽ_ADDR_LOOPBACK(بنية in6_addr *);
فراغ IN6ADDR_SETANY(بنية sockaddr_in6 *);
فراغ IN6ADDR_SETLOOPBACK(بنية sockaddr_in6 *);

#جيڪڏهن_وصف_نه_ٿيل __CRT__NO_INLINE
WS2TCPIP_INLINE صحيح IN6_ADDR_EQUAL(ثابت بنية in6_addr *a,ثابت بنية in6_addr *b) { أرجع (memcmp(a,b,حجم(بنية in6_addr))==0); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_UNSPECIFIED(ثابت بنية in6_addr *a) { أرجع ((a->s6_لفظ[0]==0) && (a->s6_لفظ[1]==0) && (a->s6_لفظ[2]==0) && (a->s6_لفظ[3]==0) && (a->s6_لفظ[4]==0) && (a->s6_لفظ[5]==0) && (a->s6_لفظ[6]==0) && (a->s6_لفظ[7]==0)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_LOOPBACK(ثابت بنية in6_addr *a) { أرجع ((a->s6_لفظ[0]==0) && (a->s6_لفظ[1]==0) && (a->s6_لفظ[2]==0) && (a->s6_لفظ[3]==0) && (a->s6_لفظ[4]==0) && (a->s6_لفظ[5]==0) && (a->s6_لفظ[6]==0) && (a->s6_لفظ[7]==0x0100)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MULTICAST(ثابت بنية in6_addr *a) { أرجع (a->s6_بائيٽون[0]==0xff); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_LINKLOCAL(ثابت بنية in6_addr *a) { أرجع ((a->s6_بائيٽون[0]==0xfe) && ((a->s6_بائيٽون[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_SITELOCAL(ثابت بنية in6_addr *a) { أرجع ((a->s6_بائيٽون[0]==0xfe) && ((a->s6_بائيٽون[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_V4MAPPED(ثابت بنية in6_addr *a) { أرجع ((a->s6_لفظ[0]==0) && (a->s6_لفظ[1]==0) && (a->s6_لفظ[2]==0) && (a->s6_لفظ[3]==0) && (a->s6_لفظ[4]==0) && (a->s6_لفظ[5]==0xffff)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_V4COMPAT(ثابت بنية in6_addr *a) { أرجع ((a->s6_لفظ[0]==0) && (a->s6_لفظ[1]==0) && (a->s6_لفظ[2]==0) && (a->s6_لفظ[3]==0) && (a->s6_لفظ[4]==0) && (a->s6_لفظ[5]==0) && !((a->s6_لفظ[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_NODELOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائيٽون[1] & 0xf)==1); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_LINKLOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائيٽون[1] & 0xf)==2); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_SITELOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائيٽون[1] & 0xf)==5); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_ORGLOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائيٽون[1] & 0xf)==8); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_GLOBAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائيٽون[1] & 0xf)==0xe); }
WS2TCPIP_INLINE صحيح IN6ADDR_ISANY(ثابت بنية sockaddr_in6 *a) { أرجع ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE صحيح IN6ADDR_ISLOOPBACK(ثابت بنية sockaddr_in6 *a) { أرجع ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE فراغ IN6_سيٽ_ADDR_UNSPECIFIED(بنية in6_addr *a) { memset(a->s6_بائيٽون,0,حجم(بنية in6_addr)); }
WS2TCPIP_INLINE فراغ IN6_سيٽ_ADDR_LOOPBACK(بنية in6_addr *a) {
  memset(a->s6_بائيٽون,0,حجم(بنية in6_addr));
  a->s6_بائيٽون[15] = 1;
}
WS2TCPIP_INLINE فراغ IN6ADDR_SETANY(بنية sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورٽ = 0;
  a->sin6_flowinfo = 0;
  IN6_سيٽ_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE فراغ IN6ADDR_SETLOOPBACK(بنية sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورٽ = 0;
  a->sin6_flowinfo = 0;
  IN6_سيٽ_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#جيڪڏهن_پورو /* !__CRT__NO_INLINE */

تعريفنوع اتحاد sockaddr_gen {
  بنية sockaddr پتو_2;
  بنية sockaddr_اندريون پتو_اندريون;
  بنية sockaddr_in6_old پتو_In6;
} sockaddr_gen;

تعريفنوع بنية _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen ii_پتو;
  sockaddr_gen ii_نشر_پتو;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

تعريفنوع بنية _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_پتو_2 ii_پتو;
  SOCKET_پتو_2 ii_نشر_پتو;
  SOCKET_پتو_2 iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#وصف_ڪريو IFF_مٿي 0x00000001
#وصف_ڪريو IFF_نشر 0x00000002
#وصف_ڪريو IFF_LOOPBACK 0x00000004
#وصف_ڪريو IFF_POINTTOPOINT 0x00000008
#وصف_ڪريو IFF_MULTICAST 0x00000010

تعريفنوع بنية اندريون_pktinfo {
  اندريون_ADDR ipi_addr;
  UINT ipi_ifindex;
} اندريون_PKTINFO;

C_ASSERT(حجم(اندريون_PKTINFO)==8);

تعريفنوع بنية in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(حجم(IN6_PKTINFO)==20);

#وصف_ڪريو EAI_AGAIN WSATRY_AGAIN
#وصف_ڪريو EAI_BADFLAGS WSAEINVAL
#وصف_ڪريو EAI_FAIL WSANO_RECOVERY
#وصف_ڪريو EAI_FAMILY WSAEAFNOSUPPORT
#وصف_ڪريو EAI_يادگيري WSA_NOT_ENOUGH_يادگيري

#وصف_ڪريو EAI_NONAME WSAHOST_NOT_مليو
#وصف_ڪريو EAI_SERVICE WSATYPE_NOT_مليو
#وصف_ڪريو EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#وصف_ڪريو EAI_NODATA EAI_NONAME

تعريفنوع بنية addrinfo {
  صحيح ai_flags;
  صحيح ai_family;
  صحيح ai_socktype;
  صحيح ai_protocol;
  سائيز_t ai_addrlen;
  حرف *ai_canonname;
  بنية sockaddr *ai_addr;
  بنية addrinfo *ai_ايندڙ;
} ADDRINFOA,*PADDRINFOA;

تعريفنوع بنية addrinfoW {
  صحيح ai_flags;
  صحيح ai_family;
  صحيح ai_socktype;
  صحيح ai_protocol;
  سائيز_t ai_addrlen;
  PWSTR ai_canonname;
  بنية sockaddr *ai_addr;
  بنية addrinfoW *ai_ايندڙ;
} ADDRINFOW,*PADDRINFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
تعريفنوع ADDRINFOW ADDRINFOT,*PADDRINFOT;
#وإلا
تعريفنوع ADDRINFOA ADDRINFOT,*PADDRINFOT;
#جيڪڏهن_پورو

تعريفنوع ADDRINFOA ADDRINFO,*LPADDRINFO;

#وصف_ڪريو AI_PASSIVE 0x1
#وصف_ڪريو AI_CANONNAME 0x2
#وصف_ڪريو AI_NUMERICHOST 0x4

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetAddrInfo GetAddrInfoW
#وإلا
#وصف_ڪريو GetAddrInfo GetAddrInfoA
#جيڪڏهن_پورو

  WINSOCK_API_LINKAGE صحيح WSAAPI getaddrinfo(ثابت حرف *nodename,ثابت حرف *servname,ثابت بنية addrinfo *hints,بنية addrinfo **res);
  WINSOCK_API_LINKAGE صحيح WSAAPI GetAddrInfoW(PCWSTR p_ڳنڍ_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_نتيجو);

#وصف_ڪريو GetAddrInfoA getaddrinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع صحيح (WSAAPI *LPFN_GETADDRINFO)(ثابت حرف *nodename,ثابت حرف *servname,ثابت بنية addrinfo *hints,بنية addrinfo **res);
  تعريفنوع صحيح (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_ڳنڍ_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_نتيجو);

#وصف_ڪريو LPFN_GETADDRINFOA LPFN_GETADDRINFO

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#وإلا
#وصف_ڪريو LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو FreeAddrInfo FreeAddrInfoW
#وإلا
#وصف_ڪريو FreeAddrInfo FreeAddrInfoA
#جيڪڏهن_پورو

  WINSOCK_API_LINKAGE فراغ WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE فراغ WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#وصف_ڪريو FreeAddrInfoA freeaddrinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع فراغ (WSAAPI *LPFN_FREEADDRINFO)(بنية addrinfo *ai);
  تعريفنوع فراغ (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#وصف_ڪريو LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#وإلا
#وصف_ڪريو LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#هدايت ڌڪو_macro("socklen_t")
#وصف_رد socklen_t

  تعريفنوع صحيح socklen_t;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetNameInfo GetNameInfoW
#وإلا
#وصف_ڪريو GetNameInfo GetNameInfoA
#جيڪڏهن_پورو

  WINSOCK_API_LINKAGE صحيح WSAAPI getnameinfo(ثابت بنية sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحيح flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_ڊيگهائي,PWCHAR p_ڳنڍ_بفر,DWORD ڳنڍ_بفر_سائيز,PWCHAR p_Service_بفر,DWORD Service_بفر_سائيز,INT Flags);

#وصف_ڪريو GetNameInfoA getnameinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع صحيح (WSAAPI *LPFN_GETNAMEINFO)(ثابت بنية sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحيح flags);
  تعريفنوع INT (WSAAPI *LPFN_GETNAMEINFOW)(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_ڊيگهائي,PWCHAR p_ڳنڍ_بفر,DWORD ڳنڍ_بفر_سائيز,PWCHAR p_Service_بفر,DWORD Service_بفر_سائيز,INT Flags);

#وصف_ڪريو LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#وإلا
#وصف_ڪريو LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#هدايت ڪڍو_macro("socklen_t")

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو gai_strerror gai_strerrorW
#وإلا
#وصف_ڪريو gai_strerror gai_strerrorA
#جيڪڏهن_پورو

#وصف_ڪريو GAI_STRERROR_بفر_سائيز 1024

حرف *gai_strerrorA (صحيح);
WCHAR *gai_strerrorW(صحيح);

#وصف_ڪريو NI_MAXHOST 1025
#وصف_ڪريو NI_MAXSERV 32

#وصف_ڪريو INET_ADDRSTRLEN 22
#وصف_ڪريو INET6_ADDRSTRLEN 65

#وصف_ڪريو NI_NOFQDN 0x01
#وصف_ڪريو NI_NUMERICHOST 0x02
#وصف_ڪريو NI_NAMEREQD 0x04
#وصف_ڪريو NI_NUMERICSERV 0x08
#وصف_ڪريو NI_DGRAM 0x10

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو
