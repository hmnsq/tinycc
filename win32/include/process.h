/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#ಅನ್ತರ್ಭಾವ <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#ಅನ್ತರ್ಭಾವ <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
ಬಾಹ್ಯ "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(ಶೂನ್ಯ (__cdecl *_StartAddress) (ಶೂನ್ಯ *),unsigned ರಾಶಿ_Size,ಶೂನ್ಯ *_ArgList);
  _CRTIMP ಶೂನ್ಯ __cdecl _endthread(ಶೂನ್ಯ);
  _CRTIMP uintptr_t __cdecl _beginthreadex(ಶೂನ್ಯ *_Security,unsigned ರಾಶಿ_Size,unsigned (__stdcall *_StartAddress) (ಶೂನ್ಯ *),ಶೂನ್ಯ *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr);
  _CRTIMP ಶೂನ್ಯ __cdecl _endthreadex(unsigned _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  ಶೂನ್ಯ __cdecl __MINGW_NOTHROW exit(ಪೂರ್ಣಾಙ್ಕ _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ಶೂನ್ಯ __cdecl __MINGW_NOTHROW _exit(ಪೂರ್ಣಾಙ್ಕ _Code) __MINGW_ATTRIB_NORETURN;

#pragma ತಳ್ಳು_macro("abort")
#undef abort
  ಶೂನ್ಯ __cdecl __declspec(noreturn) abort(ಶೂನ್ಯ);
#pragma ತೆಗೆ_macro("abort")

#endif

  _CRTIMP ಶೂನ್ಯ __cdecl __MINGW_NOTHROW _cexit(ಶೂನ್ಯ);
  _CRTIMP ಶೂನ್ಯ __cdecl __MINGW_NOTHROW _c_exit(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _getpid(ಶೂನ್ಯ);
  _CRTIMP intptr_t __cdecl _cwait(ಪೂರ್ಣಾಙ್ಕ *_TermStat,intptr_t _ProcHandle,ಪೂರ್ಣಾಙ್ಕ _Action);
  _CRTIMP intptr_t __cdecl _execl(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_ArgList,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_ArgList,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_ArgList,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_ArgList,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  ಪೂರ್ಣಾಙ್ಕ __cdecl system(ಧ್ರುವ ವರ್ಣ *_Command);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList,ಧ್ರುವ wchar_t *ಧ್ರುವ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList,ಧ್ರುವ wchar_t *ಧ್ರುವ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList,ಧ್ರುವ wchar_t *ಧ್ರುವ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(ಪೂರ್ಣಾಙ್ಕ _Mode,ಧ್ರುವ wchar_t *_Filename,ಧ್ರುವ wchar_t *ಧ್ರುವ *_ArgList,ಧ್ರುವ wchar_t *ಧ್ರುವ *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP ಪೂರ್ಣಾಙ್ಕ __cdecl _wsystem(ಧ್ರುವ wchar_t *_Command);
#endif
#endif

  ಶೂನ್ಯ __cdecl __security_init_cookie(ಶೂನ್ಯ);
#ಯದಿ (defined(_X86_) && !defined(__x86_64))
  ಶೂನ್ಯ __fastcall __security_check_cookie(uintptr_t ರಾಶಿ_Cookie);
  __declspec(noreturn) ಶೂನ್ಯ __cdecl __report_gsfailure(ಶೂನ್ಯ);
#ಅನ್ಯಥಾ
  ಶೂನ್ಯ __cdecl __security_check_cookie(uintptr_t ರಾಶಿ_Cookie);
  __declspec(noreturn) ಶೂನ್ಯ __cdecl __report_gsfailure(uintptr_t ರಾಶಿ_Cookie);
#endif
  ಬಾಹ್ಯ uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(ವರ್ಣ *_Filename);
  ಪೂರ್ಣಾಙ್ಕ __cdecl _unloaddll(intptr_t _Handle);
  ಪೂರ್ಣಾಙ್ಕ (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,ವರ್ಣ *_ProcedureName,intptr_t _Ordinal))(ಶೂನ್ಯ);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  ಬಾಹ್ಯ WINBOOL (WINAPI *ಧ್ರುವ _pRawDllMain)(HANDLE,DWORD,LPVOID);
#ಅನ್ಯಥಾ
  ಪೂರ್ಣಾಙ್ಕ __stdcall DllMain(ಶೂನ್ಯ *_HDllHandle,unsigned _Reason,ಶೂನ್ಯ *_Reserved);
  ಪೂರ್ಣಾಙ್ಕ __stdcall _CRT_INIT(ಶೂನ್ಯ *_HDllHandle,unsigned _Reason,ಶೂನ್ಯ *_Reserved);
  ಪೂರ್ಣಾಙ್ಕ __stdcall _wCRT_INIT(ಶೂನ್ಯ *_HDllHandle,unsigned _Reason,ಶೂನ್ಯ *_Reserved);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಙ್ಕ (__stdcall *ಧ್ರುವ _pRawDllMain)(ಶೂನ್ಯ *,unsigned,ಶೂನ್ಯ *);
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

  intptr_t __cdecl cwait(ಪೂರ್ಣಾಙ್ಕ *_TermStat,intptr_t _ProcHandle,ಪೂರ್ಣಾಙ್ಕ _Action);
#ifdef __GNUC__
  ಪೂರ್ಣಾಙ್ಕ __cdecl execl(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl execle(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl execlp(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl execlpe(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
#ಅನ್ಯಥಾ
    intptr_t __cdecl execl(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  intptr_t __cdecl execle(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  intptr_t __cdecl execlp(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  intptr_t __cdecl execlpe(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(ಪೂರ್ಣಾಙ್ಕ,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  intptr_t __cdecl spawnle(ಪೂರ್ಣಾಙ್ಕ,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  intptr_t __cdecl spawnlp(ಪೂರ್ಣಾಙ್ಕ,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  intptr_t __cdecl spawnlpe(ಪೂರ್ಣಾಙ್ಕ,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *_ArgList,...);
  ಪೂರ್ಣಾಙ್ಕ __cdecl getpid(ಶೂನ್ಯ);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  ಪೂರ್ಣಾಙ್ಕ __cdecl execv(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[]);
  ಪೂರ್ಣಾಙ್ಕ __cdecl execve(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[],ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _Env[]);
  ಪೂರ್ಣಾಙ್ಕ __cdecl execvp(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[]);
  ಪೂರ್ಣಾಙ್ಕ __cdecl execvpe(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[],ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _Env[]);
#ಅನ್ಯಥಾ
  intptr_t __cdecl execv(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[]);
  intptr_t __cdecl execve(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[],ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _Env[]);
  intptr_t __cdecl execvp(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[]);
  intptr_t __cdecl execvpe(ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[],ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _Env[]);
#endif
  intptr_t __cdecl spawnv(ಪೂರ್ಣಾಙ್ಕ,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[]);
  intptr_t __cdecl spawnve(ಪೂರ್ಣಾಙ್ಕ,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[],ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _Env[]);
  intptr_t __cdecl spawnvp(ಪೂರ್ಣಾಙ್ಕ,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[]);
  intptr_t __cdecl spawnvpe(ಪೂರ್ಣಾಙ್ಕ,ಧ್ರುವ ವರ್ಣ *_Filename,ಧ್ರುವ ವರ್ಣ *ಧ್ರುವ _ArgList[],ವರ್ಣ *ಧ್ರುವ _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
