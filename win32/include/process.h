/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _INC_PROCESS
#تعریف_کړه _INC_PROCESS

#ضمن <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#ضمن <sys/types.h>

#که_نه_تعریف_شوی _POSIX_
#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#تعریف_کړه _P_WAIT 0
#تعریف_کړه _P_NOWAIT 1
#تعریف_کړه _OLD_P_OVERLAY 2
#تعریف_کړه _P_NOWAITO 3
#تعریف_کړه _P_DETACH 4
#تعریف_کړه _P_OVERLAY 2

#تعریف_کړه WAIT_ماشوم_2 0
#تعریف_کړه _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(فراغ (__cdecl *پیل_پته) (فراغ *),بینښه ډېری_اندازه_2,فراغ *_ArgList);
  _CRTIMP فراغ __cdecl _endthread(فراغ);
  _CRTIMP uintptr_t __cdecl _beginthreadex(فراغ *_Security,بینښه ډېری_اندازه_2,بینښه (__stdcall *پیل_پته) (فراغ *),فراغ *_ArgList,بینښه _InitFlag,بینښه *_ThrdAddr);
  _CRTIMP فراغ __cdecl _endthreadex(بینښه _Retval);

#که_نه_تعریف_شوی _CRT_TERMINATE_DEFINED
#تعریف_کړه _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW وتل(صحيح کوډ_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح کوډ_3) __MINGW_ATTRIB_NORETURN;

#لارښوونه ټېل_macro("abort")
#تعریف_لغوه abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#لارښوونه راوباسه_macro("abort")

#د_که_پای

  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _cexit(فراغ);
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _c_exit(فراغ);
  _CRTIMP صحيح __cdecl _getpid(فراغ);
  _CRTIMP intptr_t __cdecl _cwait(صحيح *غړی_Stat,intptr_t _ProcHandle,صحيح _Action);
  _CRTIMP intptr_t __cdecl _execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(صحيح ډېرپېښ_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(صحيح ډېرپېښ_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(صحيح ډېرپېښ_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(صحيح ډېرپېښ_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(صحيح ډېرپېښ_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(صحيح ډېرپېښ_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(صحيح ډېرپېښ_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(صحيح ډېرپېښ_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);

#که_نه_تعریف_شوی _CRT_SYSTEM_DEFINED
#تعریف_کړه _CRT_SYSTEM_DEFINED
  صحيح __cdecl system(ثابت حرف *_Command);
#د_که_پای

#که_نه_تعریف_شوی _WPROCESS_DEFINED
#تعریف_کړه _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحيح ډېرپېښ_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحيح ډېرپېښ_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحيح ډېرپېښ_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحيح ډېرپېښ_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحيح ډېرپېښ_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحيح ډېرپېښ_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحيح ډېرپېښ_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحيح ډېرپېښ_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#که_نه_تعریف_شوی _CRT_WSYSTEM_DEFINED
#تعریف_کړه _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#د_که_پای
#د_که_پای

  فراغ __cdecl __security_init_cookie(فراغ);
#إذا (defined(_X86_) && !defined(__x86_64))
  فراغ __fastcall __security_check_cookie(uintptr_t ډېری_Cookie);
  __declspec(noreturn) فراغ __cdecl __report_gsfailure(فراغ);
#وإلا
  فراغ __cdecl __security_check_cookie(uintptr_t ډېری_Cookie);
  __declspec(noreturn) فراغ __cdecl __report_gsfailure(uintptr_t ډېری_Cookie);
#د_که_پای
  خارجي uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(حرف *_Filename);
  صحيح __cdecl _unloaddll(intptr_t _Handle);
  صحيح (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,حرف *_ProcedureName,intptr_t _Ordinal))(فراغ);

#که_تعریف_شوی _DECL_DLLMAIN
#که_تعریف_شوی _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  خارجي WINBOOL (WINAPI *ثابت _pRawDllMain)(HANDLE,DWORD,LPVOID);
#وإلا
  صحيح __stdcall DllMain(فراغ *_HDllHandle,بینښه _Reason,فراغ *_Reserved);
  صحيح __stdcall _CRT_INIT(فراغ *_HDllHandle,بینښه _Reason,فراغ *_Reserved);
  صحيح __stdcall _wCRT_INIT(فراغ *_HDllHandle,بینښه _Reason,فراغ *_Reserved);
  خارجي صحيح (__stdcall *ثابت _pRawDllMain)(فراغ *,بینښه,فراغ *);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی	NO_OLDNAMES
#تعریف_کړه P_WAIT _P_WAIT
#تعریف_کړه P_NOWAIT _P_NOWAIT
#تعریف_کړه P_OVERLAY _P_OVERLAY
#تعریف_کړه OLD_P_OVERLAY _OLD_P_OVERLAY
#تعریف_کړه P_NOWAITO _P_NOWAITO
#تعریف_کړه P_DETACH _P_DETACH
#تعریف_کړه WAIT_ماشوم WAIT_ماشوم_2
#تعریف_کړه WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(صحيح *غړی_Stat,intptr_t _ProcHandle,صحيح _Action);
#که_تعریف_شوی __GNUC__
  صحيح __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#وإلا
    intptr_t __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#د_که_پای
  intptr_t __cdecl spawnl(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnle(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlp(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlpe(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl getpid(فراغ);
#که_تعریف_شوی __GNUC__
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
#د_که_پای
  intptr_t __cdecl spawnv(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnve(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
  intptr_t __cdecl spawnvp(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnvpe(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],حرف *ثابت _Env[]);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
#د_که_پای
