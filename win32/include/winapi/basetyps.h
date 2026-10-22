/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#إذا !defined(_BASETYPS_H_)
#تعریف_کن _BASETYPS_H_

#اگر_تعریف_شده __cplusplus
#تعریف_کن EXTERN_C خارجي "C"
#وإلا
#تعریف_کن EXTERN_C خارجي
#پایان_اگر

#تعریف_کن STDMETHODCALLTYPE WINAPI
#تعریف_کن STDMETHODVCALLTYPE __cdecl

#تعریف_کن STDAPICALLTYPE WINAPI
#تعریف_کن STDAPIVCALLTYPE __cdecl

#تعریف_کن STDAPI EXTERN_C HRESULT WINAPI
#تعریف_کن STDAPI_(type) EXTERN_C type WINAPI

#تعریف_کن STDMETHODIMP HRESULT WINAPI
#تعریف_کن STDMETHODIMP_(type) type WINAPI

#تعریف_کن STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#تعریف_کن STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#تعریف_کن STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#تعریف_کن STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#إذا defined(__cplusplus) && !defined(CINTERFACE)

#تعریف_کن __STRUCT__ بنية
#تعریف_کن STDMETHOD(روش) مجازی HRESULT WINAPI روش
#تعریف_کن STDMETHOD_(type,روش) مجازی type WINAPI روش
#تعریف_کن STDMETHODV(روش) مجازی HRESULT STDMETHODVCALLTYPE روش
#تعریف_کن STDMETHODV_(type,روش) مجازی type STDMETHODVCALLTYPE روش
#تعریف_کن خالص = 0
#تعریف_کن THIS_
#تعریف_کن THIS فراغ
#تعریف_کن DECLARE_INTERFACE(iface) __STRUCT__ iface
#تعریف_کن DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : عام baseiface
#وإلا

#اگر_تعریف_نشده __OBJC__
#تعریف_کن interface بنية
#پایان_اگر

#تعریف_کن STDMETHOD(روش) HRESULT (WINAPI *روش)
#تعریف_کن STDMETHOD_(type,روش) type (WINAPI *روش)
#تعریف_کن STDMETHODV(روش) HRESULT (STDMETHODVCALLTYPE *روش)
#تعریف_کن STDMETHODV_(type,روش) type (STDMETHODVCALLTYPE *روش)

#تعریف_کن خالص
#تعریف_کن THIS_ INTERFACE *This,
#تعریف_کن THIS INTERFACE *This
#اگر_تعریف_شده CONST_VTABLE
#تعریف_کن DECLARE_INTERFACE(iface) تعريفنوع بنية iface { \
  ثابت بنية iface##Vtbl *lpVtbl; } iface; \
  تعريفنوع ثابت بنية iface##Vtbl iface##Vtbl; \
  ثابت بنية iface##Vtbl
#وإلا
#تعریف_کن DECLARE_INTERFACE(iface) تعريفنوع بنية iface { \
    بنية iface##Vtbl *lpVtbl; \
  } iface; \
  تعريفنوع بنية iface##Vtbl iface##Vtbl; \
  بنية iface##Vtbl
#پایان_اگر
#تعریف_کن DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#پایان_اگر

#ضمن <guiddef.h>

#اگر_تعریف_نشده ERROR_وضعیت_T_DEFINED
#تعریف_کن ERROR_وضعیت_T_DEFINED
تعريفنوع بیعلامت دراز error_وضعیت_t;
#پایان_اگر

#اگر_تعریف_نشده _WCHAR_T_DEFINED
تعريفنوع بیعلامت کوتاه wchar_t;
#تعریف_کن _WCHAR_T_DEFINED
#پایان_اگر
#پایان_اگر
