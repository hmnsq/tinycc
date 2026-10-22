/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_SHELLAPI
#define _INC_SHELLAPI

#ifndef WINSHELLAPI
#എങ്കിൽ !defined(_SHELL32_)
#define WINSHELLAPI DECLSPEC_IMPORT
#അല്ലെങ്കിൽ
#define WINSHELLAPI
#endif
#endif

#ifndef SHSTDAPI
#എങ്കിൽ !defined(_SHELL32_)
#define SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#അല്ലെങ്കിൽ
#define SHSTDAPI STDAPI
#define SHSTDAPI_(type) STDAPI_(type)
#endif
#endif

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#എങ്കിൽ !defined(_WIN64)
#അന്തര്ഭാവ <pshpack1.h>
#endif

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#ifdef UNICODE
#define ShellExecute ShellExecuteW
#define FindExecutable FindExecutableW
#അല്ലെങ്കിൽ
#define ShellExecute ShellExecuteA
#define FindExecutable FindExecutableA
#endif

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) FindExecutableA(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lpResult);
  SHSTDAPI_(HINSTANCE) FindExecutableW(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lpResult);
  SHSTDAPI_(LPWSTR *) Command_വരി_To_Argv_W(LPCWSTR lp_Cmd_വരി,പൂർണ്ണസംഖ്യ*p_അക്കം_Args);

#ifdef __cplusplus
}
#endif

#എങ്കിൽ !defined(_WIN64)
#അന്തര്ഭാവ <poppack.h>
#endif
#endif
