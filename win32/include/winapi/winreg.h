/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINREG_
#define _WINREG_

#ifdef __cplusplus
வெளி "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#define RRF_RT_REG_NONE 0x00000001
#define RRF_RT_REG_SZ 0x00000002
#define RRF_RT_REG_EXPAND_SZ 0x00000004
#define RRF_RT_REG_இருமம் 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_இருமம் | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_இருமம் | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  வகைவரை ACCESS_MASK REGSAM;

#define HKEY_CLASSES_வேர் ((HKEY) (ULONG_PTR)((LONG)0x80000000))
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

#define PROVIDER_KEEPS_மதிப்பு_LENGTH 0x1
  கட்டமைப்பு val_context {
    முழு valuelen;
    LPVOID மதிப்பு_context;
    LPVOID val_buff_ptr;
  };

  வகைவரை கட்டமைப்பு val_context *PVALCONTEXT;

  வகைவரை கட்டமைப்பு pvalueA {
    LPSTR pv_valuename;
    முழு pv_valuelen;
    LPVOID pv_மதிப்பு_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  வகைவரை கட்டமைப்பு pvalueW {
    LPWSTR pv_valuename;
    முழு pv_valuelen;
    LPVOID pv_மதிப்பு_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  வகைவரை PVALUEW PVALUE;
  வகைவரை PPVALUEW PPVALUE;
#இல்லையெனில்
  வகைவரை PVALUEA PVALUE;
  வகைவரை PPVALUEA PPVALUE;
#endif

  வகைவரை DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD இலக்கம்_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD உள்ளீடு_blen);

  வகைவரை QUERYHANDLER *PQUERYHANDLER;

  வகைவரை கட்டமைப்பு provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_சாவி_context;
  } REG_PROVIDER;

  வகைவரை கட்டமைப்பு provider_info *PPROVIDER;

  வகைவரை கட்டமைப்பு மதிப்பு_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  வகைவரை கட்டமைப்பு மதிப்பு_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ifdef UNICODE
  வகைவரை VALENTW VALENT;
  வகைவரை PVALENTW PVALENT;
#இல்லையெனில்
  வகைவரை VALENTA VALENT;
  வகைவரை PVALENTA PVALENT;
#endif
#endif

#define WIN31_CLASS வெற்று

#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#define RegConnectRegistryEx RegConnectRegistryExW
#define Reg_Create_சாவி Reg_Create_சாவி_W
#define Reg_Create_சாவி_Ex Reg_Create_சாவி_Ex_W
#define Reg_Delete_சாவி Reg_Delete_சாவி_W
#define Reg_Delete_சாவி_Ex Reg_Delete_சாவி_Ex_W
#define Reg_Delete_மதிப்பு Reg_Delete_மதிப்பு_W
#define Reg_Enum_சாவி Reg_Enum_சாவி_W
#define Reg_Enum_சாவி_Ex Reg_Enum_சாவி_Ex_W
#define Reg_Enum_மதிப்பு Reg_Enum_மதிப்பு_W
#define Reg_Load_சாவி Reg_Load_சாவி_W
#define Reg_Open_சாவி Reg_Open_சாவி_W
#define Reg_Open_சாவி_Ex Reg_Open_சாவி_Ex_W
#define Reg_Query_Info_சாவி Reg_Query_Info_சாவி_W
#define Reg_Query_மதிப்பு Reg_Query_மதிப்பு_W
#define Reg_Query_Multiple_மதிப்புகள் Reg_Query_Multiple_மதிப்புகள்_W
#define Reg_Query_மதிப்பு_Ex Reg_Query_மதிப்பு_Ex_W
#define Reg_Replace_சாவி Reg_Replace_சாவி_W
#define Reg_Restore_சாவி Reg_Restore_சாவி_W
#define Reg_Save_சாவி Reg_Save_சாவி_W
#define Reg_Set_மதிப்பு Reg_Set_மதிப்பு_W
#define Reg_Set_மதிப்பு_Ex Reg_Set_மதிப்பு_Ex_W
#define Reg_Un_Load_சாவி Reg_Un_Load_சாவி_W
#define Reg_Get_மதிப்பு Reg_Get_மதிப்பு_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#இல்லையெனில்
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_சாவி Reg_Create_சாவி_A
#define Reg_Create_சாவி_Ex Reg_Create_சாவி_Ex_A
#define Reg_Delete_சாவி Reg_Delete_சாவி_A
#define Reg_Delete_சாவி_Ex Reg_Delete_சாவி_Ex_A
#define Reg_Delete_மதிப்பு Reg_Delete_மதிப்பு_A
#define Reg_Enum_சாவி Reg_Enum_சாவி_A
#define Reg_Enum_சாவி_Ex Reg_Enum_சாவி_Ex_A
#define Reg_Enum_மதிப்பு Reg_Enum_மதிப்பு_A
#define Reg_Load_சாவி Reg_Load_சாவி_A
#define Reg_Open_சாவி Reg_Open_சாவி_A
#define Reg_Open_சாவி_Ex Reg_Open_சாவி_Ex_A
#define Reg_Query_Info_சாவி Reg_Query_Info_சாவி_A
#define Reg_Query_மதிப்பு Reg_Query_மதிப்பு_A
#define Reg_Query_Multiple_மதிப்புகள் Reg_Query_Multiple_மதிப்புகள்_A
#define Reg_Query_மதிப்பு_Ex Reg_Query_மதிப்பு_Ex_A
#define Reg_Replace_சாவி Reg_Replace_சாவி_A
#define Reg_Restore_சாவி Reg_Restore_சாவி_A
#define Reg_Save_சாவி Reg_Save_சாவி_A
#define Reg_Set_மதிப்பு Reg_Set_மதிப்பு_A
#define Reg_Set_மதிப்பு_Ex Reg_Set_மதிப்பு_Ex_A
#define Reg_Un_Load_சாவி Reg_Un_Load_சாவி_A
#define Reg_Get_மதிப்பு Reg_Get_மதிப்பு_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_சாவி(HKEY h_சாவி);
  WINADVAPI LONG WINAPI Reg_Override_Predef_சாவி(HKEY h_சாவி,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_வேர்(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_சாவி,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_சாவி,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_சாவி,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_சாவி,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_சாவி_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_சாவி_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_சாவி_Ex_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_சாவி_Ex_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_சாவி_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி);
  WINADVAPI LONG WINAPI Reg_Delete_சாவி_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி);
  WINADVAPI LONG WINAPI Reg_Delete_சாவி_Ex_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_சாவி_Ex_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_சாவி(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_சாவி(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_சாவி(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_மதிப்பு_A(HKEY h_சாவி,LPCSTR lp_மதிப்பு_Name);
  WINADVAPI LONG WINAPI Reg_Delete_மதிப்பு_W(HKEY h_சாவி,LPCWSTR lp_மதிப்பு_Name);
  WINADVAPI LONG WINAPI Reg_Enum_சாவி_A(HKEY h_சாவி,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_சாவி_W(HKEY h_சாவி,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_சாவி_Ex_A(HKEY h_சாவி,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_சாவி_Ex_W(HKEY h_சாவி,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_மதிப்பு_A(HKEY h_சாவி,DWORD dwIndex,LPSTR lp_மதிப்பு_Name,LPDWORD lpcch_மதிப்பு_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_மதிப்பு_W(HKEY h_சாவி,DWORD dwIndex,LPWSTR lp_மதிப்பு_Name,LPDWORD lpcch_மதிப்பு_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_சாவி(HKEY h_சாவி);
  WINADVAPI LONG WINAPI Reg_Get_சாவி_Security(HKEY h_சாவி,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_சாவி_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_சாவி_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_சாவி_மதிப்பு(HKEY h_சாவி,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_சாவி_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_சாவி_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_சாவி_Ex_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_சாவி_Ex_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_சாவி_A(HKEY h_சாவி,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_சாவிகள்,LPDWORD lpcb_Max_Sub_சாவி_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_மதிப்புகள்,LPDWORD lpcb_Max_மதிப்பு_Name_Len,LPDWORD lpcb_Max_மதிப்பு_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_சாவி_W(HKEY h_சாவி,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_சாவிகள்,LPDWORD lpcb_Max_Sub_சாவி_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_மதிப்புகள்,LPDWORD lpcb_Max_மதிப்பு_Name_Len,LPDWORD lpcb_Max_மதிப்பு_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_மதிப்பு_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_மதிப்பு_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_மதிப்புகள்_A(HKEY h_சாவி,PVALENTA val_list,DWORD இலக்கம்_vals,LPSTR lp_மதிப்பு_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_மதிப்புகள்_W(HKEY h_சாவி,PVALENTW val_list,DWORD இலக்கம்_vals,LPWSTR lp_மதிப்பு_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_மதிப்பு_Ex_A(HKEY h_சாவி,LPCSTR lp_மதிப்பு_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_மதிப்பு_Ex_W(HKEY h_சாவி,LPCWSTR lp_மதிப்பு_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_சாவி_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_சாவி_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_சாவி_A(HKEY h_சாவி,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_சாவி_W(HKEY h_சாவி,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_சாவி_A(HKEY h_சாவி,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_சாவி_W(HKEY h_சாவி,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_சாவி_Security(HKEY h_சாவி,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_மதிப்பு_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_மதிப்பு_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_மதிப்பு_Ex_A(HKEY h_சாவி,LPCSTR lp_மதிப்பு_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_மதிப்பு_Ex_W(HKEY h_சாவி,LPCWSTR lp_மதிப்பு_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_சாவி_A(HKEY h_சாவி,LPCSTR lp_Sub_சாவி);
  WINADVAPI LONG WINAPI Reg_Un_Load_சாவி_W(HKEY h_சாவி,LPCWSTR lp_Sub_சாவி);
  WINADVAPI LONG WINAPI Reg_Get_மதிப்பு_A(HKEY hkey,LPCSTR lp_Sub_சாவி,LPCSTR lp_மதிப்பு,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_மதிப்பு_W(HKEY hkey,LPCWSTR lp_Sub_சாவி,LPCWSTR lp_மதிப்பு,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
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
#define Reg_Save_சாவி_Ex Reg_Save_சாவி_Ex_W
#இல்லையெனில்
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_சாவி_Ex Reg_Save_சாவி_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_சாவி_Ex_A(HKEY h_சாவி,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_சாவி_Ex_W(HKEY h_சாவி,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_எண்,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
