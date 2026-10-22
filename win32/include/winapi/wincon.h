/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _WINCON_
#నిర్వచించు _WINCON_

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  రకనిర్వచనం నిర్మాణం _SMALL_RECT {
    SHORT ఎడమ_2;
    SHORT శిఖరం_2;
    SHORT కుడి_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  రకనిర్వచనం నిర్మాణం కీలకం_EVENT_రికార్డు {
    WINBOOL b_కీలకం_కిందికి;
    మాట_3 w_Repeat_లెక్క;
    మాట_3 w_Virtual_కీలకం_సంకేతం;
    మాట_3 w_Virtual_పరిశీలన_సంకేతం;
    సంఘం {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_కీలకం_State;
  } కీలకం_EVENT_రికార్డు_2,*PKEY_EVENT_రికార్డు;

#నిర్వచించు కుడి_ALT_PRESSED 0x1
#నిర్వచించు ఎడమ_ALT_PRESSED 0x2
#నిర్వచించు కుడి_CTRL_PRESSED 0x4
#నిర్వచించు ఎడమ_CTRL_PRESSED 0x8
#నిర్వచించు జరుపు_PRESSED 0x10
#నిర్వచించు NUMLOCK_ON 0x20
#నిర్వచించు SCROLLLOCK_ON 0x40
#నిర్వచించు CAPSLOCK_ON 0x80
#నిర్వచించు ENHANCED_కీలకం 0x100
#నిర్వచించు NLS_DBCSCHAR 0x10000
#నిర్వచించు NLS_ALPHANUMERIC 0x0
#నిర్వచించు NLS_KATAKANA 0x20000
#నిర్వచించు NLS_HIRAGANA 0x40000
#నిర్వచించు NLS_ROMAN 0x400000
#నిర్వచించు NLS_IME_CONVERSION 0x800000
#నిర్వచించు NLS_IME_DISABLE 0x20000000

  రకనిర్వచనం నిర్మాణం MOUSE_EVENT_రికార్డు {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_కీలకం_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_రికార్డు_2,*PMOUSE_EVENT_రికార్డు;

#నిర్వచించు FROM_ఎడమ_1_ST_BUTTON_PRESSED 0x1
#నిర్వచించు RIGHTMOST_BUTTON_PRESSED 0x2
#నిర్వచించు FROM_ఎడమ_2_ND_BUTTON_PRESSED 0x4
#నిర్వచించు FROM_ఎడమ_3_RD_BUTTON_PRESSED 0x8
#నిర్వచించు FROM_ఎడమ_4_TH_BUTTON_PRESSED 0x10

#నిర్వచించు MOUSE_MOVED 0x1
#నిర్వచించు DOUBLE_CLICK 0x2
#నిర్వచించు MOUSE_WHEELED 0x4

  రకనిర్వచనం నిర్మాణం కిటికీ_బఫరు_కొలత_రికార్డు {
    COORD dw_కొలత;
  } కిటికీ_బఫరు_కొలత_రికార్డు_2,*PWINDOW_బఫరు_కొలత_రికార్డు;

  రకనిర్వచనం నిర్మాణం MENU_EVENT_రికార్డు {
    UINT dwCommandId;
  } MENU_EVENT_రికార్డు_2,*PMENU_EVENT_రికార్డు;

  రకనిర్వచనం నిర్మాణం FOCUS_EVENT_రికార్డు {
    WINBOOL b_సమితి_Focus;
  } FOCUS_EVENT_రికార్డు_2,*PFOCUS_EVENT_రికార్డు;

  రకనిర్వచనం నిర్మాణం ఆదానం_రికార్డు {
    మాట_3 EventType;
    సంఘం {
      కీలకం_EVENT_రికార్డు_2 కీలకం_Event;
      MOUSE_EVENT_రికార్డు_2 MouseEvent;
      కిటికీ_బఫరు_కొలత_రికార్డు_2 కిటికీ_బఫరు_కొలత_Event;
      MENU_EVENT_రికార్డు_2 MenuEvent;
      FOCUS_EVENT_రికార్డు_2 FocusEvent;
    } Event;
  } ఆదానం_రికార్డు_2,*PINPUT_రికార్డు;

#నిర్వచించు కీలకం_EVENT 0x1
#నిర్వచించు MOUSE_EVENT 0x2
#నిర్వచించు కిటికీ_బఫరు_కొలత_EVENT 0x4
#నిర్వచించు MENU_EVENT 0x8
#నిర్వచించు FOCUS_EVENT 0x10

  రకనిర్వచనం నిర్మాణం _CHAR_INFO {
    సంఘం {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    మాట_3 లక్షణాలు;
  } CHAR_INFO,*PCHAR_INFO;

#నిర్వచించు FOREGROUND_BLUE 0x1
#నిర్వచించు FOREGROUND_GREEN 0x2
#నిర్వచించు FOREGROUND_RED 0x4
#నిర్వచించు FOREGROUND_INTENSITY 0x8
#నిర్వచించు BACKGROUND_BLUE 0x10
#నిర్వచించు BACKGROUND_GREEN 0x20
#నిర్వచించు BACKGROUND_RED 0x40
#నిర్వచించు BACKGROUND_INTENSITY 0x80
#నిర్వచించు COMMON_LVB_LEADING_BYTE 0x100
#నిర్వచించు COMMON_LVB_TRAILING_BYTE 0x200
#నిర్వచించు COMMON_LVB_GRID_HORIZONTAL 0x400
#నిర్వచించు COMMON_LVB_GRID_LVERTICAL 0x800
#నిర్వచించు COMMON_LVB_GRID_RVERTICAL 0x1000
#నిర్వచించు COMMON_LVB_తిరగేయి_VIDEO 0x4000
#నిర్వచించు COMMON_LVB_UNDERSCORE 0x8000

#నిర్వచించు COMMON_LVB_SBCSDBCS 0x300

  రకనిర్వచనం నిర్మాణం CONSOLE_SCREEN_బఫరు_INFO {
    COORD dw_కొలత;
    COORD dwCursorPosition;
    మాట_3 w_లక్షణాలు;
    SMALL_RECT sr_కిటికీ;
    COORD dw_గరిష్ఠ_కిటికీ_కొలత;
  } CONSOLE_SCREEN_బఫరు_INFO_2,*PCONSOLE_SCREEN_బఫరు_INFO;

  రకనిర్వచనం నిర్మాణం _CONSOLE_CURSOR_INFO {
    DWORD dw_కొలత;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  రకనిర్వచనం నిర్మాణం _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dw_Font_కొలత;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  రకనిర్వచనం నిర్మాణం _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#నిర్వచించు CONSOLE_NO_SELECTION 0x0
#నిర్వచించు CONSOLE_SELECTION_లోపల_పురోగతి 0x1
#నిర్వచించు CONSOLE_SELECTION_NOT_ఖాళీలు 0x2
#నిర్వచించు CONSOLE_MOUSE_SELECTION 0x4
#నిర్వచించు CONSOLE_MOUSE_కిందికి 0x8

  రకనిర్వచనం WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#నిర్వచించు CTRL_C_EVENT 0
#నిర్వచించు CTRL_BREAK_EVENT 1
#నిర్వచించు CTRL_CLOSE_EVENT 2

#నిర్వచించు CTRL_LOGOFF_EVENT 5
#నిర్వచించు CTRL_SHUTDOWN_EVENT 6

#నిర్వచించు ENABLE_PROCESSED_ఆదానం 0x1
#నిర్వచించు ENABLE_పంక్తి_ఆదానం 0x2
#నిర్వచించు ENABLE_ECHO_ఆదానం 0x4
#నిర్వచించు ENABLE_కిటికీ_ఆదానం 0x8
#నిర్వచించు ENABLE_MOUSE_ఆదానం 0x10
#నిర్వచించు ENABLE_చొప్పించు_బహుళకం 0x20
#నిర్వచించు ENABLE_శీఘ్ర_EDIT_బహుళకం 0x40
#నిర్వచించు ENABLE_EXTENDED_FLAGS 0x80
#నిర్వచించు ENABLE_AUTO_POSITION 0x100
#నిర్వచించు ENABLE_VIRTUAL_TERMINAL_ఆదానం 0x200

#నిర్వచించు ENABLE_PROCESSED_OUTPUT 0x1
#నిర్వచించు ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#నిర్వచించు ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#నిర్వచించు DISABLE_NEWLINE_AUTO_RETURN 0x8
#నిర్వచించు ENABLE_LVB_GRID_WORLDWIDE 0x10

#నిర్వచితమైతే UNICODE
#నిర్వచించు Peek_Console_ఆదానం Peek_Console_ఆదానం_W
#నిర్వచించు Read_Console_ఆదానం Read_Console_ఆదానం_W
#నిర్వచించు Write_Console_ఆదానం Write_Console_ఆదానం_W
#నిర్వచించు ReadConsoleOutput ReadConsoleOutputW
#నిర్వచించు WriteConsoleOutput WriteConsoleOutputW
#నిర్వచించు ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#నిర్వచించు WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#నిర్వచించు FillConsoleOutputCharacter FillConsoleOutputCharacterW
#నిర్వచించు Scroll_Console_Screen_బఫరు Scroll_Console_Screen_బఫరు_W
#నిర్వచించు GetConsoleTitle GetConsoleTitleW
#నిర్వచించు సమితి_Console_Title సమితి_Console_Title_W
#నిర్వచించు ReadConsole ReadConsoleW
#నిర్వచించు WriteConsole WriteConsoleW
#నిర్వచించు కూడు_Console_Alias కూడు_Console_Alias_W
#నిర్వచించు GetConsoleAlias GetConsoleAliasW
#నిర్వచించు Get_Console_Aliases_నిడివి Get_Console_Aliases_నిడివి_W
#నిర్వచించు Get_Console_Alias_Exes_నిడివి Get_Console_Alias_Exes_నిడివి_W
#నిర్వచించు GetConsoleAliases GetConsoleAliasesW
#నిర్వచించు GetConsoleAliasExes GetConsoleAliasExesW
#లేకపోతే
#నిర్వచించు Peek_Console_ఆదానం Peek_Console_ఆదానం_A
#నిర్వచించు Read_Console_ఆదానం Read_Console_ఆదానం_A
#నిర్వచించు Write_Console_ఆదానం Write_Console_ఆదానం_A
#నిర్వచించు ReadConsoleOutput ReadConsoleOutputA
#నిర్వచించు WriteConsoleOutput WriteConsoleOutputA
#నిర్వచించు ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#నిర్వచించు WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#నిర్వచించు FillConsoleOutputCharacter FillConsoleOutputCharacterA
#నిర్వచించు Scroll_Console_Screen_బఫరు Scroll_Console_Screen_బఫరు_A
#నిర్వచించు GetConsoleTitle GetConsoleTitleA
#నిర్వచించు సమితి_Console_Title సమితి_Console_Title_A
#నిర్వచించు ReadConsole ReadConsoleA
#నిర్వచించు WriteConsole WriteConsoleA
#నిర్వచించు కూడు_Console_Alias కూడు_Console_Alias_A
#నిర్వచించు GetConsoleAlias GetConsoleAliasA
#నిర్వచించు Get_Console_Aliases_నిడివి Get_Console_Aliases_నిడివి_A
#నిర్వచించు Get_Console_Alias_Exes_నిడివి Get_Console_Alias_Exes_నిడివి_A
#నిర్వచించు GetConsoleAliases GetConsoleAliasesA
#నిర్వచించు GetConsoleAliasExes GetConsoleAliasExesA
#అయితే_ముగింపు

  WINBASEAPI WINBOOL WINAPI Peek_Console_ఆదానం_A(HANDLE h_Console_ఆదానం,PINPUT_రికార్డు lp_బఫరు,DWORD n_నిడివి,LPDWORD lp_సంఖ్య_యొక్క_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_ఆదానం_W(HANDLE h_Console_ఆదానం,PINPUT_రికార్డు lp_బఫరు,DWORD n_నిడివి,LPDWORD lp_సంఖ్య_యొక్క_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_ఆదానం_A(HANDLE h_Console_ఆదానం,PINPUT_రికార్డు lp_బఫరు,DWORD n_నిడివి,LPDWORD lp_సంఖ్య_యొక్క_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_ఆదానం_W(HANDLE h_Console_ఆదానం,PINPUT_రికార్డు lp_బఫరు,DWORD n_నిడివి,LPDWORD lp_సంఖ్య_యొక్క_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_ఆదానం_A(HANDLE h_Console_ఆదానం,CONST ఆదానం_రికార్డు_2 *lp_బఫరు,DWORD n_నిడివి,LPDWORD lp_సంఖ్య_యొక్క_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_ఆదానం_W(HANDLE h_Console_ఆదానం,CONST ఆదానం_రికార్డు_2 *lp_బఫరు,DWORD n_నిడివి,LPDWORD lp_సంఖ్య_యొక్క_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_బఫరు,COORD dw_బఫరు_కొలత,COORD dw_బఫరు_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_బఫరు,COORD dw_బఫరు_కొలత,COORD dw_బఫరు_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_బఫరు,COORD dw_బఫరు_కొలత,COORD dw_బఫరు_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_బఫరు,COORD dw_బఫరు_కొలత,COORD dw_బఫరు_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_నిడివి,COORD dwReadCoord,LPDWORD lp_సంఖ్య_యొక్క_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_నిడివి,COORD dwReadCoord,LPDWORD lp_సంఖ్య_యొక్క_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_నిడివి,COORD dwReadCoord,LPDWORD lp_సంఖ్య_యొక్క_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_నిడివి,COORD dwWriteCoord,LPDWORD lp_సంఖ్య_యొక్క_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_నిడివి,COORD dwWriteCoord,LPDWORD lp_సంఖ్య_యొక్క_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST మాట_3 *lpAttribute,DWORD n_నిడివి,COORD dwWriteCoord,LPDWORD lp_సంఖ్య_యొక్క_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_నిడివి,COORD dwWriteCoord,LPDWORD lp_సంఖ్య_యొక్క_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_నిడివి,COORD dwWriteCoord,LPDWORD lp_సంఖ్య_యొక్క_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,మాట_3 wAttribute,DWORD n_నిడివి,COORD dwWriteCoord,LPDWORD lp_సంఖ్య_యొక్క_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI Get_Console_బహుళకం(HANDLE hConsoleHandle,LPDWORD lp_బహుళకం);
  WINBASEAPI WINBOOL WINAPI Get_సంఖ్య_యొక్క_Console_ఆదానం_Events(HANDLE h_Console_ఆదానం,LPDWORD lp_సంఖ్య_యొక్క_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_బఫరు_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_బఫరు_INFO lp_Console_Screen_బఫరు_Info);
  WINBASEAPI COORD WINAPI Get_అతిపెద్ద_Console_కిటికీ_కొలత(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL b_గరిష్ఠ_కిటికీ,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_కొలత(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_సంఖ్య_యొక్క_Console_Mouse_Buttons(LPDWORD lp_సంఖ్య_యొక్క_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_బహుళకం(HANDLE hConsoleHandle,DWORD dw_బహుళకం);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_చురుకైన_Screen_బఫరు(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_ఆదానం_బఫరు(HANDLE h_Console_ఆదానం);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_Screen_బఫరు_కొలత(HANDLE hConsoleOutput,COORD dw_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_Cursor_Position(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_Cursor_Info(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_బఫరు_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_బఫరు_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_కిటికీ_Info(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lp_Console_కిటికీ);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_పాఠ్యం_Attribute(HANDLE hConsoleOutput,మాట_3 w_లక్షణాలు);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_Ctrl_Handler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL కూడు_3);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dw_Process_సమూహం_Id);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#నిర్వచించు ATTACH_మాతృ_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_కొలత);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_కొలత);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_Title_A(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_Title_W(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_ఆదానం,LPVOID lp_బఫరు,DWORD n_సంఖ్య_యొక్క_Chars_గమ్యం_Read,LPDWORD lp_సంఖ్య_యొక్క_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_ఆదానం,LPVOID lp_బఫరు,DWORD n_సంఖ్య_యొక్క_Chars_గమ్యం_Read,LPDWORD lp_సంఖ్య_యొక్క_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_బఫరు,DWORD n_సంఖ్య_యొక్క_Chars_గమ్యం_Write,LPDWORD lp_సంఖ్య_యొక్క_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_బఫరు,DWORD n_సంఖ్య_యొక్క_Chars_గమ్యం_Write,LPDWORD lp_సంఖ్య_యొక్క_Chars_Written,LPVOID lpReserved);

#నిర్వచించు CONSOLE_TEXTMODE_బఫరు 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_బఫరు(DWORD dwDesiredAccess,DWORD dw_Share_బహుళకం,CONST SECURITY_లక్షణాలు_2 *lp_Security_లక్షణాలు,DWORD dwFlags,LPVOID lp_Screen_బఫరు_దత్తాంశం);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_CP(UINT w_సంకేతం_పుట_ID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI సమితి_Console_Output_CP(UINT w_సంకేతం_పుట_ID);

#నిర్వచించు CONSOLE_FULLSCREEN 1
#నిర్వచించు CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI Get_Console_Display_బహుళకం(LPDWORD lp_బహుళకం_Flags);
  WINBASEAPI HWND WINAPI Get_Console_కిటికీ(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_లెక్క);
  WINBASEAPI WINBOOL WINAPI కూడు_Console_Alias_A(LPSTR ఆధారం_2,LPSTR లక్ష్యం_2,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI కూడు_Console_Alias_W(LPWSTR ఆధారం_2,LPWSTR లక్ష్యం_2,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR ఆధారం_2,LPSTR లక్ష్యం_బఫరు,DWORD లక్ష్యం_బఫరు_నిడివి,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR ఆధారం_2,LPWSTR లక్ష్యం_బఫరు,DWORD లక్ష్యం_బఫరు_నిడివి,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_నిడివి_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_నిడివి_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_నిడివి_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_నిడివి_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_బఫరు,DWORD Alias_బఫరు_నిడివి,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_బఫరు,DWORD Alias_బఫరు_నిడివి,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_బఫరు,DWORD Exe_Name_బఫరు_నిడివి);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_బఫరు,DWORD Exe_Name_బఫరు_నిడివి);

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
