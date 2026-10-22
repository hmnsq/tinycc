/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#include <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#include <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
extern "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(void (__cdecl *_StartAddress) (void *),unsigned _StackSize,void *_ArgList);
  _CRTIMP void __cdecl _endthread(void);
  _CRTIMP uintptr_t __cdecl _beginthreadex(void *_Security,unsigned _StackSize,unsigned (__stdcall *_StartAddress) (void *),void *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr);
  _CRTIMP void __cdecl _endthreadex(unsigned _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  void __cdecl __MINGW_NOTHROW exit(จำนวนเต็ม _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP void __cdecl __MINGW_NOTHROW _exit(จำนวนเต็ม _Code) __MINGW_ATTRIB_NORETURN;

#pragma push_macro("abort")
#undef abort
  void __cdecl __declspec(noreturn) abort(void);
#pragma pop_macro("abort")

#endif

  _CRTIMP void __cdecl __MINGW_NOTHROW _cexit(void);
  _CRTIMP void __cdecl __MINGW_NOTHROW _c_exit(void);
  _CRTIMP จำนวนเต็ม __cdecl _getpid(void);
  _CRTIMP intptr_t __cdecl _cwait(จำนวนเต็ม *_TermStat,intptr_t _ProcHandle,จำนวนเต็ม _Action);
  _CRTIMP intptr_t __cdecl _execl(const var_na *_Filename,const var_na *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(const var_na *_Filename,const var_na *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(const var_na *_Filename,const var_na *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(const var_na *_Filename,const var_na *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(const var_na *_Filename,const var_na *const *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(const var_na *_Filename,const var_na *const *_ArgList,const var_na *const *_Env);
  _CRTIMP intptr_t __cdecl _execvp(const var_na *_Filename,const var_na *const *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(const var_na *_Filename,const var_na *const *_ArgList,const var_na *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(จำนวนเต็ม _Mode,const var_na *_Filename,const var_na *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(จำนวนเต็ม _Mode,const var_na *_Filename,const var_na *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(จำนวนเต็ม _Mode,const var_na *_Filename,const var_na *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(จำนวนเต็ม _Mode,const var_na *_Filename,const var_na *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(จำนวนเต็ม _Mode,const var_na *_Filename,const var_na *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(จำนวนเต็ม _Mode,const var_na *_Filename,const var_na *const *_ArgList,const var_na *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(จำนวนเต็ม _Mode,const var_na *_Filename,const var_na *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(จำนวนเต็ม _Mode,const var_na *_Filename,const var_na *const *_ArgList,const var_na *const *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  จำนวนเต็ม __cdecl system(const var_na *_Command);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(จำนวนเต็ม _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(จำนวนเต็ม _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(จำนวนเต็ม _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(จำนวนเต็ม _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(จำนวนเต็ม _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(จำนวนเต็ม _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(จำนวนเต็ม _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(จำนวนเต็ม _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP จำนวนเต็ม __cdecl _wsystem(const wchar_t *_Command);
#endif
#endif

  void __cdecl __security_init_cookie(void);
#ถ้า (defined(_X86_) && !defined(__x86_64))
  void __fastcall __security_check_cookie(uintptr_t _StackCookie);
  __declspec(noreturn) void __cdecl __report_gsfailure(void);
#มิฉะนั้น
  void __cdecl __security_check_cookie(uintptr_t _StackCookie);
  __declspec(noreturn) void __cdecl __report_gsfailure(uintptr_t _StackCookie);
#endif
  extern uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(var_na *_Filename);
  จำนวนเต็ม __cdecl _unloaddll(intptr_t _Handle);
  จำนวนเต็ม (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,var_na *_ProcedureName,intptr_t _Ordinal))(void);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  extern WINBOOL (WINAPI *const _pRawDllMain)(HANDLE,DWORD,LPVOID);
#มิฉะนั้น
  จำนวนเต็ม __stdcall DllMain(void *_HDllHandle,unsigned _Reason,void *_Reserved);
  จำนวนเต็ม __stdcall _CRT_INIT(void *_HDllHandle,unsigned _Reason,void *_Reserved);
  จำนวนเต็ม __stdcall _wCRT_INIT(void *_HDllHandle,unsigned _Reason,void *_Reserved);
  extern จำนวนเต็ม (__stdcall *const _pRawDllMain)(void *,unsigned,void *);
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

  intptr_t __cdecl cwait(จำนวนเต็ม *_TermStat,intptr_t _ProcHandle,จำนวนเต็ม _Action);
#ifdef __GNUC__
  จำนวนเต็ม __cdecl execl(const var_na *_Filename,const var_na *_ArgList,...);
  จำนวนเต็ม __cdecl execle(const var_na *_Filename,const var_na *_ArgList,...);
  จำนวนเต็ม __cdecl execlp(const var_na *_Filename,const var_na *_ArgList,...);
  จำนวนเต็ม __cdecl execlpe(const var_na *_Filename,const var_na *_ArgList,...);
#มิฉะนั้น
    intptr_t __cdecl execl(const var_na *_Filename,const var_na *_ArgList,...);
  intptr_t __cdecl execle(const var_na *_Filename,const var_na *_ArgList,...);
  intptr_t __cdecl execlp(const var_na *_Filename,const var_na *_ArgList,...);
  intptr_t __cdecl execlpe(const var_na *_Filename,const var_na *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(จำนวนเต็ม,const var_na *_Filename,const var_na *_ArgList,...);
  intptr_t __cdecl spawnle(จำนวนเต็ม,const var_na *_Filename,const var_na *_ArgList,...);
  intptr_t __cdecl spawnlp(จำนวนเต็ม,const var_na *_Filename,const var_na *_ArgList,...);
  intptr_t __cdecl spawnlpe(จำนวนเต็ม,const var_na *_Filename,const var_na *_ArgList,...);
  จำนวนเต็ม __cdecl getpid(void);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  จำนวนเต็ม __cdecl execv(const var_na *_Filename,const var_na *const _ArgList[]);
  จำนวนเต็ม __cdecl execve(const var_na *_Filename,const var_na *const _ArgList[],const var_na *const _Env[]);
  จำนวนเต็ม __cdecl execvp(const var_na *_Filename,const var_na *const _ArgList[]);
  จำนวนเต็ม __cdecl execvpe(const var_na *_Filename,const var_na *const _ArgList[],const var_na *const _Env[]);
#มิฉะนั้น
  intptr_t __cdecl execv(const var_na *_Filename,const var_na *const _ArgList[]);
  intptr_t __cdecl execve(const var_na *_Filename,const var_na *const _ArgList[],const var_na *const _Env[]);
  intptr_t __cdecl execvp(const var_na *_Filename,const var_na *const _ArgList[]);
  intptr_t __cdecl execvpe(const var_na *_Filename,const var_na *const _ArgList[],const var_na *const _Env[]);
#endif
  intptr_t __cdecl spawnv(จำนวนเต็ม,const var_na *_Filename,const var_na *const _ArgList[]);
  intptr_t __cdecl spawnve(จำนวนเต็ม,const var_na *_Filename,const var_na *const _ArgList[],const var_na *const _Env[]);
  intptr_t __cdecl spawnvp(จำนวนเต็ม,const var_na *_Filename,const var_na *const _ArgList[]);
  intptr_t __cdecl spawnvpe(จำนวนเต็ม,const var_na *_Filename,const var_na *const _ArgList[],var_na *const _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
