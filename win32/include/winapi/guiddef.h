/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ GUID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು GUID_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _GUID {
  ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ Data1;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ Data2;
  ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ Data3;
  ಚಿಹ್ನೆರಹಿತ ಅಕ್ಷರ Data4[8 ];
} GUID;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ UUID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು UUID_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ GUID UUID;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ FAR
#ವ್ಯಾಖ್ಯಾನಿಸು FAR
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ DECLSPEC_SELECTANY
#ವ್ಯಾಖ್ಯಾನಿಸು DECLSPEC_SELECTANY __declspec(selectany)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ EXTERN_C
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು EXTERN_C ಬಾಹ್ಯ "C"
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು EXTERN_C ಬಾಹ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ DEFINE_GUID
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು DEFINE_GUID
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ INITGUID
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ಸ್ಥಿರಾಂಕ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ಸ್ಥಿರಾಂಕ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ಸ್ಥಿರಾಂಕ GUID name
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _GUIDDEF_H_
#ವ್ಯಾಖ್ಯಾನಿಸು _GUIDDEF_H_

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __LPGUID_DEFINED__
#ವ್ಯಾಖ್ಯಾನಿಸು __LPGUID_DEFINED__
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ GUID *LPGUID;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __LPCGUID_DEFINED__
#ವ್ಯಾಖ್ಯಾನಿಸು __LPCGUID_DEFINED__
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ GUID *LPCGUID;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __IID_DEFINED__
#ವ್ಯಾಖ್ಯಾನಿಸು __IID_DEFINED__

ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ GUID IID;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ IID *LPIID;
#ವ್ಯಾಖ್ಯಾನಿಸು IID_NULL GUID_NULL
#ವ್ಯಾಖ್ಯಾನಿಸು IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ GUID CLSID;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CLSID *LPCLSID;
#ವ್ಯಾಖ್ಯಾನಿಸು CLSID_NULL GUID_NULL
#ವ್ಯಾಖ್ಯಾನಿಸು IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ GUID FMTID;
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ FMTID *LPFMTID;
#ವ್ಯಾಖ್ಯಾನಿಸು FMTID_NULL GUID_NULL
#ವ್ಯಾಖ್ಯಾನಿಸು IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __midl_proxy
#ವ್ಯಾಖ್ಯಾನಿಸು __MIDL_CONST
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು __MIDL_CONST ಸ್ಥಿರಾಂಕ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _REFGUID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _REFGUID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು REFGUID ಸ್ಥಿರಾಂಕ GUID &
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು REFGUID ಸ್ಥಿರಾಂಕ GUID *__MIDL_CONST
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _REFIID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _REFIID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು REFIID ಸ್ಥಿರಾಂಕ IID &
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು REFIID ಸ್ಥಿರಾಂಕ IID *__MIDL_CONST
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _REFCLSID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _REFCLSID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು REFCLSID ಸ್ಥಿರಾಂಕ IID &
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು REFCLSID ಸ್ಥಿರಾಂಕ IID *__MIDL_CONST
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _REFFMTID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _REFFMTID_DEFINED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು REFFMTID ಸ್ಥಿರಾಂಕ IID &
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು REFFMTID ಸ್ಥಿರಾಂಕ IID *__MIDL_CONST
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _SYS_GUID_OPERATORS_
#ವ್ಯಾಖ್ಯಾನಿಸು _SYS_GUID_OPERATORS_
#ಅನ್ತರ್ಭಾವ <string.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
__inline ಪೂರ್ಣಾಂಕ InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  ಹಿಂತಿರುಗಿ (((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) &rguid1)[0]==((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) &rguid2)[0] && ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) &rguid1)[1]==((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) &rguid2)[1] &&
    ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) &rguid1)[2]==((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) &rguid2)[2] && ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) &rguid1)[3]==((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) &rguid2)[3]);
}
__inline ಪೂರ್ಣಾಂಕ IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { ಹಿಂತಿರುಗಿ !memcmp(&rguid1,&rguid2,ಗಾತ್ರ(GUID)); }
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು InlineIsEqualGUID(rguid1,rguid2) (((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) rguid1)[0]==((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) rguid2)[0] && ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) rguid1)[1]==((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) rguid2)[1] && ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) rguid1)[2]==((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) rguid2)[2] && ((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) rguid1)[3]==((ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ *) rguid2)[3])
#ವ್ಯಾಖ್ಯಾನಿಸು IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,ಗಾತ್ರ(GUID)))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __INLINE_ISEQUAL_GUID
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು IsEqualGUID
#ವ್ಯಾಖ್ಯಾನಿಸು IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#ವ್ಯಾಖ್ಯಾನಿಸು IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#ಆದರೆ !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#ವ್ಯಾಖ್ಯಾನಿಸು _SYS_GUID_OPERATOR_EQ_
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
__inline ಪೂರ್ಣಾಂಕ ಕ್ರಿಯಾಕಾರಕ==(REFGUID guidOne,REFGUID guidOther) { ಹಿಂತಿರುಗಿ IsEqualGUID(guidOne,guidOther); }
__inline ಪೂರ್ಣಾಂಕ ಕ್ರಿಯಾಕಾರಕ!=(REFGUID guidOne,REFGUID guidOther) { ಹಿಂತಿರುಗಿ !(guidOne==guidOther); }
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
