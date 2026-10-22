/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#अगर_अघोषित _WINSOCK2API_
#घोषणा _WINSOCK2API_

#अगर_अघोषित INCL_WINSOCK_API_TYPEDEFS
#घोषणा INCL_WINSOCK_API_TYPEDEFS 0
#पूर्ण_अगर

#अगर_अघोषित _INC_WINDOWS
#समावेश <windows.h>
#पूर्ण_अगर

#अगर_अघोषित MAKEWORD
#घोषणा MAKEWORD(निचला,ऊपरी) ((WORD)(((BYTE)(निचला)) | ((WORD)((BYTE)(ऊपरी))) << 8))
#पूर्ण_अगर

#अगर_अघोषित WINSOCK_VERSION
#घोषणा WINSOCK_VERSION MAKEWORD(2,2)
#पूर्ण_अगर

#अगर_अघोषित WINSOCK_API_LINKAGE
#अगर_घोषित DECLSPEC_IMPORT
#घोषणा WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#अन्यथा
#घोषणा WINSOCK_API_LINKAGE
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित _WINSOCK_SOCKET_DEFINED
#घोषणा _WINSOCK_SOCKET_DEFINED
  प्रकार अचिन्हित अक्षर u_char;
  प्रकार अचिन्हित लघु u_short;
  प्रकार अचिन्हित पूर्णांक u_int;
  प्रकार अचिन्हित दीर्घ u_long;
  __MINGW_EXTENSION प्रकार अचिन्हित __int64 u_int64;
  प्रकार INT_PTR SOCKET;
#पूर्ण_अगर

#अगर_अघोषित FD_SETSIZE
#घोषणा FD_SETSIZE 64
#पूर्ण_अगर

  प्रकार काष्ठा fd_set {
    u_int fd_गिनती;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  बाह्य पूर्णांक WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#घोषणा FD_CLR(fd,set) करो { u_int __i; क्रम(__i = 0;__i < ((fd_set *)(set))->fd_गिनती;__i++) { अगर (((fd_set *)(set))->fd_array[__i]==fd) { जबतक (__i < ((fd_set *)(set))->fd_गिनती-1) { ((fd_set *)(set))->fd_array[__i] = ((fd_set *)(set))->fd_array[__i+1]; __i++; } ((fd_set *)(set))->fd_गिनती--; अवरोध; } } } जबतक(0)
#घोषणा FD_SET(fd,set) करो { u_int __i; क्रम(__i = 0;__i < ((fd_set *)(set))->fd_गिनती;__i++) { अगर (((fd_set *)(set))->fd_array[__i]==(fd)) { अवरोध; } } अगर (__i==((fd_set *)(set))->fd_गिनती) { अगर (((fd_set *)(set))->fd_गिनती < FD_SETSIZE) { ((fd_set *)(set))->fd_array[__i] = (fd); ((fd_set *)(set))->fd_गिनती++; } } } जबतक(0)
#घोषणा FD_ZERO(set) (((fd_set *)(set))->fd_गिनती=0)
#घोषणा FD_ISSET(fd,set) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(set))

#अगर_अघोषित _TIMEVAL_DEFINED /* also in winsock[2].h */
#घोषणा _TIMEVAL_DEFINED
  काष्ठा timeval {
    दीर्घ tv_sec;
    दीर्घ tv_usec;
  };

#घोषणा timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#घोषणा timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#घोषणा timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#पूर्ण_अगर /* _TIMEVAL_DEFINED */

#घोषणा IOCPARM_MASK 0x7f
#घोषणा IOC_VOID 0x20000000
#घोषणा IOC_OUT 0x40000000
#घोषणा IOC_IN 0x80000000
#घोषणा IOC_INOUT (IOC_IN|IOC_OUT)

#घोषणा _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#घोषणा _IOR(x,y,t) (IOC_OUT|(((दीर्घ)माप(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))
#घोषणा _IOW(x,y,t) (IOC_IN|(((दीर्घ)माप(t)&IOCPARM_MASK)<<16)|((x)<<8)|(y))

#घोषणा FIONREAD _IOR('f',127,u_long)
#घोषणा FIONBIO _IOW('f',126,u_long)
#घोषणा FIOASYNC _IOW('f',125,u_long)

#घोषणा SIOCSHIWAT _IOW('s',0,u_long)
#घोषणा SIOCGHIWAT _IOR('s',1,u_long)
#घोषणा SIOCSLOWAT _IOW('s',2,u_long)
#घोषणा SIOCGLOWAT _IOR('s',3,u_long)
#घोषणा SIOCATMARK _IOR('s',7,u_long)

#घोषणा h_addr h_addr_list[0]

  काष्ठा hostent {
    अक्षर *h_name;
    अक्षर **h_aliases;
    लघु h_addrtype;
    लघु h_लंबाई;
    अक्षर **h_addr_list;
  };

  काष्ठा netent {
    अक्षर *n_name;
    अक्षर **n_aliases;
    लघु n_addrtype;
    u_long n_net;
  };

  काष्ठा servent {
    अक्षर *s_name;
    अक्षर **s_aliases;
#अगर_घोषित _WIN64
    अक्षर *s_proto;
    लघु s_port;
#अन्यथा
    लघु s_port;
    अक्षर *s_proto;
#पूर्ण_अगर
  };

  काष्ठा protoent {
    अक्षर *p_name;
    अक्षर **p_aliases;
    लघु p_proto;
  };

#घोषणा IPPROTO_IP 0
#घोषणा IPPROTO_HOPOPTS 0
#घोषणा IPPROTO_ICMP 1
#घोषणा IPPROTO_IGMP 2
#घोषणा IPPROTO_GGP 3
#घोषणा IPPROTO_IPV4 4
#घोषणा IPPROTO_TCP 6
#घोषणा IPPROTO_PUP 12
#घोषणा IPPROTO_UDP 17
#घोषणा IPPROTO_IDP 22
#घोषणा IPPROTO_IPV6 41
#घोषणा IPPROTO_ROUTING 43
#घोषणा IPPROTO_FRAGMENT 44
#घोषणा IPPROTO_ESP 50
#घोषणा IPPROTO_AH 51
#घोषणा IPPROTO_ICMPV6 58
#घोषणा IPPROTO_NONE 59
#घोषणा IPPROTO_DSTOPTS 60
#घोषणा IPPROTO_ND 77
#घोषणा IPPROTO_ICLFXBM 78

#घोषणा IPPROTO_RAW 255
#घोषणा IPPROTO_MAX 256

#घोषणा IPPORT_ECHO 7
#घोषणा IPPORT_DISCARD 9
#घोषणा IPPORT_SYSTAT 11
#घोषणा IPPORT_DAYTIME 13
#घोषणा IPPORT_NETSTAT 15
#घोषणा IPPORT_FTP 21
#घोषणा IPPORT_TELNET 23
#घोषणा IPPORT_SMTP 25
#घोषणा IPPORT_TIMESERVER 37
#घोषणा IPPORT_NAMESERVER 42
#घोषणा IPPORT_WHOIS 43
#घोषणा IPPORT_MTP 57

#घोषणा IPPORT_TFTP 69
#घोषणा IPPORT_RJE 77
#घोषणा IPPORT_FINGER 79
#घोषणा IPPORT_TTYLINK 87
#घोषणा IPPORT_SUPDUP 95

#घोषणा IPPORT_EXECSERVER 512
#घोषणा IPPORT_LOGINSERVER 513
#घोषणा IPPORT_CMDSERVER 514
#घोषणा IPPORT_EFSSERVER 520

#घोषणा IPPORT_BIFFUDP 512
#घोषणा IPPORT_WHOSERVER 513
#घोषणा IPPORT_ROUTESERVER 520

#घोषणा IPPORT_RESERVED 1024

#घोषणा IMPLINK_IP 155
#घोषणा IMPLINK_LOWEXPER 156
#घोषणा IMPLINK_HIGHEXPER 158

#अगर_अघोषित s_addr

  काष्ठा in_addr {
    जोड़ {
      काष्ठा { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      काष्ठा { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#घोषणा s_addr S_un.S_addr
#घोषणा s_host S_un.S_un_b.s_b2
#घोषणा s_net S_un.S_un_b.s_b1
#घोषणा s_imp S_un.S_un_w.s_w2
#घोषणा s_impno S_un.S_un_b.s_b4
#घोषणा s_lh S_un.S_un_b.s_b3

#पूर्ण_अगर

#घोषणा IN_CLASSA(i) (((दीर्घ)(i) & 0x80000000)==0)
#घोषणा IN_CLASSA_NET 0xff000000
#घोषणा IN_CLASSA_NSHIFT 24
#घोषणा IN_CLASSA_HOST 0x00ffffff
#घोषणा IN_CLASSA_MAX 128

#घोषणा IN_CLASSB(i) (((दीर्घ)(i) & 0xc0000000)==0x80000000)
#घोषणा IN_CLASSB_NET 0xffff0000
#घोषणा IN_CLASSB_NSHIFT 16
#घोषणा IN_CLASSB_HOST 0x0000ffff
#घोषणा IN_CLASSB_MAX 65536

#घोषणा IN_CLASSC(i) (((दीर्घ)(i) & 0xe0000000)==0xc0000000)
#घोषणा IN_CLASSC_NET 0xffffff00
#घोषणा IN_CLASSC_NSHIFT 8
#घोषणा IN_CLASSC_HOST 0x000000ff

#घोषणा IN_CLASSD(i) (((दीर्घ)(i) & 0xf0000000)==0xe0000000)
#घोषणा IN_CLASSD_NET 0xf0000000
#घोषणा IN_CLASSD_NSHIFT 28
#घोषणा IN_CLASSD_HOST 0x0fffffff
#घोषणा IN_MULTICAST(i) IN_CLASSD(i)

#घोषणा INADDR_ANY (u_long)0x00000000
#घोषणा INADDR_LOOPBACK 0x7f000001
#घोषणा INADDR_BROADCAST (u_long)0xffffffff
#घोषणा INADDR_NONE 0xffffffff

#घोषणा ADDR_ANY INADDR_ANY

  काष्ठा sockaddr_in {
    लघु sin_family;
    u_short sin_port;
    काष्ठा in_addr sin_addr;
    अक्षर sin_zero[8];
  };

#घोषणा WSADESCRIPTION_LEN 256
#घोषणा WSASYS_STATUS_LEN 128

  प्रकार काष्ठा WSAData {
    WORD wVersion;
    WORD w_ऊपरी_Version;
#अगर_घोषित _WIN64
    अचिन्हित लघु iMaxSockets;
    अचिन्हित लघु iMaxUdpDg;
    अक्षर *lpVendorInfo;
    अक्षर szDescription[WSADESCRIPTION_LEN+1];
    अक्षर szSystemStatus[WSASYS_STATUS_LEN+1];
#अन्यथा
    अक्षर szDescription[WSADESCRIPTION_LEN+1];
    अक्षर szSystemStatus[WSASYS_STATUS_LEN+1];
    अचिन्हित लघु iMaxSockets;
    अचिन्हित लघु iMaxUdpDg;
    अक्षर *lpVendorInfo;
#पूर्ण_अगर
  } WSADATA,*LPWSADATA;

#घोषणा INVALID_SOCKET (SOCKET)(~0)
#घोषणा SOCKET_ERROR (-1)

#घोषणा FROM_PROTOCOL_INFO (-1)

#घोषणा SOCK_STREAM 1
#घोषणा SOCK_DGRAM 2
#घोषणा SOCK_RAW 3
#घोषणा SOCK_RDM 4
#घोषणा SOCK_SEQPACKET 5

#घोषणा SO_DEBUG 0x0001
#घोषणा SO_ACCEPTCONN 0x0002
#घोषणा SO_REUSEADDR 0x0004
#घोषणा SO_KEEPALIVE 0x0008
#घोषणा SO_DONTROUTE 0x0010
#घोषणा SO_BROADCAST 0x0020
#घोषणा SO_USELOOPBACK 0x0040
#घोषणा SO_LINGER 0x0080
#घोषणा SO_OOBINLINE 0x0100

#घोषणा SO_DONTLINGER (पूर्णांक)(~SO_LINGER)
#घोषणा SO_EXCLUSIVEADDRUSE ((पूर्णांक)(~SO_REUSEADDR))

#घोषणा SO_SNDBUF 0x1001
#घोषणा SO_RCVBUF 0x1002
#घोषणा SO_SNDLOWAT 0x1003
#घोषणा SO_RCVLOWAT 0x1004
#घोषणा SO_SNDTIMEO 0x1005
#घोषणा SO_RCVTIMEO 0x1006
#घोषणा SO_ERROR 0x1007
#घोषणा SO_TYPE 0x1008

#घोषणा SO_GROUP_ID 0x2001
#घोषणा SO_GROUP_PRIORITY 0x2002
#घोषणा SO_MAX_संदेश_आकार 0x2003
#घोषणा SO_PROTOCOL_INFOA 0x2004
#घोषणा SO_PROTOCOL_INFOW 0x2005
#अगर_घोषित UNICODE
#घोषणा SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#अन्यथा
#घोषणा SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#पूर्ण_अगर
#घोषणा PVD_CONFIG 0x3001
#घोषणा SO_CONDITIONAL_ACCEPT 0x3002

#घोषणा TCP_NODELAY 0x0001

#घोषणा AF_UNSPEC 0

#घोषणा AF_UNIX 1
#घोषणा AF_INET 2
#घोषणा AF_IMPLINK 3
#घोषणा AF_PUP 4
#घोषणा AF_CHAOS 5
#घोषणा AF_NS 6
#घोषणा AF_IPX AF_NS
#घोषणा AF_ISO 7
#घोषणा AF_OSI AF_ISO
#घोषणा AF_ECMA 8
#घोषणा AF_DATAKIT 9
#घोषणा AF_CCITT 10
#घोषणा AF_SNA 11
#घोषणा AF_DECnet 12
#घोषणा AF_DLI 13
#घोषणा AF_LAT 14
#घोषणा AF_HYLINK 15
#घोषणा AF_APPLETALK 16
#घोषणा AF_NETBIOS 17
#घोषणा AF_VOICEVIEW 18
#घोषणा AF_FIREFOX 19
#घोषणा AF_UNKNOWN1 20
#घोषणा AF_BAN 21
#घोषणा AF_ATM 22
#घोषणा AF_INET6 23
#घोषणा AF_CLUSTER 24
#घोषणा AF_12844 25
#घोषणा AF_IRDA 26
#घोषणा AF_NETDES 28
#घोषणा AF_TCNPROCESS 29
#घोषणा AF_TCNMESSAGE 30
#घोषणा AF_ICLFXBM 31

#घोषणा AF_MAX 32

  काष्ठा sockaddr {
    u_short sa_family;
    अक्षर sa_तथ्य[14];
  };

#घोषणा _SS_MAXSIZE 128
#घोषणा _SS_ALIGNSIZE (8)

#घोषणा SS_PAD1_आकार (_SS_ALIGNSIZE - माप (लघु))
#घोषणा SS_PAD2_आकार (_SS_MAXSIZE - (माप (लघु) + SS_PAD1_आकार + _SS_ALIGNSIZE))

  काष्ठा sockaddr_storage {
    लघु ss_family;
    अक्षर __ss_pad1[SS_PAD1_आकार];

    __MINGW_EXTENSION __int64 __ss_align;
    अक्षर __ss_pad2[SS_PAD2_आकार];

  };

  काष्ठा sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#घोषणा PF_UNSPEC AF_UNSPEC
#घोषणा PF_UNIX AF_UNIX
#घोषणा PF_INET AF_INET
#घोषणा PF_IMPLINK AF_IMPLINK
#घोषणा PF_PUP AF_PUP
#घोषणा PF_CHAOS AF_CHAOS
#घोषणा PF_NS AF_NS
#घोषणा PF_IPX AF_IPX
#घोषणा PF_ISO AF_ISO
#घोषणा PF_OSI AF_OSI
#घोषणा PF_ECMA AF_ECMA
#घोषणा PF_DATAKIT AF_DATAKIT
#घोषणा PF_CCITT AF_CCITT
#घोषणा PF_SNA AF_SNA
#घोषणा PF_DECnet AF_DECnet
#घोषणा PF_DLI AF_DLI
#घोषणा PF_LAT AF_LAT
#घोषणा PF_HYLINK AF_HYLINK
#घोषणा PF_APPLETALK AF_APPLETALK
#घोषणा PF_VOICEVIEW AF_VOICEVIEW
#घोषणा PF_FIREFOX AF_FIREFOX
#घोषणा PF_UNKNOWN1 AF_UNKNOWN1
#घोषणा PF_BAN AF_BAN
#घोषणा PF_ATM AF_ATM
#घोषणा PF_INET6 AF_INET6

#घोषणा PF_MAX AF_MAX

  काष्ठा linger {
    u_short l_onoff;
    u_short l_linger;
  };

#घोषणा SOL_SOCKET 0xffff

#घोषणा SOMAXCONN 0x7fffffff

#घोषणा संदेश_OOB 0x1
#घोषणा संदेश_PEEK 0x2
#घोषणा संदेश_DONTROUTE 0x4
#घोषणा संदेश_WAITALL 0x8

#घोषणा संदेश_PARTIAL 0x8000

#घोषणा संदेश_INTERRUPT 0x10

#घोषणा संदेश_MAXIOVLEN 16

#घोषणा MAXGETHOSTSTRUCT 1024

#घोषणा FD_READ_BIT 0
#घोषणा FD_READ (1 << FD_READ_BIT)

#घोषणा FD_WRITE_BIT 1
#घोषणा FD_WRITE (1 << FD_WRITE_BIT)

#घोषणा FD_OOB_BIT 2
#घोषणा FD_OOB (1 << FD_OOB_BIT)

#घोषणा FD_ACCEPT_BIT 3
#घोषणा FD_ACCEPT (1 << FD_ACCEPT_BIT)

#घोषणा FD_CONNECT_BIT 4
#घोषणा FD_CONNECT (1 << FD_CONNECT_BIT)

#घोषणा FD_CLOSE_BIT 5
#घोषणा FD_CLOSE (1 << FD_CLOSE_BIT)

#घोषणा FD_QOS_BIT 6
#घोषणा FD_QOS (1 << FD_QOS_BIT)

#घोषणा FD_GROUP_QOS_BIT 7
#घोषणा FD_GROUP_QOS (1 << FD_GROUP_QOS_BIT)

#घोषणा FD_ROUTING_INTERFACE_CHANGE_BIT 8
#घोषणा FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_BIT)

#घोषणा FD_ADDRESS_LIST_CHANGE_BIT 9
#घोषणा FD_ADDRESS_LIST_CHANGE (1 << FD_ADDRESS_LIST_CHANGE_BIT)

#घोषणा FD_MAX_EVENTS 10
#घोषणा FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#अगर_अघोषित WSABASEERR

#घोषणा WSABASEERR 10000

#घोषणा WSAEINTR (WSABASEERR+4)
#घोषणा WSAEBADF (WSABASEERR+9)
#घोषणा WSAEACCES (WSABASEERR+13)
#घोषणा WSAEFAULT (WSABASEERR+14)
#घोषणा WSAEINVAL (WSABASEERR+22)
#घोषणा WSAEMFILE (WSABASEERR+24)

#घोषणा WSAEWOULDBLOCK (WSABASEERR+35)
#घोषणा WSAEINPROGRESS (WSABASEERR+36)
#घोषणा WSAEALREADY (WSABASEERR+37)
#घोषणा WSAENOTSOCK (WSABASEERR+38)
#घोषणा WSAEDESTADDRREQ (WSABASEERR+39)
#घोषणा WSAEMSGSIZE (WSABASEERR+40)
#घोषणा WSAEPROTOTYPE (WSABASEERR+41)
#घोषणा WSAENOPROTOOPT (WSABASEERR+42)
#घोषणा WSAEPROTONOSUPPORT (WSABASEERR+43)
#घोषणा WSAESOCKTNOSUPPORT (WSABASEERR+44)
#घोषणा WSAEOPNOTSUPP (WSABASEERR+45)
#घोषणा WSAEPFNOSUPPORT (WSABASEERR+46)
#घोषणा WSAEAFNOSUPPORT (WSABASEERR+47)
#घोषणा WSAEADDRINUSE (WSABASEERR+48)
#घोषणा WSAEADDRNOTAVAIL (WSABASEERR+49)
#घोषणा WSAENETDOWN (WSABASEERR+50)
#घोषणा WSAENETUNREACH (WSABASEERR+51)
#घोषणा WSAENETRESET (WSABASEERR+52)
#घोषणा WSAECONNABORTED (WSABASEERR+53)
#घोषणा WSAECONNRESET (WSABASEERR+54)
#घोषणा WSAENOBUFS (WSABASEERR+55)
#घोषणा WSAEISCONN (WSABASEERR+56)
#घोषणा WSAENOTCONN (WSABASEERR+57)
#घोषणा WSAESHUTDOWN (WSABASEERR+58)
#घोषणा WSAETOOMANYREFS (WSABASEERR+59)
#घोषणा WSAETIMEDOUT (WSABASEERR+60)
#घोषणा WSAECONNREFUSED (WSABASEERR+61)
#घोषणा WSAELOOP (WSABASEERR+62)
#घोषणा WSAENAMETOOLONG (WSABASEERR+63)
#घोषणा WSAEHOSTDOWN (WSABASEERR+64)
#घोषणा WSAEHOSTUNREACH (WSABASEERR+65)
#घोषणा WSAENOTEMPTY (WSABASEERR+66)
#घोषणा WSAEPROCLIM (WSABASEERR+67)
#घोषणा WSAEUSERS (WSABASEERR+68)
#घोषणा WSAEDQUOT (WSABASEERR+69)
#घोषणा WSAESTALE (WSABASEERR+70)
#घोषणा WSAEREMOTE (WSABASEERR+71)

#घोषणा WSASYSNOTREADY (WSABASEERR+91)
#घोषणा WSAVERNOTSUPPORTED (WSABASEERR+92)
#घोषणा WSANOTINITIALISED (WSABASEERR+93)
#घोषणा WSAEDISCON (WSABASEERR+101)
#अगर_अघोषित WSAHOST_NOT_FOUND
#घोषणा WSAHOST_NOT_FOUND (WSABASEERR+1001)
#पूर्ण_अगर
#अगर_अघोषित WSATRY_AGAIN
#घोषणा WSATRY_AGAIN (WSABASEERR+1002)
#पूर्ण_अगर
#अगर_अघोषित WSANO_RECOVERY
#घोषणा WSANO_RECOVERY (WSABASEERR+1003)
#पूर्ण_अगर
#अगर_अघोषित WSANO_तथ्य
#घोषणा WSANO_तथ्य (WSABASEERR+1004)
#पूर्ण_अगर

#घोषणा WSAENOMORE (WSABASEERR+102)
#घोषणा WSAECANCELLED (WSABASEERR+103)
#घोषणा WSAEINVALIDPROCTABLE (WSABASEERR+104)
#घोषणा WSAEINVALIDPROVIDER (WSABASEERR+105)
#घोषणा WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#घोषणा WSASYSCALLFAILURE (WSABASEERR+107)
#घोषणा WSASERVICE_NOT_FOUND (WSABASEERR+108)
#घोषणा WSATYPE_NOT_FOUND (WSABASEERR+109)
#घोषणा WSA_E_NO_MORE (WSABASEERR+110)
#घोषणा WSA_E_CANCELLED (WSABASEERR+111)
#घोषणा WSAEREFUSED (WSABASEERR+112)
#अगर_अघोषित WSA_QOS_RECEIVERS
#घोषणा WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_SENDERS
#घोषणा WSA_QOS_SENDERS (WSABASEERR + 1006)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_NO_SENDERS
#घोषणा WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#घोषणा WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#घोषणा WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#घोषणा WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#घोषणा WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#घोषणा WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#घोषणा WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#घोषणा WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#घोषणा WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#घोषणा WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#घोषणा WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#घोषणा WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EFILTERSTYLE
#घोषणा WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EFILTERTYPE
#घोषणा WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EFILTERCOUNT
#घोषणा WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EOBJLENGTH
#घोषणा WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EFLOWCOUNT
#घोषणा WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EUNKNOWNPSOBJ
#घोषणा WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EPOLICYOBJ
#घोषणा WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EFLOWDESC
#घोषणा WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EPSFLOWSPEC
#घोषणा WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_EPSFILTERSPEC
#घोषणा WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_ESDMODEOBJ
#घोषणा WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_ESHAPERATEOBJ
#घोषणा WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#पूर्ण_अगर
#अगर_अघोषित WSA_QOS_RESERVED_PETYPE
#घोषणा WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#पूर्ण_अगर
#पूर्ण_अगर // WSABASEERR

#घोषणा h_errno WSAGetLastError()
#घोषणा HOST_NOT_FOUND WSAHOST_NOT_FOUND
#घोषणा TRY_AGAIN WSATRY_AGAIN
#घोषणा NO_RECOVERY WSANO_RECOVERY
#घोषणा NO_तथ्य WSANO_तथ्य

#घोषणा WSANO_ADDRESS WSANO_तथ्य
#घोषणा NO_ADDRESS WSANO_ADDRESS

#अगर 0
#घोषणा EWOULDBLOCK WSAEWOULDBLOCK
#घोषणा EINPROGRESS WSAEINPROGRESS
#घोषणा EALREADY WSAEALREADY
#घोषणा ENOTSOCK WSAENOTSOCK
#घोषणा EDESTADDRREQ WSAEDESTADDRREQ
#घोषणा EMSGSIZE WSAEMSGSIZE
#घोषणा EPROTOTYPE WSAEPROTOTYPE
#घोषणा ENOPROTOOPT WSAENOPROTOOPT
#घोषणा EPROTONOSUPPORT WSAEPROTONOSUPPORT
#घोषणा ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#घोषणा EOPNOTSUPP WSAEOPNOTSUPP
#घोषणा EPFNOSUPPORT WSAEPFNOSUPPORT
#घोषणा EAFNOSUPPORT WSAEAFNOSUPPORT
#घोषणा EADDRINUSE WSAEADDRINUSE
#घोषणा EADDRNOTAVAIL WSAEADDRNOTAVAIL
#घोषणा ENETDOWN WSAENETDOWN
#घोषणा ENETUNREACH WSAENETUNREACH
#घोषणा ENETRESET WSAENETRESET
#घोषणा ECONNABORTED WSAECONNABORTED
#घोषणा ECONNRESET WSAECONNRESET
#घोषणा ENOBUFS WSAENOBUFS
#घोषणा EISCONN WSAEISCONN
#घोषणा ENOTCONN WSAENOTCONN
#घोषणा ESHUTDOWN WSAESHUTDOWN
#घोषणा ETOOMANYREFS WSAETOOMANYREFS
#घोषणा ETIMEDOUT WSAETIMEDOUT
#घोषणा ECONNREFUSED WSAECONNREFUSED
#घोषणा ELOOP WSAELOOP
#घोषणा ENAMETOOLONG WSAENAMETOOLONG
#घोषणा EHOSTDOWN WSAEHOSTDOWN
#घोषणा EHOSTUNREACH WSAEHOSTUNREACH
#घोषणा ENOTEMPTY WSAENOTEMPTY
#घोषणा EPROCLIM WSAEPROCLIM
#घोषणा EUSERS WSAEUSERS
#घोषणा EDQUOT WSAEDQUOT
#घोषणा ESTALE WSAESTALE
#घोषणा EREMOTE WSAEREMOTE
#पूर्ण_अगर

#घोषणा WSAAPI WINAPI
#घोषणा WSAEVENT HANDLE
#घोषणा LPWSAEVENT LPHANDLE
#घोषणा WSAOVERLAPPED OVERLAPPED
  प्रकार काष्ठा _OVERLAPPED *LPWSAOVERLAPPED;

#घोषणा WSA_IO_PENDING (ERROR_IO_PENDING)
#घोषणा WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#घोषणा WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#घोषणा WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#घोषणा WSA_NOT_ENOUGH_MEMORY (ERROR_NOT_ENOUGH_MEMORY)
#घोषणा WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#घोषणा WSA_INVALID_EVENT ((WSAEVENT)शून्य)
#घोषणा WSA_MAXIMUM_WAIT_EVENTS (MAXIMUM_WAIT_OBJECTS)
#घोषणा WSA_WAIT_FAILED (WAIT_FAILED)
#घोषणा WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#घोषणा WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#घोषणा WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#घोषणा WSA_INFINITE (INFINITE)

  प्रकार काष्ठा _WSABUF {
    u_long len;
    अक्षर *buf;
  } WSABUF,*LPWSABUF;

#समावेश <qos.h>

  प्रकार काष्ठा _QualityOfService {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#घोषणा CF_ACCEPT 0x0000
#घोषणा CF_REJECT 0x0001
#घोषणा CF_DEFER 0x0002

#घोषणा SD_RECEIVE 0x00
#घोषणा SD_SEND 0x01
#घोषणा SD_BOTH 0x02

  प्रकार अचिन्हित पूर्णांक GROUP;

#घोषणा SG_UNCONSTRAINED_GROUP 0x01
#घोषणा SG_CONSTRAINED_GROUP 0x02

  प्रकार काष्ठा _WSANETWORKEVENTS {
    दीर्घ lNetworkEvents;
    पूर्णांक iErrorCode[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#अगर_अघोषित GUID_DEFINED
#समावेश <guiddef.h>
#पूर्ण_अगर

#घोषणा MAX_PROTOCOL_CHAIN 7

#घोषणा BASE_PROTOCOL 1
#घोषणा LAYERED_PROTOCOL 0

  प्रकार काष्ठा _WSAPROTOCOLCHAIN {
    पूर्णांक ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#घोषणा WSAPROTOCOL_LEN 255

  प्रकार काष्ठा _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dwCatalogEntryId;
    WSAPROTOCOLCHAIN ProtocolChain;
    पूर्णांक iVersion;
    पूर्णांक iAddressFamily;
    पूर्णांक iMaxSockAddr;
    पूर्णांक iMinSockAddr;
    पूर्णांक iSocketType;
    पूर्णांक iProtocol;
    पूर्णांक iProtocolMaxOffset;
    पूर्णांक iNetworkByteOrder;
    पूर्णांक iSecurityScheme;
    DWORD dw_Message_आकार;
    DWORD dwProviderReserved;
    CHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOA,*LPWSAPROTOCOL_INFOA;
  प्रकार काष्ठा _WSAPROTOCOL_INFOW {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dwCatalogEntryId;
    WSAPROTOCOLCHAIN ProtocolChain;
    पूर्णांक iVersion;
    पूर्णांक iAddressFamily;
    पूर्णांक iMaxSockAddr;
    पूर्णांक iMinSockAddr;
    पूर्णांक iSocketType;
    पूर्णांक iProtocol;
    पूर्णांक iProtocolMaxOffset;
    पूर्णांक iNetworkByteOrder;
    पूर्णांक iSecurityScheme;
    DWORD dw_Message_आकार;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#अगर_घोषित UNICODE
  प्रकार WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  प्रकार LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#अन्यथा
  प्रकार WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  प्रकार LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#पूर्ण_अगर

#घोषणा PFL_MULTIPLE_PROTO_ENTRIES 0x00000001
#घोषणा PFL_RECOMMENDED_PROTO_ENTRY 0x00000002
#घोषणा PFL_HIDDEN 0x00000004
#घोषणा PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#घोषणा XP1_CONNECTIONLESS 0x00000001
#घोषणा XP1_GUARANTEED_DELIVERY 0x00000002
#घोषणा XP1_GUARANTEED_ORDER 0x00000004
#घोषणा XP1_MESSAGE_ORIENTED 0x00000008
#घोषणा XP1_PSEUDO_STREAM 0x00000010
#घोषणा XP1_GRACEFUL_CLOSE 0x00000020
#घोषणा XP1_EXPEDITED_तथ्य 0x00000040
#घोषणा XP1_CONNECT_तथ्य 0x00000080
#घोषणा XP1_DISCONNECT_तथ्य 0x00000100
#घोषणा XP1_SUPPORT_BROADCAST 0x00000200
#घोषणा XP1_SUPPORT_MULTIPOINT 0x00000400
#घोषणा XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#घोषणा XP1_MULTIPOINT_तथ्य_PLANE 0x00001000
#घोषणा XP1_QOS_SUPPORTED 0x00002000
#घोषणा XP1_INTERRUPT 0x00004000
#घोषणा XP1_UNI_SEND 0x00008000
#घोषणा XP1_UNI_RECV 0x00010000
#घोषणा XP1_IFS_HANDLES 0x00020000
#घोषणा XP1_PARTIAL_MESSAGE 0x00040000

#घोषणा BIGENDIAN 0x0000
#घोषणा LITTLEENDIAN 0x0001

#घोषणा SECURITY_PROTOCOL_NONE 0x0000

#घोषणा JL_SENDER_ONLY 0x01
#घोषणा JL_RECEIVER_ONLY 0x02
#घोषणा JL_BOTH 0x04

#घोषणा WSA_FLAG_OVERLAPPED 0x01
#घोषणा WSA_FLAG_MULTIPOINT_C_मूल 0x02
#घोषणा WSA_FLAG_MULTIPOINT_C_LEAF 0x04
#घोषणा WSA_FLAG_MULTIPOINT_D_मूल 0x08
#घोषणा WSA_FLAG_MULTIPOINT_D_LEAF 0x10

#घोषणा IOC_UNIX 0x00000000
#घोषणा IOC_WS2 0x08000000
#घोषणा IOC_PROTOCOL 0x10000000
#घोषणा IOC_VENDOR 0x18000000

#घोषणा _WSAIO(x,y) (IOC_VOID|(x)|(y))
#घोषणा _WSAIOR(x,y) (IOC_OUT|(x)|(y))
#घोषणा _WSAIOW(x,y) (IOC_IN|(x)|(y))
#घोषणा _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#घोषणा SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#घोषणा SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#घोषणा SIO_FIND_ROUTE _WSAIOR(IOC_WS2,3)
#घोषणा SIO_FLUSH _WSAIO(IOC_WS2,4)
#घोषणा SIO_GET_BROADCAST_ADDRESS _WSAIOR(IOC_WS2,5)
#घोषणा SIO_GET_EXTENSION_FUNCTION_POINTER _WSAIORW(IOC_WS2,6)
#घोषणा SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#घोषणा SIO_GET_GROUP_QOS _WSAIORW(IOC_WS2,8)
#घोषणा SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#घोषणा SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#घोषणा SIO_SET_QOS _WSAIOW(IOC_WS2,11)
#घोषणा SIO_SET_GROUP_QOS _WSAIOW(IOC_WS2,12)
#घोषणा SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#घोषणा SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#घोषणा SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#घोषणा SIO_ADDRESS_LIST_QUERY _WSAIOR(IOC_WS2,22)
#घोषणा SIO_ADDRESS_LIST_CHANGE _WSAIO(IOC_WS2,23)
#घोषणा SIO_QUERY_TARGET_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#घोषणा SIO_ADDRESS_LIST_SORT _WSAIORW(IOC_WS2,25)

  प्रकार पूर्णांक (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_तथ्य,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_तथ्य,GROUP *g,DWORD_PTR dw_Callback_तथ्य);
  प्रकार व्योम (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#घोषणा SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  प्रकार क्रमागत _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_PORT,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  प्रकार काष्ठा _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    जोड़ {
      काष्ठा {
	HWND hWnd;
	UINT u_संदेश;
	WPARAM context;
      } WindowMessage;
      काष्ठा {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      काष्ठा {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      काष्ठा {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE hPort;
	ULONG_PTR कुंजी_3;
      } Port;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#घोषणा TH_NETDEV 0x00000001
#घोषणा TH_TAPI 0x00000002

  प्रकार काष्ठा sockaddr SOCKADDR;
  प्रकार काष्ठा sockaddr *PSOCKADDR;
  प्रकार काष्ठा sockaddr *LPSOCKADDR;
  प्रकार काष्ठा sockaddr_storage SOCKADDR_STORAGE;
  प्रकार काष्ठा sockaddr_storage *PSOCKADDR_STORAGE;
  प्रकार काष्ठा sockaddr_storage *LPSOCKADDR_STORAGE;

#अगर_अघोषित _tagBLOB_DEFINED
#घोषणा _tagBLOB_DEFINED
#घोषणा _BLOB_DEFINED
#घोषणा _LPBLOB_DEFINED
  प्रकार काष्ठा _BLOB {
    ULONG cb_आकार;
    BYTE *p_Blob_तथ्य;
  } BLOB,*LPBLOB;
#पूर्ण_अगर

#घोषणा SERVICE_MULTIPLE (0x00000001)

#घोषणा NS_ALL (0)

#घोषणा NS_SAP (1)
#घोषणा NS_NDS (2)
#घोषणा NS_PEER_BROWSE (3)
#घोषणा NS_SLP (5)
#घोषणा NS_DHCP (6)

#घोषणा NS_TCPIP_LOCAL (10)
#घोषणा NS_TCPIP_HOSTS (11)
#घोषणा NS_DNS (12)
#घोषणा NS_NETBT (13)
#घोषणा NS_WINS (14)
#घोषणा NS_NLA (15)

#घोषणा NS_NBP (20)

#घोषणा NS_MS (30)
#घोषणा NS_STDA (31)
#घोषणा NS_NTDS (32)

#घोषणा NS_X500 (40)
#घोषणा NS_NIS (41)
#घोषणा NS_NISPLUS (42)

#घोषणा NS_WRQ (50)

#घोषणा NS_NETDES (60)

#घोषणा RES_UNUSED_1 (0x00000001)
#घोषणा RES_FLUSH_CACHE (0x00000002)
#अगर_अघोषित RES_SERVICE
#घोषणा RES_SERVICE (0x00000004)
#पूर्ण_अगर

#घोषणा SERVICE_TYPE_मूल्य_IPXPORTA "IpxSocket"
#घोषणा SERVICE_TYPE_मूल्य_IPXPORTW L"IpxSocket"
#घोषणा SERVICE_TYPE_मूल्य_SAPIDA "SapId"
#घोषणा SERVICE_TYPE_मूल्य_SAPIDW L"SapId"

#घोषणा SERVICE_TYPE_मूल्य_TCPPORTA "TcpPort"
#घोषणा SERVICE_TYPE_मूल्य_TCPPORTW L"TcpPort"

#घोषणा SERVICE_TYPE_मूल्य_UDPPORTA "UdpPort"
#घोषणा SERVICE_TYPE_मूल्य_UDPPORTW L"UdpPort"

#घोषणा SERVICE_TYPE_मूल्य_OBJECTIDA "ObjectId"
#घोषणा SERVICE_TYPE_मूल्य_OBJECTIDW L"ObjectId"

#अगर_घोषित UNICODE

#घोषणा SERVICE_TYPE_मूल्य_SAPID SERVICE_TYPE_मूल्य_SAPIDW
#घोषणा SERVICE_TYPE_मूल्य_TCPPORT SERVICE_TYPE_मूल्य_TCPPORTW
#घोषणा SERVICE_TYPE_मूल्य_UDPPORT SERVICE_TYPE_मूल्य_UDPPORTW
#घोषणा SERVICE_TYPE_मूल्य_OBJECTID SERVICE_TYPE_मूल्य_OBJECTIDW
#अन्यथा

#घोषणा SERVICE_TYPE_मूल्य_SAPID SERVICE_TYPE_मूल्य_SAPIDA
#घोषणा SERVICE_TYPE_मूल्य_TCPPORT SERVICE_TYPE_मूल्य_TCPPORTA
#घोषणा SERVICE_TYPE_मूल्य_UDPPORT SERVICE_TYPE_मूल्य_UDPPORTA
#घोषणा SERVICE_TYPE_मूल्य_OBJECTID SERVICE_TYPE_मूल्य_OBJECTIDA
#पूर्ण_अगर

#अगर_अघोषित __CSADDR_DEFINED__
#घोषणा __CSADDR_DEFINED__

  प्रकार काष्ठा _SOCKET_ADDRESS {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_लंबाई;
  } SOCKET_ADDRESS,*PSOCKET_ADDRESS,*LPSOCKET_ADDRESS;

  प्रकार काष्ठा _CSADDR_INFO {
    SOCKET_ADDRESS LocalAddr;
    SOCKET_ADDRESS RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#पूर्ण_अगर

  प्रकार काष्ठा _SOCKET_ADDRESS_LIST {
    INT i_Address_गिनती;
    SOCKET_ADDRESS Address[1];
  } SOCKET_ADDRESS_LIST,*LPSOCKET_ADDRESS_LIST;

  प्रकार काष्ठा _AFPROTOCOLS {
    INT iAddressFamily;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  प्रकार क्रमागत _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  प्रकार काष्ठा _WSAVersion {
    DWORD dwVersion;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  प्रकार काष्ठा _WSAQuerySetA {
    DWORD dw_आकार;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lpVersion;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_संख्या_Of_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_संख्या_Of_Cs_Addrs;
    LPCSADDR_INFO lpcsa_बफर;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  प्रकार काष्ठा _WSAQuerySetW {
    DWORD dw_आकार;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lpVersion;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_संख्या_Of_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_संख्या_Of_Cs_Addrs;
    LPCSADDR_INFO lpcsa_बफर;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#अगर_घोषित UNICODE
  प्रकार WSAQUERYSETW WSAQUERYSET;
  प्रकार PWSAQUERYSETW PWSAQUERYSET;
  प्रकार LPWSAQUERYSETW LPWSAQUERYSET;
#अन्यथा
  प्रकार WSAQUERYSETA WSAQUERYSET;
  प्रकार PWSAQUERYSETA PWSAQUERYSET;
  प्रकार LPWSAQUERYSETA LPWSAQUERYSET;
#पूर्ण_अगर

#घोषणा LUP_DEEP 0x0001
#घोषणा LUP_CONTAINERS 0x0002
#घोषणा LUP_NOCONTAINERS 0x0004
#घोषणा LUP_NEAREST 0x0008
#घोषणा LUP_RETURN_NAME 0x0010
#घोषणा LUP_RETURN_TYPE 0x0020
#घोषणा LUP_RETURN_VERSION 0x0040
#घोषणा LUP_RETURN_COMMENT 0x0080
#घोषणा LUP_RETURN_ADDR 0x0100
#घोषणा LUP_RETURN_BLOB 0x0200
#घोषणा LUP_RETURN_ALIASES 0x0400
#घोषणा LUP_RETURN_QUERY_STRING 0x0800
#घोषणा LUP_RETURN_ALL 0x0FF0
#घोषणा LUP_RES_SERVICE 0x8000

#घोषणा LUP_FLUSHCACHE 0x1000
#घोषणा LUP_FLUSHPREVIOUS 0x2000

#घोषणा परिणाम_IS_ALIAS 0x0001
#घोषणा परिणाम_IS_ADDED 0x0010
#घोषणा परिणाम_IS_CHANGED 0x0020
#घोषणा परिणाम_IS_DELETED 0x0040

  प्रकार क्रमागत _WSAESETSERVICEOP {
    RNRSERVICE_REGISTER=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  प्रकार काष्ठा _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_मूल्य_Type;
    DWORD dw_मूल्य_आकार;
    LPVOID lp_मूल्य;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  प्रकार काष्ठा _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_मूल्य_Type;
    DWORD dw_मूल्य_आकार;
    LPVOID lp_मूल्य;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#अगर_घोषित UNICODE
  प्रकार WSANSCLASSINFOW WSANSCLASSINFO;
  प्रकार PWSANSCLASSINFOW PWSANSCLASSINFO;
  प्रकार LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#अन्यथा
  प्रकार WSANSCLASSINFOA WSANSCLASSINFO;
  प्रकार PWSANSCLASSINFOA PWSANSCLASSINFO;
  प्रकार LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#पूर्ण_अगर

  प्रकार काष्ठा _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_गिनती;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  प्रकार काष्ठा _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_गिनती;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#अगर_घोषित UNICODE
  प्रकार WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  प्रकार PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  प्रकार LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#अन्यथा
  प्रकार WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  प्रकार PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  प्रकार LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#पूर्ण_अगर

  प्रकार काष्ठा _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL fActive;
    DWORD dwVersion;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  प्रकार काष्ठा _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL fActive;
    DWORD dwVersion;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#अगर_घोषित UNICODE
  प्रकार WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  प्रकार PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  प्रकार LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#अन्यथा
  प्रकार WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  प्रकार PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  प्रकार LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#पूर्ण_अगर

#अगर INCL_WINSOCK_API_TYPEDEFS
#अगर_घोषित UNICODE
#घोषणा LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#घोषणा LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#घोषणा LPFN_WSASOCKET LPFN_WSASOCKETW
#घोषणा LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#घोषणा LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#घोषणा LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#घोषणा LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#घोषणा LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#घोषणा LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#घोषणा LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#घोषणा LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#घोषणा LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#अन्यथा
#घोषणा LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#घोषणा LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#घोषणा LPFN_WSASOCKET LPFN_WSASOCKETA
#घोषणा LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#घोषणा LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#घोषणा LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#घोषणा LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#घोषणा LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#घोषणा LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#घोषणा LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#घोषणा LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#घोषणा LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#पूर्ण_अगर

  प्रकार SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,काष्ठा sockaddr *addr,पूर्णांक *addrlen);
  प्रकार पूर्णांक (WSAAPI *LPFN_BIND)(SOCKET s,स्थिर काष्ठा sockaddr *name,पूर्णांक namelen);
  प्रकार पूर्णांक (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  प्रकार पूर्णांक (WSAAPI *LPFN_CONNECT)(SOCKET s,स्थिर काष्ठा sockaddr *name,पूर्णांक namelen);
  प्रकार पूर्णांक (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,दीर्घ cmd,u_long *argp);
  प्रकार पूर्णांक (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,काष्ठा sockaddr *name,पूर्णांक *namelen);
  प्रकार पूर्णांक (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,काष्ठा sockaddr *name,पूर्णांक *namelen);
  प्रकार पूर्णांक (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,पूर्णांक level,पूर्णांक optname,अक्षर *optval,पूर्णांक *optlen);
  प्रकार u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  प्रकार u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  प्रकार अचिन्हित दीर्घ (WSAAPI *LPFN_INET_ADDR)(स्थिर अक्षर *cp);
  प्रकार अक्षर *(WSAAPI *LPFN_INET_NTOA)(काष्ठा in_addr in);
  प्रकार पूर्णांक (WSAAPI *LPFN_LISTEN)(SOCKET s,पूर्णांक backlog);
  प्रकार u_long (WSAAPI *LPFN_NTOHL)(u_long netlong);
  प्रकार u_short (WSAAPI *LPFN_NTOHS)(u_short netshort);
  प्रकार पूर्णांक (WSAAPI *LPFN_RECV)(SOCKET s,अक्षर *buf,पूर्णांक len,पूर्णांक flags);
  प्रकार पूर्णांक (WSAAPI *LPFN_RECVFROM)(SOCKET s,अक्षर *buf,पूर्णांक len,पूर्णांक flags,काष्ठा sockaddr *from,पूर्णांक *fromlen);
  प्रकार पूर्णांक (WSAAPI *LPFN_SELECT)(पूर्णांक nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,स्थिर काष्ठा timeval *timeout);
  प्रकार पूर्णांक (WSAAPI *LPFN_SEND)(SOCKET s,स्थिर अक्षर *buf,पूर्णांक len,पूर्णांक flags);
  प्रकार पूर्णांक (WSAAPI *LPFN_SENDTO)(SOCKET s,स्थिर अक्षर *buf,पूर्णांक len,पूर्णांक flags,स्थिर काष्ठा sockaddr *to,पूर्णांक tolen);
  प्रकार पूर्णांक (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s,पूर्णांक level,पूर्णांक optname,स्थिर अक्षर *optval,पूर्णांक optlen);
  प्रकार पूर्णांक (WSAAPI *LPFN_SHUTDOWN)(SOCKET s,पूर्णांक how);
  प्रकार SOCKET (WSAAPI *LPFN_SOCKET)(पूर्णांक af,पूर्णांक type,पूर्णांक protocol);
  प्रकार काष्ठा hostent *(WSAAPI *LPFN_GETHOSTBYADDR)(स्थिर अक्षर *addr,पूर्णांक len,पूर्णांक type);
  प्रकार काष्ठा hostent *(WSAAPI *LPFN_GETHOSTBYNAME)(स्थिर अक्षर *name);
  प्रकार पूर्णांक (WSAAPI *LPFN_GETHOSTNAME)(अक्षर *name,पूर्णांक namelen);
  प्रकार काष्ठा servent *(WSAAPI *LPFN_GETSERVBYPORT)(पूर्णांक port,स्थिर अक्षर *proto);
  प्रकार काष्ठा servent *(WSAAPI *LPFN_GETSERVBYNAME)(स्थिर अक्षर *name,स्थिर अक्षर *proto);
  प्रकार काष्ठा protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(पूर्णांक संख्या_3);
  प्रकार काष्ठा protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(स्थिर अक्षर *name);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSASTARTUP)(WORD wVersionRequested,LPWSADATA lpWSAData);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSACLEANUP)(व्योम);
  प्रकार व्योम (WSAAPI *LPFN_WSASETLASTERROR)(पूर्णांक iError);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAGETLASTERROR)(व्योम);
  प्रकार WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(व्योम);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(व्योम);
  प्रकार FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lpBlockFunc);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(व्योम);
  प्रकार HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_संदेश,स्थिर अक्षर *name,स्थिर अक्षर *proto,अक्षर *buf,पूर्णांक buflen);
  प्रकार HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_संदेश,पूर्णांक port,स्थिर अक्षर *proto,अक्षर *buf,पूर्णांक buflen);
  प्रकार HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_संदेश,स्थिर अक्षर *name,अक्षर *buf,पूर्णांक buflen);
  प्रकार HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_संदेश,पूर्णांक संख्या_3,अक्षर *buf,पूर्णांक buflen);
  प्रकार HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_संदेश,स्थिर अक्षर *name,अक्षर *buf,पूर्णांक buflen);
  प्रकार HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_संदेश,स्थिर अक्षर *addr,पूर्णांक len,पूर्णांक type,अक्षर *buf,पूर्णांक buflen);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_संदेश,दीर्घ lEvent);
  प्रकार SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,काष्ठा sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_तथ्य);
  प्रकार WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSACONNECT)(SOCKET s,स्थिर काष्ठा sockaddr *name,पूर्णांक namelen,LPWSABUF lp_Caller_तथ्य,LPWSABUF lp_Callee_तथ्य,LPQOS lpSQOS,LPQOS lpGQOS);
  प्रकार WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(व्योम);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lpNetworkEvents);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_बफर,LPDWORD lpdw_बफर_लंबाई);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_बफर,LPDWORD lpdw_बफर_लंबाई);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,दीर्घ lNetworkEvents);
  प्रकार WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  प्रकार WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dwIoControlCode,LPVOID lpv_In_बफर,DWORD cb_In_बफर,LPVOID lpv_Out_बफर,DWORD cb_Out_बफर,LPDWORD lpcbBytesReturned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकार SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,स्थिर काष्ठा sockaddr *name,पूर्णांक namelen,LPWSABUF lp_Caller_तथ्य,LPWSABUF lp_Callee_तथ्य,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गिनती,LPDWORD lp_संख्या_Of_Bytes_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_तथ्य);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गिनती,LPDWORD lp_संख्या_Of_Bytes_Recvd,LPDWORD lpFlags,काष्ठा sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकार WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गिनती,LPDWORD lp_संख्या_Of_Bytes_Sent,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_तथ्य);
  प्रकार पूर्णांक (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गिनती,LPDWORD lp_संख्या_Of_Bytes_Sent,DWORD dwFlags,स्थिर काष्ठा sockaddr *lpTo,पूर्णांक iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकार WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  प्रकार SOCKET (WSAAPI *LPFN_WSASOCKETA)(पूर्णांक af,पूर्णांक type,पूर्णांक protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,GROUP g,DWORD dwFlags);
  प्रकार SOCKET (WSAAPI *LPFN_WSASOCKETW)(पूर्णांक af,पूर्णांक type,पूर्णांक protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,GROUP g,DWORD dwFlags);
  प्रकार DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,स्थिर WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  प्रकार INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsaAddress,DWORD dw_Address_लंबाई,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpszAddressString,LPDWORD lpdw_Address_String_लंबाई);
  प्रकार INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsaAddress,DWORD dw_Address_लंबाई,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpszAddressString,LPDWORD lpdw_Address_String_लंबाई);
  प्रकार INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lp_Address_लंबाई);
  प्रकार INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lp_Address_लंबाई);
  प्रकार INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  प्रकार INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  प्रकार INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_बफर_लंबाई,LPWSAQUERYSETA lpqsResults);
  प्रकार INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_बफर_लंबाई,LPWSAQUERYSETW lpqsResults);
  प्रकार INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dwControlCode,LPVOID lpv_In_बफर,DWORD cb_In_बफर,LPVOID lpv_Out_बफर,DWORD cb_Out_बफर,LPDWORD lpcbBytesReturned,LPWSACOMPLETION lpCompletion);
  प्रकार INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  प्रकार INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  प्रकार INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  प्रकार INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  प्रकार INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_आकार,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  प्रकार INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_आकार,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  प्रकार INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_बफर_लंबाई,LPWSANAMESPACE_INFOA lpnsp_बफर);
  प्रकार INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_बफर_लंबाई,LPWSANAMESPACE_INFOW lpnsp_बफर);
  प्रकार INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_बफर_लंबाई);
  प्रकार INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_बफर_लंबाई);
  प्रकार INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  प्रकार INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  प्रकार INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#पूर्ण_अगर

#अगर_घोषित UNICODE
#घोषणा WSADuplicateSocket WSADuplicateSocketW
#घोषणा WSAEnumProtocols WSAEnumProtocolsW
#घोषणा WSAAddressToString WSAAddressToStringW
#घोषणा WSASocket WSASocketW
#घोषणा WSAStringToAddress WSAStringToAddressW
#घोषणा WSALookupServiceBegin WSALookupServiceBeginW
#घोषणा WSALookup_Service_अग्र WSALookup_Service_अग्र_W
#घोषणा WSAInstallServiceClass WSAInstallServiceClassW
#घोषणा WSAGetServiceClassInfo WSAGetServiceClassInfoW
#घोषणा WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#घोषणा WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#घोषणा WSASetService WSASetServiceW
#अन्यथा
#घोषणा WSADuplicateSocket WSADuplicateSocketA
#घोषणा WSAEnumProtocols WSAEnumProtocolsA
#घोषणा WSASocket WSASocketA
#घोषणा WSAAddressToString WSAAddressToStringA
#घोषणा WSAStringToAddress WSAStringToAddressA
#घोषणा WSALookupServiceBegin WSALookupServiceBeginA
#घोषणा WSALookup_Service_अग्र WSALookup_Service_अग्र_A
#घोषणा WSAInstallServiceClass WSAInstallServiceClassA
#घोषणा WSAGetServiceClassInfo WSAGetServiceClassInfoA
#घोषणा WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#घोषणा WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#घोषणा WSASetService WSASetServiceA
#पूर्ण_अगर

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,काष्ठा sockaddr *addr,पूर्णांक *addrlen);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI bind(SOCKET s,स्थिर काष्ठा sockaddr *name,पूर्णांक namelen);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI connect(SOCKET s,स्थिर काष्ठा sockaddr *name,पूर्णांक namelen);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI ioctlsocket(SOCKET s,दीर्घ cmd,u_long *argp);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI getpeername(SOCKET s,काष्ठा sockaddr *name,पूर्णांक *namelen);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI getsockname(SOCKET s,काष्ठा sockaddr *name,पूर्णांक *namelen);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI getsockopt(SOCKET s,पूर्णांक level,पूर्णांक optname,अक्षर *optval,पूर्णांक *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE अचिन्हित दीर्घ WSAAPI inet_addr(स्थिर अक्षर *cp);
  WINSOCK_API_LINKAGE अक्षर *WSAAPI inet_ntoa(काष्ठा in_addr in);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI listen(SOCKET s,पूर्णांक backlog);
  WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI recv(SOCKET s,अक्षर *buf,पूर्णांक len,पूर्णांक flags);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI recvfrom(SOCKET s,अक्षर *buf,पूर्णांक len,पूर्णांक flags,काष्ठा sockaddr *from,पूर्णांक *fromlen);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI select(पूर्णांक nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,स्थिर काष्ठा timeval *timeout);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI send(SOCKET s,स्थिर अक्षर *buf,पूर्णांक len,पूर्णांक flags);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI sendto(SOCKET s,स्थिर अक्षर *buf,पूर्णांक len,पूर्णांक flags,स्थिर काष्ठा sockaddr *to,पूर्णांक tolen);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI setsockopt(SOCKET s,पूर्णांक level,पूर्णांक optname,स्थिर अक्षर *optval,पूर्णांक optlen);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI shutdown(SOCKET s,पूर्णांक how);
  WINSOCK_API_LINKAGE SOCKET WSAAPI socket(पूर्णांक af,पूर्णांक type,पूर्णांक protocol);
  WINSOCK_API_LINKAGE काष्ठा hostent *WSAAPI gethostbyaddr(स्थिर अक्षर *addr,पूर्णांक len,पूर्णांक type);
  WINSOCK_API_LINKAGE काष्ठा hostent *WSAAPI gethostbyname(स्थिर अक्षर *name);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI gethostname(अक्षर *name,पूर्णांक namelen);
  WINSOCK_API_LINKAGE काष्ठा servent *WSAAPI getservbyport(पूर्णांक port,स्थिर अक्षर *proto);
  WINSOCK_API_LINKAGE काष्ठा servent *WSAAPI getservbyname(स्थिर अक्षर *name,स्थिर अक्षर *proto);
  WINSOCK_API_LINKAGE काष्ठा protoent *WSAAPI getprotobynumber(पूर्णांक संख्या_3);
  WINSOCK_API_LINKAGE काष्ठा protoent *WSAAPI getprotobyname(स्थिर अक्षर *name);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAStartup(WORD wVersionRequested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSACleanup(व्योम);
  WINSOCK_API_LINKAGE व्योम WSAAPI WSASetLastError(पूर्णांक iError);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAGetLastError(व्योम);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(व्योम);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAUnhookBlockingHook(व्योम);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lpBlockFunc);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSACancelBlockingCall(व्योम);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_संदेश,स्थिर अक्षर *name,स्थिर अक्षर *proto,अक्षर *buf,पूर्णांक buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByPort(HWND hWnd,u_int w_संदेश,पूर्णांक port,स्थिर अक्षर *proto,अक्षर *buf,पूर्णांक buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_संदेश,स्थिर अक्षर *name,अक्षर *buf,पूर्णांक buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_संख्या(HWND hWnd,u_int w_संदेश,पूर्णांक संख्या_3,अक्षर *buf,पूर्णांक buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_संदेश,स्थिर अक्षर *name,अक्षर *buf,पूर्णांक buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_संदेश,स्थिर अक्षर *addr,पूर्णांक len,पूर्णांक type,अक्षर *buf,पूर्णांक buflen);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_संदेश,दीर्घ lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,काष्ठा sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_तथ्य);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAConnect(SOCKET s,स्थिर काष्ठा sockaddr *name,पूर्णांक namelen,LPWSABUF lp_Caller_तथ्य,LPWSABUF lp_Callee_तथ्य,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(व्योम);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAEnumNetworkEvents(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lpNetworkEvents);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_बफर,LPDWORD lpdw_बफर_लंबाई);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_बफर,LPDWORD lpdw_बफर_लंबाई);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,दीर्घ lNetworkEvents);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_परिणाम(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAIoctl(SOCKET s,DWORD dwIoControlCode,LPVOID lpv_In_बफर,DWORD cb_In_बफर,LPVOID lpv_Out_बफर,DWORD cb_Out_बफर,LPDWORD lpcbBytesReturned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoinLeaf(SOCKET s,स्थिर काष्ठा sockaddr *name,पूर्णांक namelen,LPWSABUF lp_Caller_तथ्य,LPWSABUF lp_Callee_तथ्य,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गिनती,LPDWORD lp_संख्या_Of_Bytes_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_तथ्य);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गिनती,LPDWORD lp_संख्या_Of_Bytes_Recvd,LPDWORD lpFlags,काष्ठा sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गिनती,LPDWORD lp_संख्या_Of_Bytes_Sent,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_तथ्य);
  WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSASendTo(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गिनती,LPDWORD lp_संख्या_Of_Bytes_Sent,DWORD dwFlags,स्थिर काष्ठा sockaddr *lpTo,पूर्णांक iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(पूर्णांक af,पूर्णांक type,पूर्णांक protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,GROUP g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(पूर्णांक af,पूर्णांक type,पूर्णांक protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,GROUP g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWaitForMultipleEvents(DWORD cEvents,स्थिर WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddressToStringA(LPSOCKADDR lpsaAddress,DWORD dw_Address_लंबाई,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpszAddressString,LPDWORD lpdw_Address_String_लंबाई);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddressToStringW(LPSOCKADDR lpsaAddress,DWORD dw_Address_लंबाई,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpszAddressString,LPDWORD lpdw_Address_String_लंबाई);
  WINSOCK_API_LINKAGE INT WSAAPI WSAStringToAddressA(LPSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lp_Address_लंबाई);
  WINSOCK_API_LINKAGE INT WSAAPI WSAStringToAddressW(LPWSTR AddressString,INT AddressFamily,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lpAddress,LPINT lp_Address_लंबाई);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_अग्र_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_बफर_लंबाई,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_अग्र_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_बफर_लंबाई,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dwControlCode,LPVOID lpv_In_बफर,DWORD cb_In_बफर,LPVOID lpv_Out_बफर,DWORD cb_Out_बफर,LPDWORD lpcbBytesReturned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceEnd(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_आकार,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_आकार,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_बफर_लंबाई,LPWSANAMESPACE_INFOA lpnsp_बफर);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_बफर_लंबाई,LPWSANAMESPACE_INFOW lpnsp_बफर);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_बफर_लंबाई);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_बफर_लंबाई);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  प्रकार काष्ठा sockaddr_in SOCKADDR_IN;
  प्रकार काष्ठा sockaddr_in *PSOCKADDR_IN;
  प्रकार काष्ठा sockaddr_in *LPSOCKADDR_IN;

  प्रकार काष्ठा linger LINGER;
  प्रकार काष्ठा linger *PLINGER;
  प्रकार काष्ठा linger *LPLINGER;

  प्रकार काष्ठा in_addr IN_ADDR;
  प्रकार काष्ठा in_addr *PIN_ADDR;
  प्रकार काष्ठा in_addr *LPIN_ADDR;

  प्रकार काष्ठा fd_set FD_SET;
  प्रकार काष्ठा fd_set *PFD_SET;
  प्रकार काष्ठा fd_set *LPFD_SET;

  प्रकार काष्ठा hostent HOSTENT;
  प्रकार काष्ठा hostent *PHOSTENT;
  प्रकार काष्ठा hostent *LPHOSTENT;

  प्रकार काष्ठा servent SERVENT;
  प्रकार काष्ठा servent *PSERVENT;
  प्रकार काष्ठा servent *LPSERVENT;

  प्रकार काष्ठा protoent PROTOENT;
  प्रकार काष्ठा protoent *PPROTOENT;
  प्रकार काष्ठा protoent *LPPROTOENT;

  प्रकार काष्ठा timeval TIMEVAL;
  प्रकार काष्ठा timeval *PTIMEVAL;
  प्रकार काष्ठा timeval *LPTIMEVAL;

#घोषणा WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#घोषणा WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#घोषणा WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#घोषणा WSAGETASYNCERROR(lParam) HIWORD(lParam)
#घोषणा WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#घोषणा WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#घोषणा POLLRDNORM  0x0100
#घोषणा POLLRDBAND  0x0200
#घोषणा POLLIN      (POLLRDNORM | POLLRDBAND)
#घोषणा POLLPRI     0x0400

#घोषणा POLLWRNORM  0x0010
#घोषणा POLLOUT     (POLLWRNORM)
#घोषणा POLLWRBAND  0x0020

#घोषणा POLLERR     0x0001
#घोषणा POLLHUP     0x0002
#घोषणा POLLNVAL    0x0004

प्रकार काष्ठा pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE पूर्णांक WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#अगर_घोषित _NEED_POPPACK
#समावेश <poppack.h>
#पूर्ण_अगर

#अगर_घोषित IPV6STRICT
#समावेश <wsipv6ok.h>
#पूर्ण_अगर

#अगर_अघोषित _WINSOCKAPI_
#घोषणा _WINSOCKAPI_
#पूर्ण_अगर

#अगर_घोषित _INC_WINSOCK_H
#समावेश <mswsock.h>
#पूर्ण_अगर

#पूर्ण_अगर
