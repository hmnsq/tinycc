/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef GUID_DEFINED
#define GUID_DEFINED
प्रकारनिर्देश संरचना _GUID {
  अचिन्हित दीर्घ Data1;
  अचिन्हित लघु Data2;
  अचिन्हित लघु Data3;
  अचिन्हित वर्ण Data4[8 ];
} GUID;
#endif

#ifndef UUID_DEFINED
#define UUID_DEFINED
प्रकारनिर्देश GUID UUID;
#endif

#ifndef FAR
#define FAR
#endif

#ifndef DECLSPEC_SELECTANY
#define DECLSPEC_SELECTANY __declspec(selectany)
#endif

#ifndef EXTERN_C
#ifdef __cplusplus
#define EXTERN_C बाह्य "C"
#अन्यथा
#define EXTERN_C बाह्य
#endif
#endif

#ifdef DEFINE_GUID
#undef DEFINE_GUID
#endif

#ifdef INITGUID
#ifdef __cplusplus
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C अचर GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#अन्यथा
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) अचर GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#endif
#अन्यथा
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C अचर GUID name
#endif

#define DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#ifndef _GUIDDEF_H_
#define _GUIDDEF_H_

#ifndef __LPGUID_DEFINED__
#define __LPGUID_DEFINED__
प्रकारनिर्देश GUID *LPGUID;
#endif

#ifndef __LPCGUID_DEFINED__
#define __LPCGUID_DEFINED__
प्रकारनिर्देश अचर GUID *LPCGUID;
#endif

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

प्रकारनिर्देश GUID IID;
प्रकारनिर्देश IID *LPIID;
#define IID_NULL GUID_NULL
#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
प्रकारनिर्देश GUID CLSID;
प्रकारनिर्देश CLSID *LPCLSID;
#define CLSID_NULL GUID_NULL
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
प्रकारनिर्देश GUID FMTID;
प्रकारनिर्देश FMTID *LPFMTID;
#define FMTID_NULL GUID_NULL
#define IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#ifdef __midl_proxy
#define __MIDL_CONST
#अन्यथा
#define __MIDL_CONST अचर
#endif

#ifndef _REFGUID_DEFINED
#define _REFGUID_DEFINED
#ifdef __cplusplus
#define REFGUID अचर GUID &
#अन्यथा
#define REFGUID अचर GUID *__MIDL_CONST
#endif
#endif

#ifndef _REFIID_DEFINED
#define _REFIID_DEFINED
#ifdef __cplusplus
#define REFIID अचर IID &
#अन्यथा
#define REFIID अचर IID *__MIDL_CONST
#endif
#endif

#ifndef _REFCLSID_DEFINED
#define _REFCLSID_DEFINED
#ifdef __cplusplus
#define REFCLSID अचर IID &
#अन्यथा
#define REFCLSID अचर IID *__MIDL_CONST
#endif
#endif

#ifndef _REFFMTID_DEFINED
#define _REFFMTID_DEFINED
#ifdef __cplusplus
#define REFFMTID अचर IID &
#अन्यथा
#define REFFMTID अचर IID *__MIDL_CONST
#endif
#endif
#endif

#ifndef _SYS_GUID_OPERATORS_
#define _SYS_GUID_OPERATORS_
#अन्तर्भाव <string.h>

#ifdef __cplusplus
__inline पूर्णाङ्क InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  फर्काऊ (((अचिन्हित दीर्घ *) &rguid1)[0]==((अचिन्हित दीर्घ *) &rguid2)[0] && ((अचिन्हित दीर्घ *) &rguid1)[1]==((अचिन्हित दीर्घ *) &rguid2)[1] &&
    ((अचिन्हित दीर्घ *) &rguid1)[2]==((अचिन्हित दीर्घ *) &rguid2)[2] && ((अचिन्हित दीर्घ *) &rguid1)[3]==((अचिन्हित दीर्घ *) &rguid2)[3]);
}
__inline पूर्णाङ्क IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { फर्काऊ !स_भेद(&rguid1,&rguid2,परिमाण(GUID)); }
#अन्यथा
#define InlineIsEqualGUID(rguid1,rguid2) (((अचिन्हित दीर्घ *) rguid1)[0]==((अचिन्हित दीर्घ *) rguid2)[0] && ((अचिन्हित दीर्घ *) rguid1)[1]==((अचिन्हित दीर्घ *) rguid2)[1] && ((अचिन्हित दीर्घ *) rguid1)[2]==((अचिन्हित दीर्घ *) rguid2)[2] && ((अचिन्हित दीर्घ *) rguid1)[3]==((अचिन्हित दीर्घ *) rguid2)[3])
#define IsEqualGUID(rguid1,rguid2) (!स_भेद(rguid1,rguid2,परिमाण(GUID)))
#endif

#ifdef __INLINE_ISEQUAL_GUID
#undef IsEqualGUID
#define IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#endif

#define IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#define IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#यदि !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#define _SYS_GUID_OPERATOR_EQ_
#ifdef __cplusplus
__inline पूर्णाङ्क चालक==(REFGUID guidOne,REFGUID guidOther) { फर्काऊ IsEqualGUID(guidOne,guidOther); }
__inline पूर्णाङ्क चालक!=(REFGUID guidOne,REFGUID guidOther) { फर्काऊ !(guidOne==guidOther); }
#endif
#endif
#endif
#endif
