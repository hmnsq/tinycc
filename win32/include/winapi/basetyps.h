/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#إذا !defined(_BASETYPS_H_)
#تعریف_کړه _BASETYPS_H_

#که_تعریف_شوی __cplusplus
#تعریف_کړه EXTERN_C خارجي "C"
#وإلا
#تعریف_کړه EXTERN_C خارجي
#د_که_پای

#تعریف_کړه STDMETHODCALLTYPE WINAPI
#تعریف_کړه STDMETHODVCALLTYPE __cdecl

#تعریف_کړه STDAPICALLTYPE WINAPI
#تعریف_کړه STDAPIVCALLTYPE __cdecl

#تعریف_کړه STDAPI EXTERN_C HRESULT WINAPI
#تعریف_کړه STDAPI_(type) EXTERN_C type WINAPI

#تعریف_کړه STDMETHODIMP HRESULT WINAPI
#تعریف_کړه STDMETHODIMP_(type) type WINAPI

#تعریف_کړه STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#تعریف_کړه STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#تعریف_کړه STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#تعریف_کړه STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#إذا defined(__cplusplus) && !defined(CINTERFACE)

#تعریف_کړه __STRUCT__ بنية
#تعریف_کړه STDMETHOD(لاره) مجازي HRESULT WINAPI لاره
#تعریف_کړه STDMETHOD_(type,لاره) مجازي type WINAPI لاره
#تعریف_کړه STDMETHODV(لاره) مجازي HRESULT STDMETHODVCALLTYPE لاره
#تعریف_کړه STDMETHODV_(type,لاره) مجازي type STDMETHODVCALLTYPE لاره
#تعریف_کړه خالص = 0
#تعریف_کړه THIS_
#تعریف_کړه THIS فراغ
#تعریف_کړه DECLARE_INTERFACE(iface) __STRUCT__ iface
#تعریف_کړه DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : عام baseiface
#وإلا

#که_نه_تعریف_شوی __OBJC__
#تعریف_کړه interface بنية
#د_که_پای

#تعریف_کړه STDMETHOD(لاره) HRESULT (WINAPI *لاره)
#تعریف_کړه STDMETHOD_(type,لاره) type (WINAPI *لاره)
#تعریف_کړه STDMETHODV(لاره) HRESULT (STDMETHODVCALLTYPE *لاره)
#تعریف_کړه STDMETHODV_(type,لاره) type (STDMETHODVCALLTYPE *لاره)

#تعریف_کړه خالص
#تعریف_کړه THIS_ INTERFACE *This,
#تعریف_کړه THIS INTERFACE *This
#که_تعریف_شوی CONST_VTABLE
#تعریف_کړه DECLARE_INTERFACE(iface) تعريفنوع بنية iface { \
  ثابت بنية iface##Vtbl *lpVtbl; } iface; \
  تعريفنوع ثابت بنية iface##Vtbl iface##Vtbl; \
  ثابت بنية iface##Vtbl
#وإلا
#تعریف_کړه DECLARE_INTERFACE(iface) تعريفنوع بنية iface { \
    بنية iface##Vtbl *lpVtbl; \
  } iface; \
  تعريفنوع بنية iface##Vtbl iface##Vtbl; \
  بنية iface##Vtbl
#د_که_پای
#تعریف_کړه DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#د_که_پای

#ضمن <guiddef.h>

#که_نه_تعریف_شوی ERROR_حالت_T_DEFINED
#تعریف_کړه ERROR_حالت_T_DEFINED
تعريفنوع بینښه اوږد error_حالت_t;
#د_که_پای

#که_نه_تعریف_شوی _WCHAR_T_DEFINED
تعريفنوع بینښه لنډ wchar_t;
#تعریف_کړه _WCHAR_T_DEFINED
#د_که_پای
#د_که_پای
