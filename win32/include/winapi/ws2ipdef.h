#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WS2IPDEF_H
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WS2IPDEF_H

#ਜੇ __GNUC__ >=3
#ਹਦਾਇਤ GCC system_ਸਿਰਲੇਖ
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <winsock2.h>

ਬਣਤਰ ip_mreq {
  ਬਣਤਰ ਵਿੱਚ_addr imr_multiaddr;
  ਬਣਤਰ ਵਿੱਚ_addr imr_interface;
};

ਬਣਤਰ ip_mreq_ਸਰੋਤ {
  ਬਣਤਰ ਵਿੱਚ_addr imr_multiaddr;
  ਬਣਤਰ ਵਿੱਚ_addr imr_sourceaddr;
  ਬਣਤਰ ਵਿੱਚ_addr imr_interface;
};

#ਜੇ_ਅੰਤ
