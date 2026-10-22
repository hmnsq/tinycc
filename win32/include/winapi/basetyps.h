/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ఒకవేళ !defined(_BASETYPS_H_)
#నిర్వచించు _BASETYPS_H_

#నిర్వచితమైతే __cplusplus
#నిర్వచించు EXTERN_C బాహ్య "C"
#లేకపోతే
#నిర్వచించు EXTERN_C బాహ్య
#అయితే_ముగింపు

#నిర్వచించు STDMETHODCALLTYPE WINAPI
#నిర్వచించు STDMETHODVCALLTYPE __cdecl

#నిర్వచించు STDAPICALLTYPE WINAPI
#నిర్వచించు STDAPIVCALLTYPE __cdecl

#నిర్వచించు STDAPI EXTERN_C HRESULT WINAPI
#నిర్వచించు STDAPI_(type) EXTERN_C type WINAPI

#నిర్వచించు STDMETHODIMP HRESULT WINAPI
#నిర్వచించు STDMETHODIMP_(type) type WINAPI

#నిర్వచించు STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#నిర్వచించు STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE

#నిర్వచించు STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#నిర్వచించు STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

#ఒకవేళ defined(__cplusplus) && !defined(CINTERFACE)

#నిర్వచించు __STRUCT__ నిర్మాణం
#నిర్వచించు STDMETHOD(పద్ధతి) మాయా HRESULT WINAPI పద్ధతి
#నిర్వచించు STDMETHOD_(type,పద్ధతి) మాయా type WINAPI పద్ధతి
#నిర్వచించు STDMETHODV(పద్ధతి) మాయా HRESULT STDMETHODVCALLTYPE పద్ధతి
#నిర్వచించు STDMETHODV_(type,పద్ధతి) మాయా type STDMETHODVCALLTYPE పద్ధతి
#నిర్వచించు శుద్ధ = 0
#నిర్వచించు THIS_
#నిర్వచించు THIS శూన్య
#నిర్వచించు DECLARE_INTERFACE(iface) __STRUCT__ iface
#నిర్వచించు DECLARE_INTERFACE_(iface,baseiface) __STRUCT__ iface : బహిరంగ baseiface
#లేకపోతే

#నిర్వచితం_కాకపోతే __OBJC__
#నిర్వచించు interface నిర్మాణం
#అయితే_ముగింపు

#నిర్వచించు STDMETHOD(పద్ధతి) HRESULT (WINAPI *పద్ధతి)
#నిర్వచించు STDMETHOD_(type,పద్ధతి) type (WINAPI *పద్ధతి)
#నిర్వచించు STDMETHODV(పద్ధతి) HRESULT (STDMETHODVCALLTYPE *పద్ధతి)
#నిర్వచించు STDMETHODV_(type,పద్ధతి) type (STDMETHODVCALLTYPE *పద్ధతి)

#నిర్వచించు శుద్ధ
#నిర్వచించు THIS_ INTERFACE *This,
#నిర్వచించు THIS INTERFACE *This
#నిర్వచితమైతే CONST_VTABLE
#నిర్వచించు DECLARE_INTERFACE(iface) రకనిర్వచనం నిర్మాణం iface { \
  స్థిరరాశి నిర్మాణం iface##Vtbl *lpVtbl; } iface; \
  రకనిర్వచనం స్థిరరాశి నిర్మాణం iface##Vtbl iface##Vtbl; \
  స్థిరరాశి నిర్మాణం iface##Vtbl
#లేకపోతే
#నిర్వచించు DECLARE_INTERFACE(iface) రకనిర్వచనం నిర్మాణం iface { \
    నిర్మాణం iface##Vtbl *lpVtbl; \
  } iface; \
  రకనిర్వచనం నిర్మాణం iface##Vtbl iface##Vtbl; \
  నిర్మాణం iface##Vtbl
#అయితే_ముగింపు
#నిర్వచించు DECLARE_INTERFACE_(iface,baseiface) DECLARE_INTERFACE(iface)
#అయితే_ముగింపు

#అన్తర్భావ <guiddef.h>

#నిర్వచితం_కాకపోతే ERROR_స్థితి_T_DEFINED
#నిర్వచించు ERROR_స్థితి_T_DEFINED
రకనిర్వచనం గుర్తులేని దీర్ఘ error_స్థితి_t;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WCHAR_T_DEFINED
రకనిర్వచనం గుర్తులేని పొట్టి wchar_t;
#నిర్వచించు _WCHAR_T_DEFINED
#అయితే_ముగింపు
#అయితే_ముగింపు
