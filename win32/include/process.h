/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_PROCESS
#define _INC_PROCESS

#अन्तर्भाव <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#अन्तर्भाव <sys/types.h>

#ifndef _POSIX_
#ifdef __cplusplus
बाह्य "C" {
#endif

#define _P_WAIT 0
#define _P_NOWAIT 1
#define _OLD_P_OVERLAY 2
#define _P_NOWAITO 3
#define _P_DETACH 4
#define _P_OVERLAY 2

#define _WAIT_CHILD 0
#define _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(शून्य (__cdecl *_StartAddress) (शून्य *),अचिन्हित चळत_Size,शून्य *_ArgList);
  _CRTIMP शून्य __cdecl _endthread(शून्य);
  _CRTIMP uintptr_t __cdecl _beginthreadex(शून्य *_Security,अचिन्हित चळत_Size,अचिन्हित (__stdcall *_StartAddress) (शून्य *),शून्य *_ArgList,अचिन्हित _InitFlag,अचिन्हित *_ThrdAddr);
  _CRTIMP शून्य __cdecl _endthreadex(अचिन्हित _Retval);

#ifndef _CRT_TERMINATE_DEFINED
#define _CRT_TERMINATE_DEFINED
  शून्य __cdecl __MINGW_NOTHROW निकास(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _exit(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;

#pragma ढकला_macro("abort")
#undef पात
  शून्य __cdecl __declspec(noreturn) पात(शून्य);
#pragma काढा_macro("abort")

#endif

  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _cexit(शून्य);
  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _c_exit(शून्य);
  _CRTIMP पूर्णांक __cdecl _getpid(शून्य);
  _CRTIMP intptr_t __cdecl _cwait(पूर्णांक *_TermStat,intptr_t _ProcHandle,पूर्णांक _Action);
  _CRTIMP intptr_t __cdecl _execl(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक *_ArgList,स्थिरांक अक्षर *स्थिरांक *_Env);
  _CRTIMP intptr_t __cdecl _execvp(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक *_ArgList,स्थिरांक अक्षर *स्थिरांक *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(पूर्णांक _Mode,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(पूर्णांक _Mode,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(पूर्णांक _Mode,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(पूर्णांक _Mode,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(पूर्णांक _Mode,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(पूर्णांक _Mode,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक *_ArgList,स्थिरांक अक्षर *स्थिरांक *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(पूर्णांक _Mode,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(पूर्णांक _Mode,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक *_ArgList,स्थिरांक अक्षर *स्थिरांक *_Env);

#ifndef _CRT_SYSTEM_DEFINED
#define _CRT_SYSTEM_DEFINED
  पूर्णांक __cdecl प्रणाली(स्थिरांक अक्षर *_Command);
#endif

#ifndef _WPROCESS_DEFINED
#define _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_ArgList,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_ArgList,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(पूर्णांक _Mode,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(पूर्णांक _Mode,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(पूर्णांक _Mode,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(पूर्णांक _Mode,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(पूर्णांक _Mode,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(पूर्णांक _Mode,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_ArgList,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(पूर्णांक _Mode,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(पूर्णांक _Mode,स्थिरांक ब_अक्षर_प्रकार *_Filename,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_ArgList,स्थिरांक ब_अक्षर_प्रकार *स्थिरांक *_Env);
#ifndef _CRT_WSYSTEM_DEFINED
#define _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णांक __cdecl _wsystem(स्थिरांक ब_अक्षर_प्रकार *_Command);
#endif
#endif

  शून्य __cdecl __security_init_cookie(शून्य);
#जर (defined(_X86_) && !defined(__x86_64))
  शून्य __fastcall __security_check_cookie(uintptr_t चळत_Cookie);
  __declspec(noreturn) शून्य __cdecl __report_gsfailure(शून्य);
#अन्यथा
  शून्य __cdecl __security_check_cookie(uintptr_t चळत_Cookie);
  __declspec(noreturn) शून्य __cdecl __report_gsfailure(uintptr_t चळत_Cookie);
#endif
  बाह्य uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(अक्षर *_Filename);
  पूर्णांक __cdecl _unloaddll(intptr_t _Handle);
  पूर्णांक (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,अक्षर *_ProcedureName,intptr_t _Ordinal))(शून्य);

#ifdef _DECL_DLLMAIN
#ifdef _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  बाह्य WINBOOL (WINAPI *स्थिरांक _pRawDllMain)(HANDLE,DWORD,LPVOID);
#अन्यथा
  पूर्णांक __stdcall DllMain(शून्य *_HDllHandle,अचिन्हित _Reason,शून्य *_Reserved);
  पूर्णांक __stdcall _CRT_INIT(शून्य *_HDllHandle,अचिन्हित _Reason,शून्य *_Reserved);
  पूर्णांक __stdcall _wCRT_INIT(शून्य *_HDllHandle,अचिन्हित _Reason,शून्य *_Reserved);
  बाह्य पूर्णांक (__stdcall *स्थिरांक _pRawDllMain)(शून्य *,अचिन्हित,शून्य *);
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

  intptr_t __cdecl cwait(पूर्णांक *_TermStat,intptr_t _ProcHandle,पूर्णांक _Action);
#ifdef __GNUC__
  पूर्णांक __cdecl execl(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  पूर्णांक __cdecl execle(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  पूर्णांक __cdecl execlp(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  पूर्णांक __cdecl execlpe(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
#अन्यथा
    intptr_t __cdecl execl(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  intptr_t __cdecl execle(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  intptr_t __cdecl execlp(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  intptr_t __cdecl execlpe(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
#endif
  intptr_t __cdecl spawnl(पूर्णांक,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  intptr_t __cdecl spawnle(पूर्णांक,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  intptr_t __cdecl spawnlp(पूर्णांक,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  intptr_t __cdecl spawnlpe(पूर्णांक,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *_ArgList,...);
  पूर्णांक __cdecl getpid(शून्य);
#ifdef __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  पूर्णांक __cdecl execv(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[]);
  पूर्णांक __cdecl execve(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[],स्थिरांक अक्षर *स्थिरांक _Env[]);
  पूर्णांक __cdecl execvp(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[]);
  पूर्णांक __cdecl execvpe(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[],स्थिरांक अक्षर *स्थिरांक _Env[]);
#अन्यथा
  intptr_t __cdecl execv(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[]);
  intptr_t __cdecl execve(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[],स्थिरांक अक्षर *स्थिरांक _Env[]);
  intptr_t __cdecl execvp(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[]);
  intptr_t __cdecl execvpe(स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[],स्थिरांक अक्षर *स्थिरांक _Env[]);
#endif
  intptr_t __cdecl spawnv(पूर्णांक,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[]);
  intptr_t __cdecl spawnve(पूर्णांक,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[],स्थिरांक अक्षर *स्थिरांक _Env[]);
  intptr_t __cdecl spawnvp(पूर्णांक,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[]);
  intptr_t __cdecl spawnvpe(पूर्णांक,स्थिरांक अक्षर *_Filename,स्थिरांक अक्षर *स्थिरांक _ArgList[],अक्षर *स्थिरांक _Env[]);
#endif

#ifdef __cplusplus
}
#endif
#endif
#endif
