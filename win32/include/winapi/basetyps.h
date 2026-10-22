/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ !defined(_BASETYPS_H_)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _BASETYPS_H_

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXTERN_C ਬਾਹਰੀ "C"
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXTERN_C ਬਾਹਰੀ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODCALLTYPE WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODVCALLTYPE __cdecl

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPICALLTYPE WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPIVCALLTYPE __cdecl

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPI EXTERN_C HRESULT WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPI_(type) EXTERN_C type WINAPI

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODIMP HRESULT WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODIMP_(type) type WINAPI

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#ਜੇ defined(__cplusplus) && !defined(CINTERFACE)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __STRUCT__ ਬਣਤਰ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHOD(ਵਿਧੀ_2) ਆਭਾਸੀ HRESULT WINAPI ਵਿਧੀ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHOD_(type,ਵਿਧੀ_2) ਆਭਾਸੀ type WINAPI ਵਿਧੀ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODV(ਵਿਧੀ_2) ਆਭਾਸੀ HRESULT STDMETHODVCALLTYPE ਵਿਧੀ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODV_(type,ਵਿਧੀ_2) ਆਭਾਸੀ type STDMETHODVCALLTYPE ਵਿਧੀ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸ਼ੁੱਧ = 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THIS_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THIS ਖਾਲੀ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLARE_INTERFACE(iface) __STRUCT__ iface
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : ਜਨਤਕ baseiface
#ਨਹੀਂਤਾਂ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ __OBJC__
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ interface ਬਣਤਰ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHOD(ਵਿਧੀ_2) HRESULT (WINAPI *ਵਿਧੀ_2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHOD_(type,ਵਿਧੀ_2) type (WINAPI *ਵਿਧੀ_2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODV(ਵਿਧੀ_2) HRESULT (STDMETHODVCALLTYPE *ਵਿਧੀ_2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STDMETHODV_(type,ਵਿਧੀ_2) type (STDMETHODVCALLTYPE *ਵਿਧੀ_2)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸ਼ੁੱਧ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THIS_ INTERFACE *This,
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THIS INTERFACE *This
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ CONST_VTABLE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLARE_INTERFACE(iface) ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ iface { \
  ਅਚਲ ਬਣਤਰ iface##Vtbl *lpVtbl; } iface; \
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ਬਣਤਰ iface##Vtbl iface##Vtbl; \
  ਅਚਲ ਬਣਤਰ iface##Vtbl
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLARE_INTERFACE(iface) ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ iface { \
    ਬਣਤਰ iface##Vtbl *lpVtbl; \
  } iface; \
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ iface##Vtbl iface##Vtbl; \
  ਬਣਤਰ iface##Vtbl
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <guiddef.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ERROR_ਸਥਿਤੀ_T_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ERROR_ਸਥਿਤੀ_T_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ error_ਸਥਿਤੀ_t;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WCHAR_T_DEFINED
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ wchar_t;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WCHAR_T_DEFINED
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
