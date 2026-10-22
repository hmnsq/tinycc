/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINREG_
#define _WINREG_

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#define RRF_RT_REG_NONE 0x00000001
#define RRF_RT_REG_SZ 0x00000002
#define RRF_RT_REG_EXPAND_SZ 0x00000004
#define RRF_RT_REG_ثنائي 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_ثنائي | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_ثنائي | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  تعريفنوع ACCESS_MASK REGSAM;

#define HKEY_CLASSES_جذر ((HKEY) (ULONG_PTR)((LONG)0x80000000))
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

#define PROVIDER_KEEPS_قيمة_LENGTH 0x1
  بنية val_context {
    صحيح valuelen;
    LPVOID قيمة_context;
    LPVOID val_buff_ptr;
  };

  تعريفنوع بنية val_context *PVALCONTEXT;

  تعريفنوع بنية pvalueA {
    LPSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_قيمة_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  تعريفنوع بنية pvalueW {
    LPWSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_قيمة_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  تعريفنوع PVALUEW PVALUE;
  تعريفنوع PPVALUEW PPVALUE;
#وإلا
  تعريفنوع PVALUEA PVALUE;
  تعريفنوع PPVALUEA PPVALUE;
#endif

  تعريفنوع DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD رقم_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD مدخل_blen);

  تعريفنوع QUERYHANDLER *PQUERYHANDLER;

  تعريفنوع بنية provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_مفتاح_context;
  } REG_PROVIDER;

  تعريفنوع بنية provider_info *PPROVIDER;

  تعريفنوع بنية قيمة_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  تعريفنوع بنية قيمة_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ifdef UNICODE
  تعريفنوع VALENTW VALENT;
  تعريفنوع PVALENTW PVALENT;
#وإلا
  تعريفنوع VALENTA VALENT;
  تعريفنوع PVALENTA PVALENT;
#endif
#endif

#define WIN31_CLASS عدم

#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#define RegConnectRegistryEx RegConnectRegistryExW
#define Reg_Create_مفتاح Reg_Create_مفتاح_W
#define Reg_Create_مفتاح_Ex Reg_Create_مفتاح_Ex_W
#define Reg_Delete_مفتاح Reg_Delete_مفتاح_W
#define Reg_Delete_مفتاح_Ex Reg_Delete_مفتاح_Ex_W
#define Reg_Delete_قيمة Reg_Delete_قيمة_W
#define Reg_Enum_مفتاح Reg_Enum_مفتاح_W
#define Reg_Enum_مفتاح_Ex Reg_Enum_مفتاح_Ex_W
#define Reg_Enum_قيمة Reg_Enum_قيمة_W
#define Reg_Load_مفتاح Reg_Load_مفتاح_W
#define Reg_Open_مفتاح Reg_Open_مفتاح_W
#define Reg_Open_مفتاح_Ex Reg_Open_مفتاح_Ex_W
#define Reg_Query_Info_مفتاح Reg_Query_Info_مفتاح_W
#define Reg_Query_قيمة Reg_Query_قيمة_W
#define Reg_Query_Multiple_قيم Reg_Query_Multiple_قيم_W
#define Reg_Query_قيمة_Ex Reg_Query_قيمة_Ex_W
#define Reg_Replace_مفتاح Reg_Replace_مفتاح_W
#define Reg_Restore_مفتاح Reg_Restore_مفتاح_W
#define Reg_Save_مفتاح Reg_Save_مفتاح_W
#define Reg_Set_قيمة Reg_Set_قيمة_W
#define Reg_Set_قيمة_Ex Reg_Set_قيمة_Ex_W
#define Reg_Un_Load_مفتاح Reg_Un_Load_مفتاح_W
#define Reg_Get_قيمة Reg_Get_قيمة_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#وإلا
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_مفتاح Reg_Create_مفتاح_A
#define Reg_Create_مفتاح_Ex Reg_Create_مفتاح_Ex_A
#define Reg_Delete_مفتاح Reg_Delete_مفتاح_A
#define Reg_Delete_مفتاح_Ex Reg_Delete_مفتاح_Ex_A
#define Reg_Delete_قيمة Reg_Delete_قيمة_A
#define Reg_Enum_مفتاح Reg_Enum_مفتاح_A
#define Reg_Enum_مفتاح_Ex Reg_Enum_مفتاح_Ex_A
#define Reg_Enum_قيمة Reg_Enum_قيمة_A
#define Reg_Load_مفتاح Reg_Load_مفتاح_A
#define Reg_Open_مفتاح Reg_Open_مفتاح_A
#define Reg_Open_مفتاح_Ex Reg_Open_مفتاح_Ex_A
#define Reg_Query_Info_مفتاح Reg_Query_Info_مفتاح_A
#define Reg_Query_قيمة Reg_Query_قيمة_A
#define Reg_Query_Multiple_قيم Reg_Query_Multiple_قيم_A
#define Reg_Query_قيمة_Ex Reg_Query_قيمة_Ex_A
#define Reg_Replace_مفتاح Reg_Replace_مفتاح_A
#define Reg_Restore_مفتاح Reg_Restore_مفتاح_A
#define Reg_Save_مفتاح Reg_Save_مفتاح_A
#define Reg_Set_قيمة Reg_Set_قيمة_A
#define Reg_Set_قيمة_Ex Reg_Set_قيمة_Ex_A
#define Reg_Un_Load_مفتاح Reg_Un_Load_مفتاح_A
#define Reg_Get_قيمة Reg_Get_قيمة_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_مفتاح(HKEY h_مفتاح);
  WINADVAPI LONG WINAPI Reg_Override_Predef_مفتاح(HKEY h_مفتاح,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_جذر(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_مفتاح,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_مفتاح,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_مفتاح,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_مفتاح,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_مفتاح_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_مفتاح_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_مفتاح_Ex_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_مفتاح_Ex_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_مفتاح_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح);
  WINADVAPI LONG WINAPI Reg_Delete_مفتاح_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح);
  WINADVAPI LONG WINAPI Reg_Delete_مفتاح_Ex_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_مفتاح_Ex_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_مفتاح(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_مفتاح(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_مفتاح(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_قيمة_A(HKEY h_مفتاح,LPCSTR lp_قيمة_Name);
  WINADVAPI LONG WINAPI Reg_Delete_قيمة_W(HKEY h_مفتاح,LPCWSTR lp_قيمة_Name);
  WINADVAPI LONG WINAPI Reg_Enum_مفتاح_A(HKEY h_مفتاح,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_مفتاح_W(HKEY h_مفتاح,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_مفتاح_Ex_A(HKEY h_مفتاح,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_مفتاح_Ex_W(HKEY h_مفتاح,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_قيمة_A(HKEY h_مفتاح,DWORD dwIndex,LPSTR lp_قيمة_Name,LPDWORD lpcch_قيمة_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_قيمة_W(HKEY h_مفتاح,DWORD dwIndex,LPWSTR lp_قيمة_Name,LPDWORD lpcch_قيمة_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_مفتاح(HKEY h_مفتاح);
  WINADVAPI LONG WINAPI Reg_Get_مفتاح_Security(HKEY h_مفتاح,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_مفتاح_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_مفتاح_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_مفتاح_قيمة(HKEY h_مفتاح,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_مفتاح_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_مفتاح_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_مفتاح_Ex_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_مفتاح_Ex_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_مفتاح_A(HKEY h_مفتاح,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_مفاتيح,LPDWORD lpcb_Max_Sub_مفتاح_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_قيم,LPDWORD lpcb_Max_قيمة_Name_Len,LPDWORD lpcb_Max_قيمة_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_مفتاح_W(HKEY h_مفتاح,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_مفاتيح,LPDWORD lpcb_Max_Sub_مفتاح_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_قيم,LPDWORD lpcb_Max_قيمة_Name_Len,LPDWORD lpcb_Max_قيمة_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_قيمة_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_قيمة_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_قيم_A(HKEY h_مفتاح,PVALENTA val_list,DWORD رقم_vals,LPSTR lp_قيمة_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_قيم_W(HKEY h_مفتاح,PVALENTW val_list,DWORD رقم_vals,LPWSTR lp_قيمة_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_قيمة_Ex_A(HKEY h_مفتاح,LPCSTR lp_قيمة_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_قيمة_Ex_W(HKEY h_مفتاح,LPCWSTR lp_قيمة_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_مفتاح_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_مفتاح_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_مفتاح_A(HKEY h_مفتاح,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_مفتاح_W(HKEY h_مفتاح,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_مفتاح_A(HKEY h_مفتاح,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_مفتاح_W(HKEY h_مفتاح,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_مفتاح_Security(HKEY h_مفتاح,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_قيمة_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_قيمة_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_قيمة_Ex_A(HKEY h_مفتاح,LPCSTR lp_قيمة_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_قيمة_Ex_W(HKEY h_مفتاح,LPCWSTR lp_قيمة_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_مفتاح_A(HKEY h_مفتاح,LPCSTR lp_Sub_مفتاح);
  WINADVAPI LONG WINAPI Reg_Un_Load_مفتاح_W(HKEY h_مفتاح,LPCWSTR lp_Sub_مفتاح);
  WINADVAPI LONG WINAPI Reg_Get_قيمة_A(HKEY hkey,LPCSTR lp_Sub_مفتاح,LPCSTR lp_قيمة,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_قيمة_W(HKEY hkey,LPCWSTR lp_Sub_مفتاح,LPCWSTR lp_قيمة,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
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
#define Reg_Save_مفتاح_Ex Reg_Save_مفتاح_Ex_W
#وإلا
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_مفتاح_Ex Reg_Save_مفتاح_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_مفتاح_Ex_A(HKEY h_مفتاح,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_مفتاح_Ex_W(HKEY h_مفتاح,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_رقم,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
