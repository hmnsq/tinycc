/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _INC_PROCESS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _INC_PROCESS

#ਅਨ੍ਤਰ੍ਭਾਵ <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#ਅਨ੍ਤਰ੍ਭਾਵ <sys/types.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _POSIX_
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _P_WAIT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _P_NOWAIT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _OLD_P_OVERLAY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _P_NOWAITO 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _P_DETACH 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _P_OVERLAY 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_ਬੱਚਾ_2 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(ਖਾਲੀ (__cdecl *ਸ਼ੁਰੂ_ਪਤਾ) (ਖਾਲੀ *),ਬਿਨਾਨਿਸ਼ਾਨੀ ਢੇਰ_ਮਾਪ_2,ਖਾਲੀ *_ArgList);
  _CRTIMP ਖਾਲੀ __cdecl _endthread(ਖਾਲੀ);
  _CRTIMP uintptr_t __cdecl _beginthreadex(ਖਾਲੀ *_Security,ਬਿਨਾਨਿਸ਼ਾਨੀ ਢੇਰ_ਮਾਪ_2,ਬਿਨਾਨਿਸ਼ਾਨੀ (__stdcall *ਸ਼ੁਰੂ_ਪਤਾ) (ਖਾਲੀ *),ਖਾਲੀ *_ArgList,ਬਿਨਾਨਿਸ਼ਾਨੀ _InitFlag,ਬਿਨਾਨਿਸ਼ਾਨੀ *_ThrdAddr);
  _CRTIMP ਖਾਲੀ __cdecl _endthreadex(ਬਿਨਾਨਿਸ਼ਾਨੀ _Retval);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_TERMINATE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_TERMINATE_DEFINED
  ਖਾਲੀ __cdecl __MINGW_NOTHROW ਬਾਹਰ_ਨਿਕਲੋ(ਪੂਰਨ ਕੋਡ_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ਖਾਲੀ __cdecl __MINGW_NOTHROW _exit(ਪੂਰਨ ਕੋਡ_3) __MINGW_ATTRIB_NORETURN;

#ਹਦਾਇਤ ਧੱਕੋ_macro("abort")
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ abort
  ਖਾਲੀ __cdecl __declspec(noreturn) abort(ਖਾਲੀ);
#ਹਦਾਇਤ ਕੱਢੋ_macro("abort")

#ਜੇ_ਅੰਤ

  _CRTIMP ਖਾਲੀ __cdecl __MINGW_NOTHROW _cexit(ਖਾਲੀ);
  _CRTIMP ਖਾਲੀ __cdecl __MINGW_NOTHROW _c_exit(ਖਾਲੀ);
  _CRTIMP ਪੂਰਨ __cdecl _getpid(ਖਾਲੀ);
  _CRTIMP intptr_t __cdecl _cwait(ਪੂਰਨ *ਪਦ_Stat,intptr_t _ProcHandle,ਪੂਰਨ _Action);
  _CRTIMP intptr_t __cdecl _execl(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_ArgList,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_ArgList,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_ArgList,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_ArgList,ਅਚਲ ਅੱਖਰ *ਅਚਲ *_Env);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_SYSTEM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_SYSTEM_DEFINED
  ਪੂਰਨ __cdecl system(ਅਚਲ ਅੱਖਰ *_Command);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WPROCESS_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList,ਅਚਲ wchar_t *ਅਚਲ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList,ਅਚਲ wchar_t *ਅਚਲ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList,ਅਚਲ wchar_t *ਅਚਲ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(ਪੂਰਨ ਬਹੁਲਕ_3,ਅਚਲ wchar_t *_Filename,ਅਚਲ wchar_t *ਅਚਲ *_ArgList,ਅਚਲ wchar_t *ਅਚਲ *_Env);
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _CRT_WSYSTEM_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CRT_WSYSTEM_DEFINED
  _CRTIMP ਪੂਰਨ __cdecl _wsystem(ਅਚਲ wchar_t *_Command);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  ਖਾਲੀ __cdecl __security_init_cookie(ਖਾਲੀ);
#ਜੇ (defined(_X86_) && !defined(__x86_64))
  ਖਾਲੀ __fastcall __security_check_cookie(uintptr_t ਢੇਰ_Cookie);
  __declspec(noreturn) ਖਾਲੀ __cdecl __report_gsfailure(ਖਾਲੀ);
#ਨਹੀਂਤਾਂ
  ਖਾਲੀ __cdecl __security_check_cookie(uintptr_t ਢੇਰ_Cookie);
  __declspec(noreturn) ਖਾਲੀ __cdecl __report_gsfailure(uintptr_t ਢੇਰ_Cookie);
#ਜੇ_ਅੰਤ
  ਬਾਹਰੀ uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(ਅੱਖਰ *_Filename);
  ਪੂਰਨ __cdecl _unloaddll(intptr_t _Handle);
  ਪੂਰਨ (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,ਅੱਖਰ *_ProcedureName,intptr_t _Ordinal))(ਖਾਲੀ);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _DECL_DLLMAIN
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  ਬਾਹਰੀ WINBOOL (WINAPI *ਅਚਲ _pRawDllMain)(HANDLE,DWORD,LPVOID);
#ਨਹੀਂਤਾਂ
  ਪੂਰਨ __stdcall DllMain(ਖਾਲੀ *_HDllHandle,ਬਿਨਾਨਿਸ਼ਾਨੀ _Reason,ਖਾਲੀ *_Reserved);
  ਪੂਰਨ __stdcall _CRT_INIT(ਖਾਲੀ *_HDllHandle,ਬਿਨਾਨਿਸ਼ਾਨੀ _Reason,ਖਾਲੀ *_Reserved);
  ਪੂਰਨ __stdcall _wCRT_INIT(ਖਾਲੀ *_HDllHandle,ਬਿਨਾਨਿਸ਼ਾਨੀ _Reason,ਖਾਲੀ *_Reserved);
  ਬਾਹਰੀ ਪੂਰਨ (__stdcall *ਅਚਲ _pRawDllMain)(ਖਾਲੀ *,ਬਿਨਾਨਿਸ਼ਾਨੀ,ਖਾਲੀ *);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ	NO_OLDNAMES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ P_WAIT _P_WAIT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ P_NOWAIT _P_NOWAIT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ P_OVERLAY _P_OVERLAY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OLD_P_OVERLAY _OLD_P_OVERLAY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ P_NOWAITO _P_NOWAITO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ P_DETACH _P_DETACH
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_ਬੱਚਾ WAIT_ਬੱਚਾ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(ਪੂਰਨ *ਪਦ_Stat,intptr_t _ProcHandle,ਪੂਰਨ _Action);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __GNUC__
  ਪੂਰਨ __cdecl execl(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  ਪੂਰਨ __cdecl execle(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  ਪੂਰਨ __cdecl execlp(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  ਪੂਰਨ __cdecl execlpe(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
#ਨਹੀਂਤਾਂ
    intptr_t __cdecl execl(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  intptr_t __cdecl execle(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  intptr_t __cdecl execlp(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  intptr_t __cdecl execlpe(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
#ਜੇ_ਅੰਤ
  intptr_t __cdecl spawnl(ਪੂਰਨ,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  intptr_t __cdecl spawnle(ਪੂਰਨ,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  intptr_t __cdecl spawnlp(ਪੂਰਨ,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  intptr_t __cdecl spawnlpe(ਪੂਰਨ,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *_ArgList,...);
  ਪੂਰਨ __cdecl getpid(ਖਾਲੀ);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  ਪੂਰਨ __cdecl execv(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[]);
  ਪੂਰਨ __cdecl execve(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[],ਅਚਲ ਅੱਖਰ *ਅਚਲ _Env[]);
  ਪੂਰਨ __cdecl execvp(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[]);
  ਪੂਰਨ __cdecl execvpe(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[],ਅਚਲ ਅੱਖਰ *ਅਚਲ _Env[]);
#ਨਹੀਂਤਾਂ
  intptr_t __cdecl execv(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[]);
  intptr_t __cdecl execve(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[],ਅਚਲ ਅੱਖਰ *ਅਚਲ _Env[]);
  intptr_t __cdecl execvp(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[]);
  intptr_t __cdecl execvpe(ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[],ਅਚਲ ਅੱਖਰ *ਅਚਲ _Env[]);
#ਜੇ_ਅੰਤ
  intptr_t __cdecl spawnv(ਪੂਰਨ,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[]);
  intptr_t __cdecl spawnve(ਪੂਰਨ,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[],ਅਚਲ ਅੱਖਰ *ਅਚਲ _Env[]);
  intptr_t __cdecl spawnvp(ਪੂਰਨ,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[]);
  intptr_t __cdecl spawnvpe(ਪੂਰਨ,ਅਚਲ ਅੱਖਰ *_Filename,ਅਚਲ ਅੱਖਰ *ਅਚਲ _ArgList[],ਅੱਖਰ *ਅਚਲ _Env[]);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
