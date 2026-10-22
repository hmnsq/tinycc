#अगर_अघोषित _WS2IPDEF_H
#घोषणा _WS2IPDEF_H

#अगर __GNUC__ >=3
#आशय GCC system_header
#पूर्ण_अगर

#समावेश <winsock2.h>

काष्ठा ip_mreq {
  काष्ठा in_addr imr_multiaddr;
  काष्ठा in_addr imr_interface;
};

काष्ठा ip_mreq_source {
  काष्ठा in_addr imr_multiaddr;
  काष्ठा in_addr imr_sourceaddr;
  काष्ठा in_addr imr_interface;
};

#पूर्ण_अगर
