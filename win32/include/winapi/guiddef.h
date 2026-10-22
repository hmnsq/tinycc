/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل GUID_DEFINED
#وصف_ڪريو GUID_DEFINED
تعريفنوع بنية _GUID {
  بنانشان ڊگهو Data1;
  بنانشان ننڍو Data2;
  بنانشان ننڍو Data3;
  بنانشان حرف Data4[8 ];
} GUID;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل UUID_DEFINED
#وصف_ڪريو UUID_DEFINED
تعريفنوع GUID UUID;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل FAR
#وصف_ڪريو FAR
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل DECLSPEC_SELECTANY
#وصف_ڪريو DECLSPEC_SELECTANY __declspec(selectany)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل EXTERN_C
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو EXTERN_C خارجي "C"
#وإلا
#وصف_ڪريو EXTERN_C خارجي
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل DEFINE_GUID
#وصف_رد DEFINE_GUID
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل INITGUID
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#وإلا
#وصف_ڪريو DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#جيڪڏهن_پورو
#وإلا
#وصف_ڪريو DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID name
#جيڪڏهن_پورو

#وصف_ڪريو DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#جيڪڏهن_وصف_نه_ٿيل _GUIDDEF_H_
#وصف_ڪريو _GUIDDEF_H_

#جيڪڏهن_وصف_نه_ٿيل __LPGUID_DEFINED__
#وصف_ڪريو __LPGUID_DEFINED__
تعريفنوع GUID *LPGUID;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __LPCGUID_DEFINED__
#وصف_ڪريو __LPCGUID_DEFINED__
تعريفنوع ثابت GUID *LPCGUID;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل __IID_DEFINED__
#وصف_ڪريو __IID_DEFINED__

تعريفنوع GUID IID;
تعريفنوع IID *LPIID;
#وصف_ڪريو IID_NULL GUID_NULL
#وصف_ڪريو IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
تعريفنوع GUID CLSID;
تعريفنوع CLSID *LPCLSID;
#وصف_ڪريو CLSID_NULL GUID_NULL
#وصف_ڪريو IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
تعريفنوع GUID FMTID;
تعريفنوع FMTID *LPFMTID;
#وصف_ڪريو FMTID_NULL GUID_NULL
#وصف_ڪريو IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#جيڪڏهن_وصف_ٿيل __midl_proxy
#وصف_ڪريو __MIDL_CONST
#وإلا
#وصف_ڪريو __MIDL_CONST ثابت
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _REFGUID_DEFINED
#وصف_ڪريو _REFGUID_DEFINED
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو REFGUID ثابت GUID &
#وإلا
#وصف_ڪريو REFGUID ثابت GUID *__MIDL_CONST
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _REFIID_DEFINED
#وصف_ڪريو _REFIID_DEFINED
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو REFIID ثابت IID &
#وإلا
#وصف_ڪريو REFIID ثابت IID *__MIDL_CONST
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _REFCLSID_DEFINED
#وصف_ڪريو _REFCLSID_DEFINED
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو REFCLSID ثابت IID &
#وإلا
#وصف_ڪريو REFCLSID ثابت IID *__MIDL_CONST
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _REFFMTID_DEFINED
#وصف_ڪريو _REFFMTID_DEFINED
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو REFFMTID ثابت IID &
#وإلا
#وصف_ڪريو REFFMTID ثابت IID *__MIDL_CONST
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _SYS_GUID_OPERATORS_
#وصف_ڪريو _SYS_GUID_OPERATORS_
#ضمن <string.h>

#جيڪڏهن_وصف_ٿيل __cplusplus
__inline صحيح InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  أرجع (((بنانشان ڊگهو *) &rguid1)[0]==((بنانشان ڊگهو *) &rguid2)[0] && ((بنانشان ڊگهو *) &rguid1)[1]==((بنانشان ڊگهو *) &rguid2)[1] &&
    ((بنانشان ڊگهو *) &rguid1)[2]==((بنانشان ڊگهو *) &rguid2)[2] && ((بنانشان ڊگهو *) &rguid1)[3]==((بنانشان ڊگهو *) &rguid2)[3]);
}
__inline صحيح IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { أرجع !memcmp(&rguid1,&rguid2,حجم(GUID)); }
#وإلا
#وصف_ڪريو InlineIsEqualGUID(rguid1,rguid2) (((بنانشان ڊگهو *) rguid1)[0]==((بنانشان ڊگهو *) rguid2)[0] && ((بنانشان ڊگهو *) rguid1)[1]==((بنانشان ڊگهو *) rguid2)[1] && ((بنانشان ڊگهو *) rguid1)[2]==((بنانشان ڊگهو *) rguid2)[2] && ((بنانشان ڊگهو *) rguid1)[3]==((بنانشان ڊگهو *) rguid2)[3])
#وصف_ڪريو IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,حجم(GUID)))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __INLINE_ISEQUAL_GUID
#وصف_رد IsEqualGUID
#وصف_ڪريو IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#جيڪڏهن_پورو

#وصف_ڪريو IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#وصف_ڪريو IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#إذا !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#وصف_ڪريو _SYS_GUID_OPERATOR_EQ_
#جيڪڏهن_وصف_ٿيل __cplusplus
__inline صحيح عامل==(REFGUID guidOne,REFGUID guidOther) { أرجع IsEqualGUID(guidOne,guidOther); }
__inline صحيح عامل!=(REFGUID guidOne,REFGUID guidOther) { أرجع !(guidOne==guidOther); }
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
