/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_تعریف_نشده _WINSOCK2API_
#تعریف_کن _WINSOCK2API_

#اگر_تعریف_نشده INCL_WINSOCK_API_TYPEDEFS
#تعریف_کن INCL_WINSOCK_API_TYPEDEFS 0
#پایان_اگر

#اگر_تعریف_نشده _INC_WINDOWS
#ضمن <windows.h>
#پایان_اگر

#اگر_تعریف_نشده MAKEWORD
#تعریف_کن MAKEWORD(کم,بالا) ((کلمه_3)(((BYTE)(کم)) | ((کلمه_3)((BYTE)(بالا))) << 8))
#پایان_اگر

#اگر_تعریف_نشده WINSOCK_نسخه
#تعریف_کن WINSOCK_نسخه MAKEWORD(2,2)
#پایان_اگر

#اگر_تعریف_نشده WINSOCK_API_LINKAGE
#اگر_تعریف_شده DECLSPEC_IMPORT
#تعریف_کن WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#وإلا
#تعریف_کن WINSOCK_API_LINKAGE
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده _WINSOCK_SOCKET_DEFINED
#تعریف_کن _WINSOCK_SOCKET_DEFINED
  تعريفنوع بیعلامت حرف u_char;
  تعريفنوع بیعلامت کوتاه u_short;
  تعريفنوع بیعلامت صحيح u_int;
  تعريفنوع بیعلامت دراز u_long;
  __MINGW_EXTENSION تعريفنوع بیعلامت __int64 u_int64;
  تعريفنوع INT_PTR SOCKET;
#پایان_اگر

#اگر_تعریف_نشده FD_SETSIZE
#تعریف_کن FD_SETSIZE 64
#پایان_اگر

  تعريفنوع بنية fd_set {
    u_int fd_شمار;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  خارجي صحيح WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#تعریف_کن FD_CLR(fd,مجموعه) افعل { u_int __i; لكل(__i = 0;__i < ((fd_set *)(مجموعه))->fd_شمار;__i++) { إذا (((fd_set *)(مجموعه))->fd_array[__i]==fd) { طالما (__i < ((fd_set *)(مجموعه))->fd_شمار-1) { ((fd_set *)(مجموعه))->fd_array[__i] = ((fd_set *)(مجموعه))->fd_array[__i+1]; __i++; } ((fd_set *)(مجموعه))->fd_شمار--; اكسر; } } } طالما(0)
#تعریف_کن FD_SET(fd,مجموعه) افعل { u_int __i; لكل(__i = 0;__i < ((fd_set *)(مجموعه))->fd_شمار;__i++) { إذا (((fd_set *)(مجموعه))->fd_array[__i]==(fd)) { اكسر; } } إذا (__i==((fd_set *)(مجموعه))->fd_شمار) { إذا (((fd_set *)(مجموعه))->fd_شمار < FD_SETSIZE) { ((fd_set *)(مجموعه))->fd_array[__i] = (fd); ((fd_set *)(مجموعه))->fd_شمار++; } } } طالما(0)
#تعریف_کن FD_ZERO(مجموعه) (((fd_set *)(مجموعه))->fd_شمار=0)
#تعریف_کن FD_ISSET(fd,مجموعه) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(مجموعه))

#اگر_تعریف_نشده _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کن _TIMEVAL_DEFINED
  بنية timeval {
    دراز tv_sec;
    دراز tv_usec;
  };

#تعریف_کن timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کن timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#تعریف_کن timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#پایان_اگر /* _TIMEVAL_DEFINED */

#تعریف_کن IOCPARM_ماسک 0x7f
#تعریف_کن IOC_VOID 0x20000000
#تعریف_کن IOC_بیرون 0x40000000
#تعریف_کن IOC_درون 0x80000000
#تعریف_کن IOC_INOUT (IOC_درون|IOC_بیرون)

#تعریف_کن _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#تعریف_کن _IOR(x,y,t) (IOC_بیرون|(((دراز)حجم(t)&IOCPARM_ماسک)<<16)|((x)<<8)|(y))
#تعریف_کن _IOW(x,y,t) (IOC_درون|(((دراز)حجم(t)&IOCPARM_ماسک)<<16)|((x)<<8)|(y))

#تعریف_کن FIONREAD _IOR('f',127,u_long)
#تعریف_کن FIONBIO _IOW('f',126,u_long)
#تعریف_کن FIOASYNC _IOW('f',125,u_long)

#تعریف_کن SIOCSHIWAT _IOW('s',0,u_long)
#تعریف_کن SIOCGHIWAT _IOR('s',1,u_long)
#تعریف_کن SIOCSLOWAT _IOW('s',2,u_long)
#تعریف_کن SIOCGLOWAT _IOR('s',3,u_long)
#تعریف_کن SIOCATMARK _IOR('s',7,u_long)

#تعریف_کن h_addr h_addr_list[0]

  بنية hostent {
    حرف *h_name;
    حرف **h_aliases;
    کوتاه h_addrtype;
    کوتاه h_درازی;
    حرف **h_addr_list;
  };

  بنية netent {
    حرف *n_name;
    حرف **n_aliases;
    کوتاه n_addrtype;
    u_long n_net;
  };

  بنية servent {
    حرف *s_name;
    حرف **s_aliases;
#اگر_تعریف_شده _WIN64
    حرف *s_proto;
    کوتاه s_پورت;
#وإلا
    کوتاه s_پورت;
    حرف *s_proto;
#پایان_اگر
  };

  بنية protoent {
    حرف *p_name;
    حرف **p_aliases;
    کوتاه p_proto;
  };

#تعریف_کن IPPROTO_IP 0
#تعریف_کن IPPROTO_HOPOPTS 0
#تعریف_کن IPPROTO_ICMP 1
#تعریف_کن IPPROTO_IGMP 2
#تعریف_کن IPPROTO_GGP 3
#تعریف_کن IPPROTO_IPV4 4
#تعریف_کن IPPROTO_TCP 6
#تعریف_کن IPPROTO_PUP 12
#تعریف_کن IPPROTO_UDP 17
#تعریف_کن IPPROTO_IDP 22
#تعریف_کن IPPROTO_IPV6 41
#تعریف_کن IPPROTO_ROUTING 43
#تعریف_کن IPPROTO_FRAGMENT 44
#تعریف_کن IPPROTO_ESP 50
#تعریف_کن IPPROTO_AH 51
#تعریف_کن IPPROTO_ICMPV6 58
#تعریف_کن IPPROTO_NONE 59
#تعریف_کن IPPROTO_DSTOPTS 60
#تعریف_کن IPPROTO_ND 77
#تعریف_کن IPPROTO_ICLFXBM 78

#تعریف_کن IPPROTO_RAW 255
#تعریف_کن IPPROTO_MAX 256

#تعریف_کن IPPORT_ECHO 7
#تعریف_کن IPPORT_DISCARD 9
#تعریف_کن IPPORT_SYSTAT 11
#تعریف_کن IPPORT_DAYTIME 13
#تعریف_کن IPPORT_NETSTAT 15
#تعریف_کن IPPORT_FTP 21
#تعریف_کن IPPORT_TELNET 23
#تعریف_کن IPPORT_SMTP 25
#تعریف_کن IPPORT_TIMESERVER 37
#تعریف_کن IPPORT_NAMESERVER 42
#تعریف_کن IPPORT_WHOIS 43
#تعریف_کن IPPORT_MTP 57

#تعریف_کن IPPORT_TFTP 69
#تعریف_کن IPPORT_RJE 77
#تعریف_کن IPPORT_FINGER 79
#تعریف_کن IPPORT_TTYLINK 87
#تعریف_کن IPPORT_SUPDUP 95

#تعریف_کن IPPORT_EXECSERVER 512
#تعریف_کن IPPORT_LOGINSERVER 513
#تعریف_کن IPPORT_CMDSERVER 514
#تعریف_کن IPPORT_EFSSERVER 520

#تعریف_کن IPPORT_BIFFUDP 512
#تعریف_کن IPPORT_WHOSERVER 513
#تعریف_کن IPPORT_ROUTESERVER 520

#تعریف_کن IPPORT_RESERVED 1024

#تعریف_کن IMPLINK_IP 155
#تعریف_کن IMPLINK_LOWEXPER 156
#تعریف_کن IMPLINK_HIGHEXPER 158

#اگر_تعریف_نشده s_addr

  بنية درون_addr {
    اتحاد {
      بنية { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      بنية { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#تعریف_کن s_addr S_un.S_addr
#تعریف_کن s_host S_un.S_un_b.s_b2
#تعریف_کن s_net S_un.S_un_b.s_b1
#تعریف_کن s_imp S_un.S_un_w.s_w2
#تعریف_کن s_impno S_un.S_un_b.s_b4
#تعریف_کن s_lh S_un.S_un_b.s_b3

#پایان_اگر

#تعریف_کن درون_CLASSA(i) (((دراز)(i) & 0x80000000)==0)
#تعریف_کن درون_CLASSA_NET 0xff000000
#تعریف_کن درون_CLASSA_NSHIFT 24
#تعریف_کن درون_CLASSA_HOST 0x00ffffff
#تعریف_کن درون_CLASSA_MAX 128

#تعریف_کن درون_CLASSB(i) (((دراز)(i) & 0xc0000000)==0x80000000)
#تعریف_کن درون_CLASSB_NET 0xffff0000
#تعریف_کن درون_CLASSB_NSHIFT 16
#تعریف_کن درون_CLASSB_HOST 0x0000ffff
#تعریف_کن درون_CLASSB_MAX 65536

#تعریف_کن درون_CLASSC(i) (((دراز)(i) & 0xe0000000)==0xc0000000)
#تعریف_کن درون_CLASSC_NET 0xffffff00
#تعریف_کن درون_CLASSC_NSHIFT 8
#تعریف_کن درون_CLASSC_HOST 0x000000ff

#تعریف_کن درون_CLASSD(i) (((دراز)(i) & 0xf0000000)==0xe0000000)
#تعریف_کن درون_CLASSD_NET 0xf0000000
#تعریف_کن درون_CLASSD_NSHIFT 28
#تعریف_کن درون_CLASSD_HOST 0x0fffffff
#تعریف_کن درون_MULTICAST(i) درون_CLASSD(i)

#تعریف_کن INADDR_ANY (u_long)0x00000000
#تعریف_کن INADDR_LOOPBACK 0x7f000001
#تعریف_کن INADDR_پخش (u_long)0xffffffff
#تعریف_کن INADDR_NONE 0xffffffff

#تعریف_کن ADDR_ANY INADDR_ANY

  بنية sockaddr_درون {
    کوتاه sin_family;
    u_short sin_پورت;
    بنية درون_addr sin_addr;
    حرف sin_zero[8];
  };

#تعریف_کن WSADESCRIPTION_LEN 256
#تعریف_کن WSASYS_وضعیت_LEN 128

  تعريفنوع بنية WSAData {
    کلمه_3 w_نسخه;
    کلمه_3 w_بالا_نسخه;
#اگر_تعریف_شده _WIN64
    بیعلامت کوتاه iMaxSockets;
    بیعلامت کوتاه iMaxUdpDg;
    حرف *lpVendorInfo;
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_وضعیت[WSASYS_وضعیت_LEN+1];
#وإلا
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_وضعیت[WSASYS_وضعیت_LEN+1];
    بیعلامت کوتاه iMaxSockets;
    بیعلامت کوتاه iMaxUdpDg;
    حرف *lpVendorInfo;
#پایان_اگر
  } WSADATA,*LPWSADATA;

#تعریف_کن INVALID_SOCKET (SOCKET)(~0)
#تعریف_کن SOCKET_ERROR (-1)

#تعریف_کن FROM_PROTOCOL_INFO (-1)

#تعریف_کن SOCK_جریان 1
#تعریف_کن SOCK_DGRAM 2
#تعریف_کن SOCK_RAW 3
#تعریف_کن SOCK_RDM 4
#تعریف_کن SOCK_SEQPACKET 5

#تعریف_کن SO_DEBUG 0x0001
#تعریف_کن SO_ACCEPTCONN 0x0002
#تعریف_کن SO_REUSEADDR 0x0004
#تعریف_کن SO_KEEPALIVE 0x0008
#تعریف_کن SO_DONTROUTE 0x0010
#تعریف_کن SO_پخش 0x0020
#تعریف_کن SO_USELOOPBACK 0x0040
#تعریف_کن SO_LINGER 0x0080
#تعریف_کن SO_OOBINLINE 0x0100

#تعریف_کن SO_DONTLINGER (صحيح)(~SO_LINGER)
#تعریف_کن SO_EXCLUSIVEADDRUSE ((صحيح)(~SO_REUSEADDR))

#تعریف_کن SO_SNDBUF 0x1001
#تعریف_کن SO_RCVBUF 0x1002
#تعریف_کن SO_SNDLOWAT 0x1003
#تعریف_کن SO_RCVLOWAT 0x1004
#تعریف_کن SO_SNDTIMEO 0x1005
#تعریف_کن SO_RCVTIMEO 0x1006
#تعریف_کن SO_ERROR 0x1007
#تعریف_کن SO_TYPE 0x1008

#تعریف_کن SO_گروه_ID 0x2001
#تعریف_کن SO_گروه_اولویت 0x2002
#تعریف_کن SO_MAX_پیام_اندازه 0x2003
#تعریف_کن SO_PROTOCOL_INFOA 0x2004
#تعریف_کن SO_PROTOCOL_INFOW 0x2005
#اگر_تعریف_شده UNICODE
#تعریف_کن SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#وإلا
#تعریف_کن SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#پایان_اگر
#تعریف_کن PVD_CONFIG 0x3001
#تعریف_کن SO_CONDITIONAL_ACCEPT 0x3002

#تعریف_کن TCP_NODELAY 0x0001

#تعریف_کن AF_UNSPEC 0

#تعریف_کن AF_UNIX 1
#تعریف_کن AF_INET 2
#تعریف_کن AF_IMPLINK 3
#تعریف_کن AF_PUP 4
#تعریف_کن AF_CHAOS 5
#تعریف_کن AF_NS 6
#تعریف_کن AF_IPX AF_NS
#تعریف_کن AF_ISO 7
#تعریف_کن AF_OSI AF_ISO
#تعریف_کن AF_ECMA 8
#تعریف_کن AF_DATAKIT 9
#تعریف_کن AF_CCITT 10
#تعریف_کن AF_SNA 11
#تعریف_کن AF_DECnet 12
#تعریف_کن AF_DLI 13
#تعریف_کن AF_LAT 14
#تعریف_کن AF_HYLINK 15
#تعریف_کن AF_APPLETALK 16
#تعریف_کن AF_NETBIOS 17
#تعریف_کن AF_VOICEVIEW 18
#تعریف_کن AF_FIREFOX 19
#تعریف_کن AF_UNKNOWN1 20
#تعریف_کن AF_BAN 21
#تعریف_کن AF_ATM 22
#تعریف_کن AF_INET6 23
#تعریف_کن AF_CLUSTER 24
#تعریف_کن AF_12844 25
#تعریف_کن AF_IRDA 26
#تعریف_کن AF_NETDES 28
#تعریف_کن AF_TCNPROCESS 29
#تعریف_کن AF_TCNMESSAGE 30
#تعریف_کن AF_ICLFXBM 31

#تعریف_کن AF_MAX 32

  بنية sockaddr {
    u_short sa_family;
    حرف sa_داده[14];
  };

#تعریف_کن _SS_MAXSIZE 128
#تعریف_کن _SS_ALIGNSIZE (8)

#تعریف_کن SS_PAD1_اندازه (_SS_ALIGNSIZE - حجم (کوتاه))
#تعریف_کن SS_PAD2_اندازه (_SS_MAXSIZE - (حجم (کوتاه) + SS_PAD1_اندازه + _SS_ALIGNSIZE))

  بنية sockaddr_storage {
    کوتاه ss_family;
    حرف __ss_pad1[SS_PAD1_اندازه];

    __MINGW_EXTENSION __int64 __ss_align;
    حرف __ss_pad2[SS_PAD2_اندازه];

  };

  بنية sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#تعریف_کن PF_UNSPEC AF_UNSPEC
#تعریف_کن PF_UNIX AF_UNIX
#تعریف_کن PF_INET AF_INET
#تعریف_کن PF_IMPLINK AF_IMPLINK
#تعریف_کن PF_PUP AF_PUP
#تعریف_کن PF_CHAOS AF_CHAOS
#تعریف_کن PF_NS AF_NS
#تعریف_کن PF_IPX AF_IPX
#تعریف_کن PF_ISO AF_ISO
#تعریف_کن PF_OSI AF_OSI
#تعریف_کن PF_ECMA AF_ECMA
#تعریف_کن PF_DATAKIT AF_DATAKIT
#تعریف_کن PF_CCITT AF_CCITT
#تعریف_کن PF_SNA AF_SNA
#تعریف_کن PF_DECnet AF_DECnet
#تعریف_کن PF_DLI AF_DLI
#تعریف_کن PF_LAT AF_LAT
#تعریف_کن PF_HYLINK AF_HYLINK
#تعریف_کن PF_APPLETALK AF_APPLETALK
#تعریف_کن PF_VOICEVIEW AF_VOICEVIEW
#تعریف_کن PF_FIREFOX AF_FIREFOX
#تعریف_کن PF_UNKNOWN1 AF_UNKNOWN1
#تعریف_کن PF_BAN AF_BAN
#تعریف_کن PF_ATM AF_ATM
#تعریف_کن PF_INET6 AF_INET6

#تعریف_کن PF_MAX AF_MAX

  بنية linger {
    u_short l_onoff;
    u_short l_linger;
  };

#تعریف_کن SOL_SOCKET 0xffff

#تعریف_کن SOMAXCONN 0x7fffffff

#تعریف_کن پیام_OOB 0x1
#تعریف_کن پیام_PEEK 0x2
#تعریف_کن پیام_DONTROUTE 0x4
#تعریف_کن پیام_WAITALL 0x8

#تعریف_کن پیام_PARTIAL 0x8000

#تعریف_کن پیام_وقفه 0x10

#تعریف_کن پیام_MAXIOVLEN 16

#تعریف_کن MAXGETHOSTSTRUCT 1024

#تعریف_کن FD_READ_بیت 0
#تعریف_کن FD_READ (1 << FD_READ_بیت)

#تعریف_کن FD_WRITE_بیت 1
#تعریف_کن FD_WRITE (1 << FD_WRITE_بیت)

#تعریف_کن FD_OOB_بیت 2
#تعریف_کن FD_OOB (1 << FD_OOB_بیت)

#تعریف_کن FD_ACCEPT_بیت 3
#تعریف_کن FD_ACCEPT (1 << FD_ACCEPT_بیت)

#تعریف_کن FD_CONNECT_بیت 4
#تعریف_کن FD_CONNECT (1 << FD_CONNECT_بیت)

#تعریف_کن FD_CLOSE_بیت 5
#تعریف_کن FD_CLOSE (1 << FD_CLOSE_بیت)

#تعریف_کن FD_QOS_بیت 6
#تعریف_کن FD_QOS (1 << FD_QOS_بیت)

#تعریف_کن FD_گروه_QOS_بیت 7
#تعریف_کن FD_گروه_QOS (1 << FD_گروه_QOS_بیت)

#تعریف_کن FD_ROUTING_INTERFACE_CHANGE_بیت 8
#تعریف_کن FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_بیت)

#تعریف_کن FD_آدرس_LIST_CHANGE_بیت 9
#تعریف_کن FD_آدرس_LIST_CHANGE (1 << FD_آدرس_LIST_CHANGE_بیت)

#تعریف_کن FD_MAX_EVENTS 10
#تعریف_کن FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#اگر_تعریف_نشده WSABASEERR

#تعریف_کن WSABASEERR 10000

#تعریف_کن WSAEINTR (WSABASEERR+4)
#تعریف_کن WSAEBADF (WSABASEERR+9)
#تعریف_کن WSAEACCES (WSABASEERR+13)
#تعریف_کن WSAEFAULT (WSABASEERR+14)
#تعریف_کن WSAEINVAL (WSABASEERR+22)
#تعریف_کن WSAEMFILE (WSABASEERR+24)

#تعریف_کن WSAEWOULDBLOCK (WSABASEERR+35)
#تعریف_کن WSAEINPROGRESS (WSABASEERR+36)
#تعریف_کن WSAEALREADY (WSABASEERR+37)
#تعریف_کن WSAENOTSOCK (WSABASEERR+38)
#تعریف_کن WSAEDESTADDRREQ (WSABASEERR+39)
#تعریف_کن WSAEMSGSIZE (WSABASEERR+40)
#تعریف_کن WSAEPROTOTYPE (WSABASEERR+41)
#تعریف_کن WSAENOPROTOOPT (WSABASEERR+42)
#تعریف_کن WSAEPROTONOSUPPORT (WSABASEERR+43)
#تعریف_کن WSAESOCKTNOSUPPORT (WSABASEERR+44)
#تعریف_کن WSAEOPNOTSUPP (WSABASEERR+45)
#تعریف_کن WSAEPFNOSUPPORT (WSABASEERR+46)
#تعریف_کن WSAEAFNOSUPPORT (WSABASEERR+47)
#تعریف_کن WSAEADDRINUSE (WSABASEERR+48)
#تعریف_کن WSAEADDRNOTAVAIL (WSABASEERR+49)
#تعریف_کن WSAENETDOWN (WSABASEERR+50)
#تعریف_کن WSAENETUNREACH (WSABASEERR+51)
#تعریف_کن WSAENETRESET (WSABASEERR+52)
#تعریف_کن WSAECONNABORTED (WSABASEERR+53)
#تعریف_کن WSAECONNRESET (WSABASEERR+54)
#تعریف_کن WSAENOBUFS (WSABASEERR+55)
#تعریف_کن WSAEISCONN (WSABASEERR+56)
#تعریف_کن WSAENOTCONN (WSABASEERR+57)
#تعریف_کن WSAESHUTDOWN (WSABASEERR+58)
#تعریف_کن WSAETOOMANYREFS (WSABASEERR+59)
#تعریف_کن WSAETIMEDOUT (WSABASEERR+60)
#تعریف_کن WSAECONNREFUSED (WSABASEERR+61)
#تعریف_کن WSAELOOP (WSABASEERR+62)
#تعریف_کن WSAENAMETOOLONG (WSABASEERR+63)
#تعریف_کن WSAEHOSTDOWN (WSABASEERR+64)
#تعریف_کن WSAEHOSTUNREACH (WSABASEERR+65)
#تعریف_کن WSAENOTEMPTY (WSABASEERR+66)
#تعریف_کن WSAEPROCLIM (WSABASEERR+67)
#تعریف_کن WSAEUSERS (WSABASEERR+68)
#تعریف_کن WSAEDQUOT (WSABASEERR+69)
#تعریف_کن WSAESTALE (WSABASEERR+70)
#تعریف_کن WSAEREMOTE (WSABASEERR+71)

#تعریف_کن WSASYSNOTREADY (WSABASEERR+91)
#تعریف_کن WSAVERNOTSUPPORTED (WSABASEERR+92)
#تعریف_کن WSANOTINITIALISED (WSABASEERR+93)
#تعریف_کن WSAEDISCON (WSABASEERR+101)
#اگر_تعریف_نشده WSAHOST_NOT_یافت
#تعریف_کن WSAHOST_NOT_یافت (WSABASEERR+1001)
#پایان_اگر
#اگر_تعریف_نشده WSATRY_AGAIN
#تعریف_کن WSATRY_AGAIN (WSABASEERR+1002)
#پایان_اگر
#اگر_تعریف_نشده WSANO_RECOVERY
#تعریف_کن WSANO_RECOVERY (WSABASEERR+1003)
#پایان_اگر
#اگر_تعریف_نشده WSANO_داده
#تعریف_کن WSANO_داده (WSABASEERR+1004)
#پایان_اگر

#تعریف_کن WSAENOMORE (WSABASEERR+102)
#تعریف_کن WSAECANCELLED (WSABASEERR+103)
#تعریف_کن WSAEINVALIDPROCTABLE (WSABASEERR+104)
#تعریف_کن WSAEINVALIDPROVIDER (WSABASEERR+105)
#تعریف_کن WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#تعریف_کن WSASYSCALLFAILURE (WSABASEERR+107)
#تعریف_کن WSASERVICE_NOT_یافت (WSABASEERR+108)
#تعریف_کن WSATYPE_NOT_یافت (WSABASEERR+109)
#تعریف_کن WSA_E_NO_بیشتر (WSABASEERR+110)
#تعریف_کن WSA_E_CANCELLED (WSABASEERR+111)
#تعریف_کن WSAEREFUSED (WSABASEERR+112)
#اگر_تعریف_نشده WSA_QOS_RECEIVERS
#تعریف_کن WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_SENDERS
#تعریف_کن WSA_QOS_SENDERS (WSABASEERR + 1006)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_NO_SENDERS
#تعریف_کن WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#تعریف_کن WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#تعریف_کن WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#تعریف_کن WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#تعریف_کن WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#تعریف_کن WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#تعریف_کن WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#تعریف_کن WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#تعریف_کن WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#تعریف_کن WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#تعریف_کن WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#تعریف_کن WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EFILTERSTYLE
#تعریف_کن WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EFILTERTYPE
#تعریف_کن WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EFILTERCOUNT
#تعریف_کن WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EOBJLENGTH
#تعریف_کن WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EFLOWCOUNT
#تعریف_کن WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EUNKNOWNPSOBJ
#تعریف_کن WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EPOLICYOBJ
#تعریف_کن WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EFLOWDESC
#تعریف_کن WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EPSFLOWSPEC
#تعریف_کن WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_EPSFILTERSPEC
#تعریف_کن WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_ESDMODEOBJ
#تعریف_کن WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_ESHAPERATEOBJ
#تعریف_کن WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#پایان_اگر
#اگر_تعریف_نشده WSA_QOS_RESERVED_PETYPE
#تعریف_کن WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#پایان_اگر
#پایان_اگر // WSABASEERR

#تعریف_کن h_errno WSAGet_آخرین_Error()
#تعریف_کن HOST_NOT_یافت WSAHOST_NOT_یافت
#تعریف_کن TRY_AGAIN WSATRY_AGAIN
#تعریف_کن NO_RECOVERY WSANO_RECOVERY
#تعریف_کن NO_داده WSANO_داده

#تعریف_کن WSANO_آدرس WSANO_داده
#تعریف_کن NO_آدرس WSANO_آدرس

#إذا 0
#تعریف_کن EWOULDBLOCK WSAEWOULDBLOCK
#تعریف_کن EINPROGRESS WSAEINPROGRESS
#تعریف_کن EALREADY WSAEALREADY
#تعریف_کن ENOTSOCK WSAENOTSOCK
#تعریف_کن EDESTADDRREQ WSAEDESTADDRREQ
#تعریف_کن EMSGSIZE WSAEMSGSIZE
#تعریف_کن EPROTOTYPE WSAEPROTOTYPE
#تعریف_کن ENOPROTOOPT WSAENOPROTOOPT
#تعریف_کن EPROTONOSUPPORT WSAEPROTONOSUPPORT
#تعریف_کن ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#تعریف_کن EOPNOTSUPP WSAEOPNOTSUPP
#تعریف_کن EPFNOSUPPORT WSAEPFNOSUPPORT
#تعریف_کن EAFNOSUPPORT WSAEAFNOSUPPORT
#تعریف_کن EADDRINUSE WSAEADDRINUSE
#تعریف_کن EADDRNOTAVAIL WSAEADDRNOTAVAIL
#تعریف_کن ENETDOWN WSAENETDOWN
#تعریف_کن ENETUNREACH WSAENETUNREACH
#تعریف_کن ENETRESET WSAENETRESET
#تعریف_کن ECONNABORTED WSAECONNABORTED
#تعریف_کن ECONNRESET WSAECONNRESET
#تعریف_کن ENOBUFS WSAENOBUFS
#تعریف_کن EISCONN WSAEISCONN
#تعریف_کن ENOTCONN WSAENOTCONN
#تعریف_کن ESHUTDOWN WSAESHUTDOWN
#تعریف_کن ETOOMANYREFS WSAETOOMANYREFS
#تعریف_کن ETIMEDOUT WSAETIMEDOUT
#تعریف_کن ECONNREFUSED WSAECONNREFUSED
#تعریف_کن ELOOP WSAELOOP
#تعریف_کن ENAMETOOLONG WSAENAMETOOLONG
#تعریف_کن EHOSTDOWN WSAEHOSTDOWN
#تعریف_کن EHOSTUNREACH WSAEHOSTUNREACH
#تعریف_کن ENOTEMPTY WSAENOTEMPTY
#تعریف_کن EPROCLIM WSAEPROCLIM
#تعریف_کن EUSERS WSAEUSERS
#تعریف_کن EDQUOT WSAEDQUOT
#تعریف_کن ESTALE WSAESTALE
#تعریف_کن EREMOTE WSAEREMOTE
#پایان_اگر

#تعریف_کن WSAAPI WINAPI
#تعریف_کن WSAEVENT HANDLE
#تعریف_کن LPWSAEVENT LPHANDLE
#تعریف_کن WSAOVERLAPPED OVERLAPPED
  تعريفنوع بنية _OVERLAPPED *LPWSAOVERLAPPED;

#تعریف_کن WSA_IO_PENDING (ERROR_IO_PENDING)
#تعریف_کن WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#تعریف_کن WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#تعریف_کن WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#تعریف_کن WSA_NOT_ENOUGH_حافظه (ERROR_NOT_ENOUGH_حافظه)
#تعریف_کن WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#تعریف_کن WSA_INVALID_EVENT ((WSAEVENT)عدم)
#تعریف_کن WSA_بیشینه_WAIT_EVENTS (بیشینه_WAIT_OBJECTS)
#تعریف_کن WSA_WAIT_FAILED (WAIT_FAILED)
#تعریف_کن WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#تعریف_کن WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#تعریف_کن WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#تعریف_کن WSA_INFINITE (INFINITE)

  تعريفنوع بنية _WSABUF {
    u_long len;
    حرف *buf;
  } WSABUF,*LPWSABUF;

#ضمن <qos.h>

  تعريفنوع بنية Quality_از_Service {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#تعریف_کن CF_ACCEPT 0x0000
#تعریف_کن CF_REJECT 0x0001
#تعریف_کن CF_DEFER 0x0002

#تعریف_کن SD_RECEIVE 0x00
#تعریف_کن SD_SEND 0x01
#تعریف_کن SD_BOTH 0x02

  تعريفنوع بیعلامت صحيح گروه_3;

#تعریف_کن SG_UNCONSTRAINED_گروه 0x01
#تعریف_کن SG_CONSTRAINED_گروه 0x02

  تعريفنوع بنية _WSANETWORKEVENTS {
    دراز l_شبکه_Events;
    صحيح i_Error_کد[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#اگر_تعریف_نشده GUID_DEFINED
#ضمن <guiddef.h>
#پایان_اگر

#تعریف_کن MAX_PROTOCOL_CHAIN 7

#تعریف_کن پایه_PROTOCOL 1
#تعریف_کن LAYERED_PROTOCOL 0

  تعريفنوع بنية _WSAPROTOCOLCHAIN {
    صحيح ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#تعریف_کن WSAPROTOCOL_LEN 255

  تعريفنوع بنية _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_مدخل_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحيح i_نسخه;
    صحيح i_آدرس_Family;
    صحيح iMaxSockAddr;
    صحيح iMinSockAddr;
    صحيح iSocketType;
    صحيح iProtocol;
    صحيح i_Protocol_Max_جابه_جایی;
    صحيح i_شبکه_Byte_ترتیب;
    صحيح iSecurityScheme;
    DWORD dw_پیام_اندازه;
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
    DWORD dw_Catalog_مدخل_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحيح i_نسخه;
    صحيح i_آدرس_Family;
    صحيح iMaxSockAddr;
    صحيح iMinSockAddr;
    صحيح iSocketType;
    صحيح iProtocol;
    صحيح i_Protocol_Max_جابه_جایی;
    صحيح i_شبکه_Byte_ترتیب;
    صحيح iSecurityScheme;
    DWORD dw_پیام_اندازه;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#اگر_تعریف_شده UNICODE
  تعريفنوع WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  تعريفنوع LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#وإلا
  تعريفنوع WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  تعريفنوع LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#پایان_اگر

#تعریف_کن PFL_مضرب_PROTO_ENTRIES 0x00000001
#تعریف_کن PFL_RECOMMENDED_PROTO_مدخل 0x00000002
#تعریف_کن PFL_HIDDEN 0x00000004
#تعریف_کن PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#تعریف_کن XP1_CONNECTIONLESS 0x00000001
#تعریف_کن XP1_GUARANTEED_DELIVERY 0x00000002
#تعریف_کن XP1_GUARANTEED_ترتیب 0x00000004
#تعریف_کن XP1_پیام_ORIENTED 0x00000008
#تعریف_کن XP1_PSEUDO_جریان 0x00000010
#تعریف_کن XP1_GRACEFUL_CLOSE 0x00000020
#تعریف_کن XP1_EXPEDITED_داده 0x00000040
#تعریف_کن XP1_CONNECT_داده 0x00000080
#تعریف_کن XP1_DISCONNECT_داده 0x00000100
#تعریف_کن XP1_SUPPORT_پخش 0x00000200
#تعریف_کن XP1_SUPPORT_MULTIPOINT 0x00000400
#تعریف_کن XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#تعریف_کن XP1_MULTIPOINT_داده_PLANE 0x00001000
#تعریف_کن XP1_QOS_SUPPORTED 0x00002000
#تعریف_کن XP1_وقفه 0x00004000
#تعریف_کن XP1_UNI_SEND 0x00008000
#تعریف_کن XP1_UNI_RECV 0x00010000
#تعریف_کن XP1_IFS_HANDLES 0x00020000
#تعریف_کن XP1_PARTIAL_پیام 0x00040000

#تعریف_کن BIGENDIAN 0x0000
#تعریف_کن LITTLEENDIAN 0x0001

#تعریف_کن SECURITY_PROTOCOL_NONE 0x0000

#تعریف_کن JL_SENDER_ONLY 0x01
#تعریف_کن JL_RECEIVER_ONLY 0x02
#تعریف_کن JL_BOTH 0x04

#تعریف_کن WSA_FLAG_OVERLAPPED 0x01
#تعریف_کن WSA_FLAG_MULTIPOINT_C_ریشه 0x02
#تعریف_کن WSA_FLAG_MULTIPOINT_C_برگ 0x04
#تعریف_کن WSA_FLAG_MULTIPOINT_D_ریشه 0x08
#تعریف_کن WSA_FLAG_MULTIPOINT_D_برگ 0x10

#تعریف_کن IOC_UNIX 0x00000000
#تعریف_کن IOC_WS2 0x08000000
#تعریف_کن IOC_PROTOCOL 0x10000000
#تعریف_کن IOC_VENDOR 0x18000000

#تعریف_کن _WSAIO(x,y) (IOC_VOID|(x)|(y))
#تعریف_کن _WSAIOR(x,y) (IOC_بیرون|(x)|(y))
#تعریف_کن _WSAIOW(x,y) (IOC_درون|(x)|(y))
#تعریف_کن _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#تعریف_کن SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#تعریف_کن SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#تعریف_کن SIO_پیدا_کن_ROUTE _WSAIOR(IOC_WS2,3)
#تعریف_کن SIO_FLUSH _WSAIO(IOC_WS2,4)
#تعریف_کن SIO_GET_پخش_آدرس _WSAIOR(IOC_WS2,5)
#تعریف_کن SIO_GET_EXTENSION_FUNCTION_اشاره_گر _WSAIORW(IOC_WS2,6)
#تعریف_کن SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#تعریف_کن SIO_GET_گروه_QOS _WSAIORW(IOC_WS2,8)
#تعریف_کن SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#تعریف_کن SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#تعریف_کن SIO_مجموعه_QOS _WSAIOW(IOC_WS2,11)
#تعریف_کن SIO_مجموعه_گروه_QOS _WSAIOW(IOC_WS2,12)
#تعریف_کن SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#تعریف_کن SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#تعریف_کن SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#تعریف_کن SIO_آدرس_LIST_QUERY _WSAIOR(IOC_WS2,22)
#تعریف_کن SIO_آدرس_LIST_CHANGE _WSAIO(IOC_WS2,23)
#تعریف_کن SIO_QUERY_هدف_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#تعریف_کن SIO_آدرس_LIST_مرتب_سازی _WSAIORW(IOC_WS2,25)

  تعريفنوع صحيح (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_داده,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_داده,گروه_3 *g,DWORD_PTR dw_Callback_داده);
  تعريفنوع فراغ (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#تعریف_کن SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  تعريفنوع تعداد _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_پورت,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  تعريفنوع بنية _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    اتحاد {
      بنية {
	HWND hWnd;
	UINT u_پیام;
	WPARAM context;
      } پنجره_پیام;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE h_پورت;
	ULONG_PTR کلید_3;
      } پورت;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#تعریف_کن TH_NETDEV 0x00000001
#تعریف_کن TH_TAPI 0x00000002

  تعريفنوع بنية sockaddr SOCKADDR;
  تعريفنوع بنية sockaddr *PSOCKADDR;
  تعريفنوع بنية sockaddr *LPSOCKADDR;
  تعريفنوع بنية sockaddr_storage SOCKADDR_STORAGE;
  تعريفنوع بنية sockaddr_storage *PSOCKADDR_STORAGE;
  تعريفنوع بنية sockaddr_storage *LPSOCKADDR_STORAGE;

#اگر_تعریف_نشده برچسب_BLOB_DEFINED
#تعریف_کن برچسب_BLOB_DEFINED
#تعریف_کن _BLOB_DEFINED
#تعریف_کن _LPBLOB_DEFINED
  تعريفنوع بنية _BLOB {
    ULONG cb_اندازه;
    BYTE *p_Blob_داده;
  } BLOB,*LPBLOB;
#پایان_اگر

#تعریف_کن SERVICE_مضرب (0x00000001)

#تعریف_کن NS_ALL (0)

#تعریف_کن NS_SAP (1)
#تعریف_کن NS_NDS (2)
#تعریف_کن NS_PEER_BROWSE (3)
#تعریف_کن NS_SLP (5)
#تعریف_کن NS_DHCP (6)

#تعریف_کن NS_TCPIP_LOCAL (10)
#تعریف_کن NS_TCPIP_HOSTS (11)
#تعریف_کن NS_DNS (12)
#تعریف_کن NS_NETBT (13)
#تعریف_کن NS_WINS (14)
#تعریف_کن NS_NLA (15)

#تعریف_کن NS_NBP (20)

#تعریف_کن NS_MS (30)
#تعریف_کن NS_STDA (31)
#تعریف_کن NS_NTDS (32)

#تعریف_کن NS_X500 (40)
#تعریف_کن NS_NIS (41)
#تعریف_کن NS_NISPLUS (42)

#تعریف_کن NS_WRQ (50)

#تعریف_کن NS_NETDES (60)

#تعریف_کن RES_استفادهنشده_1 (0x00000001)
#تعریف_کن RES_FLUSH_CACHE (0x00000002)
#اگر_تعریف_نشده RES_SERVICE
#تعریف_کن RES_SERVICE (0x00000004)
#پایان_اگر

#تعریف_کن SERVICE_TYPE_مقدار_IPXPORTA "IpxSocket"
#تعریف_کن SERVICE_TYPE_مقدار_IPXPORTW L"IpxSocket"
#تعریف_کن SERVICE_TYPE_مقدار_SAPIDA "SapId"
#تعریف_کن SERVICE_TYPE_مقدار_SAPIDW L"SapId"

#تعریف_کن SERVICE_TYPE_مقدار_TCPPORTA "TcpPort"
#تعریف_کن SERVICE_TYPE_مقدار_TCPPORTW L"TcpPort"

#تعریف_کن SERVICE_TYPE_مقدار_UDPPORTA "UdpPort"
#تعریف_کن SERVICE_TYPE_مقدار_UDPPORTW L"UdpPort"

#تعریف_کن SERVICE_TYPE_مقدار_OBJECTIDA "ObjectId"
#تعریف_کن SERVICE_TYPE_مقدار_OBJECTIDW L"ObjectId"

#اگر_تعریف_شده UNICODE

#تعریف_کن SERVICE_TYPE_مقدار_SAPID SERVICE_TYPE_مقدار_SAPIDW
#تعریف_کن SERVICE_TYPE_مقدار_TCPPORT SERVICE_TYPE_مقدار_TCPPORTW
#تعریف_کن SERVICE_TYPE_مقدار_UDPPORT SERVICE_TYPE_مقدار_UDPPORTW
#تعریف_کن SERVICE_TYPE_مقدار_OBJECTID SERVICE_TYPE_مقدار_OBJECTIDW
#وإلا

#تعریف_کن SERVICE_TYPE_مقدار_SAPID SERVICE_TYPE_مقدار_SAPIDA
#تعریف_کن SERVICE_TYPE_مقدار_TCPPORT SERVICE_TYPE_مقدار_TCPPORTA
#تعریف_کن SERVICE_TYPE_مقدار_UDPPORT SERVICE_TYPE_مقدار_UDPPORTA
#تعریف_کن SERVICE_TYPE_مقدار_OBJECTID SERVICE_TYPE_مقدار_OBJECTIDA
#پایان_اگر

#اگر_تعریف_نشده __CSADDR_DEFINED__
#تعریف_کن __CSADDR_DEFINED__

  تعريفنوع بنية SOCKET_آدرس {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_درازی;
  } SOCKET_آدرس_2,*PSOCKET_آدرس,*LPSOCKET_آدرس;

  تعريفنوع بنية _CSADDR_INFO {
    SOCKET_آدرس_2 LocalAddr;
    SOCKET_آدرس_2 RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#پایان_اگر

  تعريفنوع بنية SOCKET_آدرس_LIST {
    INT i_آدرس_شمار;
    SOCKET_آدرس_2 آدرس_2[1];
  } SOCKET_آدرس_LIST_2,*LPSOCKET_آدرس_LIST;

  تعريفنوع بنية _AFPROTOCOLS {
    INT i_آدرس_Family;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  تعريفنوع تعداد _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  تعريفنوع بنية _WSAVersion {
    DWORD dw_نسخه;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  تعريفنوع بنية WSAQuery_مجموعه_A {
    DWORD dw_اندازه;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخه;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_عدد_از_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_عدد_از_Cs_Addrs;
    LPCSADDR_INFO lpcsa_میانگیر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  تعريفنوع بنية WSAQuery_مجموعه_W {
    DWORD dw_اندازه;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخه;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_عدد_از_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_عدد_از_Cs_Addrs;
    LPCSADDR_INFO lpcsa_میانگیر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#اگر_تعریف_شده UNICODE
  تعريفنوع WSAQUERYSETW WSAQUERYSET;
  تعريفنوع PWSAQUERYSETW PWSAQUERYSET;
  تعريفنوع LPWSAQUERYSETW LPWSAQUERYSET;
#وإلا
  تعريفنوع WSAQUERYSETA WSAQUERYSET;
  تعريفنوع PWSAQUERYSETA PWSAQUERYSET;
  تعريفنوع LPWSAQUERYSETA LPWSAQUERYSET;
#پایان_اگر

#تعریف_کن LUP_DEEP 0x0001
#تعریف_کن LUP_CONTAINERS 0x0002
#تعریف_کن LUP_NOCONTAINERS 0x0004
#تعریف_کن LUP_نزدیکترین 0x0008
#تعریف_کن LUP_RETURN_NAME 0x0010
#تعریف_کن LUP_RETURN_TYPE 0x0020
#تعریف_کن LUP_RETURN_نسخه 0x0040
#تعریف_کن LUP_RETURN_COMMENT 0x0080
#تعریف_کن LUP_RETURN_ADDR 0x0100
#تعریف_کن LUP_RETURN_BLOB 0x0200
#تعریف_کن LUP_RETURN_ALIASES 0x0400
#تعریف_کن LUP_RETURN_QUERY_STRING 0x0800
#تعریف_کن LUP_RETURN_ALL 0x0FF0
#تعریف_کن LUP_RES_SERVICE 0x8000

#تعریف_کن LUP_FLUSHCACHE 0x1000
#تعریف_کن LUP_FLUSHPREVIOUS 0x2000

#تعریف_کن نتیجه_IS_ALIAS 0x0001
#تعریف_کن نتیجه_IS_ADDED 0x0010
#تعریف_کن نتیجه_IS_تغییریافته 0x0020
#تعریف_کن نتیجه_IS_DELETED 0x0040

  تعريفنوع تعداد _WSAESETSERVICEOP {
    RNRSERVICE_ثبات=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  تعريفنوع بنية _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_مقدار_Type;
    DWORD dw_مقدار_اندازه;
    LPVOID lp_مقدار;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  تعريفنوع بنية _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_مقدار_Type;
    DWORD dw_مقدار_اندازه;
    LPVOID lp_مقدار;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#اگر_تعریف_شده UNICODE
  تعريفنوع WSANSCLASSINFOW WSANSCLASSINFO;
  تعريفنوع PWSANSCLASSINFOW PWSANSCLASSINFO;
  تعريفنوع LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#وإلا
  تعريفنوع WSANSCLASSINFOA WSANSCLASSINFO;
  تعريفنوع PWSANSCLASSINFOA PWSANSCLASSINFO;
  تعريفنوع LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#پایان_اگر

  تعريفنوع بنية _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_شمار;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  تعريفنوع بنية _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_شمار;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#اگر_تعریف_شده UNICODE
  تعريفنوع WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  تعريفنوع PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  تعريفنوع LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#وإلا
  تعريفنوع WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  تعريفنوع PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  تعريفنوع LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#پایان_اگر

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

#اگر_تعریف_شده UNICODE
  تعريفنوع WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  تعريفنوع PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  تعريفنوع LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#وإلا
  تعريفنوع WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  تعريفنوع PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  تعريفنوع LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#پایان_اگر

#إذا INCL_WINSOCK_API_TYPEDEFS
#اگر_تعریف_شده UNICODE
#تعریف_کن LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#تعریف_کن LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#تعریف_کن LPFN_WSASOCKET LPFN_WSASOCKETW
#تعریف_کن LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#تعریف_کن LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#تعریف_کن LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#تعریف_کن LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#تعریف_کن LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#تعریف_کن LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#تعریف_کن LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#تعریف_کن LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#تعریف_کن LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#وإلا
#تعریف_کن LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#تعریف_کن LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#تعریف_کن LPFN_WSASOCKET LPFN_WSASOCKETA
#تعریف_کن LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#تعریف_کن LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#تعریف_کن LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#تعریف_کن LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#تعریف_کن LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#تعریف_کن LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#تعریف_کن LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#تعریف_کن LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#تعریف_کن LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#پایان_اگر

  تعريفنوع SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,بنية sockaddr *addr,صحيح *addrlen);
  تعريفنوع صحيح (WSAAPI *LPFN_BIND)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  تعريفنوع صحيح (WSAAPI *LPFN_CONNECT)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,دراز cmd,u_long *argp);
  تعريفنوع صحيح (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,صحيح level,صحيح optname,حرف *optval,صحيح *optlen);
  تعريفنوع u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  تعريفنوع u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  تعريفنوع بیعلامت دراز (WSAAPI *LPFN_INET_ADDR)(ثابت حرف *cp);
  تعريفنوع حرف *(WSAAPI *LPFN_INET_NTOA)(بنية درون_addr درون);
  تعريفنوع صحيح (WSAAPI *LPFN_LISTEN)(SOCKET s,صحيح backlog);
  تعريفنوع u_long (WSAAPI *LPFN_NTOHL)(u_long netlong);
  تعريفنوع u_short (WSAAPI *LPFN_NTOHS)(u_short netshort);
  تعريفنوع صحيح (WSAAPI *LPFN_RECV)(SOCKET s,حرف *buf,صحيح len,صحيح flags);
  تعريفنوع صحيح (WSAAPI *LPFN_RECVFROM)(SOCKET s,حرف *buf,صحيح len,صحيح flags,بنية sockaddr *from,صحيح *fromlen);
  تعريفنوع صحيح (WSAAPI *LPFN_SELECT)(صحيح nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ثابت بنية timeval *timeout);
  تعريفنوع صحيح (WSAAPI *LPFN_SEND)(SOCKET s,ثابت حرف *buf,صحيح len,صحيح flags);
  تعريفنوع صحيح (WSAAPI *LPFN_SENDTO)(SOCKET s,ثابت حرف *buf,صحيح len,صحيح flags,ثابت بنية sockaddr *مقصد,صحيح tolen);
  تعريفنوع صحيح (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s,صحيح level,صحيح optname,ثابت حرف *optval,صحيح optlen);
  تعريفنوع صحيح (WSAAPI *LPFN_SHUTDOWN)(SOCKET s,صحيح how);
  تعريفنوع SOCKET (WSAAPI *LPFN_SOCKET)(صحيح af,صحيح type,صحيح protocol);
  تعريفنوع بنية hostent *(WSAAPI *LPFN_GETHOSTBYADDR)(ثابت حرف *addr,صحيح len,صحيح type);
  تعريفنوع بنية hostent *(WSAAPI *LPFN_GETHOSTBYNAME)(ثابت حرف *name);
  تعريفنوع صحيح (WSAAPI *LPFN_GETHOSTNAME)(حرف *name,صحيح namelen);
  تعريفنوع بنية servent *(WSAAPI *LPFN_GETSERVBYPORT)(صحيح پورت_2,ثابت حرف *proto);
  تعريفنوع بنية servent *(WSAAPI *LPFN_GETSERVBYNAME)(ثابت حرف *name,ثابت حرف *proto);
  تعريفنوع بنية protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(صحيح عدد_3);
  تعريفنوع بنية protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(ثابت حرف *name);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASTARTUP)(کلمه_3 w_نسخه_Requested,LPWSADATA lpWSAData);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACLEANUP)(فراغ);
  تعريفنوع فراغ (WSAAPI *LPFN_WSASETLASTERROR)(صحيح iError);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAGETLASTERROR)(فراغ);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(فراغ);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(فراغ);
  تعريفنوع FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lp_بلوک_Func);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(فراغ);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_پیام,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_پیام,صحيح پورت_2,ثابت حرف *proto,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_پیام,ثابت حرف *name,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_پیام,صحيح عدد_3,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_پیام,ثابت حرف *name,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_پیام,ثابت حرف *addr,صحيح len,صحيح type,حرف *buf,صحيح buflen);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_پیام,دراز lEvent);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,بنية sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_داده);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACONNECT)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_داده,LPWSABUF lp_Callee_داده,LPQOS lpSQOS,LPQOS lpGQOS);
  تعريفنوع WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(فراغ);
  تعريفنوع صحيح (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  تعريفنوع صحيح (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_شبکه_Events);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_میانگیر,LPDWORD lpdw_میانگیر_درازی);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_میانگیر,LPDWORD lpdw_میانگیر_درازی);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,دراز l_شبکه_Events);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dw_Io_Control_کد,LPVOID lpv_درون_میانگیر,DWORD cb_درون_میانگیر,LPVOID lpv_بیرون_میانگیر,DWORD cb_بیرون_میانگیر,LPDWORD lpcb_بایتها_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_داده,LPWSABUF lp_Callee_داده,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  تعريفنوع صحيح (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  تعريفنوع صحيح (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_میانگیر_شمار,LPDWORD lp_عدد_از_بایتها_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_داده);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_میانگیر_شمار,LPDWORD lp_عدد_از_بایتها_Recvd,LPDWORD lpFlags,بنية sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_میانگیر_شمار,LPDWORD lp_عدد_از_بایتها_فرستاده,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_داده);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_میانگیر_شمار,LPDWORD lp_عدد_از_بایتها_فرستاده,DWORD dwFlags,ثابت بنية sockaddr *lp_مقصد,صحيح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSASOCKETA)(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,گروه_3 g,DWORD dwFlags);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSASOCKETW)(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,گروه_3 g,DWORD dwFlags);
  تعريفنوع DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  تعريفنوع INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsa_آدرس,DWORD dw_آدرس_درازی,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_آدرس_String,LPDWORD lpdw_آدرس_String_درازی);
  تعريفنوع INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsa_آدرس,DWORD dw_آدرس_درازی,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_آدرس_String,LPDWORD lpdw_آدرس_String_درازی);
  تعريفنوع INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR آدرس_String,INT آدرس_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_آدرس,LPINT lp_آدرس_درازی);
  تعريفنوع INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR آدرس_String,INT آدرس_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_آدرس,LPINT lp_آدرس_درازی);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_میانگیر_درازی,LPWSAQUERYSETA lpqsResults);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_میانگیر_درازی,LPWSAQUERYSETW lpqsResults);
  تعريفنوع INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dw_Control_کد,LPVOID lpv_درون_میانگیر,DWORD cb_درون_میانگیر,LPVOID lpv_بیرون_میانگیر,DWORD cb_بیرون_میانگیر,LPDWORD lpcb_بایتها_Returned,LPWSACOMPLETION lpCompletion);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_اندازه,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_اندازه,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_میانگیر_درازی,LPWSANAMESPACE_INFOA lpnsp_میانگیر);
  تعريفنوع INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_میانگیر_درازی,LPWSANAMESPACE_INFOW lpnsp_میانگیر);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_میانگیر_درازی);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_میانگیر_درازی);
  تعريفنوع INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  تعريفنوع INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  تعريفنوع INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن WSADuplicateSocket WSADuplicateSocketW
#تعریف_کن WSAEnumProtocols WSAEnumProtocolsW
#تعریف_کن WSAAddress_مقصد_String WSAAddress_مقصد_String_W
#تعریف_کن WSASocket WSASocketW
#تعریف_کن WSAString_مقصد_آدرس WSAString_مقصد_آدرس_W
#تعریف_کن WSALookupServiceBegin WSALookupServiceBeginW
#تعریف_کن WSALookup_Service_بعدی WSALookup_Service_بعدی_W
#تعریف_کن WSAInstallServiceClass WSAInstallServiceClassW
#تعریف_کن WSAGetServiceClassInfo WSAGetServiceClassInfoW
#تعریف_کن WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#تعریف_کن WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#تعریف_کن WSASetService WSASetServiceW
#وإلا
#تعریف_کن WSADuplicateSocket WSADuplicateSocketA
#تعریف_کن WSAEnumProtocols WSAEnumProtocolsA
#تعریف_کن WSASocket WSASocketA
#تعریف_کن WSAAddress_مقصد_String WSAAddress_مقصد_String_A
#تعریف_کن WSAString_مقصد_آدرس WSAString_مقصد_آدرس_A
#تعریف_کن WSALookupServiceBegin WSALookupServiceBeginA
#تعریف_کن WSALookup_Service_بعدی WSALookup_Service_بعدی_A
#تعریف_کن WSAInstallServiceClass WSAInstallServiceClassA
#تعریف_کن WSAGetServiceClassInfo WSAGetServiceClassInfoA
#تعریف_کن WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#تعریف_کن WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#تعریف_کن WSASetService WSASetServiceA
#پایان_اگر

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,بنية sockaddr *addr,صحيح *addrlen);
  WINSOCK_API_LINKAGE صحيح WSAAPI bind(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE صحيح WSAAPI connect(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI ioctlsocket(SOCKET s,دراز cmd,u_long *argp);
  WINSOCK_API_LINKAGE صحيح WSAAPI getpeername(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI getsockname(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI getsockopt(SOCKET s,صحيح level,صحيح optname,حرف *optval,صحيح *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE بیعلامت دراز WSAAPI inet_addr(ثابت حرف *cp);
  WINSOCK_API_LINKAGE حرف *WSAAPI inet_ntoa(بنية درون_addr درون);
  WINSOCK_API_LINKAGE صحيح WSAAPI listen(SOCKET s,صحيح backlog);
  WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI recv(SOCKET s,حرف *buf,صحيح len,صحيح flags);
  WINSOCK_API_LINKAGE صحيح WSAAPI recvfrom(SOCKET s,حرف *buf,صحيح len,صحيح flags,بنية sockaddr *from,صحيح *fromlen);
  WINSOCK_API_LINKAGE صحيح WSAAPI select(صحيح nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ثابت بنية timeval *timeout);
  WINSOCK_API_LINKAGE صحيح WSAAPI send(SOCKET s,ثابت حرف *buf,صحيح len,صحيح flags);
  WINSOCK_API_LINKAGE صحيح WSAAPI sendto(SOCKET s,ثابت حرف *buf,صحيح len,صحيح flags,ثابت بنية sockaddr *مقصد,صحيح tolen);
  WINSOCK_API_LINKAGE صحيح WSAAPI setsockopt(SOCKET s,صحيح level,صحيح optname,ثابت حرف *optval,صحيح optlen);
  WINSOCK_API_LINKAGE صحيح WSAAPI shutdown(SOCKET s,صحيح how);
  WINSOCK_API_LINKAGE SOCKET WSAAPI socket(صحيح af,صحيح type,صحيح protocol);
  WINSOCK_API_LINKAGE بنية hostent *WSAAPI gethostbyaddr(ثابت حرف *addr,صحيح len,صحيح type);
  WINSOCK_API_LINKAGE بنية hostent *WSAAPI gethostbyname(ثابت حرف *name);
  WINSOCK_API_LINKAGE صحيح WSAAPI gethostname(حرف *name,صحيح namelen);
  WINSOCK_API_LINKAGE بنية servent *WSAAPI getservbyport(صحيح پورت_2,ثابت حرف *proto);
  WINSOCK_API_LINKAGE بنية servent *WSAAPI getservbyname(ثابت حرف *name,ثابت حرف *proto);
  WINSOCK_API_LINKAGE بنية protoent *WSAAPI getprotobynumber(صحيح عدد_3);
  WINSOCK_API_LINKAGE بنية protoent *WSAAPI getprotobyname(ثابت حرف *name);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAStartup(کلمه_3 w_نسخه_Requested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACleanup(فراغ);
  WINSOCK_API_LINKAGE فراغ WSAAPI WSASet_آخرین_Error(صحيح iError);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAGet_آخرین_Error(فراغ);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(فراغ);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAUnhookBlockingHook(فراغ);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lp_بلوک_Func);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACancelBlockingCall(فراغ);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_پیام,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Serv_By_پورت(HWND hWnd,u_int w_پیام,صحيح پورت_2,ثابت حرف *proto,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_پیام,ثابت حرف *name,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_عدد(HWND hWnd,u_int w_پیام,صحيح عدد_3,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_پیام,ثابت حرف *name,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_پیام,ثابت حرف *addr,صحيح len,صحيح type,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_پیام,دراز lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,بنية sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_داده);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAConnect(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_داده,LPWSABUF lp_Callee_داده,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(فراغ);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnum_شبکه_Events(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_شبکه_Events);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_میانگیر,LPDWORD lpdw_میانگیر_درازی);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_میانگیر,LPDWORD lpdw_میانگیر_درازی);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,دراز l_شبکه_Events);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_نتیجه(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAIoctl(SOCKET s,DWORD dw_Io_Control_کد,LPVOID lpv_درون_میانگیر,DWORD cb_درون_میانگیر,LPVOID lpv_بیرون_میانگیر,DWORD cb_بیرون_میانگیر,LPDWORD lpcb_بایتها_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoin_برگ(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_داده,LPWSABUF lp_Callee_داده,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_میانگیر_شمار,LPDWORD lp_عدد_از_بایتها_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_داده);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_میانگیر_شمار,LPDWORD lp_عدد_از_بایتها_Recvd,LPDWORD lpFlags,بنية sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_میانگیر_شمار,LPDWORD lp_عدد_از_بایتها_فرستاده,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_داده);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASend_مقصد(SOCKET s,LPWSABUF lpBuffers,DWORD dw_میانگیر_شمار,LPDWORD lp_عدد_از_بایتها_فرستاده,DWORD dwFlags,ثابت بنية sockaddr *lp_مقصد,صحيح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,گروه_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,گروه_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWait_For_مضرب_Events(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_مقصد_String_A(LPSOCKADDR lpsa_آدرس,DWORD dw_آدرس_درازی,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_آدرس_String,LPDWORD lpdw_آدرس_String_درازی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_مقصد_String_W(LPSOCKADDR lpsa_آدرس,DWORD dw_آدرس_درازی,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_آدرس_String,LPDWORD lpdw_آدرس_String_درازی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_مقصد_آدرس_A(LPSTR آدرس_String,INT آدرس_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_آدرس,LPINT lp_آدرس_درازی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_مقصد_آدرس_W(LPWSTR آدرس_String,INT آدرس_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_آدرس,LPINT lp_آدرس_درازی);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_بعدی_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_میانگیر_درازی,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_بعدی_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_میانگیر_درازی,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dw_Control_کد,LPVOID lpv_درون_میانگیر,DWORD cb_درون_میانگیر,LPVOID lpv_بیرون_میانگیر,DWORD cb_بیرون_میانگیر,LPDWORD lpcb_بایتها_Returned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_انتها(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_اندازه,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_اندازه,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_میانگیر_درازی,LPWSANAMESPACE_INFOA lpnsp_میانگیر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_میانگیر_درازی,LPWSANAMESPACE_INFOW lpnsp_میانگیر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_میانگیر_درازی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_میانگیر_درازی);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  تعريفنوع بنية sockaddr_درون SOCKADDR_درون;
  تعريفنوع بنية sockaddr_درون *PSOCKADDR_درون;
  تعريفنوع بنية sockaddr_درون *LPSOCKADDR_درون;

  تعريفنوع بنية linger LINGER;
  تعريفنوع بنية linger *PLINGER;
  تعريفنوع بنية linger *LPLINGER;

  تعريفنوع بنية درون_addr درون_ADDR;
  تعريفنوع بنية درون_addr *PIN_ADDR;
  تعريفنوع بنية درون_addr *LPIN_ADDR;

  تعريفنوع بنية fd_set FD_SET;
  تعريفنوع بنية fd_set *PFD_مجموعه;
  تعريفنوع بنية fd_set *LPFD_مجموعه;

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

#تعریف_کن WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#تعریف_کن WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#تعریف_کن WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#تعریف_کن WSAGETASYNCERROR(lParam) HIWORD(lParam)
#تعریف_کن WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#تعریف_کن WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#تعریف_کن POLLRDNORM  0x0100
#تعریف_کن POLLRDBAND  0x0200
#تعریف_کن POLLIN      (POLLRDNORM | POLLRDBAND)
#تعریف_کن POLLPRI     0x0400

#تعریف_کن POLLWRNORM  0x0010
#تعریف_کن POLLOUT     (POLLWRNORM)
#تعریف_کن POLLWRBAND  0x0020

#تعریف_کن POLLERR     0x0001
#تعریف_کن POLLHUP     0x0002
#تعریف_کن POLLNVAL    0x0004

تعريفنوع بنية pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE صحيح WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر

#اگر_تعریف_شده _NEED_POPPACK
#ضمن <poppack.h>
#پایان_اگر

#اگر_تعریف_شده IPV6STRICT
#ضمن <wsipv6ok.h>
#پایان_اگر

#اگر_تعریف_نشده _WINSOCKAPI_
#تعریف_کن _WINSOCKAPI_
#پایان_اگر

#اگر_تعریف_شده _INC_WINSOCK_H
#ضمن <mswsock.h>
#پایان_اگر

#پایان_اگر
