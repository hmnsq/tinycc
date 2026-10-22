/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _WINREG_
#నిర్వచించు _WINREG_

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WINVER
#నిర్వచించు WINVER 0x0502
#అయితే_ముగింపు

#నిర్వచించు RRF_RT_REG_NONE 0x00000001
#నిర్వచించు RRF_RT_REG_SZ 0x00000002
#నిర్వచించు RRF_RT_REG_EXPAND_SZ 0x00000004
#నిర్వచించు RRF_RT_REG_ద్విమాన 0x00000008
#నిర్వచించు RRF_RT_REG_DWORD 0x00000010
#నిర్వచించు RRF_RT_REG_MULTI_SZ 0x00000020
#నిర్వచించు RRF_RT_REG_QWORD 0x00000040

#నిర్వచించు RRF_RT_DWORD (RRF_RT_REG_ద్విమాన | RRF_RT_REG_DWORD)
#నిర్వచించు RRF_RT_QWORD (RRF_RT_REG_ద్విమాన | RRF_RT_REG_QWORD)
#నిర్వచించు RRF_RT_ANY 0x0000ffff

#నిర్వచించు RRF_NOEXPAND 0x10000000
#నిర్వచించు RRF_ZEROONFAILURE 0x20000000

  రకనిర్వచనం ACCESS_ముసుగు REGSAM;

#నిర్వచించు HKEY_CLASSES_మూలం ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#నిర్వచించు HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#నిర్వచించు HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#నిర్వచించు HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#నిర్వచించు HKEY_PERFORMANCE_దత్తాంశం ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#నిర్వచించు HKEY_PERFORMANCE_పాఠ్యం ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#నిర్వచించు HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#నిర్వచించు HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#నిర్వచించు HKEY_DYN_దత్తాంశం ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#నిర్వచించు REG_SECURE_CONNECTION 1

#నిర్వచితం_కాకపోతే _PROVIDER_STRUCTS_DEFINED
#నిర్వచించు _PROVIDER_STRUCTS_DEFINED

#నిర్వచించు PROVIDER_KEEPS_విలువ_నిడివి 0x1
  నిర్మాణం val_context {
    పూర్ణాంకం valuelen;
    LPVOID విలువ_context;
    LPVOID val_buff_ptr;
  };

  రకనిర్వచనం నిర్మాణం val_context *PVALCONTEXT;

  రకనిర్వచనం నిర్మాణం pvalueA {
    LPSTR pv_valuename;
    పూర్ణాంకం pv_valuelen;
    LPVOID pv_విలువ_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  రకనిర్వచనం నిర్మాణం pvalueW {
    LPWSTR pv_valuename;
    పూర్ణాంకం pv_valuelen;
    LPVOID pv_విలువ_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం PVALUEW PVALUE;
  రకనిర్వచనం PPVALUEW PPVALUE;
#లేకపోతే
  రకనిర్వచనం PVALUEA PVALUE;
  రకనిర్వచనం PPVALUEA PPVALUE;
#అయితే_ముగింపు

  రకనిర్వచనం DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD అంకె_vals,LPVOID outputbuffer,DWORD *మొత్తం_outlen,DWORD ఆదానం_blen);

  రకనిర్వచనం QUERYHANDLER *PQUERYHANDLER;

  రకనిర్వచనం నిర్మాణం provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_కీలకం_context;
  } REG_PROVIDER;

  రకనిర్వచనం నిర్మాణం provider_info *PPROVIDER;

  రకనిర్వచనం నిర్మాణం విలువ_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  రకనిర్వచనం నిర్మాణం విలువ_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం VALENTW VALENT;
  రకనిర్వచనం PVALENTW PVALENT;
#లేకపోతే
  రకనిర్వచనం VALENTA VALENT;
  రకనిర్వచనం PVALENTA PVALENT;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు WIN31_CLASS ఖాళీ

#నిర్వచితమైతే UNICODE
#నిర్వచించు RegConnectRegistry RegConnectRegistryW
#నిర్వచించు RegConnectRegistryEx RegConnectRegistryExW
#నిర్వచించు Reg_Create_కీలకం Reg_Create_కీలకం_W
#నిర్వచించు Reg_Create_కీలకం_Ex Reg_Create_కీలకం_Ex_W
#నిర్వచించు Reg_Delete_కీలకం Reg_Delete_కీలకం_W
#నిర్వచించు Reg_Delete_కీలకం_Ex Reg_Delete_కీలకం_Ex_W
#నిర్వచించు Reg_Delete_విలువ Reg_Delete_విలువ_W
#నిర్వచించు Reg_Enum_కీలకం Reg_Enum_కీలకం_W
#నిర్వచించు Reg_Enum_కీలకం_Ex Reg_Enum_కీలకం_Ex_W
#నిర్వచించు Reg_Enum_విలువ Reg_Enum_విలువ_W
#నిర్వచించు Reg_ఎక్కించు_కీలకం Reg_ఎక్కించు_కీలకం_W
#నిర్వచించు Reg_Open_కీలకం Reg_Open_కీలకం_W
#నిర్వచించు Reg_Open_కీలకం_Ex Reg_Open_కీలకం_Ex_W
#నిర్వచించు Reg_Query_Info_కీలకం Reg_Query_Info_కీలకం_W
#నిర్వచించు Reg_Query_విలువ Reg_Query_విలువ_W
#నిర్వచించు Reg_Query_గుణిజం_విలువలు Reg_Query_గుణిజం_విలువలు_W
#నిర్వచించు Reg_Query_విలువ_Ex Reg_Query_విలువ_Ex_W
#నిర్వచించు Reg_Replace_కీలకం Reg_Replace_కీలకం_W
#నిర్వచించు Reg_Restore_కీలకం Reg_Restore_కీలకం_W
#నిర్వచించు Reg_Save_కీలకం Reg_Save_కీలకం_W
#నిర్వచించు Reg_సమితి_విలువ Reg_సమితి_విలువ_W
#నిర్వచించు Reg_సమితి_విలువ_Ex Reg_సమితి_విలువ_Ex_W
#నిర్వచించు Reg_Un_ఎక్కించు_కీలకం Reg_Un_ఎక్కించు_కీలకం_W
#నిర్వచించు Reg_Get_విలువ Reg_Get_విలువ_W
#నిర్వచించు InitiateSystemShutdown InitiateSystemShutdownW
#నిర్వచించు AbortSystemShutdown AbortSystemShutdownW
#లేకపోతే
#నిర్వచించు RegConnectRegistry RegConnectRegistryA
#నిర్వచించు RegConnectRegistryEx RegConnectRegistryExA
#నిర్వచించు Reg_Create_కీలకం Reg_Create_కీలకం_A
#నిర్వచించు Reg_Create_కీలకం_Ex Reg_Create_కీలకం_Ex_A
#నిర్వచించు Reg_Delete_కీలకం Reg_Delete_కీలకం_A
#నిర్వచించు Reg_Delete_కీలకం_Ex Reg_Delete_కీలకం_Ex_A
#నిర్వచించు Reg_Delete_విలువ Reg_Delete_విలువ_A
#నిర్వచించు Reg_Enum_కీలకం Reg_Enum_కీలకం_A
#నిర్వచించు Reg_Enum_కీలకం_Ex Reg_Enum_కీలకం_Ex_A
#నిర్వచించు Reg_Enum_విలువ Reg_Enum_విలువ_A
#నిర్వచించు Reg_ఎక్కించు_కీలకం Reg_ఎక్కించు_కీలకం_A
#నిర్వచించు Reg_Open_కీలకం Reg_Open_కీలకం_A
#నిర్వచించు Reg_Open_కీలకం_Ex Reg_Open_కీలకం_Ex_A
#నిర్వచించు Reg_Query_Info_కీలకం Reg_Query_Info_కీలకం_A
#నిర్వచించు Reg_Query_విలువ Reg_Query_విలువ_A
#నిర్వచించు Reg_Query_గుణిజం_విలువలు Reg_Query_గుణిజం_విలువలు_A
#నిర్వచించు Reg_Query_విలువ_Ex Reg_Query_విలువ_Ex_A
#నిర్వచించు Reg_Replace_కీలకం Reg_Replace_కీలకం_A
#నిర్వచించు Reg_Restore_కీలకం Reg_Restore_కీలకం_A
#నిర్వచించు Reg_Save_కీలకం Reg_Save_కీలకం_A
#నిర్వచించు Reg_సమితి_విలువ Reg_సమితి_విలువ_A
#నిర్వచించు Reg_సమితి_విలువ_Ex Reg_సమితి_విలువ_Ex_A
#నిర్వచించు Reg_Un_ఎక్కించు_కీలకం Reg_Un_ఎక్కించు_కీలకం_A
#నిర్వచించు Reg_Get_విలువ Reg_Get_విలువ_A
#నిర్వచించు InitiateSystemShutdown InitiateSystemShutdownA
#నిర్వచించు AbortSystemShutdown AbortSystemShutdownA
#అయితే_ముగింపు

  WINADVAPI LONG WINAPI Reg_Close_కీలకం(HKEY h_కీలకం);
  WINADVAPI LONG WINAPI Reg_Override_Predef_కీలకం(HKEY h_కీలకం,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_మూలం(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_కీలకం,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_కీలకం,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_కీలకం,ULONG Flags,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_కీలకం,ULONG Flags,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI Reg_Create_కీలకం_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI Reg_Create_కీలకం_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI Reg_Create_కీలకం_Ex_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు,PHKEY phk_ఫలితం,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_కీలకం_Ex_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు,PHKEY phk_ఫలితం,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_కీలకం_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం);
  WINADVAPI LONG WINAPI Reg_Delete_కీలకం_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం);
  WINADVAPI LONG WINAPI Reg_Delete_కీలకం_Ex_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_కీలకం_Ex_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_కీలకం(HKEY h_పునాది);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_కీలకం(HKEY h_పునాది);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_కీలకం(HKEY h_పునాది,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_విలువ_A(HKEY h_కీలకం,LPCSTR lp_విలువ_Name);
  WINADVAPI LONG WINAPI Reg_Delete_విలువ_W(HKEY h_కీలకం,LPCWSTR lp_విలువ_Name);
  WINADVAPI LONG WINAPI Reg_Enum_కీలకం_A(HKEY h_కీలకం,DWORD dw_సూచీ,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_కీలకం_W(HKEY h_కీలకం,DWORD dw_సూచీ,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_కీలకం_Ex_A(HKEY h_కీలకం,DWORD dw_సూచీ,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_చివరి_Write_సమయం);
  WINADVAPI LONG WINAPI Reg_Enum_కీలకం_Ex_W(HKEY h_కీలకం,DWORD dw_సూచీ,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_చివరి_Write_సమయం);
  WINADVAPI LONG WINAPI Reg_Enum_విలువ_A(HKEY h_కీలకం,DWORD dw_సూచీ,LPSTR lp_విలువ_Name,LPDWORD lpcch_విలువ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_దత్తాంశం,LPDWORD lpcb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_Enum_విలువ_W(HKEY h_కీలకం,DWORD dw_సూచీ,LPWSTR lp_విలువ_Name,LPDWORD lpcch_విలువ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_దత్తాంశం,LPDWORD lpcb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_Flush_కీలకం(HKEY h_కీలకం);
  WINADVAPI LONG WINAPI Reg_Get_కీలకం_Security(HKEY h_కీలకం,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_ఎక్కించు_కీలకం_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_ఎక్కించు_కీలకం_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_కీలకం_విలువ(HKEY h_కీలకం,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_కీలకం_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI Reg_Open_కీలకం_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI Reg_Open_కీలకం_Ex_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం,DWORD ulOptions,REGSAM samDesired,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI Reg_Open_కీలకం_Ex_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం,DWORD ulOptions,REGSAM samDesired,PHKEY phk_ఫలితం);
  WINADVAPI LONG WINAPI Reg_Query_Info_కీలకం_A(HKEY h_కీలకం,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_కీలకాలు,LPDWORD lpcb_Max_Sub_కీలకం_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_విలువలు,LPDWORD lpcb_Max_విలువ_Name_Len,LPDWORD lpcb_Max_విలువ_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_చివరి_Write_సమయం);
  WINADVAPI LONG WINAPI Reg_Query_Info_కీలకం_W(HKEY h_కీలకం,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_కీలకాలు,LPDWORD lpcb_Max_Sub_కీలకం_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_విలువలు,LPDWORD lpcb_Max_విలువ_Name_Len,LPDWORD lpcb_Max_విలువ_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_చివరి_Write_సమయం);
  WINADVAPI LONG WINAPI Reg_Query_విలువ_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం,LPSTR lp_దత్తాంశం,PLONG lpcb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_Query_విలువ_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం,LPWSTR lp_దత్తాంశం,PLONG lpcb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_Query_గుణిజం_విలువలు_A(HKEY h_కీలకం,PVALENTA val_list,DWORD అంకె_vals,LPSTR lp_విలువ_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_గుణిజం_విలువలు_W(HKEY h_కీలకం,PVALENTW val_list,DWORD అంకె_vals,LPWSTR lp_విలువ_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_విలువ_Ex_A(HKEY h_కీలకం,LPCSTR lp_విలువ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_దత్తాంశం,LPDWORD lpcb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_Query_విలువ_Ex_W(HKEY h_కీలకం,LPCWSTR lp_విలువ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_దత్తాంశం,LPDWORD lpcb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_Replace_కీలకం_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_కీలకం_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_కీలకం_A(HKEY h_కీలకం,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_కీలకం_W(HKEY h_కీలకం,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_కీలకం_A(HKEY h_కీలకం,LPCSTR lpFile,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINADVAPI LONG WINAPI Reg_Save_కీలకం_W(HKEY h_కీలకం,LPCWSTR lpFile,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINADVAPI LONG WINAPI Reg_సమితి_కీలకం_Security(HKEY h_కీలకం,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_సమితి_విలువ_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం,DWORD dwType,LPCSTR lp_దత్తాంశం,DWORD cb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_సమితి_విలువ_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం,DWORD dwType,LPCWSTR lp_దత్తాంశం,DWORD cb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_సమితి_విలువ_Ex_A(HKEY h_కీలకం,LPCSTR lp_విలువ_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_దత్తాంశం,DWORD cb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_సమితి_విలువ_Ex_W(HKEY h_కీలకం,LPCWSTR lp_విలువ_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_దత్తాంశం,DWORD cb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_Un_ఎక్కించు_కీలకం_A(HKEY h_కీలకం,LPCSTR lp_Sub_కీలకం);
  WINADVAPI LONG WINAPI Reg_Un_ఎక్కించు_కీలకం_W(HKEY h_కీలకం,LPCWSTR lp_Sub_కీలకం);
  WINADVAPI LONG WINAPI Reg_Get_విలువ_A(HKEY hkey,LPCSTR lp_Sub_కీలకం,LPCSTR lp_విలువ,DWORD dwFlags,LPDWORD pdwType,PVOID pv_దత్తాంశం,LPDWORD pcb_దత్తాంశం);
  WINADVAPI LONG WINAPI Reg_Get_విలువ_W(HKEY hkey,LPCWSTR lp_Sub_కీలకం,LPCWSTR lp_విలువ,DWORD dwFlags,LPDWORD pdwType,PVOID pv_దత్తాంశం,LPDWORD pcb_దత్తాంశం);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lp_సందేశం,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lp_సందేశం,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#నిర్వచించు REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#నిర్వచించు REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#నిర్వచించు REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#నిర్వచించు REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#నిర్వచించు REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#నిర్వచించు REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#నిర్వచించు REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#నిర్వచించు REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#నిర్వచించు REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#నిర్వచించు MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#నిర్వచితమైతే UNICODE
#నిర్వచించు InitiateSystemShutdownEx InitiateSystemShutdownExW
#నిర్వచించు Reg_Save_కీలకం_Ex Reg_Save_కీలకం_Ex_W
#లేకపోతే
#నిర్వచించు InitiateSystemShutdownEx InitiateSystemShutdownExA
#నిర్వచించు Reg_Save_కీలకం_Ex Reg_Save_కీలకం_Ex_A
#అయితే_ముగింపు

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lp_సందేశం,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lp_సందేశం,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_కీలకం_Ex_A(HKEY h_కీలకం,LPCSTR lpFile,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_కీలకం_Ex_W(HKEY h_కీలకం,LPCWSTR lpFile,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64_Win32_Api_నమోదు (DWORD dw_Func_సంఖ్య,DWORD dwFlag,DWORD dwRes);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
