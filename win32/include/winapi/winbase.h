/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _WINBASE_
#وصف_ڪريو _WINBASE_

#وصف_ڪريو WINADVAPI DECLSPEC_IMPORT
#وصف_ڪريو WINBASEAPI DECLSPEC_IMPORT
#وصف_ڪريو ZAWPROXYAPI DECLSPEC_IMPORT

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#وصف_ڪريو Define_Handle_جدول(w) ((w),TRUE)
#وصف_ڪريو حد_بندي_Ems_صفحا(dw)
#وصف_ڪريو سيٽ_مٽا_سٽا_Area_سائيز(w) (w)
#وصف_ڪريو تالو_Segment(w) GlobalFix((HANDLE)(w))
#وصف_ڪريو UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#وصف_ڪريو Get_Current_وقت() Get_Tick_ڳڻپ()

#وصف_ڪريو Yield()

#وصف_ڪريو INVALID_HANDLE_قدر ((HANDLE)(LONG_PTR)-1)
#وصف_ڪريو INVALID_FILE_سائيز ((DWORD)0xffffffff)
#وصف_ڪريو INVALID_سيٽ_FILE_اشارو ((DWORD)-1)
#وصف_ڪريو INVALID_FILE_خاصيتون ((DWORD)-1)

#وصف_ڪريو FILE_BEGIN 0
#وصف_ڪريو FILE_CURRENT 1
#وصف_ڪريو FILE_پڇاڙي 2

#وصف_ڪريو وقت_ZONE_ID_INVALID ((DWORD)0xffffffff)

#وصف_ڪريو WAIT_FAILED ((DWORD)0xffffffff)
#وصف_ڪريو WAIT_OBJECT_0 ((حالت_WAIT_0) + 0)
#وصف_ڪريو WAIT_ABANDONED ((حالت_ABANDONED_WAIT_0) + 0)
#وصف_ڪريو WAIT_ABANDONED_0 ((حالت_ABANDONED_WAIT_0) + 0)
#وصف_ڪريو WAIT_IO_COMPLETION حالت_USER_APC
#وصف_ڪريو STILL_سرگرم حالت_PENDING
#وصف_ڪريو EXCEPTION_ACCESS_VIOLATION حالت_ACCESS_VIOLATION
#وصف_ڪريو EXCEPTION_DATATYPE_MISALIGNMENT حالت_DATATYPE_MISALIGNMENT
#وصف_ڪريو EXCEPTION_BREAKPOINT حالت_BREAKPOINT
#وصف_ڪريو EXCEPTION_SINGLE_قدم حالت_SINGLE_قدم
#وصف_ڪريو EXCEPTION_ARRAY_BOUNDS_EXCEEDED حالت_ARRAY_BOUNDS_EXCEEDED
#وصف_ڪريو EXCEPTION_FLT_DENORMAL_عمليو حالت_FLOAT_DENORMAL_عمليو
#وصف_ڪريو EXCEPTION_FLT_DIVIDE_BY_ZERO حالت_FLOAT_DIVIDE_BY_ZERO
#وصف_ڪريو EXCEPTION_FLT_INEXACT_نتيجو حالت_FLOAT_INEXACT_نتيجو
#وصف_ڪريو EXCEPTION_FLT_INVALID_OPERATION حالت_FLOAT_INVALID_OPERATION
#وصف_ڪريو EXCEPTION_FLT_حد_کان_مٿي حالت_FLOAT_حد_کان_مٿي
#وصف_ڪريو EXCEPTION_FLT_ڍير_CHECK حالت_FLOAT_ڍير_CHECK
#وصف_ڪريو EXCEPTION_FLT_UNDERFLOW حالت_FLOAT_UNDERFLOW
#وصف_ڪريو EXCEPTION_INT_DIVIDE_BY_ZERO حالت_INTEGER_DIVIDE_BY_ZERO
#وصف_ڪريو EXCEPTION_INT_حد_کان_مٿي حالت_INTEGER_حد_کان_مٿي
#وصف_ڪريو EXCEPTION_PRIV_INSTRUCTION حالت_PRIVILEGED_INSTRUCTION
#وصف_ڪريو EXCEPTION_اندريون_صفحو_ERROR حالت_اندريون_صفحو_ERROR
#وصف_ڪريو EXCEPTION_ILLEGAL_INSTRUCTION حالت_ILLEGAL_INSTRUCTION
#وصف_ڪريو EXCEPTION_NONCONTINUABLE_EXCEPTION حالت_NONCONTINUABLE_EXCEPTION
#وصف_ڪريو EXCEPTION_ڍير_حد_کان_مٿي حالت_ڍير_حد_کان_مٿي
#وصف_ڪريو EXCEPTION_INVALID_DISPOSITION حالت_INVALID_DISPOSITION
#وصف_ڪريو EXCEPTION_GUARD_صفحو حالت_GUARD_صفحو_VIOLATION
#وصف_ڪريو EXCEPTION_INVALID_HANDLE حالت_INVALID_HANDLE
#وصف_ڪريو EXCEPTION_POSSIBLE_DEADLOCK حالت_POSSIBLE_DEADLOCK
#وصف_ڪريو CONTROL_C_EXIT حالت_CONTROL_C_EXIT
#وصف_ڪريو Move_يادگيري Rtl_Move_يادگيري
#وصف_ڪريو Copy_يادگيري Rtl_Copy_يادگيري
#وصف_ڪريو Fill_يادگيري Rtl_Fill_يادگيري
#وصف_ڪريو Zero_يادگيري Rtl_Zero_يادگيري
#وصف_ڪريو Secure_Zero_يادگيري Rtl_Secure_Zero_يادگيري

#وصف_ڪريو FILE_FLAG_WRITE_THROUGH 0x80000000
#وصف_ڪريو FILE_FLAG_OVERLAPPED 0x40000000
#وصف_ڪريو FILE_FLAG_NO_BUFFERING 0x20000000
#وصف_ڪريو FILE_FLAG_RANDOM_ACCESS 0x10000000
#وصف_ڪريو FILE_FLAG_SEQUENTIAL_جاچ 0x8000000
#وصف_ڪريو FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#وصف_ڪريو FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#وصف_ڪريو FILE_FLAG_POSIX_SEMANTICS 0x1000000
#وصف_ڪريو FILE_FLAG_OPEN_REPARSE_نقطو 0x200000
#وصف_ڪريو FILE_FLAG_OPEN_NO_RECALL 0x100000
#وصف_ڪريو FILE_FLAG_پهريون_PIPE_INSTANCE 0x80000

#وصف_ڪريو CREATE_NEW 1
#وصف_ڪريو CREATE_ALWAYS 2
#وصف_ڪريو OPEN_EXISTING 3
#وصف_ڪريو OPEN_ALWAYS 4
#وصف_ڪريو TRUNCATE_EXISTING 5

#وصف_ڪريو ترقي_CONTINUE 0
#وصف_ڪريو ترقي_CANCEL 1
#وصف_ڪريو ترقي_STOP 2
#وصف_ڪريو ترقي_QUIET 3

#وصف_ڪريو CALLBACK_CHUNK_ختم 0x0
#وصف_ڪريو CALLBACK_وهڪرو_SWITCH 0x1

#وصف_ڪريو COPY_FILE_FAIL_IF_EXISTS 0x1
#وصف_ڪريو COPY_FILE_RESTARTABLE 0x2
#وصف_ڪريو COPY_FILE_OPEN_ذريعو_FOR_WRITE 0x4
#وصف_ڪريو COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#وصف_ڪريو REPLACEFILE_WRITE_THROUGH 0x1
#وصف_ڪريو REPLACEFILE_IGNORE_ملايو_ERRORS 0x2

#وصف_ڪريو PIPE_ACCESS_INBOUND 0x1
#وصف_ڪريو PIPE_ACCESS_OUTBOUND 0x2
#وصف_ڪريو PIPE_ACCESS_DUPLEX 0x3

#وصف_ڪريو PIPE_CLIENT_پڇاڙي 0x0
#وصف_ڪريو PIPE_SERVER_پڇاڙي 0x1

#وصف_ڪريو PIPE_WAIT 0x0
#وصف_ڪريو PIPE_NOWAIT 0x1
#وصف_ڪريو PIPE_READMODE_BYTE 0x0
#وصف_ڪريو PIPE_READMODE_پيغام 0x2
#وصف_ڪريو PIPE_TYPE_BYTE 0x0
#وصف_ڪريو PIPE_TYPE_پيغام 0x4

#وصف_ڪريو PIPE_UNLIMITED_INSTANCES 255

#وصف_ڪريو SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#وصف_ڪريو SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#وصف_ڪريو SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#وصف_ڪريو SECURITY_DELEGATION (SecurityDelegation << 16)

#وصف_ڪريو SECURITY_CONTEXT_TRACKING 0x40000
#وصف_ڪريو SECURITY_EFFECTIVE_ONLY 0x80000

#وصف_ڪريو SECURITY_SQOS_PRESENT 0x100000
#وصف_ڪريو SECURITY_VALID_SQOS_FLAGS 0x1f0000

  تعريفنوع بنية _OVERLAPPED {
    ULONG_PTR اندروني;
    ULONG_PTR اندروني_مٿاهون;
    اتحاد {
      بنية {
	DWORD وٿي_3;
	DWORD وٿي_مٿاهون_2;
      };
      PVOID اشارو_2;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  تعريفنوع بنية SECURITY_خاصيتون {
    DWORD n_ڊيگهائي;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_خاصيتون_2,*PSECURITY_خاصيتون,*LPSECURITY_خاصيتون;

  تعريفنوع بنية _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#جيڪڏهن_وصف_نه_ٿيل _FILETIME_
#وصف_ڪريو _FILETIME_
  تعريفنوع بنية _FILETIME {
    DWORD dw_هيٺيون_Date_وقت;
    DWORD dw_مٿاهون_Date_وقت;
  } FILETIME,*PFILETIME,*LPFILETIME;
#جيڪڏهن_پورو

  تعريفنوع بنية _SYSTEMTIME {
    لفظ_3 wYear;
    لفظ_3 wMonth;
    لفظ_3 w_Day_جو_Week;
    لفظ_3 wDay;
    لفظ_3 wHour;
    لفظ_3 wMinute;
    لفظ_3 w_ٻيو;
    لفظ_3 wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  تعريفنوع DWORD (WINAPI *PTHREAD_شروعات_ROUTINE)(LPVOID lpThreadParameter);
  تعريفنوع PTHREAD_شروعات_ROUTINE LPTHREAD_شروعات_ROUTINE;
  تعريفنوع VOID (WINAPI *PFIBER_شروعات_ROUTINE)(LPVOID lpFiberParameter);
  تعريفنوع PFIBER_شروعات_ROUTINE LPFIBER_شروعات_ROUTINE;

  تعريفنوع RTL_CRITICAL_SECTION CRITICAL_SECTION;
  تعريفنوع PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  تعريفنوع PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  تعريفنوع RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  تعريفنوع PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  تعريفنوع PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI Encode_اشارو(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_اشارو(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Encode_System_اشارو(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_System_اشارو(PVOID Ptr);

#جيڪڏهن_وصف_ٿيل I_X86_
  تعريفنوع PLDT_داخلا LPLDT_داخلا;
#وإلا
  تعريفنوع LPVOID LPLDT_داخلا;
#جيڪڏهن_پورو

#وصف_ڪريو MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#وصف_ڪريو MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#وصف_ڪريو SP_SERIALCOMM ((DWORD)0x1)

#وصف_ڪريو PST_UNSPECIFIED ((DWORD)0x0)
#وصف_ڪريو PST_RS232 ((DWORD)0x1)
#وصف_ڪريو PST_PARALLELPORT ((DWORD)0x2)
#وصف_ڪريو PST_RS422 ((DWORD)0x3)
#وصف_ڪريو PST_RS423 ((DWORD)0x4)
#وصف_ڪريو PST_RS449 ((DWORD)0x5)
#وصف_ڪريو PST_MODEM ((DWORD)0x6)
#وصف_ڪريو PST_FAX ((DWORD)0x21)
#وصف_ڪريو PST_SCANNER ((DWORD)0x22)
#وصف_ڪريو PST_ڄار_BRIDGE ((DWORD)0x100)
#وصف_ڪريو PST_LAT ((DWORD)0x101)
#وصف_ڪريو PST_TCPIP_TELNET ((DWORD)0x102)
#وصف_ڪريو PST_X25 ((DWORD)0x103)

#وصف_ڪريو PCF_DTRDSR ((DWORD)0x1)
#وصف_ڪريو PCF_RTSCTS ((DWORD)0x2)
#وصف_ڪريو PCF_RLSD ((DWORD)0x4)
#وصف_ڪريو PCF_PARITY_CHECK ((DWORD)0x8)
#وصف_ڪريو PCF_XONXOFF ((DWORD)0x10)
#وصف_ڪريو PCF_SETXCHAR ((DWORD)0x20)
#وصف_ڪريو PCF_TOTALTIMEOUTS ((DWORD)0x40)
#وصف_ڪريو PCF_INTTIMEOUTS ((DWORD)0x80)
#وصف_ڪريو PCF_SPECIALCHARS ((DWORD)0x100)
#وصف_ڪريو PCF_16BITMODE ((DWORD)0x200)

#وصف_ڪريو SP_PARITY ((DWORD)0x1)
#وصف_ڪريو SP_BAUD ((DWORD)0x2)
#وصف_ڪريو SP_DATABITS ((DWORD)0x4)
#وصف_ڪريو SP_STOPBITS ((DWORD)0x8)
#وصف_ڪريو SP_HANDSHAKING ((DWORD)0x10)
#وصف_ڪريو SP_PARITY_CHECK ((DWORD)0x20)
#وصف_ڪريو SP_RLSD ((DWORD)0x40)

#وصف_ڪريو BAUD_075 ((DWORD)0x1)
#وصف_ڪريو BAUD_110 ((DWORD)0x2)
#وصف_ڪريو BAUD_134_5 ((DWORD)0x4)
#وصف_ڪريو BAUD_150 ((DWORD)0x8)
#وصف_ڪريو BAUD_300 ((DWORD)0x10)
#وصف_ڪريو BAUD_600 ((DWORD)0x20)
#وصف_ڪريو BAUD_1200 ((DWORD)0x40)
#وصف_ڪريو BAUD_1800 ((DWORD)0x80)
#وصف_ڪريو BAUD_2400 ((DWORD)0x100)
#وصف_ڪريو BAUD_4800 ((DWORD)0x200)
#وصف_ڪريو BAUD_7200 ((DWORD)0x400)
#وصف_ڪريو BAUD_9600 ((DWORD)0x800)
#وصف_ڪريو BAUD_14400 ((DWORD)0x1000)
#وصف_ڪريو BAUD_19200 ((DWORD)0x2000)
#وصف_ڪريو BAUD_38400 ((DWORD)0x4000)
#وصف_ڪريو BAUD_56K ((DWORD)0x8000)
#وصف_ڪريو BAUD_128K ((DWORD)0x10000)
#وصف_ڪريو BAUD_115200 ((DWORD)0x20000)
#وصف_ڪريو BAUD_57600 ((DWORD)0x40000)
#وصف_ڪريو BAUD_USER ((DWORD)0x10000000)

#وصف_ڪريو DATABITS_5 ((لفظ_3)0x1)
#وصف_ڪريو DATABITS_6 ((لفظ_3)0x2)
#وصف_ڪريو DATABITS_7 ((لفظ_3)0x4)
#وصف_ڪريو DATABITS_8 ((لفظ_3)0x8)
#وصف_ڪريو DATABITS_16 ((لفظ_3)0x10)
#وصف_ڪريو DATABITS_16X ((لفظ_3)0x20)

#وصف_ڪريو STOPBITS_10 ((لفظ_3)0x1)
#وصف_ڪريو STOPBITS_15 ((لفظ_3)0x2)
#وصف_ڪريو STOPBITS_20 ((لفظ_3)0x4)
#وصف_ڪريو PARITY_NONE ((لفظ_3)0x100)
#وصف_ڪريو PARITY_ODD ((لفظ_3)0x200)
#وصف_ڪريو PARITY_EVEN ((لفظ_3)0x400)
#وصف_ڪريو PARITY_MARK ((لفظ_3)0x800)
#وصف_ڪريو PARITY_SPACE ((لفظ_3)0x1000)

  تعريفنوع بنية _COMMPROP {
    لفظ_3 w_Packet_ڊيگهائي;
    لفظ_3 w_Packet_نسخو;
    DWORD dw_Service_نقاب;
    DWORD dwReserved1;
    DWORD dw_Max_Tx_قطار;
    DWORD dw_Max_Rx_قطار;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    لفظ_3 w_Settable_معلومات;
    لفظ_3 wSettableStopParity;
    DWORD dw_Current_Tx_قطار;
    DWORD dw_Current_Rx_قطار;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#وصف_ڪريو COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  تعريفنوع بنية _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD f_Xoff_موڪليل : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cb_اندريون_Que;
    DWORD cb_ٻاهريون_Que;
  } COMSTAT,*LPCOMSTAT;

#وصف_ڪريو DTR_CONTROL_DISABLE 0x0
#وصف_ڪريو DTR_CONTROL_ENABLE 0x1
#وصف_ڪريو DTR_CONTROL_HANDSHAKE 0x2

#وصف_ڪريو RTS_CONTROL_DISABLE 0x0
#وصف_ڪريو RTS_CONTROL_ENABLE 0x1
#وصف_ڪريو RTS_CONTROL_HANDSHAKE 0x2
#وصف_ڪريو RTS_CONTROL_TOGGLE 0x3

  تعريفنوع بنية _DCB {
    DWORD DCBlength;
    DWORD Baud_شرح;
    DWORD f_ٻٽو: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD f_Dsr_حساسيت:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD f_ٻاهريون_X: 1;
    DWORD f_اندريون_X: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    لفظ_3 wReserved;
    لفظ_3 XonLim;
    لفظ_3 XoffLim;
    BYTE Byte_سائيز;
    BYTE Parity;
    BYTE Stop_بٽ;
    حرف XonChar;
    حرف XoffChar;
    حرف ErrorChar;
    حرف EofChar;
    حرف EvtChar;
    لفظ_3 wReserved1;
  } DCB,*LPDCB;

  تعريفنوع بنية _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD Read_ڪل_Timeout_Multiplier;
    DWORD Read_ڪل_Timeout_Constant;
    DWORD Write_ڪل_Timeout_Multiplier;
    DWORD Write_ڪل_Timeout_Constant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  تعريفنوع بنية _COMMCONFIG {
    DWORD dw_سائيز;
    لفظ_3 w_نسخو;
    لفظ_3 wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dw_Provider_وٿي;
    DWORD dw_Provider_سائيز;
    WCHAR wc_Provider_معلومات[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  تعريفنوع بنية _SYSTEM_INFO {
    اتحاد {
      DWORD dwOemId;
      بنية {
	لفظ_3 wProcessorArchitecture;
	لفظ_3 wReserved;
      };
    };
    DWORD dw_صفحو_سائيز;
    LPVOID lp_Minimum_Application_پتو;
    LPVOID lp_وڌ_کان_وڌ_Application_پتو;
    DWORD_PTR dw_سرگرم_Processor_نقاب;
    DWORD dw_عدد_جو_Processors;
    DWORD dwProcessorType;
    DWORD dw_ورهاست_Granularity;
    لفظ_3 wProcessorLevel;
    لفظ_3 wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#وصف_ڪريو FreeModule(hLibModule) FreeLibrary((hLibModule))
#وصف_ڪريو MakeProcInstance(lpProc,hInstance) (lpProc)
#وصف_ڪريو FreeProcInstance(lpProc) (lpProc)

#وصف_ڪريو GMEM_FIXED 0x0
#وصف_ڪريو GMEM_MOVEABLE 0x2
#وصف_ڪريو GMEM_NOCOMPACT 0x10
#وصف_ڪريو GMEM_NODISCARD 0x20
#وصف_ڪريو GMEM_ZEROINIT 0x40
#وصف_ڪريو GMEM_MODIFY 0x80
#وصف_ڪريو GMEM_DISCARDABLE 0x100
#وصف_ڪريو GMEM_NOT_BANKED 0x1000
#وصف_ڪريو GMEM_SHARE 0x2000
#وصف_ڪريو GMEM_DDESHARE 0x2000
#وصف_ڪريو GMEM_NOTIFY 0x4000
#وصف_ڪريو GMEM_هيٺاهون GMEM_NOT_BANKED
#وصف_ڪريو GMEM_VALID_FLAGS 0x7F72
#وصف_ڪريو GMEM_INVALID_HANDLE 0x8000

#وصف_ڪريو GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#وصف_ڪريو GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#وصف_ڪريو GlobalLRUNewest(h) ((HANDLE)(h))
#وصف_ڪريو GlobalLRUOldest(h) ((HANDLE)(h))
#وصف_ڪريو GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#وصف_ڪريو GMEM_DISCARDED 0x4000
#وصف_ڪريو GMEM_LOCKCOUNT 0xff

  تعريفنوع بنية _MEMORYSTATUS {
    DWORD dw_ڊيگهائي;
    DWORD dw_يادگيري_ڀريو;
    سائيز_T dw_ڪل_Phys;
    سائيز_T dwAvailPhys;
    سائيز_T dw_ڪل_صفحو_File;
    سائيز_T dw_Avail_صفحو_File;
    سائيز_T dw_ڪل_Virtual;
    سائيز_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#وصف_ڪريو LMEM_FIXED 0x0
#وصف_ڪريو LMEM_MOVEABLE 0x2
#وصف_ڪريو LMEM_NOCOMPACT 0x10
#وصف_ڪريو LMEM_NODISCARD 0x20
#وصف_ڪريو LMEM_ZEROINIT 0x40
#وصف_ڪريو LMEM_MODIFY 0x80
#وصف_ڪريو LMEM_DISCARDABLE 0xf00
#وصف_ڪريو LMEM_VALID_FLAGS 0xf72
#وصف_ڪريو LMEM_INVALID_HANDLE 0x8000

#وصف_ڪريو LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#وصف_ڪريو LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#وصف_ڪريو NONZEROLHND (LMEM_MOVEABLE)
#وصف_ڪريو NONZEROLPTR (LMEM_FIXED)

#وصف_ڪريو LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#وصف_ڪريو LMEM_DISCARDED 0x4000
#وصف_ڪريو LMEM_LOCKCOUNT 0xff

#وصف_ڪريو DEBUG_PROCESS 0x1
#وصف_ڪريو DEBUG_ONLY_THIS_PROCESS 0x2
#وصف_ڪريو CREATE_SUSPENDED 0x4
#وصف_ڪريو DETACHED_PROCESS 0x8
#وصف_ڪريو CREATE_NEW_CONSOLE 0x10
#وصف_ڪريو عام_ترجيح_CLASS 0x20
#وصف_ڪريو IDLE_ترجيح_CLASS 0x40
#وصف_ڪريو مٿاهون_ترجيح_CLASS 0x80
#وصف_ڪريو REALTIME_ترجيح_CLASS 0x100
#وصف_ڪريو CREATE_NEW_PROCESS_گروهه 0x200
#وصف_ڪريو CREATE_UNICODE_ENVIRONMENT 0x400
#وصف_ڪريو CREATE_SEPARATE_WOW_VDM 0x800
#وصف_ڪريو CREATE_SHARED_WOW_VDM 0x1000
#وصف_ڪريو CREATE_FORCEDOS 0x2000
#وصف_ڪريو هيٺ_عام_ترجيح_CLASS 0x4000
#وصف_ڪريو ABOVE_عام_ترجيح_CLASS 0x8000
#وصف_ڪريو ڍير_سائيز_PARAM_IS_A_RESERVATION 0x10000

#وصف_ڪريو CREATE_BREAKAWAY_FROM_ڪم 0x1000000
#وصف_ڪريو CREATE_PRESERVE_ڪوڊ_AUTHZ_LEVEL 0x2000000

#وصف_ڪريو CREATE_DEFAULT_ERROR_گهڻائي 0x4000000
#وصف_ڪريو CREATE_NO_دري 0x8000000

#وصف_ڪريو PROFILE_USER 0x10000000
#وصف_ڪريو PROFILE_KERNEL 0x20000000
#وصف_ڪريو PROFILE_SERVER 0x40000000

#وصف_ڪريو CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#وصف_ڪريو THREAD_ترجيح_سڀ_کان_هيٺ THREAD_بنياد_ترجيح_MIN
#وصف_ڪريو THREAD_ترجيح_هيٺ_عام (THREAD_ترجيح_سڀ_کان_هيٺ+1)
#وصف_ڪريو THREAD_ترجيح_عام 0
#وصف_ڪريو THREAD_ترجيح_HIGHEST THREAD_بنياد_ترجيح_MAX
#وصف_ڪريو THREAD_ترجيح_ABOVE_عام (THREAD_ترجيح_HIGHEST-1)
#وصف_ڪريو THREAD_ترجيح_ERROR_RETURN (MAXLONG)

#وصف_ڪريو THREAD_ترجيح_وقت_CRITICAL THREAD_بنياد_ترجيح_LOWRT
#وصف_ڪريو THREAD_ترجيح_IDLE THREAD_بنياد_ترجيح_IDLE

#وصف_ڪريو EXCEPTION_DEBUG_EVENT 1
#وصف_ڪريو CREATE_THREAD_DEBUG_EVENT 2
#وصف_ڪريو CREATE_PROCESS_DEBUG_EVENT 3
#وصف_ڪريو EXIT_THREAD_DEBUG_EVENT 4
#وصف_ڪريو EXIT_PROCESS_DEBUG_EVENT 5
#وصف_ڪريو ڀريو_DLL_DEBUG_EVENT 6
#وصف_ڪريو UNLOAD_DLL_DEBUG_EVENT 7
#وصف_ڪريو OUTPUT_DEBUG_STRING_EVENT 8
#وصف_ڪريو RIP_EVENT 9

  تعريفنوع بنية _EXCEPTION_DEBUG_INFO {
    EXCEPTION_رڪارڊ_2 Exception_رڪارڊ;
    DWORD dw_پهريون_Chance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  تعريفنوع بنية _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lp_Thread_Local_بنياد;
    LPTHREAD_شروعات_ROUTINE lp_شروعات_پتو;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  تعريفنوع بنية _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lp_بنياد_جو_Image;
    DWORD dw_Debug_Info_File_وٿي;
    DWORD n_Debug_Info_سائيز;
    LPVOID lp_Thread_Local_بنياد;
    LPTHREAD_شروعات_ROUTINE lp_شروعات_پتو;
    LPVOID lpImageName;
    لفظ_3 fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  تعريفنوع بنية _EXIT_THREAD_DEBUG_INFO {
    DWORD dw_Exit_ڪوڊ;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  تعريفنوع بنية _EXIT_PROCESS_DEBUG_INFO {
    DWORD dw_Exit_ڪوڊ;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  تعريفنوع بنية ڀريو_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lp_بنياد_جو_Dll;
    DWORD dw_Debug_Info_File_وٿي;
    DWORD n_Debug_Info_سائيز;
    LPVOID lpImageName;
    لفظ_3 fUnicode;
  } ڀريو_DLL_DEBUG_INFO_2,*LPLOAD_DLL_DEBUG_INFO;

  تعريفنوع بنية _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lp_بنياد_جو_Dll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  تعريفنوع بنية _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lp_Debug_String_معلومات;
    لفظ_3 fUnicode;
    لفظ_3 n_Debug_String_ڊيگهائي;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  تعريفنوع بنية _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  تعريفنوع بنية _DEBUG_EVENT {
    DWORD dw_Debug_Event_ڪوڊ;
    DWORD dwProcessId;
    DWORD dwThreadId;
    اتحاد {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      ڀريو_DLL_DEBUG_INFO_2 ڀريو_Dll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  تعريفنوع PCONTEXT LPCONTEXT;
  تعريفنوع PEXCEPTION_رڪارڊ LPEXCEPTION_رڪارڊ;
  تعريفنوع PEXCEPTION_اشارا LPEXCEPTION_اشارا;

#وصف_ڪريو DRIVE_UNKNOWN 0
#وصف_ڪريو DRIVE_NO_پاڙ_DIR 1
#وصف_ڪريو DRIVE_REMOVABLE 2
#وصف_ڪريو DRIVE_FIXED 3
#وصف_ڪريو DRIVE_REMOTE 4
#وصف_ڪريو DRIVE_CDROM 5
#وصف_ڪريو DRIVE_RAMDISK 6

#وصف_ڪريو GetFreeSpace(w) (0x100000L)
#وصف_ڪريو FILE_TYPE_UNKNOWN 0x0
#وصف_ڪريو FILE_TYPE_DISK 0x1
#وصف_ڪريو FILE_TYPE_CHAR 0x2
#وصف_ڪريو FILE_TYPE_PIPE 0x3
#وصف_ڪريو FILE_TYPE_REMOTE 0x8000

#وصف_ڪريو STD_داخلا_HANDLE ((DWORD)-10)
#وصف_ڪريو STD_OUTPUT_HANDLE ((DWORD)-11)
#وصف_ڪريو STD_ERROR_HANDLE ((DWORD)-12)

#وصف_ڪريو NOPARITY 0
#وصف_ڪريو ODDPARITY 1
#وصف_ڪريو EVENPARITY 2
#وصف_ڪريو MARKPARITY 3
#وصف_ڪريو SPACEPARITY 4

#وصف_ڪريو ONESTOPBIT 0
#وصف_ڪريو ONE5STOPBITS 1
#وصف_ڪريو TWOSTOPBITS 2

#وصف_ڪريو IGNORE 0
#وصف_ڪريو INFINITE 0xffffffff

#وصف_ڪريو CBR_110 110
#وصف_ڪريو CBR_300 300
#وصف_ڪريو CBR_600 600
#وصف_ڪريو CBR_1200 1200
#وصف_ڪريو CBR_2400 2400
#وصف_ڪريو CBR_4800 4800
#وصف_ڪريو CBR_9600 9600
#وصف_ڪريو CBR_14400 14400
#وصف_ڪريو CBR_19200 19200
#وصف_ڪريو CBR_38400 38400
#وصف_ڪريو CBR_56000 56000
#وصف_ڪريو CBR_57600 57600
#وصف_ڪريو CBR_115200 115200
#وصف_ڪريو CBR_128000 128000
#وصف_ڪريو CBR_256000 256000

#وصف_ڪريو CE_RXOVER 0x1
#وصف_ڪريو CE_OVERRUN 0x2
#وصف_ڪريو CE_RXPARITY 0x4
#وصف_ڪريو CE_چوکٺو 0x8
#وصف_ڪريو CE_BREAK 0x10
#وصف_ڪريو CE_TXFULL 0x100
#وصف_ڪريو CE_PTO 0x200
#وصف_ڪريو CE_IOE 0x400
#وصف_ڪريو CE_DNS 0x800
#وصف_ڪريو CE_OOP 0x1000
#وصف_ڪريو CE_گهڻائي 0x8000

#وصف_ڪريو IE_BADID (-1)
#وصف_ڪريو IE_OPEN (-2)
#وصف_ڪريو IE_NOPEN (-3)
#وصف_ڪريو IE_يادگيري (-4)
#وصف_ڪريو IE_DEFAULT (-5)
#وصف_ڪريو IE_HARDWARE (-10)
#وصف_ڪريو IE_BYTESIZE (-11)
#وصف_ڪريو IE_BAUDRATE (-12)

#وصف_ڪريو EV_RXCHAR 0x1
#وصف_ڪريو EV_RXFLAG 0x2
#وصف_ڪريو EV_TXEMPTY 0x4
#وصف_ڪريو EV_CTS 0x8
#وصف_ڪريو EV_DSR 0x10
#وصف_ڪريو EV_RLSD 0x20
#وصف_ڪريو EV_BREAK 0x40
#وصف_ڪريو EV_ERR 0x80
#وصف_ڪريو EV_RING 0x100
#وصف_ڪريو EV_PERR 0x200
#وصف_ڪريو EV_RX80_ڀريل 0x400
#وصف_ڪريو EV_EVENT1 0x800
#وصف_ڪريو EV_EVENT2 0x1000

#وصف_ڪريو SETXOFF 1
#وصف_ڪريو SETXON 2
#وصف_ڪريو SETRTS 3
#وصف_ڪريو CLRRTS 4
#وصف_ڪريو SETDTR 5
#وصف_ڪريو CLRDTR 6
#وصف_ڪريو RESETDEV 7
#وصف_ڪريو SETBREAK 8
#وصف_ڪريو CLRBREAK 9

#وصف_ڪريو PURGE_TXABORT 0x1
#وصف_ڪريو PURGE_RXABORT 0x2
#وصف_ڪريو PURGE_TXCLEAR 0x4
#وصف_ڪريو PURGE_RXCLEAR 0x8

#وصف_ڪريو LPTx 0x80

#وصف_ڪريو MS_CTS_ON ((DWORD)0x10)
#وصف_ڪريو MS_DSR_ON ((DWORD)0x20)
#وصف_ڪريو MS_RING_ON ((DWORD)0x40)
#وصف_ڪريو MS_RLSD_ON ((DWORD)0x80)

#وصف_ڪريو S_QUEUEEMPTY 0
#وصف_ڪريو S_حد 1
#وصف_ڪريو S_ALLTHRESHOLD 2

#وصف_ڪريو S_عام 0
#وصف_ڪريو S_LEGATO 1
#وصف_ڪريو S_STACCATO 2

#وصف_ڪريو S_PERIOD512 0
#وصف_ڪريو S_PERIOD1024 1
#وصف_ڪريو S_PERIOD2048 2
#وصف_ڪريو S_PERIODVOICE 3
#وصف_ڪريو S_WHITE512 4
#وصف_ڪريو S_WHITE1024 5
#وصف_ڪريو S_WHITE2048 6
#وصف_ڪريو S_WHITEVOICE 7

#وصف_ڪريو S_SERDVNA (-1)
#وصف_ڪريو S_SEROFM (-2)
#وصف_ڪريو S_SERMACT (-3)
#وصف_ڪريو S_SERQFUL (-4)
#وصف_ڪريو S_SERBDNT (-5)
#وصف_ڪريو S_SERDLN (-6)
#وصف_ڪريو S_SERDCC (-7)
#وصف_ڪريو S_SERDTP (-8)
#وصف_ڪريو S_SERDVL (-9)
#وصف_ڪريو S_SERDMD (-10)
#وصف_ڪريو S_SERDSH (-11)
#وصف_ڪريو S_SERDPT (-12)
#وصف_ڪريو S_SERDFQ (-13)
#وصف_ڪريو S_SERDDR (-14)
#وصف_ڪريو S_SERDSR (-15)
#وصف_ڪريو S_SERDST (-16)

#وصف_ڪريو NMPWAIT_WAIT_FOREVER 0xffffffff
#وصف_ڪريو NMPWAIT_NOWAIT 0x1
#وصف_ڪريو NMPWAIT_USE_DEFAULT_WAIT 0x0

#وصف_ڪريو FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_نالا
#وصف_ڪريو FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_ڳولا
#وصف_ڪريو FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#وصف_ڪريو FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#وصف_ڪريو FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#وصف_ڪريو FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#وصف_ڪريو FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#وصف_ڪريو FILE_MAP_COPY SECTION_QUERY
#وصف_ڪريو FILE_MAP_WRITE SECTION_MAP_WRITE
#وصف_ڪريو FILE_MAP_READ SECTION_MAP_READ
#وصف_ڪريو FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#وصف_ڪريو FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#وصف_ڪريو جو_READ 0x0
#وصف_ڪريو جو_WRITE 0x1
#وصف_ڪريو جو_READWRITE 0x2
#وصف_ڪريو جو_SHARE_COMPAT 0x0
#وصف_ڪريو جو_SHARE_EXCLUSIVE 0x10
#وصف_ڪريو جو_SHARE_DENY_WRITE 0x20
#وصف_ڪريو جو_SHARE_DENY_READ 0x30
#وصف_ڪريو جو_SHARE_DENY_NONE 0x40
#وصف_ڪريو جو_PARSE 0x100
#وصف_ڪريو جو_DELETE 0x200
#وصف_ڪريو جو_VERIFY 0x400
#وصف_ڪريو جو_CANCEL 0x800
#وصف_ڪريو جو_CREATE 0x1000
#وصف_ڪريو جو_PROMPT 0x2000
#وصف_ڪريو جو_EXIST 0x4000
#وصف_ڪريو جو_REOPEN 0x8000

#وصف_ڪريو OFS_MAXPATHNAME 128
  تعريفنوع بنية _OFSTRUCT {
    BYTE c_بائيٽون;
    BYTE fFixedDisk;
    لفظ_3 n_Err_ڪوڊ;
    لفظ_3 Reserved1;
    لفظ_3 Reserved2;
    CHAR sz_رستو_Name[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#جيڪڏهن_وصف_نه_ٿيل NOWINBASEINTERLOCK

#جيڪڏهن_وصف_نه_ٿيل _NTOS_

#إذا defined(__ia64__) && !defined(RC_INVOKED)

#وصف_ڪريو InterlockedIncrement _InterlockedIncrement
#وصف_ڪريو InterlockedIncrementAcquire _InterlockedIncrement_acq
#وصف_ڪريو InterlockedIncrementRelease _InterlockedIncrement_rel
#وصف_ڪريو InterlockedDecrement _InterlockedDecrement
#وصف_ڪريو InterlockedDecrementAcquire _InterlockedDecrement_acq
#وصف_ڪريو InterlockedDecrementRelease _InterlockedDecrement_rel
#وصف_ڪريو InterlockedExchange _InterlockedExchange
#وصف_ڪريو Interlocked_Exchange_جوڙيو Interlocked_Exchange_جوڙيو_2
#وصف_ڪريو InterlockedCompareExchange _InterlockedCompareExchange
#وصف_ڪريو InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#وصف_ڪريو InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#وصف_ڪريو Interlocked_Exchange_اشارو Interlocked_Exchange_اشارو_2
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو Interlocked_Compare_Exchange_اشارو_2
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Release Interlocked_Compare_Exchange_اشارو_rel
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Acquire Interlocked_Compare_Exchange_اشارو_acq

#وصف_ڪريو InterlockedIncrement64 _InterlockedIncrement64
#وصف_ڪريو InterlockedDecrement64 _InterlockedDecrement64
#وصف_ڪريو InterlockedExchange64 _InterlockedExchange64
#وصف_ڪريو InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#وصف_ڪريو InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#وصف_ڪريو InterlockedCompareExchange64 _InterlockedCompareExchange64
#وصف_ڪريو InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#وصف_ڪريو InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG متطاير *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG متطاير *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG متطاير *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG متطاير *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG متطاير *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG متطاير *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG متطاير *هدف_2,LONGLONG قدر_3);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG متطاير *هدف_2,LONGLONG قدر_3);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG متطاير *Addend,LONGLONG قدر_3);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG متطاير *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG متطاير *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG متطاير *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG متطاير *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG متطاير *lpAddend);
  LONG __cdecl InterlockedExchange(LONG متطاير *هدف_2,LONG قدر_3);
  LONG __cdecl Interlocked_Exchange_جوڙيو(LONG متطاير *Addend,LONG قدر_3);
  LONG __cdecl InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl Interlocked_Exchange_اشارو(PVOID متطاير *هدف_2,PVOID قدر_3);
  PVOID __cdecl Interlocked_Compare_Exchange_اشارو(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_اشارو_Acquire(PVOID متطاير *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_اشارو_Release(PVOID متطاير *Destination,PVOID Exchange,PVOID Comperand);

#جيڪڏهن_وصف_نه_ٿيل InterlockedAnd
#وصف_ڪريو InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG متطاير *هدف_2,LONG سيٽ_2) {
    LONG i;
    LONG j;
    j = *هدف_2;
    افعل {
      i = j;
      j = InterlockedCompareExchange(هدف_2,i & سيٽ_2,i);
    } طالما(i!=j);
    أرجع j;
  }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل InterlockedOr
#وصف_ڪريو InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG متطاير *هدف_2,LONG سيٽ_2) {
    LONG i;
    LONG j;
    j = *هدف_2;
    افعل {
      i = j;
      j = InterlockedCompareExchange(هدف_2,i | سيٽ_2,i);
    } طالما(i!=j);
    أرجع j;
  }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل InterlockedXor
#وصف_ڪريو InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG متطاير *هدف_2,LONG سيٽ_2) {
    LONG i;
    LONG j;
    j = *هدف_2;
    افعل {
      i = j;
      j = InterlockedCompareExchange(هدف_2,i ^ سيٽ_2,i);
    } طالما(i!=j);
    أرجع j;
  }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل InterlockedAnd64
#وصف_ڪريو InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG متطاير *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old & قدر_3,Old)!=Old);
    أرجع Old;
  }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل InterlockedOr64
#وصف_ڪريو InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG متطاير *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old | قدر_3,Old)!=Old);
    أرجع Old;
  }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل InterlockedXor64
#وصف_ڪريو InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG متطاير *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old ^ قدر_3,Old)!=Old);
    أرجع Old;
  }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل Interlocked_ٻٽو_انگ_Test_And_سيٽ
#وصف_ڪريو Interlocked_ٻٽو_انگ_Test_And_سيٽ Interlocked_ٻٽو_انگ_Test_And_سيٽ_Inline

  __CRT_INLINE BOOLEAN Interlocked_ٻٽو_انگ_Test_And_سيٽ_Inline(LONG *بنياد_2,LONG ٻٽو_انگ_2) {
    LONG t_ٻٽو_انگ;
    t_ٻٽو_انگ = 1<<(ٻٽو_انگ_2 & (حجم (*بنياد_2)*8-1));
    أرجع (BOOLEAN)((InterlockedOr(&بنياد_2[ٻٽو_انگ_2/(حجم(*بنياد_2)*8)],t_ٻٽو_انگ)&t_ٻٽو_انگ)!=0);
  }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل Interlocked_ٻٽو_انگ_Test_And_Reset
#وصف_ڪريو Interlocked_ٻٽو_انگ_Test_And_Reset Interlocked_ٻٽو_انگ_Test_And_Reset_Inline

  __CRT_INLINE BOOLEAN Interlocked_ٻٽو_انگ_Test_And_Reset_Inline(LONG *بنياد_2,LONG ٻٽو_انگ_2) {
    LONG t_ٻٽو_انگ;
    t_ٻٽو_انگ = 1<<(ٻٽو_انگ_2 & (حجم (*بنياد_2)*8-1));
    أرجع (BOOLEAN)((InterlockedAnd(&بنياد_2[ٻٽو_انگ_2/(حجم(*بنياد_2)*8)],~t_ٻٽو_انگ)&t_ٻٽو_انگ)!=0);
  }
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل Interlocked_ٻٽو_انگ_Test_And_Complement
#وصف_ڪريو Interlocked_ٻٽو_انگ_Test_And_Complement Interlocked_ٻٽو_انگ_Test_And_Complement_Inline

  __CRT_INLINE BOOLEAN Interlocked_ٻٽو_انگ_Test_And_Complement_Inline(LONG *بنياد_2,LONG ٻٽو_انگ_2) {
    LONG t_ٻٽو_انگ;
    t_ٻٽو_انگ = 1<<(ٻٽو_انگ_2 & (حجم (*بنياد_2)*8-1));
    أرجع (BOOLEAN)((InterlockedXor(&بنياد_2[ٻٽو_انگ_2/(حجم(*بنياد_2)*8)],t_ٻٽو_انگ)&t_ٻٽو_انگ)!=0);
  }
#جيڪڏهن_پورو
#وإلاإذا defined(__x86_64) && !defined(RC_INVOKED)

#وصف_ڪريو InterlockedIncrement _InterlockedIncrement
#وصف_ڪريو InterlockedIncrementAcquire InterlockedIncrement
#وصف_ڪريو InterlockedIncrementRelease InterlockedIncrement
#وصف_ڪريو InterlockedDecrement _InterlockedDecrement
#وصف_ڪريو InterlockedDecrementAcquire InterlockedDecrement
#وصف_ڪريو InterlockedDecrementRelease InterlockedDecrement
#وصف_ڪريو InterlockedExchange _InterlockedExchange
#وصف_ڪريو Interlocked_Exchange_جوڙيو Interlocked_Exchange_جوڙيو_2
#وصف_ڪريو InterlockedCompareExchange _InterlockedCompareExchange
#وصف_ڪريو InterlockedCompareExchangeAcquire InterlockedCompareExchange
#وصف_ڪريو InterlockedCompareExchangeRelease InterlockedCompareExchange
#وصف_ڪريو Interlocked_Exchange_اشارو Interlocked_Exchange_اشارو_2
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو Interlocked_Compare_Exchange_اشارو_2
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Acquire Interlocked_Compare_Exchange_اشارو_2
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Release Interlocked_Compare_Exchange_اشارو_2
#وصف_ڪريو InterlockedAnd64 _InterlockedAnd64
#وصف_ڪريو InterlockedOr64 _InterlockedOr64
#وصف_ڪريو InterlockedXor64 _InterlockedXor64
#وصف_ڪريو InterlockedIncrement64 _InterlockedIncrement64
#وصف_ڪريو InterlockedDecrement64 _InterlockedDecrement64
#وصف_ڪريو InterlockedExchange64 _InterlockedExchange64
#وصف_ڪريو InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#وصف_ڪريو InterlockedCompareExchange64 _InterlockedCompareExchange64
#وصف_ڪريو InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#وصف_ڪريو InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG متطاير *Addend);
  LONG InterlockedDecrement(LONG متطاير *Addend);
  LONG InterlockedExchange(LONG متطاير *هدف_2,LONG قدر_3);
  LONG Interlocked_Exchange_جوڙيو(LONG متطاير *Addend,LONG قدر_3);
  LONG InterlockedCompareExchange(LONG متطاير *Destination,LONG ExChange,LONG Comperand);
  PVOID Interlocked_Compare_Exchange_اشارو(PVOID متطاير *Destination,PVOID Exchange,PVOID Comperand);
  PVOID Interlocked_Exchange_اشارو(PVOID متطاير *هدف_2,PVOID قدر_3);
  LONG64 InterlockedAnd64(LONG64 متطاير *Destination,LONG64 قدر_3);
  LONG64 InterlockedOr64(LONG64 متطاير *Destination,LONG64 قدر_3);
  LONG64 InterlockedXor64(LONG64 متطاير *Destination,LONG64 قدر_3);
  LONG64 InterlockedIncrement64(LONG64 متطاير *Addend);
  LONG64 InterlockedDecrement64(LONG64 متطاير *Addend);
  LONG64 InterlockedExchange64(LONG64 متطاير *هدف_2,LONG64 قدر_3);
  LONG64 InterlockedExchangeAdd64(LONG64 متطاير *Addend,LONG64 قدر_3);
  LONG64 InterlockedCompareExchange64(LONG64 متطاير *Destination,LONG64 ExChange,LONG64 Comperand);
#وإلا
  LONG WINAPI InterlockedIncrement(LONG متطاير *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG متطاير *lpAddend);
  LONG WINAPI InterlockedExchange(LONG متطاير *هدف_2,LONG قدر_3);

#جيڪڏهن_وصف_نه_ٿيل Interlocked_Exchange_اشارو
#وصف_ڪريو Interlocked_Exchange_اشارو(هدف_2,قدر_3) (PVOID)InterlockedExchange((PLONG)(هدف_2),(LONG)(قدر_3))
#جيڪڏهن_پورو

  LONG WINAPI Interlocked_Exchange_جوڙيو(LONG متطاير *Addend,LONG قدر_3);
  LONG WINAPI InterlockedCompareExchange(LONG متطاير *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG متطاير *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG متطاير *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old & قدر_3,Old)!=Old);
    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG متطاير *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old | قدر_3,Old)!=Old);
    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG متطاير *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    افعل {
      Old = *Destination;
    } طالما(InterlockedCompareExchange64(Destination,Old ^ قدر_3,Old)!=Old);

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

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG متطاير *هدف_2,LONGLONG قدر_3) {
    LONGLONG Old;
    افعل {
      Old = *هدف_2;
    } طالما(InterlockedCompareExchange64(هدف_2,قدر_3,Old)!=Old);
    أرجع Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG متطاير *Addend,LONGLONG قدر_3) {
    LONGLONG Old;
    افعل {
      Old = *Addend;
    } طالما(InterlockedCompareExchange64(Addend,Old + قدر_3,Old)!=Old);
    أرجع Old;
  }

#جيڪڏهن_وصف_نه_ٿيل Interlocked_Compare_Exchange_اشارو
#جيڪڏهن_وصف_ٿيل __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID متطاير *Destination,PVOID ExChange,PVOID Comperand) {
    أرجع((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG متطاير *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو __InlineInterlockedCompareExchangePointer
#وإلا
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG متطاير *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو InterlockedIncrementAcquire InterlockedIncrement
#وصف_ڪريو InterlockedIncrementRelease InterlockedIncrement
#وصف_ڪريو InterlockedDecrementAcquire InterlockedDecrement
#وصف_ڪريو InterlockedDecrementRelease InterlockedDecrement
#وصف_ڪريو InterlockedIncrementAcquire InterlockedIncrement
#وصف_ڪريو InterlockedIncrementRelease InterlockedIncrement
#وصف_ڪريو InterlockedCompareExchangeAcquire InterlockedCompareExchange
#وصف_ڪريو InterlockedCompareExchangeRelease InterlockedCompareExchange
#وصف_ڪريو InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#وصف_ڪريو InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#جيڪڏهن_وصف_نه_ٿيل Interlocked_Compare_Exchange_اشارو_Acquire
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Acquire Interlocked_Compare_Exchange_اشارو
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل Interlocked_Compare_Exchange_اشارو_Release
#وصف_ڪريو Interlocked_Compare_Exchange_اشارو_Release Interlocked_Compare_Exchange_اشارو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#إذا defined(SLIST_سرو) && !defined(_NTOSP_)
  WINBASEAPI VOID WINAPI Initialize_SList_سر(PSLIST_سرو List_سر);
  WINBASEAPI PSLIST_داخلا WINAPI Interlocked_ڪڍو_داخلا_SList(PSLIST_سرو List_سر);
  WINBASEAPI PSLIST_داخلا WINAPI Interlocked_ڌڪو_داخلا_SList(PSLIST_سرو List_سر,PSLIST_داخلا List_داخلا);
  WINBASEAPI PSLIST_داخلا WINAPI InterlockedFlushSList(PSLIST_سرو List_سر);
  WINBASEAPI USHORT WINAPI Query_اونهائي_SList(PSLIST_سرو List_سر);
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL h_Res_معلومات);
  WINBASEAPI LPVOID WINAPI تالو_Resource(HGLOBAL h_Res_معلومات);

#وصف_ڪريو UnlockResource(h_Res_معلومات) ((h_Res_معلومات),0)
#وصف_ڪريو MAXINTATOM 0xC000
#وصف_ڪريو MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((لفظ_3)(i)))
#وصف_ڪريو INVALID_ATOM ((ATOM)0)

  صحيح WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lp_Cmd_سٽ,صحيح nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dw_Exit_ڪوڊ);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI Get_Proc_پتو(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI Get_نسخو(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,سائيز_T dw_بائيٽون);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,سائيز_T dw_بائيٽون,UINT uFlags);
  WINBASEAPI سائيز_T WINAPI Global_سائيز(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI Global_تالو(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI سائيز_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI Global_يادگيري_حالت(LPMEMORYSTATUS lp_بفر);

  تعريفنوع بنية _MEMORYSTATUSEX {
    DWORD dw_ڊيگهائي;
    DWORD dw_يادگيري_ڀريو;
    DWORDLONG ull_ڪل_Phys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ull_ڪل_صفحو_File;
    DWORDLONG ull_Avail_صفحو_File;
    DWORDLONG ull_ڪل_Virtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI Global_يادگيري_حالت_Ex(LPMEMORYSTATUSEX lp_بفر);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,سائيز_T u_بائيٽون);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,سائيز_T u_بائيٽون,UINT uFlags);
  WINBASEAPI LPVOID WINAPI Local_تالو(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI سائيز_T WINAPI Local_سائيز(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI سائيز_T WINAPI LocalShrink(HLOCAL hMem,UINT cb_New_سائيز);
  WINBASEAPI سائيز_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lp_بنياد_پتو,سائيز_T dw_سائيز);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lp_پتو,سائيز_T dw_سائيز,DWORD fl_ورهاست_Type,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lp_پتو,سائيز_T dw_سائيز,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lp_پتو,سائيز_T dw_سائيز,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI سائيز_T WINAPI VirtualQuery(LPCVOID lp_پتو,PMEMORY_BASIC_INFORMATION lp_بفر,سائيز_T dw_ڊيگهائي);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lp_پتو,سائيز_T dw_سائيز,DWORD fl_ورهاست_Type,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lp_بنياد_پتو,سائيز_T dw_Region_سائيز,PVOID *lp_پتا,ULONG_PTR *lpdw_ڳڻپ,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lp_بنياد_پتو,سائيز_T dw_Region_سائيز);
  WINBASEAPI سائيز_T WINAPI Get_Large_صفحو_Minimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD Firmware_جدول_Provider_Signature,PVOID p_Firmware_جدول_Enum_بفر,DWORD بفر_سائيز);
  WINBASEAPI UINT WINAPI Get_System_Firmware_جدول(DWORD Firmware_جدول_Provider_Signature,DWORD Firmware_جدول_ID,PVOID p_Firmware_جدول_بفر,DWORD بفر_سائيز);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lp_پتو,سائيز_T dw_سائيز,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lp_پتو,سائيز_T dw_سائيز,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI سائيز_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lp_پتو,PMEMORY_BASIC_INFORMATION lp_بفر,سائيز_T dw_ڊيگهائي);
  WINBASEAPI HANDLE WINAPI ڍير_Create(DWORD flOptions,سائيز_T dw_Initial_سائيز,سائيز_T dw_وڌ_کان_وڌ_سائيز);
  WINBASEAPI WINBOOL WINAPI ڍير_Destroy(HANDLE h_ڍير);
  WINBASEAPI LPVOID WINAPI ڍير_Alloc(HANDLE h_ڍير,DWORD dwFlags,سائيز_T dw_بائيٽون);
  WINBASEAPI LPVOID WINAPI ڍير_Re_Alloc(HANDLE h_ڍير,DWORD dwFlags,LPVOID lpMem,سائيز_T dw_بائيٽون);
  WINBASEAPI WINBOOL WINAPI ڍير_Free(HANDLE h_ڍير,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI سائيز_T WINAPI ڍير_سائيز_3(HANDLE h_ڍير,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI ڍير_Validate(HANDLE h_ڍير,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI سائيز_T WINAPI ڍير_Compact(HANDLE h_ڍير,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI Get_Process_ڍير(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD عدد_جو_Heaps,PHANDLE ProcessHeaps);

  تعريفنوع بنية PROCESS_ڍير_داخلا {
    PVOID lp_معلومات;
    DWORD cb_معلومات;
    BYTE cbOverhead;
    BYTE i_Region_اشاريو;
    لفظ_3 wFlags;
    اتحاد {
      بنية {
	HANDLE hMem;
	DWORD dwReserved[3];
      } بلاڪ_2;
      بنية {
	DWORD dw_Committed_سائيز;
	DWORD dw_Un_Committed_سائيز;
	LPVOID lp_پهريون_بلاڪ;
	LPVOID lp_آخري_بلاڪ;
      } Region;
    };
  } PROCESS_ڍير_داخلا_2,*LPPROCESS_ڍير_داخلا,*PPROCESS_ڍير_داخلا;

#وصف_ڪريو PROCESS_ڍير_REGION 0x1
#وصف_ڪريو PROCESS_ڍير_UNCOMMITTED_RANGE 0x2
#وصف_ڪريو PROCESS_ڍير_داخلا_BUSY 0x4
#وصف_ڪريو PROCESS_ڍير_داخلا_MOVEABLE 0x10
#وصف_ڪريو PROCESS_ڍير_داخلا_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI ڍير_تالو(HANDLE h_ڍير);
  WINBASEAPI WINBOOL WINAPI ڍير_Unlock(HANDLE h_ڍير);
  WINBASEAPI WINBOOL WINAPI ڍير_Walk(HANDLE h_ڍير,LPPROCESS_ڍير_داخلا lp_داخلا);
  WINBASEAPI WINBOOL WINAPI ڍير_سيٽ_Information(HANDLE ڍير_Handle,ڍير_INFORMATION_CLASS ڍير_Information_Class,PVOID ڍير_Information,سائيز_T ڍير_Information_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI ڍير_Query_Information(HANDLE ڍير_Handle,ڍير_INFORMATION_CLASS ڍير_Information_Class,PVOID ڍير_Information,سائيز_T ڍير_Information_ڊيگهائي,PSIZE_T Return_ڊيگهائي);

#وصف_ڪريو SCS_32_ٻٽو_انگ_ٻٽو 0
#وصف_ڪريو SCS_DOS_ٻٽو 1
#وصف_ڪريو SCS_WOW_ٻٽو 2
#وصف_ڪريو SCS_PIF_ٻٽو 3
#وصف_ڪريو SCS_POSIX_ٻٽو 4
#وصف_ڪريو SCS_OS216_ٻٽو 5
#وصف_ڪريو SCS_64_ٻٽو_انگ_ٻٽو 6

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_ٻٽو_Type Get_ٻٽو_Type_W
#وصف_ڪريو Get_Short_رستو_Name Get_Short_رستو_Name_W
#وصف_ڪريو Get_Long_رستو_Name Get_Long_رستو_Name_W
#وصف_ڪريو Get_Environment_لڙيون Get_Environment_لڙيون_W
#وصف_ڪريو سيٽ_Environment_لڙيون سيٽ_Environment_لڙيون_W
#وصف_ڪريو Free_Environment_لڙيون Free_Environment_لڙيون_W
#وإلا
#وصف_ڪريو Get_ٻٽو_Type Get_ٻٽو_Type_A
#وصف_ڪريو Get_Short_رستو_Name Get_Short_رستو_Name_A
#وصف_ڪريو Get_Long_رستو_Name Get_Long_رستو_Name_A
#وصف_ڪريو Get_Environment_لڙيون_A Get_Environment_لڙيون
#وصف_ڪريو سيٽ_Environment_لڙيون سيٽ_Environment_لڙيون_A
#وصف_ڪريو Free_Environment_لڙيون Free_Environment_لڙيون_A
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو SCS_THIS_PLATFORM_ٻٽو SCS_64_ٻٽو_انگ_ٻٽو
#وإلا
#وصف_ڪريو SCS_THIS_PLATFORM_ٻٽو SCS_32_ٻٽو_انگ_ٻٽو
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI Get_ٻٽو_Type_A(LPCSTR lpApplicationName,LPDWORD lp_ٻٽو_Type);
  WINBASEAPI WINBOOL WINAPI Get_ٻٽو_Type_W(LPCWSTR lpApplicationName,LPDWORD lp_ٻٽو_Type);
  WINBASEAPI DWORD WINAPI Get_Short_رستو_Name_A(LPCSTR lpsz_Long_رستو,LPSTR lpsz_Short_رستو,DWORD cch_بفر);
  WINBASEAPI DWORD WINAPI Get_Short_رستو_Name_W(LPCWSTR lpsz_Long_رستو,LPWSTR lpsz_Short_رستو,DWORD cch_بفر);
  WINBASEAPI DWORD WINAPI Get_Long_رستو_Name_A(LPCSTR lpsz_Short_رستو,LPSTR lpsz_Long_رستو,DWORD cch_بفر);
  WINBASEAPI DWORD WINAPI Get_Long_رستو_Name_W(LPCWSTR lpsz_Short_رستو,LPWSTR lpsz_Long_رستو,DWORD cch_بفر);
  WINBASEAPI WINBOOL WINAPI Get_Process_Affinity_نقاب(HANDLE hProcess,PDWORD_PTR lp_Process_Affinity_نقاب,PDWORD_PTR lp_System_Affinity_نقاب);
  WINBASEAPI WINBOOL WINAPI سيٽ_Process_Affinity_نقاب(HANDLE hProcess,DWORD_PTR dw_Process_Affinity_نقاب);
  WINBASEAPI WINBOOL WINAPI Get_Process_Handle_ڳڻپ(HANDLE hProcess,PDWORD pdw_Handle_ڳڻپ);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lp_Creation_وقت,LPFILETIME lp_Exit_وقت,LPFILETIME lp_Kernel_وقت,LPFILETIME lp_User_وقت);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_سيٽ_سائيز(HANDLE hProcess,PSIZE_T lp_Minimum_Working_سيٽ_سائيز,PSIZE_T lp_وڌ_کان_وڌ_Working_سيٽ_سائيز);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_سيٽ_سائيز_Ex(HANDLE hProcess,PSIZE_T lp_Minimum_Working_سيٽ_سائيز,PSIZE_T lp_وڌ_کان_وڌ_Working_سيٽ_سائيز,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI سيٽ_Process_Working_سيٽ_سائيز(HANDLE hProcess,سائيز_T dw_Minimum_Working_سيٽ_سائيز,سائيز_T dw_وڌ_کان_وڌ_Working_سيٽ_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Process_Working_سيٽ_سائيز_Ex(HANDLE hProcess,سائيز_T dw_Minimum_Working_سيٽ_سائيز,سائيز_T dw_وڌ_کان_وڌ_Working_سيٽ_سائيز,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT u_Exit_ڪوڊ);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT u_Exit_ڪوڊ);
  WINBASEAPI WINBOOL WINAPI Get_Exit_ڪوڊ_Process(HANDLE hProcess,LPDWORD lp_Exit_ڪوڊ);
  WINBASEAPI VOID WINAPI FatalExit(صحيح Exit_ڪوڊ);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI Get_Environment_لڙيون_W(VOID);
  WINBASEAPI WINBOOL WINAPI سيٽ_Environment_لڙيون_A(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI سيٽ_Environment_لڙيون_W(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI Free_Environment_لڙيون_A(LPCH);
  WINBASEAPI WINBOOL WINAPI Free_Environment_لڙيون_W(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dw_Exception_ڪوڊ,DWORD dwExceptionFlags,DWORD n_عدد_جو_Arguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(بنية EXCEPTION_اشارا_2 *ExceptionInfo);

  تعريفنوع LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(بنية EXCEPTION_اشارا_2 *ExceptionInfo);
  تعريفنوع PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI سيٽ_Unhandled_Exception_Filter(LPTOP_LEVEL_EXCEPTION_FILTER lp_چوٽي_Level_Exception_Filter);

#وصف_ڪريو FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(سائيز_T dw_ڍير_سائيز,LPFIBER_شروعات_ROUTINE lp_شروعات_پتو,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(سائيز_T dw_ڍير_Commit_سائيز,سائيز_T dw_ڍير_Reserve_سائيز,DWORD dwFlags,LPFIBER_شروعات_ROUTINE lp_شروعات_پتو,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI Convert_Thread_منزل_Fiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI Convert_Thread_منزل_Fiber_Ex(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Convert_Fiber_منزل_Thread(VOID);
  WINBASEAPI VOID WINAPI Switch_منزل_Fiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI Switch_منزل_Thread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_خاصيتون lp_Thread_خاصيتون,سائيز_T dw_ڍير_سائيز,LPTHREAD_شروعات_ROUTINE lp_شروعات_پتو,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_خاصيتون lp_Thread_خاصيتون,سائيز_T dw_ڍير_سائيز,LPTHREAD_شروعات_ROUTINE lp_شروعات_پتو,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI سيٽ_Thread_ڍير_Guarantee (PULONG ڍير_سائيز_اندريون_بائيٽون);
  WINBASEAPI DWORD WINAPI Get_Process_Id_جو_Thread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI Get_Current_Processor_عدد(VOID);
  WINBASEAPI DWORD_PTR WINAPI سيٽ_Thread_Affinity_نقاب(HANDLE hThread,DWORD_PTR dw_Thread_Affinity_نقاب);
  WINBASEAPI DWORD WINAPI سيٽ_Thread_Ideal_Processor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI سيٽ_Process_ترجيح_Boost(HANDLE hProcess,WINBOOL b_Disable_ترجيح_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Process_ترجيح_Boost(HANDLE hProcess,PBOOL p_Disable_ترجيح_Boost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_وقت latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI سيٽ_Thread_ترجيح(HANDLE hThread,صحيح n_ترجيح);
  WINBASEAPI WINBOOL WINAPI سيٽ_Thread_ترجيح_Boost(HANDLE hThread,WINBOOL b_Disable_ترجيح_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Thread_ترجيح_Boost(HANDLE hThread,PBOOL p_Disable_ترجيح_Boost);
  WINBASEAPI صحيح WINAPI Get_Thread_ترجيح(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lp_Creation_وقت,LPFILETIME lp_Exit_وقت,LPFILETIME lp_Kernel_وقت,LPFILETIME lp_User_وقت);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dw_Exit_ڪوڊ);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dw_Exit_ڪوڊ);
  WINBASEAPI WINBOOL WINAPI Get_Exit_ڪوڊ_Thread(HANDLE hThread,LPDWORD lp_Exit_ڪوڊ);
  WINBASEAPI WINBOOL WINAPI Get_Thread_Selector_داخلا(HANDLE hThread,DWORD dwSelector,LPLDT_داخلا lp_Selector_داخلا);
  WINBASEAPI EXECUTION_STATE WINAPI سيٽ_Thread_Execution_State(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI Get_آخري_Error(VOID);
  WINBASEAPI VOID WINAPI سيٽ_آخري_Error(DWORD dw_Err_ڪوڊ);

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#جيڪڏهن_وصف_ٿيل WINBASE_DECLARE_RESTORE_آخري_ERROR
  WINBASEAPI VOID WINAPI Restore_آخري_Error(DWORD dw_Err_ڪوڊ);

  تعريفنوع VOID (WINAPI *PRESTORE_آخري_ERROR)(DWORD);

#وصف_ڪريو RESTORE_آخري_ERROR_NAME_A "RestoreLastError"
#وصف_ڪريو RESTORE_آخري_ERROR_NAME_W L"RestoreLastError"
#وصف_ڪريو RESTORE_آخري_ERROR_NAME متن_3("RestoreLastError")
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->اندروني)!=حالت_PENDING)

  WINBASEAPI WINBOOL WINAPI Get_Overlapped_نتيجو(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lp_عدد_جو_بائيٽون_Transferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI Create_Io_Completion_پورٽ(HANDLE FileHandle,HANDLE Existing_Completion_پورٽ,ULONG_PTR Completion_ڪنجي,DWORD عدد_جو_Concurrent_ڌاڳا);
  WINBASEAPI WINBOOL WINAPI Get_Queued_Completion_حالت(HANDLE Completion_پورٽ,LPDWORD lp_عدد_جو_بائيٽون_Transferred,PULONG_PTR lp_Completion_ڪنجي,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI Post_Queued_Completion_حالت(HANDLE Completion_پورٽ,DWORD dw_عدد_جو_بائيٽون_Transferred,ULONG_PTR dw_Completion_ڪنجي,LPOVERLAPPED lpOverlapped);

#وصف_ڪريو SEM_FAILCRITICALERRORS 0x1
#وصف_ڪريو SEM_NOGPFAULTERRORBOX 0x2
#وصف_ڪريو SEM_NOALIGNMENTFAULTEXCEPT 0x4
#وصف_ڪريو SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI سيٽ_Error_گهڻائي(UINT u_گهڻائي);
  WINBASEAPI WINBOOL WINAPI Read_Process_يادگيري(HANDLE hProcess,LPCVOID lp_بنياد_پتو,LPVOID lp_بفر,سائيز_T n_سائيز,سائيز_T *lp_عدد_جو_بائيٽون_Read);
  WINBASEAPI WINBOOL WINAPI Write_Process_يادگيري(HANDLE hProcess,LPVOID lp_بنياد_پتو,LPCVOID lp_بفر,سائيز_T n_سائيز,سائيز_T *lp_عدد_جو_بائيٽون_Written);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI سيٽ_Thread_Context(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  تعريفنوع VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI قطار_User_APC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dw_معلومات);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dw_Continue_حالت);
  WINBASEAPI WINBOOL WINAPI Debug_سرگرم_Process(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_سرگرم_Process_Stop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_سيٽ_Process_Kill_On_Exit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI Initialize_Critical_Section_And_Spin_ڳڻپ(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_ڳڻپ);
  WINBASEAPI DWORD WINAPI سيٽ_Critical_Section_Spin_ڳڻپ(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_ڳڻپ);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI سيٽ_Event(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG l_Release_ڳڻپ,LPLONG lp_اڳيون_ڳڻپ);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI Wait_For_گڻو_Objects(DWORD n_ڳڻپ,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI ڀريو_Resource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI Init_Atom_جدول(DWORD n_سائيز);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI سيٽ_Handle_ڳڻپ(UINT u_عدد);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI تالو_File(HANDLE hFile,DWORD dw_File_وٿي_هيٺيون,DWORD dw_File_وٿي_مٿاهون,DWORD n_عدد_جو_بائيٽون_منزل_تالو_هيٺيون,DWORD n_عدد_جو_بائيٽون_منزل_تالو_مٿاهون);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dw_File_وٿي_هيٺيون,DWORD dw_File_وٿي_مٿاهون,DWORD n_عدد_جو_بائيٽون_منزل_Unlock_هيٺيون,DWORD n_عدد_جو_بائيٽون_منزل_Unlock_مٿاهون);
  WINBASEAPI WINBOOL WINAPI تالو_File_Ex(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD n_عدد_جو_بائيٽون_منزل_تالو_هيٺيون,DWORD n_عدد_جو_بائيٽون_منزل_تالو_مٿاهون,LPOVERLAPPED lpOverlapped);

#وصف_ڪريو LOCKFILE_FAIL_IMMEDIATELY 0x1
#وصف_ڪريو LOCKFILE_EXCLUSIVE_تالو 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD n_عدد_جو_بائيٽون_منزل_Unlock_هيٺيون,DWORD n_عدد_جو_بائيٽون_منزل_Unlock_مٿاهون,LPOVERLAPPED lpOverlapped);

  تعريفنوع بنية _BY_HANDLE_FILE_INFORMATION {
    DWORD dw_File_خاصيتون;
    FILETIME ft_Creation_وقت;
    FILETIME ft_آخري_Access_وقت;
    FILETIME ft_آخري_Write_وقت;
    DWORD dw_Volume_Serial_عدد;
    DWORD n_File_سائيز_مٿاهون;
    DWORD n_File_سائيز_هيٺيون;
    DWORD n_عدد_جو_Links;
    DWORD n_File_اشاريو_مٿاهون;
    DWORD n_File_اشاريو_هيٺيون;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو سيٽ_File_Short_Name سيٽ_File_Short_Name_W
#وإلا
#وصف_ڪريو سيٽ_File_Short_Name سيٽ_File_Short_Name_A
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI Get_File_سائيز(HANDLE hFile,LPDWORD lp_File_سائيز_مٿاهون);
  WINBASEAPI WINBOOL WINAPI Get_File_سائيز_Ex(HANDLE hFile,PLARGE_INTEGER lp_File_سائيز);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI سيٽ_Std_Handle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lp_بفر,DWORD n_عدد_جو_بائيٽون_منزل_Write,LPDWORD lp_عدد_جو_بائيٽون_Written,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lp_بفر,DWORD n_عدد_جو_بائيٽون_منزل_Read,LPDWORD lp_عدد_جو_بائيٽون_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dw_Io_Control_ڪوڊ,LPVOID lp_اندريون_بفر,DWORD n_اندريون_بفر_سائيز,LPVOID lp_ٻاهريون_بفر,DWORD n_ٻاهريون_بفر_سائيز,LPDWORD lp_بائيٽون_Returned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI سيٽ_پيغام_انتظار_Indicator(HANDLE h_نياپو_Indicator,ULONG ul_نياپو_ڳڻپ);
  WINBASEAPI WINBOOL WINAPI سيٽ_پڇاڙي_جو_File(HANDLE hFile);
  WINBASEAPI DWORD WINAPI سيٽ_File_اشارو(HANDLE hFile,LONG l_مفاصلو_منزل_Move,PLONG lp_مفاصلو_منزل_Move_مٿاهون,DWORD dw_Move_طريقو);
  WINBASEAPI WINBOOL WINAPI سيٽ_File_اشارو_Ex(HANDLE hFile,LARGE_INTEGER li_مفاصلو_منزل_Move,PLARGE_INTEGER lp_New_File_اشارو,DWORD dw_Move_طريقو);
  WINBASEAPI WINBOOL WINAPI ڳوليو_Close(HANDLE h_ڳوليو_File);
  WINBASEAPI WINBOOL WINAPI Get_File_وقت(HANDLE hFile,LPFILETIME lp_Creation_وقت,LPFILETIME lp_آخري_Access_وقت,LPFILETIME lp_آخري_Write_وقت);
  WINBASEAPI WINBOOL WINAPI سيٽ_File_وقت(HANDLE hFile,CONST FILETIME *lp_Creation_وقت,CONST FILETIME *lp_آخري_Access_وقت,CONST FILETIME *lp_آخري_Write_وقت);
  WINBASEAPI WINBOOL WINAPI سيٽ_File_Valid_معلومات(HANDLE hFile,LONGLONG Valid_معلومات_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI سيٽ_File_Short_Name_A(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI سيٽ_File_Short_Name_W(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE h_ذريعو_Process_Handle,HANDLE h_ذريعو_Handle,HANDLE h_هدف_Process_Handle,LPHANDLE lp_هدف_Handle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI سيٽ_Handle_Information(HANDLE hObject,DWORD dw_نقاب,DWORD dwFlags);

#وصف_ڪريو HANDLE_FLAG_INHERIT 0x1
#وصف_ڪريو HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#وصف_ڪريو HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI ڀريو_Module(LPCSTR lpModuleName,LPVOID lp_Parameter_بلاڪ);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lp_Cmd_سٽ,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI تياري_Comm(HANDLE hFile,DWORD dw_اندريون_قطار,DWORD dw_ٻاهريون_قطار);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdw_سائيز);
  WINBASEAPI WINBOOL WINAPI Get_Comm_نقاب(HANDLE hFile,LPDWORD lp_Evt_نقاب);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI Get_Comm_Modem_حالت(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI سيٽ_Comm_Break(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI سيٽ_Comm_Config(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dw_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Comm_نقاب(HANDLE hFile,DWORD dw_Evt_نقاب);
  WINBASEAPI WINBOOL WINAPI سيٽ_Comm_State(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI سيٽ_Comm_Timeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,حرف cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lp_Evt_نقاب,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI سيٽ_پٽي_Position(HANDLE hDevice,DWORD dw_Position_طريقو,DWORD dw_حصا_ڪريو,DWORD dw_وٿي_هيٺيون,DWORD dw_وٿي_مٿاهون,WINBOOL b_فوري);
  WINBASEAPI DWORD WINAPI Get_پٽي_Position(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdw_حصا_ڪريو,LPDWORD lpdw_وٿي_هيٺيون,LPDWORD lpdw_وٿي_مٿاهون);
  WINBASEAPI DWORD WINAPI Prepare_پٽي(HANDLE hDevice,DWORD dwOperation,WINBOOL b_فوري);
  WINBASEAPI DWORD WINAPI Erase_پٽي(HANDLE hDevice,DWORD dwEraseType,WINBOOL b_فوري);
  WINBASEAPI DWORD WINAPI Create_پٽي_حصا_ڪريو(HANDLE hDevice,DWORD dw_حصا_ڪريو_طريقو,DWORD dw_ڳڻپ,DWORD dw_سائيز);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dw_Tapemark_ڳڻپ,WINBOOL b_فوري);
  WINBASEAPI DWORD WINAPI Get_پٽي_حالت(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI Get_پٽي_Parameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdw_سائيز,LPVOID lp_پٽي_Information);

#وصف_ڪريو GET_پٽي_MEDIA_INFORMATION 0
#وصف_ڪريو GET_پٽي_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI سيٽ_پٽي_Parameters(HANDLE hDevice,DWORD dwOperation,LPVOID lp_پٽي_Information);

#وصف_ڪريو سيٽ_پٽي_MEDIA_INFORMATION 0
#وصف_ڪريو سيٽ_پٽي_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI صحيح WINAPI MulDiv(صحيح n_عدد,صحيح nNumerator,صحيح nDenominator);
  WINBASEAPI VOID WINAPI Get_System_وقت(LPSYSTEMTIME lp_System_وقت);
  WINBASEAPI VOID WINAPI Get_System_وقت_As_File_وقت(LPFILETIME lp_System_وقت_As_File_وقت);
  WINBASEAPI WINBOOL WINAPI سيٽ_System_وقت(CONST SYSTEMTIME *lp_System_وقت);
  WINBASEAPI VOID WINAPI Get_Local_وقت(LPSYSTEMTIME lp_System_وقت);
  WINBASEAPI WINBOOL WINAPI سيٽ_Local_وقت(CONST SYSTEMTIME *lp_System_وقت);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI سيٽ_System_File_Cache_سائيز(سائيز_T Minimum_File_Cache_سائيز,سائيز_T وڌ_کان_وڌ_File_Cache_سائيز,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI Get_System_File_Cache_سائيز(PSIZE_T lp_Minimum_File_Cache_سائيز,PSIZE_T lp_وڌ_کان_وڌ_File_Cache_سائيز,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdw_Quota_استعمال_ٿيل);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lp_Idle_وقت,LPFILETIME lp_Kernel_وقت,LPFILETIME lp_User_وقت);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  تعريفنوع بنية وقت_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } وقت_ZONE_INFORMATION_2,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Format_پيغام Format_پيغام_W
#وإلا
#وصف_ڪريو Format_پيغام Format_پيغام_A
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI System_وقت_منزل_Tz_Specific_Local_وقت(LPTIME_ZONE_INFORMATION lp_وقت_Zone_Information,LPSYSTEMTIME lp_Universal_وقت,LPSYSTEMTIME lp_Local_وقت);
  WINBASEAPI WINBOOL WINAPI Tz_Specific_Local_وقت_منزل_System_وقت(LPTIME_ZONE_INFORMATION lp_وقت_Zone_Information,LPSYSTEMTIME lp_Local_وقت,LPSYSTEMTIME lp_Universal_وقت);
  WINBASEAPI DWORD WINAPI Get_وقت_Zone_Information(LPTIME_ZONE_INFORMATION lp_وقت_Zone_Information);
  WINBASEAPI WINBOOL WINAPI سيٽ_وقت_Zone_Information(CONST وقت_ZONE_INFORMATION_2 *lp_وقت_Zone_Information);
  WINBASEAPI WINBOOL WINAPI System_وقت_منزل_File_وقت(CONST SYSTEMTIME *lp_System_وقت,LPFILETIME lp_File_وقت);
  WINBASEAPI WINBOOL WINAPI File_وقت_منزل_Local_File_وقت(CONST FILETIME *lp_File_وقت,LPFILETIME lp_Local_File_وقت);
  WINBASEAPI WINBOOL WINAPI Local_File_وقت_منزل_File_وقت(CONST FILETIME *lp_Local_File_وقت,LPFILETIME lp_File_وقت);
  WINBASEAPI WINBOOL WINAPI File_وقت_منزل_System_وقت(CONST FILETIME *lp_File_وقت,LPSYSTEMTIME lp_System_وقت);
  WINBASEAPI LONG WINAPI Compare_File_وقت(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI File_وقت_منزل_Dos_Date_وقت(CONST FILETIME *lp_File_وقت,LPWORD lpFatDate,LPWORD lp_Fat_وقت);
  WINBASEAPI WINBOOL WINAPI Dos_Date_وقت_منزل_File_وقت(لفظ_3 wFatDate,لفظ_3 w_Fat_وقت,LPFILETIME lp_File_وقت);
  WINBASEAPI DWORD WINAPI Get_Tick_ڳڻپ(VOID);
  WINBASEAPI WINBOOL WINAPI سيٽ_System_وقت_Adjustment(DWORD dw_وقت_Adjustment,WINBOOL b_وقت_Adjustment_Disabled);
  WINBASEAPI WINBOOL WINAPI Get_System_وقت_Adjustment(PDWORD lp_وقت_Adjustment,PDWORD lp_وقت_Increment,PBOOL lp_وقت_Adjustment_Disabled);
  WINBASEAPI DWORD WINAPI Format_پيغام_A(DWORD dwFlags,LPCVOID lp_ذريعو,DWORD dw_پيغام_Id,DWORD dwLanguageId,LPSTR lp_بفر,DWORD n_سائيز,va_list *Arguments);
  WINBASEAPI DWORD WINAPI Format_پيغام_W(DWORD dwFlags,LPCVOID lp_ذريعو,DWORD dw_پيغام_Id,DWORD dwLanguageId,LPWSTR lp_بفر,DWORD n_سائيز,va_list *Arguments);

#وصف_ڪريو FORMAT_پيغام_ALLOCATE_بفر 0x100
#وصف_ڪريو FORMAT_پيغام_IGNORE_INSERTS 0x200
#وصف_ڪريو FORMAT_پيغام_FROM_STRING 0x400
#وصف_ڪريو FORMAT_پيغام_FROM_HMODULE 0x800
#وصف_ڪريو FORMAT_پيغام_FROM_SYSTEM 0x1000
#وصف_ڪريو FORMAT_پيغام_دليل_ARRAY 0x2000
#وصف_ڪريو FORMAT_پيغام_MAX_ويڪر_نقاب 0xff

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو CreateMailslot CreateMailslotW
#وصف_ڪريو EncryptFile EncryptFileW
#وصف_ڪريو DecryptFile DecryptFileW
#وصف_ڪريو File_Encryption_حالت File_Encryption_حالت_W
#وإلا
#وصف_ڪريو CreateMailslot CreateMailslotA
#وصف_ڪريو EncryptFile EncryptFileA
#وصف_ڪريو DecryptFile DecryptFileA
#وصف_ڪريو File_Encryption_حالت File_Encryption_حالت_A
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_خاصيتون lp_Pipe_خاصيتون,DWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI سيٽ_Named_Pipe_Handle_State(HANDLE hNamedPipe,LPDWORD lp_گهڻائي,LPDWORD lp_Max_Collection_ڳڻپ,LPDWORD lp_Collect_معلومات_Timeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lp_ٻاهريون_بفر_سائيز,LPDWORD lp_اندريون_بفر_سائيز,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lp_بفر,DWORD n_بفر_سائيز,LPDWORD lp_بائيٽون_Read,LPDWORD lp_ڪل_بائيٽون_Avail,LPDWORD lp_بائيٽون_کاٻو_This_پيغام);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lp_اندريون_بفر,DWORD n_اندريون_بفر_سائيز,LPVOID lp_ٻاهريون_بفر,DWORD n_ٻاهريون_بفر_سائيز,LPDWORD lp_بائيٽون_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD n_Max_پيغام_سائيز,DWORD lReadTimeout,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD n_Max_پيغام_سائيز,DWORD lReadTimeout,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lp_Max_پيغام_سائيز,LPDWORD lp_ايندڙ_سائيز,LPDWORD lp_پيغام_ڳڻپ,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI سيٽ_Mailslot_Info(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI Map_View_جو_File(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_وٿي_مٿاهون,DWORD dw_File_وٿي_هيٺيون,سائيز_T dw_عدد_جو_بائيٽون_منزل_Map);
  WINBASEAPI WINBOOL WINAPI Flush_View_جو_File(LPCVOID lp_بنياد_پتو,سائيز_T dw_عدد_جو_بائيٽون_منزل_Flush);
  WINBASEAPI WINBOOL WINAPI Unmap_View_جو_File(LPCVOID lp_بنياد_پتو);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#وصف_ڪريو FILE_ENCRYPTABLE 0
#وصف_ڪريو FILE_IS_ENCRYPTED 1
#وصف_ڪريو FILE_SYSTEM_ATTR 2
#وصف_ڪريو FILE_پاڙ_DIR 3
#وصف_ڪريو FILE_SYSTEM_DIR 4
#وصف_ڪريو FILE_UNKNOWN 5
#وصف_ڪريو FILE_SYSTEM_NOT_SUPPORT 6
#وصف_ڪريو FILE_USER_DISALLOWED 7
#وصف_ڪريو FILE_READ_ONLY 8
#وصف_ڪريو FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI File_Encryption_حالت_A(LPCSTR lpFileName,LPDWORD lp_حالت);
  WINADVAPI WINBOOL WINAPI File_Encryption_حالت_W(LPCWSTR lpFileName,LPDWORD lp_حالت);

#وصف_ڪريو EFS_USE_RECOVERY_ڪنجيون (0x1)

  تعريفنوع DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pb_معلومات,PVOID pvCallbackContext,ULONG ul_ڊيگهائي);
  تعريفنوع DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pb_معلومات,PVOID pvCallbackContext,PULONG ul_ڊيگهائي);

#وصف_ڪريو CREATE_FOR_IMPORT (1)
#وصف_ڪريو CREATE_FOR_DIR (2)
#وصف_ڪريو OVERWRITE_HIDDEN (4)

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو OpenEncryptedFileRaw OpenEncryptedFileRawW
#وصف_ڪريو lstrcmp lstrcmpW
#وصف_ڪريو lstrcmpi lstrcmpiW
#وصف_ڪريو lstrcpyn lstrcpynW
#وصف_ڪريو lstrcpy lstrcpyW
#وصف_ڪريو lstrcat lstrcatW
#وصف_ڪريو lstrlen lstrlenW
#وإلا
#وصف_ڪريو OpenEncryptedFileRaw OpenEncryptedFileRawA
#وصف_ڪريو lstrcmp lstrcmpA
#وصف_ڪريو lstrcmpi lstrcmpiA
#وصف_ڪريو lstrcpyn lstrcpynA
#وصف_ڪريو lstrcpy lstrcpyA
#وصف_ڪريو lstrcat lstrcatA
#وصف_ڪريو lstrlen lstrlenA
#جيڪڏهن_پورو

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI صحيح WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,صحيح i_Max_ڊيگهائي);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,صحيح i_Max_ڊيگهائي);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI صحيح WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI صحيح WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lp_رستو_Name,صحيح iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lp_رستو_Name,صحيح iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lp_بفر,UINT u_بائيٽون);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lp_بفر,UINT u_بائيٽون);
  WINBASEAPI ڊگهو WINAPI _hread(HFILE hFile,LPVOID lp_بفر,ڊگهو l_بائيٽون);
  WINBASEAPI ڊگهو WINAPI _hwrite(HFILE hFile,LPCCH lp_بفر,ڊگهو l_بائيٽون);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG l_وٿي,صحيح iOrigin);
  WINADVAPI WINBOOL WINAPI Is_متن_Unicode(CONST VOID *lpv,صحيح i_سائيز,LPINT lpi_نتيجو);

#وصف_ڪريو FLS_ٻاهريون_جو_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI Fls_Get_قدر(DWORD dw_Fls_اشاريو);
  WINBASEAPI WINBOOL WINAPI Fls_سيٽ_قدر(DWORD dw_Fls_اشاريو,PVOID lp_Fls_معلومات);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dw_Fls_اشاريو);

#وصف_ڪريو TLS_ٻاهريون_جو_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI Tls_Get_قدر(DWORD dw_Tls_اشاريو);
  WINBASEAPI WINBOOL WINAPI Tls_سيٽ_قدر(DWORD dw_Tls_اشاريو,LPVOID lp_Tls_قدر);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dw_Tls_اشاريو);

  تعريفنوع VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dw_Error_ڪوڊ,DWORD dw_عدد_جو_بائيٽون_Transfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI Wait_For_گڻو_Objects_Ex(DWORD n_ڳڻپ,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE h_Object_منزل_Signal,HANDLE h_Object_منزل_Wait_On,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lp_بفر,DWORD n_عدد_جو_بائيٽون_منزل_Read,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lp_بفر,DWORD n_عدد_جو_بائيٽون_منزل_Write,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lp_بفر,DWORD n_عدد_جو_بائيٽون_منزل_Read,LPDWORD lp_عدد_جو_بائيٽون_Read,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dw_هيٺيون_بائيٽون_منزل_Seek,DWORD dw_مٿاهون_بائيٽون_منزل_Seek,LPDWORD lpdw_هيٺيون_Byte_Seeked,LPDWORD lpdw_مٿاهون_Byte_Seeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lp_بفر,DWORD n_عدد_جو_بائيٽون_منزل_Write,LPDWORD lp_عدد_جو_بائيٽون_Written,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  تعريفنوع بنية WIN32_وهڪرو_ID {
    DWORD dw_وهڪرو_Id;
    DWORD dw_وهڪرو_خاصيتون;
    LARGE_INTEGER سائيز_3;
    DWORD dw_وهڪرو_Name_سائيز;
    WCHAR c_وهڪرو_Name[ANYSIZE_ARRAY];
  } WIN32_وهڪرو_ID_2,*LPWIN32_وهڪرو_ID;

#وصف_ڪريو BACKUP_INVALID 0x0
#وصف_ڪريو BACKUP_معلومات 0x1
#وصف_ڪريو BACKUP_EA_معلومات 0x2
#وصف_ڪريو BACKUP_SECURITY_معلومات 0x3
#وصف_ڪريو BACKUP_ALTERNATE_معلومات 0x4
#وصف_ڪريو BACKUP_LINK 0x5
#وصف_ڪريو BACKUP_PROPERTY_معلومات 0x6
#وصف_ڪريو BACKUP_OBJECT_ID 0x7
#وصف_ڪريو BACKUP_REPARSE_معلومات 0x8
#وصف_ڪريو BACKUP_SPARSE_بلاڪ 0x9

#وصف_ڪريو وهڪرو_عام_ATTRIBUTE 0x0
#وصف_ڪريو وهڪرو_MODIFIED_WHEN_READ 0x1
#وصف_ڪريو وهڪرو_شامل_آهي_SECURITY 0x2
#وصف_ڪريو وهڪرو_شامل_آهي_PROPERTIES 0x4
#وصف_ڪريو وهڪرو_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_عدد_جو_بائيٽون_منزل_Read,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_عدد_جو_بائيٽون_منزل_Write,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#وصف_ڪريو STARTF_USESHOWWINDOW 0x1
#وصف_ڪريو STARTF_USESIZE 0x2
#وصف_ڪريو STARTF_USEPOSITION 0x4
#وصف_ڪريو STARTF_USECOUNTCHARS 0x8
#وصف_ڪريو STARTF_USEFILLATTRIBUTE 0x10
#وصف_ڪريو STARTF_RUNFULLSCREEN 0x20
#وصف_ڪريو STARTF_FORCEONFEEDBACK 0x40
#وصف_ڪريو STARTF_FORCEOFFFEEDBACK 0x80
#وصف_ڪريو STARTF_USESTDHANDLES 0x100

#وصف_ڪريو STARTF_USEHOTKEY 0x200

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
    لفظ_3 w_Show_دري;
    لفظ_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_داخلا;
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
    لفظ_3 w_Show_دري;
    لفظ_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_داخلا;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع STARTUPINFOW STARTUPINFO;
  تعريفنوع LPSTARTUPINFOW LPSTARTUPINFO;
#وإلا
  تعريفنوع STARTUPINFOA STARTUPINFO;
  تعريفنوع LPSTARTUPINFOA LPSTARTUPINFO;
#جيڪڏهن_پورو

#وصف_ڪريو SHUTDOWN_NORETRY 0x1

  تعريفنوع بنية WIN32_ڳوليو_DATAA {
    DWORD dw_File_خاصيتون;
    FILETIME ft_Creation_وقت;
    FILETIME ft_آخري_Access_وقت;
    FILETIME ft_آخري_Write_وقت;
    DWORD n_File_سائيز_مٿاهون;
    DWORD n_File_سائيز_هيٺيون;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_رستو];
    CHAR cAlternateFileName[14];
  } WIN32_ڳوليو_DATAA_2,*PWIN32_ڳوليو_DATAA,*LPWIN32_ڳوليو_DATAA;

  تعريفنوع بنية WIN32_ڳوليو_DATAW {
    DWORD dw_File_خاصيتون;
    FILETIME ft_Creation_وقت;
    FILETIME ft_آخري_Access_وقت;
    FILETIME ft_آخري_Write_وقت;
    DWORD n_File_سائيز_مٿاهون;
    DWORD n_File_سائيز_هيٺيون;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_رستو];
    WCHAR cAlternateFileName[14];
  } WIN32_ڳوليو_DATAW_2,*PWIN32_ڳوليو_DATAW,*LPWIN32_ڳوليو_DATAW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WIN32_ڳوليو_DATAW_2 WIN32_ڳوليو_معلومات;
  تعريفنوع PWIN32_ڳوليو_DATAW PWIN32_ڳوليو_معلومات;
  تعريفنوع LPWIN32_ڳوليو_DATAW LPWIN32_ڳوليو_معلومات;
#وإلا
  تعريفنوع WIN32_ڳوليو_DATAA_2 WIN32_ڳوليو_معلومات;
  تعريفنوع PWIN32_ڳوليو_DATAA PWIN32_ڳوليو_معلومات;
  تعريفنوع LPWIN32_ڳوليو_DATAA LPWIN32_ڳوليو_معلومات;
#جيڪڏهن_پورو

  تعريفنوع بنية WIN32_FILE_ATTRIBUTE_معلومات {
    DWORD dw_File_خاصيتون;
    FILETIME ft_Creation_وقت;
    FILETIME ft_آخري_Access_وقت;
    FILETIME ft_آخري_Write_وقت;
    DWORD n_File_سائيز_مٿاهون;
    DWORD n_File_سائيز_هيٺيون;
  } WIN32_FILE_ATTRIBUTE_معلومات_2,*LPWIN32_FILE_ATTRIBUTE_معلومات;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو CreateMutex CreateMutexW
#وصف_ڪريو OpenMutex OpenMutexW
#وصف_ڪريو CreateEvent CreateEventW
#وصف_ڪريو OpenEvent OpenEventW
#وصف_ڪريو CreateSemaphore CreateSemaphoreW
#وصف_ڪريو OpenSemaphore OpenSemaphoreW
#وإلا
#وصف_ڪريو CreateMutex CreateMutexA
#وصف_ڪريو OpenMutex OpenMutexA
#وصف_ڪريو CreateEvent CreateEventA
#وصف_ڪريو OpenEvent OpenEventA
#وصف_ڪريو CreateSemaphore CreateSemaphoreA
#وصف_ڪريو OpenSemaphore OpenSemaphoreA
#جيڪڏهن_پورو

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_خاصيتون lp_Mutex_خاصيتون,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_خاصيتون lp_Mutex_خاصيتون,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_خاصيتون lp_Event_خاصيتون,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_خاصيتون lp_Event_خاصيتون,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_خاصيتون lp_Semaphore_خاصيتون,LONG l_Initial_ڳڻپ,LONG l_وڌ_کان_وڌ_ڳڻپ,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_خاصيتون lp_Semaphore_خاصيتون,LONG l_Initial_ڳڻپ,LONG l_وڌ_کان_وڌ_ڳڻپ,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  تعريفنوع VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lp_Arg_منزل_Completion_Routine,DWORD dw_Timer_هيٺيون_قدر,DWORD dw_Timer_مٿاهون_قدر);

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو CreateWaitableTimer CreateWaitableTimerW
#وصف_ڪريو OpenWaitableTimer OpenWaitableTimerW
#وصف_ڪريو CreateFileMapping CreateFileMappingW
#وصف_ڪريو OpenFileMapping OpenFileMappingW
#وصف_ڪريو Get_Logical_Drive_لڙيون Get_Logical_Drive_لڙيون_W
#وصف_ڪريو ڀريو_Library ڀريو_Library_W
#وصف_ڪريو ڀريو_Library_Ex ڀريو_Library_Ex_W
#وصف_ڪريو GetModuleFileName GetModuleFileNameW
#وصف_ڪريو GetModuleHandle GetModuleHandleW
#وإلا
#وصف_ڪريو CreateWaitableTimer CreateWaitableTimerA
#وصف_ڪريو OpenWaitableTimer OpenWaitableTimerA
#وصف_ڪريو CreateFileMapping CreateFileMappingA
#وصف_ڪريو OpenFileMapping OpenFileMappingA
#وصف_ڪريو Get_Logical_Drive_لڙيون Get_Logical_Drive_لڙيون_A
#وصف_ڪريو ڀريو_Library ڀريو_Library_A
#وصف_ڪريو ڀريو_Library_Ex ڀريو_Library_Ex_A
#وصف_ڪريو GetModuleFileName GetModuleFileNameA
#وصف_ڪريو GetModuleHandle GetModuleHandleA
#جيڪڏهن_پورو

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_خاصيتون lp_Timer_خاصيتون,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_خاصيتون lp_Timer_خاصيتون,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI سيٽ_Waitable_Timer(HANDLE hTimer,ثابت LARGE_INTEGER *lp_Due_وقت,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lp_Arg_منزل_Completion_Routine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_خاصيتون lp_File_Mapping_خاصيتون,DWORD flProtect,DWORD dw_وڌ_کان_وڌ_سائيز_مٿاهون,DWORD dw_وڌ_کان_وڌ_سائيز_هيٺيون,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_خاصيتون lp_File_Mapping_خاصيتون,DWORD flProtect,DWORD dw_وڌ_کان_وڌ_سائيز_مٿاهون,DWORD dw_وڌ_کان_وڌ_سائيز_هيٺيون,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_لڙيون_A(DWORD n_بفر_ڊيگهائي,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_لڙيون_W(DWORD n_بفر_ڊيگهائي,LPWSTR lp_بفر);

  تعريفنوع تعداد يادگيري_RESOURCE_NOTIFICATION_TYPE {
    هيٺيون_يادگيري_Resource_Notification,مٿاهون_يادگيري_Resource_Notification
  } يادگيري_RESOURCE_NOTIFICATION_TYPE_2;

  WINBASEAPI HANDLE WINAPI Create_يادگيري_Resource_Notification(يادگيري_RESOURCE_NOTIFICATION_TYPE_2 NotificationType);
  WINBASEAPI WINBOOL WINAPI Query_يادگيري_Resource_Notification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI ڀريو_Library_A(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI ڀريو_Library_W(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI ڀريو_Library_Ex_A(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI ڀريو_Library_Ex_W(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#وصف_ڪريو DONT_RESOLVE_DLL_REFERENCES 0x1
#وصف_ڪريو ڀريو_LIBRARY_AS_DATAFILE 0x2
#وصف_ڪريو ڀريو_WITH_ALTERED_ڳولا_رستو 0x8
#وصف_ڪريو ڀريو_IGNORE_ڪوڊ_AUTHZ_LEVEL 0x10
#وصف_ڪريو ڀريو_LIBRARY_AS_IMAGE_RESOURCE 0x20
#وصف_ڪريو ڀريو_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40
#وصف_ڪريو ڀريو_LIBRARY_REQUIRE_SIGNED_هدف 0x80
#وصف_ڪريو ڀريو_LIBRARY_ڳولا_DLL_ڀريو_DIR 0x100
#وصف_ڪريو ڀريو_LIBRARY_ڳولا_APPLICATION_DIR 0x200
#وصف_ڪريو ڀريو_LIBRARY_ڳولا_USER_DIRS 0x400
#وصف_ڪريو ڀريو_LIBRARY_ڳولا_SYSTEM32 0x800
#وصف_ڪريو ڀريو_LIBRARY_ڳولا_DEFAULT_DIRS 0x1000
#وصف_ڪريو ڀريو_LIBRARY_محفوظ_CURRENT_DIRS 0x2000

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD n_سائيز);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD n_سائيز);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#وصف_ڪريو GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#وصف_ڪريو GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#وصف_ڪريو GET_MODULE_HANDLE_EX_FLAG_FROM_پتو (0x4)

  تعريفنوع WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  تعريفنوع WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#وصف_ڪريو GetModuleHandleEx GetModuleHandleExW
#وإلا
#وصف_ڪريو PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#وصف_ڪريو GetModuleHandleEx GetModuleHandleExA
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Need_Current_Directory_For_Exe_رستو Need_Current_Directory_For_Exe_رستو_W
#وصف_ڪريو CreateProcess CreateProcessW
#وصف_ڪريو FatalAppExit FatalAppExitW
#وصف_ڪريو GetStartupInfo GetStartupInfoW
#وصف_ڪريو Get_Command_سٽ Get_Command_سٽ_W
#وصف_ڪريو GetEnvironmentVariable GetEnvironmentVariableW
#وصف_ڪريو سيٽ_Environment_Variable سيٽ_Environment_Variable_W
#وصف_ڪريو Expand_Environment_لڙيون Expand_Environment_لڙيون_W
#وصف_ڪريو GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#وصف_ڪريو سيٽ_Firmware_Environment_Variable سيٽ_Firmware_Environment_Variable_W
#وصف_ڪريو OutputDebugString OutputDebugStringW
#وصف_ڪريو ڳوليو_Resource ڳوليو_Resource_W
#وصف_ڪريو ڳوليو_Resource_Ex ڳوليو_Resource_Ex_W
#وإلا
#وصف_ڪريو Need_Current_Directory_For_Exe_رستو Need_Current_Directory_For_Exe_رستو_A
#وصف_ڪريو CreateProcess CreateProcessA
#وصف_ڪريو FatalAppExit FatalAppExitA
#وصف_ڪريو GetStartupInfo GetStartupInfoA
#وصف_ڪريو Get_Command_سٽ Get_Command_سٽ_A
#وصف_ڪريو GetEnvironmentVariable GetEnvironmentVariableA
#وصف_ڪريو سيٽ_Environment_Variable سيٽ_Environment_Variable_A
#وصف_ڪريو Expand_Environment_لڙيون Expand_Environment_لڙيون_A
#وصف_ڪريو GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#وصف_ڪريو سيٽ_Firmware_Environment_Variable سيٽ_Firmware_Environment_Variable_A
#وصف_ڪريو OutputDebugString OutputDebugStringA
#وصف_ڪريو ڳوليو_Resource ڳوليو_Resource_A
#وصف_ڪريو ڳوليو_Resource_Ex ڳوليو_Resource_Ex_A
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_رستو_A(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_رستو_W(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lp_Command_سٽ,LPSECURITY_خاصيتون lp_Process_خاصيتون,LPSECURITY_خاصيتون lp_Thread_خاصيتون,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lp_Command_سٽ,LPSECURITY_خاصيتون lp_Process_خاصيتون,LPSECURITY_خاصيتون lp_Thread_خاصيتون,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI جوڙيو_Local_Alternate_Computer_Name_A(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI جوڙيو_Local_Alternate_Computer_Name_W(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI سيٽ_Process_Shutdown_Parameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI Get_Process_نسخو(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lp_پيغام_متن);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lp_پيغام_متن);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI Get_Command_سٽ_A(VOID);
  WINBASEAPI LPWSTR WINAPI Get_Command_سٽ_W(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lp_بفر,DWORD n_سائيز);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lp_بفر,DWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Environment_Variable_A(LPCSTR lpName,LPCSTR lp_قدر);
  WINBASEAPI WINBOOL WINAPI سيٽ_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lp_قدر);
  WINBASEAPI DWORD WINAPI Expand_Environment_لڙيون_A(LPCSTR lpSrc,LPSTR lpDst,DWORD n_سائيز);
  WINBASEAPI DWORD WINAPI Expand_Environment_لڙيون_W(LPCWSTR lpSrc,LPWSTR lpDst,DWORD n_سائيز);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_بفر,DWORD n_سائيز);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_بفر,DWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Firmware_Environment_Variable_A(LPCSTR lpName,LPCSTR lpGuid,PVOID p_قدر,DWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Firmware_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_قدر,DWORD n_سائيز);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI ڳوليو_Resource_A(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI ڳوليو_Resource_W(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI ڳوليو_Resource_Ex_A(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,لفظ_3 wLanguage);
  WINBASEAPI HRSRC WINAPI ڳوليو_Resource_Ex_W(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,لفظ_3 wLanguage);

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ENUMRESTYPEPROC ENUMRESTYPEPROCW
#وصف_ڪريو ENUMRESNAMEPROC ENUMRESNAMEPROCW
#وصف_ڪريو ENUMRESLANGPROC ENUMRESLANGPROCW
#وصف_ڪريو EnumResourceTypes EnumResourceTypesW
#وصف_ڪريو Enum_Resource_نالا Enum_Resource_نالا_W
#وصف_ڪريو EnumResourceLanguages EnumResourceLanguagesW
#وصف_ڪريو BeginUpdateResource BeginUpdateResourceW
#وصف_ڪريو UpdateResource UpdateResourceW
#وصف_ڪريو پڇاڙي_Update_Resource پڇاڙي_Update_Resource_W
#وصف_ڪريو Global_جوڙيو_Atom Global_جوڙيو_Atom_W
#وصف_ڪريو Global_ڳوليو_Atom Global_ڳوليو_Atom_W
#وصف_ڪريو GlobalGetAtomName GlobalGetAtomNameW
#وصف_ڪريو جوڙيو_Atom جوڙيو_Atom_W
#وصف_ڪريو ڳوليو_Atom ڳوليو_Atom_W
#وصف_ڪريو GetAtomName GetAtomNameW
#وصف_ڪريو GetProfileInt GetProfileIntW
#وصف_ڪريو GetProfileString GetProfileStringW
#وصف_ڪريو WriteProfileString WriteProfileStringW
#وصف_ڪريو GetProfileSection GetProfileSectionW
#وصف_ڪريو WriteProfileSection WriteProfileSectionW
#وصف_ڪريو Get_ذاتي_Profile_Int Get_ذاتي_Profile_Int_W
#وصف_ڪريو Get_ذاتي_Profile_String Get_ذاتي_Profile_String_W
#وصف_ڪريو Write_ذاتي_Profile_String Write_ذاتي_Profile_String_W
#وصف_ڪريو Get_ذاتي_Profile_Section Get_ذاتي_Profile_Section_W
#وصف_ڪريو Write_ذاتي_Profile_Section Write_ذاتي_Profile_Section_W
#وصف_ڪريو Get_ذاتي_Profile_Section_نالا Get_ذاتي_Profile_Section_نالا_W
#وصف_ڪريو Get_ذاتي_Profile_Struct Get_ذاتي_Profile_Struct_W
#وصف_ڪريو Write_ذاتي_Profile_Struct Write_ذاتي_Profile_Struct_W
#وصف_ڪريو GetDriveType GetDriveTypeW
#وصف_ڪريو GetSystemDirectory GetSystemDirectoryW
#وصف_ڪريو Get_عارضي_رستو Get_عارضي_رستو_W
#وصف_ڪريو Get_عارضي_File_Name Get_عارضي_File_Name_W
#وصف_ڪريو GetWindowsDirectory GetWindowsDirectoryW
#وصف_ڪريو GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#وصف_ڪريو جوڙيو_Local_Alternate_Computer_Name جوڙيو_Local_Alternate_Computer_Name_W
#وإلا
#وصف_ڪريو ENUMRESTYPEPROC ENUMRESTYPEPROCA
#وصف_ڪريو ENUMRESNAMEPROC ENUMRESNAMEPROCA
#وصف_ڪريو ENUMRESLANGPROC ENUMRESLANGPROCA
#وصف_ڪريو EnumResourceTypes EnumResourceTypesA
#وصف_ڪريو Enum_Resource_نالا Enum_Resource_نالا_A
#وصف_ڪريو EnumResourceLanguages EnumResourceLanguagesA
#وصف_ڪريو BeginUpdateResource BeginUpdateResourceA
#وصف_ڪريو UpdateResource UpdateResourceA
#وصف_ڪريو پڇاڙي_Update_Resource پڇاڙي_Update_Resource_A
#وصف_ڪريو Global_جوڙيو_Atom Global_جوڙيو_Atom_A
#وصف_ڪريو Global_ڳوليو_Atom Global_ڳوليو_Atom_A
#وصف_ڪريو GlobalGetAtomName GlobalGetAtomNameA
#وصف_ڪريو جوڙيو_Atom جوڙيو_Atom_A
#وصف_ڪريو ڳوليو_Atom ڳوليو_Atom_A
#وصف_ڪريو GetAtomName GetAtomNameA
#وصف_ڪريو GetProfileInt GetProfileIntA
#وصف_ڪريو GetProfileString GetProfileStringA
#وصف_ڪريو WriteProfileString WriteProfileStringA
#وصف_ڪريو GetProfileSection GetProfileSectionA
#وصف_ڪريو WriteProfileSection WriteProfileSectionA
#وصف_ڪريو Get_ذاتي_Profile_Int Get_ذاتي_Profile_Int_A
#وصف_ڪريو Get_ذاتي_Profile_String Get_ذاتي_Profile_String_A
#وصف_ڪريو Write_ذاتي_Profile_String Write_ذاتي_Profile_String_A
#وصف_ڪريو Get_ذاتي_Profile_Section Get_ذاتي_Profile_Section_A
#وصف_ڪريو Write_ذاتي_Profile_Section Write_ذاتي_Profile_Section_A
#وصف_ڪريو Get_ذاتي_Profile_Section_نالا Get_ذاتي_Profile_Section_نالا_A
#وصف_ڪريو Get_ذاتي_Profile_Struct Get_ذاتي_Profile_Struct_A
#وصف_ڪريو Write_ذاتي_Profile_Struct Write_ذاتي_Profile_Struct_A
#وصف_ڪريو GetDriveType GetDriveTypeA
#وصف_ڪريو GetSystemDirectory GetSystemDirectoryA
#وصف_ڪريو Get_عارضي_رستو Get_عارضي_رستو_A
#وصف_ڪريو Get_عارضي_File_Name Get_عارضي_File_Name_A
#وصف_ڪريو GetWindowsDirectory GetWindowsDirectoryA
#وصف_ڪريو GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#وصف_ڪريو جوڙيو_Local_Alternate_Computer_Name جوڙيو_Local_Alternate_Computer_Name_A
#جيڪڏهن_پورو

  تعريفنوع WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,لفظ_3 wLanguage,LONG_PTR lParam);
  تعريفنوع WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,لفظ_3 wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_نالا_A(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_نالا_W(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,لفظ_3 wLanguage,LPVOID lp_معلومات,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,لفظ_3 wLanguage,LPVOID lp_معلومات,DWORD cb);
  WINBASEAPI WINBOOL WINAPI پڇاڙي_Update_Resource_A(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI پڇاڙي_Update_Resource_W(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI Global_جوڙيو_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_جوڙيو_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ڳوليو_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ڳوليو_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lp_بفر,صحيح n_سائيز);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lp_بفر,صحيح n_سائيز);
  WINBASEAPI ATOM WINAPI جوڙيو_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI جوڙيو_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI ڳوليو_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI ڳوليو_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lp_بفر,صحيح n_سائيز);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lp_بفر,صحيح n_سائيز);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lp_ڪنجي_Name,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_ڪنجي_Name,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lp_ڪنجي_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_سائيز);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_ڪنجي_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lp_ڪنجي_Name,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_ڪنجي_Name,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_سائيز);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI Get_ذاتي_Profile_Int_A(LPCSTR lpAppName,LPCSTR lp_ڪنجي_Name,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI Get_ذاتي_Profile_Int_W(LPCWSTR lpAppName,LPCWSTR lp_ڪنجي_Name,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ذاتي_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_ڪنجي_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_سائيز,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ذاتي_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_ڪنجي_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_سائيز,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ذاتي_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_ڪنجي_Name,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ذاتي_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_ڪنجي_Name,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ذاتي_Profile_Section_A(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_سائيز,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ذاتي_Profile_Section_W(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_سائيز,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ذاتي_Profile_Section_A(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_ذاتي_Profile_Section_W(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ذاتي_Profile_Section_نالا_A(LPSTR lpsz_Return_بفر,DWORD n_سائيز,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_ذاتي_Profile_Section_نالا_W(LPWSTR lpsz_Return_بفر,DWORD n_سائيز,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Get_ذاتي_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_ڪنجي,LPVOID lpStruct,UINT u_سائيز_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Get_ذاتي_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_ڪنجي,LPVOID lpStruct,UINT u_سائيز_Struct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_ذاتي_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_ڪنجي,LPVOID lpStruct,UINT u_سائيز_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_ذاتي_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_ڪنجي,LPVOID lpStruct,UINT u_سائيز_Struct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lp_پاڙ_رستو_Name);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lp_پاڙ_رستو_Name);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lp_بفر,UINT u_سائيز);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lp_بفر,UINT u_سائيز);
  WINBASEAPI DWORD WINAPI Get_عارضي_رستو_A(DWORD n_بفر_ڊيگهائي,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI Get_عارضي_رستو_W(DWORD n_بفر_ڊيگهائي,LPWSTR lp_بفر);
  WINBASEAPI UINT WINAPI Get_عارضي_File_Name_A(LPCSTR lp_رستو_Name,LPCSTR lp_اڳياڙي_String,UINT uUnique,LPSTR lp_عارضي_File_Name);
  WINBASEAPI UINT WINAPI Get_عارضي_File_Name_W(LPCWSTR lp_رستو_Name,LPCWSTR lp_اڳياڙي_String,UINT uUnique,LPWSTR lp_عارضي_File_Name);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lp_بفر,UINT u_سائيز);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lp_بفر,UINT u_سائيز);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lp_بفر,UINT u_سائيز);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lp_بفر,UINT u_سائيز);

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetSystemWow64Directory GetSystemWow64DirectoryW
#وإلا
#وصف_ڪريو GetSystemWow64Directory GetSystemWow64DirectoryA
#جيڪڏهن_پورو

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lp_بفر,UINT u_سائيز);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lp_بفر,UINT u_سائيز);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *Old_قدر);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID Ol_قدر);

  تعريفنوع UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lp_بفر,UINT u_سائيز);
  تعريفنوع UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lp_بفر,UINT u_سائيز);

#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T متن_3("GetSystemWow64DirectoryA")
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T متن_3("GetSystemWow64DirectoryW")

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#وإلا
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#وصف_ڪريو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو سيٽ_Current_Directory سيٽ_Current_Directory_W
#وصف_ڪريو GetCurrentDirectory GetCurrentDirectoryW
#وصف_ڪريو سيٽ_Dll_Directory سيٽ_Dll_Directory_W
#وصف_ڪريو GetDllDirectory GetDllDirectoryW
#وصف_ڪريو GetDiskFreeSpace GetDiskFreeSpaceW
#وصف_ڪريو GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#وصف_ڪريو CreateDirectory CreateDirectoryW
#وصف_ڪريو CreateDirectoryEx CreateDirectoryExW
#وصف_ڪريو RemoveDirectory RemoveDirectoryW
#وصف_ڪريو Get_ڀريل_رستو_Name Get_ڀريل_رستو_Name_W
#وصف_ڪريو DefineDosDevice DefineDosDeviceW
#وصف_ڪريو QueryDosDevice QueryDosDeviceW
#وصف_ڪريو CreateFile CreateFileW
#وصف_ڪريو سيٽ_File_خاصيتون سيٽ_File_خاصيتون_W
#وصف_ڪريو Get_File_خاصيتون Get_File_خاصيتون_W
#وإلا
#وصف_ڪريو سيٽ_Current_Directory سيٽ_Current_Directory_A
#وصف_ڪريو GetCurrentDirectory GetCurrentDirectoryA
#وصف_ڪريو سيٽ_Dll_Directory سيٽ_Dll_Directory_A
#وصف_ڪريو GetDllDirectory GetDllDirectoryA
#وصف_ڪريو GetDiskFreeSpace GetDiskFreeSpaceA
#وصف_ڪريو GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#وصف_ڪريو CreateDirectory CreateDirectoryA
#وصف_ڪريو CreateDirectoryEx CreateDirectoryExA
#وصف_ڪريو RemoveDirectory RemoveDirectoryA
#وصف_ڪريو Get_ڀريل_رستو_Name Get_ڀريل_رستو_Name_A
#وصف_ڪريو DefineDosDevice DefineDosDeviceA
#وصف_ڪريو QueryDosDevice QueryDosDeviceA
#وصف_ڪريو CreateFile CreateFileA
#وصف_ڪريو سيٽ_File_خاصيتون سيٽ_File_خاصيتون_A
#وصف_ڪريو Get_File_خاصيتون Get_File_خاصيتون_A
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI سيٽ_Current_Directory_A(LPCSTR lp_رستو_Name);
  WINBASEAPI WINBOOL WINAPI سيٽ_Current_Directory_W(LPCWSTR lp_رستو_Name);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD n_بفر_ڊيگهائي,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD n_بفر_ڊيگهائي,LPWSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI سيٽ_Dll_Directory_A(LPCSTR lp_رستو_Name);
  WINBASEAPI WINBOOL WINAPI سيٽ_Dll_Directory_W(LPCWSTR lp_رستو_Name);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD n_بفر_ڊيگهائي,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD n_بفر_ڊيگهائي,LPWSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lp_پاڙ_رستو_Name,LPDWORD lp_Sectors_في_Cluster,LPDWORD lp_بائيٽون_في_Sector,LPDWORD lp_عدد_جو_Free_Clusters,LPDWORD lp_ڪل_عدد_جو_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lp_پاڙ_رستو_Name,LPDWORD lp_Sectors_في_Cluster,LPDWORD lp_بائيٽون_في_Sector,LPDWORD lp_عدد_جو_Free_Clusters,LPDWORD lp_ڪل_عدد_جو_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lp_Free_بائيٽون_موجود_منزل_Caller,PULARGE_INTEGER lp_ڪل_عدد_جو_بائيٽون,PULARGE_INTEGER lp_ڪل_عدد_جو_Free_بائيٽون);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lp_Free_بائيٽون_موجود_منزل_Caller,PULARGE_INTEGER lp_ڪل_عدد_جو_بائيٽون,PULARGE_INTEGER lp_ڪل_عدد_جو_Free_بائيٽون);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lp_رستو_Name,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lp_رستو_Name,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lp_رستو_Name);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lp_رستو_Name);
  WINBASEAPI DWORD WINAPI Get_ڀريل_رستو_Name_A(LPCSTR lpFileName,DWORD n_بفر_ڊيگهائي,LPSTR lp_بفر,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI Get_ڀريل_رستو_Name_W(LPCWSTR lpFileName,DWORD n_بفر_ڊيگهائي,LPWSTR lp_بفر,LPWSTR *lpFilePart);

#وصف_ڪريو DDD_RAW_هدف_رستو 0x1
#وصف_ڪريو DDD_REMOVE_DEFINITION 0x2
#وصف_ڪريو DDD_EXACT_ميلاپ_ON_REMOVE 0x4
#وصف_ڪريو DDD_NO_نشر_SYSTEM 0x8
#وصف_ڪريو DDD_LUID_نشر_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lp_هدف_رستو);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lp_هدف_رستو);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lp_هدف_رستو,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lp_هدف_رستو,DWORD ucchMax);

#وصف_ڪريو EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_گهڻائي,LPSECURITY_خاصيتون lp_Security_خاصيتون,DWORD dwCreationDisposition,DWORD dw_Flags_And_خاصيتون,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_گهڻائي,LPSECURITY_خاصيتون lp_Security_خاصيتون,DWORD dwCreationDisposition,DWORD dw_Flags_And_خاصيتون,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dw_Share_گهڻائي,DWORD dw_Flags_And_خاصيتون);
  WINBASEAPI WINBOOL WINAPI سيٽ_File_خاصيتون_A(LPCSTR lpFileName,DWORD dw_File_خاصيتون);
  WINBASEAPI WINBOOL WINAPI سيٽ_File_خاصيتون_W(LPCWSTR lpFileName,DWORD dw_File_خاصيتون);
  WINBASEAPI DWORD WINAPI Get_File_خاصيتون_A(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_File_خاصيتون_W(LPCWSTR lpFileName);

  تعريفنوع تعداد GET_FILEEX_INFO_سطحون {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_سطحون_2;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_File_خاصيتون_Ex Get_File_خاصيتون_Ex_W
#وصف_ڪريو Get_Compressed_File_سائيز Get_Compressed_File_سائيز_W
#وصف_ڪريو DeleteFile DeleteFileW
#وصف_ڪريو CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#وإلا
#وصف_ڪريو Get_File_خاصيتون_Ex Get_File_خاصيتون_Ex_A
#وصف_ڪريو Get_Compressed_File_سائيز Get_Compressed_File_سائيز_A
#وصف_ڪريو DeleteFile DeleteFileA
#وصف_ڪريو CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI Get_File_خاصيتون_Ex_A(LPCSTR lpFileName,GET_FILEEX_INFO_سطحون_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI Get_File_خاصيتون_Ex_W(LPCWSTR lpFileName,GET_FILEEX_INFO_سطحون_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_سائيز_A(LPCSTR lpFileName,LPDWORD lp_File_سائيز_مٿاهون);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_سائيز_W(LPCWSTR lpFileName,LPDWORD lp_File_سائيز_مٿاهون);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD Oem_Name_سائيز,PBOOL pb_Name_شامل_آهي_Spaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD Oem_Name_سائيز,PBOOL pb_Name_شامل_آهي_Spaces,PBOOL pbNameLegal);

  تعريفنوع تعداد FINDEX_INFO_سطحون {
    ڳوليو_Ex_Info_Standard,ڳوليو_Ex_Info_Max_Info_Level
  } FINDEX_INFO_سطحون_2;

  تعريفنوع تعداد FINDEX_ڳولا_OPS {
    ڳوليو_Ex_ڳولا_Name_ميلاپ,ڳوليو_Ex_ڳولا_حد_بندي_منزل_Directories,ڳوليو_Ex_ڳولا_حد_بندي_منزل_Devices,ڳوليو_Ex_ڳولا_Max_ڳولا_Op
  } FINDEX_ڳولا_OPS_2;

#وصف_ڪريو ڳوليو_پهريون_EX_CASE_SENSITIVE 0x1

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڳوليو_پهريون_File_Ex ڳوليو_پهريون_File_Ex_W
#وصف_ڪريو ڳوليو_پهريون_File ڳوليو_پهريون_File_W
#وصف_ڪريو ڳوليو_ايندڙ_File ڳوليو_ايندڙ_File_W
#وصف_ڪريو ڳولا_رستو ڳولا_رستو_W
#وصف_ڪريو CopyFile CopyFileW
#وصف_ڪريو CopyFileEx CopyFileExW
#وصف_ڪريو MoveFile MoveFileW
#وصف_ڪريو MoveFileEx MoveFileExW
#وصف_ڪريو Move_File_With_ترقي Move_File_With_ترقي_W
#وصف_ڪريو ReplaceFile ReplaceFileW
#وصف_ڪريو CreateHardLink CreateHardLinkW
#وصف_ڪريو CreateNamedPipe CreateNamedPipeW
#وصف_ڪريو GetNamedPipeHandleState GetNamedPipeHandleStateW
#وصف_ڪريو CallNamedPipe CallNamedPipeW
#وصف_ڪريو WaitNamedPipe WaitNamedPipeW
#وصف_ڪريو سيٽ_Volume_Label سيٽ_Volume_Label_W
#وصف_ڪريو GetVolumeInformation GetVolumeInformationW
#وصف_ڪريو ClearEventLog ClearEventLogW
#وصف_ڪريو BackupEventLog BackupEventLogW
#وصف_ڪريو OpenEventLog OpenEventLogW
#وصف_ڪريو رجسٽر_Event_ذريعو رجسٽر_Event_ذريعو_W
#وصف_ڪريو OpenBackupEventLog OpenBackupEventLogW
#وصف_ڪريو ReadEventLog ReadEventLogW
#وصف_ڪريو ReportEvent ReportEventW
#وصف_ڪريو AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#وصف_ڪريو AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#وصف_ڪريو Access_Check_By_Type_نتيجو_List_And_Audit_Alarm Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_W
#وصف_ڪريو Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_By_Handle_W
#وصف_ڪريو ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#وصف_ڪريو ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#وصف_ڪريو ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#وصف_ڪريو ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#وصف_ڪريو PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#وصف_ڪريو سيٽ_File_Security سيٽ_File_Security_W
#وصف_ڪريو GetFileSecurity GetFileSecurityW
#وصف_ڪريو ڳوليو_پهريون_Change_Notification ڳوليو_پهريون_Change_Notification_W
#وصف_ڪريو IsBadStringPtr IsBadStringPtrW
#وصف_ڪريو LookupAccountSid LookupAccountSidW
#وصف_ڪريو LookupAccountName LookupAccountNameW
#وصف_ڪريو Lookup_Privilege_قدر Lookup_Privilege_قدر_W
#وصف_ڪريو LookupPrivilegeName LookupPrivilegeNameW
#وصف_ڪريو LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#وصف_ڪريو BuildCommDCB BuildCommDCBW
#وصف_ڪريو BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#وصف_ڪريو CommConfigDialog CommConfigDialogW
#وصف_ڪريو GetDefaultCommConfig GetDefaultCommConfigW
#وصف_ڪريو سيٽ_Default_Comm_Config سيٽ_Default_Comm_Config_W
#وصف_ڪريو GetComputerName GetComputerNameW
#وصف_ڪريو سيٽ_Computer_Name سيٽ_Computer_Name_W
#وصف_ڪريو GetComputerNameEx GetComputerNameExW
#وصف_ڪريو سيٽ_Computer_Name_Ex سيٽ_Computer_Name_Ex_W
#وصف_ڪريو Dns_Hostname_منزل_Computer_Name Dns_Hostname_منزل_Computer_Name_W
#وصف_ڪريو GetUserName GetUserNameW
#وإلا
#وصف_ڪريو ڳوليو_پهريون_File_Ex ڳوليو_پهريون_File_Ex_A
#وصف_ڪريو ڳوليو_پهريون_File ڳوليو_پهريون_File_A
#وصف_ڪريو ڳوليو_ايندڙ_File ڳوليو_ايندڙ_File_A
#وصف_ڪريو ڳولا_رستو ڳولا_رستو_A
#وصف_ڪريو CopyFile CopyFileA
#وصف_ڪريو CopyFileEx CopyFileExA
#وصف_ڪريو MoveFile MoveFileA
#وصف_ڪريو MoveFileEx MoveFileExA
#وصف_ڪريو Move_File_With_ترقي Move_File_With_ترقي_A
#وصف_ڪريو ReplaceFile ReplaceFileA
#وصف_ڪريو CreateHardLink CreateHardLinkA
#وصف_ڪريو CreateNamedPipe CreateNamedPipeA
#وصف_ڪريو GetNamedPipeHandleState GetNamedPipeHandleStateA
#وصف_ڪريو CallNamedPipe CallNamedPipeA
#وصف_ڪريو WaitNamedPipe WaitNamedPipeA
#وصف_ڪريو سيٽ_Volume_Label سيٽ_Volume_Label_A
#وصف_ڪريو GetVolumeInformation GetVolumeInformationA
#وصف_ڪريو ClearEventLog ClearEventLogA
#وصف_ڪريو BackupEventLog BackupEventLogA
#وصف_ڪريو OpenEventLog OpenEventLogA
#وصف_ڪريو رجسٽر_Event_ذريعو رجسٽر_Event_ذريعو_A
#وصف_ڪريو OpenBackupEventLog OpenBackupEventLogA
#وصف_ڪريو ReadEventLog ReadEventLogA
#وصف_ڪريو ReportEvent ReportEventA
#وصف_ڪريو AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#وصف_ڪريو AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#وصف_ڪريو Access_Check_By_Type_نتيجو_List_And_Audit_Alarm Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_A
#وصف_ڪريو Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_By_Handle_A
#وصف_ڪريو ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#وصف_ڪريو ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#وصف_ڪريو ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#وصف_ڪريو ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#وصف_ڪريو PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#وصف_ڪريو سيٽ_File_Security سيٽ_File_Security_A
#وصف_ڪريو GetFileSecurity GetFileSecurityA
#وصف_ڪريو ڳوليو_پهريون_Change_Notification ڳوليو_پهريون_Change_Notification_A
#وصف_ڪريو IsBadStringPtr IsBadStringPtrA
#وصف_ڪريو LookupAccountSid LookupAccountSidA
#وصف_ڪريو LookupAccountName LookupAccountNameA
#وصف_ڪريو Lookup_Privilege_قدر Lookup_Privilege_قدر_A
#وصف_ڪريو LookupPrivilegeName LookupPrivilegeNameA
#وصف_ڪريو LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#وصف_ڪريو BuildCommDCB BuildCommDCBA
#وصف_ڪريو BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#وصف_ڪريو CommConfigDialog CommConfigDialogA
#وصف_ڪريو GetDefaultCommConfig GetDefaultCommConfigA
#وصف_ڪريو سيٽ_Default_Comm_Config سيٽ_Default_Comm_Config_A
#وصف_ڪريو GetComputerName GetComputerNameA
#وصف_ڪريو سيٽ_Computer_Name سيٽ_Computer_Name_A
#وصف_ڪريو GetComputerNameEx GetComputerNameExA
#وصف_ڪريو سيٽ_Computer_Name_Ex سيٽ_Computer_Name_Ex_A
#وصف_ڪريو Dns_Hostname_منزل_Computer_Name Dns_Hostname_منزل_Computer_Name_A
#وصف_ڪريو GetUserName GetUserNameA
#جيڪڏهن_پورو

  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_File_Ex_A(LPCSTR lpFileName,FINDEX_INFO_سطحون_2 fInfoLevelId,LPVOID lp_ڳوليو_File_معلومات,FINDEX_ڳولا_OPS_2 f_ڳولا_Op,LPVOID lp_ڳولا_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_File_Ex_W(LPCWSTR lpFileName,FINDEX_INFO_سطحون_2 fInfoLevelId,LPVOID lp_ڳوليو_File_معلومات,FINDEX_ڳولا_OPS_2 f_ڳولا_Op,LPVOID lp_ڳولا_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_File_A(LPCSTR lpFileName,LPWIN32_ڳوليو_DATAA lp_ڳوليو_File_معلومات);
  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_File_W(LPCWSTR lpFileName,LPWIN32_ڳوليو_DATAW lp_ڳوليو_File_معلومات);
  WINBASEAPI WINBOOL WINAPI ڳوليو_ايندڙ_File_A(HANDLE h_ڳوليو_File,LPWIN32_ڳوليو_DATAA lp_ڳوليو_File_معلومات);
  WINBASEAPI WINBOOL WINAPI ڳوليو_ايندڙ_File_W(HANDLE h_ڳوليو_File,LPWIN32_ڳوليو_DATAW lp_ڳوليو_File_معلومات);
  WINBASEAPI DWORD WINAPI ڳولا_رستو_A(LPCSTR lp_رستو,LPCSTR lpFileName,LPCSTR lpExtension,DWORD n_بفر_ڊيگهائي,LPSTR lp_بفر,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI ڳولا_رستو_W(LPCWSTR lp_رستو,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD n_بفر_ڊيگهائي,LPWSTR lp_بفر,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  تعريفنوع DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER ڪل_File_سائيز,LARGE_INTEGER ڪل_بائيٽون_Transferred,LARGE_INTEGER وهڪرو_سائيز,LARGE_INTEGER وهڪرو_بائيٽون_Transferred,DWORD dw_وهڪرو_عدد,DWORD dwCallbackReason,HANDLE h_ذريعو_File,HANDLE hDestinationFile,LPVOID lp_معلومات);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ترقي_Routine,LPVOID lp_معلومات,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ترقي_Routine,LPVOID lp_معلومات,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_ترقي_A(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ترقي_Routine,LPVOID lp_معلومات,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_ترقي_W(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_ترقي_Routine,LPVOID lp_معلومات,DWORD dwFlags);

#وصف_ڪريو MOVEFILE_REPLACE_EXISTING 0x1
#وصف_ڪريو MOVEFILE_COPY_ALLOWED 0x2
#وصف_ڪريو MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#وصف_ڪريو MOVEFILE_WRITE_THROUGH 0x8
#وصف_ڪريو MOVEFILE_CREATE_HARDLINK 0x10
#وصف_ڪريو MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_خاصيتون lp_Security_خاصيتون);

  تعريفنوع تعداد وهڪرو_INFO_سطحون {
    ڳوليو_وهڪرو_Info_Standard,ڳوليو_وهڪرو_Info_Max_Info_Level
  } وهڪرو_INFO_سطحون_2;

  تعريفنوع بنية WIN32_ڳوليو_وهڪرو_معلومات {
    LARGE_INTEGER وهڪرو_سائيز;
    WCHAR c_وهڪرو_Name[MAX_رستو + 36];
  } WIN32_ڳوليو_وهڪرو_معلومات_2,*PWIN32_ڳوليو_وهڪرو_معلومات;

  HANDLE WINAPI ڳوليو_پهريون_وهڪرو_W(LPCWSTR lpFileName,وهڪرو_INFO_سطحون_2 InfoLevel,LPVOID lp_ڳوليو_وهڪرو_معلومات,DWORD dwFlags);
  WINBOOL WINAPI ڳوليو_ايندڙ_وهڪرو_W(HANDLE h_ڳوليو_وهڪرو,LPVOID lp_ڳوليو_وهڪرو_معلومات);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dw_Open_گهڻائي,DWORD dw_Pipe_گهڻائي,DWORD nMaxInstances,DWORD n_ٻاهريون_بفر_سائيز,DWORD n_اندريون_بفر_سائيز,DWORD n_Default_وقت_ٻاهريون,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dw_Open_گهڻائي,DWORD dw_Pipe_گهڻائي,DWORD nMaxInstances,DWORD n_ٻاهريون_بفر_سائيز,DWORD n_اندريون_بفر_سائيز,DWORD n_Default_وقت_ٻاهريون,LPSECURITY_خاصيتون lp_Security_خاصيتون);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_ڳڻپ,LPDWORD lp_Collect_معلومات_Timeout,LPSTR lpUserName,DWORD n_Max_User_Name_سائيز);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_ڳڻپ,LPDWORD lp_Collect_معلومات_Timeout,LPWSTR lpUserName,DWORD n_Max_User_Name_سائيز);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lp_اندريون_بفر,DWORD n_اندريون_بفر_سائيز,LPVOID lp_ٻاهريون_بفر,DWORD n_ٻاهريون_بفر_سائيز,LPDWORD lp_بائيٽون_Read,DWORD n_وقت_ٻاهريون);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lp_اندريون_بفر,DWORD n_اندريون_بفر_سائيز,LPVOID lp_ٻاهريون_بفر,DWORD n_ٻاهريون_بفر_سائيز,LPDWORD lp_بائيٽون_Read,DWORD n_وقت_ٻاهريون);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD n_وقت_ٻاهريون);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD n_وقت_ٻاهريون);
  WINBASEAPI WINBOOL WINAPI سيٽ_Volume_Label_A(LPCSTR lp_پاڙ_رستو_Name,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI سيٽ_Volume_Label_W(LPCWSTR lp_پاڙ_رستو_Name,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI سيٽ_File_Apis_منزل_OEM(VOID);
  WINBASEAPI VOID WINAPI سيٽ_File_Apis_منزل_ANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lp_پاڙ_رستو_Name,LPSTR lp_Volume_Name_بفر,DWORD n_Volume_Name_سائيز,LPDWORD lp_Volume_Serial_عدد,LPDWORD lp_وڌ_کان_وڌ_Component_ڊيگهائي,LPDWORD lpFileSystemFlags,LPSTR lp_File_System_Name_بفر,DWORD n_File_System_Name_سائيز);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lp_پاڙ_رستو_Name,LPWSTR lp_Volume_Name_بفر,DWORD n_Volume_Name_سائيز,LPDWORD lp_Volume_Serial_عدد,LPDWORD lp_وڌ_کان_وڌ_Component_ڊيگهائي,LPDWORD lpFileSystemFlags,LPWSTR lp_File_System_Name_بفر,DWORD n_File_System_Name_سائيز);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI Deregister_Event_ذريعو(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI Get_عدد_جو_Event_Log_رڪارڊون(HANDLE hEventLog,PDWORD عدد_جو_رڪارڊون);
  WINADVAPI WINBOOL WINAPI Get_Oldest_Event_Log_رڪارڊ(HANDLE hEventLog,PDWORD Oldest_رڪارڊ);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lp_ذريعو_Name);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lp_ذريعو_Name);
  WINADVAPI HANDLE WINAPI رجسٽر_Event_ذريعو_A(LPCSTR lpUNCServerName,LPCSTR lp_ذريعو_Name);
  WINADVAPI HANDLE WINAPI رجسٽر_Event_ذريعو_W(LPCWSTR lpUNCServerName,LPCWSTR lp_ذريعو_Name);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_رڪارڊ_وٿي,LPVOID lp_بفر,DWORD n_عدد_جو_بائيٽون_منزل_Read,DWORD *pn_بائيٽون_Read,DWORD *pn_Min_عدد_جو_بائيٽون_Needed);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_رڪارڊ_وٿي,LPVOID lp_بفر,DWORD n_عدد_جو_بائيٽون_منزل_Read,DWORD *pn_بائيٽون_Read,DWORD *pn_Min_عدد_جو_بائيٽون_Needed);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,لفظ_3 wType,لفظ_3 wCategory,DWORD dwEventID,PSID lpUserSid,لفظ_3 w_انگ_لڙيون,DWORD dw_معلومات_سائيز,LPCSTR *lp_لڙيون,LPVOID lp_Raw_معلومات);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,لفظ_3 wType,لفظ_3 wCategory,DWORD dwEventID,PSID lpUserSid,لفظ_3 w_انگ_لڙيون,DWORD dw_معلومات_سائيز,LPCWSTR *lp_لڙيون,LPVOID lp_Raw_معلومات);

#وصف_ڪريو EVENTLOG_ڀريل_INFO 0

  تعريفنوع بنية EVENTLOG_ڀريل_INFORMATION {
    DWORD dw_ڀريل;
  } EVENTLOG_ڀريل_INFORMATION_2,*LPEVENTLOG_ڀريل_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lp_بفر,DWORD cb_Buf_سائيز,LPDWORD pcb_بائيٽون_Needed);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_ڊيگهائي,LPDWORD lpn_ڊيگهائي_Needed);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI Revert_منزل_Self(VOID);
  WINADVAPI WINBOOL WINAPI سيٽ_Thread_Token (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_سيٽ Privilege_سيٽ,LPDWORD Privilege_سيٽ_ڊيگهائي,LPDWORD GrantedAccess,LPBOOL Access_حالت);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ڊيگهائي,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_سيٽ Privilege_سيٽ,LPDWORD Privilege_سيٽ_ڊيگهائي,LPDWORD GrantedAccess,LPBOOL Access_حالت);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتيجو_List(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ڊيگهائي,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_سيٽ Privilege_سيٽ,LPDWORD Privilege_سيٽ_ڊيگهائي,LPDWORD GrantedAccessList,LPDWORD Access_حالت_List);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_ڊيگهائي,PDWORD Return_ڊيگهائي);
  WINADVAPI WINBOOL WINAPI سيٽ_Token_Information(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_ڊيگهائي);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD بفر_ڊيگهائي,PTOKEN_PRIVILEGES اڳيون_State,PDWORD Return_ڊيگهائي);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL Reset_منزل_Default,PTOKEN_GROUPS NewState,DWORD بفر_ڊيگهائي,PTOKEN_GROUPS اڳيون_State,PDWORD Return_ڊيگهائي);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_سيٽ RequiredPrivileges,LPBOOL pf_نتيجو);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ڊيگهائي,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ڊيگهائي,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_A(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ڊيگهائي,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_W(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ڊيگهائي,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_By_Handle_A(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ڊيگهائي,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتيجو_List_And_Audit_Alarm_By_Handle_W(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_ڊيگهائي,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_سيٽ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_سيٽ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_سيٽ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_سيٽ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_سيٽ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_سيٽ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI Is_Well_معلوم_Sid(PSID pSid,WELL_معلوم_SID_TYPE Well_معلوم_Sid_Type);
  WINADVAPI WINBOOL WINAPI Create_Well_معلوم_Sid(WELL_معلوم_SID_TYPE Well_معلوم_Sid_Type,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI Equal_اڳياڙي_Sid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI Get_Sid_ڊيگهائي_Required (UCHAR n_Sub_Authority_ڳڻپ);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_ڳڻپ,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_ڳڻپ);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI Get_Sid_Sub_Authority_ڳڻپ(PSID pSid);
  WINADVAPI DWORD WINAPI Get_ڊيگهائي_Sid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD n_Destination_Sid_ڊيگهائي,PSID pDestinationSid,PSID p_ذريعو_Sid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI Map_Generic_نقاب(PDWORD Access_نقاب,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD n_Acl_ڊيگهائي,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_ڊيگهائي,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI سيٽ_Acl_Information(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_ڊيگهائي,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI جوڙيو_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Starting_Ace_اشاريو,LPVOID pAceList,DWORD n_Ace_List_ڊيگهائي);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dw_Ace_اشاريو);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dw_Ace_اشاريو,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI جوڙيو_Access_Allowed_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_نقاب,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڙيو_Access_Allowed_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڙيو_Access_Denied_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_نقاب,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڙيو_Access_Denied_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڙيو_Audit_Access_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Access_نقاب,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI جوڙيو_Audit_Access_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dw_Access_نقاب,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI جوڙيو_Access_Allowed_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڙيو_Access_Denied_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڙيو_Audit_Access_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI ڳوليو_پهريون_Free_Ace(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI Get_Security_Descriptor_ڊيگهائي(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI سيٽ_Security_Descriptor_Control(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL Control_بٽ_جو_Interest,SECURITY_DESCRIPTOR_CONTROL Control_بٽ_منزل_سيٽ);
  WINADVAPI WINBOOL WINAPI سيٽ_Security_Descriptor_Dacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI سيٽ_Security_Descriptor_Sacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI سيٽ_Security_Descriptor_Owner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI سيٽ_Security_Descriptor_گروهه(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID p_گروهه,WINBOOL b_گروهه_Defaulted);
  WINADVAPI WINBOOL WINAPI Get_Security_Descriptor_گروهه(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *p_گروهه,LPBOOL lpb_گروهه_Defaulted);
  WINADVAPI DWORD WINAPI سيٽ_Security_Descriptor_RMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI Create_ذاتي_Object_Security(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Convert_منزل_Auto_Inherit_ذاتي_Object_Security(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_ذاتي_Object_Security_Ex(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_ذاتي_Object_Security_With_گڻو_Inheritance(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG Guid_ڳڻپ,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI سيٽ_ذاتي_Object_Security (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI سيٽ_ذاتي_Object_Security_Ex (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI Get_ذاتي_Object_Security(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD Descriptor_ڊيگهائي,PDWORD Return_ڊيگهائي);
  WINADVAPI WINBOOL WINAPI Destroy_ذاتي_Object_Security(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_بفر_ڊيگهائي);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdw_Absolute_Security_Descriptor_سائيز,PACL pDacl,LPDWORD lpdw_Dacl_سائيز,PACL pSacl,LPDWORD lpdw_Sacl_سائيز,PSID pOwner,LPDWORD lpdw_Owner_سائيز,PSID p_Primary_گروهه,LPDWORD lpdw_Primary_گروهه_سائيز);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_بفر_سائيز);
  WINADVAPI WINBOOL WINAPI سيٽ_File_Security_A(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI سيٽ_File_Security_W(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_ڊيگهائي,LPDWORD lpn_ڊيگهائي_Needed);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_ڊيگهائي,LPDWORD lpn_ڊيگهائي_Needed);
  WINADVAPI WINBOOL WINAPI سيٽ_Kernel_Object_Security(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_Change_Notification_A(LPCSTR lp_رستو_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_Change_Notification_W(LPCWSTR lp_رستو_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI ڳوليو_ايندڙ_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ڳوليو_Close_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lp_بفر,DWORD n_بفر_ڊيگهائي,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lp_بائيٽون_Returned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI Virtual_تالو(LPVOID lp_پتو,سائيز_T dw_سائيز);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lp_پتو,سائيز_T dw_سائيز);
  WINBASEAPI LPVOID WINAPI Map_View_جو_File_Ex(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_وٿي_مٿاهون,DWORD dw_File_وٿي_هيٺيون,سائيز_T dw_عدد_جو_بائيٽون_منزل_Map,LPVOID lp_بنياد_پتو);
  WINBASEAPI WINBOOL WINAPI سيٽ_ترجيح_Class(HANDLE hProcess,DWORD dw_ترجيح_Class);
  WINBASEAPI DWORD WINAPI Get_ترجيح_Class(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI Is_Bad_ڪوڊ_Ptr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_قدر_A(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_قدر_W(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
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
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_سائيز);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Default_Comm_Config_A(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Default_Comm_Config_W(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_سائيز);

#وصف_ڪريو MAX_COMPUTERNAME_ڊيگهائي 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lp_بفر,LPDWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lp_بفر,LPDWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Computer_Name_A(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI سيٽ_Computer_Name_W(LPCWSTR lpComputerName);

  تعريفنوع تعداد _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lp_بفر,LPDWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lp_بفر,LPDWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Computer_Name_Ex_A(COMPUTER_NAME_FORMAT NameType,LPCSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI سيٽ_Computer_Name_Ex_W(COMPUTER_NAME_FORMAT NameType,LPCWSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_منزل_Computer_Name_A(LPCSTR Hostname,LPSTR ComputerName,LPDWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_منزل_Computer_Name_W(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD n_سائيز);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lp_بفر,LPDWORD pcb_بفر);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lp_بفر,LPDWORD pcb_بفر);

#وصف_ڪريو LOGON32_LOGON_INTERACTIVE 2
#وصف_ڪريو LOGON32_LOGON_ڄار 3
#وصف_ڪريو LOGON32_LOGON_BATCH 4
#وصف_ڪريو LOGON32_LOGON_SERVICE 5
#وصف_ڪريو LOGON32_LOGON_UNLOCK 7
#وصف_ڪريو LOGON32_LOGON_ڄار_CLEARTEXT 8
#وصف_ڪريو LOGON32_LOGON_NEW_CREDENTIALS 9

#وصف_ڪريو LOGON32_PROVIDER_DEFAULT 0
#وصف_ڪريو LOGON32_PROVIDER_WINNT35 1
#وصف_ڪريو LOGON32_PROVIDER_WINNT40 2
#وصف_ڪريو LOGON32_PROVIDER_WINNT50 3

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو LogonUser LogonUserW
#وصف_ڪريو LogonUserEx LogonUserExW
#وصف_ڪريو CreateProcessAsUser CreateProcessAsUserW
#وإلا
#وصف_ڪريو LogonUser LogonUserA
#وصف_ڪريو LogonUserEx LogonUserExA
#وصف_ڪريو CreateProcessAsUser CreateProcessAsUserA
#جيڪڏهن_پورو

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_بفر,LPDWORD pdw_Profile_ڊيگهائي,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_بفر,LPDWORD pdw_Profile_ڊيگهائي,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lp_Command_سٽ,LPSECURITY_خاصيتون lp_Process_خاصيتون,LPSECURITY_خاصيتون lp_Thread_خاصيتون,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lp_Command_سٽ,LPSECURITY_خاصيتون lp_Process_خاصيتون,LPSECURITY_خاصيتون lp_Thread_خاصيتون,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#وصف_ڪريو LOGON_WITH_PROFILE 0x1
#وصف_ڪريو LOGON_NETCREDENTIALS_ONLY 0x2
#وصف_ڪريو LOGON_ZERO_PASSWORD_بفر 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_سٽ,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_سٽ,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_خاصيتون lp_Token_خاصيتون,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD Disable_Sid_ڳڻپ,PSID_AND_خاصيتون Sids_منزل_Disable,DWORD Delete_Privilege_ڳڻپ,PLUID_AND_خاصيتون Privileges_منزل_Delete,DWORD Restricted_Sid_ڳڻپ,PSID_AND_خاصيتون Sids_منزل_Restrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID Sid_منزل_Check,PBOOL IsMember);

  تعريفنوع WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI رجسٽر_Wait_For_Single_Object(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI رجسٽر_Wait_For_Single_Object_Ex(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI قطار_User_Work_شي(LPTHREAD_شروعات_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI Create_Timer_قطار(VOID);
  WINBASEAPI WINBOOL WINAPI Create_Timer_قطار_Timer(PHANDLE phNewTimer,HANDLE Timer_قطار,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_وقت,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI Change_Timer_قطار_Timer(HANDLE Timer_قطار,HANDLE Timer,ULONG Due_وقت,ULONG Period);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_قطار_Timer(HANDLE Timer_قطار,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_قطار_Ex(HANDLE Timer_قطار,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI سيٽ_Timer_قطار_Timer(HANDLE Timer_قطار,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_وقت,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI Cancel_Timer_قطار_Timer(HANDLE Timer_قطار,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_قطار(HANDLE Timer_قطار);

#وصف_ڪريو HW_PROFILE_GUIDLEN 39
#وصف_ڪريو MAX_PROFILE_LEN 80

#وصف_ڪريو DOCKINFO_UNDOCKED (0x1)
#وصف_ڪريو DOCKINFO_DOCKED (0x2)
#وصف_ڪريو DOCKINFO_USER_SUPPLIED (0x4)
#وصف_ڪريو DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#وصف_ڪريو DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  تعريفنوع بنية ٽيگ_HW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  تعريفنوع بنية ٽيگ_HW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع HW_PROFILE_INFOW HW_PROFILE_INFO;
  تعريفنوع LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#وإلا
  تعريفنوع HW_PROFILE_INFOA HW_PROFILE_INFO;
  تعريفنوع LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetCurrentHwProfile GetCurrentHwProfileW
#وصف_ڪريو Get_نسخو_Ex Get_نسخو_Ex_W
#وصف_ڪريو Verify_نسخو_Info Verify_نسخو_Info_W
#وإلا
#وصف_ڪريو GetCurrentHwProfile GetCurrentHwProfileA
#وصف_ڪريو Get_نسخو_Ex Get_نسخو_Ex_A
#وصف_ڪريو Verify_نسخو_Info Verify_نسخو_Info_A
#جيڪڏهن_پورو

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lp_Performance_ڳڻپ);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI Get_نسخو_Ex_A(LPOSVERSIONINFOA lp_نسخو_Information);
  WINBASEAPI WINBOOL WINAPI Get_نسخو_Ex_W(LPOSVERSIONINFOW lp_نسخو_Information);
  WINBASEAPI WINBOOL WINAPI Verify_نسخو_Info_A(LPOSVERSIONINFOEXA lp_نسخو_Information,DWORD dw_Type_نقاب,DWORDLONG dwl_Condition_نقاب);
  WINBASEAPI WINBOOL WINAPI Verify_نسخو_Info_W(LPOSVERSIONINFOEXW lp_نسخو_Information,DWORD dw_Type_نقاب,DWORDLONG dwl_Condition_نقاب);

#ضمن <winerror.h>

#وصف_ڪريو TC_عام 0
#وصف_ڪريو TC_HARDERR 1
#وصف_ڪريو TC_GP_TRAP 2
#وصف_ڪريو TC_SIGNAL 3

#وصف_ڪريو AC_سٽ_OFFLINE 0x0
#وصف_ڪريو AC_سٽ_ONLINE 0x1
#وصف_ڪريو AC_سٽ_BACKUP_POWER 0x2
#وصف_ڪريو AC_سٽ_UNKNOWN 0xff

#وصف_ڪريو BATTERY_FLAG_مٿاهون 0x1
#وصف_ڪريو BATTERY_FLAG_هيٺيون 0x2
#وصف_ڪريو BATTERY_FLAG_CRITICAL 0x4
#وصف_ڪريو BATTERY_FLAG_CHARGING 0x8
#وصف_ڪريو BATTERY_FLAG_NO_BATTERY 0x80
#وصف_ڪريو BATTERY_FLAG_UNKNOWN 0xff

#وصف_ڪريو BATTERY_PERCENTAGE_UNKNOWN 0xff

#وصف_ڪريو BATTERY_LIFE_UNKNOWN 0xffffffff

  تعريفنوع بنية SYSTEM_POWER_حالت {
    BYTE ACLine_حالت;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD Battery_Life_وقت;
    DWORD Battery_ڀريل_Life_وقت;
  } SYSTEM_POWER_حالت_2,*LPSYSTEM_POWER_حالت;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Create_ڪم_Object Create_ڪم_Object_W
#وصف_ڪريو Open_ڪم_Object Open_ڪم_Object_W
#وصف_ڪريو ڳوليو_پهريون_Volume ڳوليو_پهريون_Volume_W
#وصف_ڪريو ڳوليو_ايندڙ_Volume ڳوليو_ايندڙ_Volume_W
#وصف_ڪريو ڳوليو_پهريون_Volume_Mount_نقطو ڳوليو_پهريون_Volume_Mount_نقطو_W
#وصف_ڪريو ڳوليو_ايندڙ_Volume_Mount_نقطو ڳوليو_ايندڙ_Volume_Mount_نقطو_W
#وصف_ڪريو سيٽ_Volume_Mount_نقطو سيٽ_Volume_Mount_نقطو_W
#وصف_ڪريو Delete_Volume_Mount_نقطو Delete_Volume_Mount_نقطو_W
#وصف_ڪريو Get_Volume_Name_For_Volume_Mount_نقطو Get_Volume_Name_For_Volume_Mount_نقطو_W
#وصف_ڪريو Get_Volume_رستو_Name Get_Volume_رستو_Name_W
#وصف_ڪريو Get_Volume_رستو_نالا_For_Volume_Name Get_Volume_رستو_نالا_For_Volume_Name_W
#وإلا
#وصف_ڪريو Create_ڪم_Object Create_ڪم_Object_A
#وصف_ڪريو Open_ڪم_Object Open_ڪم_Object_A
#وصف_ڪريو ڳوليو_پهريون_Volume ڳوليو_پهريون_Volume_A
#وصف_ڪريو ڳوليو_ايندڙ_Volume ڳوليو_ايندڙ_Volume_A
#وصف_ڪريو ڳوليو_پهريون_Volume_Mount_نقطو ڳوليو_پهريون_Volume_Mount_نقطو_A
#وصف_ڪريو ڳوليو_ايندڙ_Volume_Mount_نقطو ڳوليو_ايندڙ_Volume_Mount_نقطو_A
#وصف_ڪريو سيٽ_Volume_Mount_نقطو سيٽ_Volume_Mount_نقطو_A
#وصف_ڪريو Delete_Volume_Mount_نقطو Delete_Volume_Mount_نقطو_A
#وصف_ڪريو Get_Volume_Name_For_Volume_Mount_نقطو Get_Volume_Name_For_Volume_Mount_نقطو_A
#وصف_ڪريو Get_Volume_رستو_Name Get_Volume_رستو_Name_A
#وصف_ڪريو Get_Volume_رستو_نالا_For_Volume_Name Get_Volume_رستو_نالا_For_Volume_Name_A
#جيڪڏهن_پورو

  WINBOOL WINAPI Get_System_Power_حالت(LPSYSTEM_POWER_حالت lp_System_Power_حالت);
  WINBOOL WINAPI سيٽ_System_Power_State(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI Allocate_User_Physical_صفحا(HANDLE hProcess,PULONG_PTR عدد_جو_صفحا,PULONG_PTR صفحو_Array);
  WINBASEAPI WINBOOL WINAPI Free_User_Physical_صفحا(HANDLE hProcess,PULONG_PTR عدد_جو_صفحا,PULONG_PTR صفحو_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_صفحا(PVOID Virtual_پتو,ULONG_PTR عدد_جو_صفحا,PULONG_PTR صفحو_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_صفحا_Scatter(PVOID *Virtual_پتا,ULONG_PTR عدد_جو_صفحا,PULONG_PTR صفحو_Array);
  WINBASEAPI HANDLE WINAPI Create_ڪم_Object_A(LPSECURITY_خاصيتون lp_ڪم_خاصيتون,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Create_ڪم_Object_W(LPSECURITY_خاصيتون lp_ڪم_خاصيتون,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_ڪم_Object_A(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_ڪم_Object_W(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI سونپيو_Process_منزل_ڪم_Object(HANDLE h_ڪم,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI Terminate_ڪم_Object(HANDLE h_ڪم,UINT u_Exit_ڪوڊ);
  WINBASEAPI WINBOOL WINAPI Query_Information_ڪم_Object(HANDLE h_ڪم,JOBOBJECTINFOCLASS ڪم_Object_Information_Class,LPVOID lp_ڪم_Object_Information,DWORD cb_ڪم_Object_Information_ڊيگهائي,LPDWORD lp_Return_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI سيٽ_Information_ڪم_Object(HANDLE h_ڪم,JOBOBJECTINFOCLASS ڪم_Object_Information_Class,LPVOID lp_ڪم_Object_Information,DWORD cb_ڪم_Object_Information_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI Is_Process_اندريون_ڪم(HANDLE ProcessHandle,HANDLE ڪم_Handle,PBOOL نتيجو_3);
  WINBASEAPI WINBOOL WINAPI Create_ڪم_سيٽ(ULONG انگ_ڪم,PJOB_سيٽ_ARRAY User_ڪم_سيٽ,ULONG Flags);
  WINBASEAPI PVOID WINAPI جوڙيو_Vectored_Exception_Handler (ULONG پهريون_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI جوڙيو_Vectored_Continue_Handler (ULONG پهريون_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_Volume_A(LPSTR lpszVolumeName,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_Volume_W(LPWSTR lpszVolumeName,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI ڳوليو_ايندڙ_Volume_A(HANDLE h_ڳوليو_Volume,LPSTR lpszVolumeName,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI ڳوليو_ايندڙ_Volume_W(HANDLE h_ڳوليو_Volume,LPWSTR lpszVolumeName,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI ڳوليو_Volume_Close(HANDLE h_ڳوليو_Volume);
  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_Volume_Mount_نقطو_A(LPCSTR lpsz_پاڙ_رستو_Name,LPSTR lpsz_Volume_Mount_نقطو,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI HANDLE WINAPI ڳوليو_پهريون_Volume_Mount_نقطو_W(LPCWSTR lpsz_پاڙ_رستو_Name,LPWSTR lpsz_Volume_Mount_نقطو,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI ڳوليو_ايندڙ_Volume_Mount_نقطو_A(HANDLE h_ڳوليو_Volume_Mount_نقطو,LPSTR lpsz_Volume_Mount_نقطو,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI ڳوليو_ايندڙ_Volume_Mount_نقطو_W(HANDLE h_ڳوليو_Volume_Mount_نقطو,LPWSTR lpsz_Volume_Mount_نقطو,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI ڳوليو_Volume_Mount_نقطو_Close(HANDLE h_ڳوليو_Volume_Mount_نقطو);
  WINBASEAPI WINBOOL WINAPI سيٽ_Volume_Mount_نقطو_A(LPCSTR lpsz_Volume_Mount_نقطو,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI سيٽ_Volume_Mount_نقطو_W(LPCWSTR lpsz_Volume_Mount_نقطو,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_نقطو_A(LPCSTR lpsz_Volume_Mount_نقطو);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_نقطو_W(LPCWSTR lpsz_Volume_Mount_نقطو);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_نقطو_A(LPCSTR lpsz_Volume_Mount_نقطو,LPSTR lpszVolumeName,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_نقطو_W(LPCWSTR lpsz_Volume_Mount_نقطو,LPWSTR lpszVolumeName,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI Get_Volume_رستو_Name_A(LPCSTR lpszFileName,LPSTR lpsz_Volume_رستو_Name,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI Get_Volume_رستو_Name_W(LPCWSTR lpszFileName,LPWSTR lpsz_Volume_رستو_Name,DWORD cch_بفر_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI Get_Volume_رستو_نالا_For_Volume_Name_A(LPCSTR lpszVolumeName,LPCH lpsz_Volume_رستو_نالا,DWORD cch_بفر_ڊيگهائي,PDWORD lpcch_Return_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI Get_Volume_رستو_نالا_For_Volume_Name_W(LPCWSTR lpszVolumeName,LPWCH lpsz_Volume_رستو_نالا,DWORD cch_بفر_ڊيگهائي,PDWORD lpcch_Return_ڊيگهائي);

#وصف_ڪريو ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#وصف_ڪريو ACTCTX_FLAG_LANGID_VALID 0x2
#وصف_ڪريو ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#وصف_ڪريو ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#وصف_ڪريو ACTCTX_FLAG_سيٽ_PROCESS_DEFAULT 0x10
#وصف_ڪريو ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#وصف_ڪريو ACTCTX_FLAG_ذريعو_IS_ASSEMBLYREF 0x40
#وصف_ڪريو ACTCTX_FLAG_HMODULE_VALID 0x80

  تعريفنوع بنية ٽيگ_ACTCTXA {
    ULONG cb_سائيز;
    DWORD dwFlags;
    LPCSTR lp_ذريعو;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  تعريفنوع بنية ٽيگ_ACTCTXW {
    ULONG cb_سائيز;
    DWORD dwFlags;
    LPCWSTR lp_ذريعو;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  تعريفنوع ثابت ACTCTXA *PCACTCTXA;
  تعريفنوع ثابت ACTCTXW *PCACTCTXW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع ACTCTXW ACTCTX;
  تعريفنوع PACTCTXW PACTCTX;
  تعريفنوع PCACTCTXW PCACTCTX;
#وإلا
  تعريفنوع ACTCTXA ACTCTX;
  تعريفنوع PACTCTXA PACTCTX;
  تعريفنوع PCACTCTXA PCACTCTX;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو CreateActCtx CreateActCtxW
#وإلا
#وصف_ڪريو CreateActCtx CreateActCtxA
#جيڪڏهن_پورو

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI جوڙيو_Ref_Act_Ctx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#وصف_ڪريو DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  تعريفنوع بنية ٽيگ_ACTCTX_SECTION_KEYED_معلومات_2600 {
    ULONG cb_سائيز;
    ULONG ul_معلومات_Format_نسخو;
    PVOID lp_معلومات;
    ULONG ul_ڊيگهائي;
    PVOID lp_Section_Global_معلومات;
    ULONG ul_Section_Global_معلومات_ڊيگهائي;
    PVOID lp_Section_بنياد;
    ULONG ul_Section_ڪل_ڊيگهائي;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_اشاريو;
  } ACTCTX_SECTION_KEYED_معلومات_2600,*PACTCTX_SECTION_KEYED_معلومات_2600;

  تعريفنوع ثابت ACTCTX_SECTION_KEYED_معلومات_2600 *PCACTCTX_SECTION_KEYED_معلومات_2600;

  تعريفنوع بنية ٽيگ_ACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lp_Section_بنياد;
    ULONG ul_Section_ڊيگهائي;
    PVOID lp_Section_Global_معلومات_بنياد;
    ULONG ul_Section_Global_معلومات_ڊيگهائي;
  } ACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA;

  تعريفنوع ثابت ACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA;

  تعريفنوع بنية ٽيگ_ACTCTX_SECTION_KEYED_معلومات {
    ULONG cb_سائيز;
    ULONG ul_معلومات_Format_نسخو;
    PVOID lp_معلومات;
    ULONG ul_ڊيگهائي;
    PVOID lp_Section_Global_معلومات;
    ULONG ul_Section_Global_معلومات_ڊيگهائي;
    PVOID lp_Section_بنياد;
    ULONG ul_Section_ڪل_ڊيگهائي;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_اشاريو;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_معلومات_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_معلومات,*PACTCTX_SECTION_KEYED_معلومات;

  تعريفنوع ثابت ACTCTX_SECTION_KEYED_معلومات *PCACTCTX_SECTION_KEYED_معلومات;

#وصف_ڪريو ڳوليو_ACTCTX_SECTION_ڪنجي_RETURN_HACTCTX 0x1
#وصف_ڪريو ڳوليو_ACTCTX_SECTION_ڪنجي_RETURN_FLAGS 0x2
#وصف_ڪريو ڳوليو_ACTCTX_SECTION_ڪنجي_RETURN_ASSEMBLY_METADATA 0x4

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڳوليو_Act_Ctx_Section_String ڳوليو_Act_Ctx_Section_String_W
#وإلا
#وصف_ڪريو ڳوليو_Act_Ctx_Section_String ڳوليو_Act_Ctx_Section_String_A
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI ڳوليو_Act_Ctx_Section_String_A(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lp_String_منزل_ڳوليو,PACTCTX_SECTION_KEYED_معلومات Returned_معلومات);
  WINBASEAPI WINBOOL WINAPI ڳوليو_Act_Ctx_Section_String_W(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lp_String_منزل_ڳوليو,PACTCTX_SECTION_KEYED_معلومات Returned_معلومات);
  WINBASEAPI WINBOOL WINAPI ڳوليو_Act_Ctx_Section_Guid(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,ثابت GUID *lp_Guid_منزل_ڳوليو,PACTCTX_SECTION_KEYED_معلومات Returned_معلومات);

#جيڪڏهن_وصف_نه_ٿيل RC_INVOKED
#جيڪڏهن_وصف_نه_ٿيل ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  تعريفنوع بنية _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  تعريفنوع ثابت بنية _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#وصف_ڪريو ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو QUERY_ACTCTX_FLAG_USE_سرگرم_ACTCTX 0x4
#وصف_ڪريو QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#وصف_ڪريو QUERY_ACTCTX_FLAG_ACTCTX_IS_پتو 0x10
#وصف_ڪريو QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_بفر,سائيز_T cb_بفر,سائيز_T *pcbWrittenOrRequired);

  تعريفنوع WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_بفر,سائيز_T cb_بفر,سائيز_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI Process_Id_منزل_Session_Id(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGet_سرگرم_Console_Session_Id();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION بفر_3,PDWORD Returned_ڊيگهائي);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Highest_ڳنڍ_عدد(PULONG Highest_ڳنڍ_عدد);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Processor_ڳنڍ(UCHAR Processor,PUCHAR ڳنڍ_عدد);
  WINBASEAPI WINBOOL WINAPI Get_Numa_ڳنڍ_Processor_نقاب(UCHAR ڳنڍ_2,PULONGLONG Processor_نقاب);
  WINBASEAPI WINBOOL WINAPI Get_Numa_موجود_يادگيري_ڳنڍ(UCHAR ڳنڍ_2,PULONGLONG موجود_بائيٽون);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
