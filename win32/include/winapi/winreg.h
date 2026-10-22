/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _WINREG_
#وصف_ڪريو _WINREG_

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WINVER
#وصف_ڪريو WINVER 0x0502
#جيڪڏهن_پورو

#وصف_ڪريو RRF_RT_REG_NONE 0x00000001
#وصف_ڪريو RRF_RT_REG_SZ 0x00000002
#وصف_ڪريو RRF_RT_REG_EXPAND_SZ 0x00000004
#وصف_ڪريو RRF_RT_REG_ٻٽو 0x00000008
#وصف_ڪريو RRF_RT_REG_DWORD 0x00000010
#وصف_ڪريو RRF_RT_REG_MULTI_SZ 0x00000020
#وصف_ڪريو RRF_RT_REG_QWORD 0x00000040

#وصف_ڪريو RRF_RT_DWORD (RRF_RT_REG_ٻٽو | RRF_RT_REG_DWORD)
#وصف_ڪريو RRF_RT_QWORD (RRF_RT_REG_ٻٽو | RRF_RT_REG_QWORD)
#وصف_ڪريو RRF_RT_ANY 0x0000ffff

#وصف_ڪريو RRF_NOEXPAND 0x10000000
#وصف_ڪريو RRF_ZEROONFAILURE 0x20000000

  تعريفنوع ACCESS_نقاب REGSAM;

#وصف_ڪريو HKEY_CLASSES_پاڙ ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#وصف_ڪريو HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#وصف_ڪريو HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#وصف_ڪريو HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#وصف_ڪريو HKEY_PERFORMANCE_معلومات ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#وصف_ڪريو HKEY_PERFORMANCE_متن ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#وصف_ڪريو HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#وصف_ڪريو HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#وصف_ڪريو HKEY_DYN_معلومات ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#وصف_ڪريو REG_SECURE_CONNECTION 1

#جيڪڏهن_وصف_نه_ٿيل _PROVIDER_STRUCTS_DEFINED
#وصف_ڪريو _PROVIDER_STRUCTS_DEFINED

#وصف_ڪريو PROVIDER_KEEPS_قدر_ڊيگهائي 0x1
  بنية val_context {
    صحيح valuelen;
    LPVOID قدر_context;
    LPVOID val_buff_ptr;
  };

  تعريفنوع بنية val_context *PVALCONTEXT;

  تعريفنوع بنية pvalueA {
    LPSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_قدر_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  تعريفنوع بنية pvalueW {
    LPWSTR pv_valuename;
    صحيح pv_valuelen;
    LPVOID pv_قدر_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع PVALUEW PVALUE;
  تعريفنوع PPVALUEW PPVALUE;
#وإلا
  تعريفنوع PVALUEA PVALUE;
  تعريفنوع PPVALUEA PPVALUE;
#جيڪڏهن_پورو

  تعريفنوع DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD انگ_vals,LPVOID outputbuffer,DWORD *ڪل_outlen,DWORD داخلا_blen);

  تعريفنوع QUERYHANDLER *PQUERYHANDLER;

  تعريفنوع بنية provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_ڪنجي_context;
  } REG_PROVIDER;

  تعريفنوع بنية provider_info *PPROVIDER;

  تعريفنوع بنية قدر_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  تعريفنوع بنية قدر_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع VALENTW VALENT;
  تعريفنوع PVALENTW PVALENT;
#وإلا
  تعريفنوع VALENTA VALENT;
  تعريفنوع PVALENTA PVALENT;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو WIN31_CLASS عدم

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو RegConnectRegistry RegConnectRegistryW
#وصف_ڪريو RegConnectRegistryEx RegConnectRegistryExW
#وصف_ڪريو Reg_Create_ڪنجي Reg_Create_ڪنجي_W
#وصف_ڪريو Reg_Create_ڪنجي_Ex Reg_Create_ڪنجي_Ex_W
#وصف_ڪريو Reg_Delete_ڪنجي Reg_Delete_ڪنجي_W
#وصف_ڪريو Reg_Delete_ڪنجي_Ex Reg_Delete_ڪنجي_Ex_W
#وصف_ڪريو Reg_Delete_قدر Reg_Delete_قدر_W
#وصف_ڪريو Reg_Enum_ڪنجي Reg_Enum_ڪنجي_W
#وصف_ڪريو Reg_Enum_ڪنجي_Ex Reg_Enum_ڪنجي_Ex_W
#وصف_ڪريو Reg_Enum_قدر Reg_Enum_قدر_W
#وصف_ڪريو Reg_ڀريو_ڪنجي Reg_ڀريو_ڪنجي_W
#وصف_ڪريو Reg_Open_ڪنجي Reg_Open_ڪنجي_W
#وصف_ڪريو Reg_Open_ڪنجي_Ex Reg_Open_ڪنجي_Ex_W
#وصف_ڪريو Reg_Query_Info_ڪنجي Reg_Query_Info_ڪنجي_W
#وصف_ڪريو Reg_Query_قدر Reg_Query_قدر_W
#وصف_ڪريو Reg_Query_گڻو_قدرون Reg_Query_گڻو_قدرون_W
#وصف_ڪريو Reg_Query_قدر_Ex Reg_Query_قدر_Ex_W
#وصف_ڪريو Reg_Replace_ڪنجي Reg_Replace_ڪنجي_W
#وصف_ڪريو Reg_Restore_ڪنجي Reg_Restore_ڪنجي_W
#وصف_ڪريو Reg_Save_ڪنجي Reg_Save_ڪنجي_W
#وصف_ڪريو Reg_سيٽ_قدر Reg_سيٽ_قدر_W
#وصف_ڪريو Reg_سيٽ_قدر_Ex Reg_سيٽ_قدر_Ex_W
#وصف_ڪريو Reg_Un_ڀريو_ڪنجي Reg_Un_ڀريو_ڪنجي_W
#وصف_ڪريو Reg_Get_قدر Reg_Get_قدر_W
#وصف_ڪريو InitiateSystemShutdown InitiateSystemShutdownW
#وصف_ڪريو AbortSystemShutdown AbortSystemShutdownW
#وإلا
#وصف_ڪريو RegConnectRegistry RegConnectRegistryA
#وصف_ڪريو RegConnectRegistryEx RegConnectRegistryExA
#وصف_ڪريو Reg_Create_ڪنجي Reg_Create_ڪنجي_A
#وصف_ڪريو Reg_Create_ڪنجي_Ex Reg_Create_ڪنجي_Ex_A
#وصف_ڪريو Reg_Delete_ڪنجي Reg_Delete_ڪنجي_A
#وصف_ڪريو Reg_Delete_ڪنجي_Ex Reg_Delete_ڪنجي_Ex_A
#وصف_ڪريو Reg_Delete_قدر Reg_Delete_قدر_A
#وصف_ڪريو Reg_Enum_ڪنجي Reg_Enum_ڪنجي_A
#وصف_ڪريو Reg_Enum_ڪنجي_Ex Reg_Enum_ڪنجي_Ex_A
#وصف_ڪريو Reg_Enum_قدر Reg_Enum_قدر_A
#وصف_ڪريو Reg_ڀريو_ڪنجي Reg_ڀريو_ڪنجي_A
#وصف_ڪريو Reg_Open_ڪنجي Reg_Open_ڪنجي_A
#وصف_ڪريو Reg_Open_ڪنجي_Ex Reg_Open_ڪنجي_Ex_A
#وصف_ڪريو Reg_Query_Info_ڪنجي Reg_Query_Info_ڪنجي_A
#وصف_ڪريو Reg_Query_قدر Reg_Query_قدر_A
#وصف_ڪريو Reg_Query_گڻو_قدرون Reg_Query_گڻو_قدرون_A
#وصف_ڪريو Reg_Query_قدر_Ex Reg_Query_قدر_Ex_A
#وصف_ڪريو Reg_Replace_ڪنجي Reg_Replace_ڪنجي_A
#وصف_ڪريو Reg_Restore_ڪنجي Reg_Restore_ڪنجي_A
#وصف_ڪريو Reg_Save_ڪنجي Reg_Save_ڪنجي_A
#وصف_ڪريو Reg_سيٽ_قدر Reg_سيٽ_قدر_A
#وصف_ڪريو Reg_سيٽ_قدر_Ex Reg_سيٽ_قدر_Ex_A
#وصف_ڪريو Reg_Un_ڀريو_ڪنجي Reg_Un_ڀريو_ڪنجي_A
#وصف_ڪريو Reg_Get_قدر Reg_Get_قدر_A
#وصف_ڪريو InitiateSystemShutdown InitiateSystemShutdownA
#وصف_ڪريو AbortSystemShutdown AbortSystemShutdownA
#جيڪڏهن_پورو

  WINADVAPI LONG WINAPI Reg_Close_ڪنجي(HKEY h_ڪنجي);
  WINADVAPI LONG WINAPI Reg_Override_Predef_ڪنجي(HKEY h_ڪنجي,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_پاڙ(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_ڪنجي,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_ڪنجي,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_ڪنجي,ULONG Flags,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_ڪنجي,ULONG Flags,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI Reg_Create_ڪنجي_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI Reg_Create_ڪنجي_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI Reg_Create_ڪنجي_Ex_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_خاصيتون lp_Security_خاصيتون,PHKEY phk_نتيجو,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_ڪنجي_Ex_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_خاصيتون lp_Security_خاصيتون,PHKEY phk_نتيجو,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_ڪنجي_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي);
  WINADVAPI LONG WINAPI Reg_Delete_ڪنجي_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي);
  WINADVAPI LONG WINAPI Reg_Delete_ڪنجي_Ex_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_ڪنجي_Ex_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_ڪنجي(HKEY h_بنياد);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_ڪنجي(HKEY h_بنياد);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_ڪنجي(HKEY h_بنياد,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_قدر_A(HKEY h_ڪنجي,LPCSTR lp_قدر_Name);
  WINADVAPI LONG WINAPI Reg_Delete_قدر_W(HKEY h_ڪنجي,LPCWSTR lp_قدر_Name);
  WINADVAPI LONG WINAPI Reg_Enum_ڪنجي_A(HKEY h_ڪنجي,DWORD dw_اشاريو,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ڪنجي_W(HKEY h_ڪنجي,DWORD dw_اشاريو,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ڪنجي_Ex_A(HKEY h_ڪنجي,DWORD dw_اشاريو,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_آخري_Write_وقت);
  WINADVAPI LONG WINAPI Reg_Enum_ڪنجي_Ex_W(HKEY h_ڪنجي,DWORD dw_اشاريو,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_آخري_Write_وقت);
  WINADVAPI LONG WINAPI Reg_Enum_قدر_A(HKEY h_ڪنجي,DWORD dw_اشاريو,LPSTR lp_قدر_Name,LPDWORD lpcch_قدر_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_معلومات,LPDWORD lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Enum_قدر_W(HKEY h_ڪنجي,DWORD dw_اشاريو,LPWSTR lp_قدر_Name,LPDWORD lpcch_قدر_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_معلومات,LPDWORD lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Flush_ڪنجي(HKEY h_ڪنجي);
  WINADVAPI LONG WINAPI Reg_Get_ڪنجي_Security(HKEY h_ڪنجي,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_ڀريو_ڪنجي_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_ڀريو_ڪنجي_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_ڪنجي_قدر(HKEY h_ڪنجي,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_ڪنجي_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI Reg_Open_ڪنجي_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI Reg_Open_ڪنجي_Ex_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي,DWORD ulOptions,REGSAM samDesired,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI Reg_Open_ڪنجي_Ex_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي,DWORD ulOptions,REGSAM samDesired,PHKEY phk_نتيجو);
  WINADVAPI LONG WINAPI Reg_Query_Info_ڪنجي_A(HKEY h_ڪنجي,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ڪنجيون,LPDWORD lpcb_Max_Sub_ڪنجي_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_قدرون,LPDWORD lpcb_Max_قدر_Name_Len,LPDWORD lpcb_Max_قدر_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_آخري_Write_وقت);
  WINADVAPI LONG WINAPI Reg_Query_Info_ڪنجي_W(HKEY h_ڪنجي,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ڪنجيون,LPDWORD lpcb_Max_Sub_ڪنجي_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_قدرون,LPDWORD lpcb_Max_قدر_Name_Len,LPDWORD lpcb_Max_قدر_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_آخري_Write_وقت);
  WINADVAPI LONG WINAPI Reg_Query_قدر_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي,LPSTR lp_معلومات,PLONG lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Query_قدر_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي,LPWSTR lp_معلومات,PLONG lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Query_گڻو_قدرون_A(HKEY h_ڪنجي,PVALENTA val_list,DWORD انگ_vals,LPSTR lp_قدر_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_گڻو_قدرون_W(HKEY h_ڪنجي,PVALENTW val_list,DWORD انگ_vals,LPWSTR lp_قدر_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_قدر_Ex_A(HKEY h_ڪنجي,LPCSTR lp_قدر_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_معلومات,LPDWORD lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Query_قدر_Ex_W(HKEY h_ڪنجي,LPCWSTR lp_قدر_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_معلومات,LPDWORD lpcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Replace_ڪنجي_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_ڪنجي_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_ڪنجي_A(HKEY h_ڪنجي,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_ڪنجي_W(HKEY h_ڪنجي,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_ڪنجي_A(HKEY h_ڪنجي,LPCSTR lpFile,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINADVAPI LONG WINAPI Reg_Save_ڪنجي_W(HKEY h_ڪنجي,LPCWSTR lpFile,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINADVAPI LONG WINAPI Reg_سيٽ_ڪنجي_Security(HKEY h_ڪنجي,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_سيٽ_قدر_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي,DWORD dwType,LPCSTR lp_معلومات,DWORD cb_معلومات);
  WINADVAPI LONG WINAPI Reg_سيٽ_قدر_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي,DWORD dwType,LPCWSTR lp_معلومات,DWORD cb_معلومات);
  WINADVAPI LONG WINAPI Reg_سيٽ_قدر_Ex_A(HKEY h_ڪنجي,LPCSTR lp_قدر_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_معلومات,DWORD cb_معلومات);
  WINADVAPI LONG WINAPI Reg_سيٽ_قدر_Ex_W(HKEY h_ڪنجي,LPCWSTR lp_قدر_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_معلومات,DWORD cb_معلومات);
  WINADVAPI LONG WINAPI Reg_Un_ڀريو_ڪنجي_A(HKEY h_ڪنجي,LPCSTR lp_Sub_ڪنجي);
  WINADVAPI LONG WINAPI Reg_Un_ڀريو_ڪنجي_W(HKEY h_ڪنجي,LPCWSTR lp_Sub_ڪنجي);
  WINADVAPI LONG WINAPI Reg_Get_قدر_A(HKEY hkey,LPCSTR lp_Sub_ڪنجي,LPCSTR lp_قدر,DWORD dwFlags,LPDWORD pdwType,PVOID pv_معلومات,LPDWORD pcb_معلومات);
  WINADVAPI LONG WINAPI Reg_Get_قدر_W(HKEY hkey,LPCWSTR lp_Sub_ڪنجي,LPCWSTR lp_قدر,DWORD dwFlags,LPDWORD pdwType,PVOID pv_معلومات,LPDWORD pcb_معلومات);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lp_پيغام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lp_پيغام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#وصف_ڪريو REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#وصف_ڪريو REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#وصف_ڪريو REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#وصف_ڪريو REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#وصف_ڪريو REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#وصف_ڪريو REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#وصف_ڪريو REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#وصف_ڪريو REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#وصف_ڪريو REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#وصف_ڪريو MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو InitiateSystemShutdownEx InitiateSystemShutdownExW
#وصف_ڪريو Reg_Save_ڪنجي_Ex Reg_Save_ڪنجي_Ex_W
#وإلا
#وصف_ڪريو InitiateSystemShutdownEx InitiateSystemShutdownExA
#وصف_ڪريو Reg_Save_ڪنجي_Ex Reg_Save_ڪنجي_Ex_A
#جيڪڏهن_پورو

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lp_پيغام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lp_پيغام,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_ڪنجي_Ex_A(HKEY h_ڪنجي,LPCSTR lpFile,LPSECURITY_خاصيتون lp_Security_خاصيتون,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_ڪنجي_Ex_W(HKEY h_ڪنجي,LPCWSTR lpFile,LPSECURITY_خاصيتون lp_Security_خاصيتون,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64_Win32_Api_داخلا (DWORD dw_Func_عدد,DWORD dwFlag,DWORD dwRes);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
