/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINREG_
#define _WINREG_

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#define RRF_RT_REG_NONE 0x00000001
#define RRF_RT_REG_SZ 0x00000002
#define RRF_RT_REG_EXPAND_SZ 0x00000004
#define RRF_RT_REG_ദ്വിമാന 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_ദ്വിമാന | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_ദ്വിമാന | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  തരനിർവചനം ACCESS_MASK REGSAM;

#define HKEY_CLASSES_വേര് ((HKEY) (ULONG_PTR)((LONG)0x80000000))
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

#define PROVIDER_KEEPS_മൂല്യം_LENGTH 0x1
  ഘടന val_context {
    പൂർണ്ണസംഖ്യ valuelen;
    LPVOID മൂല്യം_context;
    LPVOID val_buff_ptr;
  };

  തരനിർവചനം ഘടന val_context *PVALCONTEXT;

  തരനിർവചനം ഘടന pvalueA {
    LPSTR pv_valuename;
    പൂർണ്ണസംഖ്യ pv_valuelen;
    LPVOID pv_മൂല്യം_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  തരനിർവചനം ഘടന pvalueW {
    LPWSTR pv_valuename;
    പൂർണ്ണസംഖ്യ pv_valuelen;
    LPVOID pv_മൂല്യം_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  തരനിർവചനം PVALUEW PVALUE;
  തരനിർവചനം PPVALUEW PPVALUE;
#അല്ലെങ്കിൽ
  തരനിർവചനം PVALUEA PVALUE;
  തരനിർവചനം PPVALUEA PPVALUE;
#endif

  തരനിർവചനം DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD അക്കം_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD നിവേശം_blen);

  തരനിർവചനം QUERYHANDLER *PQUERYHANDLER;

  തരനിർവചനം ഘടന provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_താക്കോൽ_context;
  } REG_PROVIDER;

  തരനിർവചനം ഘടന provider_info *PPROVIDER;

  തരനിർവചനം ഘടന മൂല്യം_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  തരനിർവചനം ഘടന മൂല്യം_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ifdef UNICODE
  തരനിർവചനം VALENTW VALENT;
  തരനിർവചനം PVALENTW PVALENT;
#അല്ലെങ്കിൽ
  തരനിർവചനം VALENTA VALENT;
  തരനിർവചനം PVALENTA PVALENT;
#endif
#endif

#define WIN31_CLASS ശൂന്യ

#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#define RegConnectRegistryEx RegConnectRegistryExW
#define Reg_Create_താക്കോൽ Reg_Create_താക്കോൽ_W
#define Reg_Create_താക്കോൽ_Ex Reg_Create_താക്കോൽ_Ex_W
#define Reg_Delete_താക്കോൽ Reg_Delete_താക്കോൽ_W
#define Reg_Delete_താക്കോൽ_Ex Reg_Delete_താക്കോൽ_Ex_W
#define Reg_Delete_മൂല്യം Reg_Delete_മൂല്യം_W
#define Reg_Enum_താക്കോൽ Reg_Enum_താക്കോൽ_W
#define Reg_Enum_താക്കോൽ_Ex Reg_Enum_താക്കോൽ_Ex_W
#define Reg_Enum_മൂല്യം Reg_Enum_മൂല്യം_W
#define Reg_Load_താക്കോൽ Reg_Load_താക്കോൽ_W
#define Reg_Open_താക്കോൽ Reg_Open_താക്കോൽ_W
#define Reg_Open_താക്കോൽ_Ex Reg_Open_താക്കോൽ_Ex_W
#define Reg_Query_Info_താക്കോൽ Reg_Query_Info_താക്കോൽ_W
#define Reg_Query_മൂല്യം Reg_Query_മൂല്യം_W
#define Reg_Query_Multiple_മൂല്യങ്ങൾ Reg_Query_Multiple_മൂല്യങ്ങൾ_W
#define Reg_Query_മൂല്യം_Ex Reg_Query_മൂല്യം_Ex_W
#define Reg_Replace_താക്കോൽ Reg_Replace_താക്കോൽ_W
#define Reg_Restore_താക്കോൽ Reg_Restore_താക്കോൽ_W
#define Reg_Save_താക്കോൽ Reg_Save_താക്കോൽ_W
#define Reg_Set_മൂല്യം Reg_Set_മൂല്യം_W
#define Reg_Set_മൂല്യം_Ex Reg_Set_മൂല്യം_Ex_W
#define Reg_Un_Load_താക്കോൽ Reg_Un_Load_താക്കോൽ_W
#define Reg_Get_മൂല്യം Reg_Get_മൂല്യം_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#അല്ലെങ്കിൽ
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_താക്കോൽ Reg_Create_താക്കോൽ_A
#define Reg_Create_താക്കോൽ_Ex Reg_Create_താക്കോൽ_Ex_A
#define Reg_Delete_താക്കോൽ Reg_Delete_താക്കോൽ_A
#define Reg_Delete_താക്കോൽ_Ex Reg_Delete_താക്കോൽ_Ex_A
#define Reg_Delete_മൂല്യം Reg_Delete_മൂല്യം_A
#define Reg_Enum_താക്കോൽ Reg_Enum_താക്കോൽ_A
#define Reg_Enum_താക്കോൽ_Ex Reg_Enum_താക്കോൽ_Ex_A
#define Reg_Enum_മൂല്യം Reg_Enum_മൂല്യം_A
#define Reg_Load_താക്കോൽ Reg_Load_താക്കോൽ_A
#define Reg_Open_താക്കോൽ Reg_Open_താക്കോൽ_A
#define Reg_Open_താക്കോൽ_Ex Reg_Open_താക്കോൽ_Ex_A
#define Reg_Query_Info_താക്കോൽ Reg_Query_Info_താക്കോൽ_A
#define Reg_Query_മൂല്യം Reg_Query_മൂല്യം_A
#define Reg_Query_Multiple_മൂല്യങ്ങൾ Reg_Query_Multiple_മൂല്യങ്ങൾ_A
#define Reg_Query_മൂല്യം_Ex Reg_Query_മൂല്യം_Ex_A
#define Reg_Replace_താക്കോൽ Reg_Replace_താക്കോൽ_A
#define Reg_Restore_താക്കോൽ Reg_Restore_താക്കോൽ_A
#define Reg_Save_താക്കോൽ Reg_Save_താക്കോൽ_A
#define Reg_Set_മൂല്യം Reg_Set_മൂല്യം_A
#define Reg_Set_മൂല്യം_Ex Reg_Set_മൂല്യം_Ex_A
#define Reg_Un_Load_താക്കോൽ Reg_Un_Load_താക്കോൽ_A
#define Reg_Get_മൂല്യം Reg_Get_മൂല്യം_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_താക്കോൽ(HKEY h_താക്കോൽ);
  WINADVAPI LONG WINAPI Reg_Override_Predef_താക്കോൽ(HKEY h_താക്കോൽ,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_വേര്(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_താക്കോൽ,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_താക്കോൽ,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_താക്കോൽ,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_താക്കോൽ,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_താക്കോൽ_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_താക്കോൽ_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_താക്കോൽ_Ex_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_താക്കോൽ_Ex_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_താക്കോൽ_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ);
  WINADVAPI LONG WINAPI Reg_Delete_താക്കോൽ_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ);
  WINADVAPI LONG WINAPI Reg_Delete_താക്കോൽ_Ex_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_താക്കോൽ_Ex_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_താക്കോൽ(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_താക്കോൽ(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_താക്കോൽ(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_മൂല്യം_A(HKEY h_താക്കോൽ,LPCSTR lp_മൂല്യം_Name);
  WINADVAPI LONG WINAPI Reg_Delete_മൂല്യം_W(HKEY h_താക്കോൽ,LPCWSTR lp_മൂല്യം_Name);
  WINADVAPI LONG WINAPI Reg_Enum_താക്കോൽ_A(HKEY h_താക്കോൽ,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_താക്കോൽ_W(HKEY h_താക്കോൽ,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_താക്കോൽ_Ex_A(HKEY h_താക്കോൽ,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_താക്കോൽ_Ex_W(HKEY h_താക്കോൽ,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_മൂല്യം_A(HKEY h_താക്കോൽ,DWORD dwIndex,LPSTR lp_മൂല്യം_Name,LPDWORD lpcch_മൂല്യം_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_മൂല്യം_W(HKEY h_താക്കോൽ,DWORD dwIndex,LPWSTR lp_മൂല്യം_Name,LPDWORD lpcch_മൂല്യം_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_താക്കോൽ(HKEY h_താക്കോൽ);
  WINADVAPI LONG WINAPI Reg_Get_താക്കോൽ_Security(HKEY h_താക്കോൽ,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_താക്കോൽ_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_താക്കോൽ_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_താക്കോൽ_മൂല്യം(HKEY h_താക്കോൽ,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_താക്കോൽ_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_താക്കോൽ_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_താക്കോൽ_Ex_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_താക്കോൽ_Ex_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_താക്കോൽ_A(HKEY h_താക്കോൽ,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_താക്കോലുകൾ,LPDWORD lpcb_Max_Sub_താക്കോൽ_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_മൂല്യങ്ങൾ,LPDWORD lpcb_Max_മൂല്യം_Name_Len,LPDWORD lpcb_Max_മൂല്യം_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_താക്കോൽ_W(HKEY h_താക്കോൽ,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_താക്കോലുകൾ,LPDWORD lpcb_Max_Sub_താക്കോൽ_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_മൂല്യങ്ങൾ,LPDWORD lpcb_Max_മൂല്യം_Name_Len,LPDWORD lpcb_Max_മൂല്യം_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_മൂല്യം_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_മൂല്യം_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_മൂല്യങ്ങൾ_A(HKEY h_താക്കോൽ,PVALENTA val_list,DWORD അക്കം_vals,LPSTR lp_മൂല്യം_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_മൂല്യങ്ങൾ_W(HKEY h_താക്കോൽ,PVALENTW val_list,DWORD അക്കം_vals,LPWSTR lp_മൂല്യം_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_മൂല്യം_Ex_A(HKEY h_താക്കോൽ,LPCSTR lp_മൂല്യം_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_മൂല്യം_Ex_W(HKEY h_താക്കോൽ,LPCWSTR lp_മൂല്യം_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_താക്കോൽ_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_താക്കോൽ_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_താക്കോൽ_A(HKEY h_താക്കോൽ,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_താക്കോൽ_W(HKEY h_താക്കോൽ,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_താക്കോൽ_A(HKEY h_താക്കോൽ,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_താക്കോൽ_W(HKEY h_താക്കോൽ,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_താക്കോൽ_Security(HKEY h_താക്കോൽ,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_മൂല്യം_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_മൂല്യം_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_മൂല്യം_Ex_A(HKEY h_താക്കോൽ,LPCSTR lp_മൂല്യം_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_മൂല്യം_Ex_W(HKEY h_താക്കോൽ,LPCWSTR lp_മൂല്യം_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_താക്കോൽ_A(HKEY h_താക്കോൽ,LPCSTR lp_Sub_താക്കോൽ);
  WINADVAPI LONG WINAPI Reg_Un_Load_താക്കോൽ_W(HKEY h_താക്കോൽ,LPCWSTR lp_Sub_താക്കോൽ);
  WINADVAPI LONG WINAPI Reg_Get_മൂല്യം_A(HKEY hkey,LPCSTR lp_Sub_താക്കോൽ,LPCSTR lp_മൂല്യം,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_മൂല്യം_W(HKEY hkey,LPCWSTR lp_Sub_താക്കോൽ,LPCWSTR lp_മൂല്യം,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
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
#define Reg_Save_താക്കോൽ_Ex Reg_Save_താക്കോൽ_Ex_W
#അല്ലെങ്കിൽ
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_താക്കോൽ_Ex Reg_Save_താക്കോൽ_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_താക്കോൽ_Ex_A(HKEY h_താക്കോൽ,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_താക്കോൽ_Ex_W(HKEY h_താക്കോൽ,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_സംഖ്യ,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
