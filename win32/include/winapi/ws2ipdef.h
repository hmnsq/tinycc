#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#ଯଦି __GNUC__ >=3
#pragma GCC system_header
#endif

#ଅନ୍ତର୍ଭାଵ <winsock2.h>

ସଂରଚନା ip_mreq {
  ସଂରଚନା in_addr imr_multiaddr;
  ସଂରଚନା in_addr imr_interface;
};

ସଂରଚନା ip_mreq_source {
  ସଂରଚନା in_addr imr_multiaddr;
  ସଂରଚନା in_addr imr_sourceaddr;
  ସଂରଚନା in_addr imr_interface;
};

#endif
