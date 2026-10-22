/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ಯದಿ !defined(_BASETYPS_H_)
#define _BASETYPS_H_

#ifdef __cplusplus
#define EXTERN_C ಬಾಹ್ಯ "C"
#ಅನ್ಯಥಾ
#define EXTERN_C ಬಾಹ್ಯ
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

#ಯದಿ defined(__cplusplus) && !defined(CINTERFACE)

#define __STRUCT__ ಸಂರಚನಾ
#define STDMETHOD(method) ಆಭಾಸ HRESULT WINAPI method
#define STDMETHOD_(type,method) ಆಭಾಸ type WINAPI method
#define STDMETHODV(method) ಆಭಾಸ HRESULT STDMETHODVCALLTYPE method
#define STDMETHODV_(type,method) ಆಭಾಸ type STDMETHODVCALLTYPE method
#define PURE = 0
#define THIS_
#define THIS ಶೂನ್ಯ
#define DECLARE_INTERFACE(iface) __STRUCT__ iface
#define DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : ಸಾರ್ವಜನಿಕ baseiface
#ಅನ್ಯಥಾ

#ifndef __OBJC__
#define interface ಸಂರಚನಾ
#endif

#define STDMETHOD(method) HRESULT (WINAPI *method)
#define STDMETHOD_(type,method) type (WINAPI *method)
#define STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE *method)
#define STDMETHODV_(type,method) type (STDMETHODVCALLTYPE *method)

#define PURE
#define THIS_ INTERFACE *This,
#define THIS INTERFACE *This
#ifdef CONST_VTABLE
#define DECLARE_INTERFACE(iface) ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ iface { \
  ಧ್ರುವ ಸಂರಚನಾ iface##Vtbl *lpVtbl; } iface; \
  ಪ್ರಕಾರನಿರ್ದೇಶ ಧ್ರುವ ಸಂರಚನಾ iface##Vtbl iface##Vtbl; \
  ಧ್ರುವ ಸಂರಚನಾ iface##Vtbl
#ಅನ್ಯಥಾ
#define DECLARE_INTERFACE(iface) ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ iface { \
    ಸಂರಚನಾ iface##Vtbl *lpVtbl; \
  } iface; \
  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ iface##Vtbl iface##Vtbl; \
  ಸಂರಚನಾ iface##Vtbl
#endif
#define DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#endif

#ಅನ್ತರ್ಭಾವ <guiddef.h>

#ifndef _ERROR_STATUS_T_DEFINED
#define _ERROR_STATUS_T_DEFINED
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long error_status_t;
#endif

#ifndef _WCHAR_T_DEFINED
ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif
#endif
