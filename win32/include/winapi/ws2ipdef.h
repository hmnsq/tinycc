#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#എങ്കിൽ __GNUC__ >=3
#pragma GCC system_header
#endif

#അന്തര്ഭാവ <winsock2.h>

ഘടന ip_mreq {
  ഘടന in_addr imr_multiaddr;
  ഘടന in_addr imr_interface;
};

ഘടന ip_mreq_source {
  ഘടന in_addr imr_multiaddr;
  ഘടന in_addr imr_sourceaddr;
  ഘടന in_addr imr_interface;
};

#endif
