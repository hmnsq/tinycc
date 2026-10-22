/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ଯଦି !defined(_BASETYPS_H_)
#define _BASETYPS_H_

#ifdef __cplusplus
#define EXTERN_C ବାହ୍ୟ "C"
#ଅନ୍ୟଥା
#define EXTERN_C ବାହ୍ୟ
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

#ଯଦି defined(__cplusplus) && !defined(CINTERFACE)

#define __STRUCT__ ସଂରଚନା
#define STDMETHOD(method) ଆଭାସୀ HRESULT WINAPI method
#define STDMETHOD_(type,method) ଆଭାସୀ type WINAPI method
#define STDMETHODV(method) ଆଭାସୀ HRESULT STDMETHODVCALLTYPE method
#define STDMETHODV_(type,method) ଆଭାସୀ type STDMETHODVCALLTYPE method
#define PURE = 0
#define THIS_
#define THIS ଶୂନ୍ୟ
#define DECLARE_INTERFACE(iface) __STRUCT__ iface
#define DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : ସର୍ବସାଧାରଣ baseiface
#ଅନ୍ୟଥା

#ifndef __OBJC__
#define interface ସଂରଚନା
#endif

#define STDMETHOD(method) HRESULT (WINAPI *method)
#define STDMETHOD_(type,method) type (WINAPI *method)
#define STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE *method)
#define STDMETHODV_(type,method) type (STDMETHODVCALLTYPE *method)

#define PURE
#define THIS_ INTERFACE *This,
#define THIS INTERFACE *This
#ifdef CONST_VTABLE
#define DECLARE_INTERFACE(iface) ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା iface { \
  ଅଚଳ ସଂରଚନା iface##Vtbl *lpVtbl; } iface; \
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅଚଳ ସଂରଚନା iface##Vtbl iface##Vtbl; \
  ଅଚଳ ସଂରଚନା iface##Vtbl
#ଅନ୍ୟଥା
#define DECLARE_INTERFACE(iface) ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା iface { \
    ସଂରଚନା iface##Vtbl *lpVtbl; \
  } iface; \
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା iface##Vtbl iface##Vtbl; \
  ସଂରଚନା iface##Vtbl
#endif
#define DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#endif

#ଅନ୍ତର୍ଭାଵ <guiddef.h>

#ifndef _ERROR_STATUS_T_DEFINED
#define _ERROR_STATUS_T_DEFINED
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned long error_status_t;
#endif

#ifndef _WCHAR_T_DEFINED
ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif
#endif
