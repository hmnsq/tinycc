/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर !defined(_BASETYPS_H_)
#घोषणा _BASETYPS_H_

#अगर_घोषित __cplusplus
#घोषणा EXTERN_C बाह्य "C"
#अन्यथा
#घोषणा EXTERN_C बाह्य
#पूर्ण_अगर

#घोषणा STDMETHODCALLTYPE WINAPI
#घोषणा STDMETHODVCALLTYPE __cdecl

#घोषणा STDAPICALLTYPE WINAPI
#घोषणा STDAPIVCALLTYPE __cdecl

#घोषणा STDAPI EXTERN_C HRESULT WINAPI
#घोषणा STDAPI_(type) EXTERN_C type WINAPI

#घोषणा STDMETHODIMP HRESULT WINAPI
#घोषणा STDMETHODIMP_(type) type WINAPI

#घोषणा STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#घोषणा STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#घोषणा STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#घोषणा STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#अगर defined(__cplusplus) && !defined(CINTERFACE)

#घोषणा __STRUCT__ काष्ठा
#घोषणा STDMETHOD(method) भव HRESULT WINAPI method
#घोषणा STDMETHOD_(type,method) भव type WINAPI method
#घोषणा STDMETHODV(method) भव HRESULT STDMETHODVCALLTYPE method
#घोषणा STDMETHODV_(type,method) भव type STDMETHODVCALLTYPE method
#घोषणा PURE = 0
#घोषणा THIS_
#घोषणा THIS व्योम
#घोषणा DECLARE_INTERFACE(iface) __STRUCT__ iface
#घोषणा DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : खुला baseiface
#अन्यथा

#अगर_अघोषित __OBJC__
#घोषणा interface काष्ठा
#पूर्ण_अगर

#घोषणा STDMETHOD(method) HRESULT (WINAPI *method)
#घोषणा STDMETHOD_(type,method) type (WINAPI *method)
#घोषणा STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE *method)
#घोषणा STDMETHODV_(type,method) type (STDMETHODVCALLTYPE *method)

#घोषणा PURE
#घोषणा THIS_ INTERFACE *This,
#घोषणा THIS INTERFACE *This
#अगर_घोषित CONST_VTABLE
#घोषणा DECLARE_INTERFACE(iface) प्रकार काष्ठा iface { \
  स्थिर काष्ठा iface##Vtbl *lpVtbl; } iface; \
  प्रकार स्थिर काष्ठा iface##Vtbl iface##Vtbl; \
  स्थिर काष्ठा iface##Vtbl
#अन्यथा
#घोषणा DECLARE_INTERFACE(iface) प्रकार काष्ठा iface { \
    काष्ठा iface##Vtbl *lpVtbl; \
  } iface; \
  प्रकार काष्ठा iface##Vtbl iface##Vtbl; \
  काष्ठा iface##Vtbl
#पूर्ण_अगर
#घोषणा DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#पूर्ण_अगर

#समावेश <guiddef.h>

#अगर_अघोषित _ERROR_STATUS_T_DEFINED
#घोषणा _ERROR_STATUS_T_DEFINED
प्रकार अचिन्हित दीर्घ error_status_t;
#पूर्ण_अगर

#अगर_अघोषित _WCHAR_T_DEFINED
प्रकार अचिन्हित लघु ब_अक्षर_प्रकार;
#घोषणा _WCHAR_T_DEFINED
#पूर्ण_अगर
#पूर्ण_अगर
