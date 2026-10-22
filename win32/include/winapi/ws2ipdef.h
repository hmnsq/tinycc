#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#যদি __GNUC__ >=3
#pragma GCC system_header
#endif

#অন্তর্ভাব <winsock2.h>

কাঠামো ip_mreq {
  কাঠামো in_addr imr_multiaddr;
  কাঠামো in_addr imr_interface;
};

কাঠামো ip_mreq_source {
  কাঠামো in_addr imr_multiaddr;
  কাঠামো in_addr imr_sourceaddr;
  কাঠামো in_addr imr_interface;
};

#endif
