/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#અન્તર્ભાવ <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#અન્તર્ભાવ <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
બાહ્ય "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(શૂન્ય (__cdecl *_StartAddress) (શૂન્ય *),unsigned ઢગલો_Size,શૂન્ય *_ArgList);
  _CRTIMP શૂન્ય __cdecl _endthread(શૂન્ય);
  _CRTIMP uintptr_t __cdecl _beginthreadex(શૂન્ય *_Security,unsigned ઢગલો_Size,unsigned (__stdcall *_StartAddress) (શૂન્ય *),શૂન્ય *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr);
  _CRTIMP શૂન્ય __cdecl _endthreadex(unsigned _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  શૂન્ય __cdecl __MINGW_NOTHROW exit(પૂર્ણાંક _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP શૂન્ય __cdecl __MINGW_NOTHROW _exit(પૂર્ણાંક _Code) __MINGW_ATTRIB_NORETURN;

#pragma ધકેલો_macro("abort")
#undef abort
  શૂન્ય __cdecl __declspec(noreturn) abort(શૂન્ય);
#pragma કાઢો_macro("abort")

#endif

  _CRTIMP શૂન્ય __cdecl __MINGW_NOTHROW _cexit(શૂન્ય);
  _CRTIMP શૂન્ય __cdecl __MINGW_NOTHROW _c_exit(શૂન્ય);
  _CRTIMP પૂર્ણાંક __cdecl _getpid(શૂન્ય);
  _CRTIMP intptr_t __cdecl _cwait(પૂર્ણાંક *_TermStat,intptr_t _ProcHandle,પૂર્ણાંક _Action);
  _CRTIMP intptr_t __cdecl _execl(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ *_ArgList,અચલ અક્ષર *અચલ *_Env);
  _CRTIMP intptr_t __cdecl _execvp(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ *_ArgList,અચલ અક્ષર *અચલ *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(પૂર્ણાંક _Mode,અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(પૂર્ણાંક _Mode,અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(પૂર્ણાંક _Mode,અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(પૂર્ણાંક _Mode,અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(પૂર્ણાંક _Mode,અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(પૂર્ણાંક _Mode,અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ *_ArgList,અચલ અક્ષર *અચલ *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(પૂર્ણાંક _Mode,અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(પૂર્ણાંક _Mode,અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ *_ArgList,અચલ અક્ષર *અચલ *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  પૂર્ણાંક __cdecl system(અચલ અક્ષર *_Command);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList,અચલ wchar_t *અચલ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList,અચલ wchar_t *અચલ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList,અચલ wchar_t *અચલ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(પૂર્ણાંક _Mode,અચલ wchar_t *_Filename,અચલ wchar_t *અચલ *_ArgList,અચલ wchar_t *અચલ *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP પૂર્ણાંક __cdecl _wsystem(અચલ wchar_t *_Command);
#endif
#endif

  શૂન્ય __cdecl __security_init_cookie(શૂન્ય);
#જો (defined(_X86_) && !defined(__x86_64))
  શૂન્ય __fastcall __security_check_cookie(uintptr_t ઢગલો_Cookie);
  __declspec(noreturn) શૂન્ય __cdecl __report_gsfailure(શૂન્ય);
#નહીંતર
  શૂન્ય __cdecl __security_check_cookie(uintptr_t ઢગલો_Cookie);
  __declspec(noreturn) શૂન્ય __cdecl __report_gsfailure(uintptr_t ઢગલો_Cookie);
#endif
  બાહ્ય uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(અક્ષર *_Filename);
  પૂર્ણાંક __cdecl _unloaddll(intptr_t _Handle);
  પૂર્ણાંક (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,અક્ષર *_ProcedureName,intptr_t _Ordinal))(શૂન્ય);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  બાહ્ય WINBOOL (WINAPI *અચલ _pRawDllMain)(HANDLE,DWORD,LPVOID);
#નહીંતર
  પૂર્ણાંક __stdcall DllMain(શૂન્ય *_HDllHandle,unsigned _Reason,શૂન્ય *_Reserved);
  પૂર્ણાંક __stdcall _CRT_INIT(શૂન્ય *_HDllHandle,unsigned _Reason,શૂન્ય *_Reserved);
  પૂર્ણાંક __stdcall _wCRT_INIT(શૂન્ય *_HDllHandle,unsigned _Reason,શૂન્ય *_Reserved);
  બાહ્ય પૂર્ણાંક (__stdcall *અચલ _pRawDllMain)(શૂન્ય *,unsigned,શૂન્ય *);
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

  intptr_t __cdecl cwait(પૂર્ણાંક *_TermStat,intptr_t _ProcHandle,પૂર્ણાંક _Action);
#ifdef __GNUC__
  પૂર્ણાંક __cdecl execl(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  પૂર્ણાંક __cdecl execle(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  પૂર્ણાંક __cdecl execlp(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  પૂર્ણાંક __cdecl execlpe(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
#નહીંતર
    intptr_t __cdecl execl(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  intptr_t __cdecl execle(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  intptr_t __cdecl execlp(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  intptr_t __cdecl execlpe(અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(પૂર્ણાંક,અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  intptr_t __cdecl spawnle(પૂર્ણાંક,અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  intptr_t __cdecl spawnlp(પૂર્ણાંક,અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  intptr_t __cdecl spawnlpe(પૂર્ણાંક,અચલ અક્ષર *_Filename,અચલ અક્ષર *_ArgList,...);
  પૂર્ણાંક __cdecl getpid(શૂન્ય);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  પૂર્ણાંક __cdecl execv(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[]);
  પૂર્ણાંક __cdecl execve(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[],અચલ અક્ષર *અચલ _Env[]);
  પૂર્ણાંક __cdecl execvp(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[]);
  પૂર્ણાંક __cdecl execvpe(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[],અચલ અક્ષર *અચલ _Env[]);
#નહીંતર
  intptr_t __cdecl execv(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[]);
  intptr_t __cdecl execve(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[],અચલ અક્ષર *અચલ _Env[]);
  intptr_t __cdecl execvp(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[]);
  intptr_t __cdecl execvpe(અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[],અચલ અક્ષર *અચલ _Env[]);
#endif
  intptr_t __cdecl spawnv(પૂર્ણાંક,અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[]);
  intptr_t __cdecl spawnve(પૂર્ણાંક,અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[],અચલ અક્ષર *અચલ _Env[]);
  intptr_t __cdecl spawnvp(પૂર્ણાંક,અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[]);
  intptr_t __cdecl spawnvpe(પૂર્ણાંક,અચલ અક્ષર *_Filename,અચલ અક્ષર *અચલ _ArgList[],અક્ષર *અચલ _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
