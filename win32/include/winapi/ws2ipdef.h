#که_نه_تعریف_شوی _WS2IPDEF_H
#تعریف_کړه _WS2IPDEF_H

#إذا __GNUC__ >=3
#لارښوونه GCC system_سرلیک
#د_که_پای

#ضمن <winsock2.h>

بنية ip_mreq {
  بنية دننه_addr imr_multiaddr;
  بنية دننه_addr imr_interface;
};

بنية ip_mreq_سرچینه {
  بنية دننه_addr imr_multiaddr;
  بنية دننه_addr imr_sourceaddr;
  بنية دننه_addr imr_interface;
};

#د_که_پای
