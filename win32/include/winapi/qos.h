/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده __QOS_H_
#تعریف_کن __QOS_H_

تعريفنوع ULONG SERVICETYPE;

#تعریف_کن SERVICETYPE_NOTRAFFIC 0x00000000
#تعریف_کن SERVICETYPE_BESTEFFORT 0x00000001
#تعریف_کن SERVICETYPE_CONTROLLEDLOAD 0x00000002
#تعریف_کن SERVICETYPE_GUARANTEED 0x00000003

#تعریف_کن SERVICETYPE_شبکه_UNAVAILABLE 0x00000004
#تعریف_کن SERVICETYPE_GENERAL_INFORMATION 0x00000005
#تعریف_کن SERVICETYPE_NOCHANGE 0x00000006
#تعریف_کن SERVICETYPE_NONCONFORMING 0x00000009
#تعریف_کن SERVICETYPE_شبکه_CONTROL 0x0000000A
#تعریف_کن SERVICETYPE_QUALITATIVE 0x0000000D

#تعریف_کن SERVICE_BESTEFFORT 0x80010000
#تعریف_کن SERVICE_CONTROLLEDLOAD 0x80020000
#تعریف_کن SERVICE_GUARANTEED 0x80040000
#تعریف_کن SERVICE_QUALITATIVE 0x80200000

#تعریف_کن SERVICE_NO_TRAFFIC_CONTROL 0x81000000

#تعریف_کن SERVICE_NO_QOS_SIGNALING 0x40000000

تعريفنوع بنية _flowspec {
  ULONG Token_نرخ;
  ULONG Token_سطل_اندازه;
  ULONG PeakBandwidth;
  ULONG Latency;
  ULONG DelayVariation;
  SERVICETYPE ServiceType;
  ULONG Max_Sdu_اندازه;
  ULONG Minimum_Policed_اندازه;
} FLOWSPEC,*PFLOWSPEC,*LPFLOWSPEC;

#تعریف_کن QOS_NOT_SPECIFIED 0xFFFFFFFF
#تعریف_کن مثبت_INFINITY_نرخ 0xFFFFFFFE

تعريفنوع بنية {
  ULONG ObjectType;
  ULONG Object_درازی;
} QOS_OBJECT_HDR,*LPQOS_OBJECT_HDR;

#تعریف_کن QOS_GENERAL_ID_پایه 2000
#تعریف_کن QOS_OBJECT_انتها_از_LIST (0x00000001 + QOS_GENERAL_ID_پایه)
#تعریف_کن QOS_OBJECT_SD_نما (0x00000002 + QOS_GENERAL_ID_پایه)
#تعریف_کن QOS_OBJECT_SHAPING_نرخ (0x00000003 + QOS_GENERAL_ID_پایه)
#تعریف_کن QOS_OBJECT_DESTADDR (0x00000004 + QOS_GENERAL_ID_پایه)

تعريفنوع بنية QOS_SD_نما {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shape_Discard_نما;
} QOS_SD_نما_2,*LPQOS_SD_نما;

#تعریف_کن TC_NONCONF_BORROW 0
#تعریف_کن TC_NONCONF_SHAPE 1
#تعریف_کن TC_NONCONF_DISCARD 2
#تعریف_کن TC_NONCONF_BORROW_PLUS 3

تعريفنوع بنية QOS_SHAPING_نرخ {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shaping_نرخ;
} QOS_SHAPING_نرخ_2,*LPQOS_SHAPING_نرخ;

#پایان_اگر
