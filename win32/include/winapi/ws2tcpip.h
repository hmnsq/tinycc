/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WS2TCPIP_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WS2TCPIP_H

#ਜੇ __GNUC__ >=3
#ਹਦਾਇਤ GCC system_ਸਿਰਲੇਖ
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <ws2ipdef.h>

ਬਣਤਰ ip_msfilter {
  ਬਣਤਰ ਵਿੱਚ_addr imsf_multiaddr;
  ਬਣਤਰ ਵਿੱਚ_addr imsf_interface;
  u_long imsf_fmode;
  u_long imsf_numsrc;
  ਬਣਤਰ ਵਿੱਚ_addr imsf_slist[1];
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_MSFILTER_ਮਾਪ(numsrc) (ਆਕਾਰ(ਬਣਤਰ ip_msfilter)-ਆਕਾਰ(ਬਣਤਰ ਵਿੱਚ_addr) + (numsrc)*ਆਕਾਰ(ਬਣਤਰ ਵਿੱਚ_addr))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MCAST_INCLUDE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MCAST_EXCLUDE 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_GET_INTERFACE_LIST _IOR('t',127,u_long)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_GET_INTERFACE_LIST_EX _IOR('t',126,u_long)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ਸੈੱਟ_MULTICAST_FILTER _IOW('t',125,u_long)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_GET_MULTICAST_FILTER _IOW('t',124 | IOC_ਵਿੱਚ,u_long)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_OPTIONS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_HDRINCL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_TOS 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_TTL 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_MULTICAST_IF 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_MULTICAST_TTL 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_MULTICAST_LOOP 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_ਜੋੜੋ_MEMBERSHIP 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_DROP_MEMBERSHIP 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_DONTFRAGMENT 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_ਜੋੜੋ_ਸਰੋਤ_MEMBERSHIP 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_DROP_ਸਰੋਤ_MEMBERSHIP 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_ਖੰਡ_ਸਰੋਤ 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_UNBLOCK_ਸਰੋਤ 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_PKTINFO 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IP_RECEIVE_ਪ੍ਰਸਾਰਣ 22

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_HDRINCL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_UNICAST_HOPS 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_MULTICAST_IF 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_MULTICAST_HOPS 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_MULTICAST_LOOP 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_ਜੋੜੋ_MEMBERSHIP 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_DROP_MEMBERSHIP 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_JOIN_ਸਮੂਹ IPV6_ਜੋੜੋ_MEMBERSHIP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_LEAVE_ਸਮੂਹ IPV6_DROP_MEMBERSHIP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_PKTINFO 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_HOPLIMIT 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPV6_PROTECTION_LEVEL 23

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROTECTION_LEVEL_UNRESTRICTED 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROTECTION_LEVEL_DEFAULT 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROTECTION_LEVEL_RESTRICTED 30

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UDP_NOCHECKSUM 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UDP_CHECKSUM_COVERAGE 20

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCP_EXPEDITED_1122 0x0002

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ s6_addr

ਬਣਤਰ in6_addr {
  __MINGW_EXTENSION ਸੰਘ {
    u_char Byte[16];
    u_short ਸ਼ਬਦ_2[8];
  } u;
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_addr6 in6_addr

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S6_un u
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _S6_u8 Byte
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ s6_addr _S6_un._S6_u8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ s6_ਬਾਈਟਾਂ u.Byte
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ s6_ਸ਼ਬਦ u.ਸ਼ਬਦ_2
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ipv6_mreq {
  ਬਣਤਰ in6_addr ipv6mr_multiaddr;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ipv6mr_interface;
} IPV6_MREQ;

ਬਣਤਰ sockaddr_in6_old {
  ਛੋਟਾ sin6_family;
  u_short sin6_ਪੋਰਟ;
  u_long sin6_flowinfo;
  ਬਣਤਰ in6_addr sin6_addr;
};

ਬਣਤਰ sockaddr_in6 {
  ਛੋਟਾ sin6_family;
  u_short sin6_ਪੋਰਟ;
  u_long sin6_flowinfo;
  ਬਣਤਰ in6_addr sin6_addr;
  u_long sin6_scope_id;
};

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ in6_addr IN6_ADDR;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ in6_addr *PIN6_ADDR;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ in6_addr *LPIN6_ADDR;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr_in6 SOCKADDR_IN6;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr_in6 *PSOCKADDR_IN6;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr_in6 *LPSOCKADDR_IN6;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ਪੋਰਟ(ssp) (((ਬਣਤਰ sockaddr_ਵਿੱਚ*)(ssp))->sin_ਪੋਰਟ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IN6ADDR_ANY_INIT { 0 }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IN6ADDR_LOOPBACK_INIT { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  ਬਾਹਰੀ ਅਚਲ ਬਣਤਰ in6_addr in6addr_any;
  ਬਾਹਰੀ ਅਚਲ ਬਣਤਰ in6_addr in6addr_loopback;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS2TCPIP_INLINE __CRT_INLINE

ਪੂਰਨ IN6_ADDR_EQUAL(ਅਚਲ ਬਣਤਰ in6_addr *,ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_UNSPECIFIED(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_LOOPBACK(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_MULTICAST(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_LINKLOCAL(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_SITELOCAL(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_V4MAPPED(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_V4COMPAT(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_MC_NODELOCAL(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_MC_LINKLOCAL(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_MC_SITELOCAL(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_MC_ORGLOCAL(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6_IS_ADDR_MC_GLOBAL(ਅਚਲ ਬਣਤਰ in6_addr *);
ਪੂਰਨ IN6ADDR_ISANY(ਅਚਲ ਬਣਤਰ sockaddr_in6 *);
ਪੂਰਨ IN6ADDR_ISLOOPBACK(ਅਚਲ ਬਣਤਰ sockaddr_in6 *);
ਖਾਲੀ IN6_ਸੈੱਟ_ADDR_UNSPECIFIED(ਬਣਤਰ in6_addr *);
ਖਾਲੀ IN6_ਸੈੱਟ_ADDR_LOOPBACK(ਬਣਤਰ in6_addr *);
ਖਾਲੀ IN6ADDR_SETANY(ਬਣਤਰ sockaddr_in6 *);
ਖਾਲੀ IN6ADDR_SETLOOPBACK(ਬਣਤਰ sockaddr_in6 *);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __CRT__NO_INLINE
WS2TCPIP_INLINE ਪੂਰਨ IN6_ADDR_EQUAL(ਅਚਲ ਬਣਤਰ in6_addr *a,ਅਚਲ ਬਣਤਰ in6_addr *b) { ਵਾਪਸ (memcmp(a,b,ਆਕਾਰ(ਬਣਤਰ in6_addr))==0); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_UNSPECIFIED(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ ((a->s6_ਸ਼ਬਦ[0]==0) && (a->s6_ਸ਼ਬਦ[1]==0) && (a->s6_ਸ਼ਬਦ[2]==0) && (a->s6_ਸ਼ਬਦ[3]==0) && (a->s6_ਸ਼ਬਦ[4]==0) && (a->s6_ਸ਼ਬਦ[5]==0) && (a->s6_ਸ਼ਬਦ[6]==0) && (a->s6_ਸ਼ਬਦ[7]==0)); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_LOOPBACK(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ ((a->s6_ਸ਼ਬਦ[0]==0) && (a->s6_ਸ਼ਬਦ[1]==0) && (a->s6_ਸ਼ਬਦ[2]==0) && (a->s6_ਸ਼ਬਦ[3]==0) && (a->s6_ਸ਼ਬਦ[4]==0) && (a->s6_ਸ਼ਬਦ[5]==0) && (a->s6_ਸ਼ਬਦ[6]==0) && (a->s6_ਸ਼ਬਦ[7]==0x0100)); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_MULTICAST(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ (a->s6_ਬਾਈਟਾਂ[0]==0xff); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_LINKLOCAL(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ ((a->s6_ਬਾਈਟਾਂ[0]==0xfe) && ((a->s6_ਬਾਈਟਾਂ[1] & 0xc0)==0x80)); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_SITELOCAL(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ ((a->s6_ਬਾਈਟਾਂ[0]==0xfe) && ((a->s6_ਬਾਈਟਾਂ[1] & 0xc0)==0xc0)); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_V4MAPPED(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ ((a->s6_ਸ਼ਬਦ[0]==0) && (a->s6_ਸ਼ਬਦ[1]==0) && (a->s6_ਸ਼ਬਦ[2]==0) && (a->s6_ਸ਼ਬਦ[3]==0) && (a->s6_ਸ਼ਬਦ[4]==0) && (a->s6_ਸ਼ਬਦ[5]==0xffff)); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_V4COMPAT(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ ((a->s6_ਸ਼ਬਦ[0]==0) && (a->s6_ਸ਼ਬਦ[1]==0) && (a->s6_ਸ਼ਬਦ[2]==0) && (a->s6_ਸ਼ਬਦ[3]==0) && (a->s6_ਸ਼ਬਦ[4]==0) && (a->s6_ਸ਼ਬਦ[5]==0) && !((a->s6_ਸ਼ਬਦ[6]==0) && (a->s6_addr[14]==0) && ((a->s6_addr[15]==0) || (a->s6_addr[15]==1)))); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_MC_NODELOCAL(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ਬਾਈਟਾਂ[1] & 0xf)==1); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_MC_LINKLOCAL(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ਬਾਈਟਾਂ[1] & 0xf)==2); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_MC_SITELOCAL(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ਬਾਈਟਾਂ[1] & 0xf)==5); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_MC_ORGLOCAL(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ਬਾਈਟਾਂ[1] & 0xf)==8); }
WS2TCPIP_INLINE ਪੂਰਨ IN6_IS_ADDR_MC_GLOBAL(ਅਚਲ ਬਣਤਰ in6_addr *a) { ਵਾਪਸ IN6_IS_ADDR_MULTICAST(a) && ((a->s6_ਬਾਈਟਾਂ[1] & 0xf)==0xe); }
WS2TCPIP_INLINE ਪੂਰਨ IN6ADDR_ISANY(ਅਚਲ ਬਣਤਰ sockaddr_in6 *a) { ਵਾਪਸ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_UNSPECIFIED(&a->sin6_addr)); }
WS2TCPIP_INLINE ਪੂਰਨ IN6ADDR_ISLOOPBACK(ਅਚਲ ਬਣਤਰ sockaddr_in6 *a) { ਵਾਪਸ ((a->sin6_family==AF_INET6) && IN6_IS_ADDR_LOOPBACK(&a->sin6_addr)); }
WS2TCPIP_INLINE ਖਾਲੀ IN6_ਸੈੱਟ_ADDR_UNSPECIFIED(ਬਣਤਰ in6_addr *a) { memset(a->s6_ਬਾਈਟਾਂ,0,ਆਕਾਰ(ਬਣਤਰ in6_addr)); }
WS2TCPIP_INLINE ਖਾਲੀ IN6_ਸੈੱਟ_ADDR_LOOPBACK(ਬਣਤਰ in6_addr *a) {
  memset(a->s6_ਬਾਈਟਾਂ,0,ਆਕਾਰ(ਬਣਤਰ in6_addr));
  a->s6_ਬਾਈਟਾਂ[15] = 1;
}
WS2TCPIP_INLINE ਖਾਲੀ IN6ADDR_SETANY(ਬਣਤਰ sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_ਪੋਰਟ = 0;
  a->sin6_flowinfo = 0;
  IN6_ਸੈੱਟ_ADDR_UNSPECIFIED(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
WS2TCPIP_INLINE ਖਾਲੀ IN6ADDR_SETLOOPBACK(ਬਣਤਰ sockaddr_in6 *a) {
  a->sin6_family = AF_INET6;
  a->sin6_ਪੋਰਟ = 0;
  a->sin6_flowinfo = 0;
  IN6_ਸੈੱਟ_ADDR_LOOPBACK(&a->sin6_addr);
  a->sin6_scope_id = 0;
}
#ਜੇ_ਅੰਤ /* !__CRT__NO_INLINE */

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਸੰਘ sockaddr_gen {
  ਬਣਤਰ sockaddr ਪਤਾ_2;
  ਬਣਤਰ sockaddr_ਵਿੱਚ ਪਤਾ_ਵਿੱਚ;
  ਬਣਤਰ sockaddr_in6_old ਪਤਾ_In6;
} sockaddr_gen;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _INTERFACE_INFO {
  u_long iiFlags;
  sockaddr_gen ii_ਪਤਾ;
  sockaddr_gen ii_ਪ੍ਰਸਾਰਣ_ਪਤਾ;
  sockaddr_gen iiNetmask;
} INTERFACE_INFO,*LPINTERFACE_INFO;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _INTERFACE_INFO_EX {
  u_long iiFlags;
  SOCKET_ਪਤਾ_2 ii_ਪਤਾ;
  SOCKET_ਪਤਾ_2 ii_ਪ੍ਰਸਾਰਣ_ਪਤਾ;
  SOCKET_ਪਤਾ_2 iiNetmask;
} INTERFACE_INFO_EX,*LPINTERFACE_INFO_EX;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IFF_ਉੱਪਰ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IFF_ਪ੍ਰਸਾਰਣ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IFF_LOOPBACK 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IFF_POINTTOPOINT 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IFF_MULTICAST 0x00000010

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਵਿੱਚ_pktinfo {
  ਵਿੱਚ_ADDR ipi_addr;
  UINT ipi_ifindex;
} ਵਿੱਚ_PKTINFO;

C_ASSERT(ਆਕਾਰ(ਵਿੱਚ_PKTINFO)==8);

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ in6_pktinfo {
  IN6_ADDR ipi6_addr;
  UINT ipi6_ifindex;
} IN6_PKTINFO;

C_ASSERT(ਆਕਾਰ(IN6_PKTINFO)==20);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAI_AGAIN WSATRY_AGAIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAI_BADFLAGS WSAEINVAL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAI_FAIL WSANO_RECOVERY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAI_FAMILY WSAEAFNOSUPPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAI_ਸਮ੍ਰਿਤੀ WSA_NOT_ENOUGH_ਸਮ੍ਰਿਤੀ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAI_NONAME WSAHOST_NOT_ਮਿਲਿਆ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAI_SERVICE WSATYPE_NOT_ਮਿਲਿਆ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAI_SOCKTYPE WSAESOCKTNOSUPPORT

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAI_NODATA EAI_NONAME

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ addrinfo {
  ਪੂਰਨ ai_flags;
  ਪੂਰਨ ai_family;
  ਪੂਰਨ ai_socktype;
  ਪੂਰਨ ai_protocol;
  ਮਾਪ_t ai_addrlen;
  ਅੱਖਰ *ai_canonname;
  ਬਣਤਰ sockaddr *ai_addr;
  ਬਣਤਰ addrinfo *ai_ਅਗਲਾ;
} ADDRINFOA,*PADDRINFOA;

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ addrinfoW {
  ਪੂਰਨ ai_flags;
  ਪੂਰਨ ai_family;
  ਪੂਰਨ ai_socktype;
  ਪੂਰਨ ai_protocol;
  ਮਾਪ_t ai_addrlen;
  PWSTR ai_canonname;
  ਬਣਤਰ sockaddr *ai_addr;
  ਬਣਤਰ addrinfoW *ai_ਅਗਲਾ;
} ADDRINFOW,*PADDRINFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ADDRINFOW ADDRINFOT,*PADDRINFOT;
#ਨਹੀਂਤਾਂ
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ADDRINFOA ADDRINFOT,*PADDRINFOT;
#ਜੇ_ਅੰਤ

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ADDRINFOA ADDRINFO,*LPADDRINFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AI_PASSIVE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AI_CANONNAME 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AI_NUMERICHOST 0x4

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetAddrInfo GetAddrInfoW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetAddrInfo GetAddrInfoA
#ਜੇ_ਅੰਤ

  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI getaddrinfo(ਅਚਲ ਅੱਖਰ *nodename,ਅਚਲ ਅੱਖਰ *servname,ਅਚਲ ਬਣਤਰ addrinfo *hints,ਬਣਤਰ addrinfo **res);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI GetAddrInfoW(PCWSTR p_ਗੰਢ_Name,PCWSTR pServiceName,ਅਚਲ ADDRINFOW *pHints,PADDRINFOW *pp_ਨਤੀਜਾ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetAddrInfoA getaddrinfo

#ਜੇ INCL_WINSOCK_API_TYPEDEFS
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_GETADDRINFO)(ਅਚਲ ਅੱਖਰ *nodename,ਅਚਲ ਅੱਖਰ *servname,ਅਚਲ ਬਣਤਰ addrinfo *hints,ਬਣਤਰ addrinfo **res);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_GETADDRINFOW)(PCWSTR p_ਗੰਢ_Name,PCWSTR pServiceName,ਅਚਲ ADDRINFOW *pHints,PADDRINFOW *pp_ਨਤੀਜਾ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_GETADDRINFOA LPFN_GETADDRINFO

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_GETADDRINFOT LPFN_GETADDRINFOW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_GETADDRINFOT LPFN_GETADDRINFOA
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FreeAddrInfo FreeAddrInfoW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FreeAddrInfo FreeAddrInfoA
#ਜੇ_ਅੰਤ

  WINSOCK_API_LINKAGE ਖਾਲੀ WSAAPI freeaddrinfo(LPADDRINFO pAddrInfo);
  WINSOCK_API_LINKAGE ਖਾਲੀ WSAAPI FreeAddrInfoW(PADDRINFOW pAddrInfo);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FreeAddrInfoA freeaddrinfo

#ਜੇ INCL_WINSOCK_API_TYPEDEFS
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (WSAAPI *LPFN_FREEADDRINFO)(ਬਣਤਰ addrinfo *ai);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (WSAAPI *LPFN_FREEADDRINFOW)(PADDRINFOW pAddrInfo);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_FREEADDRINFOA LPFN_FREEADDRINFO

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_FREEADDRINFOT LPFN_FREEADDRINFOW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_FREEADDRINFOT LPFN_FREEADDRINFOA
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ ਧੱਕੋ_macro("socklen_t")
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ socklen_t

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ socklen_t;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetNameInfo GetNameInfoW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetNameInfo GetNameInfoA
#ਜੇ_ਅੰਤ

  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI getnameinfo(ਅਚਲ ਬਣਤਰ sockaddr *sa,socklen_t salen,ਅੱਖਰ *host,DWORD hostlen,ਅੱਖਰ *serv,DWORD servlen,ਪੂਰਨ flags);
  WINSOCK_API_LINKAGE INT WSAAPI GetNameInfoW(ਅਚਲ SOCKADDR *pSockaddr,socklen_t Sockaddr_ਲੰਮਾਈ,PWCHAR p_ਗੰਢ_ਬਫਰ,DWORD ਗੰਢ_ਬਫਰ_ਮਾਪ,PWCHAR p_Service_ਬਫਰ,DWORD Service_ਬਫਰ_ਮਾਪ,INT Flags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetNameInfoA getnameinfo

#ਜੇ INCL_WINSOCK_API_TYPEDEFS
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_GETNAMEINFO)(ਅਚਲ ਬਣਤਰ sockaddr *sa,socklen_t salen,ਅੱਖਰ *host,DWORD hostlen,ਅੱਖਰ *serv,DWORD servlen,ਪੂਰਨ flags);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_GETNAMEINFOW)(ਅਚਲ SOCKADDR *pSockaddr,socklen_t Sockaddr_ਲੰਮਾਈ,PWCHAR p_ਗੰਢ_ਬਫਰ,DWORD ਗੰਢ_ਬਫਰ_ਮਾਪ,PWCHAR p_Service_ਬਫਰ,DWORD Service_ਬਫਰ_ਮਾਪ,INT Flags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_GETNAMEINFOA LPFN_GETNAMEINFO

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_GETNAMEINFOT LPFN_GETNAMEINFOW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_GETNAMEINFOT LPFN_GETNAMEINFOA
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਹਦਾਇਤ ਕੱਢੋ_macro("socklen_t")

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gai_strerror gai_strerrorW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ gai_strerror gai_strerrorA
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GAI_STRERROR_ਬਫਰ_ਮਾਪ 1024

ਅੱਖਰ *gai_strerrorA (ਪੂਰਨ);
WCHAR *gai_strerrorW(ਪੂਰਨ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NI_MAXHOST 1025
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NI_MAXSERV 32

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INET_ADDRSTRLEN 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INET6_ADDRSTRLEN 65

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NI_NOFQDN 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NI_NUMERICHOST 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NI_NAMEREQD 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NI_NUMERICSERV 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NI_DGRAM 0x10

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
