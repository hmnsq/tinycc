#اگر_غیر_تعریف_شدہ _WS2IPDEF_H
#تعریف_کرو _WS2IPDEF_H

#اگر __GNUC__ >=3
#ہدایت GCC system_سرخی
#اگر_ختم

#شامل <winsock2.h>

ساخت ip_mreq {
  ساخت اندر_addr imr_multiaddr;
  ساخت اندر_addr imr_interface;
};

ساخت ip_mreq_ماخذ {
  ساخت اندر_addr imr_multiaddr;
  ساخت اندر_addr imr_sourceaddr;
  ساخت اندر_addr imr_interface;
};

#اگر_ختم
