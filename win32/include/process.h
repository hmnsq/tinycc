/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#شامل <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#شامل <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
بیرونی "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(تهی (__cdecl *_StartAddress) (تهی *),unsigned پشته_Size,تهی *_ArgList);
  _CRTIMP تهی __cdecl _endthread(تهی);
  _CRTIMP uintptr_t __cdecl _beginthreadex(تهی *_Security,unsigned پشته_Size,unsigned (__stdcall *_StartAddress) (تهی *),تهی *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr);
  _CRTIMP تهی __cdecl _endthreadex(unsigned _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  تهی __cdecl __MINGW_NOTHROW exit(صحیح _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP تهی __cdecl __MINGW_NOTHROW _exit(صحیح _Code) __MINGW_ATTRIB_NORETURN;

#pragma افزودن_macro("abort")
#undef abort
  تهی __cdecl __declspec(noreturn) abort(تهی);
#pragma برداشت_macro("abort")

#endif

  _CRTIMP تهی __cdecl __MINGW_NOTHROW _cexit(تهی);
  _CRTIMP تهی __cdecl __MINGW_NOTHROW _c_exit(تهی);
  _CRTIMP صحیح __cdecl _getpid(تهی);
  _CRTIMP intptr_t __cdecl _cwait(صحیح *_TermStat,intptr_t _ProcHandle,صحیح _Action);
  _CRTIMP intptr_t __cdecl _execl(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ثابت نویسه *_Filename,ثابت نویسه *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ثابت نویسه *_Filename,ثابت نویسه *ثابت *_ArgList,ثابت نویسه *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ثابت نویسه *_Filename,ثابت نویسه *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ثابت نویسه *_Filename,ثابت نویسه *ثابت *_ArgList,ثابت نویسه *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(صحیح _Mode,ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(صحیح _Mode,ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(صحیح _Mode,ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(صحیح _Mode,ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(صحیح _Mode,ثابت نویسه *_Filename,ثابت نویسه *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(صحیح _Mode,ثابت نویسه *_Filename,ثابت نویسه *ثابت *_ArgList,ثابت نویسه *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(صحیح _Mode,ثابت نویسه *_Filename,ثابت نویسه *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(صحیح _Mode,ثابت نویسه *_Filename,ثابت نویسه *ثابت *_ArgList,ثابت نویسه *ثابت *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  صحیح __cdecl system(ثابت نویسه *_Command);
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
  _CRTIMP intptr_t __cdecl _wspawnl(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحیح _Mode,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP صحیح __cdecl _wsystem(ثابت wchar_t *_Command);
#endif
#endif

  تهی __cdecl __security_init_cookie(تهی);
#اگر (defined(_X86_) && !defined(__x86_64))
  تهی __fastcall __security_check_cookie(uintptr_t پشته_Cookie);
  __declspec(noreturn) تهی __cdecl __report_gsfailure(تهی);
#وگرنه
  تهی __cdecl __security_check_cookie(uintptr_t پشته_Cookie);
  __declspec(noreturn) تهی __cdecl __report_gsfailure(uintptr_t پشته_Cookie);
#endif
  بیرونی uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(نویسه *_Filename);
  صحیح __cdecl _unloaddll(intptr_t _Handle);
  صحیح (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,نویسه *_ProcedureName,intptr_t _Ordinal))(تهی);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  بیرونی WINBOOL (WINAPI *ثابت _pRawDllMain)(HANDLE,DWORD,LPVOID);
#وگرنه
  صحیح __stdcall DllMain(تهی *_HDllHandle,unsigned _Reason,تهی *_Reserved);
  صحیح __stdcall _CRT_INIT(تهی *_HDllHandle,unsigned _Reason,تهی *_Reserved);
  صحیح __stdcall _wCRT_INIT(تهی *_HDllHandle,unsigned _Reason,تهی *_Reserved);
  بیرونی صحیح (__stdcall *ثابت _pRawDllMain)(تهی *,unsigned,تهی *);
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

  intptr_t __cdecl cwait(صحیح *_TermStat,intptr_t _ProcHandle,صحیح _Action);
#ifdef __GNUC__
  صحیح __cdecl execl(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  صحیح __cdecl execle(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  صحیح __cdecl execlp(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  صحیح __cdecl execlpe(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
#وگرنه
    intptr_t __cdecl execl(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  intptr_t __cdecl execle(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  intptr_t __cdecl execlp(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  intptr_t __cdecl execlpe(ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(صحیح,ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  intptr_t __cdecl spawnle(صحیح,ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  intptr_t __cdecl spawnlp(صحیح,ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  intptr_t __cdecl spawnlpe(صحیح,ثابت نویسه *_Filename,ثابت نویسه *_ArgList,...);
  صحیح __cdecl getpid(تهی);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  صحیح __cdecl execv(ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[]);
  صحیح __cdecl execve(ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[],ثابت نویسه *ثابت _Env[]);
  صحیح __cdecl execvp(ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[]);
  صحیح __cdecl execvpe(ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[],ثابت نویسه *ثابت _Env[]);
#وگرنه
  intptr_t __cdecl execv(ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[]);
  intptr_t __cdecl execve(ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[],ثابت نویسه *ثابت _Env[]);
  intptr_t __cdecl execvp(ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[]);
  intptr_t __cdecl execvpe(ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[],ثابت نویسه *ثابت _Env[]);
#endif
  intptr_t __cdecl spawnv(صحیح,ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[]);
  intptr_t __cdecl spawnve(صحیح,ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[],ثابت نویسه *ثابت _Env[]);
  intptr_t __cdecl spawnvp(صحیح,ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[]);
  intptr_t __cdecl spawnvpe(صحیح,ثابت نویسه *_Filename,ثابت نویسه *ثابت _ArgList[],نویسه *ثابت _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
