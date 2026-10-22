/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् __QOS_H_
#परिभाषय __QOS_H_

प्रकारनिर्देश ULONG SERVICETYPE;

#परिभाषय SERVICETYPE_NOTRAFFIC 0x00000000
#परिभाषय SERVICETYPE_BESTEFFORT 0x00000001
#परिभाषय SERVICETYPE_CONTROLLEDLOAD 0x00000002
#परिभाषय SERVICETYPE_GUARANTEED 0x00000003

#परिभाषय SERVICETYPE_जालम्_UNAVAILABLE 0x00000004
#परिभाषय SERVICETYPE_GENERAL_INFORMATION 0x00000005
#परिभाषय SERVICETYPE_NOCHANGE 0x00000006
#परिभाषय SERVICETYPE_NONCONFORMING 0x00000009
#परिभाषय SERVICETYPE_जालम्_CONTROL 0x0000000A
#परिभाषय SERVICETYPE_QUALITATIVE 0x0000000D

#परिभाषय SERVICE_BESTEFFORT 0x80010000
#परिभाषय SERVICE_CONTROLLEDLOAD 0x80020000
#परिभाषय SERVICE_GUARANTEED 0x80040000
#परिभाषय SERVICE_QUALITATIVE 0x80200000

#परिभाषय SERVICE_NO_TRAFFIC_CONTROL 0x81000000

#परिभाषय SERVICE_NO_QOS_SIGNALING 0x40000000

प्रकारनिर्देश संरचना _flowspec {
  ULONG Token_दरः;
  ULONG Token_Bucket_आकार;
  ULONG PeakBandwidth;
  ULONG Latency;
  ULONG DelayVariation;
  SERVICETYPE ServiceType;
  ULONG Max_Sdu_आकार;
  ULONG Minimum_Policed_आकार;
} FLOWSPEC,*PFLOWSPEC,*LPFLOWSPEC;

#परिभाषय QOS_NOT_SPECIFIED 0xFFFFFFFF
#परिभाषय धनात्मकम्_INFINITY_दरः 0xFFFFFFFE

प्रकारनिर्देश संरचना {
  ULONG ObjectType;
  ULONG Object_दीर्घता;
} QOS_OBJECT_HDR,*LPQOS_OBJECT_HDR;

#परिभाषय QOS_GENERAL_ID_आधारः 2000
#परिभाषय QOS_OBJECT_अन्तः_सम्बन्धि_LIST (0x00000001 + QOS_GENERAL_ID_आधारः)
#परिभाषय QOS_OBJECT_SD_बहुलकम् (0x00000002 + QOS_GENERAL_ID_आधारः)
#परिभाषय QOS_OBJECT_SHAPING_दरः (0x00000003 + QOS_GENERAL_ID_आधारः)
#परिभाषय QOS_OBJECT_DESTADDR (0x00000004 + QOS_GENERAL_ID_आधारः)

प्रकारनिर्देश संरचना QOS_SD_बहुलकम् {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shape_Discard_बहुलकम्;
} QOS_SD_बहुलकम्_2,*LPQOS_SD_बहुलकम्;

#परिभाषय TC_NONCONF_BORROW 0
#परिभाषय TC_NONCONF_SHAPE 1
#परिभाषय TC_NONCONF_DISCARD 2
#परिभाषय TC_NONCONF_BORROW_PLUS 3

प्रकारनिर्देश संरचना QOS_SHAPING_दरः {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shaping_दरः;
} QOS_SHAPING_दरः_2,*LPQOS_SHAPING_दरः;

#यदि_अन्तः
