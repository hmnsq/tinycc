/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_SHELLAPI
#define _INC_SHELLAPI

#ifndef WINSHELLAPI
#ಯದಿ !defined(_SHELL32_)
#define WINSHELLAPI DECLSPEC_IMPORT
#ಅನ್ಯಥಾ
#define WINSHELLAPI
#endif
#endif

#ifndef SHSTDAPI
#ಯದಿ !defined(_SHELL32_)
#define SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#define SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#ಅನ್ಯಥಾ
#define SHSTDAPI STDAPI
#define SHSTDAPI_(type) STDAPI_(type)
#endif
#endif

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#ಯದಿ !defined(_WIN64)
#ಅನ್ತರ್ಭಾವ <pshpack1.h>
#endif

#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#ifdef UNICODE
#define ShellExecute ShellExecuteW
#define FindExecutable FindExecutableW
#ಅನ್ಯಥಾ
#define ShellExecute ShellExecuteA
#define FindExecutable FindExecutableA
#endif

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) FindExecutableA(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lpResult);
  SHSTDAPI_(HINSTANCE) FindExecutableW(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lpResult);
  SHSTDAPI_(LPWSTR *) Command_ಸಾಲು_To_Argv_W(LPCWSTR lp_Cmd_ಸಾಲು,ಪೂರ್ಣಾಙ್ಕ*p_ಅಂಕೆ_Args);

#ifdef __cplusplus
}
#endif

#ಯದಿ !defined(_WIN64)
#ಅನ್ತರ್ಭಾವ <poppack.h>
#endif
#endif
