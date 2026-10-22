/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _WINREG_
#تعریف_کړه _WINREG_

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی WINVER
#تعریف_کړه WINVER 0x0502
#د_که_پای

#تعریف_کړه RRF_RT_REG_NONE 0x00000001
#تعریف_کړه RRF_RT_REG_SZ 0x00000002
#تعریف_کړه RRF_RT_REG_EXPAND_SZ 0x00000004
#تعریف_کړه RRF_RT_REG_دوګونی 0x00000008
#تعریف_کړه RRF_RT_REG_DWORD 0x00000010
#تعریف_کړه RRF_RT_REG_MULTI_SZ 0x00000020
#تعریف_کړه RRF_RT_REG_QWORD 0x00000040

#تعریف_کړه RRF_RT_DWORD (RRF_RT_REG_دوګونی | RRF_RT_REG_DWORD)
#تعریف_کړه RRF_RT_QWORD (RRF_RT_REG_دوګونی | RRF_RT_REG_QWORD)
#تعریف_کړه RRF_RT_ANY 0x0000ffff

#تعریف_کړه RRF_NOEXPAND 0x10000000
#تعریف_کړه RRF_ZEROONFAILURE 0x20000000

  تعريفنوع ACCESS_ماسک REGSAM;

#تعریف_کړه HKEY_CLASSES_ریښه ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#تعریف_کړه HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#تعریف_کړه HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#تعریف_کړه HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#تعریف_کړه HKEY_PERFORMANCE_معلومات ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#تعریف_کړه HKEY_PERFORMANCE_متن ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#تعریف_کړه HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#تعریف_کړه HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#تعریف_کړه HKEY_DYN_معلومات ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#تعریف_کړه REG_SECURE_CONNECTION 1

#که_نه_تعریف_شوی _PROVIDER_STRUCTS_DEFINED
#تعریف_کړه _PROVIDER_STRUCTS_DEFINED

#تعریف_کړه PROVIDER_KEEPS_ارزښت_اوږدتیا 0x1
  بنية val_context {
    صحيح valuelen;
    LPVOID ارزښت_context;
    LPVOID val_buff_ptr;
  };

  تعريفنوع بنية val_context *PVALCONTEXT;

  تعريفنوع بنية pvalueA {
    LPSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_ارزښت_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  تعريفنوع بنية pvalueW {
    LPWSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_ارزښت_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#که_تعریف_شوی UNICODE
  تعريفنوع PVALUEW PVALUE;
  تعريفنوع PPVALUEW PPVALUE;
#وإلا
  تعريفنوع PVALUEA PVALUE;
  تعريفنوع PPVALUEA PPVALUE;
#د_که_پای

  تعريفنوع DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD عدد_vals,LPVOID outputbuffer,DWORD *ټول_outlen,DWORD ننوت_blen);

  تعريفنوع QUERYHANDLER *PQUERYHANDLER;

  تعريفنوع بنية provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_کلی_context;
  } REG_PROVIDER;

  تعريفنوع بنية provider_info *PPROVIDER;

  تعريفنوع بنية ارزښت_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  تعريفنوع بنية ارزښت_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#که_تعریف_شوی UNICODE
  تعريفنوع VALENTW VALENT;
  تعريفنوع PVALENTW PVALENT;
#وإلا
  تعريفنوع VALENTA VALENT;
  تعريفنوع PVALENTA PVALENT;
#د_که_پای
#د_که_پای

#تعریف_کړه WIN31_CLASS عدم

#که_تعریف_شوی UNICODE
#تعریف_کړه RegConnectRegistry RegConnectRegistryW
#تعریف_کړه RegConnectRegistryEx RegConnectRegistryExW
#تعریف_کړه Reg_Create_کلی Reg_Create_کلی_W
#تعریف_کړه Reg_Create_کلی_Ex Reg_Create_کلی_Ex_W
#تعریف_کړه Reg_Delete_کلی Reg_Delete_کلی_W
#تعریف_کړه Reg_Delete_کلی_Ex Reg_Delete_کلی_Ex_W
#تعریف_کړه Reg_Delete_ارزښت Reg_Delete_ارزښت_W
#تعریف_کړه Reg_Enum_کلی Reg_Enum_کلی_W
#تعریف_کړه Reg_Enum_کلی_Ex Reg_Enum_کلی_Ex_W
#تعریف_کړه Reg_Enum_ارزښت Reg_Enum_ارزښت_W
#تعریف_کړه Reg_بارول_کلی Reg_بارول_کلی_W
#تعریف_کړه Reg_Open_کلی Reg_Open_کلی_W
#تعریف_کړه Reg_Open_کلی_Ex Reg_Open_کلی_Ex_W
#تعریف_کړه Reg_Query_Info_کلی Reg_Query_Info_کلی_W
#تعریف_کړه Reg_Query_ارزښت Reg_Query_ارزښت_W
#تعریف_کړه Reg_Query_مضرب_ارزښتونه Reg_Query_مضرب_ارزښتونه_W
#تعریف_کړه Reg_Query_ارزښت_Ex Reg_Query_ارزښت_Ex_W
#تعریف_کړه Reg_Replace_کلی Reg_Replace_کلی_W
#تعریف_کړه Reg_Restore_کلی Reg_Restore_کلی_W
#تعریف_کړه Reg_Save_کلی Reg_Save_کلی_W
#تعریف_کړه Reg_سېټ_ارزښت Reg_سېټ_ارزښت_W
#تعریف_کړه Reg_سېټ_ارزښت_Ex Reg_سېټ_ارزښت_Ex_W
#تعریف_کړه Reg_Un_بارول_کلی Reg_Un_بارول_کلی_W
#تعریف_کړه Reg_Get_ارزښت Reg_Get_ارزښت_W
#تعریف_کړه InitiateSystemShutdown InitiateSystemShutdownW
#تعریف_کړه AbortSystemShutdown AbortSystemShutdownW
#وإلا
#تعریف_کړه RegConnectRegistry RegConnectRegistryA
#تعریف_کړه RegConnectRegistryEx RegConnectRegistryExA
#تعریف_کړه Reg_Create_کلی Reg_Create_کلی_A
#تعریف_کړه Reg_Create_کلی_Ex Reg_Create_کلی_Ex_A
#تعریف_کړه Reg_Delete_کلی Reg_Delete_کلی_A
#تعریف_کړه Reg_Delete_کلی_Ex Reg_Delete_کلی_Ex_A
#تعریف_کړه Reg_Delete_ارزښت Reg_Delete_ارزښت_A
#تعریف_کړه Reg_Enum_کلی Reg_Enum_کلی_A
#تعریف_کړه Reg_Enum_کلی_Ex Reg_Enum_کلی_Ex_A
#تعریف_کړه Reg_Enum_ارزښت Reg_Enum_ارزښت_A
#تعریف_کړه Reg_بارول_کلی Reg_بارول_کلی_A
#تعریف_کړه Reg_Open_کلی Reg_Open_کلی_A
#تعریف_کړه Reg_Open_کلی_Ex Reg_Open_کلی_Ex_A
#تعریف_کړه Reg_Query_Info_کلی Reg_Query_Info_کلی_A
#تعریف_کړه Reg_Query_ارزښت Reg_Query_ارزښت_A
#تعریف_کړه Reg_Query_مضرب_ارزښتونه Reg_Query_مضرب_ارزښتونه_A
#تعریف_کړه Reg_Query_ارزښت_Ex Reg_Query_ارزښت_Ex_A
#تعریف_کړه Reg_Replace_کلی Reg_Replace_کلی_A
#تعریف_کړه Reg_Restore_کلی Reg_Restore_کلی_A
#تعریف_کړه Reg_Save_کلی Reg_Save_کلی_A
#تعریف_کړه Reg_سېټ_ارزښت Reg_سېټ_ارزښت_A
#تعریف_کړه Reg_سېټ_ارزښت_Ex Reg_سېټ_ارزښت_Ex_A
#تعریف_کړه Reg_Un_بارول_کلی Reg_Un_بارول_کلی_A
#تعریف_کړه Reg_Get_ارزښت Reg_Get_ارزښت_A
#تعریف_کړه InitiateSystemShutdown InitiateSystemShutdownA
#تعریف_کړه AbortSystemShutdown AbortSystemShutdownA
#د_که_پای

  WINADVAPI LONG WINAPI Reg_Close_کلی(HKEY h_کلی);
  WINADVAPI LONG WINAPI Reg_Override_Predef_کلی(HKEY h_کلی,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_ریښه(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_کلی,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_کلی,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_کلی,ULONG Flags,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_کلی,ULONG Flags,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI Reg_Create_کلی_A(HKEY h_کلی,LPCSTR lp_Sub_کلی,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI Reg_Create_کلی_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI Reg_Create_کلی_Ex_A(HKEY h_کلی,LPCSTR lp_Sub_کلی,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې,PHKEY phk_پایله,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_کلی_Ex_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې,PHKEY phk_پایله,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_کلی_A(HKEY h_کلی,LPCSTR lp_Sub_کلی);
  WINADVAPI LONG WINAPI Reg_Delete_کلی_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی);
  WINADVAPI LONG WINAPI Reg_Delete_کلی_Ex_A(HKEY h_کلی,LPCSTR lp_Sub_کلی,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_کلی_Ex_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_کلی(HKEY h_بنسټ);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_کلی(HKEY h_بنسټ);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_کلی(HKEY h_بنسټ,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_ارزښت_A(HKEY h_کلی,LPCSTR lp_ارزښت_Name);
  WINADVAPI LONG WINAPI Reg_Delete_ارزښت_W(HKEY h_کلی,LPCWSTR lp_ارزښت_Name);
  WINADVAPI LONG WINAPI Reg_Enum_کلی_A(HKEY h_کلی,DWORD dw_شاخص,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلی_W(HKEY h_کلی,DWORD dw_شاخص,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلی_Ex_A(HKEY h_کلی,DWORD dw_شاخص,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_وروستی_Write_وخت);
  WINADVAPI LONG WINAPI Reg_Enum_کلی_Ex_W(HKEY h_کلی,DWORD dw_شاخص,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_وروستی_Write_وخت);
  WINADVAPI LONG WINAPI Reg_Enum_ارزښت_A(HKEY h_کلی,DWORD dw_شاخص,LPSTR lp_ارزښت_Name,LPDWORD lpcch_ارزښت_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_معلومات,LPDWORD lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Enum_ارزښت_W(HKEY h_کلی,DWORD dw_شاخص,LPWSTR lp_ارزښت_Name,LPDWORD lpcch_ارزښت_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_معلومات,LPDWORD lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Flush_کلی(HKEY h_کلی);
  WINADVAPI LONG WINAPI Reg_Get_کلی_Security(HKEY h_کلی,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_بارول_کلی_A(HKEY h_کلی,LPCSTR lp_Sub_کلی,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_بارول_کلی_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_کلی_ارزښت(HKEY h_کلی,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_کلی_A(HKEY h_کلی,LPCSTR lp_Sub_کلی,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI Reg_Open_کلی_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI Reg_Open_کلی_Ex_A(HKEY h_کلی,LPCSTR lp_Sub_کلی,DWORD ulOptions,REGSAM samDesired,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI Reg_Open_کلی_Ex_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی,DWORD ulOptions,REGSAM samDesired,PHKEY phk_پایله);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلی_A(HKEY h_کلی,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیګانې,LPDWORD lpcb_Max_Sub_کلی_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_ارزښتونه,LPDWORD lpcb_Max_ارزښت_Name_Len,LPDWORD lpcb_Max_ارزښت_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_وروستی_Write_وخت);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلی_W(HKEY h_کلی,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیګانې,LPDWORD lpcb_Max_Sub_کلی_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_ارزښتونه,LPDWORD lpcb_Max_ارزښت_Name_Len,LPDWORD lpcb_Max_ارزښت_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_وروستی_Write_وخت);
  WINADVAPI LONG WINAPI Reg_Query_ارزښت_A(HKEY h_کلی,LPCSTR lp_Sub_کلی,LPSTR lp_معلومات,PLONG lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Query_ارزښت_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی,LPWSTR lp_معلومات,PLONG lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Query_مضرب_ارزښتونه_A(HKEY h_کلی,PVALENTA val_list,DWORD عدد_vals,LPSTR lp_ارزښت_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_مضرب_ارزښتونه_W(HKEY h_کلی,PVALENTW val_list,DWORD عدد_vals,LPWSTR lp_ارزښت_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_ارزښت_Ex_A(HKEY h_کلی,LPCSTR lp_ارزښت_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_معلومات,LPDWORD lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Query_ارزښت_Ex_W(HKEY h_کلی,LPCWSTR lp_ارزښت_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_معلومات,LPDWORD lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Replace_کلی_A(HKEY h_کلی,LPCSTR lp_Sub_کلی,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_کلی_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_کلی_A(HKEY h_کلی,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_کلی_W(HKEY h_کلی,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_کلی_A(HKEY h_کلی,LPCSTR lpFile,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINADVAPI LONG WINAPI Reg_Save_کلی_W(HKEY h_کلی,LPCWSTR lpFile,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINADVAPI LONG WINAPI Reg_سېټ_کلی_Security(HKEY h_کلی,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_سېټ_ارزښت_A(HKEY h_کلی,LPCSTR lp_Sub_کلی,DWORD dwType,LPCSTR lp_معلومات,DWORD cb_معلومات);
  WINADVAPI LONG WINAPI Reg_سېټ_ارزښت_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی,DWORD dwType,LPCWSTR lp_معلومات,DWORD cb_معلومات);
  WINADVAPI LONG WINAPI Reg_سېټ_ارزښت_Ex_A(HKEY h_کلی,LPCSTR lp_ارزښت_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_معلومات,DWORD cb_معلومات);
  WINADVAPI LONG WINAPI Reg_سېټ_ارزښت_Ex_W(HKEY h_کلی,LPCWSTR lp_ارزښت_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_معلومات,DWORD cb_معلومات);
  WINADVAPI LONG WINAPI Reg_Un_بارول_کلی_A(HKEY h_کلی,LPCSTR lp_Sub_کلی);
  WINADVAPI LONG WINAPI Reg_Un_بارول_کلی_W(HKEY h_کلی,LPCWSTR lp_Sub_کلی);
  WINADVAPI LONG WINAPI Reg_Get_ارزښت_A(HKEY hkey,LPCSTR lp_Sub_کلی,LPCSTR lp_ارزښت,DWORD dwFlags,LPDWORD pdwType,PVOID pv_معلومات,LPDWORD pcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Get_ارزښت_W(HKEY hkey,LPCWSTR lp_Sub_کلی,LPCWSTR lp_ارزښت,DWORD dwFlags,LPDWORD pdwType,PVOID pv_معلومات,LPDWORD pcb_معلومات);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lp_پیغام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lp_پیغام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#تعریف_کړه REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#تعریف_کړه REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#تعریف_کړه REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#تعریف_کړه REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#تعریف_کړه REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#تعریف_کړه REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#تعریف_کړه REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#تعریف_کړه REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#تعریف_کړه REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#تعریف_کړه MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#که_تعریف_شوی UNICODE
#تعریف_کړه InitiateSystemShutdownEx InitiateSystemShutdownExW
#تعریف_کړه Reg_Save_کلی_Ex Reg_Save_کلی_Ex_W
#وإلا
#تعریف_کړه InitiateSystemShutdownEx InitiateSystemShutdownExA
#تعریف_کړه Reg_Save_کلی_Ex Reg_Save_کلی_Ex_A
#د_که_پای

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lp_پیغام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lp_پیغام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_کلی_Ex_A(HKEY h_کلی,LPCSTR lpFile,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_کلی_Ex_W(HKEY h_کلی,LPCWSTR lpFile,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64_Win32_Api_ثبت (DWORD dw_Func_شمېره,DWORD dwFlag,DWORD dwRes);

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
