/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _WINCON_
#تعریف_کړه _WINCON_

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

  تعريفنوع بنية _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  تعريفنوع بنية _SMALL_RECT {
    SHORT کیڼ_2;
    SHORT سر_2;
    SHORT ښی_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  تعريفنوع بنية کلی_EVENT_ریکارډ {
    WINBOOL b_کلی_ښکته;
    کلمه_3 w_Repeat_شمېر;
    کلمه_3 w_Virtual_کلی_کوډ;
    کلمه_3 w_Virtual_لټون_کوډ;
    اتحاد {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_کلی_State;
  } کلی_EVENT_ریکارډ_2,*PKEY_EVENT_ریکارډ;

#تعریف_کړه ښی_ALT_PRESSED 0x1
#تعریف_کړه کیڼ_ALT_PRESSED 0x2
#تعریف_کړه ښی_CTRL_PRESSED 0x4
#تعریف_کړه کیڼ_CTRL_PRESSED 0x8
#تعریف_کړه ښويدنه_PRESSED 0x10
#تعریف_کړه NUMLOCK_ON 0x20
#تعریف_کړه SCROLLLOCK_ON 0x40
#تعریف_کړه CAPSLOCK_ON 0x80
#تعریف_کړه ENHANCED_کلی 0x100
#تعریف_کړه NLS_DBCSCHAR 0x10000
#تعریف_کړه NLS_ALPHANUMERIC 0x0
#تعریف_کړه NLS_KATAKANA 0x20000
#تعریف_کړه NLS_HIRAGANA 0x40000
#تعریف_کړه NLS_ROMAN 0x400000
#تعریف_کړه NLS_IME_CONVERSION 0x800000
#تعریف_کړه NLS_IME_DISABLE 0x20000000

  تعريفنوع بنية MOUSE_EVENT_ریکارډ {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_کلی_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_ریکارډ_2,*PMOUSE_EVENT_ریکارډ;

#تعریف_کړه FROM_کیڼ_1_ST_BUTTON_PRESSED 0x1
#تعریف_کړه RIGHTMOST_BUTTON_PRESSED 0x2
#تعریف_کړه FROM_کیڼ_2_ND_BUTTON_PRESSED 0x4
#تعریف_کړه FROM_کیڼ_3_RD_BUTTON_PRESSED 0x8
#تعریف_کړه FROM_کیڼ_4_TH_BUTTON_PRESSED 0x10

#تعریف_کړه MOUSE_MOVED 0x1
#تعریف_کړه DOUBLE_CLICK 0x2
#تعریف_کړه MOUSE_WHEELED 0x4

  تعريفنوع بنية کړکۍ_بفر_اندازه_ریکارډ {
    COORD dw_اندازه;
  } کړکۍ_بفر_اندازه_ریکارډ_2,*PWINDOW_بفر_اندازه_ریکارډ;

  تعريفنوع بنية MENU_EVENT_ریکارډ {
    UINT dwCommandId;
  } MENU_EVENT_ریکارډ_2,*PMENU_EVENT_ریکارډ;

  تعريفنوع بنية FOCUS_EVENT_ریکارډ {
    WINBOOL b_سېټ_Focus;
  } FOCUS_EVENT_ریکارډ_2,*PFOCUS_EVENT_ریکارډ;

  تعريفنوع بنية ننوت_ریکارډ {
    کلمه_3 EventType;
    اتحاد {
      کلی_EVENT_ریکارډ_2 کلی_Event;
      MOUSE_EVENT_ریکارډ_2 MouseEvent;
      کړکۍ_بفر_اندازه_ریکارډ_2 کړکۍ_بفر_اندازه_Event;
      MENU_EVENT_ریکارډ_2 MenuEvent;
      FOCUS_EVENT_ریکارډ_2 FocusEvent;
    } Event;
  } ننوت_ریکارډ_2,*PINPUT_ریکارډ;

#تعریف_کړه کلی_EVENT 0x1
#تعریف_کړه MOUSE_EVENT 0x2
#تعریف_کړه کړکۍ_بفر_اندازه_EVENT 0x4
#تعریف_کړه MENU_EVENT 0x8
#تعریف_کړه FOCUS_EVENT 0x10

  تعريفنوع بنية _CHAR_INFO {
    اتحاد {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    کلمه_3 ځانګړتیاوې;
  } CHAR_INFO,*PCHAR_INFO;

#تعریف_کړه FOREGROUND_BLUE 0x1
#تعریف_کړه FOREGROUND_GREEN 0x2
#تعریف_کړه FOREGROUND_RED 0x4
#تعریف_کړه FOREGROUND_INTENSITY 0x8
#تعریف_کړه BACKGROUND_BLUE 0x10
#تعریف_کړه BACKGROUND_GREEN 0x20
#تعریف_کړه BACKGROUND_RED 0x40
#تعریف_کړه BACKGROUND_INTENSITY 0x80
#تعریف_کړه COMMON_LVB_LEADING_BYTE 0x100
#تعریف_کړه COMMON_LVB_TRAILING_BYTE 0x200
#تعریف_کړه COMMON_LVB_GRID_HORIZONTAL 0x400
#تعریف_کړه COMMON_LVB_GRID_LVERTICAL 0x800
#تعریف_کړه COMMON_LVB_GRID_RVERTICAL 0x1000
#تعریف_کړه COMMON_LVB_سرچپه_VIDEO 0x4000
#تعریف_کړه COMMON_LVB_UNDERSCORE 0x8000

#تعریف_کړه COMMON_LVB_SBCSDBCS 0x300

  تعريفنوع بنية CONSOLE_SCREEN_بفر_INFO {
    COORD dw_اندازه;
    COORD dwCursorPosition;
    کلمه_3 w_ځانګړتیاوې;
    SMALL_RECT sr_کړکۍ;
    COORD dw_اعظمي_کړکۍ_اندازه;
  } CONSOLE_SCREEN_بفر_INFO_2,*PCONSOLE_SCREEN_بفر_INFO;

  تعريفنوع بنية _CONSOLE_CURSOR_INFO {
    DWORD dw_اندازه;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  تعريفنوع بنية _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dw_Font_اندازه;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  تعريفنوع بنية _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#تعریف_کړه CONSOLE_NO_SELECTION 0x0
#تعریف_کړه CONSOLE_SELECTION_دننه_پرمختګ 0x1
#تعریف_کړه CONSOLE_SELECTION_NOT_تشه 0x2
#تعریف_کړه CONSOLE_MOUSE_SELECTION 0x4
#تعریف_کړه CONSOLE_MOUSE_ښکته 0x8

  تعريفنوع WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#تعریف_کړه CTRL_C_EVENT 0
#تعریف_کړه CTRL_BREAK_EVENT 1
#تعریف_کړه CTRL_CLOSE_EVENT 2

#تعریف_کړه CTRL_LOGOFF_EVENT 5
#تعریف_کړه CTRL_SHUTDOWN_EVENT 6

#تعریف_کړه ENABLE_PROCESSED_ننوت 0x1
#تعریف_کړه ENABLE_کرښه_ننوت 0x2
#تعریف_کړه ENABLE_ECHO_ننوت 0x4
#تعریف_کړه ENABLE_کړکۍ_ننوت 0x8
#تعریف_کړه ENABLE_MOUSE_ننوت 0x10
#تعریف_کړه ENABLE_ورننباسه_ډېرپېښ 0x20
#تعریف_کړه ENABLE_چټک_EDIT_ډېرپېښ 0x40
#تعریف_کړه ENABLE_EXTENDED_FLAGS 0x80
#تعریف_کړه ENABLE_AUTO_POSITION 0x100
#تعریف_کړه ENABLE_VIRTUAL_TERMINAL_ننوت 0x200

#تعریف_کړه ENABLE_PROCESSED_OUTPUT 0x1
#تعریف_کړه ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#تعریف_کړه ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#تعریف_کړه DISABLE_NEWLINE_AUTO_RETURN 0x8
#تعریف_کړه ENABLE_LVB_GRID_WORLDWIDE 0x10

#که_تعریف_شوی UNICODE
#تعریف_کړه Peek_Console_ننوت Peek_Console_ننوت_W
#تعریف_کړه Read_Console_ننوت Read_Console_ننوت_W
#تعریف_کړه Write_Console_ننوت Write_Console_ننوت_W
#تعریف_کړه ReadConsoleOutput ReadConsoleOutputW
#تعریف_کړه WriteConsoleOutput WriteConsoleOutputW
#تعریف_کړه ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#تعریف_کړه WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#تعریف_کړه FillConsoleOutputCharacter FillConsoleOutputCharacterW
#تعریف_کړه Scroll_Console_Screen_بفر Scroll_Console_Screen_بفر_W
#تعریف_کړه GetConsoleTitle GetConsoleTitleW
#تعریف_کړه سېټ_Console_Title سېټ_Console_Title_W
#تعریف_کړه ReadConsole ReadConsoleW
#تعریف_کړه WriteConsole WriteConsoleW
#تعریف_کړه جمع_کړه_Console_Alias جمع_کړه_Console_Alias_W
#تعریف_کړه GetConsoleAlias GetConsoleAliasW
#تعریف_کړه Get_Console_Aliases_اوږدتیا Get_Console_Aliases_اوږدتیا_W
#تعریف_کړه Get_Console_Alias_Exes_اوږدتیا Get_Console_Alias_Exes_اوږدتیا_W
#تعریف_کړه GetConsoleAliases GetConsoleAliasesW
#تعریف_کړه GetConsoleAliasExes GetConsoleAliasExesW
#وإلا
#تعریف_کړه Peek_Console_ننوت Peek_Console_ننوت_A
#تعریف_کړه Read_Console_ننوت Read_Console_ننوت_A
#تعریف_کړه Write_Console_ننوت Write_Console_ننوت_A
#تعریف_کړه ReadConsoleOutput ReadConsoleOutputA
#تعریف_کړه WriteConsoleOutput WriteConsoleOutputA
#تعریف_کړه ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#تعریف_کړه WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#تعریف_کړه FillConsoleOutputCharacter FillConsoleOutputCharacterA
#تعریف_کړه Scroll_Console_Screen_بفر Scroll_Console_Screen_بفر_A
#تعریف_کړه GetConsoleTitle GetConsoleTitleA
#تعریف_کړه سېټ_Console_Title سېټ_Console_Title_A
#تعریف_کړه ReadConsole ReadConsoleA
#تعریف_کړه WriteConsole WriteConsoleA
#تعریف_کړه جمع_کړه_Console_Alias جمع_کړه_Console_Alias_A
#تعریف_کړه GetConsoleAlias GetConsoleAliasA
#تعریف_کړه Get_Console_Aliases_اوږدتیا Get_Console_Aliases_اوږدتیا_A
#تعریف_کړه Get_Console_Alias_Exes_اوږدتیا Get_Console_Alias_Exes_اوږدتیا_A
#تعریف_کړه GetConsoleAliases GetConsoleAliasesA
#تعریف_کړه GetConsoleAliasExes GetConsoleAliasExesA
#د_که_پای

  WINBASEAPI WINBOOL WINAPI Peek_Console_ننوت_A(HANDLE h_Console_ننوت,PINPUT_ریکارډ lp_بفر,DWORD n_اوږدتیا,LPDWORD lp_شمېره_د_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_ننوت_W(HANDLE h_Console_ننوت,PINPUT_ریکارډ lp_بفر,DWORD n_اوږدتیا,LPDWORD lp_شمېره_د_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_ننوت_A(HANDLE h_Console_ننوت,PINPUT_ریکارډ lp_بفر,DWORD n_اوږدتیا,LPDWORD lp_شمېره_د_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_ننوت_W(HANDLE h_Console_ننوت,PINPUT_ریکارډ lp_بفر,DWORD n_اوږدتیا,LPDWORD lp_شمېره_د_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_ننوت_A(HANDLE h_Console_ننوت,CONST ننوت_ریکارډ_2 *lp_بفر,DWORD n_اوږدتیا,LPDWORD lp_شمېره_د_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_ننوت_W(HANDLE h_Console_ننوت,CONST ننوت_ریکارډ_2 *lp_بفر,DWORD n_اوږدتیا,LPDWORD lp_شمېره_د_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_بفر,COORD dw_بفر_اندازه,COORD dw_بفر_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_بفر,COORD dw_بفر_اندازه,COORD dw_بفر_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_بفر,COORD dw_بفر_اندازه,COORD dw_بفر_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_بفر,COORD dw_بفر_اندازه,COORD dw_بفر_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_اوږدتیا,COORD dwReadCoord,LPDWORD lp_شمېره_د_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_اوږدتیا,COORD dwReadCoord,LPDWORD lp_شمېره_د_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_اوږدتیا,COORD dwReadCoord,LPDWORD lp_شمېره_د_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_اوږدتیا,COORD dwWriteCoord,LPDWORD lp_شمېره_د_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_اوږدتیا,COORD dwWriteCoord,LPDWORD lp_شمېره_د_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST کلمه_3 *lpAttribute,DWORD n_اوږدتیا,COORD dwWriteCoord,LPDWORD lp_شمېره_د_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_اوږدتیا,COORD dwWriteCoord,LPDWORD lp_شمېره_د_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_اوږدتیا,COORD dwWriteCoord,LPDWORD lp_شمېره_د_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,کلمه_3 wAttribute,DWORD n_اوږدتیا,COORD dwWriteCoord,LPDWORD lp_شمېره_د_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI Get_Console_ډېرپېښ(HANDLE hConsoleHandle,LPDWORD lp_ډېرپېښ);
  WINBASEAPI WINBOOL WINAPI Get_شمېره_د_Console_ننوت_Events(HANDLE h_Console_ننوت,LPDWORD lp_شمېره_د_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_بفر_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_بفر_INFO lp_Console_Screen_بفر_Info);
  WINBASEAPI COORD WINAPI Get_تر_ټولو_لوی_Console_کړکۍ_اندازه(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL b_اعظمي_کړکۍ,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_اندازه(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_شمېره_د_Console_Mouse_Buttons(LPDWORD lp_شمېره_د_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_ډېرپېښ(HANDLE hConsoleHandle,DWORD dw_ډېرپېښ);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_فعال_Screen_بفر(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_ننوت_بفر(HANDLE h_Console_ننوت);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_Screen_بفر_اندازه(HANDLE hConsoleOutput,COORD dw_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_Cursor_Position(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_Cursor_Info(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_بفر_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_بفر_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_کړکۍ_Info(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lp_Console_کړکۍ);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_متن_Attribute(HANDLE hConsoleOutput,کلمه_3 w_ځانګړتیاوې);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_Ctrl_Handler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL جمع_کړه_3);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dw_Process_ډله_Id);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#تعریف_کړه ATTACH_پلار_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_Title_A(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_Title_W(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_ننوت,LPVOID lp_بفر,DWORD n_شمېره_د_Chars_منزل_Read,LPDWORD lp_شمېره_د_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_ننوت,LPVOID lp_بفر,DWORD n_شمېره_د_Chars_منزل_Read,LPDWORD lp_شمېره_د_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_بفر,DWORD n_شمېره_د_Chars_منزل_Write,LPDWORD lp_شمېره_د_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_بفر,DWORD n_شمېره_د_Chars_منزل_Write,LPDWORD lp_شمېره_د_Chars_Written,LPVOID lpReserved);

#تعریف_کړه CONSOLE_TEXTMODE_بفر 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_بفر(DWORD dwDesiredAccess,DWORD dw_Share_ډېرپېښ,CONST SECURITY_ځانګړتیاوې_2 *lp_Security_ځانګړتیاوې,DWORD dwFlags,LPVOID lp_Screen_بفر_معلومات);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_CP(UINT w_کوډ_پاڼه_ID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI سېټ_Console_Output_CP(UINT w_کوډ_پاڼه_ID);

#تعریف_کړه CONSOLE_FULLSCREEN 1
#تعریف_کړه CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI Get_Console_Display_ډېرپېښ(LPDWORD lp_ډېرپېښ_Flags);
  WINBASEAPI HWND WINAPI Get_Console_کړکۍ(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_شمېر);
  WINBASEAPI WINBOOL WINAPI جمع_کړه_Console_Alias_A(LPSTR سرچینه_2,LPSTR موخه_2,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI جمع_کړه_Console_Alias_W(LPWSTR سرچینه_2,LPWSTR موخه_2,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR سرچینه_2,LPSTR موخه_بفر,DWORD موخه_بفر_اوږدتیا,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR سرچینه_2,LPWSTR موخه_بفر,DWORD موخه_بفر_اوږدتیا,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_اوږدتیا_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_اوږدتیا_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_اوږدتیا_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_اوږدتیا_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_بفر,DWORD Alias_بفر_اوږدتیا,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_بفر,DWORD Alias_بفر_اوږدتیا,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_بفر,DWORD Exe_Name_بفر_اوږدتیا);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_بفر,DWORD Exe_Name_بفر_اوږدتیا);

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
