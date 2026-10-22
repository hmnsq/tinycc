/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINBASE_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINBASE_

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINADVAPI DECLSPEC_IMPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINBASEAPI DECLSPEC_IMPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ZAWPROXYAPI DECLSPEC_IMPORT

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Define_Handle_ਸਾਰਣੀ(w) ((w),TRUE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਹੱਦਬੰਦੀ_Ems_ਪੰਨੇ(dw)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਅਦਲਾ_ਬਦਲੀ_Area_ਮਾਪ(w) (w)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਤਾਲਾ_Segment(w) GlobalFix((HANDLE)(w))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Current_ਸਮਾਂ() Get_Tick_ਗਿਣਤੀ()

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Yield()

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVALID_HANDLE_ਮੁੱਲ ((HANDLE)(LONG_PTR)-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVALID_FILE_ਮਾਪ ((DWORD)0xffffffff)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVALID_ਸੈੱਟ_FILE_ਸੂਚਕ ((DWORD)-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVALID_FILE_ਗੁਣ ((DWORD)-1)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_BEGIN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_CURRENT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ਸਿਰਾ 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਮਾਂ_ZONE_ID_INVALID ((DWORD)0xffffffff)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_FAILED ((DWORD)0xffffffff)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_OBJECT_0 ((ਸਥਿਤੀ_WAIT_0) + 0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_ABANDONED ((ਸਥਿਤੀ_ABANDONED_WAIT_0) + 0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_ABANDONED_0 ((ਸਥਿਤੀ_ABANDONED_WAIT_0) + 0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WAIT_IO_COMPLETION ਸਥਿਤੀ_USER_APC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STILL_ਸਰਗਰਮ ਸਥਿਤੀ_PENDING
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_ACCESS_VIOLATION ਸਥਿਤੀ_ACCESS_VIOLATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_DATATYPE_MISALIGNMENT ਸਥਿਤੀ_DATATYPE_MISALIGNMENT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_BREAKPOINT ਸਥਿਤੀ_BREAKPOINT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_SINGLE_ਕਦਮ ਸਥਿਤੀ_SINGLE_ਕਦਮ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_ARRAY_BOUNDS_EXCEEDED ਸਥਿਤੀ_ARRAY_BOUNDS_EXCEEDED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_FLT_DENORMAL_ਸੰਕਾਰਜ ਸਥਿਤੀ_FLOAT_DENORMAL_ਸੰਕਾਰਜ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_FLT_DIVIDE_BY_ZERO ਸਥਿਤੀ_FLOAT_DIVIDE_BY_ZERO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_FLT_INEXACT_ਨਤੀਜਾ ਸਥਿਤੀ_FLOAT_INEXACT_ਨਤੀਜਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_FLT_INVALID_OPERATION ਸਥਿਤੀ_FLOAT_INVALID_OPERATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_FLT_ਉਛਾਲ ਸਥਿਤੀ_FLOAT_ਉਛਾਲ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_FLT_ਢੇਰ_CHECK ਸਥਿਤੀ_FLOAT_ਢੇਰ_CHECK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_FLT_UNDERFLOW ਸਥਿਤੀ_FLOAT_UNDERFLOW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_INT_DIVIDE_BY_ZERO ਸਥਿਤੀ_INTEGER_DIVIDE_BY_ZERO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_INT_ਉਛਾਲ ਸਥਿਤੀ_INTEGER_ਉਛਾਲ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_PRIV_INSTRUCTION ਸਥਿਤੀ_PRIVILEGED_INSTRUCTION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_ਵਿੱਚ_ਪੰਨਾ_ERROR ਸਥਿਤੀ_ਵਿੱਚ_ਪੰਨਾ_ERROR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_ILLEGAL_INSTRUCTION ਸਥਿਤੀ_ILLEGAL_INSTRUCTION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_NONCONTINUABLE_EXCEPTION ਸਥਿਤੀ_NONCONTINUABLE_EXCEPTION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_ਢੇਰ_ਉਛਾਲ ਸਥਿਤੀ_ਢੇਰ_ਉਛਾਲ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_INVALID_DISPOSITION ਸਥਿਤੀ_INVALID_DISPOSITION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_GUARD_ਪੰਨਾ ਸਥਿਤੀ_GUARD_ਪੰਨਾ_VIOLATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_INVALID_HANDLE ਸਥਿਤੀ_INVALID_HANDLE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_POSSIBLE_DEADLOCK ਸਥਿਤੀ_POSSIBLE_DEADLOCK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONTROL_C_EXIT ਸਥਿਤੀ_CONTROL_C_EXIT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Move_ਸਮ੍ਰਿਤੀ Rtl_Move_ਸਮ੍ਰਿਤੀ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Copy_ਸਮ੍ਰਿਤੀ Rtl_Copy_ਸਮ੍ਰਿਤੀ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Fill_ਸਮ੍ਰਿਤੀ Rtl_Fill_ਸਮ੍ਰਿਤੀ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Zero_ਸਮ੍ਰਿਤੀ Rtl_Zero_ਸਮ੍ਰਿਤੀ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Secure_Zero_ਸਮ੍ਰਿਤੀ Rtl_Secure_Zero_ਸਮ੍ਰਿਤੀ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_WRITE_THROUGH 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_OVERLAPPED 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_NO_BUFFERING 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_RANDOM_ACCESS 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_SEQUENTIAL_ਜਾਂਚ 0x8000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_POSIX_SEMANTICS 0x1000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_OPEN_REPARSE_ਬਿੰਦੂ 0x200000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_OPEN_NO_RECALL 0x100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_FLAG_ਪਹਿਲਾ_PIPE_INSTANCE 0x80000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_NEW 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_ALWAYS 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPEN_EXISTING 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPEN_ALWAYS 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRUNCATE_EXISTING 5

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਤਰੱਕੀ_CONTINUE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਤਰੱਕੀ_CANCEL 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਤਰੱਕੀ_STOP 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਤਰੱਕੀ_QUIET 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CALLBACK_CHUNK_ਮੁਕੰਮਲ 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CALLBACK_ਧਾਰਾ_SWITCH 0x1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COPY_FILE_FAIL_IF_EXISTS 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COPY_FILE_RESTARTABLE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COPY_FILE_OPEN_ਸਰੋਤ_FOR_WRITE 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REPLACEFILE_WRITE_THROUGH 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REPLACEFILE_IGNORE_ਮਿਲਾਓ_ERRORS 0x2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_ACCESS_INBOUND 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_ACCESS_OUTBOUND 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_ACCESS_DUPLEX 0x3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_CLIENT_ਸਿਰਾ 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_SERVER_ਸਿਰਾ 0x1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_WAIT 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_NOWAIT 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_READMODE_BYTE 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_READMODE_ਸੁਨੇਹਾ 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_TYPE_BYTE 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_TYPE_ਸੁਨੇਹਾ 0x4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PIPE_UNLIMITED_INSTANCES 255

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_DELEGATION (SecurityDelegation << 16)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_CONTEXT_TRACKING 0x40000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_EFFECTIVE_ONLY 0x80000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_SQOS_PRESENT 0x100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SECURITY_VALID_SQOS_FLAGS 0x1f0000

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OVERLAPPED {
    ULONG_PTR ਅੰਦਰੂਨੀ;
    ULONG_PTR ਅੰਦਰੂਨੀ_ਉੱਚਾ;
    ਸੰਘ {
      ਬਣਤਰ {
	DWORD ਵਿੱਥ_3;
	DWORD ਵਿੱਥ_ਉੱਚਾ_2;
      };
      PVOID ਸੂਚਕ_2;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SECURITY_ਗੁਣ {
    DWORD n_ਲੰਮਾਈ;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_ਗੁਣ_2,*PSECURITY_ਗੁਣ,*LPSECURITY_ਗੁਣ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _FILETIME_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _FILETIME_
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _FILETIME {
    DWORD dw_ਨੀਵਾਂ_Date_ਸਮਾਂ;
    DWORD dw_ਉੱਚਾ_Date_ਸਮਾਂ;
  } FILETIME,*PFILETIME,*LPFILETIME;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEMTIME {
    ਸ਼ਬਦ_3 wYear;
    ਸ਼ਬਦ_3 wMonth;
    ਸ਼ਬਦ_3 w_Day_ਦਾ_Week;
    ਸ਼ਬਦ_3 wDay;
    ਸ਼ਬਦ_3 wHour;
    ਸ਼ਬਦ_3 wMinute;
    ਸ਼ਬਦ_3 w_ਦੂਜਾ;
    ਸ਼ਬਦ_3 wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD (WINAPI *PTHREAD_ਸ਼ੁਰੂ_ROUTINE)(LPVOID lpThreadParameter);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PTHREAD_ਸ਼ੁਰੂ_ROUTINE LPTHREAD_ਸ਼ੁਰੂ_ROUTINE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (WINAPI *PFIBER_ਸ਼ੁਰੂ_ROUTINE)(LPVOID lpFiberParameter);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PFIBER_ਸ਼ੁਰੂ_ROUTINE LPFIBER_ਸ਼ੁਰੂ_ROUTINE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ RTL_CRITICAL_SECTION CRITICAL_SECTION;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI Encode_ਸੂਚਕ(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_ਸੂਚਕ(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Encode_System_ਸੂਚਕ(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_System_ਸੂਚਕ(PVOID Ptr);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ I_X86_
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PLDT_ਇੰਦਰਾਜ LPLDT_ਇੰਦਰਾਜ;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPVOID LPLDT_ਇੰਦਰਾਜ;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_SERIALCOMM ((DWORD)0x1)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_UNSPECIFIED ((DWORD)0x0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_RS232 ((DWORD)0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_PARALLELPORT ((DWORD)0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_RS422 ((DWORD)0x3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_RS423 ((DWORD)0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_RS449 ((DWORD)0x5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_MODEM ((DWORD)0x6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_FAX ((DWORD)0x21)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_SCANNER ((DWORD)0x22)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_ਜਾਲ_BRIDGE ((DWORD)0x100)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_LAT ((DWORD)0x101)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_TCPIP_TELNET ((DWORD)0x102)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PST_X25 ((DWORD)0x103)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_DTRDSR ((DWORD)0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_RTSCTS ((DWORD)0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_RLSD ((DWORD)0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_PARITY_CHECK ((DWORD)0x8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_XONXOFF ((DWORD)0x10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_SETXCHAR ((DWORD)0x20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_TOTALTIMEOUTS ((DWORD)0x40)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_INTTIMEOUTS ((DWORD)0x80)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_SPECIALCHARS ((DWORD)0x100)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PCF_16BITMODE ((DWORD)0x200)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_PARITY ((DWORD)0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_BAUD ((DWORD)0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_DATABITS ((DWORD)0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_STOPBITS ((DWORD)0x8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_HANDSHAKING ((DWORD)0x10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_PARITY_CHECK ((DWORD)0x20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_RLSD ((DWORD)0x40)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_075 ((DWORD)0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_110 ((DWORD)0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_134_5 ((DWORD)0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_150 ((DWORD)0x8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_300 ((DWORD)0x10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_600 ((DWORD)0x20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_1200 ((DWORD)0x40)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_1800 ((DWORD)0x80)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_2400 ((DWORD)0x100)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_4800 ((DWORD)0x200)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_7200 ((DWORD)0x400)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_9600 ((DWORD)0x800)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_14400 ((DWORD)0x1000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_19200 ((DWORD)0x2000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_38400 ((DWORD)0x4000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_56K ((DWORD)0x8000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_128K ((DWORD)0x10000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_115200 ((DWORD)0x20000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_57600 ((DWORD)0x40000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BAUD_USER ((DWORD)0x10000000)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DATABITS_5 ((ਸ਼ਬਦ_3)0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DATABITS_6 ((ਸ਼ਬਦ_3)0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DATABITS_7 ((ਸ਼ਬਦ_3)0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DATABITS_8 ((ਸ਼ਬਦ_3)0x8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DATABITS_16 ((ਸ਼ਬਦ_3)0x10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DATABITS_16X ((ਸ਼ਬਦ_3)0x20)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STOPBITS_10 ((ਸ਼ਬਦ_3)0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STOPBITS_15 ((ਸ਼ਬਦ_3)0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STOPBITS_20 ((ਸ਼ਬਦ_3)0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARITY_NONE ((ਸ਼ਬਦ_3)0x100)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARITY_ODD ((ਸ਼ਬਦ_3)0x200)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARITY_EVEN ((ਸ਼ਬਦ_3)0x400)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARITY_MARK ((ਸ਼ਬਦ_3)0x800)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PARITY_SPACE ((ਸ਼ਬਦ_3)0x1000)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _COMMPROP {
    ਸ਼ਬਦ_3 w_Packet_ਲੰਮਾਈ;
    ਸ਼ਬਦ_3 w_Packet_ਸੰਸਕਰਣ;
    DWORD dw_Service_ਨਕਾਬ;
    DWORD dwReserved1;
    DWORD dw_Max_Tx_ਕਤਾਰ;
    DWORD dw_Max_Rx_ਕਤਾਰ;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    ਸ਼ਬਦ_3 w_Settable_ਅੰਕੜੇ;
    ਸ਼ਬਦ_3 wSettableStopParity;
    DWORD dw_Current_Tx_ਕਤਾਰ;
    DWORD dw_Current_Rx_ਕਤਾਰ;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD f_Xoff_ਭੇਜਿਆ : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cb_ਵਿੱਚ_Que;
    DWORD cb_ਬਾਹਰਲਾ_Que;
  } COMSTAT,*LPCOMSTAT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DTR_CONTROL_DISABLE 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DTR_CONTROL_ENABLE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DTR_CONTROL_HANDSHAKE 0x2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTS_CONTROL_DISABLE 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTS_CONTROL_ENABLE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTS_CONTROL_HANDSHAKE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RTS_CONTROL_TOGGLE 0x3

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _DCB {
    DWORD DCBlength;
    DWORD Baud_ਦਰ;
    DWORD f_ਦੁਆਧਾਰੀ: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD f_Dsr_ਸੰਵੇਦਨਸ਼ੀਲਤਾ:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD f_ਬਾਹਰਲਾ_X: 1;
    DWORD f_ਵਿੱਚ_X: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    ਸ਼ਬਦ_3 wReserved;
    ਸ਼ਬਦ_3 XonLim;
    ਸ਼ਬਦ_3 XoffLim;
    BYTE Byte_ਮਾਪ;
    BYTE Parity;
    BYTE Stop_ਬਿੱਟ;
    ਅੱਖਰ XonChar;
    ਅੱਖਰ XoffChar;
    ਅੱਖਰ ErrorChar;
    ਅੱਖਰ EofChar;
    ਅੱਖਰ EvtChar;
    ਸ਼ਬਦ_3 wReserved1;
  } DCB,*LPDCB;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD Read_ਕੁੱਲ_Timeout_Multiplier;
    DWORD Read_ਕੁੱਲ_Timeout_Constant;
    DWORD Write_ਕੁੱਲ_Timeout_Multiplier;
    DWORD Write_ਕੁੱਲ_Timeout_Constant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _COMMCONFIG {
    DWORD dw_ਮਾਪ;
    ਸ਼ਬਦ_3 w_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3 wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dw_Provider_ਵਿੱਥ;
    DWORD dw_Provider_ਮਾਪ;
    WCHAR wc_Provider_ਅੰਕੜੇ[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SYSTEM_INFO {
    ਸੰਘ {
      DWORD dwOemId;
      ਬਣਤਰ {
	ਸ਼ਬਦ_3 wProcessorArchitecture;
	ਸ਼ਬਦ_3 wReserved;
      };
    };
    DWORD dw_ਪੰਨਾ_ਮਾਪ;
    LPVOID lp_Minimum_Application_ਪਤਾ;
    LPVOID lp_ਵੱਧ_ਤੋਂ_ਵੱਧ_Application_ਪਤਾ;
    DWORD_PTR dw_ਸਰਗਰਮ_Processor_ਨਕਾਬ;
    DWORD dw_ਸੰਖਿਆ_ਦਾ_Processors;
    DWORD dwProcessorType;
    DWORD dw_ਵੰਡ_Granularity;
    ਸ਼ਬਦ_3 wProcessorLevel;
    ਸ਼ਬਦ_3 wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FreeModule(hLibModule) FreeLibrary((hLibModule))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MakeProcInstance(lpProc,hInstance) (lpProc)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FreeProcInstance(lpProc) (lpProc)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_FIXED 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_MOVEABLE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_NOCOMPACT 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_NODISCARD 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_ZEROINIT 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_MODIFY 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_DISCARDABLE 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_NOT_BANKED 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_SHARE 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_DDESHARE 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_NOTIFY 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_ਹੇਠਲਾ GMEM_NOT_BANKED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_VALID_FLAGS 0x7F72
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_INVALID_HANDLE 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GlobalLRUNewest(h) ((HANDLE)(h))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GlobalLRUOldest(h) ((HANDLE)(h))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_DISCARDED 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMEM_LOCKCOUNT 0xff

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _MEMORYSTATUS {
    DWORD dw_ਲੰਮਾਈ;
    DWORD dw_ਸਮ੍ਰਿਤੀ_ਲੱਦੋ;
    ਮਾਪ_T dw_ਕੁੱਲ_Phys;
    ਮਾਪ_T dwAvailPhys;
    ਮਾਪ_T dw_ਕੁੱਲ_ਪੰਨਾ_File;
    ਮਾਪ_T dw_Avail_ਪੰਨਾ_File;
    ਮਾਪ_T dw_ਕੁੱਲ_Virtual;
    ਮਾਪ_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_FIXED 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_MOVEABLE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_NOCOMPACT 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_NODISCARD 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_ZEROINIT 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_MODIFY 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_DISCARDABLE 0xf00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_VALID_FLAGS 0xf72
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_INVALID_HANDLE 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NONZEROLHND (LMEM_MOVEABLE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NONZEROLPTR (LMEM_FIXED)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_DISCARDED 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LMEM_LOCKCOUNT 0xff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEBUG_PROCESS 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEBUG_ONLY_THIS_PROCESS 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_SUSPENDED 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DETACHED_PROCESS 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_NEW_CONSOLE 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਾਧਾਰਨ_ਤਰਜੀਹ_CLASS 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDLE_ਤਰਜੀਹ_CLASS 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਉੱਚਾ_ਤਰਜੀਹ_CLASS 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REALTIME_ਤਰਜੀਹ_CLASS 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_NEW_PROCESS_ਸਮੂਹ 0x200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_UNICODE_ENVIRONMENT 0x400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_SEPARATE_WOW_VDM 0x800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_SHARED_WOW_VDM 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_FORCEDOS 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਹੇਠਾਂ_ਸਾਧਾਰਨ_ਤਰਜੀਹ_CLASS 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ABOVE_ਸਾਧਾਰਨ_ਤਰਜੀਹ_CLASS 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਢੇਰ_ਮਾਪ_PARAM_IS_A_RESERVATION 0x10000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_BREAKAWAY_FROM_ਕੰਮ 0x1000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_PRESERVE_ਕੋਡ_AUTHZ_LEVEL 0x2000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_DEFAULT_ERROR_ਬਹੁਲਕ 0x4000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_NO_ਖਿੜਕੀ 0x8000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROFILE_USER 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROFILE_KERNEL 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROFILE_SERVER 0x40000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਤਰਜੀਹ_ਸਭ_ਤੋਂ_ਨੀਵਾਂ THREAD_ਅਧਾਰ_ਤਰਜੀਹ_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਤਰਜੀਹ_ਹੇਠਾਂ_ਸਾਧਾਰਨ (THREAD_ਤਰਜੀਹ_ਸਭ_ਤੋਂ_ਨੀਵਾਂ+1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਤਰਜੀਹ_ਸਾਧਾਰਨ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਤਰਜੀਹ_HIGHEST THREAD_ਅਧਾਰ_ਤਰਜੀਹ_MAX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਤਰਜੀਹ_ABOVE_ਸਾਧਾਰਨ (THREAD_ਤਰਜੀਹ_HIGHEST-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਤਰਜੀਹ_ERROR_RETURN (MAXLONG)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਤਰਜੀਹ_ਸਮਾਂ_CRITICAL THREAD_ਅਧਾਰ_ਤਰਜੀਹ_LOWRT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THREAD_ਤਰਜੀਹ_IDLE THREAD_ਅਧਾਰ_ਤਰਜੀਹ_IDLE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXCEPTION_DEBUG_EVENT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_THREAD_DEBUG_EVENT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_PROCESS_DEBUG_EVENT 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_THREAD_DEBUG_EVENT 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXIT_PROCESS_DEBUG_EVENT 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_DLL_DEBUG_EVENT 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNLOAD_DLL_DEBUG_EVENT 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OUTPUT_DEBUG_STRING_EVENT 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIP_EVENT 9

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _EXCEPTION_DEBUG_INFO {
    EXCEPTION_ਰਿਕਾਰਡ_2 Exception_ਰਿਕਾਰਡ;
    DWORD dw_ਪਹਿਲਾ_Chance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lp_Thread_Local_ਅਧਾਰ;
    LPTHREAD_ਸ਼ੁਰੂ_ROUTINE lp_ਸ਼ੁਰੂ_ਪਤਾ;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lp_ਅਧਾਰ_ਦਾ_Image;
    DWORD dw_Debug_Info_File_ਵਿੱਥ;
    DWORD n_Debug_Info_ਮਾਪ;
    LPVOID lp_Thread_Local_ਅਧਾਰ;
    LPTHREAD_ਸ਼ੁਰੂ_ROUTINE lp_ਸ਼ੁਰੂ_ਪਤਾ;
    LPVOID lpImageName;
    ਸ਼ਬਦ_3 fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _EXIT_THREAD_DEBUG_INFO {
    DWORD dw_Exit_ਕੋਡ;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _EXIT_PROCESS_DEBUG_INFO {
    DWORD dw_Exit_ਕੋਡ;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਲੱਦੋ_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lp_ਅਧਾਰ_ਦਾ_Dll;
    DWORD dw_Debug_Info_File_ਵਿੱਥ;
    DWORD n_Debug_Info_ਮਾਪ;
    LPVOID lpImageName;
    ਸ਼ਬਦ_3 fUnicode;
  } ਲੱਦੋ_DLL_DEBUG_INFO_2,*LPLOAD_DLL_DEBUG_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lp_ਅਧਾਰ_ਦਾ_Dll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lp_Debug_String_ਅੰਕੜੇ;
    ਸ਼ਬਦ_3 fUnicode;
    ਸ਼ਬਦ_3 n_Debug_String_ਲੰਮਾਈ;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _DEBUG_EVENT {
    DWORD dw_Debug_Event_ਕੋਡ;
    DWORD dwProcessId;
    DWORD dwThreadId;
    ਸੰਘ {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      ਲੱਦੋ_DLL_DEBUG_INFO_2 ਲੱਦੋ_Dll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PCONTEXT LPCONTEXT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PEXCEPTION_ਰਿਕਾਰਡ LPEXCEPTION_ਰਿਕਾਰਡ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PEXCEPTION_ਸੂਚਕ_ਸਾਰੇ LPEXCEPTION_ਸੂਚਕ_ਸਾਰੇ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRIVE_UNKNOWN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRIVE_NO_ਜੜ੍ਹ_DIR 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRIVE_REMOVABLE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRIVE_FIXED 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRIVE_REMOTE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRIVE_CDROM 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRIVE_RAMDISK 6

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetFreeSpace(w) (0x100000L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_TYPE_UNKNOWN 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_TYPE_DISK 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_TYPE_CHAR 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_TYPE_PIPE 0x3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_TYPE_REMOTE 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STD_ਨਿਵੇਸ਼_HANDLE ((DWORD)-10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STD_OUTPUT_HANDLE ((DWORD)-11)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STD_ERROR_HANDLE ((DWORD)-12)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOPARITY 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODDPARITY 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENPARITY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MARKPARITY 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPACEPARITY 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ONESTOPBIT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ONE5STOPBITS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TWOSTOPBITS 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IGNORE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INFINITE 0xffffffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_110 110
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_300 300
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_600 600
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_1200 1200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_2400 2400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_4800 4800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_9600 9600
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_14400 14400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_19200 19200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_38400 38400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_56000 56000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_57600 57600
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_115200 115200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_128000 128000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBR_256000 256000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_RXOVER 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_OVERRUN 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_RXPARITY 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_ਚੌਖਟਾ 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_BREAK 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_TXFULL 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_PTO 0x200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_IOE 0x400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_DNS 0x800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_OOP 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CE_ਬਹੁਲਕ 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IE_BADID (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IE_OPEN (-2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IE_NOPEN (-3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IE_ਸਮ੍ਰਿਤੀ (-4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IE_DEFAULT (-5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IE_HARDWARE (-10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IE_BYTESIZE (-11)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IE_BAUDRATE (-12)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_RXCHAR 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_RXFLAG 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_TXEMPTY 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_CTS 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_DSR 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_RLSD 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_BREAK 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_ERR 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_RING 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_PERR 0x200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_RX80_ਭਰਿਆ 0x400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_EVENT1 0x800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EV_EVENT2 0x1000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETXOFF 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETXON 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETRTS 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLRRTS 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETDTR 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLRDTR 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RESETDEV 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETBREAK 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLRBREAK 9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PURGE_TXABORT 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PURGE_RXABORT 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PURGE_TXCLEAR 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PURGE_RXCLEAR 0x8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPTx 0x80

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MS_CTS_ON ((DWORD)0x10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MS_DSR_ON ((DWORD)0x20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MS_RING_ON ((DWORD)0x40)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MS_RLSD_ON ((DWORD)0x80)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_QUEUEEMPTY 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_ਹੱਦ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_ALLTHRESHOLD 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_ਸਾਧਾਰਨ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_LEGATO 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_STACCATO 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_PERIOD512 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_PERIOD1024 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_PERIOD2048 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_PERIODVOICE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_WHITE512 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_WHITE1024 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_WHITE2048 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_WHITEVOICE 7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDVNA (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SEROFM (-2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERMACT (-3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERQFUL (-4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERBDNT (-5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDLN (-6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDCC (-7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDTP (-8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDVL (-9)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDMD (-10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDSH (-11)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDPT (-12)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDFQ (-13)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDDR (-14)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDSR (-15)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ S_SERDST (-16)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NMPWAIT_WAIT_FOREVER 0xffffffff
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NMPWAIT_NOWAIT 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NMPWAIT_USE_DEFAULT_WAIT 0x0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_ਨਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_ਖੋਜ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_MAP_COPY SECTION_QUERY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_MAP_WRITE SECTION_MAP_WRITE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_MAP_READ SECTION_MAP_READ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_READ 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_WRITE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_READWRITE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_SHARE_COMPAT 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_SHARE_EXCLUSIVE 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_SHARE_DENY_WRITE 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_SHARE_DENY_READ 0x30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_SHARE_DENY_NONE 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_PARSE 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_DELETE 0x200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_VERIFY 0x400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_CANCEL 0x800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_CREATE 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_PROMPT 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_EXIST 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਦਾ_REOPEN 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OFS_MAXPATHNAME 128
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OFSTRUCT {
    BYTE c_ਬਾਈਟਾਂ;
    BYTE fFixedDisk;
    ਸ਼ਬਦ_3 n_Err_ਕੋਡ;
    ਸ਼ਬਦ_3 Reserved1;
    ਸ਼ਬਦ_3 Reserved2;
    CHAR sz_ਰਸਤਾ_Name[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINBASEINTERLOCK

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _NTOS_

#ਜੇ defined(__ia64__) && !defined(RC_INVOKED)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrement _InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementAcquire _InterlockedIncrement_acq
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementRelease _InterlockedIncrement_rel
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrement _InterlockedDecrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrementAcquire _InterlockedDecrement_acq
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrementRelease _InterlockedDecrement_rel
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchange _InterlockedExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Exchange_ਜੋੜੋ Interlocked_Exchange_ਜੋੜੋ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchange _InterlockedCompareExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Exchange_ਸੂਚਕ Interlocked_Exchange_ਸੂਚਕ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ Interlocked_Compare_Exchange_ਸੂਚਕ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Release Interlocked_Compare_Exchange_ਸੂਚਕ_rel
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Acquire Interlocked_Compare_Exchange_ਸੂਚਕ_acq

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrement64 _InterlockedIncrement64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrement64 _InterlockedDecrement64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchange64 _InterlockedExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchange64 _InterlockedCompareExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG ਅਸਥਿਰ *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG ਅਸਥਿਰ *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG ਅਸਥਿਰ *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG ਅਸਥਿਰ *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG ਅਸਥਿਰ *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG ਅਸਥਿਰ *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONGLONG ਮੁੱਲ_3);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONGLONG ਮੁੱਲ_3);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG ਅਸਥਿਰ *Addend,LONGLONG ਮੁੱਲ_3);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG ਅਸਥਿਰ *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG ਅਸਥਿਰ *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG ਅਸਥਿਰ *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG ਅਸਥਿਰ *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG ਅਸਥਿਰ *lpAddend);
  LONG __cdecl InterlockedExchange(LONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG ਮੁੱਲ_3);
  LONG __cdecl Interlocked_Exchange_ਜੋੜੋ(LONG ਅਸਥਿਰ *Addend,LONG ਮੁੱਲ_3);
  LONG __cdecl InterlockedCompareExchange(LONG ਅਸਥਿਰ *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG ਅਸਥਿਰ *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG ਅਸਥਿਰ *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl Interlocked_Exchange_ਸੂਚਕ(PVOID ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,PVOID ਮੁੱਲ_3);
  PVOID __cdecl Interlocked_Compare_Exchange_ਸੂਚਕ(PVOID ਅਸਥਿਰ *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_ਸੂਚਕ_Acquire(PVOID ਅਸਥਿਰ *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_ਸੂਚਕ_Release(PVOID ਅਸਥਿਰ *Destination,PVOID Exchange,PVOID Comperand);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ InterlockedAnd
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG ਸੈੱਟ_2) {
    LONG i;
    LONG j;
    j = *ਨਿਸ਼ਾਨਾ_2;
    ਕਰੋ {
      i = j;
      j = InterlockedCompareExchange(ਨਿਸ਼ਾਨਾ_2,i & ਸੈੱਟ_2,i);
    } ਜਦੋਂ(i!=j);
    ਵਾਪਸ j;
  }
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ InterlockedOr
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG ਸੈੱਟ_2) {
    LONG i;
    LONG j;
    j = *ਨਿਸ਼ਾਨਾ_2;
    ਕਰੋ {
      i = j;
      j = InterlockedCompareExchange(ਨਿਸ਼ਾਨਾ_2,i | ਸੈੱਟ_2,i);
    } ਜਦੋਂ(i!=j);
    ਵਾਪਸ j;
  }
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ InterlockedXor
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG ਸੈੱਟ_2) {
    LONG i;
    LONG j;
    j = *ਨਿਸ਼ਾਨਾ_2;
    ਕਰੋ {
      i = j;
      j = InterlockedCompareExchange(ਨਿਸ਼ਾਨਾ_2,i ^ ਸੈੱਟ_2,i);
    } ਜਦੋਂ(i!=j);
    ਵਾਪਸ j;
  }
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ InterlockedAnd64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG ਅਸਥਿਰ *Destination,LONGLONG ਮੁੱਲ_3) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *Destination;
    } ਜਦੋਂ(InterlockedCompareExchange64(Destination,Old & ਮੁੱਲ_3,Old)!=Old);
    ਵਾਪਸ Old;
  }
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ InterlockedOr64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG ਅਸਥਿਰ *Destination,LONGLONG ਮੁੱਲ_3) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *Destination;
    } ਜਦੋਂ(InterlockedCompareExchange64(Destination,Old | ਮੁੱਲ_3,Old)!=Old);
    ਵਾਪਸ Old;
  }
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ InterlockedXor64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG ਅਸਥਿਰ *Destination,LONGLONG ਮੁੱਲ_3) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *Destination;
    } ਜਦੋਂ(InterlockedCompareExchange64(Destination,Old ^ ਮੁੱਲ_3,Old)!=Old);
    ਵਾਪਸ Old;
  }
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_ਸੈੱਟ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_ਸੈੱਟ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_ਸੈੱਟ_Inline

  __CRT_INLINE BOOLEAN Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_ਸੈੱਟ_Inline(LONG *ਅਧਾਰ_2,LONG ਦੋਆਧਾਰੀ_ਅੰਕ_2) {
    LONG t_ਦੋਆਧਾਰੀ_ਅੰਕ;
    t_ਦੋਆਧਾਰੀ_ਅੰਕ = 1<<(ਦੋਆਧਾਰੀ_ਅੰਕ_2 & (ਆਕਾਰ (*ਅਧਾਰ_2)*8-1));
    ਵਾਪਸ (BOOLEAN)((InterlockedOr(&ਅਧਾਰ_2[ਦੋਆਧਾਰੀ_ਅੰਕ_2/(ਆਕਾਰ(*ਅਧਾਰ_2)*8)],t_ਦੋਆਧਾਰੀ_ਅੰਕ)&t_ਦੋਆਧਾਰੀ_ਅੰਕ)!=0);
  }
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Reset
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Reset Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Reset_Inline

  __CRT_INLINE BOOLEAN Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Reset_Inline(LONG *ਅਧਾਰ_2,LONG ਦੋਆਧਾਰੀ_ਅੰਕ_2) {
    LONG t_ਦੋਆਧਾਰੀ_ਅੰਕ;
    t_ਦੋਆਧਾਰੀ_ਅੰਕ = 1<<(ਦੋਆਧਾਰੀ_ਅੰਕ_2 & (ਆਕਾਰ (*ਅਧਾਰ_2)*8-1));
    ਵਾਪਸ (BOOLEAN)((InterlockedAnd(&ਅਧਾਰ_2[ਦੋਆਧਾਰੀ_ਅੰਕ_2/(ਆਕਾਰ(*ਅਧਾਰ_2)*8)],~t_ਦੋਆਧਾਰੀ_ਅੰਕ)&t_ਦੋਆਧਾਰੀ_ਅੰਕ)!=0);
  }
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Complement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Complement Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Complement_Inline

  __CRT_INLINE BOOLEAN Interlocked_ਦੋਆਧਾਰੀ_ਅੰਕ_Test_And_Complement_Inline(LONG *ਅਧਾਰ_2,LONG ਦੋਆਧਾਰੀ_ਅੰਕ_2) {
    LONG t_ਦੋਆਧਾਰੀ_ਅੰਕ;
    t_ਦੋਆਧਾਰੀ_ਅੰਕ = 1<<(ਦੋਆਧਾਰੀ_ਅੰਕ_2 & (ਆਕਾਰ (*ਅਧਾਰ_2)*8-1));
    ਵਾਪਸ (BOOLEAN)((InterlockedXor(&ਅਧਾਰ_2[ਦੋਆਧਾਰੀ_ਅੰਕ_2/(ਆਕਾਰ(*ਅਧਾਰ_2)*8)],t_ਦੋਆਧਾਰੀ_ਅੰਕ)&t_ਦੋਆਧਾਰੀ_ਅੰਕ)!=0);
  }
#ਜੇ_ਅੰਤ
#ਜਾਂਜੇ defined(__x86_64) && !defined(RC_INVOKED)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrement _InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementAcquire InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementRelease InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrement _InterlockedDecrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrementAcquire InterlockedDecrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrementRelease InterlockedDecrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchange _InterlockedExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Exchange_ਜੋੜੋ Interlocked_Exchange_ਜੋੜੋ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchange _InterlockedCompareExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeAcquire InterlockedCompareExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeRelease InterlockedCompareExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Exchange_ਸੂਚਕ Interlocked_Exchange_ਸੂਚਕ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ Interlocked_Compare_Exchange_ਸੂਚਕ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Acquire Interlocked_Compare_Exchange_ਸੂਚਕ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Release Interlocked_Compare_Exchange_ਸੂਚਕ_2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedAnd64 _InterlockedAnd64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedOr64 _InterlockedOr64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedXor64 _InterlockedXor64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrement64 _InterlockedIncrement64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrement64 _InterlockedDecrement64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchange64 _InterlockedExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchange64 _InterlockedCompareExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG ਅਸਥਿਰ *Addend);
  LONG InterlockedDecrement(LONG ਅਸਥਿਰ *Addend);
  LONG InterlockedExchange(LONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG ਮੁੱਲ_3);
  LONG Interlocked_Exchange_ਜੋੜੋ(LONG ਅਸਥਿਰ *Addend,LONG ਮੁੱਲ_3);
  LONG InterlockedCompareExchange(LONG ਅਸਥਿਰ *Destination,LONG ExChange,LONG Comperand);
  PVOID Interlocked_Compare_Exchange_ਸੂਚਕ(PVOID ਅਸਥਿਰ *Destination,PVOID Exchange,PVOID Comperand);
  PVOID Interlocked_Exchange_ਸੂਚਕ(PVOID ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,PVOID ਮੁੱਲ_3);
  LONG64 InterlockedAnd64(LONG64 ਅਸਥਿਰ *Destination,LONG64 ਮੁੱਲ_3);
  LONG64 InterlockedOr64(LONG64 ਅਸਥਿਰ *Destination,LONG64 ਮੁੱਲ_3);
  LONG64 InterlockedXor64(LONG64 ਅਸਥਿਰ *Destination,LONG64 ਮੁੱਲ_3);
  LONG64 InterlockedIncrement64(LONG64 ਅਸਥਿਰ *Addend);
  LONG64 InterlockedDecrement64(LONG64 ਅਸਥਿਰ *Addend);
  LONG64 InterlockedExchange64(LONG64 ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG64 ਮੁੱਲ_3);
  LONG64 InterlockedExchangeAdd64(LONG64 ਅਸਥਿਰ *Addend,LONG64 ਮੁੱਲ_3);
  LONG64 InterlockedCompareExchange64(LONG64 ਅਸਥਿਰ *Destination,LONG64 ExChange,LONG64 Comperand);
#ਨਹੀਂਤਾਂ
  LONG WINAPI InterlockedIncrement(LONG ਅਸਥਿਰ *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG ਅਸਥਿਰ *lpAddend);
  LONG WINAPI InterlockedExchange(LONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONG ਮੁੱਲ_3);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ Interlocked_Exchange_ਸੂਚਕ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Exchange_ਸੂਚਕ(ਨਿਸ਼ਾਨਾ_2,ਮੁੱਲ_3) (PVOID)InterlockedExchange((PLONG)(ਨਿਸ਼ਾਨਾ_2),(LONG)(ਮੁੱਲ_3))
#ਜੇ_ਅੰਤ

  LONG WINAPI Interlocked_Exchange_ਜੋੜੋ(LONG ਅਸਥਿਰ *Addend,LONG ਮੁੱਲ_3);
  LONG WINAPI InterlockedCompareExchange(LONG ਅਸਥਿਰ *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG ਅਸਥਿਰ *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG ਅਸਥਿਰ *Destination,LONGLONG ਮੁੱਲ_3) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *Destination;
    } ਜਦੋਂ(InterlockedCompareExchange64(Destination,Old & ਮੁੱਲ_3,Old)!=Old);
    ਵਾਪਸ Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG ਅਸਥਿਰ *Destination,LONGLONG ਮੁੱਲ_3) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *Destination;
    } ਜਦੋਂ(InterlockedCompareExchange64(Destination,Old | ਮੁੱਲ_3,Old)!=Old);
    ਵਾਪਸ Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG ਅਸਥਿਰ *Destination,LONGLONG ਮੁੱਲ_3) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *Destination;
    } ਜਦੋਂ(InterlockedCompareExchange64(Destination,Old ^ ਮੁੱਲ_3,Old)!=Old);

    ਵਾਪਸ Old;
  }

  __CRT_INLINE LONGLONG InterlockedIncrement64(LONGLONG ਅਸਥਿਰ *Addend) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *Addend;
    } ਜਦੋਂ(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    ਵਾਪਸ Old + 1;
  }

  __CRT_INLINE LONGLONG InterlockedDecrement64(LONGLONG ਅਸਥਿਰ *Addend) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *Addend;
    } ਜਦੋਂ(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    ਵਾਪਸ Old - 1;
  }

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG ਅਸਥਿਰ *ਨਿਸ਼ਾਨਾ_2,LONGLONG ਮੁੱਲ_3) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *ਨਿਸ਼ਾਨਾ_2;
    } ਜਦੋਂ(InterlockedCompareExchange64(ਨਿਸ਼ਾਨਾ_2,ਮੁੱਲ_3,Old)!=Old);
    ਵਾਪਸ Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG ਅਸਥਿਰ *Addend,LONGLONG ਮੁੱਲ_3) {
    LONGLONG Old;
    ਕਰੋ {
      Old = *Addend;
    } ਜਦੋਂ(InterlockedCompareExchange64(Addend,Old + ਮੁੱਲ_3,Old)!=Old);
    ਵਾਪਸ Old;
  }

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ Interlocked_Compare_Exchange_ਸੂਚਕ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID ਅਸਥਿਰ *Destination,PVOID ExChange,PVOID Comperand) {
    ਵਾਪਸ((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG ਅਸਥਿਰ *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ __InlineInterlockedCompareExchangePointer
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG ਅਸਥਿਰ *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementAcquire InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementRelease InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrementAcquire InterlockedDecrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedDecrementRelease InterlockedDecrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementAcquire InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedIncrementRelease InterlockedIncrement
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeAcquire InterlockedCompareExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeRelease InterlockedCompareExchange
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ Interlocked_Compare_Exchange_ਸੂਚਕ_Acquire
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Acquire Interlocked_Compare_Exchange_ਸੂਚਕ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ Interlocked_Compare_Exchange_ਸੂਚਕ_Release
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Interlocked_Compare_Exchange_ਸੂਚਕ_Release Interlocked_Compare_Exchange_ਸੂਚਕ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ defined(SLIST_ਸਿਰਲੇਖ) && !defined(_NTOSP_)
  WINBASEAPI VOID WINAPI Initialize_SList_ਸਿਰ(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ);
  WINBASEAPI PSLIST_ਇੰਦਰਾਜ WINAPI Interlocked_ਕੱਢੋ_ਇੰਦਰਾਜ_SList(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ);
  WINBASEAPI PSLIST_ਇੰਦਰਾਜ WINAPI Interlocked_ਧੱਕੋ_ਇੰਦਰਾਜ_SList(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ,PSLIST_ਇੰਦਰਾਜ List_ਇੰਦਰਾਜ);
  WINBASEAPI PSLIST_ਇੰਦਰਾਜ WINAPI InterlockedFlushSList(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ);
  WINBASEAPI USHORT WINAPI Query_ਡੂੰਘਾਈ_SList(PSLIST_ਸਿਰਲੇਖ List_ਸਿਰ);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL h_Res_ਅੰਕੜੇ);
  WINBASEAPI LPVOID WINAPI ਤਾਲਾ_Resource(HGLOBAL h_Res_ਅੰਕੜੇ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UnlockResource(h_Res_ਅੰਕੜੇ) ((h_Res_ਅੰਕੜੇ),0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXINTATOM 0xC000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((ਸ਼ਬਦ_3)(i)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INVALID_ATOM ((ATOM)0)

  ਪੂਰਨ WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lp_Cmd_ਸਤਰ,ਪੂਰਨ nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dw_Exit_ਕੋਡ);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI Get_Proc_ਪਤਾ(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI Get_ਸੰਸਕਰਣ(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,ਮਾਪ_T dw_ਬਾਈਟਾਂ);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,ਮਾਪ_T dw_ਬਾਈਟਾਂ,UINT uFlags);
  WINBASEAPI ਮਾਪ_T WINAPI Global_ਮਾਪ(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI Global_ਤਾਲਾ(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI ਮਾਪ_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI Global_ਸਮ੍ਰਿਤੀ_ਸਥਿਤੀ(LPMEMORYSTATUS lp_ਬਫਰ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _MEMORYSTATUSEX {
    DWORD dw_ਲੰਮਾਈ;
    DWORD dw_ਸਮ੍ਰਿਤੀ_ਲੱਦੋ;
    DWORDLONG ull_ਕੁੱਲ_Phys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ull_ਕੁੱਲ_ਪੰਨਾ_File;
    DWORDLONG ull_Avail_ਪੰਨਾ_File;
    DWORDLONG ull_ਕੁੱਲ_Virtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI Global_ਸਮ੍ਰਿਤੀ_ਸਥਿਤੀ_Ex(LPMEMORYSTATUSEX lp_ਬਫਰ);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,ਮਾਪ_T u_ਬਾਈਟਾਂ);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,ਮਾਪ_T u_ਬਾਈਟਾਂ,UINT uFlags);
  WINBASEAPI LPVOID WINAPI Local_ਤਾਲਾ(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI ਮਾਪ_T WINAPI Local_ਮਾਪ(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI ਮਾਪ_T WINAPI LocalShrink(HLOCAL hMem,UINT cb_New_ਮਾਪ);
  WINBASEAPI ਮਾਪ_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lp_ਅਧਾਰ_ਪਤਾ,ਮਾਪ_T dw_ਮਾਪ);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lp_ਪਤਾ,ਮਾਪ_T dw_ਮਾਪ,DWORD fl_ਵੰਡ_Type,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lp_ਪਤਾ,ਮਾਪ_T dw_ਮਾਪ,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lp_ਪਤਾ,ਮਾਪ_T dw_ਮਾਪ,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI ਮਾਪ_T WINAPI VirtualQuery(LPCVOID lp_ਪਤਾ,PMEMORY_BASIC_INFORMATION lp_ਬਫਰ,ਮਾਪ_T dw_ਲੰਮਾਈ);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lp_ਪਤਾ,ਮਾਪ_T dw_ਮਾਪ,DWORD fl_ਵੰਡ_Type,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lp_ਅਧਾਰ_ਪਤਾ,ਮਾਪ_T dw_Region_ਮਾਪ,PVOID *lp_ਪਤੇ,ULONG_PTR *lpdw_ਗਿਣਤੀ,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lp_ਅਧਾਰ_ਪਤਾ,ਮਾਪ_T dw_Region_ਮਾਪ);
  WINBASEAPI ਮਾਪ_T WINAPI Get_Large_ਪੰਨਾ_Minimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD Firmware_ਸਾਰਣੀ_Provider_Signature,PVOID p_Firmware_ਸਾਰਣੀ_Enum_ਬਫਰ,DWORD ਬਫਰ_ਮਾਪ);
  WINBASEAPI UINT WINAPI Get_System_Firmware_ਸਾਰਣੀ(DWORD Firmware_ਸਾਰਣੀ_Provider_Signature,DWORD Firmware_ਸਾਰਣੀ_ID,PVOID p_Firmware_ਸਾਰਣੀ_ਬਫਰ,DWORD ਬਫਰ_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lp_ਪਤਾ,ਮਾਪ_T dw_ਮਾਪ,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lp_ਪਤਾ,ਮਾਪ_T dw_ਮਾਪ,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI ਮਾਪ_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lp_ਪਤਾ,PMEMORY_BASIC_INFORMATION lp_ਬਫਰ,ਮਾਪ_T dw_ਲੰਮਾਈ);
  WINBASEAPI HANDLE WINAPI ਢੇਰ_Create(DWORD flOptions,ਮਾਪ_T dw_Initial_ਮਾਪ,ਮਾਪ_T dw_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਢੇਰ_Destroy(HANDLE h_ਢੇਰ);
  WINBASEAPI LPVOID WINAPI ਢੇਰ_Alloc(HANDLE h_ਢੇਰ,DWORD dwFlags,ਮਾਪ_T dw_ਬਾਈਟਾਂ);
  WINBASEAPI LPVOID WINAPI ਢੇਰ_Re_Alloc(HANDLE h_ਢੇਰ,DWORD dwFlags,LPVOID lpMem,ਮਾਪ_T dw_ਬਾਈਟਾਂ);
  WINBASEAPI WINBOOL WINAPI ਢੇਰ_Free(HANDLE h_ਢੇਰ,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI ਮਾਪ_T WINAPI ਢੇਰ_ਮਾਪ_3(HANDLE h_ਢੇਰ,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI ਢੇਰ_Validate(HANDLE h_ਢੇਰ,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI ਮਾਪ_T WINAPI ਢੇਰ_Compact(HANDLE h_ਢੇਰ,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI Get_Process_ਢੇਰ(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD ਸੰਖਿਆ_ਦਾ_Heaps,PHANDLE ProcessHeaps);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ PROCESS_ਢੇਰ_ਇੰਦਰਾਜ {
    PVOID lp_ਅੰਕੜੇ;
    DWORD cb_ਅੰਕੜੇ;
    BYTE cbOverhead;
    BYTE i_Region_ਸੂਚਕਾਂਕ;
    ਸ਼ਬਦ_3 wFlags;
    ਸੰਘ {
      ਬਣਤਰ {
	HANDLE hMem;
	DWORD dwReserved[3];
      } ਖੰਡ_2;
      ਬਣਤਰ {
	DWORD dw_Committed_ਮਾਪ;
	DWORD dw_Un_Committed_ਮਾਪ;
	LPVOID lp_ਪਹਿਲਾ_ਖੰਡ;
	LPVOID lp_ਆਖਰੀ_ਖੰਡ;
      } Region;
    };
  } PROCESS_ਢੇਰ_ਇੰਦਰਾਜ_2,*LPPROCESS_ਢੇਰ_ਇੰਦਰਾਜ,*PPROCESS_ਢੇਰ_ਇੰਦਰਾਜ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ਢੇਰ_REGION 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ਢੇਰ_UNCOMMITTED_RANGE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ਢੇਰ_ਇੰਦਰਾਜ_BUSY 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ਢੇਰ_ਇੰਦਰਾਜ_MOVEABLE 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROCESS_ਢੇਰ_ਇੰਦਰਾਜ_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI ਢੇਰ_ਤਾਲਾ(HANDLE h_ਢੇਰ);
  WINBASEAPI WINBOOL WINAPI ਢੇਰ_Unlock(HANDLE h_ਢੇਰ);
  WINBASEAPI WINBOOL WINAPI ਢੇਰ_Walk(HANDLE h_ਢੇਰ,LPPROCESS_ਢੇਰ_ਇੰਦਰਾਜ lp_ਇੰਦਰਾਜ);
  WINBASEAPI WINBOOL WINAPI ਢੇਰ_ਸੈੱਟ_Information(HANDLE ਢੇਰ_Handle,ਢੇਰ_INFORMATION_CLASS ਢੇਰ_Information_Class,PVOID ਢੇਰ_Information,ਮਾਪ_T ਢੇਰ_Information_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI ਢੇਰ_Query_Information(HANDLE ਢੇਰ_Handle,ਢੇਰ_INFORMATION_CLASS ਢੇਰ_Information_Class,PVOID ਢੇਰ_Information,ਮਾਪ_T ਢੇਰ_Information_ਲੰਮਾਈ,PSIZE_T Return_ਲੰਮਾਈ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCS_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਦੁਆਧਾਰੀ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCS_DOS_ਦੁਆਧਾਰੀ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCS_WOW_ਦੁਆਧਾਰੀ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCS_PIF_ਦੁਆਧਾਰੀ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCS_POSIX_ਦੁਆਧਾਰੀ 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCS_OS216_ਦੁਆਧਾਰੀ 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCS_64_ਦੋਆਧਾਰੀ_ਅੰਕ_ਦੁਆਧਾਰੀ 6

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਦੁਆਧਾਰੀ_Type Get_ਦੁਆਧਾਰੀ_Type_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Short_ਰਸਤਾ_Name Get_Short_ਰਸਤਾ_Name_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Long_ਰਸਤਾ_Name Get_Long_ਰਸਤਾ_Name_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Environment_ਲੜੀਆਂ Get_Environment_ਲੜੀਆਂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Environment_ਲੜੀਆਂ ਸੈੱਟ_Environment_ਲੜੀਆਂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Free_Environment_ਲੜੀਆਂ Free_Environment_ਲੜੀਆਂ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਦੁਆਧਾਰੀ_Type Get_ਦੁਆਧਾਰੀ_Type_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Short_ਰਸਤਾ_Name Get_Short_ਰਸਤਾ_Name_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Long_ਰਸਤਾ_Name Get_Long_ਰਸਤਾ_Name_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Environment_ਲੜੀਆਂ_A Get_Environment_ਲੜੀਆਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Environment_ਲੜੀਆਂ ਸੈੱਟ_Environment_ਲੜੀਆਂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Free_Environment_ਲੜੀਆਂ Free_Environment_ਲੜੀਆਂ_A
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCS_THIS_PLATFORM_ਦੁਆਧਾਰੀ SCS_64_ਦੋਆਧਾਰੀ_ਅੰਕ_ਦੁਆਧਾਰੀ
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCS_THIS_PLATFORM_ਦੁਆਧਾਰੀ SCS_32_ਦੋਆਧਾਰੀ_ਅੰਕ_ਦੁਆਧਾਰੀ
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI Get_ਦੁਆਧਾਰੀ_Type_A(LPCSTR lpApplicationName,LPDWORD lp_ਦੁਆਧਾਰੀ_Type);
  WINBASEAPI WINBOOL WINAPI Get_ਦੁਆਧਾਰੀ_Type_W(LPCWSTR lpApplicationName,LPDWORD lp_ਦੁਆਧਾਰੀ_Type);
  WINBASEAPI DWORD WINAPI Get_Short_ਰਸਤਾ_Name_A(LPCSTR lpsz_Long_ਰਸਤਾ,LPSTR lpsz_Short_ਰਸਤਾ,DWORD cch_ਬਫਰ);
  WINBASEAPI DWORD WINAPI Get_Short_ਰਸਤਾ_Name_W(LPCWSTR lpsz_Long_ਰਸਤਾ,LPWSTR lpsz_Short_ਰਸਤਾ,DWORD cch_ਬਫਰ);
  WINBASEAPI DWORD WINAPI Get_Long_ਰਸਤਾ_Name_A(LPCSTR lpsz_Short_ਰਸਤਾ,LPSTR lpsz_Long_ਰਸਤਾ,DWORD cch_ਬਫਰ);
  WINBASEAPI DWORD WINAPI Get_Long_ਰਸਤਾ_Name_W(LPCWSTR lpsz_Short_ਰਸਤਾ,LPWSTR lpsz_Long_ਰਸਤਾ,DWORD cch_ਬਫਰ);
  WINBASEAPI WINBOOL WINAPI Get_Process_Affinity_ਨਕਾਬ(HANDLE hProcess,PDWORD_PTR lp_Process_Affinity_ਨਕਾਬ,PDWORD_PTR lp_System_Affinity_ਨਕਾਬ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Process_Affinity_ਨਕਾਬ(HANDLE hProcess,DWORD_PTR dw_Process_Affinity_ਨਕਾਬ);
  WINBASEAPI WINBOOL WINAPI Get_Process_Handle_ਗਿਣਤੀ(HANDLE hProcess,PDWORD pdw_Handle_ਗਿਣਤੀ);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lp_Creation_ਸਮਾਂ,LPFILETIME lp_Exit_ਸਮਾਂ,LPFILETIME lp_Kernel_ਸਮਾਂ,LPFILETIME lp_User_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_ਸੈੱਟ_ਮਾਪ(HANDLE hProcess,PSIZE_T lp_Minimum_Working_ਸੈੱਟ_ਮਾਪ,PSIZE_T lp_ਵੱਧ_ਤੋਂ_ਵੱਧ_Working_ਸੈੱਟ_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_ਸੈੱਟ_ਮਾਪ_Ex(HANDLE hProcess,PSIZE_T lp_Minimum_Working_ਸੈੱਟ_ਮਾਪ,PSIZE_T lp_ਵੱਧ_ਤੋਂ_ਵੱਧ_Working_ਸੈੱਟ_ਮਾਪ,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Process_Working_ਸੈੱਟ_ਮਾਪ(HANDLE hProcess,ਮਾਪ_T dw_Minimum_Working_ਸੈੱਟ_ਮਾਪ,ਮਾਪ_T dw_ਵੱਧ_ਤੋਂ_ਵੱਧ_Working_ਸੈੱਟ_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Process_Working_ਸੈੱਟ_ਮਾਪ_Ex(HANDLE hProcess,ਮਾਪ_T dw_Minimum_Working_ਸੈੱਟ_ਮਾਪ,ਮਾਪ_T dw_ਵੱਧ_ਤੋਂ_ਵੱਧ_Working_ਸੈੱਟ_ਮਾਪ,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT u_Exit_ਕੋਡ);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT u_Exit_ਕੋਡ);
  WINBASEAPI WINBOOL WINAPI Get_Exit_ਕੋਡ_Process(HANDLE hProcess,LPDWORD lp_Exit_ਕੋਡ);
  WINBASEAPI VOID WINAPI FatalExit(ਪੂਰਨ Exit_ਕੋਡ);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI Get_Environment_ਲੜੀਆਂ_W(VOID);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Environment_ਲੜੀਆਂ_A(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Environment_ਲੜੀਆਂ_W(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI Free_Environment_ਲੜੀਆਂ_A(LPCH);
  WINBASEAPI WINBOOL WINAPI Free_Environment_ਲੜੀਆਂ_W(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dw_Exception_ਕੋਡ,DWORD dwExceptionFlags,DWORD n_ਸੰਖਿਆ_ਦਾ_Arguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2 *ExceptionInfo);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(ਬਣਤਰ EXCEPTION_ਸੂਚਕ_ਸਾਰੇ_2 *ExceptionInfo);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI ਸੈੱਟ_Unhandled_Exception_Filter(LPTOP_LEVEL_EXCEPTION_FILTER lp_ਸਿਖਰ_Level_Exception_Filter);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(ਮਾਪ_T dw_ਢੇਰ_ਮਾਪ,LPFIBER_ਸ਼ੁਰੂ_ROUTINE lp_ਸ਼ੁਰੂ_ਪਤਾ,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(ਮਾਪ_T dw_ਢੇਰ_Commit_ਮਾਪ,ਮਾਪ_T dw_ਢੇਰ_Reserve_ਮਾਪ,DWORD dwFlags,LPFIBER_ਸ਼ੁਰੂ_ROUTINE lp_ਸ਼ੁਰੂ_ਪਤਾ,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI Convert_Thread_ਮੰਜ਼ਿਲ_Fiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI Convert_Thread_ਮੰਜ਼ਿਲ_Fiber_Ex(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Convert_Fiber_ਮੰਜ਼ਿਲ_Thread(VOID);
  WINBASEAPI VOID WINAPI Switch_ਮੰਜ਼ਿਲ_Fiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI Switch_ਮੰਜ਼ਿਲ_Thread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ਗੁਣ lp_Thread_ਗੁਣ,ਮਾਪ_T dw_ਢੇਰ_ਮਾਪ,LPTHREAD_ਸ਼ੁਰੂ_ROUTINE lp_ਸ਼ੁਰੂ_ਪਤਾ,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_ਗੁਣ lp_Thread_ਗੁਣ,ਮਾਪ_T dw_ਢੇਰ_ਮਾਪ,LPTHREAD_ਸ਼ੁਰੂ_ROUTINE lp_ਸ਼ੁਰੂ_ਪਤਾ,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Thread_ਢੇਰ_Guarantee (PULONG ਢੇਰ_ਮਾਪ_ਵਿੱਚ_ਬਾਈਟਾਂ);
  WINBASEAPI DWORD WINAPI Get_Process_Id_ਦਾ_Thread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI Get_Current_Processor_ਸੰਖਿਆ(VOID);
  WINBASEAPI DWORD_PTR WINAPI ਸੈੱਟ_Thread_Affinity_ਨਕਾਬ(HANDLE hThread,DWORD_PTR dw_Thread_Affinity_ਨਕਾਬ);
  WINBASEAPI DWORD WINAPI ਸੈੱਟ_Thread_Ideal_Processor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Process_ਤਰਜੀਹ_Boost(HANDLE hProcess,WINBOOL b_Disable_ਤਰਜੀਹ_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Process_ਤਰਜੀਹ_Boost(HANDLE hProcess,PBOOL p_Disable_ਤਰਜੀਹ_Boost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_ਸਮਾਂ latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Thread_ਤਰਜੀਹ(HANDLE hThread,ਪੂਰਨ n_ਤਰਜੀਹ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Thread_ਤਰਜੀਹ_Boost(HANDLE hThread,WINBOOL b_Disable_ਤਰਜੀਹ_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Thread_ਤਰਜੀਹ_Boost(HANDLE hThread,PBOOL p_Disable_ਤਰਜੀਹ_Boost);
  WINBASEAPI ਪੂਰਨ WINAPI Get_Thread_ਤਰਜੀਹ(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lp_Creation_ਸਮਾਂ,LPFILETIME lp_Exit_ਸਮਾਂ,LPFILETIME lp_Kernel_ਸਮਾਂ,LPFILETIME lp_User_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dw_Exit_ਕੋਡ);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dw_Exit_ਕੋਡ);
  WINBASEAPI WINBOOL WINAPI Get_Exit_ਕੋਡ_Thread(HANDLE hThread,LPDWORD lp_Exit_ਕੋਡ);
  WINBASEAPI WINBOOL WINAPI Get_Thread_Selector_ਇੰਦਰਾਜ(HANDLE hThread,DWORD dwSelector,LPLDT_ਇੰਦਰਾਜ lp_Selector_ਇੰਦਰਾਜ);
  WINBASEAPI EXECUTION_STATE WINAPI ਸੈੱਟ_Thread_Execution_State(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI Get_ਆਖਰੀ_Error(VOID);
  WINBASEAPI VOID WINAPI ਸੈੱਟ_ਆਖਰੀ_Error(DWORD dw_Err_ਕੋਡ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ WINBASE_DECLARE_RESTORE_ਆਖਰੀ_ERROR
  WINBASEAPI VOID WINAPI Restore_ਆਖਰੀ_Error(DWORD dw_Err_ਕੋਡ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (WINAPI *PRESTORE_ਆਖਰੀ_ERROR)(DWORD);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RESTORE_ਆਖਰੀ_ERROR_NAME_A "RestoreLastError"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RESTORE_ਆਖਰੀ_ERROR_NAME_W L"RestoreLastError"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RESTORE_ਆਖਰੀ_ERROR_NAME ਪਾਠ_3("RestoreLastError")
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->ਅੰਦਰੂਨੀ)!=ਸਥਿਤੀ_PENDING)

  WINBASEAPI WINBOOL WINAPI Get_Overlapped_ਨਤੀਜਾ(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Transferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI Create_Io_Completion_ਪੋਰਟ(HANDLE FileHandle,HANDLE Existing_Completion_ਪੋਰਟ,ULONG_PTR Completion_ਕੁੰਜੀ,DWORD ਸੰਖਿਆ_ਦਾ_Concurrent_ਧਾਗੇ);
  WINBASEAPI WINBOOL WINAPI Get_Queued_Completion_ਸਥਿਤੀ(HANDLE Completion_ਪੋਰਟ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Transferred,PULONG_PTR lp_Completion_ਕੁੰਜੀ,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI Post_Queued_Completion_ਸਥਿਤੀ(HANDLE Completion_ਪੋਰਟ,DWORD dw_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Transferred,ULONG_PTR dw_Completion_ਕੁੰਜੀ,LPOVERLAPPED lpOverlapped);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEM_FAILCRITICALERRORS 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEM_NOGPFAULTERRORBOX 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEM_NOALIGNMENTFAULTEXCEPT 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI ਸੈੱਟ_Error_ਬਹੁਲਕ(UINT u_ਬਹੁਲਕ);
  WINBASEAPI WINBOOL WINAPI Read_Process_ਸਮ੍ਰਿਤੀ(HANDLE hProcess,LPCVOID lp_ਅਧਾਰ_ਪਤਾ,LPVOID lp_ਬਫਰ,ਮਾਪ_T n_ਮਾਪ,ਮਾਪ_T *lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Read);
  WINBASEAPI WINBOOL WINAPI Write_Process_ਸਮ੍ਰਿਤੀ(HANDLE hProcess,LPVOID lp_ਅਧਾਰ_ਪਤਾ,LPCVOID lp_ਬਫਰ,ਮਾਪ_T n_ਮਾਪ,ਮਾਪ_T *lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Written);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Thread_Context(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI ਕਤਾਰ_User_APC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dw_ਅੰਕੜੇ);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dw_Continue_ਸਥਿਤੀ);
  WINBASEAPI WINBOOL WINAPI Debug_ਸਰਗਰਮ_Process(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_ਸਰਗਰਮ_Process_Stop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_ਸੈੱਟ_Process_Kill_On_Exit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI Initialize_Critical_Section_And_Spin_ਗਿਣਤੀ(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_ਗਿਣਤੀ);
  WINBASEAPI DWORD WINAPI ਸੈੱਟ_Critical_Section_Spin_ਗਿਣਤੀ(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_ਗਿਣਤੀ);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Event(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG l_Release_ਗਿਣਤੀ,LPLONG lp_ਪਿਛਲਾ_ਗਿਣਤੀ);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI Wait_For_ਗੁਣਜ_Objects(DWORD n_ਗਿਣਤੀ,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI ਲੱਦੋ_Resource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI Init_Atom_ਸਾਰਣੀ(DWORD n_ਮਾਪ);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI ਸੈੱਟ_Handle_ਗਿਣਤੀ(UINT u_ਸੰਖਿਆ);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI ਤਾਲਾ_File(HANDLE hFile,DWORD dw_File_ਵਿੱਥ_ਨੀਵਾਂ,DWORD dw_File_ਵਿੱਥ_ਉੱਚਾ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_ਤਾਲਾ_ਨੀਵਾਂ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_ਤਾਲਾ_ਉੱਚਾ);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dw_File_ਵਿੱਥ_ਨੀਵਾਂ,DWORD dw_File_ਵਿੱਥ_ਉੱਚਾ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Unlock_ਨੀਵਾਂ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Unlock_ਉੱਚਾ);
  WINBASEAPI WINBOOL WINAPI ਤਾਲਾ_File_Ex(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_ਤਾਲਾ_ਨੀਵਾਂ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_ਤਾਲਾ_ਉੱਚਾ,LPOVERLAPPED lpOverlapped);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCKFILE_FAIL_IMMEDIATELY 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOCKFILE_EXCLUSIVE_ਤਾਲਾ 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Unlock_ਨੀਵਾਂ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Unlock_ਉੱਚਾ,LPOVERLAPPED lpOverlapped);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _BY_HANDLE_FILE_INFORMATION {
    DWORD dw_File_ਗੁਣ;
    FILETIME ft_Creation_ਸਮਾਂ;
    FILETIME ft_ਆਖਰੀ_Access_ਸਮਾਂ;
    FILETIME ft_ਆਖਰੀ_Write_ਸਮਾਂ;
    DWORD dw_Volume_Serial_ਸੰਖਿਆ;
    DWORD n_File_ਮਾਪ_ਉੱਚਾ;
    DWORD n_File_ਮਾਪ_ਨੀਵਾਂ;
    DWORD n_ਸੰਖਿਆ_ਦਾ_Links;
    DWORD n_File_ਸੂਚਕਾਂਕ_ਉੱਚਾ;
    DWORD n_File_ਸੂਚਕਾਂਕ_ਨੀਵਾਂ;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_File_Short_Name ਸੈੱਟ_File_Short_Name_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_File_Short_Name ਸੈੱਟ_File_Short_Name_A
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI Get_File_ਮਾਪ(HANDLE hFile,LPDWORD lp_File_ਮਾਪ_ਉੱਚਾ);
  WINBASEAPI WINBOOL WINAPI Get_File_ਮਾਪ_Ex(HANDLE hFile,PLARGE_INTEGER lp_File_ਮਾਪ);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Std_Handle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Write,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Written,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Read,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dw_Io_Control_ਕੋਡ,LPVOID lp_ਵਿੱਚ_ਬਫਰ,DWORD n_ਵਿੱਚ_ਬਫਰ_ਮਾਪ,LPVOID lp_ਬਾਹਰਲਾ_ਬਫਰ,DWORD n_ਬਾਹਰਲਾ_ਬਫਰ_ਮਾਪ,LPDWORD lp_ਬਾਈਟਾਂ_Returned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_ਸੁਨੇਹਾ_ਉਡੀਕ_Indicator(HANDLE h_ਸੁਨੇਹਾ_Indicator,ULONG ul_ਸੁਨੇਹਾ_ਗਿਣਤੀ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_ਸਿਰਾ_ਦਾ_File(HANDLE hFile);
  WINBASEAPI DWORD WINAPI ਸੈੱਟ_File_ਸੂਚਕ(HANDLE hFile,LONG l_ਦੂਰੀ_ਮੰਜ਼ਿਲ_Move,PLONG lp_ਦੂਰੀ_ਮੰਜ਼ਿਲ_Move_ਉੱਚਾ,DWORD dw_Move_ਵਿਧੀ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_File_ਸੂਚਕ_Ex(HANDLE hFile,LARGE_INTEGER li_ਦੂਰੀ_ਮੰਜ਼ਿਲ_Move,PLARGE_INTEGER lp_New_File_ਸੂਚਕ,DWORD dw_Move_ਵਿਧੀ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_Close(HANDLE h_ਲੱਭੋ_File);
  WINBASEAPI WINBOOL WINAPI Get_File_ਸਮਾਂ(HANDLE hFile,LPFILETIME lp_Creation_ਸਮਾਂ,LPFILETIME lp_ਆਖਰੀ_Access_ਸਮਾਂ,LPFILETIME lp_ਆਖਰੀ_Write_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_File_ਸਮਾਂ(HANDLE hFile,CONST FILETIME *lp_Creation_ਸਮਾਂ,CONST FILETIME *lp_ਆਖਰੀ_Access_ਸਮਾਂ,CONST FILETIME *lp_ਆਖਰੀ_Write_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_File_Valid_ਅੰਕੜੇ(HANDLE hFile,LONGLONG Valid_ਅੰਕੜੇ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_File_Short_Name_A(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_File_Short_Name_W(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE h_ਸਰੋਤ_Process_Handle,HANDLE h_ਸਰੋਤ_Handle,HANDLE h_ਨਿਸ਼ਾਨਾ_Process_Handle,LPHANDLE lp_ਨਿਸ਼ਾਨਾ_Handle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Handle_Information(HANDLE hObject,DWORD dw_ਨਕਾਬ,DWORD dwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HANDLE_FLAG_INHERIT 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI ਲੱਦੋ_Module(LPCSTR lpModuleName,LPVOID lp_Parameter_ਖੰਡ);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lp_Cmd_ਸਤਰ,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI ਤਿਆਰੀ_Comm(HANDLE hFile,DWORD dw_ਵਿੱਚ_ਕਤਾਰ,DWORD dw_ਬਾਹਰਲਾ_ਕਤਾਰ);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdw_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI Get_Comm_ਨਕਾਬ(HANDLE hFile,LPDWORD lp_Evt_ਨਕਾਬ);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI Get_Comm_Modem_ਸਥਿਤੀ(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Comm_Break(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Comm_Config(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dw_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Comm_ਨਕਾਬ(HANDLE hFile,DWORD dw_Evt_ਨਕਾਬ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Comm_State(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Comm_Timeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,ਅੱਖਰ cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lp_Evt_ਨਕਾਬ,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI ਸੈੱਟ_ਫੀਤਾ_Position(HANDLE hDevice,DWORD dw_Position_ਵਿਧੀ,DWORD dw_ਹਿੱਸੇ_ਕਰੋ,DWORD dw_ਵਿੱਥ_ਨੀਵਾਂ,DWORD dw_ਵਿੱਥ_ਉੱਚਾ,WINBOOL b_ਤੁਰੰਤ);
  WINBASEAPI DWORD WINAPI Get_ਫੀਤਾ_Position(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdw_ਹਿੱਸੇ_ਕਰੋ,LPDWORD lpdw_ਵਿੱਥ_ਨੀਵਾਂ,LPDWORD lpdw_ਵਿੱਥ_ਉੱਚਾ);
  WINBASEAPI DWORD WINAPI Prepare_ਫੀਤਾ(HANDLE hDevice,DWORD dwOperation,WINBOOL b_ਤੁਰੰਤ);
  WINBASEAPI DWORD WINAPI Erase_ਫੀਤਾ(HANDLE hDevice,DWORD dwEraseType,WINBOOL b_ਤੁਰੰਤ);
  WINBASEAPI DWORD WINAPI Create_ਫੀਤਾ_ਹਿੱਸੇ_ਕਰੋ(HANDLE hDevice,DWORD dw_ਹਿੱਸੇ_ਕਰੋ_ਵਿਧੀ,DWORD dw_ਗਿਣਤੀ,DWORD dw_ਮਾਪ);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dw_Tapemark_ਗਿਣਤੀ,WINBOOL b_ਤੁਰੰਤ);
  WINBASEAPI DWORD WINAPI Get_ਫੀਤਾ_ਸਥਿਤੀ(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI Get_ਫੀਤਾ_Parameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdw_ਮਾਪ,LPVOID lp_ਫੀਤਾ_Information);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_ਫੀਤਾ_MEDIA_INFORMATION 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_ਫੀਤਾ_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI ਸੈੱਟ_ਫੀਤਾ_Parameters(HANDLE hDevice,DWORD dwOperation,LPVOID lp_ਫੀਤਾ_Information);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਫੀਤਾ_MEDIA_INFORMATION 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਫੀਤਾ_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI ਪੂਰਨ WINAPI MulDiv(ਪੂਰਨ n_ਸੰਖਿਆ,ਪੂਰਨ nNumerator,ਪੂਰਨ nDenominator);
  WINBASEAPI VOID WINAPI Get_System_ਸਮਾਂ(LPSYSTEMTIME lp_System_ਸਮਾਂ);
  WINBASEAPI VOID WINAPI Get_System_ਸਮਾਂ_As_File_ਸਮਾਂ(LPFILETIME lp_System_ਸਮਾਂ_As_File_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_System_ਸਮਾਂ(CONST SYSTEMTIME *lp_System_ਸਮਾਂ);
  WINBASEAPI VOID WINAPI Get_Local_ਸਮਾਂ(LPSYSTEMTIME lp_System_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Local_ਸਮਾਂ(CONST SYSTEMTIME *lp_System_ਸਮਾਂ);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_System_File_Cache_ਮਾਪ(ਮਾਪ_T Minimum_File_Cache_ਮਾਪ,ਮਾਪ_T ਵੱਧ_ਤੋਂ_ਵੱਧ_File_Cache_ਮਾਪ,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI Get_System_File_Cache_ਮਾਪ(PSIZE_T lp_Minimum_File_Cache_ਮਾਪ,PSIZE_T lp_ਵੱਧ_ਤੋਂ_ਵੱਧ_File_Cache_ਮਾਪ,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdw_Quota_ਵਰਤਿਆ);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lp_Idle_ਸਮਾਂ,LPFILETIME lp_Kernel_ਸਮਾਂ,LPFILETIME lp_User_ਸਮਾਂ);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸਮਾਂ_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } ਸਮਾਂ_ZONE_INFORMATION_2,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Format_ਸੁਨੇਹਾ Format_ਸੁਨੇਹਾ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Format_ਸੁਨੇਹਾ Format_ਸੁਨੇਹਾ_A
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI System_ਸਮਾਂ_ਮੰਜ਼ਿਲ_Tz_Specific_Local_ਸਮਾਂ(LPTIME_ZONE_INFORMATION lp_ਸਮਾਂ_Zone_Information,LPSYSTEMTIME lp_Universal_ਸਮਾਂ,LPSYSTEMTIME lp_Local_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI Tz_Specific_Local_ਸਮਾਂ_ਮੰਜ਼ਿਲ_System_ਸਮਾਂ(LPTIME_ZONE_INFORMATION lp_ਸਮਾਂ_Zone_Information,LPSYSTEMTIME lp_Local_ਸਮਾਂ,LPSYSTEMTIME lp_Universal_ਸਮਾਂ);
  WINBASEAPI DWORD WINAPI Get_ਸਮਾਂ_Zone_Information(LPTIME_ZONE_INFORMATION lp_ਸਮਾਂ_Zone_Information);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_ਸਮਾਂ_Zone_Information(CONST ਸਮਾਂ_ZONE_INFORMATION_2 *lp_ਸਮਾਂ_Zone_Information);
  WINBASEAPI WINBOOL WINAPI System_ਸਮਾਂ_ਮੰਜ਼ਿਲ_File_ਸਮਾਂ(CONST SYSTEMTIME *lp_System_ਸਮਾਂ,LPFILETIME lp_File_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI File_ਸਮਾਂ_ਮੰਜ਼ਿਲ_Local_File_ਸਮਾਂ(CONST FILETIME *lp_File_ਸਮਾਂ,LPFILETIME lp_Local_File_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI Local_File_ਸਮਾਂ_ਮੰਜ਼ਿਲ_File_ਸਮਾਂ(CONST FILETIME *lp_Local_File_ਸਮਾਂ,LPFILETIME lp_File_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI File_ਸਮਾਂ_ਮੰਜ਼ਿਲ_System_ਸਮਾਂ(CONST FILETIME *lp_File_ਸਮਾਂ,LPSYSTEMTIME lp_System_ਸਮਾਂ);
  WINBASEAPI LONG WINAPI Compare_File_ਸਮਾਂ(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI File_ਸਮਾਂ_ਮੰਜ਼ਿਲ_Dos_Date_ਸਮਾਂ(CONST FILETIME *lp_File_ਸਮਾਂ,LPWORD lpFatDate,LPWORD lp_Fat_ਸਮਾਂ);
  WINBASEAPI WINBOOL WINAPI Dos_Date_ਸਮਾਂ_ਮੰਜ਼ਿਲ_File_ਸਮਾਂ(ਸ਼ਬਦ_3 wFatDate,ਸ਼ਬਦ_3 w_Fat_ਸਮਾਂ,LPFILETIME lp_File_ਸਮਾਂ);
  WINBASEAPI DWORD WINAPI Get_Tick_ਗਿਣਤੀ(VOID);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_System_ਸਮਾਂ_Adjustment(DWORD dw_ਸਮਾਂ_Adjustment,WINBOOL b_ਸਮਾਂ_Adjustment_Disabled);
  WINBASEAPI WINBOOL WINAPI Get_System_ਸਮਾਂ_Adjustment(PDWORD lp_ਸਮਾਂ_Adjustment,PDWORD lp_ਸਮਾਂ_Increment,PBOOL lp_ਸਮਾਂ_Adjustment_Disabled);
  WINBASEAPI DWORD WINAPI Format_ਸੁਨੇਹਾ_A(DWORD dwFlags,LPCVOID lp_ਸਰੋਤ,DWORD dw_ਸੁਨੇਹਾ_Id,DWORD dwLanguageId,LPSTR lp_ਬਫਰ,DWORD n_ਮਾਪ,va_list *Arguments);
  WINBASEAPI DWORD WINAPI Format_ਸੁਨੇਹਾ_W(DWORD dwFlags,LPCVOID lp_ਸਰੋਤ,DWORD dw_ਸੁਨੇਹਾ_Id,DWORD dwLanguageId,LPWSTR lp_ਬਫਰ,DWORD n_ਮਾਪ,va_list *Arguments);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FORMAT_ਸੁਨੇਹਾ_ALLOCATE_ਬਫਰ 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FORMAT_ਸੁਨੇਹਾ_IGNORE_INSERTS 0x200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FORMAT_ਸੁਨੇਹਾ_FROM_STRING 0x400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FORMAT_ਸੁਨੇਹਾ_FROM_HMODULE 0x800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FORMAT_ਸੁਨੇਹਾ_FROM_SYSTEM 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FORMAT_ਸੁਨੇਹਾ_ਦਲੀਲ_ARRAY 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FORMAT_ਸੁਨੇਹਾ_MAX_ਚੌੜਾਈ_ਨਕਾਬ 0xff

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateMailslot CreateMailslotW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EncryptFile EncryptFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DecryptFile DecryptFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ File_Encryption_ਸਥਿਤੀ File_Encryption_ਸਥਿਤੀ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateMailslot CreateMailslotA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EncryptFile EncryptFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DecryptFile DecryptFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ File_Encryption_ਸਥਿਤੀ File_Encryption_ਸਥਿਤੀ_A
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_ਗੁਣ lp_Pipe_ਗੁਣ,DWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Named_Pipe_Handle_State(HANDLE hNamedPipe,LPDWORD lp_ਬਹੁਲਕ,LPDWORD lp_Max_Collection_ਗਿਣਤੀ,LPDWORD lp_Collect_ਅੰਕੜੇ_Timeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lp_ਬਾਹਰਲਾ_ਬਫਰ_ਮਾਪ,LPDWORD lp_ਵਿੱਚ_ਬਫਰ_ਮਾਪ,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lp_ਬਫਰ,DWORD n_ਬਫਰ_ਮਾਪ,LPDWORD lp_ਬਾਈਟਾਂ_Read,LPDWORD lp_ਕੁੱਲ_ਬਾਈਟਾਂ_Avail,LPDWORD lp_ਬਾਈਟਾਂ_ਖੱਬਾ_This_ਸੁਨੇਹਾ);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lp_ਵਿੱਚ_ਬਫਰ,DWORD n_ਵਿੱਚ_ਬਫਰ_ਮਾਪ,LPVOID lp_ਬਾਹਰਲਾ_ਬਫਰ,DWORD n_ਬਾਹਰਲਾ_ਬਫਰ_ਮਾਪ,LPDWORD lp_ਬਾਈਟਾਂ_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD n_Max_ਸੁਨੇਹਾ_ਮਾਪ,DWORD lReadTimeout,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD n_Max_ਸੁਨੇਹਾ_ਮਾਪ,DWORD lReadTimeout,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lp_Max_ਸੁਨੇਹਾ_ਮਾਪ,LPDWORD lp_ਅਗਲਾ_ਮਾਪ,LPDWORD lp_ਸੁਨੇਹਾ_ਗਿਣਤੀ,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Mailslot_Info(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI Map_View_ਦਾ_File(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_ਵਿੱਥ_ਉੱਚਾ,DWORD dw_File_ਵਿੱਥ_ਨੀਵਾਂ,ਮਾਪ_T dw_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Map);
  WINBASEAPI WINBOOL WINAPI Flush_View_ਦਾ_File(LPCVOID lp_ਅਧਾਰ_ਪਤਾ,ਮਾਪ_T dw_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Flush);
  WINBASEAPI WINBOOL WINAPI Unmap_View_ਦਾ_File(LPCVOID lp_ਅਧਾਰ_ਪਤਾ);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ENCRYPTABLE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_IS_ENCRYPTED 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SYSTEM_ATTR 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_ਜੜ੍ਹ_DIR 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SYSTEM_DIR 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_UNKNOWN 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_SYSTEM_NOT_SUPPORT 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_USER_DISALLOWED 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_READ_ONLY 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI File_Encryption_ਸਥਿਤੀ_A(LPCSTR lpFileName,LPDWORD lp_ਸਥਿਤੀ);
  WINADVAPI WINBOOL WINAPI File_Encryption_ਸਥਿਤੀ_W(LPCWSTR lpFileName,LPDWORD lp_ਸਥਿਤੀ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EFS_USE_RECOVERY_ਕੁੰਜੀਆਂ (0x1)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pb_ਅੰਕੜੇ,PVOID pvCallbackContext,ULONG ul_ਲੰਮਾਈ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pb_ਅੰਕੜੇ,PVOID pvCallbackContext,PULONG ul_ਲੰਮਾਈ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_FOR_IMPORT (1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATE_FOR_DIR (2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OVERWRITE_HIDDEN (4)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenEncryptedFileRaw OpenEncryptedFileRawW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcmp lstrcmpW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcmpi lstrcmpiW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcpyn lstrcpynW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcpy lstrcpyW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcat lstrcatW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrlen lstrlenW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenEncryptedFileRaw OpenEncryptedFileRawA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcmp lstrcmpA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcmpi lstrcmpiA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcpyn lstrcpynA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcpy lstrcpyA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrcat lstrcatA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ lstrlen lstrlenA
#ਜੇ_ਅੰਤ

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI ਪੂਰਨ WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI ਪੂਰਨ WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI ਪੂਰਨ WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI ਪੂਰਨ WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,ਪੂਰਨ i_Max_ਲੰਮਾਈ);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,ਪੂਰਨ i_Max_ਲੰਮਾਈ);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI ਪੂਰਨ WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI ਪੂਰਨ WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lp_ਰਸਤਾ_Name,ਪੂਰਨ iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lp_ਰਸਤਾ_Name,ਪੂਰਨ iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lp_ਬਫਰ,UINT u_ਬਾਈਟਾਂ);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lp_ਬਫਰ,UINT u_ਬਾਈਟਾਂ);
  WINBASEAPI ਲੰਮਾ WINAPI _hread(HFILE hFile,LPVOID lp_ਬਫਰ,ਲੰਮਾ l_ਬਾਈਟਾਂ);
  WINBASEAPI ਲੰਮਾ WINAPI _hwrite(HFILE hFile,LPCCH lp_ਬਫਰ,ਲੰਮਾ l_ਬਾਈਟਾਂ);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG l_ਵਿੱਥ,ਪੂਰਨ iOrigin);
  WINADVAPI WINBOOL WINAPI Is_ਪਾਠ_Unicode(CONST VOID *lpv,ਪੂਰਨ i_ਮਾਪ,LPINT lpi_ਨਤੀਜਾ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLS_ਬਾਹਰਲਾ_ਦਾ_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI Fls_Get_ਮੁੱਲ(DWORD dw_Fls_ਸੂਚਕਾਂਕ);
  WINBASEAPI WINBOOL WINAPI Fls_ਸੈੱਟ_ਮੁੱਲ(DWORD dw_Fls_ਸੂਚਕਾਂਕ,PVOID lp_Fls_ਅੰਕੜੇ);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dw_Fls_ਸੂਚਕਾਂਕ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TLS_ਬਾਹਰਲਾ_ਦਾ_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI Tls_Get_ਮੁੱਲ(DWORD dw_Tls_ਸੂਚਕਾਂਕ);
  WINBASEAPI WINBOOL WINAPI Tls_ਸੈੱਟ_ਮੁੱਲ(DWORD dw_Tls_ਸੂਚਕਾਂਕ,LPVOID lp_Tls_ਮੁੱਲ);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dw_Tls_ਸੂਚਕਾਂਕ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dw_Error_ਕੋਡ,DWORD dw_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Transfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI Wait_For_ਗੁਣਜ_Objects_Ex(DWORD n_ਗਿਣਤੀ,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE h_Object_ਮੰਜ਼ਿਲ_Signal,HANDLE h_Object_ਮੰਜ਼ਿਲ_Wait_On,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Read,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Write,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Read,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Read,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dw_ਨੀਵਾਂ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Seek,DWORD dw_ਉੱਚਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Seek,LPDWORD lpdw_ਨੀਵਾਂ_Byte_Seeked,LPDWORD lpdw_ਉੱਚਾ_Byte_Seeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Write,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Written,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ WIN32_ਧਾਰਾ_ID {
    DWORD dw_ਧਾਰਾ_Id;
    DWORD dw_ਧਾਰਾ_ਗੁਣ;
    LARGE_INTEGER ਮਾਪ_3;
    DWORD dw_ਧਾਰਾ_Name_ਮਾਪ;
    WCHAR c_ਧਾਰਾ_Name[ANYSIZE_ARRAY];
  } WIN32_ਧਾਰਾ_ID_2,*LPWIN32_ਧਾਰਾ_ID;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_INVALID 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_ਅੰਕੜੇ 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_EA_ਅੰਕੜੇ 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_SECURITY_ਅੰਕੜੇ 0x3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_ALTERNATE_ਅੰਕੜੇ 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_LINK 0x5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_PROPERTY_ਅੰਕੜੇ 0x6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_OBJECT_ID 0x7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_REPARSE_ਅੰਕੜੇ 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKUP_SPARSE_ਖੰਡ 0x9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਧਾਰਾ_ਸਾਧਾਰਨ_ATTRIBUTE 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਧਾਰਾ_MODIFIED_WHEN_READ 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਧਾਰਾ_ਸ਼ਾਮਲ_ਹੈ_SECURITY 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਧਾਰਾ_ਸ਼ਾਮਲ_ਹੈ_PROPERTIES 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਧਾਰਾ_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Read,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Write,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_USESHOWWINDOW 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_USESIZE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_USEPOSITION 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_USECOUNTCHARS 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_USEFILLATTRIBUTE 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_RUNFULLSCREEN 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_FORCEONFEEDBACK 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_FORCEOFFFEEDBACK 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_USESTDHANDLES 0x100

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTF_USEHOTKEY 0x200

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _STARTUPINFOA {
    DWORD cb;
    LPSTR lpReserved;
    LPSTR lpDesktop;
    LPSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    ਸ਼ਬਦ_3 w_Show_ਖਿੜਕੀ;
    ਸ਼ਬਦ_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_ਨਿਵੇਸ਼;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOA,*LPSTARTUPINFOA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _STARTUPINFOW {
    DWORD cb;
    LPWSTR lpReserved;
    LPWSTR lpDesktop;
    LPWSTR lpTitle;
    DWORD dwX;
    DWORD dwY;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwXCountChars;
    DWORD dwYCountChars;
    DWORD dwFillAttribute;
    DWORD dwFlags;
    ਸ਼ਬਦ_3 w_Show_ਖਿੜਕੀ;
    ਸ਼ਬਦ_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_ਨਿਵੇਸ਼;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ STARTUPINFOW STARTUPINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPSTARTUPINFOW LPSTARTUPINFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ STARTUPINFOA STARTUPINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPSTARTUPINFOA LPSTARTUPINFO;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHUTDOWN_NORETRY 0x1

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ WIN32_ਲੱਭੋ_DATAA {
    DWORD dw_File_ਗੁਣ;
    FILETIME ft_Creation_ਸਮਾਂ;
    FILETIME ft_ਆਖਰੀ_Access_ਸਮਾਂ;
    FILETIME ft_ਆਖਰੀ_Write_ਸਮਾਂ;
    DWORD n_File_ਮਾਪ_ਉੱਚਾ;
    DWORD n_File_ਮਾਪ_ਨੀਵਾਂ;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_ਰਸਤਾ];
    CHAR cAlternateFileName[14];
  } WIN32_ਲੱਭੋ_DATAA_2,*PWIN32_ਲੱਭੋ_DATAA,*LPWIN32_ਲੱਭੋ_DATAA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ WIN32_ਲੱਭੋ_DATAW {
    DWORD dw_File_ਗੁਣ;
    FILETIME ft_Creation_ਸਮਾਂ;
    FILETIME ft_ਆਖਰੀ_Access_ਸਮਾਂ;
    FILETIME ft_ਆਖਰੀ_Write_ਸਮਾਂ;
    DWORD n_File_ਮਾਪ_ਉੱਚਾ;
    DWORD n_File_ਮਾਪ_ਨੀਵਾਂ;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_ਰਸਤਾ];
    WCHAR cAlternateFileName[14];
  } WIN32_ਲੱਭੋ_DATAW_2,*PWIN32_ਲੱਭੋ_DATAW,*LPWIN32_ਲੱਭੋ_DATAW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WIN32_ਲੱਭੋ_DATAW_2 WIN32_ਲੱਭੋ_ਅੰਕੜੇ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWIN32_ਲੱਭੋ_DATAW PWIN32_ਲੱਭੋ_ਅੰਕੜੇ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWIN32_ਲੱਭੋ_DATAW LPWIN32_ਲੱਭੋ_ਅੰਕੜੇ;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WIN32_ਲੱਭੋ_DATAA_2 WIN32_ਲੱਭੋ_ਅੰਕੜੇ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWIN32_ਲੱਭੋ_DATAA PWIN32_ਲੱਭੋ_ਅੰਕੜੇ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWIN32_ਲੱਭੋ_DATAA LPWIN32_ਲੱਭੋ_ਅੰਕੜੇ;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ WIN32_FILE_ATTRIBUTE_ਅੰਕੜੇ {
    DWORD dw_File_ਗੁਣ;
    FILETIME ft_Creation_ਸਮਾਂ;
    FILETIME ft_ਆਖਰੀ_Access_ਸਮਾਂ;
    FILETIME ft_ਆਖਰੀ_Write_ਸਮਾਂ;
    DWORD n_File_ਮਾਪ_ਉੱਚਾ;
    DWORD n_File_ਮਾਪ_ਨੀਵਾਂ;
  } WIN32_FILE_ATTRIBUTE_ਅੰਕੜੇ_2,*LPWIN32_FILE_ATTRIBUTE_ਅੰਕੜੇ;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateMutex CreateMutexW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenMutex OpenMutexW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateEvent CreateEventW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenEvent OpenEventW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateSemaphore CreateSemaphoreW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenSemaphore OpenSemaphoreW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateMutex CreateMutexA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenMutex OpenMutexA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateEvent CreateEventA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenEvent OpenEventA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateSemaphore CreateSemaphoreA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenSemaphore OpenSemaphoreA
#ਜੇ_ਅੰਤ

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_ਗੁਣ lp_Mutex_ਗੁਣ,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_ਗੁਣ lp_Mutex_ਗੁਣ,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_ਗੁਣ lp_Event_ਗੁਣ,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_ਗੁਣ lp_Event_ਗੁਣ,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ਗੁਣ lp_Semaphore_ਗੁਣ,LONG l_Initial_ਗਿਣਤੀ,LONG l_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਗਿਣਤੀ,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ਗੁਣ lp_Semaphore_ਗੁਣ,LONG l_Initial_ਗਿਣਤੀ,LONG l_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਗਿਣਤੀ,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lp_Arg_ਮੰਜ਼ਿਲ_Completion_Routine,DWORD dw_Timer_ਨੀਵਾਂ_ਮੁੱਲ,DWORD dw_Timer_ਉੱਚਾ_ਮੁੱਲ);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateWaitableTimer CreateWaitableTimerW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenWaitableTimer OpenWaitableTimerW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateFileMapping CreateFileMappingW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenFileMapping OpenFileMappingW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Logical_Drive_ਲੜੀਆਂ Get_Logical_Drive_ਲੜੀਆਂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Library ਲੱਦੋ_Library_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Library_Ex ਲੱਦੋ_Library_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetModuleFileName GetModuleFileNameW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetModuleHandle GetModuleHandleW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateWaitableTimer CreateWaitableTimerA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenWaitableTimer OpenWaitableTimerA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateFileMapping CreateFileMappingA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenFileMapping OpenFileMappingA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Logical_Drive_ਲੜੀਆਂ Get_Logical_Drive_ਲੜੀਆਂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Library ਲੱਦੋ_Library_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Library_Ex ਲੱਦੋ_Library_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetModuleFileName GetModuleFileNameA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetModuleHandle GetModuleHandleA
#ਜੇ_ਅੰਤ

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ਗੁਣ lp_Timer_ਗੁਣ,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ਗੁਣ lp_Timer_ਗੁਣ,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Waitable_Timer(HANDLE hTimer,ਅਚਲ LARGE_INTEGER *lp_Due_ਸਮਾਂ,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lp_Arg_ਮੰਜ਼ਿਲ_Completion_Routine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_ਗੁਣ lp_File_Mapping_ਗੁਣ,DWORD flProtect,DWORD dw_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਮਾਪ_ਉੱਚਾ,DWORD dw_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਮਾਪ_ਨੀਵਾਂ,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_ਗੁਣ lp_File_Mapping_ਗੁਣ,DWORD flProtect,DWORD dw_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਮਾਪ_ਉੱਚਾ,DWORD dw_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਮਾਪ_ਨੀਵਾਂ,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_ਲੜੀਆਂ_A(DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPSTR lp_ਬਫਰ);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_ਲੜੀਆਂ_W(DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPWSTR lp_ਬਫਰ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ ਸਮ੍ਰਿਤੀ_RESOURCE_NOTIFICATION_TYPE {
    ਨੀਵਾਂ_ਸਮ੍ਰਿਤੀ_Resource_Notification,ਉੱਚਾ_ਸਮ੍ਰਿਤੀ_Resource_Notification
  } ਸਮ੍ਰਿਤੀ_RESOURCE_NOTIFICATION_TYPE_2;

  WINBASEAPI HANDLE WINAPI Create_ਸਮ੍ਰਿਤੀ_Resource_Notification(ਸਮ੍ਰਿਤੀ_RESOURCE_NOTIFICATION_TYPE_2 NotificationType);
  WINBASEAPI WINBOOL WINAPI Query_ਸਮ੍ਰਿਤੀ_Resource_Notification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI ਲੱਦੋ_Library_A(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI ਲੱਦੋ_Library_W(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI ਲੱਦੋ_Library_Ex_A(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI ਲੱਦੋ_Library_Ex_W(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DONT_RESOLVE_DLL_REFERENCES 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_AS_DATAFILE 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_WITH_ALTERED_ਖੋਜ_ਰਸਤਾ 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_IGNORE_ਕੋਡ_AUTHZ_LEVEL 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_AS_IMAGE_RESOURCE 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_REQUIRE_SIGNED_ਨਿਸ਼ਾਨਾ 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_ਖੋਜ_DLL_ਲੱਦੋ_DIR 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_ਖੋਜ_APPLICATION_DIR 0x200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_ਖੋਜ_USER_DIRS 0x400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_ਖੋਜ_SYSTEM32 0x800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_ਖੋਜ_DEFAULT_DIRS 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_LIBRARY_ਸੁਰੱਖਿਅਤ_CURRENT_DIRS 0x2000

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD n_ਮਾਪ);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD n_ਮਾਪ);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_MODULE_HANDLE_EX_FLAG_FROM_ਪਤਾ (0x4)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetModuleHandleEx GetModuleHandleExW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetModuleHandleEx GetModuleHandleExA
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Need_Current_Directory_For_Exe_ਰਸਤਾ Need_Current_Directory_For_Exe_ਰਸਤਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateProcess CreateProcessW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FatalAppExit FatalAppExitW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetStartupInfo GetStartupInfoW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Command_ਸਤਰ Get_Command_ਸਤਰ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetEnvironmentVariable GetEnvironmentVariableW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Environment_Variable ਸੈੱਟ_Environment_Variable_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Expand_Environment_ਲੜੀਆਂ Expand_Environment_ਲੜੀਆਂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Firmware_Environment_Variable ਸੈੱਟ_Firmware_Environment_Variable_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OutputDebugString OutputDebugStringW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Resource ਲੱਭੋ_Resource_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Resource_Ex ਲੱਭੋ_Resource_Ex_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Need_Current_Directory_For_Exe_ਰਸਤਾ Need_Current_Directory_For_Exe_ਰਸਤਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateProcess CreateProcessA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FatalAppExit FatalAppExitA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetStartupInfo GetStartupInfoA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Command_ਸਤਰ Get_Command_ਸਤਰ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetEnvironmentVariable GetEnvironmentVariableA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Environment_Variable ਸੈੱਟ_Environment_Variable_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Expand_Environment_ਲੜੀਆਂ Expand_Environment_ਲੜੀਆਂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Firmware_Environment_Variable ਸੈੱਟ_Firmware_Environment_Variable_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OutputDebugString OutputDebugStringA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Resource ਲੱਭੋ_Resource_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Resource_Ex ਲੱਭੋ_Resource_Ex_A
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_ਰਸਤਾ_A(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_ਰਸਤਾ_W(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lp_Command_ਸਤਰ,LPSECURITY_ਗੁਣ lp_Process_ਗੁਣ,LPSECURITY_ਗੁਣ lp_Thread_ਗੁਣ,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lp_Command_ਸਤਰ,LPSECURITY_ਗੁਣ lp_Process_ਗੁਣ,LPSECURITY_ਗੁਣ lp_Thread_ਗੁਣ,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI ਜੋੜੋ_Local_Alternate_Computer_Name_A(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI ਜੋੜੋ_Local_Alternate_Computer_Name_W(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Process_Shutdown_Parameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI Get_Process_ਸੰਸਕਰਣ(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lp_ਸੁਨੇਹਾ_ਪਾਠ);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lp_ਸੁਨੇਹਾ_ਪਾਠ);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI Get_Command_ਸਤਰ_A(VOID);
  WINBASEAPI LPWSTR WINAPI Get_Command_ਸਤਰ_W(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lp_ਬਫਰ,DWORD n_ਮਾਪ);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lp_ਬਫਰ,DWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Environment_Variable_A(LPCSTR lpName,LPCSTR lp_ਮੁੱਲ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lp_ਮੁੱਲ);
  WINBASEAPI DWORD WINAPI Expand_Environment_ਲੜੀਆਂ_A(LPCSTR lpSrc,LPSTR lpDst,DWORD n_ਮਾਪ);
  WINBASEAPI DWORD WINAPI Expand_Environment_ਲੜੀਆਂ_W(LPCWSTR lpSrc,LPWSTR lpDst,DWORD n_ਮਾਪ);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_ਬਫਰ,DWORD n_ਮਾਪ);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_ਬਫਰ,DWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Firmware_Environment_Variable_A(LPCSTR lpName,LPCSTR lpGuid,PVOID p_ਮੁੱਲ,DWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Firmware_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_ਮੁੱਲ,DWORD n_ਮਾਪ);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI ਲੱਭੋ_Resource_A(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI ਲੱਭੋ_Resource_W(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI ਲੱਭੋ_Resource_Ex_A(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ਸ਼ਬਦ_3 wLanguage);
  WINBASEAPI HRSRC WINAPI ਲੱਭੋ_Resource_Ex_W(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ਸ਼ਬਦ_3 wLanguage);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUMRESTYPEPROC ENUMRESTYPEPROCW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUMRESNAMEPROC ENUMRESNAMEPROCW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUMRESLANGPROC ENUMRESLANGPROCW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumResourceTypes EnumResourceTypesW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Enum_Resource_ਨਾਂ Enum_Resource_ਨਾਂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumResourceLanguages EnumResourceLanguagesW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BeginUpdateResource BeginUpdateResourceW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UpdateResource UpdateResourceW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਿਰਾ_Update_Resource ਸਿਰਾ_Update_Resource_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Global_ਜੋੜੋ_Atom Global_ਜੋੜੋ_Atom_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Global_ਲੱਭੋ_Atom Global_ਲੱਭੋ_Atom_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GlobalGetAtomName GlobalGetAtomNameW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Atom ਜੋੜੋ_Atom_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Atom ਲੱਭੋ_Atom_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetAtomName GetAtomNameW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetProfileInt GetProfileIntW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetProfileString GetProfileStringW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteProfileString WriteProfileStringW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetProfileSection GetProfileSectionW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteProfileSection WriteProfileSectionW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_Int Get_ਨਿੱਜੀ_Profile_Int_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_String Get_ਨਿੱਜੀ_Profile_String_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Write_ਨਿੱਜੀ_Profile_String Write_ਨਿੱਜੀ_Profile_String_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_Section Get_ਨਿੱਜੀ_Profile_Section_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Write_ਨਿੱਜੀ_Profile_Section Write_ਨਿੱਜੀ_Profile_Section_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_Section_ਨਾਂ Get_ਨਿੱਜੀ_Profile_Section_ਨਾਂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_Struct Get_ਨਿੱਜੀ_Profile_Struct_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Write_ਨਿੱਜੀ_Profile_Struct Write_ਨਿੱਜੀ_Profile_Struct_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDriveType GetDriveTypeW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetSystemDirectory GetSystemDirectoryW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਆਰਜ਼ੀ_ਰਸਤਾ Get_ਆਰਜ਼ੀ_ਰਸਤਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਆਰਜ਼ੀ_File_Name Get_ਆਰਜ਼ੀ_File_Name_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetWindowsDirectory GetWindowsDirectoryW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Local_Alternate_Computer_Name ਜੋੜੋ_Local_Alternate_Computer_Name_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUMRESTYPEPROC ENUMRESTYPEPROCA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUMRESNAMEPROC ENUMRESNAMEPROCA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUMRESLANGPROC ENUMRESLANGPROCA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumResourceTypes EnumResourceTypesA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Enum_Resource_ਨਾਂ Enum_Resource_ਨਾਂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumResourceLanguages EnumResourceLanguagesA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BeginUpdateResource BeginUpdateResourceA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UpdateResource UpdateResourceA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਿਰਾ_Update_Resource ਸਿਰਾ_Update_Resource_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Global_ਜੋੜੋ_Atom Global_ਜੋੜੋ_Atom_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Global_ਲੱਭੋ_Atom Global_ਲੱਭੋ_Atom_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GlobalGetAtomName GlobalGetAtomNameA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Atom ਜੋੜੋ_Atom_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Atom ਲੱਭੋ_Atom_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetAtomName GetAtomNameA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetProfileInt GetProfileIntA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetProfileString GetProfileStringA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteProfileString WriteProfileStringA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetProfileSection GetProfileSectionA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteProfileSection WriteProfileSectionA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_Int Get_ਨਿੱਜੀ_Profile_Int_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_String Get_ਨਿੱਜੀ_Profile_String_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Write_ਨਿੱਜੀ_Profile_String Write_ਨਿੱਜੀ_Profile_String_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_Section Get_ਨਿੱਜੀ_Profile_Section_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Write_ਨਿੱਜੀ_Profile_Section Write_ਨਿੱਜੀ_Profile_Section_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_Section_ਨਾਂ Get_ਨਿੱਜੀ_Profile_Section_ਨਾਂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਨਿੱਜੀ_Profile_Struct Get_ਨਿੱਜੀ_Profile_Struct_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Write_ਨਿੱਜੀ_Profile_Struct Write_ਨਿੱਜੀ_Profile_Struct_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDriveType GetDriveTypeA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetSystemDirectory GetSystemDirectoryA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਆਰਜ਼ੀ_ਰਸਤਾ Get_ਆਰਜ਼ੀ_ਰਸਤਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਆਰਜ਼ੀ_File_Name Get_ਆਰਜ਼ੀ_File_Name_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetWindowsDirectory GetWindowsDirectoryA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Local_Alternate_Computer_Name ਜੋੜੋ_Local_Alternate_Computer_Name_A
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ਸ਼ਬਦ_3 wLanguage,LONG_PTR lParam);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ਸ਼ਬਦ_3 wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_ਨਾਂ_A(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_ਨਾਂ_W(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,ਸ਼ਬਦ_3 wLanguage,LPVOID lp_ਅੰਕੜੇ,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,ਸ਼ਬਦ_3 wLanguage,LPVOID lp_ਅੰਕੜੇ,DWORD cb);
  WINBASEAPI WINBOOL WINAPI ਸਿਰਾ_Update_Resource_A(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI ਸਿਰਾ_Update_Resource_W(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI Global_ਜੋੜੋ_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ਜੋੜੋ_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ਲੱਭੋ_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ਲੱਭੋ_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lp_ਬਫਰ,ਪੂਰਨ n_ਮਾਪ);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lp_ਬਫਰ,ਪੂਰਨ n_ਮਾਪ);
  WINBASEAPI ATOM WINAPI ਜੋੜੋ_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI ਜੋੜੋ_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI ਲੱਭੋ_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI ਲੱਭੋ_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lp_ਬਫਰ,ਪੂਰਨ n_ਮਾਪ);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lp_ਬਫਰ,ਪੂਰਨ n_ਮਾਪ);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lp_ਕੁੰਜੀ_Name,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_ਕੁੰਜੀ_Name,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lp_ਕੁੰਜੀ_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_ਮਾਪ);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_ਕੁੰਜੀ_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lp_ਕੁੰਜੀ_Name,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_ਕੁੰਜੀ_Name,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_ਮਾਪ);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI Get_ਨਿੱਜੀ_Profile_Int_A(LPCSTR lpAppName,LPCSTR lp_ਕੁੰਜੀ_Name,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI Get_ਨਿੱਜੀ_Profile_Int_W(LPCWSTR lpAppName,LPCWSTR lp_ਕੁੰਜੀ_Name,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ਨਿੱਜੀ_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_ਕੁੰਜੀ_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_ਮਾਪ,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ਨਿੱਜੀ_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_ਕੁੰਜੀ_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_ਮਾਪ,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ਨਿੱਜੀ_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_ਕੁੰਜੀ_Name,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ਨਿੱਜੀ_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_ਕੁੰਜੀ_Name,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ਨਿੱਜੀ_Profile_Section_A(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_ਮਾਪ,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ਨਿੱਜੀ_Profile_Section_W(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_ਮਾਪ,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ਨਿੱਜੀ_Profile_Section_A(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ਨਿੱਜੀ_Profile_Section_W(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ਨਿੱਜੀ_Profile_Section_ਨਾਂ_A(LPSTR lpsz_Return_ਬਫਰ,DWORD n_ਮਾਪ,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ਨਿੱਜੀ_Profile_Section_ਨਾਂ_W(LPWSTR lpsz_Return_ਬਫਰ,DWORD n_ਮਾਪ,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Get_ਨਿੱਜੀ_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_ਕੁੰਜੀ,LPVOID lpStruct,UINT u_ਮਾਪ_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Get_ਨਿੱਜੀ_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_ਕੁੰਜੀ,LPVOID lpStruct,UINT u_ਮਾਪ_Struct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_ਨਿੱਜੀ_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_ਕੁੰਜੀ,LPVOID lpStruct,UINT u_ਮਾਪ_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_ਨਿੱਜੀ_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_ਕੁੰਜੀ,LPVOID lpStruct,UINT u_ਮਾਪ_Struct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lp_ਜੜ੍ਹ_ਰਸਤਾ_Name);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lp_ਜੜ੍ਹ_ਰਸਤਾ_Name);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lp_ਬਫਰ,UINT u_ਮਾਪ);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lp_ਬਫਰ,UINT u_ਮਾਪ);
  WINBASEAPI DWORD WINAPI Get_ਆਰਜ਼ੀ_ਰਸਤਾ_A(DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPSTR lp_ਬਫਰ);
  WINBASEAPI DWORD WINAPI Get_ਆਰਜ਼ੀ_ਰਸਤਾ_W(DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPWSTR lp_ਬਫਰ);
  WINBASEAPI UINT WINAPI Get_ਆਰਜ਼ੀ_File_Name_A(LPCSTR lp_ਰਸਤਾ_Name,LPCSTR lp_ਅਗੇਤਰ_String,UINT uUnique,LPSTR lp_ਆਰਜ਼ੀ_File_Name);
  WINBASEAPI UINT WINAPI Get_ਆਰਜ਼ੀ_File_Name_W(LPCWSTR lp_ਰਸਤਾ_Name,LPCWSTR lp_ਅਗੇਤਰ_String,UINT uUnique,LPWSTR lp_ਆਰਜ਼ੀ_File_Name);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lp_ਬਫਰ,UINT u_ਮਾਪ);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lp_ਬਫਰ,UINT u_ਮਾਪ);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lp_ਬਫਰ,UINT u_ਮਾਪ);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lp_ਬਫਰ,UINT u_ਮਾਪ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetSystemWow64Directory GetSystemWow64DirectoryW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetSystemWow64Directory GetSystemWow64DirectoryA
#ਜੇ_ਅੰਤ

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lp_ਬਫਰ,UINT u_ਮਾਪ);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lp_ਬਫਰ,UINT u_ਮਾਪ);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *Old_ਮੁੱਲ);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID Ol_ਮੁੱਲ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lp_ਬਫਰ,UINT u_ਮਾਪ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lp_ਬਫਰ,UINT u_ਮਾਪ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T ਪਾਠ_3("GetSystemWow64DirectoryA")
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T ਪਾਠ_3("GetSystemWow64DirectoryW")

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Current_Directory ਸੈੱਟ_Current_Directory_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCurrentDirectory GetCurrentDirectoryW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Dll_Directory ਸੈੱਟ_Dll_Directory_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDllDirectory GetDllDirectoryW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDiskFreeSpace GetDiskFreeSpaceW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDirectory CreateDirectoryW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDirectoryEx CreateDirectoryExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RemoveDirectory RemoveDirectoryW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਭਰਿਆ_ਰਸਤਾ_Name Get_ਭਰਿਆ_ਰਸਤਾ_Name_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DefineDosDevice DefineDosDeviceW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QueryDosDevice QueryDosDeviceW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateFile CreateFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_File_ਗੁਣ ਸੈੱਟ_File_ਗੁਣ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_File_ਗੁਣ Get_File_ਗੁਣ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Current_Directory ਸੈੱਟ_Current_Directory_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCurrentDirectory GetCurrentDirectoryA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Dll_Directory ਸੈੱਟ_Dll_Directory_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDllDirectory GetDllDirectoryA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDiskFreeSpace GetDiskFreeSpaceA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDirectory CreateDirectoryA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDirectoryEx CreateDirectoryExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RemoveDirectory RemoveDirectoryA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਭਰਿਆ_ਰਸਤਾ_Name Get_ਭਰਿਆ_ਰਸਤਾ_Name_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DefineDosDevice DefineDosDeviceA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QueryDosDevice QueryDosDeviceA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateFile CreateFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_File_ਗੁਣ ਸੈੱਟ_File_ਗੁਣ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_File_ਗੁਣ Get_File_ਗੁਣ_A
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Current_Directory_A(LPCSTR lp_ਰਸਤਾ_Name);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Current_Directory_W(LPCWSTR lp_ਰਸਤਾ_Name);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPSTR lp_ਬਫਰ);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPWSTR lp_ਬਫਰ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Dll_Directory_A(LPCSTR lp_ਰਸਤਾ_Name);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Dll_Directory_W(LPCWSTR lp_ਰਸਤਾ_Name);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPSTR lp_ਬਫਰ);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPWSTR lp_ਬਫਰ);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lp_ਜੜ੍ਹ_ਰਸਤਾ_Name,LPDWORD lp_Sectors_ਪ੍ਰਤੀ_Cluster,LPDWORD lp_ਬਾਈਟਾਂ_ਪ੍ਰਤੀ_Sector,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Free_Clusters,LPDWORD lp_ਕੁੱਲ_ਸੰਖਿਆ_ਦਾ_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lp_ਜੜ੍ਹ_ਰਸਤਾ_Name,LPDWORD lp_Sectors_ਪ੍ਰਤੀ_Cluster,LPDWORD lp_ਬਾਈਟਾਂ_ਪ੍ਰਤੀ_Sector,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Free_Clusters,LPDWORD lp_ਕੁੱਲ_ਸੰਖਿਆ_ਦਾ_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lp_Free_ਬਾਈਟਾਂ_ਉਪਲਬਧ_ਮੰਜ਼ਿਲ_Caller,PULARGE_INTEGER lp_ਕੁੱਲ_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ,PULARGE_INTEGER lp_ਕੁੱਲ_ਸੰਖਿਆ_ਦਾ_Free_ਬਾਈਟਾਂ);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lp_Free_ਬਾਈਟਾਂ_ਉਪਲਬਧ_ਮੰਜ਼ਿਲ_Caller,PULARGE_INTEGER lp_ਕੁੱਲ_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ,PULARGE_INTEGER lp_ਕੁੱਲ_ਸੰਖਿਆ_ਦਾ_Free_ਬਾਈਟਾਂ);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lp_ਰਸਤਾ_Name,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lp_ਰਸਤਾ_Name,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lp_ਰਸਤਾ_Name);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lp_ਰਸਤਾ_Name);
  WINBASEAPI DWORD WINAPI Get_ਭਰਿਆ_ਰਸਤਾ_Name_A(LPCSTR lpFileName,DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPSTR lp_ਬਫਰ,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI Get_ਭਰਿਆ_ਰਸਤਾ_Name_W(LPCWSTR lpFileName,DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPWSTR lp_ਬਫਰ,LPWSTR *lpFilePart);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDD_RAW_ਨਿਸ਼ਾਨਾ_ਰਸਤਾ 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDD_REMOVE_DEFINITION 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDD_EXACT_ਮੇਲ_ON_REMOVE 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDD_NO_ਪ੍ਰਸਾਰਣ_SYSTEM 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDD_LUID_ਪ੍ਰਸਾਰਣ_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lp_ਨਿਸ਼ਾਨਾ_ਰਸਤਾ);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lp_ਨਿਸ਼ਾਨਾ_ਰਸਤਾ);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lp_ਨਿਸ਼ਾਨਾ_ਰਸਤਾ,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lp_ਨਿਸ਼ਾਨਾ_ਰਸਤਾ,DWORD ucchMax);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_ਬਹੁਲਕ,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ,DWORD dwCreationDisposition,DWORD dw_Flags_And_ਗੁਣ,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_ਬਹੁਲਕ,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ,DWORD dwCreationDisposition,DWORD dw_Flags_And_ਗੁਣ,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dw_Share_ਬਹੁਲਕ,DWORD dw_Flags_And_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_File_ਗੁਣ_A(LPCSTR lpFileName,DWORD dw_File_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_File_ਗੁਣ_W(LPCWSTR lpFileName,DWORD dw_File_ਗੁਣ);
  WINBASEAPI DWORD WINAPI Get_File_ਗੁਣ_A(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_File_ਗੁਣ_W(LPCWSTR lpFileName);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ GET_FILEEX_INFO_ਪੱਧਰ {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_ਪੱਧਰ_2;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_File_ਗੁਣ_Ex Get_File_ਗੁਣ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Compressed_File_ਮਾਪ Get_Compressed_File_ਮਾਪ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DeleteFile DeleteFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_File_ਗੁਣ_Ex Get_File_ਗੁਣ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Compressed_File_ਮਾਪ Get_Compressed_File_ਮਾਪ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DeleteFile DeleteFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI Get_File_ਗੁਣ_Ex_A(LPCSTR lpFileName,GET_FILEEX_INFO_ਪੱਧਰ_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI Get_File_ਗੁਣ_Ex_W(LPCWSTR lpFileName,GET_FILEEX_INFO_ਪੱਧਰ_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_ਮਾਪ_A(LPCSTR lpFileName,LPDWORD lp_File_ਮਾਪ_ਉੱਚਾ);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_ਮਾਪ_W(LPCWSTR lpFileName,LPDWORD lp_File_ਮਾਪ_ਉੱਚਾ);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD Oem_Name_ਮਾਪ,PBOOL pb_Name_ਸ਼ਾਮਲ_ਹੈ_Spaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD Oem_Name_ਮਾਪ,PBOOL pb_Name_ਸ਼ਾਮਲ_ਹੈ_Spaces,PBOOL pbNameLegal);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ FINDEX_INFO_ਪੱਧਰ {
    ਲੱਭੋ_Ex_Info_Standard,ਲੱਭੋ_Ex_Info_Max_Info_Level
  } FINDEX_INFO_ਪੱਧਰ_2;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ FINDEX_ਖੋਜ_OPS {
    ਲੱਭੋ_Ex_ਖੋਜ_Name_ਮੇਲ,ਲੱਭੋ_Ex_ਖੋਜ_ਹੱਦਬੰਦੀ_ਮੰਜ਼ਿਲ_Directories,ਲੱਭੋ_Ex_ਖੋਜ_ਹੱਦਬੰਦੀ_ਮੰਜ਼ਿਲ_Devices,ਲੱਭੋ_Ex_ਖੋਜ_Max_ਖੋਜ_Op
  } FINDEX_ਖੋਜ_OPS_2;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_EX_CASE_SENSITIVE 0x1

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_File_Ex ਲੱਭੋ_ਪਹਿਲਾ_File_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_File ਲੱਭੋ_ਪਹਿਲਾ_File_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਅਗਲਾ_File ਲੱਭੋ_ਅਗਲਾ_File_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖੋਜ_ਰਸਤਾ ਖੋਜ_ਰਸਤਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CopyFile CopyFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CopyFileEx CopyFileExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MoveFile MoveFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MoveFileEx MoveFileExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Move_File_With_ਤਰੱਕੀ Move_File_With_ਤਰੱਕੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReplaceFile ReplaceFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateHardLink CreateHardLinkW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateNamedPipe CreateNamedPipeW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetNamedPipeHandleState GetNamedPipeHandleStateW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CallNamedPipe CallNamedPipeW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WaitNamedPipe WaitNamedPipeW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Volume_Label ਸੈੱਟ_Volume_Label_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetVolumeInformation GetVolumeInformationW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ClearEventLog ClearEventLogW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BackupEventLog BackupEventLogW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenEventLog OpenEventLogW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Event_ਸਰੋਤ ਰਜਿਸਟਰ_Event_ਸਰੋਤ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenBackupEventLog OpenBackupEventLogW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadEventLog ReadEventLogW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReportEvent ReportEventW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_By_Handle_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_File_Security ਸੈੱਟ_File_Security_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetFileSecurity GetFileSecurityW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_Change_Notification ਲੱਭੋ_ਪਹਿਲਾ_Change_Notification_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsBadStringPtr IsBadStringPtrW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LookupAccountSid LookupAccountSidW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LookupAccountName LookupAccountNameW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Lookup_Privilege_ਮੁੱਲ Lookup_Privilege_ਮੁੱਲ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LookupPrivilegeName LookupPrivilegeNameW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BuildCommDCB BuildCommDCBW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CommConfigDialog CommConfigDialogW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDefaultCommConfig GetDefaultCommConfigW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Default_Comm_Config ਸੈੱਟ_Default_Comm_Config_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetComputerName GetComputerNameW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Computer_Name ਸੈੱਟ_Computer_Name_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetComputerNameEx GetComputerNameExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Computer_Name_Ex ਸੈੱਟ_Computer_Name_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dns_Hostname_ਮੰਜ਼ਿਲ_Computer_Name Dns_Hostname_ਮੰਜ਼ਿਲ_Computer_Name_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetUserName GetUserNameW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_File_Ex ਲੱਭੋ_ਪਹਿਲਾ_File_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_File ਲੱਭੋ_ਪਹਿਲਾ_File_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਅਗਲਾ_File ਲੱਭੋ_ਅਗਲਾ_File_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖੋਜ_ਰਸਤਾ ਖੋਜ_ਰਸਤਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CopyFile CopyFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CopyFileEx CopyFileExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MoveFile MoveFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MoveFileEx MoveFileExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Move_File_With_ਤਰੱਕੀ Move_File_With_ਤਰੱਕੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReplaceFile ReplaceFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateHardLink CreateHardLinkA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateNamedPipe CreateNamedPipeA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetNamedPipeHandleState GetNamedPipeHandleStateA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CallNamedPipe CallNamedPipeA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WaitNamedPipe WaitNamedPipeA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Volume_Label ਸੈੱਟ_Volume_Label_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetVolumeInformation GetVolumeInformationA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ClearEventLog ClearEventLogA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BackupEventLog BackupEventLogA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenEventLog OpenEventLogA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Event_ਸਰੋਤ ਰਜਿਸਟਰ_Event_ਸਰੋਤ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenBackupEventLog OpenBackupEventLogA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadEventLog ReadEventLogA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReportEvent ReportEventA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_By_Handle_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_File_Security ਸੈੱਟ_File_Security_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetFileSecurity GetFileSecurityA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_Change_Notification ਲੱਭੋ_ਪਹਿਲਾ_Change_Notification_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsBadStringPtr IsBadStringPtrA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LookupAccountSid LookupAccountSidA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LookupAccountName LookupAccountNameA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Lookup_Privilege_ਮੁੱਲ Lookup_Privilege_ਮੁੱਲ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LookupPrivilegeName LookupPrivilegeNameA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BuildCommDCB BuildCommDCBA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CommConfigDialog CommConfigDialogA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetDefaultCommConfig GetDefaultCommConfigA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Default_Comm_Config ਸੈੱਟ_Default_Comm_Config_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetComputerName GetComputerNameA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Computer_Name ਸੈੱਟ_Computer_Name_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetComputerNameEx GetComputerNameExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Computer_Name_Ex ਸੈੱਟ_Computer_Name_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dns_Hostname_ਮੰਜ਼ਿਲ_Computer_Name Dns_Hostname_ਮੰਜ਼ਿਲ_Computer_Name_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetUserName GetUserNameA
#ਜੇ_ਅੰਤ

  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_File_Ex_A(LPCSTR lpFileName,FINDEX_INFO_ਪੱਧਰ_2 fInfoLevelId,LPVOID lp_ਲੱਭੋ_File_ਅੰਕੜੇ,FINDEX_ਖੋਜ_OPS_2 f_ਖੋਜ_Op,LPVOID lp_ਖੋਜ_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_File_Ex_W(LPCWSTR lpFileName,FINDEX_INFO_ਪੱਧਰ_2 fInfoLevelId,LPVOID lp_ਲੱਭੋ_File_ਅੰਕੜੇ,FINDEX_ਖੋਜ_OPS_2 f_ਖੋਜ_Op,LPVOID lp_ਖੋਜ_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_File_A(LPCSTR lpFileName,LPWIN32_ਲੱਭੋ_DATAA lp_ਲੱਭੋ_File_ਅੰਕੜੇ);
  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_File_W(LPCWSTR lpFileName,LPWIN32_ਲੱਭੋ_DATAW lp_ਲੱਭੋ_File_ਅੰਕੜੇ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_ਅਗਲਾ_File_A(HANDLE h_ਲੱਭੋ_File,LPWIN32_ਲੱਭੋ_DATAA lp_ਲੱਭੋ_File_ਅੰਕੜੇ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_ਅਗਲਾ_File_W(HANDLE h_ਲੱਭੋ_File,LPWIN32_ਲੱਭੋ_DATAW lp_ਲੱਭੋ_File_ਅੰਕੜੇ);
  WINBASEAPI DWORD WINAPI ਖੋਜ_ਰਸਤਾ_A(LPCSTR lp_ਰਸਤਾ,LPCSTR lpFileName,LPCSTR lpExtension,DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPSTR lp_ਬਫਰ,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI ਖੋਜ_ਰਸਤਾ_W(LPCWSTR lp_ਰਸਤਾ,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD n_ਬਫਰ_ਲੰਮਾਈ,LPWSTR lp_ਬਫਰ,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER ਕੁੱਲ_File_ਮਾਪ,LARGE_INTEGER ਕੁੱਲ_ਬਾਈਟਾਂ_Transferred,LARGE_INTEGER ਧਾਰਾ_ਮਾਪ,LARGE_INTEGER ਧਾਰਾ_ਬਾਈਟਾਂ_Transferred,DWORD dw_ਧਾਰਾ_ਸੰਖਿਆ,DWORD dwCallbackReason,HANDLE h_ਸਰੋਤ_File,HANDLE hDestinationFile,LPVOID lp_ਅੰਕੜੇ);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ਤਰੱਕੀ_Routine,LPVOID lp_ਅੰਕੜੇ,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ਤਰੱਕੀ_Routine,LPVOID lp_ਅੰਕੜੇ,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_ਤਰੱਕੀ_A(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ਤਰੱਕੀ_Routine,LPVOID lp_ਅੰਕੜੇ,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_ਤਰੱਕੀ_W(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ਤਰੱਕੀ_Routine,LPVOID lp_ਅੰਕੜੇ,DWORD dwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOVEFILE_REPLACE_EXISTING 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOVEFILE_COPY_ALLOWED 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOVEFILE_WRITE_THROUGH 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOVEFILE_CREATE_HARDLINK 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ ਧਾਰਾ_INFO_ਪੱਧਰ {
    ਲੱਭੋ_ਧਾਰਾ_Info_Standard,ਲੱਭੋ_ਧਾਰਾ_Info_Max_Info_Level
  } ਧਾਰਾ_INFO_ਪੱਧਰ_2;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ WIN32_ਲੱਭੋ_ਧਾਰਾ_ਅੰਕੜੇ {
    LARGE_INTEGER ਧਾਰਾ_ਮਾਪ;
    WCHAR c_ਧਾਰਾ_Name[MAX_ਰਸਤਾ + 36];
  } WIN32_ਲੱਭੋ_ਧਾਰਾ_ਅੰਕੜੇ_2,*PWIN32_ਲੱਭੋ_ਧਾਰਾ_ਅੰਕੜੇ;

  HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_ਧਾਰਾ_W(LPCWSTR lpFileName,ਧਾਰਾ_INFO_ਪੱਧਰ_2 InfoLevel,LPVOID lp_ਲੱਭੋ_ਧਾਰਾ_ਅੰਕੜੇ,DWORD dwFlags);
  WINBOOL WINAPI ਲੱਭੋ_ਅਗਲਾ_ਧਾਰਾ_W(HANDLE h_ਲੱਭੋ_ਧਾਰਾ,LPVOID lp_ਲੱਭੋ_ਧਾਰਾ_ਅੰਕੜੇ);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dw_Open_ਬਹੁਲਕ,DWORD dw_Pipe_ਬਹੁਲਕ,DWORD nMaxInstances,DWORD n_ਬਾਹਰਲਾ_ਬਫਰ_ਮਾਪ,DWORD n_ਵਿੱਚ_ਬਫਰ_ਮਾਪ,DWORD n_Default_ਸਮਾਂ_ਬਾਹਰਲਾ,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dw_Open_ਬਹੁਲਕ,DWORD dw_Pipe_ਬਹੁਲਕ,DWORD nMaxInstances,DWORD n_ਬਾਹਰਲਾ_ਬਫਰ_ਮਾਪ,DWORD n_ਵਿੱਚ_ਬਫਰ_ਮਾਪ,DWORD n_Default_ਸਮਾਂ_ਬਾਹਰਲਾ,LPSECURITY_ਗੁਣ lp_Security_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_ਗਿਣਤੀ,LPDWORD lp_Collect_ਅੰਕੜੇ_Timeout,LPSTR lpUserName,DWORD n_Max_User_Name_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_ਗਿਣਤੀ,LPDWORD lp_Collect_ਅੰਕੜੇ_Timeout,LPWSTR lpUserName,DWORD n_Max_User_Name_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lp_ਵਿੱਚ_ਬਫਰ,DWORD n_ਵਿੱਚ_ਬਫਰ_ਮਾਪ,LPVOID lp_ਬਾਹਰਲਾ_ਬਫਰ,DWORD n_ਬਾਹਰਲਾ_ਬਫਰ_ਮਾਪ,LPDWORD lp_ਬਾਈਟਾਂ_Read,DWORD n_ਸਮਾਂ_ਬਾਹਰਲਾ);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lp_ਵਿੱਚ_ਬਫਰ,DWORD n_ਵਿੱਚ_ਬਫਰ_ਮਾਪ,LPVOID lp_ਬਾਹਰਲਾ_ਬਫਰ,DWORD n_ਬਾਹਰਲਾ_ਬਫਰ_ਮਾਪ,LPDWORD lp_ਬਾਈਟਾਂ_Read,DWORD n_ਸਮਾਂ_ਬਾਹਰਲਾ);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD n_ਸਮਾਂ_ਬਾਹਰਲਾ);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD n_ਸਮਾਂ_ਬਾਹਰਲਾ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Volume_Label_A(LPCSTR lp_ਜੜ੍ਹ_ਰਸਤਾ_Name,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Volume_Label_W(LPCWSTR lp_ਜੜ੍ਹ_ਰਸਤਾ_Name,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI ਸੈੱਟ_File_Apis_ਮੰਜ਼ਿਲ_OEM(VOID);
  WINBASEAPI VOID WINAPI ਸੈੱਟ_File_Apis_ਮੰਜ਼ਿਲ_ANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lp_ਜੜ੍ਹ_ਰਸਤਾ_Name,LPSTR lp_Volume_Name_ਬਫਰ,DWORD n_Volume_Name_ਮਾਪ,LPDWORD lp_Volume_Serial_ਸੰਖਿਆ,LPDWORD lp_ਵੱਧ_ਤੋਂ_ਵੱਧ_Component_ਲੰਮਾਈ,LPDWORD lpFileSystemFlags,LPSTR lp_File_System_Name_ਬਫਰ,DWORD n_File_System_Name_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lp_ਜੜ੍ਹ_ਰਸਤਾ_Name,LPWSTR lp_Volume_Name_ਬਫਰ,DWORD n_Volume_Name_ਮਾਪ,LPDWORD lp_Volume_Serial_ਸੰਖਿਆ,LPDWORD lp_ਵੱਧ_ਤੋਂ_ਵੱਧ_Component_ਲੰਮਾਈ,LPDWORD lpFileSystemFlags,LPWSTR lp_File_System_Name_ਬਫਰ,DWORD n_File_System_Name_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI Deregister_Event_ਸਰੋਤ(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI Get_ਸੰਖਿਆ_ਦਾ_Event_Log_ਰਿਕਾਰਡਾਂ(HANDLE hEventLog,PDWORD ਸੰਖਿਆ_ਦਾ_ਰਿਕਾਰਡਾਂ);
  WINADVAPI WINBOOL WINAPI Get_Oldest_Event_Log_ਰਿਕਾਰਡ(HANDLE hEventLog,PDWORD Oldest_ਰਿਕਾਰਡ);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lp_ਸਰੋਤ_Name);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lp_ਸਰੋਤ_Name);
  WINADVAPI HANDLE WINAPI ਰਜਿਸਟਰ_Event_ਸਰੋਤ_A(LPCSTR lpUNCServerName,LPCSTR lp_ਸਰੋਤ_Name);
  WINADVAPI HANDLE WINAPI ਰਜਿਸਟਰ_Event_ਸਰੋਤ_W(LPCWSTR lpUNCServerName,LPCWSTR lp_ਸਰੋਤ_Name);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_ਰਿਕਾਰਡ_ਵਿੱਥ,LPVOID lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Read,DWORD *pn_ਬਾਈਟਾਂ_Read,DWORD *pn_Min_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Needed);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_ਰਿਕਾਰਡ_ਵਿੱਥ,LPVOID lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Read,DWORD *pn_ਬਾਈਟਾਂ_Read,DWORD *pn_Min_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_Needed);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,ਸ਼ਬਦ_3 wType,ਸ਼ਬਦ_3 wCategory,DWORD dwEventID,PSID lpUserSid,ਸ਼ਬਦ_3 w_ਅੰਕ_ਲੜੀਆਂ,DWORD dw_ਅੰਕੜੇ_ਮਾਪ,LPCSTR *lp_ਲੜੀਆਂ,LPVOID lp_Raw_ਅੰਕੜੇ);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,ਸ਼ਬਦ_3 wType,ਸ਼ਬਦ_3 wCategory,DWORD dwEventID,PSID lpUserSid,ਸ਼ਬਦ_3 w_ਅੰਕ_ਲੜੀਆਂ,DWORD dw_ਅੰਕੜੇ_ਮਾਪ,LPCWSTR *lp_ਲੜੀਆਂ,LPVOID lp_Raw_ਅੰਕੜੇ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENTLOG_ਭਰਿਆ_INFO 0

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ EVENTLOG_ਭਰਿਆ_INFORMATION {
    DWORD dw_ਭਰਿਆ;
  } EVENTLOG_ਭਰਿਆ_INFORMATION_2,*LPEVENTLOG_ਭਰਿਆ_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lp_ਬਫਰ,DWORD cb_Buf_ਮਾਪ,LPDWORD pcb_ਬਾਈਟਾਂ_Needed);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_ਲੰਮਾਈ,LPDWORD lpn_ਲੰਮਾਈ_Needed);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI Revert_ਮੰਜ਼ਿਲ_Self(VOID);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_Thread_Token (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_ਸੈੱਟ Privilege_ਸੈੱਟ,LPDWORD Privilege_ਸੈੱਟ_ਲੰਮਾਈ,LPDWORD GrantedAccess,LPBOOL Access_ਸਥਿਤੀ);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ਲੰਮਾਈ,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_ਸੈੱਟ Privilege_ਸੈੱਟ,LPDWORD Privilege_ਸੈੱਟ_ਲੰਮਾਈ,LPDWORD GrantedAccess,LPBOOL Access_ਸਥਿਤੀ);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ਨਤੀਜਾ_List(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ਲੰਮਾਈ,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_ਸੈੱਟ Privilege_ਸੈੱਟ,LPDWORD Privilege_ਸੈੱਟ_ਲੰਮਾਈ,LPDWORD GrantedAccessList,LPDWORD Access_ਸਥਿਤੀ_List);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_ਲੰਮਾਈ,PDWORD Return_ਲੰਮਾਈ);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_Token_Information(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_ਲੰਮਾਈ);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD ਬਫਰ_ਲੰਮਾਈ,PTOKEN_PRIVILEGES ਪਿਛਲਾ_State,PDWORD Return_ਲੰਮਾਈ);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL Reset_ਮੰਜ਼ਿਲ_Default,PTOKEN_GROUPS NewState,DWORD ਬਫਰ_ਲੰਮਾਈ,PTOKEN_GROUPS ਪਿਛਲਾ_State,PDWORD Return_ਲੰਮਾਈ);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_ਸੈੱਟ RequiredPrivileges,LPBOOL pf_ਨਤੀਜਾ);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_ਸਥਿਤੀ,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_ਸਥਿਤੀ,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ਲੰਮਾਈ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_ਸਥਿਤੀ,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ਲੰਮਾਈ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_ਸਥਿਤੀ,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_A(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ਲੰਮਾਈ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_ਸਥਿਤੀ_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_W(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ਲੰਮਾਈ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_ਸਥਿਤੀ_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_By_Handle_A(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ਲੰਮਾਈ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_ਸਥਿਤੀ_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ਨਤੀਜਾ_List_And_Audit_Alarm_By_Handle_W(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ਲੰਮਾਈ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_ਸਥਿਤੀ_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_ਸੈੱਟ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_ਸੈੱਟ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_ਸੈੱਟ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_ਸੈੱਟ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_ਸੈੱਟ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_ਸੈੱਟ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI Is_Well_ਗਿਆਤ_Sid(PSID pSid,WELL_ਗਿਆਤ_SID_TYPE Well_ਗਿਆਤ_Sid_Type);
  WINADVAPI WINBOOL WINAPI Create_Well_ਗਿਆਤ_Sid(WELL_ਗਿਆਤ_SID_TYPE Well_ਗਿਆਤ_Sid_Type,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI Equal_ਅਗੇਤਰ_Sid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI Get_Sid_ਲੰਮਾਈ_Required (UCHAR n_Sub_Authority_ਗਿਣਤੀ);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_ਗਿਣਤੀ,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_ਗਿਣਤੀ);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI Get_Sid_Sub_Authority_ਗਿਣਤੀ(PSID pSid);
  WINADVAPI DWORD WINAPI Get_ਲੰਮਾਈ_Sid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD n_Destination_Sid_ਲੰਮਾਈ,PSID pDestinationSid,PSID p_ਸਰੋਤ_Sid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI Map_Generic_ਨਕਾਬ(PDWORD Access_ਨਕਾਬ,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD n_Acl_ਲੰਮਾਈ,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_ਲੰਮਾਈ,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_Acl_Information(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_ਲੰਮਾਈ,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Starting_Ace_ਸੂਚਕਾਂਕ,LPVOID pAceList,DWORD n_Ace_List_ਲੰਮਾਈ);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dw_Ace_ਸੂਚਕਾਂਕ);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dw_Ace_ਸੂਚਕਾਂਕ,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Access_Allowed_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ਨਕਾਬ,PSID pSid);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Access_Allowed_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ਨਕਾਬ,PSID pSid);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Access_Denied_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ਨਕਾਬ,PSID pSid);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Access_Denied_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ਨਕਾਬ,PSID pSid);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Audit_Access_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Access_ਨਕਾਬ,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Audit_Access_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dw_Access_ਨਕਾਬ,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Access_Allowed_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ਨਕਾਬ,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Access_Denied_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ਨਕਾਬ,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI ਜੋੜੋ_Audit_Access_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ਨਕਾਬ,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI ਲੱਭੋ_ਪਹਿਲਾ_Free_Ace(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI Get_Security_Descriptor_ਲੰਮਾਈ(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_Security_Descriptor_Control(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL Control_ਬਿੱਟ_ਦਾ_Interest,SECURITY_DESCRIPTOR_CONTROL Control_ਬਿੱਟ_ਮੰਜ਼ਿਲ_ਸੈੱਟ);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_Security_Descriptor_Dacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_Security_Descriptor_Sacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_Security_Descriptor_Owner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_Security_Descriptor_ਸਮੂਹ(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID p_ਸਮੂਹ,WINBOOL b_ਸਮੂਹ_Defaulted);
  WINADVAPI WINBOOL WINAPI Get_Security_Descriptor_ਸਮੂਹ(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *p_ਸਮੂਹ,LPBOOL lpb_ਸਮੂਹ_Defaulted);
  WINADVAPI DWORD WINAPI ਸੈੱਟ_Security_Descriptor_RMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI Create_ਨਿੱਜੀ_Object_Security(PSECURITY_DESCRIPTOR ਮਾਪਾ_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Convert_ਮੰਜ਼ਿਲ_Auto_Inherit_ਨਿੱਜੀ_Object_Security(PSECURITY_DESCRIPTOR ਮਾਪਾ_Descriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_ਨਿੱਜੀ_Object_Security_Ex(PSECURITY_DESCRIPTOR ਮਾਪਾ_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_ਨਿੱਜੀ_Object_Security_With_ਗੁਣਜ_Inheritance(PSECURITY_DESCRIPTOR ਮਾਪਾ_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG Guid_ਗਿਣਤੀ,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_ਨਿੱਜੀ_Object_Security (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_ਨਿੱਜੀ_Object_Security_Ex (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI Get_ਨਿੱਜੀ_Object_Security(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD Descriptor_ਲੰਮਾਈ,PDWORD Return_ਲੰਮਾਈ);
  WINADVAPI WINBOOL WINAPI Destroy_ਨਿੱਜੀ_Object_Security(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_ਬਫਰ_ਲੰਮਾਈ);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdw_Absolute_Security_Descriptor_ਮਾਪ,PACL pDacl,LPDWORD lpdw_Dacl_ਮਾਪ,PACL pSacl,LPDWORD lpdw_Sacl_ਮਾਪ,PSID pOwner,LPDWORD lpdw_Owner_ਮਾਪ,PSID p_Primary_ਸਮੂਹ,LPDWORD lpdw_Primary_ਸਮੂਹ_ਮਾਪ);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_ਬਫਰ_ਮਾਪ);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_File_Security_A(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_File_Security_W(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_ਲੰਮਾਈ,LPDWORD lpn_ਲੰਮਾਈ_Needed);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_ਲੰਮਾਈ,LPDWORD lpn_ਲੰਮਾਈ_Needed);
  WINADVAPI WINBOOL WINAPI ਸੈੱਟ_Kernel_Object_Security(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_Change_Notification_A(LPCSTR lp_ਰਸਤਾ_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_Change_Notification_W(LPCWSTR lp_ਰਸਤਾ_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_ਅਗਲਾ_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_Close_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lp_ਬਫਰ,DWORD n_ਬਫਰ_ਲੰਮਾਈ,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lp_ਬਾਈਟਾਂ_Returned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI Virtual_ਤਾਲਾ(LPVOID lp_ਪਤਾ,ਮਾਪ_T dw_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lp_ਪਤਾ,ਮਾਪ_T dw_ਮਾਪ);
  WINBASEAPI LPVOID WINAPI Map_View_ਦਾ_File_Ex(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_ਵਿੱਥ_ਉੱਚਾ,DWORD dw_File_ਵਿੱਥ_ਨੀਵਾਂ,ਮਾਪ_T dw_ਸੰਖਿਆ_ਦਾ_ਬਾਈਟਾਂ_ਮੰਜ਼ਿਲ_Map,LPVOID lp_ਅਧਾਰ_ਪਤਾ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_ਤਰਜੀਹ_Class(HANDLE hProcess,DWORD dw_ਤਰਜੀਹ_Class);
  WINBASEAPI DWORD WINAPI Get_ਤਰਜੀਹ_Class(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI Is_Bad_ਕੋਡ_Ptr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_ਮੁੱਲ_A(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_ਮੁੱਲ_W(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeNameA(LPCSTR lpSystemName,PLUID lpLuid,LPSTR lpName,LPDWORD cchName);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeNameW(LPCWSTR lpSystemName,PLUID lpLuid,LPWSTR lpName,LPDWORD cchName);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeDisplayNameA(LPCSTR lpSystemName,LPCSTR lpName,LPSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
  WINADVAPI WINBOOL WINAPI LookupPrivilegeDisplayNameW(LPCWSTR lpSystemName,LPCWSTR lpName,LPWSTR lpDisplayName,LPDWORD cchDisplayName,LPDWORD lpLanguageId);
  WINADVAPI WINBOOL WINAPI AllocateLocallyUniqueId(PLUID Luid);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBA(LPCSTR lpDef,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBW(LPCWSTR lpDef,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBAndTimeoutsA(LPCSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI BuildCommDCBAndTimeoutsW(LPCWSTR lpDef,LPDCB lpDCB,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI CommConfigDialogA(LPCSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
  WINBASEAPI WINBOOL WINAPI CommConfigDialogW(LPCWSTR lpszName,HWND hWnd,LPCOMMCONFIG lpCC);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Default_Comm_Config_A(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Default_Comm_Config_W(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_ਮਾਪ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_COMPUTERNAME_ਲੰਮਾਈ 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lp_ਬਫਰ,LPDWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lp_ਬਫਰ,LPDWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Computer_Name_A(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Computer_Name_W(LPCWSTR lpComputerName);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਗਿਣਤੀ _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lp_ਬਫਰ,LPDWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lp_ਬਫਰ,LPDWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Computer_Name_Ex_A(COMPUTER_NAME_FORMAT NameType,LPCSTR lp_ਬਫਰ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Computer_Name_Ex_W(COMPUTER_NAME_FORMAT NameType,LPCWSTR lp_ਬਫਰ);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_ਮੰਜ਼ਿਲ_Computer_Name_A(LPCSTR Hostname,LPSTR ComputerName,LPDWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_ਮੰਜ਼ਿਲ_Computer_Name_W(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD n_ਮਾਪ);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lp_ਬਫਰ,LPDWORD pcb_ਬਫਰ);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lp_ਬਫਰ,LPDWORD pcb_ਬਫਰ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_LOGON_INTERACTIVE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_LOGON_ਜਾਲ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_LOGON_BATCH 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_LOGON_SERVICE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_LOGON_UNLOCK 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_LOGON_ਜਾਲ_CLEARTEXT 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_LOGON_NEW_CREDENTIALS 9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_PROVIDER_DEFAULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_PROVIDER_WINNT35 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_PROVIDER_WINNT40 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON32_PROVIDER_WINNT50 3

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LogonUser LogonUserW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LogonUserEx LogonUserExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateProcessAsUser CreateProcessAsUserW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LogonUser LogonUserA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LogonUserEx LogonUserExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateProcessAsUser CreateProcessAsUserA
#ਜੇ_ਅੰਤ

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_ਬਫਰ,LPDWORD pdw_Profile_ਲੰਮਾਈ,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_ਬਫਰ,LPDWORD pdw_Profile_ਲੰਮਾਈ,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lp_Command_ਸਤਰ,LPSECURITY_ਗੁਣ lp_Process_ਗੁਣ,LPSECURITY_ਗੁਣ lp_Thread_ਗੁਣ,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lp_Command_ਸਤਰ,LPSECURITY_ਗੁਣ lp_Process_ਗੁਣ,LPSECURITY_ਗੁਣ lp_Thread_ਗੁਣ,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON_WITH_PROFILE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON_NETCREDENTIALS_ONLY 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGON_ZERO_PASSWORD_ਬਫਰ 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_ਸਤਰ,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_ਸਤਰ,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_ਗੁਣ lp_Token_ਗੁਣ,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD Disable_Sid_ਗਿਣਤੀ,PSID_AND_ਗੁਣ Sids_ਮੰਜ਼ਿਲ_Disable,DWORD Delete_Privilege_ਗਿਣਤੀ,PLUID_AND_ਗੁਣ Privileges_ਮੰਜ਼ਿਲ_Delete,DWORD Restricted_Sid_ਗਿਣਤੀ,PSID_AND_ਗੁਣ Sids_ਮੰਜ਼ਿਲ_Restrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID Sid_ਮੰਜ਼ਿਲ_Check,PBOOL IsMember);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI ਰਜਿਸਟਰ_Wait_For_Single_Object(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI ਰਜਿਸਟਰ_Wait_For_Single_Object_Ex(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI ਕਤਾਰ_User_Work_ਵਸਤੂ(LPTHREAD_ਸ਼ੁਰੂ_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI Create_Timer_ਕਤਾਰ(VOID);
  WINBASEAPI WINBOOL WINAPI Create_Timer_ਕਤਾਰ_Timer(PHANDLE phNewTimer,HANDLE Timer_ਕਤਾਰ,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_ਸਮਾਂ,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI Change_Timer_ਕਤਾਰ_Timer(HANDLE Timer_ਕਤਾਰ,HANDLE Timer,ULONG Due_ਸਮਾਂ,ULONG Period);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_ਕਤਾਰ_Timer(HANDLE Timer_ਕਤਾਰ,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_ਕਤਾਰ_Ex(HANDLE Timer_ਕਤਾਰ,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI ਸੈੱਟ_Timer_ਕਤਾਰ_Timer(HANDLE Timer_ਕਤਾਰ,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_ਸਮਾਂ,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI Cancel_Timer_ਕਤਾਰ_Timer(HANDLE Timer_ਕਤਾਰ,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_ਕਤਾਰ(HANDLE Timer_ਕਤਾਰ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HW_PROFILE_GUIDLEN 39
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAX_PROFILE_LEN 80

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOCKINFO_UNDOCKED (0x1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOCKINFO_DOCKED (0x2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOCKINFO_USER_SUPPLIED (0x4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HW_PROFILE_INFOW HW_PROFILE_INFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HW_PROFILE_INFOA HW_PROFILE_INFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCurrentHwProfile GetCurrentHwProfileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਸੰਸਕਰਣ_Ex Get_ਸੰਸਕਰਣ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Verify_ਸੰਸਕਰਣ_Info Verify_ਸੰਸਕਰਣ_Info_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCurrentHwProfile GetCurrentHwProfileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਸੰਸਕਰਣ_Ex Get_ਸੰਸਕਰਣ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Verify_ਸੰਸਕਰਣ_Info Verify_ਸੰਸਕਰਣ_Info_A
#ਜੇ_ਅੰਤ

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lp_Performance_ਗਿਣਤੀ);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI Get_ਸੰਸਕਰਣ_Ex_A(LPOSVERSIONINFOA lp_ਸੰਸਕਰਣ_Information);
  WINBASEAPI WINBOOL WINAPI Get_ਸੰਸਕਰਣ_Ex_W(LPOSVERSIONINFOW lp_ਸੰਸਕਰਣ_Information);
  WINBASEAPI WINBOOL WINAPI Verify_ਸੰਸਕਰਣ_Info_A(LPOSVERSIONINFOEXA lp_ਸੰਸਕਰਣ_Information,DWORD dw_Type_ਨਕਾਬ,DWORDLONG dwl_Condition_ਨਕਾਬ);
  WINBASEAPI WINBOOL WINAPI Verify_ਸੰਸਕਰਣ_Info_W(LPOSVERSIONINFOEXW lp_ਸੰਸਕਰਣ_Information,DWORD dw_Type_ਨਕਾਬ,DWORDLONG dwl_Condition_ਨਕਾਬ);

#ਅਨ੍ਤਰ੍ਭਾਵ <winerror.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_ਸਾਧਾਰਨ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_HARDERR 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_GP_TRAP 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_SIGNAL 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AC_ਸਤਰ_OFFLINE 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AC_ਸਤਰ_ONLINE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AC_ਸਤਰ_BACKUP_POWER 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AC_ਸਤਰ_UNKNOWN 0xff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BATTERY_FLAG_ਉੱਚਾ 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BATTERY_FLAG_ਨੀਵਾਂ 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BATTERY_FLAG_CRITICAL 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BATTERY_FLAG_CHARGING 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BATTERY_FLAG_NO_BATTERY 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BATTERY_FLAG_UNKNOWN 0xff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BATTERY_PERCENTAGE_UNKNOWN 0xff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BATTERY_LIFE_UNKNOWN 0xffffffff

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ SYSTEM_POWER_ਸਥਿਤੀ {
    BYTE ACLine_ਸਥਿਤੀ;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD Battery_Life_ਸਮਾਂ;
    DWORD Battery_ਭਰਿਆ_Life_ਸਮਾਂ;
  } SYSTEM_POWER_ਸਥਿਤੀ_2,*LPSYSTEM_POWER_ਸਥਿਤੀ;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਕੰਮ_Object Create_ਕੰਮ_Object_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Open_ਕੰਮ_Object Open_ਕੰਮ_Object_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_Volume ਲੱਭੋ_ਪਹਿਲਾ_Volume_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਅਗਲਾ_Volume ਲੱਭੋ_ਅਗਲਾ_Volume_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_Volume_Mount_ਬਿੰਦੂ ਲੱਭੋ_ਪਹਿਲਾ_Volume_Mount_ਬਿੰਦੂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਅਗਲਾ_Volume_Mount_ਬਿੰਦੂ ਲੱਭੋ_ਅਗਲਾ_Volume_Mount_ਬਿੰਦੂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Volume_Mount_ਬਿੰਦੂ ਸੈੱਟ_Volume_Mount_ਬਿੰਦੂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Delete_Volume_Mount_ਬਿੰਦੂ Delete_Volume_Mount_ਬਿੰਦੂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Volume_Name_For_Volume_Mount_ਬਿੰਦੂ Get_Volume_Name_For_Volume_Mount_ਬਿੰਦੂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Volume_ਰਸਤਾ_Name Get_Volume_ਰਸਤਾ_Name_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Volume_ਰਸਤਾ_ਨਾਂ_For_Volume_Name Get_Volume_ਰਸਤਾ_ਨਾਂ_For_Volume_Name_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਕੰਮ_Object Create_ਕੰਮ_Object_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Open_ਕੰਮ_Object Open_ਕੰਮ_Object_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_Volume ਲੱਭੋ_ਪਹਿਲਾ_Volume_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਅਗਲਾ_Volume ਲੱਭੋ_ਅਗਲਾ_Volume_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਪਹਿਲਾ_Volume_Mount_ਬਿੰਦੂ ਲੱਭੋ_ਪਹਿਲਾ_Volume_Mount_ਬਿੰਦੂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਅਗਲਾ_Volume_Mount_ਬਿੰਦੂ ਲੱਭੋ_ਅਗਲਾ_Volume_Mount_ਬਿੰਦੂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Volume_Mount_ਬਿੰਦੂ ਸੈੱਟ_Volume_Mount_ਬਿੰਦੂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Delete_Volume_Mount_ਬਿੰਦੂ Delete_Volume_Mount_ਬਿੰਦੂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Volume_Name_For_Volume_Mount_ਬਿੰਦੂ Get_Volume_Name_For_Volume_Mount_ਬਿੰਦੂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Volume_ਰਸਤਾ_Name Get_Volume_ਰਸਤਾ_Name_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Volume_ਰਸਤਾ_ਨਾਂ_For_Volume_Name Get_Volume_ਰਸਤਾ_ਨਾਂ_For_Volume_Name_A
#ਜੇ_ਅੰਤ

  WINBOOL WINAPI Get_System_Power_ਸਥਿਤੀ(LPSYSTEM_POWER_ਸਥਿਤੀ lp_System_Power_ਸਥਿਤੀ);
  WINBOOL WINAPI ਸੈੱਟ_System_Power_State(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI Allocate_User_Physical_ਪੰਨੇ(HANDLE hProcess,PULONG_PTR ਸੰਖਿਆ_ਦਾ_ਪੰਨੇ,PULONG_PTR ਪੰਨਾ_Array);
  WINBASEAPI WINBOOL WINAPI Free_User_Physical_ਪੰਨੇ(HANDLE hProcess,PULONG_PTR ਸੰਖਿਆ_ਦਾ_ਪੰਨੇ,PULONG_PTR ਪੰਨਾ_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_ਪੰਨੇ(PVOID Virtual_ਪਤਾ,ULONG_PTR ਸੰਖਿਆ_ਦਾ_ਪੰਨੇ,PULONG_PTR ਪੰਨਾ_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_ਪੰਨੇ_Scatter(PVOID *Virtual_ਪਤੇ,ULONG_PTR ਸੰਖਿਆ_ਦਾ_ਪੰਨੇ,PULONG_PTR ਪੰਨਾ_Array);
  WINBASEAPI HANDLE WINAPI Create_ਕੰਮ_Object_A(LPSECURITY_ਗੁਣ lp_ਕੰਮ_ਗੁਣ,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Create_ਕੰਮ_Object_W(LPSECURITY_ਗੁਣ lp_ਕੰਮ_ਗੁਣ,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_ਕੰਮ_Object_A(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_ਕੰਮ_Object_W(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI ਸੌਂਪੋ_Process_ਮੰਜ਼ਿਲ_ਕੰਮ_Object(HANDLE h_ਕੰਮ,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI Terminate_ਕੰਮ_Object(HANDLE h_ਕੰਮ,UINT u_Exit_ਕੋਡ);
  WINBASEAPI WINBOOL WINAPI Query_Information_ਕੰਮ_Object(HANDLE h_ਕੰਮ,JOBOBJECTINFOCLASS ਕੰਮ_Object_Information_Class,LPVOID lp_ਕੰਮ_Object_Information,DWORD cb_ਕੰਮ_Object_Information_ਲੰਮਾਈ,LPDWORD lp_Return_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Information_ਕੰਮ_Object(HANDLE h_ਕੰਮ,JOBOBJECTINFOCLASS ਕੰਮ_Object_Information_Class,LPVOID lp_ਕੰਮ_Object_Information,DWORD cb_ਕੰਮ_Object_Information_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI Is_Process_ਵਿੱਚ_ਕੰਮ(HANDLE ProcessHandle,HANDLE ਕੰਮ_Handle,PBOOL ਨਤੀਜਾ_3);
  WINBASEAPI WINBOOL WINAPI Create_ਕੰਮ_ਸੈੱਟ(ULONG ਅੰਕ_ਕੰਮ,PJOB_ਸੈੱਟ_ARRAY User_ਕੰਮ_ਸੈੱਟ,ULONG Flags);
  WINBASEAPI PVOID WINAPI ਜੋੜੋ_Vectored_Exception_Handler (ULONG ਪਹਿਲਾ_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI ਜੋੜੋ_Vectored_Continue_Handler (ULONG ਪਹਿਲਾ_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_Volume_A(LPSTR lpszVolumeName,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_Volume_W(LPWSTR lpszVolumeName,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_ਅਗਲਾ_Volume_A(HANDLE h_ਲੱਭੋ_Volume,LPSTR lpszVolumeName,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_ਅਗਲਾ_Volume_W(HANDLE h_ਲੱਭੋ_Volume,LPWSTR lpszVolumeName,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_Volume_Close(HANDLE h_ਲੱਭੋ_Volume);
  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_Volume_Mount_ਬਿੰਦੂ_A(LPCSTR lpsz_ਜੜ੍ਹ_ਰਸਤਾ_Name,LPSTR lpsz_Volume_Mount_ਬਿੰਦੂ,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI HANDLE WINAPI ਲੱਭੋ_ਪਹਿਲਾ_Volume_Mount_ਬਿੰਦੂ_W(LPCWSTR lpsz_ਜੜ੍ਹ_ਰਸਤਾ_Name,LPWSTR lpsz_Volume_Mount_ਬਿੰਦੂ,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_ਅਗਲਾ_Volume_Mount_ਬਿੰਦੂ_A(HANDLE h_ਲੱਭੋ_Volume_Mount_ਬਿੰਦੂ,LPSTR lpsz_Volume_Mount_ਬਿੰਦੂ,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_ਅਗਲਾ_Volume_Mount_ਬਿੰਦੂ_W(HANDLE h_ਲੱਭੋ_Volume_Mount_ਬਿੰਦੂ,LPWSTR lpsz_Volume_Mount_ਬਿੰਦੂ,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_Volume_Mount_ਬਿੰਦੂ_Close(HANDLE h_ਲੱਭੋ_Volume_Mount_ਬਿੰਦੂ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Volume_Mount_ਬਿੰਦੂ_A(LPCSTR lpsz_Volume_Mount_ਬਿੰਦੂ,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Volume_Mount_ਬਿੰਦੂ_W(LPCWSTR lpsz_Volume_Mount_ਬਿੰਦੂ,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_ਬਿੰਦੂ_A(LPCSTR lpsz_Volume_Mount_ਬਿੰਦੂ);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_ਬਿੰਦੂ_W(LPCWSTR lpsz_Volume_Mount_ਬਿੰਦੂ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_ਬਿੰਦੂ_A(LPCSTR lpsz_Volume_Mount_ਬਿੰਦੂ,LPSTR lpszVolumeName,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_ਬਿੰਦੂ_W(LPCWSTR lpsz_Volume_Mount_ਬਿੰਦੂ,LPWSTR lpszVolumeName,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_ਰਸਤਾ_Name_A(LPCSTR lpszFileName,LPSTR lpsz_Volume_ਰਸਤਾ_Name,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_ਰਸਤਾ_Name_W(LPCWSTR lpszFileName,LPWSTR lpsz_Volume_ਰਸਤਾ_Name,DWORD cch_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_ਰਸਤਾ_ਨਾਂ_For_Volume_Name_A(LPCSTR lpszVolumeName,LPCH lpsz_Volume_ਰਸਤਾ_ਨਾਂ,DWORD cch_ਬਫਰ_ਲੰਮਾਈ,PDWORD lpcch_Return_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_ਰਸਤਾ_ਨਾਂ_For_Volume_Name_W(LPCWSTR lpszVolumeName,LPWCH lpsz_Volume_ਰਸਤਾ_ਨਾਂ,DWORD cch_ਬਫਰ_ਲੰਮਾਈ,PDWORD lpcch_Return_ਲੰਮਾਈ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTCTX_FLAG_LANGID_VALID 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTCTX_FLAG_ਸੈੱਟ_PROCESS_DEFAULT 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTCTX_FLAG_ਸਰੋਤ_IS_ASSEMBLYREF 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTCTX_FLAG_HMODULE_VALID 0x80

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ACTCTXA {
    ULONG cb_ਮਾਪ;
    DWORD dwFlags;
    LPCSTR lp_ਸਰੋਤ;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ACTCTXW {
    ULONG cb_ਮਾਪ;
    DWORD dwFlags;
    LPCWSTR lp_ਸਰੋਤ;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ACTCTXA *PCACTCTXA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ACTCTXW *PCACTCTXW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACTCTXW ACTCTX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PACTCTXW PACTCTX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PCACTCTXW PCACTCTX;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ACTCTXA ACTCTX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PACTCTXA PACTCTX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PCACTCTXA PCACTCTX;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateActCtx CreateActCtxW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateActCtx CreateActCtxA
#ਜੇ_ਅੰਤ

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI ਜੋੜੋ_Ref_Act_Ctx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ACTCTX_SECTION_KEYED_ਅੰਕੜੇ_2600 {
    ULONG cb_ਮਾਪ;
    ULONG ul_ਅੰਕੜੇ_Format_ਸੰਸਕਰਣ;
    PVOID lp_ਅੰਕੜੇ;
    ULONG ul_ਲੰਮਾਈ;
    PVOID lp_Section_Global_ਅੰਕੜੇ;
    ULONG ul_Section_Global_ਅੰਕੜੇ_ਲੰਮਾਈ;
    PVOID lp_Section_ਅਧਾਰ;
    ULONG ul_Section_ਕੁੱਲ_ਲੰਮਾਈ;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_ਸੂਚਕਾਂਕ;
  } ACTCTX_SECTION_KEYED_ਅੰਕੜੇ_2600,*PACTCTX_SECTION_KEYED_ਅੰਕੜੇ_2600;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ACTCTX_SECTION_KEYED_ਅੰਕੜੇ_2600 *PCACTCTX_SECTION_KEYED_ਅੰਕੜੇ_2600;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ACTCTX_SECTION_KEYED_ਅੰਕੜੇ_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lp_Section_ਅਧਾਰ;
    ULONG ul_Section_ਲੰਮਾਈ;
    PVOID lp_Section_Global_ਅੰਕੜੇ_ਅਧਾਰ;
    ULONG ul_Section_Global_ਅੰਕੜੇ_ਲੰਮਾਈ;
  } ACTCTX_SECTION_KEYED_ਅੰਕੜੇ_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_ਅੰਕੜੇ_ASSEMBLY_METADATA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ACTCTX_SECTION_KEYED_ਅੰਕੜੇ_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_ਅੰਕੜੇ_ASSEMBLY_METADATA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ACTCTX_SECTION_KEYED_ਅੰਕੜੇ {
    ULONG cb_ਮਾਪ;
    ULONG ul_ਅੰਕੜੇ_Format_ਸੰਸਕਰਣ;
    PVOID lp_ਅੰਕੜੇ;
    ULONG ul_ਲੰਮਾਈ;
    PVOID lp_Section_Global_ਅੰਕੜੇ;
    ULONG ul_Section_Global_ਅੰਕੜੇ_ਲੰਮਾਈ;
    PVOID lp_Section_ਅਧਾਰ;
    ULONG ul_Section_ਕੁੱਲ_ਲੰਮਾਈ;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_ਸੂਚਕਾਂਕ;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_ਅੰਕੜੇ_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_ਅੰਕੜੇ,*PACTCTX_SECTION_KEYED_ਅੰਕੜੇ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ACTCTX_SECTION_KEYED_ਅੰਕੜੇ *PCACTCTX_SECTION_KEYED_ਅੰਕੜੇ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ACTCTX_SECTION_ਕੁੰਜੀ_RETURN_HACTCTX 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ACTCTX_SECTION_ਕੁੰਜੀ_RETURN_FLAGS 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ACTCTX_SECTION_ਕੁੰਜੀ_RETURN_ASSEMBLY_METADATA 0x4

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Act_Ctx_Section_String ਲੱਭੋ_Act_Ctx_Section_String_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_Act_Ctx_Section_String ਲੱਭੋ_Act_Ctx_Section_String_A
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_Act_Ctx_Section_String_A(DWORD dwFlags,ਅਚਲ GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lp_String_ਮੰਜ਼ਿਲ_ਲੱਭੋ,PACTCTX_SECTION_KEYED_ਅੰਕੜੇ Returned_ਅੰਕੜੇ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_Act_Ctx_Section_String_W(DWORD dwFlags,ਅਚਲ GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lp_String_ਮੰਜ਼ਿਲ_ਲੱਭੋ,PACTCTX_SECTION_KEYED_ਅੰਕੜੇ Returned_ਅੰਕੜੇ);
  WINBASEAPI WINBOOL WINAPI ਲੱਭੋ_Act_Ctx_Section_Guid(DWORD dwFlags,ਅਚਲ GUID *lpExtensionGuid,ULONG ulSectionId,ਅਚਲ GUID *lp_Guid_ਮੰਜ਼ਿਲ_ਲੱਭੋ,PACTCTX_SECTION_KEYED_ਅੰਕੜੇ Returned_ਅੰਕੜੇ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਅਚਲ ਬਣਤਰ _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUERY_ACTCTX_FLAG_USE_ਸਰਗਰਮ_ACTCTX 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUERY_ACTCTX_FLAG_ACTCTX_IS_ਪਤਾ 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_ਬਫਰ,ਮਾਪ_T cb_ਬਫਰ,ਮਾਪ_T *pcbWrittenOrRequired);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_ਬਫਰ,ਮਾਪ_T cb_ਬਫਰ,ਮਾਪ_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI Process_Id_ਮੰਜ਼ਿਲ_Session_Id(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGet_ਸਰਗਰਮ_Console_Session_Id();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION ਬਫਰ_3,PDWORD Returned_ਲੰਮਾਈ);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Highest_ਗੰਢ_ਸੰਖਿਆ(PULONG Highest_ਗੰਢ_ਸੰਖਿਆ);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Processor_ਗੰਢ(UCHAR Processor,PUCHAR ਗੰਢ_ਸੰਖਿਆ);
  WINBASEAPI WINBOOL WINAPI Get_Numa_ਗੰਢ_Processor_ਨਕਾਬ(UCHAR ਗੰਢ_2,PULONGLONG Processor_ਨਕਾਬ);
  WINBASEAPI WINBOOL WINAPI Get_Numa_ਉਪਲਬਧ_ਸਮ੍ਰਿਤੀ_ਗੰਢ(UCHAR ਗੰਢ_2,PULONGLONG ਉਪਲਬਧ_ਬਾਈਟਾਂ);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
