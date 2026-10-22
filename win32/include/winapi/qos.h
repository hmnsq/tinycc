/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే __QOS_H_
#నిర్వచించు __QOS_H_

రకనిర్వచనం ULONG SERVICETYPE;

#నిర్వచించు SERVICETYPE_NOTRAFFIC 0x00000000
#నిర్వచించు SERVICETYPE_BESTEFFORT 0x00000001
#నిర్వచించు SERVICETYPE_CONTROLLEDLOAD 0x00000002
#నిర్వచించు SERVICETYPE_GUARANTEED 0x00000003

#నిర్వచించు SERVICETYPE_జాలం_UNAVAILABLE 0x00000004
#నిర్వచించు SERVICETYPE_GENERAL_INFORMATION 0x00000005
#నిర్వచించు SERVICETYPE_NOCHANGE 0x00000006
#నిర్వచించు SERVICETYPE_NONCONFORMING 0x00000009
#నిర్వచించు SERVICETYPE_జాలం_CONTROL 0x0000000A
#నిర్వచించు SERVICETYPE_QUALITATIVE 0x0000000D

#నిర్వచించు SERVICE_BESTEFFORT 0x80010000
#నిర్వచించు SERVICE_CONTROLLEDLOAD 0x80020000
#నిర్వచించు SERVICE_GUARANTEED 0x80040000
#నిర్వచించు SERVICE_QUALITATIVE 0x80200000

#నిర్వచించు SERVICE_NO_TRAFFIC_CONTROL 0x81000000

#నిర్వచించు SERVICE_NO_QOS_SIGNALING 0x40000000

రకనిర్వచనం నిర్మాణం _flowspec {
  ULONG Token_రేటు;
  ULONG Token_పాత్ర_కొలత;
  ULONG PeakBandwidth;
  ULONG Latency;
  ULONG DelayVariation;
  SERVICETYPE ServiceType;
  ULONG Max_Sdu_కొలత;
  ULONG Minimum_Policed_కొలత;
} FLOWSPEC,*PFLOWSPEC,*LPFLOWSPEC;

#నిర్వచించు QOS_NOT_SPECIFIED 0xFFFFFFFF
#నిర్వచించు ధనాత్మక_INFINITY_రేటు 0xFFFFFFFE

రకనిర్వచనం నిర్మాణం {
  ULONG ObjectType;
  ULONG Object_నిడివి;
} QOS_OBJECT_HDR,*LPQOS_OBJECT_HDR;

#నిర్వచించు QOS_GENERAL_ID_పునాది 2000
#నిర్వచించు QOS_OBJECT_చివర_యొక్క_LIST (0x00000001 + QOS_GENERAL_ID_పునాది)
#నిర్వచించు QOS_OBJECT_SD_బహుళకం (0x00000002 + QOS_GENERAL_ID_పునాది)
#నిర్వచించు QOS_OBJECT_SHAPING_రేటు (0x00000003 + QOS_GENERAL_ID_పునాది)
#నిర్వచించు QOS_OBJECT_DESTADDR (0x00000004 + QOS_GENERAL_ID_పునాది)

రకనిర్వచనం నిర్మాణం QOS_SD_బహుళకం {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shape_Discard_బహుళకం;
} QOS_SD_బహుళకం_2,*LPQOS_SD_బహుళకం;

#నిర్వచించు TC_NONCONF_BORROW 0
#నిర్వచించు TC_NONCONF_SHAPE 1
#నిర్వచించు TC_NONCONF_DISCARD 2
#నిర్వచించు TC_NONCONF_BORROW_PLUS 3

రకనిర్వచనం నిర్మాణం QOS_SHAPING_రేటు {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shaping_రేటు;
} QOS_SHAPING_రేటు_2,*LPQOS_SHAPING_రేటు;

#అయితే_ముగింపు
