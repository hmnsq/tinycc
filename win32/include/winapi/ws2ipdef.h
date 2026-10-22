#నిర్వచితం_కాకపోతే _WS2IPDEF_H
#నిర్వచించు _WS2IPDEF_H

#ఒకవేళ __GNUC__ >=3
#సూచన GCC system_శీర్షిక
#అయితే_ముగింపు

#అన్తర్భావ <winsock2.h>

నిర్మాణం ip_mreq {
  నిర్మాణం లోపల_addr imr_multiaddr;
  నిర్మాణం లోపల_addr imr_interface;
};

నిర్మాణం ip_mreq_ఆధారం {
  నిర్మాణం లోపల_addr imr_multiaddr;
  నిర్మాణం లోపల_addr imr_sourceaddr;
  నిర్మాణం లోపల_addr imr_interface;
};

#అయితే_ముగింపు
