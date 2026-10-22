/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef GUID_DEFINED
#define GUID_DEFINED
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _GUID {
  unsigned long Data1;
  unsigned short Data2;
  unsigned short Data3;
  unsigned ଅକ୍ଷର Data4[8 ];
} GUID;
#endif

#ifndef UUID_DEFINED
#define UUID_DEFINED
ପ୍ରକାରବ୍ୟାଖ୍ୟା GUID UUID;
#endif

#ifndef FAR
#define FAR
#endif

#ifndef DECLSPEC_SELECTANY
#define DECLSPEC_SELECTANY __declspec(selectany)
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C ବାହ୍ୟ "C"
#ଅନ୍ୟଥା
#define EXTERN_C ବାହ୍ୟ
#endif
#endif

#ifdef DEFINE_GUID
#undef DEFINE_GUID
#endif

#ifdef INITGUID
#ifdef __cplusplus
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ଅଚଳ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#ଅନ୍ୟଥା
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ଅଚଳ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#endif
#ଅନ୍ୟଥା
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ଅଚଳ GUID name
#endif

#define DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#ifndef _GUIDDEF_H_
#define _GUIDDEF_H_

#ifndef __LPGUID_DEFINED__
#define __LPGUID_DEFINED__
ପ୍ରକାରବ୍ୟାଖ୍ୟା GUID *LPGUID;
#endif

#ifndef __LPCGUID_DEFINED__
#define __LPCGUID_DEFINED__
ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅଚଳ GUID *LPCGUID;
#endif

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

ପ୍ରକାରବ୍ୟାଖ୍ୟା GUID IID;
ପ୍ରକାରବ୍ୟାଖ୍ୟା IID *LPIID;
#define IID_NULL GUID_NULL
#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
ପ୍ରକାରବ୍ୟାଖ୍ୟା GUID CLSID;
ପ୍ରକାରବ୍ୟାଖ୍ୟା CLSID *LPCLSID;
#define CLSID_NULL GUID_NULL
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
ପ୍ରକାରବ୍ୟାଖ୍ୟା GUID FMTID;
ପ୍ରକାରବ୍ୟାଖ୍ୟା FMTID *LPFMTID;
#define FMTID_NULL GUID_NULL
#define IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#ifdef __midl_proxy
#define __MIDL_CONST
#ଅନ୍ୟଥା
#define __MIDL_CONST ଅଚଳ
#endif

#ifndef _REFGUID_DEFINED
#define _REFGUID_DEFINED
#ifdef __cplusplus
#define REFGUID ଅଚଳ GUID &
#ଅନ୍ୟଥା
#define REFGUID ଅଚଳ GUID *__MIDL_CONST
#endif
#endif

#ifndef _REFIID_DEFINED
#define _REFIID_DEFINED
#ifdef __cplusplus
#define REFIID ଅଚଳ IID &
#ଅନ୍ୟଥା
#define REFIID ଅଚଳ IID *__MIDL_CONST
#endif
#endif

#ifndef _REFCLSID_DEFINED
#define _REFCLSID_DEFINED
#ifdef __cplusplus
#define REFCLSID ଅଚଳ IID &
#ଅନ୍ୟଥା
#define REFCLSID ଅଚଳ IID *__MIDL_CONST
#endif
#endif

#ifndef _REFFMTID_DEFINED
#define _REFFMTID_DEFINED
#ifdef __cplusplus
#define REFFMTID ଅଚଳ IID &
#ଅନ୍ୟଥା
#define REFFMTID ଅଚଳ IID *__MIDL_CONST
#endif
#endif
#endif

#ifndef _SYS_GUID_OPERATORS_
#define _SYS_GUID_OPERATORS_
#ଅନ୍ତର୍ଭାଵ <string.h>

#ifdef __cplusplus
__inline ପୂର୍ଣ୍ଣସଂଖ୍ୟା InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  ଫେରନ୍ତୁ (((unsigned long *) &rguid1)[0]==((unsigned long *) &rguid2)[0] && ((unsigned long *) &rguid1)[1]==((unsigned long *) &rguid2)[1] &&
    ((unsigned long *) &rguid1)[2]==((unsigned long *) &rguid2)[2] && ((unsigned long *) &rguid1)[3]==((unsigned long *) &rguid2)[3]);
}
__inline ପୂର୍ଣ୍ଣସଂଖ୍ୟା IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { ଫେରନ୍ତୁ !memcmp(&rguid1,&rguid2,ଆକାର(GUID)); }
#ଅନ୍ୟଥା
#define InlineIsEqualGUID(rguid1,rguid2) (((unsigned long *) rguid1)[0]==((unsigned long *) rguid2)[0] && ((unsigned long *) rguid1)[1]==((unsigned long *) rguid2)[1] && ((unsigned long *) rguid1)[2]==((unsigned long *) rguid2)[2] && ((unsigned long *) rguid1)[3]==((unsigned long *) rguid2)[3])
#define IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,ଆକାର(GUID)))
#endif

#ifdef __INLINE_ISEQUAL_GUID
#undef IsEqualGUID
#define IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#endif

#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#ଯଦି !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#define _SYS_GUID_OPERATOR_EQ_
#ifdef __cplusplus
__inline ପୂର୍ଣ୍ଣସଂଖ୍ୟା operator==(REFGUID guidOne,REFGUID guidOther) { ଫେରନ୍ତୁ IsEqualGUID(guidOne,guidOther); }
__inline ପୂର୍ଣ୍ଣସଂଖ୍ୟା operator!=(REFGUID guidOne,REFGUID guidOther) { ଫେରନ୍ତୁ !(guidOne==guidOther); }
#endif
#endif
#endif
#endif
