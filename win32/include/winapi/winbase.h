/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINBASE_
#ವ್ಯಾಖ್ಯಾನಿಸು _WINBASE_

#ವ್ಯಾಖ್ಯಾನಿಸು WINADVAPI DECLSPEC_IMPORT
#ವ್ಯಾಖ್ಯಾನಿಸು WINBASEAPI DECLSPEC_IMPORT
#ವ್ಯಾಖ್ಯಾನಿಸು ZAWPROXYAPI DECLSPEC_IMPORT

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು Define_Handle_ಕೋಷ್ಟಕ(w) ((w),TRUE)
#ವ್ಯಾಖ್ಯಾನಿಸು ಎಲ್ಲೆ_Ems_ಪುಟಗಳು(dw)
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಅದಲುಬದಲು_Area_ಗಾತ್ರ(w) (w)
#ವ್ಯಾಖ್ಯಾನಿಸು ಬೀಗ_Segment(w) GlobalFix((HANDLE)(w))
#ವ್ಯಾಖ್ಯಾನಿಸು UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Current_ಸಮಯ() Get_Tick_ಎಣಿಕೆ()

#ವ್ಯಾಖ್ಯಾನಿಸು Yield()

#ವ್ಯಾಖ್ಯಾನಿಸು INVALID_HANDLE_ಮೌಲ್ಯ ((HANDLE)(LONG_PTR)-1)
#ವ್ಯಾಖ್ಯಾನಿಸು INVALID_FILE_ಗಾತ್ರ ((DWORD)0xffffffff)
#ವ್ಯಾಖ್ಯಾನಿಸು INVALID_ಗಣ_FILE_ಸೂಚಕ ((DWORD)-1)
#ವ್ಯಾಖ್ಯಾನಿಸು INVALID_FILE_ಗುಣಲಕ್ಷಣಗಳು ((DWORD)-1)

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_BEGIN 0
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_CURRENT 1
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ಕೊನೆ 2

#ವ್ಯಾಖ್ಯಾನಿಸು ಸಮಯ_ZONE_ID_INVALID ((DWORD)0xffffffff)

#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_FAILED ((DWORD)0xffffffff)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_OBJECT_0 ((ಸ್ಥಿತಿ_WAIT_0) + 0)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_ABANDONED ((ಸ್ಥಿತಿ_ABANDONED_WAIT_0) + 0)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_ABANDONED_0 ((ಸ್ಥಿತಿ_ABANDONED_WAIT_0) + 0)
#ವ್ಯಾಖ್ಯಾನಿಸು WAIT_IO_COMPLETION ಸ್ಥಿತಿ_USER_APC
#ವ್ಯಾಖ್ಯಾನಿಸು STILL_ಸಕ್ರಿಯ ಸ್ಥಿತಿ_PENDING
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_ACCESS_VIOLATION ಸ್ಥಿತಿ_ACCESS_VIOLATION
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_DATATYPE_MISALIGNMENT ಸ್ಥಿತಿ_DATATYPE_MISALIGNMENT
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_BREAKPOINT ಸ್ಥಿತಿ_BREAKPOINT
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_SINGLE_ಹೆಜ್ಜೆ ಸ್ಥಿತಿ_SINGLE_ಹೆಜ್ಜೆ
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_ARRAY_BOUNDS_EXCEEDED ಸ್ಥಿತಿ_ARRAY_BOUNDS_EXCEEDED
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_FLT_DENORMAL_ಕಾರ್ಯಾಂಶ ಸ್ಥಿತಿ_FLOAT_DENORMAL_ಕಾರ್ಯಾಂಶ
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_FLT_DIVIDE_BY_ZERO ಸ್ಥಿತಿ_FLOAT_DIVIDE_BY_ZERO
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_FLT_INEXACT_ಫಲಿತಾಂಶ ಸ್ಥಿತಿ_FLOAT_INEXACT_ಫಲಿತಾಂಶ
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_FLT_INVALID_OPERATION ಸ್ಥಿತಿ_FLOAT_INVALID_OPERATION
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_FLT_ಅತಿಪ್ರವಾಹ ಸ್ಥಿತಿ_FLOAT_ಅತಿಪ್ರವಾಹ
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_FLT_ರಾಶಿ_CHECK ಸ್ಥಿತಿ_FLOAT_ರಾಶಿ_CHECK
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_FLT_UNDERFLOW ಸ್ಥಿತಿ_FLOAT_UNDERFLOW
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_INT_DIVIDE_BY_ZERO ಸ್ಥಿತಿ_INTEGER_DIVIDE_BY_ZERO
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_INT_ಅತಿಪ್ರವಾಹ ಸ್ಥಿತಿ_INTEGER_ಅತಿಪ್ರವಾಹ
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_PRIV_INSTRUCTION ಸ್ಥಿತಿ_PRIVILEGED_INSTRUCTION
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_ಒಳ_ಪುಟ_ERROR ಸ್ಥಿತಿ_ಒಳ_ಪುಟ_ERROR
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_ILLEGAL_INSTRUCTION ಸ್ಥಿತಿ_ILLEGAL_INSTRUCTION
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_NONCONTINUABLE_EXCEPTION ಸ್ಥಿತಿ_NONCONTINUABLE_EXCEPTION
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_ರಾಶಿ_ಅತಿಪ್ರವಾಹ ಸ್ಥಿತಿ_ರಾಶಿ_ಅತಿಪ್ರವಾಹ
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_INVALID_DISPOSITION ಸ್ಥಿತಿ_INVALID_DISPOSITION
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_GUARD_ಪುಟ ಸ್ಥಿತಿ_GUARD_ಪುಟ_VIOLATION
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_INVALID_HANDLE ಸ್ಥಿತಿ_INVALID_HANDLE
#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_POSSIBLE_DEADLOCK ಸ್ಥಿತಿ_POSSIBLE_DEADLOCK
#ವ್ಯಾಖ್ಯಾನಿಸು CONTROL_C_EXIT ಸ್ಥಿತಿ_CONTROL_C_EXIT
#ವ್ಯಾಖ್ಯಾನಿಸು Move_ಸ್ಮರಣೆ Rtl_Move_ಸ್ಮರಣೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Copy_ಸ್ಮರಣೆ Rtl_Copy_ಸ್ಮರಣೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Fill_ಸ್ಮರಣೆ Rtl_Fill_ಸ್ಮರಣೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Zero_ಸ್ಮರಣೆ Rtl_Zero_ಸ್ಮರಣೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Secure_Zero_ಸ್ಮರಣೆ Rtl_Secure_Zero_ಸ್ಮರಣೆ

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_WRITE_THROUGH 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_OVERLAPPED 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_NO_BUFFERING 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_RANDOM_ACCESS 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_SEQUENTIAL_ಪರಿಶೀಲನೆ 0x8000000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_POSIX_SEMANTICS 0x1000000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_OPEN_REPARSE_ಬಿಂದು 0x200000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_OPEN_NO_RECALL 0x100000
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_FLAG_ಮೊದಲ_PIPE_INSTANCE 0x80000

#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_NEW 1
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_ALWAYS 2
#ವ್ಯಾಖ್ಯಾನಿಸು OPEN_EXISTING 3
#ವ್ಯಾಖ್ಯಾನಿಸು OPEN_ALWAYS 4
#ವ್ಯಾಖ್ಯಾನಿಸು TRUNCATE_EXISTING 5

#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರಗತಿ_CONTINUE 0
#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರಗತಿ_CANCEL 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರಗತಿ_STOP 2
#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರಗತಿ_QUIET 3

#ವ್ಯಾಖ್ಯಾನಿಸು CALLBACK_CHUNK_ಪೂರ್ಣಗೊಂಡ 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು CALLBACK_ಹರಿವು_SWITCH 0x1

#ವ್ಯಾಖ್ಯಾನಿಸು COPY_FILE_FAIL_IF_EXISTS 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು COPY_FILE_RESTARTABLE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು COPY_FILE_OPEN_ಮೂಲ_FOR_WRITE 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#ವ್ಯಾಖ್ಯಾನಿಸು REPLACEFILE_WRITE_THROUGH 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು REPLACEFILE_IGNORE_ವಿಲೀನ_ERRORS 0x2

#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_ACCESS_INBOUND 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_ACCESS_OUTBOUND 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_ACCESS_DUPLEX 0x3

#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_CLIENT_ಕೊನೆ 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_SERVER_ಕೊನೆ 0x1

#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_WAIT 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_NOWAIT 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_READMODE_BYTE 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_READMODE_ಸಂದೇಶ 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_TYPE_BYTE 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_TYPE_ಸಂದೇಶ 0x4

#ವ್ಯಾಖ್ಯಾನಿಸು PIPE_UNLIMITED_INSTANCES 255

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_DELEGATION (SecurityDelegation << 16)

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_CONTEXT_TRACKING 0x40000
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_EFFECTIVE_ONLY 0x80000

#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_SQOS_PRESENT 0x100000
#ವ್ಯಾಖ್ಯಾನಿಸು SECURITY_VALID_SQOS_FLAGS 0x1f0000

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OVERLAPPED {
    ULONG_PTR ಆಂತರಿಕ;
    ULONG_PTR ಆಂತರಿಕ_ಮೇಲಿನ;
    ಒಕ್ಕೂಟ {
      ರಚನೆ {
	DWORD ಸ್ಥಾನಾಂತರ_3;
	DWORD ಸ್ಥಾನಾಂತರ_ಮೇಲಿನ_2;
      };
      PVOID ಸೂಚಕ_3;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SECURITY_ಗುಣಲಕ್ಷಣಗಳು {
    DWORD n_ಉದ್ದಳತೆ;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_ಗುಣಲಕ್ಷಣಗಳು_2,*PSECURITY_ಗುಣಲಕ್ಷಣಗಳು,*LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _FILETIME_
#ವ್ಯಾಖ್ಯಾನಿಸು _FILETIME_
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _FILETIME {
    DWORD dw_ಕೆಳಗಿನ_Date_ಸಮಯ;
    DWORD dw_ಮೇಲಿನ_Date_ಸಮಯ;
  } FILETIME,*PFILETIME,*LPFILETIME;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEMTIME {
    ಶಬ್ದ_3 wYear;
    ಶಬ್ದ_3 wMonth;
    ಶಬ್ದ_3 w_Day_ದ_Week;
    ಶಬ್ದ_3 wDay;
    ಶಬ್ದ_3 wHour;
    ಶಬ್ದ_3 wMinute;
    ಶಬ್ದ_3 w_ಎರಡನೇ;
    ಶಬ್ದ_3 wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD (WINAPI *PTHREAD_ಆರಂಭ_ROUTINE)(LPVOID lpThreadParameter);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PTHREAD_ಆರಂಭ_ROUTINE LPTHREAD_ಆರಂಭ_ROUTINE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (WINAPI *PFIBER_ಆರಂಭ_ROUTINE)(LPVOID lpFiberParameter);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PFIBER_ಆರಂಭ_ROUTINE LPFIBER_ಆರಂಭ_ROUTINE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ RTL_CRITICAL_SECTION CRITICAL_SECTION;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI Encode_ಸೂಚಕ(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_ಸೂಚಕ(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Encode_System_ಸೂಚಕ(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_System_ಸೂಚಕ(PVOID Ptr);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ I_X86_
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PLDT_ನಮೂದು LPLDT_ನಮೂದು;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPVOID LPLDT_ನಮೂದು;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#ವ್ಯಾಖ್ಯಾನಿಸು MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#ವ್ಯಾಖ್ಯಾನಿಸು SP_SERIALCOMM ((DWORD)0x1)

#ವ್ಯಾಖ್ಯಾನಿಸು PST_UNSPECIFIED ((DWORD)0x0)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_RS232 ((DWORD)0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_PARALLELPORT ((DWORD)0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_RS422 ((DWORD)0x3)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_RS423 ((DWORD)0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_RS449 ((DWORD)0x5)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_MODEM ((DWORD)0x6)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_FAX ((DWORD)0x21)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_SCANNER ((DWORD)0x22)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_ಜಾಲ_BRIDGE ((DWORD)0x100)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_LAT ((DWORD)0x101)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_TCPIP_TELNET ((DWORD)0x102)
#ವ್ಯಾಖ್ಯಾನಿಸು PST_X25 ((DWORD)0x103)

#ವ್ಯಾಖ್ಯಾನಿಸು PCF_DTRDSR ((DWORD)0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು PCF_RTSCTS ((DWORD)0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು PCF_RLSD ((DWORD)0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು PCF_PARITY_CHECK ((DWORD)0x8)
#ವ್ಯಾಖ್ಯಾನಿಸು PCF_XONXOFF ((DWORD)0x10)
#ವ್ಯಾಖ್ಯಾನಿಸು PCF_SETXCHAR ((DWORD)0x20)
#ವ್ಯಾಖ್ಯಾನಿಸು PCF_TOTALTIMEOUTS ((DWORD)0x40)
#ವ್ಯಾಖ್ಯಾನಿಸು PCF_INTTIMEOUTS ((DWORD)0x80)
#ವ್ಯಾಖ್ಯಾನಿಸು PCF_SPECIALCHARS ((DWORD)0x100)
#ವ್ಯಾಖ್ಯಾನಿಸು PCF_16BITMODE ((DWORD)0x200)

#ವ್ಯಾಖ್ಯಾನಿಸು SP_PARITY ((DWORD)0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_BAUD ((DWORD)0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_DATABITS ((DWORD)0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_STOPBITS ((DWORD)0x8)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_HANDSHAKING ((DWORD)0x10)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_PARITY_CHECK ((DWORD)0x20)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_RLSD ((DWORD)0x40)

#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_075 ((DWORD)0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_110 ((DWORD)0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_134_5 ((DWORD)0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_150 ((DWORD)0x8)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_300 ((DWORD)0x10)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_600 ((DWORD)0x20)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_1200 ((DWORD)0x40)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_1800 ((DWORD)0x80)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_2400 ((DWORD)0x100)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_4800 ((DWORD)0x200)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_7200 ((DWORD)0x400)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_9600 ((DWORD)0x800)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_14400 ((DWORD)0x1000)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_19200 ((DWORD)0x2000)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_38400 ((DWORD)0x4000)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_56K ((DWORD)0x8000)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_128K ((DWORD)0x10000)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_115200 ((DWORD)0x20000)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_57600 ((DWORD)0x40000)
#ವ್ಯಾಖ್ಯಾನಿಸು BAUD_USER ((DWORD)0x10000000)

#ವ್ಯಾಖ್ಯಾನಿಸು DATABITS_5 ((ಶಬ್ದ_3)0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು DATABITS_6 ((ಶಬ್ದ_3)0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು DATABITS_7 ((ಶಬ್ದ_3)0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು DATABITS_8 ((ಶಬ್ದ_3)0x8)
#ವ್ಯಾಖ್ಯಾನಿಸು DATABITS_16 ((ಶಬ್ದ_3)0x10)
#ವ್ಯಾಖ್ಯಾನಿಸು DATABITS_16X ((ಶಬ್ದ_3)0x20)

#ವ್ಯಾಖ್ಯಾನಿಸು STOPBITS_10 ((ಶಬ್ದ_3)0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು STOPBITS_15 ((ಶಬ್ದ_3)0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು STOPBITS_20 ((ಶಬ್ದ_3)0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು PARITY_NONE ((ಶಬ್ದ_3)0x100)
#ವ್ಯಾಖ್ಯಾನಿಸು PARITY_ODD ((ಶಬ್ದ_3)0x200)
#ವ್ಯಾಖ್ಯಾನಿಸು PARITY_EVEN ((ಶಬ್ದ_3)0x400)
#ವ್ಯಾಖ್ಯಾನಿಸು PARITY_MARK ((ಶಬ್ದ_3)0x800)
#ವ್ಯಾಖ್ಯಾನಿಸು PARITY_SPACE ((ಶಬ್ದ_3)0x1000)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _COMMPROP {
    ಶಬ್ದ_3 w_Packet_ಉದ್ದಳತೆ;
    ಶಬ್ದ_3 w_Packet_ಆವೃತ್ತಿ;
    DWORD dw_Service_ಮುಖವಾಡ;
    DWORD dwReserved1;
    DWORD dw_Max_Tx_ಸರತಿ;
    DWORD dw_Max_Rx_ಸರತಿ;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    ಶಬ್ದ_3 w_Settable_ದತ್ತಾಂಶ;
    ಶಬ್ದ_3 wSettableStopParity;
    DWORD dw_Current_Tx_ಸರತಿ;
    DWORD dw_Current_Rx_ಸರತಿ;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#ವ್ಯಾಖ್ಯಾನಿಸು COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD f_Xoff_ಕಳುಹಿಸಿದ : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cb_ಒಳ_Que;
    DWORD cb_ಹೊರಹೋಗು_Que;
  } COMSTAT,*LPCOMSTAT;

#ವ್ಯಾಖ್ಯಾನಿಸು DTR_CONTROL_DISABLE 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು DTR_CONTROL_ENABLE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು DTR_CONTROL_HANDSHAKE 0x2

#ವ್ಯಾಖ್ಯಾನಿಸು RTS_CONTROL_DISABLE 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು RTS_CONTROL_ENABLE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು RTS_CONTROL_HANDSHAKE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು RTS_CONTROL_TOGGLE 0x3

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _DCB {
    DWORD DCBlength;
    DWORD Baud_ದರ;
    DWORD f_ದ್ವಿಮಾನ: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD f_Dsr_ಸಂವೇದನಾಶೀಲತೆ:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD f_ಹೊರಹೋಗು_X: 1;
    DWORD f_ಒಳ_X: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    ಶಬ್ದ_3 wReserved;
    ಶಬ್ದ_3 XonLim;
    ಶಬ್ದ_3 XoffLim;
    BYTE Byte_ಗಾತ್ರ;
    BYTE Parity;
    BYTE Stop_ಬಿಟ್ಟುಗಳು;
    ಅಕ್ಷರ XonChar;
    ಅಕ್ಷರ XoffChar;
    ಅಕ್ಷರ ErrorChar;
    ಅಕ್ಷರ EofChar;
    ಅಕ್ಷರ EvtChar;
    ಶಬ್ದ_3 wReserved1;
  } DCB,*LPDCB;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD Read_ಒಟ್ಟು_Timeout_Multiplier;
    DWORD Read_ಒಟ್ಟು_Timeout_Constant;
    DWORD Write_ಒಟ್ಟು_Timeout_Multiplier;
    DWORD Write_ಒಟ್ಟು_Timeout_Constant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _COMMCONFIG {
    DWORD dw_ಗಾತ್ರ;
    ಶಬ್ದ_3 w_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3 wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dw_Provider_ಸ್ಥಾನಾಂತರ;
    DWORD dw_Provider_ಗಾತ್ರ;
    WCHAR wc_Provider_ದತ್ತಾಂಶ[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SYSTEM_INFO {
    ಒಕ್ಕೂಟ {
      DWORD dwOemId;
      ರಚನೆ {
	ಶಬ್ದ_3 wProcessorArchitecture;
	ಶಬ್ದ_3 wReserved;
      };
    };
    DWORD dw_ಪುಟ_ಗಾತ್ರ;
    LPVOID lp_Minimum_Application_ವಿಳಾಸ;
    LPVOID lp_ಗರಿಷ್ಠ_Application_ವಿಳಾಸ;
    DWORD_PTR dw_ಸಕ್ರಿಯ_Processor_ಮುಖವಾಡ;
    DWORD dw_ಸಂಖ್ಯೆ_ದ_Processors;
    DWORD dwProcessorType;
    DWORD dw_ಹಂಚಿಕೆ_Granularity;
    ಶಬ್ದ_3 wProcessorLevel;
    ಶಬ್ದ_3 wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#ವ್ಯಾಖ್ಯಾನಿಸು FreeModule(hLibModule) FreeLibrary((hLibModule))
#ವ್ಯಾಖ್ಯಾನಿಸು MakeProcInstance(lpProc,hInstance) (lpProc)
#ವ್ಯಾಖ್ಯಾನಿಸು FreeProcInstance(lpProc) (lpProc)

#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_FIXED 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_MOVEABLE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_NOCOMPACT 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_NODISCARD 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_ZEROINIT 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_MODIFY 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_DISCARDABLE 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_NOT_BANKED 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_SHARE 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_DDESHARE 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_NOTIFY 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_ಅಧೋ GMEM_NOT_BANKED
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_VALID_FLAGS 0x7F72
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_INVALID_HANDLE 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#ವ್ಯಾಖ್ಯಾನಿಸು GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#ವ್ಯಾಖ್ಯಾನಿಸು GlobalLRUNewest(h) ((HANDLE)(h))
#ವ್ಯಾಖ್ಯಾನಿಸು GlobalLRUOldest(h) ((HANDLE)(h))
#ವ್ಯಾಖ್ಯಾನಿಸು GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_DISCARDED 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು GMEM_LOCKCOUNT 0xff

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _MEMORYSTATUS {
    DWORD dw_ಉದ್ದಳತೆ;
    DWORD dw_ಸ್ಮರಣೆ_ತುಂಬು;
    ಗಾತ್ರ_T dw_ಒಟ್ಟು_Phys;
    ಗಾತ್ರ_T dwAvailPhys;
    ಗಾತ್ರ_T dw_ಒಟ್ಟು_ಪುಟ_File;
    ಗಾತ್ರ_T dw_Avail_ಪುಟ_File;
    ಗಾತ್ರ_T dw_ಒಟ್ಟು_Virtual;
    ಗಾತ್ರ_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_FIXED 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_MOVEABLE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_NOCOMPACT 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_NODISCARD 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_ZEROINIT 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_MODIFY 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_DISCARDABLE 0xf00
#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_VALID_FLAGS 0xf72
#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_INVALID_HANDLE 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#ವ್ಯಾಖ್ಯಾನಿಸು LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#ವ್ಯಾಖ್ಯಾನಿಸು NONZEROLHND (LMEM_MOVEABLE)
#ವ್ಯಾಖ್ಯಾನಿಸು NONZEROLPTR (LMEM_FIXED)

#ವ್ಯಾಖ್ಯಾನಿಸು LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_DISCARDED 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು LMEM_LOCKCOUNT 0xff

#ವ್ಯಾಖ್ಯಾನಿಸು DEBUG_PROCESS 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು DEBUG_ONLY_THIS_PROCESS 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_SUSPENDED 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು DETACHED_PROCESS 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_NEW_CONSOLE 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಾಮಾನ್ಯ_ಆದ್ಯತೆ_CLASS 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು IDLE_ಆದ್ಯತೆ_CLASS 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು ಮೇಲಿನ_ಆದ್ಯತೆ_CLASS 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು REALTIME_ಆದ್ಯತೆ_CLASS 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_NEW_PROCESS_ಗುಂಪು 0x200
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_UNICODE_ENVIRONMENT 0x400
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_SEPARATE_WOW_VDM 0x800
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_SHARED_WOW_VDM 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_FORCEDOS 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೆಳಗೆ_ಸಾಮಾನ್ಯ_ಆದ್ಯತೆ_CLASS 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು ABOVE_ಸಾಮಾನ್ಯ_ಆದ್ಯತೆ_CLASS 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು ರಾಶಿ_ಗಾತ್ರ_PARAM_IS_A_RESERVATION 0x10000

#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_BREAKAWAY_FROM_ಕೆಲಸ 0x1000000
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_PRESERVE_ಸಂಕೇತ_AUTHZ_LEVEL 0x2000000

#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_DEFAULT_ERROR_ಬಹುಲಕ 0x4000000
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_NO_ಕಿಟಕಿ 0x8000000

#ವ್ಯಾಖ್ಯಾನಿಸು PROFILE_USER 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು PROFILE_KERNEL 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು PROFILE_SERVER 0x40000000

#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಆದ್ಯತೆ_ಅತಿಕಡಿಮೆ THREAD_ತಳ_ಆದ್ಯತೆ_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಆದ್ಯತೆ_ಕೆಳಗೆ_ಸಾಮಾನ್ಯ (THREAD_ಆದ್ಯತೆ_ಅತಿಕಡಿಮೆ+1)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಆದ್ಯತೆ_ಸಾಮಾನ್ಯ 0
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಆದ್ಯತೆ_HIGHEST THREAD_ತಳ_ಆದ್ಯತೆ_MAX
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಆದ್ಯತೆ_ABOVE_ಸಾಮಾನ್ಯ (THREAD_ಆದ್ಯತೆ_HIGHEST-1)
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಆದ್ಯತೆ_ERROR_RETURN (MAXLONG)

#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಆದ್ಯತೆ_ಸಮಯ_CRITICAL THREAD_ತಳ_ಆದ್ಯತೆ_LOWRT
#ವ್ಯಾಖ್ಯಾನಿಸು THREAD_ಆದ್ಯತೆ_IDLE THREAD_ತಳ_ಆದ್ಯತೆ_IDLE

#ವ್ಯಾಖ್ಯಾನಿಸು EXCEPTION_DEBUG_EVENT 1
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_THREAD_DEBUG_EVENT 2
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_PROCESS_DEBUG_EVENT 3
#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_THREAD_DEBUG_EVENT 4
#ವ್ಯಾಖ್ಯಾನಿಸು EXIT_PROCESS_DEBUG_EVENT 5
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_DLL_DEBUG_EVENT 6
#ವ್ಯಾಖ್ಯಾನಿಸು UNLOAD_DLL_DEBUG_EVENT 7
#ವ್ಯಾಖ್ಯಾನಿಸು OUTPUT_DEBUG_STRING_EVENT 8
#ವ್ಯಾಖ್ಯಾನಿಸು RIP_EVENT 9

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _EXCEPTION_DEBUG_INFO {
    EXCEPTION_ದಾಖಲೆ_2 Exception_ದಾಖಲೆ;
    DWORD dw_ಮೊದಲ_Chance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lp_Thread_Local_ತಳ;
    LPTHREAD_ಆರಂಭ_ROUTINE lp_ಆರಂಭ_ವಿಳಾಸ;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lp_ತಳ_ದ_Image;
    DWORD dw_Debug_Info_File_ಸ್ಥಾನಾಂತರ;
    DWORD n_Debug_Info_ಗಾತ್ರ;
    LPVOID lp_Thread_Local_ತಳ;
    LPTHREAD_ಆರಂಭ_ROUTINE lp_ಆರಂಭ_ವಿಳಾಸ;
    LPVOID lpImageName;
    ಶಬ್ದ_3 fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _EXIT_THREAD_DEBUG_INFO {
    DWORD dw_Exit_ಸಂಕೇತ;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _EXIT_PROCESS_DEBUG_INFO {
    DWORD dw_Exit_ಸಂಕೇತ;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ತುಂಬು_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lp_ತಳ_ದ_Dll;
    DWORD dw_Debug_Info_File_ಸ್ಥಾನಾಂತರ;
    DWORD n_Debug_Info_ಗಾತ್ರ;
    LPVOID lpImageName;
    ಶಬ್ದ_3 fUnicode;
  } ತುಂಬು_DLL_DEBUG_INFO_2,*LPLOAD_DLL_DEBUG_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lp_ತಳ_ದ_Dll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lp_Debug_String_ದತ್ತಾಂಶ;
    ಶಬ್ದ_3 fUnicode;
    ಶಬ್ದ_3 n_Debug_String_ಉದ್ದಳತೆ;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _DEBUG_EVENT {
    DWORD dw_Debug_Event_ಸಂಕೇತ;
    DWORD dwProcessId;
    DWORD dwThreadId;
    ಒಕ್ಕೂಟ {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      ತುಂಬು_DLL_DEBUG_INFO_2 ತುಂಬು_Dll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PCONTEXT LPCONTEXT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PEXCEPTION_ದಾಖಲೆ LPEXCEPTION_ದಾಖಲೆ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PEXCEPTION_ಸೂಚಕಗಳು LPEXCEPTION_ಸೂಚಕಗಳು;

#ವ್ಯಾಖ್ಯಾನಿಸು DRIVE_UNKNOWN 0
#ವ್ಯಾಖ್ಯಾನಿಸು DRIVE_NO_ಬೇರು_DIR 1
#ವ್ಯಾಖ್ಯಾನಿಸು DRIVE_REMOVABLE 2
#ವ್ಯಾಖ್ಯಾನಿಸು DRIVE_FIXED 3
#ವ್ಯಾಖ್ಯಾನಿಸು DRIVE_REMOTE 4
#ವ್ಯಾಖ್ಯಾನಿಸು DRIVE_CDROM 5
#ವ್ಯಾಖ್ಯಾನಿಸು DRIVE_RAMDISK 6

#ವ್ಯಾಖ್ಯಾನಿಸು GetFreeSpace(w) (0x100000L)
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_TYPE_UNKNOWN 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_TYPE_DISK 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_TYPE_CHAR 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_TYPE_PIPE 0x3
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_TYPE_REMOTE 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು STD_ಒಳಹರಿವು_HANDLE ((DWORD)-10)
#ವ್ಯಾಖ್ಯಾನಿಸು STD_OUTPUT_HANDLE ((DWORD)-11)
#ವ್ಯಾಖ್ಯಾನಿಸು STD_ERROR_HANDLE ((DWORD)-12)

#ವ್ಯಾಖ್ಯಾನಿಸು NOPARITY 0
#ವ್ಯಾಖ್ಯಾನಿಸು ODDPARITY 1
#ವ್ಯಾಖ್ಯಾನಿಸು EVENPARITY 2
#ವ್ಯಾಖ್ಯಾನಿಸು MARKPARITY 3
#ವ್ಯಾಖ್ಯಾನಿಸು SPACEPARITY 4

#ವ್ಯಾಖ್ಯಾನಿಸು ONESTOPBIT 0
#ವ್ಯಾಖ್ಯಾನಿಸು ONE5STOPBITS 1
#ವ್ಯಾಖ್ಯಾನಿಸು TWOSTOPBITS 2

#ವ್ಯಾಖ್ಯಾನಿಸು IGNORE 0
#ವ್ಯಾಖ್ಯಾನಿಸು INFINITE 0xffffffff

#ವ್ಯಾಖ್ಯಾನಿಸು CBR_110 110
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_300 300
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_600 600
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_1200 1200
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_2400 2400
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_4800 4800
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_9600 9600
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_14400 14400
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_19200 19200
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_38400 38400
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_56000 56000
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_57600 57600
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_115200 115200
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_128000 128000
#ವ್ಯಾಖ್ಯಾನಿಸು CBR_256000 256000

#ವ್ಯಾಖ್ಯಾನಿಸು CE_RXOVER 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು CE_OVERRUN 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು CE_RXPARITY 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು CE_ಚೌಕಟ್ಟು 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು CE_BREAK 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು CE_TXFULL 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು CE_PTO 0x200
#ವ್ಯಾಖ್ಯಾನಿಸು CE_IOE 0x400
#ವ್ಯಾಖ್ಯಾನಿಸು CE_DNS 0x800
#ವ್ಯಾಖ್ಯಾನಿಸು CE_OOP 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು CE_ಬಹುಲಕ 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು IE_BADID (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು IE_OPEN (-2)
#ವ್ಯಾಖ್ಯಾನಿಸು IE_NOPEN (-3)
#ವ್ಯಾಖ್ಯಾನಿಸು IE_ಸ್ಮರಣೆ (-4)
#ವ್ಯಾಖ್ಯಾನಿಸು IE_DEFAULT (-5)
#ವ್ಯಾಖ್ಯಾನಿಸು IE_HARDWARE (-10)
#ವ್ಯಾಖ್ಯಾನಿಸು IE_BYTESIZE (-11)
#ವ್ಯಾಖ್ಯಾನಿಸು IE_BAUDRATE (-12)

#ವ್ಯಾಖ್ಯಾನಿಸು EV_RXCHAR 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು EV_RXFLAG 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು EV_TXEMPTY 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು EV_CTS 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು EV_DSR 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು EV_RLSD 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು EV_BREAK 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು EV_ERR 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು EV_RING 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು EV_PERR 0x200
#ವ್ಯಾಖ್ಯಾನಿಸು EV_RX80_ತುಂಬಿದ 0x400
#ವ್ಯಾಖ್ಯಾನಿಸು EV_EVENT1 0x800
#ವ್ಯಾಖ್ಯಾನಿಸು EV_EVENT2 0x1000

#ವ್ಯಾಖ್ಯಾನಿಸು SETXOFF 1
#ವ್ಯಾಖ್ಯಾನಿಸು SETXON 2
#ವ್ಯಾಖ್ಯಾನಿಸು SETRTS 3
#ವ್ಯಾಖ್ಯಾನಿಸು CLRRTS 4
#ವ್ಯಾಖ್ಯಾನಿಸು SETDTR 5
#ವ್ಯಾಖ್ಯಾನಿಸು CLRDTR 6
#ವ್ಯಾಖ್ಯಾನಿಸು RESETDEV 7
#ವ್ಯಾಖ್ಯಾನಿಸು SETBREAK 8
#ವ್ಯಾಖ್ಯಾನಿಸು CLRBREAK 9

#ವ್ಯಾಖ್ಯಾನಿಸು PURGE_TXABORT 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು PURGE_RXABORT 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು PURGE_TXCLEAR 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು PURGE_RXCLEAR 0x8

#ವ್ಯಾಖ್ಯಾನಿಸು LPTx 0x80

#ವ್ಯಾಖ್ಯಾನಿಸು MS_CTS_ON ((DWORD)0x10)
#ವ್ಯಾಖ್ಯಾನಿಸು MS_DSR_ON ((DWORD)0x20)
#ವ್ಯಾಖ್ಯಾನಿಸು MS_RING_ON ((DWORD)0x40)
#ವ್ಯಾಖ್ಯಾನಿಸು MS_RLSD_ON ((DWORD)0x80)

#ವ್ಯಾಖ್ಯಾನಿಸು S_QUEUEEMPTY 0
#ವ್ಯಾಖ್ಯಾನಿಸು S_ಮಿತಿ 1
#ವ್ಯಾಖ್ಯಾನಿಸು S_ALLTHRESHOLD 2

#ವ್ಯಾಖ್ಯಾನಿಸು S_ಸಾಮಾನ್ಯ 0
#ವ್ಯಾಖ್ಯಾನಿಸು S_LEGATO 1
#ವ್ಯಾಖ್ಯಾನಿಸು S_STACCATO 2

#ವ್ಯಾಖ್ಯಾನಿಸು S_PERIOD512 0
#ವ್ಯಾಖ್ಯಾನಿಸು S_PERIOD1024 1
#ವ್ಯಾಖ್ಯಾನಿಸು S_PERIOD2048 2
#ವ್ಯಾಖ್ಯಾನಿಸು S_PERIODVOICE 3
#ವ್ಯಾಖ್ಯಾನಿಸು S_WHITE512 4
#ವ್ಯಾಖ್ಯಾನಿಸು S_WHITE1024 5
#ವ್ಯಾಖ್ಯಾನಿಸು S_WHITE2048 6
#ವ್ಯಾಖ್ಯಾನಿಸು S_WHITEVOICE 7

#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDVNA (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SEROFM (-2)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERMACT (-3)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERQFUL (-4)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERBDNT (-5)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDLN (-6)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDCC (-7)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDTP (-8)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDVL (-9)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDMD (-10)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDSH (-11)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDPT (-12)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDFQ (-13)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDDR (-14)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDSR (-15)
#ವ್ಯಾಖ್ಯಾನಿಸು S_SERDST (-16)

#ವ್ಯಾಖ್ಯಾನಿಸು NMPWAIT_WAIT_FOREVER 0xffffffff
#ವ್ಯಾಖ್ಯಾನಿಸು NMPWAIT_NOWAIT 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು NMPWAIT_USE_DEFAULT_WAIT 0x0

#ವ್ಯಾಖ್ಯಾನಿಸು FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_ಹೆಸರುಗಳು
#ವ್ಯಾಖ್ಯಾನಿಸು FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_ಹುಡುಕು
#ವ್ಯಾಖ್ಯಾನಿಸು FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#ವ್ಯಾಖ್ಯಾನಿಸು FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#ವ್ಯಾಖ್ಯಾನಿಸು FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#ವ್ಯಾಖ್ಯಾನಿಸು FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#ವ್ಯಾಖ್ಯಾನಿಸು FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_MAP_COPY SECTION_QUERY
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_MAP_WRITE SECTION_MAP_WRITE
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_MAP_READ SECTION_MAP_READ
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#ವ್ಯಾಖ್ಯಾನಿಸು ದ_READ 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_WRITE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_READWRITE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_SHARE_COMPAT 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_SHARE_EXCLUSIVE 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_SHARE_DENY_WRITE 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_SHARE_DENY_READ 0x30
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_SHARE_DENY_NONE 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_PARSE 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_DELETE 0x200
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_VERIFY 0x400
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_CANCEL 0x800
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_CREATE 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_PROMPT 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_EXIST 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು ದ_REOPEN 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು OFS_MAXPATHNAME 128
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OFSTRUCT {
    BYTE c_ಬೈಟುಗಳು;
    BYTE fFixedDisk;
    ಶಬ್ದ_3 n_Err_ಸಂಕೇತ;
    ಶಬ್ದ_3 Reserved1;
    ಶಬ್ದ_3 Reserved2;
    CHAR sz_ಮಾರ್ಗ_Name[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINBASEINTERLOCK

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _NTOS_

#ಆದರೆ defined(__ia64__) && !defined(RC_INVOKED)

#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrement _InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementAcquire _InterlockedIncrement_acq
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementRelease _InterlockedIncrement_rel
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrement _InterlockedDecrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrementAcquire _InterlockedDecrement_acq
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrementRelease _InterlockedDecrement_rel
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchange _InterlockedExchange
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Exchange_ಕೂಡಿಸು Interlocked_Exchange_ಕೂಡಿಸು_2
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchange _InterlockedCompareExchange
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Exchange_ಸೂಚಕ Interlocked_Exchange_ಸೂಚಕ_2
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ Interlocked_Compare_Exchange_ಸೂಚಕ_2
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Release Interlocked_Compare_Exchange_ಸೂಚಕ_rel
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Acquire Interlocked_Compare_Exchange_ಸೂಚಕ_acq

#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrement64 _InterlockedIncrement64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrement64 _InterlockedDecrement64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchange64 _InterlockedExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchange64 _InterlockedCompareExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG ಅಸ್ಥಿರ *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG ಅಸ್ಥಿರ *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG ಅಸ್ಥಿರ *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG ಅಸ್ಥಿರ *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG ಅಸ್ಥಿರ *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG ಅಸ್ಥಿರ *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONGLONG ಮೌಲ್ಯ_3);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONGLONG ಮೌಲ್ಯ_3);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG ಅಸ್ಥಿರ *Addend,LONGLONG ಮೌಲ್ಯ_3);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG ಅಸ್ಥಿರ *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG ಅಸ್ಥಿರ *lpAddend);
  LONG __cdecl InterlockedExchange(LONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONG ಮೌಲ್ಯ_3);
  LONG __cdecl Interlocked_Exchange_ಕೂಡಿಸು(LONG ಅಸ್ಥಿರ *Addend,LONG ಮೌಲ್ಯ_3);
  LONG __cdecl InterlockedCompareExchange(LONG ಅಸ್ಥಿರ *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG ಅಸ್ಥಿರ *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG ಅಸ್ಥಿರ *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl Interlocked_Exchange_ಸೂಚಕ(PVOID ಅಸ್ಥಿರ *ಗುರಿ_2,PVOID ಮೌಲ್ಯ_3);
  PVOID __cdecl Interlocked_Compare_Exchange_ಸೂಚಕ(PVOID ಅಸ್ಥಿರ *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_ಸೂಚಕ_Acquire(PVOID ಅಸ್ಥಿರ *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_ಸೂಚಕ_Release(PVOID ಅಸ್ಥಿರ *Destination,PVOID Exchange,PVOID Comperand);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ InterlockedAnd
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONG ಗಣ_2) {
    LONG i;
    LONG j;
    j = *ಗುರಿ_2;
    ಮಾಡು {
      i = j;
      j = InterlockedCompareExchange(ಗುರಿ_2,i & ಗಣ_2,i);
    } ಆಗ(i!=j);
    ಹಿಂತಿರುಗಿ j;
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ InterlockedOr
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONG ಗಣ_2) {
    LONG i;
    LONG j;
    j = *ಗುರಿ_2;
    ಮಾಡು {
      i = j;
      j = InterlockedCompareExchange(ಗುರಿ_2,i | ಗಣ_2,i);
    } ಆಗ(i!=j);
    ಹಿಂತಿರುಗಿ j;
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ InterlockedXor
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONG ಗಣ_2) {
    LONG i;
    LONG j;
    j = *ಗುರಿ_2;
    ಮಾಡು {
      i = j;
      j = InterlockedCompareExchange(ಗುರಿ_2,i ^ ಗಣ_2,i);
    } ಆಗ(i!=j);
    ಹಿಂತಿರುಗಿ j;
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ InterlockedAnd64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG ಮೌಲ್ಯ_3) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *Destination;
    } ಆಗ(InterlockedCompareExchange64(Destination,Old & ಮೌಲ್ಯ_3,Old)!=Old);
    ಹಿಂತಿರುಗಿ Old;
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ InterlockedOr64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG ಮೌಲ್ಯ_3) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *Destination;
    } ಆಗ(InterlockedCompareExchange64(Destination,Old | ಮೌಲ್ಯ_3,Old)!=Old);
    ಹಿಂತಿರುಗಿ Old;
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ InterlockedXor64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG ಮೌಲ್ಯ_3) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *Destination;
    } ಆಗ(InterlockedCompareExchange64(Destination,Old ^ ಮೌಲ್ಯ_3,Old)!=Old);
    ಹಿಂತಿರುಗಿ Old;
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ Interlocked_ಬಿಟ್_Test_And_ಗಣ
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_ಬಿಟ್_Test_And_ಗಣ Interlocked_ಬಿಟ್_Test_And_ಗಣ_Inline

  __CRT_INLINE BOOLEAN Interlocked_ಬಿಟ್_Test_And_ಗಣ_Inline(LONG *ತಳ_2,LONG ಬಿಟ್_2) {
    LONG t_ಬಿಟ್;
    t_ಬಿಟ್ = 1<<(ಬಿಟ್_2 & (ಗಾತ್ರ (*ತಳ_2)*8-1));
    ಹಿಂತಿರುಗಿ (BOOLEAN)((InterlockedOr(&ತಳ_2[ಬಿಟ್_2/(ಗಾತ್ರ(*ತಳ_2)*8)],t_ಬಿಟ್)&t_ಬಿಟ್)!=0);
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ Interlocked_ಬಿಟ್_Test_And_Reset
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_ಬಿಟ್_Test_And_Reset Interlocked_ಬಿಟ್_Test_And_Reset_Inline

  __CRT_INLINE BOOLEAN Interlocked_ಬಿಟ್_Test_And_Reset_Inline(LONG *ತಳ_2,LONG ಬಿಟ್_2) {
    LONG t_ಬಿಟ್;
    t_ಬಿಟ್ = 1<<(ಬಿಟ್_2 & (ಗಾತ್ರ (*ತಳ_2)*8-1));
    ಹಿಂತಿರುಗಿ (BOOLEAN)((InterlockedAnd(&ತಳ_2[ಬಿಟ್_2/(ಗಾತ್ರ(*ತಳ_2)*8)],~t_ಬಿಟ್)&t_ಬಿಟ್)!=0);
  }
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ Interlocked_ಬಿಟ್_Test_And_Complement
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_ಬಿಟ್_Test_And_Complement Interlocked_ಬಿಟ್_Test_And_Complement_Inline

  __CRT_INLINE BOOLEAN Interlocked_ಬಿಟ್_Test_And_Complement_Inline(LONG *ತಳ_2,LONG ಬಿಟ್_2) {
    LONG t_ಬಿಟ್;
    t_ಬಿಟ್ = 1<<(ಬಿಟ್_2 & (ಗಾತ್ರ (*ತಳ_2)*8-1));
    ಹಿಂತಿರುಗಿ (BOOLEAN)((InterlockedXor(&ತಳ_2[ಬಿಟ್_2/(ಗಾತ್ರ(*ತಳ_2)*8)],t_ಬಿಟ್)&t_ಬಿಟ್)!=0);
  }
#ಆದರೆ_ಅಂತ್ಯ
#ಅಥವಾಆದರೆ defined(__x86_64) && !defined(RC_INVOKED)

#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrement _InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementAcquire InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementRelease InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrement _InterlockedDecrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrementAcquire InterlockedDecrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrementRelease InterlockedDecrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchange _InterlockedExchange
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Exchange_ಕೂಡಿಸು Interlocked_Exchange_ಕೂಡಿಸು_2
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchange _InterlockedCompareExchange
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeAcquire InterlockedCompareExchange
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeRelease InterlockedCompareExchange
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Exchange_ಸೂಚಕ Interlocked_Exchange_ಸೂಚಕ_2
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ Interlocked_Compare_Exchange_ಸೂಚಕ_2
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Acquire Interlocked_Compare_Exchange_ಸೂಚಕ_2
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Release Interlocked_Compare_Exchange_ಸೂಚಕ_2
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedAnd64 _InterlockedAnd64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedOr64 _InterlockedOr64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedXor64 _InterlockedXor64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrement64 _InterlockedIncrement64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrement64 _InterlockedDecrement64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchange64 _InterlockedExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchange64 _InterlockedCompareExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG ಅಸ್ಥಿರ *Addend);
  LONG InterlockedDecrement(LONG ಅಸ್ಥಿರ *Addend);
  LONG InterlockedExchange(LONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONG ಮೌಲ್ಯ_3);
  LONG Interlocked_Exchange_ಕೂಡಿಸು(LONG ಅಸ್ಥಿರ *Addend,LONG ಮೌಲ್ಯ_3);
  LONG InterlockedCompareExchange(LONG ಅಸ್ಥಿರ *Destination,LONG ExChange,LONG Comperand);
  PVOID Interlocked_Compare_Exchange_ಸೂಚಕ(PVOID ಅಸ್ಥಿರ *Destination,PVOID Exchange,PVOID Comperand);
  PVOID Interlocked_Exchange_ಸೂಚಕ(PVOID ಅಸ್ಥಿರ *ಗುರಿ_2,PVOID ಮೌಲ್ಯ_3);
  LONG64 InterlockedAnd64(LONG64 ಅಸ್ಥಿರ *Destination,LONG64 ಮೌಲ್ಯ_3);
  LONG64 InterlockedOr64(LONG64 ಅಸ್ಥಿರ *Destination,LONG64 ಮೌಲ್ಯ_3);
  LONG64 InterlockedXor64(LONG64 ಅಸ್ಥಿರ *Destination,LONG64 ಮೌಲ್ಯ_3);
  LONG64 InterlockedIncrement64(LONG64 ಅಸ್ಥಿರ *Addend);
  LONG64 InterlockedDecrement64(LONG64 ಅಸ್ಥಿರ *Addend);
  LONG64 InterlockedExchange64(LONG64 ಅಸ್ಥಿರ *ಗುರಿ_2,LONG64 ಮೌಲ್ಯ_3);
  LONG64 InterlockedExchangeAdd64(LONG64 ಅಸ್ಥಿರ *Addend,LONG64 ಮೌಲ್ಯ_3);
  LONG64 InterlockedCompareExchange64(LONG64 ಅಸ್ಥಿರ *Destination,LONG64 ExChange,LONG64 Comperand);
#ಇಲ್ಲದಿದ್ದರೆ
  LONG WINAPI InterlockedIncrement(LONG ಅಸ್ಥಿರ *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG ಅಸ್ಥಿರ *lpAddend);
  LONG WINAPI InterlockedExchange(LONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONG ಮೌಲ್ಯ_3);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ Interlocked_Exchange_ಸೂಚಕ
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Exchange_ಸೂಚಕ(ಗುರಿ_2,ಮೌಲ್ಯ_3) (PVOID)InterlockedExchange((PLONG)(ಗುರಿ_2),(LONG)(ಮೌಲ್ಯ_3))
#ಆದರೆ_ಅಂತ್ಯ

  LONG WINAPI Interlocked_Exchange_ಕೂಡಿಸು(LONG ಅಸ್ಥಿರ *Addend,LONG ಮೌಲ್ಯ_3);
  LONG WINAPI InterlockedCompareExchange(LONG ಅಸ್ಥಿರ *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG ಮೌಲ್ಯ_3) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *Destination;
    } ಆಗ(InterlockedCompareExchange64(Destination,Old & ಮೌಲ್ಯ_3,Old)!=Old);
    ಹಿಂತಿರುಗಿ Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG ಮೌಲ್ಯ_3) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *Destination;
    } ಆಗ(InterlockedCompareExchange64(Destination,Old | ಮೌಲ್ಯ_3,Old)!=Old);
    ಹಿಂತಿರುಗಿ Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG ಅಸ್ಥಿರ *Destination,LONGLONG ಮೌಲ್ಯ_3) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *Destination;
    } ಆಗ(InterlockedCompareExchange64(Destination,Old ^ ಮೌಲ್ಯ_3,Old)!=Old);

    ಹಿಂತಿರುಗಿ Old;
  }

  __CRT_INLINE LONGLONG InterlockedIncrement64(LONGLONG ಅಸ್ಥಿರ *Addend) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *Addend;
    } ಆಗ(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    ಹಿಂತಿರುಗಿ Old + 1;
  }

  __CRT_INLINE LONGLONG InterlockedDecrement64(LONGLONG ಅಸ್ಥಿರ *Addend) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *Addend;
    } ಆಗ(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    ಹಿಂತಿರುಗಿ Old - 1;
  }

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG ಅಸ್ಥಿರ *ಗುರಿ_2,LONGLONG ಮೌಲ್ಯ_3) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *ಗುರಿ_2;
    } ಆಗ(InterlockedCompareExchange64(ಗುರಿ_2,ಮೌಲ್ಯ_3,Old)!=Old);
    ಹಿಂತಿರುಗಿ Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG ಅಸ್ಥಿರ *Addend,LONGLONG ಮೌಲ್ಯ_3) {
    LONGLONG Old;
    ಮಾಡು {
      Old = *Addend;
    } ಆಗ(InterlockedCompareExchange64(Addend,Old + ಮೌಲ್ಯ_3,Old)!=Old);
    ಹಿಂತಿರುಗಿ Old;
  }

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ Interlocked_Compare_Exchange_ಸೂಚಕ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID ಅಸ್ಥಿರ *Destination,PVOID ExChange,PVOID Comperand) {
    ಹಿಂತಿರುಗಿ((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG ಅಸ್ಥಿರ *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ __InlineInterlockedCompareExchangePointer
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG ಅಸ್ಥಿರ *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementAcquire InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementRelease InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrementAcquire InterlockedDecrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedDecrementRelease InterlockedDecrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementAcquire InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedIncrementRelease InterlockedIncrement
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeAcquire InterlockedCompareExchange
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeRelease InterlockedCompareExchange
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#ವ್ಯಾಖ್ಯಾನಿಸು InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ Interlocked_Compare_Exchange_ಸೂಚಕ_Acquire
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Acquire Interlocked_Compare_Exchange_ಸೂಚಕ
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ Interlocked_Compare_Exchange_ಸೂಚಕ_Release
#ವ್ಯಾಖ್ಯಾನಿಸು Interlocked_Compare_Exchange_ಸೂಚಕ_Release Interlocked_Compare_Exchange_ಸೂಚಕ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ಆದರೆ defined(SLIST_ಶೀರ್ಷಿಕೆ) && !defined(_NTOSP_)
  WINBASEAPI VOID WINAPI Initialize_SList_ತಲೆ(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ);
  WINBASEAPI PSLIST_ನಮೂದು WINAPI Interlocked_ತೆಗೆ_ನಮೂದು_SList(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ);
  WINBASEAPI PSLIST_ನಮೂದು WINAPI Interlocked_ತಳ್ಳು_ನಮೂದು_SList(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ,PSLIST_ನಮೂದು List_ನಮೂದು);
  WINBASEAPI PSLIST_ನಮೂದು WINAPI InterlockedFlushSList(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ);
  WINBASEAPI USHORT WINAPI Query_ಆಳ_SList(PSLIST_ಶೀರ್ಷಿಕೆ List_ತಲೆ);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL h_Res_ದತ್ತಾಂಶ);
  WINBASEAPI LPVOID WINAPI ಬೀಗ_Resource(HGLOBAL h_Res_ದತ್ತಾಂಶ);

#ವ್ಯಾಖ್ಯಾನಿಸು UnlockResource(h_Res_ದತ್ತಾಂಶ) ((h_Res_ದತ್ತಾಂಶ),0)
#ವ್ಯಾಖ್ಯಾನಿಸು MAXINTATOM 0xC000
#ವ್ಯಾಖ್ಯಾನಿಸು MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((ಶಬ್ದ_3)(i)))
#ವ್ಯಾಖ್ಯಾನಿಸು INVALID_ATOM ((ATOM)0)

  ಪೂರ್ಣಾಂಕ WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lp_Cmd_ಸಾಲು,ಪೂರ್ಣಾಂಕ nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dw_Exit_ಸಂಕೇತ);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI Get_Proc_ವಿಳಾಸ(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI Get_ಆವೃತ್ತಿ(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,ಗಾತ್ರ_T dw_ಬೈಟುಗಳು);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,ಗಾತ್ರ_T dw_ಬೈಟುಗಳು,UINT uFlags);
  WINBASEAPI ಗಾತ್ರ_T WINAPI Global_ಗಾತ್ರ(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI Global_ಬೀಗ(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI ಗಾತ್ರ_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI Global_ಸ್ಮರಣೆ_ಸ್ಥಿತಿ(LPMEMORYSTATUS lp_ಬಫರ್);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _MEMORYSTATUSEX {
    DWORD dw_ಉದ್ದಳತೆ;
    DWORD dw_ಸ್ಮರಣೆ_ತುಂಬು;
    DWORDLONG ull_ಒಟ್ಟು_Phys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ull_ಒಟ್ಟು_ಪುಟ_File;
    DWORDLONG ull_Avail_ಪುಟ_File;
    DWORDLONG ull_ಒಟ್ಟು_Virtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI Global_ಸ್ಮರಣೆ_ಸ್ಥಿತಿ_Ex(LPMEMORYSTATUSEX lp_ಬಫರ್);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,ಗಾತ್ರ_T u_ಬೈಟುಗಳು);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,ಗಾತ್ರ_T u_ಬೈಟುಗಳು,UINT uFlags);
  WINBASEAPI LPVOID WINAPI Local_ಬೀಗ(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI ಗಾತ್ರ_T WINAPI Local_ಗಾತ್ರ(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI ಗಾತ್ರ_T WINAPI LocalShrink(HLOCAL hMem,UINT cb_New_ಗಾತ್ರ);
  WINBASEAPI ಗಾತ್ರ_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lp_ತಳ_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಗಾತ್ರ);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lp_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಗಾತ್ರ,DWORD fl_ಹಂಚಿಕೆ_Type,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lp_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಗಾತ್ರ,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lp_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಗಾತ್ರ,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI ಗಾತ್ರ_T WINAPI VirtualQuery(LPCVOID lp_ವಿಳಾಸ,PMEMORY_BASIC_INFORMATION lp_ಬಫರ್,ಗಾತ್ರ_T dw_ಉದ್ದಳತೆ);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lp_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಗಾತ್ರ,DWORD fl_ಹಂಚಿಕೆ_Type,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lp_ತಳ_ವಿಳಾಸ,ಗಾತ್ರ_T dw_Region_ಗಾತ್ರ,PVOID *lp_ವಿಳಾಸಗಳು,ULONG_PTR *lpdw_ಎಣಿಕೆ,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lp_ತಳ_ವಿಳಾಸ,ಗಾತ್ರ_T dw_Region_ಗಾತ್ರ);
  WINBASEAPI ಗಾತ್ರ_T WINAPI Get_Large_ಪುಟ_Minimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD Firmware_ಕೋಷ್ಟಕ_Provider_Signature,PVOID p_Firmware_ಕೋಷ್ಟಕ_Enum_ಬಫರ್,DWORD ಬಫರ್_ಗಾತ್ರ);
  WINBASEAPI UINT WINAPI Get_System_Firmware_ಕೋಷ್ಟಕ(DWORD Firmware_ಕೋಷ್ಟಕ_Provider_Signature,DWORD Firmware_ಕೋಷ್ಟಕ_ID,PVOID p_Firmware_ಕೋಷ್ಟಕ_ಬಫರ್,DWORD ಬಫರ್_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lp_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಗಾತ್ರ,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lp_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಗಾತ್ರ,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI ಗಾತ್ರ_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lp_ವಿಳಾಸ,PMEMORY_BASIC_INFORMATION lp_ಬಫರ್,ಗಾತ್ರ_T dw_ಉದ್ದಳತೆ);
  WINBASEAPI HANDLE WINAPI ರಾಶಿ_Create(DWORD flOptions,ಗಾತ್ರ_T dw_Initial_ಗಾತ್ರ,ಗಾತ್ರ_T dw_ಗರಿಷ್ಠ_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ರಾಶಿ_Destroy(HANDLE h_ರಾಶಿ);
  WINBASEAPI LPVOID WINAPI ರಾಶಿ_Alloc(HANDLE h_ರಾಶಿ,DWORD dwFlags,ಗಾತ್ರ_T dw_ಬೈಟುಗಳು);
  WINBASEAPI LPVOID WINAPI ರಾಶಿ_Re_Alloc(HANDLE h_ರಾಶಿ,DWORD dwFlags,LPVOID lpMem,ಗಾತ್ರ_T dw_ಬೈಟುಗಳು);
  WINBASEAPI WINBOOL WINAPI ರಾಶಿ_Free(HANDLE h_ರಾಶಿ,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI ಗಾತ್ರ_T WINAPI ರಾಶಿ_ಗಾತ್ರ_3(HANDLE h_ರಾಶಿ,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI ರಾಶಿ_Validate(HANDLE h_ರಾಶಿ,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI ಗಾತ್ರ_T WINAPI ರಾಶಿ_Compact(HANDLE h_ರಾಶಿ,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI Get_Process_ರಾಶಿ(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD ಸಂಖ್ಯೆ_ದ_Heaps,PHANDLE ProcessHeaps);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ PROCESS_ರಾಶಿ_ನಮೂದು {
    PVOID lp_ದತ್ತಾಂಶ;
    DWORD cb_ದತ್ತಾಂಶ;
    BYTE cbOverhead;
    BYTE i_Region_ಸೂಚ್ಯಂಕ;
    ಶಬ್ದ_3 wFlags;
    ಒಕ್ಕೂಟ {
      ರಚನೆ {
	HANDLE hMem;
	DWORD dwReserved[3];
      } ಖಂಡ_2;
      ರಚನೆ {
	DWORD dw_Committed_ಗಾತ್ರ;
	DWORD dw_Un_Committed_ಗಾತ್ರ;
	LPVOID lp_ಮೊದಲ_ಖಂಡ;
	LPVOID lp_ಕೊನೆಯ_ಖಂಡ;
      } Region;
    };
  } PROCESS_ರಾಶಿ_ನಮೂದು_2,*LPPROCESS_ರಾಶಿ_ನಮೂದು,*PPROCESS_ರಾಶಿ_ನಮೂದು;

#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ರಾಶಿ_REGION 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ರಾಶಿ_UNCOMMITTED_RANGE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ರಾಶಿ_ನಮೂದು_BUSY 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ರಾಶಿ_ನಮೂದು_MOVEABLE 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು PROCESS_ರಾಶಿ_ನಮೂದು_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI ರಾಶಿ_ಬೀಗ(HANDLE h_ರಾಶಿ);
  WINBASEAPI WINBOOL WINAPI ರಾಶಿ_Unlock(HANDLE h_ರಾಶಿ);
  WINBASEAPI WINBOOL WINAPI ರಾಶಿ_Walk(HANDLE h_ರಾಶಿ,LPPROCESS_ರಾಶಿ_ನಮೂದು lp_ನಮೂದು);
  WINBASEAPI WINBOOL WINAPI ರಾಶಿ_ಗಣ_Information(HANDLE ರಾಶಿ_Handle,ರಾಶಿ_INFORMATION_CLASS ರಾಶಿ_Information_Class,PVOID ರಾಶಿ_Information,ಗಾತ್ರ_T ರಾಶಿ_Information_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI ರಾಶಿ_Query_Information(HANDLE ರಾಶಿ_Handle,ರಾಶಿ_INFORMATION_CLASS ರಾಶಿ_Information_Class,PVOID ರಾಶಿ_Information,ಗಾತ್ರ_T ರಾಶಿ_Information_ಉದ್ದಳತೆ,PSIZE_T Return_ಉದ್ದಳತೆ);

#ವ್ಯಾಖ್ಯಾನಿಸು SCS_32_ಬಿಟ್_ದ್ವಿಮಾನ 0
#ವ್ಯಾಖ್ಯಾನಿಸು SCS_DOS_ದ್ವಿಮಾನ 1
#ವ್ಯಾಖ್ಯಾನಿಸು SCS_WOW_ದ್ವಿಮಾನ 2
#ವ್ಯಾಖ್ಯಾನಿಸು SCS_PIF_ದ್ವಿಮಾನ 3
#ವ್ಯಾಖ್ಯಾನಿಸು SCS_POSIX_ದ್ವಿಮಾನ 4
#ವ್ಯಾಖ್ಯಾನಿಸು SCS_OS216_ದ್ವಿಮಾನ 5
#ವ್ಯಾಖ್ಯಾನಿಸು SCS_64_ಬಿಟ್_ದ್ವಿಮಾನ 6

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ದ್ವಿಮಾನ_Type Get_ದ್ವಿಮಾನ_Type_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Short_ಮಾರ್ಗ_Name Get_Short_ಮಾರ್ಗ_Name_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Long_ಮಾರ್ಗ_Name Get_Long_ಮಾರ್ಗ_Name_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Environment_ಅಕ್ಷರಸರಣಿಗಳು Get_Environment_ಅಕ್ಷರಸರಣಿಗಳು_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Environment_ಅಕ್ಷರಸರಣಿಗಳು ಗಣ_Environment_ಅಕ್ಷರಸರಣಿಗಳು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Free_Environment_ಅಕ್ಷರಸರಣಿಗಳು Free_Environment_ಅಕ್ಷರಸರಣಿಗಳು_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ದ್ವಿಮಾನ_Type Get_ದ್ವಿಮಾನ_Type_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Short_ಮಾರ್ಗ_Name Get_Short_ಮಾರ್ಗ_Name_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Long_ಮಾರ್ಗ_Name Get_Long_ಮಾರ್ಗ_Name_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Environment_ಅಕ್ಷರಸರಣಿಗಳು_A Get_Environment_ಅಕ್ಷರಸರಣಿಗಳು
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Environment_ಅಕ್ಷರಸರಣಿಗಳು ಗಣ_Environment_ಅಕ್ಷರಸರಣಿಗಳು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Free_Environment_ಅಕ್ಷರಸರಣಿಗಳು Free_Environment_ಅಕ್ಷರಸರಣಿಗಳು_A
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು SCS_THIS_PLATFORM_ದ್ವಿಮಾನ SCS_64_ಬಿಟ್_ದ್ವಿಮಾನ
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು SCS_THIS_PLATFORM_ದ್ವಿಮಾನ SCS_32_ಬಿಟ್_ದ್ವಿಮಾನ
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI Get_ದ್ವಿಮಾನ_Type_A(LPCSTR lpApplicationName,LPDWORD lp_ದ್ವಿಮಾನ_Type);
  WINBASEAPI WINBOOL WINAPI Get_ದ್ವಿಮಾನ_Type_W(LPCWSTR lpApplicationName,LPDWORD lp_ದ್ವಿಮಾನ_Type);
  WINBASEAPI DWORD WINAPI Get_Short_ಮಾರ್ಗ_Name_A(LPCSTR lpsz_Long_ಮಾರ್ಗ,LPSTR lpsz_Short_ಮಾರ್ಗ,DWORD cch_ಬಫರ್);
  WINBASEAPI DWORD WINAPI Get_Short_ಮಾರ್ಗ_Name_W(LPCWSTR lpsz_Long_ಮಾರ್ಗ,LPWSTR lpsz_Short_ಮಾರ್ಗ,DWORD cch_ಬಫರ್);
  WINBASEAPI DWORD WINAPI Get_Long_ಮಾರ್ಗ_Name_A(LPCSTR lpsz_Short_ಮಾರ್ಗ,LPSTR lpsz_Long_ಮಾರ್ಗ,DWORD cch_ಬಫರ್);
  WINBASEAPI DWORD WINAPI Get_Long_ಮಾರ್ಗ_Name_W(LPCWSTR lpsz_Short_ಮಾರ್ಗ,LPWSTR lpsz_Long_ಮಾರ್ಗ,DWORD cch_ಬಫರ್);
  WINBASEAPI WINBOOL WINAPI Get_Process_Affinity_ಮುಖವಾಡ(HANDLE hProcess,PDWORD_PTR lp_Process_Affinity_ಮುಖವಾಡ,PDWORD_PTR lp_System_Affinity_ಮುಖವಾಡ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Process_Affinity_ಮುಖವಾಡ(HANDLE hProcess,DWORD_PTR dw_Process_Affinity_ಮುಖವಾಡ);
  WINBASEAPI WINBOOL WINAPI Get_Process_Handle_ಎಣಿಕೆ(HANDLE hProcess,PDWORD pdw_Handle_ಎಣಿಕೆ);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lp_Creation_ಸಮಯ,LPFILETIME lp_Exit_ಸಮಯ,LPFILETIME lp_Kernel_ಸಮಯ,LPFILETIME lp_User_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_ಗಣ_ಗಾತ್ರ(HANDLE hProcess,PSIZE_T lp_Minimum_Working_ಗಣ_ಗಾತ್ರ,PSIZE_T lp_ಗರಿಷ್ಠ_Working_ಗಣ_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_ಗಣ_ಗಾತ್ರ_Ex(HANDLE hProcess,PSIZE_T lp_Minimum_Working_ಗಣ_ಗಾತ್ರ,PSIZE_T lp_ಗರಿಷ್ಠ_Working_ಗಣ_ಗಾತ್ರ,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Process_Working_ಗಣ_ಗಾತ್ರ(HANDLE hProcess,ಗಾತ್ರ_T dw_Minimum_Working_ಗಣ_ಗಾತ್ರ,ಗಾತ್ರ_T dw_ಗರಿಷ್ಠ_Working_ಗಣ_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Process_Working_ಗಣ_ಗಾತ್ರ_Ex(HANDLE hProcess,ಗಾತ್ರ_T dw_Minimum_Working_ಗಣ_ಗಾತ್ರ,ಗಾತ್ರ_T dw_ಗರಿಷ್ಠ_Working_ಗಣ_ಗಾತ್ರ,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT u_Exit_ಸಂಕೇತ);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT u_Exit_ಸಂಕೇತ);
  WINBASEAPI WINBOOL WINAPI Get_Exit_ಸಂಕೇತ_Process(HANDLE hProcess,LPDWORD lp_Exit_ಸಂಕೇತ);
  WINBASEAPI VOID WINAPI FatalExit(ಪೂರ್ಣಾಂಕ Exit_ಸಂಕೇತ);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI Get_Environment_ಅಕ್ಷರಸರಣಿಗಳು_W(VOID);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Environment_ಅಕ್ಷರಸರಣಿಗಳು_A(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Environment_ಅಕ್ಷರಸರಣಿಗಳು_W(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI Free_Environment_ಅಕ್ಷರಸರಣಿಗಳು_A(LPCH);
  WINBASEAPI WINBOOL WINAPI Free_Environment_ಅಕ್ಷರಸರಣಿಗಳು_W(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dw_Exception_ಸಂಕೇತ,DWORD dwExceptionFlags,DWORD n_ಸಂಖ್ಯೆ_ದ_Arguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2 *ExceptionInfo);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(ರಚನೆ EXCEPTION_ಸೂಚಕಗಳು_2 *ExceptionInfo);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI ಗಣ_Unhandled_Exception_Filter(LPTOP_LEVEL_EXCEPTION_FILTER lp_ತುದಿ_Level_Exception_Filter);

#ವ್ಯಾಖ್ಯಾನಿಸು FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(ಗಾತ್ರ_T dw_ರಾಶಿ_ಗಾತ್ರ,LPFIBER_ಆರಂಭ_ROUTINE lp_ಆರಂಭ_ವಿಳಾಸ,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(ಗಾತ್ರ_T dw_ರಾಶಿ_Commit_ಗಾತ್ರ,ಗಾತ್ರ_T dw_ರಾಶಿ_Reserve_ಗಾತ್ರ,DWORD dwFlags,LPFIBER_ಆರಂಭ_ROUTINE lp_ಆರಂಭ_ವಿಳಾಸ,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI Convert_Thread_ಗಮ್ಯ_Fiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI Convert_Thread_ಗಮ್ಯ_Fiber_Ex(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Convert_Fiber_ಗಮ್ಯ_Thread(VOID);
  WINBASEAPI VOID WINAPI Switch_ಗಮ್ಯ_Fiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI Switch_ಗಮ್ಯ_Thread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Thread_ಗುಣಲಕ್ಷಣಗಳು,ಗಾತ್ರ_T dw_ರಾಶಿ_ಗಾತ್ರ,LPTHREAD_ಆರಂಭ_ROUTINE lp_ಆರಂಭ_ವಿಳಾಸ,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Thread_ಗುಣಲಕ್ಷಣಗಳು,ಗಾತ್ರ_T dw_ರಾಶಿ_ಗಾತ್ರ,LPTHREAD_ಆರಂಭ_ROUTINE lp_ಆರಂಭ_ವಿಳಾಸ,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Thread_ರಾಶಿ_Guarantee (PULONG ರಾಶಿ_ಗಾತ್ರ_ಒಳ_ಬೈಟುಗಳು);
  WINBASEAPI DWORD WINAPI Get_Process_Id_ದ_Thread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI Get_Current_Processor_ಸಂಖ್ಯೆ(VOID);
  WINBASEAPI DWORD_PTR WINAPI ಗಣ_Thread_Affinity_ಮುಖವಾಡ(HANDLE hThread,DWORD_PTR dw_Thread_Affinity_ಮುಖವಾಡ);
  WINBASEAPI DWORD WINAPI ಗಣ_Thread_Ideal_Processor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Process_ಆದ್ಯತೆ_Boost(HANDLE hProcess,WINBOOL b_Disable_ಆದ್ಯತೆ_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Process_ಆದ್ಯತೆ_Boost(HANDLE hProcess,PBOOL p_Disable_ಆದ್ಯತೆ_Boost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_ಸಮಯ latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Thread_ಆದ್ಯತೆ(HANDLE hThread,ಪೂರ್ಣಾಂಕ n_ಆದ್ಯತೆ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Thread_ಆದ್ಯತೆ_Boost(HANDLE hThread,WINBOOL b_Disable_ಆದ್ಯತೆ_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Thread_ಆದ್ಯತೆ_Boost(HANDLE hThread,PBOOL p_Disable_ಆದ್ಯತೆ_Boost);
  WINBASEAPI ಪೂರ್ಣಾಂಕ WINAPI Get_Thread_ಆದ್ಯತೆ(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lp_Creation_ಸಮಯ,LPFILETIME lp_Exit_ಸಮಯ,LPFILETIME lp_Kernel_ಸಮಯ,LPFILETIME lp_User_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dw_Exit_ಸಂಕೇತ);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dw_Exit_ಸಂಕೇತ);
  WINBASEAPI WINBOOL WINAPI Get_Exit_ಸಂಕೇತ_Thread(HANDLE hThread,LPDWORD lp_Exit_ಸಂಕೇತ);
  WINBASEAPI WINBOOL WINAPI Get_Thread_Selector_ನಮೂದು(HANDLE hThread,DWORD dwSelector,LPLDT_ನಮೂದು lp_Selector_ನಮೂದು);
  WINBASEAPI EXECUTION_STATE WINAPI ಗಣ_Thread_Execution_State(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI Get_ಕೊನೆಯ_Error(VOID);
  WINBASEAPI VOID WINAPI ಗಣ_ಕೊನೆಯ_Error(DWORD dw_Err_ಸಂಕೇತ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ WINBASE_DECLARE_RESTORE_ಕೊನೆಯ_ERROR
  WINBASEAPI VOID WINAPI Restore_ಕೊನೆಯ_Error(DWORD dw_Err_ಸಂಕೇತ);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (WINAPI *PRESTORE_ಕೊನೆಯ_ERROR)(DWORD);

#ವ್ಯಾಖ್ಯಾನಿಸು RESTORE_ಕೊನೆಯ_ERROR_NAME_A "RestoreLastError"
#ವ್ಯಾಖ್ಯಾನಿಸು RESTORE_ಕೊನೆಯ_ERROR_NAME_W L"RestoreLastError"
#ವ್ಯಾಖ್ಯಾನಿಸು RESTORE_ಕೊನೆಯ_ERROR_NAME ಪಠ್ಯ_3("RestoreLastError")
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->ಆಂತರಿಕ)!=ಸ್ಥಿತಿ_PENDING)

  WINBASEAPI WINBOOL WINAPI Get_Overlapped_ಫಲಿತಾಂಶ(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Transferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI Create_Io_Completion_ಪೋರ್ಟ್(HANDLE FileHandle,HANDLE Existing_Completion_ಪೋರ್ಟ್,ULONG_PTR Completion_ಕೀಲಿ,DWORD ಸಂಖ್ಯೆ_ದ_Concurrent_ಎಳೆಗಳು);
  WINBASEAPI WINBOOL WINAPI Get_Queued_Completion_ಸ್ಥಿತಿ(HANDLE Completion_ಪೋರ್ಟ್,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Transferred,PULONG_PTR lp_Completion_ಕೀಲಿ,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI Post_Queued_Completion_ಸ್ಥಿತಿ(HANDLE Completion_ಪೋರ್ಟ್,DWORD dw_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Transferred,ULONG_PTR dw_Completion_ಕೀಲಿ,LPOVERLAPPED lpOverlapped);

#ವ್ಯಾಖ್ಯಾನಿಸು SEM_FAILCRITICALERRORS 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು SEM_NOGPFAULTERRORBOX 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು SEM_NOALIGNMENTFAULTEXCEPT 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI ಗಣ_Error_ಬಹುಲಕ(UINT u_ಬಹುಲಕ);
  WINBASEAPI WINBOOL WINAPI Read_Process_ಸ್ಮರಣೆ(HANDLE hProcess,LPCVOID lp_ತಳ_ವಿಳಾಸ,LPVOID lp_ಬಫರ್,ಗಾತ್ರ_T n_ಗಾತ್ರ,ಗಾತ್ರ_T *lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Read);
  WINBASEAPI WINBOOL WINAPI Write_Process_ಸ್ಮರಣೆ(HANDLE hProcess,LPVOID lp_ತಳ_ವಿಳಾಸ,LPCVOID lp_ಬಫರ್,ಗಾತ್ರ_T n_ಗಾತ್ರ,ಗಾತ್ರ_T *lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Written);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Thread_Context(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI ಸರತಿ_User_APC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dw_ದತ್ತಾಂಶ);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dw_Continue_ಸ್ಥಿತಿ);
  WINBASEAPI WINBOOL WINAPI Debug_ಸಕ್ರಿಯ_Process(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_ಸಕ್ರಿಯ_Process_Stop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_ಗಣ_Process_Kill_On_Exit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI Initialize_Critical_Section_And_Spin_ಎಣಿಕೆ(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_ಎಣಿಕೆ);
  WINBASEAPI DWORD WINAPI ಗಣ_Critical_Section_Spin_ಎಣಿಕೆ(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_ಎಣಿಕೆ);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Event(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG l_Release_ಎಣಿಕೆ,LPLONG lp_ಹಿಂದಿನ_ಎಣಿಕೆ);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI Wait_For_ಅಪವರ್ತ್ಯ_Objects(DWORD n_ಎಣಿಕೆ,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI ತುಂಬು_Resource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI Init_Atom_ಕೋಷ್ಟಕ(DWORD n_ಗಾತ್ರ);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI ಗಣ_Handle_ಎಣಿಕೆ(UINT u_ಸಂಖ್ಯೆ);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI ಬೀಗ_File(HANDLE hFile,DWORD dw_File_ಸ್ಥಾನಾಂತರ_ಕೆಳಗಿನ,DWORD dw_File_ಸ್ಥಾನಾಂತರ_ಮೇಲಿನ,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_ಬೀಗ_ಕೆಳಗಿನ,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_ಬೀಗ_ಮೇಲಿನ);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dw_File_ಸ್ಥಾನಾಂತರ_ಕೆಳಗಿನ,DWORD dw_File_ಸ್ಥಾನಾಂತರ_ಮೇಲಿನ,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Unlock_ಕೆಳಗಿನ,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Unlock_ಮೇಲಿನ);
  WINBASEAPI WINBOOL WINAPI ಬೀಗ_File_Ex(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_ಬೀಗ_ಕೆಳಗಿನ,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_ಬೀಗ_ಮೇಲಿನ,LPOVERLAPPED lpOverlapped);

#ವ್ಯಾಖ್ಯಾನಿಸು LOCKFILE_FAIL_IMMEDIATELY 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು LOCKFILE_EXCLUSIVE_ಬೀಗ 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Unlock_ಕೆಳಗಿನ,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Unlock_ಮೇಲಿನ,LPOVERLAPPED lpOverlapped);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _BY_HANDLE_FILE_INFORMATION {
    DWORD dw_File_ಗುಣಲಕ್ಷಣಗಳು;
    FILETIME ft_Creation_ಸಮಯ;
    FILETIME ft_ಕೊನೆಯ_Access_ಸಮಯ;
    FILETIME ft_ಕೊನೆಯ_Write_ಸಮಯ;
    DWORD dw_Volume_Serial_ಸಂಖ್ಯೆ;
    DWORD n_File_ಗಾತ್ರ_ಮೇಲಿನ;
    DWORD n_File_ಗಾತ್ರ_ಕೆಳಗಿನ;
    DWORD n_ಸಂಖ್ಯೆ_ದ_Links;
    DWORD n_File_ಸೂಚ್ಯಂಕ_ಮೇಲಿನ;
    DWORD n_File_ಸೂಚ್ಯಂಕ_ಕೆಳಗಿನ;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_File_Short_Name ಗಣ_File_Short_Name_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_File_Short_Name ಗಣ_File_Short_Name_A
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI Get_File_ಗಾತ್ರ(HANDLE hFile,LPDWORD lp_File_ಗಾತ್ರ_ಮೇಲಿನ);
  WINBASEAPI WINBOOL WINAPI Get_File_ಗಾತ್ರ_Ex(HANDLE hFile,PLARGE_INTEGER lp_File_ಗಾತ್ರ);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Std_Handle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Write,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Written,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Read,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dw_Io_Control_ಸಂಕೇತ,LPVOID lp_ಒಳ_ಬಫರ್,DWORD n_ಒಳ_ಬಫರ್_ಗಾತ್ರ,LPVOID lp_ಹೊರಹೋಗು_ಬಫರ್,DWORD n_ಹೊರಹೋಗು_ಬಫರ್_ಗಾತ್ರ,LPDWORD lp_ಬೈಟುಗಳು_Returned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI ಗಣ_ಸಂದೇಶ_ಕಾಯುವಿಕೆ_Indicator(HANDLE h_ಸಂದೇಶ_Indicator,ULONG ul_ಸಂದೇಶ_ಎಣಿಕೆ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_ಕೊನೆ_ದ_File(HANDLE hFile);
  WINBASEAPI DWORD WINAPI ಗಣ_File_ಸೂಚಕ(HANDLE hFile,LONG l_ದೂರ_ಗಮ್ಯ_Move,PLONG lp_ದೂರ_ಗಮ್ಯ_Move_ಮೇಲಿನ,DWORD dw_Move_ವಿಧಾನ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_File_ಸೂಚಕ_Ex(HANDLE hFile,LARGE_INTEGER li_ದೂರ_ಗಮ್ಯ_Move,PLARGE_INTEGER lp_New_File_ಸೂಚಕ,DWORD dw_Move_ವಿಧಾನ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_Close(HANDLE h_ಕಂಡುಹಿಡಿ_File);
  WINBASEAPI WINBOOL WINAPI Get_File_ಸಮಯ(HANDLE hFile,LPFILETIME lp_Creation_ಸಮಯ,LPFILETIME lp_ಕೊನೆಯ_Access_ಸಮಯ,LPFILETIME lp_ಕೊನೆಯ_Write_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_File_ಸಮಯ(HANDLE hFile,CONST FILETIME *lp_Creation_ಸಮಯ,CONST FILETIME *lp_ಕೊನೆಯ_Access_ಸಮಯ,CONST FILETIME *lp_ಕೊನೆಯ_Write_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_File_Valid_ದತ್ತಾಂಶ(HANDLE hFile,LONGLONG Valid_ದತ್ತಾಂಶ_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_File_Short_Name_A(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI ಗಣ_File_Short_Name_W(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE h_ಮೂಲ_Process_Handle,HANDLE h_ಮೂಲ_Handle,HANDLE h_ಗುರಿ_Process_Handle,LPHANDLE lp_ಗುರಿ_Handle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Handle_Information(HANDLE hObject,DWORD dw_ಮುಖವಾಡ,DWORD dwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು HANDLE_FLAG_INHERIT 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#ವ್ಯಾಖ್ಯಾನಿಸು HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI ತುಂಬು_Module(LPCSTR lpModuleName,LPVOID lp_Parameter_ಖಂಡ);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lp_Cmd_ಸಾಲು,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI ಸಿದ್ಧತೆ_Comm(HANDLE hFile,DWORD dw_ಒಳ_ಸರತಿ,DWORD dw_ಹೊರಹೋಗು_ಸರತಿ);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdw_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI Get_Comm_ಮುಖವಾಡ(HANDLE hFile,LPDWORD lp_Evt_ಮುಖವಾಡ);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI Get_Comm_Modem_ಸ್ಥಿತಿ(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Comm_Break(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Comm_Config(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dw_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Comm_ಮುಖವಾಡ(HANDLE hFile,DWORD dw_Evt_ಮುಖವಾಡ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Comm_State(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Comm_Timeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,ಅಕ್ಷರ cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lp_Evt_ಮುಖವಾಡ,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI ಗಣ_ಪಟ್ಟಿ_Position(HANDLE hDevice,DWORD dw_Position_ವಿಧಾನ,DWORD dw_ವಿಭಜನೆ,DWORD dw_ಸ್ಥಾನಾಂತರ_ಕೆಳಗಿನ,DWORD dw_ಸ್ಥಾನಾಂತರ_ಮೇಲಿನ,WINBOOL b_ತಕ್ಷಣ);
  WINBASEAPI DWORD WINAPI Get_ಪಟ್ಟಿ_Position(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdw_ವಿಭಜನೆ,LPDWORD lpdw_ಸ್ಥಾನಾಂತರ_ಕೆಳಗಿನ,LPDWORD lpdw_ಸ್ಥಾನಾಂತರ_ಮೇಲಿನ);
  WINBASEAPI DWORD WINAPI Prepare_ಪಟ್ಟಿ(HANDLE hDevice,DWORD dwOperation,WINBOOL b_ತಕ್ಷಣ);
  WINBASEAPI DWORD WINAPI Erase_ಪಟ್ಟಿ(HANDLE hDevice,DWORD dwEraseType,WINBOOL b_ತಕ್ಷಣ);
  WINBASEAPI DWORD WINAPI Create_ಪಟ್ಟಿ_ವಿಭಜನೆ(HANDLE hDevice,DWORD dw_ವಿಭಜನೆ_ವಿಧಾನ,DWORD dw_ಎಣಿಕೆ,DWORD dw_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dw_Tapemark_ಎಣಿಕೆ,WINBOOL b_ತಕ್ಷಣ);
  WINBASEAPI DWORD WINAPI Get_ಪಟ್ಟಿ_ಸ್ಥಿತಿ(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI Get_ಪಟ್ಟಿ_Parameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdw_ಗಾತ್ರ,LPVOID lp_ಪಟ್ಟಿ_Information);

#ವ್ಯಾಖ್ಯಾನಿಸು GET_ಪಟ್ಟಿ_MEDIA_INFORMATION 0
#ವ್ಯಾಖ್ಯಾನಿಸು GET_ಪಟ್ಟಿ_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI ಗಣ_ಪಟ್ಟಿ_Parameters(HANDLE hDevice,DWORD dwOperation,LPVOID lp_ಪಟ್ಟಿ_Information);

#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಪಟ್ಟಿ_MEDIA_INFORMATION 0
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಪಟ್ಟಿ_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI ಪೂರ್ಣಾಂಕ WINAPI MulDiv(ಪೂರ್ಣಾಂಕ n_ಸಂಖ್ಯೆ,ಪೂರ್ಣಾಂಕ nNumerator,ಪೂರ್ಣಾಂಕ nDenominator);
  WINBASEAPI VOID WINAPI Get_System_ಸಮಯ(LPSYSTEMTIME lp_System_ಸಮಯ);
  WINBASEAPI VOID WINAPI Get_System_ಸಮಯ_As_File_ಸಮಯ(LPFILETIME lp_System_ಸಮಯ_As_File_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_System_ಸಮಯ(CONST SYSTEMTIME *lp_System_ಸಮಯ);
  WINBASEAPI VOID WINAPI Get_Local_ಸಮಯ(LPSYSTEMTIME lp_System_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Local_ಸಮಯ(CONST SYSTEMTIME *lp_System_ಸಮಯ);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI ಗಣ_System_File_Cache_ಗಾತ್ರ(ಗಾತ್ರ_T Minimum_File_Cache_ಗಾತ್ರ,ಗಾತ್ರ_T ಗರಿಷ್ಠ_File_Cache_ಗಾತ್ರ,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI Get_System_File_Cache_ಗಾತ್ರ(PSIZE_T lp_Minimum_File_Cache_ಗಾತ್ರ,PSIZE_T lp_ಗರಿಷ್ಠ_File_Cache_ಗಾತ್ರ,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdw_Quota_ಬಳಸಿದ);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lp_Idle_ಸಮಯ,LPFILETIME lp_Kernel_ಸಮಯ,LPFILETIME lp_User_ಸಮಯ);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಸಮಯ_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } ಸಮಯ_ZONE_INFORMATION_2,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Format_ಸಂದೇಶ Format_ಸಂದೇಶ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Format_ಸಂದೇಶ Format_ಸಂದೇಶ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI System_ಸಮಯ_ಗಮ್ಯ_Tz_Specific_Local_ಸಮಯ(LPTIME_ZONE_INFORMATION lp_ಸಮಯ_Zone_Information,LPSYSTEMTIME lp_Universal_ಸಮಯ,LPSYSTEMTIME lp_Local_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI Tz_Specific_Local_ಸಮಯ_ಗಮ್ಯ_System_ಸಮಯ(LPTIME_ZONE_INFORMATION lp_ಸಮಯ_Zone_Information,LPSYSTEMTIME lp_Local_ಸಮಯ,LPSYSTEMTIME lp_Universal_ಸಮಯ);
  WINBASEAPI DWORD WINAPI Get_ಸಮಯ_Zone_Information(LPTIME_ZONE_INFORMATION lp_ಸಮಯ_Zone_Information);
  WINBASEAPI WINBOOL WINAPI ಗಣ_ಸಮಯ_Zone_Information(CONST ಸಮಯ_ZONE_INFORMATION_2 *lp_ಸಮಯ_Zone_Information);
  WINBASEAPI WINBOOL WINAPI System_ಸಮಯ_ಗಮ್ಯ_File_ಸಮಯ(CONST SYSTEMTIME *lp_System_ಸಮಯ,LPFILETIME lp_File_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI File_ಸಮಯ_ಗಮ್ಯ_Local_File_ಸಮಯ(CONST FILETIME *lp_File_ಸಮಯ,LPFILETIME lp_Local_File_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI Local_File_ಸಮಯ_ಗಮ್ಯ_File_ಸಮಯ(CONST FILETIME *lp_Local_File_ಸಮಯ,LPFILETIME lp_File_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI File_ಸಮಯ_ಗಮ್ಯ_System_ಸಮಯ(CONST FILETIME *lp_File_ಸಮಯ,LPSYSTEMTIME lp_System_ಸಮಯ);
  WINBASEAPI LONG WINAPI Compare_File_ಸಮಯ(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI File_ಸಮಯ_ಗಮ್ಯ_Dos_Date_ಸಮಯ(CONST FILETIME *lp_File_ಸಮಯ,LPWORD lpFatDate,LPWORD lp_Fat_ಸಮಯ);
  WINBASEAPI WINBOOL WINAPI Dos_Date_ಸಮಯ_ಗಮ್ಯ_File_ಸಮಯ(ಶಬ್ದ_3 wFatDate,ಶಬ್ದ_3 w_Fat_ಸಮಯ,LPFILETIME lp_File_ಸಮಯ);
  WINBASEAPI DWORD WINAPI Get_Tick_ಎಣಿಕೆ(VOID);
  WINBASEAPI WINBOOL WINAPI ಗಣ_System_ಸಮಯ_Adjustment(DWORD dw_ಸಮಯ_Adjustment,WINBOOL b_ಸಮಯ_Adjustment_Disabled);
  WINBASEAPI WINBOOL WINAPI Get_System_ಸಮಯ_Adjustment(PDWORD lp_ಸಮಯ_Adjustment,PDWORD lp_ಸಮಯ_Increment,PBOOL lp_ಸಮಯ_Adjustment_Disabled);
  WINBASEAPI DWORD WINAPI Format_ಸಂದೇಶ_A(DWORD dwFlags,LPCVOID lp_ಮೂಲ,DWORD dw_ಸಂದೇಶ_Id,DWORD dwLanguageId,LPSTR lp_ಬಫರ್,DWORD n_ಗಾತ್ರ,va_list *Arguments);
  WINBASEAPI DWORD WINAPI Format_ಸಂದೇಶ_W(DWORD dwFlags,LPCVOID lp_ಮೂಲ,DWORD dw_ಸಂದೇಶ_Id,DWORD dwLanguageId,LPWSTR lp_ಬಫರ್,DWORD n_ಗಾತ್ರ,va_list *Arguments);

#ವ್ಯಾಖ್ಯಾನಿಸು FORMAT_ಸಂದೇಶ_ALLOCATE_ಬಫರ್ 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು FORMAT_ಸಂದೇಶ_IGNORE_INSERTS 0x200
#ವ್ಯಾಖ್ಯಾನಿಸು FORMAT_ಸಂದೇಶ_FROM_STRING 0x400
#ವ್ಯಾಖ್ಯಾನಿಸು FORMAT_ಸಂದೇಶ_FROM_HMODULE 0x800
#ವ್ಯಾಖ್ಯಾನಿಸು FORMAT_ಸಂದೇಶ_FROM_SYSTEM 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು FORMAT_ಸಂದೇಶ_ವಾದ_ARRAY 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು FORMAT_ಸಂದೇಶ_MAX_ಅಗಲ_ಮುಖವಾಡ 0xff

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು CreateMailslot CreateMailslotW
#ವ್ಯಾಖ್ಯಾನಿಸು EncryptFile EncryptFileW
#ವ್ಯಾಖ್ಯಾನಿಸು DecryptFile DecryptFileW
#ವ್ಯಾಖ್ಯಾನಿಸು File_Encryption_ಸ್ಥಿತಿ File_Encryption_ಸ್ಥಿತಿ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು CreateMailslot CreateMailslotA
#ವ್ಯಾಖ್ಯಾನಿಸು EncryptFile EncryptFileA
#ವ್ಯಾಖ್ಯಾನಿಸು DecryptFile DecryptFileA
#ವ್ಯಾಖ್ಯಾನಿಸು File_Encryption_ಸ್ಥಿತಿ File_Encryption_ಸ್ಥಿತಿ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Pipe_ಗುಣಲಕ್ಷಣಗಳು,DWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Named_Pipe_Handle_State(HANDLE hNamedPipe,LPDWORD lp_ಬಹುಲಕ,LPDWORD lp_Max_Collection_ಎಣಿಕೆ,LPDWORD lp_Collect_ದತ್ತಾಂಶ_Timeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lp_ಹೊರಹೋಗು_ಬಫರ್_ಗಾತ್ರ,LPDWORD lp_ಒಳ_ಬಫರ್_ಗಾತ್ರ,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lp_ಬಫರ್,DWORD n_ಬಫರ್_ಗಾತ್ರ,LPDWORD lp_ಬೈಟುಗಳು_Read,LPDWORD lp_ಒಟ್ಟು_ಬೈಟುಗಳು_Avail,LPDWORD lp_ಬೈಟುಗಳು_ಎಡ_This_ಸಂದೇಶ);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lp_ಒಳ_ಬಫರ್,DWORD n_ಒಳ_ಬಫರ್_ಗಾತ್ರ,LPVOID lp_ಹೊರಹೋಗು_ಬಫರ್,DWORD n_ಹೊರಹೋಗು_ಬಫರ್_ಗಾತ್ರ,LPDWORD lp_ಬೈಟುಗಳು_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD n_Max_ಸಂದೇಶ_ಗಾತ್ರ,DWORD lReadTimeout,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD n_Max_ಸಂದೇಶ_ಗಾತ್ರ,DWORD lReadTimeout,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lp_Max_ಸಂದೇಶ_ಗಾತ್ರ,LPDWORD lp_ಮುಂದಿನ_ಗಾತ್ರ,LPDWORD lp_ಸಂದೇಶ_ಎಣಿಕೆ,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Mailslot_Info(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI Map_View_ದ_File(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_ಸ್ಥಾನಾಂತರ_ಮೇಲಿನ,DWORD dw_File_ಸ್ಥಾನಾಂತರ_ಕೆಳಗಿನ,ಗಾತ್ರ_T dw_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Map);
  WINBASEAPI WINBOOL WINAPI Flush_View_ದ_File(LPCVOID lp_ತಳ_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Flush);
  WINBASEAPI WINBOOL WINAPI Unmap_View_ದ_File(LPCVOID lp_ತಳ_ವಿಳಾಸ);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ENCRYPTABLE 0
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_IS_ENCRYPTED 1
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SYSTEM_ATTR 2
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_ಬೇರು_DIR 3
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SYSTEM_DIR 4
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_UNKNOWN 5
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_SYSTEM_NOT_SUPPORT 6
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_USER_DISALLOWED 7
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_READ_ONLY 8
#ವ್ಯಾಖ್ಯಾನಿಸು FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI File_Encryption_ಸ್ಥಿತಿ_A(LPCSTR lpFileName,LPDWORD lp_ಸ್ಥಿತಿ);
  WINADVAPI WINBOOL WINAPI File_Encryption_ಸ್ಥಿತಿ_W(LPCWSTR lpFileName,LPDWORD lp_ಸ್ಥಿತಿ);

#ವ್ಯಾಖ್ಯಾನಿಸು EFS_USE_RECOVERY_ಕೀಲಿಗಳು (0x1)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pb_ದತ್ತಾಂಶ,PVOID pvCallbackContext,ULONG ul_ಉದ್ದಳತೆ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pb_ದತ್ತಾಂಶ,PVOID pvCallbackContext,PULONG ul_ಉದ್ದಳತೆ);

#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_FOR_IMPORT (1)
#ವ್ಯಾಖ್ಯಾನಿಸು CREATE_FOR_DIR (2)
#ವ್ಯಾಖ್ಯಾನಿಸು OVERWRITE_HIDDEN (4)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು OpenEncryptedFileRaw OpenEncryptedFileRawW
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcmp lstrcmpW
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcmpi lstrcmpiW
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcpyn lstrcpynW
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcpy lstrcpyW
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcat lstrcatW
#ವ್ಯಾಖ್ಯಾನಿಸು lstrlen lstrlenW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು OpenEncryptedFileRaw OpenEncryptedFileRawA
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcmp lstrcmpA
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcmpi lstrcmpiA
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcpyn lstrcpynA
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcpy lstrcpyA
#ವ್ಯಾಖ್ಯಾನಿಸು lstrcat lstrcatA
#ವ್ಯಾಖ್ಯಾನಿಸು lstrlen lstrlenA
#ಆದರೆ_ಅಂತ್ಯ

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI ಪೂರ್ಣಾಂಕ WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI ಪೂರ್ಣಾಂಕ WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI ಪೂರ್ಣಾಂಕ WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI ಪೂರ್ಣಾಂಕ WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,ಪೂರ್ಣಾಂಕ i_Max_ಉದ್ದಳತೆ);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,ಪೂರ್ಣಾಂಕ i_Max_ಉದ್ದಳತೆ);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI ಪೂರ್ಣಾಂಕ WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI ಪೂರ್ಣಾಂಕ WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lp_ಮಾರ್ಗ_Name,ಪೂರ್ಣಾಂಕ iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lp_ಮಾರ್ಗ_Name,ಪೂರ್ಣಾಂಕ iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lp_ಬಫರ್,UINT u_ಬೈಟುಗಳು);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lp_ಬಫರ್,UINT u_ಬೈಟುಗಳು);
  WINBASEAPI ದೀರ್ಘ WINAPI _hread(HFILE hFile,LPVOID lp_ಬಫರ್,ದೀರ್ಘ l_ಬೈಟುಗಳು);
  WINBASEAPI ದೀರ್ಘ WINAPI _hwrite(HFILE hFile,LPCCH lp_ಬಫರ್,ದೀರ್ಘ l_ಬೈಟುಗಳು);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG l_ಸ್ಥಾನಾಂತರ,ಪೂರ್ಣಾಂಕ iOrigin);
  WINADVAPI WINBOOL WINAPI Is_ಪಠ್ಯ_Unicode(CONST VOID *lpv,ಪೂರ್ಣಾಂಕ i_ಗಾತ್ರ,LPINT lpi_ಫಲಿತಾಂಶ);

#ವ್ಯಾಖ್ಯಾನಿಸು FLS_ಹೊರಹೋಗು_ದ_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI Fls_Get_ಮೌಲ್ಯ(DWORD dw_Fls_ಸೂಚ್ಯಂಕ);
  WINBASEAPI WINBOOL WINAPI Fls_ಗಣ_ಮೌಲ್ಯ(DWORD dw_Fls_ಸೂಚ್ಯಂಕ,PVOID lp_Fls_ದತ್ತಾಂಶ);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dw_Fls_ಸೂಚ್ಯಂಕ);

#ವ್ಯಾಖ್ಯಾನಿಸು TLS_ಹೊರಹೋಗು_ದ_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI Tls_Get_ಮೌಲ್ಯ(DWORD dw_Tls_ಸೂಚ್ಯಂಕ);
  WINBASEAPI WINBOOL WINAPI Tls_ಗಣ_ಮೌಲ್ಯ(DWORD dw_Tls_ಸೂಚ್ಯಂಕ,LPVOID lp_Tls_ಮೌಲ್ಯ);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dw_Tls_ಸೂಚ್ಯಂಕ);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dw_Error_ಸಂಕೇತ,DWORD dw_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Transfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI Wait_For_ಅಪವರ್ತ್ಯ_Objects_Ex(DWORD n_ಎಣಿಕೆ,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE h_Object_ಗಮ್ಯ_Signal,HANDLE h_Object_ಗಮ್ಯ_Wait_On,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Read,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Write,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Read,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Read,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dw_ಕೆಳಗಿನ_ಬೈಟುಗಳು_ಗಮ್ಯ_Seek,DWORD dw_ಮೇಲಿನ_ಬೈಟುಗಳು_ಗಮ್ಯ_Seek,LPDWORD lpdw_ಕೆಳಗಿನ_Byte_Seeked,LPDWORD lpdw_ಮೇಲಿನ_Byte_Seeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Write,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Written,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ WIN32_ಹರಿವು_ID {
    DWORD dw_ಹರಿವು_Id;
    DWORD dw_ಹರಿವು_ಗುಣಲಕ್ಷಣಗಳು;
    LARGE_INTEGER ಗಾತ್ರ_4;
    DWORD dw_ಹರಿವು_Name_ಗಾತ್ರ;
    WCHAR c_ಹರಿವು_Name[ANYSIZE_ARRAY];
  } WIN32_ಹರಿವು_ID_2,*LPWIN32_ಹರಿವು_ID;

#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_INVALID 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_ದತ್ತಾಂಶ 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_EA_ದತ್ತಾಂಶ 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_SECURITY_ದತ್ತಾಂಶ 0x3
#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_ALTERNATE_ದತ್ತಾಂಶ 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_LINK 0x5
#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_PROPERTY_ದತ್ತಾಂಶ 0x6
#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_OBJECT_ID 0x7
#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_REPARSE_ದತ್ತಾಂಶ 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು BACKUP_SPARSE_ಖಂಡ 0x9

#ವ್ಯಾಖ್ಯಾನಿಸು ಹರಿವು_ಸಾಮಾನ್ಯ_ATTRIBUTE 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು ಹರಿವು_MODIFIED_WHEN_READ 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ಹರಿವು_ಒಳಗೊಂಡಿದೆ_SECURITY 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ಹರಿವು_ಒಳಗೊಂಡಿದೆ_PROPERTIES 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು ಹರಿವು_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Read,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Write,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_USESHOWWINDOW 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_USESIZE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_USEPOSITION 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_USECOUNTCHARS 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_USEFILLATTRIBUTE 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_RUNFULLSCREEN 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_FORCEONFEEDBACK 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_FORCEOFFFEEDBACK 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_USESTDHANDLES 0x100

#ವ್ಯಾಖ್ಯಾನಿಸು STARTF_USEHOTKEY 0x200

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _STARTUPINFOA {
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
    ಶಬ್ದ_3 w_Show_ಕಿಟಕಿ;
    ಶಬ್ದ_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_ಒಳಹರಿವು;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOA,*LPSTARTUPINFOA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _STARTUPINFOW {
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
    ಶಬ್ದ_3 w_Show_ಕಿಟಕಿ;
    ಶಬ್ದ_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_ಒಳಹರಿವು;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ STARTUPINFOW STARTUPINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPSTARTUPINFOW LPSTARTUPINFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ STARTUPINFOA STARTUPINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPSTARTUPINFOA LPSTARTUPINFO;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು SHUTDOWN_NORETRY 0x1

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ WIN32_ಕಂಡುಹಿಡಿ_DATAA {
    DWORD dw_File_ಗುಣಲಕ್ಷಣಗಳು;
    FILETIME ft_Creation_ಸಮಯ;
    FILETIME ft_ಕೊನೆಯ_Access_ಸಮಯ;
    FILETIME ft_ಕೊನೆಯ_Write_ಸಮಯ;
    DWORD n_File_ಗಾತ್ರ_ಮೇಲಿನ;
    DWORD n_File_ಗಾತ್ರ_ಕೆಳಗಿನ;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_ಮಾರ್ಗ];
    CHAR cAlternateFileName[14];
  } WIN32_ಕಂಡುಹಿಡಿ_DATAA_2,*PWIN32_ಕಂಡುಹಿಡಿ_DATAA,*LPWIN32_ಕಂಡುಹಿಡಿ_DATAA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ WIN32_ಕಂಡುಹಿಡಿ_DATAW {
    DWORD dw_File_ಗುಣಲಕ್ಷಣಗಳು;
    FILETIME ft_Creation_ಸಮಯ;
    FILETIME ft_ಕೊನೆಯ_Access_ಸಮಯ;
    FILETIME ft_ಕೊನೆಯ_Write_ಸಮಯ;
    DWORD n_File_ಗಾತ್ರ_ಮೇಲಿನ;
    DWORD n_File_ಗಾತ್ರ_ಕೆಳಗಿನ;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_ಮಾರ್ಗ];
    WCHAR cAlternateFileName[14];
  } WIN32_ಕಂಡುಹಿಡಿ_DATAW_2,*PWIN32_ಕಂಡುಹಿಡಿ_DATAW,*LPWIN32_ಕಂಡುಹಿಡಿ_DATAW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WIN32_ಕಂಡುಹಿಡಿ_DATAW_2 WIN32_ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWIN32_ಕಂಡುಹಿಡಿ_DATAW PWIN32_ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWIN32_ಕಂಡುಹಿಡಿ_DATAW LPWIN32_ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WIN32_ಕಂಡುಹಿಡಿ_DATAA_2 WIN32_ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWIN32_ಕಂಡುಹಿಡಿ_DATAA PWIN32_ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWIN32_ಕಂಡುಹಿಡಿ_DATAA LPWIN32_ಕಂಡುಹಿಡಿ_ದತ್ತಾಂಶ;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ WIN32_FILE_ATTRIBUTE_ದತ್ತಾಂಶ {
    DWORD dw_File_ಗುಣಲಕ್ಷಣಗಳು;
    FILETIME ft_Creation_ಸಮಯ;
    FILETIME ft_ಕೊನೆಯ_Access_ಸಮಯ;
    FILETIME ft_ಕೊನೆಯ_Write_ಸಮಯ;
    DWORD n_File_ಗಾತ್ರ_ಮೇಲಿನ;
    DWORD n_File_ಗಾತ್ರ_ಕೆಳಗಿನ;
  } WIN32_FILE_ATTRIBUTE_ದತ್ತಾಂಶ_2,*LPWIN32_FILE_ATTRIBUTE_ದತ್ತಾಂಶ;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು CreateMutex CreateMutexW
#ವ್ಯಾಖ್ಯಾನಿಸು OpenMutex OpenMutexW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateEvent CreateEventW
#ವ್ಯಾಖ್ಯಾನಿಸು OpenEvent OpenEventW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateSemaphore CreateSemaphoreW
#ವ್ಯಾಖ್ಯಾನಿಸು OpenSemaphore OpenSemaphoreW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು CreateMutex CreateMutexA
#ವ್ಯಾಖ್ಯಾನಿಸು OpenMutex OpenMutexA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateEvent CreateEventA
#ವ್ಯಾಖ್ಯಾನಿಸು OpenEvent OpenEventA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateSemaphore CreateSemaphoreA
#ವ್ಯಾಖ್ಯಾನಿಸು OpenSemaphore OpenSemaphoreA
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Mutex_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Mutex_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Event_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Event_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Semaphore_ಗುಣಲಕ್ಷಣಗಳು,LONG l_Initial_ಎಣಿಕೆ,LONG l_ಗರಿಷ್ಠ_ಎಣಿಕೆ,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Semaphore_ಗುಣಲಕ್ಷಣಗಳು,LONG l_Initial_ಎಣಿಕೆ,LONG l_ಗರಿಷ್ಠ_ಎಣಿಕೆ,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lp_Arg_ಗಮ್ಯ_Completion_Routine,DWORD dw_Timer_ಕೆಳಗಿನ_ಮೌಲ್ಯ,DWORD dw_Timer_ಮೇಲಿನ_ಮೌಲ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು CreateWaitableTimer CreateWaitableTimerW
#ವ್ಯಾಖ್ಯಾನಿಸು OpenWaitableTimer OpenWaitableTimerW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateFileMapping CreateFileMappingW
#ವ್ಯಾಖ್ಯಾನಿಸು OpenFileMapping OpenFileMappingW
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Logical_Drive_ಅಕ್ಷರಸರಣಿಗಳು Get_Logical_Drive_ಅಕ್ಷರಸರಣಿಗಳು_W
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Library ತುಂಬು_Library_W
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Library_Ex ತುಂಬು_Library_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetModuleFileName GetModuleFileNameW
#ವ್ಯಾಖ್ಯಾನಿಸು GetModuleHandle GetModuleHandleW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು CreateWaitableTimer CreateWaitableTimerA
#ವ್ಯಾಖ್ಯಾನಿಸು OpenWaitableTimer OpenWaitableTimerA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateFileMapping CreateFileMappingA
#ವ್ಯಾಖ್ಯಾನಿಸು OpenFileMapping OpenFileMappingA
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Logical_Drive_ಅಕ್ಷರಸರಣಿಗಳು Get_Logical_Drive_ಅಕ್ಷರಸರಣಿಗಳು_A
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Library ತುಂಬು_Library_A
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Library_Ex ತುಂಬು_Library_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetModuleFileName GetModuleFileNameA
#ವ್ಯಾಖ್ಯಾನಿಸು GetModuleHandle GetModuleHandleA
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Timer_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Timer_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Waitable_Timer(HANDLE hTimer,ಸ್ಥಿರಾಂಕ LARGE_INTEGER *lp_Due_ಸಮಯ,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lp_Arg_ಗಮ್ಯ_Completion_Routine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_File_Mapping_ಗುಣಲಕ್ಷಣಗಳು,DWORD flProtect,DWORD dw_ಗರಿಷ್ಠ_ಗಾತ್ರ_ಮೇಲಿನ,DWORD dw_ಗರಿಷ್ಠ_ಗಾತ್ರ_ಕೆಳಗಿನ,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_File_Mapping_ಗುಣಲಕ್ಷಣಗಳು,DWORD flProtect,DWORD dw_ಗರಿಷ್ಠ_ಗಾತ್ರ_ಮೇಲಿನ,DWORD dw_ಗರಿಷ್ಠ_ಗಾತ್ರ_ಕೆಳಗಿನ,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_ಅಕ್ಷರಸರಣಿಗಳು_A(DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPSTR lp_ಬಫರ್);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_ಅಕ್ಷರಸರಣಿಗಳು_W(DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPWSTR lp_ಬಫರ್);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ ಸ್ಮರಣೆ_RESOURCE_NOTIFICATION_TYPE {
    ಕೆಳಗಿನ_ಸ್ಮರಣೆ_Resource_Notification,ಮೇಲಿನ_ಸ್ಮರಣೆ_Resource_Notification
  } ಸ್ಮರಣೆ_RESOURCE_NOTIFICATION_TYPE_2;

  WINBASEAPI HANDLE WINAPI Create_ಸ್ಮರಣೆ_Resource_Notification(ಸ್ಮರಣೆ_RESOURCE_NOTIFICATION_TYPE_2 NotificationType);
  WINBASEAPI WINBOOL WINAPI Query_ಸ್ಮರಣೆ_Resource_Notification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI ತುಂಬು_Library_A(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI ತುಂಬು_Library_W(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI ತುಂಬು_Library_Ex_A(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI ತುಂಬು_Library_Ex_W(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು DONT_RESOLVE_DLL_REFERENCES 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_AS_DATAFILE 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_WITH_ALTERED_ಹುಡುಕು_ಮಾರ್ಗ 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_IGNORE_ಸಂಕೇತ_AUTHZ_LEVEL 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_AS_IMAGE_RESOURCE 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_REQUIRE_SIGNED_ಗುರಿ 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_ಹುಡುಕು_DLL_ತುಂಬು_DIR 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_ಹುಡುಕು_APPLICATION_DIR 0x200
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_ಹುಡುಕು_USER_DIRS 0x400
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_ಹುಡುಕು_SYSTEM32 0x800
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_ಹುಡುಕು_DEFAULT_DIRS 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_LIBRARY_ಸುರಕ್ಷಿತ_CURRENT_DIRS 0x2000

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD n_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD n_ಗಾತ್ರ);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿಸು GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು GET_MODULE_HANDLE_EX_FLAG_FROM_ವಿಳಾಸ (0x4)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#ವ್ಯಾಖ್ಯಾನಿಸು GetModuleHandleEx GetModuleHandleExW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#ವ್ಯಾಖ್ಯಾನಿಸು GetModuleHandleEx GetModuleHandleExA
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Need_Current_Directory_For_Exe_ಮಾರ್ಗ Need_Current_Directory_For_Exe_ಮಾರ್ಗ_W
#ವ್ಯಾಖ್ಯಾನಿಸು CreateProcess CreateProcessW
#ವ್ಯಾಖ್ಯಾನಿಸು FatalAppExit FatalAppExitW
#ವ್ಯಾಖ್ಯಾನಿಸು GetStartupInfo GetStartupInfoW
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Command_ಸಾಲು Get_Command_ಸಾಲು_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetEnvironmentVariable GetEnvironmentVariableW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Environment_Variable ಗಣ_Environment_Variable_W
#ವ್ಯಾಖ್ಯಾನಿಸು Expand_Environment_ಅಕ್ಷರಸರಣಿಗಳು Expand_Environment_ಅಕ್ಷರಸರಣಿಗಳು_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Firmware_Environment_Variable ಗಣ_Firmware_Environment_Variable_W
#ವ್ಯಾಖ್ಯಾನಿಸು OutputDebugString OutputDebugStringW
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Resource ಕಂಡುಹಿಡಿ_Resource_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Resource_Ex ಕಂಡುಹಿಡಿ_Resource_Ex_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Need_Current_Directory_For_Exe_ಮಾರ್ಗ Need_Current_Directory_For_Exe_ಮಾರ್ಗ_A
#ವ್ಯಾಖ್ಯಾನಿಸು CreateProcess CreateProcessA
#ವ್ಯಾಖ್ಯಾನಿಸು FatalAppExit FatalAppExitA
#ವ್ಯಾಖ್ಯಾನಿಸು GetStartupInfo GetStartupInfoA
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Command_ಸಾಲು Get_Command_ಸಾಲು_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetEnvironmentVariable GetEnvironmentVariableA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Environment_Variable ಗಣ_Environment_Variable_A
#ವ್ಯಾಖ್ಯಾನಿಸು Expand_Environment_ಅಕ್ಷರಸರಣಿಗಳು Expand_Environment_ಅಕ್ಷರಸರಣಿಗಳು_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Firmware_Environment_Variable ಗಣ_Firmware_Environment_Variable_A
#ವ್ಯಾಖ್ಯಾನಿಸು OutputDebugString OutputDebugStringA
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Resource ಕಂಡುಹಿಡಿ_Resource_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Resource_Ex ಕಂಡುಹಿಡಿ_Resource_Ex_A
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_ಮಾರ್ಗ_A(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_ಮಾರ್ಗ_W(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lp_Command_ಸಾಲು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Process_ಗುಣಲಕ್ಷಣಗಳು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Thread_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lp_Command_ಸಾಲು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Process_ಗುಣಲಕ್ಷಣಗಳು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Thread_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI ಕೂಡಿಸು_Local_Alternate_Computer_Name_A(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI ಕೂಡಿಸು_Local_Alternate_Computer_Name_W(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Process_Shutdown_Parameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI Get_Process_ಆವೃತ್ತಿ(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lp_ಸಂದೇಶ_ಪಠ್ಯ);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lp_ಸಂದೇಶ_ಪಠ್ಯ);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI Get_Command_ಸಾಲು_A(VOID);
  WINBASEAPI LPWSTR WINAPI Get_Command_ಸಾಲು_W(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lp_ಬಫರ್,DWORD n_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lp_ಬಫರ್,DWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Environment_Variable_A(LPCSTR lpName,LPCSTR lp_ಮೌಲ್ಯ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lp_ಮೌಲ್ಯ);
  WINBASEAPI DWORD WINAPI Expand_Environment_ಅಕ್ಷರಸರಣಿಗಳು_A(LPCSTR lpSrc,LPSTR lpDst,DWORD n_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI Expand_Environment_ಅಕ್ಷರಸರಣಿಗಳು_W(LPCWSTR lpSrc,LPWSTR lpDst,DWORD n_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_ಬಫರ್,DWORD n_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_ಬಫರ್,DWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Firmware_Environment_Variable_A(LPCSTR lpName,LPCSTR lpGuid,PVOID p_ಮೌಲ್ಯ,DWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Firmware_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_ಮೌಲ್ಯ,DWORD n_ಗಾತ್ರ);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI ಕಂಡುಹಿಡಿ_Resource_A(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI ಕಂಡುಹಿಡಿ_Resource_W(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI ಕಂಡುಹಿಡಿ_Resource_Ex_A(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ಶಬ್ದ_3 wLanguage);
  WINBASEAPI HRSRC WINAPI ಕಂಡುಹಿಡಿ_Resource_Ex_W(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ಶಬ್ದ_3 wLanguage);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ENUMRESTYPEPROC ENUMRESTYPEPROCW
#ವ್ಯಾಖ್ಯಾನಿಸು ENUMRESNAMEPROC ENUMRESNAMEPROCW
#ವ್ಯಾಖ್ಯಾನಿಸು ENUMRESLANGPROC ENUMRESLANGPROCW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumResourceTypes EnumResourceTypesW
#ವ್ಯಾಖ್ಯಾನಿಸು Enum_Resource_ಹೆಸರುಗಳು Enum_Resource_ಹೆಸರುಗಳು_W
#ವ್ಯಾಖ್ಯಾನಿಸು EnumResourceLanguages EnumResourceLanguagesW
#ವ್ಯಾಖ್ಯಾನಿಸು BeginUpdateResource BeginUpdateResourceW
#ವ್ಯಾಖ್ಯಾನಿಸು UpdateResource UpdateResourceW
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೊನೆ_Update_Resource ಕೊನೆ_Update_Resource_W
#ವ್ಯಾಖ್ಯಾನಿಸು Global_ಕೂಡಿಸು_Atom Global_ಕೂಡಿಸು_Atom_W
#ವ್ಯಾಖ್ಯಾನಿಸು Global_ಕಂಡುಹಿಡಿ_Atom Global_ಕಂಡುಹಿಡಿ_Atom_W
#ವ್ಯಾಖ್ಯಾನಿಸು GlobalGetAtomName GlobalGetAtomNameW
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Atom ಕೂಡಿಸು_Atom_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Atom ಕಂಡುಹಿಡಿ_Atom_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetAtomName GetAtomNameW
#ವ್ಯಾಖ್ಯಾನಿಸು GetProfileInt GetProfileIntW
#ವ್ಯಾಖ್ಯಾನಿಸು GetProfileString GetProfileStringW
#ವ್ಯಾಖ್ಯಾನಿಸು WriteProfileString WriteProfileStringW
#ವ್ಯಾಖ್ಯಾನಿಸು GetProfileSection GetProfileSectionW
#ವ್ಯಾಖ್ಯಾನಿಸು WriteProfileSection WriteProfileSectionW
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_Int Get_ಖಾಸಗಿ_Profile_Int_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_String Get_ಖಾಸಗಿ_Profile_String_W
#ವ್ಯಾಖ್ಯಾನಿಸು Write_ಖಾಸಗಿ_Profile_String Write_ಖಾಸಗಿ_Profile_String_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_Section Get_ಖಾಸಗಿ_Profile_Section_W
#ವ್ಯಾಖ್ಯಾನಿಸು Write_ಖಾಸಗಿ_Profile_Section Write_ಖಾಸಗಿ_Profile_Section_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_Section_ಹೆಸರುಗಳು Get_ಖಾಸಗಿ_Profile_Section_ಹೆಸರುಗಳು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_Struct Get_ಖಾಸಗಿ_Profile_Struct_W
#ವ್ಯಾಖ್ಯಾನಿಸು Write_ಖಾಸಗಿ_Profile_Struct Write_ಖಾಸಗಿ_Profile_Struct_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetDriveType GetDriveTypeW
#ವ್ಯಾಖ್ಯಾನಿಸು GetSystemDirectory GetSystemDirectoryW
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ತಾತ್ಕಾಲಿಕ_ಮಾರ್ಗ Get_ತಾತ್ಕಾಲಿಕ_ಮಾರ್ಗ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ತಾತ್ಕಾಲಿಕ_File_Name Get_ತಾತ್ಕಾಲಿಕ_File_Name_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetWindowsDirectory GetWindowsDirectoryW
#ವ್ಯಾಖ್ಯಾನಿಸು GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Local_Alternate_Computer_Name ಕೂಡಿಸು_Local_Alternate_Computer_Name_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ENUMRESTYPEPROC ENUMRESTYPEPROCA
#ವ್ಯಾಖ್ಯಾನಿಸು ENUMRESNAMEPROC ENUMRESNAMEPROCA
#ವ್ಯಾಖ್ಯಾನಿಸು ENUMRESLANGPROC ENUMRESLANGPROCA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumResourceTypes EnumResourceTypesA
#ವ್ಯಾಖ್ಯಾನಿಸು Enum_Resource_ಹೆಸರುಗಳು Enum_Resource_ಹೆಸರುಗಳು_A
#ವ್ಯಾಖ್ಯಾನಿಸು EnumResourceLanguages EnumResourceLanguagesA
#ವ್ಯಾಖ್ಯಾನಿಸು BeginUpdateResource BeginUpdateResourceA
#ವ್ಯಾಖ್ಯಾನಿಸು UpdateResource UpdateResourceA
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೊನೆ_Update_Resource ಕೊನೆ_Update_Resource_A
#ವ್ಯಾಖ್ಯಾನಿಸು Global_ಕೂಡಿಸು_Atom Global_ಕೂಡಿಸು_Atom_A
#ವ್ಯಾಖ್ಯಾನಿಸು Global_ಕಂಡುಹಿಡಿ_Atom Global_ಕಂಡುಹಿಡಿ_Atom_A
#ವ್ಯಾಖ್ಯಾನಿಸು GlobalGetAtomName GlobalGetAtomNameA
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Atom ಕೂಡಿಸು_Atom_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Atom ಕಂಡುಹಿಡಿ_Atom_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetAtomName GetAtomNameA
#ವ್ಯಾಖ್ಯಾನಿಸು GetProfileInt GetProfileIntA
#ವ್ಯಾಖ್ಯಾನಿಸು GetProfileString GetProfileStringA
#ವ್ಯಾಖ್ಯಾನಿಸು WriteProfileString WriteProfileStringA
#ವ್ಯಾಖ್ಯಾನಿಸು GetProfileSection GetProfileSectionA
#ವ್ಯಾಖ್ಯಾನಿಸು WriteProfileSection WriteProfileSectionA
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_Int Get_ಖಾಸಗಿ_Profile_Int_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_String Get_ಖಾಸಗಿ_Profile_String_A
#ವ್ಯಾಖ್ಯಾನಿಸು Write_ಖಾಸಗಿ_Profile_String Write_ಖಾಸಗಿ_Profile_String_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_Section Get_ಖಾಸಗಿ_Profile_Section_A
#ವ್ಯಾಖ್ಯಾನಿಸು Write_ಖಾಸಗಿ_Profile_Section Write_ಖಾಸಗಿ_Profile_Section_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_Section_ಹೆಸರುಗಳು Get_ಖಾಸಗಿ_Profile_Section_ಹೆಸರುಗಳು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಖಾಸಗಿ_Profile_Struct Get_ಖಾಸಗಿ_Profile_Struct_A
#ವ್ಯಾಖ್ಯಾನಿಸು Write_ಖಾಸಗಿ_Profile_Struct Write_ಖಾಸಗಿ_Profile_Struct_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetDriveType GetDriveTypeA
#ವ್ಯಾಖ್ಯಾನಿಸು GetSystemDirectory GetSystemDirectoryA
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ತಾತ್ಕಾಲಿಕ_ಮಾರ್ಗ Get_ತಾತ್ಕಾಲಿಕ_ಮಾರ್ಗ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ತಾತ್ಕಾಲಿಕ_File_Name Get_ತಾತ್ಕಾಲಿಕ_File_Name_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetWindowsDirectory GetWindowsDirectoryA
#ವ್ಯಾಖ್ಯಾನಿಸು GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Local_Alternate_Computer_Name ಕೂಡಿಸು_Local_Alternate_Computer_Name_A
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ಶಬ್ದ_3 wLanguage,LONG_PTR lParam);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ಶಬ್ದ_3 wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_ಹೆಸರುಗಳು_A(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_ಹೆಸರುಗಳು_W(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,ಶಬ್ದ_3 wLanguage,LPVOID lp_ದತ್ತಾಂಶ,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,ಶಬ್ದ_3 wLanguage,LPVOID lp_ದತ್ತಾಂಶ,DWORD cb);
  WINBASEAPI WINBOOL WINAPI ಕೊನೆ_Update_Resource_A(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI ಕೊನೆ_Update_Resource_W(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI Global_ಕೂಡಿಸು_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ಕೂಡಿಸು_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ಕಂಡುಹಿಡಿ_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ಕಂಡುಹಿಡಿ_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lp_ಬಫರ್,ಪೂರ್ಣಾಂಕ n_ಗಾತ್ರ);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lp_ಬಫರ್,ಪೂರ್ಣಾಂಕ n_ಗಾತ್ರ);
  WINBASEAPI ATOM WINAPI ಕೂಡಿಸು_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI ಕೂಡಿಸು_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI ಕಂಡುಹಿಡಿ_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI ಕಂಡುಹಿಡಿ_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lp_ಬಫರ್,ಪೂರ್ಣಾಂಕ n_ಗಾತ್ರ);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lp_ಬಫರ್,ಪೂರ್ಣಾಂಕ n_ಗಾತ್ರ);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lp_ಕೀಲಿ_Name,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_ಕೀಲಿ_Name,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lp_ಕೀಲಿ_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_ಕೀಲಿ_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lp_ಕೀಲಿ_Name,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_ಕೀಲಿ_Name,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI Get_ಖಾಸಗಿ_Profile_Int_A(LPCSTR lpAppName,LPCSTR lp_ಕೀಲಿ_Name,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI Get_ಖಾಸಗಿ_Profile_Int_W(LPCWSTR lpAppName,LPCWSTR lp_ಕೀಲಿ_Name,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ಖಾಸಗಿ_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_ಕೀಲಿ_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_ಗಾತ್ರ,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ಖಾಸಗಿ_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_ಕೀಲಿ_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_ಗಾತ್ರ,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ಖಾಸಗಿ_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_ಕೀಲಿ_Name,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ಖಾಸಗಿ_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_ಕೀಲಿ_Name,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ಖಾಸಗಿ_Profile_Section_A(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_ಗಾತ್ರ,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ಖಾಸಗಿ_Profile_Section_W(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_ಗಾತ್ರ,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ಖಾಸಗಿ_Profile_Section_A(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ಖಾಸಗಿ_Profile_Section_W(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ಖಾಸಗಿ_Profile_Section_ಹೆಸರುಗಳು_A(LPSTR lpsz_Return_ಬಫರ್,DWORD n_ಗಾತ್ರ,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ಖಾಸಗಿ_Profile_Section_ಹೆಸರುಗಳು_W(LPWSTR lpsz_Return_ಬಫರ್,DWORD n_ಗಾತ್ರ,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Get_ಖಾಸಗಿ_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_ಕೀಲಿ,LPVOID lpStruct,UINT u_ಗಾತ್ರ_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Get_ಖಾಸಗಿ_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_ಕೀಲಿ,LPVOID lpStruct,UINT u_ಗಾತ್ರ_Struct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_ಖಾಸಗಿ_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_ಕೀಲಿ,LPVOID lpStruct,UINT u_ಗಾತ್ರ_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_ಖಾಸಗಿ_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_ಕೀಲಿ,LPVOID lpStruct,UINT u_ಗಾತ್ರ_Struct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lp_ಬೇರು_ಮಾರ್ಗ_Name);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lp_ಬೇರು_ಮಾರ್ಗ_Name);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI Get_ತಾತ್ಕಾಲಿಕ_ಮಾರ್ಗ_A(DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPSTR lp_ಬಫರ್);
  WINBASEAPI DWORD WINAPI Get_ತಾತ್ಕಾಲಿಕ_ಮಾರ್ಗ_W(DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPWSTR lp_ಬಫರ್);
  WINBASEAPI UINT WINAPI Get_ತಾತ್ಕಾಲಿಕ_File_Name_A(LPCSTR lp_ಮಾರ್ಗ_Name,LPCSTR lp_ಪೂರ್ವಪ್ರತ್ಯಯ_String,UINT uUnique,LPSTR lp_ತಾತ್ಕಾಲಿಕ_File_Name);
  WINBASEAPI UINT WINAPI Get_ತಾತ್ಕಾಲಿಕ_File_Name_W(LPCWSTR lp_ಮಾರ್ಗ_Name,LPCWSTR lp_ಪೂರ್ವಪ್ರತ್ಯಯ_String,UINT uUnique,LPWSTR lp_ತಾತ್ಕಾಲಿಕ_File_Name);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetSystemWow64Directory GetSystemWow64DirectoryW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetSystemWow64Directory GetSystemWow64DirectoryA
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *Old_ಮೌಲ್ಯ);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID Ol_ಮೌಲ್ಯ);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lp_ಬಫರ್,UINT u_ಗಾತ್ರ);

#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T ಪಠ್ಯ_3("GetSystemWow64DirectoryA")
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T ಪಠ್ಯ_3("GetSystemWow64DirectoryW")

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#ವ್ಯಾಖ್ಯಾನಿಸು GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Current_Directory ಗಣ_Current_Directory_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetCurrentDirectory GetCurrentDirectoryW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Dll_Directory ಗಣ_Dll_Directory_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetDllDirectory GetDllDirectoryW
#ವ್ಯಾಖ್ಯಾನಿಸು GetDiskFreeSpace GetDiskFreeSpaceW
#ವ್ಯಾಖ್ಯಾನಿಸು GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDirectory CreateDirectoryW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDirectoryEx CreateDirectoryExW
#ವ್ಯಾಖ್ಯಾನಿಸು RemoveDirectory RemoveDirectoryW
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ತುಂಬಿದ_ಮಾರ್ಗ_Name Get_ತುಂಬಿದ_ಮಾರ್ಗ_Name_W
#ವ್ಯಾಖ್ಯಾನಿಸು DefineDosDevice DefineDosDeviceW
#ವ್ಯಾಖ್ಯಾನಿಸು QueryDosDevice QueryDosDeviceW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateFile CreateFileW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_File_ಗುಣಲಕ್ಷಣಗಳು ಗಣ_File_ಗುಣಲಕ್ಷಣಗಳು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_File_ಗುಣಲಕ್ಷಣಗಳು Get_File_ಗುಣಲಕ್ಷಣಗಳು_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Current_Directory ಗಣ_Current_Directory_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetCurrentDirectory GetCurrentDirectoryA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Dll_Directory ಗಣ_Dll_Directory_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetDllDirectory GetDllDirectoryA
#ವ್ಯಾಖ್ಯಾನಿಸು GetDiskFreeSpace GetDiskFreeSpaceA
#ವ್ಯಾಖ್ಯಾನಿಸು GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDirectory CreateDirectoryA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDirectoryEx CreateDirectoryExA
#ವ್ಯಾಖ್ಯಾನಿಸು RemoveDirectory RemoveDirectoryA
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ತುಂಬಿದ_ಮಾರ್ಗ_Name Get_ತುಂಬಿದ_ಮಾರ್ಗ_Name_A
#ವ್ಯಾಖ್ಯಾನಿಸು DefineDosDevice DefineDosDeviceA
#ವ್ಯಾಖ್ಯಾನಿಸು QueryDosDevice QueryDosDeviceA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateFile CreateFileA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_File_ಗುಣಲಕ್ಷಣಗಳು ಗಣ_File_ಗುಣಲಕ್ಷಣಗಳು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_File_ಗುಣಲಕ್ಷಣಗಳು Get_File_ಗುಣಲಕ್ಷಣಗಳು_A
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI ಗಣ_Current_Directory_A(LPCSTR lp_ಮಾರ್ಗ_Name);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Current_Directory_W(LPCWSTR lp_ಮಾರ್ಗ_Name);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPSTR lp_ಬಫರ್);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPWSTR lp_ಬಫರ್);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Dll_Directory_A(LPCSTR lp_ಮಾರ್ಗ_Name);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Dll_Directory_W(LPCWSTR lp_ಮಾರ್ಗ_Name);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPSTR lp_ಬಫರ್);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPWSTR lp_ಬಫರ್);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lp_ಬೇರು_ಮಾರ್ಗ_Name,LPDWORD lp_Sectors_ಪ್ರತಿ_Cluster,LPDWORD lp_ಬೈಟುಗಳು_ಪ್ರತಿ_Sector,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Free_Clusters,LPDWORD lp_ಒಟ್ಟು_ಸಂಖ್ಯೆ_ದ_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lp_ಬೇರು_ಮಾರ್ಗ_Name,LPDWORD lp_Sectors_ಪ್ರತಿ_Cluster,LPDWORD lp_ಬೈಟುಗಳು_ಪ್ರತಿ_Sector,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Free_Clusters,LPDWORD lp_ಒಟ್ಟು_ಸಂಖ್ಯೆ_ದ_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lp_Free_ಬೈಟುಗಳು_ಲಭ್ಯ_ಗಮ್ಯ_Caller,PULARGE_INTEGER lp_ಒಟ್ಟು_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು,PULARGE_INTEGER lp_ಒಟ್ಟು_ಸಂಖ್ಯೆ_ದ_Free_ಬೈಟುಗಳು);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lp_Free_ಬೈಟುಗಳು_ಲಭ್ಯ_ಗಮ್ಯ_Caller,PULARGE_INTEGER lp_ಒಟ್ಟು_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು,PULARGE_INTEGER lp_ಒಟ್ಟು_ಸಂಖ್ಯೆ_ದ_Free_ಬೈಟುಗಳು);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lp_ಮಾರ್ಗ_Name,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lp_ಮಾರ್ಗ_Name,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lp_ಮಾರ್ಗ_Name);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lp_ಮಾರ್ಗ_Name);
  WINBASEAPI DWORD WINAPI Get_ತುಂಬಿದ_ಮಾರ್ಗ_Name_A(LPCSTR lpFileName,DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPSTR lp_ಬಫರ್,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI Get_ತುಂಬಿದ_ಮಾರ್ಗ_Name_W(LPCWSTR lpFileName,DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPWSTR lp_ಬಫರ್,LPWSTR *lpFilePart);

#ವ್ಯಾಖ್ಯಾನಿಸು DDD_RAW_ಗುರಿ_ಮಾರ್ಗ 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು DDD_REMOVE_DEFINITION 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು DDD_EXACT_ಹೊಂದಿಕೆ_ON_REMOVE 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು DDD_NO_ಪ್ರಸಾರ_SYSTEM 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು DDD_LUID_ಪ್ರಸಾರ_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lp_ಗುರಿ_ಮಾರ್ಗ);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lp_ಗುರಿ_ಮಾರ್ಗ);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lp_ಗುರಿ_ಮಾರ್ಗ,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lp_ಗುರಿ_ಮಾರ್ಗ,DWORD ucchMax);

#ವ್ಯಾಖ್ಯಾನಿಸು EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_ಬಹುಲಕ,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು,DWORD dwCreationDisposition,DWORD dw_Flags_And_ಗುಣಲಕ್ಷಣಗಳು,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_ಬಹುಲಕ,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು,DWORD dwCreationDisposition,DWORD dw_Flags_And_ಗುಣಲಕ್ಷಣಗಳು,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dw_Share_ಬಹುಲಕ,DWORD dw_Flags_And_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI ಗಣ_File_ಗುಣಲಕ್ಷಣಗಳು_A(LPCSTR lpFileName,DWORD dw_File_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI ಗಣ_File_ಗುಣಲಕ್ಷಣಗಳು_W(LPCWSTR lpFileName,DWORD dw_File_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI DWORD WINAPI Get_File_ಗುಣಲಕ್ಷಣಗಳು_A(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_File_ಗುಣಲಕ್ಷಣಗಳು_W(LPCWSTR lpFileName);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ GET_FILEEX_INFO_ಮಟ್ಟಗಳು {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_ಮಟ್ಟಗಳು_2;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_File_ಗುಣಲಕ್ಷಣಗಳು_Ex Get_File_ಗುಣಲಕ್ಷಣಗಳು_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Compressed_File_ಗಾತ್ರ Get_Compressed_File_ಗಾತ್ರ_W
#ವ್ಯಾಖ್ಯಾನಿಸು DeleteFile DeleteFileW
#ವ್ಯಾಖ್ಯಾನಿಸು CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_File_ಗುಣಲಕ್ಷಣಗಳು_Ex Get_File_ಗುಣಲಕ್ಷಣಗಳು_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Compressed_File_ಗಾತ್ರ Get_Compressed_File_ಗಾತ್ರ_A
#ವ್ಯಾಖ್ಯಾನಿಸು DeleteFile DeleteFileA
#ವ್ಯಾಖ್ಯಾನಿಸು CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI Get_File_ಗುಣಲಕ್ಷಣಗಳು_Ex_A(LPCSTR lpFileName,GET_FILEEX_INFO_ಮಟ್ಟಗಳು_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI Get_File_ಗುಣಲಕ್ಷಣಗಳು_Ex_W(LPCWSTR lpFileName,GET_FILEEX_INFO_ಮಟ್ಟಗಳು_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_ಗಾತ್ರ_A(LPCSTR lpFileName,LPDWORD lp_File_ಗಾತ್ರ_ಮೇಲಿನ);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_ಗಾತ್ರ_W(LPCWSTR lpFileName,LPDWORD lp_File_ಗಾತ್ರ_ಮೇಲಿನ);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD Oem_Name_ಗಾತ್ರ,PBOOL pb_Name_ಒಳಗೊಂಡಿದೆ_Spaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD Oem_Name_ಗಾತ್ರ,PBOOL pb_Name_ಒಳಗೊಂಡಿದೆ_Spaces,PBOOL pbNameLegal);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ FINDEX_INFO_ಮಟ್ಟಗಳು {
    ಕಂಡುಹಿಡಿ_Ex_Info_Standard,ಕಂಡುಹಿಡಿ_Ex_Info_Max_Info_Level
  } FINDEX_INFO_ಮಟ್ಟಗಳು_2;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ FINDEX_ಹುಡುಕು_OPS {
    ಕಂಡುಹಿಡಿ_Ex_ಹುಡುಕು_Name_ಹೊಂದಿಕೆ,ಕಂಡುಹಿಡಿ_Ex_ಹುಡುಕು_ಎಲ್ಲೆ_ಗಮ್ಯ_Directories,ಕಂಡುಹಿಡಿ_Ex_ಹುಡುಕು_ಎಲ್ಲೆ_ಗಮ್ಯ_Devices,ಕಂಡುಹಿಡಿ_Ex_ಹುಡುಕು_Max_ಹುಡುಕು_Op
  } FINDEX_ಹುಡುಕು_OPS_2;

#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_EX_CASE_SENSITIVE 0x1

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_Ex ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_File ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_File ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_File_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಹುಡುಕು_ಮಾರ್ಗ ಹುಡುಕು_ಮಾರ್ಗ_W
#ವ್ಯಾಖ್ಯಾನಿಸು CopyFile CopyFileW
#ವ್ಯಾಖ್ಯಾನಿಸು CopyFileEx CopyFileExW
#ವ್ಯಾಖ್ಯಾನಿಸು MoveFile MoveFileW
#ವ್ಯಾಖ್ಯಾನಿಸು MoveFileEx MoveFileExW
#ವ್ಯಾಖ್ಯಾನಿಸು Move_File_With_ಪ್ರಗತಿ Move_File_With_ಪ್ರಗತಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು ReplaceFile ReplaceFileW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateHardLink CreateHardLinkW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateNamedPipe CreateNamedPipeW
#ವ್ಯಾಖ್ಯಾನಿಸು GetNamedPipeHandleState GetNamedPipeHandleStateW
#ವ್ಯಾಖ್ಯಾನಿಸು CallNamedPipe CallNamedPipeW
#ವ್ಯಾಖ್ಯಾನಿಸು WaitNamedPipe WaitNamedPipeW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Volume_Label ಗಣ_Volume_Label_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetVolumeInformation GetVolumeInformationW
#ವ್ಯಾಖ್ಯಾನಿಸು ClearEventLog ClearEventLogW
#ವ್ಯಾಖ್ಯಾನಿಸು BackupEventLog BackupEventLogW
#ವ್ಯಾಖ್ಯಾನಿಸು OpenEventLog OpenEventLogW
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Event_ಮೂಲ ರಿಜಿಸ್ಟರ್_Event_ಮೂಲ_W
#ವ್ಯಾಖ್ಯಾನಿಸು OpenBackupEventLog OpenBackupEventLogW
#ವ್ಯಾಖ್ಯಾನಿಸು ReadEventLog ReadEventLogW
#ವ್ಯಾಖ್ಯಾನಿಸು ReportEvent ReportEventW
#ವ್ಯಾಖ್ಯಾನಿಸು AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#ವ್ಯಾಖ್ಯಾನಿಸು AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#ವ್ಯಾಖ್ಯಾನಿಸು Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_W
#ವ್ಯಾಖ್ಯಾನಿಸು Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_By_Handle_W
#ವ್ಯಾಖ್ಯಾನಿಸು ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#ವ್ಯಾಖ್ಯಾನಿಸು ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#ವ್ಯಾಖ್ಯಾನಿಸು ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#ವ್ಯಾಖ್ಯಾನಿಸು ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#ವ್ಯಾಖ್ಯಾನಿಸು PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_File_Security ಗಣ_File_Security_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetFileSecurity GetFileSecurityW
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_Change_Notification ಕಂಡುಹಿಡಿ_ಮೊದಲ_Change_Notification_W
#ವ್ಯಾಖ್ಯಾನಿಸು IsBadStringPtr IsBadStringPtrW
#ವ್ಯಾಖ್ಯಾನಿಸು LookupAccountSid LookupAccountSidW
#ವ್ಯಾಖ್ಯಾನಿಸು LookupAccountName LookupAccountNameW
#ವ್ಯಾಖ್ಯಾನಿಸು Lookup_Privilege_ಮೌಲ್ಯ Lookup_Privilege_ಮೌಲ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು LookupPrivilegeName LookupPrivilegeNameW
#ವ್ಯಾಖ್ಯಾನಿಸು LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#ವ್ಯಾಖ್ಯಾನಿಸು BuildCommDCB BuildCommDCBW
#ವ್ಯಾಖ್ಯಾನಿಸು BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#ವ್ಯಾಖ್ಯಾನಿಸು CommConfigDialog CommConfigDialogW
#ವ್ಯಾಖ್ಯಾನಿಸು GetDefaultCommConfig GetDefaultCommConfigW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Default_Comm_Config ಗಣ_Default_Comm_Config_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetComputerName GetComputerNameW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Computer_Name ಗಣ_Computer_Name_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetComputerNameEx GetComputerNameExW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Computer_Name_Ex ಗಣ_Computer_Name_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Dns_Hostname_ಗಮ್ಯ_Computer_Name Dns_Hostname_ಗಮ್ಯ_Computer_Name_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetUserName GetUserNameW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_Ex ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_File ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_File ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_File_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಹುಡುಕು_ಮಾರ್ಗ ಹುಡುಕು_ಮಾರ್ಗ_A
#ವ್ಯಾಖ್ಯಾನಿಸು CopyFile CopyFileA
#ವ್ಯಾಖ್ಯಾನಿಸು CopyFileEx CopyFileExA
#ವ್ಯಾಖ್ಯಾನಿಸು MoveFile MoveFileA
#ವ್ಯಾಖ್ಯಾನಿಸು MoveFileEx MoveFileExA
#ವ್ಯಾಖ್ಯಾನಿಸು Move_File_With_ಪ್ರಗತಿ Move_File_With_ಪ್ರಗತಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು ReplaceFile ReplaceFileA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateHardLink CreateHardLinkA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateNamedPipe CreateNamedPipeA
#ವ್ಯಾಖ್ಯಾನಿಸು GetNamedPipeHandleState GetNamedPipeHandleStateA
#ವ್ಯಾಖ್ಯಾನಿಸು CallNamedPipe CallNamedPipeA
#ವ್ಯಾಖ್ಯಾನಿಸು WaitNamedPipe WaitNamedPipeA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Volume_Label ಗಣ_Volume_Label_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetVolumeInformation GetVolumeInformationA
#ವ್ಯಾಖ್ಯಾನಿಸು ClearEventLog ClearEventLogA
#ವ್ಯಾಖ್ಯಾನಿಸು BackupEventLog BackupEventLogA
#ವ್ಯಾಖ್ಯಾನಿಸು OpenEventLog OpenEventLogA
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Event_ಮೂಲ ರಿಜಿಸ್ಟರ್_Event_ಮೂಲ_A
#ವ್ಯಾಖ್ಯಾನಿಸು OpenBackupEventLog OpenBackupEventLogA
#ವ್ಯಾಖ್ಯಾನಿಸು ReadEventLog ReadEventLogA
#ವ್ಯಾಖ್ಯಾನಿಸು ReportEvent ReportEventA
#ವ್ಯಾಖ್ಯಾನಿಸು AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#ವ್ಯಾಖ್ಯಾನಿಸು AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#ವ್ಯಾಖ್ಯಾನಿಸು Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_A
#ವ್ಯಾಖ್ಯಾನಿಸು Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_By_Handle_A
#ವ್ಯಾಖ್ಯಾನಿಸು ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#ವ್ಯಾಖ್ಯಾನಿಸು ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#ವ್ಯಾಖ್ಯಾನಿಸು ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#ವ್ಯಾಖ್ಯಾನಿಸು ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#ವ್ಯಾಖ್ಯಾನಿಸು PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_File_Security ಗಣ_File_Security_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetFileSecurity GetFileSecurityA
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_Change_Notification ಕಂಡುಹಿಡಿ_ಮೊದಲ_Change_Notification_A
#ವ್ಯಾಖ್ಯಾನಿಸು IsBadStringPtr IsBadStringPtrA
#ವ್ಯಾಖ್ಯಾನಿಸು LookupAccountSid LookupAccountSidA
#ವ್ಯಾಖ್ಯಾನಿಸು LookupAccountName LookupAccountNameA
#ವ್ಯಾಖ್ಯಾನಿಸು Lookup_Privilege_ಮೌಲ್ಯ Lookup_Privilege_ಮೌಲ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು LookupPrivilegeName LookupPrivilegeNameA
#ವ್ಯಾಖ್ಯಾನಿಸು LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#ವ್ಯಾಖ್ಯಾನಿಸು BuildCommDCB BuildCommDCBA
#ವ್ಯಾಖ್ಯಾನಿಸು BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#ವ್ಯಾಖ್ಯಾನಿಸು CommConfigDialog CommConfigDialogA
#ವ್ಯಾಖ್ಯಾನಿಸು GetDefaultCommConfig GetDefaultCommConfigA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Default_Comm_Config ಗಣ_Default_Comm_Config_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetComputerName GetComputerNameA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Computer_Name ಗಣ_Computer_Name_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetComputerNameEx GetComputerNameExA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Computer_Name_Ex ಗಣ_Computer_Name_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Dns_Hostname_ಗಮ್ಯ_Computer_Name Dns_Hostname_ಗಮ್ಯ_Computer_Name_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetUserName GetUserNameA
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_Ex_A(LPCSTR lpFileName,FINDEX_INFO_ಮಟ್ಟಗಳು_2 fInfoLevelId,LPVOID lp_ಕಂಡುಹಿಡಿ_File_ದತ್ತಾಂಶ,FINDEX_ಹುಡುಕು_OPS_2 f_ಹುಡುಕು_Op,LPVOID lp_ಹುಡುಕು_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_Ex_W(LPCWSTR lpFileName,FINDEX_INFO_ಮಟ್ಟಗಳು_2 fInfoLevelId,LPVOID lp_ಕಂಡುಹಿಡಿ_File_ದತ್ತಾಂಶ,FINDEX_ಹುಡುಕು_OPS_2 f_ಹುಡುಕು_Op,LPVOID lp_ಹುಡುಕು_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_A(LPCSTR lpFileName,LPWIN32_ಕಂಡುಹಿಡಿ_DATAA lp_ಕಂಡುಹಿಡಿ_File_ದತ್ತಾಂಶ);
  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_File_W(LPCWSTR lpFileName,LPWIN32_ಕಂಡುಹಿಡಿ_DATAW lp_ಕಂಡುಹಿಡಿ_File_ದತ್ತಾಂಶ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_File_A(HANDLE h_ಕಂಡುಹಿಡಿ_File,LPWIN32_ಕಂಡುಹಿಡಿ_DATAA lp_ಕಂಡುಹಿಡಿ_File_ದತ್ತಾಂಶ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_File_W(HANDLE h_ಕಂಡುಹಿಡಿ_File,LPWIN32_ಕಂಡುಹಿಡಿ_DATAW lp_ಕಂಡುಹಿಡಿ_File_ದತ್ತಾಂಶ);
  WINBASEAPI DWORD WINAPI ಹುಡುಕು_ಮಾರ್ಗ_A(LPCSTR lp_ಮಾರ್ಗ,LPCSTR lpFileName,LPCSTR lpExtension,DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPSTR lp_ಬಫರ್,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI ಹುಡುಕು_ಮಾರ್ಗ_W(LPCWSTR lp_ಮಾರ್ಗ,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,LPWSTR lp_ಬಫರ್,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER ಒಟ್ಟು_File_ಗಾತ್ರ,LARGE_INTEGER ಒಟ್ಟು_ಬೈಟುಗಳು_Transferred,LARGE_INTEGER ಹರಿವು_ಗಾತ್ರ,LARGE_INTEGER ಹರಿವು_ಬೈಟುಗಳು_Transferred,DWORD dw_ಹರಿವು_ಸಂಖ್ಯೆ,DWORD dwCallbackReason,HANDLE h_ಮೂಲ_File,HANDLE hDestinationFile,LPVOID lp_ದತ್ತಾಂಶ);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ಪ್ರಗತಿ_Routine,LPVOID lp_ದತ್ತಾಂಶ,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ಪ್ರಗತಿ_Routine,LPVOID lp_ದತ್ತಾಂಶ,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_ಪ್ರಗತಿ_A(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ಪ್ರಗತಿ_Routine,LPVOID lp_ದತ್ತಾಂಶ,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_ಪ್ರಗತಿ_W(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ಪ್ರಗತಿ_Routine,LPVOID lp_ದತ್ತಾಂಶ,DWORD dwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು MOVEFILE_REPLACE_EXISTING 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು MOVEFILE_COPY_ALLOWED 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು MOVEFILE_WRITE_THROUGH 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು MOVEFILE_CREATE_HARDLINK 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ ಹರಿವು_INFO_ಮಟ್ಟಗಳು {
    ಕಂಡುಹಿಡಿ_ಹರಿವು_Info_Standard,ಕಂಡುಹಿಡಿ_ಹರಿವು_Info_Max_Info_Level
  } ಹರಿವು_INFO_ಮಟ್ಟಗಳು_2;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ WIN32_ಕಂಡುಹಿಡಿ_ಹರಿವು_ದತ್ತಾಂಶ {
    LARGE_INTEGER ಹರಿವು_ಗಾತ್ರ;
    WCHAR c_ಹರಿವು_Name[MAX_ಮಾರ್ಗ + 36];
  } WIN32_ಕಂಡುಹಿಡಿ_ಹರಿವು_ದತ್ತಾಂಶ_2,*PWIN32_ಕಂಡುಹಿಡಿ_ಹರಿವು_ದತ್ತಾಂಶ;

  HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_ಹರಿವು_W(LPCWSTR lpFileName,ಹರಿವು_INFO_ಮಟ್ಟಗಳು_2 InfoLevel,LPVOID lp_ಕಂಡುಹಿಡಿ_ಹರಿವು_ದತ್ತಾಂಶ,DWORD dwFlags);
  WINBOOL WINAPI ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_ಹರಿವು_W(HANDLE h_ಕಂಡುಹಿಡಿ_ಹರಿವು,LPVOID lp_ಕಂಡುಹಿಡಿ_ಹರಿವು_ದತ್ತಾಂಶ);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dw_Open_ಬಹುಲಕ,DWORD dw_Pipe_ಬಹುಲಕ,DWORD nMaxInstances,DWORD n_ಹೊರಹೋಗು_ಬಫರ್_ಗಾತ್ರ,DWORD n_ಒಳ_ಬಫರ್_ಗಾತ್ರ,DWORD n_Default_ಸಮಯ_ಹೊರಹೋಗು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dw_Open_ಬಹುಲಕ,DWORD dw_Pipe_ಬಹುಲಕ,DWORD nMaxInstances,DWORD n_ಹೊರಹೋಗು_ಬಫರ್_ಗಾತ್ರ,DWORD n_ಒಳ_ಬಫರ್_ಗಾತ್ರ,DWORD n_Default_ಸಮಯ_ಹೊರಹೋಗು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Security_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_ಎಣಿಕೆ,LPDWORD lp_Collect_ದತ್ತಾಂಶ_Timeout,LPSTR lpUserName,DWORD n_Max_User_Name_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_ಎಣಿಕೆ,LPDWORD lp_Collect_ದತ್ತಾಂಶ_Timeout,LPWSTR lpUserName,DWORD n_Max_User_Name_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lp_ಒಳ_ಬಫರ್,DWORD n_ಒಳ_ಬಫರ್_ಗಾತ್ರ,LPVOID lp_ಹೊರಹೋಗು_ಬಫರ್,DWORD n_ಹೊರಹೋಗು_ಬಫರ್_ಗಾತ್ರ,LPDWORD lp_ಬೈಟುಗಳು_Read,DWORD n_ಸಮಯ_ಹೊರಹೋಗು);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lp_ಒಳ_ಬಫರ್,DWORD n_ಒಳ_ಬಫರ್_ಗಾತ್ರ,LPVOID lp_ಹೊರಹೋಗು_ಬಫರ್,DWORD n_ಹೊರಹೋಗು_ಬಫರ್_ಗಾತ್ರ,LPDWORD lp_ಬೈಟುಗಳು_Read,DWORD n_ಸಮಯ_ಹೊರಹೋಗು);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD n_ಸಮಯ_ಹೊರಹೋಗು);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD n_ಸಮಯ_ಹೊರಹೋಗು);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Volume_Label_A(LPCSTR lp_ಬೇರು_ಮಾರ್ಗ_Name,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Volume_Label_W(LPCWSTR lp_ಬೇರು_ಮಾರ್ಗ_Name,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI ಗಣ_File_Apis_ಗಮ್ಯ_OEM(VOID);
  WINBASEAPI VOID WINAPI ಗಣ_File_Apis_ಗಮ್ಯ_ANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lp_ಬೇರು_ಮಾರ್ಗ_Name,LPSTR lp_Volume_Name_ಬಫರ್,DWORD n_Volume_Name_ಗಾತ್ರ,LPDWORD lp_Volume_Serial_ಸಂಖ್ಯೆ,LPDWORD lp_ಗರಿಷ್ಠ_Component_ಉದ್ದಳತೆ,LPDWORD lpFileSystemFlags,LPSTR lp_File_System_Name_ಬಫರ್,DWORD n_File_System_Name_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lp_ಬೇರು_ಮಾರ್ಗ_Name,LPWSTR lp_Volume_Name_ಬಫರ್,DWORD n_Volume_Name_ಗಾತ್ರ,LPDWORD lp_Volume_Serial_ಸಂಖ್ಯೆ,LPDWORD lp_ಗರಿಷ್ಠ_Component_ಉದ್ದಳತೆ,LPDWORD lpFileSystemFlags,LPWSTR lp_File_System_Name_ಬಫರ್,DWORD n_File_System_Name_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI Deregister_Event_ಮೂಲ(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI Get_ಸಂಖ್ಯೆ_ದ_Event_Log_ದಾಖಲೆಗಳು(HANDLE hEventLog,PDWORD ಸಂಖ್ಯೆ_ದ_ದಾಖಲೆಗಳು);
  WINADVAPI WINBOOL WINAPI Get_Oldest_Event_Log_ದಾಖಲೆ(HANDLE hEventLog,PDWORD Oldest_ದಾಖಲೆ);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lp_ಮೂಲ_Name);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lp_ಮೂಲ_Name);
  WINADVAPI HANDLE WINAPI ರಿಜಿಸ್ಟರ್_Event_ಮೂಲ_A(LPCSTR lpUNCServerName,LPCSTR lp_ಮೂಲ_Name);
  WINADVAPI HANDLE WINAPI ರಿಜಿಸ್ಟರ್_Event_ಮೂಲ_W(LPCWSTR lpUNCServerName,LPCWSTR lp_ಮೂಲ_Name);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_ದಾಖಲೆ_ಸ್ಥಾನಾಂತರ,LPVOID lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Read,DWORD *pn_ಬೈಟುಗಳು_Read,DWORD *pn_Min_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Needed);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_ದಾಖಲೆ_ಸ್ಥಾನಾಂತರ,LPVOID lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Read,DWORD *pn_ಬೈಟುಗಳು_Read,DWORD *pn_Min_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_Needed);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,ಶಬ್ದ_3 wType,ಶಬ್ದ_3 wCategory,DWORD dwEventID,PSID lpUserSid,ಶಬ್ದ_3 w_ಅಂಕೆ_ಅಕ್ಷರಸರಣಿಗಳು,DWORD dw_ದತ್ತಾಂಶ_ಗಾತ್ರ,LPCSTR *lp_ಅಕ್ಷರಸರಣಿಗಳು,LPVOID lp_Raw_ದತ್ತಾಂಶ);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,ಶಬ್ದ_3 wType,ಶಬ್ದ_3 wCategory,DWORD dwEventID,PSID lpUserSid,ಶಬ್ದ_3 w_ಅಂಕೆ_ಅಕ್ಷರಸರಣಿಗಳು,DWORD dw_ದತ್ತಾಂಶ_ಗಾತ್ರ,LPCWSTR *lp_ಅಕ್ಷರಸರಣಿಗಳು,LPVOID lp_Raw_ದತ್ತಾಂಶ);

#ವ್ಯಾಖ್ಯಾನಿಸು EVENTLOG_ತುಂಬಿದ_INFO 0

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ EVENTLOG_ತುಂಬಿದ_INFORMATION {
    DWORD dw_ತುಂಬಿದ;
  } EVENTLOG_ತುಂಬಿದ_INFORMATION_2,*LPEVENTLOG_ತುಂಬಿದ_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lp_ಬಫರ್,DWORD cb_Buf_ಗಾತ್ರ,LPDWORD pcb_ಬೈಟುಗಳು_Needed);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_ಉದ್ದಳತೆ,LPDWORD lpn_ಉದ್ದಳತೆ_Needed);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI Revert_ಗಮ್ಯ_Self(VOID);
  WINADVAPI WINBOOL WINAPI ಗಣ_Thread_Token (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_ಗಣ Privilege_ಗಣ,LPDWORD Privilege_ಗಣ_ಉದ್ದಳತೆ,LPDWORD GrantedAccess,LPBOOL Access_ಸ್ಥಿತಿ);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ಉದ್ದಳತೆ,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_ಗಣ Privilege_ಗಣ,LPDWORD Privilege_ಗಣ_ಉದ್ದಳತೆ,LPDWORD GrantedAccess,LPBOOL Access_ಸ್ಥಿತಿ);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ಫಲಿತಾಂಶ_List(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ಉದ್ದಳತೆ,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_ಗಣ Privilege_ಗಣ,LPDWORD Privilege_ಗಣ_ಉದ್ದಳತೆ,LPDWORD GrantedAccessList,LPDWORD Access_ಸ್ಥಿತಿ_List);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_ಉದ್ದಳತೆ,PDWORD Return_ಉದ್ದಳತೆ);
  WINADVAPI WINBOOL WINAPI ಗಣ_Token_Information(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_ಉದ್ದಳತೆ);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD ಬಫರ್_ಉದ್ದಳತೆ,PTOKEN_PRIVILEGES ಹಿಂದಿನ_State,PDWORD Return_ಉದ್ದಳತೆ);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL Reset_ಗಮ್ಯ_Default,PTOKEN_GROUPS NewState,DWORD ಬಫರ್_ಉದ್ದಳತೆ,PTOKEN_GROUPS ಹಿಂದಿನ_State,PDWORD Return_ಉದ್ದಳತೆ);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_ಗಣ RequiredPrivileges,LPBOOL pf_ಫಲಿತಾಂಶ);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_ಸ್ಥಿತಿ,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_ಸ್ಥಿತಿ,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ಉದ್ದಳತೆ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_ಸ್ಥಿತಿ,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ಉದ್ದಳತೆ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_ಸ್ಥಿತಿ,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_A(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ಉದ್ದಳತೆ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_ಸ್ಥಿತಿ_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_W(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ಉದ್ದಳತೆ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_ಸ್ಥಿತಿ_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_By_Handle_A(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ಉದ್ದಳತೆ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_ಸ್ಥಿತಿ_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ಫಲಿತಾಂಶ_List_And_Audit_Alarm_By_Handle_W(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ಉದ್ದಳತೆ,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_ಸ್ಥಿತಿ_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_ಗಣ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_ಗಣ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_ಗಣ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_ಗಣ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_ಗಣ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_ಗಣ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI Is_Well_ತಿಳಿದ_Sid(PSID pSid,WELL_ತಿಳಿದ_SID_TYPE Well_ತಿಳಿದ_Sid_Type);
  WINADVAPI WINBOOL WINAPI Create_Well_ತಿಳಿದ_Sid(WELL_ತಿಳಿದ_SID_TYPE Well_ತಿಳಿದ_Sid_Type,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI Equal_ಪೂರ್ವಪ್ರತ್ಯಯ_Sid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI Get_Sid_ಉದ್ದಳತೆ_Required (UCHAR n_Sub_Authority_ಎಣಿಕೆ);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_ಎಣಿಕೆ,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_ಎಣಿಕೆ);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI Get_Sid_Sub_Authority_ಎಣಿಕೆ(PSID pSid);
  WINADVAPI DWORD WINAPI Get_ಉದ್ದಳತೆ_Sid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD n_Destination_Sid_ಉದ್ದಳತೆ,PSID pDestinationSid,PSID p_ಮೂಲ_Sid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI Map_Generic_ಮುಖವಾಡ(PDWORD Access_ಮುಖವಾಡ,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD n_Acl_ಉದ್ದಳತೆ,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_ಉದ್ದಳತೆ,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI ಗಣ_Acl_Information(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_ಉದ್ದಳತೆ,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Starting_Ace_ಸೂಚ್ಯಂಕ,LPVOID pAceList,DWORD n_Ace_List_ಉದ್ದಳತೆ);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dw_Ace_ಸೂಚ್ಯಂಕ);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dw_Ace_ಸೂಚ್ಯಂಕ,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Access_Allowed_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ಮುಖವಾಡ,PSID pSid);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Access_Allowed_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ಮುಖವಾಡ,PSID pSid);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Access_Denied_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ಮುಖವಾಡ,PSID pSid);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Access_Denied_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ಮುಖವಾಡ,PSID pSid);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Audit_Access_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Access_ಮುಖವಾಡ,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Audit_Access_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dw_Access_ಮುಖವಾಡ,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Access_Allowed_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ಮುಖವಾಡ,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Access_Denied_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ಮುಖವಾಡ,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI ಕೂಡಿಸು_Audit_Access_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ಮುಖವಾಡ,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_Free_Ace(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI Get_Security_Descriptor_ಉದ್ದಳತೆ(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI ಗಣ_Security_Descriptor_Control(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL Control_ಬಿಟ್ಟುಗಳು_ದ_Interest,SECURITY_DESCRIPTOR_CONTROL Control_ಬಿಟ್ಟುಗಳು_ಗಮ್ಯ_ಗಣ);
  WINADVAPI WINBOOL WINAPI ಗಣ_Security_Descriptor_Dacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI ಗಣ_Security_Descriptor_Sacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI ಗಣ_Security_Descriptor_Owner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI ಗಣ_Security_Descriptor_ಗುಂಪು(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID p_ಗುಂಪು,WINBOOL b_ಗುಂಪು_Defaulted);
  WINADVAPI WINBOOL WINAPI Get_Security_Descriptor_ಗುಂಪು(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *p_ಗುಂಪು,LPBOOL lpb_ಗುಂಪು_Defaulted);
  WINADVAPI DWORD WINAPI ಗಣ_Security_Descriptor_RMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI Create_ಖಾಸಗಿ_Object_Security(PSECURITY_DESCRIPTOR ಪೋಷಕ_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Convert_ಗಮ್ಯ_Auto_Inherit_ಖಾಸಗಿ_Object_Security(PSECURITY_DESCRIPTOR ಪೋಷಕ_Descriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_ಖಾಸಗಿ_Object_Security_Ex(PSECURITY_DESCRIPTOR ಪೋಷಕ_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_ಖಾಸಗಿ_Object_Security_With_ಅಪವರ್ತ್ಯ_Inheritance(PSECURITY_DESCRIPTOR ಪೋಷಕ_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG Guid_ಎಣಿಕೆ,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI ಗಣ_ಖಾಸಗಿ_Object_Security (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI ಗಣ_ಖಾಸಗಿ_Object_Security_Ex (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI Get_ಖಾಸಗಿ_Object_Security(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD Descriptor_ಉದ್ದಳತೆ,PDWORD Return_ಉದ್ದಳತೆ);
  WINADVAPI WINBOOL WINAPI Destroy_ಖಾಸಗಿ_Object_Security(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_ಬಫರ್_ಉದ್ದಳತೆ);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdw_Absolute_Security_Descriptor_ಗಾತ್ರ,PACL pDacl,LPDWORD lpdw_Dacl_ಗಾತ್ರ,PACL pSacl,LPDWORD lpdw_Sacl_ಗಾತ್ರ,PSID pOwner,LPDWORD lpdw_Owner_ಗಾತ್ರ,PSID p_Primary_ಗುಂಪು,LPDWORD lpdw_Primary_ಗುಂಪು_ಗಾತ್ರ);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_ಬಫರ್_ಗಾತ್ರ);
  WINADVAPI WINBOOL WINAPI ಗಣ_File_Security_A(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI ಗಣ_File_Security_W(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_ಉದ್ದಳತೆ,LPDWORD lpn_ಉದ್ದಳತೆ_Needed);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_ಉದ್ದಳತೆ,LPDWORD lpn_ಉದ್ದಳತೆ_Needed);
  WINADVAPI WINBOOL WINAPI ಗಣ_Kernel_Object_Security(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_Change_Notification_A(LPCSTR lp_ಮಾರ್ಗ_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_Change_Notification_W(LPCWSTR lp_ಮಾರ್ಗ_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_Close_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lp_ಬಫರ್,DWORD n_ಬಫರ್_ಉದ್ದಳತೆ,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lp_ಬೈಟುಗಳು_Returned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI Virtual_ಬೀಗ(LPVOID lp_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lp_ವಿಳಾಸ,ಗಾತ್ರ_T dw_ಗಾತ್ರ);
  WINBASEAPI LPVOID WINAPI Map_View_ದ_File_Ex(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_ಸ್ಥಾನಾಂತರ_ಮೇಲಿನ,DWORD dw_File_ಸ್ಥಾನಾಂತರ_ಕೆಳಗಿನ,ಗಾತ್ರ_T dw_ಸಂಖ್ಯೆ_ದ_ಬೈಟುಗಳು_ಗಮ್ಯ_Map,LPVOID lp_ತಳ_ವಿಳಾಸ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_ಆದ್ಯತೆ_Class(HANDLE hProcess,DWORD dw_ಆದ್ಯತೆ_Class);
  WINBASEAPI DWORD WINAPI Get_ಆದ್ಯತೆ_Class(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI Is_Bad_ಸಂಕೇತ_Ptr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_ಮೌಲ್ಯ_A(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_ಮೌಲ್ಯ_W(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
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
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Default_Comm_Config_A(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Default_Comm_Config_W(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_ಗಾತ್ರ);

#ವ್ಯಾಖ್ಯಾನಿಸು MAX_COMPUTERNAME_ಉದ್ದಳತೆ 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lp_ಬಫರ್,LPDWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lp_ಬಫರ್,LPDWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Computer_Name_A(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Computer_Name_W(LPCWSTR lpComputerName);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಎಣಿಕೆ _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lp_ಬಫರ್,LPDWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lp_ಬಫರ್,LPDWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Computer_Name_Ex_A(COMPUTER_NAME_FORMAT NameType,LPCSTR lp_ಬಫರ್);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Computer_Name_Ex_W(COMPUTER_NAME_FORMAT NameType,LPCWSTR lp_ಬಫರ್);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_ಗಮ್ಯ_Computer_Name_A(LPCSTR Hostname,LPSTR ComputerName,LPDWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_ಗಮ್ಯ_Computer_Name_W(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD n_ಗಾತ್ರ);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lp_ಬಫರ್,LPDWORD pcb_ಬಫರ್);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lp_ಬಫರ್,LPDWORD pcb_ಬಫರ್);

#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_LOGON_INTERACTIVE 2
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_LOGON_ಜಾಲ 3
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_LOGON_BATCH 4
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_LOGON_SERVICE 5
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_LOGON_UNLOCK 7
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_LOGON_ಜಾಲ_CLEARTEXT 8
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_LOGON_NEW_CREDENTIALS 9

#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_PROVIDER_DEFAULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_PROVIDER_WINNT35 1
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_PROVIDER_WINNT40 2
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON32_PROVIDER_WINNT50 3

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು LogonUser LogonUserW
#ವ್ಯಾಖ್ಯಾನಿಸು LogonUserEx LogonUserExW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateProcessAsUser CreateProcessAsUserW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು LogonUser LogonUserA
#ವ್ಯಾಖ್ಯಾನಿಸು LogonUserEx LogonUserExA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateProcessAsUser CreateProcessAsUserA
#ಆದರೆ_ಅಂತ್ಯ

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_ಬಫರ್,LPDWORD pdw_Profile_ಉದ್ದಳತೆ,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_ಬಫರ್,LPDWORD pdw_Profile_ಉದ್ದಳತೆ,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lp_Command_ಸಾಲು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Process_ಗುಣಲಕ್ಷಣಗಳು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Thread_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lp_Command_ಸಾಲು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Process_ಗುಣಲಕ್ಷಣಗಳು,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Thread_ಗುಣಲಕ್ಷಣಗಳು,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#ವ್ಯಾಖ್ಯಾನಿಸು LOGON_WITH_PROFILE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON_NETCREDENTIALS_ONLY 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು LOGON_ZERO_PASSWORD_ಬಫರ್ 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_ಸಾಲು,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_ಸಾಲು,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_Token_ಗುಣಲಕ್ಷಣಗಳು,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD Disable_Sid_ಎಣಿಕೆ,PSID_AND_ಗುಣಲಕ್ಷಣಗಳು Sids_ಗಮ್ಯ_Disable,DWORD Delete_Privilege_ಎಣಿಕೆ,PLUID_AND_ಗುಣಲಕ್ಷಣಗಳು Privileges_ಗಮ್ಯ_Delete,DWORD Restricted_Sid_ಎಣಿಕೆ,PSID_AND_ಗುಣಲಕ್ಷಣಗಳು Sids_ಗಮ್ಯ_Restrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID Sid_ಗಮ್ಯ_Check,PBOOL IsMember);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI ರಿಜಿಸ್ಟರ್_Wait_For_Single_Object(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI ರಿಜಿಸ್ಟರ್_Wait_For_Single_Object_Ex(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI ಸರತಿ_User_Work_ಅಂಶ(LPTHREAD_ಆರಂಭ_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI Create_Timer_ಸರತಿ(VOID);
  WINBASEAPI WINBOOL WINAPI Create_Timer_ಸರತಿ_Timer(PHANDLE phNewTimer,HANDLE Timer_ಸರತಿ,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_ಸಮಯ,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI Change_Timer_ಸರತಿ_Timer(HANDLE Timer_ಸರತಿ,HANDLE Timer,ULONG Due_ಸಮಯ,ULONG Period);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_ಸರತಿ_Timer(HANDLE Timer_ಸರತಿ,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_ಸರತಿ_Ex(HANDLE Timer_ಸರತಿ,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI ಗಣ_Timer_ಸರತಿ_Timer(HANDLE Timer_ಸರತಿ,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_ಸಮಯ,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI Cancel_Timer_ಸರತಿ_Timer(HANDLE Timer_ಸರತಿ,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_ಸರತಿ(HANDLE Timer_ಸರತಿ);

#ವ್ಯಾಖ್ಯಾನಿಸು HW_PROFILE_GUIDLEN 39
#ವ್ಯಾಖ್ಯಾನಿಸು MAX_PROFILE_LEN 80

#ವ್ಯಾಖ್ಯಾನಿಸು DOCKINFO_UNDOCKED (0x1)
#ವ್ಯಾಖ್ಯಾನಿಸು DOCKINFO_DOCKED (0x2)
#ವ್ಯಾಖ್ಯಾನಿಸು DOCKINFO_USER_SUPPLIED (0x4)
#ವ್ಯಾಖ್ಯಾನಿಸು DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#ವ್ಯಾಖ್ಯಾನಿಸು DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HW_PROFILE_INFOW HW_PROFILE_INFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HW_PROFILE_INFOA HW_PROFILE_INFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetCurrentHwProfile GetCurrentHwProfileW
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಆವೃತ್ತಿ_Ex Get_ಆವೃತ್ತಿ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Verify_ಆವೃತ್ತಿ_Info Verify_ಆವೃತ್ತಿ_Info_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetCurrentHwProfile GetCurrentHwProfileA
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಆವೃತ್ತಿ_Ex Get_ಆವೃತ್ತಿ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Verify_ಆವೃತ್ತಿ_Info Verify_ಆವೃತ್ತಿ_Info_A
#ಆದರೆ_ಅಂತ್ಯ

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lp_Performance_ಎಣಿಕೆ);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI Get_ಆವೃತ್ತಿ_Ex_A(LPOSVERSIONINFOA lp_ಆವೃತ್ತಿ_Information);
  WINBASEAPI WINBOOL WINAPI Get_ಆವೃತ್ತಿ_Ex_W(LPOSVERSIONINFOW lp_ಆವೃತ್ತಿ_Information);
  WINBASEAPI WINBOOL WINAPI Verify_ಆವೃತ್ತಿ_Info_A(LPOSVERSIONINFOEXA lp_ಆವೃತ್ತಿ_Information,DWORD dw_Type_ಮುಖವಾಡ,DWORDLONG dwl_Condition_ಮುಖವಾಡ);
  WINBASEAPI WINBOOL WINAPI Verify_ಆವೃತ್ತಿ_Info_W(LPOSVERSIONINFOEXW lp_ಆವೃತ್ತಿ_Information,DWORD dw_Type_ಮುಖವಾಡ,DWORDLONG dwl_Condition_ಮುಖವಾಡ);

#ಅನ್ತರ್ಭಾವ <winerror.h>

#ವ್ಯಾಖ್ಯಾನಿಸು TC_ಸಾಮಾನ್ಯ 0
#ವ್ಯಾಖ್ಯಾನಿಸು TC_HARDERR 1
#ವ್ಯಾಖ್ಯಾನಿಸು TC_GP_TRAP 2
#ವ್ಯಾಖ್ಯಾನಿಸು TC_SIGNAL 3

#ವ್ಯಾಖ್ಯಾನಿಸು AC_ಸಾಲು_OFFLINE 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು AC_ಸಾಲು_ONLINE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು AC_ಸಾಲು_BACKUP_POWER 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು AC_ಸಾಲು_UNKNOWN 0xff

#ವ್ಯಾಖ್ಯಾನಿಸು BATTERY_FLAG_ಮೇಲಿನ 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು BATTERY_FLAG_ಕೆಳಗಿನ 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು BATTERY_FLAG_CRITICAL 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು BATTERY_FLAG_CHARGING 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು BATTERY_FLAG_NO_BATTERY 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು BATTERY_FLAG_UNKNOWN 0xff

#ವ್ಯಾಖ್ಯಾನಿಸು BATTERY_PERCENTAGE_UNKNOWN 0xff

#ವ್ಯಾಖ್ಯಾನಿಸು BATTERY_LIFE_UNKNOWN 0xffffffff

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ SYSTEM_POWER_ಸ್ಥಿತಿ {
    BYTE ACLine_ಸ್ಥಿತಿ;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD Battery_Life_ಸಮಯ;
    DWORD Battery_ತುಂಬಿದ_Life_ಸಮಯ;
  } SYSTEM_POWER_ಸ್ಥಿತಿ_2,*LPSYSTEM_POWER_ಸ್ಥಿತಿ;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕೆಲಸ_Object Create_ಕೆಲಸ_Object_W
#ವ್ಯಾಖ್ಯಾನಿಸು Open_ಕೆಲಸ_Object Open_ಕೆಲಸ_Object_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_Mount_ಬಿಂದು ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_Mount_ಬಿಂದು_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_Mount_ಬಿಂದು ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_Mount_ಬಿಂದು_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Volume_Mount_ಬಿಂದು ಗಣ_Volume_Mount_ಬಿಂದು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Delete_Volume_Mount_ಬಿಂದು Delete_Volume_Mount_ಬಿಂದು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Volume_Name_For_Volume_Mount_ಬಿಂದು Get_Volume_Name_For_Volume_Mount_ಬಿಂದು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Volume_ಮಾರ್ಗ_Name Get_Volume_ಮಾರ್ಗ_Name_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Volume_ಮಾರ್ಗ_ಹೆಸರುಗಳು_For_Volume_Name Get_Volume_ಮಾರ್ಗ_ಹೆಸರುಗಳು_For_Volume_Name_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕೆಲಸ_Object Create_ಕೆಲಸ_Object_A
#ವ್ಯಾಖ್ಯಾನಿಸು Open_ಕೆಲಸ_Object Open_ಕೆಲಸ_Object_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_Mount_ಬಿಂದು ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_Mount_ಬಿಂದು_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_Mount_ಬಿಂದು ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_Mount_ಬಿಂದು_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Volume_Mount_ಬಿಂದು ಗಣ_Volume_Mount_ಬಿಂದು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Delete_Volume_Mount_ಬಿಂದು Delete_Volume_Mount_ಬಿಂದು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Volume_Name_For_Volume_Mount_ಬಿಂದು Get_Volume_Name_For_Volume_Mount_ಬಿಂದು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Volume_ಮಾರ್ಗ_Name Get_Volume_ಮಾರ್ಗ_Name_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Volume_ಮಾರ್ಗ_ಹೆಸರುಗಳು_For_Volume_Name Get_Volume_ಮಾರ್ಗ_ಹೆಸರುಗಳು_For_Volume_Name_A
#ಆದರೆ_ಅಂತ್ಯ

  WINBOOL WINAPI Get_System_Power_ಸ್ಥಿತಿ(LPSYSTEM_POWER_ಸ್ಥಿತಿ lp_System_Power_ಸ್ಥಿತಿ);
  WINBOOL WINAPI ಗಣ_System_Power_State(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI Allocate_User_Physical_ಪುಟಗಳು(HANDLE hProcess,PULONG_PTR ಸಂಖ್ಯೆ_ದ_ಪುಟಗಳು,PULONG_PTR ಪುಟ_Array);
  WINBASEAPI WINBOOL WINAPI Free_User_Physical_ಪುಟಗಳು(HANDLE hProcess,PULONG_PTR ಸಂಖ್ಯೆ_ದ_ಪುಟಗಳು,PULONG_PTR ಪುಟ_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_ಪುಟಗಳು(PVOID Virtual_ವಿಳಾಸ,ULONG_PTR ಸಂಖ್ಯೆ_ದ_ಪುಟಗಳು,PULONG_PTR ಪುಟ_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_ಪುಟಗಳು_Scatter(PVOID *Virtual_ವಿಳಾಸಗಳು,ULONG_PTR ಸಂಖ್ಯೆ_ದ_ಪುಟಗಳು,PULONG_PTR ಪುಟ_Array);
  WINBASEAPI HANDLE WINAPI Create_ಕೆಲಸ_Object_A(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_ಕೆಲಸ_ಗುಣಲಕ್ಷಣಗಳು,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Create_ಕೆಲಸ_Object_W(LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lp_ಕೆಲಸ_ಗುಣಲಕ್ಷಣಗಳು,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_ಕೆಲಸ_Object_A(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_ಕೆಲಸ_Object_W(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI ನಿಯೋಜಿಸು_Process_ಗಮ್ಯ_ಕೆಲಸ_Object(HANDLE h_ಕೆಲಸ,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI Terminate_ಕೆಲಸ_Object(HANDLE h_ಕೆಲಸ,UINT u_Exit_ಸಂಕೇತ);
  WINBASEAPI WINBOOL WINAPI Query_Information_ಕೆಲಸ_Object(HANDLE h_ಕೆಲಸ,JOBOBJECTINFOCLASS ಕೆಲಸ_Object_Information_Class,LPVOID lp_ಕೆಲಸ_Object_Information,DWORD cb_ಕೆಲಸ_Object_Information_ಉದ್ದಳತೆ,LPDWORD lp_Return_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Information_ಕೆಲಸ_Object(HANDLE h_ಕೆಲಸ,JOBOBJECTINFOCLASS ಕೆಲಸ_Object_Information_Class,LPVOID lp_ಕೆಲಸ_Object_Information,DWORD cb_ಕೆಲಸ_Object_Information_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI Is_Process_ಒಳ_ಕೆಲಸ(HANDLE ProcessHandle,HANDLE ಕೆಲಸ_Handle,PBOOL ಫಲಿತಾಂಶ_3);
  WINBASEAPI WINBOOL WINAPI Create_ಕೆಲಸ_ಗಣ(ULONG ಅಂಕೆ_ಕೆಲಸ,PJOB_ಗಣ_ARRAY User_ಕೆಲಸ_ಗಣ,ULONG Flags);
  WINBASEAPI PVOID WINAPI ಕೂಡಿಸು_Vectored_Exception_Handler (ULONG ಮೊದಲ_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI ಕೂಡಿಸು_Vectored_Continue_Handler (ULONG ಮೊದಲ_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_A(LPSTR lpszVolumeName,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_W(LPWSTR lpszVolumeName,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_A(HANDLE h_ಕಂಡುಹಿಡಿ_Volume,LPSTR lpszVolumeName,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_W(HANDLE h_ಕಂಡುಹಿಡಿ_Volume,LPWSTR lpszVolumeName,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_Volume_Close(HANDLE h_ಕಂಡುಹಿಡಿ_Volume);
  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_Mount_ಬಿಂದು_A(LPCSTR lpsz_ಬೇರು_ಮಾರ್ಗ_Name,LPSTR lpsz_Volume_Mount_ಬಿಂದು,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI HANDLE WINAPI ಕಂಡುಹಿಡಿ_ಮೊದಲ_Volume_Mount_ಬಿಂದು_W(LPCWSTR lpsz_ಬೇರು_ಮಾರ್ಗ_Name,LPWSTR lpsz_Volume_Mount_ಬಿಂದು,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_Mount_ಬಿಂದು_A(HANDLE h_ಕಂಡುಹಿಡಿ_Volume_Mount_ಬಿಂದು,LPSTR lpsz_Volume_Mount_ಬಿಂದು,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_ಮುಂದಿನ_Volume_Mount_ಬಿಂದು_W(HANDLE h_ಕಂಡುಹಿಡಿ_Volume_Mount_ಬಿಂದು,LPWSTR lpsz_Volume_Mount_ಬಿಂದು,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_Volume_Mount_ಬಿಂದು_Close(HANDLE h_ಕಂಡುಹಿಡಿ_Volume_Mount_ಬಿಂದು);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Volume_Mount_ಬಿಂದು_A(LPCSTR lpsz_Volume_Mount_ಬಿಂದು,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Volume_Mount_ಬಿಂದು_W(LPCWSTR lpsz_Volume_Mount_ಬಿಂದು,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_ಬಿಂದು_A(LPCSTR lpsz_Volume_Mount_ಬಿಂದು);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_ಬಿಂದು_W(LPCWSTR lpsz_Volume_Mount_ಬಿಂದು);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_ಬಿಂದು_A(LPCSTR lpsz_Volume_Mount_ಬಿಂದು,LPSTR lpszVolumeName,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_ಬಿಂದು_W(LPCWSTR lpsz_Volume_Mount_ಬಿಂದು,LPWSTR lpszVolumeName,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_ಮಾರ್ಗ_Name_A(LPCSTR lpszFileName,LPSTR lpsz_Volume_ಮಾರ್ಗ_Name,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_ಮಾರ್ಗ_Name_W(LPCWSTR lpszFileName,LPWSTR lpsz_Volume_ಮಾರ್ಗ_Name,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_ಮಾರ್ಗ_ಹೆಸರುಗಳು_For_Volume_Name_A(LPCSTR lpszVolumeName,LPCH lpsz_Volume_ಮಾರ್ಗ_ಹೆಸರುಗಳು,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ,PDWORD lpcch_Return_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_ಮಾರ್ಗ_ಹೆಸರುಗಳು_For_Volume_Name_W(LPCWSTR lpszVolumeName,LPWCH lpsz_Volume_ಮಾರ್ಗ_ಹೆಸರುಗಳು,DWORD cch_ಬಫರ್_ಉದ್ದಳತೆ,PDWORD lpcch_Return_ಉದ್ದಳತೆ);

#ವ್ಯಾಖ್ಯಾನಿಸು ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ACTCTX_FLAG_LANGID_VALID 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು ACTCTX_FLAG_ಗಣ_PROCESS_DEFAULT 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು ACTCTX_FLAG_ಮೂಲ_IS_ASSEMBLYREF 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು ACTCTX_FLAG_HMODULE_VALID 0x80

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ACTCTXA {
    ULONG cb_ಗಾತ್ರ;
    DWORD dwFlags;
    LPCSTR lp_ಮೂಲ;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ACTCTXW {
    ULONG cb_ಗಾತ್ರ;
    DWORD dwFlags;
    LPCWSTR lp_ಮೂಲ;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ACTCTXA *PCACTCTXA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ACTCTXW *PCACTCTXW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACTCTXW ACTCTX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PACTCTXW PACTCTX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PCACTCTXW PCACTCTX;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ACTCTXA ACTCTX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PACTCTXA PACTCTX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PCACTCTXA PCACTCTX;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು CreateActCtx CreateActCtxW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು CreateActCtx CreateActCtxA
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI ಕೂಡಿಸು_Ref_Act_Ctx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#ವ್ಯಾಖ್ಯಾನಿಸು DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_2600 {
    ULONG cb_ಗಾತ್ರ;
    ULONG ul_ದತ್ತಾಂಶ_Format_ಆವೃತ್ತಿ;
    PVOID lp_ದತ್ತಾಂಶ;
    ULONG ul_ಉದ್ದಳತೆ;
    PVOID lp_Section_Global_ದತ್ತಾಂಶ;
    ULONG ul_Section_Global_ದತ್ತಾಂಶ_ಉದ್ದಳತೆ;
    PVOID lp_Section_ತಳ;
    ULONG ul_Section_ಒಟ್ಟು_ಉದ್ದಳತೆ;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_ಸೂಚ್ಯಂಕ;
  } ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_2600,*PACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_2600;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_2600 *PCACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_2600;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lp_Section_ತಳ;
    ULONG ul_Section_ಉದ್ದಳತೆ;
    PVOID lp_Section_Global_ದತ್ತಾಂಶ_ತಳ;
    ULONG ul_Section_Global_ದತ್ತಾಂಶ_ಉದ್ದಳತೆ;
  } ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_ASSEMBLY_METADATA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_ASSEMBLY_METADATA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ {
    ULONG cb_ಗಾತ್ರ;
    ULONG ul_ದತ್ತಾಂಶ_Format_ಆವೃತ್ತಿ;
    PVOID lp_ದತ್ತಾಂಶ;
    ULONG ul_ಉದ್ದಳತೆ;
    PVOID lp_Section_Global_ದತ್ತಾಂಶ;
    ULONG ul_Section_Global_ದತ್ತಾಂಶ_ಉದ್ದಳತೆ;
    PVOID lp_Section_ತಳ;
    ULONG ul_Section_ಒಟ್ಟು_ಉದ್ದಳತೆ;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_ಸೂಚ್ಯಂಕ;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ,*PACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ *PCACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ;

#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ACTCTX_SECTION_ಕೀಲಿ_RETURN_HACTCTX 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ACTCTX_SECTION_ಕೀಲಿ_RETURN_FLAGS 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ACTCTX_SECTION_ಕೀಲಿ_RETURN_ASSEMBLY_METADATA 0x4

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Act_Ctx_Section_String ಕಂಡುಹಿಡಿ_Act_Ctx_Section_String_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_Act_Ctx_Section_String ಕಂಡುಹಿಡಿ_Act_Ctx_Section_String_A
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_Act_Ctx_Section_String_A(DWORD dwFlags,ಸ್ಥಿರಾಂಕ GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lp_String_ಗಮ್ಯ_ಕಂಡುಹಿಡಿ,PACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ Returned_ದತ್ತಾಂಶ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_Act_Ctx_Section_String_W(DWORD dwFlags,ಸ್ಥಿರಾಂಕ GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lp_String_ಗಮ್ಯ_ಕಂಡುಹಿಡಿ,PACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ Returned_ದತ್ತಾಂಶ);
  WINBASEAPI WINBOOL WINAPI ಕಂಡುಹಿಡಿ_Act_Ctx_Section_Guid(DWORD dwFlags,ಸ್ಥಿರಾಂಕ GUID *lpExtensionGuid,ULONG ulSectionId,ಸ್ಥಿರಾಂಕ GUID *lp_Guid_ಗಮ್ಯ_ಕಂಡುಹಿಡಿ,PACTCTX_SECTION_KEYED_ದತ್ತಾಂಶ Returned_ದತ್ತಾಂಶ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಸ್ಥಿರಾಂಕ ರಚನೆ _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#ವ್ಯಾಖ್ಯಾನಿಸು ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು QUERY_ACTCTX_FLAG_USE_ಸಕ್ರಿಯ_ACTCTX 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು QUERY_ACTCTX_FLAG_ACTCTX_IS_ವಿಳಾಸ 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_ಬಫರ್,ಗಾತ್ರ_T cb_ಬಫರ್,ಗಾತ್ರ_T *pcbWrittenOrRequired);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_ಬಫರ್,ಗಾತ್ರ_T cb_ಬಫರ್,ಗಾತ್ರ_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI Process_Id_ಗಮ್ಯ_Session_Id(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGet_ಸಕ್ರಿಯ_Console_Session_Id();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION ಬಫರ್_3,PDWORD Returned_ಉದ್ದಳತೆ);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Highest_ಗಂಟು_ಸಂಖ್ಯೆ(PULONG Highest_ಗಂಟು_ಸಂಖ್ಯೆ);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Processor_ಗಂಟು(UCHAR Processor,PUCHAR ಗಂಟು_ಸಂಖ್ಯೆ);
  WINBASEAPI WINBOOL WINAPI Get_Numa_ಗಂಟು_Processor_ಮುಖವಾಡ(UCHAR ಗಂಟು_2,PULONGLONG Processor_ಮುಖವಾಡ);
  WINBASEAPI WINBOOL WINAPI Get_Numa_ಲಭ್ಯ_ಸ್ಮರಣೆ_ಗಂಟು(UCHAR ಗಂಟು_2,PULONGLONG ಲಭ್ಯ_ಬೈಟುಗಳು);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
