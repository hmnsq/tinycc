/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_SHELLAPI
#घोषणा _INC_SHELLAPI

#अगर_अघोषित WINSHELLAPI
#अगर !defined(_SHELL32_)
#घोषणा WINSHELLAPI DECLSPEC_IMPORT
#अन्यथा
#घोषणा WINSHELLAPI
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित SHSTDAPI
#अगर !defined(_SHELL32_)
#घोषणा SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#घोषणा SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#अन्यथा
#घोषणा SHSTDAPI STDAPI
#घोषणा SHSTDAPI_(type) STDAPI_(type)
#पूर्ण_अगर
#पूर्ण_अगर

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#अगर !defined(_WIN64)
#समावेश <pshpack1.h>
#पूर्ण_अगर

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_घोषित UNICODE
#घोषणा ShellExecute ShellExecuteW
#घोषणा FindExecutable FindExecutableW
#अन्यथा
#घोषणा ShellExecute ShellExecuteA
#घोषणा FindExecutable FindExecutableA
#पूर्ण_अगर

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) FindExecutableA(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_परिणाम);
  SHSTDAPI_(HINSTANCE) FindExecutableW(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_परिणाम);
  SHSTDAPI_(LPWSTR *) Command_पंक्ति_To_Argv_W(LPCWSTR lp_Cmd_पंक्ति,पूर्णांक*p_अंक_Args);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#अगर !defined(_WIN64)
#समावेश <poppack.h>
#पूर्ण_अगर
#पूर्ण_अगर
