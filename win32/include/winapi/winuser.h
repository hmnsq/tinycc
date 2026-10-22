/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _WINUSER_
#تعریف_کن _WINUSER_

#تعریف_کن WINUSERAPI DECLSPEC_IMPORT

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده WINVER
#تعریف_کن WINVER 0x0502
#پایان_اگر

#ضمن <stdarg.h>

#اگر_تعریف_نشده NOUSER
  تعريفنوع HANDLE HDWP;
  تعريفنوع VOID MENUTEMPLATEA;
  تعريفنوع VOID MENUTEMPLATEW;
  تعريفنوع PVOID LPMENUTEMPLATEA;
  تعريفنوع PVOID LPMENUTEMPLATEW;

#اگر_تعریف_شده UNICODE
  تعريفنوع MENUTEMPLATEW MENUTEMPLATE;
  تعريفنوع LPMENUTEMPLATEW LPMENUTEMPLATE;
#وإلا
  تعريفنوع MENUTEMPLATEA MENUTEMPLATE;
  تعريفنوع LPMENUTEMPLATEA LPMENUTEMPLATE;
#پایان_اگر

  تعريفنوع LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
  تعريفنوع INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
  تعريفنوع VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
  تعريفنوع WINBOOL (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,صحيح);
  تعريفنوع WINBOOL (CALLBACK *WNDENUMPROC)(HWND,LPARAM);
  تعريفنوع LRESULT (CALLBACK *HOOKPROC)(صحيح کد,WPARAM wParam,LPARAM lParam);
  تعريفنوع VOID (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
  تعريفنوع WINBOOL (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
  تعريفنوع صحيح (CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch,صحيح ichCurrent,صحيح cch,صحيح کد);
  تعريفنوع صحيح (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch,صحيح ichCurrent,صحيح cch,صحيح کد);
  تعريفنوع WINBOOL (CALLBACK *DRAWSTATEPROC)(HDC hdc,LPARAM l_داده,WPARAM w_داده,صحيح cx,صحيح cy);

#اگر_تعریف_شده UNICODE
  تعريفنوع PROPENUMPROCW PROPENUMPROC;
  تعريفنوع PROPENUMPROCEXW PROPENUMPROCEX;
  تعريفنوع EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#وإلا
  تعريفنوع PROPENUMPROCA PROPENUMPROC;
  تعريفنوع PROPENUMPROCEXA PROPENUMPROCEX;
  تعريفنوع EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#پایان_اگر

  تعريفنوع WINBOOL (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
  تعريفنوع WINBOOL (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
  تعريفنوع NAMEENUMPROCA WINSTAENUMPROCA;
  تعريفنوع NAMEENUMPROCA DESKTOPENUMPROCA;
  تعريفنوع NAMEENUMPROCW WINSTAENUMPROCW;
  تعريفنوع NAMEENUMPROCW DESKTOPENUMPROCW;

#اگر_تعریف_شده UNICODE
  تعريفنوع WINSTAENUMPROCW WINSTAENUMPROC;
  تعريفنوع DESKTOPENUMPROCW DESKTOPENUMPROC;
#وإلا
  تعريفنوع WINSTAENUMPROCA WINSTAENUMPROC;
  تعريفنوع DESKTOPENUMPROCA DESKTOPENUMPROC;
#پایان_اگر

#تعریف_کن IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)
#تعریف_کن MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((کلمه_3)(i))))
#تعریف_کن MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((کلمه_3)(i))))
#اگر_تعریف_شده UNICODE
#تعریف_کن MAKEINTRESOURCE MAKEINTRESOURCEW
#وإلا
#تعریف_کن MAKEINTRESOURCE MAKEINTRESOURCEA
#پایان_اگر

#اگر_تعریف_نشده NORESOURCE

#تعریف_کن RT_CURSOR MAKEINTRESOURCE(1)
#تعریف_کن RT_BITMAP MAKEINTRESOURCE(2)
#تعریف_کن RT_ICON MAKEINTRESOURCE(3)
#تعریف_کن RT_MENU MAKEINTRESOURCE(4)
#تعریف_کن RT_DIALOG MAKEINTRESOURCE(5)
#تعریف_کن RT_STRING MAKEINTRESOURCE(6)
#تعریف_کن RT_FONTDIR MAKEINTRESOURCE(7)
#تعریف_کن RT_FONT MAKEINTRESOURCE(8)
#تعریف_کن RT_ACCELERATOR MAKEINTRESOURCE(9)
#تعریف_کن RT_RCDATA MAKEINTRESOURCE(10)
#تعریف_کن RT_MESSAGETABLE MAKEINTRESOURCE(11)

#تعریف_کن DIFFERENCE 11
#تعریف_کن RT_گروه_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
#تعریف_کن RT_گروه_ICON MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
#تعریف_کن RT_نسخه MAKEINTRESOURCE(16)
#تعریف_کن RT_DLGINCLUDE MAKEINTRESOURCE(17)
#تعریف_کن RT_PLUGPLAY MAKEINTRESOURCE(19)
#تعریف_کن RT_VXD MAKEINTRESOURCE(20)
#تعریف_کن RT_ANICURSOR MAKEINTRESOURCE(21)
#تعریف_کن RT_ANIICON MAKEINTRESOURCE(22)
#تعریف_کن RT_HTML MAKEINTRESOURCE(23)
#اگر_تعریف_شده RC_INVOKED
#تعریف_کن RT_MANIFEST 24
#تعریف_کن CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#تعریف_کن ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#تعریف_کن ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#تعریف_کن MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#تعریف_کن بیشینه_RESERVED_MANIFEST_RESOURCE_ID 16
#وإلا
#تعریف_کن RT_MANIFEST MAKEINTRESOURCE(24)
#تعریف_کن CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#تعریف_کن ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#تعریف_کن ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#تعریف_کن MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#تعریف_کن بیشینه_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن wvsprintf wvsprintfW
#تعریف_کن wsprintf wsprintfW
#وإلا
#تعریف_کن wvsprintf wvsprintfA
#تعریف_کن wsprintf wsprintfA
#پایان_اگر

  WINUSERAPI صحيح WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
  WINUSERAPI صحيح WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);
  WINUSERAPI صحيح WINAPIV wsprintfA(LPSTR,LPCSTR,...);
  WINUSERAPI صحيح WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);

#تعریف_کن SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#اگر_تعریف_نشده NOSCROLL
#تعریف_کن SB_HORZ 0
#تعریف_کن SB_VERT 1
#تعریف_کن SB_CTL 2
#تعریف_کن SB_BOTH 3

#تعریف_کن SB_LINEUP 0
#تعریف_کن SB_LINELEFT 0
#تعریف_کن SB_LINEDOWN 1
#تعریف_کن SB_LINERIGHT 1
#تعریف_کن SB_PAGEUP 2
#تعریف_کن SB_PAGELEFT 2
#تعریف_کن SB_PAGEDOWN 3
#تعریف_کن SB_PAGERIGHT 3
#تعریف_کن SB_THUMBPOSITION 4
#تعریف_کن SB_THUMBTRACK 5
#تعریف_کن SB_بالاترین 6
#تعریف_کن SB_چپ 6
#تعریف_کن SB_BOTTOM 7
#تعریف_کن SB_راست 7
#تعریف_کن SB_ENDSCROLL 8
#پایان_اگر

#اگر_تعریف_نشده NOSHOWWINDOW
#تعریف_کن SW_HIDE 0
#تعریف_کن SW_SHOWNORMAL 1
#تعریف_کن SW_نرمال 1
#تعریف_کن SW_SHOWMINIMIZED 2
#تعریف_کن SW_SHOWMAXIMIZED 3
#تعریف_کن SW_MAXIMIZE 3
#تعریف_کن SW_SHOWNOACTIVATE 4
#تعریف_کن SW_SHOW 5
#تعریف_کن SW_MINIMIZE 6
#تعریف_کن SW_SHOWMINNOACTIVE 7
#تعریف_کن SW_SHOWNA 8
#تعریف_کن SW_RESTORE 9
#تعریف_کن SW_SHOWDEFAULT 10
#تعریف_کن SW_FORCEMINIMIZE 11
#تعریف_کن SW_MAX 11

#تعریف_کن HIDE_پنجره 0
#تعریف_کن SHOW_OPENWINDOW 1
#تعریف_کن SHOW_ICONWINDOW 2
#تعریف_کن SHOW_FULLSCREEN 3
#تعریف_کن SHOW_OPENNOACTIVATE 4

#تعریف_کن SW_PARENTCLOSING 1
#تعریف_کن SW_OTHERZOOM 2
#تعریف_کن SW_PARENTOPENING 3
#تعریف_کن SW_OTHERUNZOOM 4
#پایان_اگر

#تعریف_کن AW_HOR_مثبت 0x00000001
#تعریف_کن AW_HOR_NEGATIVE 0x00000002
#تعریف_کن AW_VER_مثبت 0x00000004
#تعریف_کن AW_VER_NEGATIVE 0x00000008
#تعریف_کن AW_CENTER 0x00000010
#تعریف_کن AW_HIDE 0x00010000
#تعریف_کن AW_ACTIVATE 0x00020000
#تعریف_کن AW_SLIDE 0x00040000
#تعریف_کن AW_BLEND 0x00080000

#تعریف_کن KF_EXTENDED 0x0100
#تعریف_کن KF_DLGMODE 0x0800
#تعریف_کن KF_MENUMODE 0x1000
#تعریف_کن KF_ALTDOWN 0x2000
#تعریف_کن KF_REPEAT 0x4000
#تعریف_کن KF_به_بالا 0x8000

#اگر_تعریف_نشده NOVIRTUALKEYCODES

#تعریف_کن VK_LBUTTON 0x01
#تعریف_کن VK_RBUTTON 0x02
#تعریف_کن VK_CANCEL 0x03
#تعریف_کن VK_MBUTTON 0x04
#تعریف_کن VK_XBUTTON1 0x05
#تعریف_کن VK_XBUTTON2 0x06
#تعریف_کن VK_پشت 0x08
#تعریف_کن VK_TAB 0x09
#تعریف_کن VK_CLEAR 0x0C
#تعریف_کن VK_RETURN 0x0D
#تعریف_کن VK_لغزش 0x10
#تعریف_کن VK_CONTROL 0x11
#تعریف_کن VK_MENU 0x12
#تعریف_کن VK_PAUSE 0x13
#تعریف_کن VK_CAPITAL 0x14
#تعریف_کن VK_KANA 0x15
#تعریف_کن VK_HANGEUL 0x15
#تعریف_کن VK_HANGUL 0x15
#تعریف_کن VK_JUNJA 0x17
#تعریف_کن VK_FINAL 0x18
#تعریف_کن VK_HANJA 0x19
#تعریف_کن VK_KANJI 0x19
#تعریف_کن VK_ESCAPE 0x1B
#تعریف_کن VK_CONVERT 0x1C
#تعریف_کن VK_NONCONVERT 0x1D
#تعریف_کن VK_ACCEPT 0x1E
#تعریف_کن VK_MODECHANGE 0x1F
#تعریف_کن VK_SPACE 0x20
#تعریف_کن VK_پیشین 0x21
#تعریف_کن VK_بعدی 0x22
#تعریف_کن VK_انتها 0x23
#تعریف_کن VK_HOME 0x24
#تعریف_کن VK_چپ 0x25
#تعریف_کن VK_به_بالا 0x26
#تعریف_کن VK_راست 0x27
#تعریف_کن VK_پایین 0x28
#تعریف_کن VK_SELECT 0x29
#تعریف_کن VK_PRINT 0x2A
#تعریف_کن VK_EXECUTE 0x2B
#تعریف_کن VK_SNAPSHOT 0x2C
#تعریف_کن VK_درج 0x2D
#تعریف_کن VK_DELETE 0x2E
#تعریف_کن VK_HELP 0x2F

#تعریف_کن VK_LWIN 0x5B
#تعریف_کن VK_RWIN 0x5C
#تعریف_کن VK_APPS 0x5D
#تعریف_کن VK_SLEEP 0x5F
#تعریف_کن VK_NUMPAD0 0x60
#تعریف_کن VK_NUMPAD1 0x61
#تعریف_کن VK_NUMPAD2 0x62
#تعریف_کن VK_NUMPAD3 0x63
#تعریف_کن VK_NUMPAD4 0x64
#تعریف_کن VK_NUMPAD5 0x65
#تعریف_کن VK_NUMPAD6 0x66
#تعریف_کن VK_NUMPAD7 0x67
#تعریف_کن VK_NUMPAD8 0x68
#تعریف_کن VK_NUMPAD9 0x69
#تعریف_کن VK_MULTIPLY 0x6A
#تعریف_کن VK_جمع_کن 0x6B
#تعریف_کن VK_SEPARATOR 0x6C
#تعریف_کن VK_تفریق 0x6D
#تعریف_کن VK_DECIMAL 0x6E
#تعریف_کن VK_DIVIDE 0x6F
#تعریف_کن VK_F1 0x70
#تعریف_کن VK_F2 0x71
#تعریف_کن VK_F3 0x72
#تعریف_کن VK_F4 0x73
#تعریف_کن VK_F5 0x74
#تعریف_کن VK_F6 0x75
#تعریف_کن VK_F7 0x76
#تعریف_کن VK_F8 0x77
#تعریف_کن VK_F9 0x78
#تعریف_کن VK_F10 0x79
#تعریف_کن VK_F11 0x7A
#تعریف_کن VK_F12 0x7B
#تعریف_کن VK_F13 0x7C
#تعریف_کن VK_F14 0x7D
#تعریف_کن VK_F15 0x7E
#تعریف_کن VK_F16 0x7F
#تعریف_کن VK_F17 0x80
#تعریف_کن VK_F18 0x81
#تعریف_کن VK_F19 0x82
#تعریف_کن VK_F20 0x83
#تعریف_کن VK_F21 0x84
#تعریف_کن VK_F22 0x85
#تعریف_کن VK_F23 0x86
#تعریف_کن VK_F24 0x87
#تعریف_کن VK_NUMLOCK 0x90
#تعریف_کن VK_SCROLL 0x91
#تعریف_کن VK_OEM_NEC_EQUAL 0x92
#تعریف_کن VK_OEM_FJ_JISHO 0x92
#تعریف_کن VK_OEM_FJ_MASSHOU 0x93
#تعریف_کن VK_OEM_FJ_TOUROKU 0x94
#تعریف_کن VK_OEM_FJ_LOYA 0x95
#تعریف_کن VK_OEM_FJ_ROYA 0x96
#تعریف_کن VK_LSHIFT 0xA0
#تعریف_کن VK_RSHIFT 0xA1
#تعریف_کن VK_LCONTROL 0xA2
#تعریف_کن VK_RCONTROL 0xA3
#تعریف_کن VK_LMENU 0xA4
#تعریف_کن VK_RMENU 0xA5
#تعریف_کن VK_BROWSER_پشت 0xA6
#تعریف_کن VK_BROWSER_FORWARD 0xA7
#تعریف_کن VK_BROWSER_REFRESH 0xA8
#تعریف_کن VK_BROWSER_STOP 0xA9
#تعریف_کن VK_BROWSER_جستجو 0xAA
#تعریف_کن VK_BROWSER_FAVORITES 0xAB
#تعریف_کن VK_BROWSER_HOME 0xAC
#تعریف_کن VK_VOLUME_MUTE 0xAD
#تعریف_کن VK_VOLUME_پایین 0xAE
#تعریف_کن VK_VOLUME_به_بالا 0xAF
#تعریف_کن VK_MEDIA_بعدی_TRACK 0xB0
#تعریف_کن VK_MEDIA_PREV_TRACK 0xB1
#تعریف_کن VK_MEDIA_STOP 0xB2
#تعریف_کن VK_MEDIA_PLAY_PAUSE 0xB3
#تعریف_کن VK_LAUNCH_MAIL 0xB4
#تعریف_کن VK_LAUNCH_MEDIA_SELECT 0xB5
#تعریف_کن VK_LAUNCH_APP1 0xB6
#تعریف_کن VK_LAUNCH_APP2 0xB7
#تعریف_کن VK_OEM_1 0xBA
#تعریف_کن VK_OEM_PLUS 0xBB
#تعریف_کن VK_OEM_COMMA 0xBC
#تعریف_کن VK_OEM_MINUS 0xBD
#تعریف_کن VK_OEM_PERIOD 0xBE
#تعریف_کن VK_OEM_2 0xBF
#تعریف_کن VK_OEM_3 0xC0
#تعریف_کن VK_OEM_4 0xDB
#تعریف_کن VK_OEM_5 0xDC
#تعریف_کن VK_OEM_6 0xDD
#تعریف_کن VK_OEM_7 0xDE
#تعریف_کن VK_OEM_8 0xDF
#تعریف_کن VK_OEM_AX 0xE1
#تعریف_کن VK_OEM_102 0xE2
#تعریف_کن VK_ICO_HELP 0xE3
#تعریف_کن VK_ICO_00 0xE4
#تعریف_کن VK_PROCESSKEY 0xE5
#تعریف_کن VK_ICO_CLEAR 0xE6
#تعریف_کن VK_PACKET 0xE7
#تعریف_کن VK_OEM_RESET 0xE9
#تعریف_کن VK_OEM_JUMP 0xEA
#تعریف_کن VK_OEM_PA1 0xEB
#تعریف_کن VK_OEM_PA2 0xEC
#تعریف_کن VK_OEM_PA3 0xED
#تعریف_کن VK_OEM_WSCTRL 0xEE
#تعریف_کن VK_OEM_CUSEL 0xEF
#تعریف_کن VK_OEM_ATTN 0xF0
#تعریف_کن VK_OEM_پایان 0xF1
#تعریف_کن VK_OEM_COPY 0xF2
#تعریف_کن VK_OEM_AUTO 0xF3
#تعریف_کن VK_OEM_ENLW 0xF4
#تعریف_کن VK_OEM_BACKTAB 0xF5
#تعریف_کن VK_ATTN 0xF6
#تعریف_کن VK_CRSEL 0xF7
#تعریف_کن VK_EXSEL 0xF8
#تعریف_کن VK_EREOF 0xF9
#تعریف_کن VK_PLAY 0xFA
#تعریف_کن VK_ZOOM 0xFB
#تعریف_کن VK_NONAME 0xFC
#تعریف_کن VK_PA1 0xFD
#تعریف_کن VK_OEM_CLEAR 0xFE
#پایان_اگر

#اگر_تعریف_نشده NOWH

#تعریف_کن WH_MIN (-1)
#تعریف_کن WH_MSGFILTER (-1)
#تعریف_کن WH_JOURNALRECORD 0
#تعریف_کن WH_JOURNALPLAYBACK 1
#تعریف_کن WH_KEYBOARD 2
#تعریف_کن WH_GETMESSAGE 3
#تعریف_کن WH_CALLWNDPROC 4
#تعریف_کن WH_CBT 5
#تعریف_کن WH_SYSMSGFILTER 6
#تعریف_کن WH_MOUSE 7
#تعریف_کن WH_HARDWARE 8
#تعریف_کن WH_DEBUG 9
#تعریف_کن WH_SHELL 10
#تعریف_کن WH_FOREGROUNDIDLE 11
#تعریف_کن WH_CALLWNDPROCRET 12

#تعریف_کن WH_KEYBOARD_LL 13
#تعریف_کن WH_MOUSE_LL 14

#تعریف_کن WH_MAX 14

#تعریف_کن WH_MINHOOK WH_MIN
#تعریف_کن WH_MAXHOOK WH_MAX

#تعریف_کن HC_ACTION 0
#تعریف_کن HC_GETNEXT 1
#تعریف_کن HC_SKIP 2
#تعریف_کن HC_NOREMOVE 3
#تعریف_کن HC_NOREM HC_NOREMOVE
#تعریف_کن HC_SYSMODALON 4
#تعریف_کن HC_SYSMODALOFF 5

#تعریف_کن HCBT_MOVESIZE 0
#تعریف_کن HCBT_MINMAX 1
#تعریف_کن HCBT_QS 2
#تعریف_کن HCBT_CREATEWND 3
#تعریف_کن HCBT_DESTROYWND 4
#تعریف_کن HCBT_ACTIVATE 5
#تعریف_کن HCBT_CLICKSKIPPED 6
#تعریف_کن HCBT_KEYSKIPPED 7
#تعریف_کن HCBT_SYSCOMMAND 8
#تعریف_کن HCBT_SETFOCUS 9

  تعريفنوع بنية برچسب_CBT_CREATEWNDA {
    بنية برچسب_CREATESTRUCTA *lpcs;
    HWND hwnd_درج_After;
  } CBT_CREATEWNDA,*LPCBT_CREATEWNDA;

  تعريفنوع بنية برچسب_CBT_CREATEWNDW {
    بنية برچسب_CREATESTRUCTW *lpcs;
    HWND hwnd_درج_After;
  } CBT_CREATEWNDW,*LPCBT_CREATEWNDW;
#اگر_تعریف_شده UNICODE
  تعريفنوع CBT_CREATEWNDW CBT_CREATEWND;
  تعريفنوع LPCBT_CREATEWNDW LPCBT_CREATEWND;
#وإلا
  تعريفنوع CBT_CREATEWNDA CBT_CREATEWND;
  تعريفنوع LPCBT_CREATEWNDA LPCBT_CREATEWND;
#پایان_اگر

  تعريفنوع بنية برچسب_CBTACTIVATESTRUCT
  {
    WINBOOL fMouse;
    HWND h_Wnd_فعال;
  } CBTACTIVATESTRUCT,*LPCBTACTIVATESTRUCT;

  تعريفنوع بنية برچسب_WTSSESSION_NOTIFICATION {
    DWORD cb_اندازه;
    DWORD dwSessionId;

  } WTSSESSION_NOTIFICATION,*PWTSSESSION_NOTIFICATION;

#تعریف_کن WTS_CONSOLE_CONNECT 0x1
#تعریف_کن WTS_CONSOLE_DISCONNECT 0x2
#تعریف_کن WTS_REMOTE_CONNECT 0x3
#تعریف_کن WTS_REMOTE_DISCONNECT 0x4
#تعریف_کن WTS_SESSION_LOGON 0x5
#تعریف_کن WTS_SESSION_LOGOFF 0x6
#تعریف_کن WTS_SESSION_قفل 0x7
#تعریف_کن WTS_SESSION_UNLOCK 0x8
#تعریف_کن WTS_SESSION_REMOTE_CONTROL 0x9

#تعریف_کن MSGF_DIALOGBOX 0
#تعریف_کن MSGF_MESSAGEBOX 1
#تعریف_کن MSGF_MENU 2
#تعریف_کن MSGF_SCROLLBAR 5
#تعریف_کن MSGF_NEXTWINDOW 6
#تعریف_کن MSGF_MAX 8
#تعریف_کن MSGF_USER 4096

#تعریف_کن HSHELL_WINDOWCREATED 1
#تعریف_کن HSHELL_WINDOWDESTROYED 2
#تعریف_کن HSHELL_ACTIVATESHELLWINDOW 3

#تعریف_کن HSHELL_WINDOWACTIVATED 4
#تعریف_کن HSHELL_GETMINRECT 5
#تعریف_کن HSHELL_REDRAW 6
#تعریف_کن HSHELL_TASKMAN 7
#تعریف_کن HSHELL_LANGUAGE 8
#تعریف_کن HSHELL_SYSMENU 9
#تعریف_کن HSHELL_ENDTASK 10
#تعریف_کن HSHELL_ACCESSIBILITYSTATE 11
#تعریف_کن HSHELL_APPCOMMAND 12
#تعریف_کن HSHELL_WINDOWREPLACED 13
#تعریف_کن HSHELL_WINDOWREPLACING 14
#تعریف_کن HSHELL_HIGHBIT 0x8000
#تعریف_کن HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#تعریف_کن HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#تعریف_کن ACCESS_STICKYKEYS 0x0001
#تعریف_کن ACCESS_FILTERKEYS 0x0002
#تعریف_کن ACCESS_MOUSEKEYS 0x0003

#تعریف_کن APPCOMMAND_BROWSER_BACKWARD 1
#تعریف_کن APPCOMMAND_BROWSER_FORWARD 2
#تعریف_کن APPCOMMAND_BROWSER_REFRESH 3
#تعریف_کن APPCOMMAND_BROWSER_STOP 4
#تعریف_کن APPCOMMAND_BROWSER_جستجو 5
#تعریف_کن APPCOMMAND_BROWSER_FAVORITES 6
#تعریف_کن APPCOMMAND_BROWSER_HOME 7
#تعریف_کن APPCOMMAND_VOLUME_MUTE 8
#تعریف_کن APPCOMMAND_VOLUME_پایین 9
#تعریف_کن APPCOMMAND_VOLUME_به_بالا 10
#تعریف_کن APPCOMMAND_MEDIA_NEXTTRACK 11
#تعریف_کن APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#تعریف_کن APPCOMMAND_MEDIA_STOP 13
#تعریف_کن APPCOMMAND_MEDIA_PLAY_PAUSE 14
#تعریف_کن APPCOMMAND_LAUNCH_MAIL 15
#تعریف_کن APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#تعریف_کن APPCOMMAND_LAUNCH_APP1 17
#تعریف_کن APPCOMMAND_LAUNCH_APP2 18
#تعریف_کن APPCOMMAND_BASS_پایین 19
#تعریف_کن APPCOMMAND_BASS_BOOST 20
#تعریف_کن APPCOMMAND_BASS_به_بالا 21
#تعریف_کن APPCOMMAND_TREBLE_پایین 22
#تعریف_کن APPCOMMAND_TREBLE_به_بالا 23
#تعریف_کن APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#تعریف_کن APPCOMMAND_MICROPHONE_VOLUME_پایین 25
#تعریف_کن APPCOMMAND_MICROPHONE_VOLUME_به_بالا 26
#تعریف_کن APPCOMMAND_HELP 27
#تعریف_کن APPCOMMAND_پیدا_کن 28
#تعریف_کن APPCOMMAND_NEW 29
#تعریف_کن APPCOMMAND_OPEN 30
#تعریف_کن APPCOMMAND_CLOSE 31
#تعریف_کن APPCOMMAND_SAVE 32
#تعریف_کن APPCOMMAND_PRINT 33
#تعریف_کن APPCOMMAND_UNDO 34
#تعریف_کن APPCOMMAND_REDO 35
#تعریف_کن APPCOMMAND_COPY 36
#تعریف_کن APPCOMMAND_CUT 37
#تعریف_کن APPCOMMAND_PASTE 38
#تعریف_کن APPCOMMAND_پاسخ_مقصد_MAIL 39
#تعریف_کن APPCOMMAND_FORWARD_MAIL 40
#تعریف_کن APPCOMMAND_SEND_MAIL 41
#تعریف_کن APPCOMMAND_SPELL_CHECK 42
#تعریف_کن APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#تعریف_کن APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#تعریف_کن APPCOMMAND_CORRECTION_LIST 45
#تعریف_کن APPCOMMAND_MEDIA_PLAY 46
#تعریف_کن APPCOMMAND_MEDIA_PAUSE 47
#تعریف_کن APPCOMMAND_MEDIA_رکورد 48
#تعریف_کن APPCOMMAND_MEDIA_FAST_FORWARD 49
#تعریف_کن APPCOMMAND_MEDIA_REWIND 50
#تعریف_کن APPCOMMAND_MEDIA_CHANNEL_به_بالا 51
#تعریف_کن APPCOMMAND_MEDIA_CHANNEL_پایین 52

#تعریف_کن FAPPCOMMAND_MOUSE 0x8000
#تعریف_کن FAPPCOMMAND_کلید 0
#تعریف_کن FAPPCOMMAND_OEM 0x1000
#تعریف_کن FAPPCOMMAND_ماسک 0xF000

#تعریف_کن GET_APPCOMMAND_LPARAM(lParam) ((کوتاه)(HIWORD(lParam) & ~FAPPCOMMAND_ماسک))
#تعریف_کن GET_DEVICE_LPARAM(lParam) ((کلمه_3)(HIWORD(lParam) & FAPPCOMMAND_ماسک))
#تعریف_کن GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#تعریف_کن GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#تعریف_کن GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)

  تعريفنوع بنية {
    HWND hwnd;
    RECT rc;
  } SHELLHOOKINFO,*LPSHELLHOOKINFO;

  تعريفنوع بنية برچسب_EVENTMSG {
    UINT پیام_2;
    UINT paramL;
    UINT paramH;
    DWORD زمان;
    HWND hwnd;
  } EVENTMSG,*PEVENTMSGMSG,*NPEVENTMSGMSG,*LPEVENTMSGMSG;

  تعريفنوع بنية برچسب_EVENTMSG *PEVENTMSG,*NPEVENTMSG,*LPEVENTMSG;

  تعريفنوع بنية برچسب_CWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT پیام_2;
    HWND hwnd;
  } CWPSTRUCT,*PCWPSTRUCT,*NPCWPSTRUCT,*LPCWPSTRUCT;

  تعريفنوع بنية برچسب_CWPRETSTRUCT {
    LRESULT l_نتیجه;
    LPARAM lParam;
    WPARAM wParam;
    UINT پیام_2;
    HWND hwnd;
  } CWPRETSTRUCT,*PCWPRETSTRUCT,*NPCWPRETSTRUCT,*LPCWPRETSTRUCT;

#تعریف_کن LLKHF_EXTENDED (KF_EXTENDED >> 8)
#تعریف_کن LLKHF_INJECTED 0x00000010
#تعریف_کن LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#تعریف_کن LLKHF_به_بالا (KF_به_بالا >> 8)

#تعریف_کن LLMHF_INJECTED 0x00000001

  تعريفنوع بنية برچسب_KBDLLHOOKSTRUCT {
    DWORD vk_کد;
    DWORD پیمایش_کد;
    DWORD flags;
    DWORD زمان;
    ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;

  تعريفنوع بنية برچسب_MSLLHOOKSTRUCT {
    نقطه_3 pt;
    DWORD mouse_داده;
    DWORD flags;
    DWORD زمان;
    ULONG_PTR dwExtraInfo;
  } MSLLHOOKSTRUCT,*LPMSLLHOOKSTRUCT,*PMSLLHOOKSTRUCT;

  تعريفنوع بنية برچسب_DEBUGHOOKINFO {
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    صحيح کد;
  } DEBUGHOOKINFO,*PDEBUGHOOKINFO,*NPDEBUGHOOKINFO,*LPDEBUGHOOKINFO;

  تعريفنوع بنية برچسب_MOUSEHOOKSTRUCT {
    نقطه_3 pt;
    HWND hwnd;
    UINT w_اصابت_Test_کد;
    ULONG_PTR dwExtraInfo;
  } MOUSEHOOKSTRUCT,*LPMOUSEHOOKSTRUCT,*PMOUSEHOOKSTRUCT;

#اگر_تعریف_شده __cplusplus
  تعريفنوع بنية برچسب_MOUSEHOOKSTRUCTEX : عام برچسب_MOUSEHOOKSTRUCT {
    DWORD mouse_داده;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#وإلا
  تعريفنوع بنية برچسب_MOUSEHOOKSTRUCTEX {
    MOUSEHOOKSTRUCT _unnamed;
    DWORD mouse_داده;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#پایان_اگر

  تعريفنوع بنية برچسب_HARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT پیام_2;
    WPARAM wParam;
    LPARAM lParam;
  } HARDWAREHOOKSTRUCT,*LPHARDWAREHOOKSTRUCT,*PHARDWAREHOOKSTRUCT;
#پایان_اگر

#تعریف_کن HKL_PREV 0
#تعریف_کن HKL_بعدی 1

#تعریف_کن KLF_ACTIVATE 0x00000001
#تعریف_کن KLF_SUBSTITUTE_OK 0x00000002
#تعریف_کن KLF_REORDER 0x00000008
#تعریف_کن KLF_REPLACELANG 0x00000010
#تعریف_کن KLF_NOTELLSHELL 0x00000080
#تعریف_کن KLF_SETFORPROCESS 0x00000100
#تعریف_کن KLF_SHIFTLOCK 0x00010000
#تعریف_کن KLF_RESET 0x40000000

#تعریف_کن INPUTLANGCHANGE_SYSCHARSET 0x0001
#تعریف_کن INPUTLANGCHANGE_FORWARD 0x0002
#تعریف_کن INPUTLANGCHANGE_BACKWARD 0x0004

#تعریف_کن KL_NAMELENGTH 9

#اگر_تعریف_شده UNICODE
#تعریف_کن بارگیری_Keyboard_Layout بارگیری_Keyboard_Layout_W
#تعریف_کن GetKeyboardLayoutName GetKeyboardLayoutNameW
#وإلا
#تعریف_کن بارگیری_Keyboard_Layout بارگیری_Keyboard_Layout_A
#تعریف_کن GetKeyboardLayoutName GetKeyboardLayoutNameA
#پایان_اگر

  WINUSERAPI HKL WINAPI بارگیری_Keyboard_Layout_A(LPCSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI بارگیری_Keyboard_Layout_W(LPCWSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ActivateKeyboardLayout(HKL hkl,UINT Flags);
  WINUSERAPI صحيح WINAPI مقصد_Unicode_Ex(UINT w_Virt_کلید,UINT w_پیمایش_کد,CONST BYTE *lp_کلید_State,LPWSTR pwszBuff,صحيح cchBuff,UINT wFlags,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI UnloadKeyboardLayout(HKL hkl);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameA(LPSTR pwszKLID);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameW(LPWSTR pwszKLID);
  WINUSERAPI صحيح WINAPI GetKeyboardLayoutList(صحيح nBuff,HKL *lpList);
  WINUSERAPI HKL WINAPI GetKeyboardLayout(DWORD idThread);

  تعريفنوع بنية برچسب_MOUSEMOVEPOINT {
    صحيح x;
    صحيح y;
    DWORD زمان;
    ULONG_PTR dwExtraInfo;
  } MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

#تعریف_کن GMMP_USE_DISPLAY_POINTS 1
#تعریف_کن GMMP_USE_بالا_RESOLUTION_POINTS 2

  WINUSERAPI صحيح WINAPI GetMouseMovePointsEx(UINT cb_اندازه,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,صحيح nBufPoints,DWORD resolution);

#اگر_تعریف_نشده NODESKTOP

#تعریف_کن DESKTOP_READOBJECTS 0x0001L
#تعریف_کن DESKTOP_CREATEWINDOW 0x0002L
#تعریف_کن DESKTOP_CREATEMENU 0x0004L
#تعریف_کن DESKTOP_HOOKCONTROL 0x0008L
#تعریف_کن DESKTOP_JOURNALRECORD 0x0010L
#تعریف_کن DESKTOP_JOURNALPLAYBACK 0x0020L
#تعریف_کن DESKTOP_ENUMERATE 0x0040L
#تعریف_کن DESKTOP_WRITEOBJECTS 0x0080L
#تعریف_کن DESKTOP_SWITCHDESKTOP 0x0100L

#تعریف_کن DF_ALLOWOTHERACCOUNTHOOK 0x0001L

#اگر_تعریف_شده _WINGDI_
#اگر_تعریف_نشده NOGDI
#اگر_تعریف_شده UNICODE
#تعریف_کن CreateDesktop CreateDesktopW
#وإلا
#تعریف_کن CreateDesktop CreateDesktopA
#پایان_اگر

  WINUSERAPI HDESK WINAPI CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,LPDEVMODEA pDevmode,DWORD dwFlags,ACCESS_ماسک dwDesiredAccess,LPSECURITY_صفات lpsa);
  WINUSERAPI HDESK WINAPI CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,LPDEVMODEW pDevmode,DWORD dwFlags,ACCESS_ماسک dwDesiredAccess,LPSECURITY_صفات lpsa);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن OpenDesktop OpenDesktopW
#تعریف_کن EnumDesktops EnumDesktopsW
#وإلا
#تعریف_کن OpenDesktop OpenDesktopA
#تعریف_کن EnumDesktops EnumDesktopsA
#پایان_اگر

  WINUSERAPI HDESK WINAPI OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI HDESK WINAPI Open_درون_داد_Desktop(DWORD dwFlags,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SwitchDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI مجموعه_Thread_Desktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI CloseDesktop(HDESK hDesktop);
  WINUSERAPI HDESK WINAPI GetThreadDesktop(DWORD dwThreadId);
#پایان_اگر

#اگر_تعریف_نشده NOWINDOWSTATION
#تعریف_کن WINSTA_ENUMDESKTOPS 0x0001L
#تعریف_کن WINSTA_READATTRIBUTES 0x0002L
#تعریف_کن WINSTA_ACCESSCLIPBOARD 0x0004L
#تعریف_کن WINSTA_CREATEDESKTOP 0x0008L
#تعریف_کن WINSTA_WRITEATTRIBUTES 0x0010L
#تعریف_کن WINSTA_ACCESSGLOBALATOMS 0x0020L
#تعریف_کن WINSTA_EXITWINDOWS 0x0040L
#تعریف_کن WINSTA_ENUMERATE 0x0100L
#تعریف_کن WINSTA_READSCREEN 0x0200L
#تعریف_کن WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#تعریف_کن CWF_CREATE_ONLY 0x0001L

#تعریف_کن WSF_VISIBLE 0x0001L

#اگر_تعریف_شده UNICODE
#تعریف_کن Create_پنجره_Station Create_پنجره_Station_W
#تعریف_کن Open_پنجره_Station Open_پنجره_Station_W
#تعریف_کن Enum_پنجره_Stations Enum_پنجره_Stations_W
#وإلا
#تعریف_کن Create_پنجره_Station Create_پنجره_Station_A
#تعریف_کن Open_پنجره_Station Open_پنجره_Station_A
#تعریف_کن Enum_پنجره_Stations Enum_پنجره_Stations_A
#پایان_اگر

  WINUSERAPI HWINSTA WINAPI Create_پنجره_Station_A(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_ماسک dwDesiredAccess,LPSECURITY_صفات lpsa);
  WINUSERAPI HWINSTA WINAPI Create_پنجره_Station_W(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_ماسک dwDesiredAccess,LPSECURITY_صفات lpsa);
  WINUSERAPI HWINSTA WINAPI Open_پنجره_Station_A(LPCSTR lpszWinSta,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI HWINSTA WINAPI Open_پنجره_Station_W(LPCWSTR lpszWinSta,WINBOOL fInherit,ACCESS_ماسک dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI Enum_پنجره_Stations_A(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Enum_پنجره_Stations_W(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Close_پنجره_Station(HWINSTA hWinSta);
  WINUSERAPI WINBOOL WINAPI مجموعه_Process_پنجره_Station(HWINSTA hWinSta);
  WINUSERAPI HWINSTA WINAPI Get_Process_پنجره_Station(VOID);
#پایان_اگر

#اگر_تعریف_نشده NOSECURITY
  WINUSERAPI WINBOOL WINAPI مجموعه_User_Object_Security(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
  WINUSERAPI WINBOOL WINAPI GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD n_درازی,LPDWORD lpn_درازی_Needed);

#تعریف_کن UOI_FLAGS 1
#تعریف_کن UOI_NAME 2
#تعریف_کن UOI_TYPE 3
#تعریف_کن UOI_USER_SID 4

  تعريفنوع بنية برچسب_USEROBJECTFLAGS {
    WINBOOL fInherit;
    WINBOOL fReserved;
    DWORD dwFlags;
  } USEROBJECTFLAGS,*PUSEROBJECTFLAGS;

#اگر_تعریف_شده UNICODE
#تعریف_کن GetUserObjectInformation GetUserObjectInformationW
#تعریف_کن مجموعه_User_Object_Information مجموعه_User_Object_Information_W
#وإلا
#تعریف_کن GetUserObjectInformation GetUserObjectInformationA
#تعریف_کن مجموعه_User_Object_Information مجموعه_User_Object_Information_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationA(HANDLE hObj,صحيح n_شاخص,PVOID pvInfo,DWORD n_درازی,LPDWORD lpn_درازی_Needed);
  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationW(HANDLE hObj,صحيح n_شاخص,PVOID pvInfo,DWORD n_درازی,LPDWORD lpn_درازی_Needed);
  WINUSERAPI WINBOOL WINAPI مجموعه_User_Object_Information_A(HANDLE hObj,صحيح n_شاخص,PVOID pvInfo,DWORD n_درازی);
  WINUSERAPI WINBOOL WINAPI مجموعه_User_Object_Information_W(HANDLE hObj,صحيح n_شاخص,PVOID pvInfo,DWORD n_درازی);
#پایان_اگر

  تعريفنوع بنية برچسب_WNDCLASSEXA {
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

  تعريفنوع بنية برچسب_WNDCLASSEXW {
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

#اگر_تعریف_شده UNICODE
  تعريفنوع WNDCLASSEXW WNDCLASSEX;
  تعريفنوع PWNDCLASSEXW PWNDCLASSEX;
  تعريفنوع NPWNDCLASSEXW NPWNDCLASSEX;
  تعريفنوع LPWNDCLASSEXW LPWNDCLASSEX;
#وإلا
  تعريفنوع WNDCLASSEXA WNDCLASSEX;
  تعريفنوع PWNDCLASSEXA PWNDCLASSEX;
  تعريفنوع NPWNDCLASSEXA NPWNDCLASSEX;
  تعريفنوع LPWNDCLASSEXA LPWNDCLASSEX;
#پایان_اگر

  تعريفنوع بنية برچسب_WNDCLASSA {
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

  تعريفنوع بنية برچسب_WNDCLASSW {
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

#اگر_تعریف_شده UNICODE
  تعريفنوع WNDCLASSW WNDCLASS;
  تعريفنوع PWNDCLASSW PWNDCLASS;
  تعريفنوع NPWNDCLASSW NPWNDCLASS;
  تعريفنوع LPWNDCLASSW LPWNDCLASS;
#وإلا
  تعريفنوع WNDCLASSA WNDCLASS;
  تعريفنوع PWNDCLASSA PWNDCLASS;
  تعريفنوع NPWNDCLASSA NPWNDCLASS;
  تعريفنوع LPWNDCLASSA LPWNDCLASS;
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI Is_Hung_App_پنجره(HWND hwnd);
  WINUSERAPI VOID WINAPI DisableProcessWindowsGhosting(VOID);

#اگر_تعریف_نشده NOMSG
  تعريفنوع بنية برچسب_پیام {
    HWND hwnd;
    UINT پیام_2;
    WPARAM wParam;
    LPARAM lParam;
    DWORD زمان;
    نقطه_3 pt;
  } پیام_3,*PMSG,*NPMSG,*LPMSG;

#تعریف_کن POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#تعریف_کن POINTTOPOINTS(pt) (MAKELONG((کوتاه)((pt).x),(کوتاه)((pt).y)))
#تعریف_کن MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#تعریف_کن MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#تعریف_کن MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))
#پایان_اگر

#اگر_تعریف_نشده NOWINOFFSETS
#تعریف_کن GWL_WNDPROC (-4)
#تعریف_کن GWL_HINSTANCE (-6)
#تعریف_کن GWL_HWNDPARENT (-8)
#تعریف_کن GWL_STYLE (-16)
#تعریف_کن GWL_EXSTYLE (-20)
#تعریف_کن GWL_USERDATA (-21)
#تعریف_کن GWL_ID (-12)

#اگر_تعریف_شده _WIN64
#لغو_تعریف GWL_WNDPROC
#لغو_تعریف GWL_HINSTANCE
#لغو_تعریف GWL_HWNDPARENT
#لغو_تعریف GWL_USERDATA
#پایان_اگر

#تعریف_کن GWLP_WNDPROC (-4)
#تعریف_کن GWLP_HINSTANCE (-6)
#تعریف_کن GWLP_HWNDPARENT (-8)
#تعریف_کن GWLP_USERDATA (-21)
#تعریف_کن GWLP_ID (-12)

#تعریف_کن GCL_MENUNAME (-8)
#تعریف_کن GCL_HBRBACKGROUND (-10)
#تعریف_کن GCL_HCURSOR (-12)
#تعریف_کن GCL_HICON (-14)
#تعریف_کن GCL_HMODULE (-16)
#تعریف_کن GCL_CBWNDEXTRA (-18)
#تعریف_کن GCL_CBCLSEXTRA (-20)
#تعریف_کن GCL_WNDPROC (-24)
#تعریف_کن GCL_STYLE (-26)
#تعریف_کن GCW_ATOM (-32)
#تعریف_کن GCL_HICONSM (-34)

#اگر_تعریف_شده _WIN64

#لغو_تعریف GCL_MENUNAME
#لغو_تعریف GCL_HBRBACKGROUND
#لغو_تعریف GCL_HCURSOR
#لغو_تعریف GCL_HICON
#لغو_تعریف GCL_HMODULE
#لغو_تعریف GCL_WNDPROC
#لغو_تعریف GCL_HICONSM
#پایان_اگر

#تعریف_کن GCLP_MENUNAME (-8)
#تعریف_کن GCLP_HBRBACKGROUND (-10)
#تعریف_کن GCLP_HCURSOR (-12)
#تعریف_کن GCLP_HICON (-14)
#تعریف_کن GCLP_HMODULE (-16)
#تعریف_کن GCLP_WNDPROC (-24)
#تعریف_کن GCLP_HICONSM (-34)
#پایان_اگر

#اگر_تعریف_نشده NOWINMESSAGES

#تعریف_کن WM_NULL 0x0000
#تعریف_کن WM_CREATE 0x0001
#تعریف_کن WM_DESTROY 0x0002
#تعریف_کن WM_MOVE 0x0003
#تعریف_کن WM_اندازه 0x0005

#تعریف_کن WM_ACTIVATE 0x0006

#تعریف_کن WA_INACTIVE 0
#تعریف_کن WA_فعال 1
#تعریف_کن WA_CLICKACTIVE 2

#تعریف_کن WM_SETFOCUS 0x0007
#تعریف_کن WM_KILLFOCUS 0x0008
#تعریف_کن WM_ENABLE 0x000A
#تعریف_کن WM_SETREDRAW 0x000B
#تعریف_کن WM_SETTEXT 0x000C
#تعریف_کن WM_GETTEXT 0x000D
#تعریف_کن WM_GETTEXTLENGTH 0x000E
#تعریف_کن WM_PAINT 0x000F
#تعریف_کن WM_CLOSE 0x0010
#اگر_تعریف_نشده _WIN32_WCE
#تعریف_کن WM_QUERYENDSESSION 0x0011
#تعریف_کن WM_QUERYOPEN 0x0013
#تعریف_کن WM_ENDSESSION 0x0016
#پایان_اگر
#تعریف_کن WM_QUIT 0x0012
#تعریف_کن WM_ERASEBKGND 0x0014
#تعریف_کن WM_SYSCOLORCHANGE 0x0015
#تعریف_کن WM_SHOWWINDOW 0x0018
#تعریف_کن WM_WININICHANGE 0x001A
#تعریف_کن WM_SETTINGCHANGE WM_WININICHANGE
#تعریف_کن WM_DEVMODECHANGE 0x001B
#تعریف_کن WM_ACTIVATEAPP 0x001C
#تعریف_کن WM_FONTCHANGE 0x001D
#تعریف_کن WM_TIMECHANGE 0x001E
#تعریف_کن WM_CANCELMODE 0x001F
#تعریف_کن WM_SETCURSOR 0x0020
#تعریف_کن WM_MOUSEACTIVATE 0x0021
#تعریف_کن WM_CHILDACTIVATE 0x0022
#تعریف_کن WM_QUEUESYNC 0x0023

#تعریف_کن WM_GETMINMAXINFO 0x0024

  تعريفنوع بنية برچسب_MINMAXINFO {
    نقطه_3 ptReserved;
    نقطه_3 pt_Max_اندازه;
    نقطه_3 ptMaxPosition;
    نقطه_3 pt_Min_Track_اندازه;
    نقطه_3 pt_Max_Track_اندازه;
  } MINMAXINFO,*PMINMAXINFO,*LPMINMAXINFO;

#تعریف_کن WM_PAINTICON 0x0026
#تعریف_کن WM_ICONERASEBKGND 0x0027
#تعریف_کن WM_NEXTDLGCTL 0x0028
#تعریف_کن WM_SPOOLERSTATUS 0x002A
#تعریف_کن WM_DRAWITEM 0x002B
#تعریف_کن WM_MEASUREITEM 0x002C
#تعریف_کن WM_DELETEITEM 0x002D
#تعریف_کن WM_VKEYTOITEM 0x002E
#تعریف_کن WM_CHARTOITEM 0x002F
#تعریف_کن WM_SETFONT 0x0030
#تعریف_کن WM_GETFONT 0x0031
#تعریف_کن WM_SETHOTKEY 0x0032
#تعریف_کن WM_GETHOTKEY 0x0033
#تعریف_کن WM_QUERYDRAGICON 0x0037
#تعریف_کن WM_COMPAREITEM 0x0039
#اگر_تعریف_نشده _WIN32_WCE
#تعریف_کن WM_GETOBJECT 0x003D
#پایان_اگر
#تعریف_کن WM_COMPACTING 0x0041
#تعریف_کن WM_COMMNOTIFY 0x0044
#تعریف_کن WM_WINDOWPOSCHANGING 0x0046
#تعریف_کن WM_WINDOWPOSCHANGED 0x0047

#تعریف_کن WM_POWER 0x0048

#تعریف_کن PWR_OK 1
#تعریف_کن PWR_FAIL (-1)
#تعریف_کن PWR_SUSPENDREQUEST 1
#تعریف_کن PWR_SUSPENDRESUME 2
#تعریف_کن PWR_CRITICALRESUME 3

#تعریف_کن WM_COPYDATA 0x004A
#تعریف_کن WM_CANCELJOURNAL 0x004B

  تعريفنوع بنية برچسب_COPYDATASTRUCT {
    ULONG_PTR dw_داده;
    DWORD cb_داده;
    PVOID lp_داده;
  } COPYDATASTRUCT,*PCOPYDATASTRUCT;

  تعريفنوع بنية برچسب_MDINEXTMENU {
    HMENU hmenu_درون;
    HMENU hmenu_بعدی;
    HWND hwnd_بعدی;
  } MDINEXTMENU,*PMDINEXTMENU,*LPMDINEXTMENU;

#تعریف_کن WM_NOTIFY 0x004E
#تعریف_کن WM_INPUTLANGCHANGEREQUEST 0x0050
#تعریف_کن WM_INPUTLANGCHANGE 0x0051
#تعریف_کن WM_TCARD 0x0052
#تعریف_کن WM_HELP 0x0053
#تعریف_کن WM_USERCHANGED 0x0054
#تعریف_کن WM_NOTIFYFORMAT 0x0055

#تعریف_کن NFR_ANSI 1
#تعریف_کن NFR_UNICODE 2
#تعریف_کن NF_QUERY 3
#تعریف_کن NF_REQUERY 4

#تعریف_کن WM_CONTEXTMENU 0x007B
#تعریف_کن WM_STYLECHANGING 0x007C
#تعریف_کن WM_STYLECHANGED 0x007D
#تعریف_کن WM_DISPLAYCHANGE 0x007E
#تعریف_کن WM_GETICON 0x007F
#تعریف_کن WM_SETICON 0x0080

#تعریف_کن WM_NCCREATE 0x0081
#تعریف_کن WM_NCDESTROY 0x0082
#تعریف_کن WM_NCCALCSIZE 0x0083
#تعریف_کن WM_NCHITTEST 0x0084
#تعریف_کن WM_NCPAINT 0x0085
#تعریف_کن WM_NCACTIVATE 0x0086
#تعریف_کن WM_GETDLGCODE 0x0087
#اگر_تعریف_نشده _WIN32_WCE
#تعریف_کن WM_SYNCPAINT 0x0088
#پایان_اگر
#تعریف_کن WM_NCMOUSEMOVE 0x00A0
#تعریف_کن WM_NCLBUTTONDOWN 0x00A1
#تعریف_کن WM_NCLBUTTONUP 0x00A2
#تعریف_کن WM_NCLBUTTONDBLCLK 0x00A3
#تعریف_کن WM_NCRBUTTONDOWN 0x00A4
#تعریف_کن WM_NCRBUTTONUP 0x00A5
#تعریف_کن WM_NCRBUTTONDBLCLK 0x00A6
#تعریف_کن WM_NCMBUTTONDOWN 0x00A7
#تعریف_کن WM_NCMBUTTONUP 0x00A8
#تعریف_کن WM_NCMBUTTONDBLCLK 0x00A9

#تعریف_کن WM_NCXBUTTONDOWN 0x00AB
#تعریف_کن WM_NCXBUTTONUP 0x00AC
#تعریف_کن WM_NCXBUTTONDBLCLK 0x00AD
#تعریف_کن WM_درون_داد 0x00FF
#تعریف_کن WM_KEYFIRST 0x0100
#تعریف_کن WM_KEYDOWN 0x0100
#تعریف_کن WM_KEYUP 0x0101
#تعریف_کن WM_CHAR 0x0102
#تعریف_کن WM_DEADCHAR 0x0103
#تعریف_کن WM_SYSKEYDOWN 0x0104
#تعریف_کن WM_SYSKEYUP 0x0105
#تعریف_کن WM_SYSCHAR 0x0106
#تعریف_کن WM_SYSDEADCHAR 0x0107
#تعریف_کن WM_UNICHAR 0x0109
#تعریف_کن WM_KEYLAST 0x0109
#تعریف_کن UNICODE_NOCHAR 0xFFFF
#تعریف_کن WM_IME_STARTCOMPOSITION 0x010D
#تعریف_کن WM_IME_ENDCOMPOSITION 0x010E
#تعریف_کن WM_IME_COMPOSITION 0x010F
#تعریف_کن WM_IME_KEYLAST 0x010F
#تعریف_کن WM_INITDIALOG 0x0110
#تعریف_کن WM_COMMAND 0x0111
#تعریف_کن WM_SYSCOMMAND 0x0112
#تعریف_کن WM_TIMER 0x0113
#تعریف_کن WM_HSCROLL 0x0114
#تعریف_کن WM_VSCROLL 0x0115
#تعریف_کن WM_INITMENU 0x0116
#تعریف_کن WM_INITMENUPOPUP 0x0117
#تعریف_کن WM_MENUSELECT 0x011F
#تعریف_کن WM_MENUCHAR 0x0120
#تعریف_کن WM_ENTERIDLE 0x0121
#اگر_تعریف_نشده _WIN32_WCE
#تعریف_کن WM_MENURBUTTONUP 0x0122
#تعریف_کن WM_MENUDRAG 0x0123
#تعریف_کن WM_MENUGETOBJECT 0x0124
#تعریف_کن WM_UNINITMENUPOPUP 0x0125
#تعریف_کن WM_MENUCOMMAND 0x0126

#اگر_تعریف_نشده _WIN32_WCE
#تعریف_کن WM_CHANGEUISTATE 0x0127
#تعریف_کن WM_UPDATEUISTATE 0x0128
#تعریف_کن WM_QUERYUISTATE 0x0129

#تعریف_کن UIS_مجموعه 1
#تعریف_کن UIS_CLEAR 2
#تعریف_کن UIS_INITIALIZE 3

#تعریف_کن UISF_HIDEFOCUS 0x1
#تعریف_کن UISF_HIDEACCEL 0x2
#تعریف_کن UISF_فعال 0x4
#پایان_اگر
#پایان_اگر

#تعریف_کن WM_CTLCOLORMSGBOX 0x0132
#تعریف_کن WM_CTLCOLOREDIT 0x0133
#تعریف_کن WM_CTLCOLORLISTBOX 0x0134
#تعریف_کن WM_CTLCOLORBTN 0x0135
#تعریف_کن WM_CTLCOLORDLG 0x0136
#تعریف_کن WM_CTLCOLORSCROLLBAR 0x0137
#تعریف_کن WM_CTLCOLORSTATIC 0x0138
#تعریف_کن MN_GETHMENU 0x01E1

#تعریف_کن WM_MOUSEFIRST 0x0200
#تعریف_کن WM_MOUSEMOVE 0x0200
#تعریف_کن WM_LBUTTONDOWN 0x0201
#تعریف_کن WM_LBUTTONUP 0x0202
#تعریف_کن WM_LBUTTONDBLCLK 0x0203
#تعریف_کن WM_RBUTTONDOWN 0x0204
#تعریف_کن WM_RBUTTONUP 0x0205
#تعریف_کن WM_RBUTTONDBLCLK 0x0206
#تعریف_کن WM_MBUTTONDOWN 0x0207
#تعریف_کن WM_MBUTTONUP 0x0208
#تعریف_کن WM_MBUTTONDBLCLK 0x0209
#تعریف_کن WM_MOUSEWHEEL 0x020A
#تعریف_کن WM_XBUTTONDOWN 0x020B
#تعریف_کن WM_XBUTTONUP 0x020C
#تعریف_کن WM_XBUTTONDBLCLK 0x020D
#تعریف_کن WM_MOUSEHWHEEL 0x020E
#تعریف_کن WM_MOUSELAST 0x020E

#تعریف_کن WHEEL_DELTA 120
#تعریف_کن GET_WHEEL_DELTA_WPARAM(wParam) ((کوتاه)HIWORD(wParam))

#تعریف_کن WHEEL_PAGESCROLL (UINT_MAX)

#تعریف_کن GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#تعریف_کن GET_NCHITTEST_WPARAM(wParam) ((کوتاه)LOWORD(wParam))
#تعریف_کن GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#تعریف_کن XBUTTON1 0x0001
#تعریف_کن XBUTTON2 0x0002

#تعریف_کن WM_PARENTNOTIFY 0x0210
#تعریف_کن WM_ENTERMENULOOP 0x0211
#تعریف_کن WM_EXITMENULOOP 0x0212

#تعریف_کن WM_NEXTMENU 0x0213
#تعریف_کن WM_SIZING 0x0214
#تعریف_کن WM_CAPTURECHANGED 0x0215
#تعریف_کن WM_MOVING 0x0216

#تعریف_کن WM_POWERBROADCAST 0x0218

#اگر_تعریف_نشده _WIN32_WCE
#تعریف_کن PBT_APMQUERYSUSPEND 0x0000
#تعریف_کن PBT_APMQUERYSTANDBY 0x0001

#تعریف_کن PBT_APMQUERYSUSPENDFAILED 0x0002
#تعریف_کن PBT_APMQUERYSTANDBYFAILED 0x0003

#تعریف_کن PBT_APMSUSPEND 0x0004
#تعریف_کن PBT_APMSTANDBY 0x0005

#تعریف_کن PBT_APMRESUMECRITICAL 0x0006
#تعریف_کن PBT_APMRESUMESUSPEND 0x0007
#تعریف_کن PBT_APMRESUMESTANDBY 0x0008

#تعریف_کن PBTF_APMRESUMEFROMFAILURE 0x00000001

#تعریف_کن PBT_APMBATTERYLOW 0x0009
#تعریف_کن PBT_APMPOWERSTATUSCHANGE 0x000A

#تعریف_کن PBT_APMOEMEVENT 0x000B
#تعریف_کن PBT_APMRESUMEAUTOMATIC 0x0012
#پایان_اگر

#تعریف_کن WM_DEVICECHANGE 0x0219

#تعریف_کن WM_MDICREATE 0x0220
#تعریف_کن WM_MDIDESTROY 0x0221
#تعریف_کن WM_MDIACTIVATE 0x0222
#تعریف_کن WM_MDIRESTORE 0x0223
#تعریف_کن WM_MDINEXT 0x0224
#تعریف_کن WM_MDIMAXIMIZE 0x0225
#تعریف_کن WM_MDITILE 0x0226
#تعریف_کن WM_MDICASCADE 0x0227
#تعریف_کن WM_MDIICONARRANGE 0x0228
#تعریف_کن WM_MDIGETACTIVE 0x0229

#تعریف_کن WM_MDISETMENU 0x0230
#تعریف_کن WM_ENTERSIZEMOVE 0x0231
#تعریف_کن WM_EXITSIZEMOVE 0x0232
#تعریف_کن WM_DROPFILES 0x0233
#تعریف_کن WM_MDIREFRESHMENU 0x0234

#تعریف_کن WM_IME_SETCONTEXT 0x0281
#تعریف_کن WM_IME_NOTIFY 0x0282
#تعریف_کن WM_IME_CONTROL 0x0283
#تعریف_کن WM_IME_COMPOSITIONFULL 0x0284
#تعریف_کن WM_IME_SELECT 0x0285
#تعریف_کن WM_IME_CHAR 0x0286
#تعریف_کن WM_IME_REQUEST 0x0288
#تعریف_کن WM_IME_KEYDOWN 0x0290
#تعریف_کن WM_IME_KEYUP 0x0291

#تعریف_کن WM_MOUSEHOVER 0x02A1
#تعریف_کن WM_MOUSELEAVE 0x02A3
#تعریف_کن WM_NCMOUSEHOVER 0x02A0
#تعریف_کن WM_NCMOUSELEAVE 0x02A2
#تعریف_کن WM_WTSSESSION_CHANGE 0x02B1
#تعریف_کن WM_TABLET_اولی 0x02c0
#تعریف_کن WM_TABLET_آخرین 0x02df
#تعریف_کن WM_CUT 0x0300
#تعریف_کن WM_COPY 0x0301
#تعریف_کن WM_PASTE 0x0302
#تعریف_کن WM_CLEAR 0x0303
#تعریف_کن WM_UNDO 0x0304
#تعریف_کن WM_RENDERFORMAT 0x0305
#تعریف_کن WM_RENDERALLFORMATS 0x0306
#تعریف_کن WM_DESTROYCLIPBOARD 0x0307
#تعریف_کن WM_DRAWCLIPBOARD 0x0308
#تعریف_کن WM_PAINTCLIPBOARD 0x0309
#تعریف_کن WM_VSCROLLCLIPBOARD 0x030A
#تعریف_کن WM_SIZECLIPBOARD 0x030B
#تعریف_کن WM_ASKCBFORMATNAME 0x030C
#تعریف_کن WM_CHANGECBCHAIN 0x030D
#تعریف_کن WM_HSCROLLCLIPBOARD 0x030E
#تعریف_کن WM_QUERYNEWPALETTE 0x030F
#تعریف_کن WM_PALETTEISCHANGING 0x0310
#تعریف_کن WM_PALETTECHANGED 0x0311
#تعریف_کن WM_HOTKEY 0x0312
#تعریف_کن WM_PRINT 0x0317
#تعریف_کن WM_PRINTCLIENT 0x0318
#تعریف_کن WM_APPCOMMAND 0x0319
#تعریف_کن WM_THEMECHANGED 0x031A
#تعریف_کن WM_HANDHELDFIRST 0x0358
#تعریف_کن WM_HANDHELDLAST 0x035F
#تعریف_کن WM_AFXFIRST 0x0360
#تعریف_کن WM_AFXLAST 0x037F
#تعریف_کن WM_PENWINFIRST 0x0380
#تعریف_کن WM_PENWINLAST 0x038F
#تعریف_کن WM_APP 0x8000
#تعریف_کن WM_USER 0x0400

#تعریف_کن WMSZ_چپ 1
#تعریف_کن WMSZ_راست 2
#تعریف_کن WMSZ_بالاترین 3
#تعریف_کن WMSZ_TOPLEFT 4
#تعریف_کن WMSZ_TOPRIGHT 5
#تعریف_کن WMSZ_BOTTOM 6
#تعریف_کن WMSZ_BOTTOMLEFT 7
#تعریف_کن WMSZ_BOTTOMRIGHT 8

#اگر_تعریف_نشده NONCMESSAGES

#تعریف_کن HTERROR (-2)
#تعریف_کن HTTRANSPARENT (-1)
#تعریف_کن HTNOWHERE 0
#تعریف_کن HTCLIENT 1
#تعریف_کن HTCAPTION 2
#تعریف_کن HTSYSMENU 3
#تعریف_کن HTGROWBOX 4
#تعریف_کن HTSIZE HTGROWBOX
#تعریف_کن HTMENU 5
#تعریف_کن HTHSCROLL 6
#تعریف_کن HTVSCROLL 7
#تعریف_کن HTMINBUTTON 8
#تعریف_کن HTMAXBUTTON 9
#تعریف_کن HTLEFT 10
#تعریف_کن HTRIGHT 11
#تعریف_کن HTTOP 12
#تعریف_کن HTTOPLEFT 13
#تعریف_کن HTTOPRIGHT 14
#تعریف_کن HTBOTTOM 15
#تعریف_کن HTBOTTOMLEFT 16
#تعریف_کن HTBOTTOMRIGHT 17
#تعریف_کن HTBORDER 18
#تعریف_کن HTREDUCE HTMINBUTTON
#تعریف_کن HTZOOM HTMAXBUTTON
#تعریف_کن HTSIZEFIRST HTLEFT
#تعریف_کن HTSIZELAST HTBOTTOMRIGHT
#تعریف_کن HTOBJECT 19
#تعریف_کن HTCLOSE 20
#تعریف_کن HTHELP 21

#تعریف_کن SMTO_نرمال 0x0000
#تعریف_کن SMTO_بلوک 0x0001
#تعریف_کن SMTO_ABORTIFHUNG 0x0002
#تعریف_کن SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#پایان_اگر

#تعریف_کن MA_ACTIVATE 1
#تعریف_کن MA_ACTIVATEANDEAT 2
#تعریف_کن MA_NOACTIVATE 3
#تعریف_کن MA_NOACTIVATEANDEAT 4

#تعریف_کن ICON_SMALL 0
#تعریف_کن ICON_BIG 1
#تعریف_کن ICON_SMALL2 2

#اگر_تعریف_شده UNICODE
#تعریف_کن ثبات_پنجره_پیام ثبات_پنجره_پیام_W
#وإلا
#تعریف_کن ثبات_پنجره_پیام ثبات_پنجره_پیام_A
#پایان_اگر

  WINUSERAPI UINT WINAPI ثبات_پنجره_پیام_A(LPCSTR lpString);
  WINUSERAPI UINT WINAPI ثبات_پنجره_پیام_W(LPCWSTR lpString);

#تعریف_کن اندازه_RESTORED 0
#تعریف_کن اندازه_MINIMIZED 1
#تعریف_کن اندازه_MAXIMIZED 2
#تعریف_کن اندازه_MAXSHOW 3
#تعریف_کن اندازه_MAXHIDE 4

#تعریف_کن SIZENORMAL اندازه_RESTORED
#تعریف_کن SIZEICONIC اندازه_MINIMIZED
#تعریف_کن SIZEFULLSCREEN اندازه_MAXIMIZED
#تعریف_کن SIZEZOOMSHOW اندازه_MAXSHOW
#تعریف_کن SIZEZOOMHIDE اندازه_MAXHIDE

  تعريفنوع بنية برچسب_WINDOWPOS {
    HWND hwnd;
    HWND hwnd_درج_After;
    صحيح x;
    صحيح y;
    صحيح cx;
    صحيح cy;
    UINT flags;
  } WINDOWPOS,*LPWINDOWPOS,*PWINDOWPOS;

  تعريفنوع بنية برچسب_NCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
  } NCCALCSIZE_PARAMS,*LPNCCALCSIZE_PARAMS;

#تعریف_کن WVR_ALIGNTOP 0x0010
#تعریف_کن WVR_ALIGNLEFT 0x0020
#تعریف_کن WVR_ALIGNBOTTOM 0x0040
#تعریف_کن WVR_ALIGNRIGHT 0x0080
#تعریف_کن WVR_HREDRAW 0x0100
#تعریف_کن WVR_VREDRAW 0x0200
#تعریف_کن WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#تعریف_کن WVR_VALIDRECTS 0x0400

#اگر_تعریف_نشده NOKEYSTATES

#تعریف_کن MK_LBUTTON 0x0001
#تعریف_کن MK_RBUTTON 0x0002
#تعریف_کن MK_لغزش 0x0004
#تعریف_کن MK_CONTROL 0x0008
#تعریف_کن MK_MBUTTON 0x0010
#تعریف_کن MK_XBUTTON1 0x0020
#تعریف_کن MK_XBUTTON2 0x0040
#پایان_اگر

#اگر_تعریف_نشده NOTRACKMOUSEEVENT
#تعریف_کن TME_HOVER 0x00000001
#تعریف_کن TME_LEAVE 0x00000002
#تعریف_کن TME_NONCLIENT 0x00000010
#تعریف_کن TME_QUERY 0x40000000
#تعریف_کن TME_CANCEL 0x80000000

#تعریف_کن HOVER_DEFAULT 0xFFFFFFFF
#پایان_اگر

  تعريفنوع بنية برچسب_TRACKMOUSEEVENT {
    DWORD cb_اندازه;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dw_Hover_زمان;
  } TRACKMOUSEEVENT,*LPTRACKMOUSEEVENT;

  WINUSERAPI WINBOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#پایان_اگر

#اگر_تعریف_نشده NOWINSTYLES

#تعریف_کن WS_OVERLAPPED 0x00000000L
#تعریف_کن WS_POPUP 0x80000000L
#تعریف_کن WS_فرزند 0x40000000L
#تعریف_کن WS_MINIMIZE 0x20000000L
#تعریف_کن WS_VISIBLE 0x10000000L
#تعریف_کن WS_DISABLED 0x08000000L
#تعریف_کن WS_CLIPSIBLINGS 0x04000000L
#تعریف_کن WS_CLIPCHILDREN 0x02000000L
#تعریف_کن WS_MAXIMIZE 0x01000000L
#تعریف_کن WS_CAPTION 0x00C00000L
#تعریف_کن WS_BORDER 0x00800000L
#تعریف_کن WS_DLGFRAME 0x00400000L
#تعریف_کن WS_VSCROLL 0x00200000L
#تعریف_کن WS_HSCROLL 0x00100000L
#تعریف_کن WS_SYSMENU 0x00080000L
#تعریف_کن WS_THICKFRAME 0x00040000L
#تعریف_کن WS_گروه 0x00020000L
#تعریف_کن WS_TABSTOP 0x00010000L
#تعریف_کن WS_MINIMIZEBOX 0x00020000L
#تعریف_کن WS_MAXIMIZEBOX 0x00010000L
#تعریف_کن WS_TILED WS_OVERLAPPED
#تعریف_کن WS_ICONIC WS_MINIMIZE
#تعریف_کن WS_SIZEBOX WS_THICKFRAME
#تعریف_کن WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#تعریف_کن WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#تعریف_کن WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#تعریف_کن WS_CHILDWINDOW (WS_فرزند)

#تعریف_کن WS_EX_DLGMODALFRAME 0x00000001L
#تعریف_کن WS_EX_NOPARENTNOTIFY 0x00000004L
#تعریف_کن WS_EX_TOPMOST 0x00000008L
#تعریف_کن WS_EX_ACCEPTFILES 0x00000010L
#تعریف_کن WS_EX_TRANSPARENT 0x00000020L
#تعریف_کن WS_EX_MDICHILD 0x00000040L
#تعریف_کن WS_EX_TOOLWINDOW 0x00000080L
#تعریف_کن WS_EX_WINDOWEDGE 0x00000100L
#تعریف_کن WS_EX_CLIENTEDGE 0x00000200L
#تعریف_کن WS_EX_CONTEXTHELP 0x00000400L
#تعریف_کن WS_EX_راست 0x00001000L
#تعریف_کن WS_EX_چپ 0x00000000L
#تعریف_کن WS_EX_RTLREADING 0x00002000L
#تعریف_کن WS_EX_LTRREADING 0x00000000L
#تعریف_کن WS_EX_LEFTSCROLLBAR 0x00004000L
#تعریف_کن WS_EX_RIGHTSCROLLBAR 0x00000000L
#تعریف_کن WS_EX_CONTROLPARENT 0x00010000L
#تعریف_کن WS_EX_STATICEDGE 0x00020000L
#تعریف_کن WS_EX_APPWINDOW 0x00040000L
#تعریف_کن WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#تعریف_کن WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#تعریف_کن WS_EX_LAYERED 0x00080000
#تعریف_کن WS_EX_NOINHERITLAYOUT 0x00100000L
#تعریف_کن WS_EX_LAYOUTRTL 0x00400000L
#تعریف_کن WS_EX_COMPOSITED 0x02000000L
#تعریف_کن WS_EX_NOACTIVATE 0x08000000L

#تعریف_کن CS_VREDRAW 0x0001
#تعریف_کن CS_HREDRAW 0x0002
#تعریف_کن CS_DBLCLKS 0x0008
#تعریف_کن CS_OWNDC 0x0020
#تعریف_کن CS_CLASSDC 0x0040
#تعریف_کن CS_PARENTDC 0x0080
#تعریف_کن CS_NOCLOSE 0x0200
#تعریف_کن CS_SAVEBITS 0x0800
#تعریف_کن CS_BYTEALIGNCLIENT 0x1000
#تعریف_کن CS_BYTEALIGNWINDOW 0x2000
#تعریف_کن CS_GLOBALCLASS 0x4000
#تعریف_کن CS_IME 0x00010000
#تعریف_کن CS_DROPSHADOW 0x00020000
#پایان_اگر

#تعریف_کن PRF_CHECKVISIBLE 0x00000001L
#تعریف_کن PRF_NONCLIENT 0x00000002L
#تعریف_کن PRF_CLIENT 0x00000004L
#تعریف_کن PRF_ERASEBKGND 0x00000008L
#تعریف_کن PRF_CHILDREN 0x00000010L
#تعریف_کن PRF_OWNED 0x00000020L

#تعریف_کن BDR_RAISEDOUTER 0x0001
#تعریف_کن BDR_SUNKENOUTER 0x0002
#تعریف_کن BDR_RAISEDINNER 0x0004
#تعریف_کن BDR_SUNKENINNER 0x0008

#تعریف_کن BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#تعریف_کن BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#تعریف_کن BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#تعریف_کن BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#تعریف_کن یال_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#تعریف_کن یال_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#تعریف_کن یال_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#تعریف_کن یال_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#تعریف_کن BF_چپ 0x0001
#تعریف_کن BF_بالاترین 0x0002
#تعریف_کن BF_راست 0x0004
#تعریف_کن BF_BOTTOM 0x0008

#تعریف_کن BF_TOPLEFT (BF_بالاترین | BF_چپ)
#تعریف_کن BF_TOPRIGHT (BF_بالاترین | BF_راست)
#تعریف_کن BF_BOTTOMLEFT (BF_BOTTOM | BF_چپ)
#تعریف_کن BF_BOTTOMRIGHT (BF_BOTTOM | BF_راست)
#تعریف_کن BF_RECT (BF_چپ | BF_بالاترین | BF_راست | BF_BOTTOM)

#تعریف_کن BF_DIAGONAL 0x0010

#تعریف_کن BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_بالاترین | BF_راست)
#تعریف_کن BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_بالاترین | BF_چپ)
#تعریف_کن BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_چپ)
#تعریف_کن BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_راست)

#تعریف_کن BF_میانه 0x0800
#تعریف_کن BF_SOFT 0x1000
#تعریف_کن BF_ADJUST 0x2000
#تعریف_کن BF_FLAT 0x4000
#تعریف_کن BF_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_یال(HDC hdc,LPRECT qrc,UINT یال,UINT grfFlags);

#تعریف_کن DFC_CAPTION 1
#تعریف_کن DFC_MENU 2
#تعریف_کن DFC_SCROLL 3
#تعریف_کن DFC_BUTTON 4
#تعریف_کن DFC_POPUPMENU 5

#تعریف_کن DFCS_CAPTIONCLOSE 0x0000
#تعریف_کن DFCS_CAPTIONMIN 0x0001
#تعریف_کن DFCS_CAPTIONMAX 0x0002
#تعریف_کن DFCS_CAPTIONRESTORE 0x0003
#تعریف_کن DFCS_CAPTIONHELP 0x0004

#تعریف_کن DFCS_MENUARROW 0x0000
#تعریف_کن DFCS_MENUCHECK 0x0001
#تعریف_کن DFCS_MENUBULLET 0x0002
#تعریف_کن DFCS_MENUARROWRIGHT 0x0004
#تعریف_کن DFCS_SCROLLUP 0x0000
#تعریف_کن DFCS_SCROLLDOWN 0x0001
#تعریف_کن DFCS_SCROLLLEFT 0x0002
#تعریف_کن DFCS_SCROLLRIGHT 0x0003
#تعریف_کن DFCS_SCROLLCOMBOBOX 0x0005
#تعریف_کن DFCS_SCROLLSIZEGRIP 0x0008
#تعریف_کن DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#تعریف_کن DFCS_BUTTONCHECK 0x0000
#تعریف_کن DFCS_BUTTONRADIOIMAGE 0x0001
#تعریف_کن DFCS_BUTTONRADIOMASK 0x0002
#تعریف_کن DFCS_BUTTONRADIO 0x0004
#تعریف_کن DFCS_BUTTON3STATE 0x0008
#تعریف_کن DFCS_BUTTONPUSH 0x0010

#تعریف_کن DFCS_INACTIVE 0x0100
#تعریف_کن DFCS_PUSHED 0x0200
#تعریف_کن DFCS_CHECKED 0x0400

#تعریف_کن DFCS_TRANSPARENT 0x0800
#تعریف_کن DFCS_HOT 0x1000

#تعریف_کن DFCS_ADJUSTRECT 0x2000
#تعریف_کن DFCS_FLAT 0x4000
#تعریف_کن DFCS_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_قاب_Control(HDC,LPRECT,UINT,UINT);

#تعریف_کن DC_فعال 0x0001
#تعریف_کن DC_SMALLCAP 0x0002
#تعریف_کن DC_ICON 0x0004
#تعریف_کن DC_متن 0x0008
#تعریف_کن DC_INBUTTON 0x0010
#تعریف_کن DC_GRADIENT 0x0020
#تعریف_کن DC_BUTTONS 0x1000

  WINUSERAPI WINBOOL WINAPI DrawCaption(HWND hwnd,HDC hdc,CONST RECT *lprect,UINT flags);

#تعریف_کن IDANI_OPEN 1
#تعریف_کن IDANI_CAPTION 3

  WINUSERAPI WINBOOL WINAPI DrawAnimatedRects(HWND hwnd,صحيح idAni,CONST RECT *lprcFrom,CONST RECT *lprc_مقصد);

#اگر_تعریف_نشده NOCLIPBOARD

#تعریف_کن CF_متن 1
#تعریف_کن CF_BITMAP 2
#تعریف_کن CF_METAFILEPICT 3
#تعریف_کن CF_SYLK 4
#تعریف_کن CF_DIF 5
#تعریف_کن CF_TIFF 6
#تعریف_کن CF_OEMTEXT 7
#تعریف_کن CF_DIB 8
#تعریف_کن CF_PALETTE 9
#تعریف_کن CF_PENDATA 10
#تعریف_کن CF_RIFF 11
#تعریف_کن CF_WAVE 12
#تعریف_کن CF_UNICODETEXT 13
#تعریف_کن CF_ENHMETAFILE 14
#تعریف_کن CF_HDROP 15
#تعریف_کن CF_LOCALE 16
#تعریف_کن CF_DIBV5 17
#تعریف_کن CF_MAX 18

#تعریف_کن CF_OWNERDISPLAY 0x0080
#تعریف_کن CF_DSPTEXT 0x0081
#تعریف_کن CF_DSPBITMAP 0x0082
#تعریف_کن CF_DSPMETAFILEPICT 0x0083
#تعریف_کن CF_DSPENHMETAFILE 0x008E

#تعریف_کن CF_PRIVATEFIRST 0x0200
#تعریف_کن CF_PRIVATELAST 0x02FF

#تعریف_کن CF_GDIOBJFIRST 0x0300
#تعریف_کن CF_GDIOBJLAST 0x03FF
#پایان_اگر

#تعریف_کن FVIRTKEY TRUE
#تعریف_کن FNOINVERT 0x02
#تعریف_کن FSHIFT 0x04
#تعریف_کن FCONTROL 0x08
#تعریف_کن FALT 0x10

  تعريفنوع بنية برچسب_ACCEL {
    BYTE fVirt;
    کلمه_3 کلید;
    کلمه_3 cmd;
  } ACCEL,*LPACCEL;

  تعريفنوع بنية برچسب_PAINTSTRUCT {
    HDC hdc;
    WINBOOL fErase;
    RECT rcPaint;
    WINBOOL fRestore;
    WINBOOL fIncUpdate;
    BYTE rgbReserved[32];
  } PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;

  تعريفنوع بنية برچسب_CREATESTRUCTA {
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

  تعريفنوع بنية برچسب_CREATESTRUCTW {
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

#اگر_تعریف_شده UNICODE
  تعريفنوع CREATESTRUCTW CREATESTRUCT;
  تعريفنوع LPCREATESTRUCTW LPCREATESTRUCT;
#وإلا
  تعريفنوع CREATESTRUCTA CREATESTRUCT;
  تعريفنوع LPCREATESTRUCTA LPCREATESTRUCT;
#پایان_اگر

  تعريفنوع بنية برچسب_WINDOWPLACEMENT {
    UINT درازی;
    UINT flags;
    UINT showCmd;
    نقطه_3 ptMinPosition;
    نقطه_3 ptMaxPosition;
    RECT rc_نرمال_Position;
  } WINDOWPLACEMENT;
  تعريفنوع WINDOWPLACEMENT *PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;

#تعریف_کن WPF_SETMINPOSITION 0x0001
#تعریف_کن WPF_RESTORETOMAXIMIZED 0x0002
#تعریف_کن WPF_ASYNCWINDOWPLACEMENT 0x0004

  تعريفنوع بنية برچسب_NMHDR {
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT کد;
  } NMHDR;

  تعريفنوع NMHDR *LPNMHDR;

  تعريفنوع بنية برچسب_STYLESTRUCT {
    DWORD styleOld;
    DWORD styleNew;
  } STYLESTRUCT,*LPSTYLESTRUCT;

#تعریف_کن ODT_MENU 1
#تعریف_کن ODT_LISTBOX 2
#تعریف_کن ODT_COMBOBOX 3
#تعریف_کن ODT_BUTTON 4
#تعریف_کن ODT_STATIC 5

#تعریف_کن ODA_DRAWENTIRE 0x0001
#تعریف_کن ODA_SELECT 0x0002
#تعریف_کن ODA_FOCUS 0x0004

#تعریف_کن ODS_SELECTED 0x0001
#تعریف_کن ODS_GRAYED 0x0002
#تعریف_کن ODS_DISABLED 0x0004
#تعریف_کن ODS_CHECKED 0x0008
#تعریف_کن ODS_FOCUS 0x0010
#تعریف_کن ODS_DEFAULT 0x0020
#تعریف_کن ODS_COMBOBOXEDIT 0x1000
#تعریف_کن ODS_HOTLIGHT 0x0040
#تعریف_کن ODS_INACTIVE 0x0080
#تعریف_کن ODS_NOACCEL 0x0100
#تعریف_کن ODS_NOFOCUSRECT 0x0200

  تعريفنوع بنية برچسب_MEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT قلم_ID;
    UINT قلم_عرض;
    UINT قلم_ارتفاع;
    ULONG_PTR قلم_داده;
  } MEASUREITEMSTRUCT,*PMEASUREITEMSTRUCT,*LPMEASUREITEMSTRUCT;

  تعريفنوع بنية برچسب_DRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT قلم_ID;
    UINT قلم_Action;
    UINT قلم_State;
    HWND hwnd_قلم;
    HDC hDC;
    RECT rc_قلم;
    ULONG_PTR قلم_داده;
  } DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;

  تعريفنوع بنية برچسب_DELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT قلم_ID;
    HWND hwnd_قلم;
    ULONG_PTR قلم_داده;
  } DELETEITEMSTRUCT,*PDELETEITEMSTRUCT,*LPDELETEITEMSTRUCT;

  تعريفنوع بنية برچسب_COMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwnd_قلم;
    UINT قلم_ID1;
    ULONG_PTR قلم_Data1;
    UINT قلم_ID2;
    ULONG_PTR قلم_Data2;
    DWORD dwLocaleId;
  } COMPAREITEMSTRUCT,*PCOMPAREITEMSTRUCT,*LPCOMPAREITEMSTRUCT;

#اگر_تعریف_نشده NOMSG
#اگر_تعریف_شده UNICODE
#تعریف_کن Get_پیام Get_پیام_W
#تعریف_کن Dispatch_پیام Dispatch_پیام_W
#تعریف_کن Peek_پیام Peek_پیام_W
#وإلا
#تعریف_کن Get_پیام Get_پیام_A
#تعریف_کن Dispatch_پیام Dispatch_پیام_A
#تعریف_کن Peek_پیام Peek_پیام_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI Get_پیام_A(LPMSG lp_پیام_2,HWND hWnd,UINT w_پیام_Filter_Min,UINT w_پیام_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Get_پیام_W(LPMSG lp_پیام_2,HWND hWnd,UINT w_پیام_Filter_Min,UINT w_پیام_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Translate_پیام(CONST پیام_3 *lp_پیام_2);
  WINUSERAPI LRESULT WINAPI Dispatch_پیام_A(CONST پیام_3 *lp_پیام_2);
  WINUSERAPI LRESULT WINAPI Dispatch_پیام_W(CONST پیام_3 *lp_پیام_2);
  WINUSERAPI WINBOOL WINAPI مجموعه_پیام_صف(صحيح cMessagesMax);
  WINUSERAPI WINBOOL WINAPI Peek_پیام_A(LPMSG lp_پیام_2,HWND hWnd,UINT w_پیام_Filter_Min,UINT w_پیام_Filter_Max,UINT w_Remove_پیام);
  WINUSERAPI WINBOOL WINAPI Peek_پیام_W(LPMSG lp_پیام_2,HWND hWnd,UINT w_پیام_Filter_Min,UINT w_پیام_Filter_Max,UINT w_Remove_پیام);

#تعریف_کن PM_NOREMOVE 0x0000
#تعریف_کن PM_REMOVE 0x0001
#تعریف_کن PM_NOYIELD 0x0002
#تعریف_کن PM_QS_درون_داد (QS_درون_داد << 16)
#تعریف_کن PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#تعریف_کن PM_QS_PAINT (QS_PAINT << 16)
#تعریف_کن PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI ثبات_Hot_کلید(HWND hWnd,صحيح id,UINT fsModifiers,UINT vk);
  WINUSERAPI WINBOOL WINAPI Unregister_Hot_کلید(HWND hWnd,صحيح id);

#تعریف_کن MOD_ALT 0x0001
#تعریف_کن MOD_CONTROL 0x0002
#تعریف_کن MOD_لغزش 0x0004
#تعریف_کن MOD_WIN 0x0008

#تعریف_کن IDHOT_SNAPWINDOW (-1)
#تعریف_کن IDHOT_SNAPDESKTOP (-2)

#اگر_تعریف_شده WIN_داخلی
#اگر_تعریف_نشده LSTRING
#تعریف_کن NOLSTRING
#پایان_اگر
#اگر_تعریف_نشده LFILEIO
#تعریف_کن NOLFILEIO
#پایان_اگر
#پایان_اگر

#تعریف_کن ENDSESSION_LOGOFF 0x80000000

#تعریف_کن EWX_LOGOFF 0
#تعریف_کن EWX_SHUTDOWN 0x00000001
#تعریف_کن EWX_REBOOT 0x00000002
#تعریف_کن EWX_FORCE 0x00000004
#تعریف_کن EWX_POWEROFF 0x00000008
#تعریف_کن EWX_FORCEIFHUNG 0x00000010

#تعریف_کن ExitWindows(dwReserved,کد_4) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#اگر_تعریف_شده UNICODE
#تعریف_کن Send_پیام Send_پیام_W
#تعریف_کن Send_پیام_Timeout Send_پیام_Timeout_W
#تعریف_کن Send_Notify_پیام Send_Notify_پیام_W
#تعریف_کن Send_پیام_Callback Send_پیام_Callback_W
#وإلا
#تعریف_کن Send_پیام Send_پیام_A
#تعریف_کن Send_پیام_Timeout Send_پیام_Timeout_A
#تعریف_کن Send_Notify_پیام Send_Notify_پیام_A
#تعریف_کن Send_پیام_Callback Send_پیام_Callback_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI ExitWindowsEx(UINT uFlags,DWORD dwReason);
  WINUSERAPI WINBOOL WINAPI جابجا_Mouse_Button(WINBOOL f_جابجا);
  WINUSERAPI DWORD WINAPI Get_پیام_Pos(VOID);
  WINUSERAPI LONG WINAPI Get_پیام_زمان(VOID);
  WINUSERAPI LPARAM WINAPI Get_پیام_Extra_Info(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Wow64_پیام(VOID);
  WINUSERAPI LPARAM WINAPI مجموعه_پیام_Extra_Info(LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_پیام_A(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_پیام_W(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_پیام_Timeout_A(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_نتیجه);
  WINUSERAPI LRESULT WINAPI Send_پیام_Timeout_W(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_نتیجه);
  WINUSERAPI WINBOOL WINAPI Send_Notify_پیام_A(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_Notify_پیام_W(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_پیام_Callback_A(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_نتیجه_Call_پشت,ULONG_PTR dw_داده);
  WINUSERAPI WINBOOL WINAPI Send_پیام_Callback_W(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_نتیجه_Call_پشت,ULONG_PTR dw_داده);

  تعريفنوع بنية {
    UINT cb_اندازه;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
  } BSMINFO,*PBSMINFO;

#اگر_تعریف_شده UNICODE
#تعریف_کن پخش_System_پیام_Ex پخش_System_پیام_Ex_W
#تعریف_کن پخش_System_پیام پخش_System_پیام_W
#وإلا
#تعریف_کن پخش_System_پیام_Ex پخش_System_پیام_Ex_A
#تعریف_کن پخش_System_پیام پخش_System_پیام_A
#پایان_اگر

  WINUSERAPI دراز WINAPI پخش_System_پیام_Ex_A(DWORD flags,LPDWORD lpInfo,UINT پیام_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI دراز WINAPI پخش_System_پیام_Ex_W(DWORD flags,LPDWORD lpInfo,UINT پیام_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI دراز WINAPI پخش_System_پیام_A(DWORD flags,LPDWORD lpInfo,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI دراز WINAPI پخش_System_پیام_W(DWORD flags,LPDWORD lpInfo,UINT پیام_5,WPARAM wParam,LPARAM lParam);

#تعریف_کن BSM_ALLCOMPONENTS 0x00000000
#تعریف_کن BSM_VXDS 0x00000001
#تعریف_کن BSM_NETDRIVER 0x00000002
#تعریف_کن BSM_INSTALLABLEDRIVERS 0x00000004
#تعریف_کن BSM_APPLICATIONS 0x00000008
#تعریف_کن BSM_ALLDESKTOPS 0x00000010

#تعریف_کن BSF_QUERY 0x00000001
#تعریف_کن BSF_IGNORECURRENTTASK 0x00000002
#تعریف_کن BSF_FLUSHDISK 0x00000004
#تعریف_کن BSF_NOHANG 0x00000008
#تعریف_کن BSF_POSTMESSAGE 0x00000010
#تعریف_کن BSF_FORCEIFHUNG 0x00000020
#تعریف_کن BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#تعریف_کن BSF_ALLOWSFW 0x00000080
#تعریف_کن BSF_SENDNOTIFYMESSAGE 0x00000100
#تعریف_کن BSF_RETURNHDESK 0x00000200
#تعریف_کن BSF_LUID 0x00000400

#تعریف_کن پخش_QUERY_DENY 0x424D5144

  تعريفنوع PVOID HDEVNOTIFY;
  تعريفنوع HDEVNOTIFY *PHDEVNOTIFY;

#تعریف_کن DEVICE_NOTIFY_پنجره_HANDLE 0x00000000
#تعریف_کن DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#تعریف_کن DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#اگر_تعریف_شده UNICODE
#تعریف_کن ثبات_Device_Notification ثبات_Device_Notification_W
#تعریف_کن Post_پیام Post_پیام_W
#تعریف_کن Post_Thread_پیام Post_Thread_پیام_W
#تعریف_کن Post_App_پیام Post_App_پیام_W
#تعریف_کن Def_پنجره_Proc Def_پنجره_Proc_W
#تعریف_کن Call_پنجره_Proc Call_پنجره_Proc_W
#تعریف_کن ثبات_Class ثبات_Class_W
#تعریف_کن UnregisterClass UnregisterClassW
#تعریف_کن GetClassInfo GetClassInfoW
#تعریف_کن ثبات_Class_Ex ثبات_Class_Ex_W
#تعریف_کن GetClassInfoEx GetClassInfoExW
#وإلا
#تعریف_کن ثبات_Device_Notification ثبات_Device_Notification_A
#تعریف_کن Post_پیام Post_پیام_A
#تعریف_کن Post_Thread_پیام Post_Thread_پیام_A
#تعریف_کن Post_App_پیام Post_App_پیام_A
#تعریف_کن Def_پنجره_Proc Def_پنجره_Proc_A
#تعریف_کن Call_پنجره_Proc Call_پنجره_Proc_A
#تعریف_کن ثبات_Class ثبات_Class_A
#تعریف_کن UnregisterClass UnregisterClassA
#تعریف_کن GetClassInfo GetClassInfoA
#تعریف_کن ثبات_Class_Ex ثبات_Class_Ex_A
#تعریف_کن GetClassInfoEx GetClassInfoExA
#پایان_اگر

  WINUSERAPI HDEVNOTIFY WINAPI ثبات_Device_Notification_A(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI HDEVNOTIFY WINAPI ثبات_Device_Notification_W(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI WINBOOL WINAPI UnregisterDeviceNotification(HDEVNOTIFY Handle);
  WINUSERAPI WINBOOL WINAPI Post_پیام_A(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_پیام_W(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_پیام_A(DWORD idThread,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_پیام_W(DWORD idThread,UINT پیام_5,WPARAM wParam,LPARAM lParam);
#تعریف_کن Post_App_پیام_A(idThread,w_پیام,wParam,lParam) Post_Thread_پیام_A((DWORD)idThread,w_پیام,wParam,lParam)
#تعریف_کن Post_App_پیام_W(idThread,w_پیام,wParam,lParam) Post_Thread_پیام_W((DWORD)idThread,w_پیام,wParam,lParam)

#تعریف_کن HWND_پخش ((HWND)0xffff)
#تعریف_کن HWND_پیام ((HWND)-3)

  WINUSERAPI WINBOOL WINAPI Attach_Thread_درون_داد(DWORD idAttach,DWORD id_Attach_مقصد,WINBOOL fAttach);
  WINUSERAPI WINBOOL WINAPI پاسخ_پیام(LRESULT l_نتیجه);
  WINUSERAPI WINBOOL WINAPI Wait_پیام(VOID);
  WINUSERAPI DWORD WINAPI Wait_For_درون_داد_Idle(HANDLE hProcess,DWORD dwMilliseconds);
  WINUSERAPI LRESULT WINAPI Def_پنجره_Proc_A(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_پنجره_Proc_W(HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI VOID WINAPI Post_Quit_پیام(صحيح n_Exit_کد);
  WINUSERAPI LRESULT WINAPI Call_پنجره_Proc_A(WNDPROC lpPrevWndFunc,HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Call_پنجره_Proc_W(WNDPROC lpPrevWndFunc,HWND hWnd,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI درون_Send_پیام(VOID);
  WINUSERAPI DWORD WINAPI درون_Send_پیام_Ex(LPVOID lpReserved);

#تعریف_کن ISMEX_NOSEND 0x00000000
#تعریف_کن ISMEX_SEND 0x00000001
#تعریف_کن ISMEX_NOTIFY 0x00000002
#تعریف_کن ISMEX_CALLBACK 0x00000004
#تعریف_کن ISMEX_REPLIED 0x00000008

  WINUSERAPI UINT WINAPI Get_Double_Click_زمان(VOID);
  WINUSERAPI WINBOOL WINAPI مجموعه_Double_Click_زمان(UINT);
  WINUSERAPI ATOM WINAPI ثبات_Class_A(CONST WNDCLASSA *lpWndClass);
  WINUSERAPI ATOM WINAPI ثبات_Class_W(CONST WNDCLASSW *lpWndClass);
  WINUSERAPI WINBOOL WINAPI UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
  WINUSERAPI WINBOOL WINAPI GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
  WINUSERAPI ATOM WINAPI ثبات_Class_Ex_A(CONST WNDCLASSEXA *);
  WINUSERAPI ATOM WINAPI ثبات_Class_Ex_W(CONST WNDCLASSEXW *);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);

#تعریف_کن CW_USEDEFAULT ((صحيح)0x80000000)

#تعریف_کن HWND_DESKTOP ((HWND)0)

  تعريفنوع BOOLEAN (WINAPI *PREGISTERCLASSNAMEW)(LPCWSTR);

#اگر_تعریف_شده UNICODE
#تعریف_کن Create_پنجره_Ex Create_پنجره_Ex_W
#تعریف_کن Create_پنجره Create_پنجره_W
#وإلا
#تعریف_کن Create_پنجره_Ex Create_پنجره_Ex_A
#تعریف_کن Create_پنجره Create_پنجره_A
#پایان_اگر

  WINUSERAPI HWND WINAPI Create_پنجره_Ex_A(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lp_پنجره_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_عرض,صحيح n_ارتفاع,HWND h_Wnd_والد,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
  WINUSERAPI HWND WINAPI Create_پنجره_Ex_W(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lp_پنجره_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_عرض,صحيح n_ارتفاع,HWND h_Wnd_والد,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
#تعریف_کن Create_پنجره_A(lpClassName,lp_پنجره_Name,dwStyle,x,y,n_عرض,n_ارتفاع,h_Wnd_والد,hMenu,hInstance,lpParam) Create_پنجره_Ex_A(0L,lpClassName,lp_پنجره_Name,dwStyle,x,y,n_عرض,n_ارتفاع,h_Wnd_والد,hMenu,hInstance,lpParam)
#تعریف_کن Create_پنجره_W(lpClassName,lp_پنجره_Name,dwStyle,x,y,n_عرض,n_ارتفاع,h_Wnd_والد,hMenu,hInstance,lpParam) Create_پنجره_Ex_W(0L,lpClassName,lp_پنجره_Name,dwStyle,x,y,n_عرض,n_ارتفاع,h_Wnd_والد,hMenu,hInstance,lpParam)
  WINUSERAPI WINBOOL WINAPI Is_پنجره(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsMenu(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI Is_فرزند(HWND h_Wnd_والد,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Destroy_پنجره(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Show_پنجره(HWND hWnd,صحيح nCmdShow);
  WINUSERAPI WINBOOL WINAPI Animate_پنجره(HWND hWnd,DWORD dw_زمان,DWORD dwFlags);

#إذا defined(_WINGDI_) && !defined(NOGDI)
  WINUSERAPI WINBOOL WINAPI Update_Layered_پنجره(HWND hWnd,HDC hdcDst,نقطه_3 *pptDst,اندازه_2 *psize,HDC hdcSrc,نقطه_3 *pptSrc,COLORREF cr_کلید,BLENDFUNCTION *pblend,DWORD dwFlags);

  تعريفنوع بنية برچسب_UPDATELAYEREDWINDOWINFO {
    DWORD cb_اندازه;
    HDC hdcDst;
    نقطه_3 CONST *pptDst;
    اندازه_2 CONST *psize;
    HDC hdcSrc;
    نقطه_3 CONST *pptSrc;
    COLORREF cr_کلید;
    BLENDFUNCTION CONST *pblend;
    DWORD dwFlags;
    RECT CONST *prcDirty;
  } UPDATELAYEREDWINDOWINFO,*PUPDATELAYEREDWINDOWINFO;

  WINUSERAPI WINBOOL WINAPI Update_Layered_پنجره_غیرمستقیم(HWND hWnd,UPDATELAYEREDWINDOWINFO CONST *pULWInfo);
  WINUSERAPI WINBOOL WINAPI Get_Layered_پنجره_صفات(HWND hwnd,COLORREF *pcr_کلید,BYTE *pbAlpha,DWORD *pdwFlags);

#تعریف_کن PW_CLIENTONLY 0x00000001

  WINUSERAPI WINBOOL WINAPI Print_پنجره(HWND hwnd,HDC hdcBlt,UINT nFlags);
  WINUSERAPI WINBOOL WINAPI مجموعه_Layered_پنجره_صفات(HWND hwnd,COLORREF cr_کلید,BYTE bAlpha,DWORD dwFlags);

#تعریف_کن LWA_COLORKEY 0x00000001
#تعریف_کن LWA_ALPHA 0x00000002

#تعریف_کن ULW_COLORKEY 0x00000001
#تعریف_کن ULW_ALPHA 0x00000002
#تعریف_کن ULW_OPAQUE 0x00000004

#تعریف_کن ULW_EX_NORESIZE 0x00000008

  WINUSERAPI WINBOOL WINAPI Show_پنجره_Async(HWND hWnd,صحيح nCmdShow);
  WINUSERAPI WINBOOL WINAPI Flash_پنجره(HWND hWnd,WINBOOL bInvert);

  تعريفنوع بنية {
    UINT cb_اندازه;
    HWND hwnd;
    DWORD dwFlags;
    UINT u_شمار;
    DWORD dwTimeout;
  } FLASHWINFO,*PFLASHWINFO;

  WINUSERAPI WINBOOL WINAPI Flash_پنجره_Ex(PFLASHWINFO pfwi);

#تعریف_کن FLASHW_STOP 0
#تعریف_کن FLASHW_CAPTION 0x00000001
#تعریف_کن FLASHW_TRAY 0x00000002
#تعریف_کن FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#تعریف_کن FLASHW_TIMER 0x00000004
#تعریف_کن FLASHW_TIMERNOFG 0x0000000C

  WINUSERAPI WINBOOL WINAPI ShowOwnedPopups(HWND hWnd,WINBOOL fShow);
  WINUSERAPI WINBOOL WINAPI OpenIcon(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Close_پنجره(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Move_پنجره(HWND hWnd,صحيح X,صحيح Y,صحيح n_عرض,صحيح n_ارتفاع,WINBOOL bRepaint);
  WINUSERAPI WINBOOL WINAPI مجموعه_پنجره_Pos(HWND hWnd,HWND h_Wnd_درج_After,صحيح X,صحيح Y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI Get_پنجره_Placement(HWND hWnd,WINDOWPLACEMENT *lpwndpl);
  WINUSERAPI WINBOOL WINAPI مجموعه_پنجره_Placement(HWND hWnd,CONST WINDOWPLACEMENT *lpwndpl);

#اگر_تعریف_نشده NODEFERWINDOWPOS
  WINUSERAPI HDWP WINAPI Begin_Defer_پنجره_Pos(صحيح n_رقم_Windows);
  WINUSERAPI HDWP WINAPI Defer_پنجره_Pos(HDWP hWinPosInfo,HWND hWnd,HWND h_Wnd_درج_After,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI انتها_Defer_پنجره_Pos(HDWP hWinPosInfo);
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI Is_پنجره_Visible(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsIconic(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AnyPopup(VOID);
  WINUSERAPI WINBOOL WINAPI Bring_پنجره_مقصد_بالاترین(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsZoomed(HWND hWnd);

#تعریف_کن SWP_NOSIZE 0x0001
#تعریف_کن SWP_NOMOVE 0x0002
#تعریف_کن SWP_NOZORDER 0x0004
#تعریف_کن SWP_NOREDRAW 0x0008
#تعریف_کن SWP_NOACTIVATE 0x0010
#تعریف_کن SWP_FRAMECHANGED 0x0020
#تعریف_کن SWP_SHOWWINDOW 0x0040
#تعریف_کن SWP_HIDEWINDOW 0x0080
#تعریف_کن SWP_NOCOPYBITS 0x0100
#تعریف_کن SWP_NOOWNERZORDER 0x0200
#تعریف_کن SWP_NOSENDCHANGING 0x0400

#تعریف_کن SWP_DRAWFRAME SWP_FRAMECHANGED
#تعریف_کن SWP_NOREPOSITION SWP_NOOWNERZORDER
#تعریف_کن SWP_DEFERERASE 0x2000
#تعریف_کن SWP_ASYNCWINDOWPOS 0x4000

#تعریف_کن HWND_بالاترین ((HWND)0)
#تعریف_کن HWND_BOTTOM ((HWND)1)
#تعریف_کن HWND_TOPMOST ((HWND)-1)
#تعریف_کن HWND_NOTOPMOST ((HWND)-2)

#اگر_تعریف_نشده NOCTLMGR

#ضمن <pshpack2.h>

  تعريفنوع بنية {
    DWORD style;
    DWORD dwExtendedStyle;
    کلمه_3 cdit;
    کوتاه x;
    کوتاه y;
    کوتاه cx;
    کوتاه cy;
  } DLGTEMPLATE;

  تعريفنوع DLGTEMPLATE *LPDLGTEMPLATEA;
  تعريفنوع DLGTEMPLATE *LPDLGTEMPLATEW;

#اگر_تعریف_شده UNICODE
  تعريفنوع LPDLGTEMPLATEW LPDLGTEMPLATE;
#وإلا
  تعريفنوع LPDLGTEMPLATEA LPDLGTEMPLATE;
#پایان_اگر

  تعريفنوع CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
  تعريفنوع CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

#اگر_تعریف_شده UNICODE
  تعريفنوع LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#وإلا
  تعريفنوع LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#پایان_اگر

  تعريفنوع بنية {
    DWORD style;
    DWORD dwExtendedStyle;
    کوتاه x;
    کوتاه y;
    کوتاه cx;
    کوتاه cy;
    کلمه_3 id;
  } DLGITEMTEMPLATE;

  تعريفنوع DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
  تعريفنوع DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;

#اگر_تعریف_شده UNICODE
  تعريفنوع PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#وإلا
  تعريفنوع PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#پایان_اگر

  تعريفنوع DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
  تعريفنوع DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;

#اگر_تعریف_شده UNICODE
  تعريفنوع LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#وإلا
  تعريفنوع LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#پایان_اگر

#ضمن <poppack.h>

#اگر_تعریف_شده UNICODE
#تعریف_کن CreateDialogParam CreateDialogParamW
#تعریف_کن Create_Dialog_غیرمستقیم_Param Create_Dialog_غیرمستقیم_Param_W
#تعریف_کن CreateDialog CreateDialogW
#تعریف_کن Create_Dialog_غیرمستقیم Create_Dialog_غیرمستقیم_W
#تعریف_کن DialogBoxParam DialogBoxParamW
#تعریف_کن Dialog_Box_غیرمستقیم_Param Dialog_Box_غیرمستقیم_Param_W
#تعریف_کن DialogBox DialogBoxW
#تعریف_کن Dialog_Box_غیرمستقیم Dialog_Box_غیرمستقیم_W
#تعریف_کن مجموعه_Dlg_قلم_متن مجموعه_Dlg_قلم_متن_W
#تعریف_کن Get_Dlg_قلم_متن Get_Dlg_قلم_متن_W
#تعریف_کن Send_Dlg_قلم_پیام Send_Dlg_قلم_پیام_W
#تعریف_کن DefDlgProc DefDlgProcW
#وإلا
#تعریف_کن CreateDialogParam CreateDialogParamA
#تعریف_کن Create_Dialog_غیرمستقیم_Param Create_Dialog_غیرمستقیم_Param_A
#تعریف_کن CreateDialog CreateDialogA
#تعریف_کن Create_Dialog_غیرمستقیم Create_Dialog_غیرمستقیم_A
#تعریف_کن DialogBoxParam DialogBoxParamA
#تعریف_کن Dialog_Box_غیرمستقیم_Param Dialog_Box_غیرمستقیم_Param_A
#تعریف_کن DialogBox DialogBoxA
#تعریف_کن Dialog_Box_غیرمستقیم Dialog_Box_غیرمستقیم_A
#تعریف_کن مجموعه_Dlg_قلم_متن مجموعه_Dlg_قلم_متن_A
#تعریف_کن Get_Dlg_قلم_متن Get_Dlg_قلم_متن_A
#تعریف_کن Send_Dlg_قلم_پیام Send_Dlg_قلم_پیام_A
#تعریف_کن DefDlgProc DefDlgProcA
#پایان_اگر

  WINUSERAPI HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_غیرمستقیم_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_غیرمستقیم_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#تعریف_کن CreateDialogA(hInstance,lpName,h_Wnd_والد,lpDialogFunc) CreateDialogParamA(hInstance,lpName,h_Wnd_والد,lpDialogFunc,0L)
#تعریف_کن CreateDialogW(hInstance,lpName,h_Wnd_والد,lpDialogFunc) CreateDialogParamW(hInstance,lpName,h_Wnd_والد,lpDialogFunc,0L)
#تعریف_کن Create_Dialog_غیرمستقیم_A(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) Create_Dialog_غیرمستقیم_Param_A(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
#تعریف_کن Create_Dialog_غیرمستقیم_W(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) Create_Dialog_غیرمستقیم_Param_W(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
  WINUSERAPI INT_PTR WINAPI DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_غیرمستقیم_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_غیرمستقیم_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND h_Wnd_والد,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#تعریف_کن DialogBoxA(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
#تعریف_کن DialogBoxW(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
#تعریف_کن Dialog_Box_غیرمستقیم_A(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) Dialog_Box_غیرمستقیم_Param_A(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
#تعریف_کن Dialog_Box_غیرمستقیم_W(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc) Dialog_Box_غیرمستقیم_Param_W(hInstance,lpTemplate,h_Wnd_والد,lpDialogFunc,0L)
  WINUSERAPI WINBOOL WINAPI انتها_Dialog(HWND hDlg,INT_PTR n_نتیجه);
  WINUSERAPI HWND WINAPI Get_Dlg_قلم(HWND hDlg,صحيح n_IDDlg_قلم);
  WINUSERAPI WINBOOL WINAPI مجموعه_Dlg_قلم_Int(HWND hDlg,صحيح n_IDDlg_قلم,UINT u_مقدار,WINBOOL bSigned);
  WINUSERAPI UINT WINAPI Get_Dlg_قلم_Int(HWND hDlg,صحيح n_IDDlg_قلم,WINBOOL *lpTranslated,WINBOOL bSigned);
  WINUSERAPI WINBOOL WINAPI مجموعه_Dlg_قلم_متن_A(HWND hDlg,صحيح n_IDDlg_قلم,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI مجموعه_Dlg_قلم_متن_W(HWND hDlg,صحيح n_IDDlg_قلم,LPCWSTR lpString);
  WINUSERAPI UINT WINAPI Get_Dlg_قلم_متن_A(HWND hDlg,صحيح n_IDDlg_قلم,LPSTR lpString,صحيح cchMax);
  WINUSERAPI UINT WINAPI Get_Dlg_قلم_متن_W(HWND hDlg,صحيح n_IDDlg_قلم,LPWSTR lpString,صحيح cchMax);
  WINUSERAPI WINBOOL WINAPI CheckDlgButton(HWND hDlg,صحيح nIDButton,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI CheckRadioButton(HWND hDlg,صحيح nIDFirstButton,صحيح nIDLastButton,صحيح nIDCheckButton);
  WINUSERAPI UINT WINAPI IsDlgButtonChecked(HWND hDlg,صحيح nIDButton);
  WINUSERAPI LRESULT WINAPI Send_Dlg_قلم_پیام_A(HWND hDlg,صحيح n_IDDlg_قلم,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_Dlg_قلم_پیام_W(HWND hDlg,صحيح n_IDDlg_قلم,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI HWND WINAPI Get_بعدی_Dlg_گروه_قلم(HWND hDlg,HWND hCtl,WINBOOL b_قبلی);
  WINUSERAPI HWND WINAPI Get_بعدی_Dlg_Tab_قلم(HWND hDlg,HWND hCtl,WINBOOL b_قبلی);
  WINUSERAPI صحيح WINAPI GetDlgCtrlID(HWND hWnd);
  WINUSERAPI دراز WINAPI Get_Dialog_پایه_Units(VOID);
  WINUSERAPI LRESULT WINAPI DefDlgProcA(HWND hDlg,UINT پیام_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefDlgProcW(HWND hDlg,UINT پیام_5,WPARAM wParam,LPARAM lParam);

#تعریف_کن DLGWINDOWEXTRA 30
#پایان_اگر

#اگر_تعریف_نشده NOMSG

#اگر_تعریف_شده UNICODE
#تعریف_کن Call_پیام_Filter Call_پیام_Filter_W
#وإلا
#تعریف_کن Call_پیام_Filter Call_پیام_Filter_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI Call_پیام_Filter_A(LPMSG lp_پیام_2,صحيح n_کد);
  WINUSERAPI WINBOOL WINAPI Call_پیام_Filter_W(LPMSG lp_پیام_2,صحيح n_کد);
#پایان_اگر

#اگر_تعریف_نشده NOCLIPBOARD

#اگر_تعریف_شده UNICODE
#تعریف_کن ثبات_Clipboard_Format ثبات_Clipboard_Format_W
#تعریف_کن GetClipboardFormatName GetClipboardFormatNameW
#وإلا
#تعریف_کن ثبات_Clipboard_Format ثبات_Clipboard_Format_A
#تعریف_کن GetClipboardFormatName GetClipboardFormatNameA
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI OpenClipboard(HWND hWndNewOwner);
  WINUSERAPI WINBOOL WINAPI CloseClipboard(VOID);
  WINUSERAPI DWORD WINAPI Get_Clipboard_Sequence_عدد(VOID);
  WINUSERAPI HWND WINAPI GetClipboardOwner(VOID);
  WINUSERAPI HWND WINAPI مجموعه_Clipboard_Viewer(HWND hWndNewViewer);
  WINUSERAPI HWND WINAPI GetClipboardViewer(VOID);
  WINUSERAPI WINBOOL WINAPI ChangeClipboardChain(HWND hWndRemove,HWND h_Wnd_New_بعدی);
  WINUSERAPI HANDLE WINAPI مجموعه_Clipboard_داده(UINT uFormat,HANDLE hMem);
  WINUSERAPI HANDLE WINAPI Get_Clipboard_داده(UINT uFormat);
  WINUSERAPI UINT WINAPI ثبات_Clipboard_Format_A(LPCSTR lpszFormat);
  WINUSERAPI UINT WINAPI ثبات_Clipboard_Format_W(LPCWSTR lpszFormat);
  WINUSERAPI صحيح WINAPI شمار_Clipboard_Formats(VOID);
  WINUSERAPI UINT WINAPI EnumClipboardFormats(UINT format);
  WINUSERAPI صحيح WINAPI GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,صحيح cch_Max_شمار);
  WINUSERAPI صحيح WINAPI GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,صحيح cch_Max_شمار);
  WINUSERAPI WINBOOL WINAPI خالی_Clipboard(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Clipboard_Format_موجود(UINT format);
  WINUSERAPI صحيح WINAPI Get_اولویت_Clipboard_Format(UINT *pa_Format_اولویت_List,صحيح cFormats);
  WINUSERAPI HWND WINAPI Get_Open_Clipboard_پنجره(VOID);
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن Char_مقصد_Oem Char_مقصد_Oem_W
#تعریف_کن Oem_مقصد_Char Oem_مقصد_Char_W
#تعریف_کن Char_مقصد_Oem_Buff Char_مقصد_Oem_Buff_W
#تعریف_کن Oem_مقصد_Char_Buff Oem_مقصد_Char_Buff_W
#تعریف_کن Char_فوقانی Char_فوقانی_W
#تعریف_کن Char_فوقانی_Buff Char_فوقانی_Buff_W
#تعریف_کن Char_پایینی Char_پایینی_W
#تعریف_کن Char_پایینی_Buff Char_پایینی_Buff_W
#تعریف_کن Char_بعدی Char_بعدی_W
#تعریف_کن CharPrev CharPrevW
#وإلا
#تعریف_کن Char_مقصد_Oem Char_مقصد_Oem_A
#تعریف_کن Oem_مقصد_Char Oem_مقصد_Char_A
#تعریف_کن Char_مقصد_Oem_Buff Char_مقصد_Oem_Buff_A
#تعریف_کن Oem_مقصد_Char_Buff Oem_مقصد_Char_Buff_A
#تعریف_کن Char_فوقانی Char_فوقانی_A
#تعریف_کن Char_فوقانی_Buff Char_فوقانی_Buff_A
#تعریف_کن Char_پایینی Char_پایینی_A
#تعریف_کن Char_پایینی_Buff Char_پایینی_Buff_A
#تعریف_کن Char_بعدی Char_بعدی_A
#تعریف_کن CharPrev CharPrevA
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI Char_مقصد_Oem_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_مقصد_Oem_W(LPCWSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_مقصد_Char_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_مقصد_Char_W(LPCSTR lpszSrc,LPWSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_مقصد_Oem_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_درازی);
  WINUSERAPI WINBOOL WINAPI Char_مقصد_Oem_Buff_W(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_درازی);
  WINUSERAPI WINBOOL WINAPI Oem_مقصد_Char_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_درازی);
  WINUSERAPI WINBOOL WINAPI Oem_مقصد_Char_Buff_W(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cch_Dst_درازی);
  WINUSERAPI LPSTR WINAPI Char_فوقانی_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_فوقانی_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_فوقانی_Buff_A(LPSTR lpsz,DWORD cch_درازی);
  WINUSERAPI DWORD WINAPI Char_فوقانی_Buff_W(LPWSTR lpsz,DWORD cch_درازی);
  WINUSERAPI LPSTR WINAPI Char_پایینی_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_پایینی_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_پایینی_Buff_A(LPSTR lpsz,DWORD cch_درازی);
  WINUSERAPI DWORD WINAPI Char_پایینی_Buff_W(LPWSTR lpsz,DWORD cch_درازی);
  WINUSERAPI LPSTR WINAPI Char_بعدی_A(LPCSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_بعدی_W(LPCWSTR lpsz);
  WINUSERAPI LPSTR WINAPI CharPrevA(LPCSTR lpsz_شروع,LPCSTR lpszCurrent);
  WINUSERAPI LPWSTR WINAPI CharPrevW(LPCWSTR lpsz_شروع,LPCWSTR lpszCurrent);
  WINUSERAPI LPSTR WINAPI Char_بعدی_Ex_A(کلمه_3 کد_صفحه,LPCSTR lpCurrentChar,DWORD dwFlags);
  WINUSERAPI LPSTR WINAPI CharPrevExA(کلمه_3 کد_صفحه,LPCSTR lp_شروع,LPCSTR lpCurrentChar,DWORD dwFlags);

#تعریف_کن Ansi_مقصد_Oem Char_مقصد_Oem_A
#تعریف_کن Oem_مقصد_Ansi Oem_مقصد_Char_A
#تعریف_کن Ansi_مقصد_Oem_Buff Char_مقصد_Oem_Buff_A
#تعریف_کن Oem_مقصد_Ansi_Buff Oem_مقصد_Char_Buff_A
#تعریف_کن Ansi_فوقانی Char_فوقانی_A
#تعریف_کن Ansi_فوقانی_Buff Char_فوقانی_Buff_A
#تعریف_کن Ansi_پایینی Char_پایینی_A
#تعریف_کن Ansi_پایینی_Buff Char_پایینی_Buff_A
#تعریف_کن Ansi_بعدی Char_بعدی_A
#تعریف_کن AnsiPrev CharPrevA

#اگر_تعریف_نشده NOLANGUAGE

#اگر_تعریف_شده UNICODE
#تعریف_کن IsCharAlpha IsCharAlphaW
#تعریف_کن IsCharAlphaNumeric IsCharAlphaNumericW
#تعریف_کن Is_Char_فوقانی Is_Char_فوقانی_W
#تعریف_کن Is_Char_پایینی Is_Char_پایینی_W
#وإلا
#تعریف_کن IsCharAlpha IsCharAlphaA
#تعریف_کن IsCharAlphaNumeric IsCharAlphaNumericA
#تعریف_کن Is_Char_فوقانی Is_Char_فوقانی_A
#تعریف_کن Is_Char_پایینی Is_Char_پایینی_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI IsCharAlphaA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_فوقانی_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_فوقانی_W(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_پایینی_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_پایینی_W(WCHAR ch);
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_کلید_Name_متن Get_کلید_Name_متن_W
#تعریف_کن Vk_کلید_پیمایش Vk_کلید_پیمایش_W
#تعریف_کن Vk_کلید_پیمایش_Ex Vk_کلید_پیمایش_Ex_W
#وإلا
#تعریف_کن Get_کلید_Name_متن Get_کلید_Name_متن_A
#تعریف_کن Vk_کلید_پیمایش Vk_کلید_پیمایش_A
#تعریف_کن Vk_کلید_پیمایش_Ex Vk_کلید_پیمایش_Ex_A
#پایان_اگر

  WINUSERAPI HWND WINAPI مجموعه_Focus(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_فعال_پنجره(VOID);
  WINUSERAPI HWND WINAPI GetFocus(VOID);
  WINUSERAPI UINT WINAPI Get_KBCode_صفحه(VOID);
  WINUSERAPI SHORT WINAPI Get_کلید_State(صحيح n_Virt_کلید);
  WINUSERAPI SHORT WINAPI Get_Async_کلید_State(صحيح v_کلید);
  WINUSERAPI WINBOOL WINAPI GetKeyboardState(PBYTE lp_کلید_State);
  WINUSERAPI WINBOOL WINAPI مجموعه_Keyboard_State(LPBYTE lp_کلید_State);
  WINUSERAPI صحيح WINAPI Get_کلید_Name_متن_A(LONG lParam,LPSTR lpString,صحيح cch_اندازه);
  WINUSERAPI صحيح WINAPI Get_کلید_Name_متن_W(LONG lParam,LPWSTR lpString,صحيح cch_اندازه);
  WINUSERAPI صحيح WINAPI GetKeyboardType(صحيح nTypeFlag);
  WINUSERAPI صحيح WINAPI مقصد_Ascii(UINT u_Virt_کلید,UINT u_پیمایش_کد,CONST BYTE *lp_کلید_State,LPWORD lpChar,UINT uFlags);
  WINUSERAPI صحيح WINAPI مقصد_Ascii_Ex(UINT u_Virt_کلید,UINT u_پیمایش_کد,CONST BYTE *lp_کلید_State,LPWORD lpChar,UINT uFlags,HKL dwhkl);
  WINUSERAPI صحيح WINAPI مقصد_Unicode(UINT w_Virt_کلید,UINT w_پیمایش_کد,CONST BYTE *lp_کلید_State,LPWSTR pwszBuff,صحيح cchBuff,UINT wFlags);
  WINUSERAPI DWORD WINAPI Oem_کلید_پیمایش(کلمه_3 wOemChar);
  WINUSERAPI SHORT WINAPI Vk_کلید_پیمایش_A(CHAR ch);
  WINUSERAPI SHORT WINAPI Vk_کلید_پیمایش_W(WCHAR ch);
  WINUSERAPI SHORT WINAPI Vk_کلید_پیمایش_Ex_A(CHAR ch,HKL dwhkl);
  WINUSERAPI SHORT WINAPI Vk_کلید_پیمایش_Ex_W(WCHAR ch,HKL dwhkl);

#تعریف_کن KEYEVENTF_EXTENDEDKEY 0x0001
#تعریف_کن KEYEVENTF_KEYUP 0x0002
#تعریف_کن KEYEVENTF_UNICODE 0x0004
#تعریف_کن KEYEVENTF_SCANCODE 0x0008

  WINUSERAPI VOID WINAPI keybd_event(BYTE bVk,BYTE b_پیمایش,DWORD dwFlags,ULONG_PTR dwExtraInfo);

#تعریف_کن MOUSEEVENTF_MOVE 0x0001
#تعریف_کن MOUSEEVENTF_LEFTDOWN 0x0002
#تعریف_کن MOUSEEVENTF_LEFTUP 0x0004
#تعریف_کن MOUSEEVENTF_RIGHTDOWN 0x0008
#تعریف_کن MOUSEEVENTF_RIGHTUP 0x0010
#تعریف_کن MOUSEEVENTF_MIDDLEDOWN 0x0020
#تعریف_کن MOUSEEVENTF_MIDDLEUP 0x0040
#تعریف_کن MOUSEEVENTF_XDOWN 0x0080
#تعریف_کن MOUSEEVENTF_XUP 0x0100
#تعریف_کن MOUSEEVENTF_WHEEL 0x0800
#تعریف_کن MOUSEEVENTF_VIRTUALDESK 0x4000
#تعریف_کن MOUSEEVENTF_ABSOLUTE 0x8000

  WINUSERAPI VOID WINAPI mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dw_داده,ULONG_PTR dwExtraInfo);

  تعريفنوع بنية برچسب_MOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouse_داده;
    DWORD dwFlags;
    DWORD زمان;
    ULONG_PTR dwExtraInfo;
  } MOUSEINPUT,*PMOUSEINPUT,*LPMOUSEINPUT;

  تعريفنوع بنية برچسب_KEYBDINPUT {
    کلمه_3 wVk;
    کلمه_3 w_پیمایش;
    DWORD dwFlags;
    DWORD زمان;
    ULONG_PTR dwExtraInfo;
  } KEYBDINPUT,*PKEYBDINPUT,*LPKEYBDINPUT;

  تعريفنوع بنية برچسب_HARDWAREINPUT {
    DWORD u_پیام;
    کلمه_3 wParamL;
    کلمه_3 wParamH;
  } HARDWAREINPUT,*PHARDWAREINPUT,*LPHARDWAREINPUT;

#تعریف_کن درون_داد_MOUSE 0
#تعریف_کن درون_داد_KEYBOARD 1
#تعریف_کن درون_داد_HARDWARE 2

  تعريفنوع بنية برچسب_درون_داد {
    DWORD type;
    اتحاد {
      MOUSEINPUT mi;
      KEYBDINPUT ki;
      HARDWAREINPUT hi;
    };
  } درون_داد_2,*PINPUT,*LPINPUT;

  WINUSERAPI UINT WINAPI Send_درون_داد(UINT cInputs,LPINPUT pInputs,صحيح cb_اندازه);

  تعريفنوع بنية برچسب_LASTINPUTINFO {
    UINT cb_اندازه;
    DWORD dw_زمان;
  } LASTINPUTINFO,*PLASTINPUTINFO;

#اگر_تعریف_شده UNICODE
#تعریف_کن Map_Virtual_کلید Map_Virtual_کلید_W
#تعریف_کن Map_Virtual_کلید_Ex Map_Virtual_کلید_Ex_W
#وإلا
#تعریف_کن Map_Virtual_کلید Map_Virtual_کلید_A
#تعریف_کن Map_Virtual_کلید_Ex Map_Virtual_کلید_Ex_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI Get_آخرین_درون_داد_Info(PLASTINPUTINFO plii);
  WINUSERAPI UINT WINAPI Map_Virtual_کلید_A(UINT u_کد,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_کلید_W(UINT u_کد,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_کلید_Ex_A(UINT u_کد,UINT uMapType,HKL dwhkl);
  WINUSERAPI UINT WINAPI Map_Virtual_کلید_Ex_W(UINT u_کد,UINT uMapType,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI Get_درون_داد_State(VOID);
  WINUSERAPI DWORD WINAPI Get_صف_وضعیت(UINT flags);
  WINUSERAPI HWND WINAPI GetCapture(VOID);
  WINUSERAPI HWND WINAPI مجموعه_Capture(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ReleaseCapture(VOID);
  WINUSERAPI DWORD WINAPI پیام_Wait_For_مضرب_Objects(DWORD n_شمار,CONST HANDLE *pHandles,WINBOOL fWaitAll,DWORD dwMilliseconds,DWORD dw_Wake_ماسک);
  WINUSERAPI DWORD WINAPI پیام_Wait_For_مضرب_Objects_Ex(DWORD n_شمار,CONST HANDLE *pHandles,DWORD dwMilliseconds,DWORD dw_Wake_ماسک,DWORD dwFlags);

#تعریف_کن MWMO_WAITALL 0x0001
#تعریف_کن MWMO_ALERTABLE 0x0002
#تعریف_کن MWMO_INPUTAVAILABLE 0x0004

#تعریف_کن QS_کلید 0x0001
#تعریف_کن QS_MOUSEMOVE 0x0002
#تعریف_کن QS_MOUSEBUTTON 0x0004
#تعریف_کن QS_POSTMESSAGE 0x0008
#تعریف_کن QS_TIMER 0x0010
#تعریف_کن QS_PAINT 0x0020
#تعریف_کن QS_SENDMESSAGE 0x0040
#تعریف_کن QS_HOTKEY 0x0080
#تعریف_کن QS_ALLPOSTMESSAGE 0x0100
#تعریف_کن QS_RAWINPUT 0x0400
#تعریف_کن QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#تعریف_کن QS_درون_داد (QS_MOUSE | QS_کلید | QS_RAWINPUT)
#تعریف_کن QS_ALLEVENTS (QS_درون_داد | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#تعریف_کن QS_ALLINPUT (QS_درون_داد | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#تعریف_کن USER_TIMER_بیشینه 0x7FFFFFFF
#تعریف_کن USER_TIMER_MINIMUM 0x0000000A

#اگر_تعریف_شده UNICODE
#تعریف_کن بارگیری_Accelerators بارگیری_Accelerators_W
#تعریف_کن Create_Accelerator_جدول Create_Accelerator_جدول_W
#تعریف_کن Copy_Accelerator_جدول Copy_Accelerator_جدول_W
#وإلا
#تعریف_کن بارگیری_Accelerators بارگیری_Accelerators_A
#تعریف_کن Create_Accelerator_جدول Create_Accelerator_جدول_A
#تعریف_کن Copy_Accelerator_جدول Copy_Accelerator_جدول_A
#پایان_اگر

  WINUSERAPI UINT_PTR WINAPI مجموعه_Timer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
  WINUSERAPI WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);
  WINUSERAPI WINBOOL WINAPI Is_پنجره_Unicode(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Enable_پنجره(HWND hWnd,WINBOOL bEnable);
  WINUSERAPI WINBOOL WINAPI Is_پنجره_Enabled(HWND hWnd);
  WINUSERAPI HACCEL WINAPI بارگیری_Accelerators_A(HINSTANCE hInstance,LPCSTR lp_جدول_Name);
  WINUSERAPI HACCEL WINAPI بارگیری_Accelerators_W(HINSTANCE hInstance,LPCWSTR lp_جدول_Name);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_جدول_A(LPACCEL paccel,صحيح cAccel);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_جدول_W(LPACCEL paccel,صحيح cAccel);
  WINUSERAPI WINBOOL WINAPI Destroy_Accelerator_جدول(HACCEL hAccel);
  WINUSERAPI صحيح WINAPI Copy_Accelerator_جدول_A(HACCEL hAccelSrc,LPACCEL lpAccelDst,صحيح cAccelEntries);
  WINUSERAPI صحيح WINAPI Copy_Accelerator_جدول_W(HACCEL hAccelSrc,LPACCEL lpAccelDst,صحيح cAccelEntries);

#اگر_تعریف_نشده NOMSG

#اگر_تعریف_شده UNICODE
#تعریف_کن TranslateAccelerator TranslateAcceleratorW
#وإلا
#تعریف_کن TranslateAccelerator TranslateAcceleratorA
#پایان_اگر

  WINUSERAPI صحيح WINAPI TranslateAcceleratorA(HWND hWnd,HACCEL h_Acc_جدول,LPMSG lp_پیام_2);
  WINUSERAPI صحيح WINAPI TranslateAcceleratorW(HWND hWnd,HACCEL h_Acc_جدول,LPMSG lp_پیام_2);
#پایان_اگر

#اگر_تعریف_نشده NOSYSMETRICS

#تعریف_کن SM_CXSCREEN 0
#تعریف_کن SM_CYSCREEN 1
#تعریف_کن SM_CXVSCROLL 2
#تعریف_کن SM_CYHSCROLL 3
#تعریف_کن SM_CYCAPTION 4
#تعریف_کن SM_CXBORDER 5
#تعریف_کن SM_CYBORDER 6
#تعریف_کن SM_CXDLGFRAME 7
#تعریف_کن SM_CYDLGFRAME 8
#تعریف_کن SM_CYVTHUMB 9
#تعریف_کن SM_CXHTHUMB 10
#تعریف_کن SM_CXICON 11
#تعریف_کن SM_CYICON 12
#تعریف_کن SM_CXCURSOR 13
#تعریف_کن SM_CYCURSOR 14
#تعریف_کن SM_CYMENU 15
#تعریف_کن SM_CXFULLSCREEN 16
#تعریف_کن SM_CYFULLSCREEN 17
#تعریف_کن SM_CYKANJIWINDOW 18
#تعریف_کن SM_MOUSEPRESENT 19
#تعریف_کن SM_CYVSCROLL 20
#تعریف_کن SM_CXHSCROLL 21
#تعریف_کن SM_DEBUG 22
#تعریف_کن SM_SWAPBUTTON 23
#تعریف_کن SM_RESERVED1 24
#تعریف_کن SM_RESERVED2 25
#تعریف_کن SM_RESERVED3 26
#تعریف_کن SM_RESERVED4 27
#تعریف_کن SM_CXMIN 28
#تعریف_کن SM_CYMIN 29
#تعریف_کن SM_CXSIZE 30
#تعریف_کن SM_CYSIZE 31
#تعریف_کن SM_CXFRAME 32
#تعریف_کن SM_CYFRAME 33
#تعریف_کن SM_CXMINTRACK 34
#تعریف_کن SM_CYMINTRACK 35
#تعریف_کن SM_CXDOUBLECLK 36
#تعریف_کن SM_CYDOUBLECLK 37
#تعریف_کن SM_CXICONSPACING 38
#تعریف_کن SM_CYICONSPACING 39
#تعریف_کن SM_MENUDROPALIGNMENT 40
#تعریف_کن SM_PENWINDOWS 41
#تعریف_کن SM_DBCSENABLED 42
#تعریف_کن SM_CMOUSEBUTTONS 43

#تعریف_کن SM_CXFIXEDFRAME SM_CXDLGFRAME
#تعریف_کن SM_CYFIXEDFRAME SM_CYDLGFRAME
#تعریف_کن SM_CXSIZEFRAME SM_CXFRAME
#تعریف_کن SM_CYSIZEFRAME SM_CYFRAME

#تعریف_کن SM_SECURE 44
#تعریف_کن SM_CXEDGE 45
#تعریف_کن SM_CYEDGE 46
#تعریف_کن SM_CXMINSPACING 47
#تعریف_کن SM_CYMINSPACING 48
#تعریف_کن SM_CXSMICON 49
#تعریف_کن SM_CYSMICON 50
#تعریف_کن SM_CYSMCAPTION 51
#تعریف_کن SM_CXSMSIZE 52
#تعریف_کن SM_CYSMSIZE 53
#تعریف_کن SM_CXMENUSIZE 54
#تعریف_کن SM_CYMENUSIZE 55
#تعریف_کن SM_ARRANGE 56
#تعریف_کن SM_CXMINIMIZED 57
#تعریف_کن SM_CYMINIMIZED 58
#تعریف_کن SM_CXMAXTRACK 59
#تعریف_کن SM_CYMAXTRACK 60
#تعریف_کن SM_CXMAXIMIZED 61
#تعریف_کن SM_CYMAXIMIZED 62
#تعریف_کن SM_شبکه 63
#تعریف_کن SM_CLEANBOOT 67
#تعریف_کن SM_CXDRAG 68
#تعریف_کن SM_CYDRAG 69
#تعریف_کن SM_SHOWSOUNDS 70
#تعریف_کن SM_CXMENUCHECK 71
#تعریف_کن SM_CYMENUCHECK 72
#تعریف_کن SM_SLOWMACHINE 73
#تعریف_کن SM_MIDEASTENABLED 74
#تعریف_کن SM_MOUSEWHEELPRESENT 75
#تعریف_کن SM_XVIRTUALSCREEN 76
#تعریف_کن SM_YVIRTUALSCREEN 77
#تعریف_کن SM_CXVIRTUALSCREEN 78
#تعریف_کن SM_CYVIRTUALSCREEN 79
#تعریف_کن SM_CMONITORS 80
#تعریف_کن SM_SAMEDISPLAYFORMAT 81
#تعریف_کن SM_IMMENABLED 82
#تعریف_کن SM_CXFOCUSBORDER 83
#تعریف_کن SM_CYFOCUSBORDER 84
#تعریف_کن SM_TABLETPC 86
#تعریف_کن SM_MEDIACENTER 87
#تعریف_کن SM_STARTER 88
#تعریف_کن SM_SERVERR2 89
#تعریف_کن SM_CMETRICS 90
#تعریف_کن SM_REMOTESESSION 0x1000
#تعریف_کن SM_SHUTTINGDOWN 0x2000
#تعریف_کن SM_REMOTECONTROL 0x2001
#تعریف_کن SM_CARETBLINKINGENABLED 0x2002

  WINUSERAPI صحيح WINAPI GetSystemMetrics(صحيح n_شاخص);
#پایان_اگر

#اگر_تعریف_نشده NOMENUS

#اگر_تعریف_شده UNICODE
#تعریف_کن بارگیری_Menu بارگیری_Menu_W
#تعریف_کن بارگیری_Menu_غیرمستقیم بارگیری_Menu_غیرمستقیم_W
#تعریف_کن ChangeMenu ChangeMenuW
#تعریف_کن GetMenuString GetMenuStringW
#تعریف_کن درج_Menu درج_Menu_W
#تعریف_کن AppendMenu AppendMenuW
#تعریف_کن ModifyMenu ModifyMenuW
#وإلا
#تعریف_کن بارگیری_Menu بارگیری_Menu_A
#تعریف_کن بارگیری_Menu_غیرمستقیم بارگیری_Menu_غیرمستقیم_A
#تعریف_کن ChangeMenu ChangeMenuA
#تعریف_کن GetMenuString GetMenuStringA
#تعریف_کن درج_Menu درج_Menu_A
#تعریف_کن AppendMenu AppendMenuA
#تعریف_کن ModifyMenu ModifyMenuA
#پایان_اگر

  WINUSERAPI HMENU WINAPI بارگیری_Menu_A(HINSTANCE hInstance,LPCSTR lpMenuName);
  WINUSERAPI HMENU WINAPI بارگیری_Menu_W(HINSTANCE hInstance,LPCWSTR lpMenuName);
  WINUSERAPI HMENU WINAPI بارگیری_Menu_غیرمستقیم_A(CONST MENUTEMPLATEA *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI بارگیری_Menu_غیرمستقیم_W(CONST MENUTEMPLATEW *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI GetMenu(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI مجموعه_Menu(HWND hWnd,HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpsz_New_قلم,UINT cmd_درج,UINT flags);
  WINUSERAPI WINBOOL WINAPI ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpsz_New_قلم,UINT cmd_درج,UINT flags);
  WINUSERAPI WINBOOL WINAPI Hilite_Menu_قلم(HWND hWnd,HMENU hMenu,UINT u_IDHilite_قلم,UINT uHilite);
  WINUSERAPI صحيح WINAPI GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,صحيح cchMax,UINT flags);
  WINUSERAPI صحيح WINAPI GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,صحيح cchMax,UINT flags);
  WINUSERAPI UINT WINAPI GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawMenuBar(HWND hWnd);

#تعریف_کن PMB_فعال 0x00000001

  WINUSERAPI HMENU WINAPI GetSystemMenu(HWND hWnd,WINBOOL bRevert);
  WINUSERAPI HMENU WINAPI CreateMenu(VOID);
  WINUSERAPI HMENU WINAPI CreatePopupMenu(VOID);
  WINUSERAPI WINBOOL WINAPI DestroyMenu(HMENU hMenu);
  WINUSERAPI DWORD WINAPI Check_Menu_قلم(HMENU hMenu,UINT u_IDCheck_قلم,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI Enable_Menu_قلم(HMENU hMenu,UINT u_IDEnable_قلم,UINT uEnable);
  WINUSERAPI HMENU WINAPI GetSubMenu(HMENU hMenu,صحيح nPos);
  WINUSERAPI UINT WINAPI Get_Menu_قلم_ID(HMENU hMenu,صحيح nPos);
  WINUSERAPI صحيح WINAPI Get_Menu_قلم_شمار(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI درج_Menu_A(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_قلم,LPCSTR lp_New_قلم);
  WINUSERAPI WINBOOL WINAPI درج_Menu_W(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_قلم,LPCWSTR lp_New_قلم);
  WINUSERAPI WINBOOL WINAPI AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_قلم,LPCSTR lp_New_قلم);
  WINUSERAPI WINBOOL WINAPI AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_قلم,LPCWSTR lp_New_قلم);
  WINUSERAPI WINBOOL WINAPI ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_قلم,LPCSTR lp_New_قلم);
  WINUSERAPI WINBOOL WINAPI ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_قلم,LPCWSTR lp_New_قلم);
  WINUSERAPI WINBOOL WINAPI RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI مجموعه_Menu_قلم_Bitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
  WINUSERAPI LONG WINAPI GetMenuCheckMarkDimensions(VOID);
  WINUSERAPI WINBOOL WINAPI TrackPopupMenu(HMENU hMenu,UINT uFlags,صحيح x,صحيح y,صحيح nReserved,HWND hWnd,CONST RECT *prcRect);

#تعریف_کن MNC_IGNORE 0
#تعریف_کن MNC_CLOSE 1
#تعریف_کن MNC_EXECUTE 2
#تعریف_کن MNC_SELECT 3

  تعريفنوع بنية برچسب_TPMPARAMS {
    UINT cb_اندازه;
    RECT rcExclude;
  } TPMPARAMS;

  تعريفنوع TPMPARAMS *LPTPMPARAMS;

  WINUSERAPI WINBOOL WINAPI TrackPopupMenuEx(HMENU,UINT,صحيح,صحيح,HWND,LPTPMPARAMS);

#تعریف_کن MNS_NOCHECK 0x80000000
#تعریف_کن MNS_MODELESS 0x40000000
#تعریف_کن MNS_DRAGDROP 0x20000000
#تعریف_کن MNS_AUTODISMISS 0x10000000
#تعریف_کن MNS_NOTIFYBYPOS 0x08000000
#تعریف_کن MNS_CHECKORBMP 0x04000000

#تعریف_کن MIM_MAXHEIGHT 0x00000001
#تعریف_کن MIM_BACKGROUND 0x00000002
#تعریف_کن MIM_HELPID 0x00000004
#تعریف_کن MIM_MENUDATA 0x00000008
#تعریف_کن MIM_STYLE 0x00000010
#تعریف_کن MIM_APPLYTOSUBMENUS 0x80000000

  تعريفنوع بنية برچسب_MENUINFO {
    DWORD cb_اندازه;
    DWORD f_ماسک;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbr_پشت;
    DWORD dwContextHelpID;
    ULONG_PTR dw_Menu_داده;
  } MENUINFO,*LPMENUINFO;

  تعريفنوع MENUINFO CONST *LPCMENUINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuInfo(HMENU,LPMENUINFO);
  WINUSERAPI WINBOOL WINAPI مجموعه_Menu_Info(HMENU,LPCMENUINFO);
  WINUSERAPI WINBOOL WINAPI انتها_Menu(VOID);

#تعریف_کن MND_CONTINUE 0
#تعریف_کن MND_ENDMENU 1

  تعريفنوع بنية برچسب_MENUGETOBJECTINFO {
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
  } MENUGETOBJECTINFO,*PMENUGETOBJECTINFO;

#تعریف_کن MNGOF_TOPGAP 0x00000001
#تعریف_کن MNGOF_BOTTOMGAP 0x00000002

#تعریف_کن MNGO_NOINTERFACE 0x00000000
#تعریف_کن MNGO_NOERROR 0x00000001

#تعریف_کن MIIM_STATE 0x00000001
#تعریف_کن MIIM_ID 0x00000002
#تعریف_کن MIIM_SUBMENU 0x00000004
#تعریف_کن MIIM_CHECKMARKS 0x00000008
#تعریف_کن MIIM_TYPE 0x00000010
#تعریف_کن MIIM_داده 0x00000020

#تعریف_کن MIIM_STRING 0x00000040
#تعریف_کن MIIM_BITMAP 0x00000080
#تعریف_کن MIIM_FTYPE 0x00000100

#تعریف_کن HBMMENU_CALLBACK ((HBITMAP) -1)
#تعریف_کن HBMMENU_SYSTEM ((HBITMAP) 1)
#تعریف_کن HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#تعریف_کن HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#تعریف_کن HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#تعریف_کن HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#تعریف_کن HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#تعریف_کن HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#تعریف_کن HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#تعریف_کن HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#تعریف_کن HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

  تعريفنوع بنية برچسب_MENUITEMINFOA {
    UINT cb_اندازه;
    UINT f_ماسک;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_قلم_داده;
    LPSTR dw_Type_داده;
    UINT cch;
    HBITMAP hbmp_قلم;
  } MENUITEMINFOA,*LPMENUITEMINFOA;

  تعريفنوع بنية برچسب_MENUITEMINFOW {
    UINT cb_اندازه;
    UINT f_ماسک;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_قلم_داده;
    LPWSTR dw_Type_داده;
    UINT cch;
    HBITMAP hbmp_قلم;
  } MENUITEMINFOW,*LPMENUITEMINFOW;

#اگر_تعریف_شده UNICODE
  تعريفنوع MENUITEMINFOW MENUITEMINFO;
  تعريفنوع LPMENUITEMINFOW LPMENUITEMINFO;
#وإلا
  تعريفنوع MENUITEMINFOA MENUITEMINFO;
  تعريفنوع LPMENUITEMINFOA LPMENUITEMINFO;
#پایان_اگر
  تعريفنوع MENUITEMINFOA CONST *LPCMENUITEMINFOA;
  تعريفنوع MENUITEMINFOW CONST *LPCMENUITEMINFOW;
#اگر_تعریف_شده UNICODE
  تعريفنوع LPCMENUITEMINFOW LPCMENUITEMINFO;
#وإلا
  تعريفنوع LPCMENUITEMINFOA LPCMENUITEMINFO;
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن درج_Menu_قلم درج_Menu_قلم_W
#تعریف_کن Get_Menu_قلم_Info Get_Menu_قلم_Info_W
#تعریف_کن مجموعه_Menu_قلم_Info مجموعه_Menu_قلم_Info_W
#وإلا
#تعریف_کن درج_Menu_قلم درج_Menu_قلم_A
#تعریف_کن Get_Menu_قلم_Info Get_Menu_قلم_Info_A
#تعریف_کن مجموعه_Menu_قلم_Info مجموعه_Menu_قلم_Info_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI درج_Menu_قلم_A(HMENU hmenu,UINT قلم,WINBOOL fByPosition,LPCMENUITEMINFOA lpmi);
  WINUSERAPI WINBOOL WINAPI درج_Menu_قلم_W(HMENU hmenu,UINT قلم,WINBOOL fByPosition,LPCMENUITEMINFOW lpmi);
  WINUSERAPI WINBOOL WINAPI Get_Menu_قلم_Info_A(HMENU hmenu,UINT قلم,WINBOOL fByPosition,LPMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI Get_Menu_قلم_Info_W(HMENU hmenu,UINT قلم,WINBOOL fByPosition,LPMENUITEMINFOW lpmii);
  WINUSERAPI WINBOOL WINAPI مجموعه_Menu_قلم_Info_A(HMENU hmenu,UINT قلم,WINBOOL fByPositon,LPCMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI مجموعه_Menu_قلم_Info_W(HMENU hmenu,UINT قلم,WINBOOL fByPositon,LPCMENUITEMINFOW lpmii);

#تعریف_کن GMDI_USEDISABLED 0x0001L
#تعریف_کن GMDI_GOINTOPOPUPS 0x0002L

  WINUSERAPI UINT WINAPI Get_Menu_Default_قلم(HMENU hMenu,UINT fByPos,UINT gmdiFlags);
  WINUSERAPI WINBOOL WINAPI مجموعه_Menu_Default_قلم(HMENU hMenu,UINT u_قلم,UINT fByPos);
  WINUSERAPI WINBOOL WINAPI Get_Menu_قلم_Rect(HWND hWnd,HMENU hMenu,UINT u_قلم,LPRECT lprc_قلم);
  WINUSERAPI صحيح WINAPI Menu_قلم_From_نقطه(HWND hWnd,HMENU hMenu,نقطه_3 ptScreen);

#تعریف_کن TPM_LEFTBUTTON 0x0000L
#تعریف_کن TPM_RIGHTBUTTON 0x0002L
#تعریف_کن TPM_LEFTALIGN 0x0000L
#تعریف_کن TPM_CENTERALIGN 0x0004L
#تعریف_کن TPM_RIGHTALIGN 0x0008L
#تعریف_کن TPM_TOPALIGN 0x0000L
#تعریف_کن TPM_VCENTERALIGN 0x0010L
#تعریف_کن TPM_BOTTOMALIGN 0x0020L

#تعریف_کن TPM_HORIZONTAL 0x0000L
#تعریف_کن TPM_VERTICAL 0x0040L
#تعریف_کن TPM_NONOTIFY 0x0080L
#تعریف_کن TPM_RETURNCMD 0x0100L
#تعریف_کن TPM_RECURSE 0x0001L
#تعریف_کن TPM_HORPOSANIMATION 0x0400L
#تعریف_کن TPM_HORNEGANIMATION 0x0800L
#تعریف_کن TPM_VERPOSANIMATION 0x1000L
#تعریف_کن TPM_VERNEGANIMATION 0x2000L
#تعریف_کن TPM_NOANIMATION 0x4000L
#تعریف_کن TPM_LAYOUTRTL 0x8000L
#پایان_اگر

  تعريفنوع بنية برچسب_DROPSTRUCT {
    HWND hwnd_منبع;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dw_داده;
    نقطه_3 ptDrop;
    DWORD dw_Control_داده;
  } DROPSTRUCT,*PDROPSTRUCT,*LPDROPSTRUCT;

#تعریف_کن DOF_EXECUTABLE 0x8001
#تعریف_کن DOF_DOCUMENT 0x8002
#تعریف_کن DOF_DIRECTORY 0x8003
#تعریف_کن DOF_مضرب 0x8004
#تعریف_کن DOF_PROGMAN 0x0001
#تعریف_کن DOF_SHELLDATA 0x0002

#تعریف_کن DO_DROPFILE 0x454C4946L
#تعریف_کن DO_PRINTFILE 0x544E5250L

  WINUSERAPI DWORD WINAPI DragObject(HWND hwnd_والد_2,HWND hwndFrom,UINT fmt,ULONG_PTR داده,HCURSOR hcur);
  WINUSERAPI WINBOOL WINAPI DragDetect(HWND hwnd,نقطه_3 pt);
  WINUSERAPI WINBOOL WINAPI DrawIcon(HDC hDC,صحيح X,صحيح Y,HICON hIcon);

#اگر_تعریف_نشده NODRAWTEXT

#تعریف_کن DT_بالاترین 0x00000000
#تعریف_کن DT_چپ 0x00000000
#تعریف_کن DT_CENTER 0x00000001
#تعریف_کن DT_راست 0x00000002
#تعریف_کن DT_VCENTER 0x00000004
#تعریف_کن DT_BOTTOM 0x00000008
#تعریف_کن DT_WORDBREAK 0x00000010
#تعریف_کن DT_SINGLELINE 0x00000020
#تعریف_کن DT_EXPANDTABS 0x00000040
#تعریف_کن DT_TABSTOP 0x00000080
#تعریف_کن DT_NOCLIP 0x00000100
#تعریف_کن DT_EXTERNALLEADING 0x00000200
#تعریف_کن DT_CALCRECT 0x00000400
#تعریف_کن DT_NOPREFIX 0x00000800
#تعریف_کن DT_داخلی 0x00001000

#تعریف_کن DT_EDITCONTROL 0x00002000
#تعریف_کن DT_مسیر_ELLIPSIS 0x00004000
#تعریف_کن DT_انتها_ELLIPSIS 0x00008000
#تعریف_کن DT_MODIFYSTRING 0x00010000
#تعریف_کن DT_RTLREADING 0x00020000
#تعریف_کن DT_کلمه_ELLIPSIS 0x00040000
#تعریف_کن DT_NOFULLWIDTHCHARBREAK 0x00080000
#تعریف_کن DT_HIDEPREFIX 0x00100000
#تعریف_کن DT_PREFIXONLY 0x00200000

  تعريفنوع بنية برچسب_DRAWTEXTPARAMS {
    UINT cb_اندازه;
    صحيح i_Tab_درازی;
    صحيح i_چپ_Margin;
    صحيح i_راست_Margin;
    UINT ui_درازی_Drawn;
  } DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

#اگر_تعریف_شده UNICODE
#تعریف_کن Draw_متن Draw_متن_W
#تعریف_کن Draw_متن_Ex Draw_متن_Ex_W
#وإلا
#تعریف_کن Draw_متن Draw_متن_A
#تعریف_کن Draw_متن_Ex Draw_متن_Ex_A
#پایان_اگر

  WINUSERAPI صحيح WINAPI Draw_متن_A(HDC hdc,LPCSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format);
  WINUSERAPI صحيح WINAPI Draw_متن_W(HDC hdc,LPCWSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format);
  WINUSERAPI صحيح WINAPI Draw_متن_Ex_A(HDC hdc,LPSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
  WINUSERAPI صحيح WINAPI Draw_متن_Ex_W(HDC hdc,LPWSTR lpch_متن,صحيح cch_متن,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن خاکستری_String خاکستری_String_W
#تعریف_کن DrawState DrawStateW
#تعریف_کن Tabbed_متن_بیرون Tabbed_متن_بیرون_W
#تعریف_کن Get_Tabbed_متن_Extent Get_Tabbed_متن_Extent_W
#وإلا
#تعریف_کن خاکستری_String خاکستری_String_A
#تعریف_کن DrawState DrawStateA
#تعریف_کن Tabbed_متن_بیرون Tabbed_متن_بیرون_A
#تعریف_کن Get_Tabbed_متن_Extent Get_Tabbed_متن_Extent_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI خاکستری_String_A(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_داده,صحيح n_شمار,صحيح X,صحيح Y,صحيح n_عرض,صحيح n_ارتفاع);
  WINUSERAPI WINBOOL WINAPI خاکستری_String_W(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_داده,صحيح n_شمار,صحيح X,صحيح Y,صحيح n_عرض,صحيح n_ارتفاع);

#تعریف_کن DST_COMPLEX 0x0000
#تعریف_کن DST_متن 0x0001
#تعریف_کن DST_PREFIXTEXT 0x0002
#تعریف_کن DST_ICON 0x0003
#تعریف_کن DST_BITMAP 0x0004

#تعریف_کن DSS_نرمال 0x0000
#تعریف_کن DSS_UNION 0x0010
#تعریف_کن DSS_DISABLED 0x0020
#تعریف_کن DSS_MONO 0x0080
#تعریف_کن DSS_HIDEPREFIX 0x0200
#تعریف_کن DSS_PREFIXONLY 0x0400
#تعریف_کن DSS_راست 0x8000

  WINUSERAPI WINBOOL WINAPI DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_پشت,LPARAM l_داده,WPARAM w_داده,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_پشت,LPARAM l_داده,WPARAM w_داده,صحيح x,صحيح y,صحيح cx,صحيح cy,UINT uFlags);
  WINUSERAPI LONG WINAPI Tabbed_متن_بیرون_A(HDC hdc,صحيح x,صحيح y,LPCSTR lpString,صحيح ch_شمار,صحيح nTabPositions,CONST INT *lpnTabStopPositions,صحيح nTabOrigin);
  WINUSERAPI LONG WINAPI Tabbed_متن_بیرون_W(HDC hdc,صحيح x,صحيح y,LPCWSTR lpString,صحيح ch_شمار,صحيح nTabPositions,CONST INT *lpnTabStopPositions,صحيح nTabOrigin);
  WINUSERAPI DWORD WINAPI Get_Tabbed_متن_Extent_A(HDC hdc,LPCSTR lpString,صحيح ch_شمار,صحيح nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI DWORD WINAPI Get_Tabbed_متن_Extent_W(HDC hdc,LPCWSTR lpString,صحيح ch_شمار,صحيح nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI WINBOOL WINAPI Update_پنجره(HWND hWnd);
  WINUSERAPI HWND WINAPI مجموعه_فعال_پنجره(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_Foreground_پنجره(VOID);
  WINUSERAPI WINBOOL WINAPI PaintDesktop(HDC hdc);
  WINUSERAPI VOID WINAPI Switch_مقصد_This_پنجره(HWND hwnd,WINBOOL fUnknown);
  WINUSERAPI WINBOOL WINAPI مجموعه_Foreground_پنجره(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Allow_مجموعه_Foreground_پنجره(DWORD dwProcessId);

#تعریف_کن ASFW_ANY ((DWORD)-1)

  WINUSERAPI WINBOOL WINAPI قفل_مجموعه_Foreground_پنجره(UINT u_قفل_کد);

#تعریف_کن LSFW_قفل 1
#تعریف_کن LSFW_UNLOCK 2

  WINUSERAPI HWND WINAPI پنجره_From_DC(HDC hDC);
  WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
  WINUSERAPI HDC WINAPI GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags);

#تعریف_کن DCX_پنجره 0x00000001L
#تعریف_کن DCX_CACHE 0x00000002L
#تعریف_کن DCX_NORESETATTRS 0x00000004L
#تعریف_کن DCX_CLIPCHILDREN 0x00000008L
#تعریف_کن DCX_CLIPSIBLINGS 0x00000010L
#تعریف_کن DCX_PARENTCLIP 0x00000020L
#تعریف_کن DCX_EXCLUDERGN 0x00000040L
#تعریف_کن DCX_INTERSECTRGN 0x00000080L
#تعریف_کن DCX_EXCLUDEUPDATE 0x00000100L
#تعریف_کن DCX_INTERSECTUPDATE 0x00000200L
#تعریف_کن DCX_LOCKWINDOWUPDATE 0x00000400L

#تعریف_کن DCX_VALIDATE 0x00200000L

  WINUSERAPI HDC WINAPI Get_پنجره_DC(HWND hWnd);
  WINUSERAPI صحيح WINAPI ReleaseDC(HWND hWnd,HDC hDC);
  WINUSERAPI HDC WINAPI BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
  WINUSERAPI WINBOOL WINAPI انتها_Paint(HWND hWnd,CONST PAINTSTRUCT *lpPaint);
  WINUSERAPI WINBOOL WINAPI GetUpdateRect(HWND hWnd,LPRECT lpRect,WINBOOL bErase);
  WINUSERAPI صحيح WINAPI GetUpdateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI صحيح WINAPI مجموعه_پنجره_Rgn(HWND hWnd,HRGN hRgn,WINBOOL bRedraw);
  WINUSERAPI صحيح WINAPI Get_پنجره_Rgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI صحيح WINAPI Get_پنجره_Rgn_Box(HWND hWnd,LPRECT lprc);
  WINUSERAPI صحيح WINAPI ExcludeUpdateRgn(HDC hDC,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI InvalidateRect(HWND hWnd,CONST RECT *lpRect,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRect(HWND hWnd,CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI InvalidateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI WINBOOL WINAPI Redraw_پنجره(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#تعریف_کن RDW_INVALIDATE 0x0001
#تعریف_کن RDW_INTERNALPAINT 0x0002
#تعریف_کن RDW_ERASE 0x0004

#تعریف_کن RDW_VALIDATE 0x0008
#تعریف_کن RDW_NOINTERNALPAINT 0x0010
#تعریف_کن RDW_NOERASE 0x0020

#تعریف_کن RDW_NOCHILDREN 0x0040
#تعریف_کن RDW_ALLCHILDREN 0x0080

#تعریف_کن RDW_UPDATENOW 0x0100
#تعریف_کن RDW_ERASENOW 0x0200

#تعریف_کن RDW_قاب 0x0400
#تعریف_کن RDW_NOFRAME 0x0800

  WINUSERAPI WINBOOL WINAPI قفل_پنجره_Update(HWND h_Wnd_قفل);
  WINUSERAPI WINBOOL WINAPI Scroll_پنجره(HWND hWnd,صحيح XAmount,صحيح YAmount,CONST RECT *lpRect,CONST RECT *lpClipRect);
  WINUSERAPI WINBOOL WINAPI ScrollDC(HDC hDC,صحيح dx,صحيح dy,CONST RECT *lprcScroll,CONST RECT *lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
  WINUSERAPI صحيح WINAPI Scroll_پنجره_Ex(HWND hWnd,صحيح dx,صحيح dy,CONST RECT *prcScroll,CONST RECT *prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);

#تعریف_کن SW_SCROLLCHILDREN 0x0001
#تعریف_کن SW_INVALIDATE 0x0002
#تعریف_کن SW_ERASE 0x0004
#تعریف_کن SW_SMOOTHSCROLL 0x0010

#اگر_تعریف_نشده NOSCROLL
  WINUSERAPI صحيح WINAPI مجموعه_Scroll_Pos(HWND hWnd,صحيح nBar,صحيح nPos,WINBOOL bRedraw);
  WINUSERAPI صحيح WINAPI GetScrollPos(HWND hWnd,صحيح nBar);
  WINUSERAPI WINBOOL WINAPI مجموعه_Scroll_Range(HWND hWnd,صحيح nBar,صحيح nMinPos,صحيح nMaxPos,WINBOOL bRedraw);
  WINUSERAPI WINBOOL WINAPI GetScrollRange(HWND hWnd,صحيح nBar,LPINT lpMinPos,LPINT lpMaxPos);
  WINUSERAPI WINBOOL WINAPI ShowScrollBar(HWND hWnd,صحيح wBar,WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows);

#تعریف_کن ESB_ENABLE_BOTH 0x0000
#تعریف_کن ESB_DISABLE_BOTH 0x0003

#تعریف_کن ESB_DISABLE_چپ 0x0001
#تعریف_کن ESB_DISABLE_راست 0x0002

#تعریف_کن ESB_DISABLE_به_بالا 0x0001
#تعریف_کن ESB_DISABLE_پایین 0x0002

#تعریف_کن ESB_DISABLE_LTUP ESB_DISABLE_چپ
#تعریف_کن ESB_DISABLE_RTDN ESB_DISABLE_راست
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن مجموعه_Prop مجموعه_Prop_W
#تعریف_کن GetProp GetPropW
#تعریف_کن RemoveProp RemovePropW
#تعریف_کن EnumPropsEx EnumPropsExW
#تعریف_کن EnumProps EnumPropsW
#تعریف_کن مجموعه_پنجره_متن مجموعه_پنجره_متن_W
#تعریف_کن Get_پنجره_متن Get_پنجره_متن_W
#تعریف_کن Get_پنجره_متن_درازی Get_پنجره_متن_درازی_W
#وإلا
#تعریف_کن مجموعه_Prop مجموعه_Prop_A
#تعریف_کن GetProp GetPropA
#تعریف_کن RemoveProp RemovePropA
#تعریف_کن EnumPropsEx EnumPropsExA
#تعریف_کن EnumProps EnumPropsA
#تعریف_کن مجموعه_پنجره_متن مجموعه_پنجره_متن_A
#تعریف_کن Get_پنجره_متن Get_پنجره_متن_A
#تعریف_کن Get_پنجره_متن_درازی Get_پنجره_متن_درازی_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI مجموعه_Prop_A(HWND hWnd,LPCSTR lpString,HANDLE h_داده);
  WINUSERAPI WINBOOL WINAPI مجموعه_Prop_W(HWND hWnd,LPCWSTR lpString,HANDLE h_داده);
  WINUSERAPI HANDLE WINAPI GetPropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI GetPropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI صحيح WINAPI EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
  WINUSERAPI صحيح WINAPI EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
  WINUSERAPI صحيح WINAPI EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc);
  WINUSERAPI صحيح WINAPI EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc);
  WINUSERAPI WINBOOL WINAPI مجموعه_پنجره_متن_A(HWND hWnd,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI مجموعه_پنجره_متن_W(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI صحيح WINAPI Get_پنجره_متن_A(HWND hWnd,LPSTR lpString,صحيح n_Max_شمار);
  WINUSERAPI صحيح WINAPI Get_پنجره_متن_W(HWND hWnd,LPWSTR lpString,صحيح n_Max_شمار);
  WINUSERAPI صحيح WINAPI Get_پنجره_متن_درازی_A(HWND hWnd);
  WINUSERAPI صحيح WINAPI Get_پنجره_متن_درازی_W(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI GetClientRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Get_پنجره_Rect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Adjust_پنجره_Rect(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu);
  WINUSERAPI WINBOOL WINAPI Adjust_پنجره_Rect_Ex(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu,DWORD dwExStyle);

#تعریف_کن HELPINFO_پنجره 0x0001
#تعریف_کن HELPINFO_MENUITEM 0x0002

  تعريفنوع بنية برچسب_HELPINFO {
    UINT cb_اندازه;
    صحيح iContextType;
    صحيح iCtrlId;
    HANDLE h_قلم_Handle;
    DWORD_PTR dwContextId;
    نقطه_3 MousePos;
  } HELPINFO,*LPHELPINFO;

  WINUSERAPI WINBOOL WINAPI مجموعه_پنجره_Context_Help_Id(HWND,DWORD);
  WINUSERAPI DWORD WINAPI Get_پنجره_Context_Help_Id(HWND);
  WINUSERAPI WINBOOL WINAPI مجموعه_Menu_Context_Help_Id(HMENU,DWORD);
  WINUSERAPI DWORD WINAPI GetMenuContextHelpId(HMENU);

#اگر_تعریف_نشده NOMB

#تعریف_کن MB_OK 0x00000000L
#تعریف_کن MB_OKCANCEL 0x00000001L
#تعریف_کن MB_ABORTRETRYIGNORE 0x00000002L
#تعریف_کن MB_YESNOCANCEL 0x00000003L
#تعریف_کن MB_YESNO 0x00000004L
#تعریف_کن MB_RETRYCANCEL 0x00000005L
#تعریف_کن MB_CANCELTRYCONTINUE 0x00000006L
#تعریف_کن MB_ICONHAND 0x00000010L
#تعریف_کن MB_ICONQUESTION 0x00000020L
#تعریف_کن MB_ICONEXCLAMATION 0x00000030L
#تعریف_کن MB_ICONASTERISK 0x00000040L
#تعریف_کن MB_USERICON 0x00000080L
#تعریف_کن MB_ICONWARNING MB_ICONEXCLAMATION
#تعریف_کن MB_ICONERROR MB_ICONHAND
#تعریف_کن MB_ICONINFORMATION MB_ICONASTERISK
#تعریف_کن MB_ICONSTOP MB_ICONHAND
#تعریف_کن MB_DEFBUTTON1 0x00000000L
#تعریف_کن MB_DEFBUTTON2 0x00000100L
#تعریف_کن MB_DEFBUTTON3 0x00000200L
#تعریف_کن MB_DEFBUTTON4 0x00000300L
#تعریف_کن MB_APPLMODAL 0x00000000L
#تعریف_کن MB_SYSTEMMODAL 0x00001000L
#تعریف_کن MB_TASKMODAL 0x00002000L
#تعریف_کن MB_HELP 0x00004000L
#تعریف_کن MB_NOFOCUS 0x00008000L
#تعریف_کن MB_SETFOREGROUND 0x00010000L
#تعریف_کن MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#تعریف_کن MB_TOPMOST 0x00040000L
#تعریف_کن MB_راست 0x00080000L
#تعریف_کن MB_RTLREADING 0x00100000L
#تعریف_کن MB_SERVICE_NOTIFICATION 0x00200000L
#تعریف_کن MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#تعریف_کن MB_TYPEMASK 0x0000000FL
#تعریف_کن MB_ICONMASK 0x000000F0L
#تعریف_کن MB_DEFMASK 0x00000F00L
#تعریف_کن MB_MODEMASK 0x00003000L
#تعریف_کن MB_MISCMASK 0x0000C000L

#اگر_تعریف_شده UNICODE
#تعریف_کن پیام_Box پیام_Box_W
#تعریف_کن پیام_Box_Ex پیام_Box_Ex_W
#وإلا
#تعریف_کن پیام_Box پیام_Box_A
#تعریف_کن پیام_Box_Ex پیام_Box_Ex_A
#پایان_اگر

  WINUSERAPI صحيح WINAPI پیام_Box_A(HWND hWnd,LPCSTR lp_متن,LPCSTR lpCaption,UINT uType);
  WINUSERAPI صحيح WINAPI پیام_Box_W(HWND hWnd,LPCWSTR lp_متن,LPCWSTR lpCaption,UINT uType);
  WINUSERAPI صحيح WINAPI پیام_Box_Ex_A(HWND hWnd,LPCSTR lp_متن,LPCSTR lpCaption,UINT uType,کلمه_3 wLanguageId);
  WINUSERAPI صحيح WINAPI پیام_Box_Ex_W(HWND hWnd,LPCWSTR lp_متن,LPCWSTR lpCaption,UINT uType,کلمه_3 wLanguageId);

  تعريفنوع VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

  تعريفنوع بنية برچسب_MSGBOXPARAMSA {
    UINT cb_اندازه;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpsz_متن;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_پیام_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSA,*PMSGBOXPARAMSA,*LPMSGBOXPARAMSA;

  تعريفنوع بنية برچسب_MSGBOXPARAMSW {
    UINT cb_اندازه;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpsz_متن;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_پیام_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSW,*PMSGBOXPARAMSW,*LPMSGBOXPARAMSW;

#اگر_تعریف_شده UNICODE
  تعريفنوع MSGBOXPARAMSW MSGBOXPARAMS;
  تعريفنوع PMSGBOXPARAMSW PMSGBOXPARAMS;
  تعريفنوع LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#وإلا
  تعريفنوع MSGBOXPARAMSA MSGBOXPARAMS;
  تعريفنوع PMSGBOXPARAMSA PMSGBOXPARAMS;
  تعريفنوع LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن پیام_Box_غیرمستقیم پیام_Box_غیرمستقیم_W
#وإلا
#تعریف_کن پیام_Box_غیرمستقیم پیام_Box_غیرمستقیم_A
#پایان_اگر

  WINUSERAPI صحيح WINAPI پیام_Box_غیرمستقیم_A(CONST MSGBOXPARAMSA *lpmbp);
  WINUSERAPI صحيح WINAPI پیام_Box_غیرمستقیم_W(CONST MSGBOXPARAMSW *lpmbp);
  WINUSERAPI WINBOOL WINAPI پیام_Beep(UINT uType);
#پایان_اگر

  WINUSERAPI صحيح WINAPI ShowCursor(WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI مجموعه_Cursor_Pos(صحيح X,صحيح Y);
  WINUSERAPI HCURSOR WINAPI مجموعه_Cursor(HCURSOR hCursor);
  WINUSERAPI WINBOOL WINAPI GetCursorPos(LPPOINT lp_نقطه);
  WINUSERAPI WINBOOL WINAPI ClipCursor(CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI GetClipCursor(LPRECT lpRect);
  WINUSERAPI HCURSOR WINAPI GetCursor(VOID);
  WINUSERAPI WINBOOL WINAPI CreateCaret(HWND hWnd,HBITMAP hBitmap,صحيح n_عرض,صحيح n_ارتفاع);
  WINUSERAPI UINT WINAPI Get_Caret_Blink_زمان(VOID);
  WINUSERAPI WINBOOL WINAPI مجموعه_Caret_Blink_زمان(UINT uMSeconds);
  WINUSERAPI WINBOOL WINAPI DestroyCaret(VOID);
  WINUSERAPI WINBOOL WINAPI HideCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI مجموعه_Caret_Pos(صحيح X,صحيح Y);
  WINUSERAPI WINBOOL WINAPI GetCaretPos(LPPOINT lp_نقطه);
  WINUSERAPI WINBOOL WINAPI Client_مقصد_Screen(HWND hWnd,LPPOINT lp_نقطه);
  WINUSERAPI WINBOOL WINAPI Screen_مقصد_Client(HWND hWnd,LPPOINT lp_نقطه);
  WINUSERAPI صحيح WINAPI Map_پنجره_Points(HWND hWndFrom,HWND h_Wnd_مقصد,LPPOINT lpPoints,UINT cPoints);
  WINUSERAPI HWND WINAPI پنجره_From_نقطه(نقطه_3 نقطه_2);
  WINUSERAPI HWND WINAPI فرزند_پنجره_From_نقطه(HWND h_Wnd_والد,نقطه_3 نقطه_2);

#تعریف_کن CWP_ALL 0x0000
#تعریف_کن CWP_SKIPINVISIBLE 0x0001
#تعریف_کن CWP_SKIPDISABLED 0x0002
#تعریف_کن CWP_SKIPTRANSPARENT 0x0004

  WINUSERAPI HWND WINAPI فرزند_پنجره_From_نقطه_Ex(HWND hwnd,نقطه_3 pt,UINT flags);

#اگر_تعریف_نشده NOCOLOR

#تعریف_کن CTLCOLOR_MSGBOX 0
#تعریف_کن CTLCOLOR_EDIT 1
#تعریف_کن CTLCOLOR_LISTBOX 2
#تعریف_کن CTLCOLOR_BTN 3
#تعریف_کن CTLCOLOR_DLG 4
#تعریف_کن CTLCOLOR_SCROLLBAR 5
#تعریف_کن CTLCOLOR_STATIC 6
#تعریف_کن CTLCOLOR_MAX 7

#تعریف_کن COLOR_SCROLLBAR 0
#تعریف_کن COLOR_BACKGROUND 1
#تعریف_کن COLOR_ACTIVECAPTION 2
#تعریف_کن COLOR_INACTIVECAPTION 3
#تعریف_کن COLOR_MENU 4
#تعریف_کن COLOR_پنجره 5
#تعریف_کن COLOR_WINDOWFRAME 6
#تعریف_کن COLOR_MENUTEXT 7
#تعریف_کن COLOR_WINDOWTEXT 8
#تعریف_کن COLOR_CAPTIONTEXT 9
#تعریف_کن COLOR_ACTIVEBORDER 10
#تعریف_کن COLOR_INACTIVEBORDER 11
#تعریف_کن COLOR_APPWORKSPACE 12
#تعریف_کن COLOR_HIGHLIGHT 13
#تعریف_کن COLOR_HIGHLIGHTTEXT 14
#تعریف_کن COLOR_BTNFACE 15
#تعریف_کن COLOR_BTNSHADOW 16
#تعریف_کن COLOR_GRAYTEXT 17
#تعریف_کن COLOR_BTNTEXT 18
#تعریف_کن COLOR_INACTIVECAPTIONTEXT 19
#تعریف_کن COLOR_BTNHIGHLIGHT 20

#تعریف_کن COLOR_3DDKSHADOW 21
#تعریف_کن COLOR_3DLIGHT 22
#تعریف_کن COLOR_INFOTEXT 23
#تعریف_کن COLOR_INFOBK 24

#تعریف_کن COLOR_HOTLIGHT 26
#تعریف_کن COLOR_GRADIENTACTIVECAPTION 27
#تعریف_کن COLOR_GRADIENTINACTIVECAPTION 28
#تعریف_کن COLOR_MENUHILIGHT 29
#تعریف_کن COLOR_MENUBAR 30

#تعریف_کن COLOR_DESKTOP COLOR_BACKGROUND
#تعریف_کن COLOR_3DFACE COLOR_BTNFACE
#تعریف_کن COLOR_3DSHADOW COLOR_BTNSHADOW
#تعریف_کن COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#تعریف_کن COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#تعریف_کن COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

  WINUSERAPI DWORD WINAPI GetSysColor(صحيح n_شاخص);
  WINUSERAPI HBRUSH WINAPI GetSysColorBrush(صحيح n_شاخص);
  WINUSERAPI WINBOOL WINAPI مجموعه_Sys_Colors(صحيح cElements,CONST INT *lpaElements,CONST COLORREF *lpa_Rgb_مقادیر);
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI DrawFocusRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI صحيح WINAPI FillRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI صحيح WINAPI قاب_Rect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI WINBOOL WINAPI InvertRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI مجموعه_Rect(LPRECT lprc,صحيح x_چپ,صحيح y_بالاترین,صحيح x_راست,صحيح yBottom);
  WINUSERAPI WINBOOL WINAPI مجموعه_Rect_خالی(LPRECT lprc);
  WINUSERAPI WINBOOL WINAPI CopyRect(LPRECT lprcDst,CONST RECT *lprcSrc);
  WINUSERAPI WINBOOL WINAPI InflateRect(LPRECT lprc,صحيح dx,صحيح dy);
  WINUSERAPI WINBOOL WINAPI IntersectRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI UnionRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI تفریق_Rect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI جابه_جایی_Rect(LPRECT lprc,صحيح dx,صحيح dy);
  WINUSERAPI WINBOOL WINAPI Is_Rect_خالی(CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI EqualRect(CONST RECT *lprc1,CONST RECT *lprc2);
  WINUSERAPI WINBOOL WINAPI Pt_درون_Rect(CONST RECT *lprc,نقطه_3 pt);

#اگر_تعریف_نشده NOWINOFFSETS

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_پنجره_Long Get_پنجره_Long_W
#تعریف_کن مجموعه_پنجره_Long مجموعه_پنجره_Long_W
#وإلا
#تعریف_کن Get_پنجره_Long Get_پنجره_Long_A
#تعریف_کن مجموعه_پنجره_Long مجموعه_پنجره_Long_A
#پایان_اگر

  WINUSERAPI کلمه_3 WINAPI Get_پنجره_کلمه(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI کلمه_3 WINAPI مجموعه_پنجره_کلمه(HWND hWnd,صحيح n_شاخص,کلمه_3 w_New_کلمه);
  WINUSERAPI LONG WINAPI Get_پنجره_Long_A(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI LONG WINAPI Get_پنجره_Long_W(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI LONG WINAPI مجموعه_پنجره_Long_A(HWND hWnd,صحيح n_شاخص,LONG dwNewLong);
  WINUSERAPI LONG WINAPI مجموعه_پنجره_Long_W(HWND hWnd,صحيح n_شاخص,LONG dwNewLong);

#اگر_تعریف_شده _WIN64

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_پنجره_Long_Ptr Get_پنجره_Long_Ptr_W
#تعریف_کن مجموعه_پنجره_Long_Ptr مجموعه_پنجره_Long_Ptr_W
#وإلا
#تعریف_کن Get_پنجره_Long_Ptr Get_پنجره_Long_Ptr_A
#تعریف_کن مجموعه_پنجره_Long_Ptr مجموعه_پنجره_Long_Ptr_A
#پایان_اگر

  WINUSERAPI LONG_PTR WINAPI Get_پنجره_Long_Ptr_A(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI LONG_PTR WINAPI Get_پنجره_Long_Ptr_W(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI LONG_PTR WINAPI مجموعه_پنجره_Long_Ptr_A(HWND hWnd,صحيح n_شاخص,LONG_PTR dwNewLong);
  WINUSERAPI LONG_PTR WINAPI مجموعه_پنجره_Long_Ptr_W(HWND hWnd,صحيح n_شاخص,LONG_PTR dwNewLong);
#وإلا

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_پنجره_Long_Ptr Get_پنجره_Long_Ptr_W
#تعریف_کن مجموعه_پنجره_Long_Ptr مجموعه_پنجره_Long_Ptr_W
#وإلا
#تعریف_کن Get_پنجره_Long_Ptr Get_پنجره_Long_Ptr_A
#تعریف_کن مجموعه_پنجره_Long_Ptr مجموعه_پنجره_Long_Ptr_A
#پایان_اگر

#تعریف_کن Get_پنجره_Long_Ptr_A Get_پنجره_Long_A
#تعریف_کن Get_پنجره_Long_Ptr_W Get_پنجره_Long_W
#تعریف_کن مجموعه_پنجره_Long_Ptr_A مجموعه_پنجره_Long_A
#تعریف_کن مجموعه_پنجره_Long_Ptr_W مجموعه_پنجره_Long_W
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن GetClassLong GetClassLongW
#تعریف_کن مجموعه_Class_Long مجموعه_Class_Long_W
#وإلا
#تعریف_کن GetClassLong GetClassLongA
#تعریف_کن مجموعه_Class_Long مجموعه_Class_Long_A
#پایان_اگر

  WINUSERAPI کلمه_3 WINAPI Get_Class_کلمه(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI کلمه_3 WINAPI مجموعه_Class_کلمه(HWND hWnd,صحيح n_شاخص,کلمه_3 w_New_کلمه);
  WINUSERAPI DWORD WINAPI GetClassLongA(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI DWORD WINAPI GetClassLongW(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI DWORD WINAPI مجموعه_Class_Long_A(HWND hWnd,صحيح n_شاخص,LONG dwNewLong);
  WINUSERAPI DWORD WINAPI مجموعه_Class_Long_W(HWND hWnd,صحيح n_شاخص,LONG dwNewLong);

#اگر_تعریف_شده _WIN64

#اگر_تعریف_شده UNICODE
#تعریف_کن GetClassLongPtr GetClassLongPtrW
#تعریف_کن مجموعه_Class_Long_Ptr مجموعه_Class_Long_Ptr_W
#وإلا
#تعریف_کن GetClassLongPtr GetClassLongPtrA
#تعریف_کن مجموعه_Class_Long_Ptr مجموعه_Class_Long_Ptr_A
#پایان_اگر

  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd,صحيح n_شاخص);
  WINUSERAPI ULONG_PTR WINAPI مجموعه_Class_Long_Ptr_A(HWND hWnd,صحيح n_شاخص,LONG_PTR dwNewLong);
  WINUSERAPI ULONG_PTR WINAPI مجموعه_Class_Long_Ptr_W(HWND hWnd,صحيح n_شاخص,LONG_PTR dwNewLong);
#وإلا
#اگر_تعریف_شده UNICODE
#تعریف_کن GetClassLongPtr GetClassLongPtrW
#تعریف_کن مجموعه_Class_Long_Ptr مجموعه_Class_Long_Ptr_W
#وإلا
#تعریف_کن GetClassLongPtr GetClassLongPtrA
#تعریف_کن مجموعه_Class_Long_Ptr مجموعه_Class_Long_Ptr_A
#پایان_اگر

#تعریف_کن GetClassLongPtrA GetClassLongA
#تعریف_کن GetClassLongPtrW GetClassLongW
#تعریف_کن مجموعه_Class_Long_Ptr_A مجموعه_Class_Long_A
#تعریف_کن مجموعه_Class_Long_Ptr_W مجموعه_Class_Long_W
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن پیدا_کن_پنجره پیدا_کن_پنجره_W
#تعریف_کن پیدا_کن_پنجره_Ex پیدا_کن_پنجره_Ex_W
#تعریف_کن GetClassName GetClassNameW
#وإلا
#تعریف_کن پیدا_کن_پنجره پیدا_کن_پنجره_A
#تعریف_کن پیدا_کن_پنجره_Ex پیدا_کن_پنجره_Ex_A
#تعریف_کن GetClassName GetClassNameA
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI GetProcessDefaultLayout(DWORD *pdwDefaultLayout);
  WINUSERAPI WINBOOL WINAPI مجموعه_Process_Default_Layout(DWORD dwDefaultLayout);
  WINUSERAPI HWND WINAPI Get_Desktop_پنجره(VOID);
  WINUSERAPI HWND WINAPI Get_والد(HWND hWnd);
  WINUSERAPI HWND WINAPI مجموعه_والد(HWND h_Wnd_فرزند,HWND h_Wnd_New_والد);
  WINUSERAPI WINBOOL WINAPI Enum_فرزند_Windows(HWND h_Wnd_والد,WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI HWND WINAPI پیدا_کن_پنجره_A(LPCSTR lpClassName,LPCSTR lp_پنجره_Name);
  WINUSERAPI HWND WINAPI پیدا_کن_پنجره_W(LPCWSTR lpClassName,LPCWSTR lp_پنجره_Name);
  WINUSERAPI HWND WINAPI پیدا_کن_پنجره_Ex_A(HWND h_Wnd_والد,HWND h_Wnd_فرزند_After,LPCSTR lpszClass,LPCSTR lpsz_پنجره);
  WINUSERAPI HWND WINAPI پیدا_کن_پنجره_Ex_W(HWND h_Wnd_والد,HWND h_Wnd_فرزند_After,LPCWSTR lpszClass,LPCWSTR lpsz_پنجره);
  WINUSERAPI HWND WINAPI Get_Shell_پنجره(VOID);
  WINUSERAPI WINBOOL WINAPI ثبات_Shell_Hook_پنجره(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI Deregister_Shell_Hook_پنجره(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);

#تعریف_کن EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(Handle_مقصد_Ulong(hTask),lpfn,lParam)

  WINUSERAPI صحيح WINAPI GetClassNameA(HWND hWnd,LPSTR lpClassName,صحيح n_Max_شمار);
  WINUSERAPI صحيح WINAPI GetClassNameW(HWND hWnd,LPWSTR lpClassName,صحيح n_Max_شمار);
  WINUSERAPI HWND WINAPI Get_بالاترین_پنجره(HWND hWnd);

#تعریف_کن Get_بعدی_پنجره(hWnd,wCmd) Get_پنجره(hWnd,wCmd)
#تعریف_کن Get_Sys_Modal_پنجره() (عدم)
#تعریف_کن مجموعه_Sys_Modal_پنجره(hWnd) (عدم)

  WINUSERAPI DWORD WINAPI Get_پنجره_Thread_Process_Id(HWND hWnd,LPDWORD lpdwProcessId);
  WINUSERAPI WINBOOL WINAPI IsGUIThread(WINBOOL bConvert);

#تعریف_کن Get_پنجره_Task(hWnd) ((HANDLE)(DWORD_PTR)Get_پنجره_Thread_Process_Id(hWnd,عدم))

  WINUSERAPI HWND WINAPI Get_آخرین_فعال_Popup(HWND hWnd);

#تعریف_کن GW_HWNDFIRST 0
#تعریف_کن GW_HWNDLAST 1
#تعریف_کن GW_HWNDNEXT 2
#تعریف_کن GW_HWNDPREV 3
#تعریف_کن GW_OWNER 4
#تعریف_کن GW_فرزند 5
#تعریف_کن GW_ENABLEDPOPUP 6
#تعریف_کن GW_MAX 6

  WINUSERAPI HWND WINAPI Get_پنجره(HWND hWnd,UINT uCmd);

#اگر_تعریف_نشده NOWH

#اگر_تعریف_شده UNICODE
#تعریف_کن مجموعه_Windows_Hook مجموعه_Windows_Hook_W
#تعریف_کن مجموعه_Windows_Hook_Ex مجموعه_Windows_Hook_Ex_W
#وإلا
#تعریف_کن مجموعه_Windows_Hook مجموعه_Windows_Hook_A
#تعریف_کن مجموعه_Windows_Hook_Ex مجموعه_Windows_Hook_Ex_A
#پایان_اگر

  WINUSERAPI HHOOK WINAPI مجموعه_Windows_Hook_A(صحيح nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI مجموعه_Windows_Hook_W(صحيح nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHook(صحيح n_کد,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI مجموعه_Windows_Hook_Ex_A(صحيح idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI HHOOK WINAPI مجموعه_Windows_Hook_Ex_W(صحيح idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);
  WINUSERAPI LRESULT WINAPI Call_بعدی_Hook_Ex(HHOOK hhk,صحيح n_کد,WPARAM wParam,LPARAM lParam);
#تعریف_کن DefHookProc(n_کد,wParam,lParam,phhk) Call_بعدی_Hook_Ex(*phhk,n_کد,wParam,lParam)
#پایان_اگر

#اگر_تعریف_نشده NOMENUS

#تعریف_کن MF_درج 0x00000000L
#تعریف_کن MF_CHANGE 0x00000080L
#تعریف_کن MF_APPEND 0x00000100L
#تعریف_کن MF_DELETE 0x00000200L
#تعریف_کن MF_REMOVE 0x00001000L
#تعریف_کن MF_BYCOMMAND 0x00000000L
#تعریف_کن MF_BYPOSITION 0x00000400L
#تعریف_کن MF_SEPARATOR 0x00000800L
#تعریف_کن MF_ENABLED 0x00000000L
#تعریف_کن MF_GRAYED 0x00000001L
#تعریف_کن MF_DISABLED 0x00000002L
#تعریف_کن MF_UNCHECKED 0x00000000L
#تعریف_کن MF_CHECKED 0x00000008L
#تعریف_کن MF_USECHECKBITMAPS 0x00000200L
#تعریف_کن MF_STRING 0x00000000L
#تعریف_کن MF_BITMAP 0x00000004L
#تعریف_کن MF_OWNERDRAW 0x00000100L
#تعریف_کن MF_POPUP 0x00000010L
#تعریف_کن MF_MENUBARBREAK 0x00000020L
#تعریف_کن MF_MENUBREAK 0x00000040L
#تعریف_کن MF_UNHILITE 0x00000000L
#تعریف_کن MF_HILITE 0x00000080L
#تعریف_کن MF_DEFAULT 0x00001000L
#تعریف_کن MF_SYSMENU 0x00002000L
#تعریف_کن MF_HELP 0x00004000L
#تعریف_کن MF_RIGHTJUSTIFY 0x00004000L
#تعریف_کن MF_MOUSESELECT 0x00008000L
#تعریف_کن MF_انتها 0x00000080L

#تعریف_کن MFT_STRING MF_STRING
#تعریف_کن MFT_BITMAP MF_BITMAP
#تعریف_کن MFT_MENUBARBREAK MF_MENUBARBREAK
#تعریف_کن MFT_MENUBREAK MF_MENUBREAK
#تعریف_کن MFT_OWNERDRAW MF_OWNERDRAW
#تعریف_کن MFT_RADIOCHECK 0x00000200L
#تعریف_کن MFT_SEPARATOR MF_SEPARATOR
#تعریف_کن MFT_RIGHTORDER 0x00002000L
#تعریف_کن MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#تعریف_کن MFS_GRAYED 0x00000003L
#تعریف_کن MFS_DISABLED MFS_GRAYED
#تعریف_کن MFS_CHECKED MF_CHECKED
#تعریف_کن MFS_HILITE MF_HILITE
#تعریف_کن MFS_ENABLED MF_ENABLED
#تعریف_کن MFS_UNCHECKED MF_UNCHECKED
#تعریف_کن MFS_UNHILITE MF_UNHILITE
#تعریف_کن MFS_DEFAULT MF_DEFAULT

  WINUSERAPI WINBOOL WINAPI Check_Menu_Radio_قلم(HMENU hmenu,UINT اولی,UINT آخرین,UINT check,UINT flags);

  تعريفنوع بنية {
    کلمه_3 نسخه_عدد;
    کلمه_3 جابه_جایی;
  } MENUITEMTEMPLATEHEADER,*PMENUITEMTEMPLATEHEADER;

  تعريفنوع بنية {
    کلمه_3 mtOption;
    کلمه_3 mtID;
    WCHAR mtString[1];
  } MENUITEMTEMPLATE,*PMENUITEMTEMPLATE;
#تعریف_کن MF_انتها 0x00000080L
#پایان_اگر

#اگر_تعریف_نشده NOSYSCOMMANDS

#تعریف_کن SC_اندازه 0xF000
#تعریف_کن SC_MOVE 0xF010
#تعریف_کن SC_MINIMIZE 0xF020
#تعریف_کن SC_MAXIMIZE 0xF030
#تعریف_کن SC_NEXTWINDOW 0xF040
#تعریف_کن SC_PREVWINDOW 0xF050
#تعریف_کن SC_CLOSE 0xF060
#تعریف_کن SC_VSCROLL 0xF070
#تعریف_کن SC_HSCROLL 0xF080
#تعریف_کن SC_MOUSEMENU 0xF090
#تعریف_کن SC_KEYMENU 0xF100
#تعریف_کن SC_ARRANGE 0xF110
#تعریف_کن SC_RESTORE 0xF120
#تعریف_کن SC_TASKLIST 0xF130
#تعریف_کن SC_SCREENSAVE 0xF140
#تعریف_کن SC_HOTKEY 0xF150
#تعریف_کن SC_DEFAULT 0xF160
#تعریف_کن SC_MONITORPOWER 0xF170
#تعریف_کن SC_CONTEXTHELP 0xF180
#تعریف_کن SC_SEPARATOR 0xF00F
#تعریف_کن SC_ICON SC_MINIMIZE
#تعریف_کن SC_ZOOM SC_MAXIMIZE
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن بارگیری_Bitmap بارگیری_Bitmap_W
#تعریف_کن بارگیری_Cursor بارگیری_Cursor_W
#تعریف_کن بارگیری_Cursor_From_File بارگیری_Cursor_From_File_W
#وإلا
#تعریف_کن بارگیری_Bitmap بارگیری_Bitmap_A
#تعریف_کن بارگیری_Cursor بارگیری_Cursor_A
#تعریف_کن بارگیری_Cursor_From_File بارگیری_Cursor_From_File_A
#پایان_اگر

  WINUSERAPI HBITMAP WINAPI بارگیری_Bitmap_A(HINSTANCE hInstance,LPCSTR lpBitmapName);
  WINUSERAPI HBITMAP WINAPI بارگیری_Bitmap_W(HINSTANCE hInstance,LPCWSTR lpBitmapName);
  WINUSERAPI HCURSOR WINAPI بارگیری_Cursor_A(HINSTANCE hInstance,LPCSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI بارگیری_Cursor_W(HINSTANCE hInstance,LPCWSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI بارگیری_Cursor_From_File_A(LPCSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI بارگیری_Cursor_From_File_W(LPCWSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI CreateCursor(HINSTANCE hInst,صحيح xHotSpot,صحيح yHotSpot,صحيح n_عرض,صحيح n_ارتفاع,CONST VOID *pvANDPlane,CONST VOID *pvXORPlane);
  WINUSERAPI WINBOOL WINAPI DestroyCursor(HCURSOR hCursor);

#تعریف_کن CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

#تعریف_کن IDC_ARROW MAKEINTRESOURCE(32512)
#تعریف_کن IDC_IBEAM MAKEINTRESOURCE(32513)
#تعریف_کن IDC_WAIT MAKEINTRESOURCE(32514)
#تعریف_کن IDC_CROSS MAKEINTRESOURCE(32515)
#تعریف_کن IDC_UPARROW MAKEINTRESOURCE(32516)
#تعریف_کن IDC_اندازه MAKEINTRESOURCE(32640)
#تعریف_کن IDC_ICON MAKEINTRESOURCE(32641)
#تعریف_کن IDC_SIZENWSE MAKEINTRESOURCE(32642)
#تعریف_کن IDC_SIZENESW MAKEINTRESOURCE(32643)
#تعریف_کن IDC_SIZEWE MAKEINTRESOURCE(32644)
#تعریف_کن IDC_SIZENS MAKEINTRESOURCE(32645)
#تعریف_کن IDC_SIZEALL MAKEINTRESOURCE(32646)
#تعریف_کن IDC_NO MAKEINTRESOURCE(32648)
#تعریف_کن IDC_HAND MAKEINTRESOURCE(32649)
#تعریف_کن IDC_APPSTARTING MAKEINTRESOURCE(32650)
#تعریف_کن IDC_HELP MAKEINTRESOURCE(32651)

  WINUSERAPI WINBOOL WINAPI مجموعه_System_Cursor(HCURSOR hcur,DWORD id);

  تعريفنوع بنية _ICONINFO {
    WINBOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbm_ماسک;
    HBITMAP hbmColor;
  } ICONINFO;
  تعريفنوع ICONINFO *PICONINFO;

#اگر_تعریف_شده UNICODE
#تعریف_کن بارگیری_Icon بارگیری_Icon_W
#تعریف_کن خصوصی_استخراج_Icons خصوصی_استخراج_Icons_W
#وإلا
#تعریف_کن بارگیری_Icon بارگیری_Icon_A
#تعریف_کن خصوصی_استخراج_Icons خصوصی_استخراج_Icons_A
#پایان_اگر

  WINUSERAPI HICON WINAPI بارگیری_Icon_A(HINSTANCE hInstance,LPCSTR lpIconName);
  WINUSERAPI HICON WINAPI بارگیری_Icon_W(HINSTANCE hInstance,LPCWSTR lpIconName);
  WINUSERAPI UINT WINAPI خصوصی_استخراج_Icons_A(LPCSTR szFileName,صحيح n_Icon_شاخص,صحيح cxIcon,صحيح cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI UINT WINAPI خصوصی_استخراج_Icons_W(LPCWSTR szFileName,صحيح n_Icon_شاخص,صحيح cxIcon,صحيح cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI HICON WINAPI CreateIcon(HINSTANCE hInstance,صحيح n_عرض,صحيح n_ارتفاع,BYTE cPlanes,BYTE c_بیتها_Pixel,CONST BYTE *lpbANDbits,CONST BYTE *lpbXORbits);
  WINUSERAPI WINBOOL WINAPI DestroyIcon(HICON hIcon);
  WINUSERAPI صحيح WINAPI LookupIconIdFromDirectory(PBYTE presbits,WINBOOL fIcon);
  WINUSERAPI صحيح WINAPI LookupIconIdFromDirectoryEx(PBYTE presbits,WINBOOL fIcon,صحيح cxDesired,صحيح cyDesired,UINT Flags);
  WINUSERAPI HICON WINAPI CreateIconFromResource(PBYTE presbits,DWORD dw_Res_اندازه,WINBOOL fIcon,DWORD dwVer);
  WINUSERAPI HICON WINAPI CreateIconFromResourceEx(PBYTE presbits,DWORD dw_Res_اندازه,WINBOOL fIcon,DWORD dwVer,صحيح cxDesired,صحيح cyDesired,UINT Flags);

  تعريفنوع بنية برچسب_CURSORSHAPE {
    صحيح xHotSpot;
    صحيح yHotSpot;
    صحيح cx;
    صحيح cy;
    صحيح cb_عرض;
    BYTE Planes;
    BYTE بیتها_Pixel;
  } CURSORSHAPE,*LPCURSORSHAPE;

#تعریف_کن IMAGE_BITMAP 0
#تعریف_کن IMAGE_ICON 1
#تعریف_کن IMAGE_CURSOR 2
#تعریف_کن IMAGE_ENHMETAFILE 3

#تعریف_کن LR_DEFAULTCOLOR 0x0000
#تعریف_کن LR_MONOCHROME 0x0001
#تعریف_کن LR_COLOR 0x0002
#تعریف_کن LR_COPYRETURNORG 0x0004
#تعریف_کن LR_COPYDELETEORG 0x0008
#تعریف_کن LR_LOADFROMFILE 0x0010
#تعریف_کن LR_LOADTRANSPARENT 0x0020
#تعریف_کن LR_DEFAULTSIZE 0x0040
#تعریف_کن LR_VGACOLOR 0x0080
#تعریف_کن LR_LOADMAP3DCOLORS 0x1000
#تعریف_کن LR_CREATEDIBSECTION 0x2000
#تعریف_کن LR_COPYFROMRESOURCE 0x4000
#تعریف_کن LR_SHARED 0x8000

#اگر_تعریف_شده UNICODE
#تعریف_کن بارگیری_Image بارگیری_Image_W
#وإلا
#تعریف_کن بارگیری_Image بارگیری_Image_A
#پایان_اگر

  WINUSERAPI HANDLE WINAPI بارگیری_Image_A(HINSTANCE hInst,LPCSTR name,UINT type,صحيح cx,صحيح cy,UINT fu_بارگیری);
  WINUSERAPI HANDLE WINAPI بارگیری_Image_W(HINSTANCE hInst,LPCWSTR name,UINT type,صحيح cx,صحيح cy,UINT fu_بارگیری);
  WINUSERAPI HANDLE WINAPI CopyImage(HANDLE h,UINT type,صحيح cx,صحيح cy,UINT flags);

#تعریف_کن DI_ماسک 0x0001
#تعریف_کن DI_IMAGE 0x0002
#تعریف_کن DI_نرمال 0x0003
#تعریف_کن DI_COMPAT 0x0004
#تعریف_کن DI_DEFAULTSIZE 0x0008
#تعریف_کن DI_NOMIRROR 0x0010

  WINUSERAPI WINBOOL WINAPI DrawIconEx(HDC hdc,صحيح x_چپ,صحيح y_بالاترین,HICON hIcon,صحيح cx_عرض,صحيح cy_عرض,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
  WINUSERAPI HICON WINAPI Create_Icon_غیرمستقیم(PICONINFO piconinfo);
  WINUSERAPI HICON WINAPI CopyIcon(HICON hIcon);
  WINUSERAPI WINBOOL WINAPI GetIconInfo(HICON hIcon,PICONINFO piconinfo);

#تعریف_کن RES_ICON 1
#تعریف_کن RES_CURSOR 2

#اگر_تعریف_شده OEMRESOURCE

#تعریف_کن OBM_CLOSE 32754
#تعریف_کن OBM_UPARROW 32753
#تعریف_کن OBM_DNARROW 32752
#تعریف_کن OBM_RGARROW 32751
#تعریف_کن OBM_LFARROW 32750
#تعریف_کن OBM_REDUCE 32749
#تعریف_کن OBM_ZOOM 32748
#تعریف_کن OBM_RESTORE 32747
#تعریف_کن OBM_REDUCED 32746
#تعریف_کن OBM_ZOOMD 32745
#تعریف_کن OBM_RESTORED 32744
#تعریف_کن OBM_UPARROWD 32743
#تعریف_کن OBM_DNARROWD 32742
#تعریف_کن OBM_RGARROWD 32741
#تعریف_کن OBM_LFARROWD 32740
#تعریف_کن OBM_MNARROW 32739
#تعریف_کن OBM_COMBO 32738
#تعریف_کن OBM_UPARROWI 32737
#تعریف_کن OBM_DNARROWI 32736
#تعریف_کن OBM_RGARROWI 32735
#تعریف_کن OBM_LFARROWI 32734

#تعریف_کن OBM_OLD_CLOSE 32767
#تعریف_کن OBM_اندازه 32766
#تعریف_کن OBM_OLD_UPARROW 32765
#تعریف_کن OBM_OLD_DNARROW 32764
#تعریف_کن OBM_OLD_RGARROW 32763
#تعریف_کن OBM_OLD_LFARROW 32762
#تعریف_کن OBM_BTSIZE 32761
#تعریف_کن OBM_CHECK 32760
#تعریف_کن OBM_CHECKBOXES 32759
#تعریف_کن OBM_BTNCORNERS 32758
#تعریف_کن OBM_OLD_REDUCE 32757
#تعریف_کن OBM_OLD_ZOOM 32756
#تعریف_کن OBM_OLD_RESTORE 32755

#تعریف_کن OCR_نرمال 32512
#تعریف_کن OCR_IBEAM 32513
#تعریف_کن OCR_WAIT 32514
#تعریف_کن OCR_CROSS 32515
#تعریف_کن OCR_به_بالا 32516
#تعریف_کن OCR_اندازه 32640
#تعریف_کن OCR_ICON 32641
#تعریف_کن OCR_SIZENWSE 32642
#تعریف_کن OCR_SIZENESW 32643
#تعریف_کن OCR_SIZEWE 32644
#تعریف_کن OCR_SIZENS 32645
#تعریف_کن OCR_SIZEALL 32646
#تعریف_کن OCR_ICOCUR 32647
#تعریف_کن OCR_NO 32648
#تعریف_کن OCR_HAND 32649
#تعریف_کن OCR_APPSTARTING 32650

#تعریف_کن OIC_SAMPLE 32512
#تعریف_کن OIC_HAND 32513
#تعریف_کن OIC_QUES 32514
#تعریف_کن OIC_BANG 32515
#تعریف_کن OIC_NOTE 32516
#تعریف_کن OIC_WINLOGO 32517
#تعریف_کن OIC_WARNING OIC_BANG
#تعریف_کن OIC_ERROR OIC_HAND
#تعریف_کن OIC_INFORMATION OIC_NOTE
#پایان_اگر

#تعریف_کن ORD_LANGDRIVER 1

#اگر_تعریف_نشده NOICONS

#اگر_تعریف_شده RC_INVOKED
#تعریف_کن IDI_APPLICATION 32512
#تعریف_کن IDI_HAND 32513
#تعریف_کن IDI_QUESTION 32514
#تعریف_کن IDI_EXCLAMATION 32515
#تعریف_کن IDI_ASTERISK 32516
#تعریف_کن IDI_WINLOGO 32517
#وإلا
#تعریف_کن IDI_APPLICATION MAKEINTRESOURCE(32512)
#تعریف_کن IDI_HAND MAKEINTRESOURCE(32513)
#تعریف_کن IDI_QUESTION MAKEINTRESOURCE(32514)
#تعریف_کن IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#تعریف_کن IDI_ASTERISK MAKEINTRESOURCE(32516)
#تعریف_کن IDI_WINLOGO MAKEINTRESOURCE(32517)
#پایان_اگر

#تعریف_کن IDI_WARNING IDI_EXCLAMATION
#تعریف_کن IDI_ERROR IDI_HAND
#تعریف_کن IDI_INFORMATION IDI_ASTERISK
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن بارگیری_String بارگیری_String_W
#وإلا
#تعریف_کن بارگیری_String بارگیری_String_A
#پایان_اگر

  WINUSERAPI صحيح WINAPI بارگیری_String_A(HINSTANCE hInstance,UINT uID,LPSTR lp_میانگیر,صحيح cch_میانگیر_Max);
  WINUSERAPI صحيح WINAPI بارگیری_String_W(HINSTANCE hInstance,UINT uID,LPWSTR lp_میانگیر,صحيح cch_میانگیر_Max);

#تعریف_کن IDOK 1
#تعریف_کن IDCANCEL 2
#تعریف_کن IDABORT 3
#تعریف_کن IDRETRY 4
#تعریف_کن IDIGNORE 5
#تعریف_کن IDYES 6
#تعریف_کن IDNO 7
#تعریف_کن IDCLOSE 8
#تعریف_کن IDHELP 9
#تعریف_کن IDTRYAGAIN 10
#تعریف_کن IDCONTINUE 11

#اگر_تعریف_نشده IDTIMEOUT
#تعریف_کن IDTIMEOUT 32000
#پایان_اگر

#اگر_تعریف_نشده NOCTLMGR

#اگر_تعریف_نشده NOWINSTYLES
#تعریف_کن ES_چپ 0x0000L
#تعریف_کن ES_CENTER 0x0001L
#تعریف_کن ES_راست 0x0002L
#تعریف_کن ES_MULTILINE 0x0004L
#تعریف_کن ES_UPPERCASE 0x0008L
#تعریف_کن ES_LOWERCASE 0x0010L
#تعریف_کن ES_PASSWORD 0x0020L
#تعریف_کن ES_AUTOVSCROLL 0x0040L
#تعریف_کن ES_AUTOHSCROLL 0x0080L
#تعریف_کن ES_NOHIDESEL 0x0100L
#تعریف_کن ES_OEMCONVERT 0x0400L
#تعریف_کن ES_READONLY 0x0800L
#تعریف_کن ES_WANTRETURN 0x1000L
#تعریف_کن ES_عدد 0x2000L
#پایان_اگر

#تعریف_کن EN_SETFOCUS 0x0100
#تعریف_کن EN_KILLFOCUS 0x0200
#تعریف_کن EN_CHANGE 0x0300
#تعریف_کن EN_UPDATE 0x0400
#تعریف_کن EN_ERRSPACE 0x0500
#تعریف_کن EN_MAXTEXT 0x0501
#تعریف_کن EN_HSCROLL 0x0601
#تعریف_کن EN_VSCROLL 0x0602
#تعریف_کن EN_ALIGN_LTR_EC 0x0700
#تعریف_کن EN_ALIGN_RTL_EC 0x0701

#تعریف_کن EC_LEFTMARGIN 0x0001
#تعریف_کن EC_RIGHTMARGIN 0x0002
#تعریف_کن EC_USEFONTINFO 0xffff

#تعریف_کن EMSIS_COMPOSITIONSTRING 0x0001

#تعریف_کن EIMES_GETCOMPSTRATONCE 0x0001
#تعریف_کن EIMES_CANCELCOMPSTRINFOCUS 0x0002
#تعریف_کن EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#اگر_تعریف_نشده NOWINMESSAGES

#تعریف_کن EM_GETSEL 0x00B0
#تعریف_کن EM_SETSEL 0x00B1
#تعریف_کن EM_GETRECT 0x00B2
#تعریف_کن EM_SETRECT 0x00B3
#تعریف_کن EM_SETRECTNP 0x00B4
#تعریف_کن EM_SCROLL 0x00B5
#تعریف_کن EM_LINESCROLL 0x00B6
#تعریف_کن EM_SCROLLCARET 0x00B7
#تعریف_کن EM_GETMODIFY 0x00B8
#تعریف_کن EM_SETMODIFY 0x00B9
#تعریف_کن EM_GETLINECOUNT 0x00BA
#تعریف_کن EM_LINEINDEX 0x00BB
#تعریف_کن EM_SETHANDLE 0x00BC
#تعریف_کن EM_GETHANDLE 0x00BD
#تعریف_کن EM_GETTHUMB 0x00BE
#تعریف_کن EM_LINELENGTH 0x00C1
#تعریف_کن EM_REPLACESEL 0x00C2
#تعریف_کن EM_GETLINE 0x00C4
#تعریف_کن EM_LIMITTEXT 0x00C5
#تعریف_کن EM_CANUNDO 0x00C6
#تعریف_کن EM_UNDO 0x00C7
#تعریف_کن EM_FMTLINES 0x00C8
#تعریف_کن EM_LINEFROMCHAR 0x00C9
#تعریف_کن EM_SETTABSTOPS 0x00CB
#تعریف_کن EM_SETPASSWORDCHAR 0x00CC
#تعریف_کن EM_EMPTYUNDOBUFFER 0x00CD
#تعریف_کن EM_GETFIRSTVISIBLELINE 0x00CE
#تعریف_کن EM_SETREADONLY 0x00CF
#تعریف_کن EM_SETWORDBREAKPROC 0x00D0
#تعریف_کن EM_GETWORDBREAKPROC 0x00D1
#تعریف_کن EM_GETPASSWORDCHAR 0x00D2
#تعریف_کن EM_SETMARGINS 0x00D3
#تعریف_کن EM_GETMARGINS 0x00D4
#تعریف_کن EM_SETLIMITTEXT EM_LIMITTEXT
#تعریف_کن EM_GETLIMITTEXT 0x00D5
#تعریف_کن EM_POSFROMCHAR 0x00D6
#تعریف_کن EM_CHARFROMPOS 0x00D7
#تعریف_کن EM_SETIMESTATUS 0x00D8
#تعریف_کن EM_GETIMESTATUS 0x00D9
#پایان_اگر

#تعریف_کن WB_چپ 0
#تعریف_کن WB_راست 1
#تعریف_کن WB_ISDELIMITER 2

#تعریف_کن BS_PUSHBUTTON 0x00000000L
#تعریف_کن BS_DEFPUSHBUTTON 0x00000001L
#تعریف_کن BS_CHECKBOX 0x00000002L
#تعریف_کن BS_AUTOCHECKBOX 0x00000003L
#تعریف_کن BS_RADIOBUTTON 0x00000004L
#تعریف_کن BS_3STATE 0x00000005L
#تعریف_کن BS_AUTO3STATE 0x00000006L
#تعریف_کن BS_GROUPBOX 0x00000007L
#تعریف_کن BS_USERBUTTON 0x00000008L
#تعریف_کن BS_AUTORADIOBUTTON 0x00000009L
#تعریف_کن BS_PUSHBOX 0x0000000AL
#تعریف_کن BS_OWNERDRAW 0x0000000BL
#تعریف_کن BS_TYPEMASK 0x0000000FL
#تعریف_کن BS_LEFTTEXT 0x00000020L
#تعریف_کن BS_متن 0x00000000L
#تعریف_کن BS_ICON 0x00000040L
#تعریف_کن BS_BITMAP 0x00000080L
#تعریف_کن BS_چپ 0x00000100L
#تعریف_کن BS_راست 0x00000200L
#تعریف_کن BS_CENTER 0x00000300L
#تعریف_کن BS_بالاترین 0x00000400L
#تعریف_کن BS_BOTTOM 0x00000800L
#تعریف_کن BS_VCENTER 0x00000C00L
#تعریف_کن BS_PUSHLIKE 0x00001000L
#تعریف_کن BS_MULTILINE 0x00002000L
#تعریف_کن BS_NOTIFY 0x00004000L
#تعریف_کن BS_FLAT 0x00008000L
#تعریف_کن BS_RIGHTBUTTON BS_LEFTTEXT

#تعریف_کن BN_CLICKED 0
#تعریف_کن BN_PAINT 1
#تعریف_کن BN_HILITE 2
#تعریف_کن BN_UNHILITE 3
#تعریف_کن BN_DISABLE 4
#تعریف_کن BN_DOUBLECLICKED 5
#تعریف_کن BN_PUSHED BN_HILITE
#تعریف_کن BN_UNPUSHED BN_UNHILITE
#تعریف_کن BN_DBLCLK BN_DOUBLECLICKED
#تعریف_کن BN_SETFOCUS 6
#تعریف_کن BN_KILLFOCUS 7

#تعریف_کن BM_GETCHECK 0x00F0
#تعریف_کن BM_SETCHECK 0x00F1
#تعریف_کن BM_GETSTATE 0x00F2
#تعریف_کن BM_SETSTATE 0x00F3
#تعریف_کن BM_SETSTYLE 0x00F4
#تعریف_کن BM_CLICK 0x00F5
#تعریف_کن BM_GETIMAGE 0x00F6
#تعریف_کن BM_SETIMAGE 0x00F7

#تعریف_کن BST_UNCHECKED 0x0000
#تعریف_کن BST_CHECKED 0x0001
#تعریف_کن BST_INDETERMINATE 0x0002
#تعریف_کن BST_PUSHED 0x0004
#تعریف_کن BST_FOCUS 0x0008

#تعریف_کن SS_چپ 0x00000000L
#تعریف_کن SS_CENTER 0x00000001L
#تعریف_کن SS_راست 0x00000002L
#تعریف_کن SS_ICON 0x00000003L
#تعریف_کن SS_BLACKRECT 0x00000004L
#تعریف_کن SS_GRAYRECT 0x00000005L
#تعریف_کن SS_WHITERECT 0x00000006L
#تعریف_کن SS_BLACKFRAME 0x00000007L
#تعریف_کن SS_GRAYFRAME 0x00000008L
#تعریف_کن SS_WHITEFRAME 0x00000009L
#تعریف_کن SS_USERITEM 0x0000000AL
#تعریف_کن SS_SIMPLE 0x0000000BL
#تعریف_کن SS_LEFTNOWORDWRAP 0x0000000CL
#تعریف_کن SS_OWNERDRAW 0x0000000DL
#تعریف_کن SS_BITMAP 0x0000000EL
#تعریف_کن SS_ENHMETAFILE 0x0000000FL
#تعریف_کن SS_ETCHEDHORZ 0x00000010L
#تعریف_کن SS_ETCHEDVERT 0x00000011L
#تعریف_کن SS_ETCHEDFRAME 0x00000012L
#تعریف_کن SS_TYPEMASK 0x0000001FL
#تعریف_کن SS_REALSIZECONTROL 0x00000040L
#تعریف_کن SS_NOPREFIX 0x00000080L
#تعریف_کن SS_NOTIFY 0x00000100L
#تعریف_کن SS_CENTERIMAGE 0x00000200L
#تعریف_کن SS_RIGHTJUST 0x00000400L
#تعریف_کن SS_REALSIZEIMAGE 0x00000800L
#تعریف_کن SS_SUNKEN 0x00001000L
#تعریف_کن SS_EDITCONTROL 0x00002000L
#تعریف_کن SS_ENDELLIPSIS 0x00004000L
#تعریف_کن SS_PATHELLIPSIS 0x00008000L
#تعریف_کن SS_WORDELLIPSIS 0x0000C000L
#تعریف_کن SS_ELLIPSISMASK 0x0000C000L

#اگر_تعریف_نشده NOWINMESSAGES

#تعریف_کن STM_SETICON 0x0170
#تعریف_کن STM_GETICON 0x0171
#تعریف_کن STM_SETIMAGE 0x0172
#تعریف_کن STM_GETIMAGE 0x0173
#تعریف_کن STN_CLICKED 0
#تعریف_کن STN_DBLCLK 1
#تعریف_کن STN_ENABLE 2
#تعریف_کن STN_DISABLE 3
#تعریف_کن STM_MSGMAX 0x0174
#پایان_اگر

#تعریف_کن WC_DIALOG (MAKEINTATOM(0x8002))

#تعریف_کن DWL_MSGRESULT 0
#تعریف_کن DWL_DLGPROC 4
#تعریف_کن DWL_USER 8

#اگر_تعریف_شده _WIN64

#لغو_تعریف DWL_MSGRESULT
#لغو_تعریف DWL_DLGPROC
#لغو_تعریف DWL_USER
#پایان_اگر

#تعریف_کن DWLP_MSGRESULT 0
#تعریف_کن DWLP_DLGPROC DWLP_MSGRESULT + حجم(LRESULT)
#تعریف_کن DWLP_USER DWLP_DLGPROC + حجم(DLGPROC)

#اگر_تعریف_نشده NOMSG

#اگر_تعریف_شده UNICODE
#تعریف_کن Is_Dialog_پیام Is_Dialog_پیام_W
#وإلا
#تعریف_کن Is_Dialog_پیام Is_Dialog_پیام_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI Is_Dialog_پیام_A(HWND hDlg,LPMSG lp_پیام_2);
  WINUSERAPI WINBOOL WINAPI Is_Dialog_پیام_W(HWND hDlg,LPMSG lp_پیام_2);
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن DlgDirList DlgDirListW
#تعریف_کن DlgDirSelectEx DlgDirSelectExW
#تعریف_کن DlgDirListComboBox DlgDirListComboBoxW
#تعریف_کن DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#وإلا
#تعریف_کن DlgDirList DlgDirListA
#تعریف_کن DlgDirSelectEx DlgDirSelectExA
#تعریف_کن DlgDirListComboBox DlgDirListComboBoxA
#تعریف_کن DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI MapDialogRect(HWND hDlg,LPRECT lpRect);
  WINUSERAPI صحيح WINAPI DlgDirListA(HWND hDlg,LPSTR lp_مسیر_Spec,صحيح nIDListBox,صحيح n_IDStatic_مسیر,UINT uFileType);
  WINUSERAPI صحيح WINAPI DlgDirListW(HWND hDlg,LPWSTR lp_مسیر_Spec,صحيح nIDListBox,صحيح n_IDStatic_مسیر,UINT uFileType);

#تعریف_کن DDL_READWRITE 0x0000
#تعریف_کن DDL_READONLY 0x0001
#تعریف_کن DDL_HIDDEN 0x0002
#تعریف_کن DDL_SYSTEM 0x0004
#تعریف_کن DDL_DIRECTORY 0x0010
#تعریف_کن DDL_ARCHIVE 0x0020

#تعریف_کن DDL_POSTMSGS 0x2000
#تعریف_کن DDL_DRIVES 0x4000
#تعریف_کن DDL_EXCLUSIVE 0x8000

  WINUSERAPI WINBOOL WINAPI DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,صحيح ch_شمار,صحيح idListBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,صحيح ch_شمار,صحيح idListBox);
  WINUSERAPI صحيح WINAPI DlgDirListComboBoxA(HWND hDlg,LPSTR lp_مسیر_Spec,صحيح nIDComboBox,صحيح n_IDStatic_مسیر,UINT uFiletype);
  WINUSERAPI صحيح WINAPI DlgDirListComboBoxW(HWND hDlg,LPWSTR lp_مسیر_Spec,صحيح nIDComboBox,صحيح n_IDStatic_مسیر,UINT uFiletype);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,صحيح cch_بیرون,صحيح idComboBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,صحيح cch_بیرون,صحيح idComboBox);

#تعریف_کن DS_ABSALIGN 0x01L
#تعریف_کن DS_SYSMODAL 0x02L
#تعریف_کن DS_LOCALEDIT 0x20L
#تعریف_کن DS_SETFONT 0x40L
#تعریف_کن DS_MODALFRAME 0x80L
#تعریف_کن DS_NOIDLEMSG 0x100L
#تعریف_کن DS_SETFOREGROUND 0x200L

#تعریف_کن DS_3DLOOK 0x0004L
#تعریف_کن DS_FIXEDSYS 0x0008L
#تعریف_کن DS_NOFAILCREATE 0x0010L
#تعریف_کن DS_CONTROL 0x0400L
#تعریف_کن DS_CENTER 0x0800L
#تعریف_کن DS_CENTERMOUSE 0x1000L
#تعریف_کن DS_CONTEXTHELP 0x2000L

#تعریف_کن DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#إذا(_WIN32_WCE >= 0x0500)
#تعریف_کن DS_USEPIXELS 0x8000L
#پایان_اگر

#تعریف_کن DM_GETDEFID (WM_USER+0)
#تعریف_کن DM_SETDEFID (WM_USER+1)
#تعریف_کن DM_REPOSITION (WM_USER+2)

#تعریف_کن DC_HASDEFID 0x534B

#تعریف_کن DLGC_WANTARROWS 0x0001
#تعریف_کن DLGC_WANTTAB 0x0002
#تعریف_کن DLGC_WANTALLKEYS 0x0004
#تعریف_کن DLGC_WANTMESSAGE 0x0004
#تعریف_کن DLGC_HASSETSEL 0x0008
#تعریف_کن DLGC_DEFPUSHBUTTON 0x0010
#تعریف_کن DLGC_UNDEFPUSHBUTTON 0x0020
#تعریف_کن DLGC_RADIOBUTTON 0x0040
#تعریف_کن DLGC_WANTCHARS 0x0080
#تعریف_کن DLGC_STATIC 0x0100
#تعریف_کن DLGC_BUTTON 0x2000

#تعریف_کن LB_CTLCODE 0L

#تعریف_کن LB_OKAY 0
#تعریف_کن LB_ERR (-1)
#تعریف_کن LB_ERRSPACE (-2)

#تعریف_کن LBN_ERRSPACE (-2)
#تعریف_کن LBN_SELCHANGE 1
#تعریف_کن LBN_DBLCLK 2
#تعریف_کن LBN_SELCANCEL 3
#تعریف_کن LBN_SETFOCUS 4
#تعریف_کن LBN_KILLFOCUS 5

#اگر_تعریف_نشده NOWINMESSAGES

#تعریف_کن LB_ADDSTRING 0x0180
#تعریف_کن LB_INSERTSTRING 0x0181
#تعریف_کن LB_DELETESTRING 0x0182
#تعریف_کن LB_SELITEMRANGEEX 0x0183
#تعریف_کن LB_RESETCONTENT 0x0184
#تعریف_کن LB_SETSEL 0x0185
#تعریف_کن LB_SETCURSEL 0x0186
#تعریف_کن LB_GETSEL 0x0187
#تعریف_کن LB_GETCURSEL 0x0188
#تعریف_کن LB_GETTEXT 0x0189
#تعریف_کن LB_GETTEXTLEN 0x018A
#تعریف_کن LB_GETCOUNT 0x018B
#تعریف_کن LB_SELECTSTRING 0x018C
#تعریف_کن LB_DIR 0x018D
#تعریف_کن LB_GETTOPINDEX 0x018E
#تعریف_کن LB_FINDSTRING 0x018F
#تعریف_کن LB_GETSELCOUNT 0x0190
#تعریف_کن LB_GETSELITEMS 0x0191
#تعریف_کن LB_SETTABSTOPS 0x0192
#تعریف_کن LB_GETHORIZONTALEXTENT 0x0193
#تعریف_کن LB_SETHORIZONTALEXTENT 0x0194
#تعریف_کن LB_SETCOLUMNWIDTH 0x0195
#تعریف_کن LB_ADDFILE 0x0196
#تعریف_کن LB_SETTOPINDEX 0x0197
#تعریف_کن LB_GETITEMRECT 0x0198
#تعریف_کن LB_GETITEMDATA 0x0199
#تعریف_کن LB_SETITEMDATA 0x019A
#تعریف_کن LB_SELITEMRANGE 0x019B
#تعریف_کن LB_SETANCHORINDEX 0x019C
#تعریف_کن LB_GETANCHORINDEX 0x019D
#تعریف_کن LB_SETCARETINDEX 0x019E
#تعریف_کن LB_GETCARETINDEX 0x019F
#تعریف_کن LB_SETITEMHEIGHT 0x01A0
#تعریف_کن LB_GETITEMHEIGHT 0x01A1
#تعریف_کن LB_FINDSTRINGEXACT 0x01A2
#تعریف_کن LB_SETLOCALE 0x01A5
#تعریف_کن LB_GETLOCALE 0x01A6
#تعریف_کن LB_SETCOUNT 0x01A7
#تعریف_کن LB_INITSTORAGE 0x01A8
#تعریف_کن LB_ITEMFROMPOINT 0x01A9
#إذا(_WIN32_WCE >= 0x0400)
#تعریف_کن LB_MULTIPLEADDSTRING 0x01B1
#پایان_اگر
#تعریف_کن LB_GETLISTBOXINFO 0x01B2
#تعریف_کن LB_MSGMAX 0x01B3
#پایان_اگر

#اگر_تعریف_نشده NOWINSTYLES

#تعریف_کن LBS_NOTIFY 0x0001L
#تعریف_کن LBS_مرتب_سازی 0x0002L
#تعریف_کن LBS_NOREDRAW 0x0004L
#تعریف_کن LBS_MULTIPLESEL 0x0008L
#تعریف_کن LBS_OWNERDRAWFIXED 0x0010L
#تعریف_کن LBS_OWNERDRAWVARIABLE 0x0020L
#تعریف_کن LBS_HASSTRINGS 0x0040L
#تعریف_کن LBS_USETABSTOPS 0x0080L
#تعریف_کن LBS_NOINTEGRALHEIGHT 0x0100L
#تعریف_کن LBS_MULTICOLUMN 0x0200L
#تعریف_کن LBS_WANTKEYBOARDINPUT 0x0400L
#تعریف_کن LBS_EXTENDEDSEL 0x0800L
#تعریف_کن LBS_DISABLENOSCROLL 0x1000L
#تعریف_کن LBS_NODATA 0x2000L
#تعریف_کن LBS_NOSEL 0x4000L
#تعریف_کن LBS_COMBOBOX 0x8000L

#تعریف_کن LBS_STANDARD (LBS_NOTIFY | LBS_مرتب_سازی | WS_VSCROLL | WS_BORDER)
#پایان_اگر

#تعریف_کن CB_OKAY 0
#تعریف_کن CB_ERR (-1)
#تعریف_کن CB_ERRSPACE (-2)

#تعریف_کن CBN_ERRSPACE (-1)
#تعریف_کن CBN_SELCHANGE 1
#تعریف_کن CBN_DBLCLK 2
#تعریف_کن CBN_SETFOCUS 3
#تعریف_کن CBN_KILLFOCUS 4
#تعریف_کن CBN_EDITCHANGE 5
#تعریف_کن CBN_EDITUPDATE 6
#تعریف_کن CBN_DROPDOWN 7
#تعریف_کن CBN_CLOSEUP 8
#تعریف_کن CBN_SELENDOK 9
#تعریف_کن CBN_SELENDCANCEL 10

#اگر_تعریف_نشده NOWINSTYLES

#تعریف_کن CBS_SIMPLE 0x0001L
#تعریف_کن CBS_DROPDOWN 0x0002L
#تعریف_کن CBS_DROPDOWNLIST 0x0003L
#تعریف_کن CBS_OWNERDRAWFIXED 0x0010L
#تعریف_کن CBS_OWNERDRAWVARIABLE 0x0020L
#تعریف_کن CBS_AUTOHSCROLL 0x0040L
#تعریف_کن CBS_OEMCONVERT 0x0080L
#تعریف_کن CBS_مرتب_سازی 0x0100L
#تعریف_کن CBS_HASSTRINGS 0x0200L
#تعریف_کن CBS_NOINTEGRALHEIGHT 0x0400L
#تعریف_کن CBS_DISABLENOSCROLL 0x0800L
#تعریف_کن CBS_UPPERCASE 0x2000L
#تعریف_کن CBS_LOWERCASE 0x4000L
#پایان_اگر

#اگر_تعریف_نشده NOWINMESSAGES
#تعریف_کن CB_GETEDITSEL 0x0140
#تعریف_کن CB_LIMITTEXT 0x0141
#تعریف_کن CB_SETEDITSEL 0x0142
#تعریف_کن CB_ADDSTRING 0x0143
#تعریف_کن CB_DELETESTRING 0x0144
#تعریف_کن CB_DIR 0x0145
#تعریف_کن CB_GETCOUNT 0x0146
#تعریف_کن CB_GETCURSEL 0x0147
#تعریف_کن CB_GETLBTEXT 0x0148
#تعریف_کن CB_GETLBTEXTLEN 0x0149
#تعریف_کن CB_INSERTSTRING 0x014A
#تعریف_کن CB_RESETCONTENT 0x014B
#تعریف_کن CB_FINDSTRING 0x014C
#تعریف_کن CB_SELECTSTRING 0x014D
#تعریف_کن CB_SETCURSEL 0x014E
#تعریف_کن CB_SHOWDROPDOWN 0x014F
#تعریف_کن CB_GETITEMDATA 0x0150
#تعریف_کن CB_SETITEMDATA 0x0151
#تعریف_کن CB_GETDROPPEDCONTROLRECT 0x0152
#تعریف_کن CB_SETITEMHEIGHT 0x0153
#تعریف_کن CB_GETITEMHEIGHT 0x0154
#تعریف_کن CB_SETEXTENDEDUI 0x0155
#تعریف_کن CB_GETEXTENDEDUI 0x0156
#تعریف_کن CB_GETDROPPEDSTATE 0x0157
#تعریف_کن CB_FINDSTRINGEXACT 0x0158
#تعریف_کن CB_SETLOCALE 0x0159
#تعریف_کن CB_GETLOCALE 0x015A
#تعریف_کن CB_GETTOPINDEX 0x015b
#تعریف_کن CB_SETTOPINDEX 0x015c
#تعریف_کن CB_GETHORIZONTALEXTENT 0x015d
#تعریف_کن CB_SETHORIZONTALEXTENT 0x015e
#تعریف_کن CB_GETDROPPEDWIDTH 0x015f
#تعریف_کن CB_SETDROPPEDWIDTH 0x0160
#تعریف_کن CB_INITSTORAGE 0x0161
#إذا(_WIN32_WCE >= 0x0400)
#تعریف_کن CB_MULTIPLEADDSTRING 0x0163
#پایان_اگر
#تعریف_کن CB_GETCOMBOBOXINFO 0x0164
#تعریف_کن CB_MSGMAX 0x0165
#پایان_اگر

#اگر_تعریف_نشده NOWINSTYLES

#تعریف_کن SBS_HORZ 0x0000L
#تعریف_کن SBS_VERT 0x0001L
#تعریف_کن SBS_TOPALIGN 0x0002L
#تعریف_کن SBS_LEFTALIGN 0x0002L
#تعریف_کن SBS_BOTTOMALIGN 0x0004L
#تعریف_کن SBS_RIGHTALIGN 0x0004L
#تعریف_کن SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#تعریف_کن SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#تعریف_کن SBS_SIZEBOX 0x0008L
#تعریف_کن SBS_SIZEGRIP 0x0010L
#پایان_اگر

#اگر_تعریف_نشده NOWINMESSAGES
#تعریف_کن SBM_SETPOS 0x00E0
#تعریف_کن SBM_GETPOS 0x00E1
#تعریف_کن SBM_SETRANGE 0x00E2
#تعریف_کن SBM_SETRANGEREDRAW 0x00E6
#تعریف_کن SBM_GETRANGE 0x00E3
#تعریف_کن SBM_ENABLE_ARROWS 0x00E4
#تعریف_کن SBM_SETSCROLLINFO 0x00E9
#تعریف_کن SBM_GETSCROLLINFO 0x00EA
#تعریف_کن SBM_GETSCROLLBARINFO 0x00EB

#تعریف_کن SIF_RANGE 0x0001
#تعریف_کن SIF_صفحه 0x0002
#تعریف_کن SIF_POS 0x0004
#تعریف_کن SIF_DISABLENOSCROLL 0x0008
#تعریف_کن SIF_TRACKPOS 0x0010
#تعریف_کن SIF_ALL (SIF_RANGE | SIF_صفحه | SIF_POS | SIF_TRACKPOS)

  تعريفنوع بنية برچسب_SCROLLINFO {
    UINT cb_اندازه;
    UINT f_ماسک;
    صحيح nMin;
    صحيح nMax;
    UINT n_صفحه;
    صحيح nPos;
    صحيح nTrackPos;
  } SCROLLINFO,*LPSCROLLINFO;
  تعريفنوع SCROLLINFO CONST *LPCSCROLLINFO;

  WINUSERAPI صحيح WINAPI مجموعه_Scroll_Info(HWND hwnd,صحيح nBar,LPCSCROLLINFO lpsi,WINBOOL redraw);
  WINUSERAPI WINBOOL WINAPI GetScrollInfo(HWND hwnd,صحيح nBar,LPSCROLLINFO lpsi);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده NOMDI

#تعریف_کن MDIS_ALLCHILDSTYLES 0x0001

#تعریف_کن MDITILE_VERTICAL 0x0000
#تعریف_کن MDITILE_HORIZONTAL 0x0001
#تعریف_کن MDITILE_SKIPDISABLED 0x0002
#تعریف_کن MDITILE_ZORDER 0x0004

  تعريفنوع بنية برچسب_MDICREATESTRUCTA {
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

  تعريفنوع بنية برچسب_MDICREATESTRUCTW {
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

#اگر_تعریف_شده UNICODE
  تعريفنوع MDICREATESTRUCTW MDICREATESTRUCT;
  تعريفنوع LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#وإلا
  تعريفنوع MDICREATESTRUCTA MDICREATESTRUCT;
  تعريفنوع LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#پایان_اگر

  تعريفنوع بنية برچسب_CLIENTCREATESTRUCT {
    HANDLE h_پنجره_Menu;
    UINT id_اولی_فرزند;
  } CLIENTCREATESTRUCT,*LPCLIENTCREATESTRUCT;

#اگر_تعریف_شده UNICODE
#تعریف_کن Def_قاب_Proc Def_قاب_Proc_W
#تعریف_کن DefMDIChildProc DefMDIChildProcW
#تعریف_کن CreateMDIWindow CreateMDIWindowW
#وإلا
#تعریف_کن Def_قاب_Proc Def_قاب_Proc_A
#تعریف_کن DefMDIChildProc DefMDIChildProcA
#تعریف_کن CreateMDIWindow CreateMDIWindowA
#پایان_اگر

  WINUSERAPI LRESULT WINAPI Def_قاب_Proc_A(HWND hWnd,HWND hWndMDIClient,UINT u_پیام,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_قاب_Proc_W(HWND hWnd,HWND hWndMDIClient,UINT u_پیام,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcA(HWND hWnd,UINT u_پیام,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcW(HWND hWnd,UINT u_پیام,WPARAM wParam,LPARAM lParam);

#اگر_تعریف_نشده NOMSG
  WINUSERAPI WINBOOL WINAPI TranslateMDISysAccel(HWND hWndClient,LPMSG lp_پیام_2);
#پایان_اگر

  WINUSERAPI UINT WINAPI ArrangeIconicWindows(HWND hWnd);
  WINUSERAPI HWND WINAPI CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lp_پنجره_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_عرض,صحيح n_ارتفاع,HWND h_Wnd_والد,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI HWND WINAPI CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lp_پنجره_Name,DWORD dwStyle,صحيح X,صحيح Y,صحيح n_عرض,صحيح n_ارتفاع,HWND h_Wnd_والد,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI کلمه_3 WINAPI TileWindows(HWND hwnd_والد_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ثابت HWND *lpKids);
  WINUSERAPI کلمه_3 WINAPI CascadeWindows(HWND hwnd_والد_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ثابت HWND *lpKids);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده NOHELP

  تعريفنوع DWORD HELPPOLY;
  تعريفنوع بنية برچسب_MULTIKEYHELPA {
    DWORD mk_اندازه;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
  } MULTIKEYHELPA,*PMULTIKEYHELPA,*LPMULTIKEYHELPA;

  تعريفنوع بنية برچسب_MULTIKEYHELPW {
    DWORD mk_اندازه;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
  } MULTIKEYHELPW,*PMULTIKEYHELPW,*LPMULTIKEYHELPW;

#اگر_تعریف_شده UNICODE
  تعريفنوع MULTIKEYHELPW MULTIKEYHELP;
  تعريفنوع PMULTIKEYHELPW PMULTIKEYHELP;
  تعريفنوع LPMULTIKEYHELPW LPMULTIKEYHELP;
#وإلا
  تعريفنوع MULTIKEYHELPA MULTIKEYHELP;
  تعريفنوع PMULTIKEYHELPA PMULTIKEYHELP;
  تعريفنوع LPMULTIKEYHELPA LPMULTIKEYHELP;
#پایان_اگر

  تعريفنوع بنية برچسب_HELPWININFOA {
    صحيح w_Struct_اندازه;
    صحيح x;
    صحيح y;
    صحيح dx;
    صحيح dy;
    صحيح wMax;
    CHAR rgchMember[2];
  } HELPWININFOA,*PHELPWININFOA,*LPHELPWININFOA;

  تعريفنوع بنية برچسب_HELPWININFOW {
    صحيح w_Struct_اندازه;
    صحيح x;
    صحيح y;
    صحيح dx;
    صحيح dy;
    صحيح wMax;
    WCHAR rgchMember[2];
  } HELPWININFOW,*PHELPWININFOW,*LPHELPWININFOW;

#اگر_تعریف_شده UNICODE
  تعريفنوع HELPWININFOW HELPWININFO;
  تعريفنوع PHELPWININFOW PHELPWININFO;
  تعريفنوع LPHELPWININFOW LPHELPWININFO;
#وإلا
  تعريفنوع HELPWININFOA HELPWININFO;
  تعريفنوع PHELPWININFOA PHELPWININFO;
  تعريفنوع LPHELPWININFOA LPHELPWININFO;
#پایان_اگر

#تعریف_کن HELP_CONTEXT 0x0001L
#تعریف_کن HELP_QUIT 0x0002L
#تعریف_کن HELP_شاخص 0x0003L
#تعریف_کن HELP_CONTENTS 0x0003L
#تعریف_کن HELP_HELPONHELP 0x0004L
#تعریف_کن HELP_SETINDEX 0x0005L
#تعریف_کن HELP_SETCONTENTS 0x0005L
#تعریف_کن HELP_CONTEXTPOPUP 0x0008L
#تعریف_کن HELP_FORCEFILE 0x0009L
#تعریف_کن HELP_کلید 0x0101L
#تعریف_کن HELP_COMMAND 0x0102L
#تعریف_کن HELP_PARTIALKEY 0x0105L
#تعریف_کن HELP_MULTIKEY 0x0201L
#تعریف_کن HELP_SETWINPOS 0x0203L
#تعریف_کن HELP_CONTEXTMENU 0x000a
#تعریف_کن HELP_FINDER 0x000b
#تعریف_کن HELP_WM_HELP 0x000c
#تعریف_کن HELP_SETPOPUP_POS 0x000d

#تعریف_کن HELP_TCARD 0x8000
#تعریف_کن HELP_TCARD_داده 0x0010
#تعریف_کن HELP_TCARD_OTHER_CALLER 0x0011

#تعریف_کن IDH_NO_HELP 28440
#تعریف_کن IDH_MISSING_CONTEXT 28441
#تعریف_کن IDH_GENERIC_HELP_BUTTON 28442
#تعریف_کن IDH_OK 28443
#تعریف_کن IDH_CANCEL 28444
#تعریف_کن IDH_HELP 28445

#اگر_تعریف_شده UNICODE
#تعریف_کن WinHelp WinHelpW
#وإلا
#تعریف_کن WinHelp WinHelpA
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dw_داده);
  WINUSERAPI WINBOOL WINAPI WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dw_داده);
#پایان_اگر

#تعریف_کن GR_GDIOBJECTS 0
#تعریف_کن GR_USEROBJECTS 1

  WINUSERAPI DWORD WINAPI GetGuiResources(HANDLE hProcess,DWORD uiFlags);

#اگر_تعریف_نشده NOSYSPARAMSINFO

#تعریف_کن SPI_GETBEEP 0x0001
#تعریف_کن SPI_SETBEEP 0x0002
#تعریف_کن SPI_GETMOUSE 0x0003
#تعریف_کن SPI_SETMOUSE 0x0004
#تعریف_کن SPI_GETBORDER 0x0005
#تعریف_کن SPI_SETBORDER 0x0006
#تعریف_کن SPI_GETKEYBOARDSPEED 0x000A
#تعریف_کن SPI_SETKEYBOARDSPEED 0x000B
#تعریف_کن SPI_LANGDRIVER 0x000C
#تعریف_کن SPI_ICONHORIZONTALSPACING 0x000D
#تعریف_کن SPI_GETSCREENSAVETIMEOUT 0x000E
#تعریف_کن SPI_SETSCREENSAVETIMEOUT 0x000F
#تعریف_کن SPI_GETSCREENSAVEACTIVE 0x0010
#تعریف_کن SPI_SETSCREENSAVEACTIVE 0x0011
#تعریف_کن SPI_GETGRIDGRANULARITY 0x0012
#تعریف_کن SPI_SETGRIDGRANULARITY 0x0013
#تعریف_کن SPI_SETDESKWALLPAPER 0x0014
#تعریف_کن SPI_SETDESKPATTERN 0x0015
#تعریف_کن SPI_GETKEYBOARDDELAY 0x0016
#تعریف_کن SPI_SETKEYBOARDDELAY 0x0017
#تعریف_کن SPI_ICONVERTICALSPACING 0x0018
#تعریف_کن SPI_GETICONTITLEWRAP 0x0019
#تعریف_کن SPI_SETICONTITLEWRAP 0x001A
#تعریف_کن SPI_GETMENUDROPALIGNMENT 0x001B
#تعریف_کن SPI_SETMENUDROPALIGNMENT 0x001C
#تعریف_کن SPI_SETDOUBLECLKWIDTH 0x001D
#تعریف_کن SPI_SETDOUBLECLKHEIGHT 0x001E
#تعریف_کن SPI_GETICONTITLELOGFONT 0x001F
#تعریف_کن SPI_SETDOUBLECLICKTIME 0x0020
#تعریف_کن SPI_SETMOUSEBUTTONSWAP 0x0021
#تعریف_کن SPI_SETICONTITLELOGFONT 0x0022
#تعریف_کن SPI_GETFASTTASKSWITCH 0x0023
#تعریف_کن SPI_SETFASTTASKSWITCH 0x0024
#تعریف_کن SPI_SETDRAGFULLWINDOWS 0x0025
#تعریف_کن SPI_GETDRAGFULLWINDOWS 0x0026
#تعریف_کن SPI_GETNONCLIENTMETRICS 0x0029
#تعریف_کن SPI_SETNONCLIENTMETRICS 0x002A
#تعریف_کن SPI_GETMINIMIZEDMETRICS 0x002B
#تعریف_کن SPI_SETMINIMIZEDMETRICS 0x002C
#تعریف_کن SPI_GETICONMETRICS 0x002D
#تعریف_کن SPI_SETICONMETRICS 0x002E
#تعریف_کن SPI_SETWORKAREA 0x002F
#تعریف_کن SPI_GETWORKAREA 0x0030
#تعریف_کن SPI_SETPENWINDOWS 0x0031

#تعریف_کن SPI_GETHIGHCONTRAST 0x0042
#تعریف_کن SPI_SETHIGHCONTRAST 0x0043
#تعریف_کن SPI_GETKEYBOARDPREF 0x0044
#تعریف_کن SPI_SETKEYBOARDPREF 0x0045
#تعریف_کن SPI_GETSCREENREADER 0x0046
#تعریف_کن SPI_SETSCREENREADER 0x0047
#تعریف_کن SPI_GETANIMATION 0x0048
#تعریف_کن SPI_SETANIMATION 0x0049
#تعریف_کن SPI_GETFONTSMOOTHING 0x004A
#تعریف_کن SPI_SETFONTSMOOTHING 0x004B
#تعریف_کن SPI_SETDRAGWIDTH 0x004C
#تعریف_کن SPI_SETDRAGHEIGHT 0x004D
#تعریف_کن SPI_SETHANDHELD 0x004E
#تعریف_کن SPI_GETLOWPOWERTIMEOUT 0x004F
#تعریف_کن SPI_GETPOWEROFFTIMEOUT 0x0050
#تعریف_کن SPI_SETLOWPOWERTIMEOUT 0x0051
#تعریف_کن SPI_SETPOWEROFFTIMEOUT 0x0052
#تعریف_کن SPI_GETLOWPOWERACTIVE 0x0053
#تعریف_کن SPI_GETPOWEROFFACTIVE 0x0054
#تعریف_کن SPI_SETLOWPOWERACTIVE 0x0055
#تعریف_کن SPI_SETPOWEROFFACTIVE 0x0056
#تعریف_کن SPI_SETCURSORS 0x0057
#تعریف_کن SPI_SETICONS 0x0058
#تعریف_کن SPI_GETDEFAULTINPUTLANG 0x0059
#تعریف_کن SPI_SETDEFAULTINPUTLANG 0x005A
#تعریف_کن SPI_SETLANGTOGGLE 0x005B
#تعریف_کن SPI_GETWINDOWSEXTENSION 0x005C
#تعریف_کن SPI_SETMOUSETRAILS 0x005D
#تعریف_کن SPI_GETMOUSETRAILS 0x005E
#تعریف_کن SPI_SETSCREENSAVERRUNNING 0x0061
#تعریف_کن SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#تعریف_کن SPI_GETFILTERKEYS 0x0032
#تعریف_کن SPI_SETFILTERKEYS 0x0033
#تعریف_کن SPI_GETTOGGLEKEYS 0x0034
#تعریف_کن SPI_SETTOGGLEKEYS 0x0035
#تعریف_کن SPI_GETMOUSEKEYS 0x0036
#تعریف_کن SPI_SETMOUSEKEYS 0x0037
#تعریف_کن SPI_GETSHOWSOUNDS 0x0038
#تعریف_کن SPI_SETSHOWSOUNDS 0x0039
#تعریف_کن SPI_GETSTICKYKEYS 0x003A
#تعریف_کن SPI_SETSTICKYKEYS 0x003B
#تعریف_کن SPI_GETACCESSTIMEOUT 0x003C
#تعریف_کن SPI_SETACCESSTIMEOUT 0x003D
#تعریف_کن SPI_GETSERIALKEYS 0x003E
#تعریف_کن SPI_SETSERIALKEYS 0x003F
#تعریف_کن SPI_GETSOUNDSENTRY 0x0040
#تعریف_کن SPI_SETSOUNDSENTRY 0x0041
#تعریف_کن SPI_GETSNAPTODEFBUTTON 0x005F
#تعریف_کن SPI_SETSNAPTODEFBUTTON 0x0060
#تعریف_کن SPI_GETMOUSEHOVERWIDTH 0x0062
#تعریف_کن SPI_SETMOUSEHOVERWIDTH 0x0063
#تعریف_کن SPI_GETMOUSEHOVERHEIGHT 0x0064
#تعریف_کن SPI_SETMOUSEHOVERHEIGHT 0x0065
#تعریف_کن SPI_GETMOUSEHOVERTIME 0x0066
#تعریف_کن SPI_SETMOUSEHOVERTIME 0x0067
#تعریف_کن SPI_GETWHEELSCROLLLINES 0x0068
#تعریف_کن SPI_SETWHEELSCROLLLINES 0x0069
#تعریف_کن SPI_GETMENUSHOWDELAY 0x006A
#تعریف_کن SPI_SETMENUSHOWDELAY 0x006B
#تعریف_کن SPI_GETSHOWIMEUI 0x006E
#تعریف_کن SPI_SETSHOWIMEUI 0x006F
#تعریف_کن SPI_GETMOUSESPEED 0x0070
#تعریف_کن SPI_SETMOUSESPEED 0x0071
#تعریف_کن SPI_GETSCREENSAVERRUNNING 0x0072
#تعریف_کن SPI_GETDESKWALLPAPER 0x0073

#تعریف_کن SPI_GETACTIVEWINDOWTRACKING 0x1000
#تعریف_کن SPI_SETACTIVEWINDOWTRACKING 0x1001
#تعریف_کن SPI_GETMENUANIMATION 0x1002
#تعریف_کن SPI_SETMENUANIMATION 0x1003
#تعریف_کن SPI_GETCOMBOBOXANIMATION 0x1004
#تعریف_کن SPI_SETCOMBOBOXANIMATION 0x1005
#تعریف_کن SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#تعریف_کن SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#تعریف_کن SPI_GETGRADIENTCAPTIONS 0x1008
#تعریف_کن SPI_SETGRADIENTCAPTIONS 0x1009
#تعریف_کن SPI_GETKEYBOARDCUES 0x100A
#تعریف_کن SPI_SETKEYBOARDCUES 0x100B
#تعریف_کن SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#تعریف_کن SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#تعریف_کن SPI_GETACTIVEWNDTRKZORDER 0x100C
#تعریف_کن SPI_SETACTIVEWNDTRKZORDER 0x100D
#تعریف_کن SPI_GETHOTTRACKING 0x100E
#تعریف_کن SPI_SETHOTTRACKING 0x100F
#تعریف_کن SPI_GETMENUFADE 0x1012
#تعریف_کن SPI_SETMENUFADE 0x1013
#تعریف_کن SPI_GETSELECTIONFADE 0x1014
#تعریف_کن SPI_SETSELECTIONFADE 0x1015
#تعریف_کن SPI_GETTOOLTIPANIMATION 0x1016
#تعریف_کن SPI_SETTOOLTIPANIMATION 0x1017
#تعریف_کن SPI_GETTOOLTIPFADE 0x1018
#تعریف_کن SPI_SETTOOLTIPFADE 0x1019
#تعریف_کن SPI_GETCURSORSHADOW 0x101A
#تعریف_کن SPI_SETCURSORSHADOW 0x101B
#تعریف_کن SPI_GETMOUSESONAR 0x101C
#تعریف_کن SPI_SETMOUSESONAR 0x101D
#تعریف_کن SPI_GETMOUSECLICKLOCK 0x101E
#تعریف_کن SPI_SETMOUSECLICKLOCK 0x101F
#تعریف_کن SPI_GETMOUSEVANISH 0x1020
#تعریف_کن SPI_SETMOUSEVANISH 0x1021
#تعریف_کن SPI_GETFLATMENU 0x1022
#تعریف_کن SPI_SETFLATMENU 0x1023
#تعریف_کن SPI_GETDROPSHADOW 0x1024
#تعریف_کن SPI_SETDROPSHADOW 0x1025
#تعریف_کن SPI_GETBLOCKSENDINPUTRESETS 0x1026
#تعریف_کن SPI_SETBLOCKSENDINPUTRESETS 0x1027
#تعریف_کن SPI_GETUIEFFECTS 0x103E
#تعریف_کن SPI_SETUIEFFECTS 0x103F
#تعریف_کن SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#تعریف_کن SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#تعریف_کن SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#تعریف_کن SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#تعریف_کن SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#تعریف_کن SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#تعریف_کن SPI_GETCARETWIDTH 0x2006
#تعریف_کن SPI_SETCARETWIDTH 0x2007
#تعریف_کن SPI_GETMOUSECLICKLOCKTIME 0x2008
#تعریف_کن SPI_SETMOUSECLICKLOCKTIME 0x2009
#تعریف_کن SPI_GETFONTSMOOTHINGTYPE 0x200A
#تعریف_کن SPI_SETFONTSMOOTHINGTYPE 0x200B

#تعریف_کن FE_FONTSMOOTHINGSTANDARD 0x0001
#تعریف_کن FE_FONTSMOOTHINGCLEARTYPE 0x0002
#تعریف_کن FE_FONTSMOOTHINGDOCKING 0x8000

#تعریف_کن SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#تعریف_کن SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#تعریف_کن SPI_GETFOCUSBORDERWIDTH 0x200E
#تعریف_کن SPI_SETFOCUSBORDERWIDTH 0x200F
#تعریف_کن SPI_GETFOCUSBORDERHEIGHT 0x2010
#تعریف_کن SPI_SETFOCUSBORDERHEIGHT 0x2011
#تعریف_کن SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#تعریف_کن SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#تعریف_کن FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#تعریف_کن FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#تعریف_کن SPIF_UPDATEINIFILE 0x0001
#تعریف_کن SPIF_SENDWININICHANGE 0x0002
#تعریف_کن SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#تعریف_کن METRICS_USEDEFAULT -1
#اگر_تعریف_شده _WINGDI_
#اگر_تعریف_نشده NOGDI
  تعريفنوع بنية برچسب_NONCLIENTMETRICSA {
    UINT cb_اندازه;
    صحيح i_Border_عرض;
    صحيح i_Scroll_عرض;
    صحيح i_Scroll_ارتفاع;
    صحيح i_Caption_عرض;
    صحيح i_Caption_ارتفاع;
    LOGFONTA lfCaptionFont;
    صحيح i_Sm_Caption_عرض;
    صحيح i_Sm_Caption_ارتفاع;
    LOGFONTA lfSmCaptionFont;
    صحيح i_Menu_عرض;
    صحيح i_Menu_ارتفاع;
    LOGFONTA lfMenuFont;
    LOGFONTA lf_وضعیت_Font;
    LOGFONTA lf_پیام_Font;
  } NONCLIENTMETRICSA,*PNONCLIENTMETRICSA,*LPNONCLIENTMETRICSA;

  تعريفنوع بنية برچسب_NONCLIENTMETRICSW {
    UINT cb_اندازه;
    صحيح i_Border_عرض;
    صحيح i_Scroll_عرض;
    صحيح i_Scroll_ارتفاع;
    صحيح i_Caption_عرض;
    صحيح i_Caption_ارتفاع;
    LOGFONTW lfCaptionFont;
    صحيح i_Sm_Caption_عرض;
    صحيح i_Sm_Caption_ارتفاع;
    LOGFONTW lfSmCaptionFont;
    صحيح i_Menu_عرض;
    صحيح i_Menu_ارتفاع;
    LOGFONTW lfMenuFont;
    LOGFONTW lf_وضعیت_Font;
    LOGFONTW lf_پیام_Font;
  } NONCLIENTMETRICSW,*PNONCLIENTMETRICSW,*LPNONCLIENTMETRICSW;

#اگر_تعریف_شده UNICODE
  تعريفنوع NONCLIENTMETRICSW NONCLIENTMETRICS;
  تعريفنوع PNONCLIENTMETRICSW PNONCLIENTMETRICS;
  تعريفنوع LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#وإلا
  تعريفنوع NONCLIENTMETRICSA NONCLIENTMETRICS;
  تعريفنوع PNONCLIENTMETRICSA PNONCLIENTMETRICS;
  تعريفنوع LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#پایان_اگر
#پایان_اگر
#پایان_اگر

#تعریف_کن ARW_BOTTOMLEFT 0x0000L
#تعریف_کن ARW_BOTTOMRIGHT 0x0001L
#تعریف_کن ARW_TOPLEFT 0x0002L
#تعریف_کن ARW_TOPRIGHT 0x0003L
#تعریف_کن ARW_STARTMASK 0x0003L
#تعریف_کن ARW_STARTRIGHT 0x0001L
#تعریف_کن ARW_STARTTOP 0x0002L

#تعریف_کن ARW_چپ 0x0000L
#تعریف_کن ARW_راست 0x0000L
#تعریف_کن ARW_به_بالا 0x0004L
#تعریف_کن ARW_پایین 0x0004L
#تعریف_کن ARW_HIDE 0x0008L

  تعريفنوع بنية برچسب_MINIMIZEDMETRICS {
    UINT cb_اندازه;
    صحيح i_عرض;
    صحيح iHorzGap;
    صحيح iVertGap;
    صحيح iArrange;
  } MINIMIZEDMETRICS,*PMINIMIZEDMETRICS,*LPMINIMIZEDMETRICS;

#اگر_تعریف_شده _WINGDI_
#اگر_تعریف_نشده NOGDI
  تعريفنوع بنية برچسب_ICONMETRICSA {
    UINT cb_اندازه;
    صحيح iHorzSpacing;
    صحيح iVertSpacing;
    صحيح iTitleWrap;
    LOGFONTA lfFont;
  } ICONMETRICSA,*PICONMETRICSA,*LPICONMETRICSA;

  تعريفنوع بنية برچسب_ICONMETRICSW {
    UINT cb_اندازه;
    صحيح iHorzSpacing;
    صحيح iVertSpacing;
    صحيح iTitleWrap;
    LOGFONTW lfFont;
  } ICONMETRICSW,*PICONMETRICSW,*LPICONMETRICSW;

#اگر_تعریف_شده UNICODE
  تعريفنوع ICONMETRICSW ICONMETRICS;
  تعريفنوع PICONMETRICSW PICONMETRICS;
  تعريفنوع LPICONMETRICSW LPICONMETRICS;
#وإلا
  تعريفنوع ICONMETRICSA ICONMETRICS;
  تعريفنوع PICONMETRICSA PICONMETRICS;
  تعريفنوع LPICONMETRICSA LPICONMETRICS;
#پایان_اگر
#پایان_اگر
#پایان_اگر

  تعريفنوع بنية برچسب_ANIMATIONINFO {
    UINT cb_اندازه;
    صحيح iMinAnimate;
  } ANIMATIONINFO,*LPANIMATIONINFO;

  تعريفنوع بنية برچسب_SERIALKEYSA {
    UINT cb_اندازه;
    DWORD dwFlags;
    LPSTR lpsz_فعال_پورت;
    LPSTR lpsz_پورت;
    UINT i_Baud_نرخ;
    UINT i_پورت_State;
    UINT i_فعال;
  } SERIALKEYSA,*LPSERIALKEYSA;

  تعريفنوع بنية برچسب_SERIALKEYSW {
    UINT cb_اندازه;
    DWORD dwFlags;
    LPWSTR lpsz_فعال_پورت;
    LPWSTR lpsz_پورت;
    UINT i_Baud_نرخ;
    UINT i_پورت_State;
    UINT i_فعال;
  } SERIALKEYSW,*LPSERIALKEYSW;

#اگر_تعریف_شده UNICODE
  تعريفنوع SERIALKEYSW SERIALKEYS;
  تعريفنوع LPSERIALKEYSW LPSERIALKEYS;
#وإلا
  تعريفنوع SERIALKEYSA SERIALKEYS;
  تعريفنوع LPSERIALKEYSA LPSERIALKEYS;
#پایان_اگر

#تعریف_کن SERKF_SERIALKEYSON 0x00000001
#تعریف_کن SERKF_موجود 0x00000002
#تعریف_کن SERKF_INDICATOR 0x00000004

  تعريفنوع بنية برچسب_HIGHCONTRASTA {
    UINT cb_اندازه;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
  } HIGHCONTRASTA,*LPHIGHCONTRASTA;

  تعريفنوع بنية برچسب_HIGHCONTRASTW {
    UINT cb_اندازه;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
  } HIGHCONTRASTW,*LPHIGHCONTRASTW;

#اگر_تعریف_شده UNICODE
  تعريفنوع HIGHCONTRASTW HIGHCONTRAST;
  تعريفنوع LPHIGHCONTRASTW LPHIGHCONTRAST;
#وإلا
  تعريفنوع HIGHCONTRASTA HIGHCONTRAST;
  تعريفنوع LPHIGHCONTRASTA LPHIGHCONTRAST;
#پایان_اگر

#تعریف_کن HCF_HIGHCONTRASTON 0x00000001
#تعریف_کن HCF_موجود 0x00000002
#تعریف_کن HCF_HOTKEYACTIVE 0x00000004
#تعریف_کن HCF_CONFIRMHOTKEY 0x00000008
#تعریف_کن HCF_HOTKEYSOUND 0x00000010
#تعریف_کن HCF_INDICATOR 0x00000020
#تعریف_کن HCF_HOTKEYAVAILABLE 0x00000040
#تعریف_کن HCF_LOGONDESKTOP 0x00000100
#تعریف_کن HCF_DEFAULTDESKTOP 0x00000200

#تعریف_کن CDS_UPDATEREGISTRY 0x00000001
#تعریف_کن CDS_TEST 0x00000002
#تعریف_کن CDS_FULLSCREEN 0x00000004
#تعریف_کن CDS_GLOBAL 0x00000008
#تعریف_کن CDS_مجموعه_PRIMARY 0x00000010
#تعریف_کن CDS_VIDEOPARAMETERS 0x00000020
#تعریف_کن CDS_RESET 0x40000000
#تعریف_کن CDS_NORESET 0x10000000

//gr #include <tvout.h>

#تعریف_کن DISP_CHANGE_SUCCESSFUL 0
#تعریف_کن DISP_CHANGE_RESTART 1
#تعریف_کن DISP_CHANGE_FAILED -1
#تعریف_کن DISP_CHANGE_BADMODE -2
#تعریف_کن DISP_CHANGE_NOTUPDATED -3
#تعریف_کن DISP_CHANGE_BADFLAGS -4
#تعریف_کن DISP_CHANGE_BADPARAM -5
#تعریف_کن DISP_CHANGE_BADDUALVIEW -6

#اگر_تعریف_شده _WINGDI_
#اگر_تعریف_نشده NOGDI

#اگر_تعریف_شده UNICODE
#تعریف_کن ChangeDisplaySettings ChangeDisplaySettingsW
#تعریف_کن ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#تعریف_کن EnumDisplaySettings EnumDisplaySettingsW
#تعریف_کن EnumDisplaySettingsEx EnumDisplaySettingsExW
#تعریف_کن EnumDisplayDevices EnumDisplayDevicesW
#وإلا
#تعریف_کن ChangeDisplaySettings ChangeDisplaySettingsA
#تعریف_کن ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#تعریف_کن EnumDisplaySettings EnumDisplaySettingsA
#تعریف_کن EnumDisplaySettingsEx EnumDisplaySettingsExA
#تعریف_کن EnumDisplayDevices EnumDisplayDevicesA
#پایان_اگر

  WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lp_Dev_نما,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsW(LPDEVMODEW lp_Dev_نما,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,LPDEVMODEA lp_Dev_نما,HWND hwnd,DWORD dwflags,LPVOID lParam);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,LPDEVMODEW lp_Dev_نما,HWND hwnd,DWORD dwflags,LPVOID lParam);

#تعریف_کن ENUM_CURRENT_SETTINGS ((DWORD)-1)
#تعریف_کن ENUM_REGISTRY_SETTINGS ((DWORD)-2)

  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD i_نما_رقم,LPDEVMODEA lp_Dev_نما);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD i_نما_رقم,LPDEVMODEW lp_Dev_نما);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD i_نما_رقم,LPDEVMODEA lp_Dev_نما,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD i_نما_رقم,LPDEVMODEW lp_Dev_نما,DWORD dwFlags);

#تعریف_کن EDS_RAWMODE 0x00000002

  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesA(LPCSTR lpDevice,DWORD i_Dev_رقم,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD i_Dev_رقم,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن SystemParametersInfo SystemParametersInfoW
#وإلا
#تعریف_کن SystemParametersInfo SystemParametersInfoA
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
  WINUSERAPI WINBOOL WINAPI SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
#پایان_اگر

  تعريفنوع بنية برچسب_FILTERKEYS {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
  } FILTERKEYS,*LPFILTERKEYS;

#تعریف_کن FKF_FILTERKEYSON 0x00000001
#تعریف_کن FKF_موجود 0x00000002
#تعریف_کن FKF_HOTKEYACTIVE 0x00000004
#تعریف_کن FKF_CONFIRMHOTKEY 0x00000008
#تعریف_کن FKF_HOTKEYSOUND 0x00000010
#تعریف_کن FKF_INDICATOR 0x00000020
#تعریف_کن FKF_CLICKON 0x00000040

  تعريفنوع بنية برچسب_STICKYKEYS {
    UINT cb_اندازه;
    DWORD dwFlags;
  } STICKYKEYS,*LPSTICKYKEYS;

#تعریف_کن SKF_STICKYKEYSON 0x00000001
#تعریف_کن SKF_موجود 0x00000002
#تعریف_کن SKF_HOTKEYACTIVE 0x00000004
#تعریف_کن SKF_CONFIRMHOTKEY 0x00000008
#تعریف_کن SKF_HOTKEYSOUND 0x00000010
#تعریف_کن SKF_INDICATOR 0x00000020
#تعریف_کن SKF_AUDIBLEFEEDBACK 0x00000040
#تعریف_کن SKF_TRISTATE 0x00000080
#تعریف_کن SKF_TWOKEYSOFF 0x00000100
#تعریف_کن SKF_LALTLATCHED 0x10000000
#تعریف_کن SKF_LCTLLATCHED 0x04000000
#تعریف_کن SKF_LSHIFTLATCHED 0x01000000
#تعریف_کن SKF_RALTLATCHED 0x20000000
#تعریف_کن SKF_RCTLLATCHED 0x08000000
#تعریف_کن SKF_RSHIFTLATCHED 0x02000000
#تعریف_کن SKF_LWINLATCHED 0x40000000
#تعریف_کن SKF_RWINLATCHED 0x80000000
#تعریف_کن SKF_LALTLOCKED 0x00100000
#تعریف_کن SKF_LCTLLOCKED 0x00040000
#تعریف_کن SKF_LSHIFTLOCKED 0x00010000
#تعریف_کن SKF_RALTLOCKED 0x00200000
#تعریف_کن SKF_RCTLLOCKED 0x00080000
#تعریف_کن SKF_RSHIFTLOCKED 0x00020000
#تعریف_کن SKF_LWINLOCKED 0x00400000
#تعریف_کن SKF_RWINLOCKED 0x00800000

  تعريفنوع بنية برچسب_MOUSEKEYS {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD i_Max_سرعت;
    DWORD i_زمان_مقصد_Max_سرعت;
    DWORD i_Ctrl_سرعت;
    DWORD dwReserved1;
    DWORD dwReserved2;
  } MOUSEKEYS,*LPMOUSEKEYS;

#تعریف_کن MKF_MOUSEKEYSON 0x00000001
#تعریف_کن MKF_موجود 0x00000002
#تعریف_کن MKF_HOTKEYACTIVE 0x00000004
#تعریف_کن MKF_CONFIRMHOTKEY 0x00000008
#تعریف_کن MKF_HOTKEYSOUND 0x00000010
#تعریف_کن MKF_INDICATOR 0x00000020
#تعریف_کن MKF_MODIFIERS 0x00000040
#تعریف_کن MKF_REPLACENUMBERS 0x00000080
#تعریف_کن MKF_LEFTBUTTONSEL 0x10000000
#تعریف_کن MKF_RIGHTBUTTONSEL 0x20000000
#تعریف_کن MKF_LEFTBUTTONDOWN 0x01000000
#تعریف_کن MKF_RIGHTBUTTONDOWN 0x02000000
#تعریف_کن MKF_MOUSEMODE 0x80000000

  تعريفنوع بنية برچسب_ACCESSTIMEOUT {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD i_زمان_بیرون_MSec;
  } ACCESSTIMEOUT,*LPACCESSTIMEOUT;

#تعریف_کن ATF_TIMEOUTON 0x00000001
#تعریف_کن ATF_ONOFFFEEDBACK 0x00000002

#تعریف_کن SSGF_NONE 0
#تعریف_کن SSGF_DISPLAY 3

#تعریف_کن SSTF_NONE 0
#تعریف_کن SSTF_CHARS 1
#تعریف_کن SSTF_BORDER 2
#تعریف_کن SSTF_DISPLAY 3

#تعریف_کن SSWF_NONE 0
#تعریف_کن SSWF_TITLE 1
#تعریف_کن SSWF_پنجره 2
#تعریف_کن SSWF_DISPLAY 3
#تعریف_کن SSWF_CUSTOM 4

  تعريفنوع بنية برچسب_SOUNDSENTRYA {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_بیتها;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYA,*LPSOUNDSENTRYA;

  تعريفنوع بنية برچسب_SOUNDSENTRYW {
    UINT cb_اندازه;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_بیتها;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYW,*LPSOUNDSENTRYW;

#اگر_تعریف_شده UNICODE
  تعريفنوع SOUNDSENTRYW SOUNDSENTRY;
  تعريفنوع LPSOUNDSENTRYW LPSOUNDSENTRY;
#وإلا
  تعريفنوع SOUNDSENTRYA SOUNDSENTRY;
  تعريفنوع LPSOUNDSENTRYA LPSOUNDSENTRY;
#پایان_اگر

#تعریف_کن SSF_SOUNDSENTRYON 0x00000001
#تعریف_کن SSF_موجود 0x00000002
#تعریف_کن SSF_INDICATOR 0x00000004

  تعريفنوع بنية برچسب_TOGGLEKEYS {
    UINT cb_اندازه;
    DWORD dwFlags;
  } TOGGLEKEYS,*LPTOGGLEKEYS;

#تعریف_کن TKF_TOGGLEKEYSON 0x00000001
#تعریف_کن TKF_موجود 0x00000002
#تعریف_کن TKF_HOTKEYACTIVE 0x00000004
#تعریف_کن TKF_CONFIRMHOTKEY 0x00000008
#تعریف_کن TKF_HOTKEYSOUND 0x00000010
#تعریف_کن TKF_INDICATOR 0x00000020

  WINUSERAPI VOID WINAPI مجموعه_Debug_Error_Level(DWORD dwLevel);

#تعریف_کن SLE_ERROR 0x00000001
#تعریف_کن SLE_MINORERROR 0x00000002
#تعریف_کن SLE_WARNING 0x00000003

  WINUSERAPI VOID WINAPI مجموعه_آخرین_Error_Ex(DWORD dw_Err_کد,DWORD dwType);
  WINUSERAPI صحيح WINAPI داخلی_Get_پنجره_متن(HWND hWnd,LPWSTR pString,صحيح cch_Max_شمار);

#اگر_تعریف_شده WINNT
  WINUSERAPI WINBOOL WINAPI انتها_Task(HWND hWnd,WINBOOL f_Shut_پایین,WINBOOL fForce);
#پایان_اگر

#تعریف_کن MONITOR_DEFAULTTONULL 0x00000000
#تعریف_کن MONITOR_DEFAULTTOPRIMARY 0x00000001
#تعریف_کن MONITOR_DEFAULTTONEAREST 0x00000002

  WINUSERAPI HMONITOR WINAPI Monitor_From_نقطه(نقطه_3 pt,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromRect(LPCRECT lprc,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI Monitor_From_پنجره(HWND hwnd,DWORD dwFlags);

#تعریف_کن MONITORINFOF_PRIMARY 0x00000001

#اگر_تعریف_نشده CCHDEVICENAME
#تعریف_کن CCHDEVICENAME 32
#پایان_اگر

  تعريفنوع بنية برچسب_MONITORINFO {
    DWORD cb_اندازه;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
  } MONITORINFO,*LPMONITORINFO;

#اگر_تعریف_شده __cplusplus
  تعريفنوع بنية برچسب_MONITORINFOEXA : عام برچسب_MONITORINFO {
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  تعريفنوع بنية برچسب_MONITORINFOEXW : عام برچسب_MONITORINFO {
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;

#اگر_تعریف_شده UNICODE
  تعريفنوع MONITORINFOEXW MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXW LPMONITORINFOEX;
#وإلا
  تعريفنوع MONITORINFOEXA MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXA LPMONITORINFOEX;
#پایان_اگر
#وإلا
  تعريفنوع بنية برچسب_MONITORINFOEXA {
    MONITORINFO mi;
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  تعريفنوع بنية برچسب_MONITORINFOEXW {
    MONITORINFO mi;
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;
#اگر_تعریف_شده UNICODE
  تعريفنوع MONITORINFOEXW MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXW LPMONITORINFOEX;
#وإلا
  تعريفنوع MONITORINFOEXA MONITORINFOEX;
  تعريفنوع LPMONITORINFOEXA LPMONITORINFOEX;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده UNICODE 
#تعریف_کن GetMonitorInfo GetMonitorInfoW
#وإلا
#تعریف_کن GetMonitorInfo GetMonitorInfoA
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
  WINUSERAPI WINBOOL WINAPI GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);

  تعريفنوع WINBOOL (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

  WINUSERAPI WINBOOL WINAPI EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dw_داده);

#اگر_تعریف_نشده NOWINABLE
  WINUSERAPI VOID WINAPI NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG id_فرزند);

  تعريفنوع VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK hWinEventHook,DWORD event,HWND hwnd,LONG idObject,LONG id_فرزند,DWORD idEventThread,DWORD dwms_Event_زمان);

  WINUSERAPI HWINEVENTHOOK WINAPI مجموعه_Win_Event_Hook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI IsWinEventHookInstalled(DWORD event);

#تعریف_کن WINEVENT_OUTOFCONTEXT 0x0000
#تعریف_کن WINEVENT_SKIPOWNTHREAD 0x0001
#تعریف_کن WINEVENT_SKIPOWNPROCESS 0x0002
#تعریف_کن WINEVENT_INCONTEXT 0x0004

  WINUSERAPI WINBOOL WINAPI UnhookWinEvent(HWINEVENTHOOK hWinEventHook);

#تعریف_کن CHILDID_SELF 0
#تعریف_کن INDEXID_OBJECT 0
#تعریف_کن INDEXID_CONTAINER 0

#تعریف_کن OBJID_پنجره ((LONG)0x00000000)
#تعریف_کن OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#تعریف_کن OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#تعریف_کن OBJID_MENU ((LONG)0xFFFFFFFD)
#تعریف_کن OBJID_CLIENT ((LONG)0xFFFFFFFC)
#تعریف_کن OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#تعریف_کن OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#تعریف_کن OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#تعریف_کن OBJID_CARET ((LONG)0xFFFFFFF8)
#تعریف_کن OBJID_CURSOR ((LONG)0xFFFFFFF7)
#تعریف_کن OBJID_ALERT ((LONG)0xFFFFFFF6)
#تعریف_کن OBJID_SOUND ((LONG)0xFFFFFFF5)
#تعریف_کن OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#تعریف_کن OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#تعریف_کن EVENT_MIN 0x00000001
#تعریف_کن EVENT_MAX 0x7FFFFFFF

#تعریف_کن EVENT_SYSTEM_SOUND 0x0001
#تعریف_کن EVENT_SYSTEM_ALERT 0x0002
#تعریف_کن EVENT_SYSTEM_FOREGROUND 0x0003
#تعریف_کن EVENT_SYSTEM_MENUSTART 0x0004
#تعریف_کن EVENT_SYSTEM_MENUEND 0x0005
#تعریف_کن EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#تعریف_کن EVENT_SYSTEM_MENUPOPUPEND 0x0007
#تعریف_کن EVENT_SYSTEM_CAPTURESTART 0x0008
#تعریف_کن EVENT_SYSTEM_CAPTUREEND 0x0009
#تعریف_کن EVENT_SYSTEM_MOVESIZESTART 0x000A
#تعریف_کن EVENT_SYSTEM_MOVESIZEEND 0x000B
#تعریف_کن EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#تعریف_کن EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#تعریف_کن EVENT_SYSTEM_DRAGDROPSTART 0x000E
#تعریف_کن EVENT_SYSTEM_DRAGDROPEND 0x000F
#تعریف_کن EVENT_SYSTEM_DIALOGSTART 0x0010
#تعریف_کن EVENT_SYSTEM_DIALOGEND 0x0011
#تعریف_کن EVENT_SYSTEM_SCROLLINGSTART 0x0012
#تعریف_کن EVENT_SYSTEM_SCROLLINGEND 0x0013
#تعریف_کن EVENT_SYSTEM_SWITCHSTART 0x0014
#تعریف_کن EVENT_SYSTEM_SWITCHEND 0x0015
#تعریف_کن EVENT_SYSTEM_MINIMIZESTART 0x0016
#تعریف_کن EVENT_SYSTEM_MINIMIZEEND 0x0017

#تعریف_کن EVENT_CONSOLE_CARET 0x4001
#تعریف_کن EVENT_CONSOLE_UPDATE_REGION 0x4002
#تعریف_کن EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#تعریف_کن EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#تعریف_کن EVENT_CONSOLE_LAYOUT 0x4005
#تعریف_کن EVENT_CONSOLE_شروع_APPLICATION 0x4006
#تعریف_کن EVENT_CONSOLE_انتها_APPLICATION 0x4007

#تعریف_کن CONSOLE_APPLICATION_16_بیت 0x0001

#تعریف_کن CONSOLE_CARET_SELECTION 0x0001
#تعریف_کن CONSOLE_CARET_VISIBLE 0x0002

#تعریف_کن EVENT_OBJECT_CREATE 0x8000
#تعریف_کن EVENT_OBJECT_DESTROY 0x8001
#تعریف_کن EVENT_OBJECT_SHOW 0x8002
#تعریف_کن EVENT_OBJECT_HIDE 0x8003
#تعریف_کن EVENT_OBJECT_REORDER 0x8004

#تعریف_کن EVENT_OBJECT_FOCUS 0x8005
#تعریف_کن EVENT_OBJECT_SELECTION 0x8006
#تعریف_کن EVENT_OBJECT_SELECTIONADD 0x8007
#تعریف_کن EVENT_OBJECT_SELECTIONREMOVE 0x8008
#تعریف_کن EVENT_OBJECT_SELECTIONWITHIN 0x8009

#تعریف_کن EVENT_OBJECT_STATECHANGE 0x800A

#تعریف_کن EVENT_OBJECT_LOCATIONCHANGE 0x800B

#تعریف_کن EVENT_OBJECT_NAMECHANGE 0x800C
#تعریف_کن EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#تعریف_کن EVENT_OBJECT_VALUECHANGE 0x800E
#تعریف_کن EVENT_OBJECT_PARENTCHANGE 0x800F
#تعریف_کن EVENT_OBJECT_HELPCHANGE 0x8010
#تعریف_کن EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#تعریف_کن EVENT_OBJECT_ACCELERATORCHANGE 0x8012

#تعریف_کن SOUND_SYSTEM_STARTUP 1
#تعریف_کن SOUND_SYSTEM_SHUTDOWN 2
#تعریف_کن SOUND_SYSTEM_BEEP 3
#تعریف_کن SOUND_SYSTEM_ERROR 4
#تعریف_کن SOUND_SYSTEM_QUESTION 5
#تعریف_کن SOUND_SYSTEM_WARNING 6
#تعریف_کن SOUND_SYSTEM_INFORMATION 7
#تعریف_کن SOUND_SYSTEM_MAXIMIZE 8
#تعریف_کن SOUND_SYSTEM_MINIMIZE 9
#تعریف_کن SOUND_SYSTEM_RESTOREUP 10
#تعریف_کن SOUND_SYSTEM_RESTOREDOWN 11
#تعریف_کن SOUND_SYSTEM_APPSTART 12
#تعریف_کن SOUND_SYSTEM_FAULT 13
#تعریف_کن SOUND_SYSTEM_APPEND 14
#تعریف_کن SOUND_SYSTEM_MENUCOMMAND 15
#تعریف_کن SOUND_SYSTEM_MENUPOPUP 16
#تعریف_کن CSOUND_SYSTEM 16

#تعریف_کن ALERT_SYSTEM_INFORMATIONAL 1
#تعریف_کن ALERT_SYSTEM_WARNING 2
#تعریف_کن ALERT_SYSTEM_ERROR 3
#تعریف_کن ALERT_SYSTEM_QUERY 4
#تعریف_کن ALERT_SYSTEM_CRITICAL 5
#تعریف_کن CALERT_SYSTEM 6

  تعريفنوع بنية برچسب_GUITHREADINFO {
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

#تعریف_کن GUI_CARETBLINKING 0x00000001
#تعریف_کن GUI_INMOVESIZE 0x00000002
#تعریف_کن GUI_INMENUMODE 0x00000004
#تعریف_کن GUI_SYSTEMMENUMODE 0x00000008
#تعریف_کن GUI_POPUPMENUMODE 0x00000010
#تعریف_کن GUI_16BITTASK 0x00000020

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_پنجره_Module_File_Name Get_پنجره_Module_File_Name_W
#وإلا
#تعریف_کن Get_پنجره_Module_File_Name Get_پنجره_Module_File_Name_A
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui);
  WINUSERAPI UINT WINAPI Get_پنجره_Module_File_Name_A(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
  WINUSERAPI UINT WINAPI Get_پنجره_Module_File_Name_W(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);

#اگر_تعریف_نشده NO_STATE_FLAGS
#تعریف_کن STATE_SYSTEM_UNAVAILABLE 0x00000001
#تعریف_کن STATE_SYSTEM_SELECTED 0x00000002
#تعریف_کن STATE_SYSTEM_FOCUSED 0x00000004
#تعریف_کن STATE_SYSTEM_PRESSED 0x00000008
#تعریف_کن STATE_SYSTEM_CHECKED 0x00000010
#تعریف_کن STATE_SYSTEM_MIXED 0x00000020
#تعریف_کن STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#تعریف_کن STATE_SYSTEM_READONLY 0x00000040
#تعریف_کن STATE_SYSTEM_HOTTRACKED 0x00000080
#تعریف_کن STATE_SYSTEM_DEFAULT 0x00000100
#تعریف_کن STATE_SYSTEM_EXPANDED 0x00000200
#تعریف_کن STATE_SYSTEM_COLLAPSED 0x00000400
#تعریف_کن STATE_SYSTEM_BUSY 0x00000800
#تعریف_کن STATE_SYSTEM_FLOATING 0x00001000
#تعریف_کن STATE_SYSTEM_MARQUEED 0x00002000
#تعریف_کن STATE_SYSTEM_ANIMATED 0x00004000
#تعریف_کن STATE_SYSTEM_INVISIBLE 0x00008000
#تعریف_کن STATE_SYSTEM_OFFSCREEN 0x00010000
#تعریف_کن STATE_SYSTEM_SIZEABLE 0x00020000
#تعریف_کن STATE_SYSTEM_MOVEABLE 0x00040000
#تعریف_کن STATE_SYSTEM_SELFVOICING 0x00080000
#تعریف_کن STATE_SYSTEM_FOCUSABLE 0x00100000
#تعریف_کن STATE_SYSTEM_SELECTABLE 0x00200000
#تعریف_کن STATE_SYSTEM_LINKED 0x00400000
#تعریف_کن STATE_SYSTEM_TRAVERSED 0x00800000
#تعریف_کن STATE_SYSTEM_MULTISELECTABLE 0x01000000
#تعریف_کن STATE_SYSTEM_EXTSELECTABLE 0x02000000
#تعریف_کن STATE_SYSTEM_ALERT_کم 0x04000000
#تعریف_کن STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#تعریف_کن STATE_SYSTEM_ALERT_بالا 0x10000000
#تعریف_کن STATE_SYSTEM_PROTECTED 0x20000000
#تعریف_کن STATE_SYSTEM_VALID 0x3FFFFFFF
#پایان_اگر

#تعریف_کن CCHILDREN_TITLEBAR 5
#تعریف_کن CCHILDREN_SCROLLBAR 5

  تعريفنوع بنية برچسب_CURSORINFO {
    DWORD cb_اندازه;
    DWORD flags;
    HCURSOR hCursor;
    نقطه_3 ptScreenPos;
  } CURSORINFO,*PCURSORINFO,*LPCURSORINFO;

#تعریف_کن CURSOR_SHOWING 0x00000001

  WINUSERAPI WINBOOL WINAPI GetCursorInfo(PCURSORINFO pci);

  تعريفنوع بنية برچسب_WINDOWINFO {
    DWORD cb_اندازه;
    RECT rc_پنجره;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dw_پنجره_وضعیت;
    UINT cx_پنجره_Borders;
    UINT cy_پنجره_Borders;
    ATOM atom_پنجره_Type;
    کلمه_3 w_Creator_نسخه;
  } WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;

#تعریف_کن WS_ACTIVECAPTION 0x0001

  WINUSERAPI WINBOOL WINAPI Get_پنجره_Info(HWND hwnd,PWINDOWINFO pwi);

  تعريفنوع بنية برچسب_TITLEBARINFO {
    DWORD cb_اندازه;
    RECT rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  } TITLEBARINFO,*PTITLEBARINFO,*LPTITLEBARINFO;

  WINUSERAPI WINBOOL WINAPI GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti);

  تعريفنوع بنية برچسب_MENUBARINFO {
    DWORD cb_اندازه;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    WINBOOL fBarFocused:1;
    WINBOOL fFocused:1;
  } MENUBARINFO,*PMENUBARINFO,*LPMENUBARINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuBarInfo(HWND hwnd,LONG idObject,LONG id_قلم,PMENUBARINFO pmbi);

  تعريفنوع بنية برچسب_SCROLLBARINFO {
    DWORD cb_اندازه;
    RECT rcScrollBar;
    صحيح dxy_سطر_Button;
    صحيح xy_Thumb_بالاترین;
    صحيح xyThumbBottom;
    صحيح reserved;
    DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
  } SCROLLBARINFO,*PSCROLLBARINFO,*LPSCROLLBARINFO;

  WINUSERAPI WINBOOL WINAPI GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);

  تعريفنوع بنية برچسب_COMBOBOXINFO {
    DWORD cb_اندازه;
    RECT rc_قلم;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwnd_قلم;
    HWND hwndList;
  } COMBOBOXINFO,*PCOMBOBOXINFO,*LPCOMBOBOXINFO;

  WINUSERAPI WINBOOL WINAPI GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi);

#تعریف_کن GA_والد 1
#تعریف_کن GA_ریشه 2
#تعریف_کن GA_ROOTOWNER 3

  WINUSERAPI HWND WINAPI GetAncestor(HWND hwnd,UINT gaFlags);
  WINUSERAPI HWND WINAPI Real_فرزند_پنجره_From_نقطه(HWND hwnd_والد_2,نقطه_3 pt_والد_Client_Coords);
  WINUSERAPI UINT WINAPI Real_Get_پنجره_Class_A(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
  WINUSERAPI UINT WINAPI Real_Get_پنجره_Class_W(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
#اگر_تعریف_شده UNICODE
#تعریف_کن Real_Get_پنجره_Class Real_Get_پنجره_Class_W
#وإلا
#تعریف_کن Real_Get_پنجره_Class Real_Get_پنجره_Class_A
#پایان_اگر

  تعريفنوع بنية برچسب_ALTTABINFO {
    DWORD cb_اندازه;
    صحيح c_اقلام;
    صحيح cColumns;
    صحيح c_ردیفها;
    صحيح i_ستون_Focus;
    صحيح i_ردیف_Focus;
    صحيح cx_قلم;
    صحيح cy_قلم;
    نقطه_3 pt_شروع;
  } ALTTABINFO,*PALTTABINFO,*LPALTTABINFO;

#اگر_تعریف_شده UNICODE
#تعریف_کن GetAltTabInfo GetAltTabInfoW
#وإلا
#تعریف_کن GetAltTabInfo GetAltTabInfoA
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI GetAltTabInfoA(HWND hwnd,صحيح i_قلم,PALTTABINFO pati,LPSTR psz_قلم_متن,UINT cch_قلم_متن);
  WINUSERAPI WINBOOL WINAPI GetAltTabInfoW(HWND hwnd,صحيح i_قلم,PALTTABINFO pati,LPWSTR psz_قلم_متن,UINT cch_قلم_متن);
  WINUSERAPI DWORD WINAPI GetListBoxInfo(HWND hwnd);
#پایان_اگر

  WINUSERAPI WINBOOL WINAPI قفل_Work_Station(VOID);
  WINUSERAPI WINBOOL WINAPI UserHandleGrantAccess(HANDLE hUserHandle,HANDLE h_کار,WINBOOL bGrant);

  DECLARE_HANDLE(HRAWINPUT);

#تعریف_کن GET_RAWINPUT_کد_WPARAM(wParam) ((wParam) & 0xff)

#تعریف_کن RIM_درون_داد 0
#تعریف_کن RIM_INPUTSINK 1

  تعريفنوع بنية برچسب_RAWINPUTHEADER {
    DWORD dwType;
    DWORD dw_اندازه;
    HANDLE hDevice;
    WPARAM wParam;
  } RAWINPUTHEADER,*PRAWINPUTHEADER,*LPRAWINPUTHEADER;

#تعریف_کن RIM_TYPEMOUSE 0
#تعریف_کن RIM_TYPEKEYBOARD 1
#تعریف_کن RIM_TYPEHID 2

  تعريفنوع بنية برچسب_RAWMOUSE {
    USHORT usFlags;
    اتحاد {
      ULONG ulButtons;
      بنية {
	USHORT usButtonFlags;
	USHORT us_Button_داده;
      };
    };
    ULONG ulRawButtons;
    LONG l_آخرین_X;
    LONG l_آخرین_Y;
    ULONG ulExtraInformation;
  } RAWMOUSE,*PRAWMOUSE,*LPRAWMOUSE;

#تعریف_کن RI_MOUSE_چپ_BUTTON_پایین 0x0001
#تعریف_کن RI_MOUSE_چپ_BUTTON_به_بالا 0x0002
#تعریف_کن RI_MOUSE_راست_BUTTON_پایین 0x0004
#تعریف_کن RI_MOUSE_راست_BUTTON_به_بالا 0x0008
#تعریف_کن RI_MOUSE_میانه_BUTTON_پایین 0x0010
#تعریف_کن RI_MOUSE_میانه_BUTTON_به_بالا 0x0020

#تعریف_کن RI_MOUSE_BUTTON_1_پایین RI_MOUSE_چپ_BUTTON_پایین
#تعریف_کن RI_MOUSE_BUTTON_1_به_بالا RI_MOUSE_چپ_BUTTON_به_بالا
#تعریف_کن RI_MOUSE_BUTTON_2_پایین RI_MOUSE_راست_BUTTON_پایین
#تعریف_کن RI_MOUSE_BUTTON_2_به_بالا RI_MOUSE_راست_BUTTON_به_بالا
#تعریف_کن RI_MOUSE_BUTTON_3_پایین RI_MOUSE_میانه_BUTTON_پایین
#تعریف_کن RI_MOUSE_BUTTON_3_به_بالا RI_MOUSE_میانه_BUTTON_به_بالا

#تعریف_کن RI_MOUSE_BUTTON_4_پایین 0x0040
#تعریف_کن RI_MOUSE_BUTTON_4_به_بالا 0x0080
#تعریف_کن RI_MOUSE_BUTTON_5_پایین 0x0100
#تعریف_کن RI_MOUSE_BUTTON_5_به_بالا 0x0200

#تعریف_کن RI_MOUSE_WHEEL 0x0400

#تعریف_کن MOUSE_MOVE_RELATIVE 0
#تعریف_کن MOUSE_MOVE_ABSOLUTE 1
#تعریف_کن MOUSE_VIRTUAL_DESKTOP 0x02
#تعریف_کن MOUSE_صفات_تغییریافته 0x04

  تعريفنوع بنية برچسب_RAWKEYBOARD {
    USHORT Make_کد;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT پیام_6;
    ULONG ExtraInformation;
  } RAWKEYBOARD,*PRAWKEYBOARD,*LPRAWKEYBOARD;

#تعریف_کن KEYBOARD_OVERRUN_MAKE_کد 0xFF

#تعریف_کن RI_کلید_MAKE 0
#تعریف_کن RI_کلید_BREAK 1
#تعریف_کن RI_کلید_E0 2
#تعریف_کن RI_کلید_E1 4
#تعریف_کن RI_کلید_TERMSRV_مجموعه_LED 8
#تعریف_کن RI_کلید_TERMSRV_SHADOW 0x10

  تعريفنوع بنية برچسب_RAWHID {
    DWORD dw_اندازه_Hid;
    DWORD dw_شمار;
    BYTE b_Raw_داده[1];
  } RAWHID,*PRAWHID,*LPRAWHID;

  تعريفنوع بنية برچسب_RAWINPUT {
    RAWINPUTHEADER سرآیند;
    اتحاد {
      RAWMOUSE mouse;
      RAWKEYBOARD keyboard;
      RAWHID hid;
    } داده;
  } RAWINPUT,*PRAWINPUT,*LPRAWINPUT;

#اگر_تعریف_شده _WIN64
#تعریف_کن RAWINPUT_ALIGN(x) (((x) + حجم(QWORD) - 1) & ~(حجم(QWORD) - 1))
#وإلا
#تعریف_کن RAWINPUT_ALIGN(x) (((x) + حجم(DWORD) - 1) & ~(حجم(DWORD) - 1))
#پایان_اگر

#تعریف_کن NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->سرآیند.dw_اندازه)))

#تعریف_کن RID_درون_داد 0x10000003
#تعریف_کن RID_سرآیند 0x10000005

  WINUSERAPI UINT WINAPI Get_Raw_درون_داد_داده(HRAWINPUT h_Raw_درون_داد,UINT uiCommand,LPVOID p_داده,PUINT pcb_اندازه,UINT cb_اندازه_سرآیند);

#تعریف_کن RIDI_PREPARSEDDATA 0x20000005
#تعریف_کن RIDI_DEVICENAME 0x20000007
#تعریف_کن RIDI_DEVICEINFO 0x2000000b

  تعريفنوع بنية برچسب_RID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dw_عدد_از_Buttons;
    DWORD dw_Sample_نرخ;
  } RID_DEVICE_INFO_MOUSE,*PRID_DEVICE_INFO_MOUSE;

  تعريفنوع بنية برچسب_RID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dw_Keyboard_نما;
    DWORD dw_عدد_از_Function_کلیدها;
    DWORD dw_عدد_از_Indicators;
    DWORD dw_عدد_از_کلیدها_مجموع;
  } RID_DEVICE_INFO_KEYBOARD,*PRID_DEVICE_INFO_KEYBOARD;

  تعريفنوع بنية برچسب_RID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dw_حاصلضرب_Id;
    DWORD dw_نسخه_عدد;
    USHORT us_Usage_صفحه;
    USHORT usUsage;
  } RID_DEVICE_INFO_HID,*PRID_DEVICE_INFO_HID;

  تعريفنوع بنية برچسب_RID_DEVICE_INFO {
    DWORD cb_اندازه;
    DWORD dwType;
    اتحاد {
      RID_DEVICE_INFO_MOUSE mouse;
      RID_DEVICE_INFO_KEYBOARD keyboard;
      RID_DEVICE_INFO_HID hid;
    };
  } RID_DEVICE_INFO,*PRID_DEVICE_INFO,*LPRID_DEVICE_INFO;

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_Raw_درون_داد_Device_Info Get_Raw_درون_داد_Device_Info_W
#وإلا
#تعریف_کن Get_Raw_درون_داد_Device_Info Get_Raw_درون_داد_Device_Info_A
#پایان_اگر

  WINUSERAPI UINT WINAPI Get_Raw_درون_داد_Device_Info_A(HANDLE hDevice,UINT uiCommand,LPVOID p_داده,PUINT pcb_اندازه);
  WINUSERAPI UINT WINAPI Get_Raw_درون_داد_Device_Info_W(HANDLE hDevice,UINT uiCommand,LPVOID p_داده,PUINT pcb_اندازه);
  WINUSERAPI UINT WINAPI Get_Raw_درون_داد_میانگیر(PRAWINPUT p_داده,PUINT pcb_اندازه,UINT cb_اندازه_سرآیند);

  تعريفنوع بنية برچسب_RAWINPUTDEVICE {
    USHORT us_Usage_صفحه;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwnd_هدف;
  } RAWINPUTDEVICE,*PRAWINPUTDEVICE,*LPRAWINPUTDEVICE;

  تعريفنوع CONST RAWINPUTDEVICE *PCRAWINPUTDEVICE;

#تعریف_کن RIDEV_REMOVE 0x00000001
#تعریف_کن RIDEV_EXCLUDE 0x00000010
#تعریف_کن RIDEV_PAGEONLY 0x00000020
#تعریف_کن RIDEV_NOLEGACY 0x00000030
#تعریف_کن RIDEV_INPUTSINK 0x00000100
#تعریف_کن RIDEV_CAPTUREMOUSE 0x00000200
#تعریف_کن RIDEV_NOHOTKEYS 0x00000200
#تعریف_کن RIDEV_APPKEYS 0x00000400
#تعریف_کن RIDEV_EXMODEMASK 0x000000F0
#تعریف_کن RIDEV_EXMODE(نما) ((نما) & RIDEV_EXMODEMASK)

  WINUSERAPI WINBOOL WINAPI ثبات_Raw_درون_داد_Devices(PCRAWINPUTDEVICE p_Raw_درون_داد_Devices,UINT ui_رقم_Devices,UINT cb_اندازه);
  WINUSERAPI UINT WINAPI Get_Registered_Raw_درون_داد_Devices(PRAWINPUTDEVICE p_Raw_درون_داد_Devices,PUINT pui_رقم_Devices,UINT cb_اندازه);

  تعريفنوع بنية برچسب_RAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
  } RAWINPUTDEVICELIST,*PRAWINPUTDEVICELIST;

  WINUSERAPI UINT WINAPI Get_Raw_درون_داد_Device_List(PRAWINPUTDEVICELIST p_Raw_درون_داد_Device_List,PUINT pui_رقم_Devices,UINT cb_اندازه);
  WINUSERAPI LRESULT WINAPI Def_Raw_درون_داد_Proc(PRAWINPUT *pa_Raw_درون_داد,INT n_درون_داد,UINT cb_اندازه_سرآیند);

#پایان_اگر /* NOUSER */

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
