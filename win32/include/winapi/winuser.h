/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _WINUSER_
#تعریف_کړه _WINUSER_

#تعریف_کړه WINUSERAPI DECLSPEC_IMPORT

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی WINVER
#تعریف_کړه WINVER 0x0502
#د_که_پای

#ضمن <stdarg.h>

#که_نه_تعریف_شوی NOUSER
  تعريفنوع HANDLE HDWP;
  تعريفنوع VOID MENUTEMPLATEA;
  تعريفنوع VOID MENUTEMPLATEW;
  تعريفنوع PVOID LPMENUTEMPLATEA;
  تعريفنوع PVOID LPMENUTEMPLATEW;

#که_تعریف_شوی UNICODE
  تعريفنوع MENUTEMPLATEW MENUTEMPLATE;
  تعريفنوع LPMENUTEMPLATEW LPMENUTEMPLATE;
#وإلا
  تعريفنوع MENUTEMPLATEA MENUTEMPLATE;
  تعريفنوع LPMENUTEMPLATEA LPMENUTEMPLATE;
#د_که_پای

  تعريفنوع LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
  تعريفنوع INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
  تعريفنوع VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
  تعريفنوع WINBOOL (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,صحيح);
  تعريفنوع WINBOOL (CALLBACK *WNDENUMPROC)(HWND,LPARAM);
  تعريفنوع LRESULT (CALLBACK *HOOKPROC)(صحيح کوډ,WPARAM wParam,LPARAM lParam);
  تعريفنوع VOID (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
  تعريفنوع صحيح (CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch,صحيح ichCurrent,صحيح cch,صحيح کوډ);
  تعريفنوع صحيح (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch,صحيح ichCurrent,صحيح cch,صحيح کوډ);
  تعريفنوع WINBOOL (CALLBACK *DRAWSTATEPROC)(HDC hdc,LPARAM l_معلومات,WPARAM w_معلومات,صحيح cx,صحيح cy);

#که_تعریف_شوی UNICODE
  تعريفنوع PROPENUMPROCW PROPENUMPROC;
  تعريفنوع PROPENUMPROCEXW PROPENUMPROCEX;
  تعريفنوع EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#وإلا
  تعريفنوع PROPENUMPROCA PROPENUMPROC;
  تعريفنوع PROPENUMPROCEXA PROPENUMPROCEX;
  تعريفنوع EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#د_که_پای

  تعريفنوع WINBOOL (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
  تعريفنوع WINBOOL (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
  تعريفنوع NAMEENUMPROCA WINSTAENUMPROCA;
  تعريفنوع NAMEENUMPROCA DESKTOPENUMPROCA;
  تعريفنوع NAMEENUMPROCW WINSTAENUMPROCW;
  تعريفنوع NAMEENUMPROCW DESKTOPENUMPROCW;

#که_تعریف_شوی UNICODE
  تعريفنوع WINSTAENUMPROCW WINSTAENUMPROC;
  تعريفنوع DESKTOPENUMPROCW DESKTOPENUMPROC;
#وإلا
  تعريفنوع WINSTAENUMPROCA WINSTAENUMPROC;
  تعريفنوع DESKTOPENUMPROCA DESKTOPENUMPROC;
#د_که_پای

#تعریف_کړه IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)
#تعریف_کړه MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((کلمه_3)(i))))
#تعریف_کړه MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((کلمه_3)(i))))
#که_تعریف_شوی UNICODE
#تعریف_کړه MAKEINTRESOURCE MAKEINTRESOURCEW
#وإلا
#تعریف_کړه MAKEINTRESOURCE MAKEINTRESOURCEA
#د_که_پای

#که_نه_تعریف_شوی NORESOURCE

#تعریف_کړه RT_CURSOR MAKEINTRESOURCE(1)
#تعریف_کړه RT_BITMAP MAKEINTRESOURCE(2)
#تعریف_کړه RT_ICON MAKEINTRESOURCE(3)
#تعریف_کړه RT_MENU MAKEINTRESOURCE(4)
#تعریف_کړه RT_DIALOG MAKEINTRESOURCE(5)
#تعریف_کړه RT_STRING MAKEINTRESOURCE(6)
#تعریف_کړه RT_FONTDIR MAKEINTRESOURCE(7)
#تعریف_کړه RT_FONT MAKEINTRESOURCE(8)
#تعریف_کړه RT_ACCELERATOR MAKEINTRESOURCE(9)
#تعریف_کړه RT_RCDATA MAKEINTRESOURCE(10)
#تعریف_کړه RT_MESSAGETABLE MAKEINTRESOURCE(11)

#تعریف_کړه DIFFERENCE 11
#تعریف_کړه RT_ډله_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
#تعریف_کړه RT_ډله_ICON MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
#تعریف_کړه RT_نسخه MAKEINTRESOURCE(16)
#تعریف_کړه RT_DLGINCLUDE MAKEINTRESOURCE(17)
#تعریف_کړه RT_PLUGPLAY MAKEINTRESOURCE(19)
#تعریف_کړه RT_VXD MAKEINTRESOURCE(20)
#تعریف_کړه RT_ANICURSOR MAKEINTRESOURCE(21)
#تعریف_کړه RT_ANIICON MAKEINTRESOURCE(22)
#تعریف_کړه RT_HTML MAKEINTRESOURCE(23)
#که_تعریف_شوی RC_INVOKED
#تعریف_کړه RT_MANIFEST 24
#تعریف_کړه CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#تعریف_کړه ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#تعریف_کړه ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#تعریف_کړه MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#تعریف_کړه اعظمي_RESERVED_MANIFEST_RESOURCE_ID 16
#وإلا
#تعریف_کړه RT_MANIFEST MAKEINTRESOURCE(24)
#تعریف_کړه CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#تعریف_کړه ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#تعریف_کړه ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#تعریف_کړه MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#تعریف_کړه اعظمي_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)
#د_که_پای
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه wvsprintf wvsprintfW
#تعریف_کړه wsprintf wsprintfW
#وإلا
#تعریف_کړه wvsprintf wvsprintfA
#تعریف_کړه wsprintf wsprintfA
#د_که_پای

  WINUSERAPI صحيح WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
  WINUSERAPI صحيح WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);
  WINUSERAPI صحيح WINAPIV wsprintfA(LPSTR,LPCSTR,...);
  WINUSERAPI صحيح WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);

#تعریف_کړه SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#که_نه_تعریف_شوی NOSCROLL
#تعریف_کړه SB_HORZ 0
#تعریف_کړه SB_VERT 1
#تعریف_کړه SB_CTL 2
#تعریف_کړه SB_BOTH 3

#تعریف_کړه SB_LINEUP 0
#تعریف_کړه SB_LINELEFT 0
#تعریف_کړه SB_LINEDOWN 1
#تعریف_کړه SB_LINERIGHT 1
#تعریف_کړه SB_PAGEUP 2
#تعریف_کړه SB_PAGELEFT 2
#تعریف_کړه SB_PAGEDOWN 3
#تعریف_کړه SB_PAGERIGHT 3
#تعریف_کړه SB_THUMBPOSITION 4
#تعریف_کړه SB_THUMBTRACK 5
#تعریف_کړه SB_سر 6
#تعریف_کړه SB_کیڼ 6
#تعریف_کړه SB_BOTTOM 7
#تعریف_کړه SB_ښی 7
#تعریف_کړه SB_ENDSCROLL 8
#د_که_پای

#که_نه_تعریف_شوی NOSHOWWINDOW
#تعریف_کړه SW_HIDE 0
#تعریف_کړه SW_SHOWNORMAL 1
#تعریف_کړه SW_نورمال 1
#تعریف_کړه SW_SHOWMINIMIZED 2
#تعریف_کړه SW_SHOWMAXIMIZED 3
#تعریف_کړه SW_MAXIMIZE 3
#تعریف_کړه SW_SHOWNOACTIVATE 4
#تعریف_کړه SW_SHOW 5
#تعریف_کړه SW_MINIMIZE 6
#تعریف_کړه SW_SHOWMINNOACTIVE 7
#تعریف_کړه SW_SHOWNA 8
#تعریف_کړه SW_RESTORE 9
#تعریف_کړه SW_SHOWDEFAULT 10
#تعریف_کړه SW_FORCEMINIMIZE 11
#تعریف_کړه SW_MAX 11

#تعریف_کړه HIDE_کړکۍ 0
#تعریف_کړه SHOW_OPENWINDOW 1
#تعریف_کړه SHOW_ICONWINDOW 2
#تعریف_کړه SHOW_FULLSCREEN 3
#تعریف_کړه SHOW_OPENNOACTIVATE 4

#تعریف_کړه SW_PARENTCLOSING 1
#تعریف_کړه SW_OTHERZOOM 2
#تعریف_کړه SW_PARENTOPENING 3
#تعریف_کړه SW_OTHERUNZOOM 4
#د_که_پای

#تعریف_کړه AW_HOR_مثبت 0x00000001
#تعریف_کړه AW_HOR_NEGATIVE 0x00000002
#تعریف_کړه AW_VER_مثبت 0x00000004
#تعریف_کړه AW_VER_NEGATIVE 0x00000008
#تعریف_کړه AW_CENTER 0x00000010
#تعریف_کړه AW_HIDE 0x00010000
#تعریف_کړه AW_ACTIVATE 0x00020000
#تعریف_کړه AW_SLIDE 0x00040000
#تعریف_کړه AW_BLEND 0x00080000

#تعریف_کړه KF_EXTENDED 0x0100
#تعریف_کړه KF_DLGMODE 0x0800
#تعریف_کړه KF_MENUMODE 0x1000
#تعریف_کړه KF_ALTDOWN 0x2000
#تعریف_کړه KF_REPEAT 0x4000
#تعریف_کړه KF_پورته 0x8000

#که_نه_تعریف_شوی NOVIRTUALKEYCODES

#تعریف_کړه VK_LBUTTON 0x01
#تعریف_کړه VK_RBUTTON 0x02
#تعریف_کړه VK_CANCEL 0x03
#تعریف_کړه VK_MBUTTON 0x04
#تعریف_کړه VK_XBUTTON1 0x05
#تعریف_کړه VK_XBUTTON2 0x06
#تعریف_کړه VK_شا 0x08
#تعریف_کړه VK_TAB 0x09
#تعریف_کړه VK_CLEAR 0x0C
#تعریف_کړه VK_RETURN 0x0D
#تعریف_کړه VK_ښويدنه 0x10
#تعریف_کړه VK_CONTROL 0x11
#تعریف_کړه VK_MENU 0x12
#تعریف_کړه VK_PAUSE 0x13
#تعریف_کړه VK_CAPITAL 0x14
#تعریف_کړه VK_KANA 0x15
#تعریف_کړه VK_HANGEUL 0x15
#تعریف_کړه VK_HANGUL 0x15
#تعریف_کړه VK_JUNJA 0x17
#تعریف_کړه VK_FINAL 0x18
#تعریف_کړه VK_HANJA 0x19
#تعریف_کړه VK_KANJI 0x19
#تعریف_کړه VK_ESCAPE 0x1B
#تعریف_کړه VK_CONVERT 0x1C
#تعریف_کړه VK_NONCONVERT 0x1D
#تعریف_کړه VK_ACCEPT 0x1E
#تعریف_کړه VK_MODECHANGE 0x1F
#تعریف_کړه VK_SPACE 0x20
#تعریف_کړه VK_مخکینی 0x21
#تعریف_کړه VK_بل 0x22
#تعریف_کړه VK_پای_ټکی 0x23
#تعریف_کړه VK_HOME 0x24
#تعریف_کړه VK_کیڼ 0x25
#تعریف_کړه VK_پورته 0x26
#تعریف_کړه VK_ښی 0x27
#تعریف_کړه VK_ښکته 0x28
#تعریف_کړه VK_SELECT 0x29
#تعریف_کړه VK_PRINT 0x2A
#تعریف_کړه VK_EXECUTE 0x2B
#تعریف_کړه VK_SNAPSHOT 0x2C
#تعریف_کړه VK_ورننباسه 0x2D
#تعریف_کړه VK_DELETE 0x2E
#تعریف_کړه VK_HELP 0x2F

#تعریف_کړه VK_LWIN 0x5B
#تعریف_کړه VK_RWIN 0x5C
#تعریف_کړه VK_APPS 0x5D
#تعریف_کړه VK_SLEEP 0x5F
#تعریف_کړه VK_NUMPAD0 0x60
#تعریف_کړه VK_NUMPAD1 0x61
#تعریف_کړه VK_NUMPAD2 0x62
#تعریف_کړه VK_NUMPAD3 0x63
#تعریف_کړه VK_NUMPAD4 0x64
#تعریف_کړه VK_NUMPAD5 0x65
#تعریف_کړه VK_NUMPAD6 0x66
#تعریف_کړه VK_NUMPAD7 0x67
#تعریف_کړه VK_NUMPAD8 0x68
#تعریف_کړه VK_NUMPAD9 0x69
#تعریف_کړه VK_MULTIPLY 0x6A
#تعریف_کړه VK_جمع_کړه 0x6B
#تعریف_کړه VK_SEPARATOR 0x6C
#تعریف_کړه VK_کمول 0x6D
#تعریف_کړه VK_DECIMAL 0x6E
#تعریف_کړه VK_DIVIDE 0x6F
#تعریف_کړه VK_F1 0x70
#تعریف_کړه VK_F2 0x71
#تعریف_کړه VK_F3 0x72
#تعریف_کړه VK_F4 0x73
#تعریف_کړه VK_F5 0x74
#تعریف_کړه VK_F6 0x75
#تعریف_کړه VK_F7 0x76
#تعریف_کړه VK_F8 0x77
#تعریف_کړه VK_F9 0x78
#تعریف_کړه VK_F10 0x79
#تعریف_کړه VK_F11 0x7A
#تعریف_کړه VK_F12 0x7B
#تعریف_کړه VK_F13 0x7C
#تعریف_کړه VK_F14 0x7D
#تعریف_کړه VK_F15 0x7E
#تعریف_کړه VK_F16 0x7F
#تعریف_کړه VK_F17 0x80
#تعریف_کړه VK_F18 0x81
#تعریف_کړه VK_F19 0x82
#تعریف_کړه VK_F20 0x83
#تعریف_کړه VK_F21 0x84
#تعریف_کړه VK_F22 0x85
#تعریف_کړه VK_F23 0x86
#تعریف_کړه VK_F24 0x87
#تعریف_کړه VK_NUMLOCK 0x90
#تعریف_کړه VK_SCROLL 0x91
#تعریف_کړه VK_OEM_NEC_EQUAL 0x92
#تعریف_کړه VK_OEM_FJ_JISHO 0x92
#تعریف_کړه VK_OEM_FJ_MASSHOU 0x93
#تعریف_کړه VK_OEM_FJ_TOUROKU 0x94
#تعریف_کړه VK_OEM_FJ_LOYA 0x95
#تعریف_کړه VK_OEM_FJ_ROYA 0x96
#تعریف_کړه VK_LSHIFT 0xA0
#تعریف_کړه VK_RSHIFT 0xA1
#تعریف_کړه VK_LCONTROL 0xA2
#تعریف_کړه VK_RCONTROL 0xA3
#تعریف_کړه VK_LMENU 0xA4
#تعریف_کړه VK_RMENU 0xA5
#تعریف_کړه VK_BROWSER_شا 0xA6
#تعریف_کړه VK_BROWSER_FORWARD 0xA7
#تعریف_کړه VK_BROWSER_REFRESH 0xA8
#تعریف_کړه VK_BROWSER_STOP 0xA9
#تعریف_کړه VK_BROWSER_پلټنه 0xAA
#تعریف_کړه VK_BROWSER_FAVORITES 0xAB
#تعریف_کړه VK_BROWSER_HOME 0xAC
#تعریف_کړه VK_VOLUME_MUTE 0xAD
#تعریف_کړه VK_VOLUME_ښکته 0xAE
#تعریف_کړه VK_VOLUME_پورته 0xAF
#تعریف_کړه VK_MEDIA_بل_TRACK 0xB0
#تعریف_کړه VK_MEDIA_PREV_TRACK 0xB1
#تعریف_کړه VK_MEDIA_STOP 0xB2
#تعریف_کړه VK_MEDIA_PLAY_PAUSE 0xB3
#تعریف_کړه VK_LAUNCH_MAIL 0xB4
#تعریف_کړه VK_LAUNCH_MEDIA_SELECT 0xB5
#تعریف_کړه VK_LAUNCH_APP1 0xB6
#تعریف_کړه VK_LAUNCH_APP2 0xB7
#تعریف_کړه VK_OEM_1 0xBA
#تعریف_کړه VK_OEM_PLUS 0xBB
#تعریف_کړه VK_OEM_COMMA 0xBC
#تعریف_کړه VK_OEM_MINUS 0xBD
#تعریف_کړه VK_OEM_PERIOD 0xBE
#تعریف_کړه VK_OEM_2 0xBF
#تعریف_کړه VK_OEM_3 0xC0
#تعریف_کړه VK_OEM_4 0xDB
#تعریف_کړه VK_OEM_5 0xDC
#تعریف_کړه VK_OEM_6 0xDD
#تعریف_کړه VK_OEM_7 0xDE
#تعریف_کړه VK_OEM_8 0xDF
#تعریف_کړه VK_OEM_AX 0xE1
#تعریف_کړه VK_OEM_102 0xE2
#تعریف_کړه VK_ICO_HELP 0xE3
#تعریف_کړه VK_ICO_00 0xE4
#تعریف_کړه VK_PROCESSKEY 0xE5
#تعریف_کړه VK_ICO_CLEAR 0xE6
#تعریف_کړه VK_PACKET 0xE7
#تعریف_کړه VK_OEM_RESET 0xE9
#تعریف_کړه VK_OEM_JUMP 0xEA
#تعریف_کړه VK_OEM_PA1 0xEB
#تعریف_کړه VK_OEM_PA2 0xEC
#تعریف_کړه VK_OEM_PA3 0xED
#تعریف_کړه VK_OEM_WSCTRL 0xEE
#تعریف_کړه VK_OEM_CUSEL 0xEF
#تعریف_کړه VK_OEM_ATTN 0xF0
#تعریف_کړه VK_OEM_پای 0xF1
#تعریف_کړه VK_OEM_COPY 0xF2
#تعریف_کړه VK_OEM_AUTO 0xF3
#تعریف_کړه VK_OEM_ENLW 0xF4
#تعریف_کړه VK_OEM_BACKTAB 0xF5
#تعریف_کړه VK_ATTN 0xF6
#تعریف_کړه VK_CRSEL 0xF7
#تعریف_کړه VK_EXSEL 0xF8
#تعریف_کړه VK_EREOF 0xF9
#تعریف_کړه VK_PLAY 0xFA
#تعریف_کړه VK_ZOOM 0xFB
#تعریف_کړه VK_NONAME 0xFC
#تعریف_کړه VK_PA1 0xFD
#تعریف_کړه VK_OEM_CLEAR 0xFE
#د_که_پای

#که_نه_تعریف_شوی NOWH

#تعریف_کړه WH_MIN (-1)
#تعریف_کړه WH_MSGFILTER (-1)
#تعریف_کړه WH_JOURNALRECORD 0
#تعریف_کړه WH_JOURNALPLAYBACK 1
#تعریف_کړه WH_KEYBOARD 2
#تعریف_کړه WH_GETMESSAGE 3
#تعریف_کړه WH_CALLWNDPROC 4
#تعریف_کړه WH_CBT 5
#تعریف_کړه WH_SYSMSGFILTER 6
#تعریف_کړه WH_MOUSE 7
#تعریف_کړه WH_HARDWARE 8
#تعریف_کړه WH_DEBUG 9
#تعریف_کړه WH_SHELL 10
#تعریف_کړه WH_FOREGROUNDIDLE 11
#تعریف_کړه WH_CALLWNDPROCRET 12

#تعریف_کړه WH_KEYBOARD_LL 13
#تعریف_کړه WH_MOUSE_LL 14

#تعریف_کړه WH_MAX 14

#تعریف_کړه WH_MINHOOK WH_MIN
#تعریف_کړه WH_MAXHOOK WH_MAX

#تعریف_کړه HC_ACTION 0
#تعریف_کړه HC_GETNEXT 1
#تعریف_کړه HC_SKIP 2
#تعریف_کړه HC_NOREMOVE 3
#تعریف_کړه HC_NOREM HC_NOREMOVE
#تعریف_کړه HC_SYSMODALON 4
#تعریف_کړه HC_SYSMODALOFF 5

#تعریف_کړه HCBT_MOVESIZE 0
#تعریف_کړه HCBT_MINMAX 1
#تعریف_کړه HCBT_QS 2
#تعریف_کړه HCBT_CREATEWND 3
#تعریف_کړه HCBT_DESTROYWND 4
#تعریف_کړه HCBT_ACTIVATE 5
#تعریف_کړه HCBT_CLICKSKIPPED 6
#تعریف_کړه HCBT_KEYSKIPPED 7
#تعریف_کړه HCBT_SYSCOMMAND 8
#تعریف_کړه HCBT_SETFOCUS 9

  تعريفنوع بنية نښان_CBT_CREATEWNDA {
    بنية نښان_CREATESTRUCTA *lpcs;
    HWND hwnd_ورننباسه_After;
  } CBT_CREATEWNDA,*LPCBT_CREATEWNDA;

  تعريفنوع بنية نښان_CBT_CREATEWNDW {
    بنية نښان_CREATESTRUCTW *lpcs;
    HWND hwnd_ورننباسه_After;
  } CBT_CREATEWNDW,*LPCBT_CREATEWNDW;
#که_تعریف_شوی UNICODE
  تعريفنوع CBT_CREATEWNDW CBT_CREATEWND;
  تعريفنوع LPCBT_CREATEWNDW LPCBT_CREATEWND;
#وإلا
  تعريفنوع CBT_CREATEWNDA CBT_CREATEWND;
  تعريفنوع LPCBT_CREATEWNDA LPCBT_CREATEWND;
#د_که_پای

  تعريفنوع بنية نښان_CBTACTIVATESTRUCT
  {
    WINBOOL fMouse;
    HWND h_Wnd_فعال;
  } CBTACTIVATESTRUCT,*LPCBTACTIVATESTRUCT;

  تعريفنوع بنية نښان_WTSSESSION_NOTIFICATION {
    DWORD cb_اندازه;
    DWORD dwSessionId;

  } WTSSESSION_NOTIFICATION,*PWTSSESSION_NOTIFICATION;

#تعریف_کړه WTS_CONSOLE_CONNECT 0x1
#تعریف_کړه WTS_CONSOLE_DISCONNECT 0x2
#تعریف_کړه WTS_REMOTE_CONNECT 0x3
#تعریف_کړه WTS_REMOTE_DISCONNECT 0x4
#تعریف_کړه WTS_SESSION_LOGON 0x5
#تعریف_کړه WTS_SESSION_LOGOFF 0x6
#تعریف_کړه WTS_SESSION_قلف 0x7
#تعریف_کړه WTS_SESSION_UNLOCK 0x8
#تعریف_کړه WTS_SESSION_REMOTE_CONTROL 0x9

#تعریف_کړه MSGF_DIALOGBOX 0
#تعریف_کړه MSGF_MESSAGEBOX 1
#تعریف_کړه MSGF_MENU 2
#تعریف_کړه MSGF_SCROLLBAR 5
#تعریف_کړه MSGF_NEXTWINDOW 6
#تعریف_کړه MSGF_MAX 8
#تعریف_کړه MSGF_USER 4096

#تعریف_کړه HSHELL_WINDOWCREATED 1
#تعریف_کړه HSHELL_WINDOWDESTROYED 2
#تعریف_کړه HSHELL_ACTIVATESHELLWINDOW 3

#تعریف_کړه HSHELL_WINDOWACTIVATED 4
#تعریف_کړه HSHELL_GETMINRECT 5
#تعریف_کړه HSHELL_REDRAW 6
#تعریف_کړه HSHELL_TASKMAN 7
#تعریف_کړه HSHELL_LANGUAGE 8
#تعریف_کړه HSHELL_SYSMENU 9
#تعریف_کړه HSHELL_ENDTASK 10
#تعریف_کړه HSHELL_ACCESSIBILITYSTATE 11
#تعریف_کړه HSHELL_APPCOMMAND 12
#تعریف_کړه HSHELL_WINDOWREPLACED 13
#تعریف_کړه HSHELL_WINDOWREPLACING 14
#تعریف_کړه HSHELL_HIGHBIT 0x8000
#تعریف_کړه HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#تعریف_کړه HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#تعریف_کړه ACCESS_STICKYKEYS 0x0001
#تعریف_کړه ACCESS_FILTERKEYS 0x0002
#تعریف_کړه ACCESS_MOUSEKEYS 0x0003

#تعریف_کړه APPCOMMAND_BROWSER_BACKWARD 1
#تعریف_کړه APPCOMMAND_BROWSER_FORWARD 2
#تعریف_کړه APPCOMMAND_BROWSER_REFRESH 3
#تعریف_کړه APPCOMMAND_BROWSER_STOP 4
#تعریف_کړه APPCOMMAND_BROWSER_پلټنه 5
#تعریف_کړه APPCOMMAND_BROWSER_FAVORITES 6
#تعریف_کړه APPCOMMAND_BROWSER_HOME 7
#تعریف_کړه APPCOMMAND_VOLUME_MUTE 8
#تعریف_کړه APPCOMMAND_VOLUME_ښکته 9
#تعریف_کړه APPCOMMAND_VOLUME_پورته 10
#تعریف_کړه APPCOMMAND_MEDIA_NEXTTRACK 11
#تعریف_کړه APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#تعریف_کړه APPCOMMAND_MEDIA_STOP 13
#تعریف_کړه APPCOMMAND_MEDIA_PLAY_PAUSE 14
#تعریف_کړه APPCOMMAND_LAUNCH_MAIL 15
#تعریف_کړه APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#تعریف_کړه APPCOMMAND_LAUNCH_APP1 17
#تعریف_کړه APPCOMMAND_LAUNCH_APP2 18
#تعریف_کړه APPCOMMAND_BASS_ښکته 19
#تعریف_کړه APPCOMMAND_BASS_BOOST 20
#تعریف_کړه APPCOMMAND_BASS_پورته 21
#تعریف_کړه APPCOMMAND_TREBLE_ښکته 22
#تعریف_کړه APPCOMMAND_TREBLE_پورته 23
#تعریف_کړه APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#تعریف_کړه APPCOMMAND_MICROPHONE_VOLUME_ښکته 25
#تعریف_کړه APPCOMMAND_MICROPHONE_VOLUME_پورته 26
#تعریف_کړه APPCOMMAND_HELP 27
#تعریف_کړه APPCOMMAND_پیدا_کړه 28
#تعریف_کړه APPCOMMAND_NEW 29
#تعریف_کړه APPCOMMAND_OPEN 30
#تعریف_کړه APPCOMMAND_CLOSE 31
#تعریف_کړه APPCOMMAND_SAVE 32
#تعریف_کړه APPCOMMAND_PRINT 33
#تعریف_کړه APPCOMMAND_UNDO 34
#تعریف_کړه APPCOMMAND_REDO 35
#تعریف_کړه APPCOMMAND_COPY 36
#تعریف_کړه APPCOMMAND_CUT 37
#تعریف_کړه APPCOMMAND_PASTE 38
#تعریف_کړه APPCOMMAND_ځواب_منزل_MAIL 39
#تعریف_کړه APPCOMMAND_FORWARD_MAIL 40
#تعریف_کړه APPCOMMAND_SEND_MAIL 41
#تعریف_کړه APPCOMMAND_SPELL_CHECK 42
#تعریف_کړه APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#تعریف_کړه APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#تعریف_کړه APPCOMMAND_CORRECTION_LIST 45
#تعریف_کړه APPCOMMAND_MEDIA_PLAY 46
#تعریف_کړه APPCOMMAND_MEDIA_PAUSE 47
#تعریف_کړه APPCOMMAND_MEDIA_ریکارډ 48
#تعریف_کړه APPCOMMAND_MEDIA_FAST_FORWARD 49
#تعریف_کړه APPCOMMAND_MEDIA_REWIND 50
#تعریف_کړه APPCOMMAND_MEDIA_CHANNEL_پورته 51
#تعریف_کړه APPCOMMAND_MEDIA_CHANNEL_ښکته 52

#تعریف_کړه FAPPCOMMAND_MOUSE 0x8000
#تعریف_کړه FAPPCOMMAND_کلی 0
#تعریف_کړه FAPPCOMMAND_OEM 0x1000
#تعریف_کړه FAPPCOMMAND_ماسک 0xF000

#تعریف_کړه GET_APPCOMMAND_LPARAM(lParam) ((لنډ)(HIWORD(lParam) & ~FAPPCOMMAND_ماسک))
#تعریف_کړه GET_DEVICE_LPARAM(lParam) ((کلمه_3)(HIWORD(lParam) & FAPPCOMMAND_ماسک))
#تعریف_کړه GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#تعریف_کړه GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#تعریف_کړه GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)

  تعريفنوع بنية {
    HWND hwnd;
    RECT rc;
  } SHELLHOOKINFO,*LPSHELLHOOKINFO;

  تعريفنوع بنية نښان_EVENTMSG {
    UINT پیغام_2;
    UINT paramL;
    UINT paramH;
    DWORD وخت;
    HWND hwnd;
  } EVENTMSG,*PEVENTMSGMSG,*NPEVENTMSGMSG,*LPEVENTMSGMSG;

  تعريفنوع بنية نښان_EVENTMSG *PEVENTMSG,*NPEVENTMSG,*LPEVENTMSG;

  تعريفنوع بنية نښان_CWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT پیغام_2;
    HWND hwnd;
  } CWPSTRUCT,*PCWPSTRUCT,*NPCWPSTRUCT,*LPCWPSTRUCT;

  تعريفنوع بنية نښان_CWPRETSTRUCT {
    LRESULT l_پایله;
    LPARAM lParam;
    WPARAM wParam;
    UINT پیغام_2;
    HWND hwnd;
  } CWPRETSTRUCT,*PCWPRETSTRUCT,*NPCWPRETSTRUCT,*LPCWPRETSTRUCT;

#تعریف_کړه LLKHF_EXTENDED (KF_EXTENDED >> 8)
#تعریف_کړه LLKHF_INJECTED 0x00000010
#تعریف_کړه LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#تعریف_کړه LLKHF_پورته (KF_پورته >> 8)

#تعریف_کړه LLMHF_INJECTED 0x00000001

  تعريفنوع بنية نښان_KBDLLHOOKSTRUCT {
    DWORD vk_کوډ;
    DWORD لټون_کوډ;
    DWORD flags;
    DWORD وخت;
    ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;

  تعريفنوع بنية نښان_MSLLHOOKSTRUCT {
    ټکی_3 pt;
    DWORD mouse_معلومات;
    DWORD flags;
    DWORD وخت;
    ULONG_PTR dwExtraInfo;
  } MSLLHOOKSTRUCT,*LPMSLLHOOKSTRUCT,*PMSLLHOOKSTRUCT;

  تعريفنوع بنية نښان_DEBUGHOOKINFO {
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    صحيح کوډ;
  } DEBUGHOOKINFO,*PDEBUGHOOKINFO,*NPDEBUGHOOKINFO,*LPDEBUGHOOKINFO;

  تعريفنوع بنية نښان_MOUSEHOOKSTRUCT {
    ټکی_3 pt;
    HWND hwnd;
    UINT w_موندنه_Test_کوډ;
    ULONG_PTR dwExtraInfo;
  } MOUSEHOOKSTRUCT,*LPMOUSEHOOKSTRUCT,*PMOUSEHOOKSTRUCT;

#که_تعریف_شوی __cplusplus
  تعريفنوع بنية نښان_MOUSEHOOKSTRUCTEX : عام نښان_MOUSEHOOKSTRUCT {
    DWORD mouse_معلومات;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#وإلا
  تعريفنوع بنية نښان_MOUSEHOOKSTRUCTEX {
    MOUSEHOOKSTRUCT _unnamed;
    DWORD mouse_معلومات;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#د_که_پای

  تعريفنوع بنية نښان_HARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT پیغام_2;
    WPARAM wParam;
    LPARAM lParam;
  } HARDWAREHOOKSTRUCT,*LPHARDWAREHOOKSTRUCT,*PHARDWAREHOOKSTRUCT;
#د_که_پای

#تعریف_کړه HKL_PREV 0
#تعریف_کړه HKL_بل 1

#تعریف_کړه KLF_ACTIVATE 0x00000001
#تعریف_کړه KLF_SUBSTITUTE_OK 0x00000002
#تعریف_کړه KLF_REORDER 0x00000008
#تعریف_کړه KLF_REPLACELANG 0x00000010
#تعریف_کړه KLF_NOTELLSHELL 0x00000080
#تعریف_کړه KLF_SETFORPROCESS 0x00000100
#تعریف_کړه KLF_SHIFTLOCK 0x00010000
#تعریف_کړه KLF_RESET 0x40000000

#تعریف_کړه INPUTLANGCHANGE_SYSCHARSET 0x0001
#تعریف_کړه INPUTLANGCHANGE_FORWARD 0x0002
#تعریف_کړه INPUTLANGCHANGE_BACKWARD 0x0004

#تعریف_کړه KL_NAMELENGTH 9

#که_تعریف_شوی UNICODE
#تعریف_کړه بارول_Keyboard_Layout بارول_Keyboard_Layout_W
#تعریف_کړه GetKeyboardLayoutName GetKeyboardLayoutNameW
#وإلا
#تعریف_کړه بارول_Keyboard_Layout بارول_Keyboard_Layout_A
#تعریف_کړه GetKeyboardLayoutName GetKeyboardLayoutNameA
#د_که_پای

  WINUSERAPI HKL WINAPI بارول_Keyboard_Layout_A(LPCSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI بارول_Keyboard_Layout_W(LPCWSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ActivateKeyboardLayout(HKL hkl,UINT Flags);
  WINUSERAPI صحيح WINAPI منزل_Unicode_Ex(UINT w_Virt_کلی,UINT w_لټون_کوډ,CONST BYTE *lp_کلی_State,LPWSTR pwszBuff,صحيح cchBuff,UINT wFlags,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI UnloadKeyboardLayout(HKL hkl);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameA(LPSTR pwszKLID);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameW(LPWSTR pwszKLID);
  WINUSERAPI صحيح WINAPI GetKeyboardLayoutList(صحيح nBuff,HKL *lpList);
  WINUSERAPI HKL WINAPI GetKeyboardLayout(DWORD idThread);

  تعريفنوع بنية نښان_MOUSEMOVEPOINT {
    صحيح x;
    صحيح y;
    DWORD وخت;
    ULONG_PTR dwExtraInfo;
  } MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

#تعریف_کړه GMMP_USE_DISPLAY_POINTS 1
#تعریف_کړه GMMP_USE_لوړ_RESOLUTION_POINTS 2

  WINUSERAPI صحيح WINAPI GetMouseMovePointsEx(UINT cb_اندازه,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,صحيح nBufPoints,DWORD resolution);

#که_نه_تعریف_شوی NODESKTOP

#تعریف_کړه DESKTOP_READOBJECTS 0x0001L
#تعریف_کړه DESKTOP_CREATEWINDOW 0x0002L
#تعریف_کړه DESKTOP_CREATEMENU 0x0004L
#تعریف_کړه DESKTOP_HOOKCONTROL 0x0008L
#تعریف_کړه DESKTOP_JOURNALRECORD 0x0010L
#تعریف_کړه DESKTOP_JOURNALPLAYBACK 0x0020L
#تعریف_کړه DESKTOP_ENUMERATE 0x0040L
#تعریف_کړه DESKTOP_WRITEOBJECTS 0x0080L
#تعریف_کړه DESKTOP_SWITCHDESKTOP 0x0100L

#تعریف_کړه DF_ALLOWOTHERACCOUNTHOOK 0x0001L

#که_تعریف_شوی _WINGDI_
#که_نه_تعریف_شوی NOGDI
#که_تعریف_شوی UNICODE
#تعریف_کړه CreateDesktop CreateDesktopW
#وإلا
#تعریف_کړه CreateDesktop CreateDesktopA
#د_که_پای

  WINUSERAPI HDESK WINAPI CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,LPDEVMODEA pDevmode,DWORD dwFlags,ACCESS_ماسک dwDesiredAccess,LPSECURITY_ځانګړتیاوې lpsa);
  WINUSERAPI HDESK WINAPI CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,LPDEVMODEW pDevmode,DWORD dwFlags,ACCESS_ماسک dwDesiredAccess,LPSECURITY_ځانګړتیاوې lpsa);
#د_که_پای
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه OpenDesktop OpenDesktopW
#تعریف_کړه EnumDesktops EnumDesktopsW
#وإلا
#تعریف_کړه OpenDesktop OpenDesktopA
#تعریف_کړه EnumDesktops EnumDesktopsA
#د_که_پای

  WINUSERAPI HDESK WINAPI OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI HDESK WINAPI Open_ننوت_Desktop(DWORD dwFlags,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SwitchDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI سېټ_Thread_Desktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI CloseDesktop(HDESK hDesktop);
  WINUSERAPI HDESK WINAPI GetThreadDesktop(DWORD dwThreadId);
#د_که_پای

#که_نه_تعریف_شوی NOWINDOWSTATION
#تعریف_کړه WINSTA_ENUMDESKTOPS 0x0001L
#تعریف_کړه WINSTA_READATTRIBUTES 0x0002L
#تعریف_کړه WINSTA_ACCESSCLIPBOARD 0x0004L
#تعریف_کړه WINSTA_CREATEDESKTOP 0x0008L
#تعریف_کړه WINSTA_WRITEATTRIBUTES 0x0010L
#تعریف_کړه WINSTA_ACCESSGLOBALATOMS 0x0020L
#تعریف_کړه WINSTA_EXITWINDOWS 0x0040L
#تعریف_کړه WINSTA_ENUMERATE 0x0100L
#تعریف_کړه WINSTA_READSCREEN 0x0200L
#تعریف_کړه WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#تعریف_کړه CWF_CREATE_ONLY 0x0001L

#تعریف_کړه WSF_VISIBLE 0x0001L

#که_تعریف_شوی UNICODE
#تعریف_کړه Create_کړکۍ_Station Create_کړکۍ_Station_W
#تعریف_کړه Open_کړکۍ_Station Open_کړکۍ_Station_W
#تعریف_کړه Enum_کړکۍ_Stations Enum_کړکۍ_Stations_W
#وإلا
#تعریف_کړه Create_کړکۍ_Station Create_کړکۍ_Station_A
#تعریف_کړه Open_کړکۍ_Station Open_کړکۍ_Station_A
#تعریف_کړه Enum_کړکۍ_Stations Enum_کړکۍ_Stations_A
#د_که_پای

  WINUSERAPI HWINSTA WINAPI Create_کړکۍ_Station_A(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_ماسک dwDesiredAccess,LPSECURITY_ځانګړتیاوې lpsa);
  WINUSERAPI HWINSTA WINAPI Create_کړکۍ_Station_W(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_ماسک dwDesiredAccess,LPSECURITY_ځانګړتیاوې lpsa);
  WINUSERAPI HWINSTA WINAPI Open_کړکۍ_Station_A(LPCSTR lpszWinSta,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI HWINSTA WINAPI Open_کړکۍ_Station_W(LPCWSTR lpszWinSta,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI Enum_کړکۍ_Stations_A(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Enum_کړکۍ_Stations_W(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Close_کړکۍ_Station(HWINSTA hWinSta);
  WINUSERAPI WINBOOL WINAPI سېټ_Process_کړکۍ_Station(HWINSTA hWinSta);
  WINUSERAPI HWINSTA WINAPI Get_Process_کړکۍ_Station(VOID);
#د_که_پای

#که_نه_تعریف_شوی NOSECURITY
  WINUSERAPI WINBOOL WINAPI سېټ_User_Object_Security(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
  WINUSERAPI WINBOOL WINAPI GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD n_اوږدتیا,LPDWORD lpn_اوږدتیا_Needed);

#تعریف_کړه UOI_FLAGS 1
#تعریف_کړه UOI_NAME 2
#تعریف_کړه UOI_TYPE 3
#تعریف_کړه UOI_USER_SID 4

  تعريفنوع بنية نښان_USEROBJECTFLAGS {
    WINBOOL fInherit;
    WINBOOL fReserved;
    DWORD dwFlags;
  } USEROBJECTFLAGS,*PUSEROBJECTFLAGS;

#که_تعریف_شوی UNICODE
#تعریف_کړه GetUserObjectInformation GetUserObjectInformationW
#تعریف_کړه سېټ_User_Object_Information سېټ_User_Object_Information_W
#وإلا
#تعریف_کړه GetUserObjectInformation GetUserObjectInformationA
#تعریف_کړه سېټ_User_Object_Information سېټ_User_Object_Information_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationA(HANDLE hObj,صحيح n_شاخص,PVOID pvInfo,DWORD n_اوږدتیا,LPDWORD lpn_اوږدتیا_Needed);
  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationW(HANDLE hObj,صحيح n_شاخص,PVOID pvInfo,DWORD n_اوږدتیا,LPDWORD lpn_اوږدتیا_Needed);
  WINUSERAPI WINBOOL WINAPI سېټ_User_Object_Information_A(HANDLE hObj,صحيح n_شاخص,PVOID pvInfo,DWORD n_اوږدتیا);
  WINUSERAPI WINBOOL WINAPI سېټ_User_Object_Information_W(HANDLE hObj,صحيح n_شاخص,PVOID pvInfo,DWORD n_اوږدتیا);
#د_که_پای

  تعريفنوع بنية نښان_WNDCLASSEXA {
    UINT cb_اندازه;
    UINT style;
    WNDPROC lpfnWndProc;
    صحيح cbClsExtra;
    صحيح cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
  } WNDCLASSEXA,*PWNDCLASSEXA,*NPWNDCLASSEXA,*LPWNDCLASSEXA;

  تعريفنوع بنية نښان_WNDCLASSEXW {
    UINT cb_اندازه;
    UINT style;
    WNDPROC lpfnWndProc;
    صحيح cbClsExtra;
    صحيح cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;

    HICON hIconSm;
  } WNDCLASSEXW,*PWNDCLASSEXW,*NPWNDCLASSEXW,*LPWNDCLASSEXW;

#که_تعریف_شوی UNICODE
  تعريفنوع WNDCLASSEXW WNDCLASSEX;
  تعريفنوع PWNDCLASSEXW PWNDCLASSEX;
  تعريفنوع NPWNDCLASSEXW NPWNDCLASSEX;
  تعريفنوع LPWNDCLASSEXW LPWNDCLASSEX;
#وإلا
  تعريفنوع WNDCLASSEXA WNDCLASSEX;
  تعريفنوع PWNDCLASSEXA PWNDCLASSEX;
  تعريفنوع NPWNDCLASSEXA NPWNDCLASSEX;
  تعريفنوع LPWNDCLASSEXA LPWNDCLASSEX;
#د_که_پای

  تعريفنوع بنية نښان_WNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    صحيح cbClsExtra;
    صحيح cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
  } WNDCLASSA,*PWNDCLASSA,*NPWNDCLASSA,*LPWNDCLASSA;

  تعريفنوع بنية نښان_WNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    صحيح cbClsExtra;
    صحيح cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
  } WNDCLASSW,*PWNDCLASSW,*NPWNDCLASSW,*LPWNDCLASSW;

#که_تعریف_شوی UNICODE
  تعريفنوع WNDCLASSW WNDCLASS;
  تعريفنوع PWNDCLASSW PWNDCLASS;
  تعريفنوع NPWNDCLASSW NPWNDCLASS;
  تعريفنوع LPWNDCLASSW LPWNDCLASS;
#وإلا
  تعريفنوع WNDCLASSA WNDCLASS;
  تعريفنوع PWNDCLASSA PWNDCLASS;
  تعريفنوع NPWNDCLASSA NPWNDCLASS;
  تعريفنوع LPWNDCLASSA LPWNDCLASS;
#د_که_پای

  WINUSERAPI WINBOOL WINAPI Is_Hung_App_کړکۍ(HWND hwnd);
  WINUSERAPI VOID WINAPI DisableProcessWindowsGhosting(VOID);

#که_نه_تعریف_شوی NOMSG
  تعريفنوع بنية نښان_پیغام {
    HWND hwnd;
    UINT پیغام_2;
    WPARAM wParam;
    LPARAM lParam;
    DWORD وخت;
    ټکی_3 pt;
  } پیغام_3,*PMSG,*NPMSG,*LPMSG;

#تعریف_کړه POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#تعریف_کړه POINTTOPOINTS(pt) (MAKELONG((لنډ)((pt).x),(لنډ)((pt).y)))
#تعریف_کړه MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#تعریف_کړه MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#تعریف_کړه MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))
#د_که_پای

#که_نه_تعریف_شوی NOWINOFFSETS
#تعریف_کړه GWL_WNDPROC (-4)
#تعریف_کړه GWL_HINSTANCE (-6)
#تعریف_کړه GWL_HWNDPARENT (-8)
#تعریف_کړه GWL_STYLE (-16)
#تعریف_کړه GWL_EXSTYLE (-20)
#تعریف_کړه GWL_USERDATA (-21)
#تعریف_کړه GWL_ID (-12)

#که_تعریف_شوی _WIN64
#تعریف_لغوه GWL_WNDPROC
#تعریف_لغوه GWL_HINSTANCE
#تعریف_لغوه GWL_HWNDPARENT
#تعریف_لغوه GWL_USERDATA
#د_که_پای

#تعریف_کړه GWLP_WNDPROC (-4)
#تعریف_کړه GWLP_HINSTANCE (-6)
#تعریف_کړه GWLP_HWNDPARENT (-8)
#تعریف_کړه GWLP_USERDATA (-21)
#تعریف_کړه GWLP_ID (-12)

#تعریف_کړه GCL_MENUNAME (-8)
#تعریف_کړه GCL_HBRBACKGROUND (-10)
#تعریف_کړه GCL_HCURSOR (-12)
#تعریف_کړه GCL_HICON (-14)
#تعریف_کړه GCL_HMODULE (-16)
#تعریف_کړه GCL_CBWNDEXTRA (-18)
#تعریف_کړه GCL_CBCLSEXTRA (-20)
#تعریف_کړه GCL_WNDPROC (-24)
#تعریف_کړه GCL_STYLE (-26)
#تعریف_کړه GCW_ATOM (-32)
#تعریف_کړه GCL_HICONSM (-34)

#که_تعریف_شوی _WIN64

#تعریف_لغوه GCL_MENUNAME
#تعریف_لغوه GCL_HBRBACKGROUND
#تعریف_لغوه GCL_HCURSOR
#تعریف_لغوه GCL_HICON
#تعریف_لغوه GCL_HMODULE
#تعریف_لغوه GCL_WNDPROC
#تعریف_لغوه GCL_HICONSM
#د_که_پای

#تعریف_کړه GCLP_MENUNAME (-8)
#تعریف_کړه GCLP_HBRBACKGROUND (-10)
#تعریف_کړه GCLP_HCURSOR (-12)
#تعریف_کړه GCLP_HICON (-14)
#تعریف_کړه GCLP_HMODULE (-16)
#تعریف_کړه GCLP_WNDPROC (-24)
#تعریف_کړه GCLP_HICONSM (-34)
#د_که_پای

#که_نه_تعریف_شوی NOWINMESSAGES

#تعریف_کړه WM_NULL 0x0000
#تعریف_کړه WM_CREATE 0x0001
#تعریف_کړه WM_DESTROY 0x0002
#تعریف_کړه WM_MOVE 0x0003
#تعریف_کړه WM_اندازه 0x0005

#تعریف_کړه WM_ACTIVATE 0x0006

#تعریف_کړه WA_INACTIVE 0
#تعریف_کړه WA_فعال 1
#تعریف_کړه WA_CLICKACTIVE 2

#تعریف_کړه WM_SETFOCUS 0x0007
#تعریف_کړه WM_KILLFOCUS 0x0008
#تعریف_کړه WM_ENABLE 0x000A
#تعریف_کړه WM_SETREDRAW 0x000B
#تعریف_کړه WM_SETTEXT 0x000C
#تعریف_کړه WM_GETTEXT 0x000D
#تعریف_کړه WM_GETTEXTLENGTH 0x000E
#تعریف_کړه WM_PAINT 0x000F
#تعریف_کړه WM_CLOSE 0x0010
#که_نه_تعریف_شوی _WIN32_WCE
#تعریف_کړه WM_QUERYENDSESSION 0x0011
#تعریف_کړه WM_QUERYOPEN 0x0013
#تعریف_کړه WM_ENDSESSION 0x0016
#د_که_پای
#تعریف_کړه WM_QUIT 0x0012
#تعریف_کړه WM_ERASEBKGND 0x0014
#تعریف_کړه WM_SYSCOLORCHANGE 0x0015
#تعریف_کړه WM_SHOWWINDOW 0x0018
#تعریف_کړه WM_WININICHANGE 0x001A
#تعریف_کړه WM_SETTINGCHANGE WM_WININICHANGE
#تعریف_کړه WM_DEVMODECHANGE 0x001B
#تعریف_کړه WM_ACTIVATEAPP 0x001C
#تعریف_کړه WM_FONTCHANGE 0x001D
#تعریف_کړه WM_TIMECHANGE 0x001E
#تعریف_کړه WM_CANCELMODE 0x001F
#تعریف_کړه WM_SETCURSOR 0x0020
#تعریف_کړه WM_MOUSEACTIVATE 0x0021
#تعریف_کړه WM_CHILDACTIVATE 0x0022
#تعریف_کړه WM_QUEUESYNC 0x0023

#تعریف_کړه WM_GETMINMAXINFO 0x0024

  تعريفنوع بنية نښان_MINMAXINFO {
    ټکی_3 ptReserved;
    ټکی_3 pt_Max_اندازه;
    ټکی_3 ptMaxPosition;
    ټکی_3 pt_Min_Track_اندازه;
    ټکی_3 pt_Max_Track_اندازه;
  } MINMAXINFO,*PMINMAXINFO,*LPMINMAXINFO;

#تعریف_کړه WM_PAINTICON 0x0026
#تعریف_کړه WM_ICONERASEBKGND 0x0027
#تعریف_کړه WM_NEXTDLGCTL 0x0028
#تعریف_کړه WM_SPOOLERSTATUS 0x002A
#تعریف_کړه WM_DRAWITEM 0x002B
#تعریف_کړه WM_MEASUREITEM 0x002C
#تعریف_کړه WM_DELETEITEM 0x002D
#تعریف_کړه WM_VKEYTOITEM 0x002E
#تعریف_کړه WM_CHARTOITEM 0x002F
#تعریف_کړه WM_SETFONT 0x0030
#تعریف_کړه WM_GETFONT 0x0031
#تعریف_کړه WM_SETHOTKEY 0x0032
#تعریف_کړه WM_GETHOTKEY 0x0033
#تعریف_کړه WM_QUERYDRAGICON 0x0037
#تعریف_کړه WM_COMPAREITEM 0x0039
#که_نه_تعریف_شوی _WIN32_WCE
#تعریف_کړه WM_GETOBJECT 0x003D
#د_که_پای
#تعریف_کړه WM_COMPACTING 0x0041
#تعریف_کړه WM_COMMNOTIFY 0x0044
#تعریف_کړه WM_WINDOWPOSCHANGING 0x0046
#تعریف_کړه WM_WINDOWPOSCHANGED 0x0047

#تعریف_کړه WM_POWER 0x0048

#تعریف_کړه PWR_OK 1
#تعریف_کړه PWR_FAIL (-1)
#تعریف_کړه PWR_SUSPENDREQUEST 1
#تعریف_کړه PWR_SUSPENDRESUME 2
#تعریف_کړه PWR_CRITICALRESUME 3

#تعریف_کړه WM_COPYDATA 0x004A
#تعریف_کړه WM_CANCELJOURNAL 0x004B

  تعريفنوع بنية نښان_COPYDATASTRUCT {
    ULONG_PTR dw_معلومات;
    DWORD cb_معلومات;
    PVOID lp_معلومات;
  } COPYDATASTRUCT,*PCOPYDATASTRUCT;

  تعريفنوع بنية نښان_MDINEXTMENU {
    HMENU hmenu_دننه;
    HMENU hmenu_بل;
    HWND hwnd_بل;
  } MDINEXTMENU,*PMDINEXTMENU,*LPMDINEXTMENU;

#تعریف_کړه WM_NOTIFY 0x004E
#تعریف_کړه WM_INPUTLANGCHANGEREQUEST 0x0050
#تعریف_کړه WM_INPUTLANGCHANGE 0x0051
#تعریف_کړه WM_TCARD 0x0052
#تعریف_کړه WM_HELP 0x0053
#تعریف_کړه WM_USERCHANGED 0x0054
#تعریف_کړه WM_NOTIFYFORMAT 0x0055

#تعریف_کړه NFR_ANSI 1
#تعریف_کړه NFR_UNICODE 2
#تعریف_کړه NF_QUERY 3
#تعریف_کړه NF_REQUERY 4

#تعریف_کړه WM_CONTEXTMENU 0x007B
#تعریف_کړه WM_STYLECHANGING 0x007C
#تعریف_کړه WM_STYLECHANGED 0x007D
#تعریف_کړه WM_DISPLAYCHANGE 0x007E
#تعریف_کړه WM_GETICON 0x007F
#تعریف_کړه WM_SETICON 0x0080

#تعریف_کړه WM_NCCREATE 0x0081
#تعریف_کړه WM_NCDESTROY 0x0082
#تعریف_کړه WM_NCCALCSIZE 0x0083
#تعریف_کړه WM_NCHITTEST 0x0084
#تعریف_کړه WM_NCPAINT 0x0085
#تعریف_کړه WM_NCACTIVATE 0x0086
#تعریف_کړه WM_GETDLGCODE 0x0087
#که_نه_تعریف_شوی _WIN32_WCE
#تعریف_کړه WM_SYNCPAINT 0x0088
#د_که_پای
#تعریف_کړه WM_NCMOUSEMOVE 0x00A0
#تعریف_کړه WM_NCLBUTTONDOWN 0x00A1
#تعریف_کړه WM_NCLBUTTONUP 0x00A2
#تعریف_کړه WM_NCLBUTTONDBLCLK 0x00A3
#تعریف_کړه WM_NCRBUTTONDOWN 0x00A4
#تعریف_کړه WM_NCRBUTTONUP 0x00A5
#تعریف_کړه WM_NCRBUTTONDBLCLK 0x00A6
#تعریف_کړه WM_NCMBUTTONDOWN 0x00A7
#تعریف_کړه WM_NCMBUTTONUP 0x00A8
#تعریف_کړه WM_NCMBUTTONDBLCLK 0x00A9

#تعریف_کړه WM_NCXBUTTONDOWN 0x00AB
#تعریف_کړه WM_NCXBUTTONUP 0x00AC
#تعریف_کړه WM_NCXBUTTONDBLCLK 0x00AD
#تعریف_کړه WM_ننوت 0x00FF
#تعریف_کړه WM_KEYFIRST 0x0100
#تعریف_کړه WM_KEYDOWN 0x0100
#تعریف_کړه WM_KEYUP 0x0101
#تعریف_کړه WM_CHAR 0x0102
#تعریف_کړه WM_DEADCHAR 0x0103
#تعریف_کړه WM_SYSKEYDOWN 0x0104
#تعریف_کړه WM_SYSKEYUP 0x0105
#تعریف_کړه WM_SYSCHAR 0x0106
#تعریف_کړه WM_SYSDEADCHAR 0x0107
#تعریف_کړه WM_UNICHAR 0x0109
#تعریف_کړه WM_KEYLAST 0x0109
#تعریف_کړه UNICODE_NOCHAR 0xFFFF
#تعریف_کړه WM_IME_STARTCOMPOSITION 0x010D
#تعریف_کړه WM_IME_ENDCOMPOSITION 0x010E
#تعریف_کړه WM_IME_COMPOSITION 0x010F
#تعریف_کړه WM_IME_KEYLAST 0x010F
#تعریف_کړه WM_INITDIALOG 0x0110
#تعریف_کړه WM_COMMAND 0x0111
#تعریف_کړه WM_SYSCOMMAND 0x0112
#تعریف_کړه WM_TIMER 0x0113
#تعریف_کړه WM_HSCROLL 0x0114
#تعریف_کړه WM_VSCROLL 0x0115
#تعریف_کړه WM_INITMENU 0x0116
#تعریف_کړه WM_INITMENUPOPUP 0x0117
#تعریف_کړه WM_MENUSELECT 0x011F
#تعریف_کړه WM_MENUCHAR 0x0120
#تعریف_کړه WM_ENTERIDLE 0x0121
#که_نه_تعریف_شوی _WIN32_WCE
#تعریف_کړه WM_MENURBUTTONUP 0x0122
#تعریف_کړه WM_MENUDRAG 0x0123
#تعریف_کړه WM_MENUGETOBJECT 0x0124
#تعریف_کړه WM_UNINITMENUPOPUP 0x0125
#تعریف_کړه WM_MENUCOMMAND 0x0126

#که_نه_تعریف_شوی _WIN32_WCE
#تعریف_کړه WM_CHANGEUISTATE 0x0127
#تعریف_کړه WM_UPDATEUISTATE 0x0128
#تعریف_کړه WM_QUERYUISTATE 0x0129

#تعریف_کړه UIS_سېټ 1
#تعریف_کړه UIS_CLEAR 2
#تعریف_کړه UIS_INITIALIZE 3

#تعریف_کړه UISF_HIDEFOCUS 0x1
#تعریف_کړه UISF_HIDEACCEL 0x2
#تعریف_کړه UISF_فعال 0x4
#د_که_پای
#د_که_پای

#تعریف_کړه WM_CTLCOLORMSGBOX 0x0132
#تعریف_کړه WM_CTLCOLOREDIT 0x0133
#تعریف_کړه WM_CTLCOLORLISTBOX 0x0134
#تعریف_کړه WM_CTLCOLORBTN 0x0135
#تعریف_کړه WM_CTLCOLORDLG 0x0136
#تعریف_کړه WM_CTLCOLORSCROLLBAR 0x0137
#تعریف_کړه WM_CTLCOLORSTATIC 0x0138
#تعریف_کړه MN_GETHMENU 0x01E1

#تعریف_کړه WM_MOUSEFIRST 0x0200
#تعریف_کړه WM_MOUSEMOVE 0x0200
#تعریف_کړه WM_LBUTTONDOWN 0x0201
#تعریف_کړه WM_LBUTTONUP 0x0202
#تعریف_کړه WM_LBUTTONDBLCLK 0x0203
#تعریف_کړه WM_RBUTTONDOWN 0x0204
#تعریف_کړه WM_RBUTTONUP 0x0205
#تعریف_کړه WM_RBUTTONDBLCLK 0x0206
#تعریف_کړه WM_MBUTTONDOWN 0x0207
#تعریف_کړه WM_MBUTTONUP 0x0208
#تعریف_کړه WM_MBUTTONDBLCLK 0x0209
#تعریف_کړه WM_MOUSEWHEEL 0x020A
#تعریف_کړه WM_XBUTTONDOWN 0x020B
#تعریف_کړه WM_XBUTTONUP 0x020C
#تعریف_کړه WM_XBUTTONDBLCLK 0x020D
#تعریف_کړه WM_MOUSEHWHEEL 0x020E
#تعریف_کړه WM_MOUSELAST 0x020E

#تعریف_کړه WHEEL_DELTA 120
#تعریف_کړه GET_WHEEL_DELTA_WPARAM(wParam) ((لنډ)HIWORD(wParam))

#تعریف_کړه WHEEL_PAGESCROLL (UINT_MAX)

#تعریف_کړه GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#تعریف_کړه GET_NCHITTEST_WPARAM(wParam) ((لنډ)LOWORD(wParam))
#تعریف_کړه GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#تعریف_کړه XBUTTON1 0x0001
#تعریف_کړه XBUTTON2 0x0002

#تعریف_کړه WM_PARENTNOTIFY 0x0210
#تعریف_کړه WM_ENTERMENULOOP 0x0211
#تعریف_کړه WM_EXITMENULOOP 0x0212

#تعریف_کړه WM_NEXTMENU 0x0213
#تعریف_کړه WM_SIZING 0x0214
#تعریف_کړه WM_CAPTURECHANGED 0x0215
#تعریف_کړه WM_MOVING 0x0216

#تعریف_کړه WM_POWERBROADCAST 0x0218

#که_نه_تعریف_شوی _WIN32_WCE
#تعریف_کړه PBT_APMQUERYSUSPEND 0x0000
#تعریف_کړه PBT_APMQUERYSTANDBY 0x0001

#تعریف_کړه PBT_APMQUERYSUSPENDFAILED 0x0002
#تعریف_کړه PBT_APMQUERYSTANDBYFAILED 0x0003

#تعریف_کړه PBT_APMSUSPEND 0x0004
#تعریف_کړه PBT_APMSTANDBY 0x0005

#تعریف_کړه PBT_APMRESUMECRITICAL 0x0006
#تعریف_کړه PBT_APMRESUMESUSPEND 0x0007
#تعریف_کړه PBT_APMRESUMESTANDBY 0x0008

#تعریف_کړه PBTF_APMRESUMEFROMFAILURE 0x00000001

#تعریف_کړه PBT_APMBATTERYLOW 0x0009
#تعریف_کړه PBT_APMPOWERSTATUSCHANGE 0x000A

#تعریف_کړه PBT_APMOEMEVENT 0x000B
#تعریف_کړه PBT_APMRESUMEAUTOMATIC 0x0012
#د_که_پای

#تعریف_کړه WM_DEVICECHANGE 0x0219

#تعریف_کړه WM_MDICREATE 0x0220
#تعریف_کړه WM_MDIDESTROY 0x0221
#تعریف_کړه WM_MDIACTIVATE 0x0222
#تعریف_کړه WM_MDIRESTORE 0x0223
#تعریف_کړه WM_MDINEXT 0x0224
#تعریف_کړه WM_MDIMAXIMIZE 0x0225
#تعریف_کړه WM_MDITILE 0x0226
#تعریف_کړه WM_MDICASCADE 0x0227
#تعریف_کړه WM_MDIICONARRANGE 0x0228
#تعریف_کړه WM_MDIGETACTIVE 0x0229

#تعریف_کړه WM_MDISETMENU 0x0230
#تعریف_کړه WM_ENTERSIZEMOVE 0x0231
#تعریف_کړه WM_EXITSIZEMOVE 0x0232
#تعریف_کړه WM_DROPFILES 0x0233
#تعریف_کړه WM_MDIREFRESHMENU 0x0234

#تعریف_کړه WM_IME_SETCONTEXT 0x0281
#تعریف_کړه WM_IME_NOTIFY 0x0282
#تعریف_کړه WM_IME_CONTROL 0x0283
#تعریف_کړه WM_IME_COMPOSITIONFULL 0x0284
#تعریف_کړه WM_IME_SELECT 0x0285
#تعریف_کړه WM_IME_CHAR 0x0286
#تعریف_کړه WM_IME_REQUEST 0x0288
#تعریف_کړه WM_IME_KEYDOWN 0x0290
#تعریف_کړه WM_IME_KEYUP 0x0291

#تعریف_کړه WM_MOUSEHOVER 0x02A1
#تعریف_کړه WM_MOUSELEAVE 0x02A3
#تعریف_کړه WM_NCMOUSEHOVER 0x02A0
#تعریف_کړه WM_NCMOUSELEAVE 0x02A2
#تعریف_کړه WM_WTSSESSION_CHANGE 0x02B1
#تعریف_کړه WM_TABLET_لومړی 0x02c0
#تعریف_کړه WM_TABLET_وروستی 0x02df
#تعریف_کړه WM_CUT 0x0300
#تعریف_کړه WM_COPY 0x0301
#تعریف_کړه WM_PASTE 0x0302
#تعریف_کړه WM_CLEAR 0x0303
#تعریف_کړه WM_UNDO 0x0304
#تعریف_کړه WM_RENDERFORMAT 0x0305
#تعریف_کړه WM_RENDERALLFORMATS 0x0306
#تعریف_کړه WM_DESTROYCLIPBOARD 0x0307
#تعریف_کړه WM_DRAWCLIPBOARD 0x0308
#تعریف_کړه WM_PAINTCLIPBOARD 0x0309
#تعریف_کړه WM_VSCROLLCLIPBOARD 0x030A
#تعریف_کړه WM_SIZECLIPBOARD 0x030B
#تعریف_کړه WM_ASKCBFORMATNAME 0x030C
#تعریف_کړه WM_CHANGECBCHAIN 0x030D
#تعریف_کړه WM_HSCROLLCLIPBOARD 0x030E
#تعریف_کړه WM_QUERYNEWPALETTE 0x030F
#تعریف_کړه WM_PALETTEISCHANGING 0x0310
#تعریف_کړه WM_PALETTECHANGED 0x0311
#تعریف_کړه WM_HOTKEY 0x0312
#تعریف_کړه WM_PRINT 0x0317
#تعریف_کړه WM_PRINTCLIENT 0x0318
#تعریف_کړه WM_APPCOMMAND 0x0319
#تعریف_کړه WM_THEMECHANGED 0x031A
#تعریف_کړه WM_HANDHELDFIRST 0x0358
#تعریف_کړه WM_HANDHELDLAST 0x035F
#تعریف_کړه WM_AFXFIRST 0x0360
#تعریف_کړه WM_AFXLAST 0x037F
#تعریف_کړه WM_PENWINFIRST 0x0380
#تعریف_کړه WM_PENWINLAST 0x038F
#تعریف_کړه WM_APP 0x8000
#تعریف_کړه WM_USER 0x0400

#تعریف_کړه WMSZ_کیڼ 1
#تعریف_کړه WMSZ_ښی 2
#تعریف_کړه WMSZ_سر 3
#تعریف_کړه WMSZ_TOPLEFT 4
#تعریف_کړه WMSZ_TOPRIGHT 5
#تعریف_کړه WMSZ_BOTTOM 6
#تعریف_کړه WMSZ_BOTTOMLEFT 7
#تعریف_کړه WMSZ_BOTTOMRIGHT 8

#که_نه_تعریف_شوی NONCMESSAGES

#تعریف_کړه HTERROR (-2)
#تعریف_کړه HTTRANSPARENT (-1)
#تعریف_کړه HTNOWHERE 0
#تعریف_کړه HTCLIENT 1
#تعریف_کړه HTCAPTION 2
#تعریف_کړه HTSYSMENU 3
#تعریف_کړه HTGROWBOX 4
#تعریف_کړه HTSIZE HTGROWBOX
#تعریف_کړه HTMENU 5
#تعریف_کړه HTHSCROLL 6
#تعریف_کړه HTVSCROLL 7
#تعریف_کړه HTMINBUTTON 8
#تعریف_کړه HTMAXBUTTON 9
#تعریف_کړه HTLEFT 10
#تعریف_کړه HTRIGHT 11
#تعریف_کړه HTTOP 12
#تعریف_کړه HTTOPLEFT 13
#تعریف_کړه HTTOPRIGHT 14
#تعریف_کړه HTBOTTOM 15
#تعریف_کړه HTBOTTOMLEFT 16
#تعریف_کړه HTBOTTOMRIGHT 17
#تعریف_کړه HTBORDER 18
#تعریف_کړه HTREDUCE HTMINBUTTON
#تعریف_کړه HTZOOM HTMAXBUTTON
#تعریف_کړه HTSIZEFIRST HTLEFT
#تعریف_کړه HTSIZELAST HTBOTTOMRIGHT
#تعریف_کړه HTOBJECT 19
#تعریف_کړه HTCLOSE 20
#تعریف_کړه HTHELP 21

#تعریف_کړه SMTO_نورمال 0x0000
#تعریف_کړه SMTO_بلاک 0x0001
#تعریف_کړه SMTO_ABORTIFHUNG 0x0002
#تعریف_کړه SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#د_که_پای

#تعریف_کړه MA_ACTIVATE 1
#تعریف_کړه MA_ACTIVATEANDEAT 2
#تعریف_کړه MA_NOACTIVATE 3
#تعریف_کړه MA_NOACTIVATEANDEAT 4

#تعریف_کړه ICON_SMALL 0
#تعریف_کړه ICON_BIG 1
#تعریف_کړه ICON_SMALL2 2

#که_تعریف_شوی UNICODE
#تعریف_کړه ثبتوونکی_کړکۍ_پیغام ثبتوونکی_کړکۍ_پیغام_W
#وإلا
#تعریف_کړه ثبتوونکی_کړکۍ_پیغام ثبتوونکی_کړکۍ_پیغام_A
#د_که_پای

  WINUSERAPI UINT WINAPI ثبتوونکی_کړکۍ_پیغام_A(LPCSTR lpString);
  WINUSERAPI UINT WINAPI ثبتوونکی_کړکۍ_پیغام_W(LPCWSTR lpString);

#تعریف_کړه اندازه_RESTORED 0
#تعریف_کړه اندازه_MINIMIZED 1
#تعریف_کړه اندازه_MAXIMIZED 2
#تعریف_کړه اندازه_MAXSHOW 3
#تعریف_کړه اندازه_MAXHIDE 4

#تعریف_کړه SIZENORMAL اندازه_RESTORED
#تعریف_کړه SIZEICONIC اندازه_MINIMIZED
#تعریف_کړه SIZEFULLSCREEN اندازه_MAXIMIZED
#تعریف_کړه SIZEZOOMSHOW اندازه_MAXSHOW
#تعریف_کړه SIZEZOOMHIDE اندازه_MAXHIDE

  تعريفنوع بنية نښان_WINDOWPOS {
    HWND hwnd;
    HWND hwnd_ورننباسه_After;
    صحيح x;
    صحيح y;
    صحيح cx;
    صحيح cy;
    UINT flags;
  } WINDOWPOS,*LPWINDOWPOS,*PWINDOWPOS;

  تعريفنوع بنية نښان_NCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
  } NCCALCSIZE_PARAMS,*LPNCCALCSIZE_PARAMS;

#تعریف_کړه WVR_ALIGNTOP 0x0010
#تعریف_کړه WVR_ALIGNLEFT 0x0020
#تعریف_کړه WVR_ALIGNBOTTOM 0x0040
#تعریف_کړه WVR_ALIGNRIGHT 0x0080
#تعریف_کړه WVR_HREDRAW 0x0100
#تعریف_کړه WVR_VREDRAW 0x0200
#تعریف_کړه WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#تعریف_کړه WVR_VALIDRECTS 0x0400

#که_نه_تعریف_شوی NOKEYSTATES

#تعریف_کړه MK_LBUTTON 0x0001
#تعریف_کړه MK_RBUTTON 0x0002
#تعریف_کړه MK_ښويدنه 0x0004
#تعریف_کړه MK_CONTROL 0x0008
#تعریف_کړه MK_MBUTTON 0x0010
#تعریف_کړه MK_XBUTTON1 0x0020
#تعریف_کړه MK_XBUTTON2 0x0040
#د_که_پای

#که_نه_تعریف_شوی NOTRACKMOUSEEVENT
#تعریف_کړه TME_HOVER 0x00000001
#تعریف_کړه TME_LEAVE 0x00000002
#تعریف_کړه TME_NONCLIENT 0x00000010
#تعریف_کړه TME_QUERY 0x40000000
#تعریف_کړه TME_CANCEL 0x80000000

#تعریف_کړه HOVER_DEFAULT 0xFFFFFFFF
#د_که_پای

  تعريفنوع بنية نښان_TRACKMOUSEEVENT {
    DWORD cb_اندازه;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dw_Hover_وخت;
  } TRACKMOUSEEVENT,*LPTRACKMOUSEEVENT;

  WINUSERAPI WINBOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#د_که_پای

#که_نه_تعریف_شوی NOWINSTYLES

#تعریف_کړه WS_OVERLAPPED 0x00000000L
#تعریف_کړه WS_POPUP 0x80000000L
#تعریف_کړه WS_ماشوم 0x40000000L
#تعریف_کړه WS_MINIMIZE 0x20000000L
#تعریف_کړه WS_VISIBLE 0x10000000L
#تعریف_کړه WS_DISABLED 0x08000000L
#تعریف_کړه WS_CLIPSIBLINGS 0x04000000L
#تعریف_کړه WS_CLIPCHILDREN 0x02000000L
#تعریف_کړه WS_MAXIMIZE 0x01000000L
#تعریف_کړه WS_CAPTION 0x00C00000L
#تعریف_کړه WS_BORDER 0x00800000L
#تعریف_کړه WS_DLGFRAME 0x00400000L
#تعریف_کړه WS_VSCROLL 0x00200000L
#تعریف_کړه WS_HSCROLL 0x00100000L
#تعریف_کړه WS_SYSMENU 0x00080000L
#تعریف_کړه WS_THICKFRAME 0x00040000L
#تعریف_کړه WS_ډله 0x00020000L
#تعریف_کړه WS_TABSTOP 0x00010000L
#تعریف_کړه WS_MINIMIZEBOX 0x00020000L
#تعریف_کړه WS_MAXIMIZEBOX 0x00010000L
#تعریف_کړه WS_TILED WS_OVERLAPPED
#تعریف_کړه WS_ICONIC WS_MINIMIZE
#تعریف_کړه WS_SIZEBOX WS_THICKFRAME
#تعریف_کړه WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#تعریف_کړه WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#تعریف_کړه WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#تعریف_کړه WS_CHILDWINDOW (WS_ماشوم)

#تعریف_کړه WS_EX_DLGMODALFRAME 0x00000001L
#تعریف_کړه WS_EX_NOPARENTNOTIFY 0x00000004L
#تعریف_کړه WS_EX_TOPMOST 0x00000008L
#تعریف_کړه WS_EX_ACCEPTFILES 0x00000010L
#تعریف_کړه WS_EX_TRANSPARENT 0x00000020L
#تعریف_کړه WS_EX_MDICHILD 0x00000040L
#تعریف_کړه WS_EX_TOOLWINDOW 0x00000080L
#تعریف_کړه WS_EX_WINDOWEDGE 0x00000100L
#تعریف_کړه WS_EX_CLIENTEDGE 0x00000200L
#تعریف_کړه WS_EX_CONTEXTHELP 0x00000400L
#تعریف_کړه WS_EX_ښی 0x00001000L
#تعریف_کړه WS_EX_کیڼ 0x00000000L
#تعریف_کړه WS_EX_RTLREADING 0x00002000L
#تعریف_کړه WS_EX_LTRREADING 0x00000000L
#تعریف_کړه WS_EX_LEFTSCROLLBAR 0x00004000L
#تعریف_کړه WS_EX_RIGHTSCROLLBAR 0x00000000L
#تعریف_کړه WS_EX_CONTROLPARENT 0x00010000L
#تعریف_کړه WS_EX_STATICEDGE 0x00020000L
#تعریف_کړه WS_EX_APPWINDOW 0x00040000L
#تعریف_کړه WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#تعریف_کړه WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#تعریف_کړه WS_EX_LAYERED 0x00080000
#تعریف_کړه WS_EX_NOINHERITLAYOUT 0x00100000L
#تعریف_کړه WS_EX_LAYOUTRTL 0x00400000L
#تعریف_کړه WS_EX_COMPOSITED 0x02000000L
#تعریف_کړه WS_EX_NOACTIVATE 0x08000000L

#تعریف_کړه CS_VREDRAW 0x0001
#تعریف_کړه CS_HREDRAW 0x0002
#تعریف_کړه CS_DBLCLKS 0x0008
#تعریف_کړه CS_OWNDC 0x0020
#تعریف_کړه CS_CLASSDC 0x0040
#تعریف_کړه CS_PARENTDC 0x0080
#تعریف_کړه CS_NOCLOSE 0x0200
#تعریف_کړه CS_SAVEBITS 0x0800
#تعریف_کړه CS_BYTEALIGNCLIENT 0x1000
#تعریف_کړه CS_BYTEALIGNWINDOW 0x2000
#تعریف_کړه CS_GLOBALCLASS 0x4000
#تعریف_کړه CS_IME 0x00010000
#تعریف_کړه CS_DROPSHADOW 0x00020000
#د_که_پای

#تعریف_کړه PRF_CHECKVISIBLE 0x00000001L
#تعریف_کړه PRF_NONCLIENT 0x00000002L
#تعریف_کړه PRF_CLIENT 0x00000004L
#تعریف_کړه PRF_ERASEBKGND 0x00000008L
#تعریف_کړه PRF_CHILDREN 0x00000010L
#تعریف_کړه PRF_OWNED 0x00000020L

#تعریف_کړه BDR_RAISEDOUTER 0x0001
#تعریف_کړه BDR_SUNKENOUTER 0x0002
#تعریف_کړه BDR_RAISEDINNER 0x0004
#تعریف_کړه BDR_SUNKENINNER 0x0008

#تعریف_کړه BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#تعریف_کړه BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#تعریف_کړه BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#تعریف_کړه BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#تعریف_کړه څنډه_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#تعریف_کړه څنډه_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#تعریف_کړه څنډه_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#تعریف_کړه څنډه_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#تعریف_کړه BF_کیڼ 0x0001
#تعریف_کړه BF_سر 0x0002
#تعریف_کړه BF_ښی 0x0004
#تعریف_کړه BF_BOTTOM 0x0008

#تعریف_کړه BF_TOPLEFT (BF_سر | BF_کیڼ)
#تعریف_کړه BF_TOPRIGHT (BF_سر | BF_ښی)
#تعریف_کړه BF_BOTTOMLEFT (BF_BOTTOM | BF_کیڼ)
#تعریف_کړه BF_BOTTOMRIGHT (BF_BOTTOM | BF_ښی)
#تعریف_کړه BF_RECT (BF_کیڼ | BF_سر | BF_ښی | BF_BOTTOM)

#تعریف_کړه BF_DIAGONAL 0x0010

#تعریف_کړه BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_سر | BF_ښی)
#تعریف_کړه BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_سر | BF_کیڼ)
#تعریف_کړه BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_کیڼ)
#تعریف_کړه BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_ښی)

#تعریف_کړه BF_منځ 0x0800
#تعریف_کړه BF_SOFT 0x1000
#تعریف_کړه BF_ADJUST 0x2000
#تعریف_کړه BF_FLAT 0x4000
#تعریف_کړه BF_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_څنډه(HDC hdc,LPRECT qrc,UINT څنډه,UINT grfFlags);

#تعریف_کړه DFC_CAPTION 1
#تعریف_کړه DFC_MENU 2
#تعریف_کړه DFC_SCROLL 3
#تعریف_کړه DFC_BUTTON 4
#تعریف_کړه DFC_POPUPMENU 5

#تعریف_کړه DFCS_CAPTIONCLOSE 0x0000
#تعریف_کړه DFCS_CAPTIONMIN 0x0001
#تعریف_کړه DFCS_CAPTIONMAX 0x0002
#تعریف_کړه DFCS_CAPTIONRESTORE 0x0003
#تعریف_کړه DFCS_CAPTIONHELP 0x0004

#تعریف_کړه DFCS_MENUARROW 0x0000
#تعریف_کړه DFCS_MENUCHECK 0x0001
#تعریف_کړه DFCS_MENUBULLET 0x0002
#تعریف_کړه DFCS_MENUARROWRIGHT 0x0004
#تعریف_کړه DFCS_SCROLLUP 0x0000
#تعریف_کړه DFCS_SCROLLDOWN 0x0001
#تعریف_کړه DFCS_SCROLLLEFT 0x0002
#تعریف_کړه DFCS_SCROLLRIGHT 0x0003
#تعریف_کړه DFCS_SCROLLCOMBOBOX 0x0005
#تعریف_کړه DFCS_SCROLLSIZEGRIP 0x0008
#تعریف_کړه DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#تعریف_کړه DFCS_BUTTONCHECK 0x0000
#تعریف_کړه DFCS_BUTTONRADIOIMAGE 0x0001
#تعریف_کړه DFCS_BUTTONRADIOMASK 0x0002
#تعریف_کړه DFCS_BUTTONRADIO 0x0004
#تعریف_کړه DFCS_BUTTON3STATE 0x0008
#تعریف_کړه DFCS_BUTTONPUSH 0x0010

#تعریف_کړه DFCS_INACTIVE 0x0100
#تعریف_کړه DFCS_PUSHED 0x0200
#تعریف_کړه DFCS_CHECKED 0x0400

#تعریف_کړه DFCS_TRANSPARENT 0x0800
#تعریف_کړه DFCS_HOT 0x1000

#تعریف_کړه DFCS_ADJUSTRECT 0x2000
#تعریف_کړه DFCS_FLAT 0x4000
#تعریف_کړه DFCS_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_چوکاټ_Control(HDC,LPRECT,UINT,UINT);

#تعریف_کړه DC_فعال 0x0001
#تعریف_کړه DC_SMALLCAP 0x0002
#تعریف_کړه DC_ICON 0x0004
#تعریف_کړه DC_متن 0x0008
#تعریف_کړه DC_INBUTTON 0x0010
#تعریف_کړه DC_GRADIENT 0x0020
#تعریف_کړه DC_BUTTONS 0x1000

  WINUSERAPI WINBOOL WINAPI DrawCaption(HWND hwnd,HDC hdc,CONST RECT *lprect,UINT flags);

#تعریف_کړه IDANI_OPEN 1
#تعریف_کړه IDANI_CAPTION 3

  WINUSERAPI WINBOOL WINAPI DrawAnimatedRects(HWND hwnd,صحيح idAni,CONST RECT *lprcFrom,CONST RECT *lprc_منزل);

#که_نه_تعریف_شوی NOCLIPBOARD

#تعریف_کړه CF_متن 1
#تعریف_کړه CF_BITMAP 2
#تعریف_کړه CF_METAFILEPICT 3
#تعریف_کړه CF_SYLK 4
#تعریف_کړه CF_DIF 5
#تعریف_کړه CF_TIFF 6
#تعریف_کړه CF_OEMTEXT 7
#تعریف_کړه CF_DIB 8
#تعریف_کړه CF_PALETTE 9
#تعریف_کړه CF_PENDATA 10
#تعریف_کړه CF_RIFF 11
#تعریف_کړه CF_WAVE 12
#تعریف_کړه CF_UNICODETEXT 13
#تعریف_کړه CF_ENHMETAFILE 14
#تعریف_کړه CF_HDROP 15
#تعریف_کړه CF_LOCALE 16
#تعریف_کړه CF_DIBV5 17
#تعریف_کړه CF_MAX 18

#تعریف_کړه CF_OWNERDISPLAY 0x0080
#تعریف_کړه CF_DSPTEXT 0x0081
#تعریف_کړه CF_DSPBITMAP 0x0082
#تعریف_کړه CF_DSPMETAFILEPICT 0x0083
#تعریف_کړه CF_DSPENHMETAFILE 0x008E

#تعریف_کړه CF_PRIVATEFIRST 0x0200
#تعریف_کړه CF_PRIVATELAST 0x02FF

#تعریف_کړه CF_GDIOBJFIRST 0x0300
#تعریف_کړه CF_GDIOBJLAST 0x03FF
#د_که_پای

#تعریف_کړه FVIRTKEY TRUE
#تعریف_کړه FNOINVERT 0x02
#تعریف_کړه FSHIFT 0x04
#تعریف_کړه FCONTROL 0x08
#تعریف_کړه FALT 0x10

  تعريفنوع بنية نښان_ACCEL {
    BYTE fVirt;
    کلمه_3 کلی;
    کلمه_3 cmd;
  } ACCEL,*LPACCEL;

  تعريفنوع بنية نښان_PAINTSTRUCT {
    HDC hdc;
    WINBOOL fErase;
    RECT rcPaint;
    WINBOOL fRestore;
    WINBOOL fIncUpdate;
    BYTE rgbReserved[32];
  } PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;

  تعريفنوع بنية نښان_CREATESTRUCTA {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_پلار_2;
    صحيح cy;
    صحيح cx;
    صحيح y;
    صحيح x;
    LONG style;
    LPCSTR lpszName;
    LPCSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTA,*LPCREATESTRUCTA;

  تعريفنوع بنية نښان_CREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_پلار_2;
    صحيح cy;
    صحيح cx;
    صحيح y;
    صحيح x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTW,*LPCREATESTRUCTW;

#که_تعریف_شوی UNICODE
  تعريفنوع CREATESTRUCTW CREATESTRUCT;
  تعريفنوع LPCREATESTRUCTW LPCREATESTRUCT;
#وإلا
  تعريفنوع CREATESTRUCTA CREATESTRUCT;
  تعريفنوع LPCREATESTRUCTA LPCREATESTRUCT;
#د_که_پای

  تعريفنوع بنية نښان_WINDOWPLACEMENT {
    UINT اوږدتیا;
    UINT flags;
    UINT showCmd;
    ټکی_3 ptMinPosition;
    ټکی_3 ptMaxPosition;
    RECT rc_نورمال_Position;
  } WINDOWPLACEMENT;
  تعريفنوع WINDOWPLACEMENT *PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;

#تعریف_کړه WPF_SETMINPOSITION 0x0001
#تعریف_کړه WPF_RESTORETOMAXIMIZED 0x0002
#تعریف_کړه WPF_ASYNCWINDOWPLACEMENT 0x0004

  تعريفنوع بنية نښان_NMHDR {
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT کوډ;
  } NMHDR;

  تعريفنوع NMHDR *LPNMHDR;

  تعريفنوع بنية نښان_STYLESTRUCT {
    DWORD styleOld;
    DWORD styleNew;
  } STYLESTRUCT,*LPSTYLESTRUCT;

#تعریف_کړه ODT_MENU 1
#تعریف_کړه ODT_LISTBOX 2
#تعریف_کړه ODT_COMBOBOX 3
#تعریف_کړه ODT_BUTTON 4
#تعریف_کړه ODT_STATIC 5

#تعریف_کړه ODA_DRAWENTIRE 0x0001
#تعریف_کړه ODA_SELECT 0x0002
#تعریف_کړه ODA_FOCUS 0x0004

#تعریف_کړه ODS_SELECTED 0x0001
#تعریف_کړه ODS_GRAYED 0x0002
#تعریف_کړه ODS_DISABLED 0x0004
#تعریف_کړه ODS_CHECKED 0x0008
#تعریف_کړه ODS_FOCUS 0x0010
#تعریف_کړه ODS_DEFAULT 0x0020
#تعریف_کړه ODS_COMBOBOXEDIT 0x1000
#تعریف_کړه ODS_HOTLIGHT 0x0040
#تعریف_کړه ODS_INACTIVE 0x0080
#تعریف_کړه ODS_NOACCEL 0x0100
#تعریف_کړه ODS_NOFOCUSRECT 0x0200

  تعريفنوع بنية نښان_MEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT توکی_ID;
    UINT توکی_پلنوالی;
    UINT توکی_لوړوالی;
    ULONG_PTR توکی_معلومات;
  } MEASUREITEMSTRUCT,*PMEASUREITEMSTRUCT,*LPMEASUREITEMSTRUCT;

  تعريفنوع بنية نښان_DRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT توکی_ID;
    UINT توکی_Action;
    UINT توکی_State;
    HWND hwnd_توکی;
    HDC hDC;
    RECT rc_توکی;
    ULONG_PTR توکی_معلومات;
  } DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;

  تعريفنوع بنية نښان_DELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT توکی_ID;
    HWND hwnd_توکی;
    ULONG_PTR توکی_معلومات;
  } DELETEITEMSTRUCT,*PDELETEITEMSTRUCT,*LPDELETEITEMSTRUCT;

  تعريفنوع بنية نښان_COMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwnd_توکی;
    UINT توکی_ID1;
    ULONG_PTR توکی_Data1;
    UINT توکی_ID2;
    ULONG_PTR توکی_Data2;
    DWORD dwLocaleId;
  } COMPAREITEMSTRUCT,*PCOMPAREITEMSTRUCT,*LPCOMPAREITEMSTRUCT;

#که_نه_تعریف_شوی NOMSG
#که_تعریف_شوی UNICODE
#تعریف_کړه Get_پیغام Get_پیغام_W
#تعریف_کړه Dispatch_پیغام Dispatch_پیغام_W
#تعریف_کړه Peek_پیغام Peek_پیغام_W
#وإلا
#تعریف_کړه Get_پیغام Get_پیغام_A
#تعریف_کړه Dispatch_پیغام Dispatch_پیغام_A
#تعریف_کړه Peek_پیغام Peek_پیغام_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI Get_پیغام_A(LPMSG lp_پیغام_2,HWND hWnd,UINT w_پیغام_Filter_Min,UINT w_پیغام_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Get_پیغام_W(LPMSG lp_پیغام_2,HWND hWnd,UINT w_پیغام_Filter_Min,UINT w_پیغام_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Translate_پیغام(CONST پیغام_3 *lp_پیغام_2);
  WINUSERAPI LRESULT WINAPI Dispatch_پیغام_A(CONST پیغام_3 *lp_پیغام_2);
  WINUSERAPI LRESULT WINAPI Dispatch_پیغام_W(CONST پیغام_3 *lp_پیغام_2);
  WINUSERAPI WINBOOL WINAPI سېټ_پیغام_کتار(صحيح cMessagesMax);
  WINUSERAPI WINBOOL WINAPI Peek_پیغام_A(LPMSG lp_پیغام_2,HWND hWnd,UINT w_پیغام_Filter_Min,UINT w_پیغام_Filter_Max,UINT w_Remove_پیغام);
  WINUSERAPI WINBOOL WINAPI Peek_پیغام_W(LPMSG lp_پیغام_2,HWND hWnd,UINT w_پیغام_Filter_Min,UINT w_پیغام_Filter_Max,UINT w_Remove_پیغام);

#تعریف_کړه PM_NOREMOVE 0x0000
#تعریف_کړه PM_REMOVE 0x0001
#تعریف_کړه PM_NOYIELD 0x0002
#تعریف_کړه PM_QS_ننوت (QS_ننوت << 16)
#تعریف_کړه PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#تعریف_کړه PM_QS_PAINT (QS_PAINT << 16)
#تعریف_کړه PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)
#د_که_پای

  WINUSERAPI WINBOOL WINAPI ثبتوونکی_Hot_کلی(HWND hWnd,صحيح id,UINT fsModifiers,UINT vk);
  WINUSERAPI WINBOOL WINAPI Unregister_Hot_کلی(HWND hWnd,صحيح id);

#تعریف_کړه MOD_ALT 0x0001
#تعریف_کړه MOD_CONTROL 0x0002
#تعریف_کړه MOD_ښويدنه 0x0004
#تعریف_کړه MOD_WIN 0x0008

#تعریف_کړه IDHOT_SNAPWINDOW (-1)
#تعریف_کړه IDHOT_SNAPDESKTOP (-2)

#که_تعریف_شوی WIN_دننی
#که_نه_تعریف_شوی LSTRING
#تعریف_کړه NOLSTRING
#د_که_پای
#که_نه_تعریف_شوی LFILEIO
#تعریف_کړه NOLFILEIO
#د_که_پای
#د_که_پای

#تعریف_کړه ENDSESSION_LOGOFF 0x80000000

#تعریف_کړه EWX_LOGOFF 0
#تعریف_کړه EWX_SHUTDOWN 0x00000001
#تعریف_کړه EWX_REBOOT 0x00000002
#تعریف_کړه EWX_FORCE 0x00000004
#تعریف_کړه EWX_POWEROFF 0x00000008
#تعریف_کړه EWX_FORCEIFHUNG 0x00000010

#تعریف_کړه ExitWindows(dwReserved,کوډ_4) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#که_تعریف_شوی UNICODE
#تعریف_کړه Send_پیغام Send_پیغام_W
#تعریف_کړه Send_پیغام_Timeout Send_پیغام_Timeout_W
#تعریف_کړه Send_Notify_پیغام Send_Notify_پیغام_W
#تعریف_کړه Send_پیغام_Callback Send_پیغام_Callback_W
#وإلا
#تعریف_کړه Send_پیغام Send_پیغام_A
#تعریف_کړه Send_پیغام_Timeout Send_پیغام_Timeout_A
#تعریف_کړه Send_Notify_پیغام Send_Notify_پیغام_A
#تعریف_کړه Send_پیغام_Callback Send_پیغام_Callback_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI ExitWindowsEx(UINT uFlags,DWORD dwReason);
  WINUSERAPI WINBOOL WINAPI بدلون_Mouse_Button(WINBOOL f_بدلون);
  WINUSERAPI DWORD WINAPI Get_پیغام_Pos(VOID);
  WINUSERAPI LONG WINAPI Get_پیغام_وخت(VOID);
  WINUSERAPI LPARAM WINAPI Get_پیغام_Extra_Info(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Wow64_پیغام(VOID);
  WINUSERAPI LPARAM WINAPI سېټ_پیغام_Extra_Info(LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_پیغام_A(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_پیغام_W(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_پیغام_Timeout_A(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_پایله);
  WINUSERAPI LRESULT WINAPI Send_پیغام_Timeout_W(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_پایله);
  WINUSERAPI WINBOOL WINAPI Send_Notify_پیغام_A(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_Notify_پیغام_W(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_پیغام_Callback_A(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_پایله_Call_شا,ULONG_PTR dw_معلومات);
  WINUSERAPI WINBOOL WINAPI Send_پیغام_Callback_W(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_پایله_Call_شا,ULONG_PTR dw_معلومات);

  تعريفنوع بنية {
    UINT cb_اندازه;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
  } BSMINFO,*PBSMINFO;

#که_تعریف_شوی UNICODE
#تعریف_کړه خپرونه_System_پیغام_Ex خپرونه_System_پیغام_Ex_W
#تعریف_کړه خپرونه_System_پیغام خپرونه_System_پیغام_W
#وإلا
#تعریف_کړه خپرونه_System_پیغام_Ex خپرونه_System_پیغام_Ex_A
#تعریف_کړه خپرونه_System_پیغام خپرونه_System_پیغام_A
#د_که_پای

  WINUSERAPI اوږد WINAPI خپرونه_System_پیغام_Ex_A(DWORD flags,LPDWORD lpInfo,UINT پیغام_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI اوږد WINAPI خپرونه_System_پیغام_Ex_W(DWORD flags,LPDWORD lpInfo,UINT پیغام_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI اوږد WINAPI خپرونه_System_پیغام_A(DWORD flags,LPDWORD lpInfo,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI اوږد WINAPI خپرونه_System_پیغام_W(DWORD flags,LPDWORD lpInfo,UINT پیغام_5,WPARAM wParam,LPARAM lParam);

#تعریف_کړه BSM_ALLCOMPONENTS 0x00000000
#تعریف_کړه BSM_VXDS 0x00000001
#تعریف_کړه BSM_NETDRIVER 0x00000002
#تعریف_کړه BSM_INSTALLABLEDRIVERS 0x00000004
#تعریف_کړه BSM_APPLICATIONS 0x00000008
#تعریف_کړه BSM_ALLDESKTOPS 0x00000010

#تعریف_کړه BSF_QUERY 0x00000001
#تعریف_کړه BSF_IGNORECURRENTTASK 0x00000002
#تعریف_کړه BSF_FLUSHDISK 0x00000004
#تعریف_کړه BSF_NOHANG 0x00000008
#تعریف_کړه BSF_POSTMESSAGE 0x00000010
#تعریف_کړه BSF_FORCEIFHUNG 0x00000020
#تعریف_کړه BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#تعریف_کړه BSF_ALLOWSFW 0x00000080
#تعریف_کړه BSF_SENDNOTIFYMESSAGE 0x00000100
#تعریف_کړه BSF_RETURNHDESK 0x00000200
#تعریف_کړه BSF_LUID 0x00000400

#تعریف_کړه خپرونه_QUERY_DENY 0x424D5144

  تعريفنوع PVOID HDEVNOTIFY;
  تعريفنوع HDEVNOTIFY *PHDEVNOTIFY;

#تعریف_کړه DEVICE_NOTIFY_کړکۍ_HANDLE 0x00000000
#تعریف_کړه DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#تعریف_کړه DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#که_تعریف_شوی UNICODE
#تعریف_کړه ثبتوونکی_Device_Notification ثبتوونکی_Device_Notification_W
#تعریف_کړه Post_پیغام Post_پیغام_W
#تعریف_کړه Post_Thread_پیغام Post_Thread_پیغام_W
#تعریف_کړه Post_App_پیغام Post_App_پیغام_W
#تعریف_کړه Def_کړکۍ_Proc Def_کړکۍ_Proc_W
#تعریف_کړه Call_کړکۍ_Proc Call_کړکۍ_Proc_W
#تعریف_کړه ثبتوونکی_Class ثبتوونکی_Class_W
#تعریف_کړه UnregisterClass UnregisterClassW
#تعریف_کړه GetClassInfo GetClassInfoW
#تعریف_کړه ثبتوونکی_Class_Ex ثبتوونکی_Class_Ex_W
#تعریف_کړه GetClassInfoEx GetClassInfoExW
#وإلا
#تعریف_کړه ثبتوونکی_Device_Notification ثبتوونکی_Device_Notification_A
#تعریف_کړه Post_پیغام Post_پیغام_A
#تعریف_کړه Post_Thread_پیغام Post_Thread_پیغام_A
#تعریف_کړه Post_App_پیغام Post_App_پیغام_A
#تعریف_کړه Def_کړکۍ_Proc Def_کړکۍ_Proc_A
#تعریف_کړه Call_کړکۍ_Proc Call_کړکۍ_Proc_A
#تعریف_کړه ثبتوونکی_Class ثبتوونکی_Class_A
#تعریف_کړه UnregisterClass UnregisterClassA
#تعریف_کړه GetClassInfo GetClassInfoA
#تعریف_کړه ثبتوونکی_Class_Ex ثبتوونکی_Class_Ex_A
#تعریف_کړه GetClassInfoEx GetClassInfoExA
#د_که_پای

  WINUSERAPI HDEVNOTIFY WINAPI ثبتوونکی_Device_Notification_A(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI HDEVNOTIFY WINAPI ثبتوونکی_Device_Notification_W(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI WINBOOL WINAPI UnregisterDeviceNotification(HDEVNOTIFY Handle);
  WINUSERAPI WINBOOL WINAPI Post_پیغام_A(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_پیغام_W(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_پیغام_A(DWORD idThread,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_پیغام_W(DWORD idThread,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
#تعریف_کړه Post_App_پیغام_A(idThread,w_پیغام,wParam,lParam) Post_Thread_پیغام_A((DWORD)idThread,w_پیغام,wParam,lParam)
#تعریف_کړه Post_App_پیغام_W(idThread,w_پیغام,wParam,lParam) Post_Thread_پیغام_W((DWORD)idThread,w_پیغام,wParam,lParam)

#تعریف_کړه HWND_خپرونه ((HWND)0xffff)
#تعریف_کړه HWND_پیغام ((HWND)-3)

  WINUSERAPI WINBOOL WINAPI Attach_Thread_ننوت(DWORD idAttach,DWORD id_Attach_منزل,WINBOOL fAttach);
  WINUSERAPI WINBOOL WINAPI ځواب_پیغام(LRESULT l_پایله);
  WINUSERAPI WINBOOL WINAPI Wait_پیغام(VOID);
  WINUSERAPI DWORD WINAPI Wait_For_ننوت_Idle(HANDLE hProcess,DWORD dwMilliseconds);
  WINUSERAPI LRESULT WINAPI Def_کړکۍ_Proc_A(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_کړکۍ_Proc_W(HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI VOID WINAPI Post_Quit_پیغام(صحيح n_Exit_کوډ);
  WINUSERAPI LRESULT WINAPI Call_کړکۍ_Proc_A(WNDPROC lpPrevWndFunc,HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Call_کړکۍ_Proc_W(WNDPROC lpPrevWndFunc,HWND hWnd,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI دننه_Send_پیغام(VOID);
  WINUSERAPI DWORD WINAPI دننه_Send_پیغام_Ex(LPVOID lpReserved);

#تعریف_کړه ISMEX_NOSEND 0x00000000
#تعریف_کړه ISMEX_SEND 0x00000001
#تعریف_کړه ISMEX_NOTIFY 0x00000002
#تعریف_کړه ISMEX_CALLBACK 0x00000004
#تعریف_کړه ISMEX_REPLIED 0x00000008

  WINUSERAPI UINT WINAPI Get_Double_Click_وخت(VOID);
  WINUSERAPI WINBOOL WINAPI سېټ_Double_Click_وخت(UINT);
  WINUSERAPI ATOM WINAPI ثبتوونکی_Class_A(CONST WNDCLASSA *lpWndClass);
  WINUSERAPI ATOM WINAPI ثبتوونکی_Class_W(CONST WNDCLASSW *lpWndClass);
  WINUSERAPI WINBOOL WINAPI UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
  WINUSERAPI WINBOOL WINAPI GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
  WINUSERAPI ATOM WINAPI ثبتوونکی_Class_Ex_A(CONST WNDCLASSEXA *);
  WINUSERAPI ATOM WINAPI ثبتوونکی_Class_Ex_W(CONST WNDCLASSEXW *);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);

#تعریف_کړه CW_USEDEFAULT ((صحيح)0x80000000)

#تعریف_کړه HWND_DESKTOP ((HWND)0)

  تعريفنوع BOOLEAN (WINAPI *PREGISTERCLASSNAMEW)(LPCWSTR);

#که_تعریف_شوی UNICODE
#تعریف_کړه Create_کړکۍ_Ex Create_کړکۍ_Ex_W
#تعریف_کړه Create_کړکۍ Create_کړکۍ_W
#وإلا
#تعریف_کړه Create_کړکۍ_Ex Create_کړکۍ_Ex_A
#تعریف_کړه Create_کړکۍ Create_کړکۍ_A
#د_که_پای

  WINUSERAPI HWND WINAPI Create_کړکۍ_Ex_A(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lp_کړکۍ_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_پلنوالی,صحيح n_لوړوالی,HWND h_Wnd_پلار,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
  WINUSERAPI HWND WINAPI Create_کړکۍ_Ex_W(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lp_کړکۍ_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_پلنوالی,صحيح n_لوړوالی,HWND h_Wnd_پلار,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
#تعریف_کړه Create_کړکۍ_A(lpClassName,lp_کړکۍ_Name,dwStyle,x,y,n_پلنوالی,n_لوړوالی,h_Wnd_پلار,hMenu,hInstance,lpParam) Create_کړکۍ_Ex_A(0L,lpClassName,lp_کړکۍ_Name,dwStyle,x,y,n_پلنوالی,n_لوړوالی,h_Wnd_پلار,hMenu,hInstance,lpParam)
#تعریف_کړه Create_کړکۍ_W(lpClassName,lp_کړکۍ_Name,dwStyle,x,y,n_پلنوالی,n_لوړوالی,h_Wnd_پلار,hMenu,hInstance,lpParam) Create_کړکۍ_Ex_W(0L,lpClassName,lp_کړکۍ_Name,dwStyle,x,y,n_پلنوالی,n_لوړوالی,h_Wnd_پلار,hMenu,hInstance,lpParam)
  WINUSERAPI WINBOOL WINAPI Is_کړکۍ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsMenu(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI Is_ماشوم(HWND h_Wnd_پلار,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Destroy_کړکۍ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Show_کړکۍ(HWND hWnd,صحيح nCmdShow);
  WINUSERAPI WINBOOL WINAPI Animate_کړکۍ(HWND hWnd,DWORD dw_وخت,DWORD dwFlags);

#إذا defined(_WINGDI_) && !defined(NOGDI)
  WINUSERAPI WINBOOL WINAPI Update_Layered_کړکۍ(HWND hWnd,HDC hdcDst,ټکی_3 *pptDst,اندازه_2 *psize,HDC hdcSrc,ټکی_3 *pptSrc,COLORREF cr_کلی,BLENDFUNCTION *pblend,DWORD dwFlags);

  تعريفنوع بنية نښان_UPDATELAYEREDWINDOWINFO {
    DWORD cb_اندازه;
    HDC hdcDst;
    ټکی_3 CONST *pptDst;
    اندازه_2 CONST *psize;
    HDC hdcSrc;
    ټکی_3 CONST *pptSrc;
    COLORREF cr_کلی;
    BLENDFUNCTION CONST *pblend;
    DWORD dwFlags;
    RECT CONST *prcDirty;
  } UPDATELAYEREDWINDOWINFO,*PUPDATELAYEREDWINDOWINFO;

  WINUSERAPI WINBOOL WINAPI Update_Layered_کړکۍ_غیرمستقیم(HWND hWnd,UPDATELAYEREDWINDOWINFO CONST *pULWInfo);
  WINUSERAPI WINBOOL WINAPI Get_Layered_کړکۍ_ځانګړتیاوې(HWND hwnd,COLORREF *pcr_کلی,BYTE *pbAlpha,DWORD *pdwFlags);

#تعریف_کړه PW_CLIENTONLY 0x00000001

  WINUSERAPI WINBOOL WINAPI Print_کړکۍ(HWND hwnd,HDC hdcBlt,UINT nFlags);
  WINUSERAPI WINBOOL WINAPI سېټ_Layered_کړکۍ_ځانګړتیاوې(HWND hwnd,COLORREF cr_کلی,BYTE bAlpha,DWORD dwFlags);

#تعریف_کړه LWA_COLORKEY 0x00000001
#تعریف_کړه LWA_ALPHA 0x00000002

#تعریف_کړه ULW_COLORKEY 0x00000001
#تعریف_کړه ULW_ALPHA 0x00000002
#تعریف_کړه ULW_OPAQUE 0x00000004

#تعریف_کړه ULW_EX_NORESIZE 0x00000008

  WINUSERAPI WINBOOL WINAPI Show_کړکۍ_Async(HWND hWnd,صحيح nCmdShow);
  WINUSERAPI WINBOOL WINAPI Flash_کړکۍ(HWND hWnd,WINBOOL bInvert);

  تعريفنوع بنية {
    UINT cb_اندازه;
    HWND hwnd;
    DWORD dwFlags;
    UINT u_شمېر;
    DWORD dwTimeout;
  } FLASHWINFO,*PFLASHWINFO;

  WINUSERAPI WINBOOL WINAPI Flash_کړکۍ_Ex(PFLASHWINFO pfwi);

#تعریف_کړه FLASHW_STOP 0
#تعریف_کړه FLASHW_CAPTION 0x00000001
#تعریف_کړه FLASHW_TRAY 0x00000002
#تعریف_کړه FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#تعریف_کړه FLASHW_TIMER 0x00000004
#تعریف_کړه FLASHW_TIMERNOFG 0x0000000C

  WINUSERAPI WINBOOL WINAPI ShowOwnedPopups(HWND hWnd,WINBOOL fShow);
  WINUSERAPI WINBOOL WINAPI OpenIcon(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Close_کړکۍ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Move_کړکۍ(HWND hWnd,صحيح X,صحيح Y,صحيح n_پلنوالی,صحيح n_لوړوالی,WINBOOL bRepaint);
  WINUSERAPI WINBOOL WINAPI سېټ_کړکۍ_Pos(HWND hWnd,HWND h_Wnd_ورننباسه_After,صحيح X,صحيح Y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI Get_کړکۍ_Placement(HWND hWnd,WINDOWPLACEMENT *lpwndpl);
  WINUSERAPI WINBOOL WINAPI سېټ_کړکۍ_Placement(HWND hWnd,CONST WINDOWPLACEMENT *lpwndpl);

#که_نه_تعریف_شوی NODEFERWINDOWPOS
  WINUSERAPI HDWP WINAPI Begin_Defer_کړکۍ_Pos(صحيح n_عدد_Windows);
  WINUSERAPI HDWP WINAPI Defer_کړکۍ_Pos(HDWP hWinPosInfo,HWND hWnd,HWND h_Wnd_ورننباسه_After,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI پای_ټکی_Defer_کړکۍ_Pos(HDWP hWinPosInfo);
#د_که_پای

  WINUSERAPI WINBOOL WINAPI Is_کړکۍ_Visible(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsIconic(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AnyPopup(VOID);
  WINUSERAPI WINBOOL WINAPI Bring_کړکۍ_منزل_سر(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsZoomed(HWND hWnd);

#تعریف_کړه SWP_NOSIZE 0x0001
#تعریف_کړه SWP_NOMOVE 0x0002
#تعریف_کړه SWP_NOZORDER 0x0004
#تعریف_کړه SWP_NOREDRAW 0x0008
#تعریف_کړه SWP_NOACTIVATE 0x0010
#تعریف_کړه SWP_FRAMECHANGED 0x0020
#تعریف_کړه SWP_SHOWWINDOW 0x0040
#تعریف_کړه SWP_HIDEWINDOW 0x0080
#تعریف_کړه SWP_NOCOPYBITS 0x0100
#تعریف_کړه SWP_NOOWNERZORDER 0x0200
#تعریف_کړه SWP_NOSENDCHANGING 0x0400

#تعریف_کړه SWP_DRAWFRAME SWP_FRAMECHANGED
#تعریف_کړه SWP_NOREPOSITION SWP_NOOWNERZORDER
#تعریف_کړه SWP_DEFERERASE 0x2000
#تعریف_کړه SWP_ASYNCWINDOWPOS 0x4000

#تعریف_کړه HWND_سر ((HWND)0)
#تعریف_کړه HWND_BOTTOM ((HWND)1)
#تعریف_کړه HWND_TOPMOST ((HWND)-1)
#تعریف_کړه HWND_NOTOPMOST ((HWND)-2)

#که_نه_تعریف_شوی NOCTLMGR

#ضمن <pshpack2.h>

  تعريفنوع بنية {
    DWORD style;
    DWORD dwExtendedStyle;
    کلمه_3 cdit;
    لنډ x;
    لنډ y;
    لنډ cx;
    لنډ cy;
  } DLGTEMPLATE;

  تعريفنوع DLGTEMPLATE *LPDLGTEMPLATEA;
  تعريفنوع DLGTEMPLATE *LPDLGTEMPLATEW;

#که_تعریف_شوی UNICODE
  تعريفنوع LPDLGTEMPLATEW LPDLGTEMPLATE;
#وإلا
  تعريفنوع LPDLGTEMPLATEA LPDLGTEMPLATE;
#د_که_پای

  تعريفنوع CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
  تعريفنوع CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

#که_تعریف_شوی UNICODE
  تعريفنوع LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#وإلا
  تعريفنوع LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#د_که_پای

  تعريفنوع بنية {
    DWORD style;
    DWORD dwExtendedStyle;
    لنډ x;
    لنډ y;
    لنډ cx;
    لنډ cy;
    کلمه_3 id;
  } DLGITEMTEMPLATE;

  تعريفنوع DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
  تعريفنوع DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;

#که_تعریف_شوی UNICODE
  تعريفنوع PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#وإلا
  تعريفنوع PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#د_که_پای

  تعريفنوع DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
  تعريفنوع DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;

#که_تعریف_شوی UNICODE
  تعريفنوع LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#وإلا
  تعريفنوع LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#د_که_پای

#ضمن <poppack.h>

#که_تعریف_شوی UNICODE
#تعریف_کړه CreateDialogParam CreateDialogParamW
#تعریف_کړه Create_Dialog_غیرمستقیم_Param Create_Dialog_غیرمستقیم_Param_W
#تعریف_کړه CreateDialog CreateDialogW
#تعریف_کړه Create_Dialog_غیرمستقیم Create_Dialog_غیرمستقیم_W
#تعریف_کړه DialogBoxParam DialogBoxParamW
#تعریف_کړه Dialog_Box_غیرمستقیم_Param Dialog_Box_غیرمستقیم_Param_W
#تعریف_کړه DialogBox DialogBoxW
#تعریف_کړه Dialog_Box_غیرمستقیم Dialog_Box_غیرمستقیم_W
#تعریف_کړه سېټ_Dlg_توکی_متن سېټ_Dlg_توکی_متن_W
#تعریف_کړه Get_Dlg_توکی_متن Get_Dlg_توکی_متن_W
#تعریف_کړه Send_Dlg_توکی_پیغام Send_Dlg_توکی_پیغام_W
#تعریف_کړه DefDlgProc DefDlgProcW
#وإلا
#تعریف_کړه CreateDialogParam CreateDialogParamA
#تعریف_کړه Create_Dialog_غیرمستقیم_Param Create_Dialog_غیرمستقیم_Param_A
#تعریف_کړه CreateDialog CreateDialogA
#تعریف_کړه Create_Dialog_غیرمستقیم Create_Dialog_غیرمستقیم_A
#تعریف_کړه DialogBoxParam DialogBoxParamA
#تعریف_کړه Dialog_Box_غیرمستقیم_Param Dialog_Box_غیرمستقیم_Param_A
#تعریف_کړه DialogBox DialogBoxA
#تعریف_کړه Dialog_Box_غیرمستقیم Dialog_Box_غیرمستقیم_A
#تعریف_کړه سېټ_Dlg_توکی_متن سېټ_Dlg_توکی_متن_A
#تعریف_کړه Get_Dlg_توکی_متن Get_Dlg_توکی_متن_A
#تعریف_کړه Send_Dlg_توکی_پیغام Send_Dlg_توکی_پیغام_A
#تعریف_کړه DefDlgProc DefDlgProcA
#د_که_پای

  WINUSERAPI HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_پلار,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_پلار,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_غیرمستقیم_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND h_Wnd_پلار,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_غیرمستقیم_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND h_Wnd_پلار,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#تعریف_کړه CreateDialogA(hInstance,lpName,h_Wnd_پلار,lpDialogFunc) CreateDialogParamA(hInstance,lpName,h_Wnd_پلار,lpDialogFunc,0L)
#تعریف_کړه CreateDialogW(hInstance,lpName,h_Wnd_پلار,lpDialogFunc) CreateDialogParamW(hInstance,lpName,h_Wnd_پلار,lpDialogFunc,0L)
#تعریف_کړه Create_Dialog_غیرمستقیم_A(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc) Create_Dialog_غیرمستقیم_Param_A(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc,0L)
#تعریف_کړه Create_Dialog_غیرمستقیم_W(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc) Create_Dialog_غیرمستقیم_Param_W(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc,0L)
  WINUSERAPI INT_PTR WINAPI DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_پلار,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_پلار,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_غیرمستقیم_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND h_Wnd_پلار,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_غیرمستقیم_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND h_Wnd_پلار,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#تعریف_کړه DialogBoxA(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc,0L)
#تعریف_کړه DialogBoxW(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc,0L)
#تعریف_کړه Dialog_Box_غیرمستقیم_A(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc) Dialog_Box_غیرمستقیم_Param_A(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc,0L)
#تعریف_کړه Dialog_Box_غیرمستقیم_W(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc) Dialog_Box_غیرمستقیم_Param_W(hInstance,lpTemplate,h_Wnd_پلار,lpDialogFunc,0L)
  WINUSERAPI WINBOOL WINAPI پای_ټکی_Dialog(HWND hDlg,INT_PTR n_پایله);
  WINUSERAPI HWND WINAPI Get_Dlg_توکی(HWND hDlg,صحيح n_IDDlg_توکی);
  WINUSERAPI WINBOOL WINAPI سېټ_Dlg_توکی_Int(HWND hDlg,صحيح n_IDDlg_توکی,UINT u_ارزښت,WINBOOL bSigned);
  WINUSERAPI UINT WINAPI Get_Dlg_توکی_Int(HWND hDlg,صحيح n_IDDlg_توکی,WINBOOL *lpTranslated,WINBOOL bSigned);
  WINUSERAPI WINBOOL WINAPI سېټ_Dlg_توکی_متن_A(HWND hDlg,صحيح n_IDDlg_توکی,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI سېټ_Dlg_توکی_متن_W(HWND hDlg,صحيح n_IDDlg_توکی,LPCWSTR lpString);
  WINUSERAPI UINT WINAPI Get_Dlg_توکی_متن_A(HWND hDlg,صحيح n_IDDlg_توکی,LPSTR lpString,صحيح cchMax);
  WINUSERAPI UINT WINAPI Get_Dlg_توکی_متن_W(HWND hDlg,صحيح n_IDDlg_توکی,LPWSTR lpString,صحيح cchMax);
  WINUSERAPI WINBOOL WINAPI CheckDlgButton(HWND hDlg,صحيح nIDButton,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI CheckRadioButton(HWND hDlg,صحيح nIDFirstButton,صحيح nIDLastButton,صحيح nIDCheckButton);
  WINUSERAPI UINT WINAPI IsDlgButtonChecked(HWND hDlg,صحيح nIDButton);
  WINUSERAPI LRESULT WINAPI Send_Dlg_توکی_پیغام_A(HWND hDlg,صحيح n_IDDlg_توکی,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_Dlg_توکی_پیغام_W(HWND hDlg,صحيح n_IDDlg_توکی,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI HWND WINAPI Get_بل_Dlg_ډله_توکی(HWND hDlg,HWND hCtl,WINBOOL b_پخوانی);
  WINUSERAPI HWND WINAPI Get_بل_Dlg_Tab_توکی(HWND hDlg,HWND hCtl,WINBOOL b_پخوانی);
  WINUSERAPI صحيح WINAPI GetDlgCtrlID(HWND hWnd);
  WINUSERAPI اوږد WINAPI Get_Dialog_بنسټ_Units(VOID);
  WINUSERAPI LRESULT WINAPI DefDlgProcA(HWND hDlg,UINT پیغام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefDlgProcW(HWND hDlg,UINT پیغام_5,WPARAM wParam,LPARAM lParam);

#تعریف_کړه DLGWINDOWEXTRA 30
#د_که_پای

#که_نه_تعریف_شوی NOMSG

#که_تعریف_شوی UNICODE
#تعریف_کړه Call_پیغام_Filter Call_پیغام_Filter_W
#وإلا
#تعریف_کړه Call_پیغام_Filter Call_پیغام_Filter_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI Call_پیغام_Filter_A(LPMSG lp_پیغام_2,صحيح n_کوډ);
  WINUSERAPI WINBOOL WINAPI Call_پیغام_Filter_W(LPMSG lp_پیغام_2,صحيح n_کوډ);
#د_که_پای

#که_نه_تعریف_شوی NOCLIPBOARD

#که_تعریف_شوی UNICODE
#تعریف_کړه ثبتوونکی_Clipboard_Format ثبتوونکی_Clipboard_Format_W
#تعریف_کړه GetClipboardFormatName GetClipboardFormatNameW
#وإلا
#تعریف_کړه ثبتوونکی_Clipboard_Format ثبتوونکی_Clipboard_Format_A
#تعریف_کړه GetClipboardFormatName GetClipboardFormatNameA
#د_که_پای

  WINUSERAPI WINBOOL WINAPI OpenClipboard(HWND hWndNewOwner);
  WINUSERAPI WINBOOL WINAPI CloseClipboard(VOID);
  WINUSERAPI DWORD WINAPI Get_Clipboard_Sequence_شمېره(VOID);
  WINUSERAPI HWND WINAPI GetClipboardOwner(VOID);
  WINUSERAPI HWND WINAPI سېټ_Clipboard_Viewer(HWND hWndNewViewer);
  WINUSERAPI HWND WINAPI GetClipboardViewer(VOID);
  WINUSERAPI WINBOOL WINAPI ChangeClipboardChain(HWND hWndRemove,HWND h_Wnd_New_بل);
  WINUSERAPI HANDLE WINAPI سېټ_Clipboard_معلومات(UINT uFormat,HANDLE hMem);
  WINUSERAPI HANDLE WINAPI Get_Clipboard_معلومات(UINT uFormat);
  WINUSERAPI UINT WINAPI ثبتوونکی_Clipboard_Format_A(LPCSTR lpszFormat);
  WINUSERAPI UINT WINAPI ثبتوونکی_Clipboard_Format_W(LPCWSTR lpszFormat);
  WINUSERAPI صحيح WINAPI شمېر_Clipboard_Formats(VOID);
  WINUSERAPI UINT WINAPI EnumClipboardFormats(UINT format);
  WINUSERAPI صحيح WINAPI GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,صحيح cch_Max_شمېر);
  WINUSERAPI صحيح WINAPI GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,صحيح cch_Max_شمېر);
  WINUSERAPI WINBOOL WINAPI تشه_Clipboard(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Clipboard_Format_شته(UINT format);
  WINUSERAPI صحيح WINAPI Get_لومړیتوب_Clipboard_Format(UINT *pa_Format_لومړیتوب_List,صحيح cFormats);
  WINUSERAPI HWND WINAPI Get_Open_Clipboard_کړکۍ(VOID);
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه Char_منزل_Oem Char_منزل_Oem_W
#تعریف_کړه Oem_منزل_Char Oem_منزل_Char_W
#تعریف_کړه Char_منزل_Oem_Buff Char_منزل_Oem_Buff_W
#تعریف_کړه Oem_منزل_Char_Buff Oem_منزل_Char_Buff_W
#تعریف_کړه Char_پاسنی Char_پاسنی_W
#تعریف_کړه Char_پاسنی_Buff Char_پاسنی_Buff_W
#تعریف_کړه Char_ښکتنی Char_ښکتنی_W
#تعریف_کړه Char_ښکتنی_Buff Char_ښکتنی_Buff_W
#تعریف_کړه Char_بل Char_بل_W
#تعریف_کړه CharPrev CharPrevW
#وإلا
#تعریف_کړه Char_منزل_Oem Char_منزل_Oem_A
#تعریف_کړه Oem_منزل_Char Oem_منزل_Char_A
#تعریف_کړه Char_منزل_Oem_Buff Char_منزل_Oem_Buff_A
#تعریف_کړه Oem_منزل_Char_Buff Oem_منزل_Char_Buff_A
#تعریف_کړه Char_پاسنی Char_پاسنی_A
#تعریف_کړه Char_پاسنی_Buff Char_پاسنی_Buff_A
#تعریف_کړه Char_ښکتنی Char_ښکتنی_A
#تعریف_کړه Char_ښکتنی_Buff Char_ښکتنی_Buff_A
#تعریف_کړه Char_بل Char_بل_A
#تعریف_کړه CharPrev CharPrevA
#د_که_پای

  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_W(LPCWSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_W(LPCSTR lpszSrc,LPWSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_اوږدتیا);
  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_Buff_W(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_اوږدتیا);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_اوږدتیا);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_Buff_W(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cch_Dst_اوږدتیا);
  WINUSERAPI LPSTR WINAPI Char_پاسنی_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_پاسنی_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_پاسنی_Buff_A(LPSTR lpsz,DWORD cch_اوږدتیا);
  WINUSERAPI DWORD WINAPI Char_پاسنی_Buff_W(LPWSTR lpsz,DWORD cch_اوږدتیا);
  WINUSERAPI LPSTR WINAPI Char_ښکتنی_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ښکتنی_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_ښکتنی_Buff_A(LPSTR lpsz,DWORD cch_اوږدتیا);
  WINUSERAPI DWORD WINAPI Char_ښکتنی_Buff_W(LPWSTR lpsz,DWORD cch_اوږدتیا);
  WINUSERAPI LPSTR WINAPI Char_بل_A(LPCSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_بل_W(LPCWSTR lpsz);
  WINUSERAPI LPSTR WINAPI CharPrevA(LPCSTR lpsz_پیل,LPCSTR lpszCurrent);
  WINUSERAPI LPWSTR WINAPI CharPrevW(LPCWSTR lpsz_پیل,LPCWSTR lpszCurrent);
  WINUSERAPI LPSTR WINAPI Char_بل_Ex_A(کلمه_3 کوډ_پاڼه,LPCSTR lpCurrentChar,DWORD dwFlags);
  WINUSERAPI LPSTR WINAPI CharPrevExA(کلمه_3 کوډ_پاڼه,LPCSTR lp_پیل,LPCSTR lpCurrentChar,DWORD dwFlags);

#تعریف_کړه Ansi_منزل_Oem Char_منزل_Oem_A
#تعریف_کړه Oem_منزل_Ansi Oem_منزل_Char_A
#تعریف_کړه Ansi_منزل_Oem_Buff Char_منزل_Oem_Buff_A
#تعریف_کړه Oem_منزل_Ansi_Buff Oem_منزل_Char_Buff_A
#تعریف_کړه Ansi_پاسنی Char_پاسنی_A
#تعریف_کړه Ansi_پاسنی_Buff Char_پاسنی_Buff_A
#تعریف_کړه Ansi_ښکتنی Char_ښکتنی_A
#تعریف_کړه Ansi_ښکتنی_Buff Char_ښکتنی_Buff_A
#تعریف_کړه Ansi_بل Char_بل_A
#تعریف_کړه AnsiPrev CharPrevA

#که_نه_تعریف_شوی NOLANGUAGE

#که_تعریف_شوی UNICODE
#تعریف_کړه IsCharAlpha IsCharAlphaW
#تعریف_کړه IsCharAlphaNumeric IsCharAlphaNumericW
#تعریف_کړه Is_Char_پاسنی Is_Char_پاسنی_W
#تعریف_کړه Is_Char_ښکتنی Is_Char_ښکتنی_W
#وإلا
#تعریف_کړه IsCharAlpha IsCharAlphaA
#تعریف_کړه IsCharAlphaNumeric IsCharAlphaNumericA
#تعریف_کړه Is_Char_پاسنی Is_Char_پاسنی_A
#تعریف_کړه Is_Char_ښکتنی Is_Char_ښکتنی_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI IsCharAlphaA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_پاسنی_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_پاسنی_W(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ښکتنی_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ښکتنی_W(WCHAR ch);
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_کلی_Name_متن Get_کلی_Name_متن_W
#تعریف_کړه Vk_کلی_لټون Vk_کلی_لټون_W
#تعریف_کړه Vk_کلی_لټون_Ex Vk_کلی_لټون_Ex_W
#وإلا
#تعریف_کړه Get_کلی_Name_متن Get_کلی_Name_متن_A
#تعریف_کړه Vk_کلی_لټون Vk_کلی_لټون_A
#تعریف_کړه Vk_کلی_لټون_Ex Vk_کلی_لټون_Ex_A
#د_که_پای

  WINUSERAPI HWND WINAPI سېټ_Focus(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_فعال_کړکۍ(VOID);
  WINUSERAPI HWND WINAPI GetFocus(VOID);
  WINUSERAPI UINT WINAPI Get_KBCode_پاڼه(VOID);
  WINUSERAPI SHORT WINAPI Get_کلی_State(صحيح n_Virt_کلی);
  WINUSERAPI SHORT WINAPI Get_Async_کلی_State(صحيح v_کلی);
  WINUSERAPI WINBOOL WINAPI GetKeyboardState(PBYTE lp_کلی_State);
  WINUSERAPI WINBOOL WINAPI سېټ_Keyboard_State(LPBYTE lp_کلی_State);
  WINUSERAPI صحيح WINAPI Get_کلی_Name_متن_A(LONG lParam,LPSTR lpString,صحيح cch_اندازه);
  WINUSERAPI صحيح WINAPI Get_کلی_Name_متن_W(LONG lParam,LPWSTR lpString,صحيح cch_اندازه);
  WINUSERAPI صحيح WINAPI GetKeyboardType(صحيح nTypeFlag);
  WINUSERAPI صحيح WINAPI منزل_Ascii(UINT u_Virt_کلی,UINT u_لټون_کوډ,CONST BYTE *lp_کلی_State,LPWORD lpChar,UINT uFlags);
  WINUSERAPI صحيح WINAPI منزل_Ascii_Ex(UINT u_Virt_کلی,UINT u_لټون_کوډ,CONST BYTE *lp_کلی_State,LPWORD lpChar,UINT uFlags,HKL dwhkl);
  WINUSERAPI صحيح WINAPI منزل_Unicode(UINT w_Virt_کلی,UINT w_لټون_کوډ,CONST BYTE *lp_کلی_State,LPWSTR pwszBuff,صحيح cchBuff,UINT wFlags);
  WINUSERAPI DWORD WINAPI Oem_کلی_لټون(کلمه_3 wOemChar);
  WINUSERAPI SHORT WINAPI Vk_کلی_لټون_A(CHAR ch);
  WINUSERAPI SHORT WINAPI Vk_کلی_لټون_W(WCHAR ch);
  WINUSERAPI SHORT WINAPI Vk_کلی_لټون_Ex_A(CHAR ch,HKL dwhkl);
  WINUSERAPI SHORT WINAPI Vk_کلی_لټون_Ex_W(WCHAR ch,HKL dwhkl);

#تعریف_کړه KEYEVENTF_EXTENDEDKEY 0x0001
#تعریف_کړه KEYEVENTF_KEYUP 0x0002
#تعریف_کړه KEYEVENTF_UNICODE 0x0004
#تعریف_کړه KEYEVENTF_SCANCODE 0x0008

  WINUSERAPI VOID WINAPI keybd_event(BYTE bVk,BYTE b_لټون,DWORD dwFlags,ULONG_PTR dwExtraInfo);

#تعریف_کړه MOUSEEVENTF_MOVE 0x0001
#تعریف_کړه MOUSEEVENTF_LEFTDOWN 0x0002
#تعریف_کړه MOUSEEVENTF_LEFTUP 0x0004
#تعریف_کړه MOUSEEVENTF_RIGHTDOWN 0x0008
#تعریف_کړه MOUSEEVENTF_RIGHTUP 0x0010
#تعریف_کړه MOUSEEVENTF_MIDDLEDOWN 0x0020
#تعریف_کړه MOUSEEVENTF_MIDDLEUP 0x0040
#تعریف_کړه MOUSEEVENTF_XDOWN 0x0080
#تعریف_کړه MOUSEEVENTF_XUP 0x0100
#تعریف_کړه MOUSEEVENTF_WHEEL 0x0800
#تعریف_کړه MOUSEEVENTF_VIRTUALDESK 0x4000
#تعریف_کړه MOUSEEVENTF_ABSOLUTE 0x8000

  WINUSERAPI VOID WINAPI mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dw_معلومات,ULONG_PTR dwExtraInfo);

  تعريفنوع بنية نښان_MOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouse_معلومات;
    DWORD dwFlags;
    DWORD وخت;
    ULONG_PTR dwExtraInfo;
  } MOUSEINPUT,*PMOUSEINPUT,*LPMOUSEINPUT;

  تعريفنوع بنية نښان_KEYBDINPUT {
    کلمه_3 wVk;
    کلمه_3 w_لټون;
    DWORD dwFlags;
    DWORD وخت;
    ULONG_PTR dwExtraInfo;
  } KEYBDINPUT,*PKEYBDINPUT,*LPKEYBDINPUT;

  تعريفنوع بنية نښان_HARDWAREINPUT {
    DWORD u_پیغام;
    کلمه_3 wParamL;
    کلمه_3 wParamH;
  } HARDWAREINPUT,*PHARDWAREINPUT,*LPHARDWAREINPUT;

#تعریف_کړه ننوت_MOUSE 0
#تعریف_کړه ننوت_KEYBOARD 1
#تعریف_کړه ننوت_HARDWARE 2

  تعريفنوع بنية نښان_ننوت {
    DWORD type;
    اتحاد {
      MOUSEINPUT mi;
      KEYBDINPUT ki;
      HARDWAREINPUT hi;
    };
  } ننوت_2,*PINPUT,*LPINPUT;

  WINUSERAPI UINT WINAPI Send_ننوت(UINT cInputs,LPINPUT pInputs,صحيح cb_اندازه);

  تعريفنوع بنية نښان_LASTINPUTINFO {
    UINT cb_اندازه;
    DWORD dw_وخت;
  } LASTINPUTINFO,*PLASTINPUTINFO;

#که_تعریف_شوی UNICODE
#تعریف_کړه Map_Virtual_کلی Map_Virtual_کلی_W
#تعریف_کړه Map_Virtual_کلی_Ex Map_Virtual_کلی_Ex_W
#وإلا
#تعریف_کړه Map_Virtual_کلی Map_Virtual_کلی_A
#تعریف_کړه Map_Virtual_کلی_Ex Map_Virtual_کلی_Ex_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI Get_وروستی_ننوت_Info(PLASTINPUTINFO plii);
  WINUSERAPI UINT WINAPI Map_Virtual_کلی_A(UINT u_کوډ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_کلی_W(UINT u_کوډ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_کلی_Ex_A(UINT u_کوډ,UINT uMapType,HKL dwhkl);
  WINUSERAPI UINT WINAPI Map_Virtual_کلی_Ex_W(UINT u_کوډ,UINT uMapType,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI Get_ننوت_State(VOID);
  WINUSERAPI DWORD WINAPI Get_کتار_حالت(UINT flags);
  WINUSERAPI HWND WINAPI GetCapture(VOID);
  WINUSERAPI HWND WINAPI سېټ_Capture(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ReleaseCapture(VOID);
  WINUSERAPI DWORD WINAPI پیغام_Wait_For_مضرب_Objects(DWORD n_شمېر,CONST HANDLE *pHandles,WINBOOL fWaitAll,DWORD dwMilliseconds,DWORD dw_Wake_ماسک);
  WINUSERAPI DWORD WINAPI پیغام_Wait_For_مضرب_Objects_Ex(DWORD n_شمېر,CONST HANDLE *pHandles,DWORD dwMilliseconds,DWORD dw_Wake_ماسک,DWORD dwFlags);

#تعریف_کړه MWMO_WAITALL 0x0001
#تعریف_کړه MWMO_ALERTABLE 0x0002
#تعریف_کړه MWMO_INPUTAVAILABLE 0x0004

#تعریف_کړه QS_کلی 0x0001
#تعریف_کړه QS_MOUSEMOVE 0x0002
#تعریف_کړه QS_MOUSEBUTTON 0x0004
#تعریف_کړه QS_POSTMESSAGE 0x0008
#تعریف_کړه QS_TIMER 0x0010
#تعریف_کړه QS_PAINT 0x0020
#تعریف_کړه QS_SENDMESSAGE 0x0040
#تعریف_کړه QS_HOTKEY 0x0080
#تعریف_کړه QS_ALLPOSTMESSAGE 0x0100
#تعریف_کړه QS_RAWINPUT 0x0400
#تعریف_کړه QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#تعریف_کړه QS_ننوت (QS_MOUSE | QS_کلی | QS_RAWINPUT)
#تعریف_کړه QS_ALLEVENTS (QS_ننوت | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#تعریف_کړه QS_ALLINPUT (QS_ننوت | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#تعریف_کړه USER_TIMER_اعظمي 0x7FFFFFFF
#تعریف_کړه USER_TIMER_MINIMUM 0x0000000A

#که_تعریف_شوی UNICODE
#تعریف_کړه بارول_Accelerators بارول_Accelerators_W
#تعریف_کړه Create_Accelerator_جدول Create_Accelerator_جدول_W
#تعریف_کړه Copy_Accelerator_جدول Copy_Accelerator_جدول_W
#وإلا
#تعریف_کړه بارول_Accelerators بارول_Accelerators_A
#تعریف_کړه Create_Accelerator_جدول Create_Accelerator_جدول_A
#تعریف_کړه Copy_Accelerator_جدول Copy_Accelerator_جدول_A
#د_که_پای

  WINUSERAPI UINT_PTR WINAPI سېټ_Timer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
  WINUSERAPI WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);
  WINUSERAPI WINBOOL WINAPI Is_کړکۍ_Unicode(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Enable_کړکۍ(HWND hWnd,WINBOOL bEnable);
  WINUSERAPI WINBOOL WINAPI Is_کړکۍ_Enabled(HWND hWnd);
  WINUSERAPI HACCEL WINAPI بارول_Accelerators_A(HINSTANCE hInstance,LPCSTR lp_جدول_Name);
  WINUSERAPI HACCEL WINAPI بارول_Accelerators_W(HINSTANCE hInstance,LPCWSTR lp_جدول_Name);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_جدول_A(LPACCEL paccel,صحيح cAccel);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_جدول_W(LPACCEL paccel,صحيح cAccel);
  WINUSERAPI WINBOOL WINAPI Destroy_Accelerator_جدول(HACCEL hAccel);
  WINUSERAPI صحيح WINAPI Copy_Accelerator_جدول_A(HACCEL hAccelSrc,LPACCEL lpAccelDst,صحيح cAccelEntries);
  WINUSERAPI صحيح WINAPI Copy_Accelerator_جدول_W(HACCEL hAccelSrc,LPACCEL lpAccelDst,صحيح cAccelEntries);

#که_نه_تعریف_شوی NOMSG

#که_تعریف_شوی UNICODE
#تعریف_کړه TranslateAccelerator TranslateAcceleratorW
#وإلا
#تعریف_کړه TranslateAccelerator TranslateAcceleratorA
#د_که_پای

  WINUSERAPI صحيح WINAPI TranslateAcceleratorA(HWND hWnd,HACCEL h_Acc_جدول,LPMSG lp_پیغام_2);
  WINUSERAPI صحيح WINAPI TranslateAcceleratorW(HWND hWnd,HACCEL h_Acc_جدول,LPMSG lp_پیغام_2);
#د_که_پای

#که_نه_تعریف_شوی NOSYSMETRICS

#تعریف_کړه SM_CXSCREEN 0
#تعریف_کړه SM_CYSCREEN 1
#تعریف_کړه SM_CXVSCROLL 2
#تعریف_کړه SM_CYHSCROLL 3
#تعریف_کړه SM_CYCAPTION 4
#تعریف_کړه SM_CXBORDER 5
#تعریف_کړه SM_CYBORDER 6
#تعریف_کړه SM_CXDLGFRAME 7
#تعریف_کړه SM_CYDLGFRAME 8
#تعریف_کړه SM_CYVTHUMB 9
#تعریف_کړه SM_CXHTHUMB 10
#تعریف_کړه SM_CXICON 11
#تعریف_کړه SM_CYICON 12
#تعریف_کړه SM_CXCURSOR 13
#تعریف_کړه SM_CYCURSOR 14
#تعریف_کړه SM_CYMENU 15
#تعریف_کړه SM_CXFULLSCREEN 16
#تعریف_کړه SM_CYFULLSCREEN 17
#تعریف_کړه SM_CYKANJIWINDOW 18
#تعریف_کړه SM_MOUSEPRESENT 19
#تعریف_کړه SM_CYVSCROLL 20
#تعریف_کړه SM_CXHSCROLL 21
#تعریف_کړه SM_DEBUG 22
#تعریف_کړه SM_SWAPBUTTON 23
#تعریف_کړه SM_RESERVED1 24
#تعریف_کړه SM_RESERVED2 25
#تعریف_کړه SM_RESERVED3 26
#تعریف_کړه SM_RESERVED4 27
#تعریف_کړه SM_CXMIN 28
#تعریف_کړه SM_CYMIN 29
#تعریف_کړه SM_CXSIZE 30
#تعریف_کړه SM_CYSIZE 31
#تعریف_کړه SM_CXFRAME 32
#تعریف_کړه SM_CYFRAME 33
#تعریف_کړه SM_CXMINTRACK 34
#تعریف_کړه SM_CYMINTRACK 35
#تعریف_کړه SM_CXDOUBLECLK 36
#تعریف_کړه SM_CYDOUBLECLK 37
#تعریف_کړه SM_CXICONSPACING 38
#تعریف_کړه SM_CYICONSPACING 39
#تعریف_کړه SM_MENUDROPALIGNMENT 40
#تعریف_کړه SM_PENWINDOWS 41
#تعریف_کړه SM_DBCSENABLED 42
#تعریف_کړه SM_CMOUSEBUTTONS 43

#تعریف_کړه SM_CXFIXEDFRAME SM_CXDLGFRAME
#تعریف_کړه SM_CYFIXEDFRAME SM_CYDLGFRAME
#تعریف_کړه SM_CXSIZEFRAME SM_CXFRAME
#تعریف_کړه SM_CYSIZEFRAME SM_CYFRAME

#تعریف_کړه SM_SECURE 44
#تعریف_کړه SM_CXEDGE 45
#تعریف_کړه SM_CYEDGE 46
#تعریف_کړه SM_CXMINSPACING 47
#تعریف_کړه SM_CYMINSPACING 48
#تعریف_کړه SM_CXSMICON 49
#تعریف_کړه SM_CYSMICON 50
#تعریف_کړه SM_CYSMCAPTION 51
#تعریف_کړه SM_CXSMSIZE 52
#تعریف_کړه SM_CYSMSIZE 53
#تعریف_کړه SM_CXMENUSIZE 54
#تعریف_کړه SM_CYMENUSIZE 55
#تعریف_کړه SM_ARRANGE 56
#تعریف_کړه SM_CXMINIMIZED 57
#تعریف_کړه SM_CYMINIMIZED 58
#تعریف_کړه SM_CXMAXTRACK 59
#تعریف_کړه SM_CYMAXTRACK 60
#تعریف_کړه SM_CXMAXIMIZED 61
#تعریف_کړه SM_CYMAXIMIZED 62
#تعریف_کړه SM_شبکه 63
#تعریف_کړه SM_CLEANBOOT 67
#تعریف_کړه SM_CXDRAG 68
#تعریف_کړه SM_CYDRAG 69
#تعریف_کړه SM_SHOWSOUNDS 70
#تعریف_کړه SM_CXMENUCHECK 71
#تعریف_کړه SM_CYMENUCHECK 72
#تعریف_کړه SM_SLOWMACHINE 73
#تعریف_کړه SM_MIDEASTENABLED 74
#تعریف_کړه SM_MOUSEWHEELPRESENT 75
#تعریف_کړه SM_XVIRTUALSCREEN 76
#تعریف_کړه SM_YVIRTUALSCREEN 77
#تعریف_کړه SM_CXVIRTUALSCREEN 78
#تعریف_کړه SM_CYVIRTUALSCREEN 79
#تعریف_کړه SM_CMONITORS 80
#تعریف_کړه SM_SAMEDISPLAYFORMAT 81
#تعریف_کړه SM_IMMENABLED 82
#تعریف_کړه SM_CXFOCUSBORDER 83
#تعریف_کړه SM_CYFOCUSBORDER 84
#تعریف_کړه SM_TABLETPC 86
#تعریف_کړه SM_MEDIACENTER 87
#تعریف_کړه SM_STARTER 88
#تعریف_کړه SM_SERVERR2 89
#تعریف_کړه SM_CMETRICS 90
#تعریف_کړه SM_REMOTESESSION 0x1000
#تعریف_کړه SM_SHUTTINGDOWN 0x2000
#تعریف_کړه SM_REMOTECONTROL 0x2001
#تعریف_کړه SM_CARETBLINKINGENABLED 0x2002

  WINUSERAPI صحيح WINAPI GetSystemMetrics(صحيح n_شاخص);
#د_که_پای

#که_نه_تعریف_شوی NOMENUS

#که_تعریف_شوی UNICODE
#تعریف_کړه بارول_Menu بارول_Menu_W
#تعریف_کړه بارول_Menu_غیرمستقیم بارول_Menu_غیرمستقیم_W
#تعریف_کړه ChangeMenu ChangeMenuW
#تعریف_کړه GetMenuString GetMenuStringW
#تعریف_کړه ورننباسه_Menu ورننباسه_Menu_W
#تعریف_کړه AppendMenu AppendMenuW
#تعریف_کړه ModifyMenu ModifyMenuW
#وإلا
#تعریف_کړه بارول_Menu بارول_Menu_A
#تعریف_کړه بارول_Menu_غیرمستقیم بارول_Menu_غیرمستقیم_A
#تعریف_کړه ChangeMenu ChangeMenuA
#تعریف_کړه GetMenuString GetMenuStringA
#تعریف_کړه ورننباسه_Menu ورننباسه_Menu_A
#تعریف_کړه AppendMenu AppendMenuA
#تعریف_کړه ModifyMenu ModifyMenuA
#د_که_پای

  WINUSERAPI HMENU WINAPI بارول_Menu_A(HINSTANCE hInstance,LPCSTR lpMenuName);
  WINUSERAPI HMENU WINAPI بارول_Menu_W(HINSTANCE hInstance,LPCWSTR lpMenuName);
  WINUSERAPI HMENU WINAPI بارول_Menu_غیرمستقیم_A(CONST MENUTEMPLATEA *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI بارول_Menu_غیرمستقیم_W(CONST MENUTEMPLATEW *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI GetMenu(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI سېټ_Menu(HWND hWnd,HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpsz_New_توکی,UINT cmd_ورننباسه,UINT flags);
  WINUSERAPI WINBOOL WINAPI ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpsz_New_توکی,UINT cmd_ورننباسه,UINT flags);
  WINUSERAPI WINBOOL WINAPI Hilite_Menu_توکی(HWND hWnd,HMENU hMenu,UINT u_IDHilite_توکی,UINT uHilite);
  WINUSERAPI صحيح WINAPI GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,صحيح cchMax,UINT flags);
  WINUSERAPI صحيح WINAPI GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,صحيح cchMax,UINT flags);
  WINUSERAPI UINT WINAPI GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawMenuBar(HWND hWnd);

#تعریف_کړه PMB_فعال 0x00000001

  WINUSERAPI HMENU WINAPI GetSystemMenu(HWND hWnd,WINBOOL bRevert);
  WINUSERAPI HMENU WINAPI CreateMenu(VOID);
  WINUSERAPI HMENU WINAPI CreatePopupMenu(VOID);
  WINUSERAPI WINBOOL WINAPI DestroyMenu(HMENU hMenu);
  WINUSERAPI DWORD WINAPI Check_Menu_توکی(HMENU hMenu,UINT u_IDCheck_توکی,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI Enable_Menu_توکی(HMENU hMenu,UINT u_IDEnable_توکی,UINT uEnable);
  WINUSERAPI HMENU WINAPI GetSubMenu(HMENU hMenu,صحيح nPos);
  WINUSERAPI UINT WINAPI Get_Menu_توکی_ID(HMENU hMenu,صحيح nPos);
  WINUSERAPI صحيح WINAPI Get_Menu_توکی_شمېر(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ورننباسه_Menu_A(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_توکی,LPCSTR lp_New_توکی);
  WINUSERAPI WINBOOL WINAPI ورننباسه_Menu_W(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_توکی,LPCWSTR lp_New_توکی);
  WINUSERAPI WINBOOL WINAPI AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_توکی,LPCSTR lp_New_توکی);
  WINUSERAPI WINBOOL WINAPI AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_توکی,LPCWSTR lp_New_توکی);
  WINUSERAPI WINBOOL WINAPI ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_توکی,LPCSTR lp_New_توکی);
  WINUSERAPI WINBOOL WINAPI ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_توکی,LPCWSTR lp_New_توکی);
  WINUSERAPI WINBOOL WINAPI RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI سېټ_Menu_توکی_Bitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
  WINUSERAPI LONG WINAPI GetMenuCheckMarkDimensions(VOID);
  WINUSERAPI WINBOOL WINAPI TrackPopupMenu(HMENU hMenu,UINT uFlags,صحيح x,صحيح y,صحيح nReserved,HWND hWnd,CONST RECT *prcRect);

#تعریف_کړه MNC_IGNORE 0
#تعریف_کړه MNC_CLOSE 1
#تعریف_کړه MNC_EXECUTE 2
#تعریف_کړه MNC_SELECT 3

  تعريفنوع بنية نښان_TPMPARAMS {
    UINT cb_اندازه;
    RECT rcExclude;
  } TPMPARAMS;

  تعريفنوع TPMPARAMS *LPTPMPARAMS;

  WINUSERAPI WINBOOL WINAPI TrackPopupMenuEx(HMENU,UINT,صحيح,صحيح,HWND,LPTPMPARAMS);

#تعریف_کړه MNS_NOCHECK 0x80000000
#تعریف_کړه MNS_MODELESS 0x40000000
#تعریف_کړه MNS_DRAGDROP 0x20000000
#تعریف_کړه MNS_AUTODISMISS 0x10000000
#تعریف_کړه MNS_NOTIFYBYPOS 0x08000000
#تعریف_کړه MNS_CHECKORBMP 0x04000000

#تعریف_کړه MIM_MAXHEIGHT 0x00000001
#تعریف_کړه MIM_BACKGROUND 0x00000002
#تعریف_کړه MIM_HELPID 0x00000004
#تعریف_کړه MIM_MENUDATA 0x00000008
#تعریف_کړه MIM_STYLE 0x00000010
#تعریف_کړه MIM_APPLYTOSUBMENUS 0x80000000

  تعريفنوع بنية نښان_MENUINFO {
    DWORD cb_اندازه;
    DWORD f_ماسک;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbr_شا;
    DWORD dwContextHelpID;
    ULONG_PTR dw_Menu_معلومات;
  } MENUINFO,*LPMENUINFO;

  تعريفنوع MENUINFO CONST *LPCMENUINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuInfo(HMENU,LPMENUINFO);
  WINUSERAPI WINBOOL WINAPI سېټ_Menu_Info(HMENU,LPCMENUINFO);
  WINUSERAPI WINBOOL WINAPI پای_ټکی_Menu(VOID);

#تعریف_کړه MND_CONTINUE 0
#تعریف_کړه MND_ENDMENU 1

  تعريفنوع بنية نښان_MENUGETOBJECTINFO {
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
  } MENUGETOBJECTINFO,*PMENUGETOBJECTINFO;

#تعریف_کړه MNGOF_TOPGAP 0x00000001
#تعریف_کړه MNGOF_BOTTOMGAP 0x00000002

#تعریف_کړه MNGO_NOINTERFACE 0x00000000
#تعریف_کړه MNGO_NOERROR 0x00000001

#تعریف_کړه MIIM_STATE 0x00000001
#تعریف_کړه MIIM_ID 0x00000002
#تعریف_کړه MIIM_SUBMENU 0x00000004
#تعریف_کړه MIIM_CHECKMARKS 0x00000008
#تعریف_کړه MIIM_TYPE 0x00000010
#تعریف_کړه MIIM_معلومات 0x00000020

#تعریف_کړه MIIM_STRING 0x00000040
#تعریف_کړه MIIM_BITMAP 0x00000080
#تعریف_کړه MIIM_FTYPE 0x00000100

#تعریف_کړه HBMMENU_CALLBACK ((HBITMAP) -1)
#تعریف_کړه HBMMENU_SYSTEM ((HBITMAP) 1)
#تعریف_کړه HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#تعریف_کړه HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#تعریف_کړه HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#تعریف_کړه HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#تعریف_کړه HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#تعریف_کړه HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#تعریف_کړه HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#تعریف_کړه HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#تعریف_کړه HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

  تعريفنوع بنية نښان_MENUITEMINFOA {
    UINT cb_اندازه;
    UINT f_ماسک;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_توکی_معلومات;
    LPSTR dw_Type_معلومات;
    UINT cch;
    HBITMAP hbmp_توکی;
  } MENUITEMINFOA,*LPMENUITEMINFOA;

  تعريفنوع بنية نښان_MENUITEMINFOW {
    UINT cb_اندازه;
    UINT f_ماسک;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_توکی_معلومات;
    LPWSTR dw_Type_معلومات;
    UINT cch;
    HBITMAP hbmp_توکی;
  } MENUITEMINFOW,*LPMENUITEMINFOW;

#که_تعریف_شوی UNICODE
  تعريفنوع MENUITEMINFOW MENUITEMINFO;
  تعريفنوع LPMENUITEMINFOW LPMENUITEMINFO;
#وإلا
  تعريفنوع MENUITEMINFOA MENUITEMINFO;
  تعريفنوع LPMENUITEMINFOA LPMENUITEMINFO;
#د_که_پای
  تعريفنوع MENUITEMINFOA CONST *LPCMENUITEMINFOA;
  تعريفنوع MENUITEMINFOW CONST *LPCMENUITEMINFOW;
#که_تعریف_شوی UNICODE
  تعريفنوع LPCMENUITEMINFOW LPCMENUITEMINFO;
#وإلا
  تعريفنوع LPCMENUITEMINFOA LPCMENUITEMINFO;
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه ورننباسه_Menu_توکی ورننباسه_Menu_توکی_W
#تعریف_کړه Get_Menu_توکی_Info Get_Menu_توکی_Info_W
#تعریف_کړه سېټ_Menu_توکی_Info سېټ_Menu_توکی_Info_W
#وإلا
#تعریف_کړه ورننباسه_Menu_توکی ورننباسه_Menu_توکی_A
#تعریف_کړه Get_Menu_توکی_Info Get_Menu_توکی_Info_A
#تعریف_کړه سېټ_Menu_توکی_Info سېټ_Menu_توکی_Info_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI ورننباسه_Menu_توکی_A(HMENU hmenu,UINT توکی,WINBOOL fByPosition,LPCMENUITEMINFOA lpmi);
  WINUSERAPI WINBOOL WINAPI ورننباسه_Menu_توکی_W(HMENU hmenu,UINT توکی,WINBOOL fByPosition,LPCMENUITEMINFOW lpmi);
  WINUSERAPI WINBOOL WINAPI Get_Menu_توکی_Info_A(HMENU hmenu,UINT توکی,WINBOOL fByPosition,LPMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI Get_Menu_توکی_Info_W(HMENU hmenu,UINT توکی,WINBOOL fByPosition,LPMENUITEMINFOW lpmii);
  WINUSERAPI WINBOOL WINAPI سېټ_Menu_توکی_Info_A(HMENU hmenu,UINT توکی,WINBOOL fByPositon,LPCMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI سېټ_Menu_توکی_Info_W(HMENU hmenu,UINT توکی,WINBOOL fByPositon,LPCMENUITEMINFOW lpmii);

#تعریف_کړه GMDI_USEDISABLED 0x0001L
#تعریف_کړه GMDI_GOINTOPOPUPS 0x0002L

  WINUSERAPI UINT WINAPI Get_Menu_Default_توکی(HMENU hMenu,UINT fByPos,UINT gmdiFlags);
  WINUSERAPI WINBOOL WINAPI سېټ_Menu_Default_توکی(HMENU hMenu,UINT u_توکی,UINT fByPos);
  WINUSERAPI WINBOOL WINAPI Get_Menu_توکی_Rect(HWND hWnd,HMENU hMenu,UINT u_توکی,LPRECT lprc_توکی);
  WINUSERAPI صحيح WINAPI Menu_توکی_From_ټکی(HWND hWnd,HMENU hMenu,ټکی_3 ptScreen);

#تعریف_کړه TPM_LEFTBUTTON 0x0000L
#تعریف_کړه TPM_RIGHTBUTTON 0x0002L
#تعریف_کړه TPM_LEFTALIGN 0x0000L
#تعریف_کړه TPM_CENTERALIGN 0x0004L
#تعریف_کړه TPM_RIGHTALIGN 0x0008L
#تعریف_کړه TPM_TOPALIGN 0x0000L
#تعریف_کړه TPM_VCENTERALIGN 0x0010L
#تعریف_کړه TPM_BOTTOMALIGN 0x0020L

#تعریف_کړه TPM_HORIZONTAL 0x0000L
#تعریف_کړه TPM_VERTICAL 0x0040L
#تعریف_کړه TPM_NONOTIFY 0x0080L
#تعریف_کړه TPM_RETURNCMD 0x0100L
#تعریف_کړه TPM_RECURSE 0x0001L
#تعریف_کړه TPM_HORPOSANIMATION 0x0400L
#تعریف_کړه TPM_HORNEGANIMATION 0x0800L
#تعریف_کړه TPM_VERPOSANIMATION 0x1000L
#تعریف_کړه TPM_VERNEGANIMATION 0x2000L
#تعریف_کړه TPM_NOANIMATION 0x4000L
#تعریف_کړه TPM_LAYOUTRTL 0x8000L
#د_که_پای

  تعريفنوع بنية نښان_DROPSTRUCT {
    HWND hwnd_سرچینه;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dw_معلومات;
    ټکی_3 ptDrop;
    DWORD dw_Control_معلومات;
  } DROPSTRUCT,*PDROPSTRUCT,*LPDROPSTRUCT;

#تعریف_کړه DOF_EXECUTABLE 0x8001
#تعریف_کړه DOF_DOCUMENT 0x8002
#تعریف_کړه DOF_DIRECTORY 0x8003
#تعریف_کړه DOF_مضرب 0x8004
#تعریف_کړه DOF_PROGMAN 0x0001
#تعریف_کړه DOF_SHELLDATA 0x0002

#تعریف_کړه DO_DROPFILE 0x454C4946L
#تعریف_کړه DO_PRINTFILE 0x544E5250L

  WINUSERAPI DWORD WINAPI DragObject(HWND hwnd_پلار_2,HWND hwndFrom,UINT fmt,ULONG_PTR معلومات,HCURSOR hcur);
  WINUSERAPI WINBOOL WINAPI DragDetect(HWND hwnd,ټکی_3 pt);
  WINUSERAPI WINBOOL WINAPI DrawIcon(HDC hDC,صحيح X,صحيح Y,HICON hIcon);

#که_نه_تعریف_شوی NODRAWTEXT

#تعریف_کړه DT_سر 0x00000000
#تعریف_کړه DT_کیڼ 0x00000000
#تعریف_کړه DT_CENTER 0x00000001
#تعریف_کړه DT_ښی 0x00000002
#تعریف_کړه DT_VCENTER 0x00000004
#تعریف_کړه DT_BOTTOM 0x00000008
#تعریف_کړه DT_WORDBREAK 0x00000010
#تعریف_کړه DT_SINGLELINE 0x00000020
#تعریف_کړه DT_EXPANDTABS 0x00000040
#تعریف_کړه DT_TABSTOP 0x00000080
#تعریف_کړه DT_NOCLIP 0x00000100
#تعریف_کړه DT_EXTERNALLEADING 0x00000200
#تعریف_کړه DT_CALCRECT 0x00000400
#تعریف_کړه DT_NOPREFIX 0x00000800
#تعریف_کړه DT_دننی 0x00001000

#تعریف_کړه DT_EDITCONTROL 0x00002000
#تعریف_کړه DT_لار_ELLIPSIS 0x00004000
#تعریف_کړه DT_پای_ټکی_ELLIPSIS 0x00008000
#تعریف_کړه DT_MODIFYSTRING 0x00010000
#تعریف_کړه DT_RTLREADING 0x00020000
#تعریف_کړه DT_کلمه_ELLIPSIS 0x00040000
#تعریف_کړه DT_NOFULLWIDTHCHARBREAK 0x00080000
#تعریف_کړه DT_HIDEPREFIX 0x00100000
#تعریف_کړه DT_PREFIXONLY 0x00200000

  تعريفنوع بنية نښان_DRAWTEXTPARAMS {
    UINT cb_اندازه;
    صحيح i_Tab_اوږدتیا;
    صحيح i_کیڼ_Margin;
    صحيح i_ښی_Margin;
    UINT ui_اوږدتیا_Drawn;
  } DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

#که_تعریف_شوی UNICODE
#تعریف_کړه Draw_متن Draw_متن_W
#تعریف_کړه Draw_متن_Ex Draw_متن_Ex_W
#وإلا
#تعریف_کړه Draw_متن Draw_متن_A
#تعریف_کړه Draw_متن_Ex Draw_متن_Ex_A
#د_که_پای

  WINUSERAPI صحيح WINAPI Draw_متن_A(HDC hdc,LPCSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format);
  WINUSERAPI صحيح WINAPI Draw_متن_W(HDC hdc,LPCWSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format);
  WINUSERAPI صحيح WINAPI Draw_متن_Ex_A(HDC hdc,LPSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
  WINUSERAPI صحيح WINAPI Draw_متن_Ex_W(HDC hdc,LPWSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه خړ_String خړ_String_W
#تعریف_کړه DrawState DrawStateW
#تعریف_کړه Tabbed_متن_بهر Tabbed_متن_بهر_W
#تعریف_کړه Get_Tabbed_متن_Extent Get_Tabbed_متن_Extent_W
#وإلا
#تعریف_کړه خړ_String خړ_String_A
#تعریف_کړه DrawState DrawStateA
#تعریف_کړه Tabbed_متن_بهر Tabbed_متن_بهر_A
#تعریف_کړه Get_Tabbed_متن_Extent Get_Tabbed_متن_Extent_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI خړ_String_A(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_معلومات,صحيح n_شمېر,صحيح X,صحيح Y,صحيح n_پلنوالی,صحيح n_لوړوالی);
  WINUSERAPI WINBOOL WINAPI خړ_String_W(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_معلومات,صحيح n_شمېر,صحيح X,صحيح Y,صحيح n_پلنوالی,صحيح n_لوړوالی);

#تعریف_کړه DST_COMPLEX 0x0000
#تعریف_کړه DST_متن 0x0001
#تعریف_کړه DST_PREFIXTEXT 0x0002
#تعریف_کړه DST_ICON 0x0003
#تعریف_کړه DST_BITMAP 0x0004

#تعریف_کړه DSS_نورمال 0x0000
#تعریف_کړه DSS_UNION 0x0010
#تعریف_کړه DSS_DISABLED 0x0020
#تعریف_کړه DSS_MONO 0x0080
#تعریف_کړه DSS_HIDEPREFIX 0x0200
#تعریف_کړه DSS_PREFIXONLY 0x0400
#تعریف_کړه DSS_ښی 0x8000

  WINUSERAPI WINBOOL WINAPI DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_شا,LPARAM l_معلومات,WPARAM w_معلومات,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_شا,LPARAM l_معلومات,WPARAM w_معلومات,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI LONG WINAPI Tabbed_متن_بهر_A(HDC hdc,صحيح x,صحيح y,LPCSTR lpString,صحيح ch_شمېر,صحيح nTabPositions,CONST INT *lpnTabStopPositions,صحيح nTabOrigin);
  WINUSERAPI LONG WINAPI Tabbed_متن_بهر_W(HDC hdc,صحيح x,صحيح y,LPCWSTR lpString,صحيح ch_شمېر,صحيح nTabPositions,CONST INT *lpnTabStopPositions,صحيح nTabOrigin);
  WINUSERAPI DWORD WINAPI Get_Tabbed_متن_Extent_A(HDC hdc,LPCSTR lpString,صحيح ch_شمېر,صحيح nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI DWORD WINAPI Get_Tabbed_متن_Extent_W(HDC hdc,LPCWSTR lpString,صحيح ch_شمېر,صحيح nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI WINBOOL WINAPI Update_کړکۍ(HWND hWnd);
  WINUSERAPI HWND WINAPI سېټ_فعال_کړکۍ(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_Foreground_کړکۍ(VOID);
  WINUSERAPI WINBOOL WINAPI PaintDesktop(HDC hdc);
  WINUSERAPI VOID WINAPI Switch_منزل_This_کړکۍ(HWND hwnd,WINBOOL fUnknown);
  WINUSERAPI WINBOOL WINAPI سېټ_Foreground_کړکۍ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Allow_سېټ_Foreground_کړکۍ(DWORD dwProcessId);

#تعریف_کړه ASFW_ANY ((DWORD)-1)

  WINUSERAPI WINBOOL WINAPI قلف_سېټ_Foreground_کړکۍ(UINT u_قلف_کوډ);

#تعریف_کړه LSFW_قلف 1
#تعریف_کړه LSFW_UNLOCK 2

  WINUSERAPI HWND WINAPI کړکۍ_From_DC(HDC hDC);
  WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
  WINUSERAPI HDC WINAPI GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags);

#تعریف_کړه DCX_کړکۍ 0x00000001L
#تعریف_کړه DCX_CACHE 0x00000002L
#تعریف_کړه DCX_NORESETATTRS 0x00000004L
#تعریف_کړه DCX_CLIPCHILDREN 0x00000008L
#تعریف_کړه DCX_CLIPSIBLINGS 0x00000010L
#تعریف_کړه DCX_PARENTCLIP 0x00000020L
#تعریف_کړه DCX_EXCLUDERGN 0x00000040L
#تعریف_کړه DCX_INTERSECTRGN 0x00000080L
#تعریف_کړه DCX_EXCLUDEUPDATE 0x00000100L
#تعریف_کړه DCX_INTERSECTUPDATE 0x00000200L
#تعریف_کړه DCX_LOCKWINDOWUPDATE 0x00000400L

#تعریف_کړه DCX_VALIDATE 0x00200000L

  WINUSERAPI HDC WINAPI Get_کړکۍ_DC(HWND hWnd);
  WINUSERAPI صحيح WINAPI ReleaseDC(HWND hWnd,HDC hDC);
  WINUSERAPI HDC WINAPI BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
  WINUSERAPI WINBOOL WINAPI پای_ټکی_Paint(HWND hWnd,CONST PAINTSTRUCT *lpPaint);
  WINUSERAPI WINBOOL WINAPI GetUpdateRect(HWND hWnd,LPRECT lpRect,WINBOOL bErase);
  WINUSERAPI صحيح WINAPI GetUpdateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI صحيح WINAPI سېټ_کړکۍ_Rgn(HWND hWnd,HRGN hRgn,WINBOOL bRedraw);
  WINUSERAPI صحيح WINAPI Get_کړکۍ_Rgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI صحيح WINAPI Get_کړکۍ_Rgn_Box(HWND hWnd,LPRECT lprc);
  WINUSERAPI صحيح WINAPI ExcludeUpdateRgn(HDC hDC,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI InvalidateRect(HWND hWnd,CONST RECT *lpRect,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRect(HWND hWnd,CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI InvalidateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI WINBOOL WINAPI Redraw_کړکۍ(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#تعریف_کړه RDW_INVALIDATE 0x0001
#تعریف_کړه RDW_INTERNALPAINT 0x0002
#تعریف_کړه RDW_ERASE 0x0004

#تعریف_کړه RDW_VALIDATE 0x0008
#تعریف_کړه RDW_NOINTERNALPAINT 0x0010
#تعریف_کړه RDW_NOERASE 0x0020

#تعریف_کړه RDW_NOCHILDREN 0x0040
#تعریف_کړه RDW_ALLCHILDREN 0x0080

#تعریف_کړه RDW_UPDATENOW 0x0100
#تعریف_کړه RDW_ERASENOW 0x0200

#تعریف_کړه RDW_چوکاټ 0x0400
#تعریف_کړه RDW_NOFRAME 0x0800

  WINUSERAPI WINBOOL WINAPI قلف_کړکۍ_Update(HWND h_Wnd_قلف);
  WINUSERAPI WINBOOL WINAPI Scroll_کړکۍ(HWND hWnd,صحيح XAmount,صحيح YAmount,CONST RECT *lpRect,CONST RECT *lpClipRect);
  WINUSERAPI WINBOOL WINAPI ScrollDC(HDC hDC,صحيح dx,صحيح dy,CONST RECT *lprcScroll,CONST RECT *lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
  WINUSERAPI صحيح WINAPI Scroll_کړکۍ_Ex(HWND hWnd,صحيح dx,صحيح dy,CONST RECT *prcScroll,CONST RECT *prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);

#تعریف_کړه SW_SCROLLCHILDREN 0x0001
#تعریف_کړه SW_INVALIDATE 0x0002
#تعریف_کړه SW_ERASE 0x0004
#تعریف_کړه SW_SMOOTHSCROLL 0x0010

#که_نه_تعریف_شوی NOSCROLL
  WINUSERAPI صحيح WINAPI سېټ_Scroll_Pos(HWND hWnd,صحيح nBar,صحيح nPos,WINBOOL bRedraw);
  WINUSERAPI صحيح WINAPI GetScrollPos(HWND hWnd,صحيح nBar);
  WINUSERAPI WINBOOL WINAPI سېټ_Scroll_Range(HWND hWnd,صحيح nBar,صحيح nMinPos,صحيح nMaxPos,WINBOOL bRedraw);
  WINUSERAPI WINBOOL WINAPI GetScrollRange(HWND hWnd,صحيح nBar,LPINT lpMinPos,LPINT lpMaxPos);
  WINUSERAPI WINBOOL WINAPI ShowScrollBar(HWND hWnd,صحيح wBar,WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows);

#تعریف_کړه ESB_ENABLE_BOTH 0x0000
#تعریف_کړه ESB_DISABLE_BOTH 0x0003

#تعریف_کړه ESB_DISABLE_کیڼ 0x0001
#تعریف_کړه ESB_DISABLE_ښی 0x0002

#تعریف_کړه ESB_DISABLE_پورته 0x0001
#تعریف_کړه ESB_DISABLE_ښکته 0x0002

#تعریف_کړه ESB_DISABLE_LTUP ESB_DISABLE_کیڼ
#تعریف_کړه ESB_DISABLE_RTDN ESB_DISABLE_ښی
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه سېټ_Prop سېټ_Prop_W
#تعریف_کړه GetProp GetPropW
#تعریف_کړه RemoveProp RemovePropW
#تعریف_کړه EnumPropsEx EnumPropsExW
#تعریف_کړه EnumProps EnumPropsW
#تعریف_کړه سېټ_کړکۍ_متن سېټ_کړکۍ_متن_W
#تعریف_کړه Get_کړکۍ_متن Get_کړکۍ_متن_W
#تعریف_کړه Get_کړکۍ_متن_اوږدتیا Get_کړکۍ_متن_اوږدتیا_W
#وإلا
#تعریف_کړه سېټ_Prop سېټ_Prop_A
#تعریف_کړه GetProp GetPropA
#تعریف_کړه RemoveProp RemovePropA
#تعریف_کړه EnumPropsEx EnumPropsExA
#تعریف_کړه EnumProps EnumPropsA
#تعریف_کړه سېټ_کړکۍ_متن سېټ_کړکۍ_متن_A
#تعریف_کړه Get_کړکۍ_متن Get_کړکۍ_متن_A
#تعریف_کړه Get_کړکۍ_متن_اوږدتیا Get_کړکۍ_متن_اوږدتیا_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI سېټ_Prop_A(HWND hWnd,LPCSTR lpString,HANDLE h_معلومات);
  WINUSERAPI WINBOOL WINAPI سېټ_Prop_W(HWND hWnd,LPCWSTR lpString,HANDLE h_معلومات);
  WINUSERAPI HANDLE WINAPI GetPropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI GetPropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI صحيح WINAPI EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
  WINUSERAPI صحيح WINAPI EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
  WINUSERAPI صحيح WINAPI EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc);
  WINUSERAPI صحيح WINAPI EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc);
  WINUSERAPI WINBOOL WINAPI سېټ_کړکۍ_متن_A(HWND hWnd,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI سېټ_کړکۍ_متن_W(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI صحيح WINAPI Get_کړکۍ_متن_A(HWND hWnd,LPSTR lpString,صحيح n_Max_شمېر);
  WINUSERAPI صحيح WINAPI Get_کړکۍ_متن_W(HWND hWnd,LPWSTR lpString,صحيح n_Max_شمېر);
  WINUSERAPI صحيح WINAPI Get_کړکۍ_متن_اوږدتیا_A(HWND hWnd);
  WINUSERAPI صحيح WINAPI Get_کړکۍ_متن_اوږدتیا_W(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI GetClientRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Get_کړکۍ_Rect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Adjust_کړکۍ_Rect(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu);
  WINUSERAPI WINBOOL WINAPI Adjust_کړکۍ_Rect_Ex(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu,DWORD dwExStyle);

#تعریف_کړه HELPINFO_کړکۍ 0x0001
#تعریف_کړه HELPINFO_MENUITEM 0x0002

  تعريفنوع بنية نښان_HELPINFO {
    UINT cb_اندازه;
    صحيح iContextType;
    صحيح iCtrlId;
    HANDLE h_توکی_Handle;
    DWORD_PTR dwContextId;
    ټکی_3 MousePos;
  } HELPINFO,*LPHELPINFO;

  WINUSERAPI WINBOOL WINAPI سېټ_کړکۍ_Context_Help_Id(HWND,DWORD);
  WINUSERAPI DWORD WINAPI Get_کړکۍ_Context_Help_Id(HWND);
  WINUSERAPI WINBOOL WINAPI سېټ_Menu_Context_Help_Id(HMENU,DWORD);
  WINUSERAPI DWORD WINAPI GetMenuContextHelpId(HMENU);

#که_نه_تعریف_شوی NOMB

#تعریف_کړه MB_OK 0x00000000L
#تعریف_کړه MB_OKCANCEL 0x00000001L
#تعریف_کړه MB_ABORTRETRYIGNORE 0x00000002L
#تعریف_کړه MB_YESNOCANCEL 0x00000003L
#تعریف_کړه MB_YESNO 0x00000004L
#تعریف_کړه MB_RETRYCANCEL 0x00000005L
#تعریف_کړه MB_CANCELTRYCONTINUE 0x00000006L
#تعریف_کړه MB_ICONHAND 0x00000010L
#تعریف_کړه MB_ICONQUESTION 0x00000020L
#تعریف_کړه MB_ICONEXCLAMATION 0x00000030L
#تعریف_کړه MB_ICONASTERISK 0x00000040L
#تعریف_کړه MB_USERICON 0x00000080L
#تعریف_کړه MB_ICONWARNING MB_ICONEXCLAMATION
#تعریف_کړه MB_ICONERROR MB_ICONHAND
#تعریف_کړه MB_ICONINFORMATION MB_ICONASTERISK
#تعریف_کړه MB_ICONSTOP MB_ICONHAND
#تعریف_کړه MB_DEFBUTTON1 0x00000000L
#تعریف_کړه MB_DEFBUTTON2 0x00000100L
#تعریف_کړه MB_DEFBUTTON3 0x00000200L
#تعریف_کړه MB_DEFBUTTON4 0x00000300L
#تعریف_کړه MB_APPLMODAL 0x00000000L
#تعریف_کړه MB_SYSTEMMODAL 0x00001000L
#تعریف_کړه MB_TASKMODAL 0x00002000L
#تعریف_کړه MB_HELP 0x00004000L
#تعریف_کړه MB_NOFOCUS 0x00008000L
#تعریف_کړه MB_SETFOREGROUND 0x00010000L
#تعریف_کړه MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#تعریف_کړه MB_TOPMOST 0x00040000L
#تعریف_کړه MB_ښی 0x00080000L
#تعریف_کړه MB_RTLREADING 0x00100000L
#تعریف_کړه MB_SERVICE_NOTIFICATION 0x00200000L
#تعریف_کړه MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#تعریف_کړه MB_TYPEMASK 0x0000000FL
#تعریف_کړه MB_ICONMASK 0x000000F0L
#تعریف_کړه MB_DEFMASK 0x00000F00L
#تعریف_کړه MB_MODEMASK 0x00003000L
#تعریف_کړه MB_MISCMASK 0x0000C000L

#که_تعریف_شوی UNICODE
#تعریف_کړه پیغام_Box پیغام_Box_W
#تعریف_کړه پیغام_Box_Ex پیغام_Box_Ex_W
#وإلا
#تعریف_کړه پیغام_Box پیغام_Box_A
#تعریف_کړه پیغام_Box_Ex پیغام_Box_Ex_A
#د_که_پای

  WINUSERAPI صحيح WINAPI پیغام_Box_A(HWND hWnd,LPCSTR lp_متن,LPCSTR lpCaption,UINT uType);
  WINUSERAPI صحيح WINAPI پیغام_Box_W(HWND hWnd,LPCWSTR lp_متن,LPCWSTR lpCaption,UINT uType);
  WINUSERAPI صحيح WINAPI پیغام_Box_Ex_A(HWND hWnd,LPCSTR lp_متن,LPCSTR lpCaption,UINT uType,کلمه_3 wLanguageId);
  WINUSERAPI صحيح WINAPI پیغام_Box_Ex_W(HWND hWnd,LPCWSTR lp_متن,LPCWSTR lpCaption,UINT uType,کلمه_3 wLanguageId);

  تعريفنوع VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

  تعريفنوع بنية نښان_MSGBOXPARAMSA {
    UINT cb_اندازه;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpsz_متن;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_پیغام_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSA,*PMSGBOXPARAMSA,*LPMSGBOXPARAMSA;

  تعريفنوع بنية نښان_MSGBOXPARAMSW {
    UINT cb_اندازه;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpsz_متن;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_پیغام_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSW,*PMSGBOXPARAMSW,*LPMSGBOXPARAMSW;

#که_تعریف_شوی UNICODE
  تعريفنوع MSGBOXPARAMSW MSGBOXPARAMS;
  تعريفنوع PMSGBOXPARAMSW PMSGBOXPARAMS;
  تعريفنوع LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#وإلا
  تعريفنوع MSGBOXPARAMSA MSGBOXPARAMS;
  تعريفنوع PMSGBOXPARAMSA PMSGBOXPARAMS;
  تعريفنوع LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه پیغام_Box_غیرمستقیم پیغام_Box_غیرمستقیم_W
#وإلا
#تعریف_کړه پیغام_Box_غیرمستقیم پیغام_Box_غیرمستقیم_A
#د_که_پای

  WINUSERAPI صحيح WINAPI پیغام_Box_غیرمستقیم_A(CONST MSGBOXPARAMSA *lpmbp);
  WINUSERAPI صحيح WINAPI پیغام_Box_غیرمستقیم_W(CONST MSGBOXPARAMSW *lpmbp);
  WINUSERAPI WINBOOL WINAPI پیغام_Beep(UINT uType);
#د_که_پای

  WINUSERAPI صحيح WINAPI ShowCursor(WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI سېټ_Cursor_Pos(صحيح X,صحيح Y);
  WINUSERAPI HCURSOR WINAPI سېټ_Cursor(HCURSOR hCursor);
  WINUSERAPI WINBOOL WINAPI GetCursorPos(LPPOINT lp_ټکی);
  WINUSERAPI WINBOOL WINAPI ClipCursor(CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI GetClipCursor(LPRECT lpRect);
  WINUSERAPI HCURSOR WINAPI GetCursor(VOID);
  WINUSERAPI WINBOOL WINAPI CreateCaret(HWND hWnd,HBITMAP hBitmap,صحيح n_پلنوالی,صحيح n_لوړوالی);
  WINUSERAPI UINT WINAPI Get_Caret_Blink_وخت(VOID);
  WINUSERAPI WINBOOL WINAPI سېټ_Caret_Blink_وخت(UINT uMSeconds);
  WINUSERAPI WINBOOL WINAPI DestroyCaret(VOID);
  WINUSERAPI WINBOOL WINAPI HideCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI سېټ_Caret_Pos(صحيح X,صحيح Y);
  WINUSERAPI WINBOOL WINAPI GetCaretPos(LPPOINT lp_ټکی);
  WINUSERAPI WINBOOL WINAPI Client_منزل_Screen(HWND hWnd,LPPOINT lp_ټکی);
  WINUSERAPI WINBOOL WINAPI Screen_منزل_Client(HWND hWnd,LPPOINT lp_ټکی);
  WINUSERAPI صحيح WINAPI Map_کړکۍ_Points(HWND hWndFrom,HWND h_Wnd_منزل,LPPOINT lpPoints,UINT cPoints);
  WINUSERAPI HWND WINAPI کړکۍ_From_ټکی(ټکی_3 ټکی_2);
  WINUSERAPI HWND WINAPI ماشوم_کړکۍ_From_ټکی(HWND h_Wnd_پلار,ټکی_3 ټکی_2);

#تعریف_کړه CWP_ALL 0x0000
#تعریف_کړه CWP_SKIPINVISIBLE 0x0001
#تعریف_کړه CWP_SKIPDISABLED 0x0002
#تعریف_کړه CWP_SKIPTRANSPARENT 0x0004

  WINUSERAPI HWND WINAPI ماشوم_کړکۍ_From_ټکی_Ex(HWND hwnd,ټکی_3 pt,UINT flags);

#که_نه_تعریف_شوی NOCOLOR

#تعریف_کړه CTLCOLOR_MSGBOX 0
#تعریف_کړه CTLCOLOR_EDIT 1
#تعریف_کړه CTLCOLOR_LISTBOX 2
#تعریف_کړه CTLCOLOR_BTN 3
#تعریف_کړه CTLCOLOR_DLG 4
#تعریف_کړه CTLCOLOR_SCROLLBAR 5
#تعریف_کړه CTLCOLOR_STATIC 6
#تعریف_کړه CTLCOLOR_MAX 7

#تعریف_کړه COLOR_SCROLLBAR 0
#تعریف_کړه COLOR_BACKGROUND 1
#تعریف_کړه COLOR_ACTIVECAPTION 2
#تعریف_کړه COLOR_INACTIVECAPTION 3
#تعریف_کړه COLOR_MENU 4
#تعریف_کړه COLOR_کړکۍ 5
#تعریف_کړه COLOR_WINDOWFRAME 6
#تعریف_کړه COLOR_MENUTEXT 7
#تعریف_کړه COLOR_WINDOWTEXT 8
#تعریف_کړه COLOR_CAPTIONTEXT 9
#تعریف_کړه COLOR_ACTIVEBORDER 10
#تعریف_کړه COLOR_INACTIVEBORDER 11
#تعریف_کړه COLOR_APPWORKSPACE 12
#تعریف_کړه COLOR_HIGHLIGHT 13
#تعریف_کړه COLOR_HIGHLIGHTTEXT 14
#تعریف_کړه COLOR_BTNFACE 15
#تعریف_کړه COLOR_BTNSHADOW 16
#تعریف_کړه COLOR_GRAYTEXT 17
#تعریف_کړه COLOR_BTNTEXT 18
#تعریف_کړه COLOR_INACTIVECAPTIONTEXT 19
#تعریف_کړه COLOR_BTNHIGHLIGHT 20

#تعریف_کړه COLOR_3DDKSHADOW 21
#تعریف_کړه COLOR_3DLIGHT 22
#تعریف_کړه COLOR_INFOTEXT 23
#تعریف_کړه COLOR_INFOBK 24

#تعریف_کړه COLOR_HOTLIGHT 26
#تعریف_کړه COLOR_GRADIENTACTIVECAPTION 27
#تعریف_کړه COLOR_GRADIENTINACTIVECAPTION 28
#تعریف_کړه COLOR_MENUHILIGHT 29
#تعریف_کړه COLOR_MENUBAR 30

#تعریف_کړه COLOR_DESKTOP COLOR_BACKGROUND
#تعریف_کړه COLOR_3DFACE COLOR_BTNFACE
#تعریف_کړه COLOR_3DSHADOW COLOR_BTNSHADOW
#تعریف_کړه COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#تعریف_کړه COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#تعریف_کړه COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

  WINUSERAPI DWORD WINAPI GetSysColor(صحيح n_شاخص);
  WINUSERAPI HBRUSH WINAPI GetSysColorBrush(صحيح n_شاخص);
  WINUSERAPI WINBOOL WINAPI سېټ_Sys_Colors(صحيح cElements,CONST INT *lpaElements,CONST COLORREF *lpa_Rgb_ارزښتونه);
#د_که_پای

  WINUSERAPI WINBOOL WINAPI DrawFocusRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI صحيح WINAPI FillRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI صحيح WINAPI چوکاټ_Rect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI WINBOOL WINAPI InvertRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI سېټ_Rect(LPRECT lprc,صحيح x_کیڼ,صحيح y_سر,صحيح x_ښی,صحيح yBottom);
  WINUSERAPI WINBOOL WINAPI سېټ_Rect_تشه(LPRECT lprc);
  WINUSERAPI WINBOOL WINAPI CopyRect(LPRECT lprcDst,CONST RECT *lprcSrc);
  WINUSERAPI WINBOOL WINAPI InflateRect(LPRECT lprc,صحيح dx,صحيح dy);
  WINUSERAPI WINBOOL WINAPI IntersectRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI UnionRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI کمول_Rect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI دننه_واټن_Rect(LPRECT lprc,صحيح dx,صحيح dy);
  WINUSERAPI WINBOOL WINAPI Is_Rect_تشه(CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI EqualRect(CONST RECT *lprc1,CONST RECT *lprc2);
  WINUSERAPI WINBOOL WINAPI Pt_دننه_Rect(CONST RECT *lprc,ټکی_3 pt);

#که_نه_تعریف_شوی NOWINOFFSETS

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_کړکۍ_Long Get_کړکۍ_Long_W
#تعریف_کړه سېټ_کړکۍ_Long سېټ_کړکۍ_Long_W
#وإلا
#تعریف_کړه Get_کړکۍ_Long Get_کړکۍ_Long_A
#تعریف_کړه سېټ_کړکۍ_Long سېټ_کړکۍ_Long_A
#د_که_پای

  WINUSERAPI کلمه_3 WINAPI Get_کړکۍ_کلمه(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI کلمه_3 WINAPI سېټ_کړکۍ_کلمه(HWND hWnd,صحيح n_شاخص,کلمه_3 w_New_کلمه);
  WINUSERAPI LONG WINAPI Get_کړکۍ_Long_A(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI LONG WINAPI Get_کړکۍ_Long_W(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI LONG WINAPI سېټ_کړکۍ_Long_A(HWND hWnd,صحيح n_شاخص,LONG dwNewLong);
  WINUSERAPI LONG WINAPI سېټ_کړکۍ_Long_W(HWND hWnd,صحيح n_شاخص,LONG dwNewLong);

#که_تعریف_شوی _WIN64

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_کړکۍ_Long_Ptr Get_کړکۍ_Long_Ptr_W
#تعریف_کړه سېټ_کړکۍ_Long_Ptr سېټ_کړکۍ_Long_Ptr_W
#وإلا
#تعریف_کړه Get_کړکۍ_Long_Ptr Get_کړکۍ_Long_Ptr_A
#تعریف_کړه سېټ_کړکۍ_Long_Ptr سېټ_کړکۍ_Long_Ptr_A
#د_که_پای

  WINUSERAPI LONG_PTR WINAPI Get_کړکۍ_Long_Ptr_A(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI LONG_PTR WINAPI Get_کړکۍ_Long_Ptr_W(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI LONG_PTR WINAPI سېټ_کړکۍ_Long_Ptr_A(HWND hWnd,صحيح n_شاخص,LONG_PTR dwNewLong);
  WINUSERAPI LONG_PTR WINAPI سېټ_کړکۍ_Long_Ptr_W(HWND hWnd,صحيح n_شاخص,LONG_PTR dwNewLong);
#وإلا

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_کړکۍ_Long_Ptr Get_کړکۍ_Long_Ptr_W
#تعریف_کړه سېټ_کړکۍ_Long_Ptr سېټ_کړکۍ_Long_Ptr_W
#وإلا
#تعریف_کړه Get_کړکۍ_Long_Ptr Get_کړکۍ_Long_Ptr_A
#تعریف_کړه سېټ_کړکۍ_Long_Ptr سېټ_کړکۍ_Long_Ptr_A
#د_که_پای

#تعریف_کړه Get_کړکۍ_Long_Ptr_A Get_کړکۍ_Long_A
#تعریف_کړه Get_کړکۍ_Long_Ptr_W Get_کړکۍ_Long_W
#تعریف_کړه سېټ_کړکۍ_Long_Ptr_A سېټ_کړکۍ_Long_A
#تعریف_کړه سېټ_کړکۍ_Long_Ptr_W سېټ_کړکۍ_Long_W
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه GetClassLong GetClassLongW
#تعریف_کړه سېټ_Class_Long سېټ_Class_Long_W
#وإلا
#تعریف_کړه GetClassLong GetClassLongA
#تعریف_کړه سېټ_Class_Long سېټ_Class_Long_A
#د_که_پای

  WINUSERAPI کلمه_3 WINAPI Get_Class_کلمه(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI کلمه_3 WINAPI سېټ_Class_کلمه(HWND hWnd,صحيح n_شاخص,کلمه_3 w_New_کلمه);
  WINUSERAPI DWORD WINAPI GetClassLongA(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI DWORD WINAPI GetClassLongW(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI DWORD WINAPI سېټ_Class_Long_A(HWND hWnd,صحيح n_شاخص,LONG dwNewLong);
  WINUSERAPI DWORD WINAPI سېټ_Class_Long_W(HWND hWnd,صحيح n_شاخص,LONG dwNewLong);

#که_تعریف_شوی _WIN64

#که_تعریف_شوی UNICODE
#تعریف_کړه GetClassLongPtr GetClassLongPtrW
#تعریف_کړه سېټ_Class_Long_Ptr سېټ_Class_Long_Ptr_W
#وإلا
#تعریف_کړه GetClassLongPtr GetClassLongPtrA
#تعریف_کړه سېټ_Class_Long_Ptr سېټ_Class_Long_Ptr_A
#د_که_پای

  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI ULONG_PTR WINAPI سېټ_Class_Long_Ptr_A(HWND hWnd,صحيح n_شاخص,LONG_PTR dwNewLong);
  WINUSERAPI ULONG_PTR WINAPI سېټ_Class_Long_Ptr_W(HWND hWnd,صحيح n_شاخص,LONG_PTR dwNewLong);
#وإلا
#که_تعریف_شوی UNICODE
#تعریف_کړه GetClassLongPtr GetClassLongPtrW
#تعریف_کړه سېټ_Class_Long_Ptr سېټ_Class_Long_Ptr_W
#وإلا
#تعریف_کړه GetClassLongPtr GetClassLongPtrA
#تعریف_کړه سېټ_Class_Long_Ptr سېټ_Class_Long_Ptr_A
#د_که_پای

#تعریف_کړه GetClassLongPtrA GetClassLongA
#تعریف_کړه GetClassLongPtrW GetClassLongW
#تعریف_کړه سېټ_Class_Long_Ptr_A سېټ_Class_Long_A
#تعریف_کړه سېټ_Class_Long_Ptr_W سېټ_Class_Long_W
#د_که_پای
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه پیدا_کړه_کړکۍ پیدا_کړه_کړکۍ_W
#تعریف_کړه پیدا_کړه_کړکۍ_Ex پیدا_کړه_کړکۍ_Ex_W
#تعریف_کړه GetClassName GetClassNameW
#وإلا
#تعریف_کړه پیدا_کړه_کړکۍ پیدا_کړه_کړکۍ_A
#تعریف_کړه پیدا_کړه_کړکۍ_Ex پیدا_کړه_کړکۍ_Ex_A
#تعریف_کړه GetClassName GetClassNameA
#د_که_پای

  WINUSERAPI WINBOOL WINAPI GetProcessDefaultLayout(DWORD *pdwDefaultLayout);
  WINUSERAPI WINBOOL WINAPI سېټ_Process_Default_Layout(DWORD dwDefaultLayout);
  WINUSERAPI HWND WINAPI Get_Desktop_کړکۍ(VOID);
  WINUSERAPI HWND WINAPI Get_پلار(HWND hWnd);
  WINUSERAPI HWND WINAPI سېټ_پلار(HWND h_Wnd_ماشوم,HWND h_Wnd_New_پلار);
  WINUSERAPI WINBOOL WINAPI Enum_ماشوم_Windows(HWND h_Wnd_پلار,WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI HWND WINAPI پیدا_کړه_کړکۍ_A(LPCSTR lpClassName,LPCSTR lp_کړکۍ_Name);
  WINUSERAPI HWND WINAPI پیدا_کړه_کړکۍ_W(LPCWSTR lpClassName,LPCWSTR lp_کړکۍ_Name);
  WINUSERAPI HWND WINAPI پیدا_کړه_کړکۍ_Ex_A(HWND h_Wnd_پلار,HWND h_Wnd_ماشوم_After,LPCSTR lpszClass,LPCSTR lpsz_کړکۍ);
  WINUSERAPI HWND WINAPI پیدا_کړه_کړکۍ_Ex_W(HWND h_Wnd_پلار,HWND h_Wnd_ماشوم_After,LPCWSTR lpszClass,LPCWSTR lpsz_کړکۍ);
  WINUSERAPI HWND WINAPI Get_Shell_کړکۍ(VOID);
  WINUSERAPI WINBOOL WINAPI ثبتوونکی_Shell_Hook_کړکۍ(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI Deregister_Shell_Hook_کړکۍ(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);

#تعریف_کړه EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(Handle_منزل_Ulong(hTask),lpfn,lParam)

  WINUSERAPI صحيح WINAPI GetClassNameA(HWND hWnd,LPSTR lpClassName,صحيح n_Max_شمېر);
  WINUSERAPI صحيح WINAPI GetClassNameW(HWND hWnd,LPWSTR lpClassName,صحيح n_Max_شمېر);
  WINUSERAPI HWND WINAPI Get_سر_کړکۍ(HWND hWnd);

#تعریف_کړه Get_بل_کړکۍ(hWnd,wCmd) Get_کړکۍ(hWnd,wCmd)
#تعریف_کړه Get_Sys_Modal_کړکۍ() (عدم)
#تعریف_کړه سېټ_Sys_Modal_کړکۍ(hWnd) (عدم)

  WINUSERAPI DWORD WINAPI Get_کړکۍ_Thread_Process_Id(HWND hWnd,LPDWORD lpdwProcessId);
  WINUSERAPI WINBOOL WINAPI IsGUIThread(WINBOOL bConvert);

#تعریف_کړه Get_کړکۍ_Task(hWnd) ((HANDLE)(DWORD_PTR)Get_کړکۍ_Thread_Process_Id(hWnd,عدم))

  WINUSERAPI HWND WINAPI Get_وروستی_فعال_Popup(HWND hWnd);

#تعریف_کړه GW_HWNDFIRST 0
#تعریف_کړه GW_HWNDLAST 1
#تعریف_کړه GW_HWNDNEXT 2
#تعریف_کړه GW_HWNDPREV 3
#تعریف_کړه GW_OWNER 4
#تعریف_کړه GW_ماشوم 5
#تعریف_کړه GW_ENABLEDPOPUP 6
#تعریف_کړه GW_MAX 6

  WINUSERAPI HWND WINAPI Get_کړکۍ(HWND hWnd,UINT uCmd);

#که_نه_تعریف_شوی NOWH

#که_تعریف_شوی UNICODE
#تعریف_کړه سېټ_Windows_Hook سېټ_Windows_Hook_W
#تعریف_کړه سېټ_Windows_Hook_Ex سېټ_Windows_Hook_Ex_W
#وإلا
#تعریف_کړه سېټ_Windows_Hook سېټ_Windows_Hook_A
#تعریف_کړه سېټ_Windows_Hook_Ex سېټ_Windows_Hook_Ex_A
#د_که_پای

  WINUSERAPI HHOOK WINAPI سېټ_Windows_Hook_A(صحيح nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI سېټ_Windows_Hook_W(صحيح nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHook(صحيح n_کوډ,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI سېټ_Windows_Hook_Ex_A(صحيح idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI HHOOK WINAPI سېټ_Windows_Hook_Ex_W(صحيح idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);
  WINUSERAPI LRESULT WINAPI Call_بل_Hook_Ex(HHOOK hhk,صحيح n_کوډ,WPARAM wParam,LPARAM lParam);
#تعریف_کړه DefHookProc(n_کوډ,wParam,lParam,phhk) Call_بل_Hook_Ex(*phhk,n_کوډ,wParam,lParam)
#د_که_پای

#که_نه_تعریف_شوی NOMENUS

#تعریف_کړه MF_ورننباسه 0x00000000L
#تعریف_کړه MF_CHANGE 0x00000080L
#تعریف_کړه MF_APPEND 0x00000100L
#تعریف_کړه MF_DELETE 0x00000200L
#تعریف_کړه MF_REMOVE 0x00001000L
#تعریف_کړه MF_BYCOMMAND 0x00000000L
#تعریف_کړه MF_BYPOSITION 0x00000400L
#تعریف_کړه MF_SEPARATOR 0x00000800L
#تعریف_کړه MF_ENABLED 0x00000000L
#تعریف_کړه MF_GRAYED 0x00000001L
#تعریف_کړه MF_DISABLED 0x00000002L
#تعریف_کړه MF_UNCHECKED 0x00000000L
#تعریف_کړه MF_CHECKED 0x00000008L
#تعریف_کړه MF_USECHECKBITMAPS 0x00000200L
#تعریف_کړه MF_STRING 0x00000000L
#تعریف_کړه MF_BITMAP 0x00000004L
#تعریف_کړه MF_OWNERDRAW 0x00000100L
#تعریف_کړه MF_POPUP 0x00000010L
#تعریف_کړه MF_MENUBARBREAK 0x00000020L
#تعریف_کړه MF_MENUBREAK 0x00000040L
#تعریف_کړه MF_UNHILITE 0x00000000L
#تعریف_کړه MF_HILITE 0x00000080L
#تعریف_کړه MF_DEFAULT 0x00001000L
#تعریف_کړه MF_SYSMENU 0x00002000L
#تعریف_کړه MF_HELP 0x00004000L
#تعریف_کړه MF_RIGHTJUSTIFY 0x00004000L
#تعریف_کړه MF_MOUSESELECT 0x00008000L
#تعریف_کړه MF_پای_ټکی 0x00000080L

#تعریف_کړه MFT_STRING MF_STRING
#تعریف_کړه MFT_BITMAP MF_BITMAP
#تعریف_کړه MFT_MENUBARBREAK MF_MENUBARBREAK
#تعریف_کړه MFT_MENUBREAK MF_MENUBREAK
#تعریف_کړه MFT_OWNERDRAW MF_OWNERDRAW
#تعریف_کړه MFT_RADIOCHECK 0x00000200L
#تعریف_کړه MFT_SEPARATOR MF_SEPARATOR
#تعریف_کړه MFT_RIGHTORDER 0x00002000L
#تعریف_کړه MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#تعریف_کړه MFS_GRAYED 0x00000003L
#تعریف_کړه MFS_DISABLED MFS_GRAYED
#تعریف_کړه MFS_CHECKED MF_CHECKED
#تعریف_کړه MFS_HILITE MF_HILITE
#تعریف_کړه MFS_ENABLED MF_ENABLED
#تعریف_کړه MFS_UNCHECKED MF_UNCHECKED
#تعریف_کړه MFS_UNHILITE MF_UNHILITE
#تعریف_کړه MFS_DEFAULT MF_DEFAULT

  WINUSERAPI WINBOOL WINAPI Check_Menu_Radio_توکی(HMENU hmenu,UINT لومړی,UINT وروستی,UINT check,UINT flags);

  تعريفنوع بنية {
    کلمه_3 نسخه_شمېره;
    کلمه_3 دننه_واټن;
  } MENUITEMTEMPLATEHEADER,*PMENUITEMTEMPLATEHEADER;

  تعريفنوع بنية {
    کلمه_3 mtOption;
    کلمه_3 mtID;
    WCHAR mtString[1];
  } MENUITEMTEMPLATE,*PMENUITEMTEMPLATE;
#تعریف_کړه MF_پای_ټکی 0x00000080L
#د_که_پای

#که_نه_تعریف_شوی NOSYSCOMMANDS

#تعریف_کړه SC_اندازه 0xF000
#تعریف_کړه SC_MOVE 0xF010
#تعریف_کړه SC_MINIMIZE 0xF020
#تعریف_کړه SC_MAXIMIZE 0xF030
#تعریف_کړه SC_NEXTWINDOW 0xF040
#تعریف_کړه SC_PREVWINDOW 0xF050
#تعریف_کړه SC_CLOSE 0xF060
#تعریف_کړه SC_VSCROLL 0xF070
#تعریف_کړه SC_HSCROLL 0xF080
#تعریف_کړه SC_MOUSEMENU 0xF090
#تعریف_کړه SC_KEYMENU 0xF100
#تعریف_کړه SC_ARRANGE 0xF110
#تعریف_کړه SC_RESTORE 0xF120
#تعریف_کړه SC_TASKLIST 0xF130
#تعریف_کړه SC_SCREENSAVE 0xF140
#تعریف_کړه SC_HOTKEY 0xF150
#تعریف_کړه SC_DEFAULT 0xF160
#تعریف_کړه SC_MONITORPOWER 0xF170
#تعریف_کړه SC_CONTEXTHELP 0xF180
#تعریف_کړه SC_SEPARATOR 0xF00F
#تعریف_کړه SC_ICON SC_MINIMIZE
#تعریف_کړه SC_ZOOM SC_MAXIMIZE
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه بارول_Bitmap بارول_Bitmap_W
#تعریف_کړه بارول_Cursor بارول_Cursor_W
#تعریف_کړه بارول_Cursor_From_File بارول_Cursor_From_File_W
#وإلا
#تعریف_کړه بارول_Bitmap بارول_Bitmap_A
#تعریف_کړه بارول_Cursor بارول_Cursor_A
#تعریف_کړه بارول_Cursor_From_File بارول_Cursor_From_File_A
#د_که_پای

  WINUSERAPI HBITMAP WINAPI بارول_Bitmap_A(HINSTANCE hInstance,LPCSTR lpBitmapName);
  WINUSERAPI HBITMAP WINAPI بارول_Bitmap_W(HINSTANCE hInstance,LPCWSTR lpBitmapName);
  WINUSERAPI HCURSOR WINAPI بارول_Cursor_A(HINSTANCE hInstance,LPCSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI بارول_Cursor_W(HINSTANCE hInstance,LPCWSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI بارول_Cursor_From_File_A(LPCSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI بارول_Cursor_From_File_W(LPCWSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI CreateCursor(HINSTANCE hInst,صحيح xHotSpot,صحيح yHotSpot,صحيح n_پلنوالی,صحيح n_لوړوالی,CONST VOID *pvANDPlane,CONST VOID *pvXORPlane);
  WINUSERAPI WINBOOL WINAPI DestroyCursor(HCURSOR hCursor);

#تعریف_کړه CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

#تعریف_کړه IDC_ARROW MAKEINTRESOURCE(32512)
#تعریف_کړه IDC_IBEAM MAKEINTRESOURCE(32513)
#تعریف_کړه IDC_WAIT MAKEINTRESOURCE(32514)
#تعریف_کړه IDC_CROSS MAKEINTRESOURCE(32515)
#تعریف_کړه IDC_UPARROW MAKEINTRESOURCE(32516)
#تعریف_کړه IDC_اندازه MAKEINTRESOURCE(32640)
#تعریف_کړه IDC_ICON MAKEINTRESOURCE(32641)
#تعریف_کړه IDC_SIZENWSE MAKEINTRESOURCE(32642)
#تعریف_کړه IDC_SIZENESW MAKEINTRESOURCE(32643)
#تعریف_کړه IDC_SIZEWE MAKEINTRESOURCE(32644)
#تعریف_کړه IDC_SIZENS MAKEINTRESOURCE(32645)
#تعریف_کړه IDC_SIZEALL MAKEINTRESOURCE(32646)
#تعریف_کړه IDC_NO MAKEINTRESOURCE(32648)
#تعریف_کړه IDC_HAND MAKEINTRESOURCE(32649)
#تعریف_کړه IDC_APPSTARTING MAKEINTRESOURCE(32650)
#تعریف_کړه IDC_HELP MAKEINTRESOURCE(32651)

  WINUSERAPI WINBOOL WINAPI سېټ_System_Cursor(HCURSOR hcur,DWORD id);

  تعريفنوع بنية _ICONINFO {
    WINBOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbm_ماسک;
    HBITMAP hbmColor;
  } ICONINFO;
  تعريفنوع ICONINFO *PICONINFO;

#که_تعریف_شوی UNICODE
#تعریف_کړه بارول_Icon بارول_Icon_W
#تعریف_کړه شخصي_ایستل_Icons شخصي_ایستل_Icons_W
#وإلا
#تعریف_کړه بارول_Icon بارول_Icon_A
#تعریف_کړه شخصي_ایستل_Icons شخصي_ایستل_Icons_A
#د_که_پای

  WINUSERAPI HICON WINAPI بارول_Icon_A(HINSTANCE hInstance,LPCSTR lpIconName);
  WINUSERAPI HICON WINAPI بارول_Icon_W(HINSTANCE hInstance,LPCWSTR lpIconName);
  WINUSERAPI UINT WINAPI شخصي_ایستل_Icons_A(LPCSTR szFileName,صحيح n_Icon_شاخص,صحيح cxIcon,صحيح cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI UINT WINAPI شخصي_ایستل_Icons_W(LPCWSTR szFileName,صحيح n_Icon_شاخص,صحيح cxIcon,صحيح cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI HICON WINAPI CreateIcon(HINSTANCE hInstance,صحيح n_پلنوالی,صحيح n_لوړوالی,BYTE cPlanes,BYTE c_بټونه_Pixel,CONST BYTE *lpbANDbits,CONST BYTE *lpbXORbits);
  WINUSERAPI WINBOOL WINAPI DestroyIcon(HICON hIcon);
  WINUSERAPI صحيح WINAPI LookupIconIdFromDirectory(PBYTE presbits,WINBOOL fIcon);
  WINUSERAPI صحيح WINAPI LookupIconIdFromDirectoryEx(PBYTE presbits,WINBOOL fIcon,صحيح cxDesired,صحيح cyDesired,UINT Flags);
  WINUSERAPI HICON WINAPI CreateIconFromResource(PBYTE presbits,DWORD dw_Res_اندازه,WINBOOL fIcon,DWORD dwVer);
  WINUSERAPI HICON WINAPI CreateIconFromResourceEx(PBYTE presbits,DWORD dw_Res_اندازه,WINBOOL fIcon,DWORD dwVer,صحيح cxDesired,صحيح cyDesired,UINT Flags);

  تعريفنوع بنية نښان_CURSORSHAPE {
    صحيح xHotSpot;
    صحيح yHotSpot;
    صحيح cx;
    صحيح cy;
    صحيح cb_پلنوالی;
    BYTE Planes;
    BYTE بټونه_Pixel;
  } CURSORSHAPE,*LPCURSORSHAPE;

#تعریف_کړه IMAGE_BITMAP 0
#تعریف_کړه IMAGE_ICON 1
#تعریف_کړه IMAGE_CURSOR 2
#تعریف_کړه IMAGE_ENHMETAFILE 3

#تعریف_کړه LR_DEFAULTCOLOR 0x0000
#تعریف_کړه LR_MONOCHROME 0x0001
#تعریف_کړه LR_COLOR 0x0002
#تعریف_کړه LR_COPYRETURNORG 0x0004
#تعریف_کړه LR_COPYDELETEORG 0x0008
#تعریف_کړه LR_LOADFROMFILE 0x0010
#تعریف_کړه LR_LOADTRANSPARENT 0x0020
#تعریف_کړه LR_DEFAULTSIZE 0x0040
#تعریف_کړه LR_VGACOLOR 0x0080
#تعریف_کړه LR_LOADMAP3DCOLORS 0x1000
#تعریف_کړه LR_CREATEDIBSECTION 0x2000
#تعریف_کړه LR_COPYFROMRESOURCE 0x4000
#تعریف_کړه LR_SHARED 0x8000

#که_تعریف_شوی UNICODE
#تعریف_کړه بارول_Image بارول_Image_W
#وإلا
#تعریف_کړه بارول_Image بارول_Image_A
#د_که_پای

  WINUSERAPI HANDLE WINAPI بارول_Image_A(HINSTANCE hInst,LPCSTR name,UINT type,صحيح cx,صحيح cy,UINT fu_بارول);
  WINUSERAPI HANDLE WINAPI بارول_Image_W(HINSTANCE hInst,LPCWSTR name,UINT type,صحيح cx,صحيح cy,UINT fu_بارول);
  WINUSERAPI HANDLE WINAPI CopyImage(HANDLE h,UINT type,صحيح cx,صحيح cy,UINT flags);

#تعریف_کړه DI_ماسک 0x0001
#تعریف_کړه DI_IMAGE 0x0002
#تعریف_کړه DI_نورمال 0x0003
#تعریف_کړه DI_COMPAT 0x0004
#تعریف_کړه DI_DEFAULTSIZE 0x0008
#تعریف_کړه DI_NOMIRROR 0x0010

  WINUSERAPI WINBOOL WINAPI DrawIconEx(HDC hdc,صحيح x_کیڼ,صحيح y_سر,HICON hIcon,صحيح cx_پلنوالی,صحيح cy_پلنوالی,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
  WINUSERAPI HICON WINAPI Create_Icon_غیرمستقیم(PICONINFO piconinfo);
  WINUSERAPI HICON WINAPI CopyIcon(HICON hIcon);
  WINUSERAPI WINBOOL WINAPI GetIconInfo(HICON hIcon,PICONINFO piconinfo);

#تعریف_کړه RES_ICON 1
#تعریف_کړه RES_CURSOR 2

#که_تعریف_شوی OEMRESOURCE

#تعریف_کړه OBM_CLOSE 32754
#تعریف_کړه OBM_UPARROW 32753
#تعریف_کړه OBM_DNARROW 32752
#تعریف_کړه OBM_RGARROW 32751
#تعریف_کړه OBM_LFARROW 32750
#تعریف_کړه OBM_REDUCE 32749
#تعریف_کړه OBM_ZOOM 32748
#تعریف_کړه OBM_RESTORE 32747
#تعریف_کړه OBM_REDUCED 32746
#تعریف_کړه OBM_ZOOMD 32745
#تعریف_کړه OBM_RESTORED 32744
#تعریف_کړه OBM_UPARROWD 32743
#تعریف_کړه OBM_DNARROWD 32742
#تعریف_کړه OBM_RGARROWD 32741
#تعریف_کړه OBM_LFARROWD 32740
#تعریف_کړه OBM_MNARROW 32739
#تعریف_کړه OBM_COMBO 32738
#تعریف_کړه OBM_UPARROWI 32737
#تعریف_کړه OBM_DNARROWI 32736
#تعریف_کړه OBM_RGARROWI 32735
#تعریف_کړه OBM_LFARROWI 32734

#تعریف_کړه OBM_OLD_CLOSE 32767
#تعریف_کړه OBM_اندازه 32766
#تعریف_کړه OBM_OLD_UPARROW 32765
#تعریف_کړه OBM_OLD_DNARROW 32764
#تعریف_کړه OBM_OLD_RGARROW 32763
#تعریف_کړه OBM_OLD_LFARROW 32762
#تعریف_کړه OBM_BTSIZE 32761
#تعریف_کړه OBM_CHECK 32760
#تعریف_کړه OBM_CHECKBOXES 32759
#تعریف_کړه OBM_BTNCORNERS 32758
#تعریف_کړه OBM_OLD_REDUCE 32757
#تعریف_کړه OBM_OLD_ZOOM 32756
#تعریف_کړه OBM_OLD_RESTORE 32755

#تعریف_کړه OCR_نورمال 32512
#تعریف_کړه OCR_IBEAM 32513
#تعریف_کړه OCR_WAIT 32514
#تعریف_کړه OCR_CROSS 32515
#تعریف_کړه OCR_پورته 32516
#تعریف_کړه OCR_اندازه 32640
#تعریف_کړه OCR_ICON 32641
#تعریف_کړه OCR_SIZENWSE 32642
#تعریف_کړه OCR_SIZENESW 32643
#تعریف_کړه OCR_SIZEWE 32644
#تعریف_کړه OCR_SIZENS 32645
#تعریف_کړه OCR_SIZEALL 32646
#تعریف_کړه OCR_ICOCUR 32647
#تعریف_کړه OCR_NO 32648
#تعریف_کړه OCR_HAND 32649
#تعریف_کړه OCR_APPSTARTING 32650

#تعریف_کړه OIC_SAMPLE 32512
#تعریف_کړه OIC_HAND 32513
#تعریف_کړه OIC_QUES 32514
#تعریف_کړه OIC_BANG 32515
#تعریف_کړه OIC_NOTE 32516
#تعریف_کړه OIC_WINLOGO 32517
#تعریف_کړه OIC_WARNING OIC_BANG
#تعریف_کړه OIC_ERROR OIC_HAND
#تعریف_کړه OIC_INFORMATION OIC_NOTE
#د_که_پای

#تعریف_کړه ORD_LANGDRIVER 1

#که_نه_تعریف_شوی NOICONS

#که_تعریف_شوی RC_INVOKED
#تعریف_کړه IDI_APPLICATION 32512
#تعریف_کړه IDI_HAND 32513
#تعریف_کړه IDI_QUESTION 32514
#تعریف_کړه IDI_EXCLAMATION 32515
#تعریف_کړه IDI_ASTERISK 32516
#تعریف_کړه IDI_WINLOGO 32517
#وإلا
#تعریف_کړه IDI_APPLICATION MAKEINTRESOURCE(32512)
#تعریف_کړه IDI_HAND MAKEINTRESOURCE(32513)
#تعریف_کړه IDI_QUESTION MAKEINTRESOURCE(32514)
#تعریف_کړه IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#تعریف_کړه IDI_ASTERISK MAKEINTRESOURCE(32516)
#تعریف_کړه IDI_WINLOGO MAKEINTRESOURCE(32517)
#د_که_پای

#تعریف_کړه IDI_WARNING IDI_EXCLAMATION
#تعریف_کړه IDI_ERROR IDI_HAND
#تعریف_کړه IDI_INFORMATION IDI_ASTERISK
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه بارول_String بارول_String_W
#وإلا
#تعریف_کړه بارول_String بارول_String_A
#د_که_پای

  WINUSERAPI صحيح WINAPI بارول_String_A(HINSTANCE hInstance,UINT uID,LPSTR lp_بفر,صحيح cch_بفر_Max);
  WINUSERAPI صحيح WINAPI بارول_String_W(HINSTANCE hInstance,UINT uID,LPWSTR lp_بفر,صحيح cch_بفر_Max);

#تعریف_کړه IDOK 1
#تعریف_کړه IDCANCEL 2
#تعریف_کړه IDABORT 3
#تعریف_کړه IDRETRY 4
#تعریف_کړه IDIGNORE 5
#تعریف_کړه IDYES 6
#تعریف_کړه IDNO 7
#تعریف_کړه IDCLOSE 8
#تعریف_کړه IDHELP 9
#تعریف_کړه IDTRYAGAIN 10
#تعریف_کړه IDCONTINUE 11

#که_نه_تعریف_شوی IDTIMEOUT
#تعریف_کړه IDTIMEOUT 32000
#د_که_پای

#که_نه_تعریف_شوی NOCTLMGR

#که_نه_تعریف_شوی NOWINSTYLES
#تعریف_کړه ES_کیڼ 0x0000L
#تعریف_کړه ES_CENTER 0x0001L
#تعریف_کړه ES_ښی 0x0002L
#تعریف_کړه ES_MULTILINE 0x0004L
#تعریف_کړه ES_UPPERCASE 0x0008L
#تعریف_کړه ES_LOWERCASE 0x0010L
#تعریف_کړه ES_PASSWORD 0x0020L
#تعریف_کړه ES_AUTOVSCROLL 0x0040L
#تعریف_کړه ES_AUTOHSCROLL 0x0080L
#تعریف_کړه ES_NOHIDESEL 0x0100L
#تعریف_کړه ES_OEMCONVERT 0x0400L
#تعریف_کړه ES_READONLY 0x0800L
#تعریف_کړه ES_WANTRETURN 0x1000L
#تعریف_کړه ES_شمېره 0x2000L
#د_که_پای

#تعریف_کړه EN_SETFOCUS 0x0100
#تعریف_کړه EN_KILLFOCUS 0x0200
#تعریف_کړه EN_CHANGE 0x0300
#تعریف_کړه EN_UPDATE 0x0400
#تعریف_کړه EN_ERRSPACE 0x0500
#تعریف_کړه EN_MAXTEXT 0x0501
#تعریف_کړه EN_HSCROLL 0x0601
#تعریف_کړه EN_VSCROLL 0x0602
#تعریف_کړه EN_ALIGN_LTR_EC 0x0700
#تعریف_کړه EN_ALIGN_RTL_EC 0x0701

#تعریف_کړه EC_LEFTMARGIN 0x0001
#تعریف_کړه EC_RIGHTMARGIN 0x0002
#تعریف_کړه EC_USEFONTINFO 0xffff

#تعریف_کړه EMSIS_COMPOSITIONSTRING 0x0001

#تعریف_کړه EIMES_GETCOMPSTRATONCE 0x0001
#تعریف_کړه EIMES_CANCELCOMPSTRINFOCUS 0x0002
#تعریف_کړه EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#که_نه_تعریف_شوی NOWINMESSAGES

#تعریف_کړه EM_GETSEL 0x00B0
#تعریف_کړه EM_SETSEL 0x00B1
#تعریف_کړه EM_GETRECT 0x00B2
#تعریف_کړه EM_SETRECT 0x00B3
#تعریف_کړه EM_SETRECTNP 0x00B4
#تعریف_کړه EM_SCROLL 0x00B5
#تعریف_کړه EM_LINESCROLL 0x00B6
#تعریف_کړه EM_SCROLLCARET 0x00B7
#تعریف_کړه EM_GETMODIFY 0x00B8
#تعریف_کړه EM_SETMODIFY 0x00B9
#تعریف_کړه EM_GETLINECOUNT 0x00BA
#تعریف_کړه EM_LINEINDEX 0x00BB
#تعریف_کړه EM_SETHANDLE 0x00BC
#تعریف_کړه EM_GETHANDLE 0x00BD
#تعریف_کړه EM_GETTHUMB 0x00BE
#تعریف_کړه EM_LINELENGTH 0x00C1
#تعریف_کړه EM_REPLACESEL 0x00C2
#تعریف_کړه EM_GETLINE 0x00C4
#تعریف_کړه EM_LIMITTEXT 0x00C5
#تعریف_کړه EM_CANUNDO 0x00C6
#تعریف_کړه EM_UNDO 0x00C7
#تعریف_کړه EM_FMTLINES 0x00C8
#تعریف_کړه EM_LINEFROMCHAR 0x00C9
#تعریف_کړه EM_SETTABSTOPS 0x00CB
#تعریف_کړه EM_SETPASSWORDCHAR 0x00CC
#تعریف_کړه EM_EMPTYUNDOBUFFER 0x00CD
#تعریف_کړه EM_GETFIRSTVISIBLELINE 0x00CE
#تعریف_کړه EM_SETREADONLY 0x00CF
#تعریف_کړه EM_SETWORDBREAKPROC 0x00D0
#تعریف_کړه EM_GETWORDBREAKPROC 0x00D1
#تعریف_کړه EM_GETPASSWORDCHAR 0x00D2
#تعریف_کړه EM_SETMARGINS 0x00D3
#تعریف_کړه EM_GETMARGINS 0x00D4
#تعریف_کړه EM_SETLIMITTEXT EM_LIMITTEXT
#تعریف_کړه EM_GETLIMITTEXT 0x00D5
#تعریف_کړه EM_POSFROMCHAR 0x00D6
#تعریف_کړه EM_CHARFROMPOS 0x00D7
#تعریف_کړه EM_SETIMESTATUS 0x00D8
#تعریف_کړه EM_GETIMESTATUS 0x00D9
#د_که_پای

#تعریف_کړه WB_کیڼ 0
#تعریف_کړه WB_ښی 1
#تعریف_کړه WB_ISDELIMITER 2

#تعریف_کړه BS_PUSHBUTTON 0x00000000L
#تعریف_کړه BS_DEFPUSHBUTTON 0x00000001L
#تعریف_کړه BS_CHECKBOX 0x00000002L
#تعریف_کړه BS_AUTOCHECKBOX 0x00000003L
#تعریف_کړه BS_RADIOBUTTON 0x00000004L
#تعریف_کړه BS_3STATE 0x00000005L
#تعریف_کړه BS_AUTO3STATE 0x00000006L
#تعریف_کړه BS_GROUPBOX 0x00000007L
#تعریف_کړه BS_USERBUTTON 0x00000008L
#تعریف_کړه BS_AUTORADIOBUTTON 0x00000009L
#تعریف_کړه BS_PUSHBOX 0x0000000AL
#تعریف_کړه BS_OWNERDRAW 0x0000000BL
#تعریف_کړه BS_TYPEMASK 0x0000000FL
#تعریف_کړه BS_LEFTTEXT 0x00000020L
#تعریف_کړه BS_متن 0x00000000L
#تعریف_کړه BS_ICON 0x00000040L
#تعریف_کړه BS_BITMAP 0x00000080L
#تعریف_کړه BS_کیڼ 0x00000100L
#تعریف_کړه BS_ښی 0x00000200L
#تعریف_کړه BS_CENTER 0x00000300L
#تعریف_کړه BS_سر 0x00000400L
#تعریف_کړه BS_BOTTOM 0x00000800L
#تعریف_کړه BS_VCENTER 0x00000C00L
#تعریف_کړه BS_PUSHLIKE 0x00001000L
#تعریف_کړه BS_MULTILINE 0x00002000L
#تعریف_کړه BS_NOTIFY 0x00004000L
#تعریف_کړه BS_FLAT 0x00008000L
#تعریف_کړه BS_RIGHTBUTTON BS_LEFTTEXT

#تعریف_کړه BN_CLICKED 0
#تعریف_کړه BN_PAINT 1
#تعریف_کړه BN_HILITE 2
#تعریف_کړه BN_UNHILITE 3
#تعریف_کړه BN_DISABLE 4
#تعریف_کړه BN_DOUBLECLICKED 5
#تعریف_کړه BN_PUSHED BN_HILITE
#تعریف_کړه BN_UNPUSHED BN_UNHILITE
#تعریف_کړه BN_DBLCLK BN_DOUBLECLICKED
#تعریف_کړه BN_SETFOCUS 6
#تعریف_کړه BN_KILLFOCUS 7

#تعریف_کړه BM_GETCHECK 0x00F0
#تعریف_کړه BM_SETCHECK 0x00F1
#تعریف_کړه BM_GETSTATE 0x00F2
#تعریف_کړه BM_SETSTATE 0x00F3
#تعریف_کړه BM_SETSTYLE 0x00F4
#تعریف_کړه BM_CLICK 0x00F5
#تعریف_کړه BM_GETIMAGE 0x00F6
#تعریف_کړه BM_SETIMAGE 0x00F7

#تعریف_کړه BST_UNCHECKED 0x0000
#تعریف_کړه BST_CHECKED 0x0001
#تعریف_کړه BST_INDETERMINATE 0x0002
#تعریف_کړه BST_PUSHED 0x0004
#تعریف_کړه BST_FOCUS 0x0008

#تعریف_کړه SS_کیڼ 0x00000000L
#تعریف_کړه SS_CENTER 0x00000001L
#تعریف_کړه SS_ښی 0x00000002L
#تعریف_کړه SS_ICON 0x00000003L
#تعریف_کړه SS_BLACKRECT 0x00000004L
#تعریف_کړه SS_GRAYRECT 0x00000005L
#تعریف_کړه SS_WHITERECT 0x00000006L
#تعریف_کړه SS_BLACKFRAME 0x00000007L
#تعریف_کړه SS_GRAYFRAME 0x00000008L
#تعریف_کړه SS_WHITEFRAME 0x00000009L
#تعریف_کړه SS_USERITEM 0x0000000AL
#تعریف_کړه SS_SIMPLE 0x0000000BL
#تعریف_کړه SS_LEFTNOWORDWRAP 0x0000000CL
#تعریف_کړه SS_OWNERDRAW 0x0000000DL
#تعریف_کړه SS_BITMAP 0x0000000EL
#تعریف_کړه SS_ENHMETAFILE 0x0000000FL
#تعریف_کړه SS_ETCHEDHORZ 0x00000010L
#تعریف_کړه SS_ETCHEDVERT 0x00000011L
#تعریف_کړه SS_ETCHEDFRAME 0x00000012L
#تعریف_کړه SS_TYPEMASK 0x0000001FL
#تعریف_کړه SS_REALSIZECONTROL 0x00000040L
#تعریف_کړه SS_NOPREFIX 0x00000080L
#تعریف_کړه SS_NOTIFY 0x00000100L
#تعریف_کړه SS_CENTERIMAGE 0x00000200L
#تعریف_کړه SS_RIGHTJUST 0x00000400L
#تعریف_کړه SS_REALSIZEIMAGE 0x00000800L
#تعریف_کړه SS_SUNKEN 0x00001000L
#تعریف_کړه SS_EDITCONTROL 0x00002000L
#تعریف_کړه SS_ENDELLIPSIS 0x00004000L
#تعریف_کړه SS_PATHELLIPSIS 0x00008000L
#تعریف_کړه SS_WORDELLIPSIS 0x0000C000L
#تعریف_کړه SS_ELLIPSISMASK 0x0000C000L

#که_نه_تعریف_شوی NOWINMESSAGES

#تعریف_کړه STM_SETICON 0x0170
#تعریف_کړه STM_GETICON 0x0171
#تعریف_کړه STM_SETIMAGE 0x0172
#تعریف_کړه STM_GETIMAGE 0x0173
#تعریف_کړه STN_CLICKED 0
#تعریف_کړه STN_DBLCLK 1
#تعریف_کړه STN_ENABLE 2
#تعریف_کړه STN_DISABLE 3
#تعریف_کړه STM_MSGMAX 0x0174
#د_که_پای

#تعریف_کړه WC_DIALOG (MAKEINTATOM(0x8002))

#تعریف_کړه DWL_MSGRESULT 0
#تعریف_کړه DWL_DLGPROC 4
#تعریف_کړه DWL_USER 8

#که_تعریف_شوی _WIN64

#تعریف_لغوه DWL_MSGRESULT
#تعریف_لغوه DWL_DLGPROC
#تعریف_لغوه DWL_USER
#د_که_پای

#تعریف_کړه DWLP_MSGRESULT 0
#تعریف_کړه DWLP_DLGPROC DWLP_MSGRESULT + حجم(LRESULT)
#تعریف_کړه DWLP_USER DWLP_DLGPROC + حجم(DLGPROC)

#که_نه_تعریف_شوی NOMSG

#که_تعریف_شوی UNICODE
#تعریف_کړه Is_Dialog_پیغام Is_Dialog_پیغام_W
#وإلا
#تعریف_کړه Is_Dialog_پیغام Is_Dialog_پیغام_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI Is_Dialog_پیغام_A(HWND hDlg,LPMSG lp_پیغام_2);
  WINUSERAPI WINBOOL WINAPI Is_Dialog_پیغام_W(HWND hDlg,LPMSG lp_پیغام_2);
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه DlgDirList DlgDirListW
#تعریف_کړه DlgDirSelectEx DlgDirSelectExW
#تعریف_کړه DlgDirListComboBox DlgDirListComboBoxW
#تعریف_کړه DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#وإلا
#تعریف_کړه DlgDirList DlgDirListA
#تعریف_کړه DlgDirSelectEx DlgDirSelectExA
#تعریف_کړه DlgDirListComboBox DlgDirListComboBoxA
#تعریف_کړه DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#د_که_پای

  WINUSERAPI WINBOOL WINAPI MapDialogRect(HWND hDlg,LPRECT lpRect);
  WINUSERAPI صحيح WINAPI DlgDirListA(HWND hDlg,LPSTR lp_لار_Spec,صحيح nIDListBox,صحيح n_IDStatic_لار,UINT uFileType);
  WINUSERAPI صحيح WINAPI DlgDirListW(HWND hDlg,LPWSTR lp_لار_Spec,صحيح nIDListBox,صحيح n_IDStatic_لار,UINT uFileType);

#تعریف_کړه DDL_READWRITE 0x0000
#تعریف_کړه DDL_READONLY 0x0001
#تعریف_کړه DDL_HIDDEN 0x0002
#تعریف_کړه DDL_SYSTEM 0x0004
#تعریف_کړه DDL_DIRECTORY 0x0010
#تعریف_کړه DDL_ARCHIVE 0x0020

#تعریف_کړه DDL_POSTMSGS 0x2000
#تعریف_کړه DDL_DRIVES 0x4000
#تعریف_کړه DDL_EXCLUSIVE 0x8000

  WINUSERAPI WINBOOL WINAPI DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,صحيح ch_شمېر,صحيح idListBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,صحيح ch_شمېر,صحيح idListBox);
  WINUSERAPI صحيح WINAPI DlgDirListComboBoxA(HWND hDlg,LPSTR lp_لار_Spec,صحيح nIDComboBox,صحيح n_IDStatic_لار,UINT uFiletype);
  WINUSERAPI صحيح WINAPI DlgDirListComboBoxW(HWND hDlg,LPWSTR lp_لار_Spec,صحيح nIDComboBox,صحيح n_IDStatic_لار,UINT uFiletype);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,صحيح cch_بهر,صحيح idComboBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,صحيح cch_بهر,صحيح idComboBox);

#تعریف_کړه DS_ABSALIGN 0x01L
#تعریف_کړه DS_SYSMODAL 0x02L
#تعریف_کړه DS_LOCALEDIT 0x20L
#تعریف_کړه DS_SETFONT 0x40L
#تعریف_کړه DS_MODALFRAME 0x80L
#تعریف_کړه DS_NOIDLEMSG 0x100L
#تعریف_کړه DS_SETFOREGROUND 0x200L

#تعریف_کړه DS_3DLOOK 0x0004L
#تعریف_کړه DS_FIXEDSYS 0x0008L
#تعریف_کړه DS_NOFAILCREATE 0x0010L
#تعریف_کړه DS_CONTROL 0x0400L
#تعریف_کړه DS_CENTER 0x0800L
#تعریف_کړه DS_CENTERMOUSE 0x1000L
#تعریف_کړه DS_CONTEXTHELP 0x2000L

#تعریف_کړه DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#إذا(_WIN32_WCE >= 0x0500)
#تعریف_کړه DS_USEPIXELS 0x8000L
#د_که_پای

#تعریف_کړه DM_GETDEFID (WM_USER+0)
#تعریف_کړه DM_SETDEFID (WM_USER+1)
#تعریف_کړه DM_REPOSITION (WM_USER+2)

#تعریف_کړه DC_HASDEFID 0x534B

#تعریف_کړه DLGC_WANTARROWS 0x0001
#تعریف_کړه DLGC_WANTTAB 0x0002
#تعریف_کړه DLGC_WANTALLKEYS 0x0004
#تعریف_کړه DLGC_WANTMESSAGE 0x0004
#تعریف_کړه DLGC_HASSETSEL 0x0008
#تعریف_کړه DLGC_DEFPUSHBUTTON 0x0010
#تعریف_کړه DLGC_UNDEFPUSHBUTTON 0x0020
#تعریف_کړه DLGC_RADIOBUTTON 0x0040
#تعریف_کړه DLGC_WANTCHARS 0x0080
#تعریف_کړه DLGC_STATIC 0x0100
#تعریف_کړه DLGC_BUTTON 0x2000

#تعریف_کړه LB_CTLCODE 0L

#تعریف_کړه LB_OKAY 0
#تعریف_کړه LB_ERR (-1)
#تعریف_کړه LB_ERRSPACE (-2)

#تعریف_کړه LBN_ERRSPACE (-2)
#تعریف_کړه LBN_SELCHANGE 1
#تعریف_کړه LBN_DBLCLK 2
#تعریف_کړه LBN_SELCANCEL 3
#تعریف_کړه LBN_SETFOCUS 4
#تعریف_کړه LBN_KILLFOCUS 5

#که_نه_تعریف_شوی NOWINMESSAGES

#تعریف_کړه LB_ADDSTRING 0x0180
#تعریف_کړه LB_INSERTSTRING 0x0181
#تعریف_کړه LB_DELETESTRING 0x0182
#تعریف_کړه LB_SELITEMRANGEEX 0x0183
#تعریف_کړه LB_RESETCONTENT 0x0184
#تعریف_کړه LB_SETSEL 0x0185
#تعریف_کړه LB_SETCURSEL 0x0186
#تعریف_کړه LB_GETSEL 0x0187
#تعریف_کړه LB_GETCURSEL 0x0188
#تعریف_کړه LB_GETTEXT 0x0189
#تعریف_کړه LB_GETTEXTLEN 0x018A
#تعریف_کړه LB_GETCOUNT 0x018B
#تعریف_کړه LB_SELECTSTRING 0x018C
#تعریف_کړه LB_DIR 0x018D
#تعریف_کړه LB_GETTOPINDEX 0x018E
#تعریف_کړه LB_FINDSTRING 0x018F
#تعریف_کړه LB_GETSELCOUNT 0x0190
#تعریف_کړه LB_GETSELITEMS 0x0191
#تعریف_کړه LB_SETTABSTOPS 0x0192
#تعریف_کړه LB_GETHORIZONTALEXTENT 0x0193
#تعریف_کړه LB_SETHORIZONTALEXTENT 0x0194
#تعریف_کړه LB_SETCOLUMNWIDTH 0x0195
#تعریف_کړه LB_ADDFILE 0x0196
#تعریف_کړه LB_SETTOPINDEX 0x0197
#تعریف_کړه LB_GETITEMRECT 0x0198
#تعریف_کړه LB_GETITEMDATA 0x0199
#تعریف_کړه LB_SETITEMDATA 0x019A
#تعریف_کړه LB_SELITEMRANGE 0x019B
#تعریف_کړه LB_SETANCHORINDEX 0x019C
#تعریف_کړه LB_GETANCHORINDEX 0x019D
#تعریف_کړه LB_SETCARETINDEX 0x019E
#تعریف_کړه LB_GETCARETINDEX 0x019F
#تعریف_کړه LB_SETITEMHEIGHT 0x01A0
#تعریف_کړه LB_GETITEMHEIGHT 0x01A1
#تعریف_کړه LB_FINDSTRINGEXACT 0x01A2
#تعریف_کړه LB_SETLOCALE 0x01A5
#تعریف_کړه LB_GETLOCALE 0x01A6
#تعریف_کړه LB_SETCOUNT 0x01A7
#تعریف_کړه LB_INITSTORAGE 0x01A8
#تعریف_کړه LB_ITEMFROMPOINT 0x01A9
#إذا(_WIN32_WCE >= 0x0400)
#تعریف_کړه LB_MULTIPLEADDSTRING 0x01B1
#د_که_پای
#تعریف_کړه LB_GETLISTBOXINFO 0x01B2
#تعریف_کړه LB_MSGMAX 0x01B3
#د_که_پای

#که_نه_تعریف_شوی NOWINSTYLES

#تعریف_کړه LBS_NOTIFY 0x0001L
#تعریف_کړه LBS_ترتیبول 0x0002L
#تعریف_کړه LBS_NOREDRAW 0x0004L
#تعریف_کړه LBS_MULTIPLESEL 0x0008L
#تعریف_کړه LBS_OWNERDRAWFIXED 0x0010L
#تعریف_کړه LBS_OWNERDRAWVARIABLE 0x0020L
#تعریف_کړه LBS_HASSTRINGS 0x0040L
#تعریف_کړه LBS_USETABSTOPS 0x0080L
#تعریف_کړه LBS_NOINTEGRALHEIGHT 0x0100L
#تعریف_کړه LBS_MULTICOLUMN 0x0200L
#تعریف_کړه LBS_WANTKEYBOARDINPUT 0x0400L
#تعریف_کړه LBS_EXTENDEDSEL 0x0800L
#تعریف_کړه LBS_DISABLENOSCROLL 0x1000L
#تعریف_کړه LBS_NODATA 0x2000L
#تعریف_کړه LBS_NOSEL 0x4000L
#تعریف_کړه LBS_COMBOBOX 0x8000L

#تعریف_کړه LBS_STANDARD (LBS_NOTIFY | LBS_ترتیبول | WS_VSCROLL | WS_BORDER)
#د_که_پای

#تعریف_کړه CB_OKAY 0
#تعریف_کړه CB_ERR (-1)
#تعریف_کړه CB_ERRSPACE (-2)

#تعریف_کړه CBN_ERRSPACE (-1)
#تعریف_کړه CBN_SELCHANGE 1
#تعریف_کړه CBN_DBLCLK 2
#تعریف_کړه CBN_SETFOCUS 3
#تعریف_کړه CBN_KILLFOCUS 4
#تعریف_کړه CBN_EDITCHANGE 5
#تعریف_کړه CBN_EDITUPDATE 6
#تعریف_کړه CBN_DROPDOWN 7
#تعریف_کړه CBN_CLOSEUP 8
#تعریف_کړه CBN_SELENDOK 9
#تعریف_کړه CBN_SELENDCANCEL 10

#که_نه_تعریف_شوی NOWINSTYLES

#تعریف_کړه CBS_SIMPLE 0x0001L
#تعریف_کړه CBS_DROPDOWN 0x0002L
#تعریف_کړه CBS_DROPDOWNLIST 0x0003L
#تعریف_کړه CBS_OWNERDRAWFIXED 0x0010L
#تعریف_کړه CBS_OWNERDRAWVARIABLE 0x0020L
#تعریف_کړه CBS_AUTOHSCROLL 0x0040L
#تعریف_کړه CBS_OEMCONVERT 0x0080L
#تعریف_کړه CBS_ترتیبول 0x0100L
#تعریف_کړه CBS_HASSTRINGS 0x0200L
#تعریف_کړه CBS_NOINTEGRALHEIGHT 0x0400L
#تعریف_کړه CBS_DISABLENOSCROLL 0x0800L
#تعریف_کړه CBS_UPPERCASE 0x2000L
#تعریف_کړه CBS_LOWERCASE 0x4000L
#د_که_پای

#که_نه_تعریف_شوی NOWINMESSAGES
#تعریف_کړه CB_GETEDITSEL 0x0140
#تعریف_کړه CB_LIMITTEXT 0x0141
#تعریف_کړه CB_SETEDITSEL 0x0142
#تعریف_کړه CB_ADDSTRING 0x0143
#تعریف_کړه CB_DELETESTRING 0x0144
#تعریف_کړه CB_DIR 0x0145
#تعریف_کړه CB_GETCOUNT 0x0146
#تعریف_کړه CB_GETCURSEL 0x0147
#تعریف_کړه CB_GETLBTEXT 0x0148
#تعریف_کړه CB_GETLBTEXTLEN 0x0149
#تعریف_کړه CB_INSERTSTRING 0x014A
#تعریف_کړه CB_RESETCONTENT 0x014B
#تعریف_کړه CB_FINDSTRING 0x014C
#تعریف_کړه CB_SELECTSTRING 0x014D
#تعریف_کړه CB_SETCURSEL 0x014E
#تعریف_کړه CB_SHOWDROPDOWN 0x014F
#تعریف_کړه CB_GETITEMDATA 0x0150
#تعریف_کړه CB_SETITEMDATA 0x0151
#تعریف_کړه CB_GETDROPPEDCONTROLRECT 0x0152
#تعریف_کړه CB_SETITEMHEIGHT 0x0153
#تعریف_کړه CB_GETITEMHEIGHT 0x0154
#تعریف_کړه CB_SETEXTENDEDUI 0x0155
#تعریف_کړه CB_GETEXTENDEDUI 0x0156
#تعریف_کړه CB_GETDROPPEDSTATE 0x0157
#تعریف_کړه CB_FINDSTRINGEXACT 0x0158
#تعریف_کړه CB_SETLOCALE 0x0159
#تعریف_کړه CB_GETLOCALE 0x015A
#تعریف_کړه CB_GETTOPINDEX 0x015b
#تعریف_کړه CB_SETTOPINDEX 0x015c
#تعریف_کړه CB_GETHORIZONTALEXTENT 0x015d
#تعریف_کړه CB_SETHORIZONTALEXTENT 0x015e
#تعریف_کړه CB_GETDROPPEDWIDTH 0x015f
#تعریف_کړه CB_SETDROPPEDWIDTH 0x0160
#تعریف_کړه CB_INITSTORAGE 0x0161
#إذا(_WIN32_WCE >= 0x0400)
#تعریف_کړه CB_MULTIPLEADDSTRING 0x0163
#د_که_پای
#تعریف_کړه CB_GETCOMBOBOXINFO 0x0164
#تعریف_کړه CB_MSGMAX 0x0165
#د_که_پای

#که_نه_تعریف_شوی NOWINSTYLES

#تعریف_کړه SBS_HORZ 0x0000L
#تعریف_کړه SBS_VERT 0x0001L
#تعریف_کړه SBS_TOPALIGN 0x0002L
#تعریف_کړه SBS_LEFTALIGN 0x0002L
#تعریف_کړه SBS_BOTTOMALIGN 0x0004L
#تعریف_کړه SBS_RIGHTALIGN 0x0004L
#تعریف_کړه SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#تعریف_کړه SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#تعریف_کړه SBS_SIZEBOX 0x0008L
#تعریف_کړه SBS_SIZEGRIP 0x0010L
#د_که_پای

#که_نه_تعریف_شوی NOWINMESSAGES
#تعریف_کړه SBM_SETPOS 0x00E0
#تعریف_کړه SBM_GETPOS 0x00E1
#تعریف_کړه SBM_SETRANGE 0x00E2
#تعریف_کړه SBM_SETRANGEREDRAW 0x00E6
#تعریف_کړه SBM_GETRANGE 0x00E3
#تعریف_کړه SBM_ENABLE_ARROWS 0x00E4
#تعریف_کړه SBM_SETSCROLLINFO 0x00E9
#تعریف_کړه SBM_GETSCROLLINFO 0x00EA
#تعریف_کړه SBM_GETSCROLLBARINFO 0x00EB

#تعریف_کړه SIF_RANGE 0x0001
#تعریف_کړه SIF_پاڼه 0x0002
#تعریف_کړه SIF_POS 0x0004
#تعریف_کړه SIF_DISABLENOSCROLL 0x0008
#تعریف_کړه SIF_TRACKPOS 0x0010
#تعریف_کړه SIF_ALL (SIF_RANGE | SIF_پاڼه | SIF_POS | SIF_TRACKPOS)

  تعريفنوع بنية نښان_SCROLLINFO {
    UINT cb_اندازه;
    UINT f_ماسک;
    صحيح nMin;
    صحيح nMax;
    UINT n_پاڼه;
    صحيح nPos;
    صحيح nTrackPos;
  } SCROLLINFO,*LPSCROLLINFO;
  تعريفنوع SCROLLINFO CONST *LPCSCROLLINFO;

  WINUSERAPI صحيح WINAPI سېټ_Scroll_Info(HWND hwnd,صحيح nBar,LPCSCROLLINFO lpsi,WINBOOL redraw);
  WINUSERAPI WINBOOL WINAPI GetScrollInfo(HWND hwnd,صحيح nBar,LPSCROLLINFO lpsi);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی NOMDI

#تعریف_کړه MDIS_ALLCHILDSTYLES 0x0001

#تعریف_کړه MDITILE_VERTICAL 0x0000
#تعریف_کړه MDITILE_HORIZONTAL 0x0001
#تعریف_کړه MDITILE_SKIPDISABLED 0x0002
#تعریف_کړه MDITILE_ZORDER 0x0004

  تعريفنوع بنية نښان_MDICREATESTRUCTA {
    LPCSTR szClass;
    LPCSTR szTitle;
    HANDLE hOwner;
    صحيح x;
    صحيح y;
    صحيح cx;
    صحيح cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTA,*LPMDICREATESTRUCTA;

  تعريفنوع بنية نښان_MDICREATESTRUCTW {
    LPCWSTR szClass;
    LPCWSTR szTitle;
    HANDLE hOwner;
    صحيح x;
    صحيح y;
    صحيح cx;
    صحيح cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTW,*LPMDICREATESTRUCTW;

#که_تعریف_شوی UNICODE
  تعريفنوع MDICREATESTRUCTW MDICREATESTRUCT;
  تعريفنوع LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#وإلا
  تعريفنوع MDICREATESTRUCTA MDICREATESTRUCT;
  تعريفنوع LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#د_که_پای

  تعريفنوع بنية نښان_CLIENTCREATESTRUCT {
    HANDLE h_کړکۍ_Menu;
    UINT id_لومړی_ماشوم;
  } CLIENTCREATESTRUCT,*LPCLIENTCREATESTRUCT;

#که_تعریف_شوی UNICODE
#تعریف_کړه Def_چوکاټ_Proc Def_چوکاټ_Proc_W
#تعریف_کړه DefMDIChildProc DefMDIChildProcW
#تعریف_کړه CreateMDIWindow CreateMDIWindowW
#وإلا
#تعریف_کړه Def_چوکاټ_Proc Def_چوکاټ_Proc_A
#تعریف_کړه DefMDIChildProc DefMDIChildProcA
#تعریف_کړه CreateMDIWindow CreateMDIWindowA
#د_که_پای

  WINUSERAPI LRESULT WINAPI Def_چوکاټ_Proc_A(HWND hWnd,HWND hWndMDIClient,UINT u_پیغام,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_چوکاټ_Proc_W(HWND hWnd,HWND hWndMDIClient,UINT u_پیغام,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcA(HWND hWnd,UINT u_پیغام,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcW(HWND hWnd,UINT u_پیغام,WPARAM wParam,LPARAM lParam);

#که_نه_تعریف_شوی NOMSG
  WINUSERAPI WINBOOL WINAPI TranslateMDISysAccel(HWND hWndClient,LPMSG lp_پیغام_2);
#د_که_پای

  WINUSERAPI UINT WINAPI ArrangeIconicWindows(HWND hWnd);
  WINUSERAPI HWND WINAPI CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lp_کړکۍ_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_پلنوالی,صحيح n_لوړوالی,HWND h_Wnd_پلار,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI HWND WINAPI CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lp_کړکۍ_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_پلنوالی,صحيح n_لوړوالی,HWND h_Wnd_پلار,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI کلمه_3 WINAPI TileWindows(HWND hwnd_پلار_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ثابت HWND *lpKids);
  WINUSERAPI کلمه_3 WINAPI CascadeWindows(HWND hwnd_پلار_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ثابت HWND *lpKids);
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی NOHELP

  تعريفنوع DWORD HELPPOLY;
  تعريفنوع بنية نښان_MULTIKEYHELPA {
    DWORD mk_اندازه;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
  } MULTIKEYHELPA,*PMULTIKEYHELPA,*LPMULTIKEYHELPA;

  تعريفنوع بنية نښان_MULTIKEYHELPW {
    DWORD mk_اندازه;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
  } MULTIKEYHELPW,*PMULTIKEYHELPW,*LPMULTIKEYHELPW;

#که_تعریف_شوی UNICODE
  تعريفنوع MULTIKEYHELPW MULTIKEYHELP;
  تعريفنوع PMULTIKEYHELPW PMULTIKEYHELP;
  تعريفنوع LPMULTIKEYHELPW LPMULTIKEYHELP;
#وإلا
  تعريفنوع MULTIKEYHELPA MULTIKEYHELP;
  تعريفنوع PMULTIKEYHELPA PMULTIKEYHELP;
  تعريفنوع LPMULTIKEYHELPA LPMULTIKEYHELP;
#د_که_پای

  تعريفنوع بنية نښان_HELPWININFOA {
    صحيح w_Struct_اندازه;
    صحيح x;
    صحيح y;
    صحيح dx;
    صحيح dy;
    صحيح wMax;
    CHAR rgchMember[2];
  } HELPWININFOA,*PHELPWININFOA,*LPHELPWININFOA;

  تعريفنوع بنية نښان_HELPWININFOW {
    صحيح w_Struct_اندازه;
    صحيح x;
    صحيح y;
    صحيح dx;
    صحيح dy;
    صحيح wMax;
    WCHAR rgchMember[2];
  } HELPWININFOW,*PHELPWININFOW,*LPHELPWININFOW;

#که_تعریف_شوی UNICODE
  تعريفنوع HELPWININFOW HELPWININFO;
  تعريفنوع PHELPWININFOW PHELPWININFO;
  تعريفنوع LPHELPWININFOW LPHELPWININFO;
#وإلا
  تعريفنوع HELPWININFOA HELPWININFO;
  تعريفنوع PHELPWININFOA PHELPWININFO;
  تعريفنوع LPHELPWININFOA LPHELPWININFO;
#د_که_پای

#تعریف_کړه HELP_CONTEXT 0x0001L
#تعریف_کړه HELP_QUIT 0x0002L
#تعریف_کړه HELP_شاخص 0x0003L
#تعریف_کړه HELP_CONTENTS 0x0003L
#تعریف_کړه HELP_HELPONHELP 0x0004L
#تعریف_کړه HELP_SETINDEX 0x0005L
#تعریف_کړه HELP_SETCONTENTS 0x0005L
#تعریف_کړه HELP_CONTEXTPOPUP 0x0008L
#تعریف_کړه HELP_FORCEFILE 0x0009L
#تعریف_کړه HELP_کلی 0x0101L
#تعریف_کړه HELP_COMMAND 0x0102L
#تعریف_کړه HELP_PARTIALKEY 0x0105L
#تعریف_کړه HELP_MULTIKEY 0x0201L
#تعریف_کړه HELP_SETWINPOS 0x0203L
#تعریف_کړه HELP_CONTEXTMENU 0x000a
#تعریف_کړه HELP_FINDER 0x000b
#تعریف_کړه HELP_WM_HELP 0x000c
#تعریف_کړه HELP_SETPOPUP_POS 0x000d

#تعریف_کړه HELP_TCARD 0x8000
#تعریف_کړه HELP_TCARD_معلومات 0x0010
#تعریف_کړه HELP_TCARD_OTHER_CALLER 0x0011

#تعریف_کړه IDH_NO_HELP 28440
#تعریف_کړه IDH_MISSING_CONTEXT 28441
#تعریف_کړه IDH_GENERIC_HELP_BUTTON 28442
#تعریف_کړه IDH_OK 28443
#تعریف_کړه IDH_CANCEL 28444
#تعریف_کړه IDH_HELP 28445

#که_تعریف_شوی UNICODE
#تعریف_کړه WinHelp WinHelpW
#وإلا
#تعریف_کړه WinHelp WinHelpA
#د_که_پای

  WINUSERAPI WINBOOL WINAPI WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dw_معلومات);
  WINUSERAPI WINBOOL WINAPI WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dw_معلومات);
#د_که_پای

#تعریف_کړه GR_GDIOBJECTS 0
#تعریف_کړه GR_USEROBJECTS 1

  WINUSERAPI DWORD WINAPI GetGuiResources(HANDLE hProcess,DWORD uiFlags);

#که_نه_تعریف_شوی NOSYSPARAMSINFO

#تعریف_کړه SPI_GETBEEP 0x0001
#تعریف_کړه SPI_SETBEEP 0x0002
#تعریف_کړه SPI_GETMOUSE 0x0003
#تعریف_کړه SPI_SETMOUSE 0x0004
#تعریف_کړه SPI_GETBORDER 0x0005
#تعریف_کړه SPI_SETBORDER 0x0006
#تعریف_کړه SPI_GETKEYBOARDSPEED 0x000A
#تعریف_کړه SPI_SETKEYBOARDSPEED 0x000B
#تعریف_کړه SPI_LANGDRIVER 0x000C
#تعریف_کړه SPI_ICONHORIZONTALSPACING 0x000D
#تعریف_کړه SPI_GETSCREENSAVETIMEOUT 0x000E
#تعریف_کړه SPI_SETSCREENSAVETIMEOUT 0x000F
#تعریف_کړه SPI_GETSCREENSAVEACTIVE 0x0010
#تعریف_کړه SPI_SETSCREENSAVEACTIVE 0x0011
#تعریف_کړه SPI_GETGRIDGRANULARITY 0x0012
#تعریف_کړه SPI_SETGRIDGRANULARITY 0x0013
#تعریف_کړه SPI_SETDESKWALLPAPER 0x0014
#تعریف_کړه SPI_SETDESKPATTERN 0x0015
#تعریف_کړه SPI_GETKEYBOARDDELAY 0x0016
#تعریف_کړه SPI_SETKEYBOARDDELAY 0x0017
#تعریف_کړه SPI_ICONVERTICALSPACING 0x0018
#تعریف_کړه SPI_GETICONTITLEWRAP 0x0019
#تعریف_کړه SPI_SETICONTITLEWRAP 0x001A
#تعریف_کړه SPI_GETMENUDROPALIGNMENT 0x001B
#تعریف_کړه SPI_SETMENUDROPALIGNMENT 0x001C
#تعریف_کړه SPI_SETDOUBLECLKWIDTH 0x001D
#تعریف_کړه SPI_SETDOUBLECLKHEIGHT 0x001E
#تعریف_کړه SPI_GETICONTITLELOGFONT 0x001F
#تعریف_کړه SPI_SETDOUBLECLICKTIME 0x0020
#تعریف_کړه SPI_SETMOUSEBUTTONSWAP 0x0021
#تعریف_کړه SPI_SETICONTITLELOGFONT 0x0022
#تعریف_کړه SPI_GETFASTTASKSWITCH 0x0023
#تعریف_کړه SPI_SETFASTTASKSWITCH 0x0024
#تعریف_کړه SPI_SETDRAGFULLWINDOWS 0x0025
#تعریف_کړه SPI_GETDRAGFULLWINDOWS 0x0026
#تعریف_کړه SPI_GETNONCLIENTMETRICS 0x0029
#تعریف_کړه SPI_SETNONCLIENTMETRICS 0x002A
#تعریف_کړه SPI_GETMINIMIZEDMETRICS 0x002B
#تعریف_کړه SPI_SETMINIMIZEDMETRICS 0x002C
#تعریف_کړه SPI_GETICONMETRICS 0x002D
#تعریف_کړه SPI_SETICONMETRICS 0x002E
#تعریف_کړه SPI_SETWORKAREA 0x002F
#تعریف_کړه SPI_GETWORKAREA 0x0030
#تعریف_کړه SPI_SETPENWINDOWS 0x0031

#تعریف_کړه SPI_GETHIGHCONTRAST 0x0042
#تعریف_کړه SPI_SETHIGHCONTRAST 0x0043
#تعریف_کړه SPI_GETKEYBOARDPREF 0x0044
#تعریف_کړه SPI_SETKEYBOARDPREF 0x0045
#تعریف_کړه SPI_GETSCREENREADER 0x0046
#تعریف_کړه SPI_SETSCREENREADER 0x0047
#تعریف_کړه SPI_GETANIMATION 0x0048
#تعریف_کړه SPI_SETANIMATION 0x0049
#تعریف_کړه SPI_GETFONTSMOOTHING 0x004A
#تعریف_کړه SPI_SETFONTSMOOTHING 0x004B
#تعریف_کړه SPI_SETDRAGWIDTH 0x004C
#تعریف_کړه SPI_SETDRAGHEIGHT 0x004D
#تعریف_کړه SPI_SETHANDHELD 0x004E
#تعریف_کړه SPI_GETLOWPOWERTIMEOUT 0x004F
#تعریف_کړه SPI_GETPOWEROFFTIMEOUT 0x0050
#تعریف_کړه SPI_SETLOWPOWERTIMEOUT 0x0051
#تعریف_کړه SPI_SETPOWEROFFTIMEOUT 0x0052
#تعریف_کړه SPI_GETLOWPOWERACTIVE 0x0053
#تعریف_کړه SPI_GETPOWEROFFACTIVE 0x0054
#تعریف_کړه SPI_SETLOWPOWERACTIVE 0x0055
#تعریف_کړه SPI_SETPOWEROFFACTIVE 0x0056
#تعریف_کړه SPI_SETCURSORS 0x0057
#تعریف_کړه SPI_SETICONS 0x0058
#تعریف_کړه SPI_GETDEFAULTINPUTLANG 0x0059
#تعریف_کړه SPI_SETDEFAULTINPUTLANG 0x005A
#تعریف_کړه SPI_SETLANGTOGGLE 0x005B
#تعریف_کړه SPI_GETWINDOWSEXTENSION 0x005C
#تعریف_کړه SPI_SETMOUSETRAILS 0x005D
#تعریف_کړه SPI_GETMOUSETRAILS 0x005E
#تعریف_کړه SPI_SETSCREENSAVERRUNNING 0x0061
#تعریف_کړه SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#تعریف_کړه SPI_GETFILTERKEYS 0x0032
#تعریف_کړه SPI_SETFILTERKEYS 0x0033
#تعریف_کړه SPI_GETTOGGLEKEYS 0x0034
#تعریف_کړه SPI_SETTOGGLEKEYS 0x0035
#تعریف_کړه SPI_GETMOUSEKEYS 0x0036
#تعریف_کړه SPI_SETMOUSEKEYS 0x0037
#تعریف_کړه SPI_GETSHOWSOUNDS 0x0038
#تعریف_کړه SPI_SETSHOWSOUNDS 0x0039
#تعریف_کړه SPI_GETSTICKYKEYS 0x003A
#تعریف_کړه SPI_SETSTICKYKEYS 0x003B
#تعریف_کړه SPI_GETACCESSTIMEOUT 0x003C
#تعریف_کړه SPI_SETACCESSTIMEOUT 0x003D
#تعریف_کړه SPI_GETSERIALKEYS 0x003E
#تعریف_کړه SPI_SETSERIALKEYS 0x003F
#تعریف_کړه SPI_GETSOUNDSENTRY 0x0040
#تعریف_کړه SPI_SETSOUNDSENTRY 0x0041
#تعریف_کړه SPI_GETSNAPTODEFBUTTON 0x005F
#تعریف_کړه SPI_SETSNAPTODEFBUTTON 0x0060
#تعریف_کړه SPI_GETMOUSEHOVERWIDTH 0x0062
#تعریف_کړه SPI_SETMOUSEHOVERWIDTH 0x0063
#تعریف_کړه SPI_GETMOUSEHOVERHEIGHT 0x0064
#تعریف_کړه SPI_SETMOUSEHOVERHEIGHT 0x0065
#تعریف_کړه SPI_GETMOUSEHOVERTIME 0x0066
#تعریف_کړه SPI_SETMOUSEHOVERTIME 0x0067
#تعریف_کړه SPI_GETWHEELSCROLLLINES 0x0068
#تعریف_کړه SPI_SETWHEELSCROLLLINES 0x0069
#تعریف_کړه SPI_GETMENUSHOWDELAY 0x006A
#تعریف_کړه SPI_SETMENUSHOWDELAY 0x006B
#تعریف_کړه SPI_GETSHOWIMEUI 0x006E
#تعریف_کړه SPI_SETSHOWIMEUI 0x006F
#تعریف_کړه SPI_GETMOUSESPEED 0x0070
#تعریف_کړه SPI_SETMOUSESPEED 0x0071
#تعریف_کړه SPI_GETSCREENSAVERRUNNING 0x0072
#تعریف_کړه SPI_GETDESKWALLPAPER 0x0073

#تعریف_کړه SPI_GETACTIVEWINDOWTRACKING 0x1000
#تعریف_کړه SPI_SETACTIVEWINDOWTRACKING 0x1001
#تعریف_کړه SPI_GETMENUANIMATION 0x1002
#تعریف_کړه SPI_SETMENUANIMATION 0x1003
#تعریف_کړه SPI_GETCOMBOBOXANIMATION 0x1004
#تعریف_کړه SPI_SETCOMBOBOXANIMATION 0x1005
#تعریف_کړه SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#تعریف_کړه SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#تعریف_کړه SPI_GETGRADIENTCAPTIONS 0x1008
#تعریف_کړه SPI_SETGRADIENTCAPTIONS 0x1009
#تعریف_کړه SPI_GETKEYBOARDCUES 0x100A
#تعریف_کړه SPI_SETKEYBOARDCUES 0x100B
#تعریف_کړه SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#تعریف_کړه SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#تعریف_کړه SPI_GETACTIVEWNDTRKZORDER 0x100C
#تعریف_کړه SPI_SETACTIVEWNDTRKZORDER 0x100D
#تعریف_کړه SPI_GETHOTTRACKING 0x100E
#تعریف_کړه SPI_SETHOTTRACKING 0x100F
#تعریف_کړه SPI_GETMENUFADE 0x1012
#تعریف_کړه SPI_SETMENUFADE 0x1013
#تعریف_کړه SPI_GETSELECTIONFADE 0x1014
#تعریف_کړه SPI_SETSELECTIONFADE 0x1015
#تعریف_کړه SPI_GETTOOLTIPANIMATION 0x1016
#تعریف_کړه SPI_SETTOOLTIPANIMATION 0x1017
#تعریف_کړه SPI_GETTOOLTIPFADE 0x1018
#تعریف_کړه SPI_SETTOOLTIPFADE 0x1019
#تعریف_کړه SPI_GETCURSORSHADOW 0x101A
#تعریف_کړه SPI_SETCURSORSHADOW 0x101B
#تعریف_کړه SPI_GETMOUSESONAR 0x101C
#تعریف_کړه SPI_SETMOUSESONAR 0x101D
#تعریف_کړه SPI_GETMOUSECLICKLOCK 0x101E
#تعریف_کړه SPI_SETMOUSECLICKLOCK 0x101F
#تعریف_کړه SPI_GETMOUSEVANISH 0x1020
#تعریف_کړه SPI_SETMOUSEVANISH 0x1021
#تعریف_کړه SPI_GETFLATMENU 0x1022
#تعریف_کړه SPI_SETFLATMENU 0x1023
#تعریف_کړه SPI_GETDROPSHADOW 0x1024
#تعریف_کړه SPI_SETDROPSHADOW 0x1025
#تعریف_کړه SPI_GETBLOCKSENDINPUTRESETS 0x1026
#تعریف_کړه SPI_SETBLOCKSENDINPUTRESETS 0x1027
#تعریف_کړه SPI_GETUIEFFECTS 0x103E
#تعریف_کړه SPI_SETUIEFFECTS 0x103F
#تعریف_کړه SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#تعریف_کړه SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#تعریف_کړه SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#تعریف_کړه SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#تعریف_کړه SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#تعریف_کړه SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#تعریف_کړه SPI_GETCARETWIDTH 0x2006
#تعریف_کړه SPI_SETCARETWIDTH 0x2007
#تعریف_کړه SPI_GETMOUSECLICKLOCKTIME 0x2008
#تعریف_کړه SPI_SETMOUSECLICKLOCKTIME 0x2009
#تعریف_کړه SPI_GETFONTSMOOTHINGTYPE 0x200A
#تعریف_کړه SPI_SETFONTSMOOTHINGTYPE 0x200B

#تعریف_کړه FE_FONTSMOOTHINGSTANDARD 0x0001
#تعریف_کړه FE_FONTSMOOTHINGCLEARTYPE 0x0002
#تعریف_کړه FE_FONTSMOOTHINGDOCKING 0x8000

#تعریف_کړه SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#تعریف_کړه SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#تعریف_کړه SPI_GETFOCUSBORDERWIDTH 0x200E
#تعریف_کړه SPI_SETFOCUSBORDERWIDTH 0x200F
#تعریف_کړه SPI_GETFOCUSBORDERHEIGHT 0x2010
#تعریف_کړه SPI_SETFOCUSBORDERHEIGHT 0x2011
#تعریف_کړه SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#تعریف_کړه SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#تعریف_کړه FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#تعریف_کړه FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#تعریف_کړه SPIF_UPDATEINIFILE 0x0001
#تعریف_کړه SPIF_SENDWININICHANGE 0x0002
#تعریف_کړه SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#تعریف_کړه METRICS_USEDEFAULT -1
#که_تعریف_شوی _WINGDI_
#که_نه_تعریف_شوی NOGDI
  تعريفنوع بنية نښان_NONCLIENTMETRICSA {
    UINT cb_اندازه;
    صحيح i_Border_پلنوالی;
    صحيح i_Scroll_پلنوالی;
    صحيح i_Scroll_لوړوالی;
    صحيح i_Caption_پلنوالی;
    صحيح i_Caption_لوړوالی;
    LOGFONTA lfCaptionFont;
    صحيح i_Sm_Caption_پلنوالی;
    صحيح i_Sm_Caption_لوړوالی;
    LOGFONTA lfSmCaptionFont;
    صحيح i_Menu_پلنوالی;
    صحيح i_Menu_لوړوالی;
    LOGFONTA lfMenuFont;
    LOGFONTA lf_حالت_Font;
    LOGFONTA lf_پیغام_Font;
  } NONCLIENTMETRICSA,*PNONCLIENTMETRICSA,*LPNONCLIENTMETRICSA;

  تعريفنوع بنية نښان_NONCLIENTMETRICSW {
    UINT cb_اندازه;
    صحيح i_Border_پلنوالی;
    صحيح i_Scroll_پلنوالی;
    صحيح i_Scroll_لوړوالی;
    صحيح i_Caption_پلنوالی;
    صحيح i_Caption_لوړوالی;
    LOGFONTW lfCaptionFont;
    صحيح i_Sm_Caption_پلنوالی;
    صحيح i_Sm_Caption_لوړوالی;
    LOGFONTW lfSmCaptionFont;
    صحيح i_Menu_پلنوالی;
    صحيح i_Menu_لوړوالی;
    LOGFONTW lfMenuFont;
    LOGFONTW lf_حالت_Font;
    LOGFONTW lf_پیغام_Font;
  } NONCLIENTMETRICSW,*PNONCLIENTMETRICSW,*LPNONCLIENTMETRICSW;

#که_تعریف_شوی UNICODE
  تعريفنوع NONCLIENTMETRICSW NONCLIENTMETRICS;
  تعريفنوع PNONCLIENTMETRICSW PNONCLIENTMETRICS;
  تعريفنوع LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#وإلا
  تعريفنوع NONCLIENTMETRICSA NONCLIENTMETRICS;
  تعريفنوع PNONCLIENTMETRICSA PNONCLIENTMETRICS;
  تعريفنوع LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#د_که_پای
#د_که_پای
#د_که_پای

#تعریف_کړه ARW_BOTTOMLEFT 0x0000L
#تعریف_کړه ARW_BOTTOMRIGHT 0x0001L
#تعریف_کړه ARW_TOPLEFT 0x0002L
#تعریف_کړه ARW_TOPRIGHT 0x0003L
#تعریف_کړه ARW_STARTMASK 0x0003L
#تعریف_کړه ARW_STARTRIGHT 0x0001L
#تعریف_کړه ARW_STARTTOP 0x0002L

#تعریف_کړه ARW_کیڼ 0x0000L
#تعریف_کړه ARW_ښی 0x0000L
#تعریف_کړه ARW_پورته 0x0004L
#تعریف_کړه ARW_ښکته 0x0004L
#تعریف_کړه ARW_HIDE 0x0008L

  تعريفنوع بنية نښان_MINIMIZEDMETRICS {
    UINT cb_اندازه;
    صحيح i_پلنوالی;
    صحيح iHorzGap;
    صحيح iVertGap;
    صحيح iArrange;
  } MINIMIZEDMETRICS,*PMINIMIZEDMETRICS,*LPMINIMIZEDMETRICS;

#که_تعریف_شوی _WINGDI_
#که_نه_تعریف_شوی NOGDI
  تعريفنوع بنية نښان_ICONMETRICSA {
    UINT cb_اندازه;
    صحيح iHorzSpacing;
    صحيح iVertSpacing;
    صحيح iTitleWrap;
    LOGFONTA lfFont;
  } ICONMETRICSA,*PICONMETRICSA,*LPICONMETRICSA;

  تعريفنوع بنية نښان_ICONMETRICSW {
    UINT cb_اندازه;
    صحيح iHorzSpacing;
    صحيح iVertSpacing;
    صحيح iTitleWrap;
    LOGFONTW lfFont;
  } ICONMETRICSW,*PICONMETRICSW,*LPICONMETRICSW;

#که_تعریف_شوی UNICODE
  تعريفنوع ICONMETRICSW ICONMETRICS;
  تعريفنوع PICONMETRICSW PICONMETRICS;
  تعريفنوع LPICONMETRICSW LPICONMETRICS;
#وإلا
  تعريفنوع ICONMETRICSA ICONMETRICS;
  تعريفنوع PICONMETRICSA PICONMETRICS;
  تعريفنوع LPICONMETRICSA LPICONMETRICS;
#د_که_پای
#د_که_پای
#د_که_پای

  تعريفنوع بنية نښان_ANIMATIONINFO {
    UINT cb_اندازه;
    صحيح iMinAnimate;
  } ANIMATIONINFO,*LPANIMATIONINFO;

  تعريفنوع بنية نښان_SERIALKEYSA {
    UINT cb_اندازه;
    DWORD dwFlags;
    LPSTR lpsz_فعال_پورټ;
    LPSTR lpsz_پورټ;
    UINT i_Baud_شرح;
    UINT i_پورټ_State;
    UINT i_فعال;
  } SERIALKEYSA,*LPSERIALKEYSA;

  تعريفنوع بنية نښان_SERIALKEYSW {
    UINT cb_اندازه;
    DWORD dwFlags;
    LPWSTR lpsz_فعال_پورټ;
    LPWSTR lpsz_پورټ;
    UINT i_Baud_شرح;
    UINT i_پورټ_State;
    UINT i_فعال;
  } SERIALKEYSW,*LPSERIALKEYSW;

#که_تعریف_شوی UNICODE
  تعريفنوع SERIALKEYSW SERIALKEYS;
  تعريفنوع LPSERIALKEYSW LPSERIALKEYS;
#وإلا
  تعريفنوع SERIALKEYSA SERIALKEYS;
  تعريفنوع LPSERIALKEYSA LPSERIALKEYS;
#د_که_پای

#تعریف_کړه SERKF_SERIALKEYSON 0x00000001
#تعریف_کړه SERKF_شته 0x00000002
#تعریف_کړه SERKF_INDICATOR 0x00000004

  تعريفنوع بنية نښان_HIGHCONTRASTA {
    UINT cb_اندازه;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
  } HIGHCONTRASTA,*LPHIGHCONTRASTA;

  تعريفنوع بنية نښان_HIGHCONTRASTW {
    UINT cb_اندازه;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
  } HIGHCONTRASTW,*LPHIGHCONTRASTW;

#که_تعریف_شوی UNICODE
  تعريفنوع HIGHCONTRASTW HIGHCONTRAST;
  تعريفنوع LPHIGHCONTRASTW LPHIGHCONTRAST;
#وإلا
  تعريفنوع HIGHCONTRASTA HIGHCONTRAST;
  تعريفنوع LPHIGHCONTRASTA LPHIGHCONTRAST;
#د_که_پای

#تعریف_کړه HCF_HIGHCONTRASTON 0x00000001
#تعریف_کړه HCF_شته 0x00000002
#تعریف_کړه HCF_HOTKEYACTIVE 0x00000004
#تعریف_کړه HCF_CONFIRMHOTKEY 0x00000008
#تعریف_کړه HCF_HOTKEYSOUND 0x00000010
#تعریف_کړه HCF_INDICATOR 0x00000020
#تعریف_کړه HCF_HOTKEYAVAILABLE 0x00000040
#تعریف_کړه HCF_LOGONDESKTOP 0x00000100
#تعریف_کړه HCF_DEFAULTDESKTOP 0x00000200

#تعریف_کړه CDS_UPDATEREGISTRY 0x00000001
#تعریف_کړه CDS_TEST 0x00000002
#تعریف_کړه CDS_FULLSCREEN 0x00000004
#تعریف_کړه CDS_GLOBAL 0x00000008
#تعریف_کړه CDS_سېټ_PRIMARY 0x00000010
#تعریف_کړه CDS_VIDEOPARAMETERS 0x00000020
#تعریف_کړه CDS_RESET 0x40000000
#تعریف_کړه CDS_NORESET 0x10000000

//gr #include <tvout.h>

#تعریف_کړه DISP_CHANGE_SUCCESSFUL 0
#تعریف_کړه DISP_CHANGE_RESTART 1
#تعریف_کړه DISP_CHANGE_FAILED -1
#تعریف_کړه DISP_CHANGE_BADMODE -2
#تعریف_کړه DISP_CHANGE_NOTUPDATED -3
#تعریف_کړه DISP_CHANGE_BADFLAGS -4
#تعریف_کړه DISP_CHANGE_BADPARAM -5
#تعریف_کړه DISP_CHANGE_BADDUALVIEW -6

#که_تعریف_شوی _WINGDI_
#که_نه_تعریف_شوی NOGDI

#که_تعریف_شوی UNICODE
#تعریف_کړه ChangeDisplaySettings ChangeDisplaySettingsW
#تعریف_کړه ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#تعریف_کړه EnumDisplaySettings EnumDisplaySettingsW
#تعریف_کړه EnumDisplaySettingsEx EnumDisplaySettingsExW
#تعریف_کړه EnumDisplayDevices EnumDisplayDevicesW
#وإلا
#تعریف_کړه ChangeDisplaySettings ChangeDisplaySettingsA
#تعریف_کړه ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#تعریف_کړه EnumDisplaySettings EnumDisplaySettingsA
#تعریف_کړه EnumDisplaySettingsEx EnumDisplaySettingsExA
#تعریف_کړه EnumDisplayDevices EnumDisplayDevicesA
#د_که_پای

  WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lp_Dev_ډېرپېښ,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsW(LPDEVMODEW lp_Dev_ډېرپېښ,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,LPDEVMODEA lp_Dev_ډېرپېښ,HWND hwnd,DWORD dwflags,LPVOID lParam);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,LPDEVMODEW lp_Dev_ډېرپېښ,HWND hwnd,DWORD dwflags,LPVOID lParam);

#تعریف_کړه ENUM_CURRENT_SETTINGS ((DWORD)-1)
#تعریف_کړه ENUM_REGISTRY_SETTINGS ((DWORD)-2)

  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD i_ډېرپېښ_عدد,LPDEVMODEA lp_Dev_ډېرپېښ);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD i_ډېرپېښ_عدد,LPDEVMODEW lp_Dev_ډېرپېښ);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD i_ډېرپېښ_عدد,LPDEVMODEA lp_Dev_ډېرپېښ,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD i_ډېرپېښ_عدد,LPDEVMODEW lp_Dev_ډېرپېښ,DWORD dwFlags);

#تعریف_کړه EDS_RAWMODE 0x00000002

  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesA(LPCSTR lpDevice,DWORD i_Dev_عدد,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD i_Dev_عدد,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
#د_که_پای
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه SystemParametersInfo SystemParametersInfoW
#وإلا
#تعریف_کړه SystemParametersInfo SystemParametersInfoA
#د_که_پای

  WINUSERAPI WINBOOL WINAPI SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
  WINUSERAPI WINBOOL WINAPI SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
#د_که_پای

  تعريفنوع بنية نښان_FILTERKEYS {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
  } FILTERKEYS,*LPFILTERKEYS;

#تعریف_کړه FKF_FILTERKEYSON 0x00000001
#تعریف_کړه FKF_شته 0x00000002
#تعریف_کړه FKF_HOTKEYACTIVE 0x00000004
#تعریف_کړه FKF_CONFIRMHOTKEY 0x00000008
#تعریف_کړه FKF_HOTKEYSOUND 0x00000010
#تعریف_کړه FKF_INDICATOR 0x00000020
#تعریف_کړه FKF_CLICKON 0x00000040

  تعريفنوع بنية نښان_STICKYKEYS {
    UINT cb_اندازه;
    DWORD dwFlags;
  } STICKYKEYS,*LPSTICKYKEYS;

#تعریف_کړه SKF_STICKYKEYSON 0x00000001
#تعریف_کړه SKF_شته 0x00000002
#تعریف_کړه SKF_HOTKEYACTIVE 0x00000004
#تعریف_کړه SKF_CONFIRMHOTKEY 0x00000008
#تعریف_کړه SKF_HOTKEYSOUND 0x00000010
#تعریف_کړه SKF_INDICATOR 0x00000020
#تعریف_کړه SKF_AUDIBLEFEEDBACK 0x00000040
#تعریف_کړه SKF_TRISTATE 0x00000080
#تعریف_کړه SKF_TWOKEYSOFF 0x00000100
#تعریف_کړه SKF_LALTLATCHED 0x10000000
#تعریف_کړه SKF_LCTLLATCHED 0x04000000
#تعریف_کړه SKF_LSHIFTLATCHED 0x01000000
#تعریف_کړه SKF_RALTLATCHED 0x20000000
#تعریف_کړه SKF_RCTLLATCHED 0x08000000
#تعریف_کړه SKF_RSHIFTLATCHED 0x02000000
#تعریف_کړه SKF_LWINLATCHED 0x40000000
#تعریف_کړه SKF_RWINLATCHED 0x80000000
#تعریف_کړه SKF_LALTLOCKED 0x00100000
#تعریف_کړه SKF_LCTLLOCKED 0x00040000
#تعریف_کړه SKF_LSHIFTLOCKED 0x00010000
#تعریف_کړه SKF_RALTLOCKED 0x00200000
#تعریف_کړه SKF_RCTLLOCKED 0x00080000
#تعریف_کړه SKF_RSHIFTLOCKED 0x00020000
#تعریف_کړه SKF_LWINLOCKED 0x00400000
#تعریف_کړه SKF_RWINLOCKED 0x00800000

  تعريفنوع بنية نښان_MOUSEKEYS {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD i_Max_چټکتیا;
    DWORD i_وخت_منزل_Max_چټکتیا;
    DWORD i_Ctrl_چټکتیا;
    DWORD dwReserved1;
    DWORD dwReserved2;
  } MOUSEKEYS,*LPMOUSEKEYS;

#تعریف_کړه MKF_MOUSEKEYSON 0x00000001
#تعریف_کړه MKF_شته 0x00000002
#تعریف_کړه MKF_HOTKEYACTIVE 0x00000004
#تعریف_کړه MKF_CONFIRMHOTKEY 0x00000008
#تعریف_کړه MKF_HOTKEYSOUND 0x00000010
#تعریف_کړه MKF_INDICATOR 0x00000020
#تعریف_کړه MKF_MODIFIERS 0x00000040
#تعریف_کړه MKF_REPLACENUMBERS 0x00000080
#تعریف_کړه MKF_LEFTBUTTONSEL 0x10000000
#تعریف_کړه MKF_RIGHTBUTTONSEL 0x20000000
#تعریف_کړه MKF_LEFTBUTTONDOWN 0x01000000
#تعریف_کړه MKF_RIGHTBUTTONDOWN 0x02000000
#تعریف_کړه MKF_MOUSEMODE 0x80000000

  تعريفنوع بنية نښان_ACCESSTIMEOUT {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD i_وخت_بهر_MSec;
  } ACCESSTIMEOUT,*LPACCESSTIMEOUT;

#تعریف_کړه ATF_TIMEOUTON 0x00000001
#تعریف_کړه ATF_ONOFFFEEDBACK 0x00000002

#تعریف_کړه SSGF_NONE 0
#تعریف_کړه SSGF_DISPLAY 3

#تعریف_کړه SSTF_NONE 0
#تعریف_کړه SSTF_CHARS 1
#تعریف_کړه SSTF_BORDER 2
#تعریف_کړه SSTF_DISPLAY 3

#تعریف_کړه SSWF_NONE 0
#تعریف_کړه SSWF_TITLE 1
#تعریف_کړه SSWF_کړکۍ 2
#تعریف_کړه SSWF_DISPLAY 3
#تعریف_کړه SSWF_CUSTOM 4

  تعريفنوع بنية نښان_SOUNDSENTRYA {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_بټونه;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYA,*LPSOUNDSENTRYA;

  تعريفنوع بنية نښان_SOUNDSENTRYW {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_بټونه;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYW,*LPSOUNDSENTRYW;

#که_تعریف_شوی UNICODE
  تعريفنوع SOUNDSENTRYW SOUNDSENTRY;
  تعريفنوع LPSOUNDSENTRYW LPSOUNDSENTRY;
#وإلا
  تعريفنوع SOUNDSENTRYA SOUNDSENTRY;
  تعريفنوع LPSOUNDSENTRYA LPSOUNDSENTRY;
#د_که_پای

#تعریف_کړه SSF_SOUNDSENTRYON 0x00000001
#تعریف_کړه SSF_شته 0x00000002
#تعریف_کړه SSF_INDICATOR 0x00000004

  تعريفنوع بنية نښان_TOGGLEKEYS {
    UINT cb_اندازه;
    DWORD dwFlags;
  } TOGGLEKEYS,*LPTOGGLEKEYS;

#تعریف_کړه TKF_TOGGLEKEYSON 0x00000001
#تعریف_کړه TKF_شته 0x00000002
#تعریف_کړه TKF_HOTKEYACTIVE 0x00000004
#تعریف_کړه TKF_CONFIRMHOTKEY 0x00000008
#تعریف_کړه TKF_HOTKEYSOUND 0x00000010
#تعریف_کړه TKF_INDICATOR 0x00000020

  WINUSERAPI VOID WINAPI سېټ_Debug_Error_Level(DWORD dwLevel);

#تعریف_کړه SLE_ERROR 0x00000001
#تعریف_کړه SLE_MINORERROR 0x00000002
#تعریف_کړه SLE_WARNING 0x00000003

  WINUSERAPI VOID WINAPI سېټ_وروستی_Error_Ex(DWORD dw_Err_کوډ,DWORD dwType);
  WINUSERAPI صحيح WINAPI دننی_Get_کړکۍ_متن(HWND hWnd,LPWSTR pString,صحيح cch_Max_شمېر);

#که_تعریف_شوی WINNT
  WINUSERAPI WINBOOL WINAPI پای_ټکی_Task(HWND hWnd,WINBOOL f_Shut_ښکته,WINBOOL fForce);
#د_که_پای

#تعریف_کړه MONITOR_DEFAULTTONULL 0x00000000
#تعریف_کړه MONITOR_DEFAULTTOPRIMARY 0x00000001
#تعریف_کړه MONITOR_DEFAULTTONEAREST 0x00000002

  WINUSERAPI HMONITOR WINAPI Monitor_From_ټکی(ټکی_3 pt,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromRect(LPCRECT lprc,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI Monitor_From_کړکۍ(HWND hwnd,DWORD dwFlags);

#تعریف_کړه MONITORINFOF_PRIMARY 0x00000001

#که_نه_تعریف_شوی CCHDEVICENAME
#تعریف_کړه CCHDEVICENAME 32
#د_که_پای

  تعريفنوع بنية نښان_MONITORINFO {
    DWORD cb_اندازه;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
  } MONITORINFO,*LPMONITORINFO;

#که_تعریف_شوی __cplusplus
  تعريفنوع بنية نښان_MONITORINFOEXA : عام نښان_MONITORINFO {
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  تعريفنوع بنية نښان_MONITORINFOEXW : عام نښان_MONITORINFO {
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;

#که_تعریف_شوی UNICODE
  تعريفنوع MONITORINFOEXW MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXW LPMONITORINFOEX;
#وإلا
  تعريفنوع MONITORINFOEXA MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXA LPMONITORINFOEX;
#د_که_پای
#وإلا
  تعريفنوع بنية نښان_MONITORINFOEXA {
    MONITORINFO mi;
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  تعريفنوع بنية نښان_MONITORINFOEXW {
    MONITORINFO mi;
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;
#که_تعریف_شوی UNICODE
  تعريفنوع MONITORINFOEXW MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXW LPMONITORINFOEX;
#وإلا
  تعريفنوع MONITORINFOEXA MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXA LPMONITORINFOEX;
#د_که_پای
#د_که_پای

#که_تعریف_شوی UNICODE 
#تعریف_کړه GetMonitorInfo GetMonitorInfoW
#وإلا
#تعریف_کړه GetMonitorInfo GetMonitorInfoA
#د_که_پای

  WINUSERAPI WINBOOL WINAPI GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
  WINUSERAPI WINBOOL WINAPI GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);

  تعريفنوع WINBOOL (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

  WINUSERAPI WINBOOL WINAPI EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dw_معلومات);

#که_نه_تعریف_شوی NOWINABLE
  WINUSERAPI VOID WINAPI NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG id_ماشوم);

  تعريفنوع VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK hWinEventHook,DWORD event,HWND hwnd,LONG idObject,LONG id_ماشوم,DWORD idEventThread,DWORD dwms_Event_وخت);

  WINUSERAPI HWINEVENTHOOK WINAPI سېټ_Win_Event_Hook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI IsWinEventHookInstalled(DWORD event);

#تعریف_کړه WINEVENT_OUTOFCONTEXT 0x0000
#تعریف_کړه WINEVENT_SKIPOWNTHREAD 0x0001
#تعریف_کړه WINEVENT_SKIPOWNPROCESS 0x0002
#تعریف_کړه WINEVENT_INCONTEXT 0x0004

  WINUSERAPI WINBOOL WINAPI UnhookWinEvent(HWINEVENTHOOK hWinEventHook);

#تعریف_کړه CHILDID_SELF 0
#تعریف_کړه INDEXID_OBJECT 0
#تعریف_کړه INDEXID_CONTAINER 0

#تعریف_کړه OBJID_کړکۍ ((LONG)0x00000000)
#تعریف_کړه OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#تعریف_کړه OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#تعریف_کړه OBJID_MENU ((LONG)0xFFFFFFFD)
#تعریف_کړه OBJID_CLIENT ((LONG)0xFFFFFFFC)
#تعریف_کړه OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#تعریف_کړه OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#تعریف_کړه OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#تعریف_کړه OBJID_CARET ((LONG)0xFFFFFFF8)
#تعریف_کړه OBJID_CURSOR ((LONG)0xFFFFFFF7)
#تعریف_کړه OBJID_ALERT ((LONG)0xFFFFFFF6)
#تعریف_کړه OBJID_SOUND ((LONG)0xFFFFFFF5)
#تعریف_کړه OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#تعریف_کړه OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#تعریف_کړه EVENT_MIN 0x00000001
#تعریف_کړه EVENT_MAX 0x7FFFFFFF

#تعریف_کړه EVENT_SYSTEM_SOUND 0x0001
#تعریف_کړه EVENT_SYSTEM_ALERT 0x0002
#تعریف_کړه EVENT_SYSTEM_FOREGROUND 0x0003
#تعریف_کړه EVENT_SYSTEM_MENUSTART 0x0004
#تعریف_کړه EVENT_SYSTEM_MENUEND 0x0005
#تعریف_کړه EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#تعریف_کړه EVENT_SYSTEM_MENUPOPUPEND 0x0007
#تعریف_کړه EVENT_SYSTEM_CAPTURESTART 0x0008
#تعریف_کړه EVENT_SYSTEM_CAPTUREEND 0x0009
#تعریف_کړه EVENT_SYSTEM_MOVESIZESTART 0x000A
#تعریف_کړه EVENT_SYSTEM_MOVESIZEEND 0x000B
#تعریف_کړه EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#تعریف_کړه EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#تعریف_کړه EVENT_SYSTEM_DRAGDROPSTART 0x000E
#تعریف_کړه EVENT_SYSTEM_DRAGDROPEND 0x000F
#تعریف_کړه EVENT_SYSTEM_DIALOGSTART 0x0010
#تعریف_کړه EVENT_SYSTEM_DIALOGEND 0x0011
#تعریف_کړه EVENT_SYSTEM_SCROLLINGSTART 0x0012
#تعریف_کړه EVENT_SYSTEM_SCROLLINGEND 0x0013
#تعریف_کړه EVENT_SYSTEM_SWITCHSTART 0x0014
#تعریف_کړه EVENT_SYSTEM_SWITCHEND 0x0015
#تعریف_کړه EVENT_SYSTEM_MINIMIZESTART 0x0016
#تعریف_کړه EVENT_SYSTEM_MINIMIZEEND 0x0017

#تعریف_کړه EVENT_CONSOLE_CARET 0x4001
#تعریف_کړه EVENT_CONSOLE_UPDATE_REGION 0x4002
#تعریف_کړه EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#تعریف_کړه EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#تعریف_کړه EVENT_CONSOLE_LAYOUT 0x4005
#تعریف_کړه EVENT_CONSOLE_پیل_APPLICATION 0x4006
#تعریف_کړه EVENT_CONSOLE_پای_ټکی_APPLICATION 0x4007

#تعریف_کړه CONSOLE_APPLICATION_16_بټ 0x0001

#تعریف_کړه CONSOLE_CARET_SELECTION 0x0001
#تعریف_کړه CONSOLE_CARET_VISIBLE 0x0002

#تعریف_کړه EVENT_OBJECT_CREATE 0x8000
#تعریف_کړه EVENT_OBJECT_DESTROY 0x8001
#تعریف_کړه EVENT_OBJECT_SHOW 0x8002
#تعریف_کړه EVENT_OBJECT_HIDE 0x8003
#تعریف_کړه EVENT_OBJECT_REORDER 0x8004

#تعریف_کړه EVENT_OBJECT_FOCUS 0x8005
#تعریف_کړه EVENT_OBJECT_SELECTION 0x8006
#تعریف_کړه EVENT_OBJECT_SELECTIONADD 0x8007
#تعریف_کړه EVENT_OBJECT_SELECTIONREMOVE 0x8008
#تعریف_کړه EVENT_OBJECT_SELECTIONWITHIN 0x8009

#تعریف_کړه EVENT_OBJECT_STATECHANGE 0x800A

#تعریف_کړه EVENT_OBJECT_LOCATIONCHANGE 0x800B

#تعریف_کړه EVENT_OBJECT_NAMECHANGE 0x800C
#تعریف_کړه EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#تعریف_کړه EVENT_OBJECT_VALUECHANGE 0x800E
#تعریف_کړه EVENT_OBJECT_PARENTCHANGE 0x800F
#تعریف_کړه EVENT_OBJECT_HELPCHANGE 0x8010
#تعریف_کړه EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#تعریف_کړه EVENT_OBJECT_ACCELERATORCHANGE 0x8012

#تعریف_کړه SOUND_SYSTEM_STARTUP 1
#تعریف_کړه SOUND_SYSTEM_SHUTDOWN 2
#تعریف_کړه SOUND_SYSTEM_BEEP 3
#تعریف_کړه SOUND_SYSTEM_ERROR 4
#تعریف_کړه SOUND_SYSTEM_QUESTION 5
#تعریف_کړه SOUND_SYSTEM_WARNING 6
#تعریف_کړه SOUND_SYSTEM_INFORMATION 7
#تعریف_کړه SOUND_SYSTEM_MAXIMIZE 8
#تعریف_کړه SOUND_SYSTEM_MINIMIZE 9
#تعریف_کړه SOUND_SYSTEM_RESTOREUP 10
#تعریف_کړه SOUND_SYSTEM_RESTOREDOWN 11
#تعریف_کړه SOUND_SYSTEM_APPSTART 12
#تعریف_کړه SOUND_SYSTEM_FAULT 13
#تعریف_کړه SOUND_SYSTEM_APPEND 14
#تعریف_کړه SOUND_SYSTEM_MENUCOMMAND 15
#تعریف_کړه SOUND_SYSTEM_MENUPOPUP 16
#تعریف_کړه CSOUND_SYSTEM 16

#تعریف_کړه ALERT_SYSTEM_INFORMATIONAL 1
#تعریف_کړه ALERT_SYSTEM_WARNING 2
#تعریف_کړه ALERT_SYSTEM_ERROR 3
#تعریف_کړه ALERT_SYSTEM_QUERY 4
#تعریف_کړه ALERT_SYSTEM_CRITICAL 5
#تعریف_کړه CALERT_SYSTEM 6

  تعريفنوع بنية نښان_GUITHREADINFO {
    DWORD cb_اندازه;
    DWORD flags;
    HWND hwnd_فعال;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwnd_Move_اندازه;
    HWND hwndCaret;
    RECT rcCaret;
  } GUITHREADINFO,*PGUITHREADINFO,*LPGUITHREADINFO;

#تعریف_کړه GUI_CARETBLINKING 0x00000001
#تعریف_کړه GUI_INMOVESIZE 0x00000002
#تعریف_کړه GUI_INMENUMODE 0x00000004
#تعریف_کړه GUI_SYSTEMMENUMODE 0x00000008
#تعریف_کړه GUI_POPUPMENUMODE 0x00000010
#تعریف_کړه GUI_16BITTASK 0x00000020

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_کړکۍ_Module_File_Name Get_کړکۍ_Module_File_Name_W
#وإلا
#تعریف_کړه Get_کړکۍ_Module_File_Name Get_کړکۍ_Module_File_Name_A
#د_که_پای

  WINUSERAPI WINBOOL WINAPI GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui);
  WINUSERAPI UINT WINAPI Get_کړکۍ_Module_File_Name_A(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
  WINUSERAPI UINT WINAPI Get_کړکۍ_Module_File_Name_W(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);

#که_نه_تعریف_شوی NO_STATE_FLAGS
#تعریف_کړه STATE_SYSTEM_UNAVAILABLE 0x00000001
#تعریف_کړه STATE_SYSTEM_SELECTED 0x00000002
#تعریف_کړه STATE_SYSTEM_FOCUSED 0x00000004
#تعریف_کړه STATE_SYSTEM_PRESSED 0x00000008
#تعریف_کړه STATE_SYSTEM_CHECKED 0x00000010
#تعریف_کړه STATE_SYSTEM_MIXED 0x00000020
#تعریف_کړه STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#تعریف_کړه STATE_SYSTEM_READONLY 0x00000040
#تعریف_کړه STATE_SYSTEM_HOTTRACKED 0x00000080
#تعریف_کړه STATE_SYSTEM_DEFAULT 0x00000100
#تعریف_کړه STATE_SYSTEM_EXPANDED 0x00000200
#تعریف_کړه STATE_SYSTEM_COLLAPSED 0x00000400
#تعریف_کړه STATE_SYSTEM_BUSY 0x00000800
#تعریف_کړه STATE_SYSTEM_FLOATING 0x00001000
#تعریف_کړه STATE_SYSTEM_MARQUEED 0x00002000
#تعریف_کړه STATE_SYSTEM_ANIMATED 0x00004000
#تعریف_کړه STATE_SYSTEM_INVISIBLE 0x00008000
#تعریف_کړه STATE_SYSTEM_OFFSCREEN 0x00010000
#تعریف_کړه STATE_SYSTEM_SIZEABLE 0x00020000
#تعریف_کړه STATE_SYSTEM_MOVEABLE 0x00040000
#تعریف_کړه STATE_SYSTEM_SELFVOICING 0x00080000
#تعریف_کړه STATE_SYSTEM_FOCUSABLE 0x00100000
#تعریف_کړه STATE_SYSTEM_SELECTABLE 0x00200000
#تعریف_کړه STATE_SYSTEM_LINKED 0x00400000
#تعریف_کړه STATE_SYSTEM_TRAVERSED 0x00800000
#تعریف_کړه STATE_SYSTEM_MULTISELECTABLE 0x01000000
#تعریف_کړه STATE_SYSTEM_EXTSELECTABLE 0x02000000
#تعریف_کړه STATE_SYSTEM_ALERT_ټیټ 0x04000000
#تعریف_کړه STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#تعریف_کړه STATE_SYSTEM_ALERT_لوړ 0x10000000
#تعریف_کړه STATE_SYSTEM_PROTECTED 0x20000000
#تعریف_کړه STATE_SYSTEM_VALID 0x3FFFFFFF
#د_که_پای

#تعریف_کړه CCHILDREN_TITLEBAR 5
#تعریف_کړه CCHILDREN_SCROLLBAR 5

  تعريفنوع بنية نښان_CURSORINFO {
    DWORD cb_اندازه;
    DWORD flags;
    HCURSOR hCursor;
    ټکی_3 ptScreenPos;
  } CURSORINFO,*PCURSORINFO,*LPCURSORINFO;

#تعریف_کړه CURSOR_SHOWING 0x00000001

  WINUSERAPI WINBOOL WINAPI GetCursorInfo(PCURSORINFO pci);

  تعريفنوع بنية نښان_WINDOWINFO {
    DWORD cb_اندازه;
    RECT rc_کړکۍ;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dw_کړکۍ_حالت;
    UINT cx_کړکۍ_Borders;
    UINT cy_کړکۍ_Borders;
    ATOM atom_کړکۍ_Type;
    کلمه_3 w_Creator_نسخه;
  } WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;

#تعریف_کړه WS_ACTIVECAPTION 0x0001

  WINUSERAPI WINBOOL WINAPI Get_کړکۍ_Info(HWND hwnd,PWINDOWINFO pwi);

  تعريفنوع بنية نښان_TITLEBARINFO {
    DWORD cb_اندازه;
    RECT rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  } TITLEBARINFO,*PTITLEBARINFO,*LPTITLEBARINFO;

  WINUSERAPI WINBOOL WINAPI GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti);

  تعريفنوع بنية نښان_MENUBARINFO {
    DWORD cb_اندازه;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    WINBOOL fBarFocused:1;
    WINBOOL fFocused:1;
  } MENUBARINFO,*PMENUBARINFO,*LPMENUBARINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuBarInfo(HWND hwnd,LONG idObject,LONG id_توکی,PMENUBARINFO pmbi);

  تعريفنوع بنية نښان_SCROLLBARINFO {
    DWORD cb_اندازه;
    RECT rcScrollBar;
    صحيح dxy_کرښه_Button;
    صحيح xy_Thumb_سر;
    صحيح xyThumbBottom;
    صحيح reserved;
    DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
  } SCROLLBARINFO,*PSCROLLBARINFO,*LPSCROLLBARINFO;

  WINUSERAPI WINBOOL WINAPI GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);

  تعريفنوع بنية نښان_COMBOBOXINFO {
    DWORD cb_اندازه;
    RECT rc_توکی;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwnd_توکی;
    HWND hwndList;
  } COMBOBOXINFO,*PCOMBOBOXINFO,*LPCOMBOBOXINFO;

  WINUSERAPI WINBOOL WINAPI GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi);

#تعریف_کړه GA_پلار 1
#تعریف_کړه GA_ریښه 2
#تعریف_کړه GA_ROOTOWNER 3

  WINUSERAPI HWND WINAPI GetAncestor(HWND hwnd,UINT gaFlags);
  WINUSERAPI HWND WINAPI Real_ماشوم_کړکۍ_From_ټکی(HWND hwnd_پلار_2,ټکی_3 pt_پلار_Client_Coords);
  WINUSERAPI UINT WINAPI Real_Get_کړکۍ_Class_A(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
  WINUSERAPI UINT WINAPI Real_Get_کړکۍ_Class_W(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
#که_تعریف_شوی UNICODE
#تعریف_کړه Real_Get_کړکۍ_Class Real_Get_کړکۍ_Class_W
#وإلا
#تعریف_کړه Real_Get_کړکۍ_Class Real_Get_کړکۍ_Class_A
#د_که_پای

  تعريفنوع بنية نښان_ALTTABINFO {
    DWORD cb_اندازه;
    صحيح c_توکي;
    صحيح cColumns;
    صحيح c_لیکې;
    صحيح i_ستون_Focus;
    صحيح i_لیکه_Focus;
    صحيح cx_توکی;
    صحيح cy_توکی;
    ټکی_3 pt_پیل;
  } ALTTABINFO,*PALTTABINFO,*LPALTTABINFO;

#که_تعریف_شوی UNICODE
#تعریف_کړه GetAltTabInfo GetAltTabInfoW
#وإلا
#تعریف_کړه GetAltTabInfo GetAltTabInfoA
#د_که_پای

  WINUSERAPI WINBOOL WINAPI GetAltTabInfoA(HWND hwnd,صحيح i_توکی,PALTTABINFO pati,LPSTR psz_توکی_متن,UINT cch_توکی_متن);
  WINUSERAPI WINBOOL WINAPI GetAltTabInfoW(HWND hwnd,صحيح i_توکی,PALTTABINFO pati,LPWSTR psz_توکی_متن,UINT cch_توکی_متن);
  WINUSERAPI DWORD WINAPI GetListBoxInfo(HWND hwnd);
#د_که_پای

  WINUSERAPI WINBOOL WINAPI قلف_Work_Station(VOID);
  WINUSERAPI WINBOOL WINAPI UserHandleGrantAccess(HANDLE hUserHandle,HANDLE h_دنده,WINBOOL bGrant);

  DECLARE_HANDLE(HRAWINPUT);

#تعریف_کړه GET_RAWINPUT_کوډ_WPARAM(wParam) ((wParam) & 0xff)

#تعریف_کړه RIM_ننوت 0
#تعریف_کړه RIM_INPUTSINK 1

  تعريفنوع بنية نښان_RAWINPUTHEADER {
    DWORD dwType;
    DWORD dw_اندازه;
    HANDLE hDevice;
    WPARAM wParam;
  } RAWINPUTHEADER,*PRAWINPUTHEADER,*LPRAWINPUTHEADER;

#تعریف_کړه RIM_TYPEMOUSE 0
#تعریف_کړه RIM_TYPEKEYBOARD 1
#تعریف_کړه RIM_TYPEHID 2

  تعريفنوع بنية نښان_RAWMOUSE {
    USHORT usFlags;
    اتحاد {
      ULONG ulButtons;
      بنية {
	USHORT usButtonFlags;
	USHORT us_Button_معلومات;
      };
    };
    ULONG ulRawButtons;
    LONG l_وروستی_X;
    LONG l_وروستی_Y;
    ULONG ulExtraInformation;
  } RAWMOUSE,*PRAWMOUSE,*LPRAWMOUSE;

#تعریف_کړه RI_MOUSE_کیڼ_BUTTON_ښکته 0x0001
#تعریف_کړه RI_MOUSE_کیڼ_BUTTON_پورته 0x0002
#تعریف_کړه RI_MOUSE_ښی_BUTTON_ښکته 0x0004
#تعریف_کړه RI_MOUSE_ښی_BUTTON_پورته 0x0008
#تعریف_کړه RI_MOUSE_منځ_BUTTON_ښکته 0x0010
#تعریف_کړه RI_MOUSE_منځ_BUTTON_پورته 0x0020

#تعریف_کړه RI_MOUSE_BUTTON_1_ښکته RI_MOUSE_کیڼ_BUTTON_ښکته
#تعریف_کړه RI_MOUSE_BUTTON_1_پورته RI_MOUSE_کیڼ_BUTTON_پورته
#تعریف_کړه RI_MOUSE_BUTTON_2_ښکته RI_MOUSE_ښی_BUTTON_ښکته
#تعریف_کړه RI_MOUSE_BUTTON_2_پورته RI_MOUSE_ښی_BUTTON_پورته
#تعریف_کړه RI_MOUSE_BUTTON_3_ښکته RI_MOUSE_منځ_BUTTON_ښکته
#تعریف_کړه RI_MOUSE_BUTTON_3_پورته RI_MOUSE_منځ_BUTTON_پورته

#تعریف_کړه RI_MOUSE_BUTTON_4_ښکته 0x0040
#تعریف_کړه RI_MOUSE_BUTTON_4_پورته 0x0080
#تعریف_کړه RI_MOUSE_BUTTON_5_ښکته 0x0100
#تعریف_کړه RI_MOUSE_BUTTON_5_پورته 0x0200

#تعریف_کړه RI_MOUSE_WHEEL 0x0400

#تعریف_کړه MOUSE_MOVE_RELATIVE 0
#تعریف_کړه MOUSE_MOVE_ABSOLUTE 1
#تعریف_کړه MOUSE_VIRTUAL_DESKTOP 0x02
#تعریف_کړه MOUSE_ځانګړتیاوې_بدل_شوی 0x04

  تعريفنوع بنية نښان_RAWKEYBOARD {
    USHORT Make_کوډ;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT پیغام_6;
    ULONG ExtraInformation;
  } RAWKEYBOARD,*PRAWKEYBOARD,*LPRAWKEYBOARD;

#تعریف_کړه KEYBOARD_OVERRUN_MAKE_کوډ 0xFF

#تعریف_کړه RI_کلی_MAKE 0
#تعریف_کړه RI_کلی_BREAK 1
#تعریف_کړه RI_کلی_E0 2
#تعریف_کړه RI_کلی_E1 4
#تعریف_کړه RI_کلی_TERMSRV_سېټ_LED 8
#تعریف_کړه RI_کلی_TERMSRV_SHADOW 0x10

  تعريفنوع بنية نښان_RAWHID {
    DWORD dw_اندازه_Hid;
    DWORD dw_شمېر;
    BYTE b_Raw_معلومات[1];
  } RAWHID,*PRAWHID,*LPRAWHID;

  تعريفنوع بنية نښان_RAWINPUT {
    RAWINPUTHEADER سرلیک;
    اتحاد {
      RAWMOUSE mouse;
      RAWKEYBOARD keyboard;
      RAWHID hid;
    } معلومات;
  } RAWINPUT,*PRAWINPUT,*LPRAWINPUT;

#که_تعریف_شوی _WIN64
#تعریف_کړه RAWINPUT_ALIGN(x) (((x) + حجم(QWORD) - 1) & ~(حجم(QWORD) - 1))
#وإلا
#تعریف_کړه RAWINPUT_ALIGN(x) (((x) + حجم(DWORD) - 1) & ~(حجم(DWORD) - 1))
#د_که_پای

#تعریف_کړه NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->سرلیک.dw_اندازه)))

#تعریف_کړه RID_ننوت 0x10000003
#تعریف_کړه RID_سرلیک 0x10000005

  WINUSERAPI UINT WINAPI Get_Raw_ننوت_معلومات(HRAWINPUT h_Raw_ننوت,UINT uiCommand,LPVOID p_معلومات,PUINT pcb_اندازه,UINT cb_اندازه_سرلیک);

#تعریف_کړه RIDI_PREPARSEDDATA 0x20000005
#تعریف_کړه RIDI_DEVICENAME 0x20000007
#تعریف_کړه RIDI_DEVICEINFO 0x2000000b

  تعريفنوع بنية نښان_RID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dw_شمېره_د_Buttons;
    DWORD dw_Sample_شرح;
  } RID_DEVICE_INFO_MOUSE,*PRID_DEVICE_INFO_MOUSE;

  تعريفنوع بنية نښان_RID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dw_Keyboard_ډېرپېښ;
    DWORD dw_شمېره_د_Function_کلیګانې;
    DWORD dw_شمېره_د_Indicators;
    DWORD dw_شمېره_د_کلیګانې_ټول;
  } RID_DEVICE_INFO_KEYBOARD,*PRID_DEVICE_INFO_KEYBOARD;

  تعريفنوع بنية نښان_RID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dw_حاصل_ضرب_Id;
    DWORD dw_نسخه_شمېره;
    USHORT us_Usage_پاڼه;
    USHORT usUsage;
  } RID_DEVICE_INFO_HID,*PRID_DEVICE_INFO_HID;

  تعريفنوع بنية نښان_RID_DEVICE_INFO {
    DWORD cb_اندازه;
    DWORD dwType;
    اتحاد {
      RID_DEVICE_INFO_MOUSE mouse;
      RID_DEVICE_INFO_KEYBOARD keyboard;
      RID_DEVICE_INFO_HID hid;
    };
  } RID_DEVICE_INFO,*PRID_DEVICE_INFO,*LPRID_DEVICE_INFO;

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_Raw_ننوت_Device_Info Get_Raw_ننوت_Device_Info_W
#وإلا
#تعریف_کړه Get_Raw_ننوت_Device_Info Get_Raw_ننوت_Device_Info_A
#د_که_پای

  WINUSERAPI UINT WINAPI Get_Raw_ننوت_Device_Info_A(HANDLE hDevice,UINT uiCommand,LPVOID p_معلومات,PUINT pcb_اندازه);
  WINUSERAPI UINT WINAPI Get_Raw_ننوت_Device_Info_W(HANDLE hDevice,UINT uiCommand,LPVOID p_معلومات,PUINT pcb_اندازه);
  WINUSERAPI UINT WINAPI Get_Raw_ننوت_بفر(PRAWINPUT p_معلومات,PUINT pcb_اندازه,UINT cb_اندازه_سرلیک);

  تعريفنوع بنية نښان_RAWINPUTDEVICE {
    USHORT us_Usage_پاڼه;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwnd_موخه;
  } RAWINPUTDEVICE,*PRAWINPUTDEVICE,*LPRAWINPUTDEVICE;

  تعريفنوع CONST RAWINPUTDEVICE *PCRAWINPUTDEVICE;

#تعریف_کړه RIDEV_REMOVE 0x00000001
#تعریف_کړه RIDEV_EXCLUDE 0x00000010
#تعریف_کړه RIDEV_PAGEONLY 0x00000020
#تعریف_کړه RIDEV_NOLEGACY 0x00000030
#تعریف_کړه RIDEV_INPUTSINK 0x00000100
#تعریف_کړه RIDEV_CAPTUREMOUSE 0x00000200
#تعریف_کړه RIDEV_NOHOTKEYS 0x00000200
#تعریف_کړه RIDEV_APPKEYS 0x00000400
#تعریف_کړه RIDEV_EXMODEMASK 0x000000F0
#تعریف_کړه RIDEV_EXMODE(ډېرپېښ) ((ډېرپېښ) & RIDEV_EXMODEMASK)

  WINUSERAPI WINBOOL WINAPI ثبتوونکی_Raw_ننوت_Devices(PCRAWINPUTDEVICE p_Raw_ننوت_Devices,UINT ui_عدد_Devices,UINT cb_اندازه);
  WINUSERAPI UINT WINAPI Get_Registered_Raw_ننوت_Devices(PRAWINPUTDEVICE p_Raw_ننوت_Devices,PUINT pui_عدد_Devices,UINT cb_اندازه);

  تعريفنوع بنية نښان_RAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
  } RAWINPUTDEVICELIST,*PRAWINPUTDEVICELIST;

  WINUSERAPI UINT WINAPI Get_Raw_ننوت_Device_List(PRAWINPUTDEVICELIST p_Raw_ننوت_Device_List,PUINT pui_عدد_Devices,UINT cb_اندازه);
  WINUSERAPI LRESULT WINAPI Def_Raw_ننوت_Proc(PRAWINPUT *pa_Raw_ننوت,INT n_ننوت,UINT cb_اندازه_سرلیک);

#د_که_پای /* NOUSER */

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
