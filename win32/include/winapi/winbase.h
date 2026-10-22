/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _WINBASE_
#घोषणा _WINBASE_

#घोषणा WINADVAPI DECLSPEC_IMPORT
#घोषणा WINBASEAPI DECLSPEC_IMPORT
#घोषणा ZAWPROXYAPI DECLSPEC_IMPORT

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#घोषणा DefineHandleTable(w) ((w),TRUE)
#घोषणा LimitEmsPages(dw)
#घोषणा Set_Swap_Area_आकार(w) (w)
#घोषणा LockSegment(w) GlobalFix((HANDLE)(w))
#घोषणा UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#घोषणा GetCurrentTime() Get_Tick_गिनती()

#घोषणा Yield()

#घोषणा INVALID_HANDLE_मूल्य ((HANDLE)(LONG_PTR)-1)
#घोषणा INVALID_FILE_आकार ((DWORD)0xffffffff)
#घोषणा INVALID_SET_FILE_POINTER ((DWORD)-1)
#घोषणा INVALID_FILE_ATTRIBUTES ((DWORD)-1)

#घोषणा FILE_BEGIN 0
#घोषणा FILE_CURRENT 1
#घोषणा FILE_END 2

#घोषणा TIME_ZONE_ID_INVALID ((DWORD)0xffffffff)

#घोषणा WAIT_FAILED ((DWORD)0xffffffff)
#घोषणा WAIT_OBJECT_0 ((STATUS_WAIT_0) + 0)
#घोषणा WAIT_ABANDONED ((STATUS_ABANDONED_WAIT_0) + 0)
#घोषणा WAIT_ABANDONED_0 ((STATUS_ABANDONED_WAIT_0) + 0)
#घोषणा WAIT_IO_COMPLETION STATUS_USER_APC
#घोषणा STILL_ACTIVE STATUS_PENDING
#घोषणा EXCEPTION_ACCESS_VIOLATION STATUS_ACCESS_VIOLATION
#घोषणा EXCEPTION_DATATYPE_MISALIGNMENT STATUS_DATATYPE_MISALIGNMENT
#घोषणा EXCEPTION_BREAKPOINT STATUS_BREAKPOINT
#घोषणा EXCEPTION_SINGLE_STEP STATUS_SINGLE_STEP
#घोषणा EXCEPTION_ARRAY_BOUNDS_EXCEEDED STATUS_ARRAY_BOUNDS_EXCEEDED
#घोषणा EXCEPTION_FLT_DENORMAL_OPERAND STATUS_FLOAT_DENORMAL_OPERAND
#घोषणा EXCEPTION_FLT_DIVIDE_BY_ZERO STATUS_FLOAT_DIVIDE_BY_ZERO
#घोषणा EXCEPTION_FLT_INEXACT_परिणाम STATUS_FLOAT_INEXACT_परिणाम
#घोषणा EXCEPTION_FLT_INVALID_OPERATION STATUS_FLOAT_INVALID_OPERATION
#घोषणा EXCEPTION_FLT_OVERFLOW STATUS_FLOAT_OVERFLOW
#घोषणा EXCEPTION_FLT_ढेर_CHECK STATUS_FLOAT_ढेर_CHECK
#घोषणा EXCEPTION_FLT_UNDERFLOW STATUS_FLOAT_UNDERFLOW
#घोषणा EXCEPTION_INT_DIVIDE_BY_ZERO STATUS_INTEGER_DIVIDE_BY_ZERO
#घोषणा EXCEPTION_INT_OVERFLOW STATUS_INTEGER_OVERFLOW
#घोषणा EXCEPTION_PRIV_INSTRUCTION STATUS_PRIVILEGED_INSTRUCTION
#घोषणा EXCEPTION_IN_PAGE_ERROR STATUS_IN_PAGE_ERROR
#घोषणा EXCEPTION_ILLEGAL_INSTRUCTION STATUS_ILLEGAL_INSTRUCTION
#घोषणा EXCEPTION_NONCONTINUABLE_EXCEPTION STATUS_NONCONTINUABLE_EXCEPTION
#घोषणा EXCEPTION_ढेर_OVERFLOW STATUS_ढेर_OVERFLOW
#घोषणा EXCEPTION_INVALID_DISPOSITION STATUS_INVALID_DISPOSITION
#घोषणा EXCEPTION_GUARD_PAGE STATUS_GUARD_PAGE_VIOLATION
#घोषणा EXCEPTION_INVALID_HANDLE STATUS_INVALID_HANDLE
#घोषणा EXCEPTION_POSSIBLE_DEADLOCK STATUS_POSSIBLE_DEADLOCK
#घोषणा CONTROL_C_EXIT STATUS_CONTROL_C_EXIT
#घोषणा MoveMemory RtlMoveMemory
#घोषणा CopyMemory RtlCopyMemory
#घोषणा FillMemory RtlFillMemory
#घोषणा ZeroMemory RtlZeroMemory
#घोषणा SecureZeroMemory RtlSecureZeroMemory

#घोषणा FILE_FLAG_WRITE_THROUGH 0x80000000
#घोषणा FILE_FLAG_OVERLAPPED 0x40000000
#घोषणा FILE_FLAG_NO_BUFFERING 0x20000000
#घोषणा FILE_FLAG_RANDOM_ACCESS 0x10000000
#घोषणा FILE_FLAG_SEQUENTIAL_SCAN 0x8000000
#घोषणा FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#घोषणा FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#घोषणा FILE_FLAG_POSIX_SEMANTICS 0x1000000
#घोषणा FILE_FLAG_OPEN_REPARSE_POINT 0x200000
#घोषणा FILE_FLAG_OPEN_NO_RECALL 0x100000
#घोषणा FILE_FLAG_FIRST_PIPE_INSTANCE 0x80000

#घोषणा CREATE_NEW 1
#घोषणा CREATE_ALWAYS 2
#घोषणा OPEN_EXISTING 3
#घोषणा OPEN_ALWAYS 4
#घोषणा TRUNCATE_EXISTING 5

#घोषणा PROGRESS_CONTINUE 0
#घोषणा PROGRESS_CANCEL 1
#घोषणा PROGRESS_STOP 2
#घोषणा PROGRESS_QUIET 3

#घोषणा CALLBACK_CHUNK_FINISHED 0x0
#घोषणा CALLBACK_STREAM_SWITCH 0x1

#घोषणा COPY_FILE_FAIL_IF_EXISTS 0x1
#घोषणा COPY_FILE_RESTARTABLE 0x2
#घोषणा COPY_FILE_OPEN_SOURCE_FOR_WRITE 0x4
#घोषणा COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#घोषणा REPLACEFILE_WRITE_THROUGH 0x1
#घोषणा REPLACEFILE_IGNORE_MERGE_ERRORS 0x2

#घोषणा PIPE_ACCESS_INBOUND 0x1
#घोषणा PIPE_ACCESS_OUTBOUND 0x2
#घोषणा PIPE_ACCESS_DUPLEX 0x3

#घोषणा PIPE_CLIENT_END 0x0
#घोषणा PIPE_SERVER_END 0x1

#घोषणा PIPE_WAIT 0x0
#घोषणा PIPE_NOWAIT 0x1
#घोषणा PIPE_READMODE_BYTE 0x0
#घोषणा PIPE_READMODE_MESSAGE 0x2
#घोषणा PIPE_TYPE_BYTE 0x0
#घोषणा PIPE_TYPE_MESSAGE 0x4

#घोषणा PIPE_UNLIMITED_INSTANCES 255

#घोषणा SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#घोषणा SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#घोषणा SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#घोषणा SECURITY_DELEGATION (SecurityDelegation << 16)

#घोषणा SECURITY_CONTEXT_TRACKING 0x40000
#घोषणा SECURITY_EFFECTIVE_ONLY 0x80000

#घोषणा SECURITY_SQOS_PRESENT 0x100000
#घोषणा SECURITY_VALID_SQOS_FLAGS 0x1f0000

  प्रकार काष्ठा _OVERLAPPED {
    ULONG_PTR Internal;
    ULONG_PTR Internal_ऊपरी;
    जोड़ {
      काष्ठा {
	DWORD Offset;
	DWORD Offset_ऊपरी;
      };
      PVOID Pointer;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  प्रकार काष्ठा _SECURITY_ATTRIBUTES {
    DWORD n_लंबाई;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_ATTRIBUTES,*PSECURITY_ATTRIBUTES,*LPSECURITY_ATTRIBUTES;

  प्रकार काष्ठा _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#अगर_अघोषित _FILETIME_
#घोषणा _FILETIME_
  प्रकार काष्ठा _FILETIME {
    DWORD dw_निचला_Date_Time;
    DWORD dw_ऊपरी_Date_Time;
  } FILETIME,*PFILETIME,*LPFILETIME;
#पूर्ण_अगर

  प्रकार काष्ठा _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  प्रकार DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
  प्रकार PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
  प्रकार VOID (WINAPI *PFIBER_START_ROUTINE)(LPVOID lpFiberParameter);
  प्रकार PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;

  प्रकार RTL_CRITICAL_SECTION CRITICAL_SECTION;
  प्रकार PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  प्रकार PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  प्रकार RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  प्रकार PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  प्रकार PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI EncodePointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI DecodePointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI EncodeSystemPointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI DecodeSystemPointer(PVOID Ptr);

#अगर_घोषित I_X86_
  प्रकार PLDT_ENTRY LPLDT_ENTRY;
#अन्यथा
  प्रकार LPVOID LPLDT_ENTRY;
#पूर्ण_अगर

#घोषणा MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#घोषणा MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#घोषणा SP_SERIALCOMM ((DWORD)0x1)

#घोषणा PST_UNSPECIFIED ((DWORD)0x0)
#घोषणा PST_RS232 ((DWORD)0x1)
#घोषणा PST_PARALLELPORT ((DWORD)0x2)
#घोषणा PST_RS422 ((DWORD)0x3)
#घोषणा PST_RS423 ((DWORD)0x4)
#घोषणा PST_RS449 ((DWORD)0x5)
#घोषणा PST_MODEM ((DWORD)0x6)
#घोषणा PST_FAX ((DWORD)0x21)
#घोषणा PST_SCANNER ((DWORD)0x22)
#घोषणा PST_NETWORK_BRIDGE ((DWORD)0x100)
#घोषणा PST_LAT ((DWORD)0x101)
#घोषणा PST_TCPIP_TELNET ((DWORD)0x102)
#घोषणा PST_X25 ((DWORD)0x103)

#घोषणा PCF_DTRDSR ((DWORD)0x1)
#घोषणा PCF_RTSCTS ((DWORD)0x2)
#घोषणा PCF_RLSD ((DWORD)0x4)
#घोषणा PCF_PARITY_CHECK ((DWORD)0x8)
#घोषणा PCF_XONXOFF ((DWORD)0x10)
#घोषणा PCF_SETXCHAR ((DWORD)0x20)
#घोषणा PCF_TOTALTIMEOUTS ((DWORD)0x40)
#घोषणा PCF_INTTIMEOUTS ((DWORD)0x80)
#घोषणा PCF_SPECIALCHARS ((DWORD)0x100)
#घोषणा PCF_16BITMODE ((DWORD)0x200)

#घोषणा SP_PARITY ((DWORD)0x1)
#घोषणा SP_BAUD ((DWORD)0x2)
#घोषणा SP_DATABITS ((DWORD)0x4)
#घोषणा SP_STOPBITS ((DWORD)0x8)
#घोषणा SP_HANDSHAKING ((DWORD)0x10)
#घोषणा SP_PARITY_CHECK ((DWORD)0x20)
#घोषणा SP_RLSD ((DWORD)0x40)

#घोषणा BAUD_075 ((DWORD)0x1)
#घोषणा BAUD_110 ((DWORD)0x2)
#घोषणा BAUD_134_5 ((DWORD)0x4)
#घोषणा BAUD_150 ((DWORD)0x8)
#घोषणा BAUD_300 ((DWORD)0x10)
#घोषणा BAUD_600 ((DWORD)0x20)
#घोषणा BAUD_1200 ((DWORD)0x40)
#घोषणा BAUD_1800 ((DWORD)0x80)
#घोषणा BAUD_2400 ((DWORD)0x100)
#घोषणा BAUD_4800 ((DWORD)0x200)
#घोषणा BAUD_7200 ((DWORD)0x400)
#घोषणा BAUD_9600 ((DWORD)0x800)
#घोषणा BAUD_14400 ((DWORD)0x1000)
#घोषणा BAUD_19200 ((DWORD)0x2000)
#घोषणा BAUD_38400 ((DWORD)0x4000)
#घोषणा BAUD_56K ((DWORD)0x8000)
#घोषणा BAUD_128K ((DWORD)0x10000)
#घोषणा BAUD_115200 ((DWORD)0x20000)
#घोषणा BAUD_57600 ((DWORD)0x40000)
#घोषणा BAUD_USER ((DWORD)0x10000000)

#घोषणा DATABITS_5 ((WORD)0x1)
#घोषणा DATABITS_6 ((WORD)0x2)
#घोषणा DATABITS_7 ((WORD)0x4)
#घोषणा DATABITS_8 ((WORD)0x8)
#घोषणा DATABITS_16 ((WORD)0x10)
#घोषणा DATABITS_16X ((WORD)0x20)

#घोषणा STOPBITS_10 ((WORD)0x1)
#घोषणा STOPBITS_15 ((WORD)0x2)
#घोषणा STOPBITS_20 ((WORD)0x4)
#घोषणा PARITY_NONE ((WORD)0x100)
#घोषणा PARITY_ODD ((WORD)0x200)
#घोषणा PARITY_EVEN ((WORD)0x400)
#घोषणा PARITY_MARK ((WORD)0x800)
#घोषणा PARITY_SPACE ((WORD)0x1000)

  प्रकार काष्ठा _COMMPROP {
    WORD w_Packet_लंबाई;
    WORD wPacketVersion;
    DWORD dwServiceMask;
    DWORD dwReserved1;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD w_Settable_तथ्य;
    WORD wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#घोषणा COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  प्रकार काष्ठा _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD fXoffSent : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cbInQue;
    DWORD cbOutQue;
  } COMSTAT,*LPCOMSTAT;

#घोषणा DTR_CONTROL_DISABLE 0x0
#घोषणा DTR_CONTROL_ENABLE 0x1
#घोषणा DTR_CONTROL_HANDSHAKE 0x2

#घोषणा RTS_CONTROL_DISABLE 0x0
#घोषणा RTS_CONTROL_ENABLE 0x1
#घोषणा RTS_CONTROL_HANDSHAKE 0x2
#घोषणा RTS_CONTROL_TOGGLE 0x3

  प्रकार काष्ठा _DCB {
    DWORD DCBlength;
    DWORD BaudRate;
    DWORD f_द्विआधारी: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD fDsrSensitivity:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD fOutX: 1;
    DWORD fInX: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    WORD wReserved;
    WORD XonLim;
    WORD XoffLim;
    BYTE Byte_आकार;
    BYTE Parity;
    BYTE StopBits;
    अक्षर XonChar;
    अक्षर XoffChar;
    अक्षर ErrorChar;
    अक्षर EofChar;
    अक्षर EvtChar;
    WORD wReserved1;
  } DCB,*LPDCB;

  प्रकार काष्ठा _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD Read_योग_Timeout_Multiplier;
    DWORD Read_योग_Timeout_Constant;
    DWORD Write_योग_Timeout_Multiplier;
    DWORD Write_योग_Timeout_Constant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  प्रकार काष्ठा _COMMCONFIG {
    DWORD dw_आकार;
    WORD wVersion;
    WORD wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dwProviderOffset;
    DWORD dw_Provider_आकार;
    WCHAR wc_Provider_तथ्य[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  प्रकार काष्ठा _SYSTEM_INFO {
    जोड़ {
      DWORD dwOemId;
      काष्ठा {
	WORD wProcessorArchitecture;
	WORD wReserved;
      };
    };
    DWORD dw_Page_आकार;
    LPVOID lpMinimumApplicationAddress;
    LPVOID lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD dw_संख्या_Of_Processors;
    DWORD dwProcessorType;
    DWORD dwAllocationGranularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#घोषणा FreeModule(hLibModule) FreeLibrary((hLibModule))
#घोषणा MakeProcInstance(lpProc,hInstance) (lpProc)
#घोषणा FreeProcInstance(lpProc) (lpProc)

#घोषणा GMEM_FIXED 0x0
#घोषणा GMEM_MOVEABLE 0x2
#घोषणा GMEM_NOCOMPACT 0x10
#घोषणा GMEM_NODISCARD 0x20
#घोषणा GMEM_ZEROINIT 0x40
#घोषणा GMEM_MODIFY 0x80
#घोषणा GMEM_DISCARDABLE 0x100
#घोषणा GMEM_NOT_BANKED 0x1000
#घोषणा GMEM_SHARE 0x2000
#घोषणा GMEM_DDESHARE 0x2000
#घोषणा GMEM_NOTIFY 0x4000
#घोषणा GMEM_LOWER GMEM_NOT_BANKED
#घोषणा GMEM_VALID_FLAGS 0x7F72
#घोषणा GMEM_INVALID_HANDLE 0x8000

#घोषणा GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#घोषणा GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#घोषणा GlobalLRUNewest(h) ((HANDLE)(h))
#घोषणा GlobalLRUOldest(h) ((HANDLE)(h))
#घोषणा GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#घोषणा GMEM_DISCARDED 0x4000
#घोषणा GMEM_LOCKCOUNT 0xff

  प्रकार काष्ठा _MEMORYSTATUS {
    DWORD dw_लंबाई;
    DWORD dwMemoryLoad;
    आकार_T dw_योग_Phys;
    आकार_T dwAvailPhys;
    आकार_T dw_योग_Page_File;
    आकार_T dwAvailPageFile;
    आकार_T dw_योग_Virtual;
    आकार_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#घोषणा LMEM_FIXED 0x0
#घोषणा LMEM_MOVEABLE 0x2
#घोषणा LMEM_NOCOMPACT 0x10
#घोषणा LMEM_NODISCARD 0x20
#घोषणा LMEM_ZEROINIT 0x40
#घोषणा LMEM_MODIFY 0x80
#घोषणा LMEM_DISCARDABLE 0xf00
#घोषणा LMEM_VALID_FLAGS 0xf72
#घोषणा LMEM_INVALID_HANDLE 0x8000

#घोषणा LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#घोषणा LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#घोषणा NONZEROLHND (LMEM_MOVEABLE)
#घोषणा NONZEROLPTR (LMEM_FIXED)

#घोषणा LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#घोषणा LMEM_DISCARDED 0x4000
#घोषणा LMEM_LOCKCOUNT 0xff

#घोषणा DEBUG_PROCESS 0x1
#घोषणा DEBUG_ONLY_THIS_PROCESS 0x2
#घोषणा CREATE_SUSPENDED 0x4
#घोषणा DETACHED_PROCESS 0x8
#घोषणा CREATE_NEW_CONSOLE 0x10
#घोषणा NORMAL_PRIORITY_CLASS 0x20
#घोषणा IDLE_PRIORITY_CLASS 0x40
#घोषणा ऊपरी_PRIORITY_CLASS 0x80
#घोषणा REALTIME_PRIORITY_CLASS 0x100
#घोषणा CREATE_NEW_PROCESS_GROUP 0x200
#घोषणा CREATE_UNICODE_ENVIRONMENT 0x400
#घोषणा CREATE_SEPARATE_WOW_VDM 0x800
#घोषणा CREATE_SHARED_WOW_VDM 0x1000
#घोषणा CREATE_FORCEDOS 0x2000
#घोषणा BELOW_NORMAL_PRIORITY_CLASS 0x4000
#घोषणा ABOVE_NORMAL_PRIORITY_CLASS 0x8000
#घोषणा ढेर_आकार_PARAM_IS_A_RESERVATION 0x10000

#घोषणा CREATE_BREAKAWAY_FROM_JOB 0x1000000
#घोषणा CREATE_PRESERVE_CODE_AUTHZ_LEVEL 0x2000000

#घोषणा CREATE_DEFAULT_ERROR_MODE 0x4000000
#घोषणा CREATE_NO_WINDOW 0x8000000

#घोषणा PROFILE_USER 0x10000000
#घोषणा PROFILE_KERNEL 0x20000000
#घोषणा PROFILE_SERVER 0x40000000

#घोषणा CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#घोषणा THREAD_PRIORITY_LOWEST THREAD_BASE_PRIORITY_MIN
#घोषणा THREAD_PRIORITY_BELOW_NORMAL (THREAD_PRIORITY_LOWEST+1)
#घोषणा THREAD_PRIORITY_NORMAL 0
#घोषणा THREAD_PRIORITY_HIGHEST THREAD_BASE_PRIORITY_MAX
#घोषणा THREAD_PRIORITY_ABOVE_NORMAL (THREAD_PRIORITY_HIGHEST-1)
#घोषणा THREAD_PRIORITY_ERROR_RETURN (MAXLONG)

#घोषणा THREAD_PRIORITY_TIME_CRITICAL THREAD_BASE_PRIORITY_LOWRT
#घोषणा THREAD_PRIORITY_IDLE THREAD_BASE_PRIORITY_IDLE

#घोषणा EXCEPTION_DEBUG_EVENT 1
#घोषणा CREATE_THREAD_DEBUG_EVENT 2
#घोषणा CREATE_PROCESS_DEBUG_EVENT 3
#घोषणा EXIT_THREAD_DEBUG_EVENT 4
#घोषणा EXIT_PROCESS_DEBUG_EVENT 5
#घोषणा LOAD_DLL_DEBUG_EVENT 6
#घोषणा UNLOAD_DLL_DEBUG_EVENT 7
#घोषणा OUTPUT_DEBUG_STRING_EVENT 8
#घोषणा RIP_EVENT 9

  प्रकार काष्ठा _EXCEPTION_DEBUG_INFO {
    EXCEPTION_RECORD ExceptionRecord;
    DWORD dwFirstChance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  प्रकार काष्ठा _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  प्रकार काष्ठा _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lpBaseOfImage;
    DWORD dwDebugInfoFileOffset;
    DWORD n_Debug_Info_आकार;
    LPVOID lpThreadLocalBase;
    LPTHREAD_START_ROUTINE lpStartAddress;
    LPVOID lpImageName;
    WORD fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  प्रकार काष्ठा _EXIT_THREAD_DEBUG_INFO {
    DWORD dwExitCode;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  प्रकार काष्ठा _EXIT_PROCESS_DEBUG_INFO {
    DWORD dwExitCode;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  प्रकार काष्ठा _LOAD_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lpBaseOfDll;
    DWORD dwDebugInfoFileOffset;
    DWORD n_Debug_Info_आकार;
    LPVOID lpImageName;
    WORD fUnicode;
  } LOAD_DLL_DEBUG_INFO,*LPLOAD_DLL_DEBUG_INFO;

  प्रकार काष्ठा _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lpBaseOfDll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  प्रकार काष्ठा _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lp_Debug_String_तथ्य;
    WORD fUnicode;
    WORD n_Debug_String_लंबाई;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  प्रकार काष्ठा _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  प्रकार काष्ठा _DEBUG_EVENT {
    DWORD dwDebugEventCode;
    DWORD dwProcessId;
    DWORD dwThreadId;
    जोड़ {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      LOAD_DLL_DEBUG_INFO LoadDll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  प्रकार PCONTEXT LPCONTEXT;
  प्रकार PEXCEPTION_RECORD LPEXCEPTION_RECORD;
  प्रकार PEXCEPTION_POINTERS LPEXCEPTION_POINTERS;

#घोषणा DRIVE_UNKNOWN 0
#घोषणा DRIVE_NO_मूल_DIR 1
#घोषणा DRIVE_REMOVABLE 2
#घोषणा DRIVE_FIXED 3
#घोषणा DRIVE_REMOTE 4
#घोषणा DRIVE_CDROM 5
#घोषणा DRIVE_RAMDISK 6

#घोषणा GetFreeSpace(w) (0x100000L)
#घोषणा FILE_TYPE_UNKNOWN 0x0
#घोषणा FILE_TYPE_DISK 0x1
#घोषणा FILE_TYPE_CHAR 0x2
#घोषणा FILE_TYPE_PIPE 0x3
#घोषणा FILE_TYPE_REMOTE 0x8000

#घोषणा STD_निवेश_HANDLE ((DWORD)-10)
#घोषणा STD_OUTPUT_HANDLE ((DWORD)-11)
#घोषणा STD_ERROR_HANDLE ((DWORD)-12)

#घोषणा NOPARITY 0
#घोषणा ODDPARITY 1
#घोषणा EVENPARITY 2
#घोषणा MARKPARITY 3
#घोषणा SPACEPARITY 4

#घोषणा ONESTOPBIT 0
#घोषणा ONE5STOPBITS 1
#घोषणा TWOSTOPBITS 2

#घोषणा IGNORE 0
#घोषणा INFINITE 0xffffffff

#घोषणा CBR_110 110
#घोषणा CBR_300 300
#घोषणा CBR_600 600
#घोषणा CBR_1200 1200
#घोषणा CBR_2400 2400
#घोषणा CBR_4800 4800
#घोषणा CBR_9600 9600
#घोषणा CBR_14400 14400
#घोषणा CBR_19200 19200
#घोषणा CBR_38400 38400
#घोषणा CBR_56000 56000
#घोषणा CBR_57600 57600
#घोषणा CBR_115200 115200
#घोषणा CBR_128000 128000
#घोषणा CBR_256000 256000

#घोषणा CE_RXOVER 0x1
#घोषणा CE_OVERRUN 0x2
#घोषणा CE_RXPARITY 0x4
#घोषणा CE_FRAME 0x8
#घोषणा CE_BREAK 0x10
#घोषणा CE_TXFULL 0x100
#घोषणा CE_PTO 0x200
#घोषणा CE_IOE 0x400
#घोषणा CE_DNS 0x800
#घोषणा CE_OOP 0x1000
#घोषणा CE_MODE 0x8000

#घोषणा IE_BADID (-1)
#घोषणा IE_OPEN (-2)
#घोषणा IE_NOPEN (-3)
#घोषणा IE_MEMORY (-4)
#घोषणा IE_DEFAULT (-5)
#घोषणा IE_HARDWARE (-10)
#घोषणा IE_BYTESIZE (-11)
#घोषणा IE_BAUDRATE (-12)

#घोषणा EV_RXCHAR 0x1
#घोषणा EV_RXFLAG 0x2
#घोषणा EV_TXEMPTY 0x4
#घोषणा EV_CTS 0x8
#घोषणा EV_DSR 0x10
#घोषणा EV_RLSD 0x20
#घोषणा EV_BREAK 0x40
#घोषणा EV_ERR 0x80
#घोषणा EV_RING 0x100
#घोषणा EV_PERR 0x200
#घोषणा EV_RX80FULL 0x400
#घोषणा EV_EVENT1 0x800
#घोषणा EV_EVENT2 0x1000

#घोषणा SETXOFF 1
#घोषणा SETXON 2
#घोषणा SETRTS 3
#घोषणा CLRRTS 4
#घोषणा SETDTR 5
#घोषणा CLRDTR 6
#घोषणा RESETDEV 7
#घोषणा SETBREAK 8
#घोषणा CLRBREAK 9

#घोषणा PURGE_TXABORT 0x1
#घोषणा PURGE_RXABORT 0x2
#घोषणा PURGE_TXCLEAR 0x4
#घोषणा PURGE_RXCLEAR 0x8

#घोषणा LPTx 0x80

#घोषणा MS_CTS_ON ((DWORD)0x10)
#घोषणा MS_DSR_ON ((DWORD)0x20)
#घोषणा MS_RING_ON ((DWORD)0x40)
#घोषणा MS_RLSD_ON ((DWORD)0x80)

#घोषणा S_QUEUEEMPTY 0
#घोषणा S_THRESHOLD 1
#घोषणा S_ALLTHRESHOLD 2

#घोषणा S_NORMAL 0
#घोषणा S_LEGATO 1
#घोषणा S_STACCATO 2

#घोषणा S_PERIOD512 0
#घोषणा S_PERIOD1024 1
#घोषणा S_PERIOD2048 2
#घोषणा S_PERIODVOICE 3
#घोषणा S_WHITE512 4
#घोषणा S_WHITE1024 5
#घोषणा S_WHITE2048 6
#घोषणा S_WHITEVOICE 7

#घोषणा S_SERDVNA (-1)
#घोषणा S_SEROFM (-2)
#घोषणा S_SERMACT (-3)
#घोषणा S_SERQFUL (-4)
#घोषणा S_SERBDNT (-5)
#घोषणा S_SERDLN (-6)
#घोषणा S_SERDCC (-7)
#घोषणा S_SERDTP (-8)
#घोषणा S_SERDVL (-9)
#घोषणा S_SERDMD (-10)
#घोषणा S_SERDSH (-11)
#घोषणा S_SERDPT (-12)
#घोषणा S_SERDFQ (-13)
#घोषणा S_SERDDR (-14)
#घोषणा S_SERDSR (-15)
#घोषणा S_SERDST (-16)

#घोषणा NMPWAIT_WAIT_FOREVER 0xffffffff
#घोषणा NMPWAIT_NOWAIT 0x1
#घोषणा NMPWAIT_USE_DEFAULT_WAIT 0x0

#घोषणा FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_NAMES
#घोषणा FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_खोज
#घोषणा FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#घोषणा FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#घोषणा FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#घोषणा FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#घोषणा FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#घोषणा FILE_MAP_COPY SECTION_QUERY
#घोषणा FILE_MAP_WRITE SECTION_MAP_WRITE
#घोषणा FILE_MAP_READ SECTION_MAP_READ
#घोषणा FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#घोषणा FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#घोषणा OF_READ 0x0
#घोषणा OF_WRITE 0x1
#घोषणा OF_READWRITE 0x2
#घोषणा OF_SHARE_COMPAT 0x0
#घोषणा OF_SHARE_EXCLUSIVE 0x10
#घोषणा OF_SHARE_DENY_WRITE 0x20
#घोषणा OF_SHARE_DENY_READ 0x30
#घोषणा OF_SHARE_DENY_NONE 0x40
#घोषणा OF_PARSE 0x100
#घोषणा OF_DELETE 0x200
#घोषणा OF_VERIFY 0x400
#घोषणा OF_CANCEL 0x800
#घोषणा OF_CREATE 0x1000
#घोषणा OF_PROMPT 0x2000
#घोषणा OF_EXIST 0x4000
#घोषणा OF_REOPEN 0x8000

#घोषणा OFS_MAXPATHNAME 128
  प्रकार काष्ठा _OFSTRUCT {
    BYTE cBytes;
    BYTE fFixedDisk;
    WORD nErrCode;
    WORD Reserved1;
    WORD Reserved2;
    CHAR szPathName[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#अगर_अघोषित NOWINBASEINTERLOCK

#अगर_अघोषित _NTOS_

#अगर defined(__ia64__) && !defined(RC_INVOKED)

#घोषणा InterlockedIncrement _InterlockedIncrement
#घोषणा InterlockedIncrementAcquire _InterlockedIncrement_acq
#घोषणा InterlockedIncrementRelease _InterlockedIncrement_rel
#घोषणा InterlockedDecrement _InterlockedDecrement
#घोषणा InterlockedDecrementAcquire _InterlockedDecrement_acq
#घोषणा InterlockedDecrementRelease _InterlockedDecrement_rel
#घोषणा InterlockedExchange _InterlockedExchange
#घोषणा InterlockedExchangeAdd _InterlockedExchangeAdd
#घोषणा InterlockedCompareExchange _InterlockedCompareExchange
#घोषणा InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#घोषणा InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#घोषणा InterlockedExchangePointer _InterlockedExchangePointer
#घोषणा InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#घोषणा InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer_rel
#घोषणा InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer_acq

#घोषणा InterlockedIncrement64 _InterlockedIncrement64
#घोषणा InterlockedDecrement64 _InterlockedDecrement64
#घोषणा InterlockedExchange64 _InterlockedExchange64
#घोषणा InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#घोषणा InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#घोषणा InterlockedCompareExchange64 _InterlockedCompareExchange64
#घोषणा InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#घोषणा InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG अस्थिर *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG अस्थिर *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG अस्थिर *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG अस्थिर *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG अस्थिर *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG अस्थिर *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG अस्थिर *Target,LONGLONG मूल्य_3);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG अस्थिर *Target,LONGLONG मूल्य_3);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG अस्थिर *Addend,LONGLONG मूल्य_3);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG अस्थिर *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG अस्थिर *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG अस्थिर *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG अस्थिर *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG अस्थिर *lpAddend);
  LONG __cdecl InterlockedExchange(LONG अस्थिर *Target,LONG मूल्य_3);
  LONG __cdecl InterlockedExchangeAdd(LONG अस्थिर *Addend,LONG मूल्य_3);
  LONG __cdecl InterlockedCompareExchange(LONG अस्थिर *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG अस्थिर *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG अस्थिर *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl InterlockedExchangePointer(PVOID अस्थिर *Target,PVOID मूल्य_3);
  PVOID __cdecl InterlockedCompareExchangePointer(PVOID अस्थिर *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl InterlockedCompareExchangePointerAcquire(PVOID अस्थिर *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl InterlockedCompareExchangePointerRelease(PVOID अस्थिर *Destination,PVOID Exchange,PVOID Comperand);

#अगर_अघोषित InterlockedAnd
#घोषणा InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG अस्थिर *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    करो {
      i = j;
      j = InterlockedCompareExchange(Target,i & Set,i);
    } जबतक(i!=j);
    वापस j;
  }
#पूर्ण_अगर

#अगर_अघोषित InterlockedOr
#घोषणा InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG अस्थिर *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    करो {
      i = j;
      j = InterlockedCompareExchange(Target,i | Set,i);
    } जबतक(i!=j);
    वापस j;
  }
#पूर्ण_अगर

#अगर_अघोषित InterlockedXor
#घोषणा InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG अस्थिर *Target,LONG Set) {
    LONG i;
    LONG j;
    j = *Target;
    करो {
      i = j;
      j = InterlockedCompareExchange(Target,i ^ Set,i);
    } जबतक(i!=j);
    वापस j;
  }
#पूर्ण_अगर

#अगर_अघोषित InterlockedAnd64
#घोषणा InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG अस्थिर *Destination,LONGLONG मूल्य_3) {
    LONGLONG Old;
    करो {
      Old = *Destination;
    } जबतक(InterlockedCompareExchange64(Destination,Old & मूल्य_3,Old)!=Old);
    वापस Old;
  }
#पूर्ण_अगर

#अगर_अघोषित InterlockedOr64
#घोषणा InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG अस्थिर *Destination,LONGLONG मूल्य_3) {
    LONGLONG Old;
    करो {
      Old = *Destination;
    } जबतक(InterlockedCompareExchange64(Destination,Old | मूल्य_3,Old)!=Old);
    वापस Old;
  }
#पूर्ण_अगर

#अगर_अघोषित InterlockedXor64
#घोषणा InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG अस्थिर *Destination,LONGLONG मूल्य_3) {
    LONGLONG Old;
    करो {
      Old = *Destination;
    } जबतक(InterlockedCompareExchange64(Destination,Old ^ मूल्य_3,Old)!=Old);
    वापस Old;
  }
#पूर्ण_अगर

#अगर_अघोषित InterlockedBitTestAndSet
#घोषणा InterlockedBitTestAndSet InterlockedBitTestAndSet_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndSet_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (माप (*Base)*8-1));
    वापस (BOOLEAN)((InterlockedOr(&Base[Bit/(माप(*Base)*8)],tBit)&tBit)!=0);
  }
#पूर्ण_अगर

#अगर_अघोषित InterlockedBitTestAndReset
#घोषणा InterlockedBitTestAndReset InterlockedBitTestAndReset_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndReset_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (माप (*Base)*8-1));
    वापस (BOOLEAN)((InterlockedAnd(&Base[Bit/(माप(*Base)*8)],~tBit)&tBit)!=0);
  }
#पूर्ण_अगर

#अगर_अघोषित InterlockedBitTestAndComplement
#घोषणा InterlockedBitTestAndComplement InterlockedBitTestAndComplement_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement_Inline(LONG *Base,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (माप (*Base)*8-1));
    वापस (BOOLEAN)((InterlockedXor(&Base[Bit/(माप(*Base)*8)],tBit)&tBit)!=0);
  }
#पूर्ण_अगर
#या_अगर defined(__x86_64) && !defined(RC_INVOKED)

#घोषणा InterlockedIncrement _InterlockedIncrement
#घोषणा InterlockedIncrementAcquire InterlockedIncrement
#घोषणा InterlockedIncrementRelease InterlockedIncrement
#घोषणा InterlockedDecrement _InterlockedDecrement
#घोषणा InterlockedDecrementAcquire InterlockedDecrement
#घोषणा InterlockedDecrementRelease InterlockedDecrement
#घोषणा InterlockedExchange _InterlockedExchange
#घोषणा InterlockedExchangeAdd _InterlockedExchangeAdd
#घोषणा InterlockedCompareExchange _InterlockedCompareExchange
#घोषणा InterlockedCompareExchangeAcquire InterlockedCompareExchange
#घोषणा InterlockedCompareExchangeRelease InterlockedCompareExchange
#घोषणा InterlockedExchangePointer _InterlockedExchangePointer
#घोषणा InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#घोषणा InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#घोषणा InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer
#घोषणा InterlockedAnd64 _InterlockedAnd64
#घोषणा InterlockedOr64 _InterlockedOr64
#घोषणा InterlockedXor64 _InterlockedXor64
#घोषणा InterlockedIncrement64 _InterlockedIncrement64
#घोषणा InterlockedDecrement64 _InterlockedDecrement64
#घोषणा InterlockedExchange64 _InterlockedExchange64
#घोषणा InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#घोषणा InterlockedCompareExchange64 _InterlockedCompareExchange64
#घोषणा InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#घोषणा InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG अस्थिर *Addend);
  LONG InterlockedDecrement(LONG अस्थिर *Addend);
  LONG InterlockedExchange(LONG अस्थिर *Target,LONG मूल्य_3);
  LONG InterlockedExchangeAdd(LONG अस्थिर *Addend,LONG मूल्य_3);
  LONG InterlockedCompareExchange(LONG अस्थिर *Destination,LONG ExChange,LONG Comperand);
  PVOID InterlockedCompareExchangePointer(PVOID अस्थिर *Destination,PVOID Exchange,PVOID Comperand);
  PVOID InterlockedExchangePointer(PVOID अस्थिर *Target,PVOID मूल्य_3);
  LONG64 InterlockedAnd64(LONG64 अस्थिर *Destination,LONG64 मूल्य_3);
  LONG64 InterlockedOr64(LONG64 अस्थिर *Destination,LONG64 मूल्य_3);
  LONG64 InterlockedXor64(LONG64 अस्थिर *Destination,LONG64 मूल्य_3);
  LONG64 InterlockedIncrement64(LONG64 अस्थिर *Addend);
  LONG64 InterlockedDecrement64(LONG64 अस्थिर *Addend);
  LONG64 InterlockedExchange64(LONG64 अस्थिर *Target,LONG64 मूल्य_3);
  LONG64 InterlockedExchangeAdd64(LONG64 अस्थिर *Addend,LONG64 मूल्य_3);
  LONG64 InterlockedCompareExchange64(LONG64 अस्थिर *Destination,LONG64 ExChange,LONG64 Comperand);
#अन्यथा
  LONG WINAPI InterlockedIncrement(LONG अस्थिर *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG अस्थिर *lpAddend);
  LONG WINAPI InterlockedExchange(LONG अस्थिर *Target,LONG मूल्य_3);

#अगर_अघोषित InterlockedExchangePointer
#घोषणा InterlockedExchangePointer(Target,मूल्य_3) (PVOID)InterlockedExchange((PLONG)(Target),(LONG)(मूल्य_3))
#पूर्ण_अगर

  LONG WINAPI InterlockedExchangeAdd(LONG अस्थिर *Addend,LONG मूल्य_3);
  LONG WINAPI InterlockedCompareExchange(LONG अस्थिर *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG अस्थिर *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG अस्थिर *Destination,LONGLONG मूल्य_3) {
    LONGLONG Old;
    करो {
      Old = *Destination;
    } जबतक(InterlockedCompareExchange64(Destination,Old & मूल्य_3,Old)!=Old);
    वापस Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG अस्थिर *Destination,LONGLONG मूल्य_3) {
    LONGLONG Old;
    करो {
      Old = *Destination;
    } जबतक(InterlockedCompareExchange64(Destination,Old | मूल्य_3,Old)!=Old);
    वापस Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG अस्थिर *Destination,LONGLONG मूल्य_3) {
    LONGLONG Old;
    करो {
      Old = *Destination;
    } जबतक(InterlockedCompareExchange64(Destination,Old ^ मूल्य_3,Old)!=Old);

    वापस Old;
  }

  __CRT_INLINE LONGLONG InterlockedIncrement64(LONGLONG अस्थिर *Addend) {
    LONGLONG Old;
    करो {
      Old = *Addend;
    } जबतक(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    वापस Old + 1;
  }

  __CRT_INLINE LONGLONG InterlockedDecrement64(LONGLONG अस्थिर *Addend) {
    LONGLONG Old;
    करो {
      Old = *Addend;
    } जबतक(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    वापस Old - 1;
  }

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG अस्थिर *Target,LONGLONG मूल्य_3) {
    LONGLONG Old;
    करो {
      Old = *Target;
    } जबतक(InterlockedCompareExchange64(Target,मूल्य_3,Old)!=Old);
    वापस Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG अस्थिर *Addend,LONGLONG मूल्य_3) {
    LONGLONG Old;
    करो {
      Old = *Addend;
    } जबतक(InterlockedCompareExchange64(Addend,Old + मूल्य_3,Old)!=Old);
    वापस Old;
  }

#अगर_अघोषित InterlockedCompareExchangePointer
#अगर_घोषित __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID अस्थिर *Destination,PVOID ExChange,PVOID Comperand) {
    वापस((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG अस्थिर *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#घोषणा InterlockedCompareExchangePointer __InlineInterlockedCompareExchangePointer
#अन्यथा
#घोषणा InterlockedCompareExchangePointer(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG अस्थिर *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा InterlockedIncrementAcquire InterlockedIncrement
#घोषणा InterlockedIncrementRelease InterlockedIncrement
#घोषणा InterlockedDecrementAcquire InterlockedDecrement
#घोषणा InterlockedDecrementRelease InterlockedDecrement
#घोषणा InterlockedIncrementAcquire InterlockedIncrement
#घोषणा InterlockedIncrementRelease InterlockedIncrement
#घोषणा InterlockedCompareExchangeAcquire InterlockedCompareExchange
#घोषणा InterlockedCompareExchangeRelease InterlockedCompareExchange
#घोषणा InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#घोषणा InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#अगर_अघोषित InterlockedCompareExchangePointerAcquire
#घोषणा InterlockedCompareExchangePointerAcquire InterlockedCompareExchangePointer
#पूर्ण_अगर
#अगर_अघोषित InterlockedCompareExchangePointerRelease
#घोषणा InterlockedCompareExchangePointerRelease InterlockedCompareExchangePointer
#पूर्ण_अगर
#पूर्ण_अगर

#अगर defined(_SLIST_HEADER_) && !defined(_NTOSP_)
  WINBASEAPI VOID WINAPI Initialize_SList_शीर्ष(PSLIST_HEADER List_शीर्ष);
  WINBASEAPI PSLIST_ENTRY WINAPI Interlocked_निकालो_Entry_SList(PSLIST_HEADER List_शीर्ष);
  WINBASEAPI PSLIST_ENTRY WINAPI Interlocked_धकेलो_Entry_SList(PSLIST_HEADER List_शीर्ष,PSLIST_ENTRY ListEntry);
  WINBASEAPI PSLIST_ENTRY WINAPI InterlockedFlushSList(PSLIST_HEADER List_शीर्ष);
  WINBASEAPI USHORT WINAPI QueryDepthSList(PSLIST_HEADER List_शीर्ष);
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL h_Res_तथ्य);
  WINBASEAPI LPVOID WINAPI LockResource(HGLOBAL h_Res_तथ्य);

#घोषणा UnlockResource(h_Res_तथ्य) ((h_Res_तथ्य),0)
#घोषणा MAXINTATOM 0xC000
#घोषणा MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((WORD)(i)))
#घोषणा INVALID_ATOM ((ATOM)0)

  पूर्णांक WINAPI WinMain(HINSTANCE hInstance,HINSTANCE h_पूर्व_Instance,LPSTR lp_Cmd_पंक्ति,पूर्णांक nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dwExitCode);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI GetProcAddress(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI GetVersion(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,आकार_T dwBytes);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,आकार_T dwBytes,UINT uFlags);
  WINBASEAPI आकार_T WINAPI Global_आकार(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalLock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI आकार_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalMemoryStatus(LPMEMORYSTATUS lp_बफर);

  प्रकार काष्ठा _MEMORYSTATUSEX {
    DWORD dw_लंबाई;
    DWORD dwMemoryLoad;
    DWORDLONG ull_योग_Phys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ull_योग_Page_File;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ull_योग_Virtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI GlobalMemoryStatusEx(LPMEMORYSTATUSEX lp_बफर);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,आकार_T uBytes);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,आकार_T uBytes,UINT uFlags);
  WINBASEAPI LPVOID WINAPI LocalLock(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI आकार_T WINAPI Local_आकार(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI आकार_T WINAPI LocalShrink(HLOCAL hMem,UINT cb_New_आकार);
  WINBASEAPI आकार_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lpBaseAddress,आकार_T dw_आकार);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lpAddress,आकार_T dw_आकार,DWORD flAllocationType,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lpAddress,आकार_T dw_आकार,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lpAddress,आकार_T dw_आकार,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI आकार_T WINAPI VirtualQuery(LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lp_बफर,आकार_T dw_लंबाई);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lpAddress,आकार_T dw_आकार,DWORD flAllocationType,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lpBaseAddress,आकार_T dw_Region_आकार,PVOID *lpAddresses,ULONG_PTR *lpdw_गिनती,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lpBaseAddress,आकार_T dw_Region_आकार);
  WINBASEAPI आकार_T WINAPI GetLargePageMinimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD FirmwareTableProviderSignature,PVOID p_Firmware_Table_Enum_बफर,DWORD बफर_आकार);
  WINBASEAPI UINT WINAPI GetSystemFirmwareTable(DWORD FirmwareTableProviderSignature,DWORD FirmwareTableID,PVOID p_Firmware_Table_बफर,DWORD बफर_आकार);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lpAddress,आकार_T dw_आकार,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lpAddress,आकार_T dw_आकार,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI आकार_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lpAddress,PMEMORY_BASIC_INFORMATION lp_बफर,आकार_T dw_लंबाई);
  WINBASEAPI HANDLE WINAPI HeapCreate(DWORD flOptions,आकार_T dw_Initial_आकार,आकार_T dw_Maximum_आकार);
  WINBASEAPI WINBOOL WINAPI HeapDestroy(HANDLE hHeap);
  WINBASEAPI LPVOID WINAPI HeapAlloc(HANDLE hHeap,DWORD dwFlags,आकार_T dwBytes);
  WINBASEAPI LPVOID WINAPI HeapReAlloc(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem,आकार_T dwBytes);
  WINBASEAPI WINBOOL WINAPI HeapFree(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI आकार_T WINAPI Heap_आकार(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI HeapValidate(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI आकार_T WINAPI HeapCompact(HANDLE hHeap,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI GetProcessHeap(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD संख्या_Of_Heaps,PHANDLE ProcessHeaps);

  प्रकार काष्ठा _PROCESS_HEAP_ENTRY {
    PVOID lp_तथ्य;
    DWORD cb_तथ्य;
    BYTE cbOverhead;
    BYTE i_Region_सूचकांक;
    WORD wFlags;
    जोड़ {
      काष्ठा {
	HANDLE hMem;
	DWORD dwReserved[3];
      } Block;
      काष्ठा {
	DWORD dw_Committed_आकार;
	DWORD dw_Un_Committed_आकार;
	LPVOID lpFirstBlock;
	LPVOID lpLastBlock;
      } Region;
    };
  } PROCESS_HEAP_ENTRY,*LPPROCESS_HEAP_ENTRY,*PPROCESS_HEAP_ENTRY;

#घोषणा PROCESS_HEAP_REGION 0x1
#घोषणा PROCESS_HEAP_UNCOMMITTED_RANGE 0x2
#घोषणा PROCESS_HEAP_ENTRY_BUSY 0x4
#घोषणा PROCESS_HEAP_ENTRY_MOVEABLE 0x10
#घोषणा PROCESS_HEAP_ENTRY_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI HeapLock(HANDLE hHeap);
  WINBASEAPI WINBOOL WINAPI HeapUnlock(HANDLE hHeap);
  WINBASEAPI WINBOOL WINAPI HeapWalk(HANDLE hHeap,LPPROCESS_HEAP_ENTRY lpEntry);
  WINBASEAPI WINBOOL WINAPI HeapSetInformation(HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,आकार_T Heap_Information_लंबाई);
  WINBASEAPI WINBOOL WINAPI HeapQueryInformation(HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,आकार_T Heap_Information_लंबाई,PSIZE_T Return_लंबाई);

#घोषणा SCS_32_BIT_द्विआधारी 0
#घोषणा SCS_DOS_द्विआधारी 1
#घोषणा SCS_WOW_द्विआधारी 2
#घोषणा SCS_PIF_द्विआधारी 3
#घोषणा SCS_POSIX_द्विआधारी 4
#घोषणा SCS_OS216_द्विआधारी 5
#घोषणा SCS_64_BIT_द्विआधारी 6

#अगर_घोषित UNICODE
#घोषणा Get_द्विआधारी_Type Get_द्विआधारी_Type_W
#घोषणा GetShortPathName GetShortPathNameW
#घोषणा GetLongPathName GetLongPathNameW
#घोषणा GetEnvironmentStrings GetEnvironmentStringsW
#घोषणा SetEnvironmentStrings SetEnvironmentStringsW
#घोषणा FreeEnvironmentStrings FreeEnvironmentStringsW
#अन्यथा
#घोषणा Get_द्विआधारी_Type Get_द्विआधारी_Type_A
#घोषणा GetShortPathName GetShortPathNameA
#घोषणा GetLongPathName GetLongPathNameA
#घोषणा GetEnvironmentStringsA GetEnvironmentStrings
#घोषणा SetEnvironmentStrings SetEnvironmentStringsA
#घोषणा FreeEnvironmentStrings FreeEnvironmentStringsA
#पूर्ण_अगर

#अगर_घोषित _WIN64
#घोषणा SCS_THIS_PLATFORM_द्विआधारी SCS_64_BIT_द्विआधारी
#अन्यथा
#घोषणा SCS_THIS_PLATFORM_द्विआधारी SCS_32_BIT_द्विआधारी
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI Get_द्विआधारी_Type_A(LPCSTR lpApplicationName,LPDWORD lp_द्विआधारी_Type);
  WINBASEAPI WINBOOL WINAPI Get_द्विआधारी_Type_W(LPCWSTR lpApplicationName,LPDWORD lp_द्विआधारी_Type);
  WINBASEAPI DWORD WINAPI GetShortPathNameA(LPCSTR lpszLongPath,LPSTR lpszShortPath,DWORD cch_बफर);
  WINBASEAPI DWORD WINAPI GetShortPathNameW(LPCWSTR lpszLongPath,LPWSTR lpszShortPath,DWORD cch_बफर);
  WINBASEAPI DWORD WINAPI GetLongPathNameA(LPCSTR lpszShortPath,LPSTR lpszLongPath,DWORD cch_बफर);
  WINBASEAPI DWORD WINAPI GetLongPathNameW(LPCWSTR lpszShortPath,LPWSTR lpszLongPath,DWORD cch_बफर);
  WINBASEAPI WINBOOL WINAPI GetProcessAffinityMask(HANDLE hProcess,PDWORD_PTR lpProcessAffinityMask,PDWORD_PTR lpSystemAffinityMask);
  WINBASEAPI WINBOOL WINAPI SetProcessAffinityMask(HANDLE hProcess,DWORD_PTR dwProcessAffinityMask);
  WINBASEAPI WINBOOL WINAPI Get_Process_Handle_गिनती(HANDLE hProcess,PDWORD pdw_Handle_गिनती);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_Set_आकार(HANDLE hProcess,PSIZE_T lp_Minimum_Working_Set_आकार,PSIZE_T lp_Maximum_Working_Set_आकार);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_Set_आकार_Ex(HANDLE hProcess,PSIZE_T lp_Minimum_Working_Set_आकार,PSIZE_T lp_Maximum_Working_Set_आकार,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI Set_Process_Working_Set_आकार(HANDLE hProcess,आकार_T dw_Minimum_Working_Set_आकार,आकार_T dw_Maximum_Working_Set_आकार);
  WINBASEAPI WINBOOL WINAPI Set_Process_Working_Set_आकार_Ex(HANDLE hProcess,आकार_T dw_Minimum_Working_Set_आकार,आकार_T dw_Maximum_Working_Set_आकार,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI GetExitCodeProcess(HANDLE hProcess,LPDWORD lpExitCode);
  WINBASEAPI VOID WINAPI FatalExit(पूर्णांक ExitCode);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI GetEnvironmentStringsW(VOID);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentStringsA(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentStringsW(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI FreeEnvironmentStringsA(LPCH);
  WINBASEAPI WINBOOL WINAPI FreeEnvironmentStringsW(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dwExceptionCode,DWORD dwExceptionFlags,DWORD n_संख्या_Of_Arguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(काष्ठा _EXCEPTION_POINTERS *ExceptionInfo);

  प्रकार LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(काष्ठा _EXCEPTION_POINTERS *ExceptionInfo);
  प्रकार PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER lp_शीर्ष_Level_Exception_Filter);

#घोषणा FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(आकार_T dw_ढेर_आकार,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(आकार_T dw_ढेर_Commit_आकार,आकार_T dw_ढेर_Reserve_आकार,DWORD dwFlags,LPFIBER_START_ROUTINE lpStartAddress,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI ConvertThreadToFiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI ConvertThreadToFiberEx(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI ConvertFiberToThread(VOID);
  WINBASEAPI VOID WINAPI SwitchToFiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI SwitchToThread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ATTRIBUTES lpThreadAttributes,आकार_T dw_ढेर_आकार,LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_ATTRIBUTES lpThreadAttributes,आकार_T dw_ढेर_आकार,LPTHREAD_START_ROUTINE lpStartAddress,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI Set_Thread_ढेर_Guarantee (PULONG ढेर_आकार_In_Bytes);
  WINBASEAPI DWORD WINAPI GetProcessIdOfThread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI Get_Current_Processor_संख्या(VOID);
  WINBASEAPI DWORD_PTR WINAPI SetThreadAffinityMask(HANDLE hThread,DWORD_PTR dwThreadAffinityMask);
  WINBASEAPI DWORD WINAPI SetThreadIdealProcessor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI SetProcessPriorityBoost(HANDLE hProcess,WINBOOL bDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI GetProcessPriorityBoost(HANDLE hProcess,PBOOL pDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_TIME latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI SetThreadPriority(HANDLE hThread,पूर्णांक nPriority);
  WINBASEAPI WINBOOL WINAPI SetThreadPriorityBoost(HANDLE hThread,WINBOOL bDisablePriorityBoost);
  WINBASEAPI WINBOOL WINAPI GetThreadPriorityBoost(HANDLE hThread,PBOOL pDisablePriorityBoost);
  WINBASEAPI पूर्णांक WINAPI GetThreadPriority(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dwExitCode);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dwExitCode);
  WINBASEAPI WINBOOL WINAPI GetExitCodeThread(HANDLE hThread,LPDWORD lpExitCode);
  WINBASEAPI WINBOOL WINAPI GetThreadSelectorEntry(HANDLE hThread,DWORD dwSelector,LPLDT_ENTRY lpSelectorEntry);
  WINBASEAPI EXECUTION_STATE WINAPI SetThreadExecutionState(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI GetLastError(VOID);
  WINBASEAPI VOID WINAPI SetLastError(DWORD dwErrCode);

#अगर_अघोषित RC_INVOKED
#अगर_घोषित WINBASE_DECLARE_RESTORE_LAST_ERROR
  WINBASEAPI VOID WINAPI RestoreLastError(DWORD dwErrCode);

  प्रकार VOID (WINAPI *PRESTORE_LAST_ERROR)(DWORD);

#घोषणा RESTORE_LAST_ERROR_NAME_A "RestoreLastError"
#घोषणा RESTORE_LAST_ERROR_NAME_W L"RestoreLastError"
#घोषणा RESTORE_LAST_ERROR_NAME TEXT("RestoreLastError")
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->Internal)!=STATUS_PENDING)

  WINBASEAPI WINBOOL WINAPI Get_Overlapped_परिणाम(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lp_संख्या_Of_Bytes_Transferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI CreateIoCompletionPort(HANDLE FileHandle,HANDLE ExistingCompletionPort,ULONG_PTR Completion_कुंजी,DWORD संख्या_Of_Concurrent_Threads);
  WINBASEAPI WINBOOL WINAPI GetQueuedCompletionStatus(HANDLE CompletionPort,LPDWORD lp_संख्या_Of_Bytes_Transferred,PULONG_PTR lp_Completion_कुंजी,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI PostQueuedCompletionStatus(HANDLE CompletionPort,DWORD dw_संख्या_Of_Bytes_Transferred,ULONG_PTR dw_Completion_कुंजी,LPOVERLAPPED lpOverlapped);

#घोषणा SEM_FAILCRITICALERRORS 0x1
#घोषणा SEM_NOGPFAULTERRORBOX 0x2
#घोषणा SEM_NOALIGNMENTFAULTEXCEPT 0x4
#घोषणा SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI SetErrorMode(UINT uMode);
  WINBASEAPI WINBOOL WINAPI ReadProcessMemory(HANDLE hProcess,LPCVOID lpBaseAddress,LPVOID lp_बफर,आकार_T n_आकार,आकार_T *lp_संख्या_Of_Bytes_Read);
  WINBASEAPI WINBOOL WINAPI WriteProcessMemory(HANDLE hProcess,LPVOID lpBaseAddress,LPCVOID lp_बफर,आकार_T n_आकार,आकार_T *lp_संख्या_Of_Bytes_Written);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI SetThreadContext(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  प्रकार VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI QueueUserAPC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dw_तथ्य);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dwContinueStatus);
  WINBASEAPI WINBOOL WINAPI DebugActiveProcess(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI DebugActiveProcessStop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI DebugSetProcessKillOnExit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI Initialize_Critical_Section_And_Spin_गिनती(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_गिनती);
  WINBASEAPI DWORD WINAPI Set_Critical_Section_Spin_गिनती(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_गिनती);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI SetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG l_Release_गिनती,LPLONG lp_Previous_गिनती);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI WaitForMultipleObjects(DWORD n_गिनती,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI LoadResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI InitAtomTable(DWORD n_आकार);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI Set_Handle_गिनती(UINT u_संख्या);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI LockFile(HANDLE hFile,DWORD dw_File_Offset_निचला,DWORD dw_File_Offset_ऊपरी,DWORD n_संख्या_Of_Bytes_To_Lock_निचला,DWORD n_संख्या_Of_Bytes_To_Lock_ऊपरी);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dw_File_Offset_निचला,DWORD dw_File_Offset_ऊपरी,DWORD n_संख्या_Of_Bytes_To_Unlock_निचला,DWORD n_संख्या_Of_Bytes_To_Unlock_ऊपरी);
  WINBASEAPI WINBOOL WINAPI LockFileEx(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD n_संख्या_Of_Bytes_To_Lock_निचला,DWORD n_संख्या_Of_Bytes_To_Lock_ऊपरी,LPOVERLAPPED lpOverlapped);

#घोषणा LOCKFILE_FAIL_IMMEDIATELY 0x1
#घोषणा LOCKFILE_EXCLUSIVE_LOCK 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD n_संख्या_Of_Bytes_To_Unlock_निचला,DWORD n_संख्या_Of_Bytes_To_Unlock_ऊपरी,LPOVERLAPPED lpOverlapped);

  प्रकार काष्ठा _BY_HANDLE_FILE_INFORMATION {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD dw_Volume_Serial_संख्या;
    DWORD n_File_आकार_ऊपरी;
    DWORD n_File_आकार_निचला;
    DWORD n_संख्या_Of_Links;
    DWORD n_File_सूचकांक_ऊपरी;
    DWORD n_File_सूचकांक_निचला;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#अगर_घोषित UNICODE
#घोषणा SetFileShortName SetFileShortNameW
#अन्यथा
#घोषणा SetFileShortName SetFileShortNameA
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI Get_File_आकार(HANDLE hFile,LPDWORD lp_File_आकार_ऊपरी);
  WINBASEAPI WINBOOL WINAPI Get_File_आकार_Ex(HANDLE hFile,PLARGE_INTEGER lp_File_आकार);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI SetStdHandle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lp_बफर,DWORD n_संख्या_Of_Bytes_To_Write,LPDWORD lp_संख्या_Of_Bytes_Written,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lp_बफर,DWORD n_संख्या_Of_Bytes_To_Read,LPDWORD lp_संख्या_Of_Bytes_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dwIoControlCode,LPVOID lp_In_बफर,DWORD n_In_बफर_आकार,LPVOID lp_Out_बफर,DWORD n_Out_बफर_आकार,LPDWORD lpBytesReturned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI SetMessageWaitingIndicator(HANDLE h_संदेश_Indicator,ULONG ul_संदेश_गिनती);
  WINBASEAPI WINBOOL WINAPI SetEndOfFile(HANDLE hFile);
  WINBASEAPI DWORD WINAPI SetFilePointer(HANDLE hFile,LONG lDistanceToMove,PLONG lp_Distance_To_Move_ऊपरी,DWORD dwMoveMethod);
  WINBASEAPI WINBOOL WINAPI SetFilePointerEx(HANDLE hFile,LARGE_INTEGER liDistanceToMove,PLARGE_INTEGER lpNewFilePointer,DWORD dwMoveMethod);
  WINBASEAPI WINBOOL WINAPI FindClose(HANDLE hFindFile);
  WINBASEAPI WINBOOL WINAPI GetFileTime(HANDLE hFile,LPFILETIME lpCreationTime,LPFILETIME lpLastAccessTime,LPFILETIME lpLastWriteTime);
  WINBASEAPI WINBOOL WINAPI SetFileTime(HANDLE hFile,CONST FILETIME *lpCreationTime,CONST FILETIME *lpLastAccessTime,CONST FILETIME *lpLastWriteTime);
  WINBASEAPI WINBOOL WINAPI Set_File_Valid_तथ्य(HANDLE hFile,LONGLONG Valid_तथ्य_लंबाई);
  WINBASEAPI WINBOOL WINAPI SetFileShortNameA(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI SetFileShortNameW(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE hSourceProcessHandle,HANDLE hSourceHandle,HANDLE hTargetProcessHandle,LPHANDLE lpTargetHandle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI SetHandleInformation(HANDLE hObject,DWORD dwMask,DWORD dwFlags);

#घोषणा HANDLE_FLAG_INHERIT 0x1
#घोषणा HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#घोषणा HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI LoadModule(LPCSTR lpModuleName,LPVOID lpParameterBlock);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lp_Cmd_पंक्ति,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI SetupComm(HANDLE hFile,DWORD dwInQueue,DWORD dwOutQueue);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdw_आकार);
  WINBASEAPI WINBOOL WINAPI GetCommMask(HANDLE hFile,LPDWORD lpEvtMask);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI GetCommModemStatus(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI SetCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI SetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dw_आकार);
  WINBASEAPI WINBOOL WINAPI SetCommMask(HANDLE hFile,DWORD dwEvtMask);
  WINBASEAPI WINBOOL WINAPI SetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI SetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,अक्षर cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lpEvtMask,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI SetTapePosition(HANDLE hDevice,DWORD dwPositionMethod,DWORD dwPartition,DWORD dw_Offset_निचला,DWORD dw_Offset_ऊपरी,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI GetTapePosition(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdwPartition,LPDWORD lpdw_Offset_निचला,LPDWORD lpdw_Offset_ऊपरी);
  WINBASEAPI DWORD WINAPI PrepareTape(HANDLE hDevice,DWORD dwOperation,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI EraseTape(HANDLE hDevice,DWORD dwEraseType,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI CreateTapePartition(HANDLE hDevice,DWORD dwPartitionMethod,DWORD dw_गिनती,DWORD dw_आकार);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dw_Tapemark_गिनती,WINBOOL bImmediate);
  WINBASEAPI DWORD WINAPI GetTapeStatus(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI GetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdw_आकार,LPVOID lpTapeInformation);

#घोषणा GET_TAPE_MEDIA_INFORMATION 0
#घोषणा GET_TAPE_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI SetTapeParameters(HANDLE hDevice,DWORD dwOperation,LPVOID lpTapeInformation);

#घोषणा SET_TAPE_MEDIA_INFORMATION 0
#घोषणा SET_TAPE_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI पूर्णांक WINAPI MulDiv(पूर्णांक n_संख्या,पूर्णांक nNumerator,पूर्णांक nDenominator);
  WINBASEAPI VOID WINAPI GetSystemTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI VOID WINAPI GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime);
  WINBASEAPI WINBOOL WINAPI SetSystemTime(CONST SYSTEMTIME *lpSystemTime);
  WINBASEAPI VOID WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI WINBOOL WINAPI SetLocalTime(CONST SYSTEMTIME *lpSystemTime);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI Set_System_File_Cache_आकार(आकार_T Minimum_File_Cache_आकार,आकार_T Maximum_File_Cache_आकार,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI Get_System_File_Cache_आकार(PSIZE_T lp_Minimum_File_Cache_आकार,PSIZE_T lp_Maximum_File_Cache_आकार,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdwQuotaUsed);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lpIdleTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  प्रकार काष्ठा _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } TIME_ZONE_INFORMATION,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#अगर_घोषित UNICODE
#घोषणा FormatMessage FormatMessageW
#अन्यथा
#घोषणा FormatMessage FormatMessageA
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI SystemTimeToTzSpecificLocalTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpUniversalTime,LPSYSTEMTIME lpLocalTime);
  WINBASEAPI WINBOOL WINAPI TzSpecificLocalTimeToSystemTime(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpLocalTime,LPSYSTEMTIME lpUniversalTime);
  WINBASEAPI DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI SetTimeZoneInformation(CONST TIME_ZONE_INFORMATION *lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI SystemTimeToFileTime(CONST SYSTEMTIME *lpSystemTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI FileTimeToLocalFileTime(CONST FILETIME *lpFileTime,LPFILETIME lpLocalFileTime);
  WINBASEAPI WINBOOL WINAPI LocalFileTimeToFileTime(CONST FILETIME *lpLocalFileTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI FileTimeToSystemTime(CONST FILETIME *lpFileTime,LPSYSTEMTIME lpSystemTime);
  WINBASEAPI LONG WINAPI CompareFileTime(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI FileTimeToDosDateTime(CONST FILETIME *lpFileTime,LPWORD lpFatDate,LPWORD lpFatTime);
  WINBASEAPI WINBOOL WINAPI DosDateTimeToFileTime(WORD wFatDate,WORD wFatTime,LPFILETIME lpFileTime);
  WINBASEAPI DWORD WINAPI Get_Tick_गिनती(VOID);
  WINBASEAPI WINBOOL WINAPI SetSystemTimeAdjustment(DWORD dwTimeAdjustment,WINBOOL bTimeAdjustmentDisabled);
  WINBASEAPI WINBOOL WINAPI GetSystemTimeAdjustment(PDWORD lpTimeAdjustment,PDWORD lpTimeIncrement,PBOOL lpTimeAdjustmentDisabled);
  WINBASEAPI DWORD WINAPI FormatMessageA(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPSTR lp_बफर,DWORD n_आकार,बहु_सूची *Arguments);
  WINBASEAPI DWORD WINAPI FormatMessageW(DWORD dwFlags,LPCVOID lpSource,DWORD dwMessageId,DWORD dwLanguageId,LPWSTR lp_बफर,DWORD n_आकार,बहु_सूची *Arguments);

#घोषणा FORMAT_MESSAGE_ALLOCATE_बफर 0x100
#घोषणा FORMAT_MESSAGE_IGNORE_INSERTS 0x200
#घोषणा FORMAT_MESSAGE_FROM_STRING 0x400
#घोषणा FORMAT_MESSAGE_FROM_HMODULE 0x800
#घोषणा FORMAT_MESSAGE_FROM_SYSTEM 0x1000
#घोषणा FORMAT_MESSAGE_ARGUMENT_ARRAY 0x2000
#घोषणा FORMAT_MESSAGE_MAX_WIDTH_MASK 0xff

#अगर_घोषित UNICODE
#घोषणा CreateMailslot CreateMailslotW
#घोषणा EncryptFile EncryptFileW
#घोषणा DecryptFile DecryptFileW
#घोषणा FileEncryptionStatus FileEncryptionStatusW
#अन्यथा
#घोषणा CreateMailslot CreateMailslotA
#घोषणा EncryptFile EncryptFileA
#घोषणा DecryptFile DecryptFileA
#घोषणा FileEncryptionStatus FileEncryptionStatusA
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_ATTRIBUTES lpPipeAttributes,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI SetNamedPipeHandleState(HANDLE hNamedPipe,LPDWORD lpMode,LPDWORD lp_Max_Collection_गिनती,LPDWORD lp_Collect_तथ्य_Timeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lp_Out_बफर_आकार,LPDWORD lp_In_बफर_आकार,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lp_बफर,DWORD n_बफर_आकार,LPDWORD lpBytesRead,LPDWORD lp_योग_Bytes_Avail,LPDWORD lp_Bytes_बायाँ_This_Message);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lp_In_बफर,DWORD n_In_बफर_आकार,LPVOID lp_Out_बफर,DWORD n_Out_बफर_आकार,LPDWORD lpBytesRead,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD n_Max_Message_आकार,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD n_Max_Message_आकार,DWORD lReadTimeout,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lp_Max_Message_आकार,LPDWORD lp_अग्र_आकार,LPDWORD lp_Message_गिनती,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI SetMailslotInfo(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI MapViewOfFile(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_Offset_ऊपरी,DWORD dw_File_Offset_निचला,आकार_T dw_संख्या_Of_Bytes_To_Map);
  WINBASEAPI WINBOOL WINAPI FlushViewOfFile(LPCVOID lpBaseAddress,आकार_T dw_संख्या_Of_Bytes_To_Flush);
  WINBASEAPI WINBOOL WINAPI UnmapViewOfFile(LPCVOID lpBaseAddress);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#घोषणा FILE_ENCRYPTABLE 0
#घोषणा FILE_IS_ENCRYPTED 1
#घोषणा FILE_SYSTEM_ATTR 2
#घोषणा FILE_मूल_DIR 3
#घोषणा FILE_SYSTEM_DIR 4
#घोषणा FILE_UNKNOWN 5
#घोषणा FILE_SYSTEM_NOT_SUPPORT 6
#घोषणा FILE_USER_DISALLOWED 7
#घोषणा FILE_READ_ONLY 8
#घोषणा FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI FileEncryptionStatusA(LPCSTR lpFileName,LPDWORD lpStatus);
  WINADVAPI WINBOOL WINAPI FileEncryptionStatusW(LPCWSTR lpFileName,LPDWORD lpStatus);

#घोषणा EFS_USE_RECOVERY_कुंजियाँ (0x1)

  प्रकार DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pb_तथ्य,PVOID pvCallbackContext,ULONG ul_लंबाई);
  प्रकार DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pb_तथ्य,PVOID pvCallbackContext,PULONG ul_लंबाई);

#घोषणा CREATE_FOR_IMPORT (1)
#घोषणा CREATE_FOR_DIR (2)
#घोषणा OVERWRITE_HIDDEN (4)

#अगर_घोषित UNICODE
#घोषणा OpenEncryptedFileRaw OpenEncryptedFileRawW
#घोषणा lstrcmp lstrcmpW
#घोषणा lstrcmpi lstrcmpiW
#घोषणा lstrcpyn lstrcpynW
#घोषणा lstrcpy lstrcpyW
#घोषणा lstrcat lstrcatW
#घोषणा lstrlen lstrlenW
#अन्यथा
#घोषणा OpenEncryptedFileRaw OpenEncryptedFileRawA
#घोषणा lstrcmp lstrcmpA
#घोषणा lstrcmpi lstrcmpiA
#घोषणा lstrcpyn lstrcpynA
#घोषणा lstrcpy lstrcpyA
#घोषणा lstrcat lstrcatA
#घोषणा lstrlen lstrlenA
#पूर्ण_अगर

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI पूर्णांक WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI पूर्णांक WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI पूर्णांक WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI पूर्णांक WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,पूर्णांक i_Max_लंबाई);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,पूर्णांक i_Max_लंबाई);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI पूर्णांक WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI पूर्णांक WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lpPathName,पूर्णांक iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lpPathName,पूर्णांक iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lp_बफर,UINT uBytes);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lp_बफर,UINT uBytes);
  WINBASEAPI दीर्घ WINAPI _hread(HFILE hFile,LPVOID lp_बफर,दीर्घ lBytes);
  WINBASEAPI दीर्घ WINAPI _hwrite(HFILE hFile,LPCCH lp_बफर,दीर्घ lBytes);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG lOffset,पूर्णांक iOrigin);
  WINADVAPI WINBOOL WINAPI IsTextUnicode(CONST VOID *lpv,पूर्णांक i_आकार,LPINT lpi_परिणाम);

#घोषणा FLS_OUT_OF_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI Fls_Get_मूल्य(DWORD dw_Fls_सूचकांक);
  WINBASEAPI WINBOOL WINAPI Fls_Set_मूल्य(DWORD dw_Fls_सूचकांक,PVOID lp_Fls_तथ्य);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dw_Fls_सूचकांक);

#घोषणा TLS_OUT_OF_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI Tls_Get_मूल्य(DWORD dw_Tls_सूचकांक);
  WINBASEAPI WINBOOL WINAPI Tls_Set_मूल्य(DWORD dw_Tls_सूचकांक,LPVOID lp_Tls_मूल्य);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dw_Tls_सूचकांक);

  प्रकार VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dwErrorCode,DWORD dw_संख्या_Of_Bytes_Transfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForMultipleObjectsEx(DWORD n_गिनती,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE hObjectToSignal,HANDLE hObjectToWaitOn,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lp_बफर,DWORD n_संख्या_Of_Bytes_To_Read,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lp_बफर,DWORD n_संख्या_Of_Bytes_To_Write,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lp_बफर,DWORD n_संख्या_Of_Bytes_To_Read,LPDWORD lp_संख्या_Of_Bytes_Read,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dw_निचला_Bytes_To_Seek,DWORD dw_ऊपरी_Bytes_To_Seek,LPDWORD lpdw_निचला_Byte_Seeked,LPDWORD lpdw_ऊपरी_Byte_Seeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lp_बफर,DWORD n_संख्या_Of_Bytes_To_Write,LPDWORD lp_संख्या_Of_Bytes_Written,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  प्रकार काष्ठा _WIN32_STREAM_ID {
    DWORD dwStreamId;
    DWORD dwStreamAttributes;
    LARGE_INTEGER आकार_3;
    DWORD dw_Stream_Name_आकार;
    WCHAR cStreamName[ANYSIZE_ARRAY];
  } WIN32_STREAM_ID,*LPWIN32_STREAM_ID;

#घोषणा BACKUP_INVALID 0x0
#घोषणा BACKUP_तथ्य 0x1
#घोषणा BACKUP_EA_तथ्य 0x2
#घोषणा BACKUP_SECURITY_तथ्य 0x3
#घोषणा BACKUP_ALTERNATE_तथ्य 0x4
#घोषणा BACKUP_LINK 0x5
#घोषणा BACKUP_PROPERTY_तथ्य 0x6
#घोषणा BACKUP_OBJECT_ID 0x7
#घोषणा BACKUP_REPARSE_तथ्य 0x8
#घोषणा BACKUP_SPARSE_BLOCK 0x9

#घोषणा STREAM_NORMAL_ATTRIBUTE 0x0
#घोषणा STREAM_MODIFIED_WHEN_READ 0x1
#घोषणा STREAM_CONTAINS_SECURITY 0x2
#घोषणा STREAM_CONTAINS_PROPERTIES 0x4
#घोषणा STREAM_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_संख्या_Of_Bytes_To_Read,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_संख्या_Of_Bytes_To_Write,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#घोषणा STARTF_USESHOWWINDOW 0x1
#घोषणा STARTF_USESIZE 0x2
#घोषणा STARTF_USEPOSITION 0x4
#घोषणा STARTF_USECOUNTCHARS 0x8
#घोषणा STARTF_USEFILLATTRIBUTE 0x10
#घोषणा STARTF_RUNFULLSCREEN 0x20
#घोषणा STARTF_FORCEONFEEDBACK 0x40
#घोषणा STARTF_FORCEOFFFEEDBACK 0x80
#घोषणा STARTF_USESTDHANDLES 0x100

#घोषणा STARTF_USEHOTKEY 0x200

  प्रकार काष्ठा _STARTUPINFOA {
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
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_निवेश;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOA,*LPSTARTUPINFOA;

  प्रकार काष्ठा _STARTUPINFOW {
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
    WORD wShowWindow;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_निवेश;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#अगर_घोषित UNICODE
  प्रकार STARTUPINFOW STARTUPINFO;
  प्रकार LPSTARTUPINFOW LPSTARTUPINFO;
#अन्यथा
  प्रकार STARTUPINFOA STARTUPINFO;
  प्रकार LPSTARTUPINFOA LPSTARTUPINFO;
#पूर्ण_अगर

#घोषणा SHUTDOWN_NORETRY 0x1

  प्रकार काष्ठा _WIN32_FIND_DATAA {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD n_File_आकार_ऊपरी;
    DWORD n_File_आकार_निचला;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_PATH];
    CHAR cAlternateFileName[14];
  } WIN32_FIND_DATAA,*PWIN32_FIND_DATAA,*LPWIN32_FIND_DATAA;

  प्रकार काष्ठा _WIN32_FIND_DATAW {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD n_File_आकार_ऊपरी;
    DWORD n_File_आकार_निचला;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_PATH];
    WCHAR cAlternateFileName[14];
  } WIN32_FIND_DATAW,*PWIN32_FIND_DATAW,*LPWIN32_FIND_DATAW;

#अगर_घोषित UNICODE
  प्रकार WIN32_FIND_DATAW WIN32_FIND_तथ्य;
  प्रकार PWIN32_FIND_DATAW PWIN32_FIND_तथ्य;
  प्रकार LPWIN32_FIND_DATAW LPWIN32_FIND_तथ्य;
#अन्यथा
  प्रकार WIN32_FIND_DATAA WIN32_FIND_तथ्य;
  प्रकार PWIN32_FIND_DATAA PWIN32_FIND_तथ्य;
  प्रकार LPWIN32_FIND_DATAA LPWIN32_FIND_तथ्य;
#पूर्ण_अगर

  प्रकार काष्ठा WIN32_FILE_ATTRIBUTE_तथ्य {
    DWORD dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD n_File_आकार_ऊपरी;
    DWORD n_File_आकार_निचला;
  } WIN32_FILE_ATTRIBUTE_तथ्य_2,*LPWIN32_FILE_ATTRIBUTE_तथ्य;

#अगर_घोषित UNICODE
#घोषणा CreateMutex CreateMutexW
#घोषणा OpenMutex OpenMutexW
#घोषणा CreateEvent CreateEventW
#घोषणा OpenEvent OpenEventW
#घोषणा CreateSemaphore CreateSemaphoreW
#घोषणा OpenSemaphore OpenSemaphoreW
#अन्यथा
#घोषणा CreateMutex CreateMutexA
#घोषणा OpenMutex OpenMutexA
#घोषणा CreateEvent CreateEventA
#घोषणा OpenEvent OpenEventA
#घोषणा CreateSemaphore CreateSemaphoreA
#घोषणा OpenSemaphore OpenSemaphoreA
#पूर्ण_अगर

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG l_Initial_गिनती,LONG l_Maximum_गिनती,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,LONG l_Initial_गिनती,LONG l_Maximum_गिनती,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  प्रकार VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lpArgToCompletionRoutine,DWORD dw_Timer_निचला_मूल्य,DWORD dw_Timer_ऊपरी_मूल्य);

#अगर_घोषित UNICODE
#घोषणा CreateWaitableTimer CreateWaitableTimerW
#घोषणा OpenWaitableTimer OpenWaitableTimerW
#घोषणा CreateFileMapping CreateFileMappingW
#घोषणा OpenFileMapping OpenFileMappingW
#घोषणा GetLogicalDriveStrings GetLogicalDriveStringsW
#घोषणा LoadLibrary LoadLibraryW
#घोषणा LoadLibraryEx LoadLibraryExW
#घोषणा GetModuleFileName GetModuleFileNameW
#घोषणा GetModuleHandle GetModuleHandleW
#अन्यथा
#घोषणा CreateWaitableTimer CreateWaitableTimerA
#घोषणा OpenWaitableTimer OpenWaitableTimerA
#घोषणा CreateFileMapping CreateFileMappingA
#घोषणा OpenFileMapping OpenFileMappingA
#घोषणा GetLogicalDriveStrings GetLogicalDriveStringsA
#घोषणा LoadLibrary LoadLibraryA
#घोषणा LoadLibraryEx LoadLibraryExA
#घोषणा GetModuleFileName GetModuleFileNameA
#घोषणा GetModuleHandle GetModuleHandleA
#पूर्ण_अगर

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ATTRIBUTES lpTimerAttributes,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ATTRIBUTES lpTimerAttributes,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI SetWaitableTimer(HANDLE hTimer,स्थिर LARGE_INTEGER *lpDueTime,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lpArgToCompletionRoutine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dw_Maximum_आकार_ऊपरी,DWORD dw_Maximum_आकार_निचला,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_ATTRIBUTES lpFileMappingAttributes,DWORD flProtect,DWORD dw_Maximum_आकार_ऊपरी,DWORD dw_Maximum_आकार_निचला,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI GetLogicalDriveStringsA(DWORD n_बफर_लंबाई,LPSTR lp_बफर);
  WINBASEAPI DWORD WINAPI GetLogicalDriveStringsW(DWORD n_बफर_लंबाई,LPWSTR lp_बफर);

  प्रकार क्रमागत _MEMORY_RESOURCE_NOTIFICATION_TYPE {
    निचला_Memory_Resource_Notification,ऊपरी_Memory_Resource_Notification
  } MEMORY_RESOURCE_NOTIFICATION_TYPE;

  WINBASEAPI HANDLE WINAPI CreateMemoryResourceNotification(MEMORY_RESOURCE_NOTIFICATION_TYPE NotificationType);
  WINBASEAPI WINBOOL WINAPI QueryMemoryResourceNotification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI LoadLibraryA(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI LoadLibraryW(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI LoadLibraryExA(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI LoadLibraryExW(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#घोषणा DONT_RESOLVE_DLL_REFERENCES 0x1
#घोषणा LOAD_LIBRARY_AS_DATAFILE 0x2
#घोषणा LOAD_WITH_ALTERED_खोज_PATH 0x8
#घोषणा LOAD_IGNORE_CODE_AUTHZ_LEVEL 0x10
#घोषणा LOAD_LIBRARY_AS_IMAGE_RESOURCE 0x20
#घोषणा LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40
#घोषणा LOAD_LIBRARY_REQUIRE_SIGNED_TARGET 0x80
#घोषणा LOAD_LIBRARY_खोज_DLL_LOAD_DIR 0x100
#घोषणा LOAD_LIBRARY_खोज_APPLICATION_DIR 0x200
#घोषणा LOAD_LIBRARY_खोज_USER_DIRS 0x400
#घोषणा LOAD_LIBRARY_खोज_SYSTEM32 0x800
#घोषणा LOAD_LIBRARY_खोज_DEFAULT_DIRS 0x1000
#घोषणा LOAD_LIBRARY_SAFE_CURRENT_DIRS 0x2000

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD n_आकार);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#अगर_अघोषित RC_INVOKED
#घोषणा GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#घोषणा GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#घोषणा GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS (0x4)

  प्रकार WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  प्रकार WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#अगर_घोषित UNICODE
#घोषणा PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#घोषणा GetModuleHandleEx GetModuleHandleExW
#अन्यथा
#घोषणा PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#घोषणा GetModuleHandleEx GetModuleHandleExA
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#पूर्ण_अगर

#अगर_घोषित UNICODE
#घोषणा NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathW
#घोषणा CreateProcess CreateProcessW
#घोषणा FatalAppExit FatalAppExitW
#घोषणा GetStartupInfo GetStartupInfoW
#घोषणा Get_Command_पंक्ति Get_Command_पंक्ति_W
#घोषणा GetEnvironmentVariable GetEnvironmentVariableW
#घोषणा SetEnvironmentVariable SetEnvironmentVariableW
#घोषणा ExpandEnvironmentStrings ExpandEnvironmentStringsW
#घोषणा GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#घोषणा SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableW
#घोषणा OutputDebugString OutputDebugStringW
#घोषणा FindResource FindResourceW
#घोषणा FindResourceEx FindResourceExW
#अन्यथा
#घोषणा NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathA
#घोषणा CreateProcess CreateProcessA
#घोषणा FatalAppExit FatalAppExitA
#घोषणा GetStartupInfo GetStartupInfoA
#घोषणा Get_Command_पंक्ति Get_Command_पंक्ति_A
#घोषणा GetEnvironmentVariable GetEnvironmentVariableA
#घोषणा SetEnvironmentVariable SetEnvironmentVariableA
#घोषणा ExpandEnvironmentStrings ExpandEnvironmentStringsA
#घोषणा GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#घोषणा SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableA
#घोषणा OutputDebugString OutputDebugStringA
#घोषणा FindResource FindResourceA
#घोषणा FindResourceEx FindResourceExA
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI NeedCurrentDirectoryForExePathA(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI NeedCurrentDirectoryForExePathW(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lp_Command_पंक्ति,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lp_Command_पंक्ति,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI AddLocalAlternateComputerNameA(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI AddLocalAlternateComputerNameW(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI SetProcessShutdownParameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI GetProcessVersion(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lpMessageText);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lpMessageText);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI Get_Command_पंक्ति_A(VOID);
  WINBASEAPI LPWSTR WINAPI Get_Command_पंक्ति_W(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lp_बफर,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lp_बफर,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentVariableA(LPCSTR lpName,LPCSTR lp_मूल्य);
  WINBASEAPI WINBOOL WINAPI SetEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lp_मूल्य);
  WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsA(LPCSTR lpSrc,LPSTR lpDst,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI ExpandEnvironmentStringsW(LPCWSTR lpSrc,LPWSTR lpDst,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_बफर,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_बफर,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI SetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_मूल्य,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI SetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_मूल्य,DWORD n_आकार);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI FindResourceA(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceW(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceExA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage);
  WINBASEAPI HRSRC WINAPI FindResourceExW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage);

#अगर_घोषित UNICODE
#घोषणा ENUMRESTYPEPROC ENUMRESTYPEPROCW
#घोषणा ENUMRESNAMEPROC ENUMRESNAMEPROCW
#घोषणा ENUMRESLANGPROC ENUMRESLANGPROCW
#घोषणा EnumResourceTypes EnumResourceTypesW
#घोषणा EnumResourceNames EnumResourceNamesW
#घोषणा EnumResourceLanguages EnumResourceLanguagesW
#घोषणा BeginUpdateResource BeginUpdateResourceW
#घोषणा UpdateResource UpdateResourceW
#घोषणा EndUpdateResource EndUpdateResourceW
#घोषणा GlobalAddAtom GlobalAddAtomW
#घोषणा GlobalFindAtom GlobalFindAtomW
#घोषणा GlobalGetAtomName GlobalGetAtomNameW
#घोषणा AddAtom AddAtomW
#घोषणा FindAtom FindAtomW
#घोषणा GetAtomName GetAtomNameW
#घोषणा GetProfileInt GetProfileIntW
#घोषणा GetProfileString GetProfileStringW
#घोषणा WriteProfileString WriteProfileStringW
#घोषणा GetProfileSection GetProfileSectionW
#घोषणा WriteProfileSection WriteProfileSectionW
#घोषणा GetPrivateProfileInt GetPrivateProfileIntW
#घोषणा GetPrivateProfileString GetPrivateProfileStringW
#घोषणा WritePrivateProfileString WritePrivateProfileStringW
#घोषणा GetPrivateProfileSection GetPrivateProfileSectionW
#घोषणा WritePrivateProfileSection WritePrivateProfileSectionW
#घोषणा GetPrivateProfileSectionNames GetPrivateProfileSectionNamesW
#घोषणा GetPrivateProfileStruct GetPrivateProfileStructW
#घोषणा WritePrivateProfileStruct WritePrivateProfileStructW
#घोषणा GetDriveType GetDriveTypeW
#घोषणा GetSystemDirectory GetSystemDirectoryW
#घोषणा Get_अस्थायी_Path Get_अस्थायी_Path_W
#घोषणा Get_अस्थायी_File_Name Get_अस्थायी_File_Name_W
#घोषणा GetWindowsDirectory GetWindowsDirectoryW
#घोषणा GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#घोषणा AddLocalAlternateComputerName AddLocalAlternateComputerNameW
#अन्यथा
#घोषणा ENUMRESTYPEPROC ENUMRESTYPEPROCA
#घोषणा ENUMRESNAMEPROC ENUMRESNAMEPROCA
#घोषणा ENUMRESLANGPROC ENUMRESLANGPROCA
#घोषणा EnumResourceTypes EnumResourceTypesA
#घोषणा EnumResourceNames EnumResourceNamesA
#घोषणा EnumResourceLanguages EnumResourceLanguagesA
#घोषणा BeginUpdateResource BeginUpdateResourceA
#घोषणा UpdateResource UpdateResourceA
#घोषणा EndUpdateResource EndUpdateResourceA
#घोषणा GlobalAddAtom GlobalAddAtomA
#घोषणा GlobalFindAtom GlobalFindAtomA
#घोषणा GlobalGetAtomName GlobalGetAtomNameA
#घोषणा AddAtom AddAtomA
#घोषणा FindAtom FindAtomA
#घोषणा GetAtomName GetAtomNameA
#घोषणा GetProfileInt GetProfileIntA
#घोषणा GetProfileString GetProfileStringA
#घोषणा WriteProfileString WriteProfileStringA
#घोषणा GetProfileSection GetProfileSectionA
#घोषणा WriteProfileSection WriteProfileSectionA
#घोषणा GetPrivateProfileInt GetPrivateProfileIntA
#घोषणा GetPrivateProfileString GetPrivateProfileStringA
#घोषणा WritePrivateProfileString WritePrivateProfileStringA
#घोषणा GetPrivateProfileSection GetPrivateProfileSectionA
#घोषणा WritePrivateProfileSection WritePrivateProfileSectionA
#घोषणा GetPrivateProfileSectionNames GetPrivateProfileSectionNamesA
#घोषणा GetPrivateProfileStruct GetPrivateProfileStructA
#घोषणा WritePrivateProfileStruct WritePrivateProfileStructA
#घोषणा GetDriveType GetDriveTypeA
#घोषणा GetSystemDirectory GetSystemDirectoryA
#घोषणा Get_अस्थायी_Path Get_अस्थायी_Path_A
#घोषणा Get_अस्थायी_File_Name Get_अस्थायी_File_Name_A
#घोषणा GetWindowsDirectory GetWindowsDirectoryA
#घोषणा GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#घोषणा AddLocalAlternateComputerName AddLocalAlternateComputerNameA
#पूर्ण_अगर

  प्रकार WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  प्रकार WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  प्रकार WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  प्रकार WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  प्रकार WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LONG_PTR lParam);
  प्रकार WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceNamesA(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceNamesW(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LPVOID lp_तथ्य,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LPVOID lp_तथ्य,DWORD cb);
  WINBASEAPI WINBOOL WINAPI EndUpdateResourceA(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI EndUpdateResourceW(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI GlobalAddAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalAddAtomW(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lp_बफर,पूर्णांक n_आकार);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lp_बफर,पूर्णांक n_आकार);
  WINBASEAPI ATOM WINAPI AddAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI AddAtomW(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lp_बफर,पूर्णांक n_आकार);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lp_बफर,पूर्णांक n_आकार);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lp_कुंजी_Name,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_कुंजी_Name,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lp_कुंजी_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_कुंजी_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lp_कुंजी_Name,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_कुंजी_Name,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetPrivateProfileIntA(LPCSTR lpAppName,LPCSTR lp_कुंजी_Name,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI GetPrivateProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_कुंजी_Name,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileStringA(LPCSTR lpAppName,LPCSTR lp_कुंजी_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_आकार,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_कुंजी_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_आकार,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStringA(LPCSTR lpAppName,LPCSTR lp_कुंजी_Name,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_कुंजी_Name,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_आकार,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_आकार,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileSectionA(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesA(LPSTR lpsz_Return_बफर,DWORD n_आकार,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetPrivateProfileSectionNamesW(LPWSTR lpsz_Return_बफर,DWORD n_आकार,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI GetPrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpsz_कुंजी,LPVOID lpStruct,UINT u_आकार_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI GetPrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpsz_कुंजी,LPVOID lpStruct,UINT u_आकार_Struct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStructA(LPCSTR lpszSection,LPCSTR lpsz_कुंजी,LPVOID lpStruct,UINT u_आकार_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI WritePrivateProfileStructW(LPCWSTR lpszSection,LPCWSTR lpsz_कुंजी,LPVOID lpStruct,UINT u_आकार_Struct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lp_मूल_Path_Name);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lp_मूल_Path_Name);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lp_बफर,UINT u_आकार);
  WINBASEAPI DWORD WINAPI Get_अस्थायी_Path_A(DWORD n_बफर_लंबाई,LPSTR lp_बफर);
  WINBASEAPI DWORD WINAPI Get_अस्थायी_Path_W(DWORD n_बफर_लंबाई,LPWSTR lp_बफर);
  WINBASEAPI UINT WINAPI Get_अस्थायी_File_Name_A(LPCSTR lpPathName,LPCSTR lpPrefixString,UINT uUnique,LPSTR lp_अस्थायी_File_Name);
  WINBASEAPI UINT WINAPI Get_अस्थायी_File_Name_W(LPCWSTR lpPathName,LPCWSTR lpPrefixString,UINT uUnique,LPWSTR lp_अस्थायी_File_Name);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lp_बफर,UINT u_आकार);

#अगर_अघोषित RC_INVOKED
#अगर_घोषित UNICODE
#घोषणा GetSystemWow64Directory GetSystemWow64DirectoryW
#अन्यथा
#घोषणा GetSystemWow64Directory GetSystemWow64DirectoryA
#पूर्ण_अगर

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lp_बफर,UINT u_आकार);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *Old_मूल्य);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID Ol_मूल्य);

  प्रकार UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lp_बफर,UINT u_आकार);
  प्रकार UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lp_बफर,UINT u_आकार);

#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")

#अगर_घोषित UNICODE
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#अन्यथा
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#घोषणा GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित UNICODE
#घोषणा SetCurrentDirectory SetCurrentDirectoryW
#घोषणा GetCurrentDirectory GetCurrentDirectoryW
#घोषणा SetDllDirectory SetDllDirectoryW
#घोषणा GetDllDirectory GetDllDirectoryW
#घोषणा GetDiskFreeSpace GetDiskFreeSpaceW
#घोषणा GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#घोषणा CreateDirectory CreateDirectoryW
#घोषणा CreateDirectoryEx CreateDirectoryExW
#घोषणा RemoveDirectory RemoveDirectoryW
#घोषणा GetFullPathName GetFullPathNameW
#घोषणा DefineDosDevice DefineDosDeviceW
#घोषणा QueryDosDevice QueryDosDeviceW
#घोषणा CreateFile CreateFileW
#घोषणा SetFileAttributes SetFileAttributesW
#घोषणा GetFileAttributes GetFileAttributesW
#अन्यथा
#घोषणा SetCurrentDirectory SetCurrentDirectoryA
#घोषणा GetCurrentDirectory GetCurrentDirectoryA
#घोषणा SetDllDirectory SetDllDirectoryA
#घोषणा GetDllDirectory GetDllDirectoryA
#घोषणा GetDiskFreeSpace GetDiskFreeSpaceA
#घोषणा GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#घोषणा CreateDirectory CreateDirectoryA
#घोषणा CreateDirectoryEx CreateDirectoryExA
#घोषणा RemoveDirectory RemoveDirectoryA
#घोषणा GetFullPathName GetFullPathNameA
#घोषणा DefineDosDevice DefineDosDeviceA
#घोषणा QueryDosDevice QueryDosDeviceA
#घोषणा CreateFile CreateFileA
#घोषणा SetFileAttributes SetFileAttributesA
#घोषणा GetFileAttributes GetFileAttributesA
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI SetCurrentDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI SetCurrentDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD n_बफर_लंबाई,LPSTR lp_बफर);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD n_बफर_लंबाई,LPWSTR lp_बफर);
  WINBASEAPI WINBOOL WINAPI SetDllDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI SetDllDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD n_बफर_लंबाई,LPSTR lp_बफर);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD n_बफर_लंबाई,LPWSTR lp_बफर);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lp_मूल_Path_Name,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lp_संख्या_Of_Free_Clusters,LPDWORD lp_योग_संख्या_Of_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lp_मूल_Path_Name,LPDWORD lpSectorsPerCluster,LPDWORD lpBytesPerSector,LPDWORD lp_संख्या_Of_Free_Clusters,LPDWORD lp_योग_संख्या_Of_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lpFreeBytesAvailableToCaller,PULARGE_INTEGER lp_योग_संख्या_Of_Bytes,PULARGE_INTEGER lp_योग_संख्या_Of_Free_Bytes);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lpFreeBytesAvailableToCaller,PULARGE_INTEGER lp_योग_संख्या_Of_Bytes,PULARGE_INTEGER lp_योग_संख्या_Of_Free_Bytes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lpPathName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lpPathName);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lpPathName);
  WINBASEAPI DWORD WINAPI GetFullPathNameA(LPCSTR lpFileName,DWORD n_बफर_लंबाई,LPSTR lp_बफर,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI GetFullPathNameW(LPCWSTR lpFileName,DWORD n_बफर_लंबाई,LPWSTR lp_बफर,LPWSTR *lpFilePart);

#घोषणा DDD_RAW_TARGET_PATH 0x1
#घोषणा DDD_REMOVE_DEFINITION 0x2
#घोषणा DDD_EXACT_MATCH_ON_REMOVE 0x4
#घोषणा DDD_NO_BROADCAST_SYSTEM 0x8
#घोषणा DDD_LUID_BROADCAST_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lpTargetPath);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lpTargetPath);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lpTargetPath,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lpTargetPath,DWORD ucchMax);

#घोषणा EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dwShareMode,DWORD dwFlagsAndAttributes);
  WINBASEAPI WINBOOL WINAPI SetFileAttributesA(LPCSTR lpFileName,DWORD dwFileAttributes);
  WINBASEAPI WINBOOL WINAPI SetFileAttributesW(LPCWSTR lpFileName,DWORD dwFileAttributes);
  WINBASEAPI DWORD WINAPI GetFileAttributesA(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI GetFileAttributesW(LPCWSTR lpFileName);

  प्रकार क्रमागत _GET_FILEEX_INFO_LEVELS {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_LEVELS;

#अगर_घोषित UNICODE
#घोषणा GetFileAttributesEx GetFileAttributesExW
#घोषणा Get_Compressed_File_आकार Get_Compressed_File_आकार_W
#घोषणा DeleteFile DeleteFileW
#घोषणा CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#अन्यथा
#घोषणा GetFileAttributesEx GetFileAttributesExA
#घोषणा Get_Compressed_File_आकार Get_Compressed_File_आकार_A
#घोषणा DeleteFile DeleteFileA
#घोषणा CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI GetFileAttributesExA(LPCSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI GetFileAttributesExW(LPCWSTR lpFileName,GET_FILEEX_INFO_LEVELS fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_आकार_A(LPCSTR lpFileName,LPDWORD lp_File_आकार_ऊपरी);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_आकार_W(LPCWSTR lpFileName,LPDWORD lp_File_आकार_ऊपरी);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD Oem_Name_आकार,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD Oem_Name_आकार,PBOOL pbNameContainsSpaces,PBOOL pbNameLegal);

  प्रकार क्रमागत _FINDEX_INFO_LEVELS {
    FindExInfoStandard,FindExInfoMaxInfoLevel
  } FINDEX_INFO_LEVELS;

  प्रकार क्रमागत FINDEX_खोज_OPS {
    Find_Ex_खोज_Name_Match,Find_Ex_खोज_Limit_To_Directories,Find_Ex_खोज_Limit_To_Devices,Find_Ex_खोज_Max_खोज_Op
  } FINDEX_खोज_OPS_2;

#घोषणा FIND_FIRST_EX_CASE_SENSITIVE 0x1

#अगर_घोषित UNICODE
#घोषणा FindFirstFileEx FindFirstFileExW
#घोषणा FindFirstFile FindFirstFileW
#घोषणा Find_अग्र_File Find_अग्र_File_W
#घोषणा खोज_Path खोज_Path_W
#घोषणा CopyFile CopyFileW
#घोषणा CopyFileEx CopyFileExW
#घोषणा MoveFile MoveFileW
#घोषणा MoveFileEx MoveFileExW
#घोषणा MoveFileWithProgress MoveFileWithProgressW
#घोषणा ReplaceFile ReplaceFileW
#घोषणा CreateHardLink CreateHardLinkW
#घोषणा CreateNamedPipe CreateNamedPipeW
#घोषणा GetNamedPipeHandleState GetNamedPipeHandleStateW
#घोषणा CallNamedPipe CallNamedPipeW
#घोषणा WaitNamedPipe WaitNamedPipeW
#घोषणा SetVolumeLabel SetVolumeLabelW
#घोषणा GetVolumeInformation GetVolumeInformationW
#घोषणा ClearEventLog ClearEventLogW
#घोषणा BackupEventLog BackupEventLogW
#घोषणा OpenEventLog OpenEventLogW
#घोषणा RegisterEventSource RegisterEventSourceW
#घोषणा OpenBackupEventLog OpenBackupEventLogW
#घोषणा ReadEventLog ReadEventLogW
#घोषणा ReportEvent ReportEventW
#घोषणा AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#घोषणा AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#घोषणा Access_Check_By_Type_परिणाम_List_And_Audit_Alarm Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_W
#घोषणा Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle_W
#घोषणा ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#घोषणा ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#घोषणा ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#घोषणा ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#घोषणा PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#घोषणा SetFileSecurity SetFileSecurityW
#घोषणा GetFileSecurity GetFileSecurityW
#घोषणा FindFirstChangeNotification FindFirstChangeNotificationW
#घोषणा IsBadStringPtr IsBadStringPtrW
#घोषणा LookupAccountSid LookupAccountSidW
#घोषणा LookupAccountName LookupAccountNameW
#घोषणा Lookup_Privilege_मूल्य Lookup_Privilege_मूल्य_W
#घोषणा LookupPrivilegeName LookupPrivilegeNameW
#घोषणा LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#घोषणा BuildCommDCB BuildCommDCBW
#घोषणा BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#घोषणा CommConfigDialog CommConfigDialogW
#घोषणा GetDefaultCommConfig GetDefaultCommConfigW
#घोषणा SetDefaultCommConfig SetDefaultCommConfigW
#घोषणा GetComputerName GetComputerNameW
#घोषणा SetComputerName SetComputerNameW
#घोषणा GetComputerNameEx GetComputerNameExW
#घोषणा SetComputerNameEx SetComputerNameExW
#घोषणा DnsHostnameToComputerName DnsHostnameToComputerNameW
#घोषणा GetUserName GetUserNameW
#अन्यथा
#घोषणा FindFirstFileEx FindFirstFileExA
#घोषणा FindFirstFile FindFirstFileA
#घोषणा Find_अग्र_File Find_अग्र_File_A
#घोषणा खोज_Path खोज_Path_A
#घोषणा CopyFile CopyFileA
#घोषणा CopyFileEx CopyFileExA
#घोषणा MoveFile MoveFileA
#घोषणा MoveFileEx MoveFileExA
#घोषणा MoveFileWithProgress MoveFileWithProgressA
#घोषणा ReplaceFile ReplaceFileA
#घोषणा CreateHardLink CreateHardLinkA
#घोषणा CreateNamedPipe CreateNamedPipeA
#घोषणा GetNamedPipeHandleState GetNamedPipeHandleStateA
#घोषणा CallNamedPipe CallNamedPipeA
#घोषणा WaitNamedPipe WaitNamedPipeA
#घोषणा SetVolumeLabel SetVolumeLabelA
#घोषणा GetVolumeInformation GetVolumeInformationA
#घोषणा ClearEventLog ClearEventLogA
#घोषणा BackupEventLog BackupEventLogA
#घोषणा OpenEventLog OpenEventLogA
#घोषणा RegisterEventSource RegisterEventSourceA
#घोषणा OpenBackupEventLog OpenBackupEventLogA
#घोषणा ReadEventLog ReadEventLogA
#घोषणा ReportEvent ReportEventA
#घोषणा AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#घोषणा AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#घोषणा Access_Check_By_Type_परिणाम_List_And_Audit_Alarm Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_A
#घोषणा Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle_A
#घोषणा ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#घोषणा ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#घोषणा ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#घोषणा ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#घोषणा PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#घोषणा SetFileSecurity SetFileSecurityA
#घोषणा GetFileSecurity GetFileSecurityA
#घोषणा FindFirstChangeNotification FindFirstChangeNotificationA
#घोषणा IsBadStringPtr IsBadStringPtrA
#घोषणा LookupAccountSid LookupAccountSidA
#घोषणा LookupAccountName LookupAccountNameA
#घोषणा Lookup_Privilege_मूल्य Lookup_Privilege_मूल्य_A
#घोषणा LookupPrivilegeName LookupPrivilegeNameA
#घोषणा LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#घोषणा BuildCommDCB BuildCommDCBA
#घोषणा BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#घोषणा CommConfigDialog CommConfigDialogA
#घोषणा GetDefaultCommConfig GetDefaultCommConfigA
#घोषणा SetDefaultCommConfig SetDefaultCommConfigA
#घोषणा GetComputerName GetComputerNameA
#घोषणा SetComputerName SetComputerNameA
#घोषणा GetComputerNameEx GetComputerNameExA
#घोषणा SetComputerNameEx SetComputerNameExA
#घोषणा DnsHostnameToComputerName DnsHostnameToComputerNameA
#घोषणा GetUserName GetUserNameA
#पूर्ण_अगर

  WINBASEAPI HANDLE WINAPI FindFirstFileExA(LPCSTR lpFileName,FINDEX_INFO_LEVELS fInfoLevelId,LPVOID lp_Find_File_तथ्य,FINDEX_खोज_OPS_2 f_खोज_Op,LPVOID lp_खोज_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI FindFirstFileExW(LPCWSTR lpFileName,FINDEX_INFO_LEVELS fInfoLevelId,LPVOID lp_Find_File_तथ्य,FINDEX_खोज_OPS_2 f_खोज_Op,LPVOID lp_खोज_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI FindFirstFileA(LPCSTR lpFileName,LPWIN32_FIND_DATAA lp_Find_File_तथ्य);
  WINBASEAPI HANDLE WINAPI FindFirstFileW(LPCWSTR lpFileName,LPWIN32_FIND_DATAW lp_Find_File_तथ्य);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_File_A(HANDLE hFindFile,LPWIN32_FIND_DATAA lp_Find_File_तथ्य);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_File_W(HANDLE hFindFile,LPWIN32_FIND_DATAW lp_Find_File_तथ्य);
  WINBASEAPI DWORD WINAPI खोज_Path_A(LPCSTR lpPath,LPCSTR lpFileName,LPCSTR lpExtension,DWORD n_बफर_लंबाई,LPSTR lp_बफर,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI खोज_Path_W(LPCWSTR lpPath,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD n_बफर_लंबाई,LPWSTR lp_बफर,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  प्रकार DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER योग_File_आकार,LARGE_INTEGER योग_Bytes_Transferred,LARGE_INTEGER Stream_आकार,LARGE_INTEGER StreamBytesTransferred,DWORD dw_Stream_संख्या,DWORD dwCallbackReason,HANDLE hSourceFile,HANDLE hDestinationFile,LPVOID lp_तथ्य);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lp_तथ्य,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lp_तथ्य,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileWithProgressA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lp_तथ्य,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileWithProgressW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lpProgressRoutine,LPVOID lp_तथ्य,DWORD dwFlags);

#घोषणा MOVEFILE_REPLACE_EXISTING 0x1
#घोषणा MOVEFILE_COPY_ALLOWED 0x2
#घोषणा MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#घोषणा MOVEFILE_WRITE_THROUGH 0x8
#घोषणा MOVEFILE_CREATE_HARDLINK 0x10
#घोषणा MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_ATTRIBUTES lpSecurityAttributes);

  प्रकार क्रमागत _STREAM_INFO_LEVELS {
    FindStreamInfoStandard,FindStreamInfoMaxInfoLevel
  } STREAM_INFO_LEVELS;

  प्रकार काष्ठा WIN32_FIND_STREAM_तथ्य {
    LARGE_INTEGER Stream_आकार;
    WCHAR cStreamName[MAX_PATH + 36];
  } WIN32_FIND_STREAM_तथ्य_2,*PWIN32_FIND_STREAM_तथ्य;

  HANDLE WINAPI FindFirstStreamW(LPCWSTR lpFileName,STREAM_INFO_LEVELS InfoLevel,LPVOID lp_Find_Stream_तथ्य,DWORD dwFlags);
  WINBOOL WINAPI Find_अग्र_Stream_W(HANDLE hFindStream,LPVOID lp_Find_Stream_तथ्य);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dwOpenMode,DWORD dwPipeMode,DWORD nMaxInstances,DWORD n_Out_बफर_आकार,DWORD n_In_बफर_आकार,DWORD nDefaultTimeOut,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dwOpenMode,DWORD dwPipeMode,DWORD nMaxInstances,DWORD n_Out_बफर_आकार,DWORD n_In_बफर_आकार,DWORD nDefaultTimeOut,LPSECURITY_ATTRIBUTES lpSecurityAttributes);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_गिनती,LPDWORD lp_Collect_तथ्य_Timeout,LPSTR lpUserName,DWORD n_Max_User_Name_आकार);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_गिनती,LPDWORD lp_Collect_तथ्य_Timeout,LPWSTR lpUserName,DWORD n_Max_User_Name_आकार);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lp_In_बफर,DWORD n_In_बफर_आकार,LPVOID lp_Out_बफर,DWORD n_Out_बफर_आकार,LPDWORD lpBytesRead,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lp_In_बफर,DWORD n_In_बफर_आकार,LPVOID lp_Out_बफर,DWORD n_Out_बफर_आकार,LPDWORD lpBytesRead,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD nTimeOut);
  WINBASEAPI WINBOOL WINAPI SetVolumeLabelA(LPCSTR lp_मूल_Path_Name,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI SetVolumeLabelW(LPCWSTR lp_मूल_Path_Name,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI SetFileApisToOEM(VOID);
  WINBASEAPI VOID WINAPI SetFileApisToANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lp_मूल_Path_Name,LPSTR lp_Volume_Name_बफर,DWORD n_Volume_Name_आकार,LPDWORD lp_Volume_Serial_संख्या,LPDWORD lp_Maximum_Component_लंबाई,LPDWORD lpFileSystemFlags,LPSTR lp_File_System_Name_बफर,DWORD n_File_System_Name_आकार);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lp_मूल_Path_Name,LPWSTR lp_Volume_Name_बफर,DWORD n_Volume_Name_आकार,LPDWORD lp_Volume_Serial_संख्या,LPDWORD lp_Maximum_Component_लंबाई,LPDWORD lpFileSystemFlags,LPWSTR lp_File_System_Name_बफर,DWORD n_File_System_Name_आकार);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI DeregisterEventSource(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI Get_संख्या_Of_Event_Log_Records(HANDLE hEventLog,PDWORD संख्या_Of_Records);
  WINADVAPI WINBOOL WINAPI GetOldestEventLogRecord(HANDLE hEventLog,PDWORD OldestRecord);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI RegisterEventSourceA(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI RegisterEventSourceW(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lp_बफर,DWORD n_संख्या_Of_Bytes_To_Read,DWORD *pnBytesRead,DWORD *pn_Min_संख्या_Of_Bytes_Needed);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dwRecordOffset,LPVOID lp_बफर,DWORD n_संख्या_Of_Bytes_To_Read,DWORD *pnBytesRead,DWORD *pn_Min_संख्या_Of_Bytes_Needed);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD w_अंक_Strings,DWORD dw_तथ्य_आकार,LPCSTR *lpStrings,LPVOID lp_Raw_तथ्य);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD w_अंक_Strings,DWORD dw_तथ्य_आकार,LPCWSTR *lpStrings,LPVOID lp_Raw_तथ्य);

#घोषणा EVENTLOG_FULL_INFO 0

  प्रकार काष्ठा _EVENTLOG_FULL_INFORMATION {
    DWORD dwFull;
  } EVENTLOG_FULL_INFORMATION,*LPEVENTLOG_FULL_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lp_बफर,DWORD cb_Buf_आकार,LPDWORD pcbBytesNeeded);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_लंबाई,LPDWORD lpn_लंबाई_Needed);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI RevertToSelf(VOID);
  WINADVAPI WINBOOL WINAPI SetThreadToken (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD Privilege_Set_लंबाई,LPDWORD GrantedAccess,LPBOOL AccessStatus);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_लंबाई,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD Privilege_Set_लंबाई,LPDWORD GrantedAccess,LPBOOL AccessStatus);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_लंबाई,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_SET PrivilegeSet,LPDWORD Privilege_Set_लंबाई,LPDWORD GrantedAccessList,LPDWORD AccessStatusList);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_लंबाई,PDWORD Return_लंबाई);
  WINADVAPI WINBOOL WINAPI SetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_लंबाई);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD बफर_लंबाई,PTOKEN_PRIVILEGES PreviousState,PDWORD Return_लंबाई);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL ResetToDefault,PTOKEN_GROUPS NewState,DWORD बफर_लंबाई,PTOKEN_GROUPS PreviousState,PDWORD Return_लंबाई);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_SET RequiredPrivileges,LPBOOL pf_परिणाम);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_लंबाई,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_लंबाई,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL AccessStatus,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_A(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_लंबाई,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_W(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_लंबाई,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle_A(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_लंबाई,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle_W(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_लंबाई,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD AccessStatusList,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_SET Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_SET Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_SET Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI IsWellKnownSid(PSID pSid,WELL_KNOWN_SID_TYPE WellKnownSidType);
  WINADVAPI WINBOOL WINAPI CreateWellKnownSid(WELL_KNOWN_SID_TYPE WellKnownSidType,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI EqualPrefixSid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI Get_Sid_लंबाई_Required (UCHAR n_Sub_Authority_गिनती);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_गिनती,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_गिनती);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI Get_Sid_Sub_Authority_गिनती(PSID pSid);
  WINADVAPI DWORD WINAPI Get_लंबाई_Sid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD n_Destination_Sid_लंबाई,PSID pDestinationSid,PSID pSourceSid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI MapGenericMask(PDWORD AccessMask,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD n_Acl_लंबाई,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_लंबाई,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI SetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_लंबाई,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI AddAce(PACL pAcl,DWORD dwAceRevision,DWORD dw_Starting_Ace_सूचकांक,LPVOID pAceList,DWORD n_Ace_List_लंबाई);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dw_Ace_सूचकांक);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dw_Ace_सूचकांक,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI AddAccessAllowedAce(PACL pAcl,DWORD dwAceRevision,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessAllowedAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedAce(PACL pAcl,DWORD dwAceRevision,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAuditAccessAce(PACL pAcl,DWORD dwAceRevision,DWORD dwAccessMask,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI AddAuditAccessAceEx(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dwAccessMask,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI AddAccessAllowedObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAccessDeniedObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI AddAuditAccessObjectAce(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD AccessMask,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI FindFirstFreeAce(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI Get_Security_Descriptor_लंबाई(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL ControlBitsOfInterest,SECURITY_DESCRIPTOR_CONTROL ControlBitsToSet);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI SetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pGroup,WINBOOL bGroupDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorGroup(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pGroup,LPBOOL lpbGroupDefaulted);
  WINADVAPI DWORD WINAPI SetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI CreatePrivateObjectSecurity(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI ConvertToAutoInheritPrivateObjectSecurity(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI CreatePrivateObjectSecurityEx(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI CreatePrivateObjectSecurityWithMultipleInheritance(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG Guid_गिनती,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI SetPrivateObjectSecurity (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI SetPrivateObjectSecurityEx (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI GetPrivateObjectSecurity(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD Descriptor_लंबाई,PDWORD Return_लंबाई);
  WINADVAPI WINBOOL WINAPI DestroyPrivateObjectSecurity(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_बफर_लंबाई);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdw_Absolute_Security_Descriptor_आकार,PACL pDacl,LPDWORD lpdw_Dacl_आकार,PACL pSacl,LPDWORD lpdw_Sacl_आकार,PSID pOwner,LPDWORD lpdw_Owner_आकार,PSID pPrimaryGroup,LPDWORD lpdw_Primary_Group_आकार);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_बफर_आकार);
  WINADVAPI WINBOOL WINAPI SetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI SetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_लंबाई,LPDWORD lpn_लंबाई_Needed);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_लंबाई,LPDWORD lpn_लंबाई_Needed);
  WINADVAPI WINBOOL WINAPI SetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationA(LPCSTR lpPathName,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationW(LPCWSTR lpPathName,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI FindCloseChangeNotification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lp_बफर,DWORD n_बफर_लंबाई,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lpBytesReturned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI VirtualLock(LPVOID lpAddress,आकार_T dw_आकार);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lpAddress,आकार_T dw_आकार);
  WINBASEAPI LPVOID WINAPI MapViewOfFileEx(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_Offset_ऊपरी,DWORD dw_File_Offset_निचला,आकार_T dw_संख्या_Of_Bytes_To_Map,LPVOID lpBaseAddress);
  WINBASEAPI WINBOOL WINAPI SetPriorityClass(HANDLE hProcess,DWORD dwPriorityClass);
  WINBASEAPI DWORD WINAPI GetPriorityClass(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadCodePtr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_मूल्य_A(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_मूल्य_W(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
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
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_आकार);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_आकार);
  WINBASEAPI WINBOOL WINAPI SetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_आकार);
  WINBASEAPI WINBOOL WINAPI SetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_आकार);

#घोषणा MAX_COMPUTERNAME_लंबाई 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lp_बफर,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lp_बफर,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI SetComputerNameA(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI SetComputerNameW(LPCWSTR lpComputerName);

  प्रकार क्रमागत _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lp_बफर,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lp_बफर,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI SetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPCSTR lp_बफर);
  WINBASEAPI WINBOOL WINAPI SetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPCWSTR lp_बफर);
  WINBASEAPI WINBOOL WINAPI DnsHostnameToComputerNameA(LPCSTR Hostname,LPSTR ComputerName,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI DnsHostnameToComputerNameW(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD n_आकार);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lp_बफर,LPDWORD pcb_बफर);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lp_बफर,LPDWORD pcb_बफर);

#घोषणा LOGON32_LOGON_INTERACTIVE 2
#घोषणा LOGON32_LOGON_NETWORK 3
#घोषणा LOGON32_LOGON_BATCH 4
#घोषणा LOGON32_LOGON_SERVICE 5
#घोषणा LOGON32_LOGON_UNLOCK 7
#घोषणा LOGON32_LOGON_NETWORK_CLEARTEXT 8
#घोषणा LOGON32_LOGON_NEW_CREDENTIALS 9

#घोषणा LOGON32_PROVIDER_DEFAULT 0
#घोषणा LOGON32_PROVIDER_WINNT35 1
#घोषणा LOGON32_PROVIDER_WINNT40 2
#घोषणा LOGON32_PROVIDER_WINNT50 3

#अगर_घोषित UNICODE
#घोषणा LogonUser LogonUserW
#घोषणा LogonUserEx LogonUserExW
#घोषणा CreateProcessAsUser CreateProcessAsUserW
#अन्यथा
#घोषणा LogonUser LogonUserA
#घोषणा LogonUserEx LogonUserExA
#घोषणा CreateProcessAsUser CreateProcessAsUserA
#पूर्ण_अगर

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_बफर,LPDWORD pdw_Profile_लंबाई,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_बफर,LPDWORD pdw_Profile_लंबाई,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lp_Command_पंक्ति,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lp_Command_पंक्ति,LPSECURITY_ATTRIBUTES lpProcessAttributes,LPSECURITY_ATTRIBUTES lpThreadAttributes,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#घोषणा LOGON_WITH_PROFILE 0x1
#घोषणा LOGON_NETCREDENTIALS_ONLY 0x2
#घोषणा LOGON_ZERO_PASSWORD_बफर 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_पंक्ति,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_पंक्ति,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_ATTRIBUTES lpTokenAttributes,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD Disable_Sid_गिनती,PSID_AND_ATTRIBUTES SidsToDisable,DWORD Delete_Privilege_गिनती,PLUID_AND_ATTRIBUTES PrivilegesToDelete,DWORD Restricted_Sid_गिनती,PSID_AND_ATTRIBUTES SidsToRestrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID SidToCheck,PBOOL IsMember);

  प्रकार WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI RegisterWaitForSingleObject(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI RegisterWaitForSingleObjectEx(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI QueueUserWorkItem(LPTHREAD_START_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI CreateTimerQueue(VOID);
  WINBASEAPI WINBOOL WINAPI CreateTimerQueueTimer(PHANDLE phNewTimer,HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI ChangeTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,ULONG DueTime,ULONG Period);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueueEx(HANDLE TimerQueue,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI SetTimerQueueTimer(HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI CancelTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueue(HANDLE TimerQueue);

#घोषणा HW_PROFILE_GUIDLEN 39
#घोषणा MAX_PROFILE_LEN 80

#घोषणा DOCKINFO_UNDOCKED (0x1)
#घोषणा DOCKINFO_DOCKED (0x2)
#घोषणा DOCKINFO_USER_SUPPLIED (0x4)
#घोषणा DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#घोषणा DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  प्रकार काष्ठा tagHW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  प्रकार काष्ठा tagHW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#अगर_घोषित UNICODE
  प्रकार HW_PROFILE_INFOW HW_PROFILE_INFO;
  प्रकार LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#अन्यथा
  प्रकार HW_PROFILE_INFOA HW_PROFILE_INFO;
  प्रकार LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#पूर्ण_अगर

#अगर_घोषित UNICODE
#घोषणा GetCurrentHwProfile GetCurrentHwProfileW
#घोषणा GetVersionEx GetVersionExW
#घोषणा VerifyVersionInfo VerifyVersionInfoW
#अन्यथा
#घोषणा GetCurrentHwProfile GetCurrentHwProfileA
#घोषणा GetVersionEx GetVersionExA
#घोषणा VerifyVersionInfo VerifyVersionInfoA
#पूर्ण_अगर

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI Query_Performance_गणक(LARGE_INTEGER *lp_Performance_गिनती);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI GetVersionExA(LPOSVERSIONINFOA lpVersionInformation);
  WINBASEAPI WINBOOL WINAPI GetVersionExW(LPOSVERSIONINFOW lpVersionInformation);
  WINBASEAPI WINBOOL WINAPI VerifyVersionInfoA(LPOSVERSIONINFOEXA lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);
  WINBASEAPI WINBOOL WINAPI VerifyVersionInfoW(LPOSVERSIONINFOEXW lpVersionInformation,DWORD dwTypeMask,DWORDLONG dwlConditionMask);

#समावेश <winerror.h>

#घोषणा TC_NORMAL 0
#घोषणा TC_HARDERR 1
#घोषणा TC_GP_TRAP 2
#घोषणा TC_SIGNAL 3

#घोषणा AC_पंक्ति_OFFLINE 0x0
#घोषणा AC_पंक्ति_ONLINE 0x1
#घोषणा AC_पंक्ति_BACKUP_POWER 0x2
#घोषणा AC_पंक्ति_UNKNOWN 0xff

#घोषणा BATTERY_FLAG_ऊपरी 0x1
#घोषणा BATTERY_FLAG_निचला 0x2
#घोषणा BATTERY_FLAG_CRITICAL 0x4
#घोषणा BATTERY_FLAG_CHARGING 0x8
#घोषणा BATTERY_FLAG_NO_BATTERY 0x80
#घोषणा BATTERY_FLAG_UNKNOWN 0xff

#घोषणा BATTERY_PERCENTAGE_UNKNOWN 0xff

#घोषणा BATTERY_LIFE_UNKNOWN 0xffffffff

  प्रकार काष्ठा _SYSTEM_POWER_STATUS {
    BYTE ACLineStatus;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD BatteryFullLifeTime;
  } SYSTEM_POWER_STATUS,*LPSYSTEM_POWER_STATUS;

#अगर_घोषित UNICODE
#घोषणा CreateJobObject CreateJobObjectW
#घोषणा OpenJobObject OpenJobObjectW
#घोषणा FindFirstVolume FindFirstVolumeW
#घोषणा Find_अग्र_Volume Find_अग्र_Volume_W
#घोषणा FindFirstVolumeMountPoint FindFirstVolumeMountPointW
#घोषणा Find_अग्र_Volume_Mount_Point Find_अग्र_Volume_Mount_Point_W
#घोषणा SetVolumeMountPoint SetVolumeMountPointW
#घोषणा DeleteVolumeMountPoint DeleteVolumeMountPointW
#घोषणा GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
#घोषणा GetVolumePathName GetVolumePathNameW
#घोषणा GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameW
#अन्यथा
#घोषणा CreateJobObject CreateJobObjectA
#घोषणा OpenJobObject OpenJobObjectA
#घोषणा FindFirstVolume FindFirstVolumeA
#घोषणा Find_अग्र_Volume Find_अग्र_Volume_A
#घोषणा FindFirstVolumeMountPoint FindFirstVolumeMountPointA
#घोषणा Find_अग्र_Volume_Mount_Point Find_अग्र_Volume_Mount_Point_A
#घोषणा SetVolumeMountPoint SetVolumeMountPointA
#घोषणा DeleteVolumeMountPoint DeleteVolumeMountPointA
#घोषणा GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
#घोषणा GetVolumePathName GetVolumePathNameA
#घोषणा GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameA
#पूर्ण_अगर

  WINBOOL WINAPI GetSystemPowerStatus(LPSYSTEM_POWER_STATUS lpSystemPowerStatus);
  WINBOOL WINAPI SetSystemPowerState(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI AllocateUserPhysicalPages(HANDLE hProcess,PULONG_PTR संख्या_Of_Pages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI FreeUserPhysicalPages(HANDLE hProcess,PULONG_PTR संख्या_Of_Pages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI MapUserPhysicalPages(PVOID VirtualAddress,ULONG_PTR संख्या_Of_Pages,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI MapUserPhysicalPagesScatter(PVOID *VirtualAddresses,ULONG_PTR संख्या_Of_Pages,PULONG_PTR PageArray);
  WINBASEAPI HANDLE WINAPI CreateJobObjectA(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateJobObjectW(LPSECURITY_ATTRIBUTES lpJobAttributes,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI AssignProcessToJobObject(HANDLE hJob,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI TerminateJobObject(HANDLE hJob,UINT uExitCode);
  WINBASEAPI WINBOOL WINAPI QueryInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cb_Job_Object_Information_लंबाई,LPDWORD lp_Return_लंबाई);
  WINBASEAPI WINBOOL WINAPI SetInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cb_Job_Object_Information_लंबाई);
  WINBASEAPI WINBOOL WINAPI IsProcessInJob(HANDLE ProcessHandle,HANDLE JobHandle,PBOOL परिणाम_3);
  WINBASEAPI WINBOOL WINAPI CreateJobSet(ULONG अंक_Job,PJOB_SET_ARRAY UserJobSet,ULONG Flags);
  WINBASEAPI PVOID WINAPI AddVectoredExceptionHandler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI AddVectoredContinueHandler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeA(LPSTR lpszVolumeName,DWORD cch_बफर_लंबाई);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeW(LPWSTR lpszVolumeName,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Volume_A(HANDLE hFindVolume,LPSTR lpszVolumeName,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Volume_W(HANDLE hFindVolume,LPWSTR lpszVolumeName,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI FindVolumeClose(HANDLE hFindVolume);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointA(LPCSTR lpsz_मूल_Path_Name,LPSTR lpszVolumeMountPoint,DWORD cch_बफर_लंबाई);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointW(LPCWSTR lpsz_मूल_Path_Name,LPWSTR lpszVolumeMountPoint,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Volume_Mount_Point_A(HANDLE hFindVolumeMountPoint,LPSTR lpszVolumeMountPoint,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Volume_Mount_Point_W(HANDLE hFindVolumeMountPoint,LPWSTR lpszVolumeMountPoint,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI FindVolumeMountPointClose(HANDLE hFindVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI SetVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI SetVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointA(LPCSTR lpszVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointW(LPCWSTR lpszVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPSTR lpszVolumeName,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPWSTR lpszVolumeName,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNameA(LPCSTR lpszFileName,LPSTR lpszVolumePathName,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNameW(LPCWSTR lpszFileName,LPWSTR lpszVolumePathName,DWORD cch_बफर_लंबाई);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNamesForVolumeNameA(LPCSTR lpszVolumeName,LPCH lpszVolumePathNames,DWORD cch_बफर_लंबाई,PDWORD lpcch_Return_लंबाई);
  WINBASEAPI WINBOOL WINAPI GetVolumePathNamesForVolumeNameW(LPCWSTR lpszVolumeName,LPWCH lpszVolumePathNames,DWORD cch_बफर_लंबाई,PDWORD lpcch_Return_लंबाई);

#घोषणा ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#घोषणा ACTCTX_FLAG_LANGID_VALID 0x2
#घोषणा ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#घोषणा ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#घोषणा ACTCTX_FLAG_SET_PROCESS_DEFAULT 0x10
#घोषणा ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#घोषणा ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF 0x40
#घोषणा ACTCTX_FLAG_HMODULE_VALID 0x80

  प्रकार काष्ठा tagACTCTXA {
    ULONG cb_आकार;
    DWORD dwFlags;
    LPCSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  प्रकार काष्ठा tagACTCTXW {
    ULONG cb_आकार;
    DWORD dwFlags;
    LPCWSTR lpSource;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  प्रकार स्थिर ACTCTXA *PCACTCTXA;
  प्रकार स्थिर ACTCTXW *PCACTCTXW;

#अगर_घोषित UNICODE
  प्रकार ACTCTXW ACTCTX;
  प्रकार PACTCTXW PACTCTX;
  प्रकार PCACTCTXW PCACTCTX;
#अन्यथा
  प्रकार ACTCTXA ACTCTX;
  प्रकार PACTCTXA PACTCTX;
  प्रकार PCACTCTXA PCACTCTX;
#पूर्ण_अगर

#अगर_घोषित UNICODE
#घोषणा CreateActCtx CreateActCtxW
#अन्यथा
#घोषणा CreateActCtx CreateActCtxA
#पूर्ण_अगर

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI AddRefActCtx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#घोषणा DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  प्रकार काष्ठा tag_ACTCTX_SECTION_KEYED_तथ्य_2600 {
    ULONG cb_आकार;
    ULONG ul_तथ्य_Format_Version;
    PVOID lp_तथ्य;
    ULONG ul_लंबाई;
    PVOID lp_Section_Global_तथ्य;
    ULONG ul_Section_Global_तथ्य_लंबाई;
    PVOID lpSectionBase;
    ULONG ul_Section_योग_लंबाई;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_सूचकांक;
  } ACTCTX_SECTION_KEYED_तथ्य_2600,*PACTCTX_SECTION_KEYED_तथ्य_2600;

  प्रकार स्थिर ACTCTX_SECTION_KEYED_तथ्य_2600 *PCACTCTX_SECTION_KEYED_तथ्य_2600;

  प्रकार काष्ठा tag_ACTCTX_SECTION_KEYED_तथ्य_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lpSectionBase;
    ULONG ul_Section_लंबाई;
    PVOID lp_Section_Global_तथ्य_Base;
    ULONG ul_Section_Global_तथ्य_लंबाई;
  } ACTCTX_SECTION_KEYED_तथ्य_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_तथ्य_ASSEMBLY_METADATA;

  प्रकार स्थिर ACTCTX_SECTION_KEYED_तथ्य_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_तथ्य_ASSEMBLY_METADATA;

  प्रकार काष्ठा tag_ACTCTX_SECTION_KEYED_तथ्य {
    ULONG cb_आकार;
    ULONG ul_तथ्य_Format_Version;
    PVOID lp_तथ्य;
    ULONG ul_लंबाई;
    PVOID lp_Section_Global_तथ्य;
    ULONG ul_Section_Global_तथ्य_लंबाई;
    PVOID lpSectionBase;
    ULONG ul_Section_योग_लंबाई;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_सूचकांक;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_तथ्य_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_तथ्य,*PACTCTX_SECTION_KEYED_तथ्य;

  प्रकार स्थिर ACTCTX_SECTION_KEYED_तथ्य *PCACTCTX_SECTION_KEYED_तथ्य;

#घोषणा FIND_ACTCTX_SECTION_कुंजी_RETURN_HACTCTX 0x1
#घोषणा FIND_ACTCTX_SECTION_कुंजी_RETURN_FLAGS 0x2
#घोषणा FIND_ACTCTX_SECTION_कुंजी_RETURN_ASSEMBLY_METADATA 0x4

#अगर_घोषित UNICODE
#घोषणा FindActCtxSectionString FindActCtxSectionStringW
#अन्यथा
#घोषणा FindActCtxSectionString FindActCtxSectionStringA
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringA(DWORD dwFlags,स्थिर GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lpStringToFind,PACTCTX_SECTION_KEYED_तथ्य Returned_तथ्य);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringW(DWORD dwFlags,स्थिर GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lpStringToFind,PACTCTX_SECTION_KEYED_तथ्य Returned_तथ्य);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionGuid(DWORD dwFlags,स्थिर GUID *lpExtensionGuid,ULONG ulSectionId,स्थिर GUID *lpGuidToFind,PACTCTX_SECTION_KEYED_तथ्य Returned_तथ्य);

#अगर_अघोषित RC_INVOKED
#अगर_अघोषित ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  प्रकार काष्ठा _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  प्रकार स्थिर काष्ठा _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#घोषणा ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX 0x4
#घोषणा QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#घोषणा QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS 0x10
#घोषणा QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_बफर,आकार_T cb_बफर,आकार_T *pcbWrittenOrRequired);

  प्रकार WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_बफर,आकार_T cb_बफर,आकार_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI ProcessIdToSessionId(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGetActiveConsoleSessionId();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION बफर_3,PDWORD Returned_लंबाई);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Highest_गाँठ_संख्या(PULONG Highest_गाँठ_संख्या);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Processor_गाँठ(UCHAR Processor,PUCHAR गाँठ_संख्या);
  WINBASEAPI WINBOOL WINAPI Get_Numa_गाँठ_Processor_Mask(UCHAR गाँठ_2,PULONGLONG ProcessorMask);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Available_Memory_गाँठ(UCHAR गाँठ_2,PULONGLONG AvailableBytes);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
