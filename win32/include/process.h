/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _INC_PROCESS
#ವ್ಯಾಖ್ಯಾನಿಸು _INC_PROCESS

#ಅನ್ತರ್ಭಾವ <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#ಅನ್ತರ್ಭಾವ <sys/types.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _POSIX_
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು _P_WAIT 0
#ವ್ಯಾಖ್ಯಾನಿಸು _P_NOWAIT 1
#ವ್ಯಾಖ್ಯಾನಿಸು _OLD_P_OVERLAY 2
#ವ್ಯಾಖ್ಯಾನಿಸು _P_NOWAITO 3
#ವ್ಯಾಖ್ಯಾನಿಸು _P_DETACH 4
#ವ್ಯಾಖ್ಯಾನಿಸು _P_OVERLAY 2

#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_ಮಗು_2 0
#ವ್ಯಾಖ್ಯಾನಿಸು _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(ಶೂನ್ಯ (__cdecl *ಆರಂಭ_ವಿಳಾಸ) (ಶೂನ್ಯ *),ಚಿಹ್ನೆರಹಿತ ರಾಶಿ_ಗಾತ್ರ_2,ಶೂನ್ಯ *_ArgList);
  _CRTIMP ಶೂನ್ಯ __cdecl _endthread(ಶೂನ್ಯ);
  _CRTIMP uintptr_t __cdecl _beginthreadex(ಶೂನ್ಯ *_Security,ಚಿಹ್ನೆರಹಿತ ರಾಶಿ_ಗಾತ್ರ_2,ಚಿಹ್ನೆರಹಿತ (__stdcall *ಆರಂಭ_ವಿಳಾಸ) (ಶೂನ್ಯ *),ಶೂನ್ಯ *_ArgList,ಚಿಹ್ನೆರಹಿತ _InitFlag,ಚಿಹ್ನೆರಹಿತ *_ThrdAddr);
  _CRTIMP ಶೂನ್ಯ __cdecl _endthreadex(ಚಿಹ್ನೆರಹಿತ _Retval);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_TERMINATE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_TERMINATE_DEFINED
  ಶೂನ್ಯ __cdecl __MINGW_NOTHROW ನಿರ್ಗಮಿಸು(ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_4) __MINGW_ATTRIB_NORETURN;
  _CRTIMP ಶೂನ್ಯ __cdecl __MINGW_NOTHROW _exit(ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_4) __MINGW_ATTRIB_NORETURN;

#ಸೂಚನೆ ತಳ್ಳು_macro("abort")
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು abort
  ಶೂನ್ಯ __cdecl __declspec(noreturn) abort(ಶೂನ್ಯ);
#ಸೂಚನೆ ತೆಗೆ_macro("abort")

#ಆದರೆ_ಅಂತ್ಯ

  _CRTIMP ಶೂನ್ಯ __cdecl __MINGW_NOTHROW _cexit(ಶೂನ್ಯ);
  _CRTIMP ಶೂನ್ಯ __cdecl __MINGW_NOTHROW _c_exit(ಶೂನ್ಯ);
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _getpid(ಶೂನ್ಯ);
  _CRTIMP intptr_t __cdecl _cwait(ಪೂರ್ಣಾಂಕ *ಪದ_Stat,intptr_t _ProcHandle,ಪೂರ್ಣಾಂಕ _Action);
  _CRTIMP intptr_t __cdecl _execl(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_Env);
  _CRTIMP intptr_t __cdecl _execvp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ *_Env);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_SYSTEM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_SYSTEM_DEFINED
  ಪೂರ್ಣಾಂಕ __cdecl system(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Command);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WPROCESS_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(ಪೂರ್ಣಾಂಕ ಬಹುಲಕ_3,ಸ್ಥಿರಾಂಕ wchar_t *_Filename,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_ArgList,ಸ್ಥಿರಾಂಕ wchar_t *ಸ್ಥಿರಾಂಕ *_Env);
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _CRT_WSYSTEM_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _CRT_WSYSTEM_DEFINED
  _CRTIMP ಪೂರ್ಣಾಂಕ __cdecl _wsystem(ಸ್ಥಿರಾಂಕ wchar_t *_Command);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  ಶೂನ್ಯ __cdecl __security_init_cookie(ಶೂನ್ಯ);
#ಆದರೆ (defined(_X86_) && !defined(__x86_64))
  ಶೂನ್ಯ __fastcall __security_check_cookie(uintptr_t ರಾಶಿ_Cookie);
  __declspec(noreturn) ಶೂನ್ಯ __cdecl __report_gsfailure(ಶೂನ್ಯ);
#ಇಲ್ಲದಿದ್ದರೆ
  ಶೂನ್ಯ __cdecl __security_check_cookie(uintptr_t ರಾಶಿ_Cookie);
  __declspec(noreturn) ಶೂನ್ಯ __cdecl __report_gsfailure(uintptr_t ರಾಶಿ_Cookie);
#ಆದರೆ_ಅಂತ್ಯ
  ಬಾಹ್ಯ uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(ಅಕ್ಷರ *_Filename);
  ಪೂರ್ಣಾಂಕ __cdecl _unloaddll(intptr_t _Handle);
  ಪೂರ್ಣಾಂಕ (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,ಅಕ್ಷರ *_ProcedureName,intptr_t _Ordinal))(ಶೂನ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _DECL_DLLMAIN
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  ಬಾಹ್ಯ WINBOOL (WINAPI *ಸ್ಥಿರಾಂಕ _pRawDllMain)(HANDLE,DWORD,LPVOID);
#ಇಲ್ಲದಿದ್ದರೆ
  ಪೂರ್ಣಾಂಕ __stdcall DllMain(ಶೂನ್ಯ *_HDllHandle,ಚಿಹ್ನೆರಹಿತ _Reason,ಶೂನ್ಯ *_Reserved);
  ಪೂರ್ಣಾಂಕ __stdcall _CRT_INIT(ಶೂನ್ಯ *_HDllHandle,ಚಿಹ್ನೆರಹಿತ _Reason,ಶೂನ್ಯ *_Reserved);
  ಪೂರ್ಣಾಂಕ __stdcall _wCRT_INIT(ಶೂನ್ಯ *_HDllHandle,ಚಿಹ್ನೆರಹಿತ _Reason,ಶೂನ್ಯ *_Reserved);
  ಬಾಹ್ಯ ಪೂರ್ಣಾಂಕ (__stdcall *ಸ್ಥಿರಾಂಕ _pRawDllMain)(ಶೂನ್ಯ *,ಚಿಹ್ನೆರಹಿತ,ಶೂನ್ಯ *);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ	NO_OLDNAMES
#ವ್ಯಾಖ್ಯಾನಿಸು P_WAIT _P_WAIT
#ವ್ಯಾಖ್ಯಾನಿಸು P_NOWAIT _P_NOWAIT
#ವ್ಯಾಖ್ಯಾನಿಸು P_OVERLAY _P_OVERLAY
#ವ್ಯಾಖ್ಯಾನಿಸು OLD_P_OVERLAY _OLD_P_OVERLAY
#ವ್ಯಾಖ್ಯಾನಿಸು P_NOWAITO _P_NOWAITO
#ವ್ಯಾಖ್ಯಾನಿಸು P_DETACH _P_DETACH
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_ಮಗು WAIT_ಮಗು_2
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(ಪೂರ್ಣಾಂಕ *ಪದ_Stat,intptr_t _ProcHandle,ಪೂರ್ಣಾಂಕ _Action);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __GNUC__
  ಪೂರ್ಣಾಂಕ __cdecl execl(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  ಪೂರ್ಣಾಂಕ __cdecl execle(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  ಪೂರ್ಣಾಂಕ __cdecl execlp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  ಪೂರ್ಣಾಂಕ __cdecl execlpe(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
#ಇಲ್ಲದಿದ್ದರೆ
    intptr_t __cdecl execl(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  intptr_t __cdecl execle(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  intptr_t __cdecl execlp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  intptr_t __cdecl execlpe(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
#ಆದರೆ_ಅಂತ್ಯ
  intptr_t __cdecl spawnl(ಪೂರ್ಣಾಂಕ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  intptr_t __cdecl spawnle(ಪೂರ್ಣಾಂಕ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  intptr_t __cdecl spawnlp(ಪೂರ್ಣಾಂಕ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  intptr_t __cdecl spawnlpe(ಪೂರ್ಣಾಂಕ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_ArgList,...);
  ಪೂರ್ಣಾಂಕ __cdecl getpid(ಶೂನ್ಯ);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __GNUC__
  /* Those methods are predefined by gcc builtins to return int. So to prevent
     stupid warnings, define them in POSIX way.  This is save, because those
     methods do not return in success case, so that the return value is not
     really dependent to its scalar width.  */
  ಪೂರ್ಣಾಂಕ __cdecl execv(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[]);
  ಪೂರ್ಣಾಂಕ __cdecl execve(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[],ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _Env[]);
  ಪೂರ್ಣಾಂಕ __cdecl execvp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[]);
  ಪೂರ್ಣಾಂಕ __cdecl execvpe(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[],ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _Env[]);
#ಇಲ್ಲದಿದ್ದರೆ
  intptr_t __cdecl execv(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[]);
  intptr_t __cdecl execve(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[],ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _Env[]);
  intptr_t __cdecl execvp(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[]);
  intptr_t __cdecl execvpe(ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[],ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _Env[]);
#ಆದರೆ_ಅಂತ್ಯ
  intptr_t __cdecl spawnv(ಪೂರ್ಣಾಂಕ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[]);
  intptr_t __cdecl spawnve(ಪೂರ್ಣಾಂಕ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[],ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _Env[]);
  intptr_t __cdecl spawnvp(ಪೂರ್ಣಾಂಕ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[]);
  intptr_t __cdecl spawnvpe(ಪೂರ್ಣಾಂಕ,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *_Filename,ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _ArgList[],ಅಕ್ಷರ *ಸ್ಥಿರಾಂಕ _Env[]);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
