/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _WINUSER_
#تعریف_کرو _WINUSER_

#تعریف_کرو WINUSERAPI DECLSPEC_IMPORT

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف WINVER
#تعریف_کرو WINVER 0x0502
#جے_انت

#ضمن <stdarg.h>

#جے_بنا_تعریف NOUSER
  تعريفنوع HANDLE HDWP;
  تعريفنوع VOID MENUTEMPLATEA;
  تعريفنوع VOID MENUTEMPLATEW;
  تعريفنوع PVOID LPMENUTEMPLATEA;
  تعريفنوع PVOID LPMENUTEMPLATEW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع MENUTEMPLATEW MENUTEMPLATE;
  تعريفنوع LPMENUTEMPLATEW LPMENUTEMPLATE;
#وإلا
  تعريفنوع MENUTEMPLATEA MENUTEMPLATE;
  تعريفنوع LPMENUTEMPLATEA LPMENUTEMPLATE;
#جے_انت

  تعريفنوع LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
  تعريفنوع INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
  تعريفنوع VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
  تعريفنوع WINBOOL (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,صحيح);
  تعريفنوع WINBOOL (CALLBACK *WNDENUMPROC)(HWND,LPARAM);
  تعريفنوع LRESULT (CALLBACK *HOOKPROC)(صحيح کوڈ,WPARAM wParam,LPARAM lParam);
  تعريفنوع VOID (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
  تعريفنوع صحيح (CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch,صحيح ichCurrent,صحيح cch,صحيح کوڈ);
  تعريفنوع صحيح (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch,صحيح ichCurrent,صحيح cch,صحيح کوڈ);
  تعريفنوع WINBOOL (CALLBACK *DRAWSTATEPROC)(HDC hdc,LPARAM l_انکڑے,WPARAM w_انکڑے,صحيح cx,صحيح cy);

#جے_تعریف_شدہ UNICODE
  تعريفنوع PROPENUMPROCW PROPENUMPROC;
  تعريفنوع PROPENUMPROCEXW PROPENUMPROCEX;
  تعريفنوع EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#وإلا
  تعريفنوع PROPENUMPROCA PROPENUMPROC;
  تعريفنوع PROPENUMPROCEXA PROPENUMPROCEX;
  تعريفنوع EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#جے_انت

  تعريفنوع WINBOOL (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
  تعريفنوع WINBOOL (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
  تعريفنوع NAMEENUMPROCA WINSTAENUMPROCA;
  تعريفنوع NAMEENUMPROCA DESKTOPENUMPROCA;
  تعريفنوع NAMEENUMPROCW WINSTAENUMPROCW;
  تعريفنوع NAMEENUMPROCW DESKTOPENUMPROCW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع WINSTAENUMPROCW WINSTAENUMPROC;
  تعريفنوع DESKTOPENUMPROCW DESKTOPENUMPROC;
#وإلا
  تعريفنوع WINSTAENUMPROCA WINSTAENUMPROC;
  تعريفنوع DESKTOPENUMPROCA DESKTOPENUMPROC;
#جے_انت

#تعریف_کرو IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)
#تعریف_کرو MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((لفظ_3)(i))))
#تعریف_کرو MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((لفظ_3)(i))))
#جے_تعریف_شدہ UNICODE
#تعریف_کرو MAKEINTRESOURCE MAKEINTRESOURCEW
#وإلا
#تعریف_کرو MAKEINTRESOURCE MAKEINTRESOURCEA
#جے_انت

#جے_بنا_تعریف NORESOURCE

#تعریف_کرو RT_CURSOR MAKEINTRESOURCE(1)
#تعریف_کرو RT_BITMAP MAKEINTRESOURCE(2)
#تعریف_کرو RT_ICON MAKEINTRESOURCE(3)
#تعریف_کرو RT_MENU MAKEINTRESOURCE(4)
#تعریف_کرو RT_DIALOG MAKEINTRESOURCE(5)
#تعریف_کرو RT_STRING MAKEINTRESOURCE(6)
#تعریف_کرو RT_FONTDIR MAKEINTRESOURCE(7)
#تعریف_کرو RT_FONT MAKEINTRESOURCE(8)
#تعریف_کرو RT_ACCELERATOR MAKEINTRESOURCE(9)
#تعریف_کرو RT_RCDATA MAKEINTRESOURCE(10)
#تعریف_کرو RT_MESSAGETABLE MAKEINTRESOURCE(11)

#تعریف_کرو DIFFERENCE 11
#تعریف_کرو RT_گروہ_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
#تعریف_کرو RT_گروہ_ICON MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
#تعریف_کرو RT_نسخہ MAKEINTRESOURCE(16)
#تعریف_کرو RT_DLGINCLUDE MAKEINTRESOURCE(17)
#تعریف_کرو RT_PLUGPLAY MAKEINTRESOURCE(19)
#تعریف_کرو RT_VXD MAKEINTRESOURCE(20)
#تعریف_کرو RT_ANICURSOR MAKEINTRESOURCE(21)
#تعریف_کرو RT_ANIICON MAKEINTRESOURCE(22)
#تعریف_کرو RT_HTML MAKEINTRESOURCE(23)
#جے_تعریف_شدہ RC_INVOKED
#تعریف_کرو RT_MANIFEST 24
#تعریف_کرو CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#تعریف_کرو ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#تعریف_کرو ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#تعریف_کرو MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#تعریف_کرو ودھ_توں_ودھ_RESERVED_MANIFEST_RESOURCE_ID 16
#وإلا
#تعریف_کرو RT_MANIFEST MAKEINTRESOURCE(24)
#تعریف_کرو CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#تعریف_کرو ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#تعریف_کرو ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#تعریف_کرو MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#تعریف_کرو ودھ_توں_ودھ_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)
#جے_انت
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو wvsprintf wvsprintfW
#تعریف_کرو wsprintf wsprintfW
#وإلا
#تعریف_کرو wvsprintf wvsprintfA
#تعریف_کرو wsprintf wsprintfA
#جے_انت

  WINUSERAPI صحيح WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
  WINUSERAPI صحيح WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);
  WINUSERAPI صحيح WINAPIV wsprintfA(LPSTR,LPCSTR,...);
  WINUSERAPI صحيح WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);

#تعریف_کرو SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#جے_بنا_تعریف NOSCROLL
#تعریف_کرو SB_HORZ 0
#تعریف_کرو SB_VERT 1
#تعریف_کرو SB_CTL 2
#تعریف_کرو SB_BOTH 3

#تعریف_کرو SB_LINEUP 0
#تعریف_کرو SB_LINELEFT 0
#تعریف_کرو SB_LINEDOWN 1
#تعریف_کرو SB_LINERIGHT 1
#تعریف_کرو SB_PAGEUP 2
#تعریف_کرو SB_PAGELEFT 2
#تعریف_کرو SB_PAGEDOWN 3
#تعریف_کرو SB_PAGERIGHT 3
#تعریف_کرو SB_THUMBPOSITION 4
#تعریف_کرو SB_THUMBTRACK 5
#تعریف_کرو SB_چوٹی 6
#تعریف_کرو SB_بایاں 6
#تعریف_کرو SB_BOTTOM 7
#تعریف_کرو SB_دایاں 7
#تعریف_کرو SB_ENDSCROLL 8
#جے_انت

#جے_بنا_تعریف NOSHOWWINDOW
#تعریف_کرو SW_HIDE 0
#تعریف_کرو SW_SHOWNORMAL 1
#تعریف_کرو SW_عام 1
#تعریف_کرو SW_SHOWMINIMIZED 2
#تعریف_کرو SW_SHOWMAXIMIZED 3
#تعریف_کرو SW_MAXIMIZE 3
#تعریف_کرو SW_SHOWNOACTIVATE 4
#تعریف_کرو SW_SHOW 5
#تعریف_کرو SW_MINIMIZE 6
#تعریف_کرو SW_SHOWMINNOACTIVE 7
#تعریف_کرو SW_SHOWNA 8
#تعریف_کرو SW_RESTORE 9
#تعریف_کرو SW_SHOWDEFAULT 10
#تعریف_کرو SW_FORCEMINIMIZE 11
#تعریف_کرو SW_MAX 11

#تعریف_کرو HIDE_کھڑکی 0
#تعریف_کرو SHOW_OPENWINDOW 1
#تعریف_کرو SHOW_ICONWINDOW 2
#تعریف_کرو SHOW_FULLSCREEN 3
#تعریف_کرو SHOW_OPENNOACTIVATE 4

#تعریف_کرو SW_PARENTCLOSING 1
#تعریف_کرو SW_OTHERZOOM 2
#تعریف_کرو SW_PARENTOPENING 3
#تعریف_کرو SW_OTHERUNZOOM 4
#جے_انت

#تعریف_کرو AW_HOR_مثبت 0x00000001
#تعریف_کرو AW_HOR_NEGATIVE 0x00000002
#تعریف_کرو AW_VER_مثبت 0x00000004
#تعریف_کرو AW_VER_NEGATIVE 0x00000008
#تعریف_کرو AW_CENTER 0x00000010
#تعریف_کرو AW_HIDE 0x00010000
#تعریف_کرو AW_ACTIVATE 0x00020000
#تعریف_کرو AW_SLIDE 0x00040000
#تعریف_کرو AW_BLEND 0x00080000

#تعریف_کرو KF_EXTENDED 0x0100
#تعریف_کرو KF_DLGMODE 0x0800
#تعریف_کرو KF_MENUMODE 0x1000
#تعریف_کرو KF_ALTDOWN 0x2000
#تعریف_کرو KF_REPEAT 0x4000
#تعریف_کرو KF_اتے 0x8000

#جے_بنا_تعریف NOVIRTUALKEYCODES

#تعریف_کرو VK_LBUTTON 0x01
#تعریف_کرو VK_RBUTTON 0x02
#تعریف_کرو VK_CANCEL 0x03
#تعریف_کرو VK_MBUTTON 0x04
#تعریف_کرو VK_XBUTTON1 0x05
#تعریف_کرو VK_XBUTTON2 0x06
#تعریف_کرو VK_پٹھ 0x08
#تعریف_کرو VK_TAB 0x09
#تعریف_کرو VK_CLEAR 0x0C
#تعریف_کرو VK_RETURN 0x0D
#تعریف_کرو VK_کھسکاؤ 0x10
#تعریف_کرو VK_CONTROL 0x11
#تعریف_کرو VK_MENU 0x12
#تعریف_کرو VK_PAUSE 0x13
#تعریف_کرو VK_CAPITAL 0x14
#تعریف_کرو VK_KANA 0x15
#تعریف_کرو VK_HANGEUL 0x15
#تعریف_کرو VK_HANGUL 0x15
#تعریف_کرو VK_JUNJA 0x17
#تعریف_کرو VK_FINAL 0x18
#تعریف_کرو VK_HANJA 0x19
#تعریف_کرو VK_KANJI 0x19
#تعریف_کرو VK_ESCAPE 0x1B
#تعریف_کرو VK_CONVERT 0x1C
#تعریف_کرو VK_NONCONVERT 0x1D
#تعریف_کرو VK_ACCEPT 0x1E
#تعریف_کرو VK_MODECHANGE 0x1F
#تعریف_کرو VK_SPACE 0x20
#تعریف_کرو VK_پہلوں 0x21
#تعریف_کرو VK_اگلا 0x22
#تعریف_کرو VK_سرا 0x23
#تعریف_کرو VK_HOME 0x24
#تعریف_کرو VK_بایاں 0x25
#تعریف_کرو VK_اتے 0x26
#تعریف_کرو VK_دایاں 0x27
#تعریف_کرو VK_تھلے 0x28
#تعریف_کرو VK_SELECT 0x29
#تعریف_کرو VK_PRINT 0x2A
#تعریف_کرو VK_EXECUTE 0x2B
#تعریف_کرو VK_SNAPSHOT 0x2C
#تعریف_کرو VK_داخل_کرو 0x2D
#تعریف_کرو VK_DELETE 0x2E
#تعریف_کرو VK_HELP 0x2F

#تعریف_کرو VK_LWIN 0x5B
#تعریف_کرو VK_RWIN 0x5C
#تعریف_کرو VK_APPS 0x5D
#تعریف_کرو VK_SLEEP 0x5F
#تعریف_کرو VK_NUMPAD0 0x60
#تعریف_کرو VK_NUMPAD1 0x61
#تعریف_کرو VK_NUMPAD2 0x62
#تعریف_کرو VK_NUMPAD3 0x63
#تعریف_کرو VK_NUMPAD4 0x64
#تعریف_کرو VK_NUMPAD5 0x65
#تعریف_کرو VK_NUMPAD6 0x66
#تعریف_کرو VK_NUMPAD7 0x67
#تعریف_کرو VK_NUMPAD8 0x68
#تعریف_کرو VK_NUMPAD9 0x69
#تعریف_کرو VK_MULTIPLY 0x6A
#تعریف_کرو VK_جوڑو 0x6B
#تعریف_کرو VK_SEPARATOR 0x6C
#تعریف_کرو VK_گھٹاؤ 0x6D
#تعریف_کرو VK_DECIMAL 0x6E
#تعریف_کرو VK_DIVIDE 0x6F
#تعریف_کرو VK_F1 0x70
#تعریف_کرو VK_F2 0x71
#تعریف_کرو VK_F3 0x72
#تعریف_کرو VK_F4 0x73
#تعریف_کرو VK_F5 0x74
#تعریف_کرو VK_F6 0x75
#تعریف_کرو VK_F7 0x76
#تعریف_کرو VK_F8 0x77
#تعریف_کرو VK_F9 0x78
#تعریف_کرو VK_F10 0x79
#تعریف_کرو VK_F11 0x7A
#تعریف_کرو VK_F12 0x7B
#تعریف_کرو VK_F13 0x7C
#تعریف_کرو VK_F14 0x7D
#تعریف_کرو VK_F15 0x7E
#تعریف_کرو VK_F16 0x7F
#تعریف_کرو VK_F17 0x80
#تعریف_کرو VK_F18 0x81
#تعریف_کرو VK_F19 0x82
#تعریف_کرو VK_F20 0x83
#تعریف_کرو VK_F21 0x84
#تعریف_کرو VK_F22 0x85
#تعریف_کرو VK_F23 0x86
#تعریف_کرو VK_F24 0x87
#تعریف_کرو VK_NUMLOCK 0x90
#تعریف_کرو VK_SCROLL 0x91
#تعریف_کرو VK_OEM_NEC_EQUAL 0x92
#تعریف_کرو VK_OEM_FJ_JISHO 0x92
#تعریف_کرو VK_OEM_FJ_MASSHOU 0x93
#تعریف_کرو VK_OEM_FJ_TOUROKU 0x94
#تعریف_کرو VK_OEM_FJ_LOYA 0x95
#تعریف_کرو VK_OEM_FJ_ROYA 0x96
#تعریف_کرو VK_LSHIFT 0xA0
#تعریف_کرو VK_RSHIFT 0xA1
#تعریف_کرو VK_LCONTROL 0xA2
#تعریف_کرو VK_RCONTROL 0xA3
#تعریف_کرو VK_LMENU 0xA4
#تعریف_کرو VK_RMENU 0xA5
#تعریف_کرو VK_BROWSER_پٹھ 0xA6
#تعریف_کرو VK_BROWSER_FORWARD 0xA7
#تعریف_کرو VK_BROWSER_REFRESH 0xA8
#تعریف_کرو VK_BROWSER_STOP 0xA9
#تعریف_کرو VK_BROWSER_تلاش 0xAA
#تعریف_کرو VK_BROWSER_FAVORITES 0xAB
#تعریف_کرو VK_BROWSER_HOME 0xAC
#تعریف_کرو VK_VOLUME_MUTE 0xAD
#تعریف_کرو VK_VOLUME_تھلے 0xAE
#تعریف_کرو VK_VOLUME_اتے 0xAF
#تعریف_کرو VK_MEDIA_اگلا_TRACK 0xB0
#تعریف_کرو VK_MEDIA_PREV_TRACK 0xB1
#تعریف_کرو VK_MEDIA_STOP 0xB2
#تعریف_کرو VK_MEDIA_PLAY_PAUSE 0xB3
#تعریف_کرو VK_LAUNCH_MAIL 0xB4
#تعریف_کرو VK_LAUNCH_MEDIA_SELECT 0xB5
#تعریف_کرو VK_LAUNCH_APP1 0xB6
#تعریف_کرو VK_LAUNCH_APP2 0xB7
#تعریف_کرو VK_OEM_1 0xBA
#تعریف_کرو VK_OEM_PLUS 0xBB
#تعریف_کرو VK_OEM_COMMA 0xBC
#تعریف_کرو VK_OEM_MINUS 0xBD
#تعریف_کرو VK_OEM_PERIOD 0xBE
#تعریف_کرو VK_OEM_2 0xBF
#تعریف_کرو VK_OEM_3 0xC0
#تعریف_کرو VK_OEM_4 0xDB
#تعریف_کرو VK_OEM_5 0xDC
#تعریف_کرو VK_OEM_6 0xDD
#تعریف_کرو VK_OEM_7 0xDE
#تعریف_کرو VK_OEM_8 0xDF
#تعریف_کرو VK_OEM_AX 0xE1
#تعریف_کرو VK_OEM_102 0xE2
#تعریف_کرو VK_ICO_HELP 0xE3
#تعریف_کرو VK_ICO_00 0xE4
#تعریف_کرو VK_PROCESSKEY 0xE5
#تعریف_کرو VK_ICO_CLEAR 0xE6
#تعریف_کرو VK_PACKET 0xE7
#تعریف_کرو VK_OEM_RESET 0xE9
#تعریف_کرو VK_OEM_JUMP 0xEA
#تعریف_کرو VK_OEM_PA1 0xEB
#تعریف_کرو VK_OEM_PA2 0xEC
#تعریف_کرو VK_OEM_PA3 0xED
#تعریف_کرو VK_OEM_WSCTRL 0xEE
#تعریف_کرو VK_OEM_CUSEL 0xEF
#تعریف_کرو VK_OEM_ATTN 0xF0
#تعریف_کرو VK_OEM_انت 0xF1
#تعریف_کرو VK_OEM_COPY 0xF2
#تعریف_کرو VK_OEM_AUTO 0xF3
#تعریف_کرو VK_OEM_ENLW 0xF4
#تعریف_کرو VK_OEM_BACKTAB 0xF5
#تعریف_کرو VK_ATTN 0xF6
#تعریف_کرو VK_CRSEL 0xF7
#تعریف_کرو VK_EXSEL 0xF8
#تعریف_کرو VK_EREOF 0xF9
#تعریف_کرو VK_PLAY 0xFA
#تعریف_کرو VK_ZOOM 0xFB
#تعریف_کرو VK_NONAME 0xFC
#تعریف_کرو VK_PA1 0xFD
#تعریف_کرو VK_OEM_CLEAR 0xFE
#جے_انت

#جے_بنا_تعریف NOWH

#تعریف_کرو WH_MIN (-1)
#تعریف_کرو WH_MSGFILTER (-1)
#تعریف_کرو WH_JOURNALRECORD 0
#تعریف_کرو WH_JOURNALPLAYBACK 1
#تعریف_کرو WH_KEYBOARD 2
#تعریف_کرو WH_GETMESSAGE 3
#تعریف_کرو WH_CALLWNDPROC 4
#تعریف_کرو WH_CBT 5
#تعریف_کرو WH_SYSMSGFILTER 6
#تعریف_کرو WH_MOUSE 7
#تعریف_کرو WH_HARDWARE 8
#تعریف_کرو WH_DEBUG 9
#تعریف_کرو WH_SHELL 10
#تعریف_کرو WH_FOREGROUNDIDLE 11
#تعریف_کرو WH_CALLWNDPROCRET 12

#تعریف_کرو WH_KEYBOARD_LL 13
#تعریف_کرو WH_MOUSE_LL 14

#تعریف_کرو WH_MAX 14

#تعریف_کرو WH_MINHOOK WH_MIN
#تعریف_کرو WH_MAXHOOK WH_MAX

#تعریف_کرو HC_ACTION 0
#تعریف_کرو HC_GETNEXT 1
#تعریف_کرو HC_SKIP 2
#تعریف_کرو HC_NOREMOVE 3
#تعریف_کرو HC_NOREM HC_NOREMOVE
#تعریف_کرو HC_SYSMODALON 4
#تعریف_کرو HC_SYSMODALOFF 5

#تعریف_کرو HCBT_MOVESIZE 0
#تعریف_کرو HCBT_MINMAX 1
#تعریف_کرو HCBT_QS 2
#تعریف_کرو HCBT_CREATEWND 3
#تعریف_کرو HCBT_DESTROYWND 4
#تعریف_کرو HCBT_ACTIVATE 5
#تعریف_کرو HCBT_CLICKSKIPPED 6
#تعریف_کرو HCBT_KEYSKIPPED 7
#تعریف_کرو HCBT_SYSCOMMAND 8
#تعریف_کرو HCBT_SETFOCUS 9

  تعريفنوع بنية ٹیگ_CBT_CREATEWNDA {
    بنية ٹیگ_CREATESTRUCTA *lpcs;
    HWND hwnd_داخل_کرو_After;
  } CBT_CREATEWNDA,*LPCBT_CREATEWNDA;

  تعريفنوع بنية ٹیگ_CBT_CREATEWNDW {
    بنية ٹیگ_CREATESTRUCTW *lpcs;
    HWND hwnd_داخل_کرو_After;
  } CBT_CREATEWNDW,*LPCBT_CREATEWNDW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع CBT_CREATEWNDW CBT_CREATEWND;
  تعريفنوع LPCBT_CREATEWNDW LPCBT_CREATEWND;
#وإلا
  تعريفنوع CBT_CREATEWNDA CBT_CREATEWND;
  تعريفنوع LPCBT_CREATEWNDA LPCBT_CREATEWND;
#جے_انت

  تعريفنوع بنية ٹیگ_CBTACTIVATESTRUCT
  {
    WINBOOL fMouse;
    HWND h_Wnd_سرگرم;
  } CBTACTIVATESTRUCT,*LPCBTACTIVATESTRUCT;

  تعريفنوع بنية ٹیگ_WTSSESSION_NOTIFICATION {
    DWORD cb_ناپ;
    DWORD dwSessionId;

  } WTSSESSION_NOTIFICATION,*PWTSSESSION_NOTIFICATION;

#تعریف_کرو WTS_CONSOLE_CONNECT 0x1
#تعریف_کرو WTS_CONSOLE_DISCONNECT 0x2
#تعریف_کرو WTS_REMOTE_CONNECT 0x3
#تعریف_کرو WTS_REMOTE_DISCONNECT 0x4
#تعریف_کرو WTS_SESSION_LOGON 0x5
#تعریف_کرو WTS_SESSION_LOGOFF 0x6
#تعریف_کرو WTS_SESSION_جندرا 0x7
#تعریف_کرو WTS_SESSION_UNLOCK 0x8
#تعریف_کرو WTS_SESSION_REMOTE_CONTROL 0x9

#تعریف_کرو MSGF_DIALOGBOX 0
#تعریف_کرو MSGF_MESSAGEBOX 1
#تعریف_کرو MSGF_MENU 2
#تعریف_کرو MSGF_SCROLLBAR 5
#تعریف_کرو MSGF_NEXTWINDOW 6
#تعریف_کرو MSGF_MAX 8
#تعریف_کرو MSGF_USER 4096

#تعریف_کرو HSHELL_WINDOWCREATED 1
#تعریف_کرو HSHELL_WINDOWDESTROYED 2
#تعریف_کرو HSHELL_ACTIVATESHELLWINDOW 3

#تعریف_کرو HSHELL_WINDOWACTIVATED 4
#تعریف_کرو HSHELL_GETMINRECT 5
#تعریف_کرو HSHELL_REDRAW 6
#تعریف_کرو HSHELL_TASKMAN 7
#تعریف_کرو HSHELL_LANGUAGE 8
#تعریف_کرو HSHELL_SYSMENU 9
#تعریف_کرو HSHELL_ENDTASK 10
#تعریف_کرو HSHELL_ACCESSIBILITYSTATE 11
#تعریف_کرو HSHELL_APPCOMMAND 12
#تعریف_کرو HSHELL_WINDOWREPLACED 13
#تعریف_کرو HSHELL_WINDOWREPLACING 14
#تعریف_کرو HSHELL_HIGHBIT 0x8000
#تعریف_کرو HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#تعریف_کرو HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#تعریف_کرو ACCESS_STICKYKEYS 0x0001
#تعریف_کرو ACCESS_FILTERKEYS 0x0002
#تعریف_کرو ACCESS_MOUSEKEYS 0x0003

#تعریف_کرو APPCOMMAND_BROWSER_BACKWARD 1
#تعریف_کرو APPCOMMAND_BROWSER_FORWARD 2
#تعریف_کرو APPCOMMAND_BROWSER_REFRESH 3
#تعریف_کرو APPCOMMAND_BROWSER_STOP 4
#تعریف_کرو APPCOMMAND_BROWSER_تلاش 5
#تعریف_کرو APPCOMMAND_BROWSER_FAVORITES 6
#تعریف_کرو APPCOMMAND_BROWSER_HOME 7
#تعریف_کرو APPCOMMAND_VOLUME_MUTE 8
#تعریف_کرو APPCOMMAND_VOLUME_تھلے 9
#تعریف_کرو APPCOMMAND_VOLUME_اتے 10
#تعریف_کرو APPCOMMAND_MEDIA_NEXTTRACK 11
#تعریف_کرو APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#تعریف_کرو APPCOMMAND_MEDIA_STOP 13
#تعریف_کرو APPCOMMAND_MEDIA_PLAY_PAUSE 14
#تعریف_کرو APPCOMMAND_LAUNCH_MAIL 15
#تعریف_کرو APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#تعریف_کرو APPCOMMAND_LAUNCH_APP1 17
#تعریف_کرو APPCOMMAND_LAUNCH_APP2 18
#تعریف_کرو APPCOMMAND_BASS_تھلے 19
#تعریف_کرو APPCOMMAND_BASS_BOOST 20
#تعریف_کرو APPCOMMAND_BASS_اتے 21
#تعریف_کرو APPCOMMAND_TREBLE_تھلے 22
#تعریف_کرو APPCOMMAND_TREBLE_اتے 23
#تعریف_کرو APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#تعریف_کرو APPCOMMAND_MICROPHONE_VOLUME_تھلے 25
#تعریف_کرو APPCOMMAND_MICROPHONE_VOLUME_اتے 26
#تعریف_کرو APPCOMMAND_HELP 27
#تعریف_کرو APPCOMMAND_لبھو 28
#تعریف_کرو APPCOMMAND_NEW 29
#تعریف_کرو APPCOMMAND_OPEN 30
#تعریف_کرو APPCOMMAND_CLOSE 31
#تعریف_کرو APPCOMMAND_SAVE 32
#تعریف_کرو APPCOMMAND_PRINT 33
#تعریف_کرو APPCOMMAND_UNDO 34
#تعریف_کرو APPCOMMAND_REDO 35
#تعریف_کرو APPCOMMAND_COPY 36
#تعریف_کرو APPCOMMAND_CUT 37
#تعریف_کرو APPCOMMAND_PASTE 38
#تعریف_کرو APPCOMMAND_جواب_منزل_MAIL 39
#تعریف_کرو APPCOMMAND_FORWARD_MAIL 40
#تعریف_کرو APPCOMMAND_SEND_MAIL 41
#تعریف_کرو APPCOMMAND_SPELL_CHECK 42
#تعریف_کرو APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#تعریف_کرو APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#تعریف_کرو APPCOMMAND_CORRECTION_LIST 45
#تعریف_کرو APPCOMMAND_MEDIA_PLAY 46
#تعریف_کرو APPCOMMAND_MEDIA_PAUSE 47
#تعریف_کرو APPCOMMAND_MEDIA_ریکارڈ 48
#تعریف_کرو APPCOMMAND_MEDIA_FAST_FORWARD 49
#تعریف_کرو APPCOMMAND_MEDIA_REWIND 50
#تعریف_کرو APPCOMMAND_MEDIA_CHANNEL_اتے 51
#تعریف_کرو APPCOMMAND_MEDIA_CHANNEL_تھلے 52

#تعریف_کرو FAPPCOMMAND_MOUSE 0x8000
#تعریف_کرو FAPPCOMMAND_کلید 0
#تعریف_کرو FAPPCOMMAND_OEM 0x1000
#تعریف_کرو FAPPCOMMAND_نقاب 0xF000

#تعریف_کرو GET_APPCOMMAND_LPARAM(lParam) ((چھوٹا)(HIWORD(lParam) & ~FAPPCOMMAND_نقاب))
#تعریف_کرو GET_DEVICE_LPARAM(lParam) ((لفظ_3)(HIWORD(lParam) & FAPPCOMMAND_نقاب))
#تعریف_کرو GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#تعریف_کرو GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#تعریف_کرو GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)

  تعريفنوع بنية {
    HWND hwnd;
    RECT rc;
  } SHELLHOOKINFO,*LPSHELLHOOKINFO;

  تعريفنوع بنية ٹیگ_EVENTMSG {
    UINT سنیہا;
    UINT paramL;
    UINT paramH;
    DWORD ویلا;
    HWND hwnd;
  } EVENTMSG,*PEVENTMSGMSG,*NPEVENTMSGMSG,*LPEVENTMSGMSG;

  تعريفنوع بنية ٹیگ_EVENTMSG *PEVENTMSG,*NPEVENTMSG,*LPEVENTMSG;

  تعريفنوع بنية ٹیگ_CWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT سنیہا;
    HWND hwnd;
  } CWPSTRUCT,*PCWPSTRUCT,*NPCWPSTRUCT,*LPCWPSTRUCT;

  تعريفنوع بنية ٹیگ_CWPRETSTRUCT {
    LRESULT l_نتیجہ;
    LPARAM lParam;
    WPARAM wParam;
    UINT سنیہا;
    HWND hwnd;
  } CWPRETSTRUCT,*PCWPRETSTRUCT,*NPCWPRETSTRUCT,*LPCWPRETSTRUCT;

#تعریف_کرو LLKHF_EXTENDED (KF_EXTENDED >> 8)
#تعریف_کرو LLKHF_INJECTED 0x00000010
#تعریف_کرو LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#تعریف_کرو LLKHF_اتے (KF_اتے >> 8)

#تعریف_کرو LLMHF_INJECTED 0x00000001

  تعريفنوع بنية ٹیگ_KBDLLHOOKSTRUCT {
    DWORD vk_کوڈ;
    DWORD جانچ_کوڈ;
    DWORD flags;
    DWORD ویلا;
    ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;

  تعريفنوع بنية ٹیگ_MSLLHOOKSTRUCT {
    نقطہ_3 pt;
    DWORD mouse_انکڑے;
    DWORD flags;
    DWORD ویلا;
    ULONG_PTR dwExtraInfo;
  } MSLLHOOKSTRUCT,*LPMSLLHOOKSTRUCT,*PMSLLHOOKSTRUCT;

  تعريفنوع بنية ٹیگ_DEBUGHOOKINFO {
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    صحيح کوڈ;
  } DEBUGHOOKINFO,*PDEBUGHOOKINFO,*NPDEBUGHOOKINFO,*LPDEBUGHOOKINFO;

  تعريفنوع بنية ٹیگ_MOUSEHOOKSTRUCT {
    نقطہ_3 pt;
    HWND hwnd;
    UINT w_کامیابی_Test_کوڈ;
    ULONG_PTR dwExtraInfo;
  } MOUSEHOOKSTRUCT,*LPMOUSEHOOKSTRUCT,*PMOUSEHOOKSTRUCT;

#جے_تعریف_شدہ __cplusplus
  تعريفنوع بنية ٹیگ_MOUSEHOOKSTRUCTEX : عام ٹیگ_MOUSEHOOKSTRUCT {
    DWORD mouse_انکڑے;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#وإلا
  تعريفنوع بنية ٹیگ_MOUSEHOOKSTRUCTEX {
    MOUSEHOOKSTRUCT _unnamed;
    DWORD mouse_انکڑے;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#جے_انت

  تعريفنوع بنية ٹیگ_HARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT سنیہا;
    WPARAM wParam;
    LPARAM lParam;
  } HARDWAREHOOKSTRUCT,*LPHARDWAREHOOKSTRUCT,*PHARDWAREHOOKSTRUCT;
#جے_انت

#تعریف_کرو HKL_PREV 0
#تعریف_کرو HKL_اگلا 1

#تعریف_کرو KLF_ACTIVATE 0x00000001
#تعریف_کرو KLF_SUBSTITUTE_OK 0x00000002
#تعریف_کرو KLF_REORDER 0x00000008
#تعریف_کرو KLF_REPLACELANG 0x00000010
#تعریف_کرو KLF_NOTELLSHELL 0x00000080
#تعریف_کرو KLF_SETFORPROCESS 0x00000100
#تعریف_کرو KLF_SHIFTLOCK 0x00010000
#تعریف_کرو KLF_RESET 0x40000000

#تعریف_کرو INPUTLANGCHANGE_SYSCHARSET 0x0001
#تعریف_کرو INPUTLANGCHANGE_FORWARD 0x0002
#تعریف_کرو INPUTLANGCHANGE_BACKWARD 0x0004

#تعریف_کرو KL_NAMELENGTH 9

#جے_تعریف_شدہ UNICODE
#تعریف_کرو لدو_Keyboard_Layout لدو_Keyboard_Layout_W
#تعریف_کرو GetKeyboardLayoutName GetKeyboardLayoutNameW
#وإلا
#تعریف_کرو لدو_Keyboard_Layout لدو_Keyboard_Layout_A
#تعریف_کرو GetKeyboardLayoutName GetKeyboardLayoutNameA
#جے_انت

  WINUSERAPI HKL WINAPI لدو_Keyboard_Layout_A(LPCSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI لدو_Keyboard_Layout_W(LPCWSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ActivateKeyboardLayout(HKL hkl,UINT Flags);
  WINUSERAPI صحيح WINAPI منزل_Unicode_Ex(UINT w_Virt_کلید,UINT w_جانچ_کوڈ,CONST BYTE *lp_کلید_State,LPWSTR pwszBuff,صحيح cchBuff,UINT wFlags,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI UnloadKeyboardLayout(HKL hkl);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameA(LPSTR pwszKLID);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameW(LPWSTR pwszKLID);
  WINUSERAPI صحيح WINAPI GetKeyboardLayoutList(صحيح nBuff,HKL *lpList);
  WINUSERAPI HKL WINAPI GetKeyboardLayout(DWORD idThread);

  تعريفنوع بنية ٹیگ_MOUSEMOVEPOINT {
    صحيح x;
    صحيح y;
    DWORD ویلا;
    ULONG_PTR dwExtraInfo;
  } MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

#تعریف_کرو GMMP_USE_DISPLAY_POINTS 1
#تعریف_کرو GMMP_USE_بلند_RESOLUTION_POINTS 2

  WINUSERAPI صحيح WINAPI GetMouseMovePointsEx(UINT cb_ناپ,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,صحيح nBufPoints,DWORD resolution);

#جے_بنا_تعریف NODESKTOP

#تعریف_کرو DESKTOP_READOBJECTS 0x0001L
#تعریف_کرو DESKTOP_CREATEWINDOW 0x0002L
#تعریف_کرو DESKTOP_CREATEMENU 0x0004L
#تعریف_کرو DESKTOP_HOOKCONTROL 0x0008L
#تعریف_کرو DESKTOP_JOURNALRECORD 0x0010L
#تعریف_کرو DESKTOP_JOURNALPLAYBACK 0x0020L
#تعریف_کرو DESKTOP_ENUMERATE 0x0040L
#تعریف_کرو DESKTOP_WRITEOBJECTS 0x0080L
#تعریف_کرو DESKTOP_SWITCHDESKTOP 0x0100L

#تعریف_کرو DF_ALLOWOTHERACCOUNTHOOK 0x0001L

#جے_تعریف_شدہ _WINGDI_
#جے_بنا_تعریف NOGDI
#جے_تعریف_شدہ UNICODE
#تعریف_کرو CreateDesktop CreateDesktopW
#وإلا
#تعریف_کرو CreateDesktop CreateDesktopA
#جے_انت

  WINUSERAPI HDESK WINAPI CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,LPDEVMODEA pDevmode,DWORD dwFlags,ACCESS_نقاب dwDesiredAccess,LPSECURITY_گن lpsa);
  WINUSERAPI HDESK WINAPI CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,LPDEVMODEW pDevmode,DWORD dwFlags,ACCESS_نقاب dwDesiredAccess,LPSECURITY_گن lpsa);
#جے_انت
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو OpenDesktop OpenDesktopW
#تعریف_کرو EnumDesktops EnumDesktopsW
#وإلا
#تعریف_کرو OpenDesktop OpenDesktopA
#تعریف_کرو EnumDesktops EnumDesktopsA
#جے_انت

  WINUSERAPI HDESK WINAPI OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI HDESK WINAPI Open_داخلہ_Desktop(DWORD dwFlags,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SwitchDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI سیٹ_Thread_Desktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI CloseDesktop(HDESK hDesktop);
  WINUSERAPI HDESK WINAPI GetThreadDesktop(DWORD dwThreadId);
#جے_انت

#جے_بنا_تعریف NOWINDOWSTATION
#تعریف_کرو WINSTA_ENUMDESKTOPS 0x0001L
#تعریف_کرو WINSTA_READATTRIBUTES 0x0002L
#تعریف_کرو WINSTA_ACCESSCLIPBOARD 0x0004L
#تعریف_کرو WINSTA_CREATEDESKTOP 0x0008L
#تعریف_کرو WINSTA_WRITEATTRIBUTES 0x0010L
#تعریف_کرو WINSTA_ACCESSGLOBALATOMS 0x0020L
#تعریف_کرو WINSTA_EXITWINDOWS 0x0040L
#تعریف_کرو WINSTA_ENUMERATE 0x0100L
#تعریف_کرو WINSTA_READSCREEN 0x0200L
#تعریف_کرو WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#تعریف_کرو CWF_CREATE_ONLY 0x0001L

#تعریف_کرو WSF_VISIBLE 0x0001L

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Create_کھڑکی_Station Create_کھڑکی_Station_W
#تعریف_کرو Open_کھڑکی_Station Open_کھڑکی_Station_W
#تعریف_کرو Enum_کھڑکی_Stations Enum_کھڑکی_Stations_W
#وإلا
#تعریف_کرو Create_کھڑکی_Station Create_کھڑکی_Station_A
#تعریف_کرو Open_کھڑکی_Station Open_کھڑکی_Station_A
#تعریف_کرو Enum_کھڑکی_Stations Enum_کھڑکی_Stations_A
#جے_انت

  WINUSERAPI HWINSTA WINAPI Create_کھڑکی_Station_A(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_نقاب dwDesiredAccess,LPSECURITY_گن lpsa);
  WINUSERAPI HWINSTA WINAPI Create_کھڑکی_Station_W(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_نقاب dwDesiredAccess,LPSECURITY_گن lpsa);
  WINUSERAPI HWINSTA WINAPI Open_کھڑکی_Station_A(LPCSTR lpszWinSta,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI HWINSTA WINAPI Open_کھڑکی_Station_W(LPCWSTR lpszWinSta,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI Enum_کھڑکی_Stations_A(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Enum_کھڑکی_Stations_W(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Close_کھڑکی_Station(HWINSTA hWinSta);
  WINUSERAPI WINBOOL WINAPI سیٹ_Process_کھڑکی_Station(HWINSTA hWinSta);
  WINUSERAPI HWINSTA WINAPI Get_Process_کھڑکی_Station(VOID);
#جے_انت

#جے_بنا_تعریف NOSECURITY
  WINUSERAPI WINBOOL WINAPI سیٹ_User_Object_Security(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
  WINUSERAPI WINBOOL WINAPI GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD n_لمائی,LPDWORD lpn_لمائی_Needed);

#تعریف_کرو UOI_FLAGS 1
#تعریف_کرو UOI_NAME 2
#تعریف_کرو UOI_TYPE 3
#تعریف_کرو UOI_USER_SID 4

  تعريفنوع بنية ٹیگ_USEROBJECTFLAGS {
    WINBOOL fInherit;
    WINBOOL fReserved;
    DWORD dwFlags;
  } USEROBJECTFLAGS,*PUSEROBJECTFLAGS;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو GetUserObjectInformation GetUserObjectInformationW
#تعریف_کرو سیٹ_User_Object_Information سیٹ_User_Object_Information_W
#وإلا
#تعریف_کرو GetUserObjectInformation GetUserObjectInformationA
#تعریف_کرو سیٹ_User_Object_Information سیٹ_User_Object_Information_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationA(HANDLE hObj,صحيح n_اشاریہ,PVOID pvInfo,DWORD n_لمائی,LPDWORD lpn_لمائی_Needed);
  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationW(HANDLE hObj,صحيح n_اشاریہ,PVOID pvInfo,DWORD n_لمائی,LPDWORD lpn_لمائی_Needed);
  WINUSERAPI WINBOOL WINAPI سیٹ_User_Object_Information_A(HANDLE hObj,صحيح n_اشاریہ,PVOID pvInfo,DWORD n_لمائی);
  WINUSERAPI WINBOOL WINAPI سیٹ_User_Object_Information_W(HANDLE hObj,صحيح n_اشاریہ,PVOID pvInfo,DWORD n_لمائی);
#جے_انت

  تعريفنوع بنية ٹیگ_WNDCLASSEXA {
    UINT cb_ناپ;
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

  تعريفنوع بنية ٹیگ_WNDCLASSEXW {
    UINT cb_ناپ;
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

#جے_تعریف_شدہ UNICODE
  تعريفنوع WNDCLASSEXW WNDCLASSEX;
  تعريفنوع PWNDCLASSEXW PWNDCLASSEX;
  تعريفنوع NPWNDCLASSEXW NPWNDCLASSEX;
  تعريفنوع LPWNDCLASSEXW LPWNDCLASSEX;
#وإلا
  تعريفنوع WNDCLASSEXA WNDCLASSEX;
  تعريفنوع PWNDCLASSEXA PWNDCLASSEX;
  تعريفنوع NPWNDCLASSEXA NPWNDCLASSEX;
  تعريفنوع LPWNDCLASSEXA LPWNDCLASSEX;
#جے_انت

  تعريفنوع بنية ٹیگ_WNDCLASSA {
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

  تعريفنوع بنية ٹیگ_WNDCLASSW {
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

#جے_تعریف_شدہ UNICODE
  تعريفنوع WNDCLASSW WNDCLASS;
  تعريفنوع PWNDCLASSW PWNDCLASS;
  تعريفنوع NPWNDCLASSW NPWNDCLASS;
  تعريفنوع LPWNDCLASSW LPWNDCLASS;
#وإلا
  تعريفنوع WNDCLASSA WNDCLASS;
  تعريفنوع PWNDCLASSA PWNDCLASS;
  تعريفنوع NPWNDCLASSA NPWNDCLASS;
  تعريفنوع LPWNDCLASSA LPWNDCLASS;
#جے_انت

  WINUSERAPI WINBOOL WINAPI Is_Hung_App_کھڑکی(HWND hwnd);
  WINUSERAPI VOID WINAPI DisableProcessWindowsGhosting(VOID);

#جے_بنا_تعریف NOMSG
  تعريفنوع بنية ٹیگ_پیغام {
    HWND hwnd;
    UINT سنیہا;
    WPARAM wParam;
    LPARAM lParam;
    DWORD ویلا;
    نقطہ_3 pt;
  } پیغام_2,*PMSG,*NPMSG,*LPMSG;

#تعریف_کرو POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#تعریف_کرو POINTTOPOINTS(pt) (MAKELONG((چھوٹا)((pt).x),(چھوٹا)((pt).y)))
#تعریف_کرو MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#تعریف_کرو MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#تعریف_کرو MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))
#جے_انت

#جے_بنا_تعریف NOWINOFFSETS
#تعریف_کرو GWL_WNDPROC (-4)
#تعریف_کرو GWL_HINSTANCE (-6)
#تعریف_کرو GWL_HWNDPARENT (-8)
#تعریف_کرو GWL_STYLE (-16)
#تعریف_کرو GWL_EXSTYLE (-20)
#تعریف_کرو GWL_USERDATA (-21)
#تعریف_کرو GWL_ID (-12)

#جے_تعریف_شدہ _WIN64
#تعریف_رد GWL_WNDPROC
#تعریف_رد GWL_HINSTANCE
#تعریف_رد GWL_HWNDPARENT
#تعریف_رد GWL_USERDATA
#جے_انت

#تعریف_کرو GWLP_WNDPROC (-4)
#تعریف_کرو GWLP_HINSTANCE (-6)
#تعریف_کرو GWLP_HWNDPARENT (-8)
#تعریف_کرو GWLP_USERDATA (-21)
#تعریف_کرو GWLP_ID (-12)

#تعریف_کرو GCL_MENUNAME (-8)
#تعریف_کرو GCL_HBRBACKGROUND (-10)
#تعریف_کرو GCL_HCURSOR (-12)
#تعریف_کرو GCL_HICON (-14)
#تعریف_کرو GCL_HMODULE (-16)
#تعریف_کرو GCL_CBWNDEXTRA (-18)
#تعریف_کرو GCL_CBCLSEXTRA (-20)
#تعریف_کرو GCL_WNDPROC (-24)
#تعریف_کرو GCL_STYLE (-26)
#تعریف_کرو GCW_ATOM (-32)
#تعریف_کرو GCL_HICONSM (-34)

#جے_تعریف_شدہ _WIN64

#تعریف_رد GCL_MENUNAME
#تعریف_رد GCL_HBRBACKGROUND
#تعریف_رد GCL_HCURSOR
#تعریف_رد GCL_HICON
#تعریف_رد GCL_HMODULE
#تعریف_رد GCL_WNDPROC
#تعریف_رد GCL_HICONSM
#جے_انت

#تعریف_کرو GCLP_MENUNAME (-8)
#تعریف_کرو GCLP_HBRBACKGROUND (-10)
#تعریف_کرو GCLP_HCURSOR (-12)
#تعریف_کرو GCLP_HICON (-14)
#تعریف_کرو GCLP_HMODULE (-16)
#تعریف_کرو GCLP_WNDPROC (-24)
#تعریف_کرو GCLP_HICONSM (-34)
#جے_انت

#جے_بنا_تعریف NOWINMESSAGES

#تعریف_کرو WM_NULL 0x0000
#تعریف_کرو WM_CREATE 0x0001
#تعریف_کرو WM_DESTROY 0x0002
#تعریف_کرو WM_MOVE 0x0003
#تعریف_کرو WM_ناپ 0x0005

#تعریف_کرو WM_ACTIVATE 0x0006

#تعریف_کرو WA_INACTIVE 0
#تعریف_کرو WA_سرگرم 1
#تعریف_کرو WA_CLICKACTIVE 2

#تعریف_کرو WM_SETFOCUS 0x0007
#تعریف_کرو WM_KILLFOCUS 0x0008
#تعریف_کرو WM_ENABLE 0x000A
#تعریف_کرو WM_SETREDRAW 0x000B
#تعریف_کرو WM_SETTEXT 0x000C
#تعریف_کرو WM_GETTEXT 0x000D
#تعریف_کرو WM_GETTEXTLENGTH 0x000E
#تعریف_کرو WM_PAINT 0x000F
#تعریف_کرو WM_CLOSE 0x0010
#جے_بنا_تعریف _WIN32_WCE
#تعریف_کرو WM_QUERYENDSESSION 0x0011
#تعریف_کرو WM_QUERYOPEN 0x0013
#تعریف_کرو WM_ENDSESSION 0x0016
#جے_انت
#تعریف_کرو WM_QUIT 0x0012
#تعریف_کرو WM_ERASEBKGND 0x0014
#تعریف_کرو WM_SYSCOLORCHANGE 0x0015
#تعریف_کرو WM_SHOWWINDOW 0x0018
#تعریف_کرو WM_WININICHANGE 0x001A
#تعریف_کرو WM_SETTINGCHANGE WM_WININICHANGE
#تعریف_کرو WM_DEVMODECHANGE 0x001B
#تعریف_کرو WM_ACTIVATEAPP 0x001C
#تعریف_کرو WM_FONTCHANGE 0x001D
#تعریف_کرو WM_TIMECHANGE 0x001E
#تعریف_کرو WM_CANCELMODE 0x001F
#تعریف_کرو WM_SETCURSOR 0x0020
#تعریف_کرو WM_MOUSEACTIVATE 0x0021
#تعریف_کرو WM_CHILDACTIVATE 0x0022
#تعریف_کرو WM_QUEUESYNC 0x0023

#تعریف_کرو WM_GETMINMAXINFO 0x0024

  تعريفنوع بنية ٹیگ_MINMAXINFO {
    نقطہ_3 ptReserved;
    نقطہ_3 pt_Max_ناپ;
    نقطہ_3 ptMaxPosition;
    نقطہ_3 pt_Min_Track_ناپ;
    نقطہ_3 pt_Max_Track_ناپ;
  } MINMAXINFO,*PMINMAXINFO,*LPMINMAXINFO;

#تعریف_کرو WM_PAINTICON 0x0026
#تعریف_کرو WM_ICONERASEBKGND 0x0027
#تعریف_کرو WM_NEXTDLGCTL 0x0028
#تعریف_کرو WM_SPOOLERSTATUS 0x002A
#تعریف_کرو WM_DRAWITEM 0x002B
#تعریف_کرو WM_MEASUREITEM 0x002C
#تعریف_کرو WM_DELETEITEM 0x002D
#تعریف_کرو WM_VKEYTOITEM 0x002E
#تعریف_کرو WM_CHARTOITEM 0x002F
#تعریف_کرو WM_SETFONT 0x0030
#تعریف_کرو WM_GETFONT 0x0031
#تعریف_کرو WM_SETHOTKEY 0x0032
#تعریف_کرو WM_GETHOTKEY 0x0033
#تعریف_کرو WM_QUERYDRAGICON 0x0037
#تعریف_کرو WM_COMPAREITEM 0x0039
#جے_بنا_تعریف _WIN32_WCE
#تعریف_کرو WM_GETOBJECT 0x003D
#جے_انت
#تعریف_کرو WM_COMPACTING 0x0041
#تعریف_کرو WM_COMMNOTIFY 0x0044
#تعریف_کرو WM_WINDOWPOSCHANGING 0x0046
#تعریف_کرو WM_WINDOWPOSCHANGED 0x0047

#تعریف_کرو WM_POWER 0x0048

#تعریف_کرو PWR_OK 1
#تعریف_کرو PWR_FAIL (-1)
#تعریف_کرو PWR_SUSPENDREQUEST 1
#تعریف_کرو PWR_SUSPENDRESUME 2
#تعریف_کرو PWR_CRITICALRESUME 3

#تعریف_کرو WM_COPYDATA 0x004A
#تعریف_کرو WM_CANCELJOURNAL 0x004B

  تعريفنوع بنية ٹیگ_COPYDATASTRUCT {
    ULONG_PTR dw_انکڑے;
    DWORD cb_انکڑے;
    PVOID lp_انکڑے;
  } COPYDATASTRUCT,*PCOPYDATASTRUCT;

  تعريفنوع بنية ٹیگ_MDINEXTMENU {
    HMENU hmenu_وچ;
    HMENU hmenu_اگلا;
    HWND hwnd_اگلا;
  } MDINEXTMENU,*PMDINEXTMENU,*LPMDINEXTMENU;

#تعریف_کرو WM_NOTIFY 0x004E
#تعریف_کرو WM_INPUTLANGCHANGEREQUEST 0x0050
#تعریف_کرو WM_INPUTLANGCHANGE 0x0051
#تعریف_کرو WM_TCARD 0x0052
#تعریف_کرو WM_HELP 0x0053
#تعریف_کرو WM_USERCHANGED 0x0054
#تعریف_کرو WM_NOTIFYFORMAT 0x0055

#تعریف_کرو NFR_ANSI 1
#تعریف_کرو NFR_UNICODE 2
#تعریف_کرو NF_QUERY 3
#تعریف_کرو NF_REQUERY 4

#تعریف_کرو WM_CONTEXTMENU 0x007B
#تعریف_کرو WM_STYLECHANGING 0x007C
#تعریف_کرو WM_STYLECHANGED 0x007D
#تعریف_کرو WM_DISPLAYCHANGE 0x007E
#تعریف_کرو WM_GETICON 0x007F
#تعریف_کرو WM_SETICON 0x0080

#تعریف_کرو WM_NCCREATE 0x0081
#تعریف_کرو WM_NCDESTROY 0x0082
#تعریف_کرو WM_NCCALCSIZE 0x0083
#تعریف_کرو WM_NCHITTEST 0x0084
#تعریف_کرو WM_NCPAINT 0x0085
#تعریف_کرو WM_NCACTIVATE 0x0086
#تعریف_کرو WM_GETDLGCODE 0x0087
#جے_بنا_تعریف _WIN32_WCE
#تعریف_کرو WM_SYNCPAINT 0x0088
#جے_انت
#تعریف_کرو WM_NCMOUSEMOVE 0x00A0
#تعریف_کرو WM_NCLBUTTONDOWN 0x00A1
#تعریف_کرو WM_NCLBUTTONUP 0x00A2
#تعریف_کرو WM_NCLBUTTONDBLCLK 0x00A3
#تعریف_کرو WM_NCRBUTTONDOWN 0x00A4
#تعریف_کرو WM_NCRBUTTONUP 0x00A5
#تعریف_کرو WM_NCRBUTTONDBLCLK 0x00A6
#تعریف_کرو WM_NCMBUTTONDOWN 0x00A7
#تعریف_کرو WM_NCMBUTTONUP 0x00A8
#تعریف_کرو WM_NCMBUTTONDBLCLK 0x00A9

#تعریف_کرو WM_NCXBUTTONDOWN 0x00AB
#تعریف_کرو WM_NCXBUTTONUP 0x00AC
#تعریف_کرو WM_NCXBUTTONDBLCLK 0x00AD
#تعریف_کرو WM_داخلہ 0x00FF
#تعریف_کرو WM_KEYFIRST 0x0100
#تعریف_کرو WM_KEYDOWN 0x0100
#تعریف_کرو WM_KEYUP 0x0101
#تعریف_کرو WM_CHAR 0x0102
#تعریف_کرو WM_DEADCHAR 0x0103
#تعریف_کرو WM_SYSKEYDOWN 0x0104
#تعریف_کرو WM_SYSKEYUP 0x0105
#تعریف_کرو WM_SYSCHAR 0x0106
#تعریف_کرو WM_SYSDEADCHAR 0x0107
#تعریف_کرو WM_UNICHAR 0x0109
#تعریف_کرو WM_KEYLAST 0x0109
#تعریف_کرو UNICODE_NOCHAR 0xFFFF
#تعریف_کرو WM_IME_STARTCOMPOSITION 0x010D
#تعریف_کرو WM_IME_ENDCOMPOSITION 0x010E
#تعریف_کرو WM_IME_COMPOSITION 0x010F
#تعریف_کرو WM_IME_KEYLAST 0x010F
#تعریف_کرو WM_INITDIALOG 0x0110
#تعریف_کرو WM_COMMAND 0x0111
#تعریف_کرو WM_SYSCOMMAND 0x0112
#تعریف_کرو WM_TIMER 0x0113
#تعریف_کرو WM_HSCROLL 0x0114
#تعریف_کرو WM_VSCROLL 0x0115
#تعریف_کرو WM_INITMENU 0x0116
#تعریف_کرو WM_INITMENUPOPUP 0x0117
#تعریف_کرو WM_MENUSELECT 0x011F
#تعریف_کرو WM_MENUCHAR 0x0120
#تعریف_کرو WM_ENTERIDLE 0x0121
#جے_بنا_تعریف _WIN32_WCE
#تعریف_کرو WM_MENURBUTTONUP 0x0122
#تعریف_کرو WM_MENUDRAG 0x0123
#تعریف_کرو WM_MENUGETOBJECT 0x0124
#تعریف_کرو WM_UNINITMENUPOPUP 0x0125
#تعریف_کرو WM_MENUCOMMAND 0x0126

#جے_بنا_تعریف _WIN32_WCE
#تعریف_کرو WM_CHANGEUISTATE 0x0127
#تعریف_کرو WM_UPDATEUISTATE 0x0128
#تعریف_کرو WM_QUERYUISTATE 0x0129

#تعریف_کرو UIS_سیٹ 1
#تعریف_کرو UIS_CLEAR 2
#تعریف_کرو UIS_INITIALIZE 3

#تعریف_کرو UISF_HIDEFOCUS 0x1
#تعریف_کرو UISF_HIDEACCEL 0x2
#تعریف_کرو UISF_سرگرم 0x4
#جے_انت
#جے_انت

#تعریف_کرو WM_CTLCOLORMSGBOX 0x0132
#تعریف_کرو WM_CTLCOLOREDIT 0x0133
#تعریف_کرو WM_CTLCOLORLISTBOX 0x0134
#تعریف_کرو WM_CTLCOLORBTN 0x0135
#تعریف_کرو WM_CTLCOLORDLG 0x0136
#تعریف_کرو WM_CTLCOLORSCROLLBAR 0x0137
#تعریف_کرو WM_CTLCOLORSTATIC 0x0138
#تعریف_کرو MN_GETHMENU 0x01E1

#تعریف_کرو WM_MOUSEFIRST 0x0200
#تعریف_کرو WM_MOUSEMOVE 0x0200
#تعریف_کرو WM_LBUTTONDOWN 0x0201
#تعریف_کرو WM_LBUTTONUP 0x0202
#تعریف_کرو WM_LBUTTONDBLCLK 0x0203
#تعریف_کرو WM_RBUTTONDOWN 0x0204
#تعریف_کرو WM_RBUTTONUP 0x0205
#تعریف_کرو WM_RBUTTONDBLCLK 0x0206
#تعریف_کرو WM_MBUTTONDOWN 0x0207
#تعریف_کرو WM_MBUTTONUP 0x0208
#تعریف_کرو WM_MBUTTONDBLCLK 0x0209
#تعریف_کرو WM_MOUSEWHEEL 0x020A
#تعریف_کرو WM_XBUTTONDOWN 0x020B
#تعریف_کرو WM_XBUTTONUP 0x020C
#تعریف_کرو WM_XBUTTONDBLCLK 0x020D
#تعریف_کرو WM_MOUSEHWHEEL 0x020E
#تعریف_کرو WM_MOUSELAST 0x020E

#تعریف_کرو WHEEL_DELTA 120
#تعریف_کرو GET_WHEEL_DELTA_WPARAM(wParam) ((چھوٹا)HIWORD(wParam))

#تعریف_کرو WHEEL_PAGESCROLL (UINT_MAX)

#تعریف_کرو GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#تعریف_کرو GET_NCHITTEST_WPARAM(wParam) ((چھوٹا)LOWORD(wParam))
#تعریف_کرو GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#تعریف_کرو XBUTTON1 0x0001
#تعریف_کرو XBUTTON2 0x0002

#تعریف_کرو WM_PARENTNOTIFY 0x0210
#تعریف_کرو WM_ENTERMENULOOP 0x0211
#تعریف_کرو WM_EXITMENULOOP 0x0212

#تعریف_کرو WM_NEXTMENU 0x0213
#تعریف_کرو WM_SIZING 0x0214
#تعریف_کرو WM_CAPTURECHANGED 0x0215
#تعریف_کرو WM_MOVING 0x0216

#تعریف_کرو WM_POWERBROADCAST 0x0218

#جے_بنا_تعریف _WIN32_WCE
#تعریف_کرو PBT_APMQUERYSUSPEND 0x0000
#تعریف_کرو PBT_APMQUERYSTANDBY 0x0001

#تعریف_کرو PBT_APMQUERYSUSPENDFAILED 0x0002
#تعریف_کرو PBT_APMQUERYSTANDBYFAILED 0x0003

#تعریف_کرو PBT_APMSUSPEND 0x0004
#تعریف_کرو PBT_APMSTANDBY 0x0005

#تعریف_کرو PBT_APMRESUMECRITICAL 0x0006
#تعریف_کرو PBT_APMRESUMESUSPEND 0x0007
#تعریف_کرو PBT_APMRESUMESTANDBY 0x0008

#تعریف_کرو PBTF_APMRESUMEFROMFAILURE 0x00000001

#تعریف_کرو PBT_APMBATTERYLOW 0x0009
#تعریف_کرو PBT_APMPOWERSTATUSCHANGE 0x000A

#تعریف_کرو PBT_APMOEMEVENT 0x000B
#تعریف_کرو PBT_APMRESUMEAUTOMATIC 0x0012
#جے_انت

#تعریف_کرو WM_DEVICECHANGE 0x0219

#تعریف_کرو WM_MDICREATE 0x0220
#تعریف_کرو WM_MDIDESTROY 0x0221
#تعریف_کرو WM_MDIACTIVATE 0x0222
#تعریف_کرو WM_MDIRESTORE 0x0223
#تعریف_کرو WM_MDINEXT 0x0224
#تعریف_کرو WM_MDIMAXIMIZE 0x0225
#تعریف_کرو WM_MDITILE 0x0226
#تعریف_کرو WM_MDICASCADE 0x0227
#تعریف_کرو WM_MDIICONARRANGE 0x0228
#تعریف_کرو WM_MDIGETACTIVE 0x0229

#تعریف_کرو WM_MDISETMENU 0x0230
#تعریف_کرو WM_ENTERSIZEMOVE 0x0231
#تعریف_کرو WM_EXITSIZEMOVE 0x0232
#تعریف_کرو WM_DROPFILES 0x0233
#تعریف_کرو WM_MDIREFRESHMENU 0x0234

#تعریف_کرو WM_IME_SETCONTEXT 0x0281
#تعریف_کرو WM_IME_NOTIFY 0x0282
#تعریف_کرو WM_IME_CONTROL 0x0283
#تعریف_کرو WM_IME_COMPOSITIONFULL 0x0284
#تعریف_کرو WM_IME_SELECT 0x0285
#تعریف_کرو WM_IME_CHAR 0x0286
#تعریف_کرو WM_IME_REQUEST 0x0288
#تعریف_کرو WM_IME_KEYDOWN 0x0290
#تعریف_کرو WM_IME_KEYUP 0x0291

#تعریف_کرو WM_MOUSEHOVER 0x02A1
#تعریف_کرو WM_MOUSELEAVE 0x02A3
#تعریف_کرو WM_NCMOUSEHOVER 0x02A0
#تعریف_کرو WM_NCMOUSELEAVE 0x02A2
#تعریف_کرو WM_WTSSESSION_CHANGE 0x02B1
#تعریف_کرو WM_TABLET_پہلا 0x02c0
#تعریف_کرو WM_TABLET_آخری 0x02df
#تعریف_کرو WM_CUT 0x0300
#تعریف_کرو WM_COPY 0x0301
#تعریف_کرو WM_PASTE 0x0302
#تعریف_کرو WM_CLEAR 0x0303
#تعریف_کرو WM_UNDO 0x0304
#تعریف_کرو WM_RENDERFORMAT 0x0305
#تعریف_کرو WM_RENDERALLFORMATS 0x0306
#تعریف_کرو WM_DESTROYCLIPBOARD 0x0307
#تعریف_کرو WM_DRAWCLIPBOARD 0x0308
#تعریف_کرو WM_PAINTCLIPBOARD 0x0309
#تعریف_کرو WM_VSCROLLCLIPBOARD 0x030A
#تعریف_کرو WM_SIZECLIPBOARD 0x030B
#تعریف_کرو WM_ASKCBFORMATNAME 0x030C
#تعریف_کرو WM_CHANGECBCHAIN 0x030D
#تعریف_کرو WM_HSCROLLCLIPBOARD 0x030E
#تعریف_کرو WM_QUERYNEWPALETTE 0x030F
#تعریف_کرو WM_PALETTEISCHANGING 0x0310
#تعریف_کرو WM_PALETTECHANGED 0x0311
#تعریف_کرو WM_HOTKEY 0x0312
#تعریف_کرو WM_PRINT 0x0317
#تعریف_کرو WM_PRINTCLIENT 0x0318
#تعریف_کرو WM_APPCOMMAND 0x0319
#تعریف_کرو WM_THEMECHANGED 0x031A
#تعریف_کرو WM_HANDHELDFIRST 0x0358
#تعریف_کرو WM_HANDHELDLAST 0x035F
#تعریف_کرو WM_AFXFIRST 0x0360
#تعریف_کرو WM_AFXLAST 0x037F
#تعریف_کرو WM_PENWINFIRST 0x0380
#تعریف_کرو WM_PENWINLAST 0x038F
#تعریف_کرو WM_APP 0x8000
#تعریف_کرو WM_USER 0x0400

#تعریف_کرو WMSZ_بایاں 1
#تعریف_کرو WMSZ_دایاں 2
#تعریف_کرو WMSZ_چوٹی 3
#تعریف_کرو WMSZ_TOPLEFT 4
#تعریف_کرو WMSZ_TOPRIGHT 5
#تعریف_کرو WMSZ_BOTTOM 6
#تعریف_کرو WMSZ_BOTTOMLEFT 7
#تعریف_کرو WMSZ_BOTTOMRIGHT 8

#جے_بنا_تعریف NONCMESSAGES

#تعریف_کرو HTERROR (-2)
#تعریف_کرو HTTRANSPARENT (-1)
#تعریف_کرو HTNOWHERE 0
#تعریف_کرو HTCLIENT 1
#تعریف_کرو HTCAPTION 2
#تعریف_کرو HTSYSMENU 3
#تعریف_کرو HTGROWBOX 4
#تعریف_کرو HTSIZE HTGROWBOX
#تعریف_کرو HTMENU 5
#تعریف_کرو HTHSCROLL 6
#تعریف_کرو HTVSCROLL 7
#تعریف_کرو HTMINBUTTON 8
#تعریف_کرو HTMAXBUTTON 9
#تعریف_کرو HTLEFT 10
#تعریف_کرو HTRIGHT 11
#تعریف_کرو HTTOP 12
#تعریف_کرو HTTOPLEFT 13
#تعریف_کرو HTTOPRIGHT 14
#تعریف_کرو HTBOTTOM 15
#تعریف_کرو HTBOTTOMLEFT 16
#تعریف_کرو HTBOTTOMRIGHT 17
#تعریف_کرو HTBORDER 18
#تعریف_کرو HTREDUCE HTMINBUTTON
#تعریف_کرو HTZOOM HTMAXBUTTON
#تعریف_کرو HTSIZEFIRST HTLEFT
#تعریف_کرو HTSIZELAST HTBOTTOMRIGHT
#تعریف_کرو HTOBJECT 19
#تعریف_کرو HTCLOSE 20
#تعریف_کرو HTHELP 21

#تعریف_کرو SMTO_عام 0x0000
#تعریف_کرو SMTO_بلاک 0x0001
#تعریف_کرو SMTO_ABORTIFHUNG 0x0002
#تعریف_کرو SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#جے_انت

#تعریف_کرو MA_ACTIVATE 1
#تعریف_کرو MA_ACTIVATEANDEAT 2
#تعریف_کرو MA_NOACTIVATE 3
#تعریف_کرو MA_NOACTIVATEANDEAT 4

#تعریف_کرو ICON_SMALL 0
#تعریف_کرو ICON_BIG 1
#تعریف_کرو ICON_SMALL2 2

#جے_تعریف_شدہ UNICODE
#تعریف_کرو رجسٹر_کھڑکی_سنیہا رجسٹر_کھڑکی_سنیہا_W
#وإلا
#تعریف_کرو رجسٹر_کھڑکی_سنیہا رجسٹر_کھڑکی_سنیہا_A
#جے_انت

  WINUSERAPI UINT WINAPI رجسٹر_کھڑکی_سنیہا_A(LPCSTR lpString);
  WINUSERAPI UINT WINAPI رجسٹر_کھڑکی_سنیہا_W(LPCWSTR lpString);

#تعریف_کرو ناپ_RESTORED 0
#تعریف_کرو ناپ_MINIMIZED 1
#تعریف_کرو ناپ_MAXIMIZED 2
#تعریف_کرو ناپ_MAXSHOW 3
#تعریف_کرو ناپ_MAXHIDE 4

#تعریف_کرو SIZENORMAL ناپ_RESTORED
#تعریف_کرو SIZEICONIC ناپ_MINIMIZED
#تعریف_کرو SIZEFULLSCREEN ناپ_MAXIMIZED
#تعریف_کرو SIZEZOOMSHOW ناپ_MAXSHOW
#تعریف_کرو SIZEZOOMHIDE ناپ_MAXHIDE

  تعريفنوع بنية ٹیگ_WINDOWPOS {
    HWND hwnd;
    HWND hwnd_داخل_کرو_After;
    صحيح x;
    صحيح y;
    صحيح cx;
    صحيح cy;
    UINT flags;
  } WINDOWPOS,*LPWINDOWPOS,*PWINDOWPOS;

  تعريفنوع بنية ٹیگ_NCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
  } NCCALCSIZE_PARAMS,*LPNCCALCSIZE_PARAMS;

#تعریف_کرو WVR_ALIGNTOP 0x0010
#تعریف_کرو WVR_ALIGNLEFT 0x0020
#تعریف_کرو WVR_ALIGNBOTTOM 0x0040
#تعریف_کرو WVR_ALIGNRIGHT 0x0080
#تعریف_کرو WVR_HREDRAW 0x0100
#تعریف_کرو WVR_VREDRAW 0x0200
#تعریف_کرو WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#تعریف_کرو WVR_VALIDRECTS 0x0400

#جے_بنا_تعریف NOKEYSTATES

#تعریف_کرو MK_LBUTTON 0x0001
#تعریف_کرو MK_RBUTTON 0x0002
#تعریف_کرو MK_کھسکاؤ 0x0004
#تعریف_کرو MK_CONTROL 0x0008
#تعریف_کرو MK_MBUTTON 0x0010
#تعریف_کرو MK_XBUTTON1 0x0020
#تعریف_کرو MK_XBUTTON2 0x0040
#جے_انت

#جے_بنا_تعریف NOTRACKMOUSEEVENT
#تعریف_کرو TME_HOVER 0x00000001
#تعریف_کرو TME_LEAVE 0x00000002
#تعریف_کرو TME_NONCLIENT 0x00000010
#تعریف_کرو TME_QUERY 0x40000000
#تعریف_کرو TME_CANCEL 0x80000000

#تعریف_کرو HOVER_DEFAULT 0xFFFFFFFF
#جے_انت

  تعريفنوع بنية ٹیگ_TRACKMOUSEEVENT {
    DWORD cb_ناپ;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dw_Hover_ویلا;
  } TRACKMOUSEEVENT,*LPTRACKMOUSEEVENT;

  WINUSERAPI WINBOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#جے_انت

#جے_بنا_تعریف NOWINSTYLES

#تعریف_کرو WS_OVERLAPPED 0x00000000L
#تعریف_کرو WS_POPUP 0x80000000L
#تعریف_کرو WS_بچہ 0x40000000L
#تعریف_کرو WS_MINIMIZE 0x20000000L
#تعریف_کرو WS_VISIBLE 0x10000000L
#تعریف_کرو WS_DISABLED 0x08000000L
#تعریف_کرو WS_CLIPSIBLINGS 0x04000000L
#تعریف_کرو WS_CLIPCHILDREN 0x02000000L
#تعریف_کرو WS_MAXIMIZE 0x01000000L
#تعریف_کرو WS_CAPTION 0x00C00000L
#تعریف_کرو WS_BORDER 0x00800000L
#تعریف_کرو WS_DLGFRAME 0x00400000L
#تعریف_کرو WS_VSCROLL 0x00200000L
#تعریف_کرو WS_HSCROLL 0x00100000L
#تعریف_کرو WS_SYSMENU 0x00080000L
#تعریف_کرو WS_THICKFRAME 0x00040000L
#تعریف_کرو WS_گروہ 0x00020000L
#تعریف_کرو WS_TABSTOP 0x00010000L
#تعریف_کرو WS_MINIMIZEBOX 0x00020000L
#تعریف_کرو WS_MAXIMIZEBOX 0x00010000L
#تعریف_کرو WS_TILED WS_OVERLAPPED
#تعریف_کرو WS_ICONIC WS_MINIMIZE
#تعریف_کرو WS_SIZEBOX WS_THICKFRAME
#تعریف_کرو WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#تعریف_کرو WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#تعریف_کرو WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#تعریف_کرو WS_CHILDWINDOW (WS_بچہ)

#تعریف_کرو WS_EX_DLGMODALFRAME 0x00000001L
#تعریف_کرو WS_EX_NOPARENTNOTIFY 0x00000004L
#تعریف_کرو WS_EX_TOPMOST 0x00000008L
#تعریف_کرو WS_EX_ACCEPTFILES 0x00000010L
#تعریف_کرو WS_EX_TRANSPARENT 0x00000020L
#تعریف_کرو WS_EX_MDICHILD 0x00000040L
#تعریف_کرو WS_EX_TOOLWINDOW 0x00000080L
#تعریف_کرو WS_EX_WINDOWEDGE 0x00000100L
#تعریف_کرو WS_EX_CLIENTEDGE 0x00000200L
#تعریف_کرو WS_EX_CONTEXTHELP 0x00000400L
#تعریف_کرو WS_EX_دایاں 0x00001000L
#تعریف_کرو WS_EX_بایاں 0x00000000L
#تعریف_کرو WS_EX_RTLREADING 0x00002000L
#تعریف_کرو WS_EX_LTRREADING 0x00000000L
#تعریف_کرو WS_EX_LEFTSCROLLBAR 0x00004000L
#تعریف_کرو WS_EX_RIGHTSCROLLBAR 0x00000000L
#تعریف_کرو WS_EX_CONTROLPARENT 0x00010000L
#تعریف_کرو WS_EX_STATICEDGE 0x00020000L
#تعریف_کرو WS_EX_APPWINDOW 0x00040000L
#تعریف_کرو WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#تعریف_کرو WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#تعریف_کرو WS_EX_LAYERED 0x00080000
#تعریف_کرو WS_EX_NOINHERITLAYOUT 0x00100000L
#تعریف_کرو WS_EX_LAYOUTRTL 0x00400000L
#تعریف_کرو WS_EX_COMPOSITED 0x02000000L
#تعریف_کرو WS_EX_NOACTIVATE 0x08000000L

#تعریف_کرو CS_VREDRAW 0x0001
#تعریف_کرو CS_HREDRAW 0x0002
#تعریف_کرو CS_DBLCLKS 0x0008
#تعریف_کرو CS_OWNDC 0x0020
#تعریف_کرو CS_CLASSDC 0x0040
#تعریف_کرو CS_PARENTDC 0x0080
#تعریف_کرو CS_NOCLOSE 0x0200
#تعریف_کرو CS_SAVEBITS 0x0800
#تعریف_کرو CS_BYTEALIGNCLIENT 0x1000
#تعریف_کرو CS_BYTEALIGNWINDOW 0x2000
#تعریف_کرو CS_GLOBALCLASS 0x4000
#تعریف_کرو CS_IME 0x00010000
#تعریف_کرو CS_DROPSHADOW 0x00020000
#جے_انت

#تعریف_کرو PRF_CHECKVISIBLE 0x00000001L
#تعریف_کرو PRF_NONCLIENT 0x00000002L
#تعریف_کرو PRF_CLIENT 0x00000004L
#تعریف_کرو PRF_ERASEBKGND 0x00000008L
#تعریف_کرو PRF_CHILDREN 0x00000010L
#تعریف_کرو PRF_OWNED 0x00000020L

#تعریف_کرو BDR_RAISEDOUTER 0x0001
#تعریف_کرو BDR_SUNKENOUTER 0x0002
#تعریف_کرو BDR_RAISEDINNER 0x0004
#تعریف_کرو BDR_SUNKENINNER 0x0008

#تعریف_کرو BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#تعریف_کرو BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#تعریف_کرو BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#تعریف_کرو BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#تعریف_کرو کنارا_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#تعریف_کرو کنارا_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#تعریف_کرو کنارا_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#تعریف_کرو کنارا_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#تعریف_کرو BF_بایاں 0x0001
#تعریف_کرو BF_چوٹی 0x0002
#تعریف_کرو BF_دایاں 0x0004
#تعریف_کرو BF_BOTTOM 0x0008

#تعریف_کرو BF_TOPLEFT (BF_چوٹی | BF_بایاں)
#تعریف_کرو BF_TOPRIGHT (BF_چوٹی | BF_دایاں)
#تعریف_کرو BF_BOTTOMLEFT (BF_BOTTOM | BF_بایاں)
#تعریف_کرو BF_BOTTOMRIGHT (BF_BOTTOM | BF_دایاں)
#تعریف_کرو BF_RECT (BF_بایاں | BF_چوٹی | BF_دایاں | BF_BOTTOM)

#تعریف_کرو BF_DIAGONAL 0x0010

#تعریف_کرو BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_چوٹی | BF_دایاں)
#تعریف_کرو BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_چوٹی | BF_بایاں)
#تعریف_کرو BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_بایاں)
#تعریف_کرو BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_دایاں)

#تعریف_کرو BF_درمیان 0x0800
#تعریف_کرو BF_SOFT 0x1000
#تعریف_کرو BF_ADJUST 0x2000
#تعریف_کرو BF_FLAT 0x4000
#تعریف_کرو BF_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_کنارا(HDC hdc,LPRECT qrc,UINT کنارا,UINT grfFlags);

#تعریف_کرو DFC_CAPTION 1
#تعریف_کرو DFC_MENU 2
#تعریف_کرو DFC_SCROLL 3
#تعریف_کرو DFC_BUTTON 4
#تعریف_کرو DFC_POPUPMENU 5

#تعریف_کرو DFCS_CAPTIONCLOSE 0x0000
#تعریف_کرو DFCS_CAPTIONMIN 0x0001
#تعریف_کرو DFCS_CAPTIONMAX 0x0002
#تعریف_کرو DFCS_CAPTIONRESTORE 0x0003
#تعریف_کرو DFCS_CAPTIONHELP 0x0004

#تعریف_کرو DFCS_MENUARROW 0x0000
#تعریف_کرو DFCS_MENUCHECK 0x0001
#تعریف_کرو DFCS_MENUBULLET 0x0002
#تعریف_کرو DFCS_MENUARROWRIGHT 0x0004
#تعریف_کرو DFCS_SCROLLUP 0x0000
#تعریف_کرو DFCS_SCROLLDOWN 0x0001
#تعریف_کرو DFCS_SCROLLLEFT 0x0002
#تعریف_کرو DFCS_SCROLLRIGHT 0x0003
#تعریف_کرو DFCS_SCROLLCOMBOBOX 0x0005
#تعریف_کرو DFCS_SCROLLSIZEGRIP 0x0008
#تعریف_کرو DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#تعریف_کرو DFCS_BUTTONCHECK 0x0000
#تعریف_کرو DFCS_BUTTONRADIOIMAGE 0x0001
#تعریف_کرو DFCS_BUTTONRADIOMASK 0x0002
#تعریف_کرو DFCS_BUTTONRADIO 0x0004
#تعریف_کرو DFCS_BUTTON3STATE 0x0008
#تعریف_کرو DFCS_BUTTONPUSH 0x0010

#تعریف_کرو DFCS_INACTIVE 0x0100
#تعریف_کرو DFCS_PUSHED 0x0200
#تعریف_کرو DFCS_CHECKED 0x0400

#تعریف_کرو DFCS_TRANSPARENT 0x0800
#تعریف_کرو DFCS_HOT 0x1000

#تعریف_کرو DFCS_ADJUSTRECT 0x2000
#تعریف_کرو DFCS_FLAT 0x4000
#تعریف_کرو DFCS_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_چوکھٹا_Control(HDC,LPRECT,UINT,UINT);

#تعریف_کرو DC_سرگرم 0x0001
#تعریف_کرو DC_SMALLCAP 0x0002
#تعریف_کرو DC_ICON 0x0004
#تعریف_کرو DC_متن 0x0008
#تعریف_کرو DC_INBUTTON 0x0010
#تعریف_کرو DC_GRADIENT 0x0020
#تعریف_کرو DC_BUTTONS 0x1000

  WINUSERAPI WINBOOL WINAPI DrawCaption(HWND hwnd,HDC hdc,CONST RECT *lprect,UINT flags);

#تعریف_کرو IDANI_OPEN 1
#تعریف_کرو IDANI_CAPTION 3

  WINUSERAPI WINBOOL WINAPI DrawAnimatedRects(HWND hwnd,صحيح idAni,CONST RECT *lprcFrom,CONST RECT *lprc_منزل);

#جے_بنا_تعریف NOCLIPBOARD

#تعریف_کرو CF_متن 1
#تعریف_کرو CF_BITMAP 2
#تعریف_کرو CF_METAFILEPICT 3
#تعریف_کرو CF_SYLK 4
#تعریف_کرو CF_DIF 5
#تعریف_کرو CF_TIFF 6
#تعریف_کرو CF_OEMTEXT 7
#تعریف_کرو CF_DIB 8
#تعریف_کرو CF_PALETTE 9
#تعریف_کرو CF_PENDATA 10
#تعریف_کرو CF_RIFF 11
#تعریف_کرو CF_WAVE 12
#تعریف_کرو CF_UNICODETEXT 13
#تعریف_کرو CF_ENHMETAFILE 14
#تعریف_کرو CF_HDROP 15
#تعریف_کرو CF_LOCALE 16
#تعریف_کرو CF_DIBV5 17
#تعریف_کرو CF_MAX 18

#تعریف_کرو CF_OWNERDISPLAY 0x0080
#تعریف_کرو CF_DSPTEXT 0x0081
#تعریف_کرو CF_DSPBITMAP 0x0082
#تعریف_کرو CF_DSPMETAFILEPICT 0x0083
#تعریف_کرو CF_DSPENHMETAFILE 0x008E

#تعریف_کرو CF_PRIVATEFIRST 0x0200
#تعریف_کرو CF_PRIVATELAST 0x02FF

#تعریف_کرو CF_GDIOBJFIRST 0x0300
#تعریف_کرو CF_GDIOBJLAST 0x03FF
#جے_انت

#تعریف_کرو FVIRTKEY TRUE
#تعریف_کرو FNOINVERT 0x02
#تعریف_کرو FSHIFT 0x04
#تعریف_کرو FCONTROL 0x08
#تعریف_کرو FALT 0x10

  تعريفنوع بنية ٹیگ_ACCEL {
    BYTE fVirt;
    لفظ_3 کلید;
    لفظ_3 cmd;
  } ACCEL,*LPACCEL;

  تعريفنوع بنية ٹیگ_PAINTSTRUCT {
    HDC hdc;
    WINBOOL fErase;
    RECT rcPaint;
    WINBOOL fRestore;
    WINBOOL fIncUpdate;
    BYTE rgbReserved[32];
  } PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;

  تعريفنوع بنية ٹیگ_CREATESTRUCTA {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_ماپا_2;
    صحيح cy;
    صحيح cx;
    صحيح y;
    صحيح x;
    LONG style;
    LPCSTR lpszName;
    LPCSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTA,*LPCREATESTRUCTA;

  تعريفنوع بنية ٹیگ_CREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_ماپا_2;
    صحيح cy;
    صحيح cx;
    صحيح y;
    صحيح x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTW,*LPCREATESTRUCTW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع CREATESTRUCTW CREATESTRUCT;
  تعريفنوع LPCREATESTRUCTW LPCREATESTRUCT;
#وإلا
  تعريفنوع CREATESTRUCTA CREATESTRUCT;
  تعريفنوع LPCREATESTRUCTA LPCREATESTRUCT;
#جے_انت

  تعريفنوع بنية ٹیگ_WINDOWPLACEMENT {
    UINT لمائی;
    UINT flags;
    UINT showCmd;
    نقطہ_3 ptMinPosition;
    نقطہ_3 ptMaxPosition;
    RECT rc_عام_Position;
  } WINDOWPLACEMENT;
  تعريفنوع WINDOWPLACEMENT *PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;

#تعریف_کرو WPF_SETMINPOSITION 0x0001
#تعریف_کرو WPF_RESTORETOMAXIMIZED 0x0002
#تعریف_کرو WPF_ASYNCWINDOWPLACEMENT 0x0004

  تعريفنوع بنية ٹیگ_NMHDR {
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT کوڈ;
  } NMHDR;

  تعريفنوع NMHDR *LPNMHDR;

  تعريفنوع بنية ٹیگ_STYLESTRUCT {
    DWORD styleOld;
    DWORD styleNew;
  } STYLESTRUCT,*LPSTYLESTRUCT;

#تعریف_کرو ODT_MENU 1
#تعریف_کرو ODT_LISTBOX 2
#تعریف_کرو ODT_COMBOBOX 3
#تعریف_کرو ODT_BUTTON 4
#تعریف_کرو ODT_STATIC 5

#تعریف_کرو ODA_DRAWENTIRE 0x0001
#تعریف_کرو ODA_SELECT 0x0002
#تعریف_کرو ODA_FOCUS 0x0004

#تعریف_کرو ODS_SELECTED 0x0001
#تعریف_کرو ODS_GRAYED 0x0002
#تعریف_کرو ODS_DISABLED 0x0004
#تعریف_کرو ODS_CHECKED 0x0008
#تعریف_کرو ODS_FOCUS 0x0010
#تعریف_کرو ODS_DEFAULT 0x0020
#تعریف_کرو ODS_COMBOBOXEDIT 0x1000
#تعریف_کرو ODS_HOTLIGHT 0x0040
#تعریف_کرو ODS_INACTIVE 0x0080
#تعریف_کرو ODS_NOACCEL 0x0100
#تعریف_کرو ODS_NOFOCUSRECT 0x0200

  تعريفنوع بنية ٹیگ_MEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT شے_ID;
    UINT شے_چوڑائی;
    UINT شے_اچائی;
    ULONG_PTR شے_انکڑے;
  } MEASUREITEMSTRUCT,*PMEASUREITEMSTRUCT,*LPMEASUREITEMSTRUCT;

  تعريفنوع بنية ٹیگ_DRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT شے_ID;
    UINT شے_Action;
    UINT شے_State;
    HWND hwnd_شے;
    HDC hDC;
    RECT rc_شے;
    ULONG_PTR شے_انکڑے;
  } DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;

  تعريفنوع بنية ٹیگ_DELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT شے_ID;
    HWND hwnd_شے;
    ULONG_PTR شے_انکڑے;
  } DELETEITEMSTRUCT,*PDELETEITEMSTRUCT,*LPDELETEITEMSTRUCT;

  تعريفنوع بنية ٹیگ_COMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwnd_شے;
    UINT شے_ID1;
    ULONG_PTR شے_Data1;
    UINT شے_ID2;
    ULONG_PTR شے_Data2;
    DWORD dwLocaleId;
  } COMPAREITEMSTRUCT,*PCOMPAREITEMSTRUCT,*LPCOMPAREITEMSTRUCT;

#جے_بنا_تعریف NOMSG
#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_سنیہا Get_سنیہا_W
#تعریف_کرو Dispatch_سنیہا Dispatch_سنیہا_W
#تعریف_کرو Peek_سنیہا Peek_سنیہا_W
#وإلا
#تعریف_کرو Get_سنیہا Get_سنیہا_A
#تعریف_کرو Dispatch_سنیہا Dispatch_سنیہا_A
#تعریف_کرو Peek_سنیہا Peek_سنیہا_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI Get_سنیہا_A(LPMSG lp_پیغام,HWND hWnd,UINT w_پیغام_Filter_Min,UINT w_پیغام_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Get_سنیہا_W(LPMSG lp_پیغام,HWND hWnd,UINT w_پیغام_Filter_Min,UINT w_پیغام_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Translate_سنیہا(CONST پیغام_2 *lp_پیغام);
  WINUSERAPI LRESULT WINAPI Dispatch_سنیہا_A(CONST پیغام_2 *lp_پیغام);
  WINUSERAPI LRESULT WINAPI Dispatch_سنیہا_W(CONST پیغام_2 *lp_پیغام);
  WINUSERAPI WINBOOL WINAPI سیٹ_سنیہا_قطار(صحيح cMessagesMax);
  WINUSERAPI WINBOOL WINAPI Peek_سنیہا_A(LPMSG lp_پیغام,HWND hWnd,UINT w_پیغام_Filter_Min,UINT w_پیغام_Filter_Max,UINT w_Remove_پیغام);
  WINUSERAPI WINBOOL WINAPI Peek_سنیہا_W(LPMSG lp_پیغام,HWND hWnd,UINT w_پیغام_Filter_Min,UINT w_پیغام_Filter_Max,UINT w_Remove_پیغام);

#تعریف_کرو PM_NOREMOVE 0x0000
#تعریف_کرو PM_REMOVE 0x0001
#تعریف_کرو PM_NOYIELD 0x0002
#تعریف_کرو PM_QS_داخلہ (QS_داخلہ << 16)
#تعریف_کرو PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#تعریف_کرو PM_QS_PAINT (QS_PAINT << 16)
#تعریف_کرو PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)
#جے_انت

  WINUSERAPI WINBOOL WINAPI رجسٹر_Hot_کلید(HWND hWnd,صحيح id,UINT fsModifiers,UINT vk);
  WINUSERAPI WINBOOL WINAPI Unregister_Hot_کلید(HWND hWnd,صحيح id);

#تعریف_کرو MOD_ALT 0x0001
#تعریف_کرو MOD_CONTROL 0x0002
#تعریف_کرو MOD_کھسکاؤ 0x0004
#تعریف_کرو MOD_WIN 0x0008

#تعریف_کرو IDHOT_SNAPWINDOW (-1)
#تعریف_کرو IDHOT_SNAPDESKTOP (-2)

#جے_تعریف_شدہ WIN_اندرونی
#جے_بنا_تعریف LSTRING
#تعریف_کرو NOLSTRING
#جے_انت
#جے_بنا_تعریف LFILEIO
#تعریف_کرو NOLFILEIO
#جے_انت
#جے_انت

#تعریف_کرو ENDSESSION_LOGOFF 0x80000000

#تعریف_کرو EWX_LOGOFF 0
#تعریف_کرو EWX_SHUTDOWN 0x00000001
#تعریف_کرو EWX_REBOOT 0x00000002
#تعریف_کرو EWX_FORCE 0x00000004
#تعریف_کرو EWX_POWEROFF 0x00000008
#تعریف_کرو EWX_FORCEIFHUNG 0x00000010

#تعریف_کرو ExitWindows(dwReserved,کوڈ_4) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Send_سنیہا Send_سنیہا_W
#تعریف_کرو Send_سنیہا_Timeout Send_سنیہا_Timeout_W
#تعریف_کرو Send_Notify_سنیہا Send_Notify_سنیہا_W
#تعریف_کرو Send_سنیہا_Callback Send_سنیہا_Callback_W
#وإلا
#تعریف_کرو Send_سنیہا Send_سنیہا_A
#تعریف_کرو Send_سنیہا_Timeout Send_سنیہا_Timeout_A
#تعریف_کرو Send_Notify_سنیہا Send_Notify_سنیہا_A
#تعریف_کرو Send_سنیہا_Callback Send_سنیہا_Callback_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI ExitWindowsEx(UINT uFlags,DWORD dwReason);
  WINUSERAPI WINBOOL WINAPI وٹاندرا_Mouse_Button(WINBOOL f_وٹاندرا);
  WINUSERAPI DWORD WINAPI Get_سنیہا_Pos(VOID);
  WINUSERAPI LONG WINAPI Get_سنیہا_ویلا(VOID);
  WINUSERAPI LPARAM WINAPI Get_سنیہا_Extra_Info(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Wow64_سنیہا(VOID);
  WINUSERAPI LPARAM WINAPI سیٹ_سنیہا_Extra_Info(LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_سنیہا_A(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_سنیہا_W(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_سنیہا_Timeout_A(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_نتیجہ);
  WINUSERAPI LRESULT WINAPI Send_سنیہا_Timeout_W(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_نتیجہ);
  WINUSERAPI WINBOOL WINAPI Send_Notify_سنیہا_A(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_Notify_سنیہا_W(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_سنیہا_Callback_A(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_نتیجہ_Call_پٹھ,ULONG_PTR dw_انکڑے);
  WINUSERAPI WINBOOL WINAPI Send_سنیہا_Callback_W(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_نتیجہ_Call_پٹھ,ULONG_PTR dw_انکڑے);

  تعريفنوع بنية {
    UINT cb_ناپ;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
  } BSMINFO,*PBSMINFO;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو نشر_System_سنیہا_Ex نشر_System_سنیہا_Ex_W
#تعریف_کرو نشر_System_سنیہا نشر_System_سنیہا_W
#وإلا
#تعریف_کرو نشر_System_سنیہا_Ex نشر_System_سنیہا_Ex_A
#تعریف_کرو نشر_System_سنیہا نشر_System_سنیہا_A
#جے_انت

  WINUSERAPI لما WINAPI نشر_System_سنیہا_Ex_A(DWORD flags,LPDWORD lpInfo,UINT پیغام_3,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI لما WINAPI نشر_System_سنیہا_Ex_W(DWORD flags,LPDWORD lpInfo,UINT پیغام_3,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI لما WINAPI نشر_System_سنیہا_A(DWORD flags,LPDWORD lpInfo,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI لما WINAPI نشر_System_سنیہا_W(DWORD flags,LPDWORD lpInfo,UINT پیغام_3,WPARAM wParam,LPARAM lParam);

#تعریف_کرو BSM_ALLCOMPONENTS 0x00000000
#تعریف_کرو BSM_VXDS 0x00000001
#تعریف_کرو BSM_NETDRIVER 0x00000002
#تعریف_کرو BSM_INSTALLABLEDRIVERS 0x00000004
#تعریف_کرو BSM_APPLICATIONS 0x00000008
#تعریف_کرو BSM_ALLDESKTOPS 0x00000010

#تعریف_کرو BSF_QUERY 0x00000001
#تعریف_کرو BSF_IGNORECURRENTTASK 0x00000002
#تعریف_کرو BSF_FLUSHDISK 0x00000004
#تعریف_کرو BSF_NOHANG 0x00000008
#تعریف_کرو BSF_POSTMESSAGE 0x00000010
#تعریف_کرو BSF_FORCEIFHUNG 0x00000020
#تعریف_کرو BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#تعریف_کرو BSF_ALLOWSFW 0x00000080
#تعریف_کرو BSF_SENDNOTIFYMESSAGE 0x00000100
#تعریف_کرو BSF_RETURNHDESK 0x00000200
#تعریف_کرو BSF_LUID 0x00000400

#تعریف_کرو نشر_QUERY_DENY 0x424D5144

  تعريفنوع PVOID HDEVNOTIFY;
  تعريفنوع HDEVNOTIFY *PHDEVNOTIFY;

#تعریف_کرو DEVICE_NOTIFY_کھڑکی_HANDLE 0x00000000
#تعریف_کرو DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#تعریف_کرو DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#جے_تعریف_شدہ UNICODE
#تعریف_کرو رجسٹر_Device_Notification رجسٹر_Device_Notification_W
#تعریف_کرو Post_سنیہا Post_سنیہا_W
#تعریف_کرو Post_Thread_سنیہا Post_Thread_سنیہا_W
#تعریف_کرو Post_App_سنیہا Post_App_سنیہا_W
#تعریف_کرو Def_کھڑکی_Proc Def_کھڑکی_Proc_W
#تعریف_کرو Call_کھڑکی_Proc Call_کھڑکی_Proc_W
#تعریف_کرو رجسٹر_Class رجسٹر_Class_W
#تعریف_کرو UnregisterClass UnregisterClassW
#تعریف_کرو GetClassInfo GetClassInfoW
#تعریف_کرو رجسٹر_Class_Ex رجسٹر_Class_Ex_W
#تعریف_کرو GetClassInfoEx GetClassInfoExW
#وإلا
#تعریف_کرو رجسٹر_Device_Notification رجسٹر_Device_Notification_A
#تعریف_کرو Post_سنیہا Post_سنیہا_A
#تعریف_کرو Post_Thread_سنیہا Post_Thread_سنیہا_A
#تعریف_کرو Post_App_سنیہا Post_App_سنیہا_A
#تعریف_کرو Def_کھڑکی_Proc Def_کھڑکی_Proc_A
#تعریف_کرو Call_کھڑکی_Proc Call_کھڑکی_Proc_A
#تعریف_کرو رجسٹر_Class رجسٹر_Class_A
#تعریف_کرو UnregisterClass UnregisterClassA
#تعریف_کرو GetClassInfo GetClassInfoA
#تعریف_کرو رجسٹر_Class_Ex رجسٹر_Class_Ex_A
#تعریف_کرو GetClassInfoEx GetClassInfoExA
#جے_انت

  WINUSERAPI HDEVNOTIFY WINAPI رجسٹر_Device_Notification_A(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI HDEVNOTIFY WINAPI رجسٹر_Device_Notification_W(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI WINBOOL WINAPI UnregisterDeviceNotification(HDEVNOTIFY Handle);
  WINUSERAPI WINBOOL WINAPI Post_سنیہا_A(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_سنیہا_W(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_سنیہا_A(DWORD idThread,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_سنیہا_W(DWORD idThread,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
#تعریف_کرو Post_App_سنیہا_A(idThread,w_پیغام,wParam,lParam) Post_Thread_سنیہا_A((DWORD)idThread,w_پیغام,wParam,lParam)
#تعریف_کرو Post_App_سنیہا_W(idThread,w_پیغام,wParam,lParam) Post_Thread_سنیہا_W((DWORD)idThread,w_پیغام,wParam,lParam)

#تعریف_کرو HWND_نشر ((HWND)0xffff)
#تعریف_کرو HWND_سنیہا ((HWND)-3)

  WINUSERAPI WINBOOL WINAPI Attach_Thread_داخلہ(DWORD idAttach,DWORD id_Attach_منزل,WINBOOL fAttach);
  WINUSERAPI WINBOOL WINAPI جواب_سنیہا(LRESULT l_نتیجہ);
  WINUSERAPI WINBOOL WINAPI Wait_سنیہا(VOID);
  WINUSERAPI DWORD WINAPI Wait_For_داخلہ_Idle(HANDLE hProcess,DWORD dwMilliseconds);
  WINUSERAPI LRESULT WINAPI Def_کھڑکی_Proc_A(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_کھڑکی_Proc_W(HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI VOID WINAPI Post_Quit_سنیہا(صحيح n_Exit_کوڈ);
  WINUSERAPI LRESULT WINAPI Call_کھڑکی_Proc_A(WNDPROC lpPrevWndFunc,HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Call_کھڑکی_Proc_W(WNDPROC lpPrevWndFunc,HWND hWnd,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI وچ_Send_سنیہا(VOID);
  WINUSERAPI DWORD WINAPI وچ_Send_سنیہا_Ex(LPVOID lpReserved);

#تعریف_کرو ISMEX_NOSEND 0x00000000
#تعریف_کرو ISMEX_SEND 0x00000001
#تعریف_کرو ISMEX_NOTIFY 0x00000002
#تعریف_کرو ISMEX_CALLBACK 0x00000004
#تعریف_کرو ISMEX_REPLIED 0x00000008

  WINUSERAPI UINT WINAPI Get_Double_Click_ویلا(VOID);
  WINUSERAPI WINBOOL WINAPI سیٹ_Double_Click_ویلا(UINT);
  WINUSERAPI ATOM WINAPI رجسٹر_Class_A(CONST WNDCLASSA *lpWndClass);
  WINUSERAPI ATOM WINAPI رجسٹر_Class_W(CONST WNDCLASSW *lpWndClass);
  WINUSERAPI WINBOOL WINAPI UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
  WINUSERAPI WINBOOL WINAPI GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
  WINUSERAPI ATOM WINAPI رجسٹر_Class_Ex_A(CONST WNDCLASSEXA *);
  WINUSERAPI ATOM WINAPI رجسٹر_Class_Ex_W(CONST WNDCLASSEXW *);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);

#تعریف_کرو CW_USEDEFAULT ((صحيح)0x80000000)

#تعریف_کرو HWND_DESKTOP ((HWND)0)

  تعريفنوع BOOLEAN (WINAPI *PREGISTERCLASSNAMEW)(LPCWSTR);

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Create_کھڑکی_Ex Create_کھڑکی_Ex_W
#تعریف_کرو Create_کھڑکی Create_کھڑکی_W
#وإلا
#تعریف_کرو Create_کھڑکی_Ex Create_کھڑکی_Ex_A
#تعریف_کرو Create_کھڑکی Create_کھڑکی_A
#جے_انت

  WINUSERAPI HWND WINAPI Create_کھڑکی_Ex_A(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lp_کھڑکی_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_چوڑائی,صحيح n_اچائی,HWND h_Wnd_ماپا,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
  WINUSERAPI HWND WINAPI Create_کھڑکی_Ex_W(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lp_کھڑکی_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_چوڑائی,صحيح n_اچائی,HWND h_Wnd_ماپا,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
#تعریف_کرو Create_کھڑکی_A(lpClassName,lp_کھڑکی_Name,dwStyle,x,y,n_چوڑائی,n_اچائی,h_Wnd_ماپا,hMenu,hInstance,lpParam) Create_کھڑکی_Ex_A(0L,lpClassName,lp_کھڑکی_Name,dwStyle,x,y,n_چوڑائی,n_اچائی,h_Wnd_ماپا,hMenu,hInstance,lpParam)
#تعریف_کرو Create_کھڑکی_W(lpClassName,lp_کھڑکی_Name,dwStyle,x,y,n_چوڑائی,n_اچائی,h_Wnd_ماپا,hMenu,hInstance,lpParam) Create_کھڑکی_Ex_W(0L,lpClassName,lp_کھڑکی_Name,dwStyle,x,y,n_چوڑائی,n_اچائی,h_Wnd_ماپا,hMenu,hInstance,lpParam)
  WINUSERAPI WINBOOL WINAPI Is_کھڑکی(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsMenu(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI Is_بچہ(HWND h_Wnd_ماپا,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Destroy_کھڑکی(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Show_کھڑکی(HWND hWnd,صحيح nCmdShow);
  WINUSERAPI WINBOOL WINAPI Animate_کھڑکی(HWND hWnd,DWORD dw_ویلا,DWORD dwFlags);

#إذا defined(_WINGDI_) && !defined(NOGDI)
  WINUSERAPI WINBOOL WINAPI Update_Layered_کھڑکی(HWND hWnd,HDC hdcDst,نقطہ_3 *pptDst,ناپ_2 *psize,HDC hdcSrc,نقطہ_3 *pptSrc,COLORREF cr_کلید,BLENDFUNCTION *pblend,DWORD dwFlags);

  تعريفنوع بنية ٹیگ_UPDATELAYEREDWINDOWINFO {
    DWORD cb_ناپ;
    HDC hdcDst;
    نقطہ_3 CONST *pptDst;
    ناپ_2 CONST *psize;
    HDC hdcSrc;
    نقطہ_3 CONST *pptSrc;
    COLORREF cr_کلید;
    BLENDFUNCTION CONST *pblend;
    DWORD dwFlags;
    RECT CONST *prcDirty;
  } UPDATELAYEREDWINDOWINFO,*PUPDATELAYEREDWINDOWINFO;

  WINUSERAPI WINBOOL WINAPI Update_Layered_کھڑکی_اسدھا(HWND hWnd,UPDATELAYEREDWINDOWINFO CONST *pULWInfo);
  WINUSERAPI WINBOOL WINAPI Get_Layered_کھڑکی_گن(HWND hwnd,COLORREF *pcr_کلید,BYTE *pbAlpha,DWORD *pdwFlags);

#تعریف_کرو PW_CLIENTONLY 0x00000001

  WINUSERAPI WINBOOL WINAPI Print_کھڑکی(HWND hwnd,HDC hdcBlt,UINT nFlags);
  WINUSERAPI WINBOOL WINAPI سیٹ_Layered_کھڑکی_گن(HWND hwnd,COLORREF cr_کلید,BYTE bAlpha,DWORD dwFlags);

#تعریف_کرو LWA_COLORKEY 0x00000001
#تعریف_کرو LWA_ALPHA 0x00000002

#تعریف_کرو ULW_COLORKEY 0x00000001
#تعریف_کرو ULW_ALPHA 0x00000002
#تعریف_کرو ULW_OPAQUE 0x00000004

#تعریف_کرو ULW_EX_NORESIZE 0x00000008

  WINUSERAPI WINBOOL WINAPI Show_کھڑکی_Async(HWND hWnd,صحيح nCmdShow);
  WINUSERAPI WINBOOL WINAPI Flash_کھڑکی(HWND hWnd,WINBOOL bInvert);

  تعريفنوع بنية {
    UINT cb_ناپ;
    HWND hwnd;
    DWORD dwFlags;
    UINT u_گنتی;
    DWORD dwTimeout;
  } FLASHWINFO,*PFLASHWINFO;

  WINUSERAPI WINBOOL WINAPI Flash_کھڑکی_Ex(PFLASHWINFO pfwi);

#تعریف_کرو FLASHW_STOP 0
#تعریف_کرو FLASHW_CAPTION 0x00000001
#تعریف_کرو FLASHW_TRAY 0x00000002
#تعریف_کرو FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#تعریف_کرو FLASHW_TIMER 0x00000004
#تعریف_کرو FLASHW_TIMERNOFG 0x0000000C

  WINUSERAPI WINBOOL WINAPI ShowOwnedPopups(HWND hWnd,WINBOOL fShow);
  WINUSERAPI WINBOOL WINAPI OpenIcon(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Close_کھڑکی(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Move_کھڑکی(HWND hWnd,صحيح X,صحيح Y,صحيح n_چوڑائی,صحيح n_اچائی,WINBOOL bRepaint);
  WINUSERAPI WINBOOL WINAPI سیٹ_کھڑکی_Pos(HWND hWnd,HWND h_Wnd_داخل_کرو_After,صحيح X,صحيح Y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI Get_کھڑکی_Placement(HWND hWnd,WINDOWPLACEMENT *lpwndpl);
  WINUSERAPI WINBOOL WINAPI سیٹ_کھڑکی_Placement(HWND hWnd,CONST WINDOWPLACEMENT *lpwndpl);

#جے_بنا_تعریف NODEFERWINDOWPOS
  WINUSERAPI HDWP WINAPI Begin_Defer_کھڑکی_Pos(صحيح n_عدد_Windows);
  WINUSERAPI HDWP WINAPI Defer_کھڑکی_Pos(HDWP hWinPosInfo,HWND hWnd,HWND h_Wnd_داخل_کرو_After,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI سرا_Defer_کھڑکی_Pos(HDWP hWinPosInfo);
#جے_انت

  WINUSERAPI WINBOOL WINAPI Is_کھڑکی_Visible(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsIconic(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AnyPopup(VOID);
  WINUSERAPI WINBOOL WINAPI Bring_کھڑکی_منزل_چوٹی(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsZoomed(HWND hWnd);

#تعریف_کرو SWP_NOSIZE 0x0001
#تعریف_کرو SWP_NOMOVE 0x0002
#تعریف_کرو SWP_NOZORDER 0x0004
#تعریف_کرو SWP_NOREDRAW 0x0008
#تعریف_کرو SWP_NOACTIVATE 0x0010
#تعریف_کرو SWP_FRAMECHANGED 0x0020
#تعریف_کرو SWP_SHOWWINDOW 0x0040
#تعریف_کرو SWP_HIDEWINDOW 0x0080
#تعریف_کرو SWP_NOCOPYBITS 0x0100
#تعریف_کرو SWP_NOOWNERZORDER 0x0200
#تعریف_کرو SWP_NOSENDCHANGING 0x0400

#تعریف_کرو SWP_DRAWFRAME SWP_FRAMECHANGED
#تعریف_کرو SWP_NOREPOSITION SWP_NOOWNERZORDER
#تعریف_کرو SWP_DEFERERASE 0x2000
#تعریف_کرو SWP_ASYNCWINDOWPOS 0x4000

#تعریف_کرو HWND_چوٹی ((HWND)0)
#تعریف_کرو HWND_BOTTOM ((HWND)1)
#تعریف_کرو HWND_TOPMOST ((HWND)-1)
#تعریف_کرو HWND_NOTOPMOST ((HWND)-2)

#جے_بنا_تعریف NOCTLMGR

#ضمن <pshpack2.h>

  تعريفنوع بنية {
    DWORD style;
    DWORD dwExtendedStyle;
    لفظ_3 cdit;
    چھوٹا x;
    چھوٹا y;
    چھوٹا cx;
    چھوٹا cy;
  } DLGTEMPLATE;

  تعريفنوع DLGTEMPLATE *LPDLGTEMPLATEA;
  تعريفنوع DLGTEMPLATE *LPDLGTEMPLATEW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع LPDLGTEMPLATEW LPDLGTEMPLATE;
#وإلا
  تعريفنوع LPDLGTEMPLATEA LPDLGTEMPLATE;
#جے_انت

  تعريفنوع CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
  تعريفنوع CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#وإلا
  تعريفنوع LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#جے_انت

  تعريفنوع بنية {
    DWORD style;
    DWORD dwExtendedStyle;
    چھوٹا x;
    چھوٹا y;
    چھوٹا cx;
    چھوٹا cy;
    لفظ_3 id;
  } DLGITEMTEMPLATE;

  تعريفنوع DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
  تعريفنوع DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#وإلا
  تعريفنوع PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#جے_انت

  تعريفنوع DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
  تعريفنوع DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#وإلا
  تعريفنوع LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#جے_انت

#ضمن <poppack.h>

#جے_تعریف_شدہ UNICODE
#تعریف_کرو CreateDialogParam CreateDialogParamW
#تعریف_کرو Create_Dialog_اسدھا_Param Create_Dialog_اسدھا_Param_W
#تعریف_کرو CreateDialog CreateDialogW
#تعریف_کرو Create_Dialog_اسدھا Create_Dialog_اسدھا_W
#تعریف_کرو DialogBoxParam DialogBoxParamW
#تعریف_کرو Dialog_Box_اسدھا_Param Dialog_Box_اسدھا_Param_W
#تعریف_کرو DialogBox DialogBoxW
#تعریف_کرو Dialog_Box_اسدھا Dialog_Box_اسدھا_W
#تعریف_کرو سیٹ_Dlg_شے_متن سیٹ_Dlg_شے_متن_W
#تعریف_کرو Get_Dlg_شے_متن Get_Dlg_شے_متن_W
#تعریف_کرو Send_Dlg_شے_سنیہا Send_Dlg_شے_سنیہا_W
#تعریف_کرو DefDlgProc DefDlgProcW
#وإلا
#تعریف_کرو CreateDialogParam CreateDialogParamA
#تعریف_کرو Create_Dialog_اسدھا_Param Create_Dialog_اسدھا_Param_A
#تعریف_کرو CreateDialog CreateDialogA
#تعریف_کرو Create_Dialog_اسدھا Create_Dialog_اسدھا_A
#تعریف_کرو DialogBoxParam DialogBoxParamA
#تعریف_کرو Dialog_Box_اسدھا_Param Dialog_Box_اسدھا_Param_A
#تعریف_کرو DialogBox DialogBoxA
#تعریف_کرو Dialog_Box_اسدھا Dialog_Box_اسدھا_A
#تعریف_کرو سیٹ_Dlg_شے_متن سیٹ_Dlg_شے_متن_A
#تعریف_کرو Get_Dlg_شے_متن Get_Dlg_شے_متن_A
#تعریف_کرو Send_Dlg_شے_سنیہا Send_Dlg_شے_سنیہا_A
#تعریف_کرو DefDlgProc DefDlgProcA
#جے_انت

  WINUSERAPI HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_ماپا,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_ماپا,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_اسدھا_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND h_Wnd_ماپا,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_اسدھا_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND h_Wnd_ماپا,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#تعریف_کرو CreateDialogA(hInstance,lpName,h_Wnd_ماپا,lpDialogFunc) CreateDialogParamA(hInstance,lpName,h_Wnd_ماپا,lpDialogFunc,0L)
#تعریف_کرو CreateDialogW(hInstance,lpName,h_Wnd_ماپا,lpDialogFunc) CreateDialogParamW(hInstance,lpName,h_Wnd_ماپا,lpDialogFunc,0L)
#تعریف_کرو Create_Dialog_اسدھا_A(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc) Create_Dialog_اسدھا_Param_A(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc,0L)
#تعریف_کرو Create_Dialog_اسدھا_W(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc) Create_Dialog_اسدھا_Param_W(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc,0L)
  WINUSERAPI INT_PTR WINAPI DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_ماپا,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_ماپا,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_اسدھا_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND h_Wnd_ماپا,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_اسدھا_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND h_Wnd_ماپا,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#تعریف_کرو DialogBoxA(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc,0L)
#تعریف_کرو DialogBoxW(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc,0L)
#تعریف_کرو Dialog_Box_اسدھا_A(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc) Dialog_Box_اسدھا_Param_A(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc,0L)
#تعریف_کرو Dialog_Box_اسدھا_W(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc) Dialog_Box_اسدھا_Param_W(hInstance,lpTemplate,h_Wnd_ماپا,lpDialogFunc,0L)
  WINUSERAPI WINBOOL WINAPI سرا_Dialog(HWND hDlg,INT_PTR n_نتیجہ);
  WINUSERAPI HWND WINAPI Get_Dlg_شے(HWND hDlg,صحيح n_IDDlg_شے);
  WINUSERAPI WINBOOL WINAPI سیٹ_Dlg_شے_Int(HWND hDlg,صحيح n_IDDlg_شے,UINT u_قدر,WINBOOL bSigned);
  WINUSERAPI UINT WINAPI Get_Dlg_شے_Int(HWND hDlg,صحيح n_IDDlg_شے,WINBOOL *lpTranslated,WINBOOL bSigned);
  WINUSERAPI WINBOOL WINAPI سیٹ_Dlg_شے_متن_A(HWND hDlg,صحيح n_IDDlg_شے,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI سیٹ_Dlg_شے_متن_W(HWND hDlg,صحيح n_IDDlg_شے,LPCWSTR lpString);
  WINUSERAPI UINT WINAPI Get_Dlg_شے_متن_A(HWND hDlg,صحيح n_IDDlg_شے,LPSTR lpString,صحيح cchMax);
  WINUSERAPI UINT WINAPI Get_Dlg_شے_متن_W(HWND hDlg,صحيح n_IDDlg_شے,LPWSTR lpString,صحيح cchMax);
  WINUSERAPI WINBOOL WINAPI CheckDlgButton(HWND hDlg,صحيح nIDButton,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI CheckRadioButton(HWND hDlg,صحيح nIDFirstButton,صحيح nIDLastButton,صحيح nIDCheckButton);
  WINUSERAPI UINT WINAPI IsDlgButtonChecked(HWND hDlg,صحيح nIDButton);
  WINUSERAPI LRESULT WINAPI Send_Dlg_شے_سنیہا_A(HWND hDlg,صحيح n_IDDlg_شے,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_Dlg_شے_سنیہا_W(HWND hDlg,صحيح n_IDDlg_شے,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI HWND WINAPI Get_اگلا_Dlg_گروہ_شے(HWND hDlg,HWND hCtl,WINBOOL b_پچھلا);
  WINUSERAPI HWND WINAPI Get_اگلا_Dlg_Tab_شے(HWND hDlg,HWND hCtl,WINBOOL b_پچھلا);
  WINUSERAPI صحيح WINAPI GetDlgCtrlID(HWND hWnd);
  WINUSERAPI لما WINAPI Get_Dialog_ادھار_Units(VOID);
  WINUSERAPI LRESULT WINAPI DefDlgProcA(HWND hDlg,UINT پیغام_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefDlgProcW(HWND hDlg,UINT پیغام_3,WPARAM wParam,LPARAM lParam);

#تعریف_کرو DLGWINDOWEXTRA 30
#جے_انت

#جے_بنا_تعریف NOMSG

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Call_پیغام_Filter Call_پیغام_Filter_W
#وإلا
#تعریف_کرو Call_پیغام_Filter Call_پیغام_Filter_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI Call_پیغام_Filter_A(LPMSG lp_پیغام,صحيح n_کوڈ);
  WINUSERAPI WINBOOL WINAPI Call_پیغام_Filter_W(LPMSG lp_پیغام,صحيح n_کوڈ);
#جے_انت

#جے_بنا_تعریف NOCLIPBOARD

#جے_تعریف_شدہ UNICODE
#تعریف_کرو رجسٹر_Clipboard_Format رجسٹر_Clipboard_Format_W
#تعریف_کرو GetClipboardFormatName GetClipboardFormatNameW
#وإلا
#تعریف_کرو رجسٹر_Clipboard_Format رجسٹر_Clipboard_Format_A
#تعریف_کرو GetClipboardFormatName GetClipboardFormatNameA
#جے_انت

  WINUSERAPI WINBOOL WINAPI OpenClipboard(HWND hWndNewOwner);
  WINUSERAPI WINBOOL WINAPI CloseClipboard(VOID);
  WINUSERAPI DWORD WINAPI Get_Clipboard_Sequence_نمبر(VOID);
  WINUSERAPI HWND WINAPI GetClipboardOwner(VOID);
  WINUSERAPI HWND WINAPI سیٹ_Clipboard_Viewer(HWND hWndNewViewer);
  WINUSERAPI HWND WINAPI GetClipboardViewer(VOID);
  WINUSERAPI WINBOOL WINAPI ChangeClipboardChain(HWND hWndRemove,HWND h_Wnd_New_اگلا);
  WINUSERAPI HANDLE WINAPI سیٹ_Clipboard_انکڑے(UINT uFormat,HANDLE hMem);
  WINUSERAPI HANDLE WINAPI Get_Clipboard_انکڑے(UINT uFormat);
  WINUSERAPI UINT WINAPI رجسٹر_Clipboard_Format_A(LPCSTR lpszFormat);
  WINUSERAPI UINT WINAPI رجسٹر_Clipboard_Format_W(LPCWSTR lpszFormat);
  WINUSERAPI صحيح WINAPI گنتی_Clipboard_Formats(VOID);
  WINUSERAPI UINT WINAPI EnumClipboardFormats(UINT format);
  WINUSERAPI صحيح WINAPI GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,صحيح cch_Max_گنتی);
  WINUSERAPI صحيح WINAPI GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,صحيح cch_Max_گنتی);
  WINUSERAPI WINBOOL WINAPI خالی_تھاواں_Clipboard(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Clipboard_Format_دستیاب(UINT format);
  WINUSERAPI صحيح WINAPI Get_ترجیح_Clipboard_Format(UINT *pa_Format_ترجیح_List,صحيح cFormats);
  WINUSERAPI HWND WINAPI Get_Open_Clipboard_کھڑکی(VOID);
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Char_منزل_Oem Char_منزل_Oem_W
#تعریف_کرو Oem_منزل_Char Oem_منزل_Char_W
#تعریف_کرو Char_منزل_Oem_Buff Char_منزل_Oem_Buff_W
#تعریف_کرو Oem_منزل_Char_Buff Oem_منزل_Char_Buff_W
#تعریف_کرو Char_اتلا Char_اتلا_W
#تعریف_کرو Char_اتلا_Buff Char_اتلا_Buff_W
#تعریف_کرو Char_ہیٹھلا Char_ہیٹھلا_W
#تعریف_کرو Char_ہیٹھلا_Buff Char_ہیٹھلا_Buff_W
#تعریف_کرو Char_اگلا Char_اگلا_W
#تعریف_کرو CharPrev CharPrevW
#وإلا
#تعریف_کرو Char_منزل_Oem Char_منزل_Oem_A
#تعریف_کرو Oem_منزل_Char Oem_منزل_Char_A
#تعریف_کرو Char_منزل_Oem_Buff Char_منزل_Oem_Buff_A
#تعریف_کرو Oem_منزل_Char_Buff Oem_منزل_Char_Buff_A
#تعریف_کرو Char_اتلا Char_اتلا_A
#تعریف_کرو Char_اتلا_Buff Char_اتلا_Buff_A
#تعریف_کرو Char_ہیٹھلا Char_ہیٹھلا_A
#تعریف_کرو Char_ہیٹھلا_Buff Char_ہیٹھلا_Buff_A
#تعریف_کرو Char_اگلا Char_اگلا_A
#تعریف_کرو CharPrev CharPrevA
#جے_انت

  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_W(LPCWSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_W(LPCSTR lpszSrc,LPWSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_لمائی);
  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_Buff_W(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_لمائی);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_لمائی);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_Buff_W(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cch_Dst_لمائی);
  WINUSERAPI LPSTR WINAPI Char_اتلا_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_اتلا_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_اتلا_Buff_A(LPSTR lpsz,DWORD cch_لمائی);
  WINUSERAPI DWORD WINAPI Char_اتلا_Buff_W(LPWSTR lpsz,DWORD cch_لمائی);
  WINUSERAPI LPSTR WINAPI Char_ہیٹھلا_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ہیٹھلا_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_ہیٹھلا_Buff_A(LPSTR lpsz,DWORD cch_لمائی);
  WINUSERAPI DWORD WINAPI Char_ہیٹھلا_Buff_W(LPWSTR lpsz,DWORD cch_لمائی);
  WINUSERAPI LPSTR WINAPI Char_اگلا_A(LPCSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_اگلا_W(LPCWSTR lpsz);
  WINUSERAPI LPSTR WINAPI CharPrevA(LPCSTR lpsz_شروع,LPCSTR lpszCurrent);
  WINUSERAPI LPWSTR WINAPI CharPrevW(LPCWSTR lpsz_شروع,LPCWSTR lpszCurrent);
  WINUSERAPI LPSTR WINAPI Char_اگلا_Ex_A(لفظ_3 کوڈ_ورقہ,LPCSTR lpCurrentChar,DWORD dwFlags);
  WINUSERAPI LPSTR WINAPI CharPrevExA(لفظ_3 کوڈ_ورقہ,LPCSTR lp_شروع,LPCSTR lpCurrentChar,DWORD dwFlags);

#تعریف_کرو Ansi_منزل_Oem Char_منزل_Oem_A
#تعریف_کرو Oem_منزل_Ansi Oem_منزل_Char_A
#تعریف_کرو Ansi_منزل_Oem_Buff Char_منزل_Oem_Buff_A
#تعریف_کرو Oem_منزل_Ansi_Buff Oem_منزل_Char_Buff_A
#تعریف_کرو Ansi_اتلا Char_اتلا_A
#تعریف_کرو Ansi_اتلا_Buff Char_اتلا_Buff_A
#تعریف_کرو Ansi_ہیٹھلا Char_ہیٹھلا_A
#تعریف_کرو Ansi_ہیٹھلا_Buff Char_ہیٹھلا_Buff_A
#تعریف_کرو Ansi_اگلا Char_اگلا_A
#تعریف_کرو AnsiPrev CharPrevA

#جے_بنا_تعریف NOLANGUAGE

#جے_تعریف_شدہ UNICODE
#تعریف_کرو IsCharAlpha IsCharAlphaW
#تعریف_کرو IsCharAlphaNumeric IsCharAlphaNumericW
#تعریف_کرو Is_Char_اتلا Is_Char_اتلا_W
#تعریف_کرو Is_Char_ہیٹھلا Is_Char_ہیٹھلا_W
#وإلا
#تعریف_کرو IsCharAlpha IsCharAlphaA
#تعریف_کرو IsCharAlphaNumeric IsCharAlphaNumericA
#تعریف_کرو Is_Char_اتلا Is_Char_اتلا_A
#تعریف_کرو Is_Char_ہیٹھلا Is_Char_ہیٹھلا_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI IsCharAlphaA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_اتلا_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_اتلا_W(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ہیٹھلا_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ہیٹھلا_W(WCHAR ch);
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_کلید_Name_متن Get_کلید_Name_متن_W
#تعریف_کرو Vk_کلید_جانچ Vk_کلید_جانچ_W
#تعریف_کرو Vk_کلید_جانچ_Ex Vk_کلید_جانچ_Ex_W
#وإلا
#تعریف_کرو Get_کلید_Name_متن Get_کلید_Name_متن_A
#تعریف_کرو Vk_کلید_جانچ Vk_کلید_جانچ_A
#تعریف_کرو Vk_کلید_جانچ_Ex Vk_کلید_جانچ_Ex_A
#جے_انت

  WINUSERAPI HWND WINAPI سیٹ_Focus(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_سرگرم_کھڑکی(VOID);
  WINUSERAPI HWND WINAPI GetFocus(VOID);
  WINUSERAPI UINT WINAPI Get_KBCode_ورقہ(VOID);
  WINUSERAPI SHORT WINAPI Get_کلید_State(صحيح n_Virt_کلید);
  WINUSERAPI SHORT WINAPI Get_Async_کلید_State(صحيح v_کلید);
  WINUSERAPI WINBOOL WINAPI GetKeyboardState(PBYTE lp_کلید_State);
  WINUSERAPI WINBOOL WINAPI سیٹ_Keyboard_State(LPBYTE lp_کلید_State);
  WINUSERAPI صحيح WINAPI Get_کلید_Name_متن_A(LONG lParam,LPSTR lpString,صحيح cch_ناپ);
  WINUSERAPI صحيح WINAPI Get_کلید_Name_متن_W(LONG lParam,LPWSTR lpString,صحيح cch_ناپ);
  WINUSERAPI صحيح WINAPI GetKeyboardType(صحيح nTypeFlag);
  WINUSERAPI صحيح WINAPI منزل_Ascii(UINT u_Virt_کلید,UINT u_جانچ_کوڈ,CONST BYTE *lp_کلید_State,LPWORD lpChar,UINT uFlags);
  WINUSERAPI صحيح WINAPI منزل_Ascii_Ex(UINT u_Virt_کلید,UINT u_جانچ_کوڈ,CONST BYTE *lp_کلید_State,LPWORD lpChar,UINT uFlags,HKL dwhkl);
  WINUSERAPI صحيح WINAPI منزل_Unicode(UINT w_Virt_کلید,UINT w_جانچ_کوڈ,CONST BYTE *lp_کلید_State,LPWSTR pwszBuff,صحيح cchBuff,UINT wFlags);
  WINUSERAPI DWORD WINAPI Oem_کلید_جانچ(لفظ_3 wOemChar);
  WINUSERAPI SHORT WINAPI Vk_کلید_جانچ_A(CHAR ch);
  WINUSERAPI SHORT WINAPI Vk_کلید_جانچ_W(WCHAR ch);
  WINUSERAPI SHORT WINAPI Vk_کلید_جانچ_Ex_A(CHAR ch,HKL dwhkl);
  WINUSERAPI SHORT WINAPI Vk_کلید_جانچ_Ex_W(WCHAR ch,HKL dwhkl);

#تعریف_کرو KEYEVENTF_EXTENDEDKEY 0x0001
#تعریف_کرو KEYEVENTF_KEYUP 0x0002
#تعریف_کرو KEYEVENTF_UNICODE 0x0004
#تعریف_کرو KEYEVENTF_SCANCODE 0x0008

  WINUSERAPI VOID WINAPI keybd_event(BYTE bVk,BYTE b_جانچ,DWORD dwFlags,ULONG_PTR dwExtraInfo);

#تعریف_کرو MOUSEEVENTF_MOVE 0x0001
#تعریف_کرو MOUSEEVENTF_LEFTDOWN 0x0002
#تعریف_کرو MOUSEEVENTF_LEFTUP 0x0004
#تعریف_کرو MOUSEEVENTF_RIGHTDOWN 0x0008
#تعریف_کرو MOUSEEVENTF_RIGHTUP 0x0010
#تعریف_کرو MOUSEEVENTF_MIDDLEDOWN 0x0020
#تعریف_کرو MOUSEEVENTF_MIDDLEUP 0x0040
#تعریف_کرو MOUSEEVENTF_XDOWN 0x0080
#تعریف_کرو MOUSEEVENTF_XUP 0x0100
#تعریف_کرو MOUSEEVENTF_WHEEL 0x0800
#تعریف_کرو MOUSEEVENTF_VIRTUALDESK 0x4000
#تعریف_کرو MOUSEEVENTF_ABSOLUTE 0x8000

  WINUSERAPI VOID WINAPI mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dw_انکڑے,ULONG_PTR dwExtraInfo);

  تعريفنوع بنية ٹیگ_MOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouse_انکڑے;
    DWORD dwFlags;
    DWORD ویلا;
    ULONG_PTR dwExtraInfo;
  } MOUSEINPUT,*PMOUSEINPUT,*LPMOUSEINPUT;

  تعريفنوع بنية ٹیگ_KEYBDINPUT {
    لفظ_3 wVk;
    لفظ_3 w_جانچ;
    DWORD dwFlags;
    DWORD ویلا;
    ULONG_PTR dwExtraInfo;
  } KEYBDINPUT,*PKEYBDINPUT,*LPKEYBDINPUT;

  تعريفنوع بنية ٹیگ_HARDWAREINPUT {
    DWORD u_پیغام;
    لفظ_3 wParamL;
    لفظ_3 wParamH;
  } HARDWAREINPUT,*PHARDWAREINPUT,*LPHARDWAREINPUT;

#تعریف_کرو داخلہ_MOUSE 0
#تعریف_کرو داخلہ_KEYBOARD 1
#تعریف_کرو داخلہ_HARDWARE 2

  تعريفنوع بنية ٹیگ_داخلہ {
    DWORD type;
    اتحاد {
      MOUSEINPUT mi;
      KEYBDINPUT ki;
      HARDWAREINPUT hi;
    };
  } داخلہ_2,*PINPUT,*LPINPUT;

  WINUSERAPI UINT WINAPI Send_داخلہ(UINT cInputs,LPINPUT pInputs,صحيح cb_ناپ);

  تعريفنوع بنية ٹیگ_LASTINPUTINFO {
    UINT cb_ناپ;
    DWORD dw_ویلا;
  } LASTINPUTINFO,*PLASTINPUTINFO;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Map_Virtual_کلید Map_Virtual_کلید_W
#تعریف_کرو Map_Virtual_کلید_Ex Map_Virtual_کلید_Ex_W
#وإلا
#تعریف_کرو Map_Virtual_کلید Map_Virtual_کلید_A
#تعریف_کرو Map_Virtual_کلید_Ex Map_Virtual_کلید_Ex_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI Get_آخری_داخلہ_Info(PLASTINPUTINFO plii);
  WINUSERAPI UINT WINAPI Map_Virtual_کلید_A(UINT u_کوڈ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_کلید_W(UINT u_کوڈ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_کلید_Ex_A(UINT u_کوڈ,UINT uMapType,HKL dwhkl);
  WINUSERAPI UINT WINAPI Map_Virtual_کلید_Ex_W(UINT u_کوڈ,UINT uMapType,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI Get_داخلہ_State(VOID);
  WINUSERAPI DWORD WINAPI Get_قطار_حالت(UINT flags);
  WINUSERAPI HWND WINAPI GetCapture(VOID);
  WINUSERAPI HWND WINAPI سیٹ_Capture(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ReleaseCapture(VOID);
  WINUSERAPI DWORD WINAPI پیغام_Wait_For_مضرب_Objects(DWORD n_گنتی,CONST HANDLE *pHandles,WINBOOL fWaitAll,DWORD dwMilliseconds,DWORD dw_Wake_نقاب);
  WINUSERAPI DWORD WINAPI پیغام_Wait_For_مضرب_Objects_Ex(DWORD n_گنتی,CONST HANDLE *pHandles,DWORD dwMilliseconds,DWORD dw_Wake_نقاب,DWORD dwFlags);

#تعریف_کرو MWMO_WAITALL 0x0001
#تعریف_کرو MWMO_ALERTABLE 0x0002
#تعریف_کرو MWMO_INPUTAVAILABLE 0x0004

#تعریف_کرو QS_کلید 0x0001
#تعریف_کرو QS_MOUSEMOVE 0x0002
#تعریف_کرو QS_MOUSEBUTTON 0x0004
#تعریف_کرو QS_POSTMESSAGE 0x0008
#تعریف_کرو QS_TIMER 0x0010
#تعریف_کرو QS_PAINT 0x0020
#تعریف_کرو QS_SENDMESSAGE 0x0040
#تعریف_کرو QS_HOTKEY 0x0080
#تعریف_کرو QS_ALLPOSTMESSAGE 0x0100
#تعریف_کرو QS_RAWINPUT 0x0400
#تعریف_کرو QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#تعریف_کرو QS_داخلہ (QS_MOUSE | QS_کلید | QS_RAWINPUT)
#تعریف_کرو QS_ALLEVENTS (QS_داخلہ | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#تعریف_کرو QS_ALLINPUT (QS_داخلہ | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#تعریف_کرو USER_TIMER_ودھ_توں_ودھ 0x7FFFFFFF
#تعریف_کرو USER_TIMER_MINIMUM 0x0000000A

#جے_تعریف_شدہ UNICODE
#تعریف_کرو لدو_Accelerators لدو_Accelerators_W
#تعریف_کرو Create_Accelerator_جدول Create_Accelerator_جدول_W
#تعریف_کرو Copy_Accelerator_جدول Copy_Accelerator_جدول_W
#وإلا
#تعریف_کرو لدو_Accelerators لدو_Accelerators_A
#تعریف_کرو Create_Accelerator_جدول Create_Accelerator_جدول_A
#تعریف_کرو Copy_Accelerator_جدول Copy_Accelerator_جدول_A
#جے_انت

  WINUSERAPI UINT_PTR WINAPI سیٹ_Timer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
  WINUSERAPI WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);
  WINUSERAPI WINBOOL WINAPI Is_کھڑکی_Unicode(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Enable_کھڑکی(HWND hWnd,WINBOOL bEnable);
  WINUSERAPI WINBOOL WINAPI Is_کھڑکی_Enabled(HWND hWnd);
  WINUSERAPI HACCEL WINAPI لدو_Accelerators_A(HINSTANCE hInstance,LPCSTR lp_جدول_Name);
  WINUSERAPI HACCEL WINAPI لدو_Accelerators_W(HINSTANCE hInstance,LPCWSTR lp_جدول_Name);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_جدول_A(LPACCEL paccel,صحيح cAccel);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_جدول_W(LPACCEL paccel,صحيح cAccel);
  WINUSERAPI WINBOOL WINAPI Destroy_Accelerator_جدول(HACCEL hAccel);
  WINUSERAPI صحيح WINAPI Copy_Accelerator_جدول_A(HACCEL hAccelSrc,LPACCEL lpAccelDst,صحيح cAccelEntries);
  WINUSERAPI صحيح WINAPI Copy_Accelerator_جدول_W(HACCEL hAccelSrc,LPACCEL lpAccelDst,صحيح cAccelEntries);

#جے_بنا_تعریف NOMSG

#جے_تعریف_شدہ UNICODE
#تعریف_کرو TranslateAccelerator TranslateAcceleratorW
#وإلا
#تعریف_کرو TranslateAccelerator TranslateAcceleratorA
#جے_انت

  WINUSERAPI صحيح WINAPI TranslateAcceleratorA(HWND hWnd,HACCEL h_Acc_جدول,LPMSG lp_پیغام);
  WINUSERAPI صحيح WINAPI TranslateAcceleratorW(HWND hWnd,HACCEL h_Acc_جدول,LPMSG lp_پیغام);
#جے_انت

#جے_بنا_تعریف NOSYSMETRICS

#تعریف_کرو SM_CXSCREEN 0
#تعریف_کرو SM_CYSCREEN 1
#تعریف_کرو SM_CXVSCROLL 2
#تعریف_کرو SM_CYHSCROLL 3
#تعریف_کرو SM_CYCAPTION 4
#تعریف_کرو SM_CXBORDER 5
#تعریف_کرو SM_CYBORDER 6
#تعریف_کرو SM_CXDLGFRAME 7
#تعریف_کرو SM_CYDLGFRAME 8
#تعریف_کرو SM_CYVTHUMB 9
#تعریف_کرو SM_CXHTHUMB 10
#تعریف_کرو SM_CXICON 11
#تعریف_کرو SM_CYICON 12
#تعریف_کرو SM_CXCURSOR 13
#تعریف_کرو SM_CYCURSOR 14
#تعریف_کرو SM_CYMENU 15
#تعریف_کرو SM_CXFULLSCREEN 16
#تعریف_کرو SM_CYFULLSCREEN 17
#تعریف_کرو SM_CYKANJIWINDOW 18
#تعریف_کرو SM_MOUSEPRESENT 19
#تعریف_کرو SM_CYVSCROLL 20
#تعریف_کرو SM_CXHSCROLL 21
#تعریف_کرو SM_DEBUG 22
#تعریف_کرو SM_SWAPBUTTON 23
#تعریف_کرو SM_RESERVED1 24
#تعریف_کرو SM_RESERVED2 25
#تعریف_کرو SM_RESERVED3 26
#تعریف_کرو SM_RESERVED4 27
#تعریف_کرو SM_CXMIN 28
#تعریف_کرو SM_CYMIN 29
#تعریف_کرو SM_CXSIZE 30
#تعریف_کرو SM_CYSIZE 31
#تعریف_کرو SM_CXFRAME 32
#تعریف_کرو SM_CYFRAME 33
#تعریف_کرو SM_CXMINTRACK 34
#تعریف_کرو SM_CYMINTRACK 35
#تعریف_کرو SM_CXDOUBLECLK 36
#تعریف_کرو SM_CYDOUBLECLK 37
#تعریف_کرو SM_CXICONSPACING 38
#تعریف_کرو SM_CYICONSPACING 39
#تعریف_کرو SM_MENUDROPALIGNMENT 40
#تعریف_کرو SM_PENWINDOWS 41
#تعریف_کرو SM_DBCSENABLED 42
#تعریف_کرو SM_CMOUSEBUTTONS 43

#تعریف_کرو SM_CXFIXEDFRAME SM_CXDLGFRAME
#تعریف_کرو SM_CYFIXEDFRAME SM_CYDLGFRAME
#تعریف_کرو SM_CXSIZEFRAME SM_CXFRAME
#تعریف_کرو SM_CYSIZEFRAME SM_CYFRAME

#تعریف_کرو SM_SECURE 44
#تعریف_کرو SM_CXEDGE 45
#تعریف_کرو SM_CYEDGE 46
#تعریف_کرو SM_CXMINSPACING 47
#تعریف_کرو SM_CYMINSPACING 48
#تعریف_کرو SM_CXSMICON 49
#تعریف_کرو SM_CYSMICON 50
#تعریف_کرو SM_CYSMCAPTION 51
#تعریف_کرو SM_CXSMSIZE 52
#تعریف_کرو SM_CYSMSIZE 53
#تعریف_کرو SM_CXMENUSIZE 54
#تعریف_کرو SM_CYMENUSIZE 55
#تعریف_کرو SM_ARRANGE 56
#تعریف_کرو SM_CXMINIMIZED 57
#تعریف_کرو SM_CYMINIMIZED 58
#تعریف_کرو SM_CXMAXTRACK 59
#تعریف_کرو SM_CYMAXTRACK 60
#تعریف_کرو SM_CXMAXIMIZED 61
#تعریف_کرو SM_CYMAXIMIZED 62
#تعریف_کرو SM_جال 63
#تعریف_کرو SM_CLEANBOOT 67
#تعریف_کرو SM_CXDRAG 68
#تعریف_کرو SM_CYDRAG 69
#تعریف_کرو SM_SHOWSOUNDS 70
#تعریف_کرو SM_CXMENUCHECK 71
#تعریف_کرو SM_CYMENUCHECK 72
#تعریف_کرو SM_SLOWMACHINE 73
#تعریف_کرو SM_MIDEASTENABLED 74
#تعریف_کرو SM_MOUSEWHEELPRESENT 75
#تعریف_کرو SM_XVIRTUALSCREEN 76
#تعریف_کرو SM_YVIRTUALSCREEN 77
#تعریف_کرو SM_CXVIRTUALSCREEN 78
#تعریف_کرو SM_CYVIRTUALSCREEN 79
#تعریف_کرو SM_CMONITORS 80
#تعریف_کرو SM_SAMEDISPLAYFORMAT 81
#تعریف_کرو SM_IMMENABLED 82
#تعریف_کرو SM_CXFOCUSBORDER 83
#تعریف_کرو SM_CYFOCUSBORDER 84
#تعریف_کرو SM_TABLETPC 86
#تعریف_کرو SM_MEDIACENTER 87
#تعریف_کرو SM_STARTER 88
#تعریف_کرو SM_SERVERR2 89
#تعریف_کرو SM_CMETRICS 90
#تعریف_کرو SM_REMOTESESSION 0x1000
#تعریف_کرو SM_SHUTTINGDOWN 0x2000
#تعریف_کرو SM_REMOTECONTROL 0x2001
#تعریف_کرو SM_CARETBLINKINGENABLED 0x2002

  WINUSERAPI صحيح WINAPI GetSystemMetrics(صحيح n_اشاریہ);
#جے_انت

#جے_بنا_تعریف NOMENUS

#جے_تعریف_شدہ UNICODE
#تعریف_کرو لدو_Menu لدو_Menu_W
#تعریف_کرو لدو_Menu_اسدھا لدو_Menu_اسدھا_W
#تعریف_کرو ChangeMenu ChangeMenuW
#تعریف_کرو GetMenuString GetMenuStringW
#تعریف_کرو داخل_کرو_Menu داخل_کرو_Menu_W
#تعریف_کرو AppendMenu AppendMenuW
#تعریف_کرو ModifyMenu ModifyMenuW
#وإلا
#تعریف_کرو لدو_Menu لدو_Menu_A
#تعریف_کرو لدو_Menu_اسدھا لدو_Menu_اسدھا_A
#تعریف_کرو ChangeMenu ChangeMenuA
#تعریف_کرو GetMenuString GetMenuStringA
#تعریف_کرو داخل_کرو_Menu داخل_کرو_Menu_A
#تعریف_کرو AppendMenu AppendMenuA
#تعریف_کرو ModifyMenu ModifyMenuA
#جے_انت

  WINUSERAPI HMENU WINAPI لدو_Menu_A(HINSTANCE hInstance,LPCSTR lpMenuName);
  WINUSERAPI HMENU WINAPI لدو_Menu_W(HINSTANCE hInstance,LPCWSTR lpMenuName);
  WINUSERAPI HMENU WINAPI لدو_Menu_اسدھا_A(CONST MENUTEMPLATEA *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI لدو_Menu_اسدھا_W(CONST MENUTEMPLATEW *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI GetMenu(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI سیٹ_Menu(HWND hWnd,HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpsz_New_شے,UINT cmd_داخل_کرو,UINT flags);
  WINUSERAPI WINBOOL WINAPI ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpsz_New_شے,UINT cmd_داخل_کرو,UINT flags);
  WINUSERAPI WINBOOL WINAPI Hilite_Menu_شے(HWND hWnd,HMENU hMenu,UINT u_IDHilite_شے,UINT uHilite);
  WINUSERAPI صحيح WINAPI GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,صحيح cchMax,UINT flags);
  WINUSERAPI صحيح WINAPI GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,صحيح cchMax,UINT flags);
  WINUSERAPI UINT WINAPI GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawMenuBar(HWND hWnd);

#تعریف_کرو PMB_سرگرم 0x00000001

  WINUSERAPI HMENU WINAPI GetSystemMenu(HWND hWnd,WINBOOL bRevert);
  WINUSERAPI HMENU WINAPI CreateMenu(VOID);
  WINUSERAPI HMENU WINAPI CreatePopupMenu(VOID);
  WINUSERAPI WINBOOL WINAPI DestroyMenu(HMENU hMenu);
  WINUSERAPI DWORD WINAPI Check_Menu_شے(HMENU hMenu,UINT u_IDCheck_شے,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI Enable_Menu_شے(HMENU hMenu,UINT u_IDEnable_شے,UINT uEnable);
  WINUSERAPI HMENU WINAPI GetSubMenu(HMENU hMenu,صحيح nPos);
  WINUSERAPI UINT WINAPI Get_Menu_شے_ID(HMENU hMenu,صحيح nPos);
  WINUSERAPI صحيح WINAPI Get_Menu_شے_گنتی(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI داخل_کرو_Menu_A(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_شے,LPCSTR lp_New_شے);
  WINUSERAPI WINBOOL WINAPI داخل_کرو_Menu_W(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_شے,LPCWSTR lp_New_شے);
  WINUSERAPI WINBOOL WINAPI AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_شے,LPCSTR lp_New_شے);
  WINUSERAPI WINBOOL WINAPI AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_شے,LPCWSTR lp_New_شے);
  WINUSERAPI WINBOOL WINAPI ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_شے,LPCSTR lp_New_شے);
  WINUSERAPI WINBOOL WINAPI ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_شے,LPCWSTR lp_New_شے);
  WINUSERAPI WINBOOL WINAPI RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI سیٹ_Menu_شے_Bitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
  WINUSERAPI LONG WINAPI GetMenuCheckMarkDimensions(VOID);
  WINUSERAPI WINBOOL WINAPI TrackPopupMenu(HMENU hMenu,UINT uFlags,صحيح x,صحيح y,صحيح nReserved,HWND hWnd,CONST RECT *prcRect);

#تعریف_کرو MNC_IGNORE 0
#تعریف_کرو MNC_CLOSE 1
#تعریف_کرو MNC_EXECUTE 2
#تعریف_کرو MNC_SELECT 3

  تعريفنوع بنية ٹیگ_TPMPARAMS {
    UINT cb_ناپ;
    RECT rcExclude;
  } TPMPARAMS;

  تعريفنوع TPMPARAMS *LPTPMPARAMS;

  WINUSERAPI WINBOOL WINAPI TrackPopupMenuEx(HMENU,UINT,صحيح,صحيح,HWND,LPTPMPARAMS);

#تعریف_کرو MNS_NOCHECK 0x80000000
#تعریف_کرو MNS_MODELESS 0x40000000
#تعریف_کرو MNS_DRAGDROP 0x20000000
#تعریف_کرو MNS_AUTODISMISS 0x10000000
#تعریف_کرو MNS_NOTIFYBYPOS 0x08000000
#تعریف_کرو MNS_CHECKORBMP 0x04000000

#تعریف_کرو MIM_MAXHEIGHT 0x00000001
#تعریف_کرو MIM_BACKGROUND 0x00000002
#تعریف_کرو MIM_HELPID 0x00000004
#تعریف_کرو MIM_MENUDATA 0x00000008
#تعریف_کرو MIM_STYLE 0x00000010
#تعریف_کرو MIM_APPLYTOSUBMENUS 0x80000000

  تعريفنوع بنية ٹیگ_MENUINFO {
    DWORD cb_ناپ;
    DWORD f_نقاب;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbr_پٹھ;
    DWORD dwContextHelpID;
    ULONG_PTR dw_Menu_انکڑے;
  } MENUINFO,*LPMENUINFO;

  تعريفنوع MENUINFO CONST *LPCMENUINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuInfo(HMENU,LPMENUINFO);
  WINUSERAPI WINBOOL WINAPI سیٹ_Menu_Info(HMENU,LPCMENUINFO);
  WINUSERAPI WINBOOL WINAPI سرا_Menu(VOID);

#تعریف_کرو MND_CONTINUE 0
#تعریف_کرو MND_ENDMENU 1

  تعريفنوع بنية ٹیگ_MENUGETOBJECTINFO {
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
  } MENUGETOBJECTINFO,*PMENUGETOBJECTINFO;

#تعریف_کرو MNGOF_TOPGAP 0x00000001
#تعریف_کرو MNGOF_BOTTOMGAP 0x00000002

#تعریف_کرو MNGO_NOINTERFACE 0x00000000
#تعریف_کرو MNGO_NOERROR 0x00000001

#تعریف_کرو MIIM_STATE 0x00000001
#تعریف_کرو MIIM_ID 0x00000002
#تعریف_کرو MIIM_SUBMENU 0x00000004
#تعریف_کرو MIIM_CHECKMARKS 0x00000008
#تعریف_کرو MIIM_TYPE 0x00000010
#تعریف_کرو MIIM_انکڑے 0x00000020

#تعریف_کرو MIIM_STRING 0x00000040
#تعریف_کرو MIIM_BITMAP 0x00000080
#تعریف_کرو MIIM_FTYPE 0x00000100

#تعریف_کرو HBMMENU_CALLBACK ((HBITMAP) -1)
#تعریف_کرو HBMMENU_SYSTEM ((HBITMAP) 1)
#تعریف_کرو HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#تعریف_کرو HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#تعریف_کرو HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#تعریف_کرو HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#تعریف_کرو HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#تعریف_کرو HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#تعریف_کرو HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#تعریف_کرو HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#تعریف_کرو HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

  تعريفنوع بنية ٹیگ_MENUITEMINFOA {
    UINT cb_ناپ;
    UINT f_نقاب;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_شے_انکڑے;
    LPSTR dw_Type_انکڑے;
    UINT cch;
    HBITMAP hbmp_شے;
  } MENUITEMINFOA,*LPMENUITEMINFOA;

  تعريفنوع بنية ٹیگ_MENUITEMINFOW {
    UINT cb_ناپ;
    UINT f_نقاب;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_شے_انکڑے;
    LPWSTR dw_Type_انکڑے;
    UINT cch;
    HBITMAP hbmp_شے;
  } MENUITEMINFOW,*LPMENUITEMINFOW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع MENUITEMINFOW MENUITEMINFO;
  تعريفنوع LPMENUITEMINFOW LPMENUITEMINFO;
#وإلا
  تعريفنوع MENUITEMINFOA MENUITEMINFO;
  تعريفنوع LPMENUITEMINFOA LPMENUITEMINFO;
#جے_انت
  تعريفنوع MENUITEMINFOA CONST *LPCMENUITEMINFOA;
  تعريفنوع MENUITEMINFOW CONST *LPCMENUITEMINFOW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع LPCMENUITEMINFOW LPCMENUITEMINFO;
#وإلا
  تعريفنوع LPCMENUITEMINFOA LPCMENUITEMINFO;
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو داخل_کرو_Menu_شے داخل_کرو_Menu_شے_W
#تعریف_کرو Get_Menu_شے_Info Get_Menu_شے_Info_W
#تعریف_کرو سیٹ_Menu_شے_Info سیٹ_Menu_شے_Info_W
#وإلا
#تعریف_کرو داخل_کرو_Menu_شے داخل_کرو_Menu_شے_A
#تعریف_کرو Get_Menu_شے_Info Get_Menu_شے_Info_A
#تعریف_کرو سیٹ_Menu_شے_Info سیٹ_Menu_شے_Info_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI داخل_کرو_Menu_شے_A(HMENU hmenu,UINT شے,WINBOOL fByPosition,LPCMENUITEMINFOA lpmi);
  WINUSERAPI WINBOOL WINAPI داخل_کرو_Menu_شے_W(HMENU hmenu,UINT شے,WINBOOL fByPosition,LPCMENUITEMINFOW lpmi);
  WINUSERAPI WINBOOL WINAPI Get_Menu_شے_Info_A(HMENU hmenu,UINT شے,WINBOOL fByPosition,LPMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI Get_Menu_شے_Info_W(HMENU hmenu,UINT شے,WINBOOL fByPosition,LPMENUITEMINFOW lpmii);
  WINUSERAPI WINBOOL WINAPI سیٹ_Menu_شے_Info_A(HMENU hmenu,UINT شے,WINBOOL fByPositon,LPCMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI سیٹ_Menu_شے_Info_W(HMENU hmenu,UINT شے,WINBOOL fByPositon,LPCMENUITEMINFOW lpmii);

#تعریف_کرو GMDI_USEDISABLED 0x0001L
#تعریف_کرو GMDI_GOINTOPOPUPS 0x0002L

  WINUSERAPI UINT WINAPI Get_Menu_Default_شے(HMENU hMenu,UINT fByPos,UINT gmdiFlags);
  WINUSERAPI WINBOOL WINAPI سیٹ_Menu_Default_شے(HMENU hMenu,UINT u_شے,UINT fByPos);
  WINUSERAPI WINBOOL WINAPI Get_Menu_شے_Rect(HWND hWnd,HMENU hMenu,UINT u_شے,LPRECT lprc_شے);
  WINUSERAPI صحيح WINAPI Menu_شے_From_نقطہ(HWND hWnd,HMENU hMenu,نقطہ_3 ptScreen);

#تعریف_کرو TPM_LEFTBUTTON 0x0000L
#تعریف_کرو TPM_RIGHTBUTTON 0x0002L
#تعریف_کرو TPM_LEFTALIGN 0x0000L
#تعریف_کرو TPM_CENTERALIGN 0x0004L
#تعریف_کرو TPM_RIGHTALIGN 0x0008L
#تعریف_کرو TPM_TOPALIGN 0x0000L
#تعریف_کرو TPM_VCENTERALIGN 0x0010L
#تعریف_کرو TPM_BOTTOMALIGN 0x0020L

#تعریف_کرو TPM_HORIZONTAL 0x0000L
#تعریف_کرو TPM_VERTICAL 0x0040L
#تعریف_کرو TPM_NONOTIFY 0x0080L
#تعریف_کرو TPM_RETURNCMD 0x0100L
#تعریف_کرو TPM_RECURSE 0x0001L
#تعریف_کرو TPM_HORPOSANIMATION 0x0400L
#تعریف_کرو TPM_HORNEGANIMATION 0x0800L
#تعریف_کرو TPM_VERPOSANIMATION 0x1000L
#تعریف_کرو TPM_VERNEGANIMATION 0x2000L
#تعریف_کرو TPM_NOANIMATION 0x4000L
#تعریف_کرو TPM_LAYOUTRTL 0x8000L
#جے_انت

  تعريفنوع بنية ٹیگ_DROPSTRUCT {
    HWND hwnd_سروت;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dw_انکڑے;
    نقطہ_3 ptDrop;
    DWORD dw_Control_انکڑے;
  } DROPSTRUCT,*PDROPSTRUCT,*LPDROPSTRUCT;

#تعریف_کرو DOF_EXECUTABLE 0x8001
#تعریف_کرو DOF_DOCUMENT 0x8002
#تعریف_کرو DOF_DIRECTORY 0x8003
#تعریف_کرو DOF_مضرب 0x8004
#تعریف_کرو DOF_PROGMAN 0x0001
#تعریف_کرو DOF_SHELLDATA 0x0002

#تعریف_کرو DO_DROPFILE 0x454C4946L
#تعریف_کرو DO_PRINTFILE 0x544E5250L

  WINUSERAPI DWORD WINAPI DragObject(HWND hwnd_ماپا_2,HWND hwndFrom,UINT fmt,ULONG_PTR انکڑے,HCURSOR hcur);
  WINUSERAPI WINBOOL WINAPI DragDetect(HWND hwnd,نقطہ_3 pt);
  WINUSERAPI WINBOOL WINAPI DrawIcon(HDC hDC,صحيح X,صحيح Y,HICON hIcon);

#جے_بنا_تعریف NODRAWTEXT

#تعریف_کرو DT_چوٹی 0x00000000
#تعریف_کرو DT_بایاں 0x00000000
#تعریف_کرو DT_CENTER 0x00000001
#تعریف_کرو DT_دایاں 0x00000002
#تعریف_کرو DT_VCENTER 0x00000004
#تعریف_کرو DT_BOTTOM 0x00000008
#تعریف_کرو DT_WORDBREAK 0x00000010
#تعریف_کرو DT_SINGLELINE 0x00000020
#تعریف_کرو DT_EXPANDTABS 0x00000040
#تعریف_کرو DT_TABSTOP 0x00000080
#تعریف_کرو DT_NOCLIP 0x00000100
#تعریف_کرو DT_EXTERNALLEADING 0x00000200
#تعریف_کرو DT_CALCRECT 0x00000400
#تعریف_کرو DT_NOPREFIX 0x00000800
#تعریف_کرو DT_اندرونی 0x00001000

#تعریف_کرو DT_EDITCONTROL 0x00002000
#تعریف_کرو DT_رستہ_ELLIPSIS 0x00004000
#تعریف_کرو DT_سرا_ELLIPSIS 0x00008000
#تعریف_کرو DT_MODIFYSTRING 0x00010000
#تعریف_کرو DT_RTLREADING 0x00020000
#تعریف_کرو DT_لفظ_ELLIPSIS 0x00040000
#تعریف_کرو DT_NOFULLWIDTHCHARBREAK 0x00080000
#تعریف_کرو DT_HIDEPREFIX 0x00100000
#تعریف_کرو DT_PREFIXONLY 0x00200000

  تعريفنوع بنية ٹیگ_DRAWTEXTPARAMS {
    UINT cb_ناپ;
    صحيح i_Tab_لمائی;
    صحيح i_بایاں_Margin;
    صحيح i_دایاں_Margin;
    UINT ui_لمائی_Drawn;
  } DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Draw_متن Draw_متن_W
#تعریف_کرو Draw_متن_Ex Draw_متن_Ex_W
#وإلا
#تعریف_کرو Draw_متن Draw_متن_A
#تعریف_کرو Draw_متن_Ex Draw_متن_Ex_A
#جے_انت

  WINUSERAPI صحيح WINAPI Draw_متن_A(HDC hdc,LPCSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format);
  WINUSERAPI صحيح WINAPI Draw_متن_W(HDC hdc,LPCWSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format);
  WINUSERAPI صحيح WINAPI Draw_متن_Ex_A(HDC hdc,LPSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
  WINUSERAPI صحيح WINAPI Draw_متن_Ex_W(HDC hdc,LPWSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو سلیٹی_String سلیٹی_String_W
#تعریف_کرو DrawState DrawStateW
#تعریف_کرو Tabbed_متن_باہرلا Tabbed_متن_باہرلا_W
#تعریف_کرو Get_Tabbed_متن_Extent Get_Tabbed_متن_Extent_W
#وإلا
#تعریف_کرو سلیٹی_String سلیٹی_String_A
#تعریف_کرو DrawState DrawStateA
#تعریف_کرو Tabbed_متن_باہرلا Tabbed_متن_باہرلا_A
#تعریف_کرو Get_Tabbed_متن_Extent Get_Tabbed_متن_Extent_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI سلیٹی_String_A(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_انکڑے,صحيح n_گنتی,صحيح X,صحيح Y,صحيح n_چوڑائی,صحيح n_اچائی);
  WINUSERAPI WINBOOL WINAPI سلیٹی_String_W(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_انکڑے,صحيح n_گنتی,صحيح X,صحيح Y,صحيح n_چوڑائی,صحيح n_اچائی);

#تعریف_کرو DST_COMPLEX 0x0000
#تعریف_کرو DST_متن 0x0001
#تعریف_کرو DST_PREFIXTEXT 0x0002
#تعریف_کرو DST_ICON 0x0003
#تعریف_کرو DST_BITMAP 0x0004

#تعریف_کرو DSS_عام 0x0000
#تعریف_کرو DSS_UNION 0x0010
#تعریف_کرو DSS_DISABLED 0x0020
#تعریف_کرو DSS_MONO 0x0080
#تعریف_کرو DSS_HIDEPREFIX 0x0200
#تعریف_کرو DSS_PREFIXONLY 0x0400
#تعریف_کرو DSS_دایاں 0x8000

  WINUSERAPI WINBOOL WINAPI DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_پٹھ,LPARAM l_انکڑے,WPARAM w_انکڑے,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_پٹھ,LPARAM l_انکڑے,WPARAM w_انکڑے,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI LONG WINAPI Tabbed_متن_باہرلا_A(HDC hdc,صحيح x,صحيح y,LPCSTR lpString,صحيح ch_گنتی,صحيح nTabPositions,CONST INT *lpnTabStopPositions,صحيح nTabOrigin);
  WINUSERAPI LONG WINAPI Tabbed_متن_باہرلا_W(HDC hdc,صحيح x,صحيح y,LPCWSTR lpString,صحيح ch_گنتی,صحيح nTabPositions,CONST INT *lpnTabStopPositions,صحيح nTabOrigin);
  WINUSERAPI DWORD WINAPI Get_Tabbed_متن_Extent_A(HDC hdc,LPCSTR lpString,صحيح ch_گنتی,صحيح nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI DWORD WINAPI Get_Tabbed_متن_Extent_W(HDC hdc,LPCWSTR lpString,صحيح ch_گنتی,صحيح nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI WINBOOL WINAPI Update_کھڑکی(HWND hWnd);
  WINUSERAPI HWND WINAPI سیٹ_سرگرم_کھڑکی(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_Foreground_کھڑکی(VOID);
  WINUSERAPI WINBOOL WINAPI PaintDesktop(HDC hdc);
  WINUSERAPI VOID WINAPI Switch_منزل_This_کھڑکی(HWND hwnd,WINBOOL fUnknown);
  WINUSERAPI WINBOOL WINAPI سیٹ_Foreground_کھڑکی(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Allow_سیٹ_Foreground_کھڑکی(DWORD dwProcessId);

#تعریف_کرو ASFW_ANY ((DWORD)-1)

  WINUSERAPI WINBOOL WINAPI جندرا_سیٹ_Foreground_کھڑکی(UINT u_جندرا_کوڈ);

#تعریف_کرو LSFW_جندرا 1
#تعریف_کرو LSFW_UNLOCK 2

  WINUSERAPI HWND WINAPI کھڑکی_From_DC(HDC hDC);
  WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
  WINUSERAPI HDC WINAPI GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags);

#تعریف_کرو DCX_کھڑکی 0x00000001L
#تعریف_کرو DCX_CACHE 0x00000002L
#تعریف_کرو DCX_NORESETATTRS 0x00000004L
#تعریف_کرو DCX_CLIPCHILDREN 0x00000008L
#تعریف_کرو DCX_CLIPSIBLINGS 0x00000010L
#تعریف_کرو DCX_PARENTCLIP 0x00000020L
#تعریف_کرو DCX_EXCLUDERGN 0x00000040L
#تعریف_کرو DCX_INTERSECTRGN 0x00000080L
#تعریف_کرو DCX_EXCLUDEUPDATE 0x00000100L
#تعریف_کرو DCX_INTERSECTUPDATE 0x00000200L
#تعریف_کرو DCX_LOCKWINDOWUPDATE 0x00000400L

#تعریف_کرو DCX_VALIDATE 0x00200000L

  WINUSERAPI HDC WINAPI Get_کھڑکی_DC(HWND hWnd);
  WINUSERAPI صحيح WINAPI ReleaseDC(HWND hWnd,HDC hDC);
  WINUSERAPI HDC WINAPI BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
  WINUSERAPI WINBOOL WINAPI سرا_Paint(HWND hWnd,CONST PAINTSTRUCT *lpPaint);
  WINUSERAPI WINBOOL WINAPI GetUpdateRect(HWND hWnd,LPRECT lpRect,WINBOOL bErase);
  WINUSERAPI صحيح WINAPI GetUpdateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI صحيح WINAPI سیٹ_کھڑکی_Rgn(HWND hWnd,HRGN hRgn,WINBOOL bRedraw);
  WINUSERAPI صحيح WINAPI Get_کھڑکی_Rgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI صحيح WINAPI Get_کھڑکی_Rgn_Box(HWND hWnd,LPRECT lprc);
  WINUSERAPI صحيح WINAPI ExcludeUpdateRgn(HDC hDC,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI InvalidateRect(HWND hWnd,CONST RECT *lpRect,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRect(HWND hWnd,CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI InvalidateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI WINBOOL WINAPI Redraw_کھڑکی(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#تعریف_کرو RDW_INVALIDATE 0x0001
#تعریف_کرو RDW_INTERNALPAINT 0x0002
#تعریف_کرو RDW_ERASE 0x0004

#تعریف_کرو RDW_VALIDATE 0x0008
#تعریف_کرو RDW_NOINTERNALPAINT 0x0010
#تعریف_کرو RDW_NOERASE 0x0020

#تعریف_کرو RDW_NOCHILDREN 0x0040
#تعریف_کرو RDW_ALLCHILDREN 0x0080

#تعریف_کرو RDW_UPDATENOW 0x0100
#تعریف_کرو RDW_ERASENOW 0x0200

#تعریف_کرو RDW_چوکھٹا 0x0400
#تعریف_کرو RDW_NOFRAME 0x0800

  WINUSERAPI WINBOOL WINAPI جندرا_کھڑکی_Update(HWND h_Wnd_جندرا);
  WINUSERAPI WINBOOL WINAPI Scroll_کھڑکی(HWND hWnd,صحيح XAmount,صحيح YAmount,CONST RECT *lpRect,CONST RECT *lpClipRect);
  WINUSERAPI WINBOOL WINAPI ScrollDC(HDC hDC,صحيح dx,صحيح dy,CONST RECT *lprcScroll,CONST RECT *lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
  WINUSERAPI صحيح WINAPI Scroll_کھڑکی_Ex(HWND hWnd,صحيح dx,صحيح dy,CONST RECT *prcScroll,CONST RECT *prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);

#تعریف_کرو SW_SCROLLCHILDREN 0x0001
#تعریف_کرو SW_INVALIDATE 0x0002
#تعریف_کرو SW_ERASE 0x0004
#تعریف_کرو SW_SMOOTHSCROLL 0x0010

#جے_بنا_تعریف NOSCROLL
  WINUSERAPI صحيح WINAPI سیٹ_Scroll_Pos(HWND hWnd,صحيح nBar,صحيح nPos,WINBOOL bRedraw);
  WINUSERAPI صحيح WINAPI GetScrollPos(HWND hWnd,صحيح nBar);
  WINUSERAPI WINBOOL WINAPI سیٹ_Scroll_Range(HWND hWnd,صحيح nBar,صحيح nMinPos,صحيح nMaxPos,WINBOOL bRedraw);
  WINUSERAPI WINBOOL WINAPI GetScrollRange(HWND hWnd,صحيح nBar,LPINT lpMinPos,LPINT lpMaxPos);
  WINUSERAPI WINBOOL WINAPI ShowScrollBar(HWND hWnd,صحيح wBar,WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows);

#تعریف_کرو ESB_ENABLE_BOTH 0x0000
#تعریف_کرو ESB_DISABLE_BOTH 0x0003

#تعریف_کرو ESB_DISABLE_بایاں 0x0001
#تعریف_کرو ESB_DISABLE_دایاں 0x0002

#تعریف_کرو ESB_DISABLE_اتے 0x0001
#تعریف_کرو ESB_DISABLE_تھلے 0x0002

#تعریف_کرو ESB_DISABLE_LTUP ESB_DISABLE_بایاں
#تعریف_کرو ESB_DISABLE_RTDN ESB_DISABLE_دایاں
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو سیٹ_Prop سیٹ_Prop_W
#تعریف_کرو GetProp GetPropW
#تعریف_کرو RemoveProp RemovePropW
#تعریف_کرو EnumPropsEx EnumPropsExW
#تعریف_کرو EnumProps EnumPropsW
#تعریف_کرو سیٹ_کھڑکی_متن سیٹ_کھڑکی_متن_W
#تعریف_کرو Get_کھڑکی_متن Get_کھڑکی_متن_W
#تعریف_کرو Get_کھڑکی_متن_لمائی Get_کھڑکی_متن_لمائی_W
#وإلا
#تعریف_کرو سیٹ_Prop سیٹ_Prop_A
#تعریف_کرو GetProp GetPropA
#تعریف_کرو RemoveProp RemovePropA
#تعریف_کرو EnumPropsEx EnumPropsExA
#تعریف_کرو EnumProps EnumPropsA
#تعریف_کرو سیٹ_کھڑکی_متن سیٹ_کھڑکی_متن_A
#تعریف_کرو Get_کھڑکی_متن Get_کھڑکی_متن_A
#تعریف_کرو Get_کھڑکی_متن_لمائی Get_کھڑکی_متن_لمائی_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI سیٹ_Prop_A(HWND hWnd,LPCSTR lpString,HANDLE h_انکڑے);
  WINUSERAPI WINBOOL WINAPI سیٹ_Prop_W(HWND hWnd,LPCWSTR lpString,HANDLE h_انکڑے);
  WINUSERAPI HANDLE WINAPI GetPropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI GetPropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI صحيح WINAPI EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
  WINUSERAPI صحيح WINAPI EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
  WINUSERAPI صحيح WINAPI EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc);
  WINUSERAPI صحيح WINAPI EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc);
  WINUSERAPI WINBOOL WINAPI سیٹ_کھڑکی_متن_A(HWND hWnd,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI سیٹ_کھڑکی_متن_W(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI صحيح WINAPI Get_کھڑکی_متن_A(HWND hWnd,LPSTR lpString,صحيح n_Max_گنتی);
  WINUSERAPI صحيح WINAPI Get_کھڑکی_متن_W(HWND hWnd,LPWSTR lpString,صحيح n_Max_گنتی);
  WINUSERAPI صحيح WINAPI Get_کھڑکی_متن_لمائی_A(HWND hWnd);
  WINUSERAPI صحيح WINAPI Get_کھڑکی_متن_لمائی_W(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI GetClientRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Get_کھڑکی_Rect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Adjust_کھڑکی_Rect(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu);
  WINUSERAPI WINBOOL WINAPI Adjust_کھڑکی_Rect_Ex(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu,DWORD dwExStyle);

#تعریف_کرو HELPINFO_کھڑکی 0x0001
#تعریف_کرو HELPINFO_MENUITEM 0x0002

  تعريفنوع بنية ٹیگ_HELPINFO {
    UINT cb_ناپ;
    صحيح iContextType;
    صحيح iCtrlId;
    HANDLE h_شے_Handle;
    DWORD_PTR dwContextId;
    نقطہ_3 MousePos;
  } HELPINFO,*LPHELPINFO;

  WINUSERAPI WINBOOL WINAPI سیٹ_کھڑکی_Context_Help_Id(HWND,DWORD);
  WINUSERAPI DWORD WINAPI Get_کھڑکی_Context_Help_Id(HWND);
  WINUSERAPI WINBOOL WINAPI سیٹ_Menu_Context_Help_Id(HMENU,DWORD);
  WINUSERAPI DWORD WINAPI GetMenuContextHelpId(HMENU);

#جے_بنا_تعریف NOMB

#تعریف_کرو MB_OK 0x00000000L
#تعریف_کرو MB_OKCANCEL 0x00000001L
#تعریف_کرو MB_ABORTRETRYIGNORE 0x00000002L
#تعریف_کرو MB_YESNOCANCEL 0x00000003L
#تعریف_کرو MB_YESNO 0x00000004L
#تعریف_کرو MB_RETRYCANCEL 0x00000005L
#تعریف_کرو MB_CANCELTRYCONTINUE 0x00000006L
#تعریف_کرو MB_ICONHAND 0x00000010L
#تعریف_کرو MB_ICONQUESTION 0x00000020L
#تعریف_کرو MB_ICONEXCLAMATION 0x00000030L
#تعریف_کرو MB_ICONASTERISK 0x00000040L
#تعریف_کرو MB_USERICON 0x00000080L
#تعریف_کرو MB_ICONWARNING MB_ICONEXCLAMATION
#تعریف_کرو MB_ICONERROR MB_ICONHAND
#تعریف_کرو MB_ICONINFORMATION MB_ICONASTERISK
#تعریف_کرو MB_ICONSTOP MB_ICONHAND
#تعریف_کرو MB_DEFBUTTON1 0x00000000L
#تعریف_کرو MB_DEFBUTTON2 0x00000100L
#تعریف_کرو MB_DEFBUTTON3 0x00000200L
#تعریف_کرو MB_DEFBUTTON4 0x00000300L
#تعریف_کرو MB_APPLMODAL 0x00000000L
#تعریف_کرو MB_SYSTEMMODAL 0x00001000L
#تعریف_کرو MB_TASKMODAL 0x00002000L
#تعریف_کرو MB_HELP 0x00004000L
#تعریف_کرو MB_NOFOCUS 0x00008000L
#تعریف_کرو MB_SETFOREGROUND 0x00010000L
#تعریف_کرو MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#تعریف_کرو MB_TOPMOST 0x00040000L
#تعریف_کرو MB_دایاں 0x00080000L
#تعریف_کرو MB_RTLREADING 0x00100000L
#تعریف_کرو MB_SERVICE_NOTIFICATION 0x00200000L
#تعریف_کرو MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#تعریف_کرو MB_TYPEMASK 0x0000000FL
#تعریف_کرو MB_ICONMASK 0x000000F0L
#تعریف_کرو MB_DEFMASK 0x00000F00L
#تعریف_کرو MB_MODEMASK 0x00003000L
#تعریف_کرو MB_MISCMASK 0x0000C000L

#جے_تعریف_شدہ UNICODE
#تعریف_کرو سنیہا_Box سنیہا_Box_W
#تعریف_کرو سنیہا_Box_Ex سنیہا_Box_Ex_W
#وإلا
#تعریف_کرو سنیہا_Box سنیہا_Box_A
#تعریف_کرو سنیہا_Box_Ex سنیہا_Box_Ex_A
#جے_انت

  WINUSERAPI صحيح WINAPI سنیہا_Box_A(HWND hWnd,LPCSTR lp_متن,LPCSTR lpCaption,UINT uType);
  WINUSERAPI صحيح WINAPI سنیہا_Box_W(HWND hWnd,LPCWSTR lp_متن,LPCWSTR lpCaption,UINT uType);
  WINUSERAPI صحيح WINAPI سنیہا_Box_Ex_A(HWND hWnd,LPCSTR lp_متن,LPCSTR lpCaption,UINT uType,لفظ_3 wLanguageId);
  WINUSERAPI صحيح WINAPI سنیہا_Box_Ex_W(HWND hWnd,LPCWSTR lp_متن,LPCWSTR lpCaption,UINT uType,لفظ_3 wLanguageId);

  تعريفنوع VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

  تعريفنوع بنية ٹیگ_MSGBOXPARAMSA {
    UINT cb_ناپ;
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

  تعريفنوع بنية ٹیگ_MSGBOXPARAMSW {
    UINT cb_ناپ;
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

#جے_تعریف_شدہ UNICODE
  تعريفنوع MSGBOXPARAMSW MSGBOXPARAMS;
  تعريفنوع PMSGBOXPARAMSW PMSGBOXPARAMS;
  تعريفنوع LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#وإلا
  تعريفنوع MSGBOXPARAMSA MSGBOXPARAMS;
  تعريفنوع PMSGBOXPARAMSA PMSGBOXPARAMS;
  تعريفنوع LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو سنیہا_Box_اسدھا سنیہا_Box_اسدھا_W
#وإلا
#تعریف_کرو سنیہا_Box_اسدھا سنیہا_Box_اسدھا_A
#جے_انت

  WINUSERAPI صحيح WINAPI سنیہا_Box_اسدھا_A(CONST MSGBOXPARAMSA *lpmbp);
  WINUSERAPI صحيح WINAPI سنیہا_Box_اسدھا_W(CONST MSGBOXPARAMSW *lpmbp);
  WINUSERAPI WINBOOL WINAPI سنیہا_Beep(UINT uType);
#جے_انت

  WINUSERAPI صحيح WINAPI ShowCursor(WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI سیٹ_Cursor_Pos(صحيح X,صحيح Y);
  WINUSERAPI HCURSOR WINAPI سیٹ_Cursor(HCURSOR hCursor);
  WINUSERAPI WINBOOL WINAPI GetCursorPos(LPPOINT lp_نقطہ);
  WINUSERAPI WINBOOL WINAPI ClipCursor(CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI GetClipCursor(LPRECT lpRect);
  WINUSERAPI HCURSOR WINAPI GetCursor(VOID);
  WINUSERAPI WINBOOL WINAPI CreateCaret(HWND hWnd,HBITMAP hBitmap,صحيح n_چوڑائی,صحيح n_اچائی);
  WINUSERAPI UINT WINAPI Get_Caret_Blink_ویلا(VOID);
  WINUSERAPI WINBOOL WINAPI سیٹ_Caret_Blink_ویلا(UINT uMSeconds);
  WINUSERAPI WINBOOL WINAPI DestroyCaret(VOID);
  WINUSERAPI WINBOOL WINAPI HideCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI سیٹ_Caret_Pos(صحيح X,صحيح Y);
  WINUSERAPI WINBOOL WINAPI GetCaretPos(LPPOINT lp_نقطہ);
  WINUSERAPI WINBOOL WINAPI Client_منزل_Screen(HWND hWnd,LPPOINT lp_نقطہ);
  WINUSERAPI WINBOOL WINAPI Screen_منزل_Client(HWND hWnd,LPPOINT lp_نقطہ);
  WINUSERAPI صحيح WINAPI Map_کھڑکی_Points(HWND hWndFrom,HWND h_Wnd_منزل,LPPOINT lpPoints,UINT cPoints);
  WINUSERAPI HWND WINAPI کھڑکی_From_نقطہ(نقطہ_3 نقطہ_2);
  WINUSERAPI HWND WINAPI بچہ_کھڑکی_From_نقطہ(HWND h_Wnd_ماپا,نقطہ_3 نقطہ_2);

#تعریف_کرو CWP_ALL 0x0000
#تعریف_کرو CWP_SKIPINVISIBLE 0x0001
#تعریف_کرو CWP_SKIPDISABLED 0x0002
#تعریف_کرو CWP_SKIPTRANSPARENT 0x0004

  WINUSERAPI HWND WINAPI بچہ_کھڑکی_From_نقطہ_Ex(HWND hwnd,نقطہ_3 pt,UINT flags);

#جے_بنا_تعریف NOCOLOR

#تعریف_کرو CTLCOLOR_MSGBOX 0
#تعریف_کرو CTLCOLOR_EDIT 1
#تعریف_کرو CTLCOLOR_LISTBOX 2
#تعریف_کرو CTLCOLOR_BTN 3
#تعریف_کرو CTLCOLOR_DLG 4
#تعریف_کرو CTLCOLOR_SCROLLBAR 5
#تعریف_کرو CTLCOLOR_STATIC 6
#تعریف_کرو CTLCOLOR_MAX 7

#تعریف_کرو COLOR_SCROLLBAR 0
#تعریف_کرو COLOR_BACKGROUND 1
#تعریف_کرو COLOR_ACTIVECAPTION 2
#تعریف_کرو COLOR_INACTIVECAPTION 3
#تعریف_کرو COLOR_MENU 4
#تعریف_کرو COLOR_کھڑکی 5
#تعریف_کرو COLOR_WINDOWFRAME 6
#تعریف_کرو COLOR_MENUTEXT 7
#تعریف_کرو COLOR_WINDOWTEXT 8
#تعریف_کرو COLOR_CAPTIONTEXT 9
#تعریف_کرو COLOR_ACTIVEBORDER 10
#تعریف_کرو COLOR_INACTIVEBORDER 11
#تعریف_کرو COLOR_APPWORKSPACE 12
#تعریف_کرو COLOR_HIGHLIGHT 13
#تعریف_کرو COLOR_HIGHLIGHTTEXT 14
#تعریف_کرو COLOR_BTNFACE 15
#تعریف_کرو COLOR_BTNSHADOW 16
#تعریف_کرو COLOR_GRAYTEXT 17
#تعریف_کرو COLOR_BTNTEXT 18
#تعریف_کرو COLOR_INACTIVECAPTIONTEXT 19
#تعریف_کرو COLOR_BTNHIGHLIGHT 20

#تعریف_کرو COLOR_3DDKSHADOW 21
#تعریف_کرو COLOR_3DLIGHT 22
#تعریف_کرو COLOR_INFOTEXT 23
#تعریف_کرو COLOR_INFOBK 24

#تعریف_کرو COLOR_HOTLIGHT 26
#تعریف_کرو COLOR_GRADIENTACTIVECAPTION 27
#تعریف_کرو COLOR_GRADIENTINACTIVECAPTION 28
#تعریف_کرو COLOR_MENUHILIGHT 29
#تعریف_کرو COLOR_MENUBAR 30

#تعریف_کرو COLOR_DESKTOP COLOR_BACKGROUND
#تعریف_کرو COLOR_3DFACE COLOR_BTNFACE
#تعریف_کرو COLOR_3DSHADOW COLOR_BTNSHADOW
#تعریف_کرو COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#تعریف_کرو COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#تعریف_کرو COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

  WINUSERAPI DWORD WINAPI GetSysColor(صحيح n_اشاریہ);
  WINUSERAPI HBRUSH WINAPI GetSysColorBrush(صحيح n_اشاریہ);
  WINUSERAPI WINBOOL WINAPI سیٹ_Sys_Colors(صحيح cElements,CONST INT *lpaElements,CONST COLORREF *lpa_Rgb_اقدار);
#جے_انت

  WINUSERAPI WINBOOL WINAPI DrawFocusRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI صحيح WINAPI FillRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI صحيح WINAPI چوکھٹا_Rect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI WINBOOL WINAPI InvertRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI سیٹ_Rect(LPRECT lprc,صحيح x_بایاں,صحيح y_چوٹی,صحيح x_دایاں,صحيح yBottom);
  WINUSERAPI WINBOOL WINAPI سیٹ_Rect_خالی_تھاواں(LPRECT lprc);
  WINUSERAPI WINBOOL WINAPI CopyRect(LPRECT lprcDst,CONST RECT *lprcSrc);
  WINUSERAPI WINBOOL WINAPI InflateRect(LPRECT lprc,صحيح dx,صحيح dy);
  WINUSERAPI WINBOOL WINAPI IntersectRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI UnionRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI گھٹاؤ_Rect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI وتھ_Rect(LPRECT lprc,صحيح dx,صحيح dy);
  WINUSERAPI WINBOOL WINAPI Is_Rect_خالی_تھاواں(CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI EqualRect(CONST RECT *lprc1,CONST RECT *lprc2);
  WINUSERAPI WINBOOL WINAPI Pt_وچ_Rect(CONST RECT *lprc,نقطہ_3 pt);

#جے_بنا_تعریف NOWINOFFSETS

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_کھڑکی_Long Get_کھڑکی_Long_W
#تعریف_کرو سیٹ_کھڑکی_Long سیٹ_کھڑکی_Long_W
#وإلا
#تعریف_کرو Get_کھڑکی_Long Get_کھڑکی_Long_A
#تعریف_کرو سیٹ_کھڑکی_Long سیٹ_کھڑکی_Long_A
#جے_انت

  WINUSERAPI لفظ_3 WINAPI Get_کھڑکی_لفظ(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI لفظ_3 WINAPI سیٹ_کھڑکی_لفظ(HWND hWnd,صحيح n_اشاریہ,لفظ_3 w_New_لفظ);
  WINUSERAPI LONG WINAPI Get_کھڑکی_Long_A(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI LONG WINAPI Get_کھڑکی_Long_W(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI LONG WINAPI سیٹ_کھڑکی_Long_A(HWND hWnd,صحيح n_اشاریہ,LONG dwNewLong);
  WINUSERAPI LONG WINAPI سیٹ_کھڑکی_Long_W(HWND hWnd,صحيح n_اشاریہ,LONG dwNewLong);

#جے_تعریف_شدہ _WIN64

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_کھڑکی_Long_Ptr Get_کھڑکی_Long_Ptr_W
#تعریف_کرو سیٹ_کھڑکی_Long_Ptr سیٹ_کھڑکی_Long_Ptr_W
#وإلا
#تعریف_کرو Get_کھڑکی_Long_Ptr Get_کھڑکی_Long_Ptr_A
#تعریف_کرو سیٹ_کھڑکی_Long_Ptr سیٹ_کھڑکی_Long_Ptr_A
#جے_انت

  WINUSERAPI LONG_PTR WINAPI Get_کھڑکی_Long_Ptr_A(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI LONG_PTR WINAPI Get_کھڑکی_Long_Ptr_W(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI LONG_PTR WINAPI سیٹ_کھڑکی_Long_Ptr_A(HWND hWnd,صحيح n_اشاریہ,LONG_PTR dwNewLong);
  WINUSERAPI LONG_PTR WINAPI سیٹ_کھڑکی_Long_Ptr_W(HWND hWnd,صحيح n_اشاریہ,LONG_PTR dwNewLong);
#وإلا

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_کھڑکی_Long_Ptr Get_کھڑکی_Long_Ptr_W
#تعریف_کرو سیٹ_کھڑکی_Long_Ptr سیٹ_کھڑکی_Long_Ptr_W
#وإلا
#تعریف_کرو Get_کھڑکی_Long_Ptr Get_کھڑکی_Long_Ptr_A
#تعریف_کرو سیٹ_کھڑکی_Long_Ptr سیٹ_کھڑکی_Long_Ptr_A
#جے_انت

#تعریف_کرو Get_کھڑکی_Long_Ptr_A Get_کھڑکی_Long_A
#تعریف_کرو Get_کھڑکی_Long_Ptr_W Get_کھڑکی_Long_W
#تعریف_کرو سیٹ_کھڑکی_Long_Ptr_A سیٹ_کھڑکی_Long_A
#تعریف_کرو سیٹ_کھڑکی_Long_Ptr_W سیٹ_کھڑکی_Long_W
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو GetClassLong GetClassLongW
#تعریف_کرو سیٹ_Class_Long سیٹ_Class_Long_W
#وإلا
#تعریف_کرو GetClassLong GetClassLongA
#تعریف_کرو سیٹ_Class_Long سیٹ_Class_Long_A
#جے_انت

  WINUSERAPI لفظ_3 WINAPI Get_Class_لفظ(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI لفظ_3 WINAPI سیٹ_Class_لفظ(HWND hWnd,صحيح n_اشاریہ,لفظ_3 w_New_لفظ);
  WINUSERAPI DWORD WINAPI GetClassLongA(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI DWORD WINAPI GetClassLongW(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI DWORD WINAPI سیٹ_Class_Long_A(HWND hWnd,صحيح n_اشاریہ,LONG dwNewLong);
  WINUSERAPI DWORD WINAPI سیٹ_Class_Long_W(HWND hWnd,صحيح n_اشاریہ,LONG dwNewLong);

#جے_تعریف_شدہ _WIN64

#جے_تعریف_شدہ UNICODE
#تعریف_کرو GetClassLongPtr GetClassLongPtrW
#تعریف_کرو سیٹ_Class_Long_Ptr سیٹ_Class_Long_Ptr_W
#وإلا
#تعریف_کرو GetClassLongPtr GetClassLongPtrA
#تعریف_کرو سیٹ_Class_Long_Ptr سیٹ_Class_Long_Ptr_A
#جے_انت

  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd,صحيح n_اشاریہ);
  WINUSERAPI ULONG_PTR WINAPI سیٹ_Class_Long_Ptr_A(HWND hWnd,صحيح n_اشاریہ,LONG_PTR dwNewLong);
  WINUSERAPI ULONG_PTR WINAPI سیٹ_Class_Long_Ptr_W(HWND hWnd,صحيح n_اشاریہ,LONG_PTR dwNewLong);
#وإلا
#جے_تعریف_شدہ UNICODE
#تعریف_کرو GetClassLongPtr GetClassLongPtrW
#تعریف_کرو سیٹ_Class_Long_Ptr سیٹ_Class_Long_Ptr_W
#وإلا
#تعریف_کرو GetClassLongPtr GetClassLongPtrA
#تعریف_کرو سیٹ_Class_Long_Ptr سیٹ_Class_Long_Ptr_A
#جے_انت

#تعریف_کرو GetClassLongPtrA GetClassLongA
#تعریف_کرو GetClassLongPtrW GetClassLongW
#تعریف_کرو سیٹ_Class_Long_Ptr_A سیٹ_Class_Long_A
#تعریف_کرو سیٹ_Class_Long_Ptr_W سیٹ_Class_Long_W
#جے_انت
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو لبھو_کھڑکی لبھو_کھڑکی_W
#تعریف_کرو لبھو_کھڑکی_Ex لبھو_کھڑکی_Ex_W
#تعریف_کرو GetClassName GetClassNameW
#وإلا
#تعریف_کرو لبھو_کھڑکی لبھو_کھڑکی_A
#تعریف_کرو لبھو_کھڑکی_Ex لبھو_کھڑکی_Ex_A
#تعریف_کرو GetClassName GetClassNameA
#جے_انت

  WINUSERAPI WINBOOL WINAPI GetProcessDefaultLayout(DWORD *pdwDefaultLayout);
  WINUSERAPI WINBOOL WINAPI سیٹ_Process_Default_Layout(DWORD dwDefaultLayout);
  WINUSERAPI HWND WINAPI Get_Desktop_کھڑکی(VOID);
  WINUSERAPI HWND WINAPI Get_ماپا(HWND hWnd);
  WINUSERAPI HWND WINAPI سیٹ_ماپا(HWND h_Wnd_بچہ,HWND h_Wnd_New_ماپا);
  WINUSERAPI WINBOOL WINAPI Enum_بچہ_Windows(HWND h_Wnd_ماپا,WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI HWND WINAPI لبھو_کھڑکی_A(LPCSTR lpClassName,LPCSTR lp_کھڑکی_Name);
  WINUSERAPI HWND WINAPI لبھو_کھڑکی_W(LPCWSTR lpClassName,LPCWSTR lp_کھڑکی_Name);
  WINUSERAPI HWND WINAPI لبھو_کھڑکی_Ex_A(HWND h_Wnd_ماپا,HWND h_Wnd_بچہ_After,LPCSTR lpszClass,LPCSTR lpsz_کھڑکی);
  WINUSERAPI HWND WINAPI لبھو_کھڑکی_Ex_W(HWND h_Wnd_ماپا,HWND h_Wnd_بچہ_After,LPCWSTR lpszClass,LPCWSTR lpsz_کھڑکی);
  WINUSERAPI HWND WINAPI Get_Shell_کھڑکی(VOID);
  WINUSERAPI WINBOOL WINAPI رجسٹر_Shell_Hook_کھڑکی(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI Deregister_Shell_Hook_کھڑکی(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);

#تعریف_کرو EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(Handle_منزل_Ulong(hTask),lpfn,lParam)

  WINUSERAPI صحيح WINAPI GetClassNameA(HWND hWnd,LPSTR lpClassName,صحيح n_Max_گنتی);
  WINUSERAPI صحيح WINAPI GetClassNameW(HWND hWnd,LPWSTR lpClassName,صحيح n_Max_گنتی);
  WINUSERAPI HWND WINAPI Get_چوٹی_کھڑکی(HWND hWnd);

#تعریف_کرو Get_اگلا_کھڑکی(hWnd,wCmd) Get_کھڑکی(hWnd,wCmd)
#تعریف_کرو Get_Sys_Modal_کھڑکی() (عدم)
#تعریف_کرو سیٹ_Sys_Modal_کھڑکی(hWnd) (عدم)

  WINUSERAPI DWORD WINAPI Get_کھڑکی_Thread_Process_Id(HWND hWnd,LPDWORD lpdwProcessId);
  WINUSERAPI WINBOOL WINAPI IsGUIThread(WINBOOL bConvert);

#تعریف_کرو Get_کھڑکی_Task(hWnd) ((HANDLE)(DWORD_PTR)Get_کھڑکی_Thread_Process_Id(hWnd,عدم))

  WINUSERAPI HWND WINAPI Get_آخری_سرگرم_Popup(HWND hWnd);

#تعریف_کرو GW_HWNDFIRST 0
#تعریف_کرو GW_HWNDLAST 1
#تعریف_کرو GW_HWNDNEXT 2
#تعریف_کرو GW_HWNDPREV 3
#تعریف_کرو GW_OWNER 4
#تعریف_کرو GW_بچہ 5
#تعریف_کرو GW_ENABLEDPOPUP 6
#تعریف_کرو GW_MAX 6

  WINUSERAPI HWND WINAPI Get_کھڑکی(HWND hWnd,UINT uCmd);

#جے_بنا_تعریف NOWH

#جے_تعریف_شدہ UNICODE
#تعریف_کرو سیٹ_Windows_Hook سیٹ_Windows_Hook_W
#تعریف_کرو سیٹ_Windows_Hook_Ex سیٹ_Windows_Hook_Ex_W
#وإلا
#تعریف_کرو سیٹ_Windows_Hook سیٹ_Windows_Hook_A
#تعریف_کرو سیٹ_Windows_Hook_Ex سیٹ_Windows_Hook_Ex_A
#جے_انت

  WINUSERAPI HHOOK WINAPI سیٹ_Windows_Hook_A(صحيح nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI سیٹ_Windows_Hook_W(صحيح nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHook(صحيح n_کوڈ,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI سیٹ_Windows_Hook_Ex_A(صحيح idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI HHOOK WINAPI سیٹ_Windows_Hook_Ex_W(صحيح idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);
  WINUSERAPI LRESULT WINAPI Call_اگلا_Hook_Ex(HHOOK hhk,صحيح n_کوڈ,WPARAM wParam,LPARAM lParam);
#تعریف_کرو DefHookProc(n_کوڈ,wParam,lParam,phhk) Call_اگلا_Hook_Ex(*phhk,n_کوڈ,wParam,lParam)
#جے_انت

#جے_بنا_تعریف NOMENUS

#تعریف_کرو MF_داخل_کرو 0x00000000L
#تعریف_کرو MF_CHANGE 0x00000080L
#تعریف_کرو MF_APPEND 0x00000100L
#تعریف_کرو MF_DELETE 0x00000200L
#تعریف_کرو MF_REMOVE 0x00001000L
#تعریف_کرو MF_BYCOMMAND 0x00000000L
#تعریف_کرو MF_BYPOSITION 0x00000400L
#تعریف_کرو MF_SEPARATOR 0x00000800L
#تعریف_کرو MF_ENABLED 0x00000000L
#تعریف_کرو MF_GRAYED 0x00000001L
#تعریف_کرو MF_DISABLED 0x00000002L
#تعریف_کرو MF_UNCHECKED 0x00000000L
#تعریف_کرو MF_CHECKED 0x00000008L
#تعریف_کرو MF_USECHECKBITMAPS 0x00000200L
#تعریف_کرو MF_STRING 0x00000000L
#تعریف_کرو MF_BITMAP 0x00000004L
#تعریف_کرو MF_OWNERDRAW 0x00000100L
#تعریف_کرو MF_POPUP 0x00000010L
#تعریف_کرو MF_MENUBARBREAK 0x00000020L
#تعریف_کرو MF_MENUBREAK 0x00000040L
#تعریف_کرو MF_UNHILITE 0x00000000L
#تعریف_کرو MF_HILITE 0x00000080L
#تعریف_کرو MF_DEFAULT 0x00001000L
#تعریف_کرو MF_SYSMENU 0x00002000L
#تعریف_کرو MF_HELP 0x00004000L
#تعریف_کرو MF_RIGHTJUSTIFY 0x00004000L
#تعریف_کرو MF_MOUSESELECT 0x00008000L
#تعریف_کرو MF_سرا 0x00000080L

#تعریف_کرو MFT_STRING MF_STRING
#تعریف_کرو MFT_BITMAP MF_BITMAP
#تعریف_کرو MFT_MENUBARBREAK MF_MENUBARBREAK
#تعریف_کرو MFT_MENUBREAK MF_MENUBREAK
#تعریف_کرو MFT_OWNERDRAW MF_OWNERDRAW
#تعریف_کرو MFT_RADIOCHECK 0x00000200L
#تعریف_کرو MFT_SEPARATOR MF_SEPARATOR
#تعریف_کرو MFT_RIGHTORDER 0x00002000L
#تعریف_کرو MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#تعریف_کرو MFS_GRAYED 0x00000003L
#تعریف_کرو MFS_DISABLED MFS_GRAYED
#تعریف_کرو MFS_CHECKED MF_CHECKED
#تعریف_کرو MFS_HILITE MF_HILITE
#تعریف_کرو MFS_ENABLED MF_ENABLED
#تعریف_کرو MFS_UNCHECKED MF_UNCHECKED
#تعریف_کرو MFS_UNHILITE MF_UNHILITE
#تعریف_کرو MFS_DEFAULT MF_DEFAULT

  WINUSERAPI WINBOOL WINAPI Check_Menu_Radio_شے(HMENU hmenu,UINT پہلا,UINT آخری,UINT check,UINT flags);

  تعريفنوع بنية {
    لفظ_3 نسخہ_نمبر;
    لفظ_3 وتھ;
  } MENUITEMTEMPLATEHEADER,*PMENUITEMTEMPLATEHEADER;

  تعريفنوع بنية {
    لفظ_3 mtOption;
    لفظ_3 mtID;
    WCHAR mtString[1];
  } MENUITEMTEMPLATE,*PMENUITEMTEMPLATE;
#تعریف_کرو MF_سرا 0x00000080L
#جے_انت

#جے_بنا_تعریف NOSYSCOMMANDS

#تعریف_کرو SC_ناپ 0xF000
#تعریف_کرو SC_MOVE 0xF010
#تعریف_کرو SC_MINIMIZE 0xF020
#تعریف_کرو SC_MAXIMIZE 0xF030
#تعریف_کرو SC_NEXTWINDOW 0xF040
#تعریف_کرو SC_PREVWINDOW 0xF050
#تعریف_کرو SC_CLOSE 0xF060
#تعریف_کرو SC_VSCROLL 0xF070
#تعریف_کرو SC_HSCROLL 0xF080
#تعریف_کرو SC_MOUSEMENU 0xF090
#تعریف_کرو SC_KEYMENU 0xF100
#تعریف_کرو SC_ARRANGE 0xF110
#تعریف_کرو SC_RESTORE 0xF120
#تعریف_کرو SC_TASKLIST 0xF130
#تعریف_کرو SC_SCREENSAVE 0xF140
#تعریف_کرو SC_HOTKEY 0xF150
#تعریف_کرو SC_DEFAULT 0xF160
#تعریف_کرو SC_MONITORPOWER 0xF170
#تعریف_کرو SC_CONTEXTHELP 0xF180
#تعریف_کرو SC_SEPARATOR 0xF00F
#تعریف_کرو SC_ICON SC_MINIMIZE
#تعریف_کرو SC_ZOOM SC_MAXIMIZE
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو لدو_Bitmap لدو_Bitmap_W
#تعریف_کرو لدو_Cursor لدو_Cursor_W
#تعریف_کرو لدو_Cursor_From_File لدو_Cursor_From_File_W
#وإلا
#تعریف_کرو لدو_Bitmap لدو_Bitmap_A
#تعریف_کرو لدو_Cursor لدو_Cursor_A
#تعریف_کرو لدو_Cursor_From_File لدو_Cursor_From_File_A
#جے_انت

  WINUSERAPI HBITMAP WINAPI لدو_Bitmap_A(HINSTANCE hInstance,LPCSTR lpBitmapName);
  WINUSERAPI HBITMAP WINAPI لدو_Bitmap_W(HINSTANCE hInstance,LPCWSTR lpBitmapName);
  WINUSERAPI HCURSOR WINAPI لدو_Cursor_A(HINSTANCE hInstance,LPCSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI لدو_Cursor_W(HINSTANCE hInstance,LPCWSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI لدو_Cursor_From_File_A(LPCSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI لدو_Cursor_From_File_W(LPCWSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI CreateCursor(HINSTANCE hInst,صحيح xHotSpot,صحيح yHotSpot,صحيح n_چوڑائی,صحيح n_اچائی,CONST VOID *pvANDPlane,CONST VOID *pvXORPlane);
  WINUSERAPI WINBOOL WINAPI DestroyCursor(HCURSOR hCursor);

#تعریف_کرو CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

#تعریف_کرو IDC_ARROW MAKEINTRESOURCE(32512)
#تعریف_کرو IDC_IBEAM MAKEINTRESOURCE(32513)
#تعریف_کرو IDC_WAIT MAKEINTRESOURCE(32514)
#تعریف_کرو IDC_CROSS MAKEINTRESOURCE(32515)
#تعریف_کرو IDC_UPARROW MAKEINTRESOURCE(32516)
#تعریف_کرو IDC_ناپ MAKEINTRESOURCE(32640)
#تعریف_کرو IDC_ICON MAKEINTRESOURCE(32641)
#تعریف_کرو IDC_SIZENWSE MAKEINTRESOURCE(32642)
#تعریف_کرو IDC_SIZENESW MAKEINTRESOURCE(32643)
#تعریف_کرو IDC_SIZEWE MAKEINTRESOURCE(32644)
#تعریف_کرو IDC_SIZENS MAKEINTRESOURCE(32645)
#تعریف_کرو IDC_SIZEALL MAKEINTRESOURCE(32646)
#تعریف_کرو IDC_NO MAKEINTRESOURCE(32648)
#تعریف_کرو IDC_HAND MAKEINTRESOURCE(32649)
#تعریف_کرو IDC_APPSTARTING MAKEINTRESOURCE(32650)
#تعریف_کرو IDC_HELP MAKEINTRESOURCE(32651)

  WINUSERAPI WINBOOL WINAPI سیٹ_System_Cursor(HCURSOR hcur,DWORD id);

  تعريفنوع بنية _ICONINFO {
    WINBOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbm_نقاب;
    HBITMAP hbmColor;
  } ICONINFO;
  تعريفنوع ICONINFO *PICONINFO;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو لدو_Icon لدو_Icon_W
#تعریف_کرو نجی_کڈھو_Icons نجی_کڈھو_Icons_W
#وإلا
#تعریف_کرو لدو_Icon لدو_Icon_A
#تعریف_کرو نجی_کڈھو_Icons نجی_کڈھو_Icons_A
#جے_انت

  WINUSERAPI HICON WINAPI لدو_Icon_A(HINSTANCE hInstance,LPCSTR lpIconName);
  WINUSERAPI HICON WINAPI لدو_Icon_W(HINSTANCE hInstance,LPCWSTR lpIconName);
  WINUSERAPI UINT WINAPI نجی_کڈھو_Icons_A(LPCSTR szFileName,صحيح n_Icon_اشاریہ,صحيح cxIcon,صحيح cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI UINT WINAPI نجی_کڈھو_Icons_W(LPCWSTR szFileName,صحيح n_Icon_اشاریہ,صحيح cxIcon,صحيح cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI HICON WINAPI CreateIcon(HINSTANCE hInstance,صحيح n_چوڑائی,صحيح n_اچائی,BYTE cPlanes,BYTE c_بٹ_Pixel,CONST BYTE *lpbANDbits,CONST BYTE *lpbXORbits);
  WINUSERAPI WINBOOL WINAPI DestroyIcon(HICON hIcon);
  WINUSERAPI صحيح WINAPI LookupIconIdFromDirectory(PBYTE presbits,WINBOOL fIcon);
  WINUSERAPI صحيح WINAPI LookupIconIdFromDirectoryEx(PBYTE presbits,WINBOOL fIcon,صحيح cxDesired,صحيح cyDesired,UINT Flags);
  WINUSERAPI HICON WINAPI CreateIconFromResource(PBYTE presbits,DWORD dw_Res_ناپ,WINBOOL fIcon,DWORD dwVer);
  WINUSERAPI HICON WINAPI CreateIconFromResourceEx(PBYTE presbits,DWORD dw_Res_ناپ,WINBOOL fIcon,DWORD dwVer,صحيح cxDesired,صحيح cyDesired,UINT Flags);

  تعريفنوع بنية ٹیگ_CURSORSHAPE {
    صحيح xHotSpot;
    صحيح yHotSpot;
    صحيح cx;
    صحيح cy;
    صحيح cb_چوڑائی;
    BYTE Planes;
    BYTE بٹ_Pixel;
  } CURSORSHAPE,*LPCURSORSHAPE;

#تعریف_کرو IMAGE_BITMAP 0
#تعریف_کرو IMAGE_ICON 1
#تعریف_کرو IMAGE_CURSOR 2
#تعریف_کرو IMAGE_ENHMETAFILE 3

#تعریف_کرو LR_DEFAULTCOLOR 0x0000
#تعریف_کرو LR_MONOCHROME 0x0001
#تعریف_کرو LR_COLOR 0x0002
#تعریف_کرو LR_COPYRETURNORG 0x0004
#تعریف_کرو LR_COPYDELETEORG 0x0008
#تعریف_کرو LR_LOADFROMFILE 0x0010
#تعریف_کرو LR_LOADTRANSPARENT 0x0020
#تعریف_کرو LR_DEFAULTSIZE 0x0040
#تعریف_کرو LR_VGACOLOR 0x0080
#تعریف_کرو LR_LOADMAP3DCOLORS 0x1000
#تعریف_کرو LR_CREATEDIBSECTION 0x2000
#تعریف_کرو LR_COPYFROMRESOURCE 0x4000
#تعریف_کرو LR_SHARED 0x8000

#جے_تعریف_شدہ UNICODE
#تعریف_کرو لدو_Image لدو_Image_W
#وإلا
#تعریف_کرو لدو_Image لدو_Image_A
#جے_انت

  WINUSERAPI HANDLE WINAPI لدو_Image_A(HINSTANCE hInst,LPCSTR name,UINT type,صحيح cx,صحيح cy,UINT fu_لدو);
  WINUSERAPI HANDLE WINAPI لدو_Image_W(HINSTANCE hInst,LPCWSTR name,UINT type,صحيح cx,صحيح cy,UINT fu_لدو);
  WINUSERAPI HANDLE WINAPI CopyImage(HANDLE h,UINT type,صحيح cx,صحيح cy,UINT flags);

#تعریف_کرو DI_نقاب 0x0001
#تعریف_کرو DI_IMAGE 0x0002
#تعریف_کرو DI_عام 0x0003
#تعریف_کرو DI_COMPAT 0x0004
#تعریف_کرو DI_DEFAULTSIZE 0x0008
#تعریف_کرو DI_NOMIRROR 0x0010

  WINUSERAPI WINBOOL WINAPI DrawIconEx(HDC hdc,صحيح x_بایاں,صحيح y_چوٹی,HICON hIcon,صحيح cx_چوڑائی,صحيح cy_چوڑائی,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
  WINUSERAPI HICON WINAPI Create_Icon_اسدھا(PICONINFO piconinfo);
  WINUSERAPI HICON WINAPI CopyIcon(HICON hIcon);
  WINUSERAPI WINBOOL WINAPI GetIconInfo(HICON hIcon,PICONINFO piconinfo);

#تعریف_کرو RES_ICON 1
#تعریف_کرو RES_CURSOR 2

#جے_تعریف_شدہ OEMRESOURCE

#تعریف_کرو OBM_CLOSE 32754
#تعریف_کرو OBM_UPARROW 32753
#تعریف_کرو OBM_DNARROW 32752
#تعریف_کرو OBM_RGARROW 32751
#تعریف_کرو OBM_LFARROW 32750
#تعریف_کرو OBM_REDUCE 32749
#تعریف_کرو OBM_ZOOM 32748
#تعریف_کرو OBM_RESTORE 32747
#تعریف_کرو OBM_REDUCED 32746
#تعریف_کرو OBM_ZOOMD 32745
#تعریف_کرو OBM_RESTORED 32744
#تعریف_کرو OBM_UPARROWD 32743
#تعریف_کرو OBM_DNARROWD 32742
#تعریف_کرو OBM_RGARROWD 32741
#تعریف_کرو OBM_LFARROWD 32740
#تعریف_کرو OBM_MNARROW 32739
#تعریف_کرو OBM_COMBO 32738
#تعریف_کرو OBM_UPARROWI 32737
#تعریف_کرو OBM_DNARROWI 32736
#تعریف_کرو OBM_RGARROWI 32735
#تعریف_کرو OBM_LFARROWI 32734

#تعریف_کرو OBM_OLD_CLOSE 32767
#تعریف_کرو OBM_ناپ 32766
#تعریف_کرو OBM_OLD_UPARROW 32765
#تعریف_کرو OBM_OLD_DNARROW 32764
#تعریف_کرو OBM_OLD_RGARROW 32763
#تعریف_کرو OBM_OLD_LFARROW 32762
#تعریف_کرو OBM_BTSIZE 32761
#تعریف_کرو OBM_CHECK 32760
#تعریف_کرو OBM_CHECKBOXES 32759
#تعریف_کرو OBM_BTNCORNERS 32758
#تعریف_کرو OBM_OLD_REDUCE 32757
#تعریف_کرو OBM_OLD_ZOOM 32756
#تعریف_کرو OBM_OLD_RESTORE 32755

#تعریف_کرو OCR_عام 32512
#تعریف_کرو OCR_IBEAM 32513
#تعریف_کرو OCR_WAIT 32514
#تعریف_کرو OCR_CROSS 32515
#تعریف_کرو OCR_اتے 32516
#تعریف_کرو OCR_ناپ 32640
#تعریف_کرو OCR_ICON 32641
#تعریف_کرو OCR_SIZENWSE 32642
#تعریف_کرو OCR_SIZENESW 32643
#تعریف_کرو OCR_SIZEWE 32644
#تعریف_کرو OCR_SIZENS 32645
#تعریف_کرو OCR_SIZEALL 32646
#تعریف_کرو OCR_ICOCUR 32647
#تعریف_کرو OCR_NO 32648
#تعریف_کرو OCR_HAND 32649
#تعریف_کرو OCR_APPSTARTING 32650

#تعریف_کرو OIC_SAMPLE 32512
#تعریف_کرو OIC_HAND 32513
#تعریف_کرو OIC_QUES 32514
#تعریف_کرو OIC_BANG 32515
#تعریف_کرو OIC_NOTE 32516
#تعریف_کرو OIC_WINLOGO 32517
#تعریف_کرو OIC_WARNING OIC_BANG
#تعریف_کرو OIC_ERROR OIC_HAND
#تعریف_کرو OIC_INFORMATION OIC_NOTE
#جے_انت

#تعریف_کرو ORD_LANGDRIVER 1

#جے_بنا_تعریف NOICONS

#جے_تعریف_شدہ RC_INVOKED
#تعریف_کرو IDI_APPLICATION 32512
#تعریف_کرو IDI_HAND 32513
#تعریف_کرو IDI_QUESTION 32514
#تعریف_کرو IDI_EXCLAMATION 32515
#تعریف_کرو IDI_ASTERISK 32516
#تعریف_کرو IDI_WINLOGO 32517
#وإلا
#تعریف_کرو IDI_APPLICATION MAKEINTRESOURCE(32512)
#تعریف_کرو IDI_HAND MAKEINTRESOURCE(32513)
#تعریف_کرو IDI_QUESTION MAKEINTRESOURCE(32514)
#تعریف_کرو IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#تعریف_کرو IDI_ASTERISK MAKEINTRESOURCE(32516)
#تعریف_کرو IDI_WINLOGO MAKEINTRESOURCE(32517)
#جے_انت

#تعریف_کرو IDI_WARNING IDI_EXCLAMATION
#تعریف_کرو IDI_ERROR IDI_HAND
#تعریف_کرو IDI_INFORMATION IDI_ASTERISK
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو لدو_String لدو_String_W
#وإلا
#تعریف_کرو لدو_String لدو_String_A
#جے_انت

  WINUSERAPI صحيح WINAPI لدو_String_A(HINSTANCE hInstance,UINT uID,LPSTR lp_بفر,صحيح cch_بفر_Max);
  WINUSERAPI صحيح WINAPI لدو_String_W(HINSTANCE hInstance,UINT uID,LPWSTR lp_بفر,صحيح cch_بفر_Max);

#تعریف_کرو IDOK 1
#تعریف_کرو IDCANCEL 2
#تعریف_کرو IDABORT 3
#تعریف_کرو IDRETRY 4
#تعریف_کرو IDIGNORE 5
#تعریف_کرو IDYES 6
#تعریف_کرو IDNO 7
#تعریف_کرو IDCLOSE 8
#تعریف_کرو IDHELP 9
#تعریف_کرو IDTRYAGAIN 10
#تعریف_کرو IDCONTINUE 11

#جے_بنا_تعریف IDTIMEOUT
#تعریف_کرو IDTIMEOUT 32000
#جے_انت

#جے_بنا_تعریف NOCTLMGR

#جے_بنا_تعریف NOWINSTYLES
#تعریف_کرو ES_بایاں 0x0000L
#تعریف_کرو ES_CENTER 0x0001L
#تعریف_کرو ES_دایاں 0x0002L
#تعریف_کرو ES_MULTILINE 0x0004L
#تعریف_کرو ES_UPPERCASE 0x0008L
#تعریف_کرو ES_LOWERCASE 0x0010L
#تعریف_کرو ES_PASSWORD 0x0020L
#تعریف_کرو ES_AUTOVSCROLL 0x0040L
#تعریف_کرو ES_AUTOHSCROLL 0x0080L
#تعریف_کرو ES_NOHIDESEL 0x0100L
#تعریف_کرو ES_OEMCONVERT 0x0400L
#تعریف_کرو ES_READONLY 0x0800L
#تعریف_کرو ES_WANTRETURN 0x1000L
#تعریف_کرو ES_نمبر 0x2000L
#جے_انت

#تعریف_کرو EN_SETFOCUS 0x0100
#تعریف_کرو EN_KILLFOCUS 0x0200
#تعریف_کرو EN_CHANGE 0x0300
#تعریف_کرو EN_UPDATE 0x0400
#تعریف_کرو EN_ERRSPACE 0x0500
#تعریف_کرو EN_MAXTEXT 0x0501
#تعریف_کرو EN_HSCROLL 0x0601
#تعریف_کرو EN_VSCROLL 0x0602
#تعریف_کرو EN_ALIGN_LTR_EC 0x0700
#تعریف_کرو EN_ALIGN_RTL_EC 0x0701

#تعریف_کرو EC_LEFTMARGIN 0x0001
#تعریف_کرو EC_RIGHTMARGIN 0x0002
#تعریف_کرو EC_USEFONTINFO 0xffff

#تعریف_کرو EMSIS_COMPOSITIONSTRING 0x0001

#تعریف_کرو EIMES_GETCOMPSTRATONCE 0x0001
#تعریف_کرو EIMES_CANCELCOMPSTRINFOCUS 0x0002
#تعریف_کرو EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#جے_بنا_تعریف NOWINMESSAGES

#تعریف_کرو EM_GETSEL 0x00B0
#تعریف_کرو EM_SETSEL 0x00B1
#تعریف_کرو EM_GETRECT 0x00B2
#تعریف_کرو EM_SETRECT 0x00B3
#تعریف_کرو EM_SETRECTNP 0x00B4
#تعریف_کرو EM_SCROLL 0x00B5
#تعریف_کرو EM_LINESCROLL 0x00B6
#تعریف_کرو EM_SCROLLCARET 0x00B7
#تعریف_کرو EM_GETMODIFY 0x00B8
#تعریف_کرو EM_SETMODIFY 0x00B9
#تعریف_کرو EM_GETLINECOUNT 0x00BA
#تعریف_کرو EM_LINEINDEX 0x00BB
#تعریف_کرو EM_SETHANDLE 0x00BC
#تعریف_کرو EM_GETHANDLE 0x00BD
#تعریف_کرو EM_GETTHUMB 0x00BE
#تعریف_کرو EM_LINELENGTH 0x00C1
#تعریف_کرو EM_REPLACESEL 0x00C2
#تعریف_کرو EM_GETLINE 0x00C4
#تعریف_کرو EM_LIMITTEXT 0x00C5
#تعریف_کرو EM_CANUNDO 0x00C6
#تعریف_کرو EM_UNDO 0x00C7
#تعریف_کرو EM_FMTLINES 0x00C8
#تعریف_کرو EM_LINEFROMCHAR 0x00C9
#تعریف_کرو EM_SETTABSTOPS 0x00CB
#تعریف_کرو EM_SETPASSWORDCHAR 0x00CC
#تعریف_کرو EM_EMPTYUNDOBUFFER 0x00CD
#تعریف_کرو EM_GETFIRSTVISIBLELINE 0x00CE
#تعریف_کرو EM_SETREADONLY 0x00CF
#تعریف_کرو EM_SETWORDBREAKPROC 0x00D0
#تعریف_کرو EM_GETWORDBREAKPROC 0x00D1
#تعریف_کرو EM_GETPASSWORDCHAR 0x00D2
#تعریف_کرو EM_SETMARGINS 0x00D3
#تعریف_کرو EM_GETMARGINS 0x00D4
#تعریف_کرو EM_SETLIMITTEXT EM_LIMITTEXT
#تعریف_کرو EM_GETLIMITTEXT 0x00D5
#تعریف_کرو EM_POSFROMCHAR 0x00D6
#تعریف_کرو EM_CHARFROMPOS 0x00D7
#تعریف_کرو EM_SETIMESTATUS 0x00D8
#تعریف_کرو EM_GETIMESTATUS 0x00D9
#جے_انت

#تعریف_کرو WB_بایاں 0
#تعریف_کرو WB_دایاں 1
#تعریف_کرو WB_ISDELIMITER 2

#تعریف_کرو BS_PUSHBUTTON 0x00000000L
#تعریف_کرو BS_DEFPUSHBUTTON 0x00000001L
#تعریف_کرو BS_CHECKBOX 0x00000002L
#تعریف_کرو BS_AUTOCHECKBOX 0x00000003L
#تعریف_کرو BS_RADIOBUTTON 0x00000004L
#تعریف_کرو BS_3STATE 0x00000005L
#تعریف_کرو BS_AUTO3STATE 0x00000006L
#تعریف_کرو BS_GROUPBOX 0x00000007L
#تعریف_کرو BS_USERBUTTON 0x00000008L
#تعریف_کرو BS_AUTORADIOBUTTON 0x00000009L
#تعریف_کرو BS_PUSHBOX 0x0000000AL
#تعریف_کرو BS_OWNERDRAW 0x0000000BL
#تعریف_کرو BS_TYPEMASK 0x0000000FL
#تعریف_کرو BS_LEFTTEXT 0x00000020L
#تعریف_کرو BS_متن 0x00000000L
#تعریف_کرو BS_ICON 0x00000040L
#تعریف_کرو BS_BITMAP 0x00000080L
#تعریف_کرو BS_بایاں 0x00000100L
#تعریف_کرو BS_دایاں 0x00000200L
#تعریف_کرو BS_CENTER 0x00000300L
#تعریف_کرو BS_چوٹی 0x00000400L
#تعریف_کرو BS_BOTTOM 0x00000800L
#تعریف_کرو BS_VCENTER 0x00000C00L
#تعریف_کرو BS_PUSHLIKE 0x00001000L
#تعریف_کرو BS_MULTILINE 0x00002000L
#تعریف_کرو BS_NOTIFY 0x00004000L
#تعریف_کرو BS_FLAT 0x00008000L
#تعریف_کرو BS_RIGHTBUTTON BS_LEFTTEXT

#تعریف_کرو BN_CLICKED 0
#تعریف_کرو BN_PAINT 1
#تعریف_کرو BN_HILITE 2
#تعریف_کرو BN_UNHILITE 3
#تعریف_کرو BN_DISABLE 4
#تعریف_کرو BN_DOUBLECLICKED 5
#تعریف_کرو BN_PUSHED BN_HILITE
#تعریف_کرو BN_UNPUSHED BN_UNHILITE
#تعریف_کرو BN_DBLCLK BN_DOUBLECLICKED
#تعریف_کرو BN_SETFOCUS 6
#تعریف_کرو BN_KILLFOCUS 7

#تعریف_کرو BM_GETCHECK 0x00F0
#تعریف_کرو BM_SETCHECK 0x00F1
#تعریف_کرو BM_GETSTATE 0x00F2
#تعریف_کرو BM_SETSTATE 0x00F3
#تعریف_کرو BM_SETSTYLE 0x00F4
#تعریف_کرو BM_CLICK 0x00F5
#تعریف_کرو BM_GETIMAGE 0x00F6
#تعریف_کرو BM_SETIMAGE 0x00F7

#تعریف_کرو BST_UNCHECKED 0x0000
#تعریف_کرو BST_CHECKED 0x0001
#تعریف_کرو BST_INDETERMINATE 0x0002
#تعریف_کرو BST_PUSHED 0x0004
#تعریف_کرو BST_FOCUS 0x0008

#تعریف_کرو SS_بایاں 0x00000000L
#تعریف_کرو SS_CENTER 0x00000001L
#تعریف_کرو SS_دایاں 0x00000002L
#تعریف_کرو SS_ICON 0x00000003L
#تعریف_کرو SS_BLACKRECT 0x00000004L
#تعریف_کرو SS_GRAYRECT 0x00000005L
#تعریف_کرو SS_WHITERECT 0x00000006L
#تعریف_کرو SS_BLACKFRAME 0x00000007L
#تعریف_کرو SS_GRAYFRAME 0x00000008L
#تعریف_کرو SS_WHITEFRAME 0x00000009L
#تعریف_کرو SS_USERITEM 0x0000000AL
#تعریف_کرو SS_SIMPLE 0x0000000BL
#تعریف_کرو SS_LEFTNOWORDWRAP 0x0000000CL
#تعریف_کرو SS_OWNERDRAW 0x0000000DL
#تعریف_کرو SS_BITMAP 0x0000000EL
#تعریف_کرو SS_ENHMETAFILE 0x0000000FL
#تعریف_کرو SS_ETCHEDHORZ 0x00000010L
#تعریف_کرو SS_ETCHEDVERT 0x00000011L
#تعریف_کرو SS_ETCHEDFRAME 0x00000012L
#تعریف_کرو SS_TYPEMASK 0x0000001FL
#تعریف_کرو SS_REALSIZECONTROL 0x00000040L
#تعریف_کرو SS_NOPREFIX 0x00000080L
#تعریف_کرو SS_NOTIFY 0x00000100L
#تعریف_کرو SS_CENTERIMAGE 0x00000200L
#تعریف_کرو SS_RIGHTJUST 0x00000400L
#تعریف_کرو SS_REALSIZEIMAGE 0x00000800L
#تعریف_کرو SS_SUNKEN 0x00001000L
#تعریف_کرو SS_EDITCONTROL 0x00002000L
#تعریف_کرو SS_ENDELLIPSIS 0x00004000L
#تعریف_کرو SS_PATHELLIPSIS 0x00008000L
#تعریف_کرو SS_WORDELLIPSIS 0x0000C000L
#تعریف_کرو SS_ELLIPSISMASK 0x0000C000L

#جے_بنا_تعریف NOWINMESSAGES

#تعریف_کرو STM_SETICON 0x0170
#تعریف_کرو STM_GETICON 0x0171
#تعریف_کرو STM_SETIMAGE 0x0172
#تعریف_کرو STM_GETIMAGE 0x0173
#تعریف_کرو STN_CLICKED 0
#تعریف_کرو STN_DBLCLK 1
#تعریف_کرو STN_ENABLE 2
#تعریف_کرو STN_DISABLE 3
#تعریف_کرو STM_MSGMAX 0x0174
#جے_انت

#تعریف_کرو WC_DIALOG (MAKEINTATOM(0x8002))

#تعریف_کرو DWL_MSGRESULT 0
#تعریف_کرو DWL_DLGPROC 4
#تعریف_کرو DWL_USER 8

#جے_تعریف_شدہ _WIN64

#تعریف_رد DWL_MSGRESULT
#تعریف_رد DWL_DLGPROC
#تعریف_رد DWL_USER
#جے_انت

#تعریف_کرو DWLP_MSGRESULT 0
#تعریف_کرو DWLP_DLGPROC DWLP_MSGRESULT + حجم(LRESULT)
#تعریف_کرو DWLP_USER DWLP_DLGPROC + حجم(DLGPROC)

#جے_بنا_تعریف NOMSG

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Is_Dialog_سنیہا Is_Dialog_سنیہا_W
#وإلا
#تعریف_کرو Is_Dialog_سنیہا Is_Dialog_سنیہا_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI Is_Dialog_سنیہا_A(HWND hDlg,LPMSG lp_پیغام);
  WINUSERAPI WINBOOL WINAPI Is_Dialog_سنیہا_W(HWND hDlg,LPMSG lp_پیغام);
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو DlgDirList DlgDirListW
#تعریف_کرو DlgDirSelectEx DlgDirSelectExW
#تعریف_کرو DlgDirListComboBox DlgDirListComboBoxW
#تعریف_کرو DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#وإلا
#تعریف_کرو DlgDirList DlgDirListA
#تعریف_کرو DlgDirSelectEx DlgDirSelectExA
#تعریف_کرو DlgDirListComboBox DlgDirListComboBoxA
#تعریف_کرو DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#جے_انت

  WINUSERAPI WINBOOL WINAPI MapDialogRect(HWND hDlg,LPRECT lpRect);
  WINUSERAPI صحيح WINAPI DlgDirListA(HWND hDlg,LPSTR lp_رستہ_Spec,صحيح nIDListBox,صحيح n_IDStatic_رستہ,UINT uFileType);
  WINUSERAPI صحيح WINAPI DlgDirListW(HWND hDlg,LPWSTR lp_رستہ_Spec,صحيح nIDListBox,صحيح n_IDStatic_رستہ,UINT uFileType);

#تعریف_کرو DDL_READWRITE 0x0000
#تعریف_کرو DDL_READONLY 0x0001
#تعریف_کرو DDL_HIDDEN 0x0002
#تعریف_کرو DDL_SYSTEM 0x0004
#تعریف_کرو DDL_DIRECTORY 0x0010
#تعریف_کرو DDL_ARCHIVE 0x0020

#تعریف_کرو DDL_POSTMSGS 0x2000
#تعریف_کرو DDL_DRIVES 0x4000
#تعریف_کرو DDL_EXCLUSIVE 0x8000

  WINUSERAPI WINBOOL WINAPI DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,صحيح ch_گنتی,صحيح idListBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,صحيح ch_گنتی,صحيح idListBox);
  WINUSERAPI صحيح WINAPI DlgDirListComboBoxA(HWND hDlg,LPSTR lp_رستہ_Spec,صحيح nIDComboBox,صحيح n_IDStatic_رستہ,UINT uFiletype);
  WINUSERAPI صحيح WINAPI DlgDirListComboBoxW(HWND hDlg,LPWSTR lp_رستہ_Spec,صحيح nIDComboBox,صحيح n_IDStatic_رستہ,UINT uFiletype);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,صحيح cch_باہرلا,صحيح idComboBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,صحيح cch_باہرلا,صحيح idComboBox);

#تعریف_کرو DS_ABSALIGN 0x01L
#تعریف_کرو DS_SYSMODAL 0x02L
#تعریف_کرو DS_LOCALEDIT 0x20L
#تعریف_کرو DS_SETFONT 0x40L
#تعریف_کرو DS_MODALFRAME 0x80L
#تعریف_کرو DS_NOIDLEMSG 0x100L
#تعریف_کرو DS_SETFOREGROUND 0x200L

#تعریف_کرو DS_3DLOOK 0x0004L
#تعریف_کرو DS_FIXEDSYS 0x0008L
#تعریف_کرو DS_NOFAILCREATE 0x0010L
#تعریف_کرو DS_CONTROL 0x0400L
#تعریف_کرو DS_CENTER 0x0800L
#تعریف_کرو DS_CENTERMOUSE 0x1000L
#تعریف_کرو DS_CONTEXTHELP 0x2000L

#تعریف_کرو DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#إذا(_WIN32_WCE >= 0x0500)
#تعریف_کرو DS_USEPIXELS 0x8000L
#جے_انت

#تعریف_کرو DM_GETDEFID (WM_USER+0)
#تعریف_کرو DM_SETDEFID (WM_USER+1)
#تعریف_کرو DM_REPOSITION (WM_USER+2)

#تعریف_کرو DC_HASDEFID 0x534B

#تعریف_کرو DLGC_WANTARROWS 0x0001
#تعریف_کرو DLGC_WANTTAB 0x0002
#تعریف_کرو DLGC_WANTALLKEYS 0x0004
#تعریف_کرو DLGC_WANTMESSAGE 0x0004
#تعریف_کرو DLGC_HASSETSEL 0x0008
#تعریف_کرو DLGC_DEFPUSHBUTTON 0x0010
#تعریف_کرو DLGC_UNDEFPUSHBUTTON 0x0020
#تعریف_کرو DLGC_RADIOBUTTON 0x0040
#تعریف_کرو DLGC_WANTCHARS 0x0080
#تعریف_کرو DLGC_STATIC 0x0100
#تعریف_کرو DLGC_BUTTON 0x2000

#تعریف_کرو LB_CTLCODE 0L

#تعریف_کرو LB_OKAY 0
#تعریف_کرو LB_ERR (-1)
#تعریف_کرو LB_ERRSPACE (-2)

#تعریف_کرو LBN_ERRSPACE (-2)
#تعریف_کرو LBN_SELCHANGE 1
#تعریف_کرو LBN_DBLCLK 2
#تعریف_کرو LBN_SELCANCEL 3
#تعریف_کرو LBN_SETFOCUS 4
#تعریف_کرو LBN_KILLFOCUS 5

#جے_بنا_تعریف NOWINMESSAGES

#تعریف_کرو LB_ADDSTRING 0x0180
#تعریف_کرو LB_INSERTSTRING 0x0181
#تعریف_کرو LB_DELETESTRING 0x0182
#تعریف_کرو LB_SELITEMRANGEEX 0x0183
#تعریف_کرو LB_RESETCONTENT 0x0184
#تعریف_کرو LB_SETSEL 0x0185
#تعریف_کرو LB_SETCURSEL 0x0186
#تعریف_کرو LB_GETSEL 0x0187
#تعریف_کرو LB_GETCURSEL 0x0188
#تعریف_کرو LB_GETTEXT 0x0189
#تعریف_کرو LB_GETTEXTLEN 0x018A
#تعریف_کرو LB_GETCOUNT 0x018B
#تعریف_کرو LB_SELECTSTRING 0x018C
#تعریف_کرو LB_DIR 0x018D
#تعریف_کرو LB_GETTOPINDEX 0x018E
#تعریف_کرو LB_FINDSTRING 0x018F
#تعریف_کرو LB_GETSELCOUNT 0x0190
#تعریف_کرو LB_GETSELITEMS 0x0191
#تعریف_کرو LB_SETTABSTOPS 0x0192
#تعریف_کرو LB_GETHORIZONTALEXTENT 0x0193
#تعریف_کرو LB_SETHORIZONTALEXTENT 0x0194
#تعریف_کرو LB_SETCOLUMNWIDTH 0x0195
#تعریف_کرو LB_ADDFILE 0x0196
#تعریف_کرو LB_SETTOPINDEX 0x0197
#تعریف_کرو LB_GETITEMRECT 0x0198
#تعریف_کرو LB_GETITEMDATA 0x0199
#تعریف_کرو LB_SETITEMDATA 0x019A
#تعریف_کرو LB_SELITEMRANGE 0x019B
#تعریف_کرو LB_SETANCHORINDEX 0x019C
#تعریف_کرو LB_GETANCHORINDEX 0x019D
#تعریف_کرو LB_SETCARETINDEX 0x019E
#تعریف_کرو LB_GETCARETINDEX 0x019F
#تعریف_کرو LB_SETITEMHEIGHT 0x01A0
#تعریف_کرو LB_GETITEMHEIGHT 0x01A1
#تعریف_کرو LB_FINDSTRINGEXACT 0x01A2
#تعریف_کرو LB_SETLOCALE 0x01A5
#تعریف_کرو LB_GETLOCALE 0x01A6
#تعریف_کرو LB_SETCOUNT 0x01A7
#تعریف_کرو LB_INITSTORAGE 0x01A8
#تعریف_کرو LB_ITEMFROMPOINT 0x01A9
#إذا(_WIN32_WCE >= 0x0400)
#تعریف_کرو LB_MULTIPLEADDSTRING 0x01B1
#جے_انت
#تعریف_کرو LB_GETLISTBOXINFO 0x01B2
#تعریف_کرو LB_MSGMAX 0x01B3
#جے_انت

#جے_بنا_تعریف NOWINSTYLES

#تعریف_کرو LBS_NOTIFY 0x0001L
#تعریف_کرو LBS_ترتیب_دیو 0x0002L
#تعریف_کرو LBS_NOREDRAW 0x0004L
#تعریف_کرو LBS_MULTIPLESEL 0x0008L
#تعریف_کرو LBS_OWNERDRAWFIXED 0x0010L
#تعریف_کرو LBS_OWNERDRAWVARIABLE 0x0020L
#تعریف_کرو LBS_HASSTRINGS 0x0040L
#تعریف_کرو LBS_USETABSTOPS 0x0080L
#تعریف_کرو LBS_NOINTEGRALHEIGHT 0x0100L
#تعریف_کرو LBS_MULTICOLUMN 0x0200L
#تعریف_کرو LBS_WANTKEYBOARDINPUT 0x0400L
#تعریف_کرو LBS_EXTENDEDSEL 0x0800L
#تعریف_کرو LBS_DISABLENOSCROLL 0x1000L
#تعریف_کرو LBS_NODATA 0x2000L
#تعریف_کرو LBS_NOSEL 0x4000L
#تعریف_کرو LBS_COMBOBOX 0x8000L

#تعریف_کرو LBS_STANDARD (LBS_NOTIFY | LBS_ترتیب_دیو | WS_VSCROLL | WS_BORDER)
#جے_انت

#تعریف_کرو CB_OKAY 0
#تعریف_کرو CB_ERR (-1)
#تعریف_کرو CB_ERRSPACE (-2)

#تعریف_کرو CBN_ERRSPACE (-1)
#تعریف_کرو CBN_SELCHANGE 1
#تعریف_کرو CBN_DBLCLK 2
#تعریف_کرو CBN_SETFOCUS 3
#تعریف_کرو CBN_KILLFOCUS 4
#تعریف_کرو CBN_EDITCHANGE 5
#تعریف_کرو CBN_EDITUPDATE 6
#تعریف_کرو CBN_DROPDOWN 7
#تعریف_کرو CBN_CLOSEUP 8
#تعریف_کرو CBN_SELENDOK 9
#تعریف_کرو CBN_SELENDCANCEL 10

#جے_بنا_تعریف NOWINSTYLES

#تعریف_کرو CBS_SIMPLE 0x0001L
#تعریف_کرو CBS_DROPDOWN 0x0002L
#تعریف_کرو CBS_DROPDOWNLIST 0x0003L
#تعریف_کرو CBS_OWNERDRAWFIXED 0x0010L
#تعریف_کرو CBS_OWNERDRAWVARIABLE 0x0020L
#تعریف_کرو CBS_AUTOHSCROLL 0x0040L
#تعریف_کرو CBS_OEMCONVERT 0x0080L
#تعریف_کرو CBS_ترتیب_دیو 0x0100L
#تعریف_کرو CBS_HASSTRINGS 0x0200L
#تعریف_کرو CBS_NOINTEGRALHEIGHT 0x0400L
#تعریف_کرو CBS_DISABLENOSCROLL 0x0800L
#تعریف_کرو CBS_UPPERCASE 0x2000L
#تعریف_کرو CBS_LOWERCASE 0x4000L
#جے_انت

#جے_بنا_تعریف NOWINMESSAGES
#تعریف_کرو CB_GETEDITSEL 0x0140
#تعریف_کرو CB_LIMITTEXT 0x0141
#تعریف_کرو CB_SETEDITSEL 0x0142
#تعریف_کرو CB_ADDSTRING 0x0143
#تعریف_کرو CB_DELETESTRING 0x0144
#تعریف_کرو CB_DIR 0x0145
#تعریف_کرو CB_GETCOUNT 0x0146
#تعریف_کرو CB_GETCURSEL 0x0147
#تعریف_کرو CB_GETLBTEXT 0x0148
#تعریف_کرو CB_GETLBTEXTLEN 0x0149
#تعریف_کرو CB_INSERTSTRING 0x014A
#تعریف_کرو CB_RESETCONTENT 0x014B
#تعریف_کرو CB_FINDSTRING 0x014C
#تعریف_کرو CB_SELECTSTRING 0x014D
#تعریف_کرو CB_SETCURSEL 0x014E
#تعریف_کرو CB_SHOWDROPDOWN 0x014F
#تعریف_کرو CB_GETITEMDATA 0x0150
#تعریف_کرو CB_SETITEMDATA 0x0151
#تعریف_کرو CB_GETDROPPEDCONTROLRECT 0x0152
#تعریف_کرو CB_SETITEMHEIGHT 0x0153
#تعریف_کرو CB_GETITEMHEIGHT 0x0154
#تعریف_کرو CB_SETEXTENDEDUI 0x0155
#تعریف_کرو CB_GETEXTENDEDUI 0x0156
#تعریف_کرو CB_GETDROPPEDSTATE 0x0157
#تعریف_کرو CB_FINDSTRINGEXACT 0x0158
#تعریف_کرو CB_SETLOCALE 0x0159
#تعریف_کرو CB_GETLOCALE 0x015A
#تعریف_کرو CB_GETTOPINDEX 0x015b
#تعریف_کرو CB_SETTOPINDEX 0x015c
#تعریف_کرو CB_GETHORIZONTALEXTENT 0x015d
#تعریف_کرو CB_SETHORIZONTALEXTENT 0x015e
#تعریف_کرو CB_GETDROPPEDWIDTH 0x015f
#تعریف_کرو CB_SETDROPPEDWIDTH 0x0160
#تعریف_کرو CB_INITSTORAGE 0x0161
#إذا(_WIN32_WCE >= 0x0400)
#تعریف_کرو CB_MULTIPLEADDSTRING 0x0163
#جے_انت
#تعریف_کرو CB_GETCOMBOBOXINFO 0x0164
#تعریف_کرو CB_MSGMAX 0x0165
#جے_انت

#جے_بنا_تعریف NOWINSTYLES

#تعریف_کرو SBS_HORZ 0x0000L
#تعریف_کرو SBS_VERT 0x0001L
#تعریف_کرو SBS_TOPALIGN 0x0002L
#تعریف_کرو SBS_LEFTALIGN 0x0002L
#تعریف_کرو SBS_BOTTOMALIGN 0x0004L
#تعریف_کرو SBS_RIGHTALIGN 0x0004L
#تعریف_کرو SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#تعریف_کرو SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#تعریف_کرو SBS_SIZEBOX 0x0008L
#تعریف_کرو SBS_SIZEGRIP 0x0010L
#جے_انت

#جے_بنا_تعریف NOWINMESSAGES
#تعریف_کرو SBM_SETPOS 0x00E0
#تعریف_کرو SBM_GETPOS 0x00E1
#تعریف_کرو SBM_SETRANGE 0x00E2
#تعریف_کرو SBM_SETRANGEREDRAW 0x00E6
#تعریف_کرو SBM_GETRANGE 0x00E3
#تعریف_کرو SBM_ENABLE_ARROWS 0x00E4
#تعریف_کرو SBM_SETSCROLLINFO 0x00E9
#تعریف_کرو SBM_GETSCROLLINFO 0x00EA
#تعریف_کرو SBM_GETSCROLLBARINFO 0x00EB

#تعریف_کرو SIF_RANGE 0x0001
#تعریف_کرو SIF_ورقہ 0x0002
#تعریف_کرو SIF_POS 0x0004
#تعریف_کرو SIF_DISABLENOSCROLL 0x0008
#تعریف_کرو SIF_TRACKPOS 0x0010
#تعریف_کرو SIF_ALL (SIF_RANGE | SIF_ورقہ | SIF_POS | SIF_TRACKPOS)

  تعريفنوع بنية ٹیگ_SCROLLINFO {
    UINT cb_ناپ;
    UINT f_نقاب;
    صحيح nMin;
    صحيح nMax;
    UINT n_ورقہ;
    صحيح nPos;
    صحيح nTrackPos;
  } SCROLLINFO,*LPSCROLLINFO;
  تعريفنوع SCROLLINFO CONST *LPCSCROLLINFO;

  WINUSERAPI صحيح WINAPI سیٹ_Scroll_Info(HWND hwnd,صحيح nBar,LPCSCROLLINFO lpsi,WINBOOL redraw);
  WINUSERAPI WINBOOL WINAPI GetScrollInfo(HWND hwnd,صحيح nBar,LPSCROLLINFO lpsi);
#جے_انت
#جے_انت

#جے_بنا_تعریف NOMDI

#تعریف_کرو MDIS_ALLCHILDSTYLES 0x0001

#تعریف_کرو MDITILE_VERTICAL 0x0000
#تعریف_کرو MDITILE_HORIZONTAL 0x0001
#تعریف_کرو MDITILE_SKIPDISABLED 0x0002
#تعریف_کرو MDITILE_ZORDER 0x0004

  تعريفنوع بنية ٹیگ_MDICREATESTRUCTA {
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

  تعريفنوع بنية ٹیگ_MDICREATESTRUCTW {
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

#جے_تعریف_شدہ UNICODE
  تعريفنوع MDICREATESTRUCTW MDICREATESTRUCT;
  تعريفنوع LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#وإلا
  تعريفنوع MDICREATESTRUCTA MDICREATESTRUCT;
  تعريفنوع LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#جے_انت

  تعريفنوع بنية ٹیگ_CLIENTCREATESTRUCT {
    HANDLE h_کھڑکی_Menu;
    UINT id_پہلا_بچہ;
  } CLIENTCREATESTRUCT,*LPCLIENTCREATESTRUCT;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Def_چوکھٹا_Proc Def_چوکھٹا_Proc_W
#تعریف_کرو DefMDIChildProc DefMDIChildProcW
#تعریف_کرو CreateMDIWindow CreateMDIWindowW
#وإلا
#تعریف_کرو Def_چوکھٹا_Proc Def_چوکھٹا_Proc_A
#تعریف_کرو DefMDIChildProc DefMDIChildProcA
#تعریف_کرو CreateMDIWindow CreateMDIWindowA
#جے_انت

  WINUSERAPI LRESULT WINAPI Def_چوکھٹا_Proc_A(HWND hWnd,HWND hWndMDIClient,UINT u_پیغام,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_چوکھٹا_Proc_W(HWND hWnd,HWND hWndMDIClient,UINT u_پیغام,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcA(HWND hWnd,UINT u_پیغام,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcW(HWND hWnd,UINT u_پیغام,WPARAM wParam,LPARAM lParam);

#جے_بنا_تعریف NOMSG
  WINUSERAPI WINBOOL WINAPI TranslateMDISysAccel(HWND hWndClient,LPMSG lp_پیغام);
#جے_انت

  WINUSERAPI UINT WINAPI ArrangeIconicWindows(HWND hWnd);
  WINUSERAPI HWND WINAPI CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lp_کھڑکی_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_چوڑائی,صحيح n_اچائی,HWND h_Wnd_ماپا,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI HWND WINAPI CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lp_کھڑکی_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_چوڑائی,صحيح n_اچائی,HWND h_Wnd_ماپا,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI لفظ_3 WINAPI TileWindows(HWND hwnd_ماپا_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ثابت HWND *lpKids);
  WINUSERAPI لفظ_3 WINAPI CascadeWindows(HWND hwnd_ماپا_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ثابت HWND *lpKids);
#جے_انت
#جے_انت

#جے_بنا_تعریف NOHELP

  تعريفنوع DWORD HELPPOLY;
  تعريفنوع بنية ٹیگ_MULTIKEYHELPA {
    DWORD mk_ناپ;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
  } MULTIKEYHELPA,*PMULTIKEYHELPA,*LPMULTIKEYHELPA;

  تعريفنوع بنية ٹیگ_MULTIKEYHELPW {
    DWORD mk_ناپ;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
  } MULTIKEYHELPW,*PMULTIKEYHELPW,*LPMULTIKEYHELPW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع MULTIKEYHELPW MULTIKEYHELP;
  تعريفنوع PMULTIKEYHELPW PMULTIKEYHELP;
  تعريفنوع LPMULTIKEYHELPW LPMULTIKEYHELP;
#وإلا
  تعريفنوع MULTIKEYHELPA MULTIKEYHELP;
  تعريفنوع PMULTIKEYHELPA PMULTIKEYHELP;
  تعريفنوع LPMULTIKEYHELPA LPMULTIKEYHELP;
#جے_انت

  تعريفنوع بنية ٹیگ_HELPWININFOA {
    صحيح w_Struct_ناپ;
    صحيح x;
    صحيح y;
    صحيح dx;
    صحيح dy;
    صحيح wMax;
    CHAR rgchMember[2];
  } HELPWININFOA,*PHELPWININFOA,*LPHELPWININFOA;

  تعريفنوع بنية ٹیگ_HELPWININFOW {
    صحيح w_Struct_ناپ;
    صحيح x;
    صحيح y;
    صحيح dx;
    صحيح dy;
    صحيح wMax;
    WCHAR rgchMember[2];
  } HELPWININFOW,*PHELPWININFOW,*LPHELPWININFOW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع HELPWININFOW HELPWININFO;
  تعريفنوع PHELPWININFOW PHELPWININFO;
  تعريفنوع LPHELPWININFOW LPHELPWININFO;
#وإلا
  تعريفنوع HELPWININFOA HELPWININFO;
  تعريفنوع PHELPWININFOA PHELPWININFO;
  تعريفنوع LPHELPWININFOA LPHELPWININFO;
#جے_انت

#تعریف_کرو HELP_CONTEXT 0x0001L
#تعریف_کرو HELP_QUIT 0x0002L
#تعریف_کرو HELP_اشاریہ 0x0003L
#تعریف_کرو HELP_CONTENTS 0x0003L
#تعریف_کرو HELP_HELPONHELP 0x0004L
#تعریف_کرو HELP_SETINDEX 0x0005L
#تعریف_کرو HELP_SETCONTENTS 0x0005L
#تعریف_کرو HELP_CONTEXTPOPUP 0x0008L
#تعریف_کرو HELP_FORCEFILE 0x0009L
#تعریف_کرو HELP_کلید 0x0101L
#تعریف_کرو HELP_COMMAND 0x0102L
#تعریف_کرو HELP_PARTIALKEY 0x0105L
#تعریف_کرو HELP_MULTIKEY 0x0201L
#تعریف_کرو HELP_SETWINPOS 0x0203L
#تعریف_کرو HELP_CONTEXTMENU 0x000a
#تعریف_کرو HELP_FINDER 0x000b
#تعریف_کرو HELP_WM_HELP 0x000c
#تعریف_کرو HELP_SETPOPUP_POS 0x000d

#تعریف_کرو HELP_TCARD 0x8000
#تعریف_کرو HELP_TCARD_انکڑے 0x0010
#تعریف_کرو HELP_TCARD_OTHER_CALLER 0x0011

#تعریف_کرو IDH_NO_HELP 28440
#تعریف_کرو IDH_MISSING_CONTEXT 28441
#تعریف_کرو IDH_GENERIC_HELP_BUTTON 28442
#تعریف_کرو IDH_OK 28443
#تعریف_کرو IDH_CANCEL 28444
#تعریف_کرو IDH_HELP 28445

#جے_تعریف_شدہ UNICODE
#تعریف_کرو WinHelp WinHelpW
#وإلا
#تعریف_کرو WinHelp WinHelpA
#جے_انت

  WINUSERAPI WINBOOL WINAPI WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dw_انکڑے);
  WINUSERAPI WINBOOL WINAPI WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dw_انکڑے);
#جے_انت

#تعریف_کرو GR_GDIOBJECTS 0
#تعریف_کرو GR_USEROBJECTS 1

  WINUSERAPI DWORD WINAPI GetGuiResources(HANDLE hProcess,DWORD uiFlags);

#جے_بنا_تعریف NOSYSPARAMSINFO

#تعریف_کرو SPI_GETBEEP 0x0001
#تعریف_کرو SPI_SETBEEP 0x0002
#تعریف_کرو SPI_GETMOUSE 0x0003
#تعریف_کرو SPI_SETMOUSE 0x0004
#تعریف_کرو SPI_GETBORDER 0x0005
#تعریف_کرو SPI_SETBORDER 0x0006
#تعریف_کرو SPI_GETKEYBOARDSPEED 0x000A
#تعریف_کرو SPI_SETKEYBOARDSPEED 0x000B
#تعریف_کرو SPI_LANGDRIVER 0x000C
#تعریف_کرو SPI_ICONHORIZONTALSPACING 0x000D
#تعریف_کرو SPI_GETSCREENSAVETIMEOUT 0x000E
#تعریف_کرو SPI_SETSCREENSAVETIMEOUT 0x000F
#تعریف_کرو SPI_GETSCREENSAVEACTIVE 0x0010
#تعریف_کرو SPI_SETSCREENSAVEACTIVE 0x0011
#تعریف_کرو SPI_GETGRIDGRANULARITY 0x0012
#تعریف_کرو SPI_SETGRIDGRANULARITY 0x0013
#تعریف_کرو SPI_SETDESKWALLPAPER 0x0014
#تعریف_کرو SPI_SETDESKPATTERN 0x0015
#تعریف_کرو SPI_GETKEYBOARDDELAY 0x0016
#تعریف_کرو SPI_SETKEYBOARDDELAY 0x0017
#تعریف_کرو SPI_ICONVERTICALSPACING 0x0018
#تعریف_کرو SPI_GETICONTITLEWRAP 0x0019
#تعریف_کرو SPI_SETICONTITLEWRAP 0x001A
#تعریف_کرو SPI_GETMENUDROPALIGNMENT 0x001B
#تعریف_کرو SPI_SETMENUDROPALIGNMENT 0x001C
#تعریف_کرو SPI_SETDOUBLECLKWIDTH 0x001D
#تعریف_کرو SPI_SETDOUBLECLKHEIGHT 0x001E
#تعریف_کرو SPI_GETICONTITLELOGFONT 0x001F
#تعریف_کرو SPI_SETDOUBLECLICKTIME 0x0020
#تعریف_کرو SPI_SETMOUSEBUTTONSWAP 0x0021
#تعریف_کرو SPI_SETICONTITLELOGFONT 0x0022
#تعریف_کرو SPI_GETFASTTASKSWITCH 0x0023
#تعریف_کرو SPI_SETFASTTASKSWITCH 0x0024
#تعریف_کرو SPI_SETDRAGFULLWINDOWS 0x0025
#تعریف_کرو SPI_GETDRAGFULLWINDOWS 0x0026
#تعریف_کرو SPI_GETNONCLIENTMETRICS 0x0029
#تعریف_کرو SPI_SETNONCLIENTMETRICS 0x002A
#تعریف_کرو SPI_GETMINIMIZEDMETRICS 0x002B
#تعریف_کرو SPI_SETMINIMIZEDMETRICS 0x002C
#تعریف_کرو SPI_GETICONMETRICS 0x002D
#تعریف_کرو SPI_SETICONMETRICS 0x002E
#تعریف_کرو SPI_SETWORKAREA 0x002F
#تعریف_کرو SPI_GETWORKAREA 0x0030
#تعریف_کرو SPI_SETPENWINDOWS 0x0031

#تعریف_کرو SPI_GETHIGHCONTRAST 0x0042
#تعریف_کرو SPI_SETHIGHCONTRAST 0x0043
#تعریف_کرو SPI_GETKEYBOARDPREF 0x0044
#تعریف_کرو SPI_SETKEYBOARDPREF 0x0045
#تعریف_کرو SPI_GETSCREENREADER 0x0046
#تعریف_کرو SPI_SETSCREENREADER 0x0047
#تعریف_کرو SPI_GETANIMATION 0x0048
#تعریف_کرو SPI_SETANIMATION 0x0049
#تعریف_کرو SPI_GETFONTSMOOTHING 0x004A
#تعریف_کرو SPI_SETFONTSMOOTHING 0x004B
#تعریف_کرو SPI_SETDRAGWIDTH 0x004C
#تعریف_کرو SPI_SETDRAGHEIGHT 0x004D
#تعریف_کرو SPI_SETHANDHELD 0x004E
#تعریف_کرو SPI_GETLOWPOWERTIMEOUT 0x004F
#تعریف_کرو SPI_GETPOWEROFFTIMEOUT 0x0050
#تعریف_کرو SPI_SETLOWPOWERTIMEOUT 0x0051
#تعریف_کرو SPI_SETPOWEROFFTIMEOUT 0x0052
#تعریف_کرو SPI_GETLOWPOWERACTIVE 0x0053
#تعریف_کرو SPI_GETPOWEROFFACTIVE 0x0054
#تعریف_کرو SPI_SETLOWPOWERACTIVE 0x0055
#تعریف_کرو SPI_SETPOWEROFFACTIVE 0x0056
#تعریف_کرو SPI_SETCURSORS 0x0057
#تعریف_کرو SPI_SETICONS 0x0058
#تعریف_کرو SPI_GETDEFAULTINPUTLANG 0x0059
#تعریف_کرو SPI_SETDEFAULTINPUTLANG 0x005A
#تعریف_کرو SPI_SETLANGTOGGLE 0x005B
#تعریف_کرو SPI_GETWINDOWSEXTENSION 0x005C
#تعریف_کرو SPI_SETMOUSETRAILS 0x005D
#تعریف_کرو SPI_GETMOUSETRAILS 0x005E
#تعریف_کرو SPI_SETSCREENSAVERRUNNING 0x0061
#تعریف_کرو SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#تعریف_کرو SPI_GETFILTERKEYS 0x0032
#تعریف_کرو SPI_SETFILTERKEYS 0x0033
#تعریف_کرو SPI_GETTOGGLEKEYS 0x0034
#تعریف_کرو SPI_SETTOGGLEKEYS 0x0035
#تعریف_کرو SPI_GETMOUSEKEYS 0x0036
#تعریف_کرو SPI_SETMOUSEKEYS 0x0037
#تعریف_کرو SPI_GETSHOWSOUNDS 0x0038
#تعریف_کرو SPI_SETSHOWSOUNDS 0x0039
#تعریف_کرو SPI_GETSTICKYKEYS 0x003A
#تعریف_کرو SPI_SETSTICKYKEYS 0x003B
#تعریف_کرو SPI_GETACCESSTIMEOUT 0x003C
#تعریف_کرو SPI_SETACCESSTIMEOUT 0x003D
#تعریف_کرو SPI_GETSERIALKEYS 0x003E
#تعریف_کرو SPI_SETSERIALKEYS 0x003F
#تعریف_کرو SPI_GETSOUNDSENTRY 0x0040
#تعریف_کرو SPI_SETSOUNDSENTRY 0x0041
#تعریف_کرو SPI_GETSNAPTODEFBUTTON 0x005F
#تعریف_کرو SPI_SETSNAPTODEFBUTTON 0x0060
#تعریف_کرو SPI_GETMOUSEHOVERWIDTH 0x0062
#تعریف_کرو SPI_SETMOUSEHOVERWIDTH 0x0063
#تعریف_کرو SPI_GETMOUSEHOVERHEIGHT 0x0064
#تعریف_کرو SPI_SETMOUSEHOVERHEIGHT 0x0065
#تعریف_کرو SPI_GETMOUSEHOVERTIME 0x0066
#تعریف_کرو SPI_SETMOUSEHOVERTIME 0x0067
#تعریف_کرو SPI_GETWHEELSCROLLLINES 0x0068
#تعریف_کرو SPI_SETWHEELSCROLLLINES 0x0069
#تعریف_کرو SPI_GETMENUSHOWDELAY 0x006A
#تعریف_کرو SPI_SETMENUSHOWDELAY 0x006B
#تعریف_کرو SPI_GETSHOWIMEUI 0x006E
#تعریف_کرو SPI_SETSHOWIMEUI 0x006F
#تعریف_کرو SPI_GETMOUSESPEED 0x0070
#تعریف_کرو SPI_SETMOUSESPEED 0x0071
#تعریف_کرو SPI_GETSCREENSAVERRUNNING 0x0072
#تعریف_کرو SPI_GETDESKWALLPAPER 0x0073

#تعریف_کرو SPI_GETACTIVEWINDOWTRACKING 0x1000
#تعریف_کرو SPI_SETACTIVEWINDOWTRACKING 0x1001
#تعریف_کرو SPI_GETMENUANIMATION 0x1002
#تعریف_کرو SPI_SETMENUANIMATION 0x1003
#تعریف_کرو SPI_GETCOMBOBOXANIMATION 0x1004
#تعریف_کرو SPI_SETCOMBOBOXANIMATION 0x1005
#تعریف_کرو SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#تعریف_کرو SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#تعریف_کرو SPI_GETGRADIENTCAPTIONS 0x1008
#تعریف_کرو SPI_SETGRADIENTCAPTIONS 0x1009
#تعریف_کرو SPI_GETKEYBOARDCUES 0x100A
#تعریف_کرو SPI_SETKEYBOARDCUES 0x100B
#تعریف_کرو SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#تعریف_کرو SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#تعریف_کرو SPI_GETACTIVEWNDTRKZORDER 0x100C
#تعریف_کرو SPI_SETACTIVEWNDTRKZORDER 0x100D
#تعریف_کرو SPI_GETHOTTRACKING 0x100E
#تعریف_کرو SPI_SETHOTTRACKING 0x100F
#تعریف_کرو SPI_GETMENUFADE 0x1012
#تعریف_کرو SPI_SETMENUFADE 0x1013
#تعریف_کرو SPI_GETSELECTIONFADE 0x1014
#تعریف_کرو SPI_SETSELECTIONFADE 0x1015
#تعریف_کرو SPI_GETTOOLTIPANIMATION 0x1016
#تعریف_کرو SPI_SETTOOLTIPANIMATION 0x1017
#تعریف_کرو SPI_GETTOOLTIPFADE 0x1018
#تعریف_کرو SPI_SETTOOLTIPFADE 0x1019
#تعریف_کرو SPI_GETCURSORSHADOW 0x101A
#تعریف_کرو SPI_SETCURSORSHADOW 0x101B
#تعریف_کرو SPI_GETMOUSESONAR 0x101C
#تعریف_کرو SPI_SETMOUSESONAR 0x101D
#تعریف_کرو SPI_GETMOUSECLICKLOCK 0x101E
#تعریف_کرو SPI_SETMOUSECLICKLOCK 0x101F
#تعریف_کرو SPI_GETMOUSEVANISH 0x1020
#تعریف_کرو SPI_SETMOUSEVANISH 0x1021
#تعریف_کرو SPI_GETFLATMENU 0x1022
#تعریف_کرو SPI_SETFLATMENU 0x1023
#تعریف_کرو SPI_GETDROPSHADOW 0x1024
#تعریف_کرو SPI_SETDROPSHADOW 0x1025
#تعریف_کرو SPI_GETBLOCKSENDINPUTRESETS 0x1026
#تعریف_کرو SPI_SETBLOCKSENDINPUTRESETS 0x1027
#تعریف_کرو SPI_GETUIEFFECTS 0x103E
#تعریف_کرو SPI_SETUIEFFECTS 0x103F
#تعریف_کرو SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#تعریف_کرو SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#تعریف_کرو SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#تعریف_کرو SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#تعریف_کرو SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#تعریف_کرو SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#تعریف_کرو SPI_GETCARETWIDTH 0x2006
#تعریف_کرو SPI_SETCARETWIDTH 0x2007
#تعریف_کرو SPI_GETMOUSECLICKLOCKTIME 0x2008
#تعریف_کرو SPI_SETMOUSECLICKLOCKTIME 0x2009
#تعریف_کرو SPI_GETFONTSMOOTHINGTYPE 0x200A
#تعریف_کرو SPI_SETFONTSMOOTHINGTYPE 0x200B

#تعریف_کرو FE_FONTSMOOTHINGSTANDARD 0x0001
#تعریف_کرو FE_FONTSMOOTHINGCLEARTYPE 0x0002
#تعریف_کرو FE_FONTSMOOTHINGDOCKING 0x8000

#تعریف_کرو SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#تعریف_کرو SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#تعریف_کرو SPI_GETFOCUSBORDERWIDTH 0x200E
#تعریف_کرو SPI_SETFOCUSBORDERWIDTH 0x200F
#تعریف_کرو SPI_GETFOCUSBORDERHEIGHT 0x2010
#تعریف_کرو SPI_SETFOCUSBORDERHEIGHT 0x2011
#تعریف_کرو SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#تعریف_کرو SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#تعریف_کرو FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#تعریف_کرو FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#تعریف_کرو SPIF_UPDATEINIFILE 0x0001
#تعریف_کرو SPIF_SENDWININICHANGE 0x0002
#تعریف_کرو SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#تعریف_کرو METRICS_USEDEFAULT -1
#جے_تعریف_شدہ _WINGDI_
#جے_بنا_تعریف NOGDI
  تعريفنوع بنية ٹیگ_NONCLIENTMETRICSA {
    UINT cb_ناپ;
    صحيح i_Border_چوڑائی;
    صحيح i_Scroll_چوڑائی;
    صحيح i_Scroll_اچائی;
    صحيح i_Caption_چوڑائی;
    صحيح i_Caption_اچائی;
    LOGFONTA lfCaptionFont;
    صحيح i_Sm_Caption_چوڑائی;
    صحيح i_Sm_Caption_اچائی;
    LOGFONTA lfSmCaptionFont;
    صحيح i_Menu_چوڑائی;
    صحيح i_Menu_اچائی;
    LOGFONTA lfMenuFont;
    LOGFONTA lf_حالت_Font;
    LOGFONTA lf_سنیہا_Font;
  } NONCLIENTMETRICSA,*PNONCLIENTMETRICSA,*LPNONCLIENTMETRICSA;

  تعريفنوع بنية ٹیگ_NONCLIENTMETRICSW {
    UINT cb_ناپ;
    صحيح i_Border_چوڑائی;
    صحيح i_Scroll_چوڑائی;
    صحيح i_Scroll_اچائی;
    صحيح i_Caption_چوڑائی;
    صحيح i_Caption_اچائی;
    LOGFONTW lfCaptionFont;
    صحيح i_Sm_Caption_چوڑائی;
    صحيح i_Sm_Caption_اچائی;
    LOGFONTW lfSmCaptionFont;
    صحيح i_Menu_چوڑائی;
    صحيح i_Menu_اچائی;
    LOGFONTW lfMenuFont;
    LOGFONTW lf_حالت_Font;
    LOGFONTW lf_سنیہا_Font;
  } NONCLIENTMETRICSW,*PNONCLIENTMETRICSW,*LPNONCLIENTMETRICSW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع NONCLIENTMETRICSW NONCLIENTMETRICS;
  تعريفنوع PNONCLIENTMETRICSW PNONCLIENTMETRICS;
  تعريفنوع LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#وإلا
  تعريفنوع NONCLIENTMETRICSA NONCLIENTMETRICS;
  تعريفنوع PNONCLIENTMETRICSA PNONCLIENTMETRICS;
  تعريفنوع LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#جے_انت
#جے_انت
#جے_انت

#تعریف_کرو ARW_BOTTOMLEFT 0x0000L
#تعریف_کرو ARW_BOTTOMRIGHT 0x0001L
#تعریف_کرو ARW_TOPLEFT 0x0002L
#تعریف_کرو ARW_TOPRIGHT 0x0003L
#تعریف_کرو ARW_STARTMASK 0x0003L
#تعریف_کرو ARW_STARTRIGHT 0x0001L
#تعریف_کرو ARW_STARTTOP 0x0002L

#تعریف_کرو ARW_بایاں 0x0000L
#تعریف_کرو ARW_دایاں 0x0000L
#تعریف_کرو ARW_اتے 0x0004L
#تعریف_کرو ARW_تھلے 0x0004L
#تعریف_کرو ARW_HIDE 0x0008L

  تعريفنوع بنية ٹیگ_MINIMIZEDMETRICS {
    UINT cb_ناپ;
    صحيح i_چوڑائی;
    صحيح iHorzGap;
    صحيح iVertGap;
    صحيح iArrange;
  } MINIMIZEDMETRICS,*PMINIMIZEDMETRICS,*LPMINIMIZEDMETRICS;

#جے_تعریف_شدہ _WINGDI_
#جے_بنا_تعریف NOGDI
  تعريفنوع بنية ٹیگ_ICONMETRICSA {
    UINT cb_ناپ;
    صحيح iHorzSpacing;
    صحيح iVertSpacing;
    صحيح iTitleWrap;
    LOGFONTA lfFont;
  } ICONMETRICSA,*PICONMETRICSA,*LPICONMETRICSA;

  تعريفنوع بنية ٹیگ_ICONMETRICSW {
    UINT cb_ناپ;
    صحيح iHorzSpacing;
    صحيح iVertSpacing;
    صحيح iTitleWrap;
    LOGFONTW lfFont;
  } ICONMETRICSW,*PICONMETRICSW,*LPICONMETRICSW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع ICONMETRICSW ICONMETRICS;
  تعريفنوع PICONMETRICSW PICONMETRICS;
  تعريفنوع LPICONMETRICSW LPICONMETRICS;
#وإلا
  تعريفنوع ICONMETRICSA ICONMETRICS;
  تعريفنوع PICONMETRICSA PICONMETRICS;
  تعريفنوع LPICONMETRICSA LPICONMETRICS;
#جے_انت
#جے_انت
#جے_انت

  تعريفنوع بنية ٹیگ_ANIMATIONINFO {
    UINT cb_ناپ;
    صحيح iMinAnimate;
  } ANIMATIONINFO,*LPANIMATIONINFO;

  تعريفنوع بنية ٹیگ_SERIALKEYSA {
    UINT cb_ناپ;
    DWORD dwFlags;
    LPSTR lpsz_سرگرم_پورٹ;
    LPSTR lpsz_پورٹ;
    UINT i_Baud_شرح;
    UINT i_پورٹ_State;
    UINT i_سرگرم;
  } SERIALKEYSA,*LPSERIALKEYSA;

  تعريفنوع بنية ٹیگ_SERIALKEYSW {
    UINT cb_ناپ;
    DWORD dwFlags;
    LPWSTR lpsz_سرگرم_پورٹ;
    LPWSTR lpsz_پورٹ;
    UINT i_Baud_شرح;
    UINT i_پورٹ_State;
    UINT i_سرگرم;
  } SERIALKEYSW,*LPSERIALKEYSW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع SERIALKEYSW SERIALKEYS;
  تعريفنوع LPSERIALKEYSW LPSERIALKEYS;
#وإلا
  تعريفنوع SERIALKEYSA SERIALKEYS;
  تعريفنوع LPSERIALKEYSA LPSERIALKEYS;
#جے_انت

#تعریف_کرو SERKF_SERIALKEYSON 0x00000001
#تعریف_کرو SERKF_دستیاب 0x00000002
#تعریف_کرو SERKF_INDICATOR 0x00000004

  تعريفنوع بنية ٹیگ_HIGHCONTRASTA {
    UINT cb_ناپ;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
  } HIGHCONTRASTA,*LPHIGHCONTRASTA;

  تعريفنوع بنية ٹیگ_HIGHCONTRASTW {
    UINT cb_ناپ;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
  } HIGHCONTRASTW,*LPHIGHCONTRASTW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع HIGHCONTRASTW HIGHCONTRAST;
  تعريفنوع LPHIGHCONTRASTW LPHIGHCONTRAST;
#وإلا
  تعريفنوع HIGHCONTRASTA HIGHCONTRAST;
  تعريفنوع LPHIGHCONTRASTA LPHIGHCONTRAST;
#جے_انت

#تعریف_کرو HCF_HIGHCONTRASTON 0x00000001
#تعریف_کرو HCF_دستیاب 0x00000002
#تعریف_کرو HCF_HOTKEYACTIVE 0x00000004
#تعریف_کرو HCF_CONFIRMHOTKEY 0x00000008
#تعریف_کرو HCF_HOTKEYSOUND 0x00000010
#تعریف_کرو HCF_INDICATOR 0x00000020
#تعریف_کرو HCF_HOTKEYAVAILABLE 0x00000040
#تعریف_کرو HCF_LOGONDESKTOP 0x00000100
#تعریف_کرو HCF_DEFAULTDESKTOP 0x00000200

#تعریف_کرو CDS_UPDATEREGISTRY 0x00000001
#تعریف_کرو CDS_TEST 0x00000002
#تعریف_کرو CDS_FULLSCREEN 0x00000004
#تعریف_کرو CDS_GLOBAL 0x00000008
#تعریف_کرو CDS_سیٹ_PRIMARY 0x00000010
#تعریف_کرو CDS_VIDEOPARAMETERS 0x00000020
#تعریف_کرو CDS_RESET 0x40000000
#تعریف_کرو CDS_NORESET 0x10000000

//gr #include <tvout.h>

#تعریف_کرو DISP_CHANGE_SUCCESSFUL 0
#تعریف_کرو DISP_CHANGE_RESTART 1
#تعریف_کرو DISP_CHANGE_FAILED -1
#تعریف_کرو DISP_CHANGE_BADMODE -2
#تعریف_کرو DISP_CHANGE_NOTUPDATED -3
#تعریف_کرو DISP_CHANGE_BADFLAGS -4
#تعریف_کرو DISP_CHANGE_BADPARAM -5
#تعریف_کرو DISP_CHANGE_BADDUALVIEW -6

#جے_تعریف_شدہ _WINGDI_
#جے_بنا_تعریف NOGDI

#جے_تعریف_شدہ UNICODE
#تعریف_کرو ChangeDisplaySettings ChangeDisplaySettingsW
#تعریف_کرو ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#تعریف_کرو EnumDisplaySettings EnumDisplaySettingsW
#تعریف_کرو EnumDisplaySettingsEx EnumDisplaySettingsExW
#تعریف_کرو EnumDisplayDevices EnumDisplayDevicesW
#وإلا
#تعریف_کرو ChangeDisplaySettings ChangeDisplaySettingsA
#تعریف_کرو ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#تعریف_کرو EnumDisplaySettings EnumDisplaySettingsA
#تعریف_کرو EnumDisplaySettingsEx EnumDisplaySettingsExA
#تعریف_کرو EnumDisplayDevices EnumDisplayDevicesA
#جے_انت

  WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lp_Dev_منوال,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsW(LPDEVMODEW lp_Dev_منوال,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,LPDEVMODEA lp_Dev_منوال,HWND hwnd,DWORD dwflags,LPVOID lParam);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,LPDEVMODEW lp_Dev_منوال,HWND hwnd,DWORD dwflags,LPVOID lParam);

#تعریف_کرو ENUM_CURRENT_SETTINGS ((DWORD)-1)
#تعریف_کرو ENUM_REGISTRY_SETTINGS ((DWORD)-2)

  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD i_منوال_عدد,LPDEVMODEA lp_Dev_منوال);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD i_منوال_عدد,LPDEVMODEW lp_Dev_منوال);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD i_منوال_عدد,LPDEVMODEA lp_Dev_منوال,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD i_منوال_عدد,LPDEVMODEW lp_Dev_منوال,DWORD dwFlags);

#تعریف_کرو EDS_RAWMODE 0x00000002

  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesA(LPCSTR lpDevice,DWORD i_Dev_عدد,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD i_Dev_عدد,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
#جے_انت
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو SystemParametersInfo SystemParametersInfoW
#وإلا
#تعریف_کرو SystemParametersInfo SystemParametersInfoA
#جے_انت

  WINUSERAPI WINBOOL WINAPI SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
  WINUSERAPI WINBOOL WINAPI SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
#جے_انت

  تعريفنوع بنية ٹیگ_FILTERKEYS {
    UINT cb_ناپ;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
  } FILTERKEYS,*LPFILTERKEYS;

#تعریف_کرو FKF_FILTERKEYSON 0x00000001
#تعریف_کرو FKF_دستیاب 0x00000002
#تعریف_کرو FKF_HOTKEYACTIVE 0x00000004
#تعریف_کرو FKF_CONFIRMHOTKEY 0x00000008
#تعریف_کرو FKF_HOTKEYSOUND 0x00000010
#تعریف_کرو FKF_INDICATOR 0x00000020
#تعریف_کرو FKF_CLICKON 0x00000040

  تعريفنوع بنية ٹیگ_STICKYKEYS {
    UINT cb_ناپ;
    DWORD dwFlags;
  } STICKYKEYS,*LPSTICKYKEYS;

#تعریف_کرو SKF_STICKYKEYSON 0x00000001
#تعریف_کرو SKF_دستیاب 0x00000002
#تعریف_کرو SKF_HOTKEYACTIVE 0x00000004
#تعریف_کرو SKF_CONFIRMHOTKEY 0x00000008
#تعریف_کرو SKF_HOTKEYSOUND 0x00000010
#تعریف_کرو SKF_INDICATOR 0x00000020
#تعریف_کرو SKF_AUDIBLEFEEDBACK 0x00000040
#تعریف_کرو SKF_TRISTATE 0x00000080
#تعریف_کرو SKF_TWOKEYSOFF 0x00000100
#تعریف_کرو SKF_LALTLATCHED 0x10000000
#تعریف_کرو SKF_LCTLLATCHED 0x04000000
#تعریف_کرو SKF_LSHIFTLATCHED 0x01000000
#تعریف_کرو SKF_RALTLATCHED 0x20000000
#تعریف_کرو SKF_RCTLLATCHED 0x08000000
#تعریف_کرو SKF_RSHIFTLATCHED 0x02000000
#تعریف_کرو SKF_LWINLATCHED 0x40000000
#تعریف_کرو SKF_RWINLATCHED 0x80000000
#تعریف_کرو SKF_LALTLOCKED 0x00100000
#تعریف_کرو SKF_LCTLLOCKED 0x00040000
#تعریف_کرو SKF_LSHIFTLOCKED 0x00010000
#تعریف_کرو SKF_RALTLOCKED 0x00200000
#تعریف_کرو SKF_RCTLLOCKED 0x00080000
#تعریف_کرو SKF_RSHIFTLOCKED 0x00020000
#تعریف_کرو SKF_LWINLOCKED 0x00400000
#تعریف_کرو SKF_RWINLOCKED 0x00800000

  تعريفنوع بنية ٹیگ_MOUSEKEYS {
    UINT cb_ناپ;
    DWORD dwFlags;
    DWORD i_Max_رفتار;
    DWORD i_ویلا_منزل_Max_رفتار;
    DWORD i_Ctrl_رفتار;
    DWORD dwReserved1;
    DWORD dwReserved2;
  } MOUSEKEYS,*LPMOUSEKEYS;

#تعریف_کرو MKF_MOUSEKEYSON 0x00000001
#تعریف_کرو MKF_دستیاب 0x00000002
#تعریف_کرو MKF_HOTKEYACTIVE 0x00000004
#تعریف_کرو MKF_CONFIRMHOTKEY 0x00000008
#تعریف_کرو MKF_HOTKEYSOUND 0x00000010
#تعریف_کرو MKF_INDICATOR 0x00000020
#تعریف_کرو MKF_MODIFIERS 0x00000040
#تعریف_کرو MKF_REPLACENUMBERS 0x00000080
#تعریف_کرو MKF_LEFTBUTTONSEL 0x10000000
#تعریف_کرو MKF_RIGHTBUTTONSEL 0x20000000
#تعریف_کرو MKF_LEFTBUTTONDOWN 0x01000000
#تعریف_کرو MKF_RIGHTBUTTONDOWN 0x02000000
#تعریف_کرو MKF_MOUSEMODE 0x80000000

  تعريفنوع بنية ٹیگ_ACCESSTIMEOUT {
    UINT cb_ناپ;
    DWORD dwFlags;
    DWORD i_ویلا_باہرلا_MSec;
  } ACCESSTIMEOUT,*LPACCESSTIMEOUT;

#تعریف_کرو ATF_TIMEOUTON 0x00000001
#تعریف_کرو ATF_ONOFFFEEDBACK 0x00000002

#تعریف_کرو SSGF_NONE 0
#تعریف_کرو SSGF_DISPLAY 3

#تعریف_کرو SSTF_NONE 0
#تعریف_کرو SSTF_CHARS 1
#تعریف_کرو SSTF_BORDER 2
#تعریف_کرو SSTF_DISPLAY 3

#تعریف_کرو SSWF_NONE 0
#تعریف_کرو SSWF_TITLE 1
#تعریف_کرو SSWF_کھڑکی 2
#تعریف_کرو SSWF_DISPLAY 3
#تعریف_کرو SSWF_CUSTOM 4

  تعريفنوع بنية ٹیگ_SOUNDSENTRYA {
    UINT cb_ناپ;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_بٹ;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYA,*LPSOUNDSENTRYA;

  تعريفنوع بنية ٹیگ_SOUNDSENTRYW {
    UINT cb_ناپ;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_بٹ;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYW,*LPSOUNDSENTRYW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع SOUNDSENTRYW SOUNDSENTRY;
  تعريفنوع LPSOUNDSENTRYW LPSOUNDSENTRY;
#وإلا
  تعريفنوع SOUNDSENTRYA SOUNDSENTRY;
  تعريفنوع LPSOUNDSENTRYA LPSOUNDSENTRY;
#جے_انت

#تعریف_کرو SSF_SOUNDSENTRYON 0x00000001
#تعریف_کرو SSF_دستیاب 0x00000002
#تعریف_کرو SSF_INDICATOR 0x00000004

  تعريفنوع بنية ٹیگ_TOGGLEKEYS {
    UINT cb_ناپ;
    DWORD dwFlags;
  } TOGGLEKEYS,*LPTOGGLEKEYS;

#تعریف_کرو TKF_TOGGLEKEYSON 0x00000001
#تعریف_کرو TKF_دستیاب 0x00000002
#تعریف_کرو TKF_HOTKEYACTIVE 0x00000004
#تعریف_کرو TKF_CONFIRMHOTKEY 0x00000008
#تعریف_کرو TKF_HOTKEYSOUND 0x00000010
#تعریف_کرو TKF_INDICATOR 0x00000020

  WINUSERAPI VOID WINAPI سیٹ_Debug_Error_Level(DWORD dwLevel);

#تعریف_کرو SLE_ERROR 0x00000001
#تعریف_کرو SLE_MINORERROR 0x00000002
#تعریف_کرو SLE_WARNING 0x00000003

  WINUSERAPI VOID WINAPI سیٹ_آخری_Error_Ex(DWORD dw_Err_کوڈ,DWORD dwType);
  WINUSERAPI صحيح WINAPI اندرونی_Get_کھڑکی_متن(HWND hWnd,LPWSTR pString,صحيح cch_Max_گنتی);

#جے_تعریف_شدہ WINNT
  WINUSERAPI WINBOOL WINAPI سرا_Task(HWND hWnd,WINBOOL f_Shut_تھلے,WINBOOL fForce);
#جے_انت

#تعریف_کرو MONITOR_DEFAULTTONULL 0x00000000
#تعریف_کرو MONITOR_DEFAULTTOPRIMARY 0x00000001
#تعریف_کرو MONITOR_DEFAULTTONEAREST 0x00000002

  WINUSERAPI HMONITOR WINAPI Monitor_From_نقطہ(نقطہ_3 pt,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromRect(LPCRECT lprc,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI Monitor_From_کھڑکی(HWND hwnd,DWORD dwFlags);

#تعریف_کرو MONITORINFOF_PRIMARY 0x00000001

#جے_بنا_تعریف CCHDEVICENAME
#تعریف_کرو CCHDEVICENAME 32
#جے_انت

  تعريفنوع بنية ٹیگ_MONITORINFO {
    DWORD cb_ناپ;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
  } MONITORINFO,*LPMONITORINFO;

#جے_تعریف_شدہ __cplusplus
  تعريفنوع بنية ٹیگ_MONITORINFOEXA : عام ٹیگ_MONITORINFO {
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  تعريفنوع بنية ٹیگ_MONITORINFOEXW : عام ٹیگ_MONITORINFO {
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع MONITORINFOEXW MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXW LPMONITORINFOEX;
#وإلا
  تعريفنوع MONITORINFOEXA MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXA LPMONITORINFOEX;
#جے_انت
#وإلا
  تعريفنوع بنية ٹیگ_MONITORINFOEXA {
    MONITORINFO mi;
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  تعريفنوع بنية ٹیگ_MONITORINFOEXW {
    MONITORINFO mi;
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع MONITORINFOEXW MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXW LPMONITORINFOEX;
#وإلا
  تعريفنوع MONITORINFOEXA MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXA LPMONITORINFOEX;
#جے_انت
#جے_انت

#جے_تعریف_شدہ UNICODE 
#تعریف_کرو GetMonitorInfo GetMonitorInfoW
#وإلا
#تعریف_کرو GetMonitorInfo GetMonitorInfoA
#جے_انت

  WINUSERAPI WINBOOL WINAPI GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
  WINUSERAPI WINBOOL WINAPI GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);

  تعريفنوع WINBOOL (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

  WINUSERAPI WINBOOL WINAPI EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dw_انکڑے);

#جے_بنا_تعریف NOWINABLE
  WINUSERAPI VOID WINAPI NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG id_بچہ);

  تعريفنوع VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK hWinEventHook,DWORD event,HWND hwnd,LONG idObject,LONG id_بچہ,DWORD idEventThread,DWORD dwms_Event_ویلا);

  WINUSERAPI HWINEVENTHOOK WINAPI سیٹ_Win_Event_Hook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI IsWinEventHookInstalled(DWORD event);

#تعریف_کرو WINEVENT_OUTOFCONTEXT 0x0000
#تعریف_کرو WINEVENT_SKIPOWNTHREAD 0x0001
#تعریف_کرو WINEVENT_SKIPOWNPROCESS 0x0002
#تعریف_کرو WINEVENT_INCONTEXT 0x0004

  WINUSERAPI WINBOOL WINAPI UnhookWinEvent(HWINEVENTHOOK hWinEventHook);

#تعریف_کرو CHILDID_SELF 0
#تعریف_کرو INDEXID_OBJECT 0
#تعریف_کرو INDEXID_CONTAINER 0

#تعریف_کرو OBJID_کھڑکی ((LONG)0x00000000)
#تعریف_کرو OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#تعریف_کرو OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#تعریف_کرو OBJID_MENU ((LONG)0xFFFFFFFD)
#تعریف_کرو OBJID_CLIENT ((LONG)0xFFFFFFFC)
#تعریف_کرو OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#تعریف_کرو OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#تعریف_کرو OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#تعریف_کرو OBJID_CARET ((LONG)0xFFFFFFF8)
#تعریف_کرو OBJID_CURSOR ((LONG)0xFFFFFFF7)
#تعریف_کرو OBJID_ALERT ((LONG)0xFFFFFFF6)
#تعریف_کرو OBJID_SOUND ((LONG)0xFFFFFFF5)
#تعریف_کرو OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#تعریف_کرو OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#تعریف_کرو EVENT_MIN 0x00000001
#تعریف_کرو EVENT_MAX 0x7FFFFFFF

#تعریف_کرو EVENT_SYSTEM_SOUND 0x0001
#تعریف_کرو EVENT_SYSTEM_ALERT 0x0002
#تعریف_کرو EVENT_SYSTEM_FOREGROUND 0x0003
#تعریف_کرو EVENT_SYSTEM_MENUSTART 0x0004
#تعریف_کرو EVENT_SYSTEM_MENUEND 0x0005
#تعریف_کرو EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#تعریف_کرو EVENT_SYSTEM_MENUPOPUPEND 0x0007
#تعریف_کرو EVENT_SYSTEM_CAPTURESTART 0x0008
#تعریف_کرو EVENT_SYSTEM_CAPTUREEND 0x0009
#تعریف_کرو EVENT_SYSTEM_MOVESIZESTART 0x000A
#تعریف_کرو EVENT_SYSTEM_MOVESIZEEND 0x000B
#تعریف_کرو EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#تعریف_کرو EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#تعریف_کرو EVENT_SYSTEM_DRAGDROPSTART 0x000E
#تعریف_کرو EVENT_SYSTEM_DRAGDROPEND 0x000F
#تعریف_کرو EVENT_SYSTEM_DIALOGSTART 0x0010
#تعریف_کرو EVENT_SYSTEM_DIALOGEND 0x0011
#تعریف_کرو EVENT_SYSTEM_SCROLLINGSTART 0x0012
#تعریف_کرو EVENT_SYSTEM_SCROLLINGEND 0x0013
#تعریف_کرو EVENT_SYSTEM_SWITCHSTART 0x0014
#تعریف_کرو EVENT_SYSTEM_SWITCHEND 0x0015
#تعریف_کرو EVENT_SYSTEM_MINIMIZESTART 0x0016
#تعریف_کرو EVENT_SYSTEM_MINIMIZEEND 0x0017

#تعریف_کرو EVENT_CONSOLE_CARET 0x4001
#تعریف_کرو EVENT_CONSOLE_UPDATE_REGION 0x4002
#تعریف_کرو EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#تعریف_کرو EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#تعریف_کرو EVENT_CONSOLE_LAYOUT 0x4005
#تعریف_کرو EVENT_CONSOLE_شروع_APPLICATION 0x4006
#تعریف_کرو EVENT_CONSOLE_سرا_APPLICATION 0x4007

#تعریف_کرو CONSOLE_APPLICATION_16_ثنائی_ہندسہ 0x0001

#تعریف_کرو CONSOLE_CARET_SELECTION 0x0001
#تعریف_کرو CONSOLE_CARET_VISIBLE 0x0002

#تعریف_کرو EVENT_OBJECT_CREATE 0x8000
#تعریف_کرو EVENT_OBJECT_DESTROY 0x8001
#تعریف_کرو EVENT_OBJECT_SHOW 0x8002
#تعریف_کرو EVENT_OBJECT_HIDE 0x8003
#تعریف_کرو EVENT_OBJECT_REORDER 0x8004

#تعریف_کرو EVENT_OBJECT_FOCUS 0x8005
#تعریف_کرو EVENT_OBJECT_SELECTION 0x8006
#تعریف_کرو EVENT_OBJECT_SELECTIONADD 0x8007
#تعریف_کرو EVENT_OBJECT_SELECTIONREMOVE 0x8008
#تعریف_کرو EVENT_OBJECT_SELECTIONWITHIN 0x8009

#تعریف_کرو EVENT_OBJECT_STATECHANGE 0x800A

#تعریف_کرو EVENT_OBJECT_LOCATIONCHANGE 0x800B

#تعریف_کرو EVENT_OBJECT_NAMECHANGE 0x800C
#تعریف_کرو EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#تعریف_کرو EVENT_OBJECT_VALUECHANGE 0x800E
#تعریف_کرو EVENT_OBJECT_PARENTCHANGE 0x800F
#تعریف_کرو EVENT_OBJECT_HELPCHANGE 0x8010
#تعریف_کرو EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#تعریف_کرو EVENT_OBJECT_ACCELERATORCHANGE 0x8012

#تعریف_کرو SOUND_SYSTEM_STARTUP 1
#تعریف_کرو SOUND_SYSTEM_SHUTDOWN 2
#تعریف_کرو SOUND_SYSTEM_BEEP 3
#تعریف_کرو SOUND_SYSTEM_ERROR 4
#تعریف_کرو SOUND_SYSTEM_QUESTION 5
#تعریف_کرو SOUND_SYSTEM_WARNING 6
#تعریف_کرو SOUND_SYSTEM_INFORMATION 7
#تعریف_کرو SOUND_SYSTEM_MAXIMIZE 8
#تعریف_کرو SOUND_SYSTEM_MINIMIZE 9
#تعریف_کرو SOUND_SYSTEM_RESTOREUP 10
#تعریف_کرو SOUND_SYSTEM_RESTOREDOWN 11
#تعریف_کرو SOUND_SYSTEM_APPSTART 12
#تعریف_کرو SOUND_SYSTEM_FAULT 13
#تعریف_کرو SOUND_SYSTEM_APPEND 14
#تعریف_کرو SOUND_SYSTEM_MENUCOMMAND 15
#تعریف_کرو SOUND_SYSTEM_MENUPOPUP 16
#تعریف_کرو CSOUND_SYSTEM 16

#تعریف_کرو ALERT_SYSTEM_INFORMATIONAL 1
#تعریف_کرو ALERT_SYSTEM_WARNING 2
#تعریف_کرو ALERT_SYSTEM_ERROR 3
#تعریف_کرو ALERT_SYSTEM_QUERY 4
#تعریف_کرو ALERT_SYSTEM_CRITICAL 5
#تعریف_کرو CALERT_SYSTEM 6

  تعريفنوع بنية ٹیگ_GUITHREADINFO {
    DWORD cb_ناپ;
    DWORD flags;
    HWND hwnd_سرگرم;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwnd_Move_ناپ;
    HWND hwndCaret;
    RECT rcCaret;
  } GUITHREADINFO,*PGUITHREADINFO,*LPGUITHREADINFO;

#تعریف_کرو GUI_CARETBLINKING 0x00000001
#تعریف_کرو GUI_INMOVESIZE 0x00000002
#تعریف_کرو GUI_INMENUMODE 0x00000004
#تعریف_کرو GUI_SYSTEMMENUMODE 0x00000008
#تعریف_کرو GUI_POPUPMENUMODE 0x00000010
#تعریف_کرو GUI_16BITTASK 0x00000020

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_کھڑکی_Module_File_Name Get_کھڑکی_Module_File_Name_W
#وإلا
#تعریف_کرو Get_کھڑکی_Module_File_Name Get_کھڑکی_Module_File_Name_A
#جے_انت

  WINUSERAPI WINBOOL WINAPI GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui);
  WINUSERAPI UINT WINAPI Get_کھڑکی_Module_File_Name_A(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
  WINUSERAPI UINT WINAPI Get_کھڑکی_Module_File_Name_W(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);

#جے_بنا_تعریف NO_STATE_FLAGS
#تعریف_کرو STATE_SYSTEM_UNAVAILABLE 0x00000001
#تعریف_کرو STATE_SYSTEM_SELECTED 0x00000002
#تعریف_کرو STATE_SYSTEM_FOCUSED 0x00000004
#تعریف_کرو STATE_SYSTEM_PRESSED 0x00000008
#تعریف_کرو STATE_SYSTEM_CHECKED 0x00000010
#تعریف_کرو STATE_SYSTEM_MIXED 0x00000020
#تعریف_کرو STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#تعریف_کرو STATE_SYSTEM_READONLY 0x00000040
#تعریف_کرو STATE_SYSTEM_HOTTRACKED 0x00000080
#تعریف_کرو STATE_SYSTEM_DEFAULT 0x00000100
#تعریف_کرو STATE_SYSTEM_EXPANDED 0x00000200
#تعریف_کرو STATE_SYSTEM_COLLAPSED 0x00000400
#تعریف_کرو STATE_SYSTEM_BUSY 0x00000800
#تعریف_کرو STATE_SYSTEM_FLOATING 0x00001000
#تعریف_کرو STATE_SYSTEM_MARQUEED 0x00002000
#تعریف_کرو STATE_SYSTEM_ANIMATED 0x00004000
#تعریف_کرو STATE_SYSTEM_INVISIBLE 0x00008000
#تعریف_کرو STATE_SYSTEM_OFFSCREEN 0x00010000
#تعریف_کرو STATE_SYSTEM_SIZEABLE 0x00020000
#تعریف_کرو STATE_SYSTEM_MOVEABLE 0x00040000
#تعریف_کرو STATE_SYSTEM_SELFVOICING 0x00080000
#تعریف_کرو STATE_SYSTEM_FOCUSABLE 0x00100000
#تعریف_کرو STATE_SYSTEM_SELECTABLE 0x00200000
#تعریف_کرو STATE_SYSTEM_LINKED 0x00400000
#تعریف_کرو STATE_SYSTEM_TRAVERSED 0x00800000
#تعریف_کرو STATE_SYSTEM_MULTISELECTABLE 0x01000000
#تعریف_کرو STATE_SYSTEM_EXTSELECTABLE 0x02000000
#تعریف_کرو STATE_SYSTEM_ALERT_کم 0x04000000
#تعریف_کرو STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#تعریف_کرو STATE_SYSTEM_ALERT_بلند 0x10000000
#تعریف_کرو STATE_SYSTEM_PROTECTED 0x20000000
#تعریف_کرو STATE_SYSTEM_VALID 0x3FFFFFFF
#جے_انت

#تعریف_کرو CCHILDREN_TITLEBAR 5
#تعریف_کرو CCHILDREN_SCROLLBAR 5

  تعريفنوع بنية ٹیگ_CURSORINFO {
    DWORD cb_ناپ;
    DWORD flags;
    HCURSOR hCursor;
    نقطہ_3 ptScreenPos;
  } CURSORINFO,*PCURSORINFO,*LPCURSORINFO;

#تعریف_کرو CURSOR_SHOWING 0x00000001

  WINUSERAPI WINBOOL WINAPI GetCursorInfo(PCURSORINFO pci);

  تعريفنوع بنية ٹیگ_WINDOWINFO {
    DWORD cb_ناپ;
    RECT rc_کھڑکی;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dw_کھڑکی_حالت;
    UINT cx_کھڑکی_Borders;
    UINT cy_کھڑکی_Borders;
    ATOM atom_کھڑکی_Type;
    لفظ_3 w_Creator_نسخہ;
  } WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;

#تعریف_کرو WS_ACTIVECAPTION 0x0001

  WINUSERAPI WINBOOL WINAPI Get_کھڑکی_Info(HWND hwnd,PWINDOWINFO pwi);

  تعريفنوع بنية ٹیگ_TITLEBARINFO {
    DWORD cb_ناپ;
    RECT rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  } TITLEBARINFO,*PTITLEBARINFO,*LPTITLEBARINFO;

  WINUSERAPI WINBOOL WINAPI GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti);

  تعريفنوع بنية ٹیگ_MENUBARINFO {
    DWORD cb_ناپ;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    WINBOOL fBarFocused:1;
    WINBOOL fFocused:1;
  } MENUBARINFO,*PMENUBARINFO,*LPMENUBARINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuBarInfo(HWND hwnd,LONG idObject,LONG id_شے,PMENUBARINFO pmbi);

  تعريفنوع بنية ٹیگ_SCROLLBARINFO {
    DWORD cb_ناپ;
    RECT rcScrollBar;
    صحيح dxy_سطر_Button;
    صحيح xy_Thumb_چوٹی;
    صحيح xyThumbBottom;
    صحيح reserved;
    DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
  } SCROLLBARINFO,*PSCROLLBARINFO,*LPSCROLLBARINFO;

  WINUSERAPI WINBOOL WINAPI GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);

  تعريفنوع بنية ٹیگ_COMBOBOXINFO {
    DWORD cb_ناپ;
    RECT rc_شے;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwnd_شے;
    HWND hwndList;
  } COMBOBOXINFO,*PCOMBOBOXINFO,*LPCOMBOBOXINFO;

  WINUSERAPI WINBOOL WINAPI GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi);

#تعریف_کرو GA_ماپا 1
#تعریف_کرو GA_جڑ 2
#تعریف_کرو GA_ROOTOWNER 3

  WINUSERAPI HWND WINAPI GetAncestor(HWND hwnd,UINT gaFlags);
  WINUSERAPI HWND WINAPI Real_بچہ_کھڑکی_From_نقطہ(HWND hwnd_ماپا_2,نقطہ_3 pt_ماپا_Client_Coords);
  WINUSERAPI UINT WINAPI Real_Get_کھڑکی_Class_A(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
  WINUSERAPI UINT WINAPI Real_Get_کھڑکی_Class_W(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
#جے_تعریف_شدہ UNICODE
#تعریف_کرو Real_Get_کھڑکی_Class Real_Get_کھڑکی_Class_W
#وإلا
#تعریف_کرو Real_Get_کھڑکی_Class Real_Get_کھڑکی_Class_A
#جے_انت

  تعريفنوع بنية ٹیگ_ALTTABINFO {
    DWORD cb_ناپ;
    صحيح c_اشیاء;
    صحيح cColumns;
    صحيح c_صفاں;
    صحيح i_خانہ_Focus;
    صحيح i_صف_Focus;
    صحيح cx_شے;
    صحيح cy_شے;
    نقطہ_3 pt_شروع;
  } ALTTABINFO,*PALTTABINFO,*LPALTTABINFO;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو GetAltTabInfo GetAltTabInfoW
#وإلا
#تعریف_کرو GetAltTabInfo GetAltTabInfoA
#جے_انت

  WINUSERAPI WINBOOL WINAPI GetAltTabInfoA(HWND hwnd,صحيح i_شے,PALTTABINFO pati,LPSTR psz_شے_متن,UINT cch_شے_متن);
  WINUSERAPI WINBOOL WINAPI GetAltTabInfoW(HWND hwnd,صحيح i_شے,PALTTABINFO pati,LPWSTR psz_شے_متن,UINT cch_شے_متن);
  WINUSERAPI DWORD WINAPI GetListBoxInfo(HWND hwnd);
#جے_انت

  WINUSERAPI WINBOOL WINAPI جندرا_Work_Station(VOID);
  WINUSERAPI WINBOOL WINAPI UserHandleGrantAccess(HANDLE hUserHandle,HANDLE h_کم,WINBOOL bGrant);

  DECLARE_HANDLE(HRAWINPUT);

#تعریف_کرو GET_RAWINPUT_کوڈ_WPARAM(wParam) ((wParam) & 0xff)

#تعریف_کرو RIM_داخلہ 0
#تعریف_کرو RIM_INPUTSINK 1

  تعريفنوع بنية ٹیگ_RAWINPUTHEADER {
    DWORD dwType;
    DWORD dw_ناپ;
    HANDLE hDevice;
    WPARAM wParam;
  } RAWINPUTHEADER,*PRAWINPUTHEADER,*LPRAWINPUTHEADER;

#تعریف_کرو RIM_TYPEMOUSE 0
#تعریف_کرو RIM_TYPEKEYBOARD 1
#تعریف_کرو RIM_TYPEHID 2

  تعريفنوع بنية ٹیگ_RAWMOUSE {
    USHORT usFlags;
    اتحاد {
      ULONG ulButtons;
      بنية {
	USHORT usButtonFlags;
	USHORT us_Button_انکڑے;
      };
    };
    ULONG ulRawButtons;
    LONG l_آخری_X;
    LONG l_آخری_Y;
    ULONG ulExtraInformation;
  } RAWMOUSE,*PRAWMOUSE,*LPRAWMOUSE;

#تعریف_کرو RI_MOUSE_بایاں_BUTTON_تھلے 0x0001
#تعریف_کرو RI_MOUSE_بایاں_BUTTON_اتے 0x0002
#تعریف_کرو RI_MOUSE_دایاں_BUTTON_تھلے 0x0004
#تعریف_کرو RI_MOUSE_دایاں_BUTTON_اتے 0x0008
#تعریف_کرو RI_MOUSE_درمیان_BUTTON_تھلے 0x0010
#تعریف_کرو RI_MOUSE_درمیان_BUTTON_اتے 0x0020

#تعریف_کرو RI_MOUSE_BUTTON_1_تھلے RI_MOUSE_بایاں_BUTTON_تھلے
#تعریف_کرو RI_MOUSE_BUTTON_1_اتے RI_MOUSE_بایاں_BUTTON_اتے
#تعریف_کرو RI_MOUSE_BUTTON_2_تھلے RI_MOUSE_دایاں_BUTTON_تھلے
#تعریف_کرو RI_MOUSE_BUTTON_2_اتے RI_MOUSE_دایاں_BUTTON_اتے
#تعریف_کرو RI_MOUSE_BUTTON_3_تھلے RI_MOUSE_درمیان_BUTTON_تھلے
#تعریف_کرو RI_MOUSE_BUTTON_3_اتے RI_MOUSE_درمیان_BUTTON_اتے

#تعریف_کرو RI_MOUSE_BUTTON_4_تھلے 0x0040
#تعریف_کرو RI_MOUSE_BUTTON_4_اتے 0x0080
#تعریف_کرو RI_MOUSE_BUTTON_5_تھلے 0x0100
#تعریف_کرو RI_MOUSE_BUTTON_5_اتے 0x0200

#تعریف_کرو RI_MOUSE_WHEEL 0x0400

#تعریف_کرو MOUSE_MOVE_RELATIVE 0
#تعریف_کرو MOUSE_MOVE_ABSOLUTE 1
#تعریف_کرو MOUSE_VIRTUAL_DESKTOP 0x02
#تعریف_کرو MOUSE_گن_بدلیا 0x04

  تعريفنوع بنية ٹیگ_RAWKEYBOARD {
    USHORT Make_کوڈ;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT سنیہا_3;
    ULONG ExtraInformation;
  } RAWKEYBOARD,*PRAWKEYBOARD,*LPRAWKEYBOARD;

#تعریف_کرو KEYBOARD_OVERRUN_MAKE_کوڈ 0xFF

#تعریف_کرو RI_کلید_MAKE 0
#تعریف_کرو RI_کلید_BREAK 1
#تعریف_کرو RI_کلید_E0 2
#تعریف_کرو RI_کلید_E1 4
#تعریف_کرو RI_کلید_TERMSRV_سیٹ_LED 8
#تعریف_کرو RI_کلید_TERMSRV_SHADOW 0x10

  تعريفنوع بنية ٹیگ_RAWHID {
    DWORD dw_ناپ_Hid;
    DWORD dw_گنتی;
    BYTE b_Raw_انکڑے[1];
  } RAWHID,*PRAWHID,*LPRAWHID;

  تعريفنوع بنية ٹیگ_RAWINPUT {
    RAWINPUTHEADER سرخی;
    اتحاد {
      RAWMOUSE mouse;
      RAWKEYBOARD keyboard;
      RAWHID hid;
    } انکڑے;
  } RAWINPUT,*PRAWINPUT,*LPRAWINPUT;

#جے_تعریف_شدہ _WIN64
#تعریف_کرو RAWINPUT_ALIGN(x) (((x) + حجم(QWORD) - 1) & ~(حجم(QWORD) - 1))
#وإلا
#تعریف_کرو RAWINPUT_ALIGN(x) (((x) + حجم(DWORD) - 1) & ~(حجم(DWORD) - 1))
#جے_انت

#تعریف_کرو NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->سرخی.dw_ناپ)))

#تعریف_کرو RID_داخلہ 0x10000003
#تعریف_کرو RID_سرخی 0x10000005

  WINUSERAPI UINT WINAPI Get_Raw_داخلہ_انکڑے(HRAWINPUT h_Raw_داخلہ,UINT uiCommand,LPVOID p_انکڑے,PUINT pcb_ناپ,UINT cb_ناپ_سرخی);

#تعریف_کرو RIDI_PREPARSEDDATA 0x20000005
#تعریف_کرو RIDI_DEVICENAME 0x20000007
#تعریف_کرو RIDI_DEVICEINFO 0x2000000b

  تعريفنوع بنية ٹیگ_RID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dw_نمبر_دا_Buttons;
    DWORD dw_Sample_شرح;
  } RID_DEVICE_INFO_MOUSE,*PRID_DEVICE_INFO_MOUSE;

  تعريفنوع بنية ٹیگ_RID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dw_Keyboard_منوال;
    DWORD dw_نمبر_دا_Function_کلیدیں;
    DWORD dw_نمبر_دا_Indicators;
    DWORD dw_نمبر_دا_کلیدیں_کل;
  } RID_DEVICE_INFO_KEYBOARD,*PRID_DEVICE_INFO_KEYBOARD;

  تعريفنوع بنية ٹیگ_RID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dw_ضرب_حاصل_Id;
    DWORD dw_نسخہ_نمبر;
    USHORT us_Usage_ورقہ;
    USHORT usUsage;
  } RID_DEVICE_INFO_HID,*PRID_DEVICE_INFO_HID;

  تعريفنوع بنية ٹیگ_RID_DEVICE_INFO {
    DWORD cb_ناپ;
    DWORD dwType;
    اتحاد {
      RID_DEVICE_INFO_MOUSE mouse;
      RID_DEVICE_INFO_KEYBOARD keyboard;
      RID_DEVICE_INFO_HID hid;
    };
  } RID_DEVICE_INFO,*PRID_DEVICE_INFO,*LPRID_DEVICE_INFO;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_Raw_داخلہ_Device_Info Get_Raw_داخلہ_Device_Info_W
#وإلا
#تعریف_کرو Get_Raw_داخلہ_Device_Info Get_Raw_داخلہ_Device_Info_A
#جے_انت

  WINUSERAPI UINT WINAPI Get_Raw_داخلہ_Device_Info_A(HANDLE hDevice,UINT uiCommand,LPVOID p_انکڑے,PUINT pcb_ناپ);
  WINUSERAPI UINT WINAPI Get_Raw_داخلہ_Device_Info_W(HANDLE hDevice,UINT uiCommand,LPVOID p_انکڑے,PUINT pcb_ناپ);
  WINUSERAPI UINT WINAPI Get_Raw_داخلہ_بفر(PRAWINPUT p_انکڑے,PUINT pcb_ناپ,UINT cb_ناپ_سرخی);

  تعريفنوع بنية ٹیگ_RAWINPUTDEVICE {
    USHORT us_Usage_ورقہ;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwnd_نشانہ;
  } RAWINPUTDEVICE,*PRAWINPUTDEVICE,*LPRAWINPUTDEVICE;

  تعريفنوع CONST RAWINPUTDEVICE *PCRAWINPUTDEVICE;

#تعریف_کرو RIDEV_REMOVE 0x00000001
#تعریف_کرو RIDEV_EXCLUDE 0x00000010
#تعریف_کرو RIDEV_PAGEONLY 0x00000020
#تعریف_کرو RIDEV_NOLEGACY 0x00000030
#تعریف_کرو RIDEV_INPUTSINK 0x00000100
#تعریف_کرو RIDEV_CAPTUREMOUSE 0x00000200
#تعریف_کرو RIDEV_NOHOTKEYS 0x00000200
#تعریف_کرو RIDEV_APPKEYS 0x00000400
#تعریف_کرو RIDEV_EXMODEMASK 0x000000F0
#تعریف_کرو RIDEV_EXMODE(منوال) ((منوال) & RIDEV_EXMODEMASK)

  WINUSERAPI WINBOOL WINAPI رجسٹر_Raw_داخلہ_Devices(PCRAWINPUTDEVICE p_Raw_داخلہ_Devices,UINT ui_عدد_Devices,UINT cb_ناپ);
  WINUSERAPI UINT WINAPI Get_Registered_Raw_داخلہ_Devices(PRAWINPUTDEVICE p_Raw_داخلہ_Devices,PUINT pui_عدد_Devices,UINT cb_ناپ);

  تعريفنوع بنية ٹیگ_RAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
  } RAWINPUTDEVICELIST,*PRAWINPUTDEVICELIST;

  WINUSERAPI UINT WINAPI Get_Raw_داخلہ_Device_List(PRAWINPUTDEVICELIST p_Raw_داخلہ_Device_List,PUINT pui_عدد_Devices,UINT cb_ناپ);
  WINUSERAPI LRESULT WINAPI Def_Raw_داخلہ_Proc(PRAWINPUT *pa_Raw_داخلہ,INT n_داخلہ,UINT cb_ناپ_سرخی);

#جے_انت /* NOUSER */

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
