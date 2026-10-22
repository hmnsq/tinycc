#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#ಯದಿ __GNUC__ >=3
#pragma GCC system_header
#endif

#ಅನ್ತರ್ಭಾವ <winsock2.h>

ಸಂರಚನಾ ip_mreq {
  ಸಂರಚನಾ in_addr imr_multiaddr;
  ಸಂರಚನಾ in_addr imr_interface;
};

ಸಂರಚನಾ ip_mreq_source {
  ಸಂರಚನಾ in_addr imr_multiaddr;
  ಸಂರಚನಾ in_addr imr_sourceaddr;
  ಸಂರಚನಾ in_addr imr_interface;
};

#endif
