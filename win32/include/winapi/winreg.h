/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINREG_
#define _WINREG_

#ifdef __cplusplus
بیرونی "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#define RRF_RT_REG_NONE 0x00000001
#define RRF_RT_REG_SZ 0x00000002
#define RRF_RT_REG_EXPAND_SZ 0x00000004
#define RRF_RT_REG_دودویی 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_دودویی | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_دودویی | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  تعریفنوع ACCESS_MASK REGSAM;

#define HKEY_CLASSES_ریشه ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#define HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#define HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#define HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#define HKEY_PERFORMANCE_DATA ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#define HKEY_PERFORMANCE_TEXT ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#define HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#define HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#define HKEY_DYN_DATA ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#define REG_SECURE_CONNECTION 1

#ifndef _PROVIDER_STRUCTS_DEFINED
#define _PROVIDER_STRUCTS_DEFINED

#define PROVIDER_KEEPS_مقدار_LENGTH 0x1
  ساختار val_context {
    صحیح valuelen;
    LPVOID مقدار_context;
    LPVOID val_buff_ptr;
  };

  تعریفنوع ساختار val_context *PVALCONTEXT;

  تعریفنوع ساختار pvalueA {
    LPSTR pv_valuename;
    صحیح pv_valuelen;
    LPVOID pv_مقدار_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  تعریفنوع ساختار pvalueW {
    LPWSTR pv_valuename;
    صحیح pv_valuelen;
    LPVOID pv_مقدار_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  تعریفنوع PVALUEW PVALUE;
  تعریفنوع PPVALUEW PPVALUE;
#وگرنه
  تعریفنوع PVALUEA PVALUE;
  تعریفنوع PPVALUEA PPVALUE;
#endif

  تعریفنوع DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD رقم_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD درون_داد_blen);

  تعریفنوع QUERYHANDLER *PQUERYHANDLER;

  تعریفنوع ساختار provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_کلید_context;
  } REG_PROVIDER;

  تعریفنوع ساختار provider_info *PPROVIDER;

  تعریفنوع ساختار مقدار_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  تعریفنوع ساختار مقدار_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ifdef UNICODE
  تعریفنوع VALENTW VALENT;
  تعریفنوع PVALENTW PVALENT;
#وگرنه
  تعریفنوع VALENTA VALENT;
  تعریفنوع PVALENTA PVALENT;
#endif
#endif

#define WIN31_CLASS پوچ

#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#define RegConnectRegistryEx RegConnectRegistryExW
#define Reg_Create_کلید Reg_Create_کلید_W
#define Reg_Create_کلید_Ex Reg_Create_کلید_Ex_W
#define Reg_Delete_کلید Reg_Delete_کلید_W
#define Reg_Delete_کلید_Ex Reg_Delete_کلید_Ex_W
#define Reg_Delete_مقدار Reg_Delete_مقدار_W
#define Reg_Enum_کلید Reg_Enum_کلید_W
#define Reg_Enum_کلید_Ex Reg_Enum_کلید_Ex_W
#define Reg_Enum_مقدار Reg_Enum_مقدار_W
#define Reg_Load_کلید Reg_Load_کلید_W
#define Reg_Open_کلید Reg_Open_کلید_W
#define Reg_Open_کلید_Ex Reg_Open_کلید_Ex_W
#define Reg_Query_Info_کلید Reg_Query_Info_کلید_W
#define Reg_Query_مقدار Reg_Query_مقدار_W
#define Reg_Query_Multiple_مقادیر Reg_Query_Multiple_مقادیر_W
#define Reg_Query_مقدار_Ex Reg_Query_مقدار_Ex_W
#define Reg_Replace_کلید Reg_Replace_کلید_W
#define Reg_Restore_کلید Reg_Restore_کلید_W
#define Reg_Save_کلید Reg_Save_کلید_W
#define Reg_Set_مقدار Reg_Set_مقدار_W
#define Reg_Set_مقدار_Ex Reg_Set_مقدار_Ex_W
#define Reg_Un_Load_کلید Reg_Un_Load_کلید_W
#define Reg_Get_مقدار Reg_Get_مقدار_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#وگرنه
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_کلید Reg_Create_کلید_A
#define Reg_Create_کلید_Ex Reg_Create_کلید_Ex_A
#define Reg_Delete_کلید Reg_Delete_کلید_A
#define Reg_Delete_کلید_Ex Reg_Delete_کلید_Ex_A
#define Reg_Delete_مقدار Reg_Delete_مقدار_A
#define Reg_Enum_کلید Reg_Enum_کلید_A
#define Reg_Enum_کلید_Ex Reg_Enum_کلید_Ex_A
#define Reg_Enum_مقدار Reg_Enum_مقدار_A
#define Reg_Load_کلید Reg_Load_کلید_A
#define Reg_Open_کلید Reg_Open_کلید_A
#define Reg_Open_کلید_Ex Reg_Open_کلید_Ex_A
#define Reg_Query_Info_کلید Reg_Query_Info_کلید_A
#define Reg_Query_مقدار Reg_Query_مقدار_A
#define Reg_Query_Multiple_مقادیر Reg_Query_Multiple_مقادیر_A
#define Reg_Query_مقدار_Ex Reg_Query_مقدار_Ex_A
#define Reg_Replace_کلید Reg_Replace_کلید_A
#define Reg_Restore_کلید Reg_Restore_کلید_A
#define Reg_Save_کلید Reg_Save_کلید_A
#define Reg_Set_مقدار Reg_Set_مقدار_A
#define Reg_Set_مقدار_Ex Reg_Set_مقدار_Ex_A
#define Reg_Un_Load_کلید Reg_Un_Load_کلید_A
#define Reg_Get_مقدار Reg_Get_مقدار_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_کلید(HKEY h_کلید);
  WINADVAPI LONG WINAPI Reg_Override_Predef_کلید(HKEY h_کلید,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_ریشه(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_کلید,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_کلید,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_کلید,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_کلید,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_کلید_Ex_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_کلید_Ex_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_Ex_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_Ex_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_کلید(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_کلید(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_کلید(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_مقدار_A(HKEY h_کلید,LPCSTR lp_مقدار_Name);
  WINADVAPI LONG WINAPI Reg_Delete_مقدار_W(HKEY h_کلید,LPCWSTR lp_مقدار_Name);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_A(HKEY h_کلید,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_W(HKEY h_کلید,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_Ex_A(HKEY h_کلید,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_Ex_W(HKEY h_کلید,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_مقدار_A(HKEY h_کلید,DWORD dwIndex,LPSTR lp_مقدار_Name,LPDWORD lpcch_مقدار_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_مقدار_W(HKEY h_کلید,DWORD dwIndex,LPWSTR lp_مقدار_Name,LPDWORD lpcch_مقدار_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_کلید(HKEY h_کلید);
  WINADVAPI LONG WINAPI Reg_Get_کلید_Security(HKEY h_کلید,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_کلید_مقدار(HKEY h_کلید,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_کلید_Ex_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_کلید_Ex_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلید_A(HKEY h_کلید,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیدها,LPDWORD lpcb_Max_Sub_کلید_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_مقادیر,LPDWORD lpcb_Max_مقدار_Name_Len,LPDWORD lpcb_Max_مقدار_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلید_W(HKEY h_کلید,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیدها,LPDWORD lpcb_Max_Sub_کلید_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_مقادیر,LPDWORD lpcb_Max_مقدار_Name_Len,LPDWORD lpcb_Max_مقدار_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_مقدار_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_مقدار_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_مقادیر_A(HKEY h_کلید,PVALENTA val_list,DWORD رقم_vals,LPSTR lp_مقدار_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_مقادیر_W(HKEY h_کلید,PVALENTW val_list,DWORD رقم_vals,LPWSTR lp_مقدار_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_مقدار_Ex_A(HKEY h_کلید,LPCSTR lp_مقدار_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_مقدار_Ex_W(HKEY h_کلید,LPCWSTR lp_مقدار_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_کلید_A(HKEY h_کلید,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_کلید_W(HKEY h_کلید,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_کلید_A(HKEY h_کلید,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_کلید_W(HKEY h_کلید,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_کلید_Security(HKEY h_کلید,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_مقدار_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_مقدار_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_مقدار_Ex_A(HKEY h_کلید,LPCSTR lp_مقدار_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_مقدار_Ex_W(HKEY h_کلید,LPCWSTR lp_مقدار_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Un_Load_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Get_مقدار_A(HKEY hkey,LPCSTR lp_Sub_کلید,LPCSTR lp_مقدار,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_مقدار_W(HKEY hkey,LPCWSTR lp_Sub_کلید,LPCWSTR lp_مقدار,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#define REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#define REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#define REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#define REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#define REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#define REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#define REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#define REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#define REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#define MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#ifdef UNICODE
#define InitiateSystemShutdownEx InitiateSystemShutdownExW
#define Reg_Save_کلید_Ex Reg_Save_کلید_Ex_W
#وگرنه
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_کلید_Ex Reg_Save_کلید_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_کلید_Ex_A(HKEY h_کلید,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_کلید_Ex_W(HKEY h_کلید,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_عدد,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
