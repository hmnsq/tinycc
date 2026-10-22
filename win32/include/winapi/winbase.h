/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _WINBASE_
#నిర్వచించు _WINBASE_

#నిర్వచించు WINADVAPI DECLSPEC_IMPORT
#నిర్వచించు WINBASEAPI DECLSPEC_IMPORT
#నిర్వచించు ZAWPROXYAPI DECLSPEC_IMPORT

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచించు Define_Handle_పట్టిక(w) ((w),TRUE)
#నిర్వచించు హద్దు_Ems_పుటలు(dw)
#నిర్వచించు సమితి_మార్పిడి_Area_కొలత(w) (w)
#నిర్వచించు తాళం_Segment(w) GlobalFix((HANDLE)(w))
#నిర్వచించు UnlockSegment(w) GlobalUnfix((HANDLE)(w))
#నిర్వచించు Get_Current_సమయం() Get_Tick_లెక్క()

#నిర్వచించు Yield()

#నిర్వచించు INVALID_HANDLE_విలువ ((HANDLE)(LONG_PTR)-1)
#నిర్వచించు INVALID_FILE_కొలత ((DWORD)0xffffffff)
#నిర్వచించు INVALID_సమితి_FILE_సూచిక ((DWORD)-1)
#నిర్వచించు INVALID_FILE_లక్షణాలు ((DWORD)-1)

#నిర్వచించు FILE_BEGIN 0
#నిర్వచించు FILE_CURRENT 1
#నిర్వచించు FILE_చివర 2

#నిర్వచించు సమయం_ZONE_ID_INVALID ((DWORD)0xffffffff)

#నిర్వచించు WAIT_FAILED ((DWORD)0xffffffff)
#నిర్వచించు WAIT_OBJECT_0 ((స్థితి_WAIT_0) + 0)
#నిర్వచించు WAIT_ABANDONED ((స్థితి_ABANDONED_WAIT_0) + 0)
#నిర్వచించు WAIT_ABANDONED_0 ((స్థితి_ABANDONED_WAIT_0) + 0)
#నిర్వచించు WAIT_IO_COMPLETION స్థితి_USER_APC
#నిర్వచించు STILL_చురుకైన స్థితి_PENDING
#నిర్వచించు EXCEPTION_ACCESS_VIOLATION స్థితి_ACCESS_VIOLATION
#నిర్వచించు EXCEPTION_DATATYPE_MISALIGNMENT స్థితి_DATATYPE_MISALIGNMENT
#నిర్వచించు EXCEPTION_BREAKPOINT స్థితి_BREAKPOINT
#నిర్వచించు EXCEPTION_SINGLE_అడుగు స్థితి_SINGLE_అడుగు
#నిర్వచించు EXCEPTION_ARRAY_BOUNDS_EXCEEDED స్థితి_ARRAY_BOUNDS_EXCEEDED
#నిర్వచించు EXCEPTION_FLT_DENORMAL_నిర్వాహ్యం స్థితి_FLOAT_DENORMAL_నిర్వాహ్యం
#నిర్వచించు EXCEPTION_FLT_DIVIDE_BY_ZERO స్థితి_FLOAT_DIVIDE_BY_ZERO
#నిర్వచించు EXCEPTION_FLT_INEXACT_ఫలితం స్థితి_FLOAT_INEXACT_ఫలితం
#నిర్వచించు EXCEPTION_FLT_INVALID_OPERATION స్థితి_FLOAT_INVALID_OPERATION
#నిర్వచించు EXCEPTION_FLT_అధికప్రవాహం స్థితి_FLOAT_అధికప్రవాహం
#నిర్వచించు EXCEPTION_FLT_దొంతర_CHECK స్థితి_FLOAT_దొంతర_CHECK
#నిర్వచించు EXCEPTION_FLT_UNDERFLOW స్థితి_FLOAT_UNDERFLOW
#నిర్వచించు EXCEPTION_INT_DIVIDE_BY_ZERO స్థితి_INTEGER_DIVIDE_BY_ZERO
#నిర్వచించు EXCEPTION_INT_అధికప్రవాహం స్థితి_INTEGER_అధికప్రవాహం
#నిర్వచించు EXCEPTION_PRIV_INSTRUCTION స్థితి_PRIVILEGED_INSTRUCTION
#నిర్వచించు EXCEPTION_లోపల_పుట_ERROR స్థితి_లోపల_పుట_ERROR
#నిర్వచించు EXCEPTION_ILLEGAL_INSTRUCTION స్థితి_ILLEGAL_INSTRUCTION
#నిర్వచించు EXCEPTION_NONCONTINUABLE_EXCEPTION స్థితి_NONCONTINUABLE_EXCEPTION
#నిర్వచించు EXCEPTION_దొంతర_అధికప్రవాహం స్థితి_దొంతర_అధికప్రవాహం
#నిర్వచించు EXCEPTION_INVALID_DISPOSITION స్థితి_INVALID_DISPOSITION
#నిర్వచించు EXCEPTION_GUARD_పుట స్థితి_GUARD_పుట_VIOLATION
#నిర్వచించు EXCEPTION_INVALID_HANDLE స్థితి_INVALID_HANDLE
#నిర్వచించు EXCEPTION_POSSIBLE_DEADLOCK స్థితి_POSSIBLE_DEADLOCK
#నిర్వచించు CONTROL_C_EXIT స్థితి_CONTROL_C_EXIT
#నిర్వచించు Move_జ్ఞాపకం Rtl_Move_జ్ఞాపకం
#నిర్వచించు Copy_జ్ఞాపకం Rtl_Copy_జ్ఞాపకం
#నిర్వచించు Fill_జ్ఞాపకం Rtl_Fill_జ్ఞాపకం
#నిర్వచించు Zero_జ్ఞాపకం Rtl_Zero_జ్ఞాపకం
#నిర్వచించు Secure_Zero_జ్ఞాపకం Rtl_Secure_Zero_జ్ఞాపకం

#నిర్వచించు FILE_FLAG_WRITE_THROUGH 0x80000000
#నిర్వచించు FILE_FLAG_OVERLAPPED 0x40000000
#నిర్వచించు FILE_FLAG_NO_BUFFERING 0x20000000
#నిర్వచించు FILE_FLAG_RANDOM_ACCESS 0x10000000
#నిర్వచించు FILE_FLAG_SEQUENTIAL_పరిశీలన 0x8000000
#నిర్వచించు FILE_FLAG_DELETE_ON_CLOSE 0x4000000
#నిర్వచించు FILE_FLAG_BACKUP_SEMANTICS 0x2000000
#నిర్వచించు FILE_FLAG_POSIX_SEMANTICS 0x1000000
#నిర్వచించు FILE_FLAG_OPEN_REPARSE_బిందువు 0x200000
#నిర్వచించు FILE_FLAG_OPEN_NO_RECALL 0x100000
#నిర్వచించు FILE_FLAG_మొదటి_PIPE_INSTANCE 0x80000

#నిర్వచించు CREATE_NEW 1
#నిర్వచించు CREATE_ALWAYS 2
#నిర్వచించు OPEN_EXISTING 3
#నిర్వచించు OPEN_ALWAYS 4
#నిర్వచించు TRUNCATE_EXISTING 5

#నిర్వచించు పురోగతి_CONTINUE 0
#నిర్వచించు పురోగతి_CANCEL 1
#నిర్వచించు పురోగతి_STOP 2
#నిర్వచించు పురోగతి_QUIET 3

#నిర్వచించు CALLBACK_CHUNK_ముగిసిన 0x0
#నిర్వచించు CALLBACK_ప్రవాహం_SWITCH 0x1

#నిర్వచించు COPY_FILE_FAIL_IF_EXISTS 0x1
#నిర్వచించు COPY_FILE_RESTARTABLE 0x2
#నిర్వచించు COPY_FILE_OPEN_ఆధారం_FOR_WRITE 0x4
#నిర్వచించు COPY_FILE_ALLOW_DECRYPTED_DESTINATION 0x8

#నిర్వచించు REPLACEFILE_WRITE_THROUGH 0x1
#నిర్వచించు REPLACEFILE_IGNORE_విలీనం_ERRORS 0x2

#నిర్వచించు PIPE_ACCESS_INBOUND 0x1
#నిర్వచించు PIPE_ACCESS_OUTBOUND 0x2
#నిర్వచించు PIPE_ACCESS_DUPLEX 0x3

#నిర్వచించు PIPE_CLIENT_చివర 0x0
#నిర్వచించు PIPE_SERVER_చివర 0x1

#నిర్వచించు PIPE_WAIT 0x0
#నిర్వచించు PIPE_NOWAIT 0x1
#నిర్వచించు PIPE_READMODE_BYTE 0x0
#నిర్వచించు PIPE_READMODE_సందేశం 0x2
#నిర్వచించు PIPE_TYPE_BYTE 0x0
#నిర్వచించు PIPE_TYPE_సందేశం 0x4

#నిర్వచించు PIPE_UNLIMITED_INSTANCES 255

#నిర్వచించు SECURITY_ANONYMOUS (SecurityAnonymous << 16)
#నిర్వచించు SECURITY_IDENTIFICATION (SecurityIdentification << 16)
#నిర్వచించు SECURITY_IMPERSONATION (SecurityImpersonation << 16)
#నిర్వచించు SECURITY_DELEGATION (SecurityDelegation << 16)

#నిర్వచించు SECURITY_CONTEXT_TRACKING 0x40000
#నిర్వచించు SECURITY_EFFECTIVE_ONLY 0x80000

#నిర్వచించు SECURITY_SQOS_PRESENT 0x100000
#నిర్వచించు SECURITY_VALID_SQOS_FLAGS 0x1f0000

  రకనిర్వచనం నిర్మాణం _OVERLAPPED {
    ULONG_PTR అంతర్గత;
    ULONG_PTR అంతర్గత_ఎగువ;
    సంఘం {
      నిర్మాణం {
	DWORD స్థానభ్రంశం_3;
	DWORD స్థానభ్రంశం_ఎగువ_2;
      };
      PVOID సూచిక_3;
    };
    HANDLE hEvent;
  } OVERLAPPED,*LPOVERLAPPED;

  రకనిర్వచనం నిర్మాణం SECURITY_లక్షణాలు {
    DWORD n_నిడివి;
    LPVOID lpSecurityDescriptor;
    WINBOOL bInheritHandle;
  } SECURITY_లక్షణాలు_2,*PSECURITY_లక్షణాలు,*LPSECURITY_లక్షణాలు;

  రకనిర్వచనం నిర్మాణం _PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
  } PROCESS_INFORMATION,*PPROCESS_INFORMATION,*LPPROCESS_INFORMATION;

#నిర్వచితం_కాకపోతే _FILETIME_
#నిర్వచించు _FILETIME_
  రకనిర్వచనం నిర్మాణం _FILETIME {
    DWORD dw_దిగువ_Date_సమయం;
    DWORD dw_ఎగువ_Date_సమయం;
  } FILETIME,*PFILETIME,*LPFILETIME;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం _SYSTEMTIME {
    మాట_3 wYear;
    మాట_3 wMonth;
    మాట_3 w_Day_యొక్క_Week;
    మాట_3 wDay;
    మాట_3 wHour;
    మాట_3 wMinute;
    మాట_3 w_రెండవ;
    మాట_3 wMilliseconds;
  } SYSTEMTIME,*PSYSTEMTIME,*LPSYSTEMTIME;

  రకనిర్వచనం DWORD (WINAPI *PTHREAD_ప్రారంభం_ROUTINE)(LPVOID lpThreadParameter);
  రకనిర్వచనం PTHREAD_ప్రారంభం_ROUTINE LPTHREAD_ప్రారంభం_ROUTINE;
  రకనిర్వచనం VOID (WINAPI *PFIBER_ప్రారంభం_ROUTINE)(LPVOID lpFiberParameter);
  రకనిర్వచనం PFIBER_ప్రారంభం_ROUTINE LPFIBER_ప్రారంభం_ROUTINE;

  రకనిర్వచనం RTL_CRITICAL_SECTION CRITICAL_SECTION;
  రకనిర్వచనం PRTL_CRITICAL_SECTION PCRITICAL_SECTION;
  రకనిర్వచనం PRTL_CRITICAL_SECTION LPCRITICAL_SECTION;
  రకనిర్వచనం RTL_CRITICAL_SECTION_DEBUG CRITICAL_SECTION_DEBUG;
  రకనిర్వచనం PRTL_CRITICAL_SECTION_DEBUG PCRITICAL_SECTION_DEBUG;
  రకనిర్వచనం PRTL_CRITICAL_SECTION_DEBUG LPCRITICAL_SECTION_DEBUG;

  WINBASEAPI PVOID WINAPI Encode_సూచిక(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_సూచిక(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Encode_System_సూచిక(PVOID Ptr);
  WINBASEAPI PVOID WINAPI Decode_System_సూచిక(PVOID Ptr);

#నిర్వచితమైతే I_X86_
  రకనిర్వచనం PLDT_నమోదు LPLDT_నమోదు;
#లేకపోతే
  రకనిర్వచనం LPVOID LPLDT_నమోదు;
#అయితే_ముగింపు

#నిర్వచించు MUTEX_MODIFY_STATE MUTANT_QUERY_STATE
#నిర్వచించు MUTEX_ALL_ACCESS MUTANT_ALL_ACCESS

#నిర్వచించు SP_SERIALCOMM ((DWORD)0x1)

#నిర్వచించు PST_UNSPECIFIED ((DWORD)0x0)
#నిర్వచించు PST_RS232 ((DWORD)0x1)
#నిర్వచించు PST_PARALLELPORT ((DWORD)0x2)
#నిర్వచించు PST_RS422 ((DWORD)0x3)
#నిర్వచించు PST_RS423 ((DWORD)0x4)
#నిర్వచించు PST_RS449 ((DWORD)0x5)
#నిర్వచించు PST_MODEM ((DWORD)0x6)
#నిర్వచించు PST_FAX ((DWORD)0x21)
#నిర్వచించు PST_SCANNER ((DWORD)0x22)
#నిర్వచించు PST_జాలం_BRIDGE ((DWORD)0x100)
#నిర్వచించు PST_LAT ((DWORD)0x101)
#నిర్వచించు PST_TCPIP_TELNET ((DWORD)0x102)
#నిర్వచించు PST_X25 ((DWORD)0x103)

#నిర్వచించు PCF_DTRDSR ((DWORD)0x1)
#నిర్వచించు PCF_RTSCTS ((DWORD)0x2)
#నిర్వచించు PCF_RLSD ((DWORD)0x4)
#నిర్వచించు PCF_PARITY_CHECK ((DWORD)0x8)
#నిర్వచించు PCF_XONXOFF ((DWORD)0x10)
#నిర్వచించు PCF_SETXCHAR ((DWORD)0x20)
#నిర్వచించు PCF_TOTALTIMEOUTS ((DWORD)0x40)
#నిర్వచించు PCF_INTTIMEOUTS ((DWORD)0x80)
#నిర్వచించు PCF_SPECIALCHARS ((DWORD)0x100)
#నిర్వచించు PCF_16BITMODE ((DWORD)0x200)

#నిర్వచించు SP_PARITY ((DWORD)0x1)
#నిర్వచించు SP_BAUD ((DWORD)0x2)
#నిర్వచించు SP_DATABITS ((DWORD)0x4)
#నిర్వచించు SP_STOPBITS ((DWORD)0x8)
#నిర్వచించు SP_HANDSHAKING ((DWORD)0x10)
#నిర్వచించు SP_PARITY_CHECK ((DWORD)0x20)
#నిర్వచించు SP_RLSD ((DWORD)0x40)

#నిర్వచించు BAUD_075 ((DWORD)0x1)
#నిర్వచించు BAUD_110 ((DWORD)0x2)
#నిర్వచించు BAUD_134_5 ((DWORD)0x4)
#నిర్వచించు BAUD_150 ((DWORD)0x8)
#నిర్వచించు BAUD_300 ((DWORD)0x10)
#నిర్వచించు BAUD_600 ((DWORD)0x20)
#నిర్వచించు BAUD_1200 ((DWORD)0x40)
#నిర్వచించు BAUD_1800 ((DWORD)0x80)
#నిర్వచించు BAUD_2400 ((DWORD)0x100)
#నిర్వచించు BAUD_4800 ((DWORD)0x200)
#నిర్వచించు BAUD_7200 ((DWORD)0x400)
#నిర్వచించు BAUD_9600 ((DWORD)0x800)
#నిర్వచించు BAUD_14400 ((DWORD)0x1000)
#నిర్వచించు BAUD_19200 ((DWORD)0x2000)
#నిర్వచించు BAUD_38400 ((DWORD)0x4000)
#నిర్వచించు BAUD_56K ((DWORD)0x8000)
#నిర్వచించు BAUD_128K ((DWORD)0x10000)
#నిర్వచించు BAUD_115200 ((DWORD)0x20000)
#నిర్వచించు BAUD_57600 ((DWORD)0x40000)
#నిర్వచించు BAUD_USER ((DWORD)0x10000000)

#నిర్వచించు DATABITS_5 ((మాట_3)0x1)
#నిర్వచించు DATABITS_6 ((మాట_3)0x2)
#నిర్వచించు DATABITS_7 ((మాట_3)0x4)
#నిర్వచించు DATABITS_8 ((మాట_3)0x8)
#నిర్వచించు DATABITS_16 ((మాట_3)0x10)
#నిర్వచించు DATABITS_16X ((మాట_3)0x20)

#నిర్వచించు STOPBITS_10 ((మాట_3)0x1)
#నిర్వచించు STOPBITS_15 ((మాట_3)0x2)
#నిర్వచించు STOPBITS_20 ((మాట_3)0x4)
#నిర్వచించు PARITY_NONE ((మాట_3)0x100)
#నిర్వచించు PARITY_ODD ((మాట_3)0x200)
#నిర్వచించు PARITY_EVEN ((మాట_3)0x400)
#నిర్వచించు PARITY_MARK ((మాట_3)0x800)
#నిర్వచించు PARITY_SPACE ((మాట_3)0x1000)

  రకనిర్వచనం నిర్మాణం _COMMPROP {
    మాట_3 w_Packet_నిడివి;
    మాట_3 w_Packet_సంస్కరణ;
    DWORD dw_Service_ముసుగు;
    DWORD dwReserved1;
    DWORD dw_Max_Tx_వరుస;
    DWORD dw_Max_Rx_వరుస;
    DWORD dwMaxBaud;
    DWORD dwProvSubType;
    DWORD dwProvCapabilities;
    DWORD dwSettableParams;
    DWORD dwSettableBaud;
    మాట_3 w_Settable_దత్తాంశం;
    మాట_3 wSettableStopParity;
    DWORD dw_Current_Tx_వరుస;
    DWORD dw_Current_Rx_వరుస;
    DWORD dwProvSpec1;
    DWORD dwProvSpec2;
    WCHAR wcProvChar[1];
  } COMMPROP,*LPCOMMPROP;

#నిర్వచించు COMMPROP_INITIALIZED ((DWORD)0xE73CF52E)

  రకనిర్వచనం నిర్మాణం _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD f_Xoff_పంపిన : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cb_లోపల_Que;
    DWORD cb_బహిర్గతం_Que;
  } COMSTAT,*LPCOMSTAT;

#నిర్వచించు DTR_CONTROL_DISABLE 0x0
#నిర్వచించు DTR_CONTROL_ENABLE 0x1
#నిర్వచించు DTR_CONTROL_HANDSHAKE 0x2

#నిర్వచించు RTS_CONTROL_DISABLE 0x0
#నిర్వచించు RTS_CONTROL_ENABLE 0x1
#నిర్వచించు RTS_CONTROL_HANDSHAKE 0x2
#నిర్వచించు RTS_CONTROL_TOGGLE 0x3

  రకనిర్వచనం నిర్మాణం _DCB {
    DWORD DCBlength;
    DWORD Baud_రేటు;
    DWORD f_ద్విమాన: 1;
    DWORD fParity: 1;
    DWORD fOutxCtsFlow:1;
    DWORD fOutxDsrFlow:1;
    DWORD fDtrControl:2;
    DWORD f_Dsr_సున్నితత్వం:1;
    DWORD fTXContinueOnXoff: 1;
    DWORD f_బహిర్గతం_X: 1;
    DWORD f_లోపల_X: 1;
    DWORD fErrorChar: 1;
    DWORD fNull: 1;
    DWORD fRtsControl:2;
    DWORD fAbortOnError:1;
    DWORD fDummy2:17;
    మాట_3 wReserved;
    మాట_3 XonLim;
    మాట_3 XoffLim;
    BYTE Byte_కొలత;
    BYTE Parity;
    BYTE Stop_బిట్లు;
    అక్షరం XonChar;
    అక్షరం XoffChar;
    అక్షరం ErrorChar;
    అక్షరం EofChar;
    అక్షరం EvtChar;
    మాట_3 wReserved1;
  } DCB,*LPDCB;

  రకనిర్వచనం నిర్మాణం _COMMTIMEOUTS {
    DWORD ReadIntervalTimeout;
    DWORD Read_మొత్తం_Timeout_Multiplier;
    DWORD Read_మొత్తం_Timeout_Constant;
    DWORD Write_మొత్తం_Timeout_Multiplier;
    DWORD Write_మొత్తం_Timeout_Constant;
  } COMMTIMEOUTS,*LPCOMMTIMEOUTS;

  రకనిర్వచనం నిర్మాణం _COMMCONFIG {
    DWORD dw_కొలత;
    మాట_3 w_సంస్కరణ;
    మాట_3 wReserved;
    DCB dcb;
    DWORD dwProviderSubType;
    DWORD dw_Provider_స్థానభ్రంశం;
    DWORD dw_Provider_కొలత;
    WCHAR wc_Provider_దత్తాంశం[1];
  } COMMCONFIG,*LPCOMMCONFIG;

  రకనిర్వచనం నిర్మాణం _SYSTEM_INFO {
    సంఘం {
      DWORD dwOemId;
      నిర్మాణం {
	మాట_3 wProcessorArchitecture;
	మాట_3 wReserved;
      };
    };
    DWORD dw_పుట_కొలత;
    LPVOID lp_Minimum_Application_చిరునామా;
    LPVOID lp_గరిష్ఠ_Application_చిరునామా;
    DWORD_PTR dw_చురుకైన_Processor_ముసుగు;
    DWORD dw_సంఖ్య_యొక్క_Processors;
    DWORD dwProcessorType;
    DWORD dw_కేటాయింపు_Granularity;
    మాట_3 wProcessorLevel;
    మాట_3 wProcessorRevision;
  } SYSTEM_INFO,*LPSYSTEM_INFO;

#నిర్వచించు FreeModule(hLibModule) FreeLibrary((hLibModule))
#నిర్వచించు MakeProcInstance(lpProc,hInstance) (lpProc)
#నిర్వచించు FreeProcInstance(lpProc) (lpProc)

#నిర్వచించు GMEM_FIXED 0x0
#నిర్వచించు GMEM_MOVEABLE 0x2
#నిర్వచించు GMEM_NOCOMPACT 0x10
#నిర్వచించు GMEM_NODISCARD 0x20
#నిర్వచించు GMEM_ZEROINIT 0x40
#నిర్వచించు GMEM_MODIFY 0x80
#నిర్వచించు GMEM_DISCARDABLE 0x100
#నిర్వచించు GMEM_NOT_BANKED 0x1000
#నిర్వచించు GMEM_SHARE 0x2000
#నిర్వచించు GMEM_DDESHARE 0x2000
#నిర్వచించు GMEM_NOTIFY 0x4000
#నిర్వచించు GMEM_క్రింది GMEM_NOT_BANKED
#నిర్వచించు GMEM_VALID_FLAGS 0x7F72
#నిర్వచించు GMEM_INVALID_HANDLE 0x8000

#నిర్వచించు GHND (GMEM_MOVEABLE | GMEM_ZEROINIT)
#నిర్వచించు GPTR (GMEM_FIXED | GMEM_ZEROINIT)

#నిర్వచించు GlobalLRUNewest(h) ((HANDLE)(h))
#నిర్వచించు GlobalLRUOldest(h) ((HANDLE)(h))
#నిర్వచించు GlobalDiscard(h) GlobalReAlloc((h),0,GMEM_MOVEABLE)

#నిర్వచించు GMEM_DISCARDED 0x4000
#నిర్వచించు GMEM_LOCKCOUNT 0xff

  రకనిర్వచనం నిర్మాణం _MEMORYSTATUS {
    DWORD dw_నిడివి;
    DWORD dw_జ్ఞాపకం_ఎక్కించు;
    కొలత_T dw_మొత్తం_Phys;
    కొలత_T dwAvailPhys;
    కొలత_T dw_మొత్తం_పుట_File;
    కొలత_T dw_Avail_పుట_File;
    కొలత_T dw_మొత్తం_Virtual;
    కొలత_T dwAvailVirtual;
  } MEMORYSTATUS,*LPMEMORYSTATUS;

#నిర్వచించు LMEM_FIXED 0x0
#నిర్వచించు LMEM_MOVEABLE 0x2
#నిర్వచించు LMEM_NOCOMPACT 0x10
#నిర్వచించు LMEM_NODISCARD 0x20
#నిర్వచించు LMEM_ZEROINIT 0x40
#నిర్వచించు LMEM_MODIFY 0x80
#నిర్వచించు LMEM_DISCARDABLE 0xf00
#నిర్వచించు LMEM_VALID_FLAGS 0xf72
#నిర్వచించు LMEM_INVALID_HANDLE 0x8000

#నిర్వచించు LHND (LMEM_MOVEABLE | LMEM_ZEROINIT)
#నిర్వచించు LPTR (LMEM_FIXED | LMEM_ZEROINIT)

#నిర్వచించు NONZEROLHND (LMEM_MOVEABLE)
#నిర్వచించు NONZEROLPTR (LMEM_FIXED)

#నిర్వచించు LocalDiscard(h) LocalReAlloc((h),0,LMEM_MOVEABLE)

#నిర్వచించు LMEM_DISCARDED 0x4000
#నిర్వచించు LMEM_LOCKCOUNT 0xff

#నిర్వచించు DEBUG_PROCESS 0x1
#నిర్వచించు DEBUG_ONLY_THIS_PROCESS 0x2
#నిర్వచించు CREATE_SUSPENDED 0x4
#నిర్వచించు DETACHED_PROCESS 0x8
#నిర్వచించు CREATE_NEW_CONSOLE 0x10
#నిర్వచించు సాధారణ_ప్రాధాన్యత_CLASS 0x20
#నిర్వచించు IDLE_ప్రాధాన్యత_CLASS 0x40
#నిర్వచించు ఎగువ_ప్రాధాన్యత_CLASS 0x80
#నిర్వచించు REALTIME_ప్రాధాన్యత_CLASS 0x100
#నిర్వచించు CREATE_NEW_PROCESS_సమూహం 0x200
#నిర్వచించు CREATE_UNICODE_ENVIRONMENT 0x400
#నిర్వచించు CREATE_SEPARATE_WOW_VDM 0x800
#నిర్వచించు CREATE_SHARED_WOW_VDM 0x1000
#నిర్వచించు CREATE_FORCEDOS 0x2000
#నిర్వచించు క్రింద_సాధారణ_ప్రాధాన్యత_CLASS 0x4000
#నిర్వచించు ABOVE_సాధారణ_ప్రాధాన్యత_CLASS 0x8000
#నిర్వచించు దొంతర_కొలత_PARAM_IS_A_RESERVATION 0x10000

#నిర్వచించు CREATE_BREAKAWAY_FROM_పని 0x1000000
#నిర్వచించు CREATE_PRESERVE_సంకేతం_AUTHZ_LEVEL 0x2000000

#నిర్వచించు CREATE_DEFAULT_ERROR_బహుళకం 0x4000000
#నిర్వచించు CREATE_NO_కిటికీ 0x8000000

#నిర్వచించు PROFILE_USER 0x10000000
#నిర్వచించు PROFILE_KERNEL 0x20000000
#నిర్వచించు PROFILE_SERVER 0x40000000

#నిర్వచించు CREATE_IGNORE_SYSTEM_DEFAULT 0x80000000

#నిర్వచించు THREAD_ప్రాధాన్యత_అత్యల్ప THREAD_పునాది_ప్రాధాన్యత_MIN
#నిర్వచించు THREAD_ప్రాధాన్యత_క్రింద_సాధారణ (THREAD_ప్రాధాన్యత_అత్యల్ప+1)
#నిర్వచించు THREAD_ప్రాధాన్యత_సాధారణ 0
#నిర్వచించు THREAD_ప్రాధాన్యత_HIGHEST THREAD_పునాది_ప్రాధాన్యత_MAX
#నిర్వచించు THREAD_ప్రాధాన్యత_ABOVE_సాధారణ (THREAD_ప్రాధాన్యత_HIGHEST-1)
#నిర్వచించు THREAD_ప్రాధాన్యత_ERROR_RETURN (MAXLONG)

#నిర్వచించు THREAD_ప్రాధాన్యత_సమయం_CRITICAL THREAD_పునాది_ప్రాధాన్యత_LOWRT
#నిర్వచించు THREAD_ప్రాధాన్యత_IDLE THREAD_పునాది_ప్రాధాన్యత_IDLE

#నిర్వచించు EXCEPTION_DEBUG_EVENT 1
#నిర్వచించు CREATE_THREAD_DEBUG_EVENT 2
#నిర్వచించు CREATE_PROCESS_DEBUG_EVENT 3
#నిర్వచించు EXIT_THREAD_DEBUG_EVENT 4
#నిర్వచించు EXIT_PROCESS_DEBUG_EVENT 5
#నిర్వచించు ఎక్కించు_DLL_DEBUG_EVENT 6
#నిర్వచించు UNLOAD_DLL_DEBUG_EVENT 7
#నిర్వచించు OUTPUT_DEBUG_STRING_EVENT 8
#నిర్వచించు RIP_EVENT 9

  రకనిర్వచనం నిర్మాణం _EXCEPTION_DEBUG_INFO {
    EXCEPTION_రికార్డు_2 Exception_రికార్డు;
    DWORD dw_మొదటి_Chance;
  } EXCEPTION_DEBUG_INFO,*LPEXCEPTION_DEBUG_INFO;

  రకనిర్వచనం నిర్మాణం _CREATE_THREAD_DEBUG_INFO {
    HANDLE hThread;
    LPVOID lp_Thread_Local_పునాది;
    LPTHREAD_ప్రారంభం_ROUTINE lp_ప్రారంభం_చిరునామా;
  } CREATE_THREAD_DEBUG_INFO,*LPCREATE_THREAD_DEBUG_INFO;

  రకనిర్వచనం నిర్మాణం _CREATE_PROCESS_DEBUG_INFO {
    HANDLE hFile;
    HANDLE hProcess;
    HANDLE hThread;
    LPVOID lp_పునాది_యొక్క_Image;
    DWORD dw_Debug_Info_File_స్థానభ్రంశం;
    DWORD n_Debug_Info_కొలత;
    LPVOID lp_Thread_Local_పునాది;
    LPTHREAD_ప్రారంభం_ROUTINE lp_ప్రారంభం_చిరునామా;
    LPVOID lpImageName;
    మాట_3 fUnicode;
  } CREATE_PROCESS_DEBUG_INFO,*LPCREATE_PROCESS_DEBUG_INFO;

  రకనిర్వచనం నిర్మాణం _EXIT_THREAD_DEBUG_INFO {
    DWORD dw_Exit_సంకేతం;
  } EXIT_THREAD_DEBUG_INFO,*LPEXIT_THREAD_DEBUG_INFO;

  రకనిర్వచనం నిర్మాణం _EXIT_PROCESS_DEBUG_INFO {
    DWORD dw_Exit_సంకేతం;
  } EXIT_PROCESS_DEBUG_INFO,*LPEXIT_PROCESS_DEBUG_INFO;

  రకనిర్వచనం నిర్మాణం ఎక్కించు_DLL_DEBUG_INFO {
    HANDLE hFile;
    LPVOID lp_పునాది_యొక్క_Dll;
    DWORD dw_Debug_Info_File_స్థానభ్రంశం;
    DWORD n_Debug_Info_కొలత;
    LPVOID lpImageName;
    మాట_3 fUnicode;
  } ఎక్కించు_DLL_DEBUG_INFO_2,*LPLOAD_DLL_DEBUG_INFO;

  రకనిర్వచనం నిర్మాణం _UNLOAD_DLL_DEBUG_INFO {
    LPVOID lp_పునాది_యొక్క_Dll;
  } UNLOAD_DLL_DEBUG_INFO,*LPUNLOAD_DLL_DEBUG_INFO;

  రకనిర్వచనం నిర్మాణం _OUTPUT_DEBUG_STRING_INFO {
    LPSTR lp_Debug_String_దత్తాంశం;
    మాట_3 fUnicode;
    మాట_3 n_Debug_String_నిడివి;
  } OUTPUT_DEBUG_STRING_INFO,*LPOUTPUT_DEBUG_STRING_INFO;

  రకనిర్వచనం నిర్మాణం _RIP_INFO {
    DWORD dwError;
    DWORD dwType;
  } RIP_INFO,*LPRIP_INFO;

  రకనిర్వచనం నిర్మాణం _DEBUG_EVENT {
    DWORD dw_Debug_Event_సంకేతం;
    DWORD dwProcessId;
    DWORD dwThreadId;
    సంఘం {
      EXCEPTION_DEBUG_INFO Exception;
      CREATE_THREAD_DEBUG_INFO CreateThread;
      CREATE_PROCESS_DEBUG_INFO CreateProcessInfo;
      EXIT_THREAD_DEBUG_INFO ExitThread;
      EXIT_PROCESS_DEBUG_INFO ExitProcess;
      ఎక్కించు_DLL_DEBUG_INFO_2 ఎక్కించు_Dll;
      UNLOAD_DLL_DEBUG_INFO UnloadDll;
      OUTPUT_DEBUG_STRING_INFO DebugString;
      RIP_INFO RipInfo;
    } u;
  } DEBUG_EVENT,*LPDEBUG_EVENT;

  రకనిర్వచనం PCONTEXT LPCONTEXT;
  రకనిర్వచనం PEXCEPTION_రికార్డు LPEXCEPTION_రికార్డు;
  రకనిర్వచనం PEXCEPTION_సూచికలు LPEXCEPTION_సూచికలు;

#నిర్వచించు DRIVE_UNKNOWN 0
#నిర్వచించు DRIVE_NO_మూలం_DIR 1
#నిర్వచించు DRIVE_REMOVABLE 2
#నిర్వచించు DRIVE_FIXED 3
#నిర్వచించు DRIVE_REMOTE 4
#నిర్వచించు DRIVE_CDROM 5
#నిర్వచించు DRIVE_RAMDISK 6

#నిర్వచించు GetFreeSpace(w) (0x100000L)
#నిర్వచించు FILE_TYPE_UNKNOWN 0x0
#నిర్వచించు FILE_TYPE_DISK 0x1
#నిర్వచించు FILE_TYPE_CHAR 0x2
#నిర్వచించు FILE_TYPE_PIPE 0x3
#నిర్వచించు FILE_TYPE_REMOTE 0x8000

#నిర్వచించు STD_ఆదానం_HANDLE ((DWORD)-10)
#నిర్వచించు STD_OUTPUT_HANDLE ((DWORD)-11)
#నిర్వచించు STD_ERROR_HANDLE ((DWORD)-12)

#నిర్వచించు NOPARITY 0
#నిర్వచించు ODDPARITY 1
#నిర్వచించు EVENPARITY 2
#నిర్వచించు MARKPARITY 3
#నిర్వచించు SPACEPARITY 4

#నిర్వచించు ONESTOPBIT 0
#నిర్వచించు ONE5STOPBITS 1
#నిర్వచించు TWOSTOPBITS 2

#నిర్వచించు IGNORE 0
#నిర్వచించు INFINITE 0xffffffff

#నిర్వచించు CBR_110 110
#నిర్వచించు CBR_300 300
#నిర్వచించు CBR_600 600
#నిర్వచించు CBR_1200 1200
#నిర్వచించు CBR_2400 2400
#నిర్వచించు CBR_4800 4800
#నిర్వచించు CBR_9600 9600
#నిర్వచించు CBR_14400 14400
#నిర్వచించు CBR_19200 19200
#నిర్వచించు CBR_38400 38400
#నిర్వచించు CBR_56000 56000
#నిర్వచించు CBR_57600 57600
#నిర్వచించు CBR_115200 115200
#నిర్వచించు CBR_128000 128000
#నిర్వచించు CBR_256000 256000

#నిర్వచించు CE_RXOVER 0x1
#నిర్వచించు CE_OVERRUN 0x2
#నిర్వచించు CE_RXPARITY 0x4
#నిర్వచించు CE_చట్రం 0x8
#నిర్వచించు CE_BREAK 0x10
#నిర్వచించు CE_TXFULL 0x100
#నిర్వచించు CE_PTO 0x200
#నిర్వచించు CE_IOE 0x400
#నిర్వచించు CE_DNS 0x800
#నిర్వచించు CE_OOP 0x1000
#నిర్వచించు CE_బహుళకం 0x8000

#నిర్వచించు IE_BADID (-1)
#నిర్వచించు IE_OPEN (-2)
#నిర్వచించు IE_NOPEN (-3)
#నిర్వచించు IE_జ్ఞాపకం (-4)
#నిర్వచించు IE_DEFAULT (-5)
#నిర్వచించు IE_HARDWARE (-10)
#నిర్వచించు IE_BYTESIZE (-11)
#నిర్వచించు IE_BAUDRATE (-12)

#నిర్వచించు EV_RXCHAR 0x1
#నిర్వచించు EV_RXFLAG 0x2
#నిర్వచించు EV_TXEMPTY 0x4
#నిర్వచించు EV_CTS 0x8
#నిర్వచించు EV_DSR 0x10
#నిర్వచించు EV_RLSD 0x20
#నిర్వచించు EV_BREAK 0x40
#నిర్వచించు EV_ERR 0x80
#నిర్వచించు EV_RING 0x100
#నిర్వచించు EV_PERR 0x200
#నిర్వచించు EV_RX80_నిండిన 0x400
#నిర్వచించు EV_EVENT1 0x800
#నిర్వచించు EV_EVENT2 0x1000

#నిర్వచించు SETXOFF 1
#నిర్వచించు SETXON 2
#నిర్వచించు SETRTS 3
#నిర్వచించు CLRRTS 4
#నిర్వచించు SETDTR 5
#నిర్వచించు CLRDTR 6
#నిర్వచించు RESETDEV 7
#నిర్వచించు SETBREAK 8
#నిర్వచించు CLRBREAK 9

#నిర్వచించు PURGE_TXABORT 0x1
#నిర్వచించు PURGE_RXABORT 0x2
#నిర్వచించు PURGE_TXCLEAR 0x4
#నిర్వచించు PURGE_RXCLEAR 0x8

#నిర్వచించు LPTx 0x80

#నిర్వచించు MS_CTS_ON ((DWORD)0x10)
#నిర్వచించు MS_DSR_ON ((DWORD)0x20)
#నిర్వచించు MS_RING_ON ((DWORD)0x40)
#నిర్వచించు MS_RLSD_ON ((DWORD)0x80)

#నిర్వచించు S_QUEUEEMPTY 0
#నిర్వచించు S_పరిమితి 1
#నిర్వచించు S_ALLTHRESHOLD 2

#నిర్వచించు S_సాధారణ 0
#నిర్వచించు S_LEGATO 1
#నిర్వచించు S_STACCATO 2

#నిర్వచించు S_PERIOD512 0
#నిర్వచించు S_PERIOD1024 1
#నిర్వచించు S_PERIOD2048 2
#నిర్వచించు S_PERIODVOICE 3
#నిర్వచించు S_WHITE512 4
#నిర్వచించు S_WHITE1024 5
#నిర్వచించు S_WHITE2048 6
#నిర్వచించు S_WHITEVOICE 7

#నిర్వచించు S_SERDVNA (-1)
#నిర్వచించు S_SEROFM (-2)
#నిర్వచించు S_SERMACT (-3)
#నిర్వచించు S_SERQFUL (-4)
#నిర్వచించు S_SERBDNT (-5)
#నిర్వచించు S_SERDLN (-6)
#నిర్వచించు S_SERDCC (-7)
#నిర్వచించు S_SERDTP (-8)
#నిర్వచించు S_SERDVL (-9)
#నిర్వచించు S_SERDMD (-10)
#నిర్వచించు S_SERDSH (-11)
#నిర్వచించు S_SERDPT (-12)
#నిర్వచించు S_SERDFQ (-13)
#నిర్వచించు S_SERDDR (-14)
#నిర్వచించు S_SERDSR (-15)
#నిర్వచించు S_SERDST (-16)

#నిర్వచించు NMPWAIT_WAIT_FOREVER 0xffffffff
#నిర్వచించు NMPWAIT_NOWAIT 0x1
#నిర్వచించు NMPWAIT_USE_DEFAULT_WAIT 0x0

#నిర్వచించు FS_CASE_IS_PRESERVED FILE_CASE_PRESERVED_పేర్లు
#నిర్వచించు FS_CASE_SENSITIVE FILE_CASE_SENSITIVE_శోధన
#నిర్వచించు FS_UNICODE_STORED_ON_DISK FILE_UNICODE_ON_DISK
#నిర్వచించు FS_PERSISTENT_ACLS FILE_PERSISTENT_ACLS
#నిర్వచించు FS_VOL_IS_COMPRESSED FILE_VOLUME_IS_COMPRESSED
#నిర్వచించు FS_FILE_COMPRESSION FILE_FILE_COMPRESSION
#నిర్వచించు FS_FILE_ENCRYPTION FILE_SUPPORTS_ENCRYPTION

#నిర్వచించు FILE_MAP_COPY SECTION_QUERY
#నిర్వచించు FILE_MAP_WRITE SECTION_MAP_WRITE
#నిర్వచించు FILE_MAP_READ SECTION_MAP_READ
#నిర్వచించు FILE_MAP_ALL_ACCESS SECTION_ALL_ACCESS
#నిర్వచించు FILE_MAP_EXECUTE SECTION_MAP_EXECUTE_EXPLICIT

#నిర్వచించు యొక్క_READ 0x0
#నిర్వచించు యొక్క_WRITE 0x1
#నిర్వచించు యొక్క_READWRITE 0x2
#నిర్వచించు యొక్క_SHARE_COMPAT 0x0
#నిర్వచించు యొక్క_SHARE_EXCLUSIVE 0x10
#నిర్వచించు యొక్క_SHARE_DENY_WRITE 0x20
#నిర్వచించు యొక్క_SHARE_DENY_READ 0x30
#నిర్వచించు యొక్క_SHARE_DENY_NONE 0x40
#నిర్వచించు యొక్క_PARSE 0x100
#నిర్వచించు యొక్క_DELETE 0x200
#నిర్వచించు యొక్క_VERIFY 0x400
#నిర్వచించు యొక్క_CANCEL 0x800
#నిర్వచించు యొక్క_CREATE 0x1000
#నిర్వచించు యొక్క_PROMPT 0x2000
#నిర్వచించు యొక్క_EXIST 0x4000
#నిర్వచించు యొక్క_REOPEN 0x8000

#నిర్వచించు OFS_MAXPATHNAME 128
  రకనిర్వచనం నిర్మాణం _OFSTRUCT {
    BYTE c_బైట్లు;
    BYTE fFixedDisk;
    మాట_3 n_Err_సంకేతం;
    మాట_3 Reserved1;
    మాట_3 Reserved2;
    CHAR sz_మార్గం_Name[OFS_MAXPATHNAME];
  } OFSTRUCT,*LPOFSTRUCT,*POFSTRUCT;

#నిర్వచితం_కాకపోతే NOWINBASEINTERLOCK

#నిర్వచితం_కాకపోతే _NTOS_

#ఒకవేళ defined(__ia64__) && !defined(RC_INVOKED)

#నిర్వచించు InterlockedIncrement _InterlockedIncrement
#నిర్వచించు InterlockedIncrementAcquire _InterlockedIncrement_acq
#నిర్వచించు InterlockedIncrementRelease _InterlockedIncrement_rel
#నిర్వచించు InterlockedDecrement _InterlockedDecrement
#నిర్వచించు InterlockedDecrementAcquire _InterlockedDecrement_acq
#నిర్వచించు InterlockedDecrementRelease _InterlockedDecrement_rel
#నిర్వచించు InterlockedExchange _InterlockedExchange
#నిర్వచించు Interlocked_Exchange_కూడు Interlocked_Exchange_కూడు_2
#నిర్వచించు InterlockedCompareExchange _InterlockedCompareExchange
#నిర్వచించు InterlockedCompareExchangeAcquire _InterlockedCompareExchange_acq
#నిర్వచించు InterlockedCompareExchangeRelease _InterlockedCompareExchange_rel
#నిర్వచించు Interlocked_Exchange_సూచిక Interlocked_Exchange_సూచిక_2
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక Interlocked_Compare_Exchange_సూచిక_2
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Release Interlocked_Compare_Exchange_సూచిక_rel
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Acquire Interlocked_Compare_Exchange_సూచిక_acq

#నిర్వచించు InterlockedIncrement64 _InterlockedIncrement64
#నిర్వచించు InterlockedDecrement64 _InterlockedDecrement64
#నిర్వచించు InterlockedExchange64 _InterlockedExchange64
#నిర్వచించు InterlockedExchangeAcquire64 _InterlockedExchange64_acq
#నిర్వచించు InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#నిర్వచించు InterlockedCompareExchange64 _InterlockedCompareExchange64
#నిర్వచించు InterlockedCompareExchangeAcquire64 _InterlockedCompareExchange64_acq
#నిర్వచించు InterlockedCompareExchangeRelease64 _InterlockedCompareExchange64_rel

  LONGLONG __cdecl InterlockedIncrement64(LONGLONG అస్థిర *Addend);
  LONGLONG __cdecl InterlockedDecrement64(LONGLONG అస్థిర *Addend);
  LONG __cdecl InterlockedIncrementAcquire(LONG అస్థిర *Addend);
  LONG __cdecl InterlockedDecrementAcquire(LONG అస్థిర *Addend);
  LONG __cdecl InterlockedIncrementRelease(LONG అస్థిర *Addend);
  LONG __cdecl InterlockedDecrementRelease(LONG అస్థిర *Addend);
  LONGLONG __cdecl InterlockedExchange64 (LONGLONG అస్థిర *లక్ష్యం_2,LONGLONG విలువ_3);
  LONGLONG __cdecl InterlockedExchangeAcquire64 (LONGLONG అస్థిర *లక్ష్యం_2,LONGLONG విలువ_3);
  LONGLONG __cdecl InterlockedExchangeAdd64 (LONGLONG అస్థిర *Addend,LONGLONG విలువ_3);
  LONGLONG __cdecl InterlockedCompareExchange64 (LONGLONG అస్థిర *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeAcquire64 (LONGLONG అస్థిర *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONGLONG __cdecl InterlockedCompareExchangeRelease64 (LONGLONG అస్థిర *Destination,LONGLONG ExChange,LONGLONG Comperand);
  LONG __cdecl InterlockedIncrement(LONG అస్థిర *lpAddend);
  LONG __cdecl InterlockedDecrement(LONG అస్థిర *lpAddend);
  LONG __cdecl InterlockedExchange(LONG అస్థిర *లక్ష్యం_2,LONG విలువ_3);
  LONG __cdecl Interlocked_Exchange_కూడు(LONG అస్థిర *Addend,LONG విలువ_3);
  LONG __cdecl InterlockedCompareExchange(LONG అస్థిర *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeRelease(LONG అస్థిర *Destination,LONG ExChange,LONG Comperand);
  LONG __cdecl InterlockedCompareExchangeAcquire(LONG అస్థిర *Destination,LONG ExChange,LONG Comperand);
  PVOID __cdecl Interlocked_Exchange_సూచిక(PVOID అస్థిర *లక్ష్యం_2,PVOID విలువ_3);
  PVOID __cdecl Interlocked_Compare_Exchange_సూచిక(PVOID అస్థిర *Destination,PVOID ExChange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_సూచిక_Acquire(PVOID అస్థిర *Destination,PVOID Exchange,PVOID Comperand);
  PVOID __cdecl Interlocked_Compare_Exchange_సూచిక_Release(PVOID అస్థిర *Destination,PVOID Exchange,PVOID Comperand);

#నిర్వచితం_కాకపోతే InterlockedAnd
#నిర్వచించు InterlockedAnd InterlockedAnd_Inline
  __CRT_INLINE LONG InterlockedAnd_Inline(LONG అస్థిర *లక్ష్యం_2,LONG సమితి_2) {
    LONG i;
    LONG j;
    j = *లక్ష్యం_2;
    చేయి {
      i = j;
      j = InterlockedCompareExchange(లక్ష్యం_2,i & సమితి_2,i);
    } అయితే(i!=j);
    తిరిగి j;
  }
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే InterlockedOr
#నిర్వచించు InterlockedOr InterlockedOr_Inline

  __CRT_INLINE LONG InterlockedOr_Inline(LONG అస్థిర *లక్ష్యం_2,LONG సమితి_2) {
    LONG i;
    LONG j;
    j = *లక్ష్యం_2;
    చేయి {
      i = j;
      j = InterlockedCompareExchange(లక్ష్యం_2,i | సమితి_2,i);
    } అయితే(i!=j);
    తిరిగి j;
  }
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే InterlockedXor
#నిర్వచించు InterlockedXor InterlockedXor_Inline

  __CRT_INLINE LONG InterlockedXor_Inline(LONG అస్థిర *లక్ష్యం_2,LONG సమితి_2) {
    LONG i;
    LONG j;
    j = *లక్ష్యం_2;
    చేయి {
      i = j;
      j = InterlockedCompareExchange(లక్ష్యం_2,i ^ సమితి_2,i);
    } అయితే(i!=j);
    తిరిగి j;
  }
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే InterlockedAnd64
#నిర్వచించు InterlockedAnd64 InterlockedAnd64_Inline

  __CRT_INLINE LONGLONG InterlockedAnd64_Inline (LONGLONG అస్థిర *Destination,LONGLONG విలువ_3) {
    LONGLONG Old;
    చేయి {
      Old = *Destination;
    } అయితే(InterlockedCompareExchange64(Destination,Old & విలువ_3,Old)!=Old);
    తిరిగి Old;
  }
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే InterlockedOr64
#నిర్వచించు InterlockedOr64 InterlockedOr64_Inline

  __CRT_INLINE LONGLONG InterlockedOr64_Inline (LONGLONG అస్థిర *Destination,LONGLONG విలువ_3) {
    LONGLONG Old;
    చేయి {
      Old = *Destination;
    } అయితే(InterlockedCompareExchange64(Destination,Old | విలువ_3,Old)!=Old);
    తిరిగి Old;
  }
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే InterlockedXor64
#నిర్వచించు InterlockedXor64 InterlockedXor64_Inline

  __CRT_INLINE LONGLONG InterlockedXor64_Inline (LONGLONG అస్థిర *Destination,LONGLONG విలువ_3) {
    LONGLONG Old;
    చేయి {
      Old = *Destination;
    } అయితే(InterlockedCompareExchange64(Destination,Old ^ విలువ_3,Old)!=Old);
    తిరిగి Old;
  }
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే Interlocked_బిట్టు_Test_And_సమితి
#నిర్వచించు Interlocked_బిట్టు_Test_And_సమితి Interlocked_బిట్టు_Test_And_సమితి_Inline

  __CRT_INLINE BOOLEAN Interlocked_బిట్టు_Test_And_సమితి_Inline(LONG *పునాది_2,LONG బిట్టు_2) {
    LONG t_బిట్టు;
    t_బిట్టు = 1<<(బిట్టు_2 & (పరిమాణం (*పునాది_2)*8-1));
    తిరిగి (BOOLEAN)((InterlockedOr(&పునాది_2[బిట్టు_2/(పరిమాణం(*పునాది_2)*8)],t_బిట్టు)&t_బిట్టు)!=0);
  }
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే Interlocked_బిట్టు_Test_And_Reset
#నిర్వచించు Interlocked_బిట్టు_Test_And_Reset Interlocked_బిట్టు_Test_And_Reset_Inline

  __CRT_INLINE BOOLEAN Interlocked_బిట్టు_Test_And_Reset_Inline(LONG *పునాది_2,LONG బిట్టు_2) {
    LONG t_బిట్టు;
    t_బిట్టు = 1<<(బిట్టు_2 & (పరిమాణం (*పునాది_2)*8-1));
    తిరిగి (BOOLEAN)((InterlockedAnd(&పునాది_2[బిట్టు_2/(పరిమాణం(*పునాది_2)*8)],~t_బిట్టు)&t_బిట్టు)!=0);
  }
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే Interlocked_బిట్టు_Test_And_Complement
#నిర్వచించు Interlocked_బిట్టు_Test_And_Complement Interlocked_బిట్టు_Test_And_Complement_Inline

  __CRT_INLINE BOOLEAN Interlocked_బిట్టు_Test_And_Complement_Inline(LONG *పునాది_2,LONG బిట్టు_2) {
    LONG t_బిట్టు;
    t_బిట్టు = 1<<(బిట్టు_2 & (పరిమాణం (*పునాది_2)*8-1));
    తిరిగి (BOOLEAN)((InterlockedXor(&పునాది_2[బిట్టు_2/(పరిమాణం(*పునాది_2)*8)],t_బిట్టు)&t_బిట్టు)!=0);
  }
#అయితే_ముగింపు
#లేదావేళ defined(__x86_64) && !defined(RC_INVOKED)

#నిర్వచించు InterlockedIncrement _InterlockedIncrement
#నిర్వచించు InterlockedIncrementAcquire InterlockedIncrement
#నిర్వచించు InterlockedIncrementRelease InterlockedIncrement
#నిర్వచించు InterlockedDecrement _InterlockedDecrement
#నిర్వచించు InterlockedDecrementAcquire InterlockedDecrement
#నిర్వచించు InterlockedDecrementRelease InterlockedDecrement
#నిర్వచించు InterlockedExchange _InterlockedExchange
#నిర్వచించు Interlocked_Exchange_కూడు Interlocked_Exchange_కూడు_2
#నిర్వచించు InterlockedCompareExchange _InterlockedCompareExchange
#నిర్వచించు InterlockedCompareExchangeAcquire InterlockedCompareExchange
#నిర్వచించు InterlockedCompareExchangeRelease InterlockedCompareExchange
#నిర్వచించు Interlocked_Exchange_సూచిక Interlocked_Exchange_సూచిక_2
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక Interlocked_Compare_Exchange_సూచిక_2
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Acquire Interlocked_Compare_Exchange_సూచిక_2
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Release Interlocked_Compare_Exchange_సూచిక_2
#నిర్వచించు InterlockedAnd64 _InterlockedAnd64
#నిర్వచించు InterlockedOr64 _InterlockedOr64
#నిర్వచించు InterlockedXor64 _InterlockedXor64
#నిర్వచించు InterlockedIncrement64 _InterlockedIncrement64
#నిర్వచించు InterlockedDecrement64 _InterlockedDecrement64
#నిర్వచించు InterlockedExchange64 _InterlockedExchange64
#నిర్వచించు InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#నిర్వచించు InterlockedCompareExchange64 _InterlockedCompareExchange64
#నిర్వచించు InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#నిర్వచించు InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

  LONG InterlockedIncrement(LONG అస్థిర *Addend);
  LONG InterlockedDecrement(LONG అస్థిర *Addend);
  LONG InterlockedExchange(LONG అస్థిర *లక్ష్యం_2,LONG విలువ_3);
  LONG Interlocked_Exchange_కూడు(LONG అస్థిర *Addend,LONG విలువ_3);
  LONG InterlockedCompareExchange(LONG అస్థిర *Destination,LONG ExChange,LONG Comperand);
  PVOID Interlocked_Compare_Exchange_సూచిక(PVOID అస్థిర *Destination,PVOID Exchange,PVOID Comperand);
  PVOID Interlocked_Exchange_సూచిక(PVOID అస్థిర *లక్ష్యం_2,PVOID విలువ_3);
  LONG64 InterlockedAnd64(LONG64 అస్థిర *Destination,LONG64 విలువ_3);
  LONG64 InterlockedOr64(LONG64 అస్థిర *Destination,LONG64 విలువ_3);
  LONG64 InterlockedXor64(LONG64 అస్థిర *Destination,LONG64 విలువ_3);
  LONG64 InterlockedIncrement64(LONG64 అస్థిర *Addend);
  LONG64 InterlockedDecrement64(LONG64 అస్థిర *Addend);
  LONG64 InterlockedExchange64(LONG64 అస్థిర *లక్ష్యం_2,LONG64 విలువ_3);
  LONG64 InterlockedExchangeAdd64(LONG64 అస్థిర *Addend,LONG64 విలువ_3);
  LONG64 InterlockedCompareExchange64(LONG64 అస్థిర *Destination,LONG64 ExChange,LONG64 Comperand);
#లేకపోతే
  LONG WINAPI InterlockedIncrement(LONG అస్థిర *lpAddend);
  LONG WINAPI InterlockedDecrement(LONG అస్థిర *lpAddend);
  LONG WINAPI InterlockedExchange(LONG అస్థిర *లక్ష్యం_2,LONG విలువ_3);

#నిర్వచితం_కాకపోతే Interlocked_Exchange_సూచిక
#నిర్వచించు Interlocked_Exchange_సూచిక(లక్ష్యం_2,విలువ_3) (PVOID)InterlockedExchange((PLONG)(లక్ష్యం_2),(LONG)(విలువ_3))
#అయితే_ముగింపు

  LONG WINAPI Interlocked_Exchange_కూడు(LONG అస్థిర *Addend,LONG విలువ_3);
  LONG WINAPI InterlockedCompareExchange(LONG అస్థిర *Destination,LONG Exchange,LONG Comperand);
  LONGLONG WINAPI InterlockedCompareExchange64(LONGLONG అస్థిర *Destination,LONGLONG Exchange,LONGLONG Comperand);

  __CRT_INLINE LONGLONG InterlockedAnd64 (LONGLONG అస్థిర *Destination,LONGLONG విలువ_3) {
    LONGLONG Old;
    చేయి {
      Old = *Destination;
    } అయితే(InterlockedCompareExchange64(Destination,Old & విలువ_3,Old)!=Old);
    తిరిగి Old;
  }

  __CRT_INLINE LONGLONG InterlockedOr64 (LONGLONG అస్థిర *Destination,LONGLONG విలువ_3) {
    LONGLONG Old;
    చేయి {
      Old = *Destination;
    } అయితే(InterlockedCompareExchange64(Destination,Old | విలువ_3,Old)!=Old);
    తిరిగి Old;
  }

  __CRT_INLINE LONGLONG InterlockedXor64 (LONGLONG అస్థిర *Destination,LONGLONG విలువ_3) {
    LONGLONG Old;
    చేయి {
      Old = *Destination;
    } అయితే(InterlockedCompareExchange64(Destination,Old ^ విలువ_3,Old)!=Old);

    తిరిగి Old;
  }

  __CRT_INLINE LONGLONG InterlockedIncrement64(LONGLONG అస్థిర *Addend) {
    LONGLONG Old;
    చేయి {
      Old = *Addend;
    } అయితే(InterlockedCompareExchange64(Addend,Old + 1,Old)!=Old);
    తిరిగి Old + 1;
  }

  __CRT_INLINE LONGLONG InterlockedDecrement64(LONGLONG అస్థిర *Addend) {
    LONGLONG Old;
    చేయి {
      Old = *Addend;
    } అయితే(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
    తిరిగి Old - 1;
  }

  __CRT_INLINE LONGLONG InterlockedExchange64(LONGLONG అస్థిర *లక్ష్యం_2,LONGLONG విలువ_3) {
    LONGLONG Old;
    చేయి {
      Old = *లక్ష్యం_2;
    } అయితే(InterlockedCompareExchange64(లక్ష్యం_2,విలువ_3,Old)!=Old);
    తిరిగి Old;
  }

  __CRT_INLINE LONGLONG InterlockedExchangeAdd64(LONGLONG అస్థిర *Addend,LONGLONG విలువ_3) {
    LONGLONG Old;
    చేయి {
      Old = *Addend;
    } అయితే(InterlockedCompareExchange64(Addend,Old + విలువ_3,Old)!=Old);
    తిరిగి Old;
  }

#నిర్వచితం_కాకపోతే Interlocked_Compare_Exchange_సూచిక
#నిర్వచితమైతే __cplusplus
  __CRT_INLINE PVOID __cdecl __InlineInterlockedCompareExchangePointer(PVOID అస్థిర *Destination,PVOID ExChange,PVOID Comperand) {
    తిరిగి((PVOID)(LONG_PTR)InterlockedCompareExchange((LONG అస్థిర *)Destination,(LONG)(LONG_PTR)ExChange,(LONG)(LONG_PTR)Comperand));
  }
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక __InlineInterlockedCompareExchangePointer
#లేకపోతే
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక(Destination,ExChange,Comperand)(PVOID)(LONG_PTR)InterlockedCompareExchange((LONG అస్థిర *)(Destination),(LONG)(LONG_PTR)(ExChange),(LONG)(LONG_PTR)(Comperand))
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు InterlockedIncrementAcquire InterlockedIncrement
#నిర్వచించు InterlockedIncrementRelease InterlockedIncrement
#నిర్వచించు InterlockedDecrementAcquire InterlockedDecrement
#నిర్వచించు InterlockedDecrementRelease InterlockedDecrement
#నిర్వచించు InterlockedIncrementAcquire InterlockedIncrement
#నిర్వచించు InterlockedIncrementRelease InterlockedIncrement
#నిర్వచించు InterlockedCompareExchangeAcquire InterlockedCompareExchange
#నిర్వచించు InterlockedCompareExchangeRelease InterlockedCompareExchange
#నిర్వచించు InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#నిర్వచించు InterlockedCompareExchangeRelease64 InterlockedCompareExchange64
#నిర్వచితం_కాకపోతే Interlocked_Compare_Exchange_సూచిక_Acquire
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Acquire Interlocked_Compare_Exchange_సూచిక
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే Interlocked_Compare_Exchange_సూచిక_Release
#నిర్వచించు Interlocked_Compare_Exchange_సూచిక_Release Interlocked_Compare_Exchange_సూచిక
#అయితే_ముగింపు
#అయితే_ముగింపు

#ఒకవేళ defined(SLIST_శీర్షిక) && !defined(_NTOSP_)
  WINBASEAPI VOID WINAPI Initialize_SList_తల(PSLIST_శీర్షిక List_తల);
  WINBASEAPI PSLIST_నమోదు WINAPI Interlocked_తీయి_నమోదు_SList(PSLIST_శీర్షిక List_తల);
  WINBASEAPI PSLIST_నమోదు WINAPI Interlocked_నెట్టు_నమోదు_SList(PSLIST_శీర్షిక List_తల,PSLIST_నమోదు List_నమోదు);
  WINBASEAPI PSLIST_నమోదు WINAPI InterlockedFlushSList(PSLIST_శీర్షిక List_తల);
  WINBASEAPI USHORT WINAPI Query_లోతు_SList(PSLIST_శీర్షిక List_తల);
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI FreeResource(HGLOBAL h_Res_దత్తాంశం);
  WINBASEAPI LPVOID WINAPI తాళం_Resource(HGLOBAL h_Res_దత్తాంశం);

#నిర్వచించు UnlockResource(h_Res_దత్తాంశం) ((h_Res_దత్తాంశం),0)
#నిర్వచించు MAXINTATOM 0xC000
#నిర్వచించు MAKEINTATOM(i) (LPTSTR)((ULONG_PTR)((మాట_3)(i)))
#నిర్వచించు INVALID_ATOM ((ATOM)0)

  పూర్ణాంకం WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lp_Cmd_పంక్తి,పూర్ణాంకం nShowCmd);
  WINBASEAPI WINBOOL WINAPI FreeLibrary(HMODULE hLibModule);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI FreeLibraryAndExitThread(HMODULE hLibModule,DWORD dw_Exit_సంకేతం);
  WINBASEAPI WINBOOL WINAPI DisableThreadLibraryCalls(HMODULE hLibModule);
  WINBASEAPI FARPROC WINAPI Get_Proc_చిరునామా(HMODULE hModule,LPCSTR lpProcName);
  WINBASEAPI DWORD WINAPI Get_సంస్కరణ(VOID);
  WINBASEAPI HGLOBAL WINAPI GlobalAlloc(UINT uFlags,కొలత_T dw_బైట్లు);
  WINBASEAPI HGLOBAL WINAPI GlobalReAlloc(HGLOBAL hMem,కొలత_T dw_బైట్లు,UINT uFlags);
  WINBASEAPI కొలత_T WINAPI Global_కొలత(HGLOBAL hMem);
  WINBASEAPI UINT WINAPI GlobalFlags(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI Global_తాళం(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnlock(HGLOBAL hMem);
  WINBASEAPI HGLOBAL WINAPI GlobalFree(HGLOBAL hMem);
  WINBASEAPI కొలత_T WINAPI GlobalCompact(DWORD dwMinFree);
  WINBASEAPI VOID WINAPI GlobalFix(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI GlobalUnfix(HGLOBAL hMem);
  WINBASEAPI LPVOID WINAPI GlobalWire(HGLOBAL hMem);
  WINBASEAPI WINBOOL WINAPI GlobalUnWire(HGLOBAL hMem);
  WINBASEAPI VOID WINAPI Global_జ్ఞాపకం_స్థితి(LPMEMORYSTATUS lp_బఫరు);

  రకనిర్వచనం నిర్మాణం _MEMORYSTATUSEX {
    DWORD dw_నిడివి;
    DWORD dw_జ్ఞాపకం_ఎక్కించు;
    DWORDLONG ull_మొత్తం_Phys;
    DWORDLONG ullAvailPhys;
    DWORDLONG ull_మొత్తం_పుట_File;
    DWORDLONG ull_Avail_పుట_File;
    DWORDLONG ull_మొత్తం_Virtual;
    DWORDLONG ullAvailVirtual;
    DWORDLONG ullAvailExtendedVirtual;
  } MEMORYSTATUSEX,*LPMEMORYSTATUSEX;

  WINBASEAPI WINBOOL WINAPI Global_జ్ఞాపకం_స్థితి_Ex(LPMEMORYSTATUSEX lp_బఫరు);
  WINBASEAPI HLOCAL WINAPI LocalAlloc(UINT uFlags,కొలత_T u_బైట్లు);
  WINBASEAPI HLOCAL WINAPI LocalReAlloc(HLOCAL hMem,కొలత_T u_బైట్లు,UINT uFlags);
  WINBASEAPI LPVOID WINAPI Local_తాళం(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalHandle(LPCVOID pMem);
  WINBASEAPI WINBOOL WINAPI LocalUnlock(HLOCAL hMem);
  WINBASEAPI కొలత_T WINAPI Local_కొలత(HLOCAL hMem);
  WINBASEAPI UINT WINAPI LocalFlags(HLOCAL hMem);
  WINBASEAPI HLOCAL WINAPI LocalFree(HLOCAL hMem);
  WINBASEAPI కొలత_T WINAPI LocalShrink(HLOCAL hMem,UINT cb_New_కొలత);
  WINBASEAPI కొలత_T WINAPI LocalCompact(UINT uMinFree);
  WINBASEAPI WINBOOL WINAPI FlushInstructionCache(HANDLE hProcess,LPCVOID lp_పునాది_చిరునామా,కొలత_T dw_కొలత);
  WINBASEAPI LPVOID WINAPI VirtualAlloc(LPVOID lp_చిరునామా,కొలత_T dw_కొలత,DWORD fl_కేటాయింపు_Type,DWORD flProtect);
  WINBASEAPI WINBOOL WINAPI VirtualFree(LPVOID lp_చిరునామా,కొలత_T dw_కొలత,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtect(LPVOID lp_చిరునామా,కొలత_T dw_కొలత,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI కొలత_T WINAPI VirtualQuery(LPCVOID lp_చిరునామా,PMEMORY_BASIC_INFORMATION lp_బఫరు,కొలత_T dw_నిడివి);
  WINBASEAPI LPVOID WINAPI VirtualAllocEx(HANDLE hProcess,LPVOID lp_చిరునామా,కొలత_T dw_కొలత,DWORD fl_కేటాయింపు_Type,DWORD flProtect);
  WINBASEAPI UINT WINAPI GetWriteWatch(DWORD dwFlags,PVOID lp_పునాది_చిరునామా,కొలత_T dw_Region_కొలత,PVOID *lp_చిరునామాలు,ULONG_PTR *lpdw_లెక్క,PULONG lpdwGranularity);
  WINBASEAPI UINT WINAPI ResetWriteWatch(LPVOID lp_పునాది_చిరునామా,కొలత_T dw_Region_కొలత);
  WINBASEAPI కొలత_T WINAPI Get_Large_పుట_Minimum(VOID);
  WINBASEAPI UINT WINAPI EnumSystemFirmwareTables(DWORD Firmware_పట్టిక_Provider_Signature,PVOID p_Firmware_పట్టిక_Enum_బఫరు,DWORD బఫరు_కొలత);
  WINBASEAPI UINT WINAPI Get_System_Firmware_పట్టిక(DWORD Firmware_పట్టిక_Provider_Signature,DWORD Firmware_పట్టిక_ID,PVOID p_Firmware_పట్టిక_బఫరు,DWORD బఫరు_కొలత);
  WINBASEAPI WINBOOL WINAPI VirtualFreeEx(HANDLE hProcess,LPVOID lp_చిరునామా,కొలత_T dw_కొలత,DWORD dwFreeType);
  WINBASEAPI WINBOOL WINAPI VirtualProtectEx(HANDLE hProcess,LPVOID lp_చిరునామా,కొలత_T dw_కొలత,DWORD flNewProtect,PDWORD lpflOldProtect);
  WINBASEAPI కొలత_T WINAPI VirtualQueryEx(HANDLE hProcess,LPCVOID lp_చిరునామా,PMEMORY_BASIC_INFORMATION lp_బఫరు,కొలత_T dw_నిడివి);
  WINBASEAPI HANDLE WINAPI కుప్ప_Create(DWORD flOptions,కొలత_T dw_Initial_కొలత,కొలత_T dw_గరిష్ఠ_కొలత);
  WINBASEAPI WINBOOL WINAPI కుప్ప_Destroy(HANDLE h_కుప్ప);
  WINBASEAPI LPVOID WINAPI కుప్ప_Alloc(HANDLE h_కుప్ప,DWORD dwFlags,కొలత_T dw_బైట్లు);
  WINBASEAPI LPVOID WINAPI కుప్ప_Re_Alloc(HANDLE h_కుప్ప,DWORD dwFlags,LPVOID lpMem,కొలత_T dw_బైట్లు);
  WINBASEAPI WINBOOL WINAPI కుప్ప_Free(HANDLE h_కుప్ప,DWORD dwFlags,LPVOID lpMem);
  WINBASEAPI కొలత_T WINAPI కుప్ప_కొలత(HANDLE h_కుప్ప,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI WINBOOL WINAPI కుప్ప_Validate(HANDLE h_కుప్ప,DWORD dwFlags,LPCVOID lpMem);
  WINBASEAPI కొలత_T WINAPI కుప్ప_Compact(HANDLE h_కుప్ప,DWORD dwFlags);
  WINBASEAPI HANDLE WINAPI Get_Process_కుప్ప(VOID);
  WINBASEAPI DWORD WINAPI GetProcessHeaps(DWORD సంఖ్య_యొక్క_Heaps,PHANDLE ProcessHeaps);

  రకనిర్వచనం నిర్మాణం PROCESS_కుప్ప_నమోదు {
    PVOID lp_దత్తాంశం;
    DWORD cb_దత్తాంశం;
    BYTE cbOverhead;
    BYTE i_Region_సూచీ;
    మాట_3 wFlags;
    సంఘం {
      నిర్మాణం {
	HANDLE hMem;
	DWORD dwReserved[3];
      } ఖండం_2;
      నిర్మాణం {
	DWORD dw_Committed_కొలత;
	DWORD dw_Un_Committed_కొలత;
	LPVOID lp_మొదటి_ఖండం;
	LPVOID lp_చివరి_ఖండం;
      } Region;
    };
  } PROCESS_కుప్ప_నమోదు_2,*LPPROCESS_కుప్ప_నమోదు,*PPROCESS_కుప్ప_నమోదు;

#నిర్వచించు PROCESS_కుప్ప_REGION 0x1
#నిర్వచించు PROCESS_కుప్ప_UNCOMMITTED_RANGE 0x2
#నిర్వచించు PROCESS_కుప్ప_నమోదు_BUSY 0x4
#నిర్వచించు PROCESS_కుప్ప_నమోదు_MOVEABLE 0x10
#నిర్వచించు PROCESS_కుప్ప_నమోదు_DDESHARE 0x20

  WINBASEAPI WINBOOL WINAPI కుప్ప_తాళం(HANDLE h_కుప్ప);
  WINBASEAPI WINBOOL WINAPI కుప్ప_Unlock(HANDLE h_కుప్ప);
  WINBASEAPI WINBOOL WINAPI కుప్ప_Walk(HANDLE h_కుప్ప,LPPROCESS_కుప్ప_నమోదు lp_నమోదు);
  WINBASEAPI WINBOOL WINAPI కుప్ప_సమితి_Information(HANDLE కుప్ప_Handle,కుప్ప_INFORMATION_CLASS కుప్ప_Information_Class,PVOID కుప్ప_Information,కొలత_T కుప్ప_Information_నిడివి);
  WINBASEAPI WINBOOL WINAPI కుప్ప_Query_Information(HANDLE కుప్ప_Handle,కుప్ప_INFORMATION_CLASS కుప్ప_Information_Class,PVOID కుప్ప_Information,కొలత_T కుప్ప_Information_నిడివి,PSIZE_T Return_నిడివి);

#నిర్వచించు SCS_32_బిట్టు_ద్విమాన 0
#నిర్వచించు SCS_DOS_ద్విమాన 1
#నిర్వచించు SCS_WOW_ద్విమాన 2
#నిర్వచించు SCS_PIF_ద్విమాన 3
#నిర్వచించు SCS_POSIX_ద్విమాన 4
#నిర్వచించు SCS_OS216_ద్విమాన 5
#నిర్వచించు SCS_64_బిట్టు_ద్విమాన 6

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_ద్విమాన_Type Get_ద్విమాన_Type_W
#నిర్వచించు Get_Short_మార్గం_Name Get_Short_మార్గం_Name_W
#నిర్వచించు Get_Long_మార్గం_Name Get_Long_మార్గం_Name_W
#నిర్వచించు Get_Environment_అక్షరశ్రేణులు Get_Environment_అక్షరశ్రేణులు_W
#నిర్వచించు సమితి_Environment_అక్షరశ్రేణులు సమితి_Environment_అక్షరశ్రేణులు_W
#నిర్వచించు Free_Environment_అక్షరశ్రేణులు Free_Environment_అక్షరశ్రేణులు_W
#లేకపోతే
#నిర్వచించు Get_ద్విమాన_Type Get_ద్విమాన_Type_A
#నిర్వచించు Get_Short_మార్గం_Name Get_Short_మార్గం_Name_A
#నిర్వచించు Get_Long_మార్గం_Name Get_Long_మార్గం_Name_A
#నిర్వచించు Get_Environment_అక్షరశ్రేణులు_A Get_Environment_అక్షరశ్రేణులు
#నిర్వచించు సమితి_Environment_అక్షరశ్రేణులు సమితి_Environment_అక్షరశ్రేణులు_A
#నిర్వచించు Free_Environment_అక్షరశ్రేణులు Free_Environment_అక్షరశ్రేణులు_A
#అయితే_ముగింపు

#నిర్వచితమైతే _WIN64
#నిర్వచించు SCS_THIS_PLATFORM_ద్విమాన SCS_64_బిట్టు_ద్విమాన
#లేకపోతే
#నిర్వచించు SCS_THIS_PLATFORM_ద్విమాన SCS_32_బిట్టు_ద్విమాన
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI Get_ద్విమాన_Type_A(LPCSTR lpApplicationName,LPDWORD lp_ద్విమాన_Type);
  WINBASEAPI WINBOOL WINAPI Get_ద్విమాన_Type_W(LPCWSTR lpApplicationName,LPDWORD lp_ద్విమాన_Type);
  WINBASEAPI DWORD WINAPI Get_Short_మార్గం_Name_A(LPCSTR lpsz_Long_మార్గం,LPSTR lpsz_Short_మార్గం,DWORD cch_బఫరు);
  WINBASEAPI DWORD WINAPI Get_Short_మార్గం_Name_W(LPCWSTR lpsz_Long_మార్గం,LPWSTR lpsz_Short_మార్గం,DWORD cch_బఫరు);
  WINBASEAPI DWORD WINAPI Get_Long_మార్గం_Name_A(LPCSTR lpsz_Short_మార్గం,LPSTR lpsz_Long_మార్గం,DWORD cch_బఫరు);
  WINBASEAPI DWORD WINAPI Get_Long_మార్గం_Name_W(LPCWSTR lpsz_Short_మార్గం,LPWSTR lpsz_Long_మార్గం,DWORD cch_బఫరు);
  WINBASEAPI WINBOOL WINAPI Get_Process_Affinity_ముసుగు(HANDLE hProcess,PDWORD_PTR lp_Process_Affinity_ముసుగు,PDWORD_PTR lp_System_Affinity_ముసుగు);
  WINBASEAPI WINBOOL WINAPI సమితి_Process_Affinity_ముసుగు(HANDLE hProcess,DWORD_PTR dw_Process_Affinity_ముసుగు);
  WINBASEAPI WINBOOL WINAPI Get_Process_Handle_లెక్క(HANDLE hProcess,PDWORD pdw_Handle_లెక్క);
  WINBASEAPI WINBOOL WINAPI GetProcessTimes(HANDLE hProcess,LPFILETIME lp_Creation_సమయం,LPFILETIME lp_Exit_సమయం,LPFILETIME lp_Kernel_సమయం,LPFILETIME lp_User_సమయం);
  WINBASEAPI WINBOOL WINAPI GetProcessIoCounters(HANDLE hProcess,PIO_COUNTERS lpIoCounters);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_సమితి_కొలత(HANDLE hProcess,PSIZE_T lp_Minimum_Working_సమితి_కొలత,PSIZE_T lp_గరిష్ఠ_Working_సమితి_కొలత);
  WINBASEAPI WINBOOL WINAPI Get_Process_Working_సమితి_కొలత_Ex(HANDLE hProcess,PSIZE_T lp_Minimum_Working_సమితి_కొలత,PSIZE_T lp_గరిష్ఠ_Working_సమితి_కొలత,PDWORD Flags);
  WINBASEAPI WINBOOL WINAPI సమితి_Process_Working_సమితి_కొలత(HANDLE hProcess,కొలత_T dw_Minimum_Working_సమితి_కొలత,కొలత_T dw_గరిష్ఠ_Working_సమితి_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Process_Working_సమితి_కొలత_Ex(HANDLE hProcess,కొలత_T dw_Minimum_Working_సమితి_కొలత,కొలత_T dw_గరిష్ఠ_Working_సమితి_కొలత,DWORD Flags);
  WINBASEAPI HANDLE WINAPI OpenProcess(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwProcessId);
  WINBASEAPI HANDLE WINAPI GetCurrentProcess(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentProcessId(VOID);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitProcess(UINT u_Exit_సంకేతం);
  WINBASEAPI WINBOOL WINAPI TerminateProcess(HANDLE hProcess,UINT u_Exit_సంకేతం);
  WINBASEAPI WINBOOL WINAPI Get_Exit_సంకేతం_Process(HANDLE hProcess,LPDWORD lp_Exit_సంకేతం);
  WINBASEAPI VOID WINAPI FatalExit(పూర్ణాంకం Exit_సంకేతం);
  /*	WINBASEAPI LPCH WINAPI GetEnvironmentStrings(VOID); */
  WINBASEAPI LPWCH WINAPI Get_Environment_అక్షరశ్రేణులు_W(VOID);
  WINBASEAPI WINBOOL WINAPI సమితి_Environment_అక్షరశ్రేణులు_A(LPCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI సమితి_Environment_అక్షరశ్రేణులు_W(LPWCH NewEnvironment);
  WINBASEAPI WINBOOL WINAPI Free_Environment_అక్షరశ్రేణులు_A(LPCH);
  WINBASEAPI WINBOOL WINAPI Free_Environment_అక్షరశ్రేణులు_W(LPWCH);
  WINBASEAPI VOID WINAPI RaiseException(DWORD dw_Exception_సంకేతం,DWORD dwExceptionFlags,DWORD n_సంఖ్య_యొక్క_Arguments,CONST ULONG_PTR *lpArguments);
  WINBASEAPI LONG WINAPI UnhandledExceptionFilter(నిర్మాణం EXCEPTION_సూచికలు_2 *ExceptionInfo);

  రకనిర్వచనం LONG (WINAPI *PTOP_LEVEL_EXCEPTION_FILTER)(నిర్మాణం EXCEPTION_సూచికలు_2 *ExceptionInfo);
  రకనిర్వచనం PTOP_LEVEL_EXCEPTION_FILTER LPTOP_LEVEL_EXCEPTION_FILTER;

  WINBASEAPI LPTOP_LEVEL_EXCEPTION_FILTER WINAPI సమితి_Unhandled_Exception_Filter(LPTOP_LEVEL_EXCEPTION_FILTER lp_శిఖరం_Level_Exception_Filter);

#నిర్వచించు FIBER_FLAG_FLOAT_SWITCH 0x1

  WINBASEAPI LPVOID WINAPI CreateFiber(కొలత_T dw_దొంతర_కొలత,LPFIBER_ప్రారంభం_ROUTINE lp_ప్రారంభం_చిరునామా,LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI CreateFiberEx(కొలత_T dw_దొంతర_Commit_కొలత,కొలత_T dw_దొంతర_Reserve_కొలత,DWORD dwFlags,LPFIBER_ప్రారంభం_ROUTINE lp_ప్రారంభం_చిరునామా,LPVOID lpParameter);
  WINBASEAPI VOID WINAPI DeleteFiber(LPVOID lpFiber);
  WINBASEAPI LPVOID WINAPI Convert_Thread_గమ్యం_Fiber(LPVOID lpParameter);
  WINBASEAPI LPVOID WINAPI Convert_Thread_గమ్యం_Fiber_Ex(LPVOID lpParameter,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Convert_Fiber_గమ్యం_Thread(VOID);
  WINBASEAPI VOID WINAPI Switch_గమ్యం_Fiber(LPVOID lpFiber);
  WINBASEAPI WINBOOL WINAPI Switch_గమ్యం_Thread(VOID);
  WINBASEAPI HANDLE WINAPI CreateThread(LPSECURITY_లక్షణాలు lp_Thread_లక్షణాలు,కొలత_T dw_దొంతర_కొలత,LPTHREAD_ప్రారంభం_ROUTINE lp_ప్రారంభం_చిరునామా,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI CreateRemoteThread(HANDLE hProcess,LPSECURITY_లక్షణాలు lp_Thread_లక్షణాలు,కొలత_T dw_దొంతర_కొలత,LPTHREAD_ప్రారంభం_ROUTINE lp_ప్రారంభం_చిరునామా,LPVOID lpParameter,DWORD dwCreationFlags,LPDWORD lpThreadId);
  WINBASEAPI HANDLE WINAPI GetCurrentThread(VOID);
  WINBASEAPI DWORD WINAPI GetCurrentThreadId(VOID);
  WINBASEAPI WINBOOL WINAPI సమితి_Thread_దొంతర_Guarantee (PULONG దొంతర_కొలత_లోపల_బైట్లు);
  WINBASEAPI DWORD WINAPI Get_Process_Id_యొక్క_Thread(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetThreadId(HANDLE Thread);
  WINBASEAPI DWORD WINAPI GetProcessId(HANDLE Process);
  WINBASEAPI DWORD WINAPI Get_Current_Processor_సంఖ్య(VOID);
  WINBASEAPI DWORD_PTR WINAPI సమితి_Thread_Affinity_ముసుగు(HANDLE hThread,DWORD_PTR dw_Thread_Affinity_ముసుగు);
  WINBASEAPI DWORD WINAPI సమితి_Thread_Ideal_Processor(HANDLE hThread,DWORD dwIdealProcessor);
  WINBASEAPI WINBOOL WINAPI సమితి_Process_ప్రాధాన్యత_Boost(HANDLE hProcess,WINBOOL b_Disable_ప్రాధాన్యత_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Process_ప్రాధాన్యత_Boost(HANDLE hProcess,PBOOL p_Disable_ప్రాధాన్యత_Boost);
  WINBASEAPI WINBOOL WINAPI RequestWakeupLatency(LATENCY_సమయం latency);
  WINBASEAPI WINBOOL WINAPI IsSystemResumeAutomatic(VOID);
  WINBASEAPI HANDLE WINAPI OpenThread(DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwThreadId);
  WINBASEAPI WINBOOL WINAPI సమితి_Thread_ప్రాధాన్యత(HANDLE hThread,పూర్ణాంకం n_ప్రాధాన్యత);
  WINBASEAPI WINBOOL WINAPI సమితి_Thread_ప్రాధాన్యత_Boost(HANDLE hThread,WINBOOL b_Disable_ప్రాధాన్యత_Boost);
  WINBASEAPI WINBOOL WINAPI Get_Thread_ప్రాధాన్యత_Boost(HANDLE hThread,PBOOL p_Disable_ప్రాధాన్యత_Boost);
  WINBASEAPI పూర్ణాంకం WINAPI Get_Thread_ప్రాధాన్యత(HANDLE hThread);
  WINBASEAPI WINBOOL WINAPI GetThreadTimes(HANDLE hThread,LPFILETIME lp_Creation_సమయం,LPFILETIME lp_Exit_సమయం,LPFILETIME lp_Kernel_సమయం,LPFILETIME lp_User_సమయం);
  WINBASEAPI WINBOOL WINAPI GetThreadIOPendingFlag(HANDLE hThread,PBOOL lpIOIsPending);
  WINBASEAPI DECLSPEC_NORETURN VOID WINAPI ExitThread(DWORD dw_Exit_సంకేతం);
  WINBASEAPI WINBOOL WINAPI TerminateThread(HANDLE hThread,DWORD dw_Exit_సంకేతం);
  WINBASEAPI WINBOOL WINAPI Get_Exit_సంకేతం_Thread(HANDLE hThread,LPDWORD lp_Exit_సంకేతం);
  WINBASEAPI WINBOOL WINAPI Get_Thread_Selector_నమోదు(HANDLE hThread,DWORD dwSelector,LPLDT_నమోదు lp_Selector_నమోదు);
  WINBASEAPI EXECUTION_STATE WINAPI సమితి_Thread_Execution_State(EXECUTION_STATE esFlags);
  WINBASEAPI DWORD WINAPI Get_చివరి_Error(VOID);
  WINBASEAPI VOID WINAPI సమితి_చివరి_Error(DWORD dw_Err_సంకేతం);

#నిర్వచితం_కాకపోతే RC_INVOKED
#నిర్వచితమైతే WINBASE_DECLARE_RESTORE_చివరి_ERROR
  WINBASEAPI VOID WINAPI Restore_చివరి_Error(DWORD dw_Err_సంకేతం);

  రకనిర్వచనం VOID (WINAPI *PRESTORE_చివరి_ERROR)(DWORD);

#నిర్వచించు RESTORE_చివరి_ERROR_NAME_A "RestoreLastError"
#నిర్వచించు RESTORE_చివరి_ERROR_NAME_W L"RestoreLastError"
#నిర్వచించు RESTORE_చివరి_ERROR_NAME పాఠ్యం_3("RestoreLastError")
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు HasOverlappedIoCompleted(lpOverlapped) (((DWORD)(lpOverlapped)->అంతర్గత)!=స్థితి_PENDING)

  WINBASEAPI WINBOOL WINAPI Get_Overlapped_ఫలితం(HANDLE hFile,LPOVERLAPPED lpOverlapped,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Transferred,WINBOOL bWait);
  WINBASEAPI HANDLE WINAPI Create_Io_Completion_పోర్టు(HANDLE FileHandle,HANDLE Existing_Completion_పోర్టు,ULONG_PTR Completion_కీలకం,DWORD సంఖ్య_యొక్క_Concurrent_దారాలు);
  WINBASEAPI WINBOOL WINAPI Get_Queued_Completion_స్థితి(HANDLE Completion_పోర్టు,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Transferred,PULONG_PTR lp_Completion_కీలకం,LPOVERLAPPED *lpOverlapped,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI Post_Queued_Completion_స్థితి(HANDLE Completion_పోర్టు,DWORD dw_సంఖ్య_యొక్క_బైట్లు_Transferred,ULONG_PTR dw_Completion_కీలకం,LPOVERLAPPED lpOverlapped);

#నిర్వచించు SEM_FAILCRITICALERRORS 0x1
#నిర్వచించు SEM_NOGPFAULTERRORBOX 0x2
#నిర్వచించు SEM_NOALIGNMENTFAULTEXCEPT 0x4
#నిర్వచించు SEM_NOOPENFILEERRORBOX 0x8000

  WINBASEAPI UINT WINAPI సమితి_Error_బహుళకం(UINT u_బహుళకం);
  WINBASEAPI WINBOOL WINAPI Read_Process_జ్ఞాపకం(HANDLE hProcess,LPCVOID lp_పునాది_చిరునామా,LPVOID lp_బఫరు,కొలత_T n_కొలత,కొలత_T *lp_సంఖ్య_యొక్క_బైట్లు_Read);
  WINBASEAPI WINBOOL WINAPI Write_Process_జ్ఞాపకం(HANDLE hProcess,LPVOID lp_పునాది_చిరునామా,LPCVOID lp_బఫరు,కొలత_T n_కొలత,కొలత_T *lp_సంఖ్య_యొక్క_బైట్లు_Written);
  WINBASEAPI WINBOOL WINAPI GetThreadContext(HANDLE hThread,LPCONTEXT lpContext);
  WINBASEAPI WINBOOL WINAPI సమితి_Thread_Context(HANDLE hThread,CONST CONTEXT *lpContext);
  WINBASEAPI DWORD WINAPI SuspendThread(HANDLE hThread);
  WINBASEAPI DWORD WINAPI ResumeThread(HANDLE hThread);

  రకనిర్వచనం VOID (WINAPI *PAPCFUNC)(ULONG_PTR dwParam);

  WINBASEAPI DWORD WINAPI వరుస_User_APC(PAPCFUNC pfnAPC,HANDLE hThread,ULONG_PTR dw_దత్తాంశం);
  WINBASEAPI WINBOOL WINAPI IsDebuggerPresent(VOID);
  WINBASEAPI WINBOOL WINAPI CheckRemoteDebuggerPresent(HANDLE hProcess,PBOOL pbDebuggerPresent);
  WINBASEAPI VOID WINAPI DebugBreak(VOID);
  WINBASEAPI WINBOOL WINAPI WaitForDebugEvent(LPDEBUG_EVENT lpDebugEvent,DWORD dwMilliseconds);
  WINBASEAPI WINBOOL WINAPI ContinueDebugEvent(DWORD dwProcessId,DWORD dwThreadId,DWORD dw_Continue_స్థితి);
  WINBASEAPI WINBOOL WINAPI Debug_చురుకైన_Process(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_చురుకైన_Process_Stop(DWORD dwProcessId);
  WINBASEAPI WINBOOL WINAPI Debug_సమితి_Process_Kill_On_Exit(WINBOOL KillOnExit);
  WINBASEAPI WINBOOL WINAPI DebugBreakProcess(HANDLE Process);
  WINBASEAPI VOID WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI Initialize_Critical_Section_And_Spin_లెక్క(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_లెక్క);
  WINBASEAPI DWORD WINAPI సమితి_Critical_Section_Spin_లెక్క(LPCRITICAL_SECTION lpCriticalSection,DWORD dw_Spin_లెక్క);
  WINBASEAPI WINBOOL WINAPI TryEnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI VOID WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
  WINBASEAPI WINBOOL WINAPI సమితి_Event(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ResetEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI PulseEvent(HANDLE hEvent);
  WINBASEAPI WINBOOL WINAPI ReleaseSemaphore(HANDLE hSemaphore,LONG l_Release_లెక్క,LPLONG lp_మునుపటి_లెక్క);
  WINBASEAPI WINBOOL WINAPI ReleaseMutex(HANDLE hMutex);
  WINBASEAPI DWORD WINAPI WaitForSingleObject(HANDLE hHandle,DWORD dwMilliseconds);
  WINBASEAPI DWORD WINAPI Wait_For_గుణిజం_Objects(DWORD n_లెక్క,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds);
  WINBASEAPI VOID WINAPI Sleep(DWORD dwMilliseconds);
  WINBASEAPI HGLOBAL WINAPI ఎక్కించు_Resource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI DWORD WINAPI SizeofResource(HMODULE hModule,HRSRC hResInfo);
  WINBASEAPI ATOM WINAPI GlobalDeleteAtom(ATOM nAtom);
  WINBASEAPI WINBOOL WINAPI Init_Atom_పట్టిక(DWORD n_కొలత);
  WINBASEAPI ATOM WINAPI DeleteAtom(ATOM nAtom);
  WINBASEAPI UINT WINAPI సమితి_Handle_లెక్క(UINT u_సంఖ్య);
  WINBASEAPI DWORD WINAPI GetLogicalDrives(VOID);
  WINBASEAPI WINBOOL WINAPI తాళం_File(HANDLE hFile,DWORD dw_File_స్థానభ్రంశం_దిగువ,DWORD dw_File_స్థానభ్రంశం_ఎగువ,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_తాళం_దిగువ,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_తాళం_ఎగువ);
  WINBASEAPI WINBOOL WINAPI UnlockFile(HANDLE hFile,DWORD dw_File_స్థానభ్రంశం_దిగువ,DWORD dw_File_స్థానభ్రంశం_ఎగువ,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Unlock_దిగువ,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Unlock_ఎగువ);
  WINBASEAPI WINBOOL WINAPI తాళం_File_Ex(HANDLE hFile,DWORD dwFlags,DWORD dwReserved,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_తాళం_దిగువ,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_తాళం_ఎగువ,LPOVERLAPPED lpOverlapped);

#నిర్వచించు LOCKFILE_FAIL_IMMEDIATELY 0x1
#నిర్వచించు LOCKFILE_EXCLUSIVE_తాళం 0x2

  WINBASEAPI WINBOOL WINAPI UnlockFileEx(HANDLE hFile,DWORD dwReserved,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Unlock_దిగువ,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Unlock_ఎగువ,LPOVERLAPPED lpOverlapped);

  రకనిర్వచనం నిర్మాణం _BY_HANDLE_FILE_INFORMATION {
    DWORD dw_File_లక్షణాలు;
    FILETIME ft_Creation_సమయం;
    FILETIME ft_చివరి_Access_సమయం;
    FILETIME ft_చివరి_Write_సమయం;
    DWORD dw_Volume_Serial_సంఖ్య;
    DWORD n_File_కొలత_ఎగువ;
    DWORD n_File_కొలత_దిగువ;
    DWORD n_సంఖ్య_యొక్క_Links;
    DWORD n_File_సూచీ_ఎగువ;
    DWORD n_File_సూచీ_దిగువ;
  } BY_HANDLE_FILE_INFORMATION,*PBY_HANDLE_FILE_INFORMATION,*LPBY_HANDLE_FILE_INFORMATION;

#నిర్వచితమైతే UNICODE
#నిర్వచించు సమితి_File_Short_Name సమితి_File_Short_Name_W
#లేకపోతే
#నిర్వచించు సమితి_File_Short_Name సమితి_File_Short_Name_A
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile,LPBY_HANDLE_FILE_INFORMATION lpFileInformation);
  WINBASEAPI DWORD WINAPI GetFileType(HANDLE hFile);
  WINBASEAPI DWORD WINAPI Get_File_కొలత(HANDLE hFile,LPDWORD lp_File_కొలత_ఎగువ);
  WINBASEAPI WINBOOL WINAPI Get_File_కొలత_Ex(HANDLE hFile,PLARGE_INTEGER lp_File_కొలత);
  WINBASEAPI HANDLE WINAPI GetStdHandle(DWORD nStdHandle);
  WINBASEAPI WINBOOL WINAPI సమితి_Std_Handle(DWORD nStdHandle,HANDLE hHandle);
  WINBASEAPI WINBOOL WINAPI WriteFile(HANDLE hFile,LPCVOID lp_బఫరు,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Write,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Written,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI ReadFile(HANDLE hFile,LPVOID lp_బఫరు,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Read,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI FlushFileBuffers(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI DeviceIoControl(HANDLE hDevice,DWORD dw_Io_Control_సంకేతం,LPVOID lp_లోపల_బఫరు,DWORD n_లోపల_బఫరు_కొలత,LPVOID lp_బహిర్గతం_బఫరు,DWORD n_బహిర్గతం_బఫరు_కొలత,LPDWORD lp_బైట్లు_Returned,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI RequestDeviceWakeup(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI CancelDeviceWakeupRequest(HANDLE hDevice);
  WINBASEAPI WINBOOL WINAPI GetDevicePowerState(HANDLE hDevice,WINBOOL *pfOn);
  WINBASEAPI WINBOOL WINAPI సమితి_సందేశం_నిరీక్షణ_Indicator(HANDLE h_సందేశం_Indicator,ULONG ul_సందేశం_లెక్క);
  WINBASEAPI WINBOOL WINAPI సమితి_చివర_యొక్క_File(HANDLE hFile);
  WINBASEAPI DWORD WINAPI సమితి_File_సూచిక(HANDLE hFile,LONG l_దూరం_గమ్యం_Move,PLONG lp_దూరం_గమ్యం_Move_ఎగువ,DWORD dw_Move_పద్ధతి);
  WINBASEAPI WINBOOL WINAPI సమితి_File_సూచిక_Ex(HANDLE hFile,LARGE_INTEGER li_దూరం_గమ్యం_Move,PLARGE_INTEGER lp_New_File_సూచిక,DWORD dw_Move_పద్ధతి);
  WINBASEAPI WINBOOL WINAPI కనుగొను_Close(HANDLE h_కనుగొను_File);
  WINBASEAPI WINBOOL WINAPI Get_File_సమయం(HANDLE hFile,LPFILETIME lp_Creation_సమయం,LPFILETIME lp_చివరి_Access_సమయం,LPFILETIME lp_చివరి_Write_సమయం);
  WINBASEAPI WINBOOL WINAPI సమితి_File_సమయం(HANDLE hFile,CONST FILETIME *lp_Creation_సమయం,CONST FILETIME *lp_చివరి_Access_సమయం,CONST FILETIME *lp_చివరి_Write_సమయం);
  WINBASEAPI WINBOOL WINAPI సమితి_File_Valid_దత్తాంశం(HANDLE hFile,LONGLONG Valid_దత్తాంశం_నిడివి);
  WINBASEAPI WINBOOL WINAPI సమితి_File_Short_Name_A(HANDLE hFile,LPCSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI సమితి_File_Short_Name_W(HANDLE hFile,LPCWSTR lpShortName);
  WINBASEAPI WINBOOL WINAPI CloseHandle(HANDLE hObject);
  WINBASEAPI WINBOOL WINAPI DuplicateHandle(HANDLE h_ఆధారం_Process_Handle,HANDLE h_ఆధారం_Handle,HANDLE h_లక్ష్యం_Process_Handle,LPHANDLE lp_లక్ష్యం_Handle,DWORD dwDesiredAccess,WINBOOL bInheritHandle,DWORD dwOptions);
  WINBASEAPI WINBOOL WINAPI GetHandleInformation(HANDLE hObject,LPDWORD lpdwFlags);
  WINBASEAPI WINBOOL WINAPI సమితి_Handle_Information(HANDLE hObject,DWORD dw_ముసుగు,DWORD dwFlags);

#నిర్వచించు HANDLE_FLAG_INHERIT 0x1
#నిర్వచించు HANDLE_FLAG_PROTECT_FROM_CLOSE 0x2

#నిర్వచించు HINSTANCE_ERROR 32

  WINBASEAPI DWORD WINAPI ఎక్కించు_Module(LPCSTR lpModuleName,LPVOID lp_Parameter_ఖండం);
  WINBASEAPI UINT WINAPI WinExec(LPCSTR lp_Cmd_పంక్తి,UINT uCmdShow);
  WINBASEAPI WINBOOL WINAPI ClearCommBreak(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI ClearCommError(HANDLE hFile,LPDWORD lpErrors,LPCOMSTAT lpStat);
  WINBASEAPI WINBOOL WINAPI అమరిక_Comm(HANDLE hFile,DWORD dw_లోపల_వరుస,DWORD dw_బహిర్గతం_వరుస);
  WINBASEAPI WINBOOL WINAPI EscapeCommFunction(HANDLE hFile,DWORD dwFunc);
  WINBASEAPI WINBOOL WINAPI GetCommConfig(HANDLE hCommDev,LPCOMMCONFIG lpCC,LPDWORD lpdw_కొలత);
  WINBASEAPI WINBOOL WINAPI Get_Comm_ముసుగు(HANDLE hFile,LPDWORD lp_Evt_ముసుగు);
  WINBASEAPI WINBOOL WINAPI GetCommProperties(HANDLE hFile,LPCOMMPROP lpCommProp);
  WINBASEAPI WINBOOL WINAPI Get_Comm_Modem_స్థితి(HANDLE hFile,LPDWORD lpModemStat);
  WINBASEAPI WINBOOL WINAPI GetCommState(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI GetCommTimeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI PurgeComm(HANDLE hFile,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI సమితి_Comm_Break(HANDLE hFile);
  WINBASEAPI WINBOOL WINAPI సమితి_Comm_Config(HANDLE hCommDev,LPCOMMCONFIG lpCC,DWORD dw_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Comm_ముసుగు(HANDLE hFile,DWORD dw_Evt_ముసుగు);
  WINBASEAPI WINBOOL WINAPI సమితి_Comm_State(HANDLE hFile,LPDCB lpDCB);
  WINBASEAPI WINBOOL WINAPI సమితి_Comm_Timeouts(HANDLE hFile,LPCOMMTIMEOUTS lpCommTimeouts);
  WINBASEAPI WINBOOL WINAPI TransmitCommChar(HANDLE hFile,అక్షరం cChar);
  WINBASEAPI WINBOOL WINAPI WaitCommEvent(HANDLE hFile,LPDWORD lp_Evt_ముసుగు,LPOVERLAPPED lpOverlapped);
  WINBASEAPI DWORD WINAPI సమితి_పట్టీ_Position(HANDLE hDevice,DWORD dw_Position_పద్ధతి,DWORD dw_విభజన,DWORD dw_స్థానభ్రంశం_దిగువ,DWORD dw_స్థానభ్రంశం_ఎగువ,WINBOOL b_తక్షణ);
  WINBASEAPI DWORD WINAPI Get_పట్టీ_Position(HANDLE hDevice,DWORD dwPositionType,LPDWORD lpdw_విభజన,LPDWORD lpdw_స్థానభ్రంశం_దిగువ,LPDWORD lpdw_స్థానభ్రంశం_ఎగువ);
  WINBASEAPI DWORD WINAPI Prepare_పట్టీ(HANDLE hDevice,DWORD dwOperation,WINBOOL b_తక్షణ);
  WINBASEAPI DWORD WINAPI Erase_పట్టీ(HANDLE hDevice,DWORD dwEraseType,WINBOOL b_తక్షణ);
  WINBASEAPI DWORD WINAPI Create_పట్టీ_విభజన(HANDLE hDevice,DWORD dw_విభజన_పద్ధతి,DWORD dw_లెక్క,DWORD dw_కొలత);
  WINBASEAPI DWORD WINAPI WriteTapemark(HANDLE hDevice,DWORD dwTapemarkType,DWORD dw_Tapemark_లెక్క,WINBOOL b_తక్షణ);
  WINBASEAPI DWORD WINAPI Get_పట్టీ_స్థితి(HANDLE hDevice);
  WINBASEAPI DWORD WINAPI Get_పట్టీ_Parameters(HANDLE hDevice,DWORD dwOperation,LPDWORD lpdw_కొలత,LPVOID lp_పట్టీ_Information);

#నిర్వచించు GET_పట్టీ_MEDIA_INFORMATION 0
#నిర్వచించు GET_పట్టీ_DRIVE_INFORMATION 1

  WINBASEAPI DWORD WINAPI సమితి_పట్టీ_Parameters(HANDLE hDevice,DWORD dwOperation,LPVOID lp_పట్టీ_Information);

#నిర్వచించు సమితి_పట్టీ_MEDIA_INFORMATION 0
#నిర్వచించు సమితి_పట్టీ_DRIVE_INFORMATION 1

  WINBASEAPI WINBOOL WINAPI Beep(DWORD dwFreq,DWORD dwDuration);
  WINBASEAPI పూర్ణాంకం WINAPI MulDiv(పూర్ణాంకం n_సంఖ్య,పూర్ణాంకం nNumerator,పూర్ణాంకం nDenominator);
  WINBASEAPI VOID WINAPI Get_System_సమయం(LPSYSTEMTIME lp_System_సమయం);
  WINBASEAPI VOID WINAPI Get_System_సమయం_As_File_సమయం(LPFILETIME lp_System_సమయం_As_File_సమయం);
  WINBASEAPI WINBOOL WINAPI సమితి_System_సమయం(CONST SYSTEMTIME *lp_System_సమయం);
  WINBASEAPI VOID WINAPI Get_Local_సమయం(LPSYSTEMTIME lp_System_సమయం);
  WINBASEAPI WINBOOL WINAPI సమితి_Local_సమయం(CONST SYSTEMTIME *lp_System_సమయం);
  WINBASEAPI VOID WINAPI GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI సమితి_System_File_Cache_కొలత(కొలత_T Minimum_File_Cache_కొలత,కొలత_T గరిష్ఠ_File_Cache_కొలత,DWORD Flags);
  WINBASEAPI WINBOOL WINAPI Get_System_File_Cache_కొలత(PSIZE_T lp_Minimum_File_Cache_కొలత,PSIZE_T lp_గరిష్ఠ_File_Cache_కొలత,PDWORD lpFlags);
  WINBASEAPI WINBOOL WINAPI GetSystemRegistryQuota(PDWORD pdwQuotaAllowed,PDWORD pdw_Quota_వాడిన);
  WINBOOL WINAPI GetSystemTimes(LPFILETIME lp_Idle_సమయం,LPFILETIME lp_Kernel_సమయం,LPFILETIME lp_User_సమయం);
  WINBASEAPI VOID WINAPI GetNativeSystemInfo(LPSYSTEM_INFO lpSystemInfo);
  WINBASEAPI WINBOOL WINAPI IsProcessorFeaturePresent(DWORD ProcessorFeature);

  రకనిర్వచనం నిర్మాణం సమయం_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[32];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[32];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
  } సమయం_ZONE_INFORMATION_2,*PTIME_ZONE_INFORMATION,*LPTIME_ZONE_INFORMATION;

#నిర్వచితమైతే UNICODE
#నిర్వచించు Format_సందేశం Format_సందేశం_W
#లేకపోతే
#నిర్వచించు Format_సందేశం Format_సందేశం_A
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI System_సమయం_గమ్యం_Tz_Specific_Local_సమయం(LPTIME_ZONE_INFORMATION lp_సమయం_Zone_Information,LPSYSTEMTIME lp_Universal_సమయం,LPSYSTEMTIME lp_Local_సమయం);
  WINBASEAPI WINBOOL WINAPI Tz_Specific_Local_సమయం_గమ్యం_System_సమయం(LPTIME_ZONE_INFORMATION lp_సమయం_Zone_Information,LPSYSTEMTIME lp_Local_సమయం,LPSYSTEMTIME lp_Universal_సమయం);
  WINBASEAPI DWORD WINAPI Get_సమయం_Zone_Information(LPTIME_ZONE_INFORMATION lp_సమయం_Zone_Information);
  WINBASEAPI WINBOOL WINAPI సమితి_సమయం_Zone_Information(CONST సమయం_ZONE_INFORMATION_2 *lp_సమయం_Zone_Information);
  WINBASEAPI WINBOOL WINAPI System_సమయం_గమ్యం_File_సమయం(CONST SYSTEMTIME *lp_System_సమయం,LPFILETIME lp_File_సమయం);
  WINBASEAPI WINBOOL WINAPI File_సమయం_గమ్యం_Local_File_సమయం(CONST FILETIME *lp_File_సమయం,LPFILETIME lp_Local_File_సమయం);
  WINBASEAPI WINBOOL WINAPI Local_File_సమయం_గమ్యం_File_సమయం(CONST FILETIME *lp_Local_File_సమయం,LPFILETIME lp_File_సమయం);
  WINBASEAPI WINBOOL WINAPI File_సమయం_గమ్యం_System_సమయం(CONST FILETIME *lp_File_సమయం,LPSYSTEMTIME lp_System_సమయం);
  WINBASEAPI LONG WINAPI Compare_File_సమయం(CONST FILETIME *lpFileTime1,CONST FILETIME *lpFileTime2);
  WINBASEAPI WINBOOL WINAPI File_సమయం_గమ్యం_Dos_Date_సమయం(CONST FILETIME *lp_File_సమయం,LPWORD lpFatDate,LPWORD lp_Fat_సమయం);
  WINBASEAPI WINBOOL WINAPI Dos_Date_సమయం_గమ్యం_File_సమయం(మాట_3 wFatDate,మాట_3 w_Fat_సమయం,LPFILETIME lp_File_సమయం);
  WINBASEAPI DWORD WINAPI Get_Tick_లెక్క(VOID);
  WINBASEAPI WINBOOL WINAPI సమితి_System_సమయం_Adjustment(DWORD dw_సమయం_Adjustment,WINBOOL b_సమయం_Adjustment_Disabled);
  WINBASEAPI WINBOOL WINAPI Get_System_సమయం_Adjustment(PDWORD lp_సమయం_Adjustment,PDWORD lp_సమయం_Increment,PBOOL lp_సమయం_Adjustment_Disabled);
  WINBASEAPI DWORD WINAPI Format_సందేశం_A(DWORD dwFlags,LPCVOID lp_ఆధారం,DWORD dw_సందేశం_Id,DWORD dwLanguageId,LPSTR lp_బఫరు,DWORD n_కొలత,va_list *Arguments);
  WINBASEAPI DWORD WINAPI Format_సందేశం_W(DWORD dwFlags,LPCVOID lp_ఆధారం,DWORD dw_సందేశం_Id,DWORD dwLanguageId,LPWSTR lp_బఫరు,DWORD n_కొలత,va_list *Arguments);

#నిర్వచించు FORMAT_సందేశం_ALLOCATE_బఫరు 0x100
#నిర్వచించు FORMAT_సందేశం_IGNORE_INSERTS 0x200
#నిర్వచించు FORMAT_సందేశం_FROM_STRING 0x400
#నిర్వచించు FORMAT_సందేశం_FROM_HMODULE 0x800
#నిర్వచించు FORMAT_సందేశం_FROM_SYSTEM 0x1000
#నిర్వచించు FORMAT_సందేశం_వాదం_ARRAY 0x2000
#నిర్వచించు FORMAT_సందేశం_MAX_వెడల్పు_ముసుగు 0xff

#నిర్వచితమైతే UNICODE
#నిర్వచించు CreateMailslot CreateMailslotW
#నిర్వచించు EncryptFile EncryptFileW
#నిర్వచించు DecryptFile DecryptFileW
#నిర్వచించు File_Encryption_స్థితి File_Encryption_స్థితి_W
#లేకపోతే
#నిర్వచించు CreateMailslot CreateMailslotA
#నిర్వచించు EncryptFile EncryptFileA
#నిర్వచించు DecryptFile DecryptFileA
#నిర్వచించు File_Encryption_స్థితి File_Encryption_స్థితి_A
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI CreatePipe(PHANDLE hReadPipe,PHANDLE hWritePipe,LPSECURITY_లక్షణాలు lp_Pipe_లక్షణాలు,DWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI ConnectNamedPipe(HANDLE hNamedPipe,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI DisconnectNamedPipe(HANDLE hNamedPipe);
  WINBASEAPI WINBOOL WINAPI సమితి_Named_Pipe_Handle_State(HANDLE hNamedPipe,LPDWORD lp_బహుళకం,LPDWORD lp_Max_Collection_లెక్క,LPDWORD lp_Collect_దత్తాంశం_Timeout);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeInfo(HANDLE hNamedPipe,LPDWORD lpFlags,LPDWORD lp_బహిర్గతం_బఫరు_కొలత,LPDWORD lp_లోపల_బఫరు_కొలత,LPDWORD lpMaxInstances);
  WINBASEAPI WINBOOL WINAPI PeekNamedPipe(HANDLE hNamedPipe,LPVOID lp_బఫరు,DWORD n_బఫరు_కొలత,LPDWORD lp_బైట్లు_Read,LPDWORD lp_మొత్తం_బైట్లు_Avail,LPDWORD lp_బైట్లు_ఎడమ_This_సందేశం);
  WINBASEAPI WINBOOL WINAPI TransactNamedPipe(HANDLE hNamedPipe,LPVOID lp_లోపల_బఫరు,DWORD n_లోపల_బఫరు_కొలత,LPVOID lp_బహిర్గతం_బఫరు,DWORD n_బహిర్గతం_బఫరు_కొలత,LPDWORD lp_బైట్లు_Read,LPOVERLAPPED lpOverlapped);
  WINBASEAPI HANDLE WINAPI CreateMailslotA(LPCSTR lpName,DWORD n_Max_సందేశం_కొలత,DWORD lReadTimeout,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINBASEAPI HANDLE WINAPI CreateMailslotW(LPCWSTR lpName,DWORD n_Max_సందేశం_కొలత,DWORD lReadTimeout,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI GetMailslotInfo(HANDLE hMailslot,LPDWORD lp_Max_సందేశం_కొలత,LPDWORD lp_తదుపరి_కొలత,LPDWORD lp_సందేశం_లెక్క,LPDWORD lpReadTimeout);
  WINBASEAPI WINBOOL WINAPI సమితి_Mailslot_Info(HANDLE hMailslot,DWORD lReadTimeout);
  WINBASEAPI LPVOID WINAPI Map_View_యొక్క_File(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_స్థానభ్రంశం_ఎగువ,DWORD dw_File_స్థానభ్రంశం_దిగువ,కొలత_T dw_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Map);
  WINBASEAPI WINBOOL WINAPI Flush_View_యొక్క_File(LPCVOID lp_పునాది_చిరునామా,కొలత_T dw_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Flush);
  WINBASEAPI WINBOOL WINAPI Unmap_View_యొక్క_File(LPCVOID lp_పునాది_చిరునామా);
  WINADVAPI WINBOOL WINAPI EncryptFileA(LPCSTR lpFileName);
  WINADVAPI WINBOOL WINAPI EncryptFileW(LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI DecryptFileA(LPCSTR lpFileName,DWORD dwReserved);
  WINADVAPI WINBOOL WINAPI DecryptFileW(LPCWSTR lpFileName,DWORD dwReserved);

#నిర్వచించు FILE_ENCRYPTABLE 0
#నిర్వచించు FILE_IS_ENCRYPTED 1
#నిర్వచించు FILE_SYSTEM_ATTR 2
#నిర్వచించు FILE_మూలం_DIR 3
#నిర్వచించు FILE_SYSTEM_DIR 4
#నిర్వచించు FILE_UNKNOWN 5
#నిర్వచించు FILE_SYSTEM_NOT_SUPPORT 6
#నిర్వచించు FILE_USER_DISALLOWED 7
#నిర్వచించు FILE_READ_ONLY 8
#నిర్వచించు FILE_DIR_DISALLOWED 9

  WINADVAPI WINBOOL WINAPI File_Encryption_స్థితి_A(LPCSTR lpFileName,LPDWORD lp_స్థితి);
  WINADVAPI WINBOOL WINAPI File_Encryption_స్థితి_W(LPCWSTR lpFileName,LPDWORD lp_స్థితి);

#నిర్వచించు EFS_USE_RECOVERY_కీలకాలు (0x1)

  రకనిర్వచనం DWORD (WINAPI *PFE_EXPORT_FUNC)(PBYTE pb_దత్తాంశం,PVOID pvCallbackContext,ULONG ul_నిడివి);
  రకనిర్వచనం DWORD (WINAPI *PFE_IMPORT_FUNC)(PBYTE pb_దత్తాంశం,PVOID pvCallbackContext,PULONG ul_నిడివి);

#నిర్వచించు CREATE_FOR_IMPORT (1)
#నిర్వచించు CREATE_FOR_DIR (2)
#నిర్వచించు OVERWRITE_HIDDEN (4)

#నిర్వచితమైతే UNICODE
#నిర్వచించు OpenEncryptedFileRaw OpenEncryptedFileRawW
#నిర్వచించు lstrcmp lstrcmpW
#నిర్వచించు lstrcmpi lstrcmpiW
#నిర్వచించు lstrcpyn lstrcpynW
#నిర్వచించు lstrcpy lstrcpyW
#నిర్వచించు lstrcat lstrcatW
#నిర్వచించు lstrlen lstrlenW
#లేకపోతే
#నిర్వచించు OpenEncryptedFileRaw OpenEncryptedFileRawA
#నిర్వచించు lstrcmp lstrcmpA
#నిర్వచించు lstrcmpi lstrcmpiA
#నిర్వచించు lstrcpyn lstrcpynA
#నిర్వచించు lstrcpy lstrcpyA
#నిర్వచించు lstrcat lstrcatA
#నిర్వచించు lstrlen lstrlenA
#అయితే_ముగింపు

  WINADVAPI DWORD WINAPI OpenEncryptedFileRawA(LPCSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI OpenEncryptedFileRawW(LPCWSTR lpFileName,ULONG ulFlags,PVOID *pvContext);
  WINADVAPI DWORD WINAPI ReadEncryptedFileRaw(PFE_EXPORT_FUNC pfExportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI DWORD WINAPI WriteEncryptedFileRaw(PFE_IMPORT_FUNC pfImportCallback,PVOID pvCallbackContext,PVOID pvContext);
  WINADVAPI VOID WINAPI CloseEncryptedFileRaw(PVOID pvContext);
  WINBASEAPI పూర్ణాంకం WINAPI lstrcmpA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI పూర్ణాంకం WINAPI lstrcmpW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI పూర్ణాంకం WINAPI lstrcmpiA(LPCSTR lpString1,LPCSTR lpString2);
  WINBASEAPI పూర్ణాంకం WINAPI lstrcmpiW(LPCWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcpynA(LPSTR lpString1,LPCSTR lpString2,పూర్ణాంకం i_Max_నిడివి);
  WINBASEAPI LPWSTR WINAPI lstrcpynW(LPWSTR lpString1,LPCWSTR lpString2,పూర్ణాంకం i_Max_నిడివి);
  WINBASEAPI LPSTR WINAPI lstrcpyA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcpyW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI LPSTR WINAPI lstrcatA(LPSTR lpString1,LPCSTR lpString2);
  WINBASEAPI LPWSTR WINAPI lstrcatW(LPWSTR lpString1,LPCWSTR lpString2);
  WINBASEAPI పూర్ణాంకం WINAPI lstrlenA(LPCSTR lpString);
  WINBASEAPI పూర్ణాంకం WINAPI lstrlenW(LPCWSTR lpString);
  WINBASEAPI HFILE WINAPI OpenFile(LPCSTR lpFileName,LPOFSTRUCT lpReOpenBuff,UINT uStyle);
  WINBASEAPI HFILE WINAPI _lopen(LPCSTR lp_మార్గం_Name,పూర్ణాంకం iReadWrite);
  WINBASEAPI HFILE WINAPI _lcreat(LPCSTR lp_మార్గం_Name,పూర్ణాంకం iAttribute);
  WINBASEAPI UINT WINAPI _lread(HFILE hFile,LPVOID lp_బఫరు,UINT u_బైట్లు);
  WINBASEAPI UINT WINAPI _lwrite(HFILE hFile,LPCCH lp_బఫరు,UINT u_బైట్లు);
  WINBASEAPI దీర్ఘ WINAPI _hread(HFILE hFile,LPVOID lp_బఫరు,దీర్ఘ l_బైట్లు);
  WINBASEAPI దీర్ఘ WINAPI _hwrite(HFILE hFile,LPCCH lp_బఫరు,దీర్ఘ l_బైట్లు);
  WINBASEAPI HFILE WINAPI _lclose(HFILE hFile);
  WINBASEAPI LONG WINAPI _llseek(HFILE hFile,LONG l_స్థానభ్రంశం,పూర్ణాంకం iOrigin);
  WINADVAPI WINBOOL WINAPI Is_పాఠ్యం_Unicode(CONST VOID *lpv,పూర్ణాంకం i_కొలత,LPINT lpi_ఫలితం);

#నిర్వచించు FLS_బహిర్గతం_యొక్క_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI FlsAlloc(PFLS_CALLBACK_FUNCTION lpCallback);
  WINBASEAPI PVOID WINAPI Fls_Get_విలువ(DWORD dw_Fls_సూచీ);
  WINBASEAPI WINBOOL WINAPI Fls_సమితి_విలువ(DWORD dw_Fls_సూచీ,PVOID lp_Fls_దత్తాంశం);
  WINBASEAPI WINBOOL WINAPI FlsFree(DWORD dw_Fls_సూచీ);

#నిర్వచించు TLS_బహిర్గతం_యొక్క_INDEXES ((DWORD)0xffffffff)

  WINBASEAPI DWORD WINAPI TlsAlloc(VOID);
  WINBASEAPI LPVOID WINAPI Tls_Get_విలువ(DWORD dw_Tls_సూచీ);
  WINBASEAPI WINBOOL WINAPI Tls_సమితి_విలువ(DWORD dw_Tls_సూచీ,LPVOID lp_Tls_విలువ);
  WINBASEAPI WINBOOL WINAPI TlsFree(DWORD dw_Tls_సూచీ);

  రకనిర్వచనం VOID (WINAPI *LPOVERLAPPED_COMPLETION_ROUTINE)(DWORD dw_Error_సంకేతం,DWORD dw_సంఖ్య_యొక్క_బైట్లు_Transfered,LPOVERLAPPED lpOverlapped);

  WINBASEAPI DWORD WINAPI SleepEx(DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI WaitForSingleObjectEx(HANDLE hHandle,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI Wait_For_గుణిజం_Objects_Ex(DWORD n_లెక్క,CONST HANDLE *lpHandles,WINBOOL bWaitAll,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI DWORD WINAPI SignalObjectAndWait(HANDLE h_Object_గమ్యం_Signal,HANDLE h_Object_గమ్యం_Wait_On,DWORD dwMilliseconds,WINBOOL bAlertable);
  WINBASEAPI WINBOOL WINAPI ReadFileEx(HANDLE hFile,LPVOID lp_బఫరు,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Read,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI WriteFileEx(HANDLE hFile,LPCVOID lp_బఫరు,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Write,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI BackupRead(HANDLE hFile,LPBYTE lp_బఫరు,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Read,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Read,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupSeek(HANDLE hFile,DWORD dw_దిగువ_బైట్లు_గమ్యం_Seek,DWORD dw_ఎగువ_బైట్లు_గమ్యం_Seek,LPDWORD lpdw_దిగువ_Byte_Seeked,LPDWORD lpdw_ఎగువ_Byte_Seeked,LPVOID *lpContext);
  WINBASEAPI WINBOOL WINAPI BackupWrite(HANDLE hFile,LPBYTE lp_బఫరు,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Write,LPDWORD lp_సంఖ్య_యొక్క_బైట్లు_Written,WINBOOL bAbort,WINBOOL bProcessSecurity,LPVOID *lpContext);

  రకనిర్వచనం నిర్మాణం WIN32_ప్రవాహం_ID {
    DWORD dw_ప్రవాహం_Id;
    DWORD dw_ప్రవాహం_లక్షణాలు;
    LARGE_INTEGER కొలత_3;
    DWORD dw_ప్రవాహం_Name_కొలత;
    WCHAR c_ప్రవాహం_Name[ANYSIZE_ARRAY];
  } WIN32_ప్రవాహం_ID_2,*LPWIN32_ప్రవాహం_ID;

#నిర్వచించు BACKUP_INVALID 0x0
#నిర్వచించు BACKUP_దత్తాంశం 0x1
#నిర్వచించు BACKUP_EA_దత్తాంశం 0x2
#నిర్వచించు BACKUP_SECURITY_దత్తాంశం 0x3
#నిర్వచించు BACKUP_ALTERNATE_దత్తాంశం 0x4
#నిర్వచించు BACKUP_LINK 0x5
#నిర్వచించు BACKUP_PROPERTY_దత్తాంశం 0x6
#నిర్వచించు BACKUP_OBJECT_ID 0x7
#నిర్వచించు BACKUP_REPARSE_దత్తాంశం 0x8
#నిర్వచించు BACKUP_SPARSE_ఖండం 0x9

#నిర్వచించు ప్రవాహం_సాధారణ_ATTRIBUTE 0x0
#నిర్వచించు ప్రవాహం_MODIFIED_WHEN_READ 0x1
#నిర్వచించు ప్రవాహం_కలిగియుంది_SECURITY 0x2
#నిర్వచించు ప్రవాహం_కలిగియుంది_PROPERTIES 0x4
#నిర్వచించు ప్రవాహం_SPARSE_ATTRIBUTE 0x8

  WINBASEAPI WINBOOL WINAPI ReadFileScatter(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Read,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);
  WINBASEAPI WINBOOL WINAPI WriteFileGather(HANDLE hFile,FILE_SEGMENT_ELEMENT aSegmentArray[],DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Write,LPDWORD lpReserved,LPOVERLAPPED lpOverlapped);

#నిర్వచించు STARTF_USESHOWWINDOW 0x1
#నిర్వచించు STARTF_USESIZE 0x2
#నిర్వచించు STARTF_USEPOSITION 0x4
#నిర్వచించు STARTF_USECOUNTCHARS 0x8
#నిర్వచించు STARTF_USEFILLATTRIBUTE 0x10
#నిర్వచించు STARTF_RUNFULLSCREEN 0x20
#నిర్వచించు STARTF_FORCEONFEEDBACK 0x40
#నిర్వచించు STARTF_FORCEOFFFEEDBACK 0x80
#నిర్వచించు STARTF_USESTDHANDLES 0x100

#నిర్వచించు STARTF_USEHOTKEY 0x200

  రకనిర్వచనం నిర్మాణం _STARTUPINFOA {
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
    మాట_3 w_Show_కిటికీ;
    మాట_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_ఆదానం;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOA,*LPSTARTUPINFOA;

  రకనిర్వచనం నిర్మాణం _STARTUPINFOW {
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
    మాట_3 w_Show_కిటికీ;
    మాట_3 cbReserved2;
    LPBYTE lpReserved2;
    HANDLE h_Std_ఆదానం;
    HANDLE hStdOutput;
    HANDLE hStdError;
  } STARTUPINFOW,*LPSTARTUPINFOW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం STARTUPINFOW STARTUPINFO;
  రకనిర్వచనం LPSTARTUPINFOW LPSTARTUPINFO;
#లేకపోతే
  రకనిర్వచనం STARTUPINFOA STARTUPINFO;
  రకనిర్వచనం LPSTARTUPINFOA LPSTARTUPINFO;
#అయితే_ముగింపు

#నిర్వచించు SHUTDOWN_NORETRY 0x1

  రకనిర్వచనం నిర్మాణం WIN32_కనుగొను_DATAA {
    DWORD dw_File_లక్షణాలు;
    FILETIME ft_Creation_సమయం;
    FILETIME ft_చివరి_Access_సమయం;
    FILETIME ft_చివరి_Write_సమయం;
    DWORD n_File_కొలత_ఎగువ;
    DWORD n_File_కొలత_దిగువ;
    DWORD dwReserved0;
    DWORD dwReserved1;
    CHAR cFileName[MAX_మార్గం];
    CHAR cAlternateFileName[14];
  } WIN32_కనుగొను_DATAA_2,*PWIN32_కనుగొను_DATAA,*LPWIN32_కనుగొను_DATAA;

  రకనిర్వచనం నిర్మాణం WIN32_కనుగొను_DATAW {
    DWORD dw_File_లక్షణాలు;
    FILETIME ft_Creation_సమయం;
    FILETIME ft_చివరి_Access_సమయం;
    FILETIME ft_చివరి_Write_సమయం;
    DWORD n_File_కొలత_ఎగువ;
    DWORD n_File_కొలత_దిగువ;
    DWORD dwReserved0;
    DWORD dwReserved1;
    WCHAR cFileName[MAX_మార్గం];
    WCHAR cAlternateFileName[14];
  } WIN32_కనుగొను_DATAW_2,*PWIN32_కనుగొను_DATAW,*LPWIN32_కనుగొను_DATAW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WIN32_కనుగొను_DATAW_2 WIN32_కనుగొను_దత్తాంశం;
  రకనిర్వచనం PWIN32_కనుగొను_DATAW PWIN32_కనుగొను_దత్తాంశం;
  రకనిర్వచనం LPWIN32_కనుగొను_DATAW LPWIN32_కనుగొను_దత్తాంశం;
#లేకపోతే
  రకనిర్వచనం WIN32_కనుగొను_DATAA_2 WIN32_కనుగొను_దత్తాంశం;
  రకనిర్వచనం PWIN32_కనుగొను_DATAA PWIN32_కనుగొను_దత్తాంశం;
  రకనిర్వచనం LPWIN32_కనుగొను_DATAA LPWIN32_కనుగొను_దత్తాంశం;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం WIN32_FILE_ATTRIBUTE_దత్తాంశం {
    DWORD dw_File_లక్షణాలు;
    FILETIME ft_Creation_సమయం;
    FILETIME ft_చివరి_Access_సమయం;
    FILETIME ft_చివరి_Write_సమయం;
    DWORD n_File_కొలత_ఎగువ;
    DWORD n_File_కొలత_దిగువ;
  } WIN32_FILE_ATTRIBUTE_దత్తాంశం_2,*LPWIN32_FILE_ATTRIBUTE_దత్తాంశం;

#నిర్వచితమైతే UNICODE
#నిర్వచించు CreateMutex CreateMutexW
#నిర్వచించు OpenMutex OpenMutexW
#నిర్వచించు CreateEvent CreateEventW
#నిర్వచించు OpenEvent OpenEventW
#నిర్వచించు CreateSemaphore CreateSemaphoreW
#నిర్వచించు OpenSemaphore OpenSemaphoreW
#లేకపోతే
#నిర్వచించు CreateMutex CreateMutexA
#నిర్వచించు OpenMutex OpenMutexA
#నిర్వచించు CreateEvent CreateEventA
#నిర్వచించు OpenEvent OpenEventA
#నిర్వచించు CreateSemaphore CreateSemaphoreA
#నిర్వచించు OpenSemaphore OpenSemaphoreA
#అయితే_ముగింపు

  WINBASEAPI HANDLE WINAPI CreateMutexA(LPSECURITY_లక్షణాలు lp_Mutex_లక్షణాలు,WINBOOL bInitialOwner,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateMutexW(LPSECURITY_లక్షణాలు lp_Mutex_లక్షణాలు,WINBOOL bInitialOwner,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenMutexW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventA(LPSECURITY_లక్షణాలు lp_Event_లక్షణాలు,WINBOOL bManualReset,WINBOOL bInitialState,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateEventW(LPSECURITY_లక్షణాలు lp_Event_లక్షణాలు,WINBOOL bManualReset,WINBOOL bInitialState,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenEventW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreA(LPSECURITY_లక్షణాలు lp_Semaphore_లక్షణాలు,LONG l_Initial_లెక్క,LONG l_గరిష్ఠ_లెక్క,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateSemaphoreW(LPSECURITY_లక్షణాలు lp_Semaphore_లక్షణాలు,LONG l_Initial_లెక్క,LONG l_గరిష్ఠ_లెక్క,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenSemaphoreW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);

  రకనిర్వచనం VOID (WINAPI *PTIMERAPCROUTINE)(LPVOID lp_Arg_గమ్యం_Completion_Routine,DWORD dw_Timer_దిగువ_విలువ,DWORD dw_Timer_ఎగువ_విలువ);

#నిర్వచితమైతే UNICODE
#నిర్వచించు CreateWaitableTimer CreateWaitableTimerW
#నిర్వచించు OpenWaitableTimer OpenWaitableTimerW
#నిర్వచించు CreateFileMapping CreateFileMappingW
#నిర్వచించు OpenFileMapping OpenFileMappingW
#నిర్వచించు Get_Logical_Drive_అక్షరశ్రేణులు Get_Logical_Drive_అక్షరశ్రేణులు_W
#నిర్వచించు ఎక్కించు_Library ఎక్కించు_Library_W
#నిర్వచించు ఎక్కించు_Library_Ex ఎక్కించు_Library_Ex_W
#నిర్వచించు GetModuleFileName GetModuleFileNameW
#నిర్వచించు GetModuleHandle GetModuleHandleW
#లేకపోతే
#నిర్వచించు CreateWaitableTimer CreateWaitableTimerA
#నిర్వచించు OpenWaitableTimer OpenWaitableTimerA
#నిర్వచించు CreateFileMapping CreateFileMappingA
#నిర్వచించు OpenFileMapping OpenFileMappingA
#నిర్వచించు Get_Logical_Drive_అక్షరశ్రేణులు Get_Logical_Drive_అక్షరశ్రేణులు_A
#నిర్వచించు ఎక్కించు_Library ఎక్కించు_Library_A
#నిర్వచించు ఎక్కించు_Library_Ex ఎక్కించు_Library_Ex_A
#నిర్వచించు GetModuleFileName GetModuleFileNameA
#నిర్వచించు GetModuleHandle GetModuleHandleA
#అయితే_ముగింపు

  WINBASEAPI HANDLE WINAPI CreateWaitableTimerA(LPSECURITY_లక్షణాలు lp_Timer_లక్షణాలు,WINBOOL bManualReset,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI CreateWaitableTimerW(LPSECURITY_లక్షణాలు lp_Timer_లక్షణాలు,WINBOOL bManualReset,LPCWSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpTimerName);
  WINBASEAPI HANDLE WINAPI OpenWaitableTimerW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpTimerName);
  WINBASEAPI WINBOOL WINAPI సమితి_Waitable_Timer(HANDLE hTimer,స్థిరరాశి LARGE_INTEGER *lp_Due_సమయం,LONG lPeriod,PTIMERAPCROUTINE pfnCompletionRoutine,LPVOID lp_Arg_గమ్యం_Completion_Routine,WINBOOL fResume);
  WINBASEAPI WINBOOL WINAPI CancelWaitableTimer(HANDLE hTimer);
  WINBASEAPI HANDLE WINAPI CreateFileMappingA(HANDLE hFile,LPSECURITY_లక్షణాలు lp_File_Mapping_లక్షణాలు,DWORD flProtect,DWORD dw_గరిష్ఠ_కొలత_ఎగువ,DWORD dw_గరిష్ఠ_కొలత_దిగువ,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI CreateFileMappingW(HANDLE hFile,LPSECURITY_లక్షణాలు lp_File_Mapping_లక్షణాలు,DWORD flProtect,DWORD dw_గరిష్ఠ_కొలత_ఎగువ,DWORD dw_గరిష్ఠ_కొలత_దిగువ,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingA(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI OpenFileMappingW(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_అక్షరశ్రేణులు_A(DWORD n_బఫరు_నిడివి,LPSTR lp_బఫరు);
  WINBASEAPI DWORD WINAPI Get_Logical_Drive_అక్షరశ్రేణులు_W(DWORD n_బఫరు_నిడివి,LPWSTR lp_బఫరు);

  రకనిర్వచనం గణన జ్ఞాపకం_RESOURCE_NOTIFICATION_TYPE {
    దిగువ_జ్ఞాపకం_Resource_Notification,ఎగువ_జ్ఞాపకం_Resource_Notification
  } జ్ఞాపకం_RESOURCE_NOTIFICATION_TYPE_2;

  WINBASEAPI HANDLE WINAPI Create_జ్ఞాపకం_Resource_Notification(జ్ఞాపకం_RESOURCE_NOTIFICATION_TYPE_2 NotificationType);
  WINBASEAPI WINBOOL WINAPI Query_జ్ఞాపకం_Resource_Notification(HANDLE ResourceNotificationHandle,PBOOL ResourceState);
  WINBASEAPI HMODULE WINAPI ఎక్కించు_Library_A(LPCSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI ఎక్కించు_Library_W(LPCWSTR lpLibFileName);
  WINBASEAPI HMODULE WINAPI ఎక్కించు_Library_Ex_A(LPCSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);
  WINBASEAPI HMODULE WINAPI ఎక్కించు_Library_Ex_W(LPCWSTR lpLibFileName,HANDLE hFile,DWORD dwFlags);

#నిర్వచించు DONT_RESOLVE_DLL_REFERENCES 0x1
#నిర్వచించు ఎక్కించు_LIBRARY_AS_DATAFILE 0x2
#నిర్వచించు ఎక్కించు_WITH_ALTERED_శోధన_మార్గం 0x8
#నిర్వచించు ఎక్కించు_IGNORE_సంకేతం_AUTHZ_LEVEL 0x10
#నిర్వచించు ఎక్కించు_LIBRARY_AS_IMAGE_RESOURCE 0x20
#నిర్వచించు ఎక్కించు_LIBRARY_AS_DATAFILE_EXCLUSIVE 0x40
#నిర్వచించు ఎక్కించు_LIBRARY_REQUIRE_SIGNED_లక్ష్యం 0x80
#నిర్వచించు ఎక్కించు_LIBRARY_శోధన_DLL_ఎక్కించు_DIR 0x100
#నిర్వచించు ఎక్కించు_LIBRARY_శోధన_APPLICATION_DIR 0x200
#నిర్వచించు ఎక్కించు_LIBRARY_శోధన_USER_DIRS 0x400
#నిర్వచించు ఎక్కించు_LIBRARY_శోధన_SYSTEM32 0x800
#నిర్వచించు ఎక్కించు_LIBRARY_శోధన_DEFAULT_DIRS 0x1000
#నిర్వచించు ఎక్కించు_LIBRARY_సురక్షిత_CURRENT_DIRS 0x2000

  WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE hModule,LPCH lpFilename,DWORD n_కొలత);
  WINBASEAPI DWORD WINAPI GetModuleFileNameW(HMODULE hModule,LPWCH lpFilename,DWORD n_కొలత);
  WINBASEAPI HMODULE WINAPI GetModuleHandleA(LPCSTR lpModuleName);
  WINBASEAPI HMODULE WINAPI GetModuleHandleW(LPCWSTR lpModuleName);

#నిర్వచితం_కాకపోతే RC_INVOKED
#నిర్వచించు GET_MODULE_HANDLE_EX_FLAG_PIN (0x1)
#నిర్వచించు GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT (0x2)
#నిర్వచించు GET_MODULE_HANDLE_EX_FLAG_FROM_చిరునామా (0x4)

  రకనిర్వచనం WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXA)(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  రకనిర్వచనం WINBOOL (WINAPI *PGET_MODULE_HANDLE_EXW)(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);

#నిర్వచితమైతే UNICODE
#నిర్వచించు PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXW
#నిర్వచించు GetModuleHandleEx GetModuleHandleExW
#లేకపోతే
#నిర్వచించు PGET_MODULE_HANDLE_EX PGET_MODULE_HANDLE_EXA
#నిర్వచించు GetModuleHandleEx GetModuleHandleExA
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI GetModuleHandleExA(DWORD dwFlags,LPCSTR lpModuleName,HMODULE *phModule);
  WINBASEAPI WINBOOL WINAPI GetModuleHandleExW(DWORD dwFlags,LPCWSTR lpModuleName,HMODULE *phModule);
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు Need_Current_Directory_For_Exe_మార్గం Need_Current_Directory_For_Exe_మార్గం_W
#నిర్వచించు CreateProcess CreateProcessW
#నిర్వచించు FatalAppExit FatalAppExitW
#నిర్వచించు GetStartupInfo GetStartupInfoW
#నిర్వచించు Get_Command_పంక్తి Get_Command_పంక్తి_W
#నిర్వచించు GetEnvironmentVariable GetEnvironmentVariableW
#నిర్వచించు సమితి_Environment_Variable సమితి_Environment_Variable_W
#నిర్వచించు Expand_Environment_అక్షరశ్రేణులు Expand_Environment_అక్షరశ్రేణులు_W
#నిర్వచించు GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
#నిర్వచించు సమితి_Firmware_Environment_Variable సమితి_Firmware_Environment_Variable_W
#నిర్వచించు OutputDebugString OutputDebugStringW
#నిర్వచించు కనుగొను_Resource కనుగొను_Resource_W
#నిర్వచించు కనుగొను_Resource_Ex కనుగొను_Resource_Ex_W
#లేకపోతే
#నిర్వచించు Need_Current_Directory_For_Exe_మార్గం Need_Current_Directory_For_Exe_మార్గం_A
#నిర్వచించు CreateProcess CreateProcessA
#నిర్వచించు FatalAppExit FatalAppExitA
#నిర్వచించు GetStartupInfo GetStartupInfoA
#నిర్వచించు Get_Command_పంక్తి Get_Command_పంక్తి_A
#నిర్వచించు GetEnvironmentVariable GetEnvironmentVariableA
#నిర్వచించు సమితి_Environment_Variable సమితి_Environment_Variable_A
#నిర్వచించు Expand_Environment_అక్షరశ్రేణులు Expand_Environment_అక్షరశ్రేణులు_A
#నిర్వచించు GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
#నిర్వచించు సమితి_Firmware_Environment_Variable సమితి_Firmware_Environment_Variable_A
#నిర్వచించు OutputDebugString OutputDebugStringA
#నిర్వచించు కనుగొను_Resource కనుగొను_Resource_A
#నిర్వచించు కనుగొను_Resource_Ex కనుగొను_Resource_Ex_A
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_మార్గం_A(LPCSTR ExeName);
  WINBASEAPI WINBOOL WINAPI Need_Current_Directory_For_Exe_మార్గం_W(LPCWSTR ExeName);
  WINBASEAPI WINBOOL WINAPI CreateProcessA(LPCSTR lpApplicationName,LPSTR lp_Command_పంక్తి,LPSECURITY_లక్షణాలు lp_Process_లక్షణాలు,LPSECURITY_లక్షణాలు lp_Thread_లక్షణాలు,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI WINBOOL WINAPI CreateProcessW(LPCWSTR lpApplicationName,LPWSTR lp_Command_పంక్తి,LPSECURITY_లక్షణాలు lp_Process_లక్షణాలు,LPSECURITY_లక్షణాలు lp_Thread_లక్షణాలు,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINBASEAPI DWORD WINAPI కూడు_Local_Alternate_Computer_Name_A(LPCSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI DWORD WINAPI కూడు_Local_Alternate_Computer_Name_W(LPCWSTR lpDnsFQHostname,ULONG ulFlags);
  WINBASEAPI WINBOOL WINAPI సమితి_Process_Shutdown_Parameters(DWORD dwLevel,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetProcessShutdownParameters(LPDWORD lpdwLevel,LPDWORD lpdwFlags);
  WINBASEAPI DWORD WINAPI Get_Process_సంస్కరణ(DWORD ProcessId);
  WINBASEAPI VOID WINAPI FatalAppExitA(UINT uAction,LPCSTR lp_సందేశం_పాఠ్యం);
  WINBASEAPI VOID WINAPI FatalAppExitW(UINT uAction,LPCWSTR lp_సందేశం_పాఠ్యం);
  WINBASEAPI VOID WINAPI GetStartupInfoA(LPSTARTUPINFOA lpStartupInfo);
  WINBASEAPI VOID WINAPI GetStartupInfoW(LPSTARTUPINFOW lpStartupInfo);
  WINBASEAPI LPSTR WINAPI Get_Command_పంక్తి_A(VOID);
  WINBASEAPI LPWSTR WINAPI Get_Command_పంక్తి_W(VOID);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableA(LPCSTR lpName,LPSTR lp_బఫరు,DWORD n_కొలత);
  WINBASEAPI DWORD WINAPI GetEnvironmentVariableW(LPCWSTR lpName,LPWSTR lp_బఫరు,DWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Environment_Variable_A(LPCSTR lpName,LPCSTR lp_విలువ);
  WINBASEAPI WINBOOL WINAPI సమితి_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lp_విలువ);
  WINBASEAPI DWORD WINAPI Expand_Environment_అక్షరశ్రేణులు_A(LPCSTR lpSrc,LPSTR lpDst,DWORD n_కొలత);
  WINBASEAPI DWORD WINAPI Expand_Environment_అక్షరశ్రేణులు_W(LPCWSTR lpSrc,LPWSTR lpDst,DWORD n_కొలత);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableA(LPCSTR lpName,LPCSTR lpGuid,PVOID p_బఫరు,DWORD n_కొలత);
  WINBASEAPI DWORD WINAPI GetFirmwareEnvironmentVariableW(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_బఫరు,DWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Firmware_Environment_Variable_A(LPCSTR lpName,LPCSTR lpGuid,PVOID p_విలువ,DWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Firmware_Environment_Variable_W(LPCWSTR lpName,LPCWSTR lpGuid,PVOID p_విలువ,DWORD n_కొలత);
  WINBASEAPI VOID WINAPI OutputDebugStringA(LPCSTR lpOutputString);
  WINBASEAPI VOID WINAPI OutputDebugStringW(LPCWSTR lpOutputString);
  WINBASEAPI HRSRC WINAPI కనుగొను_Resource_A(HMODULE hModule,LPCSTR lpName,LPCSTR lpType);
  WINBASEAPI HRSRC WINAPI కనుగొను_Resource_W(HMODULE hModule,LPCWSTR lpName,LPCWSTR lpType);
  WINBASEAPI HRSRC WINAPI కనుగొను_Resource_Ex_A(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,మాట_3 wLanguage);
  WINBASEAPI HRSRC WINAPI కనుగొను_Resource_Ex_W(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,మాట_3 wLanguage);

#నిర్వచితమైతే UNICODE
#నిర్వచించు ENUMRESTYPEPROC ENUMRESTYPEPROCW
#నిర్వచించు ENUMRESNAMEPROC ENUMRESNAMEPROCW
#నిర్వచించు ENUMRESLANGPROC ENUMRESLANGPROCW
#నిర్వచించు EnumResourceTypes EnumResourceTypesW
#నిర్వచించు Enum_Resource_పేర్లు Enum_Resource_పేర్లు_W
#నిర్వచించు EnumResourceLanguages EnumResourceLanguagesW
#నిర్వచించు BeginUpdateResource BeginUpdateResourceW
#నిర్వచించు UpdateResource UpdateResourceW
#నిర్వచించు చివర_Update_Resource చివర_Update_Resource_W
#నిర్వచించు Global_కూడు_Atom Global_కూడు_Atom_W
#నిర్వచించు Global_కనుగొను_Atom Global_కనుగొను_Atom_W
#నిర్వచించు GlobalGetAtomName GlobalGetAtomNameW
#నిర్వచించు కూడు_Atom కూడు_Atom_W
#నిర్వచించు కనుగొను_Atom కనుగొను_Atom_W
#నిర్వచించు GetAtomName GetAtomNameW
#నిర్వచించు GetProfileInt GetProfileIntW
#నిర్వచించు GetProfileString GetProfileStringW
#నిర్వచించు WriteProfileString WriteProfileStringW
#నిర్వచించు GetProfileSection GetProfileSectionW
#నిర్వచించు WriteProfileSection WriteProfileSectionW
#నిర్వచించు Get_వ్యక్తిగత_Profile_Int Get_వ్యక్తిగత_Profile_Int_W
#నిర్వచించు Get_వ్యక్తిగత_Profile_String Get_వ్యక్తిగత_Profile_String_W
#నిర్వచించు Write_వ్యక్తిగత_Profile_String Write_వ్యక్తిగత_Profile_String_W
#నిర్వచించు Get_వ్యక్తిగత_Profile_Section Get_వ్యక్తిగత_Profile_Section_W
#నిర్వచించు Write_వ్యక్తిగత_Profile_Section Write_వ్యక్తిగత_Profile_Section_W
#నిర్వచించు Get_వ్యక్తిగత_Profile_Section_పేర్లు Get_వ్యక్తిగత_Profile_Section_పేర్లు_W
#నిర్వచించు Get_వ్యక్తిగత_Profile_Struct Get_వ్యక్తిగత_Profile_Struct_W
#నిర్వచించు Write_వ్యక్తిగత_Profile_Struct Write_వ్యక్తిగత_Profile_Struct_W
#నిర్వచించు GetDriveType GetDriveTypeW
#నిర్వచించు GetSystemDirectory GetSystemDirectoryW
#నిర్వచించు Get_తాత్కాలిక_మార్గం Get_తాత్కాలిక_మార్గం_W
#నిర్వచించు Get_తాత్కాలిక_File_Name Get_తాత్కాలిక_File_Name_W
#నిర్వచించు GetWindowsDirectory GetWindowsDirectoryW
#నిర్వచించు GetSystemWindowsDirectory GetSystemWindowsDirectoryW
#నిర్వచించు కూడు_Local_Alternate_Computer_Name కూడు_Local_Alternate_Computer_Name_W
#లేకపోతే
#నిర్వచించు ENUMRESTYPEPROC ENUMRESTYPEPROCA
#నిర్వచించు ENUMRESNAMEPROC ENUMRESNAMEPROCA
#నిర్వచించు ENUMRESLANGPROC ENUMRESLANGPROCA
#నిర్వచించు EnumResourceTypes EnumResourceTypesA
#నిర్వచించు Enum_Resource_పేర్లు Enum_Resource_పేర్లు_A
#నిర్వచించు EnumResourceLanguages EnumResourceLanguagesA
#నిర్వచించు BeginUpdateResource BeginUpdateResourceA
#నిర్వచించు UpdateResource UpdateResourceA
#నిర్వచించు చివర_Update_Resource చివర_Update_Resource_A
#నిర్వచించు Global_కూడు_Atom Global_కూడు_Atom_A
#నిర్వచించు Global_కనుగొను_Atom Global_కనుగొను_Atom_A
#నిర్వచించు GlobalGetAtomName GlobalGetAtomNameA
#నిర్వచించు కూడు_Atom కూడు_Atom_A
#నిర్వచించు కనుగొను_Atom కనుగొను_Atom_A
#నిర్వచించు GetAtomName GetAtomNameA
#నిర్వచించు GetProfileInt GetProfileIntA
#నిర్వచించు GetProfileString GetProfileStringA
#నిర్వచించు WriteProfileString WriteProfileStringA
#నిర్వచించు GetProfileSection GetProfileSectionA
#నిర్వచించు WriteProfileSection WriteProfileSectionA
#నిర్వచించు Get_వ్యక్తిగత_Profile_Int Get_వ్యక్తిగత_Profile_Int_A
#నిర్వచించు Get_వ్యక్తిగత_Profile_String Get_వ్యక్తిగత_Profile_String_A
#నిర్వచించు Write_వ్యక్తిగత_Profile_String Write_వ్యక్తిగత_Profile_String_A
#నిర్వచించు Get_వ్యక్తిగత_Profile_Section Get_వ్యక్తిగత_Profile_Section_A
#నిర్వచించు Write_వ్యక్తిగత_Profile_Section Write_వ్యక్తిగత_Profile_Section_A
#నిర్వచించు Get_వ్యక్తిగత_Profile_Section_పేర్లు Get_వ్యక్తిగత_Profile_Section_పేర్లు_A
#నిర్వచించు Get_వ్యక్తిగత_Profile_Struct Get_వ్యక్తిగత_Profile_Struct_A
#నిర్వచించు Write_వ్యక్తిగత_Profile_Struct Write_వ్యక్తిగత_Profile_Struct_A
#నిర్వచించు GetDriveType GetDriveTypeA
#నిర్వచించు GetSystemDirectory GetSystemDirectoryA
#నిర్వచించు Get_తాత్కాలిక_మార్గం Get_తాత్కాలిక_మార్గం_A
#నిర్వచించు Get_తాత్కాలిక_File_Name Get_తాత్కాలిక_File_Name_A
#నిర్వచించు GetWindowsDirectory GetWindowsDirectoryA
#నిర్వచించు GetSystemWindowsDirectory GetSystemWindowsDirectoryA
#నిర్వచించు కూడు_Local_Alternate_Computer_Name కూడు_Local_Alternate_Computer_Name_A
#అయితే_ముగింపు

  రకనిర్వచనం WINBOOL (CALLBACK *ENUMRESTYPEPROCA)(HMODULE hModule,LPSTR lpType,LONG_PTR lParam);
  రకనిర్వచనం WINBOOL (CALLBACK *ENUMRESTYPEPROCW)(HMODULE hModule,LPWSTR lpType,LONG_PTR lParam);
  రకనిర్వచనం WINBOOL (CALLBACK *ENUMRESNAMEPROCA)(HMODULE hModule,LPCSTR lpType,LPSTR lpName,LONG_PTR lParam);
  రకనిర్వచనం WINBOOL (CALLBACK *ENUMRESNAMEPROCW)(HMODULE hModule,LPCWSTR lpType,LPWSTR lpName,LONG_PTR lParam);
  రకనిర్వచనం WINBOOL (CALLBACK *ENUMRESLANGPROCA)(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,మాట_3 wLanguage,LONG_PTR lParam);
  రకనిర్వచనం WINBOOL (CALLBACK *ENUMRESLANGPROCW)(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,మాట_3 wLanguage,LONG_PTR lParam);

  WINBASEAPI WINBOOL WINAPI EnumResourceTypesA(HMODULE hModule,ENUMRESTYPEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceTypesW(HMODULE hModule,ENUMRESTYPEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_పేర్లు_A(HMODULE hModule,LPCSTR lpType,ENUMRESNAMEPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Resource_పేర్లు_W(HMODULE hModule,LPCWSTR lpType,ENUMRESNAMEPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesA(HMODULE hModule,LPCSTR lpType,LPCSTR lpName,ENUMRESLANGPROCA lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumResourceLanguagesW(HMODULE hModule,LPCWSTR lpType,LPCWSTR lpName,ENUMRESLANGPROCW lpEnumFunc,LONG_PTR lParam);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceA(LPCSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI HANDLE WINAPI BeginUpdateResourceW(LPCWSTR pFileName,WINBOOL bDeleteExistingResources);
  WINBASEAPI WINBOOL WINAPI UpdateResourceA(HANDLE hUpdate,LPCSTR lpType,LPCSTR lpName,మాట_3 wLanguage,LPVOID lp_దత్తాంశం,DWORD cb);
  WINBASEAPI WINBOOL WINAPI UpdateResourceW(HANDLE hUpdate,LPCWSTR lpType,LPCWSTR lpName,మాట_3 wLanguage,LPVOID lp_దత్తాంశం,DWORD cb);
  WINBASEAPI WINBOOL WINAPI చివర_Update_Resource_A(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI WINBOOL WINAPI చివర_Update_Resource_W(HANDLE hUpdate,WINBOOL fDiscard);
  WINBASEAPI ATOM WINAPI Global_కూడు_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_కూడు_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI Global_కనుగొను_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI Global_కనుగొను_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameA(ATOM nAtom,LPSTR lp_బఫరు,పూర్ణాంకం n_కొలత);
  WINBASEAPI UINT WINAPI GlobalGetAtomNameW(ATOM nAtom,LPWSTR lp_బఫరు,పూర్ణాంకం n_కొలత);
  WINBASEAPI ATOM WINAPI కూడు_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI కూడు_Atom_W(LPCWSTR lpString);
  WINBASEAPI ATOM WINAPI కనుగొను_Atom_A(LPCSTR lpString);
  WINBASEAPI ATOM WINAPI కనుగొను_Atom_W(LPCWSTR lpString);
  WINBASEAPI UINT WINAPI GetAtomNameA(ATOM nAtom,LPSTR lp_బఫరు,పూర్ణాంకం n_కొలత);
  WINBASEAPI UINT WINAPI GetAtomNameW(ATOM nAtom,LPWSTR lp_బఫరు,పూర్ణాంకం n_కొలత);
  WINBASEAPI UINT WINAPI GetProfileIntA(LPCSTR lpAppName,LPCSTR lp_కీలకం_Name,INT nDefault);
  WINBASEAPI UINT WINAPI GetProfileIntW(LPCWSTR lpAppName,LPCWSTR lp_కీలకం_Name,INT nDefault);
  WINBASEAPI DWORD WINAPI GetProfileStringA(LPCSTR lpAppName,LPCSTR lp_కీలకం_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_కొలత);
  WINBASEAPI DWORD WINAPI GetProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_కీలకం_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringA(LPCSTR lpAppName,LPCSTR lp_కీలకం_Name,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileStringW(LPCWSTR lpAppName,LPCWSTR lp_కీలకం_Name,LPCWSTR lpString);
  WINBASEAPI DWORD WINAPI GetProfileSectionA(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_కొలత);
  WINBASEAPI DWORD WINAPI GetProfileSectionW(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionA(LPCSTR lpAppName,LPCSTR lpString);
  WINBASEAPI WINBOOL WINAPI WriteProfileSectionW(LPCWSTR lpAppName,LPCWSTR lpString);
  WINBASEAPI UINT WINAPI Get_వ్యక్తిగత_Profile_Int_A(LPCSTR lpAppName,LPCSTR lp_కీలకం_Name,INT nDefault,LPCSTR lpFileName);
  WINBASEAPI UINT WINAPI Get_వ్యక్తిగత_Profile_Int_W(LPCWSTR lpAppName,LPCWSTR lp_కీలకం_Name,INT nDefault,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_వ్యక్తిగత_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_కీలకం_Name,LPCSTR lpDefault,LPSTR lpReturnedString,DWORD n_కొలత,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_వ్యక్తిగత_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_కీలకం_Name,LPCWSTR lpDefault,LPWSTR lpReturnedString,DWORD n_కొలత,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_వ్యక్తిగత_Profile_String_A(LPCSTR lpAppName,LPCSTR lp_కీలకం_Name,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_వ్యక్తిగత_Profile_String_W(LPCWSTR lpAppName,LPCWSTR lp_కీలకం_Name,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_వ్యక్తిగత_Profile_Section_A(LPCSTR lpAppName,LPSTR lpReturnedString,DWORD n_కొలత,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_వ్యక్తిగత_Profile_Section_W(LPCWSTR lpAppName,LPWSTR lpReturnedString,DWORD n_కొలత,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_వ్యక్తిగత_Profile_Section_A(LPCSTR lpAppName,LPCSTR lpString,LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Write_వ్యక్తిగత_Profile_Section_W(LPCWSTR lpAppName,LPCWSTR lpString,LPCWSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_వ్యక్తిగత_Profile_Section_పేర్లు_A(LPSTR lpsz_Return_బఫరు,DWORD n_కొలత,LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_వ్యక్తిగత_Profile_Section_పేర్లు_W(LPWSTR lpsz_Return_బఫరు,DWORD n_కొలత,LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI Get_వ్యక్తిగత_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_కీలకం,LPVOID lpStruct,UINT u_కొలత_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Get_వ్యక్తిగత_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_కీలకం,LPVOID lpStruct,UINT u_కొలత_Struct,LPCWSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_వ్యక్తిగత_Profile_Struct_A(LPCSTR lpszSection,LPCSTR lpsz_కీలకం,LPVOID lpStruct,UINT u_కొలత_Struct,LPCSTR szFile);
  WINBASEAPI WINBOOL WINAPI Write_వ్యక్తిగత_Profile_Struct_W(LPCWSTR lpszSection,LPCWSTR lpsz_కీలకం,LPVOID lpStruct,UINT u_కొలత_Struct,LPCWSTR szFile);
  WINBASEAPI UINT WINAPI GetDriveTypeA(LPCSTR lp_మూలం_మార్గం_Name);
  WINBASEAPI UINT WINAPI GetDriveTypeW(LPCWSTR lp_మూలం_మార్గం_Name);
  WINBASEAPI UINT WINAPI GetSystemDirectoryA(LPSTR lp_బఫరు,UINT u_కొలత);
  WINBASEAPI UINT WINAPI GetSystemDirectoryW(LPWSTR lp_బఫరు,UINT u_కొలత);
  WINBASEAPI DWORD WINAPI Get_తాత్కాలిక_మార్గం_A(DWORD n_బఫరు_నిడివి,LPSTR lp_బఫరు);
  WINBASEAPI DWORD WINAPI Get_తాత్కాలిక_మార్గం_W(DWORD n_బఫరు_నిడివి,LPWSTR lp_బఫరు);
  WINBASEAPI UINT WINAPI Get_తాత్కాలిక_File_Name_A(LPCSTR lp_మార్గం_Name,LPCSTR lp_ఉపసర్గ_String,UINT uUnique,LPSTR lp_తాత్కాలిక_File_Name);
  WINBASEAPI UINT WINAPI Get_తాత్కాలిక_File_Name_W(LPCWSTR lp_మార్గం_Name,LPCWSTR lp_ఉపసర్గ_String,UINT uUnique,LPWSTR lp_తాత్కాలిక_File_Name);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryA(LPSTR lp_బఫరు,UINT u_కొలత);
  WINBASEAPI UINT WINAPI GetWindowsDirectoryW(LPWSTR lp_బఫరు,UINT u_కొలత);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryA(LPSTR lp_బఫరు,UINT u_కొలత);
  WINBASEAPI UINT WINAPI GetSystemWindowsDirectoryW(LPWSTR lp_బఫరు,UINT u_కొలత);

#నిర్వచితం_కాకపోతే RC_INVOKED
#నిర్వచితమైతే UNICODE
#నిర్వచించు GetSystemWow64Directory GetSystemWow64DirectoryW
#లేకపోతే
#నిర్వచించు GetSystemWow64Directory GetSystemWow64DirectoryA
#అయితే_ముగింపు

  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryA(LPSTR lp_బఫరు,UINT u_కొలత);
  WINBASEAPI UINT WINAPI GetSystemWow64DirectoryW(LPWSTR lp_బఫరు,UINT u_కొలత);
  WINBASEAPI BOOLEAN WINAPI Wow64EnableWow64FsRedirection(BOOLEAN Wow64FsEnableRedirection);
  WINBASEAPI WINBOOL WINAPI Wow64DisableWow64FsRedirection(PVOID *Old_విలువ);
  WINBASEAPI WINBOOL WINAPI Wow64RevertWow64FsRedirection(PVOID Ol_విలువ);

  రకనిర్వచనం UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_A)(LPSTR lp_బఫరు,UINT u_కొలత);
  రకనిర్వచనం UINT (WINAPI *PGET_SYSTEM_WOW64_DIRECTORY_W)(LPWSTR lp_బఫరు,UINT u_కొలత);

#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A "GetSystemWow64DirectoryA"
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W L"GetSystemWow64DirectoryA"
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T పాఠ్యం_3("GetSystemWow64DirectoryA")
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A "GetSystemWow64DirectoryW"
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W L"GetSystemWow64DirectoryW"
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T పాఠ్యం_3("GetSystemWow64DirectoryW")

#నిర్వచితమైతే UNICODE
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
#లేకపోతే
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
#నిర్వచించు GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు సమితి_Current_Directory సమితి_Current_Directory_W
#నిర్వచించు GetCurrentDirectory GetCurrentDirectoryW
#నిర్వచించు సమితి_Dll_Directory సమితి_Dll_Directory_W
#నిర్వచించు GetDllDirectory GetDllDirectoryW
#నిర్వచించు GetDiskFreeSpace GetDiskFreeSpaceW
#నిర్వచించు GetDiskFreeSpaceEx GetDiskFreeSpaceExW
#నిర్వచించు CreateDirectory CreateDirectoryW
#నిర్వచించు CreateDirectoryEx CreateDirectoryExW
#నిర్వచించు RemoveDirectory RemoveDirectoryW
#నిర్వచించు Get_నిండిన_మార్గం_Name Get_నిండిన_మార్గం_Name_W
#నిర్వచించు DefineDosDevice DefineDosDeviceW
#నిర్వచించు QueryDosDevice QueryDosDeviceW
#నిర్వచించు CreateFile CreateFileW
#నిర్వచించు సమితి_File_లక్షణాలు సమితి_File_లక్షణాలు_W
#నిర్వచించు Get_File_లక్షణాలు Get_File_లక్షణాలు_W
#లేకపోతే
#నిర్వచించు సమితి_Current_Directory సమితి_Current_Directory_A
#నిర్వచించు GetCurrentDirectory GetCurrentDirectoryA
#నిర్వచించు సమితి_Dll_Directory సమితి_Dll_Directory_A
#నిర్వచించు GetDllDirectory GetDllDirectoryA
#నిర్వచించు GetDiskFreeSpace GetDiskFreeSpaceA
#నిర్వచించు GetDiskFreeSpaceEx GetDiskFreeSpaceExA
#నిర్వచించు CreateDirectory CreateDirectoryA
#నిర్వచించు CreateDirectoryEx CreateDirectoryExA
#నిర్వచించు RemoveDirectory RemoveDirectoryA
#నిర్వచించు Get_నిండిన_మార్గం_Name Get_నిండిన_మార్గం_Name_A
#నిర్వచించు DefineDosDevice DefineDosDeviceA
#నిర్వచించు QueryDosDevice QueryDosDeviceA
#నిర్వచించు CreateFile CreateFileA
#నిర్వచించు సమితి_File_లక్షణాలు సమితి_File_లక్షణాలు_A
#నిర్వచించు Get_File_లక్షణాలు Get_File_లక్షణాలు_A
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI సమితి_Current_Directory_A(LPCSTR lp_మార్గం_Name);
  WINBASEAPI WINBOOL WINAPI సమితి_Current_Directory_W(LPCWSTR lp_మార్గం_Name);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryA(DWORD n_బఫరు_నిడివి,LPSTR lp_బఫరు);
  WINBASEAPI DWORD WINAPI GetCurrentDirectoryW(DWORD n_బఫరు_నిడివి,LPWSTR lp_బఫరు);
  WINBASEAPI WINBOOL WINAPI సమితి_Dll_Directory_A(LPCSTR lp_మార్గం_Name);
  WINBASEAPI WINBOOL WINAPI సమితి_Dll_Directory_W(LPCWSTR lp_మార్గం_Name);
  WINBASEAPI DWORD WINAPI GetDllDirectoryA(DWORD n_బఫరు_నిడివి,LPSTR lp_బఫరు);
  WINBASEAPI DWORD WINAPI GetDllDirectoryW(DWORD n_బఫరు_నిడివి,LPWSTR lp_బఫరు);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceA(LPCSTR lp_మూలం_మార్గం_Name,LPDWORD lp_Sectors_చొప్పున_Cluster,LPDWORD lp_బైట్లు_చొప్పున_Sector,LPDWORD lp_సంఖ్య_యొక్క_Free_Clusters,LPDWORD lp_మొత్తం_సంఖ్య_యొక్క_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceW(LPCWSTR lp_మూలం_మార్గం_Name,LPDWORD lp_Sectors_చొప్పున_Cluster,LPDWORD lp_బైట్లు_చొప్పున_Sector,LPDWORD lp_సంఖ్య_యొక్క_Free_Clusters,LPDWORD lp_మొత్తం_సంఖ్య_యొక్క_Clusters);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExA(LPCSTR lpDirectoryName,PULARGE_INTEGER lp_Free_బైట్లు_అందుబాటు_గమ్యం_Caller,PULARGE_INTEGER lp_మొత్తం_సంఖ్య_యొక్క_బైట్లు,PULARGE_INTEGER lp_మొత్తం_సంఖ్య_యొక్క_Free_బైట్లు);
  WINBASEAPI WINBOOL WINAPI GetDiskFreeSpaceExW(LPCWSTR lpDirectoryName,PULARGE_INTEGER lp_Free_బైట్లు_అందుబాటు_గమ్యం_Caller,PULARGE_INTEGER lp_మొత్తం_సంఖ్య_యొక్క_బైట్లు,PULARGE_INTEGER lp_మొత్తం_సంఖ్య_యొక్క_Free_బైట్లు);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryA(LPCSTR lp_మార్గం_Name,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryW(LPCWSTR lp_మార్గం_Name,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExA(LPCSTR lpTemplateDirectory,LPCSTR lpNewDirectory,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI CreateDirectoryExW(LPCWSTR lpTemplateDirectory,LPCWSTR lpNewDirectory,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryA(LPCSTR lp_మార్గం_Name);
  WINBASEAPI WINBOOL WINAPI RemoveDirectoryW(LPCWSTR lp_మార్గం_Name);
  WINBASEAPI DWORD WINAPI Get_నిండిన_మార్గం_Name_A(LPCSTR lpFileName,DWORD n_బఫరు_నిడివి,LPSTR lp_బఫరు,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI Get_నిండిన_మార్గం_Name_W(LPCWSTR lpFileName,DWORD n_బఫరు_నిడివి,LPWSTR lp_బఫరు,LPWSTR *lpFilePart);

#నిర్వచించు DDD_RAW_లక్ష్యం_మార్గం 0x1
#నిర్వచించు DDD_REMOVE_DEFINITION 0x2
#నిర్వచించు DDD_EXACT_సరిపోలిక_ON_REMOVE 0x4
#నిర్వచించు DDD_NO_ప్రసారం_SYSTEM 0x8
#నిర్వచించు DDD_LUID_ప్రసారం_DRIVE 0x10

  WINBASEAPI WINBOOL WINAPI DefineDosDeviceA(DWORD dwFlags,LPCSTR lpDeviceName,LPCSTR lp_లక్ష్యం_మార్గం);
  WINBASEAPI WINBOOL WINAPI DefineDosDeviceW(DWORD dwFlags,LPCWSTR lpDeviceName,LPCWSTR lp_లక్ష్యం_మార్గం);
  WINBASEAPI DWORD WINAPI QueryDosDeviceA(LPCSTR lpDeviceName,LPSTR lp_లక్ష్యం_మార్గం,DWORD ucchMax);
  WINBASEAPI DWORD WINAPI QueryDosDeviceW(LPCWSTR lpDeviceName,LPWSTR lp_లక్ష్యం_మార్గం,DWORD ucchMax);

#నిర్వచించు EXPAND_LOCAL_DRIVES

  WINBASEAPI HANDLE WINAPI CreateFileA(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_బహుళకం,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు,DWORD dwCreationDisposition,DWORD dw_Flags_And_లక్షణాలు,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI CreateFileW(LPCWSTR lpFileName,DWORD dwDesiredAccess,DWORD dw_Share_బహుళకం,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు,DWORD dwCreationDisposition,DWORD dw_Flags_And_లక్షణాలు,HANDLE hTemplateFile);
  WINBASEAPI HANDLE WINAPI ReOpenFile(HANDLE hOriginalFile,DWORD dwDesiredAccess,DWORD dw_Share_బహుళకం,DWORD dw_Flags_And_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI సమితి_File_లక్షణాలు_A(LPCSTR lpFileName,DWORD dw_File_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI సమితి_File_లక్షణాలు_W(LPCWSTR lpFileName,DWORD dw_File_లక్షణాలు);
  WINBASEAPI DWORD WINAPI Get_File_లక్షణాలు_A(LPCSTR lpFileName);
  WINBASEAPI DWORD WINAPI Get_File_లక్షణాలు_W(LPCWSTR lpFileName);

  రకనిర్వచనం గణన GET_FILEEX_INFO_స్థాయిలు {
    GetFileExInfoStandard,GetFileExMaxInfoLevel
  } GET_FILEEX_INFO_స్థాయిలు_2;

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_File_లక్షణాలు_Ex Get_File_లక్షణాలు_Ex_W
#నిర్వచించు Get_Compressed_File_కొలత Get_Compressed_File_కొలత_W
#నిర్వచించు DeleteFile DeleteFileW
#నిర్వచించు CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
#లేకపోతే
#నిర్వచించు Get_File_లక్షణాలు_Ex Get_File_లక్షణాలు_Ex_A
#నిర్వచించు Get_Compressed_File_కొలత Get_Compressed_File_కొలత_A
#నిర్వచించు DeleteFile DeleteFileA
#నిర్వచించు CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI Get_File_లక్షణాలు_Ex_A(LPCSTR lpFileName,GET_FILEEX_INFO_స్థాయిలు_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI WINBOOL WINAPI Get_File_లక్షణాలు_Ex_W(LPCWSTR lpFileName,GET_FILEEX_INFO_స్థాయిలు_2 fInfoLevelId,LPVOID lpFileInformation);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_కొలత_A(LPCSTR lpFileName,LPDWORD lp_File_కొలత_ఎగువ);
  WINBASEAPI DWORD WINAPI Get_Compressed_File_కొలత_W(LPCWSTR lpFileName,LPDWORD lp_File_కొలత_ఎగువ);
  WINBASEAPI WINBOOL WINAPI DeleteFileA(LPCSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI DeleteFileW(LPCWSTR lpFileName);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3A(LPCSTR lpName,LPSTR lpOemName,DWORD Oem_Name_కొలత,PBOOL pb_Name_కలిగియుంది_Spaces,PBOOL pbNameLegal);
  WINBASEAPI WINBOOL WINAPI CheckNameLegalDOS8Dot3W(LPCWSTR lpName,LPSTR lpOemName,DWORD Oem_Name_కొలత,PBOOL pb_Name_కలిగియుంది_Spaces,PBOOL pbNameLegal);

  రకనిర్వచనం గణన FINDEX_INFO_స్థాయిలు {
    కనుగొను_Ex_Info_Standard,కనుగొను_Ex_Info_Max_Info_Level
  } FINDEX_INFO_స్థాయిలు_2;

  రకనిర్వచనం గణన FINDEX_శోధన_OPS {
    కనుగొను_Ex_శోధన_Name_సరిపోలిక,కనుగొను_Ex_శోధన_హద్దు_గమ్యం_Directories,కనుగొను_Ex_శోధన_హద్దు_గమ్యం_Devices,కనుగొను_Ex_శోధన_Max_శోధన_Op
  } FINDEX_శోధన_OPS_2;

#నిర్వచించు కనుగొను_మొదటి_EX_CASE_SENSITIVE 0x1

#నిర్వచితమైతే UNICODE
#నిర్వచించు కనుగొను_మొదటి_File_Ex కనుగొను_మొదటి_File_Ex_W
#నిర్వచించు కనుగొను_మొదటి_File కనుగొను_మొదటి_File_W
#నిర్వచించు కనుగొను_తదుపరి_File కనుగొను_తదుపరి_File_W
#నిర్వచించు శోధన_మార్గం శోధన_మార్గం_W
#నిర్వచించు CopyFile CopyFileW
#నిర్వచించు CopyFileEx CopyFileExW
#నిర్వచించు MoveFile MoveFileW
#నిర్వచించు MoveFileEx MoveFileExW
#నిర్వచించు Move_File_With_పురోగతి Move_File_With_పురోగతి_W
#నిర్వచించు ReplaceFile ReplaceFileW
#నిర్వచించు CreateHardLink CreateHardLinkW
#నిర్వచించు CreateNamedPipe CreateNamedPipeW
#నిర్వచించు GetNamedPipeHandleState GetNamedPipeHandleStateW
#నిర్వచించు CallNamedPipe CallNamedPipeW
#నిర్వచించు WaitNamedPipe WaitNamedPipeW
#నిర్వచించు సమితి_Volume_Label సమితి_Volume_Label_W
#నిర్వచించు GetVolumeInformation GetVolumeInformationW
#నిర్వచించు ClearEventLog ClearEventLogW
#నిర్వచించు BackupEventLog BackupEventLogW
#నిర్వచించు OpenEventLog OpenEventLogW
#నిర్వచించు రిజిస్టరు_Event_ఆధారం రిజిస్టరు_Event_ఆధారం_W
#నిర్వచించు OpenBackupEventLog OpenBackupEventLogW
#నిర్వచించు ReadEventLog ReadEventLogW
#నిర్వచించు ReportEvent ReportEventW
#నిర్వచించు AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
#నిర్వచించు AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
#నిర్వచించు Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_W
#నిర్వచించు Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_By_Handle_W
#నిర్వచించు ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
#నిర్వచించు ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
#నిర్వచించు ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
#నిర్వచించు ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
#నిర్వచించు PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
#నిర్వచించు సమితి_File_Security సమితి_File_Security_W
#నిర్వచించు GetFileSecurity GetFileSecurityW
#నిర్వచించు కనుగొను_మొదటి_Change_Notification కనుగొను_మొదటి_Change_Notification_W
#నిర్వచించు IsBadStringPtr IsBadStringPtrW
#నిర్వచించు LookupAccountSid LookupAccountSidW
#నిర్వచించు LookupAccountName LookupAccountNameW
#నిర్వచించు Lookup_Privilege_విలువ Lookup_Privilege_విలువ_W
#నిర్వచించు LookupPrivilegeName LookupPrivilegeNameW
#నిర్వచించు LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
#నిర్వచించు BuildCommDCB BuildCommDCBW
#నిర్వచించు BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
#నిర్వచించు CommConfigDialog CommConfigDialogW
#నిర్వచించు GetDefaultCommConfig GetDefaultCommConfigW
#నిర్వచించు సమితి_Default_Comm_Config సమితి_Default_Comm_Config_W
#నిర్వచించు GetComputerName GetComputerNameW
#నిర్వచించు సమితి_Computer_Name సమితి_Computer_Name_W
#నిర్వచించు GetComputerNameEx GetComputerNameExW
#నిర్వచించు సమితి_Computer_Name_Ex సమితి_Computer_Name_Ex_W
#నిర్వచించు Dns_Hostname_గమ్యం_Computer_Name Dns_Hostname_గమ్యం_Computer_Name_W
#నిర్వచించు GetUserName GetUserNameW
#లేకపోతే
#నిర్వచించు కనుగొను_మొదటి_File_Ex కనుగొను_మొదటి_File_Ex_A
#నిర్వచించు కనుగొను_మొదటి_File కనుగొను_మొదటి_File_A
#నిర్వచించు కనుగొను_తదుపరి_File కనుగొను_తదుపరి_File_A
#నిర్వచించు శోధన_మార్గం శోధన_మార్గం_A
#నిర్వచించు CopyFile CopyFileA
#నిర్వచించు CopyFileEx CopyFileExA
#నిర్వచించు MoveFile MoveFileA
#నిర్వచించు MoveFileEx MoveFileExA
#నిర్వచించు Move_File_With_పురోగతి Move_File_With_పురోగతి_A
#నిర్వచించు ReplaceFile ReplaceFileA
#నిర్వచించు CreateHardLink CreateHardLinkA
#నిర్వచించు CreateNamedPipe CreateNamedPipeA
#నిర్వచించు GetNamedPipeHandleState GetNamedPipeHandleStateA
#నిర్వచించు CallNamedPipe CallNamedPipeA
#నిర్వచించు WaitNamedPipe WaitNamedPipeA
#నిర్వచించు సమితి_Volume_Label సమితి_Volume_Label_A
#నిర్వచించు GetVolumeInformation GetVolumeInformationA
#నిర్వచించు ClearEventLog ClearEventLogA
#నిర్వచించు BackupEventLog BackupEventLogA
#నిర్వచించు OpenEventLog OpenEventLogA
#నిర్వచించు రిజిస్టరు_Event_ఆధారం రిజిస్టరు_Event_ఆధారం_A
#నిర్వచించు OpenBackupEventLog OpenBackupEventLogA
#నిర్వచించు ReadEventLog ReadEventLogA
#నిర్వచించు ReportEvent ReportEventA
#నిర్వచించు AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
#నిర్వచించు AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
#నిర్వచించు Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_A
#నిర్వచించు Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_By_Handle Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_By_Handle_A
#నిర్వచించు ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
#నిర్వచించు ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
#నిర్వచించు ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
#నిర్వచించు ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
#నిర్వచించు PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
#నిర్వచించు సమితి_File_Security సమితి_File_Security_A
#నిర్వచించు GetFileSecurity GetFileSecurityA
#నిర్వచించు కనుగొను_మొదటి_Change_Notification కనుగొను_మొదటి_Change_Notification_A
#నిర్వచించు IsBadStringPtr IsBadStringPtrA
#నిర్వచించు LookupAccountSid LookupAccountSidA
#నిర్వచించు LookupAccountName LookupAccountNameA
#నిర్వచించు Lookup_Privilege_విలువ Lookup_Privilege_విలువ_A
#నిర్వచించు LookupPrivilegeName LookupPrivilegeNameA
#నిర్వచించు LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
#నిర్వచించు BuildCommDCB BuildCommDCBA
#నిర్వచించు BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
#నిర్వచించు CommConfigDialog CommConfigDialogA
#నిర్వచించు GetDefaultCommConfig GetDefaultCommConfigA
#నిర్వచించు సమితి_Default_Comm_Config సమితి_Default_Comm_Config_A
#నిర్వచించు GetComputerName GetComputerNameA
#నిర్వచించు సమితి_Computer_Name సమితి_Computer_Name_A
#నిర్వచించు GetComputerNameEx GetComputerNameExA
#నిర్వచించు సమితి_Computer_Name_Ex సమితి_Computer_Name_Ex_A
#నిర్వచించు Dns_Hostname_గమ్యం_Computer_Name Dns_Hostname_గమ్యం_Computer_Name_A
#నిర్వచించు GetUserName GetUserNameA
#అయితే_ముగింపు

  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_File_Ex_A(LPCSTR lpFileName,FINDEX_INFO_స్థాయిలు_2 fInfoLevelId,LPVOID lp_కనుగొను_File_దత్తాంశం,FINDEX_శోధన_OPS_2 f_శోధన_Op,LPVOID lp_శోధన_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_File_Ex_W(LPCWSTR lpFileName,FINDEX_INFO_స్థాయిలు_2 fInfoLevelId,LPVOID lp_కనుగొను_File_దత్తాంశం,FINDEX_శోధన_OPS_2 f_శోధన_Op,LPVOID lp_శోధన_Filter,DWORD dwAdditionalFlags);
  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_File_A(LPCSTR lpFileName,LPWIN32_కనుగొను_DATAA lp_కనుగొను_File_దత్తాంశం);
  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_File_W(LPCWSTR lpFileName,LPWIN32_కనుగొను_DATAW lp_కనుగొను_File_దత్తాంశం);
  WINBASEAPI WINBOOL WINAPI కనుగొను_తదుపరి_File_A(HANDLE h_కనుగొను_File,LPWIN32_కనుగొను_DATAA lp_కనుగొను_File_దత్తాంశం);
  WINBASEAPI WINBOOL WINAPI కనుగొను_తదుపరి_File_W(HANDLE h_కనుగొను_File,LPWIN32_కనుగొను_DATAW lp_కనుగొను_File_దత్తాంశం);
  WINBASEAPI DWORD WINAPI శోధన_మార్గం_A(LPCSTR lp_మార్గం,LPCSTR lpFileName,LPCSTR lpExtension,DWORD n_బఫరు_నిడివి,LPSTR lp_బఫరు,LPSTR *lpFilePart);
  WINBASEAPI DWORD WINAPI శోధన_మార్గం_W(LPCWSTR lp_మార్గం,LPCWSTR lpFileName,LPCWSTR lpExtension,DWORD n_బఫరు_నిడివి,LPWSTR lp_బఫరు,LPWSTR *lpFilePart);
  WINBASEAPI WINBOOL WINAPI CopyFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,WINBOOL bFailIfExists);
  WINBASEAPI WINBOOL WINAPI CopyFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,WINBOOL bFailIfExists);

  రకనిర్వచనం DWORD (WINAPI *LPPROGRESS_ROUTINE)(LARGE_INTEGER మొత్తం_File_కొలత,LARGE_INTEGER మొత్తం_బైట్లు_Transferred,LARGE_INTEGER ప్రవాహం_కొలత,LARGE_INTEGER ప్రవాహం_బైట్లు_Transferred,DWORD dw_ప్రవాహం_సంఖ్య,DWORD dwCallbackReason,HANDLE h_ఆధారం_File,HANDLE hDestinationFile,LPVOID lp_దత్తాంశం);

  WINBASEAPI WINBOOL WINAPI CopyFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_పురోగతి_Routine,LPVOID lp_దత్తాంశం,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI CopyFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_పురోగతి_Routine,LPVOID lp_దత్తాంశం,LPBOOL pbCancel,DWORD dwCopyFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName);
  WINBASEAPI WINBOOL WINAPI MoveFileExA(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI MoveFileExW(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_పురోగతి_A(LPCSTR lpExistingFileName,LPCSTR lpNewFileName,LPPROGRESS_ROUTINE lp_పురోగతి_Routine,LPVOID lp_దత్తాంశం,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Move_File_With_పురోగతి_W(LPCWSTR lpExistingFileName,LPCWSTR lpNewFileName,LPPROGRESS_ROUTINE lp_పురోగతి_Routine,LPVOID lp_దత్తాంశం,DWORD dwFlags);

#నిర్వచించు MOVEFILE_REPLACE_EXISTING 0x1
#నిర్వచించు MOVEFILE_COPY_ALLOWED 0x2
#నిర్వచించు MOVEFILE_DELAY_UNTIL_REBOOT 0x4
#నిర్వచించు MOVEFILE_WRITE_THROUGH 0x8
#నిర్వచించు MOVEFILE_CREATE_HARDLINK 0x10
#నిర్వచించు MOVEFILE_FAIL_IF_NOT_TRACKABLE 0x20

  WINBASEAPI WINBOOL WINAPI ReplaceFileA(LPCSTR lpReplacedFileName,LPCSTR lpReplacementFileName,LPCSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReplaceFileW(LPCWSTR lpReplacedFileName,LPCWSTR lpReplacementFileName,LPCWSTR lpBackupFileName,DWORD dwReplaceFlags,LPVOID lpExclude,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkA(LPCSTR lpFileName,LPCSTR lpExistingFileName,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI CreateHardLinkW(LPCWSTR lpFileName,LPCWSTR lpExistingFileName,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);

  రకనిర్వచనం గణన ప్రవాహం_INFO_స్థాయిలు {
    కనుగొను_ప్రవాహం_Info_Standard,కనుగొను_ప్రవాహం_Info_Max_Info_Level
  } ప్రవాహం_INFO_స్థాయిలు_2;

  రకనిర్వచనం నిర్మాణం WIN32_కనుగొను_ప్రవాహం_దత్తాంశం {
    LARGE_INTEGER ప్రవాహం_కొలత;
    WCHAR c_ప్రవాహం_Name[MAX_మార్గం + 36];
  } WIN32_కనుగొను_ప్రవాహం_దత్తాంశం_2,*PWIN32_కనుగొను_ప్రవాహం_దత్తాంశం;

  HANDLE WINAPI కనుగొను_మొదటి_ప్రవాహం_W(LPCWSTR lpFileName,ప్రవాహం_INFO_స్థాయిలు_2 InfoLevel,LPVOID lp_కనుగొను_ప్రవాహం_దత్తాంశం,DWORD dwFlags);
  WINBOOL WINAPI కనుగొను_తదుపరి_ప్రవాహం_W(HANDLE h_కనుగొను_ప్రవాహం,LPVOID lp_కనుగొను_ప్రవాహం_దత్తాంశం);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeA(LPCSTR lpName,DWORD dw_Open_బహుళకం,DWORD dw_Pipe_బహుళకం,DWORD nMaxInstances,DWORD n_బహిర్గతం_బఫరు_కొలత,DWORD n_లోపల_బఫరు_కొలత,DWORD n_Default_సమయం_బహిర్గతం,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINBASEAPI HANDLE WINAPI CreateNamedPipeW(LPCWSTR lpName,DWORD dw_Open_బహుళకం,DWORD dw_Pipe_బహుళకం,DWORD nMaxInstances,DWORD n_బహిర్గతం_బఫరు_కొలత,DWORD n_లోపల_బఫరు_కొలత,DWORD n_Default_సమయం_బహిర్గతం,LPSECURITY_లక్షణాలు lp_Security_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateA(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_లెక్క,LPDWORD lp_Collect_దత్తాంశం_Timeout,LPSTR lpUserName,DWORD n_Max_User_Name_కొలత);
  WINBASEAPI WINBOOL WINAPI GetNamedPipeHandleStateW(HANDLE hNamedPipe,LPDWORD lpState,LPDWORD lpCurInstances,LPDWORD lp_Max_Collection_లెక్క,LPDWORD lp_Collect_దత్తాంశం_Timeout,LPWSTR lpUserName,DWORD n_Max_User_Name_కొలత);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeA(LPCSTR lpNamedPipeName,LPVOID lp_లోపల_బఫరు,DWORD n_లోపల_బఫరు_కొలత,LPVOID lp_బహిర్గతం_బఫరు,DWORD n_బహిర్గతం_బఫరు_కొలత,LPDWORD lp_బైట్లు_Read,DWORD n_సమయం_బహిర్గతం);
  WINBASEAPI WINBOOL WINAPI CallNamedPipeW(LPCWSTR lpNamedPipeName,LPVOID lp_లోపల_బఫరు,DWORD n_లోపల_బఫరు_కొలత,LPVOID lp_బహిర్గతం_బఫరు,DWORD n_బహిర్గతం_బఫరు_కొలత,LPDWORD lp_బైట్లు_Read,DWORD n_సమయం_బహిర్గతం);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeA(LPCSTR lpNamedPipeName,DWORD n_సమయం_బహిర్గతం);
  WINBASEAPI WINBOOL WINAPI WaitNamedPipeW(LPCWSTR lpNamedPipeName,DWORD n_సమయం_బహిర్గతం);
  WINBASEAPI WINBOOL WINAPI సమితి_Volume_Label_A(LPCSTR lp_మూలం_మార్గం_Name,LPCSTR lpVolumeName);
  WINBASEAPI WINBOOL WINAPI సమితి_Volume_Label_W(LPCWSTR lp_మూలం_మార్గం_Name,LPCWSTR lpVolumeName);
  WINBASEAPI VOID WINAPI సమితి_File_Apis_గమ్యం_OEM(VOID);
  WINBASEAPI VOID WINAPI సమితి_File_Apis_గమ్యం_ANSI(VOID);
  WINBASEAPI WINBOOL WINAPI AreFileApisANSI(VOID);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationA(LPCSTR lp_మూలం_మార్గం_Name,LPSTR lp_Volume_Name_బఫరు,DWORD n_Volume_Name_కొలత,LPDWORD lp_Volume_Serial_సంఖ్య,LPDWORD lp_గరిష్ఠ_Component_నిడివి,LPDWORD lpFileSystemFlags,LPSTR lp_File_System_Name_బఫరు,DWORD n_File_System_Name_కొలత);
  WINBASEAPI WINBOOL WINAPI GetVolumeInformationW(LPCWSTR lp_మూలం_మార్గం_Name,LPWSTR lp_Volume_Name_బఫరు,DWORD n_Volume_Name_కొలత,LPDWORD lp_Volume_Serial_సంఖ్య,LPDWORD lp_గరిష్ఠ_Component_నిడివి,LPDWORD lpFileSystemFlags,LPWSTR lp_File_System_Name_బఫరు,DWORD n_File_System_Name_కొలత);
  WINBASEAPI WINBOOL WINAPI CancelIo(HANDLE hFile);
  WINADVAPI WINBOOL WINAPI ClearEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI ClearEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogA(HANDLE hEventLog,LPCSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI BackupEventLogW(HANDLE hEventLog,LPCWSTR lpBackupFileName);
  WINADVAPI WINBOOL WINAPI CloseEventLog(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI Deregister_Event_ఆధారం(HANDLE hEventLog);
  WINADVAPI WINBOOL WINAPI NotifyChangeEventLog(HANDLE hEventLog,HANDLE hEvent);
  WINADVAPI WINBOOL WINAPI Get_సంఖ్య_యొక్క_Event_Log_రికార్డులు(HANDLE hEventLog,PDWORD సంఖ్య_యొక్క_రికార్డులు);
  WINADVAPI WINBOOL WINAPI Get_Oldest_Event_Log_రికార్డు(HANDLE hEventLog,PDWORD Oldest_రికార్డు);
  WINADVAPI HANDLE WINAPI OpenEventLogA(LPCSTR lpUNCServerName,LPCSTR lp_ఆధారం_Name);
  WINADVAPI HANDLE WINAPI OpenEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lp_ఆధారం_Name);
  WINADVAPI HANDLE WINAPI రిజిస్టరు_Event_ఆధారం_A(LPCSTR lpUNCServerName,LPCSTR lp_ఆధారం_Name);
  WINADVAPI HANDLE WINAPI రిజిస్టరు_Event_ఆధారం_W(LPCWSTR lpUNCServerName,LPCWSTR lp_ఆధారం_Name);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogA(LPCSTR lpUNCServerName,LPCSTR lpFileName);
  WINADVAPI HANDLE WINAPI OpenBackupEventLogW(LPCWSTR lpUNCServerName,LPCWSTR lpFileName);
  WINADVAPI WINBOOL WINAPI ReadEventLogA(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_రికార్డు_స్థానభ్రంశం,LPVOID lp_బఫరు,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Read,DWORD *pn_బైట్లు_Read,DWORD *pn_Min_సంఖ్య_యొక్క_బైట్లు_Needed);
  WINADVAPI WINBOOL WINAPI ReadEventLogW(HANDLE hEventLog,DWORD dwReadFlags,DWORD dw_రికార్డు_స్థానభ్రంశం,LPVOID lp_బఫరు,DWORD n_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Read,DWORD *pn_బైట్లు_Read,DWORD *pn_Min_సంఖ్య_యొక్క_బైట్లు_Needed);
  WINADVAPI WINBOOL WINAPI ReportEventA(HANDLE hEventLog,మాట_3 wType,మాట_3 wCategory,DWORD dwEventID,PSID lpUserSid,మాట_3 w_అంకె_అక్షరశ్రేణులు,DWORD dw_దత్తాంశం_కొలత,LPCSTR *lp_అక్షరశ్రేణులు,LPVOID lp_Raw_దత్తాంశం);
  WINADVAPI WINBOOL WINAPI ReportEventW(HANDLE hEventLog,మాట_3 wType,మాట_3 wCategory,DWORD dwEventID,PSID lpUserSid,మాట_3 w_అంకె_అక్షరశ్రేణులు,DWORD dw_దత్తాంశం_కొలత,LPCWSTR *lp_అక్షరశ్రేణులు,LPVOID lp_Raw_దత్తాంశం);

#నిర్వచించు EVENTLOG_నిండిన_INFO 0

  రకనిర్వచనం నిర్మాణం EVENTLOG_నిండిన_INFORMATION {
    DWORD dw_నిండిన;
  } EVENTLOG_నిండిన_INFORMATION_2,*LPEVENTLOG_నిండిన_INFORMATION;

  WINADVAPI WINBOOL WINAPI GetEventLogInformation(HANDLE hEventLog,DWORD dwInfoLevel,LPVOID lp_బఫరు,DWORD cb_Buf_కొలత,LPDWORD pcb_బైట్లు_Needed);
  WINADVAPI WINBOOL WINAPI DuplicateToken(HANDLE ExistingTokenHandle,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,PHANDLE DuplicateTokenHandle);
  WINADVAPI WINBOOL WINAPI GetKernelObjectSecurity(HANDLE Handle,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_నిడివి,LPDWORD lpn_నిడివి_Needed);
  WINADVAPI WINBOOL WINAPI ImpersonateNamedPipeClient(HANDLE hNamedPipe);
  WINADVAPI WINBOOL WINAPI ImpersonateSelf(SECURITY_IMPERSONATION_LEVEL ImpersonationLevel);
  WINADVAPI WINBOOL WINAPI Revert_గమ్యం_Self(VOID);
  WINADVAPI WINBOOL WINAPI సమితి_Thread_Token (PHANDLE Thread,HANDLE Token);
  WINADVAPI WINBOOL WINAPI AccessCheck(PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_సమితి Privilege_సమితి,LPDWORD Privilege_సమితి_నిడివి,LPDWORD GrantedAccess,LPBOOL Access_స్థితి);
  WINADVAPI WINBOOL WINAPI AccessCheckByType(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_నిడివి,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_సమితి Privilege_సమితి,LPDWORD Privilege_సమితి_నిడివి,LPDWORD GrantedAccess,LPBOOL Access_స్థితి);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ఫలితం_List(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID PrincipalSelfSid,HANDLE ClientToken,DWORD DesiredAccess,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_నిడివి,PGENERIC_MAPPING GenericMapping,PPRIVILEGE_సమితి Privilege_సమితి,LPDWORD Privilege_సమితి_నిడివి,LPDWORD GrantedAccessList,LPDWORD Access_స్థితి_List);
  WINADVAPI WINBOOL WINAPI OpenProcessToken(HANDLE ProcessHandle,DWORD DesiredAccess,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI OpenThreadToken(HANDLE ThreadHandle,DWORD DesiredAccess,WINBOOL OpenAsSelf,PHANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI GetTokenInformation(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_నిడివి,PDWORD Return_నిడివి);
  WINADVAPI WINBOOL WINAPI సమితి_Token_Information(HANDLE TokenHandle,TOKEN_INFORMATION_CLASS TokenInformationClass,LPVOID TokenInformation,DWORD Token_Information_నిడివి);
  WINADVAPI WINBOOL WINAPI AdjustTokenPrivileges(HANDLE TokenHandle,WINBOOL DisableAllPrivileges,PTOKEN_PRIVILEGES NewState,DWORD బఫరు_నిడివి,PTOKEN_PRIVILEGES మునుపటి_State,PDWORD Return_నిడివి);
  WINADVAPI WINBOOL WINAPI AdjustTokenGroups(HANDLE TokenHandle,WINBOOL Reset_గమ్యం_Default,PTOKEN_GROUPS NewState,DWORD బఫరు_నిడివి,PTOKEN_GROUPS మునుపటి_State,PDWORD Return_నిడివి);
  WINADVAPI WINBOOL WINAPI PrivilegeCheck(HANDLE ClientToken,PPRIVILEGE_సమితి RequiredPrivileges,LPBOOL pf_ఫలితం);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_స్థితి,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,DWORD DesiredAccess,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_స్థితి,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_నిడివి,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_స్థితి,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI AccessCheckByTypeAndAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_నిడివి,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPBOOL Access_స్థితి,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_A(LPCSTR SubsystemName,LPVOID HandleId,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_నిడివి,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_స్థితి_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_W(LPCWSTR SubsystemName,LPVOID HandleId,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_నిడివి,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_స్థితి_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_By_Handle_A(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCSTR ObjectTypeName,LPCSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_నిడివి,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_స్థితి_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI Access_Check_By_Type_ఫలితం_List_And_Audit_Alarm_By_Handle_W(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,LPCWSTR ObjectTypeName,LPCWSTR ObjectName,PSECURITY_DESCRIPTOR SecurityDescriptor,PSID PrincipalSelfSid,DWORD DesiredAccess,AUDIT_EVENT_TYPE AuditType,DWORD Flags,POBJECT_TYPE_LIST ObjectTypeList,DWORD Object_Type_List_నిడివి,PGENERIC_MAPPING GenericMapping,WINBOOL ObjectCreation,LPDWORD GrantedAccess,LPDWORD Access_స్థితి_List,LPBOOL pfGenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,LPSTR ObjectTypeName,LPSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_సమితి Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectOpenAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,LPWSTR ObjectTypeName,LPWSTR ObjectName,PSECURITY_DESCRIPTOR pSecurityDescriptor,HANDLE ClientToken,DWORD DesiredAccess,DWORD GrantedAccess,PPRIVILEGE_సమితి Privileges,WINBOOL ObjectCreation,WINBOOL AccessGranted,LPBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_సమితి Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectPrivilegeAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,HANDLE ClientToken,DWORD DesiredAccess,PPRIVILEGE_సమితి Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectCloseAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmA(LPCSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI ObjectDeleteAuditAlarmW(LPCWSTR SubsystemName,LPVOID HandleId,WINBOOL GenerateOnClose);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmA(LPCSTR SubsystemName,LPCSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_సమితి Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI PrivilegedServiceAuditAlarmW(LPCWSTR SubsystemName,LPCWSTR ServiceName,HANDLE ClientToken,PPRIVILEGE_సమితి Privileges,WINBOOL AccessGranted);
  WINADVAPI WINBOOL WINAPI Is_Well_తెలిసిన_Sid(PSID pSid,WELL_తెలిసిన_SID_TYPE Well_తెలిసిన_Sid_Type);
  WINADVAPI WINBOOL WINAPI Create_Well_తెలిసిన_Sid(WELL_తెలిసిన_SID_TYPE Well_తెలిసిన_Sid_Type,PSID DomainSid,PSID pSid,DWORD *cbSid);
  WINADVAPI WINBOOL WINAPI EqualDomainSid(PSID pSid1,PSID pSid2,WINBOOL *pfEqual);
  WINADVAPI WINBOOL WINAPI GetWindowsAccountDomainSid(PSID pSid,PSID pDomainSid,DWORD *cbDomainSid);
  WINADVAPI WINBOOL WINAPI IsValidSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI EqualSid(PSID pSid1,PSID pSid2);
  WINADVAPI WINBOOL WINAPI Equal_ఉపసర్గ_Sid(PSID pSid1,PSID pSid2);
  WINADVAPI DWORD WINAPI Get_Sid_నిడివి_Required (UCHAR n_Sub_Authority_లెక్క);
  WINADVAPI WINBOOL WINAPI AllocateAndInitializeSid(PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_లెక్క,DWORD nSubAuthority0,DWORD nSubAuthority1,DWORD nSubAuthority2,DWORD nSubAuthority3,DWORD nSubAuthority4,DWORD nSubAuthority5,DWORD nSubAuthority6,DWORD nSubAuthority7,PSID *pSid);
  WINADVAPI PVOID WINAPI FreeSid(PSID pSid);
  WINADVAPI WINBOOL WINAPI InitializeSid(PSID Sid,PSID_IDENTIFIER_AUTHORITY pIdentifierAuthority,BYTE n_Sub_Authority_లెక్క);
  WINADVAPI PSID_IDENTIFIER_AUTHORITY WINAPI GetSidIdentifierAuthority(PSID pSid);
  WINADVAPI PDWORD WINAPI GetSidSubAuthority(PSID pSid,DWORD nSubAuthority);
  WINADVAPI PUCHAR WINAPI Get_Sid_Sub_Authority_లెక్క(PSID pSid);
  WINADVAPI DWORD WINAPI Get_నిడివి_Sid(PSID pSid);
  WINADVAPI WINBOOL WINAPI CopySid(DWORD n_Destination_Sid_నిడివి,PSID pDestinationSid,PSID p_ఆధారం_Sid);
  WINADVAPI WINBOOL WINAPI AreAllAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI WINBOOL WINAPI AreAnyAccessesGranted(DWORD GrantedAccess,DWORD DesiredAccess);
  WINADVAPI VOID WINAPI Map_Generic_ముసుగు(PDWORD Access_ముసుగు,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI IsValidAcl(PACL pAcl);
  WINADVAPI WINBOOL WINAPI InitializeAcl(PACL pAcl,DWORD n_Acl_నిడివి,DWORD dwAclRevision);
  WINADVAPI WINBOOL WINAPI GetAclInformation(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_నిడివి,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI సమితి_Acl_Information(PACL pAcl,LPVOID pAclInformation,DWORD n_Acl_Information_నిడివి,ACL_INFORMATION_CLASS dwAclInformationClass);
  WINADVAPI WINBOOL WINAPI కూడు_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Starting_Ace_సూచీ,LPVOID pAceList,DWORD n_Ace_List_నిడివి);
  WINADVAPI WINBOOL WINAPI DeleteAce(PACL pAcl,DWORD dw_Ace_సూచీ);
  WINADVAPI WINBOOL WINAPI GetAce(PACL pAcl,DWORD dw_Ace_సూచీ,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI కూడు_Access_Allowed_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ముసుగు,PSID pSid);
  WINADVAPI WINBOOL WINAPI కూడు_Access_Allowed_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ముసుగు,PSID pSid);
  WINADVAPI WINBOOL WINAPI కూడు_Access_Denied_Ace(PACL pAcl,DWORD dwAceRevision,DWORD Access_ముసుగు,PSID pSid);
  WINADVAPI WINBOOL WINAPI కూడు_Access_Denied_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ముసుగు,PSID pSid);
  WINADVAPI WINBOOL WINAPI కూడు_Audit_Access_Ace(PACL pAcl,DWORD dwAceRevision,DWORD dw_Access_ముసుగు,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI కూడు_Audit_Access_Ace_Ex(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD dw_Access_ముసుగు,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI కూడు_Access_Allowed_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ముసుగు,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI కూడు_Access_Denied_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ముసుగు,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid);
  WINADVAPI WINBOOL WINAPI కూడు_Audit_Access_Object_Ace(PACL pAcl,DWORD dwAceRevision,DWORD AceFlags,DWORD Access_ముసుగు,GUID *ObjectTypeGuid,GUID *InheritedObjectTypeGuid,PSID pSid,WINBOOL bAuditSuccess,WINBOOL bAuditFailure);
  WINADVAPI WINBOOL WINAPI కనుగొను_మొదటి_Free_Ace(PACL pAcl,LPVOID *pAce);
  WINADVAPI WINBOOL WINAPI InitializeSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD dwRevision);
  WINADVAPI WINBOOL WINAPI IsValidSecurityDescriptor(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI DWORD WINAPI Get_Security_Descriptor_నిడివి(PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorControl(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSECURITY_DESCRIPTOR_CONTROL pControl,LPDWORD lpdwRevision);
  WINADVAPI WINBOOL WINAPI సమితి_Security_Descriptor_Control(PSECURITY_DESCRIPTOR pSecurityDescriptor,SECURITY_DESCRIPTOR_CONTROL Control_బిట్లు_యొక్క_Interest,SECURITY_DESCRIPTOR_CONTROL Control_బిట్లు_గమ్యం_సమితి);
  WINADVAPI WINBOOL WINAPI సమితి_Security_Descriptor_Dacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bDaclPresent,PACL pDacl,WINBOOL bDaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorDacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbDaclPresent,PACL *pDacl,LPBOOL lpbDaclDefaulted);
  WINADVAPI WINBOOL WINAPI సమితి_Security_Descriptor_Sacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,WINBOOL bSaclPresent,PACL pSacl,WINBOOL bSaclDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorSacl(PSECURITY_DESCRIPTOR pSecurityDescriptor,LPBOOL lpbSaclPresent,PACL *pSacl,LPBOOL lpbSaclDefaulted);
  WINADVAPI WINBOOL WINAPI సమితి_Security_Descriptor_Owner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID pOwner,WINBOOL bOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI GetSecurityDescriptorOwner(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *pOwner,LPBOOL lpbOwnerDefaulted);
  WINADVAPI WINBOOL WINAPI సమితి_Security_Descriptor_సమూహం(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID p_సమూహం,WINBOOL b_సమూహం_Defaulted);
  WINADVAPI WINBOOL WINAPI Get_Security_Descriptor_సమూహం(PSECURITY_DESCRIPTOR pSecurityDescriptor,PSID *p_సమూహం,LPBOOL lpb_సమూహం_Defaulted);
  WINADVAPI DWORD WINAPI సమితి_Security_Descriptor_RMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI DWORD WINAPI GetSecurityDescriptorRMControl(PSECURITY_DESCRIPTOR SecurityDescriptor,PUCHAR RMControl);
  WINADVAPI WINBOOL WINAPI Create_వ్యక్తిగత_Object_Security(PSECURITY_DESCRIPTOR మాతృ_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,WINBOOL IsDirectoryObject,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Convert_గమ్యం_Auto_Inherit_వ్యక్తిగత_Object_Security(PSECURITY_DESCRIPTOR మాతృ_Descriptor,PSECURITY_DESCRIPTOR CurrentSecurityDescriptor,PSECURITY_DESCRIPTOR *NewSecurityDescriptor,GUID *ObjectType,BOOLEAN IsDirectoryObject,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_వ్యక్తిగత_Object_Security_Ex(PSECURITY_DESCRIPTOR మాతృ_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID *ObjectType,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI Create_వ్యక్తిగత_Object_Security_With_గుణిజం_Inheritance(PSECURITY_DESCRIPTOR మాతృ_Descriptor,PSECURITY_DESCRIPTOR CreatorDescriptor,PSECURITY_DESCRIPTOR *NewDescriptor,GUID **ObjectTypes,ULONG Guid_లెక్క,WINBOOL IsContainerObject,ULONG AutoInheritFlags,HANDLE Token,PGENERIC_MAPPING GenericMapping);
  WINADVAPI WINBOOL WINAPI సమితి_వ్యక్తిగత_Object_Security (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI సమితి_వ్యక్తిగత_Object_Security_Ex (SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ModificationDescriptor,PSECURITY_DESCRIPTOR *ObjectsSecurityDescriptor,ULONG AutoInheritFlags,PGENERIC_MAPPING GenericMapping,HANDLE Token);
  WINADVAPI WINBOOL WINAPI Get_వ్యక్తిగత_Object_Security(PSECURITY_DESCRIPTOR ObjectDescriptor,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR ResultantDescriptor,DWORD Descriptor_నిడివి,PDWORD Return_నిడివి);
  WINADVAPI WINBOOL WINAPI Destroy_వ్యక్తిగత_Object_Security(PSECURITY_DESCRIPTOR *ObjectDescriptor);
  WINADVAPI WINBOOL WINAPI MakeSelfRelativeSD(PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_బఫరు_నిడివి);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,PSECURITY_DESCRIPTOR pAbsoluteSecurityDescriptor,LPDWORD lpdw_Absolute_Security_Descriptor_కొలత,PACL pDacl,LPDWORD lpdw_Dacl_కొలత,PACL pSacl,LPDWORD lpdw_Sacl_కొలత,PSID pOwner,LPDWORD lpdw_Owner_కొలత,PSID p_Primary_సమూహం,LPDWORD lpdw_Primary_సమూహం_కొలత);
  WINADVAPI WINBOOL WINAPI MakeAbsoluteSD2(PSECURITY_DESCRIPTOR pSelfRelativeSecurityDescriptor,LPDWORD lpdw_బఫరు_కొలత);
  WINADVAPI WINBOOL WINAPI సమితి_File_Security_A(LPCSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI సమితి_File_Security_W(LPCWSTR lpFileName,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor);
  WINADVAPI WINBOOL WINAPI GetFileSecurityA(LPCSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_నిడివి,LPDWORD lpn_నిడివి_Needed);
  WINADVAPI WINBOOL WINAPI GetFileSecurityW(LPCWSTR lpFileName,SECURITY_INFORMATION RequestedInformation,PSECURITY_DESCRIPTOR pSecurityDescriptor,DWORD n_నిడివి,LPDWORD lpn_నిడివి_Needed);
  WINADVAPI WINBOOL WINAPI సమితి_Kernel_Object_Security(HANDLE Handle,SECURITY_INFORMATION SecurityInformation,PSECURITY_DESCRIPTOR SecurityDescriptor);
  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_Change_Notification_A(LPCSTR lp_మార్గం_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_Change_Notification_W(LPCWSTR lp_మార్గం_Name,WINBOOL bWatchSubtree,DWORD dwNotifyFilter);
  WINBASEAPI WINBOOL WINAPI కనుగొను_తదుపరి_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI కనుగొను_Close_Change_Notification(HANDLE hChangeHandle);
  WINBASEAPI WINBOOL WINAPI ReadDirectoryChangesW(HANDLE hDirectory,LPVOID lp_బఫరు,DWORD n_బఫరు_నిడివి,WINBOOL bWatchSubtree,DWORD dwNotifyFilter,LPDWORD lp_బైట్లు_Returned,LPOVERLAPPED lpOverlapped,LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
  WINBASEAPI WINBOOL WINAPI Virtual_తాళం(LPVOID lp_చిరునామా,కొలత_T dw_కొలత);
  WINBASEAPI WINBOOL WINAPI VirtualUnlock(LPVOID lp_చిరునామా,కొలత_T dw_కొలత);
  WINBASEAPI LPVOID WINAPI Map_View_యొక్క_File_Ex(HANDLE hFileMappingObject,DWORD dwDesiredAccess,DWORD dw_File_స్థానభ్రంశం_ఎగువ,DWORD dw_File_స్థానభ్రంశం_దిగువ,కొలత_T dw_సంఖ్య_యొక్క_బైట్లు_గమ్యం_Map,LPVOID lp_పునాది_చిరునామా);
  WINBASEAPI WINBOOL WINAPI సమితి_ప్రాధాన్యత_Class(HANDLE hProcess,DWORD dw_ప్రాధాన్యత_Class);
  WINBASEAPI DWORD WINAPI Get_ప్రాధాన్యత_Class(HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI IsBadReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeReadPtr(CONST VOID *lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI IsBadHugeWritePtr(LPVOID lp,UINT_PTR ucb);
  WINBASEAPI WINBOOL WINAPI Is_Bad_సంకేతం_Ptr(FARPROC lpfn);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrA(LPCSTR lpsz,UINT_PTR ucchMax);
  WINBASEAPI WINBOOL WINAPI IsBadStringPtrW(LPCWSTR lpsz,UINT_PTR ucchMax);
  WINADVAPI WINBOOL WINAPI LookupAccountSidA(LPCSTR lpSystemName,PSID Sid,LPSTR Name,LPDWORD cchName,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountSidW(LPCWSTR lpSystemName,PSID Sid,LPWSTR Name,LPDWORD cchName,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameA(LPCSTR lpSystemName,LPCSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI LookupAccountNameW(LPCWSTR lpSystemName,LPCWSTR lpAccountName,PSID Sid,LPDWORD cbSid,LPWSTR ReferencedDomainName,LPDWORD cchReferencedDomainName,PSID_NAME_USE peUse);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_విలువ_A(LPCSTR lpSystemName,LPCSTR lpName,PLUID lpLuid);
  WINADVAPI WINBOOL WINAPI Lookup_Privilege_విలువ_W(LPCWSTR lpSystemName,LPCWSTR lpName,PLUID lpLuid);
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
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigA(LPCSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_కొలత);
  WINBASEAPI WINBOOL WINAPI GetDefaultCommConfigW(LPCWSTR lpszName,LPCOMMCONFIG lpCC,LPDWORD lpdw_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Default_Comm_Config_A(LPCSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Default_Comm_Config_W(LPCWSTR lpszName,LPCOMMCONFIG lpCC,DWORD dw_కొలత);

#నిర్వచించు MAX_COMPUTERNAME_నిడివి 15

  WINBASEAPI WINBOOL WINAPI GetComputerNameA(LPSTR lp_బఫరు,LPDWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI GetComputerNameW(LPWSTR lp_బఫరు,LPDWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Computer_Name_A(LPCSTR lpComputerName);
  WINBASEAPI WINBOOL WINAPI సమితి_Computer_Name_W(LPCWSTR lpComputerName);

  రకనిర్వచనం గణన _COMPUTER_NAME_FORMAT {
    ComputerNameNetBIOS,ComputerNameDnsHostname,ComputerNameDnsDomain,ComputerNameDnsFullyQualified,ComputerNamePhysicalNetBIOS,ComputerNamePhysicalDnsHostname,ComputerNamePhysicalDnsDomain,ComputerNamePhysicalDnsFullyQualified,ComputerNameMax
  } COMPUTER_NAME_FORMAT;

  WINBASEAPI WINBOOL WINAPI GetComputerNameExA(COMPUTER_NAME_FORMAT NameType,LPSTR lp_బఫరు,LPDWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI GetComputerNameExW(COMPUTER_NAME_FORMAT NameType,LPWSTR lp_బఫరు,LPDWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Computer_Name_Ex_A(COMPUTER_NAME_FORMAT NameType,LPCSTR lp_బఫరు);
  WINBASEAPI WINBOOL WINAPI సమితి_Computer_Name_Ex_W(COMPUTER_NAME_FORMAT NameType,LPCWSTR lp_బఫరు);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_గమ్యం_Computer_Name_A(LPCSTR Hostname,LPSTR ComputerName,LPDWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI Dns_Hostname_గమ్యం_Computer_Name_W(LPCWSTR Hostname,LPWSTR ComputerName,LPDWORD n_కొలత);
  WINADVAPI WINBOOL WINAPI GetUserNameA(LPSTR lp_బఫరు,LPDWORD pcb_బఫరు);
  WINADVAPI WINBOOL WINAPI GetUserNameW(LPWSTR lp_బఫరు,LPDWORD pcb_బఫరు);

#నిర్వచించు LOGON32_LOGON_INTERACTIVE 2
#నిర్వచించు LOGON32_LOGON_జాలం 3
#నిర్వచించు LOGON32_LOGON_BATCH 4
#నిర్వచించు LOGON32_LOGON_SERVICE 5
#నిర్వచించు LOGON32_LOGON_UNLOCK 7
#నిర్వచించు LOGON32_LOGON_జాలం_CLEARTEXT 8
#నిర్వచించు LOGON32_LOGON_NEW_CREDENTIALS 9

#నిర్వచించు LOGON32_PROVIDER_DEFAULT 0
#నిర్వచించు LOGON32_PROVIDER_WINNT35 1
#నిర్వచించు LOGON32_PROVIDER_WINNT40 2
#నిర్వచించు LOGON32_PROVIDER_WINNT50 3

#నిర్వచితమైతే UNICODE
#నిర్వచించు LogonUser LogonUserW
#నిర్వచించు LogonUserEx LogonUserExW
#నిర్వచించు CreateProcessAsUser CreateProcessAsUserW
#లేకపోతే
#నిర్వచించు LogonUser LogonUserA
#నిర్వచించు LogonUserEx LogonUserExA
#నిర్వచించు CreateProcessAsUser CreateProcessAsUserA
#అయితే_ముగింపు

  WINADVAPI WINBOOL WINAPI LogonUserA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken);
  WINADVAPI WINBOOL WINAPI LogonUserExA(LPCSTR lpszUsername,LPCSTR lpszDomain,LPCSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_బఫరు,LPDWORD pdw_Profile_నిడివి,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI LogonUserExW(LPCWSTR lpszUsername,LPCWSTR lpszDomain,LPCWSTR lpszPassword,DWORD dwLogonType,DWORD dwLogonProvider,PHANDLE phToken,PSID *ppLogonSid,PVOID *pp_Profile_బఫరు,LPDWORD pdw_Profile_నిడివి,PQUOTA_LIMITS pQuotaLimits);
  WINADVAPI WINBOOL WINAPI ImpersonateLoggedOnUser(HANDLE hToken);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserA(HANDLE hToken,LPCSTR lpApplicationName,LPSTR lp_Command_పంక్తి,LPSECURITY_లక్షణాలు lp_Process_లక్షణాలు,LPSECURITY_లక్షణాలు lp_Thread_లక్షణాలు,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCSTR lpCurrentDirectory,LPSTARTUPINFOA lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessAsUserW(HANDLE hToken,LPCWSTR lpApplicationName,LPWSTR lp_Command_పంక్తి,LPSECURITY_లక్షణాలు lp_Process_లక్షణాలు,LPSECURITY_లక్షణాలు lp_Thread_లక్షణాలు,WINBOOL bInheritHandles,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);

#నిర్వచించు LOGON_WITH_PROFILE 0x1
#నిర్వచించు LOGON_NETCREDENTIALS_ONLY 0x2
#నిర్వచించు LOGON_ZERO_PASSWORD_బఫరు 0x80000000

  WINADVAPI WINBOOL WINAPI CreateProcessWithLogonW(LPCWSTR lpUsername,LPCWSTR lpDomain,LPCWSTR lpPassword,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_పంక్తి,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI CreateProcessWithTokenW(HANDLE hToken,DWORD dwLogonFlags,LPCWSTR lpApplicationName,LPWSTR lp_Command_పంక్తి,DWORD dwCreationFlags,LPVOID lpEnvironment,LPCWSTR lpCurrentDirectory,LPSTARTUPINFOW lpStartupInfo,LPPROCESS_INFORMATION lpProcessInformation);
  WINADVAPI WINBOOL WINAPI ImpersonateAnonymousToken(HANDLE ThreadHandle);
  WINADVAPI WINBOOL WINAPI DuplicateTokenEx(HANDLE hExistingToken,DWORD dwDesiredAccess,LPSECURITY_లక్షణాలు lp_Token_లక్షణాలు,SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,TOKEN_TYPE TokenType,PHANDLE phNewToken);
  WINADVAPI WINBOOL WINAPI CreateRestrictedToken(HANDLE ExistingTokenHandle,DWORD Flags,DWORD Disable_Sid_లెక్క,PSID_AND_లక్షణాలు Sids_గమ్యం_Disable,DWORD Delete_Privilege_లెక్క,PLUID_AND_లక్షణాలు Privileges_గమ్యం_Delete,DWORD Restricted_Sid_లెక్క,PSID_AND_లక్షణాలు Sids_గమ్యం_Restrict,PHANDLE NewTokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenRestricted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI IsTokenUntrusted(HANDLE TokenHandle);
  WINADVAPI WINBOOL WINAPI CheckTokenMembership(HANDLE TokenHandle,PSID Sid_గమ్యం_Check,PBOOL IsMember);

  రకనిర్వచనం WAITORTIMERCALLBACKFUNC WAITORTIMERCALLBACK;

  WINBASEAPI WINBOOL WINAPI రిజిస్టరు_Wait_For_Single_Object(PHANDLE phNewWaitObject,HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI HANDLE WINAPI రిజిస్టరు_Wait_For_Single_Object_Ex(HANDLE hObject,WAITORTIMERCALLBACK Callback,PVOID Context,ULONG dwMilliseconds,ULONG dwFlags);
  WINBASEAPI WINBOOL WINAPI UnregisterWait(HANDLE WaitHandle);
  WINBASEAPI WINBOOL WINAPI UnregisterWaitEx(HANDLE WaitHandle,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI వరుస_User_Work_అంశం(LPTHREAD_ప్రారంభం_ROUTINE Function,PVOID Context,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI BindIoCompletionCallback(HANDLE FileHandle,LPOVERLAPPED_COMPLETION_ROUTINE Function,ULONG Flags);
  WINBASEAPI HANDLE WINAPI Create_Timer_వరుస(VOID);
  WINBASEAPI WINBOOL WINAPI Create_Timer_వరుస_Timer(PHANDLE phNewTimer,HANDLE Timer_వరుస,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_సమయం,DWORD Period,ULONG Flags);
  WINBASEAPI WINBOOL WINAPI Change_Timer_వరుస_Timer(HANDLE Timer_వరుస,HANDLE Timer,ULONG Due_సమయం,ULONG Period);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_వరుస_Timer(HANDLE Timer_వరుస,HANDLE Timer,HANDLE CompletionEvent);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_వరుస_Ex(HANDLE Timer_వరుస,HANDLE CompletionEvent);
  WINBASEAPI HANDLE WINAPI సమితి_Timer_వరుస_Timer(HANDLE Timer_వరుస,WAITORTIMERCALLBACK Callback,PVOID Parameter,DWORD Due_సమయం,DWORD Period,WINBOOL PreferIo);
  WINBASEAPI WINBOOL WINAPI Cancel_Timer_వరుస_Timer(HANDLE Timer_వరుస,HANDLE Timer);
  WINBASEAPI WINBOOL WINAPI Delete_Timer_వరుస(HANDLE Timer_వరుస);

#నిర్వచించు HW_PROFILE_GUIDLEN 39
#నిర్వచించు MAX_PROFILE_LEN 80

#నిర్వచించు DOCKINFO_UNDOCKED (0x1)
#నిర్వచించు DOCKINFO_DOCKED (0x2)
#నిర్వచించు DOCKINFO_USER_SUPPLIED (0x4)
#నిర్వచించు DOCKINFO_USER_UNDOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_UNDOCKED)
#నిర్వచించు DOCKINFO_USER_DOCKED (DOCKINFO_USER_SUPPLIED | DOCKINFO_DOCKED)

  రకనిర్వచనం నిర్మాణం ట్యాగ్_HW_PROFILE_INFOA {
    DWORD dwDockInfo;
    CHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    CHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOA,*LPHW_PROFILE_INFOA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_HW_PROFILE_INFOW {
    DWORD dwDockInfo;
    WCHAR szHwProfileGuid[HW_PROFILE_GUIDLEN];
    WCHAR szHwProfileName[MAX_PROFILE_LEN];
  } HW_PROFILE_INFOW,*LPHW_PROFILE_INFOW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం HW_PROFILE_INFOW HW_PROFILE_INFO;
  రకనిర్వచనం LPHW_PROFILE_INFOW LPHW_PROFILE_INFO;
#లేకపోతే
  రకనిర్వచనం HW_PROFILE_INFOA HW_PROFILE_INFO;
  రకనిర్వచనం LPHW_PROFILE_INFOA LPHW_PROFILE_INFO;
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు GetCurrentHwProfile GetCurrentHwProfileW
#నిర్వచించు Get_సంస్కరణ_Ex Get_సంస్కరణ_Ex_W
#నిర్వచించు Verify_సంస్కరణ_Info Verify_సంస్కరణ_Info_W
#లేకపోతే
#నిర్వచించు GetCurrentHwProfile GetCurrentHwProfileA
#నిర్వచించు Get_సంస్కరణ_Ex Get_సంస్కరణ_Ex_A
#నిర్వచించు Verify_సంస్కరణ_Info Verify_సంస్కరణ_Info_A
#అయితే_ముగింపు

  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileA (LPHW_PROFILE_INFOA lpHwProfileInfo);
  WINADVAPI WINBOOL WINAPI GetCurrentHwProfileW (LPHW_PROFILE_INFOW lpHwProfileInfo);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceCounter(LARGE_INTEGER *lp_Performance_లెక్క);
  WINBASEAPI WINBOOL WINAPI QueryPerformanceFrequency(LARGE_INTEGER *lpFrequency);
  WINBASEAPI WINBOOL WINAPI Get_సంస్కరణ_Ex_A(LPOSVERSIONINFOA lp_సంస్కరణ_Information);
  WINBASEAPI WINBOOL WINAPI Get_సంస్కరణ_Ex_W(LPOSVERSIONINFOW lp_సంస్కరణ_Information);
  WINBASEAPI WINBOOL WINAPI Verify_సంస్కరణ_Info_A(LPOSVERSIONINFOEXA lp_సంస్కరణ_Information,DWORD dw_Type_ముసుగు,DWORDLONG dwl_Condition_ముసుగు);
  WINBASEAPI WINBOOL WINAPI Verify_సంస్కరణ_Info_W(LPOSVERSIONINFOEXW lp_సంస్కరణ_Information,DWORD dw_Type_ముసుగు,DWORDLONG dwl_Condition_ముసుగు);

#అన్తర్భావ <winerror.h>

#నిర్వచించు TC_సాధారణ 0
#నిర్వచించు TC_HARDERR 1
#నిర్వచించు TC_GP_TRAP 2
#నిర్వచించు TC_SIGNAL 3

#నిర్వచించు AC_పంక్తి_OFFLINE 0x0
#నిర్వచించు AC_పంక్తి_ONLINE 0x1
#నిర్వచించు AC_పంక్తి_BACKUP_POWER 0x2
#నిర్వచించు AC_పంక్తి_UNKNOWN 0xff

#నిర్వచించు BATTERY_FLAG_ఎగువ 0x1
#నిర్వచించు BATTERY_FLAG_దిగువ 0x2
#నిర్వచించు BATTERY_FLAG_CRITICAL 0x4
#నిర్వచించు BATTERY_FLAG_CHARGING 0x8
#నిర్వచించు BATTERY_FLAG_NO_BATTERY 0x80
#నిర్వచించు BATTERY_FLAG_UNKNOWN 0xff

#నిర్వచించు BATTERY_PERCENTAGE_UNKNOWN 0xff

#నిర్వచించు BATTERY_LIFE_UNKNOWN 0xffffffff

  రకనిర్వచనం నిర్మాణం SYSTEM_POWER_స్థితి {
    BYTE ACLine_స్థితి;
    BYTE BatteryFlag;
    BYTE BatteryLifePercent;
    BYTE Reserved1;
    DWORD Battery_Life_సమయం;
    DWORD Battery_నిండిన_Life_సమయం;
  } SYSTEM_POWER_స్థితి_2,*LPSYSTEM_POWER_స్థితి;

#నిర్వచితమైతే UNICODE
#నిర్వచించు Create_పని_Object Create_పని_Object_W
#నిర్వచించు Open_పని_Object Open_పని_Object_W
#నిర్వచించు కనుగొను_మొదటి_Volume కనుగొను_మొదటి_Volume_W
#నిర్వచించు కనుగొను_తదుపరి_Volume కనుగొను_తదుపరి_Volume_W
#నిర్వచించు కనుగొను_మొదటి_Volume_Mount_బిందువు కనుగొను_మొదటి_Volume_Mount_బిందువు_W
#నిర్వచించు కనుగొను_తదుపరి_Volume_Mount_బిందువు కనుగొను_తదుపరి_Volume_Mount_బిందువు_W
#నిర్వచించు సమితి_Volume_Mount_బిందువు సమితి_Volume_Mount_బిందువు_W
#నిర్వచించు Delete_Volume_Mount_బిందువు Delete_Volume_Mount_బిందువు_W
#నిర్వచించు Get_Volume_Name_For_Volume_Mount_బిందువు Get_Volume_Name_For_Volume_Mount_బిందువు_W
#నిర్వచించు Get_Volume_మార్గం_Name Get_Volume_మార్గం_Name_W
#నిర్వచించు Get_Volume_మార్గం_పేర్లు_For_Volume_Name Get_Volume_మార్గం_పేర్లు_For_Volume_Name_W
#లేకపోతే
#నిర్వచించు Create_పని_Object Create_పని_Object_A
#నిర్వచించు Open_పని_Object Open_పని_Object_A
#నిర్వచించు కనుగొను_మొదటి_Volume కనుగొను_మొదటి_Volume_A
#నిర్వచించు కనుగొను_తదుపరి_Volume కనుగొను_తదుపరి_Volume_A
#నిర్వచించు కనుగొను_మొదటి_Volume_Mount_బిందువు కనుగొను_మొదటి_Volume_Mount_బిందువు_A
#నిర్వచించు కనుగొను_తదుపరి_Volume_Mount_బిందువు కనుగొను_తదుపరి_Volume_Mount_బిందువు_A
#నిర్వచించు సమితి_Volume_Mount_బిందువు సమితి_Volume_Mount_బిందువు_A
#నిర్వచించు Delete_Volume_Mount_బిందువు Delete_Volume_Mount_బిందువు_A
#నిర్వచించు Get_Volume_Name_For_Volume_Mount_బిందువు Get_Volume_Name_For_Volume_Mount_బిందువు_A
#నిర్వచించు Get_Volume_మార్గం_Name Get_Volume_మార్గం_Name_A
#నిర్వచించు Get_Volume_మార్గం_పేర్లు_For_Volume_Name Get_Volume_మార్గం_పేర్లు_For_Volume_Name_A
#అయితే_ముగింపు

  WINBOOL WINAPI Get_System_Power_స్థితి(LPSYSTEM_POWER_స్థితి lp_System_Power_స్థితి);
  WINBOOL WINAPI సమితి_System_Power_State(WINBOOL fSuspend,WINBOOL fForce);
  WINBASEAPI WINBOOL WINAPI Allocate_User_Physical_పుటలు(HANDLE hProcess,PULONG_PTR సంఖ్య_యొక్క_పుటలు,PULONG_PTR పుట_Array);
  WINBASEAPI WINBOOL WINAPI Free_User_Physical_పుటలు(HANDLE hProcess,PULONG_PTR సంఖ్య_యొక్క_పుటలు,PULONG_PTR పుట_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_పుటలు(PVOID Virtual_చిరునామా,ULONG_PTR సంఖ్య_యొక్క_పుటలు,PULONG_PTR పుట_Array);
  WINBASEAPI WINBOOL WINAPI Map_User_Physical_పుటలు_Scatter(PVOID *Virtual_చిరునామాలు,ULONG_PTR సంఖ్య_యొక్క_పుటలు,PULONG_PTR పుట_Array);
  WINBASEAPI HANDLE WINAPI Create_పని_Object_A(LPSECURITY_లక్షణాలు lp_పని_లక్షణాలు,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Create_పని_Object_W(LPSECURITY_లక్షణాలు lp_పని_లక్షణాలు,LPCWSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_పని_Object_A(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCSTR lpName);
  WINBASEAPI HANDLE WINAPI Open_పని_Object_W(DWORD dwDesiredAccess,WINBOOL bInheritHandle,LPCWSTR lpName);
  WINBASEAPI WINBOOL WINAPI కేటాయించు_Process_గమ్యం_పని_Object(HANDLE h_పని,HANDLE hProcess);
  WINBASEAPI WINBOOL WINAPI Terminate_పని_Object(HANDLE h_పని,UINT u_Exit_సంకేతం);
  WINBASEAPI WINBOOL WINAPI Query_Information_పని_Object(HANDLE h_పని,JOBOBJECTINFOCLASS పని_Object_Information_Class,LPVOID lp_పని_Object_Information,DWORD cb_పని_Object_Information_నిడివి,LPDWORD lp_Return_నిడివి);
  WINBASEAPI WINBOOL WINAPI సమితి_Information_పని_Object(HANDLE h_పని,JOBOBJECTINFOCLASS పని_Object_Information_Class,LPVOID lp_పని_Object_Information,DWORD cb_పని_Object_Information_నిడివి);
  WINBASEAPI WINBOOL WINAPI Is_Process_లోపల_పని(HANDLE ProcessHandle,HANDLE పని_Handle,PBOOL ఫలితం_3);
  WINBASEAPI WINBOOL WINAPI Create_పని_సమితి(ULONG అంకె_పని,PJOB_సమితి_ARRAY User_పని_సమితి,ULONG Flags);
  WINBASEAPI PVOID WINAPI కూడు_Vectored_Exception_Handler (ULONG మొదటి_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredExceptionHandler(PVOID Handle);
  WINBASEAPI PVOID WINAPI కూడు_Vectored_Continue_Handler (ULONG మొదటి_3,PVECTORED_EXCEPTION_HANDLER Handler);
  WINBASEAPI ULONG WINAPI RemoveVectoredContinueHandler(PVOID Handle);
  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_Volume_A(LPSTR lpszVolumeName,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_Volume_W(LPWSTR lpszVolumeName,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI కనుగొను_తదుపరి_Volume_A(HANDLE h_కనుగొను_Volume,LPSTR lpszVolumeName,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI కనుగొను_తదుపరి_Volume_W(HANDLE h_కనుగొను_Volume,LPWSTR lpszVolumeName,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI కనుగొను_Volume_Close(HANDLE h_కనుగొను_Volume);
  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_Volume_Mount_బిందువు_A(LPCSTR lpsz_మూలం_మార్గం_Name,LPSTR lpsz_Volume_Mount_బిందువు,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI HANDLE WINAPI కనుగొను_మొదటి_Volume_Mount_బిందువు_W(LPCWSTR lpsz_మూలం_మార్గం_Name,LPWSTR lpsz_Volume_Mount_బిందువు,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI కనుగొను_తదుపరి_Volume_Mount_బిందువు_A(HANDLE h_కనుగొను_Volume_Mount_బిందువు,LPSTR lpsz_Volume_Mount_బిందువు,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI కనుగొను_తదుపరి_Volume_Mount_బిందువు_W(HANDLE h_కనుగొను_Volume_Mount_బిందువు,LPWSTR lpsz_Volume_Mount_బిందువు,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI కనుగొను_Volume_Mount_బిందువు_Close(HANDLE h_కనుగొను_Volume_Mount_బిందువు);
  WINBASEAPI WINBOOL WINAPI సమితి_Volume_Mount_బిందువు_A(LPCSTR lpsz_Volume_Mount_బిందువు,LPCSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI సమితి_Volume_Mount_బిందువు_W(LPCWSTR lpsz_Volume_Mount_బిందువు,LPCWSTR lpszVolumeName);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_బిందువు_A(LPCSTR lpsz_Volume_Mount_బిందువు);
  WINBASEAPI WINBOOL WINAPI Delete_Volume_Mount_బిందువు_W(LPCWSTR lpsz_Volume_Mount_బిందువు);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_బిందువు_A(LPCSTR lpsz_Volume_Mount_బిందువు,LPSTR lpszVolumeName,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI Get_Volume_Name_For_Volume_Mount_బిందువు_W(LPCWSTR lpsz_Volume_Mount_బిందువు,LPWSTR lpszVolumeName,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI Get_Volume_మార్గం_Name_A(LPCSTR lpszFileName,LPSTR lpsz_Volume_మార్గం_Name,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI Get_Volume_మార్గం_Name_W(LPCWSTR lpszFileName,LPWSTR lpsz_Volume_మార్గం_Name,DWORD cch_బఫరు_నిడివి);
  WINBASEAPI WINBOOL WINAPI Get_Volume_మార్గం_పేర్లు_For_Volume_Name_A(LPCSTR lpszVolumeName,LPCH lpsz_Volume_మార్గం_పేర్లు,DWORD cch_బఫరు_నిడివి,PDWORD lpcch_Return_నిడివి);
  WINBASEAPI WINBOOL WINAPI Get_Volume_మార్గం_పేర్లు_For_Volume_Name_W(LPCWSTR lpszVolumeName,LPWCH lpsz_Volume_మార్గం_పేర్లు,DWORD cch_బఫరు_నిడివి,PDWORD lpcch_Return_నిడివి);

#నిర్వచించు ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID 0x1
#నిర్వచించు ACTCTX_FLAG_LANGID_VALID 0x2
#నిర్వచించు ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID 0x4
#నిర్వచించు ACTCTX_FLAG_RESOURCE_NAME_VALID 0x8
#నిర్వచించు ACTCTX_FLAG_సమితి_PROCESS_DEFAULT 0x10
#నిర్వచించు ACTCTX_FLAG_APPLICATION_NAME_VALID 0x20
#నిర్వచించు ACTCTX_FLAG_ఆధారం_IS_ASSEMBLYREF 0x40
#నిర్వచించు ACTCTX_FLAG_HMODULE_VALID 0x80

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ACTCTXA {
    ULONG cb_కొలత;
    DWORD dwFlags;
    LPCSTR lp_ఆధారం;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCSTR lpAssemblyDirectory;
    LPCSTR lpResourceName;
    LPCSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXA,*PACTCTXA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ACTCTXW {
    ULONG cb_కొలత;
    DWORD dwFlags;
    LPCWSTR lp_ఆధారం;
    USHORT wProcessorArchitecture;
    LANGID wLangId;
    LPCWSTR lpAssemblyDirectory;
    LPCWSTR lpResourceName;
    LPCWSTR lpApplicationName;
    HMODULE hModule;
  } ACTCTXW,*PACTCTXW;

  రకనిర్వచనం స్థిరరాశి ACTCTXA *PCACTCTXA;
  రకనిర్వచనం స్థిరరాశి ACTCTXW *PCACTCTXW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం ACTCTXW ACTCTX;
  రకనిర్వచనం PACTCTXW PACTCTX;
  రకనిర్వచనం PCACTCTXW PCACTCTX;
#లేకపోతే
  రకనిర్వచనం ACTCTXA ACTCTX;
  రకనిర్వచనం PACTCTXA PACTCTX;
  రకనిర్వచనం PCACTCTXA PCACTCTX;
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు CreateActCtx CreateActCtxW
#లేకపోతే
#నిర్వచించు CreateActCtx CreateActCtxA
#అయితే_ముగింపు

  WINBASEAPI HANDLE WINAPI CreateActCtxA(PCACTCTXA pActCtx);
  WINBASEAPI HANDLE WINAPI CreateActCtxW(PCACTCTXW pActCtx);
  WINBASEAPI VOID WINAPI కూడు_Ref_Act_Ctx(HANDLE hActCtx);
  WINBASEAPI VOID WINAPI ReleaseActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ZombifyActCtx(HANDLE hActCtx);
  WINBASEAPI WINBOOL WINAPI ActivateActCtx(HANDLE hActCtx,ULONG_PTR *lpCookie);

#నిర్వచించు DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION (0x1)

  WINBASEAPI WINBOOL WINAPI DeactivateActCtx(DWORD dwFlags,ULONG_PTR ulCookie);
  WINBASEAPI WINBOOL WINAPI GetCurrentActCtx(HANDLE *lphActCtx);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ACTCTX_SECTION_KEYED_దత్తాంశం_2600 {
    ULONG cb_కొలత;
    ULONG ul_దత్తాంశం_Format_సంస్కరణ;
    PVOID lp_దత్తాంశం;
    ULONG ul_నిడివి;
    PVOID lp_Section_Global_దత్తాంశం;
    ULONG ul_Section_Global_దత్తాంశం_నిడివి;
    PVOID lp_Section_పునాది;
    ULONG ul_Section_మొత్తం_నిడివి;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_సూచీ;
  } ACTCTX_SECTION_KEYED_దత్తాంశం_2600,*PACTCTX_SECTION_KEYED_దత్తాంశం_2600;

  రకనిర్వచనం స్థిరరాశి ACTCTX_SECTION_KEYED_దత్తాంశం_2600 *PCACTCTX_SECTION_KEYED_దత్తాంశం_2600;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ACTCTX_SECTION_KEYED_దత్తాంశం_ASSEMBLY_METADATA {
    PVOID lpInformation;
    PVOID lp_Section_పునాది;
    ULONG ul_Section_నిడివి;
    PVOID lp_Section_Global_దత్తాంశం_పునాది;
    ULONG ul_Section_Global_దత్తాంశం_నిడివి;
  } ACTCTX_SECTION_KEYED_దత్తాంశం_ASSEMBLY_METADATA,*PACTCTX_SECTION_KEYED_దత్తాంశం_ASSEMBLY_METADATA;

  రకనిర్వచనం స్థిరరాశి ACTCTX_SECTION_KEYED_దత్తాంశం_ASSEMBLY_METADATA *PCACTCTX_SECTION_KEYED_దత్తాంశం_ASSEMBLY_METADATA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ACTCTX_SECTION_KEYED_దత్తాంశం {
    ULONG cb_కొలత;
    ULONG ul_దత్తాంశం_Format_సంస్కరణ;
    PVOID lp_దత్తాంశం;
    ULONG ul_నిడివి;
    PVOID lp_Section_Global_దత్తాంశం;
    ULONG ul_Section_Global_దత్తాంశం_నిడివి;
    PVOID lp_Section_పునాది;
    ULONG ul_Section_మొత్తం_నిడివి;
    HANDLE hActCtx;
    ULONG ul_Assembly_Roster_సూచీ;

    ULONG ulFlags;
    ACTCTX_SECTION_KEYED_దత్తాంశం_ASSEMBLY_METADATA AssemblyMetadata;
  } ACTCTX_SECTION_KEYED_దత్తాంశం,*PACTCTX_SECTION_KEYED_దత్తాంశం;

  రకనిర్వచనం స్థిరరాశి ACTCTX_SECTION_KEYED_దత్తాంశం *PCACTCTX_SECTION_KEYED_దత్తాంశం;

#నిర్వచించు కనుగొను_ACTCTX_SECTION_కీలకం_RETURN_HACTCTX 0x1
#నిర్వచించు కనుగొను_ACTCTX_SECTION_కీలకం_RETURN_FLAGS 0x2
#నిర్వచించు కనుగొను_ACTCTX_SECTION_కీలకం_RETURN_ASSEMBLY_METADATA 0x4

#నిర్వచితమైతే UNICODE
#నిర్వచించు కనుగొను_Act_Ctx_Section_String కనుగొను_Act_Ctx_Section_String_W
#లేకపోతే
#నిర్వచించు కనుగొను_Act_Ctx_Section_String కనుగొను_Act_Ctx_Section_String_A
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI కనుగొను_Act_Ctx_Section_String_A(DWORD dwFlags,స్థిరరాశి GUID *lpExtensionGuid,ULONG ulSectionId,LPCSTR lp_String_గమ్యం_కనుగొను,PACTCTX_SECTION_KEYED_దత్తాంశం Returned_దత్తాంశం);
  WINBASEAPI WINBOOL WINAPI కనుగొను_Act_Ctx_Section_String_W(DWORD dwFlags,స్థిరరాశి GUID *lpExtensionGuid,ULONG ulSectionId,LPCWSTR lp_String_గమ్యం_కనుగొను,PACTCTX_SECTION_KEYED_దత్తాంశం Returned_దత్తాంశం);
  WINBASEAPI WINBOOL WINAPI కనుగొను_Act_Ctx_Section_Guid(DWORD dwFlags,స్థిరరాశి GUID *lpExtensionGuid,ULONG ulSectionId,స్థిరరాశి GUID *lp_Guid_గమ్యం_కనుగొను,PACTCTX_SECTION_KEYED_దత్తాంశం Returned_దత్తాంశం);

#నిర్వచితం_కాకపోతే RC_INVOKED
#నిర్వచితం_కాకపోతే ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED

  రకనిర్వచనం నిర్మాణం _ACTIVATION_CONTEXT_BASIC_INFORMATION {
    HANDLE hActCtx;
    DWORD dwFlags;
  } ACTIVATION_CONTEXT_BASIC_INFORMATION,*PACTIVATION_CONTEXT_BASIC_INFORMATION;

  రకనిర్వచనం స్థిరరాశి నిర్మాణం _ACTIVATION_CONTEXT_BASIC_INFORMATION *PCACTIVATION_CONTEXT_BASIC_INFORMATION;

#నిర్వచించు ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED 1
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు QUERY_ACTCTX_FLAG_USE_చురుకైన_ACTCTX 0x4
#నిర్వచించు QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE 0x8
#నిర్వచించు QUERY_ACTCTX_FLAG_ACTCTX_IS_చిరునామా 0x10
#నిర్వచించు QUERY_ACTCTX_FLAG_NO_ADDREF 0x80000000

  WINBASEAPI WINBOOL WINAPI QueryActCtxW(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_బఫరు,కొలత_T cb_బఫరు,కొలత_T *pcbWrittenOrRequired);

  రకనిర్వచనం WINBOOL (WINAPI *PQUERYACTCTXW_FUNC)(DWORD dwFlags,HANDLE hActCtx,PVOID pvSubInstance,ULONG ulInfoClass,PVOID pv_బఫరు,కొలత_T cb_బఫరు,కొలత_T *pcbWrittenOrRequired);

  WINBASEAPI WINBOOL WINAPI Process_Id_గమ్యం_Session_Id(DWORD dwProcessId,DWORD *pSessionId);
  WINBASEAPI DWORD WINAPI WTSGet_చురుకైన_Console_Session_Id();
  WINBASEAPI WINBOOL WINAPI IsWow64Process(HANDLE hProcess,PBOOL Wow64Process);
  WINBASEAPI WINBOOL WINAPI GetLogicalProcessorInformation(PSYSTEM_LOGICAL_PROCESSOR_INFORMATION బఫరు_3,PDWORD Returned_నిడివి);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Highest_కణుపు_సంఖ్య(PULONG Highest_కణుపు_సంఖ్య);
  WINBASEAPI WINBOOL WINAPI Get_Numa_Processor_కణుపు(UCHAR Processor,PUCHAR కణుపు_సంఖ్య);
  WINBASEAPI WINBOOL WINAPI Get_Numa_కణుపు_Processor_ముసుగు(UCHAR కణుపు_2,PULONGLONG Processor_ముసుగు);
  WINBASEAPI WINBOOL WINAPI Get_Numa_అందుబాటు_జ్ఞాపకం_కణుపు(UCHAR కణుపు_2,PULONGLONG అందుబాటు_బైట్లు);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
