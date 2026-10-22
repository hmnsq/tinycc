/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WS2TCPIP_H
#ವ್ಯಾಖ್ಯಾನಿಸು _WS2TCPIP_H

#ಆದರೆ __GNUC__ >=3
#ಸೂಚನೆ GCC system_ಶೀರ್ಷಿಕೆ
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <ws2ipdef.h>

ರಚನೆ ip_msfilter {
  ರಚನೆ ಒಳ_addr imsf_multiaddr;
  ರಚನೆ ಒಳ_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  ರಚನೆ ಒಳ_addr imsf_slist[1];
};

#ವ್ಯಾಖ್ಯಾನಿಸು IP_MSFILTER_ಗಾತ್ರ(numsrc) (ಗಾತ್ರ(ರಚನೆ ip_msfilter)-ಗಾತ್ರ(ರಚನೆ ಒಳ_addr) + (numsrc)*ಗಾತ್ರ(ರಚನೆ ಒಳ_addr))

#ವ್ಯಾಖ್ಯಾನಿಸು MCAST_INCLUDE 0
#ವ್ಯಾಖ್ಯಾನಿಸು MCAST_EXCLUDE 1

#ವ್ಯಾಖ್ಯಾನಿಸು SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#ವ್ಯಾಖ್ಯಾನಿಸು SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ಗಣ_MULTICAST_FILTER _IOW('t',125,u_long)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_ಒಳ,u_long)

#ವ್ಯಾಖ್ಯಾನಿಸು IP_OPTIONS 1
#ವ್ಯಾಖ್ಯಾನಿಸು IP_HDRINCL 2
#ವ್ಯಾಖ್ಯಾನಿಸು IP_TOS 3
#ವ್ಯಾಖ್ಯಾನಿಸು IP_TTL 4
#ವ್ಯಾಖ್ಯಾನಿಸು IP_MULTICAST_IF 9
#ವ್ಯಾಖ್ಯಾನಿಸು IP_MULTICAST_TTL 10
#ವ್ಯಾಖ್ಯಾನಿಸು IP_MULTICAST_LOOP 11
#ವ್ಯಾಖ್ಯಾನಿಸು IP_ಕೂಡಿಸು_MEMBERSHIP 12
#ವ್ಯಾಖ್ಯಾನಿಸು IP_DROP_MEMBERSHIP 13
#ವ್ಯಾಖ್ಯಾನಿಸು IP_DONTFRAGMENT 14
#ವ್ಯಾಖ್ಯಾನಿಸು IP_ಕೂಡಿಸು_ಮೂಲ_MEMBERSHIP 15
#ವ್ಯಾಖ್ಯಾನಿಸು IP_DROP_ಮೂಲ_MEMBERSHIP 16
#ವ್ಯಾಖ್ಯಾನಿಸು IP_ಖಂಡ_ಮೂಲ 17
#ವ್ಯಾಖ್ಯಾನಿಸು IP_UNBLOCK_ಮೂಲ 18
#ವ್ಯಾಖ್ಯಾನಿಸು IP_PKTINFO 19
#ವ್ಯಾಖ್ಯಾನಿಸು IP_RECEIVE_ಪ್ರಸಾರ 22

#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_HDRINCL 2
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_UNICAST_HOPS 4
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_MULTICAST_IF 9
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_MULTICAST_HOPS 10
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_MULTICAST_LOOP 11
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_ಕೂಡಿಸು_MEMBERSHIP 12
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_DROP_MEMBERSHIP 13
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_JOIN_ಗುಂಪು IPV6_ಕೂಡಿಸು_MEMBERSHIP
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_LEAVE_ಗುಂಪು IPV6_DROP_MEMBERSHIP
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_PKTINFO 19
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_HOPLIMIT 21
#ವ್ಯಾಖ್ಯಾನಿಸು IPV6_PROTECTION_LEVEL 23

#ವ್ಯಾಖ್ಯಾನಿಸು PROTECTION_LEVEL_UNRESTRICTED 10
#ವ್ಯಾಖ್ಯಾನಿಸು PROTECTION_LEVEL_DEFAULT 20
#ವ್ಯಾಖ್ಯಾನಿಸು PROTECTION_LEVEL_RESTRICTED 30

#ವ್ಯಾಖ್ಯಾನಿಸು UDP_NOCHECKSUM 1
#ವ್ಯಾಖ್ಯಾನಿಸು UDP_CHECKSUM_COVERAGE 20

#ವ್ಯಾಖ್ಯಾನಿಸು TCP_EXPEDITED_1122 0x0002

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ s6_addr

ರಚನೆ in6_addr {
  __MINGW_EXTENSION ಒಕ್ಕೂಟ {
    u_char Byte[16];
    u_short ಶಬ್ದ_2[8];
  } u;
};

#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_addr6 in6_addr

#ವ್ಯಾಖ್ಯಾನಿಸು _S6_un u
#ವ್ಯಾಖ್ಯಾನಿಸು _S6_u8 Byte
#ವ್ಯಾಖ್ಯಾನಿಸು s6_addr _S6_un._S6_u8

#ವ್ಯಾಖ್ಯಾನಿಸು s6_ಬೈಟುಗಳು u.Byte
#ವ್ಯಾಖ್ಯಾನಿಸು s6_ಪದಗಳು u.ಶಬ್ದ_2
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ipv6_mreq {
  ರಚನೆ in6_addr ipv6mr_multiaddr;
  ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ipv6mr_interface;
} IPV6_MREQ;

ರಚನೆ sockaddr_in6_old {
  ಗಿಡ್ಡ sin6_family;
  u_short sin6_ಪೋರ್ಟ್;
  u_long sin6_flowinfo;
  ರಚನೆ in6_addr sin6_addr;
};

ರಚನೆ sockaddr_in6 {
  ಗಿಡ್ಡ sin6_family;
  u_short sin6_ಪೋರ್ಟ್;
  u_long sin6_flowinfo;
  ರಚನೆ in6_addr sin6_addr;
  u_long sin6_scope_id;
};

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ in6_addr IN6_ADDR;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ in6_addr *PIN6_ADDR;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ in6_addr *LPIN6_ADDR;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr_in6 SOCKADDR_IN6;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr_in6 *PSOCKADDR_IN6;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr_in6 *LPSOCKADDR_IN6;

#ವ್ಯಾಖ್ಯಾನಿಸು SS_ಪೋರ್ಟ್(ssp) (((ರಚನೆ sockaddr_ಒಳ*)(ssp))->sin_ಪೋರ್ಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು IN6ADDR_ANY_INIT { 0 }
#ವ್ಯಾಖ್ಯಾನಿಸು IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  ಬಾಹ್ಯ ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr in6addr_any;
  ಬಾಹ್ಯ ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr in6addr_loopback;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು WS2TCPIP_INLINE __CRT_INLINE

ಪೂರ್ಣಾಂಕ IN6_ADDR_EQUAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *,ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_UNSPECIFIED(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_LOOPBACK(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MULTICAST(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_LINKLOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_SITELOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_V4MAPPED(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_V4COMPAT(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_NODELOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_LINKLOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_SITELOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_ORGLOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_GLOBAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *);
ಪೂರ್ಣಾಂಕ IN6ADDR_ISANY(ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr_in6 *);
ಪೂರ್ಣಾಂಕ IN6ADDR_ISLOOPBACK(ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr_in6 *);
ಶೂನ್ಯ IN6_ಗಣ_ADDR_UNSPECIFIED(ರಚನೆ in6_addr *);
ಶೂನ್ಯ IN6_ಗಣ_ADDR_LOOPBACK(ರಚನೆ in6_addr *);
ಶೂನ್ಯ IN6ADDR_SETANY(ರಚನೆ sockaddr_in6 *);
ಶೂನ್ಯ IN6ADDR_SETLOOPBACK(ರಚನೆ sockaddr_in6 *);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __CRT__NO_INLINE
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_ADDR_EQUAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a,ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *b) { ಹಿಂತಿರುಗಿ (memcmp(a,b,ಗಾತ್ರ(ರಚನೆ in6_addr))==0); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_UNSPECIFIED(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ ((a->s6_ಪದಗಳು[0]==0) && (a->s6_ಪದಗಳು[1]==0) && (a->s6_ಪದಗಳು[2]==0) && (a->s6_ಪದಗಳು[3]==0) && (a->s6_ಪದಗಳು[4]==0) && (a->s6_ಪದಗಳು[5]==0) && (a->s6_ಪದಗಳು[6]==0) && (a->s6_ಪದಗಳು[7]==0)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_LOOPBACK(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ ((a->s6_ಪದಗಳು[0]==0) && (a->s6_ಪದಗಳು[1]==0) && (a->s6_ಪದಗಳು[2]==0) && (a->s6_ಪದಗಳು[3]==0) && (a->s6_ಪದಗಳು[4]==0) && (a->s6_ಪದಗಳು[5]==0) && (a->s6_ಪದಗಳು[6]==0) && (a->s6_ಪದಗಳು[7]==0x0100)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MULTICAST(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ (a->s6_ಬೈಟುಗಳು[0]==0xff); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_LINKLOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ ((a->s6_ಬೈಟುಗಳು[0]==0xfe) && ((a->s6_ಬೈಟುಗಳು[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_SITELOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ ((a->s6_ಬೈಟುಗಳು[0]==0xfe) && ((a->s6_ಬೈಟುಗಳು[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_V4MAPPED(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ ((a->s6_ಪದಗಳು[0]==0) && (a->s6_ಪದಗಳು[1]==0) && (a->s6_ಪದಗಳು[2]==0) && (a->s6_ಪದಗಳು[3]==0) && (a->s6_ಪದಗಳು[4]==0) && (a->s6_ಪದಗಳು[5]==0xffff)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_V4COMPAT(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ ((a->s6_ಪದಗಳು[0]==0) && (a->s6_ಪದಗಳು[1]==0) && (a->s6_ಪದಗಳು[2]==0) && (a->s6_ಪದಗಳು[3]==0) && (a->s6_ಪದಗಳು[4]==0) && (a->s6_ಪದಗಳು[5]==0) && !((a->s6_ಪದಗಳು[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_NODELOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ಬೈಟುಗಳು[1] & 0xf)==1); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_LINKLOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ಬೈಟುಗಳು[1] & 0xf)==2); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_SITELOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ಬೈಟುಗಳು[1] & 0xf)==5); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_ORGLOCAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ಬೈಟುಗಳು[1] & 0xf)==8); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6_IS_ADDR_MC_GLOBAL(ಸ್ಥಿರಾಂಕ ರಚನೆ in6_addr *a) { ಹಿಂತಿರುಗಿ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ಬೈಟುಗಳು[1] & 0xf)==0xe); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6ADDR_ISANY(ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr_in6 *a) { ಹಿಂತಿರುಗಿ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE ಪೂರ್ಣಾಂಕ IN6ADDR_ISLOOPBACK(ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr_in6 *a) { ಹಿಂತಿರುಗಿ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE ಶೂನ್ಯ IN6_ಗಣ_ADDR_UNSPECIFIED(ರಚನೆ in6_addr *a) { memset(a->s6_ಬೈಟುಗಳು,0,ಗಾತ್ರ(ರಚನೆ in6_addr)); }
WS2TCPIP_INLINE ಶೂನ್ಯ IN6_ಗಣ_ADDR_LOOPBACK(ರಚನೆ in6_addr *a) {
  memset(a->s6_ಬೈಟುಗಳು,0,ಗಾತ್ರ(ರಚನೆ in6_addr));
  a->s6_ಬೈಟುಗಳು[15] = 1;
}
WS2TCPIP_INLINE ಶೂನ್ಯ IN6ADDR_SETANY(ರಚನೆ sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_ಪೋರ್ಟ್ = 0;
  a->sin6_flowinfo = 0;
  IN6_ಗಣ_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE ಶೂನ್ಯ IN6ADDR_SETLOOPBACK(ರಚನೆ sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_ಪೋರ್ಟ್ = 0;
  a->sin6_flowinfo = 0;
  IN6_ಗಣ_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#ಆದರೆ_ಅಂತ್ಯ /* !__CRT__NO_INLINE */

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಒಕ್ಕೂಟ sockaddr_gen {
  ರಚನೆ sockaddr ವಿಳಾಸ_2;
  ರಚನೆ sockaddr_ಒಳ ವಿಳಾಸ_ಒಳ;
  ರಚನೆ sockaddr_in6_old ವಿಳಾಸ_In6;
} sockaddr_gen;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen ii_ವಿಳಾಸ;
  sockaddr_gen ii_ಪ್ರಸಾರ_ವಿಳಾಸ;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_ವಿಳಾಸ_2 ii_ವಿಳಾಸ;
  SOCKET_ವಿಳಾಸ_2 ii_ಪ್ರಸಾರ_ವಿಳಾಸ;
  SOCKET_ವಿಳಾಸ_2 iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#ವ್ಯಾಖ್ಯಾನಿಸು IFF_ಮೇಲೆ 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು IFF_ಪ್ರಸಾರ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು IFF_LOOPBACK 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು IFF_POINTTOPOINT 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು IFF_MULTICAST 0x00000010

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಒಳ_pktinfo {
  ಒಳ_ADDR ipi_addr;
  UINT ipi_ifindex;
} ಒಳ_PKTINFO;

C_ASSERT(ಗಾತ್ರ(ಒಳ_PKTINFO)==8);

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(ಗಾತ್ರ(IN6_PKTINFO)==20);

#ವ್ಯಾಖ್ಯಾನಿಸು EAI_AGAIN WSATRY_AGAIN
#ವ್ಯಾಖ್ಯಾನಿಸು EAI_BADFLAGS WSAEINVAL
#ವ್ಯಾಖ್ಯಾನಿಸು EAI_FAIL WSANO_RECOVERY
#ವ್ಯಾಖ್ಯಾನಿಸು EAI_FAMILY WSAEAFNOSUPPORT
#ವ್ಯಾಖ್ಯಾನಿಸು EAI_ಸ್ಮರಣೆ WSA_NOT_ENOUGH_ಸ್ಮರಣೆ

#ವ್ಯಾಖ್ಯಾನಿಸು EAI_NONAME WSAHOST_NOT_ಸಿಕ್ಕಿತು
#ವ್ಯಾಖ್ಯಾನಿಸು EAI_SERVICE WSATYPE_NOT_ಸಿಕ್ಕಿತು
#ವ್ಯಾಖ್ಯಾನಿಸು EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#ವ್ಯಾಖ್ಯಾನಿಸು EAI_NODATA EAI_NONAME

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ addrinfo {
  ಪೂರ್ಣಾಂಕ ai_flags;
  ಪೂರ್ಣಾಂಕ ai_family;
  ಪೂರ್ಣಾಂಕ ai_socktype;
  ಪೂರ್ಣಾಂಕ ai_protocol;
  ಗಾತ್ರ_t ai_addrlen;
  ಅಕ್ಷರ *ai_canonname;
  ರಚನೆ sockaddr *ai_addr;
  ರಚನೆ addrinfo *ai_ಮುಂದಿನ;
} ADDRINFOA,*PADDRINFOA;

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ addrinfoW {
  ಪೂರ್ಣಾಂಕ ai_flags;
  ಪೂರ್ಣಾಂಕ ai_family;
  ಪೂರ್ಣಾಂಕ ai_socktype;
  ಪೂರ್ಣಾಂಕ ai_protocol;
  ಗಾತ್ರ_t ai_addrlen;
  PWSTR ai_canonname;
  ರಚನೆ sockaddr *ai_addr;
  ರಚನೆ addrinfoW *ai_ಮುಂದಿನ;
} ADDRINFOW,*PADDRINFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ADDRINFOW ADDRINFOT,*PADDRINFOT;
#ಇಲ್ಲದಿದ್ದರೆ
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ADDRINFOA ADDRINFOT,*PADDRINFOT;
#ಆದರೆ_ಅಂತ್ಯ

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ADDRINFOA ADDRINFO,*LPADDRINFO;

#ವ್ಯಾಖ್ಯಾನಿಸು AI_PASSIVE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು AI_CANONNAME 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು AI_NUMERICHOST 0x4

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetAddrInfo GetAddrInfoW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetAddrInfo GetAddrInfoA
#ಆದರೆ_ಅಂತ್ಯ

  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI getaddrinfo(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nodename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *servname,ಸ್ಥಿರಾಂಕ ರಚನೆ addrinfo *hints,ರಚನೆ addrinfo **res);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI GetAddrInfoW(PCWSTR p_ಗಂಟು_Name,PCWSTR pServiceName,ಸ್ಥಿರಾಂಕ ADDRINFOW *pHints,PADDRINFOW *pp_ಫಲಿತಾಂಶ);

#ವ್ಯಾಖ್ಯಾನಿಸು GetAddrInfoA getaddrinfo

#ಆದರೆ INCL_WINSOCK_API_TYPEDEFS
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_GETADDRINFO)(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *nodename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *servname,ಸ್ಥಿರಾಂಕ ರಚನೆ addrinfo *hints,ರಚನೆ addrinfo **res);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_ಗಂಟು_Name,PCWSTR pServiceName,ಸ್ಥಿರಾಂಕ ADDRINFOW *pHints,PADDRINFOW *pp_ಫಲಿತಾಂಶ);

#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು FreeAddrInfo FreeAddrInfoW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು FreeAddrInfo FreeAddrInfoA
#ಆದರೆ_ಅಂತ್ಯ

  WINSOCK_API_LINKAGE ಶೂನ್ಯ WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE ಶೂನ್ಯ WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#ವ್ಯಾಖ್ಯಾನಿಸು FreeAddrInfoA freeaddrinfo

#ಆದರೆ INCL_WINSOCK_API_TYPEDEFS
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ (WSAAPI *LPFN_FREEADDRINFO)(ರಚನೆ addrinfo *ai);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ ತಳ್ಳು_macro("socklen_t")
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು socklen_t

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ socklen_t;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetNameInfo GetNameInfoW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetNameInfo GetNameInfoA
#ಆದರೆ_ಅಂತ್ಯ

  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI getnameinfo(ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *sa,socklen_t salen,ಅಕ್ಷರ *host,DWORD hostlen,ಅಕ್ಷರ *serv,DWORD servlen,ಪೂರ್ಣಾಂಕ flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ಸ್ಥಿರಾಂಕ SOCKADDR *pSockaddr,socklen_t Sockaddr_ಉದ್ದಳತೆ,PWCHAR p_ಗಂಟು_ಬಫರ್,DWORD ಗಂಟು_ಬಫರ್_ಗಾತ್ರ,PWCHAR p_Service_ಬಫರ್,DWORD Service_ಬಫರ್_ಗಾತ್ರ,INT Flags);

#ವ್ಯಾಖ್ಯಾನಿಸು GetNameInfoA getnameinfo

#ಆದರೆ INCL_WINSOCK_API_TYPEDEFS
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_GETNAMEINFO)(ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *sa,socklen_t salen,ಅಕ್ಷರ *host,DWORD hostlen,ಅಕ್ಷರ *serv,DWORD servlen,ಪೂರ್ಣಾಂಕ flags);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_GETNAMEINFOW)(ಸ್ಥಿರಾಂಕ SOCKADDR *pSockaddr,socklen_t Sockaddr_ಉದ್ದಳತೆ,PWCHAR p_ಗಂಟು_ಬಫರ್,DWORD ಗಂಟು_ಬಫರ್_ಗಾತ್ರ,PWCHAR p_Service_ಬಫರ್,DWORD Service_ಬಫರ್_ಗಾತ್ರ,INT Flags);

#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಸೂಚನೆ ತೆಗೆ_macro("socklen_t")

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು gai_strerror gai_strerrorW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು gai_strerror gai_strerrorA
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು GAI_STRERROR_ಬಫರ್_ಗಾತ್ರ 1024

ಅಕ್ಷರ *gai_strerrorA (ಪೂರ್ಣಾಂಕ);
WCHAR *gai_strerrorW(ಪೂರ್ಣಾಂಕ);

#ವ್ಯಾಖ್ಯಾನಿಸು NI_MAXHOST 1025
#ವ್ಯಾಖ್ಯಾನಿಸು NI_MAXSERV 32

#ವ್ಯಾಖ್ಯಾನಿಸು INET_ADDRSTRLEN 22
#ವ್ಯಾಖ್ಯಾನಿಸು INET6_ADDRSTRLEN 65

#ವ್ಯಾಖ್ಯಾನಿಸು NI_NOFQDN 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು NI_NUMERICHOST 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು NI_NAMEREQD 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು NI_NUMERICSERV 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು NI_DGRAM 0x10

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
