/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINREG_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINREG_

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WINVER
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINVER 0x0502
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_REG_NONE 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_REG_SZ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_REG_EXPAND_SZ 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_REG_ਦੁਆਧਾਰੀ 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_REG_DWORD 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_REG_MULTI_SZ 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_REG_QWORD 0x00000040

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_DWORD (RRF_RT_REG_ਦੁਆਧਾਰੀ | RRF_RT_REG_DWORD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_QWORD (RRF_RT_REG_ਦੁਆਧਾਰੀ | RRF_RT_REG_QWORD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_RT_ANY 0x0000ffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_NOEXPAND 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RRF_ZEROONFAILURE 0x20000000

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACCESS_ਨਕਾਬ REGSAM;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKEY_CLASSES_ਜੜ੍ਹ ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKEY_PERFORMANCE_ਅੰਕੜੇ ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKEY_PERFORMANCE_ਪਾਠ ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKEY_DYN_ਅੰਕੜੇ ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_SECURE_CONNECTION 1

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _PROVIDER_STRUCTS_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PROVIDER_STRUCTS_DEFINED

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROVIDER_KEEPS_ਮੁੱਲ_ਲੰਮਾਈ 0x1
  ਬਣਤਰ val_context {
    ਪੂਰਨ valuelen;
    LPVOID ਮੁੱਲ_context;
    LPVOID val_buff_ptr;
  };

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ val_context *PVALCONTEXT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ pvalueA {
    LPSTR pv_valuename;
    ਪੂਰਨ pv_valuelen;
    LPVOID pv_ਮੁੱਲ_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ pvalueW {
    LPWSTR pv_valuename;
    ਪੂਰਨ pv_valuelen;
    LPVOID pv_ਮੁੱਲ_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVALUEW PVALUE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PPVALUEW PPVALUE;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVALUEA PVALUE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PPVALUEA PPVALUE;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD ਅੰਕ_vals,LPVOID outputbuffer,DWORD *ਕੁੱਲ_outlen,DWORD ਨਿਵੇਸ਼_blen);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ QUERYHANDLER *PQUERYHANDLER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_ਕੁੰਜੀ_context;
  } REG_PROVIDER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ provider_info *PPROVIDER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਮੁੱਲ_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਮੁੱਲ_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VALENTW VALENT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVALENTW PVALENT;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VALENTA VALENT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVALENTA PVALENT;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WIN31_CLASS ਨਿਰਾ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RegConnectRegistry RegConnectRegistryW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RegConnectRegistryEx RegConnectRegistryExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Create_ਕੁੰਜੀ Reg_Create_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Create_ਕੁੰਜੀ_Ex Reg_Create_ਕੁੰਜੀ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Delete_ਕੁੰਜੀ Reg_Delete_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Delete_ਕੁੰਜੀ_Ex Reg_Delete_ਕੁੰਜੀ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Delete_ਮੁੱਲ Reg_Delete_ਮੁੱਲ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Enum_ਕੁੰਜੀ Reg_Enum_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Enum_ਕੁੰਜੀ_Ex Reg_Enum_ਕੁੰਜੀ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Enum_ਮੁੱਲ Reg_Enum_ਮੁੱਲ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_ਲੱਦੋ_ਕੁੰਜੀ Reg_ਲੱਦੋ_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Open_ਕੁੰਜੀ Reg_Open_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Open_ਕੁੰਜੀ_Ex Reg_Open_ਕੁੰਜੀ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Query_Info_ਕੁੰਜੀ Reg_Query_Info_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Query_ਮੁੱਲ Reg_Query_ਮੁੱਲ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Query_ਗੁਣਜ_ਮੁੱਲਾਂ Reg_Query_ਗੁਣਜ_ਮੁੱਲਾਂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Query_ਮੁੱਲ_Ex Reg_Query_ਮੁੱਲ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Replace_ਕੁੰਜੀ Reg_Replace_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Restore_ਕੁੰਜੀ Reg_Restore_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Save_ਕੁੰਜੀ Reg_Save_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_ਸੈੱਟ_ਮੁੱਲ Reg_ਸੈੱਟ_ਮੁੱਲ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_ਸੈੱਟ_ਮੁੱਲ_Ex Reg_ਸੈੱਟ_ਮੁੱਲ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Un_ਲੱਦੋ_ਕੁੰਜੀ Reg_Un_ਲੱਦੋ_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Get_ਮੁੱਲ Reg_Get_ਮੁੱਲ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InitiateSystemShutdown InitiateSystemShutdownW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AbortSystemShutdown AbortSystemShutdownW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RegConnectRegistry RegConnectRegistryA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RegConnectRegistryEx RegConnectRegistryExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Create_ਕੁੰਜੀ Reg_Create_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Create_ਕੁੰਜੀ_Ex Reg_Create_ਕੁੰਜੀ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Delete_ਕੁੰਜੀ Reg_Delete_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Delete_ਕੁੰਜੀ_Ex Reg_Delete_ਕੁੰਜੀ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Delete_ਮੁੱਲ Reg_Delete_ਮੁੱਲ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Enum_ਕੁੰਜੀ Reg_Enum_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Enum_ਕੁੰਜੀ_Ex Reg_Enum_ਕੁੰਜੀ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Enum_ਮੁੱਲ Reg_Enum_ਮੁੱਲ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_ਲੱਦੋ_ਕੁੰਜੀ Reg_ਲੱਦੋ_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Open_ਕੁੰਜੀ Reg_Open_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Open_ਕੁੰਜੀ_Ex Reg_Open_ਕੁੰਜੀ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Query_Info_ਕੁੰਜੀ Reg_Query_Info_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Query_ਮੁੱਲ Reg_Query_ਮੁੱਲ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Query_ਗੁਣਜ_ਮੁੱਲਾਂ Reg_Query_ਗੁਣਜ_ਮੁੱਲਾਂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Query_ਮੁੱਲ_Ex Reg_Query_ਮੁੱਲ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Replace_ਕੁੰਜੀ Reg_Replace_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Restore_ਕੁੰਜੀ Reg_Restore_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Save_ਕੁੰਜੀ Reg_Save_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_ਸੈੱਟ_ਮੁੱਲ Reg_ਸੈੱਟ_ਮੁੱਲ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_ਸੈੱਟ_ਮੁੱਲ_Ex Reg_ਸੈੱਟ_ਮੁੱਲ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Un_ਲੱਦੋ_ਕੁੰਜੀ Reg_Un_ਲੱਦੋ_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Get_ਮੁੱਲ Reg_Get_ਮੁੱਲ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InitiateSystemShutdown InitiateSystemShutdownA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AbortSystemShutdown AbortSystemShutdownA
#ਜੇ_ਅੰਤ

  WINADVAPI LONG WINAPI Reg_Close_ਕੁੰਜੀ(HKEY h_ਕੁੰਜੀ);
  WINADVAPI LONG WINAPI Reg_Override_Predef_ਕੁੰਜੀ(HKEY h_ਕੁੰਜੀ,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_ਜੜ੍ਹ(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_ਕੁੰਜੀ,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_ਕੁੰਜੀ,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_ਕੁੰਜੀ,ULONG Flags,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_ਕੁੰਜੀ,ULONG Flags,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI Reg_Create_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI Reg_Create_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI Reg_Create_ਕੁੰਜੀ_Ex_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ,PHKEY phk_ਨਤੀਜਾ,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_ਕੁੰਜੀ_Ex_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ,PHKEY phk_ਨਤੀਜਾ,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ);
  WINADVAPI LONG WINAPI Reg_Delete_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ);
  WINADVAPI LONG WINAPI Reg_Delete_ਕੁੰਜੀ_Ex_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_ਕੁੰਜੀ_Ex_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_ਕੁੰਜੀ(HKEY h_ਅਧਾਰ);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_ਕੁੰਜੀ(HKEY h_ਅਧਾਰ);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_ਕੁੰਜੀ(HKEY h_ਅਧਾਰ,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_ਮੁੱਲ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_ਮੁੱਲ_Name);
  WINADVAPI LONG WINAPI Reg_Delete_ਮੁੱਲ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_ਮੁੱਲ_Name);
  WINADVAPI LONG WINAPI Reg_Enum_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,DWORD dw_ਸੂਚਕਾਂਕ,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,DWORD dw_ਸੂਚਕਾਂਕ,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ਕੁੰਜੀ_Ex_A(HKEY h_ਕੁੰਜੀ,DWORD dw_ਸੂਚਕਾਂਕ,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_ਆਖਰੀ_Write_ਸਮਾਂ);
  WINADVAPI LONG WINAPI Reg_Enum_ਕੁੰਜੀ_Ex_W(HKEY h_ਕੁੰਜੀ,DWORD dw_ਸੂਚਕਾਂਕ,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_ਆਖਰੀ_Write_ਸਮਾਂ);
  WINADVAPI LONG WINAPI Reg_Enum_ਮੁੱਲ_A(HKEY h_ਕੁੰਜੀ,DWORD dw_ਸੂਚਕਾਂਕ,LPSTR lp_ਮੁੱਲ_Name,LPDWORD lpcch_ਮੁੱਲ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_ਅੰਕੜੇ,LPDWORD lpcb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_Enum_ਮੁੱਲ_W(HKEY h_ਕੁੰਜੀ,DWORD dw_ਸੂਚਕਾਂਕ,LPWSTR lp_ਮੁੱਲ_Name,LPDWORD lpcch_ਮੁੱਲ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_ਅੰਕੜੇ,LPDWORD lpcb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_Flush_ਕੁੰਜੀ(HKEY h_ਕੁੰਜੀ);
  WINADVAPI LONG WINAPI Reg_Get_ਕੁੰਜੀ_Security(HKEY h_ਕੁੰਜੀ,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_ਲੱਦੋ_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_ਲੱਦੋ_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_ਕੁੰਜੀ_ਮੁੱਲ(HKEY h_ਕੁੰਜੀ,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI Reg_Open_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI Reg_Open_ਕੁੰਜੀ_Ex_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ,DWORD ulOptions,REGSAM samDesired,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI Reg_Open_ਕੁੰਜੀ_Ex_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ,DWORD ulOptions,REGSAM samDesired,PHKEY phk_ਨਤੀਜਾ);
  WINADVAPI LONG WINAPI Reg_Query_Info_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ਕੁੰਜੀਆਂ,LPDWORD lpcb_Max_Sub_ਕੁੰਜੀ_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_ਮੁੱਲਾਂ,LPDWORD lpcb_Max_ਮੁੱਲ_Name_Len,LPDWORD lpcb_Max_ਮੁੱਲ_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_ਆਖਰੀ_Write_ਸਮਾਂ);
  WINADVAPI LONG WINAPI Reg_Query_Info_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ਕੁੰਜੀਆਂ,LPDWORD lpcb_Max_Sub_ਕੁੰਜੀ_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_ਮੁੱਲਾਂ,LPDWORD lpcb_Max_ਮੁੱਲ_Name_Len,LPDWORD lpcb_Max_ਮੁੱਲ_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_ਆਖਰੀ_Write_ਸਮਾਂ);
  WINADVAPI LONG WINAPI Reg_Query_ਮੁੱਲ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ,LPSTR lp_ਅੰਕੜੇ,PLONG lpcb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_Query_ਮੁੱਲ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ,LPWSTR lp_ਅੰਕੜੇ,PLONG lpcb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_Query_ਗੁਣਜ_ਮੁੱਲਾਂ_A(HKEY h_ਕੁੰਜੀ,PVALENTA val_list,DWORD ਅੰਕ_vals,LPSTR lp_ਮੁੱਲ_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_ਗੁਣਜ_ਮੁੱਲਾਂ_W(HKEY h_ਕੁੰਜੀ,PVALENTW val_list,DWORD ਅੰਕ_vals,LPWSTR lp_ਮੁੱਲ_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_ਮੁੱਲ_Ex_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_ਮੁੱਲ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_ਅੰਕੜੇ,LPDWORD lpcb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_Query_ਮੁੱਲ_Ex_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_ਮੁੱਲ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_ਅੰਕੜੇ,LPDWORD lpcb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_Replace_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lpFile,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINADVAPI LONG WINAPI Reg_Save_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lpFile,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINADVAPI LONG WINAPI Reg_ਸੈੱਟ_ਕੁੰਜੀ_Security(HKEY h_ਕੁੰਜੀ,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_ਸੈੱਟ_ਮੁੱਲ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ,DWORD dwType,LPCSTR lp_ਅੰਕੜੇ,DWORD cb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_ਸੈੱਟ_ਮੁੱਲ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ,DWORD dwType,LPCWSTR lp_ਅੰਕੜੇ,DWORD cb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_ਸੈੱਟ_ਮੁੱਲ_Ex_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_ਮੁੱਲ_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_ਅੰਕੜੇ,DWORD cb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_ਸੈੱਟ_ਮੁੱਲ_Ex_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_ਮੁੱਲ_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_ਅੰਕੜੇ,DWORD cb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_Un_ਲੱਦੋ_ਕੁੰਜੀ_A(HKEY h_ਕੁੰਜੀ,LPCSTR lp_Sub_ਕੁੰਜੀ);
  WINADVAPI LONG WINAPI Reg_Un_ਲੱਦੋ_ਕੁੰਜੀ_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lp_Sub_ਕੁੰਜੀ);
  WINADVAPI LONG WINAPI Reg_Get_ਮੁੱਲ_A(HKEY hkey,LPCSTR lp_Sub_ਕੁੰਜੀ,LPCSTR lp_ਮੁੱਲ,DWORD dwFlags,LPDWORD pdwType,PVOID pv_ਅੰਕੜੇ,LPDWORD pcb_ਅੰਕੜੇ);
  WINADVAPI LONG WINAPI Reg_Get_ਮੁੱਲ_W(HKEY hkey,LPCWSTR lp_Sub_ਕੁੰਜੀ,LPCWSTR lp_ਮੁੱਲ,DWORD dwFlags,LPDWORD pdwType,PVOID pv_ਅੰਕੜੇ,LPDWORD pcb_ਅੰਕੜੇ);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lp_ਸੁਨੇਹਾ,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lp_ਸੁਨੇਹਾ,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InitiateSystemShutdownEx InitiateSystemShutdownExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Save_ਕੁੰਜੀ_Ex Reg_Save_ਕੁੰਜੀ_Ex_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InitiateSystemShutdownEx InitiateSystemShutdownExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Reg_Save_ਕੁੰਜੀ_Ex Reg_Save_ਕੁੰਜੀ_Ex_A
#ਜੇ_ਅੰਤ

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lp_ਸੁਨੇਹਾ,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lp_ਸੁਨੇਹਾ,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_ਕੁੰਜੀ_Ex_A(HKEY h_ਕੁੰਜੀ,LPCSTR lpFile,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_ਕੁੰਜੀ_Ex_W(HKEY h_ਕੁੰਜੀ,LPCWSTR lpFile,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64_Win32_Api_ਇੰਦਰਾਜ (DWORD dw_Func_ਸੰਖਿਆ,DWORD dwFlag,DWORD dwRes);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
