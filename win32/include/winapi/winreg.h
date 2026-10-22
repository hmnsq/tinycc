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
#define RRF_RT_REG_دووانەیی 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_دووانەیی | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_دووانەیی | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  تعريفنوع ACCESS_MASK REGSAM;

#define HKEY_CLASSES_ڕەگ ((HKEY) (ULONG_PTR)((LONG)0x80000000))
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

#define PROVIDER_KEEPS_بەها_LENGTH 0x1
  بنية val_context {
    صحيح valuelen;
    LPVOID بەها_context;
    LPVOID val_buff_ptr;
  };

  تعريفنوع بنية val_context *PVALCONTEXT;

  تعريفنوع بنية pvalueA {
    LPSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_بەها_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  تعريفنوع بنية pvalueW {
    LPWSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_بەها_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  تعريفنوع PVALUEW PVALUE;
  تعريفنوع PPVALUEW PPVALUE;
#وإلا
  تعريفنوع PVALUEA PVALUE;
  تعريفنوع PPVALUEA PPVALUE;
#endif

  تعريفنوع DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD ژمارە_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD تێخستن_blen);

  تعريفنوع QUERYHANDLER *PQUERYHANDLER;

  تعريفنوع بنية provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_کلیل_context;
  } REG_PROVIDER;

  تعريفنوع بنية provider_info *PPROVIDER;

  تعريفنوع بنية بەها_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  تعريفنوع بنية بەها_ent_W {
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
#define Reg_Create_کلیل Reg_Create_کلیل_W
#define Reg_Create_کلیل_Ex Reg_Create_کلیل_Ex_W
#define Reg_Delete_کلیل Reg_Delete_کلیل_W
#define Reg_Delete_کلیل_Ex Reg_Delete_کلیل_Ex_W
#define Reg_Delete_بەها Reg_Delete_بەها_W
#define Reg_Enum_کلیل Reg_Enum_کلیل_W
#define Reg_Enum_کلیل_Ex Reg_Enum_کلیل_Ex_W
#define Reg_Enum_بەها Reg_Enum_بەها_W
#define Reg_Load_کلیل Reg_Load_کلیل_W
#define Reg_Open_کلیل Reg_Open_کلیل_W
#define Reg_Open_کلیل_Ex Reg_Open_کلیل_Ex_W
#define Reg_Query_Info_کلیل Reg_Query_Info_کلیل_W
#define Reg_Query_بەها Reg_Query_بەها_W
#define Reg_Query_Multiple_بەهاکان Reg_Query_Multiple_بەهاکان_W
#define Reg_Query_بەها_Ex Reg_Query_بەها_Ex_W
#define Reg_Replace_کلیل Reg_Replace_کلیل_W
#define Reg_Restore_کلیل Reg_Restore_کلیل_W
#define Reg_Save_کلیل Reg_Save_کلیل_W
#define Reg_Set_بەها Reg_Set_بەها_W
#define Reg_Set_بەها_Ex Reg_Set_بەها_Ex_W
#define Reg_Un_Load_کلیل Reg_Un_Load_کلیل_W
#define Reg_Get_بەها Reg_Get_بەها_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#وإلا
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_کلیل Reg_Create_کلیل_A
#define Reg_Create_کلیل_Ex Reg_Create_کلیل_Ex_A
#define Reg_Delete_کلیل Reg_Delete_کلیل_A
#define Reg_Delete_کلیل_Ex Reg_Delete_کلیل_Ex_A
#define Reg_Delete_بەها Reg_Delete_بەها_A
#define Reg_Enum_کلیل Reg_Enum_کلیل_A
#define Reg_Enum_کلیل_Ex Reg_Enum_کلیل_Ex_A
#define Reg_Enum_بەها Reg_Enum_بەها_A
#define Reg_Load_کلیل Reg_Load_کلیل_A
#define Reg_Open_کلیل Reg_Open_کلیل_A
#define Reg_Open_کلیل_Ex Reg_Open_کلیل_Ex_A
#define Reg_Query_Info_کلیل Reg_Query_Info_کلیل_A
#define Reg_Query_بەها Reg_Query_بەها_A
#define Reg_Query_Multiple_بەهاکان Reg_Query_Multiple_بەهاکان_A
#define Reg_Query_بەها_Ex Reg_Query_بەها_Ex_A
#define Reg_Replace_کلیل Reg_Replace_کلیل_A
#define Reg_Restore_کلیل Reg_Restore_کلیل_A
#define Reg_Save_کلیل Reg_Save_کلیل_A
#define Reg_Set_بەها Reg_Set_بەها_A
#define Reg_Set_بەها_Ex Reg_Set_بەها_Ex_A
#define Reg_Un_Load_کلیل Reg_Un_Load_کلیل_A
#define Reg_Get_بەها Reg_Get_بەها_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_کلیل(HKEY h_کلیل);
  WINADVAPI LONG WINAPI Reg_Override_Predef_کلیل(HKEY h_کلیل,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_ڕەگ(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_کلیل,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_کلیل,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_کلیل,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_کلیل,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_کلیل_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_کلیل_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_کلیل_Ex_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_کلیل_Ex_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_کلیل_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل);
  WINADVAPI LONG WINAPI Reg_Delete_کلیل_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل);
  WINADVAPI LONG WINAPI Reg_Delete_کلیل_Ex_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_کلیل_Ex_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_کلیل(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_کلیل(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_کلیل(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_بەها_A(HKEY h_کلیل,LPCSTR lp_بەها_Name);
  WINADVAPI LONG WINAPI Reg_Delete_بەها_W(HKEY h_کلیل,LPCWSTR lp_بەها_Name);
  WINADVAPI LONG WINAPI Reg_Enum_کلیل_A(HKEY h_کلیل,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلیل_W(HKEY h_کلیل,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلیل_Ex_A(HKEY h_کلیل,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_کلیل_Ex_W(HKEY h_کلیل,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_بەها_A(HKEY h_کلیل,DWORD dwIndex,LPSTR lp_بەها_Name,LPDWORD lpcch_بەها_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_بەها_W(HKEY h_کلیل,DWORD dwIndex,LPWSTR lp_بەها_Name,LPDWORD lpcch_بەها_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_کلیل(HKEY h_کلیل);
  WINADVAPI LONG WINAPI Reg_Get_کلیل_Security(HKEY h_کلیل,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_کلیل_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_کلیل_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_کلیل_بەها(HKEY h_کلیل,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_کلیل_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_کلیل_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_کلیل_Ex_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_کلیل_Ex_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلیل_A(HKEY h_کلیل,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیلەکان,LPDWORD lpcb_Max_Sub_کلیل_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_بەهاکان,LPDWORD lpcb_Max_بەها_Name_Len,LPDWORD lpcb_Max_بەها_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلیل_W(HKEY h_کلیل,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیلەکان,LPDWORD lpcb_Max_Sub_کلیل_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_بەهاکان,LPDWORD lpcb_Max_بەها_Name_Len,LPDWORD lpcb_Max_بەها_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_بەها_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_بەها_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_بەهاکان_A(HKEY h_کلیل,PVALENTA val_list,DWORD ژمارە_vals,LPSTR lp_بەها_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_بەهاکان_W(HKEY h_کلیل,PVALENTW val_list,DWORD ژمارە_vals,LPWSTR lp_بەها_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_بەها_Ex_A(HKEY h_کلیل,LPCSTR lp_بەها_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_بەها_Ex_W(HKEY h_کلیل,LPCWSTR lp_بەها_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_کلیل_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_کلیل_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_کلیل_A(HKEY h_کلیل,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_کلیل_W(HKEY h_کلیل,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_کلیل_A(HKEY h_کلیل,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_کلیل_W(HKEY h_کلیل,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_کلیل_Security(HKEY h_کلیل,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_بەها_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_بەها_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_بەها_Ex_A(HKEY h_کلیل,LPCSTR lp_بەها_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_بەها_Ex_W(HKEY h_کلیل,LPCWSTR lp_بەها_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_کلیل_A(HKEY h_کلیل,LPCSTR lp_Sub_کلیل);
  WINADVAPI LONG WINAPI Reg_Un_Load_کلیل_W(HKEY h_کلیل,LPCWSTR lp_Sub_کلیل);
  WINADVAPI LONG WINAPI Reg_Get_بەها_A(HKEY hkey,LPCSTR lp_Sub_کلیل,LPCSTR lp_بەها,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_بەها_W(HKEY hkey,LPCWSTR lp_Sub_کلیل,LPCWSTR lp_بەها,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
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
#define Reg_Save_کلیل_Ex Reg_Save_کلیل_Ex_W
#وإلا
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_کلیل_Ex Reg_Save_کلیل_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_کلیل_Ex_A(HKEY h_کلیل,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_کلیل_Ex_W(HKEY h_کلیل,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_ژمار,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
