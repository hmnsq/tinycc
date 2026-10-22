#جے_بنا_تعریف _WS2IPDEF_H
#تعریف_کرو _WS2IPDEF_H

#إذا __GNUC__ >=3
#ہدایت GCC system_سرخی
#جے_انت

#ضمن <winsock2.h>

بنية ip_mreq {
  بنية وچ_addr imr_multiaddr;
  بنية وچ_addr imr_interface;
};

بنية ip_mreq_سروت {
  بنية وچ_addr imr_multiaddr;
  بنية وچ_addr imr_sourceaddr;
  بنية وچ_addr imr_interface;
};

#جے_انت
