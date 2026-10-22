/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _WINCON_
#تعریف_کرو _WINCON_

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

  تعريفنوع بنية _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  تعريفنوع بنية _SMALL_RECT {
    SHORT بایاں_2;
    SHORT چوٹی_2;
    SHORT دایاں_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  تعريفنوع بنية کلید_EVENT_ریکارڈ {
    WINBOOL b_کلید_تھلے;
    لفظ_3 w_Repeat_گنتی;
    لفظ_3 w_Virtual_کلید_کوڈ;
    لفظ_3 w_Virtual_جانچ_کوڈ;
    اتحاد {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_کلید_State;
  } کلید_EVENT_ریکارڈ_2,*PKEY_EVENT_ریکارڈ;

#تعریف_کرو دایاں_ALT_PRESSED 0x1
#تعریف_کرو بایاں_ALT_PRESSED 0x2
#تعریف_کرو دایاں_CTRL_PRESSED 0x4
#تعریف_کرو بایاں_CTRL_PRESSED 0x8
#تعریف_کرو کھسکاؤ_PRESSED 0x10
#تعریف_کرو NUMLOCK_ON 0x20
#تعریف_کرو SCROLLLOCK_ON 0x40
#تعریف_کرو CAPSLOCK_ON 0x80
#تعریف_کرو ENHANCED_کلید 0x100
#تعریف_کرو NLS_DBCSCHAR 0x10000
#تعریف_کرو NLS_ALPHANUMERIC 0x0
#تعریف_کرو NLS_KATAKANA 0x20000
#تعریف_کرو NLS_HIRAGANA 0x40000
#تعریف_کرو NLS_ROMAN 0x400000
#تعریف_کرو NLS_IME_CONVERSION 0x800000
#تعریف_کرو NLS_IME_DISABLE 0x20000000

  تعريفنوع بنية MOUSE_EVENT_ریکارڈ {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_کلید_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_ریکارڈ_2,*PMOUSE_EVENT_ریکارڈ;

#تعریف_کرو FROM_بایاں_1_ST_BUTTON_PRESSED 0x1
#تعریف_کرو RIGHTMOST_BUTTON_PRESSED 0x2
#تعریف_کرو FROM_بایاں_2_ND_BUTTON_PRESSED 0x4
#تعریف_کرو FROM_بایاں_3_RD_BUTTON_PRESSED 0x8
#تعریف_کرو FROM_بایاں_4_TH_BUTTON_PRESSED 0x10

#تعریف_کرو MOUSE_MOVED 0x1
#تعریف_کرو DOUBLE_CLICK 0x2
#تعریف_کرو MOUSE_WHEELED 0x4

  تعريفنوع بنية کھڑکی_بفر_ناپ_ریکارڈ {
    COORD dw_ناپ;
  } کھڑکی_بفر_ناپ_ریکارڈ_2,*PWINDOW_بفر_ناپ_ریکارڈ;

  تعريفنوع بنية MENU_EVENT_ریکارڈ {
    UINT dwCommandId;
  } MENU_EVENT_ریکارڈ_2,*PMENU_EVENT_ریکارڈ;

  تعريفنوع بنية FOCUS_EVENT_ریکارڈ {
    WINBOOL b_سیٹ_Focus;
  } FOCUS_EVENT_ریکارڈ_2,*PFOCUS_EVENT_ریکارڈ;

  تعريفنوع بنية داخلہ_ریکارڈ {
    لفظ_3 EventType;
    اتحاد {
      کلید_EVENT_ریکارڈ_2 کلید_Event;
      MOUSE_EVENT_ریکارڈ_2 MouseEvent;
      کھڑکی_بفر_ناپ_ریکارڈ_2 کھڑکی_بفر_ناپ_Event;
      MENU_EVENT_ریکارڈ_2 MenuEvent;
      FOCUS_EVENT_ریکارڈ_2 FocusEvent;
    } Event;
  } داخلہ_ریکارڈ_2,*PINPUT_ریکارڈ;

#تعریف_کرو کلید_EVENT 0x1
#تعریف_کرو MOUSE_EVENT 0x2
#تعریف_کرو کھڑکی_بفر_ناپ_EVENT 0x4
#تعریف_کرو MENU_EVENT 0x8
#تعریف_کرو FOCUS_EVENT 0x10

  تعريفنوع بنية _CHAR_INFO {
    اتحاد {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    لفظ_3 گن;
  } CHAR_INFO,*PCHAR_INFO;

#تعریف_کرو FOREGROUND_BLUE 0x1
#تعریف_کرو FOREGROUND_GREEN 0x2
#تعریف_کرو FOREGROUND_RED 0x4
#تعریف_کرو FOREGROUND_INTENSITY 0x8
#تعریف_کرو BACKGROUND_BLUE 0x10
#تعریف_کرو BACKGROUND_GREEN 0x20
#تعریف_کرو BACKGROUND_RED 0x40
#تعریف_کرو BACKGROUND_INTENSITY 0x80
#تعریف_کرو COMMON_LVB_LEADING_BYTE 0x100
#تعریف_کرو COMMON_LVB_TRAILING_BYTE 0x200
#تعریف_کرو COMMON_LVB_GRID_HORIZONTAL 0x400
#تعریف_کرو COMMON_LVB_GRID_LVERTICAL 0x800
#تعریف_کرو COMMON_LVB_GRID_RVERTICAL 0x1000
#تعریف_کرو COMMON_LVB_الٹ_VIDEO 0x4000
#تعریف_کرو COMMON_LVB_UNDERSCORE 0x8000

#تعریف_کرو COMMON_LVB_SBCSDBCS 0x300

  تعريفنوع بنية CONSOLE_SCREEN_بفر_INFO {
    COORD dw_ناپ;
    COORD dwCursorPosition;
    لفظ_3 w_گن;
    SMALL_RECT sr_کھڑکی;
    COORD dw_ودھ_توں_ودھ_کھڑکی_ناپ;
  } CONSOLE_SCREEN_بفر_INFO_2,*PCONSOLE_SCREEN_بفر_INFO;

  تعريفنوع بنية _CONSOLE_CURSOR_INFO {
    DWORD dw_ناپ;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  تعريفنوع بنية _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dw_Font_ناپ;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  تعريفنوع بنية _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#تعریف_کرو CONSOLE_NO_SELECTION 0x0
#تعریف_کرو CONSOLE_SELECTION_وچ_ترقی 0x1
#تعریف_کرو CONSOLE_SELECTION_NOT_خالی_تھاواں 0x2
#تعریف_کرو CONSOLE_MOUSE_SELECTION 0x4
#تعریف_کرو CONSOLE_MOUSE_تھلے 0x8

  تعريفنوع WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#تعریف_کرو CTRL_C_EVENT 0
#تعریف_کرو CTRL_BREAK_EVENT 1
#تعریف_کرو CTRL_CLOSE_EVENT 2

#تعریف_کرو CTRL_LOGOFF_EVENT 5
#تعریف_کرو CTRL_SHUTDOWN_EVENT 6

#تعریف_کرو ENABLE_PROCESSED_داخلہ 0x1
#تعریف_کرو ENABLE_سطر_داخلہ 0x2
#تعریف_کرو ENABLE_ECHO_داخلہ 0x4
#تعریف_کرو ENABLE_کھڑکی_داخلہ 0x8
#تعریف_کرو ENABLE_MOUSE_داخلہ 0x10
#تعریف_کرو ENABLE_داخل_کرو_منوال 0x20
#تعریف_کرو ENABLE_تیز_EDIT_منوال 0x40
#تعریف_کرو ENABLE_EXTENDED_FLAGS 0x80
#تعریف_کرو ENABLE_AUTO_POSITION 0x100
#تعریف_کرو ENABLE_VIRTUAL_TERMINAL_داخلہ 0x200

#تعریف_کرو ENABLE_PROCESSED_OUTPUT 0x1
#تعریف_کرو ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#تعریف_کرو ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#تعریف_کرو DISABLE_NEWLINE_AUTO_RETURN 0x8
#تعریف_کرو ENABLE_LVB_GRID_WORLDWIDE 0x10

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Peek_Console_داخلہ Peek_Console_داخلہ_W
#تعریف_کرو Read_Console_داخلہ Read_Console_داخلہ_W
#تعریف_کرو Write_Console_داخلہ Write_Console_داخلہ_W
#تعریف_کرو ReadConsoleOutput ReadConsoleOutputW
#تعریف_کرو WriteConsoleOutput WriteConsoleOutputW
#تعریف_کرو ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#تعریف_کرو WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#تعریف_کرو FillConsoleOutputCharacter FillConsoleOutputCharacterW
#تعریف_کرو Scroll_Console_Screen_بفر Scroll_Console_Screen_بفر_W
#تعریف_کرو GetConsoleTitle GetConsoleTitleW
#تعریف_کرو سیٹ_Console_Title سیٹ_Console_Title_W
#تعریف_کرو ReadConsole ReadConsoleW
#تعریف_کرو WriteConsole WriteConsoleW
#تعریف_کرو جوڑو_Console_Alias جوڑو_Console_Alias_W
#تعریف_کرو GetConsoleAlias GetConsoleAliasW
#تعریف_کرو Get_Console_Aliases_لمائی Get_Console_Aliases_لمائی_W
#تعریف_کرو Get_Console_Alias_Exes_لمائی Get_Console_Alias_Exes_لمائی_W
#تعریف_کرو GetConsoleAliases GetConsoleAliasesW
#تعریف_کرو GetConsoleAliasExes GetConsoleAliasExesW
#وإلا
#تعریف_کرو Peek_Console_داخلہ Peek_Console_داخلہ_A
#تعریف_کرو Read_Console_داخلہ Read_Console_داخلہ_A
#تعریف_کرو Write_Console_داخلہ Write_Console_داخلہ_A
#تعریف_کرو ReadConsoleOutput ReadConsoleOutputA
#تعریف_کرو WriteConsoleOutput WriteConsoleOutputA
#تعریف_کرو ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#تعریف_کرو WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#تعریف_کرو FillConsoleOutputCharacter FillConsoleOutputCharacterA
#تعریف_کرو Scroll_Console_Screen_بفر Scroll_Console_Screen_بفر_A
#تعریف_کرو GetConsoleTitle GetConsoleTitleA
#تعریف_کرو سیٹ_Console_Title سیٹ_Console_Title_A
#تعریف_کرو ReadConsole ReadConsoleA
#تعریف_کرو WriteConsole WriteConsoleA
#تعریف_کرو جوڑو_Console_Alias جوڑو_Console_Alias_A
#تعریف_کرو GetConsoleAlias GetConsoleAliasA
#تعریف_کرو Get_Console_Aliases_لمائی Get_Console_Aliases_لمائی_A
#تعریف_کرو Get_Console_Alias_Exes_لمائی Get_Console_Alias_Exes_لمائی_A
#تعریف_کرو GetConsoleAliases GetConsoleAliasesA
#تعریف_کرو GetConsoleAliasExes GetConsoleAliasExesA
#جے_انت

  WINBASEAPI WINBOOL WINAPI Peek_Console_داخلہ_A(HANDLE h_Console_داخلہ,PINPUT_ریکارڈ lp_بفر,DWORD n_لمائی,LPDWORD lp_نمبر_دا_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_داخلہ_W(HANDLE h_Console_داخلہ,PINPUT_ریکارڈ lp_بفر,DWORD n_لمائی,LPDWORD lp_نمبر_دا_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_داخلہ_A(HANDLE h_Console_داخلہ,PINPUT_ریکارڈ lp_بفر,DWORD n_لمائی,LPDWORD lp_نمبر_دا_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_داخلہ_W(HANDLE h_Console_داخلہ,PINPUT_ریکارڈ lp_بفر,DWORD n_لمائی,LPDWORD lp_نمبر_دا_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_داخلہ_A(HANDLE h_Console_داخلہ,CONST داخلہ_ریکارڈ_2 *lp_بفر,DWORD n_لمائی,LPDWORD lp_نمبر_دا_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_داخلہ_W(HANDLE h_Console_داخلہ,CONST داخلہ_ریکارڈ_2 *lp_بفر,DWORD n_لمائی,LPDWORD lp_نمبر_دا_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_بفر,COORD dw_بفر_ناپ,COORD dw_بفر_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_بفر,COORD dw_بفر_ناپ,COORD dw_بفر_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_بفر,COORD dw_بفر_ناپ,COORD dw_بفر_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_بفر,COORD dw_بفر_ناپ,COORD dw_بفر_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_لمائی,COORD dwReadCoord,LPDWORD lp_نمبر_دا_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_لمائی,COORD dwReadCoord,LPDWORD lp_نمبر_دا_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_لمائی,COORD dwReadCoord,LPDWORD lp_نمبر_دا_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_لمائی,COORD dwWriteCoord,LPDWORD lp_نمبر_دا_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_لمائی,COORD dwWriteCoord,LPDWORD lp_نمبر_دا_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST لفظ_3 *lpAttribute,DWORD n_لمائی,COORD dwWriteCoord,LPDWORD lp_نمبر_دا_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_لمائی,COORD dwWriteCoord,LPDWORD lp_نمبر_دا_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_لمائی,COORD dwWriteCoord,LPDWORD lp_نمبر_دا_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,لفظ_3 wAttribute,DWORD n_لمائی,COORD dwWriteCoord,LPDWORD lp_نمبر_دا_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI Get_Console_منوال(HANDLE hConsoleHandle,LPDWORD lp_منوال);
  WINBASEAPI WINBOOL WINAPI Get_نمبر_دا_Console_داخلہ_Events(HANDLE h_Console_داخلہ,LPDWORD lp_نمبر_دا_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_بفر_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_بفر_INFO lp_Console_Screen_بفر_Info);
  WINBASEAPI COORD WINAPI Get_سبھ_توں_وڈا_Console_کھڑکی_ناپ(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL b_ودھ_توں_ودھ_کھڑکی,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_ناپ(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_نمبر_دا_Console_Mouse_Buttons(LPDWORD lp_نمبر_دا_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_منوال(HANDLE hConsoleHandle,DWORD dw_منوال);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_سرگرم_Screen_بفر(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_داخلہ_بفر(HANDLE h_Console_داخلہ);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_Screen_بفر_ناپ(HANDLE hConsoleOutput,COORD dw_ناپ);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_Cursor_Position(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_Cursor_Info(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_بفر_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_بفر_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_کھڑکی_Info(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lp_Console_کھڑکی);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_متن_Attribute(HANDLE hConsoleOutput,لفظ_3 w_گن);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_Ctrl_Handler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL جوڑو_3);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dw_Process_گروہ_Id);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#تعریف_کرو ATTACH_ماپا_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_ناپ);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_ناپ);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_Title_A(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_Title_W(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_داخلہ,LPVOID lp_بفر,DWORD n_نمبر_دا_Chars_منزل_Read,LPDWORD lp_نمبر_دا_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_داخلہ,LPVOID lp_بفر,DWORD n_نمبر_دا_Chars_منزل_Read,LPDWORD lp_نمبر_دا_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_بفر,DWORD n_نمبر_دا_Chars_منزل_Write,LPDWORD lp_نمبر_دا_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_بفر,DWORD n_نمبر_دا_Chars_منزل_Write,LPDWORD lp_نمبر_دا_Chars_Written,LPVOID lpReserved);

#تعریف_کرو CONSOLE_TEXTMODE_بفر 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_بفر(DWORD dwDesiredAccess,DWORD dw_Share_منوال,CONST SECURITY_گن_2 *lp_Security_گن,DWORD dwFlags,LPVOID lp_Screen_بفر_انکڑے);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_CP(UINT w_کوڈ_ورقہ_ID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI سیٹ_Console_Output_CP(UINT w_کوڈ_ورقہ_ID);

#تعریف_کرو CONSOLE_FULLSCREEN 1
#تعریف_کرو CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI Get_Console_Display_منوال(LPDWORD lp_منوال_Flags);
  WINBASEAPI HWND WINAPI Get_Console_کھڑکی(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_گنتی);
  WINBASEAPI WINBOOL WINAPI جوڑو_Console_Alias_A(LPSTR سروت_2,LPSTR نشانہ_2,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI جوڑو_Console_Alias_W(LPWSTR سروت_2,LPWSTR نشانہ_2,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR سروت_2,LPSTR نشانہ_بفر,DWORD نشانہ_بفر_لمائی,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR سروت_2,LPWSTR نشانہ_بفر,DWORD نشانہ_بفر_لمائی,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_لمائی_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_لمائی_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_لمائی_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_لمائی_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_بفر,DWORD Alias_بفر_لمائی,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_بفر,DWORD Alias_بفر_لمائی,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_بفر,DWORD Exe_Name_بفر_لمائی);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_بفر,DWORD Exe_Name_بفر_لمائی);

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
