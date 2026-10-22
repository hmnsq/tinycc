/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _INC_PROCESS
#تعریف_کرو _INC_PROCESS

#شامل <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#شامل <sys/types.h>

#اگر_غیر_تعریف_شدہ _POSIX_
#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#تعریف_کرو _P_WAIT 0
#تعریف_کرو _P_NOWAIT 1
#تعریف_کرو _OLD_P_OVERLAY 2
#تعریف_کرو _P_NOWAITO 3
#تعریف_کرو _P_DETACH 4
#تعریف_کرو _P_OVERLAY 2

#تعریف_کرو WAIT_بچہ_2 0
#تعریف_کرو _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(خالی (__cdecl *آغاز_پتہ) (خالی *),غیرعلامتی ڈھیر_سائز_2,خالی *_ArgList);
  _CRTIMP خالی __cdecl _endthread(خالی);
  _CRTIMP uintptr_t __cdecl _beginthreadex(خالی *_Security,غیرعلامتی ڈھیر_سائز_2,غیرعلامتی (__stdcall *آغاز_پتہ) (خالی *),خالی *_ArgList,غیرعلامتی _InitFlag,غیرعلامتی *_ThrdAddr);
  _CRTIMP خالی __cdecl _endthreadex(غیرعلامتی _Retval);

#اگر_غیر_تعریف_شدہ _CRT_TERMINATE_DEFINED
#تعریف_کرو _CRT_TERMINATE_DEFINED
  خالی __cdecl __MINGW_NOTHROW باہر_نکلو(صحیح رمز_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP خالی __cdecl __MINGW_NOTHROW _exit(صحیح رمز_3) __MINGW_ATTRIB_NORETURN;

#ہدایت ڈالو_macro("abort")
#تعریف_منسوخ abort
  خالی __cdecl __declspec(noreturn) abort(خالی);
#ہدایت نکالو_macro("abort")

#اگر_ختم

  _CRTIMP خالی __cdecl __MINGW_NOTHROW _cexit(خالی);
  _CRTIMP خالی __cdecl __MINGW_NOTHROW _c_exit(خالی);
  _CRTIMP صحیح __cdecl _getpid(خالی);
  _CRTIMP intptr_t __cdecl _cwait(صحیح *رکن_Stat,intptr_t _ProcHandle,صحیح _Action);
  _CRTIMP intptr_t __cdecl _execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(صحیح منوال_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(صحیح منوال_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(صحیح منوال_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(صحیح منوال_3,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(صحیح منوال_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(صحیح منوال_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(صحیح منوال_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(صحیح منوال_3,ثابت حرف *_Filename,ثابت حرف *ثابت *_ArgList,ثابت حرف *ثابت *_Env);

#اگر_غیر_تعریف_شدہ _CRT_SYSTEM_DEFINED
#تعریف_کرو _CRT_SYSTEM_DEFINED
  صحیح __cdecl system(ثابت حرف *_Command);
#اگر_ختم

#اگر_غیر_تعریف_شدہ _WPROCESS_DEFINED
#تعریف_کرو _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(صحیح منوال_3,ثابت wchar_t *_Filename,ثابت wchar_t *ثابت *_ArgList,ثابت wchar_t *ثابت *_Env);
#اگر_غیر_تعریف_شدہ _CRT_WSYSTEM_DEFINED
#تعریف_کرو _CRT_WSYSTEM_DEFINED
  _CRTIMP صحیح __cdecl _wsystem(ثابت wchar_t *_Command);
#اگر_ختم
#اگر_ختم

  خالی __cdecl __security_init_cookie(خالی);
#اگر (defined(_X86_) && !defined(__x86_64))
  خالی __fastcall __security_check_cookie(uintptr_t ڈھیر_Cookie);
  __declspec(noreturn) خالی __cdecl __report_gsfailure(خالی);
#ورنہ
  خالی __cdecl __security_check_cookie(uintptr_t ڈھیر_Cookie);
  __declspec(noreturn) خالی __cdecl __report_gsfailure(uintptr_t ڈھیر_Cookie);
#اگر_ختم
  خارجی uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(حرف *_Filename);
  صحیح __cdecl _unloaddll(intptr_t _Handle);
  صحیح (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,حرف *_ProcedureName,intptr_t _Ordinal))(خالی);

#اگر_تعریف_شدہ _DECL_DLLMAIN
#اگر_تعریف_شدہ _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  خارجی WINBOOL (WINAPI *ثابت _pRawDllMain)(HANDLE,DWORD,LPVOID);
#ورنہ
  صحیح __stdcall DllMain(خالی *_HDllHandle,غیرعلامتی _Reason,خالی *_Reserved);
  صحیح __stdcall _CRT_INIT(خالی *_HDllHandle,غیرعلامتی _Reason,خالی *_Reserved);
  صحیح __stdcall _wCRT_INIT(خالی *_HDllHandle,غیرعلامتی _Reason,خالی *_Reserved);
  خارجی صحیح (__stdcall *ثابت _pRawDllMain)(خالی *,غیرعلامتی,خالی *);
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ	NO_OLDNAMES
#تعریف_کرو P_WAIT _P_WAIT
#تعریف_کرو P_NOWAIT _P_NOWAIT
#تعریف_کرو P_OVERLAY _P_OVERLAY
#تعریف_کرو OLD_P_OVERLAY _OLD_P_OVERLAY
#تعریف_کرو P_NOWAITO _P_NOWAITO
#تعریف_کرو P_DETACH _P_DETACH
#تعریف_کرو WAIT_بچہ WAIT_بچہ_2
#تعریف_کرو WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(صحیح *رکن_Stat,intptr_t _ProcHandle,صحیح _Action);
#اگر_تعریف_شدہ __GNUC__
  صحیح __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحیح __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحیح __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحیح __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#ورنہ
    intptr_t __cdecl execl(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execle(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlp(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl execlpe(ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
#اگر_ختم
  intptr_t __cdecl spawnl(صحیح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnle(صحیح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlp(صحیح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  intptr_t __cdecl spawnlpe(صحیح,ثابت حرف *_Filename,ثابت حرف *_ArgList,...);
  صحیح __cdecl getpid(خالی);
#اگر_تعریف_شدہ __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  صحیح __cdecl execv(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  صحیح __cdecl execve(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
  صحیح __cdecl execvp(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  صحیح __cdecl execvpe(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
#ورنہ
  intptr_t __cdecl execv(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl execve(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
  intptr_t __cdecl execvp(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl execvpe(ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
#اگر_ختم
  intptr_t __cdecl spawnv(صحیح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnve(صحیح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],ثابت حرف *ثابت _Env[]);
  intptr_t __cdecl spawnvp(صحیح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[]);
  intptr_t __cdecl spawnvpe(صحیح,ثابت حرف *_Filename,ثابت حرف *ثابت _ArgList[],حرف *ثابت _Env[]);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
#اگر_ختم
