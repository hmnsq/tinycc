/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _WINCON_
#وصف_ڪريو _WINCON_

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

  تعريفنوع بنية _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  تعريفنوع بنية _SMALL_RECT {
    SHORT کاٻو_2;
    SHORT چوٽي_2;
    SHORT ساڄو_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  تعريفنوع بنية ڪنجي_EVENT_رڪارڊ {
    WINBOOL b_ڪنجي_هيٺ_ڏانهن;
    لفظ_3 w_Repeat_ڳڻپ;
    لفظ_3 w_Virtual_ڪنجي_ڪوڊ;
    لفظ_3 w_Virtual_جاچ_ڪوڊ;
    اتحاد {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_ڪنجي_State;
  } ڪنجي_EVENT_رڪارڊ_2,*PKEY_EVENT_رڪارڊ;

#وصف_ڪريو ساڄو_ALT_PRESSED 0x1
#وصف_ڪريو کاٻو_ALT_PRESSED 0x2
#وصف_ڪريو ساڄو_CTRL_PRESSED 0x4
#وصف_ڪريو کاٻو_CTRL_PRESSED 0x8
#وصف_ڪريو سرڪايو_PRESSED 0x10
#وصف_ڪريو NUMLOCK_ON 0x20
#وصف_ڪريو SCROLLLOCK_ON 0x40
#وصف_ڪريو CAPSLOCK_ON 0x80
#وصف_ڪريو ENHANCED_ڪنجي 0x100
#وصف_ڪريو NLS_DBCSCHAR 0x10000
#وصف_ڪريو NLS_ALPHANUMERIC 0x0
#وصف_ڪريو NLS_KATAKANA 0x20000
#وصف_ڪريو NLS_HIRAGANA 0x40000
#وصف_ڪريو NLS_ROMAN 0x400000
#وصف_ڪريو NLS_IME_CONVERSION 0x800000
#وصف_ڪريو NLS_IME_DISABLE 0x20000000

  تعريفنوع بنية MOUSE_EVENT_رڪارڊ {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_ڪنجي_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_رڪارڊ_2,*PMOUSE_EVENT_رڪارڊ;

#وصف_ڪريو FROM_کاٻو_1_ST_BUTTON_PRESSED 0x1
#وصف_ڪريو RIGHTMOST_BUTTON_PRESSED 0x2
#وصف_ڪريو FROM_کاٻو_2_ND_BUTTON_PRESSED 0x4
#وصف_ڪريو FROM_کاٻو_3_RD_BUTTON_PRESSED 0x8
#وصف_ڪريو FROM_کاٻو_4_TH_BUTTON_PRESSED 0x10

#وصف_ڪريو MOUSE_MOVED 0x1
#وصف_ڪريو DOUBLE_CLICK 0x2
#وصف_ڪريو MOUSE_WHEELED 0x4

  تعريفنوع بنية دري_بفر_سائيز_رڪارڊ {
    COORD dw_سائيز;
  } دري_بفر_سائيز_رڪارڊ_2,*PWINDOW_بفر_سائيز_رڪارڊ;

  تعريفنوع بنية MENU_EVENT_رڪارڊ {
    UINT dwCommandId;
  } MENU_EVENT_رڪارڊ_2,*PMENU_EVENT_رڪارڊ;

  تعريفنوع بنية FOCUS_EVENT_رڪارڊ {
    WINBOOL b_سيٽ_Focus;
  } FOCUS_EVENT_رڪارڊ_2,*PFOCUS_EVENT_رڪارڊ;

  تعريفنوع بنية داخلا_رڪارڊ {
    لفظ_3 EventType;
    اتحاد {
      ڪنجي_EVENT_رڪارڊ_2 ڪنجي_Event;
      MOUSE_EVENT_رڪارڊ_2 MouseEvent;
      دري_بفر_سائيز_رڪارڊ_2 دري_بفر_سائيز_Event;
      MENU_EVENT_رڪارڊ_2 MenuEvent;
      FOCUS_EVENT_رڪارڊ_2 FocusEvent;
    } Event;
  } داخلا_رڪارڊ_2,*PINPUT_رڪارڊ;

#وصف_ڪريو ڪنجي_EVENT 0x1
#وصف_ڪريو MOUSE_EVENT 0x2
#وصف_ڪريو دري_بفر_سائيز_EVENT 0x4
#وصف_ڪريو MENU_EVENT 0x8
#وصف_ڪريو FOCUS_EVENT 0x10

  تعريفنوع بنية _CHAR_INFO {
    اتحاد {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    لفظ_3 خاصيتون;
  } CHAR_INFO,*PCHAR_INFO;

#وصف_ڪريو FOREGROUND_BLUE 0x1
#وصف_ڪريو FOREGROUND_GREEN 0x2
#وصف_ڪريو FOREGROUND_RED 0x4
#وصف_ڪريو FOREGROUND_INTENSITY 0x8
#وصف_ڪريو BACKGROUND_BLUE 0x10
#وصف_ڪريو BACKGROUND_GREEN 0x20
#وصف_ڪريو BACKGROUND_RED 0x40
#وصف_ڪريو BACKGROUND_INTENSITY 0x80
#وصف_ڪريو COMMON_LVB_LEADING_BYTE 0x100
#وصف_ڪريو COMMON_LVB_TRAILING_BYTE 0x200
#وصف_ڪريو COMMON_LVB_GRID_HORIZONTAL 0x400
#وصف_ڪريو COMMON_LVB_GRID_LVERTICAL 0x800
#وصف_ڪريو COMMON_LVB_GRID_RVERTICAL 0x1000
#وصف_ڪريو COMMON_LVB_ابتو_VIDEO 0x4000
#وصف_ڪريو COMMON_LVB_UNDERSCORE 0x8000

#وصف_ڪريو COMMON_LVB_SBCSDBCS 0x300

  تعريفنوع بنية CONSOLE_SCREEN_بفر_INFO {
    COORD dw_سائيز;
    COORD dwCursorPosition;
    لفظ_3 w_خاصيتون;
    SMALL_RECT sr_دري;
    COORD dw_وڌ_کان_وڌ_دري_سائيز;
  } CONSOLE_SCREEN_بفر_INFO_2,*PCONSOLE_SCREEN_بفر_INFO;

  تعريفنوع بنية _CONSOLE_CURSOR_INFO {
    DWORD dw_سائيز;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  تعريفنوع بنية _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dw_Font_سائيز;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  تعريفنوع بنية _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#وصف_ڪريو CONSOLE_NO_SELECTION 0x0
#وصف_ڪريو CONSOLE_SELECTION_اندريون_ترقي 0x1
#وصف_ڪريو CONSOLE_SELECTION_NOT_خالي_جايون 0x2
#وصف_ڪريو CONSOLE_MOUSE_SELECTION 0x4
#وصف_ڪريو CONSOLE_MOUSE_هيٺ_ڏانهن 0x8

  تعريفنوع WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#وصف_ڪريو CTRL_C_EVENT 0
#وصف_ڪريو CTRL_BREAK_EVENT 1
#وصف_ڪريو CTRL_CLOSE_EVENT 2

#وصف_ڪريو CTRL_LOGOFF_EVENT 5
#وصف_ڪريو CTRL_SHUTDOWN_EVENT 6

#وصف_ڪريو ENABLE_PROCESSED_داخلا 0x1
#وصف_ڪريو ENABLE_سٽ_داخلا 0x2
#وصف_ڪريو ENABLE_ECHO_داخلا 0x4
#وصف_ڪريو ENABLE_دري_داخلا 0x8
#وصف_ڪريو ENABLE_MOUSE_داخلا 0x10
#وصف_ڪريو ENABLE_وجهو_گهڻائي 0x20
#وصف_ڪريو ENABLE_تيز_EDIT_گهڻائي 0x40
#وصف_ڪريو ENABLE_EXTENDED_FLAGS 0x80
#وصف_ڪريو ENABLE_AUTO_POSITION 0x100
#وصف_ڪريو ENABLE_VIRTUAL_TERMINAL_داخلا 0x200

#وصف_ڪريو ENABLE_PROCESSED_OUTPUT 0x1
#وصف_ڪريو ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#وصف_ڪريو ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#وصف_ڪريو DISABLE_NEWLINE_AUTO_RETURN 0x8
#وصف_ڪريو ENABLE_LVB_GRID_WORLDWIDE 0x10

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Peek_Console_داخلا Peek_Console_داخلا_W
#وصف_ڪريو Read_Console_داخلا Read_Console_داخلا_W
#وصف_ڪريو Write_Console_داخلا Write_Console_داخلا_W
#وصف_ڪريو ReadConsoleOutput ReadConsoleOutputW
#وصف_ڪريو WriteConsoleOutput WriteConsoleOutputW
#وصف_ڪريو ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#وصف_ڪريو WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#وصف_ڪريو FillConsoleOutputCharacter FillConsoleOutputCharacterW
#وصف_ڪريو Scroll_Console_Screen_بفر Scroll_Console_Screen_بفر_W
#وصف_ڪريو GetConsoleTitle GetConsoleTitleW
#وصف_ڪريو سيٽ_Console_Title سيٽ_Console_Title_W
#وصف_ڪريو ReadConsole ReadConsoleW
#وصف_ڪريو WriteConsole WriteConsoleW
#وصف_ڪريو جوڙيو_Console_Alias جوڙيو_Console_Alias_W
#وصف_ڪريو GetConsoleAlias GetConsoleAliasW
#وصف_ڪريو Get_Console_Aliases_ڊيگهائي Get_Console_Aliases_ڊيگهائي_W
#وصف_ڪريو Get_Console_Alias_Exes_ڊيگهائي Get_Console_Alias_Exes_ڊيگهائي_W
#وصف_ڪريو GetConsoleAliases GetConsoleAliasesW
#وصف_ڪريو GetConsoleAliasExes GetConsoleAliasExesW
#وإلا
#وصف_ڪريو Peek_Console_داخلا Peek_Console_داخلا_A
#وصف_ڪريو Read_Console_داخلا Read_Console_داخلا_A
#وصف_ڪريو Write_Console_داخلا Write_Console_داخلا_A
#وصف_ڪريو ReadConsoleOutput ReadConsoleOutputA
#وصف_ڪريو WriteConsoleOutput WriteConsoleOutputA
#وصف_ڪريو ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#وصف_ڪريو WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#وصف_ڪريو FillConsoleOutputCharacter FillConsoleOutputCharacterA
#وصف_ڪريو Scroll_Console_Screen_بفر Scroll_Console_Screen_بفر_A
#وصف_ڪريو GetConsoleTitle GetConsoleTitleA
#وصف_ڪريو سيٽ_Console_Title سيٽ_Console_Title_A
#وصف_ڪريو ReadConsole ReadConsoleA
#وصف_ڪريو WriteConsole WriteConsoleA
#وصف_ڪريو جوڙيو_Console_Alias جوڙيو_Console_Alias_A
#وصف_ڪريو GetConsoleAlias GetConsoleAliasA
#وصف_ڪريو Get_Console_Aliases_ڊيگهائي Get_Console_Aliases_ڊيگهائي_A
#وصف_ڪريو Get_Console_Alias_Exes_ڊيگهائي Get_Console_Alias_Exes_ڊيگهائي_A
#وصف_ڪريو GetConsoleAliases GetConsoleAliasesA
#وصف_ڪريو GetConsoleAliasExes GetConsoleAliasExesA
#جيڪڏهن_پورو

  WINBASEAPI WINBOOL WINAPI Peek_Console_داخلا_A(HANDLE h_Console_داخلا,PINPUT_رڪارڊ lp_بفر,DWORD n_ڊيگهائي,LPDWORD lp_عدد_جو_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_داخلا_W(HANDLE h_Console_داخلا,PINPUT_رڪارڊ lp_بفر,DWORD n_ڊيگهائي,LPDWORD lp_عدد_جو_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_داخلا_A(HANDLE h_Console_داخلا,PINPUT_رڪارڊ lp_بفر,DWORD n_ڊيگهائي,LPDWORD lp_عدد_جو_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_داخلا_W(HANDLE h_Console_داخلا,PINPUT_رڪارڊ lp_بفر,DWORD n_ڊيگهائي,LPDWORD lp_عدد_جو_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_داخلا_A(HANDLE h_Console_داخلا,CONST داخلا_رڪارڊ_2 *lp_بفر,DWORD n_ڊيگهائي,LPDWORD lp_عدد_جو_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_داخلا_W(HANDLE h_Console_داخلا,CONST داخلا_رڪارڊ_2 *lp_بفر,DWORD n_ڊيگهائي,LPDWORD lp_عدد_جو_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_بفر,COORD dw_بفر_سائيز,COORD dw_بفر_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_بفر,COORD dw_بفر_سائيز,COORD dw_بفر_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_بفر,COORD dw_بفر_سائيز,COORD dw_بفر_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_بفر,COORD dw_بفر_سائيز,COORD dw_بفر_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_ڊيگهائي,COORD dwReadCoord,LPDWORD lp_عدد_جو_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_ڊيگهائي,COORD dwReadCoord,LPDWORD lp_عدد_جو_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_ڊيگهائي,COORD dwReadCoord,LPDWORD lp_عدد_جو_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_ڊيگهائي,COORD dwWriteCoord,LPDWORD lp_عدد_جو_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_ڊيگهائي,COORD dwWriteCoord,LPDWORD lp_عدد_جو_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST لفظ_3 *lpAttribute,DWORD n_ڊيگهائي,COORD dwWriteCoord,LPDWORD lp_عدد_جو_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_ڊيگهائي,COORD dwWriteCoord,LPDWORD lp_عدد_جو_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_ڊيگهائي,COORD dwWriteCoord,LPDWORD lp_عدد_جو_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,لفظ_3 wAttribute,DWORD n_ڊيگهائي,COORD dwWriteCoord,LPDWORD lp_عدد_جو_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI Get_Console_گهڻائي(HANDLE hConsoleHandle,LPDWORD lp_گهڻائي);
  WINBASEAPI WINBOOL WINAPI Get_عدد_جو_Console_داخلا_Events(HANDLE h_Console_داخلا,LPDWORD lp_عدد_جو_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_بفر_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_بفر_INFO lp_Console_Screen_بفر_Info);
  WINBASEAPI COORD WINAPI Get_سڀ_کان_وڏو_Console_دري_سائيز(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL b_وڌ_کان_وڌ_دري,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_سائيز(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_عدد_جو_Console_Mouse_Buttons(LPDWORD lp_عدد_جو_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_گهڻائي(HANDLE hConsoleHandle,DWORD dw_گهڻائي);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_سرگرم_Screen_بفر(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_داخلا_بفر(HANDLE h_Console_داخلا);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_Screen_بفر_سائيز(HANDLE hConsoleOutput,COORD dw_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_Cursor_Position(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_Cursor_Info(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_بفر_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_بفر_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_دري_Info(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lp_Console_دري);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_متن_Attribute(HANDLE hConsoleOutput,لفظ_3 w_خاصيتون);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_Ctrl_Handler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL جوڙيو_3);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dw_Process_گروهه_Id);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#وصف_ڪريو ATTACH_والد_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_سائيز);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_سائيز);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_Title_A(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_Title_W(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_داخلا,LPVOID lp_بفر,DWORD n_عدد_جو_Chars_منزل_Read,LPDWORD lp_عدد_جو_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_داخلا,LPVOID lp_بفر,DWORD n_عدد_جو_Chars_منزل_Read,LPDWORD lp_عدد_جو_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_بفر,DWORD n_عدد_جو_Chars_منزل_Write,LPDWORD lp_عدد_جو_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_بفر,DWORD n_عدد_جو_Chars_منزل_Write,LPDWORD lp_عدد_جو_Chars_Written,LPVOID lpReserved);

#وصف_ڪريو CONSOLE_TEXTMODE_بفر 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_بفر(DWORD dwDesiredAccess,DWORD dw_Share_گهڻائي,CONST SECURITY_خاصيتون_2 *lp_Security_خاصيتون,DWORD dwFlags,LPVOID lp_Screen_بفر_معلومات);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_CP(UINT w_ڪوڊ_صفحو_ID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI سيٽ_Console_Output_CP(UINT w_ڪوڊ_صفحو_ID);

#وصف_ڪريو CONSOLE_FULLSCREEN 1
#وصف_ڪريو CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI Get_Console_Display_گهڻائي(LPDWORD lp_گهڻائي_Flags);
  WINBASEAPI HWND WINAPI Get_Console_دري(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_ڳڻپ);
  WINBASEAPI WINBOOL WINAPI جوڙيو_Console_Alias_A(LPSTR ذريعو_2,LPSTR هدف_2,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI جوڙيو_Console_Alias_W(LPWSTR ذريعو_2,LPWSTR هدف_2,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR ذريعو_2,LPSTR هدف_بفر,DWORD هدف_بفر_ڊيگهائي,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR ذريعو_2,LPWSTR هدف_بفر,DWORD هدف_بفر_ڊيگهائي,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_ڊيگهائي_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_ڊيگهائي_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_ڊيگهائي_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_ڊيگهائي_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_بفر,DWORD Alias_بفر_ڊيگهائي,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_بفر,DWORD Alias_بفر_ڊيگهائي,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_بفر,DWORD Exe_Name_بفر_ڊيگهائي);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_بفر,DWORD Exe_Name_بفر_ڊيگهائي);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
