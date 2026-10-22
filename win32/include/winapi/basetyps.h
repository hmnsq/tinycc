/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#सचे !defined(_BASETYPS_H_)
#define _BASETYPS_H_

#ifdef __cplusplus
#define EXTERN_C बाह्य "C"
#अञ्ञथा
#define EXTERN_C बाह्य
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

#सचे defined(__cplusplus) && !defined(CINTERFACE)

#define __STRUCT__ संरचना
#define STDMETHOD(method) आभास HRESULT WINAPI method
#define STDMETHOD_(type,method) आभास type WINAPI method
#define STDMETHODV(method) आभास HRESULT STDMETHODVCALLTYPE method
#define STDMETHODV_(type,method) आभास type STDMETHODVCALLTYPE method
#define PURE = 0
#define THIS_
#define THIS शून्य
#define DECLARE_INTERFACE(iface) __STRUCT__ iface
#define DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : सार्वजनिक baseiface
#अञ्ञथा

#ifndef __OBJC__
#define interface संरचना
#endif

#define STDMETHOD(method) HRESULT (WINAPI *method)
#define STDMETHOD_(type,method) type (WINAPI *method)
#define STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE *method)
#define STDMETHODV_(type,method) type (STDMETHODVCALLTYPE *method)

#define PURE
#define THIS_ INTERFACE *This,
#define THIS INTERFACE *This
#ifdef CONST_VTABLE
#define DECLARE_INTERFACE(iface) प्रकारनिर्देश संरचना iface { \
  ध्रुव संरचना iface##Vtbl *lpVtbl; } iface; \
  प्रकारनिर्देश ध्रुव संरचना iface##Vtbl iface##Vtbl; \
  ध्रुव संरचना iface##Vtbl
#अञ्ञथा
#define DECLARE_INTERFACE(iface) प्रकारनिर्देश संरचना iface { \
    संरचना iface##Vtbl *lpVtbl; \
  } iface; \
  प्रकारनिर्देश संरचना iface##Vtbl iface##Vtbl; \
  संरचना iface##Vtbl
#endif
#define DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#endif

#अन्तर्भाव <guiddef.h>

#ifndef _ERROR_STATUS_T_DEFINED
#define _ERROR_STATUS_T_DEFINED
प्रकारनिर्देश unsigned long error_status_t;
#endif

#ifndef _WCHAR_T_DEFINED
प्रकारनिर्देश unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif
#endif
