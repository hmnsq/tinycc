/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ಆದರೆ !defined(_BASETYPS_H_)
#ವ್ಯಾಖ್ಯಾನಿಸು _BASETYPS_H_

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
#ವ್ಯಾಖ್ಯಾನಿಸು EXTERN_C ಬಾಹ್ಯ "C"
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು EXTERN_C ಬಾಹ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODCALLTYPE WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODVCALLTYPE __cdecl

#ವ್ಯಾಖ್ಯಾನಿಸು STDAPICALLTYPE WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDAPIVCALLTYPE __cdecl

#ವ್ಯಾಖ್ಯಾನಿಸು STDAPI EXTERN_C HRESULT WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDAPI_(type) EXTERN_C type WINAPI

#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODIMP HRESULT WINAPI
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODIMP_(type) type WINAPI

#ವ್ಯಾಖ್ಯಾನಿಸು STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#ವ್ಯಾಖ್ಯಾನಿಸು STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#ಆದರೆ defined(__cplusplus) && !defined(CINTERFACE)

#ವ್ಯಾಖ್ಯಾನಿಸು __STRUCT__ ರಚನೆ
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHOD(ವಿಧಾನ_2) ವಾಸ್ತವಿಕ HRESULT WINAPI ವಿಧಾನ_2
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHOD_(type,ವಿಧಾನ_2) ವಾಸ್ತವಿಕ type WINAPI ವಿಧಾನ_2
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODV(ವಿಧಾನ_2) ವಾಸ್ತವಿಕ HRESULT STDMETHODVCALLTYPE ವಿಧಾನ_2
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODV_(type,ವಿಧಾನ_2) ವಾಸ್ತವಿಕ type STDMETHODVCALLTYPE ವಿಧಾನ_2
#ವ್ಯಾಖ್ಯಾನಿಸು ಶುದ್ಧ = 0
#ವ್ಯಾಖ್ಯಾನಿಸು THIS_
#ವ್ಯಾಖ್ಯಾನಿಸು THIS ಶೂನ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು DECLARE_INTERFACE(iface) __STRUCT__ iface
#ವ್ಯಾಖ್ಯಾನಿಸು DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : ಸಾರ್ವಜನಿಕ baseiface
#ಇಲ್ಲದಿದ್ದರೆ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ __OBJC__
#ವ್ಯಾಖ್ಯಾನಿಸು interface ರಚನೆ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHOD(ವಿಧಾನ_2) HRESULT (WINAPI *ವಿಧಾನ_2)
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHOD_(type,ವಿಧಾನ_2) type (WINAPI *ವಿಧಾನ_2)
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODV(ವಿಧಾನ_2) HRESULT (STDMETHODVCALLTYPE *ವಿಧಾನ_2)
#ವ್ಯಾಖ್ಯಾನಿಸು STDMETHODV_(type,ವಿಧಾನ_2) type (STDMETHODVCALLTYPE *ವಿಧಾನ_2)

#ವ್ಯಾಖ್ಯಾನಿಸು ಶುದ್ಧ
#ವ್ಯಾಖ್ಯಾನಿಸು THIS_ INTERFACE *This,
#ವ್ಯಾಖ್ಯಾನಿಸು THIS INTERFACE *This
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ CONST_VTABLE
#ವ್ಯಾಖ್ಯಾನಿಸು DECLARE_INTERFACE(iface) ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ iface { \
  ಸ್ಥಿರಾಂಕ ರಚನೆ iface##Vtbl *lpVtbl; } iface; \
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ರಚನೆ iface##Vtbl iface##Vtbl; \
  ಸ್ಥಿರಾಂಕ ರಚನೆ iface##Vtbl
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು DECLARE_INTERFACE(iface) ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ iface { \
    ರಚನೆ iface##Vtbl *lpVtbl; \
  } iface; \
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ iface##Vtbl iface##Vtbl; \
  ರಚನೆ iface##Vtbl
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <guiddef.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ERROR_ಸ್ಥಿತಿ_T_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು ERROR_ಸ್ಥಿತಿ_T_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ದೀರ್ಘ error_ಸ್ಥಿತಿ_t;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WCHAR_T_DEFINED
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ wchar_t;
#ವ್ಯಾಖ್ಯಾನಿಸು _WCHAR_T_DEFINED
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
