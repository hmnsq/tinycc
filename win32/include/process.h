/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _INC_PROCESS
#నిర్వచించు _INC_PROCESS

#అన్తర్భావ <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#అన్తర్భావ <sys/types.h>

#నిర్వచితం_కాకపోతే _POSIX_
#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచించు _P_WAIT 0
#నిర్వచించు _P_NOWAIT 1
#నిర్వచించు _OLD_P_OVERLAY 2
#నిర్వచించు _P_NOWAITO 3
#నిర్వచించు _P_DETACH 4
#నిర్వచించు _P_OVERLAY 2

#నిర్వచించు WAIT_బిడ్డ_2 0
#నిర్వచించు _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(శూన్య (__cdecl *ప్రారంభం_చిరునామా) (శూన్య *),గుర్తులేని దొంతర_కొలత_2,శూన్య *_ArgList);
  _CRTIMP శూన్య __cdecl _endthread(శూన్య);
  _CRTIMP uintptr_t __cdecl _beginthreadex(శూన్య *_Security,గుర్తులేని దొంతర_కొలత_2,గుర్తులేని (__stdcall *ప్రారంభం_చిరునామా) (శూన్య *),శూన్య *_ArgList,గుర్తులేని _InitFlag,గుర్తులేని *_ThrdAddr);
  _CRTIMP శూన్య __cdecl _endthreadex(గుర్తులేని _Retval);

#నిర్వచితం_కాకపోతే _CRT_TERMINATE_DEFINED
#నిర్వచించు _CRT_TERMINATE_DEFINED
  శూన్య __cdecl __MINGW_NOTHROW నిష్క్రమించు(పూర్ణాంకం సంకేతం_4) __MINGW_ATTRIB_NORETURN;
  _CRTIMP శూన్య __cdecl __MINGW_NOTHROW _exit(పూర్ణాంకం సంకేతం_4) __MINGW_ATTRIB_NORETURN;

#సూచన నెట్టు_macro("abort")
#నిర్వచనం_రద్దు abort
  శూన్య __cdecl __declspec(noreturn) abort(శూన్య);
#సూచన తీయి_macro("abort")

#అయితే_ముగింపు

  _CRTIMP శూన్య __cdecl __MINGW_NOTHROW _cexit(శూన్య);
  _CRTIMP శూన్య __cdecl __MINGW_NOTHROW _c_exit(శూన్య);
  _CRTIMP పూర్ణాంకం __cdecl _getpid(శూన్య);
  _CRTIMP intptr_t __cdecl _cwait(పూర్ణాంకం *పదం_Stat,intptr_t _ProcHandle,పూర్ణాంకం _Action);
  _CRTIMP intptr_t __cdecl _execl(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి *_ArgList,స్థిరరాశి అక్షరం *స్థిరరాశి *_Env);
  _CRTIMP intptr_t __cdecl _execvp(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి *_ArgList,స్థిరరాశి అక్షరం *స్థిరరాశి *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(పూర్ణాంకం బహుళకం_3,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(పూర్ణాంకం బహుళకం_3,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(పూర్ణాంకం బహుళకం_3,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(పూర్ణాంకం బహుళకం_3,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(పూర్ణాంకం బహుళకం_3,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(పూర్ణాంకం బహుళకం_3,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి *_ArgList,స్థిరరాశి అక్షరం *స్థిరరాశి *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(పూర్ణాంకం బహుళకం_3,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(పూర్ణాంకం బహుళకం_3,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి *_ArgList,స్థిరరాశి అక్షరం *స్థిరరాశి *_Env);

#నిర్వచితం_కాకపోతే _CRT_SYSTEM_DEFINED
#నిర్వచించు _CRT_SYSTEM_DEFINED
  పూర్ణాంకం __cdecl system(స్థిరరాశి అక్షరం *_Command);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _WPROCESS_DEFINED
#నిర్వచించు _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList,స్థిరరాశి wchar_t *స్థిరరాశి *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList,స్థిరరాశి wchar_t *స్థిరరాశి *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList,స్థిరరాశి wchar_t *స్థిరరాశి *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(పూర్ణాంకం బహుళకం_3,స్థిరరాశి wchar_t *_Filename,స్థిరరాశి wchar_t *స్థిరరాశి *_ArgList,స్థిరరాశి wchar_t *స్థిరరాశి *_Env);
#నిర్వచితం_కాకపోతే _CRT_WSYSTEM_DEFINED
#నిర్వచించు _CRT_WSYSTEM_DEFINED
  _CRTIMP పూర్ణాంకం __cdecl _wsystem(స్థిరరాశి wchar_t *_Command);
#అయితే_ముగింపు
#అయితే_ముగింపు

  శూన్య __cdecl __security_init_cookie(శూన్య);
#ఒకవేళ (defined(_X86_) && !defined(__x86_64))
  శూన్య __fastcall __security_check_cookie(uintptr_t దొంతర_Cookie);
  __declspec(noreturn) శూన్య __cdecl __report_gsfailure(శూన్య);
#లేకపోతే
  శూన్య __cdecl __security_check_cookie(uintptr_t దొంతర_Cookie);
  __declspec(noreturn) శూన్య __cdecl __report_gsfailure(uintptr_t దొంతర_Cookie);
#అయితే_ముగింపు
  బాహ్య uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(అక్షరం *_Filename);
  పూర్ణాంకం __cdecl _unloaddll(intptr_t _Handle);
  పూర్ణాంకం (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,అక్షరం *_ProcedureName,intptr_t _Ordinal))(శూన్య);

#నిర్వచితమైతే _DECL_DLLMAIN
#నిర్వచితమైతే _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  బాహ్య WINBOOL (WINAPI *స్థిరరాశి _pRawDllMain)(HANDLE,DWORD,LPVOID);
#లేకపోతే
  పూర్ణాంకం __stdcall DllMain(శూన్య *_HDllHandle,గుర్తులేని _Reason,శూన్య *_Reserved);
  పూర్ణాంకం __stdcall _CRT_INIT(శూన్య *_HDllHandle,గుర్తులేని _Reason,శూన్య *_Reserved);
  పూర్ణాంకం __stdcall _wCRT_INIT(శూన్య *_HDllHandle,గుర్తులేని _Reason,శూన్య *_Reserved);
  బాహ్య పూర్ణాంకం (__stdcall *స్థిరరాశి _pRawDllMain)(శూన్య *,గుర్తులేని,శూన్య *);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే	NO_OLDNAMES
#నిర్వచించు P_WAIT _P_WAIT
#నిర్వచించు P_NOWAIT _P_NOWAIT
#నిర్వచించు P_OVERLAY _P_OVERLAY
#నిర్వచించు OLD_P_OVERLAY _OLD_P_OVERLAY
#నిర్వచించు P_NOWAITO _P_NOWAITO
#నిర్వచించు P_DETACH _P_DETACH
#నిర్వచించు WAIT_బిడ్డ WAIT_బిడ్డ_2
#నిర్వచించు WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(పూర్ణాంకం *పదం_Stat,intptr_t _ProcHandle,పూర్ణాంకం _Action);
#నిర్వచితమైతే __GNUC__
  పూర్ణాంకం __cdecl execl(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  పూర్ణాంకం __cdecl execle(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  పూర్ణాంకం __cdecl execlp(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  పూర్ణాంకం __cdecl execlpe(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
#లేకపోతే
    intptr_t __cdecl execl(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  intptr_t __cdecl execle(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  intptr_t __cdecl execlp(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  intptr_t __cdecl execlpe(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
#అయితే_ముగింపు
  intptr_t __cdecl spawnl(పూర్ణాంకం,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  intptr_t __cdecl spawnle(పూర్ణాంకం,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  intptr_t __cdecl spawnlp(పూర్ణాంకం,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  intptr_t __cdecl spawnlpe(పూర్ణాంకం,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *_ArgList,...);
  పూర్ణాంకం __cdecl getpid(శూన్య);
#నిర్వచితమైతే __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  పూర్ణాంకం __cdecl execv(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[]);
  పూర్ణాంకం __cdecl execve(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[],స్థిరరాశి అక్షరం *స్థిరరాశి _Env[]);
  పూర్ణాంకం __cdecl execvp(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[]);
  పూర్ణాంకం __cdecl execvpe(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[],స్థిరరాశి అక్షరం *స్థిరరాశి _Env[]);
#లేకపోతే
  intptr_t __cdecl execv(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[]);
  intptr_t __cdecl execve(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[],స్థిరరాశి అక్షరం *స్థిరరాశి _Env[]);
  intptr_t __cdecl execvp(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[]);
  intptr_t __cdecl execvpe(స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[],స్థిరరాశి అక్షరం *స్థిరరాశి _Env[]);
#అయితే_ముగింపు
  intptr_t __cdecl spawnv(పూర్ణాంకం,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[]);
  intptr_t __cdecl spawnve(పూర్ణాంకం,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[],స్థిరరాశి అక్షరం *స్థిరరాశి _Env[]);
  intptr_t __cdecl spawnvp(పూర్ణాంకం,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[]);
  intptr_t __cdecl spawnvpe(పూర్ణాంకం,స్థిరరాశి అక్షరం *_Filename,స్థిరరాశి అక్షరం *స్థిరరాశి _ArgList[],అక్షరం *స్థిరరాశి _Env[]);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు
