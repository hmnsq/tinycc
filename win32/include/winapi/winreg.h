/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _WINREG_
#परिभाषय _WINREG_

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् WINVER
#परिभाषय WINVER 0x0502
#यदि_अन्तः

#परिभाषय RRF_RT_REG_NONE 0x00000001
#परिभाषय RRF_RT_REG_SZ 0x00000002
#परिभाषय RRF_RT_REG_EXPAND_SZ 0x00000004
#परिभाषय RRF_RT_REG_द्विमान 0x00000008
#परिभाषय RRF_RT_REG_DWORD 0x00000010
#परिभाषय RRF_RT_REG_MULTI_SZ 0x00000020
#परिभाषय RRF_RT_REG_QWORD 0x00000040

#परिभाषय RRF_RT_DWORD (RRF_RT_REG_द्विमान | RRF_RT_REG_DWORD)
#परिभाषय RRF_RT_QWORD (RRF_RT_REG_द्विमान | RRF_RT_REG_QWORD)
#परिभाषय RRF_RT_ANY 0x0000ffff

#परिभाषय RRF_NOEXPAND 0x10000000
#परिभाषय RRF_ZEROONFAILURE 0x20000000

  प्रकारनिर्देश ACCESS_आवरणम् REGSAM;

#परिभाषय HKEY_CLASSES_मूलम् ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#परिभाषय HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#परिभाषय HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#परिभाषय HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#परिभाषय HKEY_PERFORMANCE_दत्त ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#परिभाषय HKEY_PERFORMANCE_TEXT ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#परिभाषय HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#परिभाषय HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#परिभाषय HKEY_DYN_दत्त ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#परिभाषय REG_SECURE_CONNECTION 1

#यदि_अपरिभाषितम् _PROVIDER_STRUCTS_DEFINED
#परिभाषय _PROVIDER_STRUCTS_DEFINED

#परिभाषय PROVIDER_KEEPS_मानम्_दीर्घता 0x1
  संरचना val_context {
    पूर्णाङ्क valuelen;
    LPVOID मानम्_context;
    LPVOID val_buff_ptr;
  };

  प्रकारनिर्देश संरचना val_context *PVALCONTEXT;

  प्रकारनिर्देश संरचना pvalueA {
    LPSTR pv_valuename;
    पूर्णाङ्क pv_valuelen;
    LPVOID pv_मानम्_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  प्रकारनिर्देश संरचना pvalueW {
    LPWSTR pv_valuename;
    पूर्णाङ्क pv_valuelen;
    LPVOID pv_मानम्_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश PVALUEW PVALUE;
  प्रकारनिर्देश PPVALUEW PPVALUE;
#अन्यथा
  प्रकारनिर्देश PVALUEA PVALUE;
  प्रकारनिर्देश PPVALUEA PPVALUE;
#यदि_अन्तः

  प्रकारनिर्देश DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD अङ्कः_vals,LPVOID outputbuffer,DWORD *योग_outlen,DWORD निवेशः_blen);

  प्रकारनिर्देश QUERYHANDLER *PQUERYHANDLER;

  प्रकारनिर्देश संरचना provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_कुञ्चिका_context;
  } REG_PROVIDER;

  प्रकारनिर्देश संरचना provider_info *PPROVIDER;

  प्रकारनिर्देश संरचना मानम्_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  प्रकारनिर्देश संरचना मानम्_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश VALENTW VALENT;
  प्रकारनिर्देश PVALENTW PVALENT;
#अन्यथा
  प्रकारनिर्देश VALENTA VALENT;
  प्रकारनिर्देश PVALENTA PVALENT;
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय WIN31_CLASS रिक्त

#यदि_परिभाषितम् UNICODE
#परिभाषय RegConnectRegistry RegConnectRegistryW
#परिभाषय RegConnectRegistryEx RegConnectRegistryExW
#परिभाषय Reg_Create_कुञ्चिका Reg_Create_कुञ्चिका_W
#परिभाषय Reg_Create_कुञ्चिका_Ex Reg_Create_कुञ्चिका_Ex_W
#परिभाषय Reg_Delete_कुञ्चिका Reg_Delete_कुञ्चिका_W
#परिभाषय Reg_Delete_कुञ्चिका_Ex Reg_Delete_कुञ्चिका_Ex_W
#परिभाषय Reg_Delete_मानम् Reg_Delete_मानम्_W
#परिभाषय Reg_Enum_कुञ्चिका Reg_Enum_कुञ्चिका_W
#परिभाषय Reg_Enum_कुञ्चिका_Ex Reg_Enum_कुञ्चिका_Ex_W
#परिभाषय Reg_Enum_मानम् Reg_Enum_मानम्_W
#परिभाषय Reg_आरोपय_कुञ्चिका Reg_आरोपय_कुञ्चिका_W
#परिभाषय Reg_Open_कुञ्चिका Reg_Open_कुञ्चिका_W
#परिभाषय Reg_Open_कुञ्चिका_Ex Reg_Open_कुञ्चिका_Ex_W
#परिभाषय Reg_Query_Info_कुञ्चिका Reg_Query_Info_कुञ्चिका_W
#परिभाषय Reg_Query_मानम् Reg_Query_मानम्_W
#परिभाषय Reg_Query_गुणजः_मानानि Reg_Query_गुणजः_मानानि_W
#परिभाषय Reg_Query_मानम्_Ex Reg_Query_मानम्_Ex_W
#परिभाषय Reg_Replace_कुञ्चिका Reg_Replace_कुञ्चिका_W
#परिभाषय Reg_Restore_कुञ्चिका Reg_Restore_कुञ्चिका_W
#परिभाषय Reg_Save_कुञ्चिका Reg_Save_कुञ्चिका_W
#परिभाषय Reg_समुच्चयः_मानम् Reg_समुच्चयः_मानम्_W
#परिभाषय Reg_समुच्चयः_मानम्_Ex Reg_समुच्चयः_मानम्_Ex_W
#परिभाषय Reg_Un_आरोपय_कुञ्चिका Reg_Un_आरोपय_कुञ्चिका_W
#परिभाषय Reg_Get_मानम् Reg_Get_मानम्_W
#परिभाषय InitiateSystemShutdown InitiateSystemShutdownW
#परिभाषय AbortSystemShutdown AbortSystemShutdownW
#अन्यथा
#परिभाषय RegConnectRegistry RegConnectRegistryA
#परिभाषय RegConnectRegistryEx RegConnectRegistryExA
#परिभाषय Reg_Create_कुञ्चिका Reg_Create_कुञ्चिका_A
#परिभाषय Reg_Create_कुञ्चिका_Ex Reg_Create_कुञ्चिका_Ex_A
#परिभाषय Reg_Delete_कुञ्चिका Reg_Delete_कुञ्चिका_A
#परिभाषय Reg_Delete_कुञ्चिका_Ex Reg_Delete_कुञ्चिका_Ex_A
#परिभाषय Reg_Delete_मानम् Reg_Delete_मानम्_A
#परिभाषय Reg_Enum_कुञ्चिका Reg_Enum_कुञ्चिका_A
#परिभाषय Reg_Enum_कुञ्चिका_Ex Reg_Enum_कुञ्चिका_Ex_A
#परिभाषय Reg_Enum_मानम् Reg_Enum_मानम्_A
#परिभाषय Reg_आरोपय_कुञ्चिका Reg_आरोपय_कुञ्चिका_A
#परिभाषय Reg_Open_कुञ्चिका Reg_Open_कुञ्चिका_A
#परिभाषय Reg_Open_कुञ्चिका_Ex Reg_Open_कुञ्चिका_Ex_A
#परिभाषय Reg_Query_Info_कुञ्चिका Reg_Query_Info_कुञ्चिका_A
#परिभाषय Reg_Query_मानम् Reg_Query_मानम्_A
#परिभाषय Reg_Query_गुणजः_मानानि Reg_Query_गुणजः_मानानि_A
#परिभाषय Reg_Query_मानम्_Ex Reg_Query_मानम्_Ex_A
#परिभाषय Reg_Replace_कुञ्चिका Reg_Replace_कुञ्चिका_A
#परिभाषय Reg_Restore_कुञ्चिका Reg_Restore_कुञ्चिका_A
#परिभाषय Reg_Save_कुञ्चिका Reg_Save_कुञ्चिका_A
#परिभाषय Reg_समुच्चयः_मानम् Reg_समुच्चयः_मानम्_A
#परिभाषय Reg_समुच्चयः_मानम्_Ex Reg_समुच्चयः_मानम्_Ex_A
#परिभाषय Reg_Un_आरोपय_कुञ्चिका Reg_Un_आरोपय_कुञ्चिका_A
#परिभाषय Reg_Get_मानम् Reg_Get_मानम्_A
#परिभाषय InitiateSystemShutdown InitiateSystemShutdownA
#परिभाषय AbortSystemShutdown AbortSystemShutdownA
#यदि_अन्तः

  WINADVAPI LONG WINAPI Reg_Close_कुञ्चिका(HKEY h_कुञ्चिका);
  WINADVAPI LONG WINAPI Reg_Override_Predef_कुञ्चिका(HKEY h_कुञ्चिका,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_मूलम्(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_कुञ्चिका,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_कुञ्चिका,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_कुञ्चिका,ULONG Flags,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_कुञ्चिका,ULONG Flags,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Create_कुञ्चिका_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Create_कुञ्चिका_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Create_कुञ्चिका_Ex_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_गुणाः lp_Security_गुणाः,PHKEY phk_परिणाम,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_कुञ्चिका_Ex_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_गुणाः lp_Security_गुणाः,PHKEY phk_परिणाम,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_कुञ्चिका_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका);
  WINADVAPI LONG WINAPI Reg_Delete_कुञ्चिका_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका);
  WINADVAPI LONG WINAPI Reg_Delete_कुञ्चिका_Ex_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_कुञ्चिका_Ex_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_कुञ्चिका(HKEY h_आधारः);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_कुञ्चिका(HKEY h_आधारः);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_कुञ्चिका(HKEY h_आधारः,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_मानम्_A(HKEY h_कुञ्चिका,LPCSTR lp_मानम्_Name);
  WINADVAPI LONG WINAPI Reg_Delete_मानम्_W(HKEY h_कुञ्चिका,LPCWSTR lp_मानम्_Name);
  WINADVAPI LONG WINAPI Reg_Enum_कुञ्चिका_A(HKEY h_कुञ्चिका,DWORD dw_सूचकांक,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_कुञ्चिका_W(HKEY h_कुञ्चिका,DWORD dw_सूचकांक,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_कुञ्चिका_Ex_A(HKEY h_कुञ्चिका,DWORD dw_सूचकांक,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_चरमः_Write_Time);
  WINADVAPI LONG WINAPI Reg_Enum_कुञ्चिका_Ex_W(HKEY h_कुञ्चिका,DWORD dw_सूचकांक,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_चरमः_Write_Time);
  WINADVAPI LONG WINAPI Reg_Enum_मानम्_A(HKEY h_कुञ्चिका,DWORD dw_सूचकांक,LPSTR lp_मानम्_Name,LPDWORD lpcch_मानम्_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_दत्त,LPDWORD lpcb_दत्त);
  WINADVAPI LONG WINAPI Reg_Enum_मानम्_W(HKEY h_कुञ्चिका,DWORD dw_सूचकांक,LPWSTR lp_मानम्_Name,LPDWORD lpcch_मानम्_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_दत्त,LPDWORD lpcb_दत्त);
  WINADVAPI LONG WINAPI Reg_Flush_कुञ्चिका(HKEY h_कुञ्चिका);
  WINADVAPI LONG WINAPI Reg_Get_कुञ्चिका_Security(HKEY h_कुञ्चिका,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_आरोपय_कुञ्चिका_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_आरोपय_कुञ्चिका_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_कुञ्चिका_मानम्(HKEY h_कुञ्चिका,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_कुञ्चिका_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Open_कुञ्चिका_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Open_कुञ्चिका_Ex_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका,DWORD ulOptions,REGSAM samDesired,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Open_कुञ्चिका_Ex_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका,DWORD ulOptions,REGSAM samDesired,PHKEY phk_परिणाम);
  WINADVAPI LONG WINAPI Reg_Query_Info_कुञ्चिका_A(HKEY h_कुञ्चिका,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_कुञ्चिकाः,LPDWORD lpcb_Max_Sub_कुञ्चिका_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_मानानि,LPDWORD lpcb_Max_मानम्_Name_Len,LPDWORD lpcb_Max_मानम्_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_चरमः_Write_Time);
  WINADVAPI LONG WINAPI Reg_Query_Info_कुञ्चिका_W(HKEY h_कुञ्चिका,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_कुञ्चिकाः,LPDWORD lpcb_Max_Sub_कुञ्चिका_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_मानानि,LPDWORD lpcb_Max_मानम्_Name_Len,LPDWORD lpcb_Max_मानम्_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_चरमः_Write_Time);
  WINADVAPI LONG WINAPI Reg_Query_मानम्_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका,LPSTR lp_दत्त,PLONG lpcb_दत्त);
  WINADVAPI LONG WINAPI Reg_Query_मानम्_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका,LPWSTR lp_दत्त,PLONG lpcb_दत्त);
  WINADVAPI LONG WINAPI Reg_Query_गुणजः_मानानि_A(HKEY h_कुञ्चिका,PVALENTA val_list,DWORD अङ्कः_vals,LPSTR lp_मानम्_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_गुणजः_मानानि_W(HKEY h_कुञ्चिका,PVALENTW val_list,DWORD अङ्कः_vals,LPWSTR lp_मानम्_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_मानम्_Ex_A(HKEY h_कुञ्चिका,LPCSTR lp_मानम्_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_दत्त,LPDWORD lpcb_दत्त);
  WINADVAPI LONG WINAPI Reg_Query_मानम्_Ex_W(HKEY h_कुञ्चिका,LPCWSTR lp_मानम्_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_दत्त,LPDWORD lpcb_दत्त);
  WINADVAPI LONG WINAPI Reg_Replace_कुञ्चिका_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_कुञ्चिका_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_कुञ्चिका_A(HKEY h_कुञ्चिका,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_कुञ्चिका_W(HKEY h_कुञ्चिका,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_कुञ्चिका_A(HKEY h_कुञ्चिका,LPCSTR lpFile,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINADVAPI LONG WINAPI Reg_Save_कुञ्चिका_W(HKEY h_कुञ्चिका,LPCWSTR lpFile,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINADVAPI LONG WINAPI Reg_समुच्चयः_कुञ्चिका_Security(HKEY h_कुञ्चिका,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_समुच्चयः_मानम्_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका,DWORD dwType,LPCSTR lp_दत्त,DWORD cb_दत्त);
  WINADVAPI LONG WINAPI Reg_समुच्चयः_मानम्_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका,DWORD dwType,LPCWSTR lp_दत्त,DWORD cb_दत्त);
  WINADVAPI LONG WINAPI Reg_समुच्चयः_मानम्_Ex_A(HKEY h_कुञ्चिका,LPCSTR lp_मानम्_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_दत्त,DWORD cb_दत्त);
  WINADVAPI LONG WINAPI Reg_समुच्चयः_मानम्_Ex_W(HKEY h_कुञ्चिका,LPCWSTR lp_मानम्_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_दत्त,DWORD cb_दत्त);
  WINADVAPI LONG WINAPI Reg_Un_आरोपय_कुञ्चिका_A(HKEY h_कुञ्चिका,LPCSTR lp_Sub_कुञ्चिका);
  WINADVAPI LONG WINAPI Reg_Un_आरोपय_कुञ्चिका_W(HKEY h_कुञ्चिका,LPCWSTR lp_Sub_कुञ्चिका);
  WINADVAPI LONG WINAPI Reg_Get_मानम्_A(HKEY hkey,LPCSTR lp_Sub_कुञ्चिका,LPCSTR lp_मानम्,DWORD dwFlags,LPDWORD pdwType,PVOID pv_दत्त,LPDWORD pcb_दत्त);
  WINADVAPI LONG WINAPI Reg_Get_मानम्_W(HKEY hkey,LPCWSTR lp_Sub_कुञ्चिका,LPCWSTR lp_मानम्,DWORD dwFlags,LPDWORD pdwType,PVOID pv_दत्त,LPDWORD pcb_दत्त);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lp_सन्देशः,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lp_सन्देशः,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#परिभाषय REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#परिभाषय REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#परिभाषय REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#परिभाषय REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#परिभाषय REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#परिभाषय REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#परिभाषय REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#परिभाषय REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#परिभाषय REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#परिभाषय MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#यदि_परिभाषितम् UNICODE
#परिभाषय InitiateSystemShutdownEx InitiateSystemShutdownExW
#परिभाषय Reg_Save_कुञ्चिका_Ex Reg_Save_कुञ्चिका_Ex_W
#अन्यथा
#परिभाषय InitiateSystemShutdownEx InitiateSystemShutdownExA
#परिभाषय Reg_Save_कुञ्चिका_Ex Reg_Save_कुञ्चिका_Ex_A
#यदि_अन्तः

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lp_सन्देशः,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lp_सन्देशः,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_कुञ्चिका_Ex_A(HKEY h_कुञ्चिका,LPCSTR lpFile,LPSECURITY_गुणाः lp_Security_गुणाः,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_कुञ्चिका_Ex_W(HKEY h_कुञ्चिका,LPCWSTR lpFile,LPSECURITY_गुणाः lp_Security_गुणाः,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64_Win32_Api_प्रविष्टिः (DWORD dw_Func_सङ्ख्या,DWORD dwFlag,DWORD dwRes);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
