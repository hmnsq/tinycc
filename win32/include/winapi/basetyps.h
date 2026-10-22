/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#إذا !defined(_BASETYPS_H_)
#تعریف_کرو _BASETYPS_H_

#جے_تعریف_شدہ __cplusplus
#تعریف_کرو EXTERN_C خارجي "C"
#وإلا
#تعریف_کرو EXTERN_C خارجي
#جے_انت

#تعریف_کرو STDMETHODCALLTYPE WINAPI
#تعریف_کرو STDMETHODVCALLTYPE __cdecl

#تعریف_کرو STDAPICALLTYPE WINAPI
#تعریف_کرو STDAPIVCALLTYPE __cdecl

#تعریف_کرو STDAPI EXTERN_C HRESULT WINAPI
#تعریف_کرو STDAPI_(type) EXTERN_C type WINAPI

#تعریف_کرو STDMETHODIMP HRESULT WINAPI
#تعریف_کرو STDMETHODIMP_(type) type WINAPI

#تعریف_کرو STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#تعریف_کرو STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#تعریف_کرو STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#تعریف_کرو STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#إذا defined(__cplusplus) && !defined(CINTERFACE)

#تعریف_کرو __STRUCT__ بنية
#تعریف_کرو STDMETHOD(طریقہ) مجازی HRESULT WINAPI طریقہ
#تعریف_کرو STDMETHOD_(type,طریقہ) مجازی type WINAPI طریقہ
#تعریف_کرو STDMETHODV(طریقہ) مجازی HRESULT STDMETHODVCALLTYPE طریقہ
#تعریف_کرو STDMETHODV_(type,طریقہ) مجازی type STDMETHODVCALLTYPE طریقہ
#تعریف_کرو خالص = 0
#تعریف_کرو THIS_
#تعریف_کرو THIS فراغ
#تعریف_کرو DECLARE_INTERFACE(iface) __STRUCT__ iface
#تعریف_کرو DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : عام baseiface
#وإلا

#جے_بنا_تعریف __OBJC__
#تعریف_کرو interface بنية
#جے_انت

#تعریف_کرو STDMETHOD(طریقہ) HRESULT (WINAPI *طریقہ)
#تعریف_کرو STDMETHOD_(type,طریقہ) type (WINAPI *طریقہ)
#تعریف_کرو STDMETHODV(طریقہ) HRESULT (STDMETHODVCALLTYPE *طریقہ)
#تعریف_کرو STDMETHODV_(type,طریقہ) type (STDMETHODVCALLTYPE *طریقہ)

#تعریف_کرو خالص
#تعریف_کرو THIS_ INTERFACE *This,
#تعریف_کرو THIS INTERFACE *This
#جے_تعریف_شدہ CONST_VTABLE
#تعریف_کرو DECLARE_INTERFACE(iface) تعريفنوع بنية iface { \
  ثابت بنية iface##Vtbl *lpVtbl; } iface; \
  تعريفنوع ثابت بنية iface##Vtbl iface##Vtbl; \
  ثابت بنية iface##Vtbl
#وإلا
#تعریف_کرو DECLARE_INTERFACE(iface) تعريفنوع بنية iface { \
    بنية iface##Vtbl *lpVtbl; \
  } iface; \
  تعريفنوع بنية iface##Vtbl iface##Vtbl; \
  بنية iface##Vtbl
#جے_انت
#تعریف_کرو DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#جے_انت

#ضمن <guiddef.h>

#جے_بنا_تعریف ERROR_حالت_T_DEFINED
#تعریف_کرو ERROR_حالت_T_DEFINED
تعريفنوع بنانشانی لما error_حالت_t;
#جے_انت

#جے_بنا_تعریف _WCHAR_T_DEFINED
تعريفنوع بنانشانی چھوٹا wchar_t;
#تعریف_کرو _WCHAR_T_DEFINED
#جے_انت
#جے_انت
