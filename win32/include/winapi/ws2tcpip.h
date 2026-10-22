/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _WS2TCPIP_H
#تعریف_کرو _WS2TCPIP_H

#اگر __GNUC__ >=3
#ہدایت GCC system_سرخی
#اگر_ختم

#شامل <ws2ipdef.h>

ساخت ip_msfilter {
  ساخت اندر_addr imsf_multiaddr;
  ساخت اندر_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  ساخت اندر_addr imsf_slist[1];
};

#تعریف_کرو IP_MSFILTER_سائز(numsrc) (حجم(ساخت ip_msfilter)-حجم(ساخت اندر_addr) + (numsrc)*حجم(ساخت اندر_addr))

#تعریف_کرو MCAST_INCLUDE 0
#تعریف_کرو MCAST_EXCLUDE 1

#تعریف_کرو SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#تعریف_کرو SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#تعریف_کرو SIO_سیٹ_MULTICAST_FILTER _IOW('t',125,u_long)
#تعریف_کرو SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_اندر,u_long)

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
#تعریف_کرو IP_جوڑو_ماخذ_MEMBERSHIP 15
#تعریف_کرو IP_DROP_ماخذ_MEMBERSHIP 16
#تعریف_کرو IP_بلاک_ماخذ 17
#تعریف_کرو IP_UNBLOCK_ماخذ 18
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

#اگر_غیر_تعریف_شدہ s6_addr

ساخت in6_addr {
  __MINGW_EXTENSION اتحاد {
    u_char Byte[16];
    u_short لفظ_2[8];
  } u;
};

#تعریف_کرو اندر_addr6 in6_addr

#تعریف_کرو _S6_un u
#تعریف_کرو _S6_u8 Byte
#تعریف_کرو s6_addr _S6_un._S6_u8

#تعریف_کرو s6_بائٹیں u.Byte
#تعریف_کرو s6_الفاظ u.لفظ_2
#اگر_ختم

قسمتعریف ساخت ipv6_mreq {
  ساخت in6_addr ipv6mr_multiaddr;
  غیرعلامتی صحیح ipv6mr_interface;
} IPV6_MREQ;

ساخت sockaddr_in6_old {
  مختصر sin6_family;
  u_short sin6_پورٹ;
  u_long sin6_flowinfo;
  ساخت in6_addr sin6_addr;
};

ساخت sockaddr_in6 {
  مختصر sin6_family;
  u_short sin6_پورٹ;
  u_long sin6_flowinfo;
  ساخت in6_addr sin6_addr;
  u_long sin6_scope_id;
};

قسمتعریف ساخت in6_addr IN6_ADDR;
قسمتعریف ساخت in6_addr *PIN6_ADDR;
قسمتعریف ساخت in6_addr *LPIN6_ADDR;

قسمتعریف ساخت sockaddr_in6 SOCKADDR_IN6;
قسمتعریف ساخت sockaddr_in6 *PSOCKADDR_IN6;
قسمتعریف ساخت sockaddr_in6 *LPSOCKADDR_IN6;

#تعریف_کرو SS_پورٹ(ssp) (((ساخت sockaddr_اندر*)(ssp))->sin_پورٹ)

#تعریف_کرو IN6ADDR_ANY_INIT { 0 }
#تعریف_کرو IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

  خارجی ثابت ساخت in6_addr in6addr_any;
  خارجی ثابت ساخت in6_addr in6addr_loopback;

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#تعریف_کرو WS2TCPIP_INLINE __CRT_INLINE

صحیح IN6_ADDR_EQUAL(ثابت ساخت in6_addr *,ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_UNSPECIFIED(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_LOOPBACK(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_MULTICAST(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_LINKLOCAL(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_SITELOCAL(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_V4MAPPED(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_V4COMPAT(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_MC_NODELOCAL(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_MC_LINKLOCAL(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_MC_SITELOCAL(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_MC_ORGLOCAL(ثابت ساخت in6_addr *);
صحیح IN6_IS_ADDR_MC_GLOBAL(ثابت ساخت in6_addr *);
صحیح IN6ADDR_ISANY(ثابت ساخت sockaddr_in6 *);
صحیح IN6ADDR_ISLOOPBACK(ثابت ساخت sockaddr_in6 *);
خالی IN6_سیٹ_ADDR_UNSPECIFIED(ساخت in6_addr *);
خالی IN6_سیٹ_ADDR_LOOPBACK(ساخت in6_addr *);
خالی IN6ADDR_SETANY(ساخت sockaddr_in6 *);
خالی IN6ADDR_SETLOOPBACK(ساخت sockaddr_in6 *);

#اگر_غیر_تعریف_شدہ __CRT__NO_INLINE
WS2TCPIP_INLINE صحیح IN6_ADDR_EQUAL(ثابت ساخت in6_addr *a,ثابت ساخت in6_addr *b) { واپس (memcmp(a,b,حجم(ساخت in6_addr))==0); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_UNSPECIFIED(ثابت ساخت in6_addr *a) { واپس ((a->s6_الفاظ[0]==0) && (a->s6_الفاظ[1]==0) && (a->s6_الفاظ[2]==0) && (a->s6_الفاظ[3]==0) && (a->s6_الفاظ[4]==0) && (a->s6_الفاظ[5]==0) && (a->s6_الفاظ[6]==0) && (a->s6_الفاظ[7]==0)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_LOOPBACK(ثابت ساخت in6_addr *a) { واپس ((a->s6_الفاظ[0]==0) && (a->s6_الفاظ[1]==0) && (a->s6_الفاظ[2]==0) && (a->s6_الفاظ[3]==0) && (a->s6_الفاظ[4]==0) && (a->s6_الفاظ[5]==0) && (a->s6_الفاظ[6]==0) && (a->s6_الفاظ[7]==0x0100)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MULTICAST(ثابت ساخت in6_addr *a) { واپس (a->s6_بائٹیں[0]==0xff); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_LINKLOCAL(ثابت ساخت in6_addr *a) { واپس ((a->s6_بائٹیں[0]==0xfe) && ((a->s6_بائٹیں[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_SITELOCAL(ثابت ساخت in6_addr *a) { واپس ((a->s6_بائٹیں[0]==0xfe) && ((a->s6_بائٹیں[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_V4MAPPED(ثابت ساخت in6_addr *a) { واپس ((a->s6_الفاظ[0]==0) && (a->s6_الفاظ[1]==0) && (a->s6_الفاظ[2]==0) && (a->s6_الفاظ[3]==0) && (a->s6_الفاظ[4]==0) && (a->s6_الفاظ[5]==0xffff)); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_V4COMPAT(ثابت ساخت in6_addr *a) { واپس ((a->s6_الفاظ[0]==0) && (a->s6_الفاظ[1]==0) && (a->s6_الفاظ[2]==0) && (a->s6_الفاظ[3]==0) && (a->s6_الفاظ[4]==0) && (a->s6_الفاظ[5]==0) && !((a->s6_الفاظ[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_NODELOCAL(ثابت ساخت in6_addr *a) { واپس IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹیں[1] & 0xf)==1); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_LINKLOCAL(ثابت ساخت in6_addr *a) { واپس IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹیں[1] & 0xf)==2); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_SITELOCAL(ثابت ساخت in6_addr *a) { واپس IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹیں[1] & 0xf)==5); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_ORGLOCAL(ثابت ساخت in6_addr *a) { واپس IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹیں[1] & 0xf)==8); }
WS2TCPIP_INLINE صحیح IN6_IS_ADDR_MC_GLOBAL(ثابت ساخت in6_addr *a) { واپس IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بائٹیں[1] & 0xf)==0xe); }
WS2TCPIP_INLINE صحیح IN6ADDR_ISANY(ثابت ساخت sockaddr_in6 *a) { واپس ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE صحیح IN6ADDR_ISLOOPBACK(ثابت ساخت sockaddr_in6 *a) { واپس ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE خالی IN6_سیٹ_ADDR_UNSPECIFIED(ساخت in6_addr *a) { memset(a->s6_بائٹیں,0,حجم(ساخت in6_addr)); }
WS2TCPIP_INLINE خالی IN6_سیٹ_ADDR_LOOPBACK(ساخت in6_addr *a) {
  memset(a->s6_بائٹیں,0,حجم(ساخت in6_addr));
  a->s6_بائٹیں[15] = 1;
}
WS2TCPIP_INLINE خالی IN6ADDR_SETANY(ساخت sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورٹ = 0;
  a->sin6_flowinfo = 0;
  IN6_سیٹ_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE خالی IN6ADDR_SETLOOPBACK(ساخت sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورٹ = 0;
  a->sin6_flowinfo = 0;
  IN6_سیٹ_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#اگر_ختم /* !__CRT__NO_INLINE */

قسمتعریف اتحاد sockaddr_gen {
  ساخت sockaddr پتہ_2;
  ساخت sockaddr_اندر پتہ_اندر;
  ساخت sockaddr_in6_old پتہ_In6;
} sockaddr_gen;

قسمتعریف ساخت _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen ii_پتہ;
  sockaddr_gen ii_نشر_پتہ;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

قسمتعریف ساخت _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_پتہ_2 ii_پتہ;
  SOCKET_پتہ_2 ii_نشر_پتہ;
  SOCKET_پتہ_2 iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#تعریف_کرو IFF_اوپر 0x00000001
#تعریف_کرو IFF_نشر 0x00000002
#تعریف_کرو IFF_LOOPBACK 0x00000004
#تعریف_کرو IFF_POINTTOPOINT 0x00000008
#تعریف_کرو IFF_MULTICAST 0x00000010

قسمتعریف ساخت اندر_pktinfo {
  اندر_ADDR ipi_addr;
  UINT ipi_ifindex;
} اندر_PKTINFO;

C_ASSERT(حجم(اندر_PKTINFO)==8);

قسمتعریف ساخت in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(حجم(IN6_PKTINFO)==20);

#تعریف_کرو EAI_AGAIN WSATRY_AGAIN
#تعریف_کرو EAI_BADFLAGS WSAEINVAL
#تعریف_کرو EAI_FAIL WSANO_RECOVERY
#تعریف_کرو EAI_FAMILY WSAEAFNOSUPPORT
#تعریف_کرو EAI_حافظہ WSA_NOT_ENOUGH_حافظہ

#تعریف_کرو EAI_NONAME WSAHOST_NOT_ملا
#تعریف_کرو EAI_SERVICE WSATYPE_NOT_ملا
#تعریف_کرو EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#تعریف_کرو EAI_NODATA EAI_NONAME

قسمتعریف ساخت addrinfo {
  صحیح ai_flags;
  صحیح ai_family;
  صحیح ai_socktype;
  صحیح ai_protocol;
  سائز_t ai_addrlen;
  حرف *ai_canonname;
  ساخت sockaddr *ai_addr;
  ساخت addrinfo *ai_اگلا;
} ADDRINFOA,*PADDRINFOA;

قسمتعریف ساخت addrinfoW {
  صحیح ai_flags;
  صحیح ai_family;
  صحیح ai_socktype;
  صحیح ai_protocol;
  سائز_t ai_addrlen;
  PWSTR ai_canonname;
  ساخت sockaddr *ai_addr;
  ساخت addrinfoW *ai_اگلا;
} ADDRINFOW,*PADDRINFOW;

#اگر_تعریف_شدہ UNICODE
قسمتعریف ADDRINFOW ADDRINFOT,*PADDRINFOT;
#ورنہ
قسمتعریف ADDRINFOA ADDRINFOT,*PADDRINFOT;
#اگر_ختم

قسمتعریف ADDRINFOA ADDRINFO,*LPADDRINFO;

#تعریف_کرو AI_PASSIVE 0x1
#تعریف_کرو AI_CANONNAME 0x2
#تعریف_کرو AI_NUMERICHOST 0x4

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو GetAddrInfo GetAddrInfoW
#ورنہ
#تعریف_کرو GetAddrInfo GetAddrInfoA
#اگر_ختم

  WINSOCK_API_LINKAGE صحیح WSAAPI getaddrinfo(ثابت حرف *nodename,ثابت حرف *servname,ثابت ساخت addrinfo *hints,ساخت addrinfo **res);
  WINSOCK_API_LINKAGE صحیح WSAAPI GetAddrInfoW(PCWSTR p_گرہ_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_نتیجہ);

#تعریف_کرو GetAddrInfoA getaddrinfo

#اگر INCL_WINSOCK_API_TYPEDEFS
  قسمتعریف صحیح (WSAAPI *LPFN_GETADDRINFO)(ثابت حرف *nodename,ثابت حرف *servname,ثابت ساخت addrinfo *hints,ساخت addrinfo **res);
  قسمتعریف صحیح (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_گرہ_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_نتیجہ);

#تعریف_کرو LPFN_GETADDRINFOA LPFN_GETADDRINFO

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#ورنہ
#تعریف_کرو LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو FreeAddrInfo FreeAddrInfoW
#ورنہ
#تعریف_کرو FreeAddrInfo FreeAddrInfoA
#اگر_ختم

  WINSOCK_API_LINKAGE خالی WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE خالی WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#تعریف_کرو FreeAddrInfoA freeaddrinfo

#اگر INCL_WINSOCK_API_TYPEDEFS
  قسمتعریف خالی (WSAAPI *LPFN_FREEADDRINFO)(ساخت addrinfo *ai);
  قسمتعریف خالی (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#تعریف_کرو LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#ورنہ
#تعریف_کرو LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#اگر_ختم
#اگر_ختم

#ہدایت ڈالو_macro("socklen_t")
#تعریف_منسوخ socklen_t

  قسمتعریف صحیح socklen_t;

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو GetNameInfo GetNameInfoW
#ورنہ
#تعریف_کرو GetNameInfo GetNameInfoA
#اگر_ختم

  WINSOCK_API_LINKAGE صحیح WSAAPI getnameinfo(ثابت ساخت sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحیح flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_لمبائی,PWCHAR p_گرہ_بفر,DWORD گرہ_بفر_سائز,PWCHAR p_Service_بفر,DWORD Service_بفر_سائز,INT Flags);

#تعریف_کرو GetNameInfoA getnameinfo

#اگر INCL_WINSOCK_API_TYPEDEFS
  قسمتعریف صحیح (WSAAPI *LPFN_GETNAMEINFO)(ثابت ساخت sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحیح flags);
  قسمتعریف INT (WSAAPI *LPFN_GETNAMEINFOW)(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_لمبائی,PWCHAR p_گرہ_بفر,DWORD گرہ_بفر_سائز,PWCHAR p_Service_بفر,DWORD Service_بفر_سائز,INT Flags);

#تعریف_کرو LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#ورنہ
#تعریف_کرو LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#اگر_ختم
#اگر_ختم

#ہدایت نکالو_macro("socklen_t")

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو gai_strerror gai_strerrorW
#ورنہ
#تعریف_کرو gai_strerror gai_strerrorA
#اگر_ختم

#تعریف_کرو GAI_STRERROR_بفر_سائز 1024

حرف *gai_strerrorA (صحیح);
WCHAR *gai_strerrorW(صحیح);

#تعریف_کرو NI_MAXHOST 1025
#تعریف_کرو NI_MAXSERV 32

#تعریف_کرو INET_ADDRSTRLEN 22
#تعریف_کرو INET6_ADDRSTRLEN 65

#تعریف_کرو NI_NOFQDN 0x01
#تعریف_کرو NI_NUMERICHOST 0x02
#تعریف_کرو NI_NAMEREQD 0x04
#تعریف_کرو NI_NUMERICSERV 0x08
#تعریف_کرو NI_DGRAM 0x10

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم
