/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _WINUSER_
#وصف_ڪريو _WINUSER_

#وصف_ڪريو WINUSERAPI DECLSPEC_IMPORT

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WINVER
#وصف_ڪريو WINVER 0x0502
#جيڪڏهن_پورو

#ضمن <stdarg.h>

#جيڪڏهن_وصف_نه_ٿيل NOUSER
  تعريفنوع HANDLE HDWP;
  تعريفنوع VOID MENUTEMPLATEA;
  تعريفنوع VOID MENUTEMPLATEW;
  تعريفنوع PVOID LPMENUTEMPLATEA;
  تعريفنوع PVOID LPMENUTEMPLATEW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع MENUTEMPLATEW MENUTEMPLATE;
  تعريفنوع LPMENUTEMPLATEW LPMENUTEMPLATE;
#وإلا
  تعريفنوع MENUTEMPLATEA MENUTEMPLATE;
  تعريفنوع LPMENUTEMPLATEA LPMENUTEMPLATE;
#جيڪڏهن_پورو

  تعريفنوع LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
  تعريفنوع INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
  تعريفنوع VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
  تعريفنوع WINBOOL (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,صحيح);
  تعريفنوع WINBOOL (CALLBACK *WNDENUMPROC)(HWND,LPARAM);
  تعريفنوع LRESULT (CALLBACK *HOOKPROC)(صحيح ڪوڊ,WPARAM wParam,LPARAM lParam);
  تعريفنوع VOID (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
  تعريفنوع صحيح (CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch,صحيح ichCurrent,صحيح cch,صحيح ڪوڊ);
  تعريفنوع صحيح (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch,صحيح ichCurrent,صحيح cch,صحيح ڪوڊ);
  تعريفنوع WINBOOL (CALLBACK *DRAWSTATEPROC)(HDC hdc,LPARAM l_معلومات,WPARAM w_معلومات,صحيح cx,صحيح cy);

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع PROPENUMPROCW PROPENUMPROC;
  تعريفنوع PROPENUMPROCEXW PROPENUMPROCEX;
  تعريفنوع EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#وإلا
  تعريفنوع PROPENUMPROCA PROPENUMPROC;
  تعريفنوع PROPENUMPROCEXA PROPENUMPROCEX;
  تعريفنوع EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#جيڪڏهن_پورو

  تعريفنوع WINBOOL (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
  تعريفنوع WINBOOL (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
  تعريفنوع NAMEENUMPROCA WINSTAENUMPROCA;
  تعريفنوع NAMEENUMPROCA DESKTOPENUMPROCA;
  تعريفنوع NAMEENUMPROCW WINSTAENUMPROCW;
  تعريفنوع NAMEENUMPROCW DESKTOPENUMPROCW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WINSTAENUMPROCW WINSTAENUMPROC;
  تعريفنوع DESKTOPENUMPROCW DESKTOPENUMPROC;
#وإلا
  تعريفنوع WINSTAENUMPROCA WINSTAENUMPROC;
  تعريفنوع DESKTOPENUMPROCA DESKTOPENUMPROC;
#جيڪڏهن_پورو

#وصف_ڪريو IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)
#وصف_ڪريو MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((لفظ_3)(i))))
#وصف_ڪريو MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((لفظ_3)(i))))
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو MAKEINTRESOURCE MAKEINTRESOURCEW
#وإلا
#وصف_ڪريو MAKEINTRESOURCE MAKEINTRESOURCEA
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NORESOURCE

#وصف_ڪريو RT_CURSOR MAKEINTRESOURCE(1)
#وصف_ڪريو RT_BITMAP MAKEINTRESOURCE(2)
#وصف_ڪريو RT_ICON MAKEINTRESOURCE(3)
#وصف_ڪريو RT_MENU MAKEINTRESOURCE(4)
#وصف_ڪريو RT_DIALOG MAKEINTRESOURCE(5)
#وصف_ڪريو RT_STRING MAKEINTRESOURCE(6)
#وصف_ڪريو RT_FONTDIR MAKEINTRESOURCE(7)
#وصف_ڪريو RT_FONT MAKEINTRESOURCE(8)
#وصف_ڪريو RT_ACCELERATOR MAKEINTRESOURCE(9)
#وصف_ڪريو RT_RCDATA MAKEINTRESOURCE(10)
#وصف_ڪريو RT_MESSAGETABLE MAKEINTRESOURCE(11)

#وصف_ڪريو DIFFERENCE 11
#وصف_ڪريو RT_گروهه_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
#وصف_ڪريو RT_گروهه_ICON MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
#وصف_ڪريو RT_نسخو MAKEINTRESOURCE(16)
#وصف_ڪريو RT_DLGINCLUDE MAKEINTRESOURCE(17)
#وصف_ڪريو RT_PLUGPLAY MAKEINTRESOURCE(19)
#وصف_ڪريو RT_VXD MAKEINTRESOURCE(20)
#وصف_ڪريو RT_ANICURSOR MAKEINTRESOURCE(21)
#وصف_ڪريو RT_ANIICON MAKEINTRESOURCE(22)
#وصف_ڪريو RT_HTML MAKEINTRESOURCE(23)
#جيڪڏهن_وصف_ٿيل RC_INVOKED
#وصف_ڪريو RT_MANIFEST 24
#وصف_ڪريو CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#وصف_ڪريو ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#وصف_ڪريو ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#وصف_ڪريو MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#وصف_ڪريو وڌ_کان_وڌ_RESERVED_MANIFEST_RESOURCE_ID 16
#وإلا
#وصف_ڪريو RT_MANIFEST MAKEINTRESOURCE(24)
#وصف_ڪريو CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#وصف_ڪريو ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#وصف_ڪريو ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#وصف_ڪريو MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#وصف_ڪريو وڌ_کان_وڌ_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو wvsprintf wvsprintfW
#وصف_ڪريو wsprintf wsprintfW
#وإلا
#وصف_ڪريو wvsprintf wvsprintfA
#وصف_ڪريو wsprintf wsprintfA
#جيڪڏهن_پورو

  WINUSERAPI صحيح WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
  WINUSERAPI صحيح WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);
  WINUSERAPI صحيح WINAPIV wsprintfA(LPSTR,LPCSTR,...);
  WINUSERAPI صحيح WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);

#وصف_ڪريو SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#جيڪڏهن_وصف_نه_ٿيل NOSCROLL
#وصف_ڪريو SB_HORZ 0
#وصف_ڪريو SB_VERT 1
#وصف_ڪريو SB_CTL 2
#وصف_ڪريو SB_BOTH 3

#وصف_ڪريو SB_LINEUP 0
#وصف_ڪريو SB_LINELEFT 0
#وصف_ڪريو SB_LINEDOWN 1
#وصف_ڪريو SB_LINERIGHT 1
#وصف_ڪريو SB_PAGEUP 2
#وصف_ڪريو SB_PAGELEFT 2
#وصف_ڪريو SB_PAGEDOWN 3
#وصف_ڪريو SB_PAGERIGHT 3
#وصف_ڪريو SB_THUMBPOSITION 4
#وصف_ڪريو SB_THUMBTRACK 5
#وصف_ڪريو SB_چوٽي 6
#وصف_ڪريو SB_کاٻو 6
#وصف_ڪريو SB_BOTTOM 7
#وصف_ڪريو SB_ساڄو 7
#وصف_ڪريو SB_ENDSCROLL 8
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOSHOWWINDOW
#وصف_ڪريو SW_HIDE 0
#وصف_ڪريو SW_SHOWNORMAL 1
#وصف_ڪريو SW_عام 1
#وصف_ڪريو SW_SHOWMINIMIZED 2
#وصف_ڪريو SW_SHOWMAXIMIZED 3
#وصف_ڪريو SW_MAXIMIZE 3
#وصف_ڪريو SW_SHOWNOACTIVATE 4
#وصف_ڪريو SW_SHOW 5
#وصف_ڪريو SW_MINIMIZE 6
#وصف_ڪريو SW_SHOWMINNOACTIVE 7
#وصف_ڪريو SW_SHOWNA 8
#وصف_ڪريو SW_RESTORE 9
#وصف_ڪريو SW_SHOWDEFAULT 10
#وصف_ڪريو SW_FORCEMINIMIZE 11
#وصف_ڪريو SW_MAX 11

#وصف_ڪريو HIDE_دري 0
#وصف_ڪريو SHOW_OPENWINDOW 1
#وصف_ڪريو SHOW_ICONWINDOW 2
#وصف_ڪريو SHOW_FULLSCREEN 3
#وصف_ڪريو SHOW_OPENNOACTIVATE 4

#وصف_ڪريو SW_PARENTCLOSING 1
#وصف_ڪريو SW_OTHERZOOM 2
#وصف_ڪريو SW_PARENTOPENING 3
#وصف_ڪريو SW_OTHERUNZOOM 4
#جيڪڏهن_پورو

#وصف_ڪريو AW_HOR_مثبت 0x00000001
#وصف_ڪريو AW_HOR_NEGATIVE 0x00000002
#وصف_ڪريو AW_VER_مثبت 0x00000004
#وصف_ڪريو AW_VER_NEGATIVE 0x00000008
#وصف_ڪريو AW_CENTER 0x00000010
#وصف_ڪريو AW_HIDE 0x00010000
#وصف_ڪريو AW_ACTIVATE 0x00020000
#وصف_ڪريو AW_SLIDE 0x00040000
#وصف_ڪريو AW_BLEND 0x00080000

#وصف_ڪريو KF_EXTENDED 0x0100
#وصف_ڪريو KF_DLGMODE 0x0800
#وصف_ڪريو KF_MENUMODE 0x1000
#وصف_ڪريو KF_ALTDOWN 0x2000
#وصف_ڪريو KF_REPEAT 0x4000
#وصف_ڪريو KF_مٿي 0x8000

#جيڪڏهن_وصف_نه_ٿيل NOVIRTUALKEYCODES

#وصف_ڪريو VK_LBUTTON 0x01
#وصف_ڪريو VK_RBUTTON 0x02
#وصف_ڪريو VK_CANCEL 0x03
#وصف_ڪريو VK_MBUTTON 0x04
#وصف_ڪريو VK_XBUTTON1 0x05
#وصف_ڪريو VK_XBUTTON2 0x06
#وصف_ڪريو VK_پٺ 0x08
#وصف_ڪريو VK_TAB 0x09
#وصف_ڪريو VK_CLEAR 0x0C
#وصف_ڪريو VK_RETURN 0x0D
#وصف_ڪريو VK_سرڪايو 0x10
#وصف_ڪريو VK_CONTROL 0x11
#وصف_ڪريو VK_MENU 0x12
#وصف_ڪريو VK_PAUSE 0x13
#وصف_ڪريو VK_CAPITAL 0x14
#وصف_ڪريو VK_KANA 0x15
#وصف_ڪريو VK_HANGEUL 0x15
#وصف_ڪريو VK_HANGUL 0x15
#وصف_ڪريو VK_JUNJA 0x17
#وصف_ڪريو VK_FINAL 0x18
#وصف_ڪريو VK_HANJA 0x19
#وصف_ڪريو VK_KANJI 0x19
#وصف_ڪريو VK_ESCAPE 0x1B
#وصف_ڪريو VK_CONVERT 0x1C
#وصف_ڪريو VK_NONCONVERT 0x1D
#وصف_ڪريو VK_ACCEPT 0x1E
#وصف_ڪريو VK_MODECHANGE 0x1F
#وصف_ڪريو VK_SPACE 0x20
#وصف_ڪريو VK_اڳواٽ 0x21
#وصف_ڪريو VK_ايندڙ 0x22
#وصف_ڪريو VK_پڇاڙي 0x23
#وصف_ڪريو VK_HOME 0x24
#وصف_ڪريو VK_کاٻو 0x25
#وصف_ڪريو VK_مٿي 0x26
#وصف_ڪريو VK_ساڄو 0x27
#وصف_ڪريو VK_هيٺ_ڏانهن 0x28
#وصف_ڪريو VK_SELECT 0x29
#وصف_ڪريو VK_PRINT 0x2A
#وصف_ڪريو VK_EXECUTE 0x2B
#وصف_ڪريو VK_SNAPSHOT 0x2C
#وصف_ڪريو VK_وجهو 0x2D
#وصف_ڪريو VK_DELETE 0x2E
#وصف_ڪريو VK_HELP 0x2F

#وصف_ڪريو VK_LWIN 0x5B
#وصف_ڪريو VK_RWIN 0x5C
#وصف_ڪريو VK_APPS 0x5D
#وصف_ڪريو VK_SLEEP 0x5F
#وصف_ڪريو VK_NUMPAD0 0x60
#وصف_ڪريو VK_NUMPAD1 0x61
#وصف_ڪريو VK_NUMPAD2 0x62
#وصف_ڪريو VK_NUMPAD3 0x63
#وصف_ڪريو VK_NUMPAD4 0x64
#وصف_ڪريو VK_NUMPAD5 0x65
#وصف_ڪريو VK_NUMPAD6 0x66
#وصف_ڪريو VK_NUMPAD7 0x67
#وصف_ڪريو VK_NUMPAD8 0x68
#وصف_ڪريو VK_NUMPAD9 0x69
#وصف_ڪريو VK_MULTIPLY 0x6A
#وصف_ڪريو VK_جوڙيو 0x6B
#وصف_ڪريو VK_SEPARATOR 0x6C
#وصف_ڪريو VK_ڪٽيو 0x6D
#وصف_ڪريو VK_DECIMAL 0x6E
#وصف_ڪريو VK_DIVIDE 0x6F
#وصف_ڪريو VK_F1 0x70
#وصف_ڪريو VK_F2 0x71
#وصف_ڪريو VK_F3 0x72
#وصف_ڪريو VK_F4 0x73
#وصف_ڪريو VK_F5 0x74
#وصف_ڪريو VK_F6 0x75
#وصف_ڪريو VK_F7 0x76
#وصف_ڪريو VK_F8 0x77
#وصف_ڪريو VK_F9 0x78
#وصف_ڪريو VK_F10 0x79
#وصف_ڪريو VK_F11 0x7A
#وصف_ڪريو VK_F12 0x7B
#وصف_ڪريو VK_F13 0x7C
#وصف_ڪريو VK_F14 0x7D
#وصف_ڪريو VK_F15 0x7E
#وصف_ڪريو VK_F16 0x7F
#وصف_ڪريو VK_F17 0x80
#وصف_ڪريو VK_F18 0x81
#وصف_ڪريو VK_F19 0x82
#وصف_ڪريو VK_F20 0x83
#وصف_ڪريو VK_F21 0x84
#وصف_ڪريو VK_F22 0x85
#وصف_ڪريو VK_F23 0x86
#وصف_ڪريو VK_F24 0x87
#وصف_ڪريو VK_NUMLOCK 0x90
#وصف_ڪريو VK_SCROLL 0x91
#وصف_ڪريو VK_OEM_NEC_EQUAL 0x92
#وصف_ڪريو VK_OEM_FJ_JISHO 0x92
#وصف_ڪريو VK_OEM_FJ_MASSHOU 0x93
#وصف_ڪريو VK_OEM_FJ_TOUROKU 0x94
#وصف_ڪريو VK_OEM_FJ_LOYA 0x95
#وصف_ڪريو VK_OEM_FJ_ROYA 0x96
#وصف_ڪريو VK_LSHIFT 0xA0
#وصف_ڪريو VK_RSHIFT 0xA1
#وصف_ڪريو VK_LCONTROL 0xA2
#وصف_ڪريو VK_RCONTROL 0xA3
#وصف_ڪريو VK_LMENU 0xA4
#وصف_ڪريو VK_RMENU 0xA5
#وصف_ڪريو VK_BROWSER_پٺ 0xA6
#وصف_ڪريو VK_BROWSER_FORWARD 0xA7
#وصف_ڪريو VK_BROWSER_REFRESH 0xA8
#وصف_ڪريو VK_BROWSER_STOP 0xA9
#وصف_ڪريو VK_BROWSER_ڳولا 0xAA
#وصف_ڪريو VK_BROWSER_FAVORITES 0xAB
#وصف_ڪريو VK_BROWSER_HOME 0xAC
#وصف_ڪريو VK_VOLUME_MUTE 0xAD
#وصف_ڪريو VK_VOLUME_هيٺ_ڏانهن 0xAE
#وصف_ڪريو VK_VOLUME_مٿي 0xAF
#وصف_ڪريو VK_MEDIA_ايندڙ_TRACK 0xB0
#وصف_ڪريو VK_MEDIA_PREV_TRACK 0xB1
#وصف_ڪريو VK_MEDIA_STOP 0xB2
#وصف_ڪريو VK_MEDIA_PLAY_PAUSE 0xB3
#وصف_ڪريو VK_LAUNCH_MAIL 0xB4
#وصف_ڪريو VK_LAUNCH_MEDIA_SELECT 0xB5
#وصف_ڪريو VK_LAUNCH_APP1 0xB6
#وصف_ڪريو VK_LAUNCH_APP2 0xB7
#وصف_ڪريو VK_OEM_1 0xBA
#وصف_ڪريو VK_OEM_PLUS 0xBB
#وصف_ڪريو VK_OEM_COMMA 0xBC
#وصف_ڪريو VK_OEM_MINUS 0xBD
#وصف_ڪريو VK_OEM_PERIOD 0xBE
#وصف_ڪريو VK_OEM_2 0xBF
#وصف_ڪريو VK_OEM_3 0xC0
#وصف_ڪريو VK_OEM_4 0xDB
#وصف_ڪريو VK_OEM_5 0xDC
#وصف_ڪريو VK_OEM_6 0xDD
#وصف_ڪريو VK_OEM_7 0xDE
#وصف_ڪريو VK_OEM_8 0xDF
#وصف_ڪريو VK_OEM_AX 0xE1
#وصف_ڪريو VK_OEM_102 0xE2
#وصف_ڪريو VK_ICO_HELP 0xE3
#وصف_ڪريو VK_ICO_00 0xE4
#وصف_ڪريو VK_PROCESSKEY 0xE5
#وصف_ڪريو VK_ICO_CLEAR 0xE6
#وصف_ڪريو VK_PACKET 0xE7
#وصف_ڪريو VK_OEM_RESET 0xE9
#وصف_ڪريو VK_OEM_JUMP 0xEA
#وصف_ڪريو VK_OEM_PA1 0xEB
#وصف_ڪريو VK_OEM_PA2 0xEC
#وصف_ڪريو VK_OEM_PA3 0xED
#وصف_ڪريو VK_OEM_WSCTRL 0xEE
#وصف_ڪريو VK_OEM_CUSEL 0xEF
#وصف_ڪريو VK_OEM_ATTN 0xF0
#وصف_ڪريو VK_OEM_پڄاڻي 0xF1
#وصف_ڪريو VK_OEM_COPY 0xF2
#وصف_ڪريو VK_OEM_AUTO 0xF3
#وصف_ڪريو VK_OEM_ENLW 0xF4
#وصف_ڪريو VK_OEM_BACKTAB 0xF5
#وصف_ڪريو VK_ATTN 0xF6
#وصف_ڪريو VK_CRSEL 0xF7
#وصف_ڪريو VK_EXSEL 0xF8
#وصف_ڪريو VK_EREOF 0xF9
#وصف_ڪريو VK_PLAY 0xFA
#وصف_ڪريو VK_ZOOM 0xFB
#وصف_ڪريو VK_NONAME 0xFC
#وصف_ڪريو VK_PA1 0xFD
#وصف_ڪريو VK_OEM_CLEAR 0xFE
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOWH

#وصف_ڪريو WH_MIN (-1)
#وصف_ڪريو WH_MSGFILTER (-1)
#وصف_ڪريو WH_JOURNALRECORD 0
#وصف_ڪريو WH_JOURNALPLAYBACK 1
#وصف_ڪريو WH_KEYBOARD 2
#وصف_ڪريو WH_GETMESSAGE 3
#وصف_ڪريو WH_CALLWNDPROC 4
#وصف_ڪريو WH_CBT 5
#وصف_ڪريو WH_SYSMSGFILTER 6
#وصف_ڪريو WH_MOUSE 7
#وصف_ڪريو WH_HARDWARE 8
#وصف_ڪريو WH_DEBUG 9
#وصف_ڪريو WH_SHELL 10
#وصف_ڪريو WH_FOREGROUNDIDLE 11
#وصف_ڪريو WH_CALLWNDPROCRET 12

#وصف_ڪريو WH_KEYBOARD_LL 13
#وصف_ڪريو WH_MOUSE_LL 14

#وصف_ڪريو WH_MAX 14

#وصف_ڪريو WH_MINHOOK WH_MIN
#وصف_ڪريو WH_MAXHOOK WH_MAX

#وصف_ڪريو HC_ACTION 0
#وصف_ڪريو HC_GETNEXT 1
#وصف_ڪريو HC_SKIP 2
#وصف_ڪريو HC_NOREMOVE 3
#وصف_ڪريو HC_NOREM HC_NOREMOVE
#وصف_ڪريو HC_SYSMODALON 4
#وصف_ڪريو HC_SYSMODALOFF 5

#وصف_ڪريو HCBT_MOVESIZE 0
#وصف_ڪريو HCBT_MINMAX 1
#وصف_ڪريو HCBT_QS 2
#وصف_ڪريو HCBT_CREATEWND 3
#وصف_ڪريو HCBT_DESTROYWND 4
#وصف_ڪريو HCBT_ACTIVATE 5
#وصف_ڪريو HCBT_CLICKSKIPPED 6
#وصف_ڪريو HCBT_KEYSKIPPED 7
#وصف_ڪريو HCBT_SYSCOMMAND 8
#وصف_ڪريو HCBT_SETFOCUS 9

  تعريفنوع بنية ٽيگ_CBT_CREATEWNDA {
    بنية ٽيگ_CREATESTRUCTA *lpcs;
    HWND hwnd_وجهو_After;
  } CBT_CREATEWNDA,*LPCBT_CREATEWNDA;

  تعريفنوع بنية ٽيگ_CBT_CREATEWNDW {
    بنية ٽيگ_CREATESTRUCTW *lpcs;
    HWND hwnd_وجهو_After;
  } CBT_CREATEWNDW,*LPCBT_CREATEWNDW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع CBT_CREATEWNDW CBT_CREATEWND;
  تعريفنوع LPCBT_CREATEWNDW LPCBT_CREATEWND;
#وإلا
  تعريفنوع CBT_CREATEWNDA CBT_CREATEWND;
  تعريفنوع LPCBT_CREATEWNDA LPCBT_CREATEWND;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_CBTACTIVATESTRUCT
  {
    WINBOOL fMouse;
    HWND h_Wnd_سرگرم;
  } CBTACTIVATESTRUCT,*LPCBTACTIVATESTRUCT;

  تعريفنوع بنية ٽيگ_WTSSESSION_NOTIFICATION {
    DWORD cb_سائيز;
    DWORD dwSessionId;

  } WTSSESSION_NOTIFICATION,*PWTSSESSION_NOTIFICATION;

#وصف_ڪريو WTS_CONSOLE_CONNECT 0x1
#وصف_ڪريو WTS_CONSOLE_DISCONNECT 0x2
#وصف_ڪريو WTS_REMOTE_CONNECT 0x3
#وصف_ڪريو WTS_REMOTE_DISCONNECT 0x4
#وصف_ڪريو WTS_SESSION_LOGON 0x5
#وصف_ڪريو WTS_SESSION_LOGOFF 0x6
#وصف_ڪريو WTS_SESSION_تالو 0x7
#وصف_ڪريو WTS_SESSION_UNLOCK 0x8
#وصف_ڪريو WTS_SESSION_REMOTE_CONTROL 0x9

#وصف_ڪريو MSGF_DIALOGBOX 0
#وصف_ڪريو MSGF_MESSAGEBOX 1
#وصف_ڪريو MSGF_MENU 2
#وصف_ڪريو MSGF_SCROLLBAR 5
#وصف_ڪريو MSGF_NEXTWINDOW 6
#وصف_ڪريو MSGF_MAX 8
#وصف_ڪريو MSGF_USER 4096

#وصف_ڪريو HSHELL_WINDOWCREATED 1
#وصف_ڪريو HSHELL_WINDOWDESTROYED 2
#وصف_ڪريو HSHELL_ACTIVATESHELLWINDOW 3

#وصف_ڪريو HSHELL_WINDOWACTIVATED 4
#وصف_ڪريو HSHELL_GETMINRECT 5
#وصف_ڪريو HSHELL_REDRAW 6
#وصف_ڪريو HSHELL_TASKMAN 7
#وصف_ڪريو HSHELL_LANGUAGE 8
#وصف_ڪريو HSHELL_SYSMENU 9
#وصف_ڪريو HSHELL_ENDTASK 10
#وصف_ڪريو HSHELL_ACCESSIBILITYSTATE 11
#وصف_ڪريو HSHELL_APPCOMMAND 12
#وصف_ڪريو HSHELL_WINDOWREPLACED 13
#وصف_ڪريو HSHELL_WINDOWREPLACING 14
#وصف_ڪريو HSHELL_HIGHBIT 0x8000
#وصف_ڪريو HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#وصف_ڪريو HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#وصف_ڪريو ACCESS_STICKYKEYS 0x0001
#وصف_ڪريو ACCESS_FILTERKEYS 0x0002
#وصف_ڪريو ACCESS_MOUSEKEYS 0x0003

#وصف_ڪريو APPCOMMAND_BROWSER_BACKWARD 1
#وصف_ڪريو APPCOMMAND_BROWSER_FORWARD 2
#وصف_ڪريو APPCOMMAND_BROWSER_REFRESH 3
#وصف_ڪريو APPCOMMAND_BROWSER_STOP 4
#وصف_ڪريو APPCOMMAND_BROWSER_ڳولا 5
#وصف_ڪريو APPCOMMAND_BROWSER_FAVORITES 6
#وصف_ڪريو APPCOMMAND_BROWSER_HOME 7
#وصف_ڪريو APPCOMMAND_VOLUME_MUTE 8
#وصف_ڪريو APPCOMMAND_VOLUME_هيٺ_ڏانهن 9
#وصف_ڪريو APPCOMMAND_VOLUME_مٿي 10
#وصف_ڪريو APPCOMMAND_MEDIA_NEXTTRACK 11
#وصف_ڪريو APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#وصف_ڪريو APPCOMMAND_MEDIA_STOP 13
#وصف_ڪريو APPCOMMAND_MEDIA_PLAY_PAUSE 14
#وصف_ڪريو APPCOMMAND_LAUNCH_MAIL 15
#وصف_ڪريو APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#وصف_ڪريو APPCOMMAND_LAUNCH_APP1 17
#وصف_ڪريو APPCOMMAND_LAUNCH_APP2 18
#وصف_ڪريو APPCOMMAND_BASS_هيٺ_ڏانهن 19
#وصف_ڪريو APPCOMMAND_BASS_BOOST 20
#وصف_ڪريو APPCOMMAND_BASS_مٿي 21
#وصف_ڪريو APPCOMMAND_TREBLE_هيٺ_ڏانهن 22
#وصف_ڪريو APPCOMMAND_TREBLE_مٿي 23
#وصف_ڪريو APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#وصف_ڪريو APPCOMMAND_MICROPHONE_VOLUME_هيٺ_ڏانهن 25
#وصف_ڪريو APPCOMMAND_MICROPHONE_VOLUME_مٿي 26
#وصف_ڪريو APPCOMMAND_HELP 27
#وصف_ڪريو APPCOMMAND_ڳوليو 28
#وصف_ڪريو APPCOMMAND_NEW 29
#وصف_ڪريو APPCOMMAND_OPEN 30
#وصف_ڪريو APPCOMMAND_CLOSE 31
#وصف_ڪريو APPCOMMAND_SAVE 32
#وصف_ڪريو APPCOMMAND_PRINT 33
#وصف_ڪريو APPCOMMAND_UNDO 34
#وصف_ڪريو APPCOMMAND_REDO 35
#وصف_ڪريو APPCOMMAND_COPY 36
#وصف_ڪريو APPCOMMAND_CUT 37
#وصف_ڪريو APPCOMMAND_PASTE 38
#وصف_ڪريو APPCOMMAND_جواب_منزل_MAIL 39
#وصف_ڪريو APPCOMMAND_FORWARD_MAIL 40
#وصف_ڪريو APPCOMMAND_SEND_MAIL 41
#وصف_ڪريو APPCOMMAND_SPELL_CHECK 42
#وصف_ڪريو APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#وصف_ڪريو APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#وصف_ڪريو APPCOMMAND_CORRECTION_LIST 45
#وصف_ڪريو APPCOMMAND_MEDIA_PLAY 46
#وصف_ڪريو APPCOMMAND_MEDIA_PAUSE 47
#وصف_ڪريو APPCOMMAND_MEDIA_رڪارڊ 48
#وصف_ڪريو APPCOMMAND_MEDIA_FAST_FORWARD 49
#وصف_ڪريو APPCOMMAND_MEDIA_REWIND 50
#وصف_ڪريو APPCOMMAND_MEDIA_CHANNEL_مٿي 51
#وصف_ڪريو APPCOMMAND_MEDIA_CHANNEL_هيٺ_ڏانهن 52

#وصف_ڪريو FAPPCOMMAND_MOUSE 0x8000
#وصف_ڪريو FAPPCOMMAND_ڪنجي 0
#وصف_ڪريو FAPPCOMMAND_OEM 0x1000
#وصف_ڪريو FAPPCOMMAND_نقاب 0xF000

#وصف_ڪريو GET_APPCOMMAND_LPARAM(lParam) ((ننڍو)(HIWORD(lParam) & ~FAPPCOMMAND_نقاب))
#وصف_ڪريو GET_DEVICE_LPARAM(lParam) ((لفظ_3)(HIWORD(lParam) & FAPPCOMMAND_نقاب))
#وصف_ڪريو GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#وصف_ڪريو GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#وصف_ڪريو GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)

  تعريفنوع بنية {
    HWND hwnd;
    RECT rc;
  } SHELLHOOKINFO,*LPSHELLHOOKINFO;

  تعريفنوع بنية ٽيگ_EVENTMSG {
    UINT پيغام;
    UINT paramL;
    UINT paramH;
    DWORD وقت;
    HWND hwnd;
  } EVENTMSG,*PEVENTMSGMSG,*NPEVENTMSGMSG,*LPEVENTMSGMSG;

  تعريفنوع بنية ٽيگ_EVENTMSG *PEVENTMSG,*NPEVENTMSG,*LPEVENTMSG;

  تعريفنوع بنية ٽيگ_CWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT پيغام;
    HWND hwnd;
  } CWPSTRUCT,*PCWPSTRUCT,*NPCWPSTRUCT,*LPCWPSTRUCT;

  تعريفنوع بنية ٽيگ_CWPRETSTRUCT {
    LRESULT l_نتيجو;
    LPARAM lParam;
    WPARAM wParam;
    UINT پيغام;
    HWND hwnd;
  } CWPRETSTRUCT,*PCWPRETSTRUCT,*NPCWPRETSTRUCT,*LPCWPRETSTRUCT;

#وصف_ڪريو LLKHF_EXTENDED (KF_EXTENDED >> 8)
#وصف_ڪريو LLKHF_INJECTED 0x00000010
#وصف_ڪريو LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#وصف_ڪريو LLKHF_مٿي (KF_مٿي >> 8)

#وصف_ڪريو LLMHF_INJECTED 0x00000001

  تعريفنوع بنية ٽيگ_KBDLLHOOKSTRUCT {
    DWORD vk_ڪوڊ;
    DWORD جاچ_ڪوڊ;
    DWORD flags;
    DWORD وقت;
    ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;

  تعريفنوع بنية ٽيگ_MSLLHOOKSTRUCT {
    نقطو_3 pt;
    DWORD mouse_معلومات;
    DWORD flags;
    DWORD وقت;
    ULONG_PTR dwExtraInfo;
  } MSLLHOOKSTRUCT,*LPMSLLHOOKSTRUCT,*PMSLLHOOKSTRUCT;

  تعريفنوع بنية ٽيگ_DEBUGHOOKINFO {
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    صحيح ڪوڊ;
  } DEBUGHOOKINFO,*PDEBUGHOOKINFO,*NPDEBUGHOOKINFO,*LPDEBUGHOOKINFO;

  تعريفنوع بنية ٽيگ_MOUSEHOOKSTRUCT {
    نقطو_3 pt;
    HWND hwnd;
    UINT w_ڪاميابي_Test_ڪوڊ;
    ULONG_PTR dwExtraInfo;
  } MOUSEHOOKSTRUCT,*LPMOUSEHOOKSTRUCT,*PMOUSEHOOKSTRUCT;

#جيڪڏهن_وصف_ٿيل __cplusplus
  تعريفنوع بنية ٽيگ_MOUSEHOOKSTRUCTEX : عام ٽيگ_MOUSEHOOKSTRUCT {
    DWORD mouse_معلومات;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#وإلا
  تعريفنوع بنية ٽيگ_MOUSEHOOKSTRUCTEX {
    MOUSEHOOKSTRUCT _unnamed;
    DWORD mouse_معلومات;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_HARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT پيغام;
    WPARAM wParam;
    LPARAM lParam;
  } HARDWAREHOOKSTRUCT,*LPHARDWAREHOOKSTRUCT,*PHARDWAREHOOKSTRUCT;
#جيڪڏهن_پورو

#وصف_ڪريو HKL_PREV 0
#وصف_ڪريو HKL_ايندڙ 1

#وصف_ڪريو KLF_ACTIVATE 0x00000001
#وصف_ڪريو KLF_SUBSTITUTE_OK 0x00000002
#وصف_ڪريو KLF_REORDER 0x00000008
#وصف_ڪريو KLF_REPLACELANG 0x00000010
#وصف_ڪريو KLF_NOTELLSHELL 0x00000080
#وصف_ڪريو KLF_SETFORPROCESS 0x00000100
#وصف_ڪريو KLF_SHIFTLOCK 0x00010000
#وصف_ڪريو KLF_RESET 0x40000000

#وصف_ڪريو INPUTLANGCHANGE_SYSCHARSET 0x0001
#وصف_ڪريو INPUTLANGCHANGE_FORWARD 0x0002
#وصف_ڪريو INPUTLANGCHANGE_BACKWARD 0x0004

#وصف_ڪريو KL_NAMELENGTH 9

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڀريو_Keyboard_Layout ڀريو_Keyboard_Layout_W
#وصف_ڪريو GetKeyboardLayoutName GetKeyboardLayoutNameW
#وإلا
#وصف_ڪريو ڀريو_Keyboard_Layout ڀريو_Keyboard_Layout_A
#وصف_ڪريو GetKeyboardLayoutName GetKeyboardLayoutNameA
#جيڪڏهن_پورو

  WINUSERAPI HKL WINAPI ڀريو_Keyboard_Layout_A(LPCSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ڀريو_Keyboard_Layout_W(LPCWSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ActivateKeyboardLayout(HKL hkl,UINT Flags);
  WINUSERAPI صحيح WINAPI منزل_Unicode_Ex(UINT w_Virt_ڪنجي,UINT w_جاچ_ڪوڊ,CONST BYTE *lp_ڪنجي_State,LPWSTR pwszBuff,صحيح cchBuff,UINT wFlags,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI UnloadKeyboardLayout(HKL hkl);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameA(LPSTR pwszKLID);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameW(LPWSTR pwszKLID);
  WINUSERAPI صحيح WINAPI GetKeyboardLayoutList(صحيح nBuff,HKL *lpList);
  WINUSERAPI HKL WINAPI GetKeyboardLayout(DWORD idThread);

  تعريفنوع بنية ٽيگ_MOUSEMOVEPOINT {
    صحيح x;
    صحيح y;
    DWORD وقت;
    ULONG_PTR dwExtraInfo;
  } MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

#وصف_ڪريو GMMP_USE_DISPLAY_POINTS 1
#وصف_ڪريو GMMP_USE_مٿاهون_RESOLUTION_POINTS 2

  WINUSERAPI صحيح WINAPI GetMouseMovePointsEx(UINT cb_سائيز,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,صحيح nBufPoints,DWORD resolution);

#جيڪڏهن_وصف_نه_ٿيل NODESKTOP

#وصف_ڪريو DESKTOP_READOBJECTS 0x0001L
#وصف_ڪريو DESKTOP_CREATEWINDOW 0x0002L
#وصف_ڪريو DESKTOP_CREATEMENU 0x0004L
#وصف_ڪريو DESKTOP_HOOKCONTROL 0x0008L
#وصف_ڪريو DESKTOP_JOURNALRECORD 0x0010L
#وصف_ڪريو DESKTOP_JOURNALPLAYBACK 0x0020L
#وصف_ڪريو DESKTOP_ENUMERATE 0x0040L
#وصف_ڪريو DESKTOP_WRITEOBJECTS 0x0080L
#وصف_ڪريو DESKTOP_SWITCHDESKTOP 0x0100L

#وصف_ڪريو DF_ALLOWOTHERACCOUNTHOOK 0x0001L

#جيڪڏهن_وصف_ٿيل _WINGDI_
#جيڪڏهن_وصف_نه_ٿيل NOGDI
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو CreateDesktop CreateDesktopW
#وإلا
#وصف_ڪريو CreateDesktop CreateDesktopA
#جيڪڏهن_پورو

  WINUSERAPI HDESK WINAPI CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,LPDEVMODEA pDevmode,DWORD dwFlags,ACCESS_نقاب dwDesiredAccess,LPSECURITY_خاصيتون lpsa);
  WINUSERAPI HDESK WINAPI CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,LPDEVMODEW pDevmode,DWORD dwFlags,ACCESS_نقاب dwDesiredAccess,LPSECURITY_خاصيتون lpsa);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو OpenDesktop OpenDesktopW
#وصف_ڪريو EnumDesktops EnumDesktopsW
#وإلا
#وصف_ڪريو OpenDesktop OpenDesktopA
#وصف_ڪريو EnumDesktops EnumDesktopsA
#جيڪڏهن_پورو

  WINUSERAPI HDESK WINAPI OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI HDESK WINAPI Open_داخلا_Desktop(DWORD dwFlags,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SwitchDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI سيٽ_Thread_Desktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI CloseDesktop(HDESK hDesktop);
  WINUSERAPI HDESK WINAPI GetThreadDesktop(DWORD dwThreadId);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOWINDOWSTATION
#وصف_ڪريو WINSTA_ENUMDESKTOPS 0x0001L
#وصف_ڪريو WINSTA_READATTRIBUTES 0x0002L
#وصف_ڪريو WINSTA_ACCESSCLIPBOARD 0x0004L
#وصف_ڪريو WINSTA_CREATEDESKTOP 0x0008L
#وصف_ڪريو WINSTA_WRITEATTRIBUTES 0x0010L
#وصف_ڪريو WINSTA_ACCESSGLOBALATOMS 0x0020L
#وصف_ڪريو WINSTA_EXITWINDOWS 0x0040L
#وصف_ڪريو WINSTA_ENUMERATE 0x0100L
#وصف_ڪريو WINSTA_READSCREEN 0x0200L
#وصف_ڪريو WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#وصف_ڪريو CWF_CREATE_ONLY 0x0001L

#وصف_ڪريو WSF_VISIBLE 0x0001L

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Create_دري_Station Create_دري_Station_W
#وصف_ڪريو Open_دري_Station Open_دري_Station_W
#وصف_ڪريو Enum_دري_Stations Enum_دري_Stations_W
#وإلا
#وصف_ڪريو Create_دري_Station Create_دري_Station_A
#وصف_ڪريو Open_دري_Station Open_دري_Station_A
#وصف_ڪريو Enum_دري_Stations Enum_دري_Stations_A
#جيڪڏهن_پورو

  WINUSERAPI HWINSTA WINAPI Create_دري_Station_A(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_نقاب dwDesiredAccess,LPSECURITY_خاصيتون lpsa);
  WINUSERAPI HWINSTA WINAPI Create_دري_Station_W(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_نقاب dwDesiredAccess,LPSECURITY_خاصيتون lpsa);
  WINUSERAPI HWINSTA WINAPI Open_دري_Station_A(LPCSTR lpszWinSta,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI HWINSTA WINAPI Open_دري_Station_W(LPCWSTR lpszWinSta,WINBOOL fInherit,ACCESS_نقاب dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI Enum_دري_Stations_A(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Enum_دري_Stations_W(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Close_دري_Station(HWINSTA hWinSta);
  WINUSERAPI WINBOOL WINAPI سيٽ_Process_دري_Station(HWINSTA hWinSta);
  WINUSERAPI HWINSTA WINAPI Get_Process_دري_Station(VOID);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOSECURITY
  WINUSERAPI WINBOOL WINAPI سيٽ_User_Object_Security(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
  WINUSERAPI WINBOOL WINAPI GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD n_ڊيگهائي,LPDWORD lpn_ڊيگهائي_Needed);

#وصف_ڪريو UOI_FLAGS 1
#وصف_ڪريو UOI_NAME 2
#وصف_ڪريو UOI_TYPE 3
#وصف_ڪريو UOI_USER_SID 4

  تعريفنوع بنية ٽيگ_USEROBJECTFLAGS {
    WINBOOL fInherit;
    WINBOOL fReserved;
    DWORD dwFlags;
  } USEROBJECTFLAGS,*PUSEROBJECTFLAGS;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetUserObjectInformation GetUserObjectInformationW
#وصف_ڪريو سيٽ_User_Object_Information سيٽ_User_Object_Information_W
#وإلا
#وصف_ڪريو GetUserObjectInformation GetUserObjectInformationA
#وصف_ڪريو سيٽ_User_Object_Information سيٽ_User_Object_Information_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationA(HANDLE hObj,صحيح n_اشاريو,PVOID pvInfo,DWORD n_ڊيگهائي,LPDWORD lpn_ڊيگهائي_Needed);
  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationW(HANDLE hObj,صحيح n_اشاريو,PVOID pvInfo,DWORD n_ڊيگهائي,LPDWORD lpn_ڊيگهائي_Needed);
  WINUSERAPI WINBOOL WINAPI سيٽ_User_Object_Information_A(HANDLE hObj,صحيح n_اشاريو,PVOID pvInfo,DWORD n_ڊيگهائي);
  WINUSERAPI WINBOOL WINAPI سيٽ_User_Object_Information_W(HANDLE hObj,صحيح n_اشاريو,PVOID pvInfo,DWORD n_ڊيگهائي);
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_WNDCLASSEXA {
    UINT cb_سائيز;
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

  تعريفنوع بنية ٽيگ_WNDCLASSEXW {
    UINT cb_سائيز;
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

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WNDCLASSEXW WNDCLASSEX;
  تعريفنوع PWNDCLASSEXW PWNDCLASSEX;
  تعريفنوع NPWNDCLASSEXW NPWNDCLASSEX;
  تعريفنوع LPWNDCLASSEXW LPWNDCLASSEX;
#وإلا
  تعريفنوع WNDCLASSEXA WNDCLASSEX;
  تعريفنوع PWNDCLASSEXA PWNDCLASSEX;
  تعريفنوع NPWNDCLASSEXA NPWNDCLASSEX;
  تعريفنوع LPWNDCLASSEXA LPWNDCLASSEX;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_WNDCLASSA {
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

  تعريفنوع بنية ٽيگ_WNDCLASSW {
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

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WNDCLASSW WNDCLASS;
  تعريفنوع PWNDCLASSW PWNDCLASS;
  تعريفنوع NPWNDCLASSW NPWNDCLASS;
  تعريفنوع LPWNDCLASSW LPWNDCLASS;
#وإلا
  تعريفنوع WNDCLASSA WNDCLASS;
  تعريفنوع PWNDCLASSA PWNDCLASS;
  تعريفنوع NPWNDCLASSA NPWNDCLASS;
  تعريفنوع LPWNDCLASSA LPWNDCLASS;
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI Is_Hung_App_دري(HWND hwnd);
  WINUSERAPI VOID WINAPI DisableProcessWindowsGhosting(VOID);

#جيڪڏهن_وصف_نه_ٿيل NOMSG
  تعريفنوع بنية ٽيگ_نياپو {
    HWND hwnd;
    UINT پيغام;
    WPARAM wParam;
    LPARAM lParam;
    DWORD وقت;
    نقطو_3 pt;
  } نياپو_2,*PMSG,*NPMSG,*LPMSG;

#وصف_ڪريو POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#وصف_ڪريو POINTTOPOINTS(pt) (MAKELONG((ننڍو)((pt).x),(ننڍو)((pt).y)))
#وصف_ڪريو MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#وصف_ڪريو MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#وصف_ڪريو MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOWINOFFSETS
#وصف_ڪريو GWL_WNDPROC (-4)
#وصف_ڪريو GWL_HINSTANCE (-6)
#وصف_ڪريو GWL_HWNDPARENT (-8)
#وصف_ڪريو GWL_STYLE (-16)
#وصف_ڪريو GWL_EXSTYLE (-20)
#وصف_ڪريو GWL_USERDATA (-21)
#وصف_ڪريو GWL_ID (-12)

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_رد GWL_WNDPROC
#وصف_رد GWL_HINSTANCE
#وصف_رد GWL_HWNDPARENT
#وصف_رد GWL_USERDATA
#جيڪڏهن_پورو

#وصف_ڪريو GWLP_WNDPROC (-4)
#وصف_ڪريو GWLP_HINSTANCE (-6)
#وصف_ڪريو GWLP_HWNDPARENT (-8)
#وصف_ڪريو GWLP_USERDATA (-21)
#وصف_ڪريو GWLP_ID (-12)

#وصف_ڪريو GCL_MENUNAME (-8)
#وصف_ڪريو GCL_HBRBACKGROUND (-10)
#وصف_ڪريو GCL_HCURSOR (-12)
#وصف_ڪريو GCL_HICON (-14)
#وصف_ڪريو GCL_HMODULE (-16)
#وصف_ڪريو GCL_CBWNDEXTRA (-18)
#وصف_ڪريو GCL_CBCLSEXTRA (-20)
#وصف_ڪريو GCL_WNDPROC (-24)
#وصف_ڪريو GCL_STYLE (-26)
#وصف_ڪريو GCW_ATOM (-32)
#وصف_ڪريو GCL_HICONSM (-34)

#جيڪڏهن_وصف_ٿيل _WIN64

#وصف_رد GCL_MENUNAME
#وصف_رد GCL_HBRBACKGROUND
#وصف_رد GCL_HCURSOR
#وصف_رد GCL_HICON
#وصف_رد GCL_HMODULE
#وصف_رد GCL_WNDPROC
#وصف_رد GCL_HICONSM
#جيڪڏهن_پورو

#وصف_ڪريو GCLP_MENUNAME (-8)
#وصف_ڪريو GCLP_HBRBACKGROUND (-10)
#وصف_ڪريو GCLP_HCURSOR (-12)
#وصف_ڪريو GCLP_HICON (-14)
#وصف_ڪريو GCLP_HMODULE (-16)
#وصف_ڪريو GCLP_WNDPROC (-24)
#وصف_ڪريو GCLP_HICONSM (-34)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOWINMESSAGES

#وصف_ڪريو WM_NULL 0x0000
#وصف_ڪريو WM_CREATE 0x0001
#وصف_ڪريو WM_DESTROY 0x0002
#وصف_ڪريو WM_MOVE 0x0003
#وصف_ڪريو WM_سائيز 0x0005

#وصف_ڪريو WM_ACTIVATE 0x0006

#وصف_ڪريو WA_INACTIVE 0
#وصف_ڪريو WA_سرگرم 1
#وصف_ڪريو WA_CLICKACTIVE 2

#وصف_ڪريو WM_SETFOCUS 0x0007
#وصف_ڪريو WM_KILLFOCUS 0x0008
#وصف_ڪريو WM_ENABLE 0x000A
#وصف_ڪريو WM_SETREDRAW 0x000B
#وصف_ڪريو WM_SETTEXT 0x000C
#وصف_ڪريو WM_GETTEXT 0x000D
#وصف_ڪريو WM_GETTEXTLENGTH 0x000E
#وصف_ڪريو WM_PAINT 0x000F
#وصف_ڪريو WM_CLOSE 0x0010
#جيڪڏهن_وصف_نه_ٿيل _WIN32_WCE
#وصف_ڪريو WM_QUERYENDSESSION 0x0011
#وصف_ڪريو WM_QUERYOPEN 0x0013
#وصف_ڪريو WM_ENDSESSION 0x0016
#جيڪڏهن_پورو
#وصف_ڪريو WM_QUIT 0x0012
#وصف_ڪريو WM_ERASEBKGND 0x0014
#وصف_ڪريو WM_SYSCOLORCHANGE 0x0015
#وصف_ڪريو WM_SHOWWINDOW 0x0018
#وصف_ڪريو WM_WININICHANGE 0x001A
#وصف_ڪريو WM_SETTINGCHANGE WM_WININICHANGE
#وصف_ڪريو WM_DEVMODECHANGE 0x001B
#وصف_ڪريو WM_ACTIVATEAPP 0x001C
#وصف_ڪريو WM_FONTCHANGE 0x001D
#وصف_ڪريو WM_TIMECHANGE 0x001E
#وصف_ڪريو WM_CANCELMODE 0x001F
#وصف_ڪريو WM_SETCURSOR 0x0020
#وصف_ڪريو WM_MOUSEACTIVATE 0x0021
#وصف_ڪريو WM_CHILDACTIVATE 0x0022
#وصف_ڪريو WM_QUEUESYNC 0x0023

#وصف_ڪريو WM_GETMINMAXINFO 0x0024

  تعريفنوع بنية ٽيگ_MINMAXINFO {
    نقطو_3 ptReserved;
    نقطو_3 pt_Max_سائيز;
    نقطو_3 ptMaxPosition;
    نقطو_3 pt_Min_Track_سائيز;
    نقطو_3 pt_Max_Track_سائيز;
  } MINMAXINFO,*PMINMAXINFO,*LPMINMAXINFO;

#وصف_ڪريو WM_PAINTICON 0x0026
#وصف_ڪريو WM_ICONERASEBKGND 0x0027
#وصف_ڪريو WM_NEXTDLGCTL 0x0028
#وصف_ڪريو WM_SPOOLERSTATUS 0x002A
#وصف_ڪريو WM_DRAWITEM 0x002B
#وصف_ڪريو WM_MEASUREITEM 0x002C
#وصف_ڪريو WM_DELETEITEM 0x002D
#وصف_ڪريو WM_VKEYTOITEM 0x002E
#وصف_ڪريو WM_CHARTOITEM 0x002F
#وصف_ڪريو WM_SETFONT 0x0030
#وصف_ڪريو WM_GETFONT 0x0031
#وصف_ڪريو WM_SETHOTKEY 0x0032
#وصف_ڪريو WM_GETHOTKEY 0x0033
#وصف_ڪريو WM_QUERYDRAGICON 0x0037
#وصف_ڪريو WM_COMPAREITEM 0x0039
#جيڪڏهن_وصف_نه_ٿيل _WIN32_WCE
#وصف_ڪريو WM_GETOBJECT 0x003D
#جيڪڏهن_پورو
#وصف_ڪريو WM_COMPACTING 0x0041
#وصف_ڪريو WM_COMMNOTIFY 0x0044
#وصف_ڪريو WM_WINDOWPOSCHANGING 0x0046
#وصف_ڪريو WM_WINDOWPOSCHANGED 0x0047

#وصف_ڪريو WM_POWER 0x0048

#وصف_ڪريو PWR_OK 1
#وصف_ڪريو PWR_FAIL (-1)
#وصف_ڪريو PWR_SUSPENDREQUEST 1
#وصف_ڪريو PWR_SUSPENDRESUME 2
#وصف_ڪريو PWR_CRITICALRESUME 3

#وصف_ڪريو WM_COPYDATA 0x004A
#وصف_ڪريو WM_CANCELJOURNAL 0x004B

  تعريفنوع بنية ٽيگ_COPYDATASTRUCT {
    ULONG_PTR dw_معلومات;
    DWORD cb_معلومات;
    PVOID lp_معلومات;
  } COPYDATASTRUCT,*PCOPYDATASTRUCT;

  تعريفنوع بنية ٽيگ_MDINEXTMENU {
    HMENU hmenu_اندريون;
    HMENU hmenu_ايندڙ;
    HWND hwnd_ايندڙ;
  } MDINEXTMENU,*PMDINEXTMENU,*LPMDINEXTMENU;

#وصف_ڪريو WM_NOTIFY 0x004E
#وصف_ڪريو WM_INPUTLANGCHANGEREQUEST 0x0050
#وصف_ڪريو WM_INPUTLANGCHANGE 0x0051
#وصف_ڪريو WM_TCARD 0x0052
#وصف_ڪريو WM_HELP 0x0053
#وصف_ڪريو WM_USERCHANGED 0x0054
#وصف_ڪريو WM_NOTIFYFORMAT 0x0055

#وصف_ڪريو NFR_ANSI 1
#وصف_ڪريو NFR_UNICODE 2
#وصف_ڪريو NF_QUERY 3
#وصف_ڪريو NF_REQUERY 4

#وصف_ڪريو WM_CONTEXTMENU 0x007B
#وصف_ڪريو WM_STYLECHANGING 0x007C
#وصف_ڪريو WM_STYLECHANGED 0x007D
#وصف_ڪريو WM_DISPLAYCHANGE 0x007E
#وصف_ڪريو WM_GETICON 0x007F
#وصف_ڪريو WM_SETICON 0x0080

#وصف_ڪريو WM_NCCREATE 0x0081
#وصف_ڪريو WM_NCDESTROY 0x0082
#وصف_ڪريو WM_NCCALCSIZE 0x0083
#وصف_ڪريو WM_NCHITTEST 0x0084
#وصف_ڪريو WM_NCPAINT 0x0085
#وصف_ڪريو WM_NCACTIVATE 0x0086
#وصف_ڪريو WM_GETDLGCODE 0x0087
#جيڪڏهن_وصف_نه_ٿيل _WIN32_WCE
#وصف_ڪريو WM_SYNCPAINT 0x0088
#جيڪڏهن_پورو
#وصف_ڪريو WM_NCMOUSEMOVE 0x00A0
#وصف_ڪريو WM_NCLBUTTONDOWN 0x00A1
#وصف_ڪريو WM_NCLBUTTONUP 0x00A2
#وصف_ڪريو WM_NCLBUTTONDBLCLK 0x00A3
#وصف_ڪريو WM_NCRBUTTONDOWN 0x00A4
#وصف_ڪريو WM_NCRBUTTONUP 0x00A5
#وصف_ڪريو WM_NCRBUTTONDBLCLK 0x00A6
#وصف_ڪريو WM_NCMBUTTONDOWN 0x00A7
#وصف_ڪريو WM_NCMBUTTONUP 0x00A8
#وصف_ڪريو WM_NCMBUTTONDBLCLK 0x00A9

#وصف_ڪريو WM_NCXBUTTONDOWN 0x00AB
#وصف_ڪريو WM_NCXBUTTONUP 0x00AC
#وصف_ڪريو WM_NCXBUTTONDBLCLK 0x00AD
#وصف_ڪريو WM_داخلا 0x00FF
#وصف_ڪريو WM_KEYFIRST 0x0100
#وصف_ڪريو WM_KEYDOWN 0x0100
#وصف_ڪريو WM_KEYUP 0x0101
#وصف_ڪريو WM_CHAR 0x0102
#وصف_ڪريو WM_DEADCHAR 0x0103
#وصف_ڪريو WM_SYSKEYDOWN 0x0104
#وصف_ڪريو WM_SYSKEYUP 0x0105
#وصف_ڪريو WM_SYSCHAR 0x0106
#وصف_ڪريو WM_SYSDEADCHAR 0x0107
#وصف_ڪريو WM_UNICHAR 0x0109
#وصف_ڪريو WM_KEYLAST 0x0109
#وصف_ڪريو UNICODE_NOCHAR 0xFFFF
#وصف_ڪريو WM_IME_STARTCOMPOSITION 0x010D
#وصف_ڪريو WM_IME_ENDCOMPOSITION 0x010E
#وصف_ڪريو WM_IME_COMPOSITION 0x010F
#وصف_ڪريو WM_IME_KEYLAST 0x010F
#وصف_ڪريو WM_INITDIALOG 0x0110
#وصف_ڪريو WM_COMMAND 0x0111
#وصف_ڪريو WM_SYSCOMMAND 0x0112
#وصف_ڪريو WM_TIMER 0x0113
#وصف_ڪريو WM_HSCROLL 0x0114
#وصف_ڪريو WM_VSCROLL 0x0115
#وصف_ڪريو WM_INITMENU 0x0116
#وصف_ڪريو WM_INITMENUPOPUP 0x0117
#وصف_ڪريو WM_MENUSELECT 0x011F
#وصف_ڪريو WM_MENUCHAR 0x0120
#وصف_ڪريو WM_ENTERIDLE 0x0121
#جيڪڏهن_وصف_نه_ٿيل _WIN32_WCE
#وصف_ڪريو WM_MENURBUTTONUP 0x0122
#وصف_ڪريو WM_MENUDRAG 0x0123
#وصف_ڪريو WM_MENUGETOBJECT 0x0124
#وصف_ڪريو WM_UNINITMENUPOPUP 0x0125
#وصف_ڪريو WM_MENUCOMMAND 0x0126

#جيڪڏهن_وصف_نه_ٿيل _WIN32_WCE
#وصف_ڪريو WM_CHANGEUISTATE 0x0127
#وصف_ڪريو WM_UPDATEUISTATE 0x0128
#وصف_ڪريو WM_QUERYUISTATE 0x0129

#وصف_ڪريو UIS_سيٽ 1
#وصف_ڪريو UIS_CLEAR 2
#وصف_ڪريو UIS_INITIALIZE 3

#وصف_ڪريو UISF_HIDEFOCUS 0x1
#وصف_ڪريو UISF_HIDEACCEL 0x2
#وصف_ڪريو UISF_سرگرم 0x4
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو WM_CTLCOLORMSGBOX 0x0132
#وصف_ڪريو WM_CTLCOLOREDIT 0x0133
#وصف_ڪريو WM_CTLCOLORLISTBOX 0x0134
#وصف_ڪريو WM_CTLCOLORBTN 0x0135
#وصف_ڪريو WM_CTLCOLORDLG 0x0136
#وصف_ڪريو WM_CTLCOLORSCROLLBAR 0x0137
#وصف_ڪريو WM_CTLCOLORSTATIC 0x0138
#وصف_ڪريو MN_GETHMENU 0x01E1

#وصف_ڪريو WM_MOUSEFIRST 0x0200
#وصف_ڪريو WM_MOUSEMOVE 0x0200
#وصف_ڪريو WM_LBUTTONDOWN 0x0201
#وصف_ڪريو WM_LBUTTONUP 0x0202
#وصف_ڪريو WM_LBUTTONDBLCLK 0x0203
#وصف_ڪريو WM_RBUTTONDOWN 0x0204
#وصف_ڪريو WM_RBUTTONUP 0x0205
#وصف_ڪريو WM_RBUTTONDBLCLK 0x0206
#وصف_ڪريو WM_MBUTTONDOWN 0x0207
#وصف_ڪريو WM_MBUTTONUP 0x0208
#وصف_ڪريو WM_MBUTTONDBLCLK 0x0209
#وصف_ڪريو WM_MOUSEWHEEL 0x020A
#وصف_ڪريو WM_XBUTTONDOWN 0x020B
#وصف_ڪريو WM_XBUTTONUP 0x020C
#وصف_ڪريو WM_XBUTTONDBLCLK 0x020D
#وصف_ڪريو WM_MOUSEHWHEEL 0x020E
#وصف_ڪريو WM_MOUSELAST 0x020E

#وصف_ڪريو WHEEL_DELTA 120
#وصف_ڪريو GET_WHEEL_DELTA_WPARAM(wParam) ((ننڍو)HIWORD(wParam))

#وصف_ڪريو WHEEL_PAGESCROLL (UINT_MAX)

#وصف_ڪريو GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#وصف_ڪريو GET_NCHITTEST_WPARAM(wParam) ((ننڍو)LOWORD(wParam))
#وصف_ڪريو GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#وصف_ڪريو XBUTTON1 0x0001
#وصف_ڪريو XBUTTON2 0x0002

#وصف_ڪريو WM_PARENTNOTIFY 0x0210
#وصف_ڪريو WM_ENTERMENULOOP 0x0211
#وصف_ڪريو WM_EXITMENULOOP 0x0212

#وصف_ڪريو WM_NEXTMENU 0x0213
#وصف_ڪريو WM_SIZING 0x0214
#وصف_ڪريو WM_CAPTURECHANGED 0x0215
#وصف_ڪريو WM_MOVING 0x0216

#وصف_ڪريو WM_POWERBROADCAST 0x0218

#جيڪڏهن_وصف_نه_ٿيل _WIN32_WCE
#وصف_ڪريو PBT_APMQUERYSUSPEND 0x0000
#وصف_ڪريو PBT_APMQUERYSTANDBY 0x0001

#وصف_ڪريو PBT_APMQUERYSUSPENDFAILED 0x0002
#وصف_ڪريو PBT_APMQUERYSTANDBYFAILED 0x0003

#وصف_ڪريو PBT_APMSUSPEND 0x0004
#وصف_ڪريو PBT_APMSTANDBY 0x0005

#وصف_ڪريو PBT_APMRESUMECRITICAL 0x0006
#وصف_ڪريو PBT_APMRESUMESUSPEND 0x0007
#وصف_ڪريو PBT_APMRESUMESTANDBY 0x0008

#وصف_ڪريو PBTF_APMRESUMEFROMFAILURE 0x00000001

#وصف_ڪريو PBT_APMBATTERYLOW 0x0009
#وصف_ڪريو PBT_APMPOWERSTATUSCHANGE 0x000A

#وصف_ڪريو PBT_APMOEMEVENT 0x000B
#وصف_ڪريو PBT_APMRESUMEAUTOMATIC 0x0012
#جيڪڏهن_پورو

#وصف_ڪريو WM_DEVICECHANGE 0x0219

#وصف_ڪريو WM_MDICREATE 0x0220
#وصف_ڪريو WM_MDIDESTROY 0x0221
#وصف_ڪريو WM_MDIACTIVATE 0x0222
#وصف_ڪريو WM_MDIRESTORE 0x0223
#وصف_ڪريو WM_MDINEXT 0x0224
#وصف_ڪريو WM_MDIMAXIMIZE 0x0225
#وصف_ڪريو WM_MDITILE 0x0226
#وصف_ڪريو WM_MDICASCADE 0x0227
#وصف_ڪريو WM_MDIICONARRANGE 0x0228
#وصف_ڪريو WM_MDIGETACTIVE 0x0229

#وصف_ڪريو WM_MDISETMENU 0x0230
#وصف_ڪريو WM_ENTERSIZEMOVE 0x0231
#وصف_ڪريو WM_EXITSIZEMOVE 0x0232
#وصف_ڪريو WM_DROPFILES 0x0233
#وصف_ڪريو WM_MDIREFRESHMENU 0x0234

#وصف_ڪريو WM_IME_SETCONTEXT 0x0281
#وصف_ڪريو WM_IME_NOTIFY 0x0282
#وصف_ڪريو WM_IME_CONTROL 0x0283
#وصف_ڪريو WM_IME_COMPOSITIONFULL 0x0284
#وصف_ڪريو WM_IME_SELECT 0x0285
#وصف_ڪريو WM_IME_CHAR 0x0286
#وصف_ڪريو WM_IME_REQUEST 0x0288
#وصف_ڪريو WM_IME_KEYDOWN 0x0290
#وصف_ڪريو WM_IME_KEYUP 0x0291

#وصف_ڪريو WM_MOUSEHOVER 0x02A1
#وصف_ڪريو WM_MOUSELEAVE 0x02A3
#وصف_ڪريو WM_NCMOUSEHOVER 0x02A0
#وصف_ڪريو WM_NCMOUSELEAVE 0x02A2
#وصف_ڪريو WM_WTSSESSION_CHANGE 0x02B1
#وصف_ڪريو WM_TABLET_پهريون 0x02c0
#وصف_ڪريو WM_TABLET_آخري 0x02df
#وصف_ڪريو WM_CUT 0x0300
#وصف_ڪريو WM_COPY 0x0301
#وصف_ڪريو WM_PASTE 0x0302
#وصف_ڪريو WM_CLEAR 0x0303
#وصف_ڪريو WM_UNDO 0x0304
#وصف_ڪريو WM_RENDERFORMAT 0x0305
#وصف_ڪريو WM_RENDERALLFORMATS 0x0306
#وصف_ڪريو WM_DESTROYCLIPBOARD 0x0307
#وصف_ڪريو WM_DRAWCLIPBOARD 0x0308
#وصف_ڪريو WM_PAINTCLIPBOARD 0x0309
#وصف_ڪريو WM_VSCROLLCLIPBOARD 0x030A
#وصف_ڪريو WM_SIZECLIPBOARD 0x030B
#وصف_ڪريو WM_ASKCBFORMATNAME 0x030C
#وصف_ڪريو WM_CHANGECBCHAIN 0x030D
#وصف_ڪريو WM_HSCROLLCLIPBOARD 0x030E
#وصف_ڪريو WM_QUERYNEWPALETTE 0x030F
#وصف_ڪريو WM_PALETTEISCHANGING 0x0310
#وصف_ڪريو WM_PALETTECHANGED 0x0311
#وصف_ڪريو WM_HOTKEY 0x0312
#وصف_ڪريو WM_PRINT 0x0317
#وصف_ڪريو WM_PRINTCLIENT 0x0318
#وصف_ڪريو WM_APPCOMMAND 0x0319
#وصف_ڪريو WM_THEMECHANGED 0x031A
#وصف_ڪريو WM_HANDHELDFIRST 0x0358
#وصف_ڪريو WM_HANDHELDLAST 0x035F
#وصف_ڪريو WM_AFXFIRST 0x0360
#وصف_ڪريو WM_AFXLAST 0x037F
#وصف_ڪريو WM_PENWINFIRST 0x0380
#وصف_ڪريو WM_PENWINLAST 0x038F
#وصف_ڪريو WM_APP 0x8000
#وصف_ڪريو WM_USER 0x0400

#وصف_ڪريو WMSZ_کاٻو 1
#وصف_ڪريو WMSZ_ساڄو 2
#وصف_ڪريو WMSZ_چوٽي 3
#وصف_ڪريو WMSZ_TOPLEFT 4
#وصف_ڪريو WMSZ_TOPRIGHT 5
#وصف_ڪريو WMSZ_BOTTOM 6
#وصف_ڪريو WMSZ_BOTTOMLEFT 7
#وصف_ڪريو WMSZ_BOTTOMRIGHT 8

#جيڪڏهن_وصف_نه_ٿيل NONCMESSAGES

#وصف_ڪريو HTERROR (-2)
#وصف_ڪريو HTTRANSPARENT (-1)
#وصف_ڪريو HTNOWHERE 0
#وصف_ڪريو HTCLIENT 1
#وصف_ڪريو HTCAPTION 2
#وصف_ڪريو HTSYSMENU 3
#وصف_ڪريو HTGROWBOX 4
#وصف_ڪريو HTSIZE HTGROWBOX
#وصف_ڪريو HTMENU 5
#وصف_ڪريو HTHSCROLL 6
#وصف_ڪريو HTVSCROLL 7
#وصف_ڪريو HTMINBUTTON 8
#وصف_ڪريو HTMAXBUTTON 9
#وصف_ڪريو HTLEFT 10
#وصف_ڪريو HTRIGHT 11
#وصف_ڪريو HTTOP 12
#وصف_ڪريو HTTOPLEFT 13
#وصف_ڪريو HTTOPRIGHT 14
#وصف_ڪريو HTBOTTOM 15
#وصف_ڪريو HTBOTTOMLEFT 16
#وصف_ڪريو HTBOTTOMRIGHT 17
#وصف_ڪريو HTBORDER 18
#وصف_ڪريو HTREDUCE HTMINBUTTON
#وصف_ڪريو HTZOOM HTMAXBUTTON
#وصف_ڪريو HTSIZEFIRST HTLEFT
#وصف_ڪريو HTSIZELAST HTBOTTOMRIGHT
#وصف_ڪريو HTOBJECT 19
#وصف_ڪريو HTCLOSE 20
#وصف_ڪريو HTHELP 21

#وصف_ڪريو SMTO_عام 0x0000
#وصف_ڪريو SMTO_بلاڪ 0x0001
#وصف_ڪريو SMTO_ABORTIFHUNG 0x0002
#وصف_ڪريو SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#جيڪڏهن_پورو

#وصف_ڪريو MA_ACTIVATE 1
#وصف_ڪريو MA_ACTIVATEANDEAT 2
#وصف_ڪريو MA_NOACTIVATE 3
#وصف_ڪريو MA_NOACTIVATEANDEAT 4

#وصف_ڪريو ICON_SMALL 0
#وصف_ڪريو ICON_BIG 1
#وصف_ڪريو ICON_SMALL2 2

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو رجسٽر_دري_پيغام رجسٽر_دري_پيغام_W
#وإلا
#وصف_ڪريو رجسٽر_دري_پيغام رجسٽر_دري_پيغام_A
#جيڪڏهن_پورو

  WINUSERAPI UINT WINAPI رجسٽر_دري_پيغام_A(LPCSTR lpString);
  WINUSERAPI UINT WINAPI رجسٽر_دري_پيغام_W(LPCWSTR lpString);

#وصف_ڪريو سائيز_RESTORED 0
#وصف_ڪريو سائيز_MINIMIZED 1
#وصف_ڪريو سائيز_MAXIMIZED 2
#وصف_ڪريو سائيز_MAXSHOW 3
#وصف_ڪريو سائيز_MAXHIDE 4

#وصف_ڪريو SIZENORMAL سائيز_RESTORED
#وصف_ڪريو SIZEICONIC سائيز_MINIMIZED
#وصف_ڪريو SIZEFULLSCREEN سائيز_MAXIMIZED
#وصف_ڪريو SIZEZOOMSHOW سائيز_MAXSHOW
#وصف_ڪريو SIZEZOOMHIDE سائيز_MAXHIDE

  تعريفنوع بنية ٽيگ_WINDOWPOS {
    HWND hwnd;
    HWND hwnd_وجهو_After;
    صحيح x;
    صحيح y;
    صحيح cx;
    صحيح cy;
    UINT flags;
  } WINDOWPOS,*LPWINDOWPOS,*PWINDOWPOS;

  تعريفنوع بنية ٽيگ_NCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
  } NCCALCSIZE_PARAMS,*LPNCCALCSIZE_PARAMS;

#وصف_ڪريو WVR_ALIGNTOP 0x0010
#وصف_ڪريو WVR_ALIGNLEFT 0x0020
#وصف_ڪريو WVR_ALIGNBOTTOM 0x0040
#وصف_ڪريو WVR_ALIGNRIGHT 0x0080
#وصف_ڪريو WVR_HREDRAW 0x0100
#وصف_ڪريو WVR_VREDRAW 0x0200
#وصف_ڪريو WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#وصف_ڪريو WVR_VALIDRECTS 0x0400

#جيڪڏهن_وصف_نه_ٿيل NOKEYSTATES

#وصف_ڪريو MK_LBUTTON 0x0001
#وصف_ڪريو MK_RBUTTON 0x0002
#وصف_ڪريو MK_سرڪايو 0x0004
#وصف_ڪريو MK_CONTROL 0x0008
#وصف_ڪريو MK_MBUTTON 0x0010
#وصف_ڪريو MK_XBUTTON1 0x0020
#وصف_ڪريو MK_XBUTTON2 0x0040
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOTRACKMOUSEEVENT
#وصف_ڪريو TME_HOVER 0x00000001
#وصف_ڪريو TME_LEAVE 0x00000002
#وصف_ڪريو TME_NONCLIENT 0x00000010
#وصف_ڪريو TME_QUERY 0x40000000
#وصف_ڪريو TME_CANCEL 0x80000000

#وصف_ڪريو HOVER_DEFAULT 0xFFFFFFFF
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_TRACKMOUSEEVENT {
    DWORD cb_سائيز;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dw_Hover_وقت;
  } TRACKMOUSEEVENT,*LPTRACKMOUSEEVENT;

  WINUSERAPI WINBOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOWINSTYLES

#وصف_ڪريو WS_OVERLAPPED 0x00000000L
#وصف_ڪريو WS_POPUP 0x80000000L
#وصف_ڪريو WS_ٻار 0x40000000L
#وصف_ڪريو WS_MINIMIZE 0x20000000L
#وصف_ڪريو WS_VISIBLE 0x10000000L
#وصف_ڪريو WS_DISABLED 0x08000000L
#وصف_ڪريو WS_CLIPSIBLINGS 0x04000000L
#وصف_ڪريو WS_CLIPCHILDREN 0x02000000L
#وصف_ڪريو WS_MAXIMIZE 0x01000000L
#وصف_ڪريو WS_CAPTION 0x00C00000L
#وصف_ڪريو WS_BORDER 0x00800000L
#وصف_ڪريو WS_DLGFRAME 0x00400000L
#وصف_ڪريو WS_VSCROLL 0x00200000L
#وصف_ڪريو WS_HSCROLL 0x00100000L
#وصف_ڪريو WS_SYSMENU 0x00080000L
#وصف_ڪريو WS_THICKFRAME 0x00040000L
#وصف_ڪريو WS_گروهه 0x00020000L
#وصف_ڪريو WS_TABSTOP 0x00010000L
#وصف_ڪريو WS_MINIMIZEBOX 0x00020000L
#وصف_ڪريو WS_MAXIMIZEBOX 0x00010000L
#وصف_ڪريو WS_TILED WS_OVERLAPPED
#وصف_ڪريو WS_ICONIC WS_MINIMIZE
#وصف_ڪريو WS_SIZEBOX WS_THICKFRAME
#وصف_ڪريو WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#وصف_ڪريو WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#وصف_ڪريو WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#وصف_ڪريو WS_CHILDWINDOW (WS_ٻار)

#وصف_ڪريو WS_EX_DLGMODALFRAME 0x00000001L
#وصف_ڪريو WS_EX_NOPARENTNOTIFY 0x00000004L
#وصف_ڪريو WS_EX_TOPMOST 0x00000008L
#وصف_ڪريو WS_EX_ACCEPTFILES 0x00000010L
#وصف_ڪريو WS_EX_TRANSPARENT 0x00000020L
#وصف_ڪريو WS_EX_MDICHILD 0x00000040L
#وصف_ڪريو WS_EX_TOOLWINDOW 0x00000080L
#وصف_ڪريو WS_EX_WINDOWEDGE 0x00000100L
#وصف_ڪريو WS_EX_CLIENTEDGE 0x00000200L
#وصف_ڪريو WS_EX_CONTEXTHELP 0x00000400L
#وصف_ڪريو WS_EX_ساڄو 0x00001000L
#وصف_ڪريو WS_EX_کاٻو 0x00000000L
#وصف_ڪريو WS_EX_RTLREADING 0x00002000L
#وصف_ڪريو WS_EX_LTRREADING 0x00000000L
#وصف_ڪريو WS_EX_LEFTSCROLLBAR 0x00004000L
#وصف_ڪريو WS_EX_RIGHTSCROLLBAR 0x00000000L
#وصف_ڪريو WS_EX_CONTROLPARENT 0x00010000L
#وصف_ڪريو WS_EX_STATICEDGE 0x00020000L
#وصف_ڪريو WS_EX_APPWINDOW 0x00040000L
#وصف_ڪريو WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#وصف_ڪريو WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#وصف_ڪريو WS_EX_LAYERED 0x00080000
#وصف_ڪريو WS_EX_NOINHERITLAYOUT 0x00100000L
#وصف_ڪريو WS_EX_LAYOUTRTL 0x00400000L
#وصف_ڪريو WS_EX_COMPOSITED 0x02000000L
#وصف_ڪريو WS_EX_NOACTIVATE 0x08000000L

#وصف_ڪريو CS_VREDRAW 0x0001
#وصف_ڪريو CS_HREDRAW 0x0002
#وصف_ڪريو CS_DBLCLKS 0x0008
#وصف_ڪريو CS_OWNDC 0x0020
#وصف_ڪريو CS_CLASSDC 0x0040
#وصف_ڪريو CS_PARENTDC 0x0080
#وصف_ڪريو CS_NOCLOSE 0x0200
#وصف_ڪريو CS_SAVEBITS 0x0800
#وصف_ڪريو CS_BYTEALIGNCLIENT 0x1000
#وصف_ڪريو CS_BYTEALIGNWINDOW 0x2000
#وصف_ڪريو CS_GLOBALCLASS 0x4000
#وصف_ڪريو CS_IME 0x00010000
#وصف_ڪريو CS_DROPSHADOW 0x00020000
#جيڪڏهن_پورو

#وصف_ڪريو PRF_CHECKVISIBLE 0x00000001L
#وصف_ڪريو PRF_NONCLIENT 0x00000002L
#وصف_ڪريو PRF_CLIENT 0x00000004L
#وصف_ڪريو PRF_ERASEBKGND 0x00000008L
#وصف_ڪريو PRF_CHILDREN 0x00000010L
#وصف_ڪريو PRF_OWNED 0x00000020L

#وصف_ڪريو BDR_RAISEDOUTER 0x0001
#وصف_ڪريو BDR_SUNKENOUTER 0x0002
#وصف_ڪريو BDR_RAISEDINNER 0x0004
#وصف_ڪريو BDR_SUNKENINNER 0x0008

#وصف_ڪريو BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#وصف_ڪريو BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#وصف_ڪريو BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#وصف_ڪريو BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#وصف_ڪريو ڪنارو_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#وصف_ڪريو ڪنارو_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#وصف_ڪريو ڪنارو_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#وصف_ڪريو ڪنارو_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#وصف_ڪريو BF_کاٻو 0x0001
#وصف_ڪريو BF_چوٽي 0x0002
#وصف_ڪريو BF_ساڄو 0x0004
#وصف_ڪريو BF_BOTTOM 0x0008

#وصف_ڪريو BF_TOPLEFT (BF_چوٽي | BF_کاٻو)
#وصف_ڪريو BF_TOPRIGHT (BF_چوٽي | BF_ساڄو)
#وصف_ڪريو BF_BOTTOMLEFT (BF_BOTTOM | BF_کاٻو)
#وصف_ڪريو BF_BOTTOMRIGHT (BF_BOTTOM | BF_ساڄو)
#وصف_ڪريو BF_RECT (BF_کاٻو | BF_چوٽي | BF_ساڄو | BF_BOTTOM)

#وصف_ڪريو BF_DIAGONAL 0x0010

#وصف_ڪريو BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_چوٽي | BF_ساڄو)
#وصف_ڪريو BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_چوٽي | BF_کاٻو)
#وصف_ڪريو BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_کاٻو)
#وصف_ڪريو BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_ساڄو)

#وصف_ڪريو BF_وچ 0x0800
#وصف_ڪريو BF_SOFT 0x1000
#وصف_ڪريو BF_ADJUST 0x2000
#وصف_ڪريو BF_FLAT 0x4000
#وصف_ڪريو BF_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_ڪنارو(HDC hdc,LPRECT qrc,UINT ڪنارو,UINT grfFlags);

#وصف_ڪريو DFC_CAPTION 1
#وصف_ڪريو DFC_MENU 2
#وصف_ڪريو DFC_SCROLL 3
#وصف_ڪريو DFC_BUTTON 4
#وصف_ڪريو DFC_POPUPMENU 5

#وصف_ڪريو DFCS_CAPTIONCLOSE 0x0000
#وصف_ڪريو DFCS_CAPTIONMIN 0x0001
#وصف_ڪريو DFCS_CAPTIONMAX 0x0002
#وصف_ڪريو DFCS_CAPTIONRESTORE 0x0003
#وصف_ڪريو DFCS_CAPTIONHELP 0x0004

#وصف_ڪريو DFCS_MENUARROW 0x0000
#وصف_ڪريو DFCS_MENUCHECK 0x0001
#وصف_ڪريو DFCS_MENUBULLET 0x0002
#وصف_ڪريو DFCS_MENUARROWRIGHT 0x0004
#وصف_ڪريو DFCS_SCROLLUP 0x0000
#وصف_ڪريو DFCS_SCROLLDOWN 0x0001
#وصف_ڪريو DFCS_SCROLLLEFT 0x0002
#وصف_ڪريو DFCS_SCROLLRIGHT 0x0003
#وصف_ڪريو DFCS_SCROLLCOMBOBOX 0x0005
#وصف_ڪريو DFCS_SCROLLSIZEGRIP 0x0008
#وصف_ڪريو DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#وصف_ڪريو DFCS_BUTTONCHECK 0x0000
#وصف_ڪريو DFCS_BUTTONRADIOIMAGE 0x0001
#وصف_ڪريو DFCS_BUTTONRADIOMASK 0x0002
#وصف_ڪريو DFCS_BUTTONRADIO 0x0004
#وصف_ڪريو DFCS_BUTTON3STATE 0x0008
#وصف_ڪريو DFCS_BUTTONPUSH 0x0010

#وصف_ڪريو DFCS_INACTIVE 0x0100
#وصف_ڪريو DFCS_PUSHED 0x0200
#وصف_ڪريو DFCS_CHECKED 0x0400

#وصف_ڪريو DFCS_TRANSPARENT 0x0800
#وصف_ڪريو DFCS_HOT 0x1000

#وصف_ڪريو DFCS_ADJUSTRECT 0x2000
#وصف_ڪريو DFCS_FLAT 0x4000
#وصف_ڪريو DFCS_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_چوکٺو_Control(HDC,LPRECT,UINT,UINT);

#وصف_ڪريو DC_سرگرم 0x0001
#وصف_ڪريو DC_SMALLCAP 0x0002
#وصف_ڪريو DC_ICON 0x0004
#وصف_ڪريو DC_متن 0x0008
#وصف_ڪريو DC_INBUTTON 0x0010
#وصف_ڪريو DC_GRADIENT 0x0020
#وصف_ڪريو DC_BUTTONS 0x1000

  WINUSERAPI WINBOOL WINAPI DrawCaption(HWND hwnd,HDC hdc,CONST RECT *lprect,UINT flags);

#وصف_ڪريو IDANI_OPEN 1
#وصف_ڪريو IDANI_CAPTION 3

  WINUSERAPI WINBOOL WINAPI DrawAnimatedRects(HWND hwnd,صحيح idAni,CONST RECT *lprcFrom,CONST RECT *lprc_منزل);

#جيڪڏهن_وصف_نه_ٿيل NOCLIPBOARD

#وصف_ڪريو CF_متن 1
#وصف_ڪريو CF_BITMAP 2
#وصف_ڪريو CF_METAFILEPICT 3
#وصف_ڪريو CF_SYLK 4
#وصف_ڪريو CF_DIF 5
#وصف_ڪريو CF_TIFF 6
#وصف_ڪريو CF_OEMTEXT 7
#وصف_ڪريو CF_DIB 8
#وصف_ڪريو CF_PALETTE 9
#وصف_ڪريو CF_PENDATA 10
#وصف_ڪريو CF_RIFF 11
#وصف_ڪريو CF_WAVE 12
#وصف_ڪريو CF_UNICODETEXT 13
#وصف_ڪريو CF_ENHMETAFILE 14
#وصف_ڪريو CF_HDROP 15
#وصف_ڪريو CF_LOCALE 16
#وصف_ڪريو CF_DIBV5 17
#وصف_ڪريو CF_MAX 18

#وصف_ڪريو CF_OWNERDISPLAY 0x0080
#وصف_ڪريو CF_DSPTEXT 0x0081
#وصف_ڪريو CF_DSPBITMAP 0x0082
#وصف_ڪريو CF_DSPMETAFILEPICT 0x0083
#وصف_ڪريو CF_DSPENHMETAFILE 0x008E

#وصف_ڪريو CF_PRIVATEFIRST 0x0200
#وصف_ڪريو CF_PRIVATELAST 0x02FF

#وصف_ڪريو CF_GDIOBJFIRST 0x0300
#وصف_ڪريو CF_GDIOBJLAST 0x03FF
#جيڪڏهن_پورو

#وصف_ڪريو FVIRTKEY TRUE
#وصف_ڪريو FNOINVERT 0x02
#وصف_ڪريو FSHIFT 0x04
#وصف_ڪريو FCONTROL 0x08
#وصف_ڪريو FALT 0x10

  تعريفنوع بنية ٽيگ_ACCEL {
    BYTE fVirt;
    لفظ_3 ڪنجي;
    لفظ_3 cmd;
  } ACCEL,*LPACCEL;

  تعريفنوع بنية ٽيگ_PAINTSTRUCT {
    HDC hdc;
    WINBOOL fErase;
    RECT rcPaint;
    WINBOOL fRestore;
    WINBOOL fIncUpdate;
    BYTE rgbReserved[32];
  } PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;

  تعريفنوع بنية ٽيگ_CREATESTRUCTA {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_والد_2;
    صحيح cy;
    صحيح cx;
    صحيح y;
    صحيح x;
    LONG style;
    LPCSTR lpszName;
    LPCSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTA,*LPCREATESTRUCTA;

  تعريفنوع بنية ٽيگ_CREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_والد_2;
    صحيح cy;
    صحيح cx;
    صحيح y;
    صحيح x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTW,*LPCREATESTRUCTW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع CREATESTRUCTW CREATESTRUCT;
  تعريفنوع LPCREATESTRUCTW LPCREATESTRUCT;
#وإلا
  تعريفنوع CREATESTRUCTA CREATESTRUCT;
  تعريفنوع LPCREATESTRUCTA LPCREATESTRUCT;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_WINDOWPLACEMENT {
    UINT ڊيگهائي;
    UINT flags;
    UINT showCmd;
    نقطو_3 ptMinPosition;
    نقطو_3 ptMaxPosition;
    RECT rc_عام_Position;
  } WINDOWPLACEMENT;
  تعريفنوع WINDOWPLACEMENT *PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;

#وصف_ڪريو WPF_SETMINPOSITION 0x0001
#وصف_ڪريو WPF_RESTORETOMAXIMIZED 0x0002
#وصف_ڪريو WPF_ASYNCWINDOWPLACEMENT 0x0004

  تعريفنوع بنية ٽيگ_NMHDR {
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT ڪوڊ;
  } NMHDR;

  تعريفنوع NMHDR *LPNMHDR;

  تعريفنوع بنية ٽيگ_STYLESTRUCT {
    DWORD styleOld;
    DWORD styleNew;
  } STYLESTRUCT,*LPSTYLESTRUCT;

#وصف_ڪريو ODT_MENU 1
#وصف_ڪريو ODT_LISTBOX 2
#وصف_ڪريو ODT_COMBOBOX 3
#وصف_ڪريو ODT_BUTTON 4
#وصف_ڪريو ODT_STATIC 5

#وصف_ڪريو ODA_DRAWENTIRE 0x0001
#وصف_ڪريو ODA_SELECT 0x0002
#وصف_ڪريو ODA_FOCUS 0x0004

#وصف_ڪريو ODS_SELECTED 0x0001
#وصف_ڪريو ODS_GRAYED 0x0002
#وصف_ڪريو ODS_DISABLED 0x0004
#وصف_ڪريو ODS_CHECKED 0x0008
#وصف_ڪريو ODS_FOCUS 0x0010
#وصف_ڪريو ODS_DEFAULT 0x0020
#وصف_ڪريو ODS_COMBOBOXEDIT 0x1000
#وصف_ڪريو ODS_HOTLIGHT 0x0040
#وصف_ڪريو ODS_INACTIVE 0x0080
#وصف_ڪريو ODS_NOACCEL 0x0100
#وصف_ڪريو ODS_NOFOCUSRECT 0x0200

  تعريفنوع بنية ٽيگ_MEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT شي_ID;
    UINT شي_ويڪر;
    UINT شي_اوچائي;
    ULONG_PTR شي_معلومات;
  } MEASUREITEMSTRUCT,*PMEASUREITEMSTRUCT,*LPMEASUREITEMSTRUCT;

  تعريفنوع بنية ٽيگ_DRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT شي_ID;
    UINT شي_Action;
    UINT شي_State;
    HWND hwnd_شي;
    HDC hDC;
    RECT rc_شي;
    ULONG_PTR شي_معلومات;
  } DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;

  تعريفنوع بنية ٽيگ_DELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT شي_ID;
    HWND hwnd_شي;
    ULONG_PTR شي_معلومات;
  } DELETEITEMSTRUCT,*PDELETEITEMSTRUCT,*LPDELETEITEMSTRUCT;

  تعريفنوع بنية ٽيگ_COMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwnd_شي;
    UINT شي_ID1;
    ULONG_PTR شي_Data1;
    UINT شي_ID2;
    ULONG_PTR شي_Data2;
    DWORD dwLocaleId;
  } COMPAREITEMSTRUCT,*PCOMPAREITEMSTRUCT,*LPCOMPAREITEMSTRUCT;

#جيڪڏهن_وصف_نه_ٿيل NOMSG
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_پيغام Get_پيغام_W
#وصف_ڪريو Dispatch_پيغام Dispatch_پيغام_W
#وصف_ڪريو Peek_پيغام Peek_پيغام_W
#وإلا
#وصف_ڪريو Get_پيغام Get_پيغام_A
#وصف_ڪريو Dispatch_پيغام Dispatch_پيغام_A
#وصف_ڪريو Peek_پيغام Peek_پيغام_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI Get_پيغام_A(LPMSG lp_نياپو,HWND hWnd,UINT w_نياپو_Filter_Min,UINT w_نياپو_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Get_پيغام_W(LPMSG lp_نياپو,HWND hWnd,UINT w_نياپو_Filter_Min,UINT w_نياپو_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Translate_پيغام(CONST نياپو_2 *lp_نياپو);
  WINUSERAPI LRESULT WINAPI Dispatch_پيغام_A(CONST نياپو_2 *lp_نياپو);
  WINUSERAPI LRESULT WINAPI Dispatch_پيغام_W(CONST نياپو_2 *lp_نياپو);
  WINUSERAPI WINBOOL WINAPI سيٽ_پيغام_قطار(صحيح cMessagesMax);
  WINUSERAPI WINBOOL WINAPI Peek_پيغام_A(LPMSG lp_نياپو,HWND hWnd,UINT w_نياپو_Filter_Min,UINT w_نياپو_Filter_Max,UINT w_Remove_نياپو);
  WINUSERAPI WINBOOL WINAPI Peek_پيغام_W(LPMSG lp_نياپو,HWND hWnd,UINT w_نياپو_Filter_Min,UINT w_نياپو_Filter_Max,UINT w_Remove_نياپو);

#وصف_ڪريو PM_NOREMOVE 0x0000
#وصف_ڪريو PM_REMOVE 0x0001
#وصف_ڪريو PM_NOYIELD 0x0002
#وصف_ڪريو PM_QS_داخلا (QS_داخلا << 16)
#وصف_ڪريو PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#وصف_ڪريو PM_QS_PAINT (QS_PAINT << 16)
#وصف_ڪريو PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI رجسٽر_Hot_ڪنجي(HWND hWnd,صحيح id,UINT fsModifiers,UINT vk);
  WINUSERAPI WINBOOL WINAPI Unregister_Hot_ڪنجي(HWND hWnd,صحيح id);

#وصف_ڪريو MOD_ALT 0x0001
#وصف_ڪريو MOD_CONTROL 0x0002
#وصف_ڪريو MOD_سرڪايو 0x0004
#وصف_ڪريو MOD_WIN 0x0008

#وصف_ڪريو IDHOT_SNAPWINDOW (-1)
#وصف_ڪريو IDHOT_SNAPDESKTOP (-2)

#جيڪڏهن_وصف_ٿيل WIN_اندروني
#جيڪڏهن_وصف_نه_ٿيل LSTRING
#وصف_ڪريو NOLSTRING
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل LFILEIO
#وصف_ڪريو NOLFILEIO
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو ENDSESSION_LOGOFF 0x80000000

#وصف_ڪريو EWX_LOGOFF 0
#وصف_ڪريو EWX_SHUTDOWN 0x00000001
#وصف_ڪريو EWX_REBOOT 0x00000002
#وصف_ڪريو EWX_FORCE 0x00000004
#وصف_ڪريو EWX_POWEROFF 0x00000008
#وصف_ڪريو EWX_FORCEIFHUNG 0x00000010

#وصف_ڪريو ExitWindows(dwReserved,ڪوڊ_4) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Send_پيغام Send_پيغام_W
#وصف_ڪريو Send_پيغام_Timeout Send_پيغام_Timeout_W
#وصف_ڪريو Send_Notify_پيغام Send_Notify_پيغام_W
#وصف_ڪريو Send_پيغام_Callback Send_پيغام_Callback_W
#وإلا
#وصف_ڪريو Send_پيغام Send_پيغام_A
#وصف_ڪريو Send_پيغام_Timeout Send_پيغام_Timeout_A
#وصف_ڪريو Send_Notify_پيغام Send_Notify_پيغام_A
#وصف_ڪريو Send_پيغام_Callback Send_پيغام_Callback_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI ExitWindowsEx(UINT uFlags,DWORD dwReason);
  WINUSERAPI WINBOOL WINAPI مٽا_سٽا_Mouse_Button(WINBOOL f_مٽا_سٽا);
  WINUSERAPI DWORD WINAPI Get_پيغام_Pos(VOID);
  WINUSERAPI LONG WINAPI Get_پيغام_وقت(VOID);
  WINUSERAPI LPARAM WINAPI Get_پيغام_Extra_Info(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Wow64_پيغام(VOID);
  WINUSERAPI LPARAM WINAPI سيٽ_پيغام_Extra_Info(LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_پيغام_A(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_پيغام_W(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_پيغام_Timeout_A(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_نتيجو);
  WINUSERAPI LRESULT WINAPI Send_پيغام_Timeout_W(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_نتيجو);
  WINUSERAPI WINBOOL WINAPI Send_Notify_پيغام_A(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_Notify_پيغام_W(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_پيغام_Callback_A(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_نتيجو_Call_پٺ,ULONG_PTR dw_معلومات);
  WINUSERAPI WINBOOL WINAPI Send_پيغام_Callback_W(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_نتيجو_Call_پٺ,ULONG_PTR dw_معلومات);

  تعريفنوع بنية {
    UINT cb_سائيز;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
  } BSMINFO,*PBSMINFO;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو نشر_System_پيغام_Ex نشر_System_پيغام_Ex_W
#وصف_ڪريو نشر_System_پيغام نشر_System_پيغام_W
#وإلا
#وصف_ڪريو نشر_System_پيغام_Ex نشر_System_پيغام_Ex_A
#وصف_ڪريو نشر_System_پيغام نشر_System_پيغام_A
#جيڪڏهن_پورو

  WINUSERAPI ڊگهو WINAPI نشر_System_پيغام_Ex_A(DWORD flags,LPDWORD lpInfo,UINT نياپو_3,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI ڊگهو WINAPI نشر_System_پيغام_Ex_W(DWORD flags,LPDWORD lpInfo,UINT نياپو_3,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI ڊگهو WINAPI نشر_System_پيغام_A(DWORD flags,LPDWORD lpInfo,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI ڊگهو WINAPI نشر_System_پيغام_W(DWORD flags,LPDWORD lpInfo,UINT نياپو_3,WPARAM wParam,LPARAM lParam);

#وصف_ڪريو BSM_ALLCOMPONENTS 0x00000000
#وصف_ڪريو BSM_VXDS 0x00000001
#وصف_ڪريو BSM_NETDRIVER 0x00000002
#وصف_ڪريو BSM_INSTALLABLEDRIVERS 0x00000004
#وصف_ڪريو BSM_APPLICATIONS 0x00000008
#وصف_ڪريو BSM_ALLDESKTOPS 0x00000010

#وصف_ڪريو BSF_QUERY 0x00000001
#وصف_ڪريو BSF_IGNORECURRENTTASK 0x00000002
#وصف_ڪريو BSF_FLUSHDISK 0x00000004
#وصف_ڪريو BSF_NOHANG 0x00000008
#وصف_ڪريو BSF_POSTMESSAGE 0x00000010
#وصف_ڪريو BSF_FORCEIFHUNG 0x00000020
#وصف_ڪريو BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#وصف_ڪريو BSF_ALLOWSFW 0x00000080
#وصف_ڪريو BSF_SENDNOTIFYMESSAGE 0x00000100
#وصف_ڪريو BSF_RETURNHDESK 0x00000200
#وصف_ڪريو BSF_LUID 0x00000400

#وصف_ڪريو نشر_QUERY_DENY 0x424D5144

  تعريفنوع PVOID HDEVNOTIFY;
  تعريفنوع HDEVNOTIFY *PHDEVNOTIFY;

#وصف_ڪريو DEVICE_NOTIFY_دري_HANDLE 0x00000000
#وصف_ڪريو DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#وصف_ڪريو DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو رجسٽر_Device_Notification رجسٽر_Device_Notification_W
#وصف_ڪريو Post_پيغام Post_پيغام_W
#وصف_ڪريو Post_Thread_پيغام Post_Thread_پيغام_W
#وصف_ڪريو Post_App_پيغام Post_App_پيغام_W
#وصف_ڪريو Def_دري_Proc Def_دري_Proc_W
#وصف_ڪريو Call_دري_Proc Call_دري_Proc_W
#وصف_ڪريو رجسٽر_Class رجسٽر_Class_W
#وصف_ڪريو UnregisterClass UnregisterClassW
#وصف_ڪريو GetClassInfo GetClassInfoW
#وصف_ڪريو رجسٽر_Class_Ex رجسٽر_Class_Ex_W
#وصف_ڪريو GetClassInfoEx GetClassInfoExW
#وإلا
#وصف_ڪريو رجسٽر_Device_Notification رجسٽر_Device_Notification_A
#وصف_ڪريو Post_پيغام Post_پيغام_A
#وصف_ڪريو Post_Thread_پيغام Post_Thread_پيغام_A
#وصف_ڪريو Post_App_پيغام Post_App_پيغام_A
#وصف_ڪريو Def_دري_Proc Def_دري_Proc_A
#وصف_ڪريو Call_دري_Proc Call_دري_Proc_A
#وصف_ڪريو رجسٽر_Class رجسٽر_Class_A
#وصف_ڪريو UnregisterClass UnregisterClassA
#وصف_ڪريو GetClassInfo GetClassInfoA
#وصف_ڪريو رجسٽر_Class_Ex رجسٽر_Class_Ex_A
#وصف_ڪريو GetClassInfoEx GetClassInfoExA
#جيڪڏهن_پورو

  WINUSERAPI HDEVNOTIFY WINAPI رجسٽر_Device_Notification_A(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI HDEVNOTIFY WINAPI رجسٽر_Device_Notification_W(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI WINBOOL WINAPI UnregisterDeviceNotification(HDEVNOTIFY Handle);
  WINUSERAPI WINBOOL WINAPI Post_پيغام_A(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_پيغام_W(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_پيغام_A(DWORD idThread,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_پيغام_W(DWORD idThread,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
#وصف_ڪريو Post_App_پيغام_A(idThread,w_نياپو,wParam,lParam) Post_Thread_پيغام_A((DWORD)idThread,w_نياپو,wParam,lParam)
#وصف_ڪريو Post_App_پيغام_W(idThread,w_نياپو,wParam,lParam) Post_Thread_پيغام_W((DWORD)idThread,w_نياپو,wParam,lParam)

#وصف_ڪريو HWND_نشر ((HWND)0xffff)
#وصف_ڪريو HWND_پيغام ((HWND)-3)

  WINUSERAPI WINBOOL WINAPI Attach_Thread_داخلا(DWORD idAttach,DWORD id_Attach_منزل,WINBOOL fAttach);
  WINUSERAPI WINBOOL WINAPI جواب_پيغام(LRESULT l_نتيجو);
  WINUSERAPI WINBOOL WINAPI Wait_پيغام(VOID);
  WINUSERAPI DWORD WINAPI Wait_For_داخلا_Idle(HANDLE hProcess,DWORD dwMilliseconds);
  WINUSERAPI LRESULT WINAPI Def_دري_Proc_A(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_دري_Proc_W(HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI VOID WINAPI Post_Quit_پيغام(صحيح n_Exit_ڪوڊ);
  WINUSERAPI LRESULT WINAPI Call_دري_Proc_A(WNDPROC lpPrevWndFunc,HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Call_دري_Proc_W(WNDPROC lpPrevWndFunc,HWND hWnd,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI اندريون_Send_پيغام(VOID);
  WINUSERAPI DWORD WINAPI اندريون_Send_پيغام_Ex(LPVOID lpReserved);

#وصف_ڪريو ISMEX_NOSEND 0x00000000
#وصف_ڪريو ISMEX_SEND 0x00000001
#وصف_ڪريو ISMEX_NOTIFY 0x00000002
#وصف_ڪريو ISMEX_CALLBACK 0x00000004
#وصف_ڪريو ISMEX_REPLIED 0x00000008

  WINUSERAPI UINT WINAPI Get_Double_Click_وقت(VOID);
  WINUSERAPI WINBOOL WINAPI سيٽ_Double_Click_وقت(UINT);
  WINUSERAPI ATOM WINAPI رجسٽر_Class_A(CONST WNDCLASSA *lpWndClass);
  WINUSERAPI ATOM WINAPI رجسٽر_Class_W(CONST WNDCLASSW *lpWndClass);
  WINUSERAPI WINBOOL WINAPI UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
  WINUSERAPI WINBOOL WINAPI GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
  WINUSERAPI ATOM WINAPI رجسٽر_Class_Ex_A(CONST WNDCLASSEXA *);
  WINUSERAPI ATOM WINAPI رجسٽر_Class_Ex_W(CONST WNDCLASSEXW *);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);

#وصف_ڪريو CW_USEDEFAULT ((صحيح)0x80000000)

#وصف_ڪريو HWND_DESKTOP ((HWND)0)

  تعريفنوع BOOLEAN (WINAPI *PREGISTERCLASSNAMEW)(LPCWSTR);

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Create_دري_Ex Create_دري_Ex_W
#وصف_ڪريو Create_دري Create_دري_W
#وإلا
#وصف_ڪريو Create_دري_Ex Create_دري_Ex_A
#وصف_ڪريو Create_دري Create_دري_A
#جيڪڏهن_پورو

  WINUSERAPI HWND WINAPI Create_دري_Ex_A(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lp_دري_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_ويڪر,صحيح n_اوچائي,HWND h_Wnd_والد,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
  WINUSERAPI HWND WINAPI Create_دري_Ex_W(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lp_دري_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_ويڪر,صحيح n_اوچائي,HWND h_Wnd_والد,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
#وصف_ڪريو Create_دري_A(lpClassName,lp_دري_Name,dwStyle,x,y,n_ويڪر,n_اوچائي,h_Wnd_والد,hMenu,hInstance,lpParam) Create_دري_Ex_A(0L,lpClassName,lp_دري_Name,dwStyle,x,y,n_ويڪر,n_اوچائي,h_Wnd_والد,hMenu,hInstance,lpParam)
#وصف_ڪريو Create_دري_W(lpClassName,lp_دري_Name,dwStyle,x,y,n_ويڪر,n_اوچائي,h_Wnd_والد,hMenu,hInstance,lpParam) Create_دري_Ex_W(0L,lpClassName,lp_دري_Name,dwStyle,x,y,n_ويڪر,n_اوچائي,h_Wnd_والد,hMenu,hInstance,lpParam)
  WINUSERAPI WINBOOL WINAPI Is_دري(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsMenu(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI Is_ٻار(HWND h_Wnd_والد,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Destroy_دري(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Show_دري(HWND hWnd,صحيح nCmdShow);
  WINUSERAPI WINBOOL WINAPI Animate_دري(HWND hWnd,DWORD dw_وقت,DWORD dwFlags);

#إذا defined(_WINGDI_) && !defined(NOGDI)
  WINUSERAPI WINBOOL WINAPI Update_Layered_دري(HWND hWnd,HDC hdcDst,نقطو_3 *pptDst,سائيز_2 *psize,HDC hdcSrc,نقطو_3 *pptSrc,COLORREF cr_ڪنجي,BLENDFUNCTION *pblend,DWORD dwFlags);

  تعريفنوع بنية ٽيگ_UPDATELAYEREDWINDOWINFO {
    DWORD cb_سائيز;
    HDC hdcDst;
    نقطو_3 CONST *pptDst;
    سائيز_2 CONST *psize;
    HDC hdcSrc;
    نقطو_3 CONST *pptSrc;
    COLORREF cr_ڪنجي;
    BLENDFUNCTION CONST *pblend;
    DWORD dwFlags;
    RECT CONST *prcDirty;
  } UPDATELAYEREDWINDOWINFO,*PUPDATELAYEREDWINDOWINFO;

  WINUSERAPI WINBOOL WINAPI Update_Layered_دري_اڻسڌو(HWND hWnd,UPDATELAYEREDWINDOWINFO CONST *pULWInfo);
  WINUSERAPI WINBOOL WINAPI Get_Layered_دري_خاصيتون(HWND hwnd,COLORREF *pcr_ڪنجي,BYTE *pbAlpha,DWORD *pdwFlags);

#وصف_ڪريو PW_CLIENTONLY 0x00000001

  WINUSERAPI WINBOOL WINAPI Print_دري(HWND hwnd,HDC hdcBlt,UINT nFlags);
  WINUSERAPI WINBOOL WINAPI سيٽ_Layered_دري_خاصيتون(HWND hwnd,COLORREF cr_ڪنجي,BYTE bAlpha,DWORD dwFlags);

#وصف_ڪريو LWA_COLORKEY 0x00000001
#وصف_ڪريو LWA_ALPHA 0x00000002

#وصف_ڪريو ULW_COLORKEY 0x00000001
#وصف_ڪريو ULW_ALPHA 0x00000002
#وصف_ڪريو ULW_OPAQUE 0x00000004

#وصف_ڪريو ULW_EX_NORESIZE 0x00000008

  WINUSERAPI WINBOOL WINAPI Show_دري_Async(HWND hWnd,صحيح nCmdShow);
  WINUSERAPI WINBOOL WINAPI Flash_دري(HWND hWnd,WINBOOL bInvert);

  تعريفنوع بنية {
    UINT cb_سائيز;
    HWND hwnd;
    DWORD dwFlags;
    UINT u_ڳڻپ;
    DWORD dwTimeout;
  } FLASHWINFO,*PFLASHWINFO;

  WINUSERAPI WINBOOL WINAPI Flash_دري_Ex(PFLASHWINFO pfwi);

#وصف_ڪريو FLASHW_STOP 0
#وصف_ڪريو FLASHW_CAPTION 0x00000001
#وصف_ڪريو FLASHW_TRAY 0x00000002
#وصف_ڪريو FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#وصف_ڪريو FLASHW_TIMER 0x00000004
#وصف_ڪريو FLASHW_TIMERNOFG 0x0000000C

  WINUSERAPI WINBOOL WINAPI ShowOwnedPopups(HWND hWnd,WINBOOL fShow);
  WINUSERAPI WINBOOL WINAPI OpenIcon(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Close_دري(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Move_دري(HWND hWnd,صحيح X,صحيح Y,صحيح n_ويڪر,صحيح n_اوچائي,WINBOOL bRepaint);
  WINUSERAPI WINBOOL WINAPI سيٽ_دري_Pos(HWND hWnd,HWND h_Wnd_وجهو_After,صحيح X,صحيح Y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI Get_دري_Placement(HWND hWnd,WINDOWPLACEMENT *lpwndpl);
  WINUSERAPI WINBOOL WINAPI سيٽ_دري_Placement(HWND hWnd,CONST WINDOWPLACEMENT *lpwndpl);

#جيڪڏهن_وصف_نه_ٿيل NODEFERWINDOWPOS
  WINUSERAPI HDWP WINAPI Begin_Defer_دري_Pos(صحيح n_انگ_Windows);
  WINUSERAPI HDWP WINAPI Defer_دري_Pos(HDWP hWinPosInfo,HWND hWnd,HWND h_Wnd_وجهو_After,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI پڇاڙي_Defer_دري_Pos(HDWP hWinPosInfo);
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI Is_دري_Visible(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsIconic(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AnyPopup(VOID);
  WINUSERAPI WINBOOL WINAPI Bring_دري_منزل_چوٽي(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsZoomed(HWND hWnd);

#وصف_ڪريو SWP_NOSIZE 0x0001
#وصف_ڪريو SWP_NOMOVE 0x0002
#وصف_ڪريو SWP_NOZORDER 0x0004
#وصف_ڪريو SWP_NOREDRAW 0x0008
#وصف_ڪريو SWP_NOACTIVATE 0x0010
#وصف_ڪريو SWP_FRAMECHANGED 0x0020
#وصف_ڪريو SWP_SHOWWINDOW 0x0040
#وصف_ڪريو SWP_HIDEWINDOW 0x0080
#وصف_ڪريو SWP_NOCOPYBITS 0x0100
#وصف_ڪريو SWP_NOOWNERZORDER 0x0200
#وصف_ڪريو SWP_NOSENDCHANGING 0x0400

#وصف_ڪريو SWP_DRAWFRAME SWP_FRAMECHANGED
#وصف_ڪريو SWP_NOREPOSITION SWP_NOOWNERZORDER
#وصف_ڪريو SWP_DEFERERASE 0x2000
#وصف_ڪريو SWP_ASYNCWINDOWPOS 0x4000

#وصف_ڪريو HWND_چوٽي ((HWND)0)
#وصف_ڪريو HWND_BOTTOM ((HWND)1)
#وصف_ڪريو HWND_TOPMOST ((HWND)-1)
#وصف_ڪريو HWND_NOTOPMOST ((HWND)-2)

#جيڪڏهن_وصف_نه_ٿيل NOCTLMGR

#ضمن <pshpack2.h>

  تعريفنوع بنية {
    DWORD style;
    DWORD dwExtendedStyle;
    لفظ_3 cdit;
    ننڍو x;
    ننڍو y;
    ننڍو cx;
    ننڍو cy;
  } DLGTEMPLATE;

  تعريفنوع DLGTEMPLATE *LPDLGTEMPLATEA;
  تعريفنوع DLGTEMPLATE *LPDLGTEMPLATEW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع LPDLGTEMPLATEW LPDLGTEMPLATE;
#وإلا
  تعريفنوع LPDLGTEMPLATEA LPDLGTEMPLATE;
#جيڪڏهن_پورو

  تعريفنوع CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
  تعريفنوع CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#وإلا
  تعريفنوع LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#جيڪڏهن_پورو

  تعريفنوع بنية {
    DWORD style;
    DWORD dwExtendedStyle;
    ننڍو x;
    ننڍو y;
    ننڍو cx;
    ننڍو cy;
    لفظ_3 id;
  } DLGITEMTEMPLATE;

  تعريفنوع DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
  تعريفنوع DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#وإلا
  تعريفنوع PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#جيڪڏهن_پورو

  تعريفنوع DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
  تعريفنوع DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#وإلا
  تعريفنوع LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#جيڪڏهن_پورو

#ضمن <poppack.h>

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو CreateDialogParam CreateDialogParamW
#وصف_ڪريو Create_Dialog_اڻسڌو_Param Create_Dialog_اڻسڌو_Param_W
#وصف_ڪريو CreateDialog CreateDialogW
#وصف_ڪريو Create_Dialog_اڻسڌو Create_Dialog_اڻسڌو_W
#وصف_ڪريو DialogBoxParam DialogBoxParamW
#وصف_ڪريو Dialog_Box_اڻسڌو_Param Dialog_Box_اڻسڌو_Param_W
#وصف_ڪريو DialogBox DialogBoxW
#وصف_ڪريو Dialog_Box_اڻسڌو Dialog_Box_اڻسڌو_W
#وصف_ڪريو سيٽ_Dlg_شي_متن سيٽ_Dlg_شي_متن_W
#وصف_ڪريو Get_Dlg_شي_متن Get_Dlg_شي_متن_W
#وصف_ڪريو Send_Dlg_شي_پيغام Send_Dlg_شي_پيغام_W
#وصف_ڪريو DefDlgProc DefDlgProcW
#وإلا
#وصف_ڪريو CreateDialogParam CreateDialogParamA
#وصف_ڪريو Create_Dialog_اڻسڌو_Param Create_Dialog_اڻسڌو_Param_A
#وصف_ڪريو CreateDialog CreateDialogA
#وصف_ڪريو Create_Dialog_اڻسڌو Create_Dialog_اڻسڌو_A
#وصف_ڪريو DialogBoxParam DialogBoxParamA
#وصف_ڪريو Dialog_Box_اڻسڌو_Param Dialog_Box_اڻسڌو_Param_A
#وصف_ڪريو DialogBox DialogBoxA
#وصف_ڪريو Dialog_Box_اڻسڌو Dialog_Box_اڻسڌو_A
#وصف_ڪريو سيٽ_Dlg_شي_متن سيٽ_Dlg_شي_متن_A
#وصف_ڪريو Get_Dlg_شي_متن Get_Dlg_شي_متن_A
#وصف_ڪريو Send_Dlg_شي_پيغام Send_Dlg_شي_پيغام_A
#وصف_ڪريو DefDlgProc DefDlgProcA
#جيڪڏهن_پورو

  WINUSERAPI HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_اڻسڌو_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_اڻسڌو_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#وصف_ڪريو CreateDialogA(hInstance,lpName,h_Wnd_والد,lpDialogFunc) CreateDialogParamA(hInstance,lpName,h_Wnd_والد,lpDialogFunc,0L)
#وصف_ڪريو CreateDialogW(hInstance,lpName,h_Wnd_والد,lpDialogFunc) CreateDialogParamW(hInstance,lpName,h_Wnd_والد,lpDialogFunc,0L)
#وصف_ڪريو Create_Dialog_اڻسڌو_A(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) Create_Dialog_اڻسڌو_Param_A(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
#وصف_ڪريو Create_Dialog_اڻسڌو_W(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) Create_Dialog_اڻسڌو_Param_W(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
  WINUSERAPI INT_PTR WINAPI DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_اڻسڌو_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_اڻسڌو_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#وصف_ڪريو DialogBoxA(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
#وصف_ڪريو DialogBoxW(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
#وصف_ڪريو Dialog_Box_اڻسڌو_A(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) Dialog_Box_اڻسڌو_Param_A(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
#وصف_ڪريو Dialog_Box_اڻسڌو_W(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) Dialog_Box_اڻسڌو_Param_W(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
  WINUSERAPI WINBOOL WINAPI پڇاڙي_Dialog(HWND hDlg,INT_PTR n_نتيجو);
  WINUSERAPI HWND WINAPI Get_Dlg_شي(HWND hDlg,صحيح n_IDDlg_شي);
  WINUSERAPI WINBOOL WINAPI سيٽ_Dlg_شي_Int(HWND hDlg,صحيح n_IDDlg_شي,UINT u_قدر,WINBOOL bSigned);
  WINUSERAPI UINT WINAPI Get_Dlg_شي_Int(HWND hDlg,صحيح n_IDDlg_شي,WINBOOL *lpTranslated,WINBOOL bSigned);
  WINUSERAPI WINBOOL WINAPI سيٽ_Dlg_شي_متن_A(HWND hDlg,صحيح n_IDDlg_شي,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI سيٽ_Dlg_شي_متن_W(HWND hDlg,صحيح n_IDDlg_شي,LPCWSTR lpString);
  WINUSERAPI UINT WINAPI Get_Dlg_شي_متن_A(HWND hDlg,صحيح n_IDDlg_شي,LPSTR lpString,صحيح cchMax);
  WINUSERAPI UINT WINAPI Get_Dlg_شي_متن_W(HWND hDlg,صحيح n_IDDlg_شي,LPWSTR lpString,صحيح cchMax);
  WINUSERAPI WINBOOL WINAPI CheckDlgButton(HWND hDlg,صحيح nIDButton,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI CheckRadioButton(HWND hDlg,صحيح nIDFirstButton,صحيح nIDLastButton,صحيح nIDCheckButton);
  WINUSERAPI UINT WINAPI IsDlgButtonChecked(HWND hDlg,صحيح nIDButton);
  WINUSERAPI LRESULT WINAPI Send_Dlg_شي_پيغام_A(HWND hDlg,صحيح n_IDDlg_شي,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_Dlg_شي_پيغام_W(HWND hDlg,صحيح n_IDDlg_شي,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI HWND WINAPI Get_ايندڙ_Dlg_گروهه_شي(HWND hDlg,HWND hCtl,WINBOOL b_اڳيون);
  WINUSERAPI HWND WINAPI Get_ايندڙ_Dlg_Tab_شي(HWND hDlg,HWND hCtl,WINBOOL b_اڳيون);
  WINUSERAPI صحيح WINAPI GetDlgCtrlID(HWND hWnd);
  WINUSERAPI ڊگهو WINAPI Get_Dialog_بنياد_Units(VOID);
  WINUSERAPI LRESULT WINAPI DefDlgProcA(HWND hDlg,UINT نياپو_3,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefDlgProcW(HWND hDlg,UINT نياپو_3,WPARAM wParam,LPARAM lParam);

#وصف_ڪريو DLGWINDOWEXTRA 30
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOMSG

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Call_نياپو_Filter Call_نياپو_Filter_W
#وإلا
#وصف_ڪريو Call_نياپو_Filter Call_نياپو_Filter_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI Call_نياپو_Filter_A(LPMSG lp_نياپو,صحيح n_ڪوڊ);
  WINUSERAPI WINBOOL WINAPI Call_نياپو_Filter_W(LPMSG lp_نياپو,صحيح n_ڪوڊ);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOCLIPBOARD

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو رجسٽر_Clipboard_Format رجسٽر_Clipboard_Format_W
#وصف_ڪريو GetClipboardFormatName GetClipboardFormatNameW
#وإلا
#وصف_ڪريو رجسٽر_Clipboard_Format رجسٽر_Clipboard_Format_A
#وصف_ڪريو GetClipboardFormatName GetClipboardFormatNameA
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI OpenClipboard(HWND hWndNewOwner);
  WINUSERAPI WINBOOL WINAPI CloseClipboard(VOID);
  WINUSERAPI DWORD WINAPI Get_Clipboard_Sequence_عدد(VOID);
  WINUSERAPI HWND WINAPI GetClipboardOwner(VOID);
  WINUSERAPI HWND WINAPI سيٽ_Clipboard_Viewer(HWND hWndNewViewer);
  WINUSERAPI HWND WINAPI GetClipboardViewer(VOID);
  WINUSERAPI WINBOOL WINAPI ChangeClipboardChain(HWND hWndRemove,HWND h_Wnd_New_ايندڙ);
  WINUSERAPI HANDLE WINAPI سيٽ_Clipboard_معلومات(UINT uFormat,HANDLE hMem);
  WINUSERAPI HANDLE WINAPI Get_Clipboard_معلومات(UINT uFormat);
  WINUSERAPI UINT WINAPI رجسٽر_Clipboard_Format_A(LPCSTR lpszFormat);
  WINUSERAPI UINT WINAPI رجسٽر_Clipboard_Format_W(LPCWSTR lpszFormat);
  WINUSERAPI صحيح WINAPI ڳڻپ_Clipboard_Formats(VOID);
  WINUSERAPI UINT WINAPI EnumClipboardFormats(UINT format);
  WINUSERAPI صحيح WINAPI GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,صحيح cch_Max_ڳڻپ);
  WINUSERAPI صحيح WINAPI GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,صحيح cch_Max_ڳڻپ);
  WINUSERAPI WINBOOL WINAPI خالي_جايون_Clipboard(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Clipboard_Format_موجود(UINT format);
  WINUSERAPI صحيح WINAPI Get_ترجيح_Clipboard_Format(UINT *pa_Format_ترجيح_List,صحيح cFormats);
  WINUSERAPI HWND WINAPI Get_Open_Clipboard_دري(VOID);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Char_منزل_Oem Char_منزل_Oem_W
#وصف_ڪريو Oem_منزل_Char Oem_منزل_Char_W
#وصف_ڪريو Char_منزل_Oem_Buff Char_منزل_Oem_Buff_W
#وصف_ڪريو Oem_منزل_Char_Buff Oem_منزل_Char_Buff_W
#وصف_ڪريو Char_مٿانهون Char_مٿانهون_W
#وصف_ڪريو Char_مٿانهون_Buff Char_مٿانهون_Buff_W
#وصف_ڪريو Char_هيٺاهون Char_هيٺاهون_W
#وصف_ڪريو Char_هيٺاهون_Buff Char_هيٺاهون_Buff_W
#وصف_ڪريو Char_ايندڙ Char_ايندڙ_W
#وصف_ڪريو CharPrev CharPrevW
#وإلا
#وصف_ڪريو Char_منزل_Oem Char_منزل_Oem_A
#وصف_ڪريو Oem_منزل_Char Oem_منزل_Char_A
#وصف_ڪريو Char_منزل_Oem_Buff Char_منزل_Oem_Buff_A
#وصف_ڪريو Oem_منزل_Char_Buff Oem_منزل_Char_Buff_A
#وصف_ڪريو Char_مٿانهون Char_مٿانهون_A
#وصف_ڪريو Char_مٿانهون_Buff Char_مٿانهون_Buff_A
#وصف_ڪريو Char_هيٺاهون Char_هيٺاهون_A
#وصف_ڪريو Char_هيٺاهون_Buff Char_هيٺاهون_Buff_A
#وصف_ڪريو Char_ايندڙ Char_ايندڙ_A
#وصف_ڪريو CharPrev CharPrevA
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_W(LPCWSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_W(LPCSTR lpszSrc,LPWSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_ڊيگهائي);
  WINUSERAPI WINBOOL WINAPI Char_منزل_Oem_Buff_W(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_ڊيگهائي);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_ڊيگهائي);
  WINUSERAPI WINBOOL WINAPI Oem_منزل_Char_Buff_W(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cch_Dst_ڊيگهائي);
  WINUSERAPI LPSTR WINAPI Char_مٿانهون_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_مٿانهون_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_مٿانهون_Buff_A(LPSTR lpsz,DWORD cch_ڊيگهائي);
  WINUSERAPI DWORD WINAPI Char_مٿانهون_Buff_W(LPWSTR lpsz,DWORD cch_ڊيگهائي);
  WINUSERAPI LPSTR WINAPI Char_هيٺاهون_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_هيٺاهون_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_هيٺاهون_Buff_A(LPSTR lpsz,DWORD cch_ڊيگهائي);
  WINUSERAPI DWORD WINAPI Char_هيٺاهون_Buff_W(LPWSTR lpsz,DWORD cch_ڊيگهائي);
  WINUSERAPI LPSTR WINAPI Char_ايندڙ_A(LPCSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ايندڙ_W(LPCWSTR lpsz);
  WINUSERAPI LPSTR WINAPI CharPrevA(LPCSTR lpsz_شروعات,LPCSTR lpszCurrent);
  WINUSERAPI LPWSTR WINAPI CharPrevW(LPCWSTR lpsz_شروعات,LPCWSTR lpszCurrent);
  WINUSERAPI LPSTR WINAPI Char_ايندڙ_Ex_A(لفظ_3 ڪوڊ_صفحو,LPCSTR lpCurrentChar,DWORD dwFlags);
  WINUSERAPI LPSTR WINAPI CharPrevExA(لفظ_3 ڪوڊ_صفحو,LPCSTR lp_شروعات,LPCSTR lpCurrentChar,DWORD dwFlags);

#وصف_ڪريو Ansi_منزل_Oem Char_منزل_Oem_A
#وصف_ڪريو Oem_منزل_Ansi Oem_منزل_Char_A
#وصف_ڪريو Ansi_منزل_Oem_Buff Char_منزل_Oem_Buff_A
#وصف_ڪريو Oem_منزل_Ansi_Buff Oem_منزل_Char_Buff_A
#وصف_ڪريو Ansi_مٿانهون Char_مٿانهون_A
#وصف_ڪريو Ansi_مٿانهون_Buff Char_مٿانهون_Buff_A
#وصف_ڪريو Ansi_هيٺاهون Char_هيٺاهون_A
#وصف_ڪريو Ansi_هيٺاهون_Buff Char_هيٺاهون_Buff_A
#وصف_ڪريو Ansi_ايندڙ Char_ايندڙ_A
#وصف_ڪريو AnsiPrev CharPrevA

#جيڪڏهن_وصف_نه_ٿيل NOLANGUAGE

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو IsCharAlpha IsCharAlphaW
#وصف_ڪريو IsCharAlphaNumeric IsCharAlphaNumericW
#وصف_ڪريو Is_Char_مٿانهون Is_Char_مٿانهون_W
#وصف_ڪريو Is_Char_هيٺاهون Is_Char_هيٺاهون_W
#وإلا
#وصف_ڪريو IsCharAlpha IsCharAlphaA
#وصف_ڪريو IsCharAlphaNumeric IsCharAlphaNumericA
#وصف_ڪريو Is_Char_مٿانهون Is_Char_مٿانهون_A
#وصف_ڪريو Is_Char_هيٺاهون Is_Char_هيٺاهون_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI IsCharAlphaA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_مٿانهون_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_مٿانهون_W(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_هيٺاهون_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_هيٺاهون_W(WCHAR ch);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_ڪنجي_Name_متن Get_ڪنجي_Name_متن_W
#وصف_ڪريو Vk_ڪنجي_جاچ Vk_ڪنجي_جاچ_W
#وصف_ڪريو Vk_ڪنجي_جاچ_Ex Vk_ڪنجي_جاچ_Ex_W
#وإلا
#وصف_ڪريو Get_ڪنجي_Name_متن Get_ڪنجي_Name_متن_A
#وصف_ڪريو Vk_ڪنجي_جاچ Vk_ڪنجي_جاچ_A
#وصف_ڪريو Vk_ڪنجي_جاچ_Ex Vk_ڪنجي_جاچ_Ex_A
#جيڪڏهن_پورو

  WINUSERAPI HWND WINAPI سيٽ_Focus(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_سرگرم_دري(VOID);
  WINUSERAPI HWND WINAPI GetFocus(VOID);
  WINUSERAPI UINT WINAPI Get_KBCode_صفحو(VOID);
  WINUSERAPI SHORT WINAPI Get_ڪنجي_State(صحيح n_Virt_ڪنجي);
  WINUSERAPI SHORT WINAPI Get_Async_ڪنجي_State(صحيح v_ڪنجي);
  WINUSERAPI WINBOOL WINAPI GetKeyboardState(PBYTE lp_ڪنجي_State);
  WINUSERAPI WINBOOL WINAPI سيٽ_Keyboard_State(LPBYTE lp_ڪنجي_State);
  WINUSERAPI صحيح WINAPI Get_ڪنجي_Name_متن_A(LONG lParam,LPSTR lpString,صحيح cch_سائيز);
  WINUSERAPI صحيح WINAPI Get_ڪنجي_Name_متن_W(LONG lParam,LPWSTR lpString,صحيح cch_سائيز);
  WINUSERAPI صحيح WINAPI GetKeyboardType(صحيح nTypeFlag);
  WINUSERAPI صحيح WINAPI منزل_Ascii(UINT u_Virt_ڪنجي,UINT u_جاچ_ڪوڊ,CONST BYTE *lp_ڪنجي_State,LPWORD lpChar,UINT uFlags);
  WINUSERAPI صحيح WINAPI منزل_Ascii_Ex(UINT u_Virt_ڪنجي,UINT u_جاچ_ڪوڊ,CONST BYTE *lp_ڪنجي_State,LPWORD lpChar,UINT uFlags,HKL dwhkl);
  WINUSERAPI صحيح WINAPI منزل_Unicode(UINT w_Virt_ڪنجي,UINT w_جاچ_ڪوڊ,CONST BYTE *lp_ڪنجي_State,LPWSTR pwszBuff,صحيح cchBuff,UINT wFlags);
  WINUSERAPI DWORD WINAPI Oem_ڪنجي_جاچ(لفظ_3 wOemChar);
  WINUSERAPI SHORT WINAPI Vk_ڪنجي_جاچ_A(CHAR ch);
  WINUSERAPI SHORT WINAPI Vk_ڪنجي_جاچ_W(WCHAR ch);
  WINUSERAPI SHORT WINAPI Vk_ڪنجي_جاچ_Ex_A(CHAR ch,HKL dwhkl);
  WINUSERAPI SHORT WINAPI Vk_ڪنجي_جاچ_Ex_W(WCHAR ch,HKL dwhkl);

#وصف_ڪريو KEYEVENTF_EXTENDEDKEY 0x0001
#وصف_ڪريو KEYEVENTF_KEYUP 0x0002
#وصف_ڪريو KEYEVENTF_UNICODE 0x0004
#وصف_ڪريو KEYEVENTF_SCANCODE 0x0008

  WINUSERAPI VOID WINAPI keybd_event(BYTE bVk,BYTE b_جاچ,DWORD dwFlags,ULONG_PTR dwExtraInfo);

#وصف_ڪريو MOUSEEVENTF_MOVE 0x0001
#وصف_ڪريو MOUSEEVENTF_LEFTDOWN 0x0002
#وصف_ڪريو MOUSEEVENTF_LEFTUP 0x0004
#وصف_ڪريو MOUSEEVENTF_RIGHTDOWN 0x0008
#وصف_ڪريو MOUSEEVENTF_RIGHTUP 0x0010
#وصف_ڪريو MOUSEEVENTF_MIDDLEDOWN 0x0020
#وصف_ڪريو MOUSEEVENTF_MIDDLEUP 0x0040
#وصف_ڪريو MOUSEEVENTF_XDOWN 0x0080
#وصف_ڪريو MOUSEEVENTF_XUP 0x0100
#وصف_ڪريو MOUSEEVENTF_WHEEL 0x0800
#وصف_ڪريو MOUSEEVENTF_VIRTUALDESK 0x4000
#وصف_ڪريو MOUSEEVENTF_ABSOLUTE 0x8000

  WINUSERAPI VOID WINAPI mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dw_معلومات,ULONG_PTR dwExtraInfo);

  تعريفنوع بنية ٽيگ_MOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouse_معلومات;
    DWORD dwFlags;
    DWORD وقت;
    ULONG_PTR dwExtraInfo;
  } MOUSEINPUT,*PMOUSEINPUT,*LPMOUSEINPUT;

  تعريفنوع بنية ٽيگ_KEYBDINPUT {
    لفظ_3 wVk;
    لفظ_3 w_جاچ;
    DWORD dwFlags;
    DWORD وقت;
    ULONG_PTR dwExtraInfo;
  } KEYBDINPUT,*PKEYBDINPUT,*LPKEYBDINPUT;

  تعريفنوع بنية ٽيگ_HARDWAREINPUT {
    DWORD u_نياپو;
    لفظ_3 wParamL;
    لفظ_3 wParamH;
  } HARDWAREINPUT,*PHARDWAREINPUT,*LPHARDWAREINPUT;

#وصف_ڪريو داخلا_MOUSE 0
#وصف_ڪريو داخلا_KEYBOARD 1
#وصف_ڪريو داخلا_HARDWARE 2

  تعريفنوع بنية ٽيگ_داخلا {
    DWORD type;
    اتحاد {
      MOUSEINPUT mi;
      KEYBDINPUT ki;
      HARDWAREINPUT hi;
    };
  } داخلا_3,*PINPUT,*LPINPUT;

  WINUSERAPI UINT WINAPI Send_داخلا(UINT cInputs,LPINPUT pInputs,صحيح cb_سائيز);

  تعريفنوع بنية ٽيگ_LASTINPUTINFO {
    UINT cb_سائيز;
    DWORD dw_وقت;
  } LASTINPUTINFO,*PLASTINPUTINFO;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Map_Virtual_ڪنجي Map_Virtual_ڪنجي_W
#وصف_ڪريو Map_Virtual_ڪنجي_Ex Map_Virtual_ڪنجي_Ex_W
#وإلا
#وصف_ڪريو Map_Virtual_ڪنجي Map_Virtual_ڪنجي_A
#وصف_ڪريو Map_Virtual_ڪنجي_Ex Map_Virtual_ڪنجي_Ex_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI Get_آخري_داخلا_Info(PLASTINPUTINFO plii);
  WINUSERAPI UINT WINAPI Map_Virtual_ڪنجي_A(UINT u_ڪوڊ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_ڪنجي_W(UINT u_ڪوڊ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_ڪنجي_Ex_A(UINT u_ڪوڊ,UINT uMapType,HKL dwhkl);
  WINUSERAPI UINT WINAPI Map_Virtual_ڪنجي_Ex_W(UINT u_ڪوڊ,UINT uMapType,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI Get_داخلا_State(VOID);
  WINUSERAPI DWORD WINAPI Get_قطار_حالت(UINT flags);
  WINUSERAPI HWND WINAPI GetCapture(VOID);
  WINUSERAPI HWND WINAPI سيٽ_Capture(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ReleaseCapture(VOID);
  WINUSERAPI DWORD WINAPI نياپو_Wait_For_گڻو_Objects(DWORD n_ڳڻپ,CONST HANDLE *pHandles,WINBOOL fWaitAll,DWORD dwMilliseconds,DWORD dw_Wake_نقاب);
  WINUSERAPI DWORD WINAPI نياپو_Wait_For_گڻو_Objects_Ex(DWORD n_ڳڻپ,CONST HANDLE *pHandles,DWORD dwMilliseconds,DWORD dw_Wake_نقاب,DWORD dwFlags);

#وصف_ڪريو MWMO_WAITALL 0x0001
#وصف_ڪريو MWMO_ALERTABLE 0x0002
#وصف_ڪريو MWMO_INPUTAVAILABLE 0x0004

#وصف_ڪريو QS_ڪنجي 0x0001
#وصف_ڪريو QS_MOUSEMOVE 0x0002
#وصف_ڪريو QS_MOUSEBUTTON 0x0004
#وصف_ڪريو QS_POSTMESSAGE 0x0008
#وصف_ڪريو QS_TIMER 0x0010
#وصف_ڪريو QS_PAINT 0x0020
#وصف_ڪريو QS_SENDMESSAGE 0x0040
#وصف_ڪريو QS_HOTKEY 0x0080
#وصف_ڪريو QS_ALLPOSTMESSAGE 0x0100
#وصف_ڪريو QS_RAWINPUT 0x0400
#وصف_ڪريو QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#وصف_ڪريو QS_داخلا (QS_MOUSE | QS_ڪنجي | QS_RAWINPUT)
#وصف_ڪريو QS_ALLEVENTS (QS_داخلا | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#وصف_ڪريو QS_ALLINPUT (QS_داخلا | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#وصف_ڪريو USER_TIMER_وڌ_کان_وڌ 0x7FFFFFFF
#وصف_ڪريو USER_TIMER_MINIMUM 0x0000000A

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڀريو_Accelerators ڀريو_Accelerators_W
#وصف_ڪريو Create_Accelerator_جدول Create_Accelerator_جدول_W
#وصف_ڪريو Copy_Accelerator_جدول Copy_Accelerator_جدول_W
#وإلا
#وصف_ڪريو ڀريو_Accelerators ڀريو_Accelerators_A
#وصف_ڪريو Create_Accelerator_جدول Create_Accelerator_جدول_A
#وصف_ڪريو Copy_Accelerator_جدول Copy_Accelerator_جدول_A
#جيڪڏهن_پورو

  WINUSERAPI UINT_PTR WINAPI سيٽ_Timer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
  WINUSERAPI WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);
  WINUSERAPI WINBOOL WINAPI Is_دري_Unicode(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Enable_دري(HWND hWnd,WINBOOL bEnable);
  WINUSERAPI WINBOOL WINAPI Is_دري_Enabled(HWND hWnd);
  WINUSERAPI HACCEL WINAPI ڀريو_Accelerators_A(HINSTANCE hInstance,LPCSTR lp_جدول_Name);
  WINUSERAPI HACCEL WINAPI ڀريو_Accelerators_W(HINSTANCE hInstance,LPCWSTR lp_جدول_Name);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_جدول_A(LPACCEL paccel,صحيح cAccel);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_جدول_W(LPACCEL paccel,صحيح cAccel);
  WINUSERAPI WINBOOL WINAPI Destroy_Accelerator_جدول(HACCEL hAccel);
  WINUSERAPI صحيح WINAPI Copy_Accelerator_جدول_A(HACCEL hAccelSrc,LPACCEL lpAccelDst,صحيح cAccelEntries);
  WINUSERAPI صحيح WINAPI Copy_Accelerator_جدول_W(HACCEL hAccelSrc,LPACCEL lpAccelDst,صحيح cAccelEntries);

#جيڪڏهن_وصف_نه_ٿيل NOMSG

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو TranslateAccelerator TranslateAcceleratorW
#وإلا
#وصف_ڪريو TranslateAccelerator TranslateAcceleratorA
#جيڪڏهن_پورو

  WINUSERAPI صحيح WINAPI TranslateAcceleratorA(HWND hWnd,HACCEL h_Acc_جدول,LPMSG lp_نياپو);
  WINUSERAPI صحيح WINAPI TranslateAcceleratorW(HWND hWnd,HACCEL h_Acc_جدول,LPMSG lp_نياپو);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOSYSMETRICS

#وصف_ڪريو SM_CXSCREEN 0
#وصف_ڪريو SM_CYSCREEN 1
#وصف_ڪريو SM_CXVSCROLL 2
#وصف_ڪريو SM_CYHSCROLL 3
#وصف_ڪريو SM_CYCAPTION 4
#وصف_ڪريو SM_CXBORDER 5
#وصف_ڪريو SM_CYBORDER 6
#وصف_ڪريو SM_CXDLGFRAME 7
#وصف_ڪريو SM_CYDLGFRAME 8
#وصف_ڪريو SM_CYVTHUMB 9
#وصف_ڪريو SM_CXHTHUMB 10
#وصف_ڪريو SM_CXICON 11
#وصف_ڪريو SM_CYICON 12
#وصف_ڪريو SM_CXCURSOR 13
#وصف_ڪريو SM_CYCURSOR 14
#وصف_ڪريو SM_CYMENU 15
#وصف_ڪريو SM_CXFULLSCREEN 16
#وصف_ڪريو SM_CYFULLSCREEN 17
#وصف_ڪريو SM_CYKANJIWINDOW 18
#وصف_ڪريو SM_MOUSEPRESENT 19
#وصف_ڪريو SM_CYVSCROLL 20
#وصف_ڪريو SM_CXHSCROLL 21
#وصف_ڪريو SM_DEBUG 22
#وصف_ڪريو SM_SWAPBUTTON 23
#وصف_ڪريو SM_RESERVED1 24
#وصف_ڪريو SM_RESERVED2 25
#وصف_ڪريو SM_RESERVED3 26
#وصف_ڪريو SM_RESERVED4 27
#وصف_ڪريو SM_CXMIN 28
#وصف_ڪريو SM_CYMIN 29
#وصف_ڪريو SM_CXSIZE 30
#وصف_ڪريو SM_CYSIZE 31
#وصف_ڪريو SM_CXFRAME 32
#وصف_ڪريو SM_CYFRAME 33
#وصف_ڪريو SM_CXMINTRACK 34
#وصف_ڪريو SM_CYMINTRACK 35
#وصف_ڪريو SM_CXDOUBLECLK 36
#وصف_ڪريو SM_CYDOUBLECLK 37
#وصف_ڪريو SM_CXICONSPACING 38
#وصف_ڪريو SM_CYICONSPACING 39
#وصف_ڪريو SM_MENUDROPALIGNMENT 40
#وصف_ڪريو SM_PENWINDOWS 41
#وصف_ڪريو SM_DBCSENABLED 42
#وصف_ڪريو SM_CMOUSEBUTTONS 43

#وصف_ڪريو SM_CXFIXEDFRAME SM_CXDLGFRAME
#وصف_ڪريو SM_CYFIXEDFRAME SM_CYDLGFRAME
#وصف_ڪريو SM_CXSIZEFRAME SM_CXFRAME
#وصف_ڪريو SM_CYSIZEFRAME SM_CYFRAME

#وصف_ڪريو SM_SECURE 44
#وصف_ڪريو SM_CXEDGE 45
#وصف_ڪريو SM_CYEDGE 46
#وصف_ڪريو SM_CXMINSPACING 47
#وصف_ڪريو SM_CYMINSPACING 48
#وصف_ڪريو SM_CXSMICON 49
#وصف_ڪريو SM_CYSMICON 50
#وصف_ڪريو SM_CYSMCAPTION 51
#وصف_ڪريو SM_CXSMSIZE 52
#وصف_ڪريو SM_CYSMSIZE 53
#وصف_ڪريو SM_CXMENUSIZE 54
#وصف_ڪريو SM_CYMENUSIZE 55
#وصف_ڪريو SM_ARRANGE 56
#وصف_ڪريو SM_CXMINIMIZED 57
#وصف_ڪريو SM_CYMINIMIZED 58
#وصف_ڪريو SM_CXMAXTRACK 59
#وصف_ڪريو SM_CYMAXTRACK 60
#وصف_ڪريو SM_CXMAXIMIZED 61
#وصف_ڪريو SM_CYMAXIMIZED 62
#وصف_ڪريو SM_ڄار 63
#وصف_ڪريو SM_CLEANBOOT 67
#وصف_ڪريو SM_CXDRAG 68
#وصف_ڪريو SM_CYDRAG 69
#وصف_ڪريو SM_SHOWSOUNDS 70
#وصف_ڪريو SM_CXMENUCHECK 71
#وصف_ڪريو SM_CYMENUCHECK 72
#وصف_ڪريو SM_SLOWMACHINE 73
#وصف_ڪريو SM_MIDEASTENABLED 74
#وصف_ڪريو SM_MOUSEWHEELPRESENT 75
#وصف_ڪريو SM_XVIRTUALSCREEN 76
#وصف_ڪريو SM_YVIRTUALSCREEN 77
#وصف_ڪريو SM_CXVIRTUALSCREEN 78
#وصف_ڪريو SM_CYVIRTUALSCREEN 79
#وصف_ڪريو SM_CMONITORS 80
#وصف_ڪريو SM_SAMEDISPLAYFORMAT 81
#وصف_ڪريو SM_IMMENABLED 82
#وصف_ڪريو SM_CXFOCUSBORDER 83
#وصف_ڪريو SM_CYFOCUSBORDER 84
#وصف_ڪريو SM_TABLETPC 86
#وصف_ڪريو SM_MEDIACENTER 87
#وصف_ڪريو SM_STARTER 88
#وصف_ڪريو SM_SERVERR2 89
#وصف_ڪريو SM_CMETRICS 90
#وصف_ڪريو SM_REMOTESESSION 0x1000
#وصف_ڪريو SM_SHUTTINGDOWN 0x2000
#وصف_ڪريو SM_REMOTECONTROL 0x2001
#وصف_ڪريو SM_CARETBLINKINGENABLED 0x2002

  WINUSERAPI صحيح WINAPI GetSystemMetrics(صحيح n_اشاريو);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOMENUS

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڀريو_Menu ڀريو_Menu_W
#وصف_ڪريو ڀريو_Menu_اڻسڌو ڀريو_Menu_اڻسڌو_W
#وصف_ڪريو ChangeMenu ChangeMenuW
#وصف_ڪريو GetMenuString GetMenuStringW
#وصف_ڪريو وجهو_Menu وجهو_Menu_W
#وصف_ڪريو AppendMenu AppendMenuW
#وصف_ڪريو ModifyMenu ModifyMenuW
#وإلا
#وصف_ڪريو ڀريو_Menu ڀريو_Menu_A
#وصف_ڪريو ڀريو_Menu_اڻسڌو ڀريو_Menu_اڻسڌو_A
#وصف_ڪريو ChangeMenu ChangeMenuA
#وصف_ڪريو GetMenuString GetMenuStringA
#وصف_ڪريو وجهو_Menu وجهو_Menu_A
#وصف_ڪريو AppendMenu AppendMenuA
#وصف_ڪريو ModifyMenu ModifyMenuA
#جيڪڏهن_پورو

  WINUSERAPI HMENU WINAPI ڀريو_Menu_A(HINSTANCE hInstance,LPCSTR lpMenuName);
  WINUSERAPI HMENU WINAPI ڀريو_Menu_W(HINSTANCE hInstance,LPCWSTR lpMenuName);
  WINUSERAPI HMENU WINAPI ڀريو_Menu_اڻسڌو_A(CONST MENUTEMPLATEA *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI ڀريو_Menu_اڻسڌو_W(CONST MENUTEMPLATEW *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI GetMenu(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI سيٽ_Menu(HWND hWnd,HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpsz_New_شي,UINT cmd_وجهو,UINT flags);
  WINUSERAPI WINBOOL WINAPI ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpsz_New_شي,UINT cmd_وجهو,UINT flags);
  WINUSERAPI WINBOOL WINAPI Hilite_Menu_شي(HWND hWnd,HMENU hMenu,UINT u_IDHilite_شي,UINT uHilite);
  WINUSERAPI صحيح WINAPI GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,صحيح cchMax,UINT flags);
  WINUSERAPI صحيح WINAPI GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,صحيح cchMax,UINT flags);
  WINUSERAPI UINT WINAPI GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawMenuBar(HWND hWnd);

#وصف_ڪريو PMB_سرگرم 0x00000001

  WINUSERAPI HMENU WINAPI GetSystemMenu(HWND hWnd,WINBOOL bRevert);
  WINUSERAPI HMENU WINAPI CreateMenu(VOID);
  WINUSERAPI HMENU WINAPI CreatePopupMenu(VOID);
  WINUSERAPI WINBOOL WINAPI DestroyMenu(HMENU hMenu);
  WINUSERAPI DWORD WINAPI Check_Menu_شي(HMENU hMenu,UINT u_IDCheck_شي,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI Enable_Menu_شي(HMENU hMenu,UINT u_IDEnable_شي,UINT uEnable);
  WINUSERAPI HMENU WINAPI GetSubMenu(HMENU hMenu,صحيح nPos);
  WINUSERAPI UINT WINAPI Get_Menu_شي_ID(HMENU hMenu,صحيح nPos);
  WINUSERAPI صحيح WINAPI Get_Menu_شي_ڳڻپ(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI وجهو_Menu_A(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_شي,LPCSTR lp_New_شي);
  WINUSERAPI WINBOOL WINAPI وجهو_Menu_W(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_شي,LPCWSTR lp_New_شي);
  WINUSERAPI WINBOOL WINAPI AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_شي,LPCSTR lp_New_شي);
  WINUSERAPI WINBOOL WINAPI AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_شي,LPCWSTR lp_New_شي);
  WINUSERAPI WINBOOL WINAPI ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_شي,LPCSTR lp_New_شي);
  WINUSERAPI WINBOOL WINAPI ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_شي,LPCWSTR lp_New_شي);
  WINUSERAPI WINBOOL WINAPI RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI سيٽ_Menu_شي_Bitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
  WINUSERAPI LONG WINAPI GetMenuCheckMarkDimensions(VOID);
  WINUSERAPI WINBOOL WINAPI TrackPopupMenu(HMENU hMenu,UINT uFlags,صحيح x,صحيح y,صحيح nReserved,HWND hWnd,CONST RECT *prcRect);

#وصف_ڪريو MNC_IGNORE 0
#وصف_ڪريو MNC_CLOSE 1
#وصف_ڪريو MNC_EXECUTE 2
#وصف_ڪريو MNC_SELECT 3

  تعريفنوع بنية ٽيگ_TPMPARAMS {
    UINT cb_سائيز;
    RECT rcExclude;
  } TPMPARAMS;

  تعريفنوع TPMPARAMS *LPTPMPARAMS;

  WINUSERAPI WINBOOL WINAPI TrackPopupMenuEx(HMENU,UINT,صحيح,صحيح,HWND,LPTPMPARAMS);

#وصف_ڪريو MNS_NOCHECK 0x80000000
#وصف_ڪريو MNS_MODELESS 0x40000000
#وصف_ڪريو MNS_DRAGDROP 0x20000000
#وصف_ڪريو MNS_AUTODISMISS 0x10000000
#وصف_ڪريو MNS_NOTIFYBYPOS 0x08000000
#وصف_ڪريو MNS_CHECKORBMP 0x04000000

#وصف_ڪريو MIM_MAXHEIGHT 0x00000001
#وصف_ڪريو MIM_BACKGROUND 0x00000002
#وصف_ڪريو MIM_HELPID 0x00000004
#وصف_ڪريو MIM_MENUDATA 0x00000008
#وصف_ڪريو MIM_STYLE 0x00000010
#وصف_ڪريو MIM_APPLYTOSUBMENUS 0x80000000

  تعريفنوع بنية ٽيگ_MENUINFO {
    DWORD cb_سائيز;
    DWORD f_نقاب;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbr_پٺ;
    DWORD dwContextHelpID;
    ULONG_PTR dw_Menu_معلومات;
  } MENUINFO,*LPMENUINFO;

  تعريفنوع MENUINFO CONST *LPCMENUINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuInfo(HMENU,LPMENUINFO);
  WINUSERAPI WINBOOL WINAPI سيٽ_Menu_Info(HMENU,LPCMENUINFO);
  WINUSERAPI WINBOOL WINAPI پڇاڙي_Menu(VOID);

#وصف_ڪريو MND_CONTINUE 0
#وصف_ڪريو MND_ENDMENU 1

  تعريفنوع بنية ٽيگ_MENUGETOBJECTINFO {
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
  } MENUGETOBJECTINFO,*PMENUGETOBJECTINFO;

#وصف_ڪريو MNGOF_TOPGAP 0x00000001
#وصف_ڪريو MNGOF_BOTTOMGAP 0x00000002

#وصف_ڪريو MNGO_NOINTERFACE 0x00000000
#وصف_ڪريو MNGO_NOERROR 0x00000001

#وصف_ڪريو MIIM_STATE 0x00000001
#وصف_ڪريو MIIM_ID 0x00000002
#وصف_ڪريو MIIM_SUBMENU 0x00000004
#وصف_ڪريو MIIM_CHECKMARKS 0x00000008
#وصف_ڪريو MIIM_TYPE 0x00000010
#وصف_ڪريو MIIM_معلومات 0x00000020

#وصف_ڪريو MIIM_STRING 0x00000040
#وصف_ڪريو MIIM_BITMAP 0x00000080
#وصف_ڪريو MIIM_FTYPE 0x00000100

#وصف_ڪريو HBMMENU_CALLBACK ((HBITMAP) -1)
#وصف_ڪريو HBMMENU_SYSTEM ((HBITMAP) 1)
#وصف_ڪريو HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#وصف_ڪريو HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#وصف_ڪريو HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#وصف_ڪريو HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#وصف_ڪريو HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#وصف_ڪريو HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#وصف_ڪريو HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#وصف_ڪريو HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#وصف_ڪريو HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

  تعريفنوع بنية ٽيگ_MENUITEMINFOA {
    UINT cb_سائيز;
    UINT f_نقاب;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_شي_معلومات;
    LPSTR dw_Type_معلومات;
    UINT cch;
    HBITMAP hbmp_شي;
  } MENUITEMINFOA,*LPMENUITEMINFOA;

  تعريفنوع بنية ٽيگ_MENUITEMINFOW {
    UINT cb_سائيز;
    UINT f_نقاب;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_شي_معلومات;
    LPWSTR dw_Type_معلومات;
    UINT cch;
    HBITMAP hbmp_شي;
  } MENUITEMINFOW,*LPMENUITEMINFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع MENUITEMINFOW MENUITEMINFO;
  تعريفنوع LPMENUITEMINFOW LPMENUITEMINFO;
#وإلا
  تعريفنوع MENUITEMINFOA MENUITEMINFO;
  تعريفنوع LPMENUITEMINFOA LPMENUITEMINFO;
#جيڪڏهن_پورو
  تعريفنوع MENUITEMINFOA CONST *LPCMENUITEMINFOA;
  تعريفنوع MENUITEMINFOW CONST *LPCMENUITEMINFOW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع LPCMENUITEMINFOW LPCMENUITEMINFO;
#وإلا
  تعريفنوع LPCMENUITEMINFOA LPCMENUITEMINFO;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو وجهو_Menu_شي وجهو_Menu_شي_W
#وصف_ڪريو Get_Menu_شي_Info Get_Menu_شي_Info_W
#وصف_ڪريو سيٽ_Menu_شي_Info سيٽ_Menu_شي_Info_W
#وإلا
#وصف_ڪريو وجهو_Menu_شي وجهو_Menu_شي_A
#وصف_ڪريو Get_Menu_شي_Info Get_Menu_شي_Info_A
#وصف_ڪريو سيٽ_Menu_شي_Info سيٽ_Menu_شي_Info_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI وجهو_Menu_شي_A(HMENU hmenu,UINT شي,WINBOOL fByPosition,LPCMENUITEMINFOA lpmi);
  WINUSERAPI WINBOOL WINAPI وجهو_Menu_شي_W(HMENU hmenu,UINT شي,WINBOOL fByPosition,LPCMENUITEMINFOW lpmi);
  WINUSERAPI WINBOOL WINAPI Get_Menu_شي_Info_A(HMENU hmenu,UINT شي,WINBOOL fByPosition,LPMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI Get_Menu_شي_Info_W(HMENU hmenu,UINT شي,WINBOOL fByPosition,LPMENUITEMINFOW lpmii);
  WINUSERAPI WINBOOL WINAPI سيٽ_Menu_شي_Info_A(HMENU hmenu,UINT شي,WINBOOL fByPositon,LPCMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI سيٽ_Menu_شي_Info_W(HMENU hmenu,UINT شي,WINBOOL fByPositon,LPCMENUITEMINFOW lpmii);

#وصف_ڪريو GMDI_USEDISABLED 0x0001L
#وصف_ڪريو GMDI_GOINTOPOPUPS 0x0002L

  WINUSERAPI UINT WINAPI Get_Menu_Default_شي(HMENU hMenu,UINT fByPos,UINT gmdiFlags);
  WINUSERAPI WINBOOL WINAPI سيٽ_Menu_Default_شي(HMENU hMenu,UINT u_شي,UINT fByPos);
  WINUSERAPI WINBOOL WINAPI Get_Menu_شي_Rect(HWND hWnd,HMENU hMenu,UINT u_شي,LPRECT lprc_شي);
  WINUSERAPI صحيح WINAPI Menu_شي_From_نقطو(HWND hWnd,HMENU hMenu,نقطو_3 ptScreen);

#وصف_ڪريو TPM_LEFTBUTTON 0x0000L
#وصف_ڪريو TPM_RIGHTBUTTON 0x0002L
#وصف_ڪريو TPM_LEFTALIGN 0x0000L
#وصف_ڪريو TPM_CENTERALIGN 0x0004L
#وصف_ڪريو TPM_RIGHTALIGN 0x0008L
#وصف_ڪريو TPM_TOPALIGN 0x0000L
#وصف_ڪريو TPM_VCENTERALIGN 0x0010L
#وصف_ڪريو TPM_BOTTOMALIGN 0x0020L

#وصف_ڪريو TPM_HORIZONTAL 0x0000L
#وصف_ڪريو TPM_VERTICAL 0x0040L
#وصف_ڪريو TPM_NONOTIFY 0x0080L
#وصف_ڪريو TPM_RETURNCMD 0x0100L
#وصف_ڪريو TPM_RECURSE 0x0001L
#وصف_ڪريو TPM_HORPOSANIMATION 0x0400L
#وصف_ڪريو TPM_HORNEGANIMATION 0x0800L
#وصف_ڪريو TPM_VERPOSANIMATION 0x1000L
#وصف_ڪريو TPM_VERNEGANIMATION 0x2000L
#وصف_ڪريو TPM_NOANIMATION 0x4000L
#وصف_ڪريو TPM_LAYOUTRTL 0x8000L
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_DROPSTRUCT {
    HWND hwnd_ذريعو;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dw_معلومات;
    نقطو_3 ptDrop;
    DWORD dw_Control_معلومات;
  } DROPSTRUCT,*PDROPSTRUCT,*LPDROPSTRUCT;

#وصف_ڪريو DOF_EXECUTABLE 0x8001
#وصف_ڪريو DOF_DOCUMENT 0x8002
#وصف_ڪريو DOF_DIRECTORY 0x8003
#وصف_ڪريو DOF_گڻو 0x8004
#وصف_ڪريو DOF_PROGMAN 0x0001
#وصف_ڪريو DOF_SHELLDATA 0x0002

#وصف_ڪريو DO_DROPFILE 0x454C4946L
#وصف_ڪريو DO_PRINTFILE 0x544E5250L

  WINUSERAPI DWORD WINAPI DragObject(HWND hwnd_والد_2,HWND hwndFrom,UINT fmt,ULONG_PTR معلومات,HCURSOR hcur);
  WINUSERAPI WINBOOL WINAPI DragDetect(HWND hwnd,نقطو_3 pt);
  WINUSERAPI WINBOOL WINAPI DrawIcon(HDC hDC,صحيح X,صحيح Y,HICON hIcon);

#جيڪڏهن_وصف_نه_ٿيل NODRAWTEXT

#وصف_ڪريو DT_چوٽي 0x00000000
#وصف_ڪريو DT_کاٻو 0x00000000
#وصف_ڪريو DT_CENTER 0x00000001
#وصف_ڪريو DT_ساڄو 0x00000002
#وصف_ڪريو DT_VCENTER 0x00000004
#وصف_ڪريو DT_BOTTOM 0x00000008
#وصف_ڪريو DT_WORDBREAK 0x00000010
#وصف_ڪريو DT_SINGLELINE 0x00000020
#وصف_ڪريو DT_EXPANDTABS 0x00000040
#وصف_ڪريو DT_TABSTOP 0x00000080
#وصف_ڪريو DT_NOCLIP 0x00000100
#وصف_ڪريو DT_EXTERNALLEADING 0x00000200
#وصف_ڪريو DT_CALCRECT 0x00000400
#وصف_ڪريو DT_NOPREFIX 0x00000800
#وصف_ڪريو DT_اندروني 0x00001000

#وصف_ڪريو DT_EDITCONTROL 0x00002000
#وصف_ڪريو DT_رستو_ELLIPSIS 0x00004000
#وصف_ڪريو DT_پڇاڙي_ELLIPSIS 0x00008000
#وصف_ڪريو DT_MODIFYSTRING 0x00010000
#وصف_ڪريو DT_RTLREADING 0x00020000
#وصف_ڪريو DT_لفظ_ELLIPSIS 0x00040000
#وصف_ڪريو DT_NOFULLWIDTHCHARBREAK 0x00080000
#وصف_ڪريو DT_HIDEPREFIX 0x00100000
#وصف_ڪريو DT_PREFIXONLY 0x00200000

  تعريفنوع بنية ٽيگ_DRAWTEXTPARAMS {
    UINT cb_سائيز;
    صحيح i_Tab_ڊيگهائي;
    صحيح i_کاٻو_Margin;
    صحيح i_ساڄو_Margin;
    UINT ui_ڊيگهائي_Drawn;
  } DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Draw_متن Draw_متن_W
#وصف_ڪريو Draw_متن_Ex Draw_متن_Ex_W
#وإلا
#وصف_ڪريو Draw_متن Draw_متن_A
#وصف_ڪريو Draw_متن_Ex Draw_متن_Ex_A
#جيڪڏهن_پورو

  WINUSERAPI صحيح WINAPI Draw_متن_A(HDC hdc,LPCSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format);
  WINUSERAPI صحيح WINAPI Draw_متن_W(HDC hdc,LPCWSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format);
  WINUSERAPI صحيح WINAPI Draw_متن_Ex_A(HDC hdc,LPSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
  WINUSERAPI صحيح WINAPI Draw_متن_Ex_W(HDC hdc,LPWSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ناسي_String ناسي_String_W
#وصف_ڪريو DrawState DrawStateW
#وصف_ڪريو Tabbed_متن_ٻاهريون Tabbed_متن_ٻاهريون_W
#وصف_ڪريو Get_Tabbed_متن_Extent Get_Tabbed_متن_Extent_W
#وإلا
#وصف_ڪريو ناسي_String ناسي_String_A
#وصف_ڪريو DrawState DrawStateA
#وصف_ڪريو Tabbed_متن_ٻاهريون Tabbed_متن_ٻاهريون_A
#وصف_ڪريو Get_Tabbed_متن_Extent Get_Tabbed_متن_Extent_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI ناسي_String_A(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_معلومات,صحيح n_ڳڻپ,صحيح X,صحيح Y,صحيح n_ويڪر,صحيح n_اوچائي);
  WINUSERAPI WINBOOL WINAPI ناسي_String_W(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_معلومات,صحيح n_ڳڻپ,صحيح X,صحيح Y,صحيح n_ويڪر,صحيح n_اوچائي);

#وصف_ڪريو DST_COMPLEX 0x0000
#وصف_ڪريو DST_متن 0x0001
#وصف_ڪريو DST_PREFIXTEXT 0x0002
#وصف_ڪريو DST_ICON 0x0003
#وصف_ڪريو DST_BITMAP 0x0004

#وصف_ڪريو DSS_عام 0x0000
#وصف_ڪريو DSS_UNION 0x0010
#وصف_ڪريو DSS_DISABLED 0x0020
#وصف_ڪريو DSS_MONO 0x0080
#وصف_ڪريو DSS_HIDEPREFIX 0x0200
#وصف_ڪريو DSS_PREFIXONLY 0x0400
#وصف_ڪريو DSS_ساڄو 0x8000

  WINUSERAPI WINBOOL WINAPI DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_پٺ,LPARAM l_معلومات,WPARAM w_معلومات,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_پٺ,LPARAM l_معلومات,WPARAM w_معلومات,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI LONG WINAPI Tabbed_متن_ٻاهريون_A(HDC hdc,صحيح x,صحيح y,LPCSTR lpString,صحيح ch_ڳڻپ,صحيح nTabPositions,CONST INT *lpnTabStopPositions,صحيح nTabOrigin);
  WINUSERAPI LONG WINAPI Tabbed_متن_ٻاهريون_W(HDC hdc,صحيح x,صحيح y,LPCWSTR lpString,صحيح ch_ڳڻپ,صحيح nTabPositions,CONST INT *lpnTabStopPositions,صحيح nTabOrigin);
  WINUSERAPI DWORD WINAPI Get_Tabbed_متن_Extent_A(HDC hdc,LPCSTR lpString,صحيح ch_ڳڻپ,صحيح nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI DWORD WINAPI Get_Tabbed_متن_Extent_W(HDC hdc,LPCWSTR lpString,صحيح ch_ڳڻپ,صحيح nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI WINBOOL WINAPI Update_دري(HWND hWnd);
  WINUSERAPI HWND WINAPI سيٽ_سرگرم_دري(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_Foreground_دري(VOID);
  WINUSERAPI WINBOOL WINAPI PaintDesktop(HDC hdc);
  WINUSERAPI VOID WINAPI Switch_منزل_This_دري(HWND hwnd,WINBOOL fUnknown);
  WINUSERAPI WINBOOL WINAPI سيٽ_Foreground_دري(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Allow_سيٽ_Foreground_دري(DWORD dwProcessId);

#وصف_ڪريو ASFW_ANY ((DWORD)-1)

  WINUSERAPI WINBOOL WINAPI تالو_سيٽ_Foreground_دري(UINT u_تالو_ڪوڊ);

#وصف_ڪريو LSFW_تالو 1
#وصف_ڪريو LSFW_UNLOCK 2

  WINUSERAPI HWND WINAPI دري_From_DC(HDC hDC);
  WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
  WINUSERAPI HDC WINAPI GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags);

#وصف_ڪريو DCX_دري 0x00000001L
#وصف_ڪريو DCX_CACHE 0x00000002L
#وصف_ڪريو DCX_NORESETATTRS 0x00000004L
#وصف_ڪريو DCX_CLIPCHILDREN 0x00000008L
#وصف_ڪريو DCX_CLIPSIBLINGS 0x00000010L
#وصف_ڪريو DCX_PARENTCLIP 0x00000020L
#وصف_ڪريو DCX_EXCLUDERGN 0x00000040L
#وصف_ڪريو DCX_INTERSECTRGN 0x00000080L
#وصف_ڪريو DCX_EXCLUDEUPDATE 0x00000100L
#وصف_ڪريو DCX_INTERSECTUPDATE 0x00000200L
#وصف_ڪريو DCX_LOCKWINDOWUPDATE 0x00000400L

#وصف_ڪريو DCX_VALIDATE 0x00200000L

  WINUSERAPI HDC WINAPI Get_دري_DC(HWND hWnd);
  WINUSERAPI صحيح WINAPI ReleaseDC(HWND hWnd,HDC hDC);
  WINUSERAPI HDC WINAPI BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
  WINUSERAPI WINBOOL WINAPI پڇاڙي_Paint(HWND hWnd,CONST PAINTSTRUCT *lpPaint);
  WINUSERAPI WINBOOL WINAPI GetUpdateRect(HWND hWnd,LPRECT lpRect,WINBOOL bErase);
  WINUSERAPI صحيح WINAPI GetUpdateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI صحيح WINAPI سيٽ_دري_Rgn(HWND hWnd,HRGN hRgn,WINBOOL bRedraw);
  WINUSERAPI صحيح WINAPI Get_دري_Rgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI صحيح WINAPI Get_دري_Rgn_Box(HWND hWnd,LPRECT lprc);
  WINUSERAPI صحيح WINAPI ExcludeUpdateRgn(HDC hDC,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI InvalidateRect(HWND hWnd,CONST RECT *lpRect,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRect(HWND hWnd,CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI InvalidateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI WINBOOL WINAPI Redraw_دري(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#وصف_ڪريو RDW_INVALIDATE 0x0001
#وصف_ڪريو RDW_INTERNALPAINT 0x0002
#وصف_ڪريو RDW_ERASE 0x0004

#وصف_ڪريو RDW_VALIDATE 0x0008
#وصف_ڪريو RDW_NOINTERNALPAINT 0x0010
#وصف_ڪريو RDW_NOERASE 0x0020

#وصف_ڪريو RDW_NOCHILDREN 0x0040
#وصف_ڪريو RDW_ALLCHILDREN 0x0080

#وصف_ڪريو RDW_UPDATENOW 0x0100
#وصف_ڪريو RDW_ERASENOW 0x0200

#وصف_ڪريو RDW_چوکٺو 0x0400
#وصف_ڪريو RDW_NOFRAME 0x0800

  WINUSERAPI WINBOOL WINAPI تالو_دري_Update(HWND h_Wnd_تالو);
  WINUSERAPI WINBOOL WINAPI Scroll_دري(HWND hWnd,صحيح XAmount,صحيح YAmount,CONST RECT *lpRect,CONST RECT *lpClipRect);
  WINUSERAPI WINBOOL WINAPI ScrollDC(HDC hDC,صحيح dx,صحيح dy,CONST RECT *lprcScroll,CONST RECT *lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
  WINUSERAPI صحيح WINAPI Scroll_دري_Ex(HWND hWnd,صحيح dx,صحيح dy,CONST RECT *prcScroll,CONST RECT *prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);

#وصف_ڪريو SW_SCROLLCHILDREN 0x0001
#وصف_ڪريو SW_INVALIDATE 0x0002
#وصف_ڪريو SW_ERASE 0x0004
#وصف_ڪريو SW_SMOOTHSCROLL 0x0010

#جيڪڏهن_وصف_نه_ٿيل NOSCROLL
  WINUSERAPI صحيح WINAPI سيٽ_Scroll_Pos(HWND hWnd,صحيح nBar,صحيح nPos,WINBOOL bRedraw);
  WINUSERAPI صحيح WINAPI GetScrollPos(HWND hWnd,صحيح nBar);
  WINUSERAPI WINBOOL WINAPI سيٽ_Scroll_Range(HWND hWnd,صحيح nBar,صحيح nMinPos,صحيح nMaxPos,WINBOOL bRedraw);
  WINUSERAPI WINBOOL WINAPI GetScrollRange(HWND hWnd,صحيح nBar,LPINT lpMinPos,LPINT lpMaxPos);
  WINUSERAPI WINBOOL WINAPI ShowScrollBar(HWND hWnd,صحيح wBar,WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows);

#وصف_ڪريو ESB_ENABLE_BOTH 0x0000
#وصف_ڪريو ESB_DISABLE_BOTH 0x0003

#وصف_ڪريو ESB_DISABLE_کاٻو 0x0001
#وصف_ڪريو ESB_DISABLE_ساڄو 0x0002

#وصف_ڪريو ESB_DISABLE_مٿي 0x0001
#وصف_ڪريو ESB_DISABLE_هيٺ_ڏانهن 0x0002

#وصف_ڪريو ESB_DISABLE_LTUP ESB_DISABLE_کاٻو
#وصف_ڪريو ESB_DISABLE_RTDN ESB_DISABLE_ساڄو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو سيٽ_Prop سيٽ_Prop_W
#وصف_ڪريو GetProp GetPropW
#وصف_ڪريو RemoveProp RemovePropW
#وصف_ڪريو EnumPropsEx EnumPropsExW
#وصف_ڪريو EnumProps EnumPropsW
#وصف_ڪريو سيٽ_دري_متن سيٽ_دري_متن_W
#وصف_ڪريو Get_دري_متن Get_دري_متن_W
#وصف_ڪريو Get_دري_متن_ڊيگهائي Get_دري_متن_ڊيگهائي_W
#وإلا
#وصف_ڪريو سيٽ_Prop سيٽ_Prop_A
#وصف_ڪريو GetProp GetPropA
#وصف_ڪريو RemoveProp RemovePropA
#وصف_ڪريو EnumPropsEx EnumPropsExA
#وصف_ڪريو EnumProps EnumPropsA
#وصف_ڪريو سيٽ_دري_متن سيٽ_دري_متن_A
#وصف_ڪريو Get_دري_متن Get_دري_متن_A
#وصف_ڪريو Get_دري_متن_ڊيگهائي Get_دري_متن_ڊيگهائي_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI سيٽ_Prop_A(HWND hWnd,LPCSTR lpString,HANDLE h_معلومات);
  WINUSERAPI WINBOOL WINAPI سيٽ_Prop_W(HWND hWnd,LPCWSTR lpString,HANDLE h_معلومات);
  WINUSERAPI HANDLE WINAPI GetPropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI GetPropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI صحيح WINAPI EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
  WINUSERAPI صحيح WINAPI EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
  WINUSERAPI صحيح WINAPI EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc);
  WINUSERAPI صحيح WINAPI EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc);
  WINUSERAPI WINBOOL WINAPI سيٽ_دري_متن_A(HWND hWnd,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI سيٽ_دري_متن_W(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI صحيح WINAPI Get_دري_متن_A(HWND hWnd,LPSTR lpString,صحيح n_Max_ڳڻپ);
  WINUSERAPI صحيح WINAPI Get_دري_متن_W(HWND hWnd,LPWSTR lpString,صحيح n_Max_ڳڻپ);
  WINUSERAPI صحيح WINAPI Get_دري_متن_ڊيگهائي_A(HWND hWnd);
  WINUSERAPI صحيح WINAPI Get_دري_متن_ڊيگهائي_W(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI GetClientRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Get_دري_Rect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Adjust_دري_Rect(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu);
  WINUSERAPI WINBOOL WINAPI Adjust_دري_Rect_Ex(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu,DWORD dwExStyle);

#وصف_ڪريو HELPINFO_دري 0x0001
#وصف_ڪريو HELPINFO_MENUITEM 0x0002

  تعريفنوع بنية ٽيگ_HELPINFO {
    UINT cb_سائيز;
    صحيح iContextType;
    صحيح iCtrlId;
    HANDLE h_شي_Handle;
    DWORD_PTR dwContextId;
    نقطو_3 MousePos;
  } HELPINFO,*LPHELPINFO;

  WINUSERAPI WINBOOL WINAPI سيٽ_دري_Context_Help_Id(HWND,DWORD);
  WINUSERAPI DWORD WINAPI Get_دري_Context_Help_Id(HWND);
  WINUSERAPI WINBOOL WINAPI سيٽ_Menu_Context_Help_Id(HMENU,DWORD);
  WINUSERAPI DWORD WINAPI GetMenuContextHelpId(HMENU);

#جيڪڏهن_وصف_نه_ٿيل NOMB

#وصف_ڪريو MB_OK 0x00000000L
#وصف_ڪريو MB_OKCANCEL 0x00000001L
#وصف_ڪريو MB_ABORTRETRYIGNORE 0x00000002L
#وصف_ڪريو MB_YESNOCANCEL 0x00000003L
#وصف_ڪريو MB_YESNO 0x00000004L
#وصف_ڪريو MB_RETRYCANCEL 0x00000005L
#وصف_ڪريو MB_CANCELTRYCONTINUE 0x00000006L
#وصف_ڪريو MB_ICONHAND 0x00000010L
#وصف_ڪريو MB_ICONQUESTION 0x00000020L
#وصف_ڪريو MB_ICONEXCLAMATION 0x00000030L
#وصف_ڪريو MB_ICONASTERISK 0x00000040L
#وصف_ڪريو MB_USERICON 0x00000080L
#وصف_ڪريو MB_ICONWARNING MB_ICONEXCLAMATION
#وصف_ڪريو MB_ICONERROR MB_ICONHAND
#وصف_ڪريو MB_ICONINFORMATION MB_ICONASTERISK
#وصف_ڪريو MB_ICONSTOP MB_ICONHAND
#وصف_ڪريو MB_DEFBUTTON1 0x00000000L
#وصف_ڪريو MB_DEFBUTTON2 0x00000100L
#وصف_ڪريو MB_DEFBUTTON3 0x00000200L
#وصف_ڪريو MB_DEFBUTTON4 0x00000300L
#وصف_ڪريو MB_APPLMODAL 0x00000000L
#وصف_ڪريو MB_SYSTEMMODAL 0x00001000L
#وصف_ڪريو MB_TASKMODAL 0x00002000L
#وصف_ڪريو MB_HELP 0x00004000L
#وصف_ڪريو MB_NOFOCUS 0x00008000L
#وصف_ڪريو MB_SETFOREGROUND 0x00010000L
#وصف_ڪريو MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#وصف_ڪريو MB_TOPMOST 0x00040000L
#وصف_ڪريو MB_ساڄو 0x00080000L
#وصف_ڪريو MB_RTLREADING 0x00100000L
#وصف_ڪريو MB_SERVICE_NOTIFICATION 0x00200000L
#وصف_ڪريو MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#وصف_ڪريو MB_TYPEMASK 0x0000000FL
#وصف_ڪريو MB_ICONMASK 0x000000F0L
#وصف_ڪريو MB_DEFMASK 0x00000F00L
#وصف_ڪريو MB_MODEMASK 0x00003000L
#وصف_ڪريو MB_MISCMASK 0x0000C000L

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو پيغام_Box پيغام_Box_W
#وصف_ڪريو پيغام_Box_Ex پيغام_Box_Ex_W
#وإلا
#وصف_ڪريو پيغام_Box پيغام_Box_A
#وصف_ڪريو پيغام_Box_Ex پيغام_Box_Ex_A
#جيڪڏهن_پورو

  WINUSERAPI صحيح WINAPI پيغام_Box_A(HWND hWnd,LPCSTR lp_متن,LPCSTR lpCaption,UINT uType);
  WINUSERAPI صحيح WINAPI پيغام_Box_W(HWND hWnd,LPCWSTR lp_متن,LPCWSTR lpCaption,UINT uType);
  WINUSERAPI صحيح WINAPI پيغام_Box_Ex_A(HWND hWnd,LPCSTR lp_متن,LPCSTR lpCaption,UINT uType,لفظ_3 wLanguageId);
  WINUSERAPI صحيح WINAPI پيغام_Box_Ex_W(HWND hWnd,LPCWSTR lp_متن,LPCWSTR lpCaption,UINT uType,لفظ_3 wLanguageId);

  تعريفنوع VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

  تعريفنوع بنية ٽيگ_MSGBOXPARAMSA {
    UINT cb_سائيز;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpsz_متن;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_نياپو_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSA,*PMSGBOXPARAMSA,*LPMSGBOXPARAMSA;

  تعريفنوع بنية ٽيگ_MSGBOXPARAMSW {
    UINT cb_سائيز;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpsz_متن;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_نياپو_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSW,*PMSGBOXPARAMSW,*LPMSGBOXPARAMSW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع MSGBOXPARAMSW MSGBOXPARAMS;
  تعريفنوع PMSGBOXPARAMSW PMSGBOXPARAMS;
  تعريفنوع LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#وإلا
  تعريفنوع MSGBOXPARAMSA MSGBOXPARAMS;
  تعريفنوع PMSGBOXPARAMSA PMSGBOXPARAMS;
  تعريفنوع LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو پيغام_Box_اڻسڌو پيغام_Box_اڻسڌو_W
#وإلا
#وصف_ڪريو پيغام_Box_اڻسڌو پيغام_Box_اڻسڌو_A
#جيڪڏهن_پورو

  WINUSERAPI صحيح WINAPI پيغام_Box_اڻسڌو_A(CONST MSGBOXPARAMSA *lpmbp);
  WINUSERAPI صحيح WINAPI پيغام_Box_اڻسڌو_W(CONST MSGBOXPARAMSW *lpmbp);
  WINUSERAPI WINBOOL WINAPI پيغام_Beep(UINT uType);
#جيڪڏهن_پورو

  WINUSERAPI صحيح WINAPI ShowCursor(WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI سيٽ_Cursor_Pos(صحيح X,صحيح Y);
  WINUSERAPI HCURSOR WINAPI سيٽ_Cursor(HCURSOR hCursor);
  WINUSERAPI WINBOOL WINAPI GetCursorPos(LPPOINT lp_نقطو);
  WINUSERAPI WINBOOL WINAPI ClipCursor(CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI GetClipCursor(LPRECT lpRect);
  WINUSERAPI HCURSOR WINAPI GetCursor(VOID);
  WINUSERAPI WINBOOL WINAPI CreateCaret(HWND hWnd,HBITMAP hBitmap,صحيح n_ويڪر,صحيح n_اوچائي);
  WINUSERAPI UINT WINAPI Get_Caret_Blink_وقت(VOID);
  WINUSERAPI WINBOOL WINAPI سيٽ_Caret_Blink_وقت(UINT uMSeconds);
  WINUSERAPI WINBOOL WINAPI DestroyCaret(VOID);
  WINUSERAPI WINBOOL WINAPI HideCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI سيٽ_Caret_Pos(صحيح X,صحيح Y);
  WINUSERAPI WINBOOL WINAPI GetCaretPos(LPPOINT lp_نقطو);
  WINUSERAPI WINBOOL WINAPI Client_منزل_Screen(HWND hWnd,LPPOINT lp_نقطو);
  WINUSERAPI WINBOOL WINAPI Screen_منزل_Client(HWND hWnd,LPPOINT lp_نقطو);
  WINUSERAPI صحيح WINAPI Map_دري_Points(HWND hWndFrom,HWND h_Wnd_منزل,LPPOINT lpPoints,UINT cPoints);
  WINUSERAPI HWND WINAPI دري_From_نقطو(نقطو_3 نقطو_2);
  WINUSERAPI HWND WINAPI ٻار_دري_From_نقطو(HWND h_Wnd_والد,نقطو_3 نقطو_2);

#وصف_ڪريو CWP_ALL 0x0000
#وصف_ڪريو CWP_SKIPINVISIBLE 0x0001
#وصف_ڪريو CWP_SKIPDISABLED 0x0002
#وصف_ڪريو CWP_SKIPTRANSPARENT 0x0004

  WINUSERAPI HWND WINAPI ٻار_دري_From_نقطو_Ex(HWND hwnd,نقطو_3 pt,UINT flags);

#جيڪڏهن_وصف_نه_ٿيل NOCOLOR

#وصف_ڪريو CTLCOLOR_MSGBOX 0
#وصف_ڪريو CTLCOLOR_EDIT 1
#وصف_ڪريو CTLCOLOR_LISTBOX 2
#وصف_ڪريو CTLCOLOR_BTN 3
#وصف_ڪريو CTLCOLOR_DLG 4
#وصف_ڪريو CTLCOLOR_SCROLLBAR 5
#وصف_ڪريو CTLCOLOR_STATIC 6
#وصف_ڪريو CTLCOLOR_MAX 7

#وصف_ڪريو COLOR_SCROLLBAR 0
#وصف_ڪريو COLOR_BACKGROUND 1
#وصف_ڪريو COLOR_ACTIVECAPTION 2
#وصف_ڪريو COLOR_INACTIVECAPTION 3
#وصف_ڪريو COLOR_MENU 4
#وصف_ڪريو COLOR_دري 5
#وصف_ڪريو COLOR_WINDOWFRAME 6
#وصف_ڪريو COLOR_MENUTEXT 7
#وصف_ڪريو COLOR_WINDOWTEXT 8
#وصف_ڪريو COLOR_CAPTIONTEXT 9
#وصف_ڪريو COLOR_ACTIVEBORDER 10
#وصف_ڪريو COLOR_INACTIVEBORDER 11
#وصف_ڪريو COLOR_APPWORKSPACE 12
#وصف_ڪريو COLOR_HIGHLIGHT 13
#وصف_ڪريو COLOR_HIGHLIGHTTEXT 14
#وصف_ڪريو COLOR_BTNFACE 15
#وصف_ڪريو COLOR_BTNSHADOW 16
#وصف_ڪريو COLOR_GRAYTEXT 17
#وصف_ڪريو COLOR_BTNTEXT 18
#وصف_ڪريو COLOR_INACTIVECAPTIONTEXT 19
#وصف_ڪريو COLOR_BTNHIGHLIGHT 20

#وصف_ڪريو COLOR_3DDKSHADOW 21
#وصف_ڪريو COLOR_3DLIGHT 22
#وصف_ڪريو COLOR_INFOTEXT 23
#وصف_ڪريو COLOR_INFOBK 24

#وصف_ڪريو COLOR_HOTLIGHT 26
#وصف_ڪريو COLOR_GRADIENTACTIVECAPTION 27
#وصف_ڪريو COLOR_GRADIENTINACTIVECAPTION 28
#وصف_ڪريو COLOR_MENUHILIGHT 29
#وصف_ڪريو COLOR_MENUBAR 30

#وصف_ڪريو COLOR_DESKTOP COLOR_BACKGROUND
#وصف_ڪريو COLOR_3DFACE COLOR_BTNFACE
#وصف_ڪريو COLOR_3DSHADOW COLOR_BTNSHADOW
#وصف_ڪريو COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#وصف_ڪريو COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#وصف_ڪريو COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

  WINUSERAPI DWORD WINAPI GetSysColor(صحيح n_اشاريو);
  WINUSERAPI HBRUSH WINAPI GetSysColorBrush(صحيح n_اشاريو);
  WINUSERAPI WINBOOL WINAPI سيٽ_Sys_Colors(صحيح cElements,CONST INT *lpaElements,CONST COLORREF *lpa_Rgb_قدرون);
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI DrawFocusRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI صحيح WINAPI FillRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI صحيح WINAPI چوکٺو_Rect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI WINBOOL WINAPI InvertRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI سيٽ_Rect(LPRECT lprc,صحيح x_کاٻو,صحيح y_چوٽي,صحيح x_ساڄو,صحيح yBottom);
  WINUSERAPI WINBOOL WINAPI سيٽ_Rect_خالي_جايون(LPRECT lprc);
  WINUSERAPI WINBOOL WINAPI CopyRect(LPRECT lprcDst,CONST RECT *lprcSrc);
  WINUSERAPI WINBOOL WINAPI InflateRect(LPRECT lprc,صحيح dx,صحيح dy);
  WINUSERAPI WINBOOL WINAPI IntersectRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI UnionRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI ڪٽيو_Rect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI وٿي_Rect(LPRECT lprc,صحيح dx,صحيح dy);
  WINUSERAPI WINBOOL WINAPI Is_Rect_خالي_جايون(CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI EqualRect(CONST RECT *lprc1,CONST RECT *lprc2);
  WINUSERAPI WINBOOL WINAPI Pt_اندريون_Rect(CONST RECT *lprc,نقطو_3 pt);

#جيڪڏهن_وصف_نه_ٿيل NOWINOFFSETS

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_دري_Long Get_دري_Long_W
#وصف_ڪريو سيٽ_دري_Long سيٽ_دري_Long_W
#وإلا
#وصف_ڪريو Get_دري_Long Get_دري_Long_A
#وصف_ڪريو سيٽ_دري_Long سيٽ_دري_Long_A
#جيڪڏهن_پورو

  WINUSERAPI لفظ_3 WINAPI Get_دري_لفظ(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI لفظ_3 WINAPI سيٽ_دري_لفظ(HWND hWnd,صحيح n_اشاريو,لفظ_3 w_New_لفظ);
  WINUSERAPI LONG WINAPI Get_دري_Long_A(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI LONG WINAPI Get_دري_Long_W(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI LONG WINAPI سيٽ_دري_Long_A(HWND hWnd,صحيح n_اشاريو,LONG dwNewLong);
  WINUSERAPI LONG WINAPI سيٽ_دري_Long_W(HWND hWnd,صحيح n_اشاريو,LONG dwNewLong);

#جيڪڏهن_وصف_ٿيل _WIN64

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_دري_Long_Ptr Get_دري_Long_Ptr_W
#وصف_ڪريو سيٽ_دري_Long_Ptr سيٽ_دري_Long_Ptr_W
#وإلا
#وصف_ڪريو Get_دري_Long_Ptr Get_دري_Long_Ptr_A
#وصف_ڪريو سيٽ_دري_Long_Ptr سيٽ_دري_Long_Ptr_A
#جيڪڏهن_پورو

  WINUSERAPI LONG_PTR WINAPI Get_دري_Long_Ptr_A(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI LONG_PTR WINAPI Get_دري_Long_Ptr_W(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI LONG_PTR WINAPI سيٽ_دري_Long_Ptr_A(HWND hWnd,صحيح n_اشاريو,LONG_PTR dwNewLong);
  WINUSERAPI LONG_PTR WINAPI سيٽ_دري_Long_Ptr_W(HWND hWnd,صحيح n_اشاريو,LONG_PTR dwNewLong);
#وإلا

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_دري_Long_Ptr Get_دري_Long_Ptr_W
#وصف_ڪريو سيٽ_دري_Long_Ptr سيٽ_دري_Long_Ptr_W
#وإلا
#وصف_ڪريو Get_دري_Long_Ptr Get_دري_Long_Ptr_A
#وصف_ڪريو سيٽ_دري_Long_Ptr سيٽ_دري_Long_Ptr_A
#جيڪڏهن_پورو

#وصف_ڪريو Get_دري_Long_Ptr_A Get_دري_Long_A
#وصف_ڪريو Get_دري_Long_Ptr_W Get_دري_Long_W
#وصف_ڪريو سيٽ_دري_Long_Ptr_A سيٽ_دري_Long_A
#وصف_ڪريو سيٽ_دري_Long_Ptr_W سيٽ_دري_Long_W
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetClassLong GetClassLongW
#وصف_ڪريو سيٽ_Class_Long سيٽ_Class_Long_W
#وإلا
#وصف_ڪريو GetClassLong GetClassLongA
#وصف_ڪريو سيٽ_Class_Long سيٽ_Class_Long_A
#جيڪڏهن_پورو

  WINUSERAPI لفظ_3 WINAPI Get_Class_لفظ(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI لفظ_3 WINAPI سيٽ_Class_لفظ(HWND hWnd,صحيح n_اشاريو,لفظ_3 w_New_لفظ);
  WINUSERAPI DWORD WINAPI GetClassLongA(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI DWORD WINAPI GetClassLongW(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI DWORD WINAPI سيٽ_Class_Long_A(HWND hWnd,صحيح n_اشاريو,LONG dwNewLong);
  WINUSERAPI DWORD WINAPI سيٽ_Class_Long_W(HWND hWnd,صحيح n_اشاريو,LONG dwNewLong);

#جيڪڏهن_وصف_ٿيل _WIN64

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetClassLongPtr GetClassLongPtrW
#وصف_ڪريو سيٽ_Class_Long_Ptr سيٽ_Class_Long_Ptr_W
#وإلا
#وصف_ڪريو GetClassLongPtr GetClassLongPtrA
#وصف_ڪريو سيٽ_Class_Long_Ptr سيٽ_Class_Long_Ptr_A
#جيڪڏهن_پورو

  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd,صحيح n_اشاريو);
  WINUSERAPI ULONG_PTR WINAPI سيٽ_Class_Long_Ptr_A(HWND hWnd,صحيح n_اشاريو,LONG_PTR dwNewLong);
  WINUSERAPI ULONG_PTR WINAPI سيٽ_Class_Long_Ptr_W(HWND hWnd,صحيح n_اشاريو,LONG_PTR dwNewLong);
#وإلا
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetClassLongPtr GetClassLongPtrW
#وصف_ڪريو سيٽ_Class_Long_Ptr سيٽ_Class_Long_Ptr_W
#وإلا
#وصف_ڪريو GetClassLongPtr GetClassLongPtrA
#وصف_ڪريو سيٽ_Class_Long_Ptr سيٽ_Class_Long_Ptr_A
#جيڪڏهن_پورو

#وصف_ڪريو GetClassLongPtrA GetClassLongA
#وصف_ڪريو GetClassLongPtrW GetClassLongW
#وصف_ڪريو سيٽ_Class_Long_Ptr_A سيٽ_Class_Long_A
#وصف_ڪريو سيٽ_Class_Long_Ptr_W سيٽ_Class_Long_W
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڳوليو_دري ڳوليو_دري_W
#وصف_ڪريو ڳوليو_دري_Ex ڳوليو_دري_Ex_W
#وصف_ڪريو GetClassName GetClassNameW
#وإلا
#وصف_ڪريو ڳوليو_دري ڳوليو_دري_A
#وصف_ڪريو ڳوليو_دري_Ex ڳوليو_دري_Ex_A
#وصف_ڪريو GetClassName GetClassNameA
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI GetProcessDefaultLayout(DWORD *pdwDefaultLayout);
  WINUSERAPI WINBOOL WINAPI سيٽ_Process_Default_Layout(DWORD dwDefaultLayout);
  WINUSERAPI HWND WINAPI Get_Desktop_دري(VOID);
  WINUSERAPI HWND WINAPI Get_والد(HWND hWnd);
  WINUSERAPI HWND WINAPI سيٽ_والد(HWND h_Wnd_ٻار,HWND h_Wnd_New_والد);
  WINUSERAPI WINBOOL WINAPI Enum_ٻار_Windows(HWND h_Wnd_والد,WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI HWND WINAPI ڳوليو_دري_A(LPCSTR lpClassName,LPCSTR lp_دري_Name);
  WINUSERAPI HWND WINAPI ڳوليو_دري_W(LPCWSTR lpClassName,LPCWSTR lp_دري_Name);
  WINUSERAPI HWND WINAPI ڳوليو_دري_Ex_A(HWND h_Wnd_والد,HWND h_Wnd_ٻار_After,LPCSTR lpszClass,LPCSTR lpsz_دري);
  WINUSERAPI HWND WINAPI ڳوليو_دري_Ex_W(HWND h_Wnd_والد,HWND h_Wnd_ٻار_After,LPCWSTR lpszClass,LPCWSTR lpsz_دري);
  WINUSERAPI HWND WINAPI Get_Shell_دري(VOID);
  WINUSERAPI WINBOOL WINAPI رجسٽر_Shell_Hook_دري(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI Deregister_Shell_Hook_دري(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);

#وصف_ڪريو EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(Handle_منزل_Ulong(hTask),lpfn,lParam)

  WINUSERAPI صحيح WINAPI GetClassNameA(HWND hWnd,LPSTR lpClassName,صحيح n_Max_ڳڻپ);
  WINUSERAPI صحيح WINAPI GetClassNameW(HWND hWnd,LPWSTR lpClassName,صحيح n_Max_ڳڻپ);
  WINUSERAPI HWND WINAPI Get_چوٽي_دري(HWND hWnd);

#وصف_ڪريو Get_ايندڙ_دري(hWnd,wCmd) Get_دري(hWnd,wCmd)
#وصف_ڪريو Get_Sys_Modal_دري() (عدم)
#وصف_ڪريو سيٽ_Sys_Modal_دري(hWnd) (عدم)

  WINUSERAPI DWORD WINAPI Get_دري_Thread_Process_Id(HWND hWnd,LPDWORD lpdwProcessId);
  WINUSERAPI WINBOOL WINAPI IsGUIThread(WINBOOL bConvert);

#وصف_ڪريو Get_دري_Task(hWnd) ((HANDLE)(DWORD_PTR)Get_دري_Thread_Process_Id(hWnd,عدم))

  WINUSERAPI HWND WINAPI Get_آخري_سرگرم_Popup(HWND hWnd);

#وصف_ڪريو GW_HWNDFIRST 0
#وصف_ڪريو GW_HWNDLAST 1
#وصف_ڪريو GW_HWNDNEXT 2
#وصف_ڪريو GW_HWNDPREV 3
#وصف_ڪريو GW_OWNER 4
#وصف_ڪريو GW_ٻار 5
#وصف_ڪريو GW_ENABLEDPOPUP 6
#وصف_ڪريو GW_MAX 6

  WINUSERAPI HWND WINAPI Get_دري(HWND hWnd,UINT uCmd);

#جيڪڏهن_وصف_نه_ٿيل NOWH

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو سيٽ_Windows_Hook سيٽ_Windows_Hook_W
#وصف_ڪريو سيٽ_Windows_Hook_Ex سيٽ_Windows_Hook_Ex_W
#وإلا
#وصف_ڪريو سيٽ_Windows_Hook سيٽ_Windows_Hook_A
#وصف_ڪريو سيٽ_Windows_Hook_Ex سيٽ_Windows_Hook_Ex_A
#جيڪڏهن_پورو

  WINUSERAPI HHOOK WINAPI سيٽ_Windows_Hook_A(صحيح nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI سيٽ_Windows_Hook_W(صحيح nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHook(صحيح n_ڪوڊ,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI سيٽ_Windows_Hook_Ex_A(صحيح idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI HHOOK WINAPI سيٽ_Windows_Hook_Ex_W(صحيح idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);
  WINUSERAPI LRESULT WINAPI Call_ايندڙ_Hook_Ex(HHOOK hhk,صحيح n_ڪوڊ,WPARAM wParam,LPARAM lParam);
#وصف_ڪريو DefHookProc(n_ڪوڊ,wParam,lParam,phhk) Call_ايندڙ_Hook_Ex(*phhk,n_ڪوڊ,wParam,lParam)
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOMENUS

#وصف_ڪريو MF_وجهو 0x00000000L
#وصف_ڪريو MF_CHANGE 0x00000080L
#وصف_ڪريو MF_APPEND 0x00000100L
#وصف_ڪريو MF_DELETE 0x00000200L
#وصف_ڪريو MF_REMOVE 0x00001000L
#وصف_ڪريو MF_BYCOMMAND 0x00000000L
#وصف_ڪريو MF_BYPOSITION 0x00000400L
#وصف_ڪريو MF_SEPARATOR 0x00000800L
#وصف_ڪريو MF_ENABLED 0x00000000L
#وصف_ڪريو MF_GRAYED 0x00000001L
#وصف_ڪريو MF_DISABLED 0x00000002L
#وصف_ڪريو MF_UNCHECKED 0x00000000L
#وصف_ڪريو MF_CHECKED 0x00000008L
#وصف_ڪريو MF_USECHECKBITMAPS 0x00000200L
#وصف_ڪريو MF_STRING 0x00000000L
#وصف_ڪريو MF_BITMAP 0x00000004L
#وصف_ڪريو MF_OWNERDRAW 0x00000100L
#وصف_ڪريو MF_POPUP 0x00000010L
#وصف_ڪريو MF_MENUBARBREAK 0x00000020L
#وصف_ڪريو MF_MENUBREAK 0x00000040L
#وصف_ڪريو MF_UNHILITE 0x00000000L
#وصف_ڪريو MF_HILITE 0x00000080L
#وصف_ڪريو MF_DEFAULT 0x00001000L
#وصف_ڪريو MF_SYSMENU 0x00002000L
#وصف_ڪريو MF_HELP 0x00004000L
#وصف_ڪريو MF_RIGHTJUSTIFY 0x00004000L
#وصف_ڪريو MF_MOUSESELECT 0x00008000L
#وصف_ڪريو MF_پڇاڙي 0x00000080L

#وصف_ڪريو MFT_STRING MF_STRING
#وصف_ڪريو MFT_BITMAP MF_BITMAP
#وصف_ڪريو MFT_MENUBARBREAK MF_MENUBARBREAK
#وصف_ڪريو MFT_MENUBREAK MF_MENUBREAK
#وصف_ڪريو MFT_OWNERDRAW MF_OWNERDRAW
#وصف_ڪريو MFT_RADIOCHECK 0x00000200L
#وصف_ڪريو MFT_SEPARATOR MF_SEPARATOR
#وصف_ڪريو MFT_RIGHTORDER 0x00002000L
#وصف_ڪريو MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#وصف_ڪريو MFS_GRAYED 0x00000003L
#وصف_ڪريو MFS_DISABLED MFS_GRAYED
#وصف_ڪريو MFS_CHECKED MF_CHECKED
#وصف_ڪريو MFS_HILITE MF_HILITE
#وصف_ڪريو MFS_ENABLED MF_ENABLED
#وصف_ڪريو MFS_UNCHECKED MF_UNCHECKED
#وصف_ڪريو MFS_UNHILITE MF_UNHILITE
#وصف_ڪريو MFS_DEFAULT MF_DEFAULT

  WINUSERAPI WINBOOL WINAPI Check_Menu_Radio_شي(HMENU hmenu,UINT پهريون,UINT آخري,UINT check,UINT flags);

  تعريفنوع بنية {
    لفظ_3 نسخو_عدد;
    لفظ_3 وٿي;
  } MENUITEMTEMPLATEHEADER,*PMENUITEMTEMPLATEHEADER;

  تعريفنوع بنية {
    لفظ_3 mtOption;
    لفظ_3 mtID;
    WCHAR mtString[1];
  } MENUITEMTEMPLATE,*PMENUITEMTEMPLATE;
#وصف_ڪريو MF_پڇاڙي 0x00000080L
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOSYSCOMMANDS

#وصف_ڪريو SC_سائيز 0xF000
#وصف_ڪريو SC_MOVE 0xF010
#وصف_ڪريو SC_MINIMIZE 0xF020
#وصف_ڪريو SC_MAXIMIZE 0xF030
#وصف_ڪريو SC_NEXTWINDOW 0xF040
#وصف_ڪريو SC_PREVWINDOW 0xF050
#وصف_ڪريو SC_CLOSE 0xF060
#وصف_ڪريو SC_VSCROLL 0xF070
#وصف_ڪريو SC_HSCROLL 0xF080
#وصف_ڪريو SC_MOUSEMENU 0xF090
#وصف_ڪريو SC_KEYMENU 0xF100
#وصف_ڪريو SC_ARRANGE 0xF110
#وصف_ڪريو SC_RESTORE 0xF120
#وصف_ڪريو SC_TASKLIST 0xF130
#وصف_ڪريو SC_SCREENSAVE 0xF140
#وصف_ڪريو SC_HOTKEY 0xF150
#وصف_ڪريو SC_DEFAULT 0xF160
#وصف_ڪريو SC_MONITORPOWER 0xF170
#وصف_ڪريو SC_CONTEXTHELP 0xF180
#وصف_ڪريو SC_SEPARATOR 0xF00F
#وصف_ڪريو SC_ICON SC_MINIMIZE
#وصف_ڪريو SC_ZOOM SC_MAXIMIZE
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڀريو_Bitmap ڀريو_Bitmap_W
#وصف_ڪريو ڀريو_Cursor ڀريو_Cursor_W
#وصف_ڪريو ڀريو_Cursor_From_File ڀريو_Cursor_From_File_W
#وإلا
#وصف_ڪريو ڀريو_Bitmap ڀريو_Bitmap_A
#وصف_ڪريو ڀريو_Cursor ڀريو_Cursor_A
#وصف_ڪريو ڀريو_Cursor_From_File ڀريو_Cursor_From_File_A
#جيڪڏهن_پورو

  WINUSERAPI HBITMAP WINAPI ڀريو_Bitmap_A(HINSTANCE hInstance,LPCSTR lpBitmapName);
  WINUSERAPI HBITMAP WINAPI ڀريو_Bitmap_W(HINSTANCE hInstance,LPCWSTR lpBitmapName);
  WINUSERAPI HCURSOR WINAPI ڀريو_Cursor_A(HINSTANCE hInstance,LPCSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI ڀريو_Cursor_W(HINSTANCE hInstance,LPCWSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI ڀريو_Cursor_From_File_A(LPCSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI ڀريو_Cursor_From_File_W(LPCWSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI CreateCursor(HINSTANCE hInst,صحيح xHotSpot,صحيح yHotSpot,صحيح n_ويڪر,صحيح n_اوچائي,CONST VOID *pvANDPlane,CONST VOID *pvXORPlane);
  WINUSERAPI WINBOOL WINAPI DestroyCursor(HCURSOR hCursor);

#وصف_ڪريو CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

#وصف_ڪريو IDC_ARROW MAKEINTRESOURCE(32512)
#وصف_ڪريو IDC_IBEAM MAKEINTRESOURCE(32513)
#وصف_ڪريو IDC_WAIT MAKEINTRESOURCE(32514)
#وصف_ڪريو IDC_CROSS MAKEINTRESOURCE(32515)
#وصف_ڪريو IDC_UPARROW MAKEINTRESOURCE(32516)
#وصف_ڪريو IDC_سائيز MAKEINTRESOURCE(32640)
#وصف_ڪريو IDC_ICON MAKEINTRESOURCE(32641)
#وصف_ڪريو IDC_SIZENWSE MAKEINTRESOURCE(32642)
#وصف_ڪريو IDC_SIZENESW MAKEINTRESOURCE(32643)
#وصف_ڪريو IDC_SIZEWE MAKEINTRESOURCE(32644)
#وصف_ڪريو IDC_SIZENS MAKEINTRESOURCE(32645)
#وصف_ڪريو IDC_SIZEALL MAKEINTRESOURCE(32646)
#وصف_ڪريو IDC_NO MAKEINTRESOURCE(32648)
#وصف_ڪريو IDC_HAND MAKEINTRESOURCE(32649)
#وصف_ڪريو IDC_APPSTARTING MAKEINTRESOURCE(32650)
#وصف_ڪريو IDC_HELP MAKEINTRESOURCE(32651)

  WINUSERAPI WINBOOL WINAPI سيٽ_System_Cursor(HCURSOR hcur,DWORD id);

  تعريفنوع بنية _ICONINFO {
    WINBOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbm_نقاب;
    HBITMAP hbmColor;
  } ICONINFO;
  تعريفنوع ICONINFO *PICONINFO;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڀريو_Icon ڀريو_Icon_W
#وصف_ڪريو ذاتي_ڪڍو_Icons ذاتي_ڪڍو_Icons_W
#وإلا
#وصف_ڪريو ڀريو_Icon ڀريو_Icon_A
#وصف_ڪريو ذاتي_ڪڍو_Icons ذاتي_ڪڍو_Icons_A
#جيڪڏهن_پورو

  WINUSERAPI HICON WINAPI ڀريو_Icon_A(HINSTANCE hInstance,LPCSTR lpIconName);
  WINUSERAPI HICON WINAPI ڀريو_Icon_W(HINSTANCE hInstance,LPCWSTR lpIconName);
  WINUSERAPI UINT WINAPI ذاتي_ڪڍو_Icons_A(LPCSTR szFileName,صحيح n_Icon_اشاريو,صحيح cxIcon,صحيح cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI UINT WINAPI ذاتي_ڪڍو_Icons_W(LPCWSTR szFileName,صحيح n_Icon_اشاريو,صحيح cxIcon,صحيح cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI HICON WINAPI CreateIcon(HINSTANCE hInstance,صحيح n_ويڪر,صحيح n_اوچائي,BYTE cPlanes,BYTE c_بٽ_Pixel,CONST BYTE *lpbANDbits,CONST BYTE *lpbXORbits);
  WINUSERAPI WINBOOL WINAPI DestroyIcon(HICON hIcon);
  WINUSERAPI صحيح WINAPI LookupIconIdFromDirectory(PBYTE presbits,WINBOOL fIcon);
  WINUSERAPI صحيح WINAPI LookupIconIdFromDirectoryEx(PBYTE presbits,WINBOOL fIcon,صحيح cxDesired,صحيح cyDesired,UINT Flags);
  WINUSERAPI HICON WINAPI CreateIconFromResource(PBYTE presbits,DWORD dw_Res_سائيز,WINBOOL fIcon,DWORD dwVer);
  WINUSERAPI HICON WINAPI CreateIconFromResourceEx(PBYTE presbits,DWORD dw_Res_سائيز,WINBOOL fIcon,DWORD dwVer,صحيح cxDesired,صحيح cyDesired,UINT Flags);

  تعريفنوع بنية ٽيگ_CURSORSHAPE {
    صحيح xHotSpot;
    صحيح yHotSpot;
    صحيح cx;
    صحيح cy;
    صحيح cb_ويڪر;
    BYTE Planes;
    BYTE بٽ_Pixel;
  } CURSORSHAPE,*LPCURSORSHAPE;

#وصف_ڪريو IMAGE_BITMAP 0
#وصف_ڪريو IMAGE_ICON 1
#وصف_ڪريو IMAGE_CURSOR 2
#وصف_ڪريو IMAGE_ENHMETAFILE 3

#وصف_ڪريو LR_DEFAULTCOLOR 0x0000
#وصف_ڪريو LR_MONOCHROME 0x0001
#وصف_ڪريو LR_COLOR 0x0002
#وصف_ڪريو LR_COPYRETURNORG 0x0004
#وصف_ڪريو LR_COPYDELETEORG 0x0008
#وصف_ڪريو LR_LOADFROMFILE 0x0010
#وصف_ڪريو LR_LOADTRANSPARENT 0x0020
#وصف_ڪريو LR_DEFAULTSIZE 0x0040
#وصف_ڪريو LR_VGACOLOR 0x0080
#وصف_ڪريو LR_LOADMAP3DCOLORS 0x1000
#وصف_ڪريو LR_CREATEDIBSECTION 0x2000
#وصف_ڪريو LR_COPYFROMRESOURCE 0x4000
#وصف_ڪريو LR_SHARED 0x8000

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڀريو_Image ڀريو_Image_W
#وإلا
#وصف_ڪريو ڀريو_Image ڀريو_Image_A
#جيڪڏهن_پورو

  WINUSERAPI HANDLE WINAPI ڀريو_Image_A(HINSTANCE hInst,LPCSTR name,UINT type,صحيح cx,صحيح cy,UINT fu_ڀريو);
  WINUSERAPI HANDLE WINAPI ڀريو_Image_W(HINSTANCE hInst,LPCWSTR name,UINT type,صحيح cx,صحيح cy,UINT fu_ڀريو);
  WINUSERAPI HANDLE WINAPI CopyImage(HANDLE h,UINT type,صحيح cx,صحيح cy,UINT flags);

#وصف_ڪريو DI_نقاب 0x0001
#وصف_ڪريو DI_IMAGE 0x0002
#وصف_ڪريو DI_عام 0x0003
#وصف_ڪريو DI_COMPAT 0x0004
#وصف_ڪريو DI_DEFAULTSIZE 0x0008
#وصف_ڪريو DI_NOMIRROR 0x0010

  WINUSERAPI WINBOOL WINAPI DrawIconEx(HDC hdc,صحيح x_کاٻو,صحيح y_چوٽي,HICON hIcon,صحيح cx_ويڪر,صحيح cy_ويڪر,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
  WINUSERAPI HICON WINAPI Create_Icon_اڻسڌو(PICONINFO piconinfo);
  WINUSERAPI HICON WINAPI CopyIcon(HICON hIcon);
  WINUSERAPI WINBOOL WINAPI GetIconInfo(HICON hIcon,PICONINFO piconinfo);

#وصف_ڪريو RES_ICON 1
#وصف_ڪريو RES_CURSOR 2

#جيڪڏهن_وصف_ٿيل OEMRESOURCE

#وصف_ڪريو OBM_CLOSE 32754
#وصف_ڪريو OBM_UPARROW 32753
#وصف_ڪريو OBM_DNARROW 32752
#وصف_ڪريو OBM_RGARROW 32751
#وصف_ڪريو OBM_LFARROW 32750
#وصف_ڪريو OBM_REDUCE 32749
#وصف_ڪريو OBM_ZOOM 32748
#وصف_ڪريو OBM_RESTORE 32747
#وصف_ڪريو OBM_REDUCED 32746
#وصف_ڪريو OBM_ZOOMD 32745
#وصف_ڪريو OBM_RESTORED 32744
#وصف_ڪريو OBM_UPARROWD 32743
#وصف_ڪريو OBM_DNARROWD 32742
#وصف_ڪريو OBM_RGARROWD 32741
#وصف_ڪريو OBM_LFARROWD 32740
#وصف_ڪريو OBM_MNARROW 32739
#وصف_ڪريو OBM_COMBO 32738
#وصف_ڪريو OBM_UPARROWI 32737
#وصف_ڪريو OBM_DNARROWI 32736
#وصف_ڪريو OBM_RGARROWI 32735
#وصف_ڪريو OBM_LFARROWI 32734

#وصف_ڪريو OBM_OLD_CLOSE 32767
#وصف_ڪريو OBM_سائيز 32766
#وصف_ڪريو OBM_OLD_UPARROW 32765
#وصف_ڪريو OBM_OLD_DNARROW 32764
#وصف_ڪريو OBM_OLD_RGARROW 32763
#وصف_ڪريو OBM_OLD_LFARROW 32762
#وصف_ڪريو OBM_BTSIZE 32761
#وصف_ڪريو OBM_CHECK 32760
#وصف_ڪريو OBM_CHECKBOXES 32759
#وصف_ڪريو OBM_BTNCORNERS 32758
#وصف_ڪريو OBM_OLD_REDUCE 32757
#وصف_ڪريو OBM_OLD_ZOOM 32756
#وصف_ڪريو OBM_OLD_RESTORE 32755

#وصف_ڪريو OCR_عام 32512
#وصف_ڪريو OCR_IBEAM 32513
#وصف_ڪريو OCR_WAIT 32514
#وصف_ڪريو OCR_CROSS 32515
#وصف_ڪريو OCR_مٿي 32516
#وصف_ڪريو OCR_سائيز 32640
#وصف_ڪريو OCR_ICON 32641
#وصف_ڪريو OCR_SIZENWSE 32642
#وصف_ڪريو OCR_SIZENESW 32643
#وصف_ڪريو OCR_SIZEWE 32644
#وصف_ڪريو OCR_SIZENS 32645
#وصف_ڪريو OCR_SIZEALL 32646
#وصف_ڪريو OCR_ICOCUR 32647
#وصف_ڪريو OCR_NO 32648
#وصف_ڪريو OCR_HAND 32649
#وصف_ڪريو OCR_APPSTARTING 32650

#وصف_ڪريو OIC_SAMPLE 32512
#وصف_ڪريو OIC_HAND 32513
#وصف_ڪريو OIC_QUES 32514
#وصف_ڪريو OIC_BANG 32515
#وصف_ڪريو OIC_NOTE 32516
#وصف_ڪريو OIC_WINLOGO 32517
#وصف_ڪريو OIC_WARNING OIC_BANG
#وصف_ڪريو OIC_ERROR OIC_HAND
#وصف_ڪريو OIC_INFORMATION OIC_NOTE
#جيڪڏهن_پورو

#وصف_ڪريو ORD_LANGDRIVER 1

#جيڪڏهن_وصف_نه_ٿيل NOICONS

#جيڪڏهن_وصف_ٿيل RC_INVOKED
#وصف_ڪريو IDI_APPLICATION 32512
#وصف_ڪريو IDI_HAND 32513
#وصف_ڪريو IDI_QUESTION 32514
#وصف_ڪريو IDI_EXCLAMATION 32515
#وصف_ڪريو IDI_ASTERISK 32516
#وصف_ڪريو IDI_WINLOGO 32517
#وإلا
#وصف_ڪريو IDI_APPLICATION MAKEINTRESOURCE(32512)
#وصف_ڪريو IDI_HAND MAKEINTRESOURCE(32513)
#وصف_ڪريو IDI_QUESTION MAKEINTRESOURCE(32514)
#وصف_ڪريو IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#وصف_ڪريو IDI_ASTERISK MAKEINTRESOURCE(32516)
#وصف_ڪريو IDI_WINLOGO MAKEINTRESOURCE(32517)
#جيڪڏهن_پورو

#وصف_ڪريو IDI_WARNING IDI_EXCLAMATION
#وصف_ڪريو IDI_ERROR IDI_HAND
#وصف_ڪريو IDI_INFORMATION IDI_ASTERISK
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ڀريو_String ڀريو_String_W
#وإلا
#وصف_ڪريو ڀريو_String ڀريو_String_A
#جيڪڏهن_پورو

  WINUSERAPI صحيح WINAPI ڀريو_String_A(HINSTANCE hInstance,UINT uID,LPSTR lp_بفر,صحيح cch_بفر_Max);
  WINUSERAPI صحيح WINAPI ڀريو_String_W(HINSTANCE hInstance,UINT uID,LPWSTR lp_بفر,صحيح cch_بفر_Max);

#وصف_ڪريو IDOK 1
#وصف_ڪريو IDCANCEL 2
#وصف_ڪريو IDABORT 3
#وصف_ڪريو IDRETRY 4
#وصف_ڪريو IDIGNORE 5
#وصف_ڪريو IDYES 6
#وصف_ڪريو IDNO 7
#وصف_ڪريو IDCLOSE 8
#وصف_ڪريو IDHELP 9
#وصف_ڪريو IDTRYAGAIN 10
#وصف_ڪريو IDCONTINUE 11

#جيڪڏهن_وصف_نه_ٿيل IDTIMEOUT
#وصف_ڪريو IDTIMEOUT 32000
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOCTLMGR

#جيڪڏهن_وصف_نه_ٿيل NOWINSTYLES
#وصف_ڪريو ES_کاٻو 0x0000L
#وصف_ڪريو ES_CENTER 0x0001L
#وصف_ڪريو ES_ساڄو 0x0002L
#وصف_ڪريو ES_MULTILINE 0x0004L
#وصف_ڪريو ES_UPPERCASE 0x0008L
#وصف_ڪريو ES_LOWERCASE 0x0010L
#وصف_ڪريو ES_PASSWORD 0x0020L
#وصف_ڪريو ES_AUTOVSCROLL 0x0040L
#وصف_ڪريو ES_AUTOHSCROLL 0x0080L
#وصف_ڪريو ES_NOHIDESEL 0x0100L
#وصف_ڪريو ES_OEMCONVERT 0x0400L
#وصف_ڪريو ES_READONLY 0x0800L
#وصف_ڪريو ES_WANTRETURN 0x1000L
#وصف_ڪريو ES_عدد 0x2000L
#جيڪڏهن_پورو

#وصف_ڪريو EN_SETFOCUS 0x0100
#وصف_ڪريو EN_KILLFOCUS 0x0200
#وصف_ڪريو EN_CHANGE 0x0300
#وصف_ڪريو EN_UPDATE 0x0400
#وصف_ڪريو EN_ERRSPACE 0x0500
#وصف_ڪريو EN_MAXTEXT 0x0501
#وصف_ڪريو EN_HSCROLL 0x0601
#وصف_ڪريو EN_VSCROLL 0x0602
#وصف_ڪريو EN_ALIGN_LTR_EC 0x0700
#وصف_ڪريو EN_ALIGN_RTL_EC 0x0701

#وصف_ڪريو EC_LEFTMARGIN 0x0001
#وصف_ڪريو EC_RIGHTMARGIN 0x0002
#وصف_ڪريو EC_USEFONTINFO 0xffff

#وصف_ڪريو EMSIS_COMPOSITIONSTRING 0x0001

#وصف_ڪريو EIMES_GETCOMPSTRATONCE 0x0001
#وصف_ڪريو EIMES_CANCELCOMPSTRINFOCUS 0x0002
#وصف_ڪريو EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#جيڪڏهن_وصف_نه_ٿيل NOWINMESSAGES

#وصف_ڪريو EM_GETSEL 0x00B0
#وصف_ڪريو EM_SETSEL 0x00B1
#وصف_ڪريو EM_GETRECT 0x00B2
#وصف_ڪريو EM_SETRECT 0x00B3
#وصف_ڪريو EM_SETRECTNP 0x00B4
#وصف_ڪريو EM_SCROLL 0x00B5
#وصف_ڪريو EM_LINESCROLL 0x00B6
#وصف_ڪريو EM_SCROLLCARET 0x00B7
#وصف_ڪريو EM_GETMODIFY 0x00B8
#وصف_ڪريو EM_SETMODIFY 0x00B9
#وصف_ڪريو EM_GETLINECOUNT 0x00BA
#وصف_ڪريو EM_LINEINDEX 0x00BB
#وصف_ڪريو EM_SETHANDLE 0x00BC
#وصف_ڪريو EM_GETHANDLE 0x00BD
#وصف_ڪريو EM_GETTHUMB 0x00BE
#وصف_ڪريو EM_LINELENGTH 0x00C1
#وصف_ڪريو EM_REPLACESEL 0x00C2
#وصف_ڪريو EM_GETLINE 0x00C4
#وصف_ڪريو EM_LIMITTEXT 0x00C5
#وصف_ڪريو EM_CANUNDO 0x00C6
#وصف_ڪريو EM_UNDO 0x00C7
#وصف_ڪريو EM_FMTLINES 0x00C8
#وصف_ڪريو EM_LINEFROMCHAR 0x00C9
#وصف_ڪريو EM_SETTABSTOPS 0x00CB
#وصف_ڪريو EM_SETPASSWORDCHAR 0x00CC
#وصف_ڪريو EM_EMPTYUNDOBUFFER 0x00CD
#وصف_ڪريو EM_GETFIRSTVISIBLELINE 0x00CE
#وصف_ڪريو EM_SETREADONLY 0x00CF
#وصف_ڪريو EM_SETWORDBREAKPROC 0x00D0
#وصف_ڪريو EM_GETWORDBREAKPROC 0x00D1
#وصف_ڪريو EM_GETPASSWORDCHAR 0x00D2
#وصف_ڪريو EM_SETMARGINS 0x00D3
#وصف_ڪريو EM_GETMARGINS 0x00D4
#وصف_ڪريو EM_SETLIMITTEXT EM_LIMITTEXT
#وصف_ڪريو EM_GETLIMITTEXT 0x00D5
#وصف_ڪريو EM_POSFROMCHAR 0x00D6
#وصف_ڪريو EM_CHARFROMPOS 0x00D7
#وصف_ڪريو EM_SETIMESTATUS 0x00D8
#وصف_ڪريو EM_GETIMESTATUS 0x00D9
#جيڪڏهن_پورو

#وصف_ڪريو WB_کاٻو 0
#وصف_ڪريو WB_ساڄو 1
#وصف_ڪريو WB_ISDELIMITER 2

#وصف_ڪريو BS_PUSHBUTTON 0x00000000L
#وصف_ڪريو BS_DEFPUSHBUTTON 0x00000001L
#وصف_ڪريو BS_CHECKBOX 0x00000002L
#وصف_ڪريو BS_AUTOCHECKBOX 0x00000003L
#وصف_ڪريو BS_RADIOBUTTON 0x00000004L
#وصف_ڪريو BS_3STATE 0x00000005L
#وصف_ڪريو BS_AUTO3STATE 0x00000006L
#وصف_ڪريو BS_GROUPBOX 0x00000007L
#وصف_ڪريو BS_USERBUTTON 0x00000008L
#وصف_ڪريو BS_AUTORADIOBUTTON 0x00000009L
#وصف_ڪريو BS_PUSHBOX 0x0000000AL
#وصف_ڪريو BS_OWNERDRAW 0x0000000BL
#وصف_ڪريو BS_TYPEMASK 0x0000000FL
#وصف_ڪريو BS_LEFTTEXT 0x00000020L
#وصف_ڪريو BS_متن 0x00000000L
#وصف_ڪريو BS_ICON 0x00000040L
#وصف_ڪريو BS_BITMAP 0x00000080L
#وصف_ڪريو BS_کاٻو 0x00000100L
#وصف_ڪريو BS_ساڄو 0x00000200L
#وصف_ڪريو BS_CENTER 0x00000300L
#وصف_ڪريو BS_چوٽي 0x00000400L
#وصف_ڪريو BS_BOTTOM 0x00000800L
#وصف_ڪريو BS_VCENTER 0x00000C00L
#وصف_ڪريو BS_PUSHLIKE 0x00001000L
#وصف_ڪريو BS_MULTILINE 0x00002000L
#وصف_ڪريو BS_NOTIFY 0x00004000L
#وصف_ڪريو BS_FLAT 0x00008000L
#وصف_ڪريو BS_RIGHTBUTTON BS_LEFTTEXT

#وصف_ڪريو BN_CLICKED 0
#وصف_ڪريو BN_PAINT 1
#وصف_ڪريو BN_HILITE 2
#وصف_ڪريو BN_UNHILITE 3
#وصف_ڪريو BN_DISABLE 4
#وصف_ڪريو BN_DOUBLECLICKED 5
#وصف_ڪريو BN_PUSHED BN_HILITE
#وصف_ڪريو BN_UNPUSHED BN_UNHILITE
#وصف_ڪريو BN_DBLCLK BN_DOUBLECLICKED
#وصف_ڪريو BN_SETFOCUS 6
#وصف_ڪريو BN_KILLFOCUS 7

#وصف_ڪريو BM_GETCHECK 0x00F0
#وصف_ڪريو BM_SETCHECK 0x00F1
#وصف_ڪريو BM_GETSTATE 0x00F2
#وصف_ڪريو BM_SETSTATE 0x00F3
#وصف_ڪريو BM_SETSTYLE 0x00F4
#وصف_ڪريو BM_CLICK 0x00F5
#وصف_ڪريو BM_GETIMAGE 0x00F6
#وصف_ڪريو BM_SETIMAGE 0x00F7

#وصف_ڪريو BST_UNCHECKED 0x0000
#وصف_ڪريو BST_CHECKED 0x0001
#وصف_ڪريو BST_INDETERMINATE 0x0002
#وصف_ڪريو BST_PUSHED 0x0004
#وصف_ڪريو BST_FOCUS 0x0008

#وصف_ڪريو SS_کاٻو 0x00000000L
#وصف_ڪريو SS_CENTER 0x00000001L
#وصف_ڪريو SS_ساڄو 0x00000002L
#وصف_ڪريو SS_ICON 0x00000003L
#وصف_ڪريو SS_BLACKRECT 0x00000004L
#وصف_ڪريو SS_GRAYRECT 0x00000005L
#وصف_ڪريو SS_WHITERECT 0x00000006L
#وصف_ڪريو SS_BLACKFRAME 0x00000007L
#وصف_ڪريو SS_GRAYFRAME 0x00000008L
#وصف_ڪريو SS_WHITEFRAME 0x00000009L
#وصف_ڪريو SS_USERITEM 0x0000000AL
#وصف_ڪريو SS_SIMPLE 0x0000000BL
#وصف_ڪريو SS_LEFTNOWORDWRAP 0x0000000CL
#وصف_ڪريو SS_OWNERDRAW 0x0000000DL
#وصف_ڪريو SS_BITMAP 0x0000000EL
#وصف_ڪريو SS_ENHMETAFILE 0x0000000FL
#وصف_ڪريو SS_ETCHEDHORZ 0x00000010L
#وصف_ڪريو SS_ETCHEDVERT 0x00000011L
#وصف_ڪريو SS_ETCHEDFRAME 0x00000012L
#وصف_ڪريو SS_TYPEMASK 0x0000001FL
#وصف_ڪريو SS_REALSIZECONTROL 0x00000040L
#وصف_ڪريو SS_NOPREFIX 0x00000080L
#وصف_ڪريو SS_NOTIFY 0x00000100L
#وصف_ڪريو SS_CENTERIMAGE 0x00000200L
#وصف_ڪريو SS_RIGHTJUST 0x00000400L
#وصف_ڪريو SS_REALSIZEIMAGE 0x00000800L
#وصف_ڪريو SS_SUNKEN 0x00001000L
#وصف_ڪريو SS_EDITCONTROL 0x00002000L
#وصف_ڪريو SS_ENDELLIPSIS 0x00004000L
#وصف_ڪريو SS_PATHELLIPSIS 0x00008000L
#وصف_ڪريو SS_WORDELLIPSIS 0x0000C000L
#وصف_ڪريو SS_ELLIPSISMASK 0x0000C000L

#جيڪڏهن_وصف_نه_ٿيل NOWINMESSAGES

#وصف_ڪريو STM_SETICON 0x0170
#وصف_ڪريو STM_GETICON 0x0171
#وصف_ڪريو STM_SETIMAGE 0x0172
#وصف_ڪريو STM_GETIMAGE 0x0173
#وصف_ڪريو STN_CLICKED 0
#وصف_ڪريو STN_DBLCLK 1
#وصف_ڪريو STN_ENABLE 2
#وصف_ڪريو STN_DISABLE 3
#وصف_ڪريو STM_MSGMAX 0x0174
#جيڪڏهن_پورو

#وصف_ڪريو WC_DIALOG (MAKEINTATOM(0x8002))

#وصف_ڪريو DWL_MSGRESULT 0
#وصف_ڪريو DWL_DLGPROC 4
#وصف_ڪريو DWL_USER 8

#جيڪڏهن_وصف_ٿيل _WIN64

#وصف_رد DWL_MSGRESULT
#وصف_رد DWL_DLGPROC
#وصف_رد DWL_USER
#جيڪڏهن_پورو

#وصف_ڪريو DWLP_MSGRESULT 0
#وصف_ڪريو DWLP_DLGPROC DWLP_MSGRESULT + حجم(LRESULT)
#وصف_ڪريو DWLP_USER DWLP_DLGPROC + حجم(DLGPROC)

#جيڪڏهن_وصف_نه_ٿيل NOMSG

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Is_Dialog_پيغام Is_Dialog_پيغام_W
#وإلا
#وصف_ڪريو Is_Dialog_پيغام Is_Dialog_پيغام_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI Is_Dialog_پيغام_A(HWND hDlg,LPMSG lp_نياپو);
  WINUSERAPI WINBOOL WINAPI Is_Dialog_پيغام_W(HWND hDlg,LPMSG lp_نياپو);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو DlgDirList DlgDirListW
#وصف_ڪريو DlgDirSelectEx DlgDirSelectExW
#وصف_ڪريو DlgDirListComboBox DlgDirListComboBoxW
#وصف_ڪريو DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#وإلا
#وصف_ڪريو DlgDirList DlgDirListA
#وصف_ڪريو DlgDirSelectEx DlgDirSelectExA
#وصف_ڪريو DlgDirListComboBox DlgDirListComboBoxA
#وصف_ڪريو DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI MapDialogRect(HWND hDlg,LPRECT lpRect);
  WINUSERAPI صحيح WINAPI DlgDirListA(HWND hDlg,LPSTR lp_رستو_Spec,صحيح nIDListBox,صحيح n_IDStatic_رستو,UINT uFileType);
  WINUSERAPI صحيح WINAPI DlgDirListW(HWND hDlg,LPWSTR lp_رستو_Spec,صحيح nIDListBox,صحيح n_IDStatic_رستو,UINT uFileType);

#وصف_ڪريو DDL_READWRITE 0x0000
#وصف_ڪريو DDL_READONLY 0x0001
#وصف_ڪريو DDL_HIDDEN 0x0002
#وصف_ڪريو DDL_SYSTEM 0x0004
#وصف_ڪريو DDL_DIRECTORY 0x0010
#وصف_ڪريو DDL_ARCHIVE 0x0020

#وصف_ڪريو DDL_POSTMSGS 0x2000
#وصف_ڪريو DDL_DRIVES 0x4000
#وصف_ڪريو DDL_EXCLUSIVE 0x8000

  WINUSERAPI WINBOOL WINAPI DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,صحيح ch_ڳڻپ,صحيح idListBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,صحيح ch_ڳڻپ,صحيح idListBox);
  WINUSERAPI صحيح WINAPI DlgDirListComboBoxA(HWND hDlg,LPSTR lp_رستو_Spec,صحيح nIDComboBox,صحيح n_IDStatic_رستو,UINT uFiletype);
  WINUSERAPI صحيح WINAPI DlgDirListComboBoxW(HWND hDlg,LPWSTR lp_رستو_Spec,صحيح nIDComboBox,صحيح n_IDStatic_رستو,UINT uFiletype);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,صحيح cch_ٻاهريون,صحيح idComboBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,صحيح cch_ٻاهريون,صحيح idComboBox);

#وصف_ڪريو DS_ABSALIGN 0x01L
#وصف_ڪريو DS_SYSMODAL 0x02L
#وصف_ڪريو DS_LOCALEDIT 0x20L
#وصف_ڪريو DS_SETFONT 0x40L
#وصف_ڪريو DS_MODALFRAME 0x80L
#وصف_ڪريو DS_NOIDLEMSG 0x100L
#وصف_ڪريو DS_SETFOREGROUND 0x200L

#وصف_ڪريو DS_3DLOOK 0x0004L
#وصف_ڪريو DS_FIXEDSYS 0x0008L
#وصف_ڪريو DS_NOFAILCREATE 0x0010L
#وصف_ڪريو DS_CONTROL 0x0400L
#وصف_ڪريو DS_CENTER 0x0800L
#وصف_ڪريو DS_CENTERMOUSE 0x1000L
#وصف_ڪريو DS_CONTEXTHELP 0x2000L

#وصف_ڪريو DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#إذا(_WIN32_WCE >= 0x0500)
#وصف_ڪريو DS_USEPIXELS 0x8000L
#جيڪڏهن_پورو

#وصف_ڪريو DM_GETDEFID (WM_USER+0)
#وصف_ڪريو DM_SETDEFID (WM_USER+1)
#وصف_ڪريو DM_REPOSITION (WM_USER+2)

#وصف_ڪريو DC_HASDEFID 0x534B

#وصف_ڪريو DLGC_WANTARROWS 0x0001
#وصف_ڪريو DLGC_WANTTAB 0x0002
#وصف_ڪريو DLGC_WANTALLKEYS 0x0004
#وصف_ڪريو DLGC_WANTMESSAGE 0x0004
#وصف_ڪريو DLGC_HASSETSEL 0x0008
#وصف_ڪريو DLGC_DEFPUSHBUTTON 0x0010
#وصف_ڪريو DLGC_UNDEFPUSHBUTTON 0x0020
#وصف_ڪريو DLGC_RADIOBUTTON 0x0040
#وصف_ڪريو DLGC_WANTCHARS 0x0080
#وصف_ڪريو DLGC_STATIC 0x0100
#وصف_ڪريو DLGC_BUTTON 0x2000

#وصف_ڪريو LB_CTLCODE 0L

#وصف_ڪريو LB_OKAY 0
#وصف_ڪريو LB_ERR (-1)
#وصف_ڪريو LB_ERRSPACE (-2)

#وصف_ڪريو LBN_ERRSPACE (-2)
#وصف_ڪريو LBN_SELCHANGE 1
#وصف_ڪريو LBN_DBLCLK 2
#وصف_ڪريو LBN_SELCANCEL 3
#وصف_ڪريو LBN_SETFOCUS 4
#وصف_ڪريو LBN_KILLFOCUS 5

#جيڪڏهن_وصف_نه_ٿيل NOWINMESSAGES

#وصف_ڪريو LB_ADDSTRING 0x0180
#وصف_ڪريو LB_INSERTSTRING 0x0181
#وصف_ڪريو LB_DELETESTRING 0x0182
#وصف_ڪريو LB_SELITEMRANGEEX 0x0183
#وصف_ڪريو LB_RESETCONTENT 0x0184
#وصف_ڪريو LB_SETSEL 0x0185
#وصف_ڪريو LB_SETCURSEL 0x0186
#وصف_ڪريو LB_GETSEL 0x0187
#وصف_ڪريو LB_GETCURSEL 0x0188
#وصف_ڪريو LB_GETTEXT 0x0189
#وصف_ڪريو LB_GETTEXTLEN 0x018A
#وصف_ڪريو LB_GETCOUNT 0x018B
#وصف_ڪريو LB_SELECTSTRING 0x018C
#وصف_ڪريو LB_DIR 0x018D
#وصف_ڪريو LB_GETTOPINDEX 0x018E
#وصف_ڪريو LB_FINDSTRING 0x018F
#وصف_ڪريو LB_GETSELCOUNT 0x0190
#وصف_ڪريو LB_GETSELITEMS 0x0191
#وصف_ڪريو LB_SETTABSTOPS 0x0192
#وصف_ڪريو LB_GETHORIZONTALEXTENT 0x0193
#وصف_ڪريو LB_SETHORIZONTALEXTENT 0x0194
#وصف_ڪريو LB_SETCOLUMNWIDTH 0x0195
#وصف_ڪريو LB_ADDFILE 0x0196
#وصف_ڪريو LB_SETTOPINDEX 0x0197
#وصف_ڪريو LB_GETITEMRECT 0x0198
#وصف_ڪريو LB_GETITEMDATA 0x0199
#وصف_ڪريو LB_SETITEMDATA 0x019A
#وصف_ڪريو LB_SELITEMRANGE 0x019B
#وصف_ڪريو LB_SETANCHORINDEX 0x019C
#وصف_ڪريو LB_GETANCHORINDEX 0x019D
#وصف_ڪريو LB_SETCARETINDEX 0x019E
#وصف_ڪريو LB_GETCARETINDEX 0x019F
#وصف_ڪريو LB_SETITEMHEIGHT 0x01A0
#وصف_ڪريو LB_GETITEMHEIGHT 0x01A1
#وصف_ڪريو LB_FINDSTRINGEXACT 0x01A2
#وصف_ڪريو LB_SETLOCALE 0x01A5
#وصف_ڪريو LB_GETLOCALE 0x01A6
#وصف_ڪريو LB_SETCOUNT 0x01A7
#وصف_ڪريو LB_INITSTORAGE 0x01A8
#وصف_ڪريو LB_ITEMFROMPOINT 0x01A9
#إذا(_WIN32_WCE >= 0x0400)
#وصف_ڪريو LB_MULTIPLEADDSTRING 0x01B1
#جيڪڏهن_پورو
#وصف_ڪريو LB_GETLISTBOXINFO 0x01B2
#وصف_ڪريو LB_MSGMAX 0x01B3
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOWINSTYLES

#وصف_ڪريو LBS_NOTIFY 0x0001L
#وصف_ڪريو LBS_ترتيب_ڏيو 0x0002L
#وصف_ڪريو LBS_NOREDRAW 0x0004L
#وصف_ڪريو LBS_MULTIPLESEL 0x0008L
#وصف_ڪريو LBS_OWNERDRAWFIXED 0x0010L
#وصف_ڪريو LBS_OWNERDRAWVARIABLE 0x0020L
#وصف_ڪريو LBS_HASSTRINGS 0x0040L
#وصف_ڪريو LBS_USETABSTOPS 0x0080L
#وصف_ڪريو LBS_NOINTEGRALHEIGHT 0x0100L
#وصف_ڪريو LBS_MULTICOLUMN 0x0200L
#وصف_ڪريو LBS_WANTKEYBOARDINPUT 0x0400L
#وصف_ڪريو LBS_EXTENDEDSEL 0x0800L
#وصف_ڪريو LBS_DISABLENOSCROLL 0x1000L
#وصف_ڪريو LBS_NODATA 0x2000L
#وصف_ڪريو LBS_NOSEL 0x4000L
#وصف_ڪريو LBS_COMBOBOX 0x8000L

#وصف_ڪريو LBS_STANDARD (LBS_NOTIFY | LBS_ترتيب_ڏيو | WS_VSCROLL | WS_BORDER)
#جيڪڏهن_پورو

#وصف_ڪريو CB_OKAY 0
#وصف_ڪريو CB_ERR (-1)
#وصف_ڪريو CB_ERRSPACE (-2)

#وصف_ڪريو CBN_ERRSPACE (-1)
#وصف_ڪريو CBN_SELCHANGE 1
#وصف_ڪريو CBN_DBLCLK 2
#وصف_ڪريو CBN_SETFOCUS 3
#وصف_ڪريو CBN_KILLFOCUS 4
#وصف_ڪريو CBN_EDITCHANGE 5
#وصف_ڪريو CBN_EDITUPDATE 6
#وصف_ڪريو CBN_DROPDOWN 7
#وصف_ڪريو CBN_CLOSEUP 8
#وصف_ڪريو CBN_SELENDOK 9
#وصف_ڪريو CBN_SELENDCANCEL 10

#جيڪڏهن_وصف_نه_ٿيل NOWINSTYLES

#وصف_ڪريو CBS_SIMPLE 0x0001L
#وصف_ڪريو CBS_DROPDOWN 0x0002L
#وصف_ڪريو CBS_DROPDOWNLIST 0x0003L
#وصف_ڪريو CBS_OWNERDRAWFIXED 0x0010L
#وصف_ڪريو CBS_OWNERDRAWVARIABLE 0x0020L
#وصف_ڪريو CBS_AUTOHSCROLL 0x0040L
#وصف_ڪريو CBS_OEMCONVERT 0x0080L
#وصف_ڪريو CBS_ترتيب_ڏيو 0x0100L
#وصف_ڪريو CBS_HASSTRINGS 0x0200L
#وصف_ڪريو CBS_NOINTEGRALHEIGHT 0x0400L
#وصف_ڪريو CBS_DISABLENOSCROLL 0x0800L
#وصف_ڪريو CBS_UPPERCASE 0x2000L
#وصف_ڪريو CBS_LOWERCASE 0x4000L
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOWINMESSAGES
#وصف_ڪريو CB_GETEDITSEL 0x0140
#وصف_ڪريو CB_LIMITTEXT 0x0141
#وصف_ڪريو CB_SETEDITSEL 0x0142
#وصف_ڪريو CB_ADDSTRING 0x0143
#وصف_ڪريو CB_DELETESTRING 0x0144
#وصف_ڪريو CB_DIR 0x0145
#وصف_ڪريو CB_GETCOUNT 0x0146
#وصف_ڪريو CB_GETCURSEL 0x0147
#وصف_ڪريو CB_GETLBTEXT 0x0148
#وصف_ڪريو CB_GETLBTEXTLEN 0x0149
#وصف_ڪريو CB_INSERTSTRING 0x014A
#وصف_ڪريو CB_RESETCONTENT 0x014B
#وصف_ڪريو CB_FINDSTRING 0x014C
#وصف_ڪريو CB_SELECTSTRING 0x014D
#وصف_ڪريو CB_SETCURSEL 0x014E
#وصف_ڪريو CB_SHOWDROPDOWN 0x014F
#وصف_ڪريو CB_GETITEMDATA 0x0150
#وصف_ڪريو CB_SETITEMDATA 0x0151
#وصف_ڪريو CB_GETDROPPEDCONTROLRECT 0x0152
#وصف_ڪريو CB_SETITEMHEIGHT 0x0153
#وصف_ڪريو CB_GETITEMHEIGHT 0x0154
#وصف_ڪريو CB_SETEXTENDEDUI 0x0155
#وصف_ڪريو CB_GETEXTENDEDUI 0x0156
#وصف_ڪريو CB_GETDROPPEDSTATE 0x0157
#وصف_ڪريو CB_FINDSTRINGEXACT 0x0158
#وصف_ڪريو CB_SETLOCALE 0x0159
#وصف_ڪريو CB_GETLOCALE 0x015A
#وصف_ڪريو CB_GETTOPINDEX 0x015b
#وصف_ڪريو CB_SETTOPINDEX 0x015c
#وصف_ڪريو CB_GETHORIZONTALEXTENT 0x015d
#وصف_ڪريو CB_SETHORIZONTALEXTENT 0x015e
#وصف_ڪريو CB_GETDROPPEDWIDTH 0x015f
#وصف_ڪريو CB_SETDROPPEDWIDTH 0x0160
#وصف_ڪريو CB_INITSTORAGE 0x0161
#إذا(_WIN32_WCE >= 0x0400)
#وصف_ڪريو CB_MULTIPLEADDSTRING 0x0163
#جيڪڏهن_پورو
#وصف_ڪريو CB_GETCOMBOBOXINFO 0x0164
#وصف_ڪريو CB_MSGMAX 0x0165
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOWINSTYLES

#وصف_ڪريو SBS_HORZ 0x0000L
#وصف_ڪريو SBS_VERT 0x0001L
#وصف_ڪريو SBS_TOPALIGN 0x0002L
#وصف_ڪريو SBS_LEFTALIGN 0x0002L
#وصف_ڪريو SBS_BOTTOMALIGN 0x0004L
#وصف_ڪريو SBS_RIGHTALIGN 0x0004L
#وصف_ڪريو SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#وصف_ڪريو SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#وصف_ڪريو SBS_SIZEBOX 0x0008L
#وصف_ڪريو SBS_SIZEGRIP 0x0010L
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOWINMESSAGES
#وصف_ڪريو SBM_SETPOS 0x00E0
#وصف_ڪريو SBM_GETPOS 0x00E1
#وصف_ڪريو SBM_SETRANGE 0x00E2
#وصف_ڪريو SBM_SETRANGEREDRAW 0x00E6
#وصف_ڪريو SBM_GETRANGE 0x00E3
#وصف_ڪريو SBM_ENABLE_ARROWS 0x00E4
#وصف_ڪريو SBM_SETSCROLLINFO 0x00E9
#وصف_ڪريو SBM_GETSCROLLINFO 0x00EA
#وصف_ڪريو SBM_GETSCROLLBARINFO 0x00EB

#وصف_ڪريو SIF_RANGE 0x0001
#وصف_ڪريو SIF_صفحو 0x0002
#وصف_ڪريو SIF_POS 0x0004
#وصف_ڪريو SIF_DISABLENOSCROLL 0x0008
#وصف_ڪريو SIF_TRACKPOS 0x0010
#وصف_ڪريو SIF_ALL (SIF_RANGE | SIF_صفحو | SIF_POS | SIF_TRACKPOS)

  تعريفنوع بنية ٽيگ_SCROLLINFO {
    UINT cb_سائيز;
    UINT f_نقاب;
    صحيح nMin;
    صحيح nMax;
    UINT n_صفحو;
    صحيح nPos;
    صحيح nTrackPos;
  } SCROLLINFO,*LPSCROLLINFO;
  تعريفنوع SCROLLINFO CONST *LPCSCROLLINFO;

  WINUSERAPI صحيح WINAPI سيٽ_Scroll_Info(HWND hwnd,صحيح nBar,LPCSCROLLINFO lpsi,WINBOOL redraw);
  WINUSERAPI WINBOOL WINAPI GetScrollInfo(HWND hwnd,صحيح nBar,LPSCROLLINFO lpsi);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOMDI

#وصف_ڪريو MDIS_ALLCHILDSTYLES 0x0001

#وصف_ڪريو MDITILE_VERTICAL 0x0000
#وصف_ڪريو MDITILE_HORIZONTAL 0x0001
#وصف_ڪريو MDITILE_SKIPDISABLED 0x0002
#وصف_ڪريو MDITILE_ZORDER 0x0004

  تعريفنوع بنية ٽيگ_MDICREATESTRUCTA {
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

  تعريفنوع بنية ٽيگ_MDICREATESTRUCTW {
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

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع MDICREATESTRUCTW MDICREATESTRUCT;
  تعريفنوع LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#وإلا
  تعريفنوع MDICREATESTRUCTA MDICREATESTRUCT;
  تعريفنوع LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_CLIENTCREATESTRUCT {
    HANDLE h_دري_Menu;
    UINT id_پهريون_ٻار;
  } CLIENTCREATESTRUCT,*LPCLIENTCREATESTRUCT;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Def_چوکٺو_Proc Def_چوکٺو_Proc_W
#وصف_ڪريو DefMDIChildProc DefMDIChildProcW
#وصف_ڪريو CreateMDIWindow CreateMDIWindowW
#وإلا
#وصف_ڪريو Def_چوکٺو_Proc Def_چوکٺو_Proc_A
#وصف_ڪريو DefMDIChildProc DefMDIChildProcA
#وصف_ڪريو CreateMDIWindow CreateMDIWindowA
#جيڪڏهن_پورو

  WINUSERAPI LRESULT WINAPI Def_چوکٺو_Proc_A(HWND hWnd,HWND hWndMDIClient,UINT u_نياپو,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_چوکٺو_Proc_W(HWND hWnd,HWND hWndMDIClient,UINT u_نياپو,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcA(HWND hWnd,UINT u_نياپو,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcW(HWND hWnd,UINT u_نياپو,WPARAM wParam,LPARAM lParam);

#جيڪڏهن_وصف_نه_ٿيل NOMSG
  WINUSERAPI WINBOOL WINAPI TranslateMDISysAccel(HWND hWndClient,LPMSG lp_نياپو);
#جيڪڏهن_پورو

  WINUSERAPI UINT WINAPI ArrangeIconicWindows(HWND hWnd);
  WINUSERAPI HWND WINAPI CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lp_دري_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_ويڪر,صحيح n_اوچائي,HWND h_Wnd_والد,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI HWND WINAPI CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lp_دري_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_ويڪر,صحيح n_اوچائي,HWND h_Wnd_والد,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI لفظ_3 WINAPI TileWindows(HWND hwnd_والد_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ثابت HWND *lpKids);
  WINUSERAPI لفظ_3 WINAPI CascadeWindows(HWND hwnd_والد_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ثابت HWND *lpKids);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOHELP

  تعريفنوع DWORD HELPPOLY;
  تعريفنوع بنية ٽيگ_MULTIKEYHELPA {
    DWORD mk_سائيز;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
  } MULTIKEYHELPA,*PMULTIKEYHELPA,*LPMULTIKEYHELPA;

  تعريفنوع بنية ٽيگ_MULTIKEYHELPW {
    DWORD mk_سائيز;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
  } MULTIKEYHELPW,*PMULTIKEYHELPW,*LPMULTIKEYHELPW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع MULTIKEYHELPW MULTIKEYHELP;
  تعريفنوع PMULTIKEYHELPW PMULTIKEYHELP;
  تعريفنوع LPMULTIKEYHELPW LPMULTIKEYHELP;
#وإلا
  تعريفنوع MULTIKEYHELPA MULTIKEYHELP;
  تعريفنوع PMULTIKEYHELPA PMULTIKEYHELP;
  تعريفنوع LPMULTIKEYHELPA LPMULTIKEYHELP;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_HELPWININFOA {
    صحيح w_Struct_سائيز;
    صحيح x;
    صحيح y;
    صحيح dx;
    صحيح dy;
    صحيح wMax;
    CHAR rgchMember[2];
  } HELPWININFOA,*PHELPWININFOA,*LPHELPWININFOA;

  تعريفنوع بنية ٽيگ_HELPWININFOW {
    صحيح w_Struct_سائيز;
    صحيح x;
    صحيح y;
    صحيح dx;
    صحيح dy;
    صحيح wMax;
    WCHAR rgchMember[2];
  } HELPWININFOW,*PHELPWININFOW,*LPHELPWININFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع HELPWININFOW HELPWININFO;
  تعريفنوع PHELPWININFOW PHELPWININFO;
  تعريفنوع LPHELPWININFOW LPHELPWININFO;
#وإلا
  تعريفنوع HELPWININFOA HELPWININFO;
  تعريفنوع PHELPWININFOA PHELPWININFO;
  تعريفنوع LPHELPWININFOA LPHELPWININFO;
#جيڪڏهن_پورو

#وصف_ڪريو HELP_CONTEXT 0x0001L
#وصف_ڪريو HELP_QUIT 0x0002L
#وصف_ڪريو HELP_اشاريو 0x0003L
#وصف_ڪريو HELP_CONTENTS 0x0003L
#وصف_ڪريو HELP_HELPONHELP 0x0004L
#وصف_ڪريو HELP_SETINDEX 0x0005L
#وصف_ڪريو HELP_SETCONTENTS 0x0005L
#وصف_ڪريو HELP_CONTEXTPOPUP 0x0008L
#وصف_ڪريو HELP_FORCEFILE 0x0009L
#وصف_ڪريو HELP_ڪنجي 0x0101L
#وصف_ڪريو HELP_COMMAND 0x0102L
#وصف_ڪريو HELP_PARTIALKEY 0x0105L
#وصف_ڪريو HELP_MULTIKEY 0x0201L
#وصف_ڪريو HELP_SETWINPOS 0x0203L
#وصف_ڪريو HELP_CONTEXTMENU 0x000a
#وصف_ڪريو HELP_FINDER 0x000b
#وصف_ڪريو HELP_WM_HELP 0x000c
#وصف_ڪريو HELP_SETPOPUP_POS 0x000d

#وصف_ڪريو HELP_TCARD 0x8000
#وصف_ڪريو HELP_TCARD_معلومات 0x0010
#وصف_ڪريو HELP_TCARD_OTHER_CALLER 0x0011

#وصف_ڪريو IDH_NO_HELP 28440
#وصف_ڪريو IDH_MISSING_CONTEXT 28441
#وصف_ڪريو IDH_GENERIC_HELP_BUTTON 28442
#وصف_ڪريو IDH_OK 28443
#وصف_ڪريو IDH_CANCEL 28444
#وصف_ڪريو IDH_HELP 28445

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو WinHelp WinHelpW
#وإلا
#وصف_ڪريو WinHelp WinHelpA
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dw_معلومات);
  WINUSERAPI WINBOOL WINAPI WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dw_معلومات);
#جيڪڏهن_پورو

#وصف_ڪريو GR_GDIOBJECTS 0
#وصف_ڪريو GR_USEROBJECTS 1

  WINUSERAPI DWORD WINAPI GetGuiResources(HANDLE hProcess,DWORD uiFlags);

#جيڪڏهن_وصف_نه_ٿيل NOSYSPARAMSINFO

#وصف_ڪريو SPI_GETBEEP 0x0001
#وصف_ڪريو SPI_SETBEEP 0x0002
#وصف_ڪريو SPI_GETMOUSE 0x0003
#وصف_ڪريو SPI_SETMOUSE 0x0004
#وصف_ڪريو SPI_GETBORDER 0x0005
#وصف_ڪريو SPI_SETBORDER 0x0006
#وصف_ڪريو SPI_GETKEYBOARDSPEED 0x000A
#وصف_ڪريو SPI_SETKEYBOARDSPEED 0x000B
#وصف_ڪريو SPI_LANGDRIVER 0x000C
#وصف_ڪريو SPI_ICONHORIZONTALSPACING 0x000D
#وصف_ڪريو SPI_GETSCREENSAVETIMEOUT 0x000E
#وصف_ڪريو SPI_SETSCREENSAVETIMEOUT 0x000F
#وصف_ڪريو SPI_GETSCREENSAVEACTIVE 0x0010
#وصف_ڪريو SPI_SETSCREENSAVEACTIVE 0x0011
#وصف_ڪريو SPI_GETGRIDGRANULARITY 0x0012
#وصف_ڪريو SPI_SETGRIDGRANULARITY 0x0013
#وصف_ڪريو SPI_SETDESKWALLPAPER 0x0014
#وصف_ڪريو SPI_SETDESKPATTERN 0x0015
#وصف_ڪريو SPI_GETKEYBOARDDELAY 0x0016
#وصف_ڪريو SPI_SETKEYBOARDDELAY 0x0017
#وصف_ڪريو SPI_ICONVERTICALSPACING 0x0018
#وصف_ڪريو SPI_GETICONTITLEWRAP 0x0019
#وصف_ڪريو SPI_SETICONTITLEWRAP 0x001A
#وصف_ڪريو SPI_GETMENUDROPALIGNMENT 0x001B
#وصف_ڪريو SPI_SETMENUDROPALIGNMENT 0x001C
#وصف_ڪريو SPI_SETDOUBLECLKWIDTH 0x001D
#وصف_ڪريو SPI_SETDOUBLECLKHEIGHT 0x001E
#وصف_ڪريو SPI_GETICONTITLELOGFONT 0x001F
#وصف_ڪريو SPI_SETDOUBLECLICKTIME 0x0020
#وصف_ڪريو SPI_SETMOUSEBUTTONSWAP 0x0021
#وصف_ڪريو SPI_SETICONTITLELOGFONT 0x0022
#وصف_ڪريو SPI_GETFASTTASKSWITCH 0x0023
#وصف_ڪريو SPI_SETFASTTASKSWITCH 0x0024
#وصف_ڪريو SPI_SETDRAGFULLWINDOWS 0x0025
#وصف_ڪريو SPI_GETDRAGFULLWINDOWS 0x0026
#وصف_ڪريو SPI_GETNONCLIENTMETRICS 0x0029
#وصف_ڪريو SPI_SETNONCLIENTMETRICS 0x002A
#وصف_ڪريو SPI_GETMINIMIZEDMETRICS 0x002B
#وصف_ڪريو SPI_SETMINIMIZEDMETRICS 0x002C
#وصف_ڪريو SPI_GETICONMETRICS 0x002D
#وصف_ڪريو SPI_SETICONMETRICS 0x002E
#وصف_ڪريو SPI_SETWORKAREA 0x002F
#وصف_ڪريو SPI_GETWORKAREA 0x0030
#وصف_ڪريو SPI_SETPENWINDOWS 0x0031

#وصف_ڪريو SPI_GETHIGHCONTRAST 0x0042
#وصف_ڪريو SPI_SETHIGHCONTRAST 0x0043
#وصف_ڪريو SPI_GETKEYBOARDPREF 0x0044
#وصف_ڪريو SPI_SETKEYBOARDPREF 0x0045
#وصف_ڪريو SPI_GETSCREENREADER 0x0046
#وصف_ڪريو SPI_SETSCREENREADER 0x0047
#وصف_ڪريو SPI_GETANIMATION 0x0048
#وصف_ڪريو SPI_SETANIMATION 0x0049
#وصف_ڪريو SPI_GETFONTSMOOTHING 0x004A
#وصف_ڪريو SPI_SETFONTSMOOTHING 0x004B
#وصف_ڪريو SPI_SETDRAGWIDTH 0x004C
#وصف_ڪريو SPI_SETDRAGHEIGHT 0x004D
#وصف_ڪريو SPI_SETHANDHELD 0x004E
#وصف_ڪريو SPI_GETLOWPOWERTIMEOUT 0x004F
#وصف_ڪريو SPI_GETPOWEROFFTIMEOUT 0x0050
#وصف_ڪريو SPI_SETLOWPOWERTIMEOUT 0x0051
#وصف_ڪريو SPI_SETPOWEROFFTIMEOUT 0x0052
#وصف_ڪريو SPI_GETLOWPOWERACTIVE 0x0053
#وصف_ڪريو SPI_GETPOWEROFFACTIVE 0x0054
#وصف_ڪريو SPI_SETLOWPOWERACTIVE 0x0055
#وصف_ڪريو SPI_SETPOWEROFFACTIVE 0x0056
#وصف_ڪريو SPI_SETCURSORS 0x0057
#وصف_ڪريو SPI_SETICONS 0x0058
#وصف_ڪريو SPI_GETDEFAULTINPUTLANG 0x0059
#وصف_ڪريو SPI_SETDEFAULTINPUTLANG 0x005A
#وصف_ڪريو SPI_SETLANGTOGGLE 0x005B
#وصف_ڪريو SPI_GETWINDOWSEXTENSION 0x005C
#وصف_ڪريو SPI_SETMOUSETRAILS 0x005D
#وصف_ڪريو SPI_GETMOUSETRAILS 0x005E
#وصف_ڪريو SPI_SETSCREENSAVERRUNNING 0x0061
#وصف_ڪريو SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#وصف_ڪريو SPI_GETFILTERKEYS 0x0032
#وصف_ڪريو SPI_SETFILTERKEYS 0x0033
#وصف_ڪريو SPI_GETTOGGLEKEYS 0x0034
#وصف_ڪريو SPI_SETTOGGLEKEYS 0x0035
#وصف_ڪريو SPI_GETMOUSEKEYS 0x0036
#وصف_ڪريو SPI_SETMOUSEKEYS 0x0037
#وصف_ڪريو SPI_GETSHOWSOUNDS 0x0038
#وصف_ڪريو SPI_SETSHOWSOUNDS 0x0039
#وصف_ڪريو SPI_GETSTICKYKEYS 0x003A
#وصف_ڪريو SPI_SETSTICKYKEYS 0x003B
#وصف_ڪريو SPI_GETACCESSTIMEOUT 0x003C
#وصف_ڪريو SPI_SETACCESSTIMEOUT 0x003D
#وصف_ڪريو SPI_GETSERIALKEYS 0x003E
#وصف_ڪريو SPI_SETSERIALKEYS 0x003F
#وصف_ڪريو SPI_GETSOUNDSENTRY 0x0040
#وصف_ڪريو SPI_SETSOUNDSENTRY 0x0041
#وصف_ڪريو SPI_GETSNAPTODEFBUTTON 0x005F
#وصف_ڪريو SPI_SETSNAPTODEFBUTTON 0x0060
#وصف_ڪريو SPI_GETMOUSEHOVERWIDTH 0x0062
#وصف_ڪريو SPI_SETMOUSEHOVERWIDTH 0x0063
#وصف_ڪريو SPI_GETMOUSEHOVERHEIGHT 0x0064
#وصف_ڪريو SPI_SETMOUSEHOVERHEIGHT 0x0065
#وصف_ڪريو SPI_GETMOUSEHOVERTIME 0x0066
#وصف_ڪريو SPI_SETMOUSEHOVERTIME 0x0067
#وصف_ڪريو SPI_GETWHEELSCROLLLINES 0x0068
#وصف_ڪريو SPI_SETWHEELSCROLLLINES 0x0069
#وصف_ڪريو SPI_GETMENUSHOWDELAY 0x006A
#وصف_ڪريو SPI_SETMENUSHOWDELAY 0x006B
#وصف_ڪريو SPI_GETSHOWIMEUI 0x006E
#وصف_ڪريو SPI_SETSHOWIMEUI 0x006F
#وصف_ڪريو SPI_GETMOUSESPEED 0x0070
#وصف_ڪريو SPI_SETMOUSESPEED 0x0071
#وصف_ڪريو SPI_GETSCREENSAVERRUNNING 0x0072
#وصف_ڪريو SPI_GETDESKWALLPAPER 0x0073

#وصف_ڪريو SPI_GETACTIVEWINDOWTRACKING 0x1000
#وصف_ڪريو SPI_SETACTIVEWINDOWTRACKING 0x1001
#وصف_ڪريو SPI_GETMENUANIMATION 0x1002
#وصف_ڪريو SPI_SETMENUANIMATION 0x1003
#وصف_ڪريو SPI_GETCOMBOBOXANIMATION 0x1004
#وصف_ڪريو SPI_SETCOMBOBOXANIMATION 0x1005
#وصف_ڪريو SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#وصف_ڪريو SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#وصف_ڪريو SPI_GETGRADIENTCAPTIONS 0x1008
#وصف_ڪريو SPI_SETGRADIENTCAPTIONS 0x1009
#وصف_ڪريو SPI_GETKEYBOARDCUES 0x100A
#وصف_ڪريو SPI_SETKEYBOARDCUES 0x100B
#وصف_ڪريو SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#وصف_ڪريو SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#وصف_ڪريو SPI_GETACTIVEWNDTRKZORDER 0x100C
#وصف_ڪريو SPI_SETACTIVEWNDTRKZORDER 0x100D
#وصف_ڪريو SPI_GETHOTTRACKING 0x100E
#وصف_ڪريو SPI_SETHOTTRACKING 0x100F
#وصف_ڪريو SPI_GETMENUFADE 0x1012
#وصف_ڪريو SPI_SETMENUFADE 0x1013
#وصف_ڪريو SPI_GETSELECTIONFADE 0x1014
#وصف_ڪريو SPI_SETSELECTIONFADE 0x1015
#وصف_ڪريو SPI_GETTOOLTIPANIMATION 0x1016
#وصف_ڪريو SPI_SETTOOLTIPANIMATION 0x1017
#وصف_ڪريو SPI_GETTOOLTIPFADE 0x1018
#وصف_ڪريو SPI_SETTOOLTIPFADE 0x1019
#وصف_ڪريو SPI_GETCURSORSHADOW 0x101A
#وصف_ڪريو SPI_SETCURSORSHADOW 0x101B
#وصف_ڪريو SPI_GETMOUSESONAR 0x101C
#وصف_ڪريو SPI_SETMOUSESONAR 0x101D
#وصف_ڪريو SPI_GETMOUSECLICKLOCK 0x101E
#وصف_ڪريو SPI_SETMOUSECLICKLOCK 0x101F
#وصف_ڪريو SPI_GETMOUSEVANISH 0x1020
#وصف_ڪريو SPI_SETMOUSEVANISH 0x1021
#وصف_ڪريو SPI_GETFLATMENU 0x1022
#وصف_ڪريو SPI_SETFLATMENU 0x1023
#وصف_ڪريو SPI_GETDROPSHADOW 0x1024
#وصف_ڪريو SPI_SETDROPSHADOW 0x1025
#وصف_ڪريو SPI_GETBLOCKSENDINPUTRESETS 0x1026
#وصف_ڪريو SPI_SETBLOCKSENDINPUTRESETS 0x1027
#وصف_ڪريو SPI_GETUIEFFECTS 0x103E
#وصف_ڪريو SPI_SETUIEFFECTS 0x103F
#وصف_ڪريو SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#وصف_ڪريو SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#وصف_ڪريو SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#وصف_ڪريو SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#وصف_ڪريو SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#وصف_ڪريو SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#وصف_ڪريو SPI_GETCARETWIDTH 0x2006
#وصف_ڪريو SPI_SETCARETWIDTH 0x2007
#وصف_ڪريو SPI_GETMOUSECLICKLOCKTIME 0x2008
#وصف_ڪريو SPI_SETMOUSECLICKLOCKTIME 0x2009
#وصف_ڪريو SPI_GETFONTSMOOTHINGTYPE 0x200A
#وصف_ڪريو SPI_SETFONTSMOOTHINGTYPE 0x200B

#وصف_ڪريو FE_FONTSMOOTHINGSTANDARD 0x0001
#وصف_ڪريو FE_FONTSMOOTHINGCLEARTYPE 0x0002
#وصف_ڪريو FE_FONTSMOOTHINGDOCKING 0x8000

#وصف_ڪريو SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#وصف_ڪريو SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#وصف_ڪريو SPI_GETFOCUSBORDERWIDTH 0x200E
#وصف_ڪريو SPI_SETFOCUSBORDERWIDTH 0x200F
#وصف_ڪريو SPI_GETFOCUSBORDERHEIGHT 0x2010
#وصف_ڪريو SPI_SETFOCUSBORDERHEIGHT 0x2011
#وصف_ڪريو SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#وصف_ڪريو SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#وصف_ڪريو FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#وصف_ڪريو FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#وصف_ڪريو SPIF_UPDATEINIFILE 0x0001
#وصف_ڪريو SPIF_SENDWININICHANGE 0x0002
#وصف_ڪريو SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#وصف_ڪريو METRICS_USEDEFAULT -1
#جيڪڏهن_وصف_ٿيل _WINGDI_
#جيڪڏهن_وصف_نه_ٿيل NOGDI
  تعريفنوع بنية ٽيگ_NONCLIENTMETRICSA {
    UINT cb_سائيز;
    صحيح i_Border_ويڪر;
    صحيح i_Scroll_ويڪر;
    صحيح i_Scroll_اوچائي;
    صحيح i_Caption_ويڪر;
    صحيح i_Caption_اوچائي;
    LOGFONTA lfCaptionFont;
    صحيح i_Sm_Caption_ويڪر;
    صحيح i_Sm_Caption_اوچائي;
    LOGFONTA lfSmCaptionFont;
    صحيح i_Menu_ويڪر;
    صحيح i_Menu_اوچائي;
    LOGFONTA lfMenuFont;
    LOGFONTA lf_حالت_Font;
    LOGFONTA lf_پيغام_Font;
  } NONCLIENTMETRICSA,*PNONCLIENTMETRICSA,*LPNONCLIENTMETRICSA;

  تعريفنوع بنية ٽيگ_NONCLIENTMETRICSW {
    UINT cb_سائيز;
    صحيح i_Border_ويڪر;
    صحيح i_Scroll_ويڪر;
    صحيح i_Scroll_اوچائي;
    صحيح i_Caption_ويڪر;
    صحيح i_Caption_اوچائي;
    LOGFONTW lfCaptionFont;
    صحيح i_Sm_Caption_ويڪر;
    صحيح i_Sm_Caption_اوچائي;
    LOGFONTW lfSmCaptionFont;
    صحيح i_Menu_ويڪر;
    صحيح i_Menu_اوچائي;
    LOGFONTW lfMenuFont;
    LOGFONTW lf_حالت_Font;
    LOGFONTW lf_پيغام_Font;
  } NONCLIENTMETRICSW,*PNONCLIENTMETRICSW,*LPNONCLIENTMETRICSW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع NONCLIENTMETRICSW NONCLIENTMETRICS;
  تعريفنوع PNONCLIENTMETRICSW PNONCLIENTMETRICS;
  تعريفنوع LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#وإلا
  تعريفنوع NONCLIENTMETRICSA NONCLIENTMETRICS;
  تعريفنوع PNONCLIENTMETRICSA PNONCLIENTMETRICS;
  تعريفنوع LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو ARW_BOTTOMLEFT 0x0000L
#وصف_ڪريو ARW_BOTTOMRIGHT 0x0001L
#وصف_ڪريو ARW_TOPLEFT 0x0002L
#وصف_ڪريو ARW_TOPRIGHT 0x0003L
#وصف_ڪريو ARW_STARTMASK 0x0003L
#وصف_ڪريو ARW_STARTRIGHT 0x0001L
#وصف_ڪريو ARW_STARTTOP 0x0002L

#وصف_ڪريو ARW_کاٻو 0x0000L
#وصف_ڪريو ARW_ساڄو 0x0000L
#وصف_ڪريو ARW_مٿي 0x0004L
#وصف_ڪريو ARW_هيٺ_ڏانهن 0x0004L
#وصف_ڪريو ARW_HIDE 0x0008L

  تعريفنوع بنية ٽيگ_MINIMIZEDMETRICS {
    UINT cb_سائيز;
    صحيح i_ويڪر;
    صحيح iHorzGap;
    صحيح iVertGap;
    صحيح iArrange;
  } MINIMIZEDMETRICS,*PMINIMIZEDMETRICS,*LPMINIMIZEDMETRICS;

#جيڪڏهن_وصف_ٿيل _WINGDI_
#جيڪڏهن_وصف_نه_ٿيل NOGDI
  تعريفنوع بنية ٽيگ_ICONMETRICSA {
    UINT cb_سائيز;
    صحيح iHorzSpacing;
    صحيح iVertSpacing;
    صحيح iTitleWrap;
    LOGFONTA lfFont;
  } ICONMETRICSA,*PICONMETRICSA,*LPICONMETRICSA;

  تعريفنوع بنية ٽيگ_ICONMETRICSW {
    UINT cb_سائيز;
    صحيح iHorzSpacing;
    صحيح iVertSpacing;
    صحيح iTitleWrap;
    LOGFONTW lfFont;
  } ICONMETRICSW,*PICONMETRICSW,*LPICONMETRICSW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع ICONMETRICSW ICONMETRICS;
  تعريفنوع PICONMETRICSW PICONMETRICS;
  تعريفنوع LPICONMETRICSW LPICONMETRICS;
#وإلا
  تعريفنوع ICONMETRICSA ICONMETRICS;
  تعريفنوع PICONMETRICSA PICONMETRICS;
  تعريفنوع LPICONMETRICSA LPICONMETRICS;
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_ANIMATIONINFO {
    UINT cb_سائيز;
    صحيح iMinAnimate;
  } ANIMATIONINFO,*LPANIMATIONINFO;

  تعريفنوع بنية ٽيگ_SERIALKEYSA {
    UINT cb_سائيز;
    DWORD dwFlags;
    LPSTR lpsz_سرگرم_پورٽ;
    LPSTR lpsz_پورٽ;
    UINT i_Baud_شرح;
    UINT i_پورٽ_State;
    UINT i_سرگرم;
  } SERIALKEYSA,*LPSERIALKEYSA;

  تعريفنوع بنية ٽيگ_SERIALKEYSW {
    UINT cb_سائيز;
    DWORD dwFlags;
    LPWSTR lpsz_سرگرم_پورٽ;
    LPWSTR lpsz_پورٽ;
    UINT i_Baud_شرح;
    UINT i_پورٽ_State;
    UINT i_سرگرم;
  } SERIALKEYSW,*LPSERIALKEYSW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع SERIALKEYSW SERIALKEYS;
  تعريفنوع LPSERIALKEYSW LPSERIALKEYS;
#وإلا
  تعريفنوع SERIALKEYSA SERIALKEYS;
  تعريفنوع LPSERIALKEYSA LPSERIALKEYS;
#جيڪڏهن_پورو

#وصف_ڪريو SERKF_SERIALKEYSON 0x00000001
#وصف_ڪريو SERKF_موجود 0x00000002
#وصف_ڪريو SERKF_INDICATOR 0x00000004

  تعريفنوع بنية ٽيگ_HIGHCONTRASTA {
    UINT cb_سائيز;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
  } HIGHCONTRASTA,*LPHIGHCONTRASTA;

  تعريفنوع بنية ٽيگ_HIGHCONTRASTW {
    UINT cb_سائيز;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
  } HIGHCONTRASTW,*LPHIGHCONTRASTW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع HIGHCONTRASTW HIGHCONTRAST;
  تعريفنوع LPHIGHCONTRASTW LPHIGHCONTRAST;
#وإلا
  تعريفنوع HIGHCONTRASTA HIGHCONTRAST;
  تعريفنوع LPHIGHCONTRASTA LPHIGHCONTRAST;
#جيڪڏهن_پورو

#وصف_ڪريو HCF_HIGHCONTRASTON 0x00000001
#وصف_ڪريو HCF_موجود 0x00000002
#وصف_ڪريو HCF_HOTKEYACTIVE 0x00000004
#وصف_ڪريو HCF_CONFIRMHOTKEY 0x00000008
#وصف_ڪريو HCF_HOTKEYSOUND 0x00000010
#وصف_ڪريو HCF_INDICATOR 0x00000020
#وصف_ڪريو HCF_HOTKEYAVAILABLE 0x00000040
#وصف_ڪريو HCF_LOGONDESKTOP 0x00000100
#وصف_ڪريو HCF_DEFAULTDESKTOP 0x00000200

#وصف_ڪريو CDS_UPDATEREGISTRY 0x00000001
#وصف_ڪريو CDS_TEST 0x00000002
#وصف_ڪريو CDS_FULLSCREEN 0x00000004
#وصف_ڪريو CDS_GLOBAL 0x00000008
#وصف_ڪريو CDS_سيٽ_PRIMARY 0x00000010
#وصف_ڪريو CDS_VIDEOPARAMETERS 0x00000020
#وصف_ڪريو CDS_RESET 0x40000000
#وصف_ڪريو CDS_NORESET 0x10000000

//gr #include <tvout.h>

#وصف_ڪريو DISP_CHANGE_SUCCESSFUL 0
#وصف_ڪريو DISP_CHANGE_RESTART 1
#وصف_ڪريو DISP_CHANGE_FAILED -1
#وصف_ڪريو DISP_CHANGE_BADMODE -2
#وصف_ڪريو DISP_CHANGE_NOTUPDATED -3
#وصف_ڪريو DISP_CHANGE_BADFLAGS -4
#وصف_ڪريو DISP_CHANGE_BADPARAM -5
#وصف_ڪريو DISP_CHANGE_BADDUALVIEW -6

#جيڪڏهن_وصف_ٿيل _WINGDI_
#جيڪڏهن_وصف_نه_ٿيل NOGDI

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ChangeDisplaySettings ChangeDisplaySettingsW
#وصف_ڪريو ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#وصف_ڪريو EnumDisplaySettings EnumDisplaySettingsW
#وصف_ڪريو EnumDisplaySettingsEx EnumDisplaySettingsExW
#وصف_ڪريو EnumDisplayDevices EnumDisplayDevicesW
#وإلا
#وصف_ڪريو ChangeDisplaySettings ChangeDisplaySettingsA
#وصف_ڪريو ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#وصف_ڪريو EnumDisplaySettings EnumDisplaySettingsA
#وصف_ڪريو EnumDisplaySettingsEx EnumDisplaySettingsExA
#وصف_ڪريو EnumDisplayDevices EnumDisplayDevicesA
#جيڪڏهن_پورو

  WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lp_Dev_گهڻائي,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsW(LPDEVMODEW lp_Dev_گهڻائي,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,LPDEVMODEA lp_Dev_گهڻائي,HWND hwnd,DWORD dwflags,LPVOID lParam);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,LPDEVMODEW lp_Dev_گهڻائي,HWND hwnd,DWORD dwflags,LPVOID lParam);

#وصف_ڪريو ENUM_CURRENT_SETTINGS ((DWORD)-1)
#وصف_ڪريو ENUM_REGISTRY_SETTINGS ((DWORD)-2)

  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD i_گهڻائي_انگ,LPDEVMODEA lp_Dev_گهڻائي);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD i_گهڻائي_انگ,LPDEVMODEW lp_Dev_گهڻائي);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD i_گهڻائي_انگ,LPDEVMODEA lp_Dev_گهڻائي,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD i_گهڻائي_انگ,LPDEVMODEW lp_Dev_گهڻائي,DWORD dwFlags);

#وصف_ڪريو EDS_RAWMODE 0x00000002

  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesA(LPCSTR lpDevice,DWORD i_Dev_انگ,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD i_Dev_انگ,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو SystemParametersInfo SystemParametersInfoW
#وإلا
#وصف_ڪريو SystemParametersInfo SystemParametersInfoA
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
  WINUSERAPI WINBOOL WINAPI SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_FILTERKEYS {
    UINT cb_سائيز;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
  } FILTERKEYS,*LPFILTERKEYS;

#وصف_ڪريو FKF_FILTERKEYSON 0x00000001
#وصف_ڪريو FKF_موجود 0x00000002
#وصف_ڪريو FKF_HOTKEYACTIVE 0x00000004
#وصف_ڪريو FKF_CONFIRMHOTKEY 0x00000008
#وصف_ڪريو FKF_HOTKEYSOUND 0x00000010
#وصف_ڪريو FKF_INDICATOR 0x00000020
#وصف_ڪريو FKF_CLICKON 0x00000040

  تعريفنوع بنية ٽيگ_STICKYKEYS {
    UINT cb_سائيز;
    DWORD dwFlags;
  } STICKYKEYS,*LPSTICKYKEYS;

#وصف_ڪريو SKF_STICKYKEYSON 0x00000001
#وصف_ڪريو SKF_موجود 0x00000002
#وصف_ڪريو SKF_HOTKEYACTIVE 0x00000004
#وصف_ڪريو SKF_CONFIRMHOTKEY 0x00000008
#وصف_ڪريو SKF_HOTKEYSOUND 0x00000010
#وصف_ڪريو SKF_INDICATOR 0x00000020
#وصف_ڪريو SKF_AUDIBLEFEEDBACK 0x00000040
#وصف_ڪريو SKF_TRISTATE 0x00000080
#وصف_ڪريو SKF_TWOKEYSOFF 0x00000100
#وصف_ڪريو SKF_LALTLATCHED 0x10000000
#وصف_ڪريو SKF_LCTLLATCHED 0x04000000
#وصف_ڪريو SKF_LSHIFTLATCHED 0x01000000
#وصف_ڪريو SKF_RALTLATCHED 0x20000000
#وصف_ڪريو SKF_RCTLLATCHED 0x08000000
#وصف_ڪريو SKF_RSHIFTLATCHED 0x02000000
#وصف_ڪريو SKF_LWINLATCHED 0x40000000
#وصف_ڪريو SKF_RWINLATCHED 0x80000000
#وصف_ڪريو SKF_LALTLOCKED 0x00100000
#وصف_ڪريو SKF_LCTLLOCKED 0x00040000
#وصف_ڪريو SKF_LSHIFTLOCKED 0x00010000
#وصف_ڪريو SKF_RALTLOCKED 0x00200000
#وصف_ڪريو SKF_RCTLLOCKED 0x00080000
#وصف_ڪريو SKF_RSHIFTLOCKED 0x00020000
#وصف_ڪريو SKF_LWINLOCKED 0x00400000
#وصف_ڪريو SKF_RWINLOCKED 0x00800000

  تعريفنوع بنية ٽيگ_MOUSEKEYS {
    UINT cb_سائيز;
    DWORD dwFlags;
    DWORD i_Max_رفتار;
    DWORD i_وقت_منزل_Max_رفتار;
    DWORD i_Ctrl_رفتار;
    DWORD dwReserved1;
    DWORD dwReserved2;
  } MOUSEKEYS,*LPMOUSEKEYS;

#وصف_ڪريو MKF_MOUSEKEYSON 0x00000001
#وصف_ڪريو MKF_موجود 0x00000002
#وصف_ڪريو MKF_HOTKEYACTIVE 0x00000004
#وصف_ڪريو MKF_CONFIRMHOTKEY 0x00000008
#وصف_ڪريو MKF_HOTKEYSOUND 0x00000010
#وصف_ڪريو MKF_INDICATOR 0x00000020
#وصف_ڪريو MKF_MODIFIERS 0x00000040
#وصف_ڪريو MKF_REPLACENUMBERS 0x00000080
#وصف_ڪريو MKF_LEFTBUTTONSEL 0x10000000
#وصف_ڪريو MKF_RIGHTBUTTONSEL 0x20000000
#وصف_ڪريو MKF_LEFTBUTTONDOWN 0x01000000
#وصف_ڪريو MKF_RIGHTBUTTONDOWN 0x02000000
#وصف_ڪريو MKF_MOUSEMODE 0x80000000

  تعريفنوع بنية ٽيگ_ACCESSTIMEOUT {
    UINT cb_سائيز;
    DWORD dwFlags;
    DWORD i_وقت_ٻاهريون_MSec;
  } ACCESSTIMEOUT,*LPACCESSTIMEOUT;

#وصف_ڪريو ATF_TIMEOUTON 0x00000001
#وصف_ڪريو ATF_ONOFFFEEDBACK 0x00000002

#وصف_ڪريو SSGF_NONE 0
#وصف_ڪريو SSGF_DISPLAY 3

#وصف_ڪريو SSTF_NONE 0
#وصف_ڪريو SSTF_CHARS 1
#وصف_ڪريو SSTF_BORDER 2
#وصف_ڪريو SSTF_DISPLAY 3

#وصف_ڪريو SSWF_NONE 0
#وصف_ڪريو SSWF_TITLE 1
#وصف_ڪريو SSWF_دري 2
#وصف_ڪريو SSWF_DISPLAY 3
#وصف_ڪريو SSWF_CUSTOM 4

  تعريفنوع بنية ٽيگ_SOUNDSENTRYA {
    UINT cb_سائيز;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_بٽ;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYA,*LPSOUNDSENTRYA;

  تعريفنوع بنية ٽيگ_SOUNDSENTRYW {
    UINT cb_سائيز;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_بٽ;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYW,*LPSOUNDSENTRYW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع SOUNDSENTRYW SOUNDSENTRY;
  تعريفنوع LPSOUNDSENTRYW LPSOUNDSENTRY;
#وإلا
  تعريفنوع SOUNDSENTRYA SOUNDSENTRY;
  تعريفنوع LPSOUNDSENTRYA LPSOUNDSENTRY;
#جيڪڏهن_پورو

#وصف_ڪريو SSF_SOUNDSENTRYON 0x00000001
#وصف_ڪريو SSF_موجود 0x00000002
#وصف_ڪريو SSF_INDICATOR 0x00000004

  تعريفنوع بنية ٽيگ_TOGGLEKEYS {
    UINT cb_سائيز;
    DWORD dwFlags;
  } TOGGLEKEYS,*LPTOGGLEKEYS;

#وصف_ڪريو TKF_TOGGLEKEYSON 0x00000001
#وصف_ڪريو TKF_موجود 0x00000002
#وصف_ڪريو TKF_HOTKEYACTIVE 0x00000004
#وصف_ڪريو TKF_CONFIRMHOTKEY 0x00000008
#وصف_ڪريو TKF_HOTKEYSOUND 0x00000010
#وصف_ڪريو TKF_INDICATOR 0x00000020

  WINUSERAPI VOID WINAPI سيٽ_Debug_Error_Level(DWORD dwLevel);

#وصف_ڪريو SLE_ERROR 0x00000001
#وصف_ڪريو SLE_MINORERROR 0x00000002
#وصف_ڪريو SLE_WARNING 0x00000003

  WINUSERAPI VOID WINAPI سيٽ_آخري_Error_Ex(DWORD dw_Err_ڪوڊ,DWORD dwType);
  WINUSERAPI صحيح WINAPI اندروني_Get_دري_متن(HWND hWnd,LPWSTR pString,صحيح cch_Max_ڳڻپ);

#جيڪڏهن_وصف_ٿيل WINNT
  WINUSERAPI WINBOOL WINAPI پڇاڙي_Task(HWND hWnd,WINBOOL f_Shut_هيٺ_ڏانهن,WINBOOL fForce);
#جيڪڏهن_پورو

#وصف_ڪريو MONITOR_DEFAULTTONULL 0x00000000
#وصف_ڪريو MONITOR_DEFAULTTOPRIMARY 0x00000001
#وصف_ڪريو MONITOR_DEFAULTTONEAREST 0x00000002

  WINUSERAPI HMONITOR WINAPI Monitor_From_نقطو(نقطو_3 pt,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromRect(LPCRECT lprc,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI Monitor_From_دري(HWND hwnd,DWORD dwFlags);

#وصف_ڪريو MONITORINFOF_PRIMARY 0x00000001

#جيڪڏهن_وصف_نه_ٿيل CCHDEVICENAME
#وصف_ڪريو CCHDEVICENAME 32
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_MONITORINFO {
    DWORD cb_سائيز;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
  } MONITORINFO,*LPMONITORINFO;

#جيڪڏهن_وصف_ٿيل __cplusplus
  تعريفنوع بنية ٽيگ_MONITORINFOEXA : عام ٽيگ_MONITORINFO {
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  تعريفنوع بنية ٽيگ_MONITORINFOEXW : عام ٽيگ_MONITORINFO {
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع MONITORINFOEXW MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXW LPMONITORINFOEX;
#وإلا
  تعريفنوع MONITORINFOEXA MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXA LPMONITORINFOEX;
#جيڪڏهن_پورو
#وإلا
  تعريفنوع بنية ٽيگ_MONITORINFOEXA {
    MONITORINFO mi;
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  تعريفنوع بنية ٽيگ_MONITORINFOEXW {
    MONITORINFO mi;
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع MONITORINFOEXW MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXW LPMONITORINFOEX;
#وإلا
  تعريفنوع MONITORINFOEXA MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXA LPMONITORINFOEX;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE 
#وصف_ڪريو GetMonitorInfo GetMonitorInfoW
#وإلا
#وصف_ڪريو GetMonitorInfo GetMonitorInfoA
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
  WINUSERAPI WINBOOL WINAPI GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);

  تعريفنوع WINBOOL (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

  WINUSERAPI WINBOOL WINAPI EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dw_معلومات);

#جيڪڏهن_وصف_نه_ٿيل NOWINABLE
  WINUSERAPI VOID WINAPI NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG id_ٻار);

  تعريفنوع VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK hWinEventHook,DWORD event,HWND hwnd,LONG idObject,LONG id_ٻار,DWORD idEventThread,DWORD dwms_Event_وقت);

  WINUSERAPI HWINEVENTHOOK WINAPI سيٽ_Win_Event_Hook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI IsWinEventHookInstalled(DWORD event);

#وصف_ڪريو WINEVENT_OUTOFCONTEXT 0x0000
#وصف_ڪريو WINEVENT_SKIPOWNTHREAD 0x0001
#وصف_ڪريو WINEVENT_SKIPOWNPROCESS 0x0002
#وصف_ڪريو WINEVENT_INCONTEXT 0x0004

  WINUSERAPI WINBOOL WINAPI UnhookWinEvent(HWINEVENTHOOK hWinEventHook);

#وصف_ڪريو CHILDID_SELF 0
#وصف_ڪريو INDEXID_OBJECT 0
#وصف_ڪريو INDEXID_CONTAINER 0

#وصف_ڪريو OBJID_دري ((LONG)0x00000000)
#وصف_ڪريو OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#وصف_ڪريو OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#وصف_ڪريو OBJID_MENU ((LONG)0xFFFFFFFD)
#وصف_ڪريو OBJID_CLIENT ((LONG)0xFFFFFFFC)
#وصف_ڪريو OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#وصف_ڪريو OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#وصف_ڪريو OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#وصف_ڪريو OBJID_CARET ((LONG)0xFFFFFFF8)
#وصف_ڪريو OBJID_CURSOR ((LONG)0xFFFFFFF7)
#وصف_ڪريو OBJID_ALERT ((LONG)0xFFFFFFF6)
#وصف_ڪريو OBJID_SOUND ((LONG)0xFFFFFFF5)
#وصف_ڪريو OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#وصف_ڪريو OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#وصف_ڪريو EVENT_MIN 0x00000001
#وصف_ڪريو EVENT_MAX 0x7FFFFFFF

#وصف_ڪريو EVENT_SYSTEM_SOUND 0x0001
#وصف_ڪريو EVENT_SYSTEM_ALERT 0x0002
#وصف_ڪريو EVENT_SYSTEM_FOREGROUND 0x0003
#وصف_ڪريو EVENT_SYSTEM_MENUSTART 0x0004
#وصف_ڪريو EVENT_SYSTEM_MENUEND 0x0005
#وصف_ڪريو EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#وصف_ڪريو EVENT_SYSTEM_MENUPOPUPEND 0x0007
#وصف_ڪريو EVENT_SYSTEM_CAPTURESTART 0x0008
#وصف_ڪريو EVENT_SYSTEM_CAPTUREEND 0x0009
#وصف_ڪريو EVENT_SYSTEM_MOVESIZESTART 0x000A
#وصف_ڪريو EVENT_SYSTEM_MOVESIZEEND 0x000B
#وصف_ڪريو EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#وصف_ڪريو EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#وصف_ڪريو EVENT_SYSTEM_DRAGDROPSTART 0x000E
#وصف_ڪريو EVENT_SYSTEM_DRAGDROPEND 0x000F
#وصف_ڪريو EVENT_SYSTEM_DIALOGSTART 0x0010
#وصف_ڪريو EVENT_SYSTEM_DIALOGEND 0x0011
#وصف_ڪريو EVENT_SYSTEM_SCROLLINGSTART 0x0012
#وصف_ڪريو EVENT_SYSTEM_SCROLLINGEND 0x0013
#وصف_ڪريو EVENT_SYSTEM_SWITCHSTART 0x0014
#وصف_ڪريو EVENT_SYSTEM_SWITCHEND 0x0015
#وصف_ڪريو EVENT_SYSTEM_MINIMIZESTART 0x0016
#وصف_ڪريو EVENT_SYSTEM_MINIMIZEEND 0x0017

#وصف_ڪريو EVENT_CONSOLE_CARET 0x4001
#وصف_ڪريو EVENT_CONSOLE_UPDATE_REGION 0x4002
#وصف_ڪريو EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#وصف_ڪريو EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#وصف_ڪريو EVENT_CONSOLE_LAYOUT 0x4005
#وصف_ڪريو EVENT_CONSOLE_شروعات_APPLICATION 0x4006
#وصف_ڪريو EVENT_CONSOLE_پڇاڙي_APPLICATION 0x4007

#وصف_ڪريو CONSOLE_APPLICATION_16_ٻٽو_انگ 0x0001

#وصف_ڪريو CONSOLE_CARET_SELECTION 0x0001
#وصف_ڪريو CONSOLE_CARET_VISIBLE 0x0002

#وصف_ڪريو EVENT_OBJECT_CREATE 0x8000
#وصف_ڪريو EVENT_OBJECT_DESTROY 0x8001
#وصف_ڪريو EVENT_OBJECT_SHOW 0x8002
#وصف_ڪريو EVENT_OBJECT_HIDE 0x8003
#وصف_ڪريو EVENT_OBJECT_REORDER 0x8004

#وصف_ڪريو EVENT_OBJECT_FOCUS 0x8005
#وصف_ڪريو EVENT_OBJECT_SELECTION 0x8006
#وصف_ڪريو EVENT_OBJECT_SELECTIONADD 0x8007
#وصف_ڪريو EVENT_OBJECT_SELECTIONREMOVE 0x8008
#وصف_ڪريو EVENT_OBJECT_SELECTIONWITHIN 0x8009

#وصف_ڪريو EVENT_OBJECT_STATECHANGE 0x800A

#وصف_ڪريو EVENT_OBJECT_LOCATIONCHANGE 0x800B

#وصف_ڪريو EVENT_OBJECT_NAMECHANGE 0x800C
#وصف_ڪريو EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#وصف_ڪريو EVENT_OBJECT_VALUECHANGE 0x800E
#وصف_ڪريو EVENT_OBJECT_PARENTCHANGE 0x800F
#وصف_ڪريو EVENT_OBJECT_HELPCHANGE 0x8010
#وصف_ڪريو EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#وصف_ڪريو EVENT_OBJECT_ACCELERATORCHANGE 0x8012

#وصف_ڪريو SOUND_SYSTEM_STARTUP 1
#وصف_ڪريو SOUND_SYSTEM_SHUTDOWN 2
#وصف_ڪريو SOUND_SYSTEM_BEEP 3
#وصف_ڪريو SOUND_SYSTEM_ERROR 4
#وصف_ڪريو SOUND_SYSTEM_QUESTION 5
#وصف_ڪريو SOUND_SYSTEM_WARNING 6
#وصف_ڪريو SOUND_SYSTEM_INFORMATION 7
#وصف_ڪريو SOUND_SYSTEM_MAXIMIZE 8
#وصف_ڪريو SOUND_SYSTEM_MINIMIZE 9
#وصف_ڪريو SOUND_SYSTEM_RESTOREUP 10
#وصف_ڪريو SOUND_SYSTEM_RESTOREDOWN 11
#وصف_ڪريو SOUND_SYSTEM_APPSTART 12
#وصف_ڪريو SOUND_SYSTEM_FAULT 13
#وصف_ڪريو SOUND_SYSTEM_APPEND 14
#وصف_ڪريو SOUND_SYSTEM_MENUCOMMAND 15
#وصف_ڪريو SOUND_SYSTEM_MENUPOPUP 16
#وصف_ڪريو CSOUND_SYSTEM 16

#وصف_ڪريو ALERT_SYSTEM_INFORMATIONAL 1
#وصف_ڪريو ALERT_SYSTEM_WARNING 2
#وصف_ڪريو ALERT_SYSTEM_ERROR 3
#وصف_ڪريو ALERT_SYSTEM_QUERY 4
#وصف_ڪريو ALERT_SYSTEM_CRITICAL 5
#وصف_ڪريو CALERT_SYSTEM 6

  تعريفنوع بنية ٽيگ_GUITHREADINFO {
    DWORD cb_سائيز;
    DWORD flags;
    HWND hwnd_سرگرم;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwnd_Move_سائيز;
    HWND hwndCaret;
    RECT rcCaret;
  } GUITHREADINFO,*PGUITHREADINFO,*LPGUITHREADINFO;

#وصف_ڪريو GUI_CARETBLINKING 0x00000001
#وصف_ڪريو GUI_INMOVESIZE 0x00000002
#وصف_ڪريو GUI_INMENUMODE 0x00000004
#وصف_ڪريو GUI_SYSTEMMENUMODE 0x00000008
#وصف_ڪريو GUI_POPUPMENUMODE 0x00000010
#وصف_ڪريو GUI_16BITTASK 0x00000020

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_دري_Module_File_Name Get_دري_Module_File_Name_W
#وإلا
#وصف_ڪريو Get_دري_Module_File_Name Get_دري_Module_File_Name_A
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui);
  WINUSERAPI UINT WINAPI Get_دري_Module_File_Name_A(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
  WINUSERAPI UINT WINAPI Get_دري_Module_File_Name_W(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);

#جيڪڏهن_وصف_نه_ٿيل NO_STATE_FLAGS
#وصف_ڪريو STATE_SYSTEM_UNAVAILABLE 0x00000001
#وصف_ڪريو STATE_SYSTEM_SELECTED 0x00000002
#وصف_ڪريو STATE_SYSTEM_FOCUSED 0x00000004
#وصف_ڪريو STATE_SYSTEM_PRESSED 0x00000008
#وصف_ڪريو STATE_SYSTEM_CHECKED 0x00000010
#وصف_ڪريو STATE_SYSTEM_MIXED 0x00000020
#وصف_ڪريو STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#وصف_ڪريو STATE_SYSTEM_READONLY 0x00000040
#وصف_ڪريو STATE_SYSTEM_HOTTRACKED 0x00000080
#وصف_ڪريو STATE_SYSTEM_DEFAULT 0x00000100
#وصف_ڪريو STATE_SYSTEM_EXPANDED 0x00000200
#وصف_ڪريو STATE_SYSTEM_COLLAPSED 0x00000400
#وصف_ڪريو STATE_SYSTEM_BUSY 0x00000800
#وصف_ڪريو STATE_SYSTEM_FLOATING 0x00001000
#وصف_ڪريو STATE_SYSTEM_MARQUEED 0x00002000
#وصف_ڪريو STATE_SYSTEM_ANIMATED 0x00004000
#وصف_ڪريو STATE_SYSTEM_INVISIBLE 0x00008000
#وصف_ڪريو STATE_SYSTEM_OFFSCREEN 0x00010000
#وصف_ڪريو STATE_SYSTEM_SIZEABLE 0x00020000
#وصف_ڪريو STATE_SYSTEM_MOVEABLE 0x00040000
#وصف_ڪريو STATE_SYSTEM_SELFVOICING 0x00080000
#وصف_ڪريو STATE_SYSTEM_FOCUSABLE 0x00100000
#وصف_ڪريو STATE_SYSTEM_SELECTABLE 0x00200000
#وصف_ڪريو STATE_SYSTEM_LINKED 0x00400000
#وصف_ڪريو STATE_SYSTEM_TRAVERSED 0x00800000
#وصف_ڪريو STATE_SYSTEM_MULTISELECTABLE 0x01000000
#وصف_ڪريو STATE_SYSTEM_EXTSELECTABLE 0x02000000
#وصف_ڪريو STATE_SYSTEM_ALERT_هيٺيون 0x04000000
#وصف_ڪريو STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#وصف_ڪريو STATE_SYSTEM_ALERT_مٿاهون 0x10000000
#وصف_ڪريو STATE_SYSTEM_PROTECTED 0x20000000
#وصف_ڪريو STATE_SYSTEM_VALID 0x3FFFFFFF
#جيڪڏهن_پورو

#وصف_ڪريو CCHILDREN_TITLEBAR 5
#وصف_ڪريو CCHILDREN_SCROLLBAR 5

  تعريفنوع بنية ٽيگ_CURSORINFO {
    DWORD cb_سائيز;
    DWORD flags;
    HCURSOR hCursor;
    نقطو_3 ptScreenPos;
  } CURSORINFO,*PCURSORINFO,*LPCURSORINFO;

#وصف_ڪريو CURSOR_SHOWING 0x00000001

  WINUSERAPI WINBOOL WINAPI GetCursorInfo(PCURSORINFO pci);

  تعريفنوع بنية ٽيگ_WINDOWINFO {
    DWORD cb_سائيز;
    RECT rc_دري;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dw_دري_حالت;
    UINT cx_دري_Borders;
    UINT cy_دري_Borders;
    ATOM atom_دري_Type;
    لفظ_3 w_Creator_نسخو;
  } WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;

#وصف_ڪريو WS_ACTIVECAPTION 0x0001

  WINUSERAPI WINBOOL WINAPI Get_دري_Info(HWND hwnd,PWINDOWINFO pwi);

  تعريفنوع بنية ٽيگ_TITLEBARINFO {
    DWORD cb_سائيز;
    RECT rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  } TITLEBARINFO,*PTITLEBARINFO,*LPTITLEBARINFO;

  WINUSERAPI WINBOOL WINAPI GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti);

  تعريفنوع بنية ٽيگ_MENUBARINFO {
    DWORD cb_سائيز;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    WINBOOL fBarFocused:1;
    WINBOOL fFocused:1;
  } MENUBARINFO,*PMENUBARINFO,*LPMENUBARINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuBarInfo(HWND hwnd,LONG idObject,LONG id_شي,PMENUBARINFO pmbi);

  تعريفنوع بنية ٽيگ_SCROLLBARINFO {
    DWORD cb_سائيز;
    RECT rcScrollBar;
    صحيح dxy_سٽ_Button;
    صحيح xy_Thumb_چوٽي;
    صحيح xyThumbBottom;
    صحيح reserved;
    DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
  } SCROLLBARINFO,*PSCROLLBARINFO,*LPSCROLLBARINFO;

  WINUSERAPI WINBOOL WINAPI GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);

  تعريفنوع بنية ٽيگ_COMBOBOXINFO {
    DWORD cb_سائيز;
    RECT rc_شي;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwnd_شي;
    HWND hwndList;
  } COMBOBOXINFO,*PCOMBOBOXINFO,*LPCOMBOBOXINFO;

  WINUSERAPI WINBOOL WINAPI GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi);

#وصف_ڪريو GA_والد 1
#وصف_ڪريو GA_پاڙ 2
#وصف_ڪريو GA_ROOTOWNER 3

  WINUSERAPI HWND WINAPI GetAncestor(HWND hwnd,UINT gaFlags);
  WINUSERAPI HWND WINAPI Real_ٻار_دري_From_نقطو(HWND hwnd_والد_2,نقطو_3 pt_والد_Client_Coords);
  WINUSERAPI UINT WINAPI Real_Get_دري_Class_A(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
  WINUSERAPI UINT WINAPI Real_Get_دري_Class_W(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Real_Get_دري_Class Real_Get_دري_Class_W
#وإلا
#وصف_ڪريو Real_Get_دري_Class Real_Get_دري_Class_A
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_ALTTABINFO {
    DWORD cb_سائيز;
    صحيح c_شيون;
    صحيح cColumns;
    صحيح c_صفون;
    صحيح i_کانو_Focus;
    صحيح i_صف_Focus;
    صحيح cx_شي;
    صحيح cy_شي;
    نقطو_3 pt_شروعات;
  } ALTTABINFO,*PALTTABINFO,*LPALTTABINFO;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetAltTabInfo GetAltTabInfoW
#وإلا
#وصف_ڪريو GetAltTabInfo GetAltTabInfoA
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI GetAltTabInfoA(HWND hwnd,صحيح i_شي,PALTTABINFO pati,LPSTR psz_شي_متن,UINT cch_شي_متن);
  WINUSERAPI WINBOOL WINAPI GetAltTabInfoW(HWND hwnd,صحيح i_شي,PALTTABINFO pati,LPWSTR psz_شي_متن,UINT cch_شي_متن);
  WINUSERAPI DWORD WINAPI GetListBoxInfo(HWND hwnd);
#جيڪڏهن_پورو

  WINUSERAPI WINBOOL WINAPI تالو_Work_Station(VOID);
  WINUSERAPI WINBOOL WINAPI UserHandleGrantAccess(HANDLE hUserHandle,HANDLE h_ڪم,WINBOOL bGrant);

  DECLARE_HANDLE(HRAWINPUT);

#وصف_ڪريو GET_RAWINPUT_ڪوڊ_WPARAM(wParam) ((wParam) & 0xff)

#وصف_ڪريو RIM_داخلا 0
#وصف_ڪريو RIM_INPUTSINK 1

  تعريفنوع بنية ٽيگ_RAWINPUTHEADER {
    DWORD dwType;
    DWORD dw_سائيز;
    HANDLE hDevice;
    WPARAM wParam;
  } RAWINPUTHEADER,*PRAWINPUTHEADER,*LPRAWINPUTHEADER;

#وصف_ڪريو RIM_TYPEMOUSE 0
#وصف_ڪريو RIM_TYPEKEYBOARD 1
#وصف_ڪريو RIM_TYPEHID 2

  تعريفنوع بنية ٽيگ_RAWMOUSE {
    USHORT usFlags;
    اتحاد {
      ULONG ulButtons;
      بنية {
	USHORT usButtonFlags;
	USHORT us_Button_معلومات;
      };
    };
    ULONG ulRawButtons;
    LONG l_آخري_X;
    LONG l_آخري_Y;
    ULONG ulExtraInformation;
  } RAWMOUSE,*PRAWMOUSE,*LPRAWMOUSE;

#وصف_ڪريو RI_MOUSE_کاٻو_BUTTON_هيٺ_ڏانهن 0x0001
#وصف_ڪريو RI_MOUSE_کاٻو_BUTTON_مٿي 0x0002
#وصف_ڪريو RI_MOUSE_ساڄو_BUTTON_هيٺ_ڏانهن 0x0004
#وصف_ڪريو RI_MOUSE_ساڄو_BUTTON_مٿي 0x0008
#وصف_ڪريو RI_MOUSE_وچ_BUTTON_هيٺ_ڏانهن 0x0010
#وصف_ڪريو RI_MOUSE_وچ_BUTTON_مٿي 0x0020

#وصف_ڪريو RI_MOUSE_BUTTON_1_هيٺ_ڏانهن RI_MOUSE_کاٻو_BUTTON_هيٺ_ڏانهن
#وصف_ڪريو RI_MOUSE_BUTTON_1_مٿي RI_MOUSE_کاٻو_BUTTON_مٿي
#وصف_ڪريو RI_MOUSE_BUTTON_2_هيٺ_ڏانهن RI_MOUSE_ساڄو_BUTTON_هيٺ_ڏانهن
#وصف_ڪريو RI_MOUSE_BUTTON_2_مٿي RI_MOUSE_ساڄو_BUTTON_مٿي
#وصف_ڪريو RI_MOUSE_BUTTON_3_هيٺ_ڏانهن RI_MOUSE_وچ_BUTTON_هيٺ_ڏانهن
#وصف_ڪريو RI_MOUSE_BUTTON_3_مٿي RI_MOUSE_وچ_BUTTON_مٿي

#وصف_ڪريو RI_MOUSE_BUTTON_4_هيٺ_ڏانهن 0x0040
#وصف_ڪريو RI_MOUSE_BUTTON_4_مٿي 0x0080
#وصف_ڪريو RI_MOUSE_BUTTON_5_هيٺ_ڏانهن 0x0100
#وصف_ڪريو RI_MOUSE_BUTTON_5_مٿي 0x0200

#وصف_ڪريو RI_MOUSE_WHEEL 0x0400

#وصف_ڪريو MOUSE_MOVE_RELATIVE 0
#وصف_ڪريو MOUSE_MOVE_ABSOLUTE 1
#وصف_ڪريو MOUSE_VIRTUAL_DESKTOP 0x02
#وصف_ڪريو MOUSE_خاصيتون_بدليو 0x04

  تعريفنوع بنية ٽيگ_RAWKEYBOARD {
    USHORT Make_ڪوڊ;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT پيغام_3;
    ULONG ExtraInformation;
  } RAWKEYBOARD,*PRAWKEYBOARD,*LPRAWKEYBOARD;

#وصف_ڪريو KEYBOARD_OVERRUN_MAKE_ڪوڊ 0xFF

#وصف_ڪريو RI_ڪنجي_MAKE 0
#وصف_ڪريو RI_ڪنجي_BREAK 1
#وصف_ڪريو RI_ڪنجي_E0 2
#وصف_ڪريو RI_ڪنجي_E1 4
#وصف_ڪريو RI_ڪنجي_TERMSRV_سيٽ_LED 8
#وصف_ڪريو RI_ڪنجي_TERMSRV_SHADOW 0x10

  تعريفنوع بنية ٽيگ_RAWHID {
    DWORD dw_سائيز_Hid;
    DWORD dw_ڳڻپ;
    BYTE b_Raw_معلومات[1];
  } RAWHID,*PRAWHID,*LPRAWHID;

  تعريفنوع بنية ٽيگ_RAWINPUT {
    RAWINPUTHEADER سرو;
    اتحاد {
      RAWMOUSE mouse;
      RAWKEYBOARD keyboard;
      RAWHID hid;
    } معلومات;
  } RAWINPUT,*PRAWINPUT,*LPRAWINPUT;

#جيڪڏهن_وصف_ٿيل _WIN64
#وصف_ڪريو RAWINPUT_ALIGN(x) (((x) + حجم(QWORD) - 1) & ~(حجم(QWORD) - 1))
#وإلا
#وصف_ڪريو RAWINPUT_ALIGN(x) (((x) + حجم(DWORD) - 1) & ~(حجم(DWORD) - 1))
#جيڪڏهن_پورو

#وصف_ڪريو NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->سرو.dw_سائيز)))

#وصف_ڪريو RID_داخلا 0x10000003
#وصف_ڪريو RID_سرو 0x10000005

  WINUSERAPI UINT WINAPI Get_Raw_داخلا_معلومات(HRAWINPUT h_Raw_داخلا,UINT uiCommand,LPVOID p_معلومات,PUINT pcb_سائيز,UINT cb_سائيز_سرو);

#وصف_ڪريو RIDI_PREPARSEDDATA 0x20000005
#وصف_ڪريو RIDI_DEVICENAME 0x20000007
#وصف_ڪريو RIDI_DEVICEINFO 0x2000000b

  تعريفنوع بنية ٽيگ_RID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dw_عدد_جو_Buttons;
    DWORD dw_Sample_شرح;
  } RID_DEVICE_INFO_MOUSE,*PRID_DEVICE_INFO_MOUSE;

  تعريفنوع بنية ٽيگ_RID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dw_Keyboard_گهڻائي;
    DWORD dw_عدد_جو_Function_ڪنجيون;
    DWORD dw_عدد_جو_Indicators;
    DWORD dw_عدد_جو_ڪنجيون_ڪل;
  } RID_DEVICE_INFO_KEYBOARD,*PRID_DEVICE_INFO_KEYBOARD;

  تعريفنوع بنية ٽيگ_RID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dw_حاصل_ضرب_Id;
    DWORD dw_نسخو_عدد;
    USHORT us_Usage_صفحو;
    USHORT usUsage;
  } RID_DEVICE_INFO_HID,*PRID_DEVICE_INFO_HID;

  تعريفنوع بنية ٽيگ_RID_DEVICE_INFO {
    DWORD cb_سائيز;
    DWORD dwType;
    اتحاد {
      RID_DEVICE_INFO_MOUSE mouse;
      RID_DEVICE_INFO_KEYBOARD keyboard;
      RID_DEVICE_INFO_HID hid;
    };
  } RID_DEVICE_INFO,*PRID_DEVICE_INFO,*LPRID_DEVICE_INFO;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_Raw_داخلا_Device_Info Get_Raw_داخلا_Device_Info_W
#وإلا
#وصف_ڪريو Get_Raw_داخلا_Device_Info Get_Raw_داخلا_Device_Info_A
#جيڪڏهن_پورو

  WINUSERAPI UINT WINAPI Get_Raw_داخلا_Device_Info_A(HANDLE hDevice,UINT uiCommand,LPVOID p_معلومات,PUINT pcb_سائيز);
  WINUSERAPI UINT WINAPI Get_Raw_داخلا_Device_Info_W(HANDLE hDevice,UINT uiCommand,LPVOID p_معلومات,PUINT pcb_سائيز);
  WINUSERAPI UINT WINAPI Get_Raw_داخلا_بفر(PRAWINPUT p_معلومات,PUINT pcb_سائيز,UINT cb_سائيز_سرو);

  تعريفنوع بنية ٽيگ_RAWINPUTDEVICE {
    USHORT us_Usage_صفحو;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwnd_هدف;
  } RAWINPUTDEVICE,*PRAWINPUTDEVICE,*LPRAWINPUTDEVICE;

  تعريفنوع CONST RAWINPUTDEVICE *PCRAWINPUTDEVICE;

#وصف_ڪريو RIDEV_REMOVE 0x00000001
#وصف_ڪريو RIDEV_EXCLUDE 0x00000010
#وصف_ڪريو RIDEV_PAGEONLY 0x00000020
#وصف_ڪريو RIDEV_NOLEGACY 0x00000030
#وصف_ڪريو RIDEV_INPUTSINK 0x00000100
#وصف_ڪريو RIDEV_CAPTUREMOUSE 0x00000200
#وصف_ڪريو RIDEV_NOHOTKEYS 0x00000200
#وصف_ڪريو RIDEV_APPKEYS 0x00000400
#وصف_ڪريو RIDEV_EXMODEMASK 0x000000F0
#وصف_ڪريو RIDEV_EXMODE(گهڻائي) ((گهڻائي) & RIDEV_EXMODEMASK)

  WINUSERAPI WINBOOL WINAPI رجسٽر_Raw_داخلا_Devices(PCRAWINPUTDEVICE p_Raw_داخلا_Devices,UINT ui_انگ_Devices,UINT cb_سائيز);
  WINUSERAPI UINT WINAPI Get_Registered_Raw_داخلا_Devices(PRAWINPUTDEVICE p_Raw_داخلا_Devices,PUINT pui_انگ_Devices,UINT cb_سائيز);

  تعريفنوع بنية ٽيگ_RAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
  } RAWINPUTDEVICELIST,*PRAWINPUTDEVICELIST;

  WINUSERAPI UINT WINAPI Get_Raw_داخلا_Device_List(PRAWINPUTDEVICELIST p_Raw_داخلا_Device_List,PUINT pui_انگ_Devices,UINT cb_سائيز);
  WINUSERAPI LRESULT WINAPI Def_Raw_داخلا_Proc(PRAWINPUT *pa_Raw_داخلا,INT n_داخلا,UINT cb_سائيز_سرو);

#جيڪڏهن_پورو /* NOUSER */

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
