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
#define RRF_RT_REG_نبيو 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_نبيو | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_نبيو | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  تعريفنوع ACCESS_MASK REGSAM;

#define HKEY_CLASSES_سيو ((HKEY) (ULONG_PTR)((LONG)0x80000000))
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

#define PROVIDER_KEEPS_درج_LENGTH 0x1
  بنية val_context {
    صحيح valuelen;
    LPVOID درج_context;
    LPVOID val_buff_ptr;
  };

  تعريفنوع بنية val_context *PVALCONTEXT;

  تعريفنوع بنية pvalueA {
    LPSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_درج_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  تعريفنوع بنية pvalueW {
    LPWSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_درج_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  تعريفنوع PVALUEW PVALUE;
  تعريفنوع PPVALUEW PPVALUE;
#وإلا
  تعريفنوع PVALUEA PVALUE;
  تعريفنوع PPVALUEA PPVALUE;
#endif

  تعريفنوع DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD لمب_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD شغرو_blen);

  تعريفنوع QUERYHANDLER *PQUERYHANDLER;

  تعريفنوع بنية provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_مبودي_context;
  } REG_PROVIDER;

  تعريفنوع بنية provider_info *PPROVIDER;

  تعريفنوع بنية درج_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  تعريفنوع بنية درج_ent_W {
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
#define Reg_Create_مبودي Reg_Create_مبودي_W
#define Reg_Create_مبودي_Ex Reg_Create_مبودي_Ex_W
#define Reg_Delete_مبودي Reg_Delete_مبودي_W
#define Reg_Delete_مبودي_Ex Reg_Delete_مبودي_Ex_W
#define Reg_Delete_درج Reg_Delete_درج_W
#define Reg_Enum_مبودي Reg_Enum_مبودي_W
#define Reg_Enum_مبودي_Ex Reg_Enum_مبودي_Ex_W
#define Reg_Enum_درج Reg_Enum_درج_W
#define Reg_Load_مبودي Reg_Load_مبودي_W
#define Reg_Open_مبودي Reg_Open_مبودي_W
#define Reg_Open_مبودي_Ex Reg_Open_مبودي_Ex_W
#define Reg_Query_Info_مبودي Reg_Query_Info_مبودي_W
#define Reg_Query_درج Reg_Query_درج_W
#define Reg_Query_Multiple_درجوجي Reg_Query_Multiple_درجوجي_W
#define Reg_Query_درج_Ex Reg_Query_درج_Ex_W
#define Reg_Replace_مبودي Reg_Replace_مبودي_W
#define Reg_Restore_مبودي Reg_Restore_مبودي_W
#define Reg_Save_مبودي Reg_Save_مبودي_W
#define Reg_Set_درج Reg_Set_درج_W
#define Reg_Set_درج_Ex Reg_Set_درج_Ex_W
#define Reg_Un_Load_مبودي Reg_Un_Load_مبودي_W
#define Reg_Get_درج Reg_Get_درج_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#وإلا
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_مبودي Reg_Create_مبودي_A
#define Reg_Create_مبودي_Ex Reg_Create_مبودي_Ex_A
#define Reg_Delete_مبودي Reg_Delete_مبودي_A
#define Reg_Delete_مبودي_Ex Reg_Delete_مبودي_Ex_A
#define Reg_Delete_درج Reg_Delete_درج_A
#define Reg_Enum_مبودي Reg_Enum_مبودي_A
#define Reg_Enum_مبودي_Ex Reg_Enum_مبودي_Ex_A
#define Reg_Enum_درج Reg_Enum_درج_A
#define Reg_Load_مبودي Reg_Load_مبودي_A
#define Reg_Open_مبودي Reg_Open_مبودي_A
#define Reg_Open_مبودي_Ex Reg_Open_مبودي_Ex_A
#define Reg_Query_Info_مبودي Reg_Query_Info_مبودي_A
#define Reg_Query_درج Reg_Query_درج_A
#define Reg_Query_Multiple_درجوجي Reg_Query_Multiple_درجوجي_A
#define Reg_Query_درج_Ex Reg_Query_درج_Ex_A
#define Reg_Replace_مبودي Reg_Replace_مبودي_A
#define Reg_Restore_مبودي Reg_Restore_مبودي_A
#define Reg_Save_مبودي Reg_Save_مبودي_A
#define Reg_Set_درج Reg_Set_درج_A
#define Reg_Set_درج_Ex Reg_Set_درج_Ex_A
#define Reg_Un_Load_مبودي Reg_Un_Load_مبودي_A
#define Reg_Get_درج Reg_Get_درج_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_مبودي(HKEY h_مبودي);
  WINADVAPI LONG WINAPI Reg_Override_Predef_مبودي(HKEY h_مبودي,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_سيو(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_مبودي,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_مبودي,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_مبودي,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_مبودي,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_مبودي_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_مبودي_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_مبودي_Ex_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_مبودي_Ex_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_مبودي_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي);
  WINADVAPI LONG WINAPI Reg_Delete_مبودي_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي);
  WINADVAPI LONG WINAPI Reg_Delete_مبودي_Ex_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_مبودي_Ex_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_مبودي(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_مبودي(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_مبودي(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_درج_A(HKEY h_مبودي,LPCSTR lp_درج_Name);
  WINADVAPI LONG WINAPI Reg_Delete_درج_W(HKEY h_مبودي,LPCWSTR lp_درج_Name);
  WINADVAPI LONG WINAPI Reg_Enum_مبودي_A(HKEY h_مبودي,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_مبودي_W(HKEY h_مبودي,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_مبودي_Ex_A(HKEY h_مبودي,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_مبودي_Ex_W(HKEY h_مبودي,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_درج_A(HKEY h_مبودي,DWORD dwIndex,LPSTR lp_درج_Name,LPDWORD lpcch_درج_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_درج_W(HKEY h_مبودي,DWORD dwIndex,LPWSTR lp_درج_Name,LPDWORD lpcch_درج_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_مبودي(HKEY h_مبودي);
  WINADVAPI LONG WINAPI Reg_Get_مبودي_Security(HKEY h_مبودي,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_مبودي_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_مبودي_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_مبودي_درج(HKEY h_مبودي,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_مبودي_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_مبودي_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_مبودي_Ex_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_مبودي_Ex_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_مبودي_A(HKEY h_مبودي,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_مبوداي,LPDWORD lpcb_Max_Sub_مبودي_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_درجوجي,LPDWORD lpcb_Max_درج_Name_Len,LPDWORD lpcb_Max_درج_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_مبودي_W(HKEY h_مبودي,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_مبوداي,LPDWORD lpcb_Max_Sub_مبودي_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_درجوجي,LPDWORD lpcb_Max_درج_Name_Len,LPDWORD lpcb_Max_درج_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_درج_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_درج_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_درجوجي_A(HKEY h_مبودي,PVALENTA val_list,DWORD لمب_vals,LPSTR lp_درج_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_درجوجي_W(HKEY h_مبودي,PVALENTW val_list,DWORD لمب_vals,LPWSTR lp_درج_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_درج_Ex_A(HKEY h_مبودي,LPCSTR lp_درج_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_درج_Ex_W(HKEY h_مبودي,LPCWSTR lp_درج_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_مبودي_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_مبودي_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_مبودي_A(HKEY h_مبودي,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_مبودي_W(HKEY h_مبودي,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_مبودي_A(HKEY h_مبودي,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_مبودي_W(HKEY h_مبودي,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_مبودي_Security(HKEY h_مبودي,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_درج_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_درج_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_درج_Ex_A(HKEY h_مبودي,LPCSTR lp_درج_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_درج_Ex_W(HKEY h_مبودي,LPCWSTR lp_درج_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_مبودي_A(HKEY h_مبودي,LPCSTR lp_Sub_مبودي);
  WINADVAPI LONG WINAPI Reg_Un_Load_مبودي_W(HKEY h_مبودي,LPCWSTR lp_Sub_مبودي);
  WINADVAPI LONG WINAPI Reg_Get_درج_A(HKEY hkey,LPCSTR lp_Sub_مبودي,LPCSTR lp_درج,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_درج_W(HKEY hkey,LPCWSTR lp_Sub_مبودي,LPCWSTR lp_درج,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
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
#define Reg_Save_مبودي_Ex Reg_Save_مبودي_Ex_W
#وإلا
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_مبودي_Ex Reg_Save_مبودي_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_مبودي_Ex_A(HKEY h_مبودي,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_مبودي_Ex_W(HKEY h_مبودي,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_لمب,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
