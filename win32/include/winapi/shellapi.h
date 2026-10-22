/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_SHELLAPI
#تعریف_کړه _INC_SHELLAPI

#که_نه_تعریف_شوی WINSHELLAPI
#إذا !defined(_SHELL32_)
#تعریف_کړه WINSHELLAPI DECLSPEC_IMPORT
#وإلا
#تعریف_کړه WINSHELLAPI
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی SHSTDAPI
#إذا !defined(_SHELL32_)
#تعریف_کړه SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#تعریف_کړه SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#وإلا
#تعریف_کړه SHSTDAPI STDAPI
#تعریف_کړه SHSTDAPI_(type) STDAPI_(type)
#د_که_پای
#د_که_پای

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#إذا !defined(_WIN64)
#ضمن <pshpack1.h>
#د_که_پای

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه ShellExecute ShellExecuteW
#تعریف_کړه پیدا_کړه_Executable پیدا_کړه_Executable_W
#وإلا
#تعریف_کړه ShellExecute ShellExecuteA
#تعریف_کړه پیدا_کړه_Executable پیدا_کړه_Executable_A
#د_که_پای

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) پیدا_کړه_Executable_A(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_پایله);
  SHSTDAPI_(HINSTANCE) پیدا_کړه_Executable_W(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_پایله);
  SHSTDAPI_(LPWSTR *) Command_کرښه_منزل_Argv_W(LPCWSTR lp_Cmd_کرښه,صحيح*p_عدد_دلیلونه);

#که_تعریف_شوی __cplusplus
}
#د_که_پای

#إذا !defined(_WIN64)
#ضمن <poppack.h>
#د_که_پای
#د_که_پای
