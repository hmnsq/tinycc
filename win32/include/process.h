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
  void __cdecl __MINGW_NOTHROW exit(цяло _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP void __cdecl __MINGW_NOTHROW _exit(цяло _Code) __MINGW_ATTRIB_NORETURN;

#pragma push_macro("abort")
#undef abort
  void __cdecl __declspec(noreturn) abort(void);
#pragma pop_macro("abort")

#endif

  _CRTIMP void __cdecl __MINGW_NOTHROW _cexit(void);
  _CRTIMP void __cdecl __MINGW_NOTHROW _c_exit(void);
  _CRTIMP цяло __cdecl _getpid(void);
  _CRTIMP intptr_t __cdecl _cwait(цяло *_TermStat,intptr_t _ProcHandle,цяло _Action);
  _CRTIMP intptr_t __cdecl _execl(const char *_Filename,const char *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(const char *_Filename,const char *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(const char *_Filename,const char *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(const char *_Filename,const char *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(const char *_Filename,const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(const char *_Filename,const char *const *_ArgList,const char *const *_Env);
  _CRTIMP intptr_t __cdecl _execvp(const char *_Filename,const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(const char *_Filename,const char *const *_ArgList,const char *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(цяло _Mode,const char *_Filename,const char *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(цяло _Mode,const char *_Filename,const char *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(цяло _Mode,const char *_Filename,const char *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(цяло _Mode,const char *_Filename,const char *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(цяло _Mode,const char *_Filename,const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(цяло _Mode,const char *_Filename,const char *const *_ArgList,const char *const *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(цяло _Mode,const char *_Filename,const char *const *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(цяло _Mode,const char *_Filename,const char *const *_ArgList,const char *const *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  цяло __cdecl system(const char *_Command);
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
  _CRTIMP intptr_t __cdecl _wspawnl(цяло _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(цяло _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(цяло _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(цяло _Mode,const wchar_t *_Filename,const wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(цяло _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(цяло _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(цяло _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(цяло _Mode,const wchar_t *_Filename,const wchar_t *const *_ArgList,const wchar_t *const *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP цяло __cdecl _wsystem(const wchar_t *_Command);
#endif
#endif

  void __cdecl __security_init_cookie(void);
#ако (defined(_X86_) && !defined(__x86_64))
  void __fastcall __security_check_cookie(uintptr_t _StackCookie);
  __declspec(noreturn) void __cdecl __report_gsfailure(void);
#иначе
  void __cdecl __security_check_cookie(uintptr_t _StackCookie);
  __declspec(noreturn) void __cdecl __report_gsfailure(uintptr_t _StackCookie);
#endif
  extern uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(char *_Filename);
  цяло __cdecl _unloaddll(intptr_t _Handle);
  цяло (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,char *_ProcedureName,intptr_t _Ordinal))(void);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  extern WINBOOL (WINAPI *const _pRawDllMain)(HANDLE,DWORD,LPVOID);
#иначе
  цяло __stdcall DllMain(void *_HDllHandle,unsigned _Reason,void *_Reserved);
  цяло __stdcall _CRT_INIT(void *_HDllHandle,unsigned _Reason,void *_Reserved);
  цяло __stdcall _wCRT_INIT(void *_HDllHandle,unsigned _Reason,void *_Reserved);
  extern цяло (__stdcall *const _pRawDllMain)(void *,unsigned,void *);
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

  intptr_t __cdecl cwait(цяло *_TermStat,intptr_t _ProcHandle,цяло _Action);
#ifdef __GNUC__
  цяло __cdecl execl(const char *_Filename,const char *_ArgList,...);
  цяло __cdecl execle(const char *_Filename,const char *_ArgList,...);
  цяло __cdecl execlp(const char *_Filename,const char *_ArgList,...);
  цяло __cdecl execlpe(const char *_Filename,const char *_ArgList,...);
#иначе
    intptr_t __cdecl execl(const char *_Filename,const char *_ArgList,...);
  intptr_t __cdecl execle(const char *_Filename,const char *_ArgList,...);
  intptr_t __cdecl execlp(const char *_Filename,const char *_ArgList,...);
  intptr_t __cdecl execlpe(const char *_Filename,const char *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(цяло,const char *_Filename,const char *_ArgList,...);
  intptr_t __cdecl spawnle(цяло,const char *_Filename,const char *_ArgList,...);
  intptr_t __cdecl spawnlp(цяло,const char *_Filename,const char *_ArgList,...);
  intptr_t __cdecl spawnlpe(цяло,const char *_Filename,const char *_ArgList,...);
  цяло __cdecl getpid(void);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  цяло __cdecl execv(const char *_Filename,const char *const _ArgList[]);
  цяло __cdecl execve(const char *_Filename,const char *const _ArgList[],const char *const _Env[]);
  цяло __cdecl execvp(const char *_Filename,const char *const _ArgList[]);
  цяло __cdecl execvpe(const char *_Filename,const char *const _ArgList[],const char *const _Env[]);
#иначе
  intptr_t __cdecl execv(const char *_Filename,const char *const _ArgList[]);
  intptr_t __cdecl execve(const char *_Filename,const char *const _ArgList[],const char *const _Env[]);
  intptr_t __cdecl execvp(const char *_Filename,const char *const _ArgList[]);
  intptr_t __cdecl execvpe(const char *_Filename,const char *const _ArgList[],const char *const _Env[]);
#endif
  intptr_t __cdecl spawnv(цяло,const char *_Filename,const char *const _ArgList[]);
  intptr_t __cdecl spawnve(цяло,const char *_Filename,const char *const _ArgList[],const char *const _Env[]);
  intptr_t __cdecl spawnvp(цяло,const char *_Filename,const char *const _ArgList[]);
  intptr_t __cdecl spawnvpe(цяло,const char *_Filename,const char *const _ArgList[],char *const _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
