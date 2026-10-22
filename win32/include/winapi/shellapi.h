/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_SHELLAPI
#परिभाषय _INC_SHELLAPI

#यदि_अपरिभाषितम् WINSHELLAPI
#यदि !defined(_SHELL32_)
#परिभाषय WINSHELLAPI DECLSPEC_IMPORT
#अन्यथा
#परिभाषय WINSHELLAPI
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् SHSTDAPI
#यदि !defined(_SHELL32_)
#परिभाषय SHSTDAPI EXTERN_C DECLSPEC_IMPORT HRESULT WINAPI
#परिभाषय SHSTDAPI_(type) EXTERN_C DECLSPEC_IMPORT type WINAPI
#अन्यथा
#परिभाषय SHSTDAPI STDAPI
#परिभाषय SHSTDAPI_(type) STDAPI_(type)
#यदि_अन्तः
#यदि_अन्तः

/* SHDOCAPI[_] definitions not required in this TinyCC minimal header */

#यदि !defined(_WIN64)
#अन्तर्भाव <pshpack1.h>
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय ShellExecute ShellExecuteW
#परिभाषय FindExecutable FindExecutableW
#अन्यथा
#परिभाषय ShellExecute ShellExecuteA
#परिभाषय FindExecutable FindExecutableA
#यदि_अन्तः

  /* minimal subset distributed with TinyCC. nShowCmd is at winuser.h */
  SHSTDAPI_(HINSTANCE) ShellExecuteA(HWND hwnd,LPCSTR lpOperation,LPCSTR lpFile,LPCSTR lpParameters,LPCSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) ShellExecuteW(HWND hwnd,LPCWSTR lpOperation,LPCWSTR lpFile,LPCWSTR lpParameters,LPCWSTR lpDirectory,INT nShowCmd);
  SHSTDAPI_(HINSTANCE) FindExecutableA(LPCSTR lpFile,LPCSTR lpDirectory,LPSTR lp_परिणाम);
  SHSTDAPI_(HINSTANCE) FindExecutableW(LPCWSTR lpFile,LPCWSTR lpDirectory,LPWSTR lp_परिणाम);
  SHSTDAPI_(LPWSTR *) Command_पङ्क्तिः_गन्तव्यम्_Argv_W(LPCWSTR lp_Cmd_पङ्क्तिः,पूर्णाङ्क*p_अङ्कः_तर्काः);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः

#यदि !defined(_WIN64)
#अन्तर्भाव <poppack.h>
#यदि_अन्तः
#यदि_अन्तः
