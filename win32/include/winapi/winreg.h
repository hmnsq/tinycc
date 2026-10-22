/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINREG_
#ವ್ಯಾಖ್ಯಾನಿಸು _WINREG_

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WINVER
#ವ್ಯಾಖ್ಯಾನಿಸು WINVER 0x0502
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_REG_NONE 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_REG_SZ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_REG_EXPAND_SZ 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_REG_ದ್ವಿಮಾನ 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_REG_DWORD 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_REG_MULTI_SZ 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_REG_QWORD 0x00000040

#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_DWORD (RRF_RT_REG_ದ್ವಿಮಾನ | RRF_RT_REG_DWORD)
#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_QWORD (RRF_RT_REG_ದ್ವಿಮಾನ | RRF_RT_REG_QWORD)
#ವ್ಯಾಖ್ಯಾನಿಸು RRF_RT_ANY 0x0000ffff

#ವ್ಯಾಖ್ಯಾನಿಸು RRF_NOEXPAND 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು RRF_ZEROONFAILURE 0x20000000

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACCESS_ಮುಖವಾಡ REGSAM;

#ವ್ಯಾಖ್ಯಾನಿಸು HKEY_CLASSES_ಬೇರು ((HKEY) (ULONG_PTR)((LONG)0x80000000))
#ವ್ಯಾಖ್ಯಾನಿಸು HKEY_CURRENT_USER ((HKEY) (ULONG_PTR)((LONG)0x80000001))
#ವ್ಯಾಖ್ಯಾನಿಸು HKEY_LOCAL_MACHINE ((HKEY) (ULONG_PTR)((LONG)0x80000002))
#ವ್ಯಾಖ್ಯಾನಿಸು HKEY_USERS ((HKEY) (ULONG_PTR)((LONG)0x80000003))
#ವ್ಯಾಖ್ಯಾನಿಸು HKEY_PERFORMANCE_ದತ್ತಾಂಶ ((HKEY) (ULONG_PTR)((LONG)0x80000004))
#ವ್ಯಾಖ್ಯಾನಿಸು HKEY_PERFORMANCE_ಪಠ್ಯ ((HKEY) (ULONG_PTR)((LONG)0x80000050))
#ವ್ಯಾಖ್ಯಾನಿಸು HKEY_PERFORMANCE_NLSTEXT ((HKEY) (ULONG_PTR)((LONG)0x80000060))
#ವ್ಯಾಖ್ಯಾನಿಸು HKEY_CURRENT_CONFIG ((HKEY) (ULONG_PTR)((LONG)0x80000005))
#ವ್ಯಾಖ್ಯಾನಿಸು HKEY_DYN_ದತ್ತಾಂಶ ((HKEY) (ULONG_PTR)((LONG)0x80000006))

#ವ್ಯಾಖ್ಯಾನಿಸು REG_SECURE_CONNECTION 1

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _PROVIDER_STRUCTS_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _PROVIDER_STRUCTS_DEFINED

#ವ್ಯಾಖ್ಯಾನಿಸು PROVIDER_KEEPS_ಮೌಲ್ಯ_ಉದ್ದಳತೆ 0x1
  ರಚನೆ val_context {
    ಪೂರ್ಣಾಂಕ valuelen;
    LPVOID ಮೌಲ್ಯ_context;
    LPVOID val_buff_ptr;
  };

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ val_context *PVALCONTEXT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ pvalueA {
    LPSTR pv_valuename;
    ಪೂರ್ಣಾಂಕ pv_valuelen;
    LPVOID pv_ಮೌಲ್ಯ_context;
    DWORD pv_type;
  }PVALUEA,*PPVALUEA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ pvalueW {
    LPWSTR pv_valuename;
    ಪೂರ್ಣಾಂಕ pv_valuelen;
    LPVOID pv_ಮೌಲ್ಯ_context;
    DWORD pv_type;
  }PVALUEW,*PPVALUEW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVALUEW PVALUE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PPVALUEW PPVALUE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVALUEA PVALUE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PPVALUEA PPVALUE;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD __cdecl QUERYHANDLER(LPVOID keycontext,PVALCONTEXT val_list,DWORD ಅಂಕೆ_vals,LPVOID outputbuffer,DWORD *ಒಟ್ಟು_outlen,DWORD ಒಳಹರಿವು_blen);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ QUERYHANDLER *PQUERYHANDLER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ provider_info {
    PQUERYHANDLER pi_R0_1val;
    PQUERYHANDLER pi_R0_allvals;
    PQUERYHANDLER pi_R3_1val;
    PQUERYHANDLER pi_R3_allvals;
    DWORD pi_flags;
    LPVOID pi_ಕೀಲಿ_context;
  } REG_PROVIDER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ provider_info *PPROVIDER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಮೌಲ್ಯ_ent_A {
    LPSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTA,*PVALENTA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಮೌಲ್ಯ_ent_W {
    LPWSTR ve_valuename;
    DWORD ve_valuelen;
    DWORD_PTR ve_valueptr;
    DWORD ve_type;
  } VALENTW,*PVALENTW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VALENTW VALENT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVALENTW PVALENT;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VALENTA VALENT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVALENTA PVALENT;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು WIN31_CLASS ಖಾಲಿ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು RegConnectRegistry RegConnectRegistryW
#ವ್ಯಾಖ್ಯಾನಿಸು RegConnectRegistryEx RegConnectRegistryExW
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Create_ಕೀಲಿ Reg_Create_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Create_ಕೀಲಿ_Ex Reg_Create_ಕೀಲಿ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Delete_ಕೀಲಿ Reg_Delete_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Delete_ಕೀಲಿ_Ex Reg_Delete_ಕೀಲಿ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Delete_ಮೌಲ್ಯ Reg_Delete_ಮೌಲ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Enum_ಕೀಲಿ Reg_Enum_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Enum_ಕೀಲಿ_Ex Reg_Enum_ಕೀಲಿ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Enum_ಮೌಲ್ಯ Reg_Enum_ಮೌಲ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_ತುಂಬು_ಕೀಲಿ Reg_ತುಂಬು_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Open_ಕೀಲಿ Reg_Open_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Open_ಕೀಲಿ_Ex Reg_Open_ಕೀಲಿ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Query_Info_ಕೀಲಿ Reg_Query_Info_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Query_ಮೌಲ್ಯ Reg_Query_ಮೌಲ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Query_ಅಪವರ್ತ್ಯ_ಮೌಲ್ಯಗಳು Reg_Query_ಅಪವರ್ತ್ಯ_ಮೌಲ್ಯಗಳು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Query_ಮೌಲ್ಯ_Ex Reg_Query_ಮೌಲ್ಯ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Replace_ಕೀಲಿ Reg_Replace_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Restore_ಕೀಲಿ Reg_Restore_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Save_ಕೀಲಿ Reg_Save_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_ಗಣ_ಮೌಲ್ಯ Reg_ಗಣ_ಮೌಲ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_ಗಣ_ಮೌಲ್ಯ_Ex Reg_ಗಣ_ಮೌಲ್ಯ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Un_ತುಂಬು_ಕೀಲಿ Reg_Un_ತುಂಬು_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Get_ಮೌಲ್ಯ Reg_Get_ಮೌಲ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು InitiateSystemShutdown InitiateSystemShutdownW
#ವ್ಯಾಖ್ಯಾನಿಸು AbortSystemShutdown AbortSystemShutdownW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RegConnectRegistry RegConnectRegistryA
#ವ್ಯಾಖ್ಯಾನಿಸು RegConnectRegistryEx RegConnectRegistryExA
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Create_ಕೀಲಿ Reg_Create_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Create_ಕೀಲಿ_Ex Reg_Create_ಕೀಲಿ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Delete_ಕೀಲಿ Reg_Delete_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Delete_ಕೀಲಿ_Ex Reg_Delete_ಕೀಲಿ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Delete_ಮೌಲ್ಯ Reg_Delete_ಮೌಲ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Enum_ಕೀಲಿ Reg_Enum_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Enum_ಕೀಲಿ_Ex Reg_Enum_ಕೀಲಿ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Enum_ಮೌಲ್ಯ Reg_Enum_ಮೌಲ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_ತುಂಬು_ಕೀಲಿ Reg_ತುಂಬು_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Open_ಕೀಲಿ Reg_Open_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Open_ಕೀಲಿ_Ex Reg_Open_ಕೀಲಿ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Query_Info_ಕೀಲಿ Reg_Query_Info_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Query_ಮೌಲ್ಯ Reg_Query_ಮೌಲ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Query_ಅಪವರ್ತ್ಯ_ಮೌಲ್ಯಗಳು Reg_Query_ಅಪವರ್ತ್ಯ_ಮೌಲ್ಯಗಳು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Query_ಮೌಲ್ಯ_Ex Reg_Query_ಮೌಲ್ಯ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Replace_ಕೀಲಿ Reg_Replace_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Restore_ಕೀಲಿ Reg_Restore_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Save_ಕೀಲಿ Reg_Save_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_ಗಣ_ಮೌಲ್ಯ Reg_ಗಣ_ಮೌಲ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_ಗಣ_ಮೌಲ್ಯ_Ex Reg_ಗಣ_ಮೌಲ್ಯ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Un_ತುಂಬು_ಕೀಲಿ Reg_Un_ತುಂಬು_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Get_ಮೌಲ್ಯ Reg_Get_ಮೌಲ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು InitiateSystemShutdown InitiateSystemShutdownA
#ವ್ಯಾಖ್ಯಾನಿಸು AbortSystemShutdown AbortSystemShutdownA
#ಆದರೆ_ಅಂತ್ಯ

  WINADVAPI LONG WINAPI Reg_Close_ಕೀಲಿ(HKEY h_ಕೀಲಿ);
  WINADVAPI LONG WINAPI Reg_Override_Predef_ಕೀಲಿ(HKEY h_ಕೀಲಿ,HKEY hNewHKey);
  WINADVAPI LONG WINAPI Reg_Open_User_Classes_ಬೇರು(HANDLE hToken,DWORD dwOptions,REGSAM samDesired,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI RegOpenCurrentUser(REGSAM samDesired,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI RegDisablePredefinedCache();
  WINADVAPI LONG WINAPI RegConnectRegistryA(LPCSTR lpMachineName,HKEY h_ಕೀಲಿ,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI RegConnectRegistryW(LPCWSTR lpMachineName,HKEY h_ಕೀಲಿ,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI RegConnectRegistryExA(LPCSTR lpMachineName,HKEY h_ಕೀಲಿ,ULONG Flags,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI RegConnectRegistryExW(LPCWSTR lpMachineName,HKEY h_ಕೀಲಿ,ULONG Flags,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Create_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Create_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Create_ಕೀಲಿ_Ex_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ,DWORD Reserved,LPSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು,PHKEY phk_ಫಲಿತಾಂಶ,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Create_ಕೀಲಿ_Ex_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ,DWORD Reserved,LPWSTR lpClass,DWORD dwOptions,REGSAM samDesired,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು,PHKEY phk_ಫಲಿತಾಂಶ,LPDWORD lpdwDisposition);
  WINADVAPI LONG WINAPI Reg_Delete_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ);
  WINADVAPI LONG WINAPI Reg_Delete_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ);
  WINADVAPI LONG WINAPI Reg_Delete_ಕೀಲಿ_Ex_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Delete_ಕೀಲಿ_Ex_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ,REGSAM samDesired,DWORD Reserved);
  WINADVAPI LONG WINAPI Reg_Disable_Reflection_ಕೀಲಿ(HKEY h_ತಳ);
  WINADVAPI LONG WINAPI Reg_Enable_Reflection_ಕೀಲಿ(HKEY h_ತಳ);
  WINADVAPI LONG WINAPI Reg_Query_Reflection_ಕೀಲಿ(HKEY h_ತಳ,WINBOOL *bIsReflectionDisabled);
  WINADVAPI LONG WINAPI Reg_Delete_ಮೌಲ್ಯ_A(HKEY h_ಕೀಲಿ,LPCSTR lp_ಮೌಲ್ಯ_Name);
  WINADVAPI LONG WINAPI Reg_Delete_ಮೌಲ್ಯ_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_ಮೌಲ್ಯ_Name);
  WINADVAPI LONG WINAPI Reg_Enum_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,DWORD dw_ಸೂಚ್ಯಂಕ,LPSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,DWORD dw_ಸೂಚ್ಯಂಕ,LPWSTR lpName,DWORD cchName);
  WINADVAPI LONG WINAPI Reg_Enum_ಕೀಲಿ_Ex_A(HKEY h_ಕೀಲಿ,DWORD dw_ಸೂಚ್ಯಂಕ,LPSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_ಕೊನೆಯ_Write_ಸಮಯ);
  WINADVAPI LONG WINAPI Reg_Enum_ಕೀಲಿ_Ex_W(HKEY h_ಕೀಲಿ,DWORD dw_ಸೂಚ್ಯಂಕ,LPWSTR lpName,LPDWORD lpcchName,LPDWORD lpReserved,LPWSTR lpClass,LPDWORD lpcchClass,PFILETIME lpft_ಕೊನೆಯ_Write_ಸಮಯ);
  WINADVAPI LONG WINAPI Reg_Enum_ಮೌಲ್ಯ_A(HKEY h_ಕೀಲಿ,DWORD dw_ಸೂಚ್ಯಂಕ,LPSTR lp_ಮೌಲ್ಯ_Name,LPDWORD lpcch_ಮೌಲ್ಯ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_ದತ್ತಾಂಶ,LPDWORD lpcb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Enum_ಮೌಲ್ಯ_W(HKEY h_ಕೀಲಿ,DWORD dw_ಸೂಚ್ಯಂಕ,LPWSTR lp_ಮೌಲ್ಯ_Name,LPDWORD lpcch_ಮೌಲ್ಯ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_ದತ್ತಾಂಶ,LPDWORD lpcb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Flush_ಕೀಲಿ(HKEY h_ಕೀಲಿ);
  WINADVAPI LONG WINAPI Reg_Get_ಕೀಲಿ_Security(HKEY h_ಕೀಲಿ,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,LPDWORD lpcbSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_ತುಂಬು_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ,LPCSTR lpFile);
  WINADVAPI LONG WINAPI Reg_ತುಂಬು_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ,LPCWSTR lpFile);
  WINADVAPI LONG WINAPI Reg_Notify_Change_ಕೀಲಿ_ಮೌಲ್ಯ(HKEY h_ಕೀಲಿ,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,HANDLE hEvent,WINBOOL fAsynchronous);
  WINADVAPI LONG WINAPI Reg_Open_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Open_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Open_ಕೀಲಿ_Ex_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ,DWORD ulOptions,REGSAM samDesired,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Open_ಕೀಲಿ_Ex_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ,DWORD ulOptions,REGSAM samDesired,PHKEY phk_ಫಲಿತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Query_Info_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,LPSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ಕೀಲಿಗಳು,LPDWORD lpcb_Max_Sub_ಕೀಲಿ_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_ಮೌಲ್ಯಗಳು,LPDWORD lpcb_Max_ಮೌಲ್ಯ_Name_Len,LPDWORD lpcb_Max_ಮೌಲ್ಯ_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_ಕೊನೆಯ_Write_ಸಮಯ);
  WINADVAPI LONG WINAPI Reg_Query_Info_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,LPWSTR lpClass,LPDWORD lpcchClass,LPDWORD lpReserved,LPDWORD lpc_Sub_ಕೀಲಿಗಳು,LPDWORD lpcb_Max_Sub_ಕೀಲಿ_Len,LPDWORD lpcbMaxClassLen,LPDWORD lpc_ಮೌಲ್ಯಗಳು,LPDWORD lpcb_Max_ಮೌಲ್ಯ_Name_Len,LPDWORD lpcb_Max_ಮೌಲ್ಯ_Len,LPDWORD lpcbSecurityDescriptor,PFILETIME lpft_ಕೊನೆಯ_Write_ಸಮಯ);
  WINADVAPI LONG WINAPI Reg_Query_ಮೌಲ್ಯ_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ,LPSTR lp_ದತ್ತಾಂಶ,PLONG lpcb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Query_ಮೌಲ್ಯ_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ,LPWSTR lp_ದತ್ತಾಂಶ,PLONG lpcb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Query_ಅಪವರ್ತ್ಯ_ಮೌಲ್ಯಗಳು_A(HKEY h_ಕೀಲಿ,PVALENTA val_list,DWORD ಅಂಕೆ_vals,LPSTR lp_ಮೌಲ್ಯ_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_ಅಪವರ್ತ್ಯ_ಮೌಲ್ಯಗಳು_W(HKEY h_ಕೀಲಿ,PVALENTW val_list,DWORD ಅಂಕೆ_vals,LPWSTR lp_ಮೌಲ್ಯ_Buf,LPDWORD ldwTotsize);
  WINADVAPI LONG WINAPI Reg_Query_ಮೌಲ್ಯ_Ex_A(HKEY h_ಕೀಲಿ,LPCSTR lp_ಮೌಲ್ಯ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_ದತ್ತಾಂಶ,LPDWORD lpcb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Query_ಮೌಲ್ಯ_Ex_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_ಮೌಲ್ಯ_Name,LPDWORD lpReserved,LPDWORD lpType,LPBYTE lp_ದತ್ತಾಂಶ,LPDWORD lpcb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Replace_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ,LPCSTR lpNewFile,LPCSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Replace_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ,LPCWSTR lpNewFile,LPCWSTR lpOldFile);
  WINADVAPI LONG WINAPI Reg_Restore_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,LPCSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Restore_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,LPCWSTR lpFile,DWORD dwFlags);
  WINADVAPI LONG WINAPI Reg_Save_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,LPCSTR lpFile,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINADVAPI LONG WINAPI Reg_Save_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,LPCWSTR lpFile,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINADVAPI LONG WINAPI Reg_ಗಣ_ಕೀಲಿ_Security(HKEY h_ಕೀಲಿ,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI LONG WINAPI Reg_ಗಣ_ಮೌಲ್ಯ_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ,DWORD dwType,LPCSTR lp_ದತ್ತಾಂಶ,DWORD cb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_ಗಣ_ಮೌಲ್ಯ_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ,DWORD dwType,LPCWSTR lp_ದತ್ತಾಂಶ,DWORD cb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_ಗಣ_ಮೌಲ್ಯ_Ex_A(HKEY h_ಕೀಲಿ,LPCSTR lp_ಮೌಲ್ಯ_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_ದತ್ತಾಂಶ,DWORD cb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_ಗಣ_ಮೌಲ್ಯ_Ex_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_ಮೌಲ್ಯ_Name,DWORD Reserved,DWORD dwType,CONST BYTE *lp_ದತ್ತಾಂಶ,DWORD cb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Un_ತುಂಬು_ಕೀಲಿ_A(HKEY h_ಕೀಲಿ,LPCSTR lp_Sub_ಕೀಲಿ);
  WINADVAPI LONG WINAPI Reg_Un_ತುಂಬು_ಕೀಲಿ_W(HKEY h_ಕೀಲಿ,LPCWSTR lp_Sub_ಕೀಲಿ);
  WINADVAPI LONG WINAPI Reg_Get_ಮೌಲ್ಯ_A(HKEY hkey,LPCSTR lp_Sub_ಕೀಲಿ,LPCSTR lp_ಮೌಲ್ಯ,DWORD dwFlags,LPDWORD pdwType,PVOID pv_ದತ್ತಾಂಶ,LPDWORD pcb_ದತ್ತಾಂಶ);
  WINADVAPI LONG WINAPI Reg_Get_ಮೌಲ್ಯ_W(HKEY hkey,LPCWSTR lp_Sub_ಕೀಲಿ,LPCWSTR lp_ಮೌಲ್ಯ,DWORD dwFlags,LPDWORD pdwType,PVOID pv_ದತ್ತಾಂಶ,LPDWORD pcb_ದತ್ತಾಂಶ);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownA(LPSTR lpMachineName,LPSTR lp_ಸಂದೇಶ,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownW(LPWSTR lpMachineName,LPWSTR lp_ಸಂದೇಶ,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownA(LPSTR lpMachineName);
  WINADVAPI WINBOOL WINAPI AbortSystemShutdownW(LPWSTR lpMachineName);

//gr #include <reason.h>

#ವ್ಯಾಖ್ಯಾನಿಸು REASON_SWINSTALL SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_INSTALLATION
#ವ್ಯಾಖ್ಯಾನಿಸು REASON_HWINSTALL SHTDN_REASON_MAJOR_HARDWARE|SHTDN_REASON_MINOR_INSTALLATION
#ವ್ಯಾಖ್ಯಾನಿಸು REASON_SERVICEHANG SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_HUNG
#ವ್ಯಾಖ್ಯಾನಿಸು REASON_UNSTABLE SHTDN_REASON_MAJOR_SYSTEM|SHTDN_REASON_MINOR_UNSTABLE
#ವ್ಯಾಖ್ಯಾನಿಸು REASON_SWHWRECONF SHTDN_REASON_MAJOR_SOFTWARE|SHTDN_REASON_MINOR_RECONFIG
#ವ್ಯಾಖ್ಯಾನಿಸು REASON_OTHER SHTDN_REASON_MAJOR_OTHER|SHTDN_REASON_MINOR_OTHER
#ವ್ಯಾಖ್ಯಾನಿಸು REASON_UNKNOWN SHTDN_REASON_UNKNOWN
#ವ್ಯಾಖ್ಯಾನಿಸು REASON_LEGACY_API SHTDN_REASON_LEGACY_API
#ವ್ಯಾಖ್ಯಾನಿಸು REASON_PLANNED_FLAG SHTDN_REASON_FLAG_PLANNED

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_SHUTDOWN_TIMEOUT (10*365*24*60*60)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು InitiateSystemShutdownEx InitiateSystemShutdownExW
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Save_ಕೀಲಿ_Ex Reg_Save_ಕೀಲಿ_Ex_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು InitiateSystemShutdownEx InitiateSystemShutdownExA
#ವ್ಯಾಖ್ಯಾನಿಸು Reg_Save_ಕೀಲಿ_Ex Reg_Save_ಕೀಲಿ_Ex_A
#ಆದರೆ_ಅಂತ್ಯ

  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExA(LPSTR lpMachineName,LPSTR lp_ಸಂದೇಶ,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI WINBOOL WINAPI InitiateSystemShutdownExW(LPWSTR lpMachineName,LPWSTR lp_ಸಂದೇಶ,DWORD dwTimeout,WINBOOL bForceAppsClosed,WINBOOL bRebootAfterShutdown,DWORD dwReason);
  WINADVAPI LONG WINAPI Reg_Save_ಕೀಲಿ_Ex_A(HKEY h_ಕೀಲಿ,LPCSTR lpFile,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು,DWORD Flags);
  WINADVAPI LONG WINAPI Reg_Save_ಕೀಲಿ_Ex_W(HKEY h_ಕೀಲಿ,LPCWSTR lpFile,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು,DWORD Flags);
  WINADVAPI LONG WINAPI Wow64_Win32_Api_ನಮೂದು (DWORD dw_Func_ಸಂಖ್ಯೆ,DWORD dwFlag,DWORD dwRes);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
