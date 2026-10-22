/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINSOCK2API_
#ವ್ಯಾಖ್ಯಾನಿಸು _WINSOCK2API_

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ INCL_WINSOCK_API_TYPEDEFS
#ವ್ಯಾಖ್ಯಾನಿಸು INCL_WINSOCK_API_TYPEDEFS 0
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_WINDOWS
#ಅನ್ತರ್ಭಾವ <windows.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ MAKEWORD
#ವ್ಯಾಖ್ಯಾನಿಸು MAKEWORD(ಕೆಳಗಿನ,ಮೇಲಿನ) ((ಶಬ್ದ_3)(((BYTE)(ಕೆಳಗಿನ)) | ((ಶಬ್ದ_3)((BYTE)(ಮೇಲಿನ))) << 8))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WINSOCK_ಆವೃತ್ತಿ
#ವ್ಯಾಖ್ಯಾನಿಸು WINSOCK_ಆವೃತ್ತಿ MAKEWORD(2,2)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WINSOCK_API_LINKAGE
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DECLSPEC_IMPORT
#ವ್ಯಾಖ್ಯಾನಿಸು WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು WINSOCK_API_LINKAGE
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINSOCK_SOCKET_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WINSOCK_SOCKET_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ u_char;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ u_short;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ u_int;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ u_long;
  __MINGW_EXTENSION ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ __int64 u_int64;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT_PTR SOCKET;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ FD_SETSIZE
#ವ್ಯಾಖ್ಯಾನಿಸು FD_SETSIZE 64
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ fd_set {
    u_int fd_ಎಣಿಕೆ;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#ವ್ಯಾಖ್ಯಾನಿಸು FD_CLR(fd,ಗಣ) ಮಾಡು { u_int __i; ಗಾಗಿ(__i = 0;__i < ((fd_set *)(ಗಣ))->fd_ಎಣಿಕೆ;__i++) { ಆದರೆ (((fd_set *)(ಗಣ))->fd_array[__i]==fd) { ಆಗ (__i < ((fd_set *)(ಗಣ))->fd_ಎಣಿಕೆ-1) { ((fd_set *)(ಗಣ))->fd_array[__i] = ((fd_set *)(ಗಣ))->fd_array[__i+1]; __i++; } ((fd_set *)(ಗಣ))->fd_ಎಣಿಕೆ--; ನಿಲ್ಲಿಸು; } } } ಆಗ(0)
#ವ್ಯಾಖ್ಯಾನಿಸು FD_SET(fd,ಗಣ) ಮಾಡು { u_int __i; ಗಾಗಿ(__i = 0;__i < ((fd_set *)(ಗಣ))->fd_ಎಣಿಕೆ;__i++) { ಆದರೆ (((fd_set *)(ಗಣ))->fd_array[__i]==(fd)) { ನಿಲ್ಲಿಸು; } } ಆದರೆ (__i==((fd_set *)(ಗಣ))->fd_ಎಣಿಕೆ) { ಆದರೆ (((fd_set *)(ಗಣ))->fd_ಎಣಿಕೆ < FD_SETSIZE) { ((fd_set *)(ಗಣ))->fd_array[__i] = (fd); ((fd_set *)(ಗಣ))->fd_ಎಣಿಕೆ++; } } } ಆಗ(0)
#ವ್ಯಾಖ್ಯಾನಿಸು FD_ZERO(ಗಣ) (((fd_set *)(ಗಣ))->fd_ಎಣಿಕೆ=0)
#ವ್ಯಾಖ್ಯಾನಿಸು FD_ISSET(fd,ಗಣ) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(ಗಣ))

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TIMEVAL_DEFINED /* also in winsock[2].h */
#ವ್ಯಾಖ್ಯಾನಿಸು _TIMEVAL_DEFINED
  ರಚನೆ timeval {
    ದೀರ್ಘ tv_sec;
    ದೀರ್ಘ tv_usec;
  };

#ವ್ಯಾಖ್ಯಾನಿಸು timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#ವ್ಯಾಖ್ಯಾನಿಸು timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#ವ್ಯಾಖ್ಯಾನಿಸು timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#ಆದರೆ_ಅಂತ್ಯ /* _TIMEVAL_DEFINED */

#ವ್ಯಾಖ್ಯಾನಿಸು IOCPARM_ಮುಖವಾಡ 0x7f
#ವ್ಯಾಖ್ಯಾನಿಸು IOC_VOID 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು IOC_ಹೊರಹೋಗು 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು IOC_ಒಳ 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು IOC_INOUT (IOC_ಒಳ|IOC_ಹೊರಹೋಗು)

#ವ್ಯಾಖ್ಯಾನಿಸು _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#ವ್ಯಾಖ್ಯಾನಿಸು _IOR(x,y,t) (IOC_ಹೊರಹೋಗು|(((ದೀರ್ಘ)ಗಾತ್ರ(t)&IOCPARM_ಮುಖವಾಡ)<<16)|((x)<<8)|(y))
#ವ್ಯಾಖ್ಯಾನಿಸು _IOW(x,y,t) (IOC_ಒಳ|(((ದೀರ್ಘ)ಗಾತ್ರ(t)&IOCPARM_ಮುಖವಾಡ)<<16)|((x)<<8)|(y))

#ವ್ಯಾಖ್ಯಾನಿಸು FIONREAD _IOR('f',127,u_long)
#ವ್ಯಾಖ್ಯಾನಿಸು FIONBIO _IOW('f',126,u_long)
#ವ್ಯಾಖ್ಯಾನಿಸು FIOASYNC _IOW('f',125,u_long)

#ವ್ಯಾಖ್ಯಾನಿಸು SIOCSHIWAT _IOW('s',0,u_long)
#ವ್ಯಾಖ್ಯಾನಿಸು SIOCGHIWAT _IOR('s',1,u_long)
#ವ್ಯಾಖ್ಯಾನಿಸು SIOCSLOWAT _IOW('s',2,u_long)
#ವ್ಯಾಖ್ಯಾನಿಸು SIOCGLOWAT _IOR('s',3,u_long)
#ವ್ಯಾಖ್ಯಾನಿಸು SIOCATMARK _IOR('s',7,u_long)

#ವ್ಯಾಖ್ಯಾನಿಸು h_addr h_addr_list[0]

  ರಚನೆ hostent {
    ಅಕ್ಷರ *h_name;
    ಅಕ್ಷರ **h_aliases;
    ಗಿಡ್ಡ h_addrtype;
    ಗಿಡ್ಡ h_ಉದ್ದಳತೆ;
    ಅಕ್ಷರ **h_addr_list;
  };

  ರಚನೆ netent {
    ಅಕ್ಷರ *n_name;
    ಅಕ್ಷರ **n_aliases;
    ಗಿಡ್ಡ n_addrtype;
    u_long n_net;
  };

  ರಚನೆ servent {
    ಅಕ್ಷರ *s_name;
    ಅಕ್ಷರ **s_aliases;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    ಅಕ್ಷರ *s_proto;
    ಗಿಡ್ಡ s_ಪೋರ್ಟ್;
#ಇಲ್ಲದಿದ್ದರೆ
    ಗಿಡ್ಡ s_ಪೋರ್ಟ್;
    ಅಕ್ಷರ *s_proto;
#ಆದರೆ_ಅಂತ್ಯ
  };

  ರಚನೆ protoent {
    ಅಕ್ಷರ *p_name;
    ಅಕ್ಷರ **p_aliases;
    ಗಿಡ್ಡ p_proto;
  };

#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_IP 0
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_HOPOPTS 0
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_ICMP 1
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_IGMP 2
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_GGP 3
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_IPV4 4
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_TCP 6
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_PUP 12
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_UDP 17
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_IDP 22
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_IPV6 41
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_ROUTING 43
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_FRAGMENT 44
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_ESP 50
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_AH 51
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_ICMPV6 58
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_NONE 59
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_DSTOPTS 60
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_ND 77
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_ICLFXBM 78

#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_RAW 255
#ವ್ಯಾಖ್ಯಾನಿಸು IPPROTO_MAX 256

#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_ECHO 7
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_DISCARD 9
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_SYSTAT 11
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_DAYTIME 13
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_NETSTAT 15
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_FTP 21
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_TELNET 23
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_SMTP 25
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_TIMESERVER 37
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_NAMESERVER 42
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_WHOIS 43
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_MTP 57

#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_TFTP 69
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_RJE 77
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_FINGER 79
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_TTYLINK 87
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_SUPDUP 95

#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_EXECSERVER 512
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_LOGINSERVER 513
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_CMDSERVER 514
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_EFSSERVER 520

#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_BIFFUDP 512
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_WHOSERVER 513
#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_ROUTESERVER 520

#ವ್ಯಾಖ್ಯಾನಿಸು IPPORT_RESERVED 1024

#ವ್ಯಾಖ್ಯಾನಿಸು IMPLINK_IP 155
#ವ್ಯಾಖ್ಯಾನಿಸು IMPLINK_LOWEXPER 156
#ವ್ಯಾಖ್ಯಾನಿಸು IMPLINK_HIGHEXPER 158

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ s_addr

  ರಚನೆ ಒಳ_addr {
    ಒಕ್ಕೂಟ {
      ರಚನೆ { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      ರಚನೆ { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#ವ್ಯಾಖ್ಯಾನಿಸು s_addr S_un.S_addr
#ವ್ಯಾಖ್ಯಾನಿಸು s_host S_un.S_un_b.s_b2
#ವ್ಯಾಖ್ಯಾನಿಸು s_net S_un.S_un_b.s_b1
#ವ್ಯಾಖ್ಯಾನಿಸು s_imp S_un.S_un_w.s_w2
#ವ್ಯಾಖ್ಯಾನಿಸು s_impno S_un.S_un_b.s_b4
#ವ್ಯಾಖ್ಯಾನಿಸು s_lh S_un.S_un_b.s_b3

#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSA(i) (((ದೀರ್ಘ)(i) & 0x80000000)==0)
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSA_NET 0xff000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSA_NSHIFT 24
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSA_HOST 0x00ffffff
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSA_MAX 128

#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSB(i) (((ದೀರ್ಘ)(i) & 0xc0000000)==0x80000000)
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSB_NET 0xffff0000
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSB_NSHIFT 16
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSB_HOST 0x0000ffff
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSB_MAX 65536

#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSC(i) (((ದೀರ್ಘ)(i) & 0xe0000000)==0xc0000000)
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSC_NET 0xffffff00
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSC_NSHIFT 8
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSC_HOST 0x000000ff

#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSD(i) (((ದೀರ್ಘ)(i) & 0xf0000000)==0xe0000000)
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSD_NET 0xf0000000
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSD_NSHIFT 28
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_CLASSD_HOST 0x0fffffff
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳ_MULTICAST(i) ಒಳ_CLASSD(i)

#ವ್ಯಾಖ್ಯಾನಿಸು INADDR_ANY (u_long)0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು INADDR_LOOPBACK 0x7f000001
#ವ್ಯಾಖ್ಯಾನಿಸು INADDR_ಪ್ರಸಾರ (u_long)0xffffffff
#ವ್ಯಾಖ್ಯಾನಿಸು INADDR_NONE 0xffffffff

#ವ್ಯಾಖ್ಯಾನಿಸು ADDR_ANY INADDR_ANY

  ರಚನೆ sockaddr_ಒಳ {
    ಗಿಡ್ಡ sin_family;
    u_short sin_ಪೋರ್ಟ್;
    ರಚನೆ ಒಳ_addr sin_addr;
    ಅಕ್ಷರ sin_zero[8];
  };

#ವ್ಯಾಖ್ಯಾನಿಸು WSADESCRIPTION_LEN 256
#ವ್ಯಾಖ್ಯಾನಿಸು WSASYS_ಸ್ಥಿತಿ_LEN 128

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ WSAData {
    ಶಬ್ದ_3 w_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3 w_ಮೇಲಿನ_ಆವೃತ್ತಿ;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ iMaxSockets;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ iMaxUdpDg;
    ಅಕ್ಷರ *lpVendorInfo;
    ಅಕ್ಷರ szDescription[WSADESCRIPTION_LEN+1];
    ಅಕ್ಷರ sz_System_ಸ್ಥಿತಿ[WSASYS_ಸ್ಥಿತಿ_LEN+1];
#ಇಲ್ಲದಿದ್ದರೆ
    ಅಕ್ಷರ szDescription[WSADESCRIPTION_LEN+1];
    ಅಕ್ಷರ sz_System_ಸ್ಥಿತಿ[WSASYS_ಸ್ಥಿತಿ_LEN+1];
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ iMaxSockets;
    ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ iMaxUdpDg;
    ಅಕ್ಷರ *lpVendorInfo;
#ಆದರೆ_ಅಂತ್ಯ
  } WSADATA,*LPWSADATA;

#ವ್ಯಾಖ್ಯಾನಿಸು INVALID_SOCKET (SOCKET)(~0)
#ವ್ಯಾಖ್ಯಾನಿಸು SOCKET_ERROR (-1)

#ವ್ಯಾಖ್ಯಾನಿಸು FROM_PROTOCOL_INFO (-1)

#ವ್ಯಾಖ್ಯಾನಿಸು SOCK_ಹರಿವು 1
#ವ್ಯಾಖ್ಯಾನಿಸು SOCK_DGRAM 2
#ವ್ಯಾಖ್ಯಾನಿಸು SOCK_RAW 3
#ವ್ಯಾಖ್ಯಾನಿಸು SOCK_RDM 4
#ವ್ಯಾಖ್ಯಾನಿಸು SOCK_SEQPACKET 5

#ವ್ಯಾಖ್ಯಾನಿಸು SO_DEBUG 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು SO_ACCEPTCONN 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು SO_REUSEADDR 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು SO_KEEPALIVE 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು SO_DONTROUTE 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು SO_ಪ್ರಸಾರ 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು SO_USELOOPBACK 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು SO_LINGER 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು SO_OOBINLINE 0x0100

#ವ್ಯಾಖ್ಯಾನಿಸು SO_DONTLINGER (ಪೂರ್ಣಾಂಕ)(~SO_LINGER)
#ವ್ಯಾಖ್ಯಾನಿಸು SO_EXCLUSIVEADDRUSE ((ಪೂರ್ಣಾಂಕ)(~SO_REUSEADDR))

#ವ್ಯಾಖ್ಯಾನಿಸು SO_SNDBUF 0x1001
#ವ್ಯಾಖ್ಯಾನಿಸು SO_RCVBUF 0x1002
#ವ್ಯಾಖ್ಯಾನಿಸು SO_SNDLOWAT 0x1003
#ವ್ಯಾಖ್ಯಾನಿಸು SO_RCVLOWAT 0x1004
#ವ್ಯಾಖ್ಯಾನಿಸು SO_SNDTIMEO 0x1005
#ವ್ಯಾಖ್ಯಾನಿಸು SO_RCVTIMEO 0x1006
#ವ್ಯಾಖ್ಯಾನಿಸು SO_ERROR 0x1007
#ವ್ಯಾಖ್ಯಾನಿಸು SO_TYPE 0x1008

#ವ್ಯಾಖ್ಯಾನಿಸು SO_ಗುಂಪು_ID 0x2001
#ವ್ಯಾಖ್ಯಾನಿಸು SO_ಗುಂಪು_ಆದ್ಯತೆ 0x2002
#ವ್ಯಾಖ್ಯಾನಿಸು SO_MAX_ಸಂದೇಶ_ಗಾತ್ರ 0x2003
#ವ್ಯಾಖ್ಯಾನಿಸು SO_PROTOCOL_INFOA 0x2004
#ವ್ಯಾಖ್ಯಾನಿಸು SO_PROTOCOL_INFOW 0x2005
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು PVD_CONFIG 0x3001
#ವ್ಯಾಖ್ಯಾನಿಸು SO_CONDITIONAL_ACCEPT 0x3002

#ವ್ಯಾಖ್ಯಾನಿಸು TCP_NODELAY 0x0001

#ವ್ಯಾಖ್ಯಾನಿಸು AF_UNSPEC 0

#ವ್ಯಾಖ್ಯಾನಿಸು AF_UNIX 1
#ವ್ಯಾಖ್ಯಾನಿಸು AF_INET 2
#ವ್ಯಾಖ್ಯಾನಿಸು AF_IMPLINK 3
#ವ್ಯಾಖ್ಯಾನಿಸು AF_PUP 4
#ವ್ಯಾಖ್ಯಾನಿಸು AF_CHAOS 5
#ವ್ಯಾಖ್ಯಾನಿಸು AF_NS 6
#ವ್ಯಾಖ್ಯಾನಿಸು AF_IPX AF_NS
#ವ್ಯಾಖ್ಯಾನಿಸು AF_ISO 7
#ವ್ಯಾಖ್ಯಾನಿಸು AF_OSI AF_ISO
#ವ್ಯಾಖ್ಯಾನಿಸು AF_ECMA 8
#ವ್ಯಾಖ್ಯಾನಿಸು AF_DATAKIT 9
#ವ್ಯಾಖ್ಯಾನಿಸು AF_CCITT 10
#ವ್ಯಾಖ್ಯಾನಿಸು AF_SNA 11
#ವ್ಯಾಖ್ಯಾನಿಸು AF_DECnet 12
#ವ್ಯಾಖ್ಯಾನಿಸು AF_DLI 13
#ವ್ಯಾಖ್ಯಾನಿಸು AF_LAT 14
#ವ್ಯಾಖ್ಯಾನಿಸು AF_HYLINK 15
#ವ್ಯಾಖ್ಯಾನಿಸು AF_APPLETALK 16
#ವ್ಯಾಖ್ಯಾನಿಸು AF_NETBIOS 17
#ವ್ಯಾಖ್ಯಾನಿಸು AF_VOICEVIEW 18
#ವ್ಯಾಖ್ಯಾನಿಸು AF_FIREFOX 19
#ವ್ಯಾಖ್ಯಾನಿಸು AF_UNKNOWN1 20
#ವ್ಯಾಖ್ಯಾನಿಸು AF_BAN 21
#ವ್ಯಾಖ್ಯಾನಿಸು AF_ATM 22
#ವ್ಯಾಖ್ಯಾನಿಸು AF_INET6 23
#ವ್ಯಾಖ್ಯಾನಿಸು AF_CLUSTER 24
#ವ್ಯಾಖ್ಯಾನಿಸು AF_12844 25
#ವ್ಯಾಖ್ಯಾನಿಸು AF_IRDA 26
#ವ್ಯಾಖ್ಯಾನಿಸು AF_NETDES 28
#ವ್ಯಾಖ್ಯಾನಿಸು AF_TCNPROCESS 29
#ವ್ಯಾಖ್ಯಾನಿಸು AF_TCNMESSAGE 30
#ವ್ಯಾಖ್ಯಾನಿಸು AF_ICLFXBM 31

#ವ್ಯಾಖ್ಯಾನಿಸು AF_MAX 32

  ರಚನೆ sockaddr {
    u_short sa_family;
    ಅಕ್ಷರ sa_ದತ್ತಾಂಶ[14];
  };

#ವ್ಯಾಖ್ಯಾನಿಸು _SS_MAXSIZE 128
#ವ್ಯಾಖ್ಯಾನಿಸು _SS_ALIGNSIZE (8)

#ವ್ಯಾಖ್ಯಾನಿಸು SS_PAD1_ಗಾತ್ರ (_SS_ALIGNSIZE - ಗಾತ್ರ (ಗಿಡ್ಡ))
#ವ್ಯಾಖ್ಯಾನಿಸು SS_PAD2_ಗಾತ್ರ (_SS_MAXSIZE - (ಗಾತ್ರ (ಗಿಡ್ಡ) + SS_PAD1_ಗಾತ್ರ + _SS_ALIGNSIZE))

  ರಚನೆ sockaddr_storage {
    ಗಿಡ್ಡ ss_family;
    ಅಕ್ಷರ __ss_pad1[SS_PAD1_ಗಾತ್ರ];

    __MINGW_EXTENSION __int64 __ss_align;
    ಅಕ್ಷರ __ss_pad2[SS_PAD2_ಗಾತ್ರ];

  };

  ರಚನೆ sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#ವ್ಯಾಖ್ಯಾನಿಸು PF_UNSPEC AF_UNSPEC
#ವ್ಯಾಖ್ಯಾನಿಸು PF_UNIX AF_UNIX
#ವ್ಯಾಖ್ಯಾನಿಸು PF_INET AF_INET
#ವ್ಯಾಖ್ಯಾನಿಸು PF_IMPLINK AF_IMPLINK
#ವ್ಯಾಖ್ಯಾನಿಸು PF_PUP AF_PUP
#ವ್ಯಾಖ್ಯಾನಿಸು PF_CHAOS AF_CHAOS
#ವ್ಯಾಖ್ಯಾನಿಸು PF_NS AF_NS
#ವ್ಯಾಖ್ಯಾನಿಸು PF_IPX AF_IPX
#ವ್ಯಾಖ್ಯಾನಿಸು PF_ISO AF_ISO
#ವ್ಯಾಖ್ಯಾನಿಸು PF_OSI AF_OSI
#ವ್ಯಾಖ್ಯಾನಿಸು PF_ECMA AF_ECMA
#ವ್ಯಾಖ್ಯಾನಿಸು PF_DATAKIT AF_DATAKIT
#ವ್ಯಾಖ್ಯಾನಿಸು PF_CCITT AF_CCITT
#ವ್ಯಾಖ್ಯಾನಿಸು PF_SNA AF_SNA
#ವ್ಯಾಖ್ಯಾನಿಸು PF_DECnet AF_DECnet
#ವ್ಯಾಖ್ಯಾನಿಸು PF_DLI AF_DLI
#ವ್ಯಾಖ್ಯಾನಿಸು PF_LAT AF_LAT
#ವ್ಯಾಖ್ಯಾನಿಸು PF_HYLINK AF_HYLINK
#ವ್ಯಾಖ್ಯಾನಿಸು PF_APPLETALK AF_APPLETALK
#ವ್ಯಾಖ್ಯಾನಿಸು PF_VOICEVIEW AF_VOICEVIEW
#ವ್ಯಾಖ್ಯಾನಿಸು PF_FIREFOX AF_FIREFOX
#ವ್ಯಾಖ್ಯಾನಿಸು PF_UNKNOWN1 AF_UNKNOWN1
#ವ್ಯಾಖ್ಯಾನಿಸು PF_BAN AF_BAN
#ವ್ಯಾಖ್ಯಾನಿಸು PF_ATM AF_ATM
#ವ್ಯಾಖ್ಯಾನಿಸು PF_INET6 AF_INET6

#ವ್ಯಾಖ್ಯಾನಿಸು PF_MAX AF_MAX

  ರಚನೆ linger {
    u_short l_onoff;
    u_short l_linger;
  };

#ವ್ಯಾಖ್ಯಾನಿಸು SOL_SOCKET 0xffff

#ವ್ಯಾಖ್ಯಾನಿಸು SOMAXCONN 0x7fffffff

#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_OOB 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_PEEK 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_DONTROUTE 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_WAITALL 0x8

#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_PARTIAL 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_ಅಡಚಣೆ 0x10

#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_MAXIOVLEN 16

#ವ್ಯಾಖ್ಯಾನಿಸು MAXGETHOSTSTRUCT 1024

#ವ್ಯಾಖ್ಯಾನಿಸು FD_READ_ಬಿಟ್ 0
#ವ್ಯಾಖ್ಯಾನಿಸು FD_READ (1 << FD_READ_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_WRITE_ಬಿಟ್ 1
#ವ್ಯಾಖ್ಯಾನಿಸು FD_WRITE (1 << FD_WRITE_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_OOB_ಬಿಟ್ 2
#ವ್ಯಾಖ್ಯಾನಿಸು FD_OOB (1 << FD_OOB_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_ACCEPT_ಬಿಟ್ 3
#ವ್ಯಾಖ್ಯಾನಿಸು FD_ACCEPT (1 << FD_ACCEPT_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_CONNECT_ಬಿಟ್ 4
#ವ್ಯಾಖ್ಯಾನಿಸು FD_CONNECT (1 << FD_CONNECT_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_CLOSE_ಬಿಟ್ 5
#ವ್ಯಾಖ್ಯಾನಿಸು FD_CLOSE (1 << FD_CLOSE_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_QOS_ಬಿಟ್ 6
#ವ್ಯಾಖ್ಯಾನಿಸು FD_QOS (1 << FD_QOS_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_ಗುಂಪು_QOS_ಬಿಟ್ 7
#ವ್ಯಾಖ್ಯಾನಿಸು FD_ಗುಂಪು_QOS (1 << FD_ಗುಂಪು_QOS_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_ROUTING_INTERFACE_CHANGE_ಬಿಟ್ 8
#ವ್ಯಾಖ್ಯಾನಿಸು FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_ವಿಳಾಸ_LIST_CHANGE_ಬಿಟ್ 9
#ವ್ಯಾಖ್ಯಾನಿಸು FD_ವಿಳಾಸ_LIST_CHANGE (1 << FD_ವಿಳಾಸ_LIST_CHANGE_ಬಿಟ್)

#ವ್ಯಾಖ್ಯಾನಿಸು FD_MAX_EVENTS 10
#ವ್ಯಾಖ್ಯಾನಿಸು FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSABASEERR

#ವ್ಯಾಖ್ಯಾನಿಸು WSABASEERR 10000

#ವ್ಯಾಖ್ಯಾನಿಸು WSAEINTR (WSABASEERR+4)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEBADF (WSABASEERR+9)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEACCES (WSABASEERR+13)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEFAULT (WSABASEERR+14)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEINVAL (WSABASEERR+22)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEMFILE (WSABASEERR+24)

#ವ್ಯಾಖ್ಯಾನಿಸು WSAEWOULDBLOCK (WSABASEERR+35)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEINPROGRESS (WSABASEERR+36)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEALREADY (WSABASEERR+37)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAENOTSOCK (WSABASEERR+38)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEDESTADDRREQ (WSABASEERR+39)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEMSGSIZE (WSABASEERR+40)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEPROTOTYPE (WSABASEERR+41)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAENOPROTOOPT (WSABASEERR+42)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEPROTONOSUPPORT (WSABASEERR+43)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAESOCKTNOSUPPORT (WSABASEERR+44)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEOPNOTSUPP (WSABASEERR+45)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEPFNOSUPPORT (WSABASEERR+46)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEAFNOSUPPORT (WSABASEERR+47)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEADDRINUSE (WSABASEERR+48)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEADDRNOTAVAIL (WSABASEERR+49)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAENETDOWN (WSABASEERR+50)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAENETUNREACH (WSABASEERR+51)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAENETRESET (WSABASEERR+52)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAECONNABORTED (WSABASEERR+53)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAECONNRESET (WSABASEERR+54)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAENOBUFS (WSABASEERR+55)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEISCONN (WSABASEERR+56)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAENOTCONN (WSABASEERR+57)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAESHUTDOWN (WSABASEERR+58)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAETOOMANYREFS (WSABASEERR+59)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAETIMEDOUT (WSABASEERR+60)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAECONNREFUSED (WSABASEERR+61)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAELOOP (WSABASEERR+62)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAENAMETOOLONG (WSABASEERR+63)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEHOSTDOWN (WSABASEERR+64)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEHOSTUNREACH (WSABASEERR+65)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAENOTEMPTY (WSABASEERR+66)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEPROCLIM (WSABASEERR+67)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEUSERS (WSABASEERR+68)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEDQUOT (WSABASEERR+69)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAESTALE (WSABASEERR+70)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEREMOTE (WSABASEERR+71)

#ವ್ಯಾಖ್ಯಾನಿಸು WSASYSNOTREADY (WSABASEERR+91)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAVERNOTSUPPORTED (WSABASEERR+92)
#ವ್ಯಾಖ್ಯಾನಿಸು WSANOTINITIALISED (WSABASEERR+93)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEDISCON (WSABASEERR+101)
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSAHOST_NOT_ಸಿಕ್ಕಿತು
#ವ್ಯಾಖ್ಯಾನಿಸು WSAHOST_NOT_ಸಿಕ್ಕಿತು (WSABASEERR+1001)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSATRY_AGAIN
#ವ್ಯಾಖ್ಯಾನಿಸು WSATRY_AGAIN (WSABASEERR+1002)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSANO_RECOVERY
#ವ್ಯಾಖ್ಯಾನಿಸು WSANO_RECOVERY (WSABASEERR+1003)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSANO_ದತ್ತಾಂಶ
#ವ್ಯಾಖ್ಯಾನಿಸು WSANO_ದತ್ತಾಂಶ (WSABASEERR+1004)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು WSAENOMORE (WSABASEERR+102)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAECANCELLED (WSABASEERR+103)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEINVALIDPROCTABLE (WSABASEERR+104)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEINVALIDPROVIDER (WSABASEERR+105)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#ವ್ಯಾಖ್ಯಾನಿಸು WSASYSCALLFAILURE (WSABASEERR+107)
#ವ್ಯಾಖ್ಯಾನಿಸು WSASERVICE_NOT_ಸಿಕ್ಕಿತು (WSABASEERR+108)
#ವ್ಯಾಖ್ಯಾನಿಸು WSATYPE_NOT_ಸಿಕ್ಕಿತು (WSABASEERR+109)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_E_NO_ಇನ್ನಷ್ಟು (WSABASEERR+110)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_E_CANCELLED (WSABASEERR+111)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEREFUSED (WSABASEERR+112)
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_RECEIVERS
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_SENDERS
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_SENDERS (WSABASEERR + 1006)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_NO_SENDERS
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EFILTERSTYLE
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EFILTERTYPE
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EFILTERCOUNT
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EOBJLENGTH
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EFLOWCOUNT
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EUNKNOWNPSOBJ
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EPOLICYOBJ
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EFLOWDESC
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EPSFLOWSPEC
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_EPSFILTERSPEC
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_ESDMODEOBJ
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_ESHAPERATEOBJ
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WSA_QOS_RESERVED_PETYPE
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ // WSABASEERR

#ವ್ಯಾಖ್ಯಾನಿಸು h_errno WSAGet_ಕೊನೆಯ_Error()
#ವ್ಯಾಖ್ಯಾನಿಸು HOST_NOT_ಸಿಕ್ಕಿತು WSAHOST_NOT_ಸಿಕ್ಕಿತು
#ವ್ಯಾಖ್ಯಾನಿಸು TRY_AGAIN WSATRY_AGAIN
#ವ್ಯಾಖ್ಯಾನಿಸು NO_RECOVERY WSANO_RECOVERY
#ವ್ಯಾಖ್ಯಾನಿಸು NO_ದತ್ತಾಂಶ WSANO_ದತ್ತಾಂಶ

#ವ್ಯಾಖ್ಯಾನಿಸು WSANO_ವಿಳಾಸ WSANO_ದತ್ತಾಂಶ
#ವ್ಯಾಖ್ಯಾನಿಸು NO_ವಿಳಾಸ WSANO_ವಿಳಾಸ

#ಆದರೆ 0
#ವ್ಯಾಖ್ಯಾನಿಸು EWOULDBLOCK WSAEWOULDBLOCK
#ವ್ಯಾಖ್ಯಾನಿಸು EINPROGRESS WSAEINPROGRESS
#ವ್ಯಾಖ್ಯಾನಿಸು EALREADY WSAEALREADY
#ವ್ಯಾಖ್ಯಾನಿಸು ENOTSOCK WSAENOTSOCK
#ವ್ಯಾಖ್ಯಾನಿಸು EDESTADDRREQ WSAEDESTADDRREQ
#ವ್ಯಾಖ್ಯಾನಿಸು EMSGSIZE WSAEMSGSIZE
#ವ್ಯಾಖ್ಯಾನಿಸು EPROTOTYPE WSAEPROTOTYPE
#ವ್ಯಾಖ್ಯಾನಿಸು ENOPROTOOPT WSAENOPROTOOPT
#ವ್ಯಾಖ್ಯಾನಿಸು EPROTONOSUPPORT WSAEPROTONOSUPPORT
#ವ್ಯಾಖ್ಯಾನಿಸು ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#ವ್ಯಾಖ್ಯಾನಿಸು EOPNOTSUPP WSAEOPNOTSUPP
#ವ್ಯಾಖ್ಯಾನಿಸು EPFNOSUPPORT WSAEPFNOSUPPORT
#ವ್ಯಾಖ್ಯಾನಿಸು EAFNOSUPPORT WSAEAFNOSUPPORT
#ವ್ಯಾಖ್ಯಾನಿಸು EADDRINUSE WSAEADDRINUSE
#ವ್ಯಾಖ್ಯಾನಿಸು EADDRNOTAVAIL WSAEADDRNOTAVAIL
#ವ್ಯಾಖ್ಯಾನಿಸು ENETDOWN WSAENETDOWN
#ವ್ಯಾಖ್ಯಾನಿಸು ENETUNREACH WSAENETUNREACH
#ವ್ಯಾಖ್ಯಾನಿಸು ENETRESET WSAENETRESET
#ವ್ಯಾಖ್ಯಾನಿಸು ECONNABORTED WSAECONNABORTED
#ವ್ಯಾಖ್ಯಾನಿಸು ECONNRESET WSAECONNRESET
#ವ್ಯಾಖ್ಯಾನಿಸು ENOBUFS WSAENOBUFS
#ವ್ಯಾಖ್ಯಾನಿಸು EISCONN WSAEISCONN
#ವ್ಯಾಖ್ಯಾನಿಸು ENOTCONN WSAENOTCONN
#ವ್ಯಾಖ್ಯಾನಿಸು ESHUTDOWN WSAESHUTDOWN
#ವ್ಯಾಖ್ಯಾನಿಸು ETOOMANYREFS WSAETOOMANYREFS
#ವ್ಯಾಖ್ಯಾನಿಸು ETIMEDOUT WSAETIMEDOUT
#ವ್ಯಾಖ್ಯಾನಿಸು ECONNREFUSED WSAECONNREFUSED
#ವ್ಯಾಖ್ಯಾನಿಸು ELOOP WSAELOOP
#ವ್ಯಾಖ್ಯಾನಿಸು ENAMETOOLONG WSAENAMETOOLONG
#ವ್ಯಾಖ್ಯಾನಿಸು EHOSTDOWN WSAEHOSTDOWN
#ವ್ಯಾಖ್ಯಾನಿಸು EHOSTUNREACH WSAEHOSTUNREACH
#ವ್ಯಾಖ್ಯಾನಿಸು ENOTEMPTY WSAENOTEMPTY
#ವ್ಯಾಖ್ಯಾನಿಸು EPROCLIM WSAEPROCLIM
#ವ್ಯಾಖ್ಯಾನಿಸು EUSERS WSAEUSERS
#ವ್ಯಾಖ್ಯಾನಿಸು EDQUOT WSAEDQUOT
#ವ್ಯಾಖ್ಯಾನಿಸು ESTALE WSAESTALE
#ವ್ಯಾಖ್ಯಾನಿಸು EREMOTE WSAEREMOTE
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು WSAAPI WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEVENT HANDLE
#ವ್ಯಾಖ್ಯಾನಿಸು LPWSAEVENT LPHANDLE
#ವ್ಯಾಖ್ಯಾನಿಸು WSAOVERLAPPED OVERLAPPED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OVERLAPPED *LPWSAOVERLAPPED;

#ವ್ಯಾಖ್ಯಾನಿಸು WSA_IO_PENDING (ERROR_IO_PENDING)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_NOT_ENOUGH_ಸ್ಮರಣೆ (ERROR_NOT_ENOUGH_ಸ್ಮರಣೆ)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#ವ್ಯಾಖ್ಯಾನಿಸು WSA_INVALID_EVENT ((WSAEVENT)ಖಾಲಿ)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_ಗರಿಷ್ಠ_WAIT_EVENTS (ಗರಿಷ್ಠ_WAIT_OBJECTS)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_WAIT_FAILED (WAIT_FAILED)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_INFINITE (INFINITE)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSABUF {
    u_long len;
    ಅಕ್ಷರ *buf;
  } WSABUF,*LPWSABUF;

#ಅನ್ತರ್ಭಾವ <qos.h>

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ Quality_ದ_Service {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#ವ್ಯಾಖ್ಯಾನಿಸು CF_ACCEPT 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು CF_REJECT 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು CF_DEFER 0x0002

#ವ್ಯಾಖ್ಯಾನಿಸು SD_RECEIVE 0x00
#ವ್ಯಾಖ್ಯಾನಿಸು SD_SEND 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SD_BOTH 0x02

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ ಗುಂಪು_3;

#ವ್ಯಾಖ್ಯಾನಿಸು SG_UNCONSTRAINED_ಗುಂಪು 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು SG_CONSTRAINED_ಗುಂಪು 0x02

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSANETWORKEVENTS {
    ದೀರ್ಘ l_ಜಾಲ_Events;
    ಪೂರ್ಣಾಂಕ i_Error_ಸಂಕೇತ[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ GUID_DEFINED
#ಅನ್ತರ್ಭಾವ <guiddef.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_PROTOCOL_CHAIN 7

#ವ್ಯಾಖ್ಯಾನಿಸು ತಳ_PROTOCOL 1
#ವ್ಯಾಖ್ಯಾನಿಸು LAYERED_PROTOCOL 0

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSAPROTOCOLCHAIN {
    ಪೂರ್ಣಾಂಕ ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#ವ್ಯಾಖ್ಯಾನಿಸು WSAPROTOCOL_LEN 255

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_ನಮೂದು_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    ಪೂರ್ಣಾಂಕ i_ಆವೃತ್ತಿ;
    ಪೂರ್ಣಾಂಕ i_ವಿಳಾಸ_Family;
    ಪೂರ್ಣಾಂಕ iMaxSockAddr;
    ಪೂರ್ಣಾಂಕ iMinSockAddr;
    ಪೂರ್ಣಾಂಕ iSocketType;
    ಪೂರ್ಣಾಂಕ iProtocol;
    ಪೂರ್ಣಾಂಕ i_Protocol_Max_ಸ್ಥಾನಾಂತರ;
    ಪೂರ್ಣಾಂಕ i_ಜಾಲ_Byte_ಕ್ರಮ;
    ಪೂರ್ಣಾಂಕ iSecurityScheme;
    DWORD dw_ಸಂದೇಶ_ಗಾತ್ರ;
    DWORD dwProviderReserved;
    CHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOA,*LPWSAPROTOCOL_INFOA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSAPROTOCOL_INFOW {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_ನಮೂದು_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    ಪೂರ್ಣಾಂಕ i_ಆವೃತ್ತಿ;
    ಪೂರ್ಣಾಂಕ i_ವಿಳಾಸ_Family;
    ಪೂರ್ಣಾಂಕ iMaxSockAddr;
    ಪೂರ್ಣಾಂಕ iMinSockAddr;
    ಪೂರ್ಣಾಂಕ iSocketType;
    ಪೂರ್ಣಾಂಕ iProtocol;
    ಪೂರ್ಣಾಂಕ i_Protocol_Max_ಸ್ಥಾನಾಂತರ;
    ಪೂರ್ಣಾಂಕ i_ಜಾಲ_Byte_ಕ್ರಮ;
    ಪೂರ್ಣಾಂಕ iSecurityScheme;
    DWORD dw_ಸಂದೇಶ_ಗಾತ್ರ;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು PFL_ಅಪವರ್ತ್ಯ_PROTO_ENTRIES 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು PFL_RECOMMENDED_PROTO_ನಮೂದು 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು PFL_HIDDEN 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#ವ್ಯಾಖ್ಯಾನಿಸು XP1_CONNECTIONLESS 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_GUARANTEED_DELIVERY 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_GUARANTEED_ಕ್ರಮ 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_ಸಂದೇಶ_ORIENTED 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_PSEUDO_ಹರಿವು 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_GRACEFUL_CLOSE 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_EXPEDITED_ದತ್ತಾಂಶ 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_CONNECT_ದತ್ತಾಂಶ 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_DISCONNECT_ದತ್ತಾಂಶ 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_SUPPORT_ಪ್ರಸಾರ 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_SUPPORT_MULTIPOINT 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_MULTIPOINT_ದತ್ತಾಂಶ_PLANE 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_QOS_SUPPORTED 0x00002000
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_ಅಡಚಣೆ 0x00004000
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_UNI_SEND 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_UNI_RECV 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_IFS_HANDLES 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು XP1_PARTIAL_ಸಂದೇಶ 0x00040000

#ವ್ಯಾಖ್ಯಾನಿಸು BIGENDIAN 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು LITTLEENDIAN 0x0001

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_PROTOCOL_NONE 0x0000

#ವ್ಯಾಖ್ಯಾನಿಸು JL_SENDER_ONLY 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು JL_RECEIVER_ONLY 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು JL_BOTH 0x04

#ವ್ಯಾಖ್ಯಾನಿಸು WSA_FLAG_OVERLAPPED 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_FLAG_MULTIPOINT_C_ಬೇರು 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_FLAG_MULTIPOINT_C_ಎಲೆ 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_FLAG_MULTIPOINT_D_ಬೇರು 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು WSA_FLAG_MULTIPOINT_D_ಎಲೆ 0x10

#ವ್ಯಾಖ್ಯಾನಿಸು IOC_UNIX 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು IOC_WS2 0x08000000
#ವ್ಯಾಖ್ಯಾನಿಸು IOC_PROTOCOL 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು IOC_VENDOR 0x18000000

#ವ್ಯಾಖ್ಯಾನಿಸು _WSAIO(x,y) (IOC_VOID|(x)|(y))
#ವ್ಯಾಖ್ಯಾನಿಸು _WSAIOR(x,y) (IOC_ಹೊರಹೋಗು|(x)|(y))
#ವ್ಯಾಖ್ಯಾನಿಸು _WSAIOW(x,y) (IOC_ಒಳ|(x)|(y))
#ವ್ಯಾಖ್ಯಾನಿಸು _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ಕಂಡುಹಿಡಿ_ROUTE _WSAIOR(IOC_WS2,3)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_FLUSH _WSAIO(IOC_WS2,4)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_GET_ಪ್ರಸಾರ_ವಿಳಾಸ _WSAIOR(IOC_WS2,5)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_GET_EXTENSION_FUNCTION_ಸೂಚಕ _WSAIORW(IOC_WS2,6)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_GET_ಗುಂಪು_QOS _WSAIORW(IOC_WS2,8)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ಗಣ_QOS _WSAIOW(IOC_WS2,11)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ಗಣ_ಗುಂಪು_QOS _WSAIOW(IOC_WS2,12)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ವಿಳಾಸ_LIST_QUERY _WSAIOR(IOC_WS2,22)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ವಿಳಾಸ_LIST_CHANGE _WSAIO(IOC_WS2,23)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_QUERY_ಗುರಿ_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#ವ್ಯಾಖ್ಯಾನಿಸು SIO_ವಿಳಾಸ_LIST_ವಿಂಗಡಿಸು _WSAIORW(IOC_WS2,25)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_ದತ್ತಾಂಶ,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_ದತ್ತಾಂಶ,ಗುಂಪು_3 *g,DWORD_PTR dw_Callback_ದತ್ತಾಂಶ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_ಪೋರ್ಟ್,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    ಒಕ್ಕೂಟ {
      ರಚನೆ {
	HWND hWnd;
	UINT u_ಸಂದೇಶ;
	WPARAM context;
      } ಕಿಟಕಿ_ಸಂದೇಶ;
      ರಚನೆ {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      ರಚನೆ {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      ರಚನೆ {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE h_ಪೋರ್ಟ್;
	ULONG_PTR ಕೀಲಿ_3;
      } ಪೋರ್ಟ್;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#ವ್ಯಾಖ್ಯಾನಿಸು TH_NETDEV 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು TH_TAPI 0x00000002

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr SOCKADDR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr *PSOCKADDR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr *LPSOCKADDR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr_storage SOCKADDR_STORAGE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr_storage *PSOCKADDR_STORAGE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr_storage *LPSOCKADDR_STORAGE;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ಟ್ಯಾಗ್_BLOB_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು ಟ್ಯಾಗ್_BLOB_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _BLOB_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _LPBLOB_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _BLOB {
    ULONG cb_ಗಾತ್ರ;
    BYTE *p_Blob_ದತ್ತಾಂಶ;
  } BLOB,*LPBLOB;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_ಅಪವರ್ತ್ಯ (0x00000001)

#ವ್ಯಾಖ್ಯಾನಿಸು NS_ALL (0)

#ವ್ಯಾಖ್ಯಾನಿಸು NS_SAP (1)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_NDS (2)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_PEER_BROWSE (3)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_SLP (5)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_DHCP (6)

#ವ್ಯಾಖ್ಯಾನಿಸು NS_TCPIP_LOCAL (10)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_TCPIP_HOSTS (11)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_DNS (12)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_NETBT (13)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_WINS (14)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_NLA (15)

#ವ್ಯಾಖ್ಯಾನಿಸು NS_NBP (20)

#ವ್ಯಾಖ್ಯಾನಿಸು NS_MS (30)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_STDA (31)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_NTDS (32)

#ವ್ಯಾಖ್ಯಾನಿಸು NS_X500 (40)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_NIS (41)
#ವ್ಯಾಖ್ಯಾನಿಸು NS_NISPLUS (42)

#ವ್ಯಾಖ್ಯಾನಿಸು NS_WRQ (50)

#ವ್ಯಾಖ್ಯಾನಿಸು NS_NETDES (60)

#ವ್ಯಾಖ್ಯಾನಿಸು RES_ಬಳಸದ_1 (0x00000001)
#ವ್ಯಾಖ್ಯಾನಿಸು RES_FLUSH_CACHE (0x00000002)
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RES_SERVICE
#ವ್ಯಾಖ್ಯಾನಿಸು RES_SERVICE (0x00000004)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_IPXPORTA "IpxSocket"
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_IPXPORTW L"IpxSocket"
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_SAPIDA "SapId"
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_SAPIDW L"SapId"

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_TCPPORTA "TcpPort"
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_TCPPORTW L"TcpPort"

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_UDPPORTA "UdpPort"
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_UDPPORTW L"UdpPort"

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_OBJECTIDA "ObjectId"
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_OBJECTIDW L"ObjectId"

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_SAPID SERVICE_TYPE_ಮೌಲ್ಯ_SAPIDW
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_TCPPORT SERVICE_TYPE_ಮೌಲ್ಯ_TCPPORTW
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_UDPPORT SERVICE_TYPE_ಮೌಲ್ಯ_UDPPORTW
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_OBJECTID SERVICE_TYPE_ಮೌಲ್ಯ_OBJECTIDW
#ಇಲ್ಲದಿದ್ದರೆ

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_SAPID SERVICE_TYPE_ಮೌಲ್ಯ_SAPIDA
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_TCPPORT SERVICE_TYPE_ಮೌಲ್ಯ_TCPPORTA
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_UDPPORT SERVICE_TYPE_ಮೌಲ್ಯ_UDPPORTA
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_TYPE_ಮೌಲ್ಯ_OBJECTID SERVICE_TYPE_ಮೌಲ್ಯ_OBJECTIDA
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __CSADDR_DEFINED__
#ವ್ಯಾಖ್ಯಾನಿಸು __CSADDR_DEFINED__

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SOCKET_ವಿಳಾಸ {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_ಉದ್ದಳತೆ;
  } SOCKET_ವಿಳಾಸ_2,*PSOCKET_ವಿಳಾಸ,*LPSOCKET_ವಿಳಾಸ;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CSADDR_INFO {
    SOCKET_ವಿಳಾಸ_2 LocalAddr;
    SOCKET_ವಿಳಾಸ_2 RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SOCKET_ವಿಳಾಸ_LIST {
    INT i_ವಿಳಾಸ_ಎಣಿಕೆ;
    SOCKET_ವಿಳಾಸ_2 ವಿಳಾಸ_2[1];
  } SOCKET_ವಿಳಾಸ_LIST_2,*LPSOCKET_ವಿಳಾಸ_LIST;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _AFPROTOCOLS {
    INT i_ವಿಳಾಸ_Family;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSAVersion {
    DWORD dw_ಆವೃತ್ತಿ;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ WSAQuery_ಗಣ_A {
    DWORD dw_ಗಾತ್ರ;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_ಆವೃತ್ತಿ;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_ಸಂಖ್ಯೆ_ದ_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_ಸಂಖ್ಯೆ_ದ_Cs_Addrs;
    LPCSADDR_INFO lpcsa_ಬಫರ್;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ WSAQuery_ಗಣ_W {
    DWORD dw_ಗಾತ್ರ;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_ಆವೃತ್ತಿ;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_ಸಂಖ್ಯೆ_ದ_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_ಸಂಖ್ಯೆ_ದ_Cs_Addrs;
    LPCSADDR_INFO lpcsa_ಬಫರ್;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSAQUERYSETW WSAQUERYSET;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWSAQUERYSETW PWSAQUERYSET;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSAQUERYSETW LPWSAQUERYSET;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSAQUERYSETA WSAQUERYSET;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWSAQUERYSETA PWSAQUERYSET;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSAQUERYSETA LPWSAQUERYSET;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು LUP_DEEP 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_CONTAINERS 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_NOCONTAINERS 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_ಹತ್ತಿರದ 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RETURN_NAME 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RETURN_TYPE 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RETURN_ಆವೃತ್ತಿ 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RETURN_COMMENT 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RETURN_ADDR 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RETURN_BLOB 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RETURN_ALIASES 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RETURN_QUERY_STRING 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RETURN_ALL 0x0FF0
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_RES_SERVICE 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು LUP_FLUSHCACHE 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು LUP_FLUSHPREVIOUS 0x2000

#ವ್ಯಾಖ್ಯಾನಿಸು ಫಲಿತಾಂಶ_IS_ALIAS 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು ಫಲಿತಾಂಶ_IS_ADDED 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು ಫಲಿತಾಂಶ_IS_ಬದಲಾಯಿತು 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು ಫಲಿತಾಂಶ_IS_DELETED 0x0040

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _WSAESETSERVICEOP {
    RNRSERVICE_ರಿಜಿಸ್ಟರ್=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_ಮೌಲ್ಯ_Type;
    DWORD dw_ಮೌಲ್ಯ_ಗಾತ್ರ;
    LPVOID lp_ಮೌಲ್ಯ;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_ಮೌಲ್ಯ_Type;
    DWORD dw_ಮೌಲ್ಯ_ಗಾತ್ರ;
    LPVOID lp_ಮೌಲ್ಯ;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSANSCLASSINFOW WSANSCLASSINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWSANSCLASSINFOW PWSANSCLASSINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSANSCLASSINFOA WSANSCLASSINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWSANSCLASSINFOA PWSANSCLASSINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_ಎಣಿಕೆ;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_ಎಣಿಕೆ;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_ಸಕ್ರಿಯ;
    DWORD dw_ಆವೃತ್ತಿ;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_ಸಕ್ರಿಯ;
    DWORD dw_ಆವೃತ್ತಿ;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ INCL_WINSOCK_API_TYPEDEFS
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSASOCKET LPFN_WSASOCKETW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSASOCKET LPFN_WSASOCKETA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#ವ್ಯಾಖ್ಯಾನಿಸು LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,ರಚನೆ sockaddr *addr,ಪೂರ್ಣಾಂಕ *addrlen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_BIND)(SOCKET s,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ namelen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_CONNECT)(SOCKET s,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ namelen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,ದೀರ್ಘ cmd,u_long *argp);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ *namelen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ *namelen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,ಪೂರ್ಣಾಂಕ level,ಪೂರ್ಣಾಂಕ optname,ಅಕ್ಷರ *optval,ಪೂರ್ಣಾಂಕ *optlen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ (WSAAPI *LPFN_INET_ADDR)(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *cp);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಅಕ್ಷರ *(WSAAPI *LPFN_INET_NTOA)(ರಚನೆ ಒಳ_addr ಒಳ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_LISTEN)(SOCKET s,ಪೂರ್ಣಾಂಕ backlog);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ u_long (WSAAPI *LPFN_NTOHL)(u_long netlong);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ u_short (WSAAPI *LPFN_NTOHS)(u_short netshort);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_RECV)(SOCKET s,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ flags);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_RECVFROM)(SOCKET s,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ flags,ರಚನೆ sockaddr *from,ಪೂರ್ಣಾಂಕ *fromlen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_SELECT)(ಪೂರ್ಣಾಂಕ nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ಸ್ಥಿರಾಂಕ ರಚನೆ timeval *timeout);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_SEND)(SOCKET s,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ flags);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_SENDTO)(SOCKET s,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ flags,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *ಗಮ್ಯ,ಪೂರ್ಣಾಂಕ tolen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s,ಪೂರ್ಣಾಂಕ level,ಪೂರ್ಣಾಂಕ optname,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *optval,ಪೂರ್ಣಾಂಕ optlen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_SHUTDOWN)(SOCKET s,ಪೂರ್ಣಾಂಕ how);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SOCKET (WSAAPI *LPFN_SOCKET)(ಪೂರ್ಣಾಂಕ af,ಪೂರ್ಣಾಂಕ type,ಪೂರ್ಣಾಂಕ protocol);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ hostent *(WSAAPI *LPFN_GETHOSTBYADDR)(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *addr,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ type);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ hostent *(WSAAPI *LPFN_GETHOSTBYNAME)(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_GETHOSTNAME)(ಅಕ್ಷರ *name,ಪೂರ್ಣಾಂಕ namelen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ servent *(WSAAPI *LPFN_GETSERVBYPORT)(ಪೂರ್ಣಾಂಕ ಪೋರ್ಟ್_2,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *proto);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ servent *(WSAAPI *LPFN_GETSERVBYNAME)(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *proto);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(ಪೂರ್ಣಾಂಕ ಸಂಖ್ಯೆ_3);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSASTARTUP)(ಶಬ್ದ_3 w_ಆವೃತ್ತಿ_Requested,LPWSADATA lpWSAData);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSACLEANUP)(ಶೂನ್ಯ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಶೂನ್ಯ (WSAAPI *LPFN_WSASETLASTERROR)(ಪೂರ್ಣಾಂಕ iError);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAGETLASTERROR)(ಶೂನ್ಯ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(ಶೂನ್ಯ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(ಶೂನ್ಯ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lp_ಖಂಡ_Func);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(ಶೂನ್ಯ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_ಸಂದೇಶ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *proto,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_ಸಂದೇಶ,ಪೂರ್ಣಾಂಕ ಪೋರ್ಟ್_2,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *proto,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_ಸಂದೇಶ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_ಸಂದೇಶ,ಪೂರ್ಣಾಂಕ ಸಂಖ್ಯೆ_3,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_ಸಂದೇಶ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_ಸಂದೇಶ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *addr,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ type,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_ಸಂದೇಶ,ದೀರ್ಘ lEvent);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,ರಚನೆ sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_ದತ್ತಾಂಶ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSACONNECT)(SOCKET s,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ namelen,LPWSABUF lp_Caller_ದತ್ತಾಂಶ,LPWSABUF lp_Callee_ದತ್ತಾಂಶ,LPQOS lpSQOS,LPQOS lpGQOS);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(ಶೂನ್ಯ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_ಜಾಲ_Events);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_ಬಫರ್,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_ಬಫರ್,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,ದೀರ್ಘ l_ಜಾಲ_Events);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dw_Io_Control_ಸಂಕೇತ,LPVOID lpv_ಒಳ_ಬಫರ್,DWORD cb_ಒಳ_ಬಫರ್,LPVOID lpv_ಹೊರಹೋಗು_ಬಫರ್,DWORD cb_ಹೊರಹೋಗು_ಬಫರ್,LPDWORD lpcb_ಬೈಟುಗಳು_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ namelen,LPWSABUF lp_Caller_ದತ್ತಾಂಶ,LPWSABUF lp_Callee_ದತ್ತಾಂಶ,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ಬಫರ್_ಎಣಿಕೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_ದತ್ತಾಂಶ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ಬಫರ್_ಎಣಿಕೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Recvd,LPDWORD lpFlags,ರಚನೆ sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ಬಫರ್_ಎಣಿಕೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಕಳುಹಿಸಿದ,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_ದತ್ತಾಂಶ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ಬಫರ್_ಎಣಿಕೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಕಳುಹಿಸಿದ,DWORD dwFlags,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *lp_ಗಮ್ಯ,ಪೂರ್ಣಾಂಕ iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SOCKET (WSAAPI *LPFN_WSASOCKETA)(ಪೂರ್ಣಾಂಕ af,ಪೂರ್ಣಾಂಕ type,ಪೂರ್ಣಾಂಕ protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,ಗುಂಪು_3 g,DWORD dwFlags);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SOCKET (WSAAPI *LPFN_WSASOCKETW)(ಪೂರ್ಣಾಂಕ af,ಪೂರ್ಣಾಂಕ type,ಪೂರ್ಣಾಂಕ protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,ಗುಂಪು_3 g,DWORD dwFlags);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,ಸ್ಥಿರಾಂಕ WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsa_ವಿಳಾಸ,DWORD dw_ವಿಳಾಸ_ಉದ್ದಳತೆ,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_ವಿಳಾಸ_String,LPDWORD lpdw_ವಿಳಾಸ_String_ಉದ್ದಳತೆ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsa_ವಿಳಾಸ,DWORD dw_ವಿಳಾಸ_ಉದ್ದಳತೆ,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_ವಿಳಾಸ_String,LPDWORD lpdw_ವಿಳಾಸ_String_ಉದ್ದಳತೆ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR ವಿಳಾಸ_String,INT ವಿಳಾಸ_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_ವಿಳಾಸ,LPINT lp_ವಿಳಾಸ_ಉದ್ದಳತೆ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR ವಿಳಾಸ_String,INT ವಿಳಾಸ_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_ವಿಳಾಸ,LPINT lp_ವಿಳಾಸ_ಉದ್ದಳತೆ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ,LPWSAQUERYSETA lpqsResults);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ,LPWSAQUERYSETW lpqsResults);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dw_Control_ಸಂಕೇತ,LPVOID lpv_ಒಳ_ಬಫರ್,DWORD cb_ಒಳ_ಬಫರ್,LPVOID lpv_ಹೊರಹೋಗು_ಬಫರ್,DWORD cb_ಹೊರಹೋಗು_ಬಫರ್,LPDWORD lpcb_ಬೈಟುಗಳು_Returned,LPWSACOMPLETION lpCompletion);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ಗಾತ್ರ,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ಗಾತ್ರ,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ,LPWSANAMESPACE_INFOA lpnsp_ಬಫರ್);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ,LPWSANAMESPACE_INFOW lpnsp_ಬಫರ್);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು WSADuplicateSocket WSADuplicateSocketW
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEnumProtocols WSAEnumProtocolsW
#ವ್ಯಾಖ್ಯಾನಿಸು WSAAddress_ಗಮ್ಯ_String WSAAddress_ಗಮ್ಯ_String_W
#ವ್ಯಾಖ್ಯಾನಿಸು WSASocket WSASocketW
#ವ್ಯಾಖ್ಯಾನಿಸು WSAString_ಗಮ್ಯ_ವಿಳಾಸ WSAString_ಗಮ್ಯ_ವಿಳಾಸ_W
#ವ್ಯಾಖ್ಯಾನಿಸು WSALookupServiceBegin WSALookupServiceBeginW
#ವ್ಯಾಖ್ಯಾನಿಸು WSALookup_Service_ಮುಂದಿನ WSALookup_Service_ಮುಂದಿನ_W
#ವ್ಯಾಖ್ಯಾನಿಸು WSAInstallServiceClass WSAInstallServiceClassW
#ವ್ಯಾಖ್ಯಾನಿಸು WSAGetServiceClassInfo WSAGetServiceClassInfoW
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#ವ್ಯಾಖ್ಯಾನಿಸು WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#ವ್ಯಾಖ್ಯಾನಿಸು WSASetService WSASetServiceW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು WSADuplicateSocket WSADuplicateSocketA
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEnumProtocols WSAEnumProtocolsA
#ವ್ಯಾಖ್ಯಾನಿಸು WSASocket WSASocketA
#ವ್ಯಾಖ್ಯಾನಿಸು WSAAddress_ಗಮ್ಯ_String WSAAddress_ಗಮ್ಯ_String_A
#ವ್ಯಾಖ್ಯಾನಿಸು WSAString_ಗಮ್ಯ_ವಿಳಾಸ WSAString_ಗಮ್ಯ_ವಿಳಾಸ_A
#ವ್ಯಾಖ್ಯಾನಿಸು WSALookupServiceBegin WSALookupServiceBeginA
#ವ್ಯಾಖ್ಯಾನಿಸು WSALookup_Service_ಮುಂದಿನ WSALookup_Service_ಮುಂದಿನ_A
#ವ್ಯಾಖ್ಯಾನಿಸು WSAInstallServiceClass WSAInstallServiceClassA
#ವ್ಯಾಖ್ಯಾನಿಸು WSAGetServiceClassInfo WSAGetServiceClassInfoA
#ವ್ಯಾಖ್ಯಾನಿಸು WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#ವ್ಯಾಖ್ಯಾನಿಸು WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#ವ್ಯಾಖ್ಯಾನಿಸು WSASetService WSASetServiceA
#ಆದರೆ_ಅಂತ್ಯ

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,ರಚನೆ sockaddr *addr,ಪೂರ್ಣಾಂಕ *addrlen);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI bind(SOCKET s,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ namelen);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI connect(SOCKET s,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ namelen);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI ioctlsocket(SOCKET s,ದೀರ್ಘ cmd,u_long *argp);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI getpeername(SOCKET s,ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ *namelen);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI getsockname(SOCKET s,ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ *namelen);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI getsockopt(SOCKET s,ಪೂರ್ಣಾಂಕ level,ಪೂರ್ಣಾಂಕ optname,ಅಕ್ಷರ *optval,ಪೂರ್ಣಾಂಕ *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ WSAAPI inet_addr(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *cp);
  WINSOCK_API_LINKAGE ಅಕ್ಷರ *WSAAPI inet_ntoa(ರಚನೆ ಒಳ_addr ಒಳ);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI listen(SOCKET s,ಪೂರ್ಣಾಂಕ backlog);
  WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI recv(SOCKET s,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ flags);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI recvfrom(SOCKET s,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ flags,ರಚನೆ sockaddr *from,ಪೂರ್ಣಾಂಕ *fromlen);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI select(ಪೂರ್ಣಾಂಕ nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ಸ್ಥಿರಾಂಕ ರಚನೆ timeval *timeout);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI send(SOCKET s,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ flags);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI sendto(SOCKET s,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ flags,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *ಗಮ್ಯ,ಪೂರ್ಣಾಂಕ tolen);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI setsockopt(SOCKET s,ಪೂರ್ಣಾಂಕ level,ಪೂರ್ಣಾಂಕ optname,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *optval,ಪೂರ್ಣಾಂಕ optlen);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI shutdown(SOCKET s,ಪೂರ್ಣಾಂಕ how);
  WINSOCK_API_LINKAGE SOCKET WSAAPI socket(ಪೂರ್ಣಾಂಕ af,ಪೂರ್ಣಾಂಕ type,ಪೂರ್ಣಾಂಕ protocol);
  WINSOCK_API_LINKAGE ರಚನೆ hostent *WSAAPI gethostbyaddr(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *addr,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ type);
  WINSOCK_API_LINKAGE ರಚನೆ hostent *WSAAPI gethostbyname(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI gethostname(ಅಕ್ಷರ *name,ಪೂರ್ಣಾಂಕ namelen);
  WINSOCK_API_LINKAGE ರಚನೆ servent *WSAAPI getservbyport(ಪೂರ್ಣಾಂಕ ಪೋರ್ಟ್_2,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *proto);
  WINSOCK_API_LINKAGE ರಚನೆ servent *WSAAPI getservbyname(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *proto);
  WINSOCK_API_LINKAGE ರಚನೆ protoent *WSAAPI getprotobynumber(ಪೂರ್ಣಾಂಕ ಸಂಖ್ಯೆ_3);
  WINSOCK_API_LINKAGE ರಚನೆ protoent *WSAAPI getprotobyname(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAStartup(ಶಬ್ದ_3 w_ಆವೃತ್ತಿ_Requested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSACleanup(ಶೂನ್ಯ);
  WINSOCK_API_LINKAGE ಶೂನ್ಯ WSAAPI WSASet_ಕೊನೆಯ_Error(ಪೂರ್ಣಾಂಕ iError);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAGet_ಕೊನೆಯ_Error(ಶೂನ್ಯ);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(ಶೂನ್ಯ);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAUnhookBlockingHook(ಶೂನ್ಯ);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lp_ಖಂಡ_Func);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSACancelBlockingCall(ಶೂನ್ಯ);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_ಸಂದೇಶ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *proto,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Serv_By_ಪೋರ್ಟ್(HWND hWnd,u_int w_ಸಂದೇಶ,ಪೂರ್ಣಾಂಕ ಪೋರ್ಟ್_2,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *proto,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_ಸಂದೇಶ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_ಸಂಖ್ಯೆ(HWND hWnd,u_int w_ಸಂದೇಶ,ಪೂರ್ಣಾಂಕ ಸಂಖ್ಯೆ_3,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_ಸಂದೇಶ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *name,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_ಸಂದೇಶ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *addr,ಪೂರ್ಣಾಂಕ len,ಪೂರ್ಣಾಂಕ type,ಅಕ್ಷರ *buf,ಪೂರ್ಣಾಂಕ buflen);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_ಸಂದೇಶ,ದೀರ್ಘ lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,ರಚನೆ sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_ದತ್ತಾಂಶ);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAConnect(SOCKET s,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ namelen,LPWSABUF lp_Caller_ದತ್ತಾಂಶ,LPWSABUF lp_Callee_ದತ್ತಾಂಶ,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(ಶೂನ್ಯ);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAEnum_ಜಾಲ_Events(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_ಜಾಲ_Events);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_ಬಫರ್,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_ಬಫರ್,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,ದೀರ್ಘ l_ಜಾಲ_Events);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_ಫಲಿತಾಂಶ(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAIoctl(SOCKET s,DWORD dw_Io_Control_ಸಂಕೇತ,LPVOID lpv_ಒಳ_ಬಫರ್,DWORD cb_ಒಳ_ಬಫರ್,LPVOID lpv_ಹೊರಹೋಗು_ಬಫರ್,DWORD cb_ಹೊರಹೋಗು_ಬಫರ್,LPDWORD lpcb_ಬೈಟುಗಳು_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoin_ಎಲೆ(SOCKET s,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *name,ಪೂರ್ಣಾಂಕ namelen,LPWSABUF lp_Caller_ದತ್ತಾಂಶ,LPWSABUF lp_Callee_ದತ್ತಾಂಶ,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ಬಫರ್_ಎಣಿಕೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_ದತ್ತಾಂಶ);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ಬಫರ್_ಎಣಿಕೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Recvd,LPDWORD lpFlags,ರಚನೆ sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ಬಫರ್_ಎಣಿಕೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಕಳುಹಿಸಿದ,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_ದತ್ತಾಂಶ);
  WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSASend_ಗಮ್ಯ(SOCKET s,LPWSABUF lpBuffers,DWORD dw_ಬಫರ್_ಎಣಿಕೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಕಳುಹಿಸಿದ,DWORD dwFlags,ಸ್ಥಿರಾಂಕ ರಚನೆ sockaddr *lp_ಗಮ್ಯ,ಪೂರ್ಣಾಂಕ iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(ಪೂರ್ಣಾಂಕ af,ಪೂರ್ಣಾಂಕ type,ಪೂರ್ಣಾಂಕ protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,ಗುಂಪು_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(ಪೂರ್ಣಾಂಕ af,ಪೂರ್ಣಾಂಕ type,ಪೂರ್ಣಾಂಕ protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,ಗುಂಪು_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWait_For_ಅಪವರ್ತ್ಯ_Events(DWORD cEvents,ಸ್ಥಿರಾಂಕ WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_ಗಮ್ಯ_String_A(LPSOCKADDR lpsa_ವಿಳಾಸ,DWORD dw_ವಿಳಾಸ_ಉದ್ದಳತೆ,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_ವಿಳಾಸ_String,LPDWORD lpdw_ವಿಳಾಸ_String_ಉದ್ದಳತೆ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_ಗಮ್ಯ_String_W(LPSOCKADDR lpsa_ವಿಳಾಸ,DWORD dw_ವಿಳಾಸ_ಉದ್ದಳತೆ,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_ವಿಳಾಸ_String,LPDWORD lpdw_ವಿಳಾಸ_String_ಉದ್ದಳತೆ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_ಗಮ್ಯ_ವಿಳಾಸ_A(LPSTR ವಿಳಾಸ_String,INT ವಿಳಾಸ_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_ವಿಳಾಸ,LPINT lp_ವಿಳಾಸ_ಉದ್ದಳತೆ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_ಗಮ್ಯ_ವಿಳಾಸ_W(LPWSTR ವಿಳಾಸ_String,INT ವಿಳಾಸ_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_ವಿಳಾಸ,LPINT lp_ವಿಳಾಸ_ಉದ್ದಳತೆ);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_ಮುಂದಿನ_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_ಮುಂದಿನ_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dw_Control_ಸಂಕೇತ,LPVOID lpv_ಒಳ_ಬಫರ್,DWORD cb_ಒಳ_ಬಫರ್,LPVOID lpv_ಹೊರಹೋಗು_ಬಫರ್,DWORD cb_ಹೊರಹೋಗು_ಬಫರ್,LPDWORD lpcb_ಬೈಟುಗಳು_Returned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_ಕೊನೆ(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ಗಾತ್ರ,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ಗಾತ್ರ,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ,LPWSANAMESPACE_INFOA lpnsp_ಬಫರ್);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ,LPWSANAMESPACE_INFOW lpnsp_ಬಫರ್);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr_ಒಳ SOCKADDR_ಒಳ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr_ಒಳ *PSOCKADDR_ಒಳ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ sockaddr_ಒಳ *LPSOCKADDR_ಒಳ;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ linger LINGER;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ linger *PLINGER;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ linger *LPLINGER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಒಳ_addr ಒಳ_ADDR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಒಳ_addr *PIN_ADDR;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಒಳ_addr *LPIN_ADDR;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ fd_set FD_SET;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ fd_set *PFD_ಗಣ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ fd_set *LPFD_ಗಣ;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ hostent HOSTENT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ hostent *PHOSTENT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ hostent *LPHOSTENT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ servent SERVENT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ servent *PSERVENT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ servent *LPSERVENT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ protoent PROTOENT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ protoent *PPROTOENT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ protoent *LPPROTOENT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ timeval TIMEVAL;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ timeval *PTIMEVAL;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ timeval *LPTIMEVAL;

#ವ್ಯಾಖ್ಯಾನಿಸು WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAGETASYNCERROR(lParam) HIWORD(lParam)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#ವ್ಯಾಖ್ಯಾನಿಸು WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#ವ್ಯಾಖ್ಯಾನಿಸು POLLRDNORM  0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು POLLRDBAND  0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು POLLIN      (POLLRDNORM | POLLRDBAND)
#ವ್ಯಾಖ್ಯಾನಿಸು POLLPRI     0x0400

#ವ್ಯಾಖ್ಯಾನಿಸು POLLWRNORM  0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು POLLOUT     (POLLWRNORM)
#ವ್ಯಾಖ್ಯಾನಿಸು POLLWRBAND  0x0020

#ವ್ಯಾಖ್ಯಾನಿಸು POLLERR     0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು POLLHUP     0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು POLLNVAL    0x0004

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE ಪೂರ್ಣಾಂಕ WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _NEED_POPPACK
#ಅನ್ತರ್ಭಾವ <poppack.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ IPV6STRICT
#ಅನ್ತರ್ಭಾವ <wsipv6ok.h>
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINSOCKAPI_
#ವ್ಯಾಖ್ಯಾನಿಸು _WINSOCKAPI_
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _INC_WINSOCK_H
#ಅನ್ತರ್ಭಾವ <mswsock.h>
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ_ಅಂತ್ಯ
