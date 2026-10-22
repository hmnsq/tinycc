/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#که_نه_تعریف_شوی _WINSOCK2API_
#تعریف_کړه _WINSOCK2API_

#که_نه_تعریف_شوی INCL_WINSOCK_API_TYPEDEFS
#تعریف_کړه INCL_WINSOCK_API_TYPEDEFS 0
#د_که_پای

#که_نه_تعریف_شوی _INC_WINDOWS
#ضمن <windows.h>
#د_که_پای

#که_نه_تعریف_شوی MAKEWORD
#تعریف_کړه MAKEWORD(ټیټ,لوړ) ((کلمه_3)(((BYTE)(ټیټ)) | ((کلمه_3)((BYTE)(لوړ))) << 8))
#د_که_پای

#که_نه_تعریف_شوی WINSOCK_نسخه
#تعریف_کړه WINSOCK_نسخه MAKEWORD(2,2)
#د_که_پای

#که_نه_تعریف_شوی WINSOCK_API_LINKAGE
#که_تعریف_شوی DECLSPEC_IMPORT
#تعریف_کړه WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#وإلا
#تعریف_کړه WINSOCK_API_LINKAGE
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی _WINSOCK_SOCKET_DEFINED
#تعریف_کړه _WINSOCK_SOCKET_DEFINED
  تعريفنوع بینښه حرف u_char;
  تعريفنوع بینښه لنډ u_short;
  تعريفنوع بینښه صحيح u_int;
  تعريفنوع بینښه اوږد u_long;
  __MINGW_EXTENSION تعريفنوع بینښه __int64 u_int64;
  تعريفنوع INT_PTR SOCKET;
#د_که_پای

#که_نه_تعریف_شوی FD_SETSIZE
#تعریف_کړه FD_SETSIZE 64
#د_که_پای

  تعريفنوع بنية fd_set {
    u_int fd_شمېر;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  خارجي صحيح WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#تعریف_کړه FD_CLR(fd,سېټ) افعل { u_int __i; لكل(__i = 0;__i < ((fd_set *)(سېټ))->fd_شمېر;__i++) { إذا (((fd_set *)(سېټ))->fd_array[__i]==fd) { طالما (__i < ((fd_set *)(سېټ))->fd_شمېر-1) { ((fd_set *)(سېټ))->fd_array[__i] = ((fd_set *)(سېټ))->fd_array[__i+1]; __i++; } ((fd_set *)(سېټ))->fd_شمېر--; اكسر; } } } طالما(0)
#تعریف_کړه FD_SET(fd,سېټ) افعل { u_int __i; لكل(__i = 0;__i < ((fd_set *)(سېټ))->fd_شمېر;__i++) { إذا (((fd_set *)(سېټ))->fd_array[__i]==(fd)) { اكسر; } } إذا (__i==((fd_set *)(سېټ))->fd_شمېر) { إذا (((fd_set *)(سېټ))->fd_شمېر < FD_SETSIZE) { ((fd_set *)(سېټ))->fd_array[__i] = (fd); ((fd_set *)(سېټ))->fd_شمېر++; } } } طالما(0)
#تعریف_کړه FD_ZERO(سېټ) (((fd_set *)(سېټ))->fd_شمېر=0)
#تعریف_کړه FD_ISSET(fd,سېټ) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(سېټ))

#که_نه_تعریف_شوی _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کړه _TIMEVAL_DEFINED
  بنية timeval {
    اوږد tv_sec;
    اوږد tv_usec;
  };

#تعریف_کړه timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کړه timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#تعریف_کړه timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#د_که_پای /* _TIMEVAL_DEFINED */

#تعریف_کړه IOCPARM_ماسک 0x7f
#تعریف_کړه IOC_VOID 0x20000000
#تعریف_کړه IOC_بهر 0x40000000
#تعریف_کړه IOC_دننه 0x80000000
#تعریف_کړه IOC_INOUT (IOC_دننه|IOC_بهر)

#تعریف_کړه _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#تعریف_کړه _IOR(x,y,t) (IOC_بهر|(((اوږد)حجم(t)&IOCPARM_ماسک)<<16)|((x)<<8)|(y))
#تعریف_کړه _IOW(x,y,t) (IOC_دننه|(((اوږد)حجم(t)&IOCPARM_ماسک)<<16)|((x)<<8)|(y))

#تعریف_کړه FIONREAD _IOR('f',127,u_long)
#تعریف_کړه FIONBIO _IOW('f',126,u_long)
#تعریف_کړه FIOASYNC _IOW('f',125,u_long)

#تعریف_کړه SIOCSHIWAT _IOW('s',0,u_long)
#تعریف_کړه SIOCGHIWAT _IOR('s',1,u_long)
#تعریف_کړه SIOCSLOWAT _IOW('s',2,u_long)
#تعریف_کړه SIOCGLOWAT _IOR('s',3,u_long)
#تعریف_کړه SIOCATMARK _IOR('s',7,u_long)

#تعریف_کړه h_addr h_addr_list[0]

  بنية hostent {
    حرف *h_name;
    حرف **h_aliases;
    لنډ h_addrtype;
    لنډ h_اوږدتیا;
    حرف **h_addr_list;
  };

  بنية netent {
    حرف *n_name;
    حرف **n_aliases;
    لنډ n_addrtype;
    u_long n_net;
  };

  بنية servent {
    حرف *s_name;
    حرف **s_aliases;
#که_تعریف_شوی _WIN64
    حرف *s_proto;
    لنډ s_پورټ;
#وإلا
    لنډ s_پورټ;
    حرف *s_proto;
#د_که_پای
  };

  بنية protoent {
    حرف *p_name;
    حرف **p_aliases;
    لنډ p_proto;
  };

#تعریف_کړه IPPROTO_IP 0
#تعریف_کړه IPPROTO_HOPOPTS 0
#تعریف_کړه IPPROTO_ICMP 1
#تعریف_کړه IPPROTO_IGMP 2
#تعریف_کړه IPPROTO_GGP 3
#تعریف_کړه IPPROTO_IPV4 4
#تعریف_کړه IPPROTO_TCP 6
#تعریف_کړه IPPROTO_PUP 12
#تعریف_کړه IPPROTO_UDP 17
#تعریف_کړه IPPROTO_IDP 22
#تعریف_کړه IPPROTO_IPV6 41
#تعریف_کړه IPPROTO_ROUTING 43
#تعریف_کړه IPPROTO_FRAGMENT 44
#تعریف_کړه IPPROTO_ESP 50
#تعریف_کړه IPPROTO_AH 51
#تعریف_کړه IPPROTO_ICMPV6 58
#تعریف_کړه IPPROTO_NONE 59
#تعریف_کړه IPPROTO_DSTOPTS 60
#تعریف_کړه IPPROTO_ND 77
#تعریف_کړه IPPROTO_ICLFXBM 78

#تعریف_کړه IPPROTO_RAW 255
#تعریف_کړه IPPROTO_MAX 256

#تعریف_کړه IPPORT_ECHO 7
#تعریف_کړه IPPORT_DISCARD 9
#تعریف_کړه IPPORT_SYSTAT 11
#تعریف_کړه IPPORT_DAYTIME 13
#تعریف_کړه IPPORT_NETSTAT 15
#تعریف_کړه IPPORT_FTP 21
#تعریف_کړه IPPORT_TELNET 23
#تعریف_کړه IPPORT_SMTP 25
#تعریف_کړه IPPORT_TIMESERVER 37
#تعریف_کړه IPPORT_NAMESERVER 42
#تعریف_کړه IPPORT_WHOIS 43
#تعریف_کړه IPPORT_MTP 57

#تعریف_کړه IPPORT_TFTP 69
#تعریف_کړه IPPORT_RJE 77
#تعریف_کړه IPPORT_FINGER 79
#تعریف_کړه IPPORT_TTYLINK 87
#تعریف_کړه IPPORT_SUPDUP 95

#تعریف_کړه IPPORT_EXECSERVER 512
#تعریف_کړه IPPORT_LOGINSERVER 513
#تعریف_کړه IPPORT_CMDSERVER 514
#تعریف_کړه IPPORT_EFSSERVER 520

#تعریف_کړه IPPORT_BIFFUDP 512
#تعریف_کړه IPPORT_WHOSERVER 513
#تعریف_کړه IPPORT_ROUTESERVER 520

#تعریف_کړه IPPORT_RESERVED 1024

#تعریف_کړه IMPLINK_IP 155
#تعریف_کړه IMPLINK_LOWEXPER 156
#تعریف_کړه IMPLINK_HIGHEXPER 158

#که_نه_تعریف_شوی s_addr

  بنية دننه_addr {
    اتحاد {
      بنية { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      بنية { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#تعریف_کړه s_addr S_un.S_addr
#تعریف_کړه s_host S_un.S_un_b.s_b2
#تعریف_کړه s_net S_un.S_un_b.s_b1
#تعریف_کړه s_imp S_un.S_un_w.s_w2
#تعریف_کړه s_impno S_un.S_un_b.s_b4
#تعریف_کړه s_lh S_un.S_un_b.s_b3

#د_که_پای

#تعریف_کړه دننه_CLASSA(i) (((اوږد)(i) & 0x80000000)==0)
#تعریف_کړه دننه_CLASSA_NET 0xff000000
#تعریف_کړه دننه_CLASSA_NSHIFT 24
#تعریف_کړه دننه_CLASSA_HOST 0x00ffffff
#تعریف_کړه دننه_CLASSA_MAX 128

#تعریف_کړه دننه_CLASSB(i) (((اوږد)(i) & 0xc0000000)==0x80000000)
#تعریف_کړه دننه_CLASSB_NET 0xffff0000
#تعریف_کړه دننه_CLASSB_NSHIFT 16
#تعریف_کړه دننه_CLASSB_HOST 0x0000ffff
#تعریف_کړه دننه_CLASSB_MAX 65536

#تعریف_کړه دننه_CLASSC(i) (((اوږد)(i) & 0xe0000000)==0xc0000000)
#تعریف_کړه دننه_CLASSC_NET 0xffffff00
#تعریف_کړه دننه_CLASSC_NSHIFT 8
#تعریف_کړه دننه_CLASSC_HOST 0x000000ff

#تعریف_کړه دننه_CLASSD(i) (((اوږد)(i) & 0xf0000000)==0xe0000000)
#تعریف_کړه دننه_CLASSD_NET 0xf0000000
#تعریف_کړه دننه_CLASSD_NSHIFT 28
#تعریف_کړه دننه_CLASSD_HOST 0x0fffffff
#تعریف_کړه دننه_MULTICAST(i) دننه_CLASSD(i)

#تعریف_کړه INADDR_ANY (u_long)0x00000000
#تعریف_کړه INADDR_LOOPBACK 0x7f000001
#تعریف_کړه INADDR_خپرونه (u_long)0xffffffff
#تعریف_کړه INADDR_NONE 0xffffffff

#تعریف_کړه ADDR_ANY INADDR_ANY

  بنية sockaddr_دننه {
    لنډ sin_family;
    u_short sin_پورټ;
    بنية دننه_addr sin_addr;
    حرف sin_zero[8];
  };

#تعریف_کړه WSADESCRIPTION_LEN 256
#تعریف_کړه WSASYS_حالت_LEN 128

  تعريفنوع بنية WSAData {
    کلمه_3 w_نسخه;
    کلمه_3 w_لوړ_نسخه;
#که_تعریف_شوی _WIN64
    بینښه لنډ iMaxSockets;
    بینښه لنډ iMaxUdpDg;
    حرف *lpVendorInfo;
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_حالت[WSASYS_حالت_LEN+1];
#وإلا
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_حالت[WSASYS_حالت_LEN+1];
    بینښه لنډ iMaxSockets;
    بینښه لنډ iMaxUdpDg;
    حرف *lpVendorInfo;
#د_که_پای
  } WSADATA,*LPWSADATA;

#تعریف_کړه INVALID_SOCKET (SOCKET)(~0)
#تعریف_کړه SOCKET_ERROR (-1)

#تعریف_کړه FROM_PROTOCOL_INFO (-1)

#تعریف_کړه SOCK_بهیر 1
#تعریف_کړه SOCK_DGRAM 2
#تعریف_کړه SOCK_RAW 3
#تعریف_کړه SOCK_RDM 4
#تعریف_کړه SOCK_SEQPACKET 5

#تعریف_کړه SO_DEBUG 0x0001
#تعریف_کړه SO_ACCEPTCONN 0x0002
#تعریف_کړه SO_REUSEADDR 0x0004
#تعریف_کړه SO_KEEPALIVE 0x0008
#تعریف_کړه SO_DONTROUTE 0x0010
#تعریف_کړه SO_خپرونه 0x0020
#تعریف_کړه SO_USELOOPBACK 0x0040
#تعریف_کړه SO_LINGER 0x0080
#تعریف_کړه SO_OOBINLINE 0x0100

#تعریف_کړه SO_DONTLINGER (صحيح)(~SO_LINGER)
#تعریف_کړه SO_EXCLUSIVEADDRUSE ((صحيح)(~SO_REUSEADDR))

#تعریف_کړه SO_SNDBUF 0x1001
#تعریف_کړه SO_RCVBUF 0x1002
#تعریف_کړه SO_SNDLOWAT 0x1003
#تعریف_کړه SO_RCVLOWAT 0x1004
#تعریف_کړه SO_SNDTIMEO 0x1005
#تعریف_کړه SO_RCVTIMEO 0x1006
#تعریف_کړه SO_ERROR 0x1007
#تعریف_کړه SO_TYPE 0x1008

#تعریف_کړه SO_ډله_ID 0x2001
#تعریف_کړه SO_ډله_لومړیتوب 0x2002
#تعریف_کړه SO_MAX_پیغام_اندازه 0x2003
#تعریف_کړه SO_PROTOCOL_INFOA 0x2004
#تعریف_کړه SO_PROTOCOL_INFOW 0x2005
#که_تعریف_شوی UNICODE
#تعریف_کړه SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#وإلا
#تعریف_کړه SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#د_که_پای
#تعریف_کړه PVD_CONFIG 0x3001
#تعریف_کړه SO_CONDITIONAL_ACCEPT 0x3002

#تعریف_کړه TCP_NODELAY 0x0001

#تعریف_کړه AF_UNSPEC 0

#تعریف_کړه AF_UNIX 1
#تعریف_کړه AF_INET 2
#تعریف_کړه AF_IMPLINK 3
#تعریف_کړه AF_PUP 4
#تعریف_کړه AF_CHAOS 5
#تعریف_کړه AF_NS 6
#تعریف_کړه AF_IPX AF_NS
#تعریف_کړه AF_ISO 7
#تعریف_کړه AF_OSI AF_ISO
#تعریف_کړه AF_ECMA 8
#تعریف_کړه AF_DATAKIT 9
#تعریف_کړه AF_CCITT 10
#تعریف_کړه AF_SNA 11
#تعریف_کړه AF_DECnet 12
#تعریف_کړه AF_DLI 13
#تعریف_کړه AF_LAT 14
#تعریف_کړه AF_HYLINK 15
#تعریف_کړه AF_APPLETALK 16
#تعریف_کړه AF_NETBIOS 17
#تعریف_کړه AF_VOICEVIEW 18
#تعریف_کړه AF_FIREFOX 19
#تعریف_کړه AF_UNKNOWN1 20
#تعریف_کړه AF_BAN 21
#تعریف_کړه AF_ATM 22
#تعریف_کړه AF_INET6 23
#تعریف_کړه AF_CLUSTER 24
#تعریف_کړه AF_12844 25
#تعریف_کړه AF_IRDA 26
#تعریف_کړه AF_NETDES 28
#تعریف_کړه AF_TCNPROCESS 29
#تعریف_کړه AF_TCNMESSAGE 30
#تعریف_کړه AF_ICLFXBM 31

#تعریف_کړه AF_MAX 32

  بنية sockaddr {
    u_short sa_family;
    حرف sa_معلومات[14];
  };

#تعریف_کړه _SS_MAXSIZE 128
#تعریف_کړه _SS_ALIGNSIZE (8)

#تعریف_کړه SS_PAD1_اندازه (_SS_ALIGNSIZE - حجم (لنډ))
#تعریف_کړه SS_PAD2_اندازه (_SS_MAXSIZE - (حجم (لنډ) + SS_PAD1_اندازه + _SS_ALIGNSIZE))

  بنية sockaddr_storage {
    لنډ ss_family;
    حرف __ss_pad1[SS_PAD1_اندازه];

    __MINGW_EXTENSION __int64 __ss_align;
    حرف __ss_pad2[SS_PAD2_اندازه];

  };

  بنية sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#تعریف_کړه PF_UNSPEC AF_UNSPEC
#تعریف_کړه PF_UNIX AF_UNIX
#تعریف_کړه PF_INET AF_INET
#تعریف_کړه PF_IMPLINK AF_IMPLINK
#تعریف_کړه PF_PUP AF_PUP
#تعریف_کړه PF_CHAOS AF_CHAOS
#تعریف_کړه PF_NS AF_NS
#تعریف_کړه PF_IPX AF_IPX
#تعریف_کړه PF_ISO AF_ISO
#تعریف_کړه PF_OSI AF_OSI
#تعریف_کړه PF_ECMA AF_ECMA
#تعریف_کړه PF_DATAKIT AF_DATAKIT
#تعریف_کړه PF_CCITT AF_CCITT
#تعریف_کړه PF_SNA AF_SNA
#تعریف_کړه PF_DECnet AF_DECnet
#تعریف_کړه PF_DLI AF_DLI
#تعریف_کړه PF_LAT AF_LAT
#تعریف_کړه PF_HYLINK AF_HYLINK
#تعریف_کړه PF_APPLETALK AF_APPLETALK
#تعریف_کړه PF_VOICEVIEW AF_VOICEVIEW
#تعریف_کړه PF_FIREFOX AF_FIREFOX
#تعریف_کړه PF_UNKNOWN1 AF_UNKNOWN1
#تعریف_کړه PF_BAN AF_BAN
#تعریف_کړه PF_ATM AF_ATM
#تعریف_کړه PF_INET6 AF_INET6

#تعریف_کړه PF_MAX AF_MAX

  بنية linger {
    u_short l_onoff;
    u_short l_linger;
  };

#تعریف_کړه SOL_SOCKET 0xffff

#تعریف_کړه SOMAXCONN 0x7fffffff

#تعریف_کړه پیغام_OOB 0x1
#تعریف_کړه پیغام_PEEK 0x2
#تعریف_کړه پیغام_DONTROUTE 0x4
#تعریف_کړه پیغام_WAITALL 0x8

#تعریف_کړه پیغام_PARTIAL 0x8000

#تعریف_کړه پیغام_مداخله 0x10

#تعریف_کړه پیغام_MAXIOVLEN 16

#تعریف_کړه MAXGETHOSTSTRUCT 1024

#تعریف_کړه FD_READ_بټ 0
#تعریف_کړه FD_READ (1 << FD_READ_بټ)

#تعریف_کړه FD_WRITE_بټ 1
#تعریف_کړه FD_WRITE (1 << FD_WRITE_بټ)

#تعریف_کړه FD_OOB_بټ 2
#تعریف_کړه FD_OOB (1 << FD_OOB_بټ)

#تعریف_کړه FD_ACCEPT_بټ 3
#تعریف_کړه FD_ACCEPT (1 << FD_ACCEPT_بټ)

#تعریف_کړه FD_CONNECT_بټ 4
#تعریف_کړه FD_CONNECT (1 << FD_CONNECT_بټ)

#تعریف_کړه FD_CLOSE_بټ 5
#تعریف_کړه FD_CLOSE (1 << FD_CLOSE_بټ)

#تعریف_کړه FD_QOS_بټ 6
#تعریف_کړه FD_QOS (1 << FD_QOS_بټ)

#تعریف_کړه FD_ډله_QOS_بټ 7
#تعریف_کړه FD_ډله_QOS (1 << FD_ډله_QOS_بټ)

#تعریف_کړه FD_ROUTING_INTERFACE_CHANGE_بټ 8
#تعریف_کړه FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_بټ)

#تعریف_کړه FD_پته_LIST_CHANGE_بټ 9
#تعریف_کړه FD_پته_LIST_CHANGE (1 << FD_پته_LIST_CHANGE_بټ)

#تعریف_کړه FD_MAX_EVENTS 10
#تعریف_کړه FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#که_نه_تعریف_شوی WSABASEERR

#تعریف_کړه WSABASEERR 10000

#تعریف_کړه WSAEINTR (WSABASEERR+4)
#تعریف_کړه WSAEBADF (WSABASEERR+9)
#تعریف_کړه WSAEACCES (WSABASEERR+13)
#تعریف_کړه WSAEFAULT (WSABASEERR+14)
#تعریف_کړه WSAEINVAL (WSABASEERR+22)
#تعریف_کړه WSAEMFILE (WSABASEERR+24)

#تعریف_کړه WSAEWOULDBLOCK (WSABASEERR+35)
#تعریف_کړه WSAEINPROGRESS (WSABASEERR+36)
#تعریف_کړه WSAEALREADY (WSABASEERR+37)
#تعریف_کړه WSAENOTSOCK (WSABASEERR+38)
#تعریف_کړه WSAEDESTADDRREQ (WSABASEERR+39)
#تعریف_کړه WSAEMSGSIZE (WSABASEERR+40)
#تعریف_کړه WSAEPROTOTYPE (WSABASEERR+41)
#تعریف_کړه WSAENOPROTOOPT (WSABASEERR+42)
#تعریف_کړه WSAEPROTONOSUPPORT (WSABASEERR+43)
#تعریف_کړه WSAESOCKTNOSUPPORT (WSABASEERR+44)
#تعریف_کړه WSAEOPNOTSUPP (WSABASEERR+45)
#تعریف_کړه WSAEPFNOSUPPORT (WSABASEERR+46)
#تعریف_کړه WSAEAFNOSUPPORT (WSABASEERR+47)
#تعریف_کړه WSAEADDRINUSE (WSABASEERR+48)
#تعریف_کړه WSAEADDRNOTAVAIL (WSABASEERR+49)
#تعریف_کړه WSAENETDOWN (WSABASEERR+50)
#تعریف_کړه WSAENETUNREACH (WSABASEERR+51)
#تعریف_کړه WSAENETRESET (WSABASEERR+52)
#تعریف_کړه WSAECONNABORTED (WSABASEERR+53)
#تعریف_کړه WSAECONNRESET (WSABASEERR+54)
#تعریف_کړه WSAENOBUFS (WSABASEERR+55)
#تعریف_کړه WSAEISCONN (WSABASEERR+56)
#تعریف_کړه WSAENOTCONN (WSABASEERR+57)
#تعریف_کړه WSAESHUTDOWN (WSABASEERR+58)
#تعریف_کړه WSAETOOMANYREFS (WSABASEERR+59)
#تعریف_کړه WSAETIMEDOUT (WSABASEERR+60)
#تعریف_کړه WSAECONNREFUSED (WSABASEERR+61)
#تعریف_کړه WSAELOOP (WSABASEERR+62)
#تعریف_کړه WSAENAMETOOLONG (WSABASEERR+63)
#تعریف_کړه WSAEHOSTDOWN (WSABASEERR+64)
#تعریف_کړه WSAEHOSTUNREACH (WSABASEERR+65)
#تعریف_کړه WSAENOTEMPTY (WSABASEERR+66)
#تعریف_کړه WSAEPROCLIM (WSABASEERR+67)
#تعریف_کړه WSAEUSERS (WSABASEERR+68)
#تعریف_کړه WSAEDQUOT (WSABASEERR+69)
#تعریف_کړه WSAESTALE (WSABASEERR+70)
#تعریف_کړه WSAEREMOTE (WSABASEERR+71)

#تعریف_کړه WSASYSNOTREADY (WSABASEERR+91)
#تعریف_کړه WSAVERNOTSUPPORTED (WSABASEERR+92)
#تعریف_کړه WSANOTINITIALISED (WSABASEERR+93)
#تعریف_کړه WSAEDISCON (WSABASEERR+101)
#که_نه_تعریف_شوی WSAHOST_NOT_وموندل
#تعریف_کړه WSAHOST_NOT_وموندل (WSABASEERR+1001)
#د_که_پای
#که_نه_تعریف_شوی WSATRY_AGAIN
#تعریف_کړه WSATRY_AGAIN (WSABASEERR+1002)
#د_که_پای
#که_نه_تعریف_شوی WSANO_RECOVERY
#تعریف_کړه WSANO_RECOVERY (WSABASEERR+1003)
#د_که_پای
#که_نه_تعریف_شوی WSANO_معلومات
#تعریف_کړه WSANO_معلومات (WSABASEERR+1004)
#د_که_پای

#تعریف_کړه WSAENOMORE (WSABASEERR+102)
#تعریف_کړه WSAECANCELLED (WSABASEERR+103)
#تعریف_کړه WSAEINVALIDPROCTABLE (WSABASEERR+104)
#تعریف_کړه WSAEINVALIDPROVIDER (WSABASEERR+105)
#تعریف_کړه WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#تعریف_کړه WSASYSCALLFAILURE (WSABASEERR+107)
#تعریف_کړه WSASERVICE_NOT_وموندل (WSABASEERR+108)
#تعریف_کړه WSATYPE_NOT_وموندل (WSABASEERR+109)
#تعریف_کړه WSA_E_NO_نور (WSABASEERR+110)
#تعریف_کړه WSA_E_CANCELLED (WSABASEERR+111)
#تعریف_کړه WSAEREFUSED (WSABASEERR+112)
#که_نه_تعریف_شوی WSA_QOS_RECEIVERS
#تعریف_کړه WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_SENDERS
#تعریف_کړه WSA_QOS_SENDERS (WSABASEERR + 1006)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_NO_SENDERS
#تعریف_کړه WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#تعریف_کړه WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#تعریف_کړه WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#تعریف_کړه WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#تعریف_کړه WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#تعریف_کړه WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#تعریف_کړه WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#تعریف_کړه WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#تعریف_کړه WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#تعریف_کړه WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#تعریف_کړه WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#تعریف_کړه WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EFILTERSTYLE
#تعریف_کړه WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EFILTERTYPE
#تعریف_کړه WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EFILTERCOUNT
#تعریف_کړه WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EOBJLENGTH
#تعریف_کړه WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EFLOWCOUNT
#تعریف_کړه WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EUNKNOWNPSOBJ
#تعریف_کړه WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EPOLICYOBJ
#تعریف_کړه WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EFLOWDESC
#تعریف_کړه WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EPSFLOWSPEC
#تعریف_کړه WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_EPSFILTERSPEC
#تعریف_کړه WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_ESDMODEOBJ
#تعریف_کړه WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_ESHAPERATEOBJ
#تعریف_کړه WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#د_که_پای
#که_نه_تعریف_شوی WSA_QOS_RESERVED_PETYPE
#تعریف_کړه WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#د_که_پای
#د_که_پای // WSABASEERR

#تعریف_کړه h_errno WSAGet_وروستی_Error()
#تعریف_کړه HOST_NOT_وموندل WSAHOST_NOT_وموندل
#تعریف_کړه TRY_AGAIN WSATRY_AGAIN
#تعریف_کړه NO_RECOVERY WSANO_RECOVERY
#تعریف_کړه NO_معلومات WSANO_معلومات

#تعریف_کړه WSANO_پته WSANO_معلومات
#تعریف_کړه NO_پته WSANO_پته

#إذا 0
#تعریف_کړه EWOULDBLOCK WSAEWOULDBLOCK
#تعریف_کړه EINPROGRESS WSAEINPROGRESS
#تعریف_کړه EALREADY WSAEALREADY
#تعریف_کړه ENOTSOCK WSAENOTSOCK
#تعریف_کړه EDESTADDRREQ WSAEDESTADDRREQ
#تعریف_کړه EMSGSIZE WSAEMSGSIZE
#تعریف_کړه EPROTOTYPE WSAEPROTOTYPE
#تعریف_کړه ENOPROTOOPT WSAENOPROTOOPT
#تعریف_کړه EPROTONOSUPPORT WSAEPROTONOSUPPORT
#تعریف_کړه ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#تعریف_کړه EOPNOTSUPP WSAEOPNOTSUPP
#تعریف_کړه EPFNOSUPPORT WSAEPFNOSUPPORT
#تعریف_کړه EAFNOSUPPORT WSAEAFNOSUPPORT
#تعریف_کړه EADDRINUSE WSAEADDRINUSE
#تعریف_کړه EADDRNOTAVAIL WSAEADDRNOTAVAIL
#تعریف_کړه ENETDOWN WSAENETDOWN
#تعریف_کړه ENETUNREACH WSAENETUNREACH
#تعریف_کړه ENETRESET WSAENETRESET
#تعریف_کړه ECONNABORTED WSAECONNABORTED
#تعریف_کړه ECONNRESET WSAECONNRESET
#تعریف_کړه ENOBUFS WSAENOBUFS
#تعریف_کړه EISCONN WSAEISCONN
#تعریف_کړه ENOTCONN WSAENOTCONN
#تعریف_کړه ESHUTDOWN WSAESHUTDOWN
#تعریف_کړه ETOOMANYREFS WSAETOOMANYREFS
#تعریف_کړه ETIMEDOUT WSAETIMEDOUT
#تعریف_کړه ECONNREFUSED WSAECONNREFUSED
#تعریف_کړه ELOOP WSAELOOP
#تعریف_کړه ENAMETOOLONG WSAENAMETOOLONG
#تعریف_کړه EHOSTDOWN WSAEHOSTDOWN
#تعریف_کړه EHOSTUNREACH WSAEHOSTUNREACH
#تعریف_کړه ENOTEMPTY WSAENOTEMPTY
#تعریف_کړه EPROCLIM WSAEPROCLIM
#تعریف_کړه EUSERS WSAEUSERS
#تعریف_کړه EDQUOT WSAEDQUOT
#تعریف_کړه ESTALE WSAESTALE
#تعریف_کړه EREMOTE WSAEREMOTE
#د_که_پای

#تعریف_کړه WSAAPI WINAPI
#تعریف_کړه WSAEVENT HANDLE
#تعریف_کړه LPWSAEVENT LPHANDLE
#تعریف_کړه WSAOVERLAPPED OVERLAPPED
  تعريفنوع بنية _OVERLAPPED *LPWSAOVERLAPPED;

#تعریف_کړه WSA_IO_PENDING (ERROR_IO_PENDING)
#تعریف_کړه WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#تعریف_کړه WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#تعریف_کړه WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#تعریف_کړه WSA_NOT_ENOUGH_حافظه (ERROR_NOT_ENOUGH_حافظه)
#تعریف_کړه WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#تعریف_کړه WSA_INVALID_EVENT ((WSAEVENT)عدم)
#تعریف_کړه WSA_اعظمي_WAIT_EVENTS (اعظمي_WAIT_OBJECTS)
#تعریف_کړه WSA_WAIT_FAILED (WAIT_FAILED)
#تعریف_کړه WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#تعریف_کړه WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#تعریف_کړه WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#تعریف_کړه WSA_INFINITE (INFINITE)

  تعريفنوع بنية _WSABUF {
    u_long len;
    حرف *buf;
  } WSABUF,*LPWSABUF;

#ضمن <qos.h>

  تعريفنوع بنية Quality_د_Service {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#تعریف_کړه CF_ACCEPT 0x0000
#تعریف_کړه CF_REJECT 0x0001
#تعریف_کړه CF_DEFER 0x0002

#تعریف_کړه SD_RECEIVE 0x00
#تعریف_کړه SD_SEND 0x01
#تعریف_کړه SD_BOTH 0x02

  تعريفنوع بینښه صحيح ډله_3;

#تعریف_کړه SG_UNCONSTRAINED_ډله 0x01
#تعریف_کړه SG_CONSTRAINED_ډله 0x02

  تعريفنوع بنية _WSANETWORKEVENTS {
    اوږد l_شبکه_Events;
    صحيح i_Error_کوډ[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#که_نه_تعریف_شوی GUID_DEFINED
#ضمن <guiddef.h>
#د_که_پای

#تعریف_کړه MAX_PROTOCOL_CHAIN 7

#تعریف_کړه بنسټ_PROTOCOL 1
#تعریف_کړه LAYERED_PROTOCOL 0

  تعريفنوع بنية _WSAPROTOCOLCHAIN {
    صحيح ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#تعریف_کړه WSAPROTOCOL_LEN 255

  تعريفنوع بنية _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_ثبت_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحيح i_نسخه;
    صحيح i_پته_Family;
    صحيح iMaxSockAddr;
    صحيح iMinSockAddr;
    صحيح iSocketType;
    صحيح iProtocol;
    صحيح i_Protocol_Max_دننه_واټن;
    صحيح i_شبکه_Byte_ترتیب;
    صحيح iSecurityScheme;
    DWORD dw_پیغام_اندازه;
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
    DWORD dw_Catalog_ثبت_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحيح i_نسخه;
    صحيح i_پته_Family;
    صحيح iMaxSockAddr;
    صحيح iMinSockAddr;
    صحيح iSocketType;
    صحيح iProtocol;
    صحيح i_Protocol_Max_دننه_واټن;
    صحيح i_شبکه_Byte_ترتیب;
    صحيح iSecurityScheme;
    DWORD dw_پیغام_اندازه;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#که_تعریف_شوی UNICODE
  تعريفنوع WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  تعريفنوع LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#وإلا
  تعريفنوع WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  تعريفنوع LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#د_که_پای

#تعریف_کړه PFL_مضرب_PROTO_ENTRIES 0x00000001
#تعریف_کړه PFL_RECOMMENDED_PROTO_ثبت 0x00000002
#تعریف_کړه PFL_HIDDEN 0x00000004
#تعریف_کړه PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#تعریف_کړه XP1_CONNECTIONLESS 0x00000001
#تعریف_کړه XP1_GUARANTEED_DELIVERY 0x00000002
#تعریف_کړه XP1_GUARANTEED_ترتیب 0x00000004
#تعریف_کړه XP1_پیغام_ORIENTED 0x00000008
#تعریف_کړه XP1_PSEUDO_بهیر 0x00000010
#تعریف_کړه XP1_GRACEFUL_CLOSE 0x00000020
#تعریف_کړه XP1_EXPEDITED_معلومات 0x00000040
#تعریف_کړه XP1_CONNECT_معلومات 0x00000080
#تعریف_کړه XP1_DISCONNECT_معلومات 0x00000100
#تعریف_کړه XP1_SUPPORT_خپرونه 0x00000200
#تعریف_کړه XP1_SUPPORT_MULTIPOINT 0x00000400
#تعریف_کړه XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#تعریف_کړه XP1_MULTIPOINT_معلومات_PLANE 0x00001000
#تعریف_کړه XP1_QOS_SUPPORTED 0x00002000
#تعریف_کړه XP1_مداخله 0x00004000
#تعریف_کړه XP1_UNI_SEND 0x00008000
#تعریف_کړه XP1_UNI_RECV 0x00010000
#تعریف_کړه XP1_IFS_HANDLES 0x00020000
#تعریف_کړه XP1_PARTIAL_پیغام 0x00040000

#تعریف_کړه BIGENDIAN 0x0000
#تعریف_کړه LITTLEENDIAN 0x0001

#تعریف_کړه SECURITY_PROTOCOL_NONE 0x0000

#تعریف_کړه JL_SENDER_ONLY 0x01
#تعریف_کړه JL_RECEIVER_ONLY 0x02
#تعریف_کړه JL_BOTH 0x04

#تعریف_کړه WSA_FLAG_OVERLAPPED 0x01
#تعریف_کړه WSA_FLAG_MULTIPOINT_C_ریښه 0x02
#تعریف_کړه WSA_FLAG_MULTIPOINT_C_ونې_پاڼه 0x04
#تعریف_کړه WSA_FLAG_MULTIPOINT_D_ریښه 0x08
#تعریف_کړه WSA_FLAG_MULTIPOINT_D_ونې_پاڼه 0x10

#تعریف_کړه IOC_UNIX 0x00000000
#تعریف_کړه IOC_WS2 0x08000000
#تعریف_کړه IOC_PROTOCOL 0x10000000
#تعریف_کړه IOC_VENDOR 0x18000000

#تعریف_کړه _WSAIO(x,y) (IOC_VOID|(x)|(y))
#تعریف_کړه _WSAIOR(x,y) (IOC_بهر|(x)|(y))
#تعریف_کړه _WSAIOW(x,y) (IOC_دننه|(x)|(y))
#تعریف_کړه _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#تعریف_کړه SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#تعریف_کړه SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#تعریف_کړه SIO_پیدا_کړه_ROUTE _WSAIOR(IOC_WS2,3)
#تعریف_کړه SIO_FLUSH _WSAIO(IOC_WS2,4)
#تعریف_کړه SIO_GET_خپرونه_پته _WSAIOR(IOC_WS2,5)
#تعریف_کړه SIO_GET_EXTENSION_FUNCTION_اشاره_ګر _WSAIORW(IOC_WS2,6)
#تعریف_کړه SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#تعریف_کړه SIO_GET_ډله_QOS _WSAIORW(IOC_WS2,8)
#تعریف_کړه SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#تعریف_کړه SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#تعریف_کړه SIO_سېټ_QOS _WSAIOW(IOC_WS2,11)
#تعریف_کړه SIO_سېټ_ډله_QOS _WSAIOW(IOC_WS2,12)
#تعریف_کړه SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#تعریف_کړه SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#تعریف_کړه SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#تعریف_کړه SIO_پته_LIST_QUERY _WSAIOR(IOC_WS2,22)
#تعریف_کړه SIO_پته_LIST_CHANGE _WSAIO(IOC_WS2,23)
#تعریف_کړه SIO_QUERY_موخه_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#تعریف_کړه SIO_پته_LIST_ترتیبول _WSAIORW(IOC_WS2,25)

  تعريفنوع صحيح (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_معلومات,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_معلومات,ډله_3 *g,DWORD_PTR dw_Callback_معلومات);
  تعريفنوع فراغ (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#تعریف_کړه SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  تعريفنوع تعداد _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_پورټ,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  تعريفنوع بنية _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    اتحاد {
      بنية {
	HWND hWnd;
	UINT u_پیغام;
	WPARAM context;
      } کړکۍ_پیغام;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE h_پورټ;
	ULONG_PTR کلی_3;
      } پورټ;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#تعریف_کړه TH_NETDEV 0x00000001
#تعریف_کړه TH_TAPI 0x00000002

  تعريفنوع بنية sockaddr SOCKADDR;
  تعريفنوع بنية sockaddr *PSOCKADDR;
  تعريفنوع بنية sockaddr *LPSOCKADDR;
  تعريفنوع بنية sockaddr_storage SOCKADDR_STORAGE;
  تعريفنوع بنية sockaddr_storage *PSOCKADDR_STORAGE;
  تعريفنوع بنية sockaddr_storage *LPSOCKADDR_STORAGE;

#که_نه_تعریف_شوی نښان_BLOB_DEFINED
#تعریف_کړه نښان_BLOB_DEFINED
#تعریف_کړه _BLOB_DEFINED
#تعریف_کړه _LPBLOB_DEFINED
  تعريفنوع بنية _BLOB {
    ULONG cb_اندازه;
    BYTE *p_Blob_معلومات;
  } BLOB,*LPBLOB;
#د_که_پای

#تعریف_کړه SERVICE_مضرب (0x00000001)

#تعریف_کړه NS_ALL (0)

#تعریف_کړه NS_SAP (1)
#تعریف_کړه NS_NDS (2)
#تعریف_کړه NS_PEER_BROWSE (3)
#تعریف_کړه NS_SLP (5)
#تعریف_کړه NS_DHCP (6)

#تعریف_کړه NS_TCPIP_LOCAL (10)
#تعریف_کړه NS_TCPIP_HOSTS (11)
#تعریف_کړه NS_DNS (12)
#تعریف_کړه NS_NETBT (13)
#تعریف_کړه NS_WINS (14)
#تعریف_کړه NS_NLA (15)

#تعریف_کړه NS_NBP (20)

#تعریف_کړه NS_MS (30)
#تعریف_کړه NS_STDA (31)
#تعریف_کړه NS_NTDS (32)

#تعریف_کړه NS_X500 (40)
#تعریف_کړه NS_NIS (41)
#تعریف_کړه NS_NISPLUS (42)

#تعریف_کړه NS_WRQ (50)

#تعریف_کړه NS_NETDES (60)

#تعریف_کړه RES_ناکارول_شوی_1 (0x00000001)
#تعریف_کړه RES_FLUSH_CACHE (0x00000002)
#که_نه_تعریف_شوی RES_SERVICE
#تعریف_کړه RES_SERVICE (0x00000004)
#د_که_پای

#تعریف_کړه SERVICE_TYPE_ارزښت_IPXPORTA "IpxSocket"
#تعریف_کړه SERVICE_TYPE_ارزښت_IPXPORTW L"IpxSocket"
#تعریف_کړه SERVICE_TYPE_ارزښت_SAPIDA "SapId"
#تعریف_کړه SERVICE_TYPE_ارزښت_SAPIDW L"SapId"

#تعریف_کړه SERVICE_TYPE_ارزښت_TCPPORTA "TcpPort"
#تعریف_کړه SERVICE_TYPE_ارزښت_TCPPORTW L"TcpPort"

#تعریف_کړه SERVICE_TYPE_ارزښت_UDPPORTA "UdpPort"
#تعریف_کړه SERVICE_TYPE_ارزښت_UDPPORTW L"UdpPort"

#تعریف_کړه SERVICE_TYPE_ارزښت_OBJECTIDA "ObjectId"
#تعریف_کړه SERVICE_TYPE_ارزښت_OBJECTIDW L"ObjectId"

#که_تعریف_شوی UNICODE

#تعریف_کړه SERVICE_TYPE_ارزښت_SAPID SERVICE_TYPE_ارزښت_SAPIDW
#تعریف_کړه SERVICE_TYPE_ارزښت_TCPPORT SERVICE_TYPE_ارزښت_TCPPORTW
#تعریف_کړه SERVICE_TYPE_ارزښت_UDPPORT SERVICE_TYPE_ارزښت_UDPPORTW
#تعریف_کړه SERVICE_TYPE_ارزښت_OBJECTID SERVICE_TYPE_ارزښت_OBJECTIDW
#وإلا

#تعریف_کړه SERVICE_TYPE_ارزښت_SAPID SERVICE_TYPE_ارزښت_SAPIDA
#تعریف_کړه SERVICE_TYPE_ارزښت_TCPPORT SERVICE_TYPE_ارزښت_TCPPORTA
#تعریف_کړه SERVICE_TYPE_ارزښت_UDPPORT SERVICE_TYPE_ارزښت_UDPPORTA
#تعریف_کړه SERVICE_TYPE_ارزښت_OBJECTID SERVICE_TYPE_ارزښت_OBJECTIDA
#د_که_پای

#که_نه_تعریف_شوی __CSADDR_DEFINED__
#تعریف_کړه __CSADDR_DEFINED__

  تعريفنوع بنية SOCKET_پته {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_اوږدتیا;
  } SOCKET_پته_2,*PSOCKET_پته,*LPSOCKET_پته;

  تعريفنوع بنية _CSADDR_INFO {
    SOCKET_پته_2 LocalAddr;
    SOCKET_پته_2 RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#د_که_پای

  تعريفنوع بنية SOCKET_پته_LIST {
    INT i_پته_شمېر;
    SOCKET_پته_2 پته_2[1];
  } SOCKET_پته_LIST_2,*LPSOCKET_پته_LIST;

  تعريفنوع بنية _AFPROTOCOLS {
    INT i_پته_Family;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  تعريفنوع تعداد _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  تعريفنوع بنية _WSAVersion {
    DWORD dw_نسخه;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  تعريفنوع بنية WSAQuery_سېټ_A {
    DWORD dw_اندازه;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخه;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_شمېره_د_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_شمېره_د_Cs_Addrs;
    LPCSADDR_INFO lpcsa_بفر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  تعريفنوع بنية WSAQuery_سېټ_W {
    DWORD dw_اندازه;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخه;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_شمېره_د_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_شمېره_د_Cs_Addrs;
    LPCSADDR_INFO lpcsa_بفر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#که_تعریف_شوی UNICODE
  تعريفنوع WSAQUERYSETW WSAQUERYSET;
  تعريفنوع PWSAQUERYSETW PWSAQUERYSET;
  تعريفنوع LPWSAQUERYSETW LPWSAQUERYSET;
#وإلا
  تعريفنوع WSAQUERYSETA WSAQUERYSET;
  تعريفنوع PWSAQUERYSETA PWSAQUERYSET;
  تعريفنوع LPWSAQUERYSETA LPWSAQUERYSET;
#د_که_پای

#تعریف_کړه LUP_DEEP 0x0001
#تعریف_کړه LUP_CONTAINERS 0x0002
#تعریف_کړه LUP_NOCONTAINERS 0x0004
#تعریف_کړه LUP_تر_ټولو_نږدې 0x0008
#تعریف_کړه LUP_RETURN_NAME 0x0010
#تعریف_کړه LUP_RETURN_TYPE 0x0020
#تعریف_کړه LUP_RETURN_نسخه 0x0040
#تعریف_کړه LUP_RETURN_COMMENT 0x0080
#تعریف_کړه LUP_RETURN_ADDR 0x0100
#تعریف_کړه LUP_RETURN_BLOB 0x0200
#تعریف_کړه LUP_RETURN_ALIASES 0x0400
#تعریف_کړه LUP_RETURN_QUERY_STRING 0x0800
#تعریف_کړه LUP_RETURN_ALL 0x0FF0
#تعریف_کړه LUP_RES_SERVICE 0x8000

#تعریف_کړه LUP_FLUSHCACHE 0x1000
#تعریف_کړه LUP_FLUSHPREVIOUS 0x2000

#تعریف_کړه پایله_IS_ALIAS 0x0001
#تعریف_کړه پایله_IS_ADDED 0x0010
#تعریف_کړه پایله_IS_بدل_شوی 0x0020
#تعریف_کړه پایله_IS_DELETED 0x0040

  تعريفنوع تعداد _WSAESETSERVICEOP {
    RNRSERVICE_ثبتوونکی=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  تعريفنوع بنية _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_ارزښت_Type;
    DWORD dw_ارزښت_اندازه;
    LPVOID lp_ارزښت;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  تعريفنوع بنية _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_ارزښت_Type;
    DWORD dw_ارزښت_اندازه;
    LPVOID lp_ارزښت;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#که_تعریف_شوی UNICODE
  تعريفنوع WSANSCLASSINFOW WSANSCLASSINFO;
  تعريفنوع PWSANSCLASSINFOW PWSANSCLASSINFO;
  تعريفنوع LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#وإلا
  تعريفنوع WSANSCLASSINFOA WSANSCLASSINFO;
  تعريفنوع PWSANSCLASSINFOA PWSANSCLASSINFO;
  تعريفنوع LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#د_که_پای

  تعريفنوع بنية _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_شمېر;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  تعريفنوع بنية _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_شمېر;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#که_تعریف_شوی UNICODE
  تعريفنوع WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  تعريفنوع PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  تعريفنوع LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#وإلا
  تعريفنوع WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  تعريفنوع PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  تعريفنوع LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#د_که_پای

  تعريفنوع بنية _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_فعال;
    DWORD dw_نسخه;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  تعريفنوع بنية _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_فعال;
    DWORD dw_نسخه;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#که_تعریف_شوی UNICODE
  تعريفنوع WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  تعريفنوع PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  تعريفنوع LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#وإلا
  تعريفنوع WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  تعريفنوع PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  تعريفنوع LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#د_که_پای

#إذا INCL_WINSOCK_API_TYPEDEFS
#که_تعریف_شوی UNICODE
#تعریف_کړه LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#تعریف_کړه LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#تعریف_کړه LPFN_WSASOCKET LPFN_WSASOCKETW
#تعریف_کړه LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#تعریف_کړه LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#تعریف_کړه LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#تعریف_کړه LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#تعریف_کړه LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#تعریف_کړه LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#تعریف_کړه LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#تعریف_کړه LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#تعریف_کړه LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#وإلا
#تعریف_کړه LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#تعریف_کړه LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#تعریف_کړه LPFN_WSASOCKET LPFN_WSASOCKETA
#تعریف_کړه LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#تعریف_کړه LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#تعریف_کړه LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#تعریف_کړه LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#تعریف_کړه LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#تعریف_کړه LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#تعریف_کړه LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#تعریف_کړه LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#تعریف_کړه LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#د_که_پای

  تعريفنوع SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,بنية sockaddr *addr,صحيح *addrlen);
  تعريفنوع صحيح (WSAAPI *LPFN_BIND)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  تعريفنوع صحيح (WSAAPI *LPFN_CONNECT)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,اوږد cmd,u_long *argp);
  تعريفنوع صحيح (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,صحيح level,صحيح optname,حرف *optval,صحيح *optlen);
  تعريفنوع u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  تعريفنوع u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  تعريفنوع بینښه اوږد (WSAAPI *LPFN_INET_ADDR)(ثابت حرف *cp);
  تعريفنوع حرف *(WSAAPI *LPFN_INET_NTOA)(بنية دننه_addr دننه);
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
  تعريفنوع بنية servent *(WSAAPI *LPFN_GETSERVBYPORT)(صحيح پورټ_2,ثابت حرف *proto);
  تعريفنوع بنية servent *(WSAAPI *LPFN_GETSERVBYNAME)(ثابت حرف *name,ثابت حرف *proto);
  تعريفنوع بنية protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(صحيح شمېره_3);
  تعريفنوع بنية protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(ثابت حرف *name);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASTARTUP)(کلمه_3 w_نسخه_Requested,LPWSADATA lpWSAData);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACLEANUP)(فراغ);
  تعريفنوع فراغ (WSAAPI *LPFN_WSASETLASTERROR)(صحيح iError);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAGETLASTERROR)(فراغ);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(فراغ);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(فراغ);
  تعريفنوع FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lp_بلاک_Func);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(فراغ);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_پیغام,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_پیغام,صحيح پورټ_2,ثابت حرف *proto,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_پیغام,صحيح شمېره_3,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_پیغام,ثابت حرف *addr,صحيح len,صحيح type,حرف *buf,صحيح buflen);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_پیغام,اوږد lEvent);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,بنية sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_معلومات);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACONNECT)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_معلومات,LPWSABUF lp_Callee_معلومات,LPQOS lpSQOS,LPQOS lpGQOS);
  تعريفنوع WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(فراغ);
  تعريفنوع صحيح (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  تعريفنوع صحيح (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_شبکه_Events);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_بفر,LPDWORD lpdw_بفر_اوږدتیا);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_بفر,LPDWORD lpdw_بفر_اوږدتیا);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,اوږد l_شبکه_Events);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dw_Io_Control_کوډ,LPVOID lpv_دننه_بفر,DWORD cb_دننه_بفر,LPVOID lpv_بهر_بفر,DWORD cb_بهر_بفر,LPDWORD lpcb_بایټونه_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_معلومات,LPWSABUF lp_Callee_معلومات,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  تعريفنوع صحيح (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  تعريفنوع صحيح (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_شمېر,LPDWORD lp_شمېره_د_بایټونه_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_معلومات);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_شمېر,LPDWORD lp_شمېره_د_بایټونه_Recvd,LPDWORD lpFlags,بنية sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_شمېر,LPDWORD lp_شمېره_د_بایټونه_لېږل_شوی,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_معلومات);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_شمېر,LPDWORD lp_شمېره_د_بایټونه_لېږل_شوی,DWORD dwFlags,ثابت بنية sockaddr *lp_منزل,صحيح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSASOCKETA)(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,ډله_3 g,DWORD dwFlags);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSASOCKETW)(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,ډله_3 g,DWORD dwFlags);
  تعريفنوع DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  تعريفنوع INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsa_پته,DWORD dw_پته_اوږدتیا,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_پته_String,LPDWORD lpdw_پته_String_اوږدتیا);
  تعريفنوع INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsa_پته,DWORD dw_پته_اوږدتیا,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_پته_String,LPDWORD lpdw_پته_String_اوږدتیا);
  تعريفنوع INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR پته_String,INT پته_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_پته,LPINT lp_پته_اوږدتیا);
  تعريفنوع INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR پته_String,INT پته_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_پته,LPINT lp_پته_اوږدتیا);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_اوږدتیا,LPWSAQUERYSETA lpqsResults);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_اوږدتیا,LPWSAQUERYSETW lpqsResults);
  تعريفنوع INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dw_Control_کوډ,LPVOID lpv_دننه_بفر,DWORD cb_دننه_بفر,LPVOID lpv_بهر_بفر,DWORD cb_بهر_بفر,LPDWORD lpcb_بایټونه_Returned,LPWSACOMPLETION lpCompletion);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_اندازه,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_اندازه,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_بفر_اوږدتیا,LPWSANAMESPACE_INFOA lpnsp_بفر);
  تعريفنوع INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_بفر_اوږدتیا,LPWSANAMESPACE_INFOW lpnsp_بفر);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_بفر_اوږدتیا);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_بفر_اوږدتیا);
  تعريفنوع INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  تعريفنوع INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  تعريفنوع INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه WSADuplicateSocket WSADuplicateSocketW
#تعریف_کړه WSAEnumProtocols WSAEnumProtocolsW
#تعریف_کړه WSAAddress_منزل_String WSAAddress_منزل_String_W
#تعریف_کړه WSASocket WSASocketW
#تعریف_کړه WSAString_منزل_پته WSAString_منزل_پته_W
#تعریف_کړه WSALookupServiceBegin WSALookupServiceBeginW
#تعریف_کړه WSALookup_Service_بل WSALookup_Service_بل_W
#تعریف_کړه WSAInstallServiceClass WSAInstallServiceClassW
#تعریف_کړه WSAGetServiceClassInfo WSAGetServiceClassInfoW
#تعریف_کړه WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#تعریف_کړه WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#تعریف_کړه WSASetService WSASetServiceW
#وإلا
#تعریف_کړه WSADuplicateSocket WSADuplicateSocketA
#تعریف_کړه WSAEnumProtocols WSAEnumProtocolsA
#تعریف_کړه WSASocket WSASocketA
#تعریف_کړه WSAAddress_منزل_String WSAAddress_منزل_String_A
#تعریف_کړه WSAString_منزل_پته WSAString_منزل_پته_A
#تعریف_کړه WSALookupServiceBegin WSALookupServiceBeginA
#تعریف_کړه WSALookup_Service_بل WSALookup_Service_بل_A
#تعریف_کړه WSAInstallServiceClass WSAInstallServiceClassA
#تعریف_کړه WSAGetServiceClassInfo WSAGetServiceClassInfoA
#تعریف_کړه WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#تعریف_کړه WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#تعریف_کړه WSASetService WSASetServiceA
#د_که_پای

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,بنية sockaddr *addr,صحيح *addrlen);
  WINSOCK_API_LINKAGE صحيح WSAAPI bind(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE صحيح WSAAPI connect(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI ioctlsocket(SOCKET s,اوږد cmd,u_long *argp);
  WINSOCK_API_LINKAGE صحيح WSAAPI getpeername(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI getsockname(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI getsockopt(SOCKET s,صحيح level,صحيح optname,حرف *optval,صحيح *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE بینښه اوږد WSAAPI inet_addr(ثابت حرف *cp);
  WINSOCK_API_LINKAGE حرف *WSAAPI inet_ntoa(بنية دننه_addr دننه);
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
  WINSOCK_API_LINKAGE بنية servent *WSAAPI getservbyport(صحيح پورټ_2,ثابت حرف *proto);
  WINSOCK_API_LINKAGE بنية servent *WSAAPI getservbyname(ثابت حرف *name,ثابت حرف *proto);
  WINSOCK_API_LINKAGE بنية protoent *WSAAPI getprotobynumber(صحيح شمېره_3);
  WINSOCK_API_LINKAGE بنية protoent *WSAAPI getprotobyname(ثابت حرف *name);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAStartup(کلمه_3 w_نسخه_Requested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACleanup(فراغ);
  WINSOCK_API_LINKAGE فراغ WSAAPI WSASet_وروستی_Error(صحيح iError);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAGet_وروستی_Error(فراغ);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(فراغ);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAUnhookBlockingHook(فراغ);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lp_بلاک_Func);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACancelBlockingCall(فراغ);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_پیغام,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Serv_By_پورټ(HWND hWnd,u_int w_پیغام,صحيح پورټ_2,ثابت حرف *proto,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_شمېره(HWND hWnd,u_int w_پیغام,صحيح شمېره_3,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_پیغام,ثابت حرف *addr,صحيح len,صحيح type,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_پیغام,اوږد lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,بنية sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_معلومات);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAConnect(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_معلومات,LPWSABUF lp_Callee_معلومات,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(فراغ);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnum_شبکه_Events(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_شبکه_Events);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_بفر,LPDWORD lpdw_بفر_اوږدتیا);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_بفر,LPDWORD lpdw_بفر_اوږدتیا);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,اوږد l_شبکه_Events);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_پایله(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAIoctl(SOCKET s,DWORD dw_Io_Control_کوډ,LPVOID lpv_دننه_بفر,DWORD cb_دننه_بفر,LPVOID lpv_بهر_بفر,DWORD cb_بهر_بفر,LPDWORD lpcb_بایټونه_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoin_ونې_پاڼه(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_معلومات,LPWSABUF lp_Callee_معلومات,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_شمېر,LPDWORD lp_شمېره_د_بایټونه_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_معلومات);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_شمېر,LPDWORD lp_شمېره_د_بایټونه_Recvd,LPDWORD lpFlags,بنية sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_شمېر,LPDWORD lp_شمېره_د_بایټونه_لېږل_شوی,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_معلومات);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASend_منزل(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_شمېر,LPDWORD lp_شمېره_د_بایټونه_لېږل_شوی,DWORD dwFlags,ثابت بنية sockaddr *lp_منزل,صحيح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,ډله_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,ډله_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWait_For_مضرب_Events(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_منزل_String_A(LPSOCKADDR lpsa_پته,DWORD dw_پته_اوږدتیا,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_پته_String,LPDWORD lpdw_پته_String_اوږدتیا);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_منزل_String_W(LPSOCKADDR lpsa_پته,DWORD dw_پته_اوږدتیا,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_پته_String,LPDWORD lpdw_پته_String_اوږدتیا);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_منزل_پته_A(LPSTR پته_String,INT پته_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_پته,LPINT lp_پته_اوږدتیا);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_منزل_پته_W(LPWSTR پته_String,INT پته_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_پته,LPINT lp_پته_اوږدتیا);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_بل_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_اوږدتیا,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_بل_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_اوږدتیا,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dw_Control_کوډ,LPVOID lpv_دننه_بفر,DWORD cb_دننه_بفر,LPVOID lpv_بهر_بفر,DWORD cb_بهر_بفر,LPDWORD lpcb_بایټونه_Returned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_پای_ټکی(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_اندازه,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_اندازه,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_بفر_اوږدتیا,LPWSANAMESPACE_INFOA lpnsp_بفر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_بفر_اوږدتیا,LPWSANAMESPACE_INFOW lpnsp_بفر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_بفر_اوږدتیا);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_بفر_اوږدتیا);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  تعريفنوع بنية sockaddr_دننه SOCKADDR_دننه;
  تعريفنوع بنية sockaddr_دننه *PSOCKADDR_دننه;
  تعريفنوع بنية sockaddr_دننه *LPSOCKADDR_دننه;

  تعريفنوع بنية linger LINGER;
  تعريفنوع بنية linger *PLINGER;
  تعريفنوع بنية linger *LPLINGER;

  تعريفنوع بنية دننه_addr دننه_ADDR;
  تعريفنوع بنية دننه_addr *PIN_ADDR;
  تعريفنوع بنية دننه_addr *LPIN_ADDR;

  تعريفنوع بنية fd_set FD_SET;
  تعريفنوع بنية fd_set *PFD_سېټ;
  تعريفنوع بنية fd_set *LPFD_سېټ;

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

#تعریف_کړه WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#تعریف_کړه WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#تعریف_کړه WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#تعریف_کړه WSAGETASYNCERROR(lParam) HIWORD(lParam)
#تعریف_کړه WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#تعریف_کړه WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#تعریف_کړه POLLRDNORM  0x0100
#تعریف_کړه POLLRDBAND  0x0200
#تعریف_کړه POLLIN      (POLLRDNORM | POLLRDBAND)
#تعریف_کړه POLLPRI     0x0400

#تعریف_کړه POLLWRNORM  0x0010
#تعریف_کړه POLLOUT     (POLLWRNORM)
#تعریف_کړه POLLWRBAND  0x0020

#تعریف_کړه POLLERR     0x0001
#تعریف_کړه POLLHUP     0x0002
#تعریف_کړه POLLNVAL    0x0004

تعريفنوع بنية pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE صحيح WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#که_تعریف_شوی _NEED_POPPACK
#ضمن <poppack.h>
#د_که_پای

#که_تعریف_شوی IPV6STRICT
#ضمن <wsipv6ok.h>
#د_که_پای

#که_نه_تعریف_شوی _WINSOCKAPI_
#تعریف_کړه _WINSOCKAPI_
#د_که_پای

#که_تعریف_شوی _INC_WINSOCK_H
#ضمن <mswsock.h>
#د_که_پای

#د_که_پای
