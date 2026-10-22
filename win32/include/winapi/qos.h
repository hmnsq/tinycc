/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __QOS_H_
#ವ್ಯಾಖ್ಯಾನಿಸು __QOS_H_

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ULONG SERVICETYPE;

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_NOTRAFFIC 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_BESTEFFORT 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_CONTROLLEDLOAD 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_GUARANTEED 0x00000003

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_ಜಾಲ_UNAVAILABLE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_GENERAL_INFORMATION 0x00000005
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_NOCHANGE 0x00000006
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_NONCONFORMING 0x00000009
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_ಜಾಲ_CONTROL 0x0000000A
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICETYPE_QUALITATIVE 0x0000000D

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_BESTEFFORT 0x80010000
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_CONTROLLEDLOAD 0x80020000
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_GUARANTEED 0x80040000
#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_QUALITATIVE 0x80200000

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_NO_TRAFFIC_CONTROL 0x81000000

#ವ್ಯಾಖ್ಯಾನಿಸು SERVICE_NO_QOS_SIGNALING 0x40000000

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _flowspec {
  ULONG Token_ದರ;
  ULONG Token_ಪಾತ್ರೆ_ಗಾತ್ರ;
  ULONG PeakBandwidth;
  ULONG Latency;
  ULONG DelayVariation;
  SERVICETYPE ServiceType;
  ULONG Max_Sdu_ಗಾತ್ರ;
  ULONG Minimum_Policed_ಗಾತ್ರ;
} FLOWSPEC,*PFLOWSPEC,*LPFLOWSPEC;

#ವ್ಯಾಖ್ಯಾನಿಸು QOS_NOT_SPECIFIED 0xFFFFFFFF
#ವ್ಯಾಖ್ಯಾನಿಸು ಧನಾತ್ಮಕ_INFINITY_ದರ 0xFFFFFFFE

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
  ULONG ObjectType;
  ULONG Object_ಉದ್ದಳತೆ;
} QOS_OBJECT_HDR,*LPQOS_OBJECT_HDR;

#ವ್ಯಾಖ್ಯಾನಿಸು QOS_GENERAL_ID_ತಳ 2000
#ವ್ಯಾಖ್ಯಾನಿಸು QOS_OBJECT_ಕೊನೆ_ದ_LIST (0x00000001 + QOS_GENERAL_ID_ತಳ)
#ವ್ಯಾಖ್ಯಾನಿಸು QOS_OBJECT_SD_ಬಹುಲಕ (0x00000002 + QOS_GENERAL_ID_ತಳ)
#ವ್ಯಾಖ್ಯಾನಿಸು QOS_OBJECT_SHAPING_ದರ (0x00000003 + QOS_GENERAL_ID_ತಳ)
#ವ್ಯಾಖ್ಯಾನಿಸು QOS_OBJECT_DESTADDR (0x00000004 + QOS_GENERAL_ID_ತಳ)

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ QOS_SD_ಬಹುಲಕ {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shape_Discard_ಬಹುಲಕ;
} QOS_SD_ಬಹುಲಕ_2,*LPQOS_SD_ಬಹುಲಕ;

#ವ್ಯಾಖ್ಯಾನಿಸು TC_NONCONF_BORROW 0
#ವ್ಯಾಖ್ಯಾನಿಸು TC_NONCONF_SHAPE 1
#ವ್ಯಾಖ್ಯಾನಿಸು TC_NONCONF_DISCARD 2
#ವ್ಯಾಖ್ಯಾನಿಸು TC_NONCONF_BORROW_PLUS 3

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ QOS_SHAPING_ದರ {
  QOS_OBJECT_HDR ObjectHdr;
  ULONG Shaping_ದರ;
} QOS_SHAPING_ದರ_2,*LPQOS_SHAPING_ದರ;

#ಆದರೆ_ಅಂತ್ಯ
