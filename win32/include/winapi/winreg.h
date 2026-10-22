/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _WINREG_
#घोषणा _WINREG_

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित WINVER
#घोषणा WINVER 0x0502
#पूर्ण_अगर

#घोषणा RRF_RT_REG_NONE 0x00000001
#घोषणा RRF_RT_REG_SZ 0x00000002
#घोषणा RRF_RT_REG_EXPAND_SZ 0x00000004
#घोषणा RRF_RT_REG_द्विआधारी 0x00000008
#घोषणा RRF_RT_REG_DWORD 0x00000010
#घोषणा RRF_RT_REG_MULTI_SZ 0x00000020
#घोषणा RRF_RT_REG_QWORD 0x00000040

#घोषणा RRF_RT_DWORD (RRF_RT_REG_द्विआधारी | RRF_RT_REG_DWORD)
#घोषणा RRF_RT_QWORD (RRF_RT_REG_द्विआधारी | RRF_RT_REG_QWORD)
#घोषणा RRF_RT_ANY 0x0000ffff

#घोषणा RRF_NOEXPAND 0x10000000
#घोषणा RRF_ZEROONFAILURE 0x20000000

  प्रकार ACCESS_MASK REGSAM;

#घोषणा HKEY_CLASSES_मूल ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#घोषणा HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#घोषणा HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#घोषणा HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#घोषणा HKEY_PERFORMANCE_तथ्य ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#घोषणा HKEY_PERFORMANCE_TEXT ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#घोषणा HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#घोषणा HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#घोषणा HKEY_DYN_तथ्य ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#घोषणा REG_SECURE_CONNECTION 1

#अगर_अघोषित _PROVIDER_STRUCTS_DEFINED
#घोषणा _PROVIDER_STRUCTS_DEFINED

#घोषणा PROVIDER_KEEPS_मूल्य_लंबाई 0x1
  काष्ठा val_context {
    पूर्णांक valuelen;
    LPVOID मूल्य_context;
    LPVOID val_buff_ptr;
  };

  प्रकार काष्ठा val_context *PVALCONTEXT;

  प्रकार काष्ठा pvalueA {
    LPSTR pv_valuename;
    पूर्णांक pv_valuelen;
    LPVOID pv_मूल्य_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  प्रकार काष्ठा pvalueW {
    LPWSTR pv_valuename;
    पूर्णांक pv_valuelen;
    LPVOID pv_मूल्य_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#अगर_घोषित UNICODE
  प्रकार PVALUEW PVALUE;
  प्रकार PPVALUEW PPVALUE;
#अन्यथा
  प्रकार PVALUEA PVALUE;
  प्रकार PPVALUEA PPVALUE;
#पूर्ण_अगर

  प्रकार DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD अंक_vals,LPVOID outputbuffer,DWORD *योग_outlen,DWORD निवेश_blen);

  प्रकार QUERYHANDLER *PQUERYHANDLER;

  प्रकार काष्ठा provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_कुंजी_context;
  } REG_PROVIDER;

  प्रकार काष्ठा provider_info *PPROVIDER;

  प्रकार काष्ठा मूल्य_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  प्रकार काष्ठा मूल्य_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#अगर_घोषित UNICODE
  प्रकार VALENTW VALENT;
  प्रकार PVALENTW PVALENT;
#अन्यथा
  प्रकार VALENTA VALENT;
  प्रकार PVALENTA PVALENT;
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा WIN31_CLASS शून्य

#अगर_घोषित UNICODE
#घोषणा RegConnectRegistry RegConnectRegistryW
#घोषणा RegConnectRegistryEx RegConnectRegistryExW
#घोषणा Reg_Create_कुंजी Reg_Create_कुंजी_W
#घोषणा Reg_Create_कुंजी_Ex Reg_Create_कुंजी_Ex_W
#घोषणा Reg_Delete_कुंजी Reg_Delete_कुंजी_W
#घोषणा Reg_Delete_कुंजी_Ex Reg_Delete_कुंजी_Ex_W
#घोषणा Reg_Delete_मूल्य Reg_Delete_मूल्य_W
#घोषणा Reg_Enum_कुंजी Reg_Enum_कुंजी_W
#घोषणा Reg_Enum_कुंजी_Ex Reg_Enum_कुंजी_Ex_W
#घोषणा Reg_Enum_मूल्य Reg_Enum_मूल्य_W
#घोषणा Reg_Load_कुंजी Reg_Load_कुंजी_W
#घोषणा Reg_Open_कुंजी Reg_Open_कुंजी_W
#घोषणा Reg_Open_कुंजी_Ex Reg_Open_कुंजी_Ex_W
#घोषणा Reg_Query_Info_कुंजी Reg_Query_Info_कुंजी_W
#घोषणा Reg_Query_मूल्य Reg_Query_मूल्य_W
#घोषणा Reg_Query_Multiple_मूल्यावली Reg_Query_Multiple_मूल्यावली_W
#घोषणा Reg_Query_मूल्य_Ex Reg_Query_मूल्य_Ex_W
#घोषणा Reg_Replace_कुंजी Reg_Replace_कुंजी_W
#घोषणा Reg_Restore_कुंजी Reg_Restore_कुंजी_W
#घोषणा Reg_Save_कुंजी Reg_Save_कुंजी_W
#घोषणा Reg_Set_मूल्य Reg_Set_मूल्य_W
#घोषणा Reg_Set_मूल्य_Ex Reg_Set_मूल्य_Ex_W
#घोषणा Reg_Un_Load_कुंजी Reg_Un_Load_कुंजी_W
#घोषणा Reg_Get_मूल्य Reg_Get_मूल्य_W
#घोषणा InitiateSystemShutdown InitiateSystemShutdownW
#घोषणा AbortSystemShutdown AbortSystemShutdownW
#अन्यथा
#घोषणा RegConnectRegistry RegConnectRegistryA
#घोषणा RegConnectRegistryEx RegConnectRegistryExA
#घोषणा Reg_Create_कुंजी Reg_Create_कुंजी_A
#घोषणा Reg_Create_कुंजी_Ex Reg_Create_कुंजी_Ex_A
#घोषणा Reg_Delete_कुंजी Reg_Delete_कुंजी_A
#घोषणा Reg_Delete_कुंजी_Ex Reg_Delete_कुंजी_Ex_A
#घोषणा Reg_Delete_मूल्य Reg_Delete_मूल्य_A
#घोषणा Reg_Enum_कुंजी Reg_Enum_कुंजी_A
#घोषणा Reg_Enum_कुंजी_Ex Reg_Enum_कुंजी_Ex_A
#घोषणा Reg_Enum_मूल्य Reg_Enum_मूल्य_A
#घोषणा Reg_Load_कुंजी Reg_Load_कुंजी_A
#घोषणा Reg_Open_कुंजी Reg_Open_कुंजी_A
#घोषणा Reg_Open_कुंजी_Ex Reg_Open_कुंजी_Ex_A
#घोषणा Reg_Query_Info_कुंजी Reg_Query_Info_कुंजी_A
#घोषणा Reg_Query_मूल्य Reg_Query_मूल्य_A
#घोषणा Reg_Query_Multiple_मूल्यावली Reg_Query_Multiple_मूल्यावली_A
#घोषणा Reg_Query_मूल्य_Ex Reg_Query_मूल्य_Ex_A
#घोषणा Reg_Replace_कुंजी Reg_Replace_कुंजी_A
#घोषणा Reg_Restore_कुंजी Reg_Restore_कुंजी_A
#घोषणा Reg_Save_कुंजी Reg_Save_कुंजी_A
#घोषणा Reg_Set_मूल्य Reg_Set_मूल्य_A
#घोषणा Reg_Set_मूल्य_Ex Reg_Set_मूल्य_Ex_A
#घोषणा Reg_Un_Load_कुंजी Reg_Un_Load_कुंजी_A
#घोषणा Reg_Get_मूल्य Reg_Get_मूल्य_A
#घोषणा InitiateSystemShutdown InitiateSystemShutdownA
#घोषणा AbortSystemShutdown AbortSystemShutdownA
#पूर्ण_अगर

  WINADVAPI LONG WINAPI Reg_Close_कुंजी(HKEY h_कुंजी);
  WINADVAPI LONG WINAPI Reg_Override_Predef_कुंजी(HKEY h_कुंजी,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_मूल(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_कुंजी,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_कुंजी,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_कुंजी,ULONG Flags,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_कुंजी,ULONG Flags,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Create_कुंजी_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Create_कुंजी_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Create_कुंजी_Ex_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phk_परिणाम,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_कुंजी_Ex_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ATTRIBUTES lpSecurityAttributes,PHKEY phk_परिणाम,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_कुंजी_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी);
  WINADVAPI LONG WINAPI Reg_Delete_कुंजी_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी);
  WINADVAPI LONG WINAPI Reg_Delete_कुंजी_Ex_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_कुंजी_Ex_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_कुंजी(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_कुंजी(HKEY hBase);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_कुंजी(HKEY hBase,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_मूल्य_A(HKEY h_कुंजी,LPCSTR lp_मूल्य_Name);
  WINADVAPI LONG WINAPI Reg_Delete_मूल्य_W(HKEY h_कुंजी,LPCWSTR lp_मूल्य_Name);
  WINADVAPI LONG WINAPI Reg_Enum_कुंजी_A(HKEY h_कुंजी,DWORD dw_सूचकांक,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_कुंजी_W(HKEY h_कुंजी,DWORD dw_सूचकांक,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_कुंजी_Ex_A(HKEY h_कुंजी,DWORD dw_सूचकांक,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_कुंजी_Ex_W(HKEY h_कुंजी,DWORD dw_सूचकांक,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Enum_मूल्य_A(HKEY h_कुंजी,DWORD dw_सूचकांक,LPSTR lp_मूल्य_Name,LPDWORD lpcch_मूल्य_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_तथ्य,LPDWORD lpcb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Enum_मूल्य_W(HKEY h_कुंजी,DWORD dw_सूचकांक,LPWSTR lp_मूल्य_Name,LPDWORD lpcch_मूल्य_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_तथ्य,LPDWORD lpcb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Flush_कुंजी(HKEY h_कुंजी);
  WINADVAPI LONG WINAPI Reg_Get_कुंजी_Security(HKEY h_कुंजी,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Load_कुंजी_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Load_कुंजी_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_कुंजी_मूल्य(HKEY h_कुंजी,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_कुंजी_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Open_कुंजी_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Open_कुंजी_Ex_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी,DWORD ulOptions,REGSAM samDesired,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Open_कुंजी_Ex_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी,DWORD ulOptions,REGSAM samDesired,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Query_Info_कुंजी_A(HKEY h_कुंजी,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_कुंजियाँ,LPDWORD lpcb_Max_Sub_कुंजी_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_मूल्यावली,LPDWORD lpcb_Max_मूल्य_Name_Len,LPDWORD lpcb_Max_मूल्य_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_Info_कुंजी_W(HKEY h_कुंजी,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_कुंजियाँ,LPDWORD lpcb_Max_Sub_कुंजी_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_मूल्यावली,LPDWORD lpcb_Max_मूल्य_Name_Len,LPDWORD lpcb_Max_मूल्य_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpftLastWriteTime);
  WINADVAPI LONG WINAPI Reg_Query_मूल्य_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी,LPSTR lp_तथ्य,PLONG lpcb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Query_मूल्य_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी,LPWSTR lp_तथ्य,PLONG lpcb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_मूल्यावली_A(HKEY h_कुंजी,PVALENTA val_list,DWORD अंक_vals,LPSTR lp_मूल्य_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_Multiple_मूल्यावली_W(HKEY h_कुंजी,PVALENTW val_list,DWORD अंक_vals,LPWSTR lp_मूल्य_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_मूल्य_Ex_A(HKEY h_कुंजी,LPCSTR lp_मूल्य_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_तथ्य,LPDWORD lpcb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Query_मूल्य_Ex_W(HKEY h_कुंजी,LPCWSTR lp_मूल्य_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_तथ्य,LPDWORD lpcb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Replace_कुंजी_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_कुंजी_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_कुंजी_A(HKEY h_कुंजी,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_कुंजी_W(HKEY h_कुंजी,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_कुंजी_A(HKEY h_कुंजी,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Save_कुंजी_W(HKEY h_कुंजी,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINADVAPI LONG WINAPI Reg_Set_कुंजी_Security(HKEY h_कुंजी,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_Set_मूल्य_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी,DWORD dwType,LPCSTR lp_तथ्य,DWORD cb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Set_मूल्य_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी,DWORD dwType,LPCWSTR lp_तथ्य,DWORD cb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Set_मूल्य_Ex_A(HKEY h_कुंजी,LPCSTR lp_मूल्य_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_तथ्य,DWORD cb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Set_मूल्य_Ex_W(HKEY h_कुंजी,LPCWSTR lp_मूल्य_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_तथ्य,DWORD cb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Un_Load_कुंजी_A(HKEY h_कुंजी,LPCSTR lp_Sub_कुंजी);
  WINADVAPI LONG WINAPI Reg_Un_Load_कुंजी_W(HKEY h_कुंजी,LPCWSTR lp_Sub_कुंजी);
  WINADVAPI LONG WINAPI Reg_Get_मूल्य_A(HKEY hkey,LPCSTR lp_Sub_कुंजी,LPCSTR lp_मूल्य,DWORD dwFlags,LPDWORD pdwType,PVOID pv_तथ्य,LPDWORD pcb_तथ्य);
  WINADVAPI LONG WINAPI Reg_Get_मूल्य_W(HKEY hkey,LPCWSTR lp_Sub_कुंजी,LPCWSTR lp_मूल्य,DWORD dwFlags,LPDWORD pdwType,PVOID pv_तथ्य,LPDWORD pcb_तथ्य);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#घोषणा REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#घोषणा REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#घोषणा REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#घोषणा REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#घोषणा REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#घोषणा REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#घोषणा REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#घोषणा REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#घोषणा REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#घोषणा MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#अगर_घोषित UNICODE
#घोषणा InitiateSystemShutdownEx InitiateSystemShutdownExW
#घोषणा Reg_Save_कुंजी_Ex Reg_Save_कुंजी_Ex_W
#अन्यथा
#घोषणा InitiateSystemShutdownEx InitiateSystemShutdownExA
#घोषणा Reg_Save_कुंजी_Ex Reg_Save_कुंजी_Ex_A
#पूर्ण_अगर

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lpMessage,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_कुंजी_Ex_A(HKEY h_कुंजी,LPCSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_कुंजी_Ex_W(HKEY h_कुंजी,LPCWSTR lpFile,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64Win32ApiEntry (DWORD dw_Func_संख्या,DWORD dwFlag,DWORD dwRes);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
