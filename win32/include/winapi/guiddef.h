/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی GUID_DEFINED
#تعریف_کړه GUID_DEFINED
تعريفنوع بنية _GUID {
  بینښه اوږد Data1;
  بینښه لنډ Data2;
  بینښه لنډ Data3;
  بینښه حرف Data4[8 ];
} GUID;
#د_که_پای

#که_نه_تعریف_شوی UUID_DEFINED
#تعریف_کړه UUID_DEFINED
تعريفنوع GUID UUID;
#د_که_پای

#که_نه_تعریف_شوی FAR
#تعریف_کړه FAR
#د_که_پای

#که_نه_تعریف_شوی DECLSPEC_SELECTANY
#تعریف_کړه DECLSPEC_SELECTANY __declspec(selectany)
#د_که_پای

#که_نه_تعریف_شوی EXTERN_C
#که_تعریف_شوی __cplusplus
#تعریف_کړه EXTERN_C خارجي "C"
#وإلا
#تعریف_کړه EXTERN_C خارجي
#د_که_پای
#د_که_پای

#که_تعریف_شوی DEFINE_GUID
#تعریف_لغوه DEFINE_GUID
#د_که_پای

#که_تعریف_شوی INITGUID
#که_تعریف_شوی __cplusplus
#تعریف_کړه DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#وإلا
#تعریف_کړه DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#د_که_پای
#وإلا
#تعریف_کړه DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID name
#د_که_پای

#تعریف_کړه DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#که_نه_تعریف_شوی _GUIDDEF_H_
#تعریف_کړه _GUIDDEF_H_

#که_نه_تعریف_شوی __LPGUID_DEFINED__
#تعریف_کړه __LPGUID_DEFINED__
تعريفنوع GUID *LPGUID;
#د_که_پای

#که_نه_تعریف_شوی __LPCGUID_DEFINED__
#تعریف_کړه __LPCGUID_DEFINED__
تعريفنوع ثابت GUID *LPCGUID;
#د_که_پای

#که_نه_تعریف_شوی __IID_DEFINED__
#تعریف_کړه __IID_DEFINED__

تعريفنوع GUID IID;
تعريفنوع IID *LPIID;
#تعریف_کړه IID_NULL GUID_NULL
#تعریف_کړه IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
تعريفنوع GUID CLSID;
تعريفنوع CLSID *LPCLSID;
#تعریف_کړه CLSID_NULL GUID_NULL
#تعریف_کړه IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
تعريفنوع GUID FMTID;
تعريفنوع FMTID *LPFMTID;
#تعریف_کړه FMTID_NULL GUID_NULL
#تعریف_کړه IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#که_تعریف_شوی __midl_proxy
#تعریف_کړه __MIDL_CONST
#وإلا
#تعریف_کړه __MIDL_CONST ثابت
#د_که_پای

#که_نه_تعریف_شوی _REFGUID_DEFINED
#تعریف_کړه _REFGUID_DEFINED
#که_تعریف_شوی __cplusplus
#تعریف_کړه REFGUID ثابت GUID &
#وإلا
#تعریف_کړه REFGUID ثابت GUID *__MIDL_CONST
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _REFIID_DEFINED
#تعریف_کړه _REFIID_DEFINED
#که_تعریف_شوی __cplusplus
#تعریف_کړه REFIID ثابت IID &
#وإلا
#تعریف_کړه REFIID ثابت IID *__MIDL_CONST
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _REFCLSID_DEFINED
#تعریف_کړه _REFCLSID_DEFINED
#که_تعریف_شوی __cplusplus
#تعریف_کړه REFCLSID ثابت IID &
#وإلا
#تعریف_کړه REFCLSID ثابت IID *__MIDL_CONST
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _REFFMTID_DEFINED
#تعریف_کړه _REFFMTID_DEFINED
#که_تعریف_شوی __cplusplus
#تعریف_کړه REFFMTID ثابت IID &
#وإلا
#تعریف_کړه REFFMTID ثابت IID *__MIDL_CONST
#د_که_پای
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی _SYS_GUID_OPERATORS_
#تعریف_کړه _SYS_GUID_OPERATORS_
#ضمن <string.h>

#که_تعریف_شوی __cplusplus
__inline صحيح InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  أرجع (((بینښه اوږد *) &rguid1)[0]==((بینښه اوږد *) &rguid2)[0] && ((بینښه اوږد *) &rguid1)[1]==((بینښه اوږد *) &rguid2)[1] &&
    ((بینښه اوږد *) &rguid1)[2]==((بینښه اوږد *) &rguid2)[2] && ((بینښه اوږد *) &rguid1)[3]==((بینښه اوږد *) &rguid2)[3]);
}
__inline صحيح IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { أرجع !memcmp(&rguid1,&rguid2,حجم(GUID)); }
#وإلا
#تعریف_کړه InlineIsEqualGUID(rguid1,rguid2) (((بینښه اوږد *) rguid1)[0]==((بینښه اوږد *) rguid2)[0] && ((بینښه اوږد *) rguid1)[1]==((بینښه اوږد *) rguid2)[1] && ((بینښه اوږد *) rguid1)[2]==((بینښه اوږد *) rguid2)[2] && ((بینښه اوږد *) rguid1)[3]==((بینښه اوږد *) rguid2)[3])
#تعریف_کړه IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,حجم(GUID)))
#د_که_پای

#که_تعریف_شوی __INLINE_ISEQUAL_GUID
#تعریف_لغوه IsEqualGUID
#تعریف_کړه IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#د_که_پای

#تعریف_کړه IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#تعریف_کړه IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#إذا !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#تعریف_کړه _SYS_GUID_OPERATOR_EQ_
#که_تعریف_شوی __cplusplus
__inline صحيح چلوونکی==(REFGUID guidOne,REFGUID guidOther) { أرجع IsEqualGUID(guidOne,guidOther); }
__inline صحيح چلوونکی!=(REFGUID guidOne,REFGUID guidOther) { أرجع !(guidOne==guidOther); }
#د_که_پای
#د_که_پای
#د_که_پای
#د_که_پای
