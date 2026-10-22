/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _WINBASE_
#परिभाषय _WINBASE_

#परिभाषय WINADVAPI DECLSPEC_IMPORT
#परिभाषय WINBASEAPI DECLSPEC_IMPORT
#परिभाषय ZAWPROXYAPI DECLSPEC_IMPORT

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#परिभाषय Define_Handle_सारणी(w) ((w),TRUE)
#परिभाषय सीमा_Ems_पृष्ठानि(dw)
#परिभाषय समुच्चयः_Swap_Area_आकार(w) (w)
#परिभाषय तालकम्_Segment(w) GlobalFix((HANDLE)(w))
#परिभाषय UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#परिभाषय GetCurrentTime() Get_Tick_गणनम्()

#परिभाषय Yield()

#परिभाषय INVALID_HANDLE_मानम् ((HANDLE)(LONG_PTR)-1)
#परिभाषय INVALID_FILE_आकार ((DWORD)0xffffffff)
#परिभाषय INVALID_समुच्चयः_FILE_POINTER ((DWORD)-1)
#परिभाषय INVALID_FILE_गुणाः ((DWORD)-1)

#परिभाषय FILE_BEGIN 0
#परिभाषय FILE_CURRENT 1
#परिभाषय FILE_अन्तः 2

#परिभाषय TIME_ZONE_ID_INVALID ((DWORD)0xffffffff)

#परिभाषय WAIT_FAILED ((DWORD)0xffffffff)
#परिभाषय WAIT_OBJECT_0 ((स्थितिः_WAIT_0) + 0)
#परिभाषय WAIT_ABANDONED ((स्थितिः_ABANDONED_WAIT_0) + 0)
#परिभाषय WAIT_ABANDONED_0 ((स्थितिः_ABANDONED_WAIT_0) + 0)
#परिभाषय WAIT_IO_COMPLETION स्थितिः_USER_APC
#परिभाषय STILL_सक्रिय स्थितिः_PENDING
#परिभाषय EXCEPTION_ACCESS_VIOLATION स्थितिः_ACCESS_VIOLATION
#परिभाषय EXCEPTION_DATATYPE_MISALIGNMENT स्थितिः_DATATYPE_MISALIGNMENT
#परिभाषय EXCEPTION_BREAKPOINT स्थितिः_BREAKPOINT
#परिभाषय EXCEPTION_SINGLE_चरणः स्थितिः_SINGLE_चरणः
#परिभाषय EXCEPTION_ARRAY_BOUNDS_EXCEEDED स्थितिः_ARRAY_BOUNDS_EXCEEDED
#परिभाषय EXCEPTION_FLT_DENORMAL_सङ्कार्यम् स्थितिः_FLOAT_DENORMAL_सङ्कार्यम्
#परिभाषय EXCEPTION_FLT_DIVIDE_BY_ZERO स्थितिः_FLOAT_DIVIDE_BY_ZERO
#परिभाषय EXCEPTION_FLT_INEXACT_परिणाम स्थितिः_FLOAT_INEXACT_परिणाम
#परिभाषय EXCEPTION_FLT_INVALID_OPERATION स्थितिः_FLOAT_INVALID_OPERATION
#परिभाषय EXCEPTION_FLT_अतिप्रवाहः स्थितिः_FLOAT_अतिप्रवाहः
#परिभाषय EXCEPTION_FLT_राशिः_CHECK स्थितिः_FLOAT_राशिः_CHECK
#परिभाषय EXCEPTION_FLT_UNDERFLOW स्थितिः_FLOAT_UNDERFLOW
#परिभाषय EXCEPTION_INT_DIVIDE_BY_ZERO स्थितिः_INTEGER_DIVIDE_BY_ZERO
#परिभाषय EXCEPTION_INT_अतिप्रवाहः स्थितिः_INTEGER_अतिप्रवाहः
#परिभाषय EXCEPTION_PRIV_INSTRUCTION स्थितिः_PRIVILEGED_INSTRUCTION
#परिभाषय EXCEPTION_अन्तर्_PAGE_ERROR स्थितिः_अन्तर्_PAGE_ERROR
#परिभाषय EXCEPTION_ILLEGAL_INSTRUCTION स्थितिः_ILLEGAL_INSTRUCTION
#परिभाषय EXCEPTION_NONCONTINUABLE_EXCEPTION स्थितिः_NONCONTINUABLE_EXCEPTION
#परिभाषय EXCEPTION_राशिः_अतिप्रवाहः स्थितिः_राशिः_अतिप्रवाहः
#परिभाषय EXCEPTION_INVALID_DISPOSITION स्थितिः_INVALID_DISPOSITION
#परिभाषय EXCEPTION_GUARD_PAGE स्थितिः_GUARD_PAGE_VIOLATION
#परिभाषय EXCEPTION_INVALID_HANDLE स्थितिः_INVALID_HANDLE
#परिभाषय EXCEPTION_POSSIBLE_DEADLOCK स्थितिः_POSSIBLE_DEADLOCK
#परिभाषय CONTROL_C_EXIT स्थितिः_CONTROL_C_EXIT
#परिभाषय Move_स्मृतिः Rtl_Move_स्मृतिः
#परिभाषय Copy_स्मृतिः Rtl_Copy_स्मृतिः
#परिभाषय Fill_स्मृतिः Rtl_Fill_स्मृतिः
#परिभाषय Zero_स्मृतिः Rtl_Zero_स्मृतिः
#परिभाषय Secure_Zero_स्मृतिः Rtl_Secure_Zero_स्मृतिः

#परिभाषय FILE_FLAG_WRITE_THROUGH 0x80000000
#परिभाषय FILE_FLAG_OVERLAPPED 0x40000000
#परिभाषय FILE_FLAG_NO_BUFFERING 0x20000000
#परिभाषय FILE_FLAG_RANDOM_ACCESS 0x10000000
#परिभाषय FILE_FLAG_SEQUENTIAL_अवलोकनम् 0x8000000
#परिभाषय FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#परिभाषय FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#परिभाषय FILE_FLAG_POSIX_SEMANTICS 0x1000000
#परिभाषय FILE_FLAG_OPEN_REPARSE_POINT 0x200000
#परिभाषय FILE_FLAG_OPEN_NO_RECALL 0x100000
#परिभाषय FILE_FLAG_FIRST_PIPE_INSTANCE 0x80000

#परिभाषय CREATE_NEW 1
#परिभाषय CREATE_ALWAYS 2
#परिभाषय OPEN_EXISTING 3
#परिभाषय OPEN_ALWAYS 4
#परिभाषय TRUNCATE_EXISTING 5

#परिभाषय प्रगतिः_CONTINUE 0
#परिभाषय प्रगतिः_CANCEL 1
#परिभाषय प्रगतिः_STOP 2
#परिभाषय प्रगतिः_QUIET 3

#परिभाषय CALLBACK_CHUNK_परिसमाप्तम् 0x0
#परिभाषय CALLBACK_प्रवाहः_SWITCH 0x1

#परिभाषय COPY_FILE_FAIL_IF_EXISTS 0x1
#परिभाषय COPY_FILE_RESTARTABLE 0x2
#परिभाषय COPY_FILE_OPEN_SOURCE_FOR_WRITE 0x4
#परिभाषय COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#परिभाषय REPLACEFILE_WRITE_THROUGH 0x1
#परिभाषय REPLACEFILE_IGNORE_MERGE_ERRORS 0x2

#परिभाषय PIPE_ACCESS_INBOUND 0x1
#परिभाषय PIPE_ACCESS_OUTBOUND 0x2
#परिभाषय PIPE_ACCESS_DUPLEX 0x3

#परिभाषय PIPE_CLIENT_अन्तः 0x0
#परिभाषय PIPE_SERVER_अन्तः 0x1

#परिभाषय PIPE_WAIT 0x0
#परिभाषय PIPE_NOWAIT 0x1
#परिभाषय PIPE_READMODE_BYTE 0x0
#परिभाषय PIPE_READMODE_सन्देशः 0x2
#परिभाषय PIPE_TYPE_BYTE 0x0
#परिभाषय PIPE_TYPE_सन्देशः 0x4

#परिभाषय PIPE_UNLIMITED_INSTANCES 255

#परिभाषय SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#परिभाषय SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#परिभाषय SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#परिभाषय SECURITY_DELEGATION (SecurityDelegation << 16)

#परिभाषय SECURITY_CONTEXT_TRACKING 0x40000
#परिभाषय SECURITY_EFFECTIVE_ONLY 0x80000

#परिभाषय SECURITY_SQOS_PRESENT 0x100000
#परिभाषय SECURITY_VALID_SQOS_FLAGS 0x1f0000

  प्रकारनिर्देश संरचना _OVERLAPPED {
    ULONG_PTR आन्तरिकम्;
    ULONG_PTR आन्तरिकम्_उच्चः;
    सङ्घ {
      संरचना {
	DWORD विस्थापनम्_3;
	DWORD विस्थापनम्_उच्चः_2;
      };
      PVOID Pointer;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  प्रकारनिर्देश संरचना SECURITY_गुणाः {
    DWORD n_दीर्घता;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_गुणाः_2,*PSECURITY_गुणाः,*LPSECURITY_गुणाः;

  प्रकारनिर्देश संरचना _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#यदि_अपरिभाषितम् _FILETIME_
#परिभाषय _FILETIME_
  प्रकारनिर्देश संरचना _FILETIME {
    DWORD dw_नीचः_Date_Time;
    DWORD dw_उच्चः_Date_Time;
  } FILETIME,*PFILETIME,*LPFILETIME;
#यदि_अन्तः

  प्रकारनिर्देश संरचना _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD w_Day_सम्बन्धि_Week;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  प्रकारनिर्देश DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
  प्रकारनिर्देश PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
  प्रकारनिर्देश VOID (WINAPI *PFIBER_START_ROUTINE)(LPVOID lpFiberParameter);
  प्रकारनिर्देश PFIBER_START_ROUTINE LPFIBER_START_ROUTINE;

  प्रकारनिर्देश RTL_CRITICAL_SECTION CRITICAL_SECTION;
  प्रकारनिर्देश PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  प्रकारनिर्देश PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  प्रकारनिर्देश RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  प्रकारनिर्देश PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  प्रकारनिर्देश PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI EncodePointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI DecodePointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI EncodeSystemPointer(PVOID Ptr);
  WINBASEAPI PVOID WINAPI DecodeSystemPointer(PVOID Ptr);

#यदि_परिभाषितम् I_X86_
  प्रकारनिर्देश PLDT_प्रविष्टिः LPLDT_प्रविष्टिः;
#अन्यथा
  प्रकारनिर्देश LPVOID LPLDT_प्रविष्टिः;
#यदि_अन्तः

#परिभाषय MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#परिभाषय MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#परिभाषय SP_SERIALCOMM ((DWORD)0x1)

#परिभाषय PST_UNSPECIFIED ((DWORD)0x0)
#परिभाषय PST_RS232 ((DWORD)0x1)
#परिभाषय PST_PARALLELPORT ((DWORD)0x2)
#परिभाषय PST_RS422 ((DWORD)0x3)
#परिभाषय PST_RS423 ((DWORD)0x4)
#परिभाषय PST_RS449 ((DWORD)0x5)
#परिभाषय PST_MODEM ((DWORD)0x6)
#परिभाषय PST_FAX ((DWORD)0x21)
#परिभाषय PST_SCANNER ((DWORD)0x22)
#परिभाषय PST_जालम्_BRIDGE ((DWORD)0x100)
#परिभाषय PST_LAT ((DWORD)0x101)
#परिभाषय PST_TCPIP_TELNET ((DWORD)0x102)
#परिभाषय PST_X25 ((DWORD)0x103)

#परिभाषय PCF_DTRDSR ((DWORD)0x1)
#परिभाषय PCF_RTSCTS ((DWORD)0x2)
#परिभाषय PCF_RLSD ((DWORD)0x4)
#परिभाषय PCF_PARITY_CHECK ((DWORD)0x8)
#परिभाषय PCF_XONXOFF ((DWORD)0x10)
#परिभाषय PCF_SETXCHAR ((DWORD)0x20)
#परिभाषय PCF_TOTALTIMEOUTS ((DWORD)0x40)
#परिभाषय PCF_INTTIMEOUTS ((DWORD)0x80)
#परिभाषय PCF_SPECIALCHARS ((DWORD)0x100)
#परिभाषय PCF_16BITMODE ((DWORD)0x200)

#परिभाषय SP_PARITY ((DWORD)0x1)
#परिभाषय SP_BAUD ((DWORD)0x2)
#परिभाषय SP_DATABITS ((DWORD)0x4)
#परिभाषय SP_STOPBITS ((DWORD)0x8)
#परिभाषय SP_HANDSHAKING ((DWORD)0x10)
#परिभाषय SP_PARITY_CHECK ((DWORD)0x20)
#परिभाषय SP_RLSD ((DWORD)0x40)

#परिभाषय BAUD_075 ((DWORD)0x1)
#परिभाषय BAUD_110 ((DWORD)0x2)
#परिभाषय BAUD_134_5 ((DWORD)0x4)
#परिभाषय BAUD_150 ((DWORD)0x8)
#परिभाषय BAUD_300 ((DWORD)0x10)
#परिभाषय BAUD_600 ((DWORD)0x20)
#परिभाषय BAUD_1200 ((DWORD)0x40)
#परिभाषय BAUD_1800 ((DWORD)0x80)
#परिभाषय BAUD_2400 ((DWORD)0x100)
#परिभाषय BAUD_4800 ((DWORD)0x200)
#परिभाषय BAUD_7200 ((DWORD)0x400)
#परिभाषय BAUD_9600 ((DWORD)0x800)
#परिभाषय BAUD_14400 ((DWORD)0x1000)
#परिभाषय BAUD_19200 ((DWORD)0x2000)
#परिभाषय BAUD_38400 ((DWORD)0x4000)
#परिभाषय BAUD_56K ((DWORD)0x8000)
#परिभाषय BAUD_128K ((DWORD)0x10000)
#परिभाषय BAUD_115200 ((DWORD)0x20000)
#परिभाषय BAUD_57600 ((DWORD)0x40000)
#परिभाषय BAUD_USER ((DWORD)0x10000000)

#परिभाषय DATABITS_5 ((WORD)0x1)
#परिभाषय DATABITS_6 ((WORD)0x2)
#परिभाषय DATABITS_7 ((WORD)0x4)
#परिभाषय DATABITS_8 ((WORD)0x8)
#परिभाषय DATABITS_16 ((WORD)0x10)
#परिभाषय DATABITS_16X ((WORD)0x20)

#परिभाषय STOPBITS_10 ((WORD)0x1)
#परिभाषय STOPBITS_15 ((WORD)0x2)
#परिभाषय STOPBITS_20 ((WORD)0x4)
#परिभाषय PARITY_NONE ((WORD)0x100)
#परिभाषय PARITY_ODD ((WORD)0x200)
#परिभाषय PARITY_EVEN ((WORD)0x400)
#परिभाषय PARITY_MARK ((WORD)0x800)
#परिभाषय PARITY_SPACE ((WORD)0x1000)

  प्रकारनिर्देश संरचना _COMMPROP {
    WORD w_Packet_दीर्घता;
    WORD w_Packet_संस्करणम्;
    DWORD dw_Service_आवरणम्;
    DWORD dwReserved1;
    DWORD dwMaxTxQueue;
    DWORD dwMaxRxQueue;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    WORD w_Settable_दत्त;
    WORD wSettableStopParity;
    DWORD dwCurrentTxQueue;
    DWORD dwCurrentRxQueue;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#परिभाषय COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  प्रकारनिर्देश संरचना _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD f_Xoff_प्रेषितम् : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cb_अन्तर्_Que;
    DWORD cb_बहिर्गमनम्_Que;
  } COMSTAT,*LPCOMSTAT;

#परिभाषय DTR_CONTROL_DISABLE 0x0
#परिभाषय DTR_CONTROL_ENABLE 0x1
#परिभाषय DTR_CONTROL_HANDSHAKE 0x2

#परिभाषय RTS_CONTROL_DISABLE 0x0
#परिभाषय RTS_CONTROL_ENABLE 0x1
#परिभाषय RTS_CONTROL_HANDSHAKE 0x2
#परिभाषय RTS_CONTROL_TOGGLE 0x3

  प्रकारनिर्देश संरचना _DCB {
    DWORD DCBlength;
    DWORD Baud_दरः;
    DWORD f_द्विमान: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD f_Dsr_संवेदनशीलता:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD f_बहिर्गमनम्_X: 1;
    DWORD f_अन्तर्_X: 1;
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
    BYTE Stop_द्वयङ्काः;
    वर्ण XonChar;
    वर्ण XoffChar;
    वर्ण ErrorChar;
    वर्ण EofChar;
    वर्ण EvtChar;
    WORD wReserved1;
  } DCB,*LPDCB;

  प्रकारनिर्देश संरचना _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD Read_योग_Timeout_Multiplier;
    DWORD Read_योग_Timeout_Constant;
    DWORD Write_योग_Timeout_Multiplier;
    DWORD Write_योग_Timeout_Constant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  प्रकारनिर्देश संरचना _COMMCONFIG {
    DWORD dw_आकार;
    WORD w_संस्करणम्;
    WORD wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dw_Provider_विस्थापनम्;
    DWORD dw_Provider_आकार;
    WCHAR wc_Provider_दत्त[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  प्रकारनिर्देश संरचना _SYSTEM_INFO {
    सङ्घ {
      DWORD dwOemId;
      संरचना {
	WORD wProcessorArchitecture;
	WORD wReserved;
      };
    };
    DWORD dw_Page_आकार;
    LPVOID lp_Minimum_Application_स्थानाङ्कः;
    LPVOID lp_अधिकतमम्_Application_स्थानाङ्कः;
    DWORD_PTR dw_सक्रिय_Processor_आवरणम्;
    DWORD dw_सङ्ख्या_सम्बन्धि_Processors;
    DWORD dwProcessorType;
    DWORD dw_आवण्टनम्_Granularity;
    WORD wProcessorLevel;
    WORD wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#परिभाषय FreeModule(hLibModule) FreeLibrary((hLibModule))
#परिभाषय MakeProcInstance(lpProc,hInstance) (lpProc)
#परिभाषय FreeProcInstance(lpProc) (lpProc)

#परिभाषय GMEM_FIXED 0x0
#परिभाषय GMEM_MOVEABLE 0x2
#परिभाषय GMEM_NOCOMPACT 0x10
#परिभाषय GMEM_NODISCARD 0x20
#परिभाषय GMEM_ZEROINIT 0x40
#परिभाषय GMEM_MODIFY 0x80
#परिभाषय GMEM_DISCARDABLE 0x100
#परिभाषय GMEM_NOT_BANKED 0x1000
#परिभाषय GMEM_SHARE 0x2000
#परिभाषय GMEM_DDESHARE 0x2000
#परिभाषय GMEM_NOTIFY 0x4000
#परिभाषय GMEM_अधस्तनम् GMEM_NOT_BANKED
#परिभाषय GMEM_VALID_FLAGS 0x7F72
#परिभाषय GMEM_INVALID_HANDLE 0x8000

#परिभाषय GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#परिभाषय GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#परिभाषय GlobalLRUNewest(h) ((HANDLE)(h))
#परिभाषय GlobalLRUOldest(h) ((HANDLE)(h))
#परिभाषय GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#परिभाषय GMEM_DISCARDED 0x4000
#परिभाषय GMEM_LOCKCOUNT 0xff

  प्रकारनिर्देश संरचना _MEMORYSTATUS {
    DWORD dw_दीर्घता;
    DWORD dw_स्मृतिः_आरोपय;
    आकार_T dw_योग_Phys;
    आकार_T dwAvailPhys;
    आकार_T dw_योग_Page_File;
    आकार_T dwAvailPageFile;
    आकार_T dw_योग_Virtual;
    आकार_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#परिभाषय LMEM_FIXED 0x0
#परिभाषय LMEM_MOVEABLE 0x2
#परिभाषय LMEM_NOCOMPACT 0x10
#परिभाषय LMEM_NODISCARD 0x20
#परिभाषय LMEM_ZEROINIT 0x40
#परिभाषय LMEM_MODIFY 0x80
#परिभाषय LMEM_DISCARDABLE 0xf00
#परिभाषय LMEM_VALID_FLAGS 0xf72
#परिभाषय LMEM_INVALID_HANDLE 0x8000

#परिभाषय LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#परिभाषय LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#परिभाषय NONZEROLHND (LMEM_MOVEABLE)
#परिभाषय NONZEROLPTR (LMEM_FIXED)

#परिभाषय LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#परिभाषय LMEM_DISCARDED 0x4000
#परिभाषय LMEM_LOCKCOUNT 0xff

#परिभाषय DEBUG_PROCESS 0x1
#परिभाषय DEBUG_ONLY_THIS_PROCESS 0x2
#परिभाषय CREATE_SUSPENDED 0x4
#परिभाषय DETACHED_PROCESS 0x8
#परिभाषय CREATE_NEW_CONSOLE 0x10
#परिभाषय प्रसामान्यम्_प्राथमिकता_CLASS 0x20
#परिभाषय IDLE_प्राथमिकता_CLASS 0x40
#परिभाषय उच्चः_प्राथमिकता_CLASS 0x80
#परिभाषय REALTIME_प्राथमिकता_CLASS 0x100
#परिभाषय CREATE_NEW_PROCESS_गणः 0x200
#परिभाषय CREATE_UNICODE_ENVIRONMENT 0x400
#परिभाषय CREATE_SEPARATE_WOW_VDM 0x800
#परिभाषय CREATE_SHARED_WOW_VDM 0x1000
#परिभाषय CREATE_FORCEDOS 0x2000
#परिभाषय अधः_प्रसामान्यम्_प्राथमिकता_CLASS 0x4000
#परिभाषय ABOVE_प्रसामान्यम्_प्राथमिकता_CLASS 0x8000
#परिभाषय राशिः_आकार_PARAM_IS_A_RESERVATION 0x10000

#परिभाषय CREATE_BREAKAWAY_FROM_JOB 0x1000000
#परिभाषय CREATE_PRESERVE_संहिता_AUTHZ_LEVEL 0x2000000

#परिभाषय CREATE_DEFAULT_ERROR_बहुलकम् 0x4000000
#परिभाषय CREATE_NO_गवाक्षः 0x8000000

#परिभाषय PROFILE_USER 0x10000000
#परिभाषय PROFILE_KERNEL 0x20000000
#परिभाषय PROFILE_SERVER 0x40000000

#परिभाषय CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#परिभाषय THREAD_प्राथमिकता_निम्नतमम् THREAD_आधारः_प्राथमिकता_MIN
#परिभाषय THREAD_प्राथमिकता_अधः_प्रसामान्यम् (THREAD_प्राथमिकता_निम्नतमम्+1)
#परिभाषय THREAD_प्राथमिकता_प्रसामान्यम् 0
#परिभाषय THREAD_प्राथमिकता_HIGHEST THREAD_आधारः_प्राथमिकता_MAX
#परिभाषय THREAD_प्राथमिकता_ABOVE_प्रसामान्यम् (THREAD_प्राथमिकता_HIGHEST-1)
#परिभाषय THREAD_प्राथमिकता_ERROR_RETURN (MAXLONG)

#परिभाषय THREAD_प्राथमिकता_TIME_CRITICAL THREAD_आधारः_प्राथमिकता_LOWRT
#परिभाषय THREAD_प्राथमिकता_IDLE THREAD_आधारः_प्राथमिकता_IDLE

#परिभाषय EXCEPTION_DEBUG_EVENT 1
#परिभाषय CREATE_THREAD_DEBUG_EVENT 2
#परिभाषय CREATE_PROCESS_DEBUG_EVENT 3
#परिभाषय EXIT_THREAD_DEBUG_EVENT 4
#परिभाषय EXIT_PROCESS_DEBUG_EVENT 5
#परिभाषय आरोपय_DLL_DEBUG_EVENT 6
#परिभाषय UNLOAD_DLL_DEBUG_EVENT 7
#परिभाषय OUTPUT_DEBUG_STRING_EVENT 8
#परिभाषय RIP_EVENT 9

  प्रकारनिर्देश संरचना _EXCEPTION_DEBUG_INFO {
    EXCEPTION_लेखः_2 Exception_लेखः;
    DWORD dwFirstChance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  प्रकारनिर्देश संरचना _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lp_Thread_Local_आधारः;
    LPTHREAD_START_ROUTINE lp_Start_स्थानाङ्कः;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  प्रकारनिर्देश संरचना _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lp_आधारः_सम्बन्धि_Image;
    DWORD dw_Debug_Info_File_विस्थापनम्;
    DWORD n_Debug_Info_आकार;
    LPVOID lp_Thread_Local_आधारः;
    LPTHREAD_START_ROUTINE lp_Start_स्थानाङ्कः;
    LPVOID lpImageName;
    WORD fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  प्रकारनिर्देश संरचना _EXIT_THREAD_DEBUG_INFO {
    DWORD dw_Exit_संहिता;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  प्रकारनिर्देश संरचना _EXIT_PROCESS_DEBUG_INFO {
    DWORD dw_Exit_संहिता;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  प्रकारनिर्देश संरचना आरोपय_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lp_आधारः_सम्बन्धि_Dll;
    DWORD dw_Debug_Info_File_विस्थापनम्;
    DWORD n_Debug_Info_आकार;
    LPVOID lpImageName;
    WORD fUnicode;
  } आरोपय_DLL_DEBUG_INFO_2,*LPLOAD_DLL_DEBUG_INFO;

  प्रकारनिर्देश संरचना _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lp_आधारः_सम्बन्धि_Dll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  प्रकारनिर्देश संरचना _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lp_Debug_String_दत्त;
    WORD fUnicode;
    WORD n_Debug_String_दीर्घता;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  प्रकारनिर्देश संरचना _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  प्रकारनिर्देश संरचना _DEBUG_EVENT {
    DWORD dw_Debug_Event_संहिता;
    DWORD dwProcessId;
    DWORD dwThreadId;
    सङ्घ {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      आरोपय_DLL_DEBUG_INFO_2 आरोपय_Dll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  प्रकारनिर्देश PCONTEXT LPCONTEXT;
  प्रकारनिर्देश PEXCEPTION_लेखः LPEXCEPTION_लेखः;
  प्रकारनिर्देश PEXCEPTION_सूचकाः LPEXCEPTION_सूचकाः;

#परिभाषय DRIVE_UNKNOWN 0
#परिभाषय DRIVE_NO_मूलम्_DIR 1
#परिभाषय DRIVE_REMOVABLE 2
#परिभाषय DRIVE_FIXED 3
#परिभाषय DRIVE_REMOTE 4
#परिभाषय DRIVE_CDROM 5
#परिभाषय DRIVE_RAMDISK 6

#परिभाषय GetFreeSpace(w) (0x100000L)
#परिभाषय FILE_TYPE_UNKNOWN 0x0
#परिभाषय FILE_TYPE_DISK 0x1
#परिभाषय FILE_TYPE_CHAR 0x2
#परिभाषय FILE_TYPE_PIPE 0x3
#परिभाषय FILE_TYPE_REMOTE 0x8000

#परिभाषय STD_निवेशः_HANDLE ((DWORD)-10)
#परिभाषय STD_OUTPUT_HANDLE ((DWORD)-11)
#परिभाषय STD_ERROR_HANDLE ((DWORD)-12)

#परिभाषय NOPARITY 0
#परिभाषय ODDPARITY 1
#परिभाषय EVENPARITY 2
#परिभाषय MARKPARITY 3
#परिभाषय SPACEPARITY 4

#परिभाषय ONESTOPBIT 0
#परिभाषय ONE5STOPBITS 1
#परिभाषय TWOSTOPBITS 2

#परिभाषय IGNORE 0
#परिभाषय INFINITE 0xffffffff

#परिभाषय CBR_110 110
#परिभाषय CBR_300 300
#परिभाषय CBR_600 600
#परिभाषय CBR_1200 1200
#परिभाषय CBR_2400 2400
#परिभाषय CBR_4800 4800
#परिभाषय CBR_9600 9600
#परिभाषय CBR_14400 14400
#परिभाषय CBR_19200 19200
#परिभाषय CBR_38400 38400
#परिभाषय CBR_56000 56000
#परिभाषय CBR_57600 57600
#परिभाषय CBR_115200 115200
#परिभाषय CBR_128000 128000
#परिभाषय CBR_256000 256000

#परिभाषय CE_RXOVER 0x1
#परिभाषय CE_OVERRUN 0x2
#परिभाषय CE_RXPARITY 0x4
#परिभाषय CE_FRAME 0x8
#परिभाषय CE_BREAK 0x10
#परिभाषय CE_TXFULL 0x100
#परिभाषय CE_PTO 0x200
#परिभाषय CE_IOE 0x400
#परिभाषय CE_DNS 0x800
#परिभाषय CE_OOP 0x1000
#परिभाषय CE_बहुलकम् 0x8000

#परिभाषय IE_BADID (-1)
#परिभाषय IE_OPEN (-2)
#परिभाषय IE_NOPEN (-3)
#परिभाषय IE_स्मृतिः (-4)
#परिभाषय IE_DEFAULT (-5)
#परिभाषय IE_HARDWARE (-10)
#परिभाषय IE_BYTESIZE (-11)
#परिभाषय IE_BAUDRATE (-12)

#परिभाषय EV_RXCHAR 0x1
#परिभाषय EV_RXFLAG 0x2
#परिभाषय EV_TXEMPTY 0x4
#परिभाषय EV_CTS 0x8
#परिभाषय EV_DSR 0x10
#परिभाषय EV_RLSD 0x20
#परिभाषय EV_BREAK 0x40
#परिभाषय EV_ERR 0x80
#परिभाषय EV_RING 0x100
#परिभाषय EV_PERR 0x200
#परिभाषय EV_RX80_पूर्णम् 0x400
#परिभाषय EV_EVENT1 0x800
#परिभाषय EV_EVENT2 0x1000

#परिभाषय SETXOFF 1
#परिभाषय SETXON 2
#परिभाषय SETRTS 3
#परिभाषय CLRRTS 4
#परिभाषय SETDTR 5
#परिभाषय CLRDTR 6
#परिभाषय RESETDEV 7
#परिभाषय SETBREAK 8
#परिभाषय CLRBREAK 9

#परिभाषय PURGE_TXABORT 0x1
#परिभाषय PURGE_RXABORT 0x2
#परिभाषय PURGE_TXCLEAR 0x4
#परिभाषय PURGE_RXCLEAR 0x8

#परिभाषय LPTx 0x80

#परिभाषय MS_CTS_ON ((DWORD)0x10)
#परिभाषय MS_DSR_ON ((DWORD)0x20)
#परिभाषय MS_RING_ON ((DWORD)0x40)
#परिभाषय MS_RLSD_ON ((DWORD)0x80)

#परिभाषय S_QUEUEEMPTY 0
#परिभाषय S_देहली 1
#परिभाषय S_ALLTHRESHOLD 2

#परिभाषय S_प्रसामान्यम् 0
#परिभाषय S_LEGATO 1
#परिभाषय S_STACCATO 2

#परिभाषय S_PERIOD512 0
#परिभाषय S_PERIOD1024 1
#परिभाषय S_PERIOD2048 2
#परिभाषय S_PERIODVOICE 3
#परिभाषय S_WHITE512 4
#परिभाषय S_WHITE1024 5
#परिभाषय S_WHITE2048 6
#परिभाषय S_WHITEVOICE 7

#परिभाषय S_SERDVNA (-1)
#परिभाषय S_SEROFM (-2)
#परिभाषय S_SERMACT (-3)
#परिभाषय S_SERQFUL (-4)
#परिभाषय S_SERBDNT (-5)
#परिभाषय S_SERDLN (-6)
#परिभाषय S_SERDCC (-7)
#परिभाषय S_SERDTP (-8)
#परिभाषय S_SERDVL (-9)
#परिभाषय S_SERDMD (-10)
#परिभाषय S_SERDSH (-11)
#परिभाषय S_SERDPT (-12)
#परिभाषय S_SERDFQ (-13)
#परिभाषय S_SERDDR (-14)
#परिभाषय S_SERDSR (-15)
#परिभाषय S_SERDST (-16)

#परिभाषय NMPWAIT_WAIT_FOREVER 0xffffffff
#परिभाषय NMPWAIT_NOWAIT 0x1
#परिभाषय NMPWAIT_USE_DEFAULT_WAIT 0x0

#परिभाषय FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_नामानि
#परिभाषय FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_अन्वेषणम्
#परिभाषय FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#परिभाषय FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#परिभाषय FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#परिभाषय FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#परिभाषय FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#परिभाषय FILE_MAP_COPY SECTION_QUERY
#परिभाषय FILE_MAP_WRITE SECTION_MAP_WRITE
#परिभाषय FILE_MAP_READ SECTION_MAP_READ
#परिभाषय FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#परिभाषय FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#परिभाषय सम्बन्धि_READ 0x0
#परिभाषय सम्बन्धि_WRITE 0x1
#परिभाषय सम्बन्धि_READWRITE 0x2
#परिभाषय सम्बन्धि_SHARE_COMPAT 0x0
#परिभाषय सम्बन्धि_SHARE_EXCLUSIVE 0x10
#परिभाषय सम्बन्धि_SHARE_DENY_WRITE 0x20
#परिभाषय सम्बन्धि_SHARE_DENY_READ 0x30
#परिभाषय सम्बन्धि_SHARE_DENY_NONE 0x40
#परिभाषय सम्बन्धि_PARSE 0x100
#परिभाषय सम्बन्धि_DELETE 0x200
#परिभाषय सम्बन्धि_VERIFY 0x400
#परिभाषय सम्बन्धि_CANCEL 0x800
#परिभाषय सम्बन्धि_CREATE 0x1000
#परिभाषय सम्बन्धि_PROMPT 0x2000
#परिभाषय सम्बन्धि_EXIST 0x4000
#परिभाषय सम्बन्धि_REOPEN 0x8000

#परिभाषय OFS_MAXPATHNAME 128
  प्रकारनिर्देश संरचना _OFSTRUCT {
    BYTE c_अष्टकानि;
    BYTE fFixedDisk;
    WORD n_Err_संहिता;
    WORD Reserved1;
    WORD Reserved2;
    CHAR sz_मार्गः_Name[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#यदि_अपरिभाषितम् NOWINBASEINTERLOCK

#यदि_अपरिभाषितम् _NTOS_

#यदि defined(__ia64__) && !defined(RC_INVOKED)

#परिभाषय InterlockedIncrement _InterlockedIncrement
#परिभाषय InterlockedIncrementAcquire _InterlockedIncrement_acq
#परिभाषय InterlockedIncrementRelease _InterlockedIncrement_rel
#परिभाषय InterlockedDecrement _InterlockedDecrement
#परिभाषय InterlockedDecrementAcquire _InterlockedDecrement_acq
#परिभाषय InterlockedDecrementRelease _InterlockedDecrement_rel
#परिभाषय InterlockedExchange _InterlockedExchange
#परिभाषय Interlocked_Exchange_सङ्कलय Interlocked_Exchange_सङ्कलय_2
#परिभाषय InterlockedCompareExchange _InterlockedCompareExchange
#परिभाषय InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#परिभाषय InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#परिभाषय InterlockedExchangePointer _InterlockedExchangePointer
#परिभाषय InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#परिभाषय InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer_rel
#परिभाषय InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer_acq

#परिभाषय InterlockedIncrement64 _InterlockedIncrement64
#परिभाषय InterlockedDecrement64 _InterlockedDecrement64
#परिभाषय InterlockedExchange64 _InterlockedExchange64
#परिभाषय InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#परिभाषय InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#परिभाषय InterlockedCompareExchange64 _InterlockedCompareExchange64
#परिभाषय InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#परिभाषय InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG चञ्चल *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG चञ्चल *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG चञ्चल *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG चञ्चल *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG चञ्चल *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG चञ्चल *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG चञ्चल *Target,LONGLONG मानम्_3);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG चञ्चल *Target,LONGLONG मानम्_3);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG चञ्चल *Addend,LONGLONG मानम्_3);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG चञ्चल *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG चञ्चल *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG चञ्चल *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG चञ्चल *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG चञ्चल *lpAddend);
  LONG __cdecl InterlockedExchange(LONG चञ्चल *Target,LONG मानम्_3);
  LONG __cdecl Interlocked_Exchange_सङ्कलय(LONG चञ्चल *Addend,LONG मानम्_3);
  LONG __cdecl InterlockedCompareExchange(LONG चञ्चल *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG चञ्चल *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG चञ्चल *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl InterlockedExchangePointer(PVOID चञ्चल *Target,PVOID मानम्_3);
  PVOID __cdecl InterlockedCompareExchangePointer(PVOID चञ्चल *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl InterlockedCompareExchangePointerAcquire(PVOID चञ्चल *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl InterlockedCompareExchangePointerRelease(PVOID चञ्चल *Destination,PVOID Exchange,PVOID Comperand);

#यदि_अपरिभाषितम् InterlockedAnd
#परिभाषय InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG चञ्चल *Target,LONG समुच्चयः_2) {
    LONG i;
    LONG j;
    j = *Target;
    कुरु {
      i = j;
      j = InterlockedCompareExchange(Target,i & समुच्चयः_2,i);
    } यावत्(i!=j);
    प्रत्यागम j;
  }
#यदि_अन्तः

#यदि_अपरिभाषितम् InterlockedOr
#परिभाषय InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG चञ्चल *Target,LONG समुच्चयः_2) {
    LONG i;
    LONG j;
    j = *Target;
    कुरु {
      i = j;
      j = InterlockedCompareExchange(Target,i | समुच्चयः_2,i);
    } यावत्(i!=j);
    प्रत्यागम j;
  }
#यदि_अन्तः

#यदि_अपरिभाषितम् InterlockedXor
#परिभाषय InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG चञ्चल *Target,LONG समुच्चयः_2) {
    LONG i;
    LONG j;
    j = *Target;
    कुरु {
      i = j;
      j = InterlockedCompareExchange(Target,i ^ समुच्चयः_2,i);
    } यावत्(i!=j);
    प्रत्यागम j;
  }
#यदि_अन्तः

#यदि_अपरिभाषितम् InterlockedAnd64
#परिभाषय InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG चञ्चल *Destination,LONGLONG मानम्_3) {
    LONGLONG Old;
    कुरु {
      Old = *Destination;
    } यावत्(InterlockedCompareExchange64(Destination,Old & मानम्_3,Old)!=Old);
    प्रत्यागम Old;
  }
#यदि_अन्तः

#यदि_अपरिभाषितम् InterlockedOr64
#परिभाषय InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG चञ्चल *Destination,LONGLONG मानम्_3) {
    LONGLONG Old;
    कुरु {
      Old = *Destination;
    } यावत्(InterlockedCompareExchange64(Destination,Old | मानम्_3,Old)!=Old);
    प्रत्यागम Old;
  }
#यदि_अन्तः

#यदि_अपरिभाषितम् InterlockedXor64
#परिभाषय InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG चञ्चल *Destination,LONGLONG मानम्_3) {
    LONGLONG Old;
    कुरु {
      Old = *Destination;
    } यावत्(InterlockedCompareExchange64(Destination,Old ^ मानम्_3,Old)!=Old);
    प्रत्यागम Old;
  }
#यदि_अन्तः

#यदि_अपरिभाषितम् Interlocked_Bit_Test_And_समुच्चयः
#परिभाषय Interlocked_Bit_Test_And_समुच्चयः Interlocked_Bit_Test_And_समुच्चयः_Inline

  __CRT_INLINE BOOLEAN Interlocked_Bit_Test_And_समुच्चयः_Inline(LONG *आधारः_2,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (परिमाण (*आधारः_2)*8-1));
    प्रत्यागम (BOOLEAN)((InterlockedOr(&आधारः_2[Bit/(परिमाण(*आधारः_2)*8)],tBit)&tBit)!=0);
  }
#यदि_अन्तः

#यदि_अपरिभाषितम् InterlockedBitTestAndReset
#परिभाषय InterlockedBitTestAndReset InterlockedBitTestAndReset_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndReset_Inline(LONG *आधारः_2,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (परिमाण (*आधारः_2)*8-1));
    प्रत्यागम (BOOLEAN)((InterlockedAnd(&आधारः_2[Bit/(परिमाण(*आधारः_2)*8)],~tBit)&tBit)!=0);
  }
#यदि_अन्तः

#यदि_अपरिभाषितम् InterlockedBitTestAndComplement
#परिभाषय InterlockedBitTestAndComplement InterlockedBitTestAndComplement_Inline

  __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement_Inline(LONG *आधारः_2,LONG Bit) {
    LONG tBit;
    tBit = 1<<(Bit & (परिमाण (*आधारः_2)*8-1));
    प्रत्यागम (BOOLEAN)((InterlockedXor(&आधारः_2[Bit/(परिमाण(*आधारः_2)*8)],tBit)&tBit)!=0);
  }
#यदि_अन्तः
#नोचेद्यदि defined(__x86_64) && !defined(RC_INVOKED)

#परिभाषय InterlockedIncrement _InterlockedIncrement
#परिभाषय InterlockedIncrementAcquire InterlockedIncrement
#परिभाषय InterlockedIncrementRelease InterlockedIncrement
#परिभाषय InterlockedDecrement _InterlockedDecrement
#परिभाषय InterlockedDecrementAcquire InterlockedDecrement
#परिभाषय InterlockedDecrementRelease InterlockedDecrement
#परिभाषय InterlockedExchange _InterlockedExchange
#परिभाषय Interlocked_Exchange_सङ्कलय Interlocked_Exchange_सङ्कलय_2
#परिभाषय InterlockedCompareExchange _InterlockedCompareExchange
#परिभाषय InterlockedCompareExchangeAcquire InterlockedCompareExchange
#परिभाषय InterlockedCompareExchangeRelease InterlockedCompareExchange
#परिभाषय InterlockedExchangePointer _InterlockedExchangePointer
#परिभाषय InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#परिभाषय InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#परिभाषय InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer
#परिभाषय InterlockedAnd64 _InterlockedAnd64
#परिभाषय InterlockedOr64 _InterlockedOr64
#परिभाषय InterlockedXor64 _InterlockedXor64
#परिभाषय InterlockedIncrement64 _InterlockedIncrement64
#परिभाषय InterlockedDecrement64 _InterlockedDecrement64
#परिभाषय InterlockedExchange64 _InterlockedExchange64
#परिभाषय InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#परिभाषय InterlockedCompareExchange64 _InterlockedCompareExchange64
#परिभाषय InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#परिभाषय InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG चञ्चल *Addend);
  LONG InterlockedDecrement(LONG चञ्चल *Addend);
  LONG InterlockedExchange(LONG चञ्चल *Target,LONG मानम्_3);
  LONG Interlocked_Exchange_सङ्कलय(LONG चञ्चल *Addend,LONG मानम्_3);
  LONG InterlockedCompareExchange(LONG चञ्चल *Destination,LONG ExChange,LONG Comperand);
  PVOID InterlockedCompareExchangePointer(PVOID चञ्चल *Destination,PVOID Exchange,PVOID Comperand);
  PVOID InterlockedExchangePointer(PVOID चञ्चल *Target,PVOID मानम्_3);
  LONG64 InterlockedAnd64(LONG64 चञ्चल *Destination,LONG64 मानम्_3);
  LONG64 InterlockedOr64(LONG64 चञ्चल *Destination,LONG64 मानम्_3);
  LONG64 InterlockedXor64(LONG64 चञ्चल *Destination,LONG64 मानम्_3);
  LONG64 InterlockedIncrement64(LONG64 चञ्चल *Addend);
  LONG64 InterlockedDecrement64(LONG64 चञ्चल *Addend);
  LONG64 InterlockedExchange64(LONG64 चञ्चल *Target,LONG64 मानम्_3);
  LONG64 InterlockedExchangeAdd64(LONG64 चञ्चल *Addend,LONG64 मानम्_3);
  LONG64 InterlockedCompareExchange64(LONG64 चञ्चल *Destination,LONG64 ExChange,LONG64 Comperand);
#अन्यथा
  LONG WINAPI InterlockedIncrement(LONG चञ्चल *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG चञ्चल *lpAddend);
  LONG WINAPI InterlockedExchange(LONG चञ्चल *Target,LONG मानम्_3);

#यदि_अपरिभाषितम् InterlockedExchangePointer
#परिभाषय InterlockedExchangePointer(Target,मानम्_3) (PVOID)InterlockedExchange((PLONG)(Target),(LONG)(मानम्_3))
#यदि_अन्तः

  LONG WINAPI Interlocked_Exchange_सङ्कलय(LONG चञ्चल *Addend,LONG मानम्_3);
  LONG WINAPI InterlockedCompareExchange(LONG चञ्चल *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG चञ्चल *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG चञ्चल *Destination,LONGLONG मानम्_3) {
    LONGLONG Old;
    कुरु {
      Old = *Destination;
    } यावत्(InterlockedCompareExchange64(Destination,Old & मानम्_3,Old)!=Old);
    प्रत्यागम Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG चञ्चल *Destination,LONGLONG मानम्_3) {
    LONGLONG Old;
    कुरु {
      Old = *Destination;
    } यावत्(InterlockedCompareExchange64(Destination,Old | मानम्_3,Old)!=Old);
    प्रत्यागम Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG चञ्चल *Destination,LONGLONG मानम्_3) {
    LONGLONG Old;
    कुरु {
      Old = *Destination;
    } यावत्(InterlockedCompareExchange64(Destination,Old ^ मानम्_3,Old)!=Old);

    प्रत्यागम Old;
  }

  __CRT_INLINE LONGLONG InterlockedIncrement64(LONGLONG चञ्चल *Addend) {
    LONGLONG Old;
    कुरु {
      Old = *Addend;
    } यावत्(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    प्रत्यागम Old + 1;
  }

  __CRT_INLINE LONGLONG InterlockedDecrement64(LONGLONG चञ्चल *Addend) {
    LONGLONG Old;
    कुरु {
      Old = *Addend;
    } यावत्(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    प्रत्यागम Old - 1;
  }

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG चञ्चल *Target,LONGLONG मानम्_3) {
    LONGLONG Old;
    कुरु {
      Old = *Target;
    } यावत्(InterlockedCompareExchange64(Target,मानम्_3,Old)!=Old);
    प्रत्यागम Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG चञ्चल *Addend,LONGLONG मानम्_3) {
    LONGLONG Old;
    कुरु {
      Old = *Addend;
    } यावत्(InterlockedCompareExchange64(Addend,Old + मानम्_3,Old)!=Old);
    प्रत्यागम Old;
  }

#यदि_अपरिभाषितम् InterlockedCompareExchangePointer
#यदि_परिभाषितम् __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID चञ्चल *Destination,PVOID ExChange,PVOID Comperand) {
    प्रत्यागम((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG चञ्चल *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#परिभाषय InterlockedCompareExchangePointer __InlineInterlockedCompareExchangePointer
#अन्यथा
#परिभाषय InterlockedCompareExchangePointer(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG चञ्चल *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय InterlockedIncrementAcquire InterlockedIncrement
#परिभाषय InterlockedIncrementRelease InterlockedIncrement
#परिभाषय InterlockedDecrementAcquire InterlockedDecrement
#परिभाषय InterlockedDecrementRelease InterlockedDecrement
#परिभाषय InterlockedIncrementAcquire InterlockedIncrement
#परिभाषय InterlockedIncrementRelease InterlockedIncrement
#परिभाषय InterlockedCompareExchangeAcquire InterlockedCompareExchange
#परिभाषय InterlockedCompareExchangeRelease InterlockedCompareExchange
#परिभाषय InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#परिभाषय InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#यदि_अपरिभाषितम् InterlockedCompareExchangePointerAcquire
#परिभाषय InterlockedCompareExchangePointerAcquire InterlockedCompareExchangePointer
#यदि_अन्तः
#यदि_अपरिभाषितम् InterlockedCompareExchangePointerRelease
#परिभाषय InterlockedCompareExchangePointerRelease InterlockedCompareExchangePointer
#यदि_अन्तः
#यदि_अन्तः

#यदि defined(SLIST_शीर्षकम्) && !defined(_NTOSP_)
  WINBASEAPI VOID WINAPI Initialize_SList_शीर्ष(PSLIST_शीर्षकम् List_शीर्ष);
  WINBASEAPI PSLIST_प्रविष्टिः WINAPI Interlocked_निष्कासय_प्रविष्टिः_SList(PSLIST_शीर्षकम् List_शीर्ष);
  WINBASEAPI PSLIST_प्रविष्टिः WINAPI Interlocked_प्रक्षिप_प्रविष्टिः_SList(PSLIST_शीर्षकम् List_शीर्ष,PSLIST_प्रविष्टिः List_प्रविष्टिः);
  WINBASEAPI PSLIST_प्रविष्टिः WINAPI InterlockedFlushSList(PSLIST_शीर्षकम् List_शीर्ष);
  WINBASEAPI USHORT WINAPI Query_गभीरता_SList(PSLIST_शीर्षकम् List_शीर्ष);
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL h_Res_दत्त);
  WINBASEAPI LPVOID WINAPI तालकम्_Resource(HGLOBAL h_Res_दत्त);

#परिभाषय UnlockResource(h_Res_दत्त) ((h_Res_दत्त),0)
#परिभाषय MAXINTATOM 0xC000
#परिभाषय MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((WORD)(i)))
#परिभाषय INVALID_ATOM ((ATOM)0)

  पूर्णाङ्क WINAPI WinMain(HINSTANCE hInstance,HINSTANCE h_पूर्व_Instance,LPSTR lp_Cmd_पङ्क्तिः,पूर्णाङ्क nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dw_Exit_संहिता);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI Get_Proc_स्थानाङ्कः(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI Get_संस्करणम्(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,आकार_T dw_अष्टकानि);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,आकार_T dw_अष्टकानि,UINT uFlags);
  WINBASEAPI आकार_T WINAPI Global_आकार(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI Global_तालकम्(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI आकार_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI Global_स्मृतिः_स्थितिः(LPMEMORYSTATUS lp_बफर);

  प्रकारनिर्देश संरचना _MEMORYSTATUSEX {
    DWORD dw_दीर्घता;
    DWORD dw_स्मृतिः_आरोपय;
    DWORDLONG ull_योग_Phys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ull_योग_Page_File;
    DWORDLONG ullAvailPageFile;
    DWORDLONG ull_योग_Virtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI Global_स्मृतिः_स्थितिः_Ex(LPMEMORYSTATUSEX lp_बफर);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,आकार_T u_अष्टकानि);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,आकार_T u_अष्टकानि,UINT uFlags);
  WINBASEAPI LPVOID WINAPI Local_तालकम्(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI आकार_T WINAPI Local_आकार(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI आकार_T WINAPI LocalShrink(HLOCAL hMem,UINT cb_New_आकार);
  WINBASEAPI आकार_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lp_आधारः_स्थानाङ्कः,आकार_T dw_आकार);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lp_स्थानाङ्कः,आकार_T dw_आकार,DWORD fl_आवण्टनम्_Type,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lp_स्थानाङ्कः,आकार_T dw_आकार,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lp_स्थानाङ्कः,आकार_T dw_आकार,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI आकार_T WINAPI VirtualQuery(LPCVOID lp_स्थानाङ्कः,PMEMORY_BASIC_INFORMATION lp_बफर,आकार_T dw_दीर्घता);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lp_स्थानाङ्कः,आकार_T dw_आकार,DWORD fl_आवण्टनम्_Type,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lp_आधारः_स्थानाङ्कः,आकार_T dw_Region_आकार,PVOID *lp_स्थानाङ्काः,ULONG_PTR *lpdw_गणनम्,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lp_आधारः_स्थानाङ्कः,आकार_T dw_Region_आकार);
  WINBASEAPI आकार_T WINAPI GetLargePageMinimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD Firmware_सारणी_Provider_Signature,PVOID p_Firmware_सारणी_Enum_बफर,DWORD बफर_आकार);
  WINBASEAPI UINT WINAPI Get_System_Firmware_सारणी(DWORD Firmware_सारणी_Provider_Signature,DWORD Firmware_सारणी_ID,PVOID p_Firmware_सारणी_बफर,DWORD बफर_आकार);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lp_स्थानाङ्कः,आकार_T dw_आकार,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lp_स्थानाङ्कः,आकार_T dw_आकार,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI आकार_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lp_स्थानाङ्कः,PMEMORY_BASIC_INFORMATION lp_बफर,आकार_T dw_दीर्घता);
  WINBASEAPI HANDLE WINAPI HeapCreate(DWORD flOptions,आकार_T dw_Initial_आकार,आकार_T dw_अधिकतमम्_आकार);
  WINBASEAPI WINBOOL WINAPI HeapDestroy(HANDLE hHeap);
  WINBASEAPI LPVOID WINAPI HeapAlloc(HANDLE hHeap,DWORD dwFlags,आकार_T dw_अष्टकानि);
  WINBASEAPI LPVOID WINAPI HeapReAlloc(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem,आकार_T dw_अष्टकानि);
  WINBASEAPI WINBOOL WINAPI HeapFree(HANDLE hHeap,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI आकार_T WINAPI Heap_आकार(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI HeapValidate(HANDLE hHeap,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI आकार_T WINAPI HeapCompact(HANDLE hHeap,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI GetProcessHeap(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD सङ्ख्या_सम्बन्धि_Heaps,PHANDLE ProcessHeaps);

  प्रकारनिर्देश संरचना PROCESS_HEAP_प्रविष्टिः {
    PVOID lp_दत्त;
    DWORD cb_दत्त;
    BYTE cbOverhead;
    BYTE i_Region_सूचकांक;
    WORD wFlags;
    सङ्घ {
      संरचना {
	HANDLE hMem;
	DWORD dwReserved[3];
      } खण्डम्_2;
      संरचना {
	DWORD dw_Committed_आकार;
	DWORD dw_Un_Committed_आकार;
	LPVOID lp_First_खण्डम्;
	LPVOID lp_चरमः_खण्डम्;
      } Region;
    };
  } PROCESS_HEAP_प्रविष्टिः_2,*LPPROCESS_HEAP_प्रविष्टिः,*PPROCESS_HEAP_प्रविष्टिः;

#परिभाषय PROCESS_HEAP_REGION 0x1
#परिभाषय PROCESS_HEAP_UNCOMMITTED_RANGE 0x2
#परिभाषय PROCESS_HEAP_प्रविष्टिः_BUSY 0x4
#परिभाषय PROCESS_HEAP_प्रविष्टिः_MOVEABLE 0x10
#परिभाषय PROCESS_HEAP_प्रविष्टिः_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI Heap_तालकम्(HANDLE hHeap);
  WINBASEAPI WINBOOL WINAPI HeapUnlock(HANDLE hHeap);
  WINBASEAPI WINBOOL WINAPI HeapWalk(HANDLE hHeap,LPPROCESS_HEAP_प्रविष्टिः lp_प्रविष्टिः);
  WINBASEAPI WINBOOL WINAPI Heap_समुच्चयः_Information(HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,आकार_T Heap_Information_दीर्घता);
  WINBASEAPI WINBOOL WINAPI HeapQueryInformation(HANDLE HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,आकार_T Heap_Information_दीर्घता,PSIZE_T Return_दीर्घता);

#परिभाषय SCS_32_BIT_द्विमान 0
#परिभाषय SCS_DOS_द्विमान 1
#परिभाषय SCS_WOW_द्विमान 2
#परिभाषय SCS_PIF_द्विमान 3
#परिभाषय SCS_POSIX_द्विमान 4
#परिभाषय SCS_OS216_द्विमान 5
#परिभाषय SCS_64_BIT_द्विमान 6

#यदि_परिभाषितम् UNICODE
#परिभाषय Get_द्विमान_Type Get_द्विमान_Type_W
#परिभाषय Get_Short_मार्गः_Name Get_Short_मार्गः_Name_W
#परिभाषय Get_Long_मार्गः_Name Get_Long_मार्गः_Name_W
#परिभाषय Get_Environment_वाक्यानि Get_Environment_वाक्यानि_W
#परिभाषय समुच्चयः_Environment_वाक्यानि समुच्चयः_Environment_वाक्यानि_W
#परिभाषय Free_Environment_वाक्यानि Free_Environment_वाक्यानि_W
#अन्यथा
#परिभाषय Get_द्विमान_Type Get_द्विमान_Type_A
#परिभाषय Get_Short_मार्गः_Name Get_Short_मार्गः_Name_A
#परिभाषय Get_Long_मार्गः_Name Get_Long_मार्गः_Name_A
#परिभाषय Get_Environment_वाक्यानि_A Get_Environment_वाक्यानि
#परिभाषय समुच्चयः_Environment_वाक्यानि समुच्चयः_Environment_वाक्यानि_A
#परिभाषय Free_Environment_वाक्यानि Free_Environment_वाक्यानि_A
#यदि_अन्तः

#यदि_परिभाषितम् _WIN64
#परिभाषय SCS_THIS_PLATFORM_द्विमान SCS_64_BIT_द्विमान
#अन्यथा
#परिभाषय SCS_THIS_PLATFORM_द्विमान SCS_32_BIT_द्विमान
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI Get_द्विमान_Type_A(LPCSTR lpApplicationName,LPDWORD lp_द्विमान_Type);
  WINBASEAPI WINBOOL WINAPI Get_द्विमान_Type_W(LPCWSTR lpApplicationName,LPDWORD lp_द्विमान_Type);
  WINBASEAPI DWORD WINAPI Get_Short_मार्गः_Name_A(LPCSTR lpsz_Long_मार्गः,LPSTR lpsz_Short_मार्गः,DWORD cch_बफर);
  WINBASEAPI DWORD WINAPI Get_Short_मार्गः_Name_W(LPCWSTR lpsz_Long_मार्गः,LPWSTR lpsz_Short_मार्गः,DWORD cch_बफर);
  WINBASEAPI DWORD WINAPI Get_Long_मार्गः_Name_A(LPCSTR lpsz_Short_मार्गः,LPSTR lpsz_Long_मार्गः,DWORD cch_बफर);
  WINBASEAPI DWORD WINAPI Get_Long_मार्गः_Name_W(LPCWSTR lpsz_Short_मार्गः,LPWSTR lpsz_Long_मार्गः,DWORD cch_बफर);
  WINBASEAPI WINBOOL WINAPI Get_Process_Affinity_आवरणम्(HANDLE hProcess,PDWORD_PTR lp_Process_Affinity_आवरणम्,PDWORD_PTR lp_System_Affinity_आवरणम्);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Process_Affinity_आवरणम्(HANDLE hProcess,DWORD_PTR dw_Process_Affinity_आवरणम्);
  WINBASEAPI WINBOOL WINAPI Get_Process_Handle_गणनम्(HANDLE hProcess,PDWORD pdw_Handle_गणनम्);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_समुच्चयः_आकार(HANDLE hProcess,PSIZE_T lp_Minimum_Working_समुच्चयः_आकार,PSIZE_T lp_अधिकतमम्_Working_समुच्चयः_आकार);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_समुच्चयः_आकार_Ex(HANDLE hProcess,PSIZE_T lp_Minimum_Working_समुच्चयः_आकार,PSIZE_T lp_अधिकतमम्_Working_समुच्चयः_आकार,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Process_Working_समुच्चयः_आकार(HANDLE hProcess,आकार_T dw_Minimum_Working_समुच्चयः_आकार,आकार_T dw_अधिकतमम्_Working_समुच्चयः_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Process_Working_समुच्चयः_आकार_Ex(HANDLE hProcess,आकार_T dw_Minimum_Working_समुच्चयः_आकार,आकार_T dw_अधिकतमम्_Working_समुच्चयः_आकार,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT u_Exit_संहिता);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT u_Exit_संहिता);
  WINBASEAPI WINBOOL WINAPI Get_Exit_संहिता_Process(HANDLE hProcess,LPDWORD lp_Exit_संहिता);
  WINBASEAPI VOID WINAPI FatalExit(पूर्णाङ्क Exit_संहिता);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI Get_Environment_वाक्यानि_W(VOID);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Environment_वाक्यानि_A(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Environment_वाक्यानि_W(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI Free_Environment_वाक्यानि_A(LPCH);
  WINBASEAPI WINBOOL WINAPI Free_Environment_वाक्यानि_W(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dw_Exception_संहिता,DWORD dwExceptionFlags,DWORD n_सङ्ख्या_सम्बन्धि_Arguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(संरचना EXCEPTION_सूचकाः_2 *ExceptionInfo);

  प्रकारनिर्देश LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(संरचना EXCEPTION_सूचकाः_2 *ExceptionInfo);
  प्रकारनिर्देश PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI समुच्चयः_Unhandled_Exception_Filter(LPTOP_LEVEL_EXCEPTION_FILTER lp_शिखरम्_Level_Exception_Filter);

#परिभाषय FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(आकार_T dw_राशिः_आकार,LPFIBER_START_ROUTINE lp_Start_स्थानाङ्कः,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(आकार_T dw_राशिः_Commit_आकार,आकार_T dw_राशिः_Reserve_आकार,DWORD dwFlags,LPFIBER_START_ROUTINE lp_Start_स्थानाङ्कः,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI Convert_Thread_गन्तव्यम्_Fiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI Convert_Thread_गन्तव्यम्_Fiber_Ex(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Convert_Fiber_गन्तव्यम्_Thread(VOID);
  WINBASEAPI VOID WINAPI Switch_गन्तव्यम्_Fiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI Switch_गन्तव्यम्_Thread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_गुणाः lp_Thread_गुणाः,आकार_T dw_राशिः_आकार,LPTHREAD_START_ROUTINE lp_Start_स्थानाङ्कः,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_गुणाः lp_Thread_गुणाः,आकार_T dw_राशिः_आकार,LPTHREAD_START_ROUTINE lp_Start_स्थानाङ्कः,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Thread_राशिः_Guarantee (PULONG राशिः_आकार_अन्तर्_अष्टकानि);
  WINBASEAPI DWORD WINAPI Get_Process_Id_सम्बन्धि_Thread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI Get_Current_Processor_सङ्ख्या(VOID);
  WINBASEAPI DWORD_PTR WINAPI समुच्चयः_Thread_Affinity_आवरणम्(HANDLE hThread,DWORD_PTR dw_Thread_Affinity_आवरणम्);
  WINBASEAPI DWORD WINAPI समुच्चयः_Thread_Ideal_Processor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Process_प्राथमिकता_Boost(HANDLE hProcess,WINBOOL b_Disable_प्राथमिकता_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Process_प्राथमिकता_Boost(HANDLE hProcess,PBOOL p_Disable_प्राथमिकता_Boost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_TIME latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Thread_प्राथमिकता(HANDLE hThread,पूर्णाङ्क n_प्राथमिकता);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Thread_प्राथमिकता_Boost(HANDLE hThread,WINBOOL b_Disable_प्राथमिकता_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Thread_प्राथमिकता_Boost(HANDLE hThread,PBOOL p_Disable_प्राथमिकता_Boost);
  WINBASEAPI पूर्णाङ्क WINAPI Get_Thread_प्राथमिकता(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lpCreationTime,LPFILETIME lpExitTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dw_Exit_संहिता);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dw_Exit_संहिता);
  WINBASEAPI WINBOOL WINAPI Get_Exit_संहिता_Thread(HANDLE hThread,LPDWORD lp_Exit_संहिता);
  WINBASEAPI WINBOOL WINAPI Get_Thread_Selector_प्रविष्टिः(HANDLE hThread,DWORD dwSelector,LPLDT_प्रविष्टिः lp_Selector_प्रविष्टिः);
  WINBASEAPI EXECUTION_STATE WINAPI समुच्चयः_Thread_Execution_State(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI Get_चरमः_Error(VOID);
  WINBASEAPI VOID WINAPI समुच्चयः_चरमः_Error(DWORD dw_Err_संहिता);

#यदि_अपरिभाषितम् RC_INVOKED
#यदि_परिभाषितम् WINBASE_DECLARE_RESTORE_चरमः_ERROR
  WINBASEAPI VOID WINAPI Restore_चरमः_Error(DWORD dw_Err_संहिता);

  प्रकारनिर्देश VOID (WINAPI *PRESTORE_चरमः_ERROR)(DWORD);

#परिभाषय RESTORE_चरमः_ERROR_NAME_A "RestoreLastError"
#परिभाषय RESTORE_चरमः_ERROR_NAME_W L"RestoreLastError"
#परिभाषय RESTORE_चरमः_ERROR_NAME TEXT("RestoreLastError")
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->आन्तरिकम्)!=स्थितिः_PENDING)

  WINBASEAPI WINBOOL WINAPI Get_Overlapped_परिणाम(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Transferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI Create_Io_Completion_पत्तनम्(HANDLE FileHandle,HANDLE Existing_Completion_पत्तनम्,ULONG_PTR Completion_कुञ्चिका,DWORD सङ्ख्या_सम्बन्धि_Concurrent_तन्तवः);
  WINBASEAPI WINBOOL WINAPI Get_Queued_Completion_स्थितिः(HANDLE Completion_पत्तनम्,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Transferred,PULONG_PTR lp_Completion_कुञ्चिका,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI Post_Queued_Completion_स्थितिः(HANDLE Completion_पत्तनम्,DWORD dw_सङ्ख्या_सम्बन्धि_अष्टकानि_Transferred,ULONG_PTR dw_Completion_कुञ्चिका,LPOVERLAPPED lpOverlapped);

#परिभाषय SEM_FAILCRITICALERRORS 0x1
#परिभाषय SEM_NOGPFAULTERRORBOX 0x2
#परिभाषय SEM_NOALIGNMENTFAULTEXCEPT 0x4
#परिभाषय SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI समुच्चयः_Error_बहुलकम्(UINT u_बहुलकम्);
  WINBASEAPI WINBOOL WINAPI Read_Process_स्मृतिः(HANDLE hProcess,LPCVOID lp_आधारः_स्थानाङ्कः,LPVOID lp_बफर,आकार_T n_आकार,आकार_T *lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Read);
  WINBASEAPI WINBOOL WINAPI Write_Process_स्मृतिः(HANDLE hProcess,LPVOID lp_आधारः_स्थानाङ्कः,LPCVOID lp_बफर,आकार_T n_आकार,आकार_T *lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Written);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Thread_Context(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  प्रकारनिर्देश VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI QueueUserAPC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dw_दत्त);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dw_Continue_स्थितिः);
  WINBASEAPI WINBOOL WINAPI Debug_सक्रिय_Process(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_सक्रिय_Process_Stop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_समुच्चयः_Process_Kill_On_Exit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI Initialize_Critical_Section_And_Spin_गणनम्(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_गणनम्);
  WINBASEAPI DWORD WINAPI समुच्चयः_Critical_Section_Spin_गणनम्(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_गणनम्);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Event(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG l_Release_गणनम्,LPLONG lp_Previous_गणनम्);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI Wait_For_गुणजः_Objects(DWORD n_गणनम्,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI आरोपय_Resource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI Init_Atom_सारणी(DWORD n_आकार);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI समुच्चयः_Handle_गणनम्(UINT u_सङ्ख्या);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI तालकम्_File(HANDLE hFile,DWORD dw_File_विस्थापनम्_नीचः,DWORD dw_File_विस्थापनम्_उच्चः,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_तालकम्_नीचः,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_तालकम्_उच्चः);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dw_File_विस्थापनम्_नीचः,DWORD dw_File_विस्थापनम्_उच्चः,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Unlock_नीचः,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Unlock_उच्चः);
  WINBASEAPI WINBOOL WINAPI तालकम्_File_Ex(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_तालकम्_नीचः,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_तालकम्_उच्चः,LPOVERLAPPED lpOverlapped);

#परिभाषय LOCKFILE_FAIL_IMMEDIATELY 0x1
#परिभाषय LOCKFILE_EXCLUSIVE_तालकम् 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Unlock_नीचः,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Unlock_उच्चः,LPOVERLAPPED lpOverlapped);

  प्रकारनिर्देश संरचना _BY_HANDLE_FILE_INFORMATION {
    DWORD dw_File_गुणाः;
    FILETIME ftCreationTime;
    FILETIME ft_चरमः_Access_Time;
    FILETIME ft_चरमः_Write_Time;
    DWORD dw_Volume_Serial_सङ्ख्या;
    DWORD n_File_आकार_उच्चः;
    DWORD n_File_आकार_नीचः;
    DWORD n_सङ्ख्या_सम्बन्धि_Links;
    DWORD n_File_सूचकांक_उच्चः;
    DWORD n_File_सूचकांक_नीचः;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#यदि_परिभाषितम् UNICODE
#परिभाषय समुच्चयः_File_Short_Name समुच्चयः_File_Short_Name_W
#अन्यथा
#परिभाषय समुच्चयः_File_Short_Name समुच्चयः_File_Short_Name_A
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI Get_File_आकार(HANDLE hFile,LPDWORD lp_File_आकार_उच्चः);
  WINBASEAPI WINBOOL WINAPI Get_File_आकार_Ex(HANDLE hFile,PLARGE_INTEGER lp_File_आकार);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Std_Handle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Write,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Written,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Read,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dw_Io_Control_संहिता,LPVOID lp_अन्तर्_बफर,DWORD n_अन्तर्_बफर_आकार,LPVOID lp_बहिर्गमनम्_बफर,DWORD n_बहिर्गमनम्_बफर_आकार,LPDWORD lp_अष्टकानि_Returned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_सन्देशः_प्रतीक्षा_Indicator(HANDLE h_सन्देशः_Indicator,ULONG ul_सन्देशः_गणनम्);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_अन्तः_सम्बन्धि_File(HANDLE hFile);
  WINBASEAPI DWORD WINAPI समुच्चयः_File_Pointer(HANDLE hFile,LONG l_Distance_गन्तव्यम्_Move,PLONG lp_Distance_गन्तव्यम्_Move_उच्चः,DWORD dw_Move_विधानम्);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_File_Pointer_Ex(HANDLE hFile,LARGE_INTEGER li_Distance_गन्तव्यम्_Move,PLARGE_INTEGER lpNewFilePointer,DWORD dw_Move_विधानम्);
  WINBASEAPI WINBOOL WINAPI FindClose(HANDLE hFindFile);
  WINBASEAPI WINBOOL WINAPI GetFileTime(HANDLE hFile,LPFILETIME lpCreationTime,LPFILETIME lp_चरमः_Access_Time,LPFILETIME lp_चरमः_Write_Time);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_File_Time(HANDLE hFile,CONST FILETIME *lpCreationTime,CONST FILETIME *lp_चरमः_Access_Time,CONST FILETIME *lp_चरमः_Write_Time);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_File_Valid_दत्त(HANDLE hFile,LONGLONG Valid_दत्त_दीर्घता);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_File_Short_Name_A(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_File_Short_Name_W(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE hSourceProcessHandle,HANDLE hSourceHandle,HANDLE hTargetProcessHandle,LPHANDLE lpTargetHandle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Handle_Information(HANDLE hObject,DWORD dw_आवरणम्,DWORD dwFlags);

#परिभाषय HANDLE_FLAG_INHERIT 0x1
#परिभाषय HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#परिभाषय HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI आरोपय_Module(LPCSTR lpModuleName,LPVOID lp_Parameter_खण्डम्);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lp_Cmd_पङ्क्तिः,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI सज्जता_Comm(HANDLE hFile,DWORD dw_अन्तर्_Queue,DWORD dw_बहिर्गमनम्_Queue);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdw_आकार);
  WINBASEAPI WINBOOL WINAPI Get_Comm_आवरणम्(HANDLE hFile,LPDWORD lp_Evt_आवरणम्);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI Get_Comm_Modem_स्थितिः(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Comm_Break(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Comm_Config(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dw_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Comm_आवरणम्(HANDLE hFile,DWORD dw_Evt_आवरणम्);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Comm_State(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Comm_Timeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,वर्ण cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lp_Evt_आवरणम्,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI समुच्चयः_पट्टिका_Position(HANDLE hDevice,DWORD dw_Position_विधानम्,DWORD dwPartition,DWORD dw_विस्थापनम्_नीचः,DWORD dw_विस्थापनम्_उच्चः,WINBOOL b_तात्कालिकम्);
  WINBASEAPI DWORD WINAPI Get_पट्टिका_Position(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdwPartition,LPDWORD lpdw_विस्थापनम्_नीचः,LPDWORD lpdw_विस्थापनम्_उच्चः);
  WINBASEAPI DWORD WINAPI Prepare_पट्टिका(HANDLE hDevice,DWORD dwOperation,WINBOOL b_तात्कालिकम्);
  WINBASEAPI DWORD WINAPI Erase_पट्टिका(HANDLE hDevice,DWORD dwEraseType,WINBOOL b_तात्कालिकम्);
  WINBASEAPI DWORD WINAPI Create_पट्टिका_Partition(HANDLE hDevice,DWORD dw_Partition_विधानम्,DWORD dw_गणनम्,DWORD dw_आकार);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dw_Tapemark_गणनम्,WINBOOL b_तात्कालिकम्);
  WINBASEAPI DWORD WINAPI Get_पट्टिका_स्थितिः(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI Get_पट्टिका_Parameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdw_आकार,LPVOID lp_पट्टिका_Information);

#परिभाषय GET_पट्टिका_MEDIA_INFORMATION 0
#परिभाषय GET_पट्टिका_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI समुच्चयः_पट्टिका_Parameters(HANDLE hDevice,DWORD dwOperation,LPVOID lp_पट्टिका_Information);

#परिभाषय समुच्चयः_पट्टिका_MEDIA_INFORMATION 0
#परिभाषय समुच्चयः_पट्टिका_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI पूर्णाङ्क WINAPI MulDiv(पूर्णाङ्क n_सङ्ख्या,पूर्णाङ्क nNumerator,पूर्णाङ्क nDenominator);
  WINBASEAPI VOID WINAPI GetSystemTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI VOID WINAPI GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_System_Time(CONST SYSTEMTIME *lpSystemTime);
  WINBASEAPI VOID WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Local_Time(CONST SYSTEMTIME *lpSystemTime);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_System_File_Cache_आकार(आकार_T Minimum_File_Cache_आकार,आकार_T अधिकतमम्_File_Cache_आकार,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI Get_System_File_Cache_आकार(PSIZE_T lp_Minimum_File_Cache_आकार,PSIZE_T lp_अधिकतमम्_File_Cache_आकार,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdw_Quota_प्रयुक्तम्);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lpIdleTime,LPFILETIME lpKernelTime,LPFILETIME lpUserTime);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  प्रकारनिर्देश संरचना _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } TIME_ZONE_INFORMATION,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#यदि_परिभाषितम् UNICODE
#परिभाषय Format_सन्देशः Format_सन्देशः_W
#अन्यथा
#परिभाषय Format_सन्देशः Format_सन्देशः_A
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI System_Time_गन्तव्यम्_Tz_Specific_Local_Time(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpUniversalTime,LPSYSTEMTIME lpLocalTime);
  WINBASEAPI WINBOOL WINAPI Tz_Specific_Local_Time_गन्तव्यम्_System_Time(LPTIME_ZONE_INFORMATION lpTimeZoneInformation,LPSYSTEMTIME lpLocalTime,LPSYSTEMTIME lpUniversalTime);
  WINBASEAPI DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Time_Zone_Information(CONST TIME_ZONE_INFORMATION *lpTimeZoneInformation);
  WINBASEAPI WINBOOL WINAPI System_Time_गन्तव्यम्_File_Time(CONST SYSTEMTIME *lpSystemTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI File_Time_गन्तव्यम्_Local_File_Time(CONST FILETIME *lpFileTime,LPFILETIME lpLocalFileTime);
  WINBASEAPI WINBOOL WINAPI Local_File_Time_गन्तव्यम्_File_Time(CONST FILETIME *lpLocalFileTime,LPFILETIME lpFileTime);
  WINBASEAPI WINBOOL WINAPI File_Time_गन्तव्यम्_System_Time(CONST FILETIME *lpFileTime,LPSYSTEMTIME lpSystemTime);
  WINBASEAPI LONG WINAPI CompareFileTime(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI File_Time_गन्तव्यम्_Dos_Date_Time(CONST FILETIME *lpFileTime,LPWORD lpFatDate,LPWORD lpFatTime);
  WINBASEAPI WINBOOL WINAPI Dos_Date_Time_गन्तव्यम्_File_Time(WORD wFatDate,WORD wFatTime,LPFILETIME lpFileTime);
  WINBASEAPI DWORD WINAPI Get_Tick_गणनम्(VOID);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_System_Time_Adjustment(DWORD dwTimeAdjustment,WINBOOL bTimeAdjustmentDisabled);
  WINBASEAPI WINBOOL WINAPI GetSystemTimeAdjustment(PDWORD lpTimeAdjustment,PDWORD lpTimeIncrement,PBOOL lpTimeAdjustmentDisabled);
  WINBASEAPI DWORD WINAPI Format_सन्देशः_A(DWORD dwFlags,LPCVOID lpSource,DWORD dw_सन्देशः_Id,DWORD dwLanguageId,LPSTR lp_बफर,DWORD n_आकार,va_list *Arguments);
  WINBASEAPI DWORD WINAPI Format_सन्देशः_W(DWORD dwFlags,LPCVOID lpSource,DWORD dw_सन्देशः_Id,DWORD dwLanguageId,LPWSTR lp_बफर,DWORD n_आकार,va_list *Arguments);

#परिभाषय FORMAT_सन्देशः_ALLOCATE_बफर 0x100
#परिभाषय FORMAT_सन्देशः_IGNORE_INSERTS 0x200
#परिभाषय FORMAT_सन्देशः_FROM_STRING 0x400
#परिभाषय FORMAT_सन्देशः_FROM_HMODULE 0x800
#परिभाषय FORMAT_सन्देशः_FROM_SYSTEM 0x1000
#परिभाषय FORMAT_सन्देशः_तर्कः_ARRAY 0x2000
#परिभाषय FORMAT_सन्देशः_MAX_विस्तारः_आवरणम् 0xff

#यदि_परिभाषितम् UNICODE
#परिभाषय CreateMailslot CreateMailslotW
#परिभाषय EncryptFile EncryptFileW
#परिभाषय DecryptFile DecryptFileW
#परिभाषय File_Encryption_स्थितिः File_Encryption_स्थितिः_W
#अन्यथा
#परिभाषय CreateMailslot CreateMailslotA
#परिभाषय EncryptFile EncryptFileA
#परिभाषय DecryptFile DecryptFileA
#परिभाषय File_Encryption_स्थितिः File_Encryption_स्थितिः_A
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_गुणाः lp_Pipe_गुणाः,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Named_Pipe_Handle_State(HANDLE hNamedPipe,LPDWORD lp_बहुलकम्,LPDWORD lp_Max_Collection_गणनम्,LPDWORD lp_Collect_दत्त_Timeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lp_बहिर्गमनम्_बफर_आकार,LPDWORD lp_अन्तर्_बफर_आकार,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lp_बफर,DWORD n_बफर_आकार,LPDWORD lp_अष्टकानि_Read,LPDWORD lp_योग_अष्टकानि_Avail,LPDWORD lp_अष्टकानि_वामः_This_सन्देशः);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lp_अन्तर्_बफर,DWORD n_अन्तर्_बफर_आकार,LPVOID lp_बहिर्गमनम्_बफर,DWORD n_बहिर्गमनम्_बफर_आकार,LPDWORD lp_अष्टकानि_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD n_Max_सन्देशः_आकार,DWORD lReadTimeout,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD n_Max_सन्देशः_आकार,DWORD lReadTimeout,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lp_Max_सन्देशः_आकार,LPDWORD lp_अग्र_आकार,LPDWORD lp_सन्देशः_गणनम्,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Mailslot_Info(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI Map_View_सम्बन्धि_File(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_विस्थापनम्_उच्चः,DWORD dw_File_विस्थापनम्_नीचः,आकार_T dw_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Map);
  WINBASEAPI WINBOOL WINAPI Flush_View_सम्बन्धि_File(LPCVOID lp_आधारः_स्थानाङ्कः,आकार_T dw_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Flush);
  WINBASEAPI WINBOOL WINAPI Unmap_View_सम्बन्धि_File(LPCVOID lp_आधारः_स्थानाङ्कः);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#परिभाषय FILE_ENCRYPTABLE 0
#परिभाषय FILE_IS_ENCRYPTED 1
#परिभाषय FILE_SYSTEM_ATTR 2
#परिभाषय FILE_मूलम्_DIR 3
#परिभाषय FILE_SYSTEM_DIR 4
#परिभाषय FILE_UNKNOWN 5
#परिभाषय FILE_SYSTEM_NOT_SUPPORT 6
#परिभाषय FILE_USER_DISALLOWED 7
#परिभाषय FILE_READ_ONLY 8
#परिभाषय FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI File_Encryption_स्थितिः_A(LPCSTR lpFileName,LPDWORD lp_स्थितिः);
  WINADVAPI WINBOOL WINAPI File_Encryption_स्थितिः_W(LPCWSTR lpFileName,LPDWORD lp_स्थितिः);

#परिभाषय EFS_USE_RECOVERY_कुञ्चिकाः (0x1)

  प्रकारनिर्देश DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pb_दत्त,PVOID pvCallbackContext,ULONG ul_दीर्घता);
  प्रकारनिर्देश DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pb_दत्त,PVOID pvCallbackContext,PULONG ul_दीर्घता);

#परिभाषय CREATE_FOR_IMPORT (1)
#परिभाषय CREATE_FOR_DIR (2)
#परिभाषय OVERWRITE_HIDDEN (4)

#यदि_परिभाषितम् UNICODE
#परिभाषय OpenEncryptedFileRaw OpenEncryptedFileRawW
#परिभाषय lstrcmp lstrcmpW
#परिभाषय lstrcmpi lstrcmpiW
#परिभाषय lstrcpyn lstrcpynW
#परिभाषय lstrcpy lstrcpyW
#परिभाषय lstrcat lstrcatW
#परिभाषय lstrlen lstrlenW
#अन्यथा
#परिभाषय OpenEncryptedFileRaw OpenEncryptedFileRawA
#परिभाषय lstrcmp lstrcmpA
#परिभाषय lstrcmpi lstrcmpiA
#परिभाषय lstrcpyn lstrcpynA
#परिभाषय lstrcpy lstrcpyA
#परिभाषय lstrcat lstrcatA
#परिभाषय lstrlen lstrlenA
#यदि_अन्तः

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI पूर्णाङ्क WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI पूर्णाङ्क WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI पूर्णाङ्क WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI पूर्णाङ्क WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,पूर्णाङ्क i_Max_दीर्घता);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,पूर्णाङ्क i_Max_दीर्घता);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI पूर्णाङ्क WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI पूर्णाङ्क WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lp_मार्गः_Name,पूर्णाङ्क iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lp_मार्गः_Name,पूर्णाङ्क iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lp_बफर,UINT u_अष्टकानि);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lp_बफर,UINT u_अष्टकानि);
  WINBASEAPI दीर्घ WINAPI _hread(HFILE hFile,LPVOID lp_बफर,दीर्घ l_अष्टकानि);
  WINBASEAPI दीर्घ WINAPI _hwrite(HFILE hFile,LPCCH lp_बफर,दीर्घ l_अष्टकानि);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG l_विस्थापनम्,पूर्णाङ्क iOrigin);
  WINADVAPI WINBOOL WINAPI IsTextUnicode(CONST VOID *lpv,पूर्णाङ्क i_आकार,LPINT lpi_परिणाम);

#परिभाषय FLS_बहिर्गमनम्_सम्बन्धि_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI Fls_Get_मानम्(DWORD dw_Fls_सूचकांक);
  WINBASEAPI WINBOOL WINAPI Fls_समुच्चयः_मानम्(DWORD dw_Fls_सूचकांक,PVOID lp_Fls_दत्त);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dw_Fls_सूचकांक);

#परिभाषय TLS_बहिर्गमनम्_सम्बन्धि_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI Tls_Get_मानम्(DWORD dw_Tls_सूचकांक);
  WINBASEAPI WINBOOL WINAPI Tls_समुच्चयः_मानम्(DWORD dw_Tls_सूचकांक,LPVOID lp_Tls_मानम्);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dw_Tls_सूचकांक);

  प्रकारनिर्देश VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dw_Error_संहिता,DWORD dw_सङ्ख्या_सम्बन्धि_अष्टकानि_Transfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI Wait_For_गुणजः_Objects_Ex(DWORD n_गणनम्,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE h_Object_गन्तव्यम्_Signal,HANDLE h_Object_गन्तव्यम्_Wait_On,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Read,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Write,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Read,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Read,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dw_नीचः_अष्टकानि_गन्तव्यम्_Seek,DWORD dw_उच्चः_अष्टकानि_गन्तव्यम्_Seek,LPDWORD lpdw_नीचः_Byte_Seeked,LPDWORD lpdw_उच्चः_Byte_Seeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Write,LPDWORD lp_सङ्ख्या_सम्बन्धि_अष्टकानि_Written,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  प्रकारनिर्देश संरचना WIN32_प्रवाहः_ID {
    DWORD dw_प्रवाहः_Id;
    DWORD dw_प्रवाहः_गुणाः;
    LARGE_INTEGER आकार_3;
    DWORD dw_प्रवाहः_Name_आकार;
    WCHAR c_प्रवाहः_Name[ANYSIZE_ARRAY];
  } WIN32_प्रवाहः_ID_2,*LPWIN32_प्रवाहः_ID;

#परिभाषय BACKUP_INVALID 0x0
#परिभाषय BACKUP_दत्त 0x1
#परिभाषय BACKUP_EA_दत्त 0x2
#परिभाषय BACKUP_SECURITY_दत्त 0x3
#परिभाषय BACKUP_ALTERNATE_दत्त 0x4
#परिभाषय BACKUP_LINK 0x5
#परिभाषय BACKUP_PROPERTY_दत्त 0x6
#परिभाषय BACKUP_OBJECT_ID 0x7
#परिभाषय BACKUP_REPARSE_दत्त 0x8
#परिभाषय BACKUP_SPARSE_खण्डम् 0x9

#परिभाषय प्रवाहः_प्रसामान्यम्_ATTRIBUTE 0x0
#परिभाषय प्रवाहः_MODIFIED_WHEN_READ 0x1
#परिभाषय प्रवाहः_अन्तर्भवति_SECURITY 0x2
#परिभाषय प्रवाहः_अन्तर्भवति_PROPERTIES 0x4
#परिभाषय प्रवाहः_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Read,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Write,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#परिभाषय STARTF_USESHOWWINDOW 0x1
#परिभाषय STARTF_USESIZE 0x2
#परिभाषय STARTF_USEPOSITION 0x4
#परिभाषय STARTF_USECOUNTCHARS 0x8
#परिभाषय STARTF_USEFILLATTRIBUTE 0x10
#परिभाषय STARTF_RUNFULLSCREEN 0x20
#परिभाषय STARTF_FORCEONFEEDBACK 0x40
#परिभाषय STARTF_FORCEOFFFEEDBACK 0x80
#परिभाषय STARTF_USESTDHANDLES 0x100

#परिभाषय STARTF_USEHOTKEY 0x200

  प्रकारनिर्देश संरचना _STARTUPINFOA {
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
    WORD w_Show_गवाक्षः;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_निवेशः;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOA,*LPSTARTUPINFOA;

  प्रकारनिर्देश संरचना _STARTUPINFOW {
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
    WORD w_Show_गवाक्षः;
    WORD cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_निवेशः;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश STARTUPINFOW STARTUPINFO;
  प्रकारनिर्देश LPSTARTUPINFOW LPSTARTUPINFO;
#अन्यथा
  प्रकारनिर्देश STARTUPINFOA STARTUPINFO;
  प्रकारनिर्देश LPSTARTUPINFOA LPSTARTUPINFO;
#यदि_अन्तः

#परिभाषय SHUTDOWN_NORETRY 0x1

  प्रकारनिर्देश संरचना _WIN32_FIND_DATAA {
    DWORD dw_File_गुणाः;
    FILETIME ftCreationTime;
    FILETIME ft_चरमः_Access_Time;
    FILETIME ft_चरमः_Write_Time;
    DWORD n_File_आकार_उच्चः;
    DWORD n_File_आकार_नीचः;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_मार्गः];
    CHAR cAlternateFileName[14];
  } WIN32_FIND_DATAA,*PWIN32_FIND_DATAA,*LPWIN32_FIND_DATAA;

  प्रकारनिर्देश संरचना _WIN32_FIND_DATAW {
    DWORD dw_File_गुणाः;
    FILETIME ftCreationTime;
    FILETIME ft_चरमः_Access_Time;
    FILETIME ft_चरमः_Write_Time;
    DWORD n_File_आकार_उच्चः;
    DWORD n_File_आकार_नीचः;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_मार्गः];
    WCHAR cAlternateFileName[14];
  } WIN32_FIND_DATAW,*PWIN32_FIND_DATAW,*LPWIN32_FIND_DATAW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WIN32_FIND_DATAW WIN32_FIND_दत्त;
  प्रकारनिर्देश PWIN32_FIND_DATAW PWIN32_FIND_दत्त;
  प्रकारनिर्देश LPWIN32_FIND_DATAW LPWIN32_FIND_दत्त;
#अन्यथा
  प्रकारनिर्देश WIN32_FIND_DATAA WIN32_FIND_दत्त;
  प्रकारनिर्देश PWIN32_FIND_DATAA PWIN32_FIND_दत्त;
  प्रकारनिर्देश LPWIN32_FIND_DATAA LPWIN32_FIND_दत्त;
#यदि_अन्तः

  प्रकारनिर्देश संरचना WIN32_FILE_ATTRIBUTE_दत्त {
    DWORD dw_File_गुणाः;
    FILETIME ftCreationTime;
    FILETIME ft_चरमः_Access_Time;
    FILETIME ft_चरमः_Write_Time;
    DWORD n_File_आकार_उच्चः;
    DWORD n_File_आकार_नीचः;
  } WIN32_FILE_ATTRIBUTE_दत्त_2,*LPWIN32_FILE_ATTRIBUTE_दत्त;

#यदि_परिभाषितम् UNICODE
#परिभाषय CreateMutex CreateMutexW
#परिभाषय OpenMutex OpenMutexW
#परिभाषय CreateEvent CreateEventW
#परिभाषय OpenEvent OpenEventW
#परिभाषय CreateSemaphore CreateSemaphoreW
#परिभाषय OpenSemaphore OpenSemaphoreW
#अन्यथा
#परिभाषय CreateMutex CreateMutexA
#परिभाषय OpenMutex OpenMutexA
#परिभाषय CreateEvent CreateEventA
#परिभाषय OpenEvent OpenEventA
#परिभाषय CreateSemaphore CreateSemaphoreA
#परिभाषय OpenSemaphore OpenSemaphoreA
#यदि_अन्तः

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_गुणाः lp_Mutex_गुणाः,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_गुणाः lp_Mutex_गुणाः,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_गुणाः lp_Event_गुणाः,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_गुणाः lp_Event_गुणाः,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_गुणाः lp_Semaphore_गुणाः,LONG l_Initial_गणनम्,LONG l_अधिकतमम्_गणनम्,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_गुणाः lp_Semaphore_गुणाः,LONG l_Initial_गणनम्,LONG l_अधिकतमम्_गणनम्,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  प्रकारनिर्देश VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lp_Arg_गन्तव्यम्_Completion_Routine,DWORD dw_Timer_नीचः_मानम्,DWORD dw_Timer_उच्चः_मानम्);

#यदि_परिभाषितम् UNICODE
#परिभाषय CreateWaitableTimer CreateWaitableTimerW
#परिभाषय OpenWaitableTimer OpenWaitableTimerW
#परिभाषय CreateFileMapping CreateFileMappingW
#परिभाषय OpenFileMapping OpenFileMappingW
#परिभाषय Get_Logical_Drive_वाक्यानि Get_Logical_Drive_वाक्यानि_W
#परिभाषय आरोपय_Library आरोपय_Library_W
#परिभाषय आरोपय_Library_Ex आरोपय_Library_Ex_W
#परिभाषय GetModuleFileName GetModuleFileNameW
#परिभाषय GetModuleHandle GetModuleHandleW
#अन्यथा
#परिभाषय CreateWaitableTimer CreateWaitableTimerA
#परिभाषय OpenWaitableTimer OpenWaitableTimerA
#परिभाषय CreateFileMapping CreateFileMappingA
#परिभाषय OpenFileMapping OpenFileMappingA
#परिभाषय Get_Logical_Drive_वाक्यानि Get_Logical_Drive_वाक्यानि_A
#परिभाषय आरोपय_Library आरोपय_Library_A
#परिभाषय आरोपय_Library_Ex आरोपय_Library_Ex_A
#परिभाषय GetModuleFileName GetModuleFileNameA
#परिभाषय GetModuleHandle GetModuleHandleA
#यदि_अन्तः

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_गुणाः lp_Timer_गुणाः,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_गुणाः lp_Timer_गुणाः,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Waitable_Timer(HANDLE hTimer,ध्रुव LARGE_INTEGER *lpDueTime,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lp_Arg_गन्तव्यम्_Completion_Routine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_गुणाः lp_File_Mapping_गुणाः,DWORD flProtect,DWORD dw_अधिकतमम्_आकार_उच्चः,DWORD dw_अधिकतमम्_आकार_नीचः,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_गुणाः lp_File_Mapping_गुणाः,DWORD flProtect,DWORD dw_अधिकतमम्_आकार_उच्चः,DWORD dw_अधिकतमम्_आकार_नीचः,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_वाक्यानि_A(DWORD n_बफर_दीर्घता,LPSTR lp_बफर);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_वाक्यानि_W(DWORD n_बफर_दीर्घता,LPWSTR lp_बफर);

  प्रकारनिर्देश गणना स्मृतिः_RESOURCE_NOTIFICATION_TYPE {
    नीचः_स्मृतिः_Resource_Notification,उच्चः_स्मृतिः_Resource_Notification
  } स्मृतिः_RESOURCE_NOTIFICATION_TYPE_2;

  WINBASEAPI HANDLE WINAPI Create_स्मृतिः_Resource_Notification(स्मृतिः_RESOURCE_NOTIFICATION_TYPE_2 NotificationType);
  WINBASEAPI WINBOOL WINAPI Query_स्मृतिः_Resource_Notification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI आरोपय_Library_A(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI आरोपय_Library_W(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI आरोपय_Library_Ex_A(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI आरोपय_Library_Ex_W(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#परिभाषय DONT_RESOLVE_DLL_REFERENCES 0x1
#परिभाषय आरोपय_LIBRARY_AS_DATAFILE 0x2
#परिभाषय आरोपय_WITH_ALTERED_अन्वेषणम्_मार्गः 0x8
#परिभाषय आरोपय_IGNORE_संहिता_AUTHZ_LEVEL 0x10
#परिभाषय आरोपय_LIBRARY_AS_IMAGE_RESOURCE 0x20
#परिभाषय आरोपय_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40
#परिभाषय आरोपय_LIBRARY_REQUIRE_SIGNED_TARGET 0x80
#परिभाषय आरोपय_LIBRARY_अन्वेषणम्_DLL_आरोपय_DIR 0x100
#परिभाषय आरोपय_LIBRARY_अन्वेषणम्_APPLICATION_DIR 0x200
#परिभाषय आरोपय_LIBRARY_अन्वेषणम्_USER_DIRS 0x400
#परिभाषय आरोपय_LIBRARY_अन्वेषणम्_SYSTEM32 0x800
#परिभाषय आरोपय_LIBRARY_अन्वेषणम्_DEFAULT_DIRS 0x1000
#परिभाषय आरोपय_LIBRARY_SAFE_CURRENT_DIRS 0x2000

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD n_आकार);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#यदि_अपरिभाषितम् RC_INVOKED
#परिभाषय GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#परिभाषय GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#परिभाषय GET_MODULE_HANDLE_EX_FLAG_FROM_स्थानाङ्कः (0x4)

  प्रकारनिर्देश WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  प्रकारनिर्देश WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#यदि_परिभाषितम् UNICODE
#परिभाषय PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#परिभाषय GetModuleHandleEx GetModuleHandleExW
#अन्यथा
#परिभाषय PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#परिभाषय GetModuleHandleEx GetModuleHandleExA
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय Need_Current_Directory_For_Exe_मार्गः Need_Current_Directory_For_Exe_मार्गः_W
#परिभाषय CreateProcess CreateProcessW
#परिभाषय FatalAppExit FatalAppExitW
#परिभाषय GetStartupInfo GetStartupInfoW
#परिभाषय Get_Command_पङ्क्तिः Get_Command_पङ्क्तिः_W
#परिभाषय GetEnvironmentVariable GetEnvironmentVariableW
#परिभाषय समुच्चयः_Environment_Variable समुच्चयः_Environment_Variable_W
#परिभाषय Expand_Environment_वाक्यानि Expand_Environment_वाक्यानि_W
#परिभाषय GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#परिभाषय समुच्चयः_Firmware_Environment_Variable समुच्चयः_Firmware_Environment_Variable_W
#परिभाषय OutputDebugString OutputDebugStringW
#परिभाषय FindResource FindResourceW
#परिभाषय FindResourceEx FindResourceExW
#अन्यथा
#परिभाषय Need_Current_Directory_For_Exe_मार्गः Need_Current_Directory_For_Exe_मार्गः_A
#परिभाषय CreateProcess CreateProcessA
#परिभाषय FatalAppExit FatalAppExitA
#परिभाषय GetStartupInfo GetStartupInfoA
#परिभाषय Get_Command_पङ्क्तिः Get_Command_पङ्क्तिः_A
#परिभाषय GetEnvironmentVariable GetEnvironmentVariableA
#परिभाषय समुच्चयः_Environment_Variable समुच्चयः_Environment_Variable_A
#परिभाषय Expand_Environment_वाक्यानि Expand_Environment_वाक्यानि_A
#परिभाषय GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#परिभाषय समुच्चयः_Firmware_Environment_Variable समुच्चयः_Firmware_Environment_Variable_A
#परिभाषय OutputDebugString OutputDebugStringA
#परिभाषय FindResource FindResourceA
#परिभाषय FindResourceEx FindResourceExA
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_मार्गः_A(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_मार्गः_W(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lp_Command_पङ्क्तिः,LPSECURITY_गुणाः lp_Process_गुणाः,LPSECURITY_गुणाः lp_Thread_गुणाः,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lp_Command_पङ्क्तिः,LPSECURITY_गुणाः lp_Process_गुणाः,LPSECURITY_गुणाः lp_Thread_गुणाः,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI सङ्कलय_Local_Alternate_Computer_Name_A(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI सङ्कलय_Local_Alternate_Computer_Name_W(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Process_Shutdown_Parameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI Get_Process_संस्करणम्(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lp_सन्देशः_Text);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lp_सन्देशः_Text);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI Get_Command_पङ्क्तिः_A(VOID);
  WINBASEAPI LPWSTR WINAPI Get_Command_पङ्क्तिः_W(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lp_बफर,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lp_बफर,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Environment_Variable_A(LPCSTR lpName,LPCSTR lp_मानम्);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lp_मानम्);
  WINBASEAPI DWORD WINAPI Expand_Environment_वाक्यानि_A(LPCSTR lpSrc,LPSTR lpDst,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI Expand_Environment_वाक्यानि_W(LPCWSTR lpSrc,LPWSTR lpDst,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_बफर,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_बफर,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Firmware_Environment_Variable_A(LPCSTR lpName,LPCSTR lpGuid,PVOID p_मानम्,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Firmware_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_मानम्,DWORD n_आकार);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI FindResourceA(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceW(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI FindResourceExA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage);
  WINBASEAPI HRSRC WINAPI FindResourceExW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage);

#यदि_परिभाषितम् UNICODE
#परिभाषय ENUMRESTYPEPROC ENUMRESTYPEPROCW
#परिभाषय ENUMRESNAMEPROC ENUMRESNAMEPROCW
#परिभाषय ENUMRESLANGPROC ENUMRESLANGPROCW
#परिभाषय EnumResourceTypes EnumResourceTypesW
#परिभाषय Enum_Resource_नामानि Enum_Resource_नामानि_W
#परिभाषय EnumResourceLanguages EnumResourceLanguagesW
#परिभाषय BeginUpdateResource BeginUpdateResourceW
#परिभाषय UpdateResource UpdateResourceW
#परिभाषय अन्तः_Update_Resource अन्तः_Update_Resource_W
#परिभाषय Global_सङ्कलय_Atom Global_सङ्कलय_Atom_W
#परिभाषय GlobalFindAtom GlobalFindAtomW
#परिभाषय GlobalGetAtomName GlobalGetAtomNameW
#परिभाषय सङ्कलय_Atom सङ्कलय_Atom_W
#परिभाषय FindAtom FindAtomW
#परिभाषय GetAtomName GetAtomNameW
#परिभाषय GetProfileInt GetProfileIntW
#परिभाषय GetProfileString GetProfileStringW
#परिभाषय WriteProfileString WriteProfileStringW
#परिभाषय GetProfileSection GetProfileSectionW
#परिभाषय WriteProfileSection WriteProfileSectionW
#परिभाषय Get_वैयक्तिकम्_Profile_Int Get_वैयक्तिकम्_Profile_Int_W
#परिभाषय Get_वैयक्तिकम्_Profile_String Get_वैयक्तिकम्_Profile_String_W
#परिभाषय Write_वैयक्तिकम्_Profile_String Write_वैयक्तिकम्_Profile_String_W
#परिभाषय Get_वैयक्तिकम्_Profile_Section Get_वैयक्तिकम्_Profile_Section_W
#परिभाषय Write_वैयक्तिकम्_Profile_Section Write_वैयक्तिकम्_Profile_Section_W
#परिभाषय Get_वैयक्तिकम्_Profile_Section_नामानि Get_वैयक्तिकम्_Profile_Section_नामानि_W
#परिभाषय Get_वैयक्तिकम्_Profile_Struct Get_वैयक्तिकम्_Profile_Struct_W
#परिभाषय Write_वैयक्तिकम्_Profile_Struct Write_वैयक्तिकम्_Profile_Struct_W
#परिभाषय GetDriveType GetDriveTypeW
#परिभाषय GetSystemDirectory GetSystemDirectoryW
#परिभाषय Get_अस्थायी_मार्गः Get_अस्थायी_मार्गः_W
#परिभाषय Get_अस्थायी_File_Name Get_अस्थायी_File_Name_W
#परिभाषय GetWindowsDirectory GetWindowsDirectoryW
#परिभाषय GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#परिभाषय सङ्कलय_Local_Alternate_Computer_Name सङ्कलय_Local_Alternate_Computer_Name_W
#अन्यथा
#परिभाषय ENUMRESTYPEPROC ENUMRESTYPEPROCA
#परिभाषय ENUMRESNAMEPROC ENUMRESNAMEPROCA
#परिभाषय ENUMRESLANGPROC ENUMRESLANGPROCA
#परिभाषय EnumResourceTypes EnumResourceTypesA
#परिभाषय Enum_Resource_नामानि Enum_Resource_नामानि_A
#परिभाषय EnumResourceLanguages EnumResourceLanguagesA
#परिभाषय BeginUpdateResource BeginUpdateResourceA
#परिभाषय UpdateResource UpdateResourceA
#परिभाषय अन्तः_Update_Resource अन्तः_Update_Resource_A
#परिभाषय Global_सङ्कलय_Atom Global_सङ्कलय_Atom_A
#परिभाषय GlobalFindAtom GlobalFindAtomA
#परिभाषय GlobalGetAtomName GlobalGetAtomNameA
#परिभाषय सङ्कलय_Atom सङ्कलय_Atom_A
#परिभाषय FindAtom FindAtomA
#परिभाषय GetAtomName GetAtomNameA
#परिभाषय GetProfileInt GetProfileIntA
#परिभाषय GetProfileString GetProfileStringA
#परिभाषय WriteProfileString WriteProfileStringA
#परिभाषय GetProfileSection GetProfileSectionA
#परिभाषय WriteProfileSection WriteProfileSectionA
#परिभाषय Get_वैयक्तिकम्_Profile_Int Get_वैयक्तिकम्_Profile_Int_A
#परिभाषय Get_वैयक्तिकम्_Profile_String Get_वैयक्तिकम्_Profile_String_A
#परिभाषय Write_वैयक्तिकम्_Profile_String Write_वैयक्तिकम्_Profile_String_A
#परिभाषय Get_वैयक्तिकम्_Profile_Section Get_वैयक्तिकम्_Profile_Section_A
#परिभाषय Write_वैयक्तिकम्_Profile_Section Write_वैयक्तिकम्_Profile_Section_A
#परिभाषय Get_वैयक्तिकम्_Profile_Section_नामानि Get_वैयक्तिकम्_Profile_Section_नामानि_A
#परिभाषय Get_वैयक्तिकम्_Profile_Struct Get_वैयक्तिकम्_Profile_Struct_A
#परिभाषय Write_वैयक्तिकम्_Profile_Struct Write_वैयक्तिकम्_Profile_Struct_A
#परिभाषय GetDriveType GetDriveTypeA
#परिभाषय GetSystemDirectory GetSystemDirectoryA
#परिभाषय Get_अस्थायी_मार्गः Get_अस्थायी_मार्गः_A
#परिभाषय Get_अस्थायी_File_Name Get_अस्थायी_File_Name_A
#परिभाषय GetWindowsDirectory GetWindowsDirectoryA
#परिभाषय GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#परिभाषय सङ्कलय_Local_Alternate_Computer_Name सङ्कलय_Local_Alternate_Computer_Name_A
#यदि_अन्तः

  प्रकारनिर्देश WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  प्रकारनिर्देश WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  प्रकारनिर्देश WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  प्रकारनिर्देश WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  प्रकारनिर्देश WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LONG_PTR lParam);
  प्रकारनिर्देश WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_नामानि_A(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_नामानि_W(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,WORD wLanguage,LPVOID lp_दत्त,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,WORD wLanguage,LPVOID lp_दत्त,DWORD cb);
  WINBASEAPI WINBOOL WINAPI अन्तः_Update_Resource_A(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI अन्तः_Update_Resource_W(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI Global_सङ्कलय_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_सङ्कलय_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI GlobalFindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lp_बफर,पूर्णाङ्क n_आकार);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lp_बफर,पूर्णाङ्क n_आकार);
  WINBASEAPI ATOM WINAPI सङ्कलय_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI सङ्कलय_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomA(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI FindAtomW(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lp_बफर,पूर्णाङ्क n_आकार);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lp_बफर,पूर्णाङ्क n_आकार);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lp_कुञ्चिका_Name,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_कुञ्चिका_Name,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lp_कुञ्चिका_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_कुञ्चिका_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lp_कुञ्चिका_Name,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_कुञ्चिका_Name,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI Get_वैयक्तिकम्_Profile_Int_A(LPCSTR lpAppName,LPCSTR lp_कुञ्चिका_Name,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI Get_वैयक्तिकम्_Profile_Int_W(LPCWSTR lpAppName,LPCWSTR lp_कुञ्चिका_Name,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_वैयक्तिकम्_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_कुञ्चिका_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_आकार,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_वैयक्तिकम्_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_कुञ्चिका_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_आकार,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_वैयक्तिकम्_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_कुञ्चिका_Name,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_वैयक्तिकम्_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_कुञ्चिका_Name,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_वैयक्तिकम्_Profile_Section_A(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_आकार,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_वैयक्तिकम्_Profile_Section_W(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_आकार,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_वैयक्तिकम्_Profile_Section_A(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_वैयक्तिकम्_Profile_Section_W(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_वैयक्तिकम्_Profile_Section_नामानि_A(LPSTR lpsz_Return_बफर,DWORD n_आकार,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_वैयक्तिकम्_Profile_Section_नामानि_W(LPWSTR lpsz_Return_बफर,DWORD n_आकार,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Get_वैयक्तिकम्_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_कुञ्चिका,LPVOID lpStruct,UINT u_आकार_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Get_वैयक्तिकम्_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_कुञ्चिका,LPVOID lpStruct,UINT u_आकार_Struct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_वैयक्तिकम्_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_कुञ्चिका,LPVOID lpStruct,UINT u_आकार_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_वैयक्तिकम्_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_कुञ्चिका,LPVOID lpStruct,UINT u_आकार_Struct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lp_मूलम्_मार्गः_Name);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lp_मूलम्_मार्गः_Name);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lp_बफर,UINT u_आकार);
  WINBASEAPI DWORD WINAPI Get_अस्थायी_मार्गः_A(DWORD n_बफर_दीर्घता,LPSTR lp_बफर);
  WINBASEAPI DWORD WINAPI Get_अस्थायी_मार्गः_W(DWORD n_बफर_दीर्घता,LPWSTR lp_बफर);
  WINBASEAPI UINT WINAPI Get_अस्थायी_File_Name_A(LPCSTR lp_मार्गः_Name,LPCSTR lp_उपसर्गः_String,UINT uUnique,LPSTR lp_अस्थायी_File_Name);
  WINBASEAPI UINT WINAPI Get_अस्थायी_File_Name_W(LPCWSTR lp_मार्गः_Name,LPCWSTR lp_उपसर्गः_String,UINT uUnique,LPWSTR lp_अस्थायी_File_Name);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lp_बफर,UINT u_आकार);

#यदि_अपरिभाषितम् RC_INVOKED
#यदि_परिभाषितम् UNICODE
#परिभाषय GetSystemWow64Directory GetSystemWow64DirectoryW
#अन्यथा
#परिभाषय GetSystemWow64Directory GetSystemWow64DirectoryA
#यदि_अन्तः

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lp_बफर,UINT u_आकार);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lp_बफर,UINT u_आकार);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *Old_मानम्);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID Ol_मानम्);

  प्रकारनिर्देश UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lp_बफर,UINT u_आकार);
  प्रकारनिर्देश UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lp_बफर,UINT u_आकार);

#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T TEXT("GetSystemWow64DirectoryA")
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T TEXT("GetSystemWow64DirectoryW")

#यदि_परिभाषितम् UNICODE
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#अन्यथा
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#परिभाषय GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय समुच्चयः_Current_Directory समुच्चयः_Current_Directory_W
#परिभाषय GetCurrentDirectory GetCurrentDirectoryW
#परिभाषय समुच्चयः_Dll_Directory समुच्चयः_Dll_Directory_W
#परिभाषय GetDllDirectory GetDllDirectoryW
#परिभाषय GetDiskFreeSpace GetDiskFreeSpaceW
#परिभाषय GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#परिभाषय CreateDirectory CreateDirectoryW
#परिभाषय CreateDirectoryEx CreateDirectoryExW
#परिभाषय RemoveDirectory RemoveDirectoryW
#परिभाषय Get_पूर्णम्_मार्गः_Name Get_पूर्णम्_मार्गः_Name_W
#परिभाषय DefineDosDevice DefineDosDeviceW
#परिभाषय QueryDosDevice QueryDosDeviceW
#परिभाषय CreateFile CreateFileW
#परिभाषय समुच्चयः_File_गुणाः समुच्चयः_File_गुणाः_W
#परिभाषय Get_File_गुणाः Get_File_गुणाः_W
#अन्यथा
#परिभाषय समुच्चयः_Current_Directory समुच्चयः_Current_Directory_A
#परिभाषय GetCurrentDirectory GetCurrentDirectoryA
#परिभाषय समुच्चयः_Dll_Directory समुच्चयः_Dll_Directory_A
#परिभाषय GetDllDirectory GetDllDirectoryA
#परिभाषय GetDiskFreeSpace GetDiskFreeSpaceA
#परिभाषय GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#परिभाषय CreateDirectory CreateDirectoryA
#परिभाषय CreateDirectoryEx CreateDirectoryExA
#परिभाषय RemoveDirectory RemoveDirectoryA
#परिभाषय Get_पूर्णम्_मार्गः_Name Get_पूर्णम्_मार्गः_Name_A
#परिभाषय DefineDosDevice DefineDosDeviceA
#परिभाषय QueryDosDevice QueryDosDeviceA
#परिभाषय CreateFile CreateFileA
#परिभाषय समुच्चयः_File_गुणाः समुच्चयः_File_गुणाः_A
#परिभाषय Get_File_गुणाः Get_File_गुणाः_A
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI समुच्चयः_Current_Directory_A(LPCSTR lp_मार्गः_Name);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Current_Directory_W(LPCWSTR lp_मार्गः_Name);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD n_बफर_दीर्घता,LPSTR lp_बफर);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD n_बफर_दीर्घता,LPWSTR lp_बफर);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Dll_Directory_A(LPCSTR lp_मार्गः_Name);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Dll_Directory_W(LPCWSTR lp_मार्गः_Name);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD n_बफर_दीर्घता,LPSTR lp_बफर);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD n_बफर_दीर्घता,LPWSTR lp_बफर);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lp_मूलम्_मार्गः_Name,LPDWORD lp_Sectors_प्रत्येकम्_Cluster,LPDWORD lp_अष्टकानि_प्रत्येकम्_Sector,LPDWORD lp_सङ्ख्या_सम्बन्धि_Free_Clusters,LPDWORD lp_योग_सङ्ख्या_सम्बन्धि_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lp_मूलम्_मार्गः_Name,LPDWORD lp_Sectors_प्रत्येकम्_Cluster,LPDWORD lp_अष्टकानि_प्रत्येकम्_Sector,LPDWORD lp_सङ्ख्या_सम्बन्धि_Free_Clusters,LPDWORD lp_योग_सङ्ख्या_सम्बन्धि_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lp_Free_अष्टकानि_उपलब्धम्_गन्तव्यम्_Caller,PULARGE_INTEGER lp_योग_सङ्ख्या_सम्बन्धि_अष्टकानि,PULARGE_INTEGER lp_योग_सङ्ख्या_सम्बन्धि_Free_अष्टकानि);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lp_Free_अष्टकानि_उपलब्धम्_गन्तव्यम्_Caller,PULARGE_INTEGER lp_योग_सङ्ख्या_सम्बन्धि_अष्टकानि,PULARGE_INTEGER lp_योग_सङ्ख्या_सम्बन्धि_Free_अष्टकानि);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lp_मार्गः_Name,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lp_मार्गः_Name,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lp_मार्गः_Name);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lp_मार्गः_Name);
  WINBASEAPI DWORD WINAPI Get_पूर्णम्_मार्गः_Name_A(LPCSTR lpFileName,DWORD n_बफर_दीर्घता,LPSTR lp_बफर,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI Get_पूर्णम्_मार्गः_Name_W(LPCWSTR lpFileName,DWORD n_बफर_दीर्घता,LPWSTR lp_बफर,LPWSTR *lpFilePart);

#परिभाषय DDD_RAW_TARGET_मार्गः 0x1
#परिभाषय DDD_REMOVE_DEFINITION 0x2
#परिभाषय DDD_EXACT_मेलनम्_ON_REMOVE 0x4
#परिभाषय DDD_NO_प्रसारणम्_SYSTEM 0x8
#परिभाषय DDD_LUID_प्रसारणम्_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lp_Target_मार्गः);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lp_Target_मार्गः);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lp_Target_मार्गः,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lp_Target_मार्गः,DWORD ucchMax);

#परिभाषय EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_बहुलकम्,LPSECURITY_गुणाः lp_Security_गुणाः,DWORD dwCreationDisposition,DWORD dw_Flags_And_गुणाः,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_बहुलकम्,LPSECURITY_गुणाः lp_Security_गुणाः,DWORD dwCreationDisposition,DWORD dw_Flags_And_गुणाः,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dw_Share_बहुलकम्,DWORD dw_Flags_And_गुणाः);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_File_गुणाः_A(LPCSTR lpFileName,DWORD dw_File_गुणाः);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_File_गुणाः_W(LPCWSTR lpFileName,DWORD dw_File_गुणाः);
  WINBASEAPI DWORD WINAPI Get_File_गुणाः_A(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_File_गुणाः_W(LPCWSTR lpFileName);

  प्रकारनिर्देश गणना GET_FILEEX_INFO_स्तराः {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_स्तराः_2;

#यदि_परिभाषितम् UNICODE
#परिभाषय Get_File_गुणाः_Ex Get_File_गुणाः_Ex_W
#परिभाषय Get_Compressed_File_आकार Get_Compressed_File_आकार_W
#परिभाषय DeleteFile DeleteFileW
#परिभाषय CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#अन्यथा
#परिभाषय Get_File_गुणाः_Ex Get_File_गुणाः_Ex_A
#परिभाषय Get_Compressed_File_आकार Get_Compressed_File_आकार_A
#परिभाषय DeleteFile DeleteFileA
#परिभाषय CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI Get_File_गुणाः_Ex_A(LPCSTR lpFileName,GET_FILEEX_INFO_स्तराः_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI Get_File_गुणाः_Ex_W(LPCWSTR lpFileName,GET_FILEEX_INFO_स्तराः_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_आकार_A(LPCSTR lpFileName,LPDWORD lp_File_आकार_उच्चः);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_आकार_W(LPCWSTR lpFileName,LPDWORD lp_File_आकार_उच्चः);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD Oem_Name_आकार,PBOOL pb_Name_अन्तर्भवति_Spaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD Oem_Name_आकार,PBOOL pb_Name_अन्तर्भवति_Spaces,PBOOL pbNameLegal);

  प्रकारनिर्देश गणना FINDEX_INFO_स्तराः {
    FindExInfoStandard,FindExInfoMaxInfoLevel
  } FINDEX_INFO_स्तराः_2;

  प्रकारनिर्देश गणना FINDEX_अन्वेषणम्_OPS {
    Find_Ex_अन्वेषणम्_Name_मेलनम्,Find_Ex_अन्वेषणम्_सीमा_गन्तव्यम्_Directories,Find_Ex_अन्वेषणम्_सीमा_गन्तव्यम्_Devices,Find_Ex_अन्वेषणम्_Max_अन्वेषणम्_Op
  } FINDEX_अन्वेषणम्_OPS_2;

#परिभाषय FIND_FIRST_EX_CASE_SENSITIVE 0x1

#यदि_परिभाषितम् UNICODE
#परिभाषय FindFirstFileEx FindFirstFileExW
#परिभाषय FindFirstFile FindFirstFileW
#परिभाषय Find_अग्र_File Find_अग्र_File_W
#परिभाषय अन्वेषणम्_मार्गः अन्वेषणम्_मार्गः_W
#परिभाषय CopyFile CopyFileW
#परिभाषय CopyFileEx CopyFileExW
#परिभाषय MoveFile MoveFileW
#परिभाषय MoveFileEx MoveFileExW
#परिभाषय Move_File_With_प्रगतिः Move_File_With_प्रगतिः_W
#परिभाषय ReplaceFile ReplaceFileW
#परिभाषय CreateHardLink CreateHardLinkW
#परिभाषय CreateNamedPipe CreateNamedPipeW
#परिभाषय GetNamedPipeHandleState GetNamedPipeHandleStateW
#परिभाषय CallNamedPipe CallNamedPipeW
#परिभाषय WaitNamedPipe WaitNamedPipeW
#परिभाषय समुच्चयः_Volume_Label समुच्चयः_Volume_Label_W
#परिभाषय GetVolumeInformation GetVolumeInformationW
#परिभाषय ClearEventLog ClearEventLogW
#परिभाषय BackupEventLog BackupEventLogW
#परिभाषय OpenEventLog OpenEventLogW
#परिभाषय पञ्जिकाकोशः_Event_Source पञ्जिकाकोशः_Event_Source_W
#परिभाषय OpenBackupEventLog OpenBackupEventLogW
#परिभाषय ReadEventLog ReadEventLogW
#परिभाषय ReportEvent ReportEventW
#परिभाषय AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#परिभाषय AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#परिभाषय Access_Check_By_Type_परिणाम_List_And_Audit_Alarm Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_W
#परिभाषय Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle_W
#परिभाषय ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#परिभाषय ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#परिभाषय ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#परिभाषय ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#परिभाषय PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#परिभाषय समुच्चयः_File_Security समुच्चयः_File_Security_W
#परिभाषय GetFileSecurity GetFileSecurityW
#परिभाषय FindFirstChangeNotification FindFirstChangeNotificationW
#परिभाषय IsBadStringPtr IsBadStringPtrW
#परिभाषय LookupAccountSid LookupAccountSidW
#परिभाषय LookupAccountName LookupAccountNameW
#परिभाषय Lookup_Privilege_मानम् Lookup_Privilege_मानम्_W
#परिभाषय LookupPrivilegeName LookupPrivilegeNameW
#परिभाषय LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#परिभाषय BuildCommDCB BuildCommDCBW
#परिभाषय BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#परिभाषय CommConfigDialog CommConfigDialogW
#परिभाषय GetDefaultCommConfig GetDefaultCommConfigW
#परिभाषय समुच्चयः_Default_Comm_Config समुच्चयः_Default_Comm_Config_W
#परिभाषय GetComputerName GetComputerNameW
#परिभाषय समुच्चयः_Computer_Name समुच्चयः_Computer_Name_W
#परिभाषय GetComputerNameEx GetComputerNameExW
#परिभाषय समुच्चयः_Computer_Name_Ex समुच्चयः_Computer_Name_Ex_W
#परिभाषय Dns_Hostname_गन्तव्यम्_Computer_Name Dns_Hostname_गन्तव्यम्_Computer_Name_W
#परिभाषय GetUserName GetUserNameW
#अन्यथा
#परिभाषय FindFirstFileEx FindFirstFileExA
#परिभाषय FindFirstFile FindFirstFileA
#परिभाषय Find_अग्र_File Find_अग्र_File_A
#परिभाषय अन्वेषणम्_मार्गः अन्वेषणम्_मार्गः_A
#परिभाषय CopyFile CopyFileA
#परिभाषय CopyFileEx CopyFileExA
#परिभाषय MoveFile MoveFileA
#परिभाषय MoveFileEx MoveFileExA
#परिभाषय Move_File_With_प्रगतिः Move_File_With_प्रगतिः_A
#परिभाषय ReplaceFile ReplaceFileA
#परिभाषय CreateHardLink CreateHardLinkA
#परिभाषय CreateNamedPipe CreateNamedPipeA
#परिभाषय GetNamedPipeHandleState GetNamedPipeHandleStateA
#परिभाषय CallNamedPipe CallNamedPipeA
#परिभाषय WaitNamedPipe WaitNamedPipeA
#परिभाषय समुच्चयः_Volume_Label समुच्चयः_Volume_Label_A
#परिभाषय GetVolumeInformation GetVolumeInformationA
#परिभाषय ClearEventLog ClearEventLogA
#परिभाषय BackupEventLog BackupEventLogA
#परिभाषय OpenEventLog OpenEventLogA
#परिभाषय पञ्जिकाकोशः_Event_Source पञ्जिकाकोशः_Event_Source_A
#परिभाषय OpenBackupEventLog OpenBackupEventLogA
#परिभाषय ReadEventLog ReadEventLogA
#परिभाषय ReportEvent ReportEventA
#परिभाषय AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#परिभाषय AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#परिभाषय Access_Check_By_Type_परिणाम_List_And_Audit_Alarm Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_A
#परिभाषय Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle_A
#परिभाषय ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#परिभाषय ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#परिभाषय ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#परिभाषय ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#परिभाषय PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#परिभाषय समुच्चयः_File_Security समुच्चयः_File_Security_A
#परिभाषय GetFileSecurity GetFileSecurityA
#परिभाषय FindFirstChangeNotification FindFirstChangeNotificationA
#परिभाषय IsBadStringPtr IsBadStringPtrA
#परिभाषय LookupAccountSid LookupAccountSidA
#परिभाषय LookupAccountName LookupAccountNameA
#परिभाषय Lookup_Privilege_मानम् Lookup_Privilege_मानम्_A
#परिभाषय LookupPrivilegeName LookupPrivilegeNameA
#परिभाषय LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#परिभाषय BuildCommDCB BuildCommDCBA
#परिभाषय BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#परिभाषय CommConfigDialog CommConfigDialogA
#परिभाषय GetDefaultCommConfig GetDefaultCommConfigA
#परिभाषय समुच्चयः_Default_Comm_Config समुच्चयः_Default_Comm_Config_A
#परिभाषय GetComputerName GetComputerNameA
#परिभाषय समुच्चयः_Computer_Name समुच्चयः_Computer_Name_A
#परिभाषय GetComputerNameEx GetComputerNameExA
#परिभाषय समुच्चयः_Computer_Name_Ex समुच्चयः_Computer_Name_Ex_A
#परिभाषय Dns_Hostname_गन्तव्यम्_Computer_Name Dns_Hostname_गन्तव्यम्_Computer_Name_A
#परिभाषय GetUserName GetUserNameA
#यदि_अन्तः

  WINBASEAPI HANDLE WINAPI FindFirstFileExA(LPCSTR lpFileName,FINDEX_INFO_स्तराः_2 fInfoLevelId,LPVOID lp_Find_File_दत्त,FINDEX_अन्वेषणम्_OPS_2 f_अन्वेषणम्_Op,LPVOID lp_अन्वेषणम्_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI FindFirstFileExW(LPCWSTR lpFileName,FINDEX_INFO_स्तराः_2 fInfoLevelId,LPVOID lp_Find_File_दत्त,FINDEX_अन्वेषणम्_OPS_2 f_अन्वेषणम्_Op,LPVOID lp_अन्वेषणम्_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI FindFirstFileA(LPCSTR lpFileName,LPWIN32_FIND_DATAA lp_Find_File_दत्त);
  WINBASEAPI HANDLE WINAPI FindFirstFileW(LPCWSTR lpFileName,LPWIN32_FIND_DATAW lp_Find_File_दत्त);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_File_A(HANDLE hFindFile,LPWIN32_FIND_DATAA lp_Find_File_दत्त);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_File_W(HANDLE hFindFile,LPWIN32_FIND_DATAW lp_Find_File_दत्त);
  WINBASEAPI DWORD WINAPI अन्वेषणम्_मार्गः_A(LPCSTR lp_मार्गः,LPCSTR lpFileName,LPCSTR lpExtension,DWORD n_बफर_दीर्घता,LPSTR lp_बफर,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI अन्वेषणम्_मार्गः_W(LPCWSTR lp_मार्गः,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD n_बफर_दीर्घता,LPWSTR lp_बफर,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  प्रकारनिर्देश DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER योग_File_आकार,LARGE_INTEGER योग_अष्टकानि_Transferred,LARGE_INTEGER प्रवाहः_आकार,LARGE_INTEGER प्रवाहः_अष्टकानि_Transferred,DWORD dw_प्रवाहः_सङ्ख्या,DWORD dwCallbackReason,HANDLE hSourceFile,HANDLE hDestinationFile,LPVOID lp_दत्त);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_प्रगतिः_Routine,LPVOID lp_दत्त,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_प्रगतिः_Routine,LPVOID lp_दत्त,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_प्रगतिः_A(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_प्रगतिः_Routine,LPVOID lp_दत्त,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_प्रगतिः_W(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_प्रगतिः_Routine,LPVOID lp_दत्त,DWORD dwFlags);

#परिभाषय MOVEFILE_REPLACE_EXISTING 0x1
#परिभाषय MOVEFILE_COPY_ALLOWED 0x2
#परिभाषय MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#परिभाषय MOVEFILE_WRITE_THROUGH 0x8
#परिभाषय MOVEFILE_CREATE_HARDLINK 0x10
#परिभाषय MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_गुणाः lp_Security_गुणाः);

  प्रकारनिर्देश गणना प्रवाहः_INFO_स्तराः {
    Find_प्रवाहः_Info_Standard,Find_प्रवाहः_Info_Max_Info_Level
  } प्रवाहः_INFO_स्तराः_2;

  प्रकारनिर्देश संरचना WIN32_FIND_प्रवाहः_दत्त {
    LARGE_INTEGER प्रवाहः_आकार;
    WCHAR c_प्रवाहः_Name[MAX_मार्गः + 36];
  } WIN32_FIND_प्रवाहः_दत्त_2,*PWIN32_FIND_प्रवाहः_दत्त;

  HANDLE WINAPI Find_First_प्रवाहः_W(LPCWSTR lpFileName,प्रवाहः_INFO_स्तराः_2 InfoLevel,LPVOID lp_Find_प्रवाहः_दत्त,DWORD dwFlags);
  WINBOOL WINAPI Find_अग्र_प्रवाहः_W(HANDLE h_Find_प्रवाहः,LPVOID lp_Find_प्रवाहः_दत्त);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dw_Open_बहुलकम्,DWORD dw_Pipe_बहुलकम्,DWORD nMaxInstances,DWORD n_बहिर्गमनम्_बफर_आकार,DWORD n_अन्तर्_बफर_आकार,DWORD n_Default_Time_बहिर्गमनम्,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dw_Open_बहुलकम्,DWORD dw_Pipe_बहुलकम्,DWORD nMaxInstances,DWORD n_बहिर्गमनम्_बफर_आकार,DWORD n_अन्तर्_बफर_आकार,DWORD n_Default_Time_बहिर्गमनम्,LPSECURITY_गुणाः lp_Security_गुणाः);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_गणनम्,LPDWORD lp_Collect_दत्त_Timeout,LPSTR lpUserName,DWORD n_Max_User_Name_आकार);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_गणनम्,LPDWORD lp_Collect_दत्त_Timeout,LPWSTR lpUserName,DWORD n_Max_User_Name_आकार);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lp_अन्तर्_बफर,DWORD n_अन्तर्_बफर_आकार,LPVOID lp_बहिर्गमनम्_बफर,DWORD n_बहिर्गमनम्_बफर_आकार,LPDWORD lp_अष्टकानि_Read,DWORD n_Time_बहिर्गमनम्);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lp_अन्तर्_बफर,DWORD n_अन्तर्_बफर_आकार,LPVOID lp_बहिर्गमनम्_बफर,DWORD n_बहिर्गमनम्_बफर_आकार,LPDWORD lp_अष्टकानि_Read,DWORD n_Time_बहिर्गमनम्);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD n_Time_बहिर्गमनम्);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD n_Time_बहिर्गमनम्);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Volume_Label_A(LPCSTR lp_मूलम्_मार्गः_Name,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Volume_Label_W(LPCWSTR lp_मूलम्_मार्गः_Name,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI समुच्चयः_File_Apis_गन्तव्यम्_OEM(VOID);
  WINBASEAPI VOID WINAPI समुच्चयः_File_Apis_गन्तव्यम्_ANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lp_मूलम्_मार्गः_Name,LPSTR lp_Volume_Name_बफर,DWORD n_Volume_Name_आकार,LPDWORD lp_Volume_Serial_सङ्ख्या,LPDWORD lp_अधिकतमम्_Component_दीर्घता,LPDWORD lpFileSystemFlags,LPSTR lp_File_System_Name_बफर,DWORD n_File_System_Name_आकार);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lp_मूलम्_मार्गः_Name,LPWSTR lp_Volume_Name_बफर,DWORD n_Volume_Name_आकार,LPDWORD lp_Volume_Serial_सङ्ख्या,LPDWORD lp_अधिकतमम्_Component_दीर्घता,LPDWORD lpFileSystemFlags,LPWSTR lp_File_System_Name_बफर,DWORD n_File_System_Name_आकार);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI DeregisterEventSource(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI Get_सङ्ख्या_सम्बन्धि_Event_Log_लेखाः(HANDLE hEventLog,PDWORD सङ्ख्या_सम्बन्धि_लेखाः);
  WINADVAPI WINBOOL WINAPI Get_Oldest_Event_Log_लेखः(HANDLE hEventLog,PDWORD Oldest_लेखः);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI पञ्जिकाकोशः_Event_Source_A(LPCSTR lpUNCServerName,LPCSTR lpSourceName);
  WINADVAPI HANDLE WINAPI पञ्जिकाकोशः_Event_Source_W(LPCWSTR lpUNCServerName,LPCWSTR lpSourceName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_लेखः_विस्थापनम्,LPVOID lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Read,DWORD *pn_अष्टकानि_Read,DWORD *pn_Min_सङ्ख्या_सम्बन्धि_अष्टकानि_Needed);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_लेखः_विस्थापनम्,LPVOID lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Read,DWORD *pn_अष्टकानि_Read,DWORD *pn_Min_सङ्ख्या_सम्बन्धि_अष्टकानि_Needed);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD w_अङ्कः_वाक्यानि,DWORD dw_दत्त_आकार,LPCSTR *lp_वाक्यानि,LPVOID lp_Raw_दत्त);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,WORD wType,WORD wCategory,DWORD dwEventID,PSID lpUserSid,WORD w_अङ्कः_वाक्यानि,DWORD dw_दत्त_आकार,LPCWSTR *lp_वाक्यानि,LPVOID lp_Raw_दत्त);

#परिभाषय EVENTLOG_पूर्णम्_INFO 0

  प्रकारनिर्देश संरचना EVENTLOG_पूर्णम्_INFORMATION {
    DWORD dw_पूर्णम्;
  } EVENTLOG_पूर्णम्_INFORMATION_2,*LPEVENTLOG_पूर्णम्_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lp_बफर,DWORD cb_Buf_आकार,LPDWORD pcb_अष्टकानि_Needed);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_दीर्घता,LPDWORD lpn_दीर्घता_Needed);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI Revert_गन्तव्यम्_Self(VOID);
  WINADVAPI WINBOOL WINAPI समुच्चयः_Thread_Token (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_समुच्चयः Privilege_समुच्चयः,LPDWORD Privilege_समुच्चयः_दीर्घता,LPDWORD GrantedAccess,LPBOOL Access_स्थितिः);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_दीर्घता,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_समुच्चयः Privilege_समुच्चयः,LPDWORD Privilege_समुच्चयः_दीर्घता,LPDWORD GrantedAccess,LPBOOL Access_स्थितिः);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_दीर्घता,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_समुच्चयः Privilege_समुच्चयः,LPDWORD Privilege_समुच्चयः_दीर्घता,LPDWORD GrantedAccessList,LPDWORD Access_स्थितिः_List);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_दीर्घता,PDWORD Return_दीर्घता);
  WINADVAPI WINBOOL WINAPI समुच्चयः_Token_Information(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_दीर्घता);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD बफर_दीर्घता,PTOKEN_PRIVILEGES PreviousState,PDWORD Return_दीर्घता);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL Reset_गन्तव्यम्_Default,PTOKEN_GROUPS NewState,DWORD बफर_दीर्घता,PTOKEN_GROUPS PreviousState,PDWORD Return_दीर्घता);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_समुच्चयः RequiredPrivileges,LPBOOL pf_परिणाम);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_स्थितिः,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_स्थितिः,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_दीर्घता,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_स्थितिः,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_दीर्घता,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_स्थितिः,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_A(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_दीर्घता,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_स्थितिः_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_W(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_दीर्घता,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_स्थितिः_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle_A(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_दीर्घता,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_स्थितिः_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_परिणाम_List_And_Audit_Alarm_By_Handle_W(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_दीर्घता,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_स्थितिः_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_समुच्चयः Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_समुच्चयः Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_समुच्चयः Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_समुच्चयः Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_समुच्चयः Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_समुच्चयः Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI Is_Well_ज्ञातम्_Sid(PSID pSid,WELL_ज्ञातम्_SID_TYPE Well_ज्ञातम्_Sid_Type);
  WINADVAPI WINBOOL WINAPI Create_Well_ज्ञातम्_Sid(WELL_ज्ञातम्_SID_TYPE Well_ज्ञातम्_Sid_Type,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI Equal_उपसर्गः_Sid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI Get_Sid_दीर्घता_Required (UCHAR n_Sub_Authority_गणनम्);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_गणनम्,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_गणनम्);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI Get_Sid_Sub_Authority_गणनम्(PSID pSid);
  WINADVAPI DWORD WINAPI Get_दीर्घता_Sid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD n_Destination_Sid_दीर्घता,PSID pDestinationSid,PSID pSourceSid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI Map_Generic_आवरणम्(PDWORD Access_आवरणम्,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD n_Acl_दीर्घता,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_दीर्घता,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI समुच्चयः_Acl_Information(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_दीर्घता,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Starting_Ace_सूचकांक,LPVOID pAceList,DWORD n_Ace_List_दीर्घता);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dw_Ace_सूचकांक);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dw_Ace_सूचकांक,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Access_Allowed_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_आवरणम्,PSID pSid);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Access_Allowed_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_आवरणम्,PSID pSid);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Access_Denied_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_आवरणम्,PSID pSid);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Access_Denied_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_आवरणम्,PSID pSid);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Audit_Access_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Access_आवरणम्,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Audit_Access_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dw_Access_आवरणम्,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Access_Allowed_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_आवरणम्,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Access_Denied_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_आवरणम्,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI सङ्कलय_Audit_Access_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_आवरणम्,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI FindFirstFreeAce(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI Get_Security_Descriptor_दीर्घता(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI समुच्चयः_Security_Descriptor_Control(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL Control_द्वयङ्काः_सम्बन्धि_Interest,SECURITY_DESCRIPTOR_CONTROL Control_द्वयङ्काः_गन्तव्यम्_समुच्चयः);
  WINADVAPI WINBOOL WINAPI समुच्चयः_Security_Descriptor_Dacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI समुच्चयः_Security_Descriptor_Sacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI समुच्चयः_Security_Descriptor_Owner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI समुच्चयः_Security_Descriptor_गणः(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID p_गणः,WINBOOL b_गणः_Defaulted);
  WINADVAPI WINBOOL WINAPI Get_Security_Descriptor_गणः(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *p_गणः,LPBOOL lpb_गणः_Defaulted);
  WINADVAPI DWORD WINAPI समुच्चयः_Security_Descriptor_RMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI Create_वैयक्तिकम्_Object_Security(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Convert_गन्तव्यम्_Auto_Inherit_वैयक्तिकम्_Object_Security(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_वैयक्तिकम्_Object_Security_Ex(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_वैयक्तिकम्_Object_Security_With_गुणजः_Inheritance(PSECURITY_DESCRIPTOR ParentDescriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG Guid_गणनम्,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI समुच्चयः_वैयक्तिकम्_Object_Security (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI समुच्चयः_वैयक्तिकम्_Object_Security_Ex (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI Get_वैयक्तिकम्_Object_Security(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD Descriptor_दीर्घता,PDWORD Return_दीर्घता);
  WINADVAPI WINBOOL WINAPI Destroy_वैयक्तिकम्_Object_Security(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_बफर_दीर्घता);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdw_Absolute_Security_Descriptor_आकार,PACL pDacl,LPDWORD lpdw_Dacl_आकार,PACL pSacl,LPDWORD lpdw_Sacl_आकार,PSID pOwner,LPDWORD lpdw_Owner_आकार,PSID p_Primary_गणः,LPDWORD lpdw_Primary_गणः_आकार);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_बफर_आकार);
  WINADVAPI WINBOOL WINAPI समुच्चयः_File_Security_A(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI समुच्चयः_File_Security_W(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_दीर्घता,LPDWORD lpn_दीर्घता_Needed);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_दीर्घता,LPDWORD lpn_दीर्घता_Needed);
  WINADVAPI WINBOOL WINAPI समुच्चयः_Kernel_Object_Security(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationA(LPCSTR lp_मार्गः_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI FindFirstChangeNotificationW(LPCWSTR lp_मार्गः_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI FindCloseChangeNotification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lp_बफर,DWORD n_बफर_दीर्घता,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lp_अष्टकानि_Returned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI Virtual_तालकम्(LPVOID lp_स्थानाङ्कः,आकार_T dw_आकार);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lp_स्थानाङ्कः,आकार_T dw_आकार);
  WINBASEAPI LPVOID WINAPI Map_View_सम्बन्धि_File_Ex(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_विस्थापनम्_उच्चः,DWORD dw_File_विस्थापनम्_नीचः,आकार_T dw_सङ्ख्या_सम्बन्धि_अष्टकानि_गन्तव्यम्_Map,LPVOID lp_आधारः_स्थानाङ्कः);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_प्राथमिकता_Class(HANDLE hProcess,DWORD dw_प्राथमिकता_Class);
  WINBASEAPI DWORD WINAPI Get_प्राथमिकता_Class(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI Is_Bad_संहिता_Ptr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_मानम्_A(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_मानम्_W(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
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
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Default_Comm_Config_A(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Default_Comm_Config_W(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_आकार);

#परिभाषय MAX_COMPUTERNAME_दीर्घता 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lp_बफर,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lp_बफर,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Computer_Name_A(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Computer_Name_W(LPCWSTR lpComputerName);

  प्रकारनिर्देश गणना _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lp_बफर,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lp_बफर,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Computer_Name_Ex_A(COMPUTER_NAME_FORMAT NameType,LPCSTR lp_बफर);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Computer_Name_Ex_W(COMPUTER_NAME_FORMAT NameType,LPCWSTR lp_बफर);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_गन्तव्यम्_Computer_Name_A(LPCSTR Hostname,LPSTR ComputerName,LPDWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_गन्तव्यम्_Computer_Name_W(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD n_आकार);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lp_बफर,LPDWORD pcb_बफर);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lp_बफर,LPDWORD pcb_बफर);

#परिभाषय LOGON32_LOGON_INTERACTIVE 2
#परिभाषय LOGON32_LOGON_जालम् 3
#परिभाषय LOGON32_LOGON_BATCH 4
#परिभाषय LOGON32_LOGON_SERVICE 5
#परिभाषय LOGON32_LOGON_UNLOCK 7
#परिभाषय LOGON32_LOGON_जालम्_CLEARTEXT 8
#परिभाषय LOGON32_LOGON_NEW_CREDENTIALS 9

#परिभाषय LOGON32_PROVIDER_DEFAULT 0
#परिभाषय LOGON32_PROVIDER_WINNT35 1
#परिभाषय LOGON32_PROVIDER_WINNT40 2
#परिभाषय LOGON32_PROVIDER_WINNT50 3

#यदि_परिभाषितम् UNICODE
#परिभाषय LogonUser LogonUserW
#परिभाषय LogonUserEx LogonUserExW
#परिभाषय CreateProcessAsUser CreateProcessAsUserW
#अन्यथा
#परिभाषय LogonUser LogonUserA
#परिभाषय LogonUserEx LogonUserExA
#परिभाषय CreateProcessAsUser CreateProcessAsUserA
#यदि_अन्तः

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_बफर,LPDWORD pdw_Profile_दीर्घता,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_बफर,LPDWORD pdw_Profile_दीर्घता,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lp_Command_पङ्क्तिः,LPSECURITY_गुणाः lp_Process_गुणाः,LPSECURITY_गुणाः lp_Thread_गुणाः,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lp_Command_पङ्क्तिः,LPSECURITY_गुणाः lp_Process_गुणाः,LPSECURITY_गुणाः lp_Thread_गुणाः,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#परिभाषय LOGON_WITH_PROFILE 0x1
#परिभाषय LOGON_NETCREDENTIALS_ONLY 0x2
#परिभाषय LOGON_ZERO_PASSWORD_बफर 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_पङ्क्तिः,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_पङ्क्तिः,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_गुणाः lp_Token_गुणाः,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD Disable_Sid_गणनम्,PSID_AND_गुणाः Sids_गन्तव्यम्_Disable,DWORD Delete_Privilege_गणनम्,PLUID_AND_गुणाः Privileges_गन्तव्यम्_Delete,DWORD Restricted_Sid_गणनम्,PSID_AND_गुणाः Sids_गन्तव्यम्_Restrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID Sid_गन्तव्यम्_Check,PBOOL IsMember);

  प्रकारनिर्देश WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI पञ्जिकाकोशः_Wait_For_Single_Object(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI पञ्जिकाकोशः_Wait_For_Single_Object_Ex(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI QueueUserWorkItem(LPTHREAD_START_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI CreateTimerQueue(VOID);
  WINBASEAPI WINBOOL WINAPI CreateTimerQueueTimer(PHANDLE phNewTimer,HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI ChangeTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,ULONG DueTime,ULONG Period);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueueEx(HANDLE TimerQueue,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI समुच्चयः_Timer_Queue_Timer(HANDLE TimerQueue,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD DueTime,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI CancelTimerQueueTimer(HANDLE TimerQueue,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI DeleteTimerQueue(HANDLE TimerQueue);

#परिभाषय HW_PROFILE_GUIDLEN 39
#परिभाषय MAX_PROFILE_LEN 80

#परिभाषय DOCKINFO_UNDOCKED (0x1)
#परिभाषय DOCKINFO_DOCKED (0x2)
#परिभाषय DOCKINFO_USER_SUPPLIED (0x4)
#परिभाषय DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#परिभाषय DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  प्रकारनिर्देश संरचना चिह्नकम्_HW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  प्रकारनिर्देश संरचना चिह्नकम्_HW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश HW_PROFILE_INFOW HW_PROFILE_INFO;
  प्रकारनिर्देश LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#अन्यथा
  प्रकारनिर्देश HW_PROFILE_INFOA HW_PROFILE_INFO;
  प्रकारनिर्देश LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय GetCurrentHwProfile GetCurrentHwProfileW
#परिभाषय Get_संस्करणम्_Ex Get_संस्करणम्_Ex_W
#परिभाषय Verify_संस्करणम्_Info Verify_संस्करणम्_Info_W
#अन्यथा
#परिभाषय GetCurrentHwProfile GetCurrentHwProfileA
#परिभाषय Get_संस्करणम्_Ex Get_संस्करणम्_Ex_A
#परिभाषय Verify_संस्करणम्_Info Verify_संस्करणम्_Info_A
#यदि_अन्तः

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI Query_Performance_गणक(LARGE_INTEGER *lp_Performance_गणनम्);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI Get_संस्करणम्_Ex_A(LPOSVERSIONINFOA lp_संस्करणम्_Information);
  WINBASEAPI WINBOOL WINAPI Get_संस्करणम्_Ex_W(LPOSVERSIONINFOW lp_संस्करणम्_Information);
  WINBASEAPI WINBOOL WINAPI Verify_संस्करणम्_Info_A(LPOSVERSIONINFOEXA lp_संस्करणम्_Information,DWORD dw_Type_आवरणम्,DWORDLONG dwl_Condition_आवरणम्);
  WINBASEAPI WINBOOL WINAPI Verify_संस्करणम्_Info_W(LPOSVERSIONINFOEXW lp_संस्करणम्_Information,DWORD dw_Type_आवरणम्,DWORDLONG dwl_Condition_आवरणम्);

#अन्तर्भाव <winerror.h>

#परिभाषय TC_प्रसामान्यम् 0
#परिभाषय TC_HARDERR 1
#परिभाषय TC_GP_TRAP 2
#परिभाषय TC_SIGNAL 3

#परिभाषय AC_पङ्क्तिः_OFFLINE 0x0
#परिभाषय AC_पङ्क्तिः_ONLINE 0x1
#परिभाषय AC_पङ्क्तिः_BACKUP_POWER 0x2
#परिभाषय AC_पङ्क्तिः_UNKNOWN 0xff

#परिभाषय BATTERY_FLAG_उच्चः 0x1
#परिभाषय BATTERY_FLAG_नीचः 0x2
#परिभाषय BATTERY_FLAG_CRITICAL 0x4
#परिभाषय BATTERY_FLAG_CHARGING 0x8
#परिभाषय BATTERY_FLAG_NO_BATTERY 0x80
#परिभाषय BATTERY_FLAG_UNKNOWN 0xff

#परिभाषय BATTERY_PERCENTAGE_UNKNOWN 0xff

#परिभाषय BATTERY_LIFE_UNKNOWN 0xffffffff

  प्रकारनिर्देश संरचना SYSTEM_POWER_स्थितिः {
    BYTE ACLine_स्थितिः;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD BatteryLifeTime;
    DWORD Battery_पूर्णम्_Life_Time;
  } SYSTEM_POWER_स्थितिः_2,*LPSYSTEM_POWER_स्थितिः;

#यदि_परिभाषितम् UNICODE
#परिभाषय CreateJobObject CreateJobObjectW
#परिभाषय OpenJobObject OpenJobObjectW
#परिभाषय FindFirstVolume FindFirstVolumeW
#परिभाषय Find_अग्र_Volume Find_अग्र_Volume_W
#परिभाषय FindFirstVolumeMountPoint FindFirstVolumeMountPointW
#परिभाषय Find_अग्र_Volume_Mount_Point Find_अग्र_Volume_Mount_Point_W
#परिभाषय समुच्चयः_Volume_Mount_Point समुच्चयः_Volume_Mount_Point_W
#परिभाषय DeleteVolumeMountPoint DeleteVolumeMountPointW
#परिभाषय GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
#परिभाषय Get_Volume_मार्गः_Name Get_Volume_मार्गः_Name_W
#परिभाषय Get_Volume_मार्गः_नामानि_For_Volume_Name Get_Volume_मार्गः_नामानि_For_Volume_Name_W
#अन्यथा
#परिभाषय CreateJobObject CreateJobObjectA
#परिभाषय OpenJobObject OpenJobObjectA
#परिभाषय FindFirstVolume FindFirstVolumeA
#परिभाषय Find_अग्र_Volume Find_अग्र_Volume_A
#परिभाषय FindFirstVolumeMountPoint FindFirstVolumeMountPointA
#परिभाषय Find_अग्र_Volume_Mount_Point Find_अग्र_Volume_Mount_Point_A
#परिभाषय समुच्चयः_Volume_Mount_Point समुच्चयः_Volume_Mount_Point_A
#परिभाषय DeleteVolumeMountPoint DeleteVolumeMountPointA
#परिभाषय GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
#परिभाषय Get_Volume_मार्गः_Name Get_Volume_मार्गः_Name_A
#परिभाषय Get_Volume_मार्गः_नामानि_For_Volume_Name Get_Volume_मार्गः_नामानि_For_Volume_Name_A
#यदि_अन्तः

  WINBOOL WINAPI Get_System_Power_स्थितिः(LPSYSTEM_POWER_स्थितिः lp_System_Power_स्थितिः);
  WINBOOL WINAPI समुच्चयः_System_Power_State(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI Allocate_User_Physical_पृष्ठानि(HANDLE hProcess,PULONG_PTR सङ्ख्या_सम्बन्धि_पृष्ठानि,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI Free_User_Physical_पृष्ठानि(HANDLE hProcess,PULONG_PTR सङ्ख्या_सम्बन्धि_पृष्ठानि,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_पृष्ठानि(PVOID Virtual_स्थानाङ्कः,ULONG_PTR सङ्ख्या_सम्बन्धि_पृष्ठानि,PULONG_PTR PageArray);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_पृष्ठानि_Scatter(PVOID *Virtual_स्थानाङ्काः,ULONG_PTR सङ्ख्या_सम्बन्धि_पृष्ठानि,PULONG_PTR PageArray);
  WINBASEAPI HANDLE WINAPI CreateJobObjectA(LPSECURITY_गुणाः lp_Job_गुणाः,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateJobObjectW(LPSECURITY_गुणाः lp_Job_गुणाः,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenJobObjectW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI नियोजय_Process_गन्तव्यम्_Job_Object(HANDLE hJob,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI TerminateJobObject(HANDLE hJob,UINT u_Exit_संहिता);
  WINBASEAPI WINBOOL WINAPI QueryInformationJobObject(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cb_Job_Object_Information_दीर्घता,LPDWORD lp_Return_दीर्घता);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Information_Job_Object(HANDLE hJob,JOBOBJECTINFOCLASS JobObjectInformationClass,LPVOID lpJobObjectInformation,DWORD cb_Job_Object_Information_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Is_Process_अन्तर्_Job(HANDLE ProcessHandle,HANDLE JobHandle,PBOOL परिणाम_3);
  WINBASEAPI WINBOOL WINAPI Create_Job_समुच्चयः(ULONG अङ्कः_Job,PJOB_समुच्चयः_ARRAY User_Job_समुच्चयः,ULONG Flags);
  WINBASEAPI PVOID WINAPI सङ्कलय_Vectored_Exception_Handler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI सङ्कलय_Vectored_Continue_Handler (ULONG First,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeA(LPSTR lpszVolumeName,DWORD cch_बफर_दीर्घता);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeW(LPWSTR lpszVolumeName,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Volume_A(HANDLE hFindVolume,LPSTR lpszVolumeName,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Volume_W(HANDLE hFindVolume,LPWSTR lpszVolumeName,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI FindVolumeClose(HANDLE hFindVolume);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointA(LPCSTR lpsz_मूलम्_मार्गः_Name,LPSTR lpszVolumeMountPoint,DWORD cch_बफर_दीर्घता);
  WINBASEAPI HANDLE WINAPI FindFirstVolumeMountPointW(LPCWSTR lpsz_मूलम्_मार्गः_Name,LPWSTR lpszVolumeMountPoint,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Volume_Mount_Point_A(HANDLE hFindVolumeMountPoint,LPSTR lpszVolumeMountPoint,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Find_अग्र_Volume_Mount_Point_W(HANDLE hFindVolumeMountPoint,LPWSTR lpszVolumeMountPoint,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI FindVolumeMountPointClose(HANDLE hFindVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Volume_Mount_Point_A(LPCSTR lpszVolumeMountPoint,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Volume_Mount_Point_W(LPCWSTR lpszVolumeMountPoint,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointA(LPCSTR lpszVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI DeleteVolumeMountPointW(LPCWSTR lpszVolumeMountPoint);
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointA(LPCSTR lpszVolumeMountPoint,LPSTR lpszVolumeName,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI GetVolumeNameForVolumeMountPointW(LPCWSTR lpszVolumeMountPoint,LPWSTR lpszVolumeName,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Get_Volume_मार्गः_Name_A(LPCSTR lpszFileName,LPSTR lpsz_Volume_मार्गः_Name,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Get_Volume_मार्गः_Name_W(LPCWSTR lpszFileName,LPWSTR lpsz_Volume_मार्गः_Name,DWORD cch_बफर_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Get_Volume_मार्गः_नामानि_For_Volume_Name_A(LPCSTR lpszVolumeName,LPCH lpsz_Volume_मार्गः_नामानि,DWORD cch_बफर_दीर्घता,PDWORD lpcch_Return_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Get_Volume_मार्गः_नामानि_For_Volume_Name_W(LPCWSTR lpszVolumeName,LPWCH lpsz_Volume_मार्गः_नामानि,DWORD cch_बफर_दीर्घता,PDWORD lpcch_Return_दीर्घता);

#परिभाषय ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#परिभाषय ACTCTX_FLAG_LANGID_VALID 0x2
#परिभाषय ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#परिभाषय ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#परिभाषय ACTCTX_FLAG_समुच्चयः_PROCESS_DEFAULT 0x10
#परिभाषय ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#परिभाषय ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF 0x40
#परिभाषय ACTCTX_FLAG_HMODULE_VALID 0x80

  प्रकारनिर्देश संरचना चिह्नकम्_ACTCTXA {
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

  प्रकारनिर्देश संरचना चिह्नकम्_ACTCTXW {
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

  प्रकारनिर्देश ध्रुव ACTCTXA *PCACTCTXA;
  प्रकारनिर्देश ध्रुव ACTCTXW *PCACTCTXW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश ACTCTXW ACTCTX;
  प्रकारनिर्देश PACTCTXW PACTCTX;
  प्रकारनिर्देश PCACTCTXW PCACTCTX;
#अन्यथा
  प्रकारनिर्देश ACTCTXA ACTCTX;
  प्रकारनिर्देश PACTCTXA PACTCTX;
  प्रकारनिर्देश PCACTCTXA PCACTCTX;
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय CreateActCtx CreateActCtxW
#अन्यथा
#परिभाषय CreateActCtx CreateActCtxA
#यदि_अन्तः

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI सङ्कलय_Ref_Act_Ctx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#परिभाषय DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  प्रकारनिर्देश संरचना चिह्नकम्_ACTCTX_SECTION_KEYED_दत्त_2600 {
    ULONG cb_आकार;
    ULONG ul_दत्त_Format_संस्करणम्;
    PVOID lp_दत्त;
    ULONG ul_दीर्घता;
    PVOID lp_Section_Global_दत्त;
    ULONG ul_Section_Global_दत्त_दीर्घता;
    PVOID lp_Section_आधारः;
    ULONG ul_Section_योग_दीर्घता;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_सूचकांक;
  } ACTCTX_SECTION_KEYED_दत्त_2600,*PACTCTX_SECTION_KEYED_दत्त_2600;

  प्रकारनिर्देश ध्रुव ACTCTX_SECTION_KEYED_दत्त_2600 *PCACTCTX_SECTION_KEYED_दत्त_2600;

  प्रकारनिर्देश संरचना चिह्नकम्_ACTCTX_SECTION_KEYED_दत्त_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lp_Section_आधारः;
    ULONG ul_Section_दीर्घता;
    PVOID lp_Section_Global_दत्त_आधारः;
    ULONG ul_Section_Global_दत्त_दीर्घता;
  } ACTCTX_SECTION_KEYED_दत्त_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_दत्त_ASSEMBLY_METADATA;

  प्रकारनिर्देश ध्रुव ACTCTX_SECTION_KEYED_दत्त_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_दत्त_ASSEMBLY_METADATA;

  प्रकारनिर्देश संरचना चिह्नकम्_ACTCTX_SECTION_KEYED_दत्त {
    ULONG cb_आकार;
    ULONG ul_दत्त_Format_संस्करणम्;
    PVOID lp_दत्त;
    ULONG ul_दीर्घता;
    PVOID lp_Section_Global_दत्त;
    ULONG ul_Section_Global_दत्त_दीर्घता;
    PVOID lp_Section_आधारः;
    ULONG ul_Section_योग_दीर्घता;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_सूचकांक;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_दत्त_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_दत्त,*PACTCTX_SECTION_KEYED_दत्त;

  प्रकारनिर्देश ध्रुव ACTCTX_SECTION_KEYED_दत्त *PCACTCTX_SECTION_KEYED_दत्त;

#परिभाषय FIND_ACTCTX_SECTION_कुञ्चिका_RETURN_HACTCTX 0x1
#परिभाषय FIND_ACTCTX_SECTION_कुञ्चिका_RETURN_FLAGS 0x2
#परिभाषय FIND_ACTCTX_SECTION_कुञ्चिका_RETURN_ASSEMBLY_METADATA 0x4

#यदि_परिभाषितम् UNICODE
#परिभाषय FindActCtxSectionString FindActCtxSectionStringW
#अन्यथा
#परिभाषय FindActCtxSectionString FindActCtxSectionStringA
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringA(DWORD dwFlags,ध्रुव GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lp_String_गन्तव्यम्_Find,PACTCTX_SECTION_KEYED_दत्त Returned_दत्त);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionStringW(DWORD dwFlags,ध्रुव GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lp_String_गन्तव्यम्_Find,PACTCTX_SECTION_KEYED_दत्त Returned_दत्त);
  WINBASEAPI WINBOOL WINAPI FindActCtxSectionGuid(DWORD dwFlags,ध्रुव GUID *lpExtensionGuid,ULONG ulSectionId,ध्रुव GUID *lp_Guid_गन्तव्यम्_Find,PACTCTX_SECTION_KEYED_दत्त Returned_दत्त);

#यदि_अपरिभाषितम् RC_INVOKED
#यदि_अपरिभाषितम् ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  प्रकारनिर्देश संरचना _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  प्रकारनिर्देश ध्रुव संरचना _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#परिभाषय ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय QUERY_ACTCTX_FLAG_USE_सक्रिय_ACTCTX 0x4
#परिभाषय QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#परिभाषय QUERY_ACTCTX_FLAG_ACTCTX_IS_स्थानाङ्कः 0x10
#परिभाषय QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_बफर,आकार_T cb_बफर,आकार_T *pcbWrittenOrRequired);

  प्रकारनिर्देश WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_बफर,आकार_T cb_बफर,आकार_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI Process_Id_गन्तव्यम्_Session_Id(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGet_सक्रिय_Console_Session_Id();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION बफर_3,PDWORD Returned_दीर्घता);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Highest_ग्रन्थिः_सङ्ख्या(PULONG Highest_ग्रन्थिः_सङ्ख्या);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Processor_ग्रन्थिः(UCHAR Processor,PUCHAR ग्रन्थिः_सङ्ख्या);
  WINBASEAPI WINBOOL WINAPI Get_Numa_ग्रन्थिः_Processor_आवरणम्(UCHAR ग्रन्थिः_2,PULONGLONG Processor_आवरणम्);
  WINBASEAPI WINBOOL WINAPI Get_Numa_उपलब्धम्_स्मृतिः_ग्रन्थिः(UCHAR ग्रन्थिः_2,PULONGLONG उपलब्धम्_अष्टकानि);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
