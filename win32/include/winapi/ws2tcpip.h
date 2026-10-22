/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _WS2TCPIP_H
#घोषणा _WS2TCPIP_H

#अगर __GNUC__ >=3
#आशय GCC system_header
#पूर्ण_अगर

#समावेश <ws2ipdef.h>

काष्ठा ip_msfilter {
  काष्ठा in_addr imsf_multiaddr;
  काष्ठा in_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  काष्ठा in_addr imsf_slist[1];
};

#घोषणा IP_MSFILTER_आकार(numsrc) (माप(काष्ठा ip_msfilter)-माप(काष्ठा in_addr) + (numsrc)*माप(काष्ठा in_addr))

#घोषणा MCAST_INCLUDE 0
#घोषणा MCAST_EXCLUDE 1

#घोषणा SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#घोषणा SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#घोषणा SIO_SET_MULTICAST_FILTER _IOW('t',125,u_long)
#घोषणा SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_IN,u_long)

#घोषणा IP_OPTIONS 1
#घोषणा IP_HDRINCL 2
#घोषणा IP_TOS 3
#घोषणा IP_TTL 4
#घोषणा IP_MULTICAST_IF 9
#घोषणा IP_MULTICAST_TTL 10
#घोषणा IP_MULTICAST_LOOP 11
#घोषणा IP_ADD_MEMBERSHIP 12
#घोषणा IP_DROP_MEMBERSHIP 13
#घोषणा IP_DONTFRAGMENT 14
#घोषणा IP_ADD_SOURCE_MEMBERSHIP 15
#घोषणा IP_DROP_SOURCE_MEMBERSHIP 16
#घोषणा IP_BLOCK_SOURCE 17
#घोषणा IP_UNBLOCK_SOURCE 18
#घोषणा IP_PKTINFO 19
#घोषणा IP_RECEIVE_BROADCAST 22

#घोषणा IPV6_HDRINCL 2
#घोषणा IPV6_UNICAST_HOPS 4
#घोषणा IPV6_MULTICAST_IF 9
#घोषणा IPV6_MULTICAST_HOPS 10
#घोषणा IPV6_MULTICAST_LOOP 11
#घोषणा IPV6_ADD_MEMBERSHIP 12
#घोषणा IPV6_DROP_MEMBERSHIP 13
#घोषणा IPV6_JOIN_GROUP IPV6_ADD_MEMBERSHIP
#घोषणा IPV6_LEAVE_GROUP IPV6_DROP_MEMBERSHIP
#घोषणा IPV6_PKTINFO 19
#घोषणा IPV6_HOPLIMIT 21
#घोषणा IPV6_PROTECTION_LEVEL 23

#घोषणा PROTECTION_LEVEL_UNRESTRICTED 10
#घोषणा PROTECTION_LEVEL_DEFAULT 20
#घोषणा PROTECTION_LEVEL_RESTRICTED 30

#घोषणा UDP_NOCHECKSUM 1
#घोषणा UDP_CHECKSUM_COVERAGE 20

#घोषणा TCP_EXPEDITED_1122 0x0002

#अगर_अघोषित s6_addr

काष्ठा in6_addr {
  __MINGW_EXTENSION जोड़ {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#घोषणा in_addr6 in6_addr

#घोषणा _S6_un u
#घोषणा _S6_u8 Byte
#घोषणा s6_addr _S6_un._S6_u8

#घोषणा s6_bytes u.Byte
#घोषणा s6_शब्दगण u.Word
#पूर्ण_अगर

प्रकार काष्ठा ipv6_mreq {
  काष्ठा in6_addr ipv6mr_multiaddr;
  अचिन्हित पूर्णांक ipv6mr_interface;
} IPV6_MREQ;

काष्ठा sockaddr_in6_old {
  लघु sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  काष्ठा in6_addr sin6_addr;
};

काष्ठा sockaddr_in6 {
  लघु sin6_family;
  u_short sin6_port;
  u_long sin6_flowinfo;
  काष्ठा in6_addr sin6_addr;
  u_long sin6_scope_id;
};

प्रकार काष्ठा in6_addr IN6_ADDR;
प्रकार काष्ठा in6_addr *PIN6_ADDR;
प्रकार काष्ठा in6_addr *LPIN6_ADDR;

प्रकार काष्ठा sockaddr_in6 SOCKADDR_IN6;
प्रकार काष्ठा sockaddr_in6 *PSOCKADDR_IN6;
प्रकार काष्ठा sockaddr_in6 *LPSOCKADDR_IN6;

#घोषणा SS_PORT(ssp) (((काष्ठा sockaddr_in*)(ssp))->sin_port)

#घोषणा IN6ADDR_ANY_INIT { 0 }
#घोषणा IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  बाह्य स्थिर काष्ठा in6_addr in6addr_any;
  बाह्य स्थिर काष्ठा in6_addr in6addr_loopback;

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#घोषणा WS2TCPIP_INLINE __CRT_INLINE

पूर्णांक IN6_ADDR_EQUAL(स्थिर काष्ठा in6_addr *,स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_UNSPECIFIED(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_LOOPBACK(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_MULTICAST(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_LINKLOCAL(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_SITELOCAL(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_V4MAPPED(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_V4COMPAT(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_MC_NODELOCAL(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_MC_LINKLOCAL(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_MC_SITELOCAL(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_MC_ORGLOCAL(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6_IS_ADDR_MC_GLOBAL(स्थिर काष्ठा in6_addr *);
पूर्णांक IN6ADDR_ISANY(स्थिर काष्ठा sockaddr_in6 *);
पूर्णांक IN6ADDR_ISLOOPBACK(स्थिर काष्ठा sockaddr_in6 *);
व्योम IN6_SET_ADDR_UNSPECIFIED(काष्ठा in6_addr *);
व्योम IN6_SET_ADDR_LOOPBACK(काष्ठा in6_addr *);
व्योम IN6ADDR_SETANY(काष्ठा sockaddr_in6 *);
व्योम IN6ADDR_SETLOOPBACK(काष्ठा sockaddr_in6 *);

#अगर_अघोषित __CRT__NO_INLINE
WS2TCPIP_INLINE पूर्णांक IN6_ADDR_EQUAL(स्थिर काष्ठा in6_addr *a,स्थिर काष्ठा in6_addr *b) { वापस (स_भेद(a,b,माप(काष्ठा in6_addr))==0); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_UNSPECIFIED(स्थिर काष्ठा in6_addr *a) { वापस ((a->s6_शब्दगण[0]==0) && (a->s6_शब्दगण[1]==0) && (a->s6_शब्दगण[2]==0) && (a->s6_शब्दगण[3]==0) && (a->s6_शब्दगण[4]==0) && (a->s6_शब्दगण[5]==0) && (a->s6_शब्दगण[6]==0) && (a->s6_शब्दगण[7]==0)); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_LOOPBACK(स्थिर काष्ठा in6_addr *a) { वापस ((a->s6_शब्दगण[0]==0) && (a->s6_शब्दगण[1]==0) && (a->s6_शब्दगण[2]==0) && (a->s6_शब्दगण[3]==0) && (a->s6_शब्दगण[4]==0) && (a->s6_शब्दगण[5]==0) && (a->s6_शब्दगण[6]==0) && (a->s6_शब्दगण[7]==0x0100)); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_MULTICAST(स्थिर काष्ठा in6_addr *a) { वापस (a->s6_bytes[0]==0xff); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_LINKLOCAL(स्थिर काष्ठा in6_addr *a) { वापस ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_SITELOCAL(स्थिर काष्ठा in6_addr *a) { वापस ((a->s6_bytes[0]==0xfe) && ((a->s6_bytes[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_V4MAPPED(स्थिर काष्ठा in6_addr *a) { वापस ((a->s6_शब्दगण[0]==0) && (a->s6_शब्दगण[1]==0) && (a->s6_शब्दगण[2]==0) && (a->s6_शब्दगण[3]==0) && (a->s6_शब्दगण[4]==0) && (a->s6_शब्दगण[5]==0xffff)); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_V4COMPAT(स्थिर काष्ठा in6_addr *a) { वापस ((a->s6_शब्दगण[0]==0) && (a->s6_शब्दगण[1]==0) && (a->s6_शब्दगण[2]==0) && (a->s6_शब्दगण[3]==0) && (a->s6_शब्दगण[4]==0) && (a->s6_शब्दगण[5]==0) && !((a->s6_शब्दगण[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_MC_NODELOCAL(स्थिर काष्ठा in6_addr *a) { वापस IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==1); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_MC_LINKLOCAL(स्थिर काष्ठा in6_addr *a) { वापस IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==2); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_MC_SITELOCAL(स्थिर काष्ठा in6_addr *a) { वापस IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==5); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_MC_ORGLOCAL(स्थिर काष्ठा in6_addr *a) { वापस IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==8); }
WS2TCPIP_INLINE पूर्णांक IN6_IS_ADDR_MC_GLOBAL(स्थिर काष्ठा in6_addr *a) { वापस IN6_IS_ADDR_MULTICAST(a) && ((a->s6_bytes[1] & 0xf)==0xe); }
WS2TCPIP_INLINE पूर्णांक IN6ADDR_ISANY(स्थिर काष्ठा sockaddr_in6 *a) { वापस ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE पूर्णांक IN6ADDR_ISLOOPBACK(स्थिर काष्ठा sockaddr_in6 *a) { वापस ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE व्योम IN6_SET_ADDR_UNSPECIFIED(काष्ठा in6_addr *a) { स_रखो(a->s6_bytes,0,माप(काष्ठा in6_addr)); }
WS2TCPIP_INLINE व्योम IN6_SET_ADDR_LOOPBACK(काष्ठा in6_addr *a) {
  स_रखो(a->s6_bytes,0,माप(काष्ठा in6_addr));
  a->s6_bytes[15] = 1;
}
WS2TCPIP_INLINE व्योम IN6ADDR_SETANY(काष्ठा sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE व्योम IN6ADDR_SETLOOPBACK(काष्ठा sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_port = 0;
  a->sin6_flowinfo = 0;
  IN6_SET_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#पूर्ण_अगर /* !__CRT__NO_INLINE */

प्रकार जोड़ sockaddr_gen {
  काष्ठा sockaddr Address;
  काष्ठा sockaddr_in AddressIn;
  काष्ठा sockaddr_in6_old AddressIn6;
} sockaddr_gen;

प्रकार काष्ठा _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen iiAddress;
  sockaddr_gen iiBroadcastAddress;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

प्रकार काष्ठा _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_ADDRESS iiAddress;
  SOCKET_ADDRESS iiBroadcastAddress;
  SOCKET_ADDRESS iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#घोषणा IFF_UP 0x00000001
#घोषणा IFF_BROADCAST 0x00000002
#घोषणा IFF_LOOPBACK 0x00000004
#घोषणा IFF_POINTTOPOINT 0x00000008
#घोषणा IFF_MULTICAST 0x00000010

प्रकार काष्ठा in_pktinfo {
  IN_ADDR ipi_addr;
  UINT ipi_ifindex;
} IN_PKTINFO;

C_ASSERT(माप(IN_PKTINFO)==8);

प्रकार काष्ठा in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(माप(IN6_PKTINFO)==20);

#घोषणा EAI_AGAIN WSATRY_AGAIN
#घोषणा EAI_BADFLAGS WSAEINVAL
#घोषणा EAI_FAIL WSANO_RECOVERY
#घोषणा EAI_FAMILY WSAEAFNOSUPPORT
#घोषणा EAI_MEMORY WSA_NOT_ENOUGH_MEMORY

#घोषणा EAI_NONAME WSAHOST_NOT_FOUND
#घोषणा EAI_SERVICE WSATYPE_NOT_FOUND
#घोषणा EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#घोषणा EAI_NODATA EAI_NONAME

प्रकार काष्ठा addrinfo {
  पूर्णांक ai_flags;
  पूर्णांक ai_family;
  पूर्णांक ai_socktype;
  पूर्णांक ai_protocol;
  माप_प्रकार ai_addrlen;
  अक्षर *ai_canonname;
  काष्ठा sockaddr *ai_addr;
  काष्ठा addrinfo *ai_अग्र;
} ADDRINFOA,*PADDRINFOA;

प्रकार काष्ठा addrinfoW {
  पूर्णांक ai_flags;
  पूर्णांक ai_family;
  पूर्णांक ai_socktype;
  पूर्णांक ai_protocol;
  माप_प्रकार ai_addrlen;
  PWSTR ai_canonname;
  काष्ठा sockaddr *ai_addr;
  काष्ठा addrinfoW *ai_अग्र;
} ADDRINFOW,*PADDRINFOW;

#अगर_घोषित UNICODE
प्रकार ADDRINFOW ADDRINFOT,*PADDRINFOT;
#अन्यथा
प्रकार ADDRINFOA ADDRINFOT,*PADDRINFOT;
#पूर्ण_अगर

प्रकार ADDRINFOA ADDRINFO,*LPADDRINFO;

#घोषणा AI_PASSIVE 0x1
#घोषणा AI_CANONNAME 0x2
#घोषणा AI_NUMERICHOST 0x4

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_घोषित UNICODE
#घोषणा GetAddrInfo GetAddrInfoW
#अन्यथा
#घोषणा GetAddrInfo GetAddrInfoA
#पूर्ण_अगर

  WINSOCK_API_LINKAGE पूर्णांक WSAAPI getaddrinfo(स्थिर अक्षर *nodename,स्थिर अक्षर *servname,स्थिर काष्ठा addrinfo *hints,काष्ठा addrinfo **res);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI GetAddrInfoW(PCWSTR p_गाँठ_Name,PCWSTR pServiceName,स्थिर ADDRINFOW *pHints,PADDRINFOW *pp_परिणाम);

#घोषणा GetAddrInfoA getaddrinfo

#अगर INCL_WINSOCK_API_TYPEDEFS
  प्रकार पूर्णांक (WSAAPI *LPFN_GETADDRINFO)(स्थिर अक्षर *nodename,स्थिर अक्षर *servname,स्थिर काष्ठा addrinfo *hints,काष्ठा addrinfo **res);
  प्रकार पूर्णांक (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_गाँठ_Name,PCWSTR pServiceName,स्थिर ADDRINFOW *pHints,PADDRINFOW *pp_परिणाम);

#घोषणा LPFN_GETADDRINFOA LPFN_GETADDRINFO

#अगर_घोषित UNICODE
#घोषणा LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#अन्यथा
#घोषणा LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित UNICODE
#घोषणा FreeAddrInfo FreeAddrInfoW
#अन्यथा
#घोषणा FreeAddrInfo FreeAddrInfoA
#पूर्ण_अगर

  WINSOCK_API_LINKAGE व्योम WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE व्योम WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#घोषणा FreeAddrInfoA freeaddrinfo

#अगर INCL_WINSOCK_API_TYPEDEFS
  प्रकार व्योम (WSAAPI *LPFN_FREEADDRINFO)(काष्ठा addrinfo *ai);
  प्रकार व्योम (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#घोषणा LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#अगर_घोषित UNICODE
#घोषणा LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#अन्यथा
#घोषणा LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#पूर्ण_अगर
#पूर्ण_अगर

#आशय धकेलो_macro("socklen_t")
#अघोषित socklen_t

  प्रकार पूर्णांक socklen_t;

#अगर_घोषित UNICODE
#घोषणा GetNameInfo GetNameInfoW
#अन्यथा
#घोषणा GetNameInfo GetNameInfoA
#पूर्ण_अगर

  WINSOCK_API_LINKAGE पूर्णांक WSAAPI getnameinfo(स्थिर काष्ठा sockaddr *sa,socklen_t salen,अक्षर *host,DWORD hostlen,अक्षर *serv,DWORD servlen,पूर्णांक flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(स्थिर SOCKADDR *pSockaddr,socklen_t Sockaddr_लंबाई,PWCHAR p_गाँठ_बफर,DWORD गाँठ_बफर_आकार,PWCHAR p_Service_बफर,DWORD Service_बफर_आकार,INT Flags);

#घोषणा GetNameInfoA getnameinfo

#अगर INCL_WINSOCK_API_TYPEDEFS
  प्रकार पूर्णांक (WSAAPI *LPFN_GETNAMEINFO)(स्थिर काष्ठा sockaddr *sa,socklen_t salen,अक्षर *host,DWORD hostlen,अक्षर *serv,DWORD servlen,पूर्णांक flags);
  प्रकार INT (WSAAPI *LPFN_GETNAMEINFOW)(स्थिर SOCKADDR *pSockaddr,socklen_t Sockaddr_लंबाई,PWCHAR p_गाँठ_बफर,DWORD गाँठ_बफर_आकार,PWCHAR p_Service_बफर,DWORD Service_बफर_आकार,INT Flags);

#घोषणा LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#अगर_घोषित UNICODE
#घोषणा LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#अन्यथा
#घोषणा LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#पूर्ण_अगर
#पूर्ण_अगर

#आशय निकालो_macro("socklen_t")

#अगर_घोषित UNICODE
#घोषणा gai_strerror gai_strerrorW
#अन्यथा
#घोषणा gai_strerror gai_strerrorA
#पूर्ण_अगर

#घोषणा GAI_STRERROR_बफर_आकार 1024

अक्षर *gai_strerrorA (पूर्णांक);
WCHAR *gai_strerrorW(पूर्णांक);

#घोषणा NI_MAXHOST 1025
#घोषणा NI_MAXSERV 32

#घोषणा INET_ADDRSTRLEN 22
#घोषणा INET6_ADDRSTRLEN 65

#घोषणा NI_NOFQDN 0x01
#घोषणा NI_NUMERICHOST 0x02
#घोषणा NI_NAMEREQD 0x04
#घोषणा NI_NUMERICSERV 0x08
#घोषणा NI_DGRAM 0x10

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
