/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_PROCESS
#घोषणा _INC_PROCESS

#समावेश <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#समावेश <sys/types.h>

#अगर_अघोषित _POSIX_
#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#घोषणा _P_WAIT 0
#घोषणा _P_NOWAIT 1
#घोषणा _OLD_P_OVERLAY 2
#घोषणा _P_NOWAITO 3
#घोषणा _P_DETACH 4
#घोषणा _P_OVERLAY 2

#घोषणा _WAIT_CHILD 0
#घोषणा _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(व्योम (__cdecl *_StartAddress) (व्योम *),अचिन्हित ढेर_आकार_2,व्योम *_ArgList);
  _CRTIMP व्योम __cdecl _endthread(व्योम);
  _CRTIMP uintptr_t __cdecl _beginthreadex(व्योम *_Security,अचिन्हित ढेर_आकार_2,अचिन्हित (__stdcall *_StartAddress) (व्योम *),व्योम *_ArgList,अचिन्हित _InitFlag,अचिन्हित *_ThrdAddr);
  _CRTIMP व्योम __cdecl _endthreadex(अचिन्हित _Retval);

#अगर_अघोषित _CRT_TERMINATE_DEFINED
#घोषणा _CRT_TERMINATE_DEFINED
  व्योम __cdecl __MINGW_NOTHROW निकास(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP व्योम __cdecl __MINGW_NOTHROW _निकास(पूर्णांक _Code) __MINGW_ATTRIB_NORETURN;

#आशय धकेलो_macro("abort")
#अघोषित पात
  व्योम __cdecl __declspec(noreturn) पात(व्योम);
#आशय निकालो_macro("abort")

#पूर्ण_अगर

  _CRTIMP व्योम __cdecl __MINGW_NOTHROW _cexit(व्योम);
  _CRTIMP व्योम __cdecl __MINGW_NOTHROW _c_exit(व्योम);
  _CRTIMP पूर्णांक __cdecl _getpid(व्योम);
  _CRTIMP intptr_t __cdecl _cwait(पूर्णांक *_TermStat,intptr_t _ProcHandle,पूर्णांक _Action);
  _CRTIMP intptr_t __cdecl _execl(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर *_ArgList,स्थिर अक्षर *स्थिर *_Env);
  _CRTIMP intptr_t __cdecl _execvp(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर *_ArgList,स्थिर अक्षर *स्थिर *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(पूर्णांक _Mode,स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(पूर्णांक _Mode,स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(पूर्णांक _Mode,स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(पूर्णांक _Mode,स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(पूर्णांक _Mode,स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(पूर्णांक _Mode,स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर *_ArgList,स्थिर अक्षर *स्थिर *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(पूर्णांक _Mode,स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(पूर्णांक _Mode,स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर *_ArgList,स्थिर अक्षर *स्थिर *_Env);

#अगर_अघोषित _CRT_SYSTEM_DEFINED
#घोषणा _CRT_SYSTEM_DEFINED
  पूर्णांक __cdecl प्रणाली(स्थिर अक्षर *_Command);
#पूर्ण_अगर

#अगर_अघोषित _WPROCESS_DEFINED
#घोषणा _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList,स्थिर ब_अक्षर_प्रकार *स्थिर *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList,स्थिर ब_अक्षर_प्रकार *स्थिर *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList,स्थिर ब_अक्षर_प्रकार *स्थिर *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(पूर्णांक _Mode,स्थिर ब_अक्षर_प्रकार *_Filename,स्थिर ब_अक्षर_प्रकार *स्थिर *_ArgList,स्थिर ब_अक्षर_प्रकार *स्थिर *_Env);
#अगर_अघोषित _CRT_WSYSTEM_DEFINED
#घोषणा _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णांक __cdecl _wsystem(स्थिर ब_अक्षर_प्रकार *_Command);
#पूर्ण_अगर
#पूर्ण_अगर

  व्योम __cdecl __security_init_cookie(व्योम);
#अगर (defined(_X86_) && !defined(__x86_64))
  व्योम __fastcall __security_check_cookie(uintptr_t ढेर_Cookie);
  __declspec(noreturn) व्योम __cdecl __report_gsfailure(व्योम);
#अन्यथा
  व्योम __cdecl __security_check_cookie(uintptr_t ढेर_Cookie);
  __declspec(noreturn) व्योम __cdecl __report_gsfailure(uintptr_t ढेर_Cookie);
#पूर्ण_अगर
  बाह्य uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(अक्षर *_Filename);
  पूर्णांक __cdecl _unloaddll(intptr_t _Handle);
  पूर्णांक (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,अक्षर *_ProcedureName,intptr_t _Ordinal))(व्योम);

#अगर_घोषित _DECL_DLLMAIN
#अगर_घोषित _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  बाह्य WINBOOL (WINAPI *स्थिर _pRawDllMain)(HANDLE,DWORD,LPVOID);
#अन्यथा
  पूर्णांक __stdcall DllMain(व्योम *_HDllHandle,अचिन्हित _Reason,व्योम *_Reserved);
  पूर्णांक __stdcall _CRT_INIT(व्योम *_HDllHandle,अचिन्हित _Reason,व्योम *_Reserved);
  पूर्णांक __stdcall _wCRT_INIT(व्योम *_HDllHandle,अचिन्हित _Reason,व्योम *_Reserved);
  बाह्य पूर्णांक (__stdcall *स्थिर _pRawDllMain)(व्योम *,अचिन्हित,व्योम *);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित	NO_OLDNAMES
#घोषणा P_WAIT _P_WAIT
#घोषणा P_NOWAIT _P_NOWAIT
#घोषणा P_OVERLAY _P_OVERLAY
#घोषणा OLD_P_OVERLAY _OLD_P_OVERLAY
#घोषणा P_NOWAITO _P_NOWAITO
#घोषणा P_DETACH _P_DETACH
#घोषणा WAIT_CHILD _WAIT_CHILD
#घोषणा WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(पूर्णांक *_TermStat,intptr_t _ProcHandle,पूर्णांक _Action);
#अगर_घोषित __GNUC__
  पूर्णांक __cdecl execl(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  पूर्णांक __cdecl execle(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  पूर्णांक __cdecl execlp(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  पूर्णांक __cdecl execlpe(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
#अन्यथा
    intptr_t __cdecl execl(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  intptr_t __cdecl execle(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  intptr_t __cdecl execlp(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  intptr_t __cdecl execlpe(स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
#पूर्ण_अगर
  intptr_t __cdecl spawnl(पूर्णांक,स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  intptr_t __cdecl spawnle(पूर्णांक,स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  intptr_t __cdecl spawnlp(पूर्णांक,स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  intptr_t __cdecl spawnlpe(पूर्णांक,स्थिर अक्षर *_Filename,स्थिर अक्षर *_ArgList,...);
  पूर्णांक __cdecl getpid(व्योम);
#अगर_घोषित __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  पूर्णांक __cdecl execv(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[]);
  पूर्णांक __cdecl execve(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[],स्थिर अक्षर *स्थिर _Env[]);
  पूर्णांक __cdecl execvp(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[]);
  पूर्णांक __cdecl execvpe(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[],स्थिर अक्षर *स्थिर _Env[]);
#अन्यथा
  intptr_t __cdecl execv(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[]);
  intptr_t __cdecl execve(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[],स्थिर अक्षर *स्थिर _Env[]);
  intptr_t __cdecl execvp(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[]);
  intptr_t __cdecl execvpe(स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[],स्थिर अक्षर *स्थिर _Env[]);
#पूर्ण_अगर
  intptr_t __cdecl spawnv(पूर्णांक,स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[]);
  intptr_t __cdecl spawnve(पूर्णांक,स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[],स्थिर अक्षर *स्थिर _Env[]);
  intptr_t __cdecl spawnvp(पूर्णांक,स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[]);
  intptr_t __cdecl spawnvpe(पूर्णांक,स्थिर अक्षर *_Filename,स्थिर अक्षर *स्थिर _ArgList[],अक्षर *स्थिर _Env[]);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर
