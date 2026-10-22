/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _WINBASE_
#تعریف_کن _WINBASE_

#تعریف_کن WINADVAPI DECLSPEC_IMPORT
#تعریف_کن WINBASEAPI DECLSPEC_IMPORT
#تعریف_کن ZAWPROXYAPI DECLSPEC_IMPORT

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#تعریف_کن Define_Handle_جدول(w) ((w),TRUE)
#تعریف_کن حد_Ems_صفحات(dw)
#تعریف_کن مجموعه_جابجا_Area_اندازه(w) (w)
#تعریف_کن قفل_Segment(w) GlobalFix((HANDLE)(w))
#تعریف_کن UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#تعریف_کن Get_Current_زمان() Get_Tick_شمار()

#تعریف_کن Yield()

#تعریف_کن INVALID_HANDLE_مقدار ((HANDLE)(LONG_PTR)-1)
#تعریف_کن INVALID_FILE_اندازه ((DWORD)0xffffffff)
#تعریف_کن INVALID_مجموعه_FILE_اشاره_گر ((DWORD)-1)
#تعریف_کن INVALID_FILE_صفات ((DWORD)-1)

#تعریف_کن FILE_BEGIN 0
#تعریف_کن FILE_CURRENT 1
#تعریف_کن FILE_انتها 2

#تعریف_کن زمان_ZONE_ID_INVALID ((DWORD)0xffffffff)

#تعریف_کن WAIT_FAILED ((DWORD)0xffffffff)
#تعریف_کن WAIT_OBJECT_0 ((وضعیت_WAIT_0) + 0)
#تعریف_کن WAIT_ABANDONED ((وضعیت_ABANDONED_WAIT_0) + 0)
#تعریف_کن WAIT_ABANDONED_0 ((وضعیت_ABANDONED_WAIT_0) + 0)
#تعریف_کن WAIT_IO_COMPLETION وضعیت_USER_APC
#تعریف_کن STILL_فعال وضعیت_PENDING
#تعریف_کن EXCEPTION_ACCESS_VIOLATION وضعیت_ACCESS_VIOLATION
#تعریف_کن EXCEPTION_DATATYPE_MISALIGNMENT وضعیت_DATATYPE_MISALIGNMENT
#تعریف_کن EXCEPTION_BREAKPOINT وضعیت_BREAKPOINT
#تعریف_کن EXCEPTION_SINGLE_گام وضعیت_SINGLE_گام
#تعریف_کن EXCEPTION_ARRAY_BOUNDS_EXCEEDED وضعیت_ARRAY_BOUNDS_EXCEEDED
#تعریف_کن EXCEPTION_FLT_DENORMAL_عملوند وضعیت_FLOAT_DENORMAL_عملوند
#تعریف_کن EXCEPTION_FLT_DIVIDE_BY_ZERO وضعیت_FLOAT_DIVIDE_BY_ZERO
#تعریف_کن EXCEPTION_FLT_INEXACT_نتیجه وضعیت_FLOAT_INEXACT_نتیجه
#تعریف_کن EXCEPTION_FLT_INVALID_OPERATION وضعیت_FLOAT_INVALID_OPERATION
#تعریف_کن EXCEPTION_FLT_سرریز وضعیت_FLOAT_سرریز
#تعریف_کن EXCEPTION_FLT_پشته_CHECK وضعیت_FLOAT_پشته_CHECK
#تعریف_کن EXCEPTION_FLT_UNDERFLOW وضعیت_FLOAT_UNDERFLOW
#تعریف_کن EXCEPTION_INT_DIVIDE_BY_ZERO وضعیت_INTEGER_DIVIDE_BY_ZERO
#تعریف_کن EXCEPTION_INT_سرریز وضعیت_INTEGER_سرریز
#تعریف_کن EXCEPTION_PRIV_INSTRUCTION وضعیت_PRIVILEGED_INSTRUCTION
#تعریف_کن EXCEPTION_درون_صفحه_ERROR وضعیت_درون_صفحه_ERROR
#تعریف_کن EXCEPTION_ILLEGAL_INSTRUCTION وضعیت_ILLEGAL_INSTRUCTION
#تعریف_کن EXCEPTION_NONCONTINUABLE_EXCEPTION وضعیت_NONCONTINUABLE_EXCEPTION
#تعریف_کن EXCEPTION_پشته_سرریز وضعیت_پشته_سرریز
#تعریف_کن EXCEPTION_INVALID_DISPOSITION وضعیت_INVALID_DISPOSITION
#تعریف_کن EXCEPTION_GUARD_صفحه وضعیت_GUARD_صفحه_VIOLATION
#تعریف_کن EXCEPTION_INVALID_HANDLE وضعیت_INVALID_HANDLE
#تعریف_کن EXCEPTION_POSSIBLE_DEADLOCK وضعیت_POSSIBLE_DEADLOCK
#تعریف_کن CONTROL_C_EXIT وضعیت_CONTROL_C_EXIT
#تعریف_کن Move_حافظه Rtl_Move_حافظه
#تعریف_کن Copy_حافظه Rtl_Copy_حافظه
#تعریف_کن Fill_حافظه Rtl_Fill_حافظه
#تعریف_کن Zero_حافظه Rtl_Zero_حافظه
#تعریف_کن Secure_Zero_حافظه Rtl_Secure_Zero_حافظه

#تعریف_کن FILE_FLAG_WRITE_THROUGH 0x80000000
#تعریف_کن FILE_FLAG_OVERLAPPED 0x40000000
#تعریف_کن FILE_FLAG_NO_BUFFERING 0x20000000
#تعریف_کن FILE_FLAG_RANDOM_ACCESS 0x10000000
#تعریف_کن FILE_FLAG_SEQUENTIAL_پیمایش 0x8000000
#تعریف_کن FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#تعریف_کن FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#تعریف_کن FILE_FLAG_POSIX_SEMANTICS 0x1000000
#تعریف_کن FILE_FLAG_OPEN_REPARSE_نقطه 0x200000
#تعریف_کن FILE_FLAG_OPEN_NO_RECALL 0x100000
#تعریف_کن FILE_FLAG_اولی_PIPE_INSTANCE 0x80000

#تعریف_کن CREATE_NEW 1
#تعریف_کن CREATE_ALWAYS 2
#تعریف_کن OPEN_EXISTING 3
#تعریف_کن OPEN_ALWAYS 4
#تعریف_کن TRUNCATE_EXISTING 5

#تعریف_کن پیشرفت_CONTINUE 0
#تعریف_کن پیشرفت_CANCEL 1
#تعریف_کن پیشرفت_STOP 2
#تعریف_کن پیشرفت_QUIET 3

#تعریف_کن CALLBACK_CHUNK_پایانیافته 0x0
#تعریف_کن CALLBACK_جریان_SWITCH 0x1

#تعریف_کن COPY_FILE_FAIL_IF_EXISTS 0x1
#تعریف_کن COPY_FILE_RESTARTABLE 0x2
#تعریف_کن COPY_FILE_OPEN_منبع_FOR_WRITE 0x4
#تعریف_کن COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#تعریف_کن REPLACEFILE_WRITE_THROUGH 0x1
#تعریف_کن REPLACEFILE_IGNORE_ادغام_ERRORS 0x2

#تعریف_کن PIPE_ACCESS_INBOUND 0x1
#تعریف_کن PIPE_ACCESS_OUTBOUND 0x2
#تعریف_کن PIPE_ACCESS_DUPLEX 0x3

#تعریف_کن PIPE_CLIENT_انتها 0x0
#تعریف_کن PIPE_SERVER_انتها 0x1

#تعریف_کن PIPE_WAIT 0x0
#تعریف_کن PIPE_NOWAIT 0x1
#تعریف_کن PIPE_READMODE_BYTE 0x0
#تعریف_کن PIPE_READMODE_پیام 0x2
#تعریف_کن PIPE_TYPE_BYTE 0x0
#تعریف_کن PIPE_TYPE_پیام 0x4

#تعریف_کن PIPE_UNLIMITED_INSTANCES 255

#تعریف_کن SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#تعریف_کن SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#تعریف_کن SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#تعریف_کن SECURITY_DELEGATION (SecurityDelegation << 16)

#تعریف_کن SECURITY_CONTEXT_TRACKING 0x40000
#تعریف_کن SECURITY_EFFECTIVE_ONLY 0x80000

#تعریف_کن SECURITY_SQOS_PRESENT 0x100000
#تعریف_کن SECURITY_VALID_SQOS_FLAGS 0x1f0000

  تعريفنوع بنية _OVERLAPPED {
    ULONG_PTR داخلی;
    ULONG_PTR داخلی_بالا;
    اتحاد {
      بنية {
	DWORD جابه_جایی_3;
	DWORD جابه_جایی_بالا_2;
      };
      PVOID اشاره_گر_2;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  تعريفنوع بنية SECURITY_صفات {
    DWORD n_درازی;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_صفات_2,*PSECURITY_صفات,*LPSECURITY_صفات;

  تعريفنوع بنية _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#اگر_تعریف_نشده _FILETIME_
#تعریف_کن _FILETIME_
  تعريفنوع بنية _FILETIME {
    DWORD dw_کم_Date_زمان;
    DWORD dw_بالا_Date_زمان;
  } FILETIME,*PFILETIME,*LPFILETIME;
#پایان_اگر

  تعريفنوع بنية _SYSTEMTIME {
    کلمه_3 wYear;
    کلمه_3 wMonth;
    کلمه_3 w_Day_از_Week;
    کلمه_3 wDay;
    کلمه_3 wHour;
    کلمه_3 wMinute;
    کلمه_3 w_دومی;
    کلمه_3 wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  تعريفنوع DWORD (WINAPI *PTHREAD_شروع_ROUTINE)(LPVOID lpThreadParameter);
  تعريفنوع PTHREAD_شروع_ROUTINE LPTHREAD_شروع_ROUTINE;
  تعريفنوع VOID (WINAPI *PFIBER_شروع_ROUTINE)(LPVOID lpFiberParameter);
  تعريفنوع PFIBER_شروع_ROUTINE LPFIBER_شروع_ROUTINE;

  تعريفنوع RTL_CRITICAL_SECTION CRITICAL_SECTION;
  تعريفنوع PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  تعريفنوع PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  تعريفنوع RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  تعريفنوع PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  تعريفنوع PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI Encode_اشاره_گر(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_اشاره_گر(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Encode_System_اشاره_گر(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_System_اشاره_گر(PVOID Ptr);

#اگر_تعریف_شده I_X86_
  تعريفنوع PLDT_مدخل LPLDT_مدخل;
#وإلا
  تعريفنوع LPVOID LPLDT_مدخل;
#پایان_اگر

#تعریف_کن MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#تعریف_کن MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#تعریف_کن SP_SERIALCOMM ((DWORD)0x1)

#تعریف_کن PST_UNSPECIFIED ((DWORD)0x0)
#تعریف_کن PST_RS232 ((DWORD)0x1)
#تعریف_کن PST_PARALLELPORT ((DWORD)0x2)
#تعریف_کن PST_RS422 ((DWORD)0x3)
#تعریف_کن PST_RS423 ((DWORD)0x4)
#تعریف_کن PST_RS449 ((DWORD)0x5)
#تعریف_کن PST_MODEM ((DWORD)0x6)
#تعریف_کن PST_FAX ((DWORD)0x21)
#تعریف_کن PST_SCANNER ((DWORD)0x22)
#تعریف_کن PST_شبکه_BRIDGE ((DWORD)0x100)
#تعریف_کن PST_LAT ((DWORD)0x101)
#تعریف_کن PST_TCPIP_TELNET ((DWORD)0x102)
#تعریف_کن PST_X25 ((DWORD)0x103)

#تعریف_کن PCF_DTRDSR ((DWORD)0x1)
#تعریف_کن PCF_RTSCTS ((DWORD)0x2)
#تعریف_کن PCF_RLSD ((DWORD)0x4)
#تعریف_کن PCF_PARITY_CHECK ((DWORD)0x8)
#تعریف_کن PCF_XONXOFF ((DWORD)0x10)
#تعریف_کن PCF_SETXCHAR ((DWORD)0x20)
#تعریف_کن PCF_TOTALTIMEOUTS ((DWORD)0x40)
#تعریف_کن PCF_INTTIMEOUTS ((DWORD)0x80)
#تعریف_کن PCF_SPECIALCHARS ((DWORD)0x100)
#تعریف_کن PCF_16BITMODE ((DWORD)0x200)

#تعریف_کن SP_PARITY ((DWORD)0x1)
#تعریف_کن SP_BAUD ((DWORD)0x2)
#تعریف_کن SP_DATABITS ((DWORD)0x4)
#تعریف_کن SP_STOPBITS ((DWORD)0x8)
#تعریف_کن SP_HANDSHAKING ((DWORD)0x10)
#تعریف_کن SP_PARITY_CHECK ((DWORD)0x20)
#تعریف_کن SP_RLSD ((DWORD)0x40)

#تعریف_کن BAUD_075 ((DWORD)0x1)
#تعریف_کن BAUD_110 ((DWORD)0x2)
#تعریف_کن BAUD_134_5 ((DWORD)0x4)
#تعریف_کن BAUD_150 ((DWORD)0x8)
#تعریف_کن BAUD_300 ((DWORD)0x10)
#تعریف_کن BAUD_600 ((DWORD)0x20)
#تعریف_کن BAUD_1200 ((DWORD)0x40)
#تعریف_کن BAUD_1800 ((DWORD)0x80)
#تعریف_کن BAUD_2400 ((DWORD)0x100)
#تعریف_کن BAUD_4800 ((DWORD)0x200)
#تعریف_کن BAUD_7200 ((DWORD)0x400)
#تعریف_کن BAUD_9600 ((DWORD)0x800)
#تعریف_کن BAUD_14400 ((DWORD)0x1000)
#تعریف_کن BAUD_19200 ((DWORD)0x2000)
#تعریف_کن BAUD_38400 ((DWORD)0x4000)
#تعریف_کن BAUD_56K ((DWORD)0x8000)
#تعریف_کن BAUD_128K ((DWORD)0x10000)
#تعریف_کن BAUD_115200 ((DWORD)0x20000)
#تعریف_کن BAUD_57600 ((DWORD)0x40000)
#تعریف_کن BAUD_USER ((DWORD)0x10000000)

#تعریف_کن DATABITS_5 ((کلمه_3)0x1)
#تعریف_کن DATABITS_6 ((کلمه_3)0x2)
#تعریف_کن DATABITS_7 ((کلمه_3)0x4)
#تعریف_کن DATABITS_8 ((کلمه_3)0x8)
#تعریف_کن DATABITS_16 ((کلمه_3)0x10)
#تعریف_کن DATABITS_16X ((کلمه_3)0x20)

#تعریف_کن STOPBITS_10 ((کلمه_3)0x1)
#تعریف_کن STOPBITS_15 ((کلمه_3)0x2)
#تعریف_کن STOPBITS_20 ((کلمه_3)0x4)
#تعریف_کن PARITY_NONE ((کلمه_3)0x100)
#تعریف_کن PARITY_ODD ((کلمه_3)0x200)
#تعریف_کن PARITY_EVEN ((کلمه_3)0x400)
#تعریف_کن PARITY_MARK ((کلمه_3)0x800)
#تعریف_کن PARITY_SPACE ((کلمه_3)0x1000)

  تعريفنوع بنية _COMMPROP {
    کلمه_3 w_Packet_درازی;
    کلمه_3 w_Packet_نسخه;
    DWORD dw_Service_ماسک;
    DWORD dwReserved1;
    DWORD dw_Max_Tx_صف;
    DWORD dw_Max_Rx_صف;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    کلمه_3 w_Settable_داده;
    کلمه_3 wSettableStopParity;
    DWORD dw_Current_Tx_صف;
    DWORD dw_Current_Rx_صف;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#تعریف_کن COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  تعريفنوع بنية _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD f_Xoff_فرستاده : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cb_درون_Que;
    DWORD cb_بیرون_Que;
  } COMSTAT,*LPCOMSTAT;

#تعریف_کن DTR_CONTROL_DISABLE 0x0
#تعریف_کن DTR_CONTROL_ENABLE 0x1
#تعریف_کن DTR_CONTROL_HANDSHAKE 0x2

#تعریف_کن RTS_CONTROL_DISABLE 0x0
#تعریف_کن RTS_CONTROL_ENABLE 0x1
#تعریف_کن RTS_CONTROL_HANDSHAKE 0x2
#تعریف_کن RTS_CONTROL_TOGGLE 0x3

  تعريفنوع بنية _DCB {
    DWORD DCBlength;
    DWORD Baud_نرخ;
    DWORD f_دودویی: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD f_Dsr_حساسیت:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD f_بیرون_X: 1;
    DWORD f_درون_X: 1;
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
    BYTE Stop_بیتها;
    حرف XonChar;
    حرف XoffChar;
    حرف ErrorChar;
    حرف EofChar;
    حرف EvtChar;
    کلمه_3 wReserved1;
  } DCB,*LPDCB;

  تعريفنوع بنية _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD Read_مجموع_Timeout_Multiplier;
    DWORD Read_مجموع_Timeout_Constant;
    DWORD Write_مجموع_Timeout_Multiplier;
    DWORD Write_مجموع_Timeout_Constant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  تعريفنوع بنية _COMMCONFIG {
    DWORD dw_اندازه;
    کلمه_3 w_نسخه;
    کلمه_3 wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dw_Provider_جابه_جایی;
    DWORD dw_Provider_اندازه;
    WCHAR wc_Provider_داده[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  تعريفنوع بنية _SYSTEM_INFO {
    اتحاد {
      DWORD dwOemId;
      بنية {
	کلمه_3 wProcessorArchitecture;
	کلمه_3 wReserved;
      };
    };
    DWORD dw_صفحه_اندازه;
    LPVOID lp_Minimum_Application_آدرس;
    LPVOID lp_بیشینه_Application_آدرس;
    DWORD_PTR dw_فعال_Processor_ماسک;
    DWORD dw_عدد_از_Processors;
    DWORD dwProcessorType;
    DWORD dw_تخصیص_Granularity;
    کلمه_3 wProcessorLevel;
    کلمه_3 wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#تعریف_کن FreeModule(hLibModule) FreeLibrary((hLibModule))
#تعریف_کن MakeProcInstance(lpProc,hInstance) (lpProc)
#تعریف_کن FreeProcInstance(lpProc) (lpProc)

#تعریف_کن GMEM_FIXED 0x0
#تعریف_کن GMEM_MOVEABLE 0x2
#تعریف_کن GMEM_NOCOMPACT 0x10
#تعریف_کن GMEM_NODISCARD 0x20
#تعریف_کن GMEM_ZEROINIT 0x40
#تعریف_کن GMEM_MODIFY 0x80
#تعریف_کن GMEM_DISCARDABLE 0x100
#تعریف_کن GMEM_NOT_BANKED 0x1000
#تعریف_کن GMEM_SHARE 0x2000
#تعریف_کن GMEM_DDESHARE 0x2000
#تعریف_کن GMEM_NOTIFY 0x4000
#تعریف_کن GMEM_پایینی GMEM_NOT_BANKED
#تعریف_کن GMEM_VALID_FLAGS 0x7F72
#تعریف_کن GMEM_INVALID_HANDLE 0x8000

#تعریف_کن GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#تعریف_کن GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#تعریف_کن GlobalLRUNewest(h) ((HANDLE)(h))
#تعریف_کن GlobalLRUOldest(h) ((HANDLE)(h))
#تعریف_کن GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#تعریف_کن GMEM_DISCARDED 0x4000
#تعریف_کن GMEM_LOCKCOUNT 0xff

  تعريفنوع بنية _MEMORYSTATUS {
    DWORD dw_درازی;
    DWORD dw_حافظه_بارگیری;
    اندازه_T dw_مجموع_Phys;
    اندازه_T dwAvailPhys;
    اندازه_T dw_مجموع_صفحه_File;
    اندازه_T dw_Avail_صفحه_File;
    اندازه_T dw_مجموع_Virtual;
    اندازه_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#تعریف_کن LMEM_FIXED 0x0
#تعریف_کن LMEM_MOVEABLE 0x2
#تعریف_کن LMEM_NOCOMPACT 0x10
#تعریف_کن LMEM_NODISCARD 0x20
#تعریف_کن LMEM_ZEROINIT 0x40
#تعریف_کن LMEM_MODIFY 0x80
#تعریف_کن LMEM_DISCARDABLE 0xf00
#تعریف_کن LMEM_VALID_FLAGS 0xf72
#تعریف_کن LMEM_INVALID_HANDLE 0x8000

#تعریف_کن LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#تعریف_کن LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#تعریف_کن NONZEROLHND (LMEM_MOVEABLE)
#تعریف_کن NONZEROLPTR (LMEM_FIXED)

#تعریف_کن LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#تعریف_کن LMEM_DISCARDED 0x4000
#تعریف_کن LMEM_LOCKCOUNT 0xff

#تعریف_کن DEBUG_PROCESS 0x1
#تعریف_کن DEBUG_ONLY_THIS_PROCESS 0x2
#تعریف_کن CREATE_SUSPENDED 0x4
#تعریف_کن DETACHED_PROCESS 0x8
#تعریف_کن CREATE_NEW_CONSOLE 0x10
#تعریف_کن نرمال_اولویت_CLASS 0x20
#تعریف_کن IDLE_اولویت_CLASS 0x40
#تعریف_کن بالا_اولویت_CLASS 0x80
#تعریف_کن REALTIME_اولویت_CLASS 0x100
#تعریف_کن CREATE_NEW_PROCESS_گروه 0x200
#تعریف_کن CREATE_UNICODE_ENVIRONMENT 0x400
#تعریف_کن CREATE_SEPARATE_WOW_VDM 0x800
#تعریف_کن CREATE_SHARED_WOW_VDM 0x1000
#تعریف_کن CREATE_FORCEDOS 0x2000
#تعریف_کن زیر_نرمال_اولویت_CLASS 0x4000
#تعریف_کن ABOVE_نرمال_اولویت_CLASS 0x8000
#تعریف_کن پشته_اندازه_PARAM_IS_A_RESERVATION 0x10000

#تعریف_کن CREATE_BREAKAWAY_FROM_کار 0x1000000
#تعریف_کن CREATE_PRESERVE_کد_AUTHZ_LEVEL 0x2000000

#تعریف_کن CREATE_DEFAULT_ERROR_نما 0x4000000
#تعریف_کن CREATE_NO_پنجره 0x8000000

#تعریف_کن PROFILE_USER 0x10000000
#تعریف_کن PROFILE_KERNEL 0x20000000
#تعریف_کن PROFILE_SERVER 0x40000000

#تعریف_کن CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#تعریف_کن THREAD_اولویت_پایینترین THREAD_پایه_اولویت_MIN
#تعریف_کن THREAD_اولویت_زیر_نرمال (THREAD_اولویت_پایینترین+1)
#تعریف_کن THREAD_اولویت_نرمال 0
#تعریف_کن THREAD_اولویت_HIGHEST THREAD_پایه_اولویت_MAX
#تعریف_کن THREAD_اولویت_ABOVE_نرمال (THREAD_اولویت_HIGHEST-1)
#تعریف_کن THREAD_اولویت_ERROR_RETURN (MAXLONG)

#تعریف_کن THREAD_اولویت_زمان_CRITICAL THREAD_پایه_اولویت_LOWRT
#تعریف_کن THREAD_اولویت_IDLE THREAD_پایه_اولویت_IDLE

#تعریف_کن EXCEPTION_DEBUG_EVENT 1
#تعریف_کن CREATE_THREAD_DEBUG_EVENT 2
#تعریف_کن CREATE_PROCESS_DEBUG_EVENT 3
#تعریف_کن EXIT_THREAD_DEBUG_EVENT 4
#تعریف_کن EXIT_PROCESS_DEBUG_EVENT 5
#تعریف_کن بارگیری_DLL_DEBUG_EVENT 6
#تعریف_کن UNLOAD_DLL_DEBUG_EVENT 7
#تعریف_کن OUTPUT_DEBUG_STRING_EVENT 8
#تعریف_کن RIP_EVENT 9

  تعريفنوع بنية _EXCEPTION_DEBUG_INFO {
    EXCEPTION_رکورد_2 Exception_رکورد;
    DWORD dw_اولی_Chance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  تعريفنوع بنية _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lp_Thread_Local_پایه;
    LPTHREAD_شروع_ROUTINE lp_شروع_آدرس;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  تعريفنوع بنية _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lp_پایه_از_Image;
    DWORD dw_Debug_Info_File_جابه_جایی;
    DWORD n_Debug_Info_اندازه;
    LPVOID lp_Thread_Local_پایه;
    LPTHREAD_شروع_ROUTINE lp_شروع_آدرس;
    LPVOID lpImageName;
    کلمه_3 fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  تعريفنوع بنية _EXIT_THREAD_DEBUG_INFO {
    DWORD dw_Exit_کد;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  تعريفنوع بنية _EXIT_PROCESS_DEBUG_INFO {
    DWORD dw_Exit_کد;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  تعريفنوع بنية بارگیری_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lp_پایه_از_Dll;
    DWORD dw_Debug_Info_File_جابه_جایی;
    DWORD n_Debug_Info_اندازه;
    LPVOID lpImageName;
    کلمه_3 fUnicode;
  } بارگیری_DLL_DEBUG_INFO_2,*LPLOAD_DLL_DEBUG_INFO;

  تعريفنوع بنية _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lp_پایه_از_Dll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  تعريفنوع بنية _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lp_Debug_String_داده;
    کلمه_3 fUnicode;
    کلمه_3 n_Debug_String_درازی;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  تعريفنوع بنية _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  تعريفنوع بنية _DEBUG_EVENT {
    DWORD dw_Debug_Event_کد;
    DWORD dwProcessId;
    DWORD dwThreadId;
    اتحاد {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      بارگیری_DLL_DEBUG_INFO_2 بارگیری_Dll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  تعريفنوع PCONTEXT LPCONTEXT;
  تعريفنوع PEXCEPTION_رکورد LPEXCEPTION_رکورد;
  تعريفنوع PEXCEPTION_اشارهگرها LPEXCEPTION_اشارهگرها;

#تعریف_کن DRIVE_UNKNOWN 0
#تعریف_کن DRIVE_NO_ریشه_DIR 1
#تعریف_کن DRIVE_REMOVABLE 2
#تعریف_کن DRIVE_FIXED 3
#تعریف_کن DRIVE_REMOTE 4
#تعریف_کن DRIVE_CDROM 5
#تعریف_کن DRIVE_RAMDISK 6

#تعریف_کن GetFreeSpace(w) (0x100000L)
#تعریف_کن FILE_TYPE_UNKNOWN 0x0
#تعریف_کن FILE_TYPE_DISK 0x1
#تعریف_کن FILE_TYPE_CHAR 0x2
#تعریف_کن FILE_TYPE_PIPE 0x3
#تعریف_کن FILE_TYPE_REMOTE 0x8000

#تعریف_کن STD_درون_داد_HANDLE ((DWORD)-10)
#تعریف_کن STD_OUTPUT_HANDLE ((DWORD)-11)
#تعریف_کن STD_ERROR_HANDLE ((DWORD)-12)

#تعریف_کن NOPARITY 0
#تعریف_کن ODDPARITY 1
#تعریف_کن EVENPARITY 2
#تعریف_کن MARKPARITY 3
#تعریف_کن SPACEPARITY 4

#تعریف_کن ONESTOPBIT 0
#تعریف_کن ONE5STOPBITS 1
#تعریف_کن TWOSTOPBITS 2

#تعریف_کن IGNORE 0
#تعریف_کن INFINITE 0xffffffff

#تعریف_کن CBR_110 110
#تعریف_کن CBR_300 300
#تعریف_کن CBR_600 600
#تعریف_کن CBR_1200 1200
#تعریف_کن CBR_2400 2400
#تعریف_کن CBR_4800 4800
#تعریف_کن CBR_9600 9600
#تعریف_کن CBR_14400 14400
#تعریف_کن CBR_19200 19200
#تعریف_کن CBR_38400 38400
#تعریف_کن CBR_56000 56000
#تعریف_کن CBR_57600 57600
#تعریف_کن CBR_115200 115200
#تعریف_کن CBR_128000 128000
#تعریف_کن CBR_256000 256000

#تعریف_کن CE_RXOVER 0x1
#تعریف_کن CE_OVERRUN 0x2
#تعریف_کن CE_RXPARITY 0x4
#تعریف_کن CE_قاب 0x8
#تعریف_کن CE_BREAK 0x10
#تعریف_کن CE_TXFULL 0x100
#تعریف_کن CE_PTO 0x200
#تعریف_کن CE_IOE 0x400
#تعریف_کن CE_DNS 0x800
#تعریف_کن CE_OOP 0x1000
#تعریف_کن CE_نما 0x8000

#تعریف_کن IE_BADID (-1)
#تعریف_کن IE_OPEN (-2)
#تعریف_کن IE_NOPEN (-3)
#تعریف_کن IE_حافظه (-4)
#تعریف_کن IE_DEFAULT (-5)
#تعریف_کن IE_HARDWARE (-10)
#تعریف_کن IE_BYTESIZE (-11)
#تعریف_کن IE_BAUDRATE (-12)

#تعریف_کن EV_RXCHAR 0x1
#تعریف_کن EV_RXFLAG 0x2
#تعریف_کن EV_TXEMPTY 0x4
#تعریف_کن EV_CTS 0x8
#تعریف_کن EV_DSR 0x10
#تعریف_کن EV_RLSD 0x20
#تعریف_کن EV_BREAK 0x40
#تعریف_کن EV_ERR 0x80
#تعریف_کن EV_RING 0x100
#تعریف_کن EV_PERR 0x200
#تعریف_کن EV_RX80_پر 0x400
#تعریف_کن EV_EVENT1 0x800
#تعریف_کن EV_EVENT2 0x1000

#تعریف_کن SETXOFF 1
#تعریف_کن SETXON 2
#تعریف_کن SETRTS 3
#تعریف_کن CLRRTS 4
#تعریف_کن SETDTR 5
#تعریف_کن CLRDTR 6
#تعریف_کن RESETDEV 7
#تعریف_کن SETBREAK 8
#تعریف_کن CLRBREAK 9

#تعریف_کن PURGE_TXABORT 0x1
#تعریف_کن PURGE_RXABORT 0x2
#تعریف_کن PURGE_TXCLEAR 0x4
#تعریف_کن PURGE_RXCLEAR 0x8

#تعریف_کن LPTx 0x80

#تعریف_کن MS_CTS_ON ((DWORD)0x10)
#تعریف_کن MS_DSR_ON ((DWORD)0x20)
#تعریف_کن MS_RING_ON ((DWORD)0x40)
#تعریف_کن MS_RLSD_ON ((DWORD)0x80)

#تعریف_کن S_QUEUEEMPTY 0
#تعریف_کن S_آستانه 1
#تعریف_کن S_ALLTHRESHOLD 2

#تعریف_کن S_نرمال 0
#تعریف_کن S_LEGATO 1
#تعریف_کن S_STACCATO 2

#تعریف_کن S_PERIOD512 0
#تعریف_کن S_PERIOD1024 1
#تعریف_کن S_PERIOD2048 2
#تعریف_کن S_PERIODVOICE 3
#تعریف_کن S_WHITE512 4
#تعریف_کن S_WHITE1024 5
#تعریف_کن S_WHITE2048 6
#تعریف_کن S_WHITEVOICE 7

#تعریف_کن S_SERDVNA (-1)
#تعریف_کن S_SEROFM (-2)
#تعریف_کن S_SERMACT (-3)
#تعریف_کن S_SERQFUL (-4)
#تعریف_کن S_SERBDNT (-5)
#تعریف_کن S_SERDLN (-6)
#تعریف_کن S_SERDCC (-7)
#تعریف_کن S_SERDTP (-8)
#تعریف_کن S_SERDVL (-9)
#تعریف_کن S_SERDMD (-10)
#تعریف_کن S_SERDSH (-11)
#تعریف_کن S_SERDPT (-12)
#تعریف_کن S_SERDFQ (-13)
#تعریف_کن S_SERDDR (-14)
#تعریف_کن S_SERDSR (-15)
#تعریف_کن S_SERDST (-16)

#تعریف_کن NMPWAIT_WAIT_FOREVER 0xffffffff
#تعریف_کن NMPWAIT_NOWAIT 0x1
#تعریف_کن NMPWAIT_USE_DEFAULT_WAIT 0x0

#تعریف_کن FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_نامها
#تعریف_کن FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_جستجو
#تعریف_کن FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#تعریف_کن FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#تعریف_کن FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#تعریف_کن FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#تعریف_کن FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#تعریف_کن FILE_MAP_COPY SECTION_QUERY
#تعریف_کن FILE_MAP_WRITE SECTION_MAP_WRITE
#تعریف_کن FILE_MAP_READ SECTION_MAP_READ
#تعریف_کن FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#تعریف_کن FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#تعریف_کن از_READ 0x0
#تعریف_کن از_WRITE 0x1
#تعریف_کن از_READWRITE 0x2
#تعریف_کن از_SHARE_COMPAT 0x0
#تعریف_کن از_SHARE_EXCLUSIVE 0x10
#تعریف_کن از_SHARE_DENY_WRITE 0x20
#تعریف_کن از_SHARE_DENY_READ 0x30
#تعریف_کن از_SHARE_DENY_NONE 0x40
#تعریف_کن از_PARSE 0x100
#تعریف_کن از_DELETE 0x200
#تعریف_کن از_VERIFY 0x400
#تعریف_کن از_CANCEL 0x800
#تعریف_کن از_CREATE 0x1000
#تعریف_کن از_PROMPT 0x2000
#تعریف_کن از_EXIST 0x4000
#تعریف_کن از_REOPEN 0x8000

#تعریف_کن OFS_MAXPATHNAME 128
  تعريفنوع بنية _OFSTRUCT {
    BYTE c_بایتها;
    BYTE fFixedDisk;
    کلمه_3 n_Err_کد;
    کلمه_3 Reserved1;
    کلمه_3 Reserved2;
    CHAR sz_مسیر_Name[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#اگر_تعریف_نشده NOWINBASEINTERLOCK

#اگر_تعریف_نشده _NTOS_

#إذا defined(__ia64__) && !defined(RC_INVOKED)

#تعریف_کن InterlockedIncrement _InterlockedIncrement
#تعریف_کن InterlockedIncrementAcquire _InterlockedIncrement_acq
#تعریف_کن InterlockedIncrementRelease _InterlockedIncrement_rel
#تعریف_کن InterlockedDecrement _InterlockedDecrement
#تعریف_کن InterlockedDecrementAcquire _InterlockedDecrement_acq
#تعریف_کن InterlockedDecrementRelease _InterlockedDecrement_rel
#تعریف_کن InterlockedExchange _InterlockedExchange
#تعریف_کن Interlocked_Exchange_جمع_کن Interlocked_Exchange_جمع_کن_2
#تعریف_کن InterlockedCompareExchange _InterlockedCompareExchange
#تعریف_کن InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#تعریف_کن InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#تعریف_کن Interlocked_Exchange_اشاره_گر Interlocked_Exchange_اشاره_گر_2
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر Interlocked_Compare_Exchange_اشاره_گر_2
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Release Interlocked_Compare_Exchange_اشاره_گر_rel
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Acquire Interlocked_Compare_Exchange_اشاره_گر_acq

#تعریف_کن InterlockedIncrement64 _InterlockedIncrement64
#تعریف_کن InterlockedDecrement64 _InterlockedDecrement64
#تعریف_کن InterlockedExchange64 _InterlockedExchange64
#تعریف_کن InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#تعریف_کن InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#تعریف_کن InterlockedCompareExchange64 _InterlockedCompareExchange64
#تعریف_کن InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#تعریف_کن InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG متطاير *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG متطاير *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG متطاير *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG متطاير *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG متطاير *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG متطاير *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG متطاير *هدف_2,LONGLONG مقدار_3);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG متطاير *هدف_2,LONGLONG مقدار_3);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG متطاير *Addend,LONGLONG مقدار_3);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG متطاير *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG متطاير *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG متطاير *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG متطاير *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG متطاير *lpAddend);
  LONG __cdecl InterlockedExchange(LONG متطاير *هدف_2,LONG مقدار_3);
  LONG __cdecl Interlocked_Exchange_جمع_کن(LONG متطاير *Addend,LONG مقدار_3);
  LONG __cdecl InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl Interlocked_Exchange_اشاره_گر(PVOID متطاير *هدف_2,PVOID مقدار_3);
  PVOID __cdecl Interlocked_Compare_Exchange_اشاره_گر(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_اشاره_گر_Acquire(PVOID متطاير *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_اشاره_گر_Release(PVOID متطاير *Destination,PVOID Exchange,PVOID Comperand);

#اگر_تعریف_نشده InterlockedAnd
#تعریف_کن InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG متطاير *هدف_2,LONG مجموعه_2) {
    LONG i;
    LONG j;
    j = *هدف_2;
    افعل {
      i = j;
      j = InterlockedCompareExchange(هدف_2,i & مجموعه_2,i);
    } طالما(i!=j);
    أرجع j;
  }
#پایان_اگر

#اگر_تعریف_نشده InterlockedOr
#تعریف_کن InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG متطاير *هدف_2,LONG مجموعه_2) {
    LONG i;
    LONG j;
    j = *هدف_2;
    افعل {
      i = j;
      j = InterlockedCompareExchange(هدف_2,i | مجموعه_2,i);
    } طالما(i!=j);
    أرجع j;
  }
#پایان_اگر

#اگر_تعریف_نشده InterlockedXor
#تعریف_کن InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG متطاير *هدف_2,LONG مجموعه_2) {
    LONG i;
    LONG j;
    j = *هدف_2;
    افعل {
      i = j;
      j = InterlockedCompareExchange(هدف_2,i ^ مجموعه_2,i);
    } طالما(i!=j);
    أرجع j;
  }
#پایان_اگر

#اگر_تعریف_نشده InterlockedAnd64
#تعریف_کن InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG متطاير *Destination,LONGLONG مقدار_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old & مقدار_3,Old)!=Old);
    أرجع Old;
  }
#پایان_اگر

#اگر_تعریف_نشده InterlockedOr64
#تعریف_کن InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG متطاير *Destination,LONGLONG مقدار_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old | مقدار_3,Old)!=Old);
    أرجع Old;
  }
#پایان_اگر

#اگر_تعریف_نشده InterlockedXor64
#تعریف_کن InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG متطاير *Destination,LONGLONG مقدار_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old ^ مقدار_3,Old)!=Old);
    أرجع Old;
  }
#پایان_اگر

#اگر_تعریف_نشده Interlocked_بیت_Test_And_مجموعه
#تعریف_کن Interlocked_بیت_Test_And_مجموعه Interlocked_بیت_Test_And_مجموعه_Inline

  __CRT_INLINE BOOLEAN Interlocked_بیت_Test_And_مجموعه_Inline(LONG *پایه_2,LONG بیت_2) {
    LONG t_بیت;
    t_بیت = 1<<(بیت_2 & (حجم (*پایه_2)*8-1));
    أرجع (BOOLEAN)((InterlockedOr(&پایه_2[بیت_2/(حجم(*پایه_2)*8)],t_بیت)&t_بیت)!=0);
  }
#پایان_اگر

#اگر_تعریف_نشده Interlocked_بیت_Test_And_Reset
#تعریف_کن Interlocked_بیت_Test_And_Reset Interlocked_بیت_Test_And_Reset_Inline

  __CRT_INLINE BOOLEAN Interlocked_بیت_Test_And_Reset_Inline(LONG *پایه_2,LONG بیت_2) {
    LONG t_بیت;
    t_بیت = 1<<(بیت_2 & (حجم (*پایه_2)*8-1));
    أرجع (BOOLEAN)((InterlockedAnd(&پایه_2[بیت_2/(حجم(*پایه_2)*8)],~t_بیت)&t_بیت)!=0);
  }
#پایان_اگر

#اگر_تعریف_نشده Interlocked_بیت_Test_And_Complement
#تعریف_کن Interlocked_بیت_Test_And_Complement Interlocked_بیت_Test_And_Complement_Inline

  __CRT_INLINE BOOLEAN Interlocked_بیت_Test_And_Complement_Inline(LONG *پایه_2,LONG بیت_2) {
    LONG t_بیت;
    t_بیت = 1<<(بیت_2 & (حجم (*پایه_2)*8-1));
    أرجع (BOOLEAN)((InterlockedXor(&پایه_2[بیت_2/(حجم(*پایه_2)*8)],t_بیت)&t_بیت)!=0);
  }
#پایان_اگر
#وإلاإذا defined(__x86_64) && !defined(RC_INVOKED)

#تعریف_کن InterlockedIncrement _InterlockedIncrement
#تعریف_کن InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کن InterlockedIncrementRelease InterlockedIncrement
#تعریف_کن InterlockedDecrement _InterlockedDecrement
#تعریف_کن InterlockedDecrementAcquire InterlockedDecrement
#تعریف_کن InterlockedDecrementRelease InterlockedDecrement
#تعریف_کن InterlockedExchange _InterlockedExchange
#تعریف_کن Interlocked_Exchange_جمع_کن Interlocked_Exchange_جمع_کن_2
#تعریف_کن InterlockedCompareExchange _InterlockedCompareExchange
#تعریف_کن InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کن InterlockedCompareExchangeRelease InterlockedCompareExchange
#تعریف_کن Interlocked_Exchange_اشاره_گر Interlocked_Exchange_اشاره_گر_2
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر Interlocked_Compare_Exchange_اشاره_گر_2
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Acquire Interlocked_Compare_Exchange_اشاره_گر_2
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Release Interlocked_Compare_Exchange_اشاره_گر_2
#تعریف_کن InterlockedAnd64 _InterlockedAnd64
#تعریف_کن InterlockedOr64 _InterlockedOr64
#تعریف_کن InterlockedXor64 _InterlockedXor64
#تعریف_کن InterlockedIncrement64 _InterlockedIncrement64
#تعریف_کن InterlockedDecrement64 _InterlockedDecrement64
#تعریف_کن InterlockedExchange64 _InterlockedExchange64
#تعریف_کن InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#تعریف_کن InterlockedCompareExchange64 _InterlockedCompareExchange64
#تعریف_کن InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#تعریف_کن InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG متطاير *Addend);
  LONG InterlockedDecrement(LONG متطاير *Addend);
  LONG InterlockedExchange(LONG متطاير *هدف_2,LONG مقدار_3);
  LONG Interlocked_Exchange_جمع_کن(LONG متطاير *Addend,LONG مقدار_3);
  LONG InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  PVOID Interlocked_Compare_Exchange_اشاره_گر(PVOID متطاير *Destination,PVOID Exchange,PVOID Comperand);
  PVOID Interlocked_Exchange_اشاره_گر(PVOID متطاير *هدف_2,PVOID مقدار_3);
  LONG64 InterlockedAnd64(LONG64 متطاير *Destination,LONG64 مقدار_3);
  LONG64 InterlockedOr64(LONG64 متطاير *Destination,LONG64 مقدار_3);
  LONG64 InterlockedXor64(LONG64 متطاير *Destination,LONG64 مقدار_3);
  LONG64 InterlockedIncrement64(LONG64 متطاير *Addend);
  LONG64 InterlockedDecrement64(LONG64 متطاير *Addend);
  LONG64 InterlockedExchange64(LONG64 متطاير *هدف_2,LONG64 مقدار_3);
  LONG64 InterlockedExchangeAdd64(LONG64 متطاير *Addend,LONG64 مقدار_3);
  LONG64 InterlockedCompareExchange64(LONG64 متطاير *Destination,LONG64 ExChange,LONG64 Comperand);
#وإلا
  LONG WINAPI InterlockedIncrement(LONG متطاير *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG متطاير *lpAddend);
  LONG WINAPI InterlockedExchange(LONG متطاير *هدف_2,LONG مقدار_3);

#اگر_تعریف_نشده Interlocked_Exchange_اشاره_گر
#تعریف_کن Interlocked_Exchange_اشاره_گر(هدف_2,مقدار_3) (PVOID)InterlockedExchange((PLONG)(هدف_2),(LONG)(مقدار_3))
#پایان_اگر

  LONG WINAPI Interlocked_Exchange_جمع_کن(LONG متطاير *Addend,LONG مقدار_3);
  LONG WINAPI InterlockedCompareExchange(LONG متطاير *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG متطاير *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG متطاير *Destination,LONGLONG مقدار_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old & مقدار_3,Old)!=Old);
    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG متطاير *Destination,LONGLONG مقدار_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old | مقدار_3,Old)!=Old);
    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG متطاير *Destination,LONGLONG مقدار_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old ^ مقدار_3,Old)!=Old);

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

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG متطاير *هدف_2,LONGLONG مقدار_3) {
    LONGLONG Old;
    افعل {
      Old = *هدف_2;
    } طالما(InterlockedCompareExchange64(هدف_2,مقدار_3,Old)!=Old);
    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG متطاير *Addend,LONGLONG مقدار_3) {
    LONGLONG Old;
    افعل {
      Old = *Addend;
    } طالما(InterlockedCompareExchange64(Addend,Old + مقدار_3,Old)!=Old);
    أرجع Old;
  }

#اگر_تعریف_نشده Interlocked_Compare_Exchange_اشاره_گر
#اگر_تعریف_شده __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand) {
    أرجع((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG متطاير *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر __InlineInterlockedCompareExchangePointer
#وإلا
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG متطاير *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#پایان_اگر
#پایان_اگر

#تعریف_کن InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کن InterlockedIncrementRelease InterlockedIncrement
#تعریف_کن InterlockedDecrementAcquire InterlockedDecrement
#تعریف_کن InterlockedDecrementRelease InterlockedDecrement
#تعریف_کن InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کن InterlockedIncrementRelease InterlockedIncrement
#تعریف_کن InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کن InterlockedCompareExchangeRelease InterlockedCompareExchange
#تعریف_کن InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#تعریف_کن InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#اگر_تعریف_نشده Interlocked_Compare_Exchange_اشاره_گر_Acquire
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Acquire Interlocked_Compare_Exchange_اشاره_گر
#پایان_اگر
#اگر_تعریف_نشده Interlocked_Compare_Exchange_اشاره_گر_Release
#تعریف_کن Interlocked_Compare_Exchange_اشاره_گر_Release Interlocked_Compare_Exchange_اشاره_گر
#پایان_اگر
#پایان_اگر

#إذا defined(SLIST_سرآیند) && !defined(_NTOSP_)
  WINBASEAPI VOID WINAPI Initialize_SList_سر(PSLIST_سرآیند List_سر);
  WINBASEAPI PSLIST_مدخل WINAPI Interlocked_برداشت_مدخل_SList(PSLIST_سرآیند List_سر);
  WINBASEAPI PSLIST_مدخل WINAPI Interlocked_افزودن_مدخل_SList(PSLIST_سرآیند List_سر,PSLIST_مدخل List_مدخل);
  WINBASEAPI PSLIST_مدخل WINAPI InterlockedFlushSList(PSLIST_سرآیند List_سر);
  WINBASEAPI USHORT WINAPI Query_عمق_SList(PSLIST_سرآیند List_سر);
#پایان_اگر
#پایان_اگر
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL h_Res_داده);
  WINBASEAPI LPVOID WINAPI قفل_Resource(HGLOBAL h_Res_داده);

#تعریف_کن UnlockResource(h_Res_داده) ((h_Res_داده),0)
#تعریف_کن MAXINTATOM 0xC000
#تعریف_کن MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((کلمه_3)(i)))
#تعریف_کن INVALID_ATOM ((ATOM)0)

  صحيح WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lp_Cmd_سطر,صحيح nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dw_Exit_کد);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI Get_Proc_آدرس(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI Get_نسخه(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,اندازه_T dw_بایتها);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,اندازه_T dw_بایتها,UINT uFlags);
  WINBASEAPI اندازه_T WINAPI Global_اندازه(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI Global_قفل(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI اندازه_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI Global_حافظه_وضعیت(LPMEMORYSTATUS lp_میانگیر);

  تعريفنوع بنية _MEMORYSTATUSEX {
    DWORD dw_درازی;
    DWORD dw_حافظه_بارگیری;
    DWORDLONG ull_مجموع_Phys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ull_مجموع_صفحه_File;
    DWORDLONG ull_Avail_صفحه_File;
    DWORDLONG ull_مجموع_Virtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI Global_حافظه_وضعیت_Ex(LPMEMORYSTATUSEX lp_میانگیر);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,اندازه_T u_بایتها);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,اندازه_T u_بایتها,UINT uFlags);
  WINBASEAPI LPVOID WINAPI Local_قفل(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI اندازه_T WINAPI Local_اندازه(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI اندازه_T WINAPI LocalShrink(HLOCAL hMem,UINT cb_New_اندازه);
  WINBASEAPI اندازه_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lp_پایه_آدرس,اندازه_T dw_اندازه);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lp_آدرس,اندازه_T dw_اندازه,DWORD fl_تخصیص_Type,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lp_آدرس,اندازه_T dw_اندازه,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lp_آدرس,اندازه_T dw_اندازه,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI اندازه_T WINAPI VirtualQuery(LPCVOID lp_آدرس,PMEMORY_BASIC_INFORMATION lp_میانگیر,اندازه_T dw_درازی);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lp_آدرس,اندازه_T dw_اندازه,DWORD fl_تخصیص_Type,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lp_پایه_آدرس,اندازه_T dw_Region_اندازه,PVOID *lp_آدرسها,ULONG_PTR *lpdw_شمار,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lp_پایه_آدرس,اندازه_T dw_Region_اندازه);
  WINBASEAPI اندازه_T WINAPI Get_Large_صفحه_Minimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD Firmware_جدول_Provider_Signature,PVOID p_Firmware_جدول_Enum_میانگیر,DWORD میانگیر_اندازه);
  WINBASEAPI UINT WINAPI Get_System_Firmware_جدول(DWORD Firmware_جدول_Provider_Signature,DWORD Firmware_جدول_ID,PVOID p_Firmware_جدول_میانگیر,DWORD میانگیر_اندازه);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lp_آدرس,اندازه_T dw_اندازه,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lp_آدرس,اندازه_T dw_اندازه,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI اندازه_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lp_آدرس,PMEMORY_BASIC_INFORMATION lp_میانگیر,اندازه_T dw_درازی);
  WINBASEAPI HANDLE WINAPI انباشته_Create(DWORD flOptions,اندازه_T dw_Initial_اندازه,اندازه_T dw_بیشینه_اندازه);
  WINBASEAPI WINBOOL WINAPI انباشته_Destroy(HANDLE h_انباشته);
  WINBASEAPI LPVOID WINAPI انباشته_Alloc(HANDLE h_انباشته,DWORD dwFlags,اندازه_T dw_بایتها);
  WINBASEAPI LPVOID WINAPI انباشته_Re_Alloc(HANDLE h_انباشته,DWORD dwFlags,LPVOID lpMem,اندازه_T dw_بایتها);
  WINBASEAPI WINBOOL WINAPI انباشته_Free(HANDLE h_انباشته,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI اندازه_T WINAPI انباشته_اندازه(HANDLE h_انباشته,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI انباشته_Validate(HANDLE h_انباشته,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI اندازه_T WINAPI انباشته_Compact(HANDLE h_انباشته,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI Get_Process_انباشته(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD عدد_از_Heaps,PHANDLE ProcessHeaps);

  تعريفنوع بنية PROCESS_انباشته_مدخل {
    PVOID lp_داده;
    DWORD cb_داده;
    BYTE cbOverhead;
    BYTE i_Region_شاخص;
    کلمه_3 wFlags;
    اتحاد {
      بنية {
	HANDLE hMem;
	DWORD dwReserved[3];
      } بلوک_2;
      بنية {
	DWORD dw_Committed_اندازه;
	DWORD dw_Un_Committed_اندازه;
	LPVOID lp_اولی_بلوک;
	LPVOID lp_آخرین_بلوک;
      } Region;
    };
  } PROCESS_انباشته_مدخل_2,*LPPROCESS_انباشته_مدخل,*PPROCESS_انباشته_مدخل;

#تعریف_کن PROCESS_انباشته_REGION 0x1
#تعریف_کن PROCESS_انباشته_UNCOMMITTED_RANGE 0x2
#تعریف_کن PROCESS_انباشته_مدخل_BUSY 0x4
#تعریف_کن PROCESS_انباشته_مدخل_MOVEABLE 0x10
#تعریف_کن PROCESS_انباشته_مدخل_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI انباشته_قفل(HANDLE h_انباشته);
  WINBASEAPI WINBOOL WINAPI انباشته_Unlock(HANDLE h_انباشته);
  WINBASEAPI WINBOOL WINAPI انباشته_Walk(HANDLE h_انباشته,LPPROCESS_انباشته_مدخل lp_مدخل);
  WINBASEAPI WINBOOL WINAPI انباشته_مجموعه_Information(HANDLE انباشته_Handle,انباشته_INFORMATION_CLASS انباشته_Information_Class,PVOID انباشته_Information,اندازه_T انباشته_Information_درازی);
  WINBASEAPI WINBOOL WINAPI انباشته_Query_Information(HANDLE انباشته_Handle,انباشته_INFORMATION_CLASS انباشته_Information_Class,PVOID انباشته_Information,اندازه_T انباشته_Information_درازی,PSIZE_T Return_درازی);

#تعریف_کن SCS_32_بیت_دودویی 0
#تعریف_کن SCS_DOS_دودویی 1
#تعریف_کن SCS_WOW_دودویی 2
#تعریف_کن SCS_PIF_دودویی 3
#تعریف_کن SCS_POSIX_دودویی 4
#تعریف_کن SCS_OS216_دودویی 5
#تعریف_کن SCS_64_بیت_دودویی 6

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_دودویی_Type Get_دودویی_Type_W
#تعریف_کن Get_Short_مسیر_Name Get_Short_مسیر_Name_W
#تعریف_کن Get_Long_مسیر_Name Get_Long_مسیر_Name_W
#تعریف_کن Get_Environment_رشتهها Get_Environment_رشتهها_W
#تعریف_کن مجموعه_Environment_رشتهها مجموعه_Environment_رشتهها_W
#تعریف_کن Free_Environment_رشتهها Free_Environment_رشتهها_W
#وإلا
#تعریف_کن Get_دودویی_Type Get_دودویی_Type_A
#تعریف_کن Get_Short_مسیر_Name Get_Short_مسیر_Name_A
#تعریف_کن Get_Long_مسیر_Name Get_Long_مسیر_Name_A
#تعریف_کن Get_Environment_رشتهها_A Get_Environment_رشتهها
#تعریف_کن مجموعه_Environment_رشتهها مجموعه_Environment_رشتهها_A
#تعریف_کن Free_Environment_رشتهها Free_Environment_رشتهها_A
#پایان_اگر

#اگر_تعریف_شده _WIN64
#تعریف_کن SCS_THIS_PLATFORM_دودویی SCS_64_بیت_دودویی
#وإلا
#تعریف_کن SCS_THIS_PLATFORM_دودویی SCS_32_بیت_دودویی
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI Get_دودویی_Type_A(LPCSTR lpApplicationName,LPDWORD lp_دودویی_Type);
  WINBASEAPI WINBOOL WINAPI Get_دودویی_Type_W(LPCWSTR lpApplicationName,LPDWORD lp_دودویی_Type);
  WINBASEAPI DWORD WINAPI Get_Short_مسیر_Name_A(LPCSTR lpsz_Long_مسیر,LPSTR lpsz_Short_مسیر,DWORD cch_میانگیر);
  WINBASEAPI DWORD WINAPI Get_Short_مسیر_Name_W(LPCWSTR lpsz_Long_مسیر,LPWSTR lpsz_Short_مسیر,DWORD cch_میانگیر);
  WINBASEAPI DWORD WINAPI Get_Long_مسیر_Name_A(LPCSTR lpsz_Short_مسیر,LPSTR lpsz_Long_مسیر,DWORD cch_میانگیر);
  WINBASEAPI DWORD WINAPI Get_Long_مسیر_Name_W(LPCWSTR lpsz_Short_مسیر,LPWSTR lpsz_Long_مسیر,DWORD cch_میانگیر);
  WINBASEAPI WINBOOL WINAPI Get_Process_Affinity_ماسک(HANDLE hProcess,PDWORD_PTR lp_Process_Affinity_ماسک,PDWORD_PTR lp_System_Affinity_ماسک);
  WINBASEAPI WINBOOL WINAPI مجموعه_Process_Affinity_ماسک(HANDLE hProcess,DWORD_PTR dw_Process_Affinity_ماسک);
  WINBASEAPI WINBOOL WINAPI Get_Process_Handle_شمار(HANDLE hProcess,PDWORD pdw_Handle_شمار);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lp_Creation_زمان,LPFILETIME lp_Exit_زمان,LPFILETIME lp_Kernel_زمان,LPFILETIME lp_User_زمان);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_مجموعه_اندازه(HANDLE hProcess,PSIZE_T lp_Minimum_Working_مجموعه_اندازه,PSIZE_T lp_بیشینه_Working_مجموعه_اندازه);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_مجموعه_اندازه_Ex(HANDLE hProcess,PSIZE_T lp_Minimum_Working_مجموعه_اندازه,PSIZE_T lp_بیشینه_Working_مجموعه_اندازه,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI مجموعه_Process_Working_مجموعه_اندازه(HANDLE hProcess,اندازه_T dw_Minimum_Working_مجموعه_اندازه,اندازه_T dw_بیشینه_Working_مجموعه_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Process_Working_مجموعه_اندازه_Ex(HANDLE hProcess,اندازه_T dw_Minimum_Working_مجموعه_اندازه,اندازه_T dw_بیشینه_Working_مجموعه_اندازه,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT u_Exit_کد);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT u_Exit_کد);
  WINBASEAPI WINBOOL WINAPI Get_Exit_کد_Process(HANDLE hProcess,LPDWORD lp_Exit_کد);
  WINBASEAPI VOID WINAPI FatalExit(صحيح Exit_کد);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI Get_Environment_رشتهها_W(VOID);
  WINBASEAPI WINBOOL WINAPI مجموعه_Environment_رشتهها_A(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI مجموعه_Environment_رشتهها_W(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI Free_Environment_رشتهها_A(LPCH);
  WINBASEAPI WINBOOL WINAPI Free_Environment_رشتهها_W(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dw_Exception_کد,DWORD dwExceptionFlags,DWORD n_عدد_از_Arguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(بنية EXCEPTION_اشارهگرها_2 *ExceptionInfo);

  تعريفنوع LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(بنية EXCEPTION_اشارهگرها_2 *ExceptionInfo);
  تعريفنوع PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI مجموعه_Unhandled_Exception_Filter(LPTOP_LEVEL_EXCEPTION_FILTER lp_بالاترین_Level_Exception_Filter);

#تعریف_کن FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(اندازه_T dw_پشته_اندازه,LPFIBER_شروع_ROUTINE lp_شروع_آدرس,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(اندازه_T dw_پشته_Commit_اندازه,اندازه_T dw_پشته_Reserve_اندازه,DWORD dwFlags,LPFIBER_شروع_ROUTINE lp_شروع_آدرس,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI Convert_Thread_مقصد_Fiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI Convert_Thread_مقصد_Fiber_Ex(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Convert_Fiber_مقصد_Thread(VOID);
  WINBASEAPI VOID WINAPI Switch_مقصد_Fiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI Switch_مقصد_Thread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_صفات lp_Thread_صفات,اندازه_T dw_پشته_اندازه,LPTHREAD_شروع_ROUTINE lp_شروع_آدرس,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_صفات lp_Thread_صفات,اندازه_T dw_پشته_اندازه,LPTHREAD_شروع_ROUTINE lp_شروع_آدرس,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI مجموعه_Thread_پشته_Guarantee (PULONG پشته_اندازه_درون_بایتها);
  WINBASEAPI DWORD WINAPI Get_Process_Id_از_Thread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI Get_Current_Processor_عدد(VOID);
  WINBASEAPI DWORD_PTR WINAPI مجموعه_Thread_Affinity_ماسک(HANDLE hThread,DWORD_PTR dw_Thread_Affinity_ماسک);
  WINBASEAPI DWORD WINAPI مجموعه_Thread_Ideal_Processor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI مجموعه_Process_اولویت_Boost(HANDLE hProcess,WINBOOL b_Disable_اولویت_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Process_اولویت_Boost(HANDLE hProcess,PBOOL p_Disable_اولویت_Boost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_زمان latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI مجموعه_Thread_اولویت(HANDLE hThread,صحيح n_اولویت);
  WINBASEAPI WINBOOL WINAPI مجموعه_Thread_اولویت_Boost(HANDLE hThread,WINBOOL b_Disable_اولویت_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Thread_اولویت_Boost(HANDLE hThread,PBOOL p_Disable_اولویت_Boost);
  WINBASEAPI صحيح WINAPI Get_Thread_اولویت(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lp_Creation_زمان,LPFILETIME lp_Exit_زمان,LPFILETIME lp_Kernel_زمان,LPFILETIME lp_User_زمان);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dw_Exit_کد);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dw_Exit_کد);
  WINBASEAPI WINBOOL WINAPI Get_Exit_کد_Thread(HANDLE hThread,LPDWORD lp_Exit_کد);
  WINBASEAPI WINBOOL WINAPI Get_Thread_Selector_مدخل(HANDLE hThread,DWORD dwSelector,LPLDT_مدخل lp_Selector_مدخل);
  WINBASEAPI EXECUTION_STATE WINAPI مجموعه_Thread_Execution_State(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI Get_آخرین_Error(VOID);
  WINBASEAPI VOID WINAPI مجموعه_آخرین_Error(DWORD dw_Err_کد);

#اگر_تعریف_نشده RC_INVOKED
#اگر_تعریف_شده WINBASE_DECLARE_RESTORE_آخرین_ERROR
  WINBASEAPI VOID WINAPI Restore_آخرین_Error(DWORD dw_Err_کد);

  تعريفنوع VOID (WINAPI *PRESTORE_آخرین_ERROR)(DWORD);

#تعریف_کن RESTORE_آخرین_ERROR_NAME_A "RestoreLastError"
#تعریف_کن RESTORE_آخرین_ERROR_NAME_W L"RestoreLastError"
#تعریف_کن RESTORE_آخرین_ERROR_NAME متن_3("RestoreLastError")
#پایان_اگر
#پایان_اگر

#تعریف_کن HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->داخلی)!=وضعیت_PENDING)

  WINBASEAPI WINBOOL WINAPI Get_Overlapped_نتیجه(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lp_عدد_از_بایتها_Transferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI Create_Io_Completion_پورت(HANDLE FileHandle,HANDLE Existing_Completion_پورت,ULONG_PTR Completion_کلید,DWORD عدد_از_Concurrent_نخها);
  WINBASEAPI WINBOOL WINAPI Get_Queued_Completion_وضعیت(HANDLE Completion_پورت,LPDWORD lp_عدد_از_بایتها_Transferred,PULONG_PTR lp_Completion_کلید,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI Post_Queued_Completion_وضعیت(HANDLE Completion_پورت,DWORD dw_عدد_از_بایتها_Transferred,ULONG_PTR dw_Completion_کلید,LPOVERLAPPED lpOverlapped);

#تعریف_کن SEM_FAILCRITICALERRORS 0x1
#تعریف_کن SEM_NOGPFAULTERRORBOX 0x2
#تعریف_کن SEM_NOALIGNMENTFAULTEXCEPT 0x4
#تعریف_کن SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI مجموعه_Error_نما(UINT u_نما);
  WINBASEAPI WINBOOL WINAPI Read_Process_حافظه(HANDLE hProcess,LPCVOID lp_پایه_آدرس,LPVOID lp_میانگیر,اندازه_T n_اندازه,اندازه_T *lp_عدد_از_بایتها_Read);
  WINBASEAPI WINBOOL WINAPI Write_Process_حافظه(HANDLE hProcess,LPVOID lp_پایه_آدرس,LPCVOID lp_میانگیر,اندازه_T n_اندازه,اندازه_T *lp_عدد_از_بایتها_Written);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI مجموعه_Thread_Context(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  تعريفنوع VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI صف_User_APC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dw_داده);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dw_Continue_وضعیت);
  WINBASEAPI WINBOOL WINAPI Debug_فعال_Process(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_فعال_Process_Stop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_مجموعه_Process_Kill_On_Exit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI Initialize_Critical_Section_And_Spin_شمار(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_شمار);
  WINBASEAPI DWORD WINAPI مجموعه_Critical_Section_Spin_شمار(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_شمار);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI مجموعه_Event(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG l_Release_شمار,LPLONG lp_قبلی_شمار);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI Wait_For_مضرب_Objects(DWORD n_شمار,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI بارگیری_Resource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI Init_Atom_جدول(DWORD n_اندازه);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI مجموعه_Handle_شمار(UINT u_عدد);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI قفل_File(HANDLE hFile,DWORD dw_File_جابه_جایی_کم,DWORD dw_File_جابه_جایی_بالا,DWORD n_عدد_از_بایتها_مقصد_قفل_کم,DWORD n_عدد_از_بایتها_مقصد_قفل_بالا);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dw_File_جابه_جایی_کم,DWORD dw_File_جابه_جایی_بالا,DWORD n_عدد_از_بایتها_مقصد_Unlock_کم,DWORD n_عدد_از_بایتها_مقصد_Unlock_بالا);
  WINBASEAPI WINBOOL WINAPI قفل_File_Ex(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD n_عدد_از_بایتها_مقصد_قفل_کم,DWORD n_عدد_از_بایتها_مقصد_قفل_بالا,LPOVERLAPPED lpOverlapped);

#تعریف_کن LOCKFILE_FAIL_IMMEDIATELY 0x1
#تعریف_کن LOCKFILE_EXCLUSIVE_قفل 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD n_عدد_از_بایتها_مقصد_Unlock_کم,DWORD n_عدد_از_بایتها_مقصد_Unlock_بالا,LPOVERLAPPED lpOverlapped);

  تعريفنوع بنية _BY_HANDLE_FILE_INFORMATION {
    DWORD dw_File_صفات;
    FILETIME ft_Creation_زمان;
    FILETIME ft_آخرین_Access_زمان;
    FILETIME ft_آخرین_Write_زمان;
    DWORD dw_Volume_Serial_عدد;
    DWORD n_File_اندازه_بالا;
    DWORD n_File_اندازه_کم;
    DWORD n_عدد_از_Links;
    DWORD n_File_شاخص_بالا;
    DWORD n_File_شاخص_کم;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#اگر_تعریف_شده UNICODE
#تعریف_کن مجموعه_File_Short_Name مجموعه_File_Short_Name_W
#وإلا
#تعریف_کن مجموعه_File_Short_Name مجموعه_File_Short_Name_A
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI Get_File_اندازه(HANDLE hFile,LPDWORD lp_File_اندازه_بالا);
  WINBASEAPI WINBOOL WINAPI Get_File_اندازه_Ex(HANDLE hFile,PLARGE_INTEGER lp_File_اندازه);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI مجموعه_Std_Handle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lp_میانگیر,DWORD n_عدد_از_بایتها_مقصد_Write,LPDWORD lp_عدد_از_بایتها_Written,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lp_میانگیر,DWORD n_عدد_از_بایتها_مقصد_Read,LPDWORD lp_عدد_از_بایتها_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dw_Io_Control_کد,LPVOID lp_درون_میانگیر,DWORD n_درون_میانگیر_اندازه,LPVOID lp_بیرون_میانگیر,DWORD n_بیرون_میانگیر_اندازه,LPDWORD lp_بایتها_Returned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI مجموعه_پیام_انتظار_Indicator(HANDLE h_پیام_Indicator,ULONG ul_پیام_شمار);
  WINBASEAPI WINBOOL WINAPI مجموعه_انتها_از_File(HANDLE hFile);
  WINBASEAPI DWORD WINAPI مجموعه_File_اشاره_گر(HANDLE hFile,LONG l_فاصله_مقصد_Move,PLONG lp_فاصله_مقصد_Move_بالا,DWORD dw_Move_روش);
  WINBASEAPI WINBOOL WINAPI مجموعه_File_اشاره_گر_Ex(HANDLE hFile,LARGE_INTEGER li_فاصله_مقصد_Move,PLARGE_INTEGER lp_New_File_اشاره_گر,DWORD dw_Move_روش);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_Close(HANDLE h_پیدا_کن_File);
  WINBASEAPI WINBOOL WINAPI Get_File_زمان(HANDLE hFile,LPFILETIME lp_Creation_زمان,LPFILETIME lp_آخرین_Access_زمان,LPFILETIME lp_آخرین_Write_زمان);
  WINBASEAPI WINBOOL WINAPI مجموعه_File_زمان(HANDLE hFile,CONST FILETIME *lp_Creation_زمان,CONST FILETIME *lp_آخرین_Access_زمان,CONST FILETIME *lp_آخرین_Write_زمان);
  WINBASEAPI WINBOOL WINAPI مجموعه_File_Valid_داده(HANDLE hFile,LONGLONG Valid_داده_درازی);
  WINBASEAPI WINBOOL WINAPI مجموعه_File_Short_Name_A(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI مجموعه_File_Short_Name_W(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE h_منبع_Process_Handle,HANDLE h_منبع_Handle,HANDLE h_هدف_Process_Handle,LPHANDLE lp_هدف_Handle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI مجموعه_Handle_Information(HANDLE hObject,DWORD dw_ماسک,DWORD dwFlags);

#تعریف_کن HANDLE_FLAG_INHERIT 0x1
#تعریف_کن HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#تعریف_کن HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI بارگیری_Module(LPCSTR lpModuleName,LPVOID lp_Parameter_بلوک);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lp_Cmd_سطر,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI راهاندازی_Comm(HANDLE hFile,DWORD dw_درون_صف,DWORD dw_بیرون_صف);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdw_اندازه);
  WINBASEAPI WINBOOL WINAPI Get_Comm_ماسک(HANDLE hFile,LPDWORD lp_Evt_ماسک);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI Get_Comm_Modem_وضعیت(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI مجموعه_Comm_Break(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI مجموعه_Comm_Config(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dw_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Comm_ماسک(HANDLE hFile,DWORD dw_Evt_ماسک);
  WINBASEAPI WINBOOL WINAPI مجموعه_Comm_State(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI مجموعه_Comm_Timeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,حرف cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lp_Evt_ماسک,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI مجموعه_نوار_Position(HANDLE hDevice,DWORD dw_Position_روش,DWORD dw_افراز,DWORD dw_جابه_جایی_کم,DWORD dw_جابه_جایی_بالا,WINBOOL b_فوری);
  WINBASEAPI DWORD WINAPI Get_نوار_Position(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdw_افراز,LPDWORD lpdw_جابه_جایی_کم,LPDWORD lpdw_جابه_جایی_بالا);
  WINBASEAPI DWORD WINAPI Prepare_نوار(HANDLE hDevice,DWORD dwOperation,WINBOOL b_فوری);
  WINBASEAPI DWORD WINAPI Erase_نوار(HANDLE hDevice,DWORD dwEraseType,WINBOOL b_فوری);
  WINBASEAPI DWORD WINAPI Create_نوار_افراز(HANDLE hDevice,DWORD dw_افراز_روش,DWORD dw_شمار,DWORD dw_اندازه);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dw_Tapemark_شمار,WINBOOL b_فوری);
  WINBASEAPI DWORD WINAPI Get_نوار_وضعیت(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI Get_نوار_Parameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdw_اندازه,LPVOID lp_نوار_Information);

#تعریف_کن GET_نوار_MEDIA_INFORMATION 0
#تعریف_کن GET_نوار_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI مجموعه_نوار_Parameters(HANDLE hDevice,DWORD dwOperation,LPVOID lp_نوار_Information);

#تعریف_کن مجموعه_نوار_MEDIA_INFORMATION 0
#تعریف_کن مجموعه_نوار_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI صحيح WINAPI MulDiv(صحيح n_عدد,صحيح nNumerator,صحيح nDenominator);
  WINBASEAPI VOID WINAPI Get_System_زمان(LPSYSTEMTIME lp_System_زمان);
  WINBASEAPI VOID WINAPI Get_System_زمان_As_File_زمان(LPFILETIME lp_System_زمان_As_File_زمان);
  WINBASEAPI WINBOOL WINAPI مجموعه_System_زمان(CONST SYSTEMTIME *lp_System_زمان);
  WINBASEAPI VOID WINAPI Get_Local_زمان(LPSYSTEMTIME lp_System_زمان);
  WINBASEAPI WINBOOL WINAPI مجموعه_Local_زمان(CONST SYSTEMTIME *lp_System_زمان);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI مجموعه_System_File_Cache_اندازه(اندازه_T Minimum_File_Cache_اندازه,اندازه_T بیشینه_File_Cache_اندازه,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI Get_System_File_Cache_اندازه(PSIZE_T lp_Minimum_File_Cache_اندازه,PSIZE_T lp_بیشینه_File_Cache_اندازه,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdw_Quota_استفاده_شده);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lp_Idle_زمان,LPFILETIME lp_Kernel_زمان,LPFILETIME lp_User_زمان);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  تعريفنوع بنية زمان_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } زمان_ZONE_INFORMATION_2,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#اگر_تعریف_شده UNICODE
#تعریف_کن Format_پیام Format_پیام_W
#وإلا
#تعریف_کن Format_پیام Format_پیام_A
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI System_زمان_مقصد_Tz_Specific_Local_زمان(LPTIME_ZONE_INFORMATION lp_زمان_Zone_Information,LPSYSTEMTIME lp_Universal_زمان,LPSYSTEMTIME lp_Local_زمان);
  WINBASEAPI WINBOOL WINAPI Tz_Specific_Local_زمان_مقصد_System_زمان(LPTIME_ZONE_INFORMATION lp_زمان_Zone_Information,LPSYSTEMTIME lp_Local_زمان,LPSYSTEMTIME lp_Universal_زمان);
  WINBASEAPI DWORD WINAPI Get_زمان_Zone_Information(LPTIME_ZONE_INFORMATION lp_زمان_Zone_Information);
  WINBASEAPI WINBOOL WINAPI مجموعه_زمان_Zone_Information(CONST زمان_ZONE_INFORMATION_2 *lp_زمان_Zone_Information);
  WINBASEAPI WINBOOL WINAPI System_زمان_مقصد_File_زمان(CONST SYSTEMTIME *lp_System_زمان,LPFILETIME lp_File_زمان);
  WINBASEAPI WINBOOL WINAPI File_زمان_مقصد_Local_File_زمان(CONST FILETIME *lp_File_زمان,LPFILETIME lp_Local_File_زمان);
  WINBASEAPI WINBOOL WINAPI Local_File_زمان_مقصد_File_زمان(CONST FILETIME *lp_Local_File_زمان,LPFILETIME lp_File_زمان);
  WINBASEAPI WINBOOL WINAPI File_زمان_مقصد_System_زمان(CONST FILETIME *lp_File_زمان,LPSYSTEMTIME lp_System_زمان);
  WINBASEAPI LONG WINAPI Compare_File_زمان(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI File_زمان_مقصد_Dos_Date_زمان(CONST FILETIME *lp_File_زمان,LPWORD lpFatDate,LPWORD lp_Fat_زمان);
  WINBASEAPI WINBOOL WINAPI Dos_Date_زمان_مقصد_File_زمان(کلمه_3 wFatDate,کلمه_3 w_Fat_زمان,LPFILETIME lp_File_زمان);
  WINBASEAPI DWORD WINAPI Get_Tick_شمار(VOID);
  WINBASEAPI WINBOOL WINAPI مجموعه_System_زمان_Adjustment(DWORD dw_زمان_Adjustment,WINBOOL b_زمان_Adjustment_Disabled);
  WINBASEAPI WINBOOL WINAPI Get_System_زمان_Adjustment(PDWORD lp_زمان_Adjustment,PDWORD lp_زمان_Increment,PBOOL lp_زمان_Adjustment_Disabled);
  WINBASEAPI DWORD WINAPI Format_پیام_A(DWORD dwFlags,LPCVOID lp_منبع,DWORD dw_پیام_Id,DWORD dwLanguageId,LPSTR lp_میانگیر,DWORD n_اندازه,va_list *Arguments);
  WINBASEAPI DWORD WINAPI Format_پیام_W(DWORD dwFlags,LPCVOID lp_منبع,DWORD dw_پیام_Id,DWORD dwLanguageId,LPWSTR lp_میانگیر,DWORD n_اندازه,va_list *Arguments);

#تعریف_کن FORMAT_پیام_ALLOCATE_میانگیر 0x100
#تعریف_کن FORMAT_پیام_IGNORE_INSERTS 0x200
#تعریف_کن FORMAT_پیام_FROM_STRING 0x400
#تعریف_کن FORMAT_پیام_FROM_HMODULE 0x800
#تعریف_کن FORMAT_پیام_FROM_SYSTEM 0x1000
#تعریف_کن FORMAT_پیام_آرگومان_ARRAY 0x2000
#تعریف_کن FORMAT_پیام_MAX_عرض_ماسک 0xff

#اگر_تعریف_شده UNICODE
#تعریف_کن CreateMailslot CreateMailslotW
#تعریف_کن EncryptFile EncryptFileW
#تعریف_کن DecryptFile DecryptFileW
#تعریف_کن File_Encryption_وضعیت File_Encryption_وضعیت_W
#وإلا
#تعریف_کن CreateMailslot CreateMailslotA
#تعریف_کن EncryptFile EncryptFileA
#تعریف_کن DecryptFile DecryptFileA
#تعریف_کن File_Encryption_وضعیت File_Encryption_وضعیت_A
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_صفات lp_Pipe_صفات,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI مجموعه_Named_Pipe_Handle_State(HANDLE hNamedPipe,LPDWORD lp_نما,LPDWORD lp_Max_Collection_شمار,LPDWORD lp_Collect_داده_Timeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lp_بیرون_میانگیر_اندازه,LPDWORD lp_درون_میانگیر_اندازه,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lp_میانگیر,DWORD n_میانگیر_اندازه,LPDWORD lp_بایتها_Read,LPDWORD lp_مجموع_بایتها_Avail,LPDWORD lp_بایتها_چپ_This_پیام);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lp_درون_میانگیر,DWORD n_درون_میانگیر_اندازه,LPVOID lp_بیرون_میانگیر,DWORD n_بیرون_میانگیر_اندازه,LPDWORD lp_بایتها_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD n_Max_پیام_اندازه,DWORD lReadTimeout,LPSECURITY_صفات lp_Security_صفات);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD n_Max_پیام_اندازه,DWORD lReadTimeout,LPSECURITY_صفات lp_Security_صفات);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lp_Max_پیام_اندازه,LPDWORD lp_بعدی_اندازه,LPDWORD lp_پیام_شمار,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI مجموعه_Mailslot_Info(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI Map_View_از_File(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_جابه_جایی_بالا,DWORD dw_File_جابه_جایی_کم,اندازه_T dw_عدد_از_بایتها_مقصد_Map);
  WINBASEAPI WINBOOL WINAPI Flush_View_از_File(LPCVOID lp_پایه_آدرس,اندازه_T dw_عدد_از_بایتها_مقصد_Flush);
  WINBASEAPI WINBOOL WINAPI Unmap_View_از_File(LPCVOID lp_پایه_آدرس);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#تعریف_کن FILE_ENCRYPTABLE 0
#تعریف_کن FILE_IS_ENCRYPTED 1
#تعریف_کن FILE_SYSTEM_ATTR 2
#تعریف_کن FILE_ریشه_DIR 3
#تعریف_کن FILE_SYSTEM_DIR 4
#تعریف_کن FILE_UNKNOWN 5
#تعریف_کن FILE_SYSTEM_NOT_SUPPORT 6
#تعریف_کن FILE_USER_DISALLOWED 7
#تعریف_کن FILE_READ_ONLY 8
#تعریف_کن FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI File_Encryption_وضعیت_A(LPCSTR lpFileName,LPDWORD lp_وضعیت);
  WINADVAPI WINBOOL WINAPI File_Encryption_وضعیت_W(LPCWSTR lpFileName,LPDWORD lp_وضعیت);

#تعریف_کن EFS_USE_RECOVERY_کلیدها (0x1)

  تعريفنوع DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pb_داده,PVOID pvCallbackContext,ULONG ul_درازی);
  تعريفنوع DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pb_داده,PVOID pvCallbackContext,PULONG ul_درازی);

#تعریف_کن CREATE_FOR_IMPORT (1)
#تعریف_کن CREATE_FOR_DIR (2)
#تعریف_کن OVERWRITE_HIDDEN (4)

#اگر_تعریف_شده UNICODE
#تعریف_کن OpenEncryptedFileRaw OpenEncryptedFileRawW
#تعریف_کن lstrcmp lstrcmpW
#تعریف_کن lstrcmpi lstrcmpiW
#تعریف_کن lstrcpyn lstrcpynW
#تعریف_کن lstrcpy lstrcpyW
#تعریف_کن lstrcat lstrcatW
#تعریف_کن lstrlen lstrlenW
#وإلا
#تعریف_کن OpenEncryptedFileRaw OpenEncryptedFileRawA
#تعریف_کن lstrcmp lstrcmpA
#تعریف_کن lstrcmpi lstrcmpiA
#تعریف_کن lstrcpyn lstrcpynA
#تعریف_کن lstrcpy lstrcpyA
#تعریف_کن lstrcat lstrcatA
#تعریف_کن lstrlen lstrlenA
#پایان_اگر

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI صحيح WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,صحيح i_Max_درازی);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,صحيح i_Max_درازی);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI صحيح WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lp_مسیر_Name,صحيح iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lp_مسیر_Name,صحيح iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lp_میانگیر,UINT u_بایتها);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lp_میانگیر,UINT u_بایتها);
  WINBASEAPI دراز WINAPI _hread(HFILE hFile,LPVOID lp_میانگیر,دراز l_بایتها);
  WINBASEAPI دراز WINAPI _hwrite(HFILE hFile,LPCCH lp_میانگیر,دراز l_بایتها);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG l_جابه_جایی,صحيح iOrigin);
  WINADVAPI WINBOOL WINAPI Is_متن_Unicode(CONST VOID *lpv,صحيح i_اندازه,LPINT lpi_نتیجه);

#تعریف_کن FLS_بیرون_از_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI Fls_Get_مقدار(DWORD dw_Fls_شاخص);
  WINBASEAPI WINBOOL WINAPI Fls_مجموعه_مقدار(DWORD dw_Fls_شاخص,PVOID lp_Fls_داده);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dw_Fls_شاخص);

#تعریف_کن TLS_بیرون_از_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI Tls_Get_مقدار(DWORD dw_Tls_شاخص);
  WINBASEAPI WINBOOL WINAPI Tls_مجموعه_مقدار(DWORD dw_Tls_شاخص,LPVOID lp_Tls_مقدار);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dw_Tls_شاخص);

  تعريفنوع VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dw_Error_کد,DWORD dw_عدد_از_بایتها_Transfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI Wait_For_مضرب_Objects_Ex(DWORD n_شمار,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE h_Object_مقصد_Signal,HANDLE h_Object_مقصد_Wait_On,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lp_میانگیر,DWORD n_عدد_از_بایتها_مقصد_Read,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lp_میانگیر,DWORD n_عدد_از_بایتها_مقصد_Write,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lp_میانگیر,DWORD n_عدد_از_بایتها_مقصد_Read,LPDWORD lp_عدد_از_بایتها_Read,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dw_کم_بایتها_مقصد_Seek,DWORD dw_بالا_بایتها_مقصد_Seek,LPDWORD lpdw_کم_Byte_Seeked,LPDWORD lpdw_بالا_Byte_Seeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lp_میانگیر,DWORD n_عدد_از_بایتها_مقصد_Write,LPDWORD lp_عدد_از_بایتها_Written,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  تعريفنوع بنية WIN32_جریان_ID {
    DWORD dw_جریان_Id;
    DWORD dw_جریان_صفات;
    LARGE_INTEGER اندازه_3;
    DWORD dw_جریان_Name_اندازه;
    WCHAR c_جریان_Name[ANYSIZE_ARRAY];
  } WIN32_جریان_ID_2,*LPWIN32_جریان_ID;

#تعریف_کن BACKUP_INVALID 0x0
#تعریف_کن BACKUP_داده 0x1
#تعریف_کن BACKUP_EA_داده 0x2
#تعریف_کن BACKUP_SECURITY_داده 0x3
#تعریف_کن BACKUP_ALTERNATE_داده 0x4
#تعریف_کن BACKUP_LINK 0x5
#تعریف_کن BACKUP_PROPERTY_داده 0x6
#تعریف_کن BACKUP_OBJECT_ID 0x7
#تعریف_کن BACKUP_REPARSE_داده 0x8
#تعریف_کن BACKUP_SPARSE_بلوک 0x9

#تعریف_کن جریان_نرمال_ATTRIBUTE 0x0
#تعریف_کن جریان_MODIFIED_WHEN_READ 0x1
#تعریف_کن جریان_شامل_است_SECURITY 0x2
#تعریف_کن جریان_شامل_است_PROPERTIES 0x4
#تعریف_کن جریان_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_عدد_از_بایتها_مقصد_Read,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_عدد_از_بایتها_مقصد_Write,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#تعریف_کن STARTF_USESHOWWINDOW 0x1
#تعریف_کن STARTF_USESIZE 0x2
#تعریف_کن STARTF_USEPOSITION 0x4
#تعریف_کن STARTF_USECOUNTCHARS 0x8
#تعریف_کن STARTF_USEFILLATTRIBUTE 0x10
#تعریف_کن STARTF_RUNFULLSCREEN 0x20
#تعریف_کن STARTF_FORCEONFEEDBACK 0x40
#تعریف_کن STARTF_FORCEOFFFEEDBACK 0x80
#تعریف_کن STARTF_USESTDHANDLES 0x100

#تعریف_کن STARTF_USEHOTKEY 0x200

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
    کلمه_3 w_Show_پنجره;
    کلمه_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_درون_داد;
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
    کلمه_3 w_Show_پنجره;
    کلمه_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_درون_داد;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#اگر_تعریف_شده UNICODE
  تعريفنوع STARTUPINFOW STARTUPINFO;
  تعريفنوع LPSTARTUPINFOW LPSTARTUPINFO;
#وإلا
  تعريفنوع STARTUPINFOA STARTUPINFO;
  تعريفنوع LPSTARTUPINFOA LPSTARTUPINFO;
#پایان_اگر

#تعریف_کن SHUTDOWN_NORETRY 0x1

  تعريفنوع بنية WIN32_پیدا_کن_DATAA {
    DWORD dw_File_صفات;
    FILETIME ft_Creation_زمان;
    FILETIME ft_آخرین_Access_زمان;
    FILETIME ft_آخرین_Write_زمان;
    DWORD n_File_اندازه_بالا;
    DWORD n_File_اندازه_کم;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_مسیر];
    CHAR cAlternateFileName[14];
  } WIN32_پیدا_کن_DATAA_2,*PWIN32_پیدا_کن_DATAA,*LPWIN32_پیدا_کن_DATAA;

  تعريفنوع بنية WIN32_پیدا_کن_DATAW {
    DWORD dw_File_صفات;
    FILETIME ft_Creation_زمان;
    FILETIME ft_آخرین_Access_زمان;
    FILETIME ft_آخرین_Write_زمان;
    DWORD n_File_اندازه_بالا;
    DWORD n_File_اندازه_کم;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_مسیر];
    WCHAR cAlternateFileName[14];
  } WIN32_پیدا_کن_DATAW_2,*PWIN32_پیدا_کن_DATAW,*LPWIN32_پیدا_کن_DATAW;

#اگر_تعریف_شده UNICODE
  تعريفنوع WIN32_پیدا_کن_DATAW_2 WIN32_پیدا_کن_داده;
  تعريفنوع PWIN32_پیدا_کن_DATAW PWIN32_پیدا_کن_داده;
  تعريفنوع LPWIN32_پیدا_کن_DATAW LPWIN32_پیدا_کن_داده;
#وإلا
  تعريفنوع WIN32_پیدا_کن_DATAA_2 WIN32_پیدا_کن_داده;
  تعريفنوع PWIN32_پیدا_کن_DATAA PWIN32_پیدا_کن_داده;
  تعريفنوع LPWIN32_پیدا_کن_DATAA LPWIN32_پیدا_کن_داده;
#پایان_اگر

  تعريفنوع بنية WIN32_FILE_ATTRIBUTE_داده {
    DWORD dw_File_صفات;
    FILETIME ft_Creation_زمان;
    FILETIME ft_آخرین_Access_زمان;
    FILETIME ft_آخرین_Write_زمان;
    DWORD n_File_اندازه_بالا;
    DWORD n_File_اندازه_کم;
  } WIN32_FILE_ATTRIBUTE_داده_2,*LPWIN32_FILE_ATTRIBUTE_داده;

#اگر_تعریف_شده UNICODE
#تعریف_کن CreateMutex CreateMutexW
#تعریف_کن OpenMutex OpenMutexW
#تعریف_کن CreateEvent CreateEventW
#تعریف_کن OpenEvent OpenEventW
#تعریف_کن CreateSemaphore CreateSemaphoreW
#تعریف_کن OpenSemaphore OpenSemaphoreW
#وإلا
#تعریف_کن CreateMutex CreateMutexA
#تعریف_کن OpenMutex OpenMutexA
#تعریف_کن CreateEvent CreateEventA
#تعریف_کن OpenEvent OpenEventA
#تعریف_کن CreateSemaphore CreateSemaphoreA
#تعریف_کن OpenSemaphore OpenSemaphoreA
#پایان_اگر

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_صفات lp_Mutex_صفات,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_صفات lp_Mutex_صفات,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_صفات lp_Event_صفات,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_صفات lp_Event_صفات,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_صفات lp_Semaphore_صفات,LONG l_Initial_شمار,LONG l_بیشینه_شمار,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_صفات lp_Semaphore_صفات,LONG l_Initial_شمار,LONG l_بیشینه_شمار,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  تعريفنوع VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lp_Arg_مقصد_Completion_Routine,DWORD dw_Timer_کم_مقدار,DWORD dw_Timer_بالا_مقدار);

#اگر_تعریف_شده UNICODE
#تعریف_کن CreateWaitableTimer CreateWaitableTimerW
#تعریف_کن OpenWaitableTimer OpenWaitableTimerW
#تعریف_کن CreateFileMapping CreateFileMappingW
#تعریف_کن OpenFileMapping OpenFileMappingW
#تعریف_کن Get_Logical_Drive_رشتهها Get_Logical_Drive_رشتهها_W
#تعریف_کن بارگیری_Library بارگیری_Library_W
#تعریف_کن بارگیری_Library_Ex بارگیری_Library_Ex_W
#تعریف_کن GetModuleFileName GetModuleFileNameW
#تعریف_کن GetModuleHandle GetModuleHandleW
#وإلا
#تعریف_کن CreateWaitableTimer CreateWaitableTimerA
#تعریف_کن OpenWaitableTimer OpenWaitableTimerA
#تعریف_کن CreateFileMapping CreateFileMappingA
#تعریف_کن OpenFileMapping OpenFileMappingA
#تعریف_کن Get_Logical_Drive_رشتهها Get_Logical_Drive_رشتهها_A
#تعریف_کن بارگیری_Library بارگیری_Library_A
#تعریف_کن بارگیری_Library_Ex بارگیری_Library_Ex_A
#تعریف_کن GetModuleFileName GetModuleFileNameA
#تعریف_کن GetModuleHandle GetModuleHandleA
#پایان_اگر

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_صفات lp_Timer_صفات,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_صفات lp_Timer_صفات,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI مجموعه_Waitable_Timer(HANDLE hTimer,ثابت LARGE_INTEGER *lp_Due_زمان,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lp_Arg_مقصد_Completion_Routine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_صفات lp_File_Mapping_صفات,DWORD flProtect,DWORD dw_بیشینه_اندازه_بالا,DWORD dw_بیشینه_اندازه_کم,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_صفات lp_File_Mapping_صفات,DWORD flProtect,DWORD dw_بیشینه_اندازه_بالا,DWORD dw_بیشینه_اندازه_کم,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_رشتهها_A(DWORD n_میانگیر_درازی,LPSTR lp_میانگیر);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_رشتهها_W(DWORD n_میانگیر_درازی,LPWSTR lp_میانگیر);

  تعريفنوع تعداد حافظه_RESOURCE_NOTIFICATION_TYPE {
    کم_حافظه_Resource_Notification,بالا_حافظه_Resource_Notification
  } حافظه_RESOURCE_NOTIFICATION_TYPE_2;

  WINBASEAPI HANDLE WINAPI Create_حافظه_Resource_Notification(حافظه_RESOURCE_NOTIFICATION_TYPE_2 NotificationType);
  WINBASEAPI WINBOOL WINAPI Query_حافظه_Resource_Notification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI بارگیری_Library_A(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI بارگیری_Library_W(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI بارگیری_Library_Ex_A(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI بارگیری_Library_Ex_W(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#تعریف_کن DONT_RESOLVE_DLL_REFERENCES 0x1
#تعریف_کن بارگیری_LIBRARY_AS_DATAFILE 0x2
#تعریف_کن بارگیری_WITH_ALTERED_جستجو_مسیر 0x8
#تعریف_کن بارگیری_IGNORE_کد_AUTHZ_LEVEL 0x10
#تعریف_کن بارگیری_LIBRARY_AS_IMAGE_RESOURCE 0x20
#تعریف_کن بارگیری_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40
#تعریف_کن بارگیری_LIBRARY_REQUIRE_SIGNED_هدف 0x80
#تعریف_کن بارگیری_LIBRARY_جستجو_DLL_بارگیری_DIR 0x100
#تعریف_کن بارگیری_LIBRARY_جستجو_APPLICATION_DIR 0x200
#تعریف_کن بارگیری_LIBRARY_جستجو_USER_DIRS 0x400
#تعریف_کن بارگیری_LIBRARY_جستجو_SYSTEM32 0x800
#تعریف_کن بارگیری_LIBRARY_جستجو_DEFAULT_DIRS 0x1000
#تعریف_کن بارگیری_LIBRARY_امن_CURRENT_DIRS 0x2000

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD n_اندازه);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#اگر_تعریف_نشده RC_INVOKED
#تعریف_کن GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#تعریف_کن GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#تعریف_کن GET_MODULE_HANDLE_EX_FLAG_FROM_آدرس (0x4)

  تعريفنوع WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  تعريفنوع WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#اگر_تعریف_شده UNICODE
#تعریف_کن PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#تعریف_کن GetModuleHandleEx GetModuleHandleExW
#وإلا
#تعریف_کن PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#تعریف_کن GetModuleHandleEx GetModuleHandleExA
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن Need_Current_Directory_For_Exe_مسیر Need_Current_Directory_For_Exe_مسیر_W
#تعریف_کن CreateProcess CreateProcessW
#تعریف_کن FatalAppExit FatalAppExitW
#تعریف_کن GetStartupInfo GetStartupInfoW
#تعریف_کن Get_Command_سطر Get_Command_سطر_W
#تعریف_کن GetEnvironmentVariable GetEnvironmentVariableW
#تعریف_کن مجموعه_Environment_Variable مجموعه_Environment_Variable_W
#تعریف_کن Expand_Environment_رشتهها Expand_Environment_رشتهها_W
#تعریف_کن GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#تعریف_کن مجموعه_Firmware_Environment_Variable مجموعه_Firmware_Environment_Variable_W
#تعریف_کن OutputDebugString OutputDebugStringW
#تعریف_کن پیدا_کن_Resource پیدا_کن_Resource_W
#تعریف_کن پیدا_کن_Resource_Ex پیدا_کن_Resource_Ex_W
#وإلا
#تعریف_کن Need_Current_Directory_For_Exe_مسیر Need_Current_Directory_For_Exe_مسیر_A
#تعریف_کن CreateProcess CreateProcessA
#تعریف_کن FatalAppExit FatalAppExitA
#تعریف_کن GetStartupInfo GetStartupInfoA
#تعریف_کن Get_Command_سطر Get_Command_سطر_A
#تعریف_کن GetEnvironmentVariable GetEnvironmentVariableA
#تعریف_کن مجموعه_Environment_Variable مجموعه_Environment_Variable_A
#تعریف_کن Expand_Environment_رشتهها Expand_Environment_رشتهها_A
#تعریف_کن GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#تعریف_کن مجموعه_Firmware_Environment_Variable مجموعه_Firmware_Environment_Variable_A
#تعریف_کن OutputDebugString OutputDebugStringA
#تعریف_کن پیدا_کن_Resource پیدا_کن_Resource_A
#تعریف_کن پیدا_کن_Resource_Ex پیدا_کن_Resource_Ex_A
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_مسیر_A(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_مسیر_W(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lp_Command_سطر,LPSECURITY_صفات lp_Process_صفات,LPSECURITY_صفات lp_Thread_صفات,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lp_Command_سطر,LPSECURITY_صفات lp_Process_صفات,LPSECURITY_صفات lp_Thread_صفات,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI جمع_کن_Local_Alternate_Computer_Name_A(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI جمع_کن_Local_Alternate_Computer_Name_W(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI مجموعه_Process_Shutdown_Parameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI Get_Process_نسخه(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lp_پیام_متن);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lp_پیام_متن);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI Get_Command_سطر_A(VOID);
  WINBASEAPI LPWSTR WINAPI Get_Command_سطر_W(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lp_میانگیر,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lp_میانگیر,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Environment_Variable_A(LPCSTR lpName,LPCSTR lp_مقدار);
  WINBASEAPI WINBOOL WINAPI مجموعه_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lp_مقدار);
  WINBASEAPI DWORD WINAPI Expand_Environment_رشتهها_A(LPCSTR lpSrc,LPSTR lpDst,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI Expand_Environment_رشتهها_W(LPCWSTR lpSrc,LPWSTR lpDst,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_میانگیر,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_میانگیر,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Firmware_Environment_Variable_A(LPCSTR lpName,LPCSTR lpGuid,PVOID p_مقدار,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Firmware_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_مقدار,DWORD n_اندازه);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI پیدا_کن_Resource_A(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI پیدا_کن_Resource_W(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI پیدا_کن_Resource_Ex_A(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,کلمه_3 wLanguage);
  WINBASEAPI HRSRC WINAPI پیدا_کن_Resource_Ex_W(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,کلمه_3 wLanguage);

#اگر_تعریف_شده UNICODE
#تعریف_کن ENUMRESTYPEPROC ENUMRESTYPEPROCW
#تعریف_کن ENUMRESNAMEPROC ENUMRESNAMEPROCW
#تعریف_کن ENUMRESLANGPROC ENUMRESLANGPROCW
#تعریف_کن EnumResourceTypes EnumResourceTypesW
#تعریف_کن Enum_Resource_نامها Enum_Resource_نامها_W
#تعریف_کن EnumResourceLanguages EnumResourceLanguagesW
#تعریف_کن BeginUpdateResource BeginUpdateResourceW
#تعریف_کن UpdateResource UpdateResourceW
#تعریف_کن انتها_Update_Resource انتها_Update_Resource_W
#تعریف_کن Global_جمع_کن_Atom Global_جمع_کن_Atom_W
#تعریف_کن Global_پیدا_کن_Atom Global_پیدا_کن_Atom_W
#تعریف_کن GlobalGetAtomName GlobalGetAtomNameW
#تعریف_کن جمع_کن_Atom جمع_کن_Atom_W
#تعریف_کن پیدا_کن_Atom پیدا_کن_Atom_W
#تعریف_کن GetAtomName GetAtomNameW
#تعریف_کن GetProfileInt GetProfileIntW
#تعریف_کن GetProfileString GetProfileStringW
#تعریف_کن WriteProfileString WriteProfileStringW
#تعریف_کن GetProfileSection GetProfileSectionW
#تعریف_کن WriteProfileSection WriteProfileSectionW
#تعریف_کن Get_خصوصی_Profile_Int Get_خصوصی_Profile_Int_W
#تعریف_کن Get_خصوصی_Profile_String Get_خصوصی_Profile_String_W
#تعریف_کن Write_خصوصی_Profile_String Write_خصوصی_Profile_String_W
#تعریف_کن Get_خصوصی_Profile_Section Get_خصوصی_Profile_Section_W
#تعریف_کن Write_خصوصی_Profile_Section Write_خصوصی_Profile_Section_W
#تعریف_کن Get_خصوصی_Profile_Section_نامها Get_خصوصی_Profile_Section_نامها_W
#تعریف_کن Get_خصوصی_Profile_Struct Get_خصوصی_Profile_Struct_W
#تعریف_کن Write_خصوصی_Profile_Struct Write_خصوصی_Profile_Struct_W
#تعریف_کن GetDriveType GetDriveTypeW
#تعریف_کن GetSystemDirectory GetSystemDirectoryW
#تعریف_کن Get_موقت_مسیر Get_موقت_مسیر_W
#تعریف_کن Get_موقت_File_Name Get_موقت_File_Name_W
#تعریف_کن GetWindowsDirectory GetWindowsDirectoryW
#تعریف_کن GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#تعریف_کن جمع_کن_Local_Alternate_Computer_Name جمع_کن_Local_Alternate_Computer_Name_W
#وإلا
#تعریف_کن ENUMRESTYPEPROC ENUMRESTYPEPROCA
#تعریف_کن ENUMRESNAMEPROC ENUMRESNAMEPROCA
#تعریف_کن ENUMRESLANGPROC ENUMRESLANGPROCA
#تعریف_کن EnumResourceTypes EnumResourceTypesA
#تعریف_کن Enum_Resource_نامها Enum_Resource_نامها_A
#تعریف_کن EnumResourceLanguages EnumResourceLanguagesA
#تعریف_کن BeginUpdateResource BeginUpdateResourceA
#تعریف_کن UpdateResource UpdateResourceA
#تعریف_کن انتها_Update_Resource انتها_Update_Resource_A
#تعریف_کن Global_جمع_کن_Atom Global_جمع_کن_Atom_A
#تعریف_کن Global_پیدا_کن_Atom Global_پیدا_کن_Atom_A
#تعریف_کن GlobalGetAtomName GlobalGetAtomNameA
#تعریف_کن جمع_کن_Atom جمع_کن_Atom_A
#تعریف_کن پیدا_کن_Atom پیدا_کن_Atom_A
#تعریف_کن GetAtomName GetAtomNameA
#تعریف_کن GetProfileInt GetProfileIntA
#تعریف_کن GetProfileString GetProfileStringA
#تعریف_کن WriteProfileString WriteProfileStringA
#تعریف_کن GetProfileSection GetProfileSectionA
#تعریف_کن WriteProfileSection WriteProfileSectionA
#تعریف_کن Get_خصوصی_Profile_Int Get_خصوصی_Profile_Int_A
#تعریف_کن Get_خصوصی_Profile_String Get_خصوصی_Profile_String_A
#تعریف_کن Write_خصوصی_Profile_String Write_خصوصی_Profile_String_A
#تعریف_کن Get_خصوصی_Profile_Section Get_خصوصی_Profile_Section_A
#تعریف_کن Write_خصوصی_Profile_Section Write_خصوصی_Profile_Section_A
#تعریف_کن Get_خصوصی_Profile_Section_نامها Get_خصوصی_Profile_Section_نامها_A
#تعریف_کن Get_خصوصی_Profile_Struct Get_خصوصی_Profile_Struct_A
#تعریف_کن Write_خصوصی_Profile_Struct Write_خصوصی_Profile_Struct_A
#تعریف_کن GetDriveType GetDriveTypeA
#تعریف_کن GetSystemDirectory GetSystemDirectoryA
#تعریف_کن Get_موقت_مسیر Get_موقت_مسیر_A
#تعریف_کن Get_موقت_File_Name Get_موقت_File_Name_A
#تعریف_کن GetWindowsDirectory GetWindowsDirectoryA
#تعریف_کن GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#تعریف_کن جمع_کن_Local_Alternate_Computer_Name جمع_کن_Local_Alternate_Computer_Name_A
#پایان_اگر

  تعريفنوع WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,کلمه_3 wLanguage,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,کلمه_3 wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_نامها_A(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_نامها_W(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,کلمه_3 wLanguage,LPVOID lp_داده,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,کلمه_3 wLanguage,LPVOID lp_داده,DWORD cb);
  WINBASEAPI WINBOOL WINAPI انتها_Update_Resource_A(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI انتها_Update_Resource_W(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI Global_جمع_کن_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_جمع_کن_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI Global_پیدا_کن_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_پیدا_کن_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lp_میانگیر,صحيح n_اندازه);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lp_میانگیر,صحيح n_اندازه);
  WINBASEAPI ATOM WINAPI جمع_کن_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI جمع_کن_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI پیدا_کن_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI پیدا_کن_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lp_میانگیر,صحيح n_اندازه);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lp_میانگیر,صحيح n_اندازه);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lp_کلید_Name,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lp_کلید_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lp_کلید_Name,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI Get_خصوصی_Profile_Int_A(LPCSTR lpAppName,LPCSTR lp_کلید_Name,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI Get_خصوصی_Profile_Int_W(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_خصوصی_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_کلید_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_اندازه,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_خصوصی_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_اندازه,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_خصوصی_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_کلید_Name,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_خصوصی_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_خصوصی_Profile_Section_A(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_اندازه,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_خصوصی_Profile_Section_W(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_اندازه,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_خصوصی_Profile_Section_A(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_خصوصی_Profile_Section_W(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_خصوصی_Profile_Section_نامها_A(LPSTR lpsz_Return_میانگیر,DWORD n_اندازه,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_خصوصی_Profile_Section_نامها_W(LPWSTR lpsz_Return_میانگیر,DWORD n_اندازه,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Get_خصوصی_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_کلید,LPVOID lpStruct,UINT u_اندازه_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Get_خصوصی_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_کلید,LPVOID lpStruct,UINT u_اندازه_Struct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_خصوصی_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_کلید,LPVOID lpStruct,UINT u_اندازه_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_خصوصی_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_کلید,LPVOID lpStruct,UINT u_اندازه_Struct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lp_ریشه_مسیر_Name);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lp_ریشه_مسیر_Name);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lp_میانگیر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lp_میانگیر,UINT u_اندازه);
  WINBASEAPI DWORD WINAPI Get_موقت_مسیر_A(DWORD n_میانگیر_درازی,LPSTR lp_میانگیر);
  WINBASEAPI DWORD WINAPI Get_موقت_مسیر_W(DWORD n_میانگیر_درازی,LPWSTR lp_میانگیر);
  WINBASEAPI UINT WINAPI Get_موقت_File_Name_A(LPCSTR lp_مسیر_Name,LPCSTR lp_پیشوند_String,UINT uUnique,LPSTR lp_موقت_File_Name);
  WINBASEAPI UINT WINAPI Get_موقت_File_Name_W(LPCWSTR lp_مسیر_Name,LPCWSTR lp_پیشوند_String,UINT uUnique,LPWSTR lp_موقت_File_Name);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lp_میانگیر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lp_میانگیر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lp_میانگیر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lp_میانگیر,UINT u_اندازه);

#اگر_تعریف_نشده RC_INVOKED
#اگر_تعریف_شده UNICODE
#تعریف_کن GetSystemWow64Directory GetSystemWow64DirectoryW
#وإلا
#تعریف_کن GetSystemWow64Directory GetSystemWow64DirectoryA
#پایان_اگر

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lp_میانگیر,UINT u_اندازه);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lp_میانگیر,UINT u_اندازه);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *Old_مقدار);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID Ol_مقدار);

  تعريفنوع UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lp_میانگیر,UINT u_اندازه);
  تعريفنوع UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lp_میانگیر,UINT u_اندازه);

#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T متن_3("GetSystemWow64DirectoryA")
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T متن_3("GetSystemWow64DirectoryW")

#اگر_تعریف_شده UNICODE
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#وإلا
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#تعریف_کن GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن مجموعه_Current_Directory مجموعه_Current_Directory_W
#تعریف_کن GetCurrentDirectory GetCurrentDirectoryW
#تعریف_کن مجموعه_Dll_Directory مجموعه_Dll_Directory_W
#تعریف_کن GetDllDirectory GetDllDirectoryW
#تعریف_کن GetDiskFreeSpace GetDiskFreeSpaceW
#تعریف_کن GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#تعریف_کن CreateDirectory CreateDirectoryW
#تعریف_کن CreateDirectoryEx CreateDirectoryExW
#تعریف_کن RemoveDirectory RemoveDirectoryW
#تعریف_کن Get_پر_مسیر_Name Get_پر_مسیر_Name_W
#تعریف_کن DefineDosDevice DefineDosDeviceW
#تعریف_کن QueryDosDevice QueryDosDeviceW
#تعریف_کن CreateFile CreateFileW
#تعریف_کن مجموعه_File_صفات مجموعه_File_صفات_W
#تعریف_کن Get_File_صفات Get_File_صفات_W
#وإلا
#تعریف_کن مجموعه_Current_Directory مجموعه_Current_Directory_A
#تعریف_کن GetCurrentDirectory GetCurrentDirectoryA
#تعریف_کن مجموعه_Dll_Directory مجموعه_Dll_Directory_A
#تعریف_کن GetDllDirectory GetDllDirectoryA
#تعریف_کن GetDiskFreeSpace GetDiskFreeSpaceA
#تعریف_کن GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#تعریف_کن CreateDirectory CreateDirectoryA
#تعریف_کن CreateDirectoryEx CreateDirectoryExA
#تعریف_کن RemoveDirectory RemoveDirectoryA
#تعریف_کن Get_پر_مسیر_Name Get_پر_مسیر_Name_A
#تعریف_کن DefineDosDevice DefineDosDeviceA
#تعریف_کن QueryDosDevice QueryDosDeviceA
#تعریف_کن CreateFile CreateFileA
#تعریف_کن مجموعه_File_صفات مجموعه_File_صفات_A
#تعریف_کن Get_File_صفات Get_File_صفات_A
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI مجموعه_Current_Directory_A(LPCSTR lp_مسیر_Name);
  WINBASEAPI WINBOOL WINAPI مجموعه_Current_Directory_W(LPCWSTR lp_مسیر_Name);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD n_میانگیر_درازی,LPSTR lp_میانگیر);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD n_میانگیر_درازی,LPWSTR lp_میانگیر);
  WINBASEAPI WINBOOL WINAPI مجموعه_Dll_Directory_A(LPCSTR lp_مسیر_Name);
  WINBASEAPI WINBOOL WINAPI مجموعه_Dll_Directory_W(LPCWSTR lp_مسیر_Name);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD n_میانگیر_درازی,LPSTR lp_میانگیر);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD n_میانگیر_درازی,LPWSTR lp_میانگیر);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lp_ریشه_مسیر_Name,LPDWORD lp_Sectors_در_هر_Cluster,LPDWORD lp_بایتها_در_هر_Sector,LPDWORD lp_عدد_از_Free_Clusters,LPDWORD lp_مجموع_عدد_از_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lp_ریشه_مسیر_Name,LPDWORD lp_Sectors_در_هر_Cluster,LPDWORD lp_بایتها_در_هر_Sector,LPDWORD lp_عدد_از_Free_Clusters,LPDWORD lp_مجموع_عدد_از_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lp_Free_بایتها_موجود_مقصد_Caller,PULARGE_INTEGER lp_مجموع_عدد_از_بایتها,PULARGE_INTEGER lp_مجموع_عدد_از_Free_بایتها);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lp_Free_بایتها_موجود_مقصد_Caller,PULARGE_INTEGER lp_مجموع_عدد_از_بایتها,PULARGE_INTEGER lp_مجموع_عدد_از_Free_بایتها);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lp_مسیر_Name,LPSECURITY_صفات lp_Security_صفات);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lp_مسیر_Name,LPSECURITY_صفات lp_Security_صفات);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_صفات lp_Security_صفات);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_صفات lp_Security_صفات);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lp_مسیر_Name);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lp_مسیر_Name);
  WINBASEAPI DWORD WINAPI Get_پر_مسیر_Name_A(LPCSTR lpFileName,DWORD n_میانگیر_درازی,LPSTR lp_میانگیر,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI Get_پر_مسیر_Name_W(LPCWSTR lpFileName,DWORD n_میانگیر_درازی,LPWSTR lp_میانگیر,LPWSTR *lpFilePart);

#تعریف_کن DDD_RAW_هدف_مسیر 0x1
#تعریف_کن DDD_REMOVE_DEFINITION 0x2
#تعریف_کن DDD_EXACT_تطابق_ON_REMOVE 0x4
#تعریف_کن DDD_NO_پخش_SYSTEM 0x8
#تعریف_کن DDD_LUID_پخش_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lp_هدف_مسیر);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lp_هدف_مسیر);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lp_هدف_مسیر,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lp_هدف_مسیر,DWORD ucchMax);

#تعریف_کن EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_نما,LPSECURITY_صفات lp_Security_صفات,DWORD dwCreationDisposition,DWORD dw_Flags_And_صفات,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_نما,LPSECURITY_صفات lp_Security_صفات,DWORD dwCreationDisposition,DWORD dw_Flags_And_صفات,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dw_Share_نما,DWORD dw_Flags_And_صفات);
  WINBASEAPI WINBOOL WINAPI مجموعه_File_صفات_A(LPCSTR lpFileName,DWORD dw_File_صفات);
  WINBASEAPI WINBOOL WINAPI مجموعه_File_صفات_W(LPCWSTR lpFileName,DWORD dw_File_صفات);
  WINBASEAPI DWORD WINAPI Get_File_صفات_A(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_File_صفات_W(LPCWSTR lpFileName);

  تعريفنوع تعداد GET_FILEEX_INFO_سطوح {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_سطوح_2;

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_File_صفات_Ex Get_File_صفات_Ex_W
#تعریف_کن Get_Compressed_File_اندازه Get_Compressed_File_اندازه_W
#تعریف_کن DeleteFile DeleteFileW
#تعریف_کن CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#وإلا
#تعریف_کن Get_File_صفات_Ex Get_File_صفات_Ex_A
#تعریف_کن Get_Compressed_File_اندازه Get_Compressed_File_اندازه_A
#تعریف_کن DeleteFile DeleteFileA
#تعریف_کن CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI Get_File_صفات_Ex_A(LPCSTR lpFileName,GET_FILEEX_INFO_سطوح_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI Get_File_صفات_Ex_W(LPCWSTR lpFileName,GET_FILEEX_INFO_سطوح_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_اندازه_A(LPCSTR lpFileName,LPDWORD lp_File_اندازه_بالا);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_اندازه_W(LPCWSTR lpFileName,LPDWORD lp_File_اندازه_بالا);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD Oem_Name_اندازه,PBOOL pb_Name_شامل_است_Spaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD Oem_Name_اندازه,PBOOL pb_Name_شامل_است_Spaces,PBOOL pbNameLegal);

  تعريفنوع تعداد FINDEX_INFO_سطوح {
    پیدا_کن_Ex_Info_Standard,پیدا_کن_Ex_Info_Max_Info_Level
  } FINDEX_INFO_سطوح_2;

  تعريفنوع تعداد FINDEX_جستجو_OPS {
    پیدا_کن_Ex_جستجو_Name_تطابق,پیدا_کن_Ex_جستجو_حد_مقصد_Directories,پیدا_کن_Ex_جستجو_حد_مقصد_Devices,پیدا_کن_Ex_جستجو_Max_جستجو_Op
  } FINDEX_جستجو_OPS_2;

#تعریف_کن پیدا_کن_اولی_EX_CASE_SENSITIVE 0x1

#اگر_تعریف_شده UNICODE
#تعریف_کن پیدا_کن_اولی_File_Ex پیدا_کن_اولی_File_Ex_W
#تعریف_کن پیدا_کن_اولی_File پیدا_کن_اولی_File_W
#تعریف_کن پیدا_کن_بعدی_File پیدا_کن_بعدی_File_W
#تعریف_کن جستجو_مسیر جستجو_مسیر_W
#تعریف_کن CopyFile CopyFileW
#تعریف_کن CopyFileEx CopyFileExW
#تعریف_کن MoveFile MoveFileW
#تعریف_کن MoveFileEx MoveFileExW
#تعریف_کن Move_File_With_پیشرفت Move_File_With_پیشرفت_W
#تعریف_کن ReplaceFile ReplaceFileW
#تعریف_کن CreateHardLink CreateHardLinkW
#تعریف_کن CreateNamedPipe CreateNamedPipeW
#تعریف_کن GetNamedPipeHandleState GetNamedPipeHandleStateW
#تعریف_کن CallNamedPipe CallNamedPipeW
#تعریف_کن WaitNamedPipe WaitNamedPipeW
#تعریف_کن مجموعه_Volume_Label مجموعه_Volume_Label_W
#تعریف_کن GetVolumeInformation GetVolumeInformationW
#تعریف_کن ClearEventLog ClearEventLogW
#تعریف_کن BackupEventLog BackupEventLogW
#تعریف_کن OpenEventLog OpenEventLogW
#تعریف_کن ثبات_Event_منبع ثبات_Event_منبع_W
#تعریف_کن OpenBackupEventLog OpenBackupEventLogW
#تعریف_کن ReadEventLog ReadEventLogW
#تعریف_کن ReportEvent ReportEventW
#تعریف_کن AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#تعریف_کن AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#تعریف_کن Access_Check_By_Type_نتیجه_List_And_Audit_Alarm Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_W
#تعریف_کن Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_By_Handle_W
#تعریف_کن ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#تعریف_کن ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#تعریف_کن ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#تعریف_کن ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#تعریف_کن PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#تعریف_کن مجموعه_File_Security مجموعه_File_Security_W
#تعریف_کن GetFileSecurity GetFileSecurityW
#تعریف_کن پیدا_کن_اولی_Change_Notification پیدا_کن_اولی_Change_Notification_W
#تعریف_کن IsBadStringPtr IsBadStringPtrW
#تعریف_کن LookupAccountSid LookupAccountSidW
#تعریف_کن LookupAccountName LookupAccountNameW
#تعریف_کن Lookup_Privilege_مقدار Lookup_Privilege_مقدار_W
#تعریف_کن LookupPrivilegeName LookupPrivilegeNameW
#تعریف_کن LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#تعریف_کن BuildCommDCB BuildCommDCBW
#تعریف_کن BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#تعریف_کن CommConfigDialog CommConfigDialogW
#تعریف_کن GetDefaultCommConfig GetDefaultCommConfigW
#تعریف_کن مجموعه_Default_Comm_Config مجموعه_Default_Comm_Config_W
#تعریف_کن GetComputerName GetComputerNameW
#تعریف_کن مجموعه_Computer_Name مجموعه_Computer_Name_W
#تعریف_کن GetComputerNameEx GetComputerNameExW
#تعریف_کن مجموعه_Computer_Name_Ex مجموعه_Computer_Name_Ex_W
#تعریف_کن Dns_Hostname_مقصد_Computer_Name Dns_Hostname_مقصد_Computer_Name_W
#تعریف_کن GetUserName GetUserNameW
#وإلا
#تعریف_کن پیدا_کن_اولی_File_Ex پیدا_کن_اولی_File_Ex_A
#تعریف_کن پیدا_کن_اولی_File پیدا_کن_اولی_File_A
#تعریف_کن پیدا_کن_بعدی_File پیدا_کن_بعدی_File_A
#تعریف_کن جستجو_مسیر جستجو_مسیر_A
#تعریف_کن CopyFile CopyFileA
#تعریف_کن CopyFileEx CopyFileExA
#تعریف_کن MoveFile MoveFileA
#تعریف_کن MoveFileEx MoveFileExA
#تعریف_کن Move_File_With_پیشرفت Move_File_With_پیشرفت_A
#تعریف_کن ReplaceFile ReplaceFileA
#تعریف_کن CreateHardLink CreateHardLinkA
#تعریف_کن CreateNamedPipe CreateNamedPipeA
#تعریف_کن GetNamedPipeHandleState GetNamedPipeHandleStateA
#تعریف_کن CallNamedPipe CallNamedPipeA
#تعریف_کن WaitNamedPipe WaitNamedPipeA
#تعریف_کن مجموعه_Volume_Label مجموعه_Volume_Label_A
#تعریف_کن GetVolumeInformation GetVolumeInformationA
#تعریف_کن ClearEventLog ClearEventLogA
#تعریف_کن BackupEventLog BackupEventLogA
#تعریف_کن OpenEventLog OpenEventLogA
#تعریف_کن ثبات_Event_منبع ثبات_Event_منبع_A
#تعریف_کن OpenBackupEventLog OpenBackupEventLogA
#تعریف_کن ReadEventLog ReadEventLogA
#تعریف_کن ReportEvent ReportEventA
#تعریف_کن AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#تعریف_کن AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#تعریف_کن Access_Check_By_Type_نتیجه_List_And_Audit_Alarm Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_A
#تعریف_کن Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_By_Handle_A
#تعریف_کن ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#تعریف_کن ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#تعریف_کن ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#تعریف_کن ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#تعریف_کن PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#تعریف_کن مجموعه_File_Security مجموعه_File_Security_A
#تعریف_کن GetFileSecurity GetFileSecurityA
#تعریف_کن پیدا_کن_اولی_Change_Notification پیدا_کن_اولی_Change_Notification_A
#تعریف_کن IsBadStringPtr IsBadStringPtrA
#تعریف_کن LookupAccountSid LookupAccountSidA
#تعریف_کن LookupAccountName LookupAccountNameA
#تعریف_کن Lookup_Privilege_مقدار Lookup_Privilege_مقدار_A
#تعریف_کن LookupPrivilegeName LookupPrivilegeNameA
#تعریف_کن LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#تعریف_کن BuildCommDCB BuildCommDCBA
#تعریف_کن BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#تعریف_کن CommConfigDialog CommConfigDialogA
#تعریف_کن GetDefaultCommConfig GetDefaultCommConfigA
#تعریف_کن مجموعه_Default_Comm_Config مجموعه_Default_Comm_Config_A
#تعریف_کن GetComputerName GetComputerNameA
#تعریف_کن مجموعه_Computer_Name مجموعه_Computer_Name_A
#تعریف_کن GetComputerNameEx GetComputerNameExA
#تعریف_کن مجموعه_Computer_Name_Ex مجموعه_Computer_Name_Ex_A
#تعریف_کن Dns_Hostname_مقصد_Computer_Name Dns_Hostname_مقصد_Computer_Name_A
#تعریف_کن GetUserName GetUserNameA
#پایان_اگر

  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_File_Ex_A(LPCSTR lpFileName,FINDEX_INFO_سطوح_2 fInfoLevelId,LPVOID lp_پیدا_کن_File_داده,FINDEX_جستجو_OPS_2 f_جستجو_Op,LPVOID lp_جستجو_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_File_Ex_W(LPCWSTR lpFileName,FINDEX_INFO_سطوح_2 fInfoLevelId,LPVOID lp_پیدا_کن_File_داده,FINDEX_جستجو_OPS_2 f_جستجو_Op,LPVOID lp_جستجو_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_File_A(LPCSTR lpFileName,LPWIN32_پیدا_کن_DATAA lp_پیدا_کن_File_داده);
  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_File_W(LPCWSTR lpFileName,LPWIN32_پیدا_کن_DATAW lp_پیدا_کن_File_داده);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_بعدی_File_A(HANDLE h_پیدا_کن_File,LPWIN32_پیدا_کن_DATAA lp_پیدا_کن_File_داده);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_بعدی_File_W(HANDLE h_پیدا_کن_File,LPWIN32_پیدا_کن_DATAW lp_پیدا_کن_File_داده);
  WINBASEAPI DWORD WINAPI جستجو_مسیر_A(LPCSTR lp_مسیر,LPCSTR lpFileName,LPCSTR lpExtension,DWORD n_میانگیر_درازی,LPSTR lp_میانگیر,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI جستجو_مسیر_W(LPCWSTR lp_مسیر,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD n_میانگیر_درازی,LPWSTR lp_میانگیر,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  تعريفنوع DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER مجموع_File_اندازه,LARGE_INTEGER مجموع_بایتها_Transferred,LARGE_INTEGER جریان_اندازه,LARGE_INTEGER جریان_بایتها_Transferred,DWORD dw_جریان_عدد,DWORD dwCallbackReason,HANDLE h_منبع_File,HANDLE hDestinationFile,LPVOID lp_داده);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پیشرفت_Routine,LPVOID lp_داده,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پیشرفت_Routine,LPVOID lp_داده,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_پیشرفت_A(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پیشرفت_Routine,LPVOID lp_داده,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_پیشرفت_W(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پیشرفت_Routine,LPVOID lp_داده,DWORD dwFlags);

#تعریف_کن MOVEFILE_REPLACE_EXISTING 0x1
#تعریف_کن MOVEFILE_COPY_ALLOWED 0x2
#تعریف_کن MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#تعریف_کن MOVEFILE_WRITE_THROUGH 0x8
#تعریف_کن MOVEFILE_CREATE_HARDLINK 0x10
#تعریف_کن MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_صفات lp_Security_صفات);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_صفات lp_Security_صفات);

  تعريفنوع تعداد جریان_INFO_سطوح {
    پیدا_کن_جریان_Info_Standard,پیدا_کن_جریان_Info_Max_Info_Level
  } جریان_INFO_سطوح_2;

  تعريفنوع بنية WIN32_پیدا_کن_جریان_داده {
    LARGE_INTEGER جریان_اندازه;
    WCHAR c_جریان_Name[MAX_مسیر + 36];
  } WIN32_پیدا_کن_جریان_داده_2,*PWIN32_پیدا_کن_جریان_داده;

  HANDLE WINAPI پیدا_کن_اولی_جریان_W(LPCWSTR lpFileName,جریان_INFO_سطوح_2 InfoLevel,LPVOID lp_پیدا_کن_جریان_داده,DWORD dwFlags);
  WINBOOL WINAPI پیدا_کن_بعدی_جریان_W(HANDLE h_پیدا_کن_جریان,LPVOID lp_پیدا_کن_جریان_داده);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dw_Open_نما,DWORD dw_Pipe_نما,DWORD nMaxInstances,DWORD n_بیرون_میانگیر_اندازه,DWORD n_درون_میانگیر_اندازه,DWORD n_Default_زمان_بیرون,LPSECURITY_صفات lp_Security_صفات);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dw_Open_نما,DWORD dw_Pipe_نما,DWORD nMaxInstances,DWORD n_بیرون_میانگیر_اندازه,DWORD n_درون_میانگیر_اندازه,DWORD n_Default_زمان_بیرون,LPSECURITY_صفات lp_Security_صفات);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_شمار,LPDWORD lp_Collect_داده_Timeout,LPSTR lpUserName,DWORD n_Max_User_Name_اندازه);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_شمار,LPDWORD lp_Collect_داده_Timeout,LPWSTR lpUserName,DWORD n_Max_User_Name_اندازه);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lp_درون_میانگیر,DWORD n_درون_میانگیر_اندازه,LPVOID lp_بیرون_میانگیر,DWORD n_بیرون_میانگیر_اندازه,LPDWORD lp_بایتها_Read,DWORD n_زمان_بیرون);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lp_درون_میانگیر,DWORD n_درون_میانگیر_اندازه,LPVOID lp_بیرون_میانگیر,DWORD n_بیرون_میانگیر_اندازه,LPDWORD lp_بایتها_Read,DWORD n_زمان_بیرون);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD n_زمان_بیرون);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD n_زمان_بیرون);
  WINBASEAPI WINBOOL WINAPI مجموعه_Volume_Label_A(LPCSTR lp_ریشه_مسیر_Name,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI مجموعه_Volume_Label_W(LPCWSTR lp_ریشه_مسیر_Name,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI مجموعه_File_Apis_مقصد_OEM(VOID);
  WINBASEAPI VOID WINAPI مجموعه_File_Apis_مقصد_ANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lp_ریشه_مسیر_Name,LPSTR lp_Volume_Name_میانگیر,DWORD n_Volume_Name_اندازه,LPDWORD lp_Volume_Serial_عدد,LPDWORD lp_بیشینه_Component_درازی,LPDWORD lpFileSystemFlags,LPSTR lp_File_System_Name_میانگیر,DWORD n_File_System_Name_اندازه);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lp_ریشه_مسیر_Name,LPWSTR lp_Volume_Name_میانگیر,DWORD n_Volume_Name_اندازه,LPDWORD lp_Volume_Serial_عدد,LPDWORD lp_بیشینه_Component_درازی,LPDWORD lpFileSystemFlags,LPWSTR lp_File_System_Name_میانگیر,DWORD n_File_System_Name_اندازه);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI Deregister_Event_منبع(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI Get_عدد_از_Event_Log_رکوردها(HANDLE hEventLog,PDWORD عدد_از_رکوردها);
  WINADVAPI WINBOOL WINAPI Get_Oldest_Event_Log_رکورد(HANDLE hEventLog,PDWORD Oldest_رکورد);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lp_منبع_Name);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lp_منبع_Name);
  WINADVAPI HANDLE WINAPI ثبات_Event_منبع_A(LPCSTR lpUNCServerName,LPCSTR lp_منبع_Name);
  WINADVAPI HANDLE WINAPI ثبات_Event_منبع_W(LPCWSTR lpUNCServerName,LPCWSTR lp_منبع_Name);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_رکورد_جابه_جایی,LPVOID lp_میانگیر,DWORD n_عدد_از_بایتها_مقصد_Read,DWORD *pn_بایتها_Read,DWORD *pn_Min_عدد_از_بایتها_Needed);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_رکورد_جابه_جایی,LPVOID lp_میانگیر,DWORD n_عدد_از_بایتها_مقصد_Read,DWORD *pn_بایتها_Read,DWORD *pn_Min_عدد_از_بایتها_Needed);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,کلمه_3 wType,کلمه_3 wCategory,DWORD dwEventID,PSID lpUserSid,کلمه_3 w_رقم_رشتهها,DWORD dw_داده_اندازه,LPCSTR *lp_رشتهها,LPVOID lp_Raw_داده);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,کلمه_3 wType,کلمه_3 wCategory,DWORD dwEventID,PSID lpUserSid,کلمه_3 w_رقم_رشتهها,DWORD dw_داده_اندازه,LPCWSTR *lp_رشتهها,LPVOID lp_Raw_داده);

#تعریف_کن EVENTLOG_پر_INFO 0

  تعريفنوع بنية EVENTLOG_پر_INFORMATION {
    DWORD dw_پر;
  } EVENTLOG_پر_INFORMATION_2,*LPEVENTLOG_پر_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lp_میانگیر,DWORD cb_Buf_اندازه,LPDWORD pcb_بایتها_Needed);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_درازی,LPDWORD lpn_درازی_Needed);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI Revert_مقصد_Self(VOID);
  WINADVAPI WINBOOL WINAPI مجموعه_Thread_Token (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_مجموعه Privilege_مجموعه,LPDWORD Privilege_مجموعه_درازی,LPDWORD GrantedAccess,LPBOOL Access_وضعیت);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_درازی,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_مجموعه Privilege_مجموعه,LPDWORD Privilege_مجموعه_درازی,LPDWORD GrantedAccess,LPBOOL Access_وضعیت);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجه_List(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_درازی,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_مجموعه Privilege_مجموعه,LPDWORD Privilege_مجموعه_درازی,LPDWORD GrantedAccessList,LPDWORD Access_وضعیت_List);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_درازی,PDWORD Return_درازی);
  WINADVAPI WINBOOL WINAPI مجموعه_Token_Information(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_درازی);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD میانگیر_درازی,PTOKEN_PRIVILEGES قبلی_State,PDWORD Return_درازی);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL Reset_مقصد_Default,PTOKEN_GROUPS NewState,DWORD میانگیر_درازی,PTOKEN_GROUPS قبلی_State,PDWORD Return_درازی);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_مجموعه RequiredPrivileges,LPBOOL pf_نتیجه);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_وضعیت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_وضعیت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_درازی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_وضعیت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_درازی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_وضعیت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_A(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_درازی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_وضعیت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_W(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_درازی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_وضعیت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_By_Handle_A(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_درازی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_وضعیت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجه_List_And_Audit_Alarm_By_Handle_W(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_درازی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_وضعیت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_مجموعه Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_مجموعه Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_مجموعه Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_مجموعه Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_مجموعه Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_مجموعه Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI Is_Well_معلوم_Sid(PSID pSid,WELL_معلوم_SID_TYPE Well_معلوم_Sid_Type);
  WINADVAPI WINBOOL WINAPI Create_Well_معلوم_Sid(WELL_معلوم_SID_TYPE Well_معلوم_Sid_Type,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI Equal_پیشوند_Sid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI Get_Sid_درازی_Required (UCHAR n_Sub_Authority_شمار);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_شمار,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_شمار);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI Get_Sid_Sub_Authority_شمار(PSID pSid);
  WINADVAPI DWORD WINAPI Get_درازی_Sid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD n_Destination_Sid_درازی,PSID pDestinationSid,PSID p_منبع_Sid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI Map_Generic_ماسک(PDWORD Access_ماسک,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD n_Acl_درازی,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_درازی,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI مجموعه_Acl_Information(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_درازی,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI جمع_کن_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Starting_Ace_شاخص,LPVOID pAceList,DWORD n_Ace_List_درازی);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dw_Ace_شاخص);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dw_Ace_شاخص,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI جمع_کن_Access_Allowed_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ماسک,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کن_Access_Allowed_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کن_Access_Denied_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ماسک,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کن_Access_Denied_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کن_Audit_Access_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Access_ماسک,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI جمع_کن_Audit_Access_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dw_Access_ماسک,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI جمع_کن_Access_Allowed_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کن_Access_Denied_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI جمع_کن_Audit_Access_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ماسک,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI پیدا_کن_اولی_Free_Ace(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI Get_Security_Descriptor_درازی(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI مجموعه_Security_Descriptor_Control(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL Control_بیتها_از_Interest,SECURITY_DESCRIPTOR_CONTROL Control_بیتها_مقصد_مجموعه);
  WINADVAPI WINBOOL WINAPI مجموعه_Security_Descriptor_Dacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI مجموعه_Security_Descriptor_Sacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI مجموعه_Security_Descriptor_Owner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI مجموعه_Security_Descriptor_گروه(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID p_گروه,WINBOOL b_گروه_Defaulted);
  WINADVAPI WINBOOL WINAPI Get_Security_Descriptor_گروه(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *p_گروه,LPBOOL lpb_گروه_Defaulted);
  WINADVAPI DWORD WINAPI مجموعه_Security_Descriptor_RMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI Create_خصوصی_Object_Security(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Convert_مقصد_Auto_Inherit_خصوصی_Object_Security(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_خصوصی_Object_Security_Ex(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_خصوصی_Object_Security_With_مضرب_Inheritance(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG Guid_شمار,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI مجموعه_خصوصی_Object_Security (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI مجموعه_خصوصی_Object_Security_Ex (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI Get_خصوصی_Object_Security(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD Descriptor_درازی,PDWORD Return_درازی);
  WINADVAPI WINBOOL WINAPI Destroy_خصوصی_Object_Security(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_میانگیر_درازی);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdw_Absolute_Security_Descriptor_اندازه,PACL pDacl,LPDWORD lpdw_Dacl_اندازه,PACL pSacl,LPDWORD lpdw_Sacl_اندازه,PSID pOwner,LPDWORD lpdw_Owner_اندازه,PSID p_Primary_گروه,LPDWORD lpdw_Primary_گروه_اندازه);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_میانگیر_اندازه);
  WINADVAPI WINBOOL WINAPI مجموعه_File_Security_A(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI مجموعه_File_Security_W(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_درازی,LPDWORD lpn_درازی_Needed);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_درازی,LPDWORD lpn_درازی_Needed);
  WINADVAPI WINBOOL WINAPI مجموعه_Kernel_Object_Security(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_Change_Notification_A(LPCSTR lp_مسیر_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_Change_Notification_W(LPCWSTR lp_مسیر_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_بعدی_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_Close_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lp_میانگیر,DWORD n_میانگیر_درازی,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lp_بایتها_Returned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI Virtual_قفل(LPVOID lp_آدرس,اندازه_T dw_اندازه);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lp_آدرس,اندازه_T dw_اندازه);
  WINBASEAPI LPVOID WINAPI Map_View_از_File_Ex(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_جابه_جایی_بالا,DWORD dw_File_جابه_جایی_کم,اندازه_T dw_عدد_از_بایتها_مقصد_Map,LPVOID lp_پایه_آدرس);
  WINBASEAPI WINBOOL WINAPI مجموعه_اولویت_Class(HANDLE hProcess,DWORD dw_اولویت_Class);
  WINBASEAPI DWORD WINAPI Get_اولویت_Class(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI Is_Bad_کد_Ptr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_مقدار_A(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_مقدار_W(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
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
  WINBASEAPI WINBOOL WINAPI مجموعه_Default_Comm_Config_A(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Default_Comm_Config_W(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_اندازه);

#تعریف_کن MAX_COMPUTERNAME_درازی 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lp_میانگیر,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lp_میانگیر,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Computer_Name_A(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI مجموعه_Computer_Name_W(LPCWSTR lpComputerName);

  تعريفنوع تعداد _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lp_میانگیر,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lp_میانگیر,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Computer_Name_Ex_A(COMPUTER_NAME_FORMAT NameType,LPCSTR lp_میانگیر);
  WINBASEAPI WINBOOL WINAPI مجموعه_Computer_Name_Ex_W(COMPUTER_NAME_FORMAT NameType,LPCWSTR lp_میانگیر);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_مقصد_Computer_Name_A(LPCSTR Hostname,LPSTR ComputerName,LPDWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_مقصد_Computer_Name_W(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD n_اندازه);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lp_میانگیر,LPDWORD pcb_میانگیر);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lp_میانگیر,LPDWORD pcb_میانگیر);

#تعریف_کن LOGON32_LOGON_INTERACTIVE 2
#تعریف_کن LOGON32_LOGON_شبکه 3
#تعریف_کن LOGON32_LOGON_BATCH 4
#تعریف_کن LOGON32_LOGON_SERVICE 5
#تعریف_کن LOGON32_LOGON_UNLOCK 7
#تعریف_کن LOGON32_LOGON_شبکه_CLEARTEXT 8
#تعریف_کن LOGON32_LOGON_NEW_CREDENTIALS 9

#تعریف_کن LOGON32_PROVIDER_DEFAULT 0
#تعریف_کن LOGON32_PROVIDER_WINNT35 1
#تعریف_کن LOGON32_PROVIDER_WINNT40 2
#تعریف_کن LOGON32_PROVIDER_WINNT50 3

#اگر_تعریف_شده UNICODE
#تعریف_کن LogonUser LogonUserW
#تعریف_کن LogonUserEx LogonUserExW
#تعریف_کن CreateProcessAsUser CreateProcessAsUserW
#وإلا
#تعریف_کن LogonUser LogonUserA
#تعریف_کن LogonUserEx LogonUserExA
#تعریف_کن CreateProcessAsUser CreateProcessAsUserA
#پایان_اگر

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_میانگیر,LPDWORD pdw_Profile_درازی,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_میانگیر,LPDWORD pdw_Profile_درازی,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lp_Command_سطر,LPSECURITY_صفات lp_Process_صفات,LPSECURITY_صفات lp_Thread_صفات,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lp_Command_سطر,LPSECURITY_صفات lp_Process_صفات,LPSECURITY_صفات lp_Thread_صفات,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#تعریف_کن LOGON_WITH_PROFILE 0x1
#تعریف_کن LOGON_NETCREDENTIALS_ONLY 0x2
#تعریف_کن LOGON_ZERO_PASSWORD_میانگیر 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_سطر,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_سطر,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_صفات lp_Token_صفات,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD Disable_Sid_شمار,PSID_AND_صفات Sids_مقصد_Disable,DWORD Delete_Privilege_شمار,PLUID_AND_صفات Privileges_مقصد_Delete,DWORD Restricted_Sid_شمار,PSID_AND_صفات Sids_مقصد_Restrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID Sid_مقصد_Check,PBOOL IsMember);

  تعريفنوع WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI ثبات_Wait_For_Single_Object(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI ثبات_Wait_For_Single_Object_Ex(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI صف_User_Work_قلم(LPTHREAD_شروع_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI Create_Timer_صف(VOID);
  WINBASEAPI WINBOOL WINAPI Create_Timer_صف_Timer(PHANDLE phNewTimer,HANDLE Timer_صف,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_زمان,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI Change_Timer_صف_Timer(HANDLE Timer_صف,HANDLE Timer,ULONG Due_زمان,ULONG Period);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_صف_Timer(HANDLE Timer_صف,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_صف_Ex(HANDLE Timer_صف,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI مجموعه_Timer_صف_Timer(HANDLE Timer_صف,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_زمان,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI Cancel_Timer_صف_Timer(HANDLE Timer_صف,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_صف(HANDLE Timer_صف);

#تعریف_کن HW_PROFILE_GUIDLEN 39
#تعریف_کن MAX_PROFILE_LEN 80

#تعریف_کن DOCKINFO_UNDOCKED (0x1)
#تعریف_کن DOCKINFO_DOCKED (0x2)
#تعریف_کن DOCKINFO_USER_SUPPLIED (0x4)
#تعریف_کن DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#تعریف_کن DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  تعريفنوع بنية برچسب_HW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  تعريفنوع بنية برچسب_HW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#اگر_تعریف_شده UNICODE
  تعريفنوع HW_PROFILE_INFOW HW_PROFILE_INFO;
  تعريفنوع LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#وإلا
  تعريفنوع HW_PROFILE_INFOA HW_PROFILE_INFO;
  تعريفنوع LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن GetCurrentHwProfile GetCurrentHwProfileW
#تعریف_کن Get_نسخه_Ex Get_نسخه_Ex_W
#تعریف_کن Verify_نسخه_Info Verify_نسخه_Info_W
#وإلا
#تعریف_کن GetCurrentHwProfile GetCurrentHwProfileA
#تعریف_کن Get_نسخه_Ex Get_نسخه_Ex_A
#تعریف_کن Verify_نسخه_Info Verify_نسخه_Info_A
#پایان_اگر

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lp_Performance_شمار);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI Get_نسخه_Ex_A(LPOSVERSIONINFOA lp_نسخه_Information);
  WINBASEAPI WINBOOL WINAPI Get_نسخه_Ex_W(LPOSVERSIONINFOW lp_نسخه_Information);
  WINBASEAPI WINBOOL WINAPI Verify_نسخه_Info_A(LPOSVERSIONINFOEXA lp_نسخه_Information,DWORD dw_Type_ماسک,DWORDLONG dwl_Condition_ماسک);
  WINBASEAPI WINBOOL WINAPI Verify_نسخه_Info_W(LPOSVERSIONINFOEXW lp_نسخه_Information,DWORD dw_Type_ماسک,DWORDLONG dwl_Condition_ماسک);

#ضمن <winerror.h>

#تعریف_کن TC_نرمال 0
#تعریف_کن TC_HARDERR 1
#تعریف_کن TC_GP_TRAP 2
#تعریف_کن TC_SIGNAL 3

#تعریف_کن AC_سطر_OFFLINE 0x0
#تعریف_کن AC_سطر_ONLINE 0x1
#تعریف_کن AC_سطر_BACKUP_POWER 0x2
#تعریف_کن AC_سطر_UNKNOWN 0xff

#تعریف_کن BATTERY_FLAG_بالا 0x1
#تعریف_کن BATTERY_FLAG_کم 0x2
#تعریف_کن BATTERY_FLAG_CRITICAL 0x4
#تعریف_کن BATTERY_FLAG_CHARGING 0x8
#تعریف_کن BATTERY_FLAG_NO_BATTERY 0x80
#تعریف_کن BATTERY_FLAG_UNKNOWN 0xff

#تعریف_کن BATTERY_PERCENTAGE_UNKNOWN 0xff

#تعریف_کن BATTERY_LIFE_UNKNOWN 0xffffffff

  تعريفنوع بنية SYSTEM_POWER_وضعیت {
    BYTE ACLine_وضعیت;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD Battery_Life_زمان;
    DWORD Battery_پر_Life_زمان;
  } SYSTEM_POWER_وضعیت_2,*LPSYSTEM_POWER_وضعیت;

#اگر_تعریف_شده UNICODE
#تعریف_کن Create_کار_Object Create_کار_Object_W
#تعریف_کن Open_کار_Object Open_کار_Object_W
#تعریف_کن پیدا_کن_اولی_Volume پیدا_کن_اولی_Volume_W
#تعریف_کن پیدا_کن_بعدی_Volume پیدا_کن_بعدی_Volume_W
#تعریف_کن پیدا_کن_اولی_Volume_Mount_نقطه پیدا_کن_اولی_Volume_Mount_نقطه_W
#تعریف_کن پیدا_کن_بعدی_Volume_Mount_نقطه پیدا_کن_بعدی_Volume_Mount_نقطه_W
#تعریف_کن مجموعه_Volume_Mount_نقطه مجموعه_Volume_Mount_نقطه_W
#تعریف_کن Delete_Volume_Mount_نقطه Delete_Volume_Mount_نقطه_W
#تعریف_کن Get_Volume_Name_For_Volume_Mount_نقطه Get_Volume_Name_For_Volume_Mount_نقطه_W
#تعریف_کن Get_Volume_مسیر_Name Get_Volume_مسیر_Name_W
#تعریف_کن Get_Volume_مسیر_نامها_For_Volume_Name Get_Volume_مسیر_نامها_For_Volume_Name_W
#وإلا
#تعریف_کن Create_کار_Object Create_کار_Object_A
#تعریف_کن Open_کار_Object Open_کار_Object_A
#تعریف_کن پیدا_کن_اولی_Volume پیدا_کن_اولی_Volume_A
#تعریف_کن پیدا_کن_بعدی_Volume پیدا_کن_بعدی_Volume_A
#تعریف_کن پیدا_کن_اولی_Volume_Mount_نقطه پیدا_کن_اولی_Volume_Mount_نقطه_A
#تعریف_کن پیدا_کن_بعدی_Volume_Mount_نقطه پیدا_کن_بعدی_Volume_Mount_نقطه_A
#تعریف_کن مجموعه_Volume_Mount_نقطه مجموعه_Volume_Mount_نقطه_A
#تعریف_کن Delete_Volume_Mount_نقطه Delete_Volume_Mount_نقطه_A
#تعریف_کن Get_Volume_Name_For_Volume_Mount_نقطه Get_Volume_Name_For_Volume_Mount_نقطه_A
#تعریف_کن Get_Volume_مسیر_Name Get_Volume_مسیر_Name_A
#تعریف_کن Get_Volume_مسیر_نامها_For_Volume_Name Get_Volume_مسیر_نامها_For_Volume_Name_A
#پایان_اگر

  WINBOOL WINAPI Get_System_Power_وضعیت(LPSYSTEM_POWER_وضعیت lp_System_Power_وضعیت);
  WINBOOL WINAPI مجموعه_System_Power_State(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI Allocate_User_Physical_صفحات(HANDLE hProcess,PULONG_PTR عدد_از_صفحات,PULONG_PTR صفحه_Array);
  WINBASEAPI WINBOOL WINAPI Free_User_Physical_صفحات(HANDLE hProcess,PULONG_PTR عدد_از_صفحات,PULONG_PTR صفحه_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_صفحات(PVOID Virtual_آدرس,ULONG_PTR عدد_از_صفحات,PULONG_PTR صفحه_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_صفحات_Scatter(PVOID *Virtual_آدرسها,ULONG_PTR عدد_از_صفحات,PULONG_PTR صفحه_Array);
  WINBASEAPI HANDLE WINAPI Create_کار_Object_A(LPSECURITY_صفات lp_کار_صفات,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Create_کار_Object_W(LPSECURITY_صفات lp_کار_صفات,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_کار_Object_A(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_کار_Object_W(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI تخصیص_بده_Process_مقصد_کار_Object(HANDLE h_کار,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI Terminate_کار_Object(HANDLE h_کار,UINT u_Exit_کد);
  WINBASEAPI WINBOOL WINAPI Query_Information_کار_Object(HANDLE h_کار,JOBOBJECTINFOCLASS کار_Object_Information_Class,LPVOID lp_کار_Object_Information,DWORD cb_کار_Object_Information_درازی,LPDWORD lp_Return_درازی);
  WINBASEAPI WINBOOL WINAPI مجموعه_Information_کار_Object(HANDLE h_کار,JOBOBJECTINFOCLASS کار_Object_Information_Class,LPVOID lp_کار_Object_Information,DWORD cb_کار_Object_Information_درازی);
  WINBASEAPI WINBOOL WINAPI Is_Process_درون_کار(HANDLE ProcessHandle,HANDLE کار_Handle,PBOOL نتیجه_3);
  WINBASEAPI WINBOOL WINAPI Create_کار_مجموعه(ULONG رقم_کار,PJOB_مجموعه_ARRAY User_کار_مجموعه,ULONG Flags);
  WINBASEAPI PVOID WINAPI جمع_کن_Vectored_Exception_Handler (ULONG اولی_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI جمع_کن_Vectored_Continue_Handler (ULONG اولی_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_Volume_A(LPSTR lpszVolumeName,DWORD cch_میانگیر_درازی);
  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_Volume_W(LPWSTR lpszVolumeName,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_بعدی_Volume_A(HANDLE h_پیدا_کن_Volume,LPSTR lpszVolumeName,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_بعدی_Volume_W(HANDLE h_پیدا_کن_Volume,LPWSTR lpszVolumeName,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_Volume_Close(HANDLE h_پیدا_کن_Volume);
  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_Volume_Mount_نقطه_A(LPCSTR lpsz_ریشه_مسیر_Name,LPSTR lpsz_Volume_Mount_نقطه,DWORD cch_میانگیر_درازی);
  WINBASEAPI HANDLE WINAPI پیدا_کن_اولی_Volume_Mount_نقطه_W(LPCWSTR lpsz_ریشه_مسیر_Name,LPWSTR lpsz_Volume_Mount_نقطه,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_بعدی_Volume_Mount_نقطه_A(HANDLE h_پیدا_کن_Volume_Mount_نقطه,LPSTR lpsz_Volume_Mount_نقطه,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_بعدی_Volume_Mount_نقطه_W(HANDLE h_پیدا_کن_Volume_Mount_نقطه,LPWSTR lpsz_Volume_Mount_نقطه,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_Volume_Mount_نقطه_Close(HANDLE h_پیدا_کن_Volume_Mount_نقطه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Volume_Mount_نقطه_A(LPCSTR lpsz_Volume_Mount_نقطه,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI مجموعه_Volume_Mount_نقطه_W(LPCWSTR lpsz_Volume_Mount_نقطه,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_نقطه_A(LPCSTR lpsz_Volume_Mount_نقطه);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_نقطه_W(LPCWSTR lpsz_Volume_Mount_نقطه);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_نقطه_A(LPCSTR lpsz_Volume_Mount_نقطه,LPSTR lpszVolumeName,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_نقطه_W(LPCWSTR lpsz_Volume_Mount_نقطه,LPWSTR lpszVolumeName,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_مسیر_Name_A(LPCSTR lpszFileName,LPSTR lpsz_Volume_مسیر_Name,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_مسیر_Name_W(LPCWSTR lpszFileName,LPWSTR lpsz_Volume_مسیر_Name,DWORD cch_میانگیر_درازی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_مسیر_نامها_For_Volume_Name_A(LPCSTR lpszVolumeName,LPCH lpsz_Volume_مسیر_نامها,DWORD cch_میانگیر_درازی,PDWORD lpcch_Return_درازی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_مسیر_نامها_For_Volume_Name_W(LPCWSTR lpszVolumeName,LPWCH lpsz_Volume_مسیر_نامها,DWORD cch_میانگیر_درازی,PDWORD lpcch_Return_درازی);

#تعریف_کن ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#تعریف_کن ACTCTX_FLAG_LANGID_VALID 0x2
#تعریف_کن ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#تعریف_کن ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#تعریف_کن ACTCTX_FLAG_مجموعه_PROCESS_DEFAULT 0x10
#تعریف_کن ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#تعریف_کن ACTCTX_FLAG_منبع_IS_ASSEMBLYREF 0x40
#تعریف_کن ACTCTX_FLAG_HMODULE_VALID 0x80

  تعريفنوع بنية برچسب_ACTCTXA {
    ULONG cb_اندازه;
    DWORD dwFlags;
    LPCSTR lp_منبع;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  تعريفنوع بنية برچسب_ACTCTXW {
    ULONG cb_اندازه;
    DWORD dwFlags;
    LPCWSTR lp_منبع;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  تعريفنوع ثابت ACTCTXA *PCACTCTXA;
  تعريفنوع ثابت ACTCTXW *PCACTCTXW;

#اگر_تعریف_شده UNICODE
  تعريفنوع ACTCTXW ACTCTX;
  تعريفنوع PACTCTXW PACTCTX;
  تعريفنوع PCACTCTXW PCACTCTX;
#وإلا
  تعريفنوع ACTCTXA ACTCTX;
  تعريفنوع PACTCTXA PACTCTX;
  تعريفنوع PCACTCTXA PCACTCTX;
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن CreateActCtx CreateActCtxW
#وإلا
#تعریف_کن CreateActCtx CreateActCtxA
#پایان_اگر

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI جمع_کن_Ref_Act_Ctx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#تعریف_کن DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  تعريفنوع بنية برچسب_ACTCTX_SECTION_KEYED_داده_2600 {
    ULONG cb_اندازه;
    ULONG ul_داده_Format_نسخه;
    PVOID lp_داده;
    ULONG ul_درازی;
    PVOID lp_Section_Global_داده;
    ULONG ul_Section_Global_داده_درازی;
    PVOID lp_Section_پایه;
    ULONG ul_Section_مجموع_درازی;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_شاخص;
  } ACTCTX_SECTION_KEYED_داده_2600,*PACTCTX_SECTION_KEYED_داده_2600;

  تعريفنوع ثابت ACTCTX_SECTION_KEYED_داده_2600 *PCACTCTX_SECTION_KEYED_داده_2600;

  تعريفنوع بنية برچسب_ACTCTX_SECTION_KEYED_داده_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lp_Section_پایه;
    ULONG ul_Section_درازی;
    PVOID lp_Section_Global_داده_پایه;
    ULONG ul_Section_Global_داده_درازی;
  } ACTCTX_SECTION_KEYED_داده_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_داده_ASSEMBLY_METADATA;

  تعريفنوع ثابت ACTCTX_SECTION_KEYED_داده_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_داده_ASSEMBLY_METADATA;

  تعريفنوع بنية برچسب_ACTCTX_SECTION_KEYED_داده {
    ULONG cb_اندازه;
    ULONG ul_داده_Format_نسخه;
    PVOID lp_داده;
    ULONG ul_درازی;
    PVOID lp_Section_Global_داده;
    ULONG ul_Section_Global_داده_درازی;
    PVOID lp_Section_پایه;
    ULONG ul_Section_مجموع_درازی;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_شاخص;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_داده_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_داده,*PACTCTX_SECTION_KEYED_داده;

  تعريفنوع ثابت ACTCTX_SECTION_KEYED_داده *PCACTCTX_SECTION_KEYED_داده;

#تعریف_کن پیدا_کن_ACTCTX_SECTION_کلید_RETURN_HACTCTX 0x1
#تعریف_کن پیدا_کن_ACTCTX_SECTION_کلید_RETURN_FLAGS 0x2
#تعریف_کن پیدا_کن_ACTCTX_SECTION_کلید_RETURN_ASSEMBLY_METADATA 0x4

#اگر_تعریف_شده UNICODE
#تعریف_کن پیدا_کن_Act_Ctx_Section_String پیدا_کن_Act_Ctx_Section_String_W
#وإلا
#تعریف_کن پیدا_کن_Act_Ctx_Section_String پیدا_کن_Act_Ctx_Section_String_A
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI پیدا_کن_Act_Ctx_Section_String_A(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lp_String_مقصد_پیدا_کن,PACTCTX_SECTION_KEYED_داده Returned_داده);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_Act_Ctx_Section_String_W(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lp_String_مقصد_پیدا_کن,PACTCTX_SECTION_KEYED_داده Returned_داده);
  WINBASEAPI WINBOOL WINAPI پیدا_کن_Act_Ctx_Section_Guid(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,ثابت GUID *lp_Guid_مقصد_پیدا_کن,PACTCTX_SECTION_KEYED_داده Returned_داده);

#اگر_تعریف_نشده RC_INVOKED
#اگر_تعریف_نشده ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  تعريفنوع بنية _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  تعريفنوع ثابت بنية _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#تعریف_کن ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#پایان_اگر
#پایان_اگر

#تعریف_کن QUERY_ACTCTX_FLAG_USE_فعال_ACTCTX 0x4
#تعریف_کن QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#تعریف_کن QUERY_ACTCTX_FLAG_ACTCTX_IS_آدرس 0x10
#تعریف_کن QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_میانگیر,اندازه_T cb_میانگیر,اندازه_T *pcbWrittenOrRequired);

  تعريفنوع WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_میانگیر,اندازه_T cb_میانگیر,اندازه_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI Process_Id_مقصد_Session_Id(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGet_فعال_Console_Session_Id();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION میانگیر_3,PDWORD Returned_درازی);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Highest_گره_عدد(PULONG Highest_گره_عدد);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Processor_گره(UCHAR Processor,PUCHAR گره_عدد);
  WINBASEAPI WINBOOL WINAPI Get_Numa_گره_Processor_ماسک(UCHAR گره_2,PULONGLONG Processor_ماسک);
  WINBASEAPI WINBOOL WINAPI Get_Numa_موجود_حافظه_گره(UCHAR گره_2,PULONGLONG موجود_بایتها);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
