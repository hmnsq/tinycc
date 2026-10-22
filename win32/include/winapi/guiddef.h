/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् GUID_DEFINED
#परिभाषय GUID_DEFINED
प्रकारनिर्देश संरचना _GUID {
  अचिह्नित दीर्घ Data1;
  अचिह्नित ह्रस्व Data2;
  अचिह्नित ह्रस्व Data3;
  अचिह्नित वर्ण Data4[8 ];
} GUID;
#यदि_अन्तः

#यदि_अपरिभाषितम् UUID_DEFINED
#परिभाषय UUID_DEFINED
प्रकारनिर्देश GUID UUID;
#यदि_अन्तः

#यदि_अपरिभाषितम् FAR
#परिभाषय FAR
#यदि_अन्तः

#यदि_अपरिभाषितम् DECLSPEC_SELECTANY
#परिभाषय DECLSPEC_SELECTANY __declspec(selectany)
#यदि_अन्तः

#यदि_अपरिभाषितम् EXTERN_C
#यदि_परिभाषितम् __cplusplus
#परिभाषय EXTERN_C बाह्य "C"
#अन्यथा
#परिभाषय EXTERN_C बाह्य
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् DEFINE_GUID
#अपरिभाषय DEFINE_GUID
#यदि_अन्तः

#यदि_परिभाषितम् INITGUID
#यदि_परिभाषितम् __cplusplus
#परिभाषय DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ध्रुव GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#अन्यथा
#परिभाषय DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) ध्रुव GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#यदि_अन्तः
#अन्यथा
#परिभाषय DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C ध्रुव GUID name
#यदि_अन्तः

#परिभाषय DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#यदि_अपरिभाषितम् _GUIDDEF_H_
#परिभाषय _GUIDDEF_H_

#यदि_अपरिभाषितम् __LPGUID_DEFINED__
#परिभाषय __LPGUID_DEFINED__
प्रकारनिर्देश GUID *LPGUID;
#यदि_अन्तः

#यदि_अपरिभाषितम् __LPCGUID_DEFINED__
#परिभाषय __LPCGUID_DEFINED__
प्रकारनिर्देश ध्रुव GUID *LPCGUID;
#यदि_अन्तः

#यदि_अपरिभाषितम् __IID_DEFINED__
#परिभाषय __IID_DEFINED__

प्रकारनिर्देश GUID IID;
प्रकारनिर्देश IID *LPIID;
#परिभाषय IID_NULL GUID_NULL
#परिभाषय IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
प्रकारनिर्देश GUID CLSID;
प्रकारनिर्देश CLSID *LPCLSID;
#परिभाषय CLSID_NULL GUID_NULL
#परिभाषय IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
प्रकारनिर्देश GUID FMTID;
प्रकारनिर्देश FMTID *LPFMTID;
#परिभाषय FMTID_NULL GUID_NULL
#परिभाषय IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#यदि_परिभाषितम् __midl_proxy
#परिभाषय __MIDL_CONST
#अन्यथा
#परिभाषय __MIDL_CONST ध्रुव
#यदि_अन्तः

#यदि_अपरिभाषितम् _REFGUID_DEFINED
#परिभाषय _REFGUID_DEFINED
#यदि_परिभाषितम् __cplusplus
#परिभाषय REFGUID ध्रुव GUID &
#अन्यथा
#परिभाषय REFGUID ध्रुव GUID *__MIDL_CONST
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _REFIID_DEFINED
#परिभाषय _REFIID_DEFINED
#यदि_परिभाषितम् __cplusplus
#परिभाषय REFIID ध्रुव IID &
#अन्यथा
#परिभाषय REFIID ध्रुव IID *__MIDL_CONST
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _REFCLSID_DEFINED
#परिभाषय _REFCLSID_DEFINED
#यदि_परिभाषितम् __cplusplus
#परिभाषय REFCLSID ध्रुव IID &
#अन्यथा
#परिभाषय REFCLSID ध्रुव IID *__MIDL_CONST
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _REFFMTID_DEFINED
#परिभाषय _REFFMTID_DEFINED
#यदि_परिभाषितम् __cplusplus
#परिभाषय REFFMTID ध्रुव IID &
#अन्यथा
#परिभाषय REFFMTID ध्रुव IID *__MIDL_CONST
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् _SYS_GUID_OPERATORS_
#परिभाषय _SYS_GUID_OPERATORS_
#अन्तर्भाव <string.h>

#यदि_परिभाषितम् __cplusplus
__inline पूर्णाङ्क InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  प्रत्यागम (((अचिह्नित दीर्घ *) &rguid1)[0]==((अचिह्नित दीर्घ *) &rguid2)[0] && ((अचिह्नित दीर्घ *) &rguid1)[1]==((अचिह्नित दीर्घ *) &rguid2)[1] &&
    ((अचिह्नित दीर्घ *) &rguid1)[2]==((अचिह्नित दीर्घ *) &rguid2)[2] && ((अचिह्नित दीर्घ *) &rguid1)[3]==((अचिह्नित दीर्घ *) &rguid2)[3]);
}
__inline पूर्णाङ्क IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { प्रत्यागम !memcmp(&rguid1,&rguid2,परिमाण(GUID)); }
#अन्यथा
#परिभाषय InlineIsEqualGUID(rguid1,rguid2) (((अचिह्नित दीर्घ *) rguid1)[0]==((अचिह्नित दीर्घ *) rguid2)[0] && ((अचिह्नित दीर्घ *) rguid1)[1]==((अचिह्नित दीर्घ *) rguid2)[1] && ((अचिह्नित दीर्घ *) rguid1)[2]==((अचिह्नित दीर्घ *) rguid2)[2] && ((अचिह्नित दीर्घ *) rguid1)[3]==((अचिह्नित दीर्घ *) rguid2)[3])
#परिभाषय IsEqualGUID(rguid1,rguid2) (!memcmp(rguid1,rguid2,परिमाण(GUID)))
#यदि_अन्तः

#यदि_परिभाषितम् __INLINE_ISEQUAL_GUID
#अपरिभाषय IsEqualGUID
#परिभाषय IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#यदि_अन्तः

#परिभाषय IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#परिभाषय IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#यदि !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#परिभाषय _SYS_GUID_OPERATOR_EQ_
#यदि_परिभाषितम् __cplusplus
__inline पूर्णाङ्क संक्रियकः==(REFGUID guidOne,REFGUID guidOther) { प्रत्यागम IsEqualGUID(guidOne,guidOther); }
__inline पूर्णाङ्क संक्रियकः!=(REFGUID guidOne,REFGUID guidOther) { प्रत्यागम !(guidOne==guidOther); }
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
