/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده GUID_DEFINED
#تعریف_کن GUID_DEFINED
تعريفنوع بنية _GUID {
  بیعلامت دراز Data1;
  بیعلامت کوتاه Data2;
  بیعلامت کوتاه Data3;
  بیعلامت حرف Data4[8 ];
} GUID;
#پایان_اگر

#اگر_تعریف_نشده UUID_DEFINED
#تعریف_کن UUID_DEFINED
تعريفنوع GUID UUID;
#پایان_اگر

#اگر_تعریف_نشده FAR
#تعریف_کن FAR
#پایان_اگر

#اگر_تعریف_نشده DECLSPEC_SELECTANY
#تعریف_کن DECLSPEC_SELECTANY __declspec(selectany)
#پایان_اگر

#اگر_تعریف_نشده EXTERN_C
#اگر_تعریف_شده __cplusplus
#تعریف_کن EXTERN_C خارجي "C"
#وإلا
#تعریف_کن EXTERN_C خارجي
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده DEFINE_GUID
#لغو_تعریف DEFINE_GUID
#پایان_اگر

#اگر_تعریف_شده INITGUID
#اگر_تعریف_شده __cplusplus
#تعریف_کن DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#وإلا
#تعریف_کن DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#پایان_اگر
#وإلا
#تعریف_کن DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID name
#پایان_اگر

#تعریف_کن DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#اگر_تعریف_نشده _GUIDDEF_H_
#تعریف_کن _GUIDDEF_H_

#اگر_تعریف_نشده __LPGUID_DEFINED__
#تعریف_کن __LPGUID_DEFINED__
تعريفنوع GUID *LPGUID;
#پایان_اگر

#اگر_تعریف_نشده __LPCGUID_DEFINED__
#تعریف_کن __LPCGUID_DEFINED__
تعريفنوع ثابت GUID *LPCGUID;
#پایان_اگر

#اگر_تعریف_نشده __IID_DEFINED__
#تعریف_کن __IID_DEFINED__

تعريفنوع GUID IID;
تعريفنوع IID *LPIID;
#تعریف_کن IID_NULL GUID_NULL
#تعریف_کن IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
تعريفنوع GUID CLSID;
تعريفنوع CLSID *LPCLSID;
#تعریف_کن CLSID_NULL GUID_NULL
#تعریف_کن IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
تعريفنوع GUID FMTID;
تعريفنوع FMTID *LPFMTID;
#تعریف_کن FMTID_NULL GUID_NULL
#تعریف_کن IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#اگر_تعریف_شده __midl_proxy
#تعریف_کن __MIDL_CONST
#وإلا
#تعریف_کن __MIDL_CONST ثابت
#پایان_اگر

#اگر_تعریف_نشده _REFGUID_DEFINED
#تعریف_کن _REFGUID_DEFINED
#اگر_تعریف_شده __cplusplus
#تعریف_کن REFGUID ثابت GUID &
#وإلا
#تعریف_کن REFGUID ثابت GUID *__MIDL_CONST
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _REFIID_DEFINED
#تعریف_کن _REFIID_DEFINED
#اگر_تعریف_شده __cplusplus
#تعریف_کن REFIID ثابت IID &
#وإلا
#تعریف_کن REFIID ثابت IID *__MIDL_CONST
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _REFCLSID_DEFINED
#تعریف_کن _REFCLSID_DEFINED
#اگر_تعریف_شده __cplusplus
#تعریف_کن REFCLSID ثابت IID &
#وإلا
#تعریف_کن REFCLSID ثابت IID *__MIDL_CONST
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _REFFMTID_DEFINED
#تعریف_کن _REFFMTID_DEFINED
#اگر_تعریف_شده __cplusplus
#تعریف_کن REFFMTID ثابت IID &
#وإلا
#تعریف_کن REFFMTID ثابت IID *__MIDL_CONST
#پایان_اگر
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده _SYS_GUID_OPERATORS_
#تعریف_کن _SYS_GUID_OPERATORS_
#ضمن <string.h>

#اگر_تعریف_شده __cplusplus
__inline صحيح InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  أرجع (((بیعلامت دراز *) &rguid1)[0]==((بیعلامت دراز *) &rguid2)[0] && ((بیعلامت دراز *) &rguid1)[1]==((بیعلامت دراز *) &rguid2)[1] &&
    ((بیعلامت دراز *) &rguid1)[2]==((بیعلامت دراز *) &rguid2)[2] && ((بیعلامت دراز *) &rguid1)[3]==((بیعلامت دراز *) &rguid2)[3]);
}
__inline صحيح IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { أرجع !memcmp(&rguid1,&rguid2,حجم(GUID)); }
#وإلا
#تعریف_کن InlineIsEqualGUID(rguid1,rguid2) (((بیعلامت دراز *) rguid1)[0]==((بیعلامت دراز *) rguid2)[0] && ((بیعلامت دراز *) rguid1)[1]==((بیعلامت دراز *) rguid2)[1] && ((بیعلامت دراز *) rguid1)[2]==((بیعلامت دراز *) rguid2)[2] && ((بیعلامت دراز *) rguid1)[3]==((بیعلامت دراز *) rguid2)[3])
#تعریف_کن IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,حجم(GUID)))
#پایان_اگر

#اگر_تعریف_شده __INLINE_ISEQUAL_GUID
#لغو_تعریف IsEqualGUID
#تعریف_کن IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#پایان_اگر

#تعریف_کن IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#تعریف_کن IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#إذا !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#تعریف_کن _SYS_GUID_OPERATOR_EQ_
#اگر_تعریف_شده __cplusplus
__inline صحيح عملگر==(REFGUID guidOne,REFGUID guidOther) { أرجع IsEqualGUID(guidOne,guidOther); }
__inline صحيح عملگر!=(REFGUID guidOne,REFGUID guidOther) { أرجع !(guidOne==guidOther); }
#پایان_اگر
#پایان_اگر
#پایان_اگر
#پایان_اگر
