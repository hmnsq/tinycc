/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINREG_
#define _WINREG_

#ifdef __cplusplus
বাহ্য "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#define RRF_RT_REG_NONE 0x00000001
#define RRF_RT_REG_SZ 0x00000002
#define RRF_RT_REG_EXPAND_SZ 0x00000004
#define RRF_RT_REG_দ্বিমিক 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_দ্বিমিক | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_দ্বিমিক | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  প্রকারনির্দেশ ACCESS_MASK REGSAM;

#define HKEY_CLASSES_মূল ((HKEY) (ULONG_PTR)((LONG)0x80000000))
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

#define PROVIDER_KEEPS_মান_LENGTH 0x1
  সংরচনা val_context {
    পূর্ণাঙ্ক valuelen;
    LPVOID মান_context;
    LPVOID val_buff_ptr;
  };

  প্রকারনির্দেশ সংরচনা val_context *PVALCONTEXT;

  প্রকারনির্দেশ সংরচনা pvalueA {
    LPSTR pv_valuename;
    পূর্ণাঙ্ক pv_valuelen;
    LPVOID pv_মান_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  প্রকারনির্দেশ সংরচনা pvalueW {
    LPWSTR pv_valuename;
    পূর্ণাঙ্ক pv_valuelen;
    LPVOID pv_মান_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  প্রকারনির্দেশ PVALUEW PVALUE;
  প্রকারনির্দেশ PPVALUEW PPVALUE;
#অন্যথা
  প্রকারনির্দেশ PVALUEA PVALUE;
  প্রকারনির্দেশ PPVALUEA PPVALUE;
#endif

  প্রকারনির্দেশ DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD অঙ্ক_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD প্রবেশ_blen);

  প্রকারনির্দেশ QUERYHANDLER *PQUERYHANDLER;

  প্রকারনির্দেশ সংরচনা provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_চাবি_context;
  } REG_PROVIDER;

  প্রকারনির্দেশ সংরচনা provider_info *PPROVIDER;

  প্রকারনির্দেশ সংরচনা মান_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  প্রকারনির্দেশ সংরচনা মান_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ifdef UNICODE
  প্রকারনির্দেশ VALENTW VALENT;
  প্রকারনির্দেশ PVALENTW PVALENT;
#অন্যথা
  প্রকারনির্দেশ VALENTA VALENT;
  প্রকারনির্দেশ PVALENTA PVALENT;
#endif
#endif

#define WIN31_CLASS রিক্ত

#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#define RegConnectRegistryEx RegConnectRegistryExW
#define Reg_Create_চাবি Reg_Create_চাবি_W
#define Reg_Create_চাবি_Ex Reg_Create_চাবি_Ex_W
#define Reg_Delete_চাবি Reg_Delete_চাবি_W
#define Reg_Delete_চাবি_Ex Reg_Delete_চাবি_Ex_W
#define Reg_Delete_মান Reg_Delete_মান_W
#define Reg_Enum_চাবি Reg_Enum_চাবি_W
#define Reg_Enum_চাবি_Ex Reg_Enum_চাবি_Ex_W
#define Reg_Enum_মান Reg_Enum_মান_W
#define Reg_Load_চাবি Reg_Load_চাবি_W
#define Reg_Open_চাবি Reg_Open_চাবি_W
#define Reg_Open_চাবি_Ex Reg_Open_চাবি_Ex_W
#define Reg_Query_Info_চাবি Reg_Query_Info_চাবি_W
#define Reg_Query_মান Reg_Query_মান_W
#define Reg_Query_Multiple_মানসমূহ Reg_Query_Multiple_মানসমূহ_W
#define Reg_Query_মান_Ex Reg_Query_মান_Ex_W
#define Reg_Replace_চাবি Reg_Replace_চাবি_W
#define Reg_Restore_চাবি Reg_Restore_চাবি_W
#define Reg_Save_চাবি Reg_Save_চাবি_W
#define Reg_Set_মান Reg_Set_মান_W
#define Reg_Set_মান_Ex Reg_Set_মান_Ex_W
#define Reg_Un_Load_চাবি Reg_Un_Load_চাবি_W
#define Reg_Get_মান Reg_Get_মান_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#অন্যথা
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_চাবি Reg_Create_চাবি_A
#define Reg_Create_চাবি_Ex Reg_Create_চাবি_Ex_A
#define Reg_Delete_চাবি Reg_Delete_চাবি_A
#define Reg_Delete_চাবি_Ex Reg_Delete_চাবি_Ex_A
#define Reg_Delete_মান Reg_Delete_মান_A
#define Reg_Enum_চাবি Reg_Enum_চাবি_A
#define Reg_Enum_চাবি_Ex Reg_Enum_চাবি_Ex_A
#define Reg_Enum_মান Reg_Enum_মান_A
#define Reg_Load_চাবি Reg_Load_চাবি_A
#define Reg_Open_চাবি Reg_Open_চাবি_A
#define Reg_Open_চাবি_Ex Reg_Open_চাবি_Ex_A
#define Reg_Query_Info_চাবি Reg_Query_Info_চাবি_A
#define Reg_Query_মান Reg_Query_মান_A
#define Reg_Query_Multiple_মানসমূহ Reg_Query_Multiple_মানসমূহ_A
#define Reg_Query_মান_Ex Reg_Query_মান_Ex_A
#define Reg_Replace_চাবি Reg_Replace_চাবি_A
#define Reg_Restore_চাবি Reg_Restore_চাবি_A
#define Reg_Save_চাবি Reg_Save_চাবি_A
#define Reg_Set_মান Reg_Set_মান_A
#define Reg_Set_মান_Ex Reg_Set_মান_Ex_A
#define Reg_Un_Load_চাবি Reg_Un_Load_চাবি_A
#define Reg_Get_মান Reg_Get_মান_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_চাবি(HKEY h_চাবি);
  WINADVAPI LONG WINAPI Reg_Override_Predef_চাবি(HKEY h_চাবি,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_মূল(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_চাবি,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_চাবি,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_চাবি,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_চাবি,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_চাবি_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_চাবি_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_চাবি_Ex_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_চাবি_Ex_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_চাবি_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি);
  WINADVAPI LONG WINAPI Reg_Delete_চাবি_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি);
  WINADVAPI LONG WINAPI Reg_Delete_চাবি_Ex_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_চাবি_Ex_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_চাবি(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_চাবি(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_চাবি(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_মান_A(HKEY h_চাবি,LPCSTR lp_মান_Name);
  WINADVAPI LONG WINAPI Reg_Delete_মান_W(HKEY h_চাবি,LPCWSTR lp_মান_Name);
  WINADVAPI LONG WINAPI Reg_Enum_চাবি_A(HKEY h_চাবি,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_চাবি_W(HKEY h_চাবি,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_চাবি_Ex_A(HKEY h_চাবি,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_চাবি_Ex_W(HKEY h_চাবি,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_মান_A(HKEY h_চাবি,DWORD dwIndex,LPSTR lp_মান_Name,LPDWORD lpcch_মান_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_মান_W(HKEY h_চাবি,DWORD dwIndex,LPWSTR lp_মান_Name,LPDWORD lpcch_মান_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_চাবি(HKEY h_চাবি);
  WINADVAPI LONG WINAPI Reg_Get_চাবি_Security(HKEY h_চাবি,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_চাবি_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_চাবি_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_চাবি_মান(HKEY h_চাবি,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_চাবি_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_চাবি_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_চাবি_Ex_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_চাবি_Ex_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_চাবি_A(HKEY h_চাবি,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_চাবিগুলি,LPDWORD lpcb_Max_Sub_চাবি_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_মানসমূহ,LPDWORD lpcb_Max_মান_Name_Len,LPDWORD lpcb_Max_মান_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_চাবি_W(HKEY h_চাবি,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_চাবিগুলি,LPDWORD lpcb_Max_Sub_চাবি_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_মানসমূহ,LPDWORD lpcb_Max_মান_Name_Len,LPDWORD lpcb_Max_মান_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_মান_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_মান_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_মানসমূহ_A(HKEY h_চাবি,PVALENTA val_list,DWORD অঙ্ক_vals,LPSTR lp_মান_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_মানসমূহ_W(HKEY h_চাবি,PVALENTW val_list,DWORD অঙ্ক_vals,LPWSTR lp_মান_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_মান_Ex_A(HKEY h_চাবি,LPCSTR lp_মান_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_মান_Ex_W(HKEY h_চাবি,LPCWSTR lp_মান_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_চাবি_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_চাবি_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_চাবি_A(HKEY h_চাবি,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_চাবি_W(HKEY h_চাবি,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_চাবি_A(HKEY h_চাবি,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_চাবি_W(HKEY h_চাবি,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_চাবি_Security(HKEY h_চাবি,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_মান_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_মান_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_মান_Ex_A(HKEY h_চাবি,LPCSTR lp_মান_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_মান_Ex_W(HKEY h_চাবি,LPCWSTR lp_মান_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_চাবি_A(HKEY h_চাবি,LPCSTR lp_Sub_চাবি);
  WINADVAPI LONG WINAPI Reg_Un_Load_চাবি_W(HKEY h_চাবি,LPCWSTR lp_Sub_চাবি);
  WINADVAPI LONG WINAPI Reg_Get_মান_A(HKEY hkey,LPCSTR lp_Sub_চাবি,LPCSTR lp_মান,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_মান_W(HKEY hkey,LPCWSTR lp_Sub_চাবি,LPCWSTR lp_মান,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
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
#define Reg_Save_চাবি_Ex Reg_Save_চাবি_Ex_W
#অন্যথা
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_চাবি_Ex Reg_Save_চাবি_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_চাবি_Ex_A(HKEY h_চাবি,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_চাবি_Ex_W(HKEY h_চাবি,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_সংখ্যা,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
