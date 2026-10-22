/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#অন্তর্ভাব <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#অন্তর্ভাব <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
বাহ্য "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(শূন্য (__cdecl *_StartAddress) (শূন্য *),unsigned স্তূপ_Size,শূন্য *_ArgList);
  _CRTIMP শূন্য __cdecl _endthread(শূন্য);
  _CRTIMP uintptr_t __cdecl _beginthreadex(শূন্য *_Security,unsigned স্তূপ_Size,unsigned (__stdcall *_StartAddress) (শূন্য *),শূন্য *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr);
  _CRTIMP শূন্য __cdecl _endthreadex(unsigned _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  শূন্য __cdecl __MINGW_NOTHROW exit(পূর্ণাঙ্ক _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP শূন্য __cdecl __MINGW_NOTHROW _exit(পূর্ণাঙ্ক _Code) __MINGW_ATTRIB_NORETURN;

#pragma ঠেলো_macro("abort")
#undef abort
  শূন্য __cdecl __declspec(noreturn) abort(শূন্য);
#pragma বের_করো_macro("abort")

#endif

  _CRTIMP শূন্য __cdecl __MINGW_NOTHROW _cexit(শূন্য);
  _CRTIMP শূন্য __cdecl __MINGW_NOTHROW _c_exit(শূন্য);
  _CRTIMP পূর্ণাঙ্ক __cdecl _getpid(শূন্য);
  _CRTIMP intptr_t __cdecl _cwait(পূর্ণাঙ্ক *_TermStat,intptr_t _ProcHandle,পূর্ণাঙ্ক _Action);
  _CRTIMP intptr_t __cdecl _execl(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব *_ArgList,ধ্রুব বর্ণ *ধ্রুব *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব *_ArgList,ধ্রুব বর্ণ *ধ্রুব *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(পূর্ণাঙ্ক _Mode,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(পূর্ণাঙ্ক _Mode,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(পূর্ণাঙ্ক _Mode,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(পূর্ণাঙ্ক _Mode,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(পূর্ণাঙ্ক _Mode,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(পূর্ণাঙ্ক _Mode,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব *_ArgList,ধ্রুব বর্ণ *ধ্রুব *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(পূর্ণাঙ্ক _Mode,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(পূর্ণাঙ্ক _Mode,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব *_ArgList,ধ্রুব বর্ণ *ধ্রুব *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  পূর্ণাঙ্ক __cdecl system(ধ্রুব বর্ণ *_Command);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList,ধ্রুব wchar_t *ধ্রুব *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList,ধ্রুব wchar_t *ধ্রুব *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList,ধ্রুব wchar_t *ধ্রুব *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(পূর্ণাঙ্ক _Mode,ধ্রুব wchar_t *_Filename,ধ্রুব wchar_t *ধ্রুব *_ArgList,ধ্রুব wchar_t *ধ্রুব *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP পূর্ণাঙ্ক __cdecl _wsystem(ধ্রুব wchar_t *_Command);
#endif
#endif

  শূন্য __cdecl __security_init_cookie(শূন্য);
#যদি (defined(_X86_) && !defined(__x86_64))
  শূন্য __fastcall __security_check_cookie(uintptr_t স্তূপ_Cookie);
  __declspec(noreturn) শূন্য __cdecl __report_gsfailure(শূন্য);
#অন্যথা
  শূন্য __cdecl __security_check_cookie(uintptr_t স্তূপ_Cookie);
  __declspec(noreturn) শূন্য __cdecl __report_gsfailure(uintptr_t স্তূপ_Cookie);
#endif
  বাহ্য uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(বর্ণ *_Filename);
  পূর্ণাঙ্ক __cdecl _unloaddll(intptr_t _Handle);
  পূর্ণাঙ্ক (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,বর্ণ *_ProcedureName,intptr_t _Ordinal))(শূন্য);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  বাহ্য WINBOOL (WINAPI *ধ্রুব _pRawDllMain)(HANDLE,DWORD,LPVOID);
#অন্যথা
  পূর্ণাঙ্ক __stdcall DllMain(শূন্য *_HDllHandle,unsigned _Reason,শূন্য *_Reserved);
  পূর্ণাঙ্ক __stdcall _CRT_INIT(শূন্য *_HDllHandle,unsigned _Reason,শূন্য *_Reserved);
  পূর্ণাঙ্ক __stdcall _wCRT_INIT(শূন্য *_HDllHandle,unsigned _Reason,শূন্য *_Reserved);
  বাহ্য পূর্ণাঙ্ক (__stdcall *ধ্রুব _pRawDllMain)(শূন্য *,unsigned,শূন্য *);
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

  intptr_t __cdecl cwait(পূর্ণাঙ্ক *_TermStat,intptr_t _ProcHandle,পূর্ণাঙ্ক _Action);
#ifdef __GNUC__
  পূর্ণাঙ্ক __cdecl execl(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  পূর্ণাঙ্ক __cdecl execle(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  পূর্ণাঙ্ক __cdecl execlp(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  পূর্ণাঙ্ক __cdecl execlpe(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
#অন্যথা
    intptr_t __cdecl execl(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  intptr_t __cdecl execle(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  intptr_t __cdecl execlp(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  intptr_t __cdecl execlpe(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(পূর্ণাঙ্ক,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  intptr_t __cdecl spawnle(পূর্ণাঙ্ক,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  intptr_t __cdecl spawnlp(পূর্ণাঙ্ক,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  intptr_t __cdecl spawnlpe(পূর্ণাঙ্ক,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *_ArgList,...);
  পূর্ণাঙ্ক __cdecl getpid(শূন্য);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  পূর্ণাঙ্ক __cdecl execv(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[]);
  পূর্ণাঙ্ক __cdecl execve(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[],ধ্রুব বর্ণ *ধ্রুব _Env[]);
  পূর্ণাঙ্ক __cdecl execvp(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[]);
  পূর্ণাঙ্ক __cdecl execvpe(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[],ধ্রুব বর্ণ *ধ্রুব _Env[]);
#অন্যথা
  intptr_t __cdecl execv(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[]);
  intptr_t __cdecl execve(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[],ধ্রুব বর্ণ *ধ্রুব _Env[]);
  intptr_t __cdecl execvp(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[]);
  intptr_t __cdecl execvpe(ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[],ধ্রুব বর্ণ *ধ্রুব _Env[]);
#endif
  intptr_t __cdecl spawnv(পূর্ণাঙ্ক,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[]);
  intptr_t __cdecl spawnve(পূর্ণাঙ্ক,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[],ধ্রুব বর্ণ *ধ্রুব _Env[]);
  intptr_t __cdecl spawnvp(পূর্ণাঙ্ক,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[]);
  intptr_t __cdecl spawnvpe(পূর্ণাঙ্ক,ধ্রুব বর্ণ *_Filename,ধ্রুব বর্ণ *ধ্রুব _ArgList[],বর্ণ *ধ্রুব _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
