/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#यदि_अपरिभाषितम् _WINSOCK2API_
#परिभाषय _WINSOCK2API_

#यदि_अपरिभाषितम् INCL_WINSOCK_API_TYPEDEFS
#परिभाषय INCL_WINSOCK_API_TYPEDEFS 0
#यदि_अन्तः

#यदि_अपरिभाषितम् _INC_WINDOWS
#अन्तर्भाव <windows.h>
#यदि_अन्तः

#यदि_अपरिभाषितम् MAKEWORD
#परिभाषय MAKEWORD(नीचः,उच्चः) ((WORD)(((BYTE)(नीचः)) | ((WORD)((BYTE)(उच्चः))) << 8))
#यदि_अन्तः

#यदि_अपरिभाषितम् WINSOCK_संस्करणम्
#परिभाषय WINSOCK_संस्करणम् MAKEWORD(2,2)
#यदि_अन्तः

#यदि_अपरिभाषितम् WINSOCK_API_LINKAGE
#यदि_परिभाषितम् DECLSPEC_IMPORT
#परिभाषय WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#अन्यथा
#परिभाषय WINSOCK_API_LINKAGE
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् _WINSOCK_SOCKET_DEFINED
#परिभाषय _WINSOCK_SOCKET_DEFINED
  प्रकारनिर्देश अचिह्नित वर्ण u_char;
  प्रकारनिर्देश अचिह्नित ह्रस्व u_short;
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क u_int;
  प्रकारनिर्देश अचिह्नित दीर्घ u_long;
  __MINGW_EXTENSION प्रकारनिर्देश अचिह्नित __int64 u_int64;
  प्रकारनिर्देश INT_PTR SOCKET;
#यदि_अन्तः

#यदि_अपरिभाषितम् FD_SETSIZE
#परिभाषय FD_SETSIZE 64
#यदि_अन्तः

  प्रकारनिर्देश संरचना fd_set {
    u_int fd_गणनम्;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  बाह्य पूर्णाङ्क WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#परिभाषय FD_CLR(fd,समुच्चयः) कुरु { u_int __i; प्रति(__i = 0;__i < ((fd_set *)(समुच्चयः))->fd_गणनम्;__i++) { यदि (((fd_set *)(समुच्चयः))->fd_array[__i]==fd) { यावत् (__i < ((fd_set *)(समुच्चयः))->fd_गणनम्-1) { ((fd_set *)(समुच्चयः))->fd_array[__i] = ((fd_set *)(समुच्चयः))->fd_array[__i+1]; __i++; } ((fd_set *)(समुच्चयः))->fd_गणनम्--; भङ्ग; } } } यावत्(0)
#परिभाषय FD_SET(fd,समुच्चयः) कुरु { u_int __i; प्रति(__i = 0;__i < ((fd_set *)(समुच्चयः))->fd_गणनम्;__i++) { यदि (((fd_set *)(समुच्चयः))->fd_array[__i]==(fd)) { भङ्ग; } } यदि (__i==((fd_set *)(समुच्चयः))->fd_गणनम्) { यदि (((fd_set *)(समुच्चयः))->fd_गणनम् < FD_SETSIZE) { ((fd_set *)(समुच्चयः))->fd_array[__i] = (fd); ((fd_set *)(समुच्चयः))->fd_गणनम्++; } } } यावत्(0)
#परिभाषय FD_ZERO(समुच्चयः) (((fd_set *)(समुच्चयः))->fd_गणनम्=0)
#परिभाषय FD_ISSET(fd,समुच्चयः) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(समुच्चयः))

#यदि_अपरिभाषितम् _TIMEVAL_DEFINED /* also in winsock[2].h */
#परिभाषय _TIMEVAL_DEFINED
  संरचना timeval {
    दीर्घ tv_sec;
    दीर्घ tv_usec;
  };

#परिभाषय timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#परिभाषय timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#परिभाषय timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#यदि_अन्तः /* _TIMEVAL_DEFINED */

#परिभाषय IOCPARM_आवरणम् 0x7f
#परिभाषय IOC_VOID 0x20000000
#परिभाषय IOC_बहिर्गमनम् 0x40000000
#परिभाषय IOC_अन्तर् 0x80000000
#परिभाषय IOC_INOUT (IOC_अन्तर्|IOC_बहिर्गमनम्)

#परिभाषय _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#परिभाषय _IOR(x,y,t) (IOC_बहिर्गमनम्|(((दीर्घ)परिमाण(t)&IOCPARM_आवरणम्)<<16)|((x)<<8)|(y))
#परिभाषय _IOW(x,y,t) (IOC_अन्तर्|(((दीर्घ)परिमाण(t)&IOCPARM_आवरणम्)<<16)|((x)<<8)|(y))

#परिभाषय FIONREAD _IOR('f',127,u_long)
#परिभाषय FIONBIO _IOW('f',126,u_long)
#परिभाषय FIOASYNC _IOW('f',125,u_long)

#परिभाषय SIOCSHIWAT _IOW('s',0,u_long)
#परिभाषय SIOCGHIWAT _IOR('s',1,u_long)
#परिभाषय SIOCSLOWAT _IOW('s',2,u_long)
#परिभाषय SIOCGLOWAT _IOR('s',3,u_long)
#परिभाषय SIOCATMARK _IOR('s',7,u_long)

#परिभाषय h_addr h_addr_list[0]

  संरचना hostent {
    वर्ण *h_name;
    वर्ण **h_aliases;
    ह्रस्व h_addrtype;
    ह्रस्व h_दीर्घता;
    वर्ण **h_addr_list;
  };

  संरचना netent {
    वर्ण *n_name;
    वर्ण **n_aliases;
    ह्रस्व n_addrtype;
    u_long n_net;
  };

  संरचना servent {
    वर्ण *s_name;
    वर्ण **s_aliases;
#यदि_परिभाषितम् _WIN64
    वर्ण *s_proto;
    ह्रस्व s_पत्तनम्;
#अन्यथा
    ह्रस्व s_पत्तनम्;
    वर्ण *s_proto;
#यदि_अन्तः
  };

  संरचना protoent {
    वर्ण *p_name;
    वर्ण **p_aliases;
    ह्रस्व p_proto;
  };

#परिभाषय IPPROTO_IP 0
#परिभाषय IPPROTO_HOPOPTS 0
#परिभाषय IPPROTO_ICMP 1
#परिभाषय IPPROTO_IGMP 2
#परिभाषय IPPROTO_GGP 3
#परिभाषय IPPROTO_IPV4 4
#परिभाषय IPPROTO_TCP 6
#परिभाषय IPPROTO_PUP 12
#परिभाषय IPPROTO_UDP 17
#परिभाषय IPPROTO_IDP 22
#परिभाषय IPPROTO_IPV6 41
#परिभाषय IPPROTO_ROUTING 43
#परिभाषय IPPROTO_FRAGMENT 44
#परिभाषय IPPROTO_ESP 50
#परिभाषय IPPROTO_AH 51
#परिभाषय IPPROTO_ICMPV6 58
#परिभाषय IPPROTO_NONE 59
#परिभाषय IPPROTO_DSTOPTS 60
#परिभाषय IPPROTO_ND 77
#परिभाषय IPPROTO_ICLFXBM 78

#परिभाषय IPPROTO_RAW 255
#परिभाषय IPPROTO_MAX 256

#परिभाषय IPPORT_ECHO 7
#परिभाषय IPPORT_DISCARD 9
#परिभाषय IPPORT_SYSTAT 11
#परिभाषय IPPORT_DAYTIME 13
#परिभाषय IPPORT_NETSTAT 15
#परिभाषय IPPORT_FTP 21
#परिभाषय IPPORT_TELNET 23
#परिभाषय IPPORT_SMTP 25
#परिभाषय IPPORT_TIMESERVER 37
#परिभाषय IPPORT_NAMESERVER 42
#परिभाषय IPPORT_WHOIS 43
#परिभाषय IPPORT_MTP 57

#परिभाषय IPPORT_TFTP 69
#परिभाषय IPPORT_RJE 77
#परिभाषय IPPORT_FINGER 79
#परिभाषय IPPORT_TTYLINK 87
#परिभाषय IPPORT_SUPDUP 95

#परिभाषय IPPORT_EXECSERVER 512
#परिभाषय IPPORT_LOGINSERVER 513
#परिभाषय IPPORT_CMDSERVER 514
#परिभाषय IPPORT_EFSSERVER 520

#परिभाषय IPPORT_BIFFUDP 512
#परिभाषय IPPORT_WHOSERVER 513
#परिभाषय IPPORT_ROUTESERVER 520

#परिभाषय IPPORT_RESERVED 1024

#परिभाषय IMPLINK_IP 155
#परिभाषय IMPLINK_LOWEXPER 156
#परिभाषय IMPLINK_HIGHEXPER 158

#यदि_अपरिभाषितम् s_addr

  संरचना अन्तर्_addr {
    सङ्घ {
      संरचना { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      संरचना { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#परिभाषय s_addr S_un.S_addr
#परिभाषय s_host S_un.S_un_b.s_b2
#परिभाषय s_net S_un.S_un_b.s_b1
#परिभाषय s_imp S_un.S_un_w.s_w2
#परिभाषय s_impno S_un.S_un_b.s_b4
#परिभाषय s_lh S_un.S_un_b.s_b3

#यदि_अन्तः

#परिभाषय अन्तर्_CLASSA(i) (((दीर्घ)(i) & 0x80000000)==0)
#परिभाषय अन्तर्_CLASSA_NET 0xff000000
#परिभाषय अन्तर्_CLASSA_NSHIFT 24
#परिभाषय अन्तर्_CLASSA_HOST 0x00ffffff
#परिभाषय अन्तर्_CLASSA_MAX 128

#परिभाषय अन्तर्_CLASSB(i) (((दीर्घ)(i) & 0xc0000000)==0x80000000)
#परिभाषय अन्तर्_CLASSB_NET 0xffff0000
#परिभाषय अन्तर्_CLASSB_NSHIFT 16
#परिभाषय अन्तर्_CLASSB_HOST 0x0000ffff
#परिभाषय अन्तर्_CLASSB_MAX 65536

#परिभाषय अन्तर्_CLASSC(i) (((दीर्घ)(i) & 0xe0000000)==0xc0000000)
#परिभाषय अन्तर्_CLASSC_NET 0xffffff00
#परिभाषय अन्तर्_CLASSC_NSHIFT 8
#परिभाषय अन्तर्_CLASSC_HOST 0x000000ff

#परिभाषय अन्तर्_CLASSD(i) (((दीर्घ)(i) & 0xf0000000)==0xe0000000)
#परिभाषय अन्तर्_CLASSD_NET 0xf0000000
#परिभाषय अन्तर्_CLASSD_NSHIFT 28
#परिभाषय अन्तर्_CLASSD_HOST 0x0fffffff
#परिभाषय अन्तर्_MULTICAST(i) अन्तर्_CLASSD(i)

#परिभाषय INADDR_ANY (u_long)0x00000000
#परिभाषय INADDR_LOOPBACK 0x7f000001
#परिभाषय INADDR_प्रसारणम् (u_long)0xffffffff
#परिभाषय INADDR_NONE 0xffffffff

#परिभाषय ADDR_ANY INADDR_ANY

  संरचना sockaddr_अन्तर् {
    ह्रस्व sin_family;
    u_short sin_पत्तनम्;
    संरचना अन्तर्_addr sin_addr;
    वर्ण sin_zero[8];
  };

#परिभाषय WSADESCRIPTION_LEN 256
#परिभाषय WSASYS_स्थितिः_LEN 128

  प्रकारनिर्देश संरचना WSAData {
    WORD w_संस्करणम्;
    WORD w_उच्चः_संस्करणम्;
#यदि_परिभाषितम् _WIN64
    अचिह्नित ह्रस्व iMaxSockets;
    अचिह्नित ह्रस्व iMaxUdpDg;
    वर्ण *lpVendorInfo;
    वर्ण szDescription[WSADESCRIPTION_LEN+1];
    वर्ण sz_System_स्थितिः[WSASYS_स्थितिः_LEN+1];
#अन्यथा
    वर्ण szDescription[WSADESCRIPTION_LEN+1];
    वर्ण sz_System_स्थितिः[WSASYS_स्थितिः_LEN+1];
    अचिह्नित ह्रस्व iMaxSockets;
    अचिह्नित ह्रस्व iMaxUdpDg;
    वर्ण *lpVendorInfo;
#यदि_अन्तः
  } WSADATA,*LPWSADATA;

#परिभाषय INVALID_SOCKET (SOCKET)(~0)
#परिभाषय SOCKET_ERROR (-1)

#परिभाषय FROM_PROTOCOL_INFO (-1)

#परिभाषय SOCK_प्रवाहः 1
#परिभाषय SOCK_DGRAM 2
#परिभाषय SOCK_RAW 3
#परिभाषय SOCK_RDM 4
#परिभाषय SOCK_SEQPACKET 5

#परिभाषय SO_DEBUG 0x0001
#परिभाषय SO_ACCEPTCONN 0x0002
#परिभाषय SO_REUSEADDR 0x0004
#परिभाषय SO_KEEPALIVE 0x0008
#परिभाषय SO_DONTROUTE 0x0010
#परिभाषय SO_प्रसारणम् 0x0020
#परिभाषय SO_USELOOPBACK 0x0040
#परिभाषय SO_LINGER 0x0080
#परिभाषय SO_OOBINLINE 0x0100

#परिभाषय SO_DONTLINGER (पूर्णाङ्क)(~SO_LINGER)
#परिभाषय SO_EXCLUSIVEADDRUSE ((पूर्णाङ्क)(~SO_REUSEADDR))

#परिभाषय SO_SNDBUF 0x1001
#परिभाषय SO_RCVBUF 0x1002
#परिभाषय SO_SNDLOWAT 0x1003
#परिभाषय SO_RCVLOWAT 0x1004
#परिभाषय SO_SNDTIMEO 0x1005
#परिभाषय SO_RCVTIMEO 0x1006
#परिभाषय SO_ERROR 0x1007
#परिभाषय SO_TYPE 0x1008

#परिभाषय SO_गणः_ID 0x2001
#परिभाषय SO_गणः_प्राथमिकता 0x2002
#परिभाषय SO_MAX_सन्देशः_आकार 0x2003
#परिभाषय SO_PROTOCOL_INFOA 0x2004
#परिभाषय SO_PROTOCOL_INFOW 0x2005
#यदि_परिभाषितम् UNICODE
#परिभाषय SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#अन्यथा
#परिभाषय SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#यदि_अन्तः
#परिभाषय PVD_CONFIG 0x3001
#परिभाषय SO_CONDITIONAL_ACCEPT 0x3002

#परिभाषय TCP_NODELAY 0x0001

#परिभाषय AF_UNSPEC 0

#परिभाषय AF_UNIX 1
#परिभाषय AF_INET 2
#परिभाषय AF_IMPLINK 3
#परिभाषय AF_PUP 4
#परिभाषय AF_CHAOS 5
#परिभाषय AF_NS 6
#परिभाषय AF_IPX AF_NS
#परिभाषय AF_ISO 7
#परिभाषय AF_OSI AF_ISO
#परिभाषय AF_ECMA 8
#परिभाषय AF_DATAKIT 9
#परिभाषय AF_CCITT 10
#परिभाषय AF_SNA 11
#परिभाषय AF_DECnet 12
#परिभाषय AF_DLI 13
#परिभाषय AF_LAT 14
#परिभाषय AF_HYLINK 15
#परिभाषय AF_APPLETALK 16
#परिभाषय AF_NETBIOS 17
#परिभाषय AF_VOICEVIEW 18
#परिभाषय AF_FIREFOX 19
#परिभाषय AF_UNKNOWN1 20
#परिभाषय AF_BAN 21
#परिभाषय AF_ATM 22
#परिभाषय AF_INET6 23
#परिभाषय AF_CLUSTER 24
#परिभाषय AF_12844 25
#परिभाषय AF_IRDA 26
#परिभाषय AF_NETDES 28
#परिभाषय AF_TCNPROCESS 29
#परिभाषय AF_TCNMESSAGE 30
#परिभाषय AF_ICLFXBM 31

#परिभाषय AF_MAX 32

  संरचना sockaddr {
    u_short sa_family;
    वर्ण sa_दत्त[14];
  };

#परिभाषय _SS_MAXSIZE 128
#परिभाषय _SS_ALIGNSIZE (8)

#परिभाषय SS_PAD1_आकार (_SS_ALIGNSIZE - परिमाण (ह्रस्व))
#परिभाषय SS_PAD2_आकार (_SS_MAXSIZE - (परिमाण (ह्रस्व) + SS_PAD1_आकार + _SS_ALIGNSIZE))

  संरचना sockaddr_storage {
    ह्रस्व ss_family;
    वर्ण __ss_pad1[SS_PAD1_आकार];

    __MINGW_EXTENSION __int64 __ss_align;
    वर्ण __ss_pad2[SS_PAD2_आकार];

  };

  संरचना sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#परिभाषय PF_UNSPEC AF_UNSPEC
#परिभाषय PF_UNIX AF_UNIX
#परिभाषय PF_INET AF_INET
#परिभाषय PF_IMPLINK AF_IMPLINK
#परिभाषय PF_PUP AF_PUP
#परिभाषय PF_CHAOS AF_CHAOS
#परिभाषय PF_NS AF_NS
#परिभाषय PF_IPX AF_IPX
#परिभाषय PF_ISO AF_ISO
#परिभाषय PF_OSI AF_OSI
#परिभाषय PF_ECMA AF_ECMA
#परिभाषय PF_DATAKIT AF_DATAKIT
#परिभाषय PF_CCITT AF_CCITT
#परिभाषय PF_SNA AF_SNA
#परिभाषय PF_DECnet AF_DECnet
#परिभाषय PF_DLI AF_DLI
#परिभाषय PF_LAT AF_LAT
#परिभाषय PF_HYLINK AF_HYLINK
#परिभाषय PF_APPLETALK AF_APPLETALK
#परिभाषय PF_VOICEVIEW AF_VOICEVIEW
#परिभाषय PF_FIREFOX AF_FIREFOX
#परिभाषय PF_UNKNOWN1 AF_UNKNOWN1
#परिभाषय PF_BAN AF_BAN
#परिभाषय PF_ATM AF_ATM
#परिभाषय PF_INET6 AF_INET6

#परिभाषय PF_MAX AF_MAX

  संरचना linger {
    u_short l_onoff;
    u_short l_linger;
  };

#परिभाषय SOL_SOCKET 0xffff

#परिभाषय SOMAXCONN 0x7fffffff

#परिभाषय सन्देशः_OOB 0x1
#परिभाषय सन्देशः_PEEK 0x2
#परिभाषय सन्देशः_DONTROUTE 0x4
#परिभाषय सन्देशः_WAITALL 0x8

#परिभाषय सन्देशः_PARTIAL 0x8000

#परिभाषय सन्देशः_व्यवधानम् 0x10

#परिभाषय सन्देशः_MAXIOVLEN 16

#परिभाषय MAXGETHOSTSTRUCT 1024

#परिभाषय FD_READ_BIT 0
#परिभाषय FD_READ (1 << FD_READ_BIT)

#परिभाषय FD_WRITE_BIT 1
#परिभाषय FD_WRITE (1 << FD_WRITE_BIT)

#परिभाषय FD_OOB_BIT 2
#परिभाषय FD_OOB (1 << FD_OOB_BIT)

#परिभाषय FD_ACCEPT_BIT 3
#परिभाषय FD_ACCEPT (1 << FD_ACCEPT_BIT)

#परिभाषय FD_CONNECT_BIT 4
#परिभाषय FD_CONNECT (1 << FD_CONNECT_BIT)

#परिभाषय FD_CLOSE_BIT 5
#परिभाषय FD_CLOSE (1 << FD_CLOSE_BIT)

#परिभाषय FD_QOS_BIT 6
#परिभाषय FD_QOS (1 << FD_QOS_BIT)

#परिभाषय FD_गणः_QOS_BIT 7
#परिभाषय FD_गणः_QOS (1 << FD_गणः_QOS_BIT)

#परिभाषय FD_ROUTING_INTERFACE_CHANGE_BIT 8
#परिभाषय FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_BIT)

#परिभाषय FD_स्थानाङ्कः_LIST_CHANGE_BIT 9
#परिभाषय FD_स्थानाङ्कः_LIST_CHANGE (1 << FD_स्थानाङ्कः_LIST_CHANGE_BIT)

#परिभाषय FD_MAX_EVENTS 10
#परिभाषय FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#यदि_अपरिभाषितम् WSABASEERR

#परिभाषय WSABASEERR 10000

#परिभाषय WSAEINTR (WSABASEERR+4)
#परिभाषय WSAEBADF (WSABASEERR+9)
#परिभाषय WSAEACCES (WSABASEERR+13)
#परिभाषय WSAEFAULT (WSABASEERR+14)
#परिभाषय WSAEINVAL (WSABASEERR+22)
#परिभाषय WSAEMFILE (WSABASEERR+24)

#परिभाषय WSAEWOULDBLOCK (WSABASEERR+35)
#परिभाषय WSAEINPROGRESS (WSABASEERR+36)
#परिभाषय WSAEALREADY (WSABASEERR+37)
#परिभाषय WSAENOTSOCK (WSABASEERR+38)
#परिभाषय WSAEDESTADDRREQ (WSABASEERR+39)
#परिभाषय WSAEMSGSIZE (WSABASEERR+40)
#परिभाषय WSAEPROTOTYPE (WSABASEERR+41)
#परिभाषय WSAENOPROTOOPT (WSABASEERR+42)
#परिभाषय WSAEPROTONOSUPPORT (WSABASEERR+43)
#परिभाषय WSAESOCKTNOSUPPORT (WSABASEERR+44)
#परिभाषय WSAEOPNOTSUPP (WSABASEERR+45)
#परिभाषय WSAEPFNOSUPPORT (WSABASEERR+46)
#परिभाषय WSAEAFNOSUPPORT (WSABASEERR+47)
#परिभाषय WSAEADDRINUSE (WSABASEERR+48)
#परिभाषय WSAEADDRNOTAVAIL (WSABASEERR+49)
#परिभाषय WSAENETDOWN (WSABASEERR+50)
#परिभाषय WSAENETUNREACH (WSABASEERR+51)
#परिभाषय WSAENETRESET (WSABASEERR+52)
#परिभाषय WSAECONNABORTED (WSABASEERR+53)
#परिभाषय WSAECONNRESET (WSABASEERR+54)
#परिभाषय WSAENOBUFS (WSABASEERR+55)
#परिभाषय WSAEISCONN (WSABASEERR+56)
#परिभाषय WSAENOTCONN (WSABASEERR+57)
#परिभाषय WSAESHUTDOWN (WSABASEERR+58)
#परिभाषय WSAETOOMANYREFS (WSABASEERR+59)
#परिभाषय WSAETIMEDOUT (WSABASEERR+60)
#परिभाषय WSAECONNREFUSED (WSABASEERR+61)
#परिभाषय WSAELOOP (WSABASEERR+62)
#परिभाषय WSAENAMETOOLONG (WSABASEERR+63)
#परिभाषय WSAEHOSTDOWN (WSABASEERR+64)
#परिभाषय WSAEHOSTUNREACH (WSABASEERR+65)
#परिभाषय WSAENOTEMPTY (WSABASEERR+66)
#परिभाषय WSAEPROCLIM (WSABASEERR+67)
#परिभाषय WSAEUSERS (WSABASEERR+68)
#परिभाषय WSAEDQUOT (WSABASEERR+69)
#परिभाषय WSAESTALE (WSABASEERR+70)
#परिभाषय WSAEREMOTE (WSABASEERR+71)

#परिभाषय WSASYSNOTREADY (WSABASEERR+91)
#परिभाषय WSAVERNOTSUPPORTED (WSABASEERR+92)
#परिभाषय WSANOTINITIALISED (WSABASEERR+93)
#परिभाषय WSAEDISCON (WSABASEERR+101)
#यदि_अपरिभाषितम् WSAHOST_NOT_प्राप्तम्
#परिभाषय WSAHOST_NOT_प्राप्तम् (WSABASEERR+1001)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSATRY_AGAIN
#परिभाषय WSATRY_AGAIN (WSABASEERR+1002)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSANO_RECOVERY
#परिभाषय WSANO_RECOVERY (WSABASEERR+1003)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSANO_दत्त
#परिभाषय WSANO_दत्त (WSABASEERR+1004)
#यदि_अन्तः

#परिभाषय WSAENOMORE (WSABASEERR+102)
#परिभाषय WSAECANCELLED (WSABASEERR+103)
#परिभाषय WSAEINVALIDPROCTABLE (WSABASEERR+104)
#परिभाषय WSAEINVALIDPROVIDER (WSABASEERR+105)
#परिभाषय WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#परिभाषय WSASYSCALLFAILURE (WSABASEERR+107)
#परिभाषय WSASERVICE_NOT_प्राप्तम् (WSABASEERR+108)
#परिभाषय WSATYPE_NOT_प्राप्तम् (WSABASEERR+109)
#परिभाषय WSA_E_NO_अधिकम् (WSABASEERR+110)
#परिभाषय WSA_E_CANCELLED (WSABASEERR+111)
#परिभाषय WSAEREFUSED (WSABASEERR+112)
#यदि_अपरिभाषितम् WSA_QOS_RECEIVERS
#परिभाषय WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_SENDERS
#परिभाषय WSA_QOS_SENDERS (WSABASEERR + 1006)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_NO_SENDERS
#परिभाषय WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#परिभाषय WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#परिभाषय WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#परिभाषय WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#परिभाषय WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#परिभाषय WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#परिभाषय WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#परिभाषय WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#परिभाषय WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#परिभाषय WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#परिभाषय WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#परिभाषय WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EFILTERSTYLE
#परिभाषय WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EFILTERTYPE
#परिभाषय WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EFILTERCOUNT
#परिभाषय WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EOBJLENGTH
#परिभाषय WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EFLOWCOUNT
#परिभाषय WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EUNKNOWNPSOBJ
#परिभाषय WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EPOLICYOBJ
#परिभाषय WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EFLOWDESC
#परिभाषय WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EPSFLOWSPEC
#परिभाषय WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_EPSFILTERSPEC
#परिभाषय WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_ESDMODEOBJ
#परिभाषय WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_ESHAPERATEOBJ
#परिभाषय WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#यदि_अन्तः
#यदि_अपरिभाषितम् WSA_QOS_RESERVED_PETYPE
#परिभाषय WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#यदि_अन्तः
#यदि_अन्तः // WSABASEERR

#परिभाषय h_errno WSAGet_चरमः_Error()
#परिभाषय HOST_NOT_प्राप्तम् WSAHOST_NOT_प्राप्तम्
#परिभाषय TRY_AGAIN WSATRY_AGAIN
#परिभाषय NO_RECOVERY WSANO_RECOVERY
#परिभाषय NO_दत्त WSANO_दत्त

#परिभाषय WSANO_स्थानाङ्कः WSANO_दत्त
#परिभाषय NO_स्थानाङ्कः WSANO_स्थानाङ्कः

#यदि 0
#परिभाषय EWOULDBLOCK WSAEWOULDBLOCK
#परिभाषय EINPROGRESS WSAEINPROGRESS
#परिभाषय EALREADY WSAEALREADY
#परिभाषय ENOTSOCK WSAENOTSOCK
#परिभाषय EDESTADDRREQ WSAEDESTADDRREQ
#परिभाषय EMSGSIZE WSAEMSGSIZE
#परिभाषय EPROTOTYPE WSAEPROTOTYPE
#परिभाषय ENOPROTOOPT WSAENOPROTOOPT
#परिभाषय EPROTONOSUPPORT WSAEPROTONOSUPPORT
#परिभाषय ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#परिभाषय EOPNOTSUPP WSAEOPNOTSUPP
#परिभाषय EPFNOSUPPORT WSAEPFNOSUPPORT
#परिभाषय EAFNOSUPPORT WSAEAFNOSUPPORT
#परिभाषय EADDRINUSE WSAEADDRINUSE
#परिभाषय EADDRNOTAVAIL WSAEADDRNOTAVAIL
#परिभाषय ENETDOWN WSAENETDOWN
#परिभाषय ENETUNREACH WSAENETUNREACH
#परिभाषय ENETRESET WSAENETRESET
#परिभाषय ECONNABORTED WSAECONNABORTED
#परिभाषय ECONNRESET WSAECONNRESET
#परिभाषय ENOBUFS WSAENOBUFS
#परिभाषय EISCONN WSAEISCONN
#परिभाषय ENOTCONN WSAENOTCONN
#परिभाषय ESHUTDOWN WSAESHUTDOWN
#परिभाषय ETOOMANYREFS WSAETOOMANYREFS
#परिभाषय ETIMEDOUT WSAETIMEDOUT
#परिभाषय ECONNREFUSED WSAECONNREFUSED
#परिभाषय ELOOP WSAELOOP
#परिभाषय ENAMETOOLONG WSAENAMETOOLONG
#परिभाषय EHOSTDOWN WSAEHOSTDOWN
#परिभाषय EHOSTUNREACH WSAEHOSTUNREACH
#परिभाषय ENOTEMPTY WSAENOTEMPTY
#परिभाषय EPROCLIM WSAEPROCLIM
#परिभाषय EUSERS WSAEUSERS
#परिभाषय EDQUOT WSAEDQUOT
#परिभाषय ESTALE WSAESTALE
#परिभाषय EREMOTE WSAEREMOTE
#यदि_अन्तः

#परिभाषय WSAAPI WINAPI
#परिभाषय WSAEVENT HANDLE
#परिभाषय LPWSAEVENT LPHANDLE
#परिभाषय WSAOVERLAPPED OVERLAPPED
  प्रकारनिर्देश संरचना _OVERLAPPED *LPWSAOVERLAPPED;

#परिभाषय WSA_IO_PENDING (ERROR_IO_PENDING)
#परिभाषय WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#परिभाषय WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#परिभाषय WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#परिभाषय WSA_NOT_ENOUGH_स्मृतिः (ERROR_NOT_ENOUGH_स्मृतिः)
#परिभाषय WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#परिभाषय WSA_INVALID_EVENT ((WSAEVENT)रिक्त)
#परिभाषय WSA_अधिकतमम्_WAIT_EVENTS (अधिकतमम्_WAIT_OBJECTS)
#परिभाषय WSA_WAIT_FAILED (WAIT_FAILED)
#परिभाषय WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#परिभाषय WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#परिभाषय WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#परिभाषय WSA_INFINITE (INFINITE)

  प्रकारनिर्देश संरचना _WSABUF {
    u_long len;
    वर्ण *buf;
  } WSABUF,*LPWSABUF;

#अन्तर्भाव <qos.h>

  प्रकारनिर्देश संरचना Quality_सम्बन्धि_Service {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#परिभाषय CF_ACCEPT 0x0000
#परिभाषय CF_REJECT 0x0001
#परिभाषय CF_DEFER 0x0002

#परिभाषय SD_RECEIVE 0x00
#परिभाषय SD_SEND 0x01
#परिभाषय SD_BOTH 0x02

  प्रकारनिर्देश अचिह्नित पूर्णाङ्क गणः_3;

#परिभाषय SG_UNCONSTRAINED_गणः 0x01
#परिभाषय SG_CONSTRAINED_गणः 0x02

  प्रकारनिर्देश संरचना _WSANETWORKEVENTS {
    दीर्घ l_जालम्_Events;
    पूर्णाङ्क i_Error_संहिता[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#यदि_अपरिभाषितम् GUID_DEFINED
#अन्तर्भाव <guiddef.h>
#यदि_अन्तः

#परिभाषय MAX_PROTOCOL_CHAIN 7

#परिभाषय आधारः_PROTOCOL 1
#परिभाषय LAYERED_PROTOCOL 0

  प्रकारनिर्देश संरचना _WSAPROTOCOLCHAIN {
    पूर्णाङ्क ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#परिभाषय WSAPROTOCOL_LEN 255

  प्रकारनिर्देश संरचना _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_प्रविष्टिः_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    पूर्णाङ्क i_संस्करणम्;
    पूर्णाङ्क i_स्थानाङ्कः_Family;
    पूर्णाङ्क iMaxSockAddr;
    पूर्णाङ्क iMinSockAddr;
    पूर्णाङ्क iSocketType;
    पूर्णाङ्क iProtocol;
    पूर्णाङ्क i_Protocol_Max_विस्थापनम्;
    पूर्णाङ्क i_जालम्_Byte_क्रमः;
    पूर्णाङ्क iSecurityScheme;
    DWORD dw_सन्देशः_आकार;
    DWORD dwProviderReserved;
    CHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOA,*LPWSAPROTOCOL_INFOA;
  प्रकारनिर्देश संरचना _WSAPROTOCOL_INFOW {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_प्रविष्टिः_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    पूर्णाङ्क i_संस्करणम्;
    पूर्णाङ्क i_स्थानाङ्कः_Family;
    पूर्णाङ्क iMaxSockAddr;
    पूर्णाङ्क iMinSockAddr;
    पूर्णाङ्क iSocketType;
    पूर्णाङ्क iProtocol;
    पूर्णाङ्क i_Protocol_Max_विस्थापनम्;
    पूर्णाङ्क i_जालम्_Byte_क्रमः;
    पूर्णाङ्क iSecurityScheme;
    DWORD dw_सन्देशः_आकार;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  प्रकारनिर्देश LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#अन्यथा
  प्रकारनिर्देश WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  प्रकारनिर्देश LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#यदि_अन्तः

#परिभाषय PFL_गुणजः_PROTO_ENTRIES 0x00000001
#परिभाषय PFL_RECOMMENDED_PROTO_प्रविष्टिः 0x00000002
#परिभाषय PFL_HIDDEN 0x00000004
#परिभाषय PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#परिभाषय XP1_CONNECTIONLESS 0x00000001
#परिभाषय XP1_GUARANTEED_DELIVERY 0x00000002
#परिभाषय XP1_GUARANTEED_क्रमः 0x00000004
#परिभाषय XP1_सन्देशः_ORIENTED 0x00000008
#परिभाषय XP1_PSEUDO_प्रवाहः 0x00000010
#परिभाषय XP1_GRACEFUL_CLOSE 0x00000020
#परिभाषय XP1_EXPEDITED_दत्त 0x00000040
#परिभाषय XP1_CONNECT_दत्त 0x00000080
#परिभाषय XP1_DISCONNECT_दत्त 0x00000100
#परिभाषय XP1_SUPPORT_प्रसारणम् 0x00000200
#परिभाषय XP1_SUPPORT_MULTIPOINT 0x00000400
#परिभाषय XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#परिभाषय XP1_MULTIPOINT_दत्त_PLANE 0x00001000
#परिभाषय XP1_QOS_SUPPORTED 0x00002000
#परिभाषय XP1_व्यवधानम् 0x00004000
#परिभाषय XP1_UNI_SEND 0x00008000
#परिभाषय XP1_UNI_RECV 0x00010000
#परिभाषय XP1_IFS_HANDLES 0x00020000
#परिभाषय XP1_PARTIAL_सन्देशः 0x00040000

#परिभाषय BIGENDIAN 0x0000
#परिभाषय LITTLEENDIAN 0x0001

#परिभाषय SECURITY_PROTOCOL_NONE 0x0000

#परिभाषय JL_SENDER_ONLY 0x01
#परिभाषय JL_RECEIVER_ONLY 0x02
#परिभाषय JL_BOTH 0x04

#परिभाषय WSA_FLAG_OVERLAPPED 0x01
#परिभाषय WSA_FLAG_MULTIPOINT_C_मूलम् 0x02
#परिभाषय WSA_FLAG_MULTIPOINT_C_पर्णम् 0x04
#परिभाषय WSA_FLAG_MULTIPOINT_D_मूलम् 0x08
#परिभाषय WSA_FLAG_MULTIPOINT_D_पर्णम् 0x10

#परिभाषय IOC_UNIX 0x00000000
#परिभाषय IOC_WS2 0x08000000
#परिभाषय IOC_PROTOCOL 0x10000000
#परिभाषय IOC_VENDOR 0x18000000

#परिभाषय _WSAIO(x,y) (IOC_VOID|(x)|(y))
#परिभाषय _WSAIOR(x,y) (IOC_बहिर्गमनम्|(x)|(y))
#परिभाषय _WSAIOW(x,y) (IOC_अन्तर्|(x)|(y))
#परिभाषय _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#परिभाषय SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#परिभाषय SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#परिभाषय SIO_FIND_ROUTE _WSAIOR(IOC_WS2,3)
#परिभाषय SIO_FLUSH _WSAIO(IOC_WS2,4)
#परिभाषय SIO_GET_प्रसारणम्_स्थानाङ्कः _WSAIOR(IOC_WS2,5)
#परिभाषय SIO_GET_EXTENSION_FUNCTION_POINTER _WSAIORW(IOC_WS2,6)
#परिभाषय SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#परिभाषय SIO_GET_गणः_QOS _WSAIORW(IOC_WS2,8)
#परिभाषय SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#परिभाषय SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#परिभाषय SIO_समुच्चयः_QOS _WSAIOW(IOC_WS2,11)
#परिभाषय SIO_समुच्चयः_गणः_QOS _WSAIOW(IOC_WS2,12)
#परिभाषय SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#परिभाषय SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#परिभाषय SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#परिभाषय SIO_स्थानाङ्कः_LIST_QUERY _WSAIOR(IOC_WS2,22)
#परिभाषय SIO_स्थानाङ्कः_LIST_CHANGE _WSAIO(IOC_WS2,23)
#परिभाषय SIO_QUERY_TARGET_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#परिभाषय SIO_स्थानाङ्कः_LIST_क्रमय _WSAIORW(IOC_WS2,25)

  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_दत्त,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_दत्त,गणः_3 *g,DWORD_PTR dw_Callback_दत्त);
  प्रकारनिर्देश शून्य (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#परिभाषय SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  प्रकारनिर्देश गणना _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_पत्तनम्,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  प्रकारनिर्देश संरचना _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    सङ्घ {
      संरचना {
	HWND hWnd;
	UINT u_सन्देशः;
	WPARAM context;
      } गवाक्षः_सन्देशः;
      संरचना {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      संरचना {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      संरचना {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE h_पत्तनम्;
	ULONG_PTR कुञ्चिका_3;
      } पत्तनम्;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#परिभाषय TH_NETDEV 0x00000001
#परिभाषय TH_TAPI 0x00000002

  प्रकारनिर्देश संरचना sockaddr SOCKADDR;
  प्रकारनिर्देश संरचना sockaddr *PSOCKADDR;
  प्रकारनिर्देश संरचना sockaddr *LPSOCKADDR;
  प्रकारनिर्देश संरचना sockaddr_storage SOCKADDR_STORAGE;
  प्रकारनिर्देश संरचना sockaddr_storage *PSOCKADDR_STORAGE;
  प्रकारनिर्देश संरचना sockaddr_storage *LPSOCKADDR_STORAGE;

#यदि_अपरिभाषितम् चिह्नकम्_BLOB_DEFINED
#परिभाषय चिह्नकम्_BLOB_DEFINED
#परिभाषय _BLOB_DEFINED
#परिभाषय _LPBLOB_DEFINED
  प्रकारनिर्देश संरचना _BLOB {
    ULONG cb_आकार;
    BYTE *p_Blob_दत्त;
  } BLOB,*LPBLOB;
#यदि_अन्तः

#परिभाषय SERVICE_गुणजः (0x00000001)

#परिभाषय NS_ALL (0)

#परिभाषय NS_SAP (1)
#परिभाषय NS_NDS (2)
#परिभाषय NS_PEER_BROWSE (3)
#परिभाषय NS_SLP (5)
#परिभाषय NS_DHCP (6)

#परिभाषय NS_TCPIP_LOCAL (10)
#परिभाषय NS_TCPIP_HOSTS (11)
#परिभाषय NS_DNS (12)
#परिभाषय NS_NETBT (13)
#परिभाषय NS_WINS (14)
#परिभाषय NS_NLA (15)

#परिभाषय NS_NBP (20)

#परिभाषय NS_MS (30)
#परिभाषय NS_STDA (31)
#परिभाषय NS_NTDS (32)

#परिभाषय NS_X500 (40)
#परिभाषय NS_NIS (41)
#परिभाषय NS_NISPLUS (42)

#परिभाषय NS_WRQ (50)

#परिभाषय NS_NETDES (60)

#परिभाषय RES_अप्रयुक्तम्_1 (0x00000001)
#परिभाषय RES_FLUSH_CACHE (0x00000002)
#यदि_अपरिभाषितम् RES_SERVICE
#परिभाषय RES_SERVICE (0x00000004)
#यदि_अन्तः

#परिभाषय SERVICE_TYPE_मानम्_IPXPORTA "IpxSocket"
#परिभाषय SERVICE_TYPE_मानम्_IPXPORTW L"IpxSocket"
#परिभाषय SERVICE_TYPE_मानम्_SAPIDA "SapId"
#परिभाषय SERVICE_TYPE_मानम्_SAPIDW L"SapId"

#परिभाषय SERVICE_TYPE_मानम्_TCPPORTA "TcpPort"
#परिभाषय SERVICE_TYPE_मानम्_TCPPORTW L"TcpPort"

#परिभाषय SERVICE_TYPE_मानम्_UDPPORTA "UdpPort"
#परिभाषय SERVICE_TYPE_मानम्_UDPPORTW L"UdpPort"

#परिभाषय SERVICE_TYPE_मानम्_OBJECTIDA "ObjectId"
#परिभाषय SERVICE_TYPE_मानम्_OBJECTIDW L"ObjectId"

#यदि_परिभाषितम् UNICODE

#परिभाषय SERVICE_TYPE_मानम्_SAPID SERVICE_TYPE_मानम्_SAPIDW
#परिभाषय SERVICE_TYPE_मानम्_TCPPORT SERVICE_TYPE_मानम्_TCPPORTW
#परिभाषय SERVICE_TYPE_मानम्_UDPPORT SERVICE_TYPE_मानम्_UDPPORTW
#परिभाषय SERVICE_TYPE_मानम्_OBJECTID SERVICE_TYPE_मानम्_OBJECTIDW
#अन्यथा

#परिभाषय SERVICE_TYPE_मानम्_SAPID SERVICE_TYPE_मानम्_SAPIDA
#परिभाषय SERVICE_TYPE_मानम्_TCPPORT SERVICE_TYPE_मानम्_TCPPORTA
#परिभाषय SERVICE_TYPE_मानम्_UDPPORT SERVICE_TYPE_मानम्_UDPPORTA
#परिभाषय SERVICE_TYPE_मानम्_OBJECTID SERVICE_TYPE_मानम्_OBJECTIDA
#यदि_अन्तः

#यदि_अपरिभाषितम् __CSADDR_DEFINED__
#परिभाषय __CSADDR_DEFINED__

  प्रकारनिर्देश संरचना SOCKET_स्थानाङ्कः {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_दीर्घता;
  } SOCKET_स्थानाङ्कः_2,*PSOCKET_स्थानाङ्कः,*LPSOCKET_स्थानाङ्कः;

  प्रकारनिर्देश संरचना _CSADDR_INFO {
    SOCKET_स्थानाङ्कः_2 LocalAddr;
    SOCKET_स्थानाङ्कः_2 RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#यदि_अन्तः

  प्रकारनिर्देश संरचना SOCKET_स्थानाङ्कः_LIST {
    INT i_स्थानाङ्कः_गणनम्;
    SOCKET_स्थानाङ्कः_2 स्थानाङ्कः_2[1];
  } SOCKET_स्थानाङ्कः_LIST_2,*LPSOCKET_स्थानाङ्कः_LIST;

  प्रकारनिर्देश संरचना _AFPROTOCOLS {
    INT i_स्थानाङ्कः_Family;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  प्रकारनिर्देश गणना _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  प्रकारनिर्देश संरचना _WSAVersion {
    DWORD dw_संस्करणम्;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  प्रकारनिर्देश संरचना WSAQuery_समुच्चयः_A {
    DWORD dw_आकार;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_संस्करणम्;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_सङ्ख्या_सम्बन्धि_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_सङ्ख्या_सम्बन्धि_Cs_Addrs;
    LPCSADDR_INFO lpcsa_बफर;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  प्रकारनिर्देश संरचना WSAQuery_समुच्चयः_W {
    DWORD dw_आकार;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_संस्करणम्;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_सङ्ख्या_सम्बन्धि_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_सङ्ख्या_सम्बन्धि_Cs_Addrs;
    LPCSADDR_INFO lpcsa_बफर;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WSAQUERYSETW WSAQUERYSET;
  प्रकारनिर्देश PWSAQUERYSETW PWSAQUERYSET;
  प्रकारनिर्देश LPWSAQUERYSETW LPWSAQUERYSET;
#अन्यथा
  प्रकारनिर्देश WSAQUERYSETA WSAQUERYSET;
  प्रकारनिर्देश PWSAQUERYSETA PWSAQUERYSET;
  प्रकारनिर्देश LPWSAQUERYSETA LPWSAQUERYSET;
#यदि_अन्तः

#परिभाषय LUP_DEEP 0x0001
#परिभाषय LUP_CONTAINERS 0x0002
#परिभाषय LUP_NOCONTAINERS 0x0004
#परिभाषय LUP_निकटतमः 0x0008
#परिभाषय LUP_RETURN_NAME 0x0010
#परिभाषय LUP_RETURN_TYPE 0x0020
#परिभाषय LUP_RETURN_संस्करणम् 0x0040
#परिभाषय LUP_RETURN_COMMENT 0x0080
#परिभाषय LUP_RETURN_ADDR 0x0100
#परिभाषय LUP_RETURN_BLOB 0x0200
#परिभाषय LUP_RETURN_ALIASES 0x0400
#परिभाषय LUP_RETURN_QUERY_STRING 0x0800
#परिभाषय LUP_RETURN_ALL 0x0FF0
#परिभाषय LUP_RES_SERVICE 0x8000

#परिभाषय LUP_FLUSHCACHE 0x1000
#परिभाषय LUP_FLUSHPREVIOUS 0x2000

#परिभाषय परिणाम_IS_ALIAS 0x0001
#परिभाषय परिणाम_IS_ADDED 0x0010
#परिभाषय परिणाम_IS_परिवर्तितम् 0x0020
#परिभाषय परिणाम_IS_DELETED 0x0040

  प्रकारनिर्देश गणना _WSAESETSERVICEOP {
    RNRSERVICE_पञ्जिकाकोशः=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  प्रकारनिर्देश संरचना _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_मानम्_Type;
    DWORD dw_मानम्_आकार;
    LPVOID lp_मानम्;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  प्रकारनिर्देश संरचना _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_मानम्_Type;
    DWORD dw_मानम्_आकार;
    LPVOID lp_मानम्;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WSANSCLASSINFOW WSANSCLASSINFO;
  प्रकारनिर्देश PWSANSCLASSINFOW PWSANSCLASSINFO;
  प्रकारनिर्देश LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#अन्यथा
  प्रकारनिर्देश WSANSCLASSINFOA WSANSCLASSINFO;
  प्रकारनिर्देश PWSANSCLASSINFOA PWSANSCLASSINFO;
  प्रकारनिर्देश LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#यदि_अन्तः

  प्रकारनिर्देश संरचना _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_गणनम्;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  प्रकारनिर्देश संरचना _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_गणनम्;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  प्रकारनिर्देश PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  प्रकारनिर्देश LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#अन्यथा
  प्रकारनिर्देश WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  प्रकारनिर्देश PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  प्रकारनिर्देश LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#यदि_अन्तः

  प्रकारनिर्देश संरचना _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_सक्रिय;
    DWORD dw_संस्करणम्;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  प्रकारनिर्देश संरचना _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_सक्रिय;
    DWORD dw_संस्करणम्;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  प्रकारनिर्देश PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  प्रकारनिर्देश LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#अन्यथा
  प्रकारनिर्देश WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  प्रकारनिर्देश PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  प्रकारनिर्देश LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#यदि_अन्तः

#यदि INCL_WINSOCK_API_TYPEDEFS
#यदि_परिभाषितम् UNICODE
#परिभाषय LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#परिभाषय LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#परिभाषय LPFN_WSASOCKET LPFN_WSASOCKETW
#परिभाषय LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#परिभाषय LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#परिभाषय LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#परिभाषय LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#परिभाषय LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#परिभाषय LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#परिभाषय LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#परिभाषय LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#परिभाषय LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#अन्यथा
#परिभाषय LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#परिभाषय LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#परिभाषय LPFN_WSASOCKET LPFN_WSASOCKETA
#परिभाषय LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#परिभाषय LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#परिभाषय LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#परिभाषय LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#परिभाषय LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#परिभाषय LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#परिभाषय LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#परिभाषय LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#परिभाषय LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#यदि_अन्तः

  प्रकारनिर्देश SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,संरचना sockaddr *addr,पूर्णाङ्क *addrlen);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_BIND)(SOCKET s,ध्रुव संरचना sockaddr *name,पूर्णाङ्क namelen);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_CONNECT)(SOCKET s,ध्रुव संरचना sockaddr *name,पूर्णाङ्क namelen);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,दीर्घ cmd,u_long *argp);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,संरचना sockaddr *name,पूर्णाङ्क *namelen);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,संरचना sockaddr *name,पूर्णाङ्क *namelen);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,पूर्णाङ्क level,पूर्णाङ्क optname,वर्ण *optval,पूर्णाङ्क *optlen);
  प्रकारनिर्देश u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  प्रकारनिर्देश u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  प्रकारनिर्देश अचिह्नित दीर्घ (WSAAPI *LPFN_INET_ADDR)(ध्रुव वर्ण *cp);
  प्रकारनिर्देश वर्ण *(WSAAPI *LPFN_INET_NTOA)(संरचना अन्तर्_addr अन्तर्);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_LISTEN)(SOCKET s,पूर्णाङ्क backlog);
  प्रकारनिर्देश u_long (WSAAPI *LPFN_NTOHL)(u_long netlong);
  प्रकारनिर्देश u_short (WSAAPI *LPFN_NTOHS)(u_short netshort);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_RECV)(SOCKET s,वर्ण *buf,पूर्णाङ्क len,पूर्णाङ्क flags);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_RECVFROM)(SOCKET s,वर्ण *buf,पूर्णाङ्क len,पूर्णाङ्क flags,संरचना sockaddr *from,पूर्णाङ्क *fromlen);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_SELECT)(पूर्णाङ्क nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ध्रुव संरचना timeval *timeout);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_SEND)(SOCKET s,ध्रुव वर्ण *buf,पूर्णाङ्क len,पूर्णाङ्क flags);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_SENDTO)(SOCKET s,ध्रुव वर्ण *buf,पूर्णाङ्क len,पूर्णाङ्क flags,ध्रुव संरचना sockaddr *गन्तव्यम्,पूर्णाङ्क tolen);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s,पूर्णाङ्क level,पूर्णाङ्क optname,ध्रुव वर्ण *optval,पूर्णाङ्क optlen);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_SHUTDOWN)(SOCKET s,पूर्णाङ्क how);
  प्रकारनिर्देश SOCKET (WSAAPI *LPFN_SOCKET)(पूर्णाङ्क af,पूर्णाङ्क type,पूर्णाङ्क protocol);
  प्रकारनिर्देश संरचना hostent *(WSAAPI *LPFN_GETHOSTBYADDR)(ध्रुव वर्ण *addr,पूर्णाङ्क len,पूर्णाङ्क type);
  प्रकारनिर्देश संरचना hostent *(WSAAPI *LPFN_GETHOSTBYNAME)(ध्रुव वर्ण *name);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_GETHOSTNAME)(वर्ण *name,पूर्णाङ्क namelen);
  प्रकारनिर्देश संरचना servent *(WSAAPI *LPFN_GETSERVBYPORT)(पूर्णाङ्क पत्तनम्_2,ध्रुव वर्ण *proto);
  प्रकारनिर्देश संरचना servent *(WSAAPI *LPFN_GETSERVBYNAME)(ध्रुव वर्ण *name,ध्रुव वर्ण *proto);
  प्रकारनिर्देश संरचना protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(पूर्णाङ्क सङ्ख्या_3);
  प्रकारनिर्देश संरचना protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(ध्रुव वर्ण *name);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSASTARTUP)(WORD w_संस्करणम्_Requested,LPWSADATA lpWSAData);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSACLEANUP)(शून्य);
  प्रकारनिर्देश शून्य (WSAAPI *LPFN_WSASETLASTERROR)(पूर्णाङ्क iError);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAGETLASTERROR)(शून्य);
  प्रकारनिर्देश WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(शून्य);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(शून्य);
  प्रकारनिर्देश FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lp_खण्डम्_Func);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(शून्य);
  प्रकारनिर्देश HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_सन्देशः,ध्रुव वर्ण *name,ध्रुव वर्ण *proto,वर्ण *buf,पूर्णाङ्क buflen);
  प्रकारनिर्देश HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_सन्देशः,पूर्णाङ्क पत्तनम्_2,ध्रुव वर्ण *proto,वर्ण *buf,पूर्णाङ्क buflen);
  प्रकारनिर्देश HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_सन्देशः,ध्रुव वर्ण *name,वर्ण *buf,पूर्णाङ्क buflen);
  प्रकारनिर्देश HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_सन्देशः,पूर्णाङ्क सङ्ख्या_3,वर्ण *buf,पूर्णाङ्क buflen);
  प्रकारनिर्देश HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_सन्देशः,ध्रुव वर्ण *name,वर्ण *buf,पूर्णाङ्क buflen);
  प्रकारनिर्देश HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_सन्देशः,ध्रुव वर्ण *addr,पूर्णाङ्क len,पूर्णाङ्क type,वर्ण *buf,पूर्णाङ्क buflen);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_सन्देशः,दीर्घ lEvent);
  प्रकारनिर्देश SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,संरचना sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_दत्त);
  प्रकारनिर्देश WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSACONNECT)(SOCKET s,ध्रुव संरचना sockaddr *name,पूर्णाङ्क namelen,LPWSABUF lp_Caller_दत्त,LPWSABUF lp_Callee_दत्त,LPQOS lpSQOS,LPQOS lpGQOS);
  प्रकारनिर्देश WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(शून्य);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_जालम्_Events);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_बफर,LPDWORD lpdw_बफर_दीर्घता);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_बफर,LPDWORD lpdw_बफर_दीर्घता);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,दीर्घ l_जालम्_Events);
  प्रकारनिर्देश WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  प्रकारनिर्देश WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dw_Io_Control_संहिता,LPVOID lpv_अन्तर्_बफर,DWORD cb_अन्तर्_बफर,LPVOID lpv_बहिर्गमनम्_बफर,DWORD cb_बहिर्गमनम्_बफर,LPDWORD lpcb_अष्टकानि_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकारनिर्देश SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,ध्रुव संरचना sockaddr *name,पूर्णाङ्क namelen,LPWSABUF lp_Caller_दत्त,LPWSABUF lp_Callee_दत्त,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गणनम्,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_दत्त);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गणनम्,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Recvd,LPDWORD lpFlags,संरचना sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकारनिर्देश WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गणनम्,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_प्रेषितम्,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_दत्त);
  प्रकारनिर्देश पूर्णाङ्क (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गणनम्,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_प्रेषितम्,DWORD dwFlags,ध्रुव संरचना sockaddr *lp_गन्तव्यम्,पूर्णाङ्क iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  प्रकारनिर्देश WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  प्रकारनिर्देश SOCKET (WSAAPI *LPFN_WSASOCKETA)(पूर्णाङ्क af,पूर्णाङ्क type,पूर्णाङ्क protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,गणः_3 g,DWORD dwFlags);
  प्रकारनिर्देश SOCKET (WSAAPI *LPFN_WSASOCKETW)(पूर्णाङ्क af,पूर्णाङ्क type,पूर्णाङ्क protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,गणः_3 g,DWORD dwFlags);
  प्रकारनिर्देश DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,ध्रुव WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsa_स्थानाङ्कः,DWORD dw_स्थानाङ्कः_दीर्घता,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_स्थानाङ्कः_String,LPDWORD lpdw_स्थानाङ्कः_String_दीर्घता);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsa_स्थानाङ्कः,DWORD dw_स्थानाङ्कः_दीर्घता,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_स्थानाङ्कः_String,LPDWORD lpdw_स्थानाङ्कः_String_दीर्घता);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR स्थानाङ्कः_String,INT स्थानाङ्कः_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_स्थानाङ्कः,LPINT lp_स्थानाङ्कः_दीर्घता);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR स्थानाङ्कः_String,INT स्थानाङ्कः_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_स्थानाङ्कः,LPINT lp_स्थानाङ्कः_दीर्घता);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_बफर_दीर्घता,LPWSAQUERYSETA lpqsResults);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_बफर_दीर्घता,LPWSAQUERYSETW lpqsResults);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dw_Control_संहिता,LPVOID lpv_अन्तर्_बफर,DWORD cb_अन्तर्_बफर,LPVOID lpv_बहिर्गमनम्_बफर,DWORD cb_बहिर्गमनम्_बफर,LPDWORD lpcb_अष्टकानि_Returned,LPWSACOMPLETION lpCompletion);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_आकार,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_आकार,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_बफर_दीर्घता,LPWSANAMESPACE_INFOA lpnsp_बफर);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_बफर_दीर्घता,LPWSANAMESPACE_INFOW lpnsp_बफर);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_बफर_दीर्घता);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_बफर_दीर्घता);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  प्रकारनिर्देश INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय WSADuplicateSocket WSADuplicateSocketW
#परिभाषय WSAEnumProtocols WSAEnumProtocolsW
#परिभाषय WSAAddress_गन्तव्यम्_String WSAAddress_गन्तव्यम्_String_W
#परिभाषय WSASocket WSASocketW
#परिभाषय WSAString_गन्तव्यम्_स्थानाङ्कः WSAString_गन्तव्यम्_स्थानाङ्कः_W
#परिभाषय WSALookupServiceBegin WSALookupServiceBeginW
#परिभाषय WSALookup_Service_अग्र WSALookup_Service_अग्र_W
#परिभाषय WSAInstallServiceClass WSAInstallServiceClassW
#परिभाषय WSAGetServiceClassInfo WSAGetServiceClassInfoW
#परिभाषय WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#परिभाषय WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#परिभाषय WSASetService WSASetServiceW
#अन्यथा
#परिभाषय WSADuplicateSocket WSADuplicateSocketA
#परिभाषय WSAEnumProtocols WSAEnumProtocolsA
#परिभाषय WSASocket WSASocketA
#परिभाषय WSAAddress_गन्तव्यम्_String WSAAddress_गन्तव्यम्_String_A
#परिभाषय WSAString_गन्तव्यम्_स्थानाङ्कः WSAString_गन्तव्यम्_स्थानाङ्कः_A
#परिभाषय WSALookupServiceBegin WSALookupServiceBeginA
#परिभाषय WSALookup_Service_अग्र WSALookup_Service_अग्र_A
#परिभाषय WSAInstallServiceClass WSAInstallServiceClassA
#परिभाषय WSAGetServiceClassInfo WSAGetServiceClassInfoA
#परिभाषय WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#परिभाषय WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#परिभाषय WSASetService WSASetServiceA
#यदि_अन्तः

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,संरचना sockaddr *addr,पूर्णाङ्क *addrlen);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI bind(SOCKET s,ध्रुव संरचना sockaddr *name,पूर्णाङ्क namelen);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI connect(SOCKET s,ध्रुव संरचना sockaddr *name,पूर्णाङ्क namelen);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI ioctlsocket(SOCKET s,दीर्घ cmd,u_long *argp);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI getpeername(SOCKET s,संरचना sockaddr *name,पूर्णाङ्क *namelen);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI getsockname(SOCKET s,संरचना sockaddr *name,पूर्णाङ्क *namelen);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI getsockopt(SOCKET s,पूर्णाङ्क level,पूर्णाङ्क optname,वर्ण *optval,पूर्णाङ्क *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE अचिह्नित दीर्घ WSAAPI inet_addr(ध्रुव वर्ण *cp);
  WINSOCK_API_LINKAGE वर्ण *WSAAPI inet_ntoa(संरचना अन्तर्_addr अन्तर्);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI listen(SOCKET s,पूर्णाङ्क backlog);
  WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI recv(SOCKET s,वर्ण *buf,पूर्णाङ्क len,पूर्णाङ्क flags);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI recvfrom(SOCKET s,वर्ण *buf,पूर्णाङ्क len,पूर्णाङ्क flags,संरचना sockaddr *from,पूर्णाङ्क *fromlen);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI select(पूर्णाङ्क nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,ध्रुव संरचना timeval *timeout);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI send(SOCKET s,ध्रुव वर्ण *buf,पूर्णाङ्क len,पूर्णाङ्क flags);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI sendto(SOCKET s,ध्रुव वर्ण *buf,पूर्णाङ्क len,पूर्णाङ्क flags,ध्रुव संरचना sockaddr *गन्तव्यम्,पूर्णाङ्क tolen);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI setsockopt(SOCKET s,पूर्णाङ्क level,पूर्णाङ्क optname,ध्रुव वर्ण *optval,पूर्णाङ्क optlen);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI shutdown(SOCKET s,पूर्णाङ्क how);
  WINSOCK_API_LINKAGE SOCKET WSAAPI socket(पूर्णाङ्क af,पूर्णाङ्क type,पूर्णाङ्क protocol);
  WINSOCK_API_LINKAGE संरचना hostent *WSAAPI gethostbyaddr(ध्रुव वर्ण *addr,पूर्णाङ्क len,पूर्णाङ्क type);
  WINSOCK_API_LINKAGE संरचना hostent *WSAAPI gethostbyname(ध्रुव वर्ण *name);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI gethostname(वर्ण *name,पूर्णाङ्क namelen);
  WINSOCK_API_LINKAGE संरचना servent *WSAAPI getservbyport(पूर्णाङ्क पत्तनम्_2,ध्रुव वर्ण *proto);
  WINSOCK_API_LINKAGE संरचना servent *WSAAPI getservbyname(ध्रुव वर्ण *name,ध्रुव वर्ण *proto);
  WINSOCK_API_LINKAGE संरचना protoent *WSAAPI getprotobynumber(पूर्णाङ्क सङ्ख्या_3);
  WINSOCK_API_LINKAGE संरचना protoent *WSAAPI getprotobyname(ध्रुव वर्ण *name);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAStartup(WORD w_संस्करणम्_Requested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSACleanup(शून्य);
  WINSOCK_API_LINKAGE शून्य WSAAPI WSASet_चरमः_Error(पूर्णाङ्क iError);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAGet_चरमः_Error(शून्य);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(शून्य);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAUnhookBlockingHook(शून्य);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lp_खण्डम्_Func);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSACancelBlockingCall(शून्य);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_सन्देशः,ध्रुव वर्ण *name,ध्रुव वर्ण *proto,वर्ण *buf,पूर्णाङ्क buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Serv_By_पत्तनम्(HWND hWnd,u_int w_सन्देशः,पूर्णाङ्क पत्तनम्_2,ध्रुव वर्ण *proto,वर्ण *buf,पूर्णाङ्क buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_सन्देशः,ध्रुव वर्ण *name,वर्ण *buf,पूर्णाङ्क buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_सङ्ख्या(HWND hWnd,u_int w_सन्देशः,पूर्णाङ्क सङ्ख्या_3,वर्ण *buf,पूर्णाङ्क buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_सन्देशः,ध्रुव वर्ण *name,वर्ण *buf,पूर्णाङ्क buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_सन्देशः,ध्रुव वर्ण *addr,पूर्णाङ्क len,पूर्णाङ्क type,वर्ण *buf,पूर्णाङ्क buflen);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_सन्देशः,दीर्घ lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,संरचना sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_दत्त);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAConnect(SOCKET s,ध्रुव संरचना sockaddr *name,पूर्णाङ्क namelen,LPWSABUF lp_Caller_दत्त,LPWSABUF lp_Callee_दत्त,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(शून्य);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAEnum_जालम्_Events(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_जालम्_Events);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_बफर,LPDWORD lpdw_बफर_दीर्घता);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_बफर,LPDWORD lpdw_बफर_दीर्घता);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,दीर्घ l_जालम्_Events);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_परिणाम(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAIoctl(SOCKET s,DWORD dw_Io_Control_संहिता,LPVOID lpv_अन्तर्_बफर,DWORD cb_अन्तर्_बफर,LPVOID lpv_बहिर्गमनम्_बफर,DWORD cb_बहिर्गमनम्_बफर,LPDWORD lpcb_अष्टकानि_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoin_पर्णम्(SOCKET s,ध्रुव संरचना sockaddr *name,पूर्णाङ्क namelen,LPWSABUF lp_Caller_दत्त,LPWSABUF lp_Callee_दत्त,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गणनम्,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_दत्त);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गणनम्,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Recvd,LPDWORD lpFlags,संरचना sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गणनम्,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_प्रेषितम्,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_दत्त);
  WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSASend_गन्तव्यम्(SOCKET s,LPWSABUF lpBuffers,DWORD dw_बफर_गणनम्,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_प्रेषितम्,DWORD dwFlags,ध्रुव संरचना sockaddr *lp_गन्तव्यम्,पूर्णाङ्क iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(पूर्णाङ्क af,पूर्णाङ्क type,पूर्णाङ्क protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,गणः_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(पूर्णाङ्क af,पूर्णाङ्क type,पूर्णाङ्क protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,गणः_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWait_For_गुणजः_Events(DWORD cEvents,ध्रुव WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_गन्तव्यम्_String_A(LPSOCKADDR lpsa_स्थानाङ्कः,DWORD dw_स्थानाङ्कः_दीर्घता,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_स्थानाङ्कः_String,LPDWORD lpdw_स्थानाङ्कः_String_दीर्घता);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_गन्तव्यम्_String_W(LPSOCKADDR lpsa_स्थानाङ्कः,DWORD dw_स्थानाङ्कः_दीर्घता,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_स्थानाङ्कः_String,LPDWORD lpdw_स्थानाङ्कः_String_दीर्घता);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_गन्तव्यम्_स्थानाङ्कः_A(LPSTR स्थानाङ्कः_String,INT स्थानाङ्कः_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_स्थानाङ्कः,LPINT lp_स्थानाङ्कः_दीर्घता);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_गन्तव्यम्_स्थानाङ्कः_W(LPWSTR स्थानाङ्कः_String,INT स्थानाङ्कः_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_स्थानाङ्कः,LPINT lp_स्थानाङ्कः_दीर्घता);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_अग्र_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_बफर_दीर्घता,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_अग्र_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_बफर_दीर्घता,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dw_Control_संहिता,LPVOID lpv_अन्तर्_बफर,DWORD cb_अन्तर्_बफर,LPVOID lpv_बहिर्गमनम्_बफर,DWORD cb_बहिर्गमनम्_बफर,LPDWORD lpcb_अष्टकानि_Returned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_अन्तः(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_आकार,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_आकार,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_बफर_दीर्घता,LPWSANAMESPACE_INFOA lpnsp_बफर);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_बफर_दीर्घता,LPWSANAMESPACE_INFOW lpnsp_बफर);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_बफर_दीर्घता);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_बफर_दीर्घता);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  प्रकारनिर्देश संरचना sockaddr_अन्तर् SOCKADDR_अन्तर्;
  प्रकारनिर्देश संरचना sockaddr_अन्तर् *PSOCKADDR_अन्तर्;
  प्रकारनिर्देश संरचना sockaddr_अन्तर् *LPSOCKADDR_अन्तर्;

  प्रकारनिर्देश संरचना linger LINGER;
  प्रकारनिर्देश संरचना linger *PLINGER;
  प्रकारनिर्देश संरचना linger *LPLINGER;

  प्रकारनिर्देश संरचना अन्तर्_addr अन्तर्_ADDR;
  प्रकारनिर्देश संरचना अन्तर्_addr *PIN_ADDR;
  प्रकारनिर्देश संरचना अन्तर्_addr *LPIN_ADDR;

  प्रकारनिर्देश संरचना fd_set FD_SET;
  प्रकारनिर्देश संरचना fd_set *PFD_समुच्चयः;
  प्रकारनिर्देश संरचना fd_set *LPFD_समुच्चयः;

  प्रकारनिर्देश संरचना hostent HOSTENT;
  प्रकारनिर्देश संरचना hostent *PHOSTENT;
  प्रकारनिर्देश संरचना hostent *LPHOSTENT;

  प्रकारनिर्देश संरचना servent SERVENT;
  प्रकारनिर्देश संरचना servent *PSERVENT;
  प्रकारनिर्देश संरचना servent *LPSERVENT;

  प्रकारनिर्देश संरचना protoent PROTOENT;
  प्रकारनिर्देश संरचना protoent *PPROTOENT;
  प्रकारनिर्देश संरचना protoent *LPPROTOENT;

  प्रकारनिर्देश संरचना timeval TIMEVAL;
  प्रकारनिर्देश संरचना timeval *PTIMEVAL;
  प्रकारनिर्देश संरचना timeval *LPTIMEVAL;

#परिभाषय WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#परिभाषय WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#परिभाषय WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#परिभाषय WSAGETASYNCERROR(lParam) HIWORD(lParam)
#परिभाषय WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#परिभाषय WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#परिभाषय POLLRDNORM  0x0100
#परिभाषय POLLRDBAND  0x0200
#परिभाषय POLLIN      (POLLRDNORM | POLLRDBAND)
#परिभाषय POLLPRI     0x0400

#परिभाषय POLLWRNORM  0x0010
#परिभाषय POLLOUT     (POLLWRNORM)
#परिभाषय POLLWRBAND  0x0020

#परिभाषय POLLERR     0x0001
#परिभाषय POLLHUP     0x0002
#परिभाषय POLLNVAL    0x0004

प्रकारनिर्देश संरचना pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE पूर्णाङ्क WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि_परिभाषितम् _NEED_POPPACK
#अन्तर्भाव <poppack.h>
#यदि_अन्तः

#यदि_परिभाषितम् IPV6STRICT
#अन्तर्भाव <wsipv6ok.h>
#यदि_अन्तः

#यदि_अपरिभाषितम् _WINSOCKAPI_
#परिभाषय _WINSOCKAPI_
#यदि_अन्तः

#यदि_परिभाषितम् _INC_WINSOCK_H
#अन्तर्भाव <mswsock.h>
#यदि_अन्तः

#यदि_अन्तः
