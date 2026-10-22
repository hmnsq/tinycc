/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ GUID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GUID_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _GUID {
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ Data1;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ Data2;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ Data3;
  ਬਿਨਾਨਿਸ਼ਾਨੀ ਅੱਖਰ Data4[8 ];
} GUID;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ UUID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UUID_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ GUID UUID;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ FAR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAR
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ DECLSPEC_SELECTANY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLSPEC_SELECTANY __declspec(selectany)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ EXTERN_C
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXTERN_C ਬਾਹਰੀ "C"
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXTERN_C ਬਾਹਰੀ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ DEFINE_GUID
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ DEFINE_GUID
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ INITGUID
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ਅਚਲ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ਅਚਲ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ਅਚਲ GUID name
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _GUIDDEF_H_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _GUIDDEF_H_

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __LPGUID_DEFINED__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __LPGUID_DEFINED__
ਕਿਸਮਪਰਿਭਾਸ਼ਾ GUID *LPGUID;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __LPCGUID_DEFINED__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __LPCGUID_DEFINED__
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ GUID *LPCGUID;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __IID_DEFINED__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __IID_DEFINED__

ਕਿਸਮਪਰਿਭਾਸ਼ਾ GUID IID;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ IID *LPIID;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IID_NULL GUID_NULL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
ਕਿਸਮਪਰਿਭਾਸ਼ਾ GUID CLSID;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ CLSID *LPCLSID;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLSID_NULL GUID_NULL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
ਕਿਸਮਪਰਿਭਾਸ਼ਾ GUID FMTID;
ਕਿਸਮਪਰਿਭਾਸ਼ਾ FMTID *LPFMTID;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FMTID_NULL GUID_NULL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __midl_proxy
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MIDL_CONST
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __MIDL_CONST ਅਚਲ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _REFGUID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _REFGUID_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFGUID ਅਚਲ GUID &
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFGUID ਅਚਲ GUID *__MIDL_CONST
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _REFIID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _REFIID_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFIID ਅਚਲ IID &
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFIID ਅਚਲ IID *__MIDL_CONST
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _REFCLSID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _REFCLSID_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFCLSID ਅਚਲ IID &
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFCLSID ਅਚਲ IID *__MIDL_CONST
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _REFFMTID_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _REFFMTID_DEFINED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFFMTID ਅਚਲ IID &
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFFMTID ਅਚਲ IID *__MIDL_CONST
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _SYS_GUID_OPERATORS_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SYS_GUID_OPERATORS_
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
__inline ਪੂਰਨ InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  ਵਾਪਸ (((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) &rguid1)[0]==((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) &rguid2)[0] && ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) &rguid1)[1]==((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) &rguid2)[1] &&
    ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) &rguid1)[2]==((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) &rguid2)[2] && ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) &rguid1)[3]==((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) &rguid2)[3]);
}
__inline ਪੂਰਨ IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { ਵਾਪਸ !memcmp(&rguid1,&rguid2,ਆਕਾਰ(GUID)); }
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InlineIsEqualGUID(rguid1,rguid2) (((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) rguid1)[0]==((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) rguid2)[0] && ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) rguid1)[1]==((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) rguid2)[1] && ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) rguid1)[2]==((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) rguid2)[2] && ((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) rguid1)[3]==((ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ *) rguid2)[3])
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,ਆਕਾਰ(GUID)))
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __INLINE_ISEQUAL_GUID
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ IsEqualGUID
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#ਜੇ !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SYS_GUID_OPERATOR_EQ_
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
__inline ਪੂਰਨ ਸੰਚਾਲਕ==(REFGUID guidOne,REFGUID guidOther) { ਵਾਪਸ IsEqualGUID(guidOne,guidOther); }
__inline ਪੂਰਨ ਸੰਚਾਲਕ!=(REFGUID guidOne,REFGUID guidOther) { ਵਾਪਸ !(guidOne==guidOther); }
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
