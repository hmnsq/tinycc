#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#གལ་སྲིད __GNUC__ >=3
#pragma GCC system_header
#endif

#include <winsock2.h>

sa_nracanaa ip_mreq {
  sa_nracanaa in_addr imr_multiaddr;
  sa_nracanaa in_addr imr_interface;
};

sa_nracanaa ip_mreq_source {
  sa_nracanaa in_addr imr_multiaddr;
  sa_nracanaa in_addr imr_sourceaddr;
  sa_nracanaa in_addr imr_interface;
};

#endif
