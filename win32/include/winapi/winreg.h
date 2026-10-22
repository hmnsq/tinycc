/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _WINREG_
#تعریف_کن _WINREG_

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده WINVER
#تعریف_کن WINVER 0x0502
#پایان_اگر

#تعریف_کن RRF_RT_REG_NONE 0x00000001
#تعریف_کن RRF_RT_REG_SZ 0x00000002
#تعریف_کن RRF_RT_REG_EXPAND_SZ 0x00000004
#تعریف_کن RRF_RT_REG_دودویی 0x00000008
#تعریف_کن RRF_RT_REG_DWORD 0x00000010
#تعریف_کن RRF_RT_REG_MULTI_SZ 0x00000020
#تعریف_کن RRF_RT_REG_QWORD 0x00000040

#تعریف_کن RRF_RT_DWORD (RRF_RT_REG_دودویی | RRF_RT_REG_DWORD)
#تعریف_کن RRF_RT_QWORD (RRF_RT_REG_دودویی | RRF_RT_REG_QWORD)
#تعریف_کن RRF_RT_ANY 0x0000ffff

#تعریف_کن RRF_NOEXPAND 0x10000000
#تعریف_کن RRF_ZEROONFAILURE 0x20000000

  تعريفنوع ACCESS_ماسک REGSAM;

#تعریف_کن HKEY_CLASSES_ریشه ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#تعریف_کن HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#تعریف_کن HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#تعریف_کن HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#تعریف_کن HKEY_PERFORMANCE_داده ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#تعریف_کن HKEY_PERFORMANCE_متن ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#تعریف_کن HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#تعریف_کن HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#تعریف_کن HKEY_DYN_داده ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#تعریف_کن REG_SECURE_CONNECTION 1

#اگر_تعریف_نشده _PROVIDER_STRUCTS_DEFINED
#تعریف_کن _PROVIDER_STRUCTS_DEFINED

#تعریف_کن PROVIDER_KEEPS_مقدار_درازی 0x1
  بنية val_context {
    صحيح valuelen;
    LPVOID مقدار_context;
    LPVOID val_buff_ptr;
  };

  تعريفنوع بنية val_context *PVALCONTEXT;

  تعريفنوع بنية pvalueA {
    LPSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_مقدار_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  تعريفنوع بنية pvalueW {
    LPWSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_مقدار_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#اگر_تعریف_شده UNICODE
  تعريفنوع PVALUEW PVALUE;
  تعريفنوع PPVALUEW PPVALUE;
#وإلا
  تعريفنوع PVALUEA PVALUE;
  تعريفنوع PPVALUEA PPVALUE;
#پایان_اگر

  تعريفنوع DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD رقم_vals,LPVOID outputbuffer,DWORD *مجموع_outlen,DWORD درون_داد_blen);

  تعريفنوع QUERYHANDLER *PQUERYHANDLER;

  تعريفنوع بنية provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_کلید_context;
  } REG_PROVIDER;

  تعريفنوع بنية provider_info *PPROVIDER;

  تعريفنوع بنية مقدار_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  تعريفنوع بنية مقدار_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#اگر_تعریف_شده UNICODE
  تعريفنوع VALENTW VALENT;
  تعريفنوع PVALENTW PVALENT;
#وإلا
  تعريفنوع VALENTA VALENT;
  تعريفنوع PVALENTA PVALENT;
#پایان_اگر
#پایان_اگر

#تعریف_کن WIN31_CLASS عدم

#اگر_تعریف_شده UNICODE
#تعریف_کن RegConnectRegistry RegConnectRegistryW
#تعریف_کن RegConnectRegistryEx RegConnectRegistryExW
#تعریف_کن Reg_Create_کلید Reg_Create_کلید_W
#تعریف_کن Reg_Create_کلید_Ex Reg_Create_کلید_Ex_W
#تعریف_کن Reg_Delete_کلید Reg_Delete_کلید_W
#تعریف_کن Reg_Delete_کلید_Ex Reg_Delete_کلید_Ex_W
#تعریف_کن Reg_Delete_مقدار Reg_Delete_مقدار_W
#تعریف_کن Reg_Enum_کلید Reg_Enum_کلید_W
#تعریف_کن Reg_Enum_کلید_Ex Reg_Enum_کلید_Ex_W
#تعریف_کن Reg_Enum_مقدار Reg_Enum_مقدار_W
#تعریف_کن Reg_بارگیری_کلید Reg_بارگیری_کلید_W
#تعریف_کن Reg_Open_کلید Reg_Open_کلید_W
#تعریف_کن Reg_Open_کلید_Ex Reg_Open_کلید_Ex_W
#تعریف_کن Reg_Query_Info_کلید Reg_Query_Info_کلید_W
#تعریف_کن Reg_Query_مقدار Reg_Query_مقدار_W
#تعریف_کن Reg_Query_مضرب_مقادیر Reg_Query_مضرب_مقادیر_W
#تعریف_کن Reg_Query_مقدار_Ex Reg_Query_مقدار_Ex_W
#تعریف_کن Reg_Replace_کلید Reg_Replace_کلید_W
#تعریف_کن Reg_Restore_کلید Reg_Restore_کلید_W
#تعریف_کن Reg_Save_کلید Reg_Save_کلید_W
#تعریف_کن Reg_مجموعه_مقدار Reg_مجموعه_مقدار_W
#تعریف_کن Reg_مجموعه_مقدار_Ex Reg_مجموعه_مقدار_Ex_W
#تعریف_کن Reg_Un_بارگیری_کلید Reg_Un_بارگیری_کلید_W
#تعریف_کن Reg_Get_مقدار Reg_Get_مقدار_W
#تعریف_کن InitiateSystemShutdown InitiateSystemShutdownW
#تعریف_کن AbortSystemShutdown AbortSystemShutdownW
#وإلا
#تعریف_کن RegConnectRegistry RegConnectRegistryA
#تعریف_کن RegConnectRegistryEx RegConnectRegistryExA
#تعریف_کن Reg_Create_کلید Reg_Create_کلید_A
#تعریف_کن Reg_Create_کلید_Ex Reg_Create_کلید_Ex_A
#تعریف_کن Reg_Delete_کلید Reg_Delete_کلید_A
#تعریف_کن Reg_Delete_کلید_Ex Reg_Delete_کلید_Ex_A
#تعریف_کن Reg_Delete_مقدار Reg_Delete_مقدار_A
#تعریف_کن Reg_Enum_کلید Reg_Enum_کلید_A
#تعریف_کن Reg_Enum_کلید_Ex Reg_Enum_کلید_Ex_A
#تعریف_کن Reg_Enum_مقدار Reg_Enum_مقدار_A
#تعریف_کن Reg_بارگیری_کلید Reg_بارگیری_کلید_A
#تعریف_کن Reg_Open_کلید Reg_Open_کلید_A
#تعریف_کن Reg_Open_کلید_Ex Reg_Open_کلید_Ex_A
#تعریف_کن Reg_Query_Info_کلید Reg_Query_Info_کلید_A
#تعریف_کن Reg_Query_مقدار Reg_Query_مقدار_A
#تعریف_کن Reg_Query_مضرب_مقادیر Reg_Query_مضرب_مقادیر_A
#تعریف_کن Reg_Query_مقدار_Ex Reg_Query_مقدار_Ex_A
#تعریف_کن Reg_Replace_کلید Reg_Replace_کلید_A
#تعریف_کن Reg_Restore_کلید Reg_Restore_کلید_A
#تعریف_کن Reg_Save_کلید Reg_Save_کلید_A
#تعریف_کن Reg_مجموعه_مقدار Reg_مجموعه_مقدار_A
#تعریف_کن Reg_مجموعه_مقدار_Ex Reg_مجموعه_مقدار_Ex_A
#تعریف_کن Reg_Un_بارگیری_کلید Reg_Un_بارگیری_کلید_A
#تعریف_کن Reg_Get_مقدار Reg_Get_مقدار_A
#تعریف_کن InitiateSystemShutdown InitiateSystemShutdownA
#تعریف_کن AbortSystemShutdown AbortSystemShutdownA
#پایان_اگر

  WINADVAPI LONG WINAPI Reg_Close_کلید(HKEY h_کلید);
  WINADVAPI LONG WINAPI Reg_Override_Predef_کلید(HKEY h_کلید,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_ریشه(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_کلید,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_کلید,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_کلید,ULONG Flags,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_کلید,ULONG Flags,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI Reg_Create_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI Reg_Create_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI Reg_Create_کلید_Ex_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_صفات lp_Security_صفات,PHKEY phk_نتیجه,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_کلید_Ex_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_صفات lp_Security_صفات,PHKEY phk_نتیجه,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_Ex_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_Ex_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_کلید(HKEY h_پایه);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_کلید(HKEY h_پایه);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_کلید(HKEY h_پایه,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_مقدار_A(HKEY h_کلید,LPCSTR lp_مقدار_Name);
  WINADVAPI LONG WINAPI Reg_Delete_مقدار_W(HKEY h_کلید,LPCWSTR lp_مقدار_Name);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_A(HKEY h_کلید,DWORD dw_شاخص,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_W(HKEY h_کلید,DWORD dw_شاخص,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_Ex_A(HKEY h_کلید,DWORD dw_شاخص,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_آخرین_Write_زمان);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_Ex_W(HKEY h_کلید,DWORD dw_شاخص,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_آخرین_Write_زمان);
  WINADVAPI LONG WINAPI Reg_Enum_مقدار_A(HKEY h_کلید,DWORD dw_شاخص,LPSTR lp_مقدار_Name,LPDWORD lpcch_مقدار_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_داده,LPDWORD lpcb_داده);
  WINADVAPI LONG WINAPI Reg_Enum_مقدار_W(HKEY h_کلید,DWORD dw_شاخص,LPWSTR lp_مقدار_Name,LPDWORD lpcch_مقدار_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_داده,LPDWORD lpcb_داده);
  WINADVAPI LONG WINAPI Reg_Flush_کلید(HKEY h_کلید);
  WINADVAPI LONG WINAPI Reg_Get_کلید_Security(HKEY h_کلید,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_بارگیری_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_بارگیری_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_کلید_مقدار(HKEY h_کلید,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI Reg_Open_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI Reg_Open_کلید_Ex_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,DWORD ulOptions,REGSAM samDesired,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI Reg_Open_کلید_Ex_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,DWORD ulOptions,REGSAM samDesired,PHKEY phk_نتیجه);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلید_A(HKEY h_کلید,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیدها,LPDWORD lpcb_Max_Sub_کلید_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_مقادیر,LPDWORD lpcb_Max_مقدار_Name_Len,LPDWORD lpcb_Max_مقدار_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_آخرین_Write_زمان);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلید_W(HKEY h_کلید,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیدها,LPDWORD lpcb_Max_Sub_کلید_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_مقادیر,LPDWORD lpcb_Max_مقدار_Name_Len,LPDWORD lpcb_Max_مقدار_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_آخرین_Write_زمان);
  WINADVAPI LONG WINAPI Reg_Query_مقدار_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,LPSTR lp_داده,PLONG lpcb_داده);
  WINADVAPI LONG WINAPI Reg_Query_مقدار_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,LPWSTR lp_داده,PLONG lpcb_داده);
  WINADVAPI LONG WINAPI Reg_Query_مضرب_مقادیر_A(HKEY h_کلید,PVALENTA val_list,DWORD رقم_vals,LPSTR lp_مقدار_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_مضرب_مقادیر_W(HKEY h_کلید,PVALENTW val_list,DWORD رقم_vals,LPWSTR lp_مقدار_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_مقدار_Ex_A(HKEY h_کلید,LPCSTR lp_مقدار_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_داده,LPDWORD lpcb_داده);
  WINADVAPI LONG WINAPI Reg_Query_مقدار_Ex_W(HKEY h_کلید,LPCWSTR lp_مقدار_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_داده,LPDWORD lpcb_داده);
  WINADVAPI LONG WINAPI Reg_Replace_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_کلید_A(HKEY h_کلید,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_کلید_W(HKEY h_کلید,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_کلید_A(HKEY h_کلید,LPCSTR lpFile,LPSECURITY_صفات lp_Security_صفات);
  WINADVAPI LONG WINAPI Reg_Save_کلید_W(HKEY h_کلید,LPCWSTR lpFile,LPSECURITY_صفات lp_Security_صفات);
  WINADVAPI LONG WINAPI Reg_مجموعه_کلید_Security(HKEY h_کلید,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_مجموعه_مقدار_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,DWORD dwType,LPCSTR lp_داده,DWORD cb_داده);
  WINADVAPI LONG WINAPI Reg_مجموعه_مقدار_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,DWORD dwType,LPCWSTR lp_داده,DWORD cb_داده);
  WINADVAPI LONG WINAPI Reg_مجموعه_مقدار_Ex_A(HKEY h_کلید,LPCSTR lp_مقدار_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_داده,DWORD cb_داده);
  WINADVAPI LONG WINAPI Reg_مجموعه_مقدار_Ex_W(HKEY h_کلید,LPCWSTR lp_مقدار_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_داده,DWORD cb_داده);
  WINADVAPI LONG WINAPI Reg_Un_بارگیری_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Un_بارگیری_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Get_مقدار_A(HKEY hkey,LPCSTR lp_Sub_کلید,LPCSTR lp_مقدار,DWORD dwFlags,LPDWORD pdwType,PVOID pv_داده,LPDWORD pcb_داده);
  WINADVAPI LONG WINAPI Reg_Get_مقدار_W(HKEY hkey,LPCWSTR lp_Sub_کلید,LPCWSTR lp_مقدار,DWORD dwFlags,LPDWORD pdwType,PVOID pv_داده,LPDWORD pcb_داده);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lp_پیام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lp_پیام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#تعریف_کن REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#تعریف_کن REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#تعریف_کن REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#تعریف_کن REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#تعریف_کن REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#تعریف_کن REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#تعریف_کن REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#تعریف_کن REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#تعریف_کن REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#تعریف_کن MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#اگر_تعریف_شده UNICODE
#تعریف_کن InitiateSystemShutdownEx InitiateSystemShutdownExW
#تعریف_کن Reg_Save_کلید_Ex Reg_Save_کلید_Ex_W
#وإلا
#تعریف_کن InitiateSystemShutdownEx InitiateSystemShutdownExA
#تعریف_کن Reg_Save_کلید_Ex Reg_Save_کلید_Ex_A
#پایان_اگر

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lp_پیام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lp_پیام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_کلید_Ex_A(HKEY h_کلید,LPCSTR lpFile,LPSECURITY_صفات lp_Security_صفات,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_کلید_Ex_W(HKEY h_کلید,LPCWSTR lpFile,LPSECURITY_صفات lp_Security_صفات,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64_Win32_Api_مدخل (DWORD dw_Func_عدد,DWORD dwFlag,DWORD dwRes);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
