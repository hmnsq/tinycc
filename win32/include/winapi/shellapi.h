/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_SHELLAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_SHELLAPI

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WINSHELLAPI
#ਜੇ !defined(_SHELL32_)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSHELLAPI DECLSPEC_IMPORT
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSHELLAPI
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ SHSTDAPI
#ਜੇ !defined(_SHELL32_)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHSTDAPI STDAPI
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHSTDAPI_(type) STDAPI_(type)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#ਜੇ !defined(_WIN64)
#ਅਨ੍ਤਰ੍ਭਾਵ <pshpack1.h>
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ShellExecute ShellExecuteW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Executable ਲੱਭੋ_Executable_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ShellExecute ShellExecuteA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Executable ਲੱਭੋ_Executable_A
#ਜੇ_ਅੰਤ

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ਲੱਭੋ_Executable_A(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_ਨਤੀਜਾ);
  SHSTDAPI_(HINSTANCE) ਲੱਭੋ_Executable_W(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_ਨਤੀਜਾ);
  SHSTDAPI_(LPWSTR *) Command_ਸਤਰ_ਮੰਜ਼ਿਲ_Argv_W(LPCWSTR lp_Cmd_ਸਤਰ,ਪੂਰਨ*p_ਅੰਕ_ਦਲੀਲਾਂ);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ

#ਜੇ !defined(_WIN64)
#ਅਨ੍ਤਰ੍ਭਾਵ <poppack.h>
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
