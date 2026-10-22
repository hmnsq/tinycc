/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _WINBASE_
#تعریف_کړه _WINBASE_

#تعریف_کړه WINADVAPI DECLSPEC_IMPORT
#تعریف_کړه WINBASEAPI DECLSPEC_IMPORT
#تعریف_کړه ZAWPROXYAPI DECLSPEC_IMPORT

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#تعریف_کړه Define_Handle_جدول(w) ((w),TRUE)
#تعریف_کړه حد_Ems_پاڼې(dw)
#تعریف_کړه سېټ_بدلون_Area_اندازه(w) (w)
#تعریف_کړه قلف_Segment(w) GlobalFix((HANDLE)(w))
#تعریف_کړه UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#تعریف_کړه Get_Current_وخت() Get_Tick_شمېر()

#تعریف_کړه Yield()

#تعریف_کړه INVALID_HANDLE_ارزښت ((HANDLE)(LONG_PTR)-1)
#تعریف_کړه INVALID_FILE_اندازه ((DWORD)0xffffffff)
#تعریف_کړه INVALID_سېټ_FILE_اشاره_ګر ((DWORD)-1)
#تعریف_کړه INVALID_FILE_ځانګړتیاوې ((DWORD)-1)

#تعریف_کړه FILE_BEGIN 0
#تعریف_کړه FILE_CURRENT 1
#تعریف_کړه FILE_پای_ټکی 2

#تعریف_کړه وخت_ZONE_ID_INVALID ((DWORD)0xffffffff)

#تعریف_کړه WAIT_FAILED ((DWORD)0xffffffff)
#تعریف_کړه WAIT_OBJECT_0 ((حالت_WAIT_0) + 0)
#تعریف_کړه WAIT_ABANDONED ((حالت_ABANDONED_WAIT_0) + 0)
#تعریف_کړه WAIT_ABANDONED_0 ((حالت_ABANDONED_WAIT_0) + 0)
#تعریف_کړه WAIT_IO_COMPLETION حالت_USER_APC
#تعریف_کړه STILL_فعال حالت_PENDING
#تعریف_کړه EXCEPTION_ACCESS_VIOLATION حالت_ACCESS_VIOLATION
#تعریف_کړه EXCEPTION_DATATYPE_MISALIGNMENT حالت_DATATYPE_MISALIGNMENT
#تعریف_کړه EXCEPTION_BREAKPOINT حالت_BREAKPOINT
#تعریف_کړه EXCEPTION_SINGLE_ګام حالت_SINGLE_ګام
#تعریف_کړه EXCEPTION_ARRAY_BOUNDS_EXCEEDED حالت_ARRAY_BOUNDS_EXCEEDED
#تعریف_کړه EXCEPTION_FLT_DENORMAL_عملوند حالت_FLOAT_DENORMAL_عملوند
#تعریف_کړه EXCEPTION_FLT_DIVIDE_BY_ZERO حالت_FLOAT_DIVIDE_BY_ZERO
#تعریف_کړه EXCEPTION_FLT_INEXACT_پایله حالت_FLOAT_INEXACT_پایله
#تعریف_کړه EXCEPTION_FLT_INVALID_OPERATION حالت_FLOAT_INVALID_OPERATION
#تعریف_کړه EXCEPTION_FLT_ډکېدنه حالت_FLOAT_ډکېدنه
#تعریف_کړه EXCEPTION_FLT_ډېری_CHECK حالت_FLOAT_ډېری_CHECK
#تعریف_کړه EXCEPTION_FLT_UNDERFLOW حالت_FLOAT_UNDERFLOW
#تعریف_کړه EXCEPTION_INT_DIVIDE_BY_ZERO حالت_INTEGER_DIVIDE_BY_ZERO
#تعریف_کړه EXCEPTION_INT_ډکېدنه حالت_INTEGER_ډکېدنه
#تعریف_کړه EXCEPTION_PRIV_INSTRUCTION حالت_PRIVILEGED_INSTRUCTION
#تعریف_کړه EXCEPTION_دننه_پاڼه_ERROR حالت_دننه_پاڼه_ERROR
#تعریف_کړه EXCEPTION_ILLEGAL_INSTRUCTION حالت_ILLEGAL_INSTRUCTION
#تعریف_کړه EXCEPTION_NONCONTINUABLE_EXCEPTION حالت_NONCONTINUABLE_EXCEPTION
#تعریف_کړه EXCEPTION_ډېری_ډکېدنه حالت_ډېری_ډکېدنه
#تعریف_کړه EXCEPTION_INVALID_DISPOSITION حالت_INVALID_DISPOSITION
#تعریف_کړه EXCEPTION_GUARD_پاڼه حالت_GUARD_پاڼه_VIOLATION
#تعریف_کړه EXCEPTION_INVALID_HANDLE حالت_INVALID_HANDLE
#تعریف_کړه EXCEPTION_POSSIBLE_DEADLOCK حالت_POSSIBLE_DEADLOCK
#تعریف_کړه CONTROL_C_EXIT حالت_CONTROL_C_EXIT
#تعریف_کړه Move_حافظه Rtl_Move_حافظه
#تعریف_کړه Copy_حافظه Rtl_Copy_حافظه
#تعریف_کړه Fill_حافظه Rtl_Fill_حافظه
#تعریف_کړه Zero_حافظه Rtl_Zero_حافظه
#تعریف_کړه Secure_Zero_حافظه Rtl_Secure_Zero_حافظه

#تعریف_کړه FILE_FLAG_WRITE_THROUGH 0x80000000
#تعریف_کړه FILE_FLAG_OVERLAPPED 0x40000000
#تعریف_کړه FILE_FLAG_NO_BUFFERING 0x20000000
#تعریف_کړه FILE_FLAG_RANDOM_ACCESS 0x10000000
#تعریف_کړه FILE_FLAG_SEQUENTIAL_لټون 0x8000000
#تعریف_کړه FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#تعریف_کړه FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#تعریف_کړه FILE_FLAG_POSIX_SEMANTICS 0x1000000
#تعریف_کړه FILE_FLAG_OPEN_REPARSE_ټکی 0x200000
#تعریف_کړه FILE_FLAG_OPEN_NO_RECALL 0x100000
#تعریف_کړه FILE_FLAG_لومړی_PIPE_INSTANCE 0x80000

#تعریف_کړه CREATE_NEW 1
#تعریف_کړه CREATE_ALWAYS 2
#تعریف_کړه OPEN_EXISTING 3
#تعریف_کړه OPEN_ALWAYS 4
#تعریف_کړه TRUNCATE_EXISTING 5

#تعریف_کړه پرمختګ_CONTINUE 0
#تعریف_کړه پرمختګ_CANCEL 1
#تعریف_کړه پرمختګ_STOP 2
#تعریف_کړه پرمختګ_QUIET 3

#تعریف_کړه CALLBACK_CHUNK_پای_ته_رسېدلی 0x0
#تعریف_کړه CALLBACK_بهیر_SWITCH 0x1

#تعریف_کړه COPY_FILE_FAIL_IF_EXISTS 0x1
#تعریف_کړه COPY_FILE_RESTARTABLE 0x2
#تعریف_کړه COPY_FILE_OPEN_سرچینه_FOR_WRITE 0x4
#تعریف_کړه COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#تعریف_کړه REPLACEFILE_WRITE_THROUGH 0x1
#تعریف_کړه REPLACEFILE_IGNORE_یوځای_ERRORS 0x2

#تعریف_کړه PIPE_ACCESS_INBOUND 0x1
#تعریف_کړه PIPE_ACCESS_OUTBOUND 0x2
#تعریف_کړه PIPE_ACCESS_DUPLEX 0x3

#تعریف_کړه PIPE_CLIENT_پای_ټکی 0x0
#تعریف_کړه PIPE_SERVER_پای_ټکی 0x1

#تعریف_کړه PIPE_WAIT 0x0
#تعریف_کړه PIPE_NOWAIT 0x1
#تعریف_کړه PIPE_READMODE_BYTE 0x0
#تعریف_کړه PIPE_READMODE_پیغام 0x2
#تعریف_کړه PIPE_TYPE_BYTE 0x0
#تعریف_کړه PIPE_TYPE_پیغام 0x4

#تعریف_کړه PIPE_UNLIMITED_INSTANCES 255

#تعریف_کړه SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#تعریف_کړه SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#تعریف_کړه SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#تعریف_کړه SECURITY_DELEGATION (SecurityDelegation << 16)

#تعریف_کړه SECURITY_CONTEXT_TRACKING 0x40000
#تعریف_کړه SECURITY_EFFECTIVE_ONLY 0x80000

#تعریف_کړه SECURITY_SQOS_PRESENT 0x100000
#تعریف_کړه SECURITY_VALID_SQOS_FLAGS 0x1f0000

  تعريفنوع بنية _OVERLAPPED {
    ULONG_PTR دننی;
    ULONG_PTR دننی_لوړ;
    اتحاد {
      بنية {
	DWORD دننه_واټن_3;
	DWORD دننه_واټن_لوړ_2;
      };
      PVOID اشاره_ګر_2;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  تعريفنوع بنية SECURITY_ځانګړتیاوې {
    DWORD n_اوږدتیا;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_ځانګړتیاوې_2,*PSECURITY_ځانګړتیاوې,*LPSECURITY_ځانګړتیاوې;

  تعريفنوع بنية _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#که_نه_تعریف_شوی _FILETIME_
#تعریف_کړه _FILETIME_
  تعريفنوع بنية _FILETIME {
    DWORD dw_ټیټ_Date_وخت;
    DWORD dw_لوړ_Date_وخت;
  } FILETIME,*PFILETIME,*LPFILETIME;
#د_که_پای

  تعريفنوع بنية _SYSTEMTIME {
    کلمه_3 wYear;
    کلمه_3 wMonth;
    کلمه_3 w_Day_د_Week;
    کلمه_3 wDay;
    کلمه_3 wHour;
    کلمه_3 wMinute;
    کلمه_3 w_دوهم;
    کلمه_3 wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  تعريفنوع DWORD (WINAPI *PTHREAD_پیل_ROUTINE)(LPVOID lpThreadParameter);
  تعريفنوع PTHREAD_پیل_ROUTINE LPTHREAD_پیل_ROUTINE;
  تعريفنوع VOID (WINAPI *PFIBER_پیل_ROUTINE)(LPVOID lpFiberParameter);
  تعريفنوع PFIBER_پیل_ROUTINE LPFIBER_پیل_ROUTINE;

  تعريفنوع RTL_CRITICAL_SECTION CRITICAL_SECTION;
  تعريفنوع PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  تعريفنوع PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  تعريفنوع RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  تعريفنوع PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  تعريفنوع PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI Encode_اشاره_ګر(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_اشاره_ګر(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Encode_System_اشاره_ګر(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_System_اشاره_ګر(PVOID Ptr);

#که_تعریف_شوی I_X86_
  تعريفنوع PLDT_ثبت LPLDT_ثبت;
#وإلا
  تعريفنوع LPVOID LPLDT_ثبت;
#د_که_پای

#تعریف_کړه MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#تعریف_کړه MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#تعریف_کړه SP_SERIALCOMM ((DWORD)0x1)

#تعریف_کړه PST_UNSPECIFIED ((DWORD)0x0)
#تعریف_کړه PST_RS232 ((DWORD)0x1)
#تعریف_کړه PST_PARALLELPORT ((DWORD)0x2)
#تعریف_کړه PST_RS422 ((DWORD)0x3)
#تعریف_کړه PST_RS423 ((DWORD)0x4)
#تعریف_کړه PST_RS449 ((DWORD)0x5)
#تعریف_کړه PST_MODEM ((DWORD)0x6)
#تعریف_کړه PST_FAX ((DWORD)0x21)
#تعریف_کړه PST_SCANNER ((DWORD)0x22)
#تعریف_کړه PST_شبکه_BRIDGE ((DWORD)0x100)
#تعریف_کړه PST_LAT ((DWORD)0x101)
#تعریف_کړه PST_TCPIP_TELNET ((DWORD)0x102)
#تعریف_کړه PST_X25 ((DWORD)0x103)

#تعریف_کړه PCF_DTRDSR ((DWORD)0x1)
#تعریف_کړه PCF_RTSCTS ((DWORD)0x2)
#تعریف_کړه PCF_RLSD ((DWORD)0x4)
#تعریف_کړه PCF_PARITY_CHECK ((DWORD)0x8)
#تعریف_کړه PCF_XONXOFF ((DWORD)0x10)
#تعریف_کړه PCF_SETXCHAR ((DWORD)0x20)
#تعریف_کړه PCF_TOTALTIMEOUTS ((DWORD)0x40)
#تعریف_کړه PCF_INTTIMEOUTS ((DWORD)0x80)
#تعریف_کړه PCF_SPECIALCHARS ((DWORD)0x100)
#تعریف_کړه PCF_16BITMODE ((DWORD)0x200)

#تعریف_کړه SP_PARITY ((DWORD)0x1)
#تعریف_کړه SP_BAUD ((DWORD)0x2)
#تعریف_کړه SP_DATABITS ((DWORD)0x4)
#تعریف_کړه SP_STOPBITS ((DWORD)0x8)
#تعریف_کړه SP_HANDSHAKING ((DWORD)0x10)
#تعریف_کړه SP_PARITY_CHECK ((DWORD)0x20)
#تعریف_کړه SP_RLSD ((DWORD)0x40)

#تعریف_کړه BAUD_075 ((DWORD)0x1)
#تعریف_کړه BAUD_110 ((DWORD)0x2)
#تعریف_کړه BAUD_134_5 ((DWORD)0x4)
#تعریف_کړه BAUD_150 ((DWORD)0x8)
#تعریف_کړه BAUD_300 ((DWORD)0x10)
#تعریف_کړه BAUD_600 ((DWORD)0x20)
#تعریف_کړه BAUD_1200 ((DWORD)0x40)
#تعریف_کړه BAUD_1800 ((DWORD)0x80)
#تعریف_کړه BAUD_2400 ((DWORD)0x100)
#تعریف_کړه BAUD_4800 ((DWORD)0x200)
#تعریف_کړه BAUD_7200 ((DWORD)0x400)
#تعریف_کړه BAUD_9600 ((DWORD)0x800)
#تعریف_کړه BAUD_14400 ((DWORD)0x1000)
#تعریف_کړه BAUD_19200 ((DWORD)0x2000)
#تعریف_کړه BAUD_38400 ((DWORD)0x4000)
#تعریف_کړه BAUD_56K ((DWORD)0x8000)
#تعریف_کړه BAUD_128K ((DWORD)0x10000)
#تعریف_کړه BAUD_115200 ((DWORD)0x20000)
#تعریف_کړه BAUD_57600 ((DWORD)0x40000)
#تعریف_کړه BAUD_USER ((DWORD)0x10000000)

#تعریف_کړه DATABITS_5 ((کلمه_3)0x1)
#تعریف_کړه DATABITS_6 ((کلمه_3)0x2)
#تعریف_کړه DATABITS_7 ((کلمه_3)0x4)
#تعریف_کړه DATABITS_8 ((کلمه_3)0x8)
#تعریف_کړه DATABITS_16 ((کلمه_3)0x10)
#تعریف_کړه DATABITS_16X ((کلمه_3)0x20)

#تعریف_کړه STOPBITS_10 ((کلمه_3)0x1)
#تعریف_کړه STOPBITS_15 ((کلمه_3)0x2)
#تعریف_کړه STOPBITS_20 ((کلمه_3)0x4)
#تعریف_کړه PARITY_NONE ((کلمه_3)0x100)
#تعریف_کړه PARITY_ODD ((کلمه_3)0x200)
#تعریف_کړه PARITY_EVEN ((کلمه_3)0x400)
#تعریف_کړه PARITY_MARK ((کلمه_3)0x800)
#تعریف_کړه PARITY_SPACE ((کلمه_3)0x1000)

  تعريفنوع بنية _COMMPROP {
    کلمه_3 w_Packet_اوږدتیا;
    کلمه_3 w_Packet_نسخه;
    DWORD dw_Service_ماسک;
    DWORD dwReserved1;
    DWORD dw_Max_Tx_کتار;
    DWORD dw_Max_Rx_کتار;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    کلمه_3 w_Settable_معلومات;
    کلمه_3 wSettableStopParity;
    DWORD dw_Current_Tx_کتار;
    DWORD dw_Current_Rx_کتار;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#تعریف_کړه COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  تعريفنوع بنية _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD f_Xoff_لېږل_شوی : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cb_دننه_Que;
    DWORD cb_بهر_Que;
  } COMSTAT,*LPCOMSTAT;

#تعریف_کړه DTR_CONTROL_DISABLE 0x0
#تعریف_کړه DTR_CONTROL_ENABLE 0x1
#تعریف_کړه DTR_CONTROL_HANDSHAKE 0x2

#تعریف_کړه RTS_CONTROL_DISABLE 0x0
#تعریف_کړه RTS_CONTROL_ENABLE 0x1
#تعریف_کړه RTS_CONTROL_HANDSHAKE 0x2
#تعریف_کړه RTS_CONTROL_TOGGLE 0x3

  تعريفنوع بنية _DCB {
    DWORD DCBlength;
    DWORD Baud_شرح;
    DWORD f_دوګونی: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD f_Dsr_حساسیت:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD f_بهر_X: 1;
    DWORD f_دننه_X: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    کلمه_3 wReserved;
    کلمه_3 XonLim;
    کلمه_3 XoffLim;
    BYTE Byte_اندازه;
    BYTE Parity;
    BYTE Stop_بټونه;
    حرف XonChar;
    حرف XoffChar;
    حرف ErrorChar;
    حرف EofChar;
    حرف EvtChar;
    کلمه_3 wReserved1;
  } DCB,*LPDCB;

  تعريفنوع بنية _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD Read_ټول_Timeout_Multiplier;
    DWORD Read_ټول_Timeout_Constant;
    DWORD Write_ټول_Timeout_Multiplier;
    DWORD Write_ټول_Timeout_Constant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  تعريفنوع بنية _COMMCONFIG {
    DWORD dw_اندازه;
    کلمه_3 w_نسخه;
    کلمه_3 wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dw_Provider_دننه_واټن;
    DWORD dw_Provider_اندازه;
    WCHAR wc_Provider_معلومات[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  تعريفنوع بنية _SYSTEM_INFO {
    اتحاد {
      DWORD dwOemId;
      بنية {
	کلمه_3 wProcessorArchitecture;
	کلمه_3 wReserved;
      };
    };
    DWORD dw_پاڼه_اندازه;
    LPVOID lp_Minimum_Application_پته;
    LPVOID lp_اعظمي_Application_پته;
    DWORD_PTR dw_فعال_Processor_ماسک;
    DWORD dw_شمېره_د_Processors;
    DWORD dwProcessorType;
    DWORD dw_ویش_Granularity;
    کلمه_3 wProcessorLevel;
    کلمه_3 wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#تعریف_کړه FreeModule(hLibModule) FreeLibrary((hLibModule))
#تعریف_کړه MakeProcInstance(lpProc,hInstance) (lpProc)
#تعریف_کړه FreeProcInstance(lpProc) (lpProc)

#تعریف_کړه GMEM_FIXED 0x0
#تعریف_کړه GMEM_MOVEABLE 0x2
#تعریف_کړه GMEM_NOCOMPACT 0x10
#تعریف_کړه GMEM_NODISCARD 0x20
#تعریف_کړه GMEM_ZEROINIT 0x40
#تعریف_کړه GMEM_MODIFY 0x80
#تعریف_کړه GMEM_DISCARDABLE 0x100
#تعریف_کړه GMEM_NOT_BANKED 0x1000
#تعریف_کړه GMEM_SHARE 0x2000
#تعریف_کړه GMEM_DDESHARE 0x2000
#تعریف_کړه GMEM_NOTIFY 0x4000
#تعریف_کړه GMEM_ښکتنی GMEM_NOT_BANKED
#تعریف_کړه GMEM_VALID_FLAGS 0x7F72
#تعریف_کړه GMEM_INVALID_HANDLE 0x8000

#تعریف_کړه GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#تعریف_کړه GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#تعریف_کړه GlobalLRUNewest(h) ((HANDLE)(h))
#تعریف_کړه GlobalLRUOldest(h) ((HANDLE)(h))
#تعریف_کړه GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#تعریف_کړه GMEM_DISCARDED 0x4000
#تعریف_کړه GMEM_LOCKCOUNT 0xff

  تعريفنوع بنية _MEMORYSTATUS {
    DWORD dw_اوږدتیا;
    DWORD dw_حافظه_بارول;
    اندازه_T dw_ټول_Phys;
    اندازه_T dwAvailPhys;
    اندازه_T dw_ټول_پاڼه_File;
    اندازه_T dw_Avail_پاڼه_File;
    اندازه_T dw_ټول_Virtual;
    اندازه_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#تعریف_کړه LMEM_FIXED 0x0
#تعریف_کړه LMEM_MOVEABLE 0x2
#تعریف_کړه LMEM_NOCOMPACT 0x10
#تعریف_کړه LMEM_NODISCARD 0x20
#تعریف_کړه LMEM_ZEROINIT 0x40
#تعریف_کړه LMEM_MODIFY 0x80
#تعریف_کړه LMEM_DISCARDABLE 0xf00
#تعریف_کړه LMEM_VALID_FLAGS 0xf72
#تعریف_کړه LMEM_INVALID_HANDLE 0x8000

#تعریف_کړه LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#تعریف_کړه LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#تعریف_کړه NONZEROLHND (LMEM_MOVEABLE)
#تعریف_کړه NONZEROLPTR (LMEM_FIXED)

#تعریف_کړه LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#تعریف_کړه LMEM_DISCARDED 0x4000
#تعریف_کړه LMEM_LOCKCOUNT 0xff

#تعریف_کړه DEBUG_PROCESS 0x1
#تعریف_کړه DEBUG_ONLY_THIS_PROCESS 0x2
#تعریف_کړه CREATE_SUSPENDED 0x4
#تعریف_کړه DETACHED_PROCESS 0x8
#تعریف_کړه CREATE_NEW_CONSOLE 0x10
#تعریف_کړه نورمال_لومړیتوب_CLASS 0x20
#تعریف_کړه IDLE_لومړیتوب_CLASS 0x40
#تعریف_کړه لوړ_لومړیتوب_CLASS 0x80
#تعریف_کړه REALTIME_لومړیتوب_CLASS 0x100
#تعریف_کړه CREATE_NEW_PROCESS_ډله 0x200
#تعریف_کړه CREATE_UNICODE_ENVIRONMENT 0x400
#تعریف_کړه CREATE_SEPARATE_WOW_VDM 0x800
#تعریف_کړه CREATE_SHARED_WOW_VDM 0x1000
#تعریف_کړه CREATE_FORCEDOS 0x2000
#تعریف_کړه لاندې_نورمال_لومړیتوب_CLASS 0x4000
#تعریف_کړه ABOVE_نورمال_لومړیتوب_CLASS 0x8000
#تعریف_کړه ډېری_اندازه_PARAM_IS_A_RESERVATION 0x10000

#تعریف_کړه CREATE_BREAKAWAY_FROM_دنده 0x1000000
#تعریف_کړه CREATE_PRESERVE_کوډ_AUTHZ_LEVEL 0x2000000

#تعریف_کړه CREATE_DEFAULT_ERROR_ډېرپېښ 0x4000000
#تعریف_کړه CREATE_NO_کړکۍ 0x8000000

#تعریف_کړه PROFILE_USER 0x10000000
#تعریف_کړه PROFILE_KERNEL 0x20000000
#تعریف_کړه PROFILE_SERVER 0x40000000

#تعریف_کړه CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#تعریف_کړه THREAD_لومړیتوب_ټیټ_ترین THREAD_بنسټ_لومړیتوب_MIN
#تعریف_کړه THREAD_لومړیتوب_لاندې_نورمال (THREAD_لومړیتوب_ټیټ_ترین+1)
#تعریف_کړه THREAD_لومړیتوب_نورمال 0
#تعریف_کړه THREAD_لومړیتوب_HIGHEST THREAD_بنسټ_لومړیتوب_MAX
#تعریف_کړه THREAD_لومړیتوب_ABOVE_نورمال (THREAD_لومړیتوب_HIGHEST-1)
#تعریف_کړه THREAD_لومړیتوب_ERROR_RETURN (MAXLONG)

#تعریف_کړه THREAD_لومړیتوب_وخت_CRITICAL THREAD_بنسټ_لومړیتوب_LOWRT
#تعریف_کړه THREAD_لومړیتوب_IDLE THREAD_بنسټ_لومړیتوب_IDLE

#تعریف_کړه EXCEPTION_DEBUG_EVENT 1
#تعریف_کړه CREATE_THREAD_DEBUG_EVENT 2
#تعریف_کړه CREATE_PROCESS_DEBUG_EVENT 3
#تعریف_کړه EXIT_THREAD_DEBUG_EVENT 4
#تعریف_کړه EXIT_PROCESS_DEBUG_EVENT 5
#تعریف_کړه بارول_DLL_DEBUG_EVENT 6
#تعریف_کړه UNLOAD_DLL_DEBUG_EVENT 7
#تعریف_کړه OUTPUT_DEBUG_STRING_EVENT 8
#تعریف_کړه RIP_EVENT 9

  تعريفنوع بنية _EXCEPTION_DEBUG_INFO {
    EXCEPTION_ریکارډ_2 Exception_ریکارډ;
    DWORD dw_لومړی_Chance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  تعريفنوع بنية _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lp_Thread_Local_بنسټ;
    LPTHREAD_پیل_ROUTINE lp_پیل_پته;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  تعريفنوع بنية _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lp_بنسټ_د_Image;
    DWORD dw_Debug_Info_File_دننه_واټن;
    DWORD n_Debug_Info_اندازه;
    LPVOID lp_Thread_Local_بنسټ;
    LPTHREAD_پیل_ROUTINE lp_پیل_پته;
    LPVOID lpImageName;
    کلمه_3 fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  تعريفنوع بنية _EXIT_THREAD_DEBUG_INFO {
    DWORD dw_Exit_کوډ;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  تعريفنوع بنية _EXIT_PROCESS_DEBUG_INFO {
    DWORD dw_Exit_کوډ;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  تعريفنوع بنية بارول_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lp_بنسټ_د_Dll;
    DWORD dw_Debug_Info_File_دننه_واټن;
    DWORD n_Debug_Info_اندازه;
    LPVOID lpImageName;
    کلمه_3 fUnicode;
  } بارول_DLL_DEBUG_INFO_2,*LPLOAD_DLL_DEBUG_INFO;

  تعريفنوع بنية _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lp_بنسټ_د_Dll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  تعريفنوع بنية _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lp_Debug_String_معلومات;
    کلمه_3 fUnicode;
    کلمه_3 n_Debug_String_اوږدتیا;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  تعريفنوع بنية _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  تعريفنوع بنية _DEBUG_EVENT {
    DWORD dw_Debug_Event_کوډ;
    DWORD dwProcessId;
    DWORD dwThreadId;
    اتحاد {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      بارول_DLL_DEBUG_INFO_2 بارول_Dll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  تعريفنوع PCONTEXT LPCONTEXT;
  تعريفنوع PEXCEPTION_ریکارډ LPEXCEPTION_ریکارډ;
  تعريفنوع PEXCEPTION_اشارې LPEXCEPTION_اشارې;

#تعریف_کړه DRIVE_UNKNOWN 0
#تعریف_کړه DRIVE_NO_ریښه_DIR 1
#تعریف_کړه DRIVE_REMOVABLE 2
#تعریف_کړه DRIVE_FIXED 3
#تعریف_کړه DRIVE_REMOTE 4
#تعریف_کړه DRIVE_CDROM 5
#تعریف_کړه DRIVE_RAMDISK 6

#تعریف_کړه GetFreeSpace(w) (0x100000L)
#تعریف_کړه FILE_TYPE_UNKNOWN 0x0
#تعریف_کړه FILE_TYPE_DISK 0x1
#تعریف_کړه FILE_TYPE_CHAR 0x2
#تعریف_کړه FILE_TYPE_PIPE 0x3
#تعریف_کړه FILE_TYPE_REMOTE 0x8000

#تعریف_کړه STD_ننوت_HANDLE ((DWORD)-10)
#تعریف_کړه STD_OUTPUT_HANDLE ((DWORD)-11)
#تعریف_کړه STD_ERROR_HANDLE ((DWORD)-12)

#تعریف_کړه NOPARITY 0
#تعریف_کړه ODDPARITY 1
#تعریف_کړه EVENPARITY 2
#تعریف_کړه MARKPARITY 3
#تعریف_کړه SPACEPARITY 4

#تعریف_کړه ONESTOPBIT 0
#تعریف_کړه ONE5STOPBITS 1
#تعریف_کړه TWOSTOPBITS 2

#تعریف_کړه IGNORE 0
#تعریف_کړه INFINITE 0xffffffff

#تعریف_کړه CBR_110 110
#تعریف_کړه CBR_300 300
#تعریف_کړه CBR_600 600
#تعریف_کړه CBR_1200 1200
#تعریف_کړه CBR_2400 2400
#تعریف_کړه CBR_4800 4800
#تعریف_کړه CBR_9600 9600
#تعریف_کړه CBR_14400 14400
#تعریف_کړه CBR_19200 19200
#تعریف_کړه CBR_38400 38400
#تعریف_کړه CBR_56000 56000
#تعریف_کړه CBR_57600 57600
#تعریف_کړه CBR_115200 115200
#تعریف_کړه CBR_128000 128000
#تعریف_کړه CBR_256000 256000

#تعریف_کړه CE_RXOVER 0x1
#تعریف_کړه CE_OVERRUN 0x2
#تعریف_کړه CE_RXPARITY 0x4
#تعریف_کړه CE_چوکاټ 0x8
#تعریف_کړه CE_BREAK 0x10
#تعریف_کړه CE_TXFULL 0x100
#تعریف_کړه CE_PTO 0x200
#تعریف_کړه CE_IOE 0x400
#تعریف_کړه CE_DNS 0x800
#تعریف_کړه CE_OOP 0x1000
#تعریف_کړه CE_ډېرپېښ 0x8000

#تعریف_کړه IE_BADID (-1)
#تعریف_کړه IE_OPEN (-2)
#تعریف_کړه IE_NOPEN (-3)
#تعریف_کړه IE_حافظه (-4)
#تعریف_کړه IE_DEFAULT (-5)
#تعریف_کړه IE_HARDWARE (-10)
#تعریف_کړه IE_BYTESIZE (-11)
#تعریف_کړه IE_BAUDRATE (-12)

#تعریف_کړه EV_RXCHAR 0x1
#تعریف_کړه EV_RXFLAG 0x2
#تعریف_کړه EV_TXEMPTY 0x4
#تعریف_کړه EV_CTS 0x8
#تعریف_کړه EV_DSR 0x10
#تعریف_کړه EV_RLSD 0x20
#تعریف_کړه EV_BREAK 0x40
#تعریف_کړه EV_ERR 0x80
#تعریف_کړه EV_RING 0x100
#تعریف_کړه EV_PERR 0x200
#تعریف_کړه EV_RX80_ډک 0x400
#تعریف_کړه EV_EVENT1 0x800
#تعریف_کړه EV_EVENT2 0x1000

#تعریف_کړه SETXOFF 1
#تعریف_کړه SETXON 2
#تعریف_کړه SETRTS 3
#تعریف_کړه CLRRTS 4
#تعریف_کړه SETDTR 5
#تعریف_کړه CLRDTR 6
#تعریف_کړه RESETDEV 7
#تعریف_کړه SETBREAK 8
#تعریف_کړه CLRBREAK 9

#تعریف_کړه PURGE_TXABORT 0x1
#تعریف_کړه PURGE_RXABORT 0x2
#تعریف_کړه PURGE_TXCLEAR 0x4
#تعریف_کړه PURGE_RXCLEAR 0x8

#تعریف_کړه LPTx 0x80

#تعریف_کړه MS_CTS_ON ((DWORD)0x10)
#تعریف_کړه MS_DSR_ON ((DWORD)0x20)
#تعریف_کړه MS_RING_ON ((DWORD)0x40)
#تعریف_کړه MS_RLSD_ON ((DWORD)0x80)

#تعریف_کړه S_QUEUEEMPTY 0
#تعریف_کړه S_پوله 1
#تعریف_کړه S_ALLTHRESHOLD 2

#تعریف_کړه S_نورمال 0
#تعریف_کړه S_LEGATO 1
#تعریف_کړه S_STACCATO 2

#تعریف_کړه S_PERIOD512 0
#تعریف_کړه S_PERIOD1024 1
#تعریف_کړه S_PERIOD2048 2
#تعریف_کړه S_PERIODVOICE 3
#تعریف_کړه S_WHITE512 4
#تعریف_کړه S_WHITE1024 5
#تعریف_کړه S_WHITE2048 6
#تعریف_کړه S_WHITEVOICE 7

#تعریف_کړه S_SERDVNA (-1)
#تعریف_کړه S_SEROFM (-2)
#تعریف_کړه S_SERMACT (-3)
#تعریف_کړه S_SERQFUL (-4)
#تعریف_کړه S_SERBDNT (-5)
#تعریف_کړه S_SERDLN (-6)
#تعریف_کړه S_SERDCC (-7)
#تعریف_کړه S_SERDTP (-8)
#تعریف_کړه S_SERDVL (-9)
#تعریف_کړه S_SERDMD (-10)
#تعریف_کړه S_SERDSH (-11)
#تعریف_کړه S_SERDPT (-12)
#تعریف_کړه S_SERDFQ (-13)
#تعریف_کړه S_SERDDR (-14)
#تعریف_کړه S_SERDSR (-15)
#تعریف_کړه S_SERDST (-16)

#تعریف_کړه NMPWAIT_WAIT_FOREVER 0xffffffff
#تعریف_کړه NMPWAIT_NOWAIT 0x1
#تعریف_کړه NMPWAIT_USE_DEFAULT_WAIT 0x0

#تعریف_کړه FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_نومونه
#تعریف_کړه FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_پلټنه
#تعریف_کړه FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#تعریف_کړه FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#تعریف_کړه FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#تعریف_کړه FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#تعریف_کړه FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#تعریف_کړه FILE_MAP_COPY SECTION_QUERY
#تعریف_کړه FILE_MAP_WRITE SECTION_MAP_WRITE
#تعریف_کړه FILE_MAP_READ SECTION_MAP_READ
#تعریف_کړه FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#تعریف_کړه FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#تعریف_کړه د_READ 0x0
#تعریف_کړه د_WRITE 0x1
#تعریف_کړه د_READWRITE 0x2
#تعریف_کړه د_SHARE_COMPAT 0x0
#تعریف_کړه د_SHARE_EXCLUSIVE 0x10
#تعریف_کړه د_SHARE_DENY_WRITE 0x20
#تعریف_کړه د_SHARE_DENY_READ 0x30
#تعریف_کړه د_SHARE_DENY_NONE 0x40
#تعریف_کړه د_PARSE 0x100
#تعریف_کړه د_DELETE 0x200
#تعریف_کړه د_VERIFY 0x400
#تعریف_کړه د_CANCEL 0x800
#تعریف_کړه د_CREATE 0x1000
#تعریف_کړه د_PROMPT 0x2000
#تعریف_کړه د_EXIST 0x4000
#تعریف_کړه د_REOPEN 0x8000

#تعریف_کړه OFS_MAXPATHNAME 128
  تعريفنوع بنية _OFSTRUCT {
    BYTE c_بایټونه;
    BYTE fFixedDisk;
    کلمه_3 n_Err_کوډ;
    کلمه_3 Reserved1;
    کلمه_3 Reserved2;
    CHAR sz_لار_Name[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#که_نه_تعریف_شوی NOWINBASEINTERLOCK

#که_نه_تعریف_شوی _NTOS_

#إذا defined(__ia64__) && !defined(RC_INVOKED)

#تعریف_کړه InterlockedIncrement _InterlockedIncrement
#تعریف_کړه InterlockedIncrementAcquire _InterlockedIncrement_acq
#تعریف_کړه InterlockedIncrementRelease _InterlockedIncrement_rel
#تعریف_کړه InterlockedDecrement _InterlockedDecrement
#تعریف_کړه InterlockedDecrementAcquire _InterlockedDecrement_acq
#تعریف_کړه InterlockedDecrementRelease _InterlockedDecrement_rel
#تعریف_کړه InterlockedExchange _InterlockedExchange
#تعریف_کړه Interlocked_Exchange_جمع_کړه Interlocked_Exchange_جمع_کړه_2
#تعریف_کړه InterlockedCompareExchange _InterlockedCompareExchange
#تعریف_کړه InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#تعریف_کړه InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#تعریف_کړه Interlocked_Exchange_اشاره_ګر Interlocked_Exchange_اشاره_ګر_2
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر Interlocked_Compare_Exchange_اشاره_ګر_2
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Release Interlocked_Compare_Exchange_اشاره_ګر_rel
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Acquire Interlocked_Compare_Exchange_اشاره_ګر_acq

#تعریف_کړه InterlockedIncrement64 _InterlockedIncrement64
#تعریف_کړه InterlockedDecrement64 _InterlockedDecrement64
#تعریف_کړه InterlockedExchange64 _InterlockedExchange64
#تعریف_کړه InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#تعریف_کړه InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#تعریف_کړه InterlockedCompareExchange64 _InterlockedCompareExchange64
#تعریف_کړه InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#تعریف_کړه InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG متطاير *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG متطاير *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG متطاير *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG متطاير *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG متطاير *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG متطاير *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG متطاير *موخه_2,LONGLONG ارزښت_3);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG متطاير *موخه_2,LONGLONG ارزښت_3);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG متطاير *Addend,LONGLONG ارزښت_3);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG متطاير *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG متطاير *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG متطاير *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG متطاير *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG متطاير *lpAddend);
  LONG __cdecl InterlockedExchange(LONG متطاير *موخه_2,LONG ارزښت_3);
  LONG __cdecl Interlocked_Exchange_جمع_کړه(LONG متطاير *Addend,LONG ارزښت_3);
  LONG __cdecl InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl Interlocked_Exchange_اشاره_ګر(PVOID متطاير *موخه_2,PVOID ارزښت_3);
  PVOID __cdecl Interlocked_Compare_Exchange_اشاره_ګر(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_اشاره_ګر_Acquire(PVOID متطاير *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_اشاره_ګر_Release(PVOID متطاير *Destination,PVOID Exchange,PVOID Comperand);

#که_نه_تعریف_شوی InterlockedAnd
#تعریف_کړه InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG متطاير *موخه_2,LONG سېټ_2) {
    LONG i;
    LONG j;
    j = *موخه_2;
    افعل {
      i = j;
      j = InterlockedCompareExchange(موخه_2,i & سېټ_2,i);
    } طالما(i!=j);
    أرجع j;
  }
#د_که_پای

#که_نه_تعریف_شوی InterlockedOr
#تعریف_کړه InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG متطاير *موخه_2,LONG سېټ_2) {
    LONG i;
    LONG j;
    j = *موخه_2;
    افعل {
      i = j;
      j = InterlockedCompareExchange(موخه_2,i | سېټ_2,i);
    } طالما(i!=j);
    أرجع j;
  }
#د_که_پای

#که_نه_تعریف_شوی InterlockedXor
#تعریف_کړه InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG متطاير *موخه_2,LONG سېټ_2) {
    LONG i;
    LONG j;
    j = *موخه_2;
    افعل {
      i = j;
      j = InterlockedCompareExchange(موخه_2,i ^ سېټ_2,i);
    } طالما(i!=j);
    أرجع j;
  }
#د_که_پای

#که_نه_تعریف_شوی InterlockedAnd64
#تعریف_کړه InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG متطاير *Destination,LONGLONG ارزښت_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old & ارزښت_3,Old)!=Old);
    أرجع Old;
  }
#د_که_پای

#که_نه_تعریف_شوی InterlockedOr64
#تعریف_کړه InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG متطاير *Destination,LONGLONG ارزښت_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old | ارزښت_3,Old)!=Old);
    أرجع Old;
  }
#د_که_پای

#که_نه_تعریف_شوی InterlockedXor64
#تعریف_کړه InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG متطاير *Destination,LONGLONG ارزښت_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old ^ ارزښت_3,Old)!=Old);
    أرجع Old;
  }
#د_که_پای

#که_نه_تعریف_شوی Interlocked_بټ_Test_And_سېټ
#تعریف_کړه Interlocked_بټ_Test_And_سېټ Interlocked_بټ_Test_And_سېټ_Inline

  __CRT_INLINE BOOLEAN Interlocked_بټ_Test_And_سېټ_Inline(LONG *بنسټ_2,LONG بټ_2) {
    LONG t_بټ;
    t_بټ = 1<<(بټ_2 & (حجم (*بنسټ_2)*8-1));
    أرجع (BOOLEAN)((InterlockedOr(&بنسټ_2[بټ_2/(حجم(*بنسټ_2)*8)],t_بټ)&t_بټ)!=0);
  }
#د_که_پای

#که_نه_تعریف_شوی Interlocked_بټ_Test_And_Reset
#تعریف_کړه Interlocked_بټ_Test_And_Reset Interlocked_بټ_Test_And_Reset_Inline

  __CRT_INLINE BOOLEAN Interlocked_بټ_Test_And_Reset_Inline(LONG *بنسټ_2,LONG بټ_2) {
    LONG t_بټ;
    t_بټ = 1<<(بټ_2 & (حجم (*بنسټ_2)*8-1));
    أرجع (BOOLEAN)((InterlockedAnd(&بنسټ_2[بټ_2/(حجم(*بنسټ_2)*8)],~t_بټ)&t_بټ)!=0);
  }
#د_که_پای

#که_نه_تعریف_شوی Interlocked_بټ_Test_And_Complement
#تعریف_کړه Interlocked_بټ_Test_And_Complement Interlocked_بټ_Test_And_Complement_Inline

  __CRT_INLINE BOOLEAN Interlocked_بټ_Test_And_Complement_Inline(LONG *بنسټ_2,LONG بټ_2) {
    LONG t_بټ;
    t_بټ = 1<<(بټ_2 & (حجم (*بنسټ_2)*8-1));
    أرجع (BOOLEAN)((InterlockedXor(&بنسټ_2[بټ_2/(حجم(*بنسټ_2)*8)],t_بټ)&t_بټ)!=0);
  }
#د_که_پای
#وإلاإذا defined(__x86_64) && !defined(RC_INVOKED)

#تعریف_کړه InterlockedIncrement _InterlockedIncrement
#تعریف_کړه InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کړه InterlockedIncrementRelease InterlockedIncrement
#تعریف_کړه InterlockedDecrement _InterlockedDecrement
#تعریف_کړه InterlockedDecrementAcquire InterlockedDecrement
#تعریف_کړه InterlockedDecrementRelease InterlockedDecrement
#تعریف_کړه InterlockedExchange _InterlockedExchange
#تعریف_کړه Interlocked_Exchange_جمع_کړه Interlocked_Exchange_جمع_کړه_2
#تعریف_کړه InterlockedCompareExchange _InterlockedCompareExchange
#تعریف_کړه InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کړه InterlockedCompareExchangeRelease InterlockedCompareExchange
#تعریف_کړه Interlocked_Exchange_اشاره_ګر Interlocked_Exchange_اشاره_ګر_2
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر Interlocked_Compare_Exchange_اشاره_ګر_2
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Acquire Interlocked_Compare_Exchange_اشاره_ګر_2
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Release Interlocked_Compare_Exchange_اشاره_ګر_2
#تعریف_کړه InterlockedAnd64 _InterlockedAnd64
#تعریف_کړه InterlockedOr64 _InterlockedOr64
#تعریف_کړه InterlockedXor64 _InterlockedXor64
#تعریف_کړه InterlockedIncrement64 _InterlockedIncrement64
#تعریف_کړه InterlockedDecrement64 _InterlockedDecrement64
#تعریف_کړه InterlockedExchange64 _InterlockedExchange64
#تعریف_کړه InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#تعریف_کړه InterlockedCompareExchange64 _InterlockedCompareExchange64
#تعریف_کړه InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#تعریف_کړه InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG متطاير *Addend);
  LONG InterlockedDecrement(LONG متطاير *Addend);
  LONG InterlockedExchange(LONG متطاير *موخه_2,LONG ارزښت_3);
  LONG Interlocked_Exchange_جمع_کړه(LONG متطاير *Addend,LONG ارزښت_3);
  LONG InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  PVOID Interlocked_Compare_Exchange_اشاره_ګر(PVOID متطاير *Destination,PVOID Exchange,PVOID Comperand);
  PVOID Interlocked_Exchange_اشاره_ګر(PVOID متطاير *موخه_2,PVOID ارزښت_3);
  LONG64 InterlockedAnd64(LONG64 متطاير *Destination,LONG64 ارزښت_3);
  LONG64 InterlockedOr64(LONG64 متطاير *Destination,LONG64 ارزښت_3);
  LONG64 InterlockedXor64(LONG64 متطاير *Destination,LONG64 ارزښت_3);
  LONG64 InterlockedIncrement64(LONG64 متطاير *Addend);
  LONG64 InterlockedDecrement64(LONG64 متطاير *Addend);
  LONG64 InterlockedExchange64(LONG64 متطاير *موخه_2,LONG64 ارزښت_3);
  LONG64 InterlockedExchangeAdd64(LONG64 متطاير *Addend,LONG64 ارزښت_3);
  LONG64 InterlockedCompareExchange64(LONG64 متطاير *Destination,LONG64 ExChange,LONG64 Comperand);
#وإلا
  LONG WINAPI InterlockedIncrement(LONG متطاير *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG متطاير *lpAddend);
  LONG WINAPI InterlockedExchange(LONG متطاير *موخه_2,LONG ارزښت_3);

#که_نه_تعریف_شوی Interlocked_Exchange_اشاره_ګر
#تعریف_کړه Interlocked_Exchange_اشاره_ګر(موخه_2,ارزښت_3) (PVOID)InterlockedExchange((PLONG)(موخه_2),(LONG)(ارزښت_3))
#د_که_پای

  LONG WINAPI Interlocked_Exchange_جمع_کړه(LONG متطاير *Addend,LONG ارزښت_3);
  LONG WINAPI InterlockedCompareExchange(LONG متطاير *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG متطاير *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG متطاير *Destination,LONGLONG ارزښت_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old & ارزښت_3,Old)!=Old);
    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG متطاير *Destination,LONGLONG ارزښت_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old | ارزښت_3,Old)!=Old);
    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG متطاير *Destination,LONGLONG ارزښت_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old ^ ارزښت_3,Old)!=Old);

    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedIncrement64(LONGLONG متطاير *Addend) {
    LONGLONG Old;
    افعل {
      Old = *Addend;
    } طالما(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    أرجع Old + 1;
  }

  __CRT_INLINE LONGLONG InterlockedDecrement64(LONGLONG متطاير *Addend) {
    LONGLONG Old;
    افعل {
      Old = *Addend;
    } طالما(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    أرجع Old - 1;
  }

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG متطاير *موخه_2,LONGLONG ارزښت_3) {
    LONGLONG Old;
    افعل {
      Old = *موخه_2;
    } طالما(InterlockedCompareExchange64(موخه_2,ارزښت_3,Old)!=Old);
    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG متطاير *Addend,LONGLONG ارزښت_3) {
    LONGLONG Old;
    افعل {
      Old = *Addend;
    } طالما(InterlockedCompareExchange64(Addend,Old + ارزښت_3,Old)!=Old);
    أرجع Old;
  }

#که_نه_تعریف_شوی Interlocked_Compare_Exchange_اشاره_ګر
#که_تعریف_شوی __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand) {
    أرجع((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG متطاير *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر __InlineInterlockedCompareExchangePointer
#وإلا
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG متطاير *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#د_که_پای
#د_که_پای

#تعریف_کړه InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کړه InterlockedIncrementRelease InterlockedIncrement
#تعریف_کړه InterlockedDecrementAcquire InterlockedDecrement
#تعریف_کړه InterlockedDecrementRelease InterlockedDecrement
#تعریف_کړه InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کړه InterlockedIncrementRelease InterlockedIncrement
#تعریف_کړه InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کړه InterlockedCompareExchangeRelease InterlockedCompareExchange
#تعریف_کړه InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#تعریف_کړه InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#که_نه_تعریف_شوی Interlocked_Compare_Exchange_اشاره_ګر_Acquire
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Acquire Interlocked_Compare_Exchange_اشاره_ګر
#د_که_پای
#که_نه_تعریف_شوی Interlocked_Compare_Exchange_اشاره_ګر_Release
#تعریف_کړه Interlocked_Compare_Exchange_اشاره_ګر_Release Interlocked_Compare_Exchange_اشاره_ګر
#د_که_پای
#د_که_پای

#إذا defined(SLIST_سرلیک) && !defined(_NTOSP_)
  WINBASEAPI VOID WINAPI Initialize_SList_سر(PSLIST_سرلیک List_سر);
  WINBASEAPI PSLIST_ثبت WINAPI Interlocked_راوباسه_ثبت_SList(PSLIST_سرلیک List_سر);
  WINBASEAPI PSLIST_ثبت WINAPI Interlocked_ټېل_ثبت_SList(PSLIST_سرلیک List_سر,PSLIST_ثبت List_ثبت);
  WINBASEAPI PSLIST_ثبت WINAPI InterlockedFlushSList(PSLIST_سرلیک List_سر);
  WINBASEAPI USHORT WINAPI Query_ژوروالی_SList(PSLIST_سرلیک List_سر);
#د_که_پای
#د_که_پای
#د_که_پای

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL h_Res_معلومات);
  WINBASEAPI LPVOID WINAPI قلف_Resource(HGLOBAL h_Res_معلومات);

#تعریف_کړه UnlockResource(h_Res_معلومات) ((h_Res_معلومات),0)
#تعریف_کړه MAXINTATOM 0xC000
#تعریف_کړه MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((کلمه_3)(i)))
#تعریف_کړه INVALID_ATOM ((ATOM)0)

  صحيح WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lp_Cmd_کرښه,صحيح nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dw_Exit_کوډ);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI Get_Proc_پته(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI Get_نسخه(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,اندازه_T dw_بایټونه);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,اندازه_T dw_بایټونه,UINT uFlags);
  WINBASEAPI اندازه_T WINAPI Global_اندازه(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI Global_قلف(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI اندازه_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI Global_حافظه_حالت(LPMEMORYSTATUS lp_بفر);

  تعريفنوع بنية _MEMORYSTATUSEX {
    DWORD dw_اوږدتیا;
    DWORD dw_حافظه_بارول;
    DWORDLONG ull_ټول_Phys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ull_ټول_پاڼه_File;
    DWORDLONG ull_Avail_پاڼه_File;
    DWORDLONG ull_ټول_Virtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI Global_حافظه_حالت_Ex(LPMEMORYSTATUSEX lp_بفر);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,اندازه_T u_بایټونه);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,اندازه_T u_بایټونه,UINT uFlags);
  WINBASEAPI LPVOID WINAPI Local_قلف(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI اندازه_T WINAPI Local_اندازه(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI اندازه_T WINAPI LocalShrink(HLOCAL hMem,UINT cb_New_اندازه);
  WINBASEAPI اندازه_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lp_بنسټ_پته,اندازه_T dw_اندازه);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lp_پته,اندازه_T dw_اندازه,DWORD fl_ویش_Type,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lp_پته,اندازه_T dw_اندازه,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lp_پته,اندازه_T dw_اندازه,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI اندازه_T WINAPI VirtualQuery(LPCVOID lp_پته,PMEMORY_BASIC_INFORMATION lp_بفر,اندازه_T dw_اوږدتیا);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lp_پته,اندازه_T dw_اندازه,DWORD fl_ویش_Type,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lp_بنسټ_پته,اندازه_T dw_Region_اندازه,PVOID *lp_پتې,ULONG_PTR *lpdw_شمېر,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lp_بنسټ_پته,اندازه_T dw_Region_اندازه);
  WINBASEAPI اندازه_T WINAPI Get_Large_پاڼه_Minimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD Firmware_جدول_Provider_Signature,PVOID p_Firmware_جدول_Enum_بفر,DWORD بفر_اندازه);
  WINBASEAPI UINT WINAPI Get_System_Firmware_جدول(DWORD Firmware_جدول_Provider_Signature,DWORD Firmware_جدول_ID,PVOID p_Firmware_جدول_بفر,DWORD بفر_اندازه);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lp_پته,اندازه_T dw_اندازه,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lp_پته,اندازه_T dw_اندازه,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI اندازه_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lp_پته,PMEMORY_BASIC_INFORMATION lp_بفر,اندازه_T dw_اوږدتیا);
  WINBASEAPI HANDLE WINAPI ډېرۍ_Create(DWORD flOptions,اندازه_T dw_Initial_اندازه,اندازه_T dw_اعظمي_اندازه);
  WINBASEAPI WINBOOL WINAPI ډېرۍ_Destroy(HANDLE h_ډېرۍ);
  WINBASEAPI LPVOID WINAPI ډېرۍ_Alloc(HANDLE h_ډېرۍ,DWORD dwFlags,اندازه_T dw_بایټونه);
  WINBASEAPI LPVOID WINAPI ډېرۍ_Re_Alloc(HANDLE h_ډېرۍ,DWORD dwFlags,LPVOID lpMem,اندازه_T dw_بایټونه);
  WINBASEAPI WINBOOL WINAPI ډېرۍ_Free(HANDLE h_ډېرۍ,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI اندازه_T WINAPI ډېرۍ_اندازه(HANDLE h_ډېرۍ,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI ډېرۍ_Validate(HANDLE h_ډېرۍ,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI اندازه_T WINAPI ډېرۍ_Compact(HANDLE h_ډېرۍ,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI Get_Process_ډېرۍ(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD شمېره_د_Heaps,PHANDLE ProcessHeaps);

  تعريفنوع بنية PROCESS_ډېرۍ_ثبت {
    PVOID lp_معلومات;
    DWORD cb_معلومات;
    BYTE cbOverhead;
    BYTE i_Region_شاخص;
    کلمه_3 wFlags;
    اتحاد {
      بنية {
	HANDLE hMem;
	DWORD dwReserved[3];
      } بلاک_2;
      بنية {
	DWORD dw_Committed_اندازه;
	DWORD dw_Un_Committed_اندازه;
	LPVOID lp_لومړی_بلاک;
	LPVOID lp_وروستی_بلاک;
      } Region;
    };
  } PROCESS_ډېرۍ_ثبت_2,*LPPROCESS_ډېرۍ_ثبت,*PPROCESS_ډېرۍ_ثبت;

#تعریف_کړه PROCESS_ډېرۍ_REGION 0x1
#تعریف_کړه PROCESS_ډېرۍ_UNCOMMITTED_RANGE 0x2
#تعریف_کړه PROCESS_ډېرۍ_ثبت_BUSY 0x4
#تعریف_کړه PROCESS_ډېرۍ_ثبت_MOVEABLE 0x10
#تعریف_کړه PROCESS_ډېرۍ_ثبت_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI ډېرۍ_قلف(HANDLE h_ډېرۍ);
  WINBASEAPI WINBOOL WINAPI ډېرۍ_Unlock(HANDLE h_ډېرۍ);
  WINBASEAPI WINBOOL WINAPI ډېرۍ_Walk(HANDLE h_ډېرۍ,LPPROCESS_ډېرۍ_ثبت lp_ثبت);
  WINBASEAPI WINBOOL WINAPI ډېرۍ_سېټ_Information(HANDLE ډېرۍ_Handle,ډېرۍ_INFORMATION_CLASS ډېرۍ_Information_Class,PVOID ډېرۍ_Information,اندازه_T ډېرۍ_Information_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI ډېرۍ_Query_Information(HANDLE ډېرۍ_Handle,ډېرۍ_INFORMATION_CLASS ډېرۍ_Information_Class,PVOID ډېرۍ_Information,اندازه_T ډېرۍ_Information_اوږدتیا,PSIZE_T Return_اوږدتیا);

#تعریف_کړه SCS_32_بټ_دوګونی 0
#تعریف_کړه SCS_DOS_دوګونی 1
#تعریف_کړه SCS_WOW_دوګونی 2
#تعریف_کړه SCS_PIF_دوګونی 3
#تعریف_کړه SCS_POSIX_دوګونی 4
#تعریف_کړه SCS_OS216_دوګونی 5
#تعریف_کړه SCS_64_بټ_دوګونی 6

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_دوګونی_Type Get_دوګونی_Type_W
#تعریف_کړه Get_Short_لار_Name Get_Short_لار_Name_W
#تعریف_کړه Get_Long_لار_Name Get_Long_لار_Name_W
#تعریف_کړه Get_Environment_مزي_ګانې Get_Environment_مزي_ګانې_W
#تعریف_کړه سېټ_Environment_مزي_ګانې سېټ_Environment_مزي_ګانې_W
#تعریف_کړه Free_Environment_مزي_ګانې Free_Environment_مزي_ګانې_W
#وإلا
#تعریف_کړه Get_دوګونی_Type Get_دوګونی_Type_A
#تعریف_کړه Get_Short_لار_Name Get_Short_لار_Name_A
#تعریف_کړه Get_Long_لار_Name Get_Long_لار_Name_A
#تعریف_کړه Get_Environment_مزي_ګانې_A Get_Environment_مزي_ګانې
#تعریف_کړه سېټ_Environment_مزي_ګانې سېټ_Environment_مزي_ګانې_A
#تعریف_کړه Free_Environment_مزي_ګانې Free_Environment_مزي_ګانې_A
#د_که_پای

#که_تعریف_شوی _WIN64
#تعریف_کړه SCS_THIS_PLATFORM_دوګونی SCS_64_بټ_دوګونی
#وإلا
#تعریف_کړه SCS_THIS_PLATFORM_دوګونی SCS_32_بټ_دوګونی
#د_که_پای

  WINBASEAPI WINBOOL WINAPI Get_دوګونی_Type_A(LPCSTR lpApplicationName,LPDWORD lp_دوګونی_Type);
  WINBASEAPI WINBOOL WINAPI Get_دوګونی_Type_W(LPCWSTR lpApplicationName,LPDWORD lp_دوګونی_Type);
  WINBASEAPI DWORD WINAPI Get_Short_لار_Name_A(LPCSTR lpsz_Long_لار,LPSTR lpsz_Short_لار,DWORD cch_بفر);
  WINBASEAPI DWORD WINAPI Get_Short_لار_Name_W(LPCWSTR lpsz_Long_لار,LPWSTR lpsz_Short_لار,DWORD cch_بفر);
  WINBASEAPI DWORD WINAPI Get_Long_لار_Name_A(LPCSTR lpsz_Short_لار,LPSTR lpsz_Long_لار,DWORD cch_بفر);
  WINBASEAPI DWORD WINAPI Get_Long_لار_Name_W(LPCWSTR lpsz_Short_لار,LPWSTR lpsz_Long_لار,DWORD cch_بفر);
  WINBASEAPI WINBOOL WINAPI Get_Process_Affinity_ماسک(HANDLE hProcess,PDWORD_PTR lp_Process_Affinity_ماسک,PDWORD_PTR lp_System_Affinity_ماسک);
  WINBASEAPI WINBOOL WINAPI سېټ_Process_Affinity_ماسک(HANDLE hProcess,DWORD_PTR dw_Process_Affinity_ماسک);
  WINBASEAPI WINBOOL WINAPI Get_Process_Handle_شمېر(HANDLE hProcess,PDWORD pdw_Handle_شمېر);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lp_Creation_وخت,LPFILETIME lp_Exit_وخت,LPFILETIME lp_Kernel_وخت,LPFILETIME lp_User_وخت);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_سېټ_اندازه(HANDLE hProcess,PSIZE_T lp_Minimum_Working_سېټ_اندازه,PSIZE_T lp_اعظمي_Working_سېټ_اندازه);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_سېټ_اندازه_Ex(HANDLE hProcess,PSIZE_T lp_Minimum_Working_سېټ_اندازه,PSIZE_T lp_اعظمي_Working_سېټ_اندازه,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI سېټ_Process_Working_سېټ_اندازه(HANDLE hProcess,اندازه_T dw_Minimum_Working_سېټ_اندازه,اندازه_T dw_اعظمي_Working_سېټ_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Process_Working_سېټ_اندازه_Ex(HANDLE hProcess,اندازه_T dw_Minimum_Working_سېټ_اندازه,اندازه_T dw_اعظمي_Working_سېټ_اندازه,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT u_Exit_کوډ);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT u_Exit_کوډ);
  WINBASEAPI WINBOOL WINAPI Get_Exit_کوډ_Process(HANDLE hProcess,LPDWORD lp_Exit_کوډ);
  WINBASEAPI VOID WINAPI FatalExit(صحيح Exit_کوډ);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI Get_Environment_مزي_ګانې_W(VOID);
  WINBASEAPI WINBOOL WINAPI سېټ_Environment_مزي_ګانې_A(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI سېټ_Environment_مزي_ګانې_W(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI Free_Environment_مزي_ګانې_A(LPCH);
  WINBASEAPI WINBOOL WINAPI Free_Environment_مزي_ګانې_W(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dw_Exception_کوډ,DWORD dwExceptionFlags,DWORD n_شمېره_د_Arguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(بنية EXCEPTION_اشارې_2 *ExceptionInfo);

  تعريفنوع LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(بنية EXCEPTION_اشارې_2 *ExceptionInfo);
  تعريفنوع PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI سېټ_Unhandled_Exception_Filter(LPTOP_LEVEL_EXCEPTION_FILTER lp_سر_Level_Exception_Filter);

#تعریف_کړه FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(اندازه_T dw_ډېری_اندازه,LPFIBER_پیل_ROUTINE lp_پیل_پته,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(اندازه_T dw_ډېری_Commit_اندازه,اندازه_T dw_ډېری_Reserve_اندازه,DWORD dwFlags,LPFIBER_پیل_ROUTINE lp_پیل_پته,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI Convert_Thread_منزل_Fiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI Convert_Thread_منزل_Fiber_Ex(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Convert_Fiber_منزل_Thread(VOID);
  WINBASEAPI VOID WINAPI Switch_منزل_Fiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI Switch_منزل_Thread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_ځانګړتیاوې lp_Thread_ځانګړتیاوې,اندازه_T dw_ډېری_اندازه,LPTHREAD_پیل_ROUTINE lp_پیل_پته,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_ځانګړتیاوې lp_Thread_ځانګړتیاوې,اندازه_T dw_ډېری_اندازه,LPTHREAD_پیل_ROUTINE lp_پیل_پته,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI سېټ_Thread_ډېری_Guarantee (PULONG ډېری_اندازه_دننه_بایټونه);
  WINBASEAPI DWORD WINAPI Get_Process_Id_د_Thread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI Get_Current_Processor_شمېره(VOID);
  WINBASEAPI DWORD_PTR WINAPI سېټ_Thread_Affinity_ماسک(HANDLE hThread,DWORD_PTR dw_Thread_Affinity_ماسک);
  WINBASEAPI DWORD WINAPI سېټ_Thread_Ideal_Processor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI سېټ_Process_لومړیتوب_Boost(HANDLE hProcess,WINBOOL b_Disable_لومړیتوب_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Process_لومړیتوب_Boost(HANDLE hProcess,PBOOL p_Disable_لومړیتوب_Boost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_وخت latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI سېټ_Thread_لومړیتوب(HANDLE hThread,صحيح n_لومړیتوب);
  WINBASEAPI WINBOOL WINAPI سېټ_Thread_لومړیتوب_Boost(HANDLE hThread,WINBOOL b_Disable_لومړیتوب_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Thread_لومړیتوب_Boost(HANDLE hThread,PBOOL p_Disable_لومړیتوب_Boost);
  WINBASEAPI صحيح WINAPI Get_Thread_لومړیتوب(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lp_Creation_وخت,LPFILETIME lp_Exit_وخت,LPFILETIME lp_Kernel_وخت,LPFILETIME lp_User_وخت);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dw_Exit_کوډ);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dw_Exit_کوډ);
  WINBASEAPI WINBOOL WINAPI Get_Exit_کوډ_Thread(HANDLE hThread,LPDWORD lp_Exit_کوډ);
  WINBASEAPI WINBOOL WINAPI Get_Thread_Selector_ثبت(HANDLE hThread,DWORD dwSelector,LPLDT_ثبت lp_Selector_ثبت);
  WINBASEAPI EXECUTION_STATE WINAPI سېټ_Thread_Execution_State(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI Get_وروستی_Error(VOID);
  WINBASEAPI VOID WINAPI سېټ_وروستی_Error(DWORD dw_Err_کوډ);

#که_نه_تعریف_شوی RC_INVOKED
#که_تعریف_شوی WINBASE_DECLARE_RESTORE_وروستی_ERROR
  WINBASEAPI VOID WINAPI Restore_وروستی_Error(DWORD dw_Err_کوډ);

  تعريفنوع VOID (WINAPI *PRESTORE_وروستی_ERROR)(DWORD);

#تعریف_کړه RESTORE_وروستی_ERROR_NAME_A "RestoreLastError"
#تعریف_کړه RESTORE_وروستی_ERROR_NAME_W L"RestoreLastError"
#تعریف_کړه RESTORE_وروستی_ERROR_NAME متن_3("RestoreLastError")
#د_که_پای
#د_که_پای

#تعریف_کړه HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->دننی)!=حالت_PENDING)

  WINBASEAPI WINBOOL WINAPI Get_Overlapped_پایله(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lp_شمېره_د_بایټونه_Transferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI Create_Io_Completion_پورټ(HANDLE FileHandle,HANDLE Existing_Completion_پورټ,ULONG_PTR Completion_کلی,DWORD شمېره_د_Concurrent_تارونه);
  WINBASEAPI WINBOOL WINAPI Get_Queued_Completion_حالت(HANDLE Completion_پورټ,LPDWORD lp_شمېره_د_بایټونه_Transferred,PULONG_PTR lp_Completion_کلی,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI Post_Queued_Completion_حالت(HANDLE Completion_پورټ,DWORD dw_شمېره_د_بایټونه_Transferred,ULONG_PTR dw_Completion_کلی,LPOVERLAPPED lpOverlapped);

#تعریف_کړه SEM_FAILCRITICALERRORS 0x1
#تعریف_کړه SEM_NOGPFAULTERRORBOX 0x2
#تعریف_کړه SEM_NOALIGNMENTFAULTEXCEPT 0x4
#تعریف_کړه SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI سېټ_Error_ډېرپېښ(UINT u_ډېرپېښ);
  WINBASEAPI WINBOOL WINAPI Read_Process_حافظه(HANDLE hProcess,LPCVOID lp_بنسټ_پته,LPVOID lp_بفر,اندازه_T n_اندازه,اندازه_T *lp_شمېره_د_بایټونه_Read);
  WINBASEAPI WINBOOL WINAPI Write_Process_حافظه(HANDLE hProcess,LPVOID lp_بنسټ_پته,LPCVOID lp_بفر,اندازه_T n_اندازه,اندازه_T *lp_شمېره_د_بایټونه_Written);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI سېټ_Thread_Context(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  تعريفنوع VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI کتار_User_APC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dw_معلومات);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dw_Continue_حالت);
  WINBASEAPI WINBOOL WINAPI Debug_فعال_Process(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_فعال_Process_Stop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_سېټ_Process_Kill_On_Exit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI Initialize_Critical_Section_And_Spin_شمېر(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_شمېر);
  WINBASEAPI DWORD WINAPI سېټ_Critical_Section_Spin_شمېر(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_شمېر);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI سېټ_Event(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG l_Release_شمېر,LPLONG lp_پخوانی_شمېر);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI Wait_For_مضرب_Objects(DWORD n_شمېر,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI بارول_Resource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI Init_Atom_جدول(DWORD n_اندازه);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI سېټ_Handle_شمېر(UINT u_شمېره);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI قلف_File(HANDLE hFile,DWORD dw_File_دننه_واټن_ټیټ,DWORD dw_File_دننه_واټن_لوړ,DWORD n_شمېره_د_بایټونه_منزل_قلف_ټیټ,DWORD n_شمېره_د_بایټونه_منزل_قلف_لوړ);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dw_File_دننه_واټن_ټیټ,DWORD dw_File_دننه_واټن_لوړ,DWORD n_شمېره_د_بایټونه_منزل_Unlock_ټیټ,DWORD n_شمېره_د_بایټونه_منزل_Unlock_لوړ);
  WINBASEAPI WINBOOL WINAPI قلف_File_Ex(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD n_شمېره_د_بایټونه_منزل_قلف_ټیټ,DWORD n_شمېره_د_بایټونه_منزل_قلف_لوړ,LPOVERLAPPED lpOverlapped);

#تعریف_کړه LOCKFILE_FAIL_IMMEDIATELY 0x1
#تعریف_کړه LOCKFILE_EXCLUSIVE_قلف 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD n_شمېره_د_بایټونه_منزل_Unlock_ټیټ,DWORD n_شمېره_د_بایټونه_منزل_Unlock_لوړ,LPOVERLAPPED lpOverlapped);

  تعريفنوع بنية _BY_HANDLE_FILE_INFORMATION {
    DWORD dw_File_ځانګړتیاوې;
    FILETIME ft_Creation_وخت;
    FILETIME ft_وروستی_Access_وخت;
    FILETIME ft_وروستی_Write_وخت;
    DWORD dw_Volume_Serial_شمېره;
    DWORD n_File_اندازه_لوړ;
    DWORD n_File_اندازه_ټیټ;
    DWORD n_شمېره_د_Links;
    DWORD n_File_شاخص_لوړ;
    DWORD n_File_شاخص_ټیټ;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#که_تعریف_شوی UNICODE
#تعریف_کړه سېټ_File_Short_Name سېټ_File_Short_Name_W
#وإلا
#تعریف_کړه سېټ_File_Short_Name سېټ_File_Short_Name_A
#د_که_پای

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI Get_File_اندازه(HANDLE hFile,LPDWORD lp_File_اندازه_لوړ);
  WINBASEAPI WINBOOL WINAPI Get_File_اندازه_Ex(HANDLE hFile,PLARGE_INTEGER lp_File_اندازه);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI سېټ_Std_Handle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lp_بفر,DWORD n_شمېره_د_بایټونه_منزل_Write,LPDWORD lp_شمېره_د_بایټونه_Written,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lp_بفر,DWORD n_شمېره_د_بایټونه_منزل_Read,LPDWORD lp_شمېره_د_بایټونه_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dw_Io_Control_کوډ,LPVOID lp_دننه_بفر,DWORD n_دننه_بفر_اندازه,LPVOID lp_بهر_بفر,DWORD n_بهر_بفر_اندازه,LPDWORD lp_بایټونه_Returned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI سېټ_پیغام_انتظار_Indicator(HANDLE h_پیغام_Indicator,ULONG ul_پیغام_شمېر);
  WINBASEAPI WINBOOL WINAPI سېټ_پای_ټکی_د_File(HANDLE hFile);
  WINBASEAPI DWORD WINAPI سېټ_File_اشاره_ګر(HANDLE hFile,LONG l_واټن_منزل_Move,PLONG lp_واټن_منزل_Move_لوړ,DWORD dw_Move_لاره);
  WINBASEAPI WINBOOL WINAPI سېټ_File_اشاره_ګر_Ex(HANDLE hFile,LARGE_INTEGER li_واټن_منزل_Move,PLARGE_INTEGER lp_New_File_اشاره_ګر,DWORD dw_Move_لاره);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_Close(HANDLE h_پیدا_کړه_File);
  WINBASEAPI WINBOOL WINAPI Get_File_وخت(HANDLE hFile,LPFILETIME lp_Creation_وخت,LPFILETIME lp_وروستی_Access_وخت,LPFILETIME lp_وروستی_Write_وخت);
  WINBASEAPI WINBOOL WINAPI سېټ_File_وخت(HANDLE hFile,CONST FILETIME *lp_Creation_وخت,CONST FILETIME *lp_وروستی_Access_وخت,CONST FILETIME *lp_وروستی_Write_وخت);
  WINBASEAPI WINBOOL WINAPI سېټ_File_Valid_معلومات(HANDLE hFile,LONGLONG Valid_معلومات_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI سېټ_File_Short_Name_A(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI سېټ_File_Short_Name_W(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE h_سرچینه_Process_Handle,HANDLE h_سرچینه_Handle,HANDLE h_موخه_Process_Handle,LPHANDLE lp_موخه_Handle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI سېټ_Handle_Information(HANDLE hObject,DWORD dw_ماسک,DWORD dwFlags);

#تعریف_کړه HANDLE_FLAG_INHERIT 0x1
#تعریف_کړه HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#تعریف_کړه HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI بارول_Module(LPCSTR lpModuleName,LPVOID lp_Parameter_بلاک);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lp_Cmd_کرښه,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI تیاری_Comm(HANDLE hFile,DWORD dw_دننه_کتار,DWORD dw_بهر_کتار);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdw_اندازه);
  WINBASEAPI WINBOOL WINAPI Get_Comm_ماسک(HANDLE hFile,LPDWORD lp_Evt_ماسک);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI Get_Comm_Modem_حالت(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI سېټ_Comm_Break(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI سېټ_Comm_Config(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dw_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Comm_ماسک(HANDLE hFile,DWORD dw_Evt_ماسک);
  WINBASEAPI WINBOOL WINAPI سېټ_Comm_State(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI سېټ_Comm_Timeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,حرف cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lp_Evt_ماسک,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI سېټ_فیته_Position(HANDLE hDevice,DWORD dw_Position_لاره,DWORD dw_برخه_کول,DWORD dw_دننه_واټن_ټیټ,DWORD dw_دننه_واټن_لوړ,WINBOOL b_سمدستي);
  WINBASEAPI DWORD WINAPI Get_فیته_Position(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdw_برخه_کول,LPDWORD lpdw_دننه_واټن_ټیټ,LPDWORD lpdw_دننه_واټن_لوړ);
  WINBASEAPI DWORD WINAPI Prepare_فیته(HANDLE hDevice,DWORD dwOperation,WINBOOL b_سمدستي);
  WINBASEAPI DWORD WINAPI Erase_فیته(HANDLE hDevice,DWORD dwEraseType,WINBOOL b_سمدستي);
  WINBASEAPI DWORD WINAPI Create_فیته_برخه_کول(HANDLE hDevice,DWORD dw_برخه_کول_لاره,DWORD dw_شمېر,DWORD dw_اندازه);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dw_Tapemark_شمېر,WINBOOL b_سمدستي);
  WINBASEAPI DWORD WINAPI Get_فیته_حالت(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI Get_فیته_Parameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdw_اندازه,LPVOID lp_فیته_Information);

#تعریف_کړه GET_فیته_MEDIA_INFORMATION 0
#تعریف_کړه GET_فیته_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI سېټ_فیته_Parameters(HANDLE hDevice,DWORD dwOperation,LPVOID lp_فیته_Information);

#تعریف_کړه سېټ_فیته_MEDIA_INFORMATION 0
#تعریف_کړه سېټ_فیته_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI صحيح WINAPI MulDiv(صحيح n_شمېره,صحيح nNumerator,صحيح nDenominator);
  WINBASEAPI VOID WINAPI Get_System_وخت(LPSYSTEMTIME lp_System_وخت);
  WINBASEAPI VOID WINAPI Get_System_وخت_As_File_وخت(LPFILETIME lp_System_وخت_As_File_وخت);
  WINBASEAPI WINBOOL WINAPI سېټ_System_وخت(CONST SYSTEMTIME *lp_System_وخت);
  WINBASEAPI VOID WINAPI Get_Local_وخت(LPSYSTEMTIME lp_System_وخت);
  WINBASEAPI WINBOOL WINAPI سېټ_Local_وخت(CONST SYSTEMTIME *lp_System_وخت);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI سېټ_System_File_Cache_اندازه(اندازه_T Minimum_File_Cache_اندازه,اندازه_T اعظمي_File_Cache_اندازه,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI Get_System_File_Cache_اندازه(PSIZE_T lp_Minimum_File_Cache_اندازه,PSIZE_T lp_اعظمي_File_Cache_اندازه,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdw_Quota_کارول_شوی);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lp_Idle_وخت,LPFILETIME lp_Kernel_وخت,LPFILETIME lp_User_وخت);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  تعريفنوع بنية وخت_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } وخت_ZONE_INFORMATION_2,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#که_تعریف_شوی UNICODE
#تعریف_کړه Format_پیغام Format_پیغام_W
#وإلا
#تعریف_کړه Format_پیغام Format_پیغام_A
#د_که_پای

  WINBASEAPI WINBOOL WINAPI System_وخت_منزل_Tz_Specific_Local_وخت(LPTIME_ZONE_INFORMATION lp_وخت_Zone_Information,LPSYSTEMTIME lp_Universal_وخت,LPSYSTEMTIME lp_Local_وخت);
  WINBASEAPI WINBOOL WINAPI Tz_Specific_Local_وخت_منزل_System_وخت(LPTIME_ZONE_INFORMATION lp_وخت_Zone_Information,LPSYSTEMTIME lp_Local_وخت,LPSYSTEMTIME lp_Universal_وخت);
  WINBASEAPI DWORD WINAPI Get_وخت_Zone_Information(LPTIME_ZONE_INFORMATION lp_وخت_Zone_Information);
  WINBASEAPI WINBOOL WINAPI سېټ_وخت_Zone_Information(CONST وخت_ZONE_INFORMATION_2 *lp_وخت_Zone_Information);
  WINBASEAPI WINBOOL WINAPI System_وخت_منزل_File_وخت(CONST SYSTEMTIME *lp_System_وخت,LPFILETIME lp_File_وخت);
  WINBASEAPI WINBOOL WINAPI File_وخت_منزل_Local_File_وخت(CONST FILETIME *lp_File_وخت,LPFILETIME lp_Local_File_وخت);
  WINBASEAPI WINBOOL WINAPI Local_File_وخت_منزل_File_وخت(CONST FILETIME *lp_Local_File_وخت,LPFILETIME lp_File_وخت);
  WINBASEAPI WINBOOL WINAPI File_وخت_منزل_System_وخت(CONST FILETIME *lp_File_وخت,LPSYSTEMTIME lp_System_وخت);
  WINBASEAPI LONG WINAPI Compare_File_وخت(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI File_وخت_منزل_Dos_Date_وخت(CONST FILETIME *lp_File_وخت,LPWORD lpFatDate,LPWORD lp_Fat_وخت);
  WINBASEAPI WINBOOL WINAPI Dos_Date_وخت_منزل_File_وخت(کلمه_3 wFatDate,کلمه_3 w_Fat_وخت,LPFILETIME lp_File_وخت);
  WINBASEAPI DWORD WINAPI Get_Tick_شمېر(VOID);
  WINBASEAPI WINBOOL WINAPI سېټ_System_وخت_Adjustment(DWORD dw_وخت_Adjustment,WINBOOL b_وخت_Adjustment_Disabled);
  WINBASEAPI WINBOOL WINAPI Get_System_وخت_Adjustment(PDWORD lp_وخت_Adjustment,PDWORD lp_وخت_Increment,PBOOL lp_وخت_Adjustment_Disabled);
  WINBASEAPI DWORD WINAPI Format_پیغام_A(DWORD dwFlags,LPCVOID lp_سرچینه,DWORD dw_پیغام_Id,DWORD dwLanguageId,LPSTR lp_بفر,DWORD n_اندازه,va_list *Arguments);
  WINBASEAPI DWORD WINAPI Format_پیغام_W(DWORD dwFlags,LPCVOID lp_سرچینه,DWORD dw_پیغام_Id,DWORD dwLanguageId,LPWSTR lp_بفر,DWORD n_اندازه,va_list *Arguments);

#تعریف_کړه FORMAT_پیغام_ALLOCATE_بفر 0x100
#تعریف_کړه FORMAT_پیغام_IGNORE_INSERTS 0x200
#تعریف_کړه FORMAT_پیغام_FROM_STRING 0x400
#تعریف_کړه FORMAT_پیغام_FROM_HMODULE 0x800
#تعریف_کړه FORMAT_پیغام_FROM_SYSTEM 0x1000
#تعریف_کړه FORMAT_پیغام_دلیل_ARRAY 0x2000
#تعریف_کړه FORMAT_پیغام_MAX_پلنوالی_ماسک 0xff

#که_تعریف_شوی UNICODE
#تعریف_کړه CreateMailslot CreateMailslotW
#تعریف_کړه EncryptFile EncryptFileW
#تعریف_کړه DecryptFile DecryptFileW
#تعریف_کړه File_Encryption_حالت File_Encryption_حالت_W
#وإلا
#تعریف_کړه CreateMailslot CreateMailslotA
#تعریف_کړه EncryptFile EncryptFileA
#تعریف_کړه DecryptFile DecryptFileA
#تعریف_کړه File_Encryption_حالت File_Encryption_حالت_A
#د_که_پای

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_ځانګړتیاوې lp_Pipe_ځانګړتیاوې,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI سېټ_Named_Pipe_Handle_State(HANDLE hNamedPipe,LPDWORD lp_ډېرپېښ,LPDWORD lp_Max_Collection_شمېر,LPDWORD lp_Collect_معلومات_Timeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lp_بهر_بفر_اندازه,LPDWORD lp_دننه_بفر_اندازه,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lp_بفر,DWORD n_بفر_اندازه,LPDWORD lp_بایټونه_Read,LPDWORD lp_ټول_بایټونه_Avail,LPDWORD lp_بایټونه_کیڼ_This_پیغام);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lp_دننه_بفر,DWORD n_دننه_بفر_اندازه,LPVOID lp_بهر_بفر,DWORD n_بهر_بفر_اندازه,LPDWORD lp_بایټونه_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD n_Max_پیغام_اندازه,DWORD lReadTimeout,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD n_Max_پیغام_اندازه,DWORD lReadTimeout,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lp_Max_پیغام_اندازه,LPDWORD lp_بل_اندازه,LPDWORD lp_پیغام_شمېر,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI سېټ_Mailslot_Info(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI Map_View_د_File(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_دننه_واټن_لوړ,DWORD dw_File_دننه_واټن_ټیټ,اندازه_T dw_شمېره_د_بایټونه_منزل_Map);
  WINBASEAPI WINBOOL WINAPI Flush_View_د_File(LPCVOID lp_بنسټ_پته,اندازه_T dw_شمېره_د_بایټونه_منزل_Flush);
  WINBASEAPI WINBOOL WINAPI Unmap_View_د_File(LPCVOID lp_بنسټ_پته);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#تعریف_کړه FILE_ENCRYPTABLE 0
#تعریف_کړه FILE_IS_ENCRYPTED 1
#تعریف_کړه FILE_SYSTEM_ATTR 2
#تعریف_کړه FILE_ریښه_DIR 3
#تعریف_کړه FILE_SYSTEM_DIR 4
#تعریف_کړه FILE_UNKNOWN 5
#تعریف_کړه FILE_SYSTEM_NOT_SUPPORT 6
#تعریف_کړه FILE_USER_DISALLOWED 7
#تعریف_کړه FILE_READ_ONLY 8
#تعریف_کړه FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI File_Encryption_حالت_A(LPCSTR lpFileName,LPDWORD lp_حالت);
  WINADVAPI WINBOOL WINAPI File_Encryption_حالت_W(LPCWSTR lpFileName,LPDWORD lp_حالت);

#تعریف_کړه EFS_USE_RECOVERY_کلیګانې (0x1)

  تعريفنوع DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pb_معلومات,PVOID pvCallbackContext,ULONG ul_اوږدتیا);
  تعريفنوع DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pb_معلومات,PVOID pvCallbackContext,PULONG ul_اوږدتیا);

#تعریف_کړه CREATE_FOR_IMPORT (1)
#تعریف_کړه CREATE_FOR_DIR (2)
#تعریف_کړه OVERWRITE_HIDDEN (4)

#که_تعریف_شوی UNICODE
#تعریف_کړه OpenEncryptedFileRaw OpenEncryptedFileRawW
#تعریف_کړه lstrcmp lstrcmpW
#تعریف_کړه lstrcmpi lstrcmpiW
#تعریف_کړه lstrcpyn lstrcpynW
#تعریف_کړه lstrcpy lstrcpyW
#تعریف_کړه lstrcat lstrcatW
#تعریف_کړه lstrlen lstrlenW
#وإلا
#تعریف_کړه OpenEncryptedFileRaw OpenEncryptedFileRawA
#تعریف_کړه lstrcmp lstrcmpA
#تعریف_کړه lstrcmpi lstrcmpiA
#تعریف_کړه lstrcpyn lstrcpynA
#تعریف_کړه lstrcpy lstrcpyA
#تعریف_کړه lstrcat lstrcatA
#تعریف_کړه lstrlen lstrlenA
#د_که_پای

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI صحيح WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,صحيح i_Max_اوږدتیا);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,صحيح i_Max_اوږدتیا);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI صحيح WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lp_لار_Name,صحيح iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lp_لار_Name,صحيح iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lp_بفر,UINT u_بایټونه);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lp_بفر,UINT u_بایټونه);
  WINBASEAPI اوږد WINAPI _hread(HFILE hFile,LPVOID lp_بفر,اوږد l_بایټونه);
  WINBASEAPI اوږد WINAPI _hwrite(HFILE hFile,LPCCH lp_بفر,اوږد l_بایټونه);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG l_دننه_واټن,صحيح iOrigin);
  WINADVAPI WINBOOL WINAPI Is_متن_Unicode(CONST VOID *lpv,صحيح i_اندازه,LPINT lpi_پایله);

#تعریف_کړه FLS_بهر_د_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI Fls_Get_ارزښت(DWORD dw_Fls_شاخص);
  WINBASEAPI WINBOOL WINAPI Fls_سېټ_ارزښت(DWORD dw_Fls_شاخص,PVOID lp_Fls_معلومات);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dw_Fls_شاخص);

#تعریف_کړه TLS_بهر_د_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI Tls_Get_ارزښت(DWORD dw_Tls_شاخص);
  WINBASEAPI WINBOOL WINAPI Tls_سېټ_ارزښت(DWORD dw_Tls_شاخص,LPVOID lp_Tls_ارزښت);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dw_Tls_شاخص);

  تعريفنوع VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dw_Error_کوډ,DWORD dw_شمېره_د_بایټونه_Transfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI Wait_For_مضرب_Objects_Ex(DWORD n_شمېر,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE h_Object_منزل_Signal,HANDLE h_Object_منزل_Wait_On,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lp_بفر,DWORD n_شمېره_د_بایټونه_منزل_Read,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lp_بفر,DWORD n_شمېره_د_بایټونه_منزل_Write,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lp_بفر,DWORD n_شمېره_د_بایټونه_منزل_Read,LPDWORD lp_شمېره_د_بایټونه_Read,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dw_ټیټ_بایټونه_منزل_Seek,DWORD dw_لوړ_بایټونه_منزل_Seek,LPDWORD lpdw_ټیټ_Byte_Seeked,LPDWORD lpdw_لوړ_Byte_Seeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lp_بفر,DWORD n_شمېره_د_بایټونه_منزل_Write,LPDWORD lp_شمېره_د_بایټونه_Written,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  تعريفنوع بنية WIN32_بهیر_ID {
    DWORD dw_بهیر_Id;
    DWORD dw_بهیر_ځانګړتیاوې;
    LARGE_INTEGER اندازه_3;
    DWORD dw_بهیر_Name_اندازه;
    WCHAR c_بهیر_Name[ANYSIZE_ARRAY];
  } WIN32_بهیر_ID_2,*LPWIN32_بهیر_ID;

#تعریف_کړه BACKUP_INVALID 0x0
#تعریف_کړه BACKUP_معلومات 0x1
#تعریف_کړه BACKUP_EA_معلومات 0x2
#تعریف_کړه BACKUP_SECURITY_معلومات 0x3
#تعریف_کړه BACKUP_ALTERNATE_معلومات 0x4
#تعریف_کړه BACKUP_LINK 0x5
#تعریف_کړه BACKUP_PROPERTY_معلومات 0x6
#تعریف_کړه BACKUP_OBJECT_ID 0x7
#تعریف_کړه BACKUP_REPARSE_معلومات 0x8
#تعریف_کړه BACKUP_SPARSE_بلاک 0x9

#تعریف_کړه بهیر_نورمال_ATTRIBUTE 0x0
#تعریف_کړه بهیر_MODIFIED_WHEN_READ 0x1
#تعریف_کړه بهیر_لري_SECURITY 0x2
#تعریف_کړه بهیر_لري_PROPERTIES 0x4
#تعریف_کړه بهیر_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_شمېره_د_بایټونه_منزل_Read,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_شمېره_د_بایټونه_منزل_Write,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#تعریف_کړه STARTF_USESHOWWINDOW 0x1
#تعریف_کړه STARTF_USESIZE 0x2
#تعریف_کړه STARTF_USEPOSITION 0x4
#تعریف_کړه STARTF_USECOUNTCHARS 0x8
#تعریف_کړه STARTF_USEFILLATTRIBUTE 0x10
#تعریف_کړه STARTF_RUNFULLSCREEN 0x20
#تعریف_کړه STARTF_FORCEONFEEDBACK 0x40
#تعریف_کړه STARTF_FORCEOFFFEEDBACK 0x80
#تعریف_کړه STARTF_USESTDHANDLES 0x100

#تعریف_کړه STARTF_USEHOTKEY 0x200

  تعريفنوع بنية _STARTUPINFOA {
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
    کلمه_3 w_Show_کړکۍ;
    کلمه_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_ننوت;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOA,*LPSTARTUPINFOA;

  تعريفنوع بنية _STARTUPINFOW {
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
    کلمه_3 w_Show_کړکۍ;
    کلمه_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_ننوت;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#که_تعریف_شوی UNICODE
  تعريفنوع STARTUPINFOW STARTUPINFO;
  تعريفنوع LPSTARTUPINFOW LPSTARTUPINFO;
#وإلا
  تعريفنوع STARTUPINFOA STARTUPINFO;
  تعريفنوع LPSTARTUPINFOA LPSTARTUPINFO;
#د_که_پای

#تعریف_کړه SHUTDOWN_NORETRY 0x1

  تعريفنوع بنية WIN32_پیدا_کړه_DATAA {
    DWORD dw_File_ځانګړتیاوې;
    FILETIME ft_Creation_وخت;
    FILETIME ft_وروستی_Access_وخت;
    FILETIME ft_وروستی_Write_وخت;
    DWORD n_File_اندازه_لوړ;
    DWORD n_File_اندازه_ټیټ;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_لار];
    CHAR cAlternateFileName[14];
  } WIN32_پیدا_کړه_DATAA_2,*PWIN32_پیدا_کړه_DATAA,*LPWIN32_پیدا_کړه_DATAA;

  تعريفنوع بنية WIN32_پیدا_کړه_DATAW {
    DWORD dw_File_ځانګړتیاوې;
    FILETIME ft_Creation_وخت;
    FILETIME ft_وروستی_Access_وخت;
    FILETIME ft_وروستی_Write_وخت;
    DWORD n_File_اندازه_لوړ;
    DWORD n_File_اندازه_ټیټ;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_لار];
    WCHAR cAlternateFileName[14];
  } WIN32_پیدا_کړه_DATAW_2,*PWIN32_پیدا_کړه_DATAW,*LPWIN32_پیدا_کړه_DATAW;

#که_تعریف_شوی UNICODE
  تعريفنوع WIN32_پیدا_کړه_DATAW_2 WIN32_پیدا_کړه_معلومات;
  تعريفنوع PWIN32_پیدا_کړه_DATAW PWIN32_پیدا_کړه_معلومات;
  تعريفنوع LPWIN32_پیدا_کړه_DATAW LPWIN32_پیدا_کړه_معلومات;
#وإلا
  تعريفنوع WIN32_پیدا_کړه_DATAA_2 WIN32_پیدا_کړه_معلومات;
  تعريفنوع PWIN32_پیدا_کړه_DATAA PWIN32_پیدا_کړه_معلومات;
  تعريفنوع LPWIN32_پیدا_کړه_DATAA LPWIN32_پیدا_کړه_معلومات;
#د_که_پای

  تعريفنوع بنية WIN32_FILE_ATTRIBUTE_معلومات {
    DWORD dw_File_ځانګړتیاوې;
    FILETIME ft_Creation_وخت;
    FILETIME ft_وروستی_Access_وخت;
    FILETIME ft_وروستی_Write_وخت;
    DWORD n_File_اندازه_لوړ;
    DWORD n_File_اندازه_ټیټ;
  } WIN32_FILE_ATTRIBUTE_معلومات_2,*LPWIN32_FILE_ATTRIBUTE_معلومات;

#که_تعریف_شوی UNICODE
#تعریف_کړه CreateMutex CreateMutexW
#تعریف_کړه OpenMutex OpenMutexW
#تعریف_کړه CreateEvent CreateEventW
#تعریف_کړه OpenEvent OpenEventW
#تعریف_کړه CreateSemaphore CreateSemaphoreW
#تعریف_کړه OpenSemaphore OpenSemaphoreW
#وإلا
#تعریف_کړه CreateMutex CreateMutexA
#تعریف_کړه OpenMutex OpenMutexA
#تعریف_کړه CreateEvent CreateEventA
#تعریف_کړه OpenEvent OpenEventA
#تعریف_کړه CreateSemaphore CreateSemaphoreA
#تعریف_کړه OpenSemaphore OpenSemaphoreA
#د_که_پای

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_ځانګړتیاوې lp_Mutex_ځانګړتیاوې,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_ځانګړتیاوې lp_Mutex_ځانګړتیاوې,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_ځانګړتیاوې lp_Event_ځانګړتیاوې,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_ځانګړتیاوې lp_Event_ځانګړتیاوې,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ځانګړتیاوې lp_Semaphore_ځانګړتیاوې,LONG l_Initial_شمېر,LONG l_اعظمي_شمېر,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_ځانګړتیاوې lp_Semaphore_ځانګړتیاوې,LONG l_Initial_شمېر,LONG l_اعظمي_شمېر,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  تعريفنوع VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lp_Arg_منزل_Completion_Routine,DWORD dw_Timer_ټیټ_ارزښت,DWORD dw_Timer_لوړ_ارزښت);

#که_تعریف_شوی UNICODE
#تعریف_کړه CreateWaitableTimer CreateWaitableTimerW
#تعریف_کړه OpenWaitableTimer OpenWaitableTimerW
#تعریف_کړه CreateFileMapping CreateFileMappingW
#تعریف_کړه OpenFileMapping OpenFileMappingW
#تعریف_کړه Get_Logical_Drive_مزي_ګانې Get_Logical_Drive_مزي_ګانې_W
#تعریف_کړه بارول_Library بارول_Library_W
#تعریف_کړه بارول_Library_Ex بارول_Library_Ex_W
#تعریف_کړه GetModuleFileName GetModuleFileNameW
#تعریف_کړه GetModuleHandle GetModuleHandleW
#وإلا
#تعریف_کړه CreateWaitableTimer CreateWaitableTimerA
#تعریف_کړه OpenWaitableTimer OpenWaitableTimerA
#تعریف_کړه CreateFileMapping CreateFileMappingA
#تعریف_کړه OpenFileMapping OpenFileMappingA
#تعریف_کړه Get_Logical_Drive_مزي_ګانې Get_Logical_Drive_مزي_ګانې_A
#تعریف_کړه بارول_Library بارول_Library_A
#تعریف_کړه بارول_Library_Ex بارول_Library_Ex_A
#تعریف_کړه GetModuleFileName GetModuleFileNameA
#تعریف_کړه GetModuleHandle GetModuleHandleA
#د_که_پای

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_ځانګړتیاوې lp_Timer_ځانګړتیاوې,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_ځانګړتیاوې lp_Timer_ځانګړتیاوې,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI سېټ_Waitable_Timer(HANDLE hTimer,ثابت LARGE_INTEGER *lp_Due_وخت,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lp_Arg_منزل_Completion_Routine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_ځانګړتیاوې lp_File_Mapping_ځانګړتیاوې,DWORD flProtect,DWORD dw_اعظمي_اندازه_لوړ,DWORD dw_اعظمي_اندازه_ټیټ,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_ځانګړتیاوې lp_File_Mapping_ځانګړتیاوې,DWORD flProtect,DWORD dw_اعظمي_اندازه_لوړ,DWORD dw_اعظمي_اندازه_ټیټ,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_مزي_ګانې_A(DWORD n_بفر_اوږدتیا,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_مزي_ګانې_W(DWORD n_بفر_اوږدتیا,LPWSTR lp_بفر);

  تعريفنوع تعداد حافظه_RESOURCE_NOTIFICATION_TYPE {
    ټیټ_حافظه_Resource_Notification,لوړ_حافظه_Resource_Notification
  } حافظه_RESOURCE_NOTIFICATION_TYPE_2;

  WINBASEAPI HANDLE WINAPI Create_حافظه_Resource_Notification(حافظه_RESOURCE_NOTIFICATION_TYPE_2 NotificationType);
  WINBASEAPI WINBOOL WINAPI Query_حافظه_Resource_Notification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI بارول_Library_A(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI بارول_Library_W(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI بارول_Library_Ex_A(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI بارول_Library_Ex_W(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#تعریف_کړه DONT_RESOLVE_DLL_REFERENCES 0x1
#تعریف_کړه بارول_LIBRARY_AS_DATAFILE 0x2
#تعریف_کړه بارول_WITH_ALTERED_پلټنه_لار 0x8
#تعریف_کړه بارول_IGNORE_کوډ_AUTHZ_LEVEL 0x10
#تعریف_کړه بارول_LIBRARY_AS_IMAGE_RESOURCE 0x20
#تعریف_کړه بارول_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40
#تعریف_کړه بارول_LIBRARY_REQUIRE_SIGNED_موخه 0x80
#تعریف_کړه بارول_LIBRARY_پلټنه_DLL_بارول_DIR 0x100
#تعریف_کړه بارول_LIBRARY_پلټنه_APPLICATION_DIR 0x200
#تعریف_کړه بارول_LIBRARY_پلټنه_USER_DIRS 0x400
#تعریف_کړه بارول_LIBRARY_پلټنه_SYSTEM32 0x800
#تعریف_کړه بارول_LIBRARY_پلټنه_DEFAULT_DIRS 0x1000
#تعریف_کړه بارول_LIBRARY_خوندي_CURRENT_DIRS 0x2000

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD n_اندازه);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#که_نه_تعریف_شوی RC_INVOKED
#تعریف_کړه GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#تعریف_کړه GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#تعریف_کړه GET_MODULE_HANDLE_EX_FLAG_FROM_پته (0x4)

  تعريفنوع WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  تعريفنوع WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#که_تعریف_شوی UNICODE
#تعریف_کړه PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#تعریف_کړه GetModuleHandleEx GetModuleHandleExW
#وإلا
#تعریف_کړه PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#تعریف_کړه GetModuleHandleEx GetModuleHandleExA
#د_که_پای

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه Need_Current_Directory_For_Exe_لار Need_Current_Directory_For_Exe_لار_W
#تعریف_کړه CreateProcess CreateProcessW
#تعریف_کړه FatalAppExit FatalAppExitW
#تعریف_کړه GetStartupInfo GetStartupInfoW
#تعریف_کړه Get_Command_کرښه Get_Command_کرښه_W
#تعریف_کړه GetEnvironmentVariable GetEnvironmentVariableW
#تعریف_کړه سېټ_Environment_Variable سېټ_Environment_Variable_W
#تعریف_کړه Expand_Environment_مزي_ګانې Expand_Environment_مزي_ګانې_W
#تعریف_کړه GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#تعریف_کړه سېټ_Firmware_Environment_Variable سېټ_Firmware_Environment_Variable_W
#تعریف_کړه OutputDebugString OutputDebugStringW
#تعریف_کړه پیدا_کړه_Resource پیدا_کړه_Resource_W
#تعریف_کړه پیدا_کړه_Resource_Ex پیدا_کړه_Resource_Ex_W
#وإلا
#تعریف_کړه Need_Current_Directory_For_Exe_لار Need_Current_Directory_For_Exe_لار_A
#تعریف_کړه CreateProcess CreateProcessA
#تعریف_کړه FatalAppExit FatalAppExitA
#تعریف_کړه GetStartupInfo GetStartupInfoA
#تعریف_کړه Get_Command_کرښه Get_Command_کرښه_A
#تعریف_کړه GetEnvironmentVariable GetEnvironmentVariableA
#تعریف_کړه سېټ_Environment_Variable سېټ_Environment_Variable_A
#تعریف_کړه Expand_Environment_مزي_ګانې Expand_Environment_مزي_ګانې_A
#تعریف_کړه GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#تعریف_کړه سېټ_Firmware_Environment_Variable سېټ_Firmware_Environment_Variable_A
#تعریف_کړه OutputDebugString OutputDebugStringA
#تعریف_کړه پیدا_کړه_Resource پیدا_کړه_Resource_A
#تعریف_کړه پیدا_کړه_Resource_Ex پیدا_کړه_Resource_Ex_A
#د_که_پای

  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_لار_A(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_لار_W(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lp_Command_کرښه,LPSECURITY_ځانګړتیاوې lp_Process_ځانګړتیاوې,LPSECURITY_ځانګړتیاوې lp_Thread_ځانګړتیاوې,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lp_Command_کرښه,LPSECURITY_ځانګړتیاوې lp_Process_ځانګړتیاوې,LPSECURITY_ځانګړتیاوې lp_Thread_ځانګړتیاوې,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI جمع_کړه_Local_Alternate_Computer_Name_A(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI جمع_کړه_Local_Alternate_Computer_Name_W(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI سېټ_Process_Shutdown_Parameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI Get_Process_نسخه(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lp_پیغام_متن);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lp_پیغام_متن);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI Get_Command_کرښه_A(VOID);
  WINBASEAPI LPWSTR WINAPI Get_Command_کرښه_W(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lp_بفر,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lp_بفر,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Environment_Variable_A(LPCSTR lpName,LPCSTR lp_ارزښت);
  WINBASEAPI WINBOOL WINAPI سېټ_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lp_ارزښت);
  WINBASEAPI DWORD WINAPI Expand_Environment_مزي_ګانې_A(LPCSTR lpSrc,LPSTR lpDst,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI Expand_Environment_مزي_ګانې_W(LPCWSTR lpSrc,LPWSTR lpDst,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_بفر,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_بفر,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Firmware_Environment_Variable_A(LPCSTR lpName,LPCSTR lpGuid,PVOID p_ارزښت,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Firmware_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_ارزښت,DWORD n_اندازه);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI پیدا_کړه_Resource_A(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI پیدا_کړه_Resource_W(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI پیدا_کړه_Resource_Ex_A(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,کلمه_3 wLanguage);
  WINBASEAPI HRSRC WINAPI پیدا_کړه_Resource_Ex_W(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,کلمه_3 wLanguage);

#که_تعریف_شوی UNICODE
#تعریف_کړه ENUMRESTYPEPROC ENUMRESTYPEPROCW
#تعریف_کړه ENUMRESNAMEPROC ENUMRESNAMEPROCW
#تعریف_کړه ENUMRESLANGPROC ENUMRESLANGPROCW
#تعریف_کړه EnumResourceTypes EnumResourceTypesW
#تعریف_کړه Enum_Resource_نومونه Enum_Resource_نومونه_W
#تعریف_کړه EnumResourceLanguages EnumResourceLanguagesW
#تعریف_کړه BeginUpdateResource BeginUpdateResourceW
#تعریف_کړه UpdateResource UpdateResourceW
#تعریف_کړه پای_ټکی_Update_Resource پای_ټکی_Update_Resource_W
#تعریف_کړه Global_جمع_کړه_Atom Global_جمع_کړه_Atom_W
#تعریف_کړه Global_پیدا_کړه_Atom Global_پیدا_کړه_Atom_W
#تعریف_کړه GlobalGetAtomName GlobalGetAtomNameW
#تعریف_کړه جمع_کړه_Atom جمع_کړه_Atom_W
#تعریف_کړه پیدا_کړه_Atom پیدا_کړه_Atom_W
#تعریف_کړه GetAtomName GetAtomNameW
#تعریف_کړه GetProfileInt GetProfileIntW
#تعریف_کړه GetProfileString GetProfileStringW
#تعریف_کړه WriteProfileString WriteProfileStringW
#تعریف_کړه GetProfileSection GetProfileSectionW
#تعریف_کړه WriteProfileSection WriteProfileSectionW
#تعریف_کړه Get_شخصي_Profile_Int Get_شخصي_Profile_Int_W
#تعریف_کړه Get_شخصي_Profile_String Get_شخصي_Profile_String_W
#تعریف_کړه Write_شخصي_Profile_String Write_شخصي_Profile_String_W
#تعریف_کړه Get_شخصي_Profile_Section Get_شخصي_Profile_Section_W
#تعریف_کړه Write_شخصي_Profile_Section Write_شخصي_Profile_Section_W
#تعریف_کړه Get_شخصي_Profile_Section_نومونه Get_شخصي_Profile_Section_نومونه_W
#تعریف_کړه Get_شخصي_Profile_Struct Get_شخصي_Profile_Struct_W
#تعریف_کړه Write_شخصي_Profile_Struct Write_شخصي_Profile_Struct_W
#تعریف_کړه GetDriveType GetDriveTypeW
#تعریف_کړه GetSystemDirectory GetSystemDirectoryW
#تعریف_کړه Get_لنډمهاله_لار Get_لنډمهاله_لار_W
#تعریف_کړه Get_لنډمهاله_File_Name Get_لنډمهاله_File_Name_W
#تعریف_کړه GetWindowsDirectory GetWindowsDirectoryW
#تعریف_کړه GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#تعریف_کړه جمع_کړه_Local_Alternate_Computer_Name جمع_کړه_Local_Alternate_Computer_Name_W
#وإلا
#تعریف_کړه ENUMRESTYPEPROC ENUMRESTYPEPROCA
#تعریف_کړه ENUMRESNAMEPROC ENUMRESNAMEPROCA
#تعریف_کړه ENUMRESLANGPROC ENUMRESLANGPROCA
#تعریف_کړه EnumResourceTypes EnumResourceTypesA
#تعریف_کړه Enum_Resource_نومونه Enum_Resource_نومونه_A
#تعریف_کړه EnumResourceLanguages EnumResourceLanguagesA
#تعریف_کړه BeginUpdateResource BeginUpdateResourceA
#تعریف_کړه UpdateResource UpdateResourceA
#تعریف_کړه پای_ټکی_Update_Resource پای_ټکی_Update_Resource_A
#تعریف_کړه Global_جمع_کړه_Atom Global_جمع_کړه_Atom_A
#تعریف_کړه Global_پیدا_کړه_Atom Global_پیدا_کړه_Atom_A
#تعریف_کړه GlobalGetAtomName GlobalGetAtomNameA
#تعریف_کړه جمع_کړه_Atom جمع_کړه_Atom_A
#تعریف_کړه پیدا_کړه_Atom پیدا_کړه_Atom_A
#تعریف_کړه GetAtomName GetAtomNameA
#تعریف_کړه GetProfileInt GetProfileIntA
#تعریف_کړه GetProfileString GetProfileStringA
#تعریف_کړه WriteProfileString WriteProfileStringA
#تعریف_کړه GetProfileSection GetProfileSectionA
#تعریف_کړه WriteProfileSection WriteProfileSectionA
#تعریف_کړه Get_شخصي_Profile_Int Get_شخصي_Profile_Int_A
#تعریف_کړه Get_شخصي_Profile_String Get_شخصي_Profile_String_A
#تعریف_کړه Write_شخصي_Profile_String Write_شخصي_Profile_String_A
#تعریف_کړه Get_شخصي_Profile_Section Get_شخصي_Profile_Section_A
#تعریف_کړه Write_شخصي_Profile_Section Write_شخصي_Profile_Section_A
#تعریف_کړه Get_شخصي_Profile_Section_نومونه Get_شخصي_Profile_Section_نومونه_A
#تعریف_کړه Get_شخصي_Profile_Struct Get_شخصي_Profile_Struct_A
#تعریف_کړه Write_شخصي_Profile_Struct Write_شخصي_Profile_Struct_A
#تعریف_کړه GetDriveType GetDriveTypeA
#تعریف_کړه GetSystemDirectory GetSystemDirectoryA
#تعریف_کړه Get_لنډمهاله_لار Get_لنډمهاله_لار_A
#تعریف_کړه Get_لنډمهاله_File_Name Get_لنډمهاله_File_Name_A
#تعریف_کړه GetWindowsDirectory GetWindowsDirectoryA
#تعریف_کړه GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#تعریف_کړه جمع_کړه_Local_Alternate_Computer_Name جمع_کړه_Local_Alternate_Computer_Name_A
#د_که_پای

  تعريفنوع WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,کلمه_3 wLanguage,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,کلمه_3 wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_نومونه_A(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_نومونه_W(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,کلمه_3 wLanguage,LPVOID lp_معلومات,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,کلمه_3 wLanguage,LPVOID lp_معلومات,DWORD cb);
  WINBASEAPI WINBOOL WINAPI پای_ټکی_Update_Resource_A(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI پای_ټکی_Update_Resource_W(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI Global_جمع_کړه_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_جمع_کړه_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI Global_پیدا_کړه_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_پیدا_کړه_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lp_بفر,صحيح n_اندازه);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lp_بفر,صحيح n_اندازه);
  WINBASEAPI ATOM WINAPI جمع_کړه_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI جمع_کړه_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI پیدا_کړه_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI پیدا_کړه_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lp_بفر,صحيح n_اندازه);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lp_بفر,صحيح n_اندازه);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lp_کلی_Name,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_کلی_Name,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lp_کلی_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_کلی_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lp_کلی_Name,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_کلی_Name,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI Get_شخصي_Profile_Int_A(LPCSTR lpAppName,LPCSTR lp_کلی_Name,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI Get_شخصي_Profile_Int_W(LPCWSTR lpAppName,LPCWSTR lp_کلی_Name,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_شخصي_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_کلی_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_اندازه,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_شخصي_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_کلی_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_اندازه,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_شخصي_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_کلی_Name,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_شخصي_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_کلی_Name,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_شخصي_Profile_Section_A(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_اندازه,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_شخصي_Profile_Section_W(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_اندازه,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_شخصي_Profile_Section_A(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_شخصي_Profile_Section_W(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_شخصي_Profile_Section_نومونه_A(LPSTR lpsz_Return_بفر,DWORD n_اندازه,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_شخصي_Profile_Section_نومونه_W(LPWSTR lpsz_Return_بفر,DWORD n_اندازه,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Get_شخصي_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_کلی,LPVOID lpStruct,UINT u_اندازه_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Get_شخصي_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_کلی,LPVOID lpStruct,UINT u_اندازه_Struct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_شخصي_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_کلی,LPVOID lpStruct,UINT u_اندازه_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_شخصي_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_کلی,LPVOID lpStruct,UINT u_اندازه_Struct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lp_ریښه_لار_Name);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lp_ریښه_لار_Name);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lp_بفر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lp_بفر,UINT u_اندازه);
  WINBASEAPI DWORD WINAPI Get_لنډمهاله_لار_A(DWORD n_بفر_اوږدتیا,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI Get_لنډمهاله_لار_W(DWORD n_بفر_اوږدتیا,LPWSTR lp_بفر);
  WINBASEAPI UINT WINAPI Get_لنډمهاله_File_Name_A(LPCSTR lp_لار_Name,LPCSTR lp_مختاړی_String,UINT uUnique,LPSTR lp_لنډمهاله_File_Name);
  WINBASEAPI UINT WINAPI Get_لنډمهاله_File_Name_W(LPCWSTR lp_لار_Name,LPCWSTR lp_مختاړی_String,UINT uUnique,LPWSTR lp_لنډمهاله_File_Name);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lp_بفر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lp_بفر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lp_بفر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lp_بفر,UINT u_اندازه);

#که_نه_تعریف_شوی RC_INVOKED
#که_تعریف_شوی UNICODE
#تعریف_کړه GetSystemWow64Directory GetSystemWow64DirectoryW
#وإلا
#تعریف_کړه GetSystemWow64Directory GetSystemWow64DirectoryA
#د_که_پای

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lp_بفر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lp_بفر,UINT u_اندازه);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *Old_ارزښت);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID Ol_ارزښت);

  تعريفنوع UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lp_بفر,UINT u_اندازه);
  تعريفنوع UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lp_بفر,UINT u_اندازه);

#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T متن_3("GetSystemWow64DirectoryA")
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T متن_3("GetSystemWow64DirectoryW")

#که_تعریف_شوی UNICODE
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#وإلا
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#تعریف_کړه GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#د_که_پای
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه سېټ_Current_Directory سېټ_Current_Directory_W
#تعریف_کړه GetCurrentDirectory GetCurrentDirectoryW
#تعریف_کړه سېټ_Dll_Directory سېټ_Dll_Directory_W
#تعریف_کړه GetDllDirectory GetDllDirectoryW
#تعریف_کړه GetDiskFreeSpace GetDiskFreeSpaceW
#تعریف_کړه GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#تعریف_کړه CreateDirectory CreateDirectoryW
#تعریف_کړه CreateDirectoryEx CreateDirectoryExW
#تعریف_کړه RemoveDirectory RemoveDirectoryW
#تعریف_کړه Get_ډک_لار_Name Get_ډک_لار_Name_W
#تعریف_کړه DefineDosDevice DefineDosDeviceW
#تعریف_کړه QueryDosDevice QueryDosDeviceW
#تعریف_کړه CreateFile CreateFileW
#تعریف_کړه سېټ_File_ځانګړتیاوې سېټ_File_ځانګړتیاوې_W
#تعریف_کړه Get_File_ځانګړتیاوې Get_File_ځانګړتیاوې_W
#وإلا
#تعریف_کړه سېټ_Current_Directory سېټ_Current_Directory_A
#تعریف_کړه GetCurrentDirectory GetCurrentDirectoryA
#تعریف_کړه سېټ_Dll_Directory سېټ_Dll_Directory_A
#تعریف_کړه GetDllDirectory GetDllDirectoryA
#تعریف_کړه GetDiskFreeSpace GetDiskFreeSpaceA
#تعریف_کړه GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#تعریف_کړه CreateDirectory CreateDirectoryA
#تعریف_کړه CreateDirectoryEx CreateDirectoryExA
#تعریف_کړه RemoveDirectory RemoveDirectoryA
#تعریف_کړه Get_ډک_لار_Name Get_ډک_لار_Name_A
#تعریف_کړه DefineDosDevice DefineDosDeviceA
#تعریف_کړه QueryDosDevice QueryDosDeviceA
#تعریف_کړه CreateFile CreateFileA
#تعریف_کړه سېټ_File_ځانګړتیاوې سېټ_File_ځانګړتیاوې_A
#تعریف_کړه Get_File_ځانګړتیاوې Get_File_ځانګړتیاوې_A
#د_که_پای

  WINBASEAPI WINBOOL WINAPI سېټ_Current_Directory_A(LPCSTR lp_لار_Name);
  WINBASEAPI WINBOOL WINAPI سېټ_Current_Directory_W(LPCWSTR lp_لار_Name);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD n_بفر_اوږدتیا,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD n_بفر_اوږدتیا,LPWSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI سېټ_Dll_Directory_A(LPCSTR lp_لار_Name);
  WINBASEAPI WINBOOL WINAPI سېټ_Dll_Directory_W(LPCWSTR lp_لار_Name);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD n_بفر_اوږدتیا,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD n_بفر_اوږدتیا,LPWSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lp_ریښه_لار_Name,LPDWORD lp_Sectors_فی_Cluster,LPDWORD lp_بایټونه_فی_Sector,LPDWORD lp_شمېره_د_Free_Clusters,LPDWORD lp_ټول_شمېره_د_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lp_ریښه_لار_Name,LPDWORD lp_Sectors_فی_Cluster,LPDWORD lp_بایټونه_فی_Sector,LPDWORD lp_شمېره_د_Free_Clusters,LPDWORD lp_ټول_شمېره_د_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lp_Free_بایټونه_شته_منزل_Caller,PULARGE_INTEGER lp_ټول_شمېره_د_بایټونه,PULARGE_INTEGER lp_ټول_شمېره_د_Free_بایټونه);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lp_Free_بایټونه_شته_منزل_Caller,PULARGE_INTEGER lp_ټول_شمېره_د_بایټونه,PULARGE_INTEGER lp_ټول_شمېره_د_Free_بایټونه);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lp_لار_Name,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lp_لار_Name,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lp_لار_Name);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lp_لار_Name);
  WINBASEAPI DWORD WINAPI Get_ډک_لار_Name_A(LPCSTR lpFileName,DWORD n_بفر_اوږدتیا,LPSTR lp_بفر,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI Get_ډک_لار_Name_W(LPCWSTR lpFileName,DWORD n_بفر_اوږدتیا,LPWSTR lp_بفر,LPWSTR *lpFilePart);

#تعریف_کړه DDD_RAW_موخه_لار 0x1
#تعریف_کړه DDD_REMOVE_DEFINITION 0x2
#تعریف_کړه DDD_EXACT_سمون_ON_REMOVE 0x4
#تعریف_کړه DDD_NO_خپرونه_SYSTEM 0x8
#تعریف_کړه DDD_LUID_خپرونه_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lp_موخه_لار);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lp_موخه_لار);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lp_موخه_لار,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lp_موخه_لار,DWORD ucchMax);

#تعریف_کړه EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_ډېرپېښ,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې,DWORD dwCreationDisposition,DWORD dw_Flags_And_ځانګړتیاوې,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_ډېرپېښ,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې,DWORD dwCreationDisposition,DWORD dw_Flags_And_ځانګړتیاوې,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dw_Share_ډېرپېښ,DWORD dw_Flags_And_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI سېټ_File_ځانګړتیاوې_A(LPCSTR lpFileName,DWORD dw_File_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI سېټ_File_ځانګړتیاوې_W(LPCWSTR lpFileName,DWORD dw_File_ځانګړتیاوې);
  WINBASEAPI DWORD WINAPI Get_File_ځانګړتیاوې_A(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_File_ځانګړتیاوې_W(LPCWSTR lpFileName);

  تعريفنوع تعداد GET_FILEEX_INFO_پوړونه {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_پوړونه_2;

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_File_ځانګړتیاوې_Ex Get_File_ځانګړتیاوې_Ex_W
#تعریف_کړه Get_Compressed_File_اندازه Get_Compressed_File_اندازه_W
#تعریف_کړه DeleteFile DeleteFileW
#تعریف_کړه CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#وإلا
#تعریف_کړه Get_File_ځانګړتیاوې_Ex Get_File_ځانګړتیاوې_Ex_A
#تعریف_کړه Get_Compressed_File_اندازه Get_Compressed_File_اندازه_A
#تعریف_کړه DeleteFile DeleteFileA
#تعریف_کړه CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#د_که_پای

  WINBASEAPI WINBOOL WINAPI Get_File_ځانګړتیاوې_Ex_A(LPCSTR lpFileName,GET_FILEEX_INFO_پوړونه_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI Get_File_ځانګړتیاوې_Ex_W(LPCWSTR lpFileName,GET_FILEEX_INFO_پوړونه_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_اندازه_A(LPCSTR lpFileName,LPDWORD lp_File_اندازه_لوړ);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_اندازه_W(LPCWSTR lpFileName,LPDWORD lp_File_اندازه_لوړ);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD Oem_Name_اندازه,PBOOL pb_Name_لري_Spaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD Oem_Name_اندازه,PBOOL pb_Name_لري_Spaces,PBOOL pbNameLegal);

  تعريفنوع تعداد FINDEX_INFO_پوړونه {
    پیدا_کړه_Ex_Info_Standard,پیدا_کړه_Ex_Info_Max_Info_Level
  } FINDEX_INFO_پوړونه_2;

  تعريفنوع تعداد FINDEX_پلټنه_OPS {
    پیدا_کړه_Ex_پلټنه_Name_سمون,پیدا_کړه_Ex_پلټنه_حد_منزل_Directories,پیدا_کړه_Ex_پلټنه_حد_منزل_Devices,پیدا_کړه_Ex_پلټنه_Max_پلټنه_Op
  } FINDEX_پلټنه_OPS_2;

#تعریف_کړه پیدا_کړه_لومړی_EX_CASE_SENSITIVE 0x1

#که_تعریف_شوی UNICODE
#تعریف_کړه پیدا_کړه_لومړی_File_Ex پیدا_کړه_لومړی_File_Ex_W
#تعریف_کړه پیدا_کړه_لومړی_File پیدا_کړه_لومړی_File_W
#تعریف_کړه پیدا_کړه_بل_File پیدا_کړه_بل_File_W
#تعریف_کړه پلټنه_لار پلټنه_لار_W
#تعریف_کړه CopyFile CopyFileW
#تعریف_کړه CopyFileEx CopyFileExW
#تعریف_کړه MoveFile MoveFileW
#تعریف_کړه MoveFileEx MoveFileExW
#تعریف_کړه Move_File_With_پرمختګ Move_File_With_پرمختګ_W
#تعریف_کړه ReplaceFile ReplaceFileW
#تعریف_کړه CreateHardLink CreateHardLinkW
#تعریف_کړه CreateNamedPipe CreateNamedPipeW
#تعریف_کړه GetNamedPipeHandleState GetNamedPipeHandleStateW
#تعریف_کړه CallNamedPipe CallNamedPipeW
#تعریف_کړه WaitNamedPipe WaitNamedPipeW
#تعریف_کړه سېټ_Volume_Label سېټ_Volume_Label_W
#تعریف_کړه GetVolumeInformation GetVolumeInformationW
#تعریف_کړه ClearEventLog ClearEventLogW
#تعریف_کړه BackupEventLog BackupEventLogW
#تعریف_کړه OpenEventLog OpenEventLogW
#تعریف_کړه ثبتوونکی_Event_سرچینه ثبتوونکی_Event_سرچینه_W
#تعریف_کړه OpenBackupEventLog OpenBackupEventLogW
#تعریف_کړه ReadEventLog ReadEventLogW
#تعریف_کړه ReportEvent ReportEventW
#تعریف_کړه AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#تعریف_کړه AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#تعریف_کړه Access_Check_By_Type_پایله_List_And_Audit_Alarm Access_Check_By_Type_پایله_List_And_Audit_Alarm_W
#تعریف_کړه Access_Check_By_Type_پایله_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_پایله_List_And_Audit_Alarm_By_Handle_W
#تعریف_کړه ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#تعریف_کړه ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#تعریف_کړه ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#تعریف_کړه ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#تعریف_کړه PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#تعریف_کړه سېټ_File_Security سېټ_File_Security_W
#تعریف_کړه GetFileSecurity GetFileSecurityW
#تعریف_کړه پیدا_کړه_لومړی_Change_Notification پیدا_کړه_لومړی_Change_Notification_W
#تعریف_کړه IsBadStringPtr IsBadStringPtrW
#تعریف_کړه LookupAccountSid LookupAccountSidW
#تعریف_کړه LookupAccountName LookupAccountNameW
#تعریف_کړه Lookup_Privilege_ارزښت Lookup_Privilege_ارزښت_W
#تعریف_کړه LookupPrivilegeName LookupPrivilegeNameW
#تعریف_کړه LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#تعریف_کړه BuildCommDCB BuildCommDCBW
#تعریف_کړه BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#تعریف_کړه CommConfigDialog CommConfigDialogW
#تعریف_کړه GetDefaultCommConfig GetDefaultCommConfigW
#تعریف_کړه سېټ_Default_Comm_Config سېټ_Default_Comm_Config_W
#تعریف_کړه GetComputerName GetComputerNameW
#تعریف_کړه سېټ_Computer_Name سېټ_Computer_Name_W
#تعریف_کړه GetComputerNameEx GetComputerNameExW
#تعریف_کړه سېټ_Computer_Name_Ex سېټ_Computer_Name_Ex_W
#تعریف_کړه Dns_Hostname_منزل_Computer_Name Dns_Hostname_منزل_Computer_Name_W
#تعریف_کړه GetUserName GetUserNameW
#وإلا
#تعریف_کړه پیدا_کړه_لومړی_File_Ex پیدا_کړه_لومړی_File_Ex_A
#تعریف_کړه پیدا_کړه_لومړی_File پیدا_کړه_لومړی_File_A
#تعریف_کړه پیدا_کړه_بل_File پیدا_کړه_بل_File_A
#تعریف_کړه پلټنه_لار پلټنه_لار_A
#تعریف_کړه CopyFile CopyFileA
#تعریف_کړه CopyFileEx CopyFileExA
#تعریف_کړه MoveFile MoveFileA
#تعریف_کړه MoveFileEx MoveFileExA
#تعریف_کړه Move_File_With_پرمختګ Move_File_With_پرمختګ_A
#تعریف_کړه ReplaceFile ReplaceFileA
#تعریف_کړه CreateHardLink CreateHardLinkA
#تعریف_کړه CreateNamedPipe CreateNamedPipeA
#تعریف_کړه GetNamedPipeHandleState GetNamedPipeHandleStateA
#تعریف_کړه CallNamedPipe CallNamedPipeA
#تعریف_کړه WaitNamedPipe WaitNamedPipeA
#تعریف_کړه سېټ_Volume_Label سېټ_Volume_Label_A
#تعریف_کړه GetVolumeInformation GetVolumeInformationA
#تعریف_کړه ClearEventLog ClearEventLogA
#تعریف_کړه BackupEventLog BackupEventLogA
#تعریف_کړه OpenEventLog OpenEventLogA
#تعریف_کړه ثبتوونکی_Event_سرچینه ثبتوونکی_Event_سرچینه_A
#تعریف_کړه OpenBackupEventLog OpenBackupEventLogA
#تعریف_کړه ReadEventLog ReadEventLogA
#تعریف_کړه ReportEvent ReportEventA
#تعریف_کړه AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#تعریف_کړه AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#تعریف_کړه Access_Check_By_Type_پایله_List_And_Audit_Alarm Access_Check_By_Type_پایله_List_And_Audit_Alarm_A
#تعریف_کړه Access_Check_By_Type_پایله_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_پایله_List_And_Audit_Alarm_By_Handle_A
#تعریف_کړه ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#تعریف_کړه ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#تعریف_کړه ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#تعریف_کړه ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#تعریف_کړه PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#تعریف_کړه سېټ_File_Security سېټ_File_Security_A
#تعریف_کړه GetFileSecurity GetFileSecurityA
#تعریف_کړه پیدا_کړه_لومړی_Change_Notification پیدا_کړه_لومړی_Change_Notification_A
#تعریف_کړه IsBadStringPtr IsBadStringPtrA
#تعریف_کړه LookupAccountSid LookupAccountSidA
#تعریف_کړه LookupAccountName LookupAccountNameA
#تعریف_کړه Lookup_Privilege_ارزښت Lookup_Privilege_ارزښت_A
#تعریف_کړه LookupPrivilegeName LookupPrivilegeNameA
#تعریف_کړه LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#تعریف_کړه BuildCommDCB BuildCommDCBA
#تعریف_کړه BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#تعریف_کړه CommConfigDialog CommConfigDialogA
#تعریف_کړه GetDefaultCommConfig GetDefaultCommConfigA
#تعریف_کړه سېټ_Default_Comm_Config سېټ_Default_Comm_Config_A
#تعریف_کړه GetComputerName GetComputerNameA
#تعریف_کړه سېټ_Computer_Name سېټ_Computer_Name_A
#تعریف_کړه GetComputerNameEx GetComputerNameExA
#تعریف_کړه سېټ_Computer_Name_Ex سېټ_Computer_Name_Ex_A
#تعریف_کړه Dns_Hostname_منزل_Computer_Name Dns_Hostname_منزل_Computer_Name_A
#تعریف_کړه GetUserName GetUserNameA
#د_که_پای

  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_File_Ex_A(LPCSTR lpFileName,FINDEX_INFO_پوړونه_2 fInfoLevelId,LPVOID lp_پیدا_کړه_File_معلومات,FINDEX_پلټنه_OPS_2 f_پلټنه_Op,LPVOID lp_پلټنه_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_File_Ex_W(LPCWSTR lpFileName,FINDEX_INFO_پوړونه_2 fInfoLevelId,LPVOID lp_پیدا_کړه_File_معلومات,FINDEX_پلټنه_OPS_2 f_پلټنه_Op,LPVOID lp_پلټنه_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_File_A(LPCSTR lpFileName,LPWIN32_پیدا_کړه_DATAA lp_پیدا_کړه_File_معلومات);
  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_File_W(LPCWSTR lpFileName,LPWIN32_پیدا_کړه_DATAW lp_پیدا_کړه_File_معلومات);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_بل_File_A(HANDLE h_پیدا_کړه_File,LPWIN32_پیدا_کړه_DATAA lp_پیدا_کړه_File_معلومات);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_بل_File_W(HANDLE h_پیدا_کړه_File,LPWIN32_پیدا_کړه_DATAW lp_پیدا_کړه_File_معلومات);
  WINBASEAPI DWORD WINAPI پلټنه_لار_A(LPCSTR lp_لار,LPCSTR lpFileName,LPCSTR lpExtension,DWORD n_بفر_اوږدتیا,LPSTR lp_بفر,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI پلټنه_لار_W(LPCWSTR lp_لار,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD n_بفر_اوږدتیا,LPWSTR lp_بفر,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  تعريفنوع DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER ټول_File_اندازه,LARGE_INTEGER ټول_بایټونه_Transferred,LARGE_INTEGER بهیر_اندازه,LARGE_INTEGER بهیر_بایټونه_Transferred,DWORD dw_بهیر_شمېره,DWORD dwCallbackReason,HANDLE h_سرچینه_File,HANDLE hDestinationFile,LPVOID lp_معلومات);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پرمختګ_Routine,LPVOID lp_معلومات,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پرمختګ_Routine,LPVOID lp_معلومات,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_پرمختګ_A(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پرمختګ_Routine,LPVOID lp_معلومات,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_پرمختګ_W(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پرمختګ_Routine,LPVOID lp_معلومات,DWORD dwFlags);

#تعریف_کړه MOVEFILE_REPLACE_EXISTING 0x1
#تعریف_کړه MOVEFILE_COPY_ALLOWED 0x2
#تعریف_کړه MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#تعریف_کړه MOVEFILE_WRITE_THROUGH 0x8
#تعریف_کړه MOVEFILE_CREATE_HARDLINK 0x10
#تعریف_کړه MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);

  تعريفنوع تعداد بهیر_INFO_پوړونه {
    پیدا_کړه_بهیر_Info_Standard,پیدا_کړه_بهیر_Info_Max_Info_Level
  } بهیر_INFO_پوړونه_2;

  تعريفنوع بنية WIN32_پیدا_کړه_بهیر_معلومات {
    LARGE_INTEGER بهیر_اندازه;
    WCHAR c_بهیر_Name[MAX_لار + 36];
  } WIN32_پیدا_کړه_بهیر_معلومات_2,*PWIN32_پیدا_کړه_بهیر_معلومات;

  HANDLE WINAPI پیدا_کړه_لومړی_بهیر_W(LPCWSTR lpFileName,بهیر_INFO_پوړونه_2 InfoLevel,LPVOID lp_پیدا_کړه_بهیر_معلومات,DWORD dwFlags);
  WINBOOL WINAPI پیدا_کړه_بل_بهیر_W(HANDLE h_پیدا_کړه_بهیر,LPVOID lp_پیدا_کړه_بهیر_معلومات);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dw_Open_ډېرپېښ,DWORD dw_Pipe_ډېرپېښ,DWORD nMaxInstances,DWORD n_بهر_بفر_اندازه,DWORD n_دننه_بفر_اندازه,DWORD n_Default_وخت_بهر,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dw_Open_ډېرپېښ,DWORD dw_Pipe_ډېرپېښ,DWORD nMaxInstances,DWORD n_بهر_بفر_اندازه,DWORD n_دننه_بفر_اندازه,DWORD n_Default_وخت_بهر,LPSECURITY_ځانګړتیاوې lp_Security_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_شمېر,LPDWORD lp_Collect_معلومات_Timeout,LPSTR lpUserName,DWORD n_Max_User_Name_اندازه);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_شمېر,LPDWORD lp_Collect_معلومات_Timeout,LPWSTR lpUserName,DWORD n_Max_User_Name_اندازه);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lp_دننه_بفر,DWORD n_دننه_بفر_اندازه,LPVOID lp_بهر_بفر,DWORD n_بهر_بفر_اندازه,LPDWORD lp_بایټونه_Read,DWORD n_وخت_بهر);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lp_دننه_بفر,DWORD n_دننه_بفر_اندازه,LPVOID lp_بهر_بفر,DWORD n_بهر_بفر_اندازه,LPDWORD lp_بایټونه_Read,DWORD n_وخت_بهر);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD n_وخت_بهر);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD n_وخت_بهر);
  WINBASEAPI WINBOOL WINAPI سېټ_Volume_Label_A(LPCSTR lp_ریښه_لار_Name,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI سېټ_Volume_Label_W(LPCWSTR lp_ریښه_لار_Name,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI سېټ_File_Apis_منزل_OEM(VOID);
  WINBASEAPI VOID WINAPI سېټ_File_Apis_منزل_ANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lp_ریښه_لار_Name,LPSTR lp_Volume_Name_بفر,DWORD n_Volume_Name_اندازه,LPDWORD lp_Volume_Serial_شمېره,LPDWORD lp_اعظمي_Component_اوږدتیا,LPDWORD lpFileSystemFlags,LPSTR lp_File_System_Name_بفر,DWORD n_File_System_Name_اندازه);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lp_ریښه_لار_Name,LPWSTR lp_Volume_Name_بفر,DWORD n_Volume_Name_اندازه,LPDWORD lp_Volume_Serial_شمېره,LPDWORD lp_اعظمي_Component_اوږدتیا,LPDWORD lpFileSystemFlags,LPWSTR lp_File_System_Name_بفر,DWORD n_File_System_Name_اندازه);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI Deregister_Event_سرچینه(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI Get_شمېره_د_Event_Log_ریکارډونه(HANDLE hEventLog,PDWORD شمېره_د_ریکارډونه);
  WINADVAPI WINBOOL WINAPI Get_Oldest_Event_Log_ریکارډ(HANDLE hEventLog,PDWORD Oldest_ریکارډ);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lp_سرچینه_Name);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lp_سرچینه_Name);
  WINADVAPI HANDLE WINAPI ثبتوونکی_Event_سرچینه_A(LPCSTR lpUNCServerName,LPCSTR lp_سرچینه_Name);
  WINADVAPI HANDLE WINAPI ثبتوونکی_Event_سرچینه_W(LPCWSTR lpUNCServerName,LPCWSTR lp_سرچینه_Name);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_ریکارډ_دننه_واټن,LPVOID lp_بفر,DWORD n_شمېره_د_بایټونه_منزل_Read,DWORD *pn_بایټونه_Read,DWORD *pn_Min_شمېره_د_بایټونه_Needed);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_ریکارډ_دننه_واټن,LPVOID lp_بفر,DWORD n_شمېره_د_بایټونه_منزل_Read,DWORD *pn_بایټونه_Read,DWORD *pn_Min_شمېره_د_بایټونه_Needed);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,کلمه_3 wType,کلمه_3 wCategory,DWORD dwEventID,PSID lpUserSid,کلمه_3 w_عدد_مزي_ګانې,DWORD dw_معلومات_اندازه,LPCSTR *lp_مزي_ګانې,LPVOID lp_Raw_معلومات);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,کلمه_3 wType,کلمه_3 wCategory,DWORD dwEventID,PSID lpUserSid,کلمه_3 w_عدد_مزي_ګانې,DWORD dw_معلومات_اندازه,LPCWSTR *lp_مزي_ګانې,LPVOID lp_Raw_معلومات);

#تعریف_کړه EVENTLOG_ډک_INFO 0

  تعريفنوع بنية EVENTLOG_ډک_INFORMATION {
    DWORD dw_ډک;
  } EVENTLOG_ډک_INFORMATION_2,*LPEVENTLOG_ډک_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lp_بفر,DWORD cb_Buf_اندازه,LPDWORD pcb_بایټونه_Needed);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_اوږدتیا,LPDWORD lpn_اوږدتیا_Needed);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI Revert_منزل_Self(VOID);
  WINADVAPI WINBOOL WINAPI سېټ_Thread_Token (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_سېټ Privilege_سېټ,LPDWORD Privilege_سېټ_اوږدتیا,LPDWORD GrantedAccess,LPBOOL Access_حالت);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_اوږدتیا,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_سېټ Privilege_سېټ,LPDWORD Privilege_سېټ_اوږدتیا,LPDWORD GrantedAccess,LPBOOL Access_حالت);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_پایله_List(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_اوږدتیا,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_سېټ Privilege_سېټ,LPDWORD Privilege_سېټ_اوږدتیا,LPDWORD GrantedAccessList,LPDWORD Access_حالت_List);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_اوږدتیا,PDWORD Return_اوږدتیا);
  WINADVAPI WINBOOL WINAPI سېټ_Token_Information(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_اوږدتیا);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD بفر_اوږدتیا,PTOKEN_PRIVILEGES پخوانی_State,PDWORD Return_اوږدتیا);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL Reset_منزل_Default,PTOKEN_GROUPS NewState,DWORD بفر_اوږدتیا,PTOKEN_GROUPS پخوانی_State,PDWORD Return_اوږدتیا);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_سېټ RequiredPrivileges,LPBOOL pf_پایله);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_اوږدتیا,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_اوږدتیا,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_پایله_List_And_Audit_Alarm_A(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_اوږدتیا,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_پایله_List_And_Audit_Alarm_W(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_اوږدتیا,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_پایله_List_And_Audit_Alarm_By_Handle_A(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_اوږدتیا,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_پایله_List_And_Audit_Alarm_By_Handle_W(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_اوږدتیا,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_سېټ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_سېټ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_سېټ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_سېټ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_سېټ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_سېټ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI Is_Well_معلوم_Sid(PSID pSid,WELL_معلوم_SID_TYPE Well_معلوم_Sid_Type);
  WINADVAPI WINBOOL WINAPI Create_Well_معلوم_Sid(WELL_معلوم_SID_TYPE Well_معلوم_Sid_Type,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI Equal_مختاړی_Sid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI Get_Sid_اوږدتیا_Required (UCHAR n_Sub_Authority_شمېر);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_شمېر,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_شمېر);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI Get_Sid_Sub_Authority_شمېر(PSID pSid);
  WINADVAPI DWORD WINAPI Get_اوږدتیا_Sid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD n_Destination_Sid_اوږدتیا,PSID pDestinationSid,PSID p_سرچینه_Sid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI Map_Generic_ماسک(PDWORD Access_ماسک,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD n_Acl_اوږدتیا,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_اوږدتیا,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI سېټ_Acl_Information(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_اوږدتیا,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Starting_Ace_شاخص,LPVOID pAceList,DWORD n_Ace_List_اوږدتیا);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dw_Ace_شاخص);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dw_Ace_شاخص,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Access_Allowed_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ماسک,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Access_Allowed_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Access_Denied_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ماسک,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Access_Denied_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Audit_Access_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Access_ماسک,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Audit_Access_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dw_Access_ماسک,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Access_Allowed_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Access_Denied_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کړه_Audit_Access_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI پیدا_کړه_لومړی_Free_Ace(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI Get_Security_Descriptor_اوږدتیا(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI سېټ_Security_Descriptor_Control(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL Control_بټونه_د_Interest,SECURITY_DESCRIPTOR_CONTROL Control_بټونه_منزل_سېټ);
  WINADVAPI WINBOOL WINAPI سېټ_Security_Descriptor_Dacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI سېټ_Security_Descriptor_Sacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI سېټ_Security_Descriptor_Owner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI سېټ_Security_Descriptor_ډله(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID p_ډله,WINBOOL b_ډله_Defaulted);
  WINADVAPI WINBOOL WINAPI Get_Security_Descriptor_ډله(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *p_ډله,LPBOOL lpb_ډله_Defaulted);
  WINADVAPI DWORD WINAPI سېټ_Security_Descriptor_RMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI Create_شخصي_Object_Security(PSECURITY_DESCRIPTOR پلار_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Convert_منزل_Auto_Inherit_شخصي_Object_Security(PSECURITY_DESCRIPTOR پلار_Descriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_شخصي_Object_Security_Ex(PSECURITY_DESCRIPTOR پلار_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_شخصي_Object_Security_With_مضرب_Inheritance(PSECURITY_DESCRIPTOR پلار_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG Guid_شمېر,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI سېټ_شخصي_Object_Security (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI سېټ_شخصي_Object_Security_Ex (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI Get_شخصي_Object_Security(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD Descriptor_اوږدتیا,PDWORD Return_اوږدتیا);
  WINADVAPI WINBOOL WINAPI Destroy_شخصي_Object_Security(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_بفر_اوږدتیا);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdw_Absolute_Security_Descriptor_اندازه,PACL pDacl,LPDWORD lpdw_Dacl_اندازه,PACL pSacl,LPDWORD lpdw_Sacl_اندازه,PSID pOwner,LPDWORD lpdw_Owner_اندازه,PSID p_Primary_ډله,LPDWORD lpdw_Primary_ډله_اندازه);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_بفر_اندازه);
  WINADVAPI WINBOOL WINAPI سېټ_File_Security_A(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI سېټ_File_Security_W(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_اوږدتیا,LPDWORD lpn_اوږدتیا_Needed);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_اوږدتیا,LPDWORD lpn_اوږدتیا_Needed);
  WINADVAPI WINBOOL WINAPI سېټ_Kernel_Object_Security(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_Change_Notification_A(LPCSTR lp_لار_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_Change_Notification_W(LPCWSTR lp_لار_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_بل_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_Close_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lp_بفر,DWORD n_بفر_اوږدتیا,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lp_بایټونه_Returned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI Virtual_قلف(LPVOID lp_پته,اندازه_T dw_اندازه);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lp_پته,اندازه_T dw_اندازه);
  WINBASEAPI LPVOID WINAPI Map_View_د_File_Ex(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_دننه_واټن_لوړ,DWORD dw_File_دننه_واټن_ټیټ,اندازه_T dw_شمېره_د_بایټونه_منزل_Map,LPVOID lp_بنسټ_پته);
  WINBASEAPI WINBOOL WINAPI سېټ_لومړیتوب_Class(HANDLE hProcess,DWORD dw_لومړیتوب_Class);
  WINBASEAPI DWORD WINAPI Get_لومړیتوب_Class(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI Is_Bad_کوډ_Ptr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_ارزښت_A(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_ارزښت_W(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
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
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_اندازه);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Default_Comm_Config_A(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Default_Comm_Config_W(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_اندازه);

#تعریف_کړه MAX_COMPUTERNAME_اوږدتیا 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lp_بفر,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lp_بفر,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Computer_Name_A(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI سېټ_Computer_Name_W(LPCWSTR lpComputerName);

  تعريفنوع تعداد _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lp_بفر,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lp_بفر,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Computer_Name_Ex_A(COMPUTER_NAME_FORMAT NameType,LPCSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI سېټ_Computer_Name_Ex_W(COMPUTER_NAME_FORMAT NameType,LPCWSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_منزل_Computer_Name_A(LPCSTR Hostname,LPSTR ComputerName,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_منزل_Computer_Name_W(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD n_اندازه);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lp_بفر,LPDWORD pcb_بفر);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lp_بفر,LPDWORD pcb_بفر);

#تعریف_کړه LOGON32_LOGON_INTERACTIVE 2
#تعریف_کړه LOGON32_LOGON_شبکه 3
#تعریف_کړه LOGON32_LOGON_BATCH 4
#تعریف_کړه LOGON32_LOGON_SERVICE 5
#تعریف_کړه LOGON32_LOGON_UNLOCK 7
#تعریف_کړه LOGON32_LOGON_شبکه_CLEARTEXT 8
#تعریف_کړه LOGON32_LOGON_NEW_CREDENTIALS 9

#تعریف_کړه LOGON32_PROVIDER_DEFAULT 0
#تعریف_کړه LOGON32_PROVIDER_WINNT35 1
#تعریف_کړه LOGON32_PROVIDER_WINNT40 2
#تعریف_کړه LOGON32_PROVIDER_WINNT50 3

#که_تعریف_شوی UNICODE
#تعریف_کړه LogonUser LogonUserW
#تعریف_کړه LogonUserEx LogonUserExW
#تعریف_کړه CreateProcessAsUser CreateProcessAsUserW
#وإلا
#تعریف_کړه LogonUser LogonUserA
#تعریف_کړه LogonUserEx LogonUserExA
#تعریف_کړه CreateProcessAsUser CreateProcessAsUserA
#د_که_پای

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_بفر,LPDWORD pdw_Profile_اوږدتیا,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_بفر,LPDWORD pdw_Profile_اوږدتیا,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lp_Command_کرښه,LPSECURITY_ځانګړتیاوې lp_Process_ځانګړتیاوې,LPSECURITY_ځانګړتیاوې lp_Thread_ځانګړتیاوې,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lp_Command_کرښه,LPSECURITY_ځانګړتیاوې lp_Process_ځانګړتیاوې,LPSECURITY_ځانګړتیاوې lp_Thread_ځانګړتیاوې,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#تعریف_کړه LOGON_WITH_PROFILE 0x1
#تعریف_کړه LOGON_NETCREDENTIALS_ONLY 0x2
#تعریف_کړه LOGON_ZERO_PASSWORD_بفر 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_کرښه,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_کرښه,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_ځانګړتیاوې lp_Token_ځانګړتیاوې,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD Disable_Sid_شمېر,PSID_AND_ځانګړتیاوې Sids_منزل_Disable,DWORD Delete_Privilege_شمېر,PLUID_AND_ځانګړتیاوې Privileges_منزل_Delete,DWORD Restricted_Sid_شمېر,PSID_AND_ځانګړتیاوې Sids_منزل_Restrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID Sid_منزل_Check,PBOOL IsMember);

  تعريفنوع WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI ثبتوونکی_Wait_For_Single_Object(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI ثبتوونکی_Wait_For_Single_Object_Ex(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI کتار_User_Work_توکی(LPTHREAD_پیل_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI Create_Timer_کتار(VOID);
  WINBASEAPI WINBOOL WINAPI Create_Timer_کتار_Timer(PHANDLE phNewTimer,HANDLE Timer_کتار,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_وخت,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI Change_Timer_کتار_Timer(HANDLE Timer_کتار,HANDLE Timer,ULONG Due_وخت,ULONG Period);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_کتار_Timer(HANDLE Timer_کتار,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_کتار_Ex(HANDLE Timer_کتار,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI سېټ_Timer_کتار_Timer(HANDLE Timer_کتار,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_وخت,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI Cancel_Timer_کتار_Timer(HANDLE Timer_کتار,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_کتار(HANDLE Timer_کتار);

#تعریف_کړه HW_PROFILE_GUIDLEN 39
#تعریف_کړه MAX_PROFILE_LEN 80

#تعریف_کړه DOCKINFO_UNDOCKED (0x1)
#تعریف_کړه DOCKINFO_DOCKED (0x2)
#تعریف_کړه DOCKINFO_USER_SUPPLIED (0x4)
#تعریف_کړه DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#تعریف_کړه DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  تعريفنوع بنية نښان_HW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  تعريفنوع بنية نښان_HW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#که_تعریف_شوی UNICODE
  تعريفنوع HW_PROFILE_INFOW HW_PROFILE_INFO;
  تعريفنوع LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#وإلا
  تعريفنوع HW_PROFILE_INFOA HW_PROFILE_INFO;
  تعريفنوع LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه GetCurrentHwProfile GetCurrentHwProfileW
#تعریف_کړه Get_نسخه_Ex Get_نسخه_Ex_W
#تعریف_کړه Verify_نسخه_Info Verify_نسخه_Info_W
#وإلا
#تعریف_کړه GetCurrentHwProfile GetCurrentHwProfileA
#تعریف_کړه Get_نسخه_Ex Get_نسخه_Ex_A
#تعریف_کړه Verify_نسخه_Info Verify_نسخه_Info_A
#د_که_پای

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lp_Performance_شمېر);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI Get_نسخه_Ex_A(LPOSVERSIONINFOA lp_نسخه_Information);
  WINBASEAPI WINBOOL WINAPI Get_نسخه_Ex_W(LPOSVERSIONINFOW lp_نسخه_Information);
  WINBASEAPI WINBOOL WINAPI Verify_نسخه_Info_A(LPOSVERSIONINFOEXA lp_نسخه_Information,DWORD dw_Type_ماسک,DWORDLONG dwl_Condition_ماسک);
  WINBASEAPI WINBOOL WINAPI Verify_نسخه_Info_W(LPOSVERSIONINFOEXW lp_نسخه_Information,DWORD dw_Type_ماسک,DWORDLONG dwl_Condition_ماسک);

#ضمن <winerror.h>

#تعریف_کړه TC_نورمال 0
#تعریف_کړه TC_HARDERR 1
#تعریف_کړه TC_GP_TRAP 2
#تعریف_کړه TC_SIGNAL 3

#تعریف_کړه AC_کرښه_OFFLINE 0x0
#تعریف_کړه AC_کرښه_ONLINE 0x1
#تعریف_کړه AC_کرښه_BACKUP_POWER 0x2
#تعریف_کړه AC_کرښه_UNKNOWN 0xff

#تعریف_کړه BATTERY_FLAG_لوړ 0x1
#تعریف_کړه BATTERY_FLAG_ټیټ 0x2
#تعریف_کړه BATTERY_FLAG_CRITICAL 0x4
#تعریف_کړه BATTERY_FLAG_CHARGING 0x8
#تعریف_کړه BATTERY_FLAG_NO_BATTERY 0x80
#تعریف_کړه BATTERY_FLAG_UNKNOWN 0xff

#تعریف_کړه BATTERY_PERCENTAGE_UNKNOWN 0xff

#تعریف_کړه BATTERY_LIFE_UNKNOWN 0xffffffff

  تعريفنوع بنية SYSTEM_POWER_حالت {
    BYTE ACLine_حالت;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD Battery_Life_وخت;
    DWORD Battery_ډک_Life_وخت;
  } SYSTEM_POWER_حالت_2,*LPSYSTEM_POWER_حالت;

#که_تعریف_شوی UNICODE
#تعریف_کړه Create_دنده_Object Create_دنده_Object_W
#تعریف_کړه Open_دنده_Object Open_دنده_Object_W
#تعریف_کړه پیدا_کړه_لومړی_Volume پیدا_کړه_لومړی_Volume_W
#تعریف_کړه پیدا_کړه_بل_Volume پیدا_کړه_بل_Volume_W
#تعریف_کړه پیدا_کړه_لومړی_Volume_Mount_ټکی پیدا_کړه_لومړی_Volume_Mount_ټکی_W
#تعریف_کړه پیدا_کړه_بل_Volume_Mount_ټکی پیدا_کړه_بل_Volume_Mount_ټکی_W
#تعریف_کړه سېټ_Volume_Mount_ټکی سېټ_Volume_Mount_ټکی_W
#تعریف_کړه Delete_Volume_Mount_ټکی Delete_Volume_Mount_ټکی_W
#تعریف_کړه Get_Volume_Name_For_Volume_Mount_ټکی Get_Volume_Name_For_Volume_Mount_ټکی_W
#تعریف_کړه Get_Volume_لار_Name Get_Volume_لار_Name_W
#تعریف_کړه Get_Volume_لار_نومونه_For_Volume_Name Get_Volume_لار_نومونه_For_Volume_Name_W
#وإلا
#تعریف_کړه Create_دنده_Object Create_دنده_Object_A
#تعریف_کړه Open_دنده_Object Open_دنده_Object_A
#تعریف_کړه پیدا_کړه_لومړی_Volume پیدا_کړه_لومړی_Volume_A
#تعریف_کړه پیدا_کړه_بل_Volume پیدا_کړه_بل_Volume_A
#تعریف_کړه پیدا_کړه_لومړی_Volume_Mount_ټکی پیدا_کړه_لومړی_Volume_Mount_ټکی_A
#تعریف_کړه پیدا_کړه_بل_Volume_Mount_ټکی پیدا_کړه_بل_Volume_Mount_ټکی_A
#تعریف_کړه سېټ_Volume_Mount_ټکی سېټ_Volume_Mount_ټکی_A
#تعریف_کړه Delete_Volume_Mount_ټکی Delete_Volume_Mount_ټکی_A
#تعریف_کړه Get_Volume_Name_For_Volume_Mount_ټکی Get_Volume_Name_For_Volume_Mount_ټکی_A
#تعریف_کړه Get_Volume_لار_Name Get_Volume_لار_Name_A
#تعریف_کړه Get_Volume_لار_نومونه_For_Volume_Name Get_Volume_لار_نومونه_For_Volume_Name_A
#د_که_پای

  WINBOOL WINAPI Get_System_Power_حالت(LPSYSTEM_POWER_حالت lp_System_Power_حالت);
  WINBOOL WINAPI سېټ_System_Power_State(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI Allocate_User_Physical_پاڼې(HANDLE hProcess,PULONG_PTR شمېره_د_پاڼې,PULONG_PTR پاڼه_Array);
  WINBASEAPI WINBOOL WINAPI Free_User_Physical_پاڼې(HANDLE hProcess,PULONG_PTR شمېره_د_پاڼې,PULONG_PTR پاڼه_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_پاڼې(PVOID Virtual_پته,ULONG_PTR شمېره_د_پاڼې,PULONG_PTR پاڼه_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_پاڼې_Scatter(PVOID *Virtual_پتې,ULONG_PTR شمېره_د_پاڼې,PULONG_PTR پاڼه_Array);
  WINBASEAPI HANDLE WINAPI Create_دنده_Object_A(LPSECURITY_ځانګړتیاوې lp_دنده_ځانګړتیاوې,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Create_دنده_Object_W(LPSECURITY_ځانګړتیاوې lp_دنده_ځانګړتیاوې,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_دنده_Object_A(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_دنده_Object_W(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI ټاکل_Process_منزل_دنده_Object(HANDLE h_دنده,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI Terminate_دنده_Object(HANDLE h_دنده,UINT u_Exit_کوډ);
  WINBASEAPI WINBOOL WINAPI Query_Information_دنده_Object(HANDLE h_دنده,JOBOBJECTINFOCLASS دنده_Object_Information_Class,LPVOID lp_دنده_Object_Information,DWORD cb_دنده_Object_Information_اوږدتیا,LPDWORD lp_Return_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI سېټ_Information_دنده_Object(HANDLE h_دنده,JOBOBJECTINFOCLASS دنده_Object_Information_Class,LPVOID lp_دنده_Object_Information,DWORD cb_دنده_Object_Information_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI Is_Process_دننه_دنده(HANDLE ProcessHandle,HANDLE دنده_Handle,PBOOL پایله_3);
  WINBASEAPI WINBOOL WINAPI Create_دنده_سېټ(ULONG عدد_دنده,PJOB_سېټ_ARRAY User_دنده_سېټ,ULONG Flags);
  WINBASEAPI PVOID WINAPI جمع_کړه_Vectored_Exception_Handler (ULONG لومړی_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI جمع_کړه_Vectored_Continue_Handler (ULONG لومړی_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_Volume_A(LPSTR lpszVolumeName,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_Volume_W(LPWSTR lpszVolumeName,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_بل_Volume_A(HANDLE h_پیدا_کړه_Volume,LPSTR lpszVolumeName,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_بل_Volume_W(HANDLE h_پیدا_کړه_Volume,LPWSTR lpszVolumeName,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_Volume_Close(HANDLE h_پیدا_کړه_Volume);
  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_Volume_Mount_ټکی_A(LPCSTR lpsz_ریښه_لار_Name,LPSTR lpsz_Volume_Mount_ټکی,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI HANDLE WINAPI پیدا_کړه_لومړی_Volume_Mount_ټکی_W(LPCWSTR lpsz_ریښه_لار_Name,LPWSTR lpsz_Volume_Mount_ټکی,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_بل_Volume_Mount_ټکی_A(HANDLE h_پیدا_کړه_Volume_Mount_ټکی,LPSTR lpsz_Volume_Mount_ټکی,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_بل_Volume_Mount_ټکی_W(HANDLE h_پیدا_کړه_Volume_Mount_ټکی,LPWSTR lpsz_Volume_Mount_ټکی,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_Volume_Mount_ټکی_Close(HANDLE h_پیدا_کړه_Volume_Mount_ټکی);
  WINBASEAPI WINBOOL WINAPI سېټ_Volume_Mount_ټکی_A(LPCSTR lpsz_Volume_Mount_ټکی,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI سېټ_Volume_Mount_ټکی_W(LPCWSTR lpsz_Volume_Mount_ټکی,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_ټکی_A(LPCSTR lpsz_Volume_Mount_ټکی);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_ټکی_W(LPCWSTR lpsz_Volume_Mount_ټکی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_ټکی_A(LPCSTR lpsz_Volume_Mount_ټکی,LPSTR lpszVolumeName,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_ټکی_W(LPCWSTR lpsz_Volume_Mount_ټکی,LPWSTR lpszVolumeName,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI Get_Volume_لار_Name_A(LPCSTR lpszFileName,LPSTR lpsz_Volume_لار_Name,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI Get_Volume_لار_Name_W(LPCWSTR lpszFileName,LPWSTR lpsz_Volume_لار_Name,DWORD cch_بفر_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI Get_Volume_لار_نومونه_For_Volume_Name_A(LPCSTR lpszVolumeName,LPCH lpsz_Volume_لار_نومونه,DWORD cch_بفر_اوږدتیا,PDWORD lpcch_Return_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI Get_Volume_لار_نومونه_For_Volume_Name_W(LPCWSTR lpszVolumeName,LPWCH lpsz_Volume_لار_نومونه,DWORD cch_بفر_اوږدتیا,PDWORD lpcch_Return_اوږدتیا);

#تعریف_کړه ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#تعریف_کړه ACTCTX_FLAG_LANGID_VALID 0x2
#تعریف_کړه ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#تعریف_کړه ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#تعریف_کړه ACTCTX_FLAG_سېټ_PROCESS_DEFAULT 0x10
#تعریف_کړه ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#تعریف_کړه ACTCTX_FLAG_سرچینه_IS_ASSEMBLYREF 0x40
#تعریف_کړه ACTCTX_FLAG_HMODULE_VALID 0x80

  تعريفنوع بنية نښان_ACTCTXA {
    ULONG cb_اندازه;
    DWORD dwFlags;
    LPCSTR lp_سرچینه;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  تعريفنوع بنية نښان_ACTCTXW {
    ULONG cb_اندازه;
    DWORD dwFlags;
    LPCWSTR lp_سرچینه;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  تعريفنوع ثابت ACTCTXA *PCACTCTXA;
  تعريفنوع ثابت ACTCTXW *PCACTCTXW;

#که_تعریف_شوی UNICODE
  تعريفنوع ACTCTXW ACTCTX;
  تعريفنوع PACTCTXW PACTCTX;
  تعريفنوع PCACTCTXW PCACTCTX;
#وإلا
  تعريفنوع ACTCTXA ACTCTX;
  تعريفنوع PACTCTXA PACTCTX;
  تعريفنوع PCACTCTXA PCACTCTX;
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه CreateActCtx CreateActCtxW
#وإلا
#تعریف_کړه CreateActCtx CreateActCtxA
#د_که_پای

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI جمع_کړه_Ref_Act_Ctx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#تعریف_کړه DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  تعريفنوع بنية نښان_ACTCTX_SECTION_KEYED_معلومات_2600 {
    ULONG cb_اندازه;
    ULONG ul_معلومات_Format_نسخه;
    PVOID lp_معلومات;
    ULONG ul_اوږدتیا;
    PVOID lp_Section_Global_معلومات;
    ULONG ul_Section_Global_معلومات_اوږدتیا;
    PVOID lp_Section_بنسټ;
    ULONG ul_Section_ټول_اوږدتیا;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_شاخص;
  } ACTCTX_SECTION_KEYED_معلومات_2600,*PACTCTX_SECTION_KEYED_معلومات_2600;

  تعريفنوع ثابت ACTCTX_SECTION_KEYED_معلومات_2600 *PCACTCTX_SECTION_KEYED_معلومات_2600;

  تعريفنوع بنية نښان_ACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lp_Section_بنسټ;
    ULONG ul_Section_اوږدتیا;
    PVOID lp_Section_Global_معلومات_بنسټ;
    ULONG ul_Section_Global_معلومات_اوږدتیا;
  } ACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA;

  تعريفنوع ثابت ACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA;

  تعريفنوع بنية نښان_ACTCTX_SECTION_KEYED_معلومات {
    ULONG cb_اندازه;
    ULONG ul_معلومات_Format_نسخه;
    PVOID lp_معلومات;
    ULONG ul_اوږدتیا;
    PVOID lp_Section_Global_معلومات;
    ULONG ul_Section_Global_معلومات_اوږدتیا;
    PVOID lp_Section_بنسټ;
    ULONG ul_Section_ټول_اوږدتیا;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_شاخص;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_معلومات,*PACTCTX_SECTION_KEYED_معلومات;

  تعريفنوع ثابت ACTCTX_SECTION_KEYED_معلومات *PCACTCTX_SECTION_KEYED_معلومات;

#تعریف_کړه پیدا_کړه_ACTCTX_SECTION_کلی_RETURN_HACTCTX 0x1
#تعریف_کړه پیدا_کړه_ACTCTX_SECTION_کلی_RETURN_FLAGS 0x2
#تعریف_کړه پیدا_کړه_ACTCTX_SECTION_کلی_RETURN_ASSEMBLY_METADATA 0x4

#که_تعریف_شوی UNICODE
#تعریف_کړه پیدا_کړه_Act_Ctx_Section_String پیدا_کړه_Act_Ctx_Section_String_W
#وإلا
#تعریف_کړه پیدا_کړه_Act_Ctx_Section_String پیدا_کړه_Act_Ctx_Section_String_A
#د_که_پای

  WINBASEAPI WINBOOL WINAPI پیدا_کړه_Act_Ctx_Section_String_A(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lp_String_منزل_پیدا_کړه,PACTCTX_SECTION_KEYED_معلومات Returned_معلومات);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_Act_Ctx_Section_String_W(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lp_String_منزل_پیدا_کړه,PACTCTX_SECTION_KEYED_معلومات Returned_معلومات);
  WINBASEAPI WINBOOL WINAPI پیدا_کړه_Act_Ctx_Section_Guid(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,ثابت GUID *lp_Guid_منزل_پیدا_کړه,PACTCTX_SECTION_KEYED_معلومات Returned_معلومات);

#که_نه_تعریف_شوی RC_INVOKED
#که_نه_تعریف_شوی ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  تعريفنوع بنية _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  تعريفنوع ثابت بنية _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#تعریف_کړه ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#د_که_پای
#د_که_پای

#تعریف_کړه QUERY_ACTCTX_FLAG_USE_فعال_ACTCTX 0x4
#تعریف_کړه QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#تعریف_کړه QUERY_ACTCTX_FLAG_ACTCTX_IS_پته 0x10
#تعریف_کړه QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_بفر,اندازه_T cb_بفر,اندازه_T *pcbWrittenOrRequired);

  تعريفنوع WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_بفر,اندازه_T cb_بفر,اندازه_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI Process_Id_منزل_Session_Id(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGet_فعال_Console_Session_Id();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION بفر_3,PDWORD Returned_اوږدتیا);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Highest_غوټه_شمېره(PULONG Highest_غوټه_شمېره);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Processor_غوټه(UCHAR Processor,PUCHAR غوټه_شمېره);
  WINBASEAPI WINBOOL WINAPI Get_Numa_غوټه_Processor_ماسک(UCHAR غوټه_2,PULONGLONG Processor_ماسک);
  WINBASEAPI WINBOOL WINAPI Get_Numa_شته_حافظه_غوټه(UCHAR غوټه_2,PULONGLONG شته_بایټونه);

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
