/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _INC_PROCESS
#تعریف_کرو _INC_PROCESS

#ضمن <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#ضمن <sys/types.h>

#جے_بنا_تعریف _POSIX_
#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#تعریف_کرو _P_WAIT 0
#تعریف_کرو _P_NOWAIT 1
#تعریف_کرو _OLD_P_OVERLAY 2
#تعریف_کرو _P_NOWAITO 3
#تعریف_کرو _P_DETACH 4
#تعریف_کرو _P_OVERLAY 2

#تعریف_کرو WAIT_بچہ_2 0
#تعریف_کرو _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(فراغ (__cdecl *شروع_پتہ) (فراغ *),بنانشانی ڈھیر_ناپ_2,فراغ *_ArgList);
  _CRTIMP فراغ __cdecl _endthread(فراغ);
  _CRTIMP uintptr_t __cdecl _beginthreadex(فراغ *_Security,بنانشانی ڈھیر_ناپ_2,بنانشانی (__stdcall *شروع_پتہ) (فراغ *),فراغ *_ArgList,بنانشانی _InitFlag,بنانشانی *_ThrdAddr);
  _CRTIMP فراغ __cdecl _endthreadex(بنانشانی _Retval);

#جے_بنا_تعریف _CRT_TERMINATE_DEFINED
#تعریف_کرو _CRT_TERMINATE_DEFINED
  فراغ __cdecl __MINGW_NOTHROW باہر_نکلو(صحيح کوڈ_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _exit(صحيح کوڈ_3) __MINGW_ATTRIB_NORETURN;

#ہدایت ڈالو_macro("abort")
#تعریف_رد abort
  فراغ __cdecl __declspec(noreturn) abort(فراغ);
#ہدایت نکالو_macro("abort")

#جے_انت

  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _cexit(فراغ);
  _CRTIMP فراغ __cdecl __MINGW_NOTHROW _c_exit(فراغ);
  _CRTIMP صحيح __cdecl _getpid(فراغ);
  _CRTIMP intptr_t __cdecl _cwait(صحيح *رکن_Stat,intptr_t _ProcHandle,صحيح _Action);
  _CRTIMP intptr_t __cdecl _execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(صحيح منوال_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(صحيح منوال_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(صحيح منوال_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(صحيح منوال_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(صحيح منوال_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(صحيح منوال_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(صحيح منوال_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(صحيح منوال_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);

#جے_بنا_تعریف _CRT_SYSTEM_DEFINED
#تعریف_کرو _CRT_SYSTEM_DEFINED
  صحيح __cdecl system(ثابت حرف *_Command);
#جے_انت

#جے_بنا_تعریف _WPROCESS_DEFINED
#تعریف_کرو _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحيح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#جے_بنا_تعریف _CRT_WSYSTEM_DEFINED
#تعریف_کرو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحيح __cdecl _wsystem(ثابت wchar_t *_Command);
#جے_انت
#جے_انت

  فراغ __cdecl __security_init_cookie(فراغ);
#إذا (defined(_X86_) && !defined(__x86_64))
  فراغ __fastcall __security_check_cookie(uintptr_t ڈھیر_Cookie);
  __declspec(noreturn) فراغ __cdecl __report_gsfailure(فراغ);
#وإلا
  فراغ __cdecl __security_check_cookie(uintptr_t ڈھیر_Cookie);
  __declspec(noreturn) فراغ __cdecl __report_gsfailure(uintptr_t ڈھیر_Cookie);
#جے_انت
  خارجي uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(حرف *_Filename);
  صحيح __cdecl _unloaddll(intptr_t _Handle);
  صحيح (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,حرف *_ProcedureName,intptr_t _Ordinal))(فراغ);

#جے_تعریف_شدہ _DECL_DLLMAIN
#جے_تعریف_شدہ _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  خارجي WINBOOL (WINAPI *ثابت _pRawDllMain)(HANDLE,DWORD,LPVOID);
#وإلا
  صحيح __stdcall DllMain(فراغ *_HDllHandle,بنانشانی _Reason,فراغ *_Reserved);
  صحيح __stdcall _CRT_INIT(فراغ *_HDllHandle,بنانشانی _Reason,فراغ *_Reserved);
  صحيح __stdcall _wCRT_INIT(فراغ *_HDllHandle,بنانشانی _Reason,فراغ *_Reserved);
  خارجي صحيح (__stdcall *ثابت _pRawDllMain)(فراغ *,بنانشانی,فراغ *);
#جے_انت
#جے_انت

#جے_بنا_تعریف	NO_OLDNAMES
#تعریف_کرو P_WAIT _P_WAIT
#تعریف_کرو P_NOWAIT _P_NOWAIT
#تعریف_کرو P_OVERLAY _P_OVERLAY
#تعریف_کرو OLD_P_OVERLAY _OLD_P_OVERLAY
#تعریف_کرو P_NOWAITO _P_NOWAITO
#تعریف_کرو P_DETACH _P_DETACH
#تعریف_کرو WAIT_بچہ WAIT_بچہ_2
#تعریف_کرو WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(صحيح *رکن_Stat,intptr_t _ProcHandle,صحيح _Action);
#جے_تعریف_شدہ __GNUC__
  صحيح __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#وإلا
    intptr_t __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#جے_انت
  intptr_t __cdecl spawnl(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnle(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlp(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlpe(صحيح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحيح __cdecl getpid(فراغ);
#جے_تعریف_شدہ __GNUC__
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
#جے_انت
  intptr_t __cdecl spawnv(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnve(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
  intptr_t __cdecl spawnvp(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnvpe(صحيح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],حرف *ثابت _Env[]);
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
#جے_انت
