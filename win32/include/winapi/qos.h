/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی __QOS_H_
#تعریف_کړه __QOS_H_

تعريفنوع ULONG SERVICETYPE;

#تعریف_کړه SERVICETYPE_NOTRAFFIC 0x00000000
#تعریف_کړه SERVICETYPE_BESTEFFORT 0x00000001
#تعریف_کړه SERVICETYPE_CONTROLLEDLOAD 0x00000002
#تعریف_کړه SERVICETYPE_GUARANTEED 0x00000003

#تعریف_کړه SERVICETYPE_شبکه_UNAVAILABLE 0x00000004
#تعریف_کړه SERVICETYPE_GENERAL_INFORMATION 0x00000005
#تعریف_کړه SERVICETYPE_NOCHANGE 0x00000006
#تعریف_کړه SERVICETYPE_NONCONFORMING 0x00000009
#تعریف_کړه SERVICETYPE_شبکه_CONTROL 0x0000000A
#تعریف_کړه SERVICETYPE_QUALITATIVE 0x0000000D

#تعریف_کړه SERVICE_BESTEFFORT 0x80010000
#تعریف_کړه SERVICE_CONTROLLEDLOAD 0x80020000
#تعریف_کړه SERVICE_GUARANTEED 0x80040000
#تعریف_کړه SERVICE_QUALITATIVE 0x80200000

#تعریف_کړه SERVICE_NO_TRAFFIC_CONTROL 0x81000000

#تعریف_کړه SERVICE_NO_QOS_SIGNALING 0x40000000

تعريفنوع بنية _flowspec {
  ULONG Token_شرح;
  ULONG Token_لوښی_اندازه;
  ULONG PeakBandwidth;
  ULONG Latency;
  ULONG DelayVariation;
  SERVICETYPE ServiceType;
  ULONG Max_Sdu_اندازه;
  ULONG Minimum_Policed_اندازه;
} FLOWSPEC,*PFLOWSPEC,*LPFLOWSPEC;

#تعریف_کړه QOS_NOT_SPECIFIED 0xFFFFFFFF
#تعریف_کړه مثبت_INFINITY_شرح 0xFFFFFFFE

تعريفنوع بنية {
  ULONG ObjectType;
  ULONG Object_اوږدتیا;
} QOS_OBJECT_HDR,*LPQOS_OBJECT_HDR;

#تعریف_کړه QOS_GENERAL_ID_بنسټ 2000
#تعریف_کړه QOS_OBJECT_پای_ټکی_د_LIST (0x00000001 + QOS_GENERAL_ID_بنسټ)
#تعریف_کړه QOS_OBJECT_SD_ډېرپېښ (0x00000002 + QOS_GENERAL_ID_بنسټ)
#تعریف_کړه QOS_OBJECT_SHAPING_شرح (0x00000003 + QOS_GENERAL_ID_بنسټ)
#تعریف_کړه QOS_OBJECT_DESTADDR (0x00000004 + QOS_GENERAL_ID_بنسټ)

تعريفنوع بنية QOS_SD_ډېرپېښ {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shape_Discard_ډېرپېښ;
} QOS_SD_ډېرپېښ_2,*LPQOS_SD_ډېرپېښ;

#تعریف_کړه TC_NONCONF_BORROW 0
#تعریف_کړه TC_NONCONF_SHAPE 1
#تعریف_کړه TC_NONCONF_DISCARD 2
#تعریف_کړه TC_NONCONF_BORROW_PLUS 3

تعريفنوع بنية QOS_SHAPING_شرح {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shaping_شرح;
} QOS_SHAPING_شرح_2,*LPQOS_SHAPING_شرح;

#د_که_پای
