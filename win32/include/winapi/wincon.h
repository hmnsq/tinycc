/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINCON_
#define _WINCON_

#ifdef __cplusplus
خارجي "C" {
#endif

  تعريفنوع بنية _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  تعريفنوع بنية _SMALL_RECT {
    SHORT سول_2;
    SHORT چوققا_2;
    SHORT ئوڭ_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  تعريفنوع بنية ئاچقۇچ_EVENT_RECORD {
    WINBOOL b_ئاچقۇچ_Down;
    WORD w_Repeat_سانى;
    WORD w_Virtual_ئاچقۇچ_Code;
    WORD wVirtualScanCode;
    اتحاد {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_ئاچقۇچ_State;
  } ئاچقۇچ_EVENT_RECORD_2,*PKEY_EVENT_RECORD;

#define ئوڭ_ALT_PRESSED 0x1
#define سول_ALT_PRESSED 0x2
#define ئوڭ_CTRL_PRESSED 0x4
#define سول_CTRL_PRESSED 0x8
#define SHIFT_PRESSED 0x10
#define NUMLOCK_ON 0x20
#define SCROLLLOCK_ON 0x40
#define CAPSLOCK_ON 0x80
#define ENHANCED_ئاچقۇچ 0x100
#define NLS_DBCSCHAR 0x10000
#define NLS_ALPHANUMERIC 0x0
#define NLS_KATAKANA 0x20000
#define NLS_HIRAGANA 0x40000
#define NLS_ROMAN 0x400000
#define NLS_IME_CONVERSION 0x800000
#define NLS_IME_DISABLE 0x20000000

  تعريفنوع بنية _MOUSE_EVENT_RECORD {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_ئاچقۇچ_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_RECORD,*PMOUSE_EVENT_RECORD;

#define FROM_سول_1_ST_BUTTON_PRESSED 0x1
#define RIGHTMOST_BUTTON_PRESSED 0x2
#define FROM_سول_2_ND_BUTTON_PRESSED 0x4
#define FROM_سول_3_RD_BUTTON_PRESSED 0x8
#define FROM_سول_4_TH_BUTTON_PRESSED 0x10

#define MOUSE_MOVED 0x1
#define DOUBLE_CLICK 0x2
#define MOUSE_WHEELED 0x4

  تعريفنوع بنية _WINDOW_BUFFER_SIZE_RECORD {
    COORD dwSize;
  } WINDOW_BUFFER_SIZE_RECORD,*PWINDOW_BUFFER_SIZE_RECORD;

  تعريفنوع بنية _MENU_EVENT_RECORD {
    UINT dwCommandId;
  } MENU_EVENT_RECORD,*PMENU_EVENT_RECORD;

  تعريفنوع بنية _FOCUS_EVENT_RECORD {
    WINBOOL bSetFocus;
  } FOCUS_EVENT_RECORD,*PFOCUS_EVENT_RECORD;

  تعريفنوع بنية كىرگۈزۈش_RECORD {
    WORD EventType;
    اتحاد {
      ئاچقۇچ_EVENT_RECORD_2 ئاچقۇچ_Event;
      MOUSE_EVENT_RECORD MouseEvent;
      WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
      MENU_EVENT_RECORD MenuEvent;
      FOCUS_EVENT_RECORD FocusEvent;
    } Event;
  } كىرگۈزۈش_RECORD_2,*PINPUT_RECORD;

#define ئاچقۇچ_EVENT 0x1
#define MOUSE_EVENT 0x2
#define WINDOW_BUFFER_SIZE_EVENT 0x4
#define MENU_EVENT 0x8
#define FOCUS_EVENT 0x10

  تعريفنوع بنية _CHAR_INFO {
    اتحاد {
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

  تعريفنوع بنية _CONSOLE_SCREEN_BUFFER_INFO {
    COORD dwSize;
    COORD dwCursorPosition;
    WORD wAttributes;
    SMALL_RECT srWindow;
    COORD dwMaximumWindowSize;
  } CONSOLE_SCREEN_BUFFER_INFO,*PCONSOLE_SCREEN_BUFFER_INFO;

  تعريفنوع بنية _CONSOLE_CURSOR_INFO {
    DWORD dwSize;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  تعريفنوع بنية _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dwFontSize;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  تعريفنوع بنية _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#define CONSOLE_NO_SELECTION 0x0
#define CONSOLE_SELECTION_IN_PROGRESS 0x1
#define CONSOLE_SELECTION_NOT_EMPTY 0x2
#define CONSOLE_MOUSE_SELECTION 0x4
#define CONSOLE_MOUSE_DOWN 0x8

  تعريفنوع WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#define CTRL_C_EVENT 0
#define CTRL_BREAK_EVENT 1
#define CTRL_CLOSE_EVENT 2

#define CTRL_LOGOFF_EVENT 5
#define CTRL_SHUTDOWN_EVENT 6

#define ENABLE_PROCESSED_كىرگۈزۈش 0x1
#define ENABLE_قۇر_كىرگۈزۈش 0x2
#define ENABLE_ECHO_كىرگۈزۈش 0x4
#define ENABLE_WINDOW_كىرگۈزۈش 0x8
#define ENABLE_MOUSE_كىرگۈزۈش 0x10
#define ENABLE_قىستۇرۇش_MODE 0x20
#define ENABLE_QUICK_EDIT_MODE 0x40
#define ENABLE_EXTENDED_FLAGS 0x80
#define ENABLE_AUTO_POSITION 0x100
#define ENABLE_VIRTUAL_TERMINAL_كىرگۈزۈش 0x200

#define ENABLE_PROCESSED_OUTPUT 0x1
#define ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#define DISABLE_NEWLINE_AUTO_RETURN 0x8
#define ENABLE_LVB_GRID_WORLDWIDE 0x10

#ifdef UNICODE
#define Peek_Console_كىرگۈزۈش Peek_Console_كىرگۈزۈش_W
#define Read_Console_كىرگۈزۈش Read_Console_كىرگۈزۈش_W
#define Write_Console_كىرگۈزۈش Write_Console_كىرگۈزۈش_W
#define ReadConsoleOutput ReadConsoleOutputW
#define WriteConsoleOutput WriteConsoleOutputW
#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#define FillConsoleOutputCharacter FillConsoleOutputCharacterW
#define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferW
#define GetConsoleTitle GetConsoleTitleW
#define SetConsoleTitle SetConsoleTitleW
#define ReadConsole ReadConsoleW
#define WriteConsole WriteConsoleW
#define AddConsoleAlias AddConsoleAliasW
#define GetConsoleAlias GetConsoleAliasW
#define GetConsoleAliasesLength GetConsoleAliasesLengthW
#define GetConsoleAliasExesLength GetConsoleAliasExesLengthW
#define GetConsoleAliases GetConsoleAliasesW
#define GetConsoleAliasExes GetConsoleAliasExesW
#وإلا
#define Peek_Console_كىرگۈزۈش Peek_Console_كىرگۈزۈش_A
#define Read_Console_كىرگۈزۈش Read_Console_كىرگۈزۈش_A
#define Write_Console_كىرگۈزۈش Write_Console_كىرگۈزۈش_A
#define ReadConsoleOutput ReadConsoleOutputA
#define WriteConsoleOutput WriteConsoleOutputA
#define ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#define WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#define FillConsoleOutputCharacter FillConsoleOutputCharacterA
#define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferA
#define GetConsoleTitle GetConsoleTitleA
#define SetConsoleTitle SetConsoleTitleA
#define ReadConsole ReadConsoleA
#define WriteConsole WriteConsoleA
#define AddConsoleAlias AddConsoleAliasA
#define GetConsoleAlias GetConsoleAliasA
#define GetConsoleAliasesLength GetConsoleAliasesLengthA
#define GetConsoleAliasExesLength GetConsoleAliasExesLengthA
#define GetConsoleAliases GetConsoleAliasesA
#define GetConsoleAliasExes GetConsoleAliasExesA
#endif

  WINBASEAPI WINBOOL WINAPI Peek_Console_كىرگۈزۈش_A(HANDLE h_Console_كىرگۈزۈش,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lp_سان_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_كىرگۈزۈش_W(HANDLE h_Console_كىرگۈزۈش,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lp_سان_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_كىرگۈزۈش_A(HANDLE h_Console_كىرگۈزۈش,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lp_سان_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_كىرگۈزۈش_W(HANDLE h_Console_كىرگۈزۈش,PINPUT_RECORD lpBuffer,DWORD nLength,LPDWORD lp_سان_Of_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_كىرگۈزۈش_A(HANDLE h_Console_كىرگۈزۈش,CONST كىرگۈزۈش_RECORD_2 *lpBuffer,DWORD nLength,LPDWORD lp_سان_Of_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_كىرگۈزۈش_W(HANDLE h_Console_كىرگۈزۈش,CONST كىرگۈزۈش_RECORD_2 *lpBuffer,DWORD nLength,LPDWORD lp_سان_Of_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lpBuffer,COORD dwBufferSize,COORD dwBufferCoord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD nLength,COORD dwReadCoord,LPDWORD lp_سان_Of_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD nLength,COORD dwReadCoord,LPDWORD lp_سان_Of_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD nLength,COORD dwReadCoord,LPDWORD lp_سان_Of_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lp_سان_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lp_سان_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST WORD *lpAttribute,DWORD nLength,COORD dwWriteCoord,LPDWORD lp_سان_Of_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lp_سان_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD nLength,COORD dwWriteCoord,LPDWORD lp_سان_Of_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,WORD wAttribute,DWORD nLength,COORD dwWriteCoord,LPDWORD lp_سان_Of_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI GetConsoleMode(HANDLE hConsoleHandle,LPDWORD lpMode);
  WINBASEAPI WINBOOL WINAPI Get_سان_Of_Console_كىرگۈزۈش_Events(HANDLE h_Console_كىرگۈزۈش,LPDWORD lp_سان_Of_Events);
  WINBASEAPI WINBOOL WINAPI GetConsoleScreenBufferInfo(HANDLE hConsoleOutput,PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo);
  WINBASEAPI COORD WINAPI GetLargestConsoleWindowSize(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL bMaximumWindow,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI GetConsoleFontSize(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_سان_Of_Console_Mouse_Buttons(LPDWORD lp_سان_Of_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI SetConsoleMode(HANDLE hConsoleHandle,DWORD dwMode);
  WINBASEAPI WINBOOL WINAPI SetConsoleActiveScreenBuffer(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_كىرگۈزۈش_Buffer(HANDLE h_Console_كىرگۈزۈش);
  WINBASEAPI WINBOOL WINAPI SetConsoleScreenBufferSize(HANDLE hConsoleOutput,COORD dwSize);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorPosition(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI SetConsoleCursorInfo(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI ScrollConsoleScreenBufferA(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI ScrollConsoleScreenBufferW(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI SetConsoleWindowInfo(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lpConsoleWindow);
  WINBASEAPI WINBOOL WINAPI SetConsoleTextAttribute(HANDLE hConsoleOutput,WORD wAttributes);
  WINBASEAPI WINBOOL WINAPI SetConsoleCtrlHandler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL Add);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dwProcessGroupId);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#define ATTACH_PARENT_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD nSize);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD nSize);
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleA(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI SetConsoleTitleW(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_كىرگۈزۈش,LPVOID lpBuffer,DWORD n_سان_Of_Chars_To_Read,LPDWORD lp_سان_Of_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_كىرگۈزۈش,LPVOID lpBuffer,DWORD n_سان_Of_Chars_To_Read,LPDWORD lp_سان_Of_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lpBuffer,DWORD n_سان_Of_Chars_To_Write,LPDWORD lp_سان_Of_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lpBuffer,DWORD n_سان_Of_Chars_To_Write,LPDWORD lp_سان_Of_Chars_Written,LPVOID lpReserved);

#define CONSOLE_TEXTMODE_BUFFER 1

  WINBASEAPI HANDLE WINAPI CreateConsoleScreenBuffer(DWORD dwDesiredAccess,DWORD dwShareMode,CONST SECURITY_ATTRIBUTES *lpSecurityAttributes,DWORD dwFlags,LPVOID lpScreenBufferData);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI SetConsoleCP(UINT wCodePageID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI SetConsoleOutputCP(UINT wCodePageID);

#define CONSOLE_FULLSCREEN 1
#define CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI GetConsoleDisplayMode(LPDWORD lpModeFlags);
  WINBASEAPI HWND WINAPI GetConsoleWindow(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_سانى);
  WINBASEAPI WINBOOL WINAPI AddConsoleAliasA(LPSTR Source,LPSTR Target,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI AddConsoleAliasW(LPWSTR Source,LPWSTR Target,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR Source,LPSTR TargetBuffer,DWORD TargetBufferLength,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR Source,LPWSTR TargetBuffer,DWORD TargetBufferLength,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesLengthA(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesLengthW(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesLengthA(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesLengthW(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR AliasBuffer,DWORD AliasBufferLength,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR AliasBuffer,DWORD AliasBufferLength,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR ExeNameBuffer,DWORD ExeNameBufferLength);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR ExeNameBuffer,DWORD ExeNameBufferLength);

#ifdef __cplusplus
}
#endif
#endif
