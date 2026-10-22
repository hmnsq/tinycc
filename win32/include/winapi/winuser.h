/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _WINUSER_
#నిర్వచించు _WINUSER_

#నిర్వచించు WINUSERAPI DECLSPEC_IMPORT

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WINVER
#నిర్వచించు WINVER 0x0502
#అయితే_ముగింపు

#అన్తర్భావ <stdarg.h>

#నిర్వచితం_కాకపోతే NOUSER
  రకనిర్వచనం HANDLE HDWP;
  రకనిర్వచనం VOID MENUTEMPLATEA;
  రకనిర్వచనం VOID MENUTEMPLATEW;
  రకనిర్వచనం PVOID LPMENUTEMPLATEA;
  రకనిర్వచనం PVOID LPMENUTEMPLATEW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం MENUTEMPLATEW MENUTEMPLATE;
  రకనిర్వచనం LPMENUTEMPLATEW LPMENUTEMPLATE;
#లేకపోతే
  రకనిర్వచనం MENUTEMPLATEA MENUTEMPLATE;
  రకనిర్వచనం LPMENUTEMPLATEA LPMENUTEMPLATE;
#అయితే_ముగింపు

  రకనిర్వచనం LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
  రకనిర్వచనం INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
  రకనిర్వచనం VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
  రకనిర్వచనం WINBOOL (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,పూర్ణాంకం);
  రకనిర్వచనం WINBOOL (CALLBACK *WNDENUMPROC)(HWND,LPARAM);
  రకనిర్వచనం LRESULT (CALLBACK *HOOKPROC)(పూర్ణాంకం సంకేతం_2,WPARAM wParam,LPARAM lParam);
  రకనిర్వచనం VOID (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
  రకనిర్వచనం WINBOOL (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
  రకనిర్వచనం WINBOOL (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
  రకనిర్వచనం WINBOOL (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
  రకనిర్వచనం WINBOOL (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
  రకనిర్వచనం పూర్ణాంకం (CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch,పూర్ణాంకం ichCurrent,పూర్ణాంకం cch,పూర్ణాంకం సంకేతం_2);
  రకనిర్వచనం పూర్ణాంకం (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch,పూర్ణాంకం ichCurrent,పూర్ణాంకం cch,పూర్ణాంకం సంకేతం_2);
  రకనిర్వచనం WINBOOL (CALLBACK *DRAWSTATEPROC)(HDC hdc,LPARAM l_దత్తాంశం,WPARAM w_దత్తాంశం,పూర్ణాంకం cx,పూర్ణాంకం cy);

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం PROPENUMPROCW PROPENUMPROC;
  రకనిర్వచనం PROPENUMPROCEXW PROPENUMPROCEX;
  రకనిర్వచనం EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#లేకపోతే
  రకనిర్వచనం PROPENUMPROCA PROPENUMPROC;
  రకనిర్వచనం PROPENUMPROCEXA PROPENUMPROCEX;
  రకనిర్వచనం EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#అయితే_ముగింపు

  రకనిర్వచనం WINBOOL (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
  రకనిర్వచనం WINBOOL (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
  రకనిర్వచనం NAMEENUMPROCA WINSTAENUMPROCA;
  రకనిర్వచనం NAMEENUMPROCA DESKTOPENUMPROCA;
  రకనిర్వచనం NAMEENUMPROCW WINSTAENUMPROCW;
  రకనిర్వచనం NAMEENUMPROCW DESKTOPENUMPROCW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WINSTAENUMPROCW WINSTAENUMPROC;
  రకనిర్వచనం DESKTOPENUMPROCW DESKTOPENUMPROC;
#లేకపోతే
  రకనిర్వచనం WINSTAENUMPROCA WINSTAENUMPROC;
  రకనిర్వచనం DESKTOPENUMPROCA DESKTOPENUMPROC;
#అయితే_ముగింపు

#నిర్వచించు IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)
#నిర్వచించు MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((మాట_3)(i))))
#నిర్వచించు MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((మాట_3)(i))))
#నిర్వచితమైతే UNICODE
#నిర్వచించు MAKEINTRESOURCE MAKEINTRESOURCEW
#లేకపోతే
#నిర్వచించు MAKEINTRESOURCE MAKEINTRESOURCEA
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NORESOURCE

#నిర్వచించు RT_CURSOR MAKEINTRESOURCE(1)
#నిర్వచించు RT_BITMAP MAKEINTRESOURCE(2)
#నిర్వచించు RT_ICON MAKEINTRESOURCE(3)
#నిర్వచించు RT_MENU MAKEINTRESOURCE(4)
#నిర్వచించు RT_DIALOG MAKEINTRESOURCE(5)
#నిర్వచించు RT_STRING MAKEINTRESOURCE(6)
#నిర్వచించు RT_FONTDIR MAKEINTRESOURCE(7)
#నిర్వచించు RT_FONT MAKEINTRESOURCE(8)
#నిర్వచించు RT_ACCELERATOR MAKEINTRESOURCE(9)
#నిర్వచించు RT_RCDATA MAKEINTRESOURCE(10)
#నిర్వచించు RT_MESSAGETABLE MAKEINTRESOURCE(11)

#నిర్వచించు DIFFERENCE 11
#నిర్వచించు RT_సమూహం_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
#నిర్వచించు RT_సమూహం_ICON MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
#నిర్వచించు RT_సంస్కరణ MAKEINTRESOURCE(16)
#నిర్వచించు RT_DLGINCLUDE MAKEINTRESOURCE(17)
#నిర్వచించు RT_PLUGPLAY MAKEINTRESOURCE(19)
#నిర్వచించు RT_VXD MAKEINTRESOURCE(20)
#నిర్వచించు RT_ANICURSOR MAKEINTRESOURCE(21)
#నిర్వచించు RT_ANIICON MAKEINTRESOURCE(22)
#నిర్వచించు RT_HTML MAKEINTRESOURCE(23)
#నిర్వచితమైతే RC_INVOKED
#నిర్వచించు RT_MANIFEST 24
#నిర్వచించు CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#నిర్వచించు ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#నిర్వచించు ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#నిర్వచించు MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#నిర్వచించు గరిష్ఠ_RESERVED_MANIFEST_RESOURCE_ID 16
#లేకపోతే
#నిర్వచించు RT_MANIFEST MAKEINTRESOURCE(24)
#నిర్వచించు CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#నిర్వచించు ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#నిర్వచించు ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#నిర్వచించు MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#నిర్వచించు గరిష్ఠ_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు wvsprintf wvsprintfW
#నిర్వచించు wsprintf wsprintfW
#లేకపోతే
#నిర్వచించు wvsprintf wvsprintfA
#నిర్వచించు wsprintf wsprintfA
#అయితే_ముగింపు

  WINUSERAPI పూర్ణాంకం WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
  WINUSERAPI పూర్ణాంకం WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);
  WINUSERAPI పూర్ణాంకం WINAPIV wsprintfA(LPSTR,LPCSTR,...);
  WINUSERAPI పూర్ణాంకం WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);

#నిర్వచించు SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#నిర్వచితం_కాకపోతే NOSCROLL
#నిర్వచించు SB_HORZ 0
#నిర్వచించు SB_VERT 1
#నిర్వచించు SB_CTL 2
#నిర్వచించు SB_BOTH 3

#నిర్వచించు SB_LINEUP 0
#నిర్వచించు SB_LINELEFT 0
#నిర్వచించు SB_LINEDOWN 1
#నిర్వచించు SB_LINERIGHT 1
#నిర్వచించు SB_PAGEUP 2
#నిర్వచించు SB_PAGELEFT 2
#నిర్వచించు SB_PAGEDOWN 3
#నిర్వచించు SB_PAGERIGHT 3
#నిర్వచించు SB_THUMBPOSITION 4
#నిర్వచించు SB_THUMBTRACK 5
#నిర్వచించు SB_శిఖరం 6
#నిర్వచించు SB_ఎడమ 6
#నిర్వచించు SB_BOTTOM 7
#నిర్వచించు SB_కుడి 7
#నిర్వచించు SB_ENDSCROLL 8
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOSHOWWINDOW
#నిర్వచించు SW_HIDE 0
#నిర్వచించు SW_SHOWNORMAL 1
#నిర్వచించు SW_సాధారణ 1
#నిర్వచించు SW_SHOWMINIMIZED 2
#నిర్వచించు SW_SHOWMAXIMIZED 3
#నిర్వచించు SW_MAXIMIZE 3
#నిర్వచించు SW_SHOWNOACTIVATE 4
#నిర్వచించు SW_SHOW 5
#నిర్వచించు SW_MINIMIZE 6
#నిర్వచించు SW_SHOWMINNOACTIVE 7
#నిర్వచించు SW_SHOWNA 8
#నిర్వచించు SW_RESTORE 9
#నిర్వచించు SW_SHOWDEFAULT 10
#నిర్వచించు SW_FORCEMINIMIZE 11
#నిర్వచించు SW_MAX 11

#నిర్వచించు HIDE_కిటికీ 0
#నిర్వచించు SHOW_OPENWINDOW 1
#నిర్వచించు SHOW_ICONWINDOW 2
#నిర్వచించు SHOW_FULLSCREEN 3
#నిర్వచించు SHOW_OPENNOACTIVATE 4

#నిర్వచించు SW_PARENTCLOSING 1
#నిర్వచించు SW_OTHERZOOM 2
#నిర్వచించు SW_PARENTOPENING 3
#నిర్వచించు SW_OTHERUNZOOM 4
#అయితే_ముగింపు

#నిర్వచించు AW_HOR_ధనాత్మక 0x00000001
#నిర్వచించు AW_HOR_NEGATIVE 0x00000002
#నిర్వచించు AW_VER_ధనాత్మక 0x00000004
#నిర్వచించు AW_VER_NEGATIVE 0x00000008
#నిర్వచించు AW_CENTER 0x00000010
#నిర్వచించు AW_HIDE 0x00010000
#నిర్వచించు AW_ACTIVATE 0x00020000
#నిర్వచించు AW_SLIDE 0x00040000
#నిర్వచించు AW_BLEND 0x00080000

#నిర్వచించు KF_EXTENDED 0x0100
#నిర్వచించు KF_DLGMODE 0x0800
#నిర్వచించు KF_MENUMODE 0x1000
#నిర్వచించు KF_ALTDOWN 0x2000
#నిర్వచించు KF_REPEAT 0x4000
#నిర్వచించు KF_పైకి 0x8000

#నిర్వచితం_కాకపోతే NOVIRTUALKEYCODES

#నిర్వచించు VK_LBUTTON 0x01
#నిర్వచించు VK_RBUTTON 0x02
#నిర్వచించు VK_CANCEL 0x03
#నిర్వచించు VK_MBUTTON 0x04
#నిర్వచించు VK_XBUTTON1 0x05
#నిర్వచించు VK_XBUTTON2 0x06
#నిర్వచించు VK_వెనుక 0x08
#నిర్వచించు VK_TAB 0x09
#నిర్వచించు VK_CLEAR 0x0C
#నిర్వచించు VK_RETURN 0x0D
#నిర్వచించు VK_జరుపు 0x10
#నిర్వచించు VK_CONTROL 0x11
#నిర్వచించు VK_MENU 0x12
#నిర్వచించు VK_PAUSE 0x13
#నిర్వచించు VK_CAPITAL 0x14
#నిర్వచించు VK_KANA 0x15
#నిర్వచించు VK_HANGEUL 0x15
#నిర్వచించు VK_HANGUL 0x15
#నిర్వచించు VK_JUNJA 0x17
#నిర్వచించు VK_FINAL 0x18
#నిర్వచించు VK_HANJA 0x19
#నిర్వచించు VK_KANJI 0x19
#నిర్వచించు VK_ESCAPE 0x1B
#నిర్వచించు VK_CONVERT 0x1C
#నిర్వచించు VK_NONCONVERT 0x1D
#నిర్వచించు VK_ACCEPT 0x1E
#నిర్వచించు VK_MODECHANGE 0x1F
#నిర్వచించు VK_SPACE 0x20
#నిర్వచించు VK_పూర్వ 0x21
#నిర్వచించు VK_తదుపరి 0x22
#నిర్వచించు VK_చివర 0x23
#నిర్వచించు VK_HOME 0x24
#నిర్వచించు VK_ఎడమ 0x25
#నిర్వచించు VK_పైకి 0x26
#నిర్వచించు VK_కుడి 0x27
#నిర్వచించు VK_కిందికి 0x28
#నిర్వచించు VK_SELECT 0x29
#నిర్వచించు VK_PRINT 0x2A
#నిర్వచించు VK_EXECUTE 0x2B
#నిర్వచించు VK_SNAPSHOT 0x2C
#నిర్వచించు VK_చొప్పించు 0x2D
#నిర్వచించు VK_DELETE 0x2E
#నిర్వచించు VK_HELP 0x2F

#నిర్వచించు VK_LWIN 0x5B
#నిర్వచించు VK_RWIN 0x5C
#నిర్వచించు VK_APPS 0x5D
#నిర్వచించు VK_SLEEP 0x5F
#నిర్వచించు VK_NUMPAD0 0x60
#నిర్వచించు VK_NUMPAD1 0x61
#నిర్వచించు VK_NUMPAD2 0x62
#నిర్వచించు VK_NUMPAD3 0x63
#నిర్వచించు VK_NUMPAD4 0x64
#నిర్వచించు VK_NUMPAD5 0x65
#నిర్వచించు VK_NUMPAD6 0x66
#నిర్వచించు VK_NUMPAD7 0x67
#నిర్వచించు VK_NUMPAD8 0x68
#నిర్వచించు VK_NUMPAD9 0x69
#నిర్వచించు VK_MULTIPLY 0x6A
#నిర్వచించు VK_కూడు 0x6B
#నిర్వచించు VK_SEPARATOR 0x6C
#నిర్వచించు VK_వ్యవకలనం 0x6D
#నిర్వచించు VK_DECIMAL 0x6E
#నిర్వచించు VK_DIVIDE 0x6F
#నిర్వచించు VK_F1 0x70
#నిర్వచించు VK_F2 0x71
#నిర్వచించు VK_F3 0x72
#నిర్వచించు VK_F4 0x73
#నిర్వచించు VK_F5 0x74
#నిర్వచించు VK_F6 0x75
#నిర్వచించు VK_F7 0x76
#నిర్వచించు VK_F8 0x77
#నిర్వచించు VK_F9 0x78
#నిర్వచించు VK_F10 0x79
#నిర్వచించు VK_F11 0x7A
#నిర్వచించు VK_F12 0x7B
#నిర్వచించు VK_F13 0x7C
#నిర్వచించు VK_F14 0x7D
#నిర్వచించు VK_F15 0x7E
#నిర్వచించు VK_F16 0x7F
#నిర్వచించు VK_F17 0x80
#నిర్వచించు VK_F18 0x81
#నిర్వచించు VK_F19 0x82
#నిర్వచించు VK_F20 0x83
#నిర్వచించు VK_F21 0x84
#నిర్వచించు VK_F22 0x85
#నిర్వచించు VK_F23 0x86
#నిర్వచించు VK_F24 0x87
#నిర్వచించు VK_NUMLOCK 0x90
#నిర్వచించు VK_SCROLL 0x91
#నిర్వచించు VK_OEM_NEC_EQUAL 0x92
#నిర్వచించు VK_OEM_FJ_JISHO 0x92
#నిర్వచించు VK_OEM_FJ_MASSHOU 0x93
#నిర్వచించు VK_OEM_FJ_TOUROKU 0x94
#నిర్వచించు VK_OEM_FJ_LOYA 0x95
#నిర్వచించు VK_OEM_FJ_ROYA 0x96
#నిర్వచించు VK_LSHIFT 0xA0
#నిర్వచించు VK_RSHIFT 0xA1
#నిర్వచించు VK_LCONTROL 0xA2
#నిర్వచించు VK_RCONTROL 0xA3
#నిర్వచించు VK_LMENU 0xA4
#నిర్వచించు VK_RMENU 0xA5
#నిర్వచించు VK_BROWSER_వెనుక 0xA6
#నిర్వచించు VK_BROWSER_FORWARD 0xA7
#నిర్వచించు VK_BROWSER_REFRESH 0xA8
#నిర్వచించు VK_BROWSER_STOP 0xA9
#నిర్వచించు VK_BROWSER_శోధన 0xAA
#నిర్వచించు VK_BROWSER_FAVORITES 0xAB
#నిర్వచించు VK_BROWSER_HOME 0xAC
#నిర్వచించు VK_VOLUME_MUTE 0xAD
#నిర్వచించు VK_VOLUME_కిందికి 0xAE
#నిర్వచించు VK_VOLUME_పైకి 0xAF
#నిర్వచించు VK_MEDIA_తదుపరి_TRACK 0xB0
#నిర్వచించు VK_MEDIA_PREV_TRACK 0xB1
#నిర్వచించు VK_MEDIA_STOP 0xB2
#నిర్వచించు VK_MEDIA_PLAY_PAUSE 0xB3
#నిర్వచించు VK_LAUNCH_MAIL 0xB4
#నిర్వచించు VK_LAUNCH_MEDIA_SELECT 0xB5
#నిర్వచించు VK_LAUNCH_APP1 0xB6
#నిర్వచించు VK_LAUNCH_APP2 0xB7
#నిర్వచించు VK_OEM_1 0xBA
#నిర్వచించు VK_OEM_PLUS 0xBB
#నిర్వచించు VK_OEM_COMMA 0xBC
#నిర్వచించు VK_OEM_MINUS 0xBD
#నిర్వచించు VK_OEM_PERIOD 0xBE
#నిర్వచించు VK_OEM_2 0xBF
#నిర్వచించు VK_OEM_3 0xC0
#నిర్వచించు VK_OEM_4 0xDB
#నిర్వచించు VK_OEM_5 0xDC
#నిర్వచించు VK_OEM_6 0xDD
#నిర్వచించు VK_OEM_7 0xDE
#నిర్వచించు VK_OEM_8 0xDF
#నిర్వచించు VK_OEM_AX 0xE1
#నిర్వచించు VK_OEM_102 0xE2
#నిర్వచించు VK_ICO_HELP 0xE3
#నిర్వచించు VK_ICO_00 0xE4
#నిర్వచించు VK_PROCESSKEY 0xE5
#నిర్వచించు VK_ICO_CLEAR 0xE6
#నిర్వచించు VK_PACKET 0xE7
#నిర్వచించు VK_OEM_RESET 0xE9
#నిర్వచించు VK_OEM_JUMP 0xEA
#నిర్వచించు VK_OEM_PA1 0xEB
#నిర్వచించు VK_OEM_PA2 0xEC
#నిర్వచించు VK_OEM_PA3 0xED
#నిర్వచించు VK_OEM_WSCTRL 0xEE
#నిర్వచించు VK_OEM_CUSEL 0xEF
#నిర్వచించు VK_OEM_ATTN 0xF0
#నిర్వచించు VK_OEM_ముగింపు 0xF1
#నిర్వచించు VK_OEM_COPY 0xF2
#నిర్వచించు VK_OEM_AUTO 0xF3
#నిర్వచించు VK_OEM_ENLW 0xF4
#నిర్వచించు VK_OEM_BACKTAB 0xF5
#నిర్వచించు VK_ATTN 0xF6
#నిర్వచించు VK_CRSEL 0xF7
#నిర్వచించు VK_EXSEL 0xF8
#నిర్వచించు VK_EREOF 0xF9
#నిర్వచించు VK_PLAY 0xFA
#నిర్వచించు VK_ZOOM 0xFB
#నిర్వచించు VK_NONAME 0xFC
#నిర్వచించు VK_PA1 0xFD
#నిర్వచించు VK_OEM_CLEAR 0xFE
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOWH

#నిర్వచించు WH_MIN (-1)
#నిర్వచించు WH_MSGFILTER (-1)
#నిర్వచించు WH_JOURNALRECORD 0
#నిర్వచించు WH_JOURNALPLAYBACK 1
#నిర్వచించు WH_KEYBOARD 2
#నిర్వచించు WH_GETMESSAGE 3
#నిర్వచించు WH_CALLWNDPROC 4
#నిర్వచించు WH_CBT 5
#నిర్వచించు WH_SYSMSGFILTER 6
#నిర్వచించు WH_MOUSE 7
#నిర్వచించు WH_HARDWARE 8
#నిర్వచించు WH_DEBUG 9
#నిర్వచించు WH_SHELL 10
#నిర్వచించు WH_FOREGROUNDIDLE 11
#నిర్వచించు WH_CALLWNDPROCRET 12

#నిర్వచించు WH_KEYBOARD_LL 13
#నిర్వచించు WH_MOUSE_LL 14

#నిర్వచించు WH_MAX 14

#నిర్వచించు WH_MINHOOK WH_MIN
#నిర్వచించు WH_MAXHOOK WH_MAX

#నిర్వచించు HC_ACTION 0
#నిర్వచించు HC_GETNEXT 1
#నిర్వచించు HC_SKIP 2
#నిర్వచించు HC_NOREMOVE 3
#నిర్వచించు HC_NOREM HC_NOREMOVE
#నిర్వచించు HC_SYSMODALON 4
#నిర్వచించు HC_SYSMODALOFF 5

#నిర్వచించు HCBT_MOVESIZE 0
#నిర్వచించు HCBT_MINMAX 1
#నిర్వచించు HCBT_QS 2
#నిర్వచించు HCBT_CREATEWND 3
#నిర్వచించు HCBT_DESTROYWND 4
#నిర్వచించు HCBT_ACTIVATE 5
#నిర్వచించు HCBT_CLICKSKIPPED 6
#నిర్వచించు HCBT_KEYSKIPPED 7
#నిర్వచించు HCBT_SYSCOMMAND 8
#నిర్వచించు HCBT_SETFOCUS 9

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CBT_CREATEWNDA {
    నిర్మాణం ట్యాగ్_CREATESTRUCTA *lpcs;
    HWND hwnd_చొప్పించు_After;
  } CBT_CREATEWNDA,*LPCBT_CREATEWNDA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CBT_CREATEWNDW {
    నిర్మాణం ట్యాగ్_CREATESTRUCTW *lpcs;
    HWND hwnd_చొప్పించు_After;
  } CBT_CREATEWNDW,*LPCBT_CREATEWNDW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం CBT_CREATEWNDW CBT_CREATEWND;
  రకనిర్వచనం LPCBT_CREATEWNDW LPCBT_CREATEWND;
#లేకపోతే
  రకనిర్వచనం CBT_CREATEWNDA CBT_CREATEWND;
  రకనిర్వచనం LPCBT_CREATEWNDA LPCBT_CREATEWND;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CBTACTIVATESTRUCT
  {
    WINBOOL fMouse;
    HWND h_Wnd_చురుకైన;
  } CBTACTIVATESTRUCT,*LPCBTACTIVATESTRUCT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_WTSSESSION_NOTIFICATION {
    DWORD cb_కొలత;
    DWORD dwSessionId;

  } WTSSESSION_NOTIFICATION,*PWTSSESSION_NOTIFICATION;

#నిర్వచించు WTS_CONSOLE_CONNECT 0x1
#నిర్వచించు WTS_CONSOLE_DISCONNECT 0x2
#నిర్వచించు WTS_REMOTE_CONNECT 0x3
#నిర్వచించు WTS_REMOTE_DISCONNECT 0x4
#నిర్వచించు WTS_SESSION_LOGON 0x5
#నిర్వచించు WTS_SESSION_LOGOFF 0x6
#నిర్వచించు WTS_SESSION_తాళం 0x7
#నిర్వచించు WTS_SESSION_UNLOCK 0x8
#నిర్వచించు WTS_SESSION_REMOTE_CONTROL 0x9

#నిర్వచించు MSGF_DIALOGBOX 0
#నిర్వచించు MSGF_MESSAGEBOX 1
#నిర్వచించు MSGF_MENU 2
#నిర్వచించు MSGF_SCROLLBAR 5
#నిర్వచించు MSGF_NEXTWINDOW 6
#నిర్వచించు MSGF_MAX 8
#నిర్వచించు MSGF_USER 4096

#నిర్వచించు HSHELL_WINDOWCREATED 1
#నిర్వచించు HSHELL_WINDOWDESTROYED 2
#నిర్వచించు HSHELL_ACTIVATESHELLWINDOW 3

#నిర్వచించు HSHELL_WINDOWACTIVATED 4
#నిర్వచించు HSHELL_GETMINRECT 5
#నిర్వచించు HSHELL_REDRAW 6
#నిర్వచించు HSHELL_TASKMAN 7
#నిర్వచించు HSHELL_LANGUAGE 8
#నిర్వచించు HSHELL_SYSMENU 9
#నిర్వచించు HSHELL_ENDTASK 10
#నిర్వచించు HSHELL_ACCESSIBILITYSTATE 11
#నిర్వచించు HSHELL_APPCOMMAND 12
#నిర్వచించు HSHELL_WINDOWREPLACED 13
#నిర్వచించు HSHELL_WINDOWREPLACING 14
#నిర్వచించు HSHELL_HIGHBIT 0x8000
#నిర్వచించు HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#నిర్వచించు HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#నిర్వచించు ACCESS_STICKYKEYS 0x0001
#నిర్వచించు ACCESS_FILTERKEYS 0x0002
#నిర్వచించు ACCESS_MOUSEKEYS 0x0003

#నిర్వచించు APPCOMMAND_BROWSER_BACKWARD 1
#నిర్వచించు APPCOMMAND_BROWSER_FORWARD 2
#నిర్వచించు APPCOMMAND_BROWSER_REFRESH 3
#నిర్వచించు APPCOMMAND_BROWSER_STOP 4
#నిర్వచించు APPCOMMAND_BROWSER_శోధన 5
#నిర్వచించు APPCOMMAND_BROWSER_FAVORITES 6
#నిర్వచించు APPCOMMAND_BROWSER_HOME 7
#నిర్వచించు APPCOMMAND_VOLUME_MUTE 8
#నిర్వచించు APPCOMMAND_VOLUME_కిందికి 9
#నిర్వచించు APPCOMMAND_VOLUME_పైకి 10
#నిర్వచించు APPCOMMAND_MEDIA_NEXTTRACK 11
#నిర్వచించు APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#నిర్వచించు APPCOMMAND_MEDIA_STOP 13
#నిర్వచించు APPCOMMAND_MEDIA_PLAY_PAUSE 14
#నిర్వచించు APPCOMMAND_LAUNCH_MAIL 15
#నిర్వచించు APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#నిర్వచించు APPCOMMAND_LAUNCH_APP1 17
#నిర్వచించు APPCOMMAND_LAUNCH_APP2 18
#నిర్వచించు APPCOMMAND_BASS_కిందికి 19
#నిర్వచించు APPCOMMAND_BASS_BOOST 20
#నిర్వచించు APPCOMMAND_BASS_పైకి 21
#నిర్వచించు APPCOMMAND_TREBLE_కిందికి 22
#నిర్వచించు APPCOMMAND_TREBLE_పైకి 23
#నిర్వచించు APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#నిర్వచించు APPCOMMAND_MICROPHONE_VOLUME_కిందికి 25
#నిర్వచించు APPCOMMAND_MICROPHONE_VOLUME_పైకి 26
#నిర్వచించు APPCOMMAND_HELP 27
#నిర్వచించు APPCOMMAND_కనుగొను 28
#నిర్వచించు APPCOMMAND_NEW 29
#నిర్వచించు APPCOMMAND_OPEN 30
#నిర్వచించు APPCOMMAND_CLOSE 31
#నిర్వచించు APPCOMMAND_SAVE 32
#నిర్వచించు APPCOMMAND_PRINT 33
#నిర్వచించు APPCOMMAND_UNDO 34
#నిర్వచించు APPCOMMAND_REDO 35
#నిర్వచించు APPCOMMAND_COPY 36
#నిర్వచించు APPCOMMAND_CUT 37
#నిర్వచించు APPCOMMAND_PASTE 38
#నిర్వచించు APPCOMMAND_జవాబు_గమ్యం_MAIL 39
#నిర్వచించు APPCOMMAND_FORWARD_MAIL 40
#నిర్వచించు APPCOMMAND_SEND_MAIL 41
#నిర్వచించు APPCOMMAND_SPELL_CHECK 42
#నిర్వచించు APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#నిర్వచించు APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#నిర్వచించు APPCOMMAND_CORRECTION_LIST 45
#నిర్వచించు APPCOMMAND_MEDIA_PLAY 46
#నిర్వచించు APPCOMMAND_MEDIA_PAUSE 47
#నిర్వచించు APPCOMMAND_MEDIA_రికార్డు 48
#నిర్వచించు APPCOMMAND_MEDIA_FAST_FORWARD 49
#నిర్వచించు APPCOMMAND_MEDIA_REWIND 50
#నిర్వచించు APPCOMMAND_MEDIA_CHANNEL_పైకి 51
#నిర్వచించు APPCOMMAND_MEDIA_CHANNEL_కిందికి 52

#నిర్వచించు FAPPCOMMAND_MOUSE 0x8000
#నిర్వచించు FAPPCOMMAND_కీలకం 0
#నిర్వచించు FAPPCOMMAND_OEM 0x1000
#నిర్వచించు FAPPCOMMAND_ముసుగు 0xF000

#నిర్వచించు GET_APPCOMMAND_LPARAM(lParam) ((పొట్టి)(HIWORD(lParam) & ~FAPPCOMMAND_ముసుగు))
#నిర్వచించు GET_DEVICE_LPARAM(lParam) ((మాట_3)(HIWORD(lParam) & FAPPCOMMAND_ముసుగు))
#నిర్వచించు GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#నిర్వచించు GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#నిర్వచించు GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)

  రకనిర్వచనం నిర్మాణం {
    HWND hwnd;
    RECT rc;
  } SHELLHOOKINFO,*LPSHELLHOOKINFO;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EVENTMSG {
    UINT సందేశం_2;
    UINT paramL;
    UINT paramH;
    DWORD సమయం;
    HWND hwnd;
  } EVENTMSG,*PEVENTMSGMSG,*NPEVENTMSGMSG,*LPEVENTMSGMSG;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EVENTMSG *PEVENTMSG,*NPEVENTMSG,*LPEVENTMSG;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT సందేశం_2;
    HWND hwnd;
  } CWPSTRUCT,*PCWPSTRUCT,*NPCWPSTRUCT,*LPCWPSTRUCT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CWPRETSTRUCT {
    LRESULT l_ఫలితం;
    LPARAM lParam;
    WPARAM wParam;
    UINT సందేశం_2;
    HWND hwnd;
  } CWPRETSTRUCT,*PCWPRETSTRUCT,*NPCWPRETSTRUCT,*LPCWPRETSTRUCT;

#నిర్వచించు LLKHF_EXTENDED (KF_EXTENDED >> 8)
#నిర్వచించు LLKHF_INJECTED 0x00000010
#నిర్వచించు LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#నిర్వచించు LLKHF_పైకి (KF_పైకి >> 8)

#నిర్వచించు LLMHF_INJECTED 0x00000001

  రకనిర్వచనం నిర్మాణం ట్యాగ్_KBDLLHOOKSTRUCT {
    DWORD vk_సంకేతం;
    DWORD పరిశీలన_సంకేతం;
    DWORD flags;
    DWORD సమయం;
    ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MSLLHOOKSTRUCT {
    బిందువు_3 pt;
    DWORD mouse_దత్తాంశం;
    DWORD flags;
    DWORD సమయం;
    ULONG_PTR dwExtraInfo;
  } MSLLHOOKSTRUCT,*LPMSLLHOOKSTRUCT,*PMSLLHOOKSTRUCT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_DEBUGHOOKINFO {
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    పూర్ణాంకం సంకేతం_2;
  } DEBUGHOOKINFO,*PDEBUGHOOKINFO,*NPDEBUGHOOKINFO,*LPDEBUGHOOKINFO;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MOUSEHOOKSTRUCT {
    బిందువు_3 pt;
    HWND hwnd;
    UINT w_తగిలింది_Test_సంకేతం;
    ULONG_PTR dwExtraInfo;
  } MOUSEHOOKSTRUCT,*LPMOUSEHOOKSTRUCT,*PMOUSEHOOKSTRUCT;

#నిర్వచితమైతే __cplusplus
  రకనిర్వచనం నిర్మాణం ట్యాగ్_MOUSEHOOKSTRUCTEX : బహిరంగ ట్యాగ్_MOUSEHOOKSTRUCT {
    DWORD mouse_దత్తాంశం;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#లేకపోతే
  రకనిర్వచనం నిర్మాణం ట్యాగ్_MOUSEHOOKSTRUCTEX {
    MOUSEHOOKSTRUCT _unnamed;
    DWORD mouse_దత్తాంశం;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_HARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT సందేశం_2;
    WPARAM wParam;
    LPARAM lParam;
  } HARDWAREHOOKSTRUCT,*LPHARDWAREHOOKSTRUCT,*PHARDWAREHOOKSTRUCT;
#అయితే_ముగింపు

#నిర్వచించు HKL_PREV 0
#నిర్వచించు HKL_తదుపరి 1

#నిర్వచించు KLF_ACTIVATE 0x00000001
#నిర్వచించు KLF_SUBSTITUTE_OK 0x00000002
#నిర్వచించు KLF_REORDER 0x00000008
#నిర్వచించు KLF_REPLACELANG 0x00000010
#నిర్వచించు KLF_NOTELLSHELL 0x00000080
#నిర్వచించు KLF_SETFORPROCESS 0x00000100
#నిర్వచించు KLF_SHIFTLOCK 0x00010000
#నిర్వచించు KLF_RESET 0x40000000

#నిర్వచించు INPUTLANGCHANGE_SYSCHARSET 0x0001
#నిర్వచించు INPUTLANGCHANGE_FORWARD 0x0002
#నిర్వచించు INPUTLANGCHANGE_BACKWARD 0x0004

#నిర్వచించు KL_NAMELENGTH 9

#నిర్వచితమైతే UNICODE
#నిర్వచించు ఎక్కించు_Keyboard_Layout ఎక్కించు_Keyboard_Layout_W
#నిర్వచించు GetKeyboardLayoutName GetKeyboardLayoutNameW
#లేకపోతే
#నిర్వచించు ఎక్కించు_Keyboard_Layout ఎక్కించు_Keyboard_Layout_A
#నిర్వచించు GetKeyboardLayoutName GetKeyboardLayoutNameA
#అయితే_ముగింపు

  WINUSERAPI HKL WINAPI ఎక్కించు_Keyboard_Layout_A(LPCSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ఎక్కించు_Keyboard_Layout_W(LPCWSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ActivateKeyboardLayout(HKL hkl,UINT Flags);
  WINUSERAPI పూర్ణాంకం WINAPI గమ్యం_Unicode_Ex(UINT w_Virt_కీలకం,UINT w_పరిశీలన_సంకేతం,CONST BYTE *lp_కీలకం_State,LPWSTR pwszBuff,పూర్ణాంకం cchBuff,UINT wFlags,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI UnloadKeyboardLayout(HKL hkl);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameA(LPSTR pwszKLID);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameW(LPWSTR pwszKLID);
  WINUSERAPI పూర్ణాంకం WINAPI GetKeyboardLayoutList(పూర్ణాంకం nBuff,HKL *lpList);
  WINUSERAPI HKL WINAPI GetKeyboardLayout(DWORD idThread);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MOUSEMOVEPOINT {
    పూర్ణాంకం x;
    పూర్ణాంకం y;
    DWORD సమయం;
    ULONG_PTR dwExtraInfo;
  } MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

#నిర్వచించు GMMP_USE_DISPLAY_POINTS 1
#నిర్వచించు GMMP_USE_ఎగువ_RESOLUTION_POINTS 2

  WINUSERAPI పూర్ణాంకం WINAPI GetMouseMovePointsEx(UINT cb_కొలత,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,పూర్ణాంకం nBufPoints,DWORD resolution);

#నిర్వచితం_కాకపోతే NODESKTOP

#నిర్వచించు DESKTOP_READOBJECTS 0x0001L
#నిర్వచించు DESKTOP_CREATEWINDOW 0x0002L
#నిర్వచించు DESKTOP_CREATEMENU 0x0004L
#నిర్వచించు DESKTOP_HOOKCONTROL 0x0008L
#నిర్వచించు DESKTOP_JOURNALRECORD 0x0010L
#నిర్వచించు DESKTOP_JOURNALPLAYBACK 0x0020L
#నిర్వచించు DESKTOP_ENUMERATE 0x0040L
#నిర్వచించు DESKTOP_WRITEOBJECTS 0x0080L
#నిర్వచించు DESKTOP_SWITCHDESKTOP 0x0100L

#నిర్వచించు DF_ALLOWOTHERACCOUNTHOOK 0x0001L

#నిర్వచితమైతే _WINGDI_
#నిర్వచితం_కాకపోతే NOGDI
#నిర్వచితమైతే UNICODE
#నిర్వచించు CreateDesktop CreateDesktopW
#లేకపోతే
#నిర్వచించు CreateDesktop CreateDesktopA
#అయితే_ముగింపు

  WINUSERAPI HDESK WINAPI CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,LPDEVMODEA pDevmode,DWORD dwFlags,ACCESS_ముసుగు dwDesiredAccess,LPSECURITY_లక్షణాలు lpsa);
  WINUSERAPI HDESK WINAPI CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,LPDEVMODEW pDevmode,DWORD dwFlags,ACCESS_ముసుగు dwDesiredAccess,LPSECURITY_లక్షణాలు lpsa);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు OpenDesktop OpenDesktopW
#నిర్వచించు EnumDesktops EnumDesktopsW
#లేకపోతే
#నిర్వచించు OpenDesktop OpenDesktopA
#నిర్వచించు EnumDesktops EnumDesktopsA
#అయితే_ముగింపు

  WINUSERAPI HDESK WINAPI OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ముసుగు dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ముసుగు dwDesiredAccess);
  WINUSERAPI HDESK WINAPI Open_ఆదానం_Desktop(DWORD dwFlags,WINBOOL fInherit,ACCESS_ముసుగు dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SwitchDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI సమితి_Thread_Desktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI CloseDesktop(HDESK hDesktop);
  WINUSERAPI HDESK WINAPI GetThreadDesktop(DWORD dwThreadId);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOWINDOWSTATION
#నిర్వచించు WINSTA_ENUMDESKTOPS 0x0001L
#నిర్వచించు WINSTA_READATTRIBUTES 0x0002L
#నిర్వచించు WINSTA_ACCESSCLIPBOARD 0x0004L
#నిర్వచించు WINSTA_CREATEDESKTOP 0x0008L
#నిర్వచించు WINSTA_WRITEATTRIBUTES 0x0010L
#నిర్వచించు WINSTA_ACCESSGLOBALATOMS 0x0020L
#నిర్వచించు WINSTA_EXITWINDOWS 0x0040L
#నిర్వచించు WINSTA_ENUMERATE 0x0100L
#నిర్వచించు WINSTA_READSCREEN 0x0200L
#నిర్వచించు WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#నిర్వచించు CWF_CREATE_ONLY 0x0001L

#నిర్వచించు WSF_VISIBLE 0x0001L

#నిర్వచితమైతే UNICODE
#నిర్వచించు Create_కిటికీ_Station Create_కిటికీ_Station_W
#నిర్వచించు Open_కిటికీ_Station Open_కిటికీ_Station_W
#నిర్వచించు Enum_కిటికీ_Stations Enum_కిటికీ_Stations_W
#లేకపోతే
#నిర్వచించు Create_కిటికీ_Station Create_కిటికీ_Station_A
#నిర్వచించు Open_కిటికీ_Station Open_కిటికీ_Station_A
#నిర్వచించు Enum_కిటికీ_Stations Enum_కిటికీ_Stations_A
#అయితే_ముగింపు

  WINUSERAPI HWINSTA WINAPI Create_కిటికీ_Station_A(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_ముసుగు dwDesiredAccess,LPSECURITY_లక్షణాలు lpsa);
  WINUSERAPI HWINSTA WINAPI Create_కిటికీ_Station_W(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_ముసుగు dwDesiredAccess,LPSECURITY_లక్షణాలు lpsa);
  WINUSERAPI HWINSTA WINAPI Open_కిటికీ_Station_A(LPCSTR lpszWinSta,WINBOOL fInherit,ACCESS_ముసుగు dwDesiredAccess);
  WINUSERAPI HWINSTA WINAPI Open_కిటికీ_Station_W(LPCWSTR lpszWinSta,WINBOOL fInherit,ACCESS_ముసుగు dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI Enum_కిటికీ_Stations_A(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Enum_కిటికీ_Stations_W(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Close_కిటికీ_Station(HWINSTA hWinSta);
  WINUSERAPI WINBOOL WINAPI సమితి_Process_కిటికీ_Station(HWINSTA hWinSta);
  WINUSERAPI HWINSTA WINAPI Get_Process_కిటికీ_Station(VOID);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOSECURITY
  WINUSERAPI WINBOOL WINAPI సమితి_User_Object_Security(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
  WINUSERAPI WINBOOL WINAPI GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD n_నిడివి,LPDWORD lpn_నిడివి_Needed);

#నిర్వచించు UOI_FLAGS 1
#నిర్వచించు UOI_NAME 2
#నిర్వచించు UOI_TYPE 3
#నిర్వచించు UOI_USER_SID 4

  రకనిర్వచనం నిర్మాణం ట్యాగ్_USEROBJECTFLAGS {
    WINBOOL fInherit;
    WINBOOL fReserved;
    DWORD dwFlags;
  } USEROBJECTFLAGS,*PUSEROBJECTFLAGS;

#నిర్వచితమైతే UNICODE
#నిర్వచించు GetUserObjectInformation GetUserObjectInformationW
#నిర్వచించు సమితి_User_Object_Information సమితి_User_Object_Information_W
#లేకపోతే
#నిర్వచించు GetUserObjectInformation GetUserObjectInformationA
#నిర్వచించు సమితి_User_Object_Information సమితి_User_Object_Information_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationA(HANDLE hObj,పూర్ణాంకం n_సూచీ,PVOID pvInfo,DWORD n_నిడివి,LPDWORD lpn_నిడివి_Needed);
  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationW(HANDLE hObj,పూర్ణాంకం n_సూచీ,PVOID pvInfo,DWORD n_నిడివి,LPDWORD lpn_నిడివి_Needed);
  WINUSERAPI WINBOOL WINAPI సమితి_User_Object_Information_A(HANDLE hObj,పూర్ణాంకం n_సూచీ,PVOID pvInfo,DWORD n_నిడివి);
  WINUSERAPI WINBOOL WINAPI సమితి_User_Object_Information_W(HANDLE hObj,పూర్ణాంకం n_సూచీ,PVOID pvInfo,DWORD n_నిడివి);
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_WNDCLASSEXA {
    UINT cb_కొలత;
    UINT style;
    WNDPROC lpfnWndProc;
    పూర్ణాంకం cbClsExtra;
    పూర్ణాంకం cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
  } WNDCLASSEXA,*PWNDCLASSEXA,*NPWNDCLASSEXA,*LPWNDCLASSEXA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_WNDCLASSEXW {
    UINT cb_కొలత;
    UINT style;
    WNDPROC lpfnWndProc;
    పూర్ణాంకం cbClsExtra;
    పూర్ణాంకం cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;

    HICON hIconSm;
  } WNDCLASSEXW,*PWNDCLASSEXW,*NPWNDCLASSEXW,*LPWNDCLASSEXW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WNDCLASSEXW WNDCLASSEX;
  రకనిర్వచనం PWNDCLASSEXW PWNDCLASSEX;
  రకనిర్వచనం NPWNDCLASSEXW NPWNDCLASSEX;
  రకనిర్వచనం LPWNDCLASSEXW LPWNDCLASSEX;
#లేకపోతే
  రకనిర్వచనం WNDCLASSEXA WNDCLASSEX;
  రకనిర్వచనం PWNDCLASSEXA PWNDCLASSEX;
  రకనిర్వచనం NPWNDCLASSEXA NPWNDCLASSEX;
  రకనిర్వచనం LPWNDCLASSEXA LPWNDCLASSEX;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_WNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    పూర్ణాంకం cbClsExtra;
    పూర్ణాంకం cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
  } WNDCLASSA,*PWNDCLASSA,*NPWNDCLASSA,*LPWNDCLASSA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_WNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    పూర్ణాంకం cbClsExtra;
    పూర్ణాంకం cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
  } WNDCLASSW,*PWNDCLASSW,*NPWNDCLASSW,*LPWNDCLASSW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WNDCLASSW WNDCLASS;
  రకనిర్వచనం PWNDCLASSW PWNDCLASS;
  రకనిర్వచనం NPWNDCLASSW NPWNDCLASS;
  రకనిర్వచనం LPWNDCLASSW LPWNDCLASS;
#లేకపోతే
  రకనిర్వచనం WNDCLASSA WNDCLASS;
  రకనిర్వచనం PWNDCLASSA PWNDCLASS;
  రకనిర్వచనం NPWNDCLASSA NPWNDCLASS;
  రకనిర్వచనం LPWNDCLASSA LPWNDCLASS;
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI Is_Hung_App_కిటికీ(HWND hwnd);
  WINUSERAPI VOID WINAPI DisableProcessWindowsGhosting(VOID);

#నిర్వచితం_కాకపోతే NOMSG
  రకనిర్వచనం నిర్మాణం ట్యాగ్_సందేశం {
    HWND hwnd;
    UINT సందేశం_2;
    WPARAM wParam;
    LPARAM lParam;
    DWORD సమయం;
    బిందువు_3 pt;
  } సందేశం_3,*PMSG,*NPMSG,*LPMSG;

#నిర్వచించు POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#నిర్వచించు POINTTOPOINTS(pt) (MAKELONG((పొట్టి)((pt).x),(పొట్టి)((pt).y)))
#నిర్వచించు MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#నిర్వచించు MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#నిర్వచించు MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOWINOFFSETS
#నిర్వచించు GWL_WNDPROC (-4)
#నిర్వచించు GWL_HINSTANCE (-6)
#నిర్వచించు GWL_HWNDPARENT (-8)
#నిర్వచించు GWL_STYLE (-16)
#నిర్వచించు GWL_EXSTYLE (-20)
#నిర్వచించు GWL_USERDATA (-21)
#నిర్వచించు GWL_ID (-12)

#నిర్వచితమైతే _WIN64
#నిర్వచనం_రద్దు GWL_WNDPROC
#నిర్వచనం_రద్దు GWL_HINSTANCE
#నిర్వచనం_రద్దు GWL_HWNDPARENT
#నిర్వచనం_రద్దు GWL_USERDATA
#అయితే_ముగింపు

#నిర్వచించు GWLP_WNDPROC (-4)
#నిర్వచించు GWLP_HINSTANCE (-6)
#నిర్వచించు GWLP_HWNDPARENT (-8)
#నిర్వచించు GWLP_USERDATA (-21)
#నిర్వచించు GWLP_ID (-12)

#నిర్వచించు GCL_MENUNAME (-8)
#నిర్వచించు GCL_HBRBACKGROUND (-10)
#నిర్వచించు GCL_HCURSOR (-12)
#నిర్వచించు GCL_HICON (-14)
#నిర్వచించు GCL_HMODULE (-16)
#నిర్వచించు GCL_CBWNDEXTRA (-18)
#నిర్వచించు GCL_CBCLSEXTRA (-20)
#నిర్వచించు GCL_WNDPROC (-24)
#నిర్వచించు GCL_STYLE (-26)
#నిర్వచించు GCW_ATOM (-32)
#నిర్వచించు GCL_HICONSM (-34)

#నిర్వచితమైతే _WIN64

#నిర్వచనం_రద్దు GCL_MENUNAME
#నిర్వచనం_రద్దు GCL_HBRBACKGROUND
#నిర్వచనం_రద్దు GCL_HCURSOR
#నిర్వచనం_రద్దు GCL_HICON
#నిర్వచనం_రద్దు GCL_HMODULE
#నిర్వచనం_రద్దు GCL_WNDPROC
#నిర్వచనం_రద్దు GCL_HICONSM
#అయితే_ముగింపు

#నిర్వచించు GCLP_MENUNAME (-8)
#నిర్వచించు GCLP_HBRBACKGROUND (-10)
#నిర్వచించు GCLP_HCURSOR (-12)
#నిర్వచించు GCLP_HICON (-14)
#నిర్వచించు GCLP_HMODULE (-16)
#నిర్వచించు GCLP_WNDPROC (-24)
#నిర్వచించు GCLP_HICONSM (-34)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOWINMESSAGES

#నిర్వచించు WM_NULL 0x0000
#నిర్వచించు WM_CREATE 0x0001
#నిర్వచించు WM_DESTROY 0x0002
#నిర్వచించు WM_MOVE 0x0003
#నిర్వచించు WM_కొలత 0x0005

#నిర్వచించు WM_ACTIVATE 0x0006

#నిర్వచించు WA_INACTIVE 0
#నిర్వచించు WA_చురుకైన 1
#నిర్వచించు WA_CLICKACTIVE 2

#నిర్వచించు WM_SETFOCUS 0x0007
#నిర్వచించు WM_KILLFOCUS 0x0008
#నిర్వచించు WM_ENABLE 0x000A
#నిర్వచించు WM_SETREDRAW 0x000B
#నిర్వచించు WM_SETTEXT 0x000C
#నిర్వచించు WM_GETTEXT 0x000D
#నిర్వచించు WM_GETTEXTLENGTH 0x000E
#నిర్వచించు WM_PAINT 0x000F
#నిర్వచించు WM_CLOSE 0x0010
#నిర్వచితం_కాకపోతే _WIN32_WCE
#నిర్వచించు WM_QUERYENDSESSION 0x0011
#నిర్వచించు WM_QUERYOPEN 0x0013
#నిర్వచించు WM_ENDSESSION 0x0016
#అయితే_ముగింపు
#నిర్వచించు WM_QUIT 0x0012
#నిర్వచించు WM_ERASEBKGND 0x0014
#నిర్వచించు WM_SYSCOLORCHANGE 0x0015
#నిర్వచించు WM_SHOWWINDOW 0x0018
#నిర్వచించు WM_WININICHANGE 0x001A
#నిర్వచించు WM_SETTINGCHANGE WM_WININICHANGE
#నిర్వచించు WM_DEVMODECHANGE 0x001B
#నిర్వచించు WM_ACTIVATEAPP 0x001C
#నిర్వచించు WM_FONTCHANGE 0x001D
#నిర్వచించు WM_TIMECHANGE 0x001E
#నిర్వచించు WM_CANCELMODE 0x001F
#నిర్వచించు WM_SETCURSOR 0x0020
#నిర్వచించు WM_MOUSEACTIVATE 0x0021
#నిర్వచించు WM_CHILDACTIVATE 0x0022
#నిర్వచించు WM_QUEUESYNC 0x0023

#నిర్వచించు WM_GETMINMAXINFO 0x0024

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MINMAXINFO {
    బిందువు_3 ptReserved;
    బిందువు_3 pt_Max_కొలత;
    బిందువు_3 ptMaxPosition;
    బిందువు_3 pt_Min_Track_కొలత;
    బిందువు_3 pt_Max_Track_కొలత;
  } MINMAXINFO,*PMINMAXINFO,*LPMINMAXINFO;

#నిర్వచించు WM_PAINTICON 0x0026
#నిర్వచించు WM_ICONERASEBKGND 0x0027
#నిర్వచించు WM_NEXTDLGCTL 0x0028
#నిర్వచించు WM_SPOOLERSTATUS 0x002A
#నిర్వచించు WM_DRAWITEM 0x002B
#నిర్వచించు WM_MEASUREITEM 0x002C
#నిర్వచించు WM_DELETEITEM 0x002D
#నిర్వచించు WM_VKEYTOITEM 0x002E
#నిర్వచించు WM_CHARTOITEM 0x002F
#నిర్వచించు WM_SETFONT 0x0030
#నిర్వచించు WM_GETFONT 0x0031
#నిర్వచించు WM_SETHOTKEY 0x0032
#నిర్వచించు WM_GETHOTKEY 0x0033
#నిర్వచించు WM_QUERYDRAGICON 0x0037
#నిర్వచించు WM_COMPAREITEM 0x0039
#నిర్వచితం_కాకపోతే _WIN32_WCE
#నిర్వచించు WM_GETOBJECT 0x003D
#అయితే_ముగింపు
#నిర్వచించు WM_COMPACTING 0x0041
#నిర్వచించు WM_COMMNOTIFY 0x0044
#నిర్వచించు WM_WINDOWPOSCHANGING 0x0046
#నిర్వచించు WM_WINDOWPOSCHANGED 0x0047

#నిర్వచించు WM_POWER 0x0048

#నిర్వచించు PWR_OK 1
#నిర్వచించు PWR_FAIL (-1)
#నిర్వచించు PWR_SUSPENDREQUEST 1
#నిర్వచించు PWR_SUSPENDRESUME 2
#నిర్వచించు PWR_CRITICALRESUME 3

#నిర్వచించు WM_COPYDATA 0x004A
#నిర్వచించు WM_CANCELJOURNAL 0x004B

  రకనిర్వచనం నిర్మాణం ట్యాగ్_COPYDATASTRUCT {
    ULONG_PTR dw_దత్తాంశం;
    DWORD cb_దత్తాంశం;
    PVOID lp_దత్తాంశం;
  } COPYDATASTRUCT,*PCOPYDATASTRUCT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MDINEXTMENU {
    HMENU hmenu_లోపల;
    HMENU hmenu_తదుపరి;
    HWND hwnd_తదుపరి;
  } MDINEXTMENU,*PMDINEXTMENU,*LPMDINEXTMENU;

#నిర్వచించు WM_NOTIFY 0x004E
#నిర్వచించు WM_INPUTLANGCHANGEREQUEST 0x0050
#నిర్వచించు WM_INPUTLANGCHANGE 0x0051
#నిర్వచించు WM_TCARD 0x0052
#నిర్వచించు WM_HELP 0x0053
#నిర్వచించు WM_USERCHANGED 0x0054
#నిర్వచించు WM_NOTIFYFORMAT 0x0055

#నిర్వచించు NFR_ANSI 1
#నిర్వచించు NFR_UNICODE 2
#నిర్వచించు NF_QUERY 3
#నిర్వచించు NF_REQUERY 4

#నిర్వచించు WM_CONTEXTMENU 0x007B
#నిర్వచించు WM_STYLECHANGING 0x007C
#నిర్వచించు WM_STYLECHANGED 0x007D
#నిర్వచించు WM_DISPLAYCHANGE 0x007E
#నిర్వచించు WM_GETICON 0x007F
#నిర్వచించు WM_SETICON 0x0080

#నిర్వచించు WM_NCCREATE 0x0081
#నిర్వచించు WM_NCDESTROY 0x0082
#నిర్వచించు WM_NCCALCSIZE 0x0083
#నిర్వచించు WM_NCHITTEST 0x0084
#నిర్వచించు WM_NCPAINT 0x0085
#నిర్వచించు WM_NCACTIVATE 0x0086
#నిర్వచించు WM_GETDLGCODE 0x0087
#నిర్వచితం_కాకపోతే _WIN32_WCE
#నిర్వచించు WM_SYNCPAINT 0x0088
#అయితే_ముగింపు
#నిర్వచించు WM_NCMOUSEMOVE 0x00A0
#నిర్వచించు WM_NCLBUTTONDOWN 0x00A1
#నిర్వచించు WM_NCLBUTTONUP 0x00A2
#నిర్వచించు WM_NCLBUTTONDBLCLK 0x00A3
#నిర్వచించు WM_NCRBUTTONDOWN 0x00A4
#నిర్వచించు WM_NCRBUTTONUP 0x00A5
#నిర్వచించు WM_NCRBUTTONDBLCLK 0x00A6
#నిర్వచించు WM_NCMBUTTONDOWN 0x00A7
#నిర్వచించు WM_NCMBUTTONUP 0x00A8
#నిర్వచించు WM_NCMBUTTONDBLCLK 0x00A9

#నిర్వచించు WM_NCXBUTTONDOWN 0x00AB
#నిర్వచించు WM_NCXBUTTONUP 0x00AC
#నిర్వచించు WM_NCXBUTTONDBLCLK 0x00AD
#నిర్వచించు WM_ఆదానం 0x00FF
#నిర్వచించు WM_KEYFIRST 0x0100
#నిర్వచించు WM_KEYDOWN 0x0100
#నిర్వచించు WM_KEYUP 0x0101
#నిర్వచించు WM_CHAR 0x0102
#నిర్వచించు WM_DEADCHAR 0x0103
#నిర్వచించు WM_SYSKEYDOWN 0x0104
#నిర్వచించు WM_SYSKEYUP 0x0105
#నిర్వచించు WM_SYSCHAR 0x0106
#నిర్వచించు WM_SYSDEADCHAR 0x0107
#నిర్వచించు WM_UNICHAR 0x0109
#నిర్వచించు WM_KEYLAST 0x0109
#నిర్వచించు UNICODE_NOCHAR 0xFFFF
#నిర్వచించు WM_IME_STARTCOMPOSITION 0x010D
#నిర్వచించు WM_IME_ENDCOMPOSITION 0x010E
#నిర్వచించు WM_IME_COMPOSITION 0x010F
#నిర్వచించు WM_IME_KEYLAST 0x010F
#నిర్వచించు WM_INITDIALOG 0x0110
#నిర్వచించు WM_COMMAND 0x0111
#నిర్వచించు WM_SYSCOMMAND 0x0112
#నిర్వచించు WM_TIMER 0x0113
#నిర్వచించు WM_HSCROLL 0x0114
#నిర్వచించు WM_VSCROLL 0x0115
#నిర్వచించు WM_INITMENU 0x0116
#నిర్వచించు WM_INITMENUPOPUP 0x0117
#నిర్వచించు WM_MENUSELECT 0x011F
#నిర్వచించు WM_MENUCHAR 0x0120
#నిర్వచించు WM_ENTERIDLE 0x0121
#నిర్వచితం_కాకపోతే _WIN32_WCE
#నిర్వచించు WM_MENURBUTTONUP 0x0122
#నిర్వచించు WM_MENUDRAG 0x0123
#నిర్వచించు WM_MENUGETOBJECT 0x0124
#నిర్వచించు WM_UNINITMENUPOPUP 0x0125
#నిర్వచించు WM_MENUCOMMAND 0x0126

#నిర్వచితం_కాకపోతే _WIN32_WCE
#నిర్వచించు WM_CHANGEUISTATE 0x0127
#నిర్వచించు WM_UPDATEUISTATE 0x0128
#నిర్వచించు WM_QUERYUISTATE 0x0129

#నిర్వచించు UIS_సమితి 1
#నిర్వచించు UIS_CLEAR 2
#నిర్వచించు UIS_INITIALIZE 3

#నిర్వచించు UISF_HIDEFOCUS 0x1
#నిర్వచించు UISF_HIDEACCEL 0x2
#నిర్వచించు UISF_చురుకైన 0x4
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు WM_CTLCOLORMSGBOX 0x0132
#నిర్వచించు WM_CTLCOLOREDIT 0x0133
#నిర్వచించు WM_CTLCOLORLISTBOX 0x0134
#నిర్వచించు WM_CTLCOLORBTN 0x0135
#నిర్వచించు WM_CTLCOLORDLG 0x0136
#నిర్వచించు WM_CTLCOLORSCROLLBAR 0x0137
#నిర్వచించు WM_CTLCOLORSTATIC 0x0138
#నిర్వచించు MN_GETHMENU 0x01E1

#నిర్వచించు WM_MOUSEFIRST 0x0200
#నిర్వచించు WM_MOUSEMOVE 0x0200
#నిర్వచించు WM_LBUTTONDOWN 0x0201
#నిర్వచించు WM_LBUTTONUP 0x0202
#నిర్వచించు WM_LBUTTONDBLCLK 0x0203
#నిర్వచించు WM_RBUTTONDOWN 0x0204
#నిర్వచించు WM_RBUTTONUP 0x0205
#నిర్వచించు WM_RBUTTONDBLCLK 0x0206
#నిర్వచించు WM_MBUTTONDOWN 0x0207
#నిర్వచించు WM_MBUTTONUP 0x0208
#నిర్వచించు WM_MBUTTONDBLCLK 0x0209
#నిర్వచించు WM_MOUSEWHEEL 0x020A
#నిర్వచించు WM_XBUTTONDOWN 0x020B
#నిర్వచించు WM_XBUTTONUP 0x020C
#నిర్వచించు WM_XBUTTONDBLCLK 0x020D
#నిర్వచించు WM_MOUSEHWHEEL 0x020E
#నిర్వచించు WM_MOUSELAST 0x020E

#నిర్వచించు WHEEL_DELTA 120
#నిర్వచించు GET_WHEEL_DELTA_WPARAM(wParam) ((పొట్టి)HIWORD(wParam))

#నిర్వచించు WHEEL_PAGESCROLL (UINT_MAX)

#నిర్వచించు GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#నిర్వచించు GET_NCHITTEST_WPARAM(wParam) ((పొట్టి)LOWORD(wParam))
#నిర్వచించు GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#నిర్వచించు XBUTTON1 0x0001
#నిర్వచించు XBUTTON2 0x0002

#నిర్వచించు WM_PARENTNOTIFY 0x0210
#నిర్వచించు WM_ENTERMENULOOP 0x0211
#నిర్వచించు WM_EXITMENULOOP 0x0212

#నిర్వచించు WM_NEXTMENU 0x0213
#నిర్వచించు WM_SIZING 0x0214
#నిర్వచించు WM_CAPTURECHANGED 0x0215
#నిర్వచించు WM_MOVING 0x0216

#నిర్వచించు WM_POWERBROADCAST 0x0218

#నిర్వచితం_కాకపోతే _WIN32_WCE
#నిర్వచించు PBT_APMQUERYSUSPEND 0x0000
#నిర్వచించు PBT_APMQUERYSTANDBY 0x0001

#నిర్వచించు PBT_APMQUERYSUSPENDFAILED 0x0002
#నిర్వచించు PBT_APMQUERYSTANDBYFAILED 0x0003

#నిర్వచించు PBT_APMSUSPEND 0x0004
#నిర్వచించు PBT_APMSTANDBY 0x0005

#నిర్వచించు PBT_APMRESUMECRITICAL 0x0006
#నిర్వచించు PBT_APMRESUMESUSPEND 0x0007
#నిర్వచించు PBT_APMRESUMESTANDBY 0x0008

#నిర్వచించు PBTF_APMRESUMEFROMFAILURE 0x00000001

#నిర్వచించు PBT_APMBATTERYLOW 0x0009
#నిర్వచించు PBT_APMPOWERSTATUSCHANGE 0x000A

#నిర్వచించు PBT_APMOEMEVENT 0x000B
#నిర్వచించు PBT_APMRESUMEAUTOMATIC 0x0012
#అయితే_ముగింపు

#నిర్వచించు WM_DEVICECHANGE 0x0219

#నిర్వచించు WM_MDICREATE 0x0220
#నిర్వచించు WM_MDIDESTROY 0x0221
#నిర్వచించు WM_MDIACTIVATE 0x0222
#నిర్వచించు WM_MDIRESTORE 0x0223
#నిర్వచించు WM_MDINEXT 0x0224
#నిర్వచించు WM_MDIMAXIMIZE 0x0225
#నిర్వచించు WM_MDITILE 0x0226
#నిర్వచించు WM_MDICASCADE 0x0227
#నిర్వచించు WM_MDIICONARRANGE 0x0228
#నిర్వచించు WM_MDIGETACTIVE 0x0229

#నిర్వచించు WM_MDISETMENU 0x0230
#నిర్వచించు WM_ENTERSIZEMOVE 0x0231
#నిర్వచించు WM_EXITSIZEMOVE 0x0232
#నిర్వచించు WM_DROPFILES 0x0233
#నిర్వచించు WM_MDIREFRESHMENU 0x0234

#నిర్వచించు WM_IME_SETCONTEXT 0x0281
#నిర్వచించు WM_IME_NOTIFY 0x0282
#నిర్వచించు WM_IME_CONTROL 0x0283
#నిర్వచించు WM_IME_COMPOSITIONFULL 0x0284
#నిర్వచించు WM_IME_SELECT 0x0285
#నిర్వచించు WM_IME_CHAR 0x0286
#నిర్వచించు WM_IME_REQUEST 0x0288
#నిర్వచించు WM_IME_KEYDOWN 0x0290
#నిర్వచించు WM_IME_KEYUP 0x0291

#నిర్వచించు WM_MOUSEHOVER 0x02A1
#నిర్వచించు WM_MOUSELEAVE 0x02A3
#నిర్వచించు WM_NCMOUSEHOVER 0x02A0
#నిర్వచించు WM_NCMOUSELEAVE 0x02A2
#నిర్వచించు WM_WTSSESSION_CHANGE 0x02B1
#నిర్వచించు WM_TABLET_మొదటి 0x02c0
#నిర్వచించు WM_TABLET_చివరి 0x02df
#నిర్వచించు WM_CUT 0x0300
#నిర్వచించు WM_COPY 0x0301
#నిర్వచించు WM_PASTE 0x0302
#నిర్వచించు WM_CLEAR 0x0303
#నిర్వచించు WM_UNDO 0x0304
#నిర్వచించు WM_RENDERFORMAT 0x0305
#నిర్వచించు WM_RENDERALLFORMATS 0x0306
#నిర్వచించు WM_DESTROYCLIPBOARD 0x0307
#నిర్వచించు WM_DRAWCLIPBOARD 0x0308
#నిర్వచించు WM_PAINTCLIPBOARD 0x0309
#నిర్వచించు WM_VSCROLLCLIPBOARD 0x030A
#నిర్వచించు WM_SIZECLIPBOARD 0x030B
#నిర్వచించు WM_ASKCBFORMATNAME 0x030C
#నిర్వచించు WM_CHANGECBCHAIN 0x030D
#నిర్వచించు WM_HSCROLLCLIPBOARD 0x030E
#నిర్వచించు WM_QUERYNEWPALETTE 0x030F
#నిర్వచించు WM_PALETTEISCHANGING 0x0310
#నిర్వచించు WM_PALETTECHANGED 0x0311
#నిర్వచించు WM_HOTKEY 0x0312
#నిర్వచించు WM_PRINT 0x0317
#నిర్వచించు WM_PRINTCLIENT 0x0318
#నిర్వచించు WM_APPCOMMAND 0x0319
#నిర్వచించు WM_THEMECHANGED 0x031A
#నిర్వచించు WM_HANDHELDFIRST 0x0358
#నిర్వచించు WM_HANDHELDLAST 0x035F
#నిర్వచించు WM_AFXFIRST 0x0360
#నిర్వచించు WM_AFXLAST 0x037F
#నిర్వచించు WM_PENWINFIRST 0x0380
#నిర్వచించు WM_PENWINLAST 0x038F
#నిర్వచించు WM_APP 0x8000
#నిర్వచించు WM_USER 0x0400

#నిర్వచించు WMSZ_ఎడమ 1
#నిర్వచించు WMSZ_కుడి 2
#నిర్వచించు WMSZ_శిఖరం 3
#నిర్వచించు WMSZ_TOPLEFT 4
#నిర్వచించు WMSZ_TOPRIGHT 5
#నిర్వచించు WMSZ_BOTTOM 6
#నిర్వచించు WMSZ_BOTTOMLEFT 7
#నిర్వచించు WMSZ_BOTTOMRIGHT 8

#నిర్వచితం_కాకపోతే NONCMESSAGES

#నిర్వచించు HTERROR (-2)
#నిర్వచించు HTTRANSPARENT (-1)
#నిర్వచించు HTNOWHERE 0
#నిర్వచించు HTCLIENT 1
#నిర్వచించు HTCAPTION 2
#నిర్వచించు HTSYSMENU 3
#నిర్వచించు HTGROWBOX 4
#నిర్వచించు HTSIZE HTGROWBOX
#నిర్వచించు HTMENU 5
#నిర్వచించు HTHSCROLL 6
#నిర్వచించు HTVSCROLL 7
#నిర్వచించు HTMINBUTTON 8
#నిర్వచించు HTMAXBUTTON 9
#నిర్వచించు HTLEFT 10
#నిర్వచించు HTRIGHT 11
#నిర్వచించు HTTOP 12
#నిర్వచించు HTTOPLEFT 13
#నిర్వచించు HTTOPRIGHT 14
#నిర్వచించు HTBOTTOM 15
#నిర్వచించు HTBOTTOMLEFT 16
#నిర్వచించు HTBOTTOMRIGHT 17
#నిర్వచించు HTBORDER 18
#నిర్వచించు HTREDUCE HTMINBUTTON
#నిర్వచించు HTZOOM HTMAXBUTTON
#నిర్వచించు HTSIZEFIRST HTLEFT
#నిర్వచించు HTSIZELAST HTBOTTOMRIGHT
#నిర్వచించు HTOBJECT 19
#నిర్వచించు HTCLOSE 20
#నిర్వచించు HTHELP 21

#నిర్వచించు SMTO_సాధారణ 0x0000
#నిర్వచించు SMTO_ఖండం 0x0001
#నిర్వచించు SMTO_ABORTIFHUNG 0x0002
#నిర్వచించు SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#అయితే_ముగింపు

#నిర్వచించు MA_ACTIVATE 1
#నిర్వచించు MA_ACTIVATEANDEAT 2
#నిర్వచించు MA_NOACTIVATE 3
#నిర్వచించు MA_NOACTIVATEANDEAT 4

#నిర్వచించు ICON_SMALL 0
#నిర్వచించు ICON_BIG 1
#నిర్వచించు ICON_SMALL2 2

#నిర్వచితమైతే UNICODE
#నిర్వచించు రిజిస్టరు_కిటికీ_సందేశం రిజిస్టరు_కిటికీ_సందేశం_W
#లేకపోతే
#నిర్వచించు రిజిస్టరు_కిటికీ_సందేశం రిజిస్టరు_కిటికీ_సందేశం_A
#అయితే_ముగింపు

  WINUSERAPI UINT WINAPI రిజిస్టరు_కిటికీ_సందేశం_A(LPCSTR lpString);
  WINUSERAPI UINT WINAPI రిజిస్టరు_కిటికీ_సందేశం_W(LPCWSTR lpString);

#నిర్వచించు కొలత_RESTORED 0
#నిర్వచించు కొలత_MINIMIZED 1
#నిర్వచించు కొలత_MAXIMIZED 2
#నిర్వచించు కొలత_MAXSHOW 3
#నిర్వచించు కొలత_MAXHIDE 4

#నిర్వచించు SIZENORMAL కొలత_RESTORED
#నిర్వచించు SIZEICONIC కొలత_MINIMIZED
#నిర్వచించు SIZEFULLSCREEN కొలత_MAXIMIZED
#నిర్వచించు SIZEZOOMSHOW కొలత_MAXSHOW
#నిర్వచించు SIZEZOOMHIDE కొలత_MAXHIDE

  రకనిర్వచనం నిర్మాణం ట్యాగ్_WINDOWPOS {
    HWND hwnd;
    HWND hwnd_చొప్పించు_After;
    పూర్ణాంకం x;
    పూర్ణాంకం y;
    పూర్ణాంకం cx;
    పూర్ణాంకం cy;
    UINT flags;
  } WINDOWPOS,*LPWINDOWPOS,*PWINDOWPOS;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_NCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
  } NCCALCSIZE_PARAMS,*LPNCCALCSIZE_PARAMS;

#నిర్వచించు WVR_ALIGNTOP 0x0010
#నిర్వచించు WVR_ALIGNLEFT 0x0020
#నిర్వచించు WVR_ALIGNBOTTOM 0x0040
#నిర్వచించు WVR_ALIGNRIGHT 0x0080
#నిర్వచించు WVR_HREDRAW 0x0100
#నిర్వచించు WVR_VREDRAW 0x0200
#నిర్వచించు WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#నిర్వచించు WVR_VALIDRECTS 0x0400

#నిర్వచితం_కాకపోతే NOKEYSTATES

#నిర్వచించు MK_LBUTTON 0x0001
#నిర్వచించు MK_RBUTTON 0x0002
#నిర్వచించు MK_జరుపు 0x0004
#నిర్వచించు MK_CONTROL 0x0008
#నిర్వచించు MK_MBUTTON 0x0010
#నిర్వచించు MK_XBUTTON1 0x0020
#నిర్వచించు MK_XBUTTON2 0x0040
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOTRACKMOUSEEVENT
#నిర్వచించు TME_HOVER 0x00000001
#నిర్వచించు TME_LEAVE 0x00000002
#నిర్వచించు TME_NONCLIENT 0x00000010
#నిర్వచించు TME_QUERY 0x40000000
#నిర్వచించు TME_CANCEL 0x80000000

#నిర్వచించు HOVER_DEFAULT 0xFFFFFFFF
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_TRACKMOUSEEVENT {
    DWORD cb_కొలత;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dw_Hover_సమయం;
  } TRACKMOUSEEVENT,*LPTRACKMOUSEEVENT;

  WINUSERAPI WINBOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOWINSTYLES

#నిర్వచించు WS_OVERLAPPED 0x00000000L
#నిర్వచించు WS_POPUP 0x80000000L
#నిర్వచించు WS_బిడ్డ 0x40000000L
#నిర్వచించు WS_MINIMIZE 0x20000000L
#నిర్వచించు WS_VISIBLE 0x10000000L
#నిర్వచించు WS_DISABLED 0x08000000L
#నిర్వచించు WS_CLIPSIBLINGS 0x04000000L
#నిర్వచించు WS_CLIPCHILDREN 0x02000000L
#నిర్వచించు WS_MAXIMIZE 0x01000000L
#నిర్వచించు WS_CAPTION 0x00C00000L
#నిర్వచించు WS_BORDER 0x00800000L
#నిర్వచించు WS_DLGFRAME 0x00400000L
#నిర్వచించు WS_VSCROLL 0x00200000L
#నిర్వచించు WS_HSCROLL 0x00100000L
#నిర్వచించు WS_SYSMENU 0x00080000L
#నిర్వచించు WS_THICKFRAME 0x00040000L
#నిర్వచించు WS_సమూహం 0x00020000L
#నిర్వచించు WS_TABSTOP 0x00010000L
#నిర్వచించు WS_MINIMIZEBOX 0x00020000L
#నిర్వచించు WS_MAXIMIZEBOX 0x00010000L
#నిర్వచించు WS_TILED WS_OVERLAPPED
#నిర్వచించు WS_ICONIC WS_MINIMIZE
#నిర్వచించు WS_SIZEBOX WS_THICKFRAME
#నిర్వచించు WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#నిర్వచించు WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#నిర్వచించు WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#నిర్వచించు WS_CHILDWINDOW (WS_బిడ్డ)

#నిర్వచించు WS_EX_DLGMODALFRAME 0x00000001L
#నిర్వచించు WS_EX_NOPARENTNOTIFY 0x00000004L
#నిర్వచించు WS_EX_TOPMOST 0x00000008L
#నిర్వచించు WS_EX_ACCEPTFILES 0x00000010L
#నిర్వచించు WS_EX_TRANSPARENT 0x00000020L
#నిర్వచించు WS_EX_MDICHILD 0x00000040L
#నిర్వచించు WS_EX_TOOLWINDOW 0x00000080L
#నిర్వచించు WS_EX_WINDOWEDGE 0x00000100L
#నిర్వచించు WS_EX_CLIENTEDGE 0x00000200L
#నిర్వచించు WS_EX_CONTEXTHELP 0x00000400L
#నిర్వచించు WS_EX_కుడి 0x00001000L
#నిర్వచించు WS_EX_ఎడమ 0x00000000L
#నిర్వచించు WS_EX_RTLREADING 0x00002000L
#నిర్వచించు WS_EX_LTRREADING 0x00000000L
#నిర్వచించు WS_EX_LEFTSCROLLBAR 0x00004000L
#నిర్వచించు WS_EX_RIGHTSCROLLBAR 0x00000000L
#నిర్వచించు WS_EX_CONTROLPARENT 0x00010000L
#నిర్వచించు WS_EX_STATICEDGE 0x00020000L
#నిర్వచించు WS_EX_APPWINDOW 0x00040000L
#నిర్వచించు WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#నిర్వచించు WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#నిర్వచించు WS_EX_LAYERED 0x00080000
#నిర్వచించు WS_EX_NOINHERITLAYOUT 0x00100000L
#నిర్వచించు WS_EX_LAYOUTRTL 0x00400000L
#నిర్వచించు WS_EX_COMPOSITED 0x02000000L
#నిర్వచించు WS_EX_NOACTIVATE 0x08000000L

#నిర్వచించు CS_VREDRAW 0x0001
#నిర్వచించు CS_HREDRAW 0x0002
#నిర్వచించు CS_DBLCLKS 0x0008
#నిర్వచించు CS_OWNDC 0x0020
#నిర్వచించు CS_CLASSDC 0x0040
#నిర్వచించు CS_PARENTDC 0x0080
#నిర్వచించు CS_NOCLOSE 0x0200
#నిర్వచించు CS_SAVEBITS 0x0800
#నిర్వచించు CS_BYTEALIGNCLIENT 0x1000
#నిర్వచించు CS_BYTEALIGNWINDOW 0x2000
#నిర్వచించు CS_GLOBALCLASS 0x4000
#నిర్వచించు CS_IME 0x00010000
#నిర్వచించు CS_DROPSHADOW 0x00020000
#అయితే_ముగింపు

#నిర్వచించు PRF_CHECKVISIBLE 0x00000001L
#నిర్వచించు PRF_NONCLIENT 0x00000002L
#నిర్వచించు PRF_CLIENT 0x00000004L
#నిర్వచించు PRF_ERASEBKGND 0x00000008L
#నిర్వచించు PRF_CHILDREN 0x00000010L
#నిర్వచించు PRF_OWNED 0x00000020L

#నిర్వచించు BDR_RAISEDOUTER 0x0001
#నిర్వచించు BDR_SUNKENOUTER 0x0002
#నిర్వచించు BDR_RAISEDINNER 0x0004
#నిర్వచించు BDR_SUNKENINNER 0x0008

#నిర్వచించు BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#నిర్వచించు BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#నిర్వచించు BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#నిర్వచించు BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#నిర్వచించు అంచు_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#నిర్వచించు అంచు_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#నిర్వచించు అంచు_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#నిర్వచించు అంచు_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#నిర్వచించు BF_ఎడమ 0x0001
#నిర్వచించు BF_శిఖరం 0x0002
#నిర్వచించు BF_కుడి 0x0004
#నిర్వచించు BF_BOTTOM 0x0008

#నిర్వచించు BF_TOPLEFT (BF_శిఖరం | BF_ఎడమ)
#నిర్వచించు BF_TOPRIGHT (BF_శిఖరం | BF_కుడి)
#నిర్వచించు BF_BOTTOMLEFT (BF_BOTTOM | BF_ఎడమ)
#నిర్వచించు BF_BOTTOMRIGHT (BF_BOTTOM | BF_కుడి)
#నిర్వచించు BF_RECT (BF_ఎడమ | BF_శిఖరం | BF_కుడి | BF_BOTTOM)

#నిర్వచించు BF_DIAGONAL 0x0010

#నిర్వచించు BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_శిఖరం | BF_కుడి)
#నిర్వచించు BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_శిఖరం | BF_ఎడమ)
#నిర్వచించు BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_ఎడమ)
#నిర్వచించు BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_కుడి)

#నిర్వచించు BF_మధ్య 0x0800
#నిర్వచించు BF_SOFT 0x1000
#నిర్వచించు BF_ADJUST 0x2000
#నిర్వచించు BF_FLAT 0x4000
#నిర్వచించు BF_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_అంచు(HDC hdc,LPRECT qrc,UINT అంచు,UINT grfFlags);

#నిర్వచించు DFC_CAPTION 1
#నిర్వచించు DFC_MENU 2
#నిర్వచించు DFC_SCROLL 3
#నిర్వచించు DFC_BUTTON 4
#నిర్వచించు DFC_POPUPMENU 5

#నిర్వచించు DFCS_CAPTIONCLOSE 0x0000
#నిర్వచించు DFCS_CAPTIONMIN 0x0001
#నిర్వచించు DFCS_CAPTIONMAX 0x0002
#నిర్వచించు DFCS_CAPTIONRESTORE 0x0003
#నిర్వచించు DFCS_CAPTIONHELP 0x0004

#నిర్వచించు DFCS_MENUARROW 0x0000
#నిర్వచించు DFCS_MENUCHECK 0x0001
#నిర్వచించు DFCS_MENUBULLET 0x0002
#నిర్వచించు DFCS_MENUARROWRIGHT 0x0004
#నిర్వచించు DFCS_SCROLLUP 0x0000
#నిర్వచించు DFCS_SCROLLDOWN 0x0001
#నిర్వచించు DFCS_SCROLLLEFT 0x0002
#నిర్వచించు DFCS_SCROLLRIGHT 0x0003
#నిర్వచించు DFCS_SCROLLCOMBOBOX 0x0005
#నిర్వచించు DFCS_SCROLLSIZEGRIP 0x0008
#నిర్వచించు DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#నిర్వచించు DFCS_BUTTONCHECK 0x0000
#నిర్వచించు DFCS_BUTTONRADIOIMAGE 0x0001
#నిర్వచించు DFCS_BUTTONRADIOMASK 0x0002
#నిర్వచించు DFCS_BUTTONRADIO 0x0004
#నిర్వచించు DFCS_BUTTON3STATE 0x0008
#నిర్వచించు DFCS_BUTTONPUSH 0x0010

#నిర్వచించు DFCS_INACTIVE 0x0100
#నిర్వచించు DFCS_PUSHED 0x0200
#నిర్వచించు DFCS_CHECKED 0x0400

#నిర్వచించు DFCS_TRANSPARENT 0x0800
#నిర్వచించు DFCS_HOT 0x1000

#నిర్వచించు DFCS_ADJUSTRECT 0x2000
#నిర్వచించు DFCS_FLAT 0x4000
#నిర్వచించు DFCS_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_చట్రం_Control(HDC,LPRECT,UINT,UINT);

#నిర్వచించు DC_చురుకైన 0x0001
#నిర్వచించు DC_SMALLCAP 0x0002
#నిర్వచించు DC_ICON 0x0004
#నిర్వచించు DC_పాఠ్యం 0x0008
#నిర్వచించు DC_INBUTTON 0x0010
#నిర్వచించు DC_GRADIENT 0x0020
#నిర్వచించు DC_BUTTONS 0x1000

  WINUSERAPI WINBOOL WINAPI DrawCaption(HWND hwnd,HDC hdc,CONST RECT *lprect,UINT flags);

#నిర్వచించు IDANI_OPEN 1
#నిర్వచించు IDANI_CAPTION 3

  WINUSERAPI WINBOOL WINAPI DrawAnimatedRects(HWND hwnd,పూర్ణాంకం idAni,CONST RECT *lprcFrom,CONST RECT *lprc_గమ్యం);

#నిర్వచితం_కాకపోతే NOCLIPBOARD

#నిర్వచించు CF_పాఠ్యం 1
#నిర్వచించు CF_BITMAP 2
#నిర్వచించు CF_METAFILEPICT 3
#నిర్వచించు CF_SYLK 4
#నిర్వచించు CF_DIF 5
#నిర్వచించు CF_TIFF 6
#నిర్వచించు CF_OEMTEXT 7
#నిర్వచించు CF_DIB 8
#నిర్వచించు CF_PALETTE 9
#నిర్వచించు CF_PENDATA 10
#నిర్వచించు CF_RIFF 11
#నిర్వచించు CF_WAVE 12
#నిర్వచించు CF_UNICODETEXT 13
#నిర్వచించు CF_ENHMETAFILE 14
#నిర్వచించు CF_HDROP 15
#నిర్వచించు CF_LOCALE 16
#నిర్వచించు CF_DIBV5 17
#నిర్వచించు CF_MAX 18

#నిర్వచించు CF_OWNERDISPLAY 0x0080
#నిర్వచించు CF_DSPTEXT 0x0081
#నిర్వచించు CF_DSPBITMAP 0x0082
#నిర్వచించు CF_DSPMETAFILEPICT 0x0083
#నిర్వచించు CF_DSPENHMETAFILE 0x008E

#నిర్వచించు CF_PRIVATEFIRST 0x0200
#నిర్వచించు CF_PRIVATELAST 0x02FF

#నిర్వచించు CF_GDIOBJFIRST 0x0300
#నిర్వచించు CF_GDIOBJLAST 0x03FF
#అయితే_ముగింపు

#నిర్వచించు FVIRTKEY TRUE
#నిర్వచించు FNOINVERT 0x02
#నిర్వచించు FSHIFT 0x04
#నిర్వచించు FCONTROL 0x08
#నిర్వచించు FALT 0x10

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ACCEL {
    BYTE fVirt;
    మాట_3 కీలకం;
    మాట_3 cmd;
  } ACCEL,*LPACCEL;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_PAINTSTRUCT {
    HDC hdc;
    WINBOOL fErase;
    RECT rcPaint;
    WINBOOL fRestore;
    WINBOOL fIncUpdate;
    BYTE rgbReserved[32];
  } PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CREATESTRUCTA {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_మాతృ_2;
    పూర్ణాంకం cy;
    పూర్ణాంకం cx;
    పూర్ణాంకం y;
    పూర్ణాంకం x;
    LONG style;
    LPCSTR lpszName;
    LPCSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTA,*LPCREATESTRUCTA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_మాతృ_2;
    పూర్ణాంకం cy;
    పూర్ణాంకం cx;
    పూర్ణాంకం y;
    పూర్ణాంకం x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTW,*LPCREATESTRUCTW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం CREATESTRUCTW CREATESTRUCT;
  రకనిర్వచనం LPCREATESTRUCTW LPCREATESTRUCT;
#లేకపోతే
  రకనిర్వచనం CREATESTRUCTA CREATESTRUCT;
  రకనిర్వచనం LPCREATESTRUCTA LPCREATESTRUCT;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_WINDOWPLACEMENT {
    UINT నిడివి;
    UINT flags;
    UINT showCmd;
    బిందువు_3 ptMinPosition;
    బిందువు_3 ptMaxPosition;
    RECT rc_సాధారణ_Position;
  } WINDOWPLACEMENT;
  రకనిర్వచనం WINDOWPLACEMENT *PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;

#నిర్వచించు WPF_SETMINPOSITION 0x0001
#నిర్వచించు WPF_RESTORETOMAXIMIZED 0x0002
#నిర్వచించు WPF_ASYNCWINDOWPLACEMENT 0x0004

  రకనిర్వచనం నిర్మాణం ట్యాగ్_NMHDR {
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT సంకేతం_2;
  } NMHDR;

  రకనిర్వచనం NMHDR *LPNMHDR;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_STYLESTRUCT {
    DWORD styleOld;
    DWORD styleNew;
  } STYLESTRUCT,*LPSTYLESTRUCT;

#నిర్వచించు ODT_MENU 1
#నిర్వచించు ODT_LISTBOX 2
#నిర్వచించు ODT_COMBOBOX 3
#నిర్వచించు ODT_BUTTON 4
#నిర్వచించు ODT_STATIC 5

#నిర్వచించు ODA_DRAWENTIRE 0x0001
#నిర్వచించు ODA_SELECT 0x0002
#నిర్వచించు ODA_FOCUS 0x0004

#నిర్వచించు ODS_SELECTED 0x0001
#నిర్వచించు ODS_GRAYED 0x0002
#నిర్వచించు ODS_DISABLED 0x0004
#నిర్వచించు ODS_CHECKED 0x0008
#నిర్వచించు ODS_FOCUS 0x0010
#నిర్వచించు ODS_DEFAULT 0x0020
#నిర్వచించు ODS_COMBOBOXEDIT 0x1000
#నిర్వచించు ODS_HOTLIGHT 0x0040
#నిర్వచించు ODS_INACTIVE 0x0080
#నిర్వచించు ODS_NOACCEL 0x0100
#నిర్వచించు ODS_NOFOCUSRECT 0x0200

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT అంశం_ID;
    UINT అంశం_వెడల్పు;
    UINT అంశం_ఎత్తు;
    ULONG_PTR అంశం_దత్తాంశం;
  } MEASUREITEMSTRUCT,*PMEASUREITEMSTRUCT,*LPMEASUREITEMSTRUCT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_DRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT అంశం_ID;
    UINT అంశం_Action;
    UINT అంశం_State;
    HWND hwnd_అంశం;
    HDC hDC;
    RECT rc_అంశం;
    ULONG_PTR అంశం_దత్తాంశం;
  } DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_DELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT అంశం_ID;
    HWND hwnd_అంశం;
    ULONG_PTR అంశం_దత్తాంశం;
  } DELETEITEMSTRUCT,*PDELETEITEMSTRUCT,*LPDELETEITEMSTRUCT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_COMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwnd_అంశం;
    UINT అంశం_ID1;
    ULONG_PTR అంశం_Data1;
    UINT అంశం_ID2;
    ULONG_PTR అంశం_Data2;
    DWORD dwLocaleId;
  } COMPAREITEMSTRUCT,*PCOMPAREITEMSTRUCT,*LPCOMPAREITEMSTRUCT;

#నిర్వచితం_కాకపోతే NOMSG
#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_సందేశం Get_సందేశం_W
#నిర్వచించు Dispatch_సందేశం Dispatch_సందేశం_W
#నిర్వచించు Peek_సందేశం Peek_సందేశం_W
#లేకపోతే
#నిర్వచించు Get_సందేశం Get_సందేశం_A
#నిర్వచించు Dispatch_సందేశం Dispatch_సందేశం_A
#నిర్వచించు Peek_సందేశం Peek_సందేశం_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI Get_సందేశం_A(LPMSG lp_సందేశం_2,HWND hWnd,UINT w_సందేశం_Filter_Min,UINT w_సందేశం_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Get_సందేశం_W(LPMSG lp_సందేశం_2,HWND hWnd,UINT w_సందేశం_Filter_Min,UINT w_సందేశం_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Translate_సందేశం(CONST సందేశం_3 *lp_సందేశం_2);
  WINUSERAPI LRESULT WINAPI Dispatch_సందేశం_A(CONST సందేశం_3 *lp_సందేశం_2);
  WINUSERAPI LRESULT WINAPI Dispatch_సందేశం_W(CONST సందేశం_3 *lp_సందేశం_2);
  WINUSERAPI WINBOOL WINAPI సమితి_సందేశం_వరుస(పూర్ణాంకం cMessagesMax);
  WINUSERAPI WINBOOL WINAPI Peek_సందేశం_A(LPMSG lp_సందేశం_2,HWND hWnd,UINT w_సందేశం_Filter_Min,UINT w_సందేశం_Filter_Max,UINT w_Remove_సందేశం);
  WINUSERAPI WINBOOL WINAPI Peek_సందేశం_W(LPMSG lp_సందేశం_2,HWND hWnd,UINT w_సందేశం_Filter_Min,UINT w_సందేశం_Filter_Max,UINT w_Remove_సందేశం);

#నిర్వచించు PM_NOREMOVE 0x0000
#నిర్వచించు PM_REMOVE 0x0001
#నిర్వచించు PM_NOYIELD 0x0002
#నిర్వచించు PM_QS_ఆదానం (QS_ఆదానం << 16)
#నిర్వచించు PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#నిర్వచించు PM_QS_PAINT (QS_PAINT << 16)
#నిర్వచించు PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI రిజిస్టరు_Hot_కీలకం(HWND hWnd,పూర్ణాంకం id,UINT fsModifiers,UINT vk);
  WINUSERAPI WINBOOL WINAPI Unregister_Hot_కీలకం(HWND hWnd,పూర్ణాంకం id);

#నిర్వచించు MOD_ALT 0x0001
#నిర్వచించు MOD_CONTROL 0x0002
#నిర్వచించు MOD_జరుపు 0x0004
#నిర్వచించు MOD_WIN 0x0008

#నిర్వచించు IDHOT_SNAPWINDOW (-1)
#నిర్వచించు IDHOT_SNAPDESKTOP (-2)

#నిర్వచితమైతే WIN_అంతర్గత
#నిర్వచితం_కాకపోతే LSTRING
#నిర్వచించు NOLSTRING
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే LFILEIO
#నిర్వచించు NOLFILEIO
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు ENDSESSION_LOGOFF 0x80000000

#నిర్వచించు EWX_LOGOFF 0
#నిర్వచించు EWX_SHUTDOWN 0x00000001
#నిర్వచించు EWX_REBOOT 0x00000002
#నిర్వచించు EWX_FORCE 0x00000004
#నిర్వచించు EWX_POWEROFF 0x00000008
#నిర్వచించు EWX_FORCEIFHUNG 0x00000010

#నిర్వచించు ExitWindows(dwReserved,సంకేతం_5) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#నిర్వచితమైతే UNICODE
#నిర్వచించు Send_సందేశం Send_సందేశం_W
#నిర్వచించు Send_సందేశం_Timeout Send_సందేశం_Timeout_W
#నిర్వచించు Send_Notify_సందేశం Send_Notify_సందేశం_W
#నిర్వచించు Send_సందేశం_Callback Send_సందేశం_Callback_W
#లేకపోతే
#నిర్వచించు Send_సందేశం Send_సందేశం_A
#నిర్వచించు Send_సందేశం_Timeout Send_సందేశం_Timeout_A
#నిర్వచించు Send_Notify_సందేశం Send_Notify_సందేశం_A
#నిర్వచించు Send_సందేశం_Callback Send_సందేశం_Callback_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI ExitWindowsEx(UINT uFlags,DWORD dwReason);
  WINUSERAPI WINBOOL WINAPI మార్పిడి_Mouse_Button(WINBOOL f_మార్పిడి);
  WINUSERAPI DWORD WINAPI Get_సందేశం_Pos(VOID);
  WINUSERAPI LONG WINAPI Get_సందేశం_సమయం(VOID);
  WINUSERAPI LPARAM WINAPI Get_సందేశం_Extra_Info(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Wow64_సందేశం(VOID);
  WINUSERAPI LPARAM WINAPI సమితి_సందేశం_Extra_Info(LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_సందేశం_A(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_సందేశం_W(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_సందేశం_Timeout_A(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_ఫలితం);
  WINUSERAPI LRESULT WINAPI Send_సందేశం_Timeout_W(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_ఫలితం);
  WINUSERAPI WINBOOL WINAPI Send_Notify_సందేశం_A(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_Notify_సందేశం_W(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_సందేశం_Callback_A(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_ఫలితం_Call_వెనుక,ULONG_PTR dw_దత్తాంశం);
  WINUSERAPI WINBOOL WINAPI Send_సందేశం_Callback_W(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_ఫలితం_Call_వెనుక,ULONG_PTR dw_దత్తాంశం);

  రకనిర్వచనం నిర్మాణం {
    UINT cb_కొలత;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
  } BSMINFO,*PBSMINFO;

#నిర్వచితమైతే UNICODE
#నిర్వచించు ప్రసారం_System_సందేశం_Ex ప్రసారం_System_సందేశం_Ex_W
#నిర్వచించు ప్రసారం_System_సందేశం ప్రసారం_System_సందేశం_W
#లేకపోతే
#నిర్వచించు ప్రసారం_System_సందేశం_Ex ప్రసారం_System_సందేశం_Ex_A
#నిర్వచించు ప్రసారం_System_సందేశం ప్రసారం_System_సందేశం_A
#అయితే_ముగింపు

  WINUSERAPI దీర్ఘ WINAPI ప్రసారం_System_సందేశం_Ex_A(DWORD flags,LPDWORD lpInfo,UINT సందేశం_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI దీర్ఘ WINAPI ప్రసారం_System_సందేశం_Ex_W(DWORD flags,LPDWORD lpInfo,UINT సందేశం_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI దీర్ఘ WINAPI ప్రసారం_System_సందేశం_A(DWORD flags,LPDWORD lpInfo,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI దీర్ఘ WINAPI ప్రసారం_System_సందేశం_W(DWORD flags,LPDWORD lpInfo,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);

#నిర్వచించు BSM_ALLCOMPONENTS 0x00000000
#నిర్వచించు BSM_VXDS 0x00000001
#నిర్వచించు BSM_NETDRIVER 0x00000002
#నిర్వచించు BSM_INSTALLABLEDRIVERS 0x00000004
#నిర్వచించు BSM_APPLICATIONS 0x00000008
#నిర్వచించు BSM_ALLDESKTOPS 0x00000010

#నిర్వచించు BSF_QUERY 0x00000001
#నిర్వచించు BSF_IGNORECURRENTTASK 0x00000002
#నిర్వచించు BSF_FLUSHDISK 0x00000004
#నిర్వచించు BSF_NOHANG 0x00000008
#నిర్వచించు BSF_POSTMESSAGE 0x00000010
#నిర్వచించు BSF_FORCEIFHUNG 0x00000020
#నిర్వచించు BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#నిర్వచించు BSF_ALLOWSFW 0x00000080
#నిర్వచించు BSF_SENDNOTIFYMESSAGE 0x00000100
#నిర్వచించు BSF_RETURNHDESK 0x00000200
#నిర్వచించు BSF_LUID 0x00000400

#నిర్వచించు ప్రసారం_QUERY_DENY 0x424D5144

  రకనిర్వచనం PVOID HDEVNOTIFY;
  రకనిర్వచనం HDEVNOTIFY *PHDEVNOTIFY;

#నిర్వచించు DEVICE_NOTIFY_కిటికీ_HANDLE 0x00000000
#నిర్వచించు DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#నిర్వచించు DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#నిర్వచితమైతే UNICODE
#నిర్వచించు రిజిస్టరు_Device_Notification రిజిస్టరు_Device_Notification_W
#నిర్వచించు Post_సందేశం Post_సందేశం_W
#నిర్వచించు Post_Thread_సందేశం Post_Thread_సందేశం_W
#నిర్వచించు Post_App_సందేశం Post_App_సందేశం_W
#నిర్వచించు Def_కిటికీ_Proc Def_కిటికీ_Proc_W
#నిర్వచించు Call_కిటికీ_Proc Call_కిటికీ_Proc_W
#నిర్వచించు రిజిస్టరు_Class రిజిస్టరు_Class_W
#నిర్వచించు UnregisterClass UnregisterClassW
#నిర్వచించు GetClassInfo GetClassInfoW
#నిర్వచించు రిజిస్టరు_Class_Ex రిజిస్టరు_Class_Ex_W
#నిర్వచించు GetClassInfoEx GetClassInfoExW
#లేకపోతే
#నిర్వచించు రిజిస్టరు_Device_Notification రిజిస్టరు_Device_Notification_A
#నిర్వచించు Post_సందేశం Post_సందేశం_A
#నిర్వచించు Post_Thread_సందేశం Post_Thread_సందేశం_A
#నిర్వచించు Post_App_సందేశం Post_App_సందేశం_A
#నిర్వచించు Def_కిటికీ_Proc Def_కిటికీ_Proc_A
#నిర్వచించు Call_కిటికీ_Proc Call_కిటికీ_Proc_A
#నిర్వచించు రిజిస్టరు_Class రిజిస్టరు_Class_A
#నిర్వచించు UnregisterClass UnregisterClassA
#నిర్వచించు GetClassInfo GetClassInfoA
#నిర్వచించు రిజిస్టరు_Class_Ex రిజిస్టరు_Class_Ex_A
#నిర్వచించు GetClassInfoEx GetClassInfoExA
#అయితే_ముగింపు

  WINUSERAPI HDEVNOTIFY WINAPI రిజిస్టరు_Device_Notification_A(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI HDEVNOTIFY WINAPI రిజిస్టరు_Device_Notification_W(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI WINBOOL WINAPI UnregisterDeviceNotification(HDEVNOTIFY Handle);
  WINUSERAPI WINBOOL WINAPI Post_సందేశం_A(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_సందేశం_W(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_సందేశం_A(DWORD idThread,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_సందేశం_W(DWORD idThread,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
#నిర్వచించు Post_App_సందేశం_A(idThread,w_సందేశం,wParam,lParam) Post_Thread_సందేశం_A((DWORD)idThread,w_సందేశం,wParam,lParam)
#నిర్వచించు Post_App_సందేశం_W(idThread,w_సందేశం,wParam,lParam) Post_Thread_సందేశం_W((DWORD)idThread,w_సందేశం,wParam,lParam)

#నిర్వచించు HWND_ప్రసారం ((HWND)0xffff)
#నిర్వచించు HWND_సందేశం ((HWND)-3)

  WINUSERAPI WINBOOL WINAPI Attach_Thread_ఆదానం(DWORD idAttach,DWORD id_Attach_గమ్యం,WINBOOL fAttach);
  WINUSERAPI WINBOOL WINAPI జవాబు_సందేశం(LRESULT l_ఫలితం);
  WINUSERAPI WINBOOL WINAPI Wait_సందేశం(VOID);
  WINUSERAPI DWORD WINAPI Wait_For_ఆదానం_Idle(HANDLE hProcess,DWORD dwMilliseconds);
  WINUSERAPI LRESULT WINAPI Def_కిటికీ_Proc_A(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_కిటికీ_Proc_W(HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI VOID WINAPI Post_Quit_సందేశం(పూర్ణాంకం n_Exit_సంకేతం);
  WINUSERAPI LRESULT WINAPI Call_కిటికీ_Proc_A(WNDPROC lpPrevWndFunc,HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Call_కిటికీ_Proc_W(WNDPROC lpPrevWndFunc,HWND hWnd,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI లోపల_Send_సందేశం(VOID);
  WINUSERAPI DWORD WINAPI లోపల_Send_సందేశం_Ex(LPVOID lpReserved);

#నిర్వచించు ISMEX_NOSEND 0x00000000
#నిర్వచించు ISMEX_SEND 0x00000001
#నిర్వచించు ISMEX_NOTIFY 0x00000002
#నిర్వచించు ISMEX_CALLBACK 0x00000004
#నిర్వచించు ISMEX_REPLIED 0x00000008

  WINUSERAPI UINT WINAPI Get_Double_Click_సమయం(VOID);
  WINUSERAPI WINBOOL WINAPI సమితి_Double_Click_సమయం(UINT);
  WINUSERAPI ATOM WINAPI రిజిస్టరు_Class_A(CONST WNDCLASSA *lpWndClass);
  WINUSERAPI ATOM WINAPI రిజిస్టరు_Class_W(CONST WNDCLASSW *lpWndClass);
  WINUSERAPI WINBOOL WINAPI UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
  WINUSERAPI WINBOOL WINAPI GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
  WINUSERAPI ATOM WINAPI రిజిస్టరు_Class_Ex_A(CONST WNDCLASSEXA *);
  WINUSERAPI ATOM WINAPI రిజిస్టరు_Class_Ex_W(CONST WNDCLASSEXW *);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);

#నిర్వచించు CW_USEDEFAULT ((పూర్ణాంకం)0x80000000)

#నిర్వచించు HWND_DESKTOP ((HWND)0)

  రకనిర్వచనం BOOLEAN (WINAPI *PREGISTERCLASSNAMEW)(LPCWSTR);

#నిర్వచితమైతే UNICODE
#నిర్వచించు Create_కిటికీ_Ex Create_కిటికీ_Ex_W
#నిర్వచించు Create_కిటికీ Create_కిటికీ_W
#లేకపోతే
#నిర్వచించు Create_కిటికీ_Ex Create_కిటికీ_Ex_A
#నిర్వచించు Create_కిటికీ Create_కిటికీ_A
#అయితే_ముగింపు

  WINUSERAPI HWND WINAPI Create_కిటికీ_Ex_A(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lp_కిటికీ_Name,DWORD dwStyle,పూర్ణాంకం X,పూర్ణాంకం Y,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు,HWND h_Wnd_మాతృ,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
  WINUSERAPI HWND WINAPI Create_కిటికీ_Ex_W(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lp_కిటికీ_Name,DWORD dwStyle,పూర్ణాంకం X,పూర్ణాంకం Y,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు,HWND h_Wnd_మాతృ,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
#నిర్వచించు Create_కిటికీ_A(lpClassName,lp_కిటికీ_Name,dwStyle,x,y,n_వెడల్పు,n_ఎత్తు,h_Wnd_మాతృ,hMenu,hInstance,lpParam) Create_కిటికీ_Ex_A(0L,lpClassName,lp_కిటికీ_Name,dwStyle,x,y,n_వెడల్పు,n_ఎత్తు,h_Wnd_మాతృ,hMenu,hInstance,lpParam)
#నిర్వచించు Create_కిటికీ_W(lpClassName,lp_కిటికీ_Name,dwStyle,x,y,n_వెడల్పు,n_ఎత్తు,h_Wnd_మాతృ,hMenu,hInstance,lpParam) Create_కిటికీ_Ex_W(0L,lpClassName,lp_కిటికీ_Name,dwStyle,x,y,n_వెడల్పు,n_ఎత్తు,h_Wnd_మాతృ,hMenu,hInstance,lpParam)
  WINUSERAPI WINBOOL WINAPI Is_కిటికీ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsMenu(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI Is_బిడ్డ(HWND h_Wnd_మాతృ,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Destroy_కిటికీ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Show_కిటికీ(HWND hWnd,పూర్ణాంకం nCmdShow);
  WINUSERAPI WINBOOL WINAPI Animate_కిటికీ(HWND hWnd,DWORD dw_సమయం,DWORD dwFlags);

#ఒకవేళ defined(_WINGDI_) && !defined(NOGDI)
  WINUSERAPI WINBOOL WINAPI Update_Layered_కిటికీ(HWND hWnd,HDC hdcDst,బిందువు_3 *pptDst,కొలత_2 *psize,HDC hdcSrc,బిందువు_3 *pptSrc,COLORREF cr_కీలకం,BLENDFUNCTION *pblend,DWORD dwFlags);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_UPDATELAYEREDWINDOWINFO {
    DWORD cb_కొలత;
    HDC hdcDst;
    బిందువు_3 CONST *pptDst;
    కొలత_2 CONST *psize;
    HDC hdcSrc;
    బిందువు_3 CONST *pptSrc;
    COLORREF cr_కీలకం;
    BLENDFUNCTION CONST *pblend;
    DWORD dwFlags;
    RECT CONST *prcDirty;
  } UPDATELAYEREDWINDOWINFO,*PUPDATELAYEREDWINDOWINFO;

  WINUSERAPI WINBOOL WINAPI Update_Layered_కిటికీ_పరోక్ష(HWND hWnd,UPDATELAYEREDWINDOWINFO CONST *pULWInfo);
  WINUSERAPI WINBOOL WINAPI Get_Layered_కిటికీ_లక్షణాలు(HWND hwnd,COLORREF *pcr_కీలకం,BYTE *pbAlpha,DWORD *pdwFlags);

#నిర్వచించు PW_CLIENTONLY 0x00000001

  WINUSERAPI WINBOOL WINAPI Print_కిటికీ(HWND hwnd,HDC hdcBlt,UINT nFlags);
  WINUSERAPI WINBOOL WINAPI సమితి_Layered_కిటికీ_లక్షణాలు(HWND hwnd,COLORREF cr_కీలకం,BYTE bAlpha,DWORD dwFlags);

#నిర్వచించు LWA_COLORKEY 0x00000001
#నిర్వచించు LWA_ALPHA 0x00000002

#నిర్వచించు ULW_COLORKEY 0x00000001
#నిర్వచించు ULW_ALPHA 0x00000002
#నిర్వచించు ULW_OPAQUE 0x00000004

#నిర్వచించు ULW_EX_NORESIZE 0x00000008

  WINUSERAPI WINBOOL WINAPI Show_కిటికీ_Async(HWND hWnd,పూర్ణాంకం nCmdShow);
  WINUSERAPI WINBOOL WINAPI Flash_కిటికీ(HWND hWnd,WINBOOL bInvert);

  రకనిర్వచనం నిర్మాణం {
    UINT cb_కొలత;
    HWND hwnd;
    DWORD dwFlags;
    UINT u_లెక్క;
    DWORD dwTimeout;
  } FLASHWINFO,*PFLASHWINFO;

  WINUSERAPI WINBOOL WINAPI Flash_కిటికీ_Ex(PFLASHWINFO pfwi);

#నిర్వచించు FLASHW_STOP 0
#నిర్వచించు FLASHW_CAPTION 0x00000001
#నిర్వచించు FLASHW_TRAY 0x00000002
#నిర్వచించు FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#నిర్వచించు FLASHW_TIMER 0x00000004
#నిర్వచించు FLASHW_TIMERNOFG 0x0000000C

  WINUSERAPI WINBOOL WINAPI ShowOwnedPopups(HWND hWnd,WINBOOL fShow);
  WINUSERAPI WINBOOL WINAPI OpenIcon(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Close_కిటికీ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Move_కిటికీ(HWND hWnd,పూర్ణాంకం X,పూర్ణాంకం Y,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు,WINBOOL bRepaint);
  WINUSERAPI WINBOOL WINAPI సమితి_కిటికీ_Pos(HWND hWnd,HWND h_Wnd_చొప్పించు_After,పూర్ణాంకం X,పూర్ణాంకం Y,పూర్ణాంకం cx,పూర్ణాంకం cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI Get_కిటికీ_Placement(HWND hWnd,WINDOWPLACEMENT *lpwndpl);
  WINUSERAPI WINBOOL WINAPI సమితి_కిటికీ_Placement(HWND hWnd,CONST WINDOWPLACEMENT *lpwndpl);

#నిర్వచితం_కాకపోతే NODEFERWINDOWPOS
  WINUSERAPI HDWP WINAPI Begin_Defer_కిటికీ_Pos(పూర్ణాంకం n_అంకె_Windows);
  WINUSERAPI HDWP WINAPI Defer_కిటికీ_Pos(HDWP hWinPosInfo,HWND hWnd,HWND h_Wnd_చొప్పించు_After,పూర్ణాంకం x,పూర్ణాంకం y,పూర్ణాంకం cx,పూర్ణాంకం cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI చివర_Defer_కిటికీ_Pos(HDWP hWinPosInfo);
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI Is_కిటికీ_Visible(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsIconic(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AnyPopup(VOID);
  WINUSERAPI WINBOOL WINAPI Bring_కిటికీ_గమ్యం_శిఖరం(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsZoomed(HWND hWnd);

#నిర్వచించు SWP_NOSIZE 0x0001
#నిర్వచించు SWP_NOMOVE 0x0002
#నిర్వచించు SWP_NOZORDER 0x0004
#నిర్వచించు SWP_NOREDRAW 0x0008
#నిర్వచించు SWP_NOACTIVATE 0x0010
#నిర్వచించు SWP_FRAMECHANGED 0x0020
#నిర్వచించు SWP_SHOWWINDOW 0x0040
#నిర్వచించు SWP_HIDEWINDOW 0x0080
#నిర్వచించు SWP_NOCOPYBITS 0x0100
#నిర్వచించు SWP_NOOWNERZORDER 0x0200
#నిర్వచించు SWP_NOSENDCHANGING 0x0400

#నిర్వచించు SWP_DRAWFRAME SWP_FRAMECHANGED
#నిర్వచించు SWP_NOREPOSITION SWP_NOOWNERZORDER
#నిర్వచించు SWP_DEFERERASE 0x2000
#నిర్వచించు SWP_ASYNCWINDOWPOS 0x4000

#నిర్వచించు HWND_శిఖరం ((HWND)0)
#నిర్వచించు HWND_BOTTOM ((HWND)1)
#నిర్వచించు HWND_TOPMOST ((HWND)-1)
#నిర్వచించు HWND_NOTOPMOST ((HWND)-2)

#నిర్వచితం_కాకపోతే NOCTLMGR

#అన్తర్భావ <pshpack2.h>

  రకనిర్వచనం నిర్మాణం {
    DWORD style;
    DWORD dwExtendedStyle;
    మాట_3 cdit;
    పొట్టి x;
    పొట్టి y;
    పొట్టి cx;
    పొట్టి cy;
  } DLGTEMPLATE;

  రకనిర్వచనం DLGTEMPLATE *LPDLGTEMPLATEA;
  రకనిర్వచనం DLGTEMPLATE *LPDLGTEMPLATEW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం LPDLGTEMPLATEW LPDLGTEMPLATE;
#లేకపోతే
  రకనిర్వచనం LPDLGTEMPLATEA LPDLGTEMPLATE;
#అయితే_ముగింపు

  రకనిర్వచనం CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
  రకనిర్వచనం CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#లేకపోతే
  రకనిర్వచనం LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం {
    DWORD style;
    DWORD dwExtendedStyle;
    పొట్టి x;
    పొట్టి y;
    పొట్టి cx;
    పొట్టి cy;
    మాట_3 id;
  } DLGITEMTEMPLATE;

  రకనిర్వచనం DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
  రకనిర్వచనం DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#లేకపోతే
  రకనిర్వచనం PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#అయితే_ముగింపు

  రకనిర్వచనం DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
  రకనిర్వచనం DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#లేకపోతే
  రకనిర్వచనం LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#అయితే_ముగింపు

#అన్తర్భావ <poppack.h>

#నిర్వచితమైతే UNICODE
#నిర్వచించు CreateDialogParam CreateDialogParamW
#నిర్వచించు Create_Dialog_పరోక్ష_Param Create_Dialog_పరోక్ష_Param_W
#నిర్వచించు CreateDialog CreateDialogW
#నిర్వచించు Create_Dialog_పరోక్ష Create_Dialog_పరోక్ష_W
#నిర్వచించు DialogBoxParam DialogBoxParamW
#నిర్వచించు Dialog_Box_పరోక్ష_Param Dialog_Box_పరోక్ష_Param_W
#నిర్వచించు DialogBox DialogBoxW
#నిర్వచించు Dialog_Box_పరోక్ష Dialog_Box_పరోక్ష_W
#నిర్వచించు సమితి_Dlg_అంశం_పాఠ్యం సమితి_Dlg_అంశం_పాఠ్యం_W
#నిర్వచించు Get_Dlg_అంశం_పాఠ్యం Get_Dlg_అంశం_పాఠ్యం_W
#నిర్వచించు Send_Dlg_అంశం_సందేశం Send_Dlg_అంశం_సందేశం_W
#నిర్వచించు DefDlgProc DefDlgProcW
#లేకపోతే
#నిర్వచించు CreateDialogParam CreateDialogParamA
#నిర్వచించు Create_Dialog_పరోక్ష_Param Create_Dialog_పరోక్ష_Param_A
#నిర్వచించు CreateDialog CreateDialogA
#నిర్వచించు Create_Dialog_పరోక్ష Create_Dialog_పరోక్ష_A
#నిర్వచించు DialogBoxParam DialogBoxParamA
#నిర్వచించు Dialog_Box_పరోక్ష_Param Dialog_Box_పరోక్ష_Param_A
#నిర్వచించు DialogBox DialogBoxA
#నిర్వచించు Dialog_Box_పరోక్ష Dialog_Box_పరోక్ష_A
#నిర్వచించు సమితి_Dlg_అంశం_పాఠ్యం సమితి_Dlg_అంశం_పాఠ్యం_A
#నిర్వచించు Get_Dlg_అంశం_పాఠ్యం Get_Dlg_అంశం_పాఠ్యం_A
#నిర్వచించు Send_Dlg_అంశం_సందేశం Send_Dlg_అంశం_సందేశం_A
#నిర్వచించు DefDlgProc DefDlgProcA
#అయితే_ముగింపు

  WINUSERAPI HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_మాతృ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_మాతృ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_పరోక్ష_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND h_Wnd_మాతృ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_పరోక్ష_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND h_Wnd_మాతృ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#నిర్వచించు CreateDialogA(hInstance,lpName,h_Wnd_మాతృ,lpDialogFunc) CreateDialogParamA(hInstance,lpName,h_Wnd_మాతృ,lpDialogFunc,0L)
#నిర్వచించు CreateDialogW(hInstance,lpName,h_Wnd_మాతృ,lpDialogFunc) CreateDialogParamW(hInstance,lpName,h_Wnd_మాతృ,lpDialogFunc,0L)
#నిర్వచించు Create_Dialog_పరోక్ష_A(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc) Create_Dialog_పరోక్ష_Param_A(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc,0L)
#నిర్వచించు Create_Dialog_పరోక్ష_W(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc) Create_Dialog_పరోక్ష_Param_W(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc,0L)
  WINUSERAPI INT_PTR WINAPI DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_మాతృ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_మాతృ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_పరోక్ష_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND h_Wnd_మాతృ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_పరోక్ష_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND h_Wnd_మాతృ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#నిర్వచించు DialogBoxA(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc,0L)
#నిర్వచించు DialogBoxW(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc,0L)
#నిర్వచించు Dialog_Box_పరోక్ష_A(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc) Dialog_Box_పరోక్ష_Param_A(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc,0L)
#నిర్వచించు Dialog_Box_పరోక్ష_W(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc) Dialog_Box_పరోక్ష_Param_W(hInstance,lpTemplate,h_Wnd_మాతృ,lpDialogFunc,0L)
  WINUSERAPI WINBOOL WINAPI చివర_Dialog(HWND hDlg,INT_PTR n_ఫలితం);
  WINUSERAPI HWND WINAPI Get_Dlg_అంశం(HWND hDlg,పూర్ణాంకం n_IDDlg_అంశం);
  WINUSERAPI WINBOOL WINAPI సమితి_Dlg_అంశం_Int(HWND hDlg,పూర్ణాంకం n_IDDlg_అంశం,UINT u_విలువ,WINBOOL bSigned);
  WINUSERAPI UINT WINAPI Get_Dlg_అంశం_Int(HWND hDlg,పూర్ణాంకం n_IDDlg_అంశం,WINBOOL *lpTranslated,WINBOOL bSigned);
  WINUSERAPI WINBOOL WINAPI సమితి_Dlg_అంశం_పాఠ్యం_A(HWND hDlg,పూర్ణాంకం n_IDDlg_అంశం,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI సమితి_Dlg_అంశం_పాఠ్యం_W(HWND hDlg,పూర్ణాంకం n_IDDlg_అంశం,LPCWSTR lpString);
  WINUSERAPI UINT WINAPI Get_Dlg_అంశం_పాఠ్యం_A(HWND hDlg,పూర్ణాంకం n_IDDlg_అంశం,LPSTR lpString,పూర్ణాంకం cchMax);
  WINUSERAPI UINT WINAPI Get_Dlg_అంశం_పాఠ్యం_W(HWND hDlg,పూర్ణాంకం n_IDDlg_అంశం,LPWSTR lpString,పూర్ణాంకం cchMax);
  WINUSERAPI WINBOOL WINAPI CheckDlgButton(HWND hDlg,పూర్ణాంకం nIDButton,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI CheckRadioButton(HWND hDlg,పూర్ణాంకం nIDFirstButton,పూర్ణాంకం nIDLastButton,పూర్ణాంకం nIDCheckButton);
  WINUSERAPI UINT WINAPI IsDlgButtonChecked(HWND hDlg,పూర్ణాంకం nIDButton);
  WINUSERAPI LRESULT WINAPI Send_Dlg_అంశం_సందేశం_A(HWND hDlg,పూర్ణాంకం n_IDDlg_అంశం,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_Dlg_అంశం_సందేశం_W(HWND hDlg,పూర్ణాంకం n_IDDlg_అంశం,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI HWND WINAPI Get_తదుపరి_Dlg_సమూహం_అంశం(HWND hDlg,HWND hCtl,WINBOOL b_మునుపటి);
  WINUSERAPI HWND WINAPI Get_తదుపరి_Dlg_Tab_అంశం(HWND hDlg,HWND hCtl,WINBOOL b_మునుపటి);
  WINUSERAPI పూర్ణాంకం WINAPI GetDlgCtrlID(HWND hWnd);
  WINUSERAPI దీర్ఘ WINAPI Get_Dialog_పునాది_Units(VOID);
  WINUSERAPI LRESULT WINAPI DefDlgProcA(HWND hDlg,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefDlgProcW(HWND hDlg,UINT సందేశం_5,WPARAM wParam,LPARAM lParam);

#నిర్వచించు DLGWINDOWEXTRA 30
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOMSG

#నిర్వచితమైతే UNICODE
#నిర్వచించు Call_సందేశం_Filter Call_సందేశం_Filter_W
#లేకపోతే
#నిర్వచించు Call_సందేశం_Filter Call_సందేశం_Filter_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI Call_సందేశం_Filter_A(LPMSG lp_సందేశం_2,పూర్ణాంకం n_సంకేతం);
  WINUSERAPI WINBOOL WINAPI Call_సందేశం_Filter_W(LPMSG lp_సందేశం_2,పూర్ణాంకం n_సంకేతం);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOCLIPBOARD

#నిర్వచితమైతే UNICODE
#నిర్వచించు రిజిస్టరు_Clipboard_Format రిజిస్టరు_Clipboard_Format_W
#నిర్వచించు GetClipboardFormatName GetClipboardFormatNameW
#లేకపోతే
#నిర్వచించు రిజిస్టరు_Clipboard_Format రిజిస్టరు_Clipboard_Format_A
#నిర్వచించు GetClipboardFormatName GetClipboardFormatNameA
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI OpenClipboard(HWND hWndNewOwner);
  WINUSERAPI WINBOOL WINAPI CloseClipboard(VOID);
  WINUSERAPI DWORD WINAPI Get_Clipboard_Sequence_సంఖ్య(VOID);
  WINUSERAPI HWND WINAPI GetClipboardOwner(VOID);
  WINUSERAPI HWND WINAPI సమితి_Clipboard_Viewer(HWND hWndNewViewer);
  WINUSERAPI HWND WINAPI GetClipboardViewer(VOID);
  WINUSERAPI WINBOOL WINAPI ChangeClipboardChain(HWND hWndRemove,HWND h_Wnd_New_తదుపరి);
  WINUSERAPI HANDLE WINAPI సమితి_Clipboard_దత్తాంశం(UINT uFormat,HANDLE hMem);
  WINUSERAPI HANDLE WINAPI Get_Clipboard_దత్తాంశం(UINT uFormat);
  WINUSERAPI UINT WINAPI రిజిస్టరు_Clipboard_Format_A(LPCSTR lpszFormat);
  WINUSERAPI UINT WINAPI రిజిస్టరు_Clipboard_Format_W(LPCWSTR lpszFormat);
  WINUSERAPI పూర్ణాంకం WINAPI లెక్క_Clipboard_Formats(VOID);
  WINUSERAPI UINT WINAPI EnumClipboardFormats(UINT format);
  WINUSERAPI పూర్ణాంకం WINAPI GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,పూర్ణాంకం cch_Max_లెక్క);
  WINUSERAPI పూర్ణాంకం WINAPI GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,పూర్ణాంకం cch_Max_లెక్క);
  WINUSERAPI WINBOOL WINAPI ఖాళీలు_Clipboard(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Clipboard_Format_అందుబాటు(UINT format);
  WINUSERAPI పూర్ణాంకం WINAPI Get_ప్రాధాన్యత_Clipboard_Format(UINT *pa_Format_ప్రాధాన్యత_List,పూర్ణాంకం cFormats);
  WINUSERAPI HWND WINAPI Get_Open_Clipboard_కిటికీ(VOID);
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు Char_గమ్యం_Oem Char_గమ్యం_Oem_W
#నిర్వచించు Oem_గమ్యం_Char Oem_గమ్యం_Char_W
#నిర్వచించు Char_గమ్యం_Oem_Buff Char_గమ్యం_Oem_Buff_W
#నిర్వచించు Oem_గమ్యం_Char_Buff Oem_గమ్యం_Char_Buff_W
#నిర్వచించు Char_పై Char_పై_W
#నిర్వచించు Char_పై_Buff Char_పై_Buff_W
#నిర్వచించు Char_క్రింది Char_క్రింది_W
#నిర్వచించు Char_క్రింది_Buff Char_క్రింది_Buff_W
#నిర్వచించు Char_తదుపరి Char_తదుపరి_W
#నిర్వచించు CharPrev CharPrevW
#లేకపోతే
#నిర్వచించు Char_గమ్యం_Oem Char_గమ్యం_Oem_A
#నిర్వచించు Oem_గమ్యం_Char Oem_గమ్యం_Char_A
#నిర్వచించు Char_గమ్యం_Oem_Buff Char_గమ్యం_Oem_Buff_A
#నిర్వచించు Oem_గమ్యం_Char_Buff Oem_గమ్యం_Char_Buff_A
#నిర్వచించు Char_పై Char_పై_A
#నిర్వచించు Char_పై_Buff Char_పై_Buff_A
#నిర్వచించు Char_క్రింది Char_క్రింది_A
#నిర్వచించు Char_క్రింది_Buff Char_క్రింది_Buff_A
#నిర్వచించు Char_తదుపరి Char_తదుపరి_A
#నిర్వచించు CharPrev CharPrevA
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI Char_గమ్యం_Oem_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_గమ్యం_Oem_W(LPCWSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_గమ్యం_Char_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_గమ్యం_Char_W(LPCSTR lpszSrc,LPWSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_గమ్యం_Oem_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_నిడివి);
  WINUSERAPI WINBOOL WINAPI Char_గమ్యం_Oem_Buff_W(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_నిడివి);
  WINUSERAPI WINBOOL WINAPI Oem_గమ్యం_Char_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_నిడివి);
  WINUSERAPI WINBOOL WINAPI Oem_గమ్యం_Char_Buff_W(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cch_Dst_నిడివి);
  WINUSERAPI LPSTR WINAPI Char_పై_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_పై_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_పై_Buff_A(LPSTR lpsz,DWORD cch_నిడివి);
  WINUSERAPI DWORD WINAPI Char_పై_Buff_W(LPWSTR lpsz,DWORD cch_నిడివి);
  WINUSERAPI LPSTR WINAPI Char_క్రింది_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_క్రింది_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_క్రింది_Buff_A(LPSTR lpsz,DWORD cch_నిడివి);
  WINUSERAPI DWORD WINAPI Char_క్రింది_Buff_W(LPWSTR lpsz,DWORD cch_నిడివి);
  WINUSERAPI LPSTR WINAPI Char_తదుపరి_A(LPCSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_తదుపరి_W(LPCWSTR lpsz);
  WINUSERAPI LPSTR WINAPI CharPrevA(LPCSTR lpsz_ప్రారంభం,LPCSTR lpszCurrent);
  WINUSERAPI LPWSTR WINAPI CharPrevW(LPCWSTR lpsz_ప్రారంభం,LPCWSTR lpszCurrent);
  WINUSERAPI LPSTR WINAPI Char_తదుపరి_Ex_A(మాట_3 సంకేతం_పుట,LPCSTR lpCurrentChar,DWORD dwFlags);
  WINUSERAPI LPSTR WINAPI CharPrevExA(మాట_3 సంకేతం_పుట,LPCSTR lp_ప్రారంభం,LPCSTR lpCurrentChar,DWORD dwFlags);

#నిర్వచించు Ansi_గమ్యం_Oem Char_గమ్యం_Oem_A
#నిర్వచించు Oem_గమ్యం_Ansi Oem_గమ్యం_Char_A
#నిర్వచించు Ansi_గమ్యం_Oem_Buff Char_గమ్యం_Oem_Buff_A
#నిర్వచించు Oem_గమ్యం_Ansi_Buff Oem_గమ్యం_Char_Buff_A
#నిర్వచించు Ansi_పై Char_పై_A
#నిర్వచించు Ansi_పై_Buff Char_పై_Buff_A
#నిర్వచించు Ansi_క్రింది Char_క్రింది_A
#నిర్వచించు Ansi_క్రింది_Buff Char_క్రింది_Buff_A
#నిర్వచించు Ansi_తదుపరి Char_తదుపరి_A
#నిర్వచించు AnsiPrev CharPrevA

#నిర్వచితం_కాకపోతే NOLANGUAGE

#నిర్వచితమైతే UNICODE
#నిర్వచించు IsCharAlpha IsCharAlphaW
#నిర్వచించు IsCharAlphaNumeric IsCharAlphaNumericW
#నిర్వచించు Is_Char_పై Is_Char_పై_W
#నిర్వచించు Is_Char_క్రింది Is_Char_క్రింది_W
#లేకపోతే
#నిర్వచించు IsCharAlpha IsCharAlphaA
#నిర్వచించు IsCharAlphaNumeric IsCharAlphaNumericA
#నిర్వచించు Is_Char_పై Is_Char_పై_A
#నిర్వచించు Is_Char_క్రింది Is_Char_క్రింది_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI IsCharAlphaA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_పై_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_పై_W(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_క్రింది_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_క్రింది_W(WCHAR ch);
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_కీలకం_Name_పాఠ్యం Get_కీలకం_Name_పాఠ్యం_W
#నిర్వచించు Vk_కీలకం_పరిశీలన Vk_కీలకం_పరిశీలన_W
#నిర్వచించు Vk_కీలకం_పరిశీలన_Ex Vk_కీలకం_పరిశీలన_Ex_W
#లేకపోతే
#నిర్వచించు Get_కీలకం_Name_పాఠ్యం Get_కీలకం_Name_పాఠ్యం_A
#నిర్వచించు Vk_కీలకం_పరిశీలన Vk_కీలకం_పరిశీలన_A
#నిర్వచించు Vk_కీలకం_పరిశీలన_Ex Vk_కీలకం_పరిశీలన_Ex_A
#అయితే_ముగింపు

  WINUSERAPI HWND WINAPI సమితి_Focus(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_చురుకైన_కిటికీ(VOID);
  WINUSERAPI HWND WINAPI GetFocus(VOID);
  WINUSERAPI UINT WINAPI Get_KBCode_పుట(VOID);
  WINUSERAPI SHORT WINAPI Get_కీలకం_State(పూర్ణాంకం n_Virt_కీలకం);
  WINUSERAPI SHORT WINAPI Get_Async_కీలకం_State(పూర్ణాంకం v_కీలకం);
  WINUSERAPI WINBOOL WINAPI GetKeyboardState(PBYTE lp_కీలకం_State);
  WINUSERAPI WINBOOL WINAPI సమితి_Keyboard_State(LPBYTE lp_కీలకం_State);
  WINUSERAPI పూర్ణాంకం WINAPI Get_కీలకం_Name_పాఠ్యం_A(LONG lParam,LPSTR lpString,పూర్ణాంకం cch_కొలత);
  WINUSERAPI పూర్ణాంకం WINAPI Get_కీలకం_Name_పాఠ్యం_W(LONG lParam,LPWSTR lpString,పూర్ణాంకం cch_కొలత);
  WINUSERAPI పూర్ణాంకం WINAPI GetKeyboardType(పూర్ణాంకం nTypeFlag);
  WINUSERAPI పూర్ణాంకం WINAPI గమ్యం_Ascii(UINT u_Virt_కీలకం,UINT u_పరిశీలన_సంకేతం,CONST BYTE *lp_కీలకం_State,LPWORD lpChar,UINT uFlags);
  WINUSERAPI పూర్ణాంకం WINAPI గమ్యం_Ascii_Ex(UINT u_Virt_కీలకం,UINT u_పరిశీలన_సంకేతం,CONST BYTE *lp_కీలకం_State,LPWORD lpChar,UINT uFlags,HKL dwhkl);
  WINUSERAPI పూర్ణాంకం WINAPI గమ్యం_Unicode(UINT w_Virt_కీలకం,UINT w_పరిశీలన_సంకేతం,CONST BYTE *lp_కీలకం_State,LPWSTR pwszBuff,పూర్ణాంకం cchBuff,UINT wFlags);
  WINUSERAPI DWORD WINAPI Oem_కీలకం_పరిశీలన(మాట_3 wOemChar);
  WINUSERAPI SHORT WINAPI Vk_కీలకం_పరిశీలన_A(CHAR ch);
  WINUSERAPI SHORT WINAPI Vk_కీలకం_పరిశీలన_W(WCHAR ch);
  WINUSERAPI SHORT WINAPI Vk_కీలకం_పరిశీలన_Ex_A(CHAR ch,HKL dwhkl);
  WINUSERAPI SHORT WINAPI Vk_కీలకం_పరిశీలన_Ex_W(WCHAR ch,HKL dwhkl);

#నిర్వచించు KEYEVENTF_EXTENDEDKEY 0x0001
#నిర్వచించు KEYEVENTF_KEYUP 0x0002
#నిర్వచించు KEYEVENTF_UNICODE 0x0004
#నిర్వచించు KEYEVENTF_SCANCODE 0x0008

  WINUSERAPI VOID WINAPI keybd_event(BYTE bVk,BYTE b_పరిశీలన,DWORD dwFlags,ULONG_PTR dwExtraInfo);

#నిర్వచించు MOUSEEVENTF_MOVE 0x0001
#నిర్వచించు MOUSEEVENTF_LEFTDOWN 0x0002
#నిర్వచించు MOUSEEVENTF_LEFTUP 0x0004
#నిర్వచించు MOUSEEVENTF_RIGHTDOWN 0x0008
#నిర్వచించు MOUSEEVENTF_RIGHTUP 0x0010
#నిర్వచించు MOUSEEVENTF_MIDDLEDOWN 0x0020
#నిర్వచించు MOUSEEVENTF_MIDDLEUP 0x0040
#నిర్వచించు MOUSEEVENTF_XDOWN 0x0080
#నిర్వచించు MOUSEEVENTF_XUP 0x0100
#నిర్వచించు MOUSEEVENTF_WHEEL 0x0800
#నిర్వచించు MOUSEEVENTF_VIRTUALDESK 0x4000
#నిర్వచించు MOUSEEVENTF_ABSOLUTE 0x8000

  WINUSERAPI VOID WINAPI mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dw_దత్తాంశం,ULONG_PTR dwExtraInfo);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouse_దత్తాంశం;
    DWORD dwFlags;
    DWORD సమయం;
    ULONG_PTR dwExtraInfo;
  } MOUSEINPUT,*PMOUSEINPUT,*LPMOUSEINPUT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_KEYBDINPUT {
    మాట_3 wVk;
    మాట_3 w_పరిశీలన;
    DWORD dwFlags;
    DWORD సమయం;
    ULONG_PTR dwExtraInfo;
  } KEYBDINPUT,*PKEYBDINPUT,*LPKEYBDINPUT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_HARDWAREINPUT {
    DWORD u_సందేశం;
    మాట_3 wParamL;
    మాట_3 wParamH;
  } HARDWAREINPUT,*PHARDWAREINPUT,*LPHARDWAREINPUT;

#నిర్వచించు ఆదానం_MOUSE 0
#నిర్వచించు ఆదానం_KEYBOARD 1
#నిర్వచించు ఆదానం_HARDWARE 2

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ఆదానం {
    DWORD type;
    సంఘం {
      MOUSEINPUT mi;
      KEYBDINPUT ki;
      HARDWAREINPUT hi;
    };
  } ఆదానం_2,*PINPUT,*LPINPUT;

  WINUSERAPI UINT WINAPI Send_ఆదానం(UINT cInputs,LPINPUT pInputs,పూర్ణాంకం cb_కొలత);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LASTINPUTINFO {
    UINT cb_కొలత;
    DWORD dw_సమయం;
  } LASTINPUTINFO,*PLASTINPUTINFO;

#నిర్వచితమైతే UNICODE
#నిర్వచించు Map_Virtual_కీలకం Map_Virtual_కీలకం_W
#నిర్వచించు Map_Virtual_కీలకం_Ex Map_Virtual_కీలకం_Ex_W
#లేకపోతే
#నిర్వచించు Map_Virtual_కీలకం Map_Virtual_కీలకం_A
#నిర్వచించు Map_Virtual_కీలకం_Ex Map_Virtual_కీలకం_Ex_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI Get_చివరి_ఆదానం_Info(PLASTINPUTINFO plii);
  WINUSERAPI UINT WINAPI Map_Virtual_కీలకం_A(UINT u_సంకేతం,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_కీలకం_W(UINT u_సంకేతం,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_కీలకం_Ex_A(UINT u_సంకేతం,UINT uMapType,HKL dwhkl);
  WINUSERAPI UINT WINAPI Map_Virtual_కీలకం_Ex_W(UINT u_సంకేతం,UINT uMapType,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI Get_ఆదానం_State(VOID);
  WINUSERAPI DWORD WINAPI Get_వరుస_స్థితి(UINT flags);
  WINUSERAPI HWND WINAPI GetCapture(VOID);
  WINUSERAPI HWND WINAPI సమితి_Capture(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ReleaseCapture(VOID);
  WINUSERAPI DWORD WINAPI సందేశం_Wait_For_గుణిజం_Objects(DWORD n_లెక్క,CONST HANDLE *pHandles,WINBOOL fWaitAll,DWORD dwMilliseconds,DWORD dw_Wake_ముసుగు);
  WINUSERAPI DWORD WINAPI సందేశం_Wait_For_గుణిజం_Objects_Ex(DWORD n_లెక్క,CONST HANDLE *pHandles,DWORD dwMilliseconds,DWORD dw_Wake_ముసుగు,DWORD dwFlags);

#నిర్వచించు MWMO_WAITALL 0x0001
#నిర్వచించు MWMO_ALERTABLE 0x0002
#నిర్వచించు MWMO_INPUTAVAILABLE 0x0004

#నిర్వచించు QS_కీలకం 0x0001
#నిర్వచించు QS_MOUSEMOVE 0x0002
#నిర్వచించు QS_MOUSEBUTTON 0x0004
#నిర్వచించు QS_POSTMESSAGE 0x0008
#నిర్వచించు QS_TIMER 0x0010
#నిర్వచించు QS_PAINT 0x0020
#నిర్వచించు QS_SENDMESSAGE 0x0040
#నిర్వచించు QS_HOTKEY 0x0080
#నిర్వచించు QS_ALLPOSTMESSAGE 0x0100
#నిర్వచించు QS_RAWINPUT 0x0400
#నిర్వచించు QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#నిర్వచించు QS_ఆదానం (QS_MOUSE | QS_కీలకం | QS_RAWINPUT)
#నిర్వచించు QS_ALLEVENTS (QS_ఆదానం | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#నిర్వచించు QS_ALLINPUT (QS_ఆదానం | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#నిర్వచించు USER_TIMER_గరిష్ఠ 0x7FFFFFFF
#నిర్వచించు USER_TIMER_MINIMUM 0x0000000A

#నిర్వచితమైతే UNICODE
#నిర్వచించు ఎక్కించు_Accelerators ఎక్కించు_Accelerators_W
#నిర్వచించు Create_Accelerator_పట్టిక Create_Accelerator_పట్టిక_W
#నిర్వచించు Copy_Accelerator_పట్టిక Copy_Accelerator_పట్టిక_W
#లేకపోతే
#నిర్వచించు ఎక్కించు_Accelerators ఎక్కించు_Accelerators_A
#నిర్వచించు Create_Accelerator_పట్టిక Create_Accelerator_పట్టిక_A
#నిర్వచించు Copy_Accelerator_పట్టిక Copy_Accelerator_పట్టిక_A
#అయితే_ముగింపు

  WINUSERAPI UINT_PTR WINAPI సమితి_Timer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
  WINUSERAPI WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);
  WINUSERAPI WINBOOL WINAPI Is_కిటికీ_Unicode(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Enable_కిటికీ(HWND hWnd,WINBOOL bEnable);
  WINUSERAPI WINBOOL WINAPI Is_కిటికీ_Enabled(HWND hWnd);
  WINUSERAPI HACCEL WINAPI ఎక్కించు_Accelerators_A(HINSTANCE hInstance,LPCSTR lp_పట్టిక_Name);
  WINUSERAPI HACCEL WINAPI ఎక్కించు_Accelerators_W(HINSTANCE hInstance,LPCWSTR lp_పట్టిక_Name);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_పట్టిక_A(LPACCEL paccel,పూర్ణాంకం cAccel);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_పట్టిక_W(LPACCEL paccel,పూర్ణాంకం cAccel);
  WINUSERAPI WINBOOL WINAPI Destroy_Accelerator_పట్టిక(HACCEL hAccel);
  WINUSERAPI పూర్ణాంకం WINAPI Copy_Accelerator_పట్టిక_A(HACCEL hAccelSrc,LPACCEL lpAccelDst,పూర్ణాంకం cAccelEntries);
  WINUSERAPI పూర్ణాంకం WINAPI Copy_Accelerator_పట్టిక_W(HACCEL hAccelSrc,LPACCEL lpAccelDst,పూర్ణాంకం cAccelEntries);

#నిర్వచితం_కాకపోతే NOMSG

#నిర్వచితమైతే UNICODE
#నిర్వచించు TranslateAccelerator TranslateAcceleratorW
#లేకపోతే
#నిర్వచించు TranslateAccelerator TranslateAcceleratorA
#అయితే_ముగింపు

  WINUSERAPI పూర్ణాంకం WINAPI TranslateAcceleratorA(HWND hWnd,HACCEL h_Acc_పట్టిక,LPMSG lp_సందేశం_2);
  WINUSERAPI పూర్ణాంకం WINAPI TranslateAcceleratorW(HWND hWnd,HACCEL h_Acc_పట్టిక,LPMSG lp_సందేశం_2);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOSYSMETRICS

#నిర్వచించు SM_CXSCREEN 0
#నిర్వచించు SM_CYSCREEN 1
#నిర్వచించు SM_CXVSCROLL 2
#నిర్వచించు SM_CYHSCROLL 3
#నిర్వచించు SM_CYCAPTION 4
#నిర్వచించు SM_CXBORDER 5
#నిర్వచించు SM_CYBORDER 6
#నిర్వచించు SM_CXDLGFRAME 7
#నిర్వచించు SM_CYDLGFRAME 8
#నిర్వచించు SM_CYVTHUMB 9
#నిర్వచించు SM_CXHTHUMB 10
#నిర్వచించు SM_CXICON 11
#నిర్వచించు SM_CYICON 12
#నిర్వచించు SM_CXCURSOR 13
#నిర్వచించు SM_CYCURSOR 14
#నిర్వచించు SM_CYMENU 15
#నిర్వచించు SM_CXFULLSCREEN 16
#నిర్వచించు SM_CYFULLSCREEN 17
#నిర్వచించు SM_CYKANJIWINDOW 18
#నిర్వచించు SM_MOUSEPRESENT 19
#నిర్వచించు SM_CYVSCROLL 20
#నిర్వచించు SM_CXHSCROLL 21
#నిర్వచించు SM_DEBUG 22
#నిర్వచించు SM_SWAPBUTTON 23
#నిర్వచించు SM_RESERVED1 24
#నిర్వచించు SM_RESERVED2 25
#నిర్వచించు SM_RESERVED3 26
#నిర్వచించు SM_RESERVED4 27
#నిర్వచించు SM_CXMIN 28
#నిర్వచించు SM_CYMIN 29
#నిర్వచించు SM_CXSIZE 30
#నిర్వచించు SM_CYSIZE 31
#నిర్వచించు SM_CXFRAME 32
#నిర్వచించు SM_CYFRAME 33
#నిర్వచించు SM_CXMINTRACK 34
#నిర్వచించు SM_CYMINTRACK 35
#నిర్వచించు SM_CXDOUBLECLK 36
#నిర్వచించు SM_CYDOUBLECLK 37
#నిర్వచించు SM_CXICONSPACING 38
#నిర్వచించు SM_CYICONSPACING 39
#నిర్వచించు SM_MENUDROPALIGNMENT 40
#నిర్వచించు SM_PENWINDOWS 41
#నిర్వచించు SM_DBCSENABLED 42
#నిర్వచించు SM_CMOUSEBUTTONS 43

#నిర్వచించు SM_CXFIXEDFRAME SM_CXDLGFRAME
#నిర్వచించు SM_CYFIXEDFRAME SM_CYDLGFRAME
#నిర్వచించు SM_CXSIZEFRAME SM_CXFRAME
#నిర్వచించు SM_CYSIZEFRAME SM_CYFRAME

#నిర్వచించు SM_SECURE 44
#నిర్వచించు SM_CXEDGE 45
#నిర్వచించు SM_CYEDGE 46
#నిర్వచించు SM_CXMINSPACING 47
#నిర్వచించు SM_CYMINSPACING 48
#నిర్వచించు SM_CXSMICON 49
#నిర్వచించు SM_CYSMICON 50
#నిర్వచించు SM_CYSMCAPTION 51
#నిర్వచించు SM_CXSMSIZE 52
#నిర్వచించు SM_CYSMSIZE 53
#నిర్వచించు SM_CXMENUSIZE 54
#నిర్వచించు SM_CYMENUSIZE 55
#నిర్వచించు SM_ARRANGE 56
#నిర్వచించు SM_CXMINIMIZED 57
#నిర్వచించు SM_CYMINIMIZED 58
#నిర్వచించు SM_CXMAXTRACK 59
#నిర్వచించు SM_CYMAXTRACK 60
#నిర్వచించు SM_CXMAXIMIZED 61
#నిర్వచించు SM_CYMAXIMIZED 62
#నిర్వచించు SM_జాలం 63
#నిర్వచించు SM_CLEANBOOT 67
#నిర్వచించు SM_CXDRAG 68
#నిర్వచించు SM_CYDRAG 69
#నిర్వచించు SM_SHOWSOUNDS 70
#నిర్వచించు SM_CXMENUCHECK 71
#నిర్వచించు SM_CYMENUCHECK 72
#నిర్వచించు SM_SLOWMACHINE 73
#నిర్వచించు SM_MIDEASTENABLED 74
#నిర్వచించు SM_MOUSEWHEELPRESENT 75
#నిర్వచించు SM_XVIRTUALSCREEN 76
#నిర్వచించు SM_YVIRTUALSCREEN 77
#నిర్వచించు SM_CXVIRTUALSCREEN 78
#నిర్వచించు SM_CYVIRTUALSCREEN 79
#నిర్వచించు SM_CMONITORS 80
#నిర్వచించు SM_SAMEDISPLAYFORMAT 81
#నిర్వచించు SM_IMMENABLED 82
#నిర్వచించు SM_CXFOCUSBORDER 83
#నిర్వచించు SM_CYFOCUSBORDER 84
#నిర్వచించు SM_TABLETPC 86
#నిర్వచించు SM_MEDIACENTER 87
#నిర్వచించు SM_STARTER 88
#నిర్వచించు SM_SERVERR2 89
#నిర్వచించు SM_CMETRICS 90
#నిర్వచించు SM_REMOTESESSION 0x1000
#నిర్వచించు SM_SHUTTINGDOWN 0x2000
#నిర్వచించు SM_REMOTECONTROL 0x2001
#నిర్వచించు SM_CARETBLINKINGENABLED 0x2002

  WINUSERAPI పూర్ణాంకం WINAPI GetSystemMetrics(పూర్ణాంకం n_సూచీ);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOMENUS

#నిర్వచితమైతే UNICODE
#నిర్వచించు ఎక్కించు_Menu ఎక్కించు_Menu_W
#నిర్వచించు ఎక్కించు_Menu_పరోక్ష ఎక్కించు_Menu_పరోక్ష_W
#నిర్వచించు ChangeMenu ChangeMenuW
#నిర్వచించు GetMenuString GetMenuStringW
#నిర్వచించు చొప్పించు_Menu చొప్పించు_Menu_W
#నిర్వచించు AppendMenu AppendMenuW
#నిర్వచించు ModifyMenu ModifyMenuW
#లేకపోతే
#నిర్వచించు ఎక్కించు_Menu ఎక్కించు_Menu_A
#నిర్వచించు ఎక్కించు_Menu_పరోక్ష ఎక్కించు_Menu_పరోక్ష_A
#నిర్వచించు ChangeMenu ChangeMenuA
#నిర్వచించు GetMenuString GetMenuStringA
#నిర్వచించు చొప్పించు_Menu చొప్పించు_Menu_A
#నిర్వచించు AppendMenu AppendMenuA
#నిర్వచించు ModifyMenu ModifyMenuA
#అయితే_ముగింపు

  WINUSERAPI HMENU WINAPI ఎక్కించు_Menu_A(HINSTANCE hInstance,LPCSTR lpMenuName);
  WINUSERAPI HMENU WINAPI ఎక్కించు_Menu_W(HINSTANCE hInstance,LPCWSTR lpMenuName);
  WINUSERAPI HMENU WINAPI ఎక్కించు_Menu_పరోక్ష_A(CONST MENUTEMPLATEA *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI ఎక్కించు_Menu_పరోక్ష_W(CONST MENUTEMPLATEW *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI GetMenu(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI సమితి_Menu(HWND hWnd,HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpsz_New_అంశం,UINT cmd_చొప్పించు,UINT flags);
  WINUSERAPI WINBOOL WINAPI ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpsz_New_అంశం,UINT cmd_చొప్పించు,UINT flags);
  WINUSERAPI WINBOOL WINAPI Hilite_Menu_అంశం(HWND hWnd,HMENU hMenu,UINT u_IDHilite_అంశం,UINT uHilite);
  WINUSERAPI పూర్ణాంకం WINAPI GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,పూర్ణాంకం cchMax,UINT flags);
  WINUSERAPI పూర్ణాంకం WINAPI GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,పూర్ణాంకం cchMax,UINT flags);
  WINUSERAPI UINT WINAPI GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawMenuBar(HWND hWnd);

#నిర్వచించు PMB_చురుకైన 0x00000001

  WINUSERAPI HMENU WINAPI GetSystemMenu(HWND hWnd,WINBOOL bRevert);
  WINUSERAPI HMENU WINAPI CreateMenu(VOID);
  WINUSERAPI HMENU WINAPI CreatePopupMenu(VOID);
  WINUSERAPI WINBOOL WINAPI DestroyMenu(HMENU hMenu);
  WINUSERAPI DWORD WINAPI Check_Menu_అంశం(HMENU hMenu,UINT u_IDCheck_అంశం,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI Enable_Menu_అంశం(HMENU hMenu,UINT u_IDEnable_అంశం,UINT uEnable);
  WINUSERAPI HMENU WINAPI GetSubMenu(HMENU hMenu,పూర్ణాంకం nPos);
  WINUSERAPI UINT WINAPI Get_Menu_అంశం_ID(HMENU hMenu,పూర్ణాంకం nPos);
  WINUSERAPI పూర్ణాంకం WINAPI Get_Menu_అంశం_లెక్క(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI చొప్పించు_Menu_A(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_అంశం,LPCSTR lp_New_అంశం);
  WINUSERAPI WINBOOL WINAPI చొప్పించు_Menu_W(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_అంశం,LPCWSTR lp_New_అంశం);
  WINUSERAPI WINBOOL WINAPI AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_అంశం,LPCSTR lp_New_అంశం);
  WINUSERAPI WINBOOL WINAPI AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_అంశం,LPCWSTR lp_New_అంశం);
  WINUSERAPI WINBOOL WINAPI ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_అంశం,LPCSTR lp_New_అంశం);
  WINUSERAPI WINBOOL WINAPI ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_అంశం,LPCWSTR lp_New_అంశం);
  WINUSERAPI WINBOOL WINAPI RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI సమితి_Menu_అంశం_Bitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
  WINUSERAPI LONG WINAPI GetMenuCheckMarkDimensions(VOID);
  WINUSERAPI WINBOOL WINAPI TrackPopupMenu(HMENU hMenu,UINT uFlags,పూర్ణాంకం x,పూర్ణాంకం y,పూర్ణాంకం nReserved,HWND hWnd,CONST RECT *prcRect);

#నిర్వచించు MNC_IGNORE 0
#నిర్వచించు MNC_CLOSE 1
#నిర్వచించు MNC_EXECUTE 2
#నిర్వచించు MNC_SELECT 3

  రకనిర్వచనం నిర్మాణం ట్యాగ్_TPMPARAMS {
    UINT cb_కొలత;
    RECT rcExclude;
  } TPMPARAMS;

  రకనిర్వచనం TPMPARAMS *LPTPMPARAMS;

  WINUSERAPI WINBOOL WINAPI TrackPopupMenuEx(HMENU,UINT,పూర్ణాంకం,పూర్ణాంకం,HWND,LPTPMPARAMS);

#నిర్వచించు MNS_NOCHECK 0x80000000
#నిర్వచించు MNS_MODELESS 0x40000000
#నిర్వచించు MNS_DRAGDROP 0x20000000
#నిర్వచించు MNS_AUTODISMISS 0x10000000
#నిర్వచించు MNS_NOTIFYBYPOS 0x08000000
#నిర్వచించు MNS_CHECKORBMP 0x04000000

#నిర్వచించు MIM_MAXHEIGHT 0x00000001
#నిర్వచించు MIM_BACKGROUND 0x00000002
#నిర్వచించు MIM_HELPID 0x00000004
#నిర్వచించు MIM_MENUDATA 0x00000008
#నిర్వచించు MIM_STYLE 0x00000010
#నిర్వచించు MIM_APPLYTOSUBMENUS 0x80000000

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MENUINFO {
    DWORD cb_కొలత;
    DWORD f_ముసుగు;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbr_వెనుక;
    DWORD dwContextHelpID;
    ULONG_PTR dw_Menu_దత్తాంశం;
  } MENUINFO,*LPMENUINFO;

  రకనిర్వచనం MENUINFO CONST *LPCMENUINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuInfo(HMENU,LPMENUINFO);
  WINUSERAPI WINBOOL WINAPI సమితి_Menu_Info(HMENU,LPCMENUINFO);
  WINUSERAPI WINBOOL WINAPI చివర_Menu(VOID);

#నిర్వచించు MND_CONTINUE 0
#నిర్వచించు MND_ENDMENU 1

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MENUGETOBJECTINFO {
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
  } MENUGETOBJECTINFO,*PMENUGETOBJECTINFO;

#నిర్వచించు MNGOF_TOPGAP 0x00000001
#నిర్వచించు MNGOF_BOTTOMGAP 0x00000002

#నిర్వచించు MNGO_NOINTERFACE 0x00000000
#నిర్వచించు MNGO_NOERROR 0x00000001

#నిర్వచించు MIIM_STATE 0x00000001
#నిర్వచించు MIIM_ID 0x00000002
#నిర్వచించు MIIM_SUBMENU 0x00000004
#నిర్వచించు MIIM_CHECKMARKS 0x00000008
#నిర్వచించు MIIM_TYPE 0x00000010
#నిర్వచించు MIIM_దత్తాంశం 0x00000020

#నిర్వచించు MIIM_STRING 0x00000040
#నిర్వచించు MIIM_BITMAP 0x00000080
#నిర్వచించు MIIM_FTYPE 0x00000100

#నిర్వచించు HBMMENU_CALLBACK ((HBITMAP) -1)
#నిర్వచించు HBMMENU_SYSTEM ((HBITMAP) 1)
#నిర్వచించు HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#నిర్వచించు HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#నిర్వచించు HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#నిర్వచించు HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#నిర్వచించు HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#నిర్వచించు HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#నిర్వచించు HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#నిర్వచించు HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#నిర్వచించు HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MENUITEMINFOA {
    UINT cb_కొలత;
    UINT f_ముసుగు;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_అంశం_దత్తాంశం;
    LPSTR dw_Type_దత్తాంశం;
    UINT cch;
    HBITMAP hbmp_అంశం;
  } MENUITEMINFOA,*LPMENUITEMINFOA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MENUITEMINFOW {
    UINT cb_కొలత;
    UINT f_ముసుగు;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_అంశం_దత్తాంశం;
    LPWSTR dw_Type_దత్తాంశం;
    UINT cch;
    HBITMAP hbmp_అంశం;
  } MENUITEMINFOW,*LPMENUITEMINFOW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం MENUITEMINFOW MENUITEMINFO;
  రకనిర్వచనం LPMENUITEMINFOW LPMENUITEMINFO;
#లేకపోతే
  రకనిర్వచనం MENUITEMINFOA MENUITEMINFO;
  రకనిర్వచనం LPMENUITEMINFOA LPMENUITEMINFO;
#అయితే_ముగింపు
  రకనిర్వచనం MENUITEMINFOA CONST *LPCMENUITEMINFOA;
  రకనిర్వచనం MENUITEMINFOW CONST *LPCMENUITEMINFOW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం LPCMENUITEMINFOW LPCMENUITEMINFO;
#లేకపోతే
  రకనిర్వచనం LPCMENUITEMINFOA LPCMENUITEMINFO;
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు చొప్పించు_Menu_అంశం చొప్పించు_Menu_అంశం_W
#నిర్వచించు Get_Menu_అంశం_Info Get_Menu_అంశం_Info_W
#నిర్వచించు సమితి_Menu_అంశం_Info సమితి_Menu_అంశం_Info_W
#లేకపోతే
#నిర్వచించు చొప్పించు_Menu_అంశం చొప్పించు_Menu_అంశం_A
#నిర్వచించు Get_Menu_అంశం_Info Get_Menu_అంశం_Info_A
#నిర్వచించు సమితి_Menu_అంశం_Info సమితి_Menu_అంశం_Info_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI చొప్పించు_Menu_అంశం_A(HMENU hmenu,UINT అంశం,WINBOOL fByPosition,LPCMENUITEMINFOA lpmi);
  WINUSERAPI WINBOOL WINAPI చొప్పించు_Menu_అంశం_W(HMENU hmenu,UINT అంశం,WINBOOL fByPosition,LPCMENUITEMINFOW lpmi);
  WINUSERAPI WINBOOL WINAPI Get_Menu_అంశం_Info_A(HMENU hmenu,UINT అంశం,WINBOOL fByPosition,LPMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI Get_Menu_అంశం_Info_W(HMENU hmenu,UINT అంశం,WINBOOL fByPosition,LPMENUITEMINFOW lpmii);
  WINUSERAPI WINBOOL WINAPI సమితి_Menu_అంశం_Info_A(HMENU hmenu,UINT అంశం,WINBOOL fByPositon,LPCMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI సమితి_Menu_అంశం_Info_W(HMENU hmenu,UINT అంశం,WINBOOL fByPositon,LPCMENUITEMINFOW lpmii);

#నిర్వచించు GMDI_USEDISABLED 0x0001L
#నిర్వచించు GMDI_GOINTOPOPUPS 0x0002L

  WINUSERAPI UINT WINAPI Get_Menu_Default_అంశం(HMENU hMenu,UINT fByPos,UINT gmdiFlags);
  WINUSERAPI WINBOOL WINAPI సమితి_Menu_Default_అంశం(HMENU hMenu,UINT u_అంశం,UINT fByPos);
  WINUSERAPI WINBOOL WINAPI Get_Menu_అంశం_Rect(HWND hWnd,HMENU hMenu,UINT u_అంశం,LPRECT lprc_అంశం);
  WINUSERAPI పూర్ణాంకం WINAPI Menu_అంశం_From_బిందువు(HWND hWnd,HMENU hMenu,బిందువు_3 ptScreen);

#నిర్వచించు TPM_LEFTBUTTON 0x0000L
#నిర్వచించు TPM_RIGHTBUTTON 0x0002L
#నిర్వచించు TPM_LEFTALIGN 0x0000L
#నిర్వచించు TPM_CENTERALIGN 0x0004L
#నిర్వచించు TPM_RIGHTALIGN 0x0008L
#నిర్వచించు TPM_TOPALIGN 0x0000L
#నిర్వచించు TPM_VCENTERALIGN 0x0010L
#నిర్వచించు TPM_BOTTOMALIGN 0x0020L

#నిర్వచించు TPM_HORIZONTAL 0x0000L
#నిర్వచించు TPM_VERTICAL 0x0040L
#నిర్వచించు TPM_NONOTIFY 0x0080L
#నిర్వచించు TPM_RETURNCMD 0x0100L
#నిర్వచించు TPM_RECURSE 0x0001L
#నిర్వచించు TPM_HORPOSANIMATION 0x0400L
#నిర్వచించు TPM_HORNEGANIMATION 0x0800L
#నిర్వచించు TPM_VERPOSANIMATION 0x1000L
#నిర్వచించు TPM_VERNEGANIMATION 0x2000L
#నిర్వచించు TPM_NOANIMATION 0x4000L
#నిర్వచించు TPM_LAYOUTRTL 0x8000L
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_DROPSTRUCT {
    HWND hwnd_ఆధారం;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dw_దత్తాంశం;
    బిందువు_3 ptDrop;
    DWORD dw_Control_దత్తాంశం;
  } DROPSTRUCT,*PDROPSTRUCT,*LPDROPSTRUCT;

#నిర్వచించు DOF_EXECUTABLE 0x8001
#నిర్వచించు DOF_DOCUMENT 0x8002
#నిర్వచించు DOF_DIRECTORY 0x8003
#నిర్వచించు DOF_గుణిజం 0x8004
#నిర్వచించు DOF_PROGMAN 0x0001
#నిర్వచించు DOF_SHELLDATA 0x0002

#నిర్వచించు DO_DROPFILE 0x454C4946L
#నిర్వచించు DO_PRINTFILE 0x544E5250L

  WINUSERAPI DWORD WINAPI DragObject(HWND hwnd_మాతృ_2,HWND hwndFrom,UINT fmt,ULONG_PTR దత్తాంశం,HCURSOR hcur);
  WINUSERAPI WINBOOL WINAPI DragDetect(HWND hwnd,బిందువు_3 pt);
  WINUSERAPI WINBOOL WINAPI DrawIcon(HDC hDC,పూర్ణాంకం X,పూర్ణాంకం Y,HICON hIcon);

#నిర్వచితం_కాకపోతే NODRAWTEXT

#నిర్వచించు DT_శిఖరం 0x00000000
#నిర్వచించు DT_ఎడమ 0x00000000
#నిర్వచించు DT_CENTER 0x00000001
#నిర్వచించు DT_కుడి 0x00000002
#నిర్వచించు DT_VCENTER 0x00000004
#నిర్వచించు DT_BOTTOM 0x00000008
#నిర్వచించు DT_WORDBREAK 0x00000010
#నిర్వచించు DT_SINGLELINE 0x00000020
#నిర్వచించు DT_EXPANDTABS 0x00000040
#నిర్వచించు DT_TABSTOP 0x00000080
#నిర్వచించు DT_NOCLIP 0x00000100
#నిర్వచించు DT_EXTERNALLEADING 0x00000200
#నిర్వచించు DT_CALCRECT 0x00000400
#నిర్వచించు DT_NOPREFIX 0x00000800
#నిర్వచించు DT_అంతర్గత 0x00001000

#నిర్వచించు DT_EDITCONTROL 0x00002000
#నిర్వచించు DT_మార్గం_ELLIPSIS 0x00004000
#నిర్వచించు DT_చివర_ELLIPSIS 0x00008000
#నిర్వచించు DT_MODIFYSTRING 0x00010000
#నిర్వచించు DT_RTLREADING 0x00020000
#నిర్వచించు DT_మాట_ELLIPSIS 0x00040000
#నిర్వచించు DT_NOFULLWIDTHCHARBREAK 0x00080000
#నిర్వచించు DT_HIDEPREFIX 0x00100000
#నిర్వచించు DT_PREFIXONLY 0x00200000

  రకనిర్వచనం నిర్మాణం ట్యాగ్_DRAWTEXTPARAMS {
    UINT cb_కొలత;
    పూర్ణాంకం i_Tab_నిడివి;
    పూర్ణాంకం i_ఎడమ_Margin;
    పూర్ణాంకం i_కుడి_Margin;
    UINT ui_నిడివి_Drawn;
  } DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

#నిర్వచితమైతే UNICODE
#నిర్వచించు Draw_పాఠ్యం Draw_పాఠ్యం_W
#నిర్వచించు Draw_పాఠ్యం_Ex Draw_పాఠ్యం_Ex_W
#లేకపోతే
#నిర్వచించు Draw_పాఠ్యం Draw_పాఠ్యం_A
#నిర్వచించు Draw_పాఠ్యం_Ex Draw_పాఠ్యం_Ex_A
#అయితే_ముగింపు

  WINUSERAPI పూర్ణాంకం WINAPI Draw_పాఠ్యం_A(HDC hdc,LPCSTR lpch_పాఠ్యం,పూర్ణాంకం cch_పాఠ్యం,LPRECT lprc,UINT format);
  WINUSERAPI పూర్ణాంకం WINAPI Draw_పాఠ్యం_W(HDC hdc,LPCWSTR lpch_పాఠ్యం,పూర్ణాంకం cch_పాఠ్యం,LPRECT lprc,UINT format);
  WINUSERAPI పూర్ణాంకం WINAPI Draw_పాఠ్యం_Ex_A(HDC hdc,LPSTR lpch_పాఠ్యం,పూర్ణాంకం cch_పాఠ్యం,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
  WINUSERAPI పూర్ణాంకం WINAPI Draw_పాఠ్యం_Ex_W(HDC hdc,LPWSTR lpch_పాఠ్యం,పూర్ణాంకం cch_పాఠ్యం,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు బూడిద_String బూడిద_String_W
#నిర్వచించు DrawState DrawStateW
#నిర్వచించు Tabbed_పాఠ్యం_బహిర్గతం Tabbed_పాఠ్యం_బహిర్గతం_W
#నిర్వచించు Get_Tabbed_పాఠ్యం_Extent Get_Tabbed_పాఠ్యం_Extent_W
#లేకపోతే
#నిర్వచించు బూడిద_String బూడిద_String_A
#నిర్వచించు DrawState DrawStateA
#నిర్వచించు Tabbed_పాఠ్యం_బహిర్గతం Tabbed_పాఠ్యం_బహిర్గతం_A
#నిర్వచించు Get_Tabbed_పాఠ్యం_Extent Get_Tabbed_పాఠ్యం_Extent_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI బూడిద_String_A(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_దత్తాంశం,పూర్ణాంకం n_లెక్క,పూర్ణాంకం X,పూర్ణాంకం Y,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు);
  WINUSERAPI WINBOOL WINAPI బూడిద_String_W(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_దత్తాంశం,పూర్ణాంకం n_లెక్క,పూర్ణాంకం X,పూర్ణాంకం Y,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు);

#నిర్వచించు DST_COMPLEX 0x0000
#నిర్వచించు DST_పాఠ్యం 0x0001
#నిర్వచించు DST_PREFIXTEXT 0x0002
#నిర్వచించు DST_ICON 0x0003
#నిర్వచించు DST_BITMAP 0x0004

#నిర్వచించు DSS_సాధారణ 0x0000
#నిర్వచించు DSS_UNION 0x0010
#నిర్వచించు DSS_DISABLED 0x0020
#నిర్వచించు DSS_MONO 0x0080
#నిర్వచించు DSS_HIDEPREFIX 0x0200
#నిర్వచించు DSS_PREFIXONLY 0x0400
#నిర్వచించు DSS_కుడి 0x8000

  WINUSERAPI WINBOOL WINAPI DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_వెనుక,LPARAM l_దత్తాంశం,WPARAM w_దత్తాంశం,పూర్ణాంకం x,పూర్ణాంకం y,పూర్ణాంకం cx,పూర్ణాంకం cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_వెనుక,LPARAM l_దత్తాంశం,WPARAM w_దత్తాంశం,పూర్ణాంకం x,పూర్ణాంకం y,పూర్ణాంకం cx,పూర్ణాంకం cy,UINT uFlags);
  WINUSERAPI LONG WINAPI Tabbed_పాఠ్యం_బహిర్గతం_A(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPCSTR lpString,పూర్ణాంకం ch_లెక్క,పూర్ణాంకం nTabPositions,CONST INT *lpnTabStopPositions,పూర్ణాంకం nTabOrigin);
  WINUSERAPI LONG WINAPI Tabbed_పాఠ్యం_బహిర్గతం_W(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPCWSTR lpString,పూర్ణాంకం ch_లెక్క,పూర్ణాంకం nTabPositions,CONST INT *lpnTabStopPositions,పూర్ణాంకం nTabOrigin);
  WINUSERAPI DWORD WINAPI Get_Tabbed_పాఠ్యం_Extent_A(HDC hdc,LPCSTR lpString,పూర్ణాంకం ch_లెక్క,పూర్ణాంకం nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI DWORD WINAPI Get_Tabbed_పాఠ్యం_Extent_W(HDC hdc,LPCWSTR lpString,పూర్ణాంకం ch_లెక్క,పూర్ణాంకం nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI WINBOOL WINAPI Update_కిటికీ(HWND hWnd);
  WINUSERAPI HWND WINAPI సమితి_చురుకైన_కిటికీ(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_Foreground_కిటికీ(VOID);
  WINUSERAPI WINBOOL WINAPI PaintDesktop(HDC hdc);
  WINUSERAPI VOID WINAPI Switch_గమ్యం_This_కిటికీ(HWND hwnd,WINBOOL fUnknown);
  WINUSERAPI WINBOOL WINAPI సమితి_Foreground_కిటికీ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Allow_సమితి_Foreground_కిటికీ(DWORD dwProcessId);

#నిర్వచించు ASFW_ANY ((DWORD)-1)

  WINUSERAPI WINBOOL WINAPI తాళం_సమితి_Foreground_కిటికీ(UINT u_తాళం_సంకేతం);

#నిర్వచించు LSFW_తాళం 1
#నిర్వచించు LSFW_UNLOCK 2

  WINUSERAPI HWND WINAPI కిటికీ_From_DC(HDC hDC);
  WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
  WINUSERAPI HDC WINAPI GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags);

#నిర్వచించు DCX_కిటికీ 0x00000001L
#నిర్వచించు DCX_CACHE 0x00000002L
#నిర్వచించు DCX_NORESETATTRS 0x00000004L
#నిర్వచించు DCX_CLIPCHILDREN 0x00000008L
#నిర్వచించు DCX_CLIPSIBLINGS 0x00000010L
#నిర్వచించు DCX_PARENTCLIP 0x00000020L
#నిర్వచించు DCX_EXCLUDERGN 0x00000040L
#నిర్వచించు DCX_INTERSECTRGN 0x00000080L
#నిర్వచించు DCX_EXCLUDEUPDATE 0x00000100L
#నిర్వచించు DCX_INTERSECTUPDATE 0x00000200L
#నిర్వచించు DCX_LOCKWINDOWUPDATE 0x00000400L

#నిర్వచించు DCX_VALIDATE 0x00200000L

  WINUSERAPI HDC WINAPI Get_కిటికీ_DC(HWND hWnd);
  WINUSERAPI పూర్ణాంకం WINAPI ReleaseDC(HWND hWnd,HDC hDC);
  WINUSERAPI HDC WINAPI BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
  WINUSERAPI WINBOOL WINAPI చివర_Paint(HWND hWnd,CONST PAINTSTRUCT *lpPaint);
  WINUSERAPI WINBOOL WINAPI GetUpdateRect(HWND hWnd,LPRECT lpRect,WINBOOL bErase);
  WINUSERAPI పూర్ణాంకం WINAPI GetUpdateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI పూర్ణాంకం WINAPI సమితి_కిటికీ_Rgn(HWND hWnd,HRGN hRgn,WINBOOL bRedraw);
  WINUSERAPI పూర్ణాంకం WINAPI Get_కిటికీ_Rgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI పూర్ణాంకం WINAPI Get_కిటికీ_Rgn_Box(HWND hWnd,LPRECT lprc);
  WINUSERAPI పూర్ణాంకం WINAPI ExcludeUpdateRgn(HDC hDC,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI InvalidateRect(HWND hWnd,CONST RECT *lpRect,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRect(HWND hWnd,CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI InvalidateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI WINBOOL WINAPI Redraw_కిటికీ(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#నిర్వచించు RDW_INVALIDATE 0x0001
#నిర్వచించు RDW_INTERNALPAINT 0x0002
#నిర్వచించు RDW_ERASE 0x0004

#నిర్వచించు RDW_VALIDATE 0x0008
#నిర్వచించు RDW_NOINTERNALPAINT 0x0010
#నిర్వచించు RDW_NOERASE 0x0020

#నిర్వచించు RDW_NOCHILDREN 0x0040
#నిర్వచించు RDW_ALLCHILDREN 0x0080

#నిర్వచించు RDW_UPDATENOW 0x0100
#నిర్వచించు RDW_ERASENOW 0x0200

#నిర్వచించు RDW_చట్రం 0x0400
#నిర్వచించు RDW_NOFRAME 0x0800

  WINUSERAPI WINBOOL WINAPI తాళం_కిటికీ_Update(HWND h_Wnd_తాళం);
  WINUSERAPI WINBOOL WINAPI Scroll_కిటికీ(HWND hWnd,పూర్ణాంకం XAmount,పూర్ణాంకం YAmount,CONST RECT *lpRect,CONST RECT *lpClipRect);
  WINUSERAPI WINBOOL WINAPI ScrollDC(HDC hDC,పూర్ణాంకం dx,పూర్ణాంకం dy,CONST RECT *lprcScroll,CONST RECT *lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
  WINUSERAPI పూర్ణాంకం WINAPI Scroll_కిటికీ_Ex(HWND hWnd,పూర్ణాంకం dx,పూర్ణాంకం dy,CONST RECT *prcScroll,CONST RECT *prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);

#నిర్వచించు SW_SCROLLCHILDREN 0x0001
#నిర్వచించు SW_INVALIDATE 0x0002
#నిర్వచించు SW_ERASE 0x0004
#నిర్వచించు SW_SMOOTHSCROLL 0x0010

#నిర్వచితం_కాకపోతే NOSCROLL
  WINUSERAPI పూర్ణాంకం WINAPI సమితి_Scroll_Pos(HWND hWnd,పూర్ణాంకం nBar,పూర్ణాంకం nPos,WINBOOL bRedraw);
  WINUSERAPI పూర్ణాంకం WINAPI GetScrollPos(HWND hWnd,పూర్ణాంకం nBar);
  WINUSERAPI WINBOOL WINAPI సమితి_Scroll_Range(HWND hWnd,పూర్ణాంకం nBar,పూర్ణాంకం nMinPos,పూర్ణాంకం nMaxPos,WINBOOL bRedraw);
  WINUSERAPI WINBOOL WINAPI GetScrollRange(HWND hWnd,పూర్ణాంకం nBar,LPINT lpMinPos,LPINT lpMaxPos);
  WINUSERAPI WINBOOL WINAPI ShowScrollBar(HWND hWnd,పూర్ణాంకం wBar,WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows);

#నిర్వచించు ESB_ENABLE_BOTH 0x0000
#నిర్వచించు ESB_DISABLE_BOTH 0x0003

#నిర్వచించు ESB_DISABLE_ఎడమ 0x0001
#నిర్వచించు ESB_DISABLE_కుడి 0x0002

#నిర్వచించు ESB_DISABLE_పైకి 0x0001
#నిర్వచించు ESB_DISABLE_కిందికి 0x0002

#నిర్వచించు ESB_DISABLE_LTUP ESB_DISABLE_ఎడమ
#నిర్వచించు ESB_DISABLE_RTDN ESB_DISABLE_కుడి
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు సమితి_Prop సమితి_Prop_W
#నిర్వచించు GetProp GetPropW
#నిర్వచించు RemoveProp RemovePropW
#నిర్వచించు EnumPropsEx EnumPropsExW
#నిర్వచించు EnumProps EnumPropsW
#నిర్వచించు సమితి_కిటికీ_పాఠ్యం సమితి_కిటికీ_పాఠ్యం_W
#నిర్వచించు Get_కిటికీ_పాఠ్యం Get_కిటికీ_పాఠ్యం_W
#నిర్వచించు Get_కిటికీ_పాఠ్యం_నిడివి Get_కిటికీ_పాఠ్యం_నిడివి_W
#లేకపోతే
#నిర్వచించు సమితి_Prop సమితి_Prop_A
#నిర్వచించు GetProp GetPropA
#నిర్వచించు RemoveProp RemovePropA
#నిర్వచించు EnumPropsEx EnumPropsExA
#నిర్వచించు EnumProps EnumPropsA
#నిర్వచించు సమితి_కిటికీ_పాఠ్యం సమితి_కిటికీ_పాఠ్యం_A
#నిర్వచించు Get_కిటికీ_పాఠ్యం Get_కిటికీ_పాఠ్యం_A
#నిర్వచించు Get_కిటికీ_పాఠ్యం_నిడివి Get_కిటికీ_పాఠ్యం_నిడివి_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI సమితి_Prop_A(HWND hWnd,LPCSTR lpString,HANDLE h_దత్తాంశం);
  WINUSERAPI WINBOOL WINAPI సమితి_Prop_W(HWND hWnd,LPCWSTR lpString,HANDLE h_దత్తాంశం);
  WINUSERAPI HANDLE WINAPI GetPropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI GetPropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI పూర్ణాంకం WINAPI EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
  WINUSERAPI పూర్ణాంకం WINAPI EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
  WINUSERAPI పూర్ణాంకం WINAPI EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc);
  WINUSERAPI పూర్ణాంకం WINAPI EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc);
  WINUSERAPI WINBOOL WINAPI సమితి_కిటికీ_పాఠ్యం_A(HWND hWnd,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI సమితి_కిటికీ_పాఠ్యం_W(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI పూర్ణాంకం WINAPI Get_కిటికీ_పాఠ్యం_A(HWND hWnd,LPSTR lpString,పూర్ణాంకం n_Max_లెక్క);
  WINUSERAPI పూర్ణాంకం WINAPI Get_కిటికీ_పాఠ్యం_W(HWND hWnd,LPWSTR lpString,పూర్ణాంకం n_Max_లెక్క);
  WINUSERAPI పూర్ణాంకం WINAPI Get_కిటికీ_పాఠ్యం_నిడివి_A(HWND hWnd);
  WINUSERAPI పూర్ణాంకం WINAPI Get_కిటికీ_పాఠ్యం_నిడివి_W(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI GetClientRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Get_కిటికీ_Rect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Adjust_కిటికీ_Rect(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu);
  WINUSERAPI WINBOOL WINAPI Adjust_కిటికీ_Rect_Ex(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu,DWORD dwExStyle);

#నిర్వచించు HELPINFO_కిటికీ 0x0001
#నిర్వచించు HELPINFO_MENUITEM 0x0002

  రకనిర్వచనం నిర్మాణం ట్యాగ్_HELPINFO {
    UINT cb_కొలత;
    పూర్ణాంకం iContextType;
    పూర్ణాంకం iCtrlId;
    HANDLE h_అంశం_Handle;
    DWORD_PTR dwContextId;
    బిందువు_3 MousePos;
  } HELPINFO,*LPHELPINFO;

  WINUSERAPI WINBOOL WINAPI సమితి_కిటికీ_Context_Help_Id(HWND,DWORD);
  WINUSERAPI DWORD WINAPI Get_కిటికీ_Context_Help_Id(HWND);
  WINUSERAPI WINBOOL WINAPI సమితి_Menu_Context_Help_Id(HMENU,DWORD);
  WINUSERAPI DWORD WINAPI GetMenuContextHelpId(HMENU);

#నిర్వచితం_కాకపోతే NOMB

#నిర్వచించు MB_OK 0x00000000L
#నిర్వచించు MB_OKCANCEL 0x00000001L
#నిర్వచించు MB_ABORTRETRYIGNORE 0x00000002L
#నిర్వచించు MB_YESNOCANCEL 0x00000003L
#నిర్వచించు MB_YESNO 0x00000004L
#నిర్వచించు MB_RETRYCANCEL 0x00000005L
#నిర్వచించు MB_CANCELTRYCONTINUE 0x00000006L
#నిర్వచించు MB_ICONHAND 0x00000010L
#నిర్వచించు MB_ICONQUESTION 0x00000020L
#నిర్వచించు MB_ICONEXCLAMATION 0x00000030L
#నిర్వచించు MB_ICONASTERISK 0x00000040L
#నిర్వచించు MB_USERICON 0x00000080L
#నిర్వచించు MB_ICONWARNING MB_ICONEXCLAMATION
#నిర్వచించు MB_ICONERROR MB_ICONHAND
#నిర్వచించు MB_ICONINFORMATION MB_ICONASTERISK
#నిర్వచించు MB_ICONSTOP MB_ICONHAND
#నిర్వచించు MB_DEFBUTTON1 0x00000000L
#నిర్వచించు MB_DEFBUTTON2 0x00000100L
#నిర్వచించు MB_DEFBUTTON3 0x00000200L
#నిర్వచించు MB_DEFBUTTON4 0x00000300L
#నిర్వచించు MB_APPLMODAL 0x00000000L
#నిర్వచించు MB_SYSTEMMODAL 0x00001000L
#నిర్వచించు MB_TASKMODAL 0x00002000L
#నిర్వచించు MB_HELP 0x00004000L
#నిర్వచించు MB_NOFOCUS 0x00008000L
#నిర్వచించు MB_SETFOREGROUND 0x00010000L
#నిర్వచించు MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#నిర్వచించు MB_TOPMOST 0x00040000L
#నిర్వచించు MB_కుడి 0x00080000L
#నిర్వచించు MB_RTLREADING 0x00100000L
#నిర్వచించు MB_SERVICE_NOTIFICATION 0x00200000L
#నిర్వచించు MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#నిర్వచించు MB_TYPEMASK 0x0000000FL
#నిర్వచించు MB_ICONMASK 0x000000F0L
#నిర్వచించు MB_DEFMASK 0x00000F00L
#నిర్వచించు MB_MODEMASK 0x00003000L
#నిర్వచించు MB_MISCMASK 0x0000C000L

#నిర్వచితమైతే UNICODE
#నిర్వచించు సందేశం_Box సందేశం_Box_W
#నిర్వచించు సందేశం_Box_Ex సందేశం_Box_Ex_W
#లేకపోతే
#నిర్వచించు సందేశం_Box సందేశం_Box_A
#నిర్వచించు సందేశం_Box_Ex సందేశం_Box_Ex_A
#అయితే_ముగింపు

  WINUSERAPI పూర్ణాంకం WINAPI సందేశం_Box_A(HWND hWnd,LPCSTR lp_పాఠ్యం,LPCSTR lpCaption,UINT uType);
  WINUSERAPI పూర్ణాంకం WINAPI సందేశం_Box_W(HWND hWnd,LPCWSTR lp_పాఠ్యం,LPCWSTR lpCaption,UINT uType);
  WINUSERAPI పూర్ణాంకం WINAPI సందేశం_Box_Ex_A(HWND hWnd,LPCSTR lp_పాఠ్యం,LPCSTR lpCaption,UINT uType,మాట_3 wLanguageId);
  WINUSERAPI పూర్ణాంకం WINAPI సందేశం_Box_Ex_W(HWND hWnd,LPCWSTR lp_పాఠ్యం,LPCWSTR lpCaption,UINT uType,మాట_3 wLanguageId);

  రకనిర్వచనం VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MSGBOXPARAMSA {
    UINT cb_కొలత;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpsz_పాఠ్యం;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_సందేశం_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSA,*PMSGBOXPARAMSA,*LPMSGBOXPARAMSA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MSGBOXPARAMSW {
    UINT cb_కొలత;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpsz_పాఠ్యం;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_సందేశం_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSW,*PMSGBOXPARAMSW,*LPMSGBOXPARAMSW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం MSGBOXPARAMSW MSGBOXPARAMS;
  రకనిర్వచనం PMSGBOXPARAMSW PMSGBOXPARAMS;
  రకనిర్వచనం LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#లేకపోతే
  రకనిర్వచనం MSGBOXPARAMSA MSGBOXPARAMS;
  రకనిర్వచనం PMSGBOXPARAMSA PMSGBOXPARAMS;
  రకనిర్వచనం LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు సందేశం_Box_పరోక్ష సందేశం_Box_పరోక్ష_W
#లేకపోతే
#నిర్వచించు సందేశం_Box_పరోక్ష సందేశం_Box_పరోక్ష_A
#అయితే_ముగింపు

  WINUSERAPI పూర్ణాంకం WINAPI సందేశం_Box_పరోక్ష_A(CONST MSGBOXPARAMSA *lpmbp);
  WINUSERAPI పూర్ణాంకం WINAPI సందేశం_Box_పరోక్ష_W(CONST MSGBOXPARAMSW *lpmbp);
  WINUSERAPI WINBOOL WINAPI సందేశం_Beep(UINT uType);
#అయితే_ముగింపు

  WINUSERAPI పూర్ణాంకం WINAPI ShowCursor(WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI సమితి_Cursor_Pos(పూర్ణాంకం X,పూర్ణాంకం Y);
  WINUSERAPI HCURSOR WINAPI సమితి_Cursor(HCURSOR hCursor);
  WINUSERAPI WINBOOL WINAPI GetCursorPos(LPPOINT lp_బిందువు);
  WINUSERAPI WINBOOL WINAPI ClipCursor(CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI GetClipCursor(LPRECT lpRect);
  WINUSERAPI HCURSOR WINAPI GetCursor(VOID);
  WINUSERAPI WINBOOL WINAPI CreateCaret(HWND hWnd,HBITMAP hBitmap,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు);
  WINUSERAPI UINT WINAPI Get_Caret_Blink_సమయం(VOID);
  WINUSERAPI WINBOOL WINAPI సమితి_Caret_Blink_సమయం(UINT uMSeconds);
  WINUSERAPI WINBOOL WINAPI DestroyCaret(VOID);
  WINUSERAPI WINBOOL WINAPI HideCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI సమితి_Caret_Pos(పూర్ణాంకం X,పూర్ణాంకం Y);
  WINUSERAPI WINBOOL WINAPI GetCaretPos(LPPOINT lp_బిందువు);
  WINUSERAPI WINBOOL WINAPI Client_గమ్యం_Screen(HWND hWnd,LPPOINT lp_బిందువు);
  WINUSERAPI WINBOOL WINAPI Screen_గమ్యం_Client(HWND hWnd,LPPOINT lp_బిందువు);
  WINUSERAPI పూర్ణాంకం WINAPI Map_కిటికీ_Points(HWND hWndFrom,HWND h_Wnd_గమ్యం,LPPOINT lpPoints,UINT cPoints);
  WINUSERAPI HWND WINAPI కిటికీ_From_బిందువు(బిందువు_3 బిందువు_2);
  WINUSERAPI HWND WINAPI బిడ్డ_కిటికీ_From_బిందువు(HWND h_Wnd_మాతృ,బిందువు_3 బిందువు_2);

#నిర్వచించు CWP_ALL 0x0000
#నిర్వచించు CWP_SKIPINVISIBLE 0x0001
#నిర్వచించు CWP_SKIPDISABLED 0x0002
#నిర్వచించు CWP_SKIPTRANSPARENT 0x0004

  WINUSERAPI HWND WINAPI బిడ్డ_కిటికీ_From_బిందువు_Ex(HWND hwnd,బిందువు_3 pt,UINT flags);

#నిర్వచితం_కాకపోతే NOCOLOR

#నిర్వచించు CTLCOLOR_MSGBOX 0
#నిర్వచించు CTLCOLOR_EDIT 1
#నిర్వచించు CTLCOLOR_LISTBOX 2
#నిర్వచించు CTLCOLOR_BTN 3
#నిర్వచించు CTLCOLOR_DLG 4
#నిర్వచించు CTLCOLOR_SCROLLBAR 5
#నిర్వచించు CTLCOLOR_STATIC 6
#నిర్వచించు CTLCOLOR_MAX 7

#నిర్వచించు COLOR_SCROLLBAR 0
#నిర్వచించు COLOR_BACKGROUND 1
#నిర్వచించు COLOR_ACTIVECAPTION 2
#నిర్వచించు COLOR_INACTIVECAPTION 3
#నిర్వచించు COLOR_MENU 4
#నిర్వచించు COLOR_కిటికీ 5
#నిర్వచించు COLOR_WINDOWFRAME 6
#నిర్వచించు COLOR_MENUTEXT 7
#నిర్వచించు COLOR_WINDOWTEXT 8
#నిర్వచించు COLOR_CAPTIONTEXT 9
#నిర్వచించు COLOR_ACTIVEBORDER 10
#నిర్వచించు COLOR_INACTIVEBORDER 11
#నిర్వచించు COLOR_APPWORKSPACE 12
#నిర్వచించు COLOR_HIGHLIGHT 13
#నిర్వచించు COLOR_HIGHLIGHTTEXT 14
#నిర్వచించు COLOR_BTNFACE 15
#నిర్వచించు COLOR_BTNSHADOW 16
#నిర్వచించు COLOR_GRAYTEXT 17
#నిర్వచించు COLOR_BTNTEXT 18
#నిర్వచించు COLOR_INACTIVECAPTIONTEXT 19
#నిర్వచించు COLOR_BTNHIGHLIGHT 20

#నిర్వచించు COLOR_3DDKSHADOW 21
#నిర్వచించు COLOR_3DLIGHT 22
#నిర్వచించు COLOR_INFOTEXT 23
#నిర్వచించు COLOR_INFOBK 24

#నిర్వచించు COLOR_HOTLIGHT 26
#నిర్వచించు COLOR_GRADIENTACTIVECAPTION 27
#నిర్వచించు COLOR_GRADIENTINACTIVECAPTION 28
#నిర్వచించు COLOR_MENUHILIGHT 29
#నిర్వచించు COLOR_MENUBAR 30

#నిర్వచించు COLOR_DESKTOP COLOR_BACKGROUND
#నిర్వచించు COLOR_3DFACE COLOR_BTNFACE
#నిర్వచించు COLOR_3DSHADOW COLOR_BTNSHADOW
#నిర్వచించు COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#నిర్వచించు COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#నిర్వచించు COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

  WINUSERAPI DWORD WINAPI GetSysColor(పూర్ణాంకం n_సూచీ);
  WINUSERAPI HBRUSH WINAPI GetSysColorBrush(పూర్ణాంకం n_సూచీ);
  WINUSERAPI WINBOOL WINAPI సమితి_Sys_Colors(పూర్ణాంకం cElements,CONST INT *lpaElements,CONST COLORREF *lpa_Rgb_విలువలు);
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI DrawFocusRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI పూర్ణాంకం WINAPI FillRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI పూర్ణాంకం WINAPI చట్రం_Rect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI WINBOOL WINAPI InvertRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI సమితి_Rect(LPRECT lprc,పూర్ణాంకం x_ఎడమ,పూర్ణాంకం y_శిఖరం,పూర్ణాంకం x_కుడి,పూర్ణాంకం yBottom);
  WINUSERAPI WINBOOL WINAPI సమితి_Rect_ఖాళీలు(LPRECT lprc);
  WINUSERAPI WINBOOL WINAPI CopyRect(LPRECT lprcDst,CONST RECT *lprcSrc);
  WINUSERAPI WINBOOL WINAPI InflateRect(LPRECT lprc,పూర్ణాంకం dx,పూర్ణాంకం dy);
  WINUSERAPI WINBOOL WINAPI IntersectRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI UnionRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI వ్యవకలనం_Rect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI స్థానభ్రంశం_Rect(LPRECT lprc,పూర్ణాంకం dx,పూర్ణాంకం dy);
  WINUSERAPI WINBOOL WINAPI Is_Rect_ఖాళీలు(CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI EqualRect(CONST RECT *lprc1,CONST RECT *lprc2);
  WINUSERAPI WINBOOL WINAPI Pt_లోపల_Rect(CONST RECT *lprc,బిందువు_3 pt);

#నిర్వచితం_కాకపోతే NOWINOFFSETS

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_కిటికీ_Long Get_కిటికీ_Long_W
#నిర్వచించు సమితి_కిటికీ_Long సమితి_కిటికీ_Long_W
#లేకపోతే
#నిర్వచించు Get_కిటికీ_Long Get_కిటికీ_Long_A
#నిర్వచించు సమితి_కిటికీ_Long సమితి_కిటికీ_Long_A
#అయితే_ముగింపు

  WINUSERAPI మాట_3 WINAPI Get_కిటికీ_మాట(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI మాట_3 WINAPI సమితి_కిటికీ_మాట(HWND hWnd,పూర్ణాంకం n_సూచీ,మాట_3 w_New_మాట);
  WINUSERAPI LONG WINAPI Get_కిటికీ_Long_A(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI LONG WINAPI Get_కిటికీ_Long_W(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI LONG WINAPI సమితి_కిటికీ_Long_A(HWND hWnd,పూర్ణాంకం n_సూచీ,LONG dwNewLong);
  WINUSERAPI LONG WINAPI సమితి_కిటికీ_Long_W(HWND hWnd,పూర్ణాంకం n_సూచీ,LONG dwNewLong);

#నిర్వచితమైతే _WIN64

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_కిటికీ_Long_Ptr Get_కిటికీ_Long_Ptr_W
#నిర్వచించు సమితి_కిటికీ_Long_Ptr సమితి_కిటికీ_Long_Ptr_W
#లేకపోతే
#నిర్వచించు Get_కిటికీ_Long_Ptr Get_కిటికీ_Long_Ptr_A
#నిర్వచించు సమితి_కిటికీ_Long_Ptr సమితి_కిటికీ_Long_Ptr_A
#అయితే_ముగింపు

  WINUSERAPI LONG_PTR WINAPI Get_కిటికీ_Long_Ptr_A(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI LONG_PTR WINAPI Get_కిటికీ_Long_Ptr_W(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI LONG_PTR WINAPI సమితి_కిటికీ_Long_Ptr_A(HWND hWnd,పూర్ణాంకం n_సూచీ,LONG_PTR dwNewLong);
  WINUSERAPI LONG_PTR WINAPI సమితి_కిటికీ_Long_Ptr_W(HWND hWnd,పూర్ణాంకం n_సూచీ,LONG_PTR dwNewLong);
#లేకపోతే

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_కిటికీ_Long_Ptr Get_కిటికీ_Long_Ptr_W
#నిర్వచించు సమితి_కిటికీ_Long_Ptr సమితి_కిటికీ_Long_Ptr_W
#లేకపోతే
#నిర్వచించు Get_కిటికీ_Long_Ptr Get_కిటికీ_Long_Ptr_A
#నిర్వచించు సమితి_కిటికీ_Long_Ptr సమితి_కిటికీ_Long_Ptr_A
#అయితే_ముగింపు

#నిర్వచించు Get_కిటికీ_Long_Ptr_A Get_కిటికీ_Long_A
#నిర్వచించు Get_కిటికీ_Long_Ptr_W Get_కిటికీ_Long_W
#నిర్వచించు సమితి_కిటికీ_Long_Ptr_A సమితి_కిటికీ_Long_A
#నిర్వచించు సమితి_కిటికీ_Long_Ptr_W సమితి_కిటికీ_Long_W
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు GetClassLong GetClassLongW
#నిర్వచించు సమితి_Class_Long సమితి_Class_Long_W
#లేకపోతే
#నిర్వచించు GetClassLong GetClassLongA
#నిర్వచించు సమితి_Class_Long సమితి_Class_Long_A
#అయితే_ముగింపు

  WINUSERAPI మాట_3 WINAPI Get_Class_మాట(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI మాట_3 WINAPI సమితి_Class_మాట(HWND hWnd,పూర్ణాంకం n_సూచీ,మాట_3 w_New_మాట);
  WINUSERAPI DWORD WINAPI GetClassLongA(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI DWORD WINAPI GetClassLongW(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI DWORD WINAPI సమితి_Class_Long_A(HWND hWnd,పూర్ణాంకం n_సూచీ,LONG dwNewLong);
  WINUSERAPI DWORD WINAPI సమితి_Class_Long_W(HWND hWnd,పూర్ణాంకం n_సూచీ,LONG dwNewLong);

#నిర్వచితమైతే _WIN64

#నిర్వచితమైతే UNICODE
#నిర్వచించు GetClassLongPtr GetClassLongPtrW
#నిర్వచించు సమితి_Class_Long_Ptr సమితి_Class_Long_Ptr_W
#లేకపోతే
#నిర్వచించు GetClassLongPtr GetClassLongPtrA
#నిర్వచించు సమితి_Class_Long_Ptr సమితి_Class_Long_Ptr_A
#అయితే_ముగింపు

  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd,పూర్ణాంకం n_సూచీ);
  WINUSERAPI ULONG_PTR WINAPI సమితి_Class_Long_Ptr_A(HWND hWnd,పూర్ణాంకం n_సూచీ,LONG_PTR dwNewLong);
  WINUSERAPI ULONG_PTR WINAPI సమితి_Class_Long_Ptr_W(HWND hWnd,పూర్ణాంకం n_సూచీ,LONG_PTR dwNewLong);
#లేకపోతే
#నిర్వచితమైతే UNICODE
#నిర్వచించు GetClassLongPtr GetClassLongPtrW
#నిర్వచించు సమితి_Class_Long_Ptr సమితి_Class_Long_Ptr_W
#లేకపోతే
#నిర్వచించు GetClassLongPtr GetClassLongPtrA
#నిర్వచించు సమితి_Class_Long_Ptr సమితి_Class_Long_Ptr_A
#అయితే_ముగింపు

#నిర్వచించు GetClassLongPtrA GetClassLongA
#నిర్వచించు GetClassLongPtrW GetClassLongW
#నిర్వచించు సమితి_Class_Long_Ptr_A సమితి_Class_Long_A
#నిర్వచించు సమితి_Class_Long_Ptr_W సమితి_Class_Long_W
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు కనుగొను_కిటికీ కనుగొను_కిటికీ_W
#నిర్వచించు కనుగొను_కిటికీ_Ex కనుగొను_కిటికీ_Ex_W
#నిర్వచించు GetClassName GetClassNameW
#లేకపోతే
#నిర్వచించు కనుగొను_కిటికీ కనుగొను_కిటికీ_A
#నిర్వచించు కనుగొను_కిటికీ_Ex కనుగొను_కిటికీ_Ex_A
#నిర్వచించు GetClassName GetClassNameA
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI GetProcessDefaultLayout(DWORD *pdwDefaultLayout);
  WINUSERAPI WINBOOL WINAPI సమితి_Process_Default_Layout(DWORD dwDefaultLayout);
  WINUSERAPI HWND WINAPI Get_Desktop_కిటికీ(VOID);
  WINUSERAPI HWND WINAPI Get_మాతృ(HWND hWnd);
  WINUSERAPI HWND WINAPI సమితి_మాతృ(HWND h_Wnd_బిడ్డ,HWND h_Wnd_New_మాతృ);
  WINUSERAPI WINBOOL WINAPI Enum_బిడ్డ_Windows(HWND h_Wnd_మాతృ,WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI HWND WINAPI కనుగొను_కిటికీ_A(LPCSTR lpClassName,LPCSTR lp_కిటికీ_Name);
  WINUSERAPI HWND WINAPI కనుగొను_కిటికీ_W(LPCWSTR lpClassName,LPCWSTR lp_కిటికీ_Name);
  WINUSERAPI HWND WINAPI కనుగొను_కిటికీ_Ex_A(HWND h_Wnd_మాతృ,HWND h_Wnd_బిడ్డ_After,LPCSTR lpszClass,LPCSTR lpsz_కిటికీ);
  WINUSERAPI HWND WINAPI కనుగొను_కిటికీ_Ex_W(HWND h_Wnd_మాతృ,HWND h_Wnd_బిడ్డ_After,LPCWSTR lpszClass,LPCWSTR lpsz_కిటికీ);
  WINUSERAPI HWND WINAPI Get_Shell_కిటికీ(VOID);
  WINUSERAPI WINBOOL WINAPI రిజిస్టరు_Shell_Hook_కిటికీ(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI Deregister_Shell_Hook_కిటికీ(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);

#నిర్వచించు EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(Handle_గమ్యం_Ulong(hTask),lpfn,lParam)

  WINUSERAPI పూర్ణాంకం WINAPI GetClassNameA(HWND hWnd,LPSTR lpClassName,పూర్ణాంకం n_Max_లెక్క);
  WINUSERAPI పూర్ణాంకం WINAPI GetClassNameW(HWND hWnd,LPWSTR lpClassName,పూర్ణాంకం n_Max_లెక్క);
  WINUSERAPI HWND WINAPI Get_శిఖరం_కిటికీ(HWND hWnd);

#నిర్వచించు Get_తదుపరి_కిటికీ(hWnd,wCmd) Get_కిటికీ(hWnd,wCmd)
#నిర్వచించు Get_Sys_Modal_కిటికీ() (ఖాళీ)
#నిర్వచించు సమితి_Sys_Modal_కిటికీ(hWnd) (ఖాళీ)

  WINUSERAPI DWORD WINAPI Get_కిటికీ_Thread_Process_Id(HWND hWnd,LPDWORD lpdwProcessId);
  WINUSERAPI WINBOOL WINAPI IsGUIThread(WINBOOL bConvert);

#నిర్వచించు Get_కిటికీ_Task(hWnd) ((HANDLE)(DWORD_PTR)Get_కిటికీ_Thread_Process_Id(hWnd,ఖాళీ))

  WINUSERAPI HWND WINAPI Get_చివరి_చురుకైన_Popup(HWND hWnd);

#నిర్వచించు GW_HWNDFIRST 0
#నిర్వచించు GW_HWNDLAST 1
#నిర్వచించు GW_HWNDNEXT 2
#నిర్వచించు GW_HWNDPREV 3
#నిర్వచించు GW_OWNER 4
#నిర్వచించు GW_బిడ్డ 5
#నిర్వచించు GW_ENABLEDPOPUP 6
#నిర్వచించు GW_MAX 6

  WINUSERAPI HWND WINAPI Get_కిటికీ(HWND hWnd,UINT uCmd);

#నిర్వచితం_కాకపోతే NOWH

#నిర్వచితమైతే UNICODE
#నిర్వచించు సమితి_Windows_Hook సమితి_Windows_Hook_W
#నిర్వచించు సమితి_Windows_Hook_Ex సమితి_Windows_Hook_Ex_W
#లేకపోతే
#నిర్వచించు సమితి_Windows_Hook సమితి_Windows_Hook_A
#నిర్వచించు సమితి_Windows_Hook_Ex సమితి_Windows_Hook_Ex_A
#అయితే_ముగింపు

  WINUSERAPI HHOOK WINAPI సమితి_Windows_Hook_A(పూర్ణాంకం nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI సమితి_Windows_Hook_W(పూర్ణాంకం nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHook(పూర్ణాంకం n_సంకేతం,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI సమితి_Windows_Hook_Ex_A(పూర్ణాంకం idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI HHOOK WINAPI సమితి_Windows_Hook_Ex_W(పూర్ణాంకం idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);
  WINUSERAPI LRESULT WINAPI Call_తదుపరి_Hook_Ex(HHOOK hhk,పూర్ణాంకం n_సంకేతం,WPARAM wParam,LPARAM lParam);
#నిర్వచించు DefHookProc(n_సంకేతం,wParam,lParam,phhk) Call_తదుపరి_Hook_Ex(*phhk,n_సంకేతం,wParam,lParam)
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOMENUS

#నిర్వచించు MF_చొప్పించు 0x00000000L
#నిర్వచించు MF_CHANGE 0x00000080L
#నిర్వచించు MF_APPEND 0x00000100L
#నిర్వచించు MF_DELETE 0x00000200L
#నిర్వచించు MF_REMOVE 0x00001000L
#నిర్వచించు MF_BYCOMMAND 0x00000000L
#నిర్వచించు MF_BYPOSITION 0x00000400L
#నిర్వచించు MF_SEPARATOR 0x00000800L
#నిర్వచించు MF_ENABLED 0x00000000L
#నిర్వచించు MF_GRAYED 0x00000001L
#నిర్వచించు MF_DISABLED 0x00000002L
#నిర్వచించు MF_UNCHECKED 0x00000000L
#నిర్వచించు MF_CHECKED 0x00000008L
#నిర్వచించు MF_USECHECKBITMAPS 0x00000200L
#నిర్వచించు MF_STRING 0x00000000L
#నిర్వచించు MF_BITMAP 0x00000004L
#నిర్వచించు MF_OWNERDRAW 0x00000100L
#నిర్వచించు MF_POPUP 0x00000010L
#నిర్వచించు MF_MENUBARBREAK 0x00000020L
#నిర్వచించు MF_MENUBREAK 0x00000040L
#నిర్వచించు MF_UNHILITE 0x00000000L
#నిర్వచించు MF_HILITE 0x00000080L
#నిర్వచించు MF_DEFAULT 0x00001000L
#నిర్వచించు MF_SYSMENU 0x00002000L
#నిర్వచించు MF_HELP 0x00004000L
#నిర్వచించు MF_RIGHTJUSTIFY 0x00004000L
#నిర్వచించు MF_MOUSESELECT 0x00008000L
#నిర్వచించు MF_చివర 0x00000080L

#నిర్వచించు MFT_STRING MF_STRING
#నిర్వచించు MFT_BITMAP MF_BITMAP
#నిర్వచించు MFT_MENUBARBREAK MF_MENUBARBREAK
#నిర్వచించు MFT_MENUBREAK MF_MENUBREAK
#నిర్వచించు MFT_OWNERDRAW MF_OWNERDRAW
#నిర్వచించు MFT_RADIOCHECK 0x00000200L
#నిర్వచించు MFT_SEPARATOR MF_SEPARATOR
#నిర్వచించు MFT_RIGHTORDER 0x00002000L
#నిర్వచించు MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#నిర్వచించు MFS_GRAYED 0x00000003L
#నిర్వచించు MFS_DISABLED MFS_GRAYED
#నిర్వచించు MFS_CHECKED MF_CHECKED
#నిర్వచించు MFS_HILITE MF_HILITE
#నిర్వచించు MFS_ENABLED MF_ENABLED
#నిర్వచించు MFS_UNCHECKED MF_UNCHECKED
#నిర్వచించు MFS_UNHILITE MF_UNHILITE
#నిర్వచించు MFS_DEFAULT MF_DEFAULT

  WINUSERAPI WINBOOL WINAPI Check_Menu_Radio_అంశం(HMENU hmenu,UINT మొదటి,UINT చివరి,UINT check,UINT flags);

  రకనిర్వచనం నిర్మాణం {
    మాట_3 సంస్కరణ_సంఖ్య;
    మాట_3 స్థానభ్రంశం;
  } MENUITEMTEMPLATEHEADER,*PMENUITEMTEMPLATEHEADER;

  రకనిర్వచనం నిర్మాణం {
    మాట_3 mtOption;
    మాట_3 mtID;
    WCHAR mtString[1];
  } MENUITEMTEMPLATE,*PMENUITEMTEMPLATE;
#నిర్వచించు MF_చివర 0x00000080L
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOSYSCOMMANDS

#నిర్వచించు SC_కొలత 0xF000
#నిర్వచించు SC_MOVE 0xF010
#నిర్వచించు SC_MINIMIZE 0xF020
#నిర్వచించు SC_MAXIMIZE 0xF030
#నిర్వచించు SC_NEXTWINDOW 0xF040
#నిర్వచించు SC_PREVWINDOW 0xF050
#నిర్వచించు SC_CLOSE 0xF060
#నిర్వచించు SC_VSCROLL 0xF070
#నిర్వచించు SC_HSCROLL 0xF080
#నిర్వచించు SC_MOUSEMENU 0xF090
#నిర్వచించు SC_KEYMENU 0xF100
#నిర్వచించు SC_ARRANGE 0xF110
#నిర్వచించు SC_RESTORE 0xF120
#నిర్వచించు SC_TASKLIST 0xF130
#నిర్వచించు SC_SCREENSAVE 0xF140
#నిర్వచించు SC_HOTKEY 0xF150
#నిర్వచించు SC_DEFAULT 0xF160
#నిర్వచించు SC_MONITORPOWER 0xF170
#నిర్వచించు SC_CONTEXTHELP 0xF180
#నిర్వచించు SC_SEPARATOR 0xF00F
#నిర్వచించు SC_ICON SC_MINIMIZE
#నిర్వచించు SC_ZOOM SC_MAXIMIZE
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు ఎక్కించు_Bitmap ఎక్కించు_Bitmap_W
#నిర్వచించు ఎక్కించు_Cursor ఎక్కించు_Cursor_W
#నిర్వచించు ఎక్కించు_Cursor_From_File ఎక్కించు_Cursor_From_File_W
#లేకపోతే
#నిర్వచించు ఎక్కించు_Bitmap ఎక్కించు_Bitmap_A
#నిర్వచించు ఎక్కించు_Cursor ఎక్కించు_Cursor_A
#నిర్వచించు ఎక్కించు_Cursor_From_File ఎక్కించు_Cursor_From_File_A
#అయితే_ముగింపు

  WINUSERAPI HBITMAP WINAPI ఎక్కించు_Bitmap_A(HINSTANCE hInstance,LPCSTR lpBitmapName);
  WINUSERAPI HBITMAP WINAPI ఎక్కించు_Bitmap_W(HINSTANCE hInstance,LPCWSTR lpBitmapName);
  WINUSERAPI HCURSOR WINAPI ఎక్కించు_Cursor_A(HINSTANCE hInstance,LPCSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI ఎక్కించు_Cursor_W(HINSTANCE hInstance,LPCWSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI ఎక్కించు_Cursor_From_File_A(LPCSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI ఎక్కించు_Cursor_From_File_W(LPCWSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI CreateCursor(HINSTANCE hInst,పూర్ణాంకం xHotSpot,పూర్ణాంకం yHotSpot,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు,CONST VOID *pvANDPlane,CONST VOID *pvXORPlane);
  WINUSERAPI WINBOOL WINAPI DestroyCursor(HCURSOR hCursor);

#నిర్వచించు CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

#నిర్వచించు IDC_ARROW MAKEINTRESOURCE(32512)
#నిర్వచించు IDC_IBEAM MAKEINTRESOURCE(32513)
#నిర్వచించు IDC_WAIT MAKEINTRESOURCE(32514)
#నిర్వచించు IDC_CROSS MAKEINTRESOURCE(32515)
#నిర్వచించు IDC_UPARROW MAKEINTRESOURCE(32516)
#నిర్వచించు IDC_కొలత MAKEINTRESOURCE(32640)
#నిర్వచించు IDC_ICON MAKEINTRESOURCE(32641)
#నిర్వచించు IDC_SIZENWSE MAKEINTRESOURCE(32642)
#నిర్వచించు IDC_SIZENESW MAKEINTRESOURCE(32643)
#నిర్వచించు IDC_SIZEWE MAKEINTRESOURCE(32644)
#నిర్వచించు IDC_SIZENS MAKEINTRESOURCE(32645)
#నిర్వచించు IDC_SIZEALL MAKEINTRESOURCE(32646)
#నిర్వచించు IDC_NO MAKEINTRESOURCE(32648)
#నిర్వచించు IDC_HAND MAKEINTRESOURCE(32649)
#నిర్వచించు IDC_APPSTARTING MAKEINTRESOURCE(32650)
#నిర్వచించు IDC_HELP MAKEINTRESOURCE(32651)

  WINUSERAPI WINBOOL WINAPI సమితి_System_Cursor(HCURSOR hcur,DWORD id);

  రకనిర్వచనం నిర్మాణం _ICONINFO {
    WINBOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbm_ముసుగు;
    HBITMAP hbmColor;
  } ICONINFO;
  రకనిర్వచనం ICONINFO *PICONINFO;

#నిర్వచితమైతే UNICODE
#నిర్వచించు ఎక్కించు_Icon ఎక్కించు_Icon_W
#నిర్వచించు వ్యక్తిగత_వెలికితీయి_Icons వ్యక్తిగత_వెలికితీయి_Icons_W
#లేకపోతే
#నిర్వచించు ఎక్కించు_Icon ఎక్కించు_Icon_A
#నిర్వచించు వ్యక్తిగత_వెలికితీయి_Icons వ్యక్తిగత_వెలికితీయి_Icons_A
#అయితే_ముగింపు

  WINUSERAPI HICON WINAPI ఎక్కించు_Icon_A(HINSTANCE hInstance,LPCSTR lpIconName);
  WINUSERAPI HICON WINAPI ఎక్కించు_Icon_W(HINSTANCE hInstance,LPCWSTR lpIconName);
  WINUSERAPI UINT WINAPI వ్యక్తిగత_వెలికితీయి_Icons_A(LPCSTR szFileName,పూర్ణాంకం n_Icon_సూచీ,పూర్ణాంకం cxIcon,పూర్ణాంకం cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI UINT WINAPI వ్యక్తిగత_వెలికితీయి_Icons_W(LPCWSTR szFileName,పూర్ణాంకం n_Icon_సూచీ,పూర్ణాంకం cxIcon,పూర్ణాంకం cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI HICON WINAPI CreateIcon(HINSTANCE hInstance,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు,BYTE cPlanes,BYTE c_బిట్లు_Pixel,CONST BYTE *lpbANDbits,CONST BYTE *lpbXORbits);
  WINUSERAPI WINBOOL WINAPI DestroyIcon(HICON hIcon);
  WINUSERAPI పూర్ణాంకం WINAPI LookupIconIdFromDirectory(PBYTE presbits,WINBOOL fIcon);
  WINUSERAPI పూర్ణాంకం WINAPI LookupIconIdFromDirectoryEx(PBYTE presbits,WINBOOL fIcon,పూర్ణాంకం cxDesired,పూర్ణాంకం cyDesired,UINT Flags);
  WINUSERAPI HICON WINAPI CreateIconFromResource(PBYTE presbits,DWORD dw_Res_కొలత,WINBOOL fIcon,DWORD dwVer);
  WINUSERAPI HICON WINAPI CreateIconFromResourceEx(PBYTE presbits,DWORD dw_Res_కొలత,WINBOOL fIcon,DWORD dwVer,పూర్ణాంకం cxDesired,పూర్ణాంకం cyDesired,UINT Flags);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CURSORSHAPE {
    పూర్ణాంకం xHotSpot;
    పూర్ణాంకం yHotSpot;
    పూర్ణాంకం cx;
    పూర్ణాంకం cy;
    పూర్ణాంకం cb_వెడల్పు;
    BYTE Planes;
    BYTE బిట్లు_Pixel;
  } CURSORSHAPE,*LPCURSORSHAPE;

#నిర్వచించు IMAGE_BITMAP 0
#నిర్వచించు IMAGE_ICON 1
#నిర్వచించు IMAGE_CURSOR 2
#నిర్వచించు IMAGE_ENHMETAFILE 3

#నిర్వచించు LR_DEFAULTCOLOR 0x0000
#నిర్వచించు LR_MONOCHROME 0x0001
#నిర్వచించు LR_COLOR 0x0002
#నిర్వచించు LR_COPYRETURNORG 0x0004
#నిర్వచించు LR_COPYDELETEORG 0x0008
#నిర్వచించు LR_LOADFROMFILE 0x0010
#నిర్వచించు LR_LOADTRANSPARENT 0x0020
#నిర్వచించు LR_DEFAULTSIZE 0x0040
#నిర్వచించు LR_VGACOLOR 0x0080
#నిర్వచించు LR_LOADMAP3DCOLORS 0x1000
#నిర్వచించు LR_CREATEDIBSECTION 0x2000
#నిర్వచించు LR_COPYFROMRESOURCE 0x4000
#నిర్వచించు LR_SHARED 0x8000

#నిర్వచితమైతే UNICODE
#నిర్వచించు ఎక్కించు_Image ఎక్కించు_Image_W
#లేకపోతే
#నిర్వచించు ఎక్కించు_Image ఎక్కించు_Image_A
#అయితే_ముగింపు

  WINUSERAPI HANDLE WINAPI ఎక్కించు_Image_A(HINSTANCE hInst,LPCSTR name,UINT type,పూర్ణాంకం cx,పూర్ణాంకం cy,UINT fu_ఎక్కించు);
  WINUSERAPI HANDLE WINAPI ఎక్కించు_Image_W(HINSTANCE hInst,LPCWSTR name,UINT type,పూర్ణాంకం cx,పూర్ణాంకం cy,UINT fu_ఎక్కించు);
  WINUSERAPI HANDLE WINAPI CopyImage(HANDLE h,UINT type,పూర్ణాంకం cx,పూర్ణాంకం cy,UINT flags);

#నిర్వచించు DI_ముసుగు 0x0001
#నిర్వచించు DI_IMAGE 0x0002
#నిర్వచించు DI_సాధారణ 0x0003
#నిర్వచించు DI_COMPAT 0x0004
#నిర్వచించు DI_DEFAULTSIZE 0x0008
#నిర్వచించు DI_NOMIRROR 0x0010

  WINUSERAPI WINBOOL WINAPI DrawIconEx(HDC hdc,పూర్ణాంకం x_ఎడమ,పూర్ణాంకం y_శిఖరం,HICON hIcon,పూర్ణాంకం cx_వెడల్పు,పూర్ణాంకం cy_వెడల్పు,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
  WINUSERAPI HICON WINAPI Create_Icon_పరోక్ష(PICONINFO piconinfo);
  WINUSERAPI HICON WINAPI CopyIcon(HICON hIcon);
  WINUSERAPI WINBOOL WINAPI GetIconInfo(HICON hIcon,PICONINFO piconinfo);

#నిర్వచించు RES_ICON 1
#నిర్వచించు RES_CURSOR 2

#నిర్వచితమైతే OEMRESOURCE

#నిర్వచించు OBM_CLOSE 32754
#నిర్వచించు OBM_UPARROW 32753
#నిర్వచించు OBM_DNARROW 32752
#నిర్వచించు OBM_RGARROW 32751
#నిర్వచించు OBM_LFARROW 32750
#నిర్వచించు OBM_REDUCE 32749
#నిర్వచించు OBM_ZOOM 32748
#నిర్వచించు OBM_RESTORE 32747
#నిర్వచించు OBM_REDUCED 32746
#నిర్వచించు OBM_ZOOMD 32745
#నిర్వచించు OBM_RESTORED 32744
#నిర్వచించు OBM_UPARROWD 32743
#నిర్వచించు OBM_DNARROWD 32742
#నిర్వచించు OBM_RGARROWD 32741
#నిర్వచించు OBM_LFARROWD 32740
#నిర్వచించు OBM_MNARROW 32739
#నిర్వచించు OBM_COMBO 32738
#నిర్వచించు OBM_UPARROWI 32737
#నిర్వచించు OBM_DNARROWI 32736
#నిర్వచించు OBM_RGARROWI 32735
#నిర్వచించు OBM_LFARROWI 32734

#నిర్వచించు OBM_OLD_CLOSE 32767
#నిర్వచించు OBM_కొలత 32766
#నిర్వచించు OBM_OLD_UPARROW 32765
#నిర్వచించు OBM_OLD_DNARROW 32764
#నిర్వచించు OBM_OLD_RGARROW 32763
#నిర్వచించు OBM_OLD_LFARROW 32762
#నిర్వచించు OBM_BTSIZE 32761
#నిర్వచించు OBM_CHECK 32760
#నిర్వచించు OBM_CHECKBOXES 32759
#నిర్వచించు OBM_BTNCORNERS 32758
#నిర్వచించు OBM_OLD_REDUCE 32757
#నిర్వచించు OBM_OLD_ZOOM 32756
#నిర్వచించు OBM_OLD_RESTORE 32755

#నిర్వచించు OCR_సాధారణ 32512
#నిర్వచించు OCR_IBEAM 32513
#నిర్వచించు OCR_WAIT 32514
#నిర్వచించు OCR_CROSS 32515
#నిర్వచించు OCR_పైకి 32516
#నిర్వచించు OCR_కొలత 32640
#నిర్వచించు OCR_ICON 32641
#నిర్వచించు OCR_SIZENWSE 32642
#నిర్వచించు OCR_SIZENESW 32643
#నిర్వచించు OCR_SIZEWE 32644
#నిర్వచించు OCR_SIZENS 32645
#నిర్వచించు OCR_SIZEALL 32646
#నిర్వచించు OCR_ICOCUR 32647
#నిర్వచించు OCR_NO 32648
#నిర్వచించు OCR_HAND 32649
#నిర్వచించు OCR_APPSTARTING 32650

#నిర్వచించు OIC_SAMPLE 32512
#నిర్వచించు OIC_HAND 32513
#నిర్వచించు OIC_QUES 32514
#నిర్వచించు OIC_BANG 32515
#నిర్వచించు OIC_NOTE 32516
#నిర్వచించు OIC_WINLOGO 32517
#నిర్వచించు OIC_WARNING OIC_BANG
#నిర్వచించు OIC_ERROR OIC_HAND
#నిర్వచించు OIC_INFORMATION OIC_NOTE
#అయితే_ముగింపు

#నిర్వచించు ORD_LANGDRIVER 1

#నిర్వచితం_కాకపోతే NOICONS

#నిర్వచితమైతే RC_INVOKED
#నిర్వచించు IDI_APPLICATION 32512
#నిర్వచించు IDI_HAND 32513
#నిర్వచించు IDI_QUESTION 32514
#నిర్వచించు IDI_EXCLAMATION 32515
#నిర్వచించు IDI_ASTERISK 32516
#నిర్వచించు IDI_WINLOGO 32517
#లేకపోతే
#నిర్వచించు IDI_APPLICATION MAKEINTRESOURCE(32512)
#నిర్వచించు IDI_HAND MAKEINTRESOURCE(32513)
#నిర్వచించు IDI_QUESTION MAKEINTRESOURCE(32514)
#నిర్వచించు IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#నిర్వచించు IDI_ASTERISK MAKEINTRESOURCE(32516)
#నిర్వచించు IDI_WINLOGO MAKEINTRESOURCE(32517)
#అయితే_ముగింపు

#నిర్వచించు IDI_WARNING IDI_EXCLAMATION
#నిర్వచించు IDI_ERROR IDI_HAND
#నిర్వచించు IDI_INFORMATION IDI_ASTERISK
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు ఎక్కించు_String ఎక్కించు_String_W
#లేకపోతే
#నిర్వచించు ఎక్కించు_String ఎక్కించు_String_A
#అయితే_ముగింపు

  WINUSERAPI పూర్ణాంకం WINAPI ఎక్కించు_String_A(HINSTANCE hInstance,UINT uID,LPSTR lp_బఫరు,పూర్ణాంకం cch_బఫరు_Max);
  WINUSERAPI పూర్ణాంకం WINAPI ఎక్కించు_String_W(HINSTANCE hInstance,UINT uID,LPWSTR lp_బఫరు,పూర్ణాంకం cch_బఫరు_Max);

#నిర్వచించు IDOK 1
#నిర్వచించు IDCANCEL 2
#నిర్వచించు IDABORT 3
#నిర్వచించు IDRETRY 4
#నిర్వచించు IDIGNORE 5
#నిర్వచించు IDYES 6
#నిర్వచించు IDNO 7
#నిర్వచించు IDCLOSE 8
#నిర్వచించు IDHELP 9
#నిర్వచించు IDTRYAGAIN 10
#నిర్వచించు IDCONTINUE 11

#నిర్వచితం_కాకపోతే IDTIMEOUT
#నిర్వచించు IDTIMEOUT 32000
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOCTLMGR

#నిర్వచితం_కాకపోతే NOWINSTYLES
#నిర్వచించు ES_ఎడమ 0x0000L
#నిర్వచించు ES_CENTER 0x0001L
#నిర్వచించు ES_కుడి 0x0002L
#నిర్వచించు ES_MULTILINE 0x0004L
#నిర్వచించు ES_UPPERCASE 0x0008L
#నిర్వచించు ES_LOWERCASE 0x0010L
#నిర్వచించు ES_PASSWORD 0x0020L
#నిర్వచించు ES_AUTOVSCROLL 0x0040L
#నిర్వచించు ES_AUTOHSCROLL 0x0080L
#నిర్వచించు ES_NOHIDESEL 0x0100L
#నిర్వచించు ES_OEMCONVERT 0x0400L
#నిర్వచించు ES_READONLY 0x0800L
#నిర్వచించు ES_WANTRETURN 0x1000L
#నిర్వచించు ES_సంఖ్య 0x2000L
#అయితే_ముగింపు

#నిర్వచించు EN_SETFOCUS 0x0100
#నిర్వచించు EN_KILLFOCUS 0x0200
#నిర్వచించు EN_CHANGE 0x0300
#నిర్వచించు EN_UPDATE 0x0400
#నిర్వచించు EN_ERRSPACE 0x0500
#నిర్వచించు EN_MAXTEXT 0x0501
#నిర్వచించు EN_HSCROLL 0x0601
#నిర్వచించు EN_VSCROLL 0x0602
#నిర్వచించు EN_ALIGN_LTR_EC 0x0700
#నిర్వచించు EN_ALIGN_RTL_EC 0x0701

#నిర్వచించు EC_LEFTMARGIN 0x0001
#నిర్వచించు EC_RIGHTMARGIN 0x0002
#నిర్వచించు EC_USEFONTINFO 0xffff

#నిర్వచించు EMSIS_COMPOSITIONSTRING 0x0001

#నిర్వచించు EIMES_GETCOMPSTRATONCE 0x0001
#నిర్వచించు EIMES_CANCELCOMPSTRINFOCUS 0x0002
#నిర్వచించు EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#నిర్వచితం_కాకపోతే NOWINMESSAGES

#నిర్వచించు EM_GETSEL 0x00B0
#నిర్వచించు EM_SETSEL 0x00B1
#నిర్వచించు EM_GETRECT 0x00B2
#నిర్వచించు EM_SETRECT 0x00B3
#నిర్వచించు EM_SETRECTNP 0x00B4
#నిర్వచించు EM_SCROLL 0x00B5
#నిర్వచించు EM_LINESCROLL 0x00B6
#నిర్వచించు EM_SCROLLCARET 0x00B7
#నిర్వచించు EM_GETMODIFY 0x00B8
#నిర్వచించు EM_SETMODIFY 0x00B9
#నిర్వచించు EM_GETLINECOUNT 0x00BA
#నిర్వచించు EM_LINEINDEX 0x00BB
#నిర్వచించు EM_SETHANDLE 0x00BC
#నిర్వచించు EM_GETHANDLE 0x00BD
#నిర్వచించు EM_GETTHUMB 0x00BE
#నిర్వచించు EM_LINELENGTH 0x00C1
#నిర్వచించు EM_REPLACESEL 0x00C2
#నిర్వచించు EM_GETLINE 0x00C4
#నిర్వచించు EM_LIMITTEXT 0x00C5
#నిర్వచించు EM_CANUNDO 0x00C6
#నిర్వచించు EM_UNDO 0x00C7
#నిర్వచించు EM_FMTLINES 0x00C8
#నిర్వచించు EM_LINEFROMCHAR 0x00C9
#నిర్వచించు EM_SETTABSTOPS 0x00CB
#నిర్వచించు EM_SETPASSWORDCHAR 0x00CC
#నిర్వచించు EM_EMPTYUNDOBUFFER 0x00CD
#నిర్వచించు EM_GETFIRSTVISIBLELINE 0x00CE
#నిర్వచించు EM_SETREADONLY 0x00CF
#నిర్వచించు EM_SETWORDBREAKPROC 0x00D0
#నిర్వచించు EM_GETWORDBREAKPROC 0x00D1
#నిర్వచించు EM_GETPASSWORDCHAR 0x00D2
#నిర్వచించు EM_SETMARGINS 0x00D3
#నిర్వచించు EM_GETMARGINS 0x00D4
#నిర్వచించు EM_SETLIMITTEXT EM_LIMITTEXT
#నిర్వచించు EM_GETLIMITTEXT 0x00D5
#నిర్వచించు EM_POSFROMCHAR 0x00D6
#నిర్వచించు EM_CHARFROMPOS 0x00D7
#నిర్వచించు EM_SETIMESTATUS 0x00D8
#నిర్వచించు EM_GETIMESTATUS 0x00D9
#అయితే_ముగింపు

#నిర్వచించు WB_ఎడమ 0
#నిర్వచించు WB_కుడి 1
#నిర్వచించు WB_ISDELIMITER 2

#నిర్వచించు BS_PUSHBUTTON 0x00000000L
#నిర్వచించు BS_DEFPUSHBUTTON 0x00000001L
#నిర్వచించు BS_CHECKBOX 0x00000002L
#నిర్వచించు BS_AUTOCHECKBOX 0x00000003L
#నిర్వచించు BS_RADIOBUTTON 0x00000004L
#నిర్వచించు BS_3STATE 0x00000005L
#నిర్వచించు BS_AUTO3STATE 0x00000006L
#నిర్వచించు BS_GROUPBOX 0x00000007L
#నిర్వచించు BS_USERBUTTON 0x00000008L
#నిర్వచించు BS_AUTORADIOBUTTON 0x00000009L
#నిర్వచించు BS_PUSHBOX 0x0000000AL
#నిర్వచించు BS_OWNERDRAW 0x0000000BL
#నిర్వచించు BS_TYPEMASK 0x0000000FL
#నిర్వచించు BS_LEFTTEXT 0x00000020L
#నిర్వచించు BS_పాఠ్యం 0x00000000L
#నిర్వచించు BS_ICON 0x00000040L
#నిర్వచించు BS_BITMAP 0x00000080L
#నిర్వచించు BS_ఎడమ 0x00000100L
#నిర్వచించు BS_కుడి 0x00000200L
#నిర్వచించు BS_CENTER 0x00000300L
#నిర్వచించు BS_శిఖరం 0x00000400L
#నిర్వచించు BS_BOTTOM 0x00000800L
#నిర్వచించు BS_VCENTER 0x00000C00L
#నిర్వచించు BS_PUSHLIKE 0x00001000L
#నిర్వచించు BS_MULTILINE 0x00002000L
#నిర్వచించు BS_NOTIFY 0x00004000L
#నిర్వచించు BS_FLAT 0x00008000L
#నిర్వచించు BS_RIGHTBUTTON BS_LEFTTEXT

#నిర్వచించు BN_CLICKED 0
#నిర్వచించు BN_PAINT 1
#నిర్వచించు BN_HILITE 2
#నిర్వచించు BN_UNHILITE 3
#నిర్వచించు BN_DISABLE 4
#నిర్వచించు BN_DOUBLECLICKED 5
#నిర్వచించు BN_PUSHED BN_HILITE
#నిర్వచించు BN_UNPUSHED BN_UNHILITE
#నిర్వచించు BN_DBLCLK BN_DOUBLECLICKED
#నిర్వచించు BN_SETFOCUS 6
#నిర్వచించు BN_KILLFOCUS 7

#నిర్వచించు BM_GETCHECK 0x00F0
#నిర్వచించు BM_SETCHECK 0x00F1
#నిర్వచించు BM_GETSTATE 0x00F2
#నిర్వచించు BM_SETSTATE 0x00F3
#నిర్వచించు BM_SETSTYLE 0x00F4
#నిర్వచించు BM_CLICK 0x00F5
#నిర్వచించు BM_GETIMAGE 0x00F6
#నిర్వచించు BM_SETIMAGE 0x00F7

#నిర్వచించు BST_UNCHECKED 0x0000
#నిర్వచించు BST_CHECKED 0x0001
#నిర్వచించు BST_INDETERMINATE 0x0002
#నిర్వచించు BST_PUSHED 0x0004
#నిర్వచించు BST_FOCUS 0x0008

#నిర్వచించు SS_ఎడమ 0x00000000L
#నిర్వచించు SS_CENTER 0x00000001L
#నిర్వచించు SS_కుడి 0x00000002L
#నిర్వచించు SS_ICON 0x00000003L
#నిర్వచించు SS_BLACKRECT 0x00000004L
#నిర్వచించు SS_GRAYRECT 0x00000005L
#నిర్వచించు SS_WHITERECT 0x00000006L
#నిర్వచించు SS_BLACKFRAME 0x00000007L
#నిర్వచించు SS_GRAYFRAME 0x00000008L
#నిర్వచించు SS_WHITEFRAME 0x00000009L
#నిర్వచించు SS_USERITEM 0x0000000AL
#నిర్వచించు SS_SIMPLE 0x0000000BL
#నిర్వచించు SS_LEFTNOWORDWRAP 0x0000000CL
#నిర్వచించు SS_OWNERDRAW 0x0000000DL
#నిర్వచించు SS_BITMAP 0x0000000EL
#నిర్వచించు SS_ENHMETAFILE 0x0000000FL
#నిర్వచించు SS_ETCHEDHORZ 0x00000010L
#నిర్వచించు SS_ETCHEDVERT 0x00000011L
#నిర్వచించు SS_ETCHEDFRAME 0x00000012L
#నిర్వచించు SS_TYPEMASK 0x0000001FL
#నిర్వచించు SS_REALSIZECONTROL 0x00000040L
#నిర్వచించు SS_NOPREFIX 0x00000080L
#నిర్వచించు SS_NOTIFY 0x00000100L
#నిర్వచించు SS_CENTERIMAGE 0x00000200L
#నిర్వచించు SS_RIGHTJUST 0x00000400L
#నిర్వచించు SS_REALSIZEIMAGE 0x00000800L
#నిర్వచించు SS_SUNKEN 0x00001000L
#నిర్వచించు SS_EDITCONTROL 0x00002000L
#నిర్వచించు SS_ENDELLIPSIS 0x00004000L
#నిర్వచించు SS_PATHELLIPSIS 0x00008000L
#నిర్వచించు SS_WORDELLIPSIS 0x0000C000L
#నిర్వచించు SS_ELLIPSISMASK 0x0000C000L

#నిర్వచితం_కాకపోతే NOWINMESSAGES

#నిర్వచించు STM_SETICON 0x0170
#నిర్వచించు STM_GETICON 0x0171
#నిర్వచించు STM_SETIMAGE 0x0172
#నిర్వచించు STM_GETIMAGE 0x0173
#నిర్వచించు STN_CLICKED 0
#నిర్వచించు STN_DBLCLK 1
#నిర్వచించు STN_ENABLE 2
#నిర్వచించు STN_DISABLE 3
#నిర్వచించు STM_MSGMAX 0x0174
#అయితే_ముగింపు

#నిర్వచించు WC_DIALOG (MAKEINTATOM(0x8002))

#నిర్వచించు DWL_MSGRESULT 0
#నిర్వచించు DWL_DLGPROC 4
#నిర్వచించు DWL_USER 8

#నిర్వచితమైతే _WIN64

#నిర్వచనం_రద్దు DWL_MSGRESULT
#నిర్వచనం_రద్దు DWL_DLGPROC
#నిర్వచనం_రద్దు DWL_USER
#అయితే_ముగింపు

#నిర్వచించు DWLP_MSGRESULT 0
#నిర్వచించు DWLP_DLGPROC DWLP_MSGRESULT + పరిమాణం(LRESULT)
#నిర్వచించు DWLP_USER DWLP_DLGPROC + పరిమాణం(DLGPROC)

#నిర్వచితం_కాకపోతే NOMSG

#నిర్వచితమైతే UNICODE
#నిర్వచించు Is_Dialog_సందేశం Is_Dialog_సందేశం_W
#లేకపోతే
#నిర్వచించు Is_Dialog_సందేశం Is_Dialog_సందేశం_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI Is_Dialog_సందేశం_A(HWND hDlg,LPMSG lp_సందేశం_2);
  WINUSERAPI WINBOOL WINAPI Is_Dialog_సందేశం_W(HWND hDlg,LPMSG lp_సందేశం_2);
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు DlgDirList DlgDirListW
#నిర్వచించు DlgDirSelectEx DlgDirSelectExW
#నిర్వచించు DlgDirListComboBox DlgDirListComboBoxW
#నిర్వచించు DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#లేకపోతే
#నిర్వచించు DlgDirList DlgDirListA
#నిర్వచించు DlgDirSelectEx DlgDirSelectExA
#నిర్వచించు DlgDirListComboBox DlgDirListComboBoxA
#నిర్వచించు DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI MapDialogRect(HWND hDlg,LPRECT lpRect);
  WINUSERAPI పూర్ణాంకం WINAPI DlgDirListA(HWND hDlg,LPSTR lp_మార్గం_Spec,పూర్ణాంకం nIDListBox,పూర్ణాంకం n_IDStatic_మార్గం,UINT uFileType);
  WINUSERAPI పూర్ణాంకం WINAPI DlgDirListW(HWND hDlg,LPWSTR lp_మార్గం_Spec,పూర్ణాంకం nIDListBox,పూర్ణాంకం n_IDStatic_మార్గం,UINT uFileType);

#నిర్వచించు DDL_READWRITE 0x0000
#నిర్వచించు DDL_READONLY 0x0001
#నిర్వచించు DDL_HIDDEN 0x0002
#నిర్వచించు DDL_SYSTEM 0x0004
#నిర్వచించు DDL_DIRECTORY 0x0010
#నిర్వచించు DDL_ARCHIVE 0x0020

#నిర్వచించు DDL_POSTMSGS 0x2000
#నిర్వచించు DDL_DRIVES 0x4000
#నిర్వచించు DDL_EXCLUSIVE 0x8000

  WINUSERAPI WINBOOL WINAPI DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,పూర్ణాంకం ch_లెక్క,పూర్ణాంకం idListBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,పూర్ణాంకం ch_లెక్క,పూర్ణాంకం idListBox);
  WINUSERAPI పూర్ణాంకం WINAPI DlgDirListComboBoxA(HWND hDlg,LPSTR lp_మార్గం_Spec,పూర్ణాంకం nIDComboBox,పూర్ణాంకం n_IDStatic_మార్గం,UINT uFiletype);
  WINUSERAPI పూర్ణాంకం WINAPI DlgDirListComboBoxW(HWND hDlg,LPWSTR lp_మార్గం_Spec,పూర్ణాంకం nIDComboBox,పూర్ణాంకం n_IDStatic_మార్గం,UINT uFiletype);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,పూర్ణాంకం cch_బహిర్గతం,పూర్ణాంకం idComboBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,పూర్ణాంకం cch_బహిర్గతం,పూర్ణాంకం idComboBox);

#నిర్వచించు DS_ABSALIGN 0x01L
#నిర్వచించు DS_SYSMODAL 0x02L
#నిర్వచించు DS_LOCALEDIT 0x20L
#నిర్వచించు DS_SETFONT 0x40L
#నిర్వచించు DS_MODALFRAME 0x80L
#నిర్వచించు DS_NOIDLEMSG 0x100L
#నిర్వచించు DS_SETFOREGROUND 0x200L

#నిర్వచించు DS_3DLOOK 0x0004L
#నిర్వచించు DS_FIXEDSYS 0x0008L
#నిర్వచించు DS_NOFAILCREATE 0x0010L
#నిర్వచించు DS_CONTROL 0x0400L
#నిర్వచించు DS_CENTER 0x0800L
#నిర్వచించు DS_CENTERMOUSE 0x1000L
#నిర్వచించు DS_CONTEXTHELP 0x2000L

#నిర్వచించు DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#ఒకవేళ(_WIN32_WCE >= 0x0500)
#నిర్వచించు DS_USEPIXELS 0x8000L
#అయితే_ముగింపు

#నిర్వచించు DM_GETDEFID (WM_USER+0)
#నిర్వచించు DM_SETDEFID (WM_USER+1)
#నిర్వచించు DM_REPOSITION (WM_USER+2)

#నిర్వచించు DC_HASDEFID 0x534B

#నిర్వచించు DLGC_WANTARROWS 0x0001
#నిర్వచించు DLGC_WANTTAB 0x0002
#నిర్వచించు DLGC_WANTALLKEYS 0x0004
#నిర్వచించు DLGC_WANTMESSAGE 0x0004
#నిర్వచించు DLGC_HASSETSEL 0x0008
#నిర్వచించు DLGC_DEFPUSHBUTTON 0x0010
#నిర్వచించు DLGC_UNDEFPUSHBUTTON 0x0020
#నిర్వచించు DLGC_RADIOBUTTON 0x0040
#నిర్వచించు DLGC_WANTCHARS 0x0080
#నిర్వచించు DLGC_STATIC 0x0100
#నిర్వచించు DLGC_BUTTON 0x2000

#నిర్వచించు LB_CTLCODE 0L

#నిర్వచించు LB_OKAY 0
#నిర్వచించు LB_ERR (-1)
#నిర్వచించు LB_ERRSPACE (-2)

#నిర్వచించు LBN_ERRSPACE (-2)
#నిర్వచించు LBN_SELCHANGE 1
#నిర్వచించు LBN_DBLCLK 2
#నిర్వచించు LBN_SELCANCEL 3
#నిర్వచించు LBN_SETFOCUS 4
#నిర్వచించు LBN_KILLFOCUS 5

#నిర్వచితం_కాకపోతే NOWINMESSAGES

#నిర్వచించు LB_ADDSTRING 0x0180
#నిర్వచించు LB_INSERTSTRING 0x0181
#నిర్వచించు LB_DELETESTRING 0x0182
#నిర్వచించు LB_SELITEMRANGEEX 0x0183
#నిర్వచించు LB_RESETCONTENT 0x0184
#నిర్వచించు LB_SETSEL 0x0185
#నిర్వచించు LB_SETCURSEL 0x0186
#నిర్వచించు LB_GETSEL 0x0187
#నిర్వచించు LB_GETCURSEL 0x0188
#నిర్వచించు LB_GETTEXT 0x0189
#నిర్వచించు LB_GETTEXTLEN 0x018A
#నిర్వచించు LB_GETCOUNT 0x018B
#నిర్వచించు LB_SELECTSTRING 0x018C
#నిర్వచించు LB_DIR 0x018D
#నిర్వచించు LB_GETTOPINDEX 0x018E
#నిర్వచించు LB_FINDSTRING 0x018F
#నిర్వచించు LB_GETSELCOUNT 0x0190
#నిర్వచించు LB_GETSELITEMS 0x0191
#నిర్వచించు LB_SETTABSTOPS 0x0192
#నిర్వచించు LB_GETHORIZONTALEXTENT 0x0193
#నిర్వచించు LB_SETHORIZONTALEXTENT 0x0194
#నిర్వచించు LB_SETCOLUMNWIDTH 0x0195
#నిర్వచించు LB_ADDFILE 0x0196
#నిర్వచించు LB_SETTOPINDEX 0x0197
#నిర్వచించు LB_GETITEMRECT 0x0198
#నిర్వచించు LB_GETITEMDATA 0x0199
#నిర్వచించు LB_SETITEMDATA 0x019A
#నిర్వచించు LB_SELITEMRANGE 0x019B
#నిర్వచించు LB_SETANCHORINDEX 0x019C
#నిర్వచించు LB_GETANCHORINDEX 0x019D
#నిర్వచించు LB_SETCARETINDEX 0x019E
#నిర్వచించు LB_GETCARETINDEX 0x019F
#నిర్వచించు LB_SETITEMHEIGHT 0x01A0
#నిర్వచించు LB_GETITEMHEIGHT 0x01A1
#నిర్వచించు LB_FINDSTRINGEXACT 0x01A2
#నిర్వచించు LB_SETLOCALE 0x01A5
#నిర్వచించు LB_GETLOCALE 0x01A6
#నిర్వచించు LB_SETCOUNT 0x01A7
#నిర్వచించు LB_INITSTORAGE 0x01A8
#నిర్వచించు LB_ITEMFROMPOINT 0x01A9
#ఒకవేళ(_WIN32_WCE >= 0x0400)
#నిర్వచించు LB_MULTIPLEADDSTRING 0x01B1
#అయితే_ముగింపు
#నిర్వచించు LB_GETLISTBOXINFO 0x01B2
#నిర్వచించు LB_MSGMAX 0x01B3
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOWINSTYLES

#నిర్వచించు LBS_NOTIFY 0x0001L
#నిర్వచించు LBS_క్రమీకరించు 0x0002L
#నిర్వచించు LBS_NOREDRAW 0x0004L
#నిర్వచించు LBS_MULTIPLESEL 0x0008L
#నిర్వచించు LBS_OWNERDRAWFIXED 0x0010L
#నిర్వచించు LBS_OWNERDRAWVARIABLE 0x0020L
#నిర్వచించు LBS_HASSTRINGS 0x0040L
#నిర్వచించు LBS_USETABSTOPS 0x0080L
#నిర్వచించు LBS_NOINTEGRALHEIGHT 0x0100L
#నిర్వచించు LBS_MULTICOLUMN 0x0200L
#నిర్వచించు LBS_WANTKEYBOARDINPUT 0x0400L
#నిర్వచించు LBS_EXTENDEDSEL 0x0800L
#నిర్వచించు LBS_DISABLENOSCROLL 0x1000L
#నిర్వచించు LBS_NODATA 0x2000L
#నిర్వచించు LBS_NOSEL 0x4000L
#నిర్వచించు LBS_COMBOBOX 0x8000L

#నిర్వచించు LBS_STANDARD (LBS_NOTIFY | LBS_క్రమీకరించు | WS_VSCROLL | WS_BORDER)
#అయితే_ముగింపు

#నిర్వచించు CB_OKAY 0
#నిర్వచించు CB_ERR (-1)
#నిర్వచించు CB_ERRSPACE (-2)

#నిర్వచించు CBN_ERRSPACE (-1)
#నిర్వచించు CBN_SELCHANGE 1
#నిర్వచించు CBN_DBLCLK 2
#నిర్వచించు CBN_SETFOCUS 3
#నిర్వచించు CBN_KILLFOCUS 4
#నిర్వచించు CBN_EDITCHANGE 5
#నిర్వచించు CBN_EDITUPDATE 6
#నిర్వచించు CBN_DROPDOWN 7
#నిర్వచించు CBN_CLOSEUP 8
#నిర్వచించు CBN_SELENDOK 9
#నిర్వచించు CBN_SELENDCANCEL 10

#నిర్వచితం_కాకపోతే NOWINSTYLES

#నిర్వచించు CBS_SIMPLE 0x0001L
#నిర్వచించు CBS_DROPDOWN 0x0002L
#నిర్వచించు CBS_DROPDOWNLIST 0x0003L
#నిర్వచించు CBS_OWNERDRAWFIXED 0x0010L
#నిర్వచించు CBS_OWNERDRAWVARIABLE 0x0020L
#నిర్వచించు CBS_AUTOHSCROLL 0x0040L
#నిర్వచించు CBS_OEMCONVERT 0x0080L
#నిర్వచించు CBS_క్రమీకరించు 0x0100L
#నిర్వచించు CBS_HASSTRINGS 0x0200L
#నిర్వచించు CBS_NOINTEGRALHEIGHT 0x0400L
#నిర్వచించు CBS_DISABLENOSCROLL 0x0800L
#నిర్వచించు CBS_UPPERCASE 0x2000L
#నిర్వచించు CBS_LOWERCASE 0x4000L
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOWINMESSAGES
#నిర్వచించు CB_GETEDITSEL 0x0140
#నిర్వచించు CB_LIMITTEXT 0x0141
#నిర్వచించు CB_SETEDITSEL 0x0142
#నిర్వచించు CB_ADDSTRING 0x0143
#నిర్వచించు CB_DELETESTRING 0x0144
#నిర్వచించు CB_DIR 0x0145
#నిర్వచించు CB_GETCOUNT 0x0146
#నిర్వచించు CB_GETCURSEL 0x0147
#నిర్వచించు CB_GETLBTEXT 0x0148
#నిర్వచించు CB_GETLBTEXTLEN 0x0149
#నిర్వచించు CB_INSERTSTRING 0x014A
#నిర్వచించు CB_RESETCONTENT 0x014B
#నిర్వచించు CB_FINDSTRING 0x014C
#నిర్వచించు CB_SELECTSTRING 0x014D
#నిర్వచించు CB_SETCURSEL 0x014E
#నిర్వచించు CB_SHOWDROPDOWN 0x014F
#నిర్వచించు CB_GETITEMDATA 0x0150
#నిర్వచించు CB_SETITEMDATA 0x0151
#నిర్వచించు CB_GETDROPPEDCONTROLRECT 0x0152
#నిర్వచించు CB_SETITEMHEIGHT 0x0153
#నిర్వచించు CB_GETITEMHEIGHT 0x0154
#నిర్వచించు CB_SETEXTENDEDUI 0x0155
#నిర్వచించు CB_GETEXTENDEDUI 0x0156
#నిర్వచించు CB_GETDROPPEDSTATE 0x0157
#నిర్వచించు CB_FINDSTRINGEXACT 0x0158
#నిర్వచించు CB_SETLOCALE 0x0159
#నిర్వచించు CB_GETLOCALE 0x015A
#నిర్వచించు CB_GETTOPINDEX 0x015b
#నిర్వచించు CB_SETTOPINDEX 0x015c
#నిర్వచించు CB_GETHORIZONTALEXTENT 0x015d
#నిర్వచించు CB_SETHORIZONTALEXTENT 0x015e
#నిర్వచించు CB_GETDROPPEDWIDTH 0x015f
#నిర్వచించు CB_SETDROPPEDWIDTH 0x0160
#నిర్వచించు CB_INITSTORAGE 0x0161
#ఒకవేళ(_WIN32_WCE >= 0x0400)
#నిర్వచించు CB_MULTIPLEADDSTRING 0x0163
#అయితే_ముగింపు
#నిర్వచించు CB_GETCOMBOBOXINFO 0x0164
#నిర్వచించు CB_MSGMAX 0x0165
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOWINSTYLES

#నిర్వచించు SBS_HORZ 0x0000L
#నిర్వచించు SBS_VERT 0x0001L
#నిర్వచించు SBS_TOPALIGN 0x0002L
#నిర్వచించు SBS_LEFTALIGN 0x0002L
#నిర్వచించు SBS_BOTTOMALIGN 0x0004L
#నిర్వచించు SBS_RIGHTALIGN 0x0004L
#నిర్వచించు SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#నిర్వచించు SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#నిర్వచించు SBS_SIZEBOX 0x0008L
#నిర్వచించు SBS_SIZEGRIP 0x0010L
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOWINMESSAGES
#నిర్వచించు SBM_SETPOS 0x00E0
#నిర్వచించు SBM_GETPOS 0x00E1
#నిర్వచించు SBM_SETRANGE 0x00E2
#నిర్వచించు SBM_SETRANGEREDRAW 0x00E6
#నిర్వచించు SBM_GETRANGE 0x00E3
#నిర్వచించు SBM_ENABLE_ARROWS 0x00E4
#నిర్వచించు SBM_SETSCROLLINFO 0x00E9
#నిర్వచించు SBM_GETSCROLLINFO 0x00EA
#నిర్వచించు SBM_GETSCROLLBARINFO 0x00EB

#నిర్వచించు SIF_RANGE 0x0001
#నిర్వచించు SIF_పుట 0x0002
#నిర్వచించు SIF_POS 0x0004
#నిర్వచించు SIF_DISABLENOSCROLL 0x0008
#నిర్వచించు SIF_TRACKPOS 0x0010
#నిర్వచించు SIF_ALL (SIF_RANGE | SIF_పుట | SIF_POS | SIF_TRACKPOS)

  రకనిర్వచనం నిర్మాణం ట్యాగ్_SCROLLINFO {
    UINT cb_కొలత;
    UINT f_ముసుగు;
    పూర్ణాంకం nMin;
    పూర్ణాంకం nMax;
    UINT n_పుట;
    పూర్ణాంకం nPos;
    పూర్ణాంకం nTrackPos;
  } SCROLLINFO,*LPSCROLLINFO;
  రకనిర్వచనం SCROLLINFO CONST *LPCSCROLLINFO;

  WINUSERAPI పూర్ణాంకం WINAPI సమితి_Scroll_Info(HWND hwnd,పూర్ణాంకం nBar,LPCSCROLLINFO lpsi,WINBOOL redraw);
  WINUSERAPI WINBOOL WINAPI GetScrollInfo(HWND hwnd,పూర్ణాంకం nBar,LPSCROLLINFO lpsi);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOMDI

#నిర్వచించు MDIS_ALLCHILDSTYLES 0x0001

#నిర్వచించు MDITILE_VERTICAL 0x0000
#నిర్వచించు MDITILE_HORIZONTAL 0x0001
#నిర్వచించు MDITILE_SKIPDISABLED 0x0002
#నిర్వచించు MDITILE_ZORDER 0x0004

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MDICREATESTRUCTA {
    LPCSTR szClass;
    LPCSTR szTitle;
    HANDLE hOwner;
    పూర్ణాంకం x;
    పూర్ణాంకం y;
    పూర్ణాంకం cx;
    పూర్ణాంకం cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTA,*LPMDICREATESTRUCTA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MDICREATESTRUCTW {
    LPCWSTR szClass;
    LPCWSTR szTitle;
    HANDLE hOwner;
    పూర్ణాంకం x;
    పూర్ణాంకం y;
    పూర్ణాంకం cx;
    పూర్ణాంకం cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTW,*LPMDICREATESTRUCTW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం MDICREATESTRUCTW MDICREATESTRUCT;
  రకనిర్వచనం LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#లేకపోతే
  రకనిర్వచనం MDICREATESTRUCTA MDICREATESTRUCT;
  రకనిర్వచనం LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CLIENTCREATESTRUCT {
    HANDLE h_కిటికీ_Menu;
    UINT id_మొదటి_బిడ్డ;
  } CLIENTCREATESTRUCT,*LPCLIENTCREATESTRUCT;

#నిర్వచితమైతే UNICODE
#నిర్వచించు Def_చట్రం_Proc Def_చట్రం_Proc_W
#నిర్వచించు DefMDIChildProc DefMDIChildProcW
#నిర్వచించు CreateMDIWindow CreateMDIWindowW
#లేకపోతే
#నిర్వచించు Def_చట్రం_Proc Def_చట్రం_Proc_A
#నిర్వచించు DefMDIChildProc DefMDIChildProcA
#నిర్వచించు CreateMDIWindow CreateMDIWindowA
#అయితే_ముగింపు

  WINUSERAPI LRESULT WINAPI Def_చట్రం_Proc_A(HWND hWnd,HWND hWndMDIClient,UINT u_సందేశం,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_చట్రం_Proc_W(HWND hWnd,HWND hWndMDIClient,UINT u_సందేశం,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcA(HWND hWnd,UINT u_సందేశం,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcW(HWND hWnd,UINT u_సందేశం,WPARAM wParam,LPARAM lParam);

#నిర్వచితం_కాకపోతే NOMSG
  WINUSERAPI WINBOOL WINAPI TranslateMDISysAccel(HWND hWndClient,LPMSG lp_సందేశం_2);
#అయితే_ముగింపు

  WINUSERAPI UINT WINAPI ArrangeIconicWindows(HWND hWnd);
  WINUSERAPI HWND WINAPI CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lp_కిటికీ_Name,DWORD dwStyle,పూర్ణాంకం X,పూర్ణాంకం Y,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు,HWND h_Wnd_మాతృ,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI HWND WINAPI CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lp_కిటికీ_Name,DWORD dwStyle,పూర్ణాంకం X,పూర్ణాంకం Y,పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు,HWND h_Wnd_మాతృ,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI మాట_3 WINAPI TileWindows(HWND hwnd_మాతృ_2,UINT wHow,CONST RECT *lpRect,UINT cKids,స్థిరరాశి HWND *lpKids);
  WINUSERAPI మాట_3 WINAPI CascadeWindows(HWND hwnd_మాతృ_2,UINT wHow,CONST RECT *lpRect,UINT cKids,స్థిరరాశి HWND *lpKids);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOHELP

  రకనిర్వచనం DWORD HELPPOLY;
  రకనిర్వచనం నిర్మాణం ట్యాగ్_MULTIKEYHELPA {
    DWORD mk_కొలత;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
  } MULTIKEYHELPA,*PMULTIKEYHELPA,*LPMULTIKEYHELPA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MULTIKEYHELPW {
    DWORD mk_కొలత;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
  } MULTIKEYHELPW,*PMULTIKEYHELPW,*LPMULTIKEYHELPW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం MULTIKEYHELPW MULTIKEYHELP;
  రకనిర్వచనం PMULTIKEYHELPW PMULTIKEYHELP;
  రకనిర్వచనం LPMULTIKEYHELPW LPMULTIKEYHELP;
#లేకపోతే
  రకనిర్వచనం MULTIKEYHELPA MULTIKEYHELP;
  రకనిర్వచనం PMULTIKEYHELPA PMULTIKEYHELP;
  రకనిర్వచనం LPMULTIKEYHELPA LPMULTIKEYHELP;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_HELPWININFOA {
    పూర్ణాంకం w_Struct_కొలత;
    పూర్ణాంకం x;
    పూర్ణాంకం y;
    పూర్ణాంకం dx;
    పూర్ణాంకం dy;
    పూర్ణాంకం wMax;
    CHAR rgchMember[2];
  } HELPWININFOA,*PHELPWININFOA,*LPHELPWININFOA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_HELPWININFOW {
    పూర్ణాంకం w_Struct_కొలత;
    పూర్ణాంకం x;
    పూర్ణాంకం y;
    పూర్ణాంకం dx;
    పూర్ణాంకం dy;
    పూర్ణాంకం wMax;
    WCHAR rgchMember[2];
  } HELPWININFOW,*PHELPWININFOW,*LPHELPWININFOW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం HELPWININFOW HELPWININFO;
  రకనిర్వచనం PHELPWININFOW PHELPWININFO;
  రకనిర్వచనం LPHELPWININFOW LPHELPWININFO;
#లేకపోతే
  రకనిర్వచనం HELPWININFOA HELPWININFO;
  రకనిర్వచనం PHELPWININFOA PHELPWININFO;
  రకనిర్వచనం LPHELPWININFOA LPHELPWININFO;
#అయితే_ముగింపు

#నిర్వచించు HELP_CONTEXT 0x0001L
#నిర్వచించు HELP_QUIT 0x0002L
#నిర్వచించు HELP_సూచీ 0x0003L
#నిర్వచించు HELP_CONTENTS 0x0003L
#నిర్వచించు HELP_HELPONHELP 0x0004L
#నిర్వచించు HELP_SETINDEX 0x0005L
#నిర్వచించు HELP_SETCONTENTS 0x0005L
#నిర్వచించు HELP_CONTEXTPOPUP 0x0008L
#నిర్వచించు HELP_FORCEFILE 0x0009L
#నిర్వచించు HELP_కీలకం 0x0101L
#నిర్వచించు HELP_COMMAND 0x0102L
#నిర్వచించు HELP_PARTIALKEY 0x0105L
#నిర్వచించు HELP_MULTIKEY 0x0201L
#నిర్వచించు HELP_SETWINPOS 0x0203L
#నిర్వచించు HELP_CONTEXTMENU 0x000a
#నిర్వచించు HELP_FINDER 0x000b
#నిర్వచించు HELP_WM_HELP 0x000c
#నిర్వచించు HELP_SETPOPUP_POS 0x000d

#నిర్వచించు HELP_TCARD 0x8000
#నిర్వచించు HELP_TCARD_దత్తాంశం 0x0010
#నిర్వచించు HELP_TCARD_OTHER_CALLER 0x0011

#నిర్వచించు IDH_NO_HELP 28440
#నిర్వచించు IDH_MISSING_CONTEXT 28441
#నిర్వచించు IDH_GENERIC_HELP_BUTTON 28442
#నిర్వచించు IDH_OK 28443
#నిర్వచించు IDH_CANCEL 28444
#నిర్వచించు IDH_HELP 28445

#నిర్వచితమైతే UNICODE
#నిర్వచించు WinHelp WinHelpW
#లేకపోతే
#నిర్వచించు WinHelp WinHelpA
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dw_దత్తాంశం);
  WINUSERAPI WINBOOL WINAPI WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dw_దత్తాంశం);
#అయితే_ముగింపు

#నిర్వచించు GR_GDIOBJECTS 0
#నిర్వచించు GR_USEROBJECTS 1

  WINUSERAPI DWORD WINAPI GetGuiResources(HANDLE hProcess,DWORD uiFlags);

#నిర్వచితం_కాకపోతే NOSYSPARAMSINFO

#నిర్వచించు SPI_GETBEEP 0x0001
#నిర్వచించు SPI_SETBEEP 0x0002
#నిర్వచించు SPI_GETMOUSE 0x0003
#నిర్వచించు SPI_SETMOUSE 0x0004
#నిర్వచించు SPI_GETBORDER 0x0005
#నిర్వచించు SPI_SETBORDER 0x0006
#నిర్వచించు SPI_GETKEYBOARDSPEED 0x000A
#నిర్వచించు SPI_SETKEYBOARDSPEED 0x000B
#నిర్వచించు SPI_LANGDRIVER 0x000C
#నిర్వచించు SPI_ICONHORIZONTALSPACING 0x000D
#నిర్వచించు SPI_GETSCREENSAVETIMEOUT 0x000E
#నిర్వచించు SPI_SETSCREENSAVETIMEOUT 0x000F
#నిర్వచించు SPI_GETSCREENSAVEACTIVE 0x0010
#నిర్వచించు SPI_SETSCREENSAVEACTIVE 0x0011
#నిర్వచించు SPI_GETGRIDGRANULARITY 0x0012
#నిర్వచించు SPI_SETGRIDGRANULARITY 0x0013
#నిర్వచించు SPI_SETDESKWALLPAPER 0x0014
#నిర్వచించు SPI_SETDESKPATTERN 0x0015
#నిర్వచించు SPI_GETKEYBOARDDELAY 0x0016
#నిర్వచించు SPI_SETKEYBOARDDELAY 0x0017
#నిర్వచించు SPI_ICONVERTICALSPACING 0x0018
#నిర్వచించు SPI_GETICONTITLEWRAP 0x0019
#నిర్వచించు SPI_SETICONTITLEWRAP 0x001A
#నిర్వచించు SPI_GETMENUDROPALIGNMENT 0x001B
#నిర్వచించు SPI_SETMENUDROPALIGNMENT 0x001C
#నిర్వచించు SPI_SETDOUBLECLKWIDTH 0x001D
#నిర్వచించు SPI_SETDOUBLECLKHEIGHT 0x001E
#నిర్వచించు SPI_GETICONTITLELOGFONT 0x001F
#నిర్వచించు SPI_SETDOUBLECLICKTIME 0x0020
#నిర్వచించు SPI_SETMOUSEBUTTONSWAP 0x0021
#నిర్వచించు SPI_SETICONTITLELOGFONT 0x0022
#నిర్వచించు SPI_GETFASTTASKSWITCH 0x0023
#నిర్వచించు SPI_SETFASTTASKSWITCH 0x0024
#నిర్వచించు SPI_SETDRAGFULLWINDOWS 0x0025
#నిర్వచించు SPI_GETDRAGFULLWINDOWS 0x0026
#నిర్వచించు SPI_GETNONCLIENTMETRICS 0x0029
#నిర్వచించు SPI_SETNONCLIENTMETRICS 0x002A
#నిర్వచించు SPI_GETMINIMIZEDMETRICS 0x002B
#నిర్వచించు SPI_SETMINIMIZEDMETRICS 0x002C
#నిర్వచించు SPI_GETICONMETRICS 0x002D
#నిర్వచించు SPI_SETICONMETRICS 0x002E
#నిర్వచించు SPI_SETWORKAREA 0x002F
#నిర్వచించు SPI_GETWORKAREA 0x0030
#నిర్వచించు SPI_SETPENWINDOWS 0x0031

#నిర్వచించు SPI_GETHIGHCONTRAST 0x0042
#నిర్వచించు SPI_SETHIGHCONTRAST 0x0043
#నిర్వచించు SPI_GETKEYBOARDPREF 0x0044
#నిర్వచించు SPI_SETKEYBOARDPREF 0x0045
#నిర్వచించు SPI_GETSCREENREADER 0x0046
#నిర్వచించు SPI_SETSCREENREADER 0x0047
#నిర్వచించు SPI_GETANIMATION 0x0048
#నిర్వచించు SPI_SETANIMATION 0x0049
#నిర్వచించు SPI_GETFONTSMOOTHING 0x004A
#నిర్వచించు SPI_SETFONTSMOOTHING 0x004B
#నిర్వచించు SPI_SETDRAGWIDTH 0x004C
#నిర్వచించు SPI_SETDRAGHEIGHT 0x004D
#నిర్వచించు SPI_SETHANDHELD 0x004E
#నిర్వచించు SPI_GETLOWPOWERTIMEOUT 0x004F
#నిర్వచించు SPI_GETPOWEROFFTIMEOUT 0x0050
#నిర్వచించు SPI_SETLOWPOWERTIMEOUT 0x0051
#నిర్వచించు SPI_SETPOWEROFFTIMEOUT 0x0052
#నిర్వచించు SPI_GETLOWPOWERACTIVE 0x0053
#నిర్వచించు SPI_GETPOWEROFFACTIVE 0x0054
#నిర్వచించు SPI_SETLOWPOWERACTIVE 0x0055
#నిర్వచించు SPI_SETPOWEROFFACTIVE 0x0056
#నిర్వచించు SPI_SETCURSORS 0x0057
#నిర్వచించు SPI_SETICONS 0x0058
#నిర్వచించు SPI_GETDEFAULTINPUTLANG 0x0059
#నిర్వచించు SPI_SETDEFAULTINPUTLANG 0x005A
#నిర్వచించు SPI_SETLANGTOGGLE 0x005B
#నిర్వచించు SPI_GETWINDOWSEXTENSION 0x005C
#నిర్వచించు SPI_SETMOUSETRAILS 0x005D
#నిర్వచించు SPI_GETMOUSETRAILS 0x005E
#నిర్వచించు SPI_SETSCREENSAVERRUNNING 0x0061
#నిర్వచించు SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#నిర్వచించు SPI_GETFILTERKEYS 0x0032
#నిర్వచించు SPI_SETFILTERKEYS 0x0033
#నిర్వచించు SPI_GETTOGGLEKEYS 0x0034
#నిర్వచించు SPI_SETTOGGLEKEYS 0x0035
#నిర్వచించు SPI_GETMOUSEKEYS 0x0036
#నిర్వచించు SPI_SETMOUSEKEYS 0x0037
#నిర్వచించు SPI_GETSHOWSOUNDS 0x0038
#నిర్వచించు SPI_SETSHOWSOUNDS 0x0039
#నిర్వచించు SPI_GETSTICKYKEYS 0x003A
#నిర్వచించు SPI_SETSTICKYKEYS 0x003B
#నిర్వచించు SPI_GETACCESSTIMEOUT 0x003C
#నిర్వచించు SPI_SETACCESSTIMEOUT 0x003D
#నిర్వచించు SPI_GETSERIALKEYS 0x003E
#నిర్వచించు SPI_SETSERIALKEYS 0x003F
#నిర్వచించు SPI_GETSOUNDSENTRY 0x0040
#నిర్వచించు SPI_SETSOUNDSENTRY 0x0041
#నిర్వచించు SPI_GETSNAPTODEFBUTTON 0x005F
#నిర్వచించు SPI_SETSNAPTODEFBUTTON 0x0060
#నిర్వచించు SPI_GETMOUSEHOVERWIDTH 0x0062
#నిర్వచించు SPI_SETMOUSEHOVERWIDTH 0x0063
#నిర్వచించు SPI_GETMOUSEHOVERHEIGHT 0x0064
#నిర్వచించు SPI_SETMOUSEHOVERHEIGHT 0x0065
#నిర్వచించు SPI_GETMOUSEHOVERTIME 0x0066
#నిర్వచించు SPI_SETMOUSEHOVERTIME 0x0067
#నిర్వచించు SPI_GETWHEELSCROLLLINES 0x0068
#నిర్వచించు SPI_SETWHEELSCROLLLINES 0x0069
#నిర్వచించు SPI_GETMENUSHOWDELAY 0x006A
#నిర్వచించు SPI_SETMENUSHOWDELAY 0x006B
#నిర్వచించు SPI_GETSHOWIMEUI 0x006E
#నిర్వచించు SPI_SETSHOWIMEUI 0x006F
#నిర్వచించు SPI_GETMOUSESPEED 0x0070
#నిర్వచించు SPI_SETMOUSESPEED 0x0071
#నిర్వచించు SPI_GETSCREENSAVERRUNNING 0x0072
#నిర్వచించు SPI_GETDESKWALLPAPER 0x0073

#నిర్వచించు SPI_GETACTIVEWINDOWTRACKING 0x1000
#నిర్వచించు SPI_SETACTIVEWINDOWTRACKING 0x1001
#నిర్వచించు SPI_GETMENUANIMATION 0x1002
#నిర్వచించు SPI_SETMENUANIMATION 0x1003
#నిర్వచించు SPI_GETCOMBOBOXANIMATION 0x1004
#నిర్వచించు SPI_SETCOMBOBOXANIMATION 0x1005
#నిర్వచించు SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#నిర్వచించు SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#నిర్వచించు SPI_GETGRADIENTCAPTIONS 0x1008
#నిర్వచించు SPI_SETGRADIENTCAPTIONS 0x1009
#నిర్వచించు SPI_GETKEYBOARDCUES 0x100A
#నిర్వచించు SPI_SETKEYBOARDCUES 0x100B
#నిర్వచించు SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#నిర్వచించు SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#నిర్వచించు SPI_GETACTIVEWNDTRKZORDER 0x100C
#నిర్వచించు SPI_SETACTIVEWNDTRKZORDER 0x100D
#నిర్వచించు SPI_GETHOTTRACKING 0x100E
#నిర్వచించు SPI_SETHOTTRACKING 0x100F
#నిర్వచించు SPI_GETMENUFADE 0x1012
#నిర్వచించు SPI_SETMENUFADE 0x1013
#నిర్వచించు SPI_GETSELECTIONFADE 0x1014
#నిర్వచించు SPI_SETSELECTIONFADE 0x1015
#నిర్వచించు SPI_GETTOOLTIPANIMATION 0x1016
#నిర్వచించు SPI_SETTOOLTIPANIMATION 0x1017
#నిర్వచించు SPI_GETTOOLTIPFADE 0x1018
#నిర్వచించు SPI_SETTOOLTIPFADE 0x1019
#నిర్వచించు SPI_GETCURSORSHADOW 0x101A
#నిర్వచించు SPI_SETCURSORSHADOW 0x101B
#నిర్వచించు SPI_GETMOUSESONAR 0x101C
#నిర్వచించు SPI_SETMOUSESONAR 0x101D
#నిర్వచించు SPI_GETMOUSECLICKLOCK 0x101E
#నిర్వచించు SPI_SETMOUSECLICKLOCK 0x101F
#నిర్వచించు SPI_GETMOUSEVANISH 0x1020
#నిర్వచించు SPI_SETMOUSEVANISH 0x1021
#నిర్వచించు SPI_GETFLATMENU 0x1022
#నిర్వచించు SPI_SETFLATMENU 0x1023
#నిర్వచించు SPI_GETDROPSHADOW 0x1024
#నిర్వచించు SPI_SETDROPSHADOW 0x1025
#నిర్వచించు SPI_GETBLOCKSENDINPUTRESETS 0x1026
#నిర్వచించు SPI_SETBLOCKSENDINPUTRESETS 0x1027
#నిర్వచించు SPI_GETUIEFFECTS 0x103E
#నిర్వచించు SPI_SETUIEFFECTS 0x103F
#నిర్వచించు SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#నిర్వచించు SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#నిర్వచించు SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#నిర్వచించు SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#నిర్వచించు SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#నిర్వచించు SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#నిర్వచించు SPI_GETCARETWIDTH 0x2006
#నిర్వచించు SPI_SETCARETWIDTH 0x2007
#నిర్వచించు SPI_GETMOUSECLICKLOCKTIME 0x2008
#నిర్వచించు SPI_SETMOUSECLICKLOCKTIME 0x2009
#నిర్వచించు SPI_GETFONTSMOOTHINGTYPE 0x200A
#నిర్వచించు SPI_SETFONTSMOOTHINGTYPE 0x200B

#నిర్వచించు FE_FONTSMOOTHINGSTANDARD 0x0001
#నిర్వచించు FE_FONTSMOOTHINGCLEARTYPE 0x0002
#నిర్వచించు FE_FONTSMOOTHINGDOCKING 0x8000

#నిర్వచించు SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#నిర్వచించు SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#నిర్వచించు SPI_GETFOCUSBORDERWIDTH 0x200E
#నిర్వచించు SPI_SETFOCUSBORDERWIDTH 0x200F
#నిర్వచించు SPI_GETFOCUSBORDERHEIGHT 0x2010
#నిర్వచించు SPI_SETFOCUSBORDERHEIGHT 0x2011
#నిర్వచించు SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#నిర్వచించు SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#నిర్వచించు FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#నిర్వచించు FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#నిర్వచించు SPIF_UPDATEINIFILE 0x0001
#నిర్వచించు SPIF_SENDWININICHANGE 0x0002
#నిర్వచించు SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#నిర్వచించు METRICS_USEDEFAULT -1
#నిర్వచితమైతే _WINGDI_
#నిర్వచితం_కాకపోతే NOGDI
  రకనిర్వచనం నిర్మాణం ట్యాగ్_NONCLIENTMETRICSA {
    UINT cb_కొలత;
    పూర్ణాంకం i_Border_వెడల్పు;
    పూర్ణాంకం i_Scroll_వెడల్పు;
    పూర్ణాంకం i_Scroll_ఎత్తు;
    పూర్ణాంకం i_Caption_వెడల్పు;
    పూర్ణాంకం i_Caption_ఎత్తు;
    LOGFONTA lfCaptionFont;
    పూర్ణాంకం i_Sm_Caption_వెడల్పు;
    పూర్ణాంకం i_Sm_Caption_ఎత్తు;
    LOGFONTA lfSmCaptionFont;
    పూర్ణాంకం i_Menu_వెడల్పు;
    పూర్ణాంకం i_Menu_ఎత్తు;
    LOGFONTA lfMenuFont;
    LOGFONTA lf_స్థితి_Font;
    LOGFONTA lf_సందేశం_Font;
  } NONCLIENTMETRICSA,*PNONCLIENTMETRICSA,*LPNONCLIENTMETRICSA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_NONCLIENTMETRICSW {
    UINT cb_కొలత;
    పూర్ణాంకం i_Border_వెడల్పు;
    పూర్ణాంకం i_Scroll_వెడల్పు;
    పూర్ణాంకం i_Scroll_ఎత్తు;
    పూర్ణాంకం i_Caption_వెడల్పు;
    పూర్ణాంకం i_Caption_ఎత్తు;
    LOGFONTW lfCaptionFont;
    పూర్ణాంకం i_Sm_Caption_వెడల్పు;
    పూర్ణాంకం i_Sm_Caption_ఎత్తు;
    LOGFONTW lfSmCaptionFont;
    పూర్ణాంకం i_Menu_వెడల్పు;
    పూర్ణాంకం i_Menu_ఎత్తు;
    LOGFONTW lfMenuFont;
    LOGFONTW lf_స్థితి_Font;
    LOGFONTW lf_సందేశం_Font;
  } NONCLIENTMETRICSW,*PNONCLIENTMETRICSW,*LPNONCLIENTMETRICSW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం NONCLIENTMETRICSW NONCLIENTMETRICS;
  రకనిర్వచనం PNONCLIENTMETRICSW PNONCLIENTMETRICS;
  రకనిర్వచనం LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#లేకపోతే
  రకనిర్వచనం NONCLIENTMETRICSA NONCLIENTMETRICS;
  రకనిర్వచనం PNONCLIENTMETRICSA PNONCLIENTMETRICS;
  రకనిర్వచనం LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు ARW_BOTTOMLEFT 0x0000L
#నిర్వచించు ARW_BOTTOMRIGHT 0x0001L
#నిర్వచించు ARW_TOPLEFT 0x0002L
#నిర్వచించు ARW_TOPRIGHT 0x0003L
#నిర్వచించు ARW_STARTMASK 0x0003L
#నిర్వచించు ARW_STARTRIGHT 0x0001L
#నిర్వచించు ARW_STARTTOP 0x0002L

#నిర్వచించు ARW_ఎడమ 0x0000L
#నిర్వచించు ARW_కుడి 0x0000L
#నిర్వచించు ARW_పైకి 0x0004L
#నిర్వచించు ARW_కిందికి 0x0004L
#నిర్వచించు ARW_HIDE 0x0008L

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MINIMIZEDMETRICS {
    UINT cb_కొలత;
    పూర్ణాంకం i_వెడల్పు;
    పూర్ణాంకం iHorzGap;
    పూర్ణాంకం iVertGap;
    పూర్ణాంకం iArrange;
  } MINIMIZEDMETRICS,*PMINIMIZEDMETRICS,*LPMINIMIZEDMETRICS;

#నిర్వచితమైతే _WINGDI_
#నిర్వచితం_కాకపోతే NOGDI
  రకనిర్వచనం నిర్మాణం ట్యాగ్_ICONMETRICSA {
    UINT cb_కొలత;
    పూర్ణాంకం iHorzSpacing;
    పూర్ణాంకం iVertSpacing;
    పూర్ణాంకం iTitleWrap;
    LOGFONTA lfFont;
  } ICONMETRICSA,*PICONMETRICSA,*LPICONMETRICSA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ICONMETRICSW {
    UINT cb_కొలత;
    పూర్ణాంకం iHorzSpacing;
    పూర్ణాంకం iVertSpacing;
    పూర్ణాంకం iTitleWrap;
    LOGFONTW lfFont;
  } ICONMETRICSW,*PICONMETRICSW,*LPICONMETRICSW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం ICONMETRICSW ICONMETRICS;
  రకనిర్వచనం PICONMETRICSW PICONMETRICS;
  రకనిర్వచనం LPICONMETRICSW LPICONMETRICS;
#లేకపోతే
  రకనిర్వచనం ICONMETRICSA ICONMETRICS;
  రకనిర్వచనం PICONMETRICSA PICONMETRICS;
  రకనిర్వచనం LPICONMETRICSA LPICONMETRICS;
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ANIMATIONINFO {
    UINT cb_కొలత;
    పూర్ణాంకం iMinAnimate;
  } ANIMATIONINFO,*LPANIMATIONINFO;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_SERIALKEYSA {
    UINT cb_కొలత;
    DWORD dwFlags;
    LPSTR lpsz_చురుకైన_పోర్టు;
    LPSTR lpsz_పోర్టు;
    UINT i_Baud_రేటు;
    UINT i_పోర్టు_State;
    UINT i_చురుకైన;
  } SERIALKEYSA,*LPSERIALKEYSA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_SERIALKEYSW {
    UINT cb_కొలత;
    DWORD dwFlags;
    LPWSTR lpsz_చురుకైన_పోర్టు;
    LPWSTR lpsz_పోర్టు;
    UINT i_Baud_రేటు;
    UINT i_పోర్టు_State;
    UINT i_చురుకైన;
  } SERIALKEYSW,*LPSERIALKEYSW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం SERIALKEYSW SERIALKEYS;
  రకనిర్వచనం LPSERIALKEYSW LPSERIALKEYS;
#లేకపోతే
  రకనిర్వచనం SERIALKEYSA SERIALKEYS;
  రకనిర్వచనం LPSERIALKEYSA LPSERIALKEYS;
#అయితే_ముగింపు

#నిర్వచించు SERKF_SERIALKEYSON 0x00000001
#నిర్వచించు SERKF_అందుబాటు 0x00000002
#నిర్వచించు SERKF_INDICATOR 0x00000004

  రకనిర్వచనం నిర్మాణం ట్యాగ్_HIGHCONTRASTA {
    UINT cb_కొలత;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
  } HIGHCONTRASTA,*LPHIGHCONTRASTA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_HIGHCONTRASTW {
    UINT cb_కొలత;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
  } HIGHCONTRASTW,*LPHIGHCONTRASTW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం HIGHCONTRASTW HIGHCONTRAST;
  రకనిర్వచనం LPHIGHCONTRASTW LPHIGHCONTRAST;
#లేకపోతే
  రకనిర్వచనం HIGHCONTRASTA HIGHCONTRAST;
  రకనిర్వచనం LPHIGHCONTRASTA LPHIGHCONTRAST;
#అయితే_ముగింపు

#నిర్వచించు HCF_HIGHCONTRASTON 0x00000001
#నిర్వచించు HCF_అందుబాటు 0x00000002
#నిర్వచించు HCF_HOTKEYACTIVE 0x00000004
#నిర్వచించు HCF_CONFIRMHOTKEY 0x00000008
#నిర్వచించు HCF_HOTKEYSOUND 0x00000010
#నిర్వచించు HCF_INDICATOR 0x00000020
#నిర్వచించు HCF_HOTKEYAVAILABLE 0x00000040
#నిర్వచించు HCF_LOGONDESKTOP 0x00000100
#నిర్వచించు HCF_DEFAULTDESKTOP 0x00000200

#నిర్వచించు CDS_UPDATEREGISTRY 0x00000001
#నిర్వచించు CDS_TEST 0x00000002
#నిర్వచించు CDS_FULLSCREEN 0x00000004
#నిర్వచించు CDS_GLOBAL 0x00000008
#నిర్వచించు CDS_సమితి_PRIMARY 0x00000010
#నిర్వచించు CDS_VIDEOPARAMETERS 0x00000020
#నిర్వచించు CDS_RESET 0x40000000
#నిర్వచించు CDS_NORESET 0x10000000

//gr #include <tvout.h>

#నిర్వచించు DISP_CHANGE_SUCCESSFUL 0
#నిర్వచించు DISP_CHANGE_RESTART 1
#నిర్వచించు DISP_CHANGE_FAILED -1
#నిర్వచించు DISP_CHANGE_BADMODE -2
#నిర్వచించు DISP_CHANGE_NOTUPDATED -3
#నిర్వచించు DISP_CHANGE_BADFLAGS -4
#నిర్వచించు DISP_CHANGE_BADPARAM -5
#నిర్వచించు DISP_CHANGE_BADDUALVIEW -6

#నిర్వచితమైతే _WINGDI_
#నిర్వచితం_కాకపోతే NOGDI

#నిర్వచితమైతే UNICODE
#నిర్వచించు ChangeDisplaySettings ChangeDisplaySettingsW
#నిర్వచించు ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#నిర్వచించు EnumDisplaySettings EnumDisplaySettingsW
#నిర్వచించు EnumDisplaySettingsEx EnumDisplaySettingsExW
#నిర్వచించు EnumDisplayDevices EnumDisplayDevicesW
#లేకపోతే
#నిర్వచించు ChangeDisplaySettings ChangeDisplaySettingsA
#నిర్వచించు ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#నిర్వచించు EnumDisplaySettings EnumDisplaySettingsA
#నిర్వచించు EnumDisplaySettingsEx EnumDisplaySettingsExA
#నిర్వచించు EnumDisplayDevices EnumDisplayDevicesA
#అయితే_ముగింపు

  WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lp_Dev_బహుళకం,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsW(LPDEVMODEW lp_Dev_బహుళకం,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,LPDEVMODEA lp_Dev_బహుళకం,HWND hwnd,DWORD dwflags,LPVOID lParam);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,LPDEVMODEW lp_Dev_బహుళకం,HWND hwnd,DWORD dwflags,LPVOID lParam);

#నిర్వచించు ENUM_CURRENT_SETTINGS ((DWORD)-1)
#నిర్వచించు ENUM_REGISTRY_SETTINGS ((DWORD)-2)

  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD i_బహుళకం_అంకె,LPDEVMODEA lp_Dev_బహుళకం);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD i_బహుళకం_అంకె,LPDEVMODEW lp_Dev_బహుళకం);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD i_బహుళకం_అంకె,LPDEVMODEA lp_Dev_బహుళకం,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD i_బహుళకం_అంకె,LPDEVMODEW lp_Dev_బహుళకం,DWORD dwFlags);

#నిర్వచించు EDS_RAWMODE 0x00000002

  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesA(LPCSTR lpDevice,DWORD i_Dev_అంకె,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD i_Dev_అంకె,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు SystemParametersInfo SystemParametersInfoW
#లేకపోతే
#నిర్వచించు SystemParametersInfo SystemParametersInfoA
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
  WINUSERAPI WINBOOL WINAPI SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_FILTERKEYS {
    UINT cb_కొలత;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
  } FILTERKEYS,*LPFILTERKEYS;

#నిర్వచించు FKF_FILTERKEYSON 0x00000001
#నిర్వచించు FKF_అందుబాటు 0x00000002
#నిర్వచించు FKF_HOTKEYACTIVE 0x00000004
#నిర్వచించు FKF_CONFIRMHOTKEY 0x00000008
#నిర్వచించు FKF_HOTKEYSOUND 0x00000010
#నిర్వచించు FKF_INDICATOR 0x00000020
#నిర్వచించు FKF_CLICKON 0x00000040

  రకనిర్వచనం నిర్మాణం ట్యాగ్_STICKYKEYS {
    UINT cb_కొలత;
    DWORD dwFlags;
  } STICKYKEYS,*LPSTICKYKEYS;

#నిర్వచించు SKF_STICKYKEYSON 0x00000001
#నిర్వచించు SKF_అందుబాటు 0x00000002
#నిర్వచించు SKF_HOTKEYACTIVE 0x00000004
#నిర్వచించు SKF_CONFIRMHOTKEY 0x00000008
#నిర్వచించు SKF_HOTKEYSOUND 0x00000010
#నిర్వచించు SKF_INDICATOR 0x00000020
#నిర్వచించు SKF_AUDIBLEFEEDBACK 0x00000040
#నిర్వచించు SKF_TRISTATE 0x00000080
#నిర్వచించు SKF_TWOKEYSOFF 0x00000100
#నిర్వచించు SKF_LALTLATCHED 0x10000000
#నిర్వచించు SKF_LCTLLATCHED 0x04000000
#నిర్వచించు SKF_LSHIFTLATCHED 0x01000000
#నిర్వచించు SKF_RALTLATCHED 0x20000000
#నిర్వచించు SKF_RCTLLATCHED 0x08000000
#నిర్వచించు SKF_RSHIFTLATCHED 0x02000000
#నిర్వచించు SKF_LWINLATCHED 0x40000000
#నిర్వచించు SKF_RWINLATCHED 0x80000000
#నిర్వచించు SKF_LALTLOCKED 0x00100000
#నిర్వచించు SKF_LCTLLOCKED 0x00040000
#నిర్వచించు SKF_LSHIFTLOCKED 0x00010000
#నిర్వచించు SKF_RALTLOCKED 0x00200000
#నిర్వచించు SKF_RCTLLOCKED 0x00080000
#నిర్వచించు SKF_RSHIFTLOCKED 0x00020000
#నిర్వచించు SKF_LWINLOCKED 0x00400000
#నిర్వచించు SKF_RWINLOCKED 0x00800000

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MOUSEKEYS {
    UINT cb_కొలత;
    DWORD dwFlags;
    DWORD i_Max_వేగం;
    DWORD i_సమయం_గమ్యం_Max_వేగం;
    DWORD i_Ctrl_వేగం;
    DWORD dwReserved1;
    DWORD dwReserved2;
  } MOUSEKEYS,*LPMOUSEKEYS;

#నిర్వచించు MKF_MOUSEKEYSON 0x00000001
#నిర్వచించు MKF_అందుబాటు 0x00000002
#నిర్వచించు MKF_HOTKEYACTIVE 0x00000004
#నిర్వచించు MKF_CONFIRMHOTKEY 0x00000008
#నిర్వచించు MKF_HOTKEYSOUND 0x00000010
#నిర్వచించు MKF_INDICATOR 0x00000020
#నిర్వచించు MKF_MODIFIERS 0x00000040
#నిర్వచించు MKF_REPLACENUMBERS 0x00000080
#నిర్వచించు MKF_LEFTBUTTONSEL 0x10000000
#నిర్వచించు MKF_RIGHTBUTTONSEL 0x20000000
#నిర్వచించు MKF_LEFTBUTTONDOWN 0x01000000
#నిర్వచించు MKF_RIGHTBUTTONDOWN 0x02000000
#నిర్వచించు MKF_MOUSEMODE 0x80000000

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ACCESSTIMEOUT {
    UINT cb_కొలత;
    DWORD dwFlags;
    DWORD i_సమయం_బహిర్గతం_MSec;
  } ACCESSTIMEOUT,*LPACCESSTIMEOUT;

#నిర్వచించు ATF_TIMEOUTON 0x00000001
#నిర్వచించు ATF_ONOFFFEEDBACK 0x00000002

#నిర్వచించు SSGF_NONE 0
#నిర్వచించు SSGF_DISPLAY 3

#నిర్వచించు SSTF_NONE 0
#నిర్వచించు SSTF_CHARS 1
#నిర్వచించు SSTF_BORDER 2
#నిర్వచించు SSTF_DISPLAY 3

#నిర్వచించు SSWF_NONE 0
#నిర్వచించు SSWF_TITLE 1
#నిర్వచించు SSWF_కిటికీ 2
#నిర్వచించు SSWF_DISPLAY 3
#నిర్వచించు SSWF_CUSTOM 4

  రకనిర్వచనం నిర్మాణం ట్యాగ్_SOUNDSENTRYA {
    UINT cb_కొలత;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_బిట్లు;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYA,*LPSOUNDSENTRYA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_SOUNDSENTRYW {
    UINT cb_కొలత;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_బిట్లు;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYW,*LPSOUNDSENTRYW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం SOUNDSENTRYW SOUNDSENTRY;
  రకనిర్వచనం LPSOUNDSENTRYW LPSOUNDSENTRY;
#లేకపోతే
  రకనిర్వచనం SOUNDSENTRYA SOUNDSENTRY;
  రకనిర్వచనం LPSOUNDSENTRYA LPSOUNDSENTRY;
#అయితే_ముగింపు

#నిర్వచించు SSF_SOUNDSENTRYON 0x00000001
#నిర్వచించు SSF_అందుబాటు 0x00000002
#నిర్వచించు SSF_INDICATOR 0x00000004

  రకనిర్వచనం నిర్మాణం ట్యాగ్_TOGGLEKEYS {
    UINT cb_కొలత;
    DWORD dwFlags;
  } TOGGLEKEYS,*LPTOGGLEKEYS;

#నిర్వచించు TKF_TOGGLEKEYSON 0x00000001
#నిర్వచించు TKF_అందుబాటు 0x00000002
#నిర్వచించు TKF_HOTKEYACTIVE 0x00000004
#నిర్వచించు TKF_CONFIRMHOTKEY 0x00000008
#నిర్వచించు TKF_HOTKEYSOUND 0x00000010
#నిర్వచించు TKF_INDICATOR 0x00000020

  WINUSERAPI VOID WINAPI సమితి_Debug_Error_Level(DWORD dwLevel);

#నిర్వచించు SLE_ERROR 0x00000001
#నిర్వచించు SLE_MINORERROR 0x00000002
#నిర్వచించు SLE_WARNING 0x00000003

  WINUSERAPI VOID WINAPI సమితి_చివరి_Error_Ex(DWORD dw_Err_సంకేతం,DWORD dwType);
  WINUSERAPI పూర్ణాంకం WINAPI అంతర్గత_Get_కిటికీ_పాఠ్యం(HWND hWnd,LPWSTR pString,పూర్ణాంకం cch_Max_లెక్క);

#నిర్వచితమైతే WINNT
  WINUSERAPI WINBOOL WINAPI చివర_Task(HWND hWnd,WINBOOL f_Shut_కిందికి,WINBOOL fForce);
#అయితే_ముగింపు

#నిర్వచించు MONITOR_DEFAULTTONULL 0x00000000
#నిర్వచించు MONITOR_DEFAULTTOPRIMARY 0x00000001
#నిర్వచించు MONITOR_DEFAULTTONEAREST 0x00000002

  WINUSERAPI HMONITOR WINAPI Monitor_From_బిందువు(బిందువు_3 pt,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromRect(LPCRECT lprc,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI Monitor_From_కిటికీ(HWND hwnd,DWORD dwFlags);

#నిర్వచించు MONITORINFOF_PRIMARY 0x00000001

#నిర్వచితం_కాకపోతే CCHDEVICENAME
#నిర్వచించు CCHDEVICENAME 32
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MONITORINFO {
    DWORD cb_కొలత;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
  } MONITORINFO,*LPMONITORINFO;

#నిర్వచితమైతే __cplusplus
  రకనిర్వచనం నిర్మాణం ట్యాగ్_MONITORINFOEXA : బహిరంగ ట్యాగ్_MONITORINFO {
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MONITORINFOEXW : బహిరంగ ట్యాగ్_MONITORINFO {
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం MONITORINFOEXW MONITORINFOEX;
  రకనిర్వచనం LPMONITORINFOEXW LPMONITORINFOEX;
#లేకపోతే
  రకనిర్వచనం MONITORINFOEXA MONITORINFOEX;
  రకనిర్వచనం LPMONITORINFOEXA LPMONITORINFOEX;
#అయితే_ముగింపు
#లేకపోతే
  రకనిర్వచనం నిర్మాణం ట్యాగ్_MONITORINFOEXA {
    MONITORINFO mi;
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MONITORINFOEXW {
    MONITORINFO mi;
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం MONITORINFOEXW MONITORINFOEX;
  రకనిర్వచనం LPMONITORINFOEXW LPMONITORINFOEX;
#లేకపోతే
  రకనిర్వచనం MONITORINFOEXA MONITORINFOEX;
  రకనిర్వచనం LPMONITORINFOEXA LPMONITORINFOEX;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE 
#నిర్వచించు GetMonitorInfo GetMonitorInfoW
#లేకపోతే
#నిర్వచించు GetMonitorInfo GetMonitorInfoA
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
  WINUSERAPI WINBOOL WINAPI GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);

  రకనిర్వచనం WINBOOL (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

  WINUSERAPI WINBOOL WINAPI EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dw_దత్తాంశం);

#నిర్వచితం_కాకపోతే NOWINABLE
  WINUSERAPI VOID WINAPI NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG id_బిడ్డ);

  రకనిర్వచనం VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK hWinEventHook,DWORD event,HWND hwnd,LONG idObject,LONG id_బిడ్డ,DWORD idEventThread,DWORD dwms_Event_సమయం);

  WINUSERAPI HWINEVENTHOOK WINAPI సమితి_Win_Event_Hook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI IsWinEventHookInstalled(DWORD event);

#నిర్వచించు WINEVENT_OUTOFCONTEXT 0x0000
#నిర్వచించు WINEVENT_SKIPOWNTHREAD 0x0001
#నిర్వచించు WINEVENT_SKIPOWNPROCESS 0x0002
#నిర్వచించు WINEVENT_INCONTEXT 0x0004

  WINUSERAPI WINBOOL WINAPI UnhookWinEvent(HWINEVENTHOOK hWinEventHook);

#నిర్వచించు CHILDID_SELF 0
#నిర్వచించు INDEXID_OBJECT 0
#నిర్వచించు INDEXID_CONTAINER 0

#నిర్వచించు OBJID_కిటికీ ((LONG)0x00000000)
#నిర్వచించు OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#నిర్వచించు OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#నిర్వచించు OBJID_MENU ((LONG)0xFFFFFFFD)
#నిర్వచించు OBJID_CLIENT ((LONG)0xFFFFFFFC)
#నిర్వచించు OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#నిర్వచించు OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#నిర్వచించు OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#నిర్వచించు OBJID_CARET ((LONG)0xFFFFFFF8)
#నిర్వచించు OBJID_CURSOR ((LONG)0xFFFFFFF7)
#నిర్వచించు OBJID_ALERT ((LONG)0xFFFFFFF6)
#నిర్వచించు OBJID_SOUND ((LONG)0xFFFFFFF5)
#నిర్వచించు OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#నిర్వచించు OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#నిర్వచించు EVENT_MIN 0x00000001
#నిర్వచించు EVENT_MAX 0x7FFFFFFF

#నిర్వచించు EVENT_SYSTEM_SOUND 0x0001
#నిర్వచించు EVENT_SYSTEM_ALERT 0x0002
#నిర్వచించు EVENT_SYSTEM_FOREGROUND 0x0003
#నిర్వచించు EVENT_SYSTEM_MENUSTART 0x0004
#నిర్వచించు EVENT_SYSTEM_MENUEND 0x0005
#నిర్వచించు EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#నిర్వచించు EVENT_SYSTEM_MENUPOPUPEND 0x0007
#నిర్వచించు EVENT_SYSTEM_CAPTURESTART 0x0008
#నిర్వచించు EVENT_SYSTEM_CAPTUREEND 0x0009
#నిర్వచించు EVENT_SYSTEM_MOVESIZESTART 0x000A
#నిర్వచించు EVENT_SYSTEM_MOVESIZEEND 0x000B
#నిర్వచించు EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#నిర్వచించు EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#నిర్వచించు EVENT_SYSTEM_DRAGDROPSTART 0x000E
#నిర్వచించు EVENT_SYSTEM_DRAGDROPEND 0x000F
#నిర్వచించు EVENT_SYSTEM_DIALOGSTART 0x0010
#నిర్వచించు EVENT_SYSTEM_DIALOGEND 0x0011
#నిర్వచించు EVENT_SYSTEM_SCROLLINGSTART 0x0012
#నిర్వచించు EVENT_SYSTEM_SCROLLINGEND 0x0013
#నిర్వచించు EVENT_SYSTEM_SWITCHSTART 0x0014
#నిర్వచించు EVENT_SYSTEM_SWITCHEND 0x0015
#నిర్వచించు EVENT_SYSTEM_MINIMIZESTART 0x0016
#నిర్వచించు EVENT_SYSTEM_MINIMIZEEND 0x0017

#నిర్వచించు EVENT_CONSOLE_CARET 0x4001
#నిర్వచించు EVENT_CONSOLE_UPDATE_REGION 0x4002
#నిర్వచించు EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#నిర్వచించు EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#నిర్వచించు EVENT_CONSOLE_LAYOUT 0x4005
#నిర్వచించు EVENT_CONSOLE_ప్రారంభం_APPLICATION 0x4006
#నిర్వచించు EVENT_CONSOLE_చివర_APPLICATION 0x4007

#నిర్వచించు CONSOLE_APPLICATION_16_బిట్టు 0x0001

#నిర్వచించు CONSOLE_CARET_SELECTION 0x0001
#నిర్వచించు CONSOLE_CARET_VISIBLE 0x0002

#నిర్వచించు EVENT_OBJECT_CREATE 0x8000
#నిర్వచించు EVENT_OBJECT_DESTROY 0x8001
#నిర్వచించు EVENT_OBJECT_SHOW 0x8002
#నిర్వచించు EVENT_OBJECT_HIDE 0x8003
#నిర్వచించు EVENT_OBJECT_REORDER 0x8004

#నిర్వచించు EVENT_OBJECT_FOCUS 0x8005
#నిర్వచించు EVENT_OBJECT_SELECTION 0x8006
#నిర్వచించు EVENT_OBJECT_SELECTIONADD 0x8007
#నిర్వచించు EVENT_OBJECT_SELECTIONREMOVE 0x8008
#నిర్వచించు EVENT_OBJECT_SELECTIONWITHIN 0x8009

#నిర్వచించు EVENT_OBJECT_STATECHANGE 0x800A

#నిర్వచించు EVENT_OBJECT_LOCATIONCHANGE 0x800B

#నిర్వచించు EVENT_OBJECT_NAMECHANGE 0x800C
#నిర్వచించు EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#నిర్వచించు EVENT_OBJECT_VALUECHANGE 0x800E
#నిర్వచించు EVENT_OBJECT_PARENTCHANGE 0x800F
#నిర్వచించు EVENT_OBJECT_HELPCHANGE 0x8010
#నిర్వచించు EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#నిర్వచించు EVENT_OBJECT_ACCELERATORCHANGE 0x8012

#నిర్వచించు SOUND_SYSTEM_STARTUP 1
#నిర్వచించు SOUND_SYSTEM_SHUTDOWN 2
#నిర్వచించు SOUND_SYSTEM_BEEP 3
#నిర్వచించు SOUND_SYSTEM_ERROR 4
#నిర్వచించు SOUND_SYSTEM_QUESTION 5
#నిర్వచించు SOUND_SYSTEM_WARNING 6
#నిర్వచించు SOUND_SYSTEM_INFORMATION 7
#నిర్వచించు SOUND_SYSTEM_MAXIMIZE 8
#నిర్వచించు SOUND_SYSTEM_MINIMIZE 9
#నిర్వచించు SOUND_SYSTEM_RESTOREUP 10
#నిర్వచించు SOUND_SYSTEM_RESTOREDOWN 11
#నిర్వచించు SOUND_SYSTEM_APPSTART 12
#నిర్వచించు SOUND_SYSTEM_FAULT 13
#నిర్వచించు SOUND_SYSTEM_APPEND 14
#నిర్వచించు SOUND_SYSTEM_MENUCOMMAND 15
#నిర్వచించు SOUND_SYSTEM_MENUPOPUP 16
#నిర్వచించు CSOUND_SYSTEM 16

#నిర్వచించు ALERT_SYSTEM_INFORMATIONAL 1
#నిర్వచించు ALERT_SYSTEM_WARNING 2
#నిర్వచించు ALERT_SYSTEM_ERROR 3
#నిర్వచించు ALERT_SYSTEM_QUERY 4
#నిర్వచించు ALERT_SYSTEM_CRITICAL 5
#నిర్వచించు CALERT_SYSTEM 6

  రకనిర్వచనం నిర్మాణం ట్యాగ్_GUITHREADINFO {
    DWORD cb_కొలత;
    DWORD flags;
    HWND hwnd_చురుకైన;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwnd_Move_కొలత;
    HWND hwndCaret;
    RECT rcCaret;
  } GUITHREADINFO,*PGUITHREADINFO,*LPGUITHREADINFO;

#నిర్వచించు GUI_CARETBLINKING 0x00000001
#నిర్వచించు GUI_INMOVESIZE 0x00000002
#నిర్వచించు GUI_INMENUMODE 0x00000004
#నిర్వచించు GUI_SYSTEMMENUMODE 0x00000008
#నిర్వచించు GUI_POPUPMENUMODE 0x00000010
#నిర్వచించు GUI_16BITTASK 0x00000020

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_కిటికీ_Module_File_Name Get_కిటికీ_Module_File_Name_W
#లేకపోతే
#నిర్వచించు Get_కిటికీ_Module_File_Name Get_కిటికీ_Module_File_Name_A
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui);
  WINUSERAPI UINT WINAPI Get_కిటికీ_Module_File_Name_A(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
  WINUSERAPI UINT WINAPI Get_కిటికీ_Module_File_Name_W(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);

#నిర్వచితం_కాకపోతే NO_STATE_FLAGS
#నిర్వచించు STATE_SYSTEM_UNAVAILABLE 0x00000001
#నిర్వచించు STATE_SYSTEM_SELECTED 0x00000002
#నిర్వచించు STATE_SYSTEM_FOCUSED 0x00000004
#నిర్వచించు STATE_SYSTEM_PRESSED 0x00000008
#నిర్వచించు STATE_SYSTEM_CHECKED 0x00000010
#నిర్వచించు STATE_SYSTEM_MIXED 0x00000020
#నిర్వచించు STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#నిర్వచించు STATE_SYSTEM_READONLY 0x00000040
#నిర్వచించు STATE_SYSTEM_HOTTRACKED 0x00000080
#నిర్వచించు STATE_SYSTEM_DEFAULT 0x00000100
#నిర్వచించు STATE_SYSTEM_EXPANDED 0x00000200
#నిర్వచించు STATE_SYSTEM_COLLAPSED 0x00000400
#నిర్వచించు STATE_SYSTEM_BUSY 0x00000800
#నిర్వచించు STATE_SYSTEM_FLOATING 0x00001000
#నిర్వచించు STATE_SYSTEM_MARQUEED 0x00002000
#నిర్వచించు STATE_SYSTEM_ANIMATED 0x00004000
#నిర్వచించు STATE_SYSTEM_INVISIBLE 0x00008000
#నిర్వచించు STATE_SYSTEM_OFFSCREEN 0x00010000
#నిర్వచించు STATE_SYSTEM_SIZEABLE 0x00020000
#నిర్వచించు STATE_SYSTEM_MOVEABLE 0x00040000
#నిర్వచించు STATE_SYSTEM_SELFVOICING 0x00080000
#నిర్వచించు STATE_SYSTEM_FOCUSABLE 0x00100000
#నిర్వచించు STATE_SYSTEM_SELECTABLE 0x00200000
#నిర్వచించు STATE_SYSTEM_LINKED 0x00400000
#నిర్వచించు STATE_SYSTEM_TRAVERSED 0x00800000
#నిర్వచించు STATE_SYSTEM_MULTISELECTABLE 0x01000000
#నిర్వచించు STATE_SYSTEM_EXTSELECTABLE 0x02000000
#నిర్వచించు STATE_SYSTEM_ALERT_దిగువ 0x04000000
#నిర్వచించు STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#నిర్వచించు STATE_SYSTEM_ALERT_ఎగువ 0x10000000
#నిర్వచించు STATE_SYSTEM_PROTECTED 0x20000000
#నిర్వచించు STATE_SYSTEM_VALID 0x3FFFFFFF
#అయితే_ముగింపు

#నిర్వచించు CCHILDREN_TITLEBAR 5
#నిర్వచించు CCHILDREN_SCROLLBAR 5

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CURSORINFO {
    DWORD cb_కొలత;
    DWORD flags;
    HCURSOR hCursor;
    బిందువు_3 ptScreenPos;
  } CURSORINFO,*PCURSORINFO,*LPCURSORINFO;

#నిర్వచించు CURSOR_SHOWING 0x00000001

  WINUSERAPI WINBOOL WINAPI GetCursorInfo(PCURSORINFO pci);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_WINDOWINFO {
    DWORD cb_కొలత;
    RECT rc_కిటికీ;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dw_కిటికీ_స్థితి;
    UINT cx_కిటికీ_Borders;
    UINT cy_కిటికీ_Borders;
    ATOM atom_కిటికీ_Type;
    మాట_3 w_Creator_సంస్కరణ;
  } WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;

#నిర్వచించు WS_ACTIVECAPTION 0x0001

  WINUSERAPI WINBOOL WINAPI Get_కిటికీ_Info(HWND hwnd,PWINDOWINFO pwi);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_TITLEBARINFO {
    DWORD cb_కొలత;
    RECT rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  } TITLEBARINFO,*PTITLEBARINFO,*LPTITLEBARINFO;

  WINUSERAPI WINBOOL WINAPI GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_MENUBARINFO {
    DWORD cb_కొలత;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    WINBOOL fBarFocused:1;
    WINBOOL fFocused:1;
  } MENUBARINFO,*PMENUBARINFO,*LPMENUBARINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuBarInfo(HWND hwnd,LONG idObject,LONG id_అంశం,PMENUBARINFO pmbi);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_SCROLLBARINFO {
    DWORD cb_కొలత;
    RECT rcScrollBar;
    పూర్ణాంకం dxy_పంక్తి_Button;
    పూర్ణాంకం xy_Thumb_శిఖరం;
    పూర్ణాంకం xyThumbBottom;
    పూర్ణాంకం reserved;
    DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
  } SCROLLBARINFO,*PSCROLLBARINFO,*LPSCROLLBARINFO;

  WINUSERAPI WINBOOL WINAPI GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_COMBOBOXINFO {
    DWORD cb_కొలత;
    RECT rc_అంశం;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwnd_అంశం;
    HWND hwndList;
  } COMBOBOXINFO,*PCOMBOBOXINFO,*LPCOMBOBOXINFO;

  WINUSERAPI WINBOOL WINAPI GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi);

#నిర్వచించు GA_మాతృ 1
#నిర్వచించు GA_మూలం 2
#నిర్వచించు GA_ROOTOWNER 3

  WINUSERAPI HWND WINAPI GetAncestor(HWND hwnd,UINT gaFlags);
  WINUSERAPI HWND WINAPI Real_బిడ్డ_కిటికీ_From_బిందువు(HWND hwnd_మాతృ_2,బిందువు_3 pt_మాతృ_Client_Coords);
  WINUSERAPI UINT WINAPI Real_Get_కిటికీ_Class_A(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
  WINUSERAPI UINT WINAPI Real_Get_కిటికీ_Class_W(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
#నిర్వచితమైతే UNICODE
#నిర్వచించు Real_Get_కిటికీ_Class Real_Get_కిటికీ_Class_W
#లేకపోతే
#నిర్వచించు Real_Get_కిటికీ_Class Real_Get_కిటికీ_Class_A
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ALTTABINFO {
    DWORD cb_కొలత;
    పూర్ణాంకం c_వస్తువులు;
    పూర్ణాంకం cColumns;
    పూర్ణాంకం c_అడ్డువరుసలు;
    పూర్ణాంకం i_నిలువు_Focus;
    పూర్ణాంకం i_అడ్డువరుస_Focus;
    పూర్ణాంకం cx_అంశం;
    పూర్ణాంకం cy_అంశం;
    బిందువు_3 pt_ప్రారంభం;
  } ALTTABINFO,*PALTTABINFO,*LPALTTABINFO;

#నిర్వచితమైతే UNICODE
#నిర్వచించు GetAltTabInfo GetAltTabInfoW
#లేకపోతే
#నిర్వచించు GetAltTabInfo GetAltTabInfoA
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI GetAltTabInfoA(HWND hwnd,పూర్ణాంకం i_అంశం,PALTTABINFO pati,LPSTR psz_అంశం_పాఠ్యం,UINT cch_అంశం_పాఠ్యం);
  WINUSERAPI WINBOOL WINAPI GetAltTabInfoW(HWND hwnd,పూర్ణాంకం i_అంశం,PALTTABINFO pati,LPWSTR psz_అంశం_పాఠ్యం,UINT cch_అంశం_పాఠ్యం);
  WINUSERAPI DWORD WINAPI GetListBoxInfo(HWND hwnd);
#అయితే_ముగింపు

  WINUSERAPI WINBOOL WINAPI తాళం_Work_Station(VOID);
  WINUSERAPI WINBOOL WINAPI UserHandleGrantAccess(HANDLE hUserHandle,HANDLE h_పని,WINBOOL bGrant);

  DECLARE_HANDLE(HRAWINPUT);

#నిర్వచించు GET_RAWINPUT_సంకేతం_WPARAM(wParam) ((wParam) & 0xff)

#నిర్వచించు RIM_ఆదానం 0
#నిర్వచించు RIM_INPUTSINK 1

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RAWINPUTHEADER {
    DWORD dwType;
    DWORD dw_కొలత;
    HANDLE hDevice;
    WPARAM wParam;
  } RAWINPUTHEADER,*PRAWINPUTHEADER,*LPRAWINPUTHEADER;

#నిర్వచించు RIM_TYPEMOUSE 0
#నిర్వచించు RIM_TYPEKEYBOARD 1
#నిర్వచించు RIM_TYPEHID 2

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RAWMOUSE {
    USHORT usFlags;
    సంఘం {
      ULONG ulButtons;
      నిర్మాణం {
	USHORT usButtonFlags;
	USHORT us_Button_దత్తాంశం;
      };
    };
    ULONG ulRawButtons;
    LONG l_చివరి_X;
    LONG l_చివరి_Y;
    ULONG ulExtraInformation;
  } RAWMOUSE,*PRAWMOUSE,*LPRAWMOUSE;

#నిర్వచించు RI_MOUSE_ఎడమ_BUTTON_కిందికి 0x0001
#నిర్వచించు RI_MOUSE_ఎడమ_BUTTON_పైకి 0x0002
#నిర్వచించు RI_MOUSE_కుడి_BUTTON_కిందికి 0x0004
#నిర్వచించు RI_MOUSE_కుడి_BUTTON_పైకి 0x0008
#నిర్వచించు RI_MOUSE_మధ్య_BUTTON_కిందికి 0x0010
#నిర్వచించు RI_MOUSE_మధ్య_BUTTON_పైకి 0x0020

#నిర్వచించు RI_MOUSE_BUTTON_1_కిందికి RI_MOUSE_ఎడమ_BUTTON_కిందికి
#నిర్వచించు RI_MOUSE_BUTTON_1_పైకి RI_MOUSE_ఎడమ_BUTTON_పైకి
#నిర్వచించు RI_MOUSE_BUTTON_2_కిందికి RI_MOUSE_కుడి_BUTTON_కిందికి
#నిర్వచించు RI_MOUSE_BUTTON_2_పైకి RI_MOUSE_కుడి_BUTTON_పైకి
#నిర్వచించు RI_MOUSE_BUTTON_3_కిందికి RI_MOUSE_మధ్య_BUTTON_కిందికి
#నిర్వచించు RI_MOUSE_BUTTON_3_పైకి RI_MOUSE_మధ్య_BUTTON_పైకి

#నిర్వచించు RI_MOUSE_BUTTON_4_కిందికి 0x0040
#నిర్వచించు RI_MOUSE_BUTTON_4_పైకి 0x0080
#నిర్వచించు RI_MOUSE_BUTTON_5_కిందికి 0x0100
#నిర్వచించు RI_MOUSE_BUTTON_5_పైకి 0x0200

#నిర్వచించు RI_MOUSE_WHEEL 0x0400

#నిర్వచించు MOUSE_MOVE_RELATIVE 0
#నిర్వచించు MOUSE_MOVE_ABSOLUTE 1
#నిర్వచించు MOUSE_VIRTUAL_DESKTOP 0x02
#నిర్వచించు MOUSE_లక్షణాలు_మారింది 0x04

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RAWKEYBOARD {
    USHORT Make_సంకేతం;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT సందేశం_6;
    ULONG ExtraInformation;
  } RAWKEYBOARD,*PRAWKEYBOARD,*LPRAWKEYBOARD;

#నిర్వచించు KEYBOARD_OVERRUN_MAKE_సంకేతం 0xFF

#నిర్వచించు RI_కీలకం_MAKE 0
#నిర్వచించు RI_కీలకం_BREAK 1
#నిర్వచించు RI_కీలకం_E0 2
#నిర్వచించు RI_కీలకం_E1 4
#నిర్వచించు RI_కీలకం_TERMSRV_సమితి_LED 8
#నిర్వచించు RI_కీలకం_TERMSRV_SHADOW 0x10

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RAWHID {
    DWORD dw_కొలత_Hid;
    DWORD dw_లెక్క;
    BYTE b_Raw_దత్తాంశం[1];
  } RAWHID,*PRAWHID,*LPRAWHID;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RAWINPUT {
    RAWINPUTHEADER శీర్షిక;
    సంఘం {
      RAWMOUSE mouse;
      RAWKEYBOARD keyboard;
      RAWHID hid;
    } దత్తాంశం;
  } RAWINPUT,*PRAWINPUT,*LPRAWINPUT;

#నిర్వచితమైతే _WIN64
#నిర్వచించు RAWINPUT_ALIGN(x) (((x) + పరిమాణం(QWORD) - 1) & ~(పరిమాణం(QWORD) - 1))
#లేకపోతే
#నిర్వచించు RAWINPUT_ALIGN(x) (((x) + పరిమాణం(DWORD) - 1) & ~(పరిమాణం(DWORD) - 1))
#అయితే_ముగింపు

#నిర్వచించు NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->శీర్షిక.dw_కొలత)))

#నిర్వచించు RID_ఆదానం 0x10000003
#నిర్వచించు RID_శీర్షిక 0x10000005

  WINUSERAPI UINT WINAPI Get_Raw_ఆదానం_దత్తాంశం(HRAWINPUT h_Raw_ఆదానం,UINT uiCommand,LPVOID p_దత్తాంశం,PUINT pcb_కొలత,UINT cb_కొలత_శీర్షిక);

#నిర్వచించు RIDI_PREPARSEDDATA 0x20000005
#నిర్వచించు RIDI_DEVICENAME 0x20000007
#నిర్వచించు RIDI_DEVICEINFO 0x2000000b

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dw_సంఖ్య_యొక్క_Buttons;
    DWORD dw_Sample_రేటు;
  } RID_DEVICE_INFO_MOUSE,*PRID_DEVICE_INFO_MOUSE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dw_Keyboard_బహుళకం;
    DWORD dw_సంఖ్య_యొక్క_Function_కీలకాలు;
    DWORD dw_సంఖ్య_యొక్క_Indicators;
    DWORD dw_సంఖ్య_యొక్క_కీలకాలు_మొత్తం;
  } RID_DEVICE_INFO_KEYBOARD,*PRID_DEVICE_INFO_KEYBOARD;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dw_లబ్ధం_Id;
    DWORD dw_సంస్కరణ_సంఖ్య;
    USHORT us_Usage_పుట;
    USHORT usUsage;
  } RID_DEVICE_INFO_HID,*PRID_DEVICE_INFO_HID;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RID_DEVICE_INFO {
    DWORD cb_కొలత;
    DWORD dwType;
    సంఘం {
      RID_DEVICE_INFO_MOUSE mouse;
      RID_DEVICE_INFO_KEYBOARD keyboard;
      RID_DEVICE_INFO_HID hid;
    };
  } RID_DEVICE_INFO,*PRID_DEVICE_INFO,*LPRID_DEVICE_INFO;

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_Raw_ఆదానం_Device_Info Get_Raw_ఆదానం_Device_Info_W
#లేకపోతే
#నిర్వచించు Get_Raw_ఆదానం_Device_Info Get_Raw_ఆదానం_Device_Info_A
#అయితే_ముగింపు

  WINUSERAPI UINT WINAPI Get_Raw_ఆదానం_Device_Info_A(HANDLE hDevice,UINT uiCommand,LPVOID p_దత్తాంశం,PUINT pcb_కొలత);
  WINUSERAPI UINT WINAPI Get_Raw_ఆదానం_Device_Info_W(HANDLE hDevice,UINT uiCommand,LPVOID p_దత్తాంశం,PUINT pcb_కొలత);
  WINUSERAPI UINT WINAPI Get_Raw_ఆదానం_బఫరు(PRAWINPUT p_దత్తాంశం,PUINT pcb_కొలత,UINT cb_కొలత_శీర్షిక);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RAWINPUTDEVICE {
    USHORT us_Usage_పుట;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwnd_లక్ష్యం;
  } RAWINPUTDEVICE,*PRAWINPUTDEVICE,*LPRAWINPUTDEVICE;

  రకనిర్వచనం CONST RAWINPUTDEVICE *PCRAWINPUTDEVICE;

#నిర్వచించు RIDEV_REMOVE 0x00000001
#నిర్వచించు RIDEV_EXCLUDE 0x00000010
#నిర్వచించు RIDEV_PAGEONLY 0x00000020
#నిర్వచించు RIDEV_NOLEGACY 0x00000030
#నిర్వచించు RIDEV_INPUTSINK 0x00000100
#నిర్వచించు RIDEV_CAPTUREMOUSE 0x00000200
#నిర్వచించు RIDEV_NOHOTKEYS 0x00000200
#నిర్వచించు RIDEV_APPKEYS 0x00000400
#నిర్వచించు RIDEV_EXMODEMASK 0x000000F0
#నిర్వచించు RIDEV_EXMODE(బహుళకం) ((బహుళకం) & RIDEV_EXMODEMASK)

  WINUSERAPI WINBOOL WINAPI రిజిస్టరు_Raw_ఆదానం_Devices(PCRAWINPUTDEVICE p_Raw_ఆదానం_Devices,UINT ui_అంకె_Devices,UINT cb_కొలత);
  WINUSERAPI UINT WINAPI Get_Registered_Raw_ఆదానం_Devices(PRAWINPUTDEVICE p_Raw_ఆదానం_Devices,PUINT pui_అంకె_Devices,UINT cb_కొలత);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
  } RAWINPUTDEVICELIST,*PRAWINPUTDEVICELIST;

  WINUSERAPI UINT WINAPI Get_Raw_ఆదానం_Device_List(PRAWINPUTDEVICELIST p_Raw_ఆదానం_Device_List,PUINT pui_అంకె_Devices,UINT cb_కొలత);
  WINUSERAPI LRESULT WINAPI Def_Raw_ఆదానం_Proc(PRAWINPUT *pa_Raw_ఆదానం,INT n_ఆదానం,UINT cb_కొలత_శీర్షిక);

#అయితే_ముగింపు /* NOUSER */

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
