/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ GUID_DEFINED
#تعریف_کرو GUID_DEFINED
قسمتعریف ساخت _GUID {
  غیرعلامتی طویل Data1;
  غیرعلامتی مختصر Data2;
  غیرعلامتی مختصر Data3;
  غیرعلامتی حرف Data4[8 ];
} GUID;
#اگر_ختم

#اگر_غیر_تعریف_شدہ UUID_DEFINED
#تعریف_کرو UUID_DEFINED
قسمتعریف GUID UUID;
#اگر_ختم

#اگر_غیر_تعریف_شدہ FAR
#تعریف_کرو FAR
#اگر_ختم

#اگر_غیر_تعریف_شدہ DECLSPEC_SELECTANY
#تعریف_کرو DECLSPEC_SELECTANY __declspec(selectany)
#اگر_ختم

#اگر_غیر_تعریف_شدہ EXTERN_C
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو EXTERN_C خارجی "C"
#ورنہ
#تعریف_کرو EXTERN_C خارجی
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ DEFINE_GUID
#تعریف_منسوخ DEFINE_GUID
#اگر_ختم

#اگر_تعریف_شدہ INITGUID
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#ورنہ
#تعریف_کرو DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#اگر_ختم
#ورنہ
#تعریف_کرو DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID name
#اگر_ختم

#تعریف_کرو DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#اگر_غیر_تعریف_شدہ _GUIDDEF_H_
#تعریف_کرو _GUIDDEF_H_

#اگر_غیر_تعریف_شدہ __LPGUID_DEFINED__
#تعریف_کرو __LPGUID_DEFINED__
قسمتعریف GUID *LPGUID;
#اگر_ختم

#اگر_غیر_تعریف_شدہ __LPCGUID_DEFINED__
#تعریف_کرو __LPCGUID_DEFINED__
قسمتعریف ثابت GUID *LPCGUID;
#اگر_ختم

#اگر_غیر_تعریف_شدہ __IID_DEFINED__
#تعریف_کرو __IID_DEFINED__

قسمتعریف GUID IID;
قسمتعریف IID *LPIID;
#تعریف_کرو IID_NULL GUID_NULL
#تعریف_کرو IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
قسمتعریف GUID CLSID;
قسمتعریف CLSID *LPCLSID;
#تعریف_کرو CLSID_NULL GUID_NULL
#تعریف_کرو IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
قسمتعریف GUID FMTID;
قسمتعریف FMTID *LPFMTID;
#تعریف_کرو FMTID_NULL GUID_NULL
#تعریف_کرو IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#اگر_تعریف_شدہ __midl_proxy
#تعریف_کرو __MIDL_CONST
#ورنہ
#تعریف_کرو __MIDL_CONST ثابت
#اگر_ختم

#اگر_غیر_تعریف_شدہ _REFGUID_DEFINED
#تعریف_کرو _REFGUID_DEFINED
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو REFGUID ثابت GUID &
#ورنہ
#تعریف_کرو REFGUID ثابت GUID *__MIDL_CONST
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _REFIID_DEFINED
#تعریف_کرو _REFIID_DEFINED
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو REFIID ثابت IID &
#ورنہ
#تعریف_کرو REFIID ثابت IID *__MIDL_CONST
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _REFCLSID_DEFINED
#تعریف_کرو _REFCLSID_DEFINED
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو REFCLSID ثابت IID &
#ورنہ
#تعریف_کرو REFCLSID ثابت IID *__MIDL_CONST
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _REFFMTID_DEFINED
#تعریف_کرو _REFFMTID_DEFINED
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو REFFMTID ثابت IID &
#ورنہ
#تعریف_کرو REFFMTID ثابت IID *__MIDL_CONST
#اگر_ختم
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ _SYS_GUID_OPERATORS_
#تعریف_کرو _SYS_GUID_OPERATORS_
#شامل <string.h>

#اگر_تعریف_شدہ __cplusplus
__inline صحیح InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  واپس (((غیرعلامتی طویل *) &rguid1)[0]==((غیرعلامتی طویل *) &rguid2)[0] && ((غیرعلامتی طویل *) &rguid1)[1]==((غیرعلامتی طویل *) &rguid2)[1] &&
    ((غیرعلامتی طویل *) &rguid1)[2]==((غیرعلامتی طویل *) &rguid2)[2] && ((غیرعلامتی طویل *) &rguid1)[3]==((غیرعلامتی طویل *) &rguid2)[3]);
}
__inline صحیح IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { واپس !memcmp(&rguid1,&rguid2,حجم(GUID)); }
#ورنہ
#تعریف_کرو InlineIsEqualGUID(rguid1,rguid2) (((غیرعلامتی طویل *) rguid1)[0]==((غیرعلامتی طویل *) rguid2)[0] && ((غیرعلامتی طویل *) rguid1)[1]==((غیرعلامتی طویل *) rguid2)[1] && ((غیرعلامتی طویل *) rguid1)[2]==((غیرعلامتی طویل *) rguid2)[2] && ((غیرعلامتی طویل *) rguid1)[3]==((غیرعلامتی طویل *) rguid2)[3])
#تعریف_کرو IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,حجم(GUID)))
#اگر_ختم

#اگر_تعریف_شدہ __INLINE_ISEQUAL_GUID
#تعریف_منسوخ IsEqualGUID
#تعریف_کرو IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#اگر_ختم

#تعریف_کرو IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#تعریف_کرو IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#اگر !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#تعریف_کرو _SYS_GUID_OPERATOR_EQ_
#اگر_تعریف_شدہ __cplusplus
__inline صحیح عامل==(REFGUID guidOne,REFGUID guidOther) { واپس IsEqualGUID(guidOne,guidOther); }
__inline صحیح عامل!=(REFGUID guidOne,REFGUID guidOther) { واپس !(guidOne==guidOther); }
#اگر_ختم
#اگر_ختم
#اگر_ختم
#اگر_ختم
