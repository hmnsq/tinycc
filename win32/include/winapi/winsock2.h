/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#నిర్వచితం_కాకపోతే _WINSOCK2API_
#నిర్వచించు _WINSOCK2API_

#నిర్వచితం_కాకపోతే INCL_WINSOCK_API_TYPEDEFS
#నిర్వచించు INCL_WINSOCK_API_TYPEDEFS 0
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _INC_WINDOWS
#అన్తర్భావ <windows.h>
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే MAKEWORD
#నిర్వచించు MAKEWORD(దిగువ,ఎగువ) ((మాట_3)(((BYTE)(దిగువ)) | ((మాట_3)((BYTE)(ఎగువ))) << 8))
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WINSOCK_సంస్కరణ
#నిర్వచించు WINSOCK_సంస్కరణ MAKEWORD(2,2)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WINSOCK_API_LINKAGE
#నిర్వచితమైతే DECLSPEC_IMPORT
#నిర్వచించు WINSOCK_API_LINKAGE DECLSPEC_IMPORT
#లేకపోతే
#నిర్వచించు WINSOCK_API_LINKAGE
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WINSOCK_SOCKET_DEFINED
#నిర్వచించు _WINSOCK_SOCKET_DEFINED
  రకనిర్వచనం గుర్తులేని అక్షరం u_char;
  రకనిర్వచనం గుర్తులేని పొట్టి u_short;
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం u_int;
  రకనిర్వచనం గుర్తులేని దీర్ఘ u_long;
  __MINGW_EXTENSION రకనిర్వచనం గుర్తులేని __int64 u_int64;
  రకనిర్వచనం INT_PTR SOCKET;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే FD_SETSIZE
#నిర్వచించు FD_SETSIZE 64
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం fd_set {
    u_int fd_లెక్క;
    SOCKET fd_array[FD_SETSIZE];
  } fd_set;

  బాహ్య పూర్ణాంకం WINAPI __WSAFDIsSet(SOCKET,fd_set *);

#నిర్వచించు FD_CLR(fd,సమితి) చేయి { u_int __i; కొరకు(__i = 0;__i < ((fd_set *)(సమితి))->fd_లెక్క;__i++) { ఒకవేళ (((fd_set *)(సమితి))->fd_array[__i]==fd) { అయితే (__i < ((fd_set *)(సమితి))->fd_లెక్క-1) { ((fd_set *)(సమితి))->fd_array[__i] = ((fd_set *)(సమితి))->fd_array[__i+1]; __i++; } ((fd_set *)(సమితి))->fd_లెక్క--; ఆపు; } } } అయితే(0)
#నిర్వచించు FD_SET(fd,సమితి) చేయి { u_int __i; కొరకు(__i = 0;__i < ((fd_set *)(సమితి))->fd_లెక్క;__i++) { ఒకవేళ (((fd_set *)(సమితి))->fd_array[__i]==(fd)) { ఆపు; } } ఒకవేళ (__i==((fd_set *)(సమితి))->fd_లెక్క) { ఒకవేళ (((fd_set *)(సమితి))->fd_లెక్క < FD_SETSIZE) { ((fd_set *)(సమితి))->fd_array[__i] = (fd); ((fd_set *)(సమితి))->fd_లెక్క++; } } } అయితే(0)
#నిర్వచించు FD_ZERO(సమితి) (((fd_set *)(సమితి))->fd_లెక్క=0)
#నిర్వచించు FD_ISSET(fd,సమితి) __WSAFDIsSet((SOCKET)(fd),(fd_set *)(సమితి))

#నిర్వచితం_కాకపోతే _TIMEVAL_DEFINED /* also in winsock[2].h */
#నిర్వచించు _TIMEVAL_DEFINED
  నిర్మాణం timeval {
    దీర్ఘ tv_sec;
    దీర్ఘ tv_usec;
  };

#నిర్వచించు timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#నిర్వచించు timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#నిర్వచించు timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#అయితే_ముగింపు /* _TIMEVAL_DEFINED */

#నిర్వచించు IOCPARM_ముసుగు 0x7f
#నిర్వచించు IOC_VOID 0x20000000
#నిర్వచించు IOC_బహిర్గతం 0x40000000
#నిర్వచించు IOC_లోపల 0x80000000
#నిర్వచించు IOC_INOUT (IOC_లోపల|IOC_బహిర్గతం)

#నిర్వచించు _IO(x,y) (IOC_VOID|((x)<<8)|(y))
#నిర్వచించు _IOR(x,y,t) (IOC_బహిర్గతం|(((దీర్ఘ)పరిమాణం(t)&IOCPARM_ముసుగు)<<16)|((x)<<8)|(y))
#నిర్వచించు _IOW(x,y,t) (IOC_లోపల|(((దీర్ఘ)పరిమాణం(t)&IOCPARM_ముసుగు)<<16)|((x)<<8)|(y))

#నిర్వచించు FIONREAD _IOR('f',127,u_long)
#నిర్వచించు FIONBIO _IOW('f',126,u_long)
#నిర్వచించు FIOASYNC _IOW('f',125,u_long)

#నిర్వచించు SIOCSHIWAT _IOW('s',0,u_long)
#నిర్వచించు SIOCGHIWAT _IOR('s',1,u_long)
#నిర్వచించు SIOCSLOWAT _IOW('s',2,u_long)
#నిర్వచించు SIOCGLOWAT _IOR('s',3,u_long)
#నిర్వచించు SIOCATMARK _IOR('s',7,u_long)

#నిర్వచించు h_addr h_addr_list[0]

  నిర్మాణం hostent {
    అక్షరం *h_name;
    అక్షరం **h_aliases;
    పొట్టి h_addrtype;
    పొట్టి h_నిడివి;
    అక్షరం **h_addr_list;
  };

  నిర్మాణం netent {
    అక్షరం *n_name;
    అక్షరం **n_aliases;
    పొట్టి n_addrtype;
    u_long n_net;
  };

  నిర్మాణం servent {
    అక్షరం *s_name;
    అక్షరం **s_aliases;
#నిర్వచితమైతే _WIN64
    అక్షరం *s_proto;
    పొట్టి s_పోర్టు;
#లేకపోతే
    పొట్టి s_పోర్టు;
    అక్షరం *s_proto;
#అయితే_ముగింపు
  };

  నిర్మాణం protoent {
    అక్షరం *p_name;
    అక్షరం **p_aliases;
    పొట్టి p_proto;
  };

#నిర్వచించు IPPROTO_IP 0
#నిర్వచించు IPPROTO_HOPOPTS 0
#నిర్వచించు IPPROTO_ICMP 1
#నిర్వచించు IPPROTO_IGMP 2
#నిర్వచించు IPPROTO_GGP 3
#నిర్వచించు IPPROTO_IPV4 4
#నిర్వచించు IPPROTO_TCP 6
#నిర్వచించు IPPROTO_PUP 12
#నిర్వచించు IPPROTO_UDP 17
#నిర్వచించు IPPROTO_IDP 22
#నిర్వచించు IPPROTO_IPV6 41
#నిర్వచించు IPPROTO_ROUTING 43
#నిర్వచించు IPPROTO_FRAGMENT 44
#నిర్వచించు IPPROTO_ESP 50
#నిర్వచించు IPPROTO_AH 51
#నిర్వచించు IPPROTO_ICMPV6 58
#నిర్వచించు IPPROTO_NONE 59
#నిర్వచించు IPPROTO_DSTOPTS 60
#నిర్వచించు IPPROTO_ND 77
#నిర్వచించు IPPROTO_ICLFXBM 78

#నిర్వచించు IPPROTO_RAW 255
#నిర్వచించు IPPROTO_MAX 256

#నిర్వచించు IPPORT_ECHO 7
#నిర్వచించు IPPORT_DISCARD 9
#నిర్వచించు IPPORT_SYSTAT 11
#నిర్వచించు IPPORT_DAYTIME 13
#నిర్వచించు IPPORT_NETSTAT 15
#నిర్వచించు IPPORT_FTP 21
#నిర్వచించు IPPORT_TELNET 23
#నిర్వచించు IPPORT_SMTP 25
#నిర్వచించు IPPORT_TIMESERVER 37
#నిర్వచించు IPPORT_NAMESERVER 42
#నిర్వచించు IPPORT_WHOIS 43
#నిర్వచించు IPPORT_MTP 57

#నిర్వచించు IPPORT_TFTP 69
#నిర్వచించు IPPORT_RJE 77
#నిర్వచించు IPPORT_FINGER 79
#నిర్వచించు IPPORT_TTYLINK 87
#నిర్వచించు IPPORT_SUPDUP 95

#నిర్వచించు IPPORT_EXECSERVER 512
#నిర్వచించు IPPORT_LOGINSERVER 513
#నిర్వచించు IPPORT_CMDSERVER 514
#నిర్వచించు IPPORT_EFSSERVER 520

#నిర్వచించు IPPORT_BIFFUDP 512
#నిర్వచించు IPPORT_WHOSERVER 513
#నిర్వచించు IPPORT_ROUTESERVER 520

#నిర్వచించు IPPORT_RESERVED 1024

#నిర్వచించు IMPLINK_IP 155
#నిర్వచించు IMPLINK_LOWEXPER 156
#నిర్వచించు IMPLINK_HIGHEXPER 158

#నిర్వచితం_కాకపోతే s_addr

  నిర్మాణం లోపల_addr {
    సంఘం {
      నిర్మాణం { u_char s_b1,s_b2,s_b3,s_b4; } S_un_b;
      నిర్మాణం { u_short s_w1,s_w2; } S_un_w;
      u_long S_addr;
    } S_un;
  };

#నిర్వచించు s_addr S_un.S_addr
#నిర్వచించు s_host S_un.S_un_b.s_b2
#నిర్వచించు s_net S_un.S_un_b.s_b1
#నిర్వచించు s_imp S_un.S_un_w.s_w2
#నిర్వచించు s_impno S_un.S_un_b.s_b4
#నిర్వచించు s_lh S_un.S_un_b.s_b3

#అయితే_ముగింపు

#నిర్వచించు లోపల_CLASSA(i) (((దీర్ఘ)(i) & 0x80000000)==0)
#నిర్వచించు లోపల_CLASSA_NET 0xff000000
#నిర్వచించు లోపల_CLASSA_NSHIFT 24
#నిర్వచించు లోపల_CLASSA_HOST 0x00ffffff
#నిర్వచించు లోపల_CLASSA_MAX 128

#నిర్వచించు లోపల_CLASSB(i) (((దీర్ఘ)(i) & 0xc0000000)==0x80000000)
#నిర్వచించు లోపల_CLASSB_NET 0xffff0000
#నిర్వచించు లోపల_CLASSB_NSHIFT 16
#నిర్వచించు లోపల_CLASSB_HOST 0x0000ffff
#నిర్వచించు లోపల_CLASSB_MAX 65536

#నిర్వచించు లోపల_CLASSC(i) (((దీర్ఘ)(i) & 0xe0000000)==0xc0000000)
#నిర్వచించు లోపల_CLASSC_NET 0xffffff00
#నిర్వచించు లోపల_CLASSC_NSHIFT 8
#నిర్వచించు లోపల_CLASSC_HOST 0x000000ff

#నిర్వచించు లోపల_CLASSD(i) (((దీర్ఘ)(i) & 0xf0000000)==0xe0000000)
#నిర్వచించు లోపల_CLASSD_NET 0xf0000000
#నిర్వచించు లోపల_CLASSD_NSHIFT 28
#నిర్వచించు లోపల_CLASSD_HOST 0x0fffffff
#నిర్వచించు లోపల_MULTICAST(i) లోపల_CLASSD(i)

#నిర్వచించు INADDR_ANY (u_long)0x00000000
#నిర్వచించు INADDR_LOOPBACK 0x7f000001
#నిర్వచించు INADDR_ప్రసారం (u_long)0xffffffff
#నిర్వచించు INADDR_NONE 0xffffffff

#నిర్వచించు ADDR_ANY INADDR_ANY

  నిర్మాణం sockaddr_లోపల {
    పొట్టి sin_family;
    u_short sin_పోర్టు;
    నిర్మాణం లోపల_addr sin_addr;
    అక్షరం sin_zero[8];
  };

#నిర్వచించు WSADESCRIPTION_LEN 256
#నిర్వచించు WSASYS_స్థితి_LEN 128

  రకనిర్వచనం నిర్మాణం WSAData {
    మాట_3 w_సంస్కరణ;
    మాట_3 w_ఎగువ_సంస్కరణ;
#నిర్వచితమైతే _WIN64
    గుర్తులేని పొట్టి iMaxSockets;
    గుర్తులేని పొట్టి iMaxUdpDg;
    అక్షరం *lpVendorInfo;
    అక్షరం szDescription[WSADESCRIPTION_LEN+1];
    అక్షరం sz_System_స్థితి[WSASYS_స్థితి_LEN+1];
#లేకపోతే
    అక్షరం szDescription[WSADESCRIPTION_LEN+1];
    అక్షరం sz_System_స్థితి[WSASYS_స్థితి_LEN+1];
    గుర్తులేని పొట్టి iMaxSockets;
    గుర్తులేని పొట్టి iMaxUdpDg;
    అక్షరం *lpVendorInfo;
#అయితే_ముగింపు
  } WSADATA,*LPWSADATA;

#నిర్వచించు INVALID_SOCKET (SOCKET)(~0)
#నిర్వచించు SOCKET_ERROR (-1)

#నిర్వచించు FROM_PROTOCOL_INFO (-1)

#నిర్వచించు SOCK_ప్రవాహం 1
#నిర్వచించు SOCK_DGRAM 2
#నిర్వచించు SOCK_RAW 3
#నిర్వచించు SOCK_RDM 4
#నిర్వచించు SOCK_SEQPACKET 5

#నిర్వచించు SO_DEBUG 0x0001
#నిర్వచించు SO_ACCEPTCONN 0x0002
#నిర్వచించు SO_REUSEADDR 0x0004
#నిర్వచించు SO_KEEPALIVE 0x0008
#నిర్వచించు SO_DONTROUTE 0x0010
#నిర్వచించు SO_ప్రసారం 0x0020
#నిర్వచించు SO_USELOOPBACK 0x0040
#నిర్వచించు SO_LINGER 0x0080
#నిర్వచించు SO_OOBINLINE 0x0100

#నిర్వచించు SO_DONTLINGER (పూర్ణాంకం)(~SO_LINGER)
#నిర్వచించు SO_EXCLUSIVEADDRUSE ((పూర్ణాంకం)(~SO_REUSEADDR))

#నిర్వచించు SO_SNDBUF 0x1001
#నిర్వచించు SO_RCVBUF 0x1002
#నిర్వచించు SO_SNDLOWAT 0x1003
#నిర్వచించు SO_RCVLOWAT 0x1004
#నిర్వచించు SO_SNDTIMEO 0x1005
#నిర్వచించు SO_RCVTIMEO 0x1006
#నిర్వచించు SO_ERROR 0x1007
#నిర్వచించు SO_TYPE 0x1008

#నిర్వచించు SO_సమూహం_ID 0x2001
#నిర్వచించు SO_సమూహం_ప్రాధాన్యత 0x2002
#నిర్వచించు SO_MAX_సందేశం_కొలత 0x2003
#నిర్వచించు SO_PROTOCOL_INFOA 0x2004
#నిర్వచించు SO_PROTOCOL_INFOW 0x2005
#నిర్వచితమైతే UNICODE
#నిర్వచించు SO_PROTOCOL_INFO SO_PROTOCOL_INFOW
#లేకపోతే
#నిర్వచించు SO_PROTOCOL_INFO SO_PROTOCOL_INFOA
#అయితే_ముగింపు
#నిర్వచించు PVD_CONFIG 0x3001
#నిర్వచించు SO_CONDITIONAL_ACCEPT 0x3002

#నిర్వచించు TCP_NODELAY 0x0001

#నిర్వచించు AF_UNSPEC 0

#నిర్వచించు AF_UNIX 1
#నిర్వచించు AF_INET 2
#నిర్వచించు AF_IMPLINK 3
#నిర్వచించు AF_PUP 4
#నిర్వచించు AF_CHAOS 5
#నిర్వచించు AF_NS 6
#నిర్వచించు AF_IPX AF_NS
#నిర్వచించు AF_ISO 7
#నిర్వచించు AF_OSI AF_ISO
#నిర్వచించు AF_ECMA 8
#నిర్వచించు AF_DATAKIT 9
#నిర్వచించు AF_CCITT 10
#నిర్వచించు AF_SNA 11
#నిర్వచించు AF_DECnet 12
#నిర్వచించు AF_DLI 13
#నిర్వచించు AF_LAT 14
#నిర్వచించు AF_HYLINK 15
#నిర్వచించు AF_APPLETALK 16
#నిర్వచించు AF_NETBIOS 17
#నిర్వచించు AF_VOICEVIEW 18
#నిర్వచించు AF_FIREFOX 19
#నిర్వచించు AF_UNKNOWN1 20
#నిర్వచించు AF_BAN 21
#నిర్వచించు AF_ATM 22
#నిర్వచించు AF_INET6 23
#నిర్వచించు AF_CLUSTER 24
#నిర్వచించు AF_12844 25
#నిర్వచించు AF_IRDA 26
#నిర్వచించు AF_NETDES 28
#నిర్వచించు AF_TCNPROCESS 29
#నిర్వచించు AF_TCNMESSAGE 30
#నిర్వచించు AF_ICLFXBM 31

#నిర్వచించు AF_MAX 32

  నిర్మాణం sockaddr {
    u_short sa_family;
    అక్షరం sa_దత్తాంశం[14];
  };

#నిర్వచించు _SS_MAXSIZE 128
#నిర్వచించు _SS_ALIGNSIZE (8)

#నిర్వచించు SS_PAD1_కొలత (_SS_ALIGNSIZE - పరిమాణం (పొట్టి))
#నిర్వచించు SS_PAD2_కొలత (_SS_MAXSIZE - (పరిమాణం (పొట్టి) + SS_PAD1_కొలత + _SS_ALIGNSIZE))

  నిర్మాణం sockaddr_storage {
    పొట్టి ss_family;
    అక్షరం __ss_pad1[SS_PAD1_కొలత];

    __MINGW_EXTENSION __int64 __ss_align;
    అక్షరం __ss_pad2[SS_PAD2_కొలత];

  };

  నిర్మాణం sockproto {
    u_short sp_family;
    u_short sp_protocol;
  };

#నిర్వచించు PF_UNSPEC AF_UNSPEC
#నిర్వచించు PF_UNIX AF_UNIX
#నిర్వచించు PF_INET AF_INET
#నిర్వచించు PF_IMPLINK AF_IMPLINK
#నిర్వచించు PF_PUP AF_PUP
#నిర్వచించు PF_CHAOS AF_CHAOS
#నిర్వచించు PF_NS AF_NS
#నిర్వచించు PF_IPX AF_IPX
#నిర్వచించు PF_ISO AF_ISO
#నిర్వచించు PF_OSI AF_OSI
#నిర్వచించు PF_ECMA AF_ECMA
#నిర్వచించు PF_DATAKIT AF_DATAKIT
#నిర్వచించు PF_CCITT AF_CCITT
#నిర్వచించు PF_SNA AF_SNA
#నిర్వచించు PF_DECnet AF_DECnet
#నిర్వచించు PF_DLI AF_DLI
#నిర్వచించు PF_LAT AF_LAT
#నిర్వచించు PF_HYLINK AF_HYLINK
#నిర్వచించు PF_APPLETALK AF_APPLETALK
#నిర్వచించు PF_VOICEVIEW AF_VOICEVIEW
#నిర్వచించు PF_FIREFOX AF_FIREFOX
#నిర్వచించు PF_UNKNOWN1 AF_UNKNOWN1
#నిర్వచించు PF_BAN AF_BAN
#నిర్వచించు PF_ATM AF_ATM
#నిర్వచించు PF_INET6 AF_INET6

#నిర్వచించు PF_MAX AF_MAX

  నిర్మాణం linger {
    u_short l_onoff;
    u_short l_linger;
  };

#నిర్వచించు SOL_SOCKET 0xffff

#నిర్వచించు SOMAXCONN 0x7fffffff

#నిర్వచించు సందేశం_OOB 0x1
#నిర్వచించు సందేశం_PEEK 0x2
#నిర్వచించు సందేశం_DONTROUTE 0x4
#నిర్వచించు సందేశం_WAITALL 0x8

#నిర్వచించు సందేశం_PARTIAL 0x8000

#నిర్వచించు సందేశం_అంతరాయం 0x10

#నిర్వచించు సందేశం_MAXIOVLEN 16

#నిర్వచించు MAXGETHOSTSTRUCT 1024

#నిర్వచించు FD_READ_బిట్టు 0
#నిర్వచించు FD_READ (1 << FD_READ_బిట్టు)

#నిర్వచించు FD_WRITE_బిట్టు 1
#నిర్వచించు FD_WRITE (1 << FD_WRITE_బిట్టు)

#నిర్వచించు FD_OOB_బిట్టు 2
#నిర్వచించు FD_OOB (1 << FD_OOB_బిట్టు)

#నిర్వచించు FD_ACCEPT_బిట్టు 3
#నిర్వచించు FD_ACCEPT (1 << FD_ACCEPT_బిట్టు)

#నిర్వచించు FD_CONNECT_బిట్టు 4
#నిర్వచించు FD_CONNECT (1 << FD_CONNECT_బిట్టు)

#నిర్వచించు FD_CLOSE_బిట్టు 5
#నిర్వచించు FD_CLOSE (1 << FD_CLOSE_బిట్టు)

#నిర్వచించు FD_QOS_బిట్టు 6
#నిర్వచించు FD_QOS (1 << FD_QOS_బిట్టు)

#నిర్వచించు FD_సమూహం_QOS_బిట్టు 7
#నిర్వచించు FD_సమూహం_QOS (1 << FD_సమూహం_QOS_బిట్టు)

#నిర్వచించు FD_ROUTING_INTERFACE_CHANGE_బిట్టు 8
#నిర్వచించు FD_ROUTING_INTERFACE_CHANGE (1 << FD_ROUTING_INTERFACE_CHANGE_బిట్టు)

#నిర్వచించు FD_చిరునామా_LIST_CHANGE_బిట్టు 9
#నిర్వచించు FD_చిరునామా_LIST_CHANGE (1 << FD_చిరునామా_LIST_CHANGE_బిట్టు)

#నిర్వచించు FD_MAX_EVENTS 10
#నిర్వచించు FD_ALL_EVENTS ((1 << FD_MAX_EVENTS) - 1)

#నిర్వచితం_కాకపోతే WSABASEERR

#నిర్వచించు WSABASEERR 10000

#నిర్వచించు WSAEINTR (WSABASEERR+4)
#నిర్వచించు WSAEBADF (WSABASEERR+9)
#నిర్వచించు WSAEACCES (WSABASEERR+13)
#నిర్వచించు WSAEFAULT (WSABASEERR+14)
#నిర్వచించు WSAEINVAL (WSABASEERR+22)
#నిర్వచించు WSAEMFILE (WSABASEERR+24)

#నిర్వచించు WSAEWOULDBLOCK (WSABASEERR+35)
#నిర్వచించు WSAEINPROGRESS (WSABASEERR+36)
#నిర్వచించు WSAEALREADY (WSABASEERR+37)
#నిర్వచించు WSAENOTSOCK (WSABASEERR+38)
#నిర్వచించు WSAEDESTADDRREQ (WSABASEERR+39)
#నిర్వచించు WSAEMSGSIZE (WSABASEERR+40)
#నిర్వచించు WSAEPROTOTYPE (WSABASEERR+41)
#నిర్వచించు WSAENOPROTOOPT (WSABASEERR+42)
#నిర్వచించు WSAEPROTONOSUPPORT (WSABASEERR+43)
#నిర్వచించు WSAESOCKTNOSUPPORT (WSABASEERR+44)
#నిర్వచించు WSAEOPNOTSUPP (WSABASEERR+45)
#నిర్వచించు WSAEPFNOSUPPORT (WSABASEERR+46)
#నిర్వచించు WSAEAFNOSUPPORT (WSABASEERR+47)
#నిర్వచించు WSAEADDRINUSE (WSABASEERR+48)
#నిర్వచించు WSAEADDRNOTAVAIL (WSABASEERR+49)
#నిర్వచించు WSAENETDOWN (WSABASEERR+50)
#నిర్వచించు WSAENETUNREACH (WSABASEERR+51)
#నిర్వచించు WSAENETRESET (WSABASEERR+52)
#నిర్వచించు WSAECONNABORTED (WSABASEERR+53)
#నిర్వచించు WSAECONNRESET (WSABASEERR+54)
#నిర్వచించు WSAENOBUFS (WSABASEERR+55)
#నిర్వచించు WSAEISCONN (WSABASEERR+56)
#నిర్వచించు WSAENOTCONN (WSABASEERR+57)
#నిర్వచించు WSAESHUTDOWN (WSABASEERR+58)
#నిర్వచించు WSAETOOMANYREFS (WSABASEERR+59)
#నిర్వచించు WSAETIMEDOUT (WSABASEERR+60)
#నిర్వచించు WSAECONNREFUSED (WSABASEERR+61)
#నిర్వచించు WSAELOOP (WSABASEERR+62)
#నిర్వచించు WSAENAMETOOLONG (WSABASEERR+63)
#నిర్వచించు WSAEHOSTDOWN (WSABASEERR+64)
#నిర్వచించు WSAEHOSTUNREACH (WSABASEERR+65)
#నిర్వచించు WSAENOTEMPTY (WSABASEERR+66)
#నిర్వచించు WSAEPROCLIM (WSABASEERR+67)
#నిర్వచించు WSAEUSERS (WSABASEERR+68)
#నిర్వచించు WSAEDQUOT (WSABASEERR+69)
#నిర్వచించు WSAESTALE (WSABASEERR+70)
#నిర్వచించు WSAEREMOTE (WSABASEERR+71)

#నిర్వచించు WSASYSNOTREADY (WSABASEERR+91)
#నిర్వచించు WSAVERNOTSUPPORTED (WSABASEERR+92)
#నిర్వచించు WSANOTINITIALISED (WSABASEERR+93)
#నిర్వచించు WSAEDISCON (WSABASEERR+101)
#నిర్వచితం_కాకపోతే WSAHOST_NOT_దొరికింది
#నిర్వచించు WSAHOST_NOT_దొరికింది (WSABASEERR+1001)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSATRY_AGAIN
#నిర్వచించు WSATRY_AGAIN (WSABASEERR+1002)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSANO_RECOVERY
#నిర్వచించు WSANO_RECOVERY (WSABASEERR+1003)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSANO_దత్తాంశం
#నిర్వచించు WSANO_దత్తాంశం (WSABASEERR+1004)
#అయితే_ముగింపు

#నిర్వచించు WSAENOMORE (WSABASEERR+102)
#నిర్వచించు WSAECANCELLED (WSABASEERR+103)
#నిర్వచించు WSAEINVALIDPROCTABLE (WSABASEERR+104)
#నిర్వచించు WSAEINVALIDPROVIDER (WSABASEERR+105)
#నిర్వచించు WSAEPROVIDERFAILEDINIT (WSABASEERR+106)
#నిర్వచించు WSASYSCALLFAILURE (WSABASEERR+107)
#నిర్వచించు WSASERVICE_NOT_దొరికింది (WSABASEERR+108)
#నిర్వచించు WSATYPE_NOT_దొరికింది (WSABASEERR+109)
#నిర్వచించు WSA_E_NO_మరిన్ని (WSABASEERR+110)
#నిర్వచించు WSA_E_CANCELLED (WSABASEERR+111)
#నిర్వచించు WSAEREFUSED (WSABASEERR+112)
#నిర్వచితం_కాకపోతే WSA_QOS_RECEIVERS
#నిర్వచించు WSA_QOS_RECEIVERS (WSABASEERR + 1005)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_SENDERS
#నిర్వచించు WSA_QOS_SENDERS (WSABASEERR + 1006)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_NO_SENDERS
#నిర్వచించు WSA_QOS_NO_SENDERS (WSABASEERR + 1007)
#నిర్వచించు WSA_QOS_NO_RECEIVERS (WSABASEERR + 1008)
#నిర్వచించు WSA_QOS_REQUEST_CONFIRMED (WSABASEERR + 1009)
#నిర్వచించు WSA_QOS_ADMISSION_FAILURE (WSABASEERR + 1010)
#నిర్వచించు WSA_QOS_POLICY_FAILURE (WSABASEERR + 1011)
#నిర్వచించు WSA_QOS_BAD_STYLE (WSABASEERR + 1012)
#నిర్వచించు WSA_QOS_BAD_OBJECT (WSABASEERR + 1013)
#నిర్వచించు WSA_QOS_TRAFFIC_CTRL_ERROR (WSABASEERR + 1014)
#నిర్వచించు WSA_QOS_GENERIC_ERROR (WSABASEERR + 1015)
#నిర్వచించు WSA_QOS_ESERVICETYPE (WSABASEERR + 1016)
#నిర్వచించు WSA_QOS_EFLOWSPEC (WSABASEERR + 1017)
#నిర్వచించు WSA_QOS_EPROVSPECBUF (WSABASEERR + 1018)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EFILTERSTYLE
#నిర్వచించు WSA_QOS_EFILTERSTYLE (WSABASEERR + 1019)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EFILTERTYPE
#నిర్వచించు WSA_QOS_EFILTERTYPE (WSABASEERR + 1020)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EFILTERCOUNT
#నిర్వచించు WSA_QOS_EFILTERCOUNT (WSABASEERR + 1021)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EOBJLENGTH
#నిర్వచించు WSA_QOS_EOBJLENGTH (WSABASEERR + 1022)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EFLOWCOUNT
#నిర్వచించు WSA_QOS_EFLOWCOUNT (WSABASEERR + 1023)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EUNKNOWNPSOBJ
#నిర్వచించు WSA_QOS_EUNKNOWNPSOBJ (WSABASEERR + 1024)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EPOLICYOBJ
#నిర్వచించు WSA_QOS_EPOLICYOBJ (WSABASEERR + 1025)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EFLOWDESC
#నిర్వచించు WSA_QOS_EFLOWDESC (WSABASEERR + 1026)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EPSFLOWSPEC
#నిర్వచించు WSA_QOS_EPSFLOWSPEC (WSABASEERR + 1027)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_EPSFILTERSPEC
#నిర్వచించు WSA_QOS_EPSFILTERSPEC (WSABASEERR + 1028)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_ESDMODEOBJ
#నిర్వచించు WSA_QOS_ESDMODEOBJ (WSABASEERR + 1029)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_ESHAPERATEOBJ
#నిర్వచించు WSA_QOS_ESHAPERATEOBJ (WSABASEERR + 1030)
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WSA_QOS_RESERVED_PETYPE
#నిర్వచించు WSA_QOS_RESERVED_PETYPE (WSABASEERR + 1031)
#అయితే_ముగింపు
#అయితే_ముగింపు // WSABASEERR

#నిర్వచించు h_errno WSAGet_చివరి_Error()
#నిర్వచించు HOST_NOT_దొరికింది WSAHOST_NOT_దొరికింది
#నిర్వచించు TRY_AGAIN WSATRY_AGAIN
#నిర్వచించు NO_RECOVERY WSANO_RECOVERY
#నిర్వచించు NO_దత్తాంశం WSANO_దత్తాంశం

#నిర్వచించు WSANO_చిరునామా WSANO_దత్తాంశం
#నిర్వచించు NO_చిరునామా WSANO_చిరునామా

#ఒకవేళ 0
#నిర్వచించు EWOULDBLOCK WSAEWOULDBLOCK
#నిర్వచించు EINPROGRESS WSAEINPROGRESS
#నిర్వచించు EALREADY WSAEALREADY
#నిర్వచించు ENOTSOCK WSAENOTSOCK
#నిర్వచించు EDESTADDRREQ WSAEDESTADDRREQ
#నిర్వచించు EMSGSIZE WSAEMSGSIZE
#నిర్వచించు EPROTOTYPE WSAEPROTOTYPE
#నిర్వచించు ENOPROTOOPT WSAENOPROTOOPT
#నిర్వచించు EPROTONOSUPPORT WSAEPROTONOSUPPORT
#నిర్వచించు ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#నిర్వచించు EOPNOTSUPP WSAEOPNOTSUPP
#నిర్వచించు EPFNOSUPPORT WSAEPFNOSUPPORT
#నిర్వచించు EAFNOSUPPORT WSAEAFNOSUPPORT
#నిర్వచించు EADDRINUSE WSAEADDRINUSE
#నిర్వచించు EADDRNOTAVAIL WSAEADDRNOTAVAIL
#నిర్వచించు ENETDOWN WSAENETDOWN
#నిర్వచించు ENETUNREACH WSAENETUNREACH
#నిర్వచించు ENETRESET WSAENETRESET
#నిర్వచించు ECONNABORTED WSAECONNABORTED
#నిర్వచించు ECONNRESET WSAECONNRESET
#నిర్వచించు ENOBUFS WSAENOBUFS
#నిర్వచించు EISCONN WSAEISCONN
#నిర్వచించు ENOTCONN WSAENOTCONN
#నిర్వచించు ESHUTDOWN WSAESHUTDOWN
#నిర్వచించు ETOOMANYREFS WSAETOOMANYREFS
#నిర్వచించు ETIMEDOUT WSAETIMEDOUT
#నిర్వచించు ECONNREFUSED WSAECONNREFUSED
#నిర్వచించు ELOOP WSAELOOP
#నిర్వచించు ENAMETOOLONG WSAENAMETOOLONG
#నిర్వచించు EHOSTDOWN WSAEHOSTDOWN
#నిర్వచించు EHOSTUNREACH WSAEHOSTUNREACH
#నిర్వచించు ENOTEMPTY WSAENOTEMPTY
#నిర్వచించు EPROCLIM WSAEPROCLIM
#నిర్వచించు EUSERS WSAEUSERS
#నిర్వచించు EDQUOT WSAEDQUOT
#నిర్వచించు ESTALE WSAESTALE
#నిర్వచించు EREMOTE WSAEREMOTE
#అయితే_ముగింపు

#నిర్వచించు WSAAPI WINAPI
#నిర్వచించు WSAEVENT HANDLE
#నిర్వచించు LPWSAEVENT LPHANDLE
#నిర్వచించు WSAOVERLAPPED OVERLAPPED
  రకనిర్వచనం నిర్మాణం _OVERLAPPED *LPWSAOVERLAPPED;

#నిర్వచించు WSA_IO_PENDING (ERROR_IO_PENDING)
#నిర్వచించు WSA_IO_INCOMPLETE (ERROR_IO_INCOMPLETE)
#నిర్వచించు WSA_INVALID_HANDLE (ERROR_INVALID_HANDLE)
#నిర్వచించు WSA_INVALID_PARAMETER (ERROR_INVALID_PARAMETER)
#నిర్వచించు WSA_NOT_ENOUGH_జ్ఞాపకం (ERROR_NOT_ENOUGH_జ్ఞాపకం)
#నిర్వచించు WSA_OPERATION_ABORTED (ERROR_OPERATION_ABORTED)

#నిర్వచించు WSA_INVALID_EVENT ((WSAEVENT)ఖాళీ)
#నిర్వచించు WSA_గరిష్ఠ_WAIT_EVENTS (గరిష్ఠ_WAIT_OBJECTS)
#నిర్వచించు WSA_WAIT_FAILED (WAIT_FAILED)
#నిర్వచించు WSA_WAIT_EVENT_0 (WAIT_OBJECT_0)
#నిర్వచించు WSA_WAIT_IO_COMPLETION (WAIT_IO_COMPLETION)
#నిర్వచించు WSA_WAIT_TIMEOUT (WAIT_TIMEOUT)
#నిర్వచించు WSA_INFINITE (INFINITE)

  రకనిర్వచనం నిర్మాణం _WSABUF {
    u_long len;
    అక్షరం *buf;
  } WSABUF,*LPWSABUF;

#అన్తర్భావ <qos.h>

  రకనిర్వచనం నిర్మాణం Quality_యొక్క_Service {
    FLOWSPEC SendingFlowspec;
    FLOWSPEC ReceivingFlowspec;
    WSABUF ProviderSpecific;
  } QOS,*LPQOS;

#నిర్వచించు CF_ACCEPT 0x0000
#నిర్వచించు CF_REJECT 0x0001
#నిర్వచించు CF_DEFER 0x0002

#నిర్వచించు SD_RECEIVE 0x00
#నిర్వచించు SD_SEND 0x01
#నిర్వచించు SD_BOTH 0x02

  రకనిర్వచనం గుర్తులేని పూర్ణాంకం సమూహం_3;

#నిర్వచించు SG_UNCONSTRAINED_సమూహం 0x01
#నిర్వచించు SG_CONSTRAINED_సమూహం 0x02

  రకనిర్వచనం నిర్మాణం _WSANETWORKEVENTS {
    దీర్ఘ l_జాలం_Events;
    పూర్ణాంకం i_Error_సంకేతం[FD_MAX_EVENTS];
  } WSANETWORKEVENTS,*LPWSANETWORKEVENTS;

#నిర్వచితం_కాకపోతే GUID_DEFINED
#అన్తర్భావ <guiddef.h>
#అయితే_ముగింపు

#నిర్వచించు MAX_PROTOCOL_CHAIN 7

#నిర్వచించు పునాది_PROTOCOL 1
#నిర్వచించు LAYERED_PROTOCOL 0

  రకనిర్వచనం నిర్మాణం _WSAPROTOCOLCHAIN {
    పూర్ణాంకం ChainLen;

    DWORD ChainEntries[MAX_PROTOCOL_CHAIN];
  } WSAPROTOCOLCHAIN,*LPWSAPROTOCOLCHAIN;

#నిర్వచించు WSAPROTOCOL_LEN 255

  రకనిర్వచనం నిర్మాణం _WSAPROTOCOL_INFOA {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_నమోదు_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    పూర్ణాంకం i_సంస్కరణ;
    పూర్ణాంకం i_చిరునామా_Family;
    పూర్ణాంకం iMaxSockAddr;
    పూర్ణాంకం iMinSockAddr;
    పూర్ణాంకం iSocketType;
    పూర్ణాంకం iProtocol;
    పూర్ణాంకం i_Protocol_Max_స్థానభ్రంశం;
    పూర్ణాంకం i_జాలం_Byte_క్రమం;
    పూర్ణాంకం iSecurityScheme;
    DWORD dw_సందేశం_కొలత;
    DWORD dwProviderReserved;
    CHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOA,*LPWSAPROTOCOL_INFOA;
  రకనిర్వచనం నిర్మాణం _WSAPROTOCOL_INFOW {
    DWORD dwServiceFlags1;
    DWORD dwServiceFlags2;
    DWORD dwServiceFlags3;
    DWORD dwServiceFlags4;
    DWORD dwProviderFlags;
    GUID ProviderId;
    DWORD dw_Catalog_నమోదు_Id;
    WSAPROTOCOLCHAIN ProtocolChain;
    పూర్ణాంకం i_సంస్కరణ;
    పూర్ణాంకం i_చిరునామా_Family;
    పూర్ణాంకం iMaxSockAddr;
    పూర్ణాంకం iMinSockAddr;
    పూర్ణాంకం iSocketType;
    పూర్ణాంకం iProtocol;
    పూర్ణాంకం i_Protocol_Max_స్థానభ్రంశం;
    పూర్ణాంకం i_జాలం_Byte_క్రమం;
    పూర్ణాంకం iSecurityScheme;
    DWORD dw_సందేశం_కొలత;
    DWORD dwProviderReserved;
    WCHAR szProtocol[WSAPROTOCOL_LEN+1];
  } WSAPROTOCOL_INFOW,*LPWSAPROTOCOL_INFOW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WSAPROTOCOL_INFOW WSAPROTOCOL_INFO;
  రకనిర్వచనం LPWSAPROTOCOL_INFOW LPWSAPROTOCOL_INFO;
#లేకపోతే
  రకనిర్వచనం WSAPROTOCOL_INFOA WSAPROTOCOL_INFO;
  రకనిర్వచనం LPWSAPROTOCOL_INFOA LPWSAPROTOCOL_INFO;
#అయితే_ముగింపు

#నిర్వచించు PFL_గుణిజం_PROTO_ENTRIES 0x00000001
#నిర్వచించు PFL_RECOMMENDED_PROTO_నమోదు 0x00000002
#నిర్వచించు PFL_HIDDEN 0x00000004
#నిర్వచించు PFL_MATCHES_PROTOCOL_ZERO 0x00000008

#నిర్వచించు XP1_CONNECTIONLESS 0x00000001
#నిర్వచించు XP1_GUARANTEED_DELIVERY 0x00000002
#నిర్వచించు XP1_GUARANTEED_క్రమం 0x00000004
#నిర్వచించు XP1_సందేశం_ORIENTED 0x00000008
#నిర్వచించు XP1_PSEUDO_ప్రవాహం 0x00000010
#నిర్వచించు XP1_GRACEFUL_CLOSE 0x00000020
#నిర్వచించు XP1_EXPEDITED_దత్తాంశం 0x00000040
#నిర్వచించు XP1_CONNECT_దత్తాంశం 0x00000080
#నిర్వచించు XP1_DISCONNECT_దత్తాంశం 0x00000100
#నిర్వచించు XP1_SUPPORT_ప్రసారం 0x00000200
#నిర్వచించు XP1_SUPPORT_MULTIPOINT 0x00000400
#నిర్వచించు XP1_MULTIPOINT_CONTROL_PLANE 0x00000800
#నిర్వచించు XP1_MULTIPOINT_దత్తాంశం_PLANE 0x00001000
#నిర్వచించు XP1_QOS_SUPPORTED 0x00002000
#నిర్వచించు XP1_అంతరాయం 0x00004000
#నిర్వచించు XP1_UNI_SEND 0x00008000
#నిర్వచించు XP1_UNI_RECV 0x00010000
#నిర్వచించు XP1_IFS_HANDLES 0x00020000
#నిర్వచించు XP1_PARTIAL_సందేశం 0x00040000

#నిర్వచించు BIGENDIAN 0x0000
#నిర్వచించు LITTLEENDIAN 0x0001

#నిర్వచించు SECURITY_PROTOCOL_NONE 0x0000

#నిర్వచించు JL_SENDER_ONLY 0x01
#నిర్వచించు JL_RECEIVER_ONLY 0x02
#నిర్వచించు JL_BOTH 0x04

#నిర్వచించు WSA_FLAG_OVERLAPPED 0x01
#నిర్వచించు WSA_FLAG_MULTIPOINT_C_మూలం 0x02
#నిర్వచించు WSA_FLAG_MULTIPOINT_C_ఆకు 0x04
#నిర్వచించు WSA_FLAG_MULTIPOINT_D_మూలం 0x08
#నిర్వచించు WSA_FLAG_MULTIPOINT_D_ఆకు 0x10

#నిర్వచించు IOC_UNIX 0x00000000
#నిర్వచించు IOC_WS2 0x08000000
#నిర్వచించు IOC_PROTOCOL 0x10000000
#నిర్వచించు IOC_VENDOR 0x18000000

#నిర్వచించు _WSAIO(x,y) (IOC_VOID|(x)|(y))
#నిర్వచించు _WSAIOR(x,y) (IOC_బహిర్గతం|(x)|(y))
#నిర్వచించు _WSAIOW(x,y) (IOC_లోపల|(x)|(y))
#నిర్వచించు _WSAIORW(x,y) (IOC_INOUT|(x)|(y))

#నిర్వచించు SIO_ASSOCIATE_HANDLE _WSAIOW(IOC_WS2,1)
#నిర్వచించు SIO_ENABLE_CIRCULAR_QUEUEING _WSAIO(IOC_WS2,2)
#నిర్వచించు SIO_కనుగొను_ROUTE _WSAIOR(IOC_WS2,3)
#నిర్వచించు SIO_FLUSH _WSAIO(IOC_WS2,4)
#నిర్వచించు SIO_GET_ప్రసారం_చిరునామా _WSAIOR(IOC_WS2,5)
#నిర్వచించు SIO_GET_EXTENSION_FUNCTION_సూచిక _WSAIORW(IOC_WS2,6)
#నిర్వచించు SIO_GET_QOS _WSAIORW(IOC_WS2,7)
#నిర్వచించు SIO_GET_సమూహం_QOS _WSAIORW(IOC_WS2,8)
#నిర్వచించు SIO_MULTIPOINT_LOOPBACK _WSAIOW(IOC_WS2,9)
#నిర్వచించు SIO_MULTICAST_SCOPE _WSAIOW(IOC_WS2,10)
#నిర్వచించు SIO_సమితి_QOS _WSAIOW(IOC_WS2,11)
#నిర్వచించు SIO_సమితి_సమూహం_QOS _WSAIOW(IOC_WS2,12)
#నిర్వచించు SIO_TRANSLATE_HANDLE _WSAIORW(IOC_WS2,13)
#నిర్వచించు SIO_ROUTING_INTERFACE_QUERY _WSAIORW(IOC_WS2,20)
#నిర్వచించు SIO_ROUTING_INTERFACE_CHANGE _WSAIOW(IOC_WS2,21)
#నిర్వచించు SIO_చిరునామా_LIST_QUERY _WSAIOR(IOC_WS2,22)
#నిర్వచించు SIO_చిరునామా_LIST_CHANGE _WSAIO(IOC_WS2,23)
#నిర్వచించు SIO_QUERY_లక్ష్యం_PNP_HANDLE _WSAIOR(IOC_WS2,24)
#నిర్వచించు SIO_చిరునామా_LIST_క్రమీకరించు _WSAIORW(IOC_WS2,25)

  రకనిర్వచనం పూర్ణాంకం (CALLBACK *LPCONDITIONPROC)(LPWSABUF lpCallerId,LPWSABUF lp_Caller_దత్తాంశం,LPQOS lpSQOS,LPQOS lpGQOS,LPWSABUF lpCalleeId,LPWSABUF lp_Callee_దత్తాంశం,సమూహం_3 *g,DWORD_PTR dw_Callback_దత్తాంశం);
  రకనిర్వచనం శూన్య (CALLBACK *LPWSAOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwError,DWORD cbTransferred,LPWSAOVERLAPPED lpOverlapped,DWORD dwFlags);

#నిర్వచించు SIO_NSP_NOTIFY_CHANGE _WSAIOW(IOC_WS2,25)

  రకనిర్వచనం గణన _WSACOMPLETIONTYPE {
    NSP_NOTIFY_IMMEDIATELY = 0,NSP_NOTIFY_HWND,NSP_NOTIFY_EVENT,NSP_NOTIFY_పోర్టు,NSP_NOTIFY_APC
  } WSACOMPLETIONTYPE,*PWSACOMPLETIONTYPE,*LPWSACOMPLETIONTYPE;

  రకనిర్వచనం నిర్మాణం _WSACOMPLETION {
    WSACOMPLETIONTYPE Type;
    సంఘం {
      నిర్మాణం {
	HWND hWnd;
	UINT u_సందేశం;
	WPARAM context;
      } కిటికీ_సందేశం;
      నిర్మాణం {
	LPWSAOVERLAPPED lpOverlapped;
      } Event;
      నిర్మాణం {
	LPWSAOVERLAPPED lpOverlapped;
	LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
      } Apc;
      నిర్మాణం {
	LPWSAOVERLAPPED lpOverlapped;
	HANDLE h_పోర్టు;
	ULONG_PTR కీలకం_3;
      } పోర్టు;
    } Parameters;
  } WSACOMPLETION,*PWSACOMPLETION,*LPWSACOMPLETION;

#నిర్వచించు TH_NETDEV 0x00000001
#నిర్వచించు TH_TAPI 0x00000002

  రకనిర్వచనం నిర్మాణం sockaddr SOCKADDR;
  రకనిర్వచనం నిర్మాణం sockaddr *PSOCKADDR;
  రకనిర్వచనం నిర్మాణం sockaddr *LPSOCKADDR;
  రకనిర్వచనం నిర్మాణం sockaddr_storage SOCKADDR_STORAGE;
  రకనిర్వచనం నిర్మాణం sockaddr_storage *PSOCKADDR_STORAGE;
  రకనిర్వచనం నిర్మాణం sockaddr_storage *LPSOCKADDR_STORAGE;

#నిర్వచితం_కాకపోతే ట్యాగ్_BLOB_DEFINED
#నిర్వచించు ట్యాగ్_BLOB_DEFINED
#నిర్వచించు _BLOB_DEFINED
#నిర్వచించు _LPBLOB_DEFINED
  రకనిర్వచనం నిర్మాణం _BLOB {
    ULONG cb_కొలత;
    BYTE *p_Blob_దత్తాంశం;
  } BLOB,*LPBLOB;
#అయితే_ముగింపు

#నిర్వచించు SERVICE_గుణిజం (0x00000001)

#నిర్వచించు NS_ALL (0)

#నిర్వచించు NS_SAP (1)
#నిర్వచించు NS_NDS (2)
#నిర్వచించు NS_PEER_BROWSE (3)
#నిర్వచించు NS_SLP (5)
#నిర్వచించు NS_DHCP (6)

#నిర్వచించు NS_TCPIP_LOCAL (10)
#నిర్వచించు NS_TCPIP_HOSTS (11)
#నిర్వచించు NS_DNS (12)
#నిర్వచించు NS_NETBT (13)
#నిర్వచించు NS_WINS (14)
#నిర్వచించు NS_NLA (15)

#నిర్వచించు NS_NBP (20)

#నిర్వచించు NS_MS (30)
#నిర్వచించు NS_STDA (31)
#నిర్వచించు NS_NTDS (32)

#నిర్వచించు NS_X500 (40)
#నిర్వచించు NS_NIS (41)
#నిర్వచించు NS_NISPLUS (42)

#నిర్వచించు NS_WRQ (50)

#నిర్వచించు NS_NETDES (60)

#నిర్వచించు RES_వాడని_1 (0x00000001)
#నిర్వచించు RES_FLUSH_CACHE (0x00000002)
#నిర్వచితం_కాకపోతే RES_SERVICE
#నిర్వచించు RES_SERVICE (0x00000004)
#అయితే_ముగింపు

#నిర్వచించు SERVICE_TYPE_విలువ_IPXPORTA "IpxSocket"
#నిర్వచించు SERVICE_TYPE_విలువ_IPXPORTW L"IpxSocket"
#నిర్వచించు SERVICE_TYPE_విలువ_SAPIDA "SapId"
#నిర్వచించు SERVICE_TYPE_విలువ_SAPIDW L"SapId"

#నిర్వచించు SERVICE_TYPE_విలువ_TCPPORTA "TcpPort"
#నిర్వచించు SERVICE_TYPE_విలువ_TCPPORTW L"TcpPort"

#నిర్వచించు SERVICE_TYPE_విలువ_UDPPORTA "UdpPort"
#నిర్వచించు SERVICE_TYPE_విలువ_UDPPORTW L"UdpPort"

#నిర్వచించు SERVICE_TYPE_విలువ_OBJECTIDA "ObjectId"
#నిర్వచించు SERVICE_TYPE_విలువ_OBJECTIDW L"ObjectId"

#నిర్వచితమైతే UNICODE

#నిర్వచించు SERVICE_TYPE_విలువ_SAPID SERVICE_TYPE_విలువ_SAPIDW
#నిర్వచించు SERVICE_TYPE_విలువ_TCPPORT SERVICE_TYPE_విలువ_TCPPORTW
#నిర్వచించు SERVICE_TYPE_విలువ_UDPPORT SERVICE_TYPE_విలువ_UDPPORTW
#నిర్వచించు SERVICE_TYPE_విలువ_OBJECTID SERVICE_TYPE_విలువ_OBJECTIDW
#లేకపోతే

#నిర్వచించు SERVICE_TYPE_విలువ_SAPID SERVICE_TYPE_విలువ_SAPIDA
#నిర్వచించు SERVICE_TYPE_విలువ_TCPPORT SERVICE_TYPE_విలువ_TCPPORTA
#నిర్వచించు SERVICE_TYPE_విలువ_UDPPORT SERVICE_TYPE_విలువ_UDPPORTA
#నిర్వచించు SERVICE_TYPE_విలువ_OBJECTID SERVICE_TYPE_విలువ_OBJECTIDA
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే __CSADDR_DEFINED__
#నిర్వచించు __CSADDR_DEFINED__

  రకనిర్వచనం నిర్మాణం SOCKET_చిరునామా {
    LPSOCKADDR lpSockaddr;
    INT i_Sockaddr_నిడివి;
  } SOCKET_చిరునామా_2,*PSOCKET_చిరునామా,*LPSOCKET_చిరునామా;

  రకనిర్వచనం నిర్మాణం _CSADDR_INFO {
    SOCKET_చిరునామా_2 LocalAddr;
    SOCKET_చిరునామా_2 RemoteAddr;
    INT iSocketType;
    INT iProtocol;
  } CSADDR_INFO,*PCSADDR_INFO,*LPCSADDR_INFO;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం SOCKET_చిరునామా_LIST {
    INT i_చిరునామా_లెక్క;
    SOCKET_చిరునామా_2 చిరునామా_2[1];
  } SOCKET_చిరునామా_LIST_2,*LPSOCKET_చిరునామా_LIST;

  రకనిర్వచనం నిర్మాణం _AFPROTOCOLS {
    INT i_చిరునామా_Family;
    INT iProtocol;
  } AFPROTOCOLS,*PAFPROTOCOLS,*LPAFPROTOCOLS;

  రకనిర్వచనం గణన _WSAEcomparator {
    COMP_EQUAL = 0,COMP_NOTLESS
  } WSAECOMPARATOR,*PWSAECOMPARATOR,*LPWSAECOMPARATOR;

  రకనిర్వచనం నిర్మాణం _WSAVersion {
    DWORD dw_సంస్కరణ;
    WSAECOMPARATOR ecHow;
  } WSAVERSION,*PWSAVERSION,*LPWSAVERSION;

  రకనిర్వచనం నిర్మాణం WSAQuery_సమితి_A {
    DWORD dw_కొలత;
    LPSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_సంస్కరణ;
    LPSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPSTR lpszContext;
    DWORD dw_సంఖ్య_యొక్క_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPSTR lpszQueryString;
    DWORD dw_సంఖ్య_యొక్క_Cs_Addrs;
    LPCSADDR_INFO lpcsa_బఫరు;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETA,*PWSAQUERYSETA,*LPWSAQUERYSETA;

  రకనిర్వచనం నిర్మాణం WSAQuery_సమితి_W {
    DWORD dw_కొలత;
    LPWSTR lpszServiceInstanceName;
    LPGUID lpServiceClassId;
    LPWSAVERSION lp_సంస్కరణ;
    LPWSTR lpszComment;
    DWORD dwNameSpace;
    LPGUID lpNSProviderId;
    LPWSTR lpszContext;
    DWORD dw_సంఖ్య_యొక్క_Protocols;
    LPAFPROTOCOLS lpafpProtocols;
    LPWSTR lpszQueryString;
    DWORD dw_సంఖ్య_యొక్క_Cs_Addrs;
    LPCSADDR_INFO lpcsa_బఫరు;
    DWORD dwOutputFlags;
    LPBLOB lpBlob;
  } WSAQUERYSETW,*PWSAQUERYSETW,*LPWSAQUERYSETW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WSAQUERYSETW WSAQUERYSET;
  రకనిర్వచనం PWSAQUERYSETW PWSAQUERYSET;
  రకనిర్వచనం LPWSAQUERYSETW LPWSAQUERYSET;
#లేకపోతే
  రకనిర్వచనం WSAQUERYSETA WSAQUERYSET;
  రకనిర్వచనం PWSAQUERYSETA PWSAQUERYSET;
  రకనిర్వచనం LPWSAQUERYSETA LPWSAQUERYSET;
#అయితే_ముగింపు

#నిర్వచించు LUP_DEEP 0x0001
#నిర్వచించు LUP_CONTAINERS 0x0002
#నిర్వచించు LUP_NOCONTAINERS 0x0004
#నిర్వచించు LUP_సమీప 0x0008
#నిర్వచించు LUP_RETURN_NAME 0x0010
#నిర్వచించు LUP_RETURN_TYPE 0x0020
#నిర్వచించు LUP_RETURN_సంస్కరణ 0x0040
#నిర్వచించు LUP_RETURN_COMMENT 0x0080
#నిర్వచించు LUP_RETURN_ADDR 0x0100
#నిర్వచించు LUP_RETURN_BLOB 0x0200
#నిర్వచించు LUP_RETURN_ALIASES 0x0400
#నిర్వచించు LUP_RETURN_QUERY_STRING 0x0800
#నిర్వచించు LUP_RETURN_ALL 0x0FF0
#నిర్వచించు LUP_RES_SERVICE 0x8000

#నిర్వచించు LUP_FLUSHCACHE 0x1000
#నిర్వచించు LUP_FLUSHPREVIOUS 0x2000

#నిర్వచించు ఫలితం_IS_ALIAS 0x0001
#నిర్వచించు ఫలితం_IS_ADDED 0x0010
#నిర్వచించు ఫలితం_IS_మారింది 0x0020
#నిర్వచించు ఫలితం_IS_DELETED 0x0040

  రకనిర్వచనం గణన _WSAESETSERVICEOP {
    RNRSERVICE_రిజిస్టరు=0,RNRSERVICE_DEREGISTER,RNRSERVICE_DELETE
  } WSAESETSERVICEOP,*PWSAESETSERVICEOP,*LPWSAESETSERVICEOP;

  రకనిర్వచనం నిర్మాణం _WSANSClassInfoA {
    LPSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_విలువ_Type;
    DWORD dw_విలువ_కొలత;
    LPVOID lp_విలువ;
  } WSANSCLASSINFOA,*PWSANSCLASSINFOA,*LPWSANSCLASSINFOA;

  రకనిర్వచనం నిర్మాణం _WSANSClassInfoW {
    LPWSTR lpszName;
    DWORD dwNameSpace;
    DWORD dw_విలువ_Type;
    DWORD dw_విలువ_కొలత;
    LPVOID lp_విలువ;
  } WSANSCLASSINFOW,*PWSANSCLASSINFOW,*LPWSANSCLASSINFOW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WSANSCLASSINFOW WSANSCLASSINFO;
  రకనిర్వచనం PWSANSCLASSINFOW PWSANSCLASSINFO;
  రకనిర్వచనం LPWSANSCLASSINFOW LPWSANSCLASSINFO;
#లేకపోతే
  రకనిర్వచనం WSANSCLASSINFOA WSANSCLASSINFO;
  రకనిర్వచనం PWSANSCLASSINFOA PWSANSCLASSINFO;
  రకనిర్వచనం LPWSANSCLASSINFOA LPWSANSCLASSINFO;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం _WSAServiceClassInfoA {
    LPGUID lpServiceClassId;
    LPSTR lpszServiceClassName;
    DWORD dw_లెక్క;
    LPWSANSCLASSINFOA lpClassInfos;
  } WSASERVICECLASSINFOA,*PWSASERVICECLASSINFOA,*LPWSASERVICECLASSINFOA;

  రకనిర్వచనం నిర్మాణం _WSAServiceClassInfoW {
    LPGUID lpServiceClassId;
    LPWSTR lpszServiceClassName;
    DWORD dw_లెక్క;
    LPWSANSCLASSINFOW lpClassInfos;
  } WSASERVICECLASSINFOW,*PWSASERVICECLASSINFOW,*LPWSASERVICECLASSINFOW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WSASERVICECLASSINFOW WSASERVICECLASSINFO;
  రకనిర్వచనం PWSASERVICECLASSINFOW PWSASERVICECLASSINFO;
  రకనిర్వచనం LPWSASERVICECLASSINFOW LPWSASERVICECLASSINFO;
#లేకపోతే
  రకనిర్వచనం WSASERVICECLASSINFOA WSASERVICECLASSINFO;
  రకనిర్వచనం PWSASERVICECLASSINFOA PWSASERVICECLASSINFO;
  రకనిర్వచనం LPWSASERVICECLASSINFOA LPWSASERVICECLASSINFO;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం _WSANAMESPACE_INFOA {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_చురుకైన;
    DWORD dw_సంస్కరణ;
    LPSTR lpszIdentifier;
  } WSANAMESPACE_INFOA,*PWSANAMESPACE_INFOA,*LPWSANAMESPACE_INFOA;

  రకనిర్వచనం నిర్మాణం _WSANAMESPACE_INFOW {
    GUID NSProviderId;
    DWORD dwNameSpace;
    WINBOOL f_చురుకైన;
    DWORD dw_సంస్కరణ;
    LPWSTR lpszIdentifier;
  } WSANAMESPACE_INFOW,*PWSANAMESPACE_INFOW,*LPWSANAMESPACE_INFOW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WSANAMESPACE_INFOW WSANAMESPACE_INFO;
  రకనిర్వచనం PWSANAMESPACE_INFOW PWSANAMESPACE_INFO;
  రకనిర్వచనం LPWSANAMESPACE_INFOW LPWSANAMESPACE_INFO;
#లేకపోతే
  రకనిర్వచనం WSANAMESPACE_INFOA WSANAMESPACE_INFO;
  రకనిర్వచనం PWSANAMESPACE_INFOA PWSANAMESPACE_INFO;
  రకనిర్వచనం LPWSANAMESPACE_INFOA LPWSANAMESPACE_INFO;
#అయితే_ముగింపు

#ఒకవేళ INCL_WINSOCK_API_TYPEDEFS
#నిర్వచితమైతే UNICODE
#నిర్వచించు LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETW
#నిర్వచించు LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSW
#నిర్వచించు LPFN_WSASOCKET LPFN_WSASOCKETW
#నిర్వచించు LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGW
#నిర్వచించు LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSW
#నిర్వచించు LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINW
#నిర్వచించు LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTW
#నిర్వచించు LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSW
#నిర్వచించు LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOW
#నిర్వచించు LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSW
#నిర్వచించు LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW
#నిర్వచించు LPFN_WSASETSERVICE LPFN_WSASETSERVICEW
#లేకపోతే
#నిర్వచించు LPFN_WSADUPLICATESOCKET LPFN_WSADUPLICATESOCKETA
#నిర్వచించు LPFN_WSAENUMPROTOCOLS LPFN_WSAENUMPROTOCOLSA
#నిర్వచించు LPFN_WSASOCKET LPFN_WSASOCKETA
#నిర్వచించు LPFN_WSAADDRESSTOSTRING LPFN_WSAADDRESSTOSTRINGA
#నిర్వచించు LPFN_WSASTRINGTOADDRESS LPFN_WSASTRINGTOADDRESSA
#నిర్వచించు LPFN_WSALOOKUPSERVICEBEGIN LPFN_WSALOOKUPSERVICEBEGINA
#నిర్వచించు LPFN_WSALOOKUPSERVICENEXT LPFN_WSALOOKUPSERVICENEXTA
#నిర్వచించు LPFN_WSAINSTALLSERVICECLASS LPFN_WSAINSTALLSERVICECLASSA
#నిర్వచించు LPFN_WSAGETSERVICECLASSINFO LPFN_WSAGETSERVICECLASSINFOA
#నిర్వచించు LPFN_WSAENUMNAMESPACEPROVIDERS LPFN_WSAENUMNAMESPACEPROVIDERSA
#నిర్వచించు LPFN_WSAGETSERVICECLASSNAMEBYCLASSID LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA
#నిర్వచించు LPFN_WSASETSERVICE LPFN_WSASETSERVICEA
#అయితే_ముగింపు

  రకనిర్వచనం SOCKET (WSAAPI *LPFN_ACCEPT)(SOCKET s,నిర్మాణం sockaddr *addr,పూర్ణాంకం *addrlen);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_BIND)(SOCKET s,స్థిరరాశి నిర్మాణం sockaddr *name,పూర్ణాంకం namelen);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_CLOSESOCKET)(SOCKET s);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_CONNECT)(SOCKET s,స్థిరరాశి నిర్మాణం sockaddr *name,పూర్ణాంకం namelen);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_IOCTLSOCKET)(SOCKET s,దీర్ఘ cmd,u_long *argp);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_GETPEERNAME)(SOCKET s,నిర్మాణం sockaddr *name,పూర్ణాంకం *namelen);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_GETSOCKNAME)(SOCKET s,నిర్మాణం sockaddr *name,పూర్ణాంకం *namelen);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_GETSOCKOPT)(SOCKET s,పూర్ణాంకం level,పూర్ణాంకం optname,అక్షరం *optval,పూర్ణాంకం *optlen);
  రకనిర్వచనం u_long (WSAAPI *LPFN_HTONL)(u_long hostlong);
  రకనిర్వచనం u_short (WSAAPI *LPFN_HTONS)(u_short hostshort);
  రకనిర్వచనం గుర్తులేని దీర్ఘ (WSAAPI *LPFN_INET_ADDR)(స్థిరరాశి అక్షరం *cp);
  రకనిర్వచనం అక్షరం *(WSAAPI *LPFN_INET_NTOA)(నిర్మాణం లోపల_addr లోపల);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_LISTEN)(SOCKET s,పూర్ణాంకం backlog);
  రకనిర్వచనం u_long (WSAAPI *LPFN_NTOHL)(u_long netlong);
  రకనిర్వచనం u_short (WSAAPI *LPFN_NTOHS)(u_short netshort);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_RECV)(SOCKET s,అక్షరం *buf,పూర్ణాంకం len,పూర్ణాంకం flags);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_RECVFROM)(SOCKET s,అక్షరం *buf,పూర్ణాంకం len,పూర్ణాంకం flags,నిర్మాణం sockaddr *from,పూర్ణాంకం *fromlen);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_SELECT)(పూర్ణాంకం nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,స్థిరరాశి నిర్మాణం timeval *timeout);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_SEND)(SOCKET s,స్థిరరాశి అక్షరం *buf,పూర్ణాంకం len,పూర్ణాంకం flags);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_SENDTO)(SOCKET s,స్థిరరాశి అక్షరం *buf,పూర్ణాంకం len,పూర్ణాంకం flags,స్థిరరాశి నిర్మాణం sockaddr *గమ్యం,పూర్ణాంకం tolen);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_SETSOCKOPT)(SOCKET s,పూర్ణాంకం level,పూర్ణాంకం optname,స్థిరరాశి అక్షరం *optval,పూర్ణాంకం optlen);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_SHUTDOWN)(SOCKET s,పూర్ణాంకం how);
  రకనిర్వచనం SOCKET (WSAAPI *LPFN_SOCKET)(పూర్ణాంకం af,పూర్ణాంకం type,పూర్ణాంకం protocol);
  రకనిర్వచనం నిర్మాణం hostent *(WSAAPI *LPFN_GETHOSTBYADDR)(స్థిరరాశి అక్షరం *addr,పూర్ణాంకం len,పూర్ణాంకం type);
  రకనిర్వచనం నిర్మాణం hostent *(WSAAPI *LPFN_GETHOSTBYNAME)(స్థిరరాశి అక్షరం *name);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_GETHOSTNAME)(అక్షరం *name,పూర్ణాంకం namelen);
  రకనిర్వచనం నిర్మాణం servent *(WSAAPI *LPFN_GETSERVBYPORT)(పూర్ణాంకం పోర్టు_2,స్థిరరాశి అక్షరం *proto);
  రకనిర్వచనం నిర్మాణం servent *(WSAAPI *LPFN_GETSERVBYNAME)(స్థిరరాశి అక్షరం *name,స్థిరరాశి అక్షరం *proto);
  రకనిర్వచనం నిర్మాణం protoent *(WSAAPI *LPFN_GETPROTOBYNUMBER)(పూర్ణాంకం సంఖ్య_3);
  రకనిర్వచనం నిర్మాణం protoent *(WSAAPI *LPFN_GETPROTOBYNAME)(స్థిరరాశి అక్షరం *name);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSASTARTUP)(మాట_3 w_సంస్కరణ_Requested,LPWSADATA lpWSAData);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSACLEANUP)(శూన్య);
  రకనిర్వచనం శూన్య (WSAAPI *LPFN_WSASETLASTERROR)(పూర్ణాంకం iError);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAGETLASTERROR)(శూన్య);
  రకనిర్వచనం WINBOOL (WSAAPI *LPFN_WSAISBLOCKING)(శూన్య);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAUNHOOKBLOCKINGHOOK)(శూన్య);
  రకనిర్వచనం FARPROC (WSAAPI *LPFN_WSASETBLOCKINGHOOK)(FARPROC lp_ఖండం_Func);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSACANCELBLOCKINGCALL)(శూన్య);
  రకనిర్వచనం HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYNAME)(HWND hWnd,u_int w_సందేశం,స్థిరరాశి అక్షరం *name,స్థిరరాశి అక్షరం *proto,అక్షరం *buf,పూర్ణాంకం buflen);
  రకనిర్వచనం HANDLE (WSAAPI *LPFN_WSAASYNCGETSERVBYPORT)(HWND hWnd,u_int w_సందేశం,పూర్ణాంకం పోర్టు_2,స్థిరరాశి అక్షరం *proto,అక్షరం *buf,పూర్ణాంకం buflen);
  రకనిర్వచనం HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNAME)(HWND hWnd,u_int w_సందేశం,స్థిరరాశి అక్షరం *name,అక్షరం *buf,పూర్ణాంకం buflen);
  రకనిర్వచనం HANDLE (WSAAPI *LPFN_WSAASYNCGETPROTOBYNUMBER)(HWND hWnd,u_int w_సందేశం,పూర్ణాంకం సంఖ్య_3,అక్షరం *buf,పూర్ణాంకం buflen);
  రకనిర్వచనం HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYNAME)(HWND hWnd,u_int w_సందేశం,స్థిరరాశి అక్షరం *name,అక్షరం *buf,పూర్ణాంకం buflen);
  రకనిర్వచనం HANDLE (WSAAPI *LPFN_WSAASYNCGETHOSTBYADDR)(HWND hWnd,u_int w_సందేశం,స్థిరరాశి అక్షరం *addr,పూర్ణాంకం len,పూర్ణాంకం type,అక్షరం *buf,పూర్ణాంకం buflen);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSACANCELASYNCREQUEST)(HANDLE hAsyncTaskHandle);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAASYNCSELECT)(SOCKET s,HWND hWnd,u_int w_సందేశం,దీర్ఘ lEvent);
  రకనిర్వచనం SOCKET (WSAAPI *LPFN_WSAACCEPT)(SOCKET s,నిర్మాణం sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_దత్తాంశం);
  రకనిర్వచనం WINBOOL (WSAAPI *LPFN_WSACLOSEEVENT)(WSAEVENT hEvent);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSACONNECT)(SOCKET s,స్థిరరాశి నిర్మాణం sockaddr *name,పూర్ణాంకం namelen,LPWSABUF lp_Caller_దత్తాంశం,LPWSABUF lp_Callee_దత్తాంశం,LPQOS lpSQOS,LPQOS lpGQOS);
  రకనిర్వచనం WSAEVENT (WSAAPI *LPFN_WSACREATEEVENT)(శూన్య);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSADUPLICATESOCKETA)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSADUPLICATESOCKETW)(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAENUMNETWORKEVENTS)(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_జాలం_Events);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAENUMPROTOCOLSA)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_బఫరు,LPDWORD lpdw_బఫరు_నిడివి);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAENUMPROTOCOLSW)(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_బఫరు,LPDWORD lpdw_బఫరు_నిడివి);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAEVENTSELECT)(SOCKET s,WSAEVENT hEventObject,దీర్ఘ l_జాలం_Events);
  రకనిర్వచనం WINBOOL (WSAAPI *LPFN_WSAGETOVERLAPPEDRESULT)(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  రకనిర్వచనం WINBOOL (WSAAPI *LPFN_WSAGETQOSBYNAME)(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAHTONL)(SOCKET s,u_long hostlong,u_long *lpnetlong);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAHTONS)(SOCKET s,u_short hostshort,u_short *lpnetshort);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSAIOCTL)(SOCKET s,DWORD dw_Io_Control_సంకేతం,LPVOID lpv_లోపల_బఫరు,DWORD cb_లోపల_బఫరు,LPVOID lpv_బహిర్గతం_బఫరు,DWORD cb_బహిర్గతం_బఫరు,LPDWORD lpcb_బైట్లు_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  రకనిర్వచనం SOCKET (WSAAPI *LPFN_WSAJOINLEAF)(SOCKET s,స్థిరరాశి నిర్మాణం sockaddr *name,పూర్ణాంకం namelen,LPWSABUF lp_Caller_దత్తాంశం,LPWSABUF lp_Callee_దత్తాంశం,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSANTOHL)(SOCKET s,u_long netlong,u_long *lphostlong);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSANTOHS)(SOCKET s,u_short netshort,u_short *lphostshort);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSARECV)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_బఫరు_లెక్క,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSARECVDISCONNECT)(SOCKET s,LPWSABUF lp_Inbound_Disconnect_దత్తాంశం);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSARECVFROM)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_బఫరు_లెక్క,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Recvd,LPDWORD lpFlags,నిర్మాణం sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  రకనిర్వచనం WINBOOL (WSAAPI *LPFN_WSARESETEVENT)(WSAEVENT hEvent);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSASEND)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_బఫరు_లెక్క,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_పంపిన,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSASENDDISCONNECT)(SOCKET s,LPWSABUF lp_Outbound_Disconnect_దత్తాంశం);
  రకనిర్వచనం పూర్ణాంకం (WSAAPI *LPFN_WSASENDTO)(SOCKET s,LPWSABUF lpBuffers,DWORD dw_బఫరు_లెక్క,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_పంపిన,DWORD dwFlags,స్థిరరాశి నిర్మాణం sockaddr *lp_గమ్యం,పూర్ణాంకం iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  రకనిర్వచనం WINBOOL (WSAAPI *LPFN_WSASETEVENT)(WSAEVENT hEvent);
  రకనిర్వచనం SOCKET (WSAAPI *LPFN_WSASOCKETA)(పూర్ణాంకం af,పూర్ణాంకం type,పూర్ణాంకం protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,సమూహం_3 g,DWORD dwFlags);
  రకనిర్వచనం SOCKET (WSAAPI *LPFN_WSASOCKETW)(పూర్ణాంకం af,పూర్ణాంకం type,పూర్ణాంకం protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,సమూహం_3 g,DWORD dwFlags);
  రకనిర్వచనం DWORD (WSAAPI *LPFN_WSAWAITFORMULTIPLEEVENTS)(DWORD cEvents,స్థిరరాశి WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGA)(LPSOCKADDR lpsa_చిరునామా,DWORD dw_చిరునామా_నిడివి,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_చిరునామా_String,LPDWORD lpdw_చిరునామా_String_నిడివి);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAADDRESSTOSTRINGW)(LPSOCKADDR lpsa_చిరునామా,DWORD dw_చిరునామా_నిడివి,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_చిరునామా_String,LPDWORD lpdw_చిరునామా_String_నిడివి);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSASTRINGTOADDRESSA)(LPSTR చిరునామా_String,INT చిరునామా_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_చిరునామా,LPINT lp_చిరునామా_నిడివి);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSASTRINGTOADDRESSW)(LPWSTR చిరునామా_String,INT చిరునామా_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_చిరునామా,LPINT lp_చిరునామా_నిడివి);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINA)(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSALOOKUPSERVICEBEGINW)(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTA)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_బఫరు_నిడివి,LPWSAQUERYSETA lpqsResults);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSALOOKUPSERVICENEXTW)(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_బఫరు_నిడివి,LPWSAQUERYSETW lpqsResults);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSANSPIOCTL)(HANDLE hLookup,DWORD dw_Control_సంకేతం,LPVOID lpv_లోపల_బఫరు,DWORD cb_లోపల_బఫరు,LPVOID lpv_బహిర్గతం_బఫరు,DWORD cb_బహిర్గతం_బఫరు,LPDWORD lpcb_బైట్లు_Returned,LPWSACOMPLETION lpCompletion);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSALOOKUPSERVICEEND)(HANDLE hLookup);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSA)(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAINSTALLSERVICECLASSW)(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAREMOVESERVICECLASS)(LPGUID lpServiceClassId);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOA)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_కొలత,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAGETSERVICECLASSINFOW)(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_కొలత,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSA)(LPDWORD lpdw_బఫరు_నిడివి,LPWSANAMESPACE_INFOA lpnsp_బఫరు);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAENUMNAMESPACEPROVIDERSW)(LPDWORD lpdw_బఫరు_నిడివి,LPWSANAMESPACE_INFOW lpnsp_బఫరు);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDA)(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_బఫరు_నిడివి);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAGETSERVICECLASSNAMEBYCLASSIDW)(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_బఫరు_నిడివి);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSASETSERVICEA)(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSASETSERVICEW)(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  రకనిర్వచనం INT (WSAAPI *LPFN_WSAPROVIDERCONFIGCHANGE)(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు WSADuplicateSocket WSADuplicateSocketW
#నిర్వచించు WSAEnumProtocols WSAEnumProtocolsW
#నిర్వచించు WSAAddress_గమ్యం_String WSAAddress_గమ్యం_String_W
#నిర్వచించు WSASocket WSASocketW
#నిర్వచించు WSAString_గమ్యం_చిరునామా WSAString_గమ్యం_చిరునామా_W
#నిర్వచించు WSALookupServiceBegin WSALookupServiceBeginW
#నిర్వచించు WSALookup_Service_తదుపరి WSALookup_Service_తదుపరి_W
#నిర్వచించు WSAInstallServiceClass WSAInstallServiceClassW
#నిర్వచించు WSAGetServiceClassInfo WSAGetServiceClassInfoW
#నిర్వచించు WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersW
#నిర్వచించు WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdW
#నిర్వచించు WSASetService WSASetServiceW
#లేకపోతే
#నిర్వచించు WSADuplicateSocket WSADuplicateSocketA
#నిర్వచించు WSAEnumProtocols WSAEnumProtocolsA
#నిర్వచించు WSASocket WSASocketA
#నిర్వచించు WSAAddress_గమ్యం_String WSAAddress_గమ్యం_String_A
#నిర్వచించు WSAString_గమ్యం_చిరునామా WSAString_గమ్యం_చిరునామా_A
#నిర్వచించు WSALookupServiceBegin WSALookupServiceBeginA
#నిర్వచించు WSALookup_Service_తదుపరి WSALookup_Service_తదుపరి_A
#నిర్వచించు WSAInstallServiceClass WSAInstallServiceClassA
#నిర్వచించు WSAGetServiceClassInfo WSAGetServiceClassInfoA
#నిర్వచించు WSAEnumNameSpaceProviders WSAEnumNameSpaceProvidersA
#నిర్వచించు WSAGetServiceClassNameByClassId WSAGetServiceClassNameByClassIdA
#నిర్వచించు WSASetService WSASetServiceA
#అయితే_ముగింపు

  WINSOCK_API_LINKAGE SOCKET WSAAPI accept(SOCKET s,నిర్మాణం sockaddr *addr,పూర్ణాంకం *addrlen);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI bind(SOCKET s,స్థిరరాశి నిర్మాణం sockaddr *name,పూర్ణాంకం namelen);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI closesocket(SOCKET s);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI connect(SOCKET s,స్థిరరాశి నిర్మాణం sockaddr *name,పూర్ణాంకం namelen);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI ioctlsocket(SOCKET s,దీర్ఘ cmd,u_long *argp);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI getpeername(SOCKET s,నిర్మాణం sockaddr *name,పూర్ణాంకం *namelen);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI getsockname(SOCKET s,నిర్మాణం sockaddr *name,పూర్ణాంకం *namelen);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI getsockopt(SOCKET s,పూర్ణాంకం level,పూర్ణాంకం optname,అక్షరం *optval,పూర్ణాంకం *optlen);
  WINSOCK_API_LINKAGE u_long WSAAPI htonl(u_long hostlong);
  WINSOCK_API_LINKAGE u_short WSAAPI htons(u_short hostshort);
  WINSOCK_API_LINKAGE గుర్తులేని దీర్ఘ WSAAPI inet_addr(స్థిరరాశి అక్షరం *cp);
  WINSOCK_API_LINKAGE అక్షరం *WSAAPI inet_ntoa(నిర్మాణం లోపల_addr లోపల);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI listen(SOCKET s,పూర్ణాంకం backlog);
  WINSOCK_API_LINKAGE u_long WSAAPI ntohl(u_long netlong);
  WINSOCK_API_LINKAGE u_short WSAAPI ntohs(u_short netshort);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI recv(SOCKET s,అక్షరం *buf,పూర్ణాంకం len,పూర్ణాంకం flags);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI recvfrom(SOCKET s,అక్షరం *buf,పూర్ణాంకం len,పూర్ణాంకం flags,నిర్మాణం sockaddr *from,పూర్ణాంకం *fromlen);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI select(పూర్ణాంకం nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,స్థిరరాశి నిర్మాణం timeval *timeout);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI send(SOCKET s,స్థిరరాశి అక్షరం *buf,పూర్ణాంకం len,పూర్ణాంకం flags);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI sendto(SOCKET s,స్థిరరాశి అక్షరం *buf,పూర్ణాంకం len,పూర్ణాంకం flags,స్థిరరాశి నిర్మాణం sockaddr *గమ్యం,పూర్ణాంకం tolen);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI setsockopt(SOCKET s,పూర్ణాంకం level,పూర్ణాంకం optname,స్థిరరాశి అక్షరం *optval,పూర్ణాంకం optlen);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI shutdown(SOCKET s,పూర్ణాంకం how);
  WINSOCK_API_LINKAGE SOCKET WSAAPI socket(పూర్ణాంకం af,పూర్ణాంకం type,పూర్ణాంకం protocol);
  WINSOCK_API_LINKAGE నిర్మాణం hostent *WSAAPI gethostbyaddr(స్థిరరాశి అక్షరం *addr,పూర్ణాంకం len,పూర్ణాంకం type);
  WINSOCK_API_LINKAGE నిర్మాణం hostent *WSAAPI gethostbyname(స్థిరరాశి అక్షరం *name);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI gethostname(అక్షరం *name,పూర్ణాంకం namelen);
  WINSOCK_API_LINKAGE నిర్మాణం servent *WSAAPI getservbyport(పూర్ణాంకం పోర్టు_2,స్థిరరాశి అక్షరం *proto);
  WINSOCK_API_LINKAGE నిర్మాణం servent *WSAAPI getservbyname(స్థిరరాశి అక్షరం *name,స్థిరరాశి అక్షరం *proto);
  WINSOCK_API_LINKAGE నిర్మాణం protoent *WSAAPI getprotobynumber(పూర్ణాంకం సంఖ్య_3);
  WINSOCK_API_LINKAGE నిర్మాణం protoent *WSAAPI getprotobyname(స్థిరరాశి అక్షరం *name);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAStartup(మాట_3 w_సంస్కరణ_Requested,LPWSADATA lpWSAData);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSACleanup(శూన్య);
  WINSOCK_API_LINKAGE శూన్య WSAAPI WSASet_చివరి_Error(పూర్ణాంకం iError);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAGet_చివరి_Error(శూన్య);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAIsBlocking(శూన్య);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAUnhookBlockingHook(శూన్య);
  WINSOCK_API_LINKAGE FARPROC WSAAPI WSASetBlockingHook(FARPROC lp_ఖండం_Func);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSACancelBlockingCall(శూన్య);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetServByName(HWND hWnd,u_int w_సందేశం,స్థిరరాశి అక్షరం *name,స్థిరరాశి అక్షరం *proto,అక్షరం *buf,పూర్ణాంకం buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Serv_By_పోర్టు(HWND hWnd,u_int w_సందేశం,పూర్ణాంకం పోర్టు_2,స్థిరరాశి అక్షరం *proto,అక్షరం *buf,పూర్ణాంకం buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetProtoByName(HWND hWnd,u_int w_సందేశం,స్థిరరాశి అక్షరం *name,అక్షరం *buf,పూర్ణాంకం buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsync_Get_Proto_By_సంఖ్య(HWND hWnd,u_int w_సందేశం,పూర్ణాంకం సంఖ్య_3,అక్షరం *buf,పూర్ణాంకం buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByName(HWND hWnd,u_int w_సందేశం,స్థిరరాశి అక్షరం *name,అక్షరం *buf,పూర్ణాంకం buflen);
  WINSOCK_API_LINKAGE HANDLE WSAAPI WSAAsyncGetHostByAddr(HWND hWnd,u_int w_సందేశం,స్థిరరాశి అక్షరం *addr,పూర్ణాంకం len,పూర్ణాంకం type,అక్షరం *buf,పూర్ణాంకం buflen);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSACancelAsyncRequest(HANDLE hAsyncTaskHandle);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAAsyncSelect(SOCKET s,HWND hWnd,u_int w_సందేశం,దీర్ఘ lEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAAccept(SOCKET s,నిర్మాణం sockaddr *addr,LPINT addrlen,LPCONDITIONPROC lpfnCondition,DWORD_PTR dw_Callback_దత్తాంశం);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSACloseEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAConnect(SOCKET s,స్థిరరాశి నిర్మాణం sockaddr *name,పూర్ణాంకం namelen,LPWSABUF lp_Caller_దత్తాంశం,LPWSABUF lp_Callee_దత్తాంశం,LPQOS lpSQOS,LPQOS lpGQOS);
  WINSOCK_API_LINKAGE WSAEVENT WSAAPI WSACreateEvent(శూన్య);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSADuplicateSocketA(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOA lpProtocolInfo);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSADuplicateSocketW(SOCKET s,DWORD dwProcessId,LPWSAPROTOCOL_INFOW lpProtocolInfo);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAEnum_జాలం_Events(SOCKET s,WSAEVENT hEventObject,LPWSANETWORKEVENTS lp_జాలం_Events);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAEnumProtocolsA(LPINT lpiProtocols,LPWSAPROTOCOL_INFOA lp_Protocol_బఫరు,LPDWORD lpdw_బఫరు_నిడివి);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAEnumProtocolsW(LPINT lpiProtocols,LPWSAPROTOCOL_INFOW lp_Protocol_బఫరు,LPDWORD lpdw_బఫరు_నిడివి);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAEventSelect(SOCKET s,WSAEVENT hEventObject,దీర్ఘ l_జాలం_Events);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGet_Overlapped_ఫలితం(SOCKET s,LPWSAOVERLAPPED lpOverlapped,LPDWORD lpcbTransfer,WINBOOL fWait,LPDWORD lpdwFlags);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAGetQOSByName(SOCKET s,LPWSABUF lpQOSName,LPQOS lpQOS);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAHtonl(SOCKET s,u_long hostlong,u_long *lpnetlong);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAHtons(SOCKET s,u_short hostshort,u_short *lpnetshort);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAIoctl(SOCKET s,DWORD dw_Io_Control_సంకేతం,LPVOID lpv_లోపల_బఫరు,DWORD cb_లోపల_బఫరు,LPVOID lpv_బహిర్గతం_బఫరు,DWORD cb_బహిర్గతం_బఫరు,LPDWORD lpcb_బైట్లు_Returned,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSAJoin_ఆకు(SOCKET s,స్థిరరాశి నిర్మాణం sockaddr *name,పూర్ణాంకం namelen,LPWSABUF lp_Caller_దత్తాంశం,LPWSABUF lp_Callee_దత్తాంశం,LPQOS lpSQOS,LPQOS lpGQOS,DWORD dwFlags);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSANtohl(SOCKET s,u_long netlong,u_long *lphostlong);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSANtohs(SOCKET s,u_short netshort,u_short *lphostshort);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSARecv(SOCKET s,LPWSABUF lpBuffers,DWORD dw_బఫరు_లెక్క,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Recvd,LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSARecvDisconnect(SOCKET s,LPWSABUF lp_Inbound_Disconnect_దత్తాంశం);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSARecvFrom(SOCKET s,LPWSABUF lpBuffers,DWORD dw_బఫరు_లెక్క,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Recvd,LPDWORD lpFlags,నిర్మాణం sockaddr *lpFrom,LPINT lpFromlen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSAResetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSASend(SOCKET s,LPWSABUF lpBuffers,DWORD dw_బఫరు_లెక్క,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_పంపిన,DWORD dwFlags,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSASendDisconnect(SOCKET s,LPWSABUF lp_Outbound_Disconnect_దత్తాంశం);
  WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSASend_గమ్యం(SOCKET s,LPWSABUF lpBuffers,DWORD dw_బఫరు_లెక్క,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_పంపిన,DWORD dwFlags,స్థిరరాశి నిర్మాణం sockaddr *lp_గమ్యం,పూర్ణాంకం iTolen,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINSOCK_API_LINKAGE WINBOOL WSAAPI WSASetEvent(WSAEVENT hEvent);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketA(పూర్ణాంకం af,పూర్ణాంకం type,పూర్ణాంకం protocol,LPWSAPROTOCOL_INFOA lpProtocolInfo,సమూహం_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE SOCKET WSAAPI WSASocketW(పూర్ణాంకం af,పూర్ణాంకం type,పూర్ణాంకం protocol,LPWSAPROTOCOL_INFOW lpProtocolInfo,సమూహం_3 g,DWORD dwFlags);
  WINSOCK_API_LINKAGE DWORD WSAAPI WSAWait_For_గుణిజం_Events(DWORD cEvents,స్థిరరాశి WSAEVENT *lphEvents,WINBOOL fWaitAll,DWORD dwTimeout,WINBOOL fAlertable);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_గమ్యం_String_A(LPSOCKADDR lpsa_చిరునామా,DWORD dw_చిరునామా_నిడివి,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSTR lpsz_చిరునామా_String,LPDWORD lpdw_చిరునామా_String_నిడివి);
  WINSOCK_API_LINKAGE INT WSAAPI WSAAddress_గమ్యం_String_W(LPSOCKADDR lpsa_చిరునామా,DWORD dw_చిరునామా_నిడివి,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPWSTR lpsz_చిరునామా_String,LPDWORD lpdw_చిరునామా_String_నిడివి);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_గమ్యం_చిరునామా_A(LPSTR చిరునామా_String,INT చిరునామా_Family,LPWSAPROTOCOL_INFOA lpProtocolInfo,LPSOCKADDR lp_చిరునామా,LPINT lp_చిరునామా_నిడివి);
  WINSOCK_API_LINKAGE INT WSAAPI WSAString_గమ్యం_చిరునామా_W(LPWSTR చిరునామా_String,INT చిరునామా_Family,LPWSAPROTOCOL_INFOW lpProtocolInfo,LPSOCKADDR lp_చిరునామా,LPINT lp_చిరునామా_నిడివి);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginA(LPWSAQUERYSETA lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookupServiceBeginW(LPWSAQUERYSETW lpqsRestrictions,DWORD dwControlFlags,LPHANDLE lphLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_తదుపరి_A(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_బఫరు_నిడివి,LPWSAQUERYSETA lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_తదుపరి_W(HANDLE hLookup,DWORD dwControlFlags,LPDWORD lpdw_బఫరు_నిడివి,LPWSAQUERYSETW lpqsResults);
  WINSOCK_API_LINKAGE INT WSAAPI WSANSPIoctl(HANDLE hLookup,DWORD dw_Control_సంకేతం,LPVOID lpv_లోపల_బఫరు,DWORD cb_లోపల_బఫరు,LPVOID lpv_బహిర్గతం_బఫరు,DWORD cb_బహిర్గతం_బఫరు,LPDWORD lpcb_బైట్లు_Returned,LPWSACOMPLETION lpCompletion);
  WINSOCK_API_LINKAGE INT WSAAPI WSALookup_Service_చివర(HANDLE hLookup);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassA(LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAInstallServiceClassW(LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSARemoveServiceClass(LPGUID lpServiceClassId);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoA(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_కొలత,LPWSASERVICECLASSINFOA lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassInfoW(LPGUID lpProviderId,LPGUID lpServiceClassId,LPDWORD lpdw_Buf_కొలత,LPWSASERVICECLASSINFOW lpServiceClassInfo);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersA(LPDWORD lpdw_బఫరు_నిడివి,LPWSANAMESPACE_INFOA lpnsp_బఫరు);
  WINSOCK_API_LINKAGE INT WSAAPI WSAEnumNameSpaceProvidersW(LPDWORD lpdw_బఫరు_నిడివి,LPWSANAMESPACE_INFOW lpnsp_బఫరు);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdA(LPGUID lpServiceClassId,LPSTR lpszServiceClassName,LPDWORD lpdw_బఫరు_నిడివి);
  WINSOCK_API_LINKAGE INT WSAAPI WSAGetServiceClassNameByClassIdW(LPGUID lpServiceClassId,LPWSTR lpszServiceClassName,LPDWORD lpdw_బఫరు_నిడివి);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceA(LPWSAQUERYSETA lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSASetServiceW(LPWSAQUERYSETW lpqsRegInfo,WSAESETSERVICEOP essoperation,DWORD dwControlFlags);
  WINSOCK_API_LINKAGE INT WSAAPI WSAProviderConfigChange(LPHANDLE lpNotificationHandle,LPWSAOVERLAPPED lpOverlapped,LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

  రకనిర్వచనం నిర్మాణం sockaddr_లోపల SOCKADDR_లోపల;
  రకనిర్వచనం నిర్మాణం sockaddr_లోపల *PSOCKADDR_లోపల;
  రకనిర్వచనం నిర్మాణం sockaddr_లోపల *LPSOCKADDR_లోపల;

  రకనిర్వచనం నిర్మాణం linger LINGER;
  రకనిర్వచనం నిర్మాణం linger *PLINGER;
  రకనిర్వచనం నిర్మాణం linger *LPLINGER;

  రకనిర్వచనం నిర్మాణం లోపల_addr లోపల_ADDR;
  రకనిర్వచనం నిర్మాణం లోపల_addr *PIN_ADDR;
  రకనిర్వచనం నిర్మాణం లోపల_addr *LPIN_ADDR;

  రకనిర్వచనం నిర్మాణం fd_set FD_SET;
  రకనిర్వచనం నిర్మాణం fd_set *PFD_సమితి;
  రకనిర్వచనం నిర్మాణం fd_set *LPFD_సమితి;

  రకనిర్వచనం నిర్మాణం hostent HOSTENT;
  రకనిర్వచనం నిర్మాణం hostent *PHOSTENT;
  రకనిర్వచనం నిర్మాణం hostent *LPHOSTENT;

  రకనిర్వచనం నిర్మాణం servent SERVENT;
  రకనిర్వచనం నిర్మాణం servent *PSERVENT;
  రకనిర్వచనం నిర్మాణం servent *LPSERVENT;

  రకనిర్వచనం నిర్మాణం protoent PROTOENT;
  రకనిర్వచనం నిర్మాణం protoent *PPROTOENT;
  రకనిర్వచనం నిర్మాణం protoent *LPPROTOENT;

  రకనిర్వచనం నిర్మాణం timeval TIMEVAL;
  రకనిర్వచనం నిర్మాణం timeval *PTIMEVAL;
  రకనిర్వచనం నిర్మాణం timeval *LPTIMEVAL;

#నిర్వచించు WSAMAKEASYNCREPLY(buflen,error) MAKELONG(buflen,error)
#నిర్వచించు WSAMAKESELECTREPLY(event,error) MAKELONG(event,error)
#నిర్వచించు WSAGETASYNCBUFLEN(lParam) LOWORD(lParam)
#నిర్వచించు WSAGETASYNCERROR(lParam) HIWORD(lParam)
#నిర్వచించు WSAGETSELECTEVENT(lParam) LOWORD(lParam)
#నిర్వచించు WSAGETSELECTERROR(lParam) HIWORD(lParam)

/* #if (_WIN32_WINNT >= 0x0600) */
#నిర్వచించు POLLRDNORM  0x0100
#నిర్వచించు POLLRDBAND  0x0200
#నిర్వచించు POLLIN      (POLLRDNORM | POLLRDBAND)
#నిర్వచించు POLLPRI     0x0400

#నిర్వచించు POLLWRNORM  0x0010
#నిర్వచించు POLLOUT     (POLLWRNORM)
#నిర్వచించు POLLWRBAND  0x0020

#నిర్వచించు POLLERR     0x0001
#నిర్వచించు POLLHUP     0x0002
#నిర్వచించు POLLNVAL    0x0004

రకనిర్వచనం నిర్మాణం pollfd {
        SOCKET fd;
        SHORT  events;
        SHORT  revents;
} WSAPOLLFD, *PWSAPOLLFD, FAR *LPWSAPOLLFD;

WINSOCK_API_LINKAGE పూర్ణాంకం WSAAPI WSAPoll(LPWSAPOLLFD fdArray, ULONG fds, INT timeout);
/* #endif // (_WIN32_WINNT >= 0x0600) */

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#నిర్వచితమైతే _NEED_POPPACK
#అన్తర్భావ <poppack.h>
#అయితే_ముగింపు

#నిర్వచితమైతే IPV6STRICT
#అన్తర్భావ <wsipv6ok.h>
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WINSOCKAPI_
#నిర్వచించు _WINSOCKAPI_
#అయితే_ముగింపు

#నిర్వచితమైతే _INC_WINSOCK_H
#అన్తర్భావ <mswsock.h>
#అయితే_ముగింపు

#అయితే_ముగింపు
