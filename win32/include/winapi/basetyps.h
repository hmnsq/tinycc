/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#যদি !defined(_BASETYPS_H_)
#define _BASETYPS_H_

#ifdef __cplusplus
#define EXTERN_C বাহ্য "C"
#অন্যথা
#define EXTERN_C বাহ্য
#endif

#define STDMETHODCALLTYPE WINAPI
#define STDMETHODVCALLTYPE __cdecl

#define STDAPICALLTYPE WINAPI
#define STDAPIVCALLTYPE __cdecl

#define STDAPI EXTERN_C HRESULT WINAPI
#define STDAPI_(type) EXTERN_C type WINAPI

#define STDMETHODIMP HRESULT WINAPI
#define STDMETHODIMP_(type) type WINAPI

#define STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#define STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#define STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#define STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#যদি defined(__cplusplus) && !defined(CINTERFACE)

#define __STRUCT__ সংরচনা
#define STDMETHOD(method) আভাস HRESULT WINAPI method
#define STDMETHOD_(type,method) আভাস type WINAPI method
#define STDMETHODV(method) আভাস HRESULT STDMETHODVCALLTYPE method
#define STDMETHODV_(type,method) আভাস type STDMETHODVCALLTYPE method
#define PURE = 0
#define THIS_
#define THIS শূন্য
#define DECLARE_INTERFACE(iface) __STRUCT__ iface
#define DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : সার্বজনিক baseiface
#অন্যথা

#ifndef __OBJC__
#define interface সংরচনা
#endif

#define STDMETHOD(method) HRESULT (WINAPI *method)
#define STDMETHOD_(type,method) type (WINAPI *method)
#define STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE *method)
#define STDMETHODV_(type,method) type (STDMETHODVCALLTYPE *method)

#define PURE
#define THIS_ INTERFACE *This,
#define THIS INTERFACE *This
#ifdef CONST_VTABLE
#define DECLARE_INTERFACE(iface) প্রকারনির্দেশ সংরচনা iface { \
  ধ্রুব সংরচনা iface##Vtbl *lpVtbl; } iface; \
  প্রকারনির্দেশ ধ্রুব সংরচনা iface##Vtbl iface##Vtbl; \
  ধ্রুব সংরচনা iface##Vtbl
#অন্যথা
#define DECLARE_INTERFACE(iface) প্রকারনির্দেশ সংরচনা iface { \
    সংরচনা iface##Vtbl *lpVtbl; \
  } iface; \
  প্রকারনির্দেশ সংরচনা iface##Vtbl iface##Vtbl; \
  সংরচনা iface##Vtbl
#endif
#define DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#endif

#অন্তর্ভাব <guiddef.h>

#ifndef _ERROR_STATUS_T_DEFINED
#define _ERROR_STATUS_T_DEFINED
প্রকারনির্দেশ unsigned long error_status_t;
#endif

#ifndef _WCHAR_T_DEFINED
প্রকারনির্দেশ unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif
#endif
