/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _INC_PROCESS
#परिभाषय _INC_PROCESS

#अन्तर्भाव <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#अन्तर्भाव <sys/types.h>

#यदि_अपरिभाषितम् _POSIX_
#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#परिभाषय _P_WAIT 0
#परिभाषय _P_NOWAIT 1
#परिभाषय _OLD_P_OVERLAY 2
#परिभाषय _P_NOWAITO 3
#परिभाषय _P_DETACH 4
#परिभाषय _P_OVERLAY 2

#परिभाषय _WAIT_CHILD 0
#परिभाषय _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(शून्य (__cdecl *Start_स्थानाङ्कः) (शून्य *),अचिह्नित राशिः_आकार_2,शून्य *_ArgList);
  _CRTIMP शून्य __cdecl _endthread(शून्य);
  _CRTIMP uintptr_t __cdecl _beginthreadex(शून्य *_Security,अचिह्नित राशिः_आकार_2,अचिह्नित (__stdcall *Start_स्थानाङ्कः) (शून्य *),शून्य *_ArgList,अचिह्नित _InitFlag,अचिह्नित *_ThrdAddr);
  _CRTIMP शून्य __cdecl _endthreadex(अचिह्नित _Retval);

#यदि_अपरिभाषितम् _CRT_TERMINATE_DEFINED
#परिभाषय _CRT_TERMINATE_DEFINED
  शून्य __cdecl __MINGW_NOTHROW निर्गच्छ(पूर्णाङ्क संहिता_3) __MINGW_ATTRIB_NORETURN;
  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _exit(पूर्णाङ्क संहिता_3) __MINGW_ATTRIB_NORETURN;

#निर्देशः प्रक्षिप_macro("abort")
#अपरिभाषय abort
  शून्य __cdecl __declspec(noreturn) abort(शून्य);
#निर्देशः निष्कासय_macro("abort")

#यदि_अन्तः

  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _cexit(शून्य);
  _CRTIMP शून्य __cdecl __MINGW_NOTHROW _c_exit(शून्य);
  _CRTIMP पूर्णाङ्क __cdecl _getpid(शून्य);
  _CRTIMP intptr_t __cdecl _cwait(पूर्णाङ्क *पदांशः_Stat,intptr_t _ProcHandle,पूर्णाङ्क _Action);
  _CRTIMP intptr_t __cdecl _execl(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव *_ArgList,ध्रुव वर्ण *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव *_ArgList,ध्रुव वर्ण *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(पूर्णाङ्क बहुलकम्_3,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(पूर्णाङ्क बहुलकम्_3,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(पूर्णाङ्क बहुलकम्_3,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(पूर्णाङ्क बहुलकम्_3,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(पूर्णाङ्क बहुलकम्_3,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(पूर्णाङ्क बहुलकम्_3,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव *_ArgList,ध्रुव वर्ण *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(पूर्णाङ्क बहुलकम्_3,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(पूर्णाङ्क बहुलकम्_3,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव *_ArgList,ध्रुव वर्ण *ध्रुव *_Env);

#यदि_अपरिभाषितम् _CRT_SYSTEM_DEFINED
#परिभाषय _CRT_SYSTEM_DEFINED
  पूर्णाङ्क __cdecl system(ध्रुव वर्ण *_Command);
#यदि_अन्तः

#यदि_अपरिभाषितम् _WPROCESS_DEFINED
#परिभाषय _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(पूर्णाङ्क बहुलकम्_3,ध्रुव wchar_t *_Filename,ध्रुव wchar_t *ध्रुव *_ArgList,ध्रुव wchar_t *ध्रुव *_Env);
#यदि_अपरिभाषितम् _CRT_WSYSTEM_DEFINED
#परिभाषय _CRT_WSYSTEM_DEFINED
  _CRTIMP पूर्णाङ्क __cdecl _wsystem(ध्रुव wchar_t *_Command);
#यदि_अन्तः
#यदि_अन्तः

  शून्य __cdecl __security_init_cookie(शून्य);
#यदि (defined(_X86_) && !defined(__x86_64))
  शून्य __fastcall __security_check_cookie(uintptr_t राशिः_Cookie);
  __declspec(noreturn) शून्य __cdecl __report_gsfailure(शून्य);
#अन्यथा
  शून्य __cdecl __security_check_cookie(uintptr_t राशिः_Cookie);
  __declspec(noreturn) शून्य __cdecl __report_gsfailure(uintptr_t राशिः_Cookie);
#यदि_अन्तः
  बाह्य uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(वर्ण *_Filename);
  पूर्णाङ्क __cdecl _unloaddll(intptr_t _Handle);
  पूर्णाङ्क (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,वर्ण *_ProcedureName,intptr_t _Ordinal))(शून्य);

#यदि_परिभाषितम् _DECL_DLLMAIN
#यदि_परिभाषितम् _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  बाह्य WINBOOL (WINAPI *ध्रुव _pRawDllMain)(HANDLE,DWORD,LPVOID);
#अन्यथा
  पूर्णाङ्क __stdcall DllMain(शून्य *_HDllHandle,अचिह्नित _Reason,शून्य *_Reserved);
  पूर्णाङ्क __stdcall _CRT_INIT(शून्य *_HDllHandle,अचिह्नित _Reason,शून्य *_Reserved);
  पूर्णाङ्क __stdcall _wCRT_INIT(शून्य *_HDllHandle,अचिह्नित _Reason,शून्य *_Reserved);
  बाह्य पूर्णाङ्क (__stdcall *ध्रुव _pRawDllMain)(शून्य *,अचिह्नित,शून्य *);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम्	NO_OLDNAMES
#परिभाषय P_WAIT _P_WAIT
#परिभाषय P_NOWAIT _P_NOWAIT
#परिभाषय P_OVERLAY _P_OVERLAY
#परिभाषय OLD_P_OVERLAY _OLD_P_OVERLAY
#परिभाषय P_NOWAITO _P_NOWAITO
#परिभाषय P_DETACH _P_DETACH
#परिभाषय WAIT_CHILD _WAIT_CHILD
#परिभाषय WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(पूर्णाङ्क *पदांशः_Stat,intptr_t _ProcHandle,पूर्णाङ्क _Action);
#यदि_परिभाषितम् __GNUC__
  पूर्णाङ्क __cdecl execl(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  पूर्णाङ्क __cdecl execle(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  पूर्णाङ्क __cdecl execlp(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  पूर्णाङ्क __cdecl execlpe(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
#अन्यथा
    intptr_t __cdecl execl(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  intptr_t __cdecl execle(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  intptr_t __cdecl execlp(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  intptr_t __cdecl execlpe(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
#यदि_अन्तः
  intptr_t __cdecl spawnl(पूर्णाङ्क,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  intptr_t __cdecl spawnle(पूर्णाङ्क,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  intptr_t __cdecl spawnlp(पूर्णाङ्क,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  intptr_t __cdecl spawnlpe(पूर्णाङ्क,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *_ArgList,...);
  पूर्णाङ्क __cdecl getpid(शून्य);
#यदि_परिभाषितम् __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  पूर्णाङ्क __cdecl execv(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[]);
  पूर्णाङ्क __cdecl execve(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[],ध्रुव वर्ण *ध्रुव _Env[]);
  पूर्णाङ्क __cdecl execvp(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[]);
  पूर्णाङ्क __cdecl execvpe(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[],ध्रुव वर्ण *ध्रुव _Env[]);
#अन्यथा
  intptr_t __cdecl execv(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[]);
  intptr_t __cdecl execve(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[],ध्रुव वर्ण *ध्रुव _Env[]);
  intptr_t __cdecl execvp(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[]);
  intptr_t __cdecl execvpe(ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[],ध्रुव वर्ण *ध्रुव _Env[]);
#यदि_अन्तः
  intptr_t __cdecl spawnv(पूर्णाङ्क,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[]);
  intptr_t __cdecl spawnve(पूर्णाङ्क,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[],ध्रुव वर्ण *ध्रुव _Env[]);
  intptr_t __cdecl spawnvp(पूर्णाङ्क,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[]);
  intptr_t __cdecl spawnvpe(पूर्णाङ्क,ध्रुव वर्ण *_Filename,ध्रुव वर्ण *ध्रुव _ArgList[],वर्ण *ध्रुव _Env[]);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः
