#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WS2IPDEF_H
#ವ್ಯಾಖ್ಯಾನಿಸು _WS2IPDEF_H

#ಆದರೆ __GNUC__ >=3
#ಸೂಚನೆ GCC system_ಶೀರ್ಷಿಕೆ
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <winsock2.h>

ರಚನೆ ip_mreq {
  ರಚನೆ ಒಳ_addr imr_multiaddr;
  ರಚನೆ ಒಳ_addr imr_interface;
};

ರಚನೆ ip_mreq_ಮೂಲ {
  ರಚನೆ ಒಳ_addr imr_multiaddr;
  ರಚನೆ ಒಳ_addr imr_sourceaddr;
  ರಚನೆ ಒಳ_addr imr_interface;
};

#ಆದರೆ_ಅಂತ್ಯ
