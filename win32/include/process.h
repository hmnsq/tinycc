/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#അന്തര്ഭാവ <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#അന്തര്ഭാവ <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(ശൂന്യം (__cdecl *_StartAddress) (ശൂന്യം *),unsigned അട്ടി_Size,ശൂന്യം *_ArgList);
  _CRTIMP ശൂന്യം __cdecl _endthread(ശൂന്യം);
  _CRTIMP uintptr_t __cdecl _beginthreadex(ശൂന്യം *_Security,unsigned അട്ടി_Size,unsigned (__stdcall *_StartAddress) (ശൂന്യം *),ശൂന്യം *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr);
  _CRTIMP ശൂന്യം __cdecl _endthreadex(unsigned _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  ശൂന്യം __cdecl __MINGW_NOTHROW exit(പൂർണ്ണസംഖ്യ _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ശൂന്യം __cdecl __MINGW_NOTHROW _exit(പൂർണ്ണസംഖ്യ _Code) __MINGW_ATTRIB_NORETURN;

#pragma തള്ളുക_macro("abort")
#undef abort
  ശൂന്യം __cdecl __declspec(noreturn) abort(ശൂന്യം);
#pragma എടുക്കുക_macro("abort")

#endif

  _CRTIMP ശൂന്യം __cdecl __MINGW_NOTHROW _cexit(ശൂന്യം);
  _CRTIMP ശൂന്യം __cdecl __MINGW_NOTHROW _c_exit(ശൂന്യം);
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _getpid(ശൂന്യം);
  _CRTIMP intptr_t __cdecl _cwait(പൂർണ്ണസംഖ്യ *_TermStat,intptr_t _ProcHandle,പൂർണ്ണസംഖ്യ _Action);
  _CRTIMP intptr_t __cdecl _execl(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_ArgList,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_Env);
  _CRTIMP intptr_t __cdecl _execvp(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_ArgList,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_ArgList,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_ArgList,സ്ഥിരം അക്ഷരം *സ്ഥിരം *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  പൂർണ്ണസംഖ്യ __cdecl system(സ്ഥിരം അക്ഷരം *_Command);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList,സ്ഥിരം wchar_t *സ്ഥിരം *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList,സ്ഥിരം wchar_t *സ്ഥിരം *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList,സ്ഥിരം wchar_t *സ്ഥിരം *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(പൂർണ്ണസംഖ്യ _Mode,സ്ഥിരം wchar_t *_Filename,സ്ഥിരം wchar_t *സ്ഥിരം *_ArgList,സ്ഥിരം wchar_t *സ്ഥിരം *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP പൂർണ്ണസംഖ്യ __cdecl _wsystem(സ്ഥിരം wchar_t *_Command);
#endif
#endif

  ശൂന്യം __cdecl __security_init_cookie(ശൂന്യം);
#എങ്കിൽ (defined(_X86_) && !defined(__x86_64))
  ശൂന്യം __fastcall __security_check_cookie(uintptr_t അട്ടി_Cookie);
  __declspec(noreturn) ശൂന്യം __cdecl __report_gsfailure(ശൂന്യം);
#അല്ലെങ്കിൽ
  ശൂന്യം __cdecl __security_check_cookie(uintptr_t അട്ടി_Cookie);
  __declspec(noreturn) ശൂന്യം __cdecl __report_gsfailure(uintptr_t അട്ടി_Cookie);
#endif
  ബാഹ്യ uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(അക്ഷരം *_Filename);
  പൂർണ്ണസംഖ്യ __cdecl _unloaddll(intptr_t _Handle);
  പൂർണ്ണസംഖ്യ (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,അക്ഷരം *_ProcedureName,intptr_t _Ordinal))(ശൂന്യം);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  ബാഹ്യ WINBOOL (WINAPI *സ്ഥിരം _pRawDllMain)(HANDLE,DWORD,LPVOID);
#അല്ലെങ്കിൽ
  പൂർണ്ണസംഖ്യ __stdcall DllMain(ശൂന്യം *_HDllHandle,unsigned _Reason,ശൂന്യം *_Reserved);
  പൂർണ്ണസംഖ്യ __stdcall _CRT_INIT(ശൂന്യം *_HDllHandle,unsigned _Reason,ശൂന്യം *_Reserved);
  പൂർണ്ണസംഖ്യ __stdcall _wCRT_INIT(ശൂന്യം *_HDllHandle,unsigned _Reason,ശൂന്യം *_Reserved);
  ബാഹ്യ പൂർണ്ണസംഖ്യ (__stdcall *സ്ഥിരം _pRawDllMain)(ശൂന്യം *,unsigned,ശൂന്യം *);
#endif
#endif

#ifndef	NO_OLDNAMES
#define P_WAIT _P_WAIT
#define P_NOWAIT _P_NOWAIT
#define P_OVERLAY _P_OVERLAY
#define OLD_P_OVERLAY _OLD_P_OVERLAY
#define P_NOWAITO _P_NOWAITO
#define P_DETACH _P_DETACH
#define WAIT_CHILD _WAIT_CHILD
#define WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(പൂർണ്ണസംഖ്യ *_TermStat,intptr_t _ProcHandle,പൂർണ്ണസംഖ്യ _Action);
#ifdef __GNUC__
  പൂർണ്ണസംഖ്യ __cdecl execl(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  പൂർണ്ണസംഖ്യ __cdecl execle(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  പൂർണ്ണസംഖ്യ __cdecl execlp(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  പൂർണ്ണസംഖ്യ __cdecl execlpe(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
#അല്ലെങ്കിൽ
    intptr_t __cdecl execl(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  intptr_t __cdecl execle(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  intptr_t __cdecl execlp(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  intptr_t __cdecl execlpe(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(പൂർണ്ണസംഖ്യ,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  intptr_t __cdecl spawnle(പൂർണ്ണസംഖ്യ,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  intptr_t __cdecl spawnlp(പൂർണ്ണസംഖ്യ,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  intptr_t __cdecl spawnlpe(പൂർണ്ണസംഖ്യ,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *_ArgList,...);
  പൂർണ്ണസംഖ്യ __cdecl getpid(ശൂന്യം);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  പൂർണ്ണസംഖ്യ __cdecl execv(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[]);
  പൂർണ്ണസംഖ്യ __cdecl execve(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[],സ്ഥിരം അക്ഷരം *സ്ഥിരം _Env[]);
  പൂർണ്ണസംഖ്യ __cdecl execvp(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[]);
  പൂർണ്ണസംഖ്യ __cdecl execvpe(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[],സ്ഥിരം അക്ഷരം *സ്ഥിരം _Env[]);
#അല്ലെങ്കിൽ
  intptr_t __cdecl execv(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[]);
  intptr_t __cdecl execve(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[],സ്ഥിരം അക്ഷരം *സ്ഥിരം _Env[]);
  intptr_t __cdecl execvp(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[]);
  intptr_t __cdecl execvpe(സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[],സ്ഥിരം അക്ഷരം *സ്ഥിരം _Env[]);
#endif
  intptr_t __cdecl spawnv(പൂർണ്ണസംഖ്യ,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[]);
  intptr_t __cdecl spawnve(പൂർണ്ണസംഖ്യ,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[],സ്ഥിരം അക്ഷരം *സ്ഥിരം _Env[]);
  intptr_t __cdecl spawnvp(പൂർണ്ണസംഖ്യ,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[]);
  intptr_t __cdecl spawnvpe(പൂർണ്ണസംഖ്യ,സ്ഥിരം അക്ഷരം *_Filename,സ്ഥിരം അക്ഷരം *സ്ഥിരം _ArgList[],അക്ഷരം *സ്ഥിരം _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
