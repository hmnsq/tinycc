/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _WINUSER_
#परिभाषय _WINUSER_

#परिभाषय WINUSERAPI DECLSPEC_IMPORT

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् WINVER
#परिभाषय WINVER 0x0502
#यदि_अन्तः

#अन्तर्भाव <stdarg.h>

#यदि_अपरिभाषितम् NOUSER
  प्रकारनिर्देश HANDLE HDWP;
  प्रकारनिर्देश VOID MENUTEMPLATEA;
  प्रकारनिर्देश VOID MENUTEMPLATEW;
  प्रकारनिर्देश PVOID LPMENUTEMPLATEA;
  प्रकारनिर्देश PVOID LPMENUTEMPLATEW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश MENUTEMPLATEW MENUTEMPLATE;
  प्रकारनिर्देश LPMENUTEMPLATEW LPMENUTEMPLATE;
#अन्यथा
  प्रकारनिर्देश MENUTEMPLATEA MENUTEMPLATE;
  प्रकारनिर्देश LPMENUTEMPLATEA LPMENUTEMPLATE;
#यदि_अन्तः

  प्रकारनिर्देश LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
  प्रकारनिर्देश INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
  प्रकारनिर्देश VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
  प्रकारनिर्देश WINBOOL (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,पूर्णाङ्क);
  प्रकारनिर्देश WINBOOL (CALLBACK *WNDENUMPROC)(HWND,LPARAM);
  प्रकारनिर्देश LRESULT (CALLBACK *HOOKPROC)(पूर्णाङ्क संहिता,WPARAM wParam,LPARAM lParam);
  प्रकारनिर्देश VOID (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
  प्रकारनिर्देश WINBOOL (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
  प्रकारनिर्देश WINBOOL (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
  प्रकारनिर्देश WINBOOL (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
  प्रकारनिर्देश WINBOOL (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch,पूर्णाङ्क ichCurrent,पूर्णाङ्क cch,पूर्णाङ्क संहिता);
  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch,पूर्णाङ्क ichCurrent,पूर्णाङ्क cch,पूर्णाङ्क संहिता);
  प्रकारनिर्देश WINBOOL (CALLBACK *DRAWSTATEPROC)(HDC hdc,LPARAM l_दत्त,WPARAM w_दत्त,पूर्णाङ्क cx,पूर्णाङ्क cy);

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश PROPENUMPROCW PROPENUMPROC;
  प्रकारनिर्देश PROPENUMPROCEXW PROPENUMPROCEX;
  प्रकारनिर्देश EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#अन्यथा
  प्रकारनिर्देश PROPENUMPROCA PROPENUMPROC;
  प्रकारनिर्देश PROPENUMPROCEXA PROPENUMPROCEX;
  प्रकारनिर्देश EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#यदि_अन्तः

  प्रकारनिर्देश WINBOOL (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
  प्रकारनिर्देश WINBOOL (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
  प्रकारनिर्देश NAMEENUMPROCA WINSTAENUMPROCA;
  प्रकारनिर्देश NAMEENUMPROCA DESKTOPENUMPROCA;
  प्रकारनिर्देश NAMEENUMPROCW WINSTAENUMPROCW;
  प्रकारनिर्देश NAMEENUMPROCW DESKTOPENUMPROCW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WINSTAENUMPROCW WINSTAENUMPROC;
  प्रकारनिर्देश DESKTOPENUMPROCW DESKTOPENUMPROC;
#अन्यथा
  प्रकारनिर्देश WINSTAENUMPROCA WINSTAENUMPROC;
  प्रकारनिर्देश DESKTOPENUMPROCA DESKTOPENUMPROC;
#यदि_अन्तः

#परिभाषय IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)
#परिभाषय MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
#परिभाषय MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((WORD)(i))))
#यदि_परिभाषितम् UNICODE
#परिभाषय MAKEINTRESOURCE MAKEINTRESOURCEW
#अन्यथा
#परिभाषय MAKEINTRESOURCE MAKEINTRESOURCEA
#यदि_अन्तः

#यदि_अपरिभाषितम् NORESOURCE

#परिभाषय RT_CURSOR MAKEINTRESOURCE(1)
#परिभाषय RT_BITMAP MAKEINTRESOURCE(2)
#परिभाषय RT_ICON MAKEINTRESOURCE(3)
#परिभाषय RT_MENU MAKEINTRESOURCE(4)
#परिभाषय RT_DIALOG MAKEINTRESOURCE(5)
#परिभाषय RT_STRING MAKEINTRESOURCE(6)
#परिभाषय RT_FONTDIR MAKEINTRESOURCE(7)
#परिभाषय RT_FONT MAKEINTRESOURCE(8)
#परिभाषय RT_ACCELERATOR MAKEINTRESOURCE(9)
#परिभाषय RT_RCDATA MAKEINTRESOURCE(10)
#परिभाषय RT_MESSAGETABLE MAKEINTRESOURCE(11)

#परिभाषय DIFFERENCE 11
#परिभाषय RT_गणः_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
#परिभाषय RT_गणः_ICON MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
#परिभाषय RT_संस्करणम् MAKEINTRESOURCE(16)
#परिभाषय RT_DLGINCLUDE MAKEINTRESOURCE(17)
#परिभाषय RT_PLUGPLAY MAKEINTRESOURCE(19)
#परिभाषय RT_VXD MAKEINTRESOURCE(20)
#परिभाषय RT_ANICURSOR MAKEINTRESOURCE(21)
#परिभाषय RT_ANIICON MAKEINTRESOURCE(22)
#परिभाषय RT_HTML MAKEINTRESOURCE(23)
#यदि_परिभाषितम् RC_INVOKED
#परिभाषय RT_MANIFEST 24
#परिभाषय CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#परिभाषय ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#परिभाषय ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#परिभाषय MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#परिभाषय अधिकतमम्_RESERVED_MANIFEST_RESOURCE_ID 16
#अन्यथा
#परिभाषय RT_MANIFEST MAKEINTRESOURCE(24)
#परिभाषय CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#परिभाषय ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#परिभाषय ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#परिभाषय MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#परिभाषय अधिकतमम्_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय wvsprintf wvsprintfW
#परिभाषय wsprintf wsprintfW
#अन्यथा
#परिभाषय wvsprintf wvsprintfA
#परिभाषय wsprintf wsprintfA
#यदि_अन्तः

  WINUSERAPI पूर्णाङ्क WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
  WINUSERAPI पूर्णाङ्क WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);
  WINUSERAPI पूर्णाङ्क WINAPIV wsprintfA(LPSTR,LPCSTR,...);
  WINUSERAPI पूर्णाङ्क WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);

#परिभाषय SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#यदि_अपरिभाषितम् NOSCROLL
#परिभाषय SB_HORZ 0
#परिभाषय SB_VERT 1
#परिभाषय SB_CTL 2
#परिभाषय SB_BOTH 3

#परिभाषय SB_LINEUP 0
#परिभाषय SB_LINELEFT 0
#परिभाषय SB_LINEDOWN 1
#परिभाषय SB_LINERIGHT 1
#परिभाषय SB_PAGEUP 2
#परिभाषय SB_PAGELEFT 2
#परिभाषय SB_PAGEDOWN 3
#परिभाषय SB_PAGERIGHT 3
#परिभाषय SB_THUMBPOSITION 4
#परिभाषय SB_THUMBTRACK 5
#परिभाषय SB_शिखरम् 6
#परिभाषय SB_वामः 6
#परिभाषय SB_BOTTOM 7
#परिभाषय SB_दक्षिणः 7
#परिभाषय SB_ENDSCROLL 8
#यदि_अन्तः

#यदि_अपरिभाषितम् NOSHOWWINDOW
#परिभाषय SW_HIDE 0
#परिभाषय SW_SHOWNORMAL 1
#परिभाषय SW_प्रसामान्यम् 1
#परिभाषय SW_SHOWMINIMIZED 2
#परिभाषय SW_SHOWMAXIMIZED 3
#परिभाषय SW_MAXIMIZE 3
#परिभाषय SW_SHOWNOACTIVATE 4
#परिभाषय SW_SHOW 5
#परिभाषय SW_MINIMIZE 6
#परिभाषय SW_SHOWMINNOACTIVE 7
#परिभाषय SW_SHOWNA 8
#परिभाषय SW_RESTORE 9
#परिभाषय SW_SHOWDEFAULT 10
#परिभाषय SW_FORCEMINIMIZE 11
#परिभाषय SW_MAX 11

#परिभाषय HIDE_गवाक्षः 0
#परिभाषय SHOW_OPENWINDOW 1
#परिभाषय SHOW_ICONWINDOW 2
#परिभाषय SHOW_FULLSCREEN 3
#परिभाषय SHOW_OPENNOACTIVATE 4

#परिभाषय SW_PARENTCLOSING 1
#परिभाषय SW_OTHERZOOM 2
#परिभाषय SW_PARENTOPENING 3
#परिभाषय SW_OTHERUNZOOM 4
#यदि_अन्तः

#परिभाषय AW_HOR_धनात्मकम् 0x00000001
#परिभाषय AW_HOR_NEGATIVE 0x00000002
#परिभाषय AW_VER_धनात्मकम् 0x00000004
#परिभाषय AW_VER_NEGATIVE 0x00000008
#परिभाषय AW_CENTER 0x00000010
#परिभाषय AW_HIDE 0x00010000
#परिभाषय AW_ACTIVATE 0x00020000
#परिभाषय AW_SLIDE 0x00040000
#परिभाषय AW_BLEND 0x00080000

#परिभाषय KF_EXTENDED 0x0100
#परिभाषय KF_DLGMODE 0x0800
#परिभाषय KF_MENUMODE 0x1000
#परिभाषय KF_ALTDOWN 0x2000
#परिभाषय KF_REPEAT 0x4000
#परिभाषय KF_ऊर्ध्वम् 0x8000

#यदि_अपरिभाषितम् NOVIRTUALKEYCODES

#परिभाषय VK_LBUTTON 0x01
#परिभाषय VK_RBUTTON 0x02
#परिभाषय VK_CANCEL 0x03
#परिभाषय VK_MBUTTON 0x04
#परिभाषय VK_XBUTTON1 0x05
#परिभाषय VK_XBUTTON2 0x06
#परिभाषय VK_पृष्ठभागः 0x08
#परिभाषय VK_TAB 0x09
#परिभाषय VK_CLEAR 0x0C
#परिभाषय VK_RETURN 0x0D
#परिभाषय VK_सरणम् 0x10
#परिभाषय VK_CONTROL 0x11
#परिभाषय VK_MENU 0x12
#परिभाषय VK_PAUSE 0x13
#परिभाषय VK_CAPITAL 0x14
#परिभाषय VK_KANA 0x15
#परिभाषय VK_HANGEUL 0x15
#परिभाषय VK_HANGUL 0x15
#परिभाषय VK_JUNJA 0x17
#परिभाषय VK_FINAL 0x18
#परिभाषय VK_HANJA 0x19
#परिभाषय VK_KANJI 0x19
#परिभाषय VK_ESCAPE 0x1B
#परिभाषय VK_CONVERT 0x1C
#परिभाषय VK_NONCONVERT 0x1D
#परिभाषय VK_ACCEPT 0x1E
#परिभाषय VK_MODECHANGE 0x1F
#परिभाषय VK_SPACE 0x20
#परिभाषय VK_प्राक् 0x21
#परिभाषय VK_अग्र 0x22
#परिभाषय VK_अन्तः 0x23
#परिभाषय VK_HOME 0x24
#परिभाषय VK_वामः 0x25
#परिभाषय VK_ऊर्ध्वम् 0x26
#परिभाषय VK_दक्षिणः 0x27
#परिभाषय VK_अधस्तात् 0x28
#परिभाषय VK_SELECT 0x29
#परिभाषय VK_PRINT 0x2A
#परिभाषय VK_EXECUTE 0x2B
#परिभाषय VK_SNAPSHOT 0x2C
#परिभाषय VK_निवेशय 0x2D
#परिभाषय VK_DELETE 0x2E
#परिभाषय VK_HELP 0x2F

#परिभाषय VK_LWIN 0x5B
#परिभाषय VK_RWIN 0x5C
#परिभाषय VK_APPS 0x5D
#परिभाषय VK_SLEEP 0x5F
#परिभाषय VK_NUMPAD0 0x60
#परिभाषय VK_NUMPAD1 0x61
#परिभाषय VK_NUMPAD2 0x62
#परिभाषय VK_NUMPAD3 0x63
#परिभाषय VK_NUMPAD4 0x64
#परिभाषय VK_NUMPAD5 0x65
#परिभाषय VK_NUMPAD6 0x66
#परिभाषय VK_NUMPAD7 0x67
#परिभाषय VK_NUMPAD8 0x68
#परिभाषय VK_NUMPAD9 0x69
#परिभाषय VK_MULTIPLY 0x6A
#परिभाषय VK_सङ्कलय 0x6B
#परिभाषय VK_SEPARATOR 0x6C
#परिभाषय VK_व्यवकलय 0x6D
#परिभाषय VK_DECIMAL 0x6E
#परिभाषय VK_DIVIDE 0x6F
#परिभाषय VK_F1 0x70
#परिभाषय VK_F2 0x71
#परिभाषय VK_F3 0x72
#परिभाषय VK_F4 0x73
#परिभाषय VK_F5 0x74
#परिभाषय VK_F6 0x75
#परिभाषय VK_F7 0x76
#परिभाषय VK_F8 0x77
#परिभाषय VK_F9 0x78
#परिभाषय VK_F10 0x79
#परिभाषय VK_F11 0x7A
#परिभाषय VK_F12 0x7B
#परिभाषय VK_F13 0x7C
#परिभाषय VK_F14 0x7D
#परिभाषय VK_F15 0x7E
#परिभाषय VK_F16 0x7F
#परिभाषय VK_F17 0x80
#परिभाषय VK_F18 0x81
#परिभाषय VK_F19 0x82
#परिभाषय VK_F20 0x83
#परिभाषय VK_F21 0x84
#परिभाषय VK_F22 0x85
#परिभाषय VK_F23 0x86
#परिभाषय VK_F24 0x87
#परिभाषय VK_NUMLOCK 0x90
#परिभाषय VK_SCROLL 0x91
#परिभाषय VK_OEM_NEC_EQUAL 0x92
#परिभाषय VK_OEM_FJ_JISHO 0x92
#परिभाषय VK_OEM_FJ_MASSHOU 0x93
#परिभाषय VK_OEM_FJ_TOUROKU 0x94
#परिभाषय VK_OEM_FJ_LOYA 0x95
#परिभाषय VK_OEM_FJ_ROYA 0x96
#परिभाषय VK_LSHIFT 0xA0
#परिभाषय VK_RSHIFT 0xA1
#परिभाषय VK_LCONTROL 0xA2
#परिभाषय VK_RCONTROL 0xA3
#परिभाषय VK_LMENU 0xA4
#परिभाषय VK_RMENU 0xA5
#परिभाषय VK_BROWSER_पृष्ठभागः 0xA6
#परिभाषय VK_BROWSER_FORWARD 0xA7
#परिभाषय VK_BROWSER_REFRESH 0xA8
#परिभाषय VK_BROWSER_STOP 0xA9
#परिभाषय VK_BROWSER_अन्वेषणम् 0xAA
#परिभाषय VK_BROWSER_FAVORITES 0xAB
#परिभाषय VK_BROWSER_HOME 0xAC
#परिभाषय VK_VOLUME_MUTE 0xAD
#परिभाषय VK_VOLUME_अधस्तात् 0xAE
#परिभाषय VK_VOLUME_ऊर्ध्वम् 0xAF
#परिभाषय VK_MEDIA_अग्र_TRACK 0xB0
#परिभाषय VK_MEDIA_पूर्व_TRACK 0xB1
#परिभाषय VK_MEDIA_STOP 0xB2
#परिभाषय VK_MEDIA_PLAY_PAUSE 0xB3
#परिभाषय VK_LAUNCH_MAIL 0xB4
#परिभाषय VK_LAUNCH_MEDIA_SELECT 0xB5
#परिभाषय VK_LAUNCH_APP1 0xB6
#परिभाषय VK_LAUNCH_APP2 0xB7
#परिभाषय VK_OEM_1 0xBA
#परिभाषय VK_OEM_PLUS 0xBB
#परिभाषय VK_OEM_COMMA 0xBC
#परिभाषय VK_OEM_MINUS 0xBD
#परिभाषय VK_OEM_PERIOD 0xBE
#परिभाषय VK_OEM_2 0xBF
#परिभाषय VK_OEM_3 0xC0
#परिभाषय VK_OEM_4 0xDB
#परिभाषय VK_OEM_5 0xDC
#परिभाषय VK_OEM_6 0xDD
#परिभाषय VK_OEM_7 0xDE
#परिभाषय VK_OEM_8 0xDF
#परिभाषय VK_OEM_AX 0xE1
#परिभाषय VK_OEM_102 0xE2
#परिभाषय VK_ICO_HELP 0xE3
#परिभाषय VK_ICO_00 0xE4
#परिभाषय VK_PROCESSKEY 0xE5
#परिभाषय VK_ICO_CLEAR 0xE6
#परिभाषय VK_PACKET 0xE7
#परिभाषय VK_OEM_RESET 0xE9
#परिभाषय VK_OEM_JUMP 0xEA
#परिभाषय VK_OEM_PA1 0xEB
#परिभाषय VK_OEM_PA2 0xEC
#परिभाषय VK_OEM_PA3 0xED
#परिभाषय VK_OEM_WSCTRL 0xEE
#परिभाषय VK_OEM_CUSEL 0xEF
#परिभाषय VK_OEM_ATTN 0xF0
#परिभाषय VK_OEM_FINISH 0xF1
#परिभाषय VK_OEM_COPY 0xF2
#परिभाषय VK_OEM_AUTO 0xF3
#परिभाषय VK_OEM_ENLW 0xF4
#परिभाषय VK_OEM_BACKTAB 0xF5
#परिभाषय VK_ATTN 0xF6
#परिभाषय VK_CRSEL 0xF7
#परिभाषय VK_EXSEL 0xF8
#परिभाषय VK_EREOF 0xF9
#परिभाषय VK_PLAY 0xFA
#परिभाषय VK_ZOOM 0xFB
#परिभाषय VK_NONAME 0xFC
#परिभाषय VK_PA1 0xFD
#परिभाषय VK_OEM_CLEAR 0xFE
#यदि_अन्तः

#यदि_अपरिभाषितम् NOWH

#परिभाषय WH_MIN (-1)
#परिभाषय WH_MSGFILTER (-1)
#परिभाषय WH_JOURNALRECORD 0
#परिभाषय WH_JOURNALPLAYBACK 1
#परिभाषय WH_KEYBOARD 2
#परिभाषय WH_GETMESSAGE 3
#परिभाषय WH_CALLWNDPROC 4
#परिभाषय WH_CBT 5
#परिभाषय WH_SYSMSGFILTER 6
#परिभाषय WH_MOUSE 7
#परिभाषय WH_HARDWARE 8
#परिभाषय WH_DEBUG 9
#परिभाषय WH_SHELL 10
#परिभाषय WH_FOREGROUNDIDLE 11
#परिभाषय WH_CALLWNDPROCRET 12

#परिभाषय WH_KEYBOARD_LL 13
#परिभाषय WH_MOUSE_LL 14

#परिभाषय WH_MAX 14

#परिभाषय WH_MINHOOK WH_MIN
#परिभाषय WH_MAXHOOK WH_MAX

#परिभाषय HC_ACTION 0
#परिभाषय HC_GETNEXT 1
#परिभाषय HC_SKIP 2
#परिभाषय HC_NOREMOVE 3
#परिभाषय HC_NOREM HC_NOREMOVE
#परिभाषय HC_SYSMODALON 4
#परिभाषय HC_SYSMODALOFF 5

#परिभाषय HCBT_MOVESIZE 0
#परिभाषय HCBT_MINMAX 1
#परिभाषय HCBT_QS 2
#परिभाषय HCBT_CREATEWND 3
#परिभाषय HCBT_DESTROYWND 4
#परिभाषय HCBT_ACTIVATE 5
#परिभाषय HCBT_CLICKSKIPPED 6
#परिभाषय HCBT_KEYSKIPPED 7
#परिभाषय HCBT_SYSCOMMAND 8
#परिभाषय HCBT_SETFOCUS 9

  प्रकारनिर्देश संरचना चिह्नकम्_CBT_CREATEWNDA {
    संरचना चिह्नकम्_CREATESTRUCTA *lpcs;
    HWND hwnd_निवेशय_After;
  } CBT_CREATEWNDA,*LPCBT_CREATEWNDA;

  प्रकारनिर्देश संरचना चिह्नकम्_CBT_CREATEWNDW {
    संरचना चिह्नकम्_CREATESTRUCTW *lpcs;
    HWND hwnd_निवेशय_After;
  } CBT_CREATEWNDW,*LPCBT_CREATEWNDW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश CBT_CREATEWNDW CBT_CREATEWND;
  प्रकारनिर्देश LPCBT_CREATEWNDW LPCBT_CREATEWND;
#अन्यथा
  प्रकारनिर्देश CBT_CREATEWNDA CBT_CREATEWND;
  प्रकारनिर्देश LPCBT_CREATEWNDA LPCBT_CREATEWND;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_CBTACTIVATESTRUCT
  {
    WINBOOL fMouse;
    HWND h_Wnd_सक्रिय;
  } CBTACTIVATESTRUCT,*LPCBTACTIVATESTRUCT;

  प्रकारनिर्देश संरचना चिह्नकम्_WTSSESSION_NOTIFICATION {
    DWORD cb_आकार;
    DWORD dwSessionId;

  } WTSSESSION_NOTIFICATION,*PWTSSESSION_NOTIFICATION;

#परिभाषय WTS_CONSOLE_CONNECT 0x1
#परिभाषय WTS_CONSOLE_DISCONNECT 0x2
#परिभाषय WTS_REMOTE_CONNECT 0x3
#परिभाषय WTS_REMOTE_DISCONNECT 0x4
#परिभाषय WTS_SESSION_LOGON 0x5
#परिभाषय WTS_SESSION_LOGOFF 0x6
#परिभाषय WTS_SESSION_तालकम् 0x7
#परिभाषय WTS_SESSION_UNLOCK 0x8
#परिभाषय WTS_SESSION_REMOTE_CONTROL 0x9

#परिभाषय MSGF_DIALOGBOX 0
#परिभाषय MSGF_MESSAGEBOX 1
#परिभाषय MSGF_MENU 2
#परिभाषय MSGF_SCROLLBAR 5
#परिभाषय MSGF_NEXTWINDOW 6
#परिभाषय MSGF_MAX 8
#परिभाषय MSGF_USER 4096

#परिभाषय HSHELL_WINDOWCREATED 1
#परिभाषय HSHELL_WINDOWDESTROYED 2
#परिभाषय HSHELL_ACTIVATESHELLWINDOW 3

#परिभाषय HSHELL_WINDOWACTIVATED 4
#परिभाषय HSHELL_GETMINRECT 5
#परिभाषय HSHELL_REDRAW 6
#परिभाषय HSHELL_TASKMAN 7
#परिभाषय HSHELL_LANGUAGE 8
#परिभाषय HSHELL_SYSMENU 9
#परिभाषय HSHELL_ENDTASK 10
#परिभाषय HSHELL_ACCESSIBILITYSTATE 11
#परिभाषय HSHELL_APPCOMMAND 12
#परिभाषय HSHELL_WINDOWREPLACED 13
#परिभाषय HSHELL_WINDOWREPLACING 14
#परिभाषय HSHELL_HIGHBIT 0x8000
#परिभाषय HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#परिभाषय HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#परिभाषय ACCESS_STICKYKEYS 0x0001
#परिभाषय ACCESS_FILTERKEYS 0x0002
#परिभाषय ACCESS_MOUSEKEYS 0x0003

#परिभाषय APPCOMMAND_BROWSER_BACKWARD 1
#परिभाषय APPCOMMAND_BROWSER_FORWARD 2
#परिभाषय APPCOMMAND_BROWSER_REFRESH 3
#परिभाषय APPCOMMAND_BROWSER_STOP 4
#परिभाषय APPCOMMAND_BROWSER_अन्वेषणम् 5
#परिभाषय APPCOMMAND_BROWSER_FAVORITES 6
#परिभाषय APPCOMMAND_BROWSER_HOME 7
#परिभाषय APPCOMMAND_VOLUME_MUTE 8
#परिभाषय APPCOMMAND_VOLUME_अधस्तात् 9
#परिभाषय APPCOMMAND_VOLUME_ऊर्ध्वम् 10
#परिभाषय APPCOMMAND_MEDIA_NEXTTRACK 11
#परिभाषय APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#परिभाषय APPCOMMAND_MEDIA_STOP 13
#परिभाषय APPCOMMAND_MEDIA_PLAY_PAUSE 14
#परिभाषय APPCOMMAND_LAUNCH_MAIL 15
#परिभाषय APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#परिभाषय APPCOMMAND_LAUNCH_APP1 17
#परिभाषय APPCOMMAND_LAUNCH_APP2 18
#परिभाषय APPCOMMAND_BASS_अधस्तात् 19
#परिभाषय APPCOMMAND_BASS_BOOST 20
#परिभाषय APPCOMMAND_BASS_ऊर्ध्वम् 21
#परिभाषय APPCOMMAND_TREBLE_अधस्तात् 22
#परिभाषय APPCOMMAND_TREBLE_ऊर्ध्वम् 23
#परिभाषय APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#परिभाषय APPCOMMAND_MICROPHONE_VOLUME_अधस्तात् 25
#परिभाषय APPCOMMAND_MICROPHONE_VOLUME_ऊर्ध्वम् 26
#परिभाषय APPCOMMAND_HELP 27
#परिभाषय APPCOMMAND_FIND 28
#परिभाषय APPCOMMAND_NEW 29
#परिभाषय APPCOMMAND_OPEN 30
#परिभाषय APPCOMMAND_CLOSE 31
#परिभाषय APPCOMMAND_SAVE 32
#परिभाषय APPCOMMAND_PRINT 33
#परिभाषय APPCOMMAND_UNDO 34
#परिभाषय APPCOMMAND_REDO 35
#परिभाषय APPCOMMAND_COPY 36
#परिभाषय APPCOMMAND_CUT 37
#परिभाषय APPCOMMAND_PASTE 38
#परिभाषय APPCOMMAND_प्रत्युत्तरम्_गन्तव्यम्_MAIL 39
#परिभाषय APPCOMMAND_FORWARD_MAIL 40
#परिभाषय APPCOMMAND_SEND_MAIL 41
#परिभाषय APPCOMMAND_SPELL_CHECK 42
#परिभाषय APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#परिभाषय APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#परिभाषय APPCOMMAND_CORRECTION_LIST 45
#परिभाषय APPCOMMAND_MEDIA_PLAY 46
#परिभाषय APPCOMMAND_MEDIA_PAUSE 47
#परिभाषय APPCOMMAND_MEDIA_लेखः 48
#परिभाषय APPCOMMAND_MEDIA_FAST_FORWARD 49
#परिभाषय APPCOMMAND_MEDIA_REWIND 50
#परिभाषय APPCOMMAND_MEDIA_CHANNEL_ऊर्ध्वम् 51
#परिभाषय APPCOMMAND_MEDIA_CHANNEL_अधस्तात् 52

#परिभाषय FAPPCOMMAND_MOUSE 0x8000
#परिभाषय FAPPCOMMAND_कुञ्चिका 0
#परिभाषय FAPPCOMMAND_OEM 0x1000
#परिभाषय FAPPCOMMAND_आवरणम् 0xF000

#परिभाषय GET_APPCOMMAND_LPARAM(lParam) ((ह्रस्व)(HIWORD(lParam) & ~FAPPCOMMAND_आवरणम्))
#परिभाषय GET_DEVICE_LPARAM(lParam) ((WORD)(HIWORD(lParam) & FAPPCOMMAND_आवरणम्))
#परिभाषय GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#परिभाषय GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#परिभाषय GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)

  प्रकारनिर्देश संरचना {
    HWND hwnd;
    RECT rc;
  } SHELLHOOKINFO,*LPSHELLHOOKINFO;

  प्रकारनिर्देश संरचना चिह्नकम्_EVENTMSG {
    UINT सन्देशः_2;
    UINT paramL;
    UINT paramH;
    DWORD time;
    HWND hwnd;
  } EVENTMSG,*PEVENTMSGMSG,*NPEVENTMSGMSG,*LPEVENTMSGMSG;

  प्रकारनिर्देश संरचना चिह्नकम्_EVENTMSG *PEVENTMSG,*NPEVENTMSG,*LPEVENTMSG;

  प्रकारनिर्देश संरचना चिह्नकम्_CWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT सन्देशः_2;
    HWND hwnd;
  } CWPSTRUCT,*PCWPSTRUCT,*NPCWPSTRUCT,*LPCWPSTRUCT;

  प्रकारनिर्देश संरचना चिह्नकम्_CWPRETSTRUCT {
    LRESULT l_परिणाम;
    LPARAM lParam;
    WPARAM wParam;
    UINT सन्देशः_2;
    HWND hwnd;
  } CWPRETSTRUCT,*PCWPRETSTRUCT,*NPCWPRETSTRUCT,*LPCWPRETSTRUCT;

#परिभाषय LLKHF_EXTENDED (KF_EXTENDED >> 8)
#परिभाषय LLKHF_INJECTED 0x00000010
#परिभाषय LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#परिभाषय LLKHF_ऊर्ध्वम् (KF_ऊर्ध्वम् >> 8)

#परिभाषय LLMHF_INJECTED 0x00000001

  प्रकारनिर्देश संरचना चिह्नकम्_KBDLLHOOKSTRUCT {
    DWORD vk_संहिता;
    DWORD अवलोकनम्_संहिता;
    DWORD flags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;

  प्रकारनिर्देश संरचना चिह्नकम्_MSLLHOOKSTRUCT {
    POINT pt;
    DWORD mouse_दत्त;
    DWORD flags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } MSLLHOOKSTRUCT,*LPMSLLHOOKSTRUCT,*PMSLLHOOKSTRUCT;

  प्रकारनिर्देश संरचना चिह्नकम्_DEBUGHOOKINFO {
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    पूर्णाङ्क संहिता;
  } DEBUGHOOKINFO,*PDEBUGHOOKINFO,*NPDEBUGHOOKINFO,*LPDEBUGHOOKINFO;

  प्रकारनिर्देश संरचना चिह्नकम्_MOUSEHOOKSTRUCT {
    POINT pt;
    HWND hwnd;
    UINT w_लब्धम्_Test_संहिता;
    ULONG_PTR dwExtraInfo;
  } MOUSEHOOKSTRUCT,*LPMOUSEHOOKSTRUCT,*PMOUSEHOOKSTRUCT;

#यदि_परिभाषितम् __cplusplus
  प्रकारनिर्देश संरचना चिह्नकम्_MOUSEHOOKSTRUCTEX : सार्वजनिक चिह्नकम्_MOUSEHOOKSTRUCT {
    DWORD mouse_दत्त;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#अन्यथा
  प्रकारनिर्देश संरचना चिह्नकम्_MOUSEHOOKSTRUCTEX {
    MOUSEHOOKSTRUCT _unnamed;
    DWORD mouse_दत्त;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_HARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT सन्देशः_2;
    WPARAM wParam;
    LPARAM lParam;
  } HARDWAREHOOKSTRUCT,*LPHARDWAREHOOKSTRUCT,*PHARDWAREHOOKSTRUCT;
#यदि_अन्तः

#परिभाषय HKL_पूर्व 0
#परिभाषय HKL_अग्र 1

#परिभाषय KLF_ACTIVATE 0x00000001
#परिभाषय KLF_SUBSTITUTE_OK 0x00000002
#परिभाषय KLF_REORDER 0x00000008
#परिभाषय KLF_REPLACELANG 0x00000010
#परिभाषय KLF_NOTELLSHELL 0x00000080
#परिभाषय KLF_SETFORPROCESS 0x00000100
#परिभाषय KLF_SHIFTLOCK 0x00010000
#परिभाषय KLF_RESET 0x40000000

#परिभाषय INPUTLANGCHANGE_SYSCHARSET 0x0001
#परिभाषय INPUTLANGCHANGE_FORWARD 0x0002
#परिभाषय INPUTLANGCHANGE_BACKWARD 0x0004

#परिभाषय KL_NAMELENGTH 9

#यदि_परिभाषितम् UNICODE
#परिभाषय आरोपय_Keyboard_Layout आरोपय_Keyboard_Layout_W
#परिभाषय GetKeyboardLayoutName GetKeyboardLayoutNameW
#अन्यथा
#परिभाषय आरोपय_Keyboard_Layout आरोपय_Keyboard_Layout_A
#परिभाषय GetKeyboardLayoutName GetKeyboardLayoutNameA
#यदि_अन्तः

  WINUSERAPI HKL WINAPI आरोपय_Keyboard_Layout_A(LPCSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI आरोपय_Keyboard_Layout_W(LPCWSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ActivateKeyboardLayout(HKL hkl,UINT Flags);
  WINUSERAPI पूर्णाङ्क WINAPI गन्तव्यम्_Unicode_Ex(UINT w_Virt_कुञ्चिका,UINT w_अवलोकनम्_संहिता,CONST BYTE *lp_कुञ्चिका_State,LPWSTR pwszBuff,पूर्णाङ्क cchBuff,UINT wFlags,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI UnloadKeyboardLayout(HKL hkl);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameA(LPSTR pwszKLID);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameW(LPWSTR pwszKLID);
  WINUSERAPI पूर्णाङ्क WINAPI GetKeyboardLayoutList(पूर्णाङ्क nBuff,HKL *lpList);
  WINUSERAPI HKL WINAPI GetKeyboardLayout(DWORD idThread);

  प्रकारनिर्देश संरचना चिह्नकम्_MOUSEMOVEPOINT {
    पूर्णाङ्क x;
    पूर्णाङ्क y;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

#परिभाषय GMMP_USE_DISPLAY_POINTS 1
#परिभाषय GMMP_USE_उच्चः_RESOLUTION_POINTS 2

  WINUSERAPI पूर्णाङ्क WINAPI GetMouseMovePointsEx(UINT cb_आकार,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,पूर्णाङ्क nBufPoints,DWORD resolution);

#यदि_अपरिभाषितम् NODESKTOP

#परिभाषय DESKTOP_READOBJECTS 0x0001L
#परिभाषय DESKTOP_CREATEWINDOW 0x0002L
#परिभाषय DESKTOP_CREATEMENU 0x0004L
#परिभाषय DESKTOP_HOOKCONTROL 0x0008L
#परिभाषय DESKTOP_JOURNALRECORD 0x0010L
#परिभाषय DESKTOP_JOURNALPLAYBACK 0x0020L
#परिभाषय DESKTOP_ENUMERATE 0x0040L
#परिभाषय DESKTOP_WRITEOBJECTS 0x0080L
#परिभाषय DESKTOP_SWITCHDESKTOP 0x0100L

#परिभाषय DF_ALLOWOTHERACCOUNTHOOK 0x0001L

#यदि_परिभाषितम् _WINGDI_
#यदि_अपरिभाषितम् NOGDI
#यदि_परिभाषितम् UNICODE
#परिभाषय CreateDesktop CreateDesktopW
#अन्यथा
#परिभाषय CreateDesktop CreateDesktopA
#यदि_अन्तः

  WINUSERAPI HDESK WINAPI CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,LPDEVMODEA pDevmode,DWORD dwFlags,ACCESS_आवरणम् dwDesiredAccess,LPSECURITY_गुणाः lpsa);
  WINUSERAPI HDESK WINAPI CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,LPDEVMODEW pDevmode,DWORD dwFlags,ACCESS_आवरणम् dwDesiredAccess,LPSECURITY_गुणाः lpsa);
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय OpenDesktop OpenDesktopW
#परिभाषय EnumDesktops EnumDesktopsW
#अन्यथा
#परिभाषय OpenDesktop OpenDesktopA
#परिभाषय EnumDesktops EnumDesktopsA
#यदि_अन्तः

  WINUSERAPI HDESK WINAPI OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_आवरणम् dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_आवरणम् dwDesiredAccess);
  WINUSERAPI HDESK WINAPI Open_निवेशः_Desktop(DWORD dwFlags,WINBOOL fInherit,ACCESS_आवरणम् dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SwitchDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Thread_Desktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI CloseDesktop(HDESK hDesktop);
  WINUSERAPI HDESK WINAPI GetThreadDesktop(DWORD dwThreadId);
#यदि_अन्तः

#यदि_अपरिभाषितम् NOWINDOWSTATION
#परिभाषय WINSTA_ENUMDESKTOPS 0x0001L
#परिभाषय WINSTA_READATTRIBUTES 0x0002L
#परिभाषय WINSTA_ACCESSCLIPBOARD 0x0004L
#परिभाषय WINSTA_CREATEDESKTOP 0x0008L
#परिभाषय WINSTA_WRITEATTRIBUTES 0x0010L
#परिभाषय WINSTA_ACCESSGLOBALATOMS 0x0020L
#परिभाषय WINSTA_EXITWINDOWS 0x0040L
#परिभाषय WINSTA_ENUMERATE 0x0100L
#परिभाषय WINSTA_READSCREEN 0x0200L
#परिभाषय WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#परिभाषय CWF_CREATE_ONLY 0x0001L

#परिभाषय WSF_VISIBLE 0x0001L

#यदि_परिभाषितम् UNICODE
#परिभाषय Create_गवाक्षः_Station Create_गवाक्षः_Station_W
#परिभाषय Open_गवाक्षः_Station Open_गवाक्षः_Station_W
#परिभाषय Enum_गवाक्षः_Stations Enum_गवाक्षः_Stations_W
#अन्यथा
#परिभाषय Create_गवाक्षः_Station Create_गवाक्षः_Station_A
#परिभाषय Open_गवाक्षः_Station Open_गवाक्षः_Station_A
#परिभाषय Enum_गवाक्षः_Stations Enum_गवाक्षः_Stations_A
#यदि_अन्तः

  WINUSERAPI HWINSTA WINAPI Create_गवाक्षः_Station_A(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_आवरणम् dwDesiredAccess,LPSECURITY_गुणाः lpsa);
  WINUSERAPI HWINSTA WINAPI Create_गवाक्षः_Station_W(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_आवरणम् dwDesiredAccess,LPSECURITY_गुणाः lpsa);
  WINUSERAPI HWINSTA WINAPI Open_गवाक्षः_Station_A(LPCSTR lpszWinSta,WINBOOL fInherit,ACCESS_आवरणम् dwDesiredAccess);
  WINUSERAPI HWINSTA WINAPI Open_गवाक्षः_Station_W(LPCWSTR lpszWinSta,WINBOOL fInherit,ACCESS_आवरणम् dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI Enum_गवाक्षः_Stations_A(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Enum_गवाक्षः_Stations_W(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Close_गवाक्षः_Station(HWINSTA hWinSta);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Process_गवाक्षः_Station(HWINSTA hWinSta);
  WINUSERAPI HWINSTA WINAPI Get_Process_गवाक्षः_Station(VOID);
#यदि_अन्तः

#यदि_अपरिभाषितम् NOSECURITY
  WINUSERAPI WINBOOL WINAPI समुच्चयः_User_Object_Security(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
  WINUSERAPI WINBOOL WINAPI GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD n_दीर्घता,LPDWORD lpn_दीर्घता_Needed);

#परिभाषय UOI_FLAGS 1
#परिभाषय UOI_NAME 2
#परिभाषय UOI_TYPE 3
#परिभाषय UOI_USER_SID 4

  प्रकारनिर्देश संरचना चिह्नकम्_USEROBJECTFLAGS {
    WINBOOL fInherit;
    WINBOOL fReserved;
    DWORD dwFlags;
  } USEROBJECTFLAGS,*PUSEROBJECTFLAGS;

#यदि_परिभाषितम् UNICODE
#परिभाषय GetUserObjectInformation GetUserObjectInformationW
#परिभाषय समुच्चयः_User_Object_Information समुच्चयः_User_Object_Information_W
#अन्यथा
#परिभाषय GetUserObjectInformation GetUserObjectInformationA
#परिभाषय समुच्चयः_User_Object_Information समुच्चयः_User_Object_Information_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationA(HANDLE hObj,पूर्णाङ्क n_सूचकांक,PVOID pvInfo,DWORD n_दीर्घता,LPDWORD lpn_दीर्घता_Needed);
  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationW(HANDLE hObj,पूर्णाङ्क n_सूचकांक,PVOID pvInfo,DWORD n_दीर्घता,LPDWORD lpn_दीर्घता_Needed);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_User_Object_Information_A(HANDLE hObj,पूर्णाङ्क n_सूचकांक,PVOID pvInfo,DWORD n_दीर्घता);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_User_Object_Information_W(HANDLE hObj,पूर्णाङ्क n_सूचकांक,PVOID pvInfo,DWORD n_दीर्घता);
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_WNDCLASSEXA {
    UINT cb_आकार;
    UINT style;
    WNDPROC lpfnWndProc;
    पूर्णाङ्क cbClsExtra;
    पूर्णाङ्क cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
  } WNDCLASSEXA,*PWNDCLASSEXA,*NPWNDCLASSEXA,*LPWNDCLASSEXA;

  प्रकारनिर्देश संरचना चिह्नकम्_WNDCLASSEXW {
    UINT cb_आकार;
    UINT style;
    WNDPROC lpfnWndProc;
    पूर्णाङ्क cbClsExtra;
    पूर्णाङ्क cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;

    HICON hIconSm;
  } WNDCLASSEXW,*PWNDCLASSEXW,*NPWNDCLASSEXW,*LPWNDCLASSEXW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WNDCLASSEXW WNDCLASSEX;
  प्रकारनिर्देश PWNDCLASSEXW PWNDCLASSEX;
  प्रकारनिर्देश NPWNDCLASSEXW NPWNDCLASSEX;
  प्रकारनिर्देश LPWNDCLASSEXW LPWNDCLASSEX;
#अन्यथा
  प्रकारनिर्देश WNDCLASSEXA WNDCLASSEX;
  प्रकारनिर्देश PWNDCLASSEXA PWNDCLASSEX;
  प्रकारनिर्देश NPWNDCLASSEXA NPWNDCLASSEX;
  प्रकारनिर्देश LPWNDCLASSEXA LPWNDCLASSEX;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_WNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    पूर्णाङ्क cbClsExtra;
    पूर्णाङ्क cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
  } WNDCLASSA,*PWNDCLASSA,*NPWNDCLASSA,*LPWNDCLASSA;

  प्रकारनिर्देश संरचना चिह्नकम्_WNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    पूर्णाङ्क cbClsExtra;
    पूर्णाङ्क cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
  } WNDCLASSW,*PWNDCLASSW,*NPWNDCLASSW,*LPWNDCLASSW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WNDCLASSW WNDCLASS;
  प्रकारनिर्देश PWNDCLASSW PWNDCLASS;
  प्रकारनिर्देश NPWNDCLASSW NPWNDCLASS;
  प्रकारनिर्देश LPWNDCLASSW LPWNDCLASS;
#अन्यथा
  प्रकारनिर्देश WNDCLASSA WNDCLASS;
  प्रकारनिर्देश PWNDCLASSA PWNDCLASS;
  प्रकारनिर्देश NPWNDCLASSA NPWNDCLASS;
  प्रकारनिर्देश LPWNDCLASSA LPWNDCLASS;
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI Is_Hung_App_गवाक्षः(HWND hwnd);
  WINUSERAPI VOID WINAPI DisableProcessWindowsGhosting(VOID);

#यदि_अपरिभाषितम् NOMSG
  प्रकारनिर्देश संरचना चिह्नकम्_सन्देशः {
    HWND hwnd;
    UINT सन्देशः_2;
    WPARAM wParam;
    LPARAM lParam;
    DWORD time;
    POINT pt;
  } सन्देशः_3,*PMSG,*NPMSG,*LPMSG;

#परिभाषय POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#परिभाषय POINTTOPOINTS(pt) (MAKELONG((ह्रस्व)((pt).x),(ह्रस्व)((pt).y)))
#परिभाषय MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#परिभाषय MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#परिभाषय MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))
#यदि_अन्तः

#यदि_अपरिभाषितम् NOWINOFFSETS
#परिभाषय GWL_WNDPROC (-4)
#परिभाषय GWL_HINSTANCE (-6)
#परिभाषय GWL_HWNDPARENT (-8)
#परिभाषय GWL_STYLE (-16)
#परिभाषय GWL_EXSTYLE (-20)
#परिभाषय GWL_USERDATA (-21)
#परिभाषय GWL_ID (-12)

#यदि_परिभाषितम् _WIN64
#अपरिभाषय GWL_WNDPROC
#अपरिभाषय GWL_HINSTANCE
#अपरिभाषय GWL_HWNDPARENT
#अपरिभाषय GWL_USERDATA
#यदि_अन्तः

#परिभाषय GWLP_WNDPROC (-4)
#परिभाषय GWLP_HINSTANCE (-6)
#परिभाषय GWLP_HWNDPARENT (-8)
#परिभाषय GWLP_USERDATA (-21)
#परिभाषय GWLP_ID (-12)

#परिभाषय GCL_MENUNAME (-8)
#परिभाषय GCL_HBRBACKGROUND (-10)
#परिभाषय GCL_HCURSOR (-12)
#परिभाषय GCL_HICON (-14)
#परिभाषय GCL_HMODULE (-16)
#परिभाषय GCL_CBWNDEXTRA (-18)
#परिभाषय GCL_CBCLSEXTRA (-20)
#परिभाषय GCL_WNDPROC (-24)
#परिभाषय GCL_STYLE (-26)
#परिभाषय GCW_ATOM (-32)
#परिभाषय GCL_HICONSM (-34)

#यदि_परिभाषितम् _WIN64

#अपरिभाषय GCL_MENUNAME
#अपरिभाषय GCL_HBRBACKGROUND
#अपरिभाषय GCL_HCURSOR
#अपरिभाषय GCL_HICON
#अपरिभाषय GCL_HMODULE
#अपरिभाषय GCL_WNDPROC
#अपरिभाषय GCL_HICONSM
#यदि_अन्तः

#परिभाषय GCLP_MENUNAME (-8)
#परिभाषय GCLP_HBRBACKGROUND (-10)
#परिभाषय GCLP_HCURSOR (-12)
#परिभाषय GCLP_HICON (-14)
#परिभाषय GCLP_HMODULE (-16)
#परिभाषय GCLP_WNDPROC (-24)
#परिभाषय GCLP_HICONSM (-34)
#यदि_अन्तः

#यदि_अपरिभाषितम् NOWINMESSAGES

#परिभाषय WM_NULL 0x0000
#परिभाषय WM_CREATE 0x0001
#परिभाषय WM_DESTROY 0x0002
#परिभाषय WM_MOVE 0x0003
#परिभाषय WM_आकार 0x0005

#परिभाषय WM_ACTIVATE 0x0006

#परिभाषय WA_INACTIVE 0
#परिभाषय WA_सक्रिय 1
#परिभाषय WA_CLICKACTIVE 2

#परिभाषय WM_SETFOCUS 0x0007
#परिभाषय WM_KILLFOCUS 0x0008
#परिभाषय WM_ENABLE 0x000A
#परिभाषय WM_SETREDRAW 0x000B
#परिभाषय WM_SETTEXT 0x000C
#परिभाषय WM_GETTEXT 0x000D
#परिभाषय WM_GETTEXTLENGTH 0x000E
#परिभाषय WM_PAINT 0x000F
#परिभाषय WM_CLOSE 0x0010
#यदि_अपरिभाषितम् _WIN32_WCE
#परिभाषय WM_QUERYENDSESSION 0x0011
#परिभाषय WM_QUERYOPEN 0x0013
#परिभाषय WM_ENDSESSION 0x0016
#यदि_अन्तः
#परिभाषय WM_QUIT 0x0012
#परिभाषय WM_ERASEBKGND 0x0014
#परिभाषय WM_SYSCOLORCHANGE 0x0015
#परिभाषय WM_SHOWWINDOW 0x0018
#परिभाषय WM_WININICHANGE 0x001A
#परिभाषय WM_SETTINGCHANGE WM_WININICHANGE
#परिभाषय WM_DEVMODECHANGE 0x001B
#परिभाषय WM_ACTIVATEAPP 0x001C
#परिभाषय WM_FONTCHANGE 0x001D
#परिभाषय WM_TIMECHANGE 0x001E
#परिभाषय WM_CANCELMODE 0x001F
#परिभाषय WM_SETCURSOR 0x0020
#परिभाषय WM_MOUSEACTIVATE 0x0021
#परिभाषय WM_CHILDACTIVATE 0x0022
#परिभाषय WM_QUEUESYNC 0x0023

#परिभाषय WM_GETMINMAXINFO 0x0024

  प्रकारनिर्देश संरचना चिह्नकम्_MINMAXINFO {
    POINT ptReserved;
    POINT pt_Max_आकार;
    POINT ptMaxPosition;
    POINT pt_Min_Track_आकार;
    POINT pt_Max_Track_आकार;
  } MINMAXINFO,*PMINMAXINFO,*LPMINMAXINFO;

#परिभाषय WM_PAINTICON 0x0026
#परिभाषय WM_ICONERASEBKGND 0x0027
#परिभाषय WM_NEXTDLGCTL 0x0028
#परिभाषय WM_SPOOLERSTATUS 0x002A
#परिभाषय WM_DRAWITEM 0x002B
#परिभाषय WM_MEASUREITEM 0x002C
#परिभाषय WM_DELETEITEM 0x002D
#परिभाषय WM_VKEYTOITEM 0x002E
#परिभाषय WM_CHARTOITEM 0x002F
#परिभाषय WM_SETFONT 0x0030
#परिभाषय WM_GETFONT 0x0031
#परिभाषय WM_SETHOTKEY 0x0032
#परिभाषय WM_GETHOTKEY 0x0033
#परिभाषय WM_QUERYDRAGICON 0x0037
#परिभाषय WM_COMPAREITEM 0x0039
#यदि_अपरिभाषितम् _WIN32_WCE
#परिभाषय WM_GETOBJECT 0x003D
#यदि_अन्तः
#परिभाषय WM_COMPACTING 0x0041
#परिभाषय WM_COMMNOTIFY 0x0044
#परिभाषय WM_WINDOWPOSCHANGING 0x0046
#परिभाषय WM_WINDOWPOSCHANGED 0x0047

#परिभाषय WM_POWER 0x0048

#परिभाषय PWR_OK 1
#परिभाषय PWR_FAIL (-1)
#परिभाषय PWR_SUSPENDREQUEST 1
#परिभाषय PWR_SUSPENDRESUME 2
#परिभाषय PWR_CRITICALRESUME 3

#परिभाषय WM_COPYDATA 0x004A
#परिभाषय WM_CANCELJOURNAL 0x004B

  प्रकारनिर्देश संरचना चिह्नकम्_COPYDATASTRUCT {
    ULONG_PTR dw_दत्त;
    DWORD cb_दत्त;
    PVOID lp_दत्त;
  } COPYDATASTRUCT,*PCOPYDATASTRUCT;

  प्रकारनिर्देश संरचना चिह्नकम्_MDINEXTMENU {
    HMENU hmenu_अन्तर्;
    HMENU hmenu_अग्र;
    HWND hwnd_अग्र;
  } MDINEXTMENU,*PMDINEXTMENU,*LPMDINEXTMENU;

#परिभाषय WM_NOTIFY 0x004E
#परिभाषय WM_INPUTLANGCHANGEREQUEST 0x0050
#परिभाषय WM_INPUTLANGCHANGE 0x0051
#परिभाषय WM_TCARD 0x0052
#परिभाषय WM_HELP 0x0053
#परिभाषय WM_USERCHANGED 0x0054
#परिभाषय WM_NOTIFYFORMAT 0x0055

#परिभाषय NFR_ANSI 1
#परिभाषय NFR_UNICODE 2
#परिभाषय NF_QUERY 3
#परिभाषय NF_REQUERY 4

#परिभाषय WM_CONTEXTMENU 0x007B
#परिभाषय WM_STYLECHANGING 0x007C
#परिभाषय WM_STYLECHANGED 0x007D
#परिभाषय WM_DISPLAYCHANGE 0x007E
#परिभाषय WM_GETICON 0x007F
#परिभाषय WM_SETICON 0x0080

#परिभाषय WM_NCCREATE 0x0081
#परिभाषय WM_NCDESTROY 0x0082
#परिभाषय WM_NCCALCSIZE 0x0083
#परिभाषय WM_NCHITTEST 0x0084
#परिभाषय WM_NCPAINT 0x0085
#परिभाषय WM_NCACTIVATE 0x0086
#परिभाषय WM_GETDLGCODE 0x0087
#यदि_अपरिभाषितम् _WIN32_WCE
#परिभाषय WM_SYNCPAINT 0x0088
#यदि_अन्तः
#परिभाषय WM_NCMOUSEMOVE 0x00A0
#परिभाषय WM_NCLBUTTONDOWN 0x00A1
#परिभाषय WM_NCLBUTTONUP 0x00A2
#परिभाषय WM_NCLBUTTONDBLCLK 0x00A3
#परिभाषय WM_NCRBUTTONDOWN 0x00A4
#परिभाषय WM_NCRBUTTONUP 0x00A5
#परिभाषय WM_NCRBUTTONDBLCLK 0x00A6
#परिभाषय WM_NCMBUTTONDOWN 0x00A7
#परिभाषय WM_NCMBUTTONUP 0x00A8
#परिभाषय WM_NCMBUTTONDBLCLK 0x00A9

#परिभाषय WM_NCXBUTTONDOWN 0x00AB
#परिभाषय WM_NCXBUTTONUP 0x00AC
#परिभाषय WM_NCXBUTTONDBLCLK 0x00AD
#परिभाषय WM_निवेशः 0x00FF
#परिभाषय WM_KEYFIRST 0x0100
#परिभाषय WM_KEYDOWN 0x0100
#परिभाषय WM_KEYUP 0x0101
#परिभाषय WM_CHAR 0x0102
#परिभाषय WM_DEADCHAR 0x0103
#परिभाषय WM_SYSKEYDOWN 0x0104
#परिभाषय WM_SYSKEYUP 0x0105
#परिभाषय WM_SYSCHAR 0x0106
#परिभाषय WM_SYSDEADCHAR 0x0107
#परिभाषय WM_UNICHAR 0x0109
#परिभाषय WM_KEYLAST 0x0109
#परिभाषय UNICODE_NOCHAR 0xFFFF
#परिभाषय WM_IME_STARTCOMPOSITION 0x010D
#परिभाषय WM_IME_ENDCOMPOSITION 0x010E
#परिभाषय WM_IME_COMPOSITION 0x010F
#परिभाषय WM_IME_KEYLAST 0x010F
#परिभाषय WM_INITDIALOG 0x0110
#परिभाषय WM_COMMAND 0x0111
#परिभाषय WM_SYSCOMMAND 0x0112
#परिभाषय WM_TIMER 0x0113
#परिभाषय WM_HSCROLL 0x0114
#परिभाषय WM_VSCROLL 0x0115
#परिभाषय WM_INITMENU 0x0116
#परिभाषय WM_INITMENUPOPUP 0x0117
#परिभाषय WM_MENUSELECT 0x011F
#परिभाषय WM_MENUCHAR 0x0120
#परिभाषय WM_ENTERIDLE 0x0121
#यदि_अपरिभाषितम् _WIN32_WCE
#परिभाषय WM_MENURBUTTONUP 0x0122
#परिभाषय WM_MENUDRAG 0x0123
#परिभाषय WM_MENUGETOBJECT 0x0124
#परिभाषय WM_UNINITMENUPOPUP 0x0125
#परिभाषय WM_MENUCOMMAND 0x0126

#यदि_अपरिभाषितम् _WIN32_WCE
#परिभाषय WM_CHANGEUISTATE 0x0127
#परिभाषय WM_UPDATEUISTATE 0x0128
#परिभाषय WM_QUERYUISTATE 0x0129

#परिभाषय UIS_समुच्चयः 1
#परिभाषय UIS_CLEAR 2
#परिभाषय UIS_INITIALIZE 3

#परिभाषय UISF_HIDEFOCUS 0x1
#परिभाषय UISF_HIDEACCEL 0x2
#परिभाषय UISF_सक्रिय 0x4
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय WM_CTLCOLORMSGBOX 0x0132
#परिभाषय WM_CTLCOLOREDIT 0x0133
#परिभाषय WM_CTLCOLORLISTBOX 0x0134
#परिभाषय WM_CTLCOLORBTN 0x0135
#परिभाषय WM_CTLCOLORDLG 0x0136
#परिभाषय WM_CTLCOLORSCROLLBAR 0x0137
#परिभाषय WM_CTLCOLORSTATIC 0x0138
#परिभाषय MN_GETHMENU 0x01E1

#परिभाषय WM_MOUSEFIRST 0x0200
#परिभाषय WM_MOUSEMOVE 0x0200
#परिभाषय WM_LBUTTONDOWN 0x0201
#परिभाषय WM_LBUTTONUP 0x0202
#परिभाषय WM_LBUTTONDBLCLK 0x0203
#परिभाषय WM_RBUTTONDOWN 0x0204
#परिभाषय WM_RBUTTONUP 0x0205
#परिभाषय WM_RBUTTONDBLCLK 0x0206
#परिभाषय WM_MBUTTONDOWN 0x0207
#परिभाषय WM_MBUTTONUP 0x0208
#परिभाषय WM_MBUTTONDBLCLK 0x0209
#परिभाषय WM_MOUSEWHEEL 0x020A
#परिभाषय WM_XBUTTONDOWN 0x020B
#परिभाषय WM_XBUTTONUP 0x020C
#परिभाषय WM_XBUTTONDBLCLK 0x020D
#परिभाषय WM_MOUSEHWHEEL 0x020E
#परिभाषय WM_MOUSELAST 0x020E

#परिभाषय WHEEL_DELTA 120
#परिभाषय GET_WHEEL_DELTA_WPARAM(wParam) ((ह्रस्व)HIWORD(wParam))

#परिभाषय WHEEL_PAGESCROLL (UINT_MAX)

#परिभाषय GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#परिभाषय GET_NCHITTEST_WPARAM(wParam) ((ह्रस्व)LOWORD(wParam))
#परिभाषय GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#परिभाषय XBUTTON1 0x0001
#परिभाषय XBUTTON2 0x0002

#परिभाषय WM_PARENTNOTIFY 0x0210
#परिभाषय WM_ENTERMENULOOP 0x0211
#परिभाषय WM_EXITMENULOOP 0x0212

#परिभाषय WM_NEXTMENU 0x0213
#परिभाषय WM_SIZING 0x0214
#परिभाषय WM_CAPTURECHANGED 0x0215
#परिभाषय WM_MOVING 0x0216

#परिभाषय WM_POWERBROADCAST 0x0218

#यदि_अपरिभाषितम् _WIN32_WCE
#परिभाषय PBT_APMQUERYSUSPEND 0x0000
#परिभाषय PBT_APMQUERYSTANDBY 0x0001

#परिभाषय PBT_APMQUERYSUSPENDFAILED 0x0002
#परिभाषय PBT_APMQUERYSTANDBYFAILED 0x0003

#परिभाषय PBT_APMSUSPEND 0x0004
#परिभाषय PBT_APMSTANDBY 0x0005

#परिभाषय PBT_APMRESUMECRITICAL 0x0006
#परिभाषय PBT_APMRESUMESUSPEND 0x0007
#परिभाषय PBT_APMRESUMESTANDBY 0x0008

#परिभाषय PBTF_APMRESUMEFROMFAILURE 0x00000001

#परिभाषय PBT_APMBATTERYLOW 0x0009
#परिभाषय PBT_APMPOWERSTATUSCHANGE 0x000A

#परिभाषय PBT_APMOEMEVENT 0x000B
#परिभाषय PBT_APMRESUMEAUTOMATIC 0x0012
#यदि_अन्तः

#परिभाषय WM_DEVICECHANGE 0x0219

#परिभाषय WM_MDICREATE 0x0220
#परिभाषय WM_MDIDESTROY 0x0221
#परिभाषय WM_MDIACTIVATE 0x0222
#परिभाषय WM_MDIRESTORE 0x0223
#परिभाषय WM_MDINEXT 0x0224
#परिभाषय WM_MDIMAXIMIZE 0x0225
#परिभाषय WM_MDITILE 0x0226
#परिभाषय WM_MDICASCADE 0x0227
#परिभाषय WM_MDIICONARRANGE 0x0228
#परिभाषय WM_MDIGETACTIVE 0x0229

#परिभाषय WM_MDISETMENU 0x0230
#परिभाषय WM_ENTERSIZEMOVE 0x0231
#परिभाषय WM_EXITSIZEMOVE 0x0232
#परिभाषय WM_DROPFILES 0x0233
#परिभाषय WM_MDIREFRESHMENU 0x0234

#परिभाषय WM_IME_SETCONTEXT 0x0281
#परिभाषय WM_IME_NOTIFY 0x0282
#परिभाषय WM_IME_CONTROL 0x0283
#परिभाषय WM_IME_COMPOSITIONFULL 0x0284
#परिभाषय WM_IME_SELECT 0x0285
#परिभाषय WM_IME_CHAR 0x0286
#परिभाषय WM_IME_REQUEST 0x0288
#परिभाषय WM_IME_KEYDOWN 0x0290
#परिभाषय WM_IME_KEYUP 0x0291

#परिभाषय WM_MOUSEHOVER 0x02A1
#परिभाषय WM_MOUSELEAVE 0x02A3
#परिभाषय WM_NCMOUSEHOVER 0x02A0
#परिभाषय WM_NCMOUSELEAVE 0x02A2
#परिभाषय WM_WTSSESSION_CHANGE 0x02B1
#परिभाषय WM_TABLET_FIRST 0x02c0
#परिभाषय WM_TABLET_चरमः 0x02df
#परिभाषय WM_CUT 0x0300
#परिभाषय WM_COPY 0x0301
#परिभाषय WM_PASTE 0x0302
#परिभाषय WM_CLEAR 0x0303
#परिभाषय WM_UNDO 0x0304
#परिभाषय WM_RENDERFORMAT 0x0305
#परिभाषय WM_RENDERALLFORMATS 0x0306
#परिभाषय WM_DESTROYCLIPBOARD 0x0307
#परिभाषय WM_DRAWCLIPBOARD 0x0308
#परिभाषय WM_PAINTCLIPBOARD 0x0309
#परिभाषय WM_VSCROLLCLIPBOARD 0x030A
#परिभाषय WM_SIZECLIPBOARD 0x030B
#परिभाषय WM_ASKCBFORMATNAME 0x030C
#परिभाषय WM_CHANGECBCHAIN 0x030D
#परिभाषय WM_HSCROLLCLIPBOARD 0x030E
#परिभाषय WM_QUERYNEWPALETTE 0x030F
#परिभाषय WM_PALETTEISCHANGING 0x0310
#परिभाषय WM_PALETTECHANGED 0x0311
#परिभाषय WM_HOTKEY 0x0312
#परिभाषय WM_PRINT 0x0317
#परिभाषय WM_PRINTCLIENT 0x0318
#परिभाषय WM_APPCOMMAND 0x0319
#परिभाषय WM_THEMECHANGED 0x031A
#परिभाषय WM_HANDHELDFIRST 0x0358
#परिभाषय WM_HANDHELDLAST 0x035F
#परिभाषय WM_AFXFIRST 0x0360
#परिभाषय WM_AFXLAST 0x037F
#परिभाषय WM_PENWINFIRST 0x0380
#परिभाषय WM_PENWINLAST 0x038F
#परिभाषय WM_APP 0x8000
#परिभाषय WM_USER 0x0400

#परिभाषय WMSZ_वामः 1
#परिभाषय WMSZ_दक्षिणः 2
#परिभाषय WMSZ_शिखरम् 3
#परिभाषय WMSZ_TOPLEFT 4
#परिभाषय WMSZ_TOPRIGHT 5
#परिभाषय WMSZ_BOTTOM 6
#परिभाषय WMSZ_BOTTOMLEFT 7
#परिभाषय WMSZ_BOTTOMRIGHT 8

#यदि_अपरिभाषितम् NONCMESSAGES

#परिभाषय HTERROR (-2)
#परिभाषय HTTRANSPARENT (-1)
#परिभाषय HTNOWHERE 0
#परिभाषय HTCLIENT 1
#परिभाषय HTCAPTION 2
#परिभाषय HTSYSMENU 3
#परिभाषय HTGROWBOX 4
#परिभाषय HTSIZE HTGROWBOX
#परिभाषय HTMENU 5
#परिभाषय HTHSCROLL 6
#परिभाषय HTVSCROLL 7
#परिभाषय HTMINBUTTON 8
#परिभाषय HTMAXBUTTON 9
#परिभाषय HTLEFT 10
#परिभाषय HTRIGHT 11
#परिभाषय HTTOP 12
#परिभाषय HTTOPLEFT 13
#परिभाषय HTTOPRIGHT 14
#परिभाषय HTBOTTOM 15
#परिभाषय HTBOTTOMLEFT 16
#परिभाषय HTBOTTOMRIGHT 17
#परिभाषय HTBORDER 18
#परिभाषय HTREDUCE HTMINBUTTON
#परिभाषय HTZOOM HTMAXBUTTON
#परिभाषय HTSIZEFIRST HTLEFT
#परिभाषय HTSIZELAST HTBOTTOMRIGHT
#परिभाषय HTOBJECT 19
#परिभाषय HTCLOSE 20
#परिभाषय HTHELP 21

#परिभाषय SMTO_प्रसामान्यम् 0x0000
#परिभाषय SMTO_खण्डम् 0x0001
#परिभाषय SMTO_ABORTIFHUNG 0x0002
#परिभाषय SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#यदि_अन्तः

#परिभाषय MA_ACTIVATE 1
#परिभाषय MA_ACTIVATEANDEAT 2
#परिभाषय MA_NOACTIVATE 3
#परिभाषय MA_NOACTIVATEANDEAT 4

#परिभाषय ICON_SMALL 0
#परिभाषय ICON_BIG 1
#परिभाषय ICON_SMALL2 2

#यदि_परिभाषितम् UNICODE
#परिभाषय पञ्जिकाकोशः_गवाक्षः_सन्देशः पञ्जिकाकोशः_गवाक्षः_सन्देशः_W
#अन्यथा
#परिभाषय पञ्जिकाकोशः_गवाक्षः_सन्देशः पञ्जिकाकोशः_गवाक्षः_सन्देशः_A
#यदि_अन्तः

  WINUSERAPI UINT WINAPI पञ्जिकाकोशः_गवाक्षः_सन्देशः_A(LPCSTR lpString);
  WINUSERAPI UINT WINAPI पञ्जिकाकोशः_गवाक्षः_सन्देशः_W(LPCWSTR lpString);

#परिभाषय आकार_RESTORED 0
#परिभाषय आकार_MINIMIZED 1
#परिभाषय आकार_MAXIMIZED 2
#परिभाषय आकार_MAXSHOW 3
#परिभाषय आकार_MAXHIDE 4

#परिभाषय SIZENORMAL आकार_RESTORED
#परिभाषय SIZEICONIC आकार_MINIMIZED
#परिभाषय SIZEFULLSCREEN आकार_MAXIMIZED
#परिभाषय SIZEZOOMSHOW आकार_MAXSHOW
#परिभाषय SIZEZOOMHIDE आकार_MAXHIDE

  प्रकारनिर्देश संरचना चिह्नकम्_WINDOWPOS {
    HWND hwnd;
    HWND hwnd_निवेशय_After;
    पूर्णाङ्क x;
    पूर्णाङ्क y;
    पूर्णाङ्क cx;
    पूर्णाङ्क cy;
    UINT flags;
  } WINDOWPOS,*LPWINDOWPOS,*PWINDOWPOS;

  प्रकारनिर्देश संरचना चिह्नकम्_NCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
  } NCCALCSIZE_PARAMS,*LPNCCALCSIZE_PARAMS;

#परिभाषय WVR_ALIGNTOP 0x0010
#परिभाषय WVR_ALIGNLEFT 0x0020
#परिभाषय WVR_ALIGNBOTTOM 0x0040
#परिभाषय WVR_ALIGNRIGHT 0x0080
#परिभाषय WVR_HREDRAW 0x0100
#परिभाषय WVR_VREDRAW 0x0200
#परिभाषय WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#परिभाषय WVR_VALIDRECTS 0x0400

#यदि_अपरिभाषितम् NOKEYSTATES

#परिभाषय MK_LBUTTON 0x0001
#परिभाषय MK_RBUTTON 0x0002
#परिभाषय MK_सरणम् 0x0004
#परिभाषय MK_CONTROL 0x0008
#परिभाषय MK_MBUTTON 0x0010
#परिभाषय MK_XBUTTON1 0x0020
#परिभाषय MK_XBUTTON2 0x0040
#यदि_अन्तः

#यदि_अपरिभाषितम् NOTRACKMOUSEEVENT
#परिभाषय TME_HOVER 0x00000001
#परिभाषय TME_LEAVE 0x00000002
#परिभाषय TME_NONCLIENT 0x00000010
#परिभाषय TME_QUERY 0x40000000
#परिभाषय TME_CANCEL 0x80000000

#परिभाषय HOVER_DEFAULT 0xFFFFFFFF
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_TRACKMOUSEEVENT {
    DWORD cb_आकार;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dwHoverTime;
  } TRACKMOUSEEVENT,*LPTRACKMOUSEEVENT;

  WINUSERAPI WINBOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#यदि_अन्तः

#यदि_अपरिभाषितम् NOWINSTYLES

#परिभाषय WS_OVERLAPPED 0x00000000L
#परिभाषय WS_POPUP 0x80000000L
#परिभाषय WS_CHILD 0x40000000L
#परिभाषय WS_MINIMIZE 0x20000000L
#परिभाषय WS_VISIBLE 0x10000000L
#परिभाषय WS_DISABLED 0x08000000L
#परिभाषय WS_CLIPSIBLINGS 0x04000000L
#परिभाषय WS_CLIPCHILDREN 0x02000000L
#परिभाषय WS_MAXIMIZE 0x01000000L
#परिभाषय WS_CAPTION 0x00C00000L
#परिभाषय WS_BORDER 0x00800000L
#परिभाषय WS_DLGFRAME 0x00400000L
#परिभाषय WS_VSCROLL 0x00200000L
#परिभाषय WS_HSCROLL 0x00100000L
#परिभाषय WS_SYSMENU 0x00080000L
#परिभाषय WS_THICKFRAME 0x00040000L
#परिभाषय WS_गणः 0x00020000L
#परिभाषय WS_TABSTOP 0x00010000L
#परिभाषय WS_MINIMIZEBOX 0x00020000L
#परिभाषय WS_MAXIMIZEBOX 0x00010000L
#परिभाषय WS_TILED WS_OVERLAPPED
#परिभाषय WS_ICONIC WS_MINIMIZE
#परिभाषय WS_SIZEBOX WS_THICKFRAME
#परिभाषय WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#परिभाषय WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#परिभाषय WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#परिभाषय WS_CHILDWINDOW (WS_CHILD)

#परिभाषय WS_EX_DLGMODALFRAME 0x00000001L
#परिभाषय WS_EX_NOPARENTNOTIFY 0x00000004L
#परिभाषय WS_EX_TOPMOST 0x00000008L
#परिभाषय WS_EX_ACCEPTFILES 0x00000010L
#परिभाषय WS_EX_TRANSPARENT 0x00000020L
#परिभाषय WS_EX_MDICHILD 0x00000040L
#परिभाषय WS_EX_TOOLWINDOW 0x00000080L
#परिभाषय WS_EX_WINDOWEDGE 0x00000100L
#परिभाषय WS_EX_CLIENTEDGE 0x00000200L
#परिभाषय WS_EX_CONTEXTHELP 0x00000400L
#परिभाषय WS_EX_दक्षिणः 0x00001000L
#परिभाषय WS_EX_वामः 0x00000000L
#परिभाषय WS_EX_RTLREADING 0x00002000L
#परिभाषय WS_EX_LTRREADING 0x00000000L
#परिभाषय WS_EX_LEFTSCROLLBAR 0x00004000L
#परिभाषय WS_EX_RIGHTSCROLLBAR 0x00000000L
#परिभाषय WS_EX_CONTROLPARENT 0x00010000L
#परिभाषय WS_EX_STATICEDGE 0x00020000L
#परिभाषय WS_EX_APPWINDOW 0x00040000L
#परिभाषय WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#परिभाषय WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#परिभाषय WS_EX_LAYERED 0x00080000
#परिभाषय WS_EX_NOINHERITLAYOUT 0x00100000L
#परिभाषय WS_EX_LAYOUTRTL 0x00400000L
#परिभाषय WS_EX_COMPOSITED 0x02000000L
#परिभाषय WS_EX_NOACTIVATE 0x08000000L

#परिभाषय CS_VREDRAW 0x0001
#परिभाषय CS_HREDRAW 0x0002
#परिभाषय CS_DBLCLKS 0x0008
#परिभाषय CS_OWNDC 0x0020
#परिभाषय CS_CLASSDC 0x0040
#परिभाषय CS_PARENTDC 0x0080
#परिभाषय CS_NOCLOSE 0x0200
#परिभाषय CS_SAVEBITS 0x0800
#परिभाषय CS_BYTEALIGNCLIENT 0x1000
#परिभाषय CS_BYTEALIGNWINDOW 0x2000
#परिभाषय CS_GLOBALCLASS 0x4000
#परिभाषय CS_IME 0x00010000
#परिभाषय CS_DROPSHADOW 0x00020000
#यदि_अन्तः

#परिभाषय PRF_CHECKVISIBLE 0x00000001L
#परिभाषय PRF_NONCLIENT 0x00000002L
#परिभाषय PRF_CLIENT 0x00000004L
#परिभाषय PRF_ERASEBKGND 0x00000008L
#परिभाषय PRF_CHILDREN 0x00000010L
#परिभाषय PRF_OWNED 0x00000020L

#परिभाषय BDR_RAISEDOUTER 0x0001
#परिभाषय BDR_SUNKENOUTER 0x0002
#परिभाषय BDR_RAISEDINNER 0x0004
#परिभाषय BDR_SUNKENINNER 0x0008

#परिभाषय BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#परिभाषय BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#परिभाषय BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#परिभाषय BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#परिभाषय EDGE_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#परिभाषय EDGE_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#परिभाषय EDGE_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#परिभाषय EDGE_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#परिभाषय BF_वामः 0x0001
#परिभाषय BF_शिखरम् 0x0002
#परिभाषय BF_दक्षिणः 0x0004
#परिभाषय BF_BOTTOM 0x0008

#परिभाषय BF_TOPLEFT (BF_शिखरम् | BF_वामः)
#परिभाषय BF_TOPRIGHT (BF_शिखरम् | BF_दक्षिणः)
#परिभाषय BF_BOTTOMLEFT (BF_BOTTOM | BF_वामः)
#परिभाषय BF_BOTTOMRIGHT (BF_BOTTOM | BF_दक्षिणः)
#परिभाषय BF_RECT (BF_वामः | BF_शिखरम् | BF_दक्षिणः | BF_BOTTOM)

#परिभाषय BF_DIAGONAL 0x0010

#परिभाषय BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_शिखरम् | BF_दक्षिणः)
#परिभाषय BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_शिखरम् | BF_वामः)
#परिभाषय BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_वामः)
#परिभाषय BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_दक्षिणः)

#परिभाषय BF_मध्यः 0x0800
#परिभाषय BF_SOFT 0x1000
#परिभाषय BF_ADJUST 0x2000
#परिभाषय BF_FLAT 0x4000
#परिभाषय BF_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI DrawEdge(HDC hdc,LPRECT qrc,UINT edge,UINT grfFlags);

#परिभाषय DFC_CAPTION 1
#परिभाषय DFC_MENU 2
#परिभाषय DFC_SCROLL 3
#परिभाषय DFC_BUTTON 4
#परिभाषय DFC_POPUPMENU 5

#परिभाषय DFCS_CAPTIONCLOSE 0x0000
#परिभाषय DFCS_CAPTIONMIN 0x0001
#परिभाषय DFCS_CAPTIONMAX 0x0002
#परिभाषय DFCS_CAPTIONRESTORE 0x0003
#परिभाषय DFCS_CAPTIONHELP 0x0004

#परिभाषय DFCS_MENUARROW 0x0000
#परिभाषय DFCS_MENUCHECK 0x0001
#परिभाषय DFCS_MENUBULLET 0x0002
#परिभाषय DFCS_MENUARROWRIGHT 0x0004
#परिभाषय DFCS_SCROLLUP 0x0000
#परिभाषय DFCS_SCROLLDOWN 0x0001
#परिभाषय DFCS_SCROLLLEFT 0x0002
#परिभाषय DFCS_SCROLLRIGHT 0x0003
#परिभाषय DFCS_SCROLLCOMBOBOX 0x0005
#परिभाषय DFCS_SCROLLSIZEGRIP 0x0008
#परिभाषय DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#परिभाषय DFCS_BUTTONCHECK 0x0000
#परिभाषय DFCS_BUTTONRADIOIMAGE 0x0001
#परिभाषय DFCS_BUTTONRADIOMASK 0x0002
#परिभाषय DFCS_BUTTONRADIO 0x0004
#परिभाषय DFCS_BUTTON3STATE 0x0008
#परिभाषय DFCS_BUTTONPUSH 0x0010

#परिभाषय DFCS_INACTIVE 0x0100
#परिभाषय DFCS_PUSHED 0x0200
#परिभाषय DFCS_CHECKED 0x0400

#परिभाषय DFCS_TRANSPARENT 0x0800
#परिभाषय DFCS_HOT 0x1000

#परिभाषय DFCS_ADJUSTRECT 0x2000
#परिभाषय DFCS_FLAT 0x4000
#परिभाषय DFCS_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI DrawFrameControl(HDC,LPRECT,UINT,UINT);

#परिभाषय DC_सक्रिय 0x0001
#परिभाषय DC_SMALLCAP 0x0002
#परिभाषय DC_ICON 0x0004
#परिभाषय DC_TEXT 0x0008
#परिभाषय DC_INBUTTON 0x0010
#परिभाषय DC_GRADIENT 0x0020
#परिभाषय DC_BUTTONS 0x1000

  WINUSERAPI WINBOOL WINAPI DrawCaption(HWND hwnd,HDC hdc,CONST RECT *lprect,UINT flags);

#परिभाषय IDANI_OPEN 1
#परिभाषय IDANI_CAPTION 3

  WINUSERAPI WINBOOL WINAPI DrawAnimatedRects(HWND hwnd,पूर्णाङ्क idAni,CONST RECT *lprcFrom,CONST RECT *lprc_गन्तव्यम्);

#यदि_अपरिभाषितम् NOCLIPBOARD

#परिभाषय CF_TEXT 1
#परिभाषय CF_BITMAP 2
#परिभाषय CF_METAFILEPICT 3
#परिभाषय CF_SYLK 4
#परिभाषय CF_DIF 5
#परिभाषय CF_TIFF 6
#परिभाषय CF_OEMTEXT 7
#परिभाषय CF_DIB 8
#परिभाषय CF_PALETTE 9
#परिभाषय CF_PENDATA 10
#परिभाषय CF_RIFF 11
#परिभाषय CF_WAVE 12
#परिभाषय CF_UNICODETEXT 13
#परिभाषय CF_ENHMETAFILE 14
#परिभाषय CF_HDROP 15
#परिभाषय CF_LOCALE 16
#परिभाषय CF_DIBV5 17
#परिभाषय CF_MAX 18

#परिभाषय CF_OWNERDISPLAY 0x0080
#परिभाषय CF_DSPTEXT 0x0081
#परिभाषय CF_DSPBITMAP 0x0082
#परिभाषय CF_DSPMETAFILEPICT 0x0083
#परिभाषय CF_DSPENHMETAFILE 0x008E

#परिभाषय CF_PRIVATEFIRST 0x0200
#परिभाषय CF_PRIVATELAST 0x02FF

#परिभाषय CF_GDIOBJFIRST 0x0300
#परिभाषय CF_GDIOBJLAST 0x03FF
#यदि_अन्तः

#परिभाषय FVIRTKEY TRUE
#परिभाषय FNOINVERT 0x02
#परिभाषय FSHIFT 0x04
#परिभाषय FCONTROL 0x08
#परिभाषय FALT 0x10

  प्रकारनिर्देश संरचना चिह्नकम्_ACCEL {
    BYTE fVirt;
    WORD कुञ्चिका;
    WORD cmd;
  } ACCEL,*LPACCEL;

  प्रकारनिर्देश संरचना चिह्नकम्_PAINTSTRUCT {
    HDC hdc;
    WINBOOL fErase;
    RECT rcPaint;
    WINBOOL fRestore;
    WINBOOL fIncUpdate;
    BYTE rgbReserved[32];
  } PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;

  प्रकारनिर्देश संरचना चिह्नकम्_CREATESTRUCTA {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwndParent;
    पूर्णाङ्क cy;
    पूर्णाङ्क cx;
    पूर्णाङ्क y;
    पूर्णाङ्क x;
    LONG style;
    LPCSTR lpszName;
    LPCSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTA,*LPCREATESTRUCTA;

  प्रकारनिर्देश संरचना चिह्नकम्_CREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwndParent;
    पूर्णाङ्क cy;
    पूर्णाङ्क cx;
    पूर्णाङ्क y;
    पूर्णाङ्क x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTW,*LPCREATESTRUCTW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश CREATESTRUCTW CREATESTRUCT;
  प्रकारनिर्देश LPCREATESTRUCTW LPCREATESTRUCT;
#अन्यथा
  प्रकारनिर्देश CREATESTRUCTA CREATESTRUCT;
  प्रकारनिर्देश LPCREATESTRUCTA LPCREATESTRUCT;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_WINDOWPLACEMENT {
    UINT दीर्घता;
    UINT flags;
    UINT showCmd;
    POINT ptMinPosition;
    POINT ptMaxPosition;
    RECT rc_प्रसामान्यम्_Position;
  } WINDOWPLACEMENT;
  प्रकारनिर्देश WINDOWPLACEMENT *PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;

#परिभाषय WPF_SETMINPOSITION 0x0001
#परिभाषय WPF_RESTORETOMAXIMIZED 0x0002
#परिभाषय WPF_ASYNCWINDOWPLACEMENT 0x0004

  प्रकारनिर्देश संरचना चिह्नकम्_NMHDR {
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT संहिता;
  } NMHDR;

  प्रकारनिर्देश NMHDR *LPNMHDR;

  प्रकारनिर्देश संरचना चिह्नकम्_STYLESTRUCT {
    DWORD styleOld;
    DWORD styleNew;
  } STYLESTRUCT,*LPSTYLESTRUCT;

#परिभाषय ODT_MENU 1
#परिभाषय ODT_LISTBOX 2
#परिभाषय ODT_COMBOBOX 3
#परिभाषय ODT_BUTTON 4
#परिभाषय ODT_STATIC 5

#परिभाषय ODA_DRAWENTIRE 0x0001
#परिभाषय ODA_SELECT 0x0002
#परिभाषय ODA_FOCUS 0x0004

#परिभाषय ODS_SELECTED 0x0001
#परिभाषय ODS_GRAYED 0x0002
#परिभाषय ODS_DISABLED 0x0004
#परिभाषय ODS_CHECKED 0x0008
#परिभाषय ODS_FOCUS 0x0010
#परिभाषय ODS_DEFAULT 0x0020
#परिभाषय ODS_COMBOBOXEDIT 0x1000
#परिभाषय ODS_HOTLIGHT 0x0040
#परिभाषय ODS_INACTIVE 0x0080
#परिभाषय ODS_NOACCEL 0x0100
#परिभाषय ODS_NOFOCUSRECT 0x0200

  प्रकारनिर्देश संरचना चिह्नकम्_MEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT item_विस्तारः;
    UINT itemHeight;
    ULONG_PTR item_दत्त;
  } MEASUREITEMSTRUCT,*PMEASUREITEMSTRUCT,*LPMEASUREITEMSTRUCT;

  प्रकारनिर्देश संरचना चिह्नकम्_DRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    UINT itemAction;
    UINT itemState;
    HWND hwndItem;
    HDC hDC;
    RECT rcItem;
    ULONG_PTR item_दत्त;
  } DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;

  प्रकारनिर्देश संरचना चिह्नकम्_DELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT itemID;
    HWND hwndItem;
    ULONG_PTR item_दत्त;
  } DELETEITEMSTRUCT,*PDELETEITEMSTRUCT,*LPDELETEITEMSTRUCT;

  प्रकारनिर्देश संरचना चिह्नकम्_COMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwndItem;
    UINT itemID1;
    ULONG_PTR itemData1;
    UINT itemID2;
    ULONG_PTR itemData2;
    DWORD dwLocaleId;
  } COMPAREITEMSTRUCT,*PCOMPAREITEMSTRUCT,*LPCOMPAREITEMSTRUCT;

#यदि_अपरिभाषितम् NOMSG
#यदि_परिभाषितम् UNICODE
#परिभाषय Get_सन्देशः Get_सन्देशः_W
#परिभाषय Dispatch_सन्देशः Dispatch_सन्देशः_W
#परिभाषय Peek_सन्देशः Peek_सन्देशः_W
#अन्यथा
#परिभाषय Get_सन्देशः Get_सन्देशः_A
#परिभाषय Dispatch_सन्देशः Dispatch_सन्देशः_A
#परिभाषय Peek_सन्देशः Peek_सन्देशः_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI Get_सन्देशः_A(LPMSG lp_सन्देशः_2,HWND hWnd,UINT w_सन्देशः_Filter_Min,UINT w_सन्देशः_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Get_सन्देशः_W(LPMSG lp_सन्देशः_2,HWND hWnd,UINT w_सन्देशः_Filter_Min,UINT w_सन्देशः_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Translate_सन्देशः(CONST सन्देशः_3 *lp_सन्देशः_2);
  WINUSERAPI LRESULT WINAPI Dispatch_सन्देशः_A(CONST सन्देशः_3 *lp_सन्देशः_2);
  WINUSERAPI LRESULT WINAPI Dispatch_सन्देशः_W(CONST सन्देशः_3 *lp_सन्देशः_2);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_सन्देशः_Queue(पूर्णाङ्क cMessagesMax);
  WINUSERAPI WINBOOL WINAPI Peek_सन्देशः_A(LPMSG lp_सन्देशः_2,HWND hWnd,UINT w_सन्देशः_Filter_Min,UINT w_सन्देशः_Filter_Max,UINT w_Remove_सन्देशः);
  WINUSERAPI WINBOOL WINAPI Peek_सन्देशः_W(LPMSG lp_सन्देशः_2,HWND hWnd,UINT w_सन्देशः_Filter_Min,UINT w_सन्देशः_Filter_Max,UINT w_Remove_सन्देशः);

#परिभाषय PM_NOREMOVE 0x0000
#परिभाषय PM_REMOVE 0x0001
#परिभाषय PM_NOYIELD 0x0002
#परिभाषय PM_QS_निवेशः (QS_निवेशः << 16)
#परिभाषय PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#परिभाषय PM_QS_PAINT (QS_PAINT << 16)
#परिभाषय PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI पञ्जिकाकोशः_Hot_कुञ्चिका(HWND hWnd,पूर्णाङ्क id,UINT fsModifiers,UINT vk);
  WINUSERAPI WINBOOL WINAPI Unregister_Hot_कुञ्चिका(HWND hWnd,पूर्णाङ्क id);

#परिभाषय MOD_ALT 0x0001
#परिभाषय MOD_CONTROL 0x0002
#परिभाषय MOD_सरणम् 0x0004
#परिभाषय MOD_WIN 0x0008

#परिभाषय IDHOT_SNAPWINDOW (-1)
#परिभाषय IDHOT_SNAPDESKTOP (-2)

#यदि_परिभाषितम् WIN_आन्तरिकम्
#यदि_अपरिभाषितम् LSTRING
#परिभाषय NOLSTRING
#यदि_अन्तः
#यदि_अपरिभाषितम् LFILEIO
#परिभाषय NOLFILEIO
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय ENDSESSION_LOGOFF 0x80000000

#परिभाषय EWX_LOGOFF 0
#परिभाषय EWX_SHUTDOWN 0x00000001
#परिभाषय EWX_REBOOT 0x00000002
#परिभाषय EWX_FORCE 0x00000004
#परिभाषय EWX_POWEROFF 0x00000008
#परिभाषय EWX_FORCEIFHUNG 0x00000010

#परिभाषय ExitWindows(dwReserved,संहिता_4) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#यदि_परिभाषितम् UNICODE
#परिभाषय Send_सन्देशः Send_सन्देशः_W
#परिभाषय Send_सन्देशः_Timeout Send_सन्देशः_Timeout_W
#परिभाषय Send_Notify_सन्देशः Send_Notify_सन्देशः_W
#परिभाषय Send_सन्देशः_Callback Send_सन्देशः_Callback_W
#अन्यथा
#परिभाषय Send_सन्देशः Send_सन्देशः_A
#परिभाषय Send_सन्देशः_Timeout Send_सन्देशः_Timeout_A
#परिभाषय Send_Notify_सन्देशः Send_Notify_सन्देशः_A
#परिभाषय Send_सन्देशः_Callback Send_सन्देशः_Callback_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI ExitWindowsEx(UINT uFlags,DWORD dwReason);
  WINUSERAPI WINBOOL WINAPI SwapMouseButton(WINBOOL fSwap);
  WINUSERAPI DWORD WINAPI Get_सन्देशः_Pos(VOID);
  WINUSERAPI LONG WINAPI Get_सन्देशः_Time(VOID);
  WINUSERAPI LPARAM WINAPI Get_सन्देशः_Extra_Info(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Wow64_सन्देशः(VOID);
  WINUSERAPI LPARAM WINAPI समुच्चयः_सन्देशः_Extra_Info(LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_सन्देशः_A(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_सन्देशः_W(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_सन्देशः_Timeout_A(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_परिणाम);
  WINUSERAPI LRESULT WINAPI Send_सन्देशः_Timeout_W(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_परिणाम);
  WINUSERAPI WINBOOL WINAPI Send_Notify_सन्देशः_A(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_Notify_सन्देशः_W(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_सन्देशः_Callback_A(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_परिणाम_Call_पृष्ठभागः,ULONG_PTR dw_दत्त);
  WINUSERAPI WINBOOL WINAPI Send_सन्देशः_Callback_W(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_परिणाम_Call_पृष्ठभागः,ULONG_PTR dw_दत्त);

  प्रकारनिर्देश संरचना {
    UINT cb_आकार;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
  } BSMINFO,*PBSMINFO;

#यदि_परिभाषितम् UNICODE
#परिभाषय प्रसारणम्_System_सन्देशः_Ex प्रसारणम्_System_सन्देशः_Ex_W
#परिभाषय प्रसारणम्_System_सन्देशः प्रसारणम्_System_सन्देशः_W
#अन्यथा
#परिभाषय प्रसारणम्_System_सन्देशः_Ex प्रसारणम्_System_सन्देशः_Ex_A
#परिभाषय प्रसारणम्_System_सन्देशः प्रसारणम्_System_सन्देशः_A
#यदि_अन्तः

  WINUSERAPI दीर्घ WINAPI प्रसारणम्_System_सन्देशः_Ex_A(DWORD flags,LPDWORD lpInfo,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI दीर्घ WINAPI प्रसारणम्_System_सन्देशः_Ex_W(DWORD flags,LPDWORD lpInfo,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI दीर्घ WINAPI प्रसारणम्_System_सन्देशः_A(DWORD flags,LPDWORD lpInfo,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI दीर्घ WINAPI प्रसारणम्_System_सन्देशः_W(DWORD flags,LPDWORD lpInfo,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);

#परिभाषय BSM_ALLCOMPONENTS 0x00000000
#परिभाषय BSM_VXDS 0x00000001
#परिभाषय BSM_NETDRIVER 0x00000002
#परिभाषय BSM_INSTALLABLEDRIVERS 0x00000004
#परिभाषय BSM_APPLICATIONS 0x00000008
#परिभाषय BSM_ALLDESKTOPS 0x00000010

#परिभाषय BSF_QUERY 0x00000001
#परिभाषय BSF_IGNORECURRENTTASK 0x00000002
#परिभाषय BSF_FLUSHDISK 0x00000004
#परिभाषय BSF_NOHANG 0x00000008
#परिभाषय BSF_POSTMESSAGE 0x00000010
#परिभाषय BSF_FORCEIFHUNG 0x00000020
#परिभाषय BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#परिभाषय BSF_ALLOWSFW 0x00000080
#परिभाषय BSF_SENDNOTIFYMESSAGE 0x00000100
#परिभाषय BSF_RETURNHDESK 0x00000200
#परिभाषय BSF_LUID 0x00000400

#परिभाषय प्रसारणम्_QUERY_DENY 0x424D5144

  प्रकारनिर्देश PVOID HDEVNOTIFY;
  प्रकारनिर्देश HDEVNOTIFY *PHDEVNOTIFY;

#परिभाषय DEVICE_NOTIFY_गवाक्षः_HANDLE 0x00000000
#परिभाषय DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#परिभाषय DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#यदि_परिभाषितम् UNICODE
#परिभाषय पञ्जिकाकोशः_Device_Notification पञ्जिकाकोशः_Device_Notification_W
#परिभाषय Post_सन्देशः Post_सन्देशः_W
#परिभाषय Post_Thread_सन्देशः Post_Thread_सन्देशः_W
#परिभाषय Post_App_सन्देशः Post_App_सन्देशः_W
#परिभाषय Def_गवाक्षः_Proc Def_गवाक्षः_Proc_W
#परिभाषय Call_गवाक्षः_Proc Call_गवाक्षः_Proc_W
#परिभाषय पञ्जिकाकोशः_Class पञ्जिकाकोशः_Class_W
#परिभाषय UnregisterClass UnregisterClassW
#परिभाषय GetClassInfo GetClassInfoW
#परिभाषय पञ्जिकाकोशः_Class_Ex पञ्जिकाकोशः_Class_Ex_W
#परिभाषय GetClassInfoEx GetClassInfoExW
#अन्यथा
#परिभाषय पञ्जिकाकोशः_Device_Notification पञ्जिकाकोशः_Device_Notification_A
#परिभाषय Post_सन्देशः Post_सन्देशः_A
#परिभाषय Post_Thread_सन्देशः Post_Thread_सन्देशः_A
#परिभाषय Post_App_सन्देशः Post_App_सन्देशः_A
#परिभाषय Def_गवाक्षः_Proc Def_गवाक्षः_Proc_A
#परिभाषय Call_गवाक्षः_Proc Call_गवाक्षः_Proc_A
#परिभाषय पञ्जिकाकोशः_Class पञ्जिकाकोशः_Class_A
#परिभाषय UnregisterClass UnregisterClassA
#परिभाषय GetClassInfo GetClassInfoA
#परिभाषय पञ्जिकाकोशः_Class_Ex पञ्जिकाकोशः_Class_Ex_A
#परिभाषय GetClassInfoEx GetClassInfoExA
#यदि_अन्तः

  WINUSERAPI HDEVNOTIFY WINAPI पञ्जिकाकोशः_Device_Notification_A(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI HDEVNOTIFY WINAPI पञ्जिकाकोशः_Device_Notification_W(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI WINBOOL WINAPI UnregisterDeviceNotification(HDEVNOTIFY Handle);
  WINUSERAPI WINBOOL WINAPI Post_सन्देशः_A(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_सन्देशः_W(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_सन्देशः_A(DWORD idThread,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_सन्देशः_W(DWORD idThread,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
#परिभाषय Post_App_सन्देशः_A(idThread,w_सन्देशः,wParam,lParam) Post_Thread_सन्देशः_A((DWORD)idThread,w_सन्देशः,wParam,lParam)
#परिभाषय Post_App_सन्देशः_W(idThread,w_सन्देशः,wParam,lParam) Post_Thread_सन्देशः_W((DWORD)idThread,w_सन्देशः,wParam,lParam)

#परिभाषय HWND_प्रसारणम् ((HWND)0xffff)
#परिभाषय HWND_सन्देशः ((HWND)-3)

  WINUSERAPI WINBOOL WINAPI Attach_Thread_निवेशः(DWORD idAttach,DWORD id_Attach_गन्तव्यम्,WINBOOL fAttach);
  WINUSERAPI WINBOOL WINAPI प्रत्युत्तरम्_सन्देशः(LRESULT l_परिणाम);
  WINUSERAPI WINBOOL WINAPI Wait_सन्देशः(VOID);
  WINUSERAPI DWORD WINAPI Wait_For_निवेशः_Idle(HANDLE hProcess,DWORD dwMilliseconds);
  WINUSERAPI LRESULT WINAPI Def_गवाक्षः_Proc_A(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_गवाक्षः_Proc_W(HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI VOID WINAPI Post_Quit_सन्देशः(पूर्णाङ्क n_Exit_संहिता);
  WINUSERAPI LRESULT WINAPI Call_गवाक्षः_Proc_A(WNDPROC lp_पूर्व_Wnd_Func,HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Call_गवाक्षः_Proc_W(WNDPROC lp_पूर्व_Wnd_Func,HWND hWnd,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI अन्तर्_Send_सन्देशः(VOID);
  WINUSERAPI DWORD WINAPI अन्तर्_Send_सन्देशः_Ex(LPVOID lpReserved);

#परिभाषय ISMEX_NOSEND 0x00000000
#परिभाषय ISMEX_SEND 0x00000001
#परिभाषय ISMEX_NOTIFY 0x00000002
#परिभाषय ISMEX_CALLBACK 0x00000004
#परिभाषय ISMEX_REPLIED 0x00000008

  WINUSERAPI UINT WINAPI GetDoubleClickTime(VOID);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Double_Click_Time(UINT);
  WINUSERAPI ATOM WINAPI पञ्जिकाकोशः_Class_A(CONST WNDCLASSA *lpWndClass);
  WINUSERAPI ATOM WINAPI पञ्जिकाकोशः_Class_W(CONST WNDCLASSW *lpWndClass);
  WINUSERAPI WINBOOL WINAPI UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
  WINUSERAPI WINBOOL WINAPI GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
  WINUSERAPI ATOM WINAPI पञ्जिकाकोशः_Class_Ex_A(CONST WNDCLASSEXA *);
  WINUSERAPI ATOM WINAPI पञ्जिकाकोशः_Class_Ex_W(CONST WNDCLASSEXW *);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);

#परिभाषय CW_USEDEFAULT ((पूर्णाङ्क)0x80000000)

#परिभाषय HWND_DESKTOP ((HWND)0)

  प्रकारनिर्देश BOOLEAN (WINAPI *PREGISTERCLASSNAMEW)(LPCWSTR);

#यदि_परिभाषितम् UNICODE
#परिभाषय Create_गवाक्षः_Ex Create_गवाक्षः_Ex_W
#परिभाषय Create_गवाक्षः Create_गवाक्षः_W
#अन्यथा
#परिभाषय Create_गवाक्षः_Ex Create_गवाक्षः_Ex_A
#परिभाषय Create_गवाक्षः Create_गवाक्षः_A
#यदि_अन्तः

  WINUSERAPI HWND WINAPI Create_गवाक्षः_Ex_A(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lp_गवाक्षः_Name,DWORD dwStyle,पूर्णाङ्क X,पूर्णाङ्क Y,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
  WINUSERAPI HWND WINAPI Create_गवाक्षः_Ex_W(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lp_गवाक्षः_Name,DWORD dwStyle,पूर्णाङ्क X,पूर्णाङ्क Y,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
#परिभाषय Create_गवाक्षः_A(lpClassName,lp_गवाक्षः_Name,dwStyle,x,y,n_विस्तारः,nHeight,hWndParent,hMenu,hInstance,lpParam) Create_गवाक्षः_Ex_A(0L,lpClassName,lp_गवाक्षः_Name,dwStyle,x,y,n_विस्तारः,nHeight,hWndParent,hMenu,hInstance,lpParam)
#परिभाषय Create_गवाक्षः_W(lpClassName,lp_गवाक्षः_Name,dwStyle,x,y,n_विस्तारः,nHeight,hWndParent,hMenu,hInstance,lpParam) Create_गवाक्षः_Ex_W(0L,lpClassName,lp_गवाक्षः_Name,dwStyle,x,y,n_विस्तारः,nHeight,hWndParent,hMenu,hInstance,lpParam)
  WINUSERAPI WINBOOL WINAPI Is_गवाक्षः(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsMenu(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI IsChild(HWND hWndParent,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Destroy_गवाक्षः(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Show_गवाक्षः(HWND hWnd,पूर्णाङ्क nCmdShow);
  WINUSERAPI WINBOOL WINAPI Animate_गवाक्षः(HWND hWnd,DWORD dwTime,DWORD dwFlags);

#यदि defined(_WINGDI_) && !defined(NOGDI)
  WINUSERAPI WINBOOL WINAPI Update_Layered_गवाक्षः(HWND hWnd,HDC hdcDst,POINT *pptDst,आकार_2 *psize,HDC hdcSrc,POINT *pptSrc,COLORREF cr_कुञ्चिका,BLENDFUNCTION *pblend,DWORD dwFlags);

  प्रकारनिर्देश संरचना चिह्नकम्_UPDATELAYEREDWINDOWINFO {
    DWORD cb_आकार;
    HDC hdcDst;
    POINT CONST *pptDst;
    आकार_2 CONST *psize;
    HDC hdcSrc;
    POINT CONST *pptSrc;
    COLORREF cr_कुञ्चिका;
    BLENDFUNCTION CONST *pblend;
    DWORD dwFlags;
    RECT CONST *prcDirty;
  } UPDATELAYEREDWINDOWINFO,*PUPDATELAYEREDWINDOWINFO;

  WINUSERAPI WINBOOL WINAPI Update_Layered_गवाक्षः_परोक्षम्(HWND hWnd,UPDATELAYEREDWINDOWINFO CONST *pULWInfo);
  WINUSERAPI WINBOOL WINAPI Get_Layered_गवाक्षः_गुणाः(HWND hwnd,COLORREF *pcr_कुञ्चिका,BYTE *pbAlpha,DWORD *pdwFlags);

#परिभाषय PW_CLIENTONLY 0x00000001

  WINUSERAPI WINBOOL WINAPI Print_गवाक्षः(HWND hwnd,HDC hdcBlt,UINT nFlags);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Layered_गवाक्षः_गुणाः(HWND hwnd,COLORREF cr_कुञ्चिका,BYTE bAlpha,DWORD dwFlags);

#परिभाषय LWA_COLORKEY 0x00000001
#परिभाषय LWA_ALPHA 0x00000002

#परिभाषय ULW_COLORKEY 0x00000001
#परिभाषय ULW_ALPHA 0x00000002
#परिभाषय ULW_OPAQUE 0x00000004

#परिभाषय ULW_EX_NORESIZE 0x00000008

  WINUSERAPI WINBOOL WINAPI Show_गवाक्षः_Async(HWND hWnd,पूर्णाङ्क nCmdShow);
  WINUSERAPI WINBOOL WINAPI Flash_गवाक्षः(HWND hWnd,WINBOOL bInvert);

  प्रकारनिर्देश संरचना {
    UINT cb_आकार;
    HWND hwnd;
    DWORD dwFlags;
    UINT u_गणनम्;
    DWORD dwTimeout;
  } FLASHWINFO,*PFLASHWINFO;

  WINUSERAPI WINBOOL WINAPI Flash_गवाक्षः_Ex(PFLASHWINFO pfwi);

#परिभाषय FLASHW_STOP 0
#परिभाषय FLASHW_CAPTION 0x00000001
#परिभाषय FLASHW_TRAY 0x00000002
#परिभाषय FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#परिभाषय FLASHW_TIMER 0x00000004
#परिभाषय FLASHW_TIMERNOFG 0x0000000C

  WINUSERAPI WINBOOL WINAPI ShowOwnedPopups(HWND hWnd,WINBOOL fShow);
  WINUSERAPI WINBOOL WINAPI OpenIcon(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Close_गवाक्षः(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Move_गवाक्षः(HWND hWnd,पूर्णाङ्क X,पूर्णाङ्क Y,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight,WINBOOL bRepaint);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_गवाक्षः_Pos(HWND hWnd,HWND h_Wnd_निवेशय_After,पूर्णाङ्क X,पूर्णाङ्क Y,पूर्णाङ्क cx,पूर्णाङ्क cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI Get_गवाक्षः_Placement(HWND hWnd,WINDOWPLACEMENT *lpwndpl);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_गवाक्षः_Placement(HWND hWnd,CONST WINDOWPLACEMENT *lpwndpl);

#यदि_अपरिभाषितम् NODEFERWINDOWPOS
  WINUSERAPI HDWP WINAPI Begin_Defer_गवाक्षः_Pos(पूर्णाङ्क n_अङ्कः_Windows);
  WINUSERAPI HDWP WINAPI Defer_गवाक्षः_Pos(HDWP hWinPosInfo,HWND hWnd,HWND h_Wnd_निवेशय_After,पूर्णाङ्क x,पूर्णाङ्क y,पूर्णाङ्क cx,पूर्णाङ्क cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI अन्तः_Defer_गवाक्षः_Pos(HDWP hWinPosInfo);
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI Is_गवाक्षः_Visible(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsIconic(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AnyPopup(VOID);
  WINUSERAPI WINBOOL WINAPI Bring_गवाक्षः_गन्तव्यम्_शिखरम्(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsZoomed(HWND hWnd);

#परिभाषय SWP_NOSIZE 0x0001
#परिभाषय SWP_NOMOVE 0x0002
#परिभाषय SWP_NOZORDER 0x0004
#परिभाषय SWP_NOREDRAW 0x0008
#परिभाषय SWP_NOACTIVATE 0x0010
#परिभाषय SWP_FRAMECHANGED 0x0020
#परिभाषय SWP_SHOWWINDOW 0x0040
#परिभाषय SWP_HIDEWINDOW 0x0080
#परिभाषय SWP_NOCOPYBITS 0x0100
#परिभाषय SWP_NOOWNERZORDER 0x0200
#परिभाषय SWP_NOSENDCHANGING 0x0400

#परिभाषय SWP_DRAWFRAME SWP_FRAMECHANGED
#परिभाषय SWP_NOREPOSITION SWP_NOOWNERZORDER
#परिभाषय SWP_DEFERERASE 0x2000
#परिभाषय SWP_ASYNCWINDOWPOS 0x4000

#परिभाषय HWND_शिखरम् ((HWND)0)
#परिभाषय HWND_BOTTOM ((HWND)1)
#परिभाषय HWND_TOPMOST ((HWND)-1)
#परिभाषय HWND_NOTOPMOST ((HWND)-2)

#यदि_अपरिभाषितम् NOCTLMGR

#अन्तर्भाव <pshpack2.h>

  प्रकारनिर्देश संरचना {
    DWORD style;
    DWORD dwExtendedStyle;
    WORD cdit;
    ह्रस्व x;
    ह्रस्व y;
    ह्रस्व cx;
    ह्रस्व cy;
  } DLGTEMPLATE;

  प्रकारनिर्देश DLGTEMPLATE *LPDLGTEMPLATEA;
  प्रकारनिर्देश DLGTEMPLATE *LPDLGTEMPLATEW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश LPDLGTEMPLATEW LPDLGTEMPLATE;
#अन्यथा
  प्रकारनिर्देश LPDLGTEMPLATEA LPDLGTEMPLATE;
#यदि_अन्तः

  प्रकारनिर्देश CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
  प्रकारनिर्देश CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#अन्यथा
  प्रकारनिर्देश LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#यदि_अन्तः

  प्रकारनिर्देश संरचना {
    DWORD style;
    DWORD dwExtendedStyle;
    ह्रस्व x;
    ह्रस्व y;
    ह्रस्व cx;
    ह्रस्व cy;
    WORD id;
  } DLGITEMTEMPLATE;

  प्रकारनिर्देश DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
  प्रकारनिर्देश DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#अन्यथा
  प्रकारनिर्देश PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#यदि_अन्तः

  प्रकारनिर्देश DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
  प्रकारनिर्देश DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#अन्यथा
  प्रकारनिर्देश LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#यदि_अन्तः

#अन्तर्भाव <poppack.h>

#यदि_परिभाषितम् UNICODE
#परिभाषय CreateDialogParam CreateDialogParamW
#परिभाषय Create_Dialog_परोक्षम्_Param Create_Dialog_परोक्षम्_Param_W
#परिभाषय CreateDialog CreateDialogW
#परिभाषय Create_Dialog_परोक्षम् Create_Dialog_परोक्षम्_W
#परिभाषय DialogBoxParam DialogBoxParamW
#परिभाषय Dialog_Box_परोक्षम्_Param Dialog_Box_परोक्षम्_Param_W
#परिभाषय DialogBox DialogBoxW
#परिभाषय Dialog_Box_परोक्षम् Dialog_Box_परोक्षम्_W
#परिभाषय समुच्चयः_Dlg_Item_Text समुच्चयः_Dlg_Item_Text_W
#परिभाषय GetDlgItemText GetDlgItemTextW
#परिभाषय Send_Dlg_Item_सन्देशः Send_Dlg_Item_सन्देशः_W
#परिभाषय DefDlgProc DefDlgProcW
#अन्यथा
#परिभाषय CreateDialogParam CreateDialogParamA
#परिभाषय Create_Dialog_परोक्षम्_Param Create_Dialog_परोक्षम्_Param_A
#परिभाषय CreateDialog CreateDialogA
#परिभाषय Create_Dialog_परोक्षम् Create_Dialog_परोक्षम्_A
#परिभाषय DialogBoxParam DialogBoxParamA
#परिभाषय Dialog_Box_परोक्षम्_Param Dialog_Box_परोक्षम्_Param_A
#परिभाषय DialogBox DialogBoxA
#परिभाषय Dialog_Box_परोक्षम् Dialog_Box_परोक्षम्_A
#परिभाषय समुच्चयः_Dlg_Item_Text समुच्चयः_Dlg_Item_Text_A
#परिभाषय GetDlgItemText GetDlgItemTextA
#परिभाषय Send_Dlg_Item_सन्देशः Send_Dlg_Item_सन्देशः_A
#परिभाषय DefDlgProc DefDlgProcA
#यदि_अन्तः

  WINUSERAPI HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_परोक्षम्_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_परोक्षम्_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#परिभाषय CreateDialogA(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamA(hInstance,lpName,hWndParent,lpDialogFunc,0L)
#परिभाषय CreateDialogW(hInstance,lpName,hWndParent,lpDialogFunc) CreateDialogParamW(hInstance,lpName,hWndParent,lpDialogFunc,0L)
#परिभाषय Create_Dialog_परोक्षम्_A(hInstance,lpTemplate,hWndParent,lpDialogFunc) Create_Dialog_परोक्षम्_Param_A(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
#परिभाषय Create_Dialog_परोक्षम्_W(hInstance,lpTemplate,hWndParent,lpDialogFunc) Create_Dialog_परोक्षम्_Param_W(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
  WINUSERAPI INT_PTR WINAPI DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_परोक्षम्_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_परोक्षम्_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND hWndParent,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#परिभाषय DialogBoxA(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
#परिभाषय DialogBoxW(hInstance,lpTemplate,hWndParent,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
#परिभाषय Dialog_Box_परोक्षम्_A(hInstance,lpTemplate,hWndParent,lpDialogFunc) Dialog_Box_परोक्षम्_Param_A(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
#परिभाषय Dialog_Box_परोक्षम्_W(hInstance,lpTemplate,hWndParent,lpDialogFunc) Dialog_Box_परोक्षम्_Param_W(hInstance,lpTemplate,hWndParent,lpDialogFunc,0L)
  WINUSERAPI WINBOOL WINAPI अन्तः_Dialog(HWND hDlg,INT_PTR n_परिणाम);
  WINUSERAPI HWND WINAPI GetDlgItem(HWND hDlg,पूर्णाङ्क nIDDlgItem);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Dlg_Item_Int(HWND hDlg,पूर्णाङ्क nIDDlgItem,UINT u_मानम्,WINBOOL bSigned);
  WINUSERAPI UINT WINAPI GetDlgItemInt(HWND hDlg,पूर्णाङ्क nIDDlgItem,WINBOOL *lpTranslated,WINBOOL bSigned);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Dlg_Item_Text_A(HWND hDlg,पूर्णाङ्क nIDDlgItem,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Dlg_Item_Text_W(HWND hDlg,पूर्णाङ्क nIDDlgItem,LPCWSTR lpString);
  WINUSERAPI UINT WINAPI GetDlgItemTextA(HWND hDlg,पूर्णाङ्क nIDDlgItem,LPSTR lpString,पूर्णाङ्क cchMax);
  WINUSERAPI UINT WINAPI GetDlgItemTextW(HWND hDlg,पूर्णाङ्क nIDDlgItem,LPWSTR lpString,पूर्णाङ्क cchMax);
  WINUSERAPI WINBOOL WINAPI CheckDlgButton(HWND hDlg,पूर्णाङ्क nIDButton,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI CheckRadioButton(HWND hDlg,पूर्णाङ्क nIDFirstButton,पूर्णाङ्क nIDLastButton,पूर्णाङ्क nIDCheckButton);
  WINUSERAPI UINT WINAPI IsDlgButtonChecked(HWND hDlg,पूर्णाङ्क nIDButton);
  WINUSERAPI LRESULT WINAPI Send_Dlg_Item_सन्देशः_A(HWND hDlg,पूर्णाङ्क nIDDlgItem,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_Dlg_Item_सन्देशः_W(HWND hDlg,पूर्णाङ्क nIDDlgItem,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI HWND WINAPI Get_अग्र_Dlg_गणः_Item(HWND hDlg,HWND hCtl,WINBOOL bPrevious);
  WINUSERAPI HWND WINAPI Get_अग्र_Dlg_Tab_Item(HWND hDlg,HWND hCtl,WINBOOL bPrevious);
  WINUSERAPI पूर्णाङ्क WINAPI GetDlgCtrlID(HWND hWnd);
  WINUSERAPI दीर्घ WINAPI Get_Dialog_आधारः_Units(VOID);
  WINUSERAPI LRESULT WINAPI DefDlgProcA(HWND hDlg,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefDlgProcW(HWND hDlg,UINT सन्देशः_5,WPARAM wParam,LPARAM lParam);

#परिभाषय DLGWINDOWEXTRA 30
#यदि_अन्तः

#यदि_अपरिभाषितम् NOMSG

#यदि_परिभाषितम् UNICODE
#परिभाषय Call_सन्देशः_Filter Call_सन्देशः_Filter_W
#अन्यथा
#परिभाषय Call_सन्देशः_Filter Call_सन्देशः_Filter_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI Call_सन्देशः_Filter_A(LPMSG lp_सन्देशः_2,पूर्णाङ्क n_संहिता);
  WINUSERAPI WINBOOL WINAPI Call_सन्देशः_Filter_W(LPMSG lp_सन्देशः_2,पूर्णाङ्क n_संहिता);
#यदि_अन्तः

#यदि_अपरिभाषितम् NOCLIPBOARD

#यदि_परिभाषितम् UNICODE
#परिभाषय पञ्जिकाकोशः_Clipboard_Format पञ्जिकाकोशः_Clipboard_Format_W
#परिभाषय GetClipboardFormatName GetClipboardFormatNameW
#अन्यथा
#परिभाषय पञ्जिकाकोशः_Clipboard_Format पञ्जिकाकोशः_Clipboard_Format_A
#परिभाषय GetClipboardFormatName GetClipboardFormatNameA
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI OpenClipboard(HWND hWndNewOwner);
  WINUSERAPI WINBOOL WINAPI CloseClipboard(VOID);
  WINUSERAPI DWORD WINAPI Get_Clipboard_Sequence_सङ्ख्या(VOID);
  WINUSERAPI HWND WINAPI GetClipboardOwner(VOID);
  WINUSERAPI HWND WINAPI समुच्चयः_Clipboard_Viewer(HWND hWndNewViewer);
  WINUSERAPI HWND WINAPI GetClipboardViewer(VOID);
  WINUSERAPI WINBOOL WINAPI ChangeClipboardChain(HWND hWndRemove,HWND h_Wnd_New_अग्र);
  WINUSERAPI HANDLE WINAPI समुच्चयः_Clipboard_दत्त(UINT uFormat,HANDLE hMem);
  WINUSERAPI HANDLE WINAPI Get_Clipboard_दत्त(UINT uFormat);
  WINUSERAPI UINT WINAPI पञ्जिकाकोशः_Clipboard_Format_A(LPCSTR lpszFormat);
  WINUSERAPI UINT WINAPI पञ्जिकाकोशः_Clipboard_Format_W(LPCWSTR lpszFormat);
  WINUSERAPI पूर्णाङ्क WINAPI गणनम्_Clipboard_Formats(VOID);
  WINUSERAPI UINT WINAPI EnumClipboardFormats(UINT format);
  WINUSERAPI पूर्णाङ्क WINAPI GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,पूर्णाङ्क cch_Max_गणनम्);
  WINUSERAPI पूर्णाङ्क WINAPI GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,पूर्णाङ्क cch_Max_गणनम्);
  WINUSERAPI WINBOOL WINAPI रिक्तानि_Clipboard(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Clipboard_Format_उपलब्धम्(UINT format);
  WINUSERAPI पूर्णाङ्क WINAPI Get_प्राथमिकता_Clipboard_Format(UINT *pa_Format_प्राथमिकता_List,पूर्णाङ्क cFormats);
  WINUSERAPI HWND WINAPI Get_Open_Clipboard_गवाक्षः(VOID);
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय Char_गन्तव्यम्_Oem Char_गन्तव्यम्_Oem_W
#परिभाषय Oem_गन्तव्यम्_Char Oem_गन्तव्यम्_Char_W
#परिभाषय Char_गन्तव्यम्_Oem_Buff Char_गन्तव्यम्_Oem_Buff_W
#परिभाषय Oem_गन्तव्यम्_Char_Buff Oem_गन्तव्यम्_Char_Buff_W
#परिभाषय Char_ऊर्ध्वस्थम् Char_ऊर्ध्वस्थम्_W
#परिभाषय Char_ऊर्ध्वस्थम्_Buff Char_ऊर्ध्वस्थम्_Buff_W
#परिभाषय Char_अधस्तनम् Char_अधस्तनम्_W
#परिभाषय Char_अधस्तनम्_Buff Char_अधस्तनम्_Buff_W
#परिभाषय Char_अग्र Char_अग्र_W
#परिभाषय Char_पूर्व Char_पूर्व_W
#अन्यथा
#परिभाषय Char_गन्तव्यम्_Oem Char_गन्तव्यम्_Oem_A
#परिभाषय Oem_गन्तव्यम्_Char Oem_गन्तव्यम्_Char_A
#परिभाषय Char_गन्तव्यम्_Oem_Buff Char_गन्तव्यम्_Oem_Buff_A
#परिभाषय Oem_गन्तव्यम्_Char_Buff Oem_गन्तव्यम्_Char_Buff_A
#परिभाषय Char_ऊर्ध्वस्थम् Char_ऊर्ध्वस्थम्_A
#परिभाषय Char_ऊर्ध्वस्थम्_Buff Char_ऊर्ध्वस्थम्_Buff_A
#परिभाषय Char_अधस्तनम् Char_अधस्तनम्_A
#परिभाषय Char_अधस्तनम्_Buff Char_अधस्तनम्_Buff_A
#परिभाषय Char_अग्र Char_अग्र_A
#परिभाषय Char_पूर्व Char_पूर्व_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI Char_गन्तव्यम्_Oem_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_गन्तव्यम्_Oem_W(LPCWSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_गन्तव्यम्_Char_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_गन्तव्यम्_Char_W(LPCSTR lpszSrc,LPWSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_गन्तव्यम्_Oem_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_दीर्घता);
  WINUSERAPI WINBOOL WINAPI Char_गन्तव्यम्_Oem_Buff_W(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_दीर्घता);
  WINUSERAPI WINBOOL WINAPI Oem_गन्तव्यम्_Char_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_दीर्घता);
  WINUSERAPI WINBOOL WINAPI Oem_गन्तव्यम्_Char_Buff_W(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cch_Dst_दीर्घता);
  WINUSERAPI LPSTR WINAPI Char_ऊर्ध्वस्थम्_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ऊर्ध्वस्थम्_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_ऊर्ध्वस्थम्_Buff_A(LPSTR lpsz,DWORD cch_दीर्घता);
  WINUSERAPI DWORD WINAPI Char_ऊर्ध्वस्थम्_Buff_W(LPWSTR lpsz,DWORD cch_दीर्घता);
  WINUSERAPI LPSTR WINAPI Char_अधस्तनम्_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_अधस्तनम्_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_अधस्तनम्_Buff_A(LPSTR lpsz,DWORD cch_दीर्घता);
  WINUSERAPI DWORD WINAPI Char_अधस्तनम्_Buff_W(LPWSTR lpsz,DWORD cch_दीर्घता);
  WINUSERAPI LPSTR WINAPI Char_अग्र_A(LPCSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_अग्र_W(LPCWSTR lpsz);
  WINUSERAPI LPSTR WINAPI Char_पूर्व_A(LPCSTR lpszStart,LPCSTR lpszCurrent);
  WINUSERAPI LPWSTR WINAPI Char_पूर्व_W(LPCWSTR lpszStart,LPCWSTR lpszCurrent);
  WINUSERAPI LPSTR WINAPI Char_अग्र_Ex_A(WORD संहिता_Page,LPCSTR lpCurrentChar,DWORD dwFlags);
  WINUSERAPI LPSTR WINAPI Char_पूर्व_Ex_A(WORD संहिता_Page,LPCSTR lpStart,LPCSTR lpCurrentChar,DWORD dwFlags);

#परिभाषय Ansi_गन्तव्यम्_Oem Char_गन्तव्यम्_Oem_A
#परिभाषय Oem_गन्तव्यम्_Ansi Oem_गन्तव्यम्_Char_A
#परिभाषय Ansi_गन्तव्यम्_Oem_Buff Char_गन्तव्यम्_Oem_Buff_A
#परिभाषय Oem_गन्तव्यम्_Ansi_Buff Oem_गन्तव्यम्_Char_Buff_A
#परिभाषय Ansi_ऊर्ध्वस्थम् Char_ऊर्ध्वस्थम्_A
#परिभाषय Ansi_ऊर्ध्वस्थम्_Buff Char_ऊर्ध्वस्थम्_Buff_A
#परिभाषय Ansi_अधस्तनम् Char_अधस्तनम्_A
#परिभाषय Ansi_अधस्तनम्_Buff Char_अधस्तनम्_Buff_A
#परिभाषय Ansi_अग्र Char_अग्र_A
#परिभाषय Ansi_पूर्व Char_पूर्व_A

#यदि_अपरिभाषितम् NOLANGUAGE

#यदि_परिभाषितम् UNICODE
#परिभाषय IsCharAlpha IsCharAlphaW
#परिभाषय IsCharAlphaNumeric IsCharAlphaNumericW
#परिभाषय Is_Char_ऊर्ध्वस्थम् Is_Char_ऊर्ध्वस्थम्_W
#परिभाषय Is_Char_अधस्तनम् Is_Char_अधस्तनम्_W
#अन्यथा
#परिभाषय IsCharAlpha IsCharAlphaA
#परिभाषय IsCharAlphaNumeric IsCharAlphaNumericA
#परिभाषय Is_Char_ऊर्ध्वस्थम् Is_Char_ऊर्ध्वस्थम्_A
#परिभाषय Is_Char_अधस्तनम् Is_Char_अधस्तनम्_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI IsCharAlphaA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ऊर्ध्वस्थम्_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ऊर्ध्वस्थम्_W(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_अधस्तनम्_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_अधस्तनम्_W(WCHAR ch);
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय Get_कुञ्चिका_Name_Text Get_कुञ्चिका_Name_Text_W
#परिभाषय Vk_कुञ्चिका_अवलोकनम् Vk_कुञ्चिका_अवलोकनम्_W
#परिभाषय Vk_कुञ्चिका_अवलोकनम्_Ex Vk_कुञ्चिका_अवलोकनम्_Ex_W
#अन्यथा
#परिभाषय Get_कुञ्चिका_Name_Text Get_कुञ्चिका_Name_Text_A
#परिभाषय Vk_कुञ्चिका_अवलोकनम् Vk_कुञ्चिका_अवलोकनम्_A
#परिभाषय Vk_कुञ्चिका_अवलोकनम्_Ex Vk_कुञ्चिका_अवलोकनम्_Ex_A
#यदि_अन्तः

  WINUSERAPI HWND WINAPI समुच्चयः_Focus(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_सक्रिय_गवाक्षः(VOID);
  WINUSERAPI HWND WINAPI GetFocus(VOID);
  WINUSERAPI UINT WINAPI GetKBCodePage(VOID);
  WINUSERAPI SHORT WINAPI Get_कुञ्चिका_State(पूर्णाङ्क n_Virt_कुञ्चिका);
  WINUSERAPI SHORT WINAPI Get_Async_कुञ्चिका_State(पूर्णाङ्क v_कुञ्चिका);
  WINUSERAPI WINBOOL WINAPI GetKeyboardState(PBYTE lp_कुञ्चिका_State);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Keyboard_State(LPBYTE lp_कुञ्चिका_State);
  WINUSERAPI पूर्णाङ्क WINAPI Get_कुञ्चिका_Name_Text_A(LONG lParam,LPSTR lpString,पूर्णाङ्क cch_आकार);
  WINUSERAPI पूर्णाङ्क WINAPI Get_कुञ्चिका_Name_Text_W(LONG lParam,LPWSTR lpString,पूर्णाङ्क cch_आकार);
  WINUSERAPI पूर्णाङ्क WINAPI GetKeyboardType(पूर्णाङ्क nTypeFlag);
  WINUSERAPI पूर्णाङ्क WINAPI गन्तव्यम्_Ascii(UINT u_Virt_कुञ्चिका,UINT u_अवलोकनम्_संहिता,CONST BYTE *lp_कुञ्चिका_State,LPWORD lpChar,UINT uFlags);
  WINUSERAPI पूर्णाङ्क WINAPI गन्तव्यम्_Ascii_Ex(UINT u_Virt_कुञ्चिका,UINT u_अवलोकनम्_संहिता,CONST BYTE *lp_कुञ्चिका_State,LPWORD lpChar,UINT uFlags,HKL dwhkl);
  WINUSERAPI पूर्णाङ्क WINAPI गन्तव्यम्_Unicode(UINT w_Virt_कुञ्चिका,UINT w_अवलोकनम्_संहिता,CONST BYTE *lp_कुञ्चिका_State,LPWSTR pwszBuff,पूर्णाङ्क cchBuff,UINT wFlags);
  WINUSERAPI DWORD WINAPI Oem_कुञ्चिका_अवलोकनम्(WORD wOemChar);
  WINUSERAPI SHORT WINAPI Vk_कुञ्चिका_अवलोकनम्_A(CHAR ch);
  WINUSERAPI SHORT WINAPI Vk_कुञ्चिका_अवलोकनम्_W(WCHAR ch);
  WINUSERAPI SHORT WINAPI Vk_कुञ्चिका_अवलोकनम्_Ex_A(CHAR ch,HKL dwhkl);
  WINUSERAPI SHORT WINAPI Vk_कुञ्चिका_अवलोकनम्_Ex_W(WCHAR ch,HKL dwhkl);

#परिभाषय KEYEVENTF_EXTENDEDKEY 0x0001
#परिभाषय KEYEVENTF_KEYUP 0x0002
#परिभाषय KEYEVENTF_UNICODE 0x0004
#परिभाषय KEYEVENTF_SCANCODE 0x0008

  WINUSERAPI VOID WINAPI keybd_event(BYTE bVk,BYTE b_अवलोकनम्,DWORD dwFlags,ULONG_PTR dwExtraInfo);

#परिभाषय MOUSEEVENTF_MOVE 0x0001
#परिभाषय MOUSEEVENTF_LEFTDOWN 0x0002
#परिभाषय MOUSEEVENTF_LEFTUP 0x0004
#परिभाषय MOUSEEVENTF_RIGHTDOWN 0x0008
#परिभाषय MOUSEEVENTF_RIGHTUP 0x0010
#परिभाषय MOUSEEVENTF_MIDDLEDOWN 0x0020
#परिभाषय MOUSEEVENTF_MIDDLEUP 0x0040
#परिभाषय MOUSEEVENTF_XDOWN 0x0080
#परिभाषय MOUSEEVENTF_XUP 0x0100
#परिभाषय MOUSEEVENTF_WHEEL 0x0800
#परिभाषय MOUSEEVENTF_VIRTUALDESK 0x4000
#परिभाषय MOUSEEVENTF_ABSOLUTE 0x8000

  WINUSERAPI VOID WINAPI mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dw_दत्त,ULONG_PTR dwExtraInfo);

  प्रकारनिर्देश संरचना चिह्नकम्_MOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouse_दत्त;
    DWORD dwFlags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } MOUSEINPUT,*PMOUSEINPUT,*LPMOUSEINPUT;

  प्रकारनिर्देश संरचना चिह्नकम्_KEYBDINPUT {
    WORD wVk;
    WORD w_अवलोकनम्;
    DWORD dwFlags;
    DWORD time;
    ULONG_PTR dwExtraInfo;
  } KEYBDINPUT,*PKEYBDINPUT,*LPKEYBDINPUT;

  प्रकारनिर्देश संरचना चिह्नकम्_HARDWAREINPUT {
    DWORD u_सन्देशः;
    WORD wParamL;
    WORD wParamH;
  } HARDWAREINPUT,*PHARDWAREINPUT,*LPHARDWAREINPUT;

#परिभाषय निवेशः_MOUSE 0
#परिभाषय निवेशः_KEYBOARD 1
#परिभाषय निवेशः_HARDWARE 2

  प्रकारनिर्देश संरचना चिह्नकम्_निवेशः {
    DWORD type;
    सङ्घ {
      MOUSEINPUT mi;
      KEYBDINPUT ki;
      HARDWAREINPUT hi;
    };
  } निवेशः_2,*PINPUT,*LPINPUT;

  WINUSERAPI UINT WINAPI Send_निवेशः(UINT cInputs,LPINPUT pInputs,पूर्णाङ्क cb_आकार);

  प्रकारनिर्देश संरचना चिह्नकम्_LASTINPUTINFO {
    UINT cb_आकार;
    DWORD dwTime;
  } LASTINPUTINFO,*PLASTINPUTINFO;

#यदि_परिभाषितम् UNICODE
#परिभाषय Map_Virtual_कुञ्चिका Map_Virtual_कुञ्चिका_W
#परिभाषय Map_Virtual_कुञ्चिका_Ex Map_Virtual_कुञ्चिका_Ex_W
#अन्यथा
#परिभाषय Map_Virtual_कुञ्चिका Map_Virtual_कुञ्चिका_A
#परिभाषय Map_Virtual_कुञ्चिका_Ex Map_Virtual_कुञ्चिका_Ex_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI Get_चरमः_निवेशः_Info(PLASTINPUTINFO plii);
  WINUSERAPI UINT WINAPI Map_Virtual_कुञ्चिका_A(UINT u_संहिता,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_कुञ्चिका_W(UINT u_संहिता,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_कुञ्चिका_Ex_A(UINT u_संहिता,UINT uMapType,HKL dwhkl);
  WINUSERAPI UINT WINAPI Map_Virtual_कुञ्चिका_Ex_W(UINT u_संहिता,UINT uMapType,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI Get_निवेशः_State(VOID);
  WINUSERAPI DWORD WINAPI Get_Queue_स्थितिः(UINT flags);
  WINUSERAPI HWND WINAPI GetCapture(VOID);
  WINUSERAPI HWND WINAPI समुच्चयः_Capture(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ReleaseCapture(VOID);
  WINUSERAPI DWORD WINAPI सन्देशः_Wait_For_गुणजः_Objects(DWORD n_गणनम्,CONST HANDLE *pHandles,WINBOOL fWaitAll,DWORD dwMilliseconds,DWORD dw_Wake_आवरणम्);
  WINUSERAPI DWORD WINAPI सन्देशः_Wait_For_गुणजः_Objects_Ex(DWORD n_गणनम्,CONST HANDLE *pHandles,DWORD dwMilliseconds,DWORD dw_Wake_आवरणम्,DWORD dwFlags);

#परिभाषय MWMO_WAITALL 0x0001
#परिभाषय MWMO_ALERTABLE 0x0002
#परिभाषय MWMO_INPUTAVAILABLE 0x0004

#परिभाषय QS_कुञ्चिका 0x0001
#परिभाषय QS_MOUSEMOVE 0x0002
#परिभाषय QS_MOUSEBUTTON 0x0004
#परिभाषय QS_POSTMESSAGE 0x0008
#परिभाषय QS_TIMER 0x0010
#परिभाषय QS_PAINT 0x0020
#परिभाषय QS_SENDMESSAGE 0x0040
#परिभाषय QS_HOTKEY 0x0080
#परिभाषय QS_ALLPOSTMESSAGE 0x0100
#परिभाषय QS_RAWINPUT 0x0400
#परिभाषय QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#परिभाषय QS_निवेशः (QS_MOUSE | QS_कुञ्चिका | QS_RAWINPUT)
#परिभाषय QS_ALLEVENTS (QS_निवेशः | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#परिभाषय QS_ALLINPUT (QS_निवेशः | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#परिभाषय USER_TIMER_अधिकतमम् 0x7FFFFFFF
#परिभाषय USER_TIMER_MINIMUM 0x0000000A

#यदि_परिभाषितम् UNICODE
#परिभाषय आरोपय_Accelerators आरोपय_Accelerators_W
#परिभाषय Create_Accelerator_सारणी Create_Accelerator_सारणी_W
#परिभाषय Copy_Accelerator_सारणी Copy_Accelerator_सारणी_W
#अन्यथा
#परिभाषय आरोपय_Accelerators आरोपय_Accelerators_A
#परिभाषय Create_Accelerator_सारणी Create_Accelerator_सारणी_A
#परिभाषय Copy_Accelerator_सारणी Copy_Accelerator_सारणी_A
#यदि_अन्तः

  WINUSERAPI UINT_PTR WINAPI समुच्चयः_Timer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
  WINUSERAPI WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);
  WINUSERAPI WINBOOL WINAPI Is_गवाक्षः_Unicode(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Enable_गवाक्षः(HWND hWnd,WINBOOL bEnable);
  WINUSERAPI WINBOOL WINAPI Is_गवाक्षः_Enabled(HWND hWnd);
  WINUSERAPI HACCEL WINAPI आरोपय_Accelerators_A(HINSTANCE hInstance,LPCSTR lp_सारणी_Name);
  WINUSERAPI HACCEL WINAPI आरोपय_Accelerators_W(HINSTANCE hInstance,LPCWSTR lp_सारणी_Name);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_सारणी_A(LPACCEL paccel,पूर्णाङ्क cAccel);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_सारणी_W(LPACCEL paccel,पूर्णाङ्क cAccel);
  WINUSERAPI WINBOOL WINAPI Destroy_Accelerator_सारणी(HACCEL hAccel);
  WINUSERAPI पूर्णाङ्क WINAPI Copy_Accelerator_सारणी_A(HACCEL hAccelSrc,LPACCEL lpAccelDst,पूर्णाङ्क cAccelEntries);
  WINUSERAPI पूर्णाङ्क WINAPI Copy_Accelerator_सारणी_W(HACCEL hAccelSrc,LPACCEL lpAccelDst,पूर्णाङ्क cAccelEntries);

#यदि_अपरिभाषितम् NOMSG

#यदि_परिभाषितम् UNICODE
#परिभाषय TranslateAccelerator TranslateAcceleratorW
#अन्यथा
#परिभाषय TranslateAccelerator TranslateAcceleratorA
#यदि_अन्तः

  WINUSERAPI पूर्णाङ्क WINAPI TranslateAcceleratorA(HWND hWnd,HACCEL h_Acc_सारणी,LPMSG lp_सन्देशः_2);
  WINUSERAPI पूर्णाङ्क WINAPI TranslateAcceleratorW(HWND hWnd,HACCEL h_Acc_सारणी,LPMSG lp_सन्देशः_2);
#यदि_अन्तः

#यदि_अपरिभाषितम् NOSYSMETRICS

#परिभाषय SM_CXSCREEN 0
#परिभाषय SM_CYSCREEN 1
#परिभाषय SM_CXVSCROLL 2
#परिभाषय SM_CYHSCROLL 3
#परिभाषय SM_CYCAPTION 4
#परिभाषय SM_CXBORDER 5
#परिभाषय SM_CYBORDER 6
#परिभाषय SM_CXDLGFRAME 7
#परिभाषय SM_CYDLGFRAME 8
#परिभाषय SM_CYVTHUMB 9
#परिभाषय SM_CXHTHUMB 10
#परिभाषय SM_CXICON 11
#परिभाषय SM_CYICON 12
#परिभाषय SM_CXCURSOR 13
#परिभाषय SM_CYCURSOR 14
#परिभाषय SM_CYMENU 15
#परिभाषय SM_CXFULLSCREEN 16
#परिभाषय SM_CYFULLSCREEN 17
#परिभाषय SM_CYKANJIWINDOW 18
#परिभाषय SM_MOUSEPRESENT 19
#परिभाषय SM_CYVSCROLL 20
#परिभाषय SM_CXHSCROLL 21
#परिभाषय SM_DEBUG 22
#परिभाषय SM_SWAPBUTTON 23
#परिभाषय SM_RESERVED1 24
#परिभाषय SM_RESERVED2 25
#परिभाषय SM_RESERVED3 26
#परिभाषय SM_RESERVED4 27
#परिभाषय SM_CXMIN 28
#परिभाषय SM_CYMIN 29
#परिभाषय SM_CXSIZE 30
#परिभाषय SM_CYSIZE 31
#परिभाषय SM_CXFRAME 32
#परिभाषय SM_CYFRAME 33
#परिभाषय SM_CXMINTRACK 34
#परिभाषय SM_CYMINTRACK 35
#परिभाषय SM_CXDOUBLECLK 36
#परिभाषय SM_CYDOUBLECLK 37
#परिभाषय SM_CXICONSPACING 38
#परिभाषय SM_CYICONSPACING 39
#परिभाषय SM_MENUDROPALIGNMENT 40
#परिभाषय SM_PENWINDOWS 41
#परिभाषय SM_DBCSENABLED 42
#परिभाषय SM_CMOUSEBUTTONS 43

#परिभाषय SM_CXFIXEDFRAME SM_CXDLGFRAME
#परिभाषय SM_CYFIXEDFRAME SM_CYDLGFRAME
#परिभाषय SM_CXSIZEFRAME SM_CXFRAME
#परिभाषय SM_CYSIZEFRAME SM_CYFRAME

#परिभाषय SM_SECURE 44
#परिभाषय SM_CXEDGE 45
#परिभाषय SM_CYEDGE 46
#परिभाषय SM_CXMINSPACING 47
#परिभाषय SM_CYMINSPACING 48
#परिभाषय SM_CXSMICON 49
#परिभाषय SM_CYSMICON 50
#परिभाषय SM_CYSMCAPTION 51
#परिभाषय SM_CXSMSIZE 52
#परिभाषय SM_CYSMSIZE 53
#परिभाषय SM_CXMENUSIZE 54
#परिभाषय SM_CYMENUSIZE 55
#परिभाषय SM_ARRANGE 56
#परिभाषय SM_CXMINIMIZED 57
#परिभाषय SM_CYMINIMIZED 58
#परिभाषय SM_CXMAXTRACK 59
#परिभाषय SM_CYMAXTRACK 60
#परिभाषय SM_CXMAXIMIZED 61
#परिभाषय SM_CYMAXIMIZED 62
#परिभाषय SM_जालम् 63
#परिभाषय SM_CLEANBOOT 67
#परिभाषय SM_CXDRAG 68
#परिभाषय SM_CYDRAG 69
#परिभाषय SM_SHOWSOUNDS 70
#परिभाषय SM_CXMENUCHECK 71
#परिभाषय SM_CYMENUCHECK 72
#परिभाषय SM_SLOWMACHINE 73
#परिभाषय SM_MIDEASTENABLED 74
#परिभाषय SM_MOUSEWHEELPRESENT 75
#परिभाषय SM_XVIRTUALSCREEN 76
#परिभाषय SM_YVIRTUALSCREEN 77
#परिभाषय SM_CXVIRTUALSCREEN 78
#परिभाषय SM_CYVIRTUALSCREEN 79
#परिभाषय SM_CMONITORS 80
#परिभाषय SM_SAMEDISPLAYFORMAT 81
#परिभाषय SM_IMMENABLED 82
#परिभाषय SM_CXFOCUSBORDER 83
#परिभाषय SM_CYFOCUSBORDER 84
#परिभाषय SM_TABLETPC 86
#परिभाषय SM_MEDIACENTER 87
#परिभाषय SM_STARTER 88
#परिभाषय SM_SERVERR2 89
#परिभाषय SM_CMETRICS 90
#परिभाषय SM_REMOTESESSION 0x1000
#परिभाषय SM_SHUTTINGDOWN 0x2000
#परिभाषय SM_REMOTECONTROL 0x2001
#परिभाषय SM_CARETBLINKINGENABLED 0x2002

  WINUSERAPI पूर्णाङ्क WINAPI GetSystemMetrics(पूर्णाङ्क n_सूचकांक);
#यदि_अन्तः

#यदि_अपरिभाषितम् NOMENUS

#यदि_परिभाषितम् UNICODE
#परिभाषय आरोपय_Menu आरोपय_Menu_W
#परिभाषय आरोपय_Menu_परोक्षम् आरोपय_Menu_परोक्षम्_W
#परिभाषय ChangeMenu ChangeMenuW
#परिभाषय GetMenuString GetMenuStringW
#परिभाषय निवेशय_Menu निवेशय_Menu_W
#परिभाषय AppendMenu AppendMenuW
#परिभाषय ModifyMenu ModifyMenuW
#अन्यथा
#परिभाषय आरोपय_Menu आरोपय_Menu_A
#परिभाषय आरोपय_Menu_परोक्षम् आरोपय_Menu_परोक्षम्_A
#परिभाषय ChangeMenu ChangeMenuA
#परिभाषय GetMenuString GetMenuStringA
#परिभाषय निवेशय_Menu निवेशय_Menu_A
#परिभाषय AppendMenu AppendMenuA
#परिभाषय ModifyMenu ModifyMenuA
#यदि_अन्तः

  WINUSERAPI HMENU WINAPI आरोपय_Menu_A(HINSTANCE hInstance,LPCSTR lpMenuName);
  WINUSERAPI HMENU WINAPI आरोपय_Menu_W(HINSTANCE hInstance,LPCWSTR lpMenuName);
  WINUSERAPI HMENU WINAPI आरोपय_Menu_परोक्षम्_A(CONST MENUTEMPLATEA *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI आरोपय_Menu_परोक्षम्_W(CONST MENUTEMPLATEW *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI GetMenu(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Menu(HWND hWnd,HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpszNewItem,UINT cmd_निवेशय,UINT flags);
  WINUSERAPI WINBOOL WINAPI ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpszNewItem,UINT cmd_निवेशय,UINT flags);
  WINUSERAPI WINBOOL WINAPI HiliteMenuItem(HWND hWnd,HMENU hMenu,UINT uIDHiliteItem,UINT uHilite);
  WINUSERAPI पूर्णाङ्क WINAPI GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,पूर्णाङ्क cchMax,UINT flags);
  WINUSERAPI पूर्णाङ्क WINAPI GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,पूर्णाङ्क cchMax,UINT flags);
  WINUSERAPI UINT WINAPI GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawMenuBar(HWND hWnd);

#परिभाषय PMB_सक्रिय 0x00000001

  WINUSERAPI HMENU WINAPI GetSystemMenu(HWND hWnd,WINBOOL bRevert);
  WINUSERAPI HMENU WINAPI CreateMenu(VOID);
  WINUSERAPI HMENU WINAPI CreatePopupMenu(VOID);
  WINUSERAPI WINBOOL WINAPI DestroyMenu(HMENU hMenu);
  WINUSERAPI DWORD WINAPI CheckMenuItem(HMENU hMenu,UINT uIDCheckItem,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI EnableMenuItem(HMENU hMenu,UINT uIDEnableItem,UINT uEnable);
  WINUSERAPI HMENU WINAPI GetSubMenu(HMENU hMenu,पूर्णाङ्क nPos);
  WINUSERAPI UINT WINAPI GetMenuItemID(HMENU hMenu,पूर्णाङ्क nPos);
  WINUSERAPI पूर्णाङ्क WINAPI Get_Menu_Item_गणनम्(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI निवेशय_Menu_A(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI निवेशय_Menu_W(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR uIDNewItem,LPCWSTR lpNewItem);
  WINUSERAPI WINBOOL WINAPI RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Menu_Item_Bitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
  WINUSERAPI LONG WINAPI GetMenuCheckMarkDimensions(VOID);
  WINUSERAPI WINBOOL WINAPI TrackPopupMenu(HMENU hMenu,UINT uFlags,पूर्णाङ्क x,पूर्णाङ्क y,पूर्णाङ्क nReserved,HWND hWnd,CONST RECT *prcRect);

#परिभाषय MNC_IGNORE 0
#परिभाषय MNC_CLOSE 1
#परिभाषय MNC_EXECUTE 2
#परिभाषय MNC_SELECT 3

  प्रकारनिर्देश संरचना चिह्नकम्_TPMPARAMS {
    UINT cb_आकार;
    RECT rcExclude;
  } TPMPARAMS;

  प्रकारनिर्देश TPMPARAMS *LPTPMPARAMS;

  WINUSERAPI WINBOOL WINAPI TrackPopupMenuEx(HMENU,UINT,पूर्णाङ्क,पूर्णाङ्क,HWND,LPTPMPARAMS);

#परिभाषय MNS_NOCHECK 0x80000000
#परिभाषय MNS_MODELESS 0x40000000
#परिभाषय MNS_DRAGDROP 0x20000000
#परिभाषय MNS_AUTODISMISS 0x10000000
#परिभाषय MNS_NOTIFYBYPOS 0x08000000
#परिभाषय MNS_CHECKORBMP 0x04000000

#परिभाषय MIM_MAXHEIGHT 0x00000001
#परिभाषय MIM_BACKGROUND 0x00000002
#परिभाषय MIM_HELPID 0x00000004
#परिभाषय MIM_MENUDATA 0x00000008
#परिभाषय MIM_STYLE 0x00000010
#परिभाषय MIM_APPLYTOSUBMENUS 0x80000000

  प्रकारनिर्देश संरचना चिह्नकम्_MENUINFO {
    DWORD cb_आकार;
    DWORD f_आवरणम्;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbr_पृष्ठभागः;
    DWORD dwContextHelpID;
    ULONG_PTR dw_Menu_दत्त;
  } MENUINFO,*LPMENUINFO;

  प्रकारनिर्देश MENUINFO CONST *LPCMENUINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuInfo(HMENU,LPMENUINFO);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Menu_Info(HMENU,LPCMENUINFO);
  WINUSERAPI WINBOOL WINAPI अन्तः_Menu(VOID);

#परिभाषय MND_CONTINUE 0
#परिभाषय MND_ENDMENU 1

  प्रकारनिर्देश संरचना चिह्नकम्_MENUGETOBJECTINFO {
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
  } MENUGETOBJECTINFO,*PMENUGETOBJECTINFO;

#परिभाषय MNGOF_TOPGAP 0x00000001
#परिभाषय MNGOF_BOTTOMGAP 0x00000002

#परिभाषय MNGO_NOINTERFACE 0x00000000
#परिभाषय MNGO_NOERROR 0x00000001

#परिभाषय MIIM_STATE 0x00000001
#परिभाषय MIIM_ID 0x00000002
#परिभाषय MIIM_SUBMENU 0x00000004
#परिभाषय MIIM_CHECKMARKS 0x00000008
#परिभाषय MIIM_TYPE 0x00000010
#परिभाषय MIIM_दत्त 0x00000020

#परिभाषय MIIM_STRING 0x00000040
#परिभाषय MIIM_BITMAP 0x00000080
#परिभाषय MIIM_FTYPE 0x00000100

#परिभाषय HBMMENU_CALLBACK ((HBITMAP) -1)
#परिभाषय HBMMENU_SYSTEM ((HBITMAP) 1)
#परिभाषय HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#परिभाषय HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#परिभाषय HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#परिभाषय HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#परिभाषय HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#परिभाषय HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#परिभाषय HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#परिभाषय HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#परिभाषय HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

  प्रकारनिर्देश संरचना चिह्नकम्_MENUITEMINFOA {
    UINT cb_आकार;
    UINT f_आवरणम्;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_Item_दत्त;
    LPSTR dw_Type_दत्त;
    UINT cch;
    HBITMAP hbmpItem;
  } MENUITEMINFOA,*LPMENUITEMINFOA;

  प्रकारनिर्देश संरचना चिह्नकम्_MENUITEMINFOW {
    UINT cb_आकार;
    UINT f_आवरणम्;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_Item_दत्त;
    LPWSTR dw_Type_दत्त;
    UINT cch;
    HBITMAP hbmpItem;
  } MENUITEMINFOW,*LPMENUITEMINFOW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश MENUITEMINFOW MENUITEMINFO;
  प्रकारनिर्देश LPMENUITEMINFOW LPMENUITEMINFO;
#अन्यथा
  प्रकारनिर्देश MENUITEMINFOA MENUITEMINFO;
  प्रकारनिर्देश LPMENUITEMINFOA LPMENUITEMINFO;
#यदि_अन्तः
  प्रकारनिर्देश MENUITEMINFOA CONST *LPCMENUITEMINFOA;
  प्रकारनिर्देश MENUITEMINFOW CONST *LPCMENUITEMINFOW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश LPCMENUITEMINFOW LPCMENUITEMINFO;
#अन्यथा
  प्रकारनिर्देश LPCMENUITEMINFOA LPCMENUITEMINFO;
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय निवेशय_Menu_Item निवेशय_Menu_Item_W
#परिभाषय GetMenuItemInfo GetMenuItemInfoW
#परिभाषय समुच्चयः_Menu_Item_Info समुच्चयः_Menu_Item_Info_W
#अन्यथा
#परिभाषय निवेशय_Menu_Item निवेशय_Menu_Item_A
#परिभाषय GetMenuItemInfo GetMenuItemInfoA
#परिभाषय समुच्चयः_Menu_Item_Info समुच्चयः_Menu_Item_Info_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI निवेशय_Menu_Item_A(HMENU hmenu,UINT item,WINBOOL fByPosition,LPCMENUITEMINFOA lpmi);
  WINUSERAPI WINBOOL WINAPI निवेशय_Menu_Item_W(HMENU hmenu,UINT item,WINBOOL fByPosition,LPCMENUITEMINFOW lpmi);
  WINUSERAPI WINBOOL WINAPI GetMenuItemInfoA(HMENU hmenu,UINT item,WINBOOL fByPosition,LPMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI GetMenuItemInfoW(HMENU hmenu,UINT item,WINBOOL fByPosition,LPMENUITEMINFOW lpmii);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Menu_Item_Info_A(HMENU hmenu,UINT item,WINBOOL fByPositon,LPCMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Menu_Item_Info_W(HMENU hmenu,UINT item,WINBOOL fByPositon,LPCMENUITEMINFOW lpmii);

#परिभाषय GMDI_USEDISABLED 0x0001L
#परिभाषय GMDI_GOINTOPOPUPS 0x0002L

  WINUSERAPI UINT WINAPI GetMenuDefaultItem(HMENU hMenu,UINT fByPos,UINT gmdiFlags);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Menu_Default_Item(HMENU hMenu,UINT uItem,UINT fByPos);
  WINUSERAPI WINBOOL WINAPI GetMenuItemRect(HWND hWnd,HMENU hMenu,UINT uItem,LPRECT lprcItem);
  WINUSERAPI पूर्णाङ्क WINAPI MenuItemFromPoint(HWND hWnd,HMENU hMenu,POINT ptScreen);

#परिभाषय TPM_LEFTBUTTON 0x0000L
#परिभाषय TPM_RIGHTBUTTON 0x0002L
#परिभाषय TPM_LEFTALIGN 0x0000L
#परिभाषय TPM_CENTERALIGN 0x0004L
#परिभाषय TPM_RIGHTALIGN 0x0008L
#परिभाषय TPM_TOPALIGN 0x0000L
#परिभाषय TPM_VCENTERALIGN 0x0010L
#परिभाषय TPM_BOTTOMALIGN 0x0020L

#परिभाषय TPM_HORIZONTAL 0x0000L
#परिभाषय TPM_VERTICAL 0x0040L
#परिभाषय TPM_NONOTIFY 0x0080L
#परिभाषय TPM_RETURNCMD 0x0100L
#परिभाषय TPM_RECURSE 0x0001L
#परिभाषय TPM_HORPOSANIMATION 0x0400L
#परिभाषय TPM_HORNEGANIMATION 0x0800L
#परिभाषय TPM_VERPOSANIMATION 0x1000L
#परिभाषय TPM_VERNEGANIMATION 0x2000L
#परिभाषय TPM_NOANIMATION 0x4000L
#परिभाषय TPM_LAYOUTRTL 0x8000L
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_DROPSTRUCT {
    HWND hwndSource;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dw_दत्त;
    POINT ptDrop;
    DWORD dw_Control_दत्त;
  } DROPSTRUCT,*PDROPSTRUCT,*LPDROPSTRUCT;

#परिभाषय DOF_EXECUTABLE 0x8001
#परिभाषय DOF_DOCUMENT 0x8002
#परिभाषय DOF_DIRECTORY 0x8003
#परिभाषय DOF_गुणजः 0x8004
#परिभाषय DOF_PROGMAN 0x0001
#परिभाषय DOF_SHELLDATA 0x0002

#परिभाषय DO_DROPFILE 0x454C4946L
#परिभाषय DO_PRINTFILE 0x544E5250L

  WINUSERAPI DWORD WINAPI DragObject(HWND hwndParent,HWND hwndFrom,UINT fmt,ULONG_PTR दत्त,HCURSOR hcur);
  WINUSERAPI WINBOOL WINAPI DragDetect(HWND hwnd,POINT pt);
  WINUSERAPI WINBOOL WINAPI DrawIcon(HDC hDC,पूर्णाङ्क X,पूर्णाङ्क Y,HICON hIcon);

#यदि_अपरिभाषितम् NODRAWTEXT

#परिभाषय DT_शिखरम् 0x00000000
#परिभाषय DT_वामः 0x00000000
#परिभाषय DT_CENTER 0x00000001
#परिभाषय DT_दक्षिणः 0x00000002
#परिभाषय DT_VCENTER 0x00000004
#परिभाषय DT_BOTTOM 0x00000008
#परिभाषय DT_WORDBREAK 0x00000010
#परिभाषय DT_SINGLELINE 0x00000020
#परिभाषय DT_EXPANDTABS 0x00000040
#परिभाषय DT_TABSTOP 0x00000080
#परिभाषय DT_NOCLIP 0x00000100
#परिभाषय DT_EXTERNALLEADING 0x00000200
#परिभाषय DT_CALCRECT 0x00000400
#परिभाषय DT_NOPREFIX 0x00000800
#परिभाषय DT_आन्तरिकम् 0x00001000

#परिभाषय DT_EDITCONTROL 0x00002000
#परिभाषय DT_मार्गः_ELLIPSIS 0x00004000
#परिभाषय DT_अन्तः_ELLIPSIS 0x00008000
#परिभाषय DT_MODIFYSTRING 0x00010000
#परिभाषय DT_RTLREADING 0x00020000
#परिभाषय DT_WORD_ELLIPSIS 0x00040000
#परिभाषय DT_NOFULLWIDTHCHARBREAK 0x00080000
#परिभाषय DT_HIDEPREFIX 0x00100000
#परिभाषय DT_PREFIXONLY 0x00200000

  प्रकारनिर्देश संरचना चिह्नकम्_DRAWTEXTPARAMS {
    UINT cb_आकार;
    पूर्णाङ्क i_Tab_दीर्घता;
    पूर्णाङ्क i_वामः_Margin;
    पूर्णाङ्क i_दक्षिणः_Margin;
    UINT ui_दीर्घता_Drawn;
  } DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

#यदि_परिभाषितम् UNICODE
#परिभाषय DrawText DrawTextW
#परिभाषय DrawTextEx DrawTextExW
#अन्यथा
#परिभाषय DrawText DrawTextA
#परिभाषय DrawTextEx DrawTextExA
#यदि_अन्तः

  WINUSERAPI पूर्णाङ्क WINAPI DrawTextA(HDC hdc,LPCSTR lpchText,पूर्णाङ्क cchText,LPRECT lprc,UINT format);
  WINUSERAPI पूर्णाङ्क WINAPI DrawTextW(HDC hdc,LPCWSTR lpchText,पूर्णाङ्क cchText,LPRECT lprc,UINT format);
  WINUSERAPI पूर्णाङ्क WINAPI DrawTextExA(HDC hdc,LPSTR lpchText,पूर्णाङ्क cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
  WINUSERAPI पूर्णाङ्क WINAPI DrawTextExW(HDC hdc,LPWSTR lpchText,पूर्णाङ्क cchText,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय GrayString GrayStringW
#परिभाषय DrawState DrawStateW
#परिभाषय Tabbed_Text_बहिर्गमनम् Tabbed_Text_बहिर्गमनम्_W
#परिभाषय GetTabbedTextExtent GetTabbedTextExtentW
#अन्यथा
#परिभाषय GrayString GrayStringA
#परिभाषय DrawState DrawStateA
#परिभाषय Tabbed_Text_बहिर्गमनम् Tabbed_Text_बहिर्गमनम्_A
#परिभाषय GetTabbedTextExtent GetTabbedTextExtentA
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI GrayStringA(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_दत्त,पूर्णाङ्क n_गणनम्,पूर्णाङ्क X,पूर्णाङ्क Y,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight);
  WINUSERAPI WINBOOL WINAPI GrayStringW(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_दत्त,पूर्णाङ्क n_गणनम्,पूर्णाङ्क X,पूर्णाङ्क Y,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight);

#परिभाषय DST_COMPLEX 0x0000
#परिभाषय DST_TEXT 0x0001
#परिभाषय DST_PREFIXTEXT 0x0002
#परिभाषय DST_ICON 0x0003
#परिभाषय DST_BITMAP 0x0004

#परिभाषय DSS_प्रसामान्यम् 0x0000
#परिभाषय DSS_UNION 0x0010
#परिभाषय DSS_DISABLED 0x0020
#परिभाषय DSS_MONO 0x0080
#परिभाषय DSS_HIDEPREFIX 0x0200
#परिभाषय DSS_PREFIXONLY 0x0400
#परिभाषय DSS_दक्षिणः 0x8000

  WINUSERAPI WINBOOL WINAPI DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_पृष्ठभागः,LPARAM l_दत्त,WPARAM w_दत्त,पूर्णाङ्क x,पूर्णाङ्क y,पूर्णाङ्क cx,पूर्णाङ्क cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_पृष्ठभागः,LPARAM l_दत्त,WPARAM w_दत्त,पूर्णाङ्क x,पूर्णाङ्क y,पूर्णाङ्क cx,पूर्णाङ्क cy,UINT uFlags);
  WINUSERAPI LONG WINAPI Tabbed_Text_बहिर्गमनम्_A(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPCSTR lpString,पूर्णाङ्क ch_गणनम्,पूर्णाङ्क nTabPositions,CONST INT *lpnTabStopPositions,पूर्णाङ्क nTabOrigin);
  WINUSERAPI LONG WINAPI Tabbed_Text_बहिर्गमनम्_W(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPCWSTR lpString,पूर्णाङ्क ch_गणनम्,पूर्णाङ्क nTabPositions,CONST INT *lpnTabStopPositions,पूर्णाङ्क nTabOrigin);
  WINUSERAPI DWORD WINAPI GetTabbedTextExtentA(HDC hdc,LPCSTR lpString,पूर्णाङ्क ch_गणनम्,पूर्णाङ्क nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI DWORD WINAPI GetTabbedTextExtentW(HDC hdc,LPCWSTR lpString,पूर्णाङ्क ch_गणनम्,पूर्णाङ्क nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI WINBOOL WINAPI Update_गवाक्षः(HWND hWnd);
  WINUSERAPI HWND WINAPI समुच्चयः_सक्रिय_गवाक्षः(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_Foreground_गवाक्षः(VOID);
  WINUSERAPI WINBOOL WINAPI PaintDesktop(HDC hdc);
  WINUSERAPI VOID WINAPI Switch_गन्तव्यम्_This_गवाक्षः(HWND hwnd,WINBOOL fUnknown);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Foreground_गवाक्षः(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Allow_समुच्चयः_Foreground_गवाक्षः(DWORD dwProcessId);

#परिभाषय ASFW_ANY ((DWORD)-1)

  WINUSERAPI WINBOOL WINAPI तालकम्_समुच्चयः_Foreground_गवाक्षः(UINT u_तालकम्_संहिता);

#परिभाषय LSFW_तालकम् 1
#परिभाषय LSFW_UNLOCK 2

  WINUSERAPI HWND WINAPI गवाक्षः_From_DC(HDC hDC);
  WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
  WINUSERAPI HDC WINAPI GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags);

#परिभाषय DCX_गवाक्षः 0x00000001L
#परिभाषय DCX_CACHE 0x00000002L
#परिभाषय DCX_NORESETATTRS 0x00000004L
#परिभाषय DCX_CLIPCHILDREN 0x00000008L
#परिभाषय DCX_CLIPSIBLINGS 0x00000010L
#परिभाषय DCX_PARENTCLIP 0x00000020L
#परिभाषय DCX_EXCLUDERGN 0x00000040L
#परिभाषय DCX_INTERSECTRGN 0x00000080L
#परिभाषय DCX_EXCLUDEUPDATE 0x00000100L
#परिभाषय DCX_INTERSECTUPDATE 0x00000200L
#परिभाषय DCX_LOCKWINDOWUPDATE 0x00000400L

#परिभाषय DCX_VALIDATE 0x00200000L

  WINUSERAPI HDC WINAPI Get_गवाक्षः_DC(HWND hWnd);
  WINUSERAPI पूर्णाङ्क WINAPI ReleaseDC(HWND hWnd,HDC hDC);
  WINUSERAPI HDC WINAPI BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
  WINUSERAPI WINBOOL WINAPI अन्तः_Paint(HWND hWnd,CONST PAINTSTRUCT *lpPaint);
  WINUSERAPI WINBOOL WINAPI GetUpdateRect(HWND hWnd,LPRECT lpRect,WINBOOL bErase);
  WINUSERAPI पूर्णाङ्क WINAPI GetUpdateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI पूर्णाङ्क WINAPI समुच्चयः_गवाक्षः_Rgn(HWND hWnd,HRGN hRgn,WINBOOL bRedraw);
  WINUSERAPI पूर्णाङ्क WINAPI Get_गवाक्षः_Rgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI पूर्णाङ्क WINAPI Get_गवाक्षः_Rgn_Box(HWND hWnd,LPRECT lprc);
  WINUSERAPI पूर्णाङ्क WINAPI ExcludeUpdateRgn(HDC hDC,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI InvalidateRect(HWND hWnd,CONST RECT *lpRect,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRect(HWND hWnd,CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI InvalidateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI WINBOOL WINAPI Redraw_गवाक्षः(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#परिभाषय RDW_INVALIDATE 0x0001
#परिभाषय RDW_INTERNALPAINT 0x0002
#परिभाषय RDW_ERASE 0x0004

#परिभाषय RDW_VALIDATE 0x0008
#परिभाषय RDW_NOINTERNALPAINT 0x0010
#परिभाषय RDW_NOERASE 0x0020

#परिभाषय RDW_NOCHILDREN 0x0040
#परिभाषय RDW_ALLCHILDREN 0x0080

#परिभाषय RDW_UPDATENOW 0x0100
#परिभाषय RDW_ERASENOW 0x0200

#परिभाषय RDW_FRAME 0x0400
#परिभाषय RDW_NOFRAME 0x0800

  WINUSERAPI WINBOOL WINAPI तालकम्_गवाक्षः_Update(HWND h_Wnd_तालकम्);
  WINUSERAPI WINBOOL WINAPI Scroll_गवाक्षः(HWND hWnd,पूर्णाङ्क XAmount,पूर्णाङ्क YAmount,CONST RECT *lpRect,CONST RECT *lpClipRect);
  WINUSERAPI WINBOOL WINAPI ScrollDC(HDC hDC,पूर्णाङ्क dx,पूर्णाङ्क dy,CONST RECT *lprcScroll,CONST RECT *lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
  WINUSERAPI पूर्णाङ्क WINAPI Scroll_गवाक्षः_Ex(HWND hWnd,पूर्णाङ्क dx,पूर्णाङ्क dy,CONST RECT *prcScroll,CONST RECT *prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);

#परिभाषय SW_SCROLLCHILDREN 0x0001
#परिभाषय SW_INVALIDATE 0x0002
#परिभाषय SW_ERASE 0x0004
#परिभाषय SW_SMOOTHSCROLL 0x0010

#यदि_अपरिभाषितम् NOSCROLL
  WINUSERAPI पूर्णाङ्क WINAPI समुच्चयः_Scroll_Pos(HWND hWnd,पूर्णाङ्क nBar,पूर्णाङ्क nPos,WINBOOL bRedraw);
  WINUSERAPI पूर्णाङ्क WINAPI GetScrollPos(HWND hWnd,पूर्णाङ्क nBar);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Scroll_Range(HWND hWnd,पूर्णाङ्क nBar,पूर्णाङ्क nMinPos,पूर्णाङ्क nMaxPos,WINBOOL bRedraw);
  WINUSERAPI WINBOOL WINAPI GetScrollRange(HWND hWnd,पूर्णाङ्क nBar,LPINT lpMinPos,LPINT lpMaxPos);
  WINUSERAPI WINBOOL WINAPI ShowScrollBar(HWND hWnd,पूर्णाङ्क wBar,WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows);

#परिभाषय ESB_ENABLE_BOTH 0x0000
#परिभाषय ESB_DISABLE_BOTH 0x0003

#परिभाषय ESB_DISABLE_वामः 0x0001
#परिभाषय ESB_DISABLE_दक्षिणः 0x0002

#परिभाषय ESB_DISABLE_ऊर्ध्वम् 0x0001
#परिभाषय ESB_DISABLE_अधस्तात् 0x0002

#परिभाषय ESB_DISABLE_LTUP ESB_DISABLE_वामः
#परिभाषय ESB_DISABLE_RTDN ESB_DISABLE_दक्षिणः
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय समुच्चयः_Prop समुच्चयः_Prop_W
#परिभाषय GetProp GetPropW
#परिभाषय RemoveProp RemovePropW
#परिभाषय EnumPropsEx EnumPropsExW
#परिभाषय EnumProps EnumPropsW
#परिभाषय समुच्चयः_गवाक्षः_Text समुच्चयः_गवाक्षः_Text_W
#परिभाषय Get_गवाक्षः_Text Get_गवाक्षः_Text_W
#परिभाषय Get_गवाक्षः_Text_दीर्घता Get_गवाक्षः_Text_दीर्घता_W
#अन्यथा
#परिभाषय समुच्चयः_Prop समुच्चयः_Prop_A
#परिभाषय GetProp GetPropA
#परिभाषय RemoveProp RemovePropA
#परिभाषय EnumPropsEx EnumPropsExA
#परिभाषय EnumProps EnumPropsA
#परिभाषय समुच्चयः_गवाक्षः_Text समुच्चयः_गवाक्षः_Text_A
#परिभाषय Get_गवाक्षः_Text Get_गवाक्षः_Text_A
#परिभाषय Get_गवाक्षः_Text_दीर्घता Get_गवाक्षः_Text_दीर्घता_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI समुच्चयः_Prop_A(HWND hWnd,LPCSTR lpString,HANDLE h_दत्त);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Prop_W(HWND hWnd,LPCWSTR lpString,HANDLE h_दत्त);
  WINUSERAPI HANDLE WINAPI GetPropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI GetPropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI पूर्णाङ्क WINAPI EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
  WINUSERAPI पूर्णाङ्क WINAPI EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
  WINUSERAPI पूर्णाङ्क WINAPI EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc);
  WINUSERAPI पूर्णाङ्क WINAPI EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_गवाक्षः_Text_A(HWND hWnd,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_गवाक्षः_Text_W(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI पूर्णाङ्क WINAPI Get_गवाक्षः_Text_A(HWND hWnd,LPSTR lpString,पूर्णाङ्क n_Max_गणनम्);
  WINUSERAPI पूर्णाङ्क WINAPI Get_गवाक्षः_Text_W(HWND hWnd,LPWSTR lpString,पूर्णाङ्क n_Max_गणनम्);
  WINUSERAPI पूर्णाङ्क WINAPI Get_गवाक्षः_Text_दीर्घता_A(HWND hWnd);
  WINUSERAPI पूर्णाङ्क WINAPI Get_गवाक्षः_Text_दीर्घता_W(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI GetClientRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Get_गवाक्षः_Rect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Adjust_गवाक्षः_Rect(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu);
  WINUSERAPI WINBOOL WINAPI Adjust_गवाक्षः_Rect_Ex(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu,DWORD dwExStyle);

#परिभाषय HELPINFO_गवाक्षः 0x0001
#परिभाषय HELPINFO_MENUITEM 0x0002

  प्रकारनिर्देश संरचना चिह्नकम्_HELPINFO {
    UINT cb_आकार;
    पूर्णाङ्क iContextType;
    पूर्णाङ्क iCtrlId;
    HANDLE hItemHandle;
    DWORD_PTR dwContextId;
    POINT MousePos;
  } HELPINFO,*LPHELPINFO;

  WINUSERAPI WINBOOL WINAPI समुच्चयः_गवाक्षः_Context_Help_Id(HWND,DWORD);
  WINUSERAPI DWORD WINAPI Get_गवाक्षः_Context_Help_Id(HWND);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Menu_Context_Help_Id(HMENU,DWORD);
  WINUSERAPI DWORD WINAPI GetMenuContextHelpId(HMENU);

#यदि_अपरिभाषितम् NOMB

#परिभाषय MB_OK 0x00000000L
#परिभाषय MB_OKCANCEL 0x00000001L
#परिभाषय MB_ABORTRETRYIGNORE 0x00000002L
#परिभाषय MB_YESNOCANCEL 0x00000003L
#परिभाषय MB_YESNO 0x00000004L
#परिभाषय MB_RETRYCANCEL 0x00000005L
#परिभाषय MB_CANCELTRYCONTINUE 0x00000006L
#परिभाषय MB_ICONHAND 0x00000010L
#परिभाषय MB_ICONQUESTION 0x00000020L
#परिभाषय MB_ICONEXCLAMATION 0x00000030L
#परिभाषय MB_ICONASTERISK 0x00000040L
#परिभाषय MB_USERICON 0x00000080L
#परिभाषय MB_ICONWARNING MB_ICONEXCLAMATION
#परिभाषय MB_ICONERROR MB_ICONHAND
#परिभाषय MB_ICONINFORMATION MB_ICONASTERISK
#परिभाषय MB_ICONSTOP MB_ICONHAND
#परिभाषय MB_DEFBUTTON1 0x00000000L
#परिभाषय MB_DEFBUTTON2 0x00000100L
#परिभाषय MB_DEFBUTTON3 0x00000200L
#परिभाषय MB_DEFBUTTON4 0x00000300L
#परिभाषय MB_APPLMODAL 0x00000000L
#परिभाषय MB_SYSTEMMODAL 0x00001000L
#परिभाषय MB_TASKMODAL 0x00002000L
#परिभाषय MB_HELP 0x00004000L
#परिभाषय MB_NOFOCUS 0x00008000L
#परिभाषय MB_SETFOREGROUND 0x00010000L
#परिभाषय MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#परिभाषय MB_TOPMOST 0x00040000L
#परिभाषय MB_दक्षिणः 0x00080000L
#परिभाषय MB_RTLREADING 0x00100000L
#परिभाषय MB_SERVICE_NOTIFICATION 0x00200000L
#परिभाषय MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#परिभाषय MB_TYPEMASK 0x0000000FL
#परिभाषय MB_ICONMASK 0x000000F0L
#परिभाषय MB_DEFMASK 0x00000F00L
#परिभाषय MB_MODEMASK 0x00003000L
#परिभाषय MB_MISCMASK 0x0000C000L

#यदि_परिभाषितम् UNICODE
#परिभाषय सन्देशः_Box सन्देशः_Box_W
#परिभाषय सन्देशः_Box_Ex सन्देशः_Box_Ex_W
#अन्यथा
#परिभाषय सन्देशः_Box सन्देशः_Box_A
#परिभाषय सन्देशः_Box_Ex सन्देशः_Box_Ex_A
#यदि_अन्तः

  WINUSERAPI पूर्णाङ्क WINAPI सन्देशः_Box_A(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType);
  WINUSERAPI पूर्णाङ्क WINAPI सन्देशः_Box_W(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType);
  WINUSERAPI पूर्णाङ्क WINAPI सन्देशः_Box_Ex_A(HWND hWnd,LPCSTR lpText,LPCSTR lpCaption,UINT uType,WORD wLanguageId);
  WINUSERAPI पूर्णाङ्क WINAPI सन्देशः_Box_Ex_W(HWND hWnd,LPCWSTR lpText,LPCWSTR lpCaption,UINT uType,WORD wLanguageId);

  प्रकारनिर्देश VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

  प्रकारनिर्देश संरचना चिह्नकम्_MSGBOXPARAMSA {
    UINT cb_आकार;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpszText;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_सन्देशः_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSA,*PMSGBOXPARAMSA,*LPMSGBOXPARAMSA;

  प्रकारनिर्देश संरचना चिह्नकम्_MSGBOXPARAMSW {
    UINT cb_आकार;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpszText;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_सन्देशः_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSW,*PMSGBOXPARAMSW,*LPMSGBOXPARAMSW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश MSGBOXPARAMSW MSGBOXPARAMS;
  प्रकारनिर्देश PMSGBOXPARAMSW PMSGBOXPARAMS;
  प्रकारनिर्देश LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#अन्यथा
  प्रकारनिर्देश MSGBOXPARAMSA MSGBOXPARAMS;
  प्रकारनिर्देश PMSGBOXPARAMSA PMSGBOXPARAMS;
  प्रकारनिर्देश LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय सन्देशः_Box_परोक्षम् सन्देशः_Box_परोक्षम्_W
#अन्यथा
#परिभाषय सन्देशः_Box_परोक्षम् सन्देशः_Box_परोक्षम्_A
#यदि_अन्तः

  WINUSERAPI पूर्णाङ्क WINAPI सन्देशः_Box_परोक्षम्_A(CONST MSGBOXPARAMSA *lpmbp);
  WINUSERAPI पूर्णाङ्क WINAPI सन्देशः_Box_परोक्षम्_W(CONST MSGBOXPARAMSW *lpmbp);
  WINUSERAPI WINBOOL WINAPI सन्देशः_Beep(UINT uType);
#यदि_अन्तः

  WINUSERAPI पूर्णाङ्क WINAPI ShowCursor(WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Cursor_Pos(पूर्णाङ्क X,पूर्णाङ्क Y);
  WINUSERAPI HCURSOR WINAPI समुच्चयः_Cursor(HCURSOR hCursor);
  WINUSERAPI WINBOOL WINAPI GetCursorPos(LPPOINT lpPoint);
  WINUSERAPI WINBOOL WINAPI ClipCursor(CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI GetClipCursor(LPRECT lpRect);
  WINUSERAPI HCURSOR WINAPI GetCursor(VOID);
  WINUSERAPI WINBOOL WINAPI CreateCaret(HWND hWnd,HBITMAP hBitmap,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight);
  WINUSERAPI UINT WINAPI GetCaretBlinkTime(VOID);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Caret_Blink_Time(UINT uMSeconds);
  WINUSERAPI WINBOOL WINAPI DestroyCaret(VOID);
  WINUSERAPI WINBOOL WINAPI HideCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Caret_Pos(पूर्णाङ्क X,पूर्णाङ्क Y);
  WINUSERAPI WINBOOL WINAPI GetCaretPos(LPPOINT lpPoint);
  WINUSERAPI WINBOOL WINAPI Client_गन्तव्यम्_Screen(HWND hWnd,LPPOINT lpPoint);
  WINUSERAPI WINBOOL WINAPI Screen_गन्तव्यम्_Client(HWND hWnd,LPPOINT lpPoint);
  WINUSERAPI पूर्णाङ्क WINAPI Map_गवाक्षः_Points(HWND hWndFrom,HWND h_Wnd_गन्तव्यम्,LPPOINT lpPoints,UINT cPoints);
  WINUSERAPI HWND WINAPI गवाक्षः_From_Point(POINT Point);
  WINUSERAPI HWND WINAPI Child_गवाक्षः_From_Point(HWND hWndParent,POINT Point);

#परिभाषय CWP_ALL 0x0000
#परिभाषय CWP_SKIPINVISIBLE 0x0001
#परिभाषय CWP_SKIPDISABLED 0x0002
#परिभाषय CWP_SKIPTRANSPARENT 0x0004

  WINUSERAPI HWND WINAPI Child_गवाक्षः_From_Point_Ex(HWND hwnd,POINT pt,UINT flags);

#यदि_अपरिभाषितम् NOCOLOR

#परिभाषय CTLCOLOR_MSGBOX 0
#परिभाषय CTLCOLOR_EDIT 1
#परिभाषय CTLCOLOR_LISTBOX 2
#परिभाषय CTLCOLOR_BTN 3
#परिभाषय CTLCOLOR_DLG 4
#परिभाषय CTLCOLOR_SCROLLBAR 5
#परिभाषय CTLCOLOR_STATIC 6
#परिभाषय CTLCOLOR_MAX 7

#परिभाषय COLOR_SCROLLBAR 0
#परिभाषय COLOR_BACKGROUND 1
#परिभाषय COLOR_ACTIVECAPTION 2
#परिभाषय COLOR_INACTIVECAPTION 3
#परिभाषय COLOR_MENU 4
#परिभाषय COLOR_गवाक्षः 5
#परिभाषय COLOR_WINDOWFRAME 6
#परिभाषय COLOR_MENUTEXT 7
#परिभाषय COLOR_WINDOWTEXT 8
#परिभाषय COLOR_CAPTIONTEXT 9
#परिभाषय COLOR_ACTIVEBORDER 10
#परिभाषय COLOR_INACTIVEBORDER 11
#परिभाषय COLOR_APPWORKSPACE 12
#परिभाषय COLOR_HIGHLIGHT 13
#परिभाषय COLOR_HIGHLIGHTTEXT 14
#परिभाषय COLOR_BTNFACE 15
#परिभाषय COLOR_BTNSHADOW 16
#परिभाषय COLOR_GRAYTEXT 17
#परिभाषय COLOR_BTNTEXT 18
#परिभाषय COLOR_INACTIVECAPTIONTEXT 19
#परिभाषय COLOR_BTNHIGHLIGHT 20

#परिभाषय COLOR_3DDKSHADOW 21
#परिभाषय COLOR_3DLIGHT 22
#परिभाषय COLOR_INFOTEXT 23
#परिभाषय COLOR_INFOBK 24

#परिभाषय COLOR_HOTLIGHT 26
#परिभाषय COLOR_GRADIENTACTIVECAPTION 27
#परिभाषय COLOR_GRADIENTINACTIVECAPTION 28
#परिभाषय COLOR_MENUHILIGHT 29
#परिभाषय COLOR_MENUBAR 30

#परिभाषय COLOR_DESKTOP COLOR_BACKGROUND
#परिभाषय COLOR_3DFACE COLOR_BTNFACE
#परिभाषय COLOR_3DSHADOW COLOR_BTNSHADOW
#परिभाषय COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#परिभाषय COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#परिभाषय COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

  WINUSERAPI DWORD WINAPI GetSysColor(पूर्णाङ्क n_सूचकांक);
  WINUSERAPI HBRUSH WINAPI GetSysColorBrush(पूर्णाङ्क n_सूचकांक);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Sys_Colors(पूर्णाङ्क cElements,CONST INT *lpaElements,CONST COLORREF *lpa_Rgb_मानानि);
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI DrawFocusRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI पूर्णाङ्क WINAPI FillRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI पूर्णाङ्क WINAPI FrameRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI WINBOOL WINAPI InvertRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Rect(LPRECT lprc,पूर्णाङ्क x_वामः,पूर्णाङ्क y_शिखरम्,पूर्णाङ्क x_दक्षिणः,पूर्णाङ्क yBottom);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Rect_रिक्तानि(LPRECT lprc);
  WINUSERAPI WINBOOL WINAPI CopyRect(LPRECT lprcDst,CONST RECT *lprcSrc);
  WINUSERAPI WINBOOL WINAPI InflateRect(LPRECT lprc,पूर्णाङ्क dx,पूर्णाङ्क dy);
  WINUSERAPI WINBOOL WINAPI IntersectRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI UnionRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI व्यवकलय_Rect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI विस्थापनम्_Rect(LPRECT lprc,पूर्णाङ्क dx,पूर्णाङ्क dy);
  WINUSERAPI WINBOOL WINAPI Is_Rect_रिक्तानि(CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI EqualRect(CONST RECT *lprc1,CONST RECT *lprc2);
  WINUSERAPI WINBOOL WINAPI Pt_अन्तर्_Rect(CONST RECT *lprc,POINT pt);

#यदि_अपरिभाषितम् NOWINOFFSETS

#यदि_परिभाषितम् UNICODE
#परिभाषय Get_गवाक्षः_Long Get_गवाक्षः_Long_W
#परिभाषय समुच्चयः_गवाक्षः_Long समुच्चयः_गवाक्षः_Long_W
#अन्यथा
#परिभाषय Get_गवाक्षः_Long Get_गवाक्षः_Long_A
#परिभाषय समुच्चयः_गवाक्षः_Long समुच्चयः_गवाक्षः_Long_A
#यदि_अन्तः

  WINUSERAPI WORD WINAPI Get_गवाक्षः_Word(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI WORD WINAPI समुच्चयः_गवाक्षः_Word(HWND hWnd,पूर्णाङ्क n_सूचकांक,WORD wNewWord);
  WINUSERAPI LONG WINAPI Get_गवाक्षः_Long_A(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI LONG WINAPI Get_गवाक्षः_Long_W(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI LONG WINAPI समुच्चयः_गवाक्षः_Long_A(HWND hWnd,पूर्णाङ्क n_सूचकांक,LONG dwNewLong);
  WINUSERAPI LONG WINAPI समुच्चयः_गवाक्षः_Long_W(HWND hWnd,पूर्णाङ्क n_सूचकांक,LONG dwNewLong);

#यदि_परिभाषितम् _WIN64

#यदि_परिभाषितम् UNICODE
#परिभाषय Get_गवाक्षः_Long_Ptr Get_गवाक्षः_Long_Ptr_W
#परिभाषय समुच्चयः_गवाक्षः_Long_Ptr समुच्चयः_गवाक्षः_Long_Ptr_W
#अन्यथा
#परिभाषय Get_गवाक्षः_Long_Ptr Get_गवाक्षः_Long_Ptr_A
#परिभाषय समुच्चयः_गवाक्षः_Long_Ptr समुच्चयः_गवाक्षः_Long_Ptr_A
#यदि_अन्तः

  WINUSERAPI LONG_PTR WINAPI Get_गवाक्षः_Long_Ptr_A(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI LONG_PTR WINAPI Get_गवाक्षः_Long_Ptr_W(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI LONG_PTR WINAPI समुच्चयः_गवाक्षः_Long_Ptr_A(HWND hWnd,पूर्णाङ्क n_सूचकांक,LONG_PTR dwNewLong);
  WINUSERAPI LONG_PTR WINAPI समुच्चयः_गवाक्षः_Long_Ptr_W(HWND hWnd,पूर्णाङ्क n_सूचकांक,LONG_PTR dwNewLong);
#अन्यथा

#यदि_परिभाषितम् UNICODE
#परिभाषय Get_गवाक्षः_Long_Ptr Get_गवाक्षः_Long_Ptr_W
#परिभाषय समुच्चयः_गवाक्षः_Long_Ptr समुच्चयः_गवाक्षः_Long_Ptr_W
#अन्यथा
#परिभाषय Get_गवाक्षः_Long_Ptr Get_गवाक्षः_Long_Ptr_A
#परिभाषय समुच्चयः_गवाक्षः_Long_Ptr समुच्चयः_गवाक्षः_Long_Ptr_A
#यदि_अन्तः

#परिभाषय Get_गवाक्षः_Long_Ptr_A Get_गवाक्षः_Long_A
#परिभाषय Get_गवाक्षः_Long_Ptr_W Get_गवाक्षः_Long_W
#परिभाषय समुच्चयः_गवाक्षः_Long_Ptr_A समुच्चयः_गवाक्षः_Long_A
#परिभाषय समुच्चयः_गवाक्षः_Long_Ptr_W समुच्चयः_गवाक्षः_Long_W
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय GetClassLong GetClassLongW
#परिभाषय समुच्चयः_Class_Long समुच्चयः_Class_Long_W
#अन्यथा
#परिभाषय GetClassLong GetClassLongA
#परिभाषय समुच्चयः_Class_Long समुच्चयः_Class_Long_A
#यदि_अन्तः

  WINUSERAPI WORD WINAPI GetClassWord(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI WORD WINAPI समुच्चयः_Class_Word(HWND hWnd,पूर्णाङ्क n_सूचकांक,WORD wNewWord);
  WINUSERAPI DWORD WINAPI GetClassLongA(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI DWORD WINAPI GetClassLongW(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI DWORD WINAPI समुच्चयः_Class_Long_A(HWND hWnd,पूर्णाङ्क n_सूचकांक,LONG dwNewLong);
  WINUSERAPI DWORD WINAPI समुच्चयः_Class_Long_W(HWND hWnd,पूर्णाङ्क n_सूचकांक,LONG dwNewLong);

#यदि_परिभाषितम् _WIN64

#यदि_परिभाषितम् UNICODE
#परिभाषय GetClassLongPtr GetClassLongPtrW
#परिभाषय समुच्चयः_Class_Long_Ptr समुच्चयः_Class_Long_Ptr_W
#अन्यथा
#परिभाषय GetClassLongPtr GetClassLongPtrA
#परिभाषय समुच्चयः_Class_Long_Ptr समुच्चयः_Class_Long_Ptr_A
#यदि_अन्तः

  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd,पूर्णाङ्क n_सूचकांक);
  WINUSERAPI ULONG_PTR WINAPI समुच्चयः_Class_Long_Ptr_A(HWND hWnd,पूर्णाङ्क n_सूचकांक,LONG_PTR dwNewLong);
  WINUSERAPI ULONG_PTR WINAPI समुच्चयः_Class_Long_Ptr_W(HWND hWnd,पूर्णाङ्क n_सूचकांक,LONG_PTR dwNewLong);
#अन्यथा
#यदि_परिभाषितम् UNICODE
#परिभाषय GetClassLongPtr GetClassLongPtrW
#परिभाषय समुच्चयः_Class_Long_Ptr समुच्चयः_Class_Long_Ptr_W
#अन्यथा
#परिभाषय GetClassLongPtr GetClassLongPtrA
#परिभाषय समुच्चयः_Class_Long_Ptr समुच्चयः_Class_Long_Ptr_A
#यदि_अन्तः

#परिभाषय GetClassLongPtrA GetClassLongA
#परिभाषय GetClassLongPtrW GetClassLongW
#परिभाषय समुच्चयः_Class_Long_Ptr_A समुच्चयः_Class_Long_A
#परिभाषय समुच्चयः_Class_Long_Ptr_W समुच्चयः_Class_Long_W
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय Find_गवाक्षः Find_गवाक्षः_W
#परिभाषय Find_गवाक्षः_Ex Find_गवाक्षः_Ex_W
#परिभाषय GetClassName GetClassNameW
#अन्यथा
#परिभाषय Find_गवाक्षः Find_गवाक्षः_A
#परिभाषय Find_गवाक्षः_Ex Find_गवाक्षः_Ex_A
#परिभाषय GetClassName GetClassNameA
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI GetProcessDefaultLayout(DWORD *pdwDefaultLayout);
  WINUSERAPI WINBOOL WINAPI समुच्चयः_Process_Default_Layout(DWORD dwDefaultLayout);
  WINUSERAPI HWND WINAPI Get_Desktop_गवाक्षः(VOID);
  WINUSERAPI HWND WINAPI GetParent(HWND hWnd);
  WINUSERAPI HWND WINAPI समुच्चयः_Parent(HWND hWndChild,HWND hWndNewParent);
  WINUSERAPI WINBOOL WINAPI EnumChildWindows(HWND hWndParent,WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI HWND WINAPI Find_गवाक्षः_A(LPCSTR lpClassName,LPCSTR lp_गवाक्षः_Name);
  WINUSERAPI HWND WINAPI Find_गवाक्षः_W(LPCWSTR lpClassName,LPCWSTR lp_गवाक्षः_Name);
  WINUSERAPI HWND WINAPI Find_गवाक्षः_Ex_A(HWND hWndParent,HWND hWndChildAfter,LPCSTR lpszClass,LPCSTR lpsz_गवाक्षः);
  WINUSERAPI HWND WINAPI Find_गवाक्षः_Ex_W(HWND hWndParent,HWND hWndChildAfter,LPCWSTR lpszClass,LPCWSTR lpsz_गवाक्षः);
  WINUSERAPI HWND WINAPI Get_Shell_गवाक्षः(VOID);
  WINUSERAPI WINBOOL WINAPI पञ्जिकाकोशः_Shell_Hook_गवाक्षः(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI Deregister_Shell_Hook_गवाक्षः(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);

#परिभाषय EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(Handle_गन्तव्यम्_Ulong(hTask),lpfn,lParam)

  WINUSERAPI पूर्णाङ्क WINAPI GetClassNameA(HWND hWnd,LPSTR lpClassName,पूर्णाङ्क n_Max_गणनम्);
  WINUSERAPI पूर्णाङ्क WINAPI GetClassNameW(HWND hWnd,LPWSTR lpClassName,पूर्णाङ्क n_Max_गणनम्);
  WINUSERAPI HWND WINAPI Get_शिखरम्_गवाक्षः(HWND hWnd);

#परिभाषय Get_अग्र_गवाक्षः(hWnd,wCmd) Get_गवाक्षः(hWnd,wCmd)
#परिभाषय Get_Sys_Modal_गवाक्षः() (रिक्त)
#परिभाषय समुच्चयः_Sys_Modal_गवाक्षः(hWnd) (रिक्त)

  WINUSERAPI DWORD WINAPI Get_गवाक्षः_Thread_Process_Id(HWND hWnd,LPDWORD lpdwProcessId);
  WINUSERAPI WINBOOL WINAPI IsGUIThread(WINBOOL bConvert);

#परिभाषय Get_गवाक्षः_Task(hWnd) ((HANDLE)(DWORD_PTR)Get_गवाक्षः_Thread_Process_Id(hWnd,रिक्त))

  WINUSERAPI HWND WINAPI Get_चरमः_सक्रिय_Popup(HWND hWnd);

#परिभाषय GW_HWNDFIRST 0
#परिभाषय GW_HWNDLAST 1
#परिभाषय GW_HWNDNEXT 2
#परिभाषय GW_HWNDPREV 3
#परिभाषय GW_OWNER 4
#परिभाषय GW_CHILD 5
#परिभाषय GW_ENABLEDPOPUP 6
#परिभाषय GW_MAX 6

  WINUSERAPI HWND WINAPI Get_गवाक्षः(HWND hWnd,UINT uCmd);

#यदि_अपरिभाषितम् NOWH

#यदि_परिभाषितम् UNICODE
#परिभाषय समुच्चयः_Windows_Hook समुच्चयः_Windows_Hook_W
#परिभाषय समुच्चयः_Windows_Hook_Ex समुच्चयः_Windows_Hook_Ex_W
#अन्यथा
#परिभाषय समुच्चयः_Windows_Hook समुच्चयः_Windows_Hook_A
#परिभाषय समुच्चयः_Windows_Hook_Ex समुच्चयः_Windows_Hook_Ex_A
#यदि_अन्तः

  WINUSERAPI HHOOK WINAPI समुच्चयः_Windows_Hook_A(पूर्णाङ्क nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI समुच्चयः_Windows_Hook_W(पूर्णाङ्क nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHook(पूर्णाङ्क n_संहिता,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI समुच्चयः_Windows_Hook_Ex_A(पूर्णाङ्क idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI HHOOK WINAPI समुच्चयः_Windows_Hook_Ex_W(पूर्णाङ्क idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);
  WINUSERAPI LRESULT WINAPI Call_अग्र_Hook_Ex(HHOOK hhk,पूर्णाङ्क n_संहिता,WPARAM wParam,LPARAM lParam);
#परिभाषय DefHookProc(n_संहिता,wParam,lParam,phhk) Call_अग्र_Hook_Ex(*phhk,n_संहिता,wParam,lParam)
#यदि_अन्तः

#यदि_अपरिभाषितम् NOMENUS

#परिभाषय MF_निवेशय 0x00000000L
#परिभाषय MF_CHANGE 0x00000080L
#परिभाषय MF_APPEND 0x00000100L
#परिभाषय MF_DELETE 0x00000200L
#परिभाषय MF_REMOVE 0x00001000L
#परिभाषय MF_BYCOMMAND 0x00000000L
#परिभाषय MF_BYPOSITION 0x00000400L
#परिभाषय MF_SEPARATOR 0x00000800L
#परिभाषय MF_ENABLED 0x00000000L
#परिभाषय MF_GRAYED 0x00000001L
#परिभाषय MF_DISABLED 0x00000002L
#परिभाषय MF_UNCHECKED 0x00000000L
#परिभाषय MF_CHECKED 0x00000008L
#परिभाषय MF_USECHECKBITMAPS 0x00000200L
#परिभाषय MF_STRING 0x00000000L
#परिभाषय MF_BITMAP 0x00000004L
#परिभाषय MF_OWNERDRAW 0x00000100L
#परिभाषय MF_POPUP 0x00000010L
#परिभाषय MF_MENUBARBREAK 0x00000020L
#परिभाषय MF_MENUBREAK 0x00000040L
#परिभाषय MF_UNHILITE 0x00000000L
#परिभाषय MF_HILITE 0x00000080L
#परिभाषय MF_DEFAULT 0x00001000L
#परिभाषय MF_SYSMENU 0x00002000L
#परिभाषय MF_HELP 0x00004000L
#परिभाषय MF_RIGHTJUSTIFY 0x00004000L
#परिभाषय MF_MOUSESELECT 0x00008000L
#परिभाषय MF_अन्तः 0x00000080L

#परिभाषय MFT_STRING MF_STRING
#परिभाषय MFT_BITMAP MF_BITMAP
#परिभाषय MFT_MENUBARBREAK MF_MENUBARBREAK
#परिभाषय MFT_MENUBREAK MF_MENUBREAK
#परिभाषय MFT_OWNERDRAW MF_OWNERDRAW
#परिभाषय MFT_RADIOCHECK 0x00000200L
#परिभाषय MFT_SEPARATOR MF_SEPARATOR
#परिभाषय MFT_RIGHTORDER 0x00002000L
#परिभाषय MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#परिभाषय MFS_GRAYED 0x00000003L
#परिभाषय MFS_DISABLED MFS_GRAYED
#परिभाषय MFS_CHECKED MF_CHECKED
#परिभाषय MFS_HILITE MF_HILITE
#परिभाषय MFS_ENABLED MF_ENABLED
#परिभाषय MFS_UNCHECKED MF_UNCHECKED
#परिभाषय MFS_UNHILITE MF_UNHILITE
#परिभाषय MFS_DEFAULT MF_DEFAULT

  WINUSERAPI WINBOOL WINAPI CheckMenuRadioItem(HMENU hmenu,UINT first,UINT चरमः,UINT check,UINT flags);

  प्रकारनिर्देश संरचना {
    WORD संस्करणम्_सङ्ख्या;
    WORD विस्थापनम्;
  } MENUITEMTEMPLATEHEADER,*PMENUITEMTEMPLATEHEADER;

  प्रकारनिर्देश संरचना {
    WORD mtOption;
    WORD mtID;
    WCHAR mtString[1];
  } MENUITEMTEMPLATE,*PMENUITEMTEMPLATE;
#परिभाषय MF_अन्तः 0x00000080L
#यदि_अन्तः

#यदि_अपरिभाषितम् NOSYSCOMMANDS

#परिभाषय SC_आकार 0xF000
#परिभाषय SC_MOVE 0xF010
#परिभाषय SC_MINIMIZE 0xF020
#परिभाषय SC_MAXIMIZE 0xF030
#परिभाषय SC_NEXTWINDOW 0xF040
#परिभाषय SC_PREVWINDOW 0xF050
#परिभाषय SC_CLOSE 0xF060
#परिभाषय SC_VSCROLL 0xF070
#परिभाषय SC_HSCROLL 0xF080
#परिभाषय SC_MOUSEMENU 0xF090
#परिभाषय SC_KEYMENU 0xF100
#परिभाषय SC_ARRANGE 0xF110
#परिभाषय SC_RESTORE 0xF120
#परिभाषय SC_TASKLIST 0xF130
#परिभाषय SC_SCREENSAVE 0xF140
#परिभाषय SC_HOTKEY 0xF150
#परिभाषय SC_DEFAULT 0xF160
#परिभाषय SC_MONITORPOWER 0xF170
#परिभाषय SC_CONTEXTHELP 0xF180
#परिभाषय SC_SEPARATOR 0xF00F
#परिभाषय SC_ICON SC_MINIMIZE
#परिभाषय SC_ZOOM SC_MAXIMIZE
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय आरोपय_Bitmap आरोपय_Bitmap_W
#परिभाषय आरोपय_Cursor आरोपय_Cursor_W
#परिभाषय आरोपय_Cursor_From_File आरोपय_Cursor_From_File_W
#अन्यथा
#परिभाषय आरोपय_Bitmap आरोपय_Bitmap_A
#परिभाषय आरोपय_Cursor आरोपय_Cursor_A
#परिभाषय आरोपय_Cursor_From_File आरोपय_Cursor_From_File_A
#यदि_अन्तः

  WINUSERAPI HBITMAP WINAPI आरोपय_Bitmap_A(HINSTANCE hInstance,LPCSTR lpBitmapName);
  WINUSERAPI HBITMAP WINAPI आरोपय_Bitmap_W(HINSTANCE hInstance,LPCWSTR lpBitmapName);
  WINUSERAPI HCURSOR WINAPI आरोपय_Cursor_A(HINSTANCE hInstance,LPCSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI आरोपय_Cursor_W(HINSTANCE hInstance,LPCWSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI आरोपय_Cursor_From_File_A(LPCSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI आरोपय_Cursor_From_File_W(LPCWSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI CreateCursor(HINSTANCE hInst,पूर्णाङ्क xHotSpot,पूर्णाङ्क yHotSpot,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight,CONST VOID *pvANDPlane,CONST VOID *pvXORPlane);
  WINUSERAPI WINBOOL WINAPI DestroyCursor(HCURSOR hCursor);

#परिभाषय CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

#परिभाषय IDC_ARROW MAKEINTRESOURCE(32512)
#परिभाषय IDC_IBEAM MAKEINTRESOURCE(32513)
#परिभाषय IDC_WAIT MAKEINTRESOURCE(32514)
#परिभाषय IDC_CROSS MAKEINTRESOURCE(32515)
#परिभाषय IDC_UPARROW MAKEINTRESOURCE(32516)
#परिभाषय IDC_आकार MAKEINTRESOURCE(32640)
#परिभाषय IDC_ICON MAKEINTRESOURCE(32641)
#परिभाषय IDC_SIZENWSE MAKEINTRESOURCE(32642)
#परिभाषय IDC_SIZENESW MAKEINTRESOURCE(32643)
#परिभाषय IDC_SIZEWE MAKEINTRESOURCE(32644)
#परिभाषय IDC_SIZENS MAKEINTRESOURCE(32645)
#परिभाषय IDC_SIZEALL MAKEINTRESOURCE(32646)
#परिभाषय IDC_NO MAKEINTRESOURCE(32648)
#परिभाषय IDC_HAND MAKEINTRESOURCE(32649)
#परिभाषय IDC_APPSTARTING MAKEINTRESOURCE(32650)
#परिभाषय IDC_HELP MAKEINTRESOURCE(32651)

  WINUSERAPI WINBOOL WINAPI समुच्चयः_System_Cursor(HCURSOR hcur,DWORD id);

  प्रकारनिर्देश संरचना _ICONINFO {
    WINBOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbm_आवरणम्;
    HBITMAP hbmColor;
  } ICONINFO;
  प्रकारनिर्देश ICONINFO *PICONINFO;

#यदि_परिभाषितम् UNICODE
#परिभाषय आरोपय_Icon आरोपय_Icon_W
#परिभाषय वैयक्तिकम्_Extract_Icons वैयक्तिकम्_Extract_Icons_W
#अन्यथा
#परिभाषय आरोपय_Icon आरोपय_Icon_A
#परिभाषय वैयक्तिकम्_Extract_Icons वैयक्तिकम्_Extract_Icons_A
#यदि_अन्तः

  WINUSERAPI HICON WINAPI आरोपय_Icon_A(HINSTANCE hInstance,LPCSTR lpIconName);
  WINUSERAPI HICON WINAPI आरोपय_Icon_W(HINSTANCE hInstance,LPCWSTR lpIconName);
  WINUSERAPI UINT WINAPI वैयक्तिकम्_Extract_Icons_A(LPCSTR szFileName,पूर्णाङ्क n_Icon_सूचकांक,पूर्णाङ्क cxIcon,पूर्णाङ्क cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI UINT WINAPI वैयक्तिकम्_Extract_Icons_W(LPCWSTR szFileName,पूर्णाङ्क n_Icon_सूचकांक,पूर्णाङ्क cxIcon,पूर्णाङ्क cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI HICON WINAPI CreateIcon(HINSTANCE hInstance,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight,BYTE cPlanes,BYTE c_द्वयङ्काः_Pixel,CONST BYTE *lpbANDbits,CONST BYTE *lpbXORbits);
  WINUSERAPI WINBOOL WINAPI DestroyIcon(HICON hIcon);
  WINUSERAPI पूर्णाङ्क WINAPI LookupIconIdFromDirectory(PBYTE presbits,WINBOOL fIcon);
  WINUSERAPI पूर्णाङ्क WINAPI LookupIconIdFromDirectoryEx(PBYTE presbits,WINBOOL fIcon,पूर्णाङ्क cxDesired,पूर्णाङ्क cyDesired,UINT Flags);
  WINUSERAPI HICON WINAPI CreateIconFromResource(PBYTE presbits,DWORD dw_Res_आकार,WINBOOL fIcon,DWORD dwVer);
  WINUSERAPI HICON WINAPI CreateIconFromResourceEx(PBYTE presbits,DWORD dw_Res_आकार,WINBOOL fIcon,DWORD dwVer,पूर्णाङ्क cxDesired,पूर्णाङ्क cyDesired,UINT Flags);

  प्रकारनिर्देश संरचना चिह्नकम्_CURSORSHAPE {
    पूर्णाङ्क xHotSpot;
    पूर्णाङ्क yHotSpot;
    पूर्णाङ्क cx;
    पूर्णाङ्क cy;
    पूर्णाङ्क cb_विस्तारः;
    BYTE Planes;
    BYTE द्वयङ्काः_Pixel;
  } CURSORSHAPE,*LPCURSORSHAPE;

#परिभाषय IMAGE_BITMAP 0
#परिभाषय IMAGE_ICON 1
#परिभाषय IMAGE_CURSOR 2
#परिभाषय IMAGE_ENHMETAFILE 3

#परिभाषय LR_DEFAULTCOLOR 0x0000
#परिभाषय LR_MONOCHROME 0x0001
#परिभाषय LR_COLOR 0x0002
#परिभाषय LR_COPYRETURNORG 0x0004
#परिभाषय LR_COPYDELETEORG 0x0008
#परिभाषय LR_LOADFROMFILE 0x0010
#परिभाषय LR_LOADTRANSPARENT 0x0020
#परिभाषय LR_DEFAULTSIZE 0x0040
#परिभाषय LR_VGACOLOR 0x0080
#परिभाषय LR_LOADMAP3DCOLORS 0x1000
#परिभाषय LR_CREATEDIBSECTION 0x2000
#परिभाषय LR_COPYFROMRESOURCE 0x4000
#परिभाषय LR_SHARED 0x8000

#यदि_परिभाषितम् UNICODE
#परिभाषय आरोपय_Image आरोपय_Image_W
#अन्यथा
#परिभाषय आरोपय_Image आरोपय_Image_A
#यदि_अन्तः

  WINUSERAPI HANDLE WINAPI आरोपय_Image_A(HINSTANCE hInst,LPCSTR name,UINT type,पूर्णाङ्क cx,पूर्णाङ्क cy,UINT fu_आरोपय);
  WINUSERAPI HANDLE WINAPI आरोपय_Image_W(HINSTANCE hInst,LPCWSTR name,UINT type,पूर्णाङ्क cx,पूर्णाङ्क cy,UINT fu_आरोपय);
  WINUSERAPI HANDLE WINAPI CopyImage(HANDLE h,UINT type,पूर्णाङ्क cx,पूर्णाङ्क cy,UINT flags);

#परिभाषय DI_आवरणम् 0x0001
#परिभाषय DI_IMAGE 0x0002
#परिभाषय DI_प्रसामान्यम् 0x0003
#परिभाषय DI_COMPAT 0x0004
#परिभाषय DI_DEFAULTSIZE 0x0008
#परिभाषय DI_NOMIRROR 0x0010

  WINUSERAPI WINBOOL WINAPI DrawIconEx(HDC hdc,पूर्णाङ्क x_वामः,पूर्णाङ्क y_शिखरम्,HICON hIcon,पूर्णाङ्क cx_विस्तारः,पूर्णाङ्क cy_विस्तारः,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
  WINUSERAPI HICON WINAPI Create_Icon_परोक्षम्(PICONINFO piconinfo);
  WINUSERAPI HICON WINAPI CopyIcon(HICON hIcon);
  WINUSERAPI WINBOOL WINAPI GetIconInfo(HICON hIcon,PICONINFO piconinfo);

#परिभाषय RES_ICON 1
#परिभाषय RES_CURSOR 2

#यदि_परिभाषितम् OEMRESOURCE

#परिभाषय OBM_CLOSE 32754
#परिभाषय OBM_UPARROW 32753
#परिभाषय OBM_DNARROW 32752
#परिभाषय OBM_RGARROW 32751
#परिभाषय OBM_LFARROW 32750
#परिभाषय OBM_REDUCE 32749
#परिभाषय OBM_ZOOM 32748
#परिभाषय OBM_RESTORE 32747
#परिभाषय OBM_REDUCED 32746
#परिभाषय OBM_ZOOMD 32745
#परिभाषय OBM_RESTORED 32744
#परिभाषय OBM_UPARROWD 32743
#परिभाषय OBM_DNARROWD 32742
#परिभाषय OBM_RGARROWD 32741
#परिभाषय OBM_LFARROWD 32740
#परिभाषय OBM_MNARROW 32739
#परिभाषय OBM_COMBO 32738
#परिभाषय OBM_UPARROWI 32737
#परिभाषय OBM_DNARROWI 32736
#परिभाषय OBM_RGARROWI 32735
#परिभाषय OBM_LFARROWI 32734

#परिभाषय OBM_OLD_CLOSE 32767
#परिभाषय OBM_आकार 32766
#परिभाषय OBM_OLD_UPARROW 32765
#परिभाषय OBM_OLD_DNARROW 32764
#परिभाषय OBM_OLD_RGARROW 32763
#परिभाषय OBM_OLD_LFARROW 32762
#परिभाषय OBM_BTSIZE 32761
#परिभाषय OBM_CHECK 32760
#परिभाषय OBM_CHECKBOXES 32759
#परिभाषय OBM_BTNCORNERS 32758
#परिभाषय OBM_OLD_REDUCE 32757
#परिभाषय OBM_OLD_ZOOM 32756
#परिभाषय OBM_OLD_RESTORE 32755

#परिभाषय OCR_प्रसामान्यम् 32512
#परिभाषय OCR_IBEAM 32513
#परिभाषय OCR_WAIT 32514
#परिभाषय OCR_CROSS 32515
#परिभाषय OCR_ऊर्ध्वम् 32516
#परिभाषय OCR_आकार 32640
#परिभाषय OCR_ICON 32641
#परिभाषय OCR_SIZENWSE 32642
#परिभाषय OCR_SIZENESW 32643
#परिभाषय OCR_SIZEWE 32644
#परिभाषय OCR_SIZENS 32645
#परिभाषय OCR_SIZEALL 32646
#परिभाषय OCR_ICOCUR 32647
#परिभाषय OCR_NO 32648
#परिभाषय OCR_HAND 32649
#परिभाषय OCR_APPSTARTING 32650

#परिभाषय OIC_SAMPLE 32512
#परिभाषय OIC_HAND 32513
#परिभाषय OIC_QUES 32514
#परिभाषय OIC_BANG 32515
#परिभाषय OIC_NOTE 32516
#परिभाषय OIC_WINLOGO 32517
#परिभाषय OIC_WARNING OIC_BANG
#परिभाषय OIC_ERROR OIC_HAND
#परिभाषय OIC_INFORMATION OIC_NOTE
#यदि_अन्तः

#परिभाषय ORD_LANGDRIVER 1

#यदि_अपरिभाषितम् NOICONS

#यदि_परिभाषितम् RC_INVOKED
#परिभाषय IDI_APPLICATION 32512
#परिभाषय IDI_HAND 32513
#परिभाषय IDI_QUESTION 32514
#परिभाषय IDI_EXCLAMATION 32515
#परिभाषय IDI_ASTERISK 32516
#परिभाषय IDI_WINLOGO 32517
#अन्यथा
#परिभाषय IDI_APPLICATION MAKEINTRESOURCE(32512)
#परिभाषय IDI_HAND MAKEINTRESOURCE(32513)
#परिभाषय IDI_QUESTION MAKEINTRESOURCE(32514)
#परिभाषय IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#परिभाषय IDI_ASTERISK MAKEINTRESOURCE(32516)
#परिभाषय IDI_WINLOGO MAKEINTRESOURCE(32517)
#यदि_अन्तः

#परिभाषय IDI_WARNING IDI_EXCLAMATION
#परिभाषय IDI_ERROR IDI_HAND
#परिभाषय IDI_INFORMATION IDI_ASTERISK
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय आरोपय_String आरोपय_String_W
#अन्यथा
#परिभाषय आरोपय_String आरोपय_String_A
#यदि_अन्तः

  WINUSERAPI पूर्णाङ्क WINAPI आरोपय_String_A(HINSTANCE hInstance,UINT uID,LPSTR lp_बफर,पूर्णाङ्क cch_बफर_Max);
  WINUSERAPI पूर्णाङ्क WINAPI आरोपय_String_W(HINSTANCE hInstance,UINT uID,LPWSTR lp_बफर,पूर्णाङ्क cch_बफर_Max);

#परिभाषय IDOK 1
#परिभाषय IDCANCEL 2
#परिभाषय IDABORT 3
#परिभाषय IDRETRY 4
#परिभाषय IDIGNORE 5
#परिभाषय IDYES 6
#परिभाषय IDNO 7
#परिभाषय IDCLOSE 8
#परिभाषय IDHELP 9
#परिभाषय IDTRYAGAIN 10
#परिभाषय IDCONTINUE 11

#यदि_अपरिभाषितम् IDTIMEOUT
#परिभाषय IDTIMEOUT 32000
#यदि_अन्तः

#यदि_अपरिभाषितम् NOCTLMGR

#यदि_अपरिभाषितम् NOWINSTYLES
#परिभाषय ES_वामः 0x0000L
#परिभाषय ES_CENTER 0x0001L
#परिभाषय ES_दक्षिणः 0x0002L
#परिभाषय ES_MULTILINE 0x0004L
#परिभाषय ES_UPPERCASE 0x0008L
#परिभाषय ES_LOWERCASE 0x0010L
#परिभाषय ES_PASSWORD 0x0020L
#परिभाषय ES_AUTOVSCROLL 0x0040L
#परिभाषय ES_AUTOHSCROLL 0x0080L
#परिभाषय ES_NOHIDESEL 0x0100L
#परिभाषय ES_OEMCONVERT 0x0400L
#परिभाषय ES_READONLY 0x0800L
#परिभाषय ES_WANTRETURN 0x1000L
#परिभाषय ES_सङ्ख्या 0x2000L
#यदि_अन्तः

#परिभाषय EN_SETFOCUS 0x0100
#परिभाषय EN_KILLFOCUS 0x0200
#परिभाषय EN_CHANGE 0x0300
#परिभाषय EN_UPDATE 0x0400
#परिभाषय EN_ERRSPACE 0x0500
#परिभाषय EN_MAXTEXT 0x0501
#परिभाषय EN_HSCROLL 0x0601
#परिभाषय EN_VSCROLL 0x0602
#परिभाषय EN_ALIGN_LTR_EC 0x0700
#परिभाषय EN_ALIGN_RTL_EC 0x0701

#परिभाषय EC_LEFTMARGIN 0x0001
#परिभाषय EC_RIGHTMARGIN 0x0002
#परिभाषय EC_USEFONTINFO 0xffff

#परिभाषय EMSIS_COMPOSITIONSTRING 0x0001

#परिभाषय EIMES_GETCOMPSTRATONCE 0x0001
#परिभाषय EIMES_CANCELCOMPSTRINFOCUS 0x0002
#परिभाषय EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#यदि_अपरिभाषितम् NOWINMESSAGES

#परिभाषय EM_GETSEL 0x00B0
#परिभाषय EM_SETSEL 0x00B1
#परिभाषय EM_GETRECT 0x00B2
#परिभाषय EM_SETRECT 0x00B3
#परिभाषय EM_SETRECTNP 0x00B4
#परिभाषय EM_SCROLL 0x00B5
#परिभाषय EM_LINESCROLL 0x00B6
#परिभाषय EM_SCROLLCARET 0x00B7
#परिभाषय EM_GETMODIFY 0x00B8
#परिभाषय EM_SETMODIFY 0x00B9
#परिभाषय EM_GETLINECOUNT 0x00BA
#परिभाषय EM_LINEINDEX 0x00BB
#परिभाषय EM_SETHANDLE 0x00BC
#परिभाषय EM_GETHANDLE 0x00BD
#परिभाषय EM_GETTHUMB 0x00BE
#परिभाषय EM_LINELENGTH 0x00C1
#परिभाषय EM_REPLACESEL 0x00C2
#परिभाषय EM_GETLINE 0x00C4
#परिभाषय EM_LIMITTEXT 0x00C5
#परिभाषय EM_CANUNDO 0x00C6
#परिभाषय EM_UNDO 0x00C7
#परिभाषय EM_FMTLINES 0x00C8
#परिभाषय EM_LINEFROMCHAR 0x00C9
#परिभाषय EM_SETTABSTOPS 0x00CB
#परिभाषय EM_SETPASSWORDCHAR 0x00CC
#परिभाषय EM_EMPTYUNDOBUFFER 0x00CD
#परिभाषय EM_GETFIRSTVISIBLELINE 0x00CE
#परिभाषय EM_SETREADONLY 0x00CF
#परिभाषय EM_SETWORDBREAKPROC 0x00D0
#परिभाषय EM_GETWORDBREAKPROC 0x00D1
#परिभाषय EM_GETPASSWORDCHAR 0x00D2
#परिभाषय EM_SETMARGINS 0x00D3
#परिभाषय EM_GETMARGINS 0x00D4
#परिभाषय EM_SETLIMITTEXT EM_LIMITTEXT
#परिभाषय EM_GETLIMITTEXT 0x00D5
#परिभाषय EM_POSFROMCHAR 0x00D6
#परिभाषय EM_CHARFROMPOS 0x00D7
#परिभाषय EM_SETIMESTATUS 0x00D8
#परिभाषय EM_GETIMESTATUS 0x00D9
#यदि_अन्तः

#परिभाषय WB_वामः 0
#परिभाषय WB_दक्षिणः 1
#परिभाषय WB_ISDELIMITER 2

#परिभाषय BS_PUSHBUTTON 0x00000000L
#परिभाषय BS_DEFPUSHBUTTON 0x00000001L
#परिभाषय BS_CHECKBOX 0x00000002L
#परिभाषय BS_AUTOCHECKBOX 0x00000003L
#परिभाषय BS_RADIOBUTTON 0x00000004L
#परिभाषय BS_3STATE 0x00000005L
#परिभाषय BS_AUTO3STATE 0x00000006L
#परिभाषय BS_GROUPBOX 0x00000007L
#परिभाषय BS_USERBUTTON 0x00000008L
#परिभाषय BS_AUTORADIOBUTTON 0x00000009L
#परिभाषय BS_PUSHBOX 0x0000000AL
#परिभाषय BS_OWNERDRAW 0x0000000BL
#परिभाषय BS_TYPEMASK 0x0000000FL
#परिभाषय BS_LEFTTEXT 0x00000020L
#परिभाषय BS_TEXT 0x00000000L
#परिभाषय BS_ICON 0x00000040L
#परिभाषय BS_BITMAP 0x00000080L
#परिभाषय BS_वामः 0x00000100L
#परिभाषय BS_दक्षिणः 0x00000200L
#परिभाषय BS_CENTER 0x00000300L
#परिभाषय BS_शिखरम् 0x00000400L
#परिभाषय BS_BOTTOM 0x00000800L
#परिभाषय BS_VCENTER 0x00000C00L
#परिभाषय BS_PUSHLIKE 0x00001000L
#परिभाषय BS_MULTILINE 0x00002000L
#परिभाषय BS_NOTIFY 0x00004000L
#परिभाषय BS_FLAT 0x00008000L
#परिभाषय BS_RIGHTBUTTON BS_LEFTTEXT

#परिभाषय BN_CLICKED 0
#परिभाषय BN_PAINT 1
#परिभाषय BN_HILITE 2
#परिभाषय BN_UNHILITE 3
#परिभाषय BN_DISABLE 4
#परिभाषय BN_DOUBLECLICKED 5
#परिभाषय BN_PUSHED BN_HILITE
#परिभाषय BN_UNPUSHED BN_UNHILITE
#परिभाषय BN_DBLCLK BN_DOUBLECLICKED
#परिभाषय BN_SETFOCUS 6
#परिभाषय BN_KILLFOCUS 7

#परिभाषय BM_GETCHECK 0x00F0
#परिभाषय BM_SETCHECK 0x00F1
#परिभाषय BM_GETSTATE 0x00F2
#परिभाषय BM_SETSTATE 0x00F3
#परिभाषय BM_SETSTYLE 0x00F4
#परिभाषय BM_CLICK 0x00F5
#परिभाषय BM_GETIMAGE 0x00F6
#परिभाषय BM_SETIMAGE 0x00F7

#परिभाषय BST_UNCHECKED 0x0000
#परिभाषय BST_CHECKED 0x0001
#परिभाषय BST_INDETERMINATE 0x0002
#परिभाषय BST_PUSHED 0x0004
#परिभाषय BST_FOCUS 0x0008

#परिभाषय SS_वामः 0x00000000L
#परिभाषय SS_CENTER 0x00000001L
#परिभाषय SS_दक्षिणः 0x00000002L
#परिभाषय SS_ICON 0x00000003L
#परिभाषय SS_BLACKRECT 0x00000004L
#परिभाषय SS_GRAYRECT 0x00000005L
#परिभाषय SS_WHITERECT 0x00000006L
#परिभाषय SS_BLACKFRAME 0x00000007L
#परिभाषय SS_GRAYFRAME 0x00000008L
#परिभाषय SS_WHITEFRAME 0x00000009L
#परिभाषय SS_USERITEM 0x0000000AL
#परिभाषय SS_SIMPLE 0x0000000BL
#परिभाषय SS_LEFTNOWORDWRAP 0x0000000CL
#परिभाषय SS_OWNERDRAW 0x0000000DL
#परिभाषय SS_BITMAP 0x0000000EL
#परिभाषय SS_ENHMETAFILE 0x0000000FL
#परिभाषय SS_ETCHEDHORZ 0x00000010L
#परिभाषय SS_ETCHEDVERT 0x00000011L
#परिभाषय SS_ETCHEDFRAME 0x00000012L
#परिभाषय SS_TYPEMASK 0x0000001FL
#परिभाषय SS_REALSIZECONTROL 0x00000040L
#परिभाषय SS_NOPREFIX 0x00000080L
#परिभाषय SS_NOTIFY 0x00000100L
#परिभाषय SS_CENTERIMAGE 0x00000200L
#परिभाषय SS_RIGHTJUST 0x00000400L
#परिभाषय SS_REALSIZEIMAGE 0x00000800L
#परिभाषय SS_SUNKEN 0x00001000L
#परिभाषय SS_EDITCONTROL 0x00002000L
#परिभाषय SS_ENDELLIPSIS 0x00004000L
#परिभाषय SS_PATHELLIPSIS 0x00008000L
#परिभाषय SS_WORDELLIPSIS 0x0000C000L
#परिभाषय SS_ELLIPSISMASK 0x0000C000L

#यदि_अपरिभाषितम् NOWINMESSAGES

#परिभाषय STM_SETICON 0x0170
#परिभाषय STM_GETICON 0x0171
#परिभाषय STM_SETIMAGE 0x0172
#परिभाषय STM_GETIMAGE 0x0173
#परिभाषय STN_CLICKED 0
#परिभाषय STN_DBLCLK 1
#परिभाषय STN_ENABLE 2
#परिभाषय STN_DISABLE 3
#परिभाषय STM_MSGMAX 0x0174
#यदि_अन्तः

#परिभाषय WC_DIALOG (MAKEINTATOM(0x8002))

#परिभाषय DWL_MSGRESULT 0
#परिभाषय DWL_DLGPROC 4
#परिभाषय DWL_USER 8

#यदि_परिभाषितम् _WIN64

#अपरिभाषय DWL_MSGRESULT
#अपरिभाषय DWL_DLGPROC
#अपरिभाषय DWL_USER
#यदि_अन्तः

#परिभाषय DWLP_MSGRESULT 0
#परिभाषय DWLP_DLGPROC DWLP_MSGRESULT + परिमाण(LRESULT)
#परिभाषय DWLP_USER DWLP_DLGPROC + परिमाण(DLGPROC)

#यदि_अपरिभाषितम् NOMSG

#यदि_परिभाषितम् UNICODE
#परिभाषय Is_Dialog_सन्देशः Is_Dialog_सन्देशः_W
#अन्यथा
#परिभाषय Is_Dialog_सन्देशः Is_Dialog_सन्देशः_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI Is_Dialog_सन्देशः_A(HWND hDlg,LPMSG lp_सन्देशः_2);
  WINUSERAPI WINBOOL WINAPI Is_Dialog_सन्देशः_W(HWND hDlg,LPMSG lp_सन्देशः_2);
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय DlgDirList DlgDirListW
#परिभाषय DlgDirSelectEx DlgDirSelectExW
#परिभाषय DlgDirListComboBox DlgDirListComboBoxW
#परिभाषय DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#अन्यथा
#परिभाषय DlgDirList DlgDirListA
#परिभाषय DlgDirSelectEx DlgDirSelectExA
#परिभाषय DlgDirListComboBox DlgDirListComboBoxA
#परिभाषय DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI MapDialogRect(HWND hDlg,LPRECT lpRect);
  WINUSERAPI पूर्णाङ्क WINAPI DlgDirListA(HWND hDlg,LPSTR lp_मार्गः_Spec,पूर्णाङ्क nIDListBox,पूर्णाङ्क n_IDStatic_मार्गः,UINT uFileType);
  WINUSERAPI पूर्णाङ्क WINAPI DlgDirListW(HWND hDlg,LPWSTR lp_मार्गः_Spec,पूर्णाङ्क nIDListBox,पूर्णाङ्क n_IDStatic_मार्गः,UINT uFileType);

#परिभाषय DDL_READWRITE 0x0000
#परिभाषय DDL_READONLY 0x0001
#परिभाषय DDL_HIDDEN 0x0002
#परिभाषय DDL_SYSTEM 0x0004
#परिभाषय DDL_DIRECTORY 0x0010
#परिभाषय DDL_ARCHIVE 0x0020

#परिभाषय DDL_POSTMSGS 0x2000
#परिभाषय DDL_DRIVES 0x4000
#परिभाषय DDL_EXCLUSIVE 0x8000

  WINUSERAPI WINBOOL WINAPI DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,पूर्णाङ्क ch_गणनम्,पूर्णाङ्क idListBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,पूर्णाङ्क ch_गणनम्,पूर्णाङ्क idListBox);
  WINUSERAPI पूर्णाङ्क WINAPI DlgDirListComboBoxA(HWND hDlg,LPSTR lp_मार्गः_Spec,पूर्णाङ्क nIDComboBox,पूर्णाङ्क n_IDStatic_मार्गः,UINT uFiletype);
  WINUSERAPI पूर्णाङ्क WINAPI DlgDirListComboBoxW(HWND hDlg,LPWSTR lp_मार्गः_Spec,पूर्णाङ्क nIDComboBox,पूर्णाङ्क n_IDStatic_मार्गः,UINT uFiletype);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,पूर्णाङ्क cch_बहिर्गमनम्,पूर्णाङ्क idComboBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,पूर्णाङ्क cch_बहिर्गमनम्,पूर्णाङ्क idComboBox);

#परिभाषय DS_ABSALIGN 0x01L
#परिभाषय DS_SYSMODAL 0x02L
#परिभाषय DS_LOCALEDIT 0x20L
#परिभाषय DS_SETFONT 0x40L
#परिभाषय DS_MODALFRAME 0x80L
#परिभाषय DS_NOIDLEMSG 0x100L
#परिभाषय DS_SETFOREGROUND 0x200L

#परिभाषय DS_3DLOOK 0x0004L
#परिभाषय DS_FIXEDSYS 0x0008L
#परिभाषय DS_NOFAILCREATE 0x0010L
#परिभाषय DS_CONTROL 0x0400L
#परिभाषय DS_CENTER 0x0800L
#परिभाषय DS_CENTERMOUSE 0x1000L
#परिभाषय DS_CONTEXTHELP 0x2000L

#परिभाषय DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#यदि(_WIN32_WCE >= 0x0500)
#परिभाषय DS_USEPIXELS 0x8000L
#यदि_अन्तः

#परिभाषय DM_GETDEFID (WM_USER+0)
#परिभाषय DM_SETDEFID (WM_USER+1)
#परिभाषय DM_REPOSITION (WM_USER+2)

#परिभाषय DC_HASDEFID 0x534B

#परिभाषय DLGC_WANTARROWS 0x0001
#परिभाषय DLGC_WANTTAB 0x0002
#परिभाषय DLGC_WANTALLKEYS 0x0004
#परिभाषय DLGC_WANTMESSAGE 0x0004
#परिभाषय DLGC_HASSETSEL 0x0008
#परिभाषय DLGC_DEFPUSHBUTTON 0x0010
#परिभाषय DLGC_UNDEFPUSHBUTTON 0x0020
#परिभाषय DLGC_RADIOBUTTON 0x0040
#परिभाषय DLGC_WANTCHARS 0x0080
#परिभाषय DLGC_STATIC 0x0100
#परिभाषय DLGC_BUTTON 0x2000

#परिभाषय LB_CTLCODE 0L

#परिभाषय LB_OKAY 0
#परिभाषय LB_ERR (-1)
#परिभाषय LB_ERRSPACE (-2)

#परिभाषय LBN_ERRSPACE (-2)
#परिभाषय LBN_SELCHANGE 1
#परिभाषय LBN_DBLCLK 2
#परिभाषय LBN_SELCANCEL 3
#परिभाषय LBN_SETFOCUS 4
#परिभाषय LBN_KILLFOCUS 5

#यदि_अपरिभाषितम् NOWINMESSAGES

#परिभाषय LB_ADDSTRING 0x0180
#परिभाषय LB_INSERTSTRING 0x0181
#परिभाषय LB_DELETESTRING 0x0182
#परिभाषय LB_SELITEMRANGEEX 0x0183
#परिभाषय LB_RESETCONTENT 0x0184
#परिभाषय LB_SETSEL 0x0185
#परिभाषय LB_SETCURSEL 0x0186
#परिभाषय LB_GETSEL 0x0187
#परिभाषय LB_GETCURSEL 0x0188
#परिभाषय LB_GETTEXT 0x0189
#परिभाषय LB_GETTEXTLEN 0x018A
#परिभाषय LB_GETCOUNT 0x018B
#परिभाषय LB_SELECTSTRING 0x018C
#परिभाषय LB_DIR 0x018D
#परिभाषय LB_GETTOPINDEX 0x018E
#परिभाषय LB_FINDSTRING 0x018F
#परिभाषय LB_GETSELCOUNT 0x0190
#परिभाषय LB_GETSELITEMS 0x0191
#परिभाषय LB_SETTABSTOPS 0x0192
#परिभाषय LB_GETHORIZONTALEXTENT 0x0193
#परिभाषय LB_SETHORIZONTALEXTENT 0x0194
#परिभाषय LB_SETCOLUMNWIDTH 0x0195
#परिभाषय LB_ADDFILE 0x0196
#परिभाषय LB_SETTOPINDEX 0x0197
#परिभाषय LB_GETITEMRECT 0x0198
#परिभाषय LB_GETITEMDATA 0x0199
#परिभाषय LB_SETITEMDATA 0x019A
#परिभाषय LB_SELITEMRANGE 0x019B
#परिभाषय LB_SETANCHORINDEX 0x019C
#परिभाषय LB_GETANCHORINDEX 0x019D
#परिभाषय LB_SETCARETINDEX 0x019E
#परिभाषय LB_GETCARETINDEX 0x019F
#परिभाषय LB_SETITEMHEIGHT 0x01A0
#परिभाषय LB_GETITEMHEIGHT 0x01A1
#परिभाषय LB_FINDSTRINGEXACT 0x01A2
#परिभाषय LB_SETLOCALE 0x01A5
#परिभाषय LB_GETLOCALE 0x01A6
#परिभाषय LB_SETCOUNT 0x01A7
#परिभाषय LB_INITSTORAGE 0x01A8
#परिभाषय LB_ITEMFROMPOINT 0x01A9
#यदि(_WIN32_WCE >= 0x0400)
#परिभाषय LB_MULTIPLEADDSTRING 0x01B1
#यदि_अन्तः
#परिभाषय LB_GETLISTBOXINFO 0x01B2
#परिभाषय LB_MSGMAX 0x01B3
#यदि_अन्तः

#यदि_अपरिभाषितम् NOWINSTYLES

#परिभाषय LBS_NOTIFY 0x0001L
#परिभाषय LBS_क्रमय 0x0002L
#परिभाषय LBS_NOREDRAW 0x0004L
#परिभाषय LBS_MULTIPLESEL 0x0008L
#परिभाषय LBS_OWNERDRAWFIXED 0x0010L
#परिभाषय LBS_OWNERDRAWVARIABLE 0x0020L
#परिभाषय LBS_HASSTRINGS 0x0040L
#परिभाषय LBS_USETABSTOPS 0x0080L
#परिभाषय LBS_NOINTEGRALHEIGHT 0x0100L
#परिभाषय LBS_MULTICOLUMN 0x0200L
#परिभाषय LBS_WANTKEYBOARDINPUT 0x0400L
#परिभाषय LBS_EXTENDEDSEL 0x0800L
#परिभाषय LBS_DISABLENOSCROLL 0x1000L
#परिभाषय LBS_NODATA 0x2000L
#परिभाषय LBS_NOSEL 0x4000L
#परिभाषय LBS_COMBOBOX 0x8000L

#परिभाषय LBS_STANDARD (LBS_NOTIFY | LBS_क्रमय | WS_VSCROLL | WS_BORDER)
#यदि_अन्तः

#परिभाषय CB_OKAY 0
#परिभाषय CB_ERR (-1)
#परिभाषय CB_ERRSPACE (-2)

#परिभाषय CBN_ERRSPACE (-1)
#परिभाषय CBN_SELCHANGE 1
#परिभाषय CBN_DBLCLK 2
#परिभाषय CBN_SETFOCUS 3
#परिभाषय CBN_KILLFOCUS 4
#परिभाषय CBN_EDITCHANGE 5
#परिभाषय CBN_EDITUPDATE 6
#परिभाषय CBN_DROPDOWN 7
#परिभाषय CBN_CLOSEUP 8
#परिभाषय CBN_SELENDOK 9
#परिभाषय CBN_SELENDCANCEL 10

#यदि_अपरिभाषितम् NOWINSTYLES

#परिभाषय CBS_SIMPLE 0x0001L
#परिभाषय CBS_DROPDOWN 0x0002L
#परिभाषय CBS_DROPDOWNLIST 0x0003L
#परिभाषय CBS_OWNERDRAWFIXED 0x0010L
#परिभाषय CBS_OWNERDRAWVARIABLE 0x0020L
#परिभाषय CBS_AUTOHSCROLL 0x0040L
#परिभाषय CBS_OEMCONVERT 0x0080L
#परिभाषय CBS_क्रमय 0x0100L
#परिभाषय CBS_HASSTRINGS 0x0200L
#परिभाषय CBS_NOINTEGRALHEIGHT 0x0400L
#परिभाषय CBS_DISABLENOSCROLL 0x0800L
#परिभाषय CBS_UPPERCASE 0x2000L
#परिभाषय CBS_LOWERCASE 0x4000L
#यदि_अन्तः

#यदि_अपरिभाषितम् NOWINMESSAGES
#परिभाषय CB_GETEDITSEL 0x0140
#परिभाषय CB_LIMITTEXT 0x0141
#परिभाषय CB_SETEDITSEL 0x0142
#परिभाषय CB_ADDSTRING 0x0143
#परिभाषय CB_DELETESTRING 0x0144
#परिभाषय CB_DIR 0x0145
#परिभाषय CB_GETCOUNT 0x0146
#परिभाषय CB_GETCURSEL 0x0147
#परिभाषय CB_GETLBTEXT 0x0148
#परिभाषय CB_GETLBTEXTLEN 0x0149
#परिभाषय CB_INSERTSTRING 0x014A
#परिभाषय CB_RESETCONTENT 0x014B
#परिभाषय CB_FINDSTRING 0x014C
#परिभाषय CB_SELECTSTRING 0x014D
#परिभाषय CB_SETCURSEL 0x014E
#परिभाषय CB_SHOWDROPDOWN 0x014F
#परिभाषय CB_GETITEMDATA 0x0150
#परिभाषय CB_SETITEMDATA 0x0151
#परिभाषय CB_GETDROPPEDCONTROLRECT 0x0152
#परिभाषय CB_SETITEMHEIGHT 0x0153
#परिभाषय CB_GETITEMHEIGHT 0x0154
#परिभाषय CB_SETEXTENDEDUI 0x0155
#परिभाषय CB_GETEXTENDEDUI 0x0156
#परिभाषय CB_GETDROPPEDSTATE 0x0157
#परिभाषय CB_FINDSTRINGEXACT 0x0158
#परिभाषय CB_SETLOCALE 0x0159
#परिभाषय CB_GETLOCALE 0x015A
#परिभाषय CB_GETTOPINDEX 0x015b
#परिभाषय CB_SETTOPINDEX 0x015c
#परिभाषय CB_GETHORIZONTALEXTENT 0x015d
#परिभाषय CB_SETHORIZONTALEXTENT 0x015e
#परिभाषय CB_GETDROPPEDWIDTH 0x015f
#परिभाषय CB_SETDROPPEDWIDTH 0x0160
#परिभाषय CB_INITSTORAGE 0x0161
#यदि(_WIN32_WCE >= 0x0400)
#परिभाषय CB_MULTIPLEADDSTRING 0x0163
#यदि_अन्तः
#परिभाषय CB_GETCOMBOBOXINFO 0x0164
#परिभाषय CB_MSGMAX 0x0165
#यदि_अन्तः

#यदि_अपरिभाषितम् NOWINSTYLES

#परिभाषय SBS_HORZ 0x0000L
#परिभाषय SBS_VERT 0x0001L
#परिभाषय SBS_TOPALIGN 0x0002L
#परिभाषय SBS_LEFTALIGN 0x0002L
#परिभाषय SBS_BOTTOMALIGN 0x0004L
#परिभाषय SBS_RIGHTALIGN 0x0004L
#परिभाषय SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#परिभाषय SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#परिभाषय SBS_SIZEBOX 0x0008L
#परिभाषय SBS_SIZEGRIP 0x0010L
#यदि_अन्तः

#यदि_अपरिभाषितम् NOWINMESSAGES
#परिभाषय SBM_SETPOS 0x00E0
#परिभाषय SBM_GETPOS 0x00E1
#परिभाषय SBM_SETRANGE 0x00E2
#परिभाषय SBM_SETRANGEREDRAW 0x00E6
#परिभाषय SBM_GETRANGE 0x00E3
#परिभाषय SBM_ENABLE_ARROWS 0x00E4
#परिभाषय SBM_SETSCROLLINFO 0x00E9
#परिभाषय SBM_GETSCROLLINFO 0x00EA
#परिभाषय SBM_GETSCROLLBARINFO 0x00EB

#परिभाषय SIF_RANGE 0x0001
#परिभाषय SIF_PAGE 0x0002
#परिभाषय SIF_POS 0x0004
#परिभाषय SIF_DISABLENOSCROLL 0x0008
#परिभाषय SIF_TRACKPOS 0x0010
#परिभाषय SIF_ALL (SIF_RANGE | SIF_PAGE | SIF_POS | SIF_TRACKPOS)

  प्रकारनिर्देश संरचना चिह्नकम्_SCROLLINFO {
    UINT cb_आकार;
    UINT f_आवरणम्;
    पूर्णाङ्क nMin;
    पूर्णाङ्क nMax;
    UINT nPage;
    पूर्णाङ्क nPos;
    पूर्णाङ्क nTrackPos;
  } SCROLLINFO,*LPSCROLLINFO;
  प्रकारनिर्देश SCROLLINFO CONST *LPCSCROLLINFO;

  WINUSERAPI पूर्णाङ्क WINAPI समुच्चयः_Scroll_Info(HWND hwnd,पूर्णाङ्क nBar,LPCSCROLLINFO lpsi,WINBOOL redraw);
  WINUSERAPI WINBOOL WINAPI GetScrollInfo(HWND hwnd,पूर्णाङ्क nBar,LPSCROLLINFO lpsi);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् NOMDI

#परिभाषय MDIS_ALLCHILDSTYLES 0x0001

#परिभाषय MDITILE_VERTICAL 0x0000
#परिभाषय MDITILE_HORIZONTAL 0x0001
#परिभाषय MDITILE_SKIPDISABLED 0x0002
#परिभाषय MDITILE_ZORDER 0x0004

  प्रकारनिर्देश संरचना चिह्नकम्_MDICREATESTRUCTA {
    LPCSTR szClass;
    LPCSTR szTitle;
    HANDLE hOwner;
    पूर्णाङ्क x;
    पूर्णाङ्क y;
    पूर्णाङ्क cx;
    पूर्णाङ्क cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTA,*LPMDICREATESTRUCTA;

  प्रकारनिर्देश संरचना चिह्नकम्_MDICREATESTRUCTW {
    LPCWSTR szClass;
    LPCWSTR szTitle;
    HANDLE hOwner;
    पूर्णाङ्क x;
    पूर्णाङ्क y;
    पूर्णाङ्क cx;
    पूर्णाङ्क cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTW,*LPMDICREATESTRUCTW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश MDICREATESTRUCTW MDICREATESTRUCT;
  प्रकारनिर्देश LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#अन्यथा
  प्रकारनिर्देश MDICREATESTRUCTA MDICREATESTRUCT;
  प्रकारनिर्देश LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_CLIENTCREATESTRUCT {
    HANDLE h_गवाक्षः_Menu;
    UINT idFirstChild;
  } CLIENTCREATESTRUCT,*LPCLIENTCREATESTRUCT;

#यदि_परिभाषितम् UNICODE
#परिभाषय DefFrameProc DefFrameProcW
#परिभाषय DefMDIChildProc DefMDIChildProcW
#परिभाषय CreateMDIWindow CreateMDIWindowW
#अन्यथा
#परिभाषय DefFrameProc DefFrameProcA
#परिभाषय DefMDIChildProc DefMDIChildProcA
#परिभाषय CreateMDIWindow CreateMDIWindowA
#यदि_अन्तः

  WINUSERAPI LRESULT WINAPI DefFrameProcA(HWND hWnd,HWND hWndMDIClient,UINT u_सन्देशः,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefFrameProcW(HWND hWnd,HWND hWndMDIClient,UINT u_सन्देशः,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcA(HWND hWnd,UINT u_सन्देशः,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcW(HWND hWnd,UINT u_सन्देशः,WPARAM wParam,LPARAM lParam);

#यदि_अपरिभाषितम् NOMSG
  WINUSERAPI WINBOOL WINAPI TranslateMDISysAccel(HWND hWndClient,LPMSG lp_सन्देशः_2);
#यदि_अन्तः

  WINUSERAPI UINT WINAPI ArrangeIconicWindows(HWND hWnd);
  WINUSERAPI HWND WINAPI CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lp_गवाक्षः_Name,DWORD dwStyle,पूर्णाङ्क X,पूर्णाङ्क Y,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI HWND WINAPI CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lp_गवाक्षः_Name,DWORD dwStyle,पूर्णाङ्क X,पूर्णाङ्क Y,पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight,HWND hWndParent,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI WORD WINAPI TileWindows(HWND hwndParent,UINT wHow,CONST RECT *lpRect,UINT cKids,ध्रुव HWND *lpKids);
  WINUSERAPI WORD WINAPI CascadeWindows(HWND hwndParent,UINT wHow,CONST RECT *lpRect,UINT cKids,ध्रुव HWND *lpKids);
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् NOHELP

  प्रकारनिर्देश DWORD HELPPOLY;
  प्रकारनिर्देश संरचना चिह्नकम्_MULTIKEYHELPA {
    DWORD mk_आकार;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
  } MULTIKEYHELPA,*PMULTIKEYHELPA,*LPMULTIKEYHELPA;

  प्रकारनिर्देश संरचना चिह्नकम्_MULTIKEYHELPW {
    DWORD mk_आकार;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
  } MULTIKEYHELPW,*PMULTIKEYHELPW,*LPMULTIKEYHELPW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश MULTIKEYHELPW MULTIKEYHELP;
  प्रकारनिर्देश PMULTIKEYHELPW PMULTIKEYHELP;
  प्रकारनिर्देश LPMULTIKEYHELPW LPMULTIKEYHELP;
#अन्यथा
  प्रकारनिर्देश MULTIKEYHELPA MULTIKEYHELP;
  प्रकारनिर्देश PMULTIKEYHELPA PMULTIKEYHELP;
  प्रकारनिर्देश LPMULTIKEYHELPA LPMULTIKEYHELP;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_HELPWININFOA {
    पूर्णाङ्क w_Struct_आकार;
    पूर्णाङ्क x;
    पूर्णाङ्क y;
    पूर्णाङ्क dx;
    पूर्णाङ्क dy;
    पूर्णाङ्क wMax;
    CHAR rgchMember[2];
  } HELPWININFOA,*PHELPWININFOA,*LPHELPWININFOA;

  प्रकारनिर्देश संरचना चिह्नकम्_HELPWININFOW {
    पूर्णाङ्क w_Struct_आकार;
    पूर्णाङ्क x;
    पूर्णाङ्क y;
    पूर्णाङ्क dx;
    पूर्णाङ्क dy;
    पूर्णाङ्क wMax;
    WCHAR rgchMember[2];
  } HELPWININFOW,*PHELPWININFOW,*LPHELPWININFOW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश HELPWININFOW HELPWININFO;
  प्रकारनिर्देश PHELPWININFOW PHELPWININFO;
  प्रकारनिर्देश LPHELPWININFOW LPHELPWININFO;
#अन्यथा
  प्रकारनिर्देश HELPWININFOA HELPWININFO;
  प्रकारनिर्देश PHELPWININFOA PHELPWININFO;
  प्रकारनिर्देश LPHELPWININFOA LPHELPWININFO;
#यदि_अन्तः

#परिभाषय HELP_CONTEXT 0x0001L
#परिभाषय HELP_QUIT 0x0002L
#परिभाषय HELP_सूचकांक 0x0003L
#परिभाषय HELP_CONTENTS 0x0003L
#परिभाषय HELP_HELPONHELP 0x0004L
#परिभाषय HELP_SETINDEX 0x0005L
#परिभाषय HELP_SETCONTENTS 0x0005L
#परिभाषय HELP_CONTEXTPOPUP 0x0008L
#परिभाषय HELP_FORCEFILE 0x0009L
#परिभाषय HELP_कुञ्चिका 0x0101L
#परिभाषय HELP_COMMAND 0x0102L
#परिभाषय HELP_PARTIALKEY 0x0105L
#परिभाषय HELP_MULTIKEY 0x0201L
#परिभाषय HELP_SETWINPOS 0x0203L
#परिभाषय HELP_CONTEXTMENU 0x000a
#परिभाषय HELP_FINDER 0x000b
#परिभाषय HELP_WM_HELP 0x000c
#परिभाषय HELP_SETPOPUP_POS 0x000d

#परिभाषय HELP_TCARD 0x8000
#परिभाषय HELP_TCARD_दत्त 0x0010
#परिभाषय HELP_TCARD_OTHER_CALLER 0x0011

#परिभाषय IDH_NO_HELP 28440
#परिभाषय IDH_MISSING_CONTEXT 28441
#परिभाषय IDH_GENERIC_HELP_BUTTON 28442
#परिभाषय IDH_OK 28443
#परिभाषय IDH_CANCEL 28444
#परिभाषय IDH_HELP 28445

#यदि_परिभाषितम् UNICODE
#परिभाषय WinHelp WinHelpW
#अन्यथा
#परिभाषय WinHelp WinHelpA
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dw_दत्त);
  WINUSERAPI WINBOOL WINAPI WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dw_दत्त);
#यदि_अन्तः

#परिभाषय GR_GDIOBJECTS 0
#परिभाषय GR_USEROBJECTS 1

  WINUSERAPI DWORD WINAPI GetGuiResources(HANDLE hProcess,DWORD uiFlags);

#यदि_अपरिभाषितम् NOSYSPARAMSINFO

#परिभाषय SPI_GETBEEP 0x0001
#परिभाषय SPI_SETBEEP 0x0002
#परिभाषय SPI_GETMOUSE 0x0003
#परिभाषय SPI_SETMOUSE 0x0004
#परिभाषय SPI_GETBORDER 0x0005
#परिभाषय SPI_SETBORDER 0x0006
#परिभाषय SPI_GETKEYBOARDSPEED 0x000A
#परिभाषय SPI_SETKEYBOARDSPEED 0x000B
#परिभाषय SPI_LANGDRIVER 0x000C
#परिभाषय SPI_ICONHORIZONTALSPACING 0x000D
#परिभाषय SPI_GETSCREENSAVETIMEOUT 0x000E
#परिभाषय SPI_SETSCREENSAVETIMEOUT 0x000F
#परिभाषय SPI_GETSCREENSAVEACTIVE 0x0010
#परिभाषय SPI_SETSCREENSAVEACTIVE 0x0011
#परिभाषय SPI_GETGRIDGRANULARITY 0x0012
#परिभाषय SPI_SETGRIDGRANULARITY 0x0013
#परिभाषय SPI_SETDESKWALLPAPER 0x0014
#परिभाषय SPI_SETDESKPATTERN 0x0015
#परिभाषय SPI_GETKEYBOARDDELAY 0x0016
#परिभाषय SPI_SETKEYBOARDDELAY 0x0017
#परिभाषय SPI_ICONVERTICALSPACING 0x0018
#परिभाषय SPI_GETICONTITLEWRAP 0x0019
#परिभाषय SPI_SETICONTITLEWRAP 0x001A
#परिभाषय SPI_GETMENUDROPALIGNMENT 0x001B
#परिभाषय SPI_SETMENUDROPALIGNMENT 0x001C
#परिभाषय SPI_SETDOUBLECLKWIDTH 0x001D
#परिभाषय SPI_SETDOUBLECLKHEIGHT 0x001E
#परिभाषय SPI_GETICONTITLELOGFONT 0x001F
#परिभाषय SPI_SETDOUBLECLICKTIME 0x0020
#परिभाषय SPI_SETMOUSEBUTTONSWAP 0x0021
#परिभाषय SPI_SETICONTITLELOGFONT 0x0022
#परिभाषय SPI_GETFASTTASKSWITCH 0x0023
#परिभाषय SPI_SETFASTTASKSWITCH 0x0024
#परिभाषय SPI_SETDRAGFULLWINDOWS 0x0025
#परिभाषय SPI_GETDRAGFULLWINDOWS 0x0026
#परिभाषय SPI_GETNONCLIENTMETRICS 0x0029
#परिभाषय SPI_SETNONCLIENTMETRICS 0x002A
#परिभाषय SPI_GETMINIMIZEDMETRICS 0x002B
#परिभाषय SPI_SETMINIMIZEDMETRICS 0x002C
#परिभाषय SPI_GETICONMETRICS 0x002D
#परिभाषय SPI_SETICONMETRICS 0x002E
#परिभाषय SPI_SETWORKAREA 0x002F
#परिभाषय SPI_GETWORKAREA 0x0030
#परिभाषय SPI_SETPENWINDOWS 0x0031

#परिभाषय SPI_GETHIGHCONTRAST 0x0042
#परिभाषय SPI_SETHIGHCONTRAST 0x0043
#परिभाषय SPI_GETKEYBOARDPREF 0x0044
#परिभाषय SPI_SETKEYBOARDPREF 0x0045
#परिभाषय SPI_GETSCREENREADER 0x0046
#परिभाषय SPI_SETSCREENREADER 0x0047
#परिभाषय SPI_GETANIMATION 0x0048
#परिभाषय SPI_SETANIMATION 0x0049
#परिभाषय SPI_GETFONTSMOOTHING 0x004A
#परिभाषय SPI_SETFONTSMOOTHING 0x004B
#परिभाषय SPI_SETDRAGWIDTH 0x004C
#परिभाषय SPI_SETDRAGHEIGHT 0x004D
#परिभाषय SPI_SETHANDHELD 0x004E
#परिभाषय SPI_GETLOWPOWERTIMEOUT 0x004F
#परिभाषय SPI_GETPOWEROFFTIMEOUT 0x0050
#परिभाषय SPI_SETLOWPOWERTIMEOUT 0x0051
#परिभाषय SPI_SETPOWEROFFTIMEOUT 0x0052
#परिभाषय SPI_GETLOWPOWERACTIVE 0x0053
#परिभाषय SPI_GETPOWEROFFACTIVE 0x0054
#परिभाषय SPI_SETLOWPOWERACTIVE 0x0055
#परिभाषय SPI_SETPOWEROFFACTIVE 0x0056
#परिभाषय SPI_SETCURSORS 0x0057
#परिभाषय SPI_SETICONS 0x0058
#परिभाषय SPI_GETDEFAULTINPUTLANG 0x0059
#परिभाषय SPI_SETDEFAULTINPUTLANG 0x005A
#परिभाषय SPI_SETLANGTOGGLE 0x005B
#परिभाषय SPI_GETWINDOWSEXTENSION 0x005C
#परिभाषय SPI_SETMOUSETRAILS 0x005D
#परिभाषय SPI_GETMOUSETRAILS 0x005E
#परिभाषय SPI_SETSCREENSAVERRUNNING 0x0061
#परिभाषय SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#परिभाषय SPI_GETFILTERKEYS 0x0032
#परिभाषय SPI_SETFILTERKEYS 0x0033
#परिभाषय SPI_GETTOGGLEKEYS 0x0034
#परिभाषय SPI_SETTOGGLEKEYS 0x0035
#परिभाषय SPI_GETMOUSEKEYS 0x0036
#परिभाषय SPI_SETMOUSEKEYS 0x0037
#परिभाषय SPI_GETSHOWSOUNDS 0x0038
#परिभाषय SPI_SETSHOWSOUNDS 0x0039
#परिभाषय SPI_GETSTICKYKEYS 0x003A
#परिभाषय SPI_SETSTICKYKEYS 0x003B
#परिभाषय SPI_GETACCESSTIMEOUT 0x003C
#परिभाषय SPI_SETACCESSTIMEOUT 0x003D
#परिभाषय SPI_GETSERIALKEYS 0x003E
#परिभाषय SPI_SETSERIALKEYS 0x003F
#परिभाषय SPI_GETSOUNDSENTRY 0x0040
#परिभाषय SPI_SETSOUNDSENTRY 0x0041
#परिभाषय SPI_GETSNAPTODEFBUTTON 0x005F
#परिभाषय SPI_SETSNAPTODEFBUTTON 0x0060
#परिभाषय SPI_GETMOUSEHOVERWIDTH 0x0062
#परिभाषय SPI_SETMOUSEHOVERWIDTH 0x0063
#परिभाषय SPI_GETMOUSEHOVERHEIGHT 0x0064
#परिभाषय SPI_SETMOUSEHOVERHEIGHT 0x0065
#परिभाषय SPI_GETMOUSEHOVERTIME 0x0066
#परिभाषय SPI_SETMOUSEHOVERTIME 0x0067
#परिभाषय SPI_GETWHEELSCROLLLINES 0x0068
#परिभाषय SPI_SETWHEELSCROLLLINES 0x0069
#परिभाषय SPI_GETMENUSHOWDELAY 0x006A
#परिभाषय SPI_SETMENUSHOWDELAY 0x006B
#परिभाषय SPI_GETSHOWIMEUI 0x006E
#परिभाषय SPI_SETSHOWIMEUI 0x006F
#परिभाषय SPI_GETMOUSESPEED 0x0070
#परिभाषय SPI_SETMOUSESPEED 0x0071
#परिभाषय SPI_GETSCREENSAVERRUNNING 0x0072
#परिभाषय SPI_GETDESKWALLPAPER 0x0073

#परिभाषय SPI_GETACTIVEWINDOWTRACKING 0x1000
#परिभाषय SPI_SETACTIVEWINDOWTRACKING 0x1001
#परिभाषय SPI_GETMENUANIMATION 0x1002
#परिभाषय SPI_SETMENUANIMATION 0x1003
#परिभाषय SPI_GETCOMBOBOXANIMATION 0x1004
#परिभाषय SPI_SETCOMBOBOXANIMATION 0x1005
#परिभाषय SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#परिभाषय SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#परिभाषय SPI_GETGRADIENTCAPTIONS 0x1008
#परिभाषय SPI_SETGRADIENTCAPTIONS 0x1009
#परिभाषय SPI_GETKEYBOARDCUES 0x100A
#परिभाषय SPI_SETKEYBOARDCUES 0x100B
#परिभाषय SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#परिभाषय SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#परिभाषय SPI_GETACTIVEWNDTRKZORDER 0x100C
#परिभाषय SPI_SETACTIVEWNDTRKZORDER 0x100D
#परिभाषय SPI_GETHOTTRACKING 0x100E
#परिभाषय SPI_SETHOTTRACKING 0x100F
#परिभाषय SPI_GETMENUFADE 0x1012
#परिभाषय SPI_SETMENUFADE 0x1013
#परिभाषय SPI_GETSELECTIONFADE 0x1014
#परिभाषय SPI_SETSELECTIONFADE 0x1015
#परिभाषय SPI_GETTOOLTIPANIMATION 0x1016
#परिभाषय SPI_SETTOOLTIPANIMATION 0x1017
#परिभाषय SPI_GETTOOLTIPFADE 0x1018
#परिभाषय SPI_SETTOOLTIPFADE 0x1019
#परिभाषय SPI_GETCURSORSHADOW 0x101A
#परिभाषय SPI_SETCURSORSHADOW 0x101B
#परिभाषय SPI_GETMOUSESONAR 0x101C
#परिभाषय SPI_SETMOUSESONAR 0x101D
#परिभाषय SPI_GETMOUSECLICKLOCK 0x101E
#परिभाषय SPI_SETMOUSECLICKLOCK 0x101F
#परिभाषय SPI_GETMOUSEVANISH 0x1020
#परिभाषय SPI_SETMOUSEVANISH 0x1021
#परिभाषय SPI_GETFLATMENU 0x1022
#परिभाषय SPI_SETFLATMENU 0x1023
#परिभाषय SPI_GETDROPSHADOW 0x1024
#परिभाषय SPI_SETDROPSHADOW 0x1025
#परिभाषय SPI_GETBLOCKSENDINPUTRESETS 0x1026
#परिभाषय SPI_SETBLOCKSENDINPUTRESETS 0x1027
#परिभाषय SPI_GETUIEFFECTS 0x103E
#परिभाषय SPI_SETUIEFFECTS 0x103F
#परिभाषय SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#परिभाषय SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#परिभाषय SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#परिभाषय SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#परिभाषय SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#परिभाषय SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#परिभाषय SPI_GETCARETWIDTH 0x2006
#परिभाषय SPI_SETCARETWIDTH 0x2007
#परिभाषय SPI_GETMOUSECLICKLOCKTIME 0x2008
#परिभाषय SPI_SETMOUSECLICKLOCKTIME 0x2009
#परिभाषय SPI_GETFONTSMOOTHINGTYPE 0x200A
#परिभाषय SPI_SETFONTSMOOTHINGTYPE 0x200B

#परिभाषय FE_FONTSMOOTHINGSTANDARD 0x0001
#परिभाषय FE_FONTSMOOTHINGCLEARTYPE 0x0002
#परिभाषय FE_FONTSMOOTHINGDOCKING 0x8000

#परिभाषय SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#परिभाषय SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#परिभाषय SPI_GETFOCUSBORDERWIDTH 0x200E
#परिभाषय SPI_SETFOCUSBORDERWIDTH 0x200F
#परिभाषय SPI_GETFOCUSBORDERHEIGHT 0x2010
#परिभाषय SPI_SETFOCUSBORDERHEIGHT 0x2011
#परिभाषय SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#परिभाषय SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#परिभाषय FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#परिभाषय FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#परिभाषय SPIF_UPDATEINIFILE 0x0001
#परिभाषय SPIF_SENDWININICHANGE 0x0002
#परिभाषय SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#परिभाषय METRICS_USEDEFAULT -1
#यदि_परिभाषितम् _WINGDI_
#यदि_अपरिभाषितम् NOGDI
  प्रकारनिर्देश संरचना चिह्नकम्_NONCLIENTMETRICSA {
    UINT cb_आकार;
    पूर्णाङ्क i_Border_विस्तारः;
    पूर्णाङ्क i_Scroll_विस्तारः;
    पूर्णाङ्क iScrollHeight;
    पूर्णाङ्क i_Caption_विस्तारः;
    पूर्णाङ्क iCaptionHeight;
    LOGFONTA lfCaptionFont;
    पूर्णाङ्क i_Sm_Caption_विस्तारः;
    पूर्णाङ्क iSmCaptionHeight;
    LOGFONTA lfSmCaptionFont;
    पूर्णाङ्क i_Menu_विस्तारः;
    पूर्णाङ्क iMenuHeight;
    LOGFONTA lfMenuFont;
    LOGFONTA lf_स्थितिः_Font;
    LOGFONTA lf_सन्देशः_Font;
  } NONCLIENTMETRICSA,*PNONCLIENTMETRICSA,*LPNONCLIENTMETRICSA;

  प्रकारनिर्देश संरचना चिह्नकम्_NONCLIENTMETRICSW {
    UINT cb_आकार;
    पूर्णाङ्क i_Border_विस्तारः;
    पूर्णाङ्क i_Scroll_विस्तारः;
    पूर्णाङ्क iScrollHeight;
    पूर्णाङ्क i_Caption_विस्तारः;
    पूर्णाङ्क iCaptionHeight;
    LOGFONTW lfCaptionFont;
    पूर्णाङ्क i_Sm_Caption_विस्तारः;
    पूर्णाङ्क iSmCaptionHeight;
    LOGFONTW lfSmCaptionFont;
    पूर्णाङ्क i_Menu_विस्तारः;
    पूर्णाङ्क iMenuHeight;
    LOGFONTW lfMenuFont;
    LOGFONTW lf_स्थितिः_Font;
    LOGFONTW lf_सन्देशः_Font;
  } NONCLIENTMETRICSW,*PNONCLIENTMETRICSW,*LPNONCLIENTMETRICSW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश NONCLIENTMETRICSW NONCLIENTMETRICS;
  प्रकारनिर्देश PNONCLIENTMETRICSW PNONCLIENTMETRICS;
  प्रकारनिर्देश LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#अन्यथा
  प्रकारनिर्देश NONCLIENTMETRICSA NONCLIENTMETRICS;
  प्रकारनिर्देश PNONCLIENTMETRICSA PNONCLIENTMETRICS;
  प्रकारनिर्देश LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय ARW_BOTTOMLEFT 0x0000L
#परिभाषय ARW_BOTTOMRIGHT 0x0001L
#परिभाषय ARW_TOPLEFT 0x0002L
#परिभाषय ARW_TOPRIGHT 0x0003L
#परिभाषय ARW_STARTMASK 0x0003L
#परिभाषय ARW_STARTRIGHT 0x0001L
#परिभाषय ARW_STARTTOP 0x0002L

#परिभाषय ARW_वामः 0x0000L
#परिभाषय ARW_दक्षिणः 0x0000L
#परिभाषय ARW_ऊर्ध्वम् 0x0004L
#परिभाषय ARW_अधस्तात् 0x0004L
#परिभाषय ARW_HIDE 0x0008L

  प्रकारनिर्देश संरचना चिह्नकम्_MINIMIZEDMETRICS {
    UINT cb_आकार;
    पूर्णाङ्क i_विस्तारः;
    पूर्णाङ्क iHorzGap;
    पूर्णाङ्क iVertGap;
    पूर्णाङ्क iArrange;
  } MINIMIZEDMETRICS,*PMINIMIZEDMETRICS,*LPMINIMIZEDMETRICS;

#यदि_परिभाषितम् _WINGDI_
#यदि_अपरिभाषितम् NOGDI
  प्रकारनिर्देश संरचना चिह्नकम्_ICONMETRICSA {
    UINT cb_आकार;
    पूर्णाङ्क iHorzSpacing;
    पूर्णाङ्क iVertSpacing;
    पूर्णाङ्क iTitleWrap;
    LOGFONTA lfFont;
  } ICONMETRICSA,*PICONMETRICSA,*LPICONMETRICSA;

  प्रकारनिर्देश संरचना चिह्नकम्_ICONMETRICSW {
    UINT cb_आकार;
    पूर्णाङ्क iHorzSpacing;
    पूर्णाङ्क iVertSpacing;
    पूर्णाङ्क iTitleWrap;
    LOGFONTW lfFont;
  } ICONMETRICSW,*PICONMETRICSW,*LPICONMETRICSW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश ICONMETRICSW ICONMETRICS;
  प्रकारनिर्देश PICONMETRICSW PICONMETRICS;
  प्रकारनिर्देश LPICONMETRICSW LPICONMETRICS;
#अन्यथा
  प्रकारनिर्देश ICONMETRICSA ICONMETRICS;
  प्रकारनिर्देश PICONMETRICSA PICONMETRICS;
  प्रकारनिर्देश LPICONMETRICSA LPICONMETRICS;
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_ANIMATIONINFO {
    UINT cb_आकार;
    पूर्णाङ्क iMinAnimate;
  } ANIMATIONINFO,*LPANIMATIONINFO;

  प्रकारनिर्देश संरचना चिह्नकम्_SERIALKEYSA {
    UINT cb_आकार;
    DWORD dwFlags;
    LPSTR lpsz_सक्रिय_पत्तनम्;
    LPSTR lpsz_पत्तनम्;
    UINT i_Baud_दरः;
    UINT i_पत्तनम्_State;
    UINT i_सक्रिय;
  } SERIALKEYSA,*LPSERIALKEYSA;

  प्रकारनिर्देश संरचना चिह्नकम्_SERIALKEYSW {
    UINT cb_आकार;
    DWORD dwFlags;
    LPWSTR lpsz_सक्रिय_पत्तनम्;
    LPWSTR lpsz_पत्तनम्;
    UINT i_Baud_दरः;
    UINT i_पत्तनम्_State;
    UINT i_सक्रिय;
  } SERIALKEYSW,*LPSERIALKEYSW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश SERIALKEYSW SERIALKEYS;
  प्रकारनिर्देश LPSERIALKEYSW LPSERIALKEYS;
#अन्यथा
  प्रकारनिर्देश SERIALKEYSA SERIALKEYS;
  प्रकारनिर्देश LPSERIALKEYSA LPSERIALKEYS;
#यदि_अन्तः

#परिभाषय SERKF_SERIALKEYSON 0x00000001
#परिभाषय SERKF_उपलब्धम् 0x00000002
#परिभाषय SERKF_INDICATOR 0x00000004

  प्रकारनिर्देश संरचना चिह्नकम्_HIGHCONTRASTA {
    UINT cb_आकार;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
  } HIGHCONTRASTA,*LPHIGHCONTRASTA;

  प्रकारनिर्देश संरचना चिह्नकम्_HIGHCONTRASTW {
    UINT cb_आकार;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
  } HIGHCONTRASTW,*LPHIGHCONTRASTW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश HIGHCONTRASTW HIGHCONTRAST;
  प्रकारनिर्देश LPHIGHCONTRASTW LPHIGHCONTRAST;
#अन्यथा
  प्रकारनिर्देश HIGHCONTRASTA HIGHCONTRAST;
  प्रकारनिर्देश LPHIGHCONTRASTA LPHIGHCONTRAST;
#यदि_अन्तः

#परिभाषय HCF_HIGHCONTRASTON 0x00000001
#परिभाषय HCF_उपलब्धम् 0x00000002
#परिभाषय HCF_HOTKEYACTIVE 0x00000004
#परिभाषय HCF_CONFIRMHOTKEY 0x00000008
#परिभाषय HCF_HOTKEYSOUND 0x00000010
#परिभाषय HCF_INDICATOR 0x00000020
#परिभाषय HCF_HOTKEYAVAILABLE 0x00000040
#परिभाषय HCF_LOGONDESKTOP 0x00000100
#परिभाषय HCF_DEFAULTDESKTOP 0x00000200

#परिभाषय CDS_UPDATEREGISTRY 0x00000001
#परिभाषय CDS_TEST 0x00000002
#परिभाषय CDS_FULLSCREEN 0x00000004
#परिभाषय CDS_GLOBAL 0x00000008
#परिभाषय CDS_समुच्चयः_PRIMARY 0x00000010
#परिभाषय CDS_VIDEOPARAMETERS 0x00000020
#परिभाषय CDS_RESET 0x40000000
#परिभाषय CDS_NORESET 0x10000000

//gr #include <tvout.h>

#परिभाषय DISP_CHANGE_SUCCESSFUL 0
#परिभाषय DISP_CHANGE_RESTART 1
#परिभाषय DISP_CHANGE_FAILED -1
#परिभाषय DISP_CHANGE_BADMODE -2
#परिभाषय DISP_CHANGE_NOTUPDATED -3
#परिभाषय DISP_CHANGE_BADFLAGS -4
#परिभाषय DISP_CHANGE_BADPARAM -5
#परिभाषय DISP_CHANGE_BADDUALVIEW -6

#यदि_परिभाषितम् _WINGDI_
#यदि_अपरिभाषितम् NOGDI

#यदि_परिभाषितम् UNICODE
#परिभाषय ChangeDisplaySettings ChangeDisplaySettingsW
#परिभाषय ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#परिभाषय EnumDisplaySettings EnumDisplaySettingsW
#परिभाषय EnumDisplaySettingsEx EnumDisplaySettingsExW
#परिभाषय EnumDisplayDevices EnumDisplayDevicesW
#अन्यथा
#परिभाषय ChangeDisplaySettings ChangeDisplaySettingsA
#परिभाषय ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#परिभाषय EnumDisplaySettings EnumDisplaySettingsA
#परिभाषय EnumDisplaySettingsEx EnumDisplaySettingsExA
#परिभाषय EnumDisplayDevices EnumDisplayDevicesA
#यदि_अन्तः

  WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lp_Dev_बहुलकम्,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsW(LPDEVMODEW lp_Dev_बहुलकम्,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,LPDEVMODEA lp_Dev_बहुलकम्,HWND hwnd,DWORD dwflags,LPVOID lParam);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,LPDEVMODEW lp_Dev_बहुलकम्,HWND hwnd,DWORD dwflags,LPVOID lParam);

#परिभाषय ENUM_CURRENT_SETTINGS ((DWORD)-1)
#परिभाषय ENUM_REGISTRY_SETTINGS ((DWORD)-2)

  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD i_बहुलकम्_अङ्कः,LPDEVMODEA lp_Dev_बहुलकम्);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD i_बहुलकम्_अङ्कः,LPDEVMODEW lp_Dev_बहुलकम्);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD i_बहुलकम्_अङ्कः,LPDEVMODEA lp_Dev_बहुलकम्,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD i_बहुलकम्_अङ्कः,LPDEVMODEW lp_Dev_बहुलकम्,DWORD dwFlags);

#परिभाषय EDS_RAWMODE 0x00000002

  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesA(LPCSTR lpDevice,DWORD i_Dev_अङ्कः,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD i_Dev_अङ्कः,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय SystemParametersInfo SystemParametersInfoW
#अन्यथा
#परिभाषय SystemParametersInfo SystemParametersInfoA
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
  WINUSERAPI WINBOOL WINAPI SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_FILTERKEYS {
    UINT cb_आकार;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
  } FILTERKEYS,*LPFILTERKEYS;

#परिभाषय FKF_FILTERKEYSON 0x00000001
#परिभाषय FKF_उपलब्धम् 0x00000002
#परिभाषय FKF_HOTKEYACTIVE 0x00000004
#परिभाषय FKF_CONFIRMHOTKEY 0x00000008
#परिभाषय FKF_HOTKEYSOUND 0x00000010
#परिभाषय FKF_INDICATOR 0x00000020
#परिभाषय FKF_CLICKON 0x00000040

  प्रकारनिर्देश संरचना चिह्नकम्_STICKYKEYS {
    UINT cb_आकार;
    DWORD dwFlags;
  } STICKYKEYS,*LPSTICKYKEYS;

#परिभाषय SKF_STICKYKEYSON 0x00000001
#परिभाषय SKF_उपलब्धम् 0x00000002
#परिभाषय SKF_HOTKEYACTIVE 0x00000004
#परिभाषय SKF_CONFIRMHOTKEY 0x00000008
#परिभाषय SKF_HOTKEYSOUND 0x00000010
#परिभाषय SKF_INDICATOR 0x00000020
#परिभाषय SKF_AUDIBLEFEEDBACK 0x00000040
#परिभाषय SKF_TRISTATE 0x00000080
#परिभाषय SKF_TWOKEYSOFF 0x00000100
#परिभाषय SKF_LALTLATCHED 0x10000000
#परिभाषय SKF_LCTLLATCHED 0x04000000
#परिभाषय SKF_LSHIFTLATCHED 0x01000000
#परिभाषय SKF_RALTLATCHED 0x20000000
#परिभाषय SKF_RCTLLATCHED 0x08000000
#परिभाषय SKF_RSHIFTLATCHED 0x02000000
#परिभाषय SKF_LWINLATCHED 0x40000000
#परिभाषय SKF_RWINLATCHED 0x80000000
#परिभाषय SKF_LALTLOCKED 0x00100000
#परिभाषय SKF_LCTLLOCKED 0x00040000
#परिभाषय SKF_LSHIFTLOCKED 0x00010000
#परिभाषय SKF_RALTLOCKED 0x00200000
#परिभाषय SKF_RCTLLOCKED 0x00080000
#परिभाषय SKF_RSHIFTLOCKED 0x00020000
#परिभाषय SKF_LWINLOCKED 0x00400000
#परिभाषय SKF_RWINLOCKED 0x00800000

  प्रकारनिर्देश संरचना चिह्नकम्_MOUSEKEYS {
    UINT cb_आकार;
    DWORD dwFlags;
    DWORD i_Max_जवः;
    DWORD i_Time_गन्तव्यम्_Max_जवः;
    DWORD i_Ctrl_जवः;
    DWORD dwReserved1;
    DWORD dwReserved2;
  } MOUSEKEYS,*LPMOUSEKEYS;

#परिभाषय MKF_MOUSEKEYSON 0x00000001
#परिभाषय MKF_उपलब्धम् 0x00000002
#परिभाषय MKF_HOTKEYACTIVE 0x00000004
#परिभाषय MKF_CONFIRMHOTKEY 0x00000008
#परिभाषय MKF_HOTKEYSOUND 0x00000010
#परिभाषय MKF_INDICATOR 0x00000020
#परिभाषय MKF_MODIFIERS 0x00000040
#परिभाषय MKF_REPLACENUMBERS 0x00000080
#परिभाषय MKF_LEFTBUTTONSEL 0x10000000
#परिभाषय MKF_RIGHTBUTTONSEL 0x20000000
#परिभाषय MKF_LEFTBUTTONDOWN 0x01000000
#परिभाषय MKF_RIGHTBUTTONDOWN 0x02000000
#परिभाषय MKF_MOUSEMODE 0x80000000

  प्रकारनिर्देश संरचना चिह्नकम्_ACCESSTIMEOUT {
    UINT cb_आकार;
    DWORD dwFlags;
    DWORD i_Time_बहिर्गमनम्_MSec;
  } ACCESSTIMEOUT,*LPACCESSTIMEOUT;

#परिभाषय ATF_TIMEOUTON 0x00000001
#परिभाषय ATF_ONOFFFEEDBACK 0x00000002

#परिभाषय SSGF_NONE 0
#परिभाषय SSGF_DISPLAY 3

#परिभाषय SSTF_NONE 0
#परिभाषय SSTF_CHARS 1
#परिभाषय SSTF_BORDER 2
#परिभाषय SSTF_DISPLAY 3

#परिभाषय SSWF_NONE 0
#परिभाषय SSWF_TITLE 1
#परिभाषय SSWF_गवाक्षः 2
#परिभाषय SSWF_DISPLAY 3
#परिभाषय SSWF_CUSTOM 4

  प्रकारनिर्देश संरचना चिह्नकम्_SOUNDSENTRYA {
    UINT cb_आकार;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_द्वयङ्काः;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYA,*LPSOUNDSENTRYA;

  प्रकारनिर्देश संरचना चिह्नकम्_SOUNDSENTRYW {
    UINT cb_आकार;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_द्वयङ्काः;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYW,*LPSOUNDSENTRYW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश SOUNDSENTRYW SOUNDSENTRY;
  प्रकारनिर्देश LPSOUNDSENTRYW LPSOUNDSENTRY;
#अन्यथा
  प्रकारनिर्देश SOUNDSENTRYA SOUNDSENTRY;
  प्रकारनिर्देश LPSOUNDSENTRYA LPSOUNDSENTRY;
#यदि_अन्तः

#परिभाषय SSF_SOUNDSENTRYON 0x00000001
#परिभाषय SSF_उपलब्धम् 0x00000002
#परिभाषय SSF_INDICATOR 0x00000004

  प्रकारनिर्देश संरचना चिह्नकम्_TOGGLEKEYS {
    UINT cb_आकार;
    DWORD dwFlags;
  } TOGGLEKEYS,*LPTOGGLEKEYS;

#परिभाषय TKF_TOGGLEKEYSON 0x00000001
#परिभाषय TKF_उपलब्धम् 0x00000002
#परिभाषय TKF_HOTKEYACTIVE 0x00000004
#परिभाषय TKF_CONFIRMHOTKEY 0x00000008
#परिभाषय TKF_HOTKEYSOUND 0x00000010
#परिभाषय TKF_INDICATOR 0x00000020

  WINUSERAPI VOID WINAPI समुच्चयः_Debug_Error_Level(DWORD dwLevel);

#परिभाषय SLE_ERROR 0x00000001
#परिभाषय SLE_MINORERROR 0x00000002
#परिभाषय SLE_WARNING 0x00000003

  WINUSERAPI VOID WINAPI समुच्चयः_चरमः_Error_Ex(DWORD dw_Err_संहिता,DWORD dwType);
  WINUSERAPI पूर्णाङ्क WINAPI आन्तरिकम्_Get_गवाक्षः_Text(HWND hWnd,LPWSTR pString,पूर्णाङ्क cch_Max_गणनम्);

#यदि_परिभाषितम् WINNT
  WINUSERAPI WINBOOL WINAPI अन्तः_Task(HWND hWnd,WINBOOL f_Shut_अधस्तात्,WINBOOL fForce);
#यदि_अन्तः

#परिभाषय MONITOR_DEFAULTTONULL 0x00000000
#परिभाषय MONITOR_DEFAULTTOPRIMARY 0x00000001
#परिभाषय MONITOR_DEFAULTTONEAREST 0x00000002

  WINUSERAPI HMONITOR WINAPI MonitorFromPoint(POINT pt,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromRect(LPCRECT lprc,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI Monitor_From_गवाक्षः(HWND hwnd,DWORD dwFlags);

#परिभाषय MONITORINFOF_PRIMARY 0x00000001

#यदि_अपरिभाषितम् CCHDEVICENAME
#परिभाषय CCHDEVICENAME 32
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_MONITORINFO {
    DWORD cb_आकार;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
  } MONITORINFO,*LPMONITORINFO;

#यदि_परिभाषितम् __cplusplus
  प्रकारनिर्देश संरचना चिह्नकम्_MONITORINFOEXA : सार्वजनिक चिह्नकम्_MONITORINFO {
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  प्रकारनिर्देश संरचना चिह्नकम्_MONITORINFOEXW : सार्वजनिक चिह्नकम्_MONITORINFO {
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश MONITORINFOEXW MONITORINFOEX;
  प्रकारनिर्देश LPMONITORINFOEXW LPMONITORINFOEX;
#अन्यथा
  प्रकारनिर्देश MONITORINFOEXA MONITORINFOEX;
  प्रकारनिर्देश LPMONITORINFOEXA LPMONITORINFOEX;
#यदि_अन्तः
#अन्यथा
  प्रकारनिर्देश संरचना चिह्नकम्_MONITORINFOEXA {
    MONITORINFO mi;
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  प्रकारनिर्देश संरचना चिह्नकम्_MONITORINFOEXW {
    MONITORINFO mi;
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश MONITORINFOEXW MONITORINFOEX;
  प्रकारनिर्देश LPMONITORINFOEXW LPMONITORINFOEX;
#अन्यथा
  प्रकारनिर्देश MONITORINFOEXA MONITORINFOEX;
  प्रकारनिर्देश LPMONITORINFOEXA LPMONITORINFOEX;
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE 
#परिभाषय GetMonitorInfo GetMonitorInfoW
#अन्यथा
#परिभाषय GetMonitorInfo GetMonitorInfoA
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
  WINUSERAPI WINBOOL WINAPI GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);

  प्रकारनिर्देश WINBOOL (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

  WINUSERAPI WINBOOL WINAPI EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dw_दत्त);

#यदि_अपरिभाषितम् NOWINABLE
  WINUSERAPI VOID WINAPI NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG idChild);

  प्रकारनिर्देश VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK hWinEventHook,DWORD event,HWND hwnd,LONG idObject,LONG idChild,DWORD idEventThread,DWORD dwmsEventTime);

  WINUSERAPI HWINEVENTHOOK WINAPI समुच्चयः_Win_Event_Hook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI IsWinEventHookInstalled(DWORD event);

#परिभाषय WINEVENT_OUTOFCONTEXT 0x0000
#परिभाषय WINEVENT_SKIPOWNTHREAD 0x0001
#परिभाषय WINEVENT_SKIPOWNPROCESS 0x0002
#परिभाषय WINEVENT_INCONTEXT 0x0004

  WINUSERAPI WINBOOL WINAPI UnhookWinEvent(HWINEVENTHOOK hWinEventHook);

#परिभाषय CHILDID_SELF 0
#परिभाषय INDEXID_OBJECT 0
#परिभाषय INDEXID_CONTAINER 0

#परिभाषय OBJID_गवाक्षः ((LONG)0x00000000)
#परिभाषय OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#परिभाषय OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#परिभाषय OBJID_MENU ((LONG)0xFFFFFFFD)
#परिभाषय OBJID_CLIENT ((LONG)0xFFFFFFFC)
#परिभाषय OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#परिभाषय OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#परिभाषय OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#परिभाषय OBJID_CARET ((LONG)0xFFFFFFF8)
#परिभाषय OBJID_CURSOR ((LONG)0xFFFFFFF7)
#परिभाषय OBJID_ALERT ((LONG)0xFFFFFFF6)
#परिभाषय OBJID_SOUND ((LONG)0xFFFFFFF5)
#परिभाषय OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#परिभाषय OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#परिभाषय EVENT_MIN 0x00000001
#परिभाषय EVENT_MAX 0x7FFFFFFF

#परिभाषय EVENT_SYSTEM_SOUND 0x0001
#परिभाषय EVENT_SYSTEM_ALERT 0x0002
#परिभाषय EVENT_SYSTEM_FOREGROUND 0x0003
#परिभाषय EVENT_SYSTEM_MENUSTART 0x0004
#परिभाषय EVENT_SYSTEM_MENUEND 0x0005
#परिभाषय EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#परिभाषय EVENT_SYSTEM_MENUPOPUPEND 0x0007
#परिभाषय EVENT_SYSTEM_CAPTURESTART 0x0008
#परिभाषय EVENT_SYSTEM_CAPTUREEND 0x0009
#परिभाषय EVENT_SYSTEM_MOVESIZESTART 0x000A
#परिभाषय EVENT_SYSTEM_MOVESIZEEND 0x000B
#परिभाषय EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#परिभाषय EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#परिभाषय EVENT_SYSTEM_DRAGDROPSTART 0x000E
#परिभाषय EVENT_SYSTEM_DRAGDROPEND 0x000F
#परिभाषय EVENT_SYSTEM_DIALOGSTART 0x0010
#परिभाषय EVENT_SYSTEM_DIALOGEND 0x0011
#परिभाषय EVENT_SYSTEM_SCROLLINGSTART 0x0012
#परिभाषय EVENT_SYSTEM_SCROLLINGEND 0x0013
#परिभाषय EVENT_SYSTEM_SWITCHSTART 0x0014
#परिभाषय EVENT_SYSTEM_SWITCHEND 0x0015
#परिभाषय EVENT_SYSTEM_MINIMIZESTART 0x0016
#परिभाषय EVENT_SYSTEM_MINIMIZEEND 0x0017

#परिभाषय EVENT_CONSOLE_CARET 0x4001
#परिभाषय EVENT_CONSOLE_UPDATE_REGION 0x4002
#परिभाषय EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#परिभाषय EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#परिभाषय EVENT_CONSOLE_LAYOUT 0x4005
#परिभाषय EVENT_CONSOLE_START_APPLICATION 0x4006
#परिभाषय EVENT_CONSOLE_अन्तः_APPLICATION 0x4007

#परिभाषय CONSOLE_APPLICATION_16BIT 0x0001

#परिभाषय CONSOLE_CARET_SELECTION 0x0001
#परिभाषय CONSOLE_CARET_VISIBLE 0x0002

#परिभाषय EVENT_OBJECT_CREATE 0x8000
#परिभाषय EVENT_OBJECT_DESTROY 0x8001
#परिभाषय EVENT_OBJECT_SHOW 0x8002
#परिभाषय EVENT_OBJECT_HIDE 0x8003
#परिभाषय EVENT_OBJECT_REORDER 0x8004

#परिभाषय EVENT_OBJECT_FOCUS 0x8005
#परिभाषय EVENT_OBJECT_SELECTION 0x8006
#परिभाषय EVENT_OBJECT_SELECTIONADD 0x8007
#परिभाषय EVENT_OBJECT_SELECTIONREMOVE 0x8008
#परिभाषय EVENT_OBJECT_SELECTIONWITHIN 0x8009

#परिभाषय EVENT_OBJECT_STATECHANGE 0x800A

#परिभाषय EVENT_OBJECT_LOCATIONCHANGE 0x800B

#परिभाषय EVENT_OBJECT_NAMECHANGE 0x800C
#परिभाषय EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#परिभाषय EVENT_OBJECT_VALUECHANGE 0x800E
#परिभाषय EVENT_OBJECT_PARENTCHANGE 0x800F
#परिभाषय EVENT_OBJECT_HELPCHANGE 0x8010
#परिभाषय EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#परिभाषय EVENT_OBJECT_ACCELERATORCHANGE 0x8012

#परिभाषय SOUND_SYSTEM_STARTUP 1
#परिभाषय SOUND_SYSTEM_SHUTDOWN 2
#परिभाषय SOUND_SYSTEM_BEEP 3
#परिभाषय SOUND_SYSTEM_ERROR 4
#परिभाषय SOUND_SYSTEM_QUESTION 5
#परिभाषय SOUND_SYSTEM_WARNING 6
#परिभाषय SOUND_SYSTEM_INFORMATION 7
#परिभाषय SOUND_SYSTEM_MAXIMIZE 8
#परिभाषय SOUND_SYSTEM_MINIMIZE 9
#परिभाषय SOUND_SYSTEM_RESTOREUP 10
#परिभाषय SOUND_SYSTEM_RESTOREDOWN 11
#परिभाषय SOUND_SYSTEM_APPSTART 12
#परिभाषय SOUND_SYSTEM_FAULT 13
#परिभाषय SOUND_SYSTEM_APPEND 14
#परिभाषय SOUND_SYSTEM_MENUCOMMAND 15
#परिभाषय SOUND_SYSTEM_MENUPOPUP 16
#परिभाषय CSOUND_SYSTEM 16

#परिभाषय ALERT_SYSTEM_INFORMATIONAL 1
#परिभाषय ALERT_SYSTEM_WARNING 2
#परिभाषय ALERT_SYSTEM_ERROR 3
#परिभाषय ALERT_SYSTEM_QUERY 4
#परिभाषय ALERT_SYSTEM_CRITICAL 5
#परिभाषय CALERT_SYSTEM 6

  प्रकारनिर्देश संरचना चिह्नकम्_GUITHREADINFO {
    DWORD cb_आकार;
    DWORD flags;
    HWND hwnd_सक्रिय;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwnd_Move_आकार;
    HWND hwndCaret;
    RECT rcCaret;
  } GUITHREADINFO,*PGUITHREADINFO,*LPGUITHREADINFO;

#परिभाषय GUI_CARETBLINKING 0x00000001
#परिभाषय GUI_INMOVESIZE 0x00000002
#परिभाषय GUI_INMENUMODE 0x00000004
#परिभाषय GUI_SYSTEMMENUMODE 0x00000008
#परिभाषय GUI_POPUPMENUMODE 0x00000010
#परिभाषय GUI_16BITTASK 0x00000020

#यदि_परिभाषितम् UNICODE
#परिभाषय Get_गवाक्षः_Module_File_Name Get_गवाक्षः_Module_File_Name_W
#अन्यथा
#परिभाषय Get_गवाक्षः_Module_File_Name Get_गवाक्षः_Module_File_Name_A
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui);
  WINUSERAPI UINT WINAPI Get_गवाक्षः_Module_File_Name_A(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
  WINUSERAPI UINT WINAPI Get_गवाक्षः_Module_File_Name_W(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);

#यदि_अपरिभाषितम् NO_STATE_FLAGS
#परिभाषय STATE_SYSTEM_UNAVAILABLE 0x00000001
#परिभाषय STATE_SYSTEM_SELECTED 0x00000002
#परिभाषय STATE_SYSTEM_FOCUSED 0x00000004
#परिभाषय STATE_SYSTEM_PRESSED 0x00000008
#परिभाषय STATE_SYSTEM_CHECKED 0x00000010
#परिभाषय STATE_SYSTEM_MIXED 0x00000020
#परिभाषय STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#परिभाषय STATE_SYSTEM_READONLY 0x00000040
#परिभाषय STATE_SYSTEM_HOTTRACKED 0x00000080
#परिभाषय STATE_SYSTEM_DEFAULT 0x00000100
#परिभाषय STATE_SYSTEM_EXPANDED 0x00000200
#परिभाषय STATE_SYSTEM_COLLAPSED 0x00000400
#परिभाषय STATE_SYSTEM_BUSY 0x00000800
#परिभाषय STATE_SYSTEM_FLOATING 0x00001000
#परिभाषय STATE_SYSTEM_MARQUEED 0x00002000
#परिभाषय STATE_SYSTEM_ANIMATED 0x00004000
#परिभाषय STATE_SYSTEM_INVISIBLE 0x00008000
#परिभाषय STATE_SYSTEM_OFFSCREEN 0x00010000
#परिभाषय STATE_SYSTEM_SIZEABLE 0x00020000
#परिभाषय STATE_SYSTEM_MOVEABLE 0x00040000
#परिभाषय STATE_SYSTEM_SELFVOICING 0x00080000
#परिभाषय STATE_SYSTEM_FOCUSABLE 0x00100000
#परिभाषय STATE_SYSTEM_SELECTABLE 0x00200000
#परिभाषय STATE_SYSTEM_LINKED 0x00400000
#परिभाषय STATE_SYSTEM_TRAVERSED 0x00800000
#परिभाषय STATE_SYSTEM_MULTISELECTABLE 0x01000000
#परिभाषय STATE_SYSTEM_EXTSELECTABLE 0x02000000
#परिभाषय STATE_SYSTEM_ALERT_नीचः 0x04000000
#परिभाषय STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#परिभाषय STATE_SYSTEM_ALERT_उच्चः 0x10000000
#परिभाषय STATE_SYSTEM_PROTECTED 0x20000000
#परिभाषय STATE_SYSTEM_VALID 0x3FFFFFFF
#यदि_अन्तः

#परिभाषय CCHILDREN_TITLEBAR 5
#परिभाषय CCHILDREN_SCROLLBAR 5

  प्रकारनिर्देश संरचना चिह्नकम्_CURSORINFO {
    DWORD cb_आकार;
    DWORD flags;
    HCURSOR hCursor;
    POINT ptScreenPos;
  } CURSORINFO,*PCURSORINFO,*LPCURSORINFO;

#परिभाषय CURSOR_SHOWING 0x00000001

  WINUSERAPI WINBOOL WINAPI GetCursorInfo(PCURSORINFO pci);

  प्रकारनिर्देश संरचना चिह्नकम्_WINDOWINFO {
    DWORD cb_आकार;
    RECT rc_गवाक्षः;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dw_गवाक्षः_स्थितिः;
    UINT cx_गवाक्षः_Borders;
    UINT cy_गवाक्षः_Borders;
    ATOM atom_गवाक्षः_Type;
    WORD w_Creator_संस्करणम्;
  } WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;

#परिभाषय WS_ACTIVECAPTION 0x0001

  WINUSERAPI WINBOOL WINAPI Get_गवाक्षः_Info(HWND hwnd,PWINDOWINFO pwi);

  प्रकारनिर्देश संरचना चिह्नकम्_TITLEBARINFO {
    DWORD cb_आकार;
    RECT rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  } TITLEBARINFO,*PTITLEBARINFO,*LPTITLEBARINFO;

  WINUSERAPI WINBOOL WINAPI GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti);

  प्रकारनिर्देश संरचना चिह्नकम्_MENUBARINFO {
    DWORD cb_आकार;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    WINBOOL fBarFocused:1;
    WINBOOL fFocused:1;
  } MENUBARINFO,*PMENUBARINFO,*LPMENUBARINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuBarInfo(HWND hwnd,LONG idObject,LONG idItem,PMENUBARINFO pmbi);

  प्रकारनिर्देश संरचना चिह्नकम्_SCROLLBARINFO {
    DWORD cb_आकार;
    RECT rcScrollBar;
    पूर्णाङ्क dxy_पङ्क्तिः_Button;
    पूर्णाङ्क xy_Thumb_शिखरम्;
    पूर्णाङ्क xyThumbBottom;
    पूर्णाङ्क reserved;
    DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
  } SCROLLBARINFO,*PSCROLLBARINFO,*LPSCROLLBARINFO;

  WINUSERAPI WINBOOL WINAPI GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);

  प्रकारनिर्देश संरचना चिह्नकम्_COMBOBOXINFO {
    DWORD cb_आकार;
    RECT rcItem;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwndItem;
    HWND hwndList;
  } COMBOBOXINFO,*PCOMBOBOXINFO,*LPCOMBOBOXINFO;

  WINUSERAPI WINBOOL WINAPI GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi);

#परिभाषय GA_PARENT 1
#परिभाषय GA_मूलम् 2
#परिभाषय GA_ROOTOWNER 3

  WINUSERAPI HWND WINAPI GetAncestor(HWND hwnd,UINT gaFlags);
  WINUSERAPI HWND WINAPI Real_Child_गवाक्षः_From_Point(HWND hwndParent,POINT ptParentClientCoords);
  WINUSERAPI UINT WINAPI Real_Get_गवाक्षः_Class_A(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
  WINUSERAPI UINT WINAPI Real_Get_गवाक्षः_Class_W(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
#यदि_परिभाषितम् UNICODE
#परिभाषय Real_Get_गवाक्षः_Class Real_Get_गवाक्षः_Class_W
#अन्यथा
#परिभाषय Real_Get_गवाक्षः_Class Real_Get_गवाक्षः_Class_A
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_ALTTABINFO {
    DWORD cb_आकार;
    पूर्णाङ्क c_वस्तूनि;
    पूर्णाङ्क cColumns;
    पूर्णाङ्क c_पङ्क्तिकाः;
    पूर्णाङ्क iColFocus;
    पूर्णाङ्क iRowFocus;
    पूर्णाङ्क cxItem;
    पूर्णाङ्क cyItem;
    POINT ptStart;
  } ALTTABINFO,*PALTTABINFO,*LPALTTABINFO;

#यदि_परिभाषितम् UNICODE
#परिभाषय GetAltTabInfo GetAltTabInfoW
#अन्यथा
#परिभाषय GetAltTabInfo GetAltTabInfoA
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI GetAltTabInfoA(HWND hwnd,पूर्णाङ्क iItem,PALTTABINFO pati,LPSTR pszItemText,UINT cchItemText);
  WINUSERAPI WINBOOL WINAPI GetAltTabInfoW(HWND hwnd,पूर्णाङ्क iItem,PALTTABINFO pati,LPWSTR pszItemText,UINT cchItemText);
  WINUSERAPI DWORD WINAPI GetListBoxInfo(HWND hwnd);
#यदि_अन्तः

  WINUSERAPI WINBOOL WINAPI तालकम्_Work_Station(VOID);
  WINUSERAPI WINBOOL WINAPI UserHandleGrantAccess(HANDLE hUserHandle,HANDLE hJob,WINBOOL bGrant);

  DECLARE_HANDLE(HRAWINPUT);

#परिभाषय GET_RAWINPUT_संहिता_WPARAM(wParam) ((wParam) & 0xff)

#परिभाषय RIM_निवेशः 0
#परिभाषय RIM_INPUTSINK 1

  प्रकारनिर्देश संरचना चिह्नकम्_RAWINPUTHEADER {
    DWORD dwType;
    DWORD dw_आकार;
    HANDLE hDevice;
    WPARAM wParam;
  } RAWINPUTHEADER,*PRAWINPUTHEADER,*LPRAWINPUTHEADER;

#परिभाषय RIM_TYPEMOUSE 0
#परिभाषय RIM_TYPEKEYBOARD 1
#परिभाषय RIM_TYPEHID 2

  प्रकारनिर्देश संरचना चिह्नकम्_RAWMOUSE {
    USHORT usFlags;
    सङ्घ {
      ULONG ulButtons;
      संरचना {
	USHORT usButtonFlags;
	USHORT us_Button_दत्त;
      };
    };
    ULONG ulRawButtons;
    LONG l_चरमः_X;
    LONG l_चरमः_Y;
    ULONG ulExtraInformation;
  } RAWMOUSE,*PRAWMOUSE,*LPRAWMOUSE;

#परिभाषय RI_MOUSE_वामः_BUTTON_अधस्तात् 0x0001
#परिभाषय RI_MOUSE_वामः_BUTTON_ऊर्ध्वम् 0x0002
#परिभाषय RI_MOUSE_दक्षिणः_BUTTON_अधस्तात् 0x0004
#परिभाषय RI_MOUSE_दक्षिणः_BUTTON_ऊर्ध्वम् 0x0008
#परिभाषय RI_MOUSE_मध्यः_BUTTON_अधस्तात् 0x0010
#परिभाषय RI_MOUSE_मध्यः_BUTTON_ऊर्ध्वम् 0x0020

#परिभाषय RI_MOUSE_BUTTON_1_अधस्तात् RI_MOUSE_वामः_BUTTON_अधस्तात्
#परिभाषय RI_MOUSE_BUTTON_1_ऊर्ध्वम् RI_MOUSE_वामः_BUTTON_ऊर्ध्वम्
#परिभाषय RI_MOUSE_BUTTON_2_अधस्तात् RI_MOUSE_दक्षिणः_BUTTON_अधस्तात्
#परिभाषय RI_MOUSE_BUTTON_2_ऊर्ध्वम् RI_MOUSE_दक्षिणः_BUTTON_ऊर्ध्वम्
#परिभाषय RI_MOUSE_BUTTON_3_अधस्तात् RI_MOUSE_मध्यः_BUTTON_अधस्तात्
#परिभाषय RI_MOUSE_BUTTON_3_ऊर्ध्वम् RI_MOUSE_मध्यः_BUTTON_ऊर्ध्वम्

#परिभाषय RI_MOUSE_BUTTON_4_अधस्तात् 0x0040
#परिभाषय RI_MOUSE_BUTTON_4_ऊर्ध्वम् 0x0080
#परिभाषय RI_MOUSE_BUTTON_5_अधस्तात् 0x0100
#परिभाषय RI_MOUSE_BUTTON_5_ऊर्ध्वम् 0x0200

#परिभाषय RI_MOUSE_WHEEL 0x0400

#परिभाषय MOUSE_MOVE_RELATIVE 0
#परिभाषय MOUSE_MOVE_ABSOLUTE 1
#परिभाषय MOUSE_VIRTUAL_DESKTOP 0x02
#परिभाषय MOUSE_गुणाः_परिवर्तितम् 0x04

  प्रकारनिर्देश संरचना चिह्नकम्_RAWKEYBOARD {
    USHORT Make_संहिता;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT सन्देशः_6;
    ULONG ExtraInformation;
  } RAWKEYBOARD,*PRAWKEYBOARD,*LPRAWKEYBOARD;

#परिभाषय KEYBOARD_OVERRUN_MAKE_संहिता 0xFF

#परिभाषय RI_कुञ्चिका_MAKE 0
#परिभाषय RI_कुञ्चिका_BREAK 1
#परिभाषय RI_कुञ्चिका_E0 2
#परिभाषय RI_कुञ्चिका_E1 4
#परिभाषय RI_कुञ्चिका_TERMSRV_समुच्चयः_LED 8
#परिभाषय RI_कुञ्चिका_TERMSRV_SHADOW 0x10

  प्रकारनिर्देश संरचना चिह्नकम्_RAWHID {
    DWORD dw_आकार_Hid;
    DWORD dw_गणनम्;
    BYTE b_Raw_दत्त[1];
  } RAWHID,*PRAWHID,*LPRAWHID;

  प्रकारनिर्देश संरचना चिह्नकम्_RAWINPUT {
    RAWINPUTHEADER शीर्षकम्;
    सङ्घ {
      RAWMOUSE mouse;
      RAWKEYBOARD keyboard;
      RAWHID hid;
    } दत्त;
  } RAWINPUT,*PRAWINPUT,*LPRAWINPUT;

#यदि_परिभाषितम् _WIN64
#परिभाषय RAWINPUT_ALIGN(x) (((x) + परिमाण(QWORD) - 1) & ~(परिमाण(QWORD) - 1))
#अन्यथा
#परिभाषय RAWINPUT_ALIGN(x) (((x) + परिमाण(DWORD) - 1) & ~(परिमाण(DWORD) - 1))
#यदि_अन्तः

#परिभाषय NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->शीर्षकम्.dw_आकार)))

#परिभाषय RID_निवेशः 0x10000003
#परिभाषय RID_शीर्षकम् 0x10000005

  WINUSERAPI UINT WINAPI Get_Raw_निवेशः_दत्त(HRAWINPUT h_Raw_निवेशः,UINT uiCommand,LPVOID p_दत्त,PUINT pcb_आकार,UINT cb_आकार_शीर्षकम्);

#परिभाषय RIDI_PREPARSEDDATA 0x20000005
#परिभाषय RIDI_DEVICENAME 0x20000007
#परिभाषय RIDI_DEVICEINFO 0x2000000b

  प्रकारनिर्देश संरचना चिह्नकम्_RID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dw_सङ्ख्या_सम्बन्धि_Buttons;
    DWORD dw_Sample_दरः;
  } RID_DEVICE_INFO_MOUSE,*PRID_DEVICE_INFO_MOUSE;

  प्रकारनिर्देश संरचना चिह्नकम्_RID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dw_Keyboard_बहुलकम्;
    DWORD dw_सङ्ख्या_सम्बन्धि_Function_कुञ्चिकाः;
    DWORD dw_सङ्ख्या_सम्बन्धि_Indicators;
    DWORD dw_सङ्ख्या_सम्बन्धि_कुञ्चिकाः_योग;
  } RID_DEVICE_INFO_KEYBOARD,*PRID_DEVICE_INFO_KEYBOARD;

  प्रकारनिर्देश संरचना चिह्नकम्_RID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dw_गुणनफलम्_Id;
    DWORD dw_संस्करणम्_सङ्ख्या;
    USHORT usUsagePage;
    USHORT usUsage;
  } RID_DEVICE_INFO_HID,*PRID_DEVICE_INFO_HID;

  प्रकारनिर्देश संरचना चिह्नकम्_RID_DEVICE_INFO {
    DWORD cb_आकार;
    DWORD dwType;
    सङ्घ {
      RID_DEVICE_INFO_MOUSE mouse;
      RID_DEVICE_INFO_KEYBOARD keyboard;
      RID_DEVICE_INFO_HID hid;
    };
  } RID_DEVICE_INFO,*PRID_DEVICE_INFO,*LPRID_DEVICE_INFO;

#यदि_परिभाषितम् UNICODE
#परिभाषय Get_Raw_निवेशः_Device_Info Get_Raw_निवेशः_Device_Info_W
#अन्यथा
#परिभाषय Get_Raw_निवेशः_Device_Info Get_Raw_निवेशः_Device_Info_A
#यदि_अन्तः

  WINUSERAPI UINT WINAPI Get_Raw_निवेशः_Device_Info_A(HANDLE hDevice,UINT uiCommand,LPVOID p_दत्त,PUINT pcb_आकार);
  WINUSERAPI UINT WINAPI Get_Raw_निवेशः_Device_Info_W(HANDLE hDevice,UINT uiCommand,LPVOID p_दत्त,PUINT pcb_आकार);
  WINUSERAPI UINT WINAPI Get_Raw_निवेशः_बफर(PRAWINPUT p_दत्त,PUINT pcb_आकार,UINT cb_आकार_शीर्षकम्);

  प्रकारनिर्देश संरचना चिह्नकम्_RAWINPUTDEVICE {
    USHORT usUsagePage;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwndTarget;
  } RAWINPUTDEVICE,*PRAWINPUTDEVICE,*LPRAWINPUTDEVICE;

  प्रकारनिर्देश CONST RAWINPUTDEVICE *PCRAWINPUTDEVICE;

#परिभाषय RIDEV_REMOVE 0x00000001
#परिभाषय RIDEV_EXCLUDE 0x00000010
#परिभाषय RIDEV_PAGEONLY 0x00000020
#परिभाषय RIDEV_NOLEGACY 0x00000030
#परिभाषय RIDEV_INPUTSINK 0x00000100
#परिभाषय RIDEV_CAPTUREMOUSE 0x00000200
#परिभाषय RIDEV_NOHOTKEYS 0x00000200
#परिभाषय RIDEV_APPKEYS 0x00000400
#परिभाषय RIDEV_EXMODEMASK 0x000000F0
#परिभाषय RIDEV_EXMODE(बहुलकम्) ((बहुलकम्) & RIDEV_EXMODEMASK)

  WINUSERAPI WINBOOL WINAPI पञ्जिकाकोशः_Raw_निवेशः_Devices(PCRAWINPUTDEVICE p_Raw_निवेशः_Devices,UINT ui_अङ्कः_Devices,UINT cb_आकार);
  WINUSERAPI UINT WINAPI Get_Registered_Raw_निवेशः_Devices(PRAWINPUTDEVICE p_Raw_निवेशः_Devices,PUINT pui_अङ्कः_Devices,UINT cb_आकार);

  प्रकारनिर्देश संरचना चिह्नकम्_RAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
  } RAWINPUTDEVICELIST,*PRAWINPUTDEVICELIST;

  WINUSERAPI UINT WINAPI Get_Raw_निवेशः_Device_List(PRAWINPUTDEVICELIST p_Raw_निवेशः_Device_List,PUINT pui_अङ्कः_Devices,UINT cb_आकार);
  WINUSERAPI LRESULT WINAPI Def_Raw_निवेशः_Proc(PRAWINPUT *pa_Raw_निवेशः,INT n_निवेशः,UINT cb_आकार_शीर्षकम्);

#यदि_अन्तः /* NOUSER */

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
