/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#அந்தர்பாவ <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#அந்தர்பாவ <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
வெளி "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(வெறுமை (__cdecl *_StartAddress) (வெறுமை *),unsigned அடுக்கு_Size,வெறுமை *_ArgList);
  _CRTIMP வெறுமை __cdecl _endthread(வெறுமை);
  _CRTIMP uintptr_t __cdecl _beginthreadex(வெறுமை *_Security,unsigned அடுக்கு_Size,unsigned (__stdcall *_StartAddress) (வெறுமை *),வெறுமை *_ArgList,unsigned _InitFlag,unsigned *_ThrdAddr);
  _CRTIMP வெறுமை __cdecl _endthreadex(unsigned _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  வெறுமை __cdecl __MINGW_NOTHROW exit(முழு _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP வெறுமை __cdecl __MINGW_NOTHROW _exit(முழு _Code) __MINGW_ATTRIB_NORETURN;

#pragma தள்ளு_macro("abort")
#undef abort
  வெறுமை __cdecl __declspec(noreturn) abort(வெறுமை);
#pragma எடு_macro("abort")

#endif

  _CRTIMP வெறுமை __cdecl __MINGW_NOTHROW _cexit(வெறுமை);
  _CRTIMP வெறுமை __cdecl __MINGW_NOTHROW _c_exit(வெறுமை);
  _CRTIMP முழு __cdecl _getpid(வெறுமை);
  _CRTIMP intptr_t __cdecl _cwait(முழு *_TermStat,intptr_t _ProcHandle,முழு _Action);
  _CRTIMP intptr_t __cdecl _execl(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி *_ArgList,மாறிலி எழுத்து *மாறிலி *_Env);
  _CRTIMP intptr_t __cdecl _execvp(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி *_ArgList,மாறிலி எழுத்து *மாறிலி *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(முழு _Mode,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(முழு _Mode,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(முழு _Mode,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(முழு _Mode,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(முழு _Mode,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(முழு _Mode,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி *_ArgList,மாறிலி எழுத்து *மாறிலி *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(முழு _Mode,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(முழு _Mode,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி *_ArgList,மாறிலி எழுத்து *மாறிலி *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  முழு __cdecl system(மாறிலி எழுத்து *_Command);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList,மாறிலி wchar_t *மாறிலி *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList,மாறிலி wchar_t *மாறிலி *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList,மாறிலி wchar_t *மாறிலி *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(முழு _Mode,மாறிலி wchar_t *_Filename,மாறிலி wchar_t *மாறிலி *_ArgList,மாறிலி wchar_t *மாறிலி *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP முழு __cdecl _wsystem(மாறிலி wchar_t *_Command);
#endif
#endif

  வெறுமை __cdecl __security_init_cookie(வெறுமை);
#எனில் (defined(_X86_) && !defined(__x86_64))
  வெறுமை __fastcall __security_check_cookie(uintptr_t அடுக்கு_Cookie);
  __declspec(noreturn) வெறுமை __cdecl __report_gsfailure(வெறுமை);
#இல்லையெனில்
  வெறுமை __cdecl __security_check_cookie(uintptr_t அடுக்கு_Cookie);
  __declspec(noreturn) வெறுமை __cdecl __report_gsfailure(uintptr_t அடுக்கு_Cookie);
#endif
  வெளி uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(எழுத்து *_Filename);
  முழு __cdecl _unloaddll(intptr_t _Handle);
  முழு (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,எழுத்து *_ProcedureName,intptr_t _Ordinal))(வெறுமை);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  வெளி WINBOOL (WINAPI *மாறிலி _pRawDllMain)(HANDLE,DWORD,LPVOID);
#இல்லையெனில்
  முழு __stdcall DllMain(வெறுமை *_HDllHandle,unsigned _Reason,வெறுமை *_Reserved);
  முழு __stdcall _CRT_INIT(வெறுமை *_HDllHandle,unsigned _Reason,வெறுமை *_Reserved);
  முழு __stdcall _wCRT_INIT(வெறுமை *_HDllHandle,unsigned _Reason,வெறுமை *_Reserved);
  வெளி முழு (__stdcall *மாறிலி _pRawDllMain)(வெறுமை *,unsigned,வெறுமை *);
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

  intptr_t __cdecl cwait(முழு *_TermStat,intptr_t _ProcHandle,முழு _Action);
#ifdef __GNUC__
  முழு __cdecl execl(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  முழு __cdecl execle(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  முழு __cdecl execlp(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  முழு __cdecl execlpe(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
#இல்லையெனில்
    intptr_t __cdecl execl(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  intptr_t __cdecl execle(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  intptr_t __cdecl execlp(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  intptr_t __cdecl execlpe(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(முழு,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  intptr_t __cdecl spawnle(முழு,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  intptr_t __cdecl spawnlp(முழு,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  intptr_t __cdecl spawnlpe(முழு,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *_ArgList,...);
  முழு __cdecl getpid(வெறுமை);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  முழு __cdecl execv(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[]);
  முழு __cdecl execve(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[],மாறிலி எழுத்து *மாறிலி _Env[]);
  முழு __cdecl execvp(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[]);
  முழு __cdecl execvpe(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[],மாறிலி எழுத்து *மாறிலி _Env[]);
#இல்லையெனில்
  intptr_t __cdecl execv(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[]);
  intptr_t __cdecl execve(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[],மாறிலி எழுத்து *மாறிலி _Env[]);
  intptr_t __cdecl execvp(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[]);
  intptr_t __cdecl execvpe(மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[],மாறிலி எழுத்து *மாறிலி _Env[]);
#endif
  intptr_t __cdecl spawnv(முழு,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[]);
  intptr_t __cdecl spawnve(முழு,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[],மாறிலி எழுத்து *மாறிலி _Env[]);
  intptr_t __cdecl spawnvp(முழு,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[]);
  intptr_t __cdecl spawnvpe(முழு,மாறிலி எழுத்து *_Filename,மாறிலி எழுத்து *மாறிலி _ArgList[],எழுத்து *மாறிலி _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
