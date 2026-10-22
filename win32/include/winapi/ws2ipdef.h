#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#اگر __GNUC__ >=3
#pragma GCC system_header
#endif

#شامل <winsock2.h>

ساختار ip_mreq {
  ساختار in_addr imr_multiaddr;
  ساختار in_addr imr_interface;
};

ساختار ip_mreq_source {
  ساختار in_addr imr_multiaddr;
  ساختار in_addr imr_sourceaddr;
  ساختار in_addr imr_interface;
};

#endif
