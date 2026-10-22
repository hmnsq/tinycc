/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _WINREG_
#تعریف_کرو _WINREG_

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف WINVER
#تعریف_کرو WINVER 0x0502
#جے_انت

#تعریف_کرو RRF_RT_REG_NONE 0x00000001
#تعریف_کرو RRF_RT_REG_SZ 0x00000002
#تعریف_کرو RRF_RT_REG_EXPAND_SZ 0x00000004
#تعریف_کرو RRF_RT_REG_ثنائی 0x00000008
#تعریف_کرو RRF_RT_REG_DWORD 0x00000010
#تعریف_کرو RRF_RT_REG_MULTI_SZ 0x00000020
#تعریف_کرو RRF_RT_REG_QWORD 0x00000040

#تعریف_کرو RRF_RT_DWORD (RRF_RT_REG_ثنائی | RRF_RT_REG_DWORD)
#تعریف_کرو RRF_RT_QWORD (RRF_RT_REG_ثنائی | RRF_RT_REG_QWORD)
#تعریف_کرو RRF_RT_ANY 0x0000ffff

#تعریف_کرو RRF_NOEXPAND 0x10000000
#تعریف_کرو RRF_ZEROONFAILURE 0x20000000

  تعريفنوع ACCESS_نقاب REGSAM;

#تعریف_کرو HKEY_CLASSES_جڑ ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#تعریف_کرو HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#تعریف_کرو HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#تعریف_کرو HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#تعریف_کرو HKEY_PERFORMANCE_انکڑے ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#تعریف_کرو HKEY_PERFORMANCE_متن ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#تعریف_کرو HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#تعریف_کرو HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#تعریف_کرو HKEY_DYN_انکڑے ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#تعریف_کرو REG_SECURE_CONNECTION 1

#جے_بنا_تعریف _PROVIDER_STRUCTS_DEFINED
#تعریف_کرو _PROVIDER_STRUCTS_DEFINED

#تعریف_کرو PROVIDER_KEEPS_قدر_لمائی 0x1
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

#جے_تعریف_شدہ UNICODE
  تعريفنوع PVALUEW PVALUE;
  تعريفنوع PPVALUEW PPVALUE;
#وإلا
  تعريفنوع PVALUEA PVALUE;
  تعريفنوع PPVALUEA PPVALUE;
#جے_انت

  تعريفنوع DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD عدد_vals,LPVOID outputbuffer,DWORD *کل_outlen,DWORD داخلہ_blen);

  تعريفنوع QUERYHANDLER *PQUERYHANDLER;

  تعريفنوع بنية provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_کلید_context;
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

#جے_تعریف_شدہ UNICODE
  تعريفنوع VALENTW VALENT;
  تعريفنوع PVALENTW PVALENT;
#وإلا
  تعريفنوع VALENTA VALENT;
  تعريفنوع PVALENTA PVALENT;
#جے_انت
#جے_انت

#تعریف_کرو WIN31_CLASS عدم

#جے_تعریف_شدہ UNICODE
#تعریف_کرو RegConnectRegistry RegConnectRegistryW
#تعریف_کرو RegConnectRegistryEx RegConnectRegistryExW
#تعریف_کرو Reg_Create_کلید Reg_Create_کلید_W
#تعریف_کرو Reg_Create_کلید_Ex Reg_Create_کلید_Ex_W
#تعریف_کرو Reg_Delete_کلید Reg_Delete_کلید_W
#تعریف_کرو Reg_Delete_کلید_Ex Reg_Delete_کلید_Ex_W
#تعریف_کرو Reg_Delete_قدر Reg_Delete_قدر_W
#تعریف_کرو Reg_Enum_کلید Reg_Enum_کلید_W
#تعریف_کرو Reg_Enum_کلید_Ex Reg_Enum_کلید_Ex_W
#تعریف_کرو Reg_Enum_قدر Reg_Enum_قدر_W
#تعریف_کرو Reg_لدو_کلید Reg_لدو_کلید_W
#تعریف_کرو Reg_Open_کلید Reg_Open_کلید_W
#تعریف_کرو Reg_Open_کلید_Ex Reg_Open_کلید_Ex_W
#تعریف_کرو Reg_Query_Info_کلید Reg_Query_Info_کلید_W
#تعریف_کرو Reg_Query_قدر Reg_Query_قدر_W
#تعریف_کرو Reg_Query_مضرب_اقدار Reg_Query_مضرب_اقدار_W
#تعریف_کرو Reg_Query_قدر_Ex Reg_Query_قدر_Ex_W
#تعریف_کرو Reg_Replace_کلید Reg_Replace_کلید_W
#تعریف_کرو Reg_Restore_کلید Reg_Restore_کلید_W
#تعریف_کرو Reg_Save_کلید Reg_Save_کلید_W
#تعریف_کرو Reg_سیٹ_قدر Reg_سیٹ_قدر_W
#تعریف_کرو Reg_سیٹ_قدر_Ex Reg_سیٹ_قدر_Ex_W
#تعریف_کرو Reg_Un_لدو_کلید Reg_Un_لدو_کلید_W
#تعریف_کرو Reg_Get_قدر Reg_Get_قدر_W
#تعریف_کرو InitiateSystemShutdown InitiateSystemShutdownW
#تعریف_کرو AbortSystemShutdown AbortSystemShutdownW
#وإلا
#تعریف_کرو RegConnectRegistry RegConnectRegistryA
#تعریف_کرو RegConnectRegistryEx RegConnectRegistryExA
#تعریف_کرو Reg_Create_کلید Reg_Create_کلید_A
#تعریف_کرو Reg_Create_کلید_Ex Reg_Create_کلید_Ex_A
#تعریف_کرو Reg_Delete_کلید Reg_Delete_کلید_A
#تعریف_کرو Reg_Delete_کلید_Ex Reg_Delete_کلید_Ex_A
#تعریف_کرو Reg_Delete_قدر Reg_Delete_قدر_A
#تعریف_کرو Reg_Enum_کلید Reg_Enum_کلید_A
#تعریف_کرو Reg_Enum_کلید_Ex Reg_Enum_کلید_Ex_A
#تعریف_کرو Reg_Enum_قدر Reg_Enum_قدر_A
#تعریف_کرو Reg_لدو_کلید Reg_لدو_کلید_A
#تعریف_کرو Reg_Open_کلید Reg_Open_کلید_A
#تعریف_کرو Reg_Open_کلید_Ex Reg_Open_کلید_Ex_A
#تعریف_کرو Reg_Query_Info_کلید Reg_Query_Info_کلید_A
#تعریف_کرو Reg_Query_قدر Reg_Query_قدر_A
#تعریف_کرو Reg_Query_مضرب_اقدار Reg_Query_مضرب_اقدار_A
#تعریف_کرو Reg_Query_قدر_Ex Reg_Query_قدر_Ex_A
#تعریف_کرو Reg_Replace_کلید Reg_Replace_کلید_A
#تعریف_کرو Reg_Restore_کلید Reg_Restore_کلید_A
#تعریف_کرو Reg_Save_کلید Reg_Save_کلید_A
#تعریف_کرو Reg_سیٹ_قدر Reg_سیٹ_قدر_A
#تعریف_کرو Reg_سیٹ_قدر_Ex Reg_سیٹ_قدر_Ex_A
#تعریف_کرو Reg_Un_لدو_کلید Reg_Un_لدو_کلید_A
#تعریف_کرو Reg_Get_قدر Reg_Get_قدر_A
#تعریف_کرو InitiateSystemShutdown InitiateSystemShutdownA
#تعریف_کرو AbortSystemShutdown AbortSystemShutdownA
#جے_انت

  WINADVAPI LONG WINAPI Reg_Close_کلید(HKEY h_کلید);
  WINADVAPI LONG WINAPI Reg_Override_Predef_کلید(HKEY h_کلید,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_جڑ(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_کلید,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_کلید,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_کلید,ULONG Flags,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_کلید,ULONG Flags,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI Reg_Create_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI Reg_Create_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI Reg_Create_کلید_Ex_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_گن lp_Security_گن,PHKEY phk_نتیجہ,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_کلید_Ex_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_گن lp_Security_گن,PHKEY phk_نتیجہ,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_Ex_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_کلید_Ex_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_کلید(HKEY h_ادھار);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_کلید(HKEY h_ادھار);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_کلید(HKEY h_ادھار,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_قدر_A(HKEY h_کلید,LPCSTR lp_قدر_Name);
  WINADVAPI LONG WINAPI Reg_Delete_قدر_W(HKEY h_کلید,LPCWSTR lp_قدر_Name);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_A(HKEY h_کلید,DWORD dw_اشاریہ,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_W(HKEY h_کلید,DWORD dw_اشاریہ,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_Ex_A(HKEY h_کلید,DWORD dw_اشاریہ,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_آخری_Write_ویلا);
  WINADVAPI LONG WINAPI Reg_Enum_کلید_Ex_W(HKEY h_کلید,DWORD dw_اشاریہ,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_آخری_Write_ویلا);
  WINADVAPI LONG WINAPI Reg_Enum_قدر_A(HKEY h_کلید,DWORD dw_اشاریہ,LPSTR lp_قدر_Name,LPDWORD lpcch_قدر_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_انکڑے,LPDWORD lpcb_انکڑے);
  WINADVAPI LONG WINAPI Reg_Enum_قدر_W(HKEY h_کلید,DWORD dw_اشاریہ,LPWSTR lp_قدر_Name,LPDWORD lpcch_قدر_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_انکڑے,LPDWORD lpcb_انکڑے);
  WINADVAPI LONG WINAPI Reg_Flush_کلید(HKEY h_کلید);
  WINADVAPI LONG WINAPI Reg_Get_کلید_Security(HKEY h_کلید,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_لدو_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_لدو_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_کلید_قدر(HKEY h_کلید,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI Reg_Open_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI Reg_Open_کلید_Ex_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,DWORD ulOptions,REGSAM samDesired,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI Reg_Open_کلید_Ex_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,DWORD ulOptions,REGSAM samDesired,PHKEY phk_نتیجہ);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلید_A(HKEY h_کلید,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیدیں,LPDWORD lpcb_Max_Sub_کلید_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_اقدار,LPDWORD lpcb_Max_قدر_Name_Len,LPDWORD lpcb_Max_قدر_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_آخری_Write_ویلا);
  WINADVAPI LONG WINAPI Reg_Query_Info_کلید_W(HKEY h_کلید,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_کلیدیں,LPDWORD lpcb_Max_Sub_کلید_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_اقدار,LPDWORD lpcb_Max_قدر_Name_Len,LPDWORD lpcb_Max_قدر_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_آخری_Write_ویلا);
  WINADVAPI LONG WINAPI Reg_Query_قدر_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,LPSTR lp_انکڑے,PLONG lpcb_انکڑے);
  WINADVAPI LONG WINAPI Reg_Query_قدر_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,LPWSTR lp_انکڑے,PLONG lpcb_انکڑے);
  WINADVAPI LONG WINAPI Reg_Query_مضرب_اقدار_A(HKEY h_کلید,PVALENTA val_list,DWORD عدد_vals,LPSTR lp_قدر_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_مضرب_اقدار_W(HKEY h_کلید,PVALENTW val_list,DWORD عدد_vals,LPWSTR lp_قدر_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_قدر_Ex_A(HKEY h_کلید,LPCSTR lp_قدر_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_انکڑے,LPDWORD lpcb_انکڑے);
  WINADVAPI LONG WINAPI Reg_Query_قدر_Ex_W(HKEY h_کلید,LPCWSTR lp_قدر_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_انکڑے,LPDWORD lpcb_انکڑے);
  WINADVAPI LONG WINAPI Reg_Replace_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_کلید_A(HKEY h_کلید,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_کلید_W(HKEY h_کلید,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_کلید_A(HKEY h_کلید,LPCSTR lpFile,LPSECURITY_گن lp_Security_گن);
  WINADVAPI LONG WINAPI Reg_Save_کلید_W(HKEY h_کلید,LPCWSTR lpFile,LPSECURITY_گن lp_Security_گن);
  WINADVAPI LONG WINAPI Reg_سیٹ_کلید_Security(HKEY h_کلید,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_سیٹ_قدر_A(HKEY h_کلید,LPCSTR lp_Sub_کلید,DWORD dwType,LPCSTR lp_انکڑے,DWORD cb_انکڑے);
  WINADVAPI LONG WINAPI Reg_سیٹ_قدر_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید,DWORD dwType,LPCWSTR lp_انکڑے,DWORD cb_انکڑے);
  WINADVAPI LONG WINAPI Reg_سیٹ_قدر_Ex_A(HKEY h_کلید,LPCSTR lp_قدر_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_انکڑے,DWORD cb_انکڑے);
  WINADVAPI LONG WINAPI Reg_سیٹ_قدر_Ex_W(HKEY h_کلید,LPCWSTR lp_قدر_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_انکڑے,DWORD cb_انکڑے);
  WINADVAPI LONG WINAPI Reg_Un_لدو_کلید_A(HKEY h_کلید,LPCSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Un_لدو_کلید_W(HKEY h_کلید,LPCWSTR lp_Sub_کلید);
  WINADVAPI LONG WINAPI Reg_Get_قدر_A(HKEY hkey,LPCSTR lp_Sub_کلید,LPCSTR lp_قدر,DWORD dwFlags,LPDWORD pdwType,PVOID pv_انکڑے,LPDWORD pcb_انکڑے);
  WINADVAPI LONG WINAPI Reg_Get_قدر_W(HKEY hkey,LPCWSTR lp_Sub_کلید,LPCWSTR lp_قدر,DWORD dwFlags,LPDWORD pdwType,PVOID pv_انکڑے,LPDWORD pcb_انکڑے);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lp_سنیہا,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lp_سنیہا,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#تعریف_کرو REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#تعریف_کرو REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#تعریف_کرو REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#تعریف_کرو REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#تعریف_کرو REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#تعریف_کرو REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#تعریف_کرو REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#تعریف_کرو REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#تعریف_کرو REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#تعریف_کرو MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#جے_تعریف_شدہ UNICODE
#تعریف_کرو InitiateSystemShutdownEx InitiateSystemShutdownExW
#تعریف_کرو Reg_Save_کلید_Ex Reg_Save_کلید_Ex_W
#وإلا
#تعریف_کرو InitiateSystemShutdownEx InitiateSystemShutdownExA
#تعریف_کرو Reg_Save_کلید_Ex Reg_Save_کلید_Ex_A
#جے_انت

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lp_سنیہا,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lp_سنیہا,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_کلید_Ex_A(HKEY h_کلید,LPCSTR lpFile,LPSECURITY_گن lp_Security_گن,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_کلید_Ex_W(HKEY h_کلید,LPCWSTR lpFile,LPSECURITY_گن lp_Security_گن,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64_Win32_Api_اندراج (DWORD dw_Func_نمبر,DWORD dwFlag,DWORD dwRes);

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
