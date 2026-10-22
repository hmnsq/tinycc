/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _WINCON_
#تعریف_کن _WINCON_

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

  تعريفنوع بنية _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  تعريفنوع بنية _SMALL_RECT {
    SHORT چپ_2;
    SHORT بالاترین_2;
    SHORT راست_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  تعريفنوع بنية کلید_EVENT_رکورد {
    WINBOOL b_کلید_پایین;
    کلمه_3 w_Repeat_شمار;
    کلمه_3 w_Virtual_کلید_کد;
    کلمه_3 w_Virtual_پیمایش_کد;
    اتحاد {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_کلید_State;
  } کلید_EVENT_رکورد_2,*PKEY_EVENT_رکورد;

#تعریف_کن راست_ALT_PRESSED 0x1
#تعریف_کن چپ_ALT_PRESSED 0x2
#تعریف_کن راست_CTRL_PRESSED 0x4
#تعریف_کن چپ_CTRL_PRESSED 0x8
#تعریف_کن لغزش_PRESSED 0x10
#تعریف_کن NUMLOCK_ON 0x20
#تعریف_کن SCROLLLOCK_ON 0x40
#تعریف_کن CAPSLOCK_ON 0x80
#تعریف_کن ENHANCED_کلید 0x100
#تعریف_کن NLS_DBCSCHAR 0x10000
#تعریف_کن NLS_ALPHANUMERIC 0x0
#تعریف_کن NLS_KATAKANA 0x20000
#تعریف_کن NLS_HIRAGANA 0x40000
#تعریف_کن NLS_ROMAN 0x400000
#تعریف_کن NLS_IME_CONVERSION 0x800000
#تعریف_کن NLS_IME_DISABLE 0x20000000

  تعريفنوع بنية MOUSE_EVENT_رکورد {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_کلید_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_رکورد_2,*PMOUSE_EVENT_رکورد;

#تعریف_کن FROM_چپ_1_ST_BUTTON_PRESSED 0x1
#تعریف_کن RIGHTMOST_BUTTON_PRESSED 0x2
#تعریف_کن FROM_چپ_2_ND_BUTTON_PRESSED 0x4
#تعریف_کن FROM_چپ_3_RD_BUTTON_PRESSED 0x8
#تعریف_کن FROM_چپ_4_TH_BUTTON_PRESSED 0x10

#تعریف_کن MOUSE_MOVED 0x1
#تعریف_کن DOUBLE_CLICK 0x2
#تعریف_کن MOUSE_WHEELED 0x4

  تعريفنوع بنية پنجره_میانگیر_اندازه_رکورد {
    COORD dw_اندازه;
  } پنجره_میانگیر_اندازه_رکورد_2,*PWINDOW_میانگیر_اندازه_رکورد;

  تعريفنوع بنية MENU_EVENT_رکورد {
    UINT dwCommandId;
  } MENU_EVENT_رکورد_2,*PMENU_EVENT_رکورد;

  تعريفنوع بنية FOCUS_EVENT_رکورد {
    WINBOOL b_مجموعه_Focus;
  } FOCUS_EVENT_رکورد_2,*PFOCUS_EVENT_رکورد;

  تعريفنوع بنية درون_داد_رکورد {
    کلمه_3 EventType;
    اتحاد {
      کلید_EVENT_رکورد_2 کلید_Event;
      MOUSE_EVENT_رکورد_2 MouseEvent;
      پنجره_میانگیر_اندازه_رکورد_2 پنجره_میانگیر_اندازه_Event;
      MENU_EVENT_رکورد_2 MenuEvent;
      FOCUS_EVENT_رکورد_2 FocusEvent;
    } Event;
  } درون_داد_رکورد_2,*PINPUT_رکورد;

#تعریف_کن کلید_EVENT 0x1
#تعریف_کن MOUSE_EVENT 0x2
#تعریف_کن پنجره_میانگیر_اندازه_EVENT 0x4
#تعریف_کن MENU_EVENT 0x8
#تعریف_کن FOCUS_EVENT 0x10

  تعريفنوع بنية _CHAR_INFO {
    اتحاد {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    کلمه_3 صفات;
  } CHAR_INFO,*PCHAR_INFO;

#تعریف_کن FOREGROUND_BLUE 0x1
#تعریف_کن FOREGROUND_GREEN 0x2
#تعریف_کن FOREGROUND_RED 0x4
#تعریف_کن FOREGROUND_INTENSITY 0x8
#تعریف_کن BACKGROUND_BLUE 0x10
#تعریف_کن BACKGROUND_GREEN 0x20
#تعریف_کن BACKGROUND_RED 0x40
#تعریف_کن BACKGROUND_INTENSITY 0x80
#تعریف_کن COMMON_LVB_LEADING_BYTE 0x100
#تعریف_کن COMMON_LVB_TRAILING_BYTE 0x200
#تعریف_کن COMMON_LVB_GRID_HORIZONTAL 0x400
#تعریف_کن COMMON_LVB_GRID_LVERTICAL 0x800
#تعریف_کن COMMON_LVB_GRID_RVERTICAL 0x1000
#تعریف_کن COMMON_LVB_معکوس_VIDEO 0x4000
#تعریف_کن COMMON_LVB_UNDERSCORE 0x8000

#تعریف_کن COMMON_LVB_SBCSDBCS 0x300

  تعريفنوع بنية CONSOLE_SCREEN_میانگیر_INFO {
    COORD dw_اندازه;
    COORD dwCursorPosition;
    کلمه_3 w_صفات;
    SMALL_RECT sr_پنجره;
    COORD dw_بیشینه_پنجره_اندازه;
  } CONSOLE_SCREEN_میانگیر_INFO_2,*PCONSOLE_SCREEN_میانگیر_INFO;

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

#تعریف_کن CONSOLE_NO_SELECTION 0x0
#تعریف_کن CONSOLE_SELECTION_درون_پیشرفت 0x1
#تعریف_کن CONSOLE_SELECTION_NOT_خالی 0x2
#تعریف_کن CONSOLE_MOUSE_SELECTION 0x4
#تعریف_کن CONSOLE_MOUSE_پایین 0x8

  تعريفنوع WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#تعریف_کن CTRL_C_EVENT 0
#تعریف_کن CTRL_BREAK_EVENT 1
#تعریف_کن CTRL_CLOSE_EVENT 2

#تعریف_کن CTRL_LOGOFF_EVENT 5
#تعریف_کن CTRL_SHUTDOWN_EVENT 6

#تعریف_کن ENABLE_PROCESSED_درون_داد 0x1
#تعریف_کن ENABLE_سطر_درون_داد 0x2
#تعریف_کن ENABLE_ECHO_درون_داد 0x4
#تعریف_کن ENABLE_پنجره_درون_داد 0x8
#تعریف_کن ENABLE_MOUSE_درون_داد 0x10
#تعریف_کن ENABLE_درج_نما 0x20
#تعریف_کن ENABLE_سریع_EDIT_نما 0x40
#تعریف_کن ENABLE_EXTENDED_FLAGS 0x80
#تعریف_کن ENABLE_AUTO_POSITION 0x100
#تعریف_کن ENABLE_VIRTUAL_TERMINAL_درون_داد 0x200

#تعریف_کن ENABLE_PROCESSED_OUTPUT 0x1
#تعریف_کن ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#تعریف_کن ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#تعریف_کن DISABLE_NEWLINE_AUTO_RETURN 0x8
#تعریف_کن ENABLE_LVB_GRID_WORLDWIDE 0x10

#اگر_تعریف_شده UNICODE
#تعریف_کن Peek_Console_درون_داد Peek_Console_درون_داد_W
#تعریف_کن Read_Console_درون_داد Read_Console_درون_داد_W
#تعریف_کن Write_Console_درون_داد Write_Console_درون_داد_W
#تعریف_کن ReadConsoleOutput ReadConsoleOutputW
#تعریف_کن WriteConsoleOutput WriteConsoleOutputW
#تعریف_کن ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#تعریف_کن WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#تعریف_کن FillConsoleOutputCharacter FillConsoleOutputCharacterW
#تعریف_کن Scroll_Console_Screen_میانگیر Scroll_Console_Screen_میانگیر_W
#تعریف_کن GetConsoleTitle GetConsoleTitleW
#تعریف_کن مجموعه_Console_Title مجموعه_Console_Title_W
#تعریف_کن ReadConsole ReadConsoleW
#تعریف_کن WriteConsole WriteConsoleW
#تعریف_کن جمع_کن_Console_Alias جمع_کن_Console_Alias_W
#تعریف_کن GetConsoleAlias GetConsoleAliasW
#تعریف_کن Get_Console_Aliases_درازی Get_Console_Aliases_درازی_W
#تعریف_کن Get_Console_Alias_Exes_درازی Get_Console_Alias_Exes_درازی_W
#تعریف_کن GetConsoleAliases GetConsoleAliasesW
#تعریف_کن GetConsoleAliasExes GetConsoleAliasExesW
#وإلا
#تعریف_کن Peek_Console_درون_داد Peek_Console_درون_داد_A
#تعریف_کن Read_Console_درون_داد Read_Console_درون_داد_A
#تعریف_کن Write_Console_درون_داد Write_Console_درون_داد_A
#تعریف_کن ReadConsoleOutput ReadConsoleOutputA
#تعریف_کن WriteConsoleOutput WriteConsoleOutputA
#تعریف_کن ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#تعریف_کن WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#تعریف_کن FillConsoleOutputCharacter FillConsoleOutputCharacterA
#تعریف_کن Scroll_Console_Screen_میانگیر Scroll_Console_Screen_میانگیر_A
#تعریف_کن GetConsoleTitle GetConsoleTitleA
#تعریف_کن مجموعه_Console_Title مجموعه_Console_Title_A
#تعریف_کن ReadConsole ReadConsoleA
#تعریف_کن WriteConsole WriteConsoleA
#تعریف_کن جمع_کن_Console_Alias جمع_کن_Console_Alias_A
#تعریف_کن GetConsoleAlias GetConsoleAliasA
#تعریف_کن Get_Console_Aliases_درازی Get_Console_Aliases_درازی_A
#تعریف_کن Get_Console_Alias_Exes_درازی Get_Console_Alias_Exes_درازی_A
#تعریف_کن GetConsoleAliases GetConsoleAliasesA
#تعریف_کن GetConsoleAliasExes GetConsoleAliasExesA
#پایان_اگر

  WINBASEAPI WINBOOL WINAPI Peek_Console_درون_داد_A(HANDLE h_Console_درون_داد,PINPUT_رکورد lp_میانگیر,DWORD n_درازی,LPDWORD lp_عدد_از_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_درون_داد_W(HANDLE h_Console_درون_داد,PINPUT_رکورد lp_میانگیر,DWORD n_درازی,LPDWORD lp_عدد_از_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_درون_داد_A(HANDLE h_Console_درون_داد,PINPUT_رکورد lp_میانگیر,DWORD n_درازی,LPDWORD lp_عدد_از_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_درون_داد_W(HANDLE h_Console_درون_داد,PINPUT_رکورد lp_میانگیر,DWORD n_درازی,LPDWORD lp_عدد_از_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_درون_داد_A(HANDLE h_Console_درون_داد,CONST درون_داد_رکورد_2 *lp_میانگیر,DWORD n_درازی,LPDWORD lp_عدد_از_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_درون_داد_W(HANDLE h_Console_درون_داد,CONST درون_داد_رکورد_2 *lp_میانگیر,DWORD n_درازی,LPDWORD lp_عدد_از_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_میانگیر,COORD dw_میانگیر_اندازه,COORD dw_میانگیر_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_میانگیر,COORD dw_میانگیر_اندازه,COORD dw_میانگیر_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_میانگیر,COORD dw_میانگیر_اندازه,COORD dw_میانگیر_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_میانگیر,COORD dw_میانگیر_اندازه,COORD dw_میانگیر_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_درازی,COORD dwReadCoord,LPDWORD lp_عدد_از_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_درازی,COORD dwReadCoord,LPDWORD lp_عدد_از_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_درازی,COORD dwReadCoord,LPDWORD lp_عدد_از_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_درازی,COORD dwWriteCoord,LPDWORD lp_عدد_از_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_درازی,COORD dwWriteCoord,LPDWORD lp_عدد_از_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST کلمه_3 *lpAttribute,DWORD n_درازی,COORD dwWriteCoord,LPDWORD lp_عدد_از_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_درازی,COORD dwWriteCoord,LPDWORD lp_عدد_از_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_درازی,COORD dwWriteCoord,LPDWORD lp_عدد_از_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,کلمه_3 wAttribute,DWORD n_درازی,COORD dwWriteCoord,LPDWORD lp_عدد_از_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI Get_Console_نما(HANDLE hConsoleHandle,LPDWORD lp_نما);
  WINBASEAPI WINBOOL WINAPI Get_عدد_از_Console_درون_داد_Events(HANDLE h_Console_درون_داد,LPDWORD lp_عدد_از_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_میانگیر_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_میانگیر_INFO lp_Console_Screen_میانگیر_Info);
  WINBASEAPI COORD WINAPI Get_بزرگترین_Console_پنجره_اندازه(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL b_بیشینه_پنجره,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_اندازه(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_عدد_از_Console_Mouse_Buttons(LPDWORD lp_عدد_از_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_نما(HANDLE hConsoleHandle,DWORD dw_نما);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_فعال_Screen_میانگیر(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_درون_داد_میانگیر(HANDLE h_Console_درون_داد);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_Screen_میانگیر_اندازه(HANDLE hConsoleOutput,COORD dw_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_Cursor_Position(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_Cursor_Info(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_میانگیر_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_میانگیر_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_پنجره_Info(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lp_Console_پنجره);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_متن_Attribute(HANDLE hConsoleOutput,کلمه_3 w_صفات);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_Ctrl_Handler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL جمع_کن_3);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dw_Process_گروه_Id);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#تعریف_کن ATTACH_والد_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_اندازه);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_اندازه);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_Title_A(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_Title_W(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_درون_داد,LPVOID lp_میانگیر,DWORD n_عدد_از_Chars_مقصد_Read,LPDWORD lp_عدد_از_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_درون_داد,LPVOID lp_میانگیر,DWORD n_عدد_از_Chars_مقصد_Read,LPDWORD lp_عدد_از_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_میانگیر,DWORD n_عدد_از_Chars_مقصد_Write,LPDWORD lp_عدد_از_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_میانگیر,DWORD n_عدد_از_Chars_مقصد_Write,LPDWORD lp_عدد_از_Chars_Written,LPVOID lpReserved);

#تعریف_کن CONSOLE_TEXTMODE_میانگیر 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_میانگیر(DWORD dwDesiredAccess,DWORD dw_Share_نما,CONST SECURITY_صفات_2 *lp_Security_صفات,DWORD dwFlags,LPVOID lp_Screen_میانگیر_داده);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_CP(UINT w_کد_صفحه_ID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI مجموعه_Console_Output_CP(UINT w_کد_صفحه_ID);

#تعریف_کن CONSOLE_FULLSCREEN 1
#تعریف_کن CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI Get_Console_Display_نما(LPDWORD lp_نما_Flags);
  WINBASEAPI HWND WINAPI Get_Console_پنجره(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_شمار);
  WINBASEAPI WINBOOL WINAPI جمع_کن_Console_Alias_A(LPSTR منبع_2,LPSTR هدف_2,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI جمع_کن_Console_Alias_W(LPWSTR منبع_2,LPWSTR هدف_2,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR منبع_2,LPSTR هدف_میانگیر,DWORD هدف_میانگیر_درازی,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR منبع_2,LPWSTR هدف_میانگیر,DWORD هدف_میانگیر_درازی,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_درازی_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_درازی_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_درازی_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_درازی_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_میانگیر,DWORD Alias_میانگیر_درازی,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_میانگیر,DWORD Alias_میانگیر_درازی,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_میانگیر,DWORD Exe_Name_میانگیر_درازی);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_میانگیر,DWORD Exe_Name_میانگیر_درازی);

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
