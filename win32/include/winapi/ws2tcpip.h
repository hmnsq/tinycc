/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _WS2TCPIP_H
#परिभाषय _WS2TCPIP_H

#यदि __GNUC__ >=3
#निर्देशः GCC system_शीर्षकम्
#यदि_अन्तः

#अन्तर्भाव <ws2ipdef.h>

संरचना ip_msfilter {
  संरचना अन्तर्_addr imsf_multiaddr;
  संरचना अन्तर्_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  संरचना अन्तर्_addr imsf_slist[1];
};

#परिभाषय IP_MSFILTER_आकार(numsrc) (परिमाण(संरचना ip_msfilter)-परिमाण(संरचना अन्तर्_addr) + (numsrc)*परिमाण(संरचना अन्तर्_addr))

#परिभाषय MCAST_INCLUDE 0
#परिभाषय MCAST_EXCLUDE 1

#परिभाषय SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#परिभाषय SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#परिभाषय SIO_समुच्चयः_MULTICAST_FILTER _IOW('t',125,u_long)
#परिभाषय SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_अन्तर्,u_long)

#परिभाषय IP_OPTIONS 1
#परिभाषय IP_HDRINCL 2
#परिभाषय IP_TOS 3
#परिभाषय IP_TTL 4
#परिभाषय IP_MULTICAST_IF 9
#परिभाषय IP_MULTICAST_TTL 10
#परिभाषय IP_MULTICAST_LOOP 11
#परिभाषय IP_सङ्कलय_MEMBERSHIP 12
#परिभाषय IP_DROP_MEMBERSHIP 13
#परिभाषय IP_DONTFRAGMENT 14
#परिभाषय IP_सङ्कलय_SOURCE_MEMBERSHIP 15
#परिभाषय IP_DROP_SOURCE_MEMBERSHIP 16
#परिभाषय IP_खण्डम्_SOURCE 17
#परिभाषय IP_UNBLOCK_SOURCE 18
#परिभाषय IP_PKTINFO 19
#परिभाषय IP_RECEIVE_प्रसारणम् 22

#परिभाषय IPV6_HDRINCL 2
#परिभाषय IPV6_UNICAST_HOPS 4
#परिभाषय IPV6_MULTICAST_IF 9
#परिभाषय IPV6_MULTICAST_HOPS 10
#परिभाषय IPV6_MULTICAST_LOOP 11
#परिभाषय IPV6_सङ्कलय_MEMBERSHIP 12
#परिभाषय IPV6_DROP_MEMBERSHIP 13
#परिभाषय IPV6_JOIN_गणः IPV6_सङ्कलय_MEMBERSHIP
#परिभाषय IPV6_LEAVE_गणः IPV6_DROP_MEMBERSHIP
#परिभाषय IPV6_PKTINFO 19
#परिभाषय IPV6_HOPLIMIT 21
#परिभाषय IPV6_PROTECTION_LEVEL 23

#परिभाषय PROTECTION_LEVEL_UNRESTRICTED 10
#परिभाषय PROTECTION_LEVEL_DEFAULT 20
#परिभाषय PROTECTION_LEVEL_RESTRICTED 30

#परिभाषय UDP_NOCHECKSUM 1
#परिभाषय UDP_CHECKSUM_COVERAGE 20

#परिभाषय TCP_EXPEDITED_1122 0x0002

#यदि_अपरिभाषितम् s6_addr

संरचना in6_addr {
  __MINGW_EXTENSION सङ्घ {
    u_char Byte[16];
    u_short Word[8];
  } u;
};

#परिभाषय अन्तर्_addr6 in6_addr

#परिभाषय _S6_un u
#परिभाषय _S6_u8 Byte
#परिभाषय s6_addr _S6_un._S6_u8

#परिभाषय s6_अष्टकानि u.Byte
#परिभाषय s6_शब्दाः u.Word
#यदि_अन्तः

प्रकारनिर्देश संरचना ipv6_mreq {
  संरचना in6_addr ipv6mr_multiaddr;
  अचिह्नित पूर्णाङ्क ipv6mr_interface;
} IPV6_MREQ;

संरचना sockaddr_in6_old {
  ह्रस्व sin6_family;
  u_short sin6_पत्तनम्;
  u_long sin6_flowinfo;
  संरचना in6_addr sin6_addr;
};

संरचना sockaddr_in6 {
  ह्रस्व sin6_family;
  u_short sin6_पत्तनम्;
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

#परिभाषय SS_पत्तनम्(ssp) (((संरचना sockaddr_अन्तर्*)(ssp))->sin_पत्तनम्)

#परिभाषय IN6ADDR_ANY_INIT { 0 }
#परिभाषय IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  बाह्य ध्रुव संरचना in6_addr in6addr_any;
  बाह्य ध्रुव संरचना in6_addr in6addr_loopback;

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#परिभाषय WS2TCPIP_INLINE __CRT_INLINE

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
शून्य IN6_समुच्चयः_ADDR_UNSPECIFIED(संरचना in6_addr *);
शून्य IN6_समुच्चयः_ADDR_LOOPBACK(संरचना in6_addr *);
शून्य IN6ADDR_SETANY(संरचना sockaddr_in6 *);
शून्य IN6ADDR_SETLOOPBACK(संरचना sockaddr_in6 *);

#यदि_अपरिभाषितम् __CRT__NO_INLINE
WS2TCPIP_INLINE पूर्णाङ्क IN6_ADDR_EQUAL(ध्रुव संरचना in6_addr *a,ध्रुव संरचना in6_addr *b) { प्रत्यागम (memcmp(a,b,परिमाण(संरचना in6_addr))==0); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_UNSPECIFIED(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_शब्दाः[0]==0) && (a->s6_शब्दाः[1]==0) && (a->s6_शब्दाः[2]==0) && (a->s6_शब्दाः[3]==0) && (a->s6_शब्दाः[4]==0) && (a->s6_शब्दाः[5]==0) && (a->s6_शब्दाः[6]==0) && (a->s6_शब्दाः[7]==0)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_LOOPBACK(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_शब्दाः[0]==0) && (a->s6_शब्दाः[1]==0) && (a->s6_शब्दाः[2]==0) && (a->s6_शब्दाः[3]==0) && (a->s6_शब्दाः[4]==0) && (a->s6_शब्दाः[5]==0) && (a->s6_शब्दाः[6]==0) && (a->s6_शब्दाः[7]==0x0100)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MULTICAST(ध्रुव संरचना in6_addr *a) { प्रत्यागम (a->s6_अष्टकानि[0]==0xff); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_LINKLOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_अष्टकानि[0]==0xfe) && ((a->s6_अष्टकानि[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_SITELOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_अष्टकानि[0]==0xfe) && ((a->s6_अष्टकानि[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_V4MAPPED(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_शब्दाः[0]==0) && (a->s6_शब्दाः[1]==0) && (a->s6_शब्दाः[2]==0) && (a->s6_शब्दाः[3]==0) && (a->s6_शब्दाः[4]==0) && (a->s6_शब्दाः[5]==0xffff)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_V4COMPAT(ध्रुव संरचना in6_addr *a) { प्रत्यागम ((a->s6_शब्दाः[0]==0) && (a->s6_शब्दाः[1]==0) && (a->s6_शब्दाः[2]==0) && (a->s6_शब्दाः[3]==0) && (a->s6_शब्दाः[4]==0) && (a->s6_शब्दाः[5]==0) && !((a->s6_शब्दाः[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_NODELOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_अष्टकानि[1] & 0xf)==1); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_LINKLOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_अष्टकानि[1] & 0xf)==2); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_SITELOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_अष्टकानि[1] & 0xf)==5); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_ORGLOCAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_अष्टकानि[1] & 0xf)==8); }
WS2TCPIP_INLINE पूर्णाङ्क IN6_IS_ADDR_MC_GLOBAL(ध्रुव संरचना in6_addr *a) { प्रत्यागम IN6_IS_ADDR_MULTICAST(a) && ((a->s6_अष्टकानि[1] & 0xf)==0xe); }
WS2TCPIP_INLINE पूर्णाङ्क IN6ADDR_ISANY(ध्रुव संरचना sockaddr_in6 *a) { प्रत्यागम ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE पूर्णाङ्क IN6ADDR_ISLOOPBACK(ध्रुव संरचना sockaddr_in6 *a) { प्रत्यागम ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE शून्य IN6_समुच्चयः_ADDR_UNSPECIFIED(संरचना in6_addr *a) { स्मृतिं_पूरय(a->s6_अष्टकानि,0,परिमाण(संरचना in6_addr)); }
WS2TCPIP_INLINE शून्य IN6_समुच्चयः_ADDR_LOOPBACK(संरचना in6_addr *a) {
  स्मृतिं_पूरय(a->s6_अष्टकानि,0,परिमाण(संरचना in6_addr));
  a->s6_अष्टकानि[15] = 1;
}
WS2TCPIP_INLINE शून्य IN6ADDR_SETANY(संरचना sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_पत्तनम् = 0;
  a->sin6_flowinfo = 0;
  IN6_समुच्चयः_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE शून्य IN6ADDR_SETLOOPBACK(संरचना sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_पत्तनम् = 0;
  a->sin6_flowinfo = 0;
  IN6_समुच्चयः_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#यदि_अन्तः /* !__CRT__NO_INLINE */

प्रकारनिर्देश सङ्घ sockaddr_gen {
  संरचना sockaddr स्थानाङ्कः_2;
  संरचना sockaddr_अन्तर् स्थानाङ्कः_अन्तर्;
  संरचना sockaddr_in6_old स्थानाङ्कः_In6;
} sockaddr_gen;

प्रकारनिर्देश संरचना _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen ii_स्थानाङ्कः;
  sockaddr_gen ii_प्रसारणम्_स्थानाङ्कः;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

प्रकारनिर्देश संरचना _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_स्थानाङ्कः_2 ii_स्थानाङ्कः;
  SOCKET_स्थानाङ्कः_2 ii_प्रसारणम्_स्थानाङ्कः;
  SOCKET_स्थानाङ्कः_2 iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#परिभाषय IFF_ऊर्ध्वम् 0x00000001
#परिभाषय IFF_प्रसारणम् 0x00000002
#परिभाषय IFF_LOOPBACK 0x00000004
#परिभाषय IFF_POINTTOPOINT 0x00000008
#परिभाषय IFF_MULTICAST 0x00000010

प्रकारनिर्देश संरचना अन्तर्_pktinfo {
  अन्तर्_ADDR ipi_addr;
  UINT ipi_ifindex;
} अन्तर्_PKTINFO;

C_ASSERT(परिमाण(अन्तर्_PKTINFO)==8);

प्रकारनिर्देश संरचना in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(परिमाण(IN6_PKTINFO)==20);

#परिभाषय EAI_AGAIN WSATRY_AGAIN
#परिभाषय EAI_BADFLAGS WSAEINVAL
#परिभाषय EAI_FAIL WSANO_RECOVERY
#परिभाषय EAI_FAMILY WSAEAFNOSUPPORT
#परिभाषय EAI_स्मृतिः WSA_NOT_ENOUGH_स्मृतिः

#परिभाषय EAI_NONAME WSAHOST_NOT_प्राप्तम्
#परिभाषय EAI_SERVICE WSATYPE_NOT_प्राप्तम्
#परिभाषय EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#परिभाषय EAI_NODATA EAI_NONAME

प्रकारनिर्देश संरचना addrinfo {
  पूर्णाङ्क ai_flags;
  पूर्णाङ्क ai_family;
  पूर्णाङ्क ai_socktype;
  पूर्णाङ्क ai_protocol;
  आकार_t ai_addrlen;
  वर्ण *ai_canonname;
  संरचना sockaddr *ai_addr;
  संरचना addrinfo *ai_अग्र;
} ADDRINFOA,*PADDRINFOA;

प्रकारनिर्देश संरचना addrinfoW {
  पूर्णाङ्क ai_flags;
  पूर्णाङ्क ai_family;
  पूर्णाङ्क ai_socktype;
  पूर्णाङ्क ai_protocol;
  आकार_t ai_addrlen;
  PWSTR ai_canonname;
  संरचना sockaddr *ai_addr;
  संरचना addrinfoW *ai_अग्र;
} ADDRINFOW,*PADDRINFOW;

#यदि_परिभाषितम् UNICODE
प्रकारनिर्देश ADDRINFOW ADDRINFOT,*PADDRINFOT;
#अन्यथा
प्रकारनिर्देश ADDRINFOA ADDRINFOT,*PADDRINFOT;
#यदि_अन्तः

प्रकारनिर्देश ADDRINFOA ADDRINFO,*LPADDRINFO;

#परिभाषय AI_PASSIVE 0x1
#परिभाषय AI_CANONNAME 0x2
#परिभाषय AI_NUMERICHOST 0x4

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय GetAddrInfo GetAddrInfoW
#अन्यथा
#परिभाषय GetAddrInfo GetAddrInfoA
#यदि_अन्तः

  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI getaddrinfo(ध्रुव वर्ण *nodename,ध्रुव वर्ण *servname,ध्रुव संरचना addrinfo *hints,संरचना addrinfo **res);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI GetAddrInfoW(PCWSTR p_ग्रन्थिः_Name,PCWSTR pServiceName,ध्रुव ADDRINFOW *pHints,PADDRINFOW *pp_परिणाम);

#परिभाषय GetAddrInfoA getaddrinfo

#यदि INCL_WINSOCK_API_TYPEDEFS
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETADDRINFO)(ध्रुव वर्ण *nodename,ध्रुव वर्ण *servname,ध्रुव संरचना addrinfo *hints,संरचना addrinfo **res);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_ग्रन्थिः_Name,PCWSTR pServiceName,ध्रुव ADDRINFOW *pHints,PADDRINFOW *pp_परिणाम);

#परिभाषय LPFN_GETADDRINFOA LPFN_GETADDRINFO

#यदि_परिभाषितम् UNICODE
#परिभाषय LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#अन्यथा
#परिभाषय LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय FreeAddrInfo FreeAddrInfoW
#अन्यथा
#परिभाषय FreeAddrInfo FreeAddrInfoA
#यदि_अन्तः

  WINSOCK_API_LINKAGE शून्य WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE शून्य WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#परिभाषय FreeAddrInfoA freeaddrinfo

#यदि INCL_WINSOCK_API_TYPEDEFS
  प्रकारनिर्देश शून्य (WSAAPI *LPFN_FREEADDRINFO)(संरचना addrinfo *ai);
  प्रकारनिर्देश शून्य (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#परिभाषय LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#यदि_परिभाषितम् UNICODE
#परिभाषय LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#अन्यथा
#परिभाषय LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#यदि_अन्तः
#यदि_अन्तः

#निर्देशः प्रक्षिप_macro("socklen_t")
#अपरिभाषय socklen_t

  प्रकारनिर्देश पूर्णाङ्क socklen_t;

#यदि_परिभाषितम् UNICODE
#परिभाषय GetNameInfo GetNameInfoW
#अन्यथा
#परिभाषय GetNameInfo GetNameInfoA
#यदि_अन्तः

  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI getnameinfo(ध्रुव संरचना sockaddr *sa,socklen_t salen,वर्ण *host,DWORD hostlen,वर्ण *serv,DWORD servlen,पूर्णाङ्क flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ध्रुव SOCKADDR *pSockaddr,socklen_t Sockaddr_दीर्घता,PWCHAR p_ग्रन्थिः_बफर,DWORD ग्रन्थिः_बफर_आकार,PWCHAR p_Service_बफर,DWORD Service_बफर_आकार,INT Flags);

#परिभाषय GetNameInfoA getnameinfo

#यदि INCL_WINSOCK_API_TYPEDEFS
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETNAMEINFO)(ध्रुव संरचना sockaddr *sa,socklen_t salen,वर्ण *host,DWORD hostlen,वर्ण *serv,DWORD servlen,पूर्णाङ्क flags);
  प्रकारनिर्देश INT (WSAAPI *LPFN_GETNAMEINFOW)(ध्रुव SOCKADDR *pSockaddr,socklen_t Sockaddr_दीर्घता,PWCHAR p_ग्रन्थिः_बफर,DWORD ग्रन्थिः_बफर_आकार,PWCHAR p_Service_बफर,DWORD Service_बफर_आकार,INT Flags);

#परिभाषय LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#यदि_परिभाषितम् UNICODE
#परिभाषय LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#अन्यथा
#परिभाषय LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#यदि_अन्तः
#यदि_अन्तः

#निर्देशः निष्कासय_macro("socklen_t")

#यदि_परिभाषितम् UNICODE
#परिभाषय gai_strerror gai_strerrorW
#अन्यथा
#परिभाषय gai_strerror gai_strerrorA
#यदि_अन्तः

#परिभाषय GAI_STRERROR_बफर_आकार 1024

वर्ण *gai_strerrorA (पूर्णाङ्क);
WCHAR *gai_strerrorW(पूर्णाङ्क);

#परिभाषय NI_MAXHOST 1025
#परिभाषय NI_MAXSERV 32

#परिभाषय INET_ADDRSTRLEN 22
#परिभाषय INET6_ADDRSTRLEN 65

#परिभाषय NI_NOFQDN 0x01
#परिभाषय NI_NUMERICHOST 0x02
#परिभाषय NI_NAMEREQD 0x04
#परिभाषय NI_NUMERICSERV 0x08
#परिभाषय NI_DGRAM 0x10

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_अन्तः
