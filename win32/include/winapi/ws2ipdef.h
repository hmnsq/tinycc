#جيڪڏهن_وصف_نه_ٿيل _WS2IPDEF_H
#وصف_ڪريو _WS2IPDEF_H

#إذا __GNUC__ >=3
#هدايت GCC system_سرو
#جيڪڏهن_پورو

#ضمن <winsock2.h>

بنية ip_mreq {
  بنية اندريون_addr imr_multiaddr;
  بنية اندريون_addr imr_interface;
};

بنية ip_mreq_ذريعو {
  بنية اندريون_addr imr_multiaddr;
  بنية اندريون_addr imr_sourceaddr;
  بنية اندريون_addr imr_interface;
};

#جيڪڏهن_پورو
