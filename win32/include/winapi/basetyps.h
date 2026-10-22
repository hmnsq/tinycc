/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि !defined(_BASETYPS_H_)
#परिभाषय _BASETYPS_H_

#यदि_परिभाषितम् __cplusplus
#परिभाषय EXTERN_C बाह्य "C"
#अन्यथा
#परिभाषय EXTERN_C बाह्य
#यदि_अन्तः

#परिभाषय STDMETHODCALLTYPE WINAPI
#परिभाषय STDMETHODVCALLTYPE __cdecl

#परिभाषय STDAPICALLTYPE WINAPI
#परिभाषय STDAPIVCALLTYPE __cdecl

#परिभाषय STDAPI EXTERN_C HRESULT WINAPI
#परिभाषय STDAPI_(type) EXTERN_C type WINAPI

#परिभाषय STDMETHODIMP HRESULT WINAPI
#परिभाषय STDMETHODIMP_(type) type WINAPI

#परिभाषय STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#परिभाषय STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#परिभाषय STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#परिभाषय STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#यदि defined(__cplusplus) && !defined(CINTERFACE)

#परिभाषय __STRUCT__ संरचना
#परिभाषय STDMETHOD(विधानम्) आभास HRESULT WINAPI विधानम्
#परिभाषय STDMETHOD_(type,विधानम्) आभास type WINAPI विधानम्
#परिभाषय STDMETHODV(विधानम्) आभास HRESULT STDMETHODVCALLTYPE विधानम्
#परिभाषय STDMETHODV_(type,विधानम्) आभास type STDMETHODVCALLTYPE विधानम्
#परिभाषय विशुद्धम् = 0
#परिभाषय THIS_
#परिभाषय THIS शून्य
#परिभाषय DECLARE_INTERFACE(iface) __STRUCT__ iface
#परिभाषय DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : सार्वजनिक baseiface
#अन्यथा

#यदि_अपरिभाषितम् __OBJC__
#परिभाषय interface संरचना
#यदि_अन्तः

#परिभाषय STDMETHOD(विधानम्) HRESULT (WINAPI *विधानम्)
#परिभाषय STDMETHOD_(type,विधानम्) type (WINAPI *विधानम्)
#परिभाषय STDMETHODV(विधानम्) HRESULT (STDMETHODVCALLTYPE *विधानम्)
#परिभाषय STDMETHODV_(type,विधानम्) type (STDMETHODVCALLTYPE *विधानम्)

#परिभाषय विशुद्धम्
#परिभाषय THIS_ INTERFACE *This,
#परिभाषय THIS INTERFACE *This
#यदि_परिभाषितम् CONST_VTABLE
#परिभाषय DECLARE_INTERFACE(iface) प्रकारनिर्देश संरचना iface { \
  ध्रुव संरचना iface##Vtbl *lpVtbl; } iface; \
  प्रकारनिर्देश ध्रुव संरचना iface##Vtbl iface##Vtbl; \
  ध्रुव संरचना iface##Vtbl
#अन्यथा
#परिभाषय DECLARE_INTERFACE(iface) प्रकारनिर्देश संरचना iface { \
    संरचना iface##Vtbl *lpVtbl; \
  } iface; \
  प्रकारनिर्देश संरचना iface##Vtbl iface##Vtbl; \
  संरचना iface##Vtbl
#यदि_अन्तः
#परिभाषय DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#यदि_अन्तः

#अन्तर्भाव <guiddef.h>

#यदि_अपरिभाषितम् ERROR_स्थितिः_T_DEFINED
#परिभाषय ERROR_स्थितिः_T_DEFINED
प्रकारनिर्देश अचिह्नित दीर्घ error_स्थितिः_t;
#यदि_अन्तः

#यदि_अपरिभाषितम् _WCHAR_T_DEFINED
प्रकारनिर्देश अचिह्नित ह्रस्व wchar_t;
#परिभाषय _WCHAR_T_DEFINED
#यदि_अन्तः
#यदि_अन्तः
