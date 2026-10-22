/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINCON_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINCON_

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _COORD {
    SHORT X;
    SHORT Y;
  } COORD,*PCOORD;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _SMALL_RECT {
    SHORT ਖੱਬਾ_2;
    SHORT ਸਿਖਰ_2;
    SHORT ਸੱਜਾ_2;
    SHORT Bottom;
  } SMALL_RECT,*PSMALL_RECT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਕੁੰਜੀ_EVENT_ਰਿਕਾਰਡ {
    WINBOOL b_ਕੁੰਜੀ_ਥੱਲੇ;
    ਸ਼ਬਦ_3 w_Repeat_ਗਿਣਤੀ;
    ਸ਼ਬਦ_3 w_Virtual_ਕੁੰਜੀ_ਕੋਡ;
    ਸ਼ਬਦ_3 w_Virtual_ਜਾਂਚ_ਕੋਡ;
    ਸੰਘ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } uChar;
    DWORD dw_Control_ਕੁੰਜੀ_State;
  } ਕੁੰਜੀ_EVENT_ਰਿਕਾਰਡ_2,*PKEY_EVENT_ਰਿਕਾਰਡ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੱਜਾ_ALT_PRESSED 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖੱਬਾ_ALT_PRESSED 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੱਜਾ_CTRL_PRESSED 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖੱਬਾ_CTRL_PRESSED 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖਿਸਕਾਓ_PRESSED 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NUMLOCK_ON 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCROLLLOCK_ON 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CAPSLOCK_ON 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENHANCED_ਕੁੰਜੀ 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NLS_DBCSCHAR 0x10000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NLS_ALPHANUMERIC 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NLS_KATAKANA 0x20000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NLS_HIRAGANA 0x40000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NLS_ROMAN 0x400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NLS_IME_CONVERSION 0x800000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NLS_IME_DISABLE 0x20000000

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ MOUSE_EVENT_ਰਿਕਾਰਡ {
    COORD dwMousePosition;
    DWORD dwButtonState;
    DWORD dw_Control_ਕੁੰਜੀ_State;
    DWORD dwEventFlags;
  } MOUSE_EVENT_ਰਿਕਾਰਡ_2,*PMOUSE_EVENT_ਰਿਕਾਰਡ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FROM_ਖੱਬਾ_1_ST_BUTTON_PRESSED 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIGHTMOST_BUTTON_PRESSED 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FROM_ਖੱਬਾ_2_ND_BUTTON_PRESSED 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FROM_ਖੱਬਾ_3_RD_BUTTON_PRESSED 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FROM_ਖੱਬਾ_4_TH_BUTTON_PRESSED 0x10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSE_MOVED 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOUBLE_CLICK 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSE_WHEELED 0x4

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਖਿੜਕੀ_ਬਫਰ_ਮਾਪ_ਰਿਕਾਰਡ {
    COORD dw_ਮਾਪ;
  } ਖਿੜਕੀ_ਬਫਰ_ਮਾਪ_ਰਿਕਾਰਡ_2,*PWINDOW_ਬਫਰ_ਮਾਪ_ਰਿਕਾਰਡ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ MENU_EVENT_ਰਿਕਾਰਡ {
    UINT dwCommandId;
  } MENU_EVENT_ਰਿਕਾਰਡ_2,*PMENU_EVENT_ਰਿਕਾਰਡ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ FOCUS_EVENT_ਰਿਕਾਰਡ {
    WINBOOL b_ਸੈੱਟ_Focus;
  } FOCUS_EVENT_ਰਿਕਾਰਡ_2,*PFOCUS_EVENT_ਰਿਕਾਰਡ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਨਿਵੇਸ਼_ਰਿਕਾਰਡ {
    ਸ਼ਬਦ_3 EventType;
    ਸੰਘ {
      ਕੁੰਜੀ_EVENT_ਰਿਕਾਰਡ_2 ਕੁੰਜੀ_Event;
      MOUSE_EVENT_ਰਿਕਾਰਡ_2 MouseEvent;
      ਖਿੜਕੀ_ਬਫਰ_ਮਾਪ_ਰਿਕਾਰਡ_2 ਖਿੜਕੀ_ਬਫਰ_ਮਾਪ_Event;
      MENU_EVENT_ਰਿਕਾਰਡ_2 MenuEvent;
      FOCUS_EVENT_ਰਿਕਾਰਡ_2 FocusEvent;
    } Event;
  } ਨਿਵੇਸ਼_ਰਿਕਾਰਡ_2,*PINPUT_ਰਿਕਾਰਡ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕੁੰਜੀ_EVENT 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSE_EVENT 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਖਿੜਕੀ_ਬਫਰ_ਮਾਪ_EVENT 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MENU_EVENT 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FOCUS_EVENT 0x10

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CHAR_INFO {
    ਸੰਘ {
      WCHAR UnicodeChar;
      CHAR AsciiChar;
    } Char;
    ਸ਼ਬਦ_3 ਗੁਣ;
  } CHAR_INFO,*PCHAR_INFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FOREGROUND_BLUE 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FOREGROUND_GREEN 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FOREGROUND_RED 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FOREGROUND_INTENSITY 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKGROUND_BLUE 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKGROUND_GREEN 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKGROUND_RED 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BACKGROUND_INTENSITY 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMMON_LVB_LEADING_BYTE 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMMON_LVB_TRAILING_BYTE 0x200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMMON_LVB_GRID_HORIZONTAL 0x400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMMON_LVB_GRID_LVERTICAL 0x800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMMON_LVB_GRID_RVERTICAL 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMMON_LVB_ਉਲਟ_VIDEO 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMMON_LVB_UNDERSCORE 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMMON_LVB_SBCSDBCS 0x300

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ CONSOLE_SCREEN_ਬਫਰ_INFO {
    COORD dw_ਮਾਪ;
    COORD dwCursorPosition;
    ਸ਼ਬਦ_3 w_ਗੁਣ;
    SMALL_RECT sr_ਖਿੜਕੀ;
    COORD dw_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਖਿੜਕੀ_ਮਾਪ;
  } CONSOLE_SCREEN_ਬਫਰ_INFO_2,*PCONSOLE_SCREEN_ਬਫਰ_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CONSOLE_CURSOR_INFO {
    DWORD dw_ਮਾਪ;
    WINBOOL bVisible;
  } CONSOLE_CURSOR_INFO,*PCONSOLE_CURSOR_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CONSOLE_FONT_INFO {
    DWORD nFont;
    COORD dw_Font_ਮਾਪ;
  } CONSOLE_FONT_INFO,*PCONSOLE_FONT_INFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _CONSOLE_SELECTION_INFO {
    DWORD dwFlags;
    COORD dwSelectionAnchor;
    SMALL_RECT srSelection;
  } CONSOLE_SELECTION_INFO,*PCONSOLE_SELECTION_INFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_NO_SELECTION 0x0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_SELECTION_ਵਿੱਚ_ਤਰੱਕੀ 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_SELECTION_NOT_ਖਾਲੀ_ਥਾਵਾਂ 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_MOUSE_SELECTION 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_MOUSE_ਥੱਲੇ 0x8

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (WINAPI *PHANDLER_ROUTINE)(DWORD CtrlType);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTRL_C_EVENT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTRL_BREAK_EVENT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTRL_CLOSE_EVENT 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTRL_LOGOFF_EVENT 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTRL_SHUTDOWN_EVENT 6

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_PROCESSED_ਨਿਵੇਸ਼ 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_ਸਤਰ_ਨਿਵੇਸ਼ 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_ECHO_ਨਿਵੇਸ਼ 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_ਖਿੜਕੀ_ਨਿਵੇਸ਼ 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_MOUSE_ਨਿਵੇਸ਼ 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_ਪਾਓ_ਬਹੁਲਕ 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_ਤੇਜ਼_EDIT_ਬਹੁਲਕ 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_EXTENDED_FLAGS 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_AUTO_POSITION 0x100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_VIRTUAL_TERMINAL_ਨਿਵੇਸ਼ 0x200

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_PROCESSED_OUTPUT 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_WRAP_AT_EOL_OUTPUT 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISABLE_NEWLINE_AUTO_RETURN 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLE_LVB_GRID_WORLDWIDE 0x10

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Peek_Console_ਨਿਵੇਸ਼ Peek_Console_ਨਿਵੇਸ਼_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Read_Console_ਨਿਵੇਸ਼ Read_Console_ਨਿਵੇਸ਼_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Write_Console_ਨਿਵੇਸ਼ Write_Console_ਨਿਵੇਸ਼_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadConsoleOutput ReadConsoleOutputW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteConsoleOutput WriteConsoleOutputW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FillConsoleOutputCharacter FillConsoleOutputCharacterW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Scroll_Console_Screen_ਬਫਰ Scroll_Console_Screen_ਬਫਰ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetConsoleTitle GetConsoleTitleW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Console_Title ਸੈੱਟ_Console_Title_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadConsole ReadConsoleW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteConsole WriteConsoleW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Console_Alias ਜੋੜੋ_Console_Alias_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetConsoleAlias GetConsoleAliasW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Console_Aliases_ਲੰਮਾਈ Get_Console_Aliases_ਲੰਮਾਈ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Console_Alias_Exes_ਲੰਮਾਈ Get_Console_Alias_Exes_ਲੰਮਾਈ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetConsoleAliases GetConsoleAliasesW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetConsoleAliasExes GetConsoleAliasExesW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Peek_Console_ਨਿਵੇਸ਼ Peek_Console_ਨਿਵੇਸ਼_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Read_Console_ਨਿਵੇਸ਼ Read_Console_ਨਿਵੇਸ਼_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Write_Console_ਨਿਵੇਸ਼ Write_Console_ਨਿਵੇਸ਼_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadConsoleOutput ReadConsoleOutputA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteConsoleOutput WriteConsoleOutputA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FillConsoleOutputCharacter FillConsoleOutputCharacterA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Scroll_Console_Screen_ਬਫਰ Scroll_Console_Screen_ਬਫਰ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetConsoleTitle GetConsoleTitleA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Console_Title ਸੈੱਟ_Console_Title_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ReadConsole ReadConsoleA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WriteConsole WriteConsoleA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Console_Alias ਜੋੜੋ_Console_Alias_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetConsoleAlias GetConsoleAliasA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Console_Aliases_ਲੰਮਾਈ Get_Console_Aliases_ਲੰਮਾਈ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Console_Alias_Exes_ਲੰਮਾਈ Get_Console_Alias_Exes_ਲੰਮਾਈ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetConsoleAliases GetConsoleAliasesA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetConsoleAliasExes GetConsoleAliasExesA
#ਜੇ_ਅੰਤ

  WINBASEAPI WINBOOL WINAPI Peek_Console_ਨਿਵੇਸ਼_A(HANDLE h_Console_ਨਿਵੇਸ਼,PINPUT_ਰਿਕਾਰਡ lp_ਬਫਰ,DWORD n_ਲੰਮਾਈ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Events_Read);
  WINBASEAPI WINBOOL WINAPI Peek_Console_ਨਿਵੇਸ਼_W(HANDLE h_Console_ਨਿਵੇਸ਼,PINPUT_ਰਿਕਾਰਡ lp_ਬਫਰ,DWORD n_ਲੰਮਾਈ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_ਨਿਵੇਸ਼_A(HANDLE h_Console_ਨਿਵੇਸ਼,PINPUT_ਰਿਕਾਰਡ lp_ਬਫਰ,DWORD n_ਲੰਮਾਈ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Events_Read);
  WINBASEAPI WINBOOL WINAPI Read_Console_ਨਿਵੇਸ਼_W(HANDLE h_Console_ਨਿਵੇਸ਼,PINPUT_ਰਿਕਾਰਡ lp_ਬਫਰ,DWORD n_ਲੰਮਾਈ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Events_Read);
  WINBASEAPI WINBOOL WINAPI Write_Console_ਨਿਵੇਸ਼_A(HANDLE h_Console_ਨਿਵੇਸ਼,CONST ਨਿਵੇਸ਼_ਰਿਕਾਰਡ_2 *lp_ਬਫਰ,DWORD n_ਲੰਮਾਈ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Events_Written);
  WINBASEAPI WINBOOL WINAPI Write_Console_ਨਿਵੇਸ਼_W(HANDLE h_Console_ਨਿਵੇਸ਼,CONST ਨਿਵੇਸ਼_ਰਿਕਾਰਡ_2 *lp_ਬਫਰ,DWORD n_ਲੰਮਾਈ,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Events_Written);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputA(HANDLE hConsoleOutput,PCHAR_INFO lp_ਬਫਰ,COORD dw_ਬਫਰ_ਮਾਪ,COORD dw_ਬਫਰ_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputW(HANDLE hConsoleOutput,PCHAR_INFO lp_ਬਫਰ,COORD dw_ਬਫਰ_ਮਾਪ,COORD dw_ਬਫਰ_Coord,PSMALL_RECT lpReadRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputA(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_ਬਫਰ,COORD dw_ਬਫਰ_ਮਾਪ,COORD dw_ਬਫਰ_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputW(HANDLE hConsoleOutput,CONST CHAR_INFO *lp_ਬਫਰ,COORD dw_ਬਫਰ_ਮਾਪ,COORD dw_ਬਫਰ_Coord,PSMALL_RECT lpWriteRegion);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterA(HANDLE hConsoleOutput,LPSTR lpCharacter,DWORD n_ਲੰਮਾਈ,COORD dwReadCoord,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputCharacterW(HANDLE hConsoleOutput,LPWSTR lpCharacter,DWORD n_ਲੰਮਾਈ,COORD dwReadCoord,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Read);
  WINBASEAPI WINBOOL WINAPI ReadConsoleOutputAttribute(HANDLE hConsoleOutput,LPWORD lpAttribute,DWORD n_ਲੰਮਾਈ,COORD dwReadCoord,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Attrs_Read);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterA(HANDLE hConsoleOutput,LPCSTR lpCharacter,DWORD n_ਲੰਮਾਈ,COORD dwWriteCoord,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputCharacterW(HANDLE hConsoleOutput,LPCWSTR lpCharacter,DWORD n_ਲੰਮਾਈ,COORD dwWriteCoord,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Written);
  WINBASEAPI WINBOOL WINAPI WriteConsoleOutputAttribute(HANDLE hConsoleOutput,CONST ਸ਼ਬਦ_3 *lpAttribute,DWORD n_ਲੰਮਾਈ,COORD dwWriteCoord,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterA(HANDLE hConsoleOutput,CHAR cCharacter,DWORD n_ਲੰਮਾਈ,COORD dwWriteCoord,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputCharacterW(HANDLE hConsoleOutput,WCHAR cCharacter,DWORD n_ਲੰਮਾਈ,COORD dwWriteCoord,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Written);
  WINBASEAPI WINBOOL WINAPI FillConsoleOutputAttribute(HANDLE hConsoleOutput,ਸ਼ਬਦ_3 wAttribute,DWORD n_ਲੰਮਾਈ,COORD dwWriteCoord,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Attrs_Written);
  WINBASEAPI WINBOOL WINAPI Get_Console_ਬਹੁਲਕ(HANDLE hConsoleHandle,LPDWORD lp_ਬਹੁਲਕ);
  WINBASEAPI WINBOOL WINAPI Get_ਸੰਖਿਆ_ਦਾ_Console_ਨਿਵੇਸ਼_Events(HANDLE h_Console_ਨਿਵੇਸ਼,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Events);
  WINBASEAPI WINBOOL WINAPI Get_Console_Screen_ਬਫਰ_Info(HANDLE hConsoleOutput,PCONSOLE_SCREEN_ਬਫਰ_INFO lp_Console_Screen_ਬਫਰ_Info);
  WINBASEAPI COORD WINAPI Get_ਸਭ_ਤੋਂ_ਵੱਡਾ_Console_ਖਿੜਕੀ_ਮਾਪ(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI GetConsoleCursorInfo(HANDLE hConsoleOutput,PCONSOLE_CURSOR_INFO lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI GetCurrentConsoleFont(HANDLE hConsoleOutput,WINBOOL b_ਵੱਧ_ਤੋਂ_ਵੱਧ_ਖਿੜਕੀ,PCONSOLE_FONT_INFO lpConsoleCurrentFont);
  WINBASEAPI COORD WINAPI Get_Console_Font_ਮਾਪ(HANDLE hConsoleOutput,DWORD nFont);
  WINBASEAPI WINBOOL WINAPI GetConsoleSelectionInfo(PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo);
  WINBASEAPI WINBOOL WINAPI Get_ਸੰਖਿਆ_ਦਾ_Console_Mouse_Buttons(LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Mouse_Buttons);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_ਬਹੁਲਕ(HANDLE hConsoleHandle,DWORD dw_ਬਹੁਲਕ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_ਸਰਗਰਮ_Screen_ਬਫਰ(HANDLE hConsoleOutput);
  WINBASEAPI WINBOOL WINAPI Flush_Console_ਨਿਵੇਸ਼_ਬਫਰ(HANDLE h_Console_ਨਿਵੇਸ਼);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_Screen_ਬਫਰ_ਮਾਪ(HANDLE hConsoleOutput,COORD dw_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_Cursor_Position(HANDLE hConsoleOutput,COORD dwCursorPosition);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_Cursor_Info(HANDLE hConsoleOutput,CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_ਬਫਰ_A(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI Scroll_Console_Screen_ਬਫਰ_W(HANDLE hConsoleOutput,CONST SMALL_RECT *lpScrollRectangle,CONST SMALL_RECT *lpClipRectangle,COORD dwDestinationOrigin,CONST CHAR_INFO *lpFill);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_ਖਿੜਕੀ_Info(HANDLE hConsoleOutput,WINBOOL bAbsolute,CONST SMALL_RECT *lp_Console_ਖਿੜਕੀ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_ਪਾਠ_Attribute(HANDLE hConsoleOutput,ਸ਼ਬਦ_3 w_ਗੁਣ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_Ctrl_Handler(PHANDLER_ROUTINE HandlerRoutine,WINBOOL ਜੋੜੋ_3);
  WINBASEAPI WINBOOL WINAPI GenerateConsoleCtrlEvent(DWORD dwCtrlEvent,DWORD dw_Process_ਸਮੂਹ_Id);
  WINBASEAPI WINBOOL WINAPI AllocConsole(VOID);
  WINBASEAPI WINBOOL WINAPI FreeConsole(VOID);
  WINBASEAPI WINBOOL WINAPI AttachConsole(DWORD dwProcessId);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATTACH_ਮਾਪਾ_PROCESS ((DWORD)-1)

  WINBASEAPI DWORD WINAPI GetConsoleTitleA(LPSTR lpConsoleTitle,DWORD n_ਮਾਪ);
  WINBASEAPI DWORD WINAPI GetConsoleTitleW(LPWSTR lpConsoleTitle,DWORD n_ਮਾਪ);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_Title_A(LPCSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_Title_W(LPCWSTR lpConsoleTitle);
  WINBASEAPI WINBOOL WINAPI ReadConsoleA(HANDLE h_Console_ਨਿਵੇਸ਼,LPVOID lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_Chars_ਮੰਜ਼ਿਲ_Read,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI ReadConsoleW(HANDLE h_Console_ਨਿਵੇਸ਼,LPVOID lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_Chars_ਮੰਜ਼ਿਲ_Read,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Read,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleA(HANDLE hConsoleOutput,CONST VOID *lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_Chars_ਮੰਜ਼ਿਲ_Write,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Written,LPVOID lpReserved);
  WINBASEAPI WINBOOL WINAPI WriteConsoleW(HANDLE hConsoleOutput,CONST VOID *lp_ਬਫਰ,DWORD n_ਸੰਖਿਆ_ਦਾ_Chars_ਮੰਜ਼ਿਲ_Write,LPDWORD lp_ਸੰਖਿਆ_ਦਾ_Chars_Written,LPVOID lpReserved);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_TEXTMODE_ਬਫਰ 1

  WINBASEAPI HANDLE WINAPI Create_Console_Screen_ਬਫਰ(DWORD dwDesiredAccess,DWORD dw_Share_ਬਹੁਲਕ,CONST SECURITY_ਗੁਣ_2 *lp_Security_ਗੁਣ,DWORD dwFlags,LPVOID lp_Screen_ਬਫਰ_ਅੰਕੜੇ);
  WINBASEAPI UINT WINAPI GetConsoleCP(VOID);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_CP(UINT w_ਕੋਡ_ਪੰਨਾ_ID);
  WINBASEAPI UINT WINAPI GetConsoleOutputCP(VOID);
  WINBASEAPI WINBOOL WINAPI ਸੈੱਟ_Console_Output_CP(UINT w_ਕੋਡ_ਪੰਨਾ_ID);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_FULLSCREEN 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_FULLSCREEN_HARDWARE 2

  WINBASEAPI WINBOOL WINAPI Get_Console_Display_ਬਹੁਲਕ(LPDWORD lp_ਬਹੁਲਕ_Flags);
  WINBASEAPI HWND WINAPI Get_Console_ਖਿੜਕੀ(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleProcessList(LPDWORD lpdwProcessList,DWORD dw_Process_ਗਿਣਤੀ);
  WINBASEAPI WINBOOL WINAPI ਜੋੜੋ_Console_Alias_A(LPSTR ਸਰੋਤ_2,LPSTR ਨਿਸ਼ਾਨਾ_2,LPSTR ExeName);
  WINBASEAPI WINBOOL WINAPI ਜੋੜੋ_Console_Alias_W(LPWSTR ਸਰੋਤ_2,LPWSTR ਨਿਸ਼ਾਨਾ_2,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasA(LPSTR ਸਰੋਤ_2,LPSTR ਨਿਸ਼ਾਨਾ_ਬਫਰ,DWORD ਨਿਸ਼ਾਨਾ_ਬਫਰ_ਲੰਮਾਈ,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasW(LPWSTR ਸਰੋਤ_2,LPWSTR ਨਿਸ਼ਾਨਾ_ਬਫਰ,DWORD ਨਿਸ਼ਾਨਾ_ਬਫਰ_ਲੰਮਾਈ,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_ਲੰਮਾਈ_A(LPSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Aliases_ਲੰਮਾਈ_W(LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_ਲੰਮਾਈ_A(VOID);
  WINBASEAPI DWORD WINAPI Get_Console_Alias_Exes_ਲੰਮਾਈ_W(VOID);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesA(LPSTR Alias_ਬਫਰ,DWORD Alias_ਬਫਰ_ਲੰਮਾਈ,LPSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasesW(LPWSTR Alias_ਬਫਰ,DWORD Alias_ਬਫਰ_ਲੰਮਾਈ,LPWSTR ExeName);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesA(LPSTR Exe_Name_ਬਫਰ,DWORD Exe_Name_ਬਫਰ_ਲੰਮਾਈ);
  WINBASEAPI DWORD WINAPI GetConsoleAliasExesW(LPWSTR Exe_Name_ਬਫਰ,DWORD Exe_Name_ਬਫਰ_ਲੰਮਾਈ);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
