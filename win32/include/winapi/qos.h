/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __QOS_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __QOS_H_

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ULONG SERVICETYPE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_NOTRAFFIC 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_BESTEFFORT 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_CONTROLLEDLOAD 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_GUARANTEED 0x00000003

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_ਜਾਲ_UNAVAILABLE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_GENERAL_INFORMATION 0x00000005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_NOCHANGE 0x00000006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_NONCONFORMING 0x00000009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_ਜਾਲ_CONTROL 0x0000000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICETYPE_QUALITATIVE 0x0000000D

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_BESTEFFORT 0x80010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_CONTROLLEDLOAD 0x80020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_GUARANTEED 0x80040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_QUALITATIVE 0x80200000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_NO_TRAFFIC_CONTROL 0x81000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERVICE_NO_QOS_SIGNALING 0x40000000

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _flowspec {
  ULONG Token_ਦਰ;
  ULONG Token_ਬਾਲਟੀ_ਮਾਪ;
  ULONG PeakBandwidth;
  ULONG Latency;
  ULONG DelayVariation;
  SERVICETYPE ServiceType;
  ULONG Max_Sdu_ਮਾਪ;
  ULONG Minimum_Policed_ਮਾਪ;
} FLOWSPEC,*PFLOWSPEC,*LPFLOWSPEC;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QOS_NOT_SPECIFIED 0xFFFFFFFF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਕਾਰਾਤਮਕ_INFINITY_ਦਰ 0xFFFFFFFE

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
  ULONG ObjectType;
  ULONG Object_ਲੰਮਾਈ;
} QOS_OBJECT_HDR,*LPQOS_OBJECT_HDR;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QOS_GENERAL_ID_ਅਧਾਰ 2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QOS_OBJECT_ਸਿਰਾ_ਦਾ_LIST (0x00000001 + QOS_GENERAL_ID_ਅਧਾਰ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QOS_OBJECT_SD_ਬਹੁਲਕ (0x00000002 + QOS_GENERAL_ID_ਅਧਾਰ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QOS_OBJECT_SHAPING_ਦਰ (0x00000003 + QOS_GENERAL_ID_ਅਧਾਰ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QOS_OBJECT_DESTADDR (0x00000004 + QOS_GENERAL_ID_ਅਧਾਰ)

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ QOS_SD_ਬਹੁਲਕ {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shape_Discard_ਬਹੁਲਕ;
} QOS_SD_ਬਹੁਲਕ_2,*LPQOS_SD_ਬਹੁਲਕ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_NONCONF_BORROW 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_NONCONF_SHAPE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_NONCONF_DISCARD 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_NONCONF_BORROW_PLUS 3

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ QOS_SHAPING_ਦਰ {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shaping_ਦਰ;
} QOS_SHAPING_ਦਰ_2,*LPQOS_SHAPING_ਦਰ;

#ਜੇ_ਅੰਤ
