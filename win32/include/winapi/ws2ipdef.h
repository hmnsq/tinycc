#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#எனில் __GNUC__ >=3
#pragma GCC system_header
#endif

#அந்தர்பாவ <winsock2.h>

கட்டமைப்பு ip_mreq {
  கட்டமைப்பு in_addr imr_multiaddr;
  கட்டமைப்பு in_addr imr_interface;
};

கட்டமைப்பு ip_mreq_source {
  கட்டமைப்பு in_addr imr_multiaddr;
  கட்டமைப்பு in_addr imr_sourceaddr;
  கட்டமைப்பு in_addr imr_interface;
};

#endif
