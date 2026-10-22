/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#ضمن <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#ضمن <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
خارجي "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(فراغ (__cdecl *_StartAddress) (فراغ *),unsigned مكدس_Size,فراغ *_ArgList);
  _CRTIMP فراغ __cdecl _endthread(فراغ);
  _CRTIMP uintptr_t __cdecl _beginthreadex(فراغ *_Security,unsigned مكدس_Size,unsigned (__stdcall *_StartAddress) (فراغ *),فراغ *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr);
  _CRTIMP فراغ __cdecl _endthreadex(unsigned _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW exit(صحيح _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح _Code) __MINGW_ATTRIB_NORETURN;

#pragma ادفع_macro("abort")
#undef abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#pragma اسحب_macro("abort")

#endif

  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _cexit(فراغ);
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _c_exit(فراغ);
  _CRTIMP صحيح __cdecl _getpid(فراغ);
  _CRTIMP intptr_t __cdecl _cwait(صحيح *_TermStat,intptr_t _ProcHandle,صحيح _Action);
  _CRTIMP intptr_t __cdecl _execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(صحيح _Mode,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(صحيح _Mode,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(صحيح _Mode,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(صحيح _Mode,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(صحيح _Mode,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(صحيح _Mode,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(صحيح _Mode,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(صحيح _Mode,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  صحيح __cdecl system(ثابت حرف *_Command);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحيح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحيح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحيح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحيح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحيح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحيح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحيح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحيح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#endif
#endif

  فراغ __cdecl __security_init_cookie(فراغ);
#إذا (defined(_X86_) && !defined(__x86_64))
  فراغ __fastcall __security_check_cookie(uintptr_t مكدس_Cookie);
  __declspec(noreturn) فراغ __cdecl __report_gsfailure(فراغ);
#وإلا
  فراغ __cdecl __security_check_cookie(uintptr_t مكدس_Cookie);
  __declspec(noreturn) فراغ __cdecl __report_gsfailure(uintptr_t مكدس_Cookie);
#endif
  خارجي uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(حرف *_Filename);
  صحيح __cdecl _unloaddll(intptr_t _Handle);
  صحيح (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,حرف *_ProcedureName,intptr_t _Ordinal))(فراغ);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  خارجي WINBOOL (WINAPI *ثابت _pRawDllMain)(HANDLE,DWORD,LPVOID);
#وإلا
  صحيح __stdcall DllMain(فراغ *_HDllHandle,unsigned _Reason,فراغ *_Reserved);
  صحيح __stdcall _CRT_INIT(فراغ *_HDllHandle,unsigned _Reason,فراغ *_Reserved);
  صحيح __stdcall _wCRT_INIT(فراغ *_HDllHandle,unsigned _Reason,فراغ *_Reserved);
  خارجي صحيح (__stdcall *ثابت _pRawDllMain)(فراغ *,unsigned,فراغ *);
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

  intptr_t __cdecl cwait(صحيح *_TermStat,intptr_t _ProcHandle,صحيح _Action);
#ifdef __GNUC__
  صحيح __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#وإلا
    intptr_t __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnle(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlp(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlpe(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl getpid(فراغ);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  صحيح __cdecl execv(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  صحيح __cdecl execve(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
  صحيح __cdecl execvp(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  صحيح __cdecl execvpe(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
#وإلا
  intptr_t __cdecl execv(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl execve(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
  intptr_t __cdecl execvp(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl execvpe(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
#endif
  intptr_t __cdecl spawnv(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnve(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
  intptr_t __cdecl spawnvp(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnvpe(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],حرف *ثابت _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
