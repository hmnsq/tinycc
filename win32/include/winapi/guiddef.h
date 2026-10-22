/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف GUID_DEFINED
#تعریف_کرو GUID_DEFINED
تعريفنوع بنية _GUID {
  بنانشانی لما Data1;
  بنانشانی چھوٹا Data2;
  بنانشانی چھوٹا Data3;
  بنانشانی حرف Data4[8 ];
} GUID;
#جے_انت

#جے_بنا_تعریف UUID_DEFINED
#تعریف_کرو UUID_DEFINED
تعريفنوع GUID UUID;
#جے_انت

#جے_بنا_تعریف FAR
#تعریف_کرو FAR
#جے_انت

#جے_بنا_تعریف DECLSPEC_SELECTANY
#تعریف_کرو DECLSPEC_SELECTANY __declspec(selectany)
#جے_انت

#جے_بنا_تعریف EXTERN_C
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو EXTERN_C خارجي "C"
#وإلا
#تعریف_کرو EXTERN_C خارجي
#جے_انت
#جے_انت

#جے_تعریف_شدہ DEFINE_GUID
#تعریف_رد DEFINE_GUID
#جے_انت

#جے_تعریف_شدہ INITGUID
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#وإلا
#تعریف_کرو DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#جے_انت
#وإلا
#تعریف_کرو DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID name
#جے_انت

#تعریف_کرو DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#جے_بنا_تعریف _GUIDDEF_H_
#تعریف_کرو _GUIDDEF_H_

#جے_بنا_تعریف __LPGUID_DEFINED__
#تعریف_کرو __LPGUID_DEFINED__
تعريفنوع GUID *LPGUID;
#جے_انت

#جے_بنا_تعریف __LPCGUID_DEFINED__
#تعریف_کرو __LPCGUID_DEFINED__
تعريفنوع ثابت GUID *LPCGUID;
#جے_انت

#جے_بنا_تعریف __IID_DEFINED__
#تعریف_کرو __IID_DEFINED__

تعريفنوع GUID IID;
تعريفنوع IID *LPIID;
#تعریف_کرو IID_NULL GUID_NULL
#تعریف_کرو IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
تعريفنوع GUID CLSID;
تعريفنوع CLSID *LPCLSID;
#تعریف_کرو CLSID_NULL GUID_NULL
#تعریف_کرو IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
تعريفنوع GUID FMTID;
تعريفنوع FMTID *LPFMTID;
#تعریف_کرو FMTID_NULL GUID_NULL
#تعریف_کرو IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#جے_تعریف_شدہ __midl_proxy
#تعریف_کرو __MIDL_CONST
#وإلا
#تعریف_کرو __MIDL_CONST ثابت
#جے_انت

#جے_بنا_تعریف _REFGUID_DEFINED
#تعریف_کرو _REFGUID_DEFINED
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو REFGUID ثابت GUID &
#وإلا
#تعریف_کرو REFGUID ثابت GUID *__MIDL_CONST
#جے_انت
#جے_انت

#جے_بنا_تعریف _REFIID_DEFINED
#تعریف_کرو _REFIID_DEFINED
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو REFIID ثابت IID &
#وإلا
#تعریف_کرو REFIID ثابت IID *__MIDL_CONST
#جے_انت
#جے_انت

#جے_بنا_تعریف _REFCLSID_DEFINED
#تعریف_کرو _REFCLSID_DEFINED
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو REFCLSID ثابت IID &
#وإلا
#تعریف_کرو REFCLSID ثابت IID *__MIDL_CONST
#جے_انت
#جے_انت

#جے_بنا_تعریف _REFFMTID_DEFINED
#تعریف_کرو _REFFMTID_DEFINED
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو REFFMTID ثابت IID &
#وإلا
#تعریف_کرو REFFMTID ثابت IID *__MIDL_CONST
#جے_انت
#جے_انت
#جے_انت

#جے_بنا_تعریف _SYS_GUID_OPERATORS_
#تعریف_کرو _SYS_GUID_OPERATORS_
#ضمن <string.h>

#جے_تعریف_شدہ __cplusplus
__inline صحيح InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  أرجع (((بنانشانی لما *) &rguid1)[0]==((بنانشانی لما *) &rguid2)[0] && ((بنانشانی لما *) &rguid1)[1]==((بنانشانی لما *) &rguid2)[1] &&
    ((بنانشانی لما *) &rguid1)[2]==((بنانشانی لما *) &rguid2)[2] && ((بنانشانی لما *) &rguid1)[3]==((بنانشانی لما *) &rguid2)[3]);
}
__inline صحيح IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { أرجع !memcmp(&rguid1,&rguid2,حجم(GUID)); }
#وإلا
#تعریف_کرو InlineIsEqualGUID(rguid1,rguid2) (((بنانشانی لما *) rguid1)[0]==((بنانشانی لما *) rguid2)[0] && ((بنانشانی لما *) rguid1)[1]==((بنانشانی لما *) rguid2)[1] && ((بنانشانی لما *) rguid1)[2]==((بنانشانی لما *) rguid2)[2] && ((بنانشانی لما *) rguid1)[3]==((بنانشانی لما *) rguid2)[3])
#تعریف_کرو IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,حجم(GUID)))
#جے_انت

#جے_تعریف_شدہ __INLINE_ISEQUAL_GUID
#تعریف_رد IsEqualGUID
#تعریف_کرو IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#جے_انت

#تعریف_کرو IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#تعریف_کرو IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#إذا !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#تعریف_کرو _SYS_GUID_OPERATOR_EQ_
#جے_تعریف_شدہ __cplusplus
__inline صحيح عامل==(REFGUID guidOne,REFGUID guidOther) { أرجع IsEqualGUID(guidOne,guidOther); }
__inline صحيح عامل!=(REFGUID guidOne,REFGUID guidOther) { أرجع !(guidOne==guidOther); }
#جے_انت
#جے_انت
#جے_انت
#جے_انت
