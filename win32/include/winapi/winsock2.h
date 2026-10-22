/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#اگر_غیر_تعریف_شدہ _WINSOCK2API_
#تعریف_کرو _WINSOCK2API_

#اگر_غیر_تعریف_شدہ INCL_WINSOCK_API_TYPEDEFS
#تعریف_کرو INCL_WINSOCK_API_TYPEDEFS 0
#اگر_ختم

#اگر_غیر_تعریف_شدہ _INC_WINDOWS
#شامل <windows.h>
#اگر_ختم

#اگر_غیر_تعریف_شدہ MAKEWORD
#تعریف_کرو MAKEWORD(کم,بلند) ((لفظ_3)(((BYTE)(کم)) | ((لفظ_3)((BYTE)(بلند))) << 8))
#اگر_ختم

#اگر_غیر_تعریف_شدہ WINSOCK_نسخہ
#تعریف_کرو WINSOCK_نسخہ MAKEWORD(2,2)
#اگر_ختم

#اگر_غیر_تعریف_شدہ WINSOCK_API_LINKAGE
#اگر_تعریف_شدہ DECLSPEC_IMPORT
#تعریف_کرو WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#ورنہ
#تعریف_کرو WINSOCK_API_LINKAGE
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WINSOCK_SOCKET_DEFINED
#تعریف_کرو _WINSOCK_SOCKET_DEFINED
  قسمتعریف غیرعلامتی حرف u_char;
  قسمتعریف غیرعلامتی مختصر u_short;
  قسمتعریف غیرعلامتی صحیح u_int;
  قسمتعریف غیرعلامتی طویل u_long;
  __MINGW_EXTENSION قسمتعریف غیرعلامتی __int64 u_int64;
  قسمتعریف INT_PTR SOCKET;
#اگر_ختم

#اگر_غیر_تعریف_شدہ FD_SETSIZE
#تعریف_کرو FD_SETSIZE 64
#اگر_ختم

  قسمتعریف ساخت fd_set {
    u_int fd_گنتی;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  خارجی صحیح WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#تعریف_کرو FD_CLR(fd,سیٹ) کرو { u_int __i; برائے(__i = 0;__i < ((fd_set *)(سیٹ))->fd_گنتی;__i++) { اگر (((fd_set *)(سیٹ))->fd_array[__i]==fd) { جب (__i < ((fd_set *)(سیٹ))->fd_گنتی-1) { ((fd_set *)(سیٹ))->fd_array[__i] = ((fd_set *)(سیٹ))->fd_array[__i+1]; __i++; } ((fd_set *)(سیٹ))->fd_گنتی--; توڑو; } } } جب(0)
#تعریف_کرو FD_SET(fd,سیٹ) کرو { u_int __i; برائے(__i = 0;__i < ((fd_set *)(سیٹ))->fd_گنتی;__i++) { اگر (((fd_set *)(سیٹ))->fd_array[__i]==(fd)) { توڑو; } } اگر (__i==((fd_set *)(سیٹ))->fd_گنتی) { اگر (((fd_set *)(سیٹ))->fd_گنتی < FD_SETSIZE) { ((fd_set *)(سیٹ))->fd_array[__i] = (fd); ((fd_set *)(سیٹ))->fd_گنتی++; } } } جب(0)
#تعریف_کرو FD_ZERO(سیٹ) (((fd_set *)(سیٹ))->fd_گنتی=0)
#تعریف_کرو FD_ISSET(fd,سیٹ) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(سیٹ))

#اگر_غیر_تعریف_شدہ _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کرو _TIMEVAL_DEFINED
  ساخت timeval {
    طویل tv_sec;
    طویل tv_usec;
  };

#تعریف_کرو timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کرو timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#تعریف_کرو timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#اگر_ختم /* _TIMEVAL_DEFINED */

#تعریف_کرو IOCPARM_نقاب 0x7f
#تعریف_کرو IOC_VOID 0x20000000
#تعریف_کرو IOC_برآمد 0x40000000
#تعریف_کرو IOC_اندر 0x80000000
#تعریف_کرو IOC_INOUT (IOC_اندر|IOC_برآمد)

#تعریف_کرو _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#تعریف_کرو _IOR(x,y,t) (IOC_برآمد|(((طویل)حجم(t)&IOCPARM_نقاب)<<16)|((x)<<8)|(y))
#تعریف_کرو _IOW(x,y,t) (IOC_اندر|(((طویل)حجم(t)&IOCPARM_نقاب)<<16)|((x)<<8)|(y))

#تعریف_کرو FIONREAD _IOR('f',127,u_long)
#تعریف_کرو FIONBIO _IOW('f',126,u_long)
#تعریف_کرو FIOASYNC _IOW('f',125,u_long)

#تعریف_کرو SIOCSHIWAT _IOW('s',0,u_long)
#تعریف_کرو SIOCGHIWAT _IOR('s',1,u_long)
#تعریف_کرو SIOCSLOWAT _IOW('s',2,u_long)
#تعریف_کرو SIOCGLOWAT _IOR('s',3,u_long)
#تعریف_کرو SIOCATMARK _IOR('s',7,u_long)

#تعریف_کرو h_addr h_addr_list[0]

  ساخت hostent {
    حرف *h_name;
    حرف **h_aliases;
    مختصر h_addrtype;
    مختصر h_لمبائی;
    حرف **h_addr_list;
  };

  ساخت netent {
    حرف *n_name;
    حرف **n_aliases;
    مختصر n_addrtype;
    u_long n_net;
  };

  ساخت servent {
    حرف *s_name;
    حرف **s_aliases;
#اگر_تعریف_شدہ _WIN64
    حرف *s_proto;
    مختصر s_پورٹ;
#ورنہ
    مختصر s_پورٹ;
    حرف *s_proto;
#اگر_ختم
  };

  ساخت protoent {
    حرف *p_name;
    حرف **p_aliases;
    مختصر p_proto;
  };

#تعریف_کرو IPPROTO_IP 0
#تعریف_کرو IPPROTO_HOPOPTS 0
#تعریف_کرو IPPROTO_ICMP 1
#تعریف_کرو IPPROTO_IGMP 2
#تعریف_کرو IPPROTO_GGP 3
#تعریف_کرو IPPROTO_IPV4 4
#تعریف_کرو IPPROTO_TCP 6
#تعریف_کرو IPPROTO_PUP 12
#تعریف_کرو IPPROTO_UDP 17
#تعریف_کرو IPPROTO_IDP 22
#تعریف_کرو IPPROTO_IPV6 41
#تعریف_کرو IPPROTO_ROUTING 43
#تعریف_کرو IPPROTO_FRAGMENT 44
#تعریف_کرو IPPROTO_ESP 50
#تعریف_کرو IPPROTO_AH 51
#تعریف_کرو IPPROTO_ICMPV6 58
#تعریف_کرو IPPROTO_NONE 59
#تعریف_کرو IPPROTO_DSTOPTS 60
#تعریف_کرو IPPROTO_ND 77
#تعریف_کرو IPPROTO_ICLFXBM 78

#تعریف_کرو IPPROTO_RAW 255
#تعریف_کرو IPPROTO_MAX 256

#تعریف_کرو IPPORT_ECHO 7
#تعریف_کرو IPPORT_DISCARD 9
#تعریف_کرو IPPORT_SYSTAT 11
#تعریف_کرو IPPORT_DAYTIME 13
#تعریف_کرو IPPORT_NETSTAT 15
#تعریف_کرو IPPORT_FTP 21
#تعریف_کرو IPPORT_TELNET 23
#تعریف_کرو IPPORT_SMTP 25
#تعریف_کرو IPPORT_TIMESERVER 37
#تعریف_کرو IPPORT_NAMESERVER 42
#تعریف_کرو IPPORT_WHOIS 43
#تعریف_کرو IPPORT_MTP 57

#تعریف_کرو IPPORT_TFTP 69
#تعریف_کرو IPPORT_RJE 77
#تعریف_کرو IPPORT_FINGER 79
#تعریف_کرو IPPORT_TTYLINK 87
#تعریف_کرو IPPORT_SUPDUP 95

#تعریف_کرو IPPORT_EXECSERVER 512
#تعریف_کرو IPPORT_LOGINSERVER 513
#تعریف_کرو IPPORT_CMDSERVER 514
#تعریف_کرو IPPORT_EFSSERVER 520

#تعریف_کرو IPPORT_BIFFUDP 512
#تعریف_کرو IPPORT_WHOSERVER 513
#تعریف_کرو IPPORT_ROUTESERVER 520

#تعریف_کرو IPPORT_RESERVED 1024

#تعریف_کرو IMPLINK_IP 155
#تعریف_کرو IMPLINK_LOWEXPER 156
#تعریف_کرو IMPLINK_HIGHEXPER 158

#اگر_غیر_تعریف_شدہ s_addr

  ساخت اندر_addr {
    اتحاد {
      ساخت { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      ساخت { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#تعریف_کرو s_addr S_un.S_addr
#تعریف_کرو s_host S_un.S_un_b.s_b2
#تعریف_کرو s_net S_un.S_un_b.s_b1
#تعریف_کرو s_imp S_un.S_un_w.s_w2
#تعریف_کرو s_impno S_un.S_un_b.s_b4
#تعریف_کرو s_lh S_un.S_un_b.s_b3

#اگر_ختم

#تعریف_کرو اندر_CLASSA(i) (((طویل)(i) & 0x80000000)==0)
#تعریف_کرو اندر_CLASSA_NET 0xff000000
#تعریف_کرو اندر_CLASSA_NSHIFT 24
#تعریف_کرو اندر_CLASSA_HOST 0x00ffffff
#تعریف_کرو اندر_CLASSA_MAX 128

#تعریف_کرو اندر_CLASSB(i) (((طویل)(i) & 0xc0000000)==0x80000000)
#تعریف_کرو اندر_CLASSB_NET 0xffff0000
#تعریف_کرو اندر_CLASSB_NSHIFT 16
#تعریف_کرو اندر_CLASSB_HOST 0x0000ffff
#تعریف_کرو اندر_CLASSB_MAX 65536

#تعریف_کرو اندر_CLASSC(i) (((طویل)(i) & 0xe0000000)==0xc0000000)
#تعریف_کرو اندر_CLASSC_NET 0xffffff00
#تعریف_کرو اندر_CLASSC_NSHIFT 8
#تعریف_کرو اندر_CLASSC_HOST 0x000000ff

#تعریف_کرو اندر_CLASSD(i) (((طویل)(i) & 0xf0000000)==0xe0000000)
#تعریف_کرو اندر_CLASSD_NET 0xf0000000
#تعریف_کرو اندر_CLASSD_NSHIFT 28
#تعریف_کرو اندر_CLASSD_HOST 0x0fffffff
#تعریف_کرو اندر_MULTICAST(i) اندر_CLASSD(i)

#تعریف_کرو INADDR_ANY (u_long)0x00000000
#تعریف_کرو INADDR_LOOPBACK 0x7f000001
#تعریف_کرو INADDR_نشر (u_long)0xffffffff
#تعریف_کرو INADDR_NONE 0xffffffff

#تعریف_کرو ADDR_ANY INADDR_ANY

  ساخت sockaddr_اندر {
    مختصر sin_family;
    u_short sin_پورٹ;
    ساخت اندر_addr sin_addr;
    حرف sin_zero[8];
  };

#تعریف_کرو WSADESCRIPTION_LEN 256
#تعریف_کرو WSASYS_حالت_LEN 128

  قسمتعریف ساخت WSAData {
    لفظ_3 w_نسخہ;
    لفظ_3 w_بلند_نسخہ;
#اگر_تعریف_شدہ _WIN64
    غیرعلامتی مختصر iMaxSockets;
    غیرعلامتی مختصر iMaxUdpDg;
    حرف *lpVendorInfo;
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_حالت[WSASYS_حالت_LEN+1];
#ورنہ
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_حالت[WSASYS_حالت_LEN+1];
    غیرعلامتی مختصر iMaxSockets;
    غیرعلامتی مختصر iMaxUdpDg;
    حرف *lpVendorInfo;
#اگر_ختم
  } WSADATA,*LPWSADATA;

#تعریف_کرو INVALID_SOCKET (SOCKET)(~0)
#تعریف_کرو SOCKET_ERROR (-1)

#تعریف_کرو FROM_PROTOCOL_INFO (-1)

#تعریف_کرو SOCK_دھارا 1
#تعریف_کرو SOCK_DGRAM 2
#تعریف_کرو SOCK_RAW 3
#تعریف_کرو SOCK_RDM 4
#تعریف_کرو SOCK_SEQPACKET 5

#تعریف_کرو SO_DEBUG 0x0001
#تعریف_کرو SO_ACCEPTCONN 0x0002
#تعریف_کرو SO_REUSEADDR 0x0004
#تعریف_کرو SO_KEEPALIVE 0x0008
#تعریف_کرو SO_DONTROUTE 0x0010
#تعریف_کرو SO_نشر 0x0020
#تعریف_کرو SO_USELOOPBACK 0x0040
#تعریف_کرو SO_LINGER 0x0080
#تعریف_کرو SO_OOBINLINE 0x0100

#تعریف_کرو SO_DONTLINGER (صحیح)(~SO_LINGER)
#تعریف_کرو SO_EXCLUSIVEADDRUSE ((صحیح)(~SO_REUSEADDR))

#تعریف_کرو SO_SNDBUF 0x1001
#تعریف_کرو SO_RCVBUF 0x1002
#تعریف_کرو SO_SNDLOWAT 0x1003
#تعریف_کرو SO_RCVLOWAT 0x1004
#تعریف_کرو SO_SNDTIMEO 0x1005
#تعریف_کرو SO_RCVTIMEO 0x1006
#تعریف_کرو SO_ERROR 0x1007
#تعریف_کرو SO_TYPE 0x1008

#تعریف_کرو SO_گروہ_ID 0x2001
#تعریف_کرو SO_گروہ_ترجیح 0x2002
#تعریف_کرو SO_MAX_پیغام_سائز 0x2003
#تعریف_کرو SO_PROTOCOL_INFOA 0x2004
#تعریف_کرو SO_PROTOCOL_INFOW 0x2005
#اگر_تعریف_شدہ UNICODE
#تعریف_کرو SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#ورنہ
#تعریف_کرو SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#اگر_ختم
#تعریف_کرو PVD_CONFIG 0x3001
#تعریف_کرو SO_CONDITIONAL_ACCEPT 0x3002

#تعریف_کرو TCP_NODELAY 0x0001

#تعریف_کرو AF_UNSPEC 0

#تعریف_کرو AF_UNIX 1
#تعریف_کرو AF_INET 2
#تعریف_کرو AF_IMPLINK 3
#تعریف_کرو AF_PUP 4
#تعریف_کرو AF_CHAOS 5
#تعریف_کرو AF_NS 6
#تعریف_کرو AF_IPX AF_NS
#تعریف_کرو AF_ISO 7
#تعریف_کرو AF_OSI AF_ISO
#تعریف_کرو AF_ECMA 8
#تعریف_کرو AF_DATAKIT 9
#تعریف_کرو AF_CCITT 10
#تعریف_کرو AF_SNA 11
#تعریف_کرو AF_DECnet 12
#تعریف_کرو AF_DLI 13
#تعریف_کرو AF_LAT 14
#تعریف_کرو AF_HYLINK 15
#تعریف_کرو AF_APPLETALK 16
#تعریف_کرو AF_NETBIOS 17
#تعریف_کرو AF_VOICEVIEW 18
#تعریف_کرو AF_FIREFOX 19
#تعریف_کرو AF_UNKNOWN1 20
#تعریف_کرو AF_BAN 21
#تعریف_کرو AF_ATM 22
#تعریف_کرو AF_INET6 23
#تعریف_کرو AF_CLUSTER 24
#تعریف_کرو AF_12844 25
#تعریف_کرو AF_IRDA 26
#تعریف_کرو AF_NETDES 28
#تعریف_کرو AF_TCNPROCESS 29
#تعریف_کرو AF_TCNMESSAGE 30
#تعریف_کرو AF_ICLFXBM 31

#تعریف_کرو AF_MAX 32

  ساخت sockaddr {
    u_short sa_family;
    حرف sa_ڈیٹا[14];
  };

#تعریف_کرو _SS_MAXSIZE 128
#تعریف_کرو _SS_ALIGNSIZE (8)

#تعریف_کرو SS_PAD1_سائز (_SS_ALIGNSIZE - حجم (مختصر))
#تعریف_کرو SS_PAD2_سائز (_SS_MAXSIZE - (حجم (مختصر) + SS_PAD1_سائز + _SS_ALIGNSIZE))

  ساخت sockaddr_storage {
    مختصر ss_family;
    حرف __ss_pad1[SS_PAD1_سائز];

    __MINGW_EXTENSION __int64 __ss_align;
    حرف __ss_pad2[SS_PAD2_سائز];

  };

  ساخت sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#تعریف_کرو PF_UNSPEC AF_UNSPEC
#تعریف_کرو PF_UNIX AF_UNIX
#تعریف_کرو PF_INET AF_INET
#تعریف_کرو PF_IMPLINK AF_IMPLINK
#تعریف_کرو PF_PUP AF_PUP
#تعریف_کرو PF_CHAOS AF_CHAOS
#تعریف_کرو PF_NS AF_NS
#تعریف_کرو PF_IPX AF_IPX
#تعریف_کرو PF_ISO AF_ISO
#تعریف_کرو PF_OSI AF_OSI
#تعریف_کرو PF_ECMA AF_ECMA
#تعریف_کرو PF_DATAKIT AF_DATAKIT
#تعریف_کرو PF_CCITT AF_CCITT
#تعریف_کرو PF_SNA AF_SNA
#تعریف_کرو PF_DECnet AF_DECnet
#تعریف_کرو PF_DLI AF_DLI
#تعریف_کرو PF_LAT AF_LAT
#تعریف_کرو PF_HYLINK AF_HYLINK
#تعریف_کرو PF_APPLETALK AF_APPLETALK
#تعریف_کرو PF_VOICEVIEW AF_VOICEVIEW
#تعریف_کرو PF_FIREFOX AF_FIREFOX
#تعریف_کرو PF_UNKNOWN1 AF_UNKNOWN1
#تعریف_کرو PF_BAN AF_BAN
#تعریف_کرو PF_ATM AF_ATM
#تعریف_کرو PF_INET6 AF_INET6

#تعریف_کرو PF_MAX AF_MAX

  ساخت linger {
    u_short l_onoff;
    u_short l_linger;
  };

#تعریف_کرو SOL_SOCKET 0xffff

#تعریف_کرو SOMAXCONN 0x7fffffff

#تعریف_کرو پیغام_OOB 0x1
#تعریف_کرو پیغام_PEEK 0x2
#تعریف_کرو پیغام_DONTROUTE 0x4
#تعریف_کرو پیغام_WAITALL 0x8

#تعریف_کرو پیغام_PARTIAL 0x8000

#تعریف_کرو پیغام_مداخلت 0x10

#تعریف_کرو پیغام_MAXIOVLEN 16

#تعریف_کرو MAXGETHOSTSTRUCT 1024

#تعریف_کرو FD_READ_ثنائی_ہندسہ 0
#تعریف_کرو FD_READ (1 << FD_READ_ثنائی_ہندسہ)

#تعریف_کرو FD_WRITE_ثنائی_ہندسہ 1
#تعریف_کرو FD_WRITE (1 << FD_WRITE_ثنائی_ہندسہ)

#تعریف_کرو FD_OOB_ثنائی_ہندسہ 2
#تعریف_کرو FD_OOB (1 << FD_OOB_ثنائی_ہندسہ)

#تعریف_کرو FD_ACCEPT_ثنائی_ہندسہ 3
#تعریف_کرو FD_ACCEPT (1 << FD_ACCEPT_ثنائی_ہندسہ)

#تعریف_کرو FD_CONNECT_ثنائی_ہندسہ 4
#تعریف_کرو FD_CONNECT (1 << FD_CONNECT_ثنائی_ہندسہ)

#تعریف_کرو FD_CLOSE_ثنائی_ہندسہ 5
#تعریف_کرو FD_CLOSE (1 << FD_CLOSE_ثنائی_ہندسہ)

#تعریف_کرو FD_QOS_ثنائی_ہندسہ 6
#تعریف_کرو FD_QOS (1 << FD_QOS_ثنائی_ہندسہ)

#تعریف_کرو FD_گروہ_QOS_ثنائی_ہندسہ 7
#تعریف_کرو FD_گروہ_QOS (1 << FD_گروہ_QOS_ثنائی_ہندسہ)

#تعریف_کرو FD_ROUTING_INTERFACE_CHANGE_ثنائی_ہندسہ 8
#تعریف_کرو FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_ثنائی_ہندسہ)

#تعریف_کرو FD_پتہ_LIST_CHANGE_ثنائی_ہندسہ 9
#تعریف_کرو FD_پتہ_LIST_CHANGE (1 << FD_پتہ_LIST_CHANGE_ثنائی_ہندسہ)

#تعریف_کرو FD_MAX_EVENTS 10
#تعریف_کرو FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#اگر_غیر_تعریف_شدہ WSABASEERR

#تعریف_کرو WSABASEERR 10000

#تعریف_کرو WSAEINTR (WSABASEERR+4)
#تعریف_کرو WSAEBADF (WSABASEERR+9)
#تعریف_کرو WSAEACCES (WSABASEERR+13)
#تعریف_کرو WSAEFAULT (WSABASEERR+14)
#تعریف_کرو WSAEINVAL (WSABASEERR+22)
#تعریف_کرو WSAEMFILE (WSABASEERR+24)

#تعریف_کرو WSAEWOULDBLOCK (WSABASEERR+35)
#تعریف_کرو WSAEINPROGRESS (WSABASEERR+36)
#تعریف_کرو WSAEALREADY (WSABASEERR+37)
#تعریف_کرو WSAENOTSOCK (WSABASEERR+38)
#تعریف_کرو WSAEDESTADDRREQ (WSABASEERR+39)
#تعریف_کرو WSAEMSGSIZE (WSABASEERR+40)
#تعریف_کرو WSAEPROTOTYPE (WSABASEERR+41)
#تعریف_کرو WSAENOPROTOOPT (WSABASEERR+42)
#تعریف_کرو WSAEPROTONOSUPPORT (WSABASEERR+43)
#تعریف_کرو WSAESOCKTNOSUPPORT (WSABASEERR+44)
#تعریف_کرو WSAEOPNOTSUPP (WSABASEERR+45)
#تعریف_کرو WSAEPFNOSUPPORT (WSABASEERR+46)
#تعریف_کرو WSAEAFNOSUPPORT (WSABASEERR+47)
#تعریف_کرو WSAEADDRINUSE (WSABASEERR+48)
#تعریف_کرو WSAEADDRNOTAVAIL (WSABASEERR+49)
#تعریف_کرو WSAENETDOWN (WSABASEERR+50)
#تعریف_کرو WSAENETUNREACH (WSABASEERR+51)
#تعریف_کرو WSAENETRESET (WSABASEERR+52)
#تعریف_کرو WSAECONNABORTED (WSABASEERR+53)
#تعریف_کرو WSAECONNRESET (WSABASEERR+54)
#تعریف_کرو WSAENOBUFS (WSABASEERR+55)
#تعریف_کرو WSAEISCONN (WSABASEERR+56)
#تعریف_کرو WSAENOTCONN (WSABASEERR+57)
#تعریف_کرو WSAESHUTDOWN (WSABASEERR+58)
#تعریف_کرو WSAETOOMANYREFS (WSABASEERR+59)
#تعریف_کرو WSAETIMEDOUT (WSABASEERR+60)
#تعریف_کرو WSAECONNREFUSED (WSABASEERR+61)
#تعریف_کرو WSAELOOP (WSABASEERR+62)
#تعریف_کرو WSAENAMETOOLONG (WSABASEERR+63)
#تعریف_کرو WSAEHOSTDOWN (WSABASEERR+64)
#تعریف_کرو WSAEHOSTUNREACH (WSABASEERR+65)
#تعریف_کرو WSAENOTEMPTY (WSABASEERR+66)
#تعریف_کرو WSAEPROCLIM (WSABASEERR+67)
#تعریف_کرو WSAEUSERS (WSABASEERR+68)
#تعریف_کرو WSAEDQUOT (WSABASEERR+69)
#تعریف_کرو WSAESTALE (WSABASEERR+70)
#تعریف_کرو WSAEREMOTE (WSABASEERR+71)

#تعریف_کرو WSASYSNOTREADY (WSABASEERR+91)
#تعریف_کرو WSAVERNOTSUPPORTED (WSABASEERR+92)
#تعریف_کرو WSANOTINITIALISED (WSABASEERR+93)
#تعریف_کرو WSAEDISCON (WSABASEERR+101)
#اگر_غیر_تعریف_شدہ WSAHOST_NOT_ملا
#تعریف_کرو WSAHOST_NOT_ملا (WSABASEERR+1001)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSATRY_AGAIN
#تعریف_کرو WSATRY_AGAIN (WSABASEERR+1002)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSANO_RECOVERY
#تعریف_کرو WSANO_RECOVERY (WSABASEERR+1003)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSANO_ڈیٹا
#تعریف_کرو WSANO_ڈیٹا (WSABASEERR+1004)
#اگر_ختم

#تعریف_کرو WSAENOMORE (WSABASEERR+102)
#تعریف_کرو WSAECANCELLED (WSABASEERR+103)
#تعریف_کرو WSAEINVALIDPROCTABLE (WSABASEERR+104)
#تعریف_کرو WSAEINVALIDPROVIDER (WSABASEERR+105)
#تعریف_کرو WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#تعریف_کرو WSASYSCALLFAILURE (WSABASEERR+107)
#تعریف_کرو WSASERVICE_NOT_ملا (WSABASEERR+108)
#تعریف_کرو WSATYPE_NOT_ملا (WSABASEERR+109)
#تعریف_کرو WSA_E_NO_مزید (WSABASEERR+110)
#تعریف_کرو WSA_E_CANCELLED (WSABASEERR+111)
#تعریف_کرو WSAEREFUSED (WSABASEERR+112)
#اگر_غیر_تعریف_شدہ WSA_QOS_RECEIVERS
#تعریف_کرو WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_SENDERS
#تعریف_کرو WSA_QOS_SENDERS (WSABASEERR + 1006)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_NO_SENDERS
#تعریف_کرو WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#تعریف_کرو WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#تعریف_کرو WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#تعریف_کرو WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#تعریف_کرو WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#تعریف_کرو WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#تعریف_کرو WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#تعریف_کرو WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#تعریف_کرو WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#تعریف_کرو WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#تعریف_کرو WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#تعریف_کرو WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EFILTERSTYLE
#تعریف_کرو WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EFILTERTYPE
#تعریف_کرو WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EFILTERCOUNT
#تعریف_کرو WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EOBJLENGTH
#تعریف_کرو WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EFLOWCOUNT
#تعریف_کرو WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EUNKNOWNPSOBJ
#تعریف_کرو WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EPOLICYOBJ
#تعریف_کرو WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EFLOWDESC
#تعریف_کرو WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EPSFLOWSPEC
#تعریف_کرو WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_EPSFILTERSPEC
#تعریف_کرو WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_ESDMODEOBJ
#تعریف_کرو WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_ESHAPERATEOBJ
#تعریف_کرو WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#اگر_ختم
#اگر_غیر_تعریف_شدہ WSA_QOS_RESERVED_PETYPE
#تعریف_کرو WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#اگر_ختم
#اگر_ختم // WSABASEERR

#تعریف_کرو h_errno WSAGet_آخری_Error()
#تعریف_کرو HOST_NOT_ملا WSAHOST_NOT_ملا
#تعریف_کرو TRY_AGAIN WSATRY_AGAIN
#تعریف_کرو NO_RECOVERY WSANO_RECOVERY
#تعریف_کرو NO_ڈیٹا WSANO_ڈیٹا

#تعریف_کرو WSANO_پتہ WSANO_ڈیٹا
#تعریف_کرو NO_پتہ WSANO_پتہ

#اگر 0
#تعریف_کرو EWOULDBLOCK WSAEWOULDBLOCK
#تعریف_کرو EINPROGRESS WSAEINPROGRESS
#تعریف_کرو EALREADY WSAEALREADY
#تعریف_کرو ENOTSOCK WSAENOTSOCK
#تعریف_کرو EDESTADDRREQ WSAEDESTADDRREQ
#تعریف_کرو EMSGSIZE WSAEMSGSIZE
#تعریف_کرو EPROTOTYPE WSAEPROTOTYPE
#تعریف_کرو ENOPROTOOPT WSAENOPROTOOPT
#تعریف_کرو EPROTONOSUPPORT WSAEPROTONOSUPPORT
#تعریف_کرو ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#تعریف_کرو EOPNOTSUPP WSAEOPNOTSUPP
#تعریف_کرو EPFNOSUPPORT WSAEPFNOSUPPORT
#تعریف_کرو EAFNOSUPPORT WSAEAFNOSUPPORT
#تعریف_کرو EADDRINUSE WSAEADDRINUSE
#تعریف_کرو EADDRNOTAVAIL WSAEADDRNOTAVAIL
#تعریف_کرو ENETDOWN WSAENETDOWN
#تعریف_کرو ENETUNREACH WSAENETUNREACH
#تعریف_کرو ENETRESET WSAENETRESET
#تعریف_کرو ECONNABORTED WSAECONNABORTED
#تعریف_کرو ECONNRESET WSAECONNRESET
#تعریف_کرو ENOBUFS WSAENOBUFS
#تعریف_کرو EISCONN WSAEISCONN
#تعریف_کرو ENOTCONN WSAENOTCONN
#تعریف_کرو ESHUTDOWN WSAESHUTDOWN
#تعریف_کرو ETOOMANYREFS WSAETOOMANYREFS
#تعریف_کرو ETIMEDOUT WSAETIMEDOUT
#تعریف_کرو ECONNREFUSED WSAECONNREFUSED
#تعریف_کرو ELOOP WSAELOOP
#تعریف_کرو ENAMETOOLONG WSAENAMETOOLONG
#تعریف_کرو EHOSTDOWN WSAEHOSTDOWN
#تعریف_کرو EHOSTUNREACH WSAEHOSTUNREACH
#تعریف_کرو ENOTEMPTY WSAENOTEMPTY
#تعریف_کرو EPROCLIM WSAEPROCLIM
#تعریف_کرو EUSERS WSAEUSERS
#تعریف_کرو EDQUOT WSAEDQUOT
#تعریف_کرو ESTALE WSAESTALE
#تعریف_کرو EREMOTE WSAEREMOTE
#اگر_ختم

#تعریف_کرو WSAAPI WINAPI
#تعریف_کرو WSAEVENT HANDLE
#تعریف_کرو LPWSAEVENT LPHANDLE
#تعریف_کرو WSAOVERLAPPED OVERLAPPED
  قسمتعریف ساخت _OVERLAPPED *LPWSAOVERLAPPED;

#تعریف_کرو WSA_IO_PENDING (ERROR_IO_PENDING)
#تعریف_کرو WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#تعریف_کرو WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#تعریف_کرو WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#تعریف_کرو WSA_NOT_ENOUGH_حافظہ (ERROR_NOT_ENOUGH_حافظہ)
#تعریف_کرو WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#تعریف_کرو WSA_INVALID_EVENT ((WSAEVENT)تہی)
#تعریف_کرو WSA_زیادہ_سے_زیادہ_WAIT_EVENTS (زیادہ_سے_زیادہ_WAIT_OBJECTS)
#تعریف_کرو WSA_WAIT_FAILED (WAIT_FAILED)
#تعریف_کرو WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#تعریف_کرو WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#تعریف_کرو WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#تعریف_کرو WSA_INFINITE (INFINITE)

  قسمتعریف ساخت _WSABUF {
    u_long len;
    حرف *buf;
  } WSABUF,*LPWSABUF;

#شامل <qos.h>

  قسمتعریف ساخت Quality_کا_Service {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#تعریف_کرو CF_ACCEPT 0x0000
#تعریف_کرو CF_REJECT 0x0001
#تعریف_کرو CF_DEFER 0x0002

#تعریف_کرو SD_RECEIVE 0x00
#تعریف_کرو SD_SEND 0x01
#تعریف_کرو SD_BOTH 0x02

  قسمتعریف غیرعلامتی صحیح گروہ_3;

#تعریف_کرو SG_UNCONSTRAINED_گروہ 0x01
#تعریف_کرو SG_CONSTRAINED_گروہ 0x02

  قسمتعریف ساخت _WSANETWORKEVENTS {
    طویل l_جال_Events;
    صحیح i_Error_رمز[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#اگر_غیر_تعریف_شدہ GUID_DEFINED
#شامل <guiddef.h>
#اگر_ختم

#تعریف_کرو MAX_PROTOCOL_CHAIN 7

#تعریف_کرو بنیاد_PROTOCOL 1
#تعریف_کرو LAYERED_PROTOCOL 0

  قسمتعریف ساخت _WSAPROTOCOLCHAIN {
    صحیح ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#تعریف_کرو WSAPROTOCOL_LEN 255

  قسمتعریف ساخت _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_اندراج_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحیح i_نسخہ;
    صحیح i_پتہ_Family;
    صحیح iMaxSockAddr;
    صحیح iMinSockAddr;
    صحیح iSocketType;
    صحیح iProtocol;
    صحیح i_Protocol_Max_انحراف;
    صحیح i_جال_Byte_ترتیب;
    صحیح iSecurityScheme;
    DWORD dw_پیغام_سائز;
    DWORD dwProviderReserved;
    CHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOA,*LPWSAPROTOCOL_INFOA;
  قسمتعریف ساخت _WSAPROTOCOL_INFOW {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_اندراج_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحیح i_نسخہ;
    صحیح i_پتہ_Family;
    صحیح iMaxSockAddr;
    صحیح iMinSockAddr;
    صحیح iSocketType;
    صحیح iProtocol;
    صحیح i_Protocol_Max_انحراف;
    صحیح i_جال_Byte_ترتیب;
    صحیح iSecurityScheme;
    DWORD dw_پیغام_سائز;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#اگر_تعریف_شدہ UNICODE
  قسمتعریف WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  قسمتعریف LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#ورنہ
  قسمتعریف WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  قسمتعریف LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#اگر_ختم

#تعریف_کرو PFL_مضرب_PROTO_ENTRIES 0x00000001
#تعریف_کرو PFL_RECOMMENDED_PROTO_اندراج 0x00000002
#تعریف_کرو PFL_HIDDEN 0x00000004
#تعریف_کرو PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#تعریف_کرو XP1_CONNECTIONLESS 0x00000001
#تعریف_کرو XP1_GUARANTEED_DELIVERY 0x00000002
#تعریف_کرو XP1_GUARANTEED_ترتیب 0x00000004
#تعریف_کرو XP1_پیغام_ORIENTED 0x00000008
#تعریف_کرو XP1_PSEUDO_دھارا 0x00000010
#تعریف_کرو XP1_GRACEFUL_CLOSE 0x00000020
#تعریف_کرو XP1_EXPEDITED_ڈیٹا 0x00000040
#تعریف_کرو XP1_CONNECT_ڈیٹا 0x00000080
#تعریف_کرو XP1_DISCONNECT_ڈیٹا 0x00000100
#تعریف_کرو XP1_SUPPORT_نشر 0x00000200
#تعریف_کرو XP1_SUPPORT_MULTIPOINT 0x00000400
#تعریف_کرو XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#تعریف_کرو XP1_MULTIPOINT_ڈیٹا_PLANE 0x00001000
#تعریف_کرو XP1_QOS_SUPPORTED 0x00002000
#تعریف_کرو XP1_مداخلت 0x00004000
#تعریف_کرو XP1_UNI_SEND 0x00008000
#تعریف_کرو XP1_UNI_RECV 0x00010000
#تعریف_کرو XP1_IFS_HANDLES 0x00020000
#تعریف_کرو XP1_PARTIAL_پیغام 0x00040000

#تعریف_کرو BIGENDIAN 0x0000
#تعریف_کرو LITTLEENDIAN 0x0001

#تعریف_کرو SECURITY_PROTOCOL_NONE 0x0000

#تعریف_کرو JL_SENDER_ONLY 0x01
#تعریف_کرو JL_RECEIVER_ONLY 0x02
#تعریف_کرو JL_BOTH 0x04

#تعریف_کرو WSA_FLAG_OVERLAPPED 0x01
#تعریف_کرو WSA_FLAG_MULTIPOINT_C_جڑ 0x02
#تعریف_کرو WSA_FLAG_MULTIPOINT_C_برگ 0x04
#تعریف_کرو WSA_FLAG_MULTIPOINT_D_جڑ 0x08
#تعریف_کرو WSA_FLAG_MULTIPOINT_D_برگ 0x10

#تعریف_کرو IOC_UNIX 0x00000000
#تعریف_کرو IOC_WS2 0x08000000
#تعریف_کرو IOC_PROTOCOL 0x10000000
#تعریف_کرو IOC_VENDOR 0x18000000

#تعریف_کرو _WSAIO(x,y) (IOC_VOID|(x)|(y))
#تعریف_کرو _WSAIOR(x,y) (IOC_برآمد|(x)|(y))
#تعریف_کرو _WSAIOW(x,y) (IOC_اندر|(x)|(y))
#تعریف_کرو _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#تعریف_کرو SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#تعریف_کرو SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#تعریف_کرو SIO_ڈھونڈو_ROUTE _WSAIOR(IOC_WS2,3)
#تعریف_کرو SIO_FLUSH _WSAIO(IOC_WS2,4)
#تعریف_کرو SIO_GET_نشر_پتہ _WSAIOR(IOC_WS2,5)
#تعریف_کرو SIO_GET_EXTENSION_FUNCTION_اشارہ_گر _WSAIORW(IOC_WS2,6)
#تعریف_کرو SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#تعریف_کرو SIO_GET_گروہ_QOS _WSAIORW(IOC_WS2,8)
#تعریف_کرو SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#تعریف_کرو SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#تعریف_کرو SIO_سیٹ_QOS _WSAIOW(IOC_WS2,11)
#تعریف_کرو SIO_سیٹ_گروہ_QOS _WSAIOW(IOC_WS2,12)
#تعریف_کرو SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#تعریف_کرو SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#تعریف_کرو SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#تعریف_کرو SIO_پتہ_LIST_QUERY _WSAIOR(IOC_WS2,22)
#تعریف_کرو SIO_پتہ_LIST_CHANGE _WSAIO(IOC_WS2,23)
#تعریف_کرو SIO_QUERY_ہدف_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#تعریف_کرو SIO_پتہ_LIST_ترتیب_دو _WSAIORW(IOC_WS2,25)

  قسمتعریف صحیح (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_ڈیٹا,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_ڈیٹا,گروہ_3 *g,DWORD_PTR dw_Callback_ڈیٹا);
  قسمتعریف خالی (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#تعریف_کرو SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  قسمتعریف شمار _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_پورٹ,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  قسمتعریف ساخت _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    اتحاد {
      ساخت {
	HWND hWnd;
	UINT u_پیغام;
	WPARAM context;
      } کھڑکی_پیغام;
      ساخت {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      ساخت {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      ساخت {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE h_پورٹ;
	ULONG_PTR کلید_3;
      } پورٹ;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#تعریف_کرو TH_NETDEV 0x00000001
#تعریف_کرو TH_TAPI 0x00000002

  قسمتعریف ساخت sockaddr SOCKADDR;
  قسمتعریف ساخت sockaddr *PSOCKADDR;
  قسمتعریف ساخت sockaddr *LPSOCKADDR;
  قسمتعریف ساخت sockaddr_storage SOCKADDR_STORAGE;
  قسمتعریف ساخت sockaddr_storage *PSOCKADDR_STORAGE;
  قسمتعریف ساخت sockaddr_storage *LPSOCKADDR_STORAGE;

#اگر_غیر_تعریف_شدہ لیبل_BLOB_DEFINED
#تعریف_کرو لیبل_BLOB_DEFINED
#تعریف_کرو _BLOB_DEFINED
#تعریف_کرو _LPBLOB_DEFINED
  قسمتعریف ساخت _BLOB {
    ULONG cb_سائز;
    BYTE *p_Blob_ڈیٹا;
  } BLOB,*LPBLOB;
#اگر_ختم

#تعریف_کرو SERVICE_مضرب (0x00000001)

#تعریف_کرو NS_ALL (0)

#تعریف_کرو NS_SAP (1)
#تعریف_کرو NS_NDS (2)
#تعریف_کرو NS_PEER_BROWSE (3)
#تعریف_کرو NS_SLP (5)
#تعریف_کرو NS_DHCP (6)

#تعریف_کرو NS_TCPIP_LOCAL (10)
#تعریف_کرو NS_TCPIP_HOSTS (11)
#تعریف_کرو NS_DNS (12)
#تعریف_کرو NS_NETBT (13)
#تعریف_کرو NS_WINS (14)
#تعریف_کرو NS_NLA (15)

#تعریف_کرو NS_NBP (20)

#تعریف_کرو NS_MS (30)
#تعریف_کرو NS_STDA (31)
#تعریف_کرو NS_NTDS (32)

#تعریف_کرو NS_X500 (40)
#تعریف_کرو NS_NIS (41)
#تعریف_کرو NS_NISPLUS (42)

#تعریف_کرو NS_WRQ (50)

#تعریف_کرو NS_NETDES (60)

#تعریف_کرو RES_غیر_مستعمل_1 (0x00000001)
#تعریف_کرو RES_FLUSH_CACHE (0x00000002)
#اگر_غیر_تعریف_شدہ RES_SERVICE
#تعریف_کرو RES_SERVICE (0x00000004)
#اگر_ختم

#تعریف_کرو SERVICE_TYPE_قدر_IPXPORTA "IpxSocket"
#تعریف_کرو SERVICE_TYPE_قدر_IPXPORTW L"IpxSocket"
#تعریف_کرو SERVICE_TYPE_قدر_SAPIDA "SapId"
#تعریف_کرو SERVICE_TYPE_قدر_SAPIDW L"SapId"

#تعریف_کرو SERVICE_TYPE_قدر_TCPPORTA "TcpPort"
#تعریف_کرو SERVICE_TYPE_قدر_TCPPORTW L"TcpPort"

#تعریف_کرو SERVICE_TYPE_قدر_UDPPORTA "UdpPort"
#تعریف_کرو SERVICE_TYPE_قدر_UDPPORTW L"UdpPort"

#تعریف_کرو SERVICE_TYPE_قدر_OBJECTIDA "ObjectId"
#تعریف_کرو SERVICE_TYPE_قدر_OBJECTIDW L"ObjectId"

#اگر_تعریف_شدہ UNICODE

#تعریف_کرو SERVICE_TYPE_قدر_SAPID SERVICE_TYPE_قدر_SAPIDW
#تعریف_کرو SERVICE_TYPE_قدر_TCPPORT SERVICE_TYPE_قدر_TCPPORTW
#تعریف_کرو SERVICE_TYPE_قدر_UDPPORT SERVICE_TYPE_قدر_UDPPORTW
#تعریف_کرو SERVICE_TYPE_قدر_OBJECTID SERVICE_TYPE_قدر_OBJECTIDW
#ورنہ

#تعریف_کرو SERVICE_TYPE_قدر_SAPID SERVICE_TYPE_قدر_SAPIDA
#تعریف_کرو SERVICE_TYPE_قدر_TCPPORT SERVICE_TYPE_قدر_TCPPORTA
#تعریف_کرو SERVICE_TYPE_قدر_UDPPORT SERVICE_TYPE_قدر_UDPPORTA
#تعریف_کرو SERVICE_TYPE_قدر_OBJECTID SERVICE_TYPE_قدر_OBJECTIDA
#اگر_ختم

#اگر_غیر_تعریف_شدہ __CSADDR_DEFINED__
#تعریف_کرو __CSADDR_DEFINED__

  قسمتعریف ساخت SOCKET_پتہ {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_لمبائی;
  } SOCKET_پتہ_2,*PSOCKET_پتہ,*LPSOCKET_پتہ;

  قسمتعریف ساخت _CSADDR_INFO {
    SOCKET_پتہ_2 LocalAddr;
    SOCKET_پتہ_2 RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#اگر_ختم

  قسمتعریف ساخت SOCKET_پتہ_LIST {
    INT i_پتہ_گنتی;
    SOCKET_پتہ_2 پتہ_2[1];
  } SOCKET_پتہ_LIST_2,*LPSOCKET_پتہ_LIST;

  قسمتعریف ساخت _AFPROTOCOLS {
    INT i_پتہ_Family;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  قسمتعریف شمار _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  قسمتعریف ساخت _WSAVersion {
    DWORD dw_نسخہ;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  قسمتعریف ساخت WSAQuery_سیٹ_A {
    DWORD dw_سائز;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخہ;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_نمبر_کا_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_نمبر_کا_Cs_Addrs;
    LPCSADDR_INFO lpcsa_بفر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  قسمتعریف ساخت WSAQuery_سیٹ_W {
    DWORD dw_سائز;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخہ;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_نمبر_کا_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_نمبر_کا_Cs_Addrs;
    LPCSADDR_INFO lpcsa_بفر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف WSAQUERYSETW WSAQUERYSET;
  قسمتعریف PWSAQUERYSETW PWSAQUERYSET;
  قسمتعریف LPWSAQUERYSETW LPWSAQUERYSET;
#ورنہ
  قسمتعریف WSAQUERYSETA WSAQUERYSET;
  قسمتعریف PWSAQUERYSETA PWSAQUERYSET;
  قسمتعریف LPWSAQUERYSETA LPWSAQUERYSET;
#اگر_ختم

#تعریف_کرو LUP_DEEP 0x0001
#تعریف_کرو LUP_CONTAINERS 0x0002
#تعریف_کرو LUP_NOCONTAINERS 0x0004
#تعریف_کرو LUP_قریب_ترین 0x0008
#تعریف_کرو LUP_RETURN_NAME 0x0010
#تعریف_کرو LUP_RETURN_TYPE 0x0020
#تعریف_کرو LUP_RETURN_نسخہ 0x0040
#تعریف_کرو LUP_RETURN_COMMENT 0x0080
#تعریف_کرو LUP_RETURN_ADDR 0x0100
#تعریف_کرو LUP_RETURN_BLOB 0x0200
#تعریف_کرو LUP_RETURN_ALIASES 0x0400
#تعریف_کرو LUP_RETURN_QUERY_STRING 0x0800
#تعریف_کرو LUP_RETURN_ALL 0x0FF0
#تعریف_کرو LUP_RES_SERVICE 0x8000

#تعریف_کرو LUP_FLUSHCACHE 0x1000
#تعریف_کرو LUP_FLUSHPREVIOUS 0x2000

#تعریف_کرو نتیجہ_IS_ALIAS 0x0001
#تعریف_کرو نتیجہ_IS_ADDED 0x0010
#تعریف_کرو نتیجہ_IS_بدلا 0x0020
#تعریف_کرو نتیجہ_IS_DELETED 0x0040

  قسمتعریف شمار _WSAESETSERVICEOP {
    RNRSERVICE_رجسٹر=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  قسمتعریف ساخت _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_قدر_Type;
    DWORD dw_قدر_سائز;
    LPVOID lp_قدر;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  قسمتعریف ساخت _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_قدر_Type;
    DWORD dw_قدر_سائز;
    LPVOID lp_قدر;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف WSANSCLASSINFOW WSANSCLASSINFO;
  قسمتعریف PWSANSCLASSINFOW PWSANSCLASSINFO;
  قسمتعریف LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#ورنہ
  قسمتعریف WSANSCLASSINFOA WSANSCLASSINFO;
  قسمتعریف PWSANSCLASSINFOA PWSANSCLASSINFO;
  قسمتعریف LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#اگر_ختم

  قسمتعریف ساخت _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_گنتی;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  قسمتعریف ساخت _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_گنتی;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  قسمتعریف PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  قسمتعریف LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#ورنہ
  قسمتعریف WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  قسمتعریف PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  قسمتعریف LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#اگر_ختم

  قسمتعریف ساخت _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_فعال;
    DWORD dw_نسخہ;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  قسمتعریف ساخت _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_فعال;
    DWORD dw_نسخہ;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  قسمتعریف PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  قسمتعریف LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#ورنہ
  قسمتعریف WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  قسمتعریف PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  قسمتعریف LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#اگر_ختم

#اگر INCL_WINSOCK_API_TYPEDEFS
#اگر_تعریف_شدہ UNICODE
#تعریف_کرو LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#تعریف_کرو LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#تعریف_کرو LPFN_WSASOCKET LPFN_WSASOCKETW
#تعریف_کرو LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#تعریف_کرو LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#تعریف_کرو LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#تعریف_کرو LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#تعریف_کرو LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#تعریف_کرو LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#تعریف_کرو LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#تعریف_کرو LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#تعریف_کرو LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#ورنہ
#تعریف_کرو LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#تعریف_کرو LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#تعریف_کرو LPFN_WSASOCKET LPFN_WSASOCKETA
#تعریف_کرو LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#تعریف_کرو LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#تعریف_کرو LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#تعریف_کرو LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#تعریف_کرو LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#تعریف_کرو LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#تعریف_کرو LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#تعریف_کرو LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#تعریف_کرو LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#اگر_ختم

  قسمتعریف SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,ساخت sockaddr *addr,صحیح *addrlen);
  قسمتعریف صحیح (WSAAPI *LPFN_BIND)(SOCKET s,ثابت ساخت sockaddr *name,صحیح namelen);
  قسمتعریف صحیح (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  قسمتعریف صحیح (WSAAPI *LPFN_CONNECT)(SOCKET s,ثابت ساخت sockaddr *name,صحیح namelen);
  قسمتعریف صحیح (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,طویل cmd,u_long *argp);
  قسمتعریف صحیح (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,ساخت sockaddr *name,صحیح *namelen);
  قسمتعریف صحیح (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,ساخت sockaddr *name,صحیح *namelen);
  قسمتعریف صحیح (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,صحیح level,صحیح optname,حرف *optval,صحیح *optlen);
  قسمتعریف u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  قسمتعریف u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  قسمتعریف غیرعلامتی طویل (WSAAPI *LPFN_INET_ADDR)(ثابت حرف *cp);
  قسمتعریف حرف *(WSAAPI *LPFN_INET_NTOA)(ساخت اندر_addr اندر);
  قسمتعریف صحیح (WSAAPI *LPFN_LISTEN)(SOCKET s,صحیح backlog);
  قسمتعریف u_long (WSAAPI *LPFN_NTOHL)(u_long netlong);
  قسمتعریف u_short (WSAAPI *LPFN_NTOHS)(u_short netshort);
  قسمتعریف صحیح (WSAAPI *LPFN_RECV)(SOCKET s,حرف *buf,صحیح len,صحیح flags);
  قسمتعریف صحیح (WSAAPI *LPFN_RECVFROM)(SOCKET s,حرف *buf,صحیح len,صحیح flags,ساخت sockaddr *from,صحیح *fromlen);
  قسمتعریف صحیح (WSAAPI *LPFN_SELECT)(صحیح nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ثابت ساخت timeval *timeout);
  قسمتعریف صحیح (WSAAPI *LPFN_SEND)(SOCKET s,ثابت حرف *buf,صحیح len,صحیح flags);
  قسمتعریف صحیح (WSAAPI *LPFN_SENDTO)(SOCKET s,ثابت حرف *buf,صحیح len,صحیح flags,ثابت ساخت sockaddr *مقصد,صحیح tolen);
  قسمتعریف صحیح (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s,صحیح level,صحیح optname,ثابت حرف *optval,صحیح optlen);
  قسمتعریف صحیح (WSAAPI *LPFN_SHUTDOWN)(SOCKET s,صحیح how);
  قسمتعریف SOCKET (WSAAPI *LPFN_SOCKET)(صحیح af,صحیح type,صحیح protocol);
  قسمتعریف ساخت hostent *(WSAAPI *LPFN_GETHOSTBYADDR)(ثابت حرف *addr,صحیح len,صحیح type);
  قسمتعریف ساخت hostent *(WSAAPI *LPFN_GETHOSTBYNAME)(ثابت حرف *name);
  قسمتعریف صحیح (WSAAPI *LPFN_GETHOSTNAME)(حرف *name,صحیح namelen);
  قسمتعریف ساخت servent *(WSAAPI *LPFN_GETSERVBYPORT)(صحیح پورٹ_2,ثابت حرف *proto);
  قسمتعریف ساخت servent *(WSAAPI *LPFN_GETSERVBYNAME)(ثابت حرف *name,ثابت حرف *proto);
  قسمتعریف ساخت protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(صحیح نمبر_3);
  قسمتعریف ساخت protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(ثابت حرف *name);
  قسمتعریف صحیح (WSAAPI *LPFN_WSASTARTUP)(لفظ_3 w_نسخہ_Requested,LPWSADATA lpWSAData);
  قسمتعریف صحیح (WSAAPI *LPFN_WSACLEANUP)(خالی);
  قسمتعریف خالی (WSAAPI *LPFN_WSASETLASTERROR)(صحیح iError);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAGETLASTERROR)(خالی);
  قسمتعریف WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(خالی);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(خالی);
  قسمتعریف FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lp_بلاک_Func);
  قسمتعریف صحیح (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(خالی);
  قسمتعریف HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_پیغام,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحیح buflen);
  قسمتعریف HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_پیغام,صحیح پورٹ_2,ثابت حرف *proto,حرف *buf,صحیح buflen);
  قسمتعریف HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحیح buflen);
  قسمتعریف HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_پیغام,صحیح نمبر_3,حرف *buf,صحیح buflen);
  قسمتعریف HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحیح buflen);
  قسمتعریف HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_پیغام,ثابت حرف *addr,صحیح len,صحیح type,حرف *buf,صحیح buflen);
  قسمتعریف صحیح (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_پیغام,طویل lEvent);
  قسمتعریف SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,ساخت sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_ڈیٹا);
  قسمتعریف WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  قسمتعریف صحیح (WSAAPI *LPFN_WSACONNECT)(SOCKET s,ثابت ساخت sockaddr *name,صحیح namelen,LPWSABUF lp_Caller_ڈیٹا,LPWSABUF lp_Callee_ڈیٹا,LPQOS lpSQOS,LPQOS lpGQOS);
  قسمتعریف WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(خالی);
  قسمتعریف صحیح (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  قسمتعریف صحیح (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_جال_Events);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_بفر,LPDWORD lpdw_بفر_لمبائی);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_بفر,LPDWORD lpdw_بفر_لمبائی);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,طویل l_جال_Events);
  قسمتعریف WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  قسمتعریف WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  قسمتعریف صحیح (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dw_Io_Control_رمز,LPVOID lpv_اندر_بفر,DWORD cb_اندر_بفر,LPVOID lpv_برآمد_بفر,DWORD cb_برآمد_بفر,LPDWORD lpcb_بائٹیں_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  قسمتعریف SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,ثابت ساخت sockaddr *name,صحیح namelen,LPWSABUF lp_Caller_ڈیٹا,LPWSABUF lp_Callee_ڈیٹا,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  قسمتعریف صحیح (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  قسمتعریف صحیح (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  قسمتعریف صحیح (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_کا_بائٹیں_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  قسمتعریف صحیح (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_ڈیٹا);
  قسمتعریف صحیح (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_کا_بائٹیں_Recvd,LPDWORD lpFlags,ساخت sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  قسمتعریف WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  قسمتعریف صحیح (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_کا_بائٹیں_بھیجا,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  قسمتعریف صحیح (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_ڈیٹا);
  قسمتعریف صحیح (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_کا_بائٹیں_بھیجا,DWORD dwFlags,ثابت ساخت sockaddr *lp_مقصد,صحیح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  قسمتعریف WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  قسمتعریف SOCKET (WSAAPI *LPFN_WSASOCKETA)(صحیح af,صحیح type,صحیح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,گروہ_3 g,DWORD dwFlags);
  قسمتعریف SOCKET (WSAAPI *LPFN_WSASOCKETW)(صحیح af,صحیح type,صحیح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,گروہ_3 g,DWORD dwFlags);
  قسمتعریف DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  قسمتعریف INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsa_پتہ,DWORD dw_پتہ_لمبائی,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_پتہ_String,LPDWORD lpdw_پتہ_String_لمبائی);
  قسمتعریف INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsa_پتہ,DWORD dw_پتہ_لمبائی,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_پتہ_String,LPDWORD lpdw_پتہ_String_لمبائی);
  قسمتعریف INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR پتہ_String,INT پتہ_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_پتہ,LPINT lp_پتہ_لمبائی);
  قسمتعریف INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR پتہ_String,INT پتہ_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_پتہ,LPINT lp_پتہ_لمبائی);
  قسمتعریف INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  قسمتعریف INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  قسمتعریف INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_لمبائی,LPWSAQUERYSETA lpqsResults);
  قسمتعریف INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_لمبائی,LPWSAQUERYSETW lpqsResults);
  قسمتعریف INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dw_Control_رمز,LPVOID lpv_اندر_بفر,DWORD cb_اندر_بفر,LPVOID lpv_برآمد_بفر,DWORD cb_برآمد_بفر,LPDWORD lpcb_بائٹیں_Returned,LPWSACOMPLETION lpCompletion);
  قسمتعریف INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  قسمتعریف INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  قسمتعریف INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  قسمتعریف INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  قسمتعریف INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_سائز,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  قسمتعریف INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_سائز,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  قسمتعریف INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_بفر_لمبائی,LPWSANAMESPACE_INFOA lpnsp_بفر);
  قسمتعریف INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_بفر_لمبائی,LPWSANAMESPACE_INFOW lpnsp_بفر);
  قسمتعریف INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_بفر_لمبائی);
  قسمتعریف INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_بفر_لمبائی);
  قسمتعریف INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  قسمتعریف INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  قسمتعریف INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#اگر_ختم

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو WSADuplicateSocket WSADuplicateSocketW
#تعریف_کرو WSAEnumProtocols WSAEnumProtocolsW
#تعریف_کرو WSAAddress_مقصد_String WSAAddress_مقصد_String_W
#تعریف_کرو WSASocket WSASocketW
#تعریف_کرو WSAString_مقصد_پتہ WSAString_مقصد_پتہ_W
#تعریف_کرو WSALookupServiceBegin WSALookupServiceBeginW
#تعریف_کرو WSALookup_Service_اگلا WSALookup_Service_اگلا_W
#تعریف_کرو WSAInstallServiceClass WSAInstallServiceClassW
#تعریف_کرو WSAGetServiceClassInfo WSAGetServiceClassInfoW
#تعریف_کرو WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#تعریف_کرو WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#تعریف_کرو WSASetService WSASetServiceW
#ورنہ
#تعریف_کرو WSADuplicateSocket WSADuplicateSocketA
#تعریف_کرو WSAEnumProtocols WSAEnumProtocolsA
#تعریف_کرو WSASocket WSASocketA
#تعریف_کرو WSAAddress_مقصد_String WSAAddress_مقصد_String_A
#تعریف_کرو WSAString_مقصد_پتہ WSAString_مقصد_پتہ_A
#تعریف_کرو WSALookupServiceBegin WSALookupServiceBeginA
#تعریف_کرو WSALookup_Service_اگلا WSALookup_Service_اگلا_A
#تعریف_کرو WSAInstallServiceClass WSAInstallServiceClassA
#تعریف_کرو WSAGetServiceClassInfo WSAGetServiceClassInfoA
#تعریف_کرو WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#تعریف_کرو WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#تعریف_کرو WSASetService WSASetServiceA
#اگر_ختم

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,ساخت sockaddr *addr,صحیح *addrlen);
  WINSOCK_API_LINKAGE صحیح WSAAPI bind(SOCKET s,ثابت ساخت sockaddr *name,صحیح namelen);
  WINSOCK_API_LINKAGE صحیح WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE صحیح WSAAPI connect(SOCKET s,ثابت ساخت sockaddr *name,صحیح namelen);
  WINSOCK_API_LINKAGE صحیح WSAAPI ioctlsocket(SOCKET s,طویل cmd,u_long *argp);
  WINSOCK_API_LINKAGE صحیح WSAAPI getpeername(SOCKET s,ساخت sockaddr *name,صحیح *namelen);
  WINSOCK_API_LINKAGE صحیح WSAAPI getsockname(SOCKET s,ساخت sockaddr *name,صحیح *namelen);
  WINSOCK_API_LINKAGE صحیح WSAAPI getsockopt(SOCKET s,صحیح level,صحیح optname,حرف *optval,صحیح *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE غیرعلامتی طویل WSAAPI inet_addr(ثابت حرف *cp);
  WINSOCK_API_LINKAGE حرف *WSAAPI inet_ntoa(ساخت اندر_addr اندر);
  WINSOCK_API_LINKAGE صحیح WSAAPI listen(SOCKET s,صحیح backlog);
  WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE صحیح WSAAPI recv(SOCKET s,حرف *buf,صحیح len,صحیح flags);
  WINSOCK_API_LINKAGE صحیح WSAAPI recvfrom(SOCKET s,حرف *buf,صحیح len,صحیح flags,ساخت sockaddr *from,صحیح *fromlen);
  WINSOCK_API_LINKAGE صحیح WSAAPI select(صحیح nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ثابت ساخت timeval *timeout);
  WINSOCK_API_LINKAGE صحیح WSAAPI send(SOCKET s,ثابت حرف *buf,صحیح len,صحیح flags);
  WINSOCK_API_LINKAGE صحیح WSAAPI sendto(SOCKET s,ثابت حرف *buf,صحیح len,صحیح flags,ثابت ساخت sockaddr *مقصد,صحیح tolen);
  WINSOCK_API_LINKAGE صحیح WSAAPI setsockopt(SOCKET s,صحیح level,صحیح optname,ثابت حرف *optval,صحیح optlen);
  WINSOCK_API_LINKAGE صحیح WSAAPI shutdown(SOCKET s,صحیح how);
  WINSOCK_API_LINKAGE SOCKET WSAAPI socket(صحیح af,صحیح type,صحیح protocol);
  WINSOCK_API_LINKAGE ساخت hostent *WSAAPI gethostbyaddr(ثابت حرف *addr,صحیح len,صحیح type);
  WINSOCK_API_LINKAGE ساخت hostent *WSAAPI gethostbyname(ثابت حرف *name);
  WINSOCK_API_LINKAGE صحیح WSAAPI gethostname(حرف *name,صحیح namelen);
  WINSOCK_API_LINKAGE ساخت servent *WSAAPI getservbyport(صحیح پورٹ_2,ثابت حرف *proto);
  WINSOCK_API_LINKAGE ساخت servent *WSAAPI getservbyname(ثابت حرف *name,ثابت حرف *proto);
  WINSOCK_API_LINKAGE ساخت protoent *WSAAPI getprotobynumber(صحیح نمبر_3);
  WINSOCK_API_LINKAGE ساخت protoent *WSAAPI getprotobyname(ثابت حرف *name);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAStartup(لفظ_3 w_نسخہ_Requested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSACleanup(خالی);
  WINSOCK_API_LINKAGE خالی WSAAPI WSASet_آخری_Error(صحیح iError);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAGet_آخری_Error(خالی);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(خالی);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAUnhookBlockingHook(خالی);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lp_بلاک_Func);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSACancelBlockingCall(خالی);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_پیغام,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحیح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Serv_By_پورٹ(HWND hWnd,u_int w_پیغام,صحیح پورٹ_2,ثابت حرف *proto,حرف *buf,صحیح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحیح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_نمبر(HWND hWnd,u_int w_پیغام,صحیح نمبر_3,حرف *buf,صحیح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحیح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_پیغام,ثابت حرف *addr,صحیح len,صحیح type,حرف *buf,صحیح buflen);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_پیغام,طویل lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,ساخت sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_ڈیٹا);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAConnect(SOCKET s,ثابت ساخت sockaddr *name,صحیح namelen,LPWSABUF lp_Caller_ڈیٹا,LPWSABUF lp_Callee_ڈیٹا,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(خالی);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAEnum_جال_Events(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_جال_Events);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_بفر,LPDWORD lpdw_بفر_لمبائی);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_بفر,LPDWORD lpdw_بفر_لمبائی);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,طویل l_جال_Events);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_نتیجہ(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSAIoctl(SOCKET s,DWORD dw_Io_Control_رمز,LPVOID lpv_اندر_بفر,DWORD cb_اندر_بفر,LPVOID lpv_برآمد_بفر,DWORD cb_برآمد_بفر,LPDWORD lpcb_بائٹیں_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoin_برگ(SOCKET s,ثابت ساخت sockaddr *name,صحیح namelen,LPWSABUF lp_Caller_ڈیٹا,LPWSABUF lp_Callee_ڈیٹا,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_کا_بائٹیں_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_ڈیٹا);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_کا_بائٹیں_Recvd,LPDWORD lpFlags,ساخت sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_کا_بائٹیں_بھیجا,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_ڈیٹا);
  WINSOCK_API_LINKAGE صحیح WSAAPI WSASend_مقصد(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_کا_بائٹیں_بھیجا,DWORD dwFlags,ثابت ساخت sockaddr *lp_مقصد,صحیح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(صحیح af,صحیح type,صحیح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,گروہ_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(صحیح af,صحیح type,صحیح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,گروہ_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWait_For_مضرب_Events(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_مقصد_String_A(LPSOCKADDR lpsa_پتہ,DWORD dw_پتہ_لمبائی,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_پتہ_String,LPDWORD lpdw_پتہ_String_لمبائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_مقصد_String_W(LPSOCKADDR lpsa_پتہ,DWORD dw_پتہ_لمبائی,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_پتہ_String,LPDWORD lpdw_پتہ_String_لمبائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_مقصد_پتہ_A(LPSTR پتہ_String,INT پتہ_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_پتہ,LPINT lp_پتہ_لمبائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_مقصد_پتہ_W(LPWSTR پتہ_String,INT پتہ_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_پتہ,LPINT lp_پتہ_لمبائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_اگلا_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_لمبائی,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_اگلا_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_لمبائی,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dw_Control_رمز,LPVOID lpv_اندر_بفر,DWORD cb_اندر_بفر,LPVOID lpv_برآمد_بفر,DWORD cb_برآمد_بفر,LPDWORD lpcb_بائٹیں_Returned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_انتہا(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_سائز,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_سائز,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_بفر_لمبائی,LPWSANAMESPACE_INFOA lpnsp_بفر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_بفر_لمبائی,LPWSANAMESPACE_INFOW lpnsp_بفر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_بفر_لمبائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_بفر_لمبائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  قسمتعریف ساخت sockaddr_اندر SOCKADDR_اندر;
  قسمتعریف ساخت sockaddr_اندر *PSOCKADDR_اندر;
  قسمتعریف ساخت sockaddr_اندر *LPSOCKADDR_اندر;

  قسمتعریف ساخت linger LINGER;
  قسمتعریف ساخت linger *PLINGER;
  قسمتعریف ساخت linger *LPLINGER;

  قسمتعریف ساخت اندر_addr اندر_ADDR;
  قسمتعریف ساخت اندر_addr *PIN_ADDR;
  قسمتعریف ساخت اندر_addr *LPIN_ADDR;

  قسمتعریف ساخت fd_set FD_SET;
  قسمتعریف ساخت fd_set *PFD_سیٹ;
  قسمتعریف ساخت fd_set *LPFD_سیٹ;

  قسمتعریف ساخت hostent HOSTENT;
  قسمتعریف ساخت hostent *PHOSTENT;
  قسمتعریف ساخت hostent *LPHOSTENT;

  قسمتعریف ساخت servent SERVENT;
  قسمتعریف ساخت servent *PSERVENT;
  قسمتعریف ساخت servent *LPSERVENT;

  قسمتعریف ساخت protoent PROTOENT;
  قسمتعریف ساخت protoent *PPROTOENT;
  قسمتعریف ساخت protoent *LPPROTOENT;

  قسمتعریف ساخت timeval TIMEVAL;
  قسمتعریف ساخت timeval *PTIMEVAL;
  قسمتعریف ساخت timeval *LPTIMEVAL;

#تعریف_کرو WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#تعریف_کرو WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#تعریف_کرو WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#تعریف_کرو WSAGETASYNCERROR(lParam) HIWORD(lParam)
#تعریف_کرو WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#تعریف_کرو WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#تعریف_کرو POLLRDNORM  0x0100
#تعریف_کرو POLLRDBAND  0x0200
#تعریف_کرو POLLIN      (POLLRDNORM | POLLRDBAND)
#تعریف_کرو POLLPRI     0x0400

#تعریف_کرو POLLWRNORM  0x0010
#تعریف_کرو POLLOUT     (POLLWRNORM)
#تعریف_کرو POLLWRBAND  0x0020

#تعریف_کرو POLLERR     0x0001
#تعریف_کرو POLLHUP     0x0002
#تعریف_کرو POLLNVAL    0x0004

قسمتعریف ساخت pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE صحیح WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_تعریف_شدہ _NEED_POPPACK
#شامل <poppack.h>
#اگر_ختم

#اگر_تعریف_شدہ IPV6STRICT
#شامل <wsipv6ok.h>
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WINSOCKAPI_
#تعریف_کرو _WINSOCKAPI_
#اگر_ختم

#اگر_تعریف_شدہ _INC_WINSOCK_H
#شامل <mswsock.h>
#اگر_ختم

#اگر_ختم
