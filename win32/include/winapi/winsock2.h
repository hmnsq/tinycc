/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#جيڪڏهن_وصف_نه_ٿيل _WINSOCK2API_
#وصف_ڪريو _WINSOCK2API_

#جيڪڏهن_وصف_نه_ٿيل INCL_WINSOCK_API_TYPEDEFS
#وصف_ڪريو INCL_WINSOCK_API_TYPEDEFS 0
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _INC_WINDOWS
#ضمن <windows.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل MAKEWORD
#وصف_ڪريو MAKEWORD(هيٺيون,مٿاهون) ((لفظ_3)(((BYTE)(هيٺيون)) | ((لفظ_3)((BYTE)(مٿاهون))) << 8))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WINSOCK_نسخو
#وصف_ڪريو WINSOCK_نسخو MAKEWORD(2,2)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WINSOCK_API_LINKAGE
#جيڪڏهن_وصف_ٿيل DECLSPEC_IMPORT
#وصف_ڪريو WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#وإلا
#وصف_ڪريو WINSOCK_API_LINKAGE
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WINSOCK_SOCKET_DEFINED
#وصف_ڪريو _WINSOCK_SOCKET_DEFINED
  تعريفنوع بنانشان حرف u_char;
  تعريفنوع بنانشان ننڍو u_short;
  تعريفنوع بنانشان صحيح u_int;
  تعريفنوع بنانشان ڊگهو u_long;
  __MINGW_EXTENSION تعريفنوع بنانشان __int64 u_int64;
  تعريفنوع INT_PTR SOCKET;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل FD_SETSIZE
#وصف_ڪريو FD_SETSIZE 64
#جيڪڏهن_پورو

  تعريفنوع بنية fd_set {
    u_int fd_ڳڻپ;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  خارجي صحيح WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#وصف_ڪريو FD_CLR(fd,سيٽ) افعل { u_int __i; لكل(__i = 0;__i < ((fd_set *)(سيٽ))->fd_ڳڻپ;__i++) { إذا (((fd_set *)(سيٽ))->fd_array[__i]==fd) { طالما (__i < ((fd_set *)(سيٽ))->fd_ڳڻپ-1) { ((fd_set *)(سيٽ))->fd_array[__i] = ((fd_set *)(سيٽ))->fd_array[__i+1]; __i++; } ((fd_set *)(سيٽ))->fd_ڳڻپ--; اكسر; } } } طالما(0)
#وصف_ڪريو FD_SET(fd,سيٽ) افعل { u_int __i; لكل(__i = 0;__i < ((fd_set *)(سيٽ))->fd_ڳڻپ;__i++) { إذا (((fd_set *)(سيٽ))->fd_array[__i]==(fd)) { اكسر; } } إذا (__i==((fd_set *)(سيٽ))->fd_ڳڻپ) { إذا (((fd_set *)(سيٽ))->fd_ڳڻپ < FD_SETSIZE) { ((fd_set *)(سيٽ))->fd_array[__i] = (fd); ((fd_set *)(سيٽ))->fd_ڳڻپ++; } } } طالما(0)
#وصف_ڪريو FD_ZERO(سيٽ) (((fd_set *)(سيٽ))->fd_ڳڻپ=0)
#وصف_ڪريو FD_ISSET(fd,سيٽ) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(سيٽ))

#جيڪڏهن_وصف_نه_ٿيل _TIMEVAL_DEFINED /* also in winsock[2].h */
#وصف_ڪريو _TIMEVAL_DEFINED
  بنية timeval {
    ڊگهو tv_sec;
    ڊگهو tv_usec;
  };

#وصف_ڪريو timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#وصف_ڪريو timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#وصف_ڪريو timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#جيڪڏهن_پورو /* _TIMEVAL_DEFINED */

#وصف_ڪريو IOCPARM_نقاب 0x7f
#وصف_ڪريو IOC_VOID 0x20000000
#وصف_ڪريو IOC_ٻاهريون 0x40000000
#وصف_ڪريو IOC_اندريون 0x80000000
#وصف_ڪريو IOC_INOUT (IOC_اندريون|IOC_ٻاهريون)

#وصف_ڪريو _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#وصف_ڪريو _IOR(x,y,t) (IOC_ٻاهريون|(((ڊگهو)حجم(t)&IOCPARM_نقاب)<<16)|((x)<<8)|(y))
#وصف_ڪريو _IOW(x,y,t) (IOC_اندريون|(((ڊگهو)حجم(t)&IOCPARM_نقاب)<<16)|((x)<<8)|(y))

#وصف_ڪريو FIONREAD _IOR('f',127,u_long)
#وصف_ڪريو FIONBIO _IOW('f',126,u_long)
#وصف_ڪريو FIOASYNC _IOW('f',125,u_long)

#وصف_ڪريو SIOCSHIWAT _IOW('s',0,u_long)
#وصف_ڪريو SIOCGHIWAT _IOR('s',1,u_long)
#وصف_ڪريو SIOCSLOWAT _IOW('s',2,u_long)
#وصف_ڪريو SIOCGLOWAT _IOR('s',3,u_long)
#وصف_ڪريو SIOCATMARK _IOR('s',7,u_long)

#وصف_ڪريو h_addr h_addr_list[0]

  بنية hostent {
    حرف *h_name;
    حرف **h_aliases;
    ننڍو h_addrtype;
    ننڍو h_ڊيگهائي;
    حرف **h_addr_list;
  };

  بنية netent {
    حرف *n_name;
    حرف **n_aliases;
    ننڍو n_addrtype;
    u_long n_net;
  };

  بنية servent {
    حرف *s_name;
    حرف **s_aliases;
#جيڪڏهن_وصف_ٿيل _WIN64
    حرف *s_proto;
    ننڍو s_پورٽ;
#وإلا
    ننڍو s_پورٽ;
    حرف *s_proto;
#جيڪڏهن_پورو
  };

  بنية protoent {
    حرف *p_name;
    حرف **p_aliases;
    ننڍو p_proto;
  };

#وصف_ڪريو IPPROTO_IP 0
#وصف_ڪريو IPPROTO_HOPOPTS 0
#وصف_ڪريو IPPROTO_ICMP 1
#وصف_ڪريو IPPROTO_IGMP 2
#وصف_ڪريو IPPROTO_GGP 3
#وصف_ڪريو IPPROTO_IPV4 4
#وصف_ڪريو IPPROTO_TCP 6
#وصف_ڪريو IPPROTO_PUP 12
#وصف_ڪريو IPPROTO_UDP 17
#وصف_ڪريو IPPROTO_IDP 22
#وصف_ڪريو IPPROTO_IPV6 41
#وصف_ڪريو IPPROTO_ROUTING 43
#وصف_ڪريو IPPROTO_FRAGMENT 44
#وصف_ڪريو IPPROTO_ESP 50
#وصف_ڪريو IPPROTO_AH 51
#وصف_ڪريو IPPROTO_ICMPV6 58
#وصف_ڪريو IPPROTO_NONE 59
#وصف_ڪريو IPPROTO_DSTOPTS 60
#وصف_ڪريو IPPROTO_ND 77
#وصف_ڪريو IPPROTO_ICLFXBM 78

#وصف_ڪريو IPPROTO_RAW 255
#وصف_ڪريو IPPROTO_MAX 256

#وصف_ڪريو IPPORT_ECHO 7
#وصف_ڪريو IPPORT_DISCARD 9
#وصف_ڪريو IPPORT_SYSTAT 11
#وصف_ڪريو IPPORT_DAYTIME 13
#وصف_ڪريو IPPORT_NETSTAT 15
#وصف_ڪريو IPPORT_FTP 21
#وصف_ڪريو IPPORT_TELNET 23
#وصف_ڪريو IPPORT_SMTP 25
#وصف_ڪريو IPPORT_TIMESERVER 37
#وصف_ڪريو IPPORT_NAMESERVER 42
#وصف_ڪريو IPPORT_WHOIS 43
#وصف_ڪريو IPPORT_MTP 57

#وصف_ڪريو IPPORT_TFTP 69
#وصف_ڪريو IPPORT_RJE 77
#وصف_ڪريو IPPORT_FINGER 79
#وصف_ڪريو IPPORT_TTYLINK 87
#وصف_ڪريو IPPORT_SUPDUP 95

#وصف_ڪريو IPPORT_EXECSERVER 512
#وصف_ڪريو IPPORT_LOGINSERVER 513
#وصف_ڪريو IPPORT_CMDSERVER 514
#وصف_ڪريو IPPORT_EFSSERVER 520

#وصف_ڪريو IPPORT_BIFFUDP 512
#وصف_ڪريو IPPORT_WHOSERVER 513
#وصف_ڪريو IPPORT_ROUTESERVER 520

#وصف_ڪريو IPPORT_RESERVED 1024

#وصف_ڪريو IMPLINK_IP 155
#وصف_ڪريو IMPLINK_LOWEXPER 156
#وصف_ڪريو IMPLINK_HIGHEXPER 158

#جيڪڏهن_وصف_نه_ٿيل s_addr

  بنية اندريون_addr {
    اتحاد {
      بنية { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      بنية { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#وصف_ڪريو s_addr S_un.S_addr
#وصف_ڪريو s_host S_un.S_un_b.s_b2
#وصف_ڪريو s_net S_un.S_un_b.s_b1
#وصف_ڪريو s_imp S_un.S_un_w.s_w2
#وصف_ڪريو s_impno S_un.S_un_b.s_b4
#وصف_ڪريو s_lh S_un.S_un_b.s_b3

#جيڪڏهن_پورو

#وصف_ڪريو اندريون_CLASSA(i) (((ڊگهو)(i) & 0x80000000)==0)
#وصف_ڪريو اندريون_CLASSA_NET 0xff000000
#وصف_ڪريو اندريون_CLASSA_NSHIFT 24
#وصف_ڪريو اندريون_CLASSA_HOST 0x00ffffff
#وصف_ڪريو اندريون_CLASSA_MAX 128

#وصف_ڪريو اندريون_CLASSB(i) (((ڊگهو)(i) & 0xc0000000)==0x80000000)
#وصف_ڪريو اندريون_CLASSB_NET 0xffff0000
#وصف_ڪريو اندريون_CLASSB_NSHIFT 16
#وصف_ڪريو اندريون_CLASSB_HOST 0x0000ffff
#وصف_ڪريو اندريون_CLASSB_MAX 65536

#وصف_ڪريو اندريون_CLASSC(i) (((ڊگهو)(i) & 0xe0000000)==0xc0000000)
#وصف_ڪريو اندريون_CLASSC_NET 0xffffff00
#وصف_ڪريو اندريون_CLASSC_NSHIFT 8
#وصف_ڪريو اندريون_CLASSC_HOST 0x000000ff

#وصف_ڪريو اندريون_CLASSD(i) (((ڊگهو)(i) & 0xf0000000)==0xe0000000)
#وصف_ڪريو اندريون_CLASSD_NET 0xf0000000
#وصف_ڪريو اندريون_CLASSD_NSHIFT 28
#وصف_ڪريو اندريون_CLASSD_HOST 0x0fffffff
#وصف_ڪريو اندريون_MULTICAST(i) اندريون_CLASSD(i)

#وصف_ڪريو INADDR_ANY (u_long)0x00000000
#وصف_ڪريو INADDR_LOOPBACK 0x7f000001
#وصف_ڪريو INADDR_نشر (u_long)0xffffffff
#وصف_ڪريو INADDR_NONE 0xffffffff

#وصف_ڪريو ADDR_ANY INADDR_ANY

  بنية sockaddr_اندريون {
    ننڍو sin_family;
    u_short sin_پورٽ;
    بنية اندريون_addr sin_addr;
    حرف sin_zero[8];
  };

#وصف_ڪريو WSADESCRIPTION_LEN 256
#وصف_ڪريو WSASYS_حالت_LEN 128

  تعريفنوع بنية WSAData {
    لفظ_3 w_نسخو;
    لفظ_3 w_مٿاهون_نسخو;
#جيڪڏهن_وصف_ٿيل _WIN64
    بنانشان ننڍو iMaxSockets;
    بنانشان ننڍو iMaxUdpDg;
    حرف *lpVendorInfo;
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_حالت[WSASYS_حالت_LEN+1];
#وإلا
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_حالت[WSASYS_حالت_LEN+1];
    بنانشان ننڍو iMaxSockets;
    بنانشان ننڍو iMaxUdpDg;
    حرف *lpVendorInfo;
#جيڪڏهن_پورو
  } WSADATA,*LPWSADATA;

#وصف_ڪريو INVALID_SOCKET (SOCKET)(~0)
#وصف_ڪريو SOCKET_ERROR (-1)

#وصف_ڪريو FROM_PROTOCOL_INFO (-1)

#وصف_ڪريو SOCK_وهڪرو 1
#وصف_ڪريو SOCK_DGRAM 2
#وصف_ڪريو SOCK_RAW 3
#وصف_ڪريو SOCK_RDM 4
#وصف_ڪريو SOCK_SEQPACKET 5

#وصف_ڪريو SO_DEBUG 0x0001
#وصف_ڪريو SO_ACCEPTCONN 0x0002
#وصف_ڪريو SO_REUSEADDR 0x0004
#وصف_ڪريو SO_KEEPALIVE 0x0008
#وصف_ڪريو SO_DONTROUTE 0x0010
#وصف_ڪريو SO_نشر 0x0020
#وصف_ڪريو SO_USELOOPBACK 0x0040
#وصف_ڪريو SO_LINGER 0x0080
#وصف_ڪريو SO_OOBINLINE 0x0100

#وصف_ڪريو SO_DONTLINGER (صحيح)(~SO_LINGER)
#وصف_ڪريو SO_EXCLUSIVEADDRUSE ((صحيح)(~SO_REUSEADDR))

#وصف_ڪريو SO_SNDBUF 0x1001
#وصف_ڪريو SO_RCVBUF 0x1002
#وصف_ڪريو SO_SNDLOWAT 0x1003
#وصف_ڪريو SO_RCVLOWAT 0x1004
#وصف_ڪريو SO_SNDTIMEO 0x1005
#وصف_ڪريو SO_RCVTIMEO 0x1006
#وصف_ڪريو SO_ERROR 0x1007
#وصف_ڪريو SO_TYPE 0x1008

#وصف_ڪريو SO_گروهه_ID 0x2001
#وصف_ڪريو SO_گروهه_ترجيح 0x2002
#وصف_ڪريو SO_MAX_نياپو_سائيز 0x2003
#وصف_ڪريو SO_PROTOCOL_INFOA 0x2004
#وصف_ڪريو SO_PROTOCOL_INFOW 0x2005
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#وإلا
#وصف_ڪريو SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#جيڪڏهن_پورو
#وصف_ڪريو PVD_CONFIG 0x3001
#وصف_ڪريو SO_CONDITIONAL_ACCEPT 0x3002

#وصف_ڪريو TCP_NODELAY 0x0001

#وصف_ڪريو AF_UNSPEC 0

#وصف_ڪريو AF_UNIX 1
#وصف_ڪريو AF_INET 2
#وصف_ڪريو AF_IMPLINK 3
#وصف_ڪريو AF_PUP 4
#وصف_ڪريو AF_CHAOS 5
#وصف_ڪريو AF_NS 6
#وصف_ڪريو AF_IPX AF_NS
#وصف_ڪريو AF_ISO 7
#وصف_ڪريو AF_OSI AF_ISO
#وصف_ڪريو AF_ECMA 8
#وصف_ڪريو AF_DATAKIT 9
#وصف_ڪريو AF_CCITT 10
#وصف_ڪريو AF_SNA 11
#وصف_ڪريو AF_DECnet 12
#وصف_ڪريو AF_DLI 13
#وصف_ڪريو AF_LAT 14
#وصف_ڪريو AF_HYLINK 15
#وصف_ڪريو AF_APPLETALK 16
#وصف_ڪريو AF_NETBIOS 17
#وصف_ڪريو AF_VOICEVIEW 18
#وصف_ڪريو AF_FIREFOX 19
#وصف_ڪريو AF_UNKNOWN1 20
#وصف_ڪريو AF_BAN 21
#وصف_ڪريو AF_ATM 22
#وصف_ڪريو AF_INET6 23
#وصف_ڪريو AF_CLUSTER 24
#وصف_ڪريو AF_12844 25
#وصف_ڪريو AF_IRDA 26
#وصف_ڪريو AF_NETDES 28
#وصف_ڪريو AF_TCNPROCESS 29
#وصف_ڪريو AF_TCNMESSAGE 30
#وصف_ڪريو AF_ICLFXBM 31

#وصف_ڪريو AF_MAX 32

  بنية sockaddr {
    u_short sa_family;
    حرف sa_معلومات[14];
  };

#وصف_ڪريو _SS_MAXSIZE 128
#وصف_ڪريو _SS_ALIGNSIZE (8)

#وصف_ڪريو SS_PAD1_سائيز (_SS_ALIGNSIZE - حجم (ننڍو))
#وصف_ڪريو SS_PAD2_سائيز (_SS_MAXSIZE - (حجم (ننڍو) + SS_PAD1_سائيز + _SS_ALIGNSIZE))

  بنية sockaddr_storage {
    ننڍو ss_family;
    حرف __ss_pad1[SS_PAD1_سائيز];

    __MINGW_EXTENSION __int64 __ss_align;
    حرف __ss_pad2[SS_PAD2_سائيز];

  };

  بنية sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#وصف_ڪريو PF_UNSPEC AF_UNSPEC
#وصف_ڪريو PF_UNIX AF_UNIX
#وصف_ڪريو PF_INET AF_INET
#وصف_ڪريو PF_IMPLINK AF_IMPLINK
#وصف_ڪريو PF_PUP AF_PUP
#وصف_ڪريو PF_CHAOS AF_CHAOS
#وصف_ڪريو PF_NS AF_NS
#وصف_ڪريو PF_IPX AF_IPX
#وصف_ڪريو PF_ISO AF_ISO
#وصف_ڪريو PF_OSI AF_OSI
#وصف_ڪريو PF_ECMA AF_ECMA
#وصف_ڪريو PF_DATAKIT AF_DATAKIT
#وصف_ڪريو PF_CCITT AF_CCITT
#وصف_ڪريو PF_SNA AF_SNA
#وصف_ڪريو PF_DECnet AF_DECnet
#وصف_ڪريو PF_DLI AF_DLI
#وصف_ڪريو PF_LAT AF_LAT
#وصف_ڪريو PF_HYLINK AF_HYLINK
#وصف_ڪريو PF_APPLETALK AF_APPLETALK
#وصف_ڪريو PF_VOICEVIEW AF_VOICEVIEW
#وصف_ڪريو PF_FIREFOX AF_FIREFOX
#وصف_ڪريو PF_UNKNOWN1 AF_UNKNOWN1
#وصف_ڪريو PF_BAN AF_BAN
#وصف_ڪريو PF_ATM AF_ATM
#وصف_ڪريو PF_INET6 AF_INET6

#وصف_ڪريو PF_MAX AF_MAX

  بنية linger {
    u_short l_onoff;
    u_short l_linger;
  };

#وصف_ڪريو SOL_SOCKET 0xffff

#وصف_ڪريو SOMAXCONN 0x7fffffff

#وصف_ڪريو نياپو_OOB 0x1
#وصف_ڪريو نياپو_PEEK 0x2
#وصف_ڪريو نياپو_DONTROUTE 0x4
#وصف_ڪريو نياپو_WAITALL 0x8

#وصف_ڪريو نياپو_PARTIAL 0x8000

#وصف_ڪريو نياپو_مداخلت 0x10

#وصف_ڪريو نياپو_MAXIOVLEN 16

#وصف_ڪريو MAXGETHOSTSTRUCT 1024

#وصف_ڪريو FD_READ_ٻٽو_انگ 0
#وصف_ڪريو FD_READ (1 << FD_READ_ٻٽو_انگ)

#وصف_ڪريو FD_WRITE_ٻٽو_انگ 1
#وصف_ڪريو FD_WRITE (1 << FD_WRITE_ٻٽو_انگ)

#وصف_ڪريو FD_OOB_ٻٽو_انگ 2
#وصف_ڪريو FD_OOB (1 << FD_OOB_ٻٽو_انگ)

#وصف_ڪريو FD_ACCEPT_ٻٽو_انگ 3
#وصف_ڪريو FD_ACCEPT (1 << FD_ACCEPT_ٻٽو_انگ)

#وصف_ڪريو FD_CONNECT_ٻٽو_انگ 4
#وصف_ڪريو FD_CONNECT (1 << FD_CONNECT_ٻٽو_انگ)

#وصف_ڪريو FD_CLOSE_ٻٽو_انگ 5
#وصف_ڪريو FD_CLOSE (1 << FD_CLOSE_ٻٽو_انگ)

#وصف_ڪريو FD_QOS_ٻٽو_انگ 6
#وصف_ڪريو FD_QOS (1 << FD_QOS_ٻٽو_انگ)

#وصف_ڪريو FD_گروهه_QOS_ٻٽو_انگ 7
#وصف_ڪريو FD_گروهه_QOS (1 << FD_گروهه_QOS_ٻٽو_انگ)

#وصف_ڪريو FD_ROUTING_INTERFACE_CHANGE_ٻٽو_انگ 8
#وصف_ڪريو FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_ٻٽو_انگ)

#وصف_ڪريو FD_پتو_LIST_CHANGE_ٻٽو_انگ 9
#وصف_ڪريو FD_پتو_LIST_CHANGE (1 << FD_پتو_LIST_CHANGE_ٻٽو_انگ)

#وصف_ڪريو FD_MAX_EVENTS 10
#وصف_ڪريو FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#جيڪڏهن_وصف_نه_ٿيل WSABASEERR

#وصف_ڪريو WSABASEERR 10000

#وصف_ڪريو WSAEINTR (WSABASEERR+4)
#وصف_ڪريو WSAEBADF (WSABASEERR+9)
#وصف_ڪريو WSAEACCES (WSABASEERR+13)
#وصف_ڪريو WSAEFAULT (WSABASEERR+14)
#وصف_ڪريو WSAEINVAL (WSABASEERR+22)
#وصف_ڪريو WSAEMFILE (WSABASEERR+24)

#وصف_ڪريو WSAEWOULDBLOCK (WSABASEERR+35)
#وصف_ڪريو WSAEINPROGRESS (WSABASEERR+36)
#وصف_ڪريو WSAEALREADY (WSABASEERR+37)
#وصف_ڪريو WSAENOTSOCK (WSABASEERR+38)
#وصف_ڪريو WSAEDESTADDRREQ (WSABASEERR+39)
#وصف_ڪريو WSAEMSGSIZE (WSABASEERR+40)
#وصف_ڪريو WSAEPROTOTYPE (WSABASEERR+41)
#وصف_ڪريو WSAENOPROTOOPT (WSABASEERR+42)
#وصف_ڪريو WSAEPROTONOSUPPORT (WSABASEERR+43)
#وصف_ڪريو WSAESOCKTNOSUPPORT (WSABASEERR+44)
#وصف_ڪريو WSAEOPNOTSUPP (WSABASEERR+45)
#وصف_ڪريو WSAEPFNOSUPPORT (WSABASEERR+46)
#وصف_ڪريو WSAEAFNOSUPPORT (WSABASEERR+47)
#وصف_ڪريو WSAEADDRINUSE (WSABASEERR+48)
#وصف_ڪريو WSAEADDRNOTAVAIL (WSABASEERR+49)
#وصف_ڪريو WSAENETDOWN (WSABASEERR+50)
#وصف_ڪريو WSAENETUNREACH (WSABASEERR+51)
#وصف_ڪريو WSAENETRESET (WSABASEERR+52)
#وصف_ڪريو WSAECONNABORTED (WSABASEERR+53)
#وصف_ڪريو WSAECONNRESET (WSABASEERR+54)
#وصف_ڪريو WSAENOBUFS (WSABASEERR+55)
#وصف_ڪريو WSAEISCONN (WSABASEERR+56)
#وصف_ڪريو WSAENOTCONN (WSABASEERR+57)
#وصف_ڪريو WSAESHUTDOWN (WSABASEERR+58)
#وصف_ڪريو WSAETOOMANYREFS (WSABASEERR+59)
#وصف_ڪريو WSAETIMEDOUT (WSABASEERR+60)
#وصف_ڪريو WSAECONNREFUSED (WSABASEERR+61)
#وصف_ڪريو WSAELOOP (WSABASEERR+62)
#وصف_ڪريو WSAENAMETOOLONG (WSABASEERR+63)
#وصف_ڪريو WSAEHOSTDOWN (WSABASEERR+64)
#وصف_ڪريو WSAEHOSTUNREACH (WSABASEERR+65)
#وصف_ڪريو WSAENOTEMPTY (WSABASEERR+66)
#وصف_ڪريو WSAEPROCLIM (WSABASEERR+67)
#وصف_ڪريو WSAEUSERS (WSABASEERR+68)
#وصف_ڪريو WSAEDQUOT (WSABASEERR+69)
#وصف_ڪريو WSAESTALE (WSABASEERR+70)
#وصف_ڪريو WSAEREMOTE (WSABASEERR+71)

#وصف_ڪريو WSASYSNOTREADY (WSABASEERR+91)
#وصف_ڪريو WSAVERNOTSUPPORTED (WSABASEERR+92)
#وصف_ڪريو WSANOTINITIALISED (WSABASEERR+93)
#وصف_ڪريو WSAEDISCON (WSABASEERR+101)
#جيڪڏهن_وصف_نه_ٿيل WSAHOST_NOT_مليو
#وصف_ڪريو WSAHOST_NOT_مليو (WSABASEERR+1001)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSATRY_AGAIN
#وصف_ڪريو WSATRY_AGAIN (WSABASEERR+1002)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSANO_RECOVERY
#وصف_ڪريو WSANO_RECOVERY (WSABASEERR+1003)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSANO_معلومات
#وصف_ڪريو WSANO_معلومات (WSABASEERR+1004)
#جيڪڏهن_پورو

#وصف_ڪريو WSAENOMORE (WSABASEERR+102)
#وصف_ڪريو WSAECANCELLED (WSABASEERR+103)
#وصف_ڪريو WSAEINVALIDPROCTABLE (WSABASEERR+104)
#وصف_ڪريو WSAEINVALIDPROVIDER (WSABASEERR+105)
#وصف_ڪريو WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#وصف_ڪريو WSASYSCALLFAILURE (WSABASEERR+107)
#وصف_ڪريو WSASERVICE_NOT_مليو (WSABASEERR+108)
#وصف_ڪريو WSATYPE_NOT_مليو (WSABASEERR+109)
#وصف_ڪريو WSA_E_NO_وڌيڪ (WSABASEERR+110)
#وصف_ڪريو WSA_E_CANCELLED (WSABASEERR+111)
#وصف_ڪريو WSAEREFUSED (WSABASEERR+112)
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_RECEIVERS
#وصف_ڪريو WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_SENDERS
#وصف_ڪريو WSA_QOS_SENDERS (WSABASEERR + 1006)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_NO_SENDERS
#وصف_ڪريو WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#وصف_ڪريو WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#وصف_ڪريو WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#وصف_ڪريو WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#وصف_ڪريو WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#وصف_ڪريو WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#وصف_ڪريو WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#وصف_ڪريو WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#وصف_ڪريو WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#وصف_ڪريو WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#وصف_ڪريو WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#وصف_ڪريو WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EFILTERSTYLE
#وصف_ڪريو WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EFILTERTYPE
#وصف_ڪريو WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EFILTERCOUNT
#وصف_ڪريو WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EOBJLENGTH
#وصف_ڪريو WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EFLOWCOUNT
#وصف_ڪريو WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EUNKNOWNPSOBJ
#وصف_ڪريو WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EPOLICYOBJ
#وصف_ڪريو WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EFLOWDESC
#وصف_ڪريو WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EPSFLOWSPEC
#وصف_ڪريو WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_EPSFILTERSPEC
#وصف_ڪريو WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_ESDMODEOBJ
#وصف_ڪريو WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_ESHAPERATEOBJ
#وصف_ڪريو WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WSA_QOS_RESERVED_PETYPE
#وصف_ڪريو WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#جيڪڏهن_پورو
#جيڪڏهن_پورو // WSABASEERR

#وصف_ڪريو h_errno WSAGet_آخري_Error()
#وصف_ڪريو HOST_NOT_مليو WSAHOST_NOT_مليو
#وصف_ڪريو TRY_AGAIN WSATRY_AGAIN
#وصف_ڪريو NO_RECOVERY WSANO_RECOVERY
#وصف_ڪريو NO_معلومات WSANO_معلومات

#وصف_ڪريو WSANO_پتو WSANO_معلومات
#وصف_ڪريو NO_پتو WSANO_پتو

#إذا 0
#وصف_ڪريو EWOULDBLOCK WSAEWOULDBLOCK
#وصف_ڪريو EINPROGRESS WSAEINPROGRESS
#وصف_ڪريو EALREADY WSAEALREADY
#وصف_ڪريو ENOTSOCK WSAENOTSOCK
#وصف_ڪريو EDESTADDRREQ WSAEDESTADDRREQ
#وصف_ڪريو EMSGSIZE WSAEMSGSIZE
#وصف_ڪريو EPROTOTYPE WSAEPROTOTYPE
#وصف_ڪريو ENOPROTOOPT WSAENOPROTOOPT
#وصف_ڪريو EPROTONOSUPPORT WSAEPROTONOSUPPORT
#وصف_ڪريو ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#وصف_ڪريو EOPNOTSUPP WSAEOPNOTSUPP
#وصف_ڪريو EPFNOSUPPORT WSAEPFNOSUPPORT
#وصف_ڪريو EAFNOSUPPORT WSAEAFNOSUPPORT
#وصف_ڪريو EADDRINUSE WSAEADDRINUSE
#وصف_ڪريو EADDRNOTAVAIL WSAEADDRNOTAVAIL
#وصف_ڪريو ENETDOWN WSAENETDOWN
#وصف_ڪريو ENETUNREACH WSAENETUNREACH
#وصف_ڪريو ENETRESET WSAENETRESET
#وصف_ڪريو ECONNABORTED WSAECONNABORTED
#وصف_ڪريو ECONNRESET WSAECONNRESET
#وصف_ڪريو ENOBUFS WSAENOBUFS
#وصف_ڪريو EISCONN WSAEISCONN
#وصف_ڪريو ENOTCONN WSAENOTCONN
#وصف_ڪريو ESHUTDOWN WSAESHUTDOWN
#وصف_ڪريو ETOOMANYREFS WSAETOOMANYREFS
#وصف_ڪريو ETIMEDOUT WSAETIMEDOUT
#وصف_ڪريو ECONNREFUSED WSAECONNREFUSED
#وصف_ڪريو ELOOP WSAELOOP
#وصف_ڪريو ENAMETOOLONG WSAENAMETOOLONG
#وصف_ڪريو EHOSTDOWN WSAEHOSTDOWN
#وصف_ڪريو EHOSTUNREACH WSAEHOSTUNREACH
#وصف_ڪريو ENOTEMPTY WSAENOTEMPTY
#وصف_ڪريو EPROCLIM WSAEPROCLIM
#وصف_ڪريو EUSERS WSAEUSERS
#وصف_ڪريو EDQUOT WSAEDQUOT
#وصف_ڪريو ESTALE WSAESTALE
#وصف_ڪريو EREMOTE WSAEREMOTE
#جيڪڏهن_پورو

#وصف_ڪريو WSAAPI WINAPI
#وصف_ڪريو WSAEVENT HANDLE
#وصف_ڪريو LPWSAEVENT LPHANDLE
#وصف_ڪريو WSAOVERLAPPED OVERLAPPED
  تعريفنوع بنية _OVERLAPPED *LPWSAOVERLAPPED;

#وصف_ڪريو WSA_IO_PENDING (ERROR_IO_PENDING)
#وصف_ڪريو WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#وصف_ڪريو WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#وصف_ڪريو WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#وصف_ڪريو WSA_NOT_ENOUGH_يادگيري (ERROR_NOT_ENOUGH_يادگيري)
#وصف_ڪريو WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#وصف_ڪريو WSA_INVALID_EVENT ((WSAEVENT)عدم)
#وصف_ڪريو WSA_وڌ_کان_وڌ_WAIT_EVENTS (وڌ_کان_وڌ_WAIT_OBJECTS)
#وصف_ڪريو WSA_WAIT_FAILED (WAIT_FAILED)
#وصف_ڪريو WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#وصف_ڪريو WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#وصف_ڪريو WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#وصف_ڪريو WSA_INFINITE (INFINITE)

  تعريفنوع بنية _WSABUF {
    u_long len;
    حرف *buf;
  } WSABUF,*LPWSABUF;

#ضمن <qos.h>

  تعريفنوع بنية Quality_جو_Service {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#وصف_ڪريو CF_ACCEPT 0x0000
#وصف_ڪريو CF_REJECT 0x0001
#وصف_ڪريو CF_DEFER 0x0002

#وصف_ڪريو SD_RECEIVE 0x00
#وصف_ڪريو SD_SEND 0x01
#وصف_ڪريو SD_BOTH 0x02

  تعريفنوع بنانشان صحيح گروهه_3;

#وصف_ڪريو SG_UNCONSTRAINED_گروهه 0x01
#وصف_ڪريو SG_CONSTRAINED_گروهه 0x02

  تعريفنوع بنية _WSANETWORKEVENTS {
    ڊگهو l_ڄار_Events;
    صحيح i_Error_ڪوڊ[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#جيڪڏهن_وصف_نه_ٿيل GUID_DEFINED
#ضمن <guiddef.h>
#جيڪڏهن_پورو

#وصف_ڪريو MAX_PROTOCOL_CHAIN 7

#وصف_ڪريو بنياد_PROTOCOL 1
#وصف_ڪريو LAYERED_PROTOCOL 0

  تعريفنوع بنية _WSAPROTOCOLCHAIN {
    صحيح ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#وصف_ڪريو WSAPROTOCOL_LEN 255

  تعريفنوع بنية _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_داخلا_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحيح i_نسخو;
    صحيح i_پتو_Family;
    صحيح iMaxSockAddr;
    صحيح iMinSockAddr;
    صحيح iSocketType;
    صحيح iProtocol;
    صحيح i_Protocol_Max_وٿي;
    صحيح i_ڄار_Byte_ترتيب;
    صحيح iSecurityScheme;
    DWORD dw_پيغام_سائيز;
    DWORD dwProviderReserved;
    CHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOA,*LPWSAPROTOCOL_INFOA;
  تعريفنوع بنية _WSAPROTOCOL_INFOW {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_داخلا_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحيح i_نسخو;
    صحيح i_پتو_Family;
    صحيح iMaxSockAddr;
    صحيح iMinSockAddr;
    صحيح iSocketType;
    صحيح iProtocol;
    صحيح i_Protocol_Max_وٿي;
    صحيح i_ڄار_Byte_ترتيب;
    صحيح iSecurityScheme;
    DWORD dw_پيغام_سائيز;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  تعريفنوع LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#وإلا
  تعريفنوع WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  تعريفنوع LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#جيڪڏهن_پورو

#وصف_ڪريو PFL_گڻو_PROTO_ENTRIES 0x00000001
#وصف_ڪريو PFL_RECOMMENDED_PROTO_داخلا 0x00000002
#وصف_ڪريو PFL_HIDDEN 0x00000004
#وصف_ڪريو PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#وصف_ڪريو XP1_CONNECTIONLESS 0x00000001
#وصف_ڪريو XP1_GUARANTEED_DELIVERY 0x00000002
#وصف_ڪريو XP1_GUARANTEED_ترتيب 0x00000004
#وصف_ڪريو XP1_پيغام_ORIENTED 0x00000008
#وصف_ڪريو XP1_PSEUDO_وهڪرو 0x00000010
#وصف_ڪريو XP1_GRACEFUL_CLOSE 0x00000020
#وصف_ڪريو XP1_EXPEDITED_معلومات 0x00000040
#وصف_ڪريو XP1_CONNECT_معلومات 0x00000080
#وصف_ڪريو XP1_DISCONNECT_معلومات 0x00000100
#وصف_ڪريو XP1_SUPPORT_نشر 0x00000200
#وصف_ڪريو XP1_SUPPORT_MULTIPOINT 0x00000400
#وصف_ڪريو XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#وصف_ڪريو XP1_MULTIPOINT_معلومات_PLANE 0x00001000
#وصف_ڪريو XP1_QOS_SUPPORTED 0x00002000
#وصف_ڪريو XP1_مداخلت 0x00004000
#وصف_ڪريو XP1_UNI_SEND 0x00008000
#وصف_ڪريو XP1_UNI_RECV 0x00010000
#وصف_ڪريو XP1_IFS_HANDLES 0x00020000
#وصف_ڪريو XP1_PARTIAL_پيغام 0x00040000

#وصف_ڪريو BIGENDIAN 0x0000
#وصف_ڪريو LITTLEENDIAN 0x0001

#وصف_ڪريو SECURITY_PROTOCOL_NONE 0x0000

#وصف_ڪريو JL_SENDER_ONLY 0x01
#وصف_ڪريو JL_RECEIVER_ONLY 0x02
#وصف_ڪريو JL_BOTH 0x04

#وصف_ڪريو WSA_FLAG_OVERLAPPED 0x01
#وصف_ڪريو WSA_FLAG_MULTIPOINT_C_پاڙ 0x02
#وصف_ڪريو WSA_FLAG_MULTIPOINT_C_پن 0x04
#وصف_ڪريو WSA_FLAG_MULTIPOINT_D_پاڙ 0x08
#وصف_ڪريو WSA_FLAG_MULTIPOINT_D_پن 0x10

#وصف_ڪريو IOC_UNIX 0x00000000
#وصف_ڪريو IOC_WS2 0x08000000
#وصف_ڪريو IOC_PROTOCOL 0x10000000
#وصف_ڪريو IOC_VENDOR 0x18000000

#وصف_ڪريو _WSAIO(x,y) (IOC_VOID|(x)|(y))
#وصف_ڪريو _WSAIOR(x,y) (IOC_ٻاهريون|(x)|(y))
#وصف_ڪريو _WSAIOW(x,y) (IOC_اندريون|(x)|(y))
#وصف_ڪريو _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#وصف_ڪريو SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#وصف_ڪريو SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#وصف_ڪريو SIO_ڳوليو_ROUTE _WSAIOR(IOC_WS2,3)
#وصف_ڪريو SIO_FLUSH _WSAIO(IOC_WS2,4)
#وصف_ڪريو SIO_GET_نشر_پتو _WSAIOR(IOC_WS2,5)
#وصف_ڪريو SIO_GET_EXTENSION_FUNCTION_اشارو _WSAIORW(IOC_WS2,6)
#وصف_ڪريو SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#وصف_ڪريو SIO_GET_گروهه_QOS _WSAIORW(IOC_WS2,8)
#وصف_ڪريو SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#وصف_ڪريو SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#وصف_ڪريو SIO_سيٽ_QOS _WSAIOW(IOC_WS2,11)
#وصف_ڪريو SIO_سيٽ_گروهه_QOS _WSAIOW(IOC_WS2,12)
#وصف_ڪريو SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#وصف_ڪريو SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#وصف_ڪريو SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#وصف_ڪريو SIO_پتو_LIST_QUERY _WSAIOR(IOC_WS2,22)
#وصف_ڪريو SIO_پتو_LIST_CHANGE _WSAIO(IOC_WS2,23)
#وصف_ڪريو SIO_QUERY_هدف_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#وصف_ڪريو SIO_پتو_LIST_ترتيب_ڏيو _WSAIORW(IOC_WS2,25)

  تعريفنوع صحيح (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_معلومات,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_معلومات,گروهه_3 *g,DWORD_PTR dw_Callback_معلومات);
  تعريفنوع فراغ (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#وصف_ڪريو SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  تعريفنوع تعداد _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_پورٽ,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  تعريفنوع بنية _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    اتحاد {
      بنية {
	HWND hWnd;
	UINT u_نياپو;
	WPARAM context;
      } دري_پيغام;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE h_پورٽ;
	ULONG_PTR ڪنجي_3;
      } پورٽ;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#وصف_ڪريو TH_NETDEV 0x00000001
#وصف_ڪريو TH_TAPI 0x00000002

  تعريفنوع بنية sockaddr SOCKADDR;
  تعريفنوع بنية sockaddr *PSOCKADDR;
  تعريفنوع بنية sockaddr *LPSOCKADDR;
  تعريفنوع بنية sockaddr_storage SOCKADDR_STORAGE;
  تعريفنوع بنية sockaddr_storage *PSOCKADDR_STORAGE;
  تعريفنوع بنية sockaddr_storage *LPSOCKADDR_STORAGE;

#جيڪڏهن_وصف_نه_ٿيل ٽيگ_BLOB_DEFINED
#وصف_ڪريو ٽيگ_BLOB_DEFINED
#وصف_ڪريو _BLOB_DEFINED
#وصف_ڪريو _LPBLOB_DEFINED
  تعريفنوع بنية _BLOB {
    ULONG cb_سائيز;
    BYTE *p_Blob_معلومات;
  } BLOB,*LPBLOB;
#جيڪڏهن_پورو

#وصف_ڪريو SERVICE_گڻو (0x00000001)

#وصف_ڪريو NS_ALL (0)

#وصف_ڪريو NS_SAP (1)
#وصف_ڪريو NS_NDS (2)
#وصف_ڪريو NS_PEER_BROWSE (3)
#وصف_ڪريو NS_SLP (5)
#وصف_ڪريو NS_DHCP (6)

#وصف_ڪريو NS_TCPIP_LOCAL (10)
#وصف_ڪريو NS_TCPIP_HOSTS (11)
#وصف_ڪريو NS_DNS (12)
#وصف_ڪريو NS_NETBT (13)
#وصف_ڪريو NS_WINS (14)
#وصف_ڪريو NS_NLA (15)

#وصف_ڪريو NS_NBP (20)

#وصف_ڪريو NS_MS (30)
#وصف_ڪريو NS_STDA (31)
#وصف_ڪريو NS_NTDS (32)

#وصف_ڪريو NS_X500 (40)
#وصف_ڪريو NS_NIS (41)
#وصف_ڪريو NS_NISPLUS (42)

#وصف_ڪريو NS_WRQ (50)

#وصف_ڪريو NS_NETDES (60)

#وصف_ڪريو RES_اڻ_استعمال_ٿيل_1 (0x00000001)
#وصف_ڪريو RES_FLUSH_CACHE (0x00000002)
#جيڪڏهن_وصف_نه_ٿيل RES_SERVICE
#وصف_ڪريو RES_SERVICE (0x00000004)
#جيڪڏهن_پورو

#وصف_ڪريو SERVICE_TYPE_قدر_IPXPORTA "IpxSocket"
#وصف_ڪريو SERVICE_TYPE_قدر_IPXPORTW L"IpxSocket"
#وصف_ڪريو SERVICE_TYPE_قدر_SAPIDA "SapId"
#وصف_ڪريو SERVICE_TYPE_قدر_SAPIDW L"SapId"

#وصف_ڪريو SERVICE_TYPE_قدر_TCPPORTA "TcpPort"
#وصف_ڪريو SERVICE_TYPE_قدر_TCPPORTW L"TcpPort"

#وصف_ڪريو SERVICE_TYPE_قدر_UDPPORTA "UdpPort"
#وصف_ڪريو SERVICE_TYPE_قدر_UDPPORTW L"UdpPort"

#وصف_ڪريو SERVICE_TYPE_قدر_OBJECTIDA "ObjectId"
#وصف_ڪريو SERVICE_TYPE_قدر_OBJECTIDW L"ObjectId"

#جيڪڏهن_وصف_ٿيل UNICODE

#وصف_ڪريو SERVICE_TYPE_قدر_SAPID SERVICE_TYPE_قدر_SAPIDW
#وصف_ڪريو SERVICE_TYPE_قدر_TCPPORT SERVICE_TYPE_قدر_TCPPORTW
#وصف_ڪريو SERVICE_TYPE_قدر_UDPPORT SERVICE_TYPE_قدر_UDPPORTW
#وصف_ڪريو SERVICE_TYPE_قدر_OBJECTID SERVICE_TYPE_قدر_OBJECTIDW
#وإلا

#وصف_ڪريو SERVICE_TYPE_قدر_SAPID SERVICE_TYPE_قدر_SAPIDA
#وصف_ڪريو SERVICE_TYPE_قدر_TCPPORT SERVICE_TYPE_قدر_TCPPORTA
#وصف_ڪريو SERVICE_TYPE_قدر_UDPPORT SERVICE_TYPE_قدر_UDPPORTA
#وصف_ڪريو SERVICE_TYPE_قدر_OBJECTID SERVICE_TYPE_قدر_OBJECTIDA
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __CSADDR_DEFINED__
#وصف_ڪريو __CSADDR_DEFINED__

  تعريفنوع بنية SOCKET_پتو {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_ڊيگهائي;
  } SOCKET_پتو_2,*PSOCKET_پتو,*LPSOCKET_پتو;

  تعريفنوع بنية _CSADDR_INFO {
    SOCKET_پتو_2 LocalAddr;
    SOCKET_پتو_2 RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#جيڪڏهن_پورو

  تعريفنوع بنية SOCKET_پتو_LIST {
    INT i_پتو_ڳڻپ;
    SOCKET_پتو_2 پتو_2[1];
  } SOCKET_پتو_LIST_2,*LPSOCKET_پتو_LIST;

  تعريفنوع بنية _AFPROTOCOLS {
    INT i_پتو_Family;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  تعريفنوع تعداد _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  تعريفنوع بنية _WSAVersion {
    DWORD dw_نسخو;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  تعريفنوع بنية WSAQuery_سيٽ_A {
    DWORD dw_سائيز;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخو;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_عدد_جو_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_عدد_جو_Cs_Addrs;
    LPCSADDR_INFO lpcsa_بفر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  تعريفنوع بنية WSAQuery_سيٽ_W {
    DWORD dw_سائيز;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخو;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_عدد_جو_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_عدد_جو_Cs_Addrs;
    LPCSADDR_INFO lpcsa_بفر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WSAQUERYSETW WSAQUERYSET;
  تعريفنوع PWSAQUERYSETW PWSAQUERYSET;
  تعريفنوع LPWSAQUERYSETW LPWSAQUERYSET;
#وإلا
  تعريفنوع WSAQUERYSETA WSAQUERYSET;
  تعريفنوع PWSAQUERYSETA PWSAQUERYSET;
  تعريفنوع LPWSAQUERYSETA LPWSAQUERYSET;
#جيڪڏهن_پورو

#وصف_ڪريو LUP_DEEP 0x0001
#وصف_ڪريو LUP_CONTAINERS 0x0002
#وصف_ڪريو LUP_NOCONTAINERS 0x0004
#وصف_ڪريو LUP_سڀ_کان_ويجهو 0x0008
#وصف_ڪريو LUP_RETURN_NAME 0x0010
#وصف_ڪريو LUP_RETURN_TYPE 0x0020
#وصف_ڪريو LUP_RETURN_نسخو 0x0040
#وصف_ڪريو LUP_RETURN_COMMENT 0x0080
#وصف_ڪريو LUP_RETURN_ADDR 0x0100
#وصف_ڪريو LUP_RETURN_BLOB 0x0200
#وصف_ڪريو LUP_RETURN_ALIASES 0x0400
#وصف_ڪريو LUP_RETURN_QUERY_STRING 0x0800
#وصف_ڪريو LUP_RETURN_ALL 0x0FF0
#وصف_ڪريو LUP_RES_SERVICE 0x8000

#وصف_ڪريو LUP_FLUSHCACHE 0x1000
#وصف_ڪريو LUP_FLUSHPREVIOUS 0x2000

#وصف_ڪريو نتيجو_IS_ALIAS 0x0001
#وصف_ڪريو نتيجو_IS_ADDED 0x0010
#وصف_ڪريو نتيجو_IS_بدليو 0x0020
#وصف_ڪريو نتيجو_IS_DELETED 0x0040

  تعريفنوع تعداد _WSAESETSERVICEOP {
    RNRSERVICE_رجسٽر=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  تعريفنوع بنية _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_قدر_Type;
    DWORD dw_قدر_سائيز;
    LPVOID lp_قدر;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  تعريفنوع بنية _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_قدر_Type;
    DWORD dw_قدر_سائيز;
    LPVOID lp_قدر;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WSANSCLASSINFOW WSANSCLASSINFO;
  تعريفنوع PWSANSCLASSINFOW PWSANSCLASSINFO;
  تعريفنوع LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#وإلا
  تعريفنوع WSANSCLASSINFOA WSANSCLASSINFO;
  تعريفنوع PWSANSCLASSINFOA PWSANSCLASSINFO;
  تعريفنوع LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#جيڪڏهن_پورو

  تعريفنوع بنية _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_ڳڻپ;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  تعريفنوع بنية _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_ڳڻپ;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  تعريفنوع PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  تعريفنوع LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#وإلا
  تعريفنوع WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  تعريفنوع PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  تعريفنوع LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#جيڪڏهن_پورو

  تعريفنوع بنية _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_سرگرم;
    DWORD dw_نسخو;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  تعريفنوع بنية _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_سرگرم;
    DWORD dw_نسخو;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  تعريفنوع PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  تعريفنوع LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#وإلا
  تعريفنوع WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  تعريفنوع PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  تعريفنوع LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#جيڪڏهن_پورو

#إذا INCL_WINSOCK_API_TYPEDEFS
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#وصف_ڪريو LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#وصف_ڪريو LPFN_WSASOCKET LPFN_WSASOCKETW
#وصف_ڪريو LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#وصف_ڪريو LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#وصف_ڪريو LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#وصف_ڪريو LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#وصف_ڪريو LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#وصف_ڪريو LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#وصف_ڪريو LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#وصف_ڪريو LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#وصف_ڪريو LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#وإلا
#وصف_ڪريو LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#وصف_ڪريو LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#وصف_ڪريو LPFN_WSASOCKET LPFN_WSASOCKETA
#وصف_ڪريو LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#وصف_ڪريو LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#وصف_ڪريو LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#وصف_ڪريو LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#وصف_ڪريو LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#وصف_ڪريو LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#وصف_ڪريو LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#وصف_ڪريو LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#وصف_ڪريو LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#جيڪڏهن_پورو

  تعريفنوع SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,بنية sockaddr *addr,صحيح *addrlen);
  تعريفنوع صحيح (WSAAPI *LPFN_BIND)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  تعريفنوع صحيح (WSAAPI *LPFN_CONNECT)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,ڊگهو cmd,u_long *argp);
  تعريفنوع صحيح (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,صحيح level,صحيح optname,حرف *optval,صحيح *optlen);
  تعريفنوع u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  تعريفنوع u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  تعريفنوع بنانشان ڊگهو (WSAAPI *LPFN_INET_ADDR)(ثابت حرف *cp);
  تعريفنوع حرف *(WSAAPI *LPFN_INET_NTOA)(بنية اندريون_addr اندريون);
  تعريفنوع صحيح (WSAAPI *LPFN_LISTEN)(SOCKET s,صحيح backlog);
  تعريفنوع u_long (WSAAPI *LPFN_NTOHL)(u_long netlong);
  تعريفنوع u_short (WSAAPI *LPFN_NTOHS)(u_short netshort);
  تعريفنوع صحيح (WSAAPI *LPFN_RECV)(SOCKET s,حرف *buf,صحيح len,صحيح flags);
  تعريفنوع صحيح (WSAAPI *LPFN_RECVFROM)(SOCKET s,حرف *buf,صحيح len,صحيح flags,بنية sockaddr *from,صحيح *fromlen);
  تعريفنوع صحيح (WSAAPI *LPFN_SELECT)(صحيح nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ثابت بنية timeval *timeout);
  تعريفنوع صحيح (WSAAPI *LPFN_SEND)(SOCKET s,ثابت حرف *buf,صحيح len,صحيح flags);
  تعريفنوع صحيح (WSAAPI *LPFN_SENDTO)(SOCKET s,ثابت حرف *buf,صحيح len,صحيح flags,ثابت بنية sockaddr *منزل,صحيح tolen);
  تعريفنوع صحيح (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s,صحيح level,صحيح optname,ثابت حرف *optval,صحيح optlen);
  تعريفنوع صحيح (WSAAPI *LPFN_SHUTDOWN)(SOCKET s,صحيح how);
  تعريفنوع SOCKET (WSAAPI *LPFN_SOCKET)(صحيح af,صحيح type,صحيح protocol);
  تعريفنوع بنية hostent *(WSAAPI *LPFN_GETHOSTBYADDR)(ثابت حرف *addr,صحيح len,صحيح type);
  تعريفنوع بنية hostent *(WSAAPI *LPFN_GETHOSTBYNAME)(ثابت حرف *name);
  تعريفنوع صحيح (WSAAPI *LPFN_GETHOSTNAME)(حرف *name,صحيح namelen);
  تعريفنوع بنية servent *(WSAAPI *LPFN_GETSERVBYPORT)(صحيح پورٽ_2,ثابت حرف *proto);
  تعريفنوع بنية servent *(WSAAPI *LPFN_GETSERVBYNAME)(ثابت حرف *name,ثابت حرف *proto);
  تعريفنوع بنية protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(صحيح عدد_3);
  تعريفنوع بنية protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(ثابت حرف *name);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASTARTUP)(لفظ_3 w_نسخو_Requested,LPWSADATA lpWSAData);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACLEANUP)(فراغ);
  تعريفنوع فراغ (WSAAPI *LPFN_WSASETLASTERROR)(صحيح iError);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAGETLASTERROR)(فراغ);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(فراغ);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(فراغ);
  تعريفنوع FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lp_بلاڪ_Func);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(فراغ);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_نياپو,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_نياپو,صحيح پورٽ_2,ثابت حرف *proto,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_نياپو,ثابت حرف *name,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_نياپو,صحيح عدد_3,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_نياپو,ثابت حرف *name,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_نياپو,ثابت حرف *addr,صحيح len,صحيح type,حرف *buf,صحيح buflen);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_نياپو,ڊگهو lEvent);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,بنية sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_معلومات);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACONNECT)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_معلومات,LPWSABUF lp_Callee_معلومات,LPQOS lpSQOS,LPQOS lpGQOS);
  تعريفنوع WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(فراغ);
  تعريفنوع صحيح (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  تعريفنوع صحيح (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_ڄار_Events);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_بفر,LPDWORD lpdw_بفر_ڊيگهائي);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_بفر,LPDWORD lpdw_بفر_ڊيگهائي);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,ڊگهو l_ڄار_Events);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dw_Io_Control_ڪوڊ,LPVOID lpv_اندريون_بفر,DWORD cb_اندريون_بفر,LPVOID lpv_ٻاهريون_بفر,DWORD cb_ٻاهريون_بفر,LPDWORD lpcb_بائيٽون_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_معلومات,LPWSABUF lp_Callee_معلومات,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  تعريفنوع صحيح (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  تعريفنوع صحيح (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_ڳڻپ,LPDWORD lp_عدد_جو_بائيٽون_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_معلومات);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_ڳڻپ,LPDWORD lp_عدد_جو_بائيٽون_Recvd,LPDWORD lpFlags,بنية sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_ڳڻپ,LPDWORD lp_عدد_جو_بائيٽون_موڪليل,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_معلومات);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_ڳڻپ,LPDWORD lp_عدد_جو_بائيٽون_موڪليل,DWORD dwFlags,ثابت بنية sockaddr *lp_منزل,صحيح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSASOCKETA)(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,گروهه_3 g,DWORD dwFlags);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSASOCKETW)(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,گروهه_3 g,DWORD dwFlags);
  تعريفنوع DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  تعريفنوع INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsa_پتو,DWORD dw_پتو_ڊيگهائي,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_پتو_String,LPDWORD lpdw_پتو_String_ڊيگهائي);
  تعريفنوع INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsa_پتو,DWORD dw_پتو_ڊيگهائي,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_پتو_String,LPDWORD lpdw_پتو_String_ڊيگهائي);
  تعريفنوع INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR پتو_String,INT پتو_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_پتو,LPINT lp_پتو_ڊيگهائي);
  تعريفنوع INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR پتو_String,INT پتو_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_پتو,LPINT lp_پتو_ڊيگهائي);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_ڊيگهائي,LPWSAQUERYSETA lpqsResults);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_ڊيگهائي,LPWSAQUERYSETW lpqsResults);
  تعريفنوع INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dw_Control_ڪوڊ,LPVOID lpv_اندريون_بفر,DWORD cb_اندريون_بفر,LPVOID lpv_ٻاهريون_بفر,DWORD cb_ٻاهريون_بفر,LPDWORD lpcb_بائيٽون_Returned,LPWSACOMPLETION lpCompletion);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_سائيز,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_سائيز,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_بفر_ڊيگهائي,LPWSANAMESPACE_INFOA lpnsp_بفر);
  تعريفنوع INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_بفر_ڊيگهائي,LPWSANAMESPACE_INFOW lpnsp_بفر);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_بفر_ڊيگهائي);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_بفر_ڊيگهائي);
  تعريفنوع INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  تعريفنوع INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  تعريفنوع INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو WSADuplicateSocket WSADuplicateSocketW
#وصف_ڪريو WSAEnumProtocols WSAEnumProtocolsW
#وصف_ڪريو WSAAddress_منزل_String WSAAddress_منزل_String_W
#وصف_ڪريو WSASocket WSASocketW
#وصف_ڪريو WSAString_منزل_پتو WSAString_منزل_پتو_W
#وصف_ڪريو WSALookupServiceBegin WSALookupServiceBeginW
#وصف_ڪريو WSALookup_Service_ايندڙ WSALookup_Service_ايندڙ_W
#وصف_ڪريو WSAInstallServiceClass WSAInstallServiceClassW
#وصف_ڪريو WSAGetServiceClassInfo WSAGetServiceClassInfoW
#وصف_ڪريو WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#وصف_ڪريو WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#وصف_ڪريو WSASetService WSASetServiceW
#وإلا
#وصف_ڪريو WSADuplicateSocket WSADuplicateSocketA
#وصف_ڪريو WSAEnumProtocols WSAEnumProtocolsA
#وصف_ڪريو WSASocket WSASocketA
#وصف_ڪريو WSAAddress_منزل_String WSAAddress_منزل_String_A
#وصف_ڪريو WSAString_منزل_پتو WSAString_منزل_پتو_A
#وصف_ڪريو WSALookupServiceBegin WSALookupServiceBeginA
#وصف_ڪريو WSALookup_Service_ايندڙ WSALookup_Service_ايندڙ_A
#وصف_ڪريو WSAInstallServiceClass WSAInstallServiceClassA
#وصف_ڪريو WSAGetServiceClassInfo WSAGetServiceClassInfoA
#وصف_ڪريو WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#وصف_ڪريو WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#وصف_ڪريو WSASetService WSASetServiceA
#جيڪڏهن_پورو

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,بنية sockaddr *addr,صحيح *addrlen);
  WINSOCK_API_LINKAGE صحيح WSAAPI bind(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE صحيح WSAAPI connect(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI ioctlsocket(SOCKET s,ڊگهو cmd,u_long *argp);
  WINSOCK_API_LINKAGE صحيح WSAAPI getpeername(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI getsockname(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI getsockopt(SOCKET s,صحيح level,صحيح optname,حرف *optval,صحيح *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE بنانشان ڊگهو WSAAPI inet_addr(ثابت حرف *cp);
  WINSOCK_API_LINKAGE حرف *WSAAPI inet_ntoa(بنية اندريون_addr اندريون);
  WINSOCK_API_LINKAGE صحيح WSAAPI listen(SOCKET s,صحيح backlog);
  WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI recv(SOCKET s,حرف *buf,صحيح len,صحيح flags);
  WINSOCK_API_LINKAGE صحيح WSAAPI recvfrom(SOCKET s,حرف *buf,صحيح len,صحيح flags,بنية sockaddr *from,صحيح *fromlen);
  WINSOCK_API_LINKAGE صحيح WSAAPI select(صحيح nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ثابت بنية timeval *timeout);
  WINSOCK_API_LINKAGE صحيح WSAAPI send(SOCKET s,ثابت حرف *buf,صحيح len,صحيح flags);
  WINSOCK_API_LINKAGE صحيح WSAAPI sendto(SOCKET s,ثابت حرف *buf,صحيح len,صحيح flags,ثابت بنية sockaddr *منزل,صحيح tolen);
  WINSOCK_API_LINKAGE صحيح WSAAPI setsockopt(SOCKET s,صحيح level,صحيح optname,ثابت حرف *optval,صحيح optlen);
  WINSOCK_API_LINKAGE صحيح WSAAPI shutdown(SOCKET s,صحيح how);
  WINSOCK_API_LINKAGE SOCKET WSAAPI socket(صحيح af,صحيح type,صحيح protocol);
  WINSOCK_API_LINKAGE بنية hostent *WSAAPI gethostbyaddr(ثابت حرف *addr,صحيح len,صحيح type);
  WINSOCK_API_LINKAGE بنية hostent *WSAAPI gethostbyname(ثابت حرف *name);
  WINSOCK_API_LINKAGE صحيح WSAAPI gethostname(حرف *name,صحيح namelen);
  WINSOCK_API_LINKAGE بنية servent *WSAAPI getservbyport(صحيح پورٽ_2,ثابت حرف *proto);
  WINSOCK_API_LINKAGE بنية servent *WSAAPI getservbyname(ثابت حرف *name,ثابت حرف *proto);
  WINSOCK_API_LINKAGE بنية protoent *WSAAPI getprotobynumber(صحيح عدد_3);
  WINSOCK_API_LINKAGE بنية protoent *WSAAPI getprotobyname(ثابت حرف *name);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAStartup(لفظ_3 w_نسخو_Requested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACleanup(فراغ);
  WINSOCK_API_LINKAGE فراغ WSAAPI WSASet_آخري_Error(صحيح iError);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAGet_آخري_Error(فراغ);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(فراغ);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAUnhookBlockingHook(فراغ);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lp_بلاڪ_Func);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACancelBlockingCall(فراغ);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_نياپو,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Serv_By_پورٽ(HWND hWnd,u_int w_نياپو,صحيح پورٽ_2,ثابت حرف *proto,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_نياپو,ثابت حرف *name,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_عدد(HWND hWnd,u_int w_نياپو,صحيح عدد_3,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_نياپو,ثابت حرف *name,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_نياپو,ثابت حرف *addr,صحيح len,صحيح type,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_نياپو,ڊگهو lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,بنية sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_معلومات);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAConnect(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_معلومات,LPWSABUF lp_Callee_معلومات,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(فراغ);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnum_ڄار_Events(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_ڄار_Events);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_بفر,LPDWORD lpdw_بفر_ڊيگهائي);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_بفر,LPDWORD lpdw_بفر_ڊيگهائي);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,ڊگهو l_ڄار_Events);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_نتيجو(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAIoctl(SOCKET s,DWORD dw_Io_Control_ڪوڊ,LPVOID lpv_اندريون_بفر,DWORD cb_اندريون_بفر,LPVOID lpv_ٻاهريون_بفر,DWORD cb_ٻاهريون_بفر,LPDWORD lpcb_بائيٽون_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoin_پن(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_معلومات,LPWSABUF lp_Callee_معلومات,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_ڳڻپ,LPDWORD lp_عدد_جو_بائيٽون_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_معلومات);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_ڳڻپ,LPDWORD lp_عدد_جو_بائيٽون_Recvd,LPDWORD lpFlags,بنية sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_ڳڻپ,LPDWORD lp_عدد_جو_بائيٽون_موڪليل,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_معلومات);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASend_منزل(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_ڳڻپ,LPDWORD lp_عدد_جو_بائيٽون_موڪليل,DWORD dwFlags,ثابت بنية sockaddr *lp_منزل,صحيح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,گروهه_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,گروهه_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWait_For_گڻو_Events(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_منزل_String_A(LPSOCKADDR lpsa_پتو,DWORD dw_پتو_ڊيگهائي,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_پتو_String,LPDWORD lpdw_پتو_String_ڊيگهائي);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_منزل_String_W(LPSOCKADDR lpsa_پتو,DWORD dw_پتو_ڊيگهائي,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_پتو_String,LPDWORD lpdw_پتو_String_ڊيگهائي);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_منزل_پتو_A(LPSTR پتو_String,INT پتو_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_پتو,LPINT lp_پتو_ڊيگهائي);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_منزل_پتو_W(LPWSTR پتو_String,INT پتو_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_پتو,LPINT lp_پتو_ڊيگهائي);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_ايندڙ_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_ڊيگهائي,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_ايندڙ_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_ڊيگهائي,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dw_Control_ڪوڊ,LPVOID lpv_اندريون_بفر,DWORD cb_اندريون_بفر,LPVOID lpv_ٻاهريون_بفر,DWORD cb_ٻاهريون_بفر,LPDWORD lpcb_بائيٽون_Returned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_پڇاڙي(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_سائيز,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_سائيز,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_بفر_ڊيگهائي,LPWSANAMESPACE_INFOA lpnsp_بفر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_بفر_ڊيگهائي,LPWSANAMESPACE_INFOW lpnsp_بفر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_بفر_ڊيگهائي);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_بفر_ڊيگهائي);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  تعريفنوع بنية sockaddr_اندريون SOCKADDR_اندريون;
  تعريفنوع بنية sockaddr_اندريون *PSOCKADDR_اندريون;
  تعريفنوع بنية sockaddr_اندريون *LPSOCKADDR_اندريون;

  تعريفنوع بنية linger LINGER;
  تعريفنوع بنية linger *PLINGER;
  تعريفنوع بنية linger *LPLINGER;

  تعريفنوع بنية اندريون_addr اندريون_ADDR;
  تعريفنوع بنية اندريون_addr *PIN_ADDR;
  تعريفنوع بنية اندريون_addr *LPIN_ADDR;

  تعريفنوع بنية fd_set FD_SET;
  تعريفنوع بنية fd_set *PFD_سيٽ;
  تعريفنوع بنية fd_set *LPFD_سيٽ;

  تعريفنوع بنية hostent HOSTENT;
  تعريفنوع بنية hostent *PHOSTENT;
  تعريفنوع بنية hostent *LPHOSTENT;

  تعريفنوع بنية servent SERVENT;
  تعريفنوع بنية servent *PSERVENT;
  تعريفنوع بنية servent *LPSERVENT;

  تعريفنوع بنية protoent PROTOENT;
  تعريفنوع بنية protoent *PPROTOENT;
  تعريفنوع بنية protoent *LPPROTOENT;

  تعريفنوع بنية timeval TIMEVAL;
  تعريفنوع بنية timeval *PTIMEVAL;
  تعريفنوع بنية timeval *LPTIMEVAL;

#وصف_ڪريو WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#وصف_ڪريو WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#وصف_ڪريو WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#وصف_ڪريو WSAGETASYNCERROR(lParam) HIWORD(lParam)
#وصف_ڪريو WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#وصف_ڪريو WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#وصف_ڪريو POLLRDNORM  0x0100
#وصف_ڪريو POLLRDBAND  0x0200
#وصف_ڪريو POLLIN      (POLLRDNORM | POLLRDBAND)
#وصف_ڪريو POLLPRI     0x0400

#وصف_ڪريو POLLWRNORM  0x0010
#وصف_ڪريو POLLOUT     (POLLWRNORM)
#وصف_ڪريو POLLWRBAND  0x0020

#وصف_ڪريو POLLERR     0x0001
#وصف_ڪريو POLLHUP     0x0002
#وصف_ڪريو POLLNVAL    0x0004

تعريفنوع بنية pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE صحيح WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _NEED_POPPACK
#ضمن <poppack.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل IPV6STRICT
#ضمن <wsipv6ok.h>
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WINSOCKAPI_
#وصف_ڪريو _WINSOCKAPI_
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _INC_WINSOCK_H
#ضمن <mswsock.h>
#جيڪڏهن_پورو

#جيڪڏهن_پورو
