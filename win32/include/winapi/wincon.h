/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINCON_
#define _WINCON_

#ifdef __cplusplus
বাহ্যিক "C" {
#endif

  প্রকারলেখ কাঠামো _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  প্রকারলেখ কাঠামো _SMALL_RECT {
    SHORT বাম_2;
    SHORT শীর্ষ_2;
    SHORT ডান_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  প্রকারলেখ কাঠামো চাবি_EVENT_RECORD {
    WINBOOL b_চাবি_Down;
    WORD w_Repeat_গুনতি;
    WORD w_Virtual_চাবি_Code;
    WORD wVirtualScanCode;
    সংঘ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_চাবি_State;
  } চাবি_EVENT_RECORD_2,*PKEY_EVENT_RECORD;

#define ডান_ALT_PRESSED 0x1
#define বাম_ALT_PRESSED 0x2
#define ডান_CTRL_PRESSED 0x4
#define বাম_CTRL_PRESSED 0x8
#define SHIFT_PRESSED 0x10
#define NUMLOCK_ON 0x20
#define SCROLLLOCK_ON 0x40
#define CAPSLOCK_ON 0x80
#define ENHANCED_চাবি 0x100
#define NLS_DBCSCHAR 0x10000
#define NLS_ALPHANUMERIC 0x0
#define NLS_KATAKANA 0x20000
#define NLS_HIRAGANA 0x40000
#define NLS_ROMAN 0x400000
#define NLS_IME_CONVERSION 0x800000
#define NLS_IME_DISABLE 0x20000000

  প্রকারলেখ কাঠামো _MOUSE_EVENT_RECORD {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_চাবি_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_RECORD,*PMOUSE_EVENT_RECORD;

#define FROM_বাম_1_ST_BUTTON_PRESSED 0x1
#define RIGHTMOST_BUTTON_PRESSED 0x2
#define FROM_বাম_2_ND_BUTTON_PRESSED 0x4
#define FROM_বাম_3_RD_BUTTON_PRESSED 0x8
#define FROM_বাম_4_TH_BUTTON_PRESSED 0x10

#define MOUSE_MOVED 0x1
#define DOUBLE_CLICK 0x2
#define MOUSE_WHEELED 0x4

  প্রকারলেখ কাঠামো WINDOW_বাফার_আকার_RECORD {
    COORD dw_আকার;
  } WINDOW_বাফার_আকার_RECORD_2,*PWINDOW_বাফার_আকার_RECORD;

  প্রকারলেখ কাঠামো _MENU_EVENT_RECORD {
    UINT dwCommandId;
  } MENU_EVENT_RECORD,*PMENU_EVENT_RECORD;

  প্রকারলেখ কাঠামো _FOCUS_EVENT_RECORD {
    WINBOOL bSetFocus;
  } FOCUS_EVENT_RECORD,*PFOCUS_EVENT_RECORD;

  প্রকারলেখ কাঠামো প্রবেশ_RECORD {
    WORD EventType;
    সংঘ {
      চাবি_EVENT_RECORD_2 চাবি_Event;
      MOUSE_EVENT_RECORD MouseEvent;
      WINDOW_বাফার_আকার_RECORD_2 Window_বাফার_আকার_Event;
      MENU_EVENT_RECORD MenuEvent;
      FOCUS_EVENT_RECORD FocusEvent;
    } Event;
  } প্রবেশ_RECORD_2,*PINPUT_RECORD;

#define চাবি_EVENT 0x1
#define MOUSE_EVENT 0x2
#define WINDOW_বাফার_আকার_EVENT 0x4
#define MENU_EVENT 0x8
#define FOCUS_EVENT 0x10

  প্রকারলেখ কাঠামো _CHAR_INFO {
    সংঘ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    WORD Attributes;
  } CHAR_INFO,*PCHAR_INFO;

#define FOREGROUND_BLUE 0x1
#define FOREGROUND_GREEN 0x2
#define FOREGROUND_RED 0x4
#define FOREGROUND_INTENSITY 0x8
#define BACKGROUND_BLUE 0x10
#define BACKGROUND_GREEN 0x20
#define BACKGROUND_RED 0x40
#define BACKGROUND_INTENSITY 0x80
#define COMMON_LVB_LEADING_BYTE 0x100
#define COMMON_LVB_TRAILING_BYTE 0x200
#define COMMON_LVB_GRID_HORIZONTAL 0x400
#define COMMON_LVB_GRID_LVERTICAL 0x800
#define COMMON_LVB_GRID_RVERTICAL 0x1000
#define COMMON_LVB_REVERSE_VIDEO 0x4000
#define COMMON_LVB_UNDERSCORE 0x8000

#define COMMON_LVB_SBCSDBCS 0x300

  প্রকারলেখ কাঠামো CONSOLE_SCREEN_বাফার_INFO {
    COORD dw_আকার;
    COORD dwCursorPosition;
    WORD wAttributes;
    SMALL_RECT srWindow;
    COORD dw_Maximum_Window_আকার;
  } CONSOLE_SCREEN_বাফার_INFO_2,*PCONSOLE_SCREEN_বাফার_INFO;

  প্রকারলেখ কাঠামো _CONSOLE_CURSOR_INFO {
    DWORD dw_আকার;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  প্রকারলেখ কাঠামো _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dw_Font_আকার;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  প্রকারলেখ কাঠামো _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#define CONSOLE_NO_SELECTION 0x0
#define CONSOLE_SELECTION_IN_PROGRESS 0x1
#define CONSOLE_SELECTION_NOT_EMPTY 0x2
#define CONSOLE_MOUSE_SELECTION 0x4
#define CONSOLE_MOUSE_DOWN 0x8

  প্রকারলেখ WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#define CTRL_C_EVENT 0
#define CTRL_BREAK_EVENT 1
#define CTRL_CLOSE_EVENT 2

#define CTRL_LOGOFF_EVENT 5
#define CTRL_SHUTDOWN_EVENT 6

#define ENABLE_PROCESSED_প্রবেশ 0x1
#define ENABLE_সারি_প্রবেশ 0x2
#define ENABLE_ECHO_প্রবেশ 0x4
#define ENABLE_WINDOW_প্রবেশ 0x8
#define ENABLE_MOUSE_প্রবেশ 0x10
#define ENABLE_ঢোকাও_MODE 0x20
#define ENABLE_QUICK_EDIT_MODE 0x40
#define ENABLE_EXTENDED_FLAGS 0x80
#define ENABLE_AUTO_POSITION 0x100
#define ENABLE_VIRTUAL_TERMINAL_প্রবেশ 0x200

#define ENABLE_PROCESSED_OUTPUT 0x1
#define ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#define DISABLE_NEWLINE_AUTO_RETURN 0x8
#define ENABLE_LVB_GRID_WORLDWIDE 0x10

#ifdef UNICODE
#define Peek_Console_প্রবেশ Peek_Console_প্রবেশ_W
#define Read_Console_প্রবেশ Read_Console_প্রবেশ_W
#define Write_Console_প্রবেশ Write_Console_প্রবেশ_W
#define ReadConsoleOutput ReadConsoleOutputW
#define WriteConsoleOutput WriteConsoleOutputW
#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#define FillConsoleOutputCharacter FillConsoleOutputCharacterW
#define Scroll_Console_Screen_বাফার Scroll_Console_Screen_বাফার_W
#define GetConsoleTitle GetConsoleTitleW
#define SetConsoleTitle SetConsoleTitleW
#define ReadConsole ReadConsoleW
#define WriteConsole WriteConsoleW
#define AddConsoleAlias AddConsoleAliasW
#define GetConsoleAlias GetConsoleAliasW
#define Get_Console_Aliases_দৈর্ঘ্য Get_Console_Aliases_দৈর্ঘ্য_W
#define Get_Console_Alias_Exes_দৈর্ঘ্য Get_Console_Alias_Exes_দৈর্ঘ্য_W
#define GetConsoleAliases GetConsoleAliasesW
#define GetConsoleAliasExes GetConsoleAliasExesW
#অন্যথা
#define Peek_Console_প্রবেশ Peek_Console_প্রবেশ_A
#define Read_Console_প্রবেশ Read_Console_প্রবেশ_A
#define Write_Console_প্রবেশ Write_Console_প্রবেশ_A
#define ReadConsoleOutput ReadConsoleOutputA
#define WriteConsoleOutput WriteConsoleOutputA
#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#define FillConsoleOutputCharacter FillConsoleOutputCharacterA
#define Scroll_Console_Screen_বাফার Scroll_Console_Screen_বাফার_A
#define GetConsoleTitle GetConsoleTitleA
#define SetConsoleTitle SetConsoleTitleA
#define ReadConsole ReadConsoleA
#define WriteConsole WriteConsoleA
#define AddConsoleAlias AddConsoleAliasA
#define GetConsoleAlias GetConsoleAliasA
#define Get_Console_Aliases_দৈর্ঘ্য Get_Console_Aliases_দৈর্ঘ্য_A
#define Get_Console_Alias_Exes_দৈর্ঘ্য Get_Console_Alias_Exes_দৈর্ঘ্য_A
#define GetConsoleAliases GetConsoleAliasesA
#define GetConsoleAliasExes GetConsoleAliasExesA
#endif

  WINBASEAPI WINBOOL WINAPI Peek_Console_প্রবেশ_A(HANDLE h_Console_প্রবেশ,PINPUT_RECORD lp_বাফার,DWORD n_দৈর্ঘ্য,LPDWORD lp_সংখ্যা_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_প্রবেশ_W(HANDLE h_Console_প্রবেশ,PINPUT_RECORD lp_বাফার,DWORD n_দৈর্ঘ্য,LPDWORD lp_সংখ্যা_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_প্রবেশ_A(HANDLE h_Console_প্রবেশ,PINPUT_RECORD lp_বাফার,DWORD n_দৈর্ঘ্য,LPDWORD lp_সংখ্যা_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_প্রবেশ_W(HANDLE h_Console_প্রবেশ,PINPUT_RECORD lp_বাফার,DWORD n_দৈর্ঘ্য,LPDWORD lp_সংখ্যা_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_প্রবেশ_A(HANDLE h_Console_প্রবেশ,CONST প্রবেশ_RECORD_2 *lp_বাফার,DWORD n_দৈর্ঘ্য,LPDWORD lp_সংখ্যা_Of_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_প্রবেশ_W(HANDLE h_Console_প্রবেশ,CONST প্রবেশ_RECORD_2 *lp_বাফার,DWORD n_দৈর্ঘ্য,LPDWORD lp_সংখ্যা_Of_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_বাফার,COORD dw_বাফার_আকার,COORD dw_বাফার_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_বাফার,COORD dw_বাফার_আকার,COORD dw_বাফার_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_বাফার,COORD dw_বাফার_আকার,COORD dw_বাফার_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_বাফার,COORD dw_বাফার_আকার,COORD dw_বাফার_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_দৈর্ঘ্য,COORD dwReadCoord,LPDWORD lp_সংখ্যা_Of_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_দৈর্ঘ্য,COORD dwReadCoord,LPDWORD lp_সংখ্যা_Of_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_দৈর্ঘ্য,COORD dwReadCoord,LPDWORD lp_সংখ্যা_Of_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_দৈর্ঘ্য,COORD dwWriteCoord,LPDWORD lp_সংখ্যা_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_দৈর্ঘ্য,COORD dwWriteCoord,LPDWORD lp_সংখ্যা_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST WORD *lpAttribute,DWORD n_দৈর্ঘ্য,COORD dwWriteCoord,LPDWORD lp_সংখ্যা_Of_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_দৈর্ঘ্য,COORD dwWriteCoord,LPDWORD lp_সংখ্যা_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_দৈর্ঘ্য,COORD dwWriteCoord,LPDWORD lp_সংখ্যা_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,WORD wAttribute,DWORD n_দৈর্ঘ্য,COORD dwWriteCoord,LPDWORD lp_সংখ্যা_Of_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI GetConsoleMode(HANDLE hConsoleHandle,LPDWORD lpMode);
  WINBASEAPI WINBOOL WINAPI Get_সংখ্যা_Of_Console_প্রবেশ_Events(HANDLE h_Console_প্রবেশ,LPDWORD lp_সংখ্যা_Of_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_বাফার_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_বাফার_INFO lp_Console_Screen_বাফার_Info);
  WINBASEAPI COORD WINAPI Get_Largest_Console_Window_আকার(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL bMaximumWindow,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_আকার(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_সংখ্যা_Of_Console_Mouse_Buttons(LPDWORD lp_সংখ্যা_Of_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI SetConsoleMode(HANDLE hConsoleHandle,DWORD dwMode);
  WINBASEAPI WINBOOL WINAPI Set_Console_Active_Screen_বাফার(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_প্রবেশ_বাফার(HANDLE h_Console_প্রবেশ);
  WINBASEAPI WINBOOL WINAPI Set_Console_Screen_বাফার_আকার(HANDLE hConsoleOutput,COORD dw_আকার);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorPosition(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorInfo(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_বাফার_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_বাফার_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI SetConsoleWindowInfo(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lpConsoleWindow);
  WINBASEAPI WINBOOL WINAPI SetConsoleTextAttribute(HANDLE hConsoleOutput,WORD wAttributes);
  WINBASEAPI WINBOOL WINAPI SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL Add);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dwProcessGroupId);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#define ATTACH_PARENT_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_আকার);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_আকার);
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleA(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleW(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_প্রবেশ,LPVOID lp_বাফার,DWORD n_সংখ্যা_Of_Chars_To_Read,LPDWORD lp_সংখ্যা_Of_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_প্রবেশ,LPVOID lp_বাফার,DWORD n_সংখ্যা_Of_Chars_To_Read,LPDWORD lp_সংখ্যা_Of_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_বাফার,DWORD n_সংখ্যা_Of_Chars_To_Write,LPDWORD lp_সংখ্যা_Of_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_বাফার,DWORD n_সংখ্যা_Of_Chars_To_Write,LPDWORD lp_সংখ্যা_Of_Chars_Written,LPVOID lpReserved);

#define CONSOLE_TEXTMODE_বাফার 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_বাফার(DWORD dwDesiredAccess,DWORD dwShareMode,CONST SECURITY_ATTRIBUTES *lpSecurityAttributes,DWORD dwFlags,LPVOID lp_Screen_বাফার_তথ্য);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI SetConsoleCP(UINT wCodePageID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI SetConsoleOutputCP(UINT wCodePageID);

#define CONSOLE_FULLSCREEN 1
#define CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI GetConsoleDisplayMode(LPDWORD lpModeFlags);
  WINBASEAPI HWND WINAPI GetConsoleWindow(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_গুনতি);
  WINBASEAPI WINBOOL WINAPI AddConsoleAliasA(LPSTR Source,LPSTR Target,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI AddConsoleAliasW(LPWSTR Source,LPWSTR Target,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR Source,LPSTR Target_বাফার,DWORD Target_বাফার_দৈর্ঘ্য,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR Source,LPWSTR Target_বাফার,DWORD Target_বাফার_দৈর্ঘ্য,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_দৈর্ঘ্য_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_দৈর্ঘ্য_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_দৈর্ঘ্য_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_দৈর্ঘ্য_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_বাফার,DWORD Alias_বাফার_দৈর্ঘ্য,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_বাফার,DWORD Alias_বাফার_দৈর্ঘ্য,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_বাফার,DWORD Exe_Name_বাফার_দৈর্ঘ্য);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_বাফার,DWORD Exe_Name_বাফার_দৈর্ঘ্য);

#ifdef __cplusplus
}
#endif
#endif
