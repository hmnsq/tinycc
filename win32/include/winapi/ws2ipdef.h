#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#যদি __GNUC__ >=3
#pragma GCC system_header
#endif

#অন্তর্ভাব <winsock2.h>

সংরচনা ip_mreq {
  সংরচনা in_addr imr_multiaddr;
  সংরচনা in_addr imr_interface;
};

সংরচনা ip_mreq_source {
  সংরচনা in_addr imr_multiaddr;
  সংরচনা in_addr imr_sourceaddr;
  সংরচনা in_addr imr_interface;
};

#endif
