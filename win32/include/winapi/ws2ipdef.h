#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#જો __GNUC__ >=3
#pragma GCC system_header
#endif

#અન્તર્ભાવ <winsock2.h>

સંરચના ip_mreq {
  સંરચના in_addr imr_multiaddr;
  સંરચના in_addr imr_interface;
};

સંરચના ip_mreq_source {
  સંરચના in_addr imr_multiaddr;
  સંરચના in_addr imr_sourceaddr;
  સંરચના in_addr imr_interface;
};

#endif
