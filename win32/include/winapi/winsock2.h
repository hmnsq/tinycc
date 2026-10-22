/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#ifndef _WINSOCK2API_
#define _WINSOCK2API_

#ifndef INCL_WINSOCK_API_TYPEDEFS
#define INCL_WINSOCK_API_TYPEDEFS 0
#endif

#ifndef _INC_WINDOWS
#அந்தர்பாவ <windows.h>
#endif

#ifndef MAKEWORD
#define MAKEWORD(கீழ்,உயர்வு) ((WORD)(((BYTE)(கீழ்)) | ((WORD)((BYTE)(உயர்வு))) << 8))
#endif

#ifndef WINSOCK_VERSION
#define WINSOCK_VERSION MAKEWORD(2,2)
#endif

#ifndef WINSOCK_API_LINKAGE
#ifdef DECLSPEC_IMPORT
#define WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#இல்லையெனில்
#define WINSOCK_API_LINKAGE
#endif
#endif

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef _WINSOCK_SOCKET_DEFINED
#define _WINSOCK_SOCKET_DEFINED
  வகைவரை unsigned எழுத்து u_char;
  வகைவரை unsigned short u_short;
  வகைவரை unsigned முழு u_int;
  வகைவரை unsigned long u_long;
  __MINGW_EXTENSION வகைவரை unsigned __int64 u_int64;
  வகைவரை INT_PTR SOCKET;
#endif

#ifndef FD_SETSIZE
#define FD_SETSIZE 64
#endif

  வகைவரை கட்டமைப்பு fd_set {
    u_int fd_மொத்தம்;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  வெளி முழு WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#define FD_CLR(fd,set) செய் { u_int __i; க்கு(__i = 0;__i < ((fd_set *)(set))->fd_மொத்தம்;__i++) { எனில் (((fd_set *)(set))->fd_array[__i]==fd) { போது (__i < ((fd_set *)(set))->fd_மொத்தம்-1) { ((fd_set *)(set))->fd_array[__i] = ((fd_set *)(set))->fd_array[__i+1]; __i++; } ((fd_set *)(set))->fd_மொத்தம்--; நிறுத்து; } } } போது(0)
#define FD_SET(fd,set) செய் { u_int __i; க்கு(__i = 0;__i < ((fd_set *)(set))->fd_மொத்தம்;__i++) { எனில் (((fd_set *)(set))->fd_array[__i]==(fd)) { நிறுத்து; } } எனில் (__i==((fd_set *)(set))->fd_மொத்தம்) { எனில் (((fd_set *)(set))->fd_மொத்தம் < FD_SETSIZE) { ((fd_set *)(set))->fd_array[__i] = (fd); ((fd_set *)(set))->fd_மொத்தம்++; } } } போது(0)
#define FD_ZERO(set) (((fd_set *)(set))->fd_மொத்தம்=0)
#define FD_ISSET(fd,set) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(set))

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
  கட்டமைப்பு timeval {
    long tv_sec;
    long tv_usec;
  };

#define timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#define timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#endif /* _TIMEVAL_DEFINED */

#define IOCPARM_MASK 0x7f
#define IOC_VOID 0x20000000
#define IOC_OUT 0x40000000
#define IOC_IN 0x80000000
#define IOC_INOUT (IOC_IN|IOC_OUT)

#define _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#define _IOR(x,y,t) (IOC_OUT|(((long)அளவு(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#define _IOW(x,y,t) (IOC_IN|(((long)அளவு(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

#define FIONREAD _IOR('f',127,u_long)
#define FIONBIO _IOW('f',126,u_long)
#define FIOASYNC _IOW('f',125,u_long)

#define SIOCSHIWAT _IOW('s',0,u_long)
#define SIOCGHIWAT _IOR('s',1,u_long)
#define SIOCSLOWAT _IOW('s',2,u_long)
#define SIOCGLOWAT _IOR('s',3,u_long)
#define SIOCATMARK _IOR('s',7,u_long)

#define h_addr h_addr_list[0]

  கட்டமைப்பு hostent {
    எழுத்து *h_name;
    எழுத்து **h_aliases;
    short h_addrtype;
    short h_length;
    எழுத்து **h_addr_list;
  };

  கட்டமைப்பு netent {
    எழுத்து *n_name;
    எழுத்து **n_aliases;
    short n_addrtype;
    u_long n_net;
  };

  கட்டமைப்பு servent {
    எழுத்து *s_name;
    எழுத்து **s_aliases;
#ifdef _WIN64
    எழுத்து *s_proto;
    short s_port;
#இல்லையெனில்
    short s_port;
    எழுத்து *s_proto;
#endif
  };

  கட்டமைப்பு protoent {
    எழுத்து *p_name;
    எழுத்து **p_aliases;
    short p_proto;
  };

#define IPPROTO_IP 0
#define IPPROTO_HOPOPTS 0
#define IPPROTO_ICMP 1
#define IPPROTO_IGMP 2
#define IPPROTO_GGP 3
#define IPPROTO_IPV4 4
#define IPPROTO_TCP 6
#define IPPROTO_PUP 12
#define IPPROTO_UDP 17
#define IPPROTO_IDP 22
#define IPPROTO_IPV6 41
#define IPPROTO_ROUTING 43
#define IPPROTO_FRAGMENT 44
#define IPPROTO_ESP 50
#define IPPROTO_AH 51
#define IPPROTO_ICMPV6 58
#define IPPROTO_NONE 59
#define IPPROTO_DSTOPTS 60
#define IPPROTO_ND 77
#define IPPROTO_ICLFXBM 78

#define IPPROTO_RAW 255
#define IPPROTO_MAX 256

#define IPPORT_ECHO 7
#define IPPORT_DISCARD 9
#define IPPORT_SYSTAT 11
#define IPPORT_DAYTIME 13
#define IPPORT_NETSTAT 15
#define IPPORT_FTP 21
#define IPPORT_TELNET 23
#define IPPORT_SMTP 25
#define IPPORT_TIMESERVER 37
#define IPPORT_NAMESERVER 42
#define IPPORT_WHOIS 43
#define IPPORT_MTP 57

#define IPPORT_TFTP 69
#define IPPORT_RJE 77
#define IPPORT_FINGER 79
#define IPPORT_TTYLINK 87
#define IPPORT_SUPDUP 95

#define IPPORT_EXECSERVER 512
#define IPPORT_LOGINSERVER 513
#define IPPORT_CMDSERVER 514
#define IPPORT_EFSSERVER 520

#define IPPORT_BIFFUDP 512
#define IPPORT_WHOSERVER 513
#define IPPORT_ROUTESERVER 520

#define IPPORT_RESERVED 1024

#define IMPLINK_IP 155
#define IMPLINK_LOWEXPER 156
#define IMPLINK_HIGHEXPER 158

#ifndef s_addr

  கட்டமைப்பு in_addr {
    ஒன்றிப்பு {
      கட்டமைப்பு { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      கட்டமைப்பு { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#define s_addr S_un.S_addr
#define s_host S_un.S_un_b.s_b2
#define s_net S_un.S_un_b.s_b1
#define s_imp S_un.S_un_w.s_w2
#define s_impno S_un.S_un_b.s_b4
#define s_lh S_un.S_un_b.s_b3

#endif

#define IN_CLASSA(i) (((long)(i) & 0x80000000)==0)
#define IN_CLASSA_NET 0xff000000
#define IN_CLASSA_NSHIFT 24
#define IN_CLASSA_HOST 0x00ffffff
#define IN_CLASSA_MAX 128

#define IN_CLASSB(i) (((long)(i) & 0xc0000000)==0x80000000)
#define IN_CLASSB_NET 0xffff0000
#define IN_CLASSB_NSHIFT 16
#define IN_CLASSB_HOST 0x0000ffff
#define IN_CLASSB_MAX 65536

#define IN_CLASSC(i) (((long)(i) & 0xe0000000)==0xc0000000)
#define IN_CLASSC_NET 0xffffff00
#define IN_CLASSC_NSHIFT 8
#define IN_CLASSC_HOST 0x000000ff

#define IN_CLASSD(i) (((long)(i) & 0xf0000000)==0xe0000000)
#define IN_CLASSD_NET 0xf0000000
#define IN_CLASSD_NSHIFT 28
#define IN_CLASSD_HOST 0x0fffffff
#define IN_MULTICAST(i) IN_CLASSD(i)

#define INADDR_ANY (u_long)0x00000000
#define INADDR_LOOPBACK 0x7f000001
#define INADDR_BROADCAST (u_long)0xffffffff
#define INADDR_NONE 0xffffffff

#define ADDR_ANY INADDR_ANY

  கட்டமைப்பு sockaddr_in {
    short sin_family;
    u_short sin_port;
    கட்டமைப்பு in_addr sin_addr;
    எழுத்து sin_zero[8];
  };

#define WSADESCRIPTION_LEN 256
#define WSASYS_STATUS_LEN 128

  வகைவரை கட்டமைப்பு WSAData {
    WORD wVersion;
    WORD w_உயர்வு_Version;
#ifdef _WIN64
    unsigned short iMaxSockets;
    unsigned short iMaxUdpDg;
    எழுத்து *lpVendorInfo;
    எழுத்து szDescription[WSADESCRIPTION_LEN+1];
    எழுத்து szSystemStatus[WSASYS_STATUS_LEN+1];
#இல்லையெனில்
    எழுத்து szDescription[WSADESCRIPTION_LEN+1];
    எழுத்து szSystemStatus[WSASYS_STATUS_LEN+1];
    unsigned short iMaxSockets;
    unsigned short iMaxUdpDg;
    எழுத்து *lpVendorInfo;
#endif
  } WSADATA,*LPWSADATA;

#define INVALID_SOCKET (SOCKET)(~0)
#define SOCKET_ERROR (-1)

#define FROM_PROTOCOL_INFO (-1)

#define SOCK_STREAM 1
#define SOCK_DGRAM 2
#define SOCK_RAW 3
#define SOCK_RDM 4
#define SOCK_SEQPACKET 5

#define SO_DEBUG 0x0001
#define SO_ACCEPTCONN 0x0002
#define SO_REUSEADDR 0x0004
#define SO_KEEPALIVE 0x0008
#define SO_DONTROUTE 0x0010
#define SO_BROADCAST 0x0020
#define SO_USELOOPBACK 0x0040
#define SO_LINGER 0x0080
#define SO_OOBINLINE 0x0100

#define SO_DONTLINGER (முழு)(~SO_LINGER)
#define SO_EXCLUSIVEADDRUSE ((முழு)(~SO_REUSEADDR))

#define SO_SNDBUF 0x1001
#define SO_RCVBUF 0x1002
#define SO_SNDLOWAT 0x1003
#define SO_RCVLOWAT 0x1004
#define SO_SNDTIMEO 0x1005
#define SO_RCVTIMEO 0x1006
#define SO_ERROR 0x1007
#define SO_TYPE 0x1008

#define SO_GROUP_ID 0x2001
#define SO_GROUP_PRIORITY 0x2002
#define SO_MAX_செய்தி_SIZE 0x2003
#define SO_PROTOCOL_INFOA 0x2004
#define SO_PROTOCOL_INFOW 0x2005
#ifdef UNICODE
#define SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#இல்லையெனில்
#define SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#endif
#define PVD_CONFIG 0x3001
#define SO_CONDITIONAL_ACCEPT 0x3002

#define TCP_NODELAY 0x0001

#define AF_UNSPEC 0

#define AF_UNIX 1
#define AF_INET 2
#define AF_IMPLINK 3
#define AF_PUP 4
#define AF_CHAOS 5
#define AF_NS 6
#define AF_IPX AF_NS
#define AF_ISO 7
#define AF_OSI AF_ISO
#define AF_ECMA 8
#define AF_DATAKIT 9
#define AF_CCITT 10
#define AF_SNA 11
#define AF_DECnet 12
#define AF_DLI 13
#define AF_LAT 14
#define AF_HYLINK 15
#define AF_APPLETALK 16
#define AF_NETBIOS 17
#define AF_VOICEVIEW 18
#define AF_FIREFOX 19
#define AF_UNKNOWN1 20
#define AF_BAN 21
#define AF_ATM 22
#define AF_INET6 23
#define AF_CLUSTER 24
#define AF_12844 25
#define AF_IRDA 26
#define AF_NETDES 28
#define AF_TCNPROCESS 29
#define AF_TCNMESSAGE 30
#define AF_ICLFXBM 31

#define AF_MAX 32

  கட்டமைப்பு sockaddr {
    u_short sa_family;
    எழுத்து sa_data[14];
  };

#define _SS_MAXSIZE 128
#define _SS_ALIGNSIZE (8)

#define _SS_PAD1SIZE (_SS_ALIGNSIZE - அளவு (short))
#define _SS_PAD2SIZE (_SS_MAXSIZE - (அளவு (short) + _SS_PAD1SIZE + _SS_ALIGNSIZE))

  கட்டமைப்பு sockaddr_storage {
    short ss_family;
    எழுத்து __ss_pad1[_SS_PAD1SIZE];

    __MINGW_EXTENSION __int64 __ss_align;
    எழுத்து __ss_pad2[_SS_PAD2SIZE];

  };

  கட்டமைப்பு sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#define PF_UNSPEC AF_UNSPEC
#define PF_UNIX AF_UNIX
#define PF_INET AF_INET
#define PF_IMPLINK AF_IMPLINK
#define PF_PUP AF_PUP
#define PF_CHAOS AF_CHAOS
#define PF_NS AF_NS
#define PF_IPX AF_IPX
#define PF_ISO AF_ISO
#define PF_OSI AF_OSI
#define PF_ECMA AF_ECMA
#define PF_DATAKIT AF_DATAKIT
#define PF_CCITT AF_CCITT
#define PF_SNA AF_SNA
#define PF_DECnet AF_DECnet
#define PF_DLI AF_DLI
#define PF_LAT AF_LAT
#define PF_HYLINK AF_HYLINK
#define PF_APPLETALK AF_APPLETALK
#define PF_VOICEVIEW AF_VOICEVIEW
#define PF_FIREFOX AF_FIREFOX
#define PF_UNKNOWN1 AF_UNKNOWN1
#define PF_BAN AF_BAN
#define PF_ATM AF_ATM
#define PF_INET6 AF_INET6

#define PF_MAX AF_MAX

  கட்டமைப்பு linger {
    u_short l_onoff;
    u_short l_linger;
  };

#define SOL_SOCKET 0xffff

#define SOMAXCONN 0x7fffffff

#define செய்தி_OOB 0x1
#define செய்தி_PEEK 0x2
#define செய்தி_DONTROUTE 0x4
#define செய்தி_WAITALL 0x8

#define செய்தி_PARTIAL 0x8000

#define செய்தி_INTERRUPT 0x10

#define செய்தி_MAXIOVLEN 16

#define MAXGETHOSTSTRUCT 1024

#define FD_READ_BIT 0
#define FD_READ (1 << FD_READ_BIT)

#define FD_WRITE_BIT 1
#define FD_WRITE (1 << FD_WRITE_BIT)

#define FD_OOB_BIT 2
#define FD_OOB (1 << FD_OOB_BIT)

#define FD_ACCEPT_BIT 3
#define FD_ACCEPT (1 << FD_ACCEPT_BIT)

#define FD_CONNECT_BIT 4
#define FD_CONNECT (1 << FD_CONNECT_BIT)

#define FD_CLOSE_BIT 5
#define FD_CLOSE (1 << FD_CLOSE_BIT)

#define FD_QOS_BIT 6
#define FD_QOS (1 << FD_QOS_BIT)

#define FD_GROUP_QOS_BIT 7
#define FD_GROUP_QOS (1 << FD_GROUP_QOS_BIT)

#define FD_ROUTING_INTERFACE_CHANGE_BIT 8
#define FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_BIT)

#define FD_ADDRESS_LIST_CHANGE_BIT 9
#define FD_ADDRESS_LIST_CHANGE (1 << FD_ADDRESS_LIST_CHANGE_BIT)

#define FD_MAX_EVENTS 10
#define FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#ifndef WSABASEERR

#define WSABASEERR 10000

#define WSAEINTR (WSABASEERR+4)
#define WSAEBADF (WSABASEERR+9)
#define WSAEACCES (WSABASEERR+13)
#define WSAEFAULT (WSABASEERR+14)
#define WSAEINVAL (WSABASEERR+22)
#define WSAEMFILE (WSABASEERR+24)

#define WSAEWOULDBLOCK (WSABASEERR+35)
#define WSAEINPROGRESS (WSABASEERR+36)
#define WSAEALREADY (WSABASEERR+37)
#define WSAENOTSOCK (WSABASEERR+38)
#define WSAEDESTADDRREQ (WSABASEERR+39)
#define WSAEMSGSIZE (WSABASEERR+40)
#define WSAEPROTOTYPE (WSABASEERR+41)
#define WSAENOPROTOOPT (WSABASEERR+42)
#define WSAEPROTONOSUPPORT (WSABASEERR+43)
#define WSAESOCKTNOSUPPORT (WSABASEERR+44)
#define WSAEOPNOTSUPP (WSABASEERR+45)
#define WSAEPFNOSUPPORT (WSABASEERR+46)
#define WSAEAFNOSUPPORT (WSABASEERR+47)
#define WSAEADDRINUSE (WSABASEERR+48)
#define WSAEADDRNOTAVAIL (WSABASEERR+49)
#define WSAENETDOWN (WSABASEERR+50)
#define WSAENETUNREACH (WSABASEERR+51)
#define WSAENETRESET (WSABASEERR+52)
#define WSAECONNABORTED (WSABASEERR+53)
#define WSAECONNRESET (WSABASEERR+54)
#define WSAENOBUFS (WSABASEERR+55)
#define WSAEISCONN (WSABASEERR+56)
#define WSAENOTCONN (WSABASEERR+57)
#define WSAESHUTDOWN (WSABASEERR+58)
#define WSAETOOMANYREFS (WSABASEERR+59)
#define WSAETIMEDOUT (WSABASEERR+60)
#define WSAECONNREFUSED (WSABASEERR+61)
#define WSAELOOP (WSABASEERR+62)
#define WSAENAMETOOLONG (WSABASEERR+63)
#define WSAEHOSTDOWN (WSABASEERR+64)
#define WSAEHOSTUNREACH (WSABASEERR+65)
#define WSAENOTEMPTY (WSABASEERR+66)
#define WSAEPROCLIM (WSABASEERR+67)
#define WSAEUSERS (WSABASEERR+68)
#define WSAEDQUOT (WSABASEERR+69)
#define WSAESTALE (WSABASEERR+70)
#define WSAEREMOTE (WSABASEERR+71)

#define WSASYSNOTREADY (WSABASEERR+91)
#define WSAVERNOTSUPPORTED (WSABASEERR+92)
#define WSANOTINITIALISED (WSABASEERR+93)
#define WSAEDISCON (WSABASEERR+101)
#ifndef WSAHOST_NOT_FOUND
#define WSAHOST_NOT_FOUND (WSABASEERR+1001)
#endif
#ifndef WSATRY_AGAIN
#define WSATRY_AGAIN (WSABASEERR+1002)
#endif
#ifndef WSANO_RECOVERY
#define WSANO_RECOVERY (WSABASEERR+1003)
#endif
#ifndef WSANO_DATA
#define WSANO_DATA (WSABASEERR+1004)
#endif

#define WSAENOMORE (WSABASEERR+102)
#define WSAECANCELLED (WSABASEERR+103)
#define WSAEINVALIDPROCTABLE (WSABASEERR+104)
#define WSAEINVALIDPROVIDER (WSABASEERR+105)
#define WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#define WSASYSCALLFAILURE (WSABASEERR+107)
#define WSASERVICE_NOT_FOUND (WSABASEERR+108)
#define WSATYPE_NOT_FOUND (WSABASEERR+109)
#define WSA_E_NO_MORE (WSABASEERR+110)
#define WSA_E_CANCELLED (WSABASEERR+111)
#define WSAEREFUSED (WSABASEERR+112)
#ifndef WSA_QOS_RECEIVERS
#define WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#endif
#ifndef WSA_QOS_SENDERS
#define WSA_QOS_SENDERS (WSABASEERR + 1006)
#endif
#ifndef WSA_QOS_NO_SENDERS
#define WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#define WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#define WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#define WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#define WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#define WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#define WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#define WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#define WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#define WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#define WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#define WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#endif
#ifndef WSA_QOS_EFILTERSTYLE
#define WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#endif
#ifndef WSA_QOS_EFILTERTYPE
#define WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#endif
#ifndef WSA_QOS_EFILTERCOUNT
#define WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#endif
#ifndef WSA_QOS_EOBJLENGTH
#define WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#endif
#ifndef WSA_QOS_EFLOWCOUNT
#define WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#endif
#ifndef WSA_QOS_EUNKNOWNPSOBJ
#define WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#endif
#ifndef WSA_QOS_EPOLICYOBJ
#define WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#endif
#ifndef WSA_QOS_EFLOWDESC
#define WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#endif
#ifndef WSA_QOS_EPSFLOWSPEC
#define WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#endif
#ifndef WSA_QOS_EPSFILTERSPEC
#define WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#endif
#ifndef WSA_QOS_ESDMODEOBJ
#define WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#endif
#ifndef WSA_QOS_ESHAPERATEOBJ
#define WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#endif
#ifndef WSA_QOS_RESERVED_PETYPE
#define WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#endif
#endif // WSABASEERR

#define h_errno WSAGetLastError()
#define HOST_NOT_FOUND WSAHOST_NOT_FOUND
#define TRY_AGAIN WSATRY_AGAIN
#define NO_RECOVERY WSANO_RECOVERY
#define NO_DATA WSANO_DATA

#define WSANO_ADDRESS WSANO_DATA
#define NO_ADDRESS WSANO_ADDRESS

#எனில் 0
#define EWOULDBLOCK WSAEWOULDBLOCK
#define EINPROGRESS WSAEINPROGRESS
#define EALREADY WSAEALREADY
#define ENOTSOCK WSAENOTSOCK
#define EDESTADDRREQ WSAEDESTADDRREQ
#define EMSGSIZE WSAEMSGSIZE
#define EPROTOTYPE WSAEPROTOTYPE
#define ENOPROTOOPT WSAENOPROTOOPT
#define EPROTONOSUPPORT WSAEPROTONOSUPPORT
#define ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#define EOPNOTSUPP WSAEOPNOTSUPP
#define EPFNOSUPPORT WSAEPFNOSUPPORT
#define EAFNOSUPPORT WSAEAFNOSUPPORT
#define EADDRINUSE WSAEADDRINUSE
#define EADDRNOTAVAIL WSAEADDRNOTAVAIL
#define ENETDOWN WSAENETDOWN
#define ENETUNREACH WSAENETUNREACH
#define ENETRESET WSAENETRESET
#define ECONNABORTED WSAECONNABORTED
#define ECONNRESET WSAECONNRESET
#define ENOBUFS WSAENOBUFS
#define EISCONN WSAEISCONN
#define ENOTCONN WSAENOTCONN
#define ESHUTDOWN WSAESHUTDOWN
#define ETOOMANYREFS WSAETOOMANYREFS
#define ETIMEDOUT WSAETIMEDOUT
#define ECONNREFUSED WSAECONNREFUSED
#define ELOOP WSAELOOP
#define ENAMETOOLONG WSAENAMETOOLONG
#define EHOSTDOWN WSAEHOSTDOWN
#define EHOSTUNREACH WSAEHOSTUNREACH
#define ENOTEMPTY WSAENOTEMPTY
#define EPROCLIM WSAEPROCLIM
#define EUSERS WSAEUSERS
#define EDQUOT WSAEDQUOT
#define ESTALE WSAESTALE
#define EREMOTE WSAEREMOTE
#endif

#define WSAAPI WINAPI
#define WSAEVENT HANDLE
#define LPWSAEVENT LPHANDLE
#define WSAOVERLAPPED OVERLAPPED
  வகைவரை கட்டமைப்பு _OVERLAPPED *LPWSAOVERLAPPED;

#define WSA_IO_PENDING (ERROR_IO_PENDING)
#define WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#define WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#define WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#define WSA_NOT_ENOUGH_MEMORY (ERROR_NOT_ENOUGH_MEMORY)
#define WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#define WSA_INVALID_EVENT ((WSAEVENT)வெற்று)
#define WSA_MAXIMUM_WAIT_EVENTS (MAXIMUM_WAIT_OBJECTS)
#define WSA_WAIT_FAILED (WAIT_FAILED)
#define WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#define WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#define WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#define WSA_INFINITE (INFINITE)

  வகைவரை கட்டமைப்பு _WSABUF {
    u_long len;
    எழுத்து *buf;
  } WSABUF,*LPWSABUF;

#அந்தர்பாவ <qos.h>

  வகைவரை கட்டமைப்பு _QualityOfService {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#define CF_ACCEPT 0x0000
#define CF_REJECT 0x0001
#define CF_DEFER 0x0002

#define SD_RECEIVE 0x00
#define SD_SEND 0x01
#define SD_BOTH 0x02

  வகைவரை unsigned முழு GROUP;

#define SG_UNCONSTRAINED_GROUP 0x01
#define SG_CONSTRAINED_GROUP 0x02

  வகைவரை கட்டமைப்பு _WSANETWORKEVENTS {
    long lNetworkEvents;
    முழு iErrorCode[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#ifndef GUID_DEFINED
#அந்தர்பாவ <guiddef.h>
#endif

#define MAX_PROTOCOL_CHAIN 7

#define BASE_PROTOCOL 1
#define LAYERED_PROTOCOL 0

  வகைவரை கட்டமைப்பு _WSAPROTOCOLCHAIN {
    முழு ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#define WSAPROTOCOL_LEN 255

  வகைவரை கட்டமைப்பு _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dwCatalogEntryId;
    WSAPROTOCOLCHAIN ProtocolChain;
    முழு iVersion;
    முழு iAddressFamily;
    முழு iMaxSockAddr;
    முழு iMinSockAddr;
    முழு iSocketType;
    முழு iProtocol;
    முழு iProtocolMaxOffset;
    முழு iNetworkByteOrder;
    முழு iSecurityScheme;
    DWORD dwMessageSize;
    DWORD dwProviderReserved;
    CHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOA,*LPWSAPROTOCOL_INFOA;
  வகைவரை கட்டமைப்பு _WSAPROTOCOL_INFOW {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dwCatalogEntryId;
    WSAPROTOCOLCHAIN ProtocolChain;
    முழு iVersion;
    முழு iAddressFamily;
    முழு iMaxSockAddr;
    முழு iMinSockAddr;
    முழு iSocketType;
    முழு iProtocol;
    முழு iProtocolMaxOffset;
    முழு iNetworkByteOrder;
    முழு iSecurityScheme;
    DWORD dwMessageSize;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#ifdef UNICODE
  வகைவரை WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  வகைவரை LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#இல்லையெனில்
  வகைவரை WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  வகைவரை LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#endif

#define PFL_MULTIPLE_PROTO_ENTRIES 0x00000001
#define PFL_RECOMMENDED_PROTO_ENTRY 0x00000002
#define PFL_HIDDEN 0x00000004
#define PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#define XP1_CONNECTIONLESS 0x00000001
#define XP1_GUARANTEED_DELIVERY 0x00000002
#define XP1_GUARANTEED_ORDER 0x00000004
#define XP1_MESSAGE_ORIENTED 0x00000008
#define XP1_PSEUDO_STREAM 0x00000010
#define XP1_GRACEFUL_CLOSE 0x00000020
#define XP1_EXPEDITED_DATA 0x00000040
#define XP1_CONNECT_DATA 0x00000080
#define XP1_DISCONNECT_DATA 0x00000100
#define XP1_SUPPORT_BROADCAST 0x00000200
#define XP1_SUPPORT_MULTIPOINT 0x00000400
#define XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#define XP1_MULTIPOINT_DATA_PLANE 0x00001000
#define XP1_QOS_SUPPORTED 0x00002000
#define XP1_INTERRUPT 0x00004000
#define XP1_UNI_SEND 0x00008000
#define XP1_UNI_RECV 0x00010000
#define XP1_IFS_HANDLES 0x00020000
#define XP1_PARTIAL_MESSAGE 0x00040000

#define BIGENDIAN 0x0000
#define LITTLEENDIAN 0x0001

#define SECURITY_PROTOCOL_NONE 0x0000

#define JL_SENDER_ONLY 0x01
#define JL_RECEIVER_ONLY 0x02
#define JL_BOTH 0x04

#define WSA_FLAG_OVERLAPPED 0x01
#define WSA_FLAG_MULTIPOINT_C_வேர் 0x02
#define WSA_FLAG_MULTIPOINT_C_LEAF 0x04
#define WSA_FLAG_MULTIPOINT_D_வேர் 0x08
#define WSA_FLAG_MULTIPOINT_D_LEAF 0x10

#define IOC_UNIX 0x00000000
#define IOC_WS2 0x08000000
#define IOC_PROTOCOL 0x10000000
#define IOC_VENDOR 0x18000000

#define _WSAIO(x,y) (IOC_VOID|(x)|(y))
#define _WSAIOR(x,y) (IOC_OUT|(x)|(y))
#define _WSAIOW(x,y) (IOC_IN|(x)|(y))
#define _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#define SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#define SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#define SIO_FIND_ROUTE _WSAIOR(IOC_WS2,3)
#define SIO_FLUSH _WSAIO(IOC_WS2,4)
#define SIO_GET_BROADCAST_ADDRESS _WSAIOR(IOC_WS2,5)
#define SIO_GET_EXTENSION_FUNCTION_POINTER _WSAIORW(IOC_WS2,6)
#define SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#define SIO_GET_GROUP_QOS _WSAIORW(IOC_WS2,8)
#define SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#define SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#define SIO_SET_QOS _WSAIOW(IOC_WS2,11)
#define SIO_SET_GROUP_QOS _WSAIOW(IOC_WS2,12)
#define SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#define SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#define SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#define SIO_ADDRESS_LIST_QUERY _WSAIOR(IOC_WS2,22)
#define SIO_ADDRESS_LIST_CHANGE _WSAIO(IOC_WS2,23)
#define SIO_QUERY_TARGET_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#define SIO_ADDRESS_LIST_SORT _WSAIORW(IOC_WS2,25)

  வகைவரை முழு (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lpCallerData,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lpCalleeData,GROUP *g,DWORD_PTR dwCallbackData);
  வகைவரை வெறுமை (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#define SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  வகைவரை எண்ணிக்கை _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_PORT,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  வகைவரை கட்டமைப்பு _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    ஒன்றிப்பு {
      கட்டமைப்பு {
	HWND hWnd;
	UINT u_செய்தி;
	WPARAM context;
      } WindowMessage;
      கட்டமைப்பு {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      கட்டமைப்பு {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      கட்டமைப்பு {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE hPort;
	ULONG_PTR சாவி_3;
      } Port;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#define TH_NETDEV 0x00000001
#define TH_TAPI 0x00000002

  வகைவரை கட்டமைப்பு sockaddr SOCKADDR;
  வகைவரை கட்டமைப்பு sockaddr *PSOCKADDR;
  வகைவரை கட்டமைப்பு sockaddr *LPSOCKADDR;
  வகைவரை கட்டமைப்பு sockaddr_storage SOCKADDR_STORAGE;
  வகைவரை கட்டமைப்பு sockaddr_storage *PSOCKADDR_STORAGE;
  வகைவரை கட்டமைப்பு sockaddr_storage *LPSOCKADDR_STORAGE;

#ifndef _tagBLOB_DEFINED
#define _tagBLOB_DEFINED
#define _BLOB_DEFINED
#define _LPBLOB_DEFINED
  வகைவரை கட்டமைப்பு _BLOB {
    ULONG cbSize;
    BYTE *pBlobData;
  } BLOB,*LPBLOB;
#endif

#define SERVICE_MULTIPLE (0x00000001)

#define NS_ALL (0)

#define NS_SAP (1)
#define NS_NDS (2)
#define NS_PEER_BROWSE (3)
#define NS_SLP (5)
#define NS_DHCP (6)

#define NS_TCPIP_LOCAL (10)
#define NS_TCPIP_HOSTS (11)
#define NS_DNS (12)
#define NS_NETBT (13)
#define NS_WINS (14)
#define NS_NLA (15)

#define NS_NBP (20)

#define NS_MS (30)
#define NS_STDA (31)
#define NS_NTDS (32)

#define NS_X500 (40)
#define NS_NIS (41)
#define NS_NISPLUS (42)

#define NS_WRQ (50)

#define NS_NETDES (60)

#define RES_UNUSED_1 (0x00000001)
#define RES_FLUSH_CACHE (0x00000002)
#ifndef RES_SERVICE
#define RES_SERVICE (0x00000004)
#endif

#define SERVICE_TYPE_மதிப்பு_IPXPORTA "IpxSocket"
#define SERVICE_TYPE_மதிப்பு_IPXPORTW L"IpxSocket"
#define SERVICE_TYPE_மதிப்பு_SAPIDA "SapId"
#define SERVICE_TYPE_மதிப்பு_SAPIDW L"SapId"

#define SERVICE_TYPE_மதிப்பு_TCPPORTA "TcpPort"
#define SERVICE_TYPE_மதிப்பு_TCPPORTW L"TcpPort"

#define SERVICE_TYPE_மதிப்பு_UDPPORTA "UdpPort"
#define SERVICE_TYPE_மதிப்பு_UDPPORTW L"UdpPort"

#define SERVICE_TYPE_மதிப்பு_OBJECTIDA "ObjectId"
#define SERVICE_TYPE_மதிப்பு_OBJECTIDW L"ObjectId"

#ifdef UNICODE

#define SERVICE_TYPE_மதிப்பு_SAPID SERVICE_TYPE_மதிப்பு_SAPIDW
#define SERVICE_TYPE_மதிப்பு_TCPPORT SERVICE_TYPE_மதிப்பு_TCPPORTW
#define SERVICE_TYPE_மதிப்பு_UDPPORT SERVICE_TYPE_மதிப்பு_UDPPORTW
#define SERVICE_TYPE_மதிப்பு_OBJECTID SERVICE_TYPE_மதிப்பு_OBJECTIDW
#இல்லையெனில்

#define SERVICE_TYPE_மதிப்பு_SAPID SERVICE_TYPE_மதிப்பு_SAPIDA
#define SERVICE_TYPE_மதிப்பு_TCPPORT SERVICE_TYPE_மதிப்பு_TCPPORTA
#define SERVICE_TYPE_மதிப்பு_UDPPORT SERVICE_TYPE_மதிப்பு_UDPPORTA
#define SERVICE_TYPE_மதிப்பு_OBJECTID SERVICE_TYPE_மதிப்பு_OBJECTIDA
#endif

#ifndef __CSADDR_DEFINED__
#define __CSADDR_DEFINED__

  வகைவரை கட்டமைப்பு _SOCKET_ADDRESS {
    LPSOCKADDR lpSockaddr;
    INT iSockaddrLength;
  } SOCKET_ADDRESS,*PSOCKET_ADDRESS,*LPSOCKET_ADDRESS;

  வகைவரை கட்டமைப்பு _CSADDR_INFO {
    SOCKET_ADDRESS LocalAddr;
    SOCKET_ADDRESS RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#endif

  வகைவரை கட்டமைப்பு _SOCKET_ADDRESS_LIST {
    INT i_Address_மொத்தம்;
    SOCKET_ADDRESS Address[1];
  } SOCKET_ADDRESS_LIST,*LPSOCKET_ADDRESS_LIST;

  வகைவரை கட்டமைப்பு _AFPROTOCOLS {
    INT iAddressFamily;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  வகைவரை எண்ணிக்கை _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  வகைவரை கட்டமைப்பு _WSAVersion {
    DWORD dwVersion;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  வகைவரை கட்டமைப்பு _WSAQuerySetA {
    DWORD dwSize;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lpVersion;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_எண்_Of_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_எண்_Of_Cs_Addrs;
    LPCSADDR_INFO lpcsaBuffer;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  வகைவரை கட்டமைப்பு _WSAQuerySetW {
    DWORD dwSize;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lpVersion;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_எண்_Of_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_எண்_Of_Cs_Addrs;
    LPCSADDR_INFO lpcsaBuffer;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#ifdef UNICODE
  வகைவரை WSAQUERYSETW WSAQUERYSET;
  வகைவரை PWSAQUERYSETW PWSAQUERYSET;
  வகைவரை LPWSAQUERYSETW LPWSAQUERYSET;
#இல்லையெனில்
  வகைவரை WSAQUERYSETA WSAQUERYSET;
  வகைவரை PWSAQUERYSETA PWSAQUERYSET;
  வகைவரை LPWSAQUERYSETA LPWSAQUERYSET;
#endif

#define LUP_DEEP 0x0001
#define LUP_CONTAINERS 0x0002
#define LUP_NOCONTAINERS 0x0004
#define LUP_NEAREST 0x0008
#define LUP_RETURN_NAME 0x0010
#define LUP_RETURN_TYPE 0x0020
#define LUP_RETURN_VERSION 0x0040
#define LUP_RETURN_COMMENT 0x0080
#define LUP_RETURN_ADDR 0x0100
#define LUP_RETURN_BLOB 0x0200
#define LUP_RETURN_ALIASES 0x0400
#define LUP_RETURN_QUERY_STRING 0x0800
#define LUP_RETURN_ALL 0x0FF0
#define LUP_RES_SERVICE 0x8000

#define LUP_FLUSHCACHE 0x1000
#define LUP_FLUSHPREVIOUS 0x2000

#define RESULT_IS_ALIAS 0x0001
#define RESULT_IS_ADDED 0x0010
#define RESULT_IS_CHANGED 0x0020
#define RESULT_IS_DELETED 0x0040

  வகைவரை எண்ணிக்கை _WSAESETSERVICEOP {
    RNRSERVICE_REGISTER=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  வகைவரை கட்டமைப்பு _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_மதிப்பு_Type;
    DWORD dw_மதிப்பு_Size;
    LPVOID lp_மதிப்பு;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  வகைவரை கட்டமைப்பு _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_மதிப்பு_Type;
    DWORD dw_மதிப்பு_Size;
    LPVOID lp_மதிப்பு;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#ifdef UNICODE
  வகைவரை WSANSCLASSINFOW WSANSCLASSINFO;
  வகைவரை PWSANSCLASSINFOW PWSANSCLASSINFO;
  வகைவரை LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#இல்லையெனில்
  வகைவரை WSANSCLASSINFOA WSANSCLASSINFO;
  வகைவரை PWSANSCLASSINFOA PWSANSCLASSINFO;
  வகைவரை LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#endif

  வகைவரை கட்டமைப்பு _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_மொத்தம்;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  வகைவரை கட்டமைப்பு _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_மொத்தம்;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#ifdef UNICODE
  வகைவரை WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  வகைவரை PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  வகைவரை LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#இல்லையெனில்
  வகைவரை WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  வகைவரை PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  வகைவரை LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#endif

  வகைவரை கட்டமைப்பு _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL fActive;
    DWORD dwVersion;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  வகைவரை கட்டமைப்பு _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL fActive;
    DWORD dwVersion;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#ifdef UNICODE
  வகைவரை WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  வகைவரை PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  வகைவரை LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#இல்லையெனில்
  வகைவரை WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  வகைவரை PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  வகைவரை LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#endif

#எனில் INCL_WINSOCK_API_TYPEDEFS
#ifdef UNICODE
#define LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#define LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#define LPFN_WSASOCKET LPFN_WSASOCKETW
#define LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#define LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#define LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#define LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#define LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#define LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#define LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#define LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#define LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#இல்லையெனில்
#define LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#define LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#define LPFN_WSASOCKET LPFN_WSASOCKETA
#define LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#define LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#define LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#define LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#define LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#define LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#define LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#define LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#define LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#endif

  வகைவரை SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,கட்டமைப்பு sockaddr *addr,முழு *addrlen);
  வகைவரை முழு (WSAAPI *LPFN_BIND)(SOCKET s,மாறிலி கட்டமைப்பு sockaddr *name,முழு namelen);
  வகைவரை முழு (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  வகைவரை முழு (WSAAPI *LPFN_CONNECT)(SOCKET s,மாறிலி கட்டமைப்பு sockaddr *name,முழு namelen);
  வகைவரை முழு (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,long cmd,u_long *argp);
  வகைவரை முழு (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,கட்டமைப்பு sockaddr *name,முழு *namelen);
  வகைவரை முழு (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,கட்டமைப்பு sockaddr *name,முழு *namelen);
  வகைவரை முழு (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,முழு level,முழு optname,எழுத்து *optval,முழு *optlen);
  வகைவரை u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  வகைவரை u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  வகைவரை unsigned long (WSAAPI *LPFN_INET_ADDR)(மாறிலி எழுத்து *cp);
  வகைவரை எழுத்து *(WSAAPI *LPFN_INET_NTOA)(கட்டமைப்பு in_addr in);
  வகைவரை முழு (WSAAPI *LPFN_LISTEN)(SOCKET s,முழு backlog);
  வகைவரை u_long (WSAAPI *LPFN_NTOHL)(u_long netlong);
  வகைவரை u_short (WSAAPI *LPFN_NTOHS)(u_short netshort);
  வகைவரை முழு (WSAAPI *LPFN_RECV)(SOCKET s,எழுத்து *buf,முழு len,முழு flags);
  வகைவரை முழு (WSAAPI *LPFN_RECVFROM)(SOCKET s,எழுத்து *buf,முழு len,முழு flags,கட்டமைப்பு sockaddr *from,முழு *fromlen);
  வகைவரை முழு (WSAAPI *LPFN_SELECT)(முழு nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,மாறிலி கட்டமைப்பு timeval *timeout);
  வகைவரை முழு (WSAAPI *LPFN_SEND)(SOCKET s,மாறிலி எழுத்து *buf,முழு len,முழு flags);
  வகைவரை முழு (WSAAPI *LPFN_SENDTO)(SOCKET s,மாறிலி எழுத்து *buf,முழு len,முழு flags,மாறிலி கட்டமைப்பு sockaddr *to,முழு tolen);
  வகைவரை முழு (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s,முழு level,முழு optname,மாறிலி எழுத்து *optval,முழு optlen);
  வகைவரை முழு (WSAAPI *LPFN_SHUTDOWN)(SOCKET s,முழு how);
  வகைவரை SOCKET (WSAAPI *LPFN_SOCKET)(முழு af,முழு type,முழு protocol);
  வகைவரை கட்டமைப்பு hostent *(WSAAPI *LPFN_GETHOSTBYADDR)(மாறிலி எழுத்து *addr,முழு len,முழு type);
  வகைவரை கட்டமைப்பு hostent *(WSAAPI *LPFN_GETHOSTBYNAME)(மாறிலி எழுத்து *name);
  வகைவரை முழு (WSAAPI *LPFN_GETHOSTNAME)(எழுத்து *name,முழு namelen);
  வகைவரை கட்டமைப்பு servent *(WSAAPI *LPFN_GETSERVBYPORT)(முழு port,மாறிலி எழுத்து *proto);
  வகைவரை கட்டமைப்பு servent *(WSAAPI *LPFN_GETSERVBYNAME)(மாறிலி எழுத்து *name,மாறிலி எழுத்து *proto);
  வகைவரை கட்டமைப்பு protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(முழு எண்_3);
  வகைவரை கட்டமைப்பு protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(மாறிலி எழுத்து *name);
  வகைவரை முழு (WSAAPI *LPFN_WSASTARTUP)(WORD wVersionRequested,LPWSADATA lpWSAData);
  வகைவரை முழு (WSAAPI *LPFN_WSACLEANUP)(வெறுமை);
  வகைவரை வெறுமை (WSAAPI *LPFN_WSASETLASTERROR)(முழு iError);
  வகைவரை முழு (WSAAPI *LPFN_WSAGETLASTERROR)(வெறுமை);
  வகைவரை WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(வெறுமை);
  வகைவரை முழு (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(வெறுமை);
  வகைவரை FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lpBlockFunc);
  வகைவரை முழு (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(வெறுமை);
  வகைவரை HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_செய்தி,மாறிலி எழுத்து *name,மாறிலி எழுத்து *proto,எழுத்து *buf,முழு buflen);
  வகைவரை HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_செய்தி,முழு port,மாறிலி எழுத்து *proto,எழுத்து *buf,முழு buflen);
  வகைவரை HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_செய்தி,மாறிலி எழுத்து *name,எழுத்து *buf,முழு buflen);
  வகைவரை HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_செய்தி,முழு எண்_3,எழுத்து *buf,முழு buflen);
  வகைவரை HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_செய்தி,மாறிலி எழுத்து *name,எழுத்து *buf,முழு buflen);
  வகைவரை HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_செய்தி,மாறிலி எழுத்து *addr,முழு len,முழு type,எழுத்து *buf,முழு buflen);
  வகைவரை முழு (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  வகைவரை முழு (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_செய்தி,long lEvent);
  வகைவரை SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,கட்டமைப்பு sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dwCallbackData);
  வகைவரை WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  வகைவரை முழு (WSAAPI *LPFN_WSACONNECT)(SOCKET s,மாறிலி கட்டமைப்பு sockaddr *name,முழு namelen,LPWSABUF lpCallerData,LPWSABUF lpCalleeData,LPQOS lpSQOS,LPQOS lpGQOS);
  வகைவரை WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(வெறுமை);
  வகைவரை முழு (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  வகைவரை முழு (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  வகைவரை முழு (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lpNetworkEvents);
  வகைவரை முழு (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lpProtocolBuffer,LPDWORD lpdwBufferLength);
  வகைவரை முழு (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lpProtocolBuffer,LPDWORD lpdwBufferLength);
  வகைவரை முழு (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,long lNetworkEvents);
  வகைவரை WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  வகைவரை WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  வகைவரை முழு (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  வகைவரை முழு (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  வகைவரை முழு (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dwIoControlCode,LPVOID lpvInBuffer,DWORD cbInBuffer,LPVOID lpvOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbBytesReturned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  வகைவரை SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,மாறிலி கட்டமைப்பு sockaddr *name,முழு namelen,LPWSABUF lpCallerData,LPWSABUF lpCalleeData,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  வகைவரை முழு (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  வகைவரை முழு (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  வகைவரை முழு (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_Buffer_மொத்தம்,LPDWORD lp_எண்_Of_Bytes_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  வகைவரை முழு (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lpInboundDisconnectData);
  வகைவரை முழு (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_Buffer_மொத்தம்,LPDWORD lp_எண்_Of_Bytes_Recvd,LPDWORD lpFlags,கட்டமைப்பு sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  வகைவரை WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  வகைவரை முழு (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_Buffer_மொத்தம்,LPDWORD lp_எண்_Of_Bytes_Sent,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  வகைவரை முழு (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lpOutboundDisconnectData);
  வகைவரை முழு (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_Buffer_மொத்தம்,LPDWORD lp_எண்_Of_Bytes_Sent,DWORD dwFlags,மாறிலி கட்டமைப்பு sockaddr *lpTo,முழு iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  வகைவரை WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  வகைவரை SOCKET (WSAAPI *LPFN_WSASOCKETA)(முழு af,முழு type,முழு protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,GROUP g,DWORD dwFlags);
  வகைவரை SOCKET (WSAAPI *LPFN_WSASOCKETW)(முழு af,முழு type,முழு protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,GROUP g,DWORD dwFlags);
  வகைவரை DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,மாறிலி WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  வகைவரை INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsaAddress,DWORD dwAddressLength,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpszAddressString,LPDWORD lpdwAddressStringLength);
  வகைவரை INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsaAddress,DWORD dwAddressLength,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpszAddressString,LPDWORD lpdwAddressStringLength);
  வகைவரை INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lpAddressLength);
  வகைவரை INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lpAddressLength);
  வகைவரை INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  வகைவரை INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  வகைவரை INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdwBufferLength,LPWSAQUERYSETA lpqsResults);
  வகைவரை INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdwBufferLength,LPWSAQUERYSETW lpqsResults);
  வகைவரை INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dwControlCode,LPVOID lpvInBuffer,DWORD cbInBuffer,LPVOID lpvOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbBytesReturned,LPWSACOMPLETION lpCompletion);
  வகைவரை INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  வகைவரை INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  வகைவரை INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  வகைவரை INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  வகைவரை INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdwBufSize,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  வகைவரை INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdwBufSize,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  வகைவரை INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdwBufferLength,LPWSANAMESPACE_INFOA lpnspBuffer);
  வகைவரை INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdwBufferLength,LPWSANAMESPACE_INFOW lpnspBuffer);
  வகைவரை INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdwBufferLength);
  வகைவரை INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdwBufferLength);
  வகைவரை INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  வகைவரை INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  வகைவரை INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#endif

#ifdef UNICODE
#define WSADuplicateSocket WSADuplicateSocketW
#define WSAEnumProtocols WSAEnumProtocolsW
#define WSAAddressToString WSAAddressToStringW
#define WSASocket WSASocketW
#define WSAStringToAddress WSAStringToAddressW
#define WSALookupServiceBegin WSALookupServiceBeginW
#define WSALookupServiceNext WSALookupServiceNextW
#define WSAInstallServiceClass WSAInstallServiceClassW
#define WSAGetServiceClassInfo WSAGetServiceClassInfoW
#define WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#define WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#define WSASetService WSASetServiceW
#இல்லையெனில்
#define WSADuplicateSocket WSADuplicateSocketA
#define WSAEnumProtocols WSAEnumProtocolsA
#define WSASocket WSASocketA
#define WSAAddressToString WSAAddressToStringA
#define WSAStringToAddress WSAStringToAddressA
#define WSALookupServiceBegin WSALookupServiceBeginA
#define WSALookupServiceNext WSALookupServiceNextA
#define WSAInstallServiceClass WSAInstallServiceClassA
#define WSAGetServiceClassInfo WSAGetServiceClassInfoA
#define WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#define WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#define WSASetService WSASetServiceA
#endif

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,கட்டமைப்பு sockaddr *addr,முழு *addrlen);
  WINSOCK_API_LINKAGE முழு WSAAPI bind(SOCKET s,மாறிலி கட்டமைப்பு sockaddr *name,முழு namelen);
  WINSOCK_API_LINKAGE முழு WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE முழு WSAAPI connect(SOCKET s,மாறிலி கட்டமைப்பு sockaddr *name,முழு namelen);
  WINSOCK_API_LINKAGE முழு WSAAPI ioctlsocket(SOCKET s,long cmd,u_long *argp);
  WINSOCK_API_LINKAGE முழு WSAAPI getpeername(SOCKET s,கட்டமைப்பு sockaddr *name,முழு *namelen);
  WINSOCK_API_LINKAGE முழு WSAAPI getsockname(SOCKET s,கட்டமைப்பு sockaddr *name,முழு *namelen);
  WINSOCK_API_LINKAGE முழு WSAAPI getsockopt(SOCKET s,முழு level,முழு optname,எழுத்து *optval,முழு *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE unsigned long WSAAPI inet_addr(மாறிலி எழுத்து *cp);
  WINSOCK_API_LINKAGE எழுத்து *WSAAPI inet_ntoa(கட்டமைப்பு in_addr in);
  WINSOCK_API_LINKAGE முழு WSAAPI listen(SOCKET s,முழு backlog);
  WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE முழு WSAAPI recv(SOCKET s,எழுத்து *buf,முழு len,முழு flags);
  WINSOCK_API_LINKAGE முழு WSAAPI recvfrom(SOCKET s,எழுத்து *buf,முழு len,முழு flags,கட்டமைப்பு sockaddr *from,முழு *fromlen);
  WINSOCK_API_LINKAGE முழு WSAAPI select(முழு nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,மாறிலி கட்டமைப்பு timeval *timeout);
  WINSOCK_API_LINKAGE முழு WSAAPI send(SOCKET s,மாறிலி எழுத்து *buf,முழு len,முழு flags);
  WINSOCK_API_LINKAGE முழு WSAAPI sendto(SOCKET s,மாறிலி எழுத்து *buf,முழு len,முழு flags,மாறிலி கட்டமைப்பு sockaddr *to,முழு tolen);
  WINSOCK_API_LINKAGE முழு WSAAPI setsockopt(SOCKET s,முழு level,முழு optname,மாறிலி எழுத்து *optval,முழு optlen);
  WINSOCK_API_LINKAGE முழு WSAAPI shutdown(SOCKET s,முழு how);
  WINSOCK_API_LINKAGE SOCKET WSAAPI socket(முழு af,முழு type,முழு protocol);
  WINSOCK_API_LINKAGE கட்டமைப்பு hostent *WSAAPI gethostbyaddr(மாறிலி எழுத்து *addr,முழு len,முழு type);
  WINSOCK_API_LINKAGE கட்டமைப்பு hostent *WSAAPI gethostbyname(மாறிலி எழுத்து *name);
  WINSOCK_API_LINKAGE முழு WSAAPI gethostname(எழுத்து *name,முழு namelen);
  WINSOCK_API_LINKAGE கட்டமைப்பு servent *WSAAPI getservbyport(முழு port,மாறிலி எழுத்து *proto);
  WINSOCK_API_LINKAGE கட்டமைப்பு servent *WSAAPI getservbyname(மாறிலி எழுத்து *name,மாறிலி எழுத்து *proto);
  WINSOCK_API_LINKAGE கட்டமைப்பு protoent *WSAAPI getprotobynumber(முழு எண்_3);
  WINSOCK_API_LINKAGE கட்டமைப்பு protoent *WSAAPI getprotobyname(மாறிலி எழுத்து *name);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAStartup(WORD wVersionRequested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE முழு WSAAPI WSACleanup(வெறுமை);
  WINSOCK_API_LINKAGE வெறுமை WSAAPI WSASetLastError(முழு iError);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAGetLastError(வெறுமை);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(வெறுமை);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAUnhookBlockingHook(வெறுமை);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lpBlockFunc);
  WINSOCK_API_LINKAGE முழு WSAAPI WSACancelBlockingCall(வெறுமை);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_செய்தி,மாறிலி எழுத்து *name,மாறிலி எழுத்து *proto,எழுத்து *buf,முழு buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByPort(HWND hWnd,u_int w_செய்தி,முழு port,மாறிலி எழுத்து *proto,எழுத்து *buf,முழு buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_செய்தி,மாறிலி எழுத்து *name,எழுத்து *buf,முழு buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_எண்(HWND hWnd,u_int w_செய்தி,முழு எண்_3,எழுத்து *buf,முழு buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_செய்தி,மாறிலி எழுத்து *name,எழுத்து *buf,முழு buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_செய்தி,மாறிலி எழுத்து *addr,முழு len,முழு type,எழுத்து *buf,முழு buflen);
  WINSOCK_API_LINKAGE முழு WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_செய்தி,long lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,கட்டமைப்பு sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dwCallbackData);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAConnect(SOCKET s,மாறிலி கட்டமைப்பு sockaddr *name,முழு namelen,LPWSABUF lpCallerData,LPWSABUF lpCalleeData,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(வெறுமை);
  WINSOCK_API_LINKAGE முழு WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE முழு WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAEnumNetworkEvents(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lpNetworkEvents);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lpProtocolBuffer,LPDWORD lpdwBufferLength);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lpProtocolBuffer,LPDWORD lpdwBufferLength);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,long lNetworkEvents);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetOverlappedResult(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE முழு WSAAPI WSAIoctl(SOCKET s,DWORD dwIoControlCode,LPVOID lpvInBuffer,DWORD cbInBuffer,LPVOID lpvOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbBytesReturned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoinLeaf(SOCKET s,மாறிலி கட்டமைப்பு sockaddr *name,முழு namelen,LPWSABUF lpCallerData,LPWSABUF lpCalleeData,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE முழு WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE முழு WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE முழு WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_Buffer_மொத்தம்,LPDWORD lp_எண்_Of_Bytes_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE முழு WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lpInboundDisconnectData);
  WINSOCK_API_LINKAGE முழு WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_Buffer_மொத்தம்,LPDWORD lp_எண்_Of_Bytes_Recvd,LPDWORD lpFlags,கட்டமைப்பு sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE முழு WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_Buffer_மொத்தம்,LPDWORD lp_எண்_Of_Bytes_Sent,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE முழு WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lpOutboundDisconnectData);
  WINSOCK_API_LINKAGE முழு WSAAPI WSASendTo(SOCKET s,LPWSABUF lpBuffers,DWORD dw_Buffer_மொத்தம்,LPDWORD lp_எண்_Of_Bytes_Sent,DWORD dwFlags,மாறிலி கட்டமைப்பு sockaddr *lpTo,முழு iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(முழு af,முழு type,முழு protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,GROUP g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(முழு af,முழு type,முழு protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,GROUP g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWaitForMultipleEvents(DWORD cEvents,மாறிலி WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddressToStringA(LPSOCKADDR lpsaAddress,DWORD dwAddressLength,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpszAddressString,LPDWORD lpdwAddressStringLength);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddressToStringW(LPSOCKADDR lpsaAddress,DWORD dwAddressLength,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpszAddressString,LPDWORD lpdwAddressStringLength);
  WINSOCK_API_LINKAGE INT WSAAPI WSAStringToAddressA(LPSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lpAddressLength);
  WINSOCK_API_LINKAGE INT WSAAPI WSAStringToAddressW(LPWSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lpAddressLength);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceNextA(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdwBufferLength,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceNextW(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdwBufferLength,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dwControlCode,LPVOID lpvInBuffer,DWORD cbInBuffer,LPVOID lpvOutBuffer,DWORD cbOutBuffer,LPDWORD lpcbBytesReturned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceEnd(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdwBufSize,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdwBufSize,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdwBufferLength,LPWSANAMESPACE_INFOA lpnspBuffer);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdwBufferLength,LPWSANAMESPACE_INFOW lpnspBuffer);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdwBufferLength);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdwBufferLength);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  வகைவரை கட்டமைப்பு sockaddr_in SOCKADDR_IN;
  வகைவரை கட்டமைப்பு sockaddr_in *PSOCKADDR_IN;
  வகைவரை கட்டமைப்பு sockaddr_in *LPSOCKADDR_IN;

  வகைவரை கட்டமைப்பு linger LINGER;
  வகைவரை கட்டமைப்பு linger *PLINGER;
  வகைவரை கட்டமைப்பு linger *LPLINGER;

  வகைவரை கட்டமைப்பு in_addr IN_ADDR;
  வகைவரை கட்டமைப்பு in_addr *PIN_ADDR;
  வகைவரை கட்டமைப்பு in_addr *LPIN_ADDR;

  வகைவரை கட்டமைப்பு fd_set FD_SET;
  வகைவரை கட்டமைப்பு fd_set *PFD_SET;
  வகைவரை கட்டமைப்பு fd_set *LPFD_SET;

  வகைவரை கட்டமைப்பு hostent HOSTENT;
  வகைவரை கட்டமைப்பு hostent *PHOSTENT;
  வகைவரை கட்டமைப்பு hostent *LPHOSTENT;

  வகைவரை கட்டமைப்பு servent SERVENT;
  வகைவரை கட்டமைப்பு servent *PSERVENT;
  வகைவரை கட்டமைப்பு servent *LPSERVENT;

  வகைவரை கட்டமைப்பு protoent PROTOENT;
  வகைவரை கட்டமைப்பு protoent *PPROTOENT;
  வகைவரை கட்டமைப்பு protoent *LPPROTOENT;

  வகைவரை கட்டமைப்பு timeval TIMEVAL;
  வகைவரை கட்டமைப்பு timeval *PTIMEVAL;
  வகைவரை கட்டமைப்பு timeval *LPTIMEVAL;

#define WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#define WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#define WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#define WSAGETASYNCERROR(lParam) HIWORD(lParam)
#define WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#define WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#define POLLRDNORM  0x0100
#define POLLRDBAND  0x0200
#define POLLIN      (POLLRDNORM | POLLRDBAND)
#define POLLPRI     0x0400

#define POLLWRNORM  0x0010
#define POLLOUT     (POLLWRNORM)
#define POLLWRBAND  0x0020

#define POLLERR     0x0001
#define POLLHUP     0x0002
#define POLLNVAL    0x0004

வகைவரை கட்டமைப்பு pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE முழு WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#ifdef __cplusplus
}
#endif

#ifdef _NEED_POPPACK
#அந்தர்பாவ <poppack.h>
#endif

#ifdef IPV6STRICT
#அந்தர்பாவ <wsipv6ok.h>
#endif

#ifndef _WINSOCKAPI_
#define _WINSOCKAPI_
#endif

#ifdef _INC_WINSOCK_H
#அந்தர்பாவ <mswsock.h>
#endif

#endif
