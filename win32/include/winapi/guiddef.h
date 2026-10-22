/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef GUID_DEFINED
#define GUID_DEFINED
প্রকারনির্দেশ সংরচনা _GUID {
  unsigned long Data1;
  unsigned short Data2;
  unsigned short Data3;
  unsigned ৱর্ণ Data4[8 ];
} GUID;
#endif

#ifndef UUID_DEFINED
#define UUID_DEFINED
প্রকারনির্দেশ GUID UUID;
#endif

#ifndef FAR
#define FAR
#endif

#ifndef DECLSPEC_SELECTANY
#define DECLSPEC_SELECTANY __declspec(selectany)
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C বাহ্য "C"
#অন্যথা
#define EXTERN_C বাহ্য
#endif
#endif

#ifdef DEFINE_GUID
#undef DEFINE_GUID
#endif

#ifdef INITGUID
#ifdef __cplusplus
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ধ্রুৱ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#অন্যথা
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ধ্রুৱ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#endif
#অন্যথা
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ধ্রুৱ GUID name
#endif

#define DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#ifndef _GUIDDEF_H_
#define _GUIDDEF_H_

#ifndef __LPGUID_DEFINED__
#define __LPGUID_DEFINED__
প্রকারনির্দেশ GUID *LPGUID;
#endif

#ifndef __LPCGUID_DEFINED__
#define __LPCGUID_DEFINED__
প্রকারনির্দেশ ধ্রুৱ GUID *LPCGUID;
#endif

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

প্রকারনির্দেশ GUID IID;
প্রকারনির্দেশ IID *LPIID;
#define IID_NULL GUID_NULL
#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
প্রকারনির্দেশ GUID CLSID;
প্রকারনির্দেশ CLSID *LPCLSID;
#define CLSID_NULL GUID_NULL
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
প্রকারনির্দেশ GUID FMTID;
প্রকারনির্দেশ FMTID *LPFMTID;
#define FMTID_NULL GUID_NULL
#define IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#ifdef __midl_proxy
#define __MIDL_CONST
#অন্যথা
#define __MIDL_CONST ধ্রুৱ
#endif

#ifndef _REFGUID_DEFINED
#define _REFGUID_DEFINED
#ifdef __cplusplus
#define REFGUID ধ্রুৱ GUID &
#অন্যথা
#define REFGUID ধ্রুৱ GUID *__MIDL_CONST
#endif
#endif

#ifndef _REFIID_DEFINED
#define _REFIID_DEFINED
#ifdef __cplusplus
#define REFIID ধ্রুৱ IID &
#অন্যথা
#define REFIID ধ্রুৱ IID *__MIDL_CONST
#endif
#endif

#ifndef _REFCLSID_DEFINED
#define _REFCLSID_DEFINED
#ifdef __cplusplus
#define REFCLSID ধ্রুৱ IID &
#অন্যথা
#define REFCLSID ধ্রুৱ IID *__MIDL_CONST
#endif
#endif

#ifndef _REFFMTID_DEFINED
#define _REFFMTID_DEFINED
#ifdef __cplusplus
#define REFFMTID ধ্রুৱ IID &
#অন্যথা
#define REFFMTID ধ্রুৱ IID *__MIDL_CONST
#endif
#endif
#endif

#ifndef _SYS_GUID_OPERATORS_
#define _SYS_GUID_OPERATORS_
#অন্তর্ভাৱ <string.h>

#ifdef __cplusplus
__inline পূর্ণাঙ্ক InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  ঘূৰাই (((unsigned long *) &rguid1)[0]==((unsigned long *) &rguid2)[0] && ((unsigned long *) &rguid1)[1]==((unsigned long *) &rguid2)[1] &&
    ((unsigned long *) &rguid1)[2]==((unsigned long *) &rguid2)[2] && ((unsigned long *) &rguid1)[3]==((unsigned long *) &rguid2)[3]);
}
__inline পূর্ণাঙ্ক IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { ঘূৰাই !memcmp(&rguid1,&rguid2,পরিমাণ(GUID)); }
#অন্যথা
#define InlineIsEqualGUID(rguid1,rguid2) (((unsigned long *) rguid1)[0]==((unsigned long *) rguid2)[0] && ((unsigned long *) rguid1)[1]==((unsigned long *) rguid2)[1] && ((unsigned long *) rguid1)[2]==((unsigned long *) rguid2)[2] && ((unsigned long *) rguid1)[3]==((unsigned long *) rguid2)[3])
#define IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,পরিমাণ(GUID)))
#endif

#ifdef __INLINE_ISEQUAL_GUID
#undef IsEqualGUID
#define IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#endif

#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#যদি !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#define _SYS_GUID_OPERATOR_EQ_
#ifdef __cplusplus
__inline পূর্ণাঙ্ক operator==(REFGUID guidOne,REFGUID guidOther) { ঘূৰাই IsEqualGUID(guidOne,guidOther); }
__inline পূর্ণাঙ্ক operator!=(REFGUID guidOne,REFGUID guidOther) { ঘূৰাই !(guidOne==guidOther); }
#endif
#endif
#endif
#endif
