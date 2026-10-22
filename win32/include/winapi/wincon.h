/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _WINCON_
#घोषणा _WINCON_

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  प्रकार काष्ठा _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  प्रकार काष्ठा _SMALL_RECT {
    SHORT बायाँ_2;
    SHORT शीर्ष_2;
    SHORT दायाँ_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  प्रकार काष्ठा कुंजी_EVENT_RECORD {
    WINBOOL b_कुंजी_Down;
    WORD w_Repeat_गिनती;
    WORD w_Virtual_कुंजी_Code;
    WORD wVirtualScanCode;
    जोड़ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_कुंजी_State;
  } कुंजी_EVENT_RECORD_2,*PKEY_EVENT_RECORD;

#घोषणा दायाँ_ALT_PRESSED 0x1
#घोषणा बायाँ_ALT_PRESSED 0x2
#घोषणा दायाँ_CTRL_PRESSED 0x4
#घोषणा बायाँ_CTRL_PRESSED 0x8
#घोषणा SHIFT_PRESSED 0x10
#घोषणा NUMLOCK_ON 0x20
#घोषणा SCROLLLOCK_ON 0x40
#घोषणा CAPSLOCK_ON 0x80
#घोषणा ENHANCED_कुंजी 0x100
#घोषणा NLS_DBCSCHAR 0x10000
#घोषणा NLS_ALPHANUMERIC 0x0
#घोषणा NLS_KATAKANA 0x20000
#घोषणा NLS_HIRAGANA 0x40000
#घोषणा NLS_ROMAN 0x400000
#घोषणा NLS_IME_CONVERSION 0x800000
#घोषणा NLS_IME_DISABLE 0x20000000

  प्रकार काष्ठा _MOUSE_EVENT_RECORD {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_कुंजी_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_RECORD,*PMOUSE_EVENT_RECORD;

#घोषणा FROM_बायाँ_1_ST_BUTTON_PRESSED 0x1
#घोषणा RIGHTMOST_BUTTON_PRESSED 0x2
#घोषणा FROM_बायाँ_2_ND_BUTTON_PRESSED 0x4
#घोषणा FROM_बायाँ_3_RD_BUTTON_PRESSED 0x8
#घोषणा FROM_बायाँ_4_TH_BUTTON_PRESSED 0x10

#घोषणा MOUSE_MOVED 0x1
#घोषणा DOUBLE_CLICK 0x2
#घोषणा MOUSE_WHEELED 0x4

  प्रकार काष्ठा WINDOW_बफर_आकार_RECORD {
    COORD dw_आकार;
  } WINDOW_बफर_आकार_RECORD_2,*PWINDOW_बफर_आकार_RECORD;

  प्रकार काष्ठा _MENU_EVENT_RECORD {
    UINT dwCommandId;
  } MENU_EVENT_RECORD,*PMENU_EVENT_RECORD;

  प्रकार काष्ठा _FOCUS_EVENT_RECORD {
    WINBOOL bSetFocus;
  } FOCUS_EVENT_RECORD,*PFOCUS_EVENT_RECORD;

  प्रकार काष्ठा निवेश_RECORD {
    WORD EventType;
    जोड़ {
      कुंजी_EVENT_RECORD_2 कुंजी_Event;
      MOUSE_EVENT_RECORD MouseEvent;
      WINDOW_बफर_आकार_RECORD_2 Window_बफर_आकार_Event;
      MENU_EVENT_RECORD MenuEvent;
      FOCUS_EVENT_RECORD FocusEvent;
    } Event;
  } निवेश_RECORD_2,*PINPUT_RECORD;

#घोषणा कुंजी_EVENT 0x1
#घोषणा MOUSE_EVENT 0x2
#घोषणा WINDOW_बफर_आकार_EVENT 0x4
#घोषणा MENU_EVENT 0x8
#घोषणा FOCUS_EVENT 0x10

  प्रकार काष्ठा _CHAR_INFO {
    जोड़ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    WORD Attributes;
  } CHAR_INFO,*PCHAR_INFO;

#घोषणा FOREGROUND_BLUE 0x1
#घोषणा FOREGROUND_GREEN 0x2
#घोषणा FOREGROUND_RED 0x4
#घोषणा FOREGROUND_INTENSITY 0x8
#घोषणा BACKGROUND_BLUE 0x10
#घोषणा BACKGROUND_GREEN 0x20
#घोषणा BACKGROUND_RED 0x40
#घोषणा BACKGROUND_INTENSITY 0x80
#घोषणा COMMON_LVB_LEADING_BYTE 0x100
#घोषणा COMMON_LVB_TRAILING_BYTE 0x200
#घोषणा COMMON_LVB_GRID_HORIZONTAL 0x400
#घोषणा COMMON_LVB_GRID_LVERTICAL 0x800
#घोषणा COMMON_LVB_GRID_RVERTICAL 0x1000
#घोषणा COMMON_LVB_REVERSE_VIDEO 0x4000
#घोषणा COMMON_LVB_UNDERSCORE 0x8000

#घोषणा COMMON_LVB_SBCSDBCS 0x300

  प्रकार काष्ठा CONSOLE_SCREEN_बफर_INFO {
    COORD dw_आकार;
    COORD dwCursorPosition;
    WORD wAttributes;
    SMALL_RECT srWindow;
    COORD dw_Maximum_Window_आकार;
  } CONSOLE_SCREEN_बफर_INFO_2,*PCONSOLE_SCREEN_बफर_INFO;

  प्रकार काष्ठा _CONSOLE_CURSOR_INFO {
    DWORD dw_आकार;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  प्रकार काष्ठा _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dw_Font_आकार;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  प्रकार काष्ठा _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#घोषणा CONSOLE_NO_SELECTION 0x0
#घोषणा CONSOLE_SELECTION_IN_PROGRESS 0x1
#घोषणा CONSOLE_SELECTION_NOT_EMPTY 0x2
#घोषणा CONSOLE_MOUSE_SELECTION 0x4
#घोषणा CONSOLE_MOUSE_DOWN 0x8

  प्रकार WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#घोषणा CTRL_C_EVENT 0
#घोषणा CTRL_BREAK_EVENT 1
#घोषणा CTRL_CLOSE_EVENT 2

#घोषणा CTRL_LOGOFF_EVENT 5
#घोषणा CTRL_SHUTDOWN_EVENT 6

#घोषणा ENABLE_PROCESSED_निवेश 0x1
#घोषणा ENABLE_पंक्ति_निवेश 0x2
#घोषणा ENABLE_ECHO_निवेश 0x4
#घोषणा ENABLE_WINDOW_निवेश 0x8
#घोषणा ENABLE_MOUSE_निवेश 0x10
#घोषणा ENABLE_जोड़ो_MODE 0x20
#घोषणा ENABLE_QUICK_EDIT_MODE 0x40
#घोषणा ENABLE_EXTENDED_FLAGS 0x80
#घोषणा ENABLE_AUTO_POSITION 0x100
#घोषणा ENABLE_VIRTUAL_TERMINAL_निवेश 0x200

#घोषणा ENABLE_PROCESSED_OUTPUT 0x1
#घोषणा ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#घोषणा ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#घोषणा DISABLE_NEWLINE_AUTO_RETURN 0x8
#घोषणा ENABLE_LVB_GRID_WORLDWIDE 0x10

#अगर_घोषित UNICODE
#घोषणा Peek_Console_निवेश Peek_Console_निवेश_W
#घोषणा Read_Console_निवेश Read_Console_निवेश_W
#घोषणा Write_Console_निवेश Write_Console_निवेश_W
#घोषणा ReadConsoleOutput ReadConsoleOutputW
#घोषणा WriteConsoleOutput WriteConsoleOutputW
#घोषणा ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#घोषणा WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#घोषणा FillConsoleOutputCharacter FillConsoleOutputCharacterW
#घोषणा Scroll_Console_Screen_बफर Scroll_Console_Screen_बफर_W
#घोषणा GetConsoleTitle GetConsoleTitleW
#घोषणा SetConsoleTitle SetConsoleTitleW
#घोषणा ReadConsole ReadConsoleW
#घोषणा WriteConsole WriteConsoleW
#घोषणा AddConsoleAlias AddConsoleAliasW
#घोषणा GetConsoleAlias GetConsoleAliasW
#घोषणा Get_Console_Aliases_लंबाई Get_Console_Aliases_लंबाई_W
#घोषणा Get_Console_Alias_Exes_लंबाई Get_Console_Alias_Exes_लंबाई_W
#घोषणा GetConsoleAliases GetConsoleAliasesW
#घोषणा GetConsoleAliasExes GetConsoleAliasExesW
#अन्यथा
#घोषणा Peek_Console_निवेश Peek_Console_निवेश_A
#घोषणा Read_Console_निवेश Read_Console_निवेश_A
#घोषणा Write_Console_निवेश Write_Console_निवेश_A
#घोषणा ReadConsoleOutput ReadConsoleOutputA
#घोषणा WriteConsoleOutput WriteConsoleOutputA
#घोषणा ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#घोषणा WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#घोषणा FillConsoleOutputCharacter FillConsoleOutputCharacterA
#घोषणा Scroll_Console_Screen_बफर Scroll_Console_Screen_बफर_A
#घोषणा GetConsoleTitle GetConsoleTitleA
#घोषणा SetConsoleTitle SetConsoleTitleA
#घोषणा ReadConsole ReadConsoleA
#घोषणा WriteConsole WriteConsoleA
#घोषणा AddConsoleAlias AddConsoleAliasA
#घोषणा GetConsoleAlias GetConsoleAliasA
#घोषणा Get_Console_Aliases_लंबाई Get_Console_Aliases_लंबाई_A
#घोषणा Get_Console_Alias_Exes_लंबाई Get_Console_Alias_Exes_लंबाई_A
#घोषणा GetConsoleAliases GetConsoleAliasesA
#घोषणा GetConsoleAliasExes GetConsoleAliasExesA
#पूर्ण_अगर

  WINBASEAPI WINBOOL WINAPI Peek_Console_निवेश_A(HANDLE h_Console_निवेश,PINPUT_RECORD lp_बफर,DWORD n_लंबाई,LPDWORD lp_संख्या_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_निवेश_W(HANDLE h_Console_निवेश,PINPUT_RECORD lp_बफर,DWORD n_लंबाई,LPDWORD lp_संख्या_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_निवेश_A(HANDLE h_Console_निवेश,PINPUT_RECORD lp_बफर,DWORD n_लंबाई,LPDWORD lp_संख्या_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_निवेश_W(HANDLE h_Console_निवेश,PINPUT_RECORD lp_बफर,DWORD n_लंबाई,LPDWORD lp_संख्या_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_निवेश_A(HANDLE h_Console_निवेश,CONST निवेश_RECORD_2 *lp_बफर,DWORD n_लंबाई,LPDWORD lp_संख्या_Of_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_निवेश_W(HANDLE h_Console_निवेश,CONST निवेश_RECORD_2 *lp_बफर,DWORD n_लंबाई,LPDWORD lp_संख्या_Of_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_बफर,COORD dw_बफर_आकार,COORD dw_बफर_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_बफर,COORD dw_बफर_आकार,COORD dw_बफर_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_बफर,COORD dw_बफर_आकार,COORD dw_बफर_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_बफर,COORD dw_बफर_आकार,COORD dw_बफर_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_लंबाई,COORD dwReadCoord,LPDWORD lp_संख्या_Of_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_लंबाई,COORD dwReadCoord,LPDWORD lp_संख्या_Of_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_लंबाई,COORD dwReadCoord,LPDWORD lp_संख्या_Of_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_लंबाई,COORD dwWriteCoord,LPDWORD lp_संख्या_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_लंबाई,COORD dwWriteCoord,LPDWORD lp_संख्या_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST WORD *lpAttribute,DWORD n_लंबाई,COORD dwWriteCoord,LPDWORD lp_संख्या_Of_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_लंबाई,COORD dwWriteCoord,LPDWORD lp_संख्या_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_लंबाई,COORD dwWriteCoord,LPDWORD lp_संख्या_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,WORD wAttribute,DWORD n_लंबाई,COORD dwWriteCoord,LPDWORD lp_संख्या_Of_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI GetConsoleMode(HANDLE hConsoleHandle,LPDWORD lpMode);
  WINBASEAPI WINBOOL WINAPI Get_संख्या_Of_Console_निवेश_Events(HANDLE h_Console_निवेश,LPDWORD lp_संख्या_Of_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_बफर_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_बफर_INFO lp_Console_Screen_बफर_Info);
  WINBASEAPI COORD WINAPI Get_Largest_Console_Window_आकार(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL bMaximumWindow,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_आकार(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_संख्या_Of_Console_Mouse_Buttons(LPDWORD lp_संख्या_Of_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI SetConsoleMode(HANDLE hConsoleHandle,DWORD dwMode);
  WINBASEAPI WINBOOL WINAPI Set_Console_Active_Screen_बफर(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_निवेश_बफर(HANDLE h_Console_निवेश);
  WINBASEAPI WINBOOL WINAPI Set_Console_Screen_बफर_आकार(HANDLE hConsoleOutput,COORD dw_आकार);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorPosition(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorInfo(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_बफर_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_बफर_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI SetConsoleWindowInfo(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lpConsoleWindow);
  WINBASEAPI WINBOOL WINAPI SetConsoleTextAttribute(HANDLE hConsoleOutput,WORD wAttributes);
  WINBASEAPI WINBOOL WINAPI SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL Add);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dwProcessGroupId);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#घोषणा ATTACH_PARENT_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_आकार);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_आकार);
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleA(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleW(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_निवेश,LPVOID lp_बफर,DWORD n_संख्या_Of_Chars_To_Read,LPDWORD lp_संख्या_Of_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_निवेश,LPVOID lp_बफर,DWORD n_संख्या_Of_Chars_To_Read,LPDWORD lp_संख्या_Of_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_बफर,DWORD n_संख्या_Of_Chars_To_Write,LPDWORD lp_संख्या_Of_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_बफर,DWORD n_संख्या_Of_Chars_To_Write,LPDWORD lp_संख्या_Of_Chars_Written,LPVOID lpReserved);

#घोषणा CONSOLE_TEXTMODE_बफर 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_बफर(DWORD dwDesiredAccess,DWORD dwShareMode,CONST SECURITY_ATTRIBUTES *lpSecurityAttributes,DWORD dwFlags,LPVOID lp_Screen_बफर_तथ्य);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI SetConsoleCP(UINT wCodePageID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI SetConsoleOutputCP(UINT wCodePageID);

#घोषणा CONSOLE_FULLSCREEN 1
#घोषणा CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI GetConsoleDisplayMode(LPDWORD lpModeFlags);
  WINBASEAPI HWND WINAPI GetConsoleWindow(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_गिनती);
  WINBASEAPI WINBOOL WINAPI AddConsoleAliasA(LPSTR Source,LPSTR Target,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI AddConsoleAliasW(LPWSTR Source,LPWSTR Target,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR Source,LPSTR Target_बफर,DWORD Target_बफर_लंबाई,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR Source,LPWSTR Target_बफर,DWORD Target_बफर_लंबाई,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_लंबाई_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_लंबाई_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_लंबाई_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_लंबाई_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_बफर,DWORD Alias_बफर_लंबाई,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_बफर,DWORD Alias_बफर_लंबाई,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_बफर,DWORD Exe_Name_बफर_लंबाई);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_बफर,DWORD Exe_Name_बफर_लंबाई);

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
