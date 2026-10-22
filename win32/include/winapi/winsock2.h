/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#جے_بنا_تعریف _WINSOCK2API_
#تعریف_کرو _WINSOCK2API_

#جے_بنا_تعریف INCL_WINSOCK_API_TYPEDEFS
#تعریف_کرو INCL_WINSOCK_API_TYPEDEFS 0
#جے_انت

#جے_بنا_تعریف _INC_WINDOWS
#ضمن <windows.h>
#جے_انت

#جے_بنا_تعریف MAKEWORD
#تعریف_کرو MAKEWORD(کم,بلند) ((لفظ_3)(((BYTE)(کم)) | ((لفظ_3)((BYTE)(بلند))) << 8))
#جے_انت

#جے_بنا_تعریف WINSOCK_نسخہ
#تعریف_کرو WINSOCK_نسخہ MAKEWORD(2,2)
#جے_انت

#جے_بنا_تعریف WINSOCK_API_LINKAGE
#جے_تعریف_شدہ DECLSPEC_IMPORT
#تعریف_کرو WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#وإلا
#تعریف_کرو WINSOCK_API_LINKAGE
#جے_انت
#جے_انت

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف _WINSOCK_SOCKET_DEFINED
#تعریف_کرو _WINSOCK_SOCKET_DEFINED
  تعريفنوع بنانشانی حرف u_char;
  تعريفنوع بنانشانی چھوٹا u_short;
  تعريفنوع بنانشانی صحيح u_int;
  تعريفنوع بنانشانی لما u_long;
  __MINGW_EXTENSION تعريفنوع بنانشانی __int64 u_int64;
  تعريفنوع INT_PTR SOCKET;
#جے_انت

#جے_بنا_تعریف FD_SETSIZE
#تعریف_کرو FD_SETSIZE 64
#جے_انت

  تعريفنوع بنية fd_set {
    u_int fd_گنتی;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  خارجي صحيح WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#تعریف_کرو FD_CLR(fd,سیٹ) افعل { u_int __i; لكل(__i = 0;__i < ((fd_set *)(سیٹ))->fd_گنتی;__i++) { إذا (((fd_set *)(سیٹ))->fd_array[__i]==fd) { طالما (__i < ((fd_set *)(سیٹ))->fd_گنتی-1) { ((fd_set *)(سیٹ))->fd_array[__i] = ((fd_set *)(سیٹ))->fd_array[__i+1]; __i++; } ((fd_set *)(سیٹ))->fd_گنتی--; اكسر; } } } طالما(0)
#تعریف_کرو FD_SET(fd,سیٹ) افعل { u_int __i; لكل(__i = 0;__i < ((fd_set *)(سیٹ))->fd_گنتی;__i++) { إذا (((fd_set *)(سیٹ))->fd_array[__i]==(fd)) { اكسر; } } إذا (__i==((fd_set *)(سیٹ))->fd_گنتی) { إذا (((fd_set *)(سیٹ))->fd_گنتی < FD_SETSIZE) { ((fd_set *)(سیٹ))->fd_array[__i] = (fd); ((fd_set *)(سیٹ))->fd_گنتی++; } } } طالما(0)
#تعریف_کرو FD_ZERO(سیٹ) (((fd_set *)(سیٹ))->fd_گنتی=0)
#تعریف_کرو FD_ISSET(fd,سیٹ) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(سیٹ))

#جے_بنا_تعریف _TIMEVAL_DEFINED /* also in winsock[2].h */
#تعریف_کرو _TIMEVAL_DEFINED
  بنية timeval {
    لما tv_sec;
    لما tv_usec;
  };

#تعریف_کرو timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#تعریف_کرو timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#تعریف_کرو timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#جے_انت /* _TIMEVAL_DEFINED */

#تعریف_کرو IOCPARM_نقاب 0x7f
#تعریف_کرو IOC_VOID 0x20000000
#تعریف_کرو IOC_باہرلا 0x40000000
#تعریف_کرو IOC_وچ 0x80000000
#تعریف_کرو IOC_INOUT (IOC_وچ|IOC_باہرلا)

#تعریف_کرو _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#تعریف_کرو _IOR(x,y,t) (IOC_باہرلا|(((لما)حجم(t)&IOCPARM_نقاب)<<16)|((x)<<8)|(y))
#تعریف_کرو _IOW(x,y,t) (IOC_وچ|(((لما)حجم(t)&IOCPARM_نقاب)<<16)|((x)<<8)|(y))

#تعریف_کرو FIONREAD _IOR('f',127,u_long)
#تعریف_کرو FIONBIO _IOW('f',126,u_long)
#تعریف_کرو FIOASYNC _IOW('f',125,u_long)

#تعریف_کرو SIOCSHIWAT _IOW('s',0,u_long)
#تعریف_کرو SIOCGHIWAT _IOR('s',1,u_long)
#تعریف_کرو SIOCSLOWAT _IOW('s',2,u_long)
#تعریف_کرو SIOCGLOWAT _IOR('s',3,u_long)
#تعریف_کرو SIOCATMARK _IOR('s',7,u_long)

#تعریف_کرو h_addr h_addr_list[0]

  بنية hostent {
    حرف *h_name;
    حرف **h_aliases;
    چھوٹا h_addrtype;
    چھوٹا h_لمائی;
    حرف **h_addr_list;
  };

  بنية netent {
    حرف *n_name;
    حرف **n_aliases;
    چھوٹا n_addrtype;
    u_long n_net;
  };

  بنية servent {
    حرف *s_name;
    حرف **s_aliases;
#جے_تعریف_شدہ _WIN64
    حرف *s_proto;
    چھوٹا s_پورٹ;
#وإلا
    چھوٹا s_پورٹ;
    حرف *s_proto;
#جے_انت
  };

  بنية protoent {
    حرف *p_name;
    حرف **p_aliases;
    چھوٹا p_proto;
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

#جے_بنا_تعریف s_addr

  بنية وچ_addr {
    اتحاد {
      بنية { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      بنية { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#تعریف_کرو s_addr S_un.S_addr
#تعریف_کرو s_host S_un.S_un_b.s_b2
#تعریف_کرو s_net S_un.S_un_b.s_b1
#تعریف_کرو s_imp S_un.S_un_w.s_w2
#تعریف_کرو s_impno S_un.S_un_b.s_b4
#تعریف_کرو s_lh S_un.S_un_b.s_b3

#جے_انت

#تعریف_کرو وچ_CLASSA(i) (((لما)(i) & 0x80000000)==0)
#تعریف_کرو وچ_CLASSA_NET 0xff000000
#تعریف_کرو وچ_CLASSA_NSHIFT 24
#تعریف_کرو وچ_CLASSA_HOST 0x00ffffff
#تعریف_کرو وچ_CLASSA_MAX 128

#تعریف_کرو وچ_CLASSB(i) (((لما)(i) & 0xc0000000)==0x80000000)
#تعریف_کرو وچ_CLASSB_NET 0xffff0000
#تعریف_کرو وچ_CLASSB_NSHIFT 16
#تعریف_کرو وچ_CLASSB_HOST 0x0000ffff
#تعریف_کرو وچ_CLASSB_MAX 65536

#تعریف_کرو وچ_CLASSC(i) (((لما)(i) & 0xe0000000)==0xc0000000)
#تعریف_کرو وچ_CLASSC_NET 0xffffff00
#تعریف_کرو وچ_CLASSC_NSHIFT 8
#تعریف_کرو وچ_CLASSC_HOST 0x000000ff

#تعریف_کرو وچ_CLASSD(i) (((لما)(i) & 0xf0000000)==0xe0000000)
#تعریف_کرو وچ_CLASSD_NET 0xf0000000
#تعریف_کرو وچ_CLASSD_NSHIFT 28
#تعریف_کرو وچ_CLASSD_HOST 0x0fffffff
#تعریف_کرو وچ_MULTICAST(i) وچ_CLASSD(i)

#تعریف_کرو INADDR_ANY (u_long)0x00000000
#تعریف_کرو INADDR_LOOPBACK 0x7f000001
#تعریف_کرو INADDR_نشر (u_long)0xffffffff
#تعریف_کرو INADDR_NONE 0xffffffff

#تعریف_کرو ADDR_ANY INADDR_ANY

  بنية sockaddr_وچ {
    چھوٹا sin_family;
    u_short sin_پورٹ;
    بنية وچ_addr sin_addr;
    حرف sin_zero[8];
  };

#تعریف_کرو WSADESCRIPTION_LEN 256
#تعریف_کرو WSASYS_حالت_LEN 128

  تعريفنوع بنية WSAData {
    لفظ_3 w_نسخہ;
    لفظ_3 w_بلند_نسخہ;
#جے_تعریف_شدہ _WIN64
    بنانشانی چھوٹا iMaxSockets;
    بنانشانی چھوٹا iMaxUdpDg;
    حرف *lpVendorInfo;
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_حالت[WSASYS_حالت_LEN+1];
#وإلا
    حرف szDescription[WSADESCRIPTION_LEN+1];
    حرف sz_System_حالت[WSASYS_حالت_LEN+1];
    بنانشانی چھوٹا iMaxSockets;
    بنانشانی چھوٹا iMaxUdpDg;
    حرف *lpVendorInfo;
#جے_انت
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

#تعریف_کرو SO_DONTLINGER (صحيح)(~SO_LINGER)
#تعریف_کرو SO_EXCLUSIVEADDRUSE ((صحيح)(~SO_REUSEADDR))

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
#تعریف_کرو SO_MAX_پیغام_ناپ 0x2003
#تعریف_کرو SO_PROTOCOL_INFOA 0x2004
#تعریف_کرو SO_PROTOCOL_INFOW 0x2005
#جے_تعریف_شدہ UNICODE
#تعریف_کرو SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#وإلا
#تعریف_کرو SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#جے_انت
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

  بنية sockaddr {
    u_short sa_family;
    حرف sa_انکڑے[14];
  };

#تعریف_کرو _SS_MAXSIZE 128
#تعریف_کرو _SS_ALIGNSIZE (8)

#تعریف_کرو SS_PAD1_ناپ (_SS_ALIGNSIZE - حجم (چھوٹا))
#تعریف_کرو SS_PAD2_ناپ (_SS_MAXSIZE - (حجم (چھوٹا) + SS_PAD1_ناپ + _SS_ALIGNSIZE))

  بنية sockaddr_storage {
    چھوٹا ss_family;
    حرف __ss_pad1[SS_PAD1_ناپ];

    __MINGW_EXTENSION __int64 __ss_align;
    حرف __ss_pad2[SS_PAD2_ناپ];

  };

  بنية sockproto {
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

  بنية linger {
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

#تعریف_کرو پیغام_رکاوٹ 0x10

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

#جے_بنا_تعریف WSABASEERR

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
#جے_بنا_تعریف WSAHOST_NOT_لبھیا
#تعریف_کرو WSAHOST_NOT_لبھیا (WSABASEERR+1001)
#جے_انت
#جے_بنا_تعریف WSATRY_AGAIN
#تعریف_کرو WSATRY_AGAIN (WSABASEERR+1002)
#جے_انت
#جے_بنا_تعریف WSANO_RECOVERY
#تعریف_کرو WSANO_RECOVERY (WSABASEERR+1003)
#جے_انت
#جے_بنا_تعریف WSANO_انکڑے
#تعریف_کرو WSANO_انکڑے (WSABASEERR+1004)
#جے_انت

#تعریف_کرو WSAENOMORE (WSABASEERR+102)
#تعریف_کرو WSAECANCELLED (WSABASEERR+103)
#تعریف_کرو WSAEINVALIDPROCTABLE (WSABASEERR+104)
#تعریف_کرو WSAEINVALIDPROVIDER (WSABASEERR+105)
#تعریف_کرو WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#تعریف_کرو WSASYSCALLFAILURE (WSABASEERR+107)
#تعریف_کرو WSASERVICE_NOT_لبھیا (WSABASEERR+108)
#تعریف_کرو WSATYPE_NOT_لبھیا (WSABASEERR+109)
#تعریف_کرو WSA_E_NO_ہور (WSABASEERR+110)
#تعریف_کرو WSA_E_CANCELLED (WSABASEERR+111)
#تعریف_کرو WSAEREFUSED (WSABASEERR+112)
#جے_بنا_تعریف WSA_QOS_RECEIVERS
#تعریف_کرو WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#جے_انت
#جے_بنا_تعریف WSA_QOS_SENDERS
#تعریف_کرو WSA_QOS_SENDERS (WSABASEERR + 1006)
#جے_انت
#جے_بنا_تعریف WSA_QOS_NO_SENDERS
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
#جے_انت
#جے_بنا_تعریف WSA_QOS_EFILTERSTYLE
#تعریف_کرو WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#جے_انت
#جے_بنا_تعریف WSA_QOS_EFILTERTYPE
#تعریف_کرو WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#جے_انت
#جے_بنا_تعریف WSA_QOS_EFILTERCOUNT
#تعریف_کرو WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#جے_انت
#جے_بنا_تعریف WSA_QOS_EOBJLENGTH
#تعریف_کرو WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#جے_انت
#جے_بنا_تعریف WSA_QOS_EFLOWCOUNT
#تعریف_کرو WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#جے_انت
#جے_بنا_تعریف WSA_QOS_EUNKNOWNPSOBJ
#تعریف_کرو WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#جے_انت
#جے_بنا_تعریف WSA_QOS_EPOLICYOBJ
#تعریف_کرو WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#جے_انت
#جے_بنا_تعریف WSA_QOS_EFLOWDESC
#تعریف_کرو WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#جے_انت
#جے_بنا_تعریف WSA_QOS_EPSFLOWSPEC
#تعریف_کرو WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#جے_انت
#جے_بنا_تعریف WSA_QOS_EPSFILTERSPEC
#تعریف_کرو WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#جے_انت
#جے_بنا_تعریف WSA_QOS_ESDMODEOBJ
#تعریف_کرو WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#جے_انت
#جے_بنا_تعریف WSA_QOS_ESHAPERATEOBJ
#تعریف_کرو WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#جے_انت
#جے_بنا_تعریف WSA_QOS_RESERVED_PETYPE
#تعریف_کرو WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#جے_انت
#جے_انت // WSABASEERR

#تعریف_کرو h_errno WSAGet_آخری_Error()
#تعریف_کرو HOST_NOT_لبھیا WSAHOST_NOT_لبھیا
#تعریف_کرو TRY_AGAIN WSATRY_AGAIN
#تعریف_کرو NO_RECOVERY WSANO_RECOVERY
#تعریف_کرو NO_انکڑے WSANO_انکڑے

#تعریف_کرو WSANO_پتہ WSANO_انکڑے
#تعریف_کرو NO_پتہ WSANO_پتہ

#إذا 0
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
#جے_انت

#تعریف_کرو WSAAPI WINAPI
#تعریف_کرو WSAEVENT HANDLE
#تعریف_کرو LPWSAEVENT LPHANDLE
#تعریف_کرو WSAOVERLAPPED OVERLAPPED
  تعريفنوع بنية _OVERLAPPED *LPWSAOVERLAPPED;

#تعریف_کرو WSA_IO_PENDING (ERROR_IO_PENDING)
#تعریف_کرو WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#تعریف_کرو WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#تعریف_کرو WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#تعریف_کرو WSA_NOT_ENOUGH_حافظہ (ERROR_NOT_ENOUGH_حافظہ)
#تعریف_کرو WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#تعریف_کرو WSA_INVALID_EVENT ((WSAEVENT)عدم)
#تعریف_کرو WSA_ودھ_توں_ودھ_WAIT_EVENTS (ودھ_توں_ودھ_WAIT_OBJECTS)
#تعریف_کرو WSA_WAIT_FAILED (WAIT_FAILED)
#تعریف_کرو WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#تعریف_کرو WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#تعریف_کرو WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#تعریف_کرو WSA_INFINITE (INFINITE)

  تعريفنوع بنية _WSABUF {
    u_long len;
    حرف *buf;
  } WSABUF,*LPWSABUF;

#ضمن <qos.h>

  تعريفنوع بنية Quality_دا_Service {
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

  تعريفنوع بنانشانی صحيح گروہ_3;

#تعریف_کرو SG_UNCONSTRAINED_گروہ 0x01
#تعریف_کرو SG_CONSTRAINED_گروہ 0x02

  تعريفنوع بنية _WSANETWORKEVENTS {
    لما l_جال_Events;
    صحيح i_Error_کوڈ[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#جے_بنا_تعریف GUID_DEFINED
#ضمن <guiddef.h>
#جے_انت

#تعریف_کرو MAX_PROTOCOL_CHAIN 7

#تعریف_کرو ادھار_PROTOCOL 1
#تعریف_کرو LAYERED_PROTOCOL 0

  تعريفنوع بنية _WSAPROTOCOLCHAIN {
    صحيح ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#تعریف_کرو WSAPROTOCOL_LEN 255

  تعريفنوع بنية _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_اندراج_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحيح i_نسخہ;
    صحيح i_پتہ_Family;
    صحيح iMaxSockAddr;
    صحيح iMinSockAddr;
    صحيح iSocketType;
    صحيح iProtocol;
    صحيح i_Protocol_Max_وتھ;
    صحيح i_جال_Byte_ترتیب;
    صحيح iSecurityScheme;
    DWORD dw_سنیہا_ناپ;
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
    DWORD dw_Catalog_اندراج_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    صحيح i_نسخہ;
    صحيح i_پتہ_Family;
    صحيح iMaxSockAddr;
    صحيح iMinSockAddr;
    صحيح iSocketType;
    صحيح iProtocol;
    صحيح i_Protocol_Max_وتھ;
    صحيح i_جال_Byte_ترتیب;
    صحيح iSecurityScheme;
    DWORD dw_سنیہا_ناپ;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  تعريفنوع LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#وإلا
  تعريفنوع WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  تعريفنوع LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#جے_انت

#تعریف_کرو PFL_مضرب_PROTO_ENTRIES 0x00000001
#تعریف_کرو PFL_RECOMMENDED_PROTO_اندراج 0x00000002
#تعریف_کرو PFL_HIDDEN 0x00000004
#تعریف_کرو PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#تعریف_کرو XP1_CONNECTIONLESS 0x00000001
#تعریف_کرو XP1_GUARANTEED_DELIVERY 0x00000002
#تعریف_کرو XP1_GUARANTEED_ترتیب 0x00000004
#تعریف_کرو XP1_سنیہا_ORIENTED 0x00000008
#تعریف_کرو XP1_PSEUDO_دھارا 0x00000010
#تعریف_کرو XP1_GRACEFUL_CLOSE 0x00000020
#تعریف_کرو XP1_EXPEDITED_انکڑے 0x00000040
#تعریف_کرو XP1_CONNECT_انکڑے 0x00000080
#تعریف_کرو XP1_DISCONNECT_انکڑے 0x00000100
#تعریف_کرو XP1_SUPPORT_نشر 0x00000200
#تعریف_کرو XP1_SUPPORT_MULTIPOINT 0x00000400
#تعریف_کرو XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#تعریف_کرو XP1_MULTIPOINT_انکڑے_PLANE 0x00001000
#تعریف_کرو XP1_QOS_SUPPORTED 0x00002000
#تعریف_کرو XP1_رکاوٹ 0x00004000
#تعریف_کرو XP1_UNI_SEND 0x00008000
#تعریف_کرو XP1_UNI_RECV 0x00010000
#تعریف_کرو XP1_IFS_HANDLES 0x00020000
#تعریف_کرو XP1_PARTIAL_سنیہا 0x00040000

#تعریف_کرو BIGENDIAN 0x0000
#تعریف_کرو LITTLEENDIAN 0x0001

#تعریف_کرو SECURITY_PROTOCOL_NONE 0x0000

#تعریف_کرو JL_SENDER_ONLY 0x01
#تعریف_کرو JL_RECEIVER_ONLY 0x02
#تعریف_کرو JL_BOTH 0x04

#تعریف_کرو WSA_FLAG_OVERLAPPED 0x01
#تعریف_کرو WSA_FLAG_MULTIPOINT_C_جڑ 0x02
#تعریف_کرو WSA_FLAG_MULTIPOINT_C_پتی 0x04
#تعریف_کرو WSA_FLAG_MULTIPOINT_D_جڑ 0x08
#تعریف_کرو WSA_FLAG_MULTIPOINT_D_پتی 0x10

#تعریف_کرو IOC_UNIX 0x00000000
#تعریف_کرو IOC_WS2 0x08000000
#تعریف_کرو IOC_PROTOCOL 0x10000000
#تعریف_کرو IOC_VENDOR 0x18000000

#تعریف_کرو _WSAIO(x,y) (IOC_VOID|(x)|(y))
#تعریف_کرو _WSAIOR(x,y) (IOC_باہرلا|(x)|(y))
#تعریف_کرو _WSAIOW(x,y) (IOC_وچ|(x)|(y))
#تعریف_کرو _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#تعریف_کرو SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#تعریف_کرو SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#تعریف_کرو SIO_لبھو_ROUTE _WSAIOR(IOC_WS2,3)
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
#تعریف_کرو SIO_QUERY_نشانہ_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#تعریف_کرو SIO_پتہ_LIST_ترتیب_دیو _WSAIORW(IOC_WS2,25)

  تعريفنوع صحيح (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_انکڑے,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_انکڑے,گروہ_3 *g,DWORD_PTR dw_Callback_انکڑے);
  تعريفنوع فراغ (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#تعریف_کرو SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  تعريفنوع تعداد _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_پورٹ,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  تعريفنوع بنية _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    اتحاد {
      بنية {
	HWND hWnd;
	UINT u_پیغام;
	WPARAM context;
      } کھڑکی_سنیہا;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      بنية {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE h_پورٹ;
	ULONG_PTR کلید_3;
      } پورٹ;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#تعریف_کرو TH_NETDEV 0x00000001
#تعریف_کرو TH_TAPI 0x00000002

  تعريفنوع بنية sockaddr SOCKADDR;
  تعريفنوع بنية sockaddr *PSOCKADDR;
  تعريفنوع بنية sockaddr *LPSOCKADDR;
  تعريفنوع بنية sockaddr_storage SOCKADDR_STORAGE;
  تعريفنوع بنية sockaddr_storage *PSOCKADDR_STORAGE;
  تعريفنوع بنية sockaddr_storage *LPSOCKADDR_STORAGE;

#جے_بنا_تعریف ٹیگ_BLOB_DEFINED
#تعریف_کرو ٹیگ_BLOB_DEFINED
#تعریف_کرو _BLOB_DEFINED
#تعریف_کرو _LPBLOB_DEFINED
  تعريفنوع بنية _BLOB {
    ULONG cb_ناپ;
    BYTE *p_Blob_انکڑے;
  } BLOB,*LPBLOB;
#جے_انت

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

#تعریف_کرو RES_بن_ورتیا_1 (0x00000001)
#تعریف_کرو RES_FLUSH_CACHE (0x00000002)
#جے_بنا_تعریف RES_SERVICE
#تعریف_کرو RES_SERVICE (0x00000004)
#جے_انت

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

#جے_تعریف_شدہ UNICODE

#تعریف_کرو SERVICE_TYPE_قدر_SAPID SERVICE_TYPE_قدر_SAPIDW
#تعریف_کرو SERVICE_TYPE_قدر_TCPPORT SERVICE_TYPE_قدر_TCPPORTW
#تعریف_کرو SERVICE_TYPE_قدر_UDPPORT SERVICE_TYPE_قدر_UDPPORTW
#تعریف_کرو SERVICE_TYPE_قدر_OBJECTID SERVICE_TYPE_قدر_OBJECTIDW
#وإلا

#تعریف_کرو SERVICE_TYPE_قدر_SAPID SERVICE_TYPE_قدر_SAPIDA
#تعریف_کرو SERVICE_TYPE_قدر_TCPPORT SERVICE_TYPE_قدر_TCPPORTA
#تعریف_کرو SERVICE_TYPE_قدر_UDPPORT SERVICE_TYPE_قدر_UDPPORTA
#تعریف_کرو SERVICE_TYPE_قدر_OBJECTID SERVICE_TYPE_قدر_OBJECTIDA
#جے_انت

#جے_بنا_تعریف __CSADDR_DEFINED__
#تعریف_کرو __CSADDR_DEFINED__

  تعريفنوع بنية SOCKET_پتہ {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_لمائی;
  } SOCKET_پتہ_2,*PSOCKET_پتہ,*LPSOCKET_پتہ;

  تعريفنوع بنية _CSADDR_INFO {
    SOCKET_پتہ_2 LocalAddr;
    SOCKET_پتہ_2 RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#جے_انت

  تعريفنوع بنية SOCKET_پتہ_LIST {
    INT i_پتہ_گنتی;
    SOCKET_پتہ_2 پتہ_2[1];
  } SOCKET_پتہ_LIST_2,*LPSOCKET_پتہ_LIST;

  تعريفنوع بنية _AFPROTOCOLS {
    INT i_پتہ_Family;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  تعريفنوع تعداد _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  تعريفنوع بنية _WSAVersion {
    DWORD dw_نسخہ;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  تعريفنوع بنية WSAQuery_سیٹ_A {
    DWORD dw_ناپ;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخہ;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_نمبر_دا_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_نمبر_دا_Cs_Addrs;
    LPCSADDR_INFO lpcsa_بفر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  تعريفنوع بنية WSAQuery_سیٹ_W {
    DWORD dw_ناپ;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_نسخہ;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_نمبر_دا_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_نمبر_دا_Cs_Addrs;
    LPCSADDR_INFO lpcsa_بفر;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع WSAQUERYSETW WSAQUERYSET;
  تعريفنوع PWSAQUERYSETW PWSAQUERYSET;
  تعريفنوع LPWSAQUERYSETW LPWSAQUERYSET;
#وإلا
  تعريفنوع WSAQUERYSETA WSAQUERYSET;
  تعريفنوع PWSAQUERYSETA PWSAQUERYSET;
  تعريفنوع LPWSAQUERYSETA LPWSAQUERYSET;
#جے_انت

#تعریف_کرو LUP_DEEP 0x0001
#تعریف_کرو LUP_CONTAINERS 0x0002
#تعریف_کرو LUP_NOCONTAINERS 0x0004
#تعریف_کرو LUP_سبھ_توں_نیڑے 0x0008
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
#تعریف_کرو نتیجہ_IS_بدلیا 0x0020
#تعریف_کرو نتیجہ_IS_DELETED 0x0040

  تعريفنوع تعداد _WSAESETSERVICEOP {
    RNRSERVICE_رجسٹر=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  تعريفنوع بنية _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_قدر_Type;
    DWORD dw_قدر_ناپ;
    LPVOID lp_قدر;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  تعريفنوع بنية _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_قدر_Type;
    DWORD dw_قدر_ناپ;
    LPVOID lp_قدر;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع WSANSCLASSINFOW WSANSCLASSINFO;
  تعريفنوع PWSANSCLASSINFOW PWSANSCLASSINFO;
  تعريفنوع LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#وإلا
  تعريفنوع WSANSCLASSINFOA WSANSCLASSINFO;
  تعريفنوع PWSANSCLASSINFOA PWSANSCLASSINFO;
  تعريفنوع LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#جے_انت

  تعريفنوع بنية _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_گنتی;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  تعريفنوع بنية _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_گنتی;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  تعريفنوع PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  تعريفنوع LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#وإلا
  تعريفنوع WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  تعريفنوع PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  تعريفنوع LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#جے_انت

  تعريفنوع بنية _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_سرگرم;
    DWORD dw_نسخہ;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  تعريفنوع بنية _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_سرگرم;
    DWORD dw_نسخہ;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  تعريفنوع PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  تعريفنوع LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#وإلا
  تعريفنوع WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  تعريفنوع PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  تعريفنوع LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#جے_انت

#إذا INCL_WINSOCK_API_TYPEDEFS
#جے_تعریف_شدہ UNICODE
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
#وإلا
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
#جے_انت

  تعريفنوع SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,بنية sockaddr *addr,صحيح *addrlen);
  تعريفنوع صحيح (WSAAPI *LPFN_BIND)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  تعريفنوع صحيح (WSAAPI *LPFN_CONNECT)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,لما cmd,u_long *argp);
  تعريفنوع صحيح (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  تعريفنوع صحيح (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,صحيح level,صحيح optname,حرف *optval,صحيح *optlen);
  تعريفنوع u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  تعريفنوع u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  تعريفنوع بنانشانی لما (WSAAPI *LPFN_INET_ADDR)(ثابت حرف *cp);
  تعريفنوع حرف *(WSAAPI *LPFN_INET_NTOA)(بنية وچ_addr وچ);
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
  تعريفنوع بنية servent *(WSAAPI *LPFN_GETSERVBYPORT)(صحيح پورٹ_2,ثابت حرف *proto);
  تعريفنوع بنية servent *(WSAAPI *LPFN_GETSERVBYNAME)(ثابت حرف *name,ثابت حرف *proto);
  تعريفنوع بنية protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(صحيح نمبر_3);
  تعريفنوع بنية protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(ثابت حرف *name);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASTARTUP)(لفظ_3 w_نسخہ_Requested,LPWSADATA lpWSAData);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACLEANUP)(فراغ);
  تعريفنوع فراغ (WSAAPI *LPFN_WSASETLASTERROR)(صحيح iError);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAGETLASTERROR)(فراغ);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(فراغ);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(فراغ);
  تعريفنوع FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lp_بلاک_Func);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(فراغ);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_پیغام,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_پیغام,صحيح پورٹ_2,ثابت حرف *proto,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_پیغام,صحيح نمبر_3,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحيح buflen);
  تعريفنوع HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_پیغام,ثابت حرف *addr,صحيح len,صحيح type,حرف *buf,صحيح buflen);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_پیغام,لما lEvent);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,بنية sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_انکڑے);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  تعريفنوع صحيح (WSAAPI *LPFN_WSACONNECT)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_انکڑے,LPWSABUF lp_Callee_انکڑے,LPQOS lpSQOS,LPQOS lpGQOS);
  تعريفنوع WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(فراغ);
  تعريفنوع صحيح (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  تعريفنوع صحيح (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_جال_Events);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_بفر,LPDWORD lpdw_بفر_لمائی);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_بفر,LPDWORD lpdw_بفر_لمائی);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,لما l_جال_Events);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  تعريفنوع صحيح (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dw_Io_Control_کوڈ,LPVOID lpv_وچ_بفر,DWORD cb_وچ_بفر,LPVOID lpv_باہرلا_بفر,DWORD cb_باہرلا_بفر,LPDWORD lpcb_بائٹاں_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_انکڑے,LPWSABUF lp_Callee_انکڑے,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  تعريفنوع صحيح (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  تعريفنوع صحيح (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_دا_بائٹاں_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_انکڑے);
  تعريفنوع صحيح (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_دا_بائٹاں_Recvd,LPDWORD lpFlags,بنية sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_دا_بائٹاں_گھلیا,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_انکڑے);
  تعريفنوع صحيح (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_دا_بائٹاں_گھلیا,DWORD dwFlags,ثابت بنية sockaddr *lp_منزل,صحيح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  تعريفنوع WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSASOCKETA)(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,گروہ_3 g,DWORD dwFlags);
  تعريفنوع SOCKET (WSAAPI *LPFN_WSASOCKETW)(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,گروہ_3 g,DWORD dwFlags);
  تعريفنوع DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  تعريفنوع INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsa_پتہ,DWORD dw_پتہ_لمائی,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_پتہ_String,LPDWORD lpdw_پتہ_String_لمائی);
  تعريفنوع INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsa_پتہ,DWORD dw_پتہ_لمائی,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_پتہ_String,LPDWORD lpdw_پتہ_String_لمائی);
  تعريفنوع INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR پتہ_String,INT پتہ_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_پتہ,LPINT lp_پتہ_لمائی);
  تعريفنوع INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR پتہ_String,INT پتہ_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_پتہ,LPINT lp_پتہ_لمائی);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_لمائی,LPWSAQUERYSETA lpqsResults);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_لمائی,LPWSAQUERYSETW lpqsResults);
  تعريفنوع INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dw_Control_کوڈ,LPVOID lpv_وچ_بفر,DWORD cb_وچ_بفر,LPVOID lpv_باہرلا_بفر,DWORD cb_باہرلا_بفر,LPDWORD lpcb_بائٹاں_Returned,LPWSACOMPLETION lpCompletion);
  تعريفنوع INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  تعريفنوع INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ناپ,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ناپ,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  تعريفنوع INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_بفر_لمائی,LPWSANAMESPACE_INFOA lpnsp_بفر);
  تعريفنوع INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_بفر_لمائی,LPWSANAMESPACE_INFOW lpnsp_بفر);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_بفر_لمائی);
  تعريفنوع INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_بفر_لمائی);
  تعريفنوع INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  تعريفنوع INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  تعريفنوع INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو WSADuplicateSocket WSADuplicateSocketW
#تعریف_کرو WSAEnumProtocols WSAEnumProtocolsW
#تعریف_کرو WSAAddress_منزل_String WSAAddress_منزل_String_W
#تعریف_کرو WSASocket WSASocketW
#تعریف_کرو WSAString_منزل_پتہ WSAString_منزل_پتہ_W
#تعریف_کرو WSALookupServiceBegin WSALookupServiceBeginW
#تعریف_کرو WSALookup_Service_اگلا WSALookup_Service_اگلا_W
#تعریف_کرو WSAInstallServiceClass WSAInstallServiceClassW
#تعریف_کرو WSAGetServiceClassInfo WSAGetServiceClassInfoW
#تعریف_کرو WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#تعریف_کرو WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#تعریف_کرو WSASetService WSASetServiceW
#وإلا
#تعریف_کرو WSADuplicateSocket WSADuplicateSocketA
#تعریف_کرو WSAEnumProtocols WSAEnumProtocolsA
#تعریف_کرو WSASocket WSASocketA
#تعریف_کرو WSAAddress_منزل_String WSAAddress_منزل_String_A
#تعریف_کرو WSAString_منزل_پتہ WSAString_منزل_پتہ_A
#تعریف_کرو WSALookupServiceBegin WSALookupServiceBeginA
#تعریف_کرو WSALookup_Service_اگلا WSALookup_Service_اگلا_A
#تعریف_کرو WSAInstallServiceClass WSAInstallServiceClassA
#تعریف_کرو WSAGetServiceClassInfo WSAGetServiceClassInfoA
#تعریف_کرو WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#تعریف_کرو WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#تعریف_کرو WSASetService WSASetServiceA
#جے_انت

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,بنية sockaddr *addr,صحيح *addrlen);
  WINSOCK_API_LINKAGE صحيح WSAAPI bind(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE صحيح WSAAPI connect(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI ioctlsocket(SOCKET s,لما cmd,u_long *argp);
  WINSOCK_API_LINKAGE صحيح WSAAPI getpeername(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI getsockname(SOCKET s,بنية sockaddr *name,صحيح *namelen);
  WINSOCK_API_LINKAGE صحيح WSAAPI getsockopt(SOCKET s,صحيح level,صحيح optname,حرف *optval,صحيح *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE بنانشانی لما WSAAPI inet_addr(ثابت حرف *cp);
  WINSOCK_API_LINKAGE حرف *WSAAPI inet_ntoa(بنية وچ_addr وچ);
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
  WINSOCK_API_LINKAGE بنية servent *WSAAPI getservbyport(صحيح پورٹ_2,ثابت حرف *proto);
  WINSOCK_API_LINKAGE بنية servent *WSAAPI getservbyname(ثابت حرف *name,ثابت حرف *proto);
  WINSOCK_API_LINKAGE بنية protoent *WSAAPI getprotobynumber(صحيح نمبر_3);
  WINSOCK_API_LINKAGE بنية protoent *WSAAPI getprotobyname(ثابت حرف *name);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAStartup(لفظ_3 w_نسخہ_Requested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACleanup(فراغ);
  WINSOCK_API_LINKAGE فراغ WSAAPI WSASet_آخری_Error(صحيح iError);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAGet_آخری_Error(فراغ);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(فراغ);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAUnhookBlockingHook(فراغ);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lp_بلاک_Func);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACancelBlockingCall(فراغ);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_پیغام,ثابت حرف *name,ثابت حرف *proto,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Serv_By_پورٹ(HWND hWnd,u_int w_پیغام,صحيح پورٹ_2,ثابت حرف *proto,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_نمبر(HWND hWnd,u_int w_پیغام,صحيح نمبر_3,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_پیغام,ثابت حرف *name,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_پیغام,ثابت حرف *addr,صحيح len,صحيح type,حرف *buf,صحيح buflen);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_پیغام,لما lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,بنية sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_انکڑے);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAConnect(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_انکڑے,LPWSABUF lp_Callee_انکڑے,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(فراغ);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnum_جال_Events(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_جال_Events);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_بفر,LPDWORD lpdw_بفر_لمائی);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_بفر,LPDWORD lpdw_بفر_لمائی);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,لما l_جال_Events);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_نتیجہ(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSAIoctl(SOCKET s,DWORD dw_Io_Control_کوڈ,LPVOID lpv_وچ_بفر,DWORD cb_وچ_بفر,LPVOID lpv_باہرلا_بفر,DWORD cb_باہرلا_بفر,LPDWORD lpcb_بائٹاں_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoin_پتی(SOCKET s,ثابت بنية sockaddr *name,صحيح namelen,LPWSABUF lp_Caller_انکڑے,LPWSABUF lp_Callee_انکڑے,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_دا_بائٹاں_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_انکڑے);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_دا_بائٹاں_Recvd,LPDWORD lpFlags,بنية sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_دا_بائٹاں_گھلیا,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_انکڑے);
  WINSOCK_API_LINKAGE صحيح WSAAPI WSASend_منزل(SOCKET s,LPWSABUF lpBuffers,DWORD dw_بفر_گنتی,LPDWORD lp_نمبر_دا_بائٹاں_گھلیا,DWORD dwFlags,ثابت بنية sockaddr *lp_منزل,صحيح iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,گروہ_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(صحيح af,صحيح type,صحيح protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,گروہ_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWait_For_مضرب_Events(DWORD cEvents,ثابت WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_منزل_String_A(LPSOCKADDR lpsa_پتہ,DWORD dw_پتہ_لمائی,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_پتہ_String,LPDWORD lpdw_پتہ_String_لمائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_منزل_String_W(LPSOCKADDR lpsa_پتہ,DWORD dw_پتہ_لمائی,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_پتہ_String,LPDWORD lpdw_پتہ_String_لمائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_منزل_پتہ_A(LPSTR پتہ_String,INT پتہ_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_پتہ,LPINT lp_پتہ_لمائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_منزل_پتہ_W(LPWSTR پتہ_String,INT پتہ_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_پتہ,LPINT lp_پتہ_لمائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_اگلا_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_لمائی,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_اگلا_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_بفر_لمائی,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dw_Control_کوڈ,LPVOID lpv_وچ_بفر,DWORD cb_وچ_بفر,LPVOID lpv_باہرلا_بفر,DWORD cb_باہرلا_بفر,LPDWORD lpcb_بائٹاں_Returned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_سرا(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ناپ,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_ناپ,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_بفر_لمائی,LPWSANAMESPACE_INFOA lpnsp_بفر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_بفر_لمائی,LPWSANAMESPACE_INFOW lpnsp_بفر);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_بفر_لمائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_بفر_لمائی);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  تعريفنوع بنية sockaddr_وچ SOCKADDR_وچ;
  تعريفنوع بنية sockaddr_وچ *PSOCKADDR_وچ;
  تعريفنوع بنية sockaddr_وچ *LPSOCKADDR_وچ;

  تعريفنوع بنية linger LINGER;
  تعريفنوع بنية linger *PLINGER;
  تعريفنوع بنية linger *LPLINGER;

  تعريفنوع بنية وچ_addr وچ_ADDR;
  تعريفنوع بنية وچ_addr *PIN_ADDR;
  تعريفنوع بنية وچ_addr *LPIN_ADDR;

  تعريفنوع بنية fd_set FD_SET;
  تعريفنوع بنية fd_set *PFD_سیٹ;
  تعريفنوع بنية fd_set *LPFD_سیٹ;

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

تعريفنوع بنية pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE صحيح WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#جے_تعریف_شدہ __cplusplus
}
#جے_انت

#جے_تعریف_شدہ _NEED_POPPACK
#ضمن <poppack.h>
#جے_انت

#جے_تعریف_شدہ IPV6STRICT
#ضمن <wsipv6ok.h>
#جے_انت

#جے_بنا_تعریف _WINSOCKAPI_
#تعریف_کرو _WINSOCKAPI_
#جے_انت

#جے_تعریف_شدہ _INC_WINSOCK_H
#ضمن <mswsock.h>
#جے_انت

#جے_انت
