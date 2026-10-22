/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _WS2TCPIP_H
#నిర్వచించు _WS2TCPIP_H

#ఒకవేళ __GNUC__ >=3
#సూచన GCC system_శీర్షిక
#అయితే_ముగింపు

#అన్తర్భావ <ws2ipdef.h>

నిర్మాణం ip_msfilter {
  నిర్మాణం లోపల_addr imsf_multiaddr;
  నిర్మాణం లోపల_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  నిర్మాణం లోపల_addr imsf_slist[1];
};

#నిర్వచించు IP_MSFILTER_కొలత(numsrc) (పరిమాణం(నిర్మాణం ip_msfilter)-పరిమాణం(నిర్మాణం లోపల_addr) + (numsrc)*పరిమాణం(నిర్మాణం లోపల_addr))

#నిర్వచించు MCAST_INCLUDE 0
#నిర్వచించు MCAST_EXCLUDE 1

#నిర్వచించు SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#నిర్వచించు SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#నిర్వచించు SIO_సమితి_MULTICAST_FILTER _IOW('t',125,u_long)
#నిర్వచించు SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_లోపల,u_long)

#నిర్వచించు IP_OPTIONS 1
#నిర్వచించు IP_HDRINCL 2
#నిర్వచించు IP_TOS 3
#నిర్వచించు IP_TTL 4
#నిర్వచించు IP_MULTICAST_IF 9
#నిర్వచించు IP_MULTICAST_TTL 10
#నిర్వచించు IP_MULTICAST_LOOP 11
#నిర్వచించు IP_కూడు_MEMBERSHIP 12
#నిర్వచించు IP_DROP_MEMBERSHIP 13
#నిర్వచించు IP_DONTFRAGMENT 14
#నిర్వచించు IP_కూడు_ఆధారం_MEMBERSHIP 15
#నిర్వచించు IP_DROP_ఆధారం_MEMBERSHIP 16
#నిర్వచించు IP_ఖండం_ఆధారం 17
#నిర్వచించు IP_UNBLOCK_ఆధారం 18
#నిర్వచించు IP_PKTINFO 19
#నిర్వచించు IP_RECEIVE_ప్రసారం 22

#నిర్వచించు IPV6_HDRINCL 2
#నిర్వచించు IPV6_UNICAST_HOPS 4
#నిర్వచించు IPV6_MULTICAST_IF 9
#నిర్వచించు IPV6_MULTICAST_HOPS 10
#నిర్వచించు IPV6_MULTICAST_LOOP 11
#నిర్వచించు IPV6_కూడు_MEMBERSHIP 12
#నిర్వచించు IPV6_DROP_MEMBERSHIP 13
#నిర్వచించు IPV6_JOIN_సమూహం IPV6_కూడు_MEMBERSHIP
#నిర్వచించు IPV6_LEAVE_సమూహం IPV6_DROP_MEMBERSHIP
#నిర్వచించు IPV6_PKTINFO 19
#నిర్వచించు IPV6_HOPLIMIT 21
#నిర్వచించు IPV6_PROTECTION_LEVEL 23

#నిర్వచించు PROTECTION_LEVEL_UNRESTRICTED 10
#నిర్వచించు PROTECTION_LEVEL_DEFAULT 20
#నిర్వచించు PROTECTION_LEVEL_RESTRICTED 30

#నిర్వచించు UDP_NOCHECKSUM 1
#నిర్వచించు UDP_CHECKSUM_COVERAGE 20

#నిర్వచించు TCP_EXPEDITED_1122 0x0002

#నిర్వచితం_కాకపోతే s6_addr

నిర్మాణం in6_addr {
  __MINGW_EXTENSION సంఘం {
    u_char Byte[16];
    u_short మాట_2[8];
  } u;
};

#నిర్వచించు లోపల_addr6 in6_addr

#నిర్వచించు _S6_un u
#నిర్వచించు _S6_u8 Byte
#నిర్వచించు s6_addr _S6_un._S6_u8

#నిర్వచించు s6_బైట్లు u.Byte
#నిర్వచించు s6_పదాలు u.మాట_2
#అయితే_ముగింపు

రకనిర్వచనం నిర్మాణం ipv6_mreq {
  నిర్మాణం in6_addr ipv6mr_multiaddr;
  గుర్తులేని పూర్ణాంకం ipv6mr_interface;
} IPV6_MREQ;

నిర్మాణం sockaddr_in6_old {
  పొట్టి sin6_family;
  u_short sin6_పోర్టు;
  u_long sin6_flowinfo;
  నిర్మాణం in6_addr sin6_addr;
};

నిర్మాణం sockaddr_in6 {
  పొట్టి sin6_family;
  u_short sin6_పోర్టు;
  u_long sin6_flowinfo;
  నిర్మాణం in6_addr sin6_addr;
  u_long sin6_scope_id;
};

రకనిర్వచనం నిర్మాణం in6_addr IN6_ADDR;
రకనిర్వచనం నిర్మాణం in6_addr *PIN6_ADDR;
రకనిర్వచనం నిర్మాణం in6_addr *LPIN6_ADDR;

రకనిర్వచనం నిర్మాణం sockaddr_in6 SOCKADDR_IN6;
రకనిర్వచనం నిర్మాణం sockaddr_in6 *PSOCKADDR_IN6;
రకనిర్వచనం నిర్మాణం sockaddr_in6 *LPSOCKADDR_IN6;

#నిర్వచించు SS_పోర్టు(ssp) (((నిర్మాణం sockaddr_లోపల*)(ssp))->sin_పోర్టు)

#నిర్వచించు IN6ADDR_ANY_INIT { 0 }
#నిర్వచించు IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  బాహ్య స్థిరరాశి నిర్మాణం in6_addr in6addr_any;
  బాహ్య స్థిరరాశి నిర్మాణం in6_addr in6addr_loopback;

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#నిర్వచించు WS2TCPIP_INLINE __CRT_INLINE

పూర్ణాంకం IN6_ADDR_EQUAL(స్థిరరాశి నిర్మాణం in6_addr *,స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_UNSPECIFIED(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_LOOPBACK(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_MULTICAST(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_LINKLOCAL(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_SITELOCAL(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_V4MAPPED(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_V4COMPAT(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_MC_NODELOCAL(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_MC_LINKLOCAL(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_MC_SITELOCAL(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_MC_ORGLOCAL(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6_IS_ADDR_MC_GLOBAL(స్థిరరాశి నిర్మాణం in6_addr *);
పూర్ణాంకం IN6ADDR_ISANY(స్థిరరాశి నిర్మాణం sockaddr_in6 *);
పూర్ణాంకం IN6ADDR_ISLOOPBACK(స్థిరరాశి నిర్మాణం sockaddr_in6 *);
శూన్య IN6_సమితి_ADDR_UNSPECIFIED(నిర్మాణం in6_addr *);
శూన్య IN6_సమితి_ADDR_LOOPBACK(నిర్మాణం in6_addr *);
శూన్య IN6ADDR_SETANY(నిర్మాణం sockaddr_in6 *);
శూన్య IN6ADDR_SETLOOPBACK(నిర్మాణం sockaddr_in6 *);

#నిర్వచితం_కాకపోతే __CRT__NO_INLINE
WS2TCPIP_INLINE పూర్ణాంకం IN6_ADDR_EQUAL(స్థిరరాశి నిర్మాణం in6_addr *a,స్థిరరాశి నిర్మాణం in6_addr *b) { తిరిగి (memcmp(a,b,పరిమాణం(నిర్మాణం in6_addr))==0); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_UNSPECIFIED(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి ((a->s6_పదాలు[0]==0) && (a->s6_పదాలు[1]==0) && (a->s6_పదాలు[2]==0) && (a->s6_పదాలు[3]==0) && (a->s6_పదాలు[4]==0) && (a->s6_పదాలు[5]==0) && (a->s6_పదాలు[6]==0) && (a->s6_పదాలు[7]==0)); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_LOOPBACK(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి ((a->s6_పదాలు[0]==0) && (a->s6_పదాలు[1]==0) && (a->s6_పదాలు[2]==0) && (a->s6_పదాలు[3]==0) && (a->s6_పదాలు[4]==0) && (a->s6_పదాలు[5]==0) && (a->s6_పదాలు[6]==0) && (a->s6_పదాలు[7]==0x0100)); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_MULTICAST(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి (a->s6_బైట్లు[0]==0xff); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_LINKLOCAL(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి ((a->s6_బైట్లు[0]==0xfe) && ((a->s6_బైట్లు[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_SITELOCAL(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి ((a->s6_బైట్లు[0]==0xfe) && ((a->s6_బైట్లు[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_V4MAPPED(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి ((a->s6_పదాలు[0]==0) && (a->s6_పదాలు[1]==0) && (a->s6_పదాలు[2]==0) && (a->s6_పదాలు[3]==0) && (a->s6_పదాలు[4]==0) && (a->s6_పదాలు[5]==0xffff)); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_V4COMPAT(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి ((a->s6_పదాలు[0]==0) && (a->s6_పదాలు[1]==0) && (a->s6_పదాలు[2]==0) && (a->s6_పదాలు[3]==0) && (a->s6_పదాలు[4]==0) && (a->s6_పదాలు[5]==0) && !((a->s6_పదాలు[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_MC_NODELOCAL(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి IN6_IS_ADDR_MULTICAST(a) && ((a->s6_బైట్లు[1] & 0xf)==1); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_MC_LINKLOCAL(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి IN6_IS_ADDR_MULTICAST(a) && ((a->s6_బైట్లు[1] & 0xf)==2); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_MC_SITELOCAL(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి IN6_IS_ADDR_MULTICAST(a) && ((a->s6_బైట్లు[1] & 0xf)==5); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_MC_ORGLOCAL(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి IN6_IS_ADDR_MULTICAST(a) && ((a->s6_బైట్లు[1] & 0xf)==8); }
WS2TCPIP_INLINE పూర్ణాంకం IN6_IS_ADDR_MC_GLOBAL(స్థిరరాశి నిర్మాణం in6_addr *a) { తిరిగి IN6_IS_ADDR_MULTICAST(a) && ((a->s6_బైట్లు[1] & 0xf)==0xe); }
WS2TCPIP_INLINE పూర్ణాంకం IN6ADDR_ISANY(స్థిరరాశి నిర్మాణం sockaddr_in6 *a) { తిరిగి ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE పూర్ణాంకం IN6ADDR_ISLOOPBACK(స్థిరరాశి నిర్మాణం sockaddr_in6 *a) { తిరిగి ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE శూన్య IN6_సమితి_ADDR_UNSPECIFIED(నిర్మాణం in6_addr *a) { memset(a->s6_బైట్లు,0,పరిమాణం(నిర్మాణం in6_addr)); }
WS2TCPIP_INLINE శూన్య IN6_సమితి_ADDR_LOOPBACK(నిర్మాణం in6_addr *a) {
  memset(a->s6_బైట్లు,0,పరిమాణం(నిర్మాణం in6_addr));
  a->s6_బైట్లు[15] = 1;
}
WS2TCPIP_INLINE శూన్య IN6ADDR_SETANY(నిర్మాణం sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_పోర్టు = 0;
  a->sin6_flowinfo = 0;
  IN6_సమితి_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE శూన్య IN6ADDR_SETLOOPBACK(నిర్మాణం sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_పోర్టు = 0;
  a->sin6_flowinfo = 0;
  IN6_సమితి_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#అయితే_ముగింపు /* !__CRT__NO_INLINE */

రకనిర్వచనం సంఘం sockaddr_gen {
  నిర్మాణం sockaddr చిరునామా_2;
  నిర్మాణం sockaddr_లోపల చిరునామా_లోపల;
  నిర్మాణం sockaddr_in6_old చిరునామా_In6;
} sockaddr_gen;

రకనిర్వచనం నిర్మాణం _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen ii_చిరునామా;
  sockaddr_gen ii_ప్రసారం_చిరునామా;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

రకనిర్వచనం నిర్మాణం _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_చిరునామా_2 ii_చిరునామా;
  SOCKET_చిరునామా_2 ii_ప్రసారం_చిరునామా;
  SOCKET_చిరునామా_2 iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#నిర్వచించు IFF_పైకి 0x00000001
#నిర్వచించు IFF_ప్రసారం 0x00000002
#నిర్వచించు IFF_LOOPBACK 0x00000004
#నిర్వచించు IFF_POINTTOPOINT 0x00000008
#నిర్వచించు IFF_MULTICAST 0x00000010

రకనిర్వచనం నిర్మాణం లోపల_pktinfo {
  లోపల_ADDR ipi_addr;
  UINT ipi_ifindex;
} లోపల_PKTINFO;

C_ASSERT(పరిమాణం(లోపల_PKTINFO)==8);

రకనిర్వచనం నిర్మాణం in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(పరిమాణం(IN6_PKTINFO)==20);

#నిర్వచించు EAI_AGAIN WSATRY_AGAIN
#నిర్వచించు EAI_BADFLAGS WSAEINVAL
#నిర్వచించు EAI_FAIL WSANO_RECOVERY
#నిర్వచించు EAI_FAMILY WSAEAFNOSUPPORT
#నిర్వచించు EAI_జ్ఞాపకం WSA_NOT_ENOUGH_జ్ఞాపకం

#నిర్వచించు EAI_NONAME WSAHOST_NOT_దొరికింది
#నిర్వచించు EAI_SERVICE WSATYPE_NOT_దొరికింది
#నిర్వచించు EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#నిర్వచించు EAI_NODATA EAI_NONAME

రకనిర్వచనం నిర్మాణం addrinfo {
  పూర్ణాంకం ai_flags;
  పూర్ణాంకం ai_family;
  పూర్ణాంకం ai_socktype;
  పూర్ణాంకం ai_protocol;
  కొలత_t ai_addrlen;
  అక్షరం *ai_canonname;
  నిర్మాణం sockaddr *ai_addr;
  నిర్మాణం addrinfo *ai_తదుపరి;
} ADDRINFOA,*PADDRINFOA;

రకనిర్వచనం నిర్మాణం addrinfoW {
  పూర్ణాంకం ai_flags;
  పూర్ణాంకం ai_family;
  పూర్ణాంకం ai_socktype;
  పూర్ణాంకం ai_protocol;
  కొలత_t ai_addrlen;
  PWSTR ai_canonname;
  నిర్మాణం sockaddr *ai_addr;
  నిర్మాణం addrinfoW *ai_తదుపరి;
} ADDRINFOW,*PADDRINFOW;

#నిర్వచితమైతే UNICODE
రకనిర్వచనం ADDRINFOW ADDRINFOT,*PADDRINFOT;
#లేకపోతే
రకనిర్వచనం ADDRINFOA ADDRINFOT,*PADDRINFOT;
#అయితే_ముగింపు

రకనిర్వచనం ADDRINFOA ADDRINFO,*LPADDRINFO;

#నిర్వచించు AI_PASSIVE 0x1
#నిర్వచించు AI_CANONNAME 0x2
#నిర్వచించు AI_NUMERICHOST 0x4

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు GetAddrInfo GetAddrInfoW
#లేకపోతే
#నిర్వచించు GetAddrInfo GetAddrInfoA
#అయితే_ముగింపు

  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI getaddrinfo(స్థిరరాశి అక్షరం *nodename,స్థిరరాశి అక్షరం *servname,స్థిరరాశి నిర్మాణం addrinfo *hints,నిర్మాణం addrinfo **res);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI GetAddrInfoW(PCWSTR p_కణుపు_Name,PCWSTR pServiceName,స్థిరరాశి ADDRINFOW *pHints,PADDRINFOW *pp_ఫలితం);

#నిర్వచించు GetAddrInfoA getaddrinfo

#ఒకవేళ INCL_WINSOCK_API_TYPEDEFS
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_GETADDRINFO)(స్థిరరాశి అక్షరం *nodename,స్థిరరాశి అక్షరం *servname,స్థిరరాశి నిర్మాణం addrinfo *hints,నిర్మాణం addrinfo **res);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_కణుపు_Name,PCWSTR pServiceName,స్థిరరాశి ADDRINFOW *pHints,PADDRINFOW *pp_ఫలితం);

#నిర్వచించు LPFN_GETADDRINFOA LPFN_GETADDRINFO

#నిర్వచితమైతే UNICODE
#నిర్వచించు LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#లేకపోతే
#నిర్వచించు LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు FreeAddrInfo FreeAddrInfoW
#లేకపోతే
#నిర్వచించు FreeAddrInfo FreeAddrInfoA
#అయితే_ముగింపు

  WINSOCK_API_LINKAGE శూన్య WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE శూన్య WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#నిర్వచించు FreeAddrInfoA freeaddrinfo

#ఒకవేళ INCL_WINSOCK_API_TYPEDEFS
  రకనిర్వచనం శూన్య (WSAAPI *LPFN_FREEADDRINFO)(నిర్మాణం addrinfo *ai);
  రకనిర్వచనం శూన్య (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#నిర్వచించు LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#నిర్వచితమైతే UNICODE
#నిర్వచించు LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#లేకపోతే
#నిర్వచించు LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#అయితే_ముగింపు
#అయితే_ముగింపు

#సూచన నెట్టు_macro("socklen_t")
#నిర్వచనం_రద్దు socklen_t

  రకనిర్వచనం పూర్ణాంకం socklen_t;

#నిర్వచితమైతే UNICODE
#నిర్వచించు GetNameInfo GetNameInfoW
#లేకపోతే
#నిర్వచించు GetNameInfo GetNameInfoA
#అయితే_ముగింపు

  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI getnameinfo(స్థిరరాశి నిర్మాణం sockaddr *sa,socklen_t salen,అక్షరం *host,DWORD hostlen,అక్షరం *serv,DWORD servlen,పూర్ణాంకం flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(స్థిరరాశి SOCKADDR *pSockaddr,socklen_t Sockaddr_నిడివి,PWCHAR p_కణుపు_బఫరు,DWORD కణుపు_బఫరు_కొలత,PWCHAR p_Service_బఫరు,DWORD Service_బఫరు_కొలత,INT Flags);

#నిర్వచించు GetNameInfoA getnameinfo

#ఒకవేళ INCL_WINSOCK_API_TYPEDEFS
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_GETNAMEINFO)(స్థిరరాశి నిర్మాణం sockaddr *sa,socklen_t salen,అక్షరం *host,DWORD hostlen,అక్షరం *serv,DWORD servlen,పూర్ణాంకం flags);
  రకనిర్వచనం INT (WSAAPI *LPFN_GETNAMEINFOW)(స్థిరరాశి SOCKADDR *pSockaddr,socklen_t Sockaddr_నిడివి,PWCHAR p_కణుపు_బఫరు,DWORD కణుపు_బఫరు_కొలత,PWCHAR p_Service_బఫరు,DWORD Service_బఫరు_కొలత,INT Flags);

#నిర్వచించు LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#నిర్వచితమైతే UNICODE
#నిర్వచించు LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#లేకపోతే
#నిర్వచించు LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#అయితే_ముగింపు
#అయితే_ముగింపు

#సూచన తీయి_macro("socklen_t")

#నిర్వచితమైతే UNICODE
#నిర్వచించు gai_strerror gai_strerrorW
#లేకపోతే
#నిర్వచించు gai_strerror gai_strerrorA
#అయితే_ముగింపు

#నిర్వచించు GAI_STRERROR_బఫరు_కొలత 1024

అక్షరం *gai_strerrorA (పూర్ణాంకం);
WCHAR *gai_strerrorW(పూర్ణాంకం);

#నిర్వచించు NI_MAXHOST 1025
#నిర్వచించు NI_MAXSERV 32

#నిర్వచించు INET_ADDRSTRLEN 22
#నిర్వచించు INET6_ADDRSTRLEN 65

#నిర్వచించు NI_NOFQDN 0x01
#నిర్వచించు NI_NUMERICHOST 0x02
#నిర్వచించు NI_NAMEREQD 0x04
#నిర్వచించు NI_NUMERICSERV 0x08
#నిర్వచించు NI_DGRAM 0x10

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#అయితే_ముగింపు
