/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_SHELLAPI
#నిర్వచించు _INC_SHELLAPI

#నిర్వచితం_కాకపోతే WINSHELLAPI
#ఒకవేళ !defined(_SHELL32_)
#నిర్వచించు WINSHELLAPI DECLSPEC_IMPORT
#లేకపోతే
#నిర్వచించు WINSHELLAPI
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే SHSTDAPI
#ఒకవేళ !defined(_SHELL32_)
#నిర్వచించు SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#నిర్వచించు SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#లేకపోతే
#నిర్వచించు SHSTDAPI STDAPI
#నిర్వచించు SHSTDAPI_(type) STDAPI_(type)
#అయితే_ముగింపు
#అయితే_ముగింపు

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#ఒకవేళ !defined(_WIN64)
#అన్తర్భావ <pshpack1.h>
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు ShellExecute ShellExecuteW
#నిర్వచించు కనుగొను_Executable కనుగొను_Executable_W
#లేకపోతే
#నిర్వచించు ShellExecute ShellExecuteA
#నిర్వచించు కనుగొను_Executable కనుగొను_Executable_A
#అయితే_ముగింపు

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) కనుగొను_Executable_A(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_ఫలితం);
  SHSTDAPI_(HINSTANCE) కనుగొను_Executable_W(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_ఫలితం);
  SHSTDAPI_(LPWSTR *) Command_పంక్తి_గమ్యం_Argv_W(LPCWSTR lp_Cmd_పంక్తి,పూర్ణాంకం*p_అంకె_వాదనలు);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు

#ఒకవేళ !defined(_WIN64)
#అన్తర్భావ <poppack.h>
#అయితే_ముగింపు
#అయితే_ముగింపు
