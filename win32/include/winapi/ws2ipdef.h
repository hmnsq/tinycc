#यदि_अपरिभाषितम् _WS2IPDEF_H
#परिभाषय _WS2IPDEF_H

#यदि __GNUC__ >=3
#निर्देशः GCC system_शीर्षकम्
#यदि_अन्तः

#अन्तर्भाव <winsock2.h>

संरचना ip_mreq {
  संरचना अन्तर्_addr imr_multiaddr;
  संरचना अन्तर्_addr imr_interface;
};

संरचना ip_mreq_source {
  संरचना अन्तर्_addr imr_multiaddr;
  संरचना अन्तर्_addr imr_sourceaddr;
  संरचना अन्तर्_addr imr_interface;
};

#यदि_अन्तः
