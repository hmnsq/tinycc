/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف __QOS_H_
#تعریف_کرو __QOS_H_

تعريفنوع ULONG SERVICETYPE;

#تعریف_کرو SERVICETYPE_NOTRAFFIC 0x00000000
#تعریف_کرو SERVICETYPE_BESTEFFORT 0x00000001
#تعریف_کرو SERVICETYPE_CONTROLLEDLOAD 0x00000002
#تعریف_کرو SERVICETYPE_GUARANTEED 0x00000003

#تعریف_کرو SERVICETYPE_جال_UNAVAILABLE 0x00000004
#تعریف_کرو SERVICETYPE_GENERAL_INFORMATION 0x00000005
#تعریف_کرو SERVICETYPE_NOCHANGE 0x00000006
#تعریف_کرو SERVICETYPE_NONCONFORMING 0x00000009
#تعریف_کرو SERVICETYPE_جال_CONTROL 0x0000000A
#تعریف_کرو SERVICETYPE_QUALITATIVE 0x0000000D

#تعریف_کرو SERVICE_BESTEFFORT 0x80010000
#تعریف_کرو SERVICE_CONTROLLEDLOAD 0x80020000
#تعریف_کرو SERVICE_GUARANTEED 0x80040000
#تعریف_کرو SERVICE_QUALITATIVE 0x80200000

#تعریف_کرو SERVICE_NO_TRAFFIC_CONTROL 0x81000000

#تعریف_کرو SERVICE_NO_QOS_SIGNALING 0x40000000

تعريفنوع بنية _flowspec {
  ULONG Token_شرح;
  ULONG Token_بالٹی_ناپ;
  ULONG PeakBandwidth;
  ULONG Latency;
  ULONG DelayVariation;
  SERVICETYPE ServiceType;
  ULONG Max_Sdu_ناپ;
  ULONG Minimum_Policed_ناپ;
} FLOWSPEC,*PFLOWSPEC,*LPFLOWSPEC;

#تعریف_کرو QOS_NOT_SPECIFIED 0xFFFFFFFF
#تعریف_کرو مثبت_INFINITY_شرح 0xFFFFFFFE

تعريفنوع بنية {
  ULONG ObjectType;
  ULONG Object_لمائی;
} QOS_OBJECT_HDR,*LPQOS_OBJECT_HDR;

#تعریف_کرو QOS_GENERAL_ID_ادھار 2000
#تعریف_کرو QOS_OBJECT_سرا_دا_LIST (0x00000001 + QOS_GENERAL_ID_ادھار)
#تعریف_کرو QOS_OBJECT_SD_منوال (0x00000002 + QOS_GENERAL_ID_ادھار)
#تعریف_کرو QOS_OBJECT_SHAPING_شرح (0x00000003 + QOS_GENERAL_ID_ادھار)
#تعریف_کرو QOS_OBJECT_DESTADDR (0x00000004 + QOS_GENERAL_ID_ادھار)

تعريفنوع بنية QOS_SD_منوال {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shape_Discard_منوال;
} QOS_SD_منوال_2,*LPQOS_SD_منوال;

#تعریف_کرو TC_NONCONF_BORROW 0
#تعریف_کرو TC_NONCONF_SHAPE 1
#تعریف_کرو TC_NONCONF_DISCARD 2
#تعریف_کرو TC_NONCONF_BORROW_PLUS 3

تعريفنوع بنية QOS_SHAPING_شرح {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shaping_شرح;
} QOS_SHAPING_شرح_2,*LPQOS_SHAPING_شرح;

#جے_انت
