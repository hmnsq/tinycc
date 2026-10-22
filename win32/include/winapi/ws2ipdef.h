#ifndef _WS2IPDEF_H
#define _WS2IPDEF_H

#𐡄𐡍 __GNUC__ >=3
#pragma GCC system_header
#endif

#ضمن <winsock2.h>

بنية ip_mreq {
  بنية in_addr imr_multiaddr;
  بنية in_addr imr_interface;
};

بنية ip_mreq_source {
  بنية in_addr imr_multiaddr;
  بنية in_addr imr_sourceaddr;
  بنية in_addr imr_interface;
};

#endif
