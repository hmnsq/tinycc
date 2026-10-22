/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef GUID_DEFINED
#define GUID_DEFINED
تعريفنوع بنية _GUID {
  unsigned long Data1;
  unsigned short Data2;
  unsigned short Data3;
  unsigned حرف Data4[8 ];
} GUID;
#endif

#ifndef UUID_DEFINED
#define UUID_DEFINED
تعريفنوع GUID UUID;
#endif

#ifndef FAR
#define FAR
#endif

#ifndef DECLSPEC_SELECTANY
#define DECLSPEC_SELECTANY __declspec(selectany)
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C خارجي "C"
#وإلا
#define EXTERN_C خارجي
#endif
#endif

#ifdef DEFINE_GUID
#undef DEFINE_GUID
#endif

#ifdef INITGUID
#ifdef __cplusplus
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#وإلا
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ثابت GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#endif
#وإلا
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ثابت GUID name
#endif

#define DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#ifndef _GUIDDEF_H_
#define _GUIDDEF_H_

#ifndef __LPGUID_DEFINED__
#define __LPGUID_DEFINED__
تعريفنوع GUID *LPGUID;
#endif

#ifndef __LPCGUID_DEFINED__
#define __LPCGUID_DEFINED__
تعريفنوع ثابت GUID *LPCGUID;
#endif

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

تعريفنوع GUID IID;
تعريفنوع IID *LPIID;
#define IID_NULL GUID_NULL
#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
تعريفنوع GUID CLSID;
تعريفنوع CLSID *LPCLSID;
#define CLSID_NULL GUID_NULL
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
تعريفنوع GUID FMTID;
تعريفنوع FMTID *LPFMTID;
#define FMTID_NULL GUID_NULL
#define IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#ifdef __midl_proxy
#define __MIDL_CONST
#وإلا
#define __MIDL_CONST ثابت
#endif

#ifndef _REFGUID_DEFINED
#define _REFGUID_DEFINED
#ifdef __cplusplus
#define REFGUID ثابت GUID &
#وإلا
#define REFGUID ثابت GUID *__MIDL_CONST
#endif
#endif

#ifndef _REFIID_DEFINED
#define _REFIID_DEFINED
#ifdef __cplusplus
#define REFIID ثابت IID &
#وإلا
#define REFIID ثابت IID *__MIDL_CONST
#endif
#endif

#ifndef _REFCLSID_DEFINED
#define _REFCLSID_DEFINED
#ifdef __cplusplus
#define REFCLSID ثابت IID &
#وإلا
#define REFCLSID ثابت IID *__MIDL_CONST
#endif
#endif

#ifndef _REFFMTID_DEFINED
#define _REFFMTID_DEFINED
#ifdef __cplusplus
#define REFFMTID ثابت IID &
#وإلا
#define REFFMTID ثابت IID *__MIDL_CONST
#endif
#endif
#endif

#ifndef _SYS_GUID_OPERATORS_
#define _SYS_GUID_OPERATORS_
#ضمن <string.h>

#ifdef __cplusplus
__inline صحيح InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  أرجع (((unsigned long *) &rguid1)[0]==((unsigned long *) &rguid2)[0] && ((unsigned long *) &rguid1)[1]==((unsigned long *) &rguid2)[1] &&
    ((unsigned long *) &rguid1)[2]==((unsigned long *) &rguid2)[2] && ((unsigned long *) &rguid1)[3]==((unsigned long *) &rguid2)[3]);
}
__inline صحيح IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { أرجع !memcmp(&rguid1,&rguid2,حجم(GUID)); }
#وإلا
#define InlineIsEqualGUID(rguid1,rguid2) (((unsigned long *) rguid1)[0]==((unsigned long *) rguid2)[0] && ((unsigned long *) rguid1)[1]==((unsigned long *) rguid2)[1] && ((unsigned long *) rguid1)[2]==((unsigned long *) rguid2)[2] && ((unsigned long *) rguid1)[3]==((unsigned long *) rguid2)[3])
#define IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,حجم(GUID)))
#endif

#ifdef __INLINE_ISEQUAL_GUID
#undef IsEqualGUID
#define IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#endif

#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#إذا !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#define _SYS_GUID_OPERATOR_EQ_
#ifdef __cplusplus
__inline صحيح operator==(REFGUID guidOne,REFGUID guidOther) { أرجع IsEqualGUID(guidOne,guidOther); }
__inline صحيح operator!=(REFGUID guidOne,REFGUID guidOther) { أرجع !(guidOne==guidOther); }
#endif
#endif
#endif
#endif
