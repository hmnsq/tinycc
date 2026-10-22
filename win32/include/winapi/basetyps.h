/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر !defined(_BASETYPS_H_)
#define _BASETYPS_H_

#ifdef __cplusplus
#define EXTERN_C بیرونی "C"
#وگرنه
#define EXTERN_C بیرونی
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

#اگر defined(__cplusplus) && !defined(CINTERFACE)

#define __STRUCT__ ساختار
#define STDMETHOD(method) مجازی HRESULT WINAPI method
#define STDMETHOD_(type,method) مجازی type WINAPI method
#define STDMETHODV(method) مجازی HRESULT STDMETHODVCALLTYPE method
#define STDMETHODV_(type,method) مجازی type STDMETHODVCALLTYPE method
#define PURE = 0
#define THIS_
#define THIS تهی
#define DECLARE_INTERFACE(iface) __STRUCT__ iface
#define DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : عمومی baseiface
#وگرنه

#ifndef __OBJC__
#define interface ساختار
#endif

#define STDMETHOD(method) HRESULT (WINAPI *method)
#define STDMETHOD_(type,method) type (WINAPI *method)
#define STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE *method)
#define STDMETHODV_(type,method) type (STDMETHODVCALLTYPE *method)

#define PURE
#define THIS_ INTERFACE *This,
#define THIS INTERFACE *This
#ifdef CONST_VTABLE
#define DECLARE_INTERFACE(iface) تعریفنوع ساختار iface { \
  ثابت ساختار iface##Vtbl *lpVtbl; } iface; \
  تعریفنوع ثابت ساختار iface##Vtbl iface##Vtbl; \
  ثابت ساختار iface##Vtbl
#وگرنه
#define DECLARE_INTERFACE(iface) تعریفنوع ساختار iface { \
    ساختار iface##Vtbl *lpVtbl; \
  } iface; \
  تعریفنوع ساختار iface##Vtbl iface##Vtbl; \
  ساختار iface##Vtbl
#endif
#define DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#endif

#شامل <guiddef.h>

#ifndef _ERROR_STATUS_T_DEFINED
#define _ERROR_STATUS_T_DEFINED
تعریفنوع unsigned long error_status_t;
#endif

#ifndef _WCHAR_T_DEFINED
تعریفنوع unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif
#endif
