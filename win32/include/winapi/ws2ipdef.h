#اگر_تعریف_نشده _WS2IPDEF_H
#تعریف_کن _WS2IPDEF_H

#إذا __GNUC__ >=3
#رهنمود GCC system_سرآیند
#پایان_اگر

#ضمن <winsock2.h>

بنية ip_mreq {
  بنية درون_addr imr_multiaddr;
  بنية درون_addr imr_interface;
};

بنية ip_mreq_منبع {
  بنية درون_addr imr_multiaddr;
  بنية درون_addr imr_sourceaddr;
  بنية درون_addr imr_interface;
};

#پایان_اگر
