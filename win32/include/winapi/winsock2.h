/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINSOCK2API_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINSOCK2API_

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ INCL_WINSOCK_API_TYPEDEFS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INCL_WINSOCK_API_TYPEDEFS 0
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_WINDOWS
#ਅਨ੍ਤਰ੍ਭਾਵ <windows.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ MAKEWORD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKEWORD(ਨੀਵਾਂ,ਉੱਚਾ) ((ਸ਼ਬਦ_3)(((BYTE)(ਨੀਵਾਂ)) | ((ਸ਼ਬਦ_3)((BYTE)(ਉੱਚਾ))) << 8))
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WINSOCK_ਸੰਸਕਰਣ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSOCK_ਸੰਸਕਰਣ MAKEWORD(2,2)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WINSOCK_API_LINKAGE
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DECLSPEC_IMPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSOCK_API_LINKAGE
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINSOCK_SOCKET_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINSOCK_SOCKET_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ u_char;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ u_short;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ u_int;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ u_long;
  __MINGW_EXTENSION ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ __int64 u_int64;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT_PTR SOCKET;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ FD_SETSIZE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_SETSIZE 64
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ fd_set {
    u_int fd_ਗਿਣਤੀ;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  ਬਾਹਰੀ ਪੂਰਨ WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_CLR(fd,ਸੈੱਟ) ਕਰੋ { u_int __i; ਲਈ(__i = 0;__i < ((fd_set *)(ਸੈੱਟ))->fd_ਗਿਣਤੀ;__i++) { ਜੇ (((fd_set *)(ਸੈੱਟ))->fd_array[__i]==fd) { ਜਦੋਂ (__i < ((fd_set *)(ਸੈੱਟ))->fd_ਗਿਣਤੀ-1) { ((fd_set *)(ਸੈੱਟ))->fd_array[__i] = ((fd_set *)(ਸੈੱਟ))->fd_array[__i+1]; __i++; } ((fd_set *)(ਸੈੱਟ))->fd_ਗਿਣਤੀ--; ਰੋਕੋ; } } } ਜਦੋਂ(0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_SET(fd,ਸੈੱਟ) ਕਰੋ { u_int __i; ਲਈ(__i = 0;__i < ((fd_set *)(ਸੈੱਟ))->fd_ਗਿਣਤੀ;__i++) { ਜੇ (((fd_set *)(ਸੈੱਟ))->fd_array[__i]==(fd)) { ਰੋਕੋ; } } ਜੇ (__i==((fd_set *)(ਸੈੱਟ))->fd_ਗਿਣਤੀ) { ਜੇ (((fd_set *)(ਸੈੱਟ))->fd_ਗਿਣਤੀ < FD_SETSIZE) { ((fd_set *)(ਸੈੱਟ))->fd_array[__i] = (fd); ((fd_set *)(ਸੈੱਟ))->fd_ਗਿਣਤੀ++; } } } ਜਦੋਂ(0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ZERO(ਸੈੱਟ) (((fd_set *)(ਸੈੱਟ))->fd_ਗਿਣਤੀ=0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ISSET(fd,ਸੈੱਟ) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(ਸੈੱਟ))

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TIMEVAL_DEFINED /* also in winsock[2].h */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TIMEVAL_DEFINED
  ਬਣਤਰ timeval {
    ਲੰਮਾ tv_sec;
    ਲੰਮਾ tv_usec;
  };

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#ਜੇ_ਅੰਤ /* _TIMEVAL_DEFINED */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IOCPARM_ਨਕਾਬ 0x7f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IOC_VOID 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IOC_ਬਾਹਰਲਾ 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IOC_ਵਿੱਚ 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IOC_INOUT (IOC_ਵਿੱਚ|IOC_ਬਾਹਰਲਾ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOR(x,y,t) (IOC_ਬਾਹਰਲਾ|(((ਲੰਮਾ)ਆਕਾਰ(t)&IOCPARM_ਨਕਾਬ)<<16)|((x)<<8)|(y))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _IOW(x,y,t) (IOC_ਵਿੱਚ|(((ਲੰਮਾ)ਆਕਾਰ(t)&IOCPARM_ਨਕਾਬ)<<16)|((x)<<8)|(y))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FIONREAD _IOR('f',127,u_long)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FIONBIO _IOW('f',126,u_long)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FIOASYNC _IOW('f',125,u_long)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIOCSHIWAT _IOW('s',0,u_long)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIOCGHIWAT _IOR('s',1,u_long)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIOCSLOWAT _IOW('s',2,u_long)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIOCGLOWAT _IOR('s',3,u_long)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIOCATMARK _IOR('s',7,u_long)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ h_addr h_addr_list[0]

  ਬਣਤਰ hostent {
    ਅੱਖਰ *h_name;
    ਅੱਖਰ **h_aliases;
    ਛੋਟਾ h_addrtype;
    ਛੋਟਾ h_ਲੰਮਾਈ;
    ਅੱਖਰ **h_addr_list;
  };

  ਬਣਤਰ netent {
    ਅੱਖਰ *n_name;
    ਅੱਖਰ **n_aliases;
    ਛੋਟਾ n_addrtype;
    u_long n_net;
  };

  ਬਣਤਰ servent {
    ਅੱਖਰ *s_name;
    ਅੱਖਰ **s_aliases;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    ਅੱਖਰ *s_proto;
    ਛੋਟਾ s_ਪੋਰਟ;
#ਨਹੀਂਤਾਂ
    ਛੋਟਾ s_ਪੋਰਟ;
    ਅੱਖਰ *s_proto;
#ਜੇ_ਅੰਤ
  };

  ਬਣਤਰ protoent {
    ਅੱਖਰ *p_name;
    ਅੱਖਰ **p_aliases;
    ਛੋਟਾ p_proto;
  };

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_IP 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_HOPOPTS 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_ICMP 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_IGMP 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_GGP 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_IPV4 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_TCP 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_PUP 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_UDP 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_IDP 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_IPV6 41
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_ROUTING 43
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_FRAGMENT 44
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_ESP 50
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_AH 51
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_ICMPV6 58
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_NONE 59
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_DSTOPTS 60
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_ND 77
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_ICLFXBM 78

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_RAW 255
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPROTO_MAX 256

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_ECHO 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_DISCARD 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_SYSTAT 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_DAYTIME 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_NETSTAT 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_FTP 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_TELNET 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_SMTP 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_TIMESERVER 37
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_NAMESERVER 42
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_WHOIS 43
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_MTP 57

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_TFTP 69
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_RJE 77
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_FINGER 79
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_TTYLINK 87
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_SUPDUP 95

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_EXECSERVER 512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_LOGINSERVER 513
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_CMDSERVER 514
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_EFSSERVER 520

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_BIFFUDP 512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_WHOSERVER 513
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_ROUTESERVER 520

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IPPORT_RESERVED 1024

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMPLINK_IP 155
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMPLINK_LOWEXPER 156
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMPLINK_HIGHEXPER 158

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ s_addr

  ਬਣਤਰ ਵਿੱਚ_addr {
    ਸੰਘ {
      ਬਣਤਰ { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      ਬਣਤਰ { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ s_addr S_un.S_addr
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ s_host S_un.S_un_b.s_b2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ s_net S_un.S_un_b.s_b1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ s_imp S_un.S_un_w.s_w2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ s_impno S_un.S_un_b.s_b4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ s_lh S_un.S_un_b.s_b3

#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSA(i) (((ਲੰਮਾ)(i) & 0x80000000)==0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSA_NET 0xff000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSA_NSHIFT 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSA_HOST 0x00ffffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSA_MAX 128

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSB(i) (((ਲੰਮਾ)(i) & 0xc0000000)==0x80000000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSB_NET 0xffff0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSB_NSHIFT 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSB_HOST 0x0000ffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSB_MAX 65536

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSC(i) (((ਲੰਮਾ)(i) & 0xe0000000)==0xc0000000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSC_NET 0xffffff00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSC_NSHIFT 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSC_HOST 0x000000ff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSD(i) (((ਲੰਮਾ)(i) & 0xf0000000)==0xe0000000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSD_NET 0xf0000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSD_NSHIFT 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_CLASSD_HOST 0x0fffffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵਿੱਚ_MULTICAST(i) ਵਿੱਚ_CLASSD(i)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INADDR_ANY (u_long)0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INADDR_LOOPBACK 0x7f000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INADDR_ਪ੍ਰਸਾਰਣ (u_long)0xffffffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INADDR_NONE 0xffffffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ADDR_ANY INADDR_ANY

  ਬਣਤਰ sockaddr_ਵਿੱਚ {
    ਛੋਟਾ sin_family;
    u_short sin_ਪੋਰਟ;
    ਬਣਤਰ ਵਿੱਚ_addr sin_addr;
    ਅੱਖਰ sin_zero[8];
  };

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSADESCRIPTION_LEN 256
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSASYS_ਸਥਿਤੀ_LEN 128

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ WSAData {
    ਸ਼ਬਦ_3 w_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3 w_ਉੱਚਾ_ਸੰਸਕਰਣ;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ iMaxSockets;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ iMaxUdpDg;
    ਅੱਖਰ *lpVendorInfo;
    ਅੱਖਰ szDescription[WSADESCRIPTION_LEN+1];
    ਅੱਖਰ sz_System_ਸਥਿਤੀ[WSASYS_ਸਥਿਤੀ_LEN+1];
#ਨਹੀਂਤਾਂ
    ਅੱਖਰ szDescription[WSADESCRIPTION_LEN+1];
    ਅੱਖਰ sz_System_ਸਥਿਤੀ[WSASYS_ਸਥਿਤੀ_LEN+1];
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ iMaxSockets;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ iMaxUdpDg;
    ਅੱਖਰ *lpVendorInfo;
#ਜੇ_ਅੰਤ
  } WSADATA,*LPWSADATA;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVALID_SOCKET (SOCKET)(~0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOCKET_ERROR (-1)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FROM_PROTOCOL_INFO (-1)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOCK_ਧਾਰਾ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOCK_DGRAM 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOCK_RAW 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOCK_RDM 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOCK_SEQPACKET 5

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_DEBUG 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_ACCEPTCONN 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_REUSEADDR 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_KEEPALIVE 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_DONTROUTE 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_ਪ੍ਰਸਾਰਣ 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_USELOOPBACK 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_LINGER 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_OOBINLINE 0x0100

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_DONTLINGER (ਪੂਰਨ)(~SO_LINGER)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_EXCLUSIVEADDRUSE ((ਪੂਰਨ)(~SO_REUSEADDR))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_SNDBUF 0x1001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_RCVBUF 0x1002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_SNDLOWAT 0x1003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_RCVLOWAT 0x1004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_SNDTIMEO 0x1005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_RCVTIMEO 0x1006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_ERROR 0x1007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_TYPE 0x1008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_ਸਮੂਹ_ID 0x2001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_ਸਮੂਹ_ਤਰਜੀਹ 0x2002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_MAX_ਸੁਨੇਹਾ_ਮਾਪ 0x2003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_PROTOCOL_INFOA 0x2004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_PROTOCOL_INFOW 0x2005
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PVD_CONFIG 0x3001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SO_CONDITIONAL_ACCEPT 0x3002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCP_NODELAY 0x0001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_UNSPEC 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_UNIX 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_INET 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_IMPLINK 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_PUP 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_CHAOS 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_NS 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_IPX AF_NS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_ISO 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_OSI AF_ISO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_ECMA 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_DATAKIT 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_CCITT 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_SNA 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_DECnet 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_DLI 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_LAT 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_HYLINK 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_APPLETALK 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_NETBIOS 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_VOICEVIEW 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_FIREFOX 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_UNKNOWN1 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_BAN 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_ATM 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_INET6 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_CLUSTER 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_12844 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_IRDA 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_NETDES 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_TCNPROCESS 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_TCNMESSAGE 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_ICLFXBM 31

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AF_MAX 32

  ਬਣਤਰ sockaddr {
    u_short sa_family;
    ਅੱਖਰ sa_ਅੰਕੜੇ[14];
  };

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SS_MAXSIZE 128
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SS_ALIGNSIZE (8)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_PAD1_ਮਾਪ (_SS_ALIGNSIZE - ਆਕਾਰ (ਛੋਟਾ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_PAD2_ਮਾਪ (_SS_MAXSIZE - (ਆਕਾਰ (ਛੋਟਾ) + SS_PAD1_ਮਾਪ + _SS_ALIGNSIZE))

  ਬਣਤਰ sockaddr_storage {
    ਛੋਟਾ ss_family;
    ਅੱਖਰ __ss_pad1[SS_PAD1_ਮਾਪ];

    __MINGW_EXTENSION __int64 __ss_align;
    ਅੱਖਰ __ss_pad2[SS_PAD2_ਮਾਪ];

  };

  ਬਣਤਰ sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_UNSPEC AF_UNSPEC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_UNIX AF_UNIX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_INET AF_INET
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_IMPLINK AF_IMPLINK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_PUP AF_PUP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_CHAOS AF_CHAOS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_NS AF_NS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_IPX AF_IPX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_ISO AF_ISO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_OSI AF_OSI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_ECMA AF_ECMA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_DATAKIT AF_DATAKIT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_CCITT AF_CCITT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_SNA AF_SNA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_DECnet AF_DECnet
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_DLI AF_DLI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_LAT AF_LAT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_HYLINK AF_HYLINK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_APPLETALK AF_APPLETALK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_VOICEVIEW AF_VOICEVIEW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_FIREFOX AF_FIREFOX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_UNKNOWN1 AF_UNKNOWN1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_BAN AF_BAN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_ATM AF_ATM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_INET6 AF_INET6

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PF_MAX AF_MAX

  ਬਣਤਰ linger {
    u_short l_onoff;
    u_short l_linger;
  };

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOL_SOCKET 0xffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOMAXCONN 0x7fffffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_OOB 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_PEEK 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_DONTROUTE 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_WAITALL 0x8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_PARTIAL 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_ਰੁਕਾਵਟ 0x10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_MAXIOVLEN 16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXGETHOSTSTRUCT 1024

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_READ_ਦੋਆਧਾਰੀ_ਅੰਕ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_READ (1 << FD_READ_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_WRITE_ਦੋਆਧਾਰੀ_ਅੰਕ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_WRITE (1 << FD_WRITE_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_OOB_ਦੋਆਧਾਰੀ_ਅੰਕ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_OOB (1 << FD_OOB_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ACCEPT_ਦੋਆਧਾਰੀ_ਅੰਕ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ACCEPT (1 << FD_ACCEPT_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_CONNECT_ਦੋਆਧਾਰੀ_ਅੰਕ 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_CONNECT (1 << FD_CONNECT_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_CLOSE_ਦੋਆਧਾਰੀ_ਅੰਕ 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_CLOSE (1 << FD_CLOSE_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_QOS_ਦੋਆਧਾਰੀ_ਅੰਕ 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_QOS (1 << FD_QOS_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ਸਮੂਹ_QOS_ਦੋਆਧਾਰੀ_ਅੰਕ 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ਸਮੂਹ_QOS (1 << FD_ਸਮੂਹ_QOS_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ROUTING_INTERFACE_CHANGE_ਦੋਆਧਾਰੀ_ਅੰਕ 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ਪਤਾ_LIST_CHANGE_ਦੋਆਧਾਰੀ_ਅੰਕ 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ਪਤਾ_LIST_CHANGE (1 << FD_ਪਤਾ_LIST_CHANGE_ਦੋਆਧਾਰੀ_ਅੰਕ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_MAX_EVENTS 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSABASEERR

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSABASEERR 10000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEINTR (WSABASEERR+4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEBADF (WSABASEERR+9)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEACCES (WSABASEERR+13)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEFAULT (WSABASEERR+14)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEINVAL (WSABASEERR+22)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEMFILE (WSABASEERR+24)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEWOULDBLOCK (WSABASEERR+35)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEINPROGRESS (WSABASEERR+36)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEALREADY (WSABASEERR+37)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENOTSOCK (WSABASEERR+38)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEDESTADDRREQ (WSABASEERR+39)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEMSGSIZE (WSABASEERR+40)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEPROTOTYPE (WSABASEERR+41)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENOPROTOOPT (WSABASEERR+42)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEPROTONOSUPPORT (WSABASEERR+43)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAESOCKTNOSUPPORT (WSABASEERR+44)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEOPNOTSUPP (WSABASEERR+45)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEPFNOSUPPORT (WSABASEERR+46)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEAFNOSUPPORT (WSABASEERR+47)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEADDRINUSE (WSABASEERR+48)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEADDRNOTAVAIL (WSABASEERR+49)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENETDOWN (WSABASEERR+50)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENETUNREACH (WSABASEERR+51)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENETRESET (WSABASEERR+52)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAECONNABORTED (WSABASEERR+53)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAECONNRESET (WSABASEERR+54)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENOBUFS (WSABASEERR+55)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEISCONN (WSABASEERR+56)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENOTCONN (WSABASEERR+57)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAESHUTDOWN (WSABASEERR+58)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAETOOMANYREFS (WSABASEERR+59)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAETIMEDOUT (WSABASEERR+60)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAECONNREFUSED (WSABASEERR+61)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAELOOP (WSABASEERR+62)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENAMETOOLONG (WSABASEERR+63)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEHOSTDOWN (WSABASEERR+64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEHOSTUNREACH (WSABASEERR+65)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENOTEMPTY (WSABASEERR+66)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEPROCLIM (WSABASEERR+67)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEUSERS (WSABASEERR+68)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEDQUOT (WSABASEERR+69)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAESTALE (WSABASEERR+70)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEREMOTE (WSABASEERR+71)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSASYSNOTREADY (WSABASEERR+91)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAVERNOTSUPPORTED (WSABASEERR+92)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSANOTINITIALISED (WSABASEERR+93)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEDISCON (WSABASEERR+101)
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSAHOST_NOT_ਮਿਲਿਆ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAHOST_NOT_ਮਿਲਿਆ (WSABASEERR+1001)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSATRY_AGAIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSATRY_AGAIN (WSABASEERR+1002)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSANO_RECOVERY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSANO_RECOVERY (WSABASEERR+1003)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSANO_ਅੰਕੜੇ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSANO_ਅੰਕੜੇ (WSABASEERR+1004)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAENOMORE (WSABASEERR+102)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAECANCELLED (WSABASEERR+103)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEINVALIDPROCTABLE (WSABASEERR+104)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEINVALIDPROVIDER (WSABASEERR+105)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSASYSCALLFAILURE (WSABASEERR+107)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSASERVICE_NOT_ਮਿਲਿਆ (WSABASEERR+108)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSATYPE_NOT_ਮਿਲਿਆ (WSABASEERR+109)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_E_NO_ਹੋਰ (WSABASEERR+110)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_E_CANCELLED (WSABASEERR+111)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEREFUSED (WSABASEERR+112)
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_RECEIVERS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_SENDERS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_SENDERS (WSABASEERR + 1006)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_NO_SENDERS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EFILTERSTYLE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EFILTERTYPE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EFILTERCOUNT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EOBJLENGTH
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EFLOWCOUNT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EUNKNOWNPSOBJ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EPOLICYOBJ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EFLOWDESC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EPSFLOWSPEC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_EPSFILTERSPEC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_ESDMODEOBJ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_ESHAPERATEOBJ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WSA_QOS_RESERVED_PETYPE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ // WSABASEERR

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ h_errno WSAGet_ਆਖਰੀ_Error()
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HOST_NOT_ਮਿਲਿਆ WSAHOST_NOT_ਮਿਲਿਆ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRY_AGAIN WSATRY_AGAIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_RECOVERY WSANO_RECOVERY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_ਅੰਕੜੇ WSANO_ਅੰਕੜੇ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSANO_ਪਤਾ WSANO_ਅੰਕੜੇ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NO_ਪਤਾ WSANO_ਪਤਾ

#ਜੇ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EWOULDBLOCK WSAEWOULDBLOCK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EINPROGRESS WSAEINPROGRESS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EALREADY WSAEALREADY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOTSOCK WSAENOTSOCK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EDESTADDRREQ WSAEDESTADDRREQ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMSGSIZE WSAEMSGSIZE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EPROTOTYPE WSAEPROTOTYPE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOPROTOOPT WSAENOPROTOOPT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EPROTONOSUPPORT WSAEPROTONOSUPPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EOPNOTSUPP WSAEOPNOTSUPP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EPFNOSUPPORT WSAEPFNOSUPPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EAFNOSUPPORT WSAEAFNOSUPPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EADDRINUSE WSAEADDRINUSE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EADDRNOTAVAIL WSAEADDRNOTAVAIL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENETDOWN WSAENETDOWN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENETUNREACH WSAENETUNREACH
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENETRESET WSAENETRESET
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ECONNABORTED WSAECONNABORTED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ECONNRESET WSAECONNRESET
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOBUFS WSAENOBUFS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EISCONN WSAEISCONN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOTCONN WSAENOTCONN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESHUTDOWN WSAESHUTDOWN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETOOMANYREFS WSAETOOMANYREFS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETIMEDOUT WSAETIMEDOUT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ECONNREFUSED WSAECONNREFUSED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELOOP WSAELOOP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENAMETOOLONG WSAENAMETOOLONG
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EHOSTDOWN WSAEHOSTDOWN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EHOSTUNREACH WSAEHOSTUNREACH
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENOTEMPTY WSAENOTEMPTY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EPROCLIM WSAEPROCLIM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EUSERS WSAEUSERS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EDQUOT WSAEDQUOT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESTALE WSAESTALE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EREMOTE WSAEREMOTE
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAAPI WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEVENT HANDLE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPWSAEVENT LPHANDLE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAOVERLAPPED OVERLAPPED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OVERLAPPED *LPWSAOVERLAPPED;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_IO_PENDING (ERROR_IO_PENDING)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_NOT_ENOUGH_ਸਮ੍ਰਿਤੀ (ERROR_NOT_ENOUGH_ਸਮ੍ਰਿਤੀ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_INVALID_EVENT ((WSAEVENT)ਨਿਰਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_ਵੱਧ_ਤੋਂ_ਵੱਧ_WAIT_EVENTS (ਵੱਧ_ਤੋਂ_ਵੱਧ_WAIT_OBJECTS)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_WAIT_FAILED (WAIT_FAILED)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_INFINITE (INFINITE)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSABUF {
    u_long len;
    ਅੱਖਰ *buf;
  } WSABUF,*LPWSABUF;

#ਅਨ੍ਤਰ੍ਭਾਵ <qos.h>

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ Quality_ਦਾ_Service {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_ACCEPT 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_REJECT 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_DEFER 0x0002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SD_RECEIVE 0x00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SD_SEND 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SD_BOTH 0x02

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ ਸਮੂਹ_3;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SG_UNCONSTRAINED_ਸਮੂਹ 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SG_CONSTRAINED_ਸਮੂਹ 0x02

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSANETWORKEVENTS {
    ਲੰਮਾ l_ਜਾਲ_Events;
    ਪੂਰਨ i_Error_ਕੋਡ[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ GUID_DEFINED
#ਅਨ੍ਤਰ੍ਭਾਵ <guiddef.h>
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_PROTOCOL_CHAIN 7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਅਧਾਰ_PROTOCOL 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LAYERED_PROTOCOL 0

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSAPROTOCOLCHAIN {
    ਪੂਰਨ ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAPROTOCOL_LEN 255

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_ਇੰਦਰਾਜ_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    ਪੂਰਨ i_ਸੰਸਕਰਣ;
    ਪੂਰਨ i_ਪਤਾ_Family;
    ਪੂਰਨ iMaxSockAddr;
    ਪੂਰਨ iMinSockAddr;
    ਪੂਰਨ iSocketType;
    ਪੂਰਨ iProtocol;
    ਪੂਰਨ i_Protocol_Max_ਵਿੱਥ;
    ਪੂਰਨ i_ਜਾਲ_Byte_ਕ੍ਰਮ;
    ਪੂਰਨ iSecurityScheme;
    DWORD dw_ਸੁਨੇਹਾ_ਮਾਪ;
    DWORD dwProviderReserved;
    CHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOA,*LPWSAPROTOCOL_INFOA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSAPROTOCOL_INFOW {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_ਇੰਦਰਾਜ_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    ਪੂਰਨ i_ਸੰਸਕਰਣ;
    ਪੂਰਨ i_ਪਤਾ_Family;
    ਪੂਰਨ iMaxSockAddr;
    ਪੂਰਨ iMinSockAddr;
    ਪੂਰਨ iSocketType;
    ਪੂਰਨ iProtocol;
    ਪੂਰਨ i_Protocol_Max_ਵਿੱਥ;
    ਪੂਰਨ i_ਜਾਲ_Byte_ਕ੍ਰਮ;
    ਪੂਰਨ iSecurityScheme;
    DWORD dw_ਸੁਨੇਹਾ_ਮਾਪ;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFL_ਗੁਣਜ_PROTO_ENTRIES 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFL_RECOMMENDED_PROTO_ਇੰਦਰਾਜ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFL_HIDDEN 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_CONNECTIONLESS 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_GUARANTEED_DELIVERY 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_GUARANTEED_ਕ੍ਰਮ 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_ਸੁਨੇਹਾ_ORIENTED 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_PSEUDO_ਧਾਰਾ 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_GRACEFUL_CLOSE 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_EXPEDITED_ਅੰਕੜੇ 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_CONNECT_ਅੰਕੜੇ 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_DISCONNECT_ਅੰਕੜੇ 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_SUPPORT_ਪ੍ਰਸਾਰਣ 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_SUPPORT_MULTIPOINT 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_MULTIPOINT_ਅੰਕੜੇ_PLANE 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_QOS_SUPPORTED 0x00002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_ਰੁਕਾਵਟ 0x00004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_UNI_SEND 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_UNI_RECV 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_IFS_HANDLES 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XP1_PARTIAL_ਸੁਨੇਹਾ 0x00040000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BIGENDIAN 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LITTLEENDIAN 0x0001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_PROTOCOL_NONE 0x0000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ JL_SENDER_ONLY 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ JL_RECEIVER_ONLY 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ JL_BOTH 0x04

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_FLAG_OVERLAPPED 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_FLAG_MULTIPOINT_C_ਜੜ੍ਹ 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_FLAG_MULTIPOINT_C_ਪੱਤੀ 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_FLAG_MULTIPOINT_D_ਜੜ੍ਹ 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSA_FLAG_MULTIPOINT_D_ਪੱਤੀ 0x10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IOC_UNIX 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IOC_WS2 0x08000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IOC_PROTOCOL 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IOC_VENDOR 0x18000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSAIO(x,y) (IOC_VOID|(x)|(y))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSAIOR(x,y) (IOC_ਬਾਹਰਲਾ|(x)|(y))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSAIOW(x,y) (IOC_ਵਿੱਚ|(x)|(y))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ਲੱਭੋ_ROUTE _WSAIOR(IOC_WS2,3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_FLUSH _WSAIO(IOC_WS2,4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_GET_ਪ੍ਰਸਾਰਣ_ਪਤਾ _WSAIOR(IOC_WS2,5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_GET_EXTENSION_FUNCTION_ਸੂਚਕ _WSAIORW(IOC_WS2,6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_GET_ਸਮੂਹ_QOS _WSAIORW(IOC_WS2,8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ਸੈੱਟ_QOS _WSAIOW(IOC_WS2,11)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ਸੈੱਟ_ਸਮੂਹ_QOS _WSAIOW(IOC_WS2,12)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ਪਤਾ_LIST_QUERY _WSAIOR(IOC_WS2,22)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ਪਤਾ_LIST_CHANGE _WSAIO(IOC_WS2,23)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_QUERY_ਨਿਸ਼ਾਨਾ_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_ਪਤਾ_LIST_ਛਾਂਟੋ _WSAIORW(IOC_WS2,25)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_ਅੰਕੜੇ,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_ਅੰਕੜੇ,ਸਮੂਹ_3 *g,DWORD_PTR dw_Callback_ਅੰਕੜੇ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_ਪੋਰਟ,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    ਸੰਘ {
      ਬਣਤਰ {
	HWND hWnd;
	UINT u_ਸੁਨੇਹਾ;
	WPARAM context;
      } ਖਿੜਕੀ_ਸੁਨੇਹਾ;
      ਬਣਤਰ {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      ਬਣਤਰ {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      ਬਣਤਰ {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE h_ਪੋਰਟ;
	ULONG_PTR ਕੁੰਜੀ_3;
      } ਪੋਰਟ;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TH_NETDEV 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TH_TAPI 0x00000002

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr SOCKADDR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr *PSOCKADDR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr *LPSOCKADDR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr_storage SOCKADDR_STORAGE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr_storage *PSOCKADDR_STORAGE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr_storage *LPSOCKADDR_STORAGE;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ਟੈਗ_BLOB_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਟੈਗ_BLOB_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _BLOB_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _LPBLOB_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _BLOB {
    ULONG cb_ਮਾਪ;
    BYTE *p_Blob_ਅੰਕੜੇ;
  } BLOB,*LPBLOB;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_ਗੁਣਜ (0x00000001)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_ALL (0)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_SAP (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_NDS (2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_PEER_BROWSE (3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_SLP (5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_DHCP (6)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_TCPIP_LOCAL (10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_TCPIP_HOSTS (11)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_DNS (12)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_NETBT (13)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_WINS (14)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_NLA (15)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_NBP (20)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_MS (30)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_STDA (31)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_NTDS (32)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_X500 (40)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_NIS (41)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_NISPLUS (42)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_WRQ (50)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NS_NETDES (60)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RES_ਅਣਵਰਤਿਆ_1 (0x00000001)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RES_FLUSH_CACHE (0x00000002)
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RES_SERVICE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RES_SERVICE (0x00000004)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_IPXPORTA "IpxSocket"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_IPXPORTW L"IpxSocket"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_SAPIDA "SapId"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_SAPIDW L"SapId"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_TCPPORTA "TcpPort"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_TCPPORTW L"TcpPort"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_UDPPORTA "UdpPort"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_UDPPORTW L"UdpPort"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_OBJECTIDA "ObjectId"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_OBJECTIDW L"ObjectId"

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_SAPID SERVICE_TYPE_ਮੁੱਲ_SAPIDW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_TCPPORT SERVICE_TYPE_ਮੁੱਲ_TCPPORTW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_UDPPORT SERVICE_TYPE_ਮੁੱਲ_UDPPORTW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_OBJECTID SERVICE_TYPE_ਮੁੱਲ_OBJECTIDW
#ਨਹੀਂਤਾਂ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_SAPID SERVICE_TYPE_ਮੁੱਲ_SAPIDA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_TCPPORT SERVICE_TYPE_ਮੁੱਲ_TCPPORTA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_UDPPORT SERVICE_TYPE_ਮੁੱਲ_UDPPORTA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_TYPE_ਮੁੱਲ_OBJECTID SERVICE_TYPE_ਮੁੱਲ_OBJECTIDA
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __CSADDR_DEFINED__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __CSADDR_DEFINED__

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SOCKET_ਪਤਾ {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_ਲੰਮਾਈ;
  } SOCKET_ਪਤਾ_2,*PSOCKET_ਪਤਾ,*LPSOCKET_ਪਤਾ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CSADDR_INFO {
    SOCKET_ਪਤਾ_2 LocalAddr;
    SOCKET_ਪਤਾ_2 RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SOCKET_ਪਤਾ_LIST {
    INT i_ਪਤਾ_ਗਿਣਤੀ;
    SOCKET_ਪਤਾ_2 ਪਤਾ_2[1];
  } SOCKET_ਪਤਾ_LIST_2,*LPSOCKET_ਪਤਾ_LIST;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _AFPROTOCOLS {
    INT i_ਪਤਾ_Family;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSAVersion {
    DWORD dw_ਸੰਸਕਰਣ;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ WSAQuery_ਸੈੱਟ_A {
    DWORD dw_ਮਾਪ;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_ਸੰਸਕਰਣ;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_ਸੰਖਿਆ_ਦਾ_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_ਸੰਖਿਆ_ਦਾ_Cs_Addrs;
    LPCSADDR_INFO lpcsa_ਬਫਰ;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ WSAQuery_ਸੈੱਟ_W {
    DWORD dw_ਮਾਪ;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_ਸੰਸਕਰਣ;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_ਸੰਖਿਆ_ਦਾ_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_ਸੰਖਿਆ_ਦਾ_Cs_Addrs;
    LPCSADDR_INFO lpcsa_ਬਫਰ;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSAQUERYSETW WSAQUERYSET;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWSAQUERYSETW PWSAQUERYSET;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSAQUERYSETW LPWSAQUERYSET;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSAQUERYSETA WSAQUERYSET;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWSAQUERYSETA PWSAQUERYSET;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSAQUERYSETA LPWSAQUERYSET;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_DEEP 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_CONTAINERS 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_NOCONTAINERS 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_ਸਭ_ਤੋਂ_ਨੇੜੇ 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RETURN_NAME 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RETURN_TYPE 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RETURN_ਸੰਸਕਰਣ 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RETURN_COMMENT 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RETURN_ADDR 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RETURN_BLOB 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RETURN_ALIASES 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RETURN_QUERY_STRING 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RETURN_ALL 0x0FF0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_RES_SERVICE 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_FLUSHCACHE 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LUP_FLUSHPREVIOUS 0x2000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਤੀਜਾ_IS_ALIAS 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਤੀਜਾ_IS_ADDED 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਤੀਜਾ_IS_ਬਦਲਿਆ 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਤੀਜਾ_IS_DELETED 0x0040

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _WSAESETSERVICEOP {
    RNRSERVICE_ਰਜਿਸਟਰ=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_ਮੁੱਲ_Type;
    DWORD dw_ਮੁੱਲ_ਮਾਪ;
    LPVOID lp_ਮੁੱਲ;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_ਮੁੱਲ_Type;
    DWORD dw_ਮੁੱਲ_ਮਾਪ;
    LPVOID lp_ਮੁੱਲ;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSANSCLASSINFOW WSANSCLASSINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWSANSCLASSINFOW PWSANSCLASSINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSANSCLASSINFOA WSANSCLASSINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWSANSCLASSINFOA PWSANSCLASSINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_ਗਿਣਤੀ;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_ਗਿਣਤੀ;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_ਸਰਗਰਮ;
    DWORD dw_ਸੰਸਕਰਣ;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_ਸਰਗਰਮ;
    DWORD dw_ਸੰਸਕਰਣ;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#ਜੇ_ਅੰਤ

#ਜੇ INCL_WINSOCK_API_TYPEDEFS
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSASOCKET LPFN_WSASOCKETW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSASOCKET LPFN_WSASOCKETA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,ਬਣਤਰ sockaddr *addr,ਪੂਰਨ *addrlen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_BIND)(SOCKET s,ਅਚਲ ਬਣਤਰ sockaddr *name,ਪੂਰਨ namelen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_CONNECT)(SOCKET s,ਅਚਲ ਬਣਤਰ sockaddr *name,ਪੂਰਨ namelen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,ਲੰਮਾ cmd,u_long *argp);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,ਬਣਤਰ sockaddr *name,ਪੂਰਨ *namelen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,ਬਣਤਰ sockaddr *name,ਪੂਰਨ *namelen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,ਪੂਰਨ level,ਪੂਰਨ optname,ਅੱਖਰ *optval,ਪੂਰਨ *optlen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ (WSAAPI *LPFN_INET_ADDR)(ਅਚਲ ਅੱਖਰ *cp);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅੱਖਰ *(WSAAPI *LPFN_INET_NTOA)(ਬਣਤਰ ਵਿੱਚ_addr ਵਿੱਚ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_LISTEN)(SOCKET s,ਪੂਰਨ backlog);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ u_long (WSAAPI *LPFN_NTOHL)(u_long netlong);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ u_short (WSAAPI *LPFN_NTOHS)(u_short netshort);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_RECV)(SOCKET s,ਅੱਖਰ *buf,ਪੂਰਨ len,ਪੂਰਨ flags);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_RECVFROM)(SOCKET s,ਅੱਖਰ *buf,ਪੂਰਨ len,ਪੂਰਨ flags,ਬਣਤਰ sockaddr *from,ਪੂਰਨ *fromlen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_SELECT)(ਪੂਰਨ nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ਅਚਲ ਬਣਤਰ timeval *timeout);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_SEND)(SOCKET s,ਅਚਲ ਅੱਖਰ *buf,ਪੂਰਨ len,ਪੂਰਨ flags);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_SENDTO)(SOCKET s,ਅਚਲ ਅੱਖਰ *buf,ਪੂਰਨ len,ਪੂਰਨ flags,ਅਚਲ ਬਣਤਰ sockaddr *ਮੰਜ਼ਿਲ,ਪੂਰਨ tolen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s,ਪੂਰਨ level,ਪੂਰਨ optname,ਅਚਲ ਅੱਖਰ *optval,ਪੂਰਨ optlen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_SHUTDOWN)(SOCKET s,ਪੂਰਨ how);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SOCKET (WSAAPI *LPFN_SOCKET)(ਪੂਰਨ af,ਪੂਰਨ type,ਪੂਰਨ protocol);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ hostent *(WSAAPI *LPFN_GETHOSTBYADDR)(ਅਚਲ ਅੱਖਰ *addr,ਪੂਰਨ len,ਪੂਰਨ type);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ hostent *(WSAAPI *LPFN_GETHOSTBYNAME)(ਅਚਲ ਅੱਖਰ *name);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_GETHOSTNAME)(ਅੱਖਰ *name,ਪੂਰਨ namelen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ servent *(WSAAPI *LPFN_GETSERVBYPORT)(ਪੂਰਨ ਪੋਰਟ_2,ਅਚਲ ਅੱਖਰ *proto);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ servent *(WSAAPI *LPFN_GETSERVBYNAME)(ਅਚਲ ਅੱਖਰ *name,ਅਚਲ ਅੱਖਰ *proto);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(ਪੂਰਨ ਸੰਖਿਆ_3);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(ਅਚਲ ਅੱਖਰ *name);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSASTARTUP)(ਸ਼ਬਦ_3 w_ਸੰਸਕਰਣ_Requested,LPWSADATA lpWSAData);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSACLEANUP)(ਖਾਲੀ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਖਾਲੀ (WSAAPI *LPFN_WSASETLASTERROR)(ਪੂਰਨ iError);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAGETLASTERROR)(ਖਾਲੀ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(ਖਾਲੀ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(ਖਾਲੀ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lp_ਖੰਡ_Func);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(ਖਾਲੀ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਅਚਲ ਅੱਖਰ *name,ਅਚਲ ਅੱਖਰ *proto,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਪੂਰਨ ਪੋਰਟ_2,ਅਚਲ ਅੱਖਰ *proto,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਅਚਲ ਅੱਖਰ *name,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਪੂਰਨ ਸੰਖਿਆ_3,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਅਚਲ ਅੱਖਰ *name,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਅਚਲ ਅੱਖਰ *addr,ਪੂਰਨ len,ਪੂਰਨ type,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਲੰਮਾ lEvent);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,ਬਣਤਰ sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_ਅੰਕੜੇ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSACONNECT)(SOCKET s,ਅਚਲ ਬਣਤਰ sockaddr *name,ਪੂਰਨ namelen,LPWSABUF lp_Caller_ਅੰਕੜੇ,LPWSABUF lp_Callee_ਅੰਕੜੇ,LPQOS lpSQOS,LPQOS lpGQOS);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(ਖਾਲੀ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_ਜਾਲ_Events);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_ਬਫਰ,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_ਬਫਰ,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,ਲੰਮਾ l_ਜਾਲ_Events);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dw_Io_Control_ਕੋਡ,LPVOID lpv_ਵਿੱਚ_ਬਫਰ,DWORD cb_ਵਿੱਚ_ਬਫਰ,LPVOID lpv_ਬਾਹਰਲਾ_ਬਫਰ,DWORD cb_ਬਾਹਰਲਾ_ਬਫਰ,LPDWORD lpcb_ਬਾਈਟਾਂ_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,ਅਚਲ ਬਣਤਰ sockaddr *name,ਪੂਰਨ namelen,LPWSABUF lp_Caller_ਅੰਕੜੇ,LPWSABUF lp_Callee_ਅੰਕੜੇ,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ਬਫਰ_ਗਿਣਤੀ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_ਅੰਕੜੇ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ਬਫਰ_ਗਿਣਤੀ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Recvd,LPDWORD lpFlags,ਬਣਤਰ sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ਬਫਰ_ਗਿਣਤੀ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਭੇਜਿਆ,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_ਅੰਕੜੇ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ਬਫਰ_ਗਿਣਤੀ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਭੇਜਿਆ,DWORD dwFlags,ਅਚਲ ਬਣਤਰ sockaddr *lp_ਮੰਜ਼ਿਲ,ਪੂਰਨ iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SOCKET (WSAAPI *LPFN_WSASOCKETA)(ਪੂਰਨ af,ਪੂਰਨ type,ਪੂਰਨ protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,ਸਮੂਹ_3 g,DWORD dwFlags);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SOCKET (WSAAPI *LPFN_WSASOCKETW)(ਪੂਰਨ af,ਪੂਰਨ type,ਪੂਰਨ protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,ਸਮੂਹ_3 g,DWORD dwFlags);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,ਅਚਲ WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsa_ਪਤਾ,DWORD dw_ਪਤਾ_ਲੰਮਾਈ,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_ਪਤਾ_String,LPDWORD lpdw_ਪਤਾ_String_ਲੰਮਾਈ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsa_ਪਤਾ,DWORD dw_ਪਤਾ_ਲੰਮਾਈ,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_ਪਤਾ_String,LPDWORD lpdw_ਪਤਾ_String_ਲੰਮਾਈ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR ਪਤਾ_String,INT ਪਤਾ_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_ਪਤਾ,LPINT lp_ਪਤਾ_ਲੰਮਾਈ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR ਪਤਾ_String,INT ਪਤਾ_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_ਪਤਾ,LPINT lp_ਪਤਾ_ਲੰਮਾਈ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ,LPWSAQUERYSETA lpqsResults);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ,LPWSAQUERYSETW lpqsResults);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dw_Control_ਕੋਡ,LPVOID lpv_ਵਿੱਚ_ਬਫਰ,DWORD cb_ਵਿੱਚ_ਬਫਰ,LPVOID lpv_ਬਾਹਰਲਾ_ਬਫਰ,DWORD cb_ਬਾਹਰਲਾ_ਬਫਰ,LPDWORD lpcb_ਬਾਈਟਾਂ_Returned,LPWSACOMPLETION lpCompletion);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ਮਾਪ,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ਮਾਪ,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ,LPWSANAMESPACE_INFOA lpnsp_ਬਫਰ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ,LPWSANAMESPACE_INFOW lpnsp_ਬਫਰ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSADuplicateSocket WSADuplicateSocketW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEnumProtocols WSAEnumProtocolsW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAAddress_ਮੰਜ਼ਿਲ_String WSAAddress_ਮੰਜ਼ਿਲ_String_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSASocket WSASocketW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAString_ਮੰਜ਼ਿਲ_ਪਤਾ WSAString_ਮੰਜ਼ਿਲ_ਪਤਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSALookupServiceBegin WSALookupServiceBeginW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSALookup_Service_ਅਗਲਾ WSALookup_Service_ਅਗਲਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAInstallServiceClass WSAInstallServiceClassW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAGetServiceClassInfo WSAGetServiceClassInfoW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSASetService WSASetServiceW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSADuplicateSocket WSADuplicateSocketA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEnumProtocols WSAEnumProtocolsA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSASocket WSASocketA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAAddress_ਮੰਜ਼ਿਲ_String WSAAddress_ਮੰਜ਼ਿਲ_String_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAString_ਮੰਜ਼ਿਲ_ਪਤਾ WSAString_ਮੰਜ਼ਿਲ_ਪਤਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSALookupServiceBegin WSALookupServiceBeginA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSALookup_Service_ਅਗਲਾ WSALookup_Service_ਅਗਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAInstallServiceClass WSAInstallServiceClassA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAGetServiceClassInfo WSAGetServiceClassInfoA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSASetService WSASetServiceA
#ਜੇ_ਅੰਤ

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,ਬਣਤਰ sockaddr *addr,ਪੂਰਨ *addrlen);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI bind(SOCKET s,ਅਚਲ ਬਣਤਰ sockaddr *name,ਪੂਰਨ namelen);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI connect(SOCKET s,ਅਚਲ ਬਣਤਰ sockaddr *name,ਪੂਰਨ namelen);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI ioctlsocket(SOCKET s,ਲੰਮਾ cmd,u_long *argp);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI getpeername(SOCKET s,ਬਣਤਰ sockaddr *name,ਪੂਰਨ *namelen);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI getsockname(SOCKET s,ਬਣਤਰ sockaddr *name,ਪੂਰਨ *namelen);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI getsockopt(SOCKET s,ਪੂਰਨ level,ਪੂਰਨ optname,ਅੱਖਰ *optval,ਪੂਰਨ *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ WSAAPI inet_addr(ਅਚਲ ਅੱਖਰ *cp);
  WINSOCK_API_LINKAGE ਅੱਖਰ *WSAAPI inet_ntoa(ਬਣਤਰ ਵਿੱਚ_addr ਵਿੱਚ);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI listen(SOCKET s,ਪੂਰਨ backlog);
  WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI recv(SOCKET s,ਅੱਖਰ *buf,ਪੂਰਨ len,ਪੂਰਨ flags);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI recvfrom(SOCKET s,ਅੱਖਰ *buf,ਪੂਰਨ len,ਪੂਰਨ flags,ਬਣਤਰ sockaddr *from,ਪੂਰਨ *fromlen);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI select(ਪੂਰਨ nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ਅਚਲ ਬਣਤਰ timeval *timeout);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI send(SOCKET s,ਅਚਲ ਅੱਖਰ *buf,ਪੂਰਨ len,ਪੂਰਨ flags);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI sendto(SOCKET s,ਅਚਲ ਅੱਖਰ *buf,ਪੂਰਨ len,ਪੂਰਨ flags,ਅਚਲ ਬਣਤਰ sockaddr *ਮੰਜ਼ਿਲ,ਪੂਰਨ tolen);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI setsockopt(SOCKET s,ਪੂਰਨ level,ਪੂਰਨ optname,ਅਚਲ ਅੱਖਰ *optval,ਪੂਰਨ optlen);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI shutdown(SOCKET s,ਪੂਰਨ how);
  WINSOCK_API_LINKAGE SOCKET WSAAPI socket(ਪੂਰਨ af,ਪੂਰਨ type,ਪੂਰਨ protocol);
  WINSOCK_API_LINKAGE ਬਣਤਰ hostent *WSAAPI gethostbyaddr(ਅਚਲ ਅੱਖਰ *addr,ਪੂਰਨ len,ਪੂਰਨ type);
  WINSOCK_API_LINKAGE ਬਣਤਰ hostent *WSAAPI gethostbyname(ਅਚਲ ਅੱਖਰ *name);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI gethostname(ਅੱਖਰ *name,ਪੂਰਨ namelen);
  WINSOCK_API_LINKAGE ਬਣਤਰ servent *WSAAPI getservbyport(ਪੂਰਨ ਪੋਰਟ_2,ਅਚਲ ਅੱਖਰ *proto);
  WINSOCK_API_LINKAGE ਬਣਤਰ servent *WSAAPI getservbyname(ਅਚਲ ਅੱਖਰ *name,ਅਚਲ ਅੱਖਰ *proto);
  WINSOCK_API_LINKAGE ਬਣਤਰ protoent *WSAAPI getprotobynumber(ਪੂਰਨ ਸੰਖਿਆ_3);
  WINSOCK_API_LINKAGE ਬਣਤਰ protoent *WSAAPI getprotobyname(ਅਚਲ ਅੱਖਰ *name);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAStartup(ਸ਼ਬਦ_3 w_ਸੰਸਕਰਣ_Requested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSACleanup(ਖਾਲੀ);
  WINSOCK_API_LINKAGE ਖਾਲੀ WSAAPI WSASet_ਆਖਰੀ_Error(ਪੂਰਨ iError);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAGet_ਆਖਰੀ_Error(ਖਾਲੀ);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(ਖਾਲੀ);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAUnhookBlockingHook(ਖਾਲੀ);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lp_ਖੰਡ_Func);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSACancelBlockingCall(ਖਾਲੀ);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਅਚਲ ਅੱਖਰ *name,ਅਚਲ ਅੱਖਰ *proto,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Serv_By_ਪੋਰਟ(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਪੂਰਨ ਪੋਰਟ_2,ਅਚਲ ਅੱਖਰ *proto,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਅਚਲ ਅੱਖਰ *name,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_ਸੰਖਿਆ(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਪੂਰਨ ਸੰਖਿਆ_3,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਅਚਲ ਅੱਖਰ *name,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਅਚਲ ਅੱਖਰ *addr,ਪੂਰਨ len,ਪੂਰਨ type,ਅੱਖਰ *buf,ਪੂਰਨ buflen);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_ਸੁਨੇਹਾ,ਲੰਮਾ lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,ਬਣਤਰ sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_ਅੰਕੜੇ);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAConnect(SOCKET s,ਅਚਲ ਬਣਤਰ sockaddr *name,ਪੂਰਨ namelen,LPWSABUF lp_Caller_ਅੰਕੜੇ,LPWSABUF lp_Callee_ਅੰਕੜੇ,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(ਖਾਲੀ);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAEnum_ਜਾਲ_Events(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_ਜਾਲ_Events);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_ਬਫਰ,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_ਬਫਰ,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,ਲੰਮਾ l_ਜਾਲ_Events);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_ਨਤੀਜਾ(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAIoctl(SOCKET s,DWORD dw_Io_Control_ਕੋਡ,LPVOID lpv_ਵਿੱਚ_ਬਫਰ,DWORD cb_ਵਿੱਚ_ਬਫਰ,LPVOID lpv_ਬਾਹਰਲਾ_ਬਫਰ,DWORD cb_ਬਾਹਰਲਾ_ਬਫਰ,LPDWORD lpcb_ਬਾਈਟਾਂ_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoin_ਪੱਤੀ(SOCKET s,ਅਚਲ ਬਣਤਰ sockaddr *name,ਪੂਰਨ namelen,LPWSABUF lp_Caller_ਅੰਕੜੇ,LPWSABUF lp_Callee_ਅੰਕੜੇ,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ਬਫਰ_ਗਿਣਤੀ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_ਅੰਕੜੇ);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ਬਫਰ_ਗਿਣਤੀ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Recvd,LPDWORD lpFlags,ਬਣਤਰ sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ਬਫਰ_ਗਿਣਤੀ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਭੇਜਿਆ,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_ਅੰਕੜੇ);
  WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSASend_ਮੰਜ਼ਿਲ(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ਬਫਰ_ਗਿਣਤੀ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਭੇਜਿਆ,DWORD dwFlags,ਅਚਲ ਬਣਤਰ sockaddr *lp_ਮੰਜ਼ਿਲ,ਪੂਰਨ iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(ਪੂਰਨ af,ਪੂਰਨ type,ਪੂਰਨ protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,ਸਮੂਹ_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(ਪੂਰਨ af,ਪੂਰਨ type,ਪੂਰਨ protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,ਸਮੂਹ_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWait_For_ਗੁਣਜ_Events(DWORD cEvents,ਅਚਲ WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_ਮੰਜ਼ਿਲ_String_A(LPSOCKADDR lpsa_ਪਤਾ,DWORD dw_ਪਤਾ_ਲੰਮਾਈ,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_ਪਤਾ_String,LPDWORD lpdw_ਪਤਾ_String_ਲੰਮਾਈ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_ਮੰਜ਼ਿਲ_String_W(LPSOCKADDR lpsa_ਪਤਾ,DWORD dw_ਪਤਾ_ਲੰਮਾਈ,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_ਪਤਾ_String,LPDWORD lpdw_ਪਤਾ_String_ਲੰਮਾਈ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_ਮੰਜ਼ਿਲ_ਪਤਾ_A(LPSTR ਪਤਾ_String,INT ਪਤਾ_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_ਪਤਾ,LPINT lp_ਪਤਾ_ਲੰਮਾਈ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_ਮੰਜ਼ਿਲ_ਪਤਾ_W(LPWSTR ਪਤਾ_String,INT ਪਤਾ_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_ਪਤਾ,LPINT lp_ਪਤਾ_ਲੰਮਾਈ);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_ਅਗਲਾ_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_ਅਗਲਾ_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dw_Control_ਕੋਡ,LPVOID lpv_ਵਿੱਚ_ਬਫਰ,DWORD cb_ਵਿੱਚ_ਬਫਰ,LPVOID lpv_ਬਾਹਰਲਾ_ਬਫਰ,DWORD cb_ਬਾਹਰਲਾ_ਬਫਰ,LPDWORD lpcb_ਬਾਈਟਾਂ_Returned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_ਸਿਰਾ(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ਮਾਪ,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ਮਾਪ,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ,LPWSANAMESPACE_INFOA lpnsp_ਬਫਰ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ,LPWSANAMESPACE_INFOW lpnsp_ਬਫਰ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr_ਵਿੱਚ SOCKADDR_ਵਿੱਚ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr_ਵਿੱਚ *PSOCKADDR_ਵਿੱਚ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ sockaddr_ਵਿੱਚ *LPSOCKADDR_ਵਿੱਚ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ linger LINGER;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ linger *PLINGER;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ linger *LPLINGER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਵਿੱਚ_addr ਵਿੱਚ_ADDR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਵਿੱਚ_addr *PIN_ADDR;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਵਿੱਚ_addr *LPIN_ADDR;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ fd_set FD_SET;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ fd_set *PFD_ਸੈੱਟ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ fd_set *LPFD_ਸੈੱਟ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ hostent HOSTENT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ hostent *PHOSTENT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ hostent *LPHOSTENT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ servent SERVENT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ servent *PSERVENT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ servent *LPSERVENT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ protoent PROTOENT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ protoent *PPROTOENT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ protoent *LPPROTOENT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ timeval TIMEVAL;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ timeval *PTIMEVAL;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ timeval *LPTIMEVAL;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAGETASYNCERROR(lParam) HIWORD(lParam)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLRDNORM  0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLRDBAND  0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLIN      (POLLRDNORM | POLLRDBAND)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLPRI     0x0400

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLWRNORM  0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLOUT     (POLLWRNORM)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLWRBAND  0x0020

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLERR     0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLHUP     0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLLNVAL    0x0004

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE ਪੂਰਨ WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _NEED_POPPACK
#ਅਨ੍ਤਰ੍ਭਾਵ <poppack.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ IPV6STRICT
#ਅਨ੍ਤਰ੍ਭਾਵ <wsipv6ok.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINSOCKAPI_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINSOCKAPI_
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _INC_WINSOCK_H
#ਅਨ੍ਤਰ੍ਭਾਵ <mswsock.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਅੰਤ
