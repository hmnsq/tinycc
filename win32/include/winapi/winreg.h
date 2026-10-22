/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINREG_
#define _WINREG_

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#define RRF_RT_REG_NONE 0x00000001
#define RRF_RT_REG_SZ 0x00000002
#define RRF_RT_REG_EXPAND_SZ 0x00000004
#define RRF_RT_REG_ଦ୍ୱିମିକ 0x00000008
#define RRF_RT_REG_DWORD 0x00000010
#define RRF_RT_REG_MULTI_SZ 0x00000020
#define RRF_RT_REG_QWORD 0x00000040

#define RRF_RT_DWORD (RRF_RT_REG_ଦ୍ୱିମିକ | RRF_RT_REG_DWORD)
#define RRF_RT_QWORD (RRF_RT_REG_ଦ୍ୱିମିକ | RRF_RT_REG_QWORD)
#define RRF_RT_ANY 0x0000ffff

#define RRF_NOEXPAND 0x10000000
#define RRF_ZEROONFAILURE 0x20000000

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ACCESS_MASK REGSAM;

#define HKEY_CLASSES_ମୂଳ ((HKEY) (ULONG_PTR)((LONG)0x80000000))
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

#define PROVIDER_KEEPS_ମୂଲ୍ୟ_LENGTH 0x1
  ସଂରଚନା val_context {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା valuelen;
    LPVOID ମୂଲ୍ୟ_context;
    LPVOID val_buff_ptr;
  };

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା val_context *PVALCONTEXT;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା pvalueA {
    LPSTR pv_valuename;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pv_valuelen;
    LPVOID pv_ମୂଲ୍ୟ_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା pvalueW {
    LPWSTR pv_valuename;
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା pv_valuelen;
    LPVOID pv_ମୂଲ୍ୟ_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ifdef UNICODE
  ପ୍ରକାରବ୍ୟାଖ୍ୟା PVALUEW PVALUE;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା PPVALUEW PPVALUE;
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା PVALUEA PVALUE;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା PPVALUEA PPVALUE;
#endif

  ପ୍ରକାରବ୍ୟାଖ୍ୟା DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD ଅଙ୍କ_vals,LPVOID outputbuffer,DWORD *total_outlen,DWORD ନିବେଶ_blen);

  ପ୍ରକାରବ୍ୟାଖ୍ୟା QUERYHANDLER *PQUERYHANDLER;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_ଚାବି_context;
  } REG_PROVIDER;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା provider_info *PPROVIDER;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା ମୂଲ୍ୟ_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା ମୂଲ୍ୟ_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ifdef UNICODE
  ପ୍ରକାରବ୍ୟାଖ୍ୟା VALENTW VALENT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା PVALENTW PVALENT;
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା VALENTA VALENT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା PVALENTA PVALENT;
#endif
#endif

#define WIN31_CLASS ଖାଲି

#ifdef UNICODE
#define RegConnectRegistry RegConnectRegistryW
#define RegConnectRegistryEx RegConnectRegistryExW
#define Reg_Create_ଚାବି Reg_Create_ଚାବି_W
#define Reg_Create_ଚାବି_Ex Reg_Create_ଚାବି_Ex_W
#define Reg_Delete_ଚାବି Reg_Delete_ଚାବି_W
#define Reg_Delete_ଚାବି_Ex Reg_Delete_ଚାବି_Ex_W
#define Reg_Delete_ମୂଲ୍ୟ Reg_Delete_ମୂଲ୍ୟ_W
#define Reg_Enum_ଚାବି Reg_Enum_ଚାବି_W
#define Reg_Enum_ଚାବି_Ex Reg_Enum_ଚାବି_Ex_W
#define Reg_Enum_ମୂଲ୍ୟ Reg_Enum_ମୂଲ୍ୟ_W
#define Reg_Load_ଚାବି Reg_Load_ଚାବି_W
#define Reg_Open_ଚାବି Reg_Open_ଚାବି_W
#define Reg_Open_ଚାବି_Ex Reg_Open_ଚାବି_Ex_W
#define Reg_Query_Info_ଚାବି Reg_Query_Info_ଚାବି_W
#define Reg_Query_ମୂଲ୍ୟ Reg_Query_ମୂଲ୍ୟ_W
#define Reg_Query_Multiple_ମୂଲ୍ୟଗୁଡ଼ିକ Reg_Query_Multiple_ମୂଲ୍ୟଗୁଡ଼ିକ_W
#define Reg_Query_ମୂଲ୍ୟ_Ex Reg_Query_ମୂଲ୍ୟ_Ex_W
#define Reg_Replace_ଚାବି Reg_Replace_ଚାବି_W
#define Reg_Restore_ଚାବି Reg_Restore_ଚାବି_W
#define Reg_Save_ଚାବି Reg_Save_ଚାବି_W
#define Reg_Set_ମୂଲ୍ୟ Reg_Set_ମୂଲ୍ୟ_W
#define Reg_Set_ମୂଲ୍ୟ_Ex Reg_Set_ମୂଲ୍ୟ_Ex_W
#define Reg_Un_Load_ଚାବି Reg_Un_Load_ଚାବି_W
#define Reg_Get_ମୂଲ୍ୟ Reg_Get_ମୂଲ୍ୟ_W
#define InitiateSystemShutdown InitiateSystemShutdownW
#define AbortSystemShutdown AbortSystemShutdownW
#ଅନ୍ୟଥା
#define RegConnectRegistry RegConnectRegistryA
#define RegConnectRegistryEx RegConnectRegistryExA
#define Reg_Create_ଚାବି Reg_Create_ଚାବି_A
#define Reg_Create_ଚାବି_Ex Reg_Create_ଚାବି_Ex_A
#define Reg_Delete_ଚାବି Reg_Delete_ଚାବି_A
#define Reg_Delete_ଚାବି_Ex Reg_Delete_ଚାବି_Ex_A
#define Reg_Delete_ମୂଲ୍ୟ Reg_Delete_ମୂଲ୍ୟ_A
#define Reg_Enum_ଚାବି Reg_Enum_ଚାବି_A
#define Reg_Enum_ଚାବି_Ex Reg_Enum_ଚାବି_Ex_A
#define Reg_Enum_ମୂଲ୍ୟ Reg_Enum_ମୂଲ୍ୟ_A
#define Reg_Load_ଚାବି Reg_Load_ଚାବି_A
#define Reg_Open_ଚାବି Reg_Open_ଚାବି_A
#define Reg_Open_ଚାବି_Ex Reg_Open_ଚାବି_Ex_A
#define Reg_Query_Info_ଚାବି Reg_Query_Info_ଚାବି_A
#define Reg_Query_ମୂଲ୍ୟ Reg_Query_ମୂଲ୍ୟ_A
#define Reg_Query_Multiple_ମୂଲ୍ୟଗୁଡ଼ିକ Reg_Query_Multiple_ମୂଲ୍ୟଗୁଡ଼ିକ_A
#define Reg_Query_ମୂଲ୍ୟ_Ex Reg_Query_ମୂଲ୍ୟ_Ex_A
#define Reg_Replace_ଚାବି Reg_Replace_ଚାବି_A
#define Reg_Restore_ଚାବି Reg_Restore_ଚାବି_A
#define Reg_Save_ଚାବି Reg_Save_ଚାବି_A
#define Reg_Set_ମୂଲ୍ୟ Reg_Set_ମୂଲ୍ୟ_A
#define Reg_Set_ମୂଲ୍ୟ_Ex Reg_Set_ମୂଲ୍ୟ_Ex_A
#define Reg_Un_Load_ଚାବି Reg_Un_Load_ଚାବି_A
#define Reg_Get_ମୂଲ୍ୟ Reg_Get_ମୂଲ୍ୟ_A
#define InitiateSystemShutdown InitiateSystemShutdownA
#define AbortSystemShutdown AbortSystemShutdownA
#endif

  WINADVAPI LONG WINAPI Reg_Close_ଚାବି(HKEY h_ଚାବି);
  WINADVAPI LONG WINAPI Reg_Override_Predef_ଚାବି(HKEY h_ଚାବି,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_ମୂଳ(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_ଚାବି,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_ଚାବି,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_ଚାବି,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_ଚାବି,ULONG Flags,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_ଚାବି_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_ଚାବି_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Create_ଚାବି_Ex_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_ଚାବି_Ex_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phkResult,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_ଚାବି_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି);
  WINADVAPI LONG WINAPI Reg_Delete_ଚାବି_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି);
  WINADVAPI LONG WINAPI Reg_Delete_ଚାବି_Ex_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_ଚାବି_Ex_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_ଚାବି(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_ଚାବି(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_ଚାବି(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_ମୂଲ୍ୟ_A(HKEY h_ଚାବି,LPCSTR lp_ମୂଲ୍ୟ_Name);
  WINADVAPI LONG WINAPI Reg_Delete_ମୂଲ୍ୟ_W(HKEY h_ଚାବି,LPCWSTR lp_ମୂଲ୍ୟ_Name);
  WINADVAPI LONG WINAPI Reg_Enum_ଚାବି_A(HKEY h_ଚାବି,DWORD dwIndex,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ଚାବି_W(HKEY h_ଚାବି,DWORD dwIndex,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ଚାବି_Ex_A(HKEY h_ଚାବି,DWORD dwIndex,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_ଚାବି_Ex_W(HKEY h_ଚାବି,DWORD dwIndex,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_ମୂଲ୍ୟ_A(HKEY h_ଚାବି,DWORD dwIndex,LPSTR lp_ମୂଲ୍ୟ_Name,LPDWORD lpcch_ମୂଲ୍ୟ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Enum_ମୂଲ୍ୟ_W(HKEY h_ଚାବି,DWORD dwIndex,LPWSTR lp_ମୂଲ୍ୟ_Name,LPDWORD lpcch_ମୂଲ୍ୟ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Flush_ଚାବି(HKEY h_ଚାବି);
  WINADVAPI LONG WINAPI Reg_Get_ଚାବି_Security(HKEY h_ଚାବି,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_ଚାବି_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_ଚାବି_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_ଚାବି_ମୂଲ୍ୟ(HKEY h_ଚାବି,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_ଚାବି_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_ଚାବି_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_ଚାବି_Ex_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Open_ଚାବି_Ex_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି,DWORD ulOptions,REGSAM samDesired,PHKEY phkResult);
  WINADVAPI LONG WINAPI Reg_Query_Info_ଚାବି_A(HKEY h_ଚାବି,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ଚାବିଗୁଡ଼ିକ,LPDWORD lpcb_Max_Sub_ଚାବି_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_ମୂଲ୍ୟଗୁଡ଼ିକ,LPDWORD lpcb_Max_ମୂଲ୍ୟ_Name_Len,LPDWORD lpcb_Max_ମୂଲ୍ୟ_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_ଚାବି_W(HKEY h_ଚାବି,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ଚାବିଗୁଡ଼ିକ,LPDWORD lpcb_Max_Sub_ଚାବି_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_ମୂଲ୍ୟଗୁଡ଼ିକ,LPDWORD lpcb_Max_ମୂଲ୍ୟ_Name_Len,LPDWORD lpcb_Max_ମୂଲ୍ୟ_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_ମୂଲ୍ୟ_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି,LPSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_ମୂଲ୍ୟ_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି,LPWSTR lpData,PLONG lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_ମୂଲ୍ୟଗୁଡ଼ିକ_A(HKEY h_ଚାବି,PVALENTA val_list,DWORD ଅଙ୍କ_vals,LPSTR lp_ମୂଲ୍ୟ_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_ମୂଲ୍ୟଗୁଡ଼ିକ_W(HKEY h_ଚାବି,PVALENTW val_list,DWORD ଅଙ୍କ_vals,LPWSTR lp_ମୂଲ୍ୟ_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_ମୂଲ୍ୟ_Ex_A(HKEY h_ଚାବି,LPCSTR lp_ମୂଲ୍ୟ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Query_ମୂଲ୍ୟ_Ex_W(HKEY h_ଚାବି,LPCWSTR lp_ମୂଲ୍ୟ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lpData,LPDWORD lpcbData);
  WINADVAPI LONG WINAPI Reg_Replace_ଚାବି_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_ଚାବି_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_ଚାବି_A(HKEY h_ଚାବି,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_ଚାବି_W(HKEY h_ଚାବି,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_ଚାବି_A(HKEY h_ଚାବି,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_ଚାବି_W(HKEY h_ଚାବି,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_ଚାବି_Security(HKEY h_ଚାବି,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_ମୂଲ୍ୟ_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି,DWORD dwType,LPCSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_ମୂଲ୍ୟ_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି,DWORD dwType,LPCWSTR lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_ମୂଲ୍ୟ_Ex_A(HKEY h_ଚାବି,LPCSTR lp_ମୂଲ୍ୟ_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Set_ମୂଲ୍ୟ_Ex_W(HKEY h_ଚାବି,LPCWSTR lp_ମୂଲ୍ୟ_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lpData,DWORD cbData);
  WINADVAPI LONG WINAPI Reg_Un_Load_ଚାବି_A(HKEY h_ଚାବି,LPCSTR lp_Sub_ଚାବି);
  WINADVAPI LONG WINAPI Reg_Un_Load_ଚାବି_W(HKEY h_ଚାବି,LPCWSTR lp_Sub_ଚାବି);
  WINADVAPI LONG WINAPI Reg_Get_ମୂଲ୍ୟ_A(HKEY hkey,LPCSTR lp_Sub_ଚାବି,LPCSTR lp_ମୂଲ୍ୟ,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
  WINADVAPI LONG WINAPI Reg_Get_ମୂଲ୍ୟ_W(HKEY hkey,LPCWSTR lp_Sub_ଚାବି,LPCWSTR lp_ମୂଲ୍ୟ,DWORD dwFlags,LPDWORD pdwType,PVOID pvData,LPDWORD pcbData);
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
#define Reg_Save_ଚାବି_Ex Reg_Save_ଚାବି_Ex_W
#ଅନ୍ୟଥା
#define InitiateSystemShutdownEx InitiateSystemShutdownExA
#define Reg_Save_ଚାବି_Ex Reg_Save_ଚାବି_Ex_A
#endif

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_ଚାବି_Ex_A(HKEY h_ଚାବି,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_ଚାବି_Ex_W(HKEY h_ଚାବି,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_ସଂଖ୍ୟା,DWORD dwFlag,DWORD dwRes);

#ifdef __cplusplus
}
#endif
#endif
