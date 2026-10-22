/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر !defined(_BASETYPS_H_)
#تعریف_کرو _BASETYPS_H_

#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو EXTERN_C خارجی "C"
#ورنہ
#تعریف_کرو EXTERN_C خارجی
#اگر_ختم

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

#اگر defined(__cplusplus) && !defined(CINTERFACE)

#تعریف_کرو __STRUCT__ ساخت
#تعریف_کرو STDMETHOD(طریقہ_2) مجازی HRESULT WINAPI طریقہ_2
#تعریف_کرو STDMETHOD_(type,طریقہ_2) مجازی type WINAPI طریقہ_2
#تعریف_کرو STDMETHODV(طریقہ_2) مجازی HRESULT STDMETHODVCALLTYPE طریقہ_2
#تعریف_کرو STDMETHODV_(type,طریقہ_2) مجازی type STDMETHODVCALLTYPE طریقہ_2
#تعریف_کرو خالص = 0
#تعریف_کرو THIS_
#تعریف_کرو THIS خالی
#تعریف_کرو DECLARE_INTERFACE(iface) __STRUCT__ iface
#تعریف_کرو DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : عوامی baseiface
#ورنہ

#اگر_غیر_تعریف_شدہ __OBJC__
#تعریف_کرو interface ساخت
#اگر_ختم

#تعریف_کرو STDMETHOD(طریقہ_2) HRESULT (WINAPI *طریقہ_2)
#تعریف_کرو STDMETHOD_(type,طریقہ_2) type (WINAPI *طریقہ_2)
#تعریف_کرو STDMETHODV(طریقہ_2) HRESULT (STDMETHODVCALLTYPE *طریقہ_2)
#تعریف_کرو STDMETHODV_(type,طریقہ_2) type (STDMETHODVCALLTYPE *طریقہ_2)

#تعریف_کرو خالص
#تعریف_کرو THIS_ INTERFACE *This,
#تعریف_کرو THIS INTERFACE *This
#اگر_تعریف_شدہ CONST_VTABLE
#تعریف_کرو DECLARE_INTERFACE(iface) قسمتعریف ساخت iface { \
  ثابت ساخت iface##Vtbl *lpVtbl; } iface; \
  قسمتعریف ثابت ساخت iface##Vtbl iface##Vtbl; \
  ثابت ساخت iface##Vtbl
#ورنہ
#تعریف_کرو DECLARE_INTERFACE(iface) قسمتعریف ساخت iface { \
    ساخت iface##Vtbl *lpVtbl; \
  } iface; \
  قسمتعریف ساخت iface##Vtbl iface##Vtbl; \
  ساخت iface##Vtbl
#اگر_ختم
#تعریف_کرو DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#اگر_ختم

#شامل <guiddef.h>

#اگر_غیر_تعریف_شدہ ERROR_حالت_T_DEFINED
#تعریف_کرو ERROR_حالت_T_DEFINED
قسمتعریف غیرعلامتی طویل error_حالت_t;
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WCHAR_T_DEFINED
قسمتعریف غیرعلامتی مختصر wchar_t;
#تعریف_کرو _WCHAR_T_DEFINED
#اگر_ختم
#اگر_ختم
