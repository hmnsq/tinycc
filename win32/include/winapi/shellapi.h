/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_SHELLAPI
#تعریف_کرو _INC_SHELLAPI

#اگر_غیر_تعریف_شدہ WINSHELLAPI
#اگر !defined(_SHELL32_)
#تعریف_کرو WINSHELLAPI DECLSPEC_IMPORT
#ورنہ
#تعریف_کرو WINSHELLAPI
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ SHSTDAPI
#اگر !defined(_SHELL32_)
#تعریف_کرو SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#تعریف_کرو SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#ورنہ
#تعریف_کرو SHSTDAPI STDAPI
#تعریف_کرو SHSTDAPI_(type) STDAPI_(type)
#اگر_ختم
#اگر_ختم

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#اگر !defined(_WIN64)
#شامل <pshpack1.h>
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو ShellExecute ShellExecuteW
#تعریف_کرو ڈھونڈو_Executable ڈھونڈو_Executable_W
#ورنہ
#تعریف_کرو ShellExecute ShellExecuteA
#تعریف_کرو ڈھونڈو_Executable ڈھونڈو_Executable_A
#اگر_ختم

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ڈھونڈو_Executable_A(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_نتیجہ);
  SHSTDAPI_(HINSTANCE) ڈھونڈو_Executable_W(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_نتیجہ);
  SHSTDAPI_(LPWSTR *) Command_سطر_مقصد_Argv_W(LPCWSTR lp_Cmd_سطر,صحیح*p_عدد_دلائل);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر !defined(_WIN64)
#شامل <poppack.h>
#اگر_ختم
#اگر_ختم
