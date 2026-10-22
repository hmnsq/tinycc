/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित GUID_DEFINED
#घोषणा GUID_DEFINED
प्रकार काष्ठा _GUID {
  अचिन्हित दीर्घ Data1;
  अचिन्हित लघु Data2;
  अचिन्हित लघु Data3;
  अचिन्हित अक्षर Data4[8 ];
} GUID;
#पूर्ण_अगर

#अगर_अघोषित UUID_DEFINED
#घोषणा UUID_DEFINED
प्रकार GUID UUID;
#पूर्ण_अगर

#अगर_अघोषित FAR
#घोषणा FAR
#पूर्ण_अगर

#अगर_अघोषित DECLSPEC_SELECTANY
#घोषणा DECLSPEC_SELECTANY __declspec(selectany)
#पूर्ण_अगर

#अगर_अघोषित EXTERN_C
#अगर_घोषित __cplusplus
#घोषणा EXTERN_C बाह्य "C"
#अन्यथा
#घोषणा EXTERN_C बाह्य
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित DEFINE_GUID
#अघोषित DEFINE_GUID
#पूर्ण_अगर

#अगर_घोषित INITGUID
#अगर_घोषित __cplusplus
#घोषणा DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C स्थिर GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#अन्यथा
#घोषणा DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) स्थिर GUID DECLSPEC_SELECTANY name = { l,w1,w2,{ b1,b2,b3,b4,b5,b6,b7,b8 } }
#पूर्ण_अगर
#अन्यथा
#घोषणा DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C स्थिर GUID name
#पूर्ण_अगर

#घोषणा DEFINE_OLEGUID(name,l,w1,w2) DEFINE_GUID(name,l,w1,w2,0xC0,0,0,0,0,0,0,0x46)

#अगर_अघोषित _GUIDDEF_H_
#घोषणा _GUIDDEF_H_

#अगर_अघोषित __LPGUID_DEFINED__
#घोषणा __LPGUID_DEFINED__
प्रकार GUID *LPGUID;
#पूर्ण_अगर

#अगर_अघोषित __LPCGUID_DEFINED__
#घोषणा __LPCGUID_DEFINED__
प्रकार स्थिर GUID *LPCGUID;
#पूर्ण_अगर

#अगर_अघोषित __IID_DEFINED__
#घोषणा __IID_DEFINED__

प्रकार GUID IID;
प्रकार IID *LPIID;
#घोषणा IID_NULL GUID_NULL
#घोषणा IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
प्रकार GUID CLSID;
प्रकार CLSID *LPCLSID;
#घोषणा CLSID_NULL GUID_NULL
#घोषणा IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)
प्रकार GUID FMTID;
प्रकार FMTID *LPFMTID;
#घोषणा FMTID_NULL GUID_NULL
#घोषणा IsEqualFMTID(rfmtid1,rfmtid2) IsEqualGUID(rfmtid1,rfmtid2)

#अगर_घोषित __midl_proxy
#घोषणा __MIDL_CONST
#अन्यथा
#घोषणा __MIDL_CONST स्थिर
#पूर्ण_अगर

#अगर_अघोषित _REFGUID_DEFINED
#घोषणा _REFGUID_DEFINED
#अगर_घोषित __cplusplus
#घोषणा REFGUID स्थिर GUID &
#अन्यथा
#घोषणा REFGUID स्थिर GUID *__MIDL_CONST
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _REFIID_DEFINED
#घोषणा _REFIID_DEFINED
#अगर_घोषित __cplusplus
#घोषणा REFIID स्थिर IID &
#अन्यथा
#घोषणा REFIID स्थिर IID *__MIDL_CONST
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _REFCLSID_DEFINED
#घोषणा _REFCLSID_DEFINED
#अगर_घोषित __cplusplus
#घोषणा REFCLSID स्थिर IID &
#अन्यथा
#घोषणा REFCLSID स्थिर IID *__MIDL_CONST
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _REFFMTID_DEFINED
#घोषणा _REFFMTID_DEFINED
#अगर_घोषित __cplusplus
#घोषणा REFFMTID स्थिर IID &
#अन्यथा
#घोषणा REFFMTID स्थिर IID *__MIDL_CONST
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित _SYS_GUID_OPERATORS_
#घोषणा _SYS_GUID_OPERATORS_
#समावेश <string.h>

#अगर_घोषित __cplusplus
__inline पूर्णांक InlineIsEqualGUID(REFGUID rguid1,REFGUID rguid2) {
  वापस (((अचिन्हित दीर्घ *) &rguid1)[0]==((अचिन्हित दीर्घ *) &rguid2)[0] && ((अचिन्हित दीर्घ *) &rguid1)[1]==((अचिन्हित दीर्घ *) &rguid2)[1] &&
    ((अचिन्हित दीर्घ *) &rguid1)[2]==((अचिन्हित दीर्घ *) &rguid2)[2] && ((अचिन्हित दीर्घ *) &rguid1)[3]==((अचिन्हित दीर्घ *) &rguid2)[3]);
}
__inline पूर्णांक IsEqualGUID(REFGUID rguid1,REFGUID rguid2) { वापस !स_भेद(&rguid1,&rguid2,माप(GUID)); }
#अन्यथा
#घोषणा InlineIsEqualGUID(rguid1,rguid2) (((अचिन्हित दीर्घ *) rguid1)[0]==((अचिन्हित दीर्घ *) rguid2)[0] && ((अचिन्हित दीर्घ *) rguid1)[1]==((अचिन्हित दीर्घ *) rguid2)[1] && ((अचिन्हित दीर्घ *) rguid1)[2]==((अचिन्हित दीर्घ *) rguid2)[2] && ((अचिन्हित दीर्घ *) rguid1)[3]==((अचिन्हित दीर्घ *) rguid2)[3])
#घोषणा IsEqualGUID(rguid1,rguid2) (!स_भेद(rguid1,rguid2,माप(GUID)))
#पूर्ण_अगर

#अगर_घोषित __INLINE_ISEQUAL_GUID
#अघोषित IsEqualGUID
#घोषणा IsEqualGUID(rguid1,rguid2) InlineIsEqualGUID(rguid1,rguid2)
#पूर्ण_अगर

#घोषणा IsEqualIID(riid1,riid2) IsEqualGUID(riid1,riid2)
#घोषणा IsEqualCLSID(rclsid1,rclsid2) IsEqualGUID(rclsid1,rclsid2)

#अगर !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
#घोषणा _SYS_GUID_OPERATOR_EQ_
#अगर_घोषित __cplusplus
__inline पूर्णांक चालक==(REFGUID guidOne,REFGUID guidOther) { वापस IsEqualGUID(guidOne,guidOther); }
__inline पूर्णांक चालक!=(REFGUID guidOne,REFGUID guidOther) { वापस !(guidOne==guidOther); }
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
