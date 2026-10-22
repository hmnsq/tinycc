/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINREG_
#define _WINREG_

#ifdef __cplusplus
બાહ્ય "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#define RRF_RT_REG_NONE 0x00000001
#define RRF_RT_REG_SZ 0x00000002
#define RRF_RT_REG_EXPAND_SZ 0x00000004
#define RRF_RT_REG_દ્વિઅંકી 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_દ્વિઅંકી | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_દ્વિઅંકી | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  પ્રકારવ્યાખ્યા ACCESS_MASK REGSAM;

#define HKEY_CLASSES_મૂળ ((HKEY) (ULONG_PTR)((LONG)0x80000000))
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

#define PROVIDER_KEEPS_કિંમત_LENGTH 0x1
  સંરચના val_context {
    પૂર્ણાંક valuelen;
    LPVOID કિંમત_context;
    LPVOID val_buff_ptr;
  };

  પ્રકારવ્યાખ્યા સંરચના val_context *PVALCONTEXT;

  પ્રકારવ્યાખ્યા સંરચના pvalueA {
    LPSTR pv_valuename;
    પૂર્ણાંક pv_valuelen;
    LPVOID pv_કિંમત_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  પ્રકારવ્યાખ્યા સંરચના pvalueW {
    LPWSTR pv_valuename;
    પૂર્ણાંક pv_valuelen;
    LPVOID pv_કિંમત_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  પ્રકારવ્યાખ્યા PVALUEW PVALUE;
  પ્રકારવ્યાખ્યા PPVALUEW PPVALUE;
#નહીંતર
  પ્રકારવ્યાખ્યા PVALUEA PVALUE;
  પ્રકારવ્યાખ્યા PPVALUEA PPVALUE;
#endif

  પ્રકારવ્યાખ્યા DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD અંક_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD આગત_blen);

  પ્રકારવ્યાખ્યા QUERYHANDLER *PQUERYHANDLER;

  પ્રકારવ્યાખ્યા સંરચના provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_ચાવી_context;
  } REG_PROVIDER;

  પ્રકારવ્યાખ્યા સંરચના provider_info *PPROVIDER;

  પ્રકારવ્યાખ્યા સંરચના કિંમત_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  પ્રકારવ્યાખ્યા સંરચના કિંમત_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ifdef UNICODE
  પ્રકારવ્યાખ્યા VALENTW VALENT;
  પ્રકારવ્યાખ્યા PVALENTW PVALENT;
#નહીંતર
  પ્રકારવ્યાખ્યા VALENTA VALENT;
  પ્રકારવ્યાખ્યા PVALENTA PVALENT;
#endif
#endif

#define WIN31_CLASS ખાલી

#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#define RegConnectRegistryEx RegConnectRegistryExW
#define Reg_Create_ચાવી Reg_Create_ચાવી_W
#define Reg_Create_ચાવી_Ex Reg_Create_ચાવી_Ex_W
#define Reg_Delete_ચાવી Reg_Delete_ચાવી_W
#define Reg_Delete_ચાવી_Ex Reg_Delete_ચાવી_Ex_W
#define Reg_Delete_કિંમત Reg_Delete_કિંમત_W
#define Reg_Enum_ચાવી Reg_Enum_ચાવી_W
#define Reg_Enum_ચાવી_Ex Reg_Enum_ચાવી_Ex_W
#define Reg_Enum_કિંમત Reg_Enum_કિંમત_W
#define Reg_Load_ચાવી Reg_Load_ચાવી_W
#define Reg_Open_ચાવી Reg_Open_ચાવી_W
#define Reg_Open_ચાવી_Ex Reg_Open_ચાવી_Ex_W
#define Reg_Query_Info_ચાવી Reg_Query_Info_ચાવી_W
#define Reg_Query_કિંમત Reg_Query_કિંમત_W
#define Reg_Query_Multiple_કિંમતો Reg_Query_Multiple_કિંમતો_W
#define Reg_Query_કિંમત_Ex Reg_Query_કિંમત_Ex_W
#define Reg_Replace_ચાવી Reg_Replace_ચાવી_W
#define Reg_Restore_ચાવી Reg_Restore_ચાવી_W
#define Reg_Save_ચાવી Reg_Save_ચાવી_W
#define Reg_Set_કિંમત Reg_Set_કિંમત_W
#define Reg_Set_કિંમત_Ex Reg_Set_કિંમત_Ex_W
#define Reg_Un_Load_ચાવી Reg_Un_Load_ચાવી_W
#define Reg_Get_કિંમત Reg_Get_કિંમત_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#નહીંતર
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_ચાવી Reg_Create_ચાવી_A
#define Reg_Create_ચાવી_Ex Reg_Create_ચાવી_Ex_A
#define Reg_Delete_ચાવી Reg_Delete_ચાવી_A
#define Reg_Delete_ચાવી_Ex Reg_Delete_ચાવી_Ex_A
#define Reg_Delete_કિંમત Reg_Delete_કિંમત_A
#define Reg_Enum_ચાવી Reg_Enum_ચાવી_A
#define Reg_Enum_ચાવી_Ex Reg_Enum_ચાવી_Ex_A
#define Reg_Enum_કિંમત Reg_Enum_કિંમત_A
#define Reg_Load_ચાવી Reg_Load_ચાવી_A
#define Reg_Open_ચાવી Reg_Open_ચાવી_A
#define Reg_Open_ચાવી_Ex Reg_Open_ચાવી_Ex_A
#define Reg_Query_Info_ચાવી Reg_Query_Info_ચાવી_A
#define Reg_Query_કિંમત Reg_Query_કિંમત_A
#define Reg_Query_Multiple_કિંમતો Reg_Query_Multiple_કિંમતો_A
#define Reg_Query_કિંમત_Ex Reg_Query_કિંમત_Ex_A
#define Reg_Replace_ચાવી Reg_Replace_ચાવી_A
#define Reg_Restore_ચાવી Reg_Restore_ચાવી_A
#define Reg_Save_ચાવી Reg_Save_ચાવી_A
#define Reg_Set_કિંમત Reg_Set_કિંમત_A
#define Reg_Set_કિંમત_Ex Reg_Set_કિંમત_Ex_A
#define Reg_Un_Load_ચાવી Reg_Un_Load_ચાવી_A
#define Reg_Get_કિંમત Reg_Get_કિંમત_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_ચાવી(HKEY h_ચાવી);
  WINADVAPI LONG WINAPI Reg_Override_Predef_ચાવી(HKEY h_ચાવી,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_મૂળ(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_ચાવી,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_ચાવી,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_ચાવી,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_ચાવી,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_ચાવી_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_ચાવી_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_ચાવી_Ex_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_ચાવી_Ex_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_ચાવી_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી);
  WINADVAPI LONG WINAPI Reg_Delete_ચાવી_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી);
  WINADVAPI LONG WINAPI Reg_Delete_ચાવી_Ex_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_ચાવી_Ex_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_ચાવી(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_ચાવી(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_ચાવી(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_કિંમત_A(HKEY h_ચાવી,LPCSTR lp_કિંમત_Name);
  WINADVAPI LONG WINAPI Reg_Delete_કિંમત_W(HKEY h_ચાવી,LPCWSTR lp_કિંમત_Name);
  WINADVAPI LONG WINAPI Reg_Enum_ચાવી_A(HKEY h_ચાવી,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ચાવી_W(HKEY h_ચાવી,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ચાવી_Ex_A(HKEY h_ચાવી,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_ચાવી_Ex_W(HKEY h_ચાવી,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_કિંમત_A(HKEY h_ચાવી,DWORD dwIndex,LPSTR lp_કિંમત_Name,LPDWORD lpcch_કિંમત_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_કિંમત_W(HKEY h_ચાવી,DWORD dwIndex,LPWSTR lp_કિંમત_Name,LPDWORD lpcch_કિંમત_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_ચાવી(HKEY h_ચાવી);
  WINADVAPI LONG WINAPI Reg_Get_ચાવી_Security(HKEY h_ચાવી,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_ચાવી_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_ચાવી_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_ચાવી_કિંમત(HKEY h_ચાવી,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_ચાવી_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_ચાવી_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_ચાવી_Ex_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_ચાવી_Ex_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_ચાવી_A(HKEY h_ચાવી,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ચાવીઓ,LPDWORD lpcb_Max_Sub_ચાવી_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_કિંમતો,LPDWORD lpcb_Max_કિંમત_Name_Len,LPDWORD lpcb_Max_કિંમત_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_ચાવી_W(HKEY h_ચાવી,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ચાવીઓ,LPDWORD lpcb_Max_Sub_ચાવી_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_કિંમતો,LPDWORD lpcb_Max_કિંમત_Name_Len,LPDWORD lpcb_Max_કિંમત_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_કિંમત_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_કિંમત_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_કિંમતો_A(HKEY h_ચાવી,PVALENTA val_list,DWORD અંક_vals,LPSTR lp_કિંમત_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_કિંમતો_W(HKEY h_ચાવી,PVALENTW val_list,DWORD અંક_vals,LPWSTR lp_કિંમત_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_કિંમત_Ex_A(HKEY h_ચાવી,LPCSTR lp_કિંમત_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_કિંમત_Ex_W(HKEY h_ચાવી,LPCWSTR lp_કિંમત_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_ચાવી_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_ચાવી_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_ચાવી_A(HKEY h_ચાવી,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_ચાવી_W(HKEY h_ચાવી,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_ચાવી_A(HKEY h_ચાવી,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_ચાવી_W(HKEY h_ચાવી,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_ચાવી_Security(HKEY h_ચાવી,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_કિંમત_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_કિંમત_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_કિંમત_Ex_A(HKEY h_ચાવી,LPCSTR lp_કિંમત_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_કિંમત_Ex_W(HKEY h_ચાવી,LPCWSTR lp_કિંમત_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_ચાવી_A(HKEY h_ચાવી,LPCSTR lp_Sub_ચાવી);
  WINADVAPI LONG WINAPI Reg_Un_Load_ચાવી_W(HKEY h_ચાવી,LPCWSTR lp_Sub_ચાવી);
  WINADVAPI LONG WINAPI Reg_Get_કિંમત_A(HKEY hkey,LPCSTR lp_Sub_ચાવી,LPCSTR lp_કિંમત,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_કિંમત_W(HKEY hkey,LPCWSTR lp_Sub_ચાવી,LPCWSTR lp_કિંમત,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
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
#define Reg_Save_ચાવી_Ex Reg_Save_ચાવી_Ex_W
#નહીંતર
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_ચાવી_Ex Reg_Save_ચાવી_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_ચાવી_Ex_A(HKEY h_ચાવી,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_ચાવી_Ex_W(HKEY h_ચાવી,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_સંખ્યા,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
