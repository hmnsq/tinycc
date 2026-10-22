/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINREG_
#define _WINREG_

#ifdef __cplusplus
बाह्य "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#define RRF_RT_REG_NONE 0x00000001
#define RRF_RT_REG_SZ 0x00000002
#define RRF_RT_REG_EXPAND_SZ 0x00000004
#define RRF_RT_REG_द्विआधारी 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_द्विआधारी | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_द्विआधारी | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  प्रकारनिर्देश ACCESS_MASK REGSAM;

#define HKEY_CLASSES_जरा ((HKEY) (ULONG_PTR)((LONG)0x80000000))
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

#define PROVIDER_KEEPS_मान_LENGTH 0x1
  संरचना val_context {
    पूर्णाङ्क valuelen;
    LPVOID मान_context;
    LPVOID val_buff_ptr;
  };

  प्रकारनिर्देश संरचना val_context *PVALCONTEXT;

  प्रकारनिर्देश संरचना pvalueA {
    LPSTR pv_valuename;
    पूर्णाङ्क pv_valuelen;
    LPVOID pv_मान_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  प्रकारनिर्देश संरचना pvalueW {
    LPWSTR pv_valuename;
    पूर्णाङ्क pv_valuelen;
    LPVOID pv_मान_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  प्रकारनिर्देश PVALUEW PVALUE;
  प्रकारनिर्देश PPVALUEW PPVALUE;
#अन्यथा
  प्रकारनिर्देश PVALUEA PVALUE;
  प्रकारनिर्देश PPVALUEA PPVALUE;
#endif

  प्रकारनिर्देश DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD अङ्क_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD आगत_blen);

  प्रकारनिर्देश QUERYHANDLER *PQUERYHANDLER;

  प्रकारनिर्देश संरचना provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_साँचो_context;
  } REG_PROVIDER;

  प्रकारनिर्देश संरचना provider_info *PPROVIDER;

  प्रकारनिर्देश संरचना मान_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  प्रकारनिर्देश संरचना मान_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ifdef UNICODE
  प्रकारनिर्देश VALENTW VALENT;
  प्रकारनिर्देश PVALENTW PVALENT;
#अन्यथा
  प्रकारनिर्देश VALENTA VALENT;
  प्रकारनिर्देश PVALENTA PVALENT;
#endif
#endif

#define WIN31_CLASS रिक्त

#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#define RegConnectRegistryEx RegConnectRegistryExW
#define Reg_Create_साँचो Reg_Create_साँचो_W
#define Reg_Create_साँचो_Ex Reg_Create_साँचो_Ex_W
#define Reg_Delete_साँचो Reg_Delete_साँचो_W
#define Reg_Delete_साँचो_Ex Reg_Delete_साँचो_Ex_W
#define Reg_Delete_मान Reg_Delete_मान_W
#define Reg_Enum_साँचो Reg_Enum_साँचो_W
#define Reg_Enum_साँचो_Ex Reg_Enum_साँचो_Ex_W
#define Reg_Enum_मान Reg_Enum_मान_W
#define Reg_Load_साँचो Reg_Load_साँचो_W
#define Reg_Open_साँचो Reg_Open_साँचो_W
#define Reg_Open_साँचो_Ex Reg_Open_साँचो_Ex_W
#define Reg_Query_Info_साँचो Reg_Query_Info_साँचो_W
#define Reg_Query_मान Reg_Query_मान_W
#define Reg_Query_Multiple_मानहरू Reg_Query_Multiple_मानहरू_W
#define Reg_Query_मान_Ex Reg_Query_मान_Ex_W
#define Reg_Replace_साँचो Reg_Replace_साँचो_W
#define Reg_Restore_साँचो Reg_Restore_साँचो_W
#define Reg_Save_साँचो Reg_Save_साँचो_W
#define Reg_Set_मान Reg_Set_मान_W
#define Reg_Set_मान_Ex Reg_Set_मान_Ex_W
#define Reg_Un_Load_साँचो Reg_Un_Load_साँचो_W
#define Reg_Get_मान Reg_Get_मान_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#अन्यथा
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_साँचो Reg_Create_साँचो_A
#define Reg_Create_साँचो_Ex Reg_Create_साँचो_Ex_A
#define Reg_Delete_साँचो Reg_Delete_साँचो_A
#define Reg_Delete_साँचो_Ex Reg_Delete_साँचो_Ex_A
#define Reg_Delete_मान Reg_Delete_मान_A
#define Reg_Enum_साँचो Reg_Enum_साँचो_A
#define Reg_Enum_साँचो_Ex Reg_Enum_साँचो_Ex_A
#define Reg_Enum_मान Reg_Enum_मान_A
#define Reg_Load_साँचो Reg_Load_साँचो_A
#define Reg_Open_साँचो Reg_Open_साँचो_A
#define Reg_Open_साँचो_Ex Reg_Open_साँचो_Ex_A
#define Reg_Query_Info_साँचो Reg_Query_Info_साँचो_A
#define Reg_Query_मान Reg_Query_मान_A
#define Reg_Query_Multiple_मानहरू Reg_Query_Multiple_मानहरू_A
#define Reg_Query_मान_Ex Reg_Query_मान_Ex_A
#define Reg_Replace_साँचो Reg_Replace_साँचो_A
#define Reg_Restore_साँचो Reg_Restore_साँचो_A
#define Reg_Save_साँचो Reg_Save_साँचो_A
#define Reg_Set_मान Reg_Set_मान_A
#define Reg_Set_मान_Ex Reg_Set_मान_Ex_A
#define Reg_Un_Load_साँचो Reg_Un_Load_साँचो_A
#define Reg_Get_मान Reg_Get_मान_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_साँचो(HKEY h_साँचो);
  WINADVAPI LONG WINAPI Reg_Override_Predef_साँचो(HKEY h_साँचो,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_जरा(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_साँचो,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_साँचो,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_साँचो,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_साँचो,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_साँचो_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_साँचो_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_साँचो_Ex_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_साँचो_Ex_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_साँचो_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो);
  WINADVAPI LONG WINAPI Reg_Delete_साँचो_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो);
  WINADVAPI LONG WINAPI Reg_Delete_साँचो_Ex_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_साँचो_Ex_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_साँचो(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_साँचो(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_साँचो(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_मान_A(HKEY h_साँचो,LPCSTR lp_मान_Name);
  WINADVAPI LONG WINAPI Reg_Delete_मान_W(HKEY h_साँचो,LPCWSTR lp_मान_Name);
  WINADVAPI LONG WINAPI Reg_Enum_साँचो_A(HKEY h_साँचो,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_साँचो_W(HKEY h_साँचो,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_साँचो_Ex_A(HKEY h_साँचो,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_साँचो_Ex_W(HKEY h_साँचो,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_मान_A(HKEY h_साँचो,DWORD dwIndex,LPSTR lp_मान_Name,LPDWORD lpcch_मान_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_मान_W(HKEY h_साँचो,DWORD dwIndex,LPWSTR lp_मान_Name,LPDWORD lpcch_मान_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_साँचो(HKEY h_साँचो);
  WINADVAPI LONG WINAPI Reg_Get_साँचो_Security(HKEY h_साँचो,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_साँचो_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_साँचो_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_साँचो_मान(HKEY h_साँचो,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_साँचो_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_साँचो_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_साँचो_Ex_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_साँचो_Ex_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_साँचो_A(HKEY h_साँचो,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_साँचोहरू,LPDWORD lpcb_Max_Sub_साँचो_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_मानहरू,LPDWORD lpcb_Max_मान_Name_Len,LPDWORD lpcb_Max_मान_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_साँचो_W(HKEY h_साँचो,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_साँचोहरू,LPDWORD lpcb_Max_Sub_साँचो_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_मानहरू,LPDWORD lpcb_Max_मान_Name_Len,LPDWORD lpcb_Max_मान_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_मान_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_मान_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_मानहरू_A(HKEY h_साँचो,PVALENTA val_list,DWORD अङ्क_vals,LPSTR lp_मान_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_मानहरू_W(HKEY h_साँचो,PVALENTW val_list,DWORD अङ्क_vals,LPWSTR lp_मान_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_मान_Ex_A(HKEY h_साँचो,LPCSTR lp_मान_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_मान_Ex_W(HKEY h_साँचो,LPCWSTR lp_मान_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_साँचो_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_साँचो_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_साँचो_A(HKEY h_साँचो,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_साँचो_W(HKEY h_साँचो,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_साँचो_A(HKEY h_साँचो,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_साँचो_W(HKEY h_साँचो,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_साँचो_Security(HKEY h_साँचो,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_मान_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_मान_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_मान_Ex_A(HKEY h_साँचो,LPCSTR lp_मान_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_मान_Ex_W(HKEY h_साँचो,LPCWSTR lp_मान_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_साँचो_A(HKEY h_साँचो,LPCSTR lp_Sub_साँचो);
  WINADVAPI LONG WINAPI Reg_Un_Load_साँचो_W(HKEY h_साँचो,LPCWSTR lp_Sub_साँचो);
  WINADVAPI LONG WINAPI Reg_Get_मान_A(HKEY hkey,LPCSTR lp_Sub_साँचो,LPCSTR lp_मान,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_मान_W(HKEY hkey,LPCWSTR lp_Sub_साँचो,LPCWSTR lp_मान,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
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
#define Reg_Save_साँचो_Ex Reg_Save_साँचो_Ex_W
#अन्यथा
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_साँचो_Ex Reg_Save_साँचो_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_साँचो_Ex_A(HKEY h_साँचो,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_साँचो_Ex_W(HKEY h_साँचो,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_सङ्ख्या,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
