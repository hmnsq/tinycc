/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#எனில் !defined(_BASETYPS_H_)
#define _BASETYPS_H_

#ifdef __cplusplus
#define EXTERN_C வெளி "C"
#இல்லையெனில்
#define EXTERN_C வெளி
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

#எனில் defined(__cplusplus) && !defined(CINTERFACE)

#define __STRUCT__ கட்டமைப்பு
#define STDMETHOD(method) மெய்நிகர் HRESULT WINAPI method
#define STDMETHOD_(type,method) மெய்நிகர் type WINAPI method
#define STDMETHODV(method) மெய்நிகர் HRESULT STDMETHODVCALLTYPE method
#define STDMETHODV_(type,method) மெய்நிகர் type STDMETHODVCALLTYPE method
#define PURE = 0
#define THIS_
#define THIS வெறுமை
#define DECLARE_INTERFACE(iface) __STRUCT__ iface
#define DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : பொது baseiface
#இல்லையெனில்

#ifndef __OBJC__
#define interface கட்டமைப்பு
#endif

#define STDMETHOD(method) HRESULT (WINAPI *method)
#define STDMETHOD_(type,method) type (WINAPI *method)
#define STDMETHODV(method) HRESULT (STDMETHODVCALLTYPE *method)
#define STDMETHODV_(type,method) type (STDMETHODVCALLTYPE *method)

#define PURE
#define THIS_ INTERFACE *This,
#define THIS INTERFACE *This
#ifdef CONST_VTABLE
#define DECLARE_INTERFACE(iface) வகைவரை கட்டமைப்பு iface { \
  மாறிலி கட்டமைப்பு iface##Vtbl *lpVtbl; } iface; \
  வகைவரை மாறிலி கட்டமைப்பு iface##Vtbl iface##Vtbl; \
  மாறிலி கட்டமைப்பு iface##Vtbl
#இல்லையெனில்
#define DECLARE_INTERFACE(iface) வகைவரை கட்டமைப்பு iface { \
    கட்டமைப்பு iface##Vtbl *lpVtbl; \
  } iface; \
  வகைவரை கட்டமைப்பு iface##Vtbl iface##Vtbl; \
  கட்டமைப்பு iface##Vtbl
#endif
#define DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#endif

#அந்தர்பாவ <guiddef.h>

#ifndef _ERROR_STATUS_T_DEFINED
#define _ERROR_STATUS_T_DEFINED
வகைவரை unsigned long error_status_t;
#endif

#ifndef _WCHAR_T_DEFINED
வகைவரை unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif
#endif
