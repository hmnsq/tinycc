/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINCON_
#ವ್ಯಾಖ್ಯಾನಿಸು _WINCON_

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _SMALL_RECT {
    SHORT ಎಡ_2;
    SHORT ತುದಿ_2;
    SHORT ಬಲ_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಕೀಲಿ_EVENT_ದಾಖಲೆ {
    WINBOOL b_ಕೀಲಿ_ಕೆಳಕ್ಕೆ;
    ಶಬ್ದ_3 w_Repeat_ಎಣಿಕೆ;
    ಶಬ್ದ_3 w_Virtual_ಕೀಲಿ_ಸಂಕೇತ;
    ಶಬ್ದ_3 w_Virtual_ಪರಿಶೀಲನೆ_ಸಂಕೇತ;
    ಒಕ್ಕೂಟ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_ಕೀಲಿ_State;
  } ಕೀಲಿ_EVENT_ದಾಖಲೆ_2,*PKEY_EVENT_ದಾಖಲೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು ಬಲ_ALT_PRESSED 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ಎಡ_ALT_PRESSED 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ಬಲ_CTRL_PRESSED 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು ಎಡ_CTRL_PRESSED 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು ಸರಿಸು_PRESSED 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು NUMLOCK_ON 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು SCROLLLOCK_ON 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು CAPSLOCK_ON 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು ENHANCED_ಕೀಲಿ 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು NLS_DBCSCHAR 0x10000
#ವ್ಯಾಖ್ಯಾನಿಸು NLS_ALPHANUMERIC 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು NLS_KATAKANA 0x20000
#ವ್ಯಾಖ್ಯಾನಿಸು NLS_HIRAGANA 0x40000
#ವ್ಯಾಖ್ಯಾನಿಸು NLS_ROMAN 0x400000
#ವ್ಯಾಖ್ಯಾನಿಸು NLS_IME_CONVERSION 0x800000
#ವ್ಯಾಖ್ಯಾನಿಸು NLS_IME_DISABLE 0x20000000

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ MOUSE_EVENT_ದಾಖಲೆ {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_ಕೀಲಿ_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_ದಾಖಲೆ_2,*PMOUSE_EVENT_ದಾಖಲೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು FROM_ಎಡ_1_ST_BUTTON_PRESSED 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು RIGHTMOST_BUTTON_PRESSED 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು FROM_ಎಡ_2_ND_BUTTON_PRESSED 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು FROM_ಎಡ_3_RD_BUTTON_PRESSED 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು FROM_ಎಡ_4_TH_BUTTON_PRESSED 0x10

#ವ್ಯಾಖ್ಯಾನಿಸು MOUSE_MOVED 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು DOUBLE_CLICK 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSE_WHEELED 0x4

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಕಿಟಕಿ_ಬಫರ್_ಗಾತ್ರ_ದಾಖಲೆ {
    COORD dw_ಗಾತ್ರ;
  } ಕಿಟಕಿ_ಬಫರ್_ಗಾತ್ರ_ದಾಖಲೆ_2,*PWINDOW_ಬಫರ್_ಗಾತ್ರ_ದಾಖಲೆ;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ MENU_EVENT_ದಾಖಲೆ {
    UINT dwCommandId;
  } MENU_EVENT_ದಾಖಲೆ_2,*PMENU_EVENT_ದಾಖಲೆ;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ FOCUS_EVENT_ದಾಖಲೆ {
    WINBOOL b_ಗಣ_Focus;
  } FOCUS_EVENT_ದಾಖಲೆ_2,*PFOCUS_EVENT_ದಾಖಲೆ;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಒಳಹರಿವು_ದಾಖಲೆ {
    ಶಬ್ದ_3 EventType;
    ಒಕ್ಕೂಟ {
      ಕೀಲಿ_EVENT_ದಾಖಲೆ_2 ಕೀಲಿ_Event;
      MOUSE_EVENT_ದಾಖಲೆ_2 MouseEvent;
      ಕಿಟಕಿ_ಬಫರ್_ಗಾತ್ರ_ದಾಖಲೆ_2 ಕಿಟಕಿ_ಬಫರ್_ಗಾತ್ರ_Event;
      MENU_EVENT_ದಾಖಲೆ_2 MenuEvent;
      FOCUS_EVENT_ದಾಖಲೆ_2 FocusEvent;
    } Event;
  } ಒಳಹರಿವು_ದಾಖಲೆ_2,*PINPUT_ದಾಖಲೆ;

#ವ್ಯಾಖ್ಯಾನಿಸು ಕೀಲಿ_EVENT 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSE_EVENT 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಿಟಕಿ_ಬಫರ್_ಗಾತ್ರ_EVENT 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು MENU_EVENT 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು FOCUS_EVENT 0x10

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CHAR_INFO {
    ಒಕ್ಕೂಟ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    ಶಬ್ದ_3 ಗುಣಲಕ್ಷಣಗಳು;
  } CHAR_INFO,*PCHAR_INFO;

#ವ್ಯಾಖ್ಯಾನಿಸು FOREGROUND_BLUE 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು FOREGROUND_GREEN 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು FOREGROUND_RED 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು FOREGROUND_INTENSITY 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು BACKGROUND_BLUE 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು BACKGROUND_GREEN 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು BACKGROUND_RED 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು BACKGROUND_INTENSITY 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು COMMON_LVB_LEADING_BYTE 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು COMMON_LVB_TRAILING_BYTE 0x200
#ವ್ಯಾಖ್ಯಾನಿಸು COMMON_LVB_GRID_HORIZONTAL 0x400
#ವ್ಯಾಖ್ಯಾನಿಸು COMMON_LVB_GRID_LVERTICAL 0x800
#ವ್ಯಾಖ್ಯಾನಿಸು COMMON_LVB_GRID_RVERTICAL 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು COMMON_LVB_ಹಿಮ್ಮುಖ_VIDEO 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು COMMON_LVB_UNDERSCORE 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು COMMON_LVB_SBCSDBCS 0x300

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ CONSOLE_SCREEN_ಬಫರ್_INFO {
    COORD dw_ಗಾತ್ರ;
    COORD dwCursorPosition;
    ಶಬ್ದ_3 w_ಗುಣಲಕ್ಷಣಗಳು;
    SMALL_RECT sr_ಕಿಟಕಿ;
    COORD dw_ಗರಿಷ್ಠ_ಕಿಟಕಿ_ಗಾತ್ರ;
  } CONSOLE_SCREEN_ಬಫರ್_INFO_2,*PCONSOLE_SCREEN_ಬಫರ್_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CONSOLE_CURSOR_INFO {
    DWORD dw_ಗಾತ್ರ;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dw_Font_ಗಾತ್ರ;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_NO_SELECTION 0x0
#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_SELECTION_ಒಳ_ಪ್ರಗತಿ 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_SELECTION_NOT_ಖಾಲಿಗಳು 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_MOUSE_SELECTION 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_MOUSE_ಕೆಳಕ್ಕೆ 0x8

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#ವ್ಯಾಖ್ಯಾನಿಸು CTRL_C_EVENT 0
#ವ್ಯಾಖ್ಯಾನಿಸು CTRL_BREAK_EVENT 1
#ವ್ಯಾಖ್ಯಾನಿಸು CTRL_CLOSE_EVENT 2

#ವ್ಯಾಖ್ಯಾನಿಸು CTRL_LOGOFF_EVENT 5
#ವ್ಯಾಖ್ಯಾನಿಸು CTRL_SHUTDOWN_EVENT 6

#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_PROCESSED_ಒಳಹರಿವು 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_ಸಾಲು_ಒಳಹರಿವು 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_ECHO_ಒಳಹರಿವು 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_ಕಿಟಕಿ_ಒಳಹರಿವು 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_MOUSE_ಒಳಹರಿವು 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_ಸೇರಿಸು_ಬಹುಲಕ 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_ಶೀಘ್ರ_EDIT_ಬಹುಲಕ 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_EXTENDED_FLAGS 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_AUTO_POSITION 0x100
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_VIRTUAL_TERMINAL_ಒಳಹರಿವು 0x200

#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_PROCESSED_OUTPUT 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು DISABLE_NEWLINE_AUTO_RETURN 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLE_LVB_GRID_WORLDWIDE 0x10

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Peek_Console_ಒಳಹರಿವು Peek_Console_ಒಳಹರಿವು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Read_Console_ಒಳಹರಿವು Read_Console_ಒಳಹರಿವು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Write_Console_ಒಳಹರಿವು Write_Console_ಒಳಹರಿವು_W
#ವ್ಯಾಖ್ಯಾನಿಸು ReadConsoleOutput ReadConsoleOutputW
#ವ್ಯಾಖ್ಯಾನಿಸು WriteConsoleOutput WriteConsoleOutputW
#ವ್ಯಾಖ್ಯಾನಿಸು ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#ವ್ಯಾಖ್ಯಾನಿಸು WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#ವ್ಯಾಖ್ಯಾನಿಸು FillConsoleOutputCharacter FillConsoleOutputCharacterW
#ವ್ಯಾಖ್ಯಾನಿಸು Scroll_Console_Screen_ಬಫರ್ Scroll_Console_Screen_ಬಫರ್_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetConsoleTitle GetConsoleTitleW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Console_Title ಗಣ_Console_Title_W
#ವ್ಯಾಖ್ಯಾನಿಸು ReadConsole ReadConsoleW
#ವ್ಯಾಖ್ಯಾನಿಸು WriteConsole WriteConsoleW
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Console_Alias ಕೂಡಿಸು_Console_Alias_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetConsoleAlias GetConsoleAliasW
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Console_Aliases_ಉದ್ದಳತೆ Get_Console_Aliases_ಉದ್ದಳತೆ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Console_Alias_Exes_ಉದ್ದಳತೆ Get_Console_Alias_Exes_ಉದ್ದಳತೆ_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetConsoleAliases GetConsoleAliasesW
#ವ್ಯಾಖ್ಯಾನಿಸು GetConsoleAliasExes GetConsoleAliasExesW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Peek_Console_ಒಳಹರಿವು Peek_Console_ಒಳಹರಿವು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Read_Console_ಒಳಹರಿವು Read_Console_ಒಳಹರಿವು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Write_Console_ಒಳಹರಿವು Write_Console_ಒಳಹರಿವು_A
#ವ್ಯಾಖ್ಯಾನಿಸು ReadConsoleOutput ReadConsoleOutputA
#ವ್ಯಾಖ್ಯಾನಿಸು WriteConsoleOutput WriteConsoleOutputA
#ವ್ಯಾಖ್ಯಾನಿಸು ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#ವ್ಯಾಖ್ಯಾನಿಸು WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#ವ್ಯಾಖ್ಯಾನಿಸು FillConsoleOutputCharacter FillConsoleOutputCharacterA
#ವ್ಯಾಖ್ಯಾನಿಸು Scroll_Console_Screen_ಬಫರ್ Scroll_Console_Screen_ಬಫರ್_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetConsoleTitle GetConsoleTitleA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Console_Title ಗಣ_Console_Title_A
#ವ್ಯಾಖ್ಯಾನಿಸು ReadConsole ReadConsoleA
#ವ್ಯಾಖ್ಯಾನಿಸು WriteConsole WriteConsoleA
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Console_Alias ಕೂಡಿಸು_Console_Alias_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetConsoleAlias GetConsoleAliasA
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Console_Aliases_ಉದ್ದಳತೆ Get_Console_Aliases_ಉದ್ದಳತೆ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Console_Alias_Exes_ಉದ್ದಳತೆ Get_Console_Alias_Exes_ಉದ್ದಳತೆ_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetConsoleAliases GetConsoleAliasesA
#ವ್ಯಾಖ್ಯಾನಿಸು GetConsoleAliasExes GetConsoleAliasExesA
#ಆದರೆ_ಅಂತ್ಯ

  WINBASEAPI WINBOOL WINAPI Peek_Console_ಒಳಹರಿವು_A(HANDLE h_Console_ಒಳಹರಿವು,PINPUT_ದಾಖಲೆ lp_ಬಫರ್,DWORD n_ಉದ್ದಳತೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_ಒಳಹರಿವು_W(HANDLE h_Console_ಒಳಹರಿವು,PINPUT_ದಾಖಲೆ lp_ಬಫರ್,DWORD n_ಉದ್ದಳತೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_ಒಳಹರಿವು_A(HANDLE h_Console_ಒಳಹರಿವು,PINPUT_ದಾಖಲೆ lp_ಬಫರ್,DWORD n_ಉದ್ದಳತೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_ಒಳಹರಿವು_W(HANDLE h_Console_ಒಳಹರಿವು,PINPUT_ದಾಖಲೆ lp_ಬಫರ್,DWORD n_ಉದ್ದಳತೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_ಒಳಹರಿವು_A(HANDLE h_Console_ಒಳಹರಿವು,CONST ಒಳಹರಿವು_ದಾಖಲೆ_2 *lp_ಬಫರ್,DWORD n_ಉದ್ದಳತೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_ಒಳಹರಿವು_W(HANDLE h_Console_ಒಳಹರಿವು,CONST ಒಳಹರಿವು_ದಾಖಲೆ_2 *lp_ಬಫರ್,DWORD n_ಉದ್ದಳತೆ,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_ಬಫರ್,COORD dw_ಬಫರ್_ಗಾತ್ರ,COORD dw_ಬಫರ್_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_ಬಫರ್,COORD dw_ಬಫರ್_ಗಾತ್ರ,COORD dw_ಬಫರ್_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_ಬಫರ್,COORD dw_ಬಫರ್_ಗಾತ್ರ,COORD dw_ಬಫರ್_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_ಬಫರ್,COORD dw_ಬಫರ್_ಗಾತ್ರ,COORD dw_ಬಫರ್_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_ಉದ್ದಳತೆ,COORD dwReadCoord,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_ಉದ್ದಳತೆ,COORD dwReadCoord,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_ಉದ್ದಳತೆ,COORD dwReadCoord,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_ಉದ್ದಳತೆ,COORD dwWriteCoord,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_ಉದ್ದಳತೆ,COORD dwWriteCoord,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST ಶಬ್ದ_3 *lpAttribute,DWORD n_ಉದ್ದಳತೆ,COORD dwWriteCoord,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_ಉದ್ದಳತೆ,COORD dwWriteCoord,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_ಉದ್ದಳತೆ,COORD dwWriteCoord,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,ಶಬ್ದ_3 wAttribute,DWORD n_ಉದ್ದಳತೆ,COORD dwWriteCoord,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI Get_Console_ಬಹುಲಕ(HANDLE hConsoleHandle,LPDWORD lp_ಬಹುಲಕ);
  WINBASEAPI WINBOOL WINAPI Get_ಸಂಖ್ಯೆ_ದ_Console_ಒಳಹರಿವು_Events(HANDLE h_Console_ಒಳಹರಿವು,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_ಬಫರ್_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_ಬಫರ್_INFO lp_Console_Screen_ಬಫರ್_Info);
  WINBASEAPI COORD WINAPI Get_ಅತಿದೊಡ್ಡ_Console_ಕಿಟಕಿ_ಗಾತ್ರ(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL b_ಗರಿಷ್ಠ_ಕಿಟಕಿ,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_ಗಾತ್ರ(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_ಸಂಖ್ಯೆ_ದ_Console_Mouse_Buttons(LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_ಬಹುಲಕ(HANDLE hConsoleHandle,DWORD dw_ಬಹುಲಕ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_ಸಕ್ರಿಯ_Screen_ಬಫರ್(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_ಒಳಹರಿವು_ಬಫರ್(HANDLE h_Console_ಒಳಹರಿವು);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_Screen_ಬಫರ್_ಗಾತ್ರ(HANDLE hConsoleOutput,COORD dw_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_Cursor_Position(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_Cursor_Info(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_ಬಫರ್_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_ಬಫರ್_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_ಕಿಟಕಿ_Info(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lp_Console_ಕಿಟಕಿ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_ಪಠ್ಯ_Attribute(HANDLE hConsoleOutput,ಶಬ್ದ_3 w_ಗುಣಲಕ್ಷಣಗಳು);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_Ctrl_Handler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL ಕೂಡಿಸು_3);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dw_Process_ಗುಂಪು_Id);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#ವ್ಯಾಖ್ಯಾನಿಸು ATTACH_ಪೋಷಕ_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_ಗಾತ್ರ);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_ಗಾತ್ರ);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_Title_A(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_Title_W(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_ಒಳಹರಿವು,LPVOID lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_Chars_ಗಮ್ಯ_Read,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_ಒಳಹರಿವು,LPVOID lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_Chars_ಗಮ್ಯ_Read,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_Chars_ಗಮ್ಯ_Write,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_ಬಫರ್,DWORD n_ಸಂಖ್ಯೆ_ದ_Chars_ಗಮ್ಯ_Write,LPDWORD lp_ಸಂಖ್ಯೆ_ದ_Chars_Written,LPVOID lpReserved);

#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_TEXTMODE_ಬಫರ್ 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_ಬಫರ್(DWORD dwDesiredAccess,DWORD dw_Share_ಬಹುಲಕ,CONST SECURITY_ಗುಣಲಕ್ಷಣಗಳು_2 *lp_Security_ಗುಣಲಕ್ಷಣಗಳು,DWORD dwFlags,LPVOID lp_Screen_ಬಫರ್_ದತ್ತಾಂಶ);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_CP(UINT w_ಸಂಕೇತ_ಪುಟ_ID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI ಗಣ_Console_Output_CP(UINT w_ಸಂಕೇತ_ಪುಟ_ID);

#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_FULLSCREEN 1
#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI Get_Console_Display_ಬಹುಲಕ(LPDWORD lp_ಬಹುಲಕ_Flags);
  WINBASEAPI HWND WINAPI Get_Console_ಕಿಟಕಿ(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_ಎಣಿಕೆ);
  WINBASEAPI WINBOOL WINAPI ಕೂಡಿಸು_Console_Alias_A(LPSTR ಮೂಲ_2,LPSTR ಗುರಿ_2,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI ಕೂಡಿಸು_Console_Alias_W(LPWSTR ಮೂಲ_2,LPWSTR ಗುರಿ_2,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR ಮೂಲ_2,LPSTR ಗುರಿ_ಬಫರ್,DWORD ಗುರಿ_ಬಫರ್_ಉದ್ದಳತೆ,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR ಮೂಲ_2,LPWSTR ಗುರಿ_ಬಫರ್,DWORD ಗುರಿ_ಬಫರ್_ಉದ್ದಳತೆ,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_ಉದ್ದಳತೆ_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_ಉದ್ದಳತೆ_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_ಉದ್ದಳತೆ_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_ಉದ್ದಳತೆ_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_ಬಫರ್,DWORD Alias_ಬಫರ್_ಉದ್ದಳತೆ,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_ಬಫರ್,DWORD Alias_ಬಫರ್_ಉದ್ದಳತೆ,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_ಬಫರ್,DWORD Exe_Name_ಬಫರ್_ಉದ್ದಳತೆ);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_ಬಫರ್,DWORD Exe_Name_ಬಫರ್_ಉದ್ದಳತೆ);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
