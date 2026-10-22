/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#إذا !defined(_BASETYPS_H_)
#وصف_ڪريو _BASETYPS_H_

#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو EXTERN_C خارجي "C"
#وإلا
#وصف_ڪريو EXTERN_C خارجي
#جيڪڏهن_پورو

#وصف_ڪريو STDMETHODCALLTYPE WINAPI
#وصف_ڪريو STDMETHODVCALLTYPE __cdecl

#وصف_ڪريو STDAPICALLTYPE WINAPI
#وصف_ڪريو STDAPIVCALLTYPE __cdecl

#وصف_ڪريو STDAPI EXTERN_C HRESULT WINAPI
#وصف_ڪريو STDAPI_(type) EXTERN_C type WINAPI

#وصف_ڪريو STDMETHODIMP HRESULT WINAPI
#وصف_ڪريو STDMETHODIMP_(type) type WINAPI

#وصف_ڪريو STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#وصف_ڪريو STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#وصف_ڪريو STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#وصف_ڪريو STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#إذا defined(__cplusplus) && !defined(CINTERFACE)

#وصف_ڪريو __STRUCT__ بنية
#وصف_ڪريو STDMETHOD(طريقو) مجازي HRESULT WINAPI طريقو
#وصف_ڪريو STDMETHOD_(type,طريقو) مجازي type WINAPI طريقو
#وصف_ڪريو STDMETHODV(طريقو) مجازي HRESULT STDMETHODVCALLTYPE طريقو
#وصف_ڪريو STDMETHODV_(type,طريقو) مجازي type STDMETHODVCALLTYPE طريقو
#وصف_ڪريو خالص = 0
#وصف_ڪريو THIS_
#وصف_ڪريو THIS فراغ
#وصف_ڪريو DECLARE_INTERFACE(iface) __STRUCT__ iface
#وصف_ڪريو DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : عام baseiface
#وإلا

#جيڪڏهن_وصف_نه_ٿيل __OBJC__
#وصف_ڪريو interface بنية
#جيڪڏهن_پورو

#وصف_ڪريو STDMETHOD(طريقو) HRESULT (WINAPI *طريقو)
#وصف_ڪريو STDMETHOD_(type,طريقو) type (WINAPI *طريقو)
#وصف_ڪريو STDMETHODV(طريقو) HRESULT (STDMETHODVCALLTYPE *طريقو)
#وصف_ڪريو STDMETHODV_(type,طريقو) type (STDMETHODVCALLTYPE *طريقو)

#وصف_ڪريو خالص
#وصف_ڪريو THIS_ INTERFACE *This,
#وصف_ڪريو THIS INTERFACE *This
#جيڪڏهن_وصف_ٿيل CONST_VTABLE
#وصف_ڪريو DECLARE_INTERFACE(iface) تعريفنوع بنية iface { \
  ثابت بنية iface##Vtbl *lpVtbl; } iface; \
  تعريفنوع ثابت بنية iface##Vtbl iface##Vtbl; \
  ثابت بنية iface##Vtbl
#وإلا
#وصف_ڪريو DECLARE_INTERFACE(iface) تعريفنوع بنية iface { \
    بنية iface##Vtbl *lpVtbl; \
  } iface; \
  تعريفنوع بنية iface##Vtbl iface##Vtbl; \
  بنية iface##Vtbl
#جيڪڏهن_پورو
#وصف_ڪريو DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#جيڪڏهن_پورو

#ضمن <guiddef.h>

#جيڪڏهن_وصف_نه_ٿيل ERROR_حالت_T_DEFINED
#وصف_ڪريو ERROR_حالت_T_DEFINED
تعريفنوع بنانشان ڊگهو error_حالت_t;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WCHAR_T_DEFINED
تعريفنوع بنانشان ننڍو wchar_t;
#وصف_ڪريو _WCHAR_T_DEFINED
#جيڪڏهن_پورو
#جيڪڏهن_پورو
