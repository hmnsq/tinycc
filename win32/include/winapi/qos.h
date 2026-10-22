/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل __QOS_H_
#وصف_ڪريو __QOS_H_

تعريفنوع ULONG SERVICETYPE;

#وصف_ڪريو SERVICETYPE_NOTRAFFIC 0x00000000
#وصف_ڪريو SERVICETYPE_BESTEFFORT 0x00000001
#وصف_ڪريو SERVICETYPE_CONTROLLEDLOAD 0x00000002
#وصف_ڪريو SERVICETYPE_GUARANTEED 0x00000003

#وصف_ڪريو SERVICETYPE_ڄار_UNAVAILABLE 0x00000004
#وصف_ڪريو SERVICETYPE_GENERAL_INFORMATION 0x00000005
#وصف_ڪريو SERVICETYPE_NOCHANGE 0x00000006
#وصف_ڪريو SERVICETYPE_NONCONFORMING 0x00000009
#وصف_ڪريو SERVICETYPE_ڄار_CONTROL 0x0000000A
#وصف_ڪريو SERVICETYPE_QUALITATIVE 0x0000000D

#وصف_ڪريو SERVICE_BESTEFFORT 0x80010000
#وصف_ڪريو SERVICE_CONTROLLEDLOAD 0x80020000
#وصف_ڪريو SERVICE_GUARANTEED 0x80040000
#وصف_ڪريو SERVICE_QUALITATIVE 0x80200000

#وصف_ڪريو SERVICE_NO_TRAFFIC_CONTROL 0x81000000

#وصف_ڪريو SERVICE_NO_QOS_SIGNALING 0x40000000

تعريفنوع بنية _flowspec {
  ULONG Token_شرح;
  ULONG Token_ٻالٽي_سائيز;
  ULONG PeakBandwidth;
  ULONG Latency;
  ULONG DelayVariation;
  SERVICETYPE ServiceType;
  ULONG Max_Sdu_سائيز;
  ULONG Minimum_Policed_سائيز;
} FLOWSPEC,*PFLOWSPEC,*LPFLOWSPEC;

#وصف_ڪريو QOS_NOT_SPECIFIED 0xFFFFFFFF
#وصف_ڪريو مثبت_INFINITY_شرح 0xFFFFFFFE

تعريفنوع بنية {
  ULONG ObjectType;
  ULONG Object_ڊيگهائي;
} QOS_OBJECT_HDR,*LPQOS_OBJECT_HDR;

#وصف_ڪريو QOS_GENERAL_ID_بنياد 2000
#وصف_ڪريو QOS_OBJECT_پڇاڙي_جو_LIST (0x00000001 + QOS_GENERAL_ID_بنياد)
#وصف_ڪريو QOS_OBJECT_SD_گهڻائي (0x00000002 + QOS_GENERAL_ID_بنياد)
#وصف_ڪريو QOS_OBJECT_SHAPING_شرح (0x00000003 + QOS_GENERAL_ID_بنياد)
#وصف_ڪريو QOS_OBJECT_DESTADDR (0x00000004 + QOS_GENERAL_ID_بنياد)

تعريفنوع بنية QOS_SD_گهڻائي {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shape_Discard_گهڻائي;
} QOS_SD_گهڻائي_2,*LPQOS_SD_گهڻائي;

#وصف_ڪريو TC_NONCONF_BORROW 0
#وصف_ڪريو TC_NONCONF_SHAPE 1
#وصف_ڪريو TC_NONCONF_DISCARD 2
#وصف_ڪريو TC_NONCONF_BORROW_PLUS 3

تعريفنوع بنية QOS_SHAPING_شرح {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shaping_شرح;
} QOS_SHAPING_شرح_2,*LPQOS_SHAPING_شرح;

#جيڪڏهن_پورو
