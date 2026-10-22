/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#ଅନ୍ତର୍ଭାଵ <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#ଅନ୍ତର୍ଭାଵ <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(ଶୂନ୍ୟ (__cdecl *_StartAddress) (ଶୂନ୍ୟ *),unsigned ଗଦା_Size,ଶୂନ୍ୟ *_ArgList);
  _CRTIMP ଶୂନ୍ୟ __cdecl _endthread(ଶୂନ୍ୟ);
  _CRTIMP uintptr_t __cdecl _beginthreadex(ଶୂନ୍ୟ *_Security,unsigned ଗଦା_Size,unsigned (__stdcall *_StartAddress) (ଶୂନ୍ୟ *),ଶୂନ୍ୟ *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr);
  _CRTIMP ଶୂନ୍ୟ __cdecl _endthreadex(unsigned _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  ଶୂନ୍ୟ __cdecl __MINGW_NOTHROW exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ଶୂନ୍ୟ __cdecl __MINGW_NOTHROW _exit(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Code) __MINGW_ATTRIB_NORETURN;

#pragma ଠେଲ_macro("abort")
#undef abort
  ଶୂନ୍ୟ __cdecl __declspec(noreturn) abort(ଶୂନ୍ୟ);
#pragma କାଢ଼_macro("abort")

#endif

  _CRTIMP ଶୂନ୍ୟ __cdecl __MINGW_NOTHROW _cexit(ଶୂନ୍ୟ);
  _CRTIMP ଶୂନ୍ୟ __cdecl __MINGW_NOTHROW _c_exit(ଶୂନ୍ୟ);
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _getpid(ଶୂନ୍ୟ);
  _CRTIMP intptr_t __cdecl _cwait(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_TermStat,intptr_t _ProcHandle,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Action);
  _CRTIMP intptr_t __cdecl _execl(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_ArgList,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_ArgList,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_ArgList,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_ArgList,ଅଚଳ ଅକ୍ଷର *ଅଚଳ *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl system(ଅଚଳ ଅକ୍ଷର *_Command);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList,ଅଚଳ wchar_t *ଅଚଳ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList,ଅଚଳ wchar_t *ଅଚଳ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList,ଅଚଳ wchar_t *ଅଚଳ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Mode,ଅଚଳ wchar_t *_Filename,ଅଚଳ wchar_t *ଅଚଳ *_ArgList,ଅଚଳ wchar_t *ଅଚଳ *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _wsystem(ଅଚଳ wchar_t *_Command);
#endif
#endif

  ଶୂନ୍ୟ __cdecl __security_init_cookie(ଶୂନ୍ୟ);
#ଯଦି (defined(_X86_) && !defined(__x86_64))
  ଶୂନ୍ୟ __fastcall __security_check_cookie(uintptr_t ଗଦା_Cookie);
  __declspec(noreturn) ଶୂନ୍ୟ __cdecl __report_gsfailure(ଶୂନ୍ୟ);
#ଅନ୍ୟଥା
  ଶୂନ୍ୟ __cdecl __security_check_cookie(uintptr_t ଗଦା_Cookie);
  __declspec(noreturn) ଶୂନ୍ୟ __cdecl __report_gsfailure(uintptr_t ଗଦା_Cookie);
#endif
  ବାହ୍ୟ uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(ଅକ୍ଷର *_Filename);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl _unloaddll(intptr_t _Handle);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,ଅକ୍ଷର *_ProcedureName,intptr_t _Ordinal))(ଶୂନ୍ୟ);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  ବାହ୍ୟ WINBOOL (WINAPI *ଅଚଳ _pRawDllMain)(HANDLE,DWORD,LPVOID);
#ଅନ୍ୟଥା
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __stdcall DllMain(ଶୂନ୍ୟ *_HDllHandle,unsigned _Reason,ଶୂନ୍ୟ *_Reserved);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __stdcall _CRT_INIT(ଶୂନ୍ୟ *_HDllHandle,unsigned _Reason,ଶୂନ୍ୟ *_Reserved);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __stdcall _wCRT_INIT(ଶୂନ୍ୟ *_HDllHandle,unsigned _Reason,ଶୂନ୍ୟ *_Reserved);
  ବାହ୍ୟ ପୂର୍ଣ୍ଣସଂଖ୍ୟା (__stdcall *ଅଚଳ _pRawDllMain)(ଶୂନ୍ୟ *,unsigned,ଶୂନ୍ୟ *);
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

  intptr_t __cdecl cwait(ପୂର୍ଣ୍ଣସଂଖ୍ୟା *_TermStat,intptr_t _ProcHandle,ପୂର୍ଣ୍ଣସଂଖ୍ୟା _Action);
#ifdef __GNUC__
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl execl(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl execle(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl execlp(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl execlpe(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
#ଅନ୍ୟଥା
    intptr_t __cdecl execl(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  intptr_t __cdecl execle(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  intptr_t __cdecl execlp(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  intptr_t __cdecl execlpe(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  intptr_t __cdecl spawnle(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  intptr_t __cdecl spawnlp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  intptr_t __cdecl spawnlpe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *_ArgList,...);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl getpid(ଶୂନ୍ୟ);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl execv(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[]);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl execve(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[],ଅଚଳ ଅକ୍ଷର *ଅଚଳ _Env[]);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl execvp(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[]);
  ପୂର୍ଣ୍ଣସଂଖ୍ୟା __cdecl execvpe(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[],ଅଚଳ ଅକ୍ଷର *ଅଚଳ _Env[]);
#ଅନ୍ୟଥା
  intptr_t __cdecl execv(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[]);
  intptr_t __cdecl execve(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[],ଅଚଳ ଅକ୍ଷର *ଅଚଳ _Env[]);
  intptr_t __cdecl execvp(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[]);
  intptr_t __cdecl execvpe(ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[],ଅଚଳ ଅକ୍ଷର *ଅଚଳ _Env[]);
#endif
  intptr_t __cdecl spawnv(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[]);
  intptr_t __cdecl spawnve(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[],ଅଚଳ ଅକ୍ଷର *ଅଚଳ _Env[]);
  intptr_t __cdecl spawnvp(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[]);
  intptr_t __cdecl spawnvpe(ପୂର୍ଣ୍ଣସଂଖ୍ୟା,ଅଚଳ ଅକ୍ଷର *_Filename,ଅଚଳ ଅକ୍ଷର *ଅଚଳ _ArgList[],ଅକ୍ଷର *ଅଚଳ _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
