/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _WINBASE_
#تعریف_کرو _WINBASE_

#تعریف_کرو WINADVAPI DECLSPEC_IMPORT
#تعریف_کرو WINBASEAPI DECLSPEC_IMPORT
#تعریف_کرو ZAWPROXYAPI DECLSPEC_IMPORT

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#تعریف_کرو Define_Handle_جدول(w) ((w),TRUE)
#تعریف_کرو حد_بندی_Ems_صفحات(dw)
#تعریف_کرو سیٹ_تبادلہ_Area_سائز(w) (w)
#تعریف_کرو تالا_Segment(w) GlobalFix((HANDLE)(w))
#تعریف_کرو UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#تعریف_کرو Get_Current_وقت() Get_Tick_گنتی()

#تعریف_کرو Yield()

#تعریف_کرو INVALID_HANDLE_قدر ((HANDLE)(LONG_PTR)-1)
#تعریف_کرو INVALID_FILE_سائز ((DWORD)0xffffffff)
#تعریف_کرو INVALID_سیٹ_FILE_اشارہ_گر ((DWORD)-1)
#تعریف_کرو INVALID_FILE_اوصاف ((DWORD)-1)

#تعریف_کرو FILE_BEGIN 0
#تعریف_کرو FILE_CURRENT 1
#تعریف_کرو FILE_انتہا 2

#تعریف_کرو وقت_ZONE_ID_INVALID ((DWORD)0xffffffff)

#تعریف_کرو WAIT_FAILED ((DWORD)0xffffffff)
#تعریف_کرو WAIT_OBJECT_0 ((حالت_WAIT_0) + 0)
#تعریف_کرو WAIT_ABANDONED ((حالت_ABANDONED_WAIT_0) + 0)
#تعریف_کرو WAIT_ABANDONED_0 ((حالت_ABANDONED_WAIT_0) + 0)
#تعریف_کرو WAIT_IO_COMPLETION حالت_USER_APC
#تعریف_کرو STILL_فعال حالت_PENDING
#تعریف_کرو EXCEPTION_ACCESS_VIOLATION حالت_ACCESS_VIOLATION
#تعریف_کرو EXCEPTION_DATATYPE_MISALIGNMENT حالت_DATATYPE_MISALIGNMENT
#تعریف_کرو EXCEPTION_BREAKPOINT حالت_BREAKPOINT
#تعریف_کرو EXCEPTION_SINGLE_قدم حالت_SINGLE_قدم
#تعریف_کرو EXCEPTION_ARRAY_BOUNDS_EXCEEDED حالت_ARRAY_BOUNDS_EXCEEDED
#تعریف_کرو EXCEPTION_FLT_DENORMAL_عملیہ حالت_FLOAT_DENORMAL_عملیہ
#تعریف_کرو EXCEPTION_FLT_DIVIDE_BY_ZERO حالت_FLOAT_DIVIDE_BY_ZERO
#تعریف_کرو EXCEPTION_FLT_INEXACT_نتیجہ حالت_FLOAT_INEXACT_نتیجہ
#تعریف_کرو EXCEPTION_FLT_INVALID_OPERATION حالت_FLOAT_INVALID_OPERATION
#تعریف_کرو EXCEPTION_FLT_حد_سے_تجاوز حالت_FLOAT_حد_سے_تجاوز
#تعریف_کرو EXCEPTION_FLT_ڈھیر_CHECK حالت_FLOAT_ڈھیر_CHECK
#تعریف_کرو EXCEPTION_FLT_UNDERFLOW حالت_FLOAT_UNDERFLOW
#تعریف_کرو EXCEPTION_INT_DIVIDE_BY_ZERO حالت_INTEGER_DIVIDE_BY_ZERO
#تعریف_کرو EXCEPTION_INT_حد_سے_تجاوز حالت_INTEGER_حد_سے_تجاوز
#تعریف_کرو EXCEPTION_PRIV_INSTRUCTION حالت_PRIVILEGED_INSTRUCTION
#تعریف_کرو EXCEPTION_اندر_صفحہ_ERROR حالت_اندر_صفحہ_ERROR
#تعریف_کرو EXCEPTION_ILLEGAL_INSTRUCTION حالت_ILLEGAL_INSTRUCTION
#تعریف_کرو EXCEPTION_NONCONTINUABLE_EXCEPTION حالت_NONCONTINUABLE_EXCEPTION
#تعریف_کرو EXCEPTION_ڈھیر_حد_سے_تجاوز حالت_ڈھیر_حد_سے_تجاوز
#تعریف_کرو EXCEPTION_INVALID_DISPOSITION حالت_INVALID_DISPOSITION
#تعریف_کرو EXCEPTION_GUARD_صفحہ حالت_GUARD_صفحہ_VIOLATION
#تعریف_کرو EXCEPTION_INVALID_HANDLE حالت_INVALID_HANDLE
#تعریف_کرو EXCEPTION_POSSIBLE_DEADLOCK حالت_POSSIBLE_DEADLOCK
#تعریف_کرو CONTROL_C_EXIT حالت_CONTROL_C_EXIT
#تعریف_کرو Move_حافظہ Rtl_Move_حافظہ
#تعریف_کرو Copy_حافظہ Rtl_Copy_حافظہ
#تعریف_کرو Fill_حافظہ Rtl_Fill_حافظہ
#تعریف_کرو Zero_حافظہ Rtl_Zero_حافظہ
#تعریف_کرو Secure_Zero_حافظہ Rtl_Secure_Zero_حافظہ

#تعریف_کرو FILE_FLAG_WRITE_THROUGH 0x80000000
#تعریف_کرو FILE_FLAG_OVERLAPPED 0x40000000
#تعریف_کرو FILE_FLAG_NO_BUFFERING 0x20000000
#تعریف_کرو FILE_FLAG_RANDOM_ACCESS 0x10000000
#تعریف_کرو FILE_FLAG_SEQUENTIAL_جائزہ 0x8000000
#تعریف_کرو FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#تعریف_کرو FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#تعریف_کرو FILE_FLAG_POSIX_SEMANTICS 0x1000000
#تعریف_کرو FILE_FLAG_OPEN_REPARSE_نقطہ 0x200000
#تعریف_کرو FILE_FLAG_OPEN_NO_RECALL 0x100000
#تعریف_کرو FILE_FLAG_پہلا_PIPE_INSTANCE 0x80000

#تعریف_کرو CREATE_NEW 1
#تعریف_کرو CREATE_ALWAYS 2
#تعریف_کرو OPEN_EXISTING 3
#تعریف_کرو OPEN_ALWAYS 4
#تعریف_کرو TRUNCATE_EXISTING 5

#تعریف_کرو پیش_رفت_CONTINUE 0
#تعریف_کرو پیش_رفت_CANCEL 1
#تعریف_کرو پیش_رفت_STOP 2
#تعریف_کرو پیش_رفت_QUIET 3

#تعریف_کرو CALLBACK_CHUNK_ختم_شدہ 0x0
#تعریف_کرو CALLBACK_دھارا_SWITCH 0x1

#تعریف_کرو COPY_FILE_FAIL_IF_EXISTS 0x1
#تعریف_کرو COPY_FILE_RESTARTABLE 0x2
#تعریف_کرو COPY_FILE_OPEN_ماخذ_FOR_WRITE 0x4
#تعریف_کرو COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#تعریف_کرو REPLACEFILE_WRITE_THROUGH 0x1
#تعریف_کرو REPLACEFILE_IGNORE_ملاؤ_ERRORS 0x2

#تعریف_کرو PIPE_ACCESS_INBOUND 0x1
#تعریف_کرو PIPE_ACCESS_OUTBOUND 0x2
#تعریف_کرو PIPE_ACCESS_DUPLEX 0x3

#تعریف_کرو PIPE_CLIENT_انتہا 0x0
#تعریف_کرو PIPE_SERVER_انتہا 0x1

#تعریف_کرو PIPE_WAIT 0x0
#تعریف_کرو PIPE_NOWAIT 0x1
#تعریف_کرو PIPE_READMODE_BYTE 0x0
#تعریف_کرو PIPE_READMODE_پیغام 0x2
#تعریف_کرو PIPE_TYPE_BYTE 0x0
#تعریف_کرو PIPE_TYPE_پیغام 0x4

#تعریف_کرو PIPE_UNLIMITED_INSTANCES 255

#تعریف_کرو SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#تعریف_کرو SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#تعریف_کرو SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#تعریف_کرو SECURITY_DELEGATION (SecurityDelegation << 16)

#تعریف_کرو SECURITY_CONTEXT_TRACKING 0x40000
#تعریف_کرو SECURITY_EFFECTIVE_ONLY 0x80000

#تعریف_کرو SECURITY_SQOS_PRESENT 0x100000
#تعریف_کرو SECURITY_VALID_SQOS_FLAGS 0x1f0000

  قسمتعریف ساخت _OVERLAPPED {
    ULONG_PTR اندرونی_2;
    ULONG_PTR اندرونی_بلند;
    اتحاد {
      ساخت {
	DWORD انحراف_3;
	DWORD انحراف_بلند_2;
      };
      PVOID اشارہ_گر_2;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  قسمتعریف ساخت SECURITY_اوصاف {
    DWORD n_لمبائی;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_اوصاف_2,*PSECURITY_اوصاف,*LPSECURITY_اوصاف;

  قسمتعریف ساخت _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#اگر_غیر_تعریف_شدہ _FILETIME_
#تعریف_کرو _FILETIME_
  قسمتعریف ساخت _FILETIME {
    DWORD dw_کم_Date_وقت;
    DWORD dw_بلند_Date_وقت;
  } FILETIME,*PFILETIME,*LPFILETIME;
#اگر_ختم

  قسمتعریف ساخت _SYSTEMTIME {
    لفظ_3 wYear;
    لفظ_3 wMonth;
    لفظ_3 w_Day_کا_Week;
    لفظ_3 wDay;
    لفظ_3 wHour;
    لفظ_3 wMinute;
    لفظ_3 w_دوسرا;
    لفظ_3 wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  قسمتعریف DWORD (WINAPI *PTHREAD_آغاز_ROUTINE)(LPVOID lpThreadParameter);
  قسمتعریف PTHREAD_آغاز_ROUTINE LPTHREAD_آغاز_ROUTINE;
  قسمتعریف VOID (WINAPI *PFIBER_آغاز_ROUTINE)(LPVOID lpFiberParameter);
  قسمتعریف PFIBER_آغاز_ROUTINE LPFIBER_آغاز_ROUTINE;

  قسمتعریف RTL_CRITICAL_SECTION CRITICAL_SECTION;
  قسمتعریف PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  قسمتعریف PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  قسمتعریف RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  قسمتعریف PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  قسمتعریف PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI Encode_اشارہ_گر(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_اشارہ_گر(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Encode_System_اشارہ_گر(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_System_اشارہ_گر(PVOID Ptr);

#اگر_تعریف_شدہ I_X86_
  قسمتعریف PLDT_اندراج LPLDT_اندراج;
#ورنہ
  قسمتعریف LPVOID LPLDT_اندراج;
#اگر_ختم

#تعریف_کرو MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#تعریف_کرو MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#تعریف_کرو SP_SERIALCOMM ((DWORD)0x1)

#تعریف_کرو PST_UNSPECIFIED ((DWORD)0x0)
#تعریف_کرو PST_RS232 ((DWORD)0x1)
#تعریف_کرو PST_PARALLELPORT ((DWORD)0x2)
#تعریف_کرو PST_RS422 ((DWORD)0x3)
#تعریف_کرو PST_RS423 ((DWORD)0x4)
#تعریف_کرو PST_RS449 ((DWORD)0x5)
#تعریف_کرو PST_MODEM ((DWORD)0x6)
#تعریف_کرو PST_FAX ((DWORD)0x21)
#تعریف_کرو PST_SCANNER ((DWORD)0x22)
#تعریف_کرو PST_جال_BRIDGE ((DWORD)0x100)
#تعریف_کرو PST_LAT ((DWORD)0x101)
#تعریف_کرو PST_TCPIP_TELNET ((DWORD)0x102)
#تعریف_کرو PST_X25 ((DWORD)0x103)

#تعریف_کرو PCF_DTRDSR ((DWORD)0x1)
#تعریف_کرو PCF_RTSCTS ((DWORD)0x2)
#تعریف_کرو PCF_RLSD ((DWORD)0x4)
#تعریف_کرو PCF_PARITY_CHECK ((DWORD)0x8)
#تعریف_کرو PCF_XONXOFF ((DWORD)0x10)
#تعریف_کرو PCF_SETXCHAR ((DWORD)0x20)
#تعریف_کرو PCF_TOTALTIMEOUTS ((DWORD)0x40)
#تعریف_کرو PCF_INTTIMEOUTS ((DWORD)0x80)
#تعریف_کرو PCF_SPECIALCHARS ((DWORD)0x100)
#تعریف_کرو PCF_16BITMODE ((DWORD)0x200)

#تعریف_کرو SP_PARITY ((DWORD)0x1)
#تعریف_کرو SP_BAUD ((DWORD)0x2)
#تعریف_کرو SP_DATABITS ((DWORD)0x4)
#تعریف_کرو SP_STOPBITS ((DWORD)0x8)
#تعریف_کرو SP_HANDSHAKING ((DWORD)0x10)
#تعریف_کرو SP_PARITY_CHECK ((DWORD)0x20)
#تعریف_کرو SP_RLSD ((DWORD)0x40)

#تعریف_کرو BAUD_075 ((DWORD)0x1)
#تعریف_کرو BAUD_110 ((DWORD)0x2)
#تعریف_کرو BAUD_134_5 ((DWORD)0x4)
#تعریف_کرو BAUD_150 ((DWORD)0x8)
#تعریف_کرو BAUD_300 ((DWORD)0x10)
#تعریف_کرو BAUD_600 ((DWORD)0x20)
#تعریف_کرو BAUD_1200 ((DWORD)0x40)
#تعریف_کرو BAUD_1800 ((DWORD)0x80)
#تعریف_کرو BAUD_2400 ((DWORD)0x100)
#تعریف_کرو BAUD_4800 ((DWORD)0x200)
#تعریف_کرو BAUD_7200 ((DWORD)0x400)
#تعریف_کرو BAUD_9600 ((DWORD)0x800)
#تعریف_کرو BAUD_14400 ((DWORD)0x1000)
#تعریف_کرو BAUD_19200 ((DWORD)0x2000)
#تعریف_کرو BAUD_38400 ((DWORD)0x4000)
#تعریف_کرو BAUD_56K ((DWORD)0x8000)
#تعریف_کرو BAUD_128K ((DWORD)0x10000)
#تعریف_کرو BAUD_115200 ((DWORD)0x20000)
#تعریف_کرو BAUD_57600 ((DWORD)0x40000)
#تعریف_کرو BAUD_USER ((DWORD)0x10000000)

#تعریف_کرو DATABITS_5 ((لفظ_3)0x1)
#تعریف_کرو DATABITS_6 ((لفظ_3)0x2)
#تعریف_کرو DATABITS_7 ((لفظ_3)0x4)
#تعریف_کرو DATABITS_8 ((لفظ_3)0x8)
#تعریف_کرو DATABITS_16 ((لفظ_3)0x10)
#تعریف_کرو DATABITS_16X ((لفظ_3)0x20)

#تعریف_کرو STOPBITS_10 ((لفظ_3)0x1)
#تعریف_کرو STOPBITS_15 ((لفظ_3)0x2)
#تعریف_کرو STOPBITS_20 ((لفظ_3)0x4)
#تعریف_کرو PARITY_NONE ((لفظ_3)0x100)
#تعریف_کرو PARITY_ODD ((لفظ_3)0x200)
#تعریف_کرو PARITY_EVEN ((لفظ_3)0x400)
#تعریف_کرو PARITY_MARK ((لفظ_3)0x800)
#تعریف_کرو PARITY_SPACE ((لفظ_3)0x1000)

  قسمتعریف ساخت _COMMPROP {
    لفظ_3 w_Packet_لمبائی;
    لفظ_3 w_Packet_نسخہ;
    DWORD dw_Service_نقاب;
    DWORD dwReserved1;
    DWORD dw_Max_Tx_قطار;
    DWORD dw_Max_Rx_قطار;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    لفظ_3 w_Settable_ڈیٹا;
    لفظ_3 wSettableStopParity;
    DWORD dw_Current_Tx_قطار;
    DWORD dw_Current_Rx_قطار;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#تعریف_کرو COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  قسمتعریف ساخت _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD f_Xoff_بھیجا : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cb_اندر_Que;
    DWORD cb_برآمد_Que;
  } COMSTAT,*LPCOMSTAT;

#تعریف_کرو DTR_CONTROL_DISABLE 0x0
#تعریف_کرو DTR_CONTROL_ENABLE 0x1
#تعریف_کرو DTR_CONTROL_HANDSHAKE 0x2

#تعریف_کرو RTS_CONTROL_DISABLE 0x0
#تعریف_کرو RTS_CONTROL_ENABLE 0x1
#تعریف_کرو RTS_CONTROL_HANDSHAKE 0x2
#تعریف_کرو RTS_CONTROL_TOGGLE 0x3

  قسمتعریف ساخت _DCB {
    DWORD DCBlength;
    DWORD Baud_شرح;
    DWORD f_ثنائی: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD f_Dsr_حساسیت:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD f_برآمد_X: 1;
    DWORD f_اندر_X: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    لفظ_3 wReserved;
    لفظ_3 XonLim;
    لفظ_3 XoffLim;
    BYTE Byte_سائز;
    BYTE Parity;
    BYTE Stop_بٹ;
    حرف XonChar;
    حرف XoffChar;
    حرف ErrorChar;
    حرف EofChar;
    حرف EvtChar;
    لفظ_3 wReserved1;
  } DCB,*LPDCB;

  قسمتعریف ساخت _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD Read_کل_Timeout_Multiplier;
    DWORD Read_کل_Timeout_Constant;
    DWORD Write_کل_Timeout_Multiplier;
    DWORD Write_کل_Timeout_Constant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  قسمتعریف ساخت _COMMCONFIG {
    DWORD dw_سائز;
    لفظ_3 w_نسخہ;
    لفظ_3 wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dw_Provider_انحراف;
    DWORD dw_Provider_سائز;
    WCHAR wc_Provider_ڈیٹا[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  قسمتعریف ساخت _SYSTEM_INFO {
    اتحاد {
      DWORD dwOemId;
      ساخت {
	لفظ_3 wProcessorArchitecture;
	لفظ_3 wReserved;
      };
    };
    DWORD dw_صفحہ_سائز;
    LPVOID lp_Minimum_Application_پتہ;
    LPVOID lp_زیادہ_سے_زیادہ_Application_پتہ;
    DWORD_PTR dw_فعال_Processor_نقاب;
    DWORD dw_نمبر_کا_Processors;
    DWORD dwProcessorType;
    DWORD dw_تخصیص_Granularity;
    لفظ_3 wProcessorLevel;
    لفظ_3 wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#تعریف_کرو FreeModule(hLibModule) FreeLibrary((hLibModule))
#تعریف_کرو MakeProcInstance(lpProc,hInstance) (lpProc)
#تعریف_کرو FreeProcInstance(lpProc) (lpProc)

#تعریف_کرو GMEM_FIXED 0x0
#تعریف_کرو GMEM_MOVEABLE 0x2
#تعریف_کرو GMEM_NOCOMPACT 0x10
#تعریف_کرو GMEM_NODISCARD 0x20
#تعریف_کرو GMEM_ZEROINIT 0x40
#تعریف_کرو GMEM_MODIFY 0x80
#تعریف_کرو GMEM_DISCARDABLE 0x100
#تعریف_کرو GMEM_NOT_BANKED 0x1000
#تعریف_کرو GMEM_SHARE 0x2000
#تعریف_کرو GMEM_DDESHARE 0x2000
#تعریف_کرو GMEM_NOTIFY 0x4000
#تعریف_کرو GMEM_زیریں GMEM_NOT_BANKED
#تعریف_کرو GMEM_VALID_FLAGS 0x7F72
#تعریف_کرو GMEM_INVALID_HANDLE 0x8000

#تعریف_کرو GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#تعریف_کرو GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#تعریف_کرو GlobalLRUNewest(h) ((HANDLE)(h))
#تعریف_کرو GlobalLRUOldest(h) ((HANDLE)(h))
#تعریف_کرو GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#تعریف_کرو GMEM_DISCARDED 0x4000
#تعریف_کرو GMEM_LOCKCOUNT 0xff

  قسمتعریف ساخت _MEMORYSTATUS {
    DWORD dw_لمبائی;
    DWORD dw_حافظہ_بھرو;
    سائز_T dw_کل_Phys;
    سائز_T dwAvailPhys;
    سائز_T dw_کل_صفحہ_File;
    سائز_T dw_Avail_صفحہ_File;
    سائز_T dw_کل_Virtual;
    سائز_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#تعریف_کرو LMEM_FIXED 0x0
#تعریف_کرو LMEM_MOVEABLE 0x2
#تعریف_کرو LMEM_NOCOMPACT 0x10
#تعریف_کرو LMEM_NODISCARD 0x20
#تعریف_کرو LMEM_ZEROINIT 0x40
#تعریف_کرو LMEM_MODIFY 0x80
#تعریف_کرو LMEM_DISCARDABLE 0xf00
#تعریف_کرو LMEM_VALID_FLAGS 0xf72
#تعریف_کرو LMEM_INVALID_HANDLE 0x8000

#تعریف_کرو LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#تعریف_کرو LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#تعریف_کرو NONZEROLHND (LMEM_MOVEABLE)
#تعریف_کرو NONZEROLPTR (LMEM_FIXED)

#تعریف_کرو LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#تعریف_کرو LMEM_DISCARDED 0x4000
#تعریف_کرو LMEM_LOCKCOUNT 0xff

#تعریف_کرو DEBUG_PROCESS 0x1
#تعریف_کرو DEBUG_ONLY_THIS_PROCESS 0x2
#تعریف_کرو CREATE_SUSPENDED 0x4
#تعریف_کرو DETACHED_PROCESS 0x8
#تعریف_کرو CREATE_NEW_CONSOLE 0x10
#تعریف_کرو معمول_ترجیح_CLASS 0x20
#تعریف_کرو IDLE_ترجیح_CLASS 0x40
#تعریف_کرو بلند_ترجیح_CLASS 0x80
#تعریف_کرو REALTIME_ترجیح_CLASS 0x100
#تعریف_کرو CREATE_NEW_PROCESS_گروہ 0x200
#تعریف_کرو CREATE_UNICODE_ENVIRONMENT 0x400
#تعریف_کرو CREATE_SEPARATE_WOW_VDM 0x800
#تعریف_کرو CREATE_SHARED_WOW_VDM 0x1000
#تعریف_کرو CREATE_FORCEDOS 0x2000
#تعریف_کرو نیچے_معمول_ترجیح_CLASS 0x4000
#تعریف_کرو ABOVE_معمول_ترجیح_CLASS 0x8000
#تعریف_کرو ڈھیر_سائز_PARAM_IS_A_RESERVATION 0x10000

#تعریف_کرو CREATE_BREAKAWAY_FROM_کام 0x1000000
#تعریف_کرو CREATE_PRESERVE_رمز_AUTHZ_LEVEL 0x2000000

#تعریف_کرو CREATE_DEFAULT_ERROR_منوال 0x4000000
#تعریف_کرو CREATE_NO_کھڑکی 0x8000000

#تعریف_کرو PROFILE_USER 0x10000000
#تعریف_کرو PROFILE_KERNEL 0x20000000
#تعریف_کرو PROFILE_SERVER 0x40000000

#تعریف_کرو CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#تعریف_کرو THREAD_ترجیح_سب_سے_نیچا THREAD_بنیاد_ترجیح_MIN
#تعریف_کرو THREAD_ترجیح_نیچے_معمول (THREAD_ترجیح_سب_سے_نیچا+1)
#تعریف_کرو THREAD_ترجیح_معمول 0
#تعریف_کرو THREAD_ترجیح_HIGHEST THREAD_بنیاد_ترجیح_MAX
#تعریف_کرو THREAD_ترجیح_ABOVE_معمول (THREAD_ترجیح_HIGHEST-1)
#تعریف_کرو THREAD_ترجیح_ERROR_RETURN (MAXLONG)

#تعریف_کرو THREAD_ترجیح_وقت_CRITICAL THREAD_بنیاد_ترجیح_LOWRT
#تعریف_کرو THREAD_ترجیح_IDLE THREAD_بنیاد_ترجیح_IDLE

#تعریف_کرو EXCEPTION_DEBUG_EVENT 1
#تعریف_کرو CREATE_THREAD_DEBUG_EVENT 2
#تعریف_کرو CREATE_PROCESS_DEBUG_EVENT 3
#تعریف_کرو EXIT_THREAD_DEBUG_EVENT 4
#تعریف_کرو EXIT_PROCESS_DEBUG_EVENT 5
#تعریف_کرو بھرو_DLL_DEBUG_EVENT 6
#تعریف_کرو UNLOAD_DLL_DEBUG_EVENT 7
#تعریف_کرو OUTPUT_DEBUG_STRING_EVENT 8
#تعریف_کرو RIP_EVENT 9

  قسمتعریف ساخت _EXCEPTION_DEBUG_INFO {
    EXCEPTION_ریکارڈ_2 Exception_ریکارڈ;
    DWORD dw_پہلا_Chance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  قسمتعریف ساخت _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lp_Thread_Local_بنیاد;
    LPTHREAD_آغاز_ROUTINE lp_آغاز_پتہ;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  قسمتعریف ساخت _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lp_بنیاد_کا_Image;
    DWORD dw_Debug_Info_File_انحراف;
    DWORD n_Debug_Info_سائز;
    LPVOID lp_Thread_Local_بنیاد;
    LPTHREAD_آغاز_ROUTINE lp_آغاز_پتہ;
    LPVOID lpImageName;
    لفظ_3 fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  قسمتعریف ساخت _EXIT_THREAD_DEBUG_INFO {
    DWORD dw_Exit_رمز;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  قسمتعریف ساخت _EXIT_PROCESS_DEBUG_INFO {
    DWORD dw_Exit_رمز;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  قسمتعریف ساخت بھرو_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lp_بنیاد_کا_Dll;
    DWORD dw_Debug_Info_File_انحراف;
    DWORD n_Debug_Info_سائز;
    LPVOID lpImageName;
    لفظ_3 fUnicode;
  } بھرو_DLL_DEBUG_INFO_2,*LPLOAD_DLL_DEBUG_INFO;

  قسمتعریف ساخت _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lp_بنیاد_کا_Dll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  قسمتعریف ساخت _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lp_Debug_String_ڈیٹا;
    لفظ_3 fUnicode;
    لفظ_3 n_Debug_String_لمبائی;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  قسمتعریف ساخت _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  قسمتعریف ساخت _DEBUG_EVENT {
    DWORD dw_Debug_Event_رمز;
    DWORD dwProcessId;
    DWORD dwThreadId;
    اتحاد {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      بھرو_DLL_DEBUG_INFO_2 بھرو_Dll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  قسمتعریف PCONTEXT LPCONTEXT;
  قسمتعریف PEXCEPTION_ریکارڈ LPEXCEPTION_ریکارڈ;
  قسمتعریف PEXCEPTION_اشارے LPEXCEPTION_اشارے;

#تعریف_کرو DRIVE_UNKNOWN 0
#تعریف_کرو DRIVE_NO_جڑ_DIR 1
#تعریف_کرو DRIVE_REMOVABLE 2
#تعریف_کرو DRIVE_FIXED 3
#تعریف_کرو DRIVE_REMOTE 4
#تعریف_کرو DRIVE_CDROM 5
#تعریف_کرو DRIVE_RAMDISK 6

#تعریف_کرو GetFreeSpace(w) (0x100000L)
#تعریف_کرو FILE_TYPE_UNKNOWN 0x0
#تعریف_کرو FILE_TYPE_DISK 0x1
#تعریف_کرو FILE_TYPE_CHAR 0x2
#تعریف_کرو FILE_TYPE_PIPE 0x3
#تعریف_کرو FILE_TYPE_REMOTE 0x8000

#تعریف_کرو STD_داخلہ_HANDLE ((DWORD)-10)
#تعریف_کرو STD_OUTPUT_HANDLE ((DWORD)-11)
#تعریف_کرو STD_ERROR_HANDLE ((DWORD)-12)

#تعریف_کرو NOPARITY 0
#تعریف_کرو ODDPARITY 1
#تعریف_کرو EVENPARITY 2
#تعریف_کرو MARKPARITY 3
#تعریف_کرو SPACEPARITY 4

#تعریف_کرو ONESTOPBIT 0
#تعریف_کرو ONE5STOPBITS 1
#تعریف_کرو TWOSTOPBITS 2

#تعریف_کرو IGNORE 0
#تعریف_کرو INFINITE 0xffffffff

#تعریف_کرو CBR_110 110
#تعریف_کرو CBR_300 300
#تعریف_کرو CBR_600 600
#تعریف_کرو CBR_1200 1200
#تعریف_کرو CBR_2400 2400
#تعریف_کرو CBR_4800 4800
#تعریف_کرو CBR_9600 9600
#تعریف_کرو CBR_14400 14400
#تعریف_کرو CBR_19200 19200
#تعریف_کرو CBR_38400 38400
#تعریف_کرو CBR_56000 56000
#تعریف_کرو CBR_57600 57600
#تعریف_کرو CBR_115200 115200
#تعریف_کرو CBR_128000 128000
#تعریف_کرو CBR_256000 256000

#تعریف_کرو CE_RXOVER 0x1
#تعریف_کرو CE_OVERRUN 0x2
#تعریف_کرو CE_RXPARITY 0x4
#تعریف_کرو CE_چوکھٹا 0x8
#تعریف_کرو CE_BREAK 0x10
#تعریف_کرو CE_TXFULL 0x100
#تعریف_کرو CE_PTO 0x200
#تعریف_کرو CE_IOE 0x400
#تعریف_کرو CE_DNS 0x800
#تعریف_کرو CE_OOP 0x1000
#تعریف_کرو CE_منوال 0x8000

#تعریف_کرو IE_BADID (-1)
#تعریف_کرو IE_OPEN (-2)
#تعریف_کرو IE_NOPEN (-3)
#تعریف_کرو IE_حافظہ (-4)
#تعریف_کرو IE_DEFAULT (-5)
#تعریف_کرو IE_HARDWARE (-10)
#تعریف_کرو IE_BYTESIZE (-11)
#تعریف_کرو IE_BAUDRATE (-12)

#تعریف_کرو EV_RXCHAR 0x1
#تعریف_کرو EV_RXFLAG 0x2
#تعریف_کرو EV_TXEMPTY 0x4
#تعریف_کرو EV_CTS 0x8
#تعریف_کرو EV_DSR 0x10
#تعریف_کرو EV_RLSD 0x20
#تعریف_کرو EV_BREAK 0x40
#تعریف_کرو EV_ERR 0x80
#تعریف_کرو EV_RING 0x100
#تعریف_کرو EV_PERR 0x200
#تعریف_کرو EV_RX80_بھرا 0x400
#تعریف_کرو EV_EVENT1 0x800
#تعریف_کرو EV_EVENT2 0x1000

#تعریف_کرو SETXOFF 1
#تعریف_کرو SETXON 2
#تعریف_کرو SETRTS 3
#تعریف_کرو CLRRTS 4
#تعریف_کرو SETDTR 5
#تعریف_کرو CLRDTR 6
#تعریف_کرو RESETDEV 7
#تعریف_کرو SETBREAK 8
#تعریف_کرو CLRBREAK 9

#تعریف_کرو PURGE_TXABORT 0x1
#تعریف_کرو PURGE_RXABORT 0x2
#تعریف_کرو PURGE_TXCLEAR 0x4
#تعریف_کرو PURGE_RXCLEAR 0x8

#تعریف_کرو LPTx 0x80

#تعریف_کرو MS_CTS_ON ((DWORD)0x10)
#تعریف_کرو MS_DSR_ON ((DWORD)0x20)
#تعریف_کرو MS_RING_ON ((DWORD)0x40)
#تعریف_کرو MS_RLSD_ON ((DWORD)0x80)

#تعریف_کرو S_QUEUEEMPTY 0
#تعریف_کرو S_حد 1
#تعریف_کرو S_ALLTHRESHOLD 2

#تعریف_کرو S_معمول 0
#تعریف_کرو S_LEGATO 1
#تعریف_کرو S_STACCATO 2

#تعریف_کرو S_PERIOD512 0
#تعریف_کرو S_PERIOD1024 1
#تعریف_کرو S_PERIOD2048 2
#تعریف_کرو S_PERIODVOICE 3
#تعریف_کرو S_WHITE512 4
#تعریف_کرو S_WHITE1024 5
#تعریف_کرو S_WHITE2048 6
#تعریف_کرو S_WHITEVOICE 7

#تعریف_کرو S_SERDVNA (-1)
#تعریف_کرو S_SEROFM (-2)
#تعریف_کرو S_SERMACT (-3)
#تعریف_کرو S_SERQFUL (-4)
#تعریف_کرو S_SERBDNT (-5)
#تعریف_کرو S_SERDLN (-6)
#تعریف_کرو S_SERDCC (-7)
#تعریف_کرو S_SERDTP (-8)
#تعریف_کرو S_SERDVL (-9)
#تعریف_کرو S_SERDMD (-10)
#تعریف_کرو S_SERDSH (-11)
#تعریف_کرو S_SERDPT (-12)
#تعریف_کرو S_SERDFQ (-13)
#تعریف_کرو S_SERDDR (-14)
#تعریف_کرو S_SERDSR (-15)
#تعریف_کرو S_SERDST (-16)

#تعریف_کرو NMPWAIT_WAIT_FOREVER 0xffffffff
#تعریف_کرو NMPWAIT_NOWAIT 0x1
#تعریف_کرو NMPWAIT_USE_DEFAULT_WAIT 0x0

#تعریف_کرو FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_نام
#تعریف_کرو FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_تلاش
#تعریف_کرو FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#تعریف_کرو FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#تعریف_کرو FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#تعریف_کرو FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#تعریف_کرو FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#تعریف_کرو FILE_MAP_COPY SECTION_QUERY
#تعریف_کرو FILE_MAP_WRITE SECTION_MAP_WRITE
#تعریف_کرو FILE_MAP_READ SECTION_MAP_READ
#تعریف_کرو FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#تعریف_کرو FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#تعریف_کرو کا_READ 0x0
#تعریف_کرو کا_WRITE 0x1
#تعریف_کرو کا_READWRITE 0x2
#تعریف_کرو کا_SHARE_COMPAT 0x0
#تعریف_کرو کا_SHARE_EXCLUSIVE 0x10
#تعریف_کرو کا_SHARE_DENY_WRITE 0x20
#تعریف_کرو کا_SHARE_DENY_READ 0x30
#تعریف_کرو کا_SHARE_DENY_NONE 0x40
#تعریف_کرو کا_PARSE 0x100
#تعریف_کرو کا_DELETE 0x200
#تعریف_کرو کا_VERIFY 0x400
#تعریف_کرو کا_CANCEL 0x800
#تعریف_کرو کا_CREATE 0x1000
#تعریف_کرو کا_PROMPT 0x2000
#تعریف_کرو کا_EXIST 0x4000
#تعریف_کرو کا_REOPEN 0x8000

#تعریف_کرو OFS_MAXPATHNAME 128
  قسمتعریف ساخت _OFSTRUCT {
    BYTE c_بائٹیں;
    BYTE fFixedDisk;
    لفظ_3 n_Err_رمز;
    لفظ_3 Reserved1;
    لفظ_3 Reserved2;
    CHAR sz_راستہ_Name[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#اگر_غیر_تعریف_شدہ NOWINBASEINTERLOCK

#اگر_غیر_تعریف_شدہ _NTOS_

#اگر defined(__ia64__) && !defined(RC_INVOKED)

#تعریف_کرو InterlockedIncrement _InterlockedIncrement
#تعریف_کرو InterlockedIncrementAcquire _InterlockedIncrement_acq
#تعریف_کرو InterlockedIncrementRelease _InterlockedIncrement_rel
#تعریف_کرو InterlockedDecrement _InterlockedDecrement
#تعریف_کرو InterlockedDecrementAcquire _InterlockedDecrement_acq
#تعریف_کرو InterlockedDecrementRelease _InterlockedDecrement_rel
#تعریف_کرو InterlockedExchange _InterlockedExchange
#تعریف_کرو Interlocked_Exchange_جوڑو Interlocked_Exchange_جوڑو_2
#تعریف_کرو InterlockedCompareExchange _InterlockedCompareExchange
#تعریف_کرو InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#تعریف_کرو InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#تعریف_کرو Interlocked_Exchange_اشارہ_گر Interlocked_Exchange_اشارہ_گر_2
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر Interlocked_Compare_Exchange_اشارہ_گر_2
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Release Interlocked_Compare_Exchange_اشارہ_گر_rel
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Acquire Interlocked_Compare_Exchange_اشارہ_گر_acq

#تعریف_کرو InterlockedIncrement64 _InterlockedIncrement64
#تعریف_کرو InterlockedDecrement64 _InterlockedDecrement64
#تعریف_کرو InterlockedExchange64 _InterlockedExchange64
#تعریف_کرو InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#تعریف_کرو InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#تعریف_کرو InterlockedCompareExchange64 _InterlockedCompareExchange64
#تعریف_کرو InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#تعریف_کرو InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG متلون *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG متلون *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG متلون *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG متلون *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG متلون *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG متلون *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG متلون *ہدف_2,LONGLONG قدر_3);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG متلون *ہدف_2,LONGLONG قدر_3);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG متلون *Addend,LONGLONG قدر_3);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG متلون *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG متلون *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG متلون *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG متلون *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG متلون *lpAddend);
  LONG __cdecl InterlockedExchange(LONG متلون *ہدف_2,LONG قدر_3);
  LONG __cdecl Interlocked_Exchange_جوڑو(LONG متلون *Addend,LONG قدر_3);
  LONG __cdecl InterlockedCompareExchange(LONG متلون *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG متلون *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG متلون *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl Interlocked_Exchange_اشارہ_گر(PVOID متلون *ہدف_2,PVOID قدر_3);
  PVOID __cdecl Interlocked_Compare_Exchange_اشارہ_گر(PVOID متلون *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_اشارہ_گر_Acquire(PVOID متلون *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_اشارہ_گر_Release(PVOID متلون *Destination,PVOID Exchange,PVOID Comperand);

#اگر_غیر_تعریف_شدہ InterlockedAnd
#تعریف_کرو InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG متلون *ہدف_2,LONG سیٹ_2) {
    LONG i;
    LONG j;
    j = *ہدف_2;
    کرو {
      i = j;
      j = InterlockedCompareExchange(ہدف_2,i & سیٹ_2,i);
    } جب(i!=j);
    واپس j;
  }
#اگر_ختم

#اگر_غیر_تعریف_شدہ InterlockedOr
#تعریف_کرو InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG متلون *ہدف_2,LONG سیٹ_2) {
    LONG i;
    LONG j;
    j = *ہدف_2;
    کرو {
      i = j;
      j = InterlockedCompareExchange(ہدف_2,i | سیٹ_2,i);
    } جب(i!=j);
    واپس j;
  }
#اگر_ختم

#اگر_غیر_تعریف_شدہ InterlockedXor
#تعریف_کرو InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG متلون *ہدف_2,LONG سیٹ_2) {
    LONG i;
    LONG j;
    j = *ہدف_2;
    کرو {
      i = j;
      j = InterlockedCompareExchange(ہدف_2,i ^ سیٹ_2,i);
    } جب(i!=j);
    واپس j;
  }
#اگر_ختم

#اگر_غیر_تعریف_شدہ InterlockedAnd64
#تعریف_کرو InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG متلون *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    کرو {
      Old = *Destination;
    } جب(InterlockedCompareExchange64(Destination,Old & قدر_3,Old)!=Old);
    واپس Old;
  }
#اگر_ختم

#اگر_غیر_تعریف_شدہ InterlockedOr64
#تعریف_کرو InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG متلون *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    کرو {
      Old = *Destination;
    } جب(InterlockedCompareExchange64(Destination,Old | قدر_3,Old)!=Old);
    واپس Old;
  }
#اگر_ختم

#اگر_غیر_تعریف_شدہ InterlockedXor64
#تعریف_کرو InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG متلون *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    کرو {
      Old = *Destination;
    } جب(InterlockedCompareExchange64(Destination,Old ^ قدر_3,Old)!=Old);
    واپس Old;
  }
#اگر_ختم

#اگر_غیر_تعریف_شدہ Interlocked_ثنائی_ہندسہ_Test_And_سیٹ
#تعریف_کرو Interlocked_ثنائی_ہندسہ_Test_And_سیٹ Interlocked_ثنائی_ہندسہ_Test_And_سیٹ_Inline

  __CRT_INLINE BOOLEAN Interlocked_ثنائی_ہندسہ_Test_And_سیٹ_Inline(LONG *بنیاد_2,LONG ثنائی_ہندسہ_2) {
    LONG t_ثنائی_ہندسہ;
    t_ثنائی_ہندسہ = 1<<(ثنائی_ہندسہ_2 & (حجم (*بنیاد_2)*8-1));
    واپس (BOOLEAN)((InterlockedOr(&بنیاد_2[ثنائی_ہندسہ_2/(حجم(*بنیاد_2)*8)],t_ثنائی_ہندسہ)&t_ثنائی_ہندسہ)!=0);
  }
#اگر_ختم

#اگر_غیر_تعریف_شدہ Interlocked_ثنائی_ہندسہ_Test_And_Reset
#تعریف_کرو Interlocked_ثنائی_ہندسہ_Test_And_Reset Interlocked_ثنائی_ہندسہ_Test_And_Reset_Inline

  __CRT_INLINE BOOLEAN Interlocked_ثنائی_ہندسہ_Test_And_Reset_Inline(LONG *بنیاد_2,LONG ثنائی_ہندسہ_2) {
    LONG t_ثنائی_ہندسہ;
    t_ثنائی_ہندسہ = 1<<(ثنائی_ہندسہ_2 & (حجم (*بنیاد_2)*8-1));
    واپس (BOOLEAN)((InterlockedAnd(&بنیاد_2[ثنائی_ہندسہ_2/(حجم(*بنیاد_2)*8)],~t_ثنائی_ہندسہ)&t_ثنائی_ہندسہ)!=0);
  }
#اگر_ختم

#اگر_غیر_تعریف_شدہ Interlocked_ثنائی_ہندسہ_Test_And_Complement
#تعریف_کرو Interlocked_ثنائی_ہندسہ_Test_And_Complement Interlocked_ثنائی_ہندسہ_Test_And_Complement_Inline

  __CRT_INLINE BOOLEAN Interlocked_ثنائی_ہندسہ_Test_And_Complement_Inline(LONG *بنیاد_2,LONG ثنائی_ہندسہ_2) {
    LONG t_ثنائی_ہندسہ;
    t_ثنائی_ہندسہ = 1<<(ثنائی_ہندسہ_2 & (حجم (*بنیاد_2)*8-1));
    واپس (BOOLEAN)((InterlockedXor(&بنیاد_2[ثنائی_ہندسہ_2/(حجم(*بنیاد_2)*8)],t_ثنائی_ہندسہ)&t_ثنائی_ہندسہ)!=0);
  }
#اگر_ختم
#وگرنہ_اگر defined(__x86_64) && !defined(RC_INVOKED)

#تعریف_کرو InterlockedIncrement _InterlockedIncrement
#تعریف_کرو InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کرو InterlockedIncrementRelease InterlockedIncrement
#تعریف_کرو InterlockedDecrement _InterlockedDecrement
#تعریف_کرو InterlockedDecrementAcquire InterlockedDecrement
#تعریف_کرو InterlockedDecrementRelease InterlockedDecrement
#تعریف_کرو InterlockedExchange _InterlockedExchange
#تعریف_کرو Interlocked_Exchange_جوڑو Interlocked_Exchange_جوڑو_2
#تعریف_کرو InterlockedCompareExchange _InterlockedCompareExchange
#تعریف_کرو InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کرو InterlockedCompareExchangeRelease InterlockedCompareExchange
#تعریف_کرو Interlocked_Exchange_اشارہ_گر Interlocked_Exchange_اشارہ_گر_2
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر Interlocked_Compare_Exchange_اشارہ_گر_2
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Acquire Interlocked_Compare_Exchange_اشارہ_گر_2
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Release Interlocked_Compare_Exchange_اشارہ_گر_2
#تعریف_کرو InterlockedAnd64 _InterlockedAnd64
#تعریف_کرو InterlockedOr64 _InterlockedOr64
#تعریف_کرو InterlockedXor64 _InterlockedXor64
#تعریف_کرو InterlockedIncrement64 _InterlockedIncrement64
#تعریف_کرو InterlockedDecrement64 _InterlockedDecrement64
#تعریف_کرو InterlockedExchange64 _InterlockedExchange64
#تعریف_کرو InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#تعریف_کرو InterlockedCompareExchange64 _InterlockedCompareExchange64
#تعریف_کرو InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#تعریف_کرو InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG متلون *Addend);
  LONG InterlockedDecrement(LONG متلون *Addend);
  LONG InterlockedExchange(LONG متلون *ہدف_2,LONG قدر_3);
  LONG Interlocked_Exchange_جوڑو(LONG متلون *Addend,LONG قدر_3);
  LONG InterlockedCompareExchange(LONG متلون *Destination,LONG ExChange,LONG Comperand);
  PVOID Interlocked_Compare_Exchange_اشارہ_گر(PVOID متلون *Destination,PVOID Exchange,PVOID Comperand);
  PVOID Interlocked_Exchange_اشارہ_گر(PVOID متلون *ہدف_2,PVOID قدر_3);
  LONG64 InterlockedAnd64(LONG64 متلون *Destination,LONG64 قدر_3);
  LONG64 InterlockedOr64(LONG64 متلون *Destination,LONG64 قدر_3);
  LONG64 InterlockedXor64(LONG64 متلون *Destination,LONG64 قدر_3);
  LONG64 InterlockedIncrement64(LONG64 متلون *Addend);
  LONG64 InterlockedDecrement64(LONG64 متلون *Addend);
  LONG64 InterlockedExchange64(LONG64 متلون *ہدف_2,LONG64 قدر_3);
  LONG64 InterlockedExchangeAdd64(LONG64 متلون *Addend,LONG64 قدر_3);
  LONG64 InterlockedCompareExchange64(LONG64 متلون *Destination,LONG64 ExChange,LONG64 Comperand);
#ورنہ
  LONG WINAPI InterlockedIncrement(LONG متلون *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG متلون *lpAddend);
  LONG WINAPI InterlockedExchange(LONG متلون *ہدف_2,LONG قدر_3);

#اگر_غیر_تعریف_شدہ Interlocked_Exchange_اشارہ_گر
#تعریف_کرو Interlocked_Exchange_اشارہ_گر(ہدف_2,قدر_3) (PVOID)InterlockedExchange((PLONG)(ہدف_2),(LONG)(قدر_3))
#اگر_ختم

  LONG WINAPI Interlocked_Exchange_جوڑو(LONG متلون *Addend,LONG قدر_3);
  LONG WINAPI InterlockedCompareExchange(LONG متلون *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG متلون *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG متلون *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    کرو {
      Old = *Destination;
    } جب(InterlockedCompareExchange64(Destination,Old & قدر_3,Old)!=Old);
    واپس Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG متلون *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    کرو {
      Old = *Destination;
    } جب(InterlockedCompareExchange64(Destination,Old | قدر_3,Old)!=Old);
    واپس Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG متلون *Destination,LONGLONG قدر_3) {
    LONGLONG Old;
    کرو {
      Old = *Destination;
    } جب(InterlockedCompareExchange64(Destination,Old ^ قدر_3,Old)!=Old);

    واپس Old;
  }

  __CRT_INLINE LONGLONG InterlockedIncrement64(LONGLONG متلون *Addend) {
    LONGLONG Old;
    کرو {
      Old = *Addend;
    } جب(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    واپس Old + 1;
  }

  __CRT_INLINE LONGLONG InterlockedDecrement64(LONGLONG متلون *Addend) {
    LONGLONG Old;
    کرو {
      Old = *Addend;
    } جب(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    واپس Old - 1;
  }

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG متلون *ہدف_2,LONGLONG قدر_3) {
    LONGLONG Old;
    کرو {
      Old = *ہدف_2;
    } جب(InterlockedCompareExchange64(ہدف_2,قدر_3,Old)!=Old);
    واپس Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG متلون *Addend,LONGLONG قدر_3) {
    LONGLONG Old;
    کرو {
      Old = *Addend;
    } جب(InterlockedCompareExchange64(Addend,Old + قدر_3,Old)!=Old);
    واپس Old;
  }

#اگر_غیر_تعریف_شدہ Interlocked_Compare_Exchange_اشارہ_گر
#اگر_تعریف_شدہ __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID متلون *Destination,PVOID ExChange,PVOID Comperand) {
    واپس((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG متلون *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر __InlineInterlockedCompareExchangePointer
#ورنہ
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG متلون *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#اگر_ختم
#اگر_ختم

#تعریف_کرو InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کرو InterlockedIncrementRelease InterlockedIncrement
#تعریف_کرو InterlockedDecrementAcquire InterlockedDecrement
#تعریف_کرو InterlockedDecrementRelease InterlockedDecrement
#تعریف_کرو InterlockedIncrementAcquire InterlockedIncrement
#تعریف_کرو InterlockedIncrementRelease InterlockedIncrement
#تعریف_کرو InterlockedCompareExchangeAcquire InterlockedCompareExchange
#تعریف_کرو InterlockedCompareExchangeRelease InterlockedCompareExchange
#تعریف_کرو InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#تعریف_کرو InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#اگر_غیر_تعریف_شدہ Interlocked_Compare_Exchange_اشارہ_گر_Acquire
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Acquire Interlocked_Compare_Exchange_اشارہ_گر
#اگر_ختم
#اگر_غیر_تعریف_شدہ Interlocked_Compare_Exchange_اشارہ_گر_Release
#تعریف_کرو Interlocked_Compare_Exchange_اشارہ_گر_Release Interlocked_Compare_Exchange_اشارہ_گر
#اگر_ختم
#اگر_ختم

#اگر defined(SLIST_سرخی) && !defined(_NTOSP_)
  WINBASEAPI VOID WINAPI Initialize_SList_سر(PSLIST_سرخی List_سر);
  WINBASEAPI PSLIST_اندراج WINAPI Interlocked_نکالو_اندراج_SList(PSLIST_سرخی List_سر);
  WINBASEAPI PSLIST_اندراج WINAPI Interlocked_ڈالو_اندراج_SList(PSLIST_سرخی List_سر,PSLIST_اندراج List_اندراج);
  WINBASEAPI PSLIST_اندراج WINAPI InterlockedFlushSList(PSLIST_سرخی List_سر);
  WINBASEAPI USHORT WINAPI Query_گہرائی_SList(PSLIST_سرخی List_سر);
#اگر_ختم
#اگر_ختم
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL h_Res_ڈیٹا);
  WINBASEAPI LPVOID WINAPI تالا_Resource(HGLOBAL h_Res_ڈیٹا);

#تعریف_کرو UnlockResource(h_Res_ڈیٹا) ((h_Res_ڈیٹا),0)
#تعریف_کرو MAXINTATOM 0xC000
#تعریف_کرو MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((لفظ_3)(i)))
#تعریف_کرو INVALID_ATOM ((ATOM)0)

  صحیح WINAPI WinMain(HINSTANCE hInstance,HINSTANCE h_پچھلا_Instance,LPSTR lp_Cmd_سطر,صحیح nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dw_Exit_رمز);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI Get_Proc_پتہ(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI Get_نسخہ(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,سائز_T dw_بائٹیں);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,سائز_T dw_بائٹیں,UINT uFlags);
  WINBASEAPI سائز_T WINAPI Global_سائز(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI Global_تالا(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI سائز_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI Global_حافظہ_حالت(LPMEMORYSTATUS lp_بفر);

  قسمتعریف ساخت _MEMORYSTATUSEX {
    DWORD dw_لمبائی;
    DWORD dw_حافظہ_بھرو;
    DWORDLONG ull_کل_Phys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ull_کل_صفحہ_File;
    DWORDLONG ull_Avail_صفحہ_File;
    DWORDLONG ull_کل_Virtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI Global_حافظہ_حالت_Ex(LPMEMORYSTATUSEX lp_بفر);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,سائز_T u_بائٹیں);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,سائز_T u_بائٹیں,UINT uFlags);
  WINBASEAPI LPVOID WINAPI Local_تالا(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI سائز_T WINAPI Local_سائز(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI سائز_T WINAPI LocalShrink(HLOCAL hMem,UINT cb_New_سائز);
  WINBASEAPI سائز_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lp_بنیاد_پتہ,سائز_T dw_سائز);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lp_پتہ,سائز_T dw_سائز,DWORD fl_تخصیص_Type,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lp_پتہ,سائز_T dw_سائز,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lp_پتہ,سائز_T dw_سائز,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI سائز_T WINAPI VirtualQuery(LPCVOID lp_پتہ,PMEMORY_BASIC_INFORMATION lp_بفر,سائز_T dw_لمبائی);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lp_پتہ,سائز_T dw_سائز,DWORD fl_تخصیص_Type,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lp_بنیاد_پتہ,سائز_T dw_Region_سائز,PVOID *lp_پتے,ULONG_PTR *lpdw_گنتی,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lp_بنیاد_پتہ,سائز_T dw_Region_سائز);
  WINBASEAPI سائز_T WINAPI Get_Large_صفحہ_Minimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD Firmware_جدول_Provider_Signature,PVOID p_Firmware_جدول_Enum_بفر,DWORD بفر_سائز);
  WINBASEAPI UINT WINAPI Get_System_Firmware_جدول(DWORD Firmware_جدول_Provider_Signature,DWORD Firmware_جدول_ID,PVOID p_Firmware_جدول_بفر,DWORD بفر_سائز);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lp_پتہ,سائز_T dw_سائز,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lp_پتہ,سائز_T dw_سائز,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI سائز_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lp_پتہ,PMEMORY_BASIC_INFORMATION lp_بفر,سائز_T dw_لمبائی);
  WINBASEAPI HANDLE WINAPI ڈھیر_Create(DWORD flOptions,سائز_T dw_Initial_سائز,سائز_T dw_زیادہ_سے_زیادہ_سائز);
  WINBASEAPI WINBOOL WINAPI ڈھیر_Destroy(HANDLE h_ڈھیر);
  WINBASEAPI LPVOID WINAPI ڈھیر_Alloc(HANDLE h_ڈھیر,DWORD dwFlags,سائز_T dw_بائٹیں);
  WINBASEAPI LPVOID WINAPI ڈھیر_Re_Alloc(HANDLE h_ڈھیر,DWORD dwFlags,LPVOID lpMem,سائز_T dw_بائٹیں);
  WINBASEAPI WINBOOL WINAPI ڈھیر_Free(HANDLE h_ڈھیر,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI سائز_T WINAPI ڈھیر_سائز_3(HANDLE h_ڈھیر,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI ڈھیر_Validate(HANDLE h_ڈھیر,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI سائز_T WINAPI ڈھیر_Compact(HANDLE h_ڈھیر,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI Get_Process_ڈھیر(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD نمبر_کا_Heaps,PHANDLE ProcessHeaps);

  قسمتعریف ساخت PROCESS_ڈھیر_اندراج {
    PVOID lp_ڈیٹا;
    DWORD cb_ڈیٹا;
    BYTE cbOverhead;
    BYTE i_Region_اشاریہ;
    لفظ_3 wFlags;
    اتحاد {
      ساخت {
	HANDLE hMem;
	DWORD dwReserved[3];
      } بلاک_2;
      ساخت {
	DWORD dw_Committed_سائز;
	DWORD dw_Un_Committed_سائز;
	LPVOID lp_پہلا_بلاک;
	LPVOID lp_آخری_بلاک;
      } Region;
    };
  } PROCESS_ڈھیر_اندراج_2,*LPPROCESS_ڈھیر_اندراج,*PPROCESS_ڈھیر_اندراج;

#تعریف_کرو PROCESS_ڈھیر_REGION 0x1
#تعریف_کرو PROCESS_ڈھیر_UNCOMMITTED_RANGE 0x2
#تعریف_کرو PROCESS_ڈھیر_اندراج_BUSY 0x4
#تعریف_کرو PROCESS_ڈھیر_اندراج_MOVEABLE 0x10
#تعریف_کرو PROCESS_ڈھیر_اندراج_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI ڈھیر_تالا(HANDLE h_ڈھیر);
  WINBASEAPI WINBOOL WINAPI ڈھیر_Unlock(HANDLE h_ڈھیر);
  WINBASEAPI WINBOOL WINAPI ڈھیر_Walk(HANDLE h_ڈھیر,LPPROCESS_ڈھیر_اندراج lp_اندراج);
  WINBASEAPI WINBOOL WINAPI ڈھیر_سیٹ_Information(HANDLE ڈھیر_Handle,ڈھیر_INFORMATION_CLASS ڈھیر_Information_Class,PVOID ڈھیر_Information,سائز_T ڈھیر_Information_لمبائی);
  WINBASEAPI WINBOOL WINAPI ڈھیر_Query_Information(HANDLE ڈھیر_Handle,ڈھیر_INFORMATION_CLASS ڈھیر_Information_Class,PVOID ڈھیر_Information,سائز_T ڈھیر_Information_لمبائی,PSIZE_T Return_لمبائی);

#تعریف_کرو SCS_32_ثنائی_ہندسہ_ثنائی 0
#تعریف_کرو SCS_DOS_ثنائی 1
#تعریف_کرو SCS_WOW_ثنائی 2
#تعریف_کرو SCS_PIF_ثنائی 3
#تعریف_کرو SCS_POSIX_ثنائی 4
#تعریف_کرو SCS_OS216_ثنائی 5
#تعریف_کرو SCS_64_ثنائی_ہندسہ_ثنائی 6

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو Get_ثنائی_Type Get_ثنائی_Type_W
#تعریف_کرو Get_Short_راستہ_Name Get_Short_راستہ_Name_W
#تعریف_کرو Get_Long_راستہ_Name Get_Long_راستہ_Name_W
#تعریف_کرو Get_Environment_لڑیاں Get_Environment_لڑیاں_W
#تعریف_کرو سیٹ_Environment_لڑیاں سیٹ_Environment_لڑیاں_W
#تعریف_کرو Free_Environment_لڑیاں Free_Environment_لڑیاں_W
#ورنہ
#تعریف_کرو Get_ثنائی_Type Get_ثنائی_Type_A
#تعریف_کرو Get_Short_راستہ_Name Get_Short_راستہ_Name_A
#تعریف_کرو Get_Long_راستہ_Name Get_Long_راستہ_Name_A
#تعریف_کرو Get_Environment_لڑیاں_A Get_Environment_لڑیاں
#تعریف_کرو سیٹ_Environment_لڑیاں سیٹ_Environment_لڑیاں_A
#تعریف_کرو Free_Environment_لڑیاں Free_Environment_لڑیاں_A
#اگر_ختم

#اگر_تعریف_شدہ _WIN64
#تعریف_کرو SCS_THIS_PLATFORM_ثنائی SCS_64_ثنائی_ہندسہ_ثنائی
#ورنہ
#تعریف_کرو SCS_THIS_PLATFORM_ثنائی SCS_32_ثنائی_ہندسہ_ثنائی
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI Get_ثنائی_Type_A(LPCSTR lpApplicationName,LPDWORD lp_ثنائی_Type);
  WINBASEAPI WINBOOL WINAPI Get_ثنائی_Type_W(LPCWSTR lpApplicationName,LPDWORD lp_ثنائی_Type);
  WINBASEAPI DWORD WINAPI Get_Short_راستہ_Name_A(LPCSTR lpsz_Long_راستہ,LPSTR lpsz_Short_راستہ,DWORD cch_بفر);
  WINBASEAPI DWORD WINAPI Get_Short_راستہ_Name_W(LPCWSTR lpsz_Long_راستہ,LPWSTR lpsz_Short_راستہ,DWORD cch_بفر);
  WINBASEAPI DWORD WINAPI Get_Long_راستہ_Name_A(LPCSTR lpsz_Short_راستہ,LPSTR lpsz_Long_راستہ,DWORD cch_بفر);
  WINBASEAPI DWORD WINAPI Get_Long_راستہ_Name_W(LPCWSTR lpsz_Short_راستہ,LPWSTR lpsz_Long_راستہ,DWORD cch_بفر);
  WINBASEAPI WINBOOL WINAPI Get_Process_Affinity_نقاب(HANDLE hProcess,PDWORD_PTR lp_Process_Affinity_نقاب,PDWORD_PTR lp_System_Affinity_نقاب);
  WINBASEAPI WINBOOL WINAPI سیٹ_Process_Affinity_نقاب(HANDLE hProcess,DWORD_PTR dw_Process_Affinity_نقاب);
  WINBASEAPI WINBOOL WINAPI Get_Process_Handle_گنتی(HANDLE hProcess,PDWORD pdw_Handle_گنتی);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lp_Creation_وقت,LPFILETIME lp_Exit_وقت,LPFILETIME lp_Kernel_وقت,LPFILETIME lp_User_وقت);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_سیٹ_سائز(HANDLE hProcess,PSIZE_T lp_Minimum_Working_سیٹ_سائز,PSIZE_T lp_زیادہ_سے_زیادہ_Working_سیٹ_سائز);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_سیٹ_سائز_Ex(HANDLE hProcess,PSIZE_T lp_Minimum_Working_سیٹ_سائز,PSIZE_T lp_زیادہ_سے_زیادہ_Working_سیٹ_سائز,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI سیٹ_Process_Working_سیٹ_سائز(HANDLE hProcess,سائز_T dw_Minimum_Working_سیٹ_سائز,سائز_T dw_زیادہ_سے_زیادہ_Working_سیٹ_سائز);
  WINBASEAPI WINBOOL WINAPI سیٹ_Process_Working_سیٹ_سائز_Ex(HANDLE hProcess,سائز_T dw_Minimum_Working_سیٹ_سائز,سائز_T dw_زیادہ_سے_زیادہ_Working_سیٹ_سائز,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT u_Exit_رمز);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT u_Exit_رمز);
  WINBASEAPI WINBOOL WINAPI Get_Exit_رمز_Process(HANDLE hProcess,LPDWORD lp_Exit_رمز);
  WINBASEAPI VOID WINAPI FatalExit(صحیح Exit_رمز);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI Get_Environment_لڑیاں_W(VOID);
  WINBASEAPI WINBOOL WINAPI سیٹ_Environment_لڑیاں_A(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI سیٹ_Environment_لڑیاں_W(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI Free_Environment_لڑیاں_A(LPCH);
  WINBASEAPI WINBOOL WINAPI Free_Environment_لڑیاں_W(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dw_Exception_رمز,DWORD dwExceptionFlags,DWORD n_نمبر_کا_Arguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(ساخت EXCEPTION_اشارے_2 *ExceptionInfo);

  قسمتعریف LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(ساخت EXCEPTION_اشارے_2 *ExceptionInfo);
  قسمتعریف PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI سیٹ_Unhandled_Exception_Filter(LPTOP_LEVEL_EXCEPTION_FILTER lp_چوٹی_Level_Exception_Filter);

#تعریف_کرو FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(سائز_T dw_ڈھیر_سائز,LPFIBER_آغاز_ROUTINE lp_آغاز_پتہ,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(سائز_T dw_ڈھیر_Commit_سائز,سائز_T dw_ڈھیر_Reserve_سائز,DWORD dwFlags,LPFIBER_آغاز_ROUTINE lp_آغاز_پتہ,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI Convert_Thread_مقصد_Fiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI Convert_Thread_مقصد_Fiber_Ex(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Convert_Fiber_مقصد_Thread(VOID);
  WINBASEAPI VOID WINAPI Switch_مقصد_Fiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI Switch_مقصد_Thread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_اوصاف lp_Thread_اوصاف,سائز_T dw_ڈھیر_سائز,LPTHREAD_آغاز_ROUTINE lp_آغاز_پتہ,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_اوصاف lp_Thread_اوصاف,سائز_T dw_ڈھیر_سائز,LPTHREAD_آغاز_ROUTINE lp_آغاز_پتہ,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI سیٹ_Thread_ڈھیر_Guarantee (PULONG ڈھیر_سائز_اندر_بائٹیں);
  WINBASEAPI DWORD WINAPI Get_Process_Id_کا_Thread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI Get_Current_Processor_نمبر(VOID);
  WINBASEAPI DWORD_PTR WINAPI سیٹ_Thread_Affinity_نقاب(HANDLE hThread,DWORD_PTR dw_Thread_Affinity_نقاب);
  WINBASEAPI DWORD WINAPI سیٹ_Thread_Ideal_Processor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI سیٹ_Process_ترجیح_Boost(HANDLE hProcess,WINBOOL b_Disable_ترجیح_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Process_ترجیح_Boost(HANDLE hProcess,PBOOL p_Disable_ترجیح_Boost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_وقت latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI سیٹ_Thread_ترجیح(HANDLE hThread,صحیح n_ترجیح);
  WINBASEAPI WINBOOL WINAPI سیٹ_Thread_ترجیح_Boost(HANDLE hThread,WINBOOL b_Disable_ترجیح_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Thread_ترجیح_Boost(HANDLE hThread,PBOOL p_Disable_ترجیح_Boost);
  WINBASEAPI صحیح WINAPI Get_Thread_ترجیح(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lp_Creation_وقت,LPFILETIME lp_Exit_وقت,LPFILETIME lp_Kernel_وقت,LPFILETIME lp_User_وقت);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dw_Exit_رمز);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dw_Exit_رمز);
  WINBASEAPI WINBOOL WINAPI Get_Exit_رمز_Thread(HANDLE hThread,LPDWORD lp_Exit_رمز);
  WINBASEAPI WINBOOL WINAPI Get_Thread_Selector_اندراج(HANDLE hThread,DWORD dwSelector,LPLDT_اندراج lp_Selector_اندراج);
  WINBASEAPI EXECUTION_STATE WINAPI سیٹ_Thread_Execution_State(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI Get_آخری_Error(VOID);
  WINBASEAPI VOID WINAPI سیٹ_آخری_Error(DWORD dw_Err_رمز);

#اگر_غیر_تعریف_شدہ RC_INVOKED
#اگر_تعریف_شدہ WINBASE_DECLARE_RESTORE_آخری_ERROR
  WINBASEAPI VOID WINAPI Restore_آخری_Error(DWORD dw_Err_رمز);

  قسمتعریف VOID (WINAPI *PRESTORE_آخری_ERROR)(DWORD);

#تعریف_کرو RESTORE_آخری_ERROR_NAME_A "RestoreLastError"
#تعریف_کرو RESTORE_آخری_ERROR_NAME_W L"RestoreLastError"
#تعریف_کرو RESTORE_آخری_ERROR_NAME متن_3("RestoreLastError")
#اگر_ختم
#اگر_ختم

#تعریف_کرو HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->اندرونی_2)!=حالت_PENDING)

  WINBASEAPI WINBOOL WINAPI Get_Overlapped_نتیجہ(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lp_نمبر_کا_بائٹیں_Transferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI Create_Io_Completion_پورٹ(HANDLE FileHandle,HANDLE Existing_Completion_پورٹ,ULONG_PTR Completion_کلید,DWORD نمبر_کا_Concurrent_دھاگے);
  WINBASEAPI WINBOOL WINAPI Get_Queued_Completion_حالت(HANDLE Completion_پورٹ,LPDWORD lp_نمبر_کا_بائٹیں_Transferred,PULONG_PTR lp_Completion_کلید,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI Post_Queued_Completion_حالت(HANDLE Completion_پورٹ,DWORD dw_نمبر_کا_بائٹیں_Transferred,ULONG_PTR dw_Completion_کلید,LPOVERLAPPED lpOverlapped);

#تعریف_کرو SEM_FAILCRITICALERRORS 0x1
#تعریف_کرو SEM_NOGPFAULTERRORBOX 0x2
#تعریف_کرو SEM_NOALIGNMENTFAULTEXCEPT 0x4
#تعریف_کرو SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI سیٹ_Error_منوال(UINT u_منوال);
  WINBASEAPI WINBOOL WINAPI Read_Process_حافظہ(HANDLE hProcess,LPCVOID lp_بنیاد_پتہ,LPVOID lp_بفر,سائز_T n_سائز,سائز_T *lp_نمبر_کا_بائٹیں_Read);
  WINBASEAPI WINBOOL WINAPI Write_Process_حافظہ(HANDLE hProcess,LPVOID lp_بنیاد_پتہ,LPCVOID lp_بفر,سائز_T n_سائز,سائز_T *lp_نمبر_کا_بائٹیں_Written);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI سیٹ_Thread_Context(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  قسمتعریف VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI قطار_User_APC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dw_ڈیٹا);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dw_Continue_حالت);
  WINBASEAPI WINBOOL WINAPI Debug_فعال_Process(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_فعال_Process_Stop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_سیٹ_Process_Kill_On_Exit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI Initialize_Critical_Section_And_Spin_گنتی(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_گنتی);
  WINBASEAPI DWORD WINAPI سیٹ_Critical_Section_Spin_گنتی(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_گنتی);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI سیٹ_Event(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG l_Release_گنتی,LPLONG lp_پچھلا_گنتی);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI Wait_For_مضرب_Objects(DWORD n_گنتی,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI بھرو_Resource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI Init_Atom_جدول(DWORD n_سائز);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI سیٹ_Handle_گنتی(UINT u_نمبر);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI تالا_File(HANDLE hFile,DWORD dw_File_انحراف_کم,DWORD dw_File_انحراف_بلند,DWORD n_نمبر_کا_بائٹیں_مقصد_تالا_کم,DWORD n_نمبر_کا_بائٹیں_مقصد_تالا_بلند);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dw_File_انحراف_کم,DWORD dw_File_انحراف_بلند,DWORD n_نمبر_کا_بائٹیں_مقصد_Unlock_کم,DWORD n_نمبر_کا_بائٹیں_مقصد_Unlock_بلند);
  WINBASEAPI WINBOOL WINAPI تالا_File_Ex(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD n_نمبر_کا_بائٹیں_مقصد_تالا_کم,DWORD n_نمبر_کا_بائٹیں_مقصد_تالا_بلند,LPOVERLAPPED lpOverlapped);

#تعریف_کرو LOCKFILE_FAIL_IMMEDIATELY 0x1
#تعریف_کرو LOCKFILE_EXCLUSIVE_تالا 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD n_نمبر_کا_بائٹیں_مقصد_Unlock_کم,DWORD n_نمبر_کا_بائٹیں_مقصد_Unlock_بلند,LPOVERLAPPED lpOverlapped);

  قسمتعریف ساخت _BY_HANDLE_FILE_INFORMATION {
    DWORD dw_File_اوصاف;
    FILETIME ft_Creation_وقت;
    FILETIME ft_آخری_Access_وقت;
    FILETIME ft_آخری_Write_وقت;
    DWORD dw_Volume_Serial_نمبر;
    DWORD n_File_سائز_بلند;
    DWORD n_File_سائز_کم;
    DWORD n_نمبر_کا_Links;
    DWORD n_File_اشاریہ_بلند;
    DWORD n_File_اشاریہ_کم;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو سیٹ_File_Short_Name سیٹ_File_Short_Name_W
#ورنہ
#تعریف_کرو سیٹ_File_Short_Name سیٹ_File_Short_Name_A
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI Get_File_سائز(HANDLE hFile,LPDWORD lp_File_سائز_بلند);
  WINBASEAPI WINBOOL WINAPI Get_File_سائز_Ex(HANDLE hFile,PLARGE_INTEGER lp_File_سائز);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI سیٹ_Std_Handle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lp_بفر,DWORD n_نمبر_کا_بائٹیں_مقصد_Write,LPDWORD lp_نمبر_کا_بائٹیں_Written,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lp_بفر,DWORD n_نمبر_کا_بائٹیں_مقصد_Read,LPDWORD lp_نمبر_کا_بائٹیں_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dw_Io_Control_رمز,LPVOID lp_اندر_بفر,DWORD n_اندر_بفر_سائز,LPVOID lp_برآمد_بفر,DWORD n_برآمد_بفر_سائز,LPDWORD lp_بائٹیں_Returned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI سیٹ_پیغام_انتظار_Indicator(HANDLE h_پیغام_Indicator,ULONG ul_پیغام_گنتی);
  WINBASEAPI WINBOOL WINAPI سیٹ_انتہا_کا_File(HANDLE hFile);
  WINBASEAPI DWORD WINAPI سیٹ_File_اشارہ_گر(HANDLE hFile,LONG l_فاصلہ_مقصد_Move,PLONG lp_فاصلہ_مقصد_Move_بلند,DWORD dw_Move_طریقہ);
  WINBASEAPI WINBOOL WINAPI سیٹ_File_اشارہ_گر_Ex(HANDLE hFile,LARGE_INTEGER li_فاصلہ_مقصد_Move,PLARGE_INTEGER lp_New_File_اشارہ_گر,DWORD dw_Move_طریقہ);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_Close(HANDLE h_ڈھونڈو_File);
  WINBASEAPI WINBOOL WINAPI Get_File_وقت(HANDLE hFile,LPFILETIME lp_Creation_وقت,LPFILETIME lp_آخری_Access_وقت,LPFILETIME lp_آخری_Write_وقت);
  WINBASEAPI WINBOOL WINAPI سیٹ_File_وقت(HANDLE hFile,CONST FILETIME *lp_Creation_وقت,CONST FILETIME *lp_آخری_Access_وقت,CONST FILETIME *lp_آخری_Write_وقت);
  WINBASEAPI WINBOOL WINAPI سیٹ_File_Valid_ڈیٹا(HANDLE hFile,LONGLONG Valid_ڈیٹا_لمبائی);
  WINBASEAPI WINBOOL WINAPI سیٹ_File_Short_Name_A(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI سیٹ_File_Short_Name_W(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE h_ماخذ_Process_Handle,HANDLE h_ماخذ_Handle,HANDLE h_ہدف_Process_Handle,LPHANDLE lp_ہدف_Handle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI سیٹ_Handle_Information(HANDLE hObject,DWORD dw_نقاب,DWORD dwFlags);

#تعریف_کرو HANDLE_FLAG_INHERIT 0x1
#تعریف_کرو HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#تعریف_کرو HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI بھرو_Module(LPCSTR lpModuleName,LPVOID lp_Parameter_بلاک);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lp_Cmd_سطر,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI تیاری_Comm(HANDLE hFile,DWORD dw_اندر_قطار,DWORD dw_برآمد_قطار);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdw_سائز);
  WINBASEAPI WINBOOL WINAPI Get_Comm_نقاب(HANDLE hFile,LPDWORD lp_Evt_نقاب);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI Get_Comm_Modem_حالت(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI سیٹ_Comm_Break(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI سیٹ_Comm_Config(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dw_سائز);
  WINBASEAPI WINBOOL WINAPI سیٹ_Comm_نقاب(HANDLE hFile,DWORD dw_Evt_نقاب);
  WINBASEAPI WINBOOL WINAPI سیٹ_Comm_State(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI سیٹ_Comm_Timeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,حرف cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lp_Evt_نقاب,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI سیٹ_فیتہ_Position(HANDLE hDevice,DWORD dw_Position_طریقہ,DWORD dw_تقسیم,DWORD dw_انحراف_کم,DWORD dw_انحراف_بلند,WINBOOL b_فوری);
  WINBASEAPI DWORD WINAPI Get_فیتہ_Position(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdw_تقسیم,LPDWORD lpdw_انحراف_کم,LPDWORD lpdw_انحراف_بلند);
  WINBASEAPI DWORD WINAPI Prepare_فیتہ(HANDLE hDevice,DWORD dwOperation,WINBOOL b_فوری);
  WINBASEAPI DWORD WINAPI Erase_فیتہ(HANDLE hDevice,DWORD dwEraseType,WINBOOL b_فوری);
  WINBASEAPI DWORD WINAPI Create_فیتہ_تقسیم(HANDLE hDevice,DWORD dw_تقسیم_طریقہ,DWORD dw_گنتی,DWORD dw_سائز);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dw_Tapemark_گنتی,WINBOOL b_فوری);
  WINBASEAPI DWORD WINAPI Get_فیتہ_حالت(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI Get_فیتہ_Parameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdw_سائز,LPVOID lp_فیتہ_Information);

#تعریف_کرو GET_فیتہ_MEDIA_INFORMATION 0
#تعریف_کرو GET_فیتہ_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI سیٹ_فیتہ_Parameters(HANDLE hDevice,DWORD dwOperation,LPVOID lp_فیتہ_Information);

#تعریف_کرو سیٹ_فیتہ_MEDIA_INFORMATION 0
#تعریف_کرو سیٹ_فیتہ_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI صحیح WINAPI MulDiv(صحیح n_نمبر,صحیح nNumerator,صحیح nDenominator);
  WINBASEAPI VOID WINAPI Get_System_وقت(LPSYSTEMTIME lp_System_وقت);
  WINBASEAPI VOID WINAPI Get_System_وقت_As_File_وقت(LPFILETIME lp_System_وقت_As_File_وقت);
  WINBASEAPI WINBOOL WINAPI سیٹ_System_وقت(CONST SYSTEMTIME *lp_System_وقت);
  WINBASEAPI VOID WINAPI Get_Local_وقت(LPSYSTEMTIME lp_System_وقت);
  WINBASEAPI WINBOOL WINAPI سیٹ_Local_وقت(CONST SYSTEMTIME *lp_System_وقت);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI سیٹ_System_File_Cache_سائز(سائز_T Minimum_File_Cache_سائز,سائز_T زیادہ_سے_زیادہ_File_Cache_سائز,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI Get_System_File_Cache_سائز(PSIZE_T lp_Minimum_File_Cache_سائز,PSIZE_T lp_زیادہ_سے_زیادہ_File_Cache_سائز,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdw_Quota_مستعمل);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lp_Idle_وقت,LPFILETIME lp_Kernel_وقت,LPFILETIME lp_User_وقت);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  قسمتعریف ساخت وقت_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } وقت_ZONE_INFORMATION_2,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو Format_پیغام Format_پیغام_W
#ورنہ
#تعریف_کرو Format_پیغام Format_پیغام_A
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI System_وقت_مقصد_Tz_Specific_Local_وقت(LPTIME_ZONE_INFORMATION lp_وقت_Zone_Information,LPSYSTEMTIME lp_Universal_وقت,LPSYSTEMTIME lp_Local_وقت);
  WINBASEAPI WINBOOL WINAPI Tz_Specific_Local_وقت_مقصد_System_وقت(LPTIME_ZONE_INFORMATION lp_وقت_Zone_Information,LPSYSTEMTIME lp_Local_وقت,LPSYSTEMTIME lp_Universal_وقت);
  WINBASEAPI DWORD WINAPI Get_وقت_Zone_Information(LPTIME_ZONE_INFORMATION lp_وقت_Zone_Information);
  WINBASEAPI WINBOOL WINAPI سیٹ_وقت_Zone_Information(CONST وقت_ZONE_INFORMATION_2 *lp_وقت_Zone_Information);
  WINBASEAPI WINBOOL WINAPI System_وقت_مقصد_File_وقت(CONST SYSTEMTIME *lp_System_وقت,LPFILETIME lp_File_وقت);
  WINBASEAPI WINBOOL WINAPI File_وقت_مقصد_Local_File_وقت(CONST FILETIME *lp_File_وقت,LPFILETIME lp_Local_File_وقت);
  WINBASEAPI WINBOOL WINAPI Local_File_وقت_مقصد_File_وقت(CONST FILETIME *lp_Local_File_وقت,LPFILETIME lp_File_وقت);
  WINBASEAPI WINBOOL WINAPI File_وقت_مقصد_System_وقت(CONST FILETIME *lp_File_وقت,LPSYSTEMTIME lp_System_وقت);
  WINBASEAPI LONG WINAPI Compare_File_وقت(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI File_وقت_مقصد_Dos_Date_وقت(CONST FILETIME *lp_File_وقت,LPWORD lpFatDate,LPWORD lp_Fat_وقت);
  WINBASEAPI WINBOOL WINAPI Dos_Date_وقت_مقصد_File_وقت(لفظ_3 wFatDate,لفظ_3 w_Fat_وقت,LPFILETIME lp_File_وقت);
  WINBASEAPI DWORD WINAPI Get_Tick_گنتی(VOID);
  WINBASEAPI WINBOOL WINAPI سیٹ_System_وقت_Adjustment(DWORD dw_وقت_Adjustment,WINBOOL b_وقت_Adjustment_Disabled);
  WINBASEAPI WINBOOL WINAPI Get_System_وقت_Adjustment(PDWORD lp_وقت_Adjustment,PDWORD lp_وقت_Increment,PBOOL lp_وقت_Adjustment_Disabled);
  WINBASEAPI DWORD WINAPI Format_پیغام_A(DWORD dwFlags,LPCVOID lp_ماخذ,DWORD dw_پیغام_Id,DWORD dwLanguageId,LPSTR lp_بفر,DWORD n_سائز,va_list *Arguments);
  WINBASEAPI DWORD WINAPI Format_پیغام_W(DWORD dwFlags,LPCVOID lp_ماخذ,DWORD dw_پیغام_Id,DWORD dwLanguageId,LPWSTR lp_بفر,DWORD n_سائز,va_list *Arguments);

#تعریف_کرو FORMAT_پیغام_ALLOCATE_بفر 0x100
#تعریف_کرو FORMAT_پیغام_IGNORE_INSERTS 0x200
#تعریف_کرو FORMAT_پیغام_FROM_STRING 0x400
#تعریف_کرو FORMAT_پیغام_FROM_HMODULE 0x800
#تعریف_کرو FORMAT_پیغام_FROM_SYSTEM 0x1000
#تعریف_کرو FORMAT_پیغام_دلیل_ARRAY 0x2000
#تعریف_کرو FORMAT_پیغام_MAX_چوڑائی_نقاب 0xff

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو CreateMailslot CreateMailslotW
#تعریف_کرو EncryptFile EncryptFileW
#تعریف_کرو DecryptFile DecryptFileW
#تعریف_کرو File_Encryption_حالت File_Encryption_حالت_W
#ورنہ
#تعریف_کرو CreateMailslot CreateMailslotA
#تعریف_کرو EncryptFile EncryptFileA
#تعریف_کرو DecryptFile DecryptFileA
#تعریف_کرو File_Encryption_حالت File_Encryption_حالت_A
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_اوصاف lp_Pipe_اوصاف,DWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI سیٹ_Named_Pipe_Handle_State(HANDLE hNamedPipe,LPDWORD lp_منوال,LPDWORD lp_Max_Collection_گنتی,LPDWORD lp_Collect_ڈیٹا_Timeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lp_برآمد_بفر_سائز,LPDWORD lp_اندر_بفر_سائز,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lp_بفر,DWORD n_بفر_سائز,LPDWORD lp_بائٹیں_Read,LPDWORD lp_کل_بائٹیں_Avail,LPDWORD lp_بائٹیں_بایاں_This_پیغام);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lp_اندر_بفر,DWORD n_اندر_بفر_سائز,LPVOID lp_برآمد_بفر,DWORD n_برآمد_بفر_سائز,LPDWORD lp_بائٹیں_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD n_Max_پیغام_سائز,DWORD lReadTimeout,LPSECURITY_اوصاف lp_Security_اوصاف);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD n_Max_پیغام_سائز,DWORD lReadTimeout,LPSECURITY_اوصاف lp_Security_اوصاف);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lp_Max_پیغام_سائز,LPDWORD lp_اگلا_سائز,LPDWORD lp_پیغام_گنتی,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI سیٹ_Mailslot_Info(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI Map_View_کا_File(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_انحراف_بلند,DWORD dw_File_انحراف_کم,سائز_T dw_نمبر_کا_بائٹیں_مقصد_Map);
  WINBASEAPI WINBOOL WINAPI Flush_View_کا_File(LPCVOID lp_بنیاد_پتہ,سائز_T dw_نمبر_کا_بائٹیں_مقصد_Flush);
  WINBASEAPI WINBOOL WINAPI Unmap_View_کا_File(LPCVOID lp_بنیاد_پتہ);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#تعریف_کرو FILE_ENCRYPTABLE 0
#تعریف_کرو FILE_IS_ENCRYPTED 1
#تعریف_کرو FILE_SYSTEM_ATTR 2
#تعریف_کرو FILE_جڑ_DIR 3
#تعریف_کرو FILE_SYSTEM_DIR 4
#تعریف_کرو FILE_UNKNOWN 5
#تعریف_کرو FILE_SYSTEM_NOT_SUPPORT 6
#تعریف_کرو FILE_USER_DISALLOWED 7
#تعریف_کرو FILE_READ_ONLY 8
#تعریف_کرو FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI File_Encryption_حالت_A(LPCSTR lpFileName,LPDWORD lp_حالت);
  WINADVAPI WINBOOL WINAPI File_Encryption_حالت_W(LPCWSTR lpFileName,LPDWORD lp_حالت);

#تعریف_کرو EFS_USE_RECOVERY_کلیدیں (0x1)

  قسمتعریف DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pb_ڈیٹا,PVOID pvCallbackContext,ULONG ul_لمبائی);
  قسمتعریف DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pb_ڈیٹا,PVOID pvCallbackContext,PULONG ul_لمبائی);

#تعریف_کرو CREATE_FOR_IMPORT (1)
#تعریف_کرو CREATE_FOR_DIR (2)
#تعریف_کرو OVERWRITE_HIDDEN (4)

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو OpenEncryptedFileRaw OpenEncryptedFileRawW
#تعریف_کرو lstrcmp lstrcmpW
#تعریف_کرو lstrcmpi lstrcmpiW
#تعریف_کرو lstrcpyn lstrcpynW
#تعریف_کرو lstrcpy lstrcpyW
#تعریف_کرو lstrcat lstrcatW
#تعریف_کرو lstrlen lstrlenW
#ورنہ
#تعریف_کرو OpenEncryptedFileRaw OpenEncryptedFileRawA
#تعریف_کرو lstrcmp lstrcmpA
#تعریف_کرو lstrcmpi lstrcmpiA
#تعریف_کرو lstrcpyn lstrcpynA
#تعریف_کرو lstrcpy lstrcpyA
#تعریف_کرو lstrcat lstrcatA
#تعریف_کرو lstrlen lstrlenA
#اگر_ختم

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI صحیح WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI صحیح WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI صحیح WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI صحیح WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,صحیح i_Max_لمبائی);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,صحیح i_Max_لمبائی);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI صحیح WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI صحیح WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lp_راستہ_Name,صحیح iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lp_راستہ_Name,صحیح iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lp_بفر,UINT u_بائٹیں);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lp_بفر,UINT u_بائٹیں);
  WINBASEAPI طویل WINAPI _hread(HFILE hFile,LPVOID lp_بفر,طویل l_بائٹیں);
  WINBASEAPI طویل WINAPI _hwrite(HFILE hFile,LPCCH lp_بفر,طویل l_بائٹیں);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG l_انحراف,صحیح iOrigin);
  WINADVAPI WINBOOL WINAPI Is_متن_Unicode(CONST VOID *lpv,صحیح i_سائز,LPINT lpi_نتیجہ);

#تعریف_کرو FLS_برآمد_کا_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI Fls_Get_قدر(DWORD dw_Fls_اشاریہ);
  WINBASEAPI WINBOOL WINAPI Fls_سیٹ_قدر(DWORD dw_Fls_اشاریہ,PVOID lp_Fls_ڈیٹا);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dw_Fls_اشاریہ);

#تعریف_کرو TLS_برآمد_کا_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI Tls_Get_قدر(DWORD dw_Tls_اشاریہ);
  WINBASEAPI WINBOOL WINAPI Tls_سیٹ_قدر(DWORD dw_Tls_اشاریہ,LPVOID lp_Tls_قدر);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dw_Tls_اشاریہ);

  قسمتعریف VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dw_Error_رمز,DWORD dw_نمبر_کا_بائٹیں_Transfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI Wait_For_مضرب_Objects_Ex(DWORD n_گنتی,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE h_Object_مقصد_Signal,HANDLE h_Object_مقصد_Wait_On,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lp_بفر,DWORD n_نمبر_کا_بائٹیں_مقصد_Read,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lp_بفر,DWORD n_نمبر_کا_بائٹیں_مقصد_Write,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lp_بفر,DWORD n_نمبر_کا_بائٹیں_مقصد_Read,LPDWORD lp_نمبر_کا_بائٹیں_Read,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dw_کم_بائٹیں_مقصد_Seek,DWORD dw_بلند_بائٹیں_مقصد_Seek,LPDWORD lpdw_کم_Byte_Seeked,LPDWORD lpdw_بلند_Byte_Seeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lp_بفر,DWORD n_نمبر_کا_بائٹیں_مقصد_Write,LPDWORD lp_نمبر_کا_بائٹیں_Written,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  قسمتعریف ساخت WIN32_دھارا_ID {
    DWORD dw_دھارا_Id;
    DWORD dw_دھارا_اوصاف;
    LARGE_INTEGER سائز_3;
    DWORD dw_دھارا_Name_سائز;
    WCHAR c_دھارا_Name[ANYSIZE_ARRAY];
  } WIN32_دھارا_ID_2,*LPWIN32_دھارا_ID;

#تعریف_کرو BACKUP_INVALID 0x0
#تعریف_کرو BACKUP_ڈیٹا 0x1
#تعریف_کرو BACKUP_EA_ڈیٹا 0x2
#تعریف_کرو BACKUP_SECURITY_ڈیٹا 0x3
#تعریف_کرو BACKUP_ALTERNATE_ڈیٹا 0x4
#تعریف_کرو BACKUP_LINK 0x5
#تعریف_کرو BACKUP_PROPERTY_ڈیٹا 0x6
#تعریف_کرو BACKUP_OBJECT_ID 0x7
#تعریف_کرو BACKUP_REPARSE_ڈیٹا 0x8
#تعریف_کرو BACKUP_SPARSE_بلاک 0x9

#تعریف_کرو دھارا_معمول_ATTRIBUTE 0x0
#تعریف_کرو دھارا_MODIFIED_WHEN_READ 0x1
#تعریف_کرو دھارا_شامل_ہے_SECURITY 0x2
#تعریف_کرو دھارا_شامل_ہے_PROPERTIES 0x4
#تعریف_کرو دھارا_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_نمبر_کا_بائٹیں_مقصد_Read,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_نمبر_کا_بائٹیں_مقصد_Write,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#تعریف_کرو STARTF_USESHOWWINDOW 0x1
#تعریف_کرو STARTF_USESIZE 0x2
#تعریف_کرو STARTF_USEPOSITION 0x4
#تعریف_کرو STARTF_USECOUNTCHARS 0x8
#تعریف_کرو STARTF_USEFILLATTRIBUTE 0x10
#تعریف_کرو STARTF_RUNFULLSCREEN 0x20
#تعریف_کرو STARTF_FORCEONFEEDBACK 0x40
#تعریف_کرو STARTF_FORCEOFFFEEDBACK 0x80
#تعریف_کرو STARTF_USESTDHANDLES 0x100

#تعریف_کرو STARTF_USEHOTKEY 0x200

  قسمتعریف ساخت _STARTUPINFOA {
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
    لفظ_3 w_Show_کھڑکی;
    لفظ_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_داخلہ;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOA,*LPSTARTUPINFOA;

  قسمتعریف ساخت _STARTUPINFOW {
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
    لفظ_3 w_Show_کھڑکی;
    لفظ_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_داخلہ;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف STARTUPINFOW STARTUPINFO;
  قسمتعریف LPSTARTUPINFOW LPSTARTUPINFO;
#ورنہ
  قسمتعریف STARTUPINFOA STARTUPINFO;
  قسمتعریف LPSTARTUPINFOA LPSTARTUPINFO;
#اگر_ختم

#تعریف_کرو SHUTDOWN_NORETRY 0x1

  قسمتعریف ساخت WIN32_ڈھونڈو_DATAA {
    DWORD dw_File_اوصاف;
    FILETIME ft_Creation_وقت;
    FILETIME ft_آخری_Access_وقت;
    FILETIME ft_آخری_Write_وقت;
    DWORD n_File_سائز_بلند;
    DWORD n_File_سائز_کم;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_راستہ];
    CHAR cAlternateFileName[14];
  } WIN32_ڈھونڈو_DATAA_2,*PWIN32_ڈھونڈو_DATAA,*LPWIN32_ڈھونڈو_DATAA;

  قسمتعریف ساخت WIN32_ڈھونڈو_DATAW {
    DWORD dw_File_اوصاف;
    FILETIME ft_Creation_وقت;
    FILETIME ft_آخری_Access_وقت;
    FILETIME ft_آخری_Write_وقت;
    DWORD n_File_سائز_بلند;
    DWORD n_File_سائز_کم;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_راستہ];
    WCHAR cAlternateFileName[14];
  } WIN32_ڈھونڈو_DATAW_2,*PWIN32_ڈھونڈو_DATAW,*LPWIN32_ڈھونڈو_DATAW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف WIN32_ڈھونڈو_DATAW_2 WIN32_ڈھونڈو_ڈیٹا;
  قسمتعریف PWIN32_ڈھونڈو_DATAW PWIN32_ڈھونڈو_ڈیٹا;
  قسمتعریف LPWIN32_ڈھونڈو_DATAW LPWIN32_ڈھونڈو_ڈیٹا;
#ورنہ
  قسمتعریف WIN32_ڈھونڈو_DATAA_2 WIN32_ڈھونڈو_ڈیٹا;
  قسمتعریف PWIN32_ڈھونڈو_DATAA PWIN32_ڈھونڈو_ڈیٹا;
  قسمتعریف LPWIN32_ڈھونڈو_DATAA LPWIN32_ڈھونڈو_ڈیٹا;
#اگر_ختم

  قسمتعریف ساخت WIN32_FILE_ATTRIBUTE_ڈیٹا {
    DWORD dw_File_اوصاف;
    FILETIME ft_Creation_وقت;
    FILETIME ft_آخری_Access_وقت;
    FILETIME ft_آخری_Write_وقت;
    DWORD n_File_سائز_بلند;
    DWORD n_File_سائز_کم;
  } WIN32_FILE_ATTRIBUTE_ڈیٹا_2,*LPWIN32_FILE_ATTRIBUTE_ڈیٹا;

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو CreateMutex CreateMutexW
#تعریف_کرو OpenMutex OpenMutexW
#تعریف_کرو CreateEvent CreateEventW
#تعریف_کرو OpenEvent OpenEventW
#تعریف_کرو CreateSemaphore CreateSemaphoreW
#تعریف_کرو OpenSemaphore OpenSemaphoreW
#ورنہ
#تعریف_کرو CreateMutex CreateMutexA
#تعریف_کرو OpenMutex OpenMutexA
#تعریف_کرو CreateEvent CreateEventA
#تعریف_کرو OpenEvent OpenEventA
#تعریف_کرو CreateSemaphore CreateSemaphoreA
#تعریف_کرو OpenSemaphore OpenSemaphoreA
#اگر_ختم

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_اوصاف lp_Mutex_اوصاف,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_اوصاف lp_Mutex_اوصاف,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_اوصاف lp_Event_اوصاف,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_اوصاف lp_Event_اوصاف,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_اوصاف lp_Semaphore_اوصاف,LONG l_Initial_گنتی,LONG l_زیادہ_سے_زیادہ_گنتی,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_اوصاف lp_Semaphore_اوصاف,LONG l_Initial_گنتی,LONG l_زیادہ_سے_زیادہ_گنتی,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  قسمتعریف VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lp_Arg_مقصد_Completion_Routine,DWORD dw_Timer_کم_قدر,DWORD dw_Timer_بلند_قدر);

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو CreateWaitableTimer CreateWaitableTimerW
#تعریف_کرو OpenWaitableTimer OpenWaitableTimerW
#تعریف_کرو CreateFileMapping CreateFileMappingW
#تعریف_کرو OpenFileMapping OpenFileMappingW
#تعریف_کرو Get_Logical_Drive_لڑیاں Get_Logical_Drive_لڑیاں_W
#تعریف_کرو بھرو_Library بھرو_Library_W
#تعریف_کرو بھرو_Library_Ex بھرو_Library_Ex_W
#تعریف_کرو GetModuleFileName GetModuleFileNameW
#تعریف_کرو GetModuleHandle GetModuleHandleW
#ورنہ
#تعریف_کرو CreateWaitableTimer CreateWaitableTimerA
#تعریف_کرو OpenWaitableTimer OpenWaitableTimerA
#تعریف_کرو CreateFileMapping CreateFileMappingA
#تعریف_کرو OpenFileMapping OpenFileMappingA
#تعریف_کرو Get_Logical_Drive_لڑیاں Get_Logical_Drive_لڑیاں_A
#تعریف_کرو بھرو_Library بھرو_Library_A
#تعریف_کرو بھرو_Library_Ex بھرو_Library_Ex_A
#تعریف_کرو GetModuleFileName GetModuleFileNameA
#تعریف_کرو GetModuleHandle GetModuleHandleA
#اگر_ختم

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_اوصاف lp_Timer_اوصاف,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_اوصاف lp_Timer_اوصاف,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI سیٹ_Waitable_Timer(HANDLE hTimer,ثابت LARGE_INTEGER *lp_Due_وقت,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lp_Arg_مقصد_Completion_Routine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_اوصاف lp_File_Mapping_اوصاف,DWORD flProtect,DWORD dw_زیادہ_سے_زیادہ_سائز_بلند,DWORD dw_زیادہ_سے_زیادہ_سائز_کم,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_اوصاف lp_File_Mapping_اوصاف,DWORD flProtect,DWORD dw_زیادہ_سے_زیادہ_سائز_بلند,DWORD dw_زیادہ_سے_زیادہ_سائز_کم,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_لڑیاں_A(DWORD n_بفر_لمبائی,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_لڑیاں_W(DWORD n_بفر_لمبائی,LPWSTR lp_بفر);

  قسمتعریف شمار حافظہ_RESOURCE_NOTIFICATION_TYPE {
    کم_حافظہ_Resource_Notification,بلند_حافظہ_Resource_Notification
  } حافظہ_RESOURCE_NOTIFICATION_TYPE_2;

  WINBASEAPI HANDLE WINAPI Create_حافظہ_Resource_Notification(حافظہ_RESOURCE_NOTIFICATION_TYPE_2 NotificationType);
  WINBASEAPI WINBOOL WINAPI Query_حافظہ_Resource_Notification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI بھرو_Library_A(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI بھرو_Library_W(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI بھرو_Library_Ex_A(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI بھرو_Library_Ex_W(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#تعریف_کرو DONT_RESOLVE_DLL_REFERENCES 0x1
#تعریف_کرو بھرو_LIBRARY_AS_DATAFILE 0x2
#تعریف_کرو بھرو_WITH_ALTERED_تلاش_راستہ 0x8
#تعریف_کرو بھرو_IGNORE_رمز_AUTHZ_LEVEL 0x10
#تعریف_کرو بھرو_LIBRARY_AS_IMAGE_RESOURCE 0x20
#تعریف_کرو بھرو_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40
#تعریف_کرو بھرو_LIBRARY_REQUIRE_SIGNED_ہدف 0x80
#تعریف_کرو بھرو_LIBRARY_تلاش_DLL_بھرو_DIR 0x100
#تعریف_کرو بھرو_LIBRARY_تلاش_APPLICATION_DIR 0x200
#تعریف_کرو بھرو_LIBRARY_تلاش_USER_DIRS 0x400
#تعریف_کرو بھرو_LIBRARY_تلاش_SYSTEM32 0x800
#تعریف_کرو بھرو_LIBRARY_تلاش_DEFAULT_DIRS 0x1000
#تعریف_کرو بھرو_LIBRARY_محفوظ_CURRENT_DIRS 0x2000

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD n_سائز);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD n_سائز);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#اگر_غیر_تعریف_شدہ RC_INVOKED
#تعریف_کرو GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#تعریف_کرو GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#تعریف_کرو GET_MODULE_HANDLE_EX_FLAG_FROM_پتہ (0x4)

  قسمتعریف WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  قسمتعریف WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#تعریف_کرو GetModuleHandleEx GetModuleHandleExW
#ورنہ
#تعریف_کرو PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#تعریف_کرو GetModuleHandleEx GetModuleHandleExA
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#اگر_ختم

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو Need_Current_Directory_For_Exe_راستہ Need_Current_Directory_For_Exe_راستہ_W
#تعریف_کرو CreateProcess CreateProcessW
#تعریف_کرو FatalAppExit FatalAppExitW
#تعریف_کرو GetStartupInfo GetStartupInfoW
#تعریف_کرو Get_Command_سطر Get_Command_سطر_W
#تعریف_کرو GetEnvironmentVariable GetEnvironmentVariableW
#تعریف_کرو سیٹ_Environment_Variable سیٹ_Environment_Variable_W
#تعریف_کرو Expand_Environment_لڑیاں Expand_Environment_لڑیاں_W
#تعریف_کرو GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#تعریف_کرو سیٹ_Firmware_Environment_Variable سیٹ_Firmware_Environment_Variable_W
#تعریف_کرو OutputDebugString OutputDebugStringW
#تعریف_کرو ڈھونڈو_Resource ڈھونڈو_Resource_W
#تعریف_کرو ڈھونڈو_Resource_Ex ڈھونڈو_Resource_Ex_W
#ورنہ
#تعریف_کرو Need_Current_Directory_For_Exe_راستہ Need_Current_Directory_For_Exe_راستہ_A
#تعریف_کرو CreateProcess CreateProcessA
#تعریف_کرو FatalAppExit FatalAppExitA
#تعریف_کرو GetStartupInfo GetStartupInfoA
#تعریف_کرو Get_Command_سطر Get_Command_سطر_A
#تعریف_کرو GetEnvironmentVariable GetEnvironmentVariableA
#تعریف_کرو سیٹ_Environment_Variable سیٹ_Environment_Variable_A
#تعریف_کرو Expand_Environment_لڑیاں Expand_Environment_لڑیاں_A
#تعریف_کرو GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#تعریف_کرو سیٹ_Firmware_Environment_Variable سیٹ_Firmware_Environment_Variable_A
#تعریف_کرو OutputDebugString OutputDebugStringA
#تعریف_کرو ڈھونڈو_Resource ڈھونڈو_Resource_A
#تعریف_کرو ڈھونڈو_Resource_Ex ڈھونڈو_Resource_Ex_A
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_راستہ_A(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_راستہ_W(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lp_Command_سطر,LPSECURITY_اوصاف lp_Process_اوصاف,LPSECURITY_اوصاف lp_Thread_اوصاف,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lp_Command_سطر,LPSECURITY_اوصاف lp_Process_اوصاف,LPSECURITY_اوصاف lp_Thread_اوصاف,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI جوڑو_Local_Alternate_Computer_Name_A(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI جوڑو_Local_Alternate_Computer_Name_W(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI سیٹ_Process_Shutdown_Parameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI Get_Process_نسخہ(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lp_پیغام_متن);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lp_پیغام_متن);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI Get_Command_سطر_A(VOID);
  WINBASEAPI LPWSTR WINAPI Get_Command_سطر_W(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lp_بفر,DWORD n_سائز);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lp_بفر,DWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI سیٹ_Environment_Variable_A(LPCSTR lpName,LPCSTR lp_قدر);
  WINBASEAPI WINBOOL WINAPI سیٹ_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lp_قدر);
  WINBASEAPI DWORD WINAPI Expand_Environment_لڑیاں_A(LPCSTR lpSrc,LPSTR lpDst,DWORD n_سائز);
  WINBASEAPI DWORD WINAPI Expand_Environment_لڑیاں_W(LPCWSTR lpSrc,LPWSTR lpDst,DWORD n_سائز);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_بفر,DWORD n_سائز);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_بفر,DWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI سیٹ_Firmware_Environment_Variable_A(LPCSTR lpName,LPCSTR lpGuid,PVOID p_قدر,DWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI سیٹ_Firmware_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_قدر,DWORD n_سائز);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI ڈھونڈو_Resource_A(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI ڈھونڈو_Resource_W(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI ڈھونڈو_Resource_Ex_A(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,لفظ_3 wLanguage);
  WINBASEAPI HRSRC WINAPI ڈھونڈو_Resource_Ex_W(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,لفظ_3 wLanguage);

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو ENUMRESTYPEPROC ENUMRESTYPEPROCW
#تعریف_کرو ENUMRESNAMEPROC ENUMRESNAMEPROCW
#تعریف_کرو ENUMRESLANGPROC ENUMRESLANGPROCW
#تعریف_کرو EnumResourceTypes EnumResourceTypesW
#تعریف_کرو Enum_Resource_نام Enum_Resource_نام_W
#تعریف_کرو EnumResourceLanguages EnumResourceLanguagesW
#تعریف_کرو BeginUpdateResource BeginUpdateResourceW
#تعریف_کرو UpdateResource UpdateResourceW
#تعریف_کرو انتہا_Update_Resource انتہا_Update_Resource_W
#تعریف_کرو Global_جوڑو_Atom Global_جوڑو_Atom_W
#تعریف_کرو Global_ڈھونڈو_Atom Global_ڈھونڈو_Atom_W
#تعریف_کرو GlobalGetAtomName GlobalGetAtomNameW
#تعریف_کرو جوڑو_Atom جوڑو_Atom_W
#تعریف_کرو ڈھونڈو_Atom ڈھونڈو_Atom_W
#تعریف_کرو GetAtomName GetAtomNameW
#تعریف_کرو GetProfileInt GetProfileIntW
#تعریف_کرو GetProfileString GetProfileStringW
#تعریف_کرو WriteProfileString WriteProfileStringW
#تعریف_کرو GetProfileSection GetProfileSectionW
#تعریف_کرو WriteProfileSection WriteProfileSectionW
#تعریف_کرو Get_نجی_Profile_Int Get_نجی_Profile_Int_W
#تعریف_کرو Get_نجی_Profile_String Get_نجی_Profile_String_W
#تعریف_کرو Write_نجی_Profile_String Write_نجی_Profile_String_W
#تعریف_کرو Get_نجی_Profile_Section Get_نجی_Profile_Section_W
#تعریف_کرو Write_نجی_Profile_Section Write_نجی_Profile_Section_W
#تعریف_کرو Get_نجی_Profile_Section_نام Get_نجی_Profile_Section_نام_W
#تعریف_کرو Get_نجی_Profile_Struct Get_نجی_Profile_Struct_W
#تعریف_کرو Write_نجی_Profile_Struct Write_نجی_Profile_Struct_W
#تعریف_کرو GetDriveType GetDriveTypeW
#تعریف_کرو GetSystemDirectory GetSystemDirectoryW
#تعریف_کرو Get_عارضی_راستہ Get_عارضی_راستہ_W
#تعریف_کرو Get_عارضی_File_Name Get_عارضی_File_Name_W
#تعریف_کرو GetWindowsDirectory GetWindowsDirectoryW
#تعریف_کرو GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#تعریف_کرو جوڑو_Local_Alternate_Computer_Name جوڑو_Local_Alternate_Computer_Name_W
#ورنہ
#تعریف_کرو ENUMRESTYPEPROC ENUMRESTYPEPROCA
#تعریف_کرو ENUMRESNAMEPROC ENUMRESNAMEPROCA
#تعریف_کرو ENUMRESLANGPROC ENUMRESLANGPROCA
#تعریف_کرو EnumResourceTypes EnumResourceTypesA
#تعریف_کرو Enum_Resource_نام Enum_Resource_نام_A
#تعریف_کرو EnumResourceLanguages EnumResourceLanguagesA
#تعریف_کرو BeginUpdateResource BeginUpdateResourceA
#تعریف_کرو UpdateResource UpdateResourceA
#تعریف_کرو انتہا_Update_Resource انتہا_Update_Resource_A
#تعریف_کرو Global_جوڑو_Atom Global_جوڑو_Atom_A
#تعریف_کرو Global_ڈھونڈو_Atom Global_ڈھونڈو_Atom_A
#تعریف_کرو GlobalGetAtomName GlobalGetAtomNameA
#تعریف_کرو جوڑو_Atom جوڑو_Atom_A
#تعریف_کرو ڈھونڈو_Atom ڈھونڈو_Atom_A
#تعریف_کرو GetAtomName GetAtomNameA
#تعریف_کرو GetProfileInt GetProfileIntA
#تعریف_کرو GetProfileString GetProfileStringA
#تعریف_کرو WriteProfileString WriteProfileStringA
#تعریف_کرو GetProfileSection GetProfileSectionA
#تعریف_کرو WriteProfileSection WriteProfileSectionA
#تعریف_کرو Get_نجی_Profile_Int Get_نجی_Profile_Int_A
#تعریف_کرو Get_نجی_Profile_String Get_نجی_Profile_String_A
#تعریف_کرو Write_نجی_Profile_String Write_نجی_Profile_String_A
#تعریف_کرو Get_نجی_Profile_Section Get_نجی_Profile_Section_A
#تعریف_کرو Write_نجی_Profile_Section Write_نجی_Profile_Section_A
#تعریف_کرو Get_نجی_Profile_Section_نام Get_نجی_Profile_Section_نام_A
#تعریف_کرو Get_نجی_Profile_Struct Get_نجی_Profile_Struct_A
#تعریف_کرو Write_نجی_Profile_Struct Write_نجی_Profile_Struct_A
#تعریف_کرو GetDriveType GetDriveTypeA
#تعریف_کرو GetSystemDirectory GetSystemDirectoryA
#تعریف_کرو Get_عارضی_راستہ Get_عارضی_راستہ_A
#تعریف_کرو Get_عارضی_File_Name Get_عارضی_File_Name_A
#تعریف_کرو GetWindowsDirectory GetWindowsDirectoryA
#تعریف_کرو GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#تعریف_کرو جوڑو_Local_Alternate_Computer_Name جوڑو_Local_Alternate_Computer_Name_A
#اگر_ختم

  قسمتعریف WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  قسمتعریف WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  قسمتعریف WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  قسمتعریف WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  قسمتعریف WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,لفظ_3 wLanguage,LONG_PTR lParam);
  قسمتعریف WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,لفظ_3 wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_نام_A(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_نام_W(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,لفظ_3 wLanguage,LPVOID lp_ڈیٹا,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,لفظ_3 wLanguage,LPVOID lp_ڈیٹا,DWORD cb);
  WINBASEAPI WINBOOL WINAPI انتہا_Update_Resource_A(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI انتہا_Update_Resource_W(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI Global_جوڑو_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_جوڑو_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ڈھونڈو_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_ڈھونڈو_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lp_بفر,صحیح n_سائز);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lp_بفر,صحیح n_سائز);
  WINBASEAPI ATOM WINAPI جوڑو_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI جوڑو_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI ڈھونڈو_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI ڈھونڈو_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lp_بفر,صحیح n_سائز);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lp_بفر,صحیح n_سائز);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lp_کلید_Name,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lp_کلید_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_سائز);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lp_کلید_Name,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_سائز);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI Get_نجی_Profile_Int_A(LPCSTR lpAppName,LPCSTR lp_کلید_Name,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI Get_نجی_Profile_Int_W(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_نجی_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_کلید_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_سائز,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_نجی_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_سائز,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_نجی_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_کلید_Name,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_نجی_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_کلید_Name,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_نجی_Profile_Section_A(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_سائز,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_نجی_Profile_Section_W(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_سائز,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_نجی_Profile_Section_A(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_نجی_Profile_Section_W(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_نجی_Profile_Section_نام_A(LPSTR lpsz_Return_بفر,DWORD n_سائز,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_نجی_Profile_Section_نام_W(LPWSTR lpsz_Return_بفر,DWORD n_سائز,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Get_نجی_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_کلید,LPVOID lpStruct,UINT u_سائز_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Get_نجی_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_کلید,LPVOID lpStruct,UINT u_سائز_Struct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_نجی_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_کلید,LPVOID lpStruct,UINT u_سائز_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_نجی_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_کلید,LPVOID lpStruct,UINT u_سائز_Struct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lp_جڑ_راستہ_Name);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lp_جڑ_راستہ_Name);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lp_بفر,UINT u_سائز);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lp_بفر,UINT u_سائز);
  WINBASEAPI DWORD WINAPI Get_عارضی_راستہ_A(DWORD n_بفر_لمبائی,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI Get_عارضی_راستہ_W(DWORD n_بفر_لمبائی,LPWSTR lp_بفر);
  WINBASEAPI UINT WINAPI Get_عارضی_File_Name_A(LPCSTR lp_راستہ_Name,LPCSTR lp_سابقہ_String,UINT uUnique,LPSTR lp_عارضی_File_Name);
  WINBASEAPI UINT WINAPI Get_عارضی_File_Name_W(LPCWSTR lp_راستہ_Name,LPCWSTR lp_سابقہ_String,UINT uUnique,LPWSTR lp_عارضی_File_Name);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lp_بفر,UINT u_سائز);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lp_بفر,UINT u_سائز);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lp_بفر,UINT u_سائز);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lp_بفر,UINT u_سائز);

#اگر_غیر_تعریف_شدہ RC_INVOKED
#اگر_تعریف_شدہ UNICODE
#تعریف_کرو GetSystemWow64Directory GetSystemWow64DirectoryW
#ورنہ
#تعریف_کرو GetSystemWow64Directory GetSystemWow64DirectoryA
#اگر_ختم

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lp_بفر,UINT u_سائز);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lp_بفر,UINT u_سائز);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *Old_قدر);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID Ol_قدر);

  قسمتعریف UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lp_بفر,UINT u_سائز);
  قسمتعریف UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lp_بفر,UINT u_سائز);

#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T متن_3("GetSystemWow64DirectoryA")
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T متن_3("GetSystemWow64DirectoryW")

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#ورنہ
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#تعریف_کرو GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#اگر_ختم
#اگر_ختم

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو سیٹ_Current_Directory سیٹ_Current_Directory_W
#تعریف_کرو GetCurrentDirectory GetCurrentDirectoryW
#تعریف_کرو سیٹ_Dll_Directory سیٹ_Dll_Directory_W
#تعریف_کرو GetDllDirectory GetDllDirectoryW
#تعریف_کرو GetDiskFreeSpace GetDiskFreeSpaceW
#تعریف_کرو GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#تعریف_کرو CreateDirectory CreateDirectoryW
#تعریف_کرو CreateDirectoryEx CreateDirectoryExW
#تعریف_کرو RemoveDirectory RemoveDirectoryW
#تعریف_کرو Get_بھرا_راستہ_Name Get_بھرا_راستہ_Name_W
#تعریف_کرو DefineDosDevice DefineDosDeviceW
#تعریف_کرو QueryDosDevice QueryDosDeviceW
#تعریف_کرو CreateFile CreateFileW
#تعریف_کرو سیٹ_File_اوصاف سیٹ_File_اوصاف_W
#تعریف_کرو Get_File_اوصاف Get_File_اوصاف_W
#ورنہ
#تعریف_کرو سیٹ_Current_Directory سیٹ_Current_Directory_A
#تعریف_کرو GetCurrentDirectory GetCurrentDirectoryA
#تعریف_کرو سیٹ_Dll_Directory سیٹ_Dll_Directory_A
#تعریف_کرو GetDllDirectory GetDllDirectoryA
#تعریف_کرو GetDiskFreeSpace GetDiskFreeSpaceA
#تعریف_کرو GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#تعریف_کرو CreateDirectory CreateDirectoryA
#تعریف_کرو CreateDirectoryEx CreateDirectoryExA
#تعریف_کرو RemoveDirectory RemoveDirectoryA
#تعریف_کرو Get_بھرا_راستہ_Name Get_بھرا_راستہ_Name_A
#تعریف_کرو DefineDosDevice DefineDosDeviceA
#تعریف_کرو QueryDosDevice QueryDosDeviceA
#تعریف_کرو CreateFile CreateFileA
#تعریف_کرو سیٹ_File_اوصاف سیٹ_File_اوصاف_A
#تعریف_کرو Get_File_اوصاف Get_File_اوصاف_A
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI سیٹ_Current_Directory_A(LPCSTR lp_راستہ_Name);
  WINBASEAPI WINBOOL WINAPI سیٹ_Current_Directory_W(LPCWSTR lp_راستہ_Name);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD n_بفر_لمبائی,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD n_بفر_لمبائی,LPWSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI سیٹ_Dll_Directory_A(LPCSTR lp_راستہ_Name);
  WINBASEAPI WINBOOL WINAPI سیٹ_Dll_Directory_W(LPCWSTR lp_راستہ_Name);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD n_بفر_لمبائی,LPSTR lp_بفر);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD n_بفر_لمبائی,LPWSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lp_جڑ_راستہ_Name,LPDWORD lp_Sectors_فی_Cluster,LPDWORD lp_بائٹیں_فی_Sector,LPDWORD lp_نمبر_کا_Free_Clusters,LPDWORD lp_کل_نمبر_کا_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lp_جڑ_راستہ_Name,LPDWORD lp_Sectors_فی_Cluster,LPDWORD lp_بائٹیں_فی_Sector,LPDWORD lp_نمبر_کا_Free_Clusters,LPDWORD lp_کل_نمبر_کا_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lp_Free_بائٹیں_دستیاب_مقصد_Caller,PULARGE_INTEGER lp_کل_نمبر_کا_بائٹیں,PULARGE_INTEGER lp_کل_نمبر_کا_Free_بائٹیں);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lp_Free_بائٹیں_دستیاب_مقصد_Caller,PULARGE_INTEGER lp_کل_نمبر_کا_بائٹیں,PULARGE_INTEGER lp_کل_نمبر_کا_Free_بائٹیں);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lp_راستہ_Name,LPSECURITY_اوصاف lp_Security_اوصاف);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lp_راستہ_Name,LPSECURITY_اوصاف lp_Security_اوصاف);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_اوصاف lp_Security_اوصاف);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_اوصاف lp_Security_اوصاف);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lp_راستہ_Name);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lp_راستہ_Name);
  WINBASEAPI DWORD WINAPI Get_بھرا_راستہ_Name_A(LPCSTR lpFileName,DWORD n_بفر_لمبائی,LPSTR lp_بفر,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI Get_بھرا_راستہ_Name_W(LPCWSTR lpFileName,DWORD n_بفر_لمبائی,LPWSTR lp_بفر,LPWSTR *lpFilePart);

#تعریف_کرو DDD_RAW_ہدف_راستہ 0x1
#تعریف_کرو DDD_REMOVE_DEFINITION 0x2
#تعریف_کرو DDD_EXACT_مطابقت_ON_REMOVE 0x4
#تعریف_کرو DDD_NO_نشر_SYSTEM 0x8
#تعریف_کرو DDD_LUID_نشر_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lp_ہدف_راستہ);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lp_ہدف_راستہ);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lp_ہدف_راستہ,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lp_ہدف_راستہ,DWORD ucchMax);

#تعریف_کرو EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_منوال,LPSECURITY_اوصاف lp_Security_اوصاف,DWORD dwCreationDisposition,DWORD dw_Flags_And_اوصاف,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_منوال,LPSECURITY_اوصاف lp_Security_اوصاف,DWORD dwCreationDisposition,DWORD dw_Flags_And_اوصاف,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dw_Share_منوال,DWORD dw_Flags_And_اوصاف);
  WINBASEAPI WINBOOL WINAPI سیٹ_File_اوصاف_A(LPCSTR lpFileName,DWORD dw_File_اوصاف);
  WINBASEAPI WINBOOL WINAPI سیٹ_File_اوصاف_W(LPCWSTR lpFileName,DWORD dw_File_اوصاف);
  WINBASEAPI DWORD WINAPI Get_File_اوصاف_A(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_File_اوصاف_W(LPCWSTR lpFileName);

  قسمتعریف شمار GET_FILEEX_INFO_سطحیں {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_سطحیں_2;

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو Get_File_اوصاف_Ex Get_File_اوصاف_Ex_W
#تعریف_کرو Get_Compressed_File_سائز Get_Compressed_File_سائز_W
#تعریف_کرو DeleteFile DeleteFileW
#تعریف_کرو CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#ورنہ
#تعریف_کرو Get_File_اوصاف_Ex Get_File_اوصاف_Ex_A
#تعریف_کرو Get_Compressed_File_سائز Get_Compressed_File_سائز_A
#تعریف_کرو DeleteFile DeleteFileA
#تعریف_کرو CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI Get_File_اوصاف_Ex_A(LPCSTR lpFileName,GET_FILEEX_INFO_سطحیں_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI Get_File_اوصاف_Ex_W(LPCWSTR lpFileName,GET_FILEEX_INFO_سطحیں_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_سائز_A(LPCSTR lpFileName,LPDWORD lp_File_سائز_بلند);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_سائز_W(LPCWSTR lpFileName,LPDWORD lp_File_سائز_بلند);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD Oem_Name_سائز,PBOOL pb_Name_شامل_ہے_Spaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD Oem_Name_سائز,PBOOL pb_Name_شامل_ہے_Spaces,PBOOL pbNameLegal);

  قسمتعریف شمار FINDEX_INFO_سطحیں {
    ڈھونڈو_Ex_Info_Standard,ڈھونڈو_Ex_Info_Max_Info_Level
  } FINDEX_INFO_سطحیں_2;

  قسمتعریف شمار FINDEX_تلاش_OPS {
    ڈھونڈو_Ex_تلاش_Name_مطابقت,ڈھونڈو_Ex_تلاش_حد_بندی_مقصد_Directories,ڈھونڈو_Ex_تلاش_حد_بندی_مقصد_Devices,ڈھونڈو_Ex_تلاش_Max_تلاش_Op
  } FINDEX_تلاش_OPS_2;

#تعریف_کرو ڈھونڈو_پہلا_EX_CASE_SENSITIVE 0x1

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو ڈھونڈو_پہلا_File_Ex ڈھونڈو_پہلا_File_Ex_W
#تعریف_کرو ڈھونڈو_پہلا_File ڈھونڈو_پہلا_File_W
#تعریف_کرو ڈھونڈو_اگلا_File ڈھونڈو_اگلا_File_W
#تعریف_کرو تلاش_راستہ تلاش_راستہ_W
#تعریف_کرو CopyFile CopyFileW
#تعریف_کرو CopyFileEx CopyFileExW
#تعریف_کرو MoveFile MoveFileW
#تعریف_کرو MoveFileEx MoveFileExW
#تعریف_کرو Move_File_With_پیش_رفت Move_File_With_پیش_رفت_W
#تعریف_کرو ReplaceFile ReplaceFileW
#تعریف_کرو CreateHardLink CreateHardLinkW
#تعریف_کرو CreateNamedPipe CreateNamedPipeW
#تعریف_کرو GetNamedPipeHandleState GetNamedPipeHandleStateW
#تعریف_کرو CallNamedPipe CallNamedPipeW
#تعریف_کرو WaitNamedPipe WaitNamedPipeW
#تعریف_کرو سیٹ_Volume_Label سیٹ_Volume_Label_W
#تعریف_کرو GetVolumeInformation GetVolumeInformationW
#تعریف_کرو ClearEventLog ClearEventLogW
#تعریف_کرو BackupEventLog BackupEventLogW
#تعریف_کرو OpenEventLog OpenEventLogW
#تعریف_کرو رجسٹر_Event_ماخذ رجسٹر_Event_ماخذ_W
#تعریف_کرو OpenBackupEventLog OpenBackupEventLogW
#تعریف_کرو ReadEventLog ReadEventLogW
#تعریف_کرو ReportEvent ReportEventW
#تعریف_کرو AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#تعریف_کرو AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#تعریف_کرو Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_W
#تعریف_کرو Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_By_Handle_W
#تعریف_کرو ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#تعریف_کرو ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#تعریف_کرو ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#تعریف_کرو ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#تعریف_کرو PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#تعریف_کرو سیٹ_File_Security سیٹ_File_Security_W
#تعریف_کرو GetFileSecurity GetFileSecurityW
#تعریف_کرو ڈھونڈو_پہلا_Change_Notification ڈھونڈو_پہلا_Change_Notification_W
#تعریف_کرو IsBadStringPtr IsBadStringPtrW
#تعریف_کرو LookupAccountSid LookupAccountSidW
#تعریف_کرو LookupAccountName LookupAccountNameW
#تعریف_کرو Lookup_Privilege_قدر Lookup_Privilege_قدر_W
#تعریف_کرو LookupPrivilegeName LookupPrivilegeNameW
#تعریف_کرو LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#تعریف_کرو BuildCommDCB BuildCommDCBW
#تعریف_کرو BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#تعریف_کرو CommConfigDialog CommConfigDialogW
#تعریف_کرو GetDefaultCommConfig GetDefaultCommConfigW
#تعریف_کرو سیٹ_Default_Comm_Config سیٹ_Default_Comm_Config_W
#تعریف_کرو GetComputerName GetComputerNameW
#تعریف_کرو سیٹ_Computer_Name سیٹ_Computer_Name_W
#تعریف_کرو GetComputerNameEx GetComputerNameExW
#تعریف_کرو سیٹ_Computer_Name_Ex سیٹ_Computer_Name_Ex_W
#تعریف_کرو Dns_Hostname_مقصد_Computer_Name Dns_Hostname_مقصد_Computer_Name_W
#تعریف_کرو GetUserName GetUserNameW
#ورنہ
#تعریف_کرو ڈھونڈو_پہلا_File_Ex ڈھونڈو_پہلا_File_Ex_A
#تعریف_کرو ڈھونڈو_پہلا_File ڈھونڈو_پہلا_File_A
#تعریف_کرو ڈھونڈو_اگلا_File ڈھونڈو_اگلا_File_A
#تعریف_کرو تلاش_راستہ تلاش_راستہ_A
#تعریف_کرو CopyFile CopyFileA
#تعریف_کرو CopyFileEx CopyFileExA
#تعریف_کرو MoveFile MoveFileA
#تعریف_کرو MoveFileEx MoveFileExA
#تعریف_کرو Move_File_With_پیش_رفت Move_File_With_پیش_رفت_A
#تعریف_کرو ReplaceFile ReplaceFileA
#تعریف_کرو CreateHardLink CreateHardLinkA
#تعریف_کرو CreateNamedPipe CreateNamedPipeA
#تعریف_کرو GetNamedPipeHandleState GetNamedPipeHandleStateA
#تعریف_کرو CallNamedPipe CallNamedPipeA
#تعریف_کرو WaitNamedPipe WaitNamedPipeA
#تعریف_کرو سیٹ_Volume_Label سیٹ_Volume_Label_A
#تعریف_کرو GetVolumeInformation GetVolumeInformationA
#تعریف_کرو ClearEventLog ClearEventLogA
#تعریف_کرو BackupEventLog BackupEventLogA
#تعریف_کرو OpenEventLog OpenEventLogA
#تعریف_کرو رجسٹر_Event_ماخذ رجسٹر_Event_ماخذ_A
#تعریف_کرو OpenBackupEventLog OpenBackupEventLogA
#تعریف_کرو ReadEventLog ReadEventLogA
#تعریف_کرو ReportEvent ReportEventA
#تعریف_کرو AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#تعریف_کرو AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#تعریف_کرو Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_A
#تعریف_کرو Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_By_Handle_A
#تعریف_کرو ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#تعریف_کرو ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#تعریف_کرو ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#تعریف_کرو ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#تعریف_کرو PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#تعریف_کرو سیٹ_File_Security سیٹ_File_Security_A
#تعریف_کرو GetFileSecurity GetFileSecurityA
#تعریف_کرو ڈھونڈو_پہلا_Change_Notification ڈھونڈو_پہلا_Change_Notification_A
#تعریف_کرو IsBadStringPtr IsBadStringPtrA
#تعریف_کرو LookupAccountSid LookupAccountSidA
#تعریف_کرو LookupAccountName LookupAccountNameA
#تعریف_کرو Lookup_Privilege_قدر Lookup_Privilege_قدر_A
#تعریف_کرو LookupPrivilegeName LookupPrivilegeNameA
#تعریف_کرو LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#تعریف_کرو BuildCommDCB BuildCommDCBA
#تعریف_کرو BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#تعریف_کرو CommConfigDialog CommConfigDialogA
#تعریف_کرو GetDefaultCommConfig GetDefaultCommConfigA
#تعریف_کرو سیٹ_Default_Comm_Config سیٹ_Default_Comm_Config_A
#تعریف_کرو GetComputerName GetComputerNameA
#تعریف_کرو سیٹ_Computer_Name سیٹ_Computer_Name_A
#تعریف_کرو GetComputerNameEx GetComputerNameExA
#تعریف_کرو سیٹ_Computer_Name_Ex سیٹ_Computer_Name_Ex_A
#تعریف_کرو Dns_Hostname_مقصد_Computer_Name Dns_Hostname_مقصد_Computer_Name_A
#تعریف_کرو GetUserName GetUserNameA
#اگر_ختم

  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_File_Ex_A(LPCSTR lpFileName,FINDEX_INFO_سطحیں_2 fInfoLevelId,LPVOID lp_ڈھونڈو_File_ڈیٹا,FINDEX_تلاش_OPS_2 f_تلاش_Op,LPVOID lp_تلاش_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_File_Ex_W(LPCWSTR lpFileName,FINDEX_INFO_سطحیں_2 fInfoLevelId,LPVOID lp_ڈھونڈو_File_ڈیٹا,FINDEX_تلاش_OPS_2 f_تلاش_Op,LPVOID lp_تلاش_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_File_A(LPCSTR lpFileName,LPWIN32_ڈھونڈو_DATAA lp_ڈھونڈو_File_ڈیٹا);
  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_File_W(LPCWSTR lpFileName,LPWIN32_ڈھونڈو_DATAW lp_ڈھونڈو_File_ڈیٹا);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_اگلا_File_A(HANDLE h_ڈھونڈو_File,LPWIN32_ڈھونڈو_DATAA lp_ڈھونڈو_File_ڈیٹا);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_اگلا_File_W(HANDLE h_ڈھونڈو_File,LPWIN32_ڈھونڈو_DATAW lp_ڈھونڈو_File_ڈیٹا);
  WINBASEAPI DWORD WINAPI تلاش_راستہ_A(LPCSTR lp_راستہ,LPCSTR lpFileName,LPCSTR lpExtension,DWORD n_بفر_لمبائی,LPSTR lp_بفر,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI تلاش_راستہ_W(LPCWSTR lp_راستہ,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD n_بفر_لمبائی,LPWSTR lp_بفر,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  قسمتعریف DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER کل_File_سائز,LARGE_INTEGER کل_بائٹیں_Transferred,LARGE_INTEGER دھارا_سائز,LARGE_INTEGER دھارا_بائٹیں_Transferred,DWORD dw_دھارا_نمبر,DWORD dwCallbackReason,HANDLE h_ماخذ_File,HANDLE hDestinationFile,LPVOID lp_ڈیٹا);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پیش_رفت_Routine,LPVOID lp_ڈیٹا,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پیش_رفت_Routine,LPVOID lp_ڈیٹا,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_پیش_رفت_A(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پیش_رفت_Routine,LPVOID lp_ڈیٹا,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_پیش_رفت_W(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_پیش_رفت_Routine,LPVOID lp_ڈیٹا,DWORD dwFlags);

#تعریف_کرو MOVEFILE_REPLACE_EXISTING 0x1
#تعریف_کرو MOVEFILE_COPY_ALLOWED 0x2
#تعریف_کرو MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#تعریف_کرو MOVEFILE_WRITE_THROUGH 0x8
#تعریف_کرو MOVEFILE_CREATE_HARDLINK 0x10
#تعریف_کرو MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_اوصاف lp_Security_اوصاف);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_اوصاف lp_Security_اوصاف);

  قسمتعریف شمار دھارا_INFO_سطحیں {
    ڈھونڈو_دھارا_Info_Standard,ڈھونڈو_دھارا_Info_Max_Info_Level
  } دھارا_INFO_سطحیں_2;

  قسمتعریف ساخت WIN32_ڈھونڈو_دھارا_ڈیٹا {
    LARGE_INTEGER دھارا_سائز;
    WCHAR c_دھارا_Name[MAX_راستہ + 36];
  } WIN32_ڈھونڈو_دھارا_ڈیٹا_2,*PWIN32_ڈھونڈو_دھارا_ڈیٹا;

  HANDLE WINAPI ڈھونڈو_پہلا_دھارا_W(LPCWSTR lpFileName,دھارا_INFO_سطحیں_2 InfoLevel,LPVOID lp_ڈھونڈو_دھارا_ڈیٹا,DWORD dwFlags);
  WINBOOL WINAPI ڈھونڈو_اگلا_دھارا_W(HANDLE h_ڈھونڈو_دھارا,LPVOID lp_ڈھونڈو_دھارا_ڈیٹا);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dw_Open_منوال,DWORD dw_Pipe_منوال,DWORD nMaxInstances,DWORD n_برآمد_بفر_سائز,DWORD n_اندر_بفر_سائز,DWORD n_Default_وقت_برآمد,LPSECURITY_اوصاف lp_Security_اوصاف);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dw_Open_منوال,DWORD dw_Pipe_منوال,DWORD nMaxInstances,DWORD n_برآمد_بفر_سائز,DWORD n_اندر_بفر_سائز,DWORD n_Default_وقت_برآمد,LPSECURITY_اوصاف lp_Security_اوصاف);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_گنتی,LPDWORD lp_Collect_ڈیٹا_Timeout,LPSTR lpUserName,DWORD n_Max_User_Name_سائز);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_گنتی,LPDWORD lp_Collect_ڈیٹا_Timeout,LPWSTR lpUserName,DWORD n_Max_User_Name_سائز);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lp_اندر_بفر,DWORD n_اندر_بفر_سائز,LPVOID lp_برآمد_بفر,DWORD n_برآمد_بفر_سائز,LPDWORD lp_بائٹیں_Read,DWORD n_وقت_برآمد);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lp_اندر_بفر,DWORD n_اندر_بفر_سائز,LPVOID lp_برآمد_بفر,DWORD n_برآمد_بفر_سائز,LPDWORD lp_بائٹیں_Read,DWORD n_وقت_برآمد);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD n_وقت_برآمد);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD n_وقت_برآمد);
  WINBASEAPI WINBOOL WINAPI سیٹ_Volume_Label_A(LPCSTR lp_جڑ_راستہ_Name,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI سیٹ_Volume_Label_W(LPCWSTR lp_جڑ_راستہ_Name,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI سیٹ_File_Apis_مقصد_OEM(VOID);
  WINBASEAPI VOID WINAPI سیٹ_File_Apis_مقصد_ANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lp_جڑ_راستہ_Name,LPSTR lp_Volume_Name_بفر,DWORD n_Volume_Name_سائز,LPDWORD lp_Volume_Serial_نمبر,LPDWORD lp_زیادہ_سے_زیادہ_Component_لمبائی,LPDWORD lpFileSystemFlags,LPSTR lp_File_System_Name_بفر,DWORD n_File_System_Name_سائز);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lp_جڑ_راستہ_Name,LPWSTR lp_Volume_Name_بفر,DWORD n_Volume_Name_سائز,LPDWORD lp_Volume_Serial_نمبر,LPDWORD lp_زیادہ_سے_زیادہ_Component_لمبائی,LPDWORD lpFileSystemFlags,LPWSTR lp_File_System_Name_بفر,DWORD n_File_System_Name_سائز);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI Deregister_Event_ماخذ(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI Get_نمبر_کا_Event_Log_اندراجات(HANDLE hEventLog,PDWORD نمبر_کا_اندراجات);
  WINADVAPI WINBOOL WINAPI Get_Oldest_Event_Log_ریکارڈ(HANDLE hEventLog,PDWORD Oldest_ریکارڈ);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lp_ماخذ_Name);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lp_ماخذ_Name);
  WINADVAPI HANDLE WINAPI رجسٹر_Event_ماخذ_A(LPCSTR lpUNCServerName,LPCSTR lp_ماخذ_Name);
  WINADVAPI HANDLE WINAPI رجسٹر_Event_ماخذ_W(LPCWSTR lpUNCServerName,LPCWSTR lp_ماخذ_Name);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_ریکارڈ_انحراف,LPVOID lp_بفر,DWORD n_نمبر_کا_بائٹیں_مقصد_Read,DWORD *pn_بائٹیں_Read,DWORD *pn_Min_نمبر_کا_بائٹیں_Needed);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_ریکارڈ_انحراف,LPVOID lp_بفر,DWORD n_نمبر_کا_بائٹیں_مقصد_Read,DWORD *pn_بائٹیں_Read,DWORD *pn_Min_نمبر_کا_بائٹیں_Needed);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,لفظ_3 wType,لفظ_3 wCategory,DWORD dwEventID,PSID lpUserSid,لفظ_3 w_عدد_لڑیاں,DWORD dw_ڈیٹا_سائز,LPCSTR *lp_لڑیاں,LPVOID lp_Raw_ڈیٹا);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,لفظ_3 wType,لفظ_3 wCategory,DWORD dwEventID,PSID lpUserSid,لفظ_3 w_عدد_لڑیاں,DWORD dw_ڈیٹا_سائز,LPCWSTR *lp_لڑیاں,LPVOID lp_Raw_ڈیٹا);

#تعریف_کرو EVENTLOG_بھرا_INFO 0

  قسمتعریف ساخت EVENTLOG_بھرا_INFORMATION {
    DWORD dw_بھرا;
  } EVENTLOG_بھرا_INFORMATION_2,*LPEVENTLOG_بھرا_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lp_بفر,DWORD cb_Buf_سائز,LPDWORD pcb_بائٹیں_Needed);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_لمبائی,LPDWORD lpn_لمبائی_Needed);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI Revert_مقصد_Self(VOID);
  WINADVAPI WINBOOL WINAPI سیٹ_Thread_Token (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_سیٹ Privilege_سیٹ,LPDWORD Privilege_سیٹ_لمبائی,LPDWORD GrantedAccess,LPBOOL Access_حالت);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_لمبائی,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_سیٹ Privilege_سیٹ,LPDWORD Privilege_سیٹ_لمبائی,LPDWORD GrantedAccess,LPBOOL Access_حالت);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجہ_List(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_لمبائی,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_سیٹ Privilege_سیٹ,LPDWORD Privilege_سیٹ_لمبائی,LPDWORD GrantedAccessList,LPDWORD Access_حالت_List);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_لمبائی,PDWORD Return_لمبائی);
  WINADVAPI WINBOOL WINAPI سیٹ_Token_Information(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_لمبائی);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD بفر_لمبائی,PTOKEN_PRIVILEGES پچھلا_State,PDWORD Return_لمبائی);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL Reset_مقصد_Default,PTOKEN_GROUPS NewState,DWORD بفر_لمبائی,PTOKEN_GROUPS پچھلا_State,PDWORD Return_لمبائی);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_سیٹ RequiredPrivileges,LPBOOL pf_نتیجہ);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_لمبائی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_لمبائی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_حالت,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_A(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_لمبائی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_W(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_لمبائی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_By_Handle_A(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_لمبائی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_نتیجہ_List_And_Audit_Alarm_By_Handle_W(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_لمبائی,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_حالت_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_سیٹ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_سیٹ Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_سیٹ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_سیٹ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_سیٹ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_سیٹ Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI Is_Well_معلوم_Sid(PSID pSid,WELL_معلوم_SID_TYPE Well_معلوم_Sid_Type);
  WINADVAPI WINBOOL WINAPI Create_Well_معلوم_Sid(WELL_معلوم_SID_TYPE Well_معلوم_Sid_Type,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI Equal_سابقہ_Sid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI Get_Sid_لمبائی_Required (UCHAR n_Sub_Authority_گنتی);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_گنتی,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_گنتی);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI Get_Sid_Sub_Authority_گنتی(PSID pSid);
  WINADVAPI DWORD WINAPI Get_لمبائی_Sid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD n_Destination_Sid_لمبائی,PSID pDestinationSid,PSID p_ماخذ_Sid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI Map_Generic_نقاب(PDWORD Access_نقاب,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD n_Acl_لمبائی,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_لمبائی,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI سیٹ_Acl_Information(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_لمبائی,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI جوڑو_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Starting_Ace_اشاریہ,LPVOID pAceList,DWORD n_Ace_List_لمبائی);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dw_Ace_اشاریہ);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dw_Ace_اشاریہ,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI جوڑو_Access_Allowed_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_نقاب,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڑو_Access_Allowed_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڑو_Access_Denied_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_نقاب,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڑو_Access_Denied_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڑو_Audit_Access_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Access_نقاب,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI جوڑو_Audit_Access_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dw_Access_نقاب,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI جوڑو_Access_Allowed_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڑو_Access_Denied_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI جوڑو_Audit_Access_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_نقاب,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI ڈھونڈو_پہلا_Free_Ace(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI Get_Security_Descriptor_لمبائی(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI سیٹ_Security_Descriptor_Control(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL Control_بٹ_کا_Interest,SECURITY_DESCRIPTOR_CONTROL Control_بٹ_مقصد_سیٹ);
  WINADVAPI WINBOOL WINAPI سیٹ_Security_Descriptor_Dacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI سیٹ_Security_Descriptor_Sacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI سیٹ_Security_Descriptor_Owner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI سیٹ_Security_Descriptor_گروہ(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID p_گروہ,WINBOOL b_گروہ_Defaulted);
  WINADVAPI WINBOOL WINAPI Get_Security_Descriptor_گروہ(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *p_گروہ,LPBOOL lpb_گروہ_Defaulted);
  WINADVAPI DWORD WINAPI سیٹ_Security_Descriptor_RMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI Create_نجی_Object_Security(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Convert_مقصد_Auto_Inherit_نجی_Object_Security(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_نجی_Object_Security_Ex(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_نجی_Object_Security_With_مضرب_Inheritance(PSECURITY_DESCRIPTOR والد_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG Guid_گنتی,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI سیٹ_نجی_Object_Security (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI سیٹ_نجی_Object_Security_Ex (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI Get_نجی_Object_Security(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD Descriptor_لمبائی,PDWORD Return_لمبائی);
  WINADVAPI WINBOOL WINAPI Destroy_نجی_Object_Security(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_بفر_لمبائی);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdw_Absolute_Security_Descriptor_سائز,PACL pDacl,LPDWORD lpdw_Dacl_سائز,PACL pSacl,LPDWORD lpdw_Sacl_سائز,PSID pOwner,LPDWORD lpdw_Owner_سائز,PSID p_Primary_گروہ,LPDWORD lpdw_Primary_گروہ_سائز);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_بفر_سائز);
  WINADVAPI WINBOOL WINAPI سیٹ_File_Security_A(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI سیٹ_File_Security_W(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_لمبائی,LPDWORD lpn_لمبائی_Needed);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_لمبائی,LPDWORD lpn_لمبائی_Needed);
  WINADVAPI WINBOOL WINAPI سیٹ_Kernel_Object_Security(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_Change_Notification_A(LPCSTR lp_راستہ_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_Change_Notification_W(LPCWSTR lp_راستہ_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_اگلا_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_Close_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lp_بفر,DWORD n_بفر_لمبائی,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lp_بائٹیں_Returned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI Virtual_تالا(LPVOID lp_پتہ,سائز_T dw_سائز);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lp_پتہ,سائز_T dw_سائز);
  WINBASEAPI LPVOID WINAPI Map_View_کا_File_Ex(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_انحراف_بلند,DWORD dw_File_انحراف_کم,سائز_T dw_نمبر_کا_بائٹیں_مقصد_Map,LPVOID lp_بنیاد_پتہ);
  WINBASEAPI WINBOOL WINAPI سیٹ_ترجیح_Class(HANDLE hProcess,DWORD dw_ترجیح_Class);
  WINBASEAPI DWORD WINAPI Get_ترجیح_Class(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI Is_Bad_رمز_Ptr(FARPROC lpfn);
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
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_سائز);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_سائز);
  WINBASEAPI WINBOOL WINAPI سیٹ_Default_Comm_Config_A(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_سائز);
  WINBASEAPI WINBOOL WINAPI سیٹ_Default_Comm_Config_W(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_سائز);

#تعریف_کرو MAX_COMPUTERNAME_لمبائی 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lp_بفر,LPDWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lp_بفر,LPDWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI سیٹ_Computer_Name_A(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI سیٹ_Computer_Name_W(LPCWSTR lpComputerName);

  قسمتعریف شمار _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lp_بفر,LPDWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lp_بفر,LPDWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI سیٹ_Computer_Name_Ex_A(COMPUTER_NAME_FORMAT NameType,LPCSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI سیٹ_Computer_Name_Ex_W(COMPUTER_NAME_FORMAT NameType,LPCWSTR lp_بفر);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_مقصد_Computer_Name_A(LPCSTR Hostname,LPSTR ComputerName,LPDWORD n_سائز);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_مقصد_Computer_Name_W(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD n_سائز);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lp_بفر,LPDWORD pcb_بفر);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lp_بفر,LPDWORD pcb_بفر);

#تعریف_کرو LOGON32_LOGON_INTERACTIVE 2
#تعریف_کرو LOGON32_LOGON_جال 3
#تعریف_کرو LOGON32_LOGON_BATCH 4
#تعریف_کرو LOGON32_LOGON_SERVICE 5
#تعریف_کرو LOGON32_LOGON_UNLOCK 7
#تعریف_کرو LOGON32_LOGON_جال_CLEARTEXT 8
#تعریف_کرو LOGON32_LOGON_NEW_CREDENTIALS 9

#تعریف_کرو LOGON32_PROVIDER_DEFAULT 0
#تعریف_کرو LOGON32_PROVIDER_WINNT35 1
#تعریف_کرو LOGON32_PROVIDER_WINNT40 2
#تعریف_کرو LOGON32_PROVIDER_WINNT50 3

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو LogonUser LogonUserW
#تعریف_کرو LogonUserEx LogonUserExW
#تعریف_کرو CreateProcessAsUser CreateProcessAsUserW
#ورنہ
#تعریف_کرو LogonUser LogonUserA
#تعریف_کرو LogonUserEx LogonUserExA
#تعریف_کرو CreateProcessAsUser CreateProcessAsUserA
#اگر_ختم

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_بفر,LPDWORD pdw_Profile_لمبائی,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_بفر,LPDWORD pdw_Profile_لمبائی,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lp_Command_سطر,LPSECURITY_اوصاف lp_Process_اوصاف,LPSECURITY_اوصاف lp_Thread_اوصاف,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lp_Command_سطر,LPSECURITY_اوصاف lp_Process_اوصاف,LPSECURITY_اوصاف lp_Thread_اوصاف,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#تعریف_کرو LOGON_WITH_PROFILE 0x1
#تعریف_کرو LOGON_NETCREDENTIALS_ONLY 0x2
#تعریف_کرو LOGON_ZERO_PASSWORD_بفر 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_سطر,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_سطر,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_اوصاف lp_Token_اوصاف,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD Disable_Sid_گنتی,PSID_AND_اوصاف Sids_مقصد_Disable,DWORD Delete_Privilege_گنتی,PLUID_AND_اوصاف Privileges_مقصد_Delete,DWORD Restricted_Sid_گنتی,PSID_AND_اوصاف Sids_مقصد_Restrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID Sid_مقصد_Check,PBOOL IsMember);

  قسمتعریف WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI رجسٹر_Wait_For_Single_Object(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI رجسٹر_Wait_For_Single_Object_Ex(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI قطار_User_Work_شے(LPTHREAD_آغاز_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI Create_Timer_قطار(VOID);
  WINBASEAPI WINBOOL WINAPI Create_Timer_قطار_Timer(PHANDLE phNewTimer,HANDLE Timer_قطار,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_وقت,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI Change_Timer_قطار_Timer(HANDLE Timer_قطار,HANDLE Timer,ULONG Due_وقت,ULONG Period);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_قطار_Timer(HANDLE Timer_قطار,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_قطار_Ex(HANDLE Timer_قطار,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI سیٹ_Timer_قطار_Timer(HANDLE Timer_قطار,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_وقت,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI Cancel_Timer_قطار_Timer(HANDLE Timer_قطار,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_قطار(HANDLE Timer_قطار);

#تعریف_کرو HW_PROFILE_GUIDLEN 39
#تعریف_کرو MAX_PROFILE_LEN 80

#تعریف_کرو DOCKINFO_UNDOCKED (0x1)
#تعریف_کرو DOCKINFO_DOCKED (0x2)
#تعریف_کرو DOCKINFO_USER_SUPPLIED (0x4)
#تعریف_کرو DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#تعریف_کرو DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  قسمتعریف ساخت لیبل_HW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  قسمتعریف ساخت لیبل_HW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف HW_PROFILE_INFOW HW_PROFILE_INFO;
  قسمتعریف LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#ورنہ
  قسمتعریف HW_PROFILE_INFOA HW_PROFILE_INFO;
  قسمتعریف LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#اگر_ختم

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو GetCurrentHwProfile GetCurrentHwProfileW
#تعریف_کرو Get_نسخہ_Ex Get_نسخہ_Ex_W
#تعریف_کرو Verify_نسخہ_Info Verify_نسخہ_Info_W
#ورنہ
#تعریف_کرو GetCurrentHwProfile GetCurrentHwProfileA
#تعریف_کرو Get_نسخہ_Ex Get_نسخہ_Ex_A
#تعریف_کرو Verify_نسخہ_Info Verify_نسخہ_Info_A
#اگر_ختم

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI Query_Performance_شمار(LARGE_INTEGER *lp_Performance_گنتی);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI Get_نسخہ_Ex_A(LPOSVERSIONINFOA lp_نسخہ_Information);
  WINBASEAPI WINBOOL WINAPI Get_نسخہ_Ex_W(LPOSVERSIONINFOW lp_نسخہ_Information);
  WINBASEAPI WINBOOL WINAPI Verify_نسخہ_Info_A(LPOSVERSIONINFOEXA lp_نسخہ_Information,DWORD dw_Type_نقاب,DWORDLONG dwl_Condition_نقاب);
  WINBASEAPI WINBOOL WINAPI Verify_نسخہ_Info_W(LPOSVERSIONINFOEXW lp_نسخہ_Information,DWORD dw_Type_نقاب,DWORDLONG dwl_Condition_نقاب);

#شامل <winerror.h>

#تعریف_کرو TC_معمول 0
#تعریف_کرو TC_HARDERR 1
#تعریف_کرو TC_GP_TRAP 2
#تعریف_کرو TC_SIGNAL 3

#تعریف_کرو AC_سطر_OFFLINE 0x0
#تعریف_کرو AC_سطر_ONLINE 0x1
#تعریف_کرو AC_سطر_BACKUP_POWER 0x2
#تعریف_کرو AC_سطر_UNKNOWN 0xff

#تعریف_کرو BATTERY_FLAG_بلند 0x1
#تعریف_کرو BATTERY_FLAG_کم 0x2
#تعریف_کرو BATTERY_FLAG_CRITICAL 0x4
#تعریف_کرو BATTERY_FLAG_CHARGING 0x8
#تعریف_کرو BATTERY_FLAG_NO_BATTERY 0x80
#تعریف_کرو BATTERY_FLAG_UNKNOWN 0xff

#تعریف_کرو BATTERY_PERCENTAGE_UNKNOWN 0xff

#تعریف_کرو BATTERY_LIFE_UNKNOWN 0xffffffff

  قسمتعریف ساخت SYSTEM_POWER_حالت {
    BYTE ACLine_حالت;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD Battery_Life_وقت;
    DWORD Battery_بھرا_Life_وقت;
  } SYSTEM_POWER_حالت_2,*LPSYSTEM_POWER_حالت;

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو Create_کام_Object Create_کام_Object_W
#تعریف_کرو Open_کام_Object Open_کام_Object_W
#تعریف_کرو ڈھونڈو_پہلا_Volume ڈھونڈو_پہلا_Volume_W
#تعریف_کرو ڈھونڈو_اگلا_Volume ڈھونڈو_اگلا_Volume_W
#تعریف_کرو ڈھونڈو_پہلا_Volume_Mount_نقطہ ڈھونڈو_پہلا_Volume_Mount_نقطہ_W
#تعریف_کرو ڈھونڈو_اگلا_Volume_Mount_نقطہ ڈھونڈو_اگلا_Volume_Mount_نقطہ_W
#تعریف_کرو سیٹ_Volume_Mount_نقطہ سیٹ_Volume_Mount_نقطہ_W
#تعریف_کرو Delete_Volume_Mount_نقطہ Delete_Volume_Mount_نقطہ_W
#تعریف_کرو Get_Volume_Name_For_Volume_Mount_نقطہ Get_Volume_Name_For_Volume_Mount_نقطہ_W
#تعریف_کرو Get_Volume_راستہ_Name Get_Volume_راستہ_Name_W
#تعریف_کرو Get_Volume_راستہ_نام_For_Volume_Name Get_Volume_راستہ_نام_For_Volume_Name_W
#ورنہ
#تعریف_کرو Create_کام_Object Create_کام_Object_A
#تعریف_کرو Open_کام_Object Open_کام_Object_A
#تعریف_کرو ڈھونڈو_پہلا_Volume ڈھونڈو_پہلا_Volume_A
#تعریف_کرو ڈھونڈو_اگلا_Volume ڈھونڈو_اگلا_Volume_A
#تعریف_کرو ڈھونڈو_پہلا_Volume_Mount_نقطہ ڈھونڈو_پہلا_Volume_Mount_نقطہ_A
#تعریف_کرو ڈھونڈو_اگلا_Volume_Mount_نقطہ ڈھونڈو_اگلا_Volume_Mount_نقطہ_A
#تعریف_کرو سیٹ_Volume_Mount_نقطہ سیٹ_Volume_Mount_نقطہ_A
#تعریف_کرو Delete_Volume_Mount_نقطہ Delete_Volume_Mount_نقطہ_A
#تعریف_کرو Get_Volume_Name_For_Volume_Mount_نقطہ Get_Volume_Name_For_Volume_Mount_نقطہ_A
#تعریف_کرو Get_Volume_راستہ_Name Get_Volume_راستہ_Name_A
#تعریف_کرو Get_Volume_راستہ_نام_For_Volume_Name Get_Volume_راستہ_نام_For_Volume_Name_A
#اگر_ختم

  WINBOOL WINAPI Get_System_Power_حالت(LPSYSTEM_POWER_حالت lp_System_Power_حالت);
  WINBOOL WINAPI سیٹ_System_Power_State(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI Allocate_User_Physical_صفحات(HANDLE hProcess,PULONG_PTR نمبر_کا_صفحات,PULONG_PTR صفحہ_Array);
  WINBASEAPI WINBOOL WINAPI Free_User_Physical_صفحات(HANDLE hProcess,PULONG_PTR نمبر_کا_صفحات,PULONG_PTR صفحہ_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_صفحات(PVOID Virtual_پتہ,ULONG_PTR نمبر_کا_صفحات,PULONG_PTR صفحہ_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_صفحات_Scatter(PVOID *Virtual_پتے,ULONG_PTR نمبر_کا_صفحات,PULONG_PTR صفحہ_Array);
  WINBASEAPI HANDLE WINAPI Create_کام_Object_A(LPSECURITY_اوصاف lp_کام_اوصاف,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Create_کام_Object_W(LPSECURITY_اوصاف lp_کام_اوصاف,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_کام_Object_A(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_کام_Object_W(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI تفویض_Process_مقصد_کام_Object(HANDLE h_کام,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI Terminate_کام_Object(HANDLE h_کام,UINT u_Exit_رمز);
  WINBASEAPI WINBOOL WINAPI Query_Information_کام_Object(HANDLE h_کام,JOBOBJECTINFOCLASS کام_Object_Information_Class,LPVOID lp_کام_Object_Information,DWORD cb_کام_Object_Information_لمبائی,LPDWORD lp_Return_لمبائی);
  WINBASEAPI WINBOOL WINAPI سیٹ_Information_کام_Object(HANDLE h_کام,JOBOBJECTINFOCLASS کام_Object_Information_Class,LPVOID lp_کام_Object_Information,DWORD cb_کام_Object_Information_لمبائی);
  WINBASEAPI WINBOOL WINAPI Is_Process_اندر_کام(HANDLE ProcessHandle,HANDLE کام_Handle,PBOOL نتیجہ_3);
  WINBASEAPI WINBOOL WINAPI Create_کام_سیٹ(ULONG عدد_کام,PJOB_سیٹ_ARRAY User_کام_سیٹ,ULONG Flags);
  WINBASEAPI PVOID WINAPI جوڑو_Vectored_Exception_Handler (ULONG پہلا_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI جوڑو_Vectored_Continue_Handler (ULONG پہلا_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_Volume_A(LPSTR lpszVolumeName,DWORD cch_بفر_لمبائی);
  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_Volume_W(LPWSTR lpszVolumeName,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_اگلا_Volume_A(HANDLE h_ڈھونڈو_Volume,LPSTR lpszVolumeName,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_اگلا_Volume_W(HANDLE h_ڈھونڈو_Volume,LPWSTR lpszVolumeName,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_Volume_Close(HANDLE h_ڈھونڈو_Volume);
  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_Volume_Mount_نقطہ_A(LPCSTR lpsz_جڑ_راستہ_Name,LPSTR lpsz_Volume_Mount_نقطہ,DWORD cch_بفر_لمبائی);
  WINBASEAPI HANDLE WINAPI ڈھونڈو_پہلا_Volume_Mount_نقطہ_W(LPCWSTR lpsz_جڑ_راستہ_Name,LPWSTR lpsz_Volume_Mount_نقطہ,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_اگلا_Volume_Mount_نقطہ_A(HANDLE h_ڈھونڈو_Volume_Mount_نقطہ,LPSTR lpsz_Volume_Mount_نقطہ,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_اگلا_Volume_Mount_نقطہ_W(HANDLE h_ڈھونڈو_Volume_Mount_نقطہ,LPWSTR lpsz_Volume_Mount_نقطہ,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_Volume_Mount_نقطہ_Close(HANDLE h_ڈھونڈو_Volume_Mount_نقطہ);
  WINBASEAPI WINBOOL WINAPI سیٹ_Volume_Mount_نقطہ_A(LPCSTR lpsz_Volume_Mount_نقطہ,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI سیٹ_Volume_Mount_نقطہ_W(LPCWSTR lpsz_Volume_Mount_نقطہ,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_نقطہ_A(LPCSTR lpsz_Volume_Mount_نقطہ);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_نقطہ_W(LPCWSTR lpsz_Volume_Mount_نقطہ);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_نقطہ_A(LPCSTR lpsz_Volume_Mount_نقطہ,LPSTR lpszVolumeName,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_نقطہ_W(LPCWSTR lpsz_Volume_Mount_نقطہ,LPWSTR lpszVolumeName,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_راستہ_Name_A(LPCSTR lpszFileName,LPSTR lpsz_Volume_راستہ_Name,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_راستہ_Name_W(LPCWSTR lpszFileName,LPWSTR lpsz_Volume_راستہ_Name,DWORD cch_بفر_لمبائی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_راستہ_نام_For_Volume_Name_A(LPCSTR lpszVolumeName,LPCH lpsz_Volume_راستہ_نام,DWORD cch_بفر_لمبائی,PDWORD lpcch_Return_لمبائی);
  WINBASEAPI WINBOOL WINAPI Get_Volume_راستہ_نام_For_Volume_Name_W(LPCWSTR lpszVolumeName,LPWCH lpsz_Volume_راستہ_نام,DWORD cch_بفر_لمبائی,PDWORD lpcch_Return_لمبائی);

#تعریف_کرو ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#تعریف_کرو ACTCTX_FLAG_LANGID_VALID 0x2
#تعریف_کرو ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#تعریف_کرو ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#تعریف_کرو ACTCTX_FLAG_سیٹ_PROCESS_DEFAULT 0x10
#تعریف_کرو ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#تعریف_کرو ACTCTX_FLAG_ماخذ_IS_ASSEMBLYREF 0x40
#تعریف_کرو ACTCTX_FLAG_HMODULE_VALID 0x80

  قسمتعریف ساخت لیبل_ACTCTXA {
    ULONG cb_سائز;
    DWORD dwFlags;
    LPCSTR lp_ماخذ;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  قسمتعریف ساخت لیبل_ACTCTXW {
    ULONG cb_سائز;
    DWORD dwFlags;
    LPCWSTR lp_ماخذ;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  قسمتعریف ثابت ACTCTXA *PCACTCTXA;
  قسمتعریف ثابت ACTCTXW *PCACTCTXW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف ACTCTXW ACTCTX;
  قسمتعریف PACTCTXW PACTCTX;
  قسمتعریف PCACTCTXW PCACTCTX;
#ورنہ
  قسمتعریف ACTCTXA ACTCTX;
  قسمتعریف PACTCTXA PACTCTX;
  قسمتعریف PCACTCTXA PCACTCTX;
#اگر_ختم

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو CreateActCtx CreateActCtxW
#ورنہ
#تعریف_کرو CreateActCtx CreateActCtxA
#اگر_ختم

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI جوڑو_Ref_Act_Ctx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#تعریف_کرو DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  قسمتعریف ساخت لیبل_ACTCTX_SECTION_KEYED_ڈیٹا_2600 {
    ULONG cb_سائز;
    ULONG ul_ڈیٹا_Format_نسخہ;
    PVOID lp_ڈیٹا;
    ULONG ul_لمبائی;
    PVOID lp_Section_Global_ڈیٹا;
    ULONG ul_Section_Global_ڈیٹا_لمبائی;
    PVOID lp_Section_بنیاد;
    ULONG ul_Section_کل_لمبائی;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_اشاریہ;
  } ACTCTX_SECTION_KEYED_ڈیٹا_2600,*PACTCTX_SECTION_KEYED_ڈیٹا_2600;

  قسمتعریف ثابت ACTCTX_SECTION_KEYED_ڈیٹا_2600 *PCACTCTX_SECTION_KEYED_ڈیٹا_2600;

  قسمتعریف ساخت لیبل_ACTCTX_SECTION_KEYED_ڈیٹا_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lp_Section_بنیاد;
    ULONG ul_Section_لمبائی;
    PVOID lp_Section_Global_ڈیٹا_بنیاد;
    ULONG ul_Section_Global_ڈیٹا_لمبائی;
  } ACTCTX_SECTION_KEYED_ڈیٹا_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_ڈیٹا_ASSEMBLY_METADATA;

  قسمتعریف ثابت ACTCTX_SECTION_KEYED_ڈیٹا_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_ڈیٹا_ASSEMBLY_METADATA;

  قسمتعریف ساخت لیبل_ACTCTX_SECTION_KEYED_ڈیٹا {
    ULONG cb_سائز;
    ULONG ul_ڈیٹا_Format_نسخہ;
    PVOID lp_ڈیٹا;
    ULONG ul_لمبائی;
    PVOID lp_Section_Global_ڈیٹا;
    ULONG ul_Section_Global_ڈیٹا_لمبائی;
    PVOID lp_Section_بنیاد;
    ULONG ul_Section_کل_لمبائی;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_اشاریہ;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_ڈیٹا_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_ڈیٹا,*PACTCTX_SECTION_KEYED_ڈیٹا;

  قسمتعریف ثابت ACTCTX_SECTION_KEYED_ڈیٹا *PCACTCTX_SECTION_KEYED_ڈیٹا;

#تعریف_کرو ڈھونڈو_ACTCTX_SECTION_کلید_RETURN_HACTCTX 0x1
#تعریف_کرو ڈھونڈو_ACTCTX_SECTION_کلید_RETURN_FLAGS 0x2
#تعریف_کرو ڈھونڈو_ACTCTX_SECTION_کلید_RETURN_ASSEMBLY_METADATA 0x4

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو ڈھونڈو_Act_Ctx_Section_String ڈھونڈو_Act_Ctx_Section_String_W
#ورنہ
#تعریف_کرو ڈھونڈو_Act_Ctx_Section_String ڈھونڈو_Act_Ctx_Section_String_A
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI ڈھونڈو_Act_Ctx_Section_String_A(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lp_String_مقصد_ڈھونڈو,PACTCTX_SECTION_KEYED_ڈیٹا Returned_ڈیٹا);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_Act_Ctx_Section_String_W(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lp_String_مقصد_ڈھونڈو,PACTCTX_SECTION_KEYED_ڈیٹا Returned_ڈیٹا);
  WINBASEAPI WINBOOL WINAPI ڈھونڈو_Act_Ctx_Section_Guid(DWORD dwFlags,ثابت GUID *lpExtensionGuid,ULONG ulSectionId,ثابت GUID *lp_Guid_مقصد_ڈھونڈو,PACTCTX_SECTION_KEYED_ڈیٹا Returned_ڈیٹا);

#اگر_غیر_تعریف_شدہ RC_INVOKED
#اگر_غیر_تعریف_شدہ ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  قسمتعریف ساخت _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  قسمتعریف ثابت ساخت _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#تعریف_کرو ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#اگر_ختم
#اگر_ختم

#تعریف_کرو QUERY_ACTCTX_FLAG_USE_فعال_ACTCTX 0x4
#تعریف_کرو QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#تعریف_کرو QUERY_ACTCTX_FLAG_ACTCTX_IS_پتہ 0x10
#تعریف_کرو QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_بفر,سائز_T cb_بفر,سائز_T *pcbWrittenOrRequired);

  قسمتعریف WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_بفر,سائز_T cb_بفر,سائز_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI Process_Id_مقصد_Session_Id(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGet_فعال_Console_Session_Id();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION بفر_3,PDWORD Returned_لمبائی);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Highest_گرہ_نمبر(PULONG Highest_گرہ_نمبر);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Processor_گرہ(UCHAR Processor,PUCHAR گرہ_نمبر);
  WINBASEAPI WINBOOL WINAPI Get_Numa_گرہ_Processor_نقاب(UCHAR گرہ_2,PULONGLONG Processor_نقاب);
  WINBASEAPI WINBOOL WINAPI Get_Numa_دستیاب_حافظہ_گرہ(UCHAR گرہ_2,PULONGLONG دستیاب_بائٹیں);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
