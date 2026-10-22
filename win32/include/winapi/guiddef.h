/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef GUID_DEFINED
#define GUID_DEFINED
પ્રકારવ્યાખ્યા સંરચના _GUID {
  unsigned long Data1;
  unsigned short Data2;
  unsigned short Data3;
  unsigned અક્ષર Data4[8 ];
} GUID;
#endif

#ifndef UUID_DEFINED
#define UUID_DEFINED
પ્રકારવ્યાખ્યા GUID UUID;
#endif

#ifndef FAR
#define FAR
#endif

#ifndef DECLSPEC_SELECTANY
#define DECLSPEC_SELECTANY __declspec(selectany)
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C બાહ્ય "C"
#નહીંતર
#define EXTERN_C બાહ્ય
#endif
#endif

#ifdef DEFINE_GUID
#undef DEFINE_GUID
#endif

#ifdef INITGUID
#ifdef __cplusplus
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C અચલ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#નહીંતર
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) અચલ GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#endif
#નહીંતર
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C અચલ GUID name
#endif

#define DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#ifndef _GUIDDEF_H_
#define _GUIDDEF_H_

#ifndef __LPGUID_DEFINED__
#define __LPGUID_DEFINED__
પ્રકારવ્યાખ્યા GUID *LPGUID;
#endif

#ifndef __LPCGUID_DEFINED__
#define __LPCGUID_DEFINED__
પ્રકારવ્યાખ્યા અચલ GUID *LPCGUID;
#endif

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

પ્રકારવ્યાખ્યા GUID IID;
પ્રકારવ્યાખ્યા IID *LPIID;
#define IID_NULL GUID_NULL
#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
પ્રકારવ્યાખ્યા GUID CLSID;
પ્રકારવ્યાખ્યા CLSID *LPCLSID;
#define CLSID_NULL GUID_NULL
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
પ્રકારવ્યાખ્યા GUID FMTID;
પ્રકારવ્યાખ્યા FMTID *LPFMTID;
#define FMTID_NULL GUID_NULL
#define IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#ifdef __midl_proxy
#define __MIDL_CONST
#નહીંતર
#define __MIDL_CONST અચલ
#endif

#ifndef _REFGUID_DEFINED
#define _REFGUID_DEFINED
#ifdef __cplusplus
#define REFGUID અચલ GUID &
#નહીંતર
#define REFGUID અચલ GUID *__MIDL_CONST
#endif
#endif

#ifndef _REFIID_DEFINED
#define _REFIID_DEFINED
#ifdef __cplusplus
#define REFIID અચલ IID &
#નહીંતર
#define REFIID અચલ IID *__MIDL_CONST
#endif
#endif

#ifndef _REFCLSID_DEFINED
#define _REFCLSID_DEFINED
#ifdef __cplusplus
#define REFCLSID અચલ IID &
#નહીંતર
#define REFCLSID અચલ IID *__MIDL_CONST
#endif
#endif

#ifndef _REFFMTID_DEFINED
#define _REFFMTID_DEFINED
#ifdef __cplusplus
#define REFFMTID અચલ IID &
#નહીંતર
#define REFFMTID અચલ IID *__MIDL_CONST
#endif
#endif
#endif

#ifndef _SYS_GUID_OPERATORS_
#define _SYS_GUID_OPERATORS_
#અન્તર્ભાવ <string.h>

#ifdef __cplusplus
__inline પૂર્ણાંક InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  પાછા (((unsigned long *) &rguid1)[0]==((unsigned long *) &rguid2)[0] && ((unsigned long *) &rguid1)[1]==((unsigned long *) &rguid2)[1] &&
    ((unsigned long *) &rguid1)[2]==((unsigned long *) &rguid2)[2] && ((unsigned long *) &rguid1)[3]==((unsigned long *) &rguid2)[3]);
}
__inline પૂર્ણાંક IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { પાછા !memcmp(&rguid1,&rguid2,કદ(GUID)); }
#નહીંતર
#define InlineIsEqualGUID(rguid1,rguid2) (((unsigned long *) rguid1)[0]==((unsigned long *) rguid2)[0] && ((unsigned long *) rguid1)[1]==((unsigned long *) rguid2)[1] && ((unsigned long *) rguid1)[2]==((unsigned long *) rguid2)[2] && ((unsigned long *) rguid1)[3]==((unsigned long *) rguid2)[3])
#define IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,કદ(GUID)))
#endif

#ifdef __INLINE_ISEQUAL_GUID
#undef IsEqualGUID
#define IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#endif

#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#જો !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#define _SYS_GUID_OPERATOR_EQ_
#ifdef __cplusplus
__inline પૂર્ણાંક operator==(REFGUID guidOne,REFGUID guidOther) { પાછા IsEqualGUID(guidOne,guidOther); }
__inline પૂર્ણાંક operator!=(REFGUID guidOne,REFGUID guidOther) { પાછા !(guidOne==guidOther); }
#endif
#endif
#endif
#endif
