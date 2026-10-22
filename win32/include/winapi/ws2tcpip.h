/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _WS2TCPIP_H
#تعریف_کن _WS2TCPIP_H

#إذا __GNUC__ >=3
#رهنمود GCC system_سرآیند
#پایان_اگر

#ضمن <ws2ipdef.h>

بنية ip_msfilter {
  بنية درون_addr imsf_multiaddr;
  بنية درون_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  بنية درون_addr imsf_slist[1];
};

#تعریف_کن IP_MSFILTER_اندازه(numsrc) (حجم(بنية ip_msfilter)-حجم(بنية درون_addr) + (numsrc)*حجم(بنية درون_addr))

#تعریف_کن MCAST_INCLUDE 0
#تعریف_کن MCAST_EXCLUDE 1

#تعریف_کن SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#تعریف_کن SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#تعریف_کن SIO_مجموعه_MULTICAST_FILTER _IOW('t',125,u_long)
#تعریف_کن SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_درون,u_long)

#تعریف_کن IP_OPTIONS 1
#تعریف_کن IP_HDRINCL 2
#تعریف_کن IP_TOS 3
#تعریف_کن IP_TTL 4
#تعریف_کن IP_MULTICAST_IF 9
#تعریف_کن IP_MULTICAST_TTL 10
#تعریف_کن IP_MULTICAST_LOOP 11
#تعریف_کن IP_جمع_کن_MEMBERSHIP 12
#تعریف_کن IP_DROP_MEMBERSHIP 13
#تعریف_کن IP_DONTFRAGMENT 14
#تعریف_کن IP_جمع_کن_منبع_MEMBERSHIP 15
#تعریف_کن IP_DROP_منبع_MEMBERSHIP 16
#تعریف_کن IP_بلوک_منبع 17
#تعریف_کن IP_UNBLOCK_منبع 18
#تعریف_کن IP_PKTINFO 19
#تعریف_کن IP_RECEIVE_پخش 22

#تعریف_کن IPV6_HDRINCL 2
#تعریف_کن IPV6_UNICAST_HOPS 4
#تعریف_کن IPV6_MULTICAST_IF 9
#تعریف_کن IPV6_MULTICAST_HOPS 10
#تعریف_کن IPV6_MULTICAST_LOOP 11
#تعریف_کن IPV6_جمع_کن_MEMBERSHIP 12
#تعریف_کن IPV6_DROP_MEMBERSHIP 13
#تعریف_کن IPV6_JOIN_گروه IPV6_جمع_کن_MEMBERSHIP
#تعریف_کن IPV6_LEAVE_گروه IPV6_DROP_MEMBERSHIP
#تعریف_کن IPV6_PKTINFO 19
#تعریف_کن IPV6_HOPLIMIT 21
#تعریف_کن IPV6_PROTECTION_LEVEL 23

#تعریف_کن PROTECTION_LEVEL_UNRESTRICTED 10
#تعریف_کن PROTECTION_LEVEL_DEFAULT 20
#تعریف_کن PROTECTION_LEVEL_RESTRICTED 30

#تعریف_کن UDP_NOCHECKSUM 1
#تعریف_کن UDP_CHECKSUM_COVERAGE 20

#تعریف_کن TCP_EXPEDITED_1122 0x0002

#اگر_تعریف_نشده s6_addr

بنية in6_addr {
  __MINGW_EXTENSION اتحاد {
    u_char Byte[16];
    u_short کلمه_2[8];
  } u;
};

#تعریف_کن درون_addr6 in6_addr

#تعریف_کن _S6_un u
#تعریف_کن _S6_u8 Byte
#تعریف_کن s6_addr _S6_un._S6_u8

#تعریف_کن s6_بایتها u.Byte
#تعریف_کن s6_واژگان u.کلمه_2
#پایان_اگر

تعريفنوع بنية ipv6_mreq {
  بنية in6_addr ipv6mr_multiaddr;
  بیعلامت صحيح ipv6mr_interface;
} IPV6_MREQ;

بنية sockaddr_in6_old {
  کوتاه sin6_family;
  u_short sin6_پورت;
  u_long sin6_flowinfo;
  بنية in6_addr sin6_addr;
};

بنية sockaddr_in6 {
  کوتاه sin6_family;
  u_short sin6_پورت;
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

#تعریف_کن SS_پورت(ssp) (((بنية sockaddr_درون*)(ssp))->sin_پورت)

#تعریف_کن IN6ADDR_ANY_INIT { 0 }
#تعریف_کن IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  خارجي ثابت بنية in6_addr in6addr_any;
  خارجي ثابت بنية in6_addr in6addr_loopback;

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#تعریف_کن WS2TCPIP_INLINE __CRT_INLINE

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
فراغ IN6_مجموعه_ADDR_UNSPECIFIED(بنية in6_addr *);
فراغ IN6_مجموعه_ADDR_LOOPBACK(بنية in6_addr *);
فراغ IN6ADDR_SETANY(بنية sockaddr_in6 *);
فراغ IN6ADDR_SETLOOPBACK(بنية sockaddr_in6 *);

#اگر_تعریف_نشده __CRT__NO_INLINE
WS2TCPIP_INLINE صحيح IN6_ADDR_EQUAL(ثابت بنية in6_addr *a,ثابت بنية in6_addr *b) { أرجع (memcmp(a,b,حجم(بنية in6_addr))==0); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_UNSPECIFIED(ثابت بنية in6_addr *a) { أرجع ((a->s6_واژگان[0]==0) && (a->s6_واژگان[1]==0) && (a->s6_واژگان[2]==0) && (a->s6_واژگان[3]==0) && (a->s6_واژگان[4]==0) && (a->s6_واژگان[5]==0) && (a->s6_واژگان[6]==0) && (a->s6_واژگان[7]==0)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_LOOPBACK(ثابت بنية in6_addr *a) { أرجع ((a->s6_واژگان[0]==0) && (a->s6_واژگان[1]==0) && (a->s6_واژگان[2]==0) && (a->s6_واژگان[3]==0) && (a->s6_واژگان[4]==0) && (a->s6_واژگان[5]==0) && (a->s6_واژگان[6]==0) && (a->s6_واژگان[7]==0x0100)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MULTICAST(ثابت بنية in6_addr *a) { أرجع (a->s6_بایتها[0]==0xff); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_LINKLOCAL(ثابت بنية in6_addr *a) { أرجع ((a->s6_بایتها[0]==0xfe) && ((a->s6_بایتها[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_SITELOCAL(ثابت بنية in6_addr *a) { أرجع ((a->s6_بایتها[0]==0xfe) && ((a->s6_بایتها[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_V4MAPPED(ثابت بنية in6_addr *a) { أرجع ((a->s6_واژگان[0]==0) && (a->s6_واژگان[1]==0) && (a->s6_واژگان[2]==0) && (a->s6_واژگان[3]==0) && (a->s6_واژگان[4]==0) && (a->s6_واژگان[5]==0xffff)); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_V4COMPAT(ثابت بنية in6_addr *a) { أرجع ((a->s6_واژگان[0]==0) && (a->s6_واژگان[1]==0) && (a->s6_واژگان[2]==0) && (a->s6_واژگان[3]==0) && (a->s6_واژگان[4]==0) && (a->s6_واژگان[5]==0) && !((a->s6_واژگان[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_NODELOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایتها[1] & 0xf)==1); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_LINKLOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایتها[1] & 0xf)==2); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_SITELOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایتها[1] & 0xf)==5); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_ORGLOCAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایتها[1] & 0xf)==8); }
WS2TCPIP_INLINE صحيح IN6_IS_ADDR_MC_GLOBAL(ثابت بنية in6_addr *a) { أرجع IN6_IS_ADDR_MULTICAST(a) && ((a->s6_بایتها[1] & 0xf)==0xe); }
WS2TCPIP_INLINE صحيح IN6ADDR_ISANY(ثابت بنية sockaddr_in6 *a) { أرجع ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE صحيح IN6ADDR_ISLOOPBACK(ثابت بنية sockaddr_in6 *a) { أرجع ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE فراغ IN6_مجموعه_ADDR_UNSPECIFIED(بنية in6_addr *a) { memset(a->s6_بایتها,0,حجم(بنية in6_addr)); }
WS2TCPIP_INLINE فراغ IN6_مجموعه_ADDR_LOOPBACK(بنية in6_addr *a) {
  memset(a->s6_بایتها,0,حجم(بنية in6_addr));
  a->s6_بایتها[15] = 1;
}
WS2TCPIP_INLINE فراغ IN6ADDR_SETANY(بنية sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورت = 0;
  a->sin6_flowinfo = 0;
  IN6_مجموعه_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE فراغ IN6ADDR_SETLOOPBACK(بنية sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_پورت = 0;
  a->sin6_flowinfo = 0;
  IN6_مجموعه_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#پایان_اگر /* !__CRT__NO_INLINE */

تعريفنوع اتحاد sockaddr_gen {
  بنية sockaddr آدرس_2;
  بنية sockaddr_درون آدرس_درون;
  بنية sockaddr_in6_old آدرس_In6;
} sockaddr_gen;

تعريفنوع بنية _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen ii_آدرس;
  sockaddr_gen ii_پخش_آدرس;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

تعريفنوع بنية _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_آدرس_2 ii_آدرس;
  SOCKET_آدرس_2 ii_پخش_آدرس;
  SOCKET_آدرس_2 iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#تعریف_کن IFF_به_بالا 0x00000001
#تعریف_کن IFF_پخش 0x00000002
#تعریف_کن IFF_LOOPBACK 0x00000004
#تعریف_کن IFF_POINTTOPOINT 0x00000008
#تعریف_کن IFF_MULTICAST 0x00000010

تعريفنوع بنية درون_pktinfo {
  درون_ADDR ipi_addr;
  UINT ipi_ifindex;
} درون_PKTINFO;

C_ASSERT(حجم(درون_PKTINFO)==8);

تعريفنوع بنية in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(حجم(IN6_PKTINFO)==20);

#تعریف_کن EAI_AGAIN WSATRY_AGAIN
#تعریف_کن EAI_BADFLAGS WSAEINVAL
#تعریف_کن EAI_FAIL WSANO_RECOVERY
#تعریف_کن EAI_FAMILY WSAEAFNOSUPPORT
#تعریف_کن EAI_حافظه WSA_NOT_ENOUGH_حافظه

#تعریف_کن EAI_NONAME WSAHOST_NOT_یافت
#تعریف_کن EAI_SERVICE WSATYPE_NOT_یافت
#تعریف_کن EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#تعریف_کن EAI_NODATA EAI_NONAME

تعريفنوع بنية addrinfo {
  صحيح ai_flags;
  صحيح ai_family;
  صحيح ai_socktype;
  صحيح ai_protocol;
  اندازه_t ai_addrlen;
  حرف *ai_canonname;
  بنية sockaddr *ai_addr;
  بنية addrinfo *ai_بعدی;
} ADDRINFOA,*PADDRINFOA;

تعريفنوع بنية addrinfoW {
  صحيح ai_flags;
  صحيح ai_family;
  صحيح ai_socktype;
  صحيح ai_protocol;
  اندازه_t ai_addrlen;
  PWSTR ai_canonname;
  بنية sockaddr *ai_addr;
  بنية addrinfoW *ai_بعدی;
} ADDRINFOW,*PADDRINFOW;

#اگر_تعریف_شده UNICODE
تعريفنوع ADDRINFOW ADDRINFOT,*PADDRINFOT;
#وإلا
تعريفنوع ADDRINFOA ADDRINFOT,*PADDRINFOT;
#پایان_اگر

تعريفنوع ADDRINFOA ADDRINFO,*LPADDRINFO;

#تعریف_کن AI_PASSIVE 0x1
#تعریف_کن AI_CANONNAME 0x2
#تعریف_کن AI_NUMERICHOST 0x4

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن GetAddrInfo GetAddrInfoW
#وإلا
#تعریف_کن GetAddrInfo GetAddrInfoA
#پایان_اگر

  WINSOCK_API_LINKAGE صحيح WSAAPI getaddrinfo(ثابت حرف *nodename,ثابت حرف *servname,ثابت بنية addrinfo *hints,بنية addrinfo **res);
  WINSOCK_API_LINKAGE صحيح WSAAPI GetAddrInfoW(PCWSTR p_گره_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_نتیجه);

#تعریف_کن GetAddrInfoA getaddrinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع صحيح (WSAAPI *LPFN_GETADDRINFO)(ثابت حرف *nodename,ثابت حرف *servname,ثابت بنية addrinfo *hints,بنية addrinfo **res);
  تعريفنوع صحيح (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_گره_Name,PCWSTR pServiceName,ثابت ADDRINFOW *pHints,PADDRINFOW *pp_نتیجه);

#تعریف_کن LPFN_GETADDRINFOA LPFN_GETADDRINFO

#اگر_تعریف_شده UNICODE
#تعریف_کن LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#وإلا
#تعریف_کن LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن FreeAddrInfo FreeAddrInfoW
#وإلا
#تعریف_کن FreeAddrInfo FreeAddrInfoA
#پایان_اگر

  WINSOCK_API_LINKAGE فراغ WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE فراغ WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#تعریف_کن FreeAddrInfoA freeaddrinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع فراغ (WSAAPI *LPFN_FREEADDRINFO)(بنية addrinfo *ai);
  تعريفنوع فراغ (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#تعریف_کن LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#اگر_تعریف_شده UNICODE
#تعریف_کن LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#وإلا
#تعریف_کن LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#پایان_اگر
#پایان_اگر

#رهنمود افزودن_macro("socklen_t")
#لغو_تعریف socklen_t

  تعريفنوع صحيح socklen_t;

#اگر_تعریف_شده UNICODE
#تعریف_کن GetNameInfo GetNameInfoW
#وإلا
#تعریف_کن GetNameInfo GetNameInfoA
#پایان_اگر

  WINSOCK_API_LINKAGE صحيح WSAAPI getnameinfo(ثابت بنية sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحيح flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_درازی,PWCHAR p_گره_میانگیر,DWORD گره_میانگیر_اندازه,PWCHAR p_Service_میانگیر,DWORD Service_میانگیر_اندازه,INT Flags);

#تعریف_کن GetNameInfoA getnameinfo

#إذا INCL_WINSOCK_API_TYPEDEFS
  تعريفنوع صحيح (WSAAPI *LPFN_GETNAMEINFO)(ثابت بنية sockaddr *sa,socklen_t salen,حرف *host,DWORD hostlen,حرف *serv,DWORD servlen,صحيح flags);
  تعريفنوع INT (WSAAPI *LPFN_GETNAMEINFOW)(ثابت SOCKADDR *pSockaddr,socklen_t Sockaddr_درازی,PWCHAR p_گره_میانگیر,DWORD گره_میانگیر_اندازه,PWCHAR p_Service_میانگیر,DWORD Service_میانگیر_اندازه,INT Flags);

#تعریف_کن LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#اگر_تعریف_شده UNICODE
#تعریف_کن LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#وإلا
#تعریف_کن LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#پایان_اگر
#پایان_اگر

#رهنمود برداشت_macro("socklen_t")

#اگر_تعریف_شده UNICODE
#تعریف_کن gai_strerror gai_strerrorW
#وإلا
#تعریف_کن gai_strerror gai_strerrorA
#پایان_اگر

#تعریف_کن GAI_STRERROR_میانگیر_اندازه 1024

حرف *gai_strerrorA (صحيح);
WCHAR *gai_strerrorW(صحيح);

#تعریف_کن NI_MAXHOST 1025
#تعریف_کن NI_MAXSERV 32

#تعریف_کن INET_ADDRSTRLEN 22
#تعریف_کن INET6_ADDRSTRLEN 65

#تعریف_کن NI_NOFQDN 0x01
#تعریف_کن NI_NUMERICHOST 0x02
#تعریف_کن NI_NAMEREQD 0x04
#تعریف_کن NI_NUMERICSERV 0x08
#تعریف_کن NI_DGRAM 0x10

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#پایان_اگر
