/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _INC_PROCESS
#وصف_ڪريو _INC_PROCESS

#ضمن <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#ضمن <sys/types.h>

#جيڪڏهن_وصف_نه_ٿيل _POSIX_
#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#وصف_ڪريو _P_WAIT 0
#وصف_ڪريو _P_NOWAIT 1
#وصف_ڪريو _OLD_P_OVERLAY 2
#وصف_ڪريو _P_NOWAITO 3
#وصف_ڪريو _P_DETACH 4
#وصف_ڪريو _P_OVERLAY 2

#وصف_ڪريو WAIT_ٻار_2 0
#وصف_ڪريو _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(فراغ (__cdecl *شروعات_پتو) (فراغ *),بنانشان ڍير_سائيز_2,فراغ *_ArgList);
  _CRTIMP فراغ __cdecl _endthread(فراغ);
  _CRTIMP uintptr_t __cdecl _beginthreadex(فراغ *_Security,بنانشان ڍير_سائيز_2,بنانشان (__stdcall *شروعات_پتو) (فراغ *),فراغ *_ArgList,بنانشان _InitFlag,بنانشان *_ThrdAddr);
  _CRTIMP فراغ __cdecl _endthreadex(بنانشان _Retval);

#جيڪڏهن_وصف_نه_ٿيل _CRT_TERMINATE_DEFINED
#وصف_ڪريو _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW ٻاهر_نڪرو(صحيح ڪوڊ_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح ڪوڊ_3) __MINGW_ATTRIB_NORETURN;

#هدايت ڌڪو_macro("abort")
#وصف_رد abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#هدايت ڪڍو_macro("abort")

#جيڪڏهن_پورو

  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _cexit(فراغ);
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _c_exit(فراغ);
  _CRTIMP صحيح __cdecl _getpid(فراغ);
  _CRTIMP intptr_t __cdecl _cwait(صحيح *رڪن_Stat,intptr_t _ProcHandle,صحيح _Action);
  _CRTIMP intptr_t __cdecl _execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(صحيح گهڻائي_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(صحيح گهڻائي_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(صحيح گهڻائي_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(صحيح گهڻائي_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(صحيح گهڻائي_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(صحيح گهڻائي_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(صحيح گهڻائي_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(صحيح گهڻائي_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);

#جيڪڏهن_وصف_نه_ٿيل _CRT_SYSTEM_DEFINED
#وصف_ڪريو _CRT_SYSTEM_DEFINED
  صحيح __cdecl system(ثابت حرف *_Command);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _WPROCESS_DEFINED
#وصف_ڪريو _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحيح گهڻائي_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#جيڪڏهن_وصف_نه_ٿيل _CRT_WSYSTEM_DEFINED
#وصف_ڪريو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  فراغ __cdecl __security_init_cookie(فراغ);
#إذا (defined(_X86_) && !defined(__x86_64))
  فراغ __fastcall __security_check_cookie(uintptr_t ڍير_Cookie);
  __declspec(noreturn) فراغ __cdecl __report_gsfailure(فراغ);
#وإلا
  فراغ __cdecl __security_check_cookie(uintptr_t ڍير_Cookie);
  __declspec(noreturn) فراغ __cdecl __report_gsfailure(uintptr_t ڍير_Cookie);
#جيڪڏهن_پورو
  خارجي uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(حرف *_Filename);
  صحيح __cdecl _unloaddll(intptr_t _Handle);
  صحيح (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,حرف *_ProcedureName,intptr_t _Ordinal))(فراغ);

#جيڪڏهن_وصف_ٿيل _DECL_DLLMAIN
#جيڪڏهن_وصف_ٿيل _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  خارجي WINBOOL (WINAPI *ثابت _pRawDllMain)(HANDLE,DWORD,LPVOID);
#وإلا
  صحيح __stdcall DllMain(فراغ *_HDllHandle,بنانشان _Reason,فراغ *_Reserved);
  صحيح __stdcall _CRT_INIT(فراغ *_HDllHandle,بنانشان _Reason,فراغ *_Reserved);
  صحيح __stdcall _wCRT_INIT(فراغ *_HDllHandle,بنانشان _Reason,فراغ *_Reserved);
  خارجي صحيح (__stdcall *ثابت _pRawDllMain)(فراغ *,بنانشان,فراغ *);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل	NO_OLDNAMES
#وصف_ڪريو P_WAIT _P_WAIT
#وصف_ڪريو P_NOWAIT _P_NOWAIT
#وصف_ڪريو P_OVERLAY _P_OVERLAY
#وصف_ڪريو OLD_P_OVERLAY _OLD_P_OVERLAY
#وصف_ڪريو P_NOWAITO _P_NOWAITO
#وصف_ڪريو P_DETACH _P_DETACH
#وصف_ڪريو WAIT_ٻار WAIT_ٻار_2
#وصف_ڪريو WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(صحيح *رڪن_Stat,intptr_t _ProcHandle,صحيح _Action);
#جيڪڏهن_وصف_ٿيل __GNUC__
  صحيح __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#وإلا
    intptr_t __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#جيڪڏهن_پورو
  intptr_t __cdecl spawnl(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnle(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlp(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlpe(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl getpid(فراغ);
#جيڪڏهن_وصف_ٿيل __GNUC__
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
#جيڪڏهن_پورو
  intptr_t __cdecl spawnv(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnve(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
  intptr_t __cdecl spawnvp(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnvpe(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],حرف *ثابت _Env[]);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو
