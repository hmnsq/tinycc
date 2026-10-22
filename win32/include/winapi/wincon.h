/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _WINCON_
#परिभाषय _WINCON_

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

  प्रकारनिर्देश संरचना _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  प्रकारनिर्देश संरचना _SMALL_RECT {
    SHORT वामः_2;
    SHORT शिखरम्_2;
    SHORT दक्षिणः_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  प्रकारनिर्देश संरचना कुञ्चिका_EVENT_लेखः {
    WINBOOL b_कुञ्चिका_अधस्तात्;
    WORD w_Repeat_गणनम्;
    WORD w_Virtual_कुञ्चिका_संहिता;
    WORD w_Virtual_अवलोकनम्_संहिता;
    सङ्घ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_कुञ्चिका_State;
  } कुञ्चिका_EVENT_लेखः_2,*PKEY_EVENT_लेखः;

#परिभाषय दक्षिणः_ALT_PRESSED 0x1
#परिभाषय वामः_ALT_PRESSED 0x2
#परिभाषय दक्षिणः_CTRL_PRESSED 0x4
#परिभाषय वामः_CTRL_PRESSED 0x8
#परिभाषय सरणम्_PRESSED 0x10
#परिभाषय NUMLOCK_ON 0x20
#परिभाषय SCROLLLOCK_ON 0x40
#परिभाषय CAPSLOCK_ON 0x80
#परिभाषय ENHANCED_कुञ्चिका 0x100
#परिभाषय NLS_DBCSCHAR 0x10000
#परिभाषय NLS_ALPHANUMERIC 0x0
#परिभाषय NLS_KATAKANA 0x20000
#परिभाषय NLS_HIRAGANA 0x40000
#परिभाषय NLS_ROMAN 0x400000
#परिभाषय NLS_IME_CONVERSION 0x800000
#परिभाषय NLS_IME_DISABLE 0x20000000

  प्रकारनिर्देश संरचना MOUSE_EVENT_लेखः {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_कुञ्चिका_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_लेखः_2,*PMOUSE_EVENT_लेखः;

#परिभाषय FROM_वामः_1_ST_BUTTON_PRESSED 0x1
#परिभाषय RIGHTMOST_BUTTON_PRESSED 0x2
#परिभाषय FROM_वामः_2_ND_BUTTON_PRESSED 0x4
#परिभाषय FROM_वामः_3_RD_BUTTON_PRESSED 0x8
#परिभाषय FROM_वामः_4_TH_BUTTON_PRESSED 0x10

#परिभाषय MOUSE_MOVED 0x1
#परिभाषय DOUBLE_CLICK 0x2
#परिभाषय MOUSE_WHEELED 0x4

  प्रकारनिर्देश संरचना गवाक्षः_बफर_आकार_लेखः {
    COORD dw_आकार;
  } गवाक्षः_बफर_आकार_लेखः_2,*PWINDOW_बफर_आकार_लेखः;

  प्रकारनिर्देश संरचना MENU_EVENT_लेखः {
    UINT dwCommandId;
  } MENU_EVENT_लेखः_2,*PMENU_EVENT_लेखः;

  प्रकारनिर्देश संरचना FOCUS_EVENT_लेखः {
    WINBOOL b_समुच्चयः_Focus;
  } FOCUS_EVENT_लेखः_2,*PFOCUS_EVENT_लेखः;

  प्रकारनिर्देश संरचना निवेशः_लेखः {
    WORD EventType;
    सङ्घ {
      कुञ्चिका_EVENT_लेखः_2 कुञ्चिका_Event;
      MOUSE_EVENT_लेखः_2 MouseEvent;
      गवाक्षः_बफर_आकार_लेखः_2 गवाक्षः_बफर_आकार_Event;
      MENU_EVENT_लेखः_2 MenuEvent;
      FOCUS_EVENT_लेखः_2 FocusEvent;
    } Event;
  } निवेशः_लेखः_2,*PINPUT_लेखः;

#परिभाषय कुञ्चिका_EVENT 0x1
#परिभाषय MOUSE_EVENT 0x2
#परिभाषय गवाक्षः_बफर_आकार_EVENT 0x4
#परिभाषय MENU_EVENT 0x8
#परिभाषय FOCUS_EVENT 0x10

  प्रकारनिर्देश संरचना _CHAR_INFO {
    सङ्घ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    WORD गुणाः;
  } CHAR_INFO,*PCHAR_INFO;

#परिभाषय FOREGROUND_BLUE 0x1
#परिभाषय FOREGROUND_GREEN 0x2
#परिभाषय FOREGROUND_RED 0x4
#परिभाषय FOREGROUND_INTENSITY 0x8
#परिभाषय BACKGROUND_BLUE 0x10
#परिभाषय BACKGROUND_GREEN 0x20
#परिभाषय BACKGROUND_RED 0x40
#परिभाषय BACKGROUND_INTENSITY 0x80
#परिभाषय COMMON_LVB_LEADING_BYTE 0x100
#परिभाषय COMMON_LVB_TRAILING_BYTE 0x200
#परिभाषय COMMON_LVB_GRID_HORIZONTAL 0x400
#परिभाषय COMMON_LVB_GRID_LVERTICAL 0x800
#परिभाषय COMMON_LVB_GRID_RVERTICAL 0x1000
#परिभाषय COMMON_LVB_REVERSE_VIDEO 0x4000
#परिभाषय COMMON_LVB_UNDERSCORE 0x8000

#परिभाषय COMMON_LVB_SBCSDBCS 0x300

  प्रकारनिर्देश संरचना CONSOLE_SCREEN_बफर_INFO {
    COORD dw_आकार;
    COORD dwCursorPosition;
    WORD w_गुणाः;
    SMALL_RECT sr_गवाक्षः;
    COORD dw_अधिकतमम्_गवाक्षः_आकार;
  } CONSOLE_SCREEN_बफर_INFO_2,*PCONSOLE_SCREEN_बफर_INFO;

  प्रकारनिर्देश संरचना _CONSOLE_CURSOR_INFO {
    DWORD dw_आकार;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  प्रकारनिर्देश संरचना _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dw_Font_आकार;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  प्रकारनिर्देश संरचना _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#परिभाषय CONSOLE_NO_SELECTION 0x0
#परिभाषय CONSOLE_SELECTION_अन्तर्_प्रगतिः 0x1
#परिभाषय CONSOLE_SELECTION_NOT_रिक्तानि 0x2
#परिभाषय CONSOLE_MOUSE_SELECTION 0x4
#परिभाषय CONSOLE_MOUSE_अधस्तात् 0x8

  प्रकारनिर्देश WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#परिभाषय CTRL_C_EVENT 0
#परिभाषय CTRL_BREAK_EVENT 1
#परिभाषय CTRL_CLOSE_EVENT 2

#परिभाषय CTRL_LOGOFF_EVENT 5
#परिभाषय CTRL_SHUTDOWN_EVENT 6

#परिभाषय ENABLE_PROCESSED_निवेशः 0x1
#परिभाषय ENABLE_पङ्क्तिः_निवेशः 0x2
#परिभाषय ENABLE_ECHO_निवेशः 0x4
#परिभाषय ENABLE_गवाक्षः_निवेशः 0x8
#परिभाषय ENABLE_MOUSE_निवेशः 0x10
#परिभाषय ENABLE_निवेशय_बहुलकम् 0x20
#परिभाषय ENABLE_शीघ्र_EDIT_बहुलकम् 0x40
#परिभाषय ENABLE_EXTENDED_FLAGS 0x80
#परिभाषय ENABLE_AUTO_POSITION 0x100
#परिभाषय ENABLE_VIRTUAL_TERMINAL_निवेशः 0x200

#परिभाषय ENABLE_PROCESSED_OUTPUT 0x1
#परिभाषय ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#परिभाषय ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#परिभाषय DISABLE_NEWLINE_AUTO_RETURN 0x8
#परिभाषय ENABLE_LVB_GRID_WORLDWIDE 0x10

#यदि_परिभाषितम् UNICODE
#परिभाषय Peek_Console_निवेशः Peek_Console_निवेशः_W
#परिभाषय Read_Console_निवेशः Read_Console_निवेशः_W
#परिभाषय Write_Console_निवेशः Write_Console_निवेशः_W
#परिभाषय ReadConsoleOutput ReadConsoleOutputW
#परिभाषय WriteConsoleOutput WriteConsoleOutputW
#परिभाषय ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#परिभाषय WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#परिभाषय FillConsoleOutputCharacter FillConsoleOutputCharacterW
#परिभाषय Scroll_Console_Screen_बफर Scroll_Console_Screen_बफर_W
#परिभाषय GetConsoleTitle GetConsoleTitleW
#परिभाषय समुच्चयः_Console_Title समुच्चयः_Console_Title_W
#परिभाषय ReadConsole ReadConsoleW
#परिभाषय WriteConsole WriteConsoleW
#परिभाषय सङ्कलय_Console_Alias सङ्कलय_Console_Alias_W
#परिभाषय GetConsoleAlias GetConsoleAliasW
#परिभाषय Get_Console_Aliases_दीर्घता Get_Console_Aliases_दीर्घता_W
#परिभाषय Get_Console_Alias_Exes_दीर्घता Get_Console_Alias_Exes_दीर्घता_W
#परिभाषय GetConsoleAliases GetConsoleAliasesW
#परिभाषय GetConsoleAliasExes GetConsoleAliasExesW
#अन्यथा
#परिभाषय Peek_Console_निवेशः Peek_Console_निवेशः_A
#परिभाषय Read_Console_निवेशः Read_Console_निवेशः_A
#परिभाषय Write_Console_निवेशः Write_Console_निवेशः_A
#परिभाषय ReadConsoleOutput ReadConsoleOutputA
#परिभाषय WriteConsoleOutput WriteConsoleOutputA
#परिभाषय ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#परिभाषय WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#परिभाषय FillConsoleOutputCharacter FillConsoleOutputCharacterA
#परिभाषय Scroll_Console_Screen_बफर Scroll_Console_Screen_बफर_A
#परिभाषय GetConsoleTitle GetConsoleTitleA
#परिभाषय समुच्चयः_Console_Title समुच्चयः_Console_Title_A
#परिभाषय ReadConsole ReadConsoleA
#परिभाषय WriteConsole WriteConsoleA
#परिभाषय सङ्कलय_Console_Alias सङ्कलय_Console_Alias_A
#परिभाषय GetConsoleAlias GetConsoleAliasA
#परिभाषय Get_Console_Aliases_दीर्घता Get_Console_Aliases_दीर्घता_A
#परिभाषय Get_Console_Alias_Exes_दीर्घता Get_Console_Alias_Exes_दीर्घता_A
#परिभाषय GetConsoleAliases GetConsoleAliasesA
#परिभाषय GetConsoleAliasExes GetConsoleAliasExesA
#यदि_अन्तः

  WINBASEAPI WINBOOL WINAPI Peek_Console_निवेशः_A(HANDLE h_Console_निवेशः,PINPUT_लेखः lp_बफर,DWORD n_दीर्घता,LPDWORD lp_सङ्ख्या_सम्बन्धि_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_निवेशः_W(HANDLE h_Console_निवेशः,PINPUT_लेखः lp_बफर,DWORD n_दीर्घता,LPDWORD lp_सङ्ख्या_सम्बन्धि_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_निवेशः_A(HANDLE h_Console_निवेशः,PINPUT_लेखः lp_बफर,DWORD n_दीर्घता,LPDWORD lp_सङ्ख्या_सम्बन्धि_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_निवेशः_W(HANDLE h_Console_निवेशः,PINPUT_लेखः lp_बफर,DWORD n_दीर्घता,LPDWORD lp_सङ्ख्या_सम्बन्धि_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_निवेशः_A(HANDLE h_Console_निवेशः,CONST निवेशः_लेखः_2 *lp_बफर,DWORD n_दीर्घता,LPDWORD lp_सङ्ख्या_सम्बन्धि_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_निवेशः_W(HANDLE h_Console_निवेशः,CONST निवेशः_लेखः_2 *lp_बफर,DWORD n_दीर्घता,LPDWORD lp_सङ्ख्या_सम्बन्धि_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_बफर,COORD dw_बफर_आकार,COORD dw_बफर_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_बफर,COORD dw_बफर_आकार,COORD dw_बफर_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_बफर,COORD dw_बफर_आकार,COORD dw_बफर_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_बफर,COORD dw_बफर_आकार,COORD dw_बफर_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_दीर्घता,COORD dwReadCoord,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_दीर्घता,COORD dwReadCoord,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_दीर्घता,COORD dwReadCoord,LPDWORD lp_सङ्ख्या_सम्बन्धि_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_दीर्घता,COORD dwWriteCoord,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_दीर्घता,COORD dwWriteCoord,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST WORD *lpAttribute,DWORD n_दीर्घता,COORD dwWriteCoord,LPDWORD lp_सङ्ख्या_सम्बन्धि_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_दीर्घता,COORD dwWriteCoord,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_दीर्घता,COORD dwWriteCoord,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,WORD wAttribute,DWORD n_दीर्घता,COORD dwWriteCoord,LPDWORD lp_सङ्ख्या_सम्बन्धि_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI Get_Console_बहुलकम्(HANDLE hConsoleHandle,LPDWORD lp_बहुलकम्);
  WINBASEAPI WINBOOL WINAPI Get_सङ्ख्या_सम्बन्धि_Console_निवेशः_Events(HANDLE h_Console_निवेशः,LPDWORD lp_सङ्ख्या_सम्बन्धि_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_बफर_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_बफर_INFO lp_Console_Screen_बफर_Info);
  WINBASEAPI COORD WINAPI Get_Largest_Console_गवाक्षः_आकार(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL b_अधिकतमम्_गवाक्षः,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_आकार(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_सङ्ख्या_सम्बन्धि_Console_Mouse_Buttons(LPDWORD lp_सङ्ख्या_सम्बन्धि_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_बहुलकम्(HANDLE hConsoleHandle,DWORD dw_बहुलकम्);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_सक्रिय_Screen_बफर(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_निवेशः_बफर(HANDLE h_Console_निवेशः);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_Screen_बफर_आकार(HANDLE hConsoleOutput,COORD dw_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_Cursor_Position(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_Cursor_Info(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_बफर_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_बफर_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_गवाक्षः_Info(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lp_Console_गवाक्षः);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_Text_Attribute(HANDLE hConsoleOutput,WORD w_गुणाः);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_Ctrl_Handler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL सङ्कलय_3);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dw_Process_गणः_Id);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#परिभाषय ATTACH_PARENT_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_Title_A(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_Title_W(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_निवेशः,LPVOID lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_Chars_गन्तव्यम्_Read,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_निवेशः,LPVOID lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_Chars_गन्तव्यम्_Read,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_Chars_गन्तव्यम्_Write,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_बफर,DWORD n_सङ्ख्या_सम्बन्धि_Chars_गन्तव्यम्_Write,LPDWORD lp_सङ्ख्या_सम्बन्धि_Chars_Written,LPVOID lpReserved);

#परिभाषय CONSOLE_TEXTMODE_बफर 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_बफर(DWORD dwDesiredAccess,DWORD dw_Share_बहुलकम्,CONST SECURITY_गुणाः_2 *lp_Security_गुणाः,DWORD dwFlags,LPVOID lp_Screen_बफर_दत्त);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_CP(UINT w_संहिता_Page_ID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI समुच्चयः_Console_Output_CP(UINT w_संहिता_Page_ID);

#परिभाषय CONSOLE_FULLSCREEN 1
#परिभाषय CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI Get_Console_Display_बहुलकम्(LPDWORD lp_बहुलकम्_Flags);
  WINBASEAPI HWND WINAPI Get_Console_गवाक्षः(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_गणनम्);
  WINBASEAPI WINBOOL WINAPI सङ्कलय_Console_Alias_A(LPSTR Source,LPSTR Target,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI सङ्कलय_Console_Alias_W(LPWSTR Source,LPWSTR Target,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR Source,LPSTR Target_बफर,DWORD Target_बफर_दीर्घता,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR Source,LPWSTR Target_बफर,DWORD Target_बफर_दीर्घता,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_दीर्घता_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_दीर्घता_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_दीर्घता_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_दीर्घता_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_बफर,DWORD Alias_बफर_दीर्घता,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_बफर,DWORD Alias_बफर_दीर्घता,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_बफर,DWORD Exe_Name_बफर_दीर्घता);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_बफर,DWORD Exe_Name_बफर_दीर्घता);

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
