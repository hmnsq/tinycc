#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#जइ __GNUC__ >=3
#pragma GCC system_header
#endif

#अन्तर्भाव <winsock2.h>

संरचना ip_mreq {
  संरचना in_addr imr_multiaddr;
  संरचना in_addr imr_interface;
};

संरचना ip_mreq_source {
  संरचना in_addr imr_multiaddr;
  संरचना in_addr imr_sourceaddr;
  संरचना in_addr imr_interface;
};

#endif
