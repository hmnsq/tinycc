/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINUSER_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINUSER_

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINUSERAPI DECLSPEC_IMPORT

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WINVER
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINVER 0x0502
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <stdarg.h>

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOUSER
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HANDLE HDWP;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID MENUTEMPLATEA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID MENUTEMPLATEW;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVOID LPMENUTEMPLATEA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVOID LPMENUTEMPLATEW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MENUTEMPLATEW MENUTEMPLATE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMENUTEMPLATEW LPMENUTEMPLATE;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MENUTEMPLATEA MENUTEMPLATE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMENUTEMPLATEA LPMENUTEMPLATE;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,ਪੂਰਨ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *WNDENUMPROC)(HWND,LPARAM);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LRESULT (CALLBACK *HOOKPROC)(ਪੂਰਨ ਕੋਡ,WPARAM wParam,LPARAM lParam);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch,ਪੂਰਨ ichCurrent,ਪੂਰਨ cch,ਪੂਰਨ ਕੋਡ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch,ਪੂਰਨ ichCurrent,ਪੂਰਨ cch,ਪੂਰਨ ਕੋਡ);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *DRAWSTATEPROC)(HDC hdc,LPARAM l_ਅੰਕੜੇ,WPARAM w_ਅੰਕੜੇ,ਪੂਰਨ cx,ਪੂਰਨ cy);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PROPENUMPROCW PROPENUMPROC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PROPENUMPROCEXW PROPENUMPROCEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PROPENUMPROCA PROPENUMPROC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PROPENUMPROCEXA PROPENUMPROCEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NAMEENUMPROCA WINSTAENUMPROCA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NAMEENUMPROCA DESKTOPENUMPROCA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NAMEENUMPROCW WINSTAENUMPROCW;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NAMEENUMPROCW DESKTOPENUMPROCW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINSTAENUMPROCW WINSTAENUMPROC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DESKTOPENUMPROCW DESKTOPENUMPROC;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINSTAENUMPROCA WINSTAENUMPROC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DESKTOPENUMPROCA DESKTOPENUMPROC;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((ਸ਼ਬਦ_3)(i))))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((ਸ਼ਬਦ_3)(i))))
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKEINTRESOURCE MAKEINTRESOURCEW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKEINTRESOURCE MAKEINTRESOURCEA
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NORESOURCE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_CURSOR MAKEINTRESOURCE(1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_BITMAP MAKEINTRESOURCE(2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_ICON MAKEINTRESOURCE(3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_MENU MAKEINTRESOURCE(4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_DIALOG MAKEINTRESOURCE(5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_STRING MAKEINTRESOURCE(6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_FONTDIR MAKEINTRESOURCE(7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_FONT MAKEINTRESOURCE(8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_ACCELERATOR MAKEINTRESOURCE(9)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_RCDATA MAKEINTRESOURCE(10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_MESSAGETABLE MAKEINTRESOURCE(11)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DIFFERENCE 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_ਸਮੂਹ_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_ਸਮੂਹ_ICON MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_ਸੰਸਕਰਣ MAKEINTRESOURCE(16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_DLGINCLUDE MAKEINTRESOURCE(17)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_PLUGPLAY MAKEINTRESOURCE(19)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_VXD MAKEINTRESOURCE(20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_ANICURSOR MAKEINTRESOURCE(21)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_ANIICON MAKEINTRESOURCE(22)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_HTML MAKEINTRESOURCE(23)
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_MANIFEST 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_RESERVED_MANIFEST_RESOURCE_ID 16
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RT_MANIFEST MAKEINTRESOURCE(24)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਵੱਧ_ਤੋਂ_ਵੱਧ_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wvsprintf wvsprintfW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wsprintf wsprintfW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wvsprintf wvsprintfA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wsprintf wsprintfA
#ਜੇ_ਅੰਤ

  WINUSERAPI ਪੂਰਨ WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
  WINUSERAPI ਪੂਰਨ WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);
  WINUSERAPI ਪੂਰਨ WINAPIV wsprintfA(LPSTR,LPCSTR,...);
  WINUSERAPI ਪੂਰਨ WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOSCROLL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_HORZ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_VERT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_CTL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_BOTH 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_LINEUP 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_LINELEFT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_LINEDOWN 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_LINERIGHT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_PAGEUP 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_PAGELEFT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_PAGEDOWN 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_PAGERIGHT 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_THUMBPOSITION 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_THUMBTRACK 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_ਸਿਖਰ 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_ਖੱਬਾ 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_BOTTOM 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_ਸੱਜਾ 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_ENDSCROLL 8
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOSHOWWINDOW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_HIDE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SHOWNORMAL 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_ਸਾਧਾਰਨ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SHOWMINIMIZED 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SHOWMAXIMIZED 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_MAXIMIZE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SHOWNOACTIVATE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SHOW 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_MINIMIZE 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SHOWMINNOACTIVE 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SHOWNA 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_RESTORE 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SHOWDEFAULT 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_FORCEMINIMIZE 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_MAX 11

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HIDE_ਖਿੜਕੀ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHOW_OPENWINDOW 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHOW_ICONWINDOW 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHOW_FULLSCREEN 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHOW_OPENNOACTIVATE 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_PARENTCLOSING 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_OTHERZOOM 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_PARENTOPENING 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_OTHERUNZOOM 4
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AW_HOR_ਸਕਾਰਾਤਮਕ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AW_HOR_NEGATIVE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AW_VER_ਸਕਾਰਾਤਮਕ 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AW_VER_NEGATIVE 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AW_CENTER 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AW_HIDE 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AW_ACTIVATE 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AW_SLIDE 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AW_BLEND 0x00080000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KF_EXTENDED 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KF_DLGMODE 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KF_MENUMODE 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KF_ALTDOWN 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KF_REPEAT 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KF_ਉੱਪਰ 0x8000

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOVIRTUALKEYCODES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_LBUTTON 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_RBUTTON 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_CANCEL 0x03
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_MBUTTON 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_XBUTTON1 0x05
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_XBUTTON2 0x06
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਪਿੱਠ 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_TAB 0x09
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_CLEAR 0x0C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_RETURN 0x0D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਖਿਸਕਾਓ 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_CONTROL 0x11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_MENU 0x12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_PAUSE 0x13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_CAPITAL 0x14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_KANA 0x15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_HANGEUL 0x15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_HANGUL 0x15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_JUNJA 0x17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_FINAL 0x18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_HANJA 0x19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_KANJI 0x19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ESCAPE 0x1B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_CONVERT 0x1C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NONCONVERT 0x1D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ACCEPT 0x1E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_MODECHANGE 0x1F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_SPACE 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਪੂਰਵ 0x21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਅਗਲਾ 0x22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਸਿਰਾ 0x23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_HOME 0x24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਖੱਬਾ 0x25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਉੱਪਰ 0x26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਸੱਜਾ 0x27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਥੱਲੇ 0x28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_SELECT 0x29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_PRINT 0x2A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_EXECUTE 0x2B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_SNAPSHOT 0x2C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਪਾਓ 0x2D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_DELETE 0x2E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_HELP 0x2F

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_LWIN 0x5B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_RWIN 0x5C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_APPS 0x5D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_SLEEP 0x5F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD0 0x60
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD1 0x61
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD2 0x62
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD3 0x63
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD4 0x64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD5 0x65
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD6 0x66
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD7 0x67
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD8 0x68
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMPAD9 0x69
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_MULTIPLY 0x6A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਜੋੜੋ 0x6B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_SEPARATOR 0x6C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ਘਟਾਓ 0x6D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_DECIMAL 0x6E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_DIVIDE 0x6F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F1 0x70
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F2 0x71
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F3 0x72
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F4 0x73
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F5 0x74
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F6 0x75
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F7 0x76
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F8 0x77
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F9 0x78
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F10 0x79
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F11 0x7A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F12 0x7B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F13 0x7C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F14 0x7D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F15 0x7E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F16 0x7F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F17 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F18 0x81
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F19 0x82
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F20 0x83
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F21 0x84
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F22 0x85
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F23 0x86
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_F24 0x87
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NUMLOCK 0x90
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_SCROLL 0x91
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_NEC_EQUAL 0x92
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_FJ_JISHO 0x92
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_FJ_MASSHOU 0x93
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_FJ_TOUROKU 0x94
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_FJ_LOYA 0x95
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_FJ_ROYA 0x96
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_LSHIFT 0xA0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_RSHIFT 0xA1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_LCONTROL 0xA2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_RCONTROL 0xA3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_LMENU 0xA4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_RMENU 0xA5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_BROWSER_ਪਿੱਠ 0xA6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_BROWSER_FORWARD 0xA7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_BROWSER_REFRESH 0xA8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_BROWSER_STOP 0xA9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_BROWSER_ਖੋਜ 0xAA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_BROWSER_FAVORITES 0xAB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_BROWSER_HOME 0xAC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_VOLUME_MUTE 0xAD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_VOLUME_ਥੱਲੇ 0xAE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_VOLUME_ਉੱਪਰ 0xAF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_MEDIA_ਅਗਲਾ_TRACK 0xB0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_MEDIA_PREV_TRACK 0xB1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_MEDIA_STOP 0xB2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_MEDIA_PLAY_PAUSE 0xB3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_LAUNCH_MAIL 0xB4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_LAUNCH_MEDIA_SELECT 0xB5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_LAUNCH_APP1 0xB6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_LAUNCH_APP2 0xB7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_1 0xBA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_PLUS 0xBB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_COMMA 0xBC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_MINUS 0xBD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_PERIOD 0xBE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_2 0xBF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_3 0xC0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_4 0xDB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_5 0xDC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_6 0xDD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_7 0xDE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_8 0xDF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_AX 0xE1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_102 0xE2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ICO_HELP 0xE3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ICO_00 0xE4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_PROCESSKEY 0xE5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ICO_CLEAR 0xE6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_PACKET 0xE7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_RESET 0xE9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_JUMP 0xEA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_PA1 0xEB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_PA2 0xEC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_PA3 0xED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_WSCTRL 0xEE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_CUSEL 0xEF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_ATTN 0xF0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_ਅੰਤ 0xF1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_COPY 0xF2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_AUTO 0xF3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_ENLW 0xF4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_BACKTAB 0xF5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ATTN 0xF6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_CRSEL 0xF7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_EXSEL 0xF8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_EREOF 0xF9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_PLAY 0xFA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_ZOOM 0xFB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_NONAME 0xFC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_PA1 0xFD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VK_OEM_CLEAR 0xFE
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWH

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_MIN (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_MSGFILTER (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_JOURNALRECORD 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_JOURNALPLAYBACK 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_KEYBOARD 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_GETMESSAGE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_CALLWNDPROC 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_CBT 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_SYSMSGFILTER 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_MOUSE 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_HARDWARE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_DEBUG 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_SHELL 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_FOREGROUNDIDLE 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_CALLWNDPROCRET 12

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_KEYBOARD_LL 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_MOUSE_LL 14

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_MAX 14

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_MINHOOK WH_MIN
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WH_MAXHOOK WH_MAX

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HC_ACTION 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HC_GETNEXT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HC_SKIP 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HC_NOREMOVE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HC_NOREM HC_NOREMOVE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HC_SYSMODALON 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HC_SYSMODALOFF 5

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_MOVESIZE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_MINMAX 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_QS 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_CREATEWND 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_DESTROYWND 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_ACTIVATE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_CLICKSKIPPED 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_KEYSKIPPED 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_SYSCOMMAND 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCBT_SETFOCUS 9

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CBT_CREATEWNDA {
    ਬਣਤਰ ਟੈਗ_CREATESTRUCTA *lpcs;
    HWND hwnd_ਪਾਓ_After;
  } CBT_CREATEWNDA,*LPCBT_CREATEWNDA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CBT_CREATEWNDW {
    ਬਣਤਰ ਟੈਗ_CREATESTRUCTW *lpcs;
    HWND hwnd_ਪਾਓ_After;
  } CBT_CREATEWNDW,*LPCBT_CREATEWNDW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CBT_CREATEWNDW CBT_CREATEWND;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCBT_CREATEWNDW LPCBT_CREATEWND;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CBT_CREATEWNDA CBT_CREATEWND;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCBT_CREATEWNDA LPCBT_CREATEWND;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CBTACTIVATESTRUCT
  {
    WINBOOL fMouse;
    HWND h_Wnd_ਸਰਗਰਮ;
  } CBTACTIVATESTRUCT,*LPCBTACTIVATESTRUCT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_WTSSESSION_NOTIFICATION {
    DWORD cb_ਮਾਪ;
    DWORD dwSessionId;

  } WTSSESSION_NOTIFICATION,*PWTSSESSION_NOTIFICATION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WTS_CONSOLE_CONNECT 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WTS_CONSOLE_DISCONNECT 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WTS_REMOTE_CONNECT 0x3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WTS_REMOTE_DISCONNECT 0x4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WTS_SESSION_LOGON 0x5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WTS_SESSION_LOGOFF 0x6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WTS_SESSION_ਤਾਲਾ 0x7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WTS_SESSION_UNLOCK 0x8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WTS_SESSION_REMOTE_CONTROL 0x9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MSGF_DIALOGBOX 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MSGF_MESSAGEBOX 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MSGF_MENU 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MSGF_SCROLLBAR 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MSGF_NEXTWINDOW 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MSGF_MAX 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MSGF_USER 4096

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_WINDOWCREATED 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_WINDOWDESTROYED 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_ACTIVATESHELLWINDOW 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_WINDOWACTIVATED 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_GETMINRECT 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_REDRAW 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_TASKMAN 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_LANGUAGE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_SYSMENU 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_ENDTASK 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_ACCESSIBILITYSTATE 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_APPCOMMAND 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_WINDOWREPLACED 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_WINDOWREPLACING 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_HIGHBIT 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_STICKYKEYS 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_FILTERKEYS 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ACCESS_MOUSEKEYS 0x0003

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BROWSER_BACKWARD 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BROWSER_FORWARD 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BROWSER_REFRESH 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BROWSER_STOP 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BROWSER_ਖੋਜ 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BROWSER_FAVORITES 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BROWSER_HOME 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_VOLUME_MUTE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_VOLUME_ਥੱਲੇ 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_VOLUME_ਉੱਪਰ 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_NEXTTRACK 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_STOP 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_PLAY_PAUSE 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_LAUNCH_MAIL 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_LAUNCH_APP1 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_LAUNCH_APP2 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BASS_ਥੱਲੇ 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BASS_BOOST 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_BASS_ਉੱਪਰ 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_TREBLE_ਥੱਲੇ 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_TREBLE_ਉੱਪਰ 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MICROPHONE_VOLUME_ਥੱਲੇ 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MICROPHONE_VOLUME_ਉੱਪਰ 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_HELP 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_ਲੱਭੋ 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_NEW 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_OPEN 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_CLOSE 31
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_SAVE 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_PRINT 33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_UNDO 34
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_REDO 35
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_COPY 36
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_CUT 37
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_PASTE 38
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_ਜਵਾਬ_ਮੰਜ਼ਿਲ_MAIL 39
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_FORWARD_MAIL 40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_SEND_MAIL 41
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_SPELL_CHECK 42
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_CORRECTION_LIST 45
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_PLAY 46
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_PAUSE 47
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_ਰਿਕਾਰਡ 48
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_FAST_FORWARD 49
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_REWIND 50
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_CHANNEL_ਉੱਪਰ 51
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ APPCOMMAND_MEDIA_CHANNEL_ਥੱਲੇ 52

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAPPCOMMAND_MOUSE 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAPPCOMMAND_ਕੁੰਜੀ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAPPCOMMAND_OEM 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FAPPCOMMAND_ਨਕਾਬ 0xF000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_APPCOMMAND_LPARAM(lParam) ((ਛੋਟਾ)(HIWORD(lParam) & ~FAPPCOMMAND_ਨਕਾਬ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_DEVICE_LPARAM(lParam) ((ਸ਼ਬਦ_3)(HIWORD(lParam) & FAPPCOMMAND_ਨਕਾਬ))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    HWND hwnd;
    RECT rc;
  } SHELLHOOKINFO,*LPSHELLHOOKINFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EVENTMSG {
    UINT ਸੁਨੇਹਾ_2;
    UINT paramL;
    UINT paramH;
    DWORD ਸਮਾਂ;
    HWND hwnd;
  } EVENTMSG,*PEVENTMSGMSG,*NPEVENTMSGMSG,*LPEVENTMSGMSG;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EVENTMSG *PEVENTMSG,*NPEVENTMSG,*LPEVENTMSG;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT ਸੁਨੇਹਾ_2;
    HWND hwnd;
  } CWPSTRUCT,*PCWPSTRUCT,*NPCWPSTRUCT,*LPCWPSTRUCT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CWPRETSTRUCT {
    LRESULT l_ਨਤੀਜਾ;
    LPARAM lParam;
    WPARAM wParam;
    UINT ਸੁਨੇਹਾ_2;
    HWND hwnd;
  } CWPRETSTRUCT,*PCWPRETSTRUCT,*NPCWPRETSTRUCT,*LPCWPRETSTRUCT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LLKHF_EXTENDED (KF_EXTENDED >> 8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LLKHF_INJECTED 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LLKHF_ਉੱਪਰ (KF_ਉੱਪਰ >> 8)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LLMHF_INJECTED 0x00000001

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_KBDLLHOOKSTRUCT {
    DWORD vk_ਕੋਡ;
    DWORD ਜਾਂਚ_ਕੋਡ;
    DWORD flags;
    DWORD ਸਮਾਂ;
    ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MSLLHOOKSTRUCT {
    ਬਿੰਦੂ_3 pt;
    DWORD mouse_ਅੰਕੜੇ;
    DWORD flags;
    DWORD ਸਮਾਂ;
    ULONG_PTR dwExtraInfo;
  } MSLLHOOKSTRUCT,*LPMSLLHOOKSTRUCT,*PMSLLHOOKSTRUCT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_DEBUGHOOKINFO {
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    ਪੂਰਨ ਕੋਡ;
  } DEBUGHOOKINFO,*PDEBUGHOOKINFO,*NPDEBUGHOOKINFO,*LPDEBUGHOOKINFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MOUSEHOOKSTRUCT {
    ਬਿੰਦੂ_3 pt;
    HWND hwnd;
    UINT w_ਪ੍ਰਾਪਤੀ_Test_ਕੋਡ;
    ULONG_PTR dwExtraInfo;
  } MOUSEHOOKSTRUCT,*LPMOUSEHOOKSTRUCT,*PMOUSEHOOKSTRUCT;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MOUSEHOOKSTRUCTEX : ਜਨਤਕ ਟੈਗ_MOUSEHOOKSTRUCT {
    DWORD mouse_ਅੰਕੜੇ;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MOUSEHOOKSTRUCTEX {
    MOUSEHOOKSTRUCT _unnamed;
    DWORD mouse_ਅੰਕੜੇ;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT ਸੁਨੇਹਾ_2;
    WPARAM wParam;
    LPARAM lParam;
  } HARDWAREHOOKSTRUCT,*LPHARDWAREHOOKSTRUCT,*PHARDWAREHOOKSTRUCT;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKL_PREV 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HKL_ਅਗਲਾ 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KLF_ACTIVATE 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KLF_SUBSTITUTE_OK 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KLF_REORDER 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KLF_REPLACELANG 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KLF_NOTELLSHELL 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KLF_SETFORPROCESS 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KLF_SHIFTLOCK 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KLF_RESET 0x40000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INPUTLANGCHANGE_SYSCHARSET 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INPUTLANGCHANGE_FORWARD 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INPUTLANGCHANGE_BACKWARD 0x0004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KL_NAMELENGTH 9

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Keyboard_Layout ਲੱਦੋ_Keyboard_Layout_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetKeyboardLayoutName GetKeyboardLayoutNameW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Keyboard_Layout ਲੱਦੋ_Keyboard_Layout_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetKeyboardLayoutName GetKeyboardLayoutNameA
#ਜੇ_ਅੰਤ

  WINUSERAPI HKL WINAPI ਲੱਦੋ_Keyboard_Layout_A(LPCSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ਲੱਦੋ_Keyboard_Layout_W(LPCWSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ActivateKeyboardLayout(HKL hkl,UINT Flags);
  WINUSERAPI ਪੂਰਨ WINAPI ਮੰਜ਼ਿਲ_Unicode_Ex(UINT w_Virt_ਕੁੰਜੀ,UINT w_ਜਾਂਚ_ਕੋਡ,CONST BYTE *lp_ਕੁੰਜੀ_State,LPWSTR pwszBuff,ਪੂਰਨ cchBuff,UINT wFlags,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI UnloadKeyboardLayout(HKL hkl);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameA(LPSTR pwszKLID);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameW(LPWSTR pwszKLID);
  WINUSERAPI ਪੂਰਨ WINAPI GetKeyboardLayoutList(ਪੂਰਨ nBuff,HKL *lpList);
  WINUSERAPI HKL WINAPI GetKeyboardLayout(DWORD idThread);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MOUSEMOVEPOINT {
    ਪੂਰਨ x;
    ਪੂਰਨ y;
    DWORD ਸਮਾਂ;
    ULONG_PTR dwExtraInfo;
  } MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMMP_USE_DISPLAY_POINTS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMMP_USE_ਉੱਚਾ_RESOLUTION_POINTS 2

  WINUSERAPI ਪੂਰਨ WINAPI GetMouseMovePointsEx(UINT cb_ਮਾਪ,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,ਪੂਰਨ nBufPoints,DWORD resolution);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NODESKTOP

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOP_READOBJECTS 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOP_CREATEWINDOW 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOP_CREATEMENU 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOP_HOOKCONTROL 0x0008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOP_JOURNALRECORD 0x0010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOP_JOURNALPLAYBACK 0x0020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOP_ENUMERATE 0x0040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOP_WRITEOBJECTS 0x0080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOP_SWITCHDESKTOP 0x0100L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DF_ALLOWOTHERACCOUNTHOOK 0x0001L

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WINGDI_
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOGDI
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDesktop CreateDesktopW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDesktop CreateDesktopA
#ਜੇ_ਅੰਤ

  WINUSERAPI HDESK WINAPI CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,LPDEVMODEA pDevmode,DWORD dwFlags,ACCESS_ਨਕਾਬ dwDesiredAccess,LPSECURITY_ਗੁਣ lpsa);
  WINUSERAPI HDESK WINAPI CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,LPDEVMODEW pDevmode,DWORD dwFlags,ACCESS_ਨਕਾਬ dwDesiredAccess,LPSECURITY_ਗੁਣ lpsa);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenDesktop OpenDesktopW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumDesktops EnumDesktopsW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OpenDesktop OpenDesktopA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumDesktops EnumDesktopsA
#ਜੇ_ਅੰਤ

  WINUSERAPI HDESK WINAPI OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ਨਕਾਬ dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ਨਕਾਬ dwDesiredAccess);
  WINUSERAPI HDESK WINAPI Open_ਨਿਵੇਸ਼_Desktop(DWORD dwFlags,WINBOOL fInherit,ACCESS_ਨਕਾਬ dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SwitchDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Thread_Desktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI CloseDesktop(HDESK hDesktop);
  WINUSERAPI HDESK WINAPI GetThreadDesktop(DWORD dwThreadId);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINDOWSTATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_ENUMDESKTOPS 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_READATTRIBUTES 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_ACCESSCLIPBOARD 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_CREATEDESKTOP 0x0008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_WRITEATTRIBUTES 0x0010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_ACCESSGLOBALATOMS 0x0020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_EXITWINDOWS 0x0040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_ENUMERATE 0x0100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_READSCREEN 0x0200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CWF_CREATE_ONLY 0x0001L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WSF_VISIBLE 0x0001L

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਖਿੜਕੀ_Station Create_ਖਿੜਕੀ_Station_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Open_ਖਿੜਕੀ_Station Open_ਖਿੜਕੀ_Station_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Enum_ਖਿੜਕੀ_Stations Enum_ਖਿੜਕੀ_Stations_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਖਿੜਕੀ_Station Create_ਖਿੜਕੀ_Station_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Open_ਖਿੜਕੀ_Station Open_ਖਿੜਕੀ_Station_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Enum_ਖਿੜਕੀ_Stations Enum_ਖਿੜਕੀ_Stations_A
#ਜੇ_ਅੰਤ

  WINUSERAPI HWINSTA WINAPI Create_ਖਿੜਕੀ_Station_A(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_ਨਕਾਬ dwDesiredAccess,LPSECURITY_ਗੁਣ lpsa);
  WINUSERAPI HWINSTA WINAPI Create_ਖਿੜਕੀ_Station_W(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_ਨਕਾਬ dwDesiredAccess,LPSECURITY_ਗੁਣ lpsa);
  WINUSERAPI HWINSTA WINAPI Open_ਖਿੜਕੀ_Station_A(LPCSTR lpszWinSta,WINBOOL fInherit,ACCESS_ਨਕਾਬ dwDesiredAccess);
  WINUSERAPI HWINSTA WINAPI Open_ਖਿੜਕੀ_Station_W(LPCWSTR lpszWinSta,WINBOOL fInherit,ACCESS_ਨਕਾਬ dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI Enum_ਖਿੜਕੀ_Stations_A(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Enum_ਖਿੜਕੀ_Stations_W(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Close_ਖਿੜਕੀ_Station(HWINSTA hWinSta);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Process_ਖਿੜਕੀ_Station(HWINSTA hWinSta);
  WINUSERAPI HWINSTA WINAPI Get_Process_ਖਿੜਕੀ_Station(VOID);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOSECURITY
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_User_Object_Security(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
  WINUSERAPI WINBOOL WINAPI GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD n_ਲੰਮਾਈ,LPDWORD lpn_ਲੰਮਾਈ_Needed);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UOI_FLAGS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UOI_NAME 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UOI_TYPE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UOI_USER_SID 4

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_USEROBJECTFLAGS {
    WINBOOL fInherit;
    WINBOOL fReserved;
    DWORD dwFlags;
  } USEROBJECTFLAGS,*PUSEROBJECTFLAGS;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetUserObjectInformation GetUserObjectInformationW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_User_Object_Information ਸੈੱਟ_User_Object_Information_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetUserObjectInformation GetUserObjectInformationA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_User_Object_Information ਸੈੱਟ_User_Object_Information_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationA(HANDLE hObj,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,PVOID pvInfo,DWORD n_ਲੰਮਾਈ,LPDWORD lpn_ਲੰਮਾਈ_Needed);
  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationW(HANDLE hObj,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,PVOID pvInfo,DWORD n_ਲੰਮਾਈ,LPDWORD lpn_ਲੰਮਾਈ_Needed);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_User_Object_Information_A(HANDLE hObj,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,PVOID pvInfo,DWORD n_ਲੰਮਾਈ);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_User_Object_Information_W(HANDLE hObj,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,PVOID pvInfo,DWORD n_ਲੰਮਾਈ);
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_WNDCLASSEXA {
    UINT cb_ਮਾਪ;
    UINT style;
    WNDPROC lpfnWndProc;
    ਪੂਰਨ cbClsExtra;
    ਪੂਰਨ cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
  } WNDCLASSEXA,*PWNDCLASSEXA,*NPWNDCLASSEXA,*LPWNDCLASSEXA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_WNDCLASSEXW {
    UINT cb_ਮਾਪ;
    UINT style;
    WNDPROC lpfnWndProc;
    ਪੂਰਨ cbClsExtra;
    ਪੂਰਨ cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;

    HICON hIconSm;
  } WNDCLASSEXW,*PWNDCLASSEXW,*NPWNDCLASSEXW,*LPWNDCLASSEXW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WNDCLASSEXW WNDCLASSEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWNDCLASSEXW PWNDCLASSEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPWNDCLASSEXW NPWNDCLASSEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWNDCLASSEXW LPWNDCLASSEX;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WNDCLASSEXA WNDCLASSEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWNDCLASSEXA PWNDCLASSEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPWNDCLASSEXA NPWNDCLASSEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWNDCLASSEXA LPWNDCLASSEX;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_WNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    ਪੂਰਨ cbClsExtra;
    ਪੂਰਨ cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
  } WNDCLASSA,*PWNDCLASSA,*NPWNDCLASSA,*LPWNDCLASSA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_WNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    ਪੂਰਨ cbClsExtra;
    ਪੂਰਨ cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
  } WNDCLASSW,*PWNDCLASSW,*NPWNDCLASSW,*LPWNDCLASSW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WNDCLASSW WNDCLASS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWNDCLASSW PWNDCLASS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPWNDCLASSW NPWNDCLASS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWNDCLASSW LPWNDCLASS;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WNDCLASSA WNDCLASS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PWNDCLASSA PWNDCLASS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPWNDCLASSA NPWNDCLASS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPWNDCLASSA LPWNDCLASS;
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI Is_Hung_App_ਖਿੜਕੀ(HWND hwnd);
  WINUSERAPI VOID WINAPI DisableProcessWindowsGhosting(VOID);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMSG
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ਸੁਨੇਹਾ {
    HWND hwnd;
    UINT ਸੁਨੇਹਾ_2;
    WPARAM wParam;
    LPARAM lParam;
    DWORD ਸਮਾਂ;
    ਬਿੰਦੂ_3 pt;
  } ਸੁਨੇਹਾ_3,*PMSG,*NPMSG,*LPMSG;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POINTTOPOINTS(pt) (MAKELONG((ਛੋਟਾ)((pt).x),(ਛੋਟਾ)((pt).y)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINOFFSETS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWL_WNDPROC (-4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWL_HINSTANCE (-6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWL_HWNDPARENT (-8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWL_STYLE (-16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWL_EXSTYLE (-20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWL_USERDATA (-21)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWL_ID (-12)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GWL_WNDPROC
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GWL_HINSTANCE
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GWL_HWNDPARENT
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GWL_USERDATA
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWLP_WNDPROC (-4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWLP_HINSTANCE (-6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWLP_HWNDPARENT (-8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWLP_USERDATA (-21)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GWLP_ID (-12)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_MENUNAME (-8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_HBRBACKGROUND (-10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_HCURSOR (-12)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_HICON (-14)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_HMODULE (-16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_CBWNDEXTRA (-18)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_CBCLSEXTRA (-20)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_WNDPROC (-24)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_STYLE (-26)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCW_ATOM (-32)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCL_HICONSM (-34)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GCL_MENUNAME
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GCL_HBRBACKGROUND
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GCL_HCURSOR
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GCL_HICON
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GCL_HMODULE
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GCL_WNDPROC
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ GCL_HICONSM
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCLP_MENUNAME (-8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCLP_HBRBACKGROUND (-10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCLP_HCURSOR (-12)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCLP_HICON (-14)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCLP_HMODULE (-16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCLP_WNDPROC (-24)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCLP_HICONSM (-34)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINMESSAGES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NULL 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CREATE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DESTROY 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOVE 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ਮਾਪ 0x0005

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ACTIVATE 0x0006

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WA_INACTIVE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WA_ਸਰਗਰਮ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WA_CLICKACTIVE 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SETFOCUS 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_KILLFOCUS 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ENABLE 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SETREDRAW 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SETTEXT 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_GETTEXT 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_GETTEXTLENGTH 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PAINT 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CLOSE 0x0010
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32_WCE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_QUERYENDSESSION 0x0011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_QUERYOPEN 0x0013
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ENDSESSION 0x0016
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_QUIT 0x0012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ERASEBKGND 0x0014
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SYSCOLORCHANGE 0x0015
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SHOWWINDOW 0x0018
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_WININICHANGE 0x001A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SETTINGCHANGE WM_WININICHANGE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DEVMODECHANGE 0x001B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ACTIVATEAPP 0x001C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_FONTCHANGE 0x001D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_TIMECHANGE 0x001E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CANCELMODE 0x001F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SETCURSOR 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOUSEACTIVATE 0x0021
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CHILDACTIVATE 0x0022
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_QUEUESYNC 0x0023

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_GETMINMAXINFO 0x0024

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MINMAXINFO {
    ਬਿੰਦੂ_3 ptReserved;
    ਬਿੰਦੂ_3 pt_Max_ਮਾਪ;
    ਬਿੰਦੂ_3 ptMaxPosition;
    ਬਿੰਦੂ_3 pt_Min_Track_ਮਾਪ;
    ਬਿੰਦੂ_3 pt_Max_Track_ਮਾਪ;
  } MINMAXINFO,*PMINMAXINFO,*LPMINMAXINFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PAINTICON 0x0026
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ICONERASEBKGND 0x0027
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NEXTDLGCTL 0x0028
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SPOOLERSTATUS 0x002A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DRAWITEM 0x002B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MEASUREITEM 0x002C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DELETEITEM 0x002D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_VKEYTOITEM 0x002E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CHARTOITEM 0x002F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SETFONT 0x0030
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_GETFONT 0x0031
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SETHOTKEY 0x0032
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_GETHOTKEY 0x0033
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_QUERYDRAGICON 0x0037
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_COMPAREITEM 0x0039
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32_WCE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_GETOBJECT 0x003D
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_COMPACTING 0x0041
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_COMMNOTIFY 0x0044
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_WINDOWPOSCHANGING 0x0046
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_WINDOWPOSCHANGED 0x0047

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_POWER 0x0048

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PWR_OK 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PWR_FAIL (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PWR_SUSPENDREQUEST 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PWR_SUSPENDRESUME 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PWR_CRITICALRESUME 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_COPYDATA 0x004A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CANCELJOURNAL 0x004B

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_COPYDATASTRUCT {
    ULONG_PTR dw_ਅੰਕੜੇ;
    DWORD cb_ਅੰਕੜੇ;
    PVOID lp_ਅੰਕੜੇ;
  } COPYDATASTRUCT,*PCOPYDATASTRUCT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MDINEXTMENU {
    HMENU hmenu_ਵਿੱਚ;
    HMENU hmenu_ਅਗਲਾ;
    HWND hwnd_ਅਗਲਾ;
  } MDINEXTMENU,*PMDINEXTMENU,*LPMDINEXTMENU;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NOTIFY 0x004E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_INPUTLANGCHANGEREQUEST 0x0050
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_INPUTLANGCHANGE 0x0051
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_TCARD 0x0052
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_HELP 0x0053
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_USERCHANGED 0x0054
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NOTIFYFORMAT 0x0055

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NFR_ANSI 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NFR_UNICODE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NF_QUERY 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NF_REQUERY 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CONTEXTMENU 0x007B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_STYLECHANGING 0x007C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_STYLECHANGED 0x007D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DISPLAYCHANGE 0x007E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_GETICON 0x007F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SETICON 0x0080

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCCREATE 0x0081
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCDESTROY 0x0082
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCCALCSIZE 0x0083
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCHITTEST 0x0084
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCPAINT 0x0085
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCACTIVATE 0x0086
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_GETDLGCODE 0x0087
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32_WCE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SYNCPAINT 0x0088
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCMOUSEMOVE 0x00A0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCLBUTTONDOWN 0x00A1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCLBUTTONUP 0x00A2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCLBUTTONDBLCLK 0x00A3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCRBUTTONDOWN 0x00A4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCRBUTTONUP 0x00A5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCRBUTTONDBLCLK 0x00A6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCMBUTTONDOWN 0x00A7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCMBUTTONUP 0x00A8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCMBUTTONDBLCLK 0x00A9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCXBUTTONDOWN 0x00AB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCXBUTTONUP 0x00AC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCXBUTTONDBLCLK 0x00AD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ਨਿਵੇਸ਼ 0x00FF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_KEYFIRST 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_KEYDOWN 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_KEYUP 0x0101
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CHAR 0x0102
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DEADCHAR 0x0103
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SYSKEYDOWN 0x0104
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SYSKEYUP 0x0105
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SYSCHAR 0x0106
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SYSDEADCHAR 0x0107
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_UNICHAR 0x0109
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_KEYLAST 0x0109
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UNICODE_NOCHAR 0xFFFF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_STARTCOMPOSITION 0x010D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_ENDCOMPOSITION 0x010E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_COMPOSITION 0x010F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_KEYLAST 0x010F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_INITDIALOG 0x0110
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_COMMAND 0x0111
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SYSCOMMAND 0x0112
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_TIMER 0x0113
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_HSCROLL 0x0114
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_VSCROLL 0x0115
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_INITMENU 0x0116
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_INITMENUPOPUP 0x0117
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MENUSELECT 0x011F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MENUCHAR 0x0120
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ENTERIDLE 0x0121
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32_WCE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MENURBUTTONUP 0x0122
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MENUDRAG 0x0123
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MENUGETOBJECT 0x0124
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_UNINITMENUPOPUP 0x0125
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MENUCOMMAND 0x0126

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32_WCE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CHANGEUISTATE 0x0127
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_UPDATEUISTATE 0x0128
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_QUERYUISTATE 0x0129

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UIS_ਸੈੱਟ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UIS_CLEAR 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UIS_INITIALIZE 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UISF_HIDEFOCUS 0x1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UISF_HIDEACCEL 0x2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UISF_ਸਰਗਰਮ 0x4
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CTLCOLORMSGBOX 0x0132
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CTLCOLOREDIT 0x0133
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CTLCOLORLISTBOX 0x0134
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CTLCOLORBTN 0x0135
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CTLCOLORDLG 0x0136
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CTLCOLORSCROLLBAR 0x0137
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CTLCOLORSTATIC 0x0138
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MN_GETHMENU 0x01E1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOUSEFIRST 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOUSEMOVE 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_LBUTTONDOWN 0x0201
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_LBUTTONUP 0x0202
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_LBUTTONDBLCLK 0x0203
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_RBUTTONDOWN 0x0204
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_RBUTTONUP 0x0205
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_RBUTTONDBLCLK 0x0206
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MBUTTONDOWN 0x0207
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MBUTTONUP 0x0208
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MBUTTONDBLCLK 0x0209
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOUSEWHEEL 0x020A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_XBUTTONDOWN 0x020B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_XBUTTONUP 0x020C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_XBUTTONDBLCLK 0x020D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOUSEHWHEEL 0x020E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOUSELAST 0x020E

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WHEEL_DELTA 120
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_WHEEL_DELTA_WPARAM(wParam) ((ਛੋਟਾ)HIWORD(wParam))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WHEEL_PAGESCROLL (UINT_MAX)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_NCHITTEST_WPARAM(wParam) ((ਛੋਟਾ)LOWORD(wParam))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XBUTTON1 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ XBUTTON2 0x0002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PARENTNOTIFY 0x0210
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ENTERMENULOOP 0x0211
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_EXITMENULOOP 0x0212

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NEXTMENU 0x0213
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SIZING 0x0214
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CAPTURECHANGED 0x0215
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOVING 0x0216

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_POWERBROADCAST 0x0218

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WIN32_WCE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMQUERYSUSPEND 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMQUERYSTANDBY 0x0001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMQUERYSUSPENDFAILED 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMQUERYSTANDBYFAILED 0x0003

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMSUSPEND 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMSTANDBY 0x0005

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMRESUMECRITICAL 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMRESUMESUSPEND 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMRESUMESTANDBY 0x0008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBTF_APMRESUMEFROMFAILURE 0x00000001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMBATTERYLOW 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMPOWERSTATUSCHANGE 0x000A

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMOEMEVENT 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PBT_APMRESUMEAUTOMATIC 0x0012
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DEVICECHANGE 0x0219

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDICREATE 0x0220
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDIDESTROY 0x0221
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDIACTIVATE 0x0222
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDIRESTORE 0x0223
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDINEXT 0x0224
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDIMAXIMIZE 0x0225
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDITILE 0x0226
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDICASCADE 0x0227
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDIICONARRANGE 0x0228
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDIGETACTIVE 0x0229

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDISETMENU 0x0230
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ENTERSIZEMOVE 0x0231
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_EXITSIZEMOVE 0x0232
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DROPFILES 0x0233
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MDIREFRESHMENU 0x0234

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_SETCONTEXT 0x0281
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_NOTIFY 0x0282
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_CONTROL 0x0283
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_COMPOSITIONFULL 0x0284
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_SELECT 0x0285
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_CHAR 0x0286
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_REQUEST 0x0288
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_KEYDOWN 0x0290
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_IME_KEYUP 0x0291

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOUSEHOVER 0x02A1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_MOUSELEAVE 0x02A3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCMOUSEHOVER 0x02A0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_NCMOUSELEAVE 0x02A2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_WTSSESSION_CHANGE 0x02B1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_TABLET_ਪਹਿਲਾ 0x02c0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_TABLET_ਆਖਰੀ 0x02df
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CUT 0x0300
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_COPY 0x0301
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PASTE 0x0302
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CLEAR 0x0303
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_UNDO 0x0304
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_RENDERFORMAT 0x0305
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_RENDERALLFORMATS 0x0306
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DESTROYCLIPBOARD 0x0307
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_DRAWCLIPBOARD 0x0308
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PAINTCLIPBOARD 0x0309
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_VSCROLLCLIPBOARD 0x030A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_SIZECLIPBOARD 0x030B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_ASKCBFORMATNAME 0x030C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_CHANGECBCHAIN 0x030D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_HSCROLLCLIPBOARD 0x030E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_QUERYNEWPALETTE 0x030F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PALETTEISCHANGING 0x0310
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PALETTECHANGED 0x0311
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_HOTKEY 0x0312
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PRINT 0x0317
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PRINTCLIENT 0x0318
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_APPCOMMAND 0x0319
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_THEMECHANGED 0x031A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_HANDHELDFIRST 0x0358
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_HANDHELDLAST 0x035F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_AFXFIRST 0x0360
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_AFXLAST 0x037F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PENWINFIRST 0x0380
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_PENWINLAST 0x038F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_APP 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WM_USER 0x0400

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WMSZ_ਖੱਬਾ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WMSZ_ਸੱਜਾ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WMSZ_ਸਿਖਰ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WMSZ_TOPLEFT 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WMSZ_TOPRIGHT 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WMSZ_BOTTOM 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WMSZ_BOTTOMLEFT 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WMSZ_BOTTOMRIGHT 8

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NONCMESSAGES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTERROR (-2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTTRANSPARENT (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTNOWHERE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTCLIENT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTCAPTION 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTSYSMENU 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTGROWBOX 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTSIZE HTGROWBOX
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTMENU 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTHSCROLL 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTVSCROLL 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTMINBUTTON 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTMAXBUTTON 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTLEFT 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTRIGHT 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTTOP 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTTOPLEFT 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTTOPRIGHT 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTBOTTOM 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTBOTTOMLEFT 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTBOTTOMRIGHT 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTBORDER 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTREDUCE HTMINBUTTON
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTZOOM HTMAXBUTTON
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTSIZEFIRST HTLEFT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTSIZELAST HTBOTTOMRIGHT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTOBJECT 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTCLOSE 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HTHELP 21

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SMTO_ਸਾਧਾਰਨ 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SMTO_ਖੰਡ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SMTO_ABORTIFHUNG 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MA_ACTIVATE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MA_ACTIVATEANDEAT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MA_NOACTIVATE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MA_NOACTIVATEANDEAT 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICON_SMALL 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICON_BIG 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICON_SMALL2 2

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_ਖਿੜਕੀ_ਸੁਨੇਹਾ ਰਜਿਸਟਰ_ਖਿੜਕੀ_ਸੁਨੇਹਾ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_ਖਿੜਕੀ_ਸੁਨੇਹਾ ਰਜਿਸਟਰ_ਖਿੜਕੀ_ਸੁਨੇਹਾ_A
#ਜੇ_ਅੰਤ

  WINUSERAPI UINT WINAPI ਰਜਿਸਟਰ_ਖਿੜਕੀ_ਸੁਨੇਹਾ_A(LPCSTR lpString);
  WINUSERAPI UINT WINAPI ਰਜਿਸਟਰ_ਖਿੜਕੀ_ਸੁਨੇਹਾ_W(LPCWSTR lpString);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਮਾਪ_RESTORED 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਮਾਪ_MINIMIZED 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਮਾਪ_MAXIMIZED 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਮਾਪ_MAXSHOW 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਮਾਪ_MAXHIDE 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZENORMAL ਮਾਪ_RESTORED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZEICONIC ਮਾਪ_MINIMIZED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZEFULLSCREEN ਮਾਪ_MAXIMIZED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZEZOOMSHOW ਮਾਪ_MAXSHOW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZEZOOMHIDE ਮਾਪ_MAXHIDE

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_WINDOWPOS {
    HWND hwnd;
    HWND hwnd_ਪਾਓ_After;
    ਪੂਰਨ x;
    ਪੂਰਨ y;
    ਪੂਰਨ cx;
    ਪੂਰਨ cy;
    UINT flags;
  } WINDOWPOS,*LPWINDOWPOS,*PWINDOWPOS;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_NCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
  } NCCALCSIZE_PARAMS,*LPNCCALCSIZE_PARAMS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WVR_ALIGNTOP 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WVR_ALIGNLEFT 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WVR_ALIGNBOTTOM 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WVR_ALIGNRIGHT 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WVR_HREDRAW 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WVR_VREDRAW 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WVR_VALIDRECTS 0x0400

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOKEYSTATES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MK_LBUTTON 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MK_RBUTTON 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MK_ਖਿਸਕਾਓ 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MK_CONTROL 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MK_MBUTTON 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MK_XBUTTON1 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MK_XBUTTON2 0x0040
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOTRACKMOUSEEVENT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TME_HOVER 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TME_LEAVE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TME_NONCLIENT 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TME_QUERY 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TME_CANCEL 0x80000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HOVER_DEFAULT 0xFFFFFFFF
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_TRACKMOUSEEVENT {
    DWORD cb_ਮਾਪ;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dw_Hover_ਸਮਾਂ;
  } TRACKMOUSEEVENT,*LPTRACKMOUSEEVENT;

  WINUSERAPI WINBOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINSTYLES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_OVERLAPPED 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_POPUP 0x80000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_ਬੱਚਾ 0x40000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_MINIMIZE 0x20000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_VISIBLE 0x10000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_DISABLED 0x08000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_CLIPSIBLINGS 0x04000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_CLIPCHILDREN 0x02000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_MAXIMIZE 0x01000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_CAPTION 0x00C00000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_BORDER 0x00800000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_DLGFRAME 0x00400000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_VSCROLL 0x00200000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_HSCROLL 0x00100000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_SYSMENU 0x00080000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_THICKFRAME 0x00040000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_ਸਮੂਹ 0x00020000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_TABSTOP 0x00010000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_MINIMIZEBOX 0x00020000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_MAXIMIZEBOX 0x00010000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_TILED WS_OVERLAPPED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_ICONIC WS_MINIMIZE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_SIZEBOX WS_THICKFRAME
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_CHILDWINDOW (WS_ਬੱਚਾ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_DLGMODALFRAME 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_NOPARENTNOTIFY 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_TOPMOST 0x00000008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_ACCEPTFILES 0x00000010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_TRANSPARENT 0x00000020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_MDICHILD 0x00000040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_TOOLWINDOW 0x00000080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_WINDOWEDGE 0x00000100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_CLIENTEDGE 0x00000200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_CONTEXTHELP 0x00000400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_ਸੱਜਾ 0x00001000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_ਖੱਬਾ 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_RTLREADING 0x00002000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_LTRREADING 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_LEFTSCROLLBAR 0x00004000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_RIGHTSCROLLBAR 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_CONTROLPARENT 0x00010000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_STATICEDGE 0x00020000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_APPWINDOW 0x00040000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_LAYERED 0x00080000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_NOINHERITLAYOUT 0x00100000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_LAYOUTRTL 0x00400000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_COMPOSITED 0x02000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_EX_NOACTIVATE 0x08000000L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_VREDRAW 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_HREDRAW 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_DBLCLKS 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_OWNDC 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_CLASSDC 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_PARENTDC 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_NOCLOSE 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_SAVEBITS 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_BYTEALIGNCLIENT 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_BYTEALIGNWINDOW 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_GLOBALCLASS 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_IME 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_DROPSHADOW 0x00020000
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRF_CHECKVISIBLE 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRF_NONCLIENT 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRF_CLIENT 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRF_ERASEBKGND 0x00000008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRF_CHILDREN 0x00000010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRF_OWNED 0x00000020L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BDR_RAISEDOUTER 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BDR_SUNKENOUTER 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BDR_RAISEDINNER 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BDR_SUNKENINNER 0x0008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕਿਨਾਰਾ_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕਿਨਾਰਾ_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕਿਨਾਰਾ_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਕਿਨਾਰਾ_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_ਖੱਬਾ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_ਸਿਖਰ 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_ਸੱਜਾ 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_BOTTOM 0x0008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_TOPLEFT (BF_ਸਿਖਰ | BF_ਖੱਬਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_TOPRIGHT (BF_ਸਿਖਰ | BF_ਸੱਜਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_BOTTOMLEFT (BF_BOTTOM | BF_ਖੱਬਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_BOTTOMRIGHT (BF_BOTTOM | BF_ਸੱਜਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_RECT (BF_ਖੱਬਾ | BF_ਸਿਖਰ | BF_ਸੱਜਾ | BF_BOTTOM)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_DIAGONAL 0x0010

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_ਸਿਖਰ | BF_ਸੱਜਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_ਸਿਖਰ | BF_ਖੱਬਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_ਖੱਬਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_ਸੱਜਾ)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_ਵਿਚਕਾਰ 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_SOFT 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_ADJUST 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_FLAT 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BF_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_ਕਿਨਾਰਾ(HDC hdc,LPRECT qrc,UINT ਕਿਨਾਰਾ,UINT grfFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFC_CAPTION 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFC_MENU 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFC_SCROLL 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFC_BUTTON 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFC_POPUPMENU 5

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_CAPTIONCLOSE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_CAPTIONMIN 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_CAPTIONMAX 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_CAPTIONRESTORE 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_CAPTIONHELP 0x0004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_MENUARROW 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_MENUCHECK 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_MENUBULLET 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_MENUARROWRIGHT 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_SCROLLUP 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_SCROLLDOWN 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_SCROLLLEFT 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_SCROLLRIGHT 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_SCROLLCOMBOBOX 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_SCROLLSIZEGRIP 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_BUTTONCHECK 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_BUTTONRADIOIMAGE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_BUTTONRADIOMASK 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_BUTTONRADIO 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_BUTTON3STATE 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_BUTTONPUSH 0x0010

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_INACTIVE 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_PUSHED 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_CHECKED 0x0400

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_TRANSPARENT 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_HOT 0x1000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_ADJUSTRECT 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_FLAT 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DFCS_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_ਚੌਖਟਾ_Control(HDC,LPRECT,UINT,UINT);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_ਸਰਗਰਮ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_SMALLCAP 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_ICON 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_ਪਾਠ 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_INBUTTON 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_GRADIENT 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_BUTTONS 0x1000

  WINUSERAPI WINBOOL WINAPI DrawCaption(HWND hwnd,HDC hdc,CONST RECT *lprect,UINT flags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDANI_OPEN 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDANI_CAPTION 3

  WINUSERAPI WINBOOL WINAPI DrawAnimatedRects(HWND hwnd,ਪੂਰਨ idAni,CONST RECT *lprcFrom,CONST RECT *lprc_ਮੰਜ਼ਿਲ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOCLIPBOARD

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_ਪਾਠ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_BITMAP 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_METAFILEPICT 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_SYLK 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_DIF 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_TIFF 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_OEMTEXT 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_DIB 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_PALETTE 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_PENDATA 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_RIFF 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_WAVE 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_UNICODETEXT 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_ENHMETAFILE 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_HDROP 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_LOCALE 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_DIBV5 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_MAX 18

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_OWNERDISPLAY 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_DSPTEXT 0x0081
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_DSPBITMAP 0x0082
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_DSPMETAFILEPICT 0x0083
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_DSPENHMETAFILE 0x008E

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_PRIVATEFIRST 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_PRIVATELAST 0x02FF

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_GDIOBJFIRST 0x0300
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CF_GDIOBJLAST 0x03FF
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FVIRTKEY TRUE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FNOINVERT 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FSHIFT 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FCONTROL 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FALT 0x10

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ACCEL {
    BYTE fVirt;
    ਸ਼ਬਦ_3 ਕੁੰਜੀ;
    ਸ਼ਬਦ_3 cmd;
  } ACCEL,*LPACCEL;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_PAINTSTRUCT {
    HDC hdc;
    WINBOOL fErase;
    RECT rcPaint;
    WINBOOL fRestore;
    WINBOOL fIncUpdate;
    BYTE rgbReserved[32];
  } PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CREATESTRUCTA {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_ਮਾਪਾ_2;
    ਪੂਰਨ cy;
    ਪੂਰਨ cx;
    ਪੂਰਨ y;
    ਪੂਰਨ x;
    LONG style;
    LPCSTR lpszName;
    LPCSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTA,*LPCREATESTRUCTA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_ਮਾਪਾ_2;
    ਪੂਰਨ cy;
    ਪੂਰਨ cx;
    ਪੂਰਨ y;
    ਪੂਰਨ x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTW,*LPCREATESTRUCTW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CREATESTRUCTW CREATESTRUCT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCREATESTRUCTW LPCREATESTRUCT;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CREATESTRUCTA CREATESTRUCT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCREATESTRUCTA LPCREATESTRUCT;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_WINDOWPLACEMENT {
    UINT ਲੰਮਾਈ;
    UINT flags;
    UINT showCmd;
    ਬਿੰਦੂ_3 ptMinPosition;
    ਬਿੰਦੂ_3 ptMaxPosition;
    RECT rc_ਸਾਧਾਰਨ_Position;
  } WINDOWPLACEMENT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINDOWPLACEMENT *PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WPF_SETMINPOSITION 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WPF_RESTORETOMAXIMIZED 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WPF_ASYNCWINDOWPLACEMENT 0x0004

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_NMHDR {
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT ਕੋਡ;
  } NMHDR;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NMHDR *LPNMHDR;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_STYLESTRUCT {
    DWORD styleOld;
    DWORD styleNew;
  } STYLESTRUCT,*LPSTYLESTRUCT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODT_MENU 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODT_LISTBOX 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODT_COMBOBOX 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODT_BUTTON 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODT_STATIC 5

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODA_DRAWENTIRE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODA_SELECT 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODA_FOCUS 0x0004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_SELECTED 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_GRAYED 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_DISABLED 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_CHECKED 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_FOCUS 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_DEFAULT 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_COMBOBOXEDIT 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_HOTLIGHT 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_INACTIVE 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_NOACCEL 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ODS_NOFOCUSRECT 0x0200

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT ਵਸਤੂ_ID;
    UINT ਵਸਤੂ_ਚੌੜਾਈ;
    UINT ਵਸਤੂ_ਉਚਾਈ;
    ULONG_PTR ਵਸਤੂ_ਅੰਕੜੇ;
  } MEASUREITEMSTRUCT,*PMEASUREITEMSTRUCT,*LPMEASUREITEMSTRUCT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_DRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT ਵਸਤੂ_ID;
    UINT ਵਸਤੂ_Action;
    UINT ਵਸਤੂ_State;
    HWND hwnd_ਵਸਤੂ;
    HDC hDC;
    RECT rc_ਵਸਤੂ;
    ULONG_PTR ਵਸਤੂ_ਅੰਕੜੇ;
  } DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_DELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT ਵਸਤੂ_ID;
    HWND hwnd_ਵਸਤੂ;
    ULONG_PTR ਵਸਤੂ_ਅੰਕੜੇ;
  } DELETEITEMSTRUCT,*PDELETEITEMSTRUCT,*LPDELETEITEMSTRUCT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_COMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwnd_ਵਸਤੂ;
    UINT ਵਸਤੂ_ID1;
    ULONG_PTR ਵਸਤੂ_Data1;
    UINT ਵਸਤੂ_ID2;
    ULONG_PTR ਵਸਤੂ_Data2;
    DWORD dwLocaleId;
  } COMPAREITEMSTRUCT,*PCOMPAREITEMSTRUCT,*LPCOMPAREITEMSTRUCT;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMSG
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਸੁਨੇਹਾ Get_ਸੁਨੇਹਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dispatch_ਸੁਨੇਹਾ Dispatch_ਸੁਨੇਹਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Peek_ਸੁਨੇਹਾ Peek_ਸੁਨੇਹਾ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਸੁਨੇਹਾ Get_ਸੁਨੇਹਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dispatch_ਸੁਨੇਹਾ Dispatch_ਸੁਨੇਹਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Peek_ਸੁਨੇਹਾ Peek_ਸੁਨੇਹਾ_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI Get_ਸੁਨੇਹਾ_A(LPMSG lp_ਸੁਨੇਹਾ_2,HWND hWnd,UINT w_ਸੁਨੇਹਾ_Filter_Min,UINT w_ਸੁਨੇਹਾ_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Get_ਸੁਨੇਹਾ_W(LPMSG lp_ਸੁਨੇਹਾ_2,HWND hWnd,UINT w_ਸੁਨੇਹਾ_Filter_Min,UINT w_ਸੁਨੇਹਾ_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Translate_ਸੁਨੇਹਾ(CONST ਸੁਨੇਹਾ_3 *lp_ਸੁਨੇਹਾ_2);
  WINUSERAPI LRESULT WINAPI Dispatch_ਸੁਨੇਹਾ_A(CONST ਸੁਨੇਹਾ_3 *lp_ਸੁਨੇਹਾ_2);
  WINUSERAPI LRESULT WINAPI Dispatch_ਸੁਨੇਹਾ_W(CONST ਸੁਨੇਹਾ_3 *lp_ਸੁਨੇਹਾ_2);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_ਸੁਨੇਹਾ_ਕਤਾਰ(ਪੂਰਨ cMessagesMax);
  WINUSERAPI WINBOOL WINAPI Peek_ਸੁਨੇਹਾ_A(LPMSG lp_ਸੁਨੇਹਾ_2,HWND hWnd,UINT w_ਸੁਨੇਹਾ_Filter_Min,UINT w_ਸੁਨੇਹਾ_Filter_Max,UINT w_Remove_ਸੁਨੇਹਾ);
  WINUSERAPI WINBOOL WINAPI Peek_ਸੁਨੇਹਾ_W(LPMSG lp_ਸੁਨੇਹਾ_2,HWND hWnd,UINT w_ਸੁਨੇਹਾ_Filter_Min,UINT w_ਸੁਨੇਹਾ_Filter_Max,UINT w_Remove_ਸੁਨੇਹਾ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PM_NOREMOVE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PM_REMOVE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PM_NOYIELD 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PM_QS_ਨਿਵੇਸ਼ (QS_ਨਿਵੇਸ਼ << 16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PM_QS_PAINT (QS_PAINT << 16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI ਰਜਿਸਟਰ_Hot_ਕੁੰਜੀ(HWND hWnd,ਪੂਰਨ id,UINT fsModifiers,UINT vk);
  WINUSERAPI WINBOOL WINAPI Unregister_Hot_ਕੁੰਜੀ(HWND hWnd,ਪੂਰਨ id);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOD_ALT 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOD_CONTROL 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOD_ਖਿਸਕਾਓ 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOD_WIN 0x0008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDHOT_SNAPWINDOW (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDHOT_SNAPDESKTOP (-2)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ WIN_ਅੰਦਰੂਨੀ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ LSTRING
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOLSTRING
#ਜੇ_ਅੰਤ
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ LFILEIO
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOLFILEIO
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENDSESSION_LOGOFF 0x80000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EWX_LOGOFF 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EWX_SHUTDOWN 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EWX_REBOOT 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EWX_FORCE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EWX_POWEROFF 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EWX_FORCEIFHUNG 0x00000010

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ExitWindows(dwReserved,ਕੋਡ_4) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_ਸੁਨੇਹਾ Send_ਸੁਨੇਹਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_ਸੁਨੇਹਾ_Timeout Send_ਸੁਨੇਹਾ_Timeout_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_Notify_ਸੁਨੇਹਾ Send_Notify_ਸੁਨੇਹਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_ਸੁਨੇਹਾ_Callback Send_ਸੁਨੇਹਾ_Callback_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_ਸੁਨੇਹਾ Send_ਸੁਨੇਹਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_ਸੁਨੇਹਾ_Timeout Send_ਸੁਨੇਹਾ_Timeout_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_Notify_ਸੁਨੇਹਾ Send_Notify_ਸੁਨੇਹਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_ਸੁਨੇਹਾ_Callback Send_ਸੁਨੇਹਾ_Callback_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI ExitWindowsEx(UINT uFlags,DWORD dwReason);
  WINUSERAPI WINBOOL WINAPI ਅਦਲਾ_ਬਦਲੀ_Mouse_Button(WINBOOL f_ਅਦਲਾ_ਬਦਲੀ);
  WINUSERAPI DWORD WINAPI Get_ਸੁਨੇਹਾ_Pos(VOID);
  WINUSERAPI LONG WINAPI Get_ਸੁਨੇਹਾ_ਸਮਾਂ(VOID);
  WINUSERAPI LPARAM WINAPI Get_ਸੁਨੇਹਾ_Extra_Info(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Wow64_ਸੁਨੇਹਾ(VOID);
  WINUSERAPI LPARAM WINAPI ਸੈੱਟ_ਸੁਨੇਹਾ_Extra_Info(LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_ਸੁਨੇਹਾ_A(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_ਸੁਨੇਹਾ_W(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_ਸੁਨੇਹਾ_Timeout_A(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_ਨਤੀਜਾ);
  WINUSERAPI LRESULT WINAPI Send_ਸੁਨੇਹਾ_Timeout_W(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_ਨਤੀਜਾ);
  WINUSERAPI WINBOOL WINAPI Send_Notify_ਸੁਨੇਹਾ_A(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_Notify_ਸੁਨੇਹਾ_W(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_ਸੁਨੇਹਾ_Callback_A(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_ਨਤੀਜਾ_Call_ਪਿੱਠ,ULONG_PTR dw_ਅੰਕੜੇ);
  WINUSERAPI WINBOOL WINAPI Send_ਸੁਨੇਹਾ_Callback_W(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_ਨਤੀਜਾ_Call_ਪਿੱਠ,ULONG_PTR dw_ਅੰਕੜੇ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    UINT cb_ਮਾਪ;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
  } BSMINFO,*PBSMINFO;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_Ex ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_Ex ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_A
#ਜੇ_ਅੰਤ

  WINUSERAPI ਲੰਮਾ WINAPI ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_Ex_A(DWORD flags,LPDWORD lpInfo,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI ਲੰਮਾ WINAPI ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_Ex_W(DWORD flags,LPDWORD lpInfo,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI ਲੰਮਾ WINAPI ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_A(DWORD flags,LPDWORD lpInfo,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI ਲੰਮਾ WINAPI ਪ੍ਰਸਾਰਣ_System_ਸੁਨੇਹਾ_W(DWORD flags,LPDWORD lpInfo,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSM_ALLCOMPONENTS 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSM_VXDS 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSM_NETDRIVER 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSM_INSTALLABLEDRIVERS 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSM_APPLICATIONS 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSM_ALLDESKTOPS 0x00000010

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_QUERY 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_IGNORECURRENTTASK 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_FLUSHDISK 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_NOHANG 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_POSTMESSAGE 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_FORCEIFHUNG 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_ALLOWSFW 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_SENDNOTIFYMESSAGE 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_RETURNHDESK 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BSF_LUID 0x00000400

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪ੍ਰਸਾਰਣ_QUERY_DENY 0x424D5144

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PVOID HDEVNOTIFY;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HDEVNOTIFY *PHDEVNOTIFY;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEVICE_NOTIFY_ਖਿੜਕੀ_HANDLE 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Device_Notification ਰਜਿਸਟਰ_Device_Notification_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Post_ਸੁਨੇਹਾ Post_ਸੁਨੇਹਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Post_Thread_ਸੁਨੇਹਾ Post_Thread_ਸੁਨੇਹਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Post_App_ਸੁਨੇਹਾ Post_App_ਸੁਨੇਹਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Def_ਖਿੜਕੀ_Proc Def_ਖਿੜਕੀ_Proc_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Call_ਖਿੜਕੀ_Proc Call_ਖਿੜਕੀ_Proc_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Class ਰਜਿਸਟਰ_Class_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UnregisterClass UnregisterClassW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassInfo GetClassInfoW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Class_Ex ਰਜਿਸਟਰ_Class_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassInfoEx GetClassInfoExW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Device_Notification ਰਜਿਸਟਰ_Device_Notification_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Post_ਸੁਨੇਹਾ Post_ਸੁਨੇਹਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Post_Thread_ਸੁਨੇਹਾ Post_Thread_ਸੁਨੇਹਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Post_App_ਸੁਨੇਹਾ Post_App_ਸੁਨੇਹਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Def_ਖਿੜਕੀ_Proc Def_ਖਿੜਕੀ_Proc_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Call_ਖਿੜਕੀ_Proc Call_ਖਿੜਕੀ_Proc_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Class ਰਜਿਸਟਰ_Class_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ UnregisterClass UnregisterClassA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassInfo GetClassInfoA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Class_Ex ਰਜਿਸਟਰ_Class_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassInfoEx GetClassInfoExA
#ਜੇ_ਅੰਤ

  WINUSERAPI HDEVNOTIFY WINAPI ਰਜਿਸਟਰ_Device_Notification_A(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI HDEVNOTIFY WINAPI ਰਜਿਸਟਰ_Device_Notification_W(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI WINBOOL WINAPI UnregisterDeviceNotification(HDEVNOTIFY Handle);
  WINUSERAPI WINBOOL WINAPI Post_ਸੁਨੇਹਾ_A(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_ਸੁਨੇਹਾ_W(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_ਸੁਨੇਹਾ_A(DWORD idThread,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_ਸੁਨੇਹਾ_W(DWORD idThread,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Post_App_ਸੁਨੇਹਾ_A(idThread,w_ਸੁਨੇਹਾ,wParam,lParam) Post_Thread_ਸੁਨੇਹਾ_A((DWORD)idThread,w_ਸੁਨੇਹਾ,wParam,lParam)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Post_App_ਸੁਨੇਹਾ_W(idThread,w_ਸੁਨੇਹਾ,wParam,lParam) Post_Thread_ਸੁਨੇਹਾ_W((DWORD)idThread,w_ਸੁਨੇਹਾ,wParam,lParam)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HWND_ਪ੍ਰਸਾਰਣ ((HWND)0xffff)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HWND_ਸੁਨੇਹਾ ((HWND)-3)

  WINUSERAPI WINBOOL WINAPI Attach_Thread_ਨਿਵੇਸ਼(DWORD idAttach,DWORD id_Attach_ਮੰਜ਼ਿਲ,WINBOOL fAttach);
  WINUSERAPI WINBOOL WINAPI ਜਵਾਬ_ਸੁਨੇਹਾ(LRESULT l_ਨਤੀਜਾ);
  WINUSERAPI WINBOOL WINAPI Wait_ਸੁਨੇਹਾ(VOID);
  WINUSERAPI DWORD WINAPI Wait_For_ਨਿਵੇਸ਼_Idle(HANDLE hProcess,DWORD dwMilliseconds);
  WINUSERAPI LRESULT WINAPI Def_ਖਿੜਕੀ_Proc_A(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_ਖਿੜਕੀ_Proc_W(HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI VOID WINAPI Post_Quit_ਸੁਨੇਹਾ(ਪੂਰਨ n_Exit_ਕੋਡ);
  WINUSERAPI LRESULT WINAPI Call_ਖਿੜਕੀ_Proc_A(WNDPROC lpPrevWndFunc,HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Call_ਖਿੜਕੀ_Proc_W(WNDPROC lpPrevWndFunc,HWND hWnd,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI ਵਿੱਚ_Send_ਸੁਨੇਹਾ(VOID);
  WINUSERAPI DWORD WINAPI ਵਿੱਚ_Send_ਸੁਨੇਹਾ_Ex(LPVOID lpReserved);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISMEX_NOSEND 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISMEX_SEND 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISMEX_NOTIFY 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISMEX_CALLBACK 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISMEX_REPLIED 0x00000008

  WINUSERAPI UINT WINAPI Get_Double_Click_ਸਮਾਂ(VOID);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Double_Click_ਸਮਾਂ(UINT);
  WINUSERAPI ATOM WINAPI ਰਜਿਸਟਰ_Class_A(CONST WNDCLASSA *lpWndClass);
  WINUSERAPI ATOM WINAPI ਰਜਿਸਟਰ_Class_W(CONST WNDCLASSW *lpWndClass);
  WINUSERAPI WINBOOL WINAPI UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
  WINUSERAPI WINBOOL WINAPI GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
  WINUSERAPI ATOM WINAPI ਰਜਿਸਟਰ_Class_Ex_A(CONST WNDCLASSEXA *);
  WINUSERAPI ATOM WINAPI ਰਜਿਸਟਰ_Class_Ex_W(CONST WNDCLASSEXW *);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CW_USEDEFAULT ((ਪੂਰਨ)0x80000000)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HWND_DESKTOP ((HWND)0)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ BOOLEAN (WINAPI *PREGISTERCLASSNAMEW)(LPCWSTR);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਖਿੜਕੀ_Ex Create_ਖਿੜਕੀ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਖਿੜਕੀ Create_ਖਿੜਕੀ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਖਿੜਕੀ_Ex Create_ਖਿੜਕੀ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਖਿੜਕੀ Create_ਖਿੜਕੀ_A
#ਜੇ_ਅੰਤ

  WINUSERAPI HWND WINAPI Create_ਖਿੜਕੀ_Ex_A(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lp_ਖਿੜਕੀ_Name,DWORD dwStyle,ਪੂਰਨ X,ਪੂਰਨ Y,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ,HWND h_Wnd_ਮਾਪਾ,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
  WINUSERAPI HWND WINAPI Create_ਖਿੜਕੀ_Ex_W(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lp_ਖਿੜਕੀ_Name,DWORD dwStyle,ਪੂਰਨ X,ਪੂਰਨ Y,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ,HWND h_Wnd_ਮਾਪਾ,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਖਿੜਕੀ_A(lpClassName,lp_ਖਿੜਕੀ_Name,dwStyle,x,y,n_ਚੌੜਾਈ,n_ਉਚਾਈ,h_Wnd_ਮਾਪਾ,hMenu,hInstance,lpParam) Create_ਖਿੜਕੀ_Ex_A(0L,lpClassName,lp_ਖਿੜਕੀ_Name,dwStyle,x,y,n_ਚੌੜਾਈ,n_ਉਚਾਈ,h_Wnd_ਮਾਪਾ,hMenu,hInstance,lpParam)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_ਖਿੜਕੀ_W(lpClassName,lp_ਖਿੜਕੀ_Name,dwStyle,x,y,n_ਚੌੜਾਈ,n_ਉਚਾਈ,h_Wnd_ਮਾਪਾ,hMenu,hInstance,lpParam) Create_ਖਿੜਕੀ_Ex_W(0L,lpClassName,lp_ਖਿੜਕੀ_Name,dwStyle,x,y,n_ਚੌੜਾਈ,n_ਉਚਾਈ,h_Wnd_ਮਾਪਾ,hMenu,hInstance,lpParam)
  WINUSERAPI WINBOOL WINAPI Is_ਖਿੜਕੀ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsMenu(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI Is_ਬੱਚਾ(HWND h_Wnd_ਮਾਪਾ,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Destroy_ਖਿੜਕੀ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Show_ਖਿੜਕੀ(HWND hWnd,ਪੂਰਨ nCmdShow);
  WINUSERAPI WINBOOL WINAPI Animate_ਖਿੜਕੀ(HWND hWnd,DWORD dw_ਸਮਾਂ,DWORD dwFlags);

#ਜੇ defined(_WINGDI_) && !defined(NOGDI)
  WINUSERAPI WINBOOL WINAPI Update_Layered_ਖਿੜਕੀ(HWND hWnd,HDC hdcDst,ਬਿੰਦੂ_3 *pptDst,ਮਾਪ_2 *psize,HDC hdcSrc,ਬਿੰਦੂ_3 *pptSrc,COLORREF cr_ਕੁੰਜੀ,BLENDFUNCTION *pblend,DWORD dwFlags);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_UPDATELAYEREDWINDOWINFO {
    DWORD cb_ਮਾਪ;
    HDC hdcDst;
    ਬਿੰਦੂ_3 CONST *pptDst;
    ਮਾਪ_2 CONST *psize;
    HDC hdcSrc;
    ਬਿੰਦੂ_3 CONST *pptSrc;
    COLORREF cr_ਕੁੰਜੀ;
    BLENDFUNCTION CONST *pblend;
    DWORD dwFlags;
    RECT CONST *prcDirty;
  } UPDATELAYEREDWINDOWINFO,*PUPDATELAYEREDWINDOWINFO;

  WINUSERAPI WINBOOL WINAPI Update_Layered_ਖਿੜਕੀ_ਅਸਿੱਧਾ(HWND hWnd,UPDATELAYEREDWINDOWINFO CONST *pULWInfo);
  WINUSERAPI WINBOOL WINAPI Get_Layered_ਖਿੜਕੀ_ਗੁਣ(HWND hwnd,COLORREF *pcr_ਕੁੰਜੀ,BYTE *pbAlpha,DWORD *pdwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PW_CLIENTONLY 0x00000001

  WINUSERAPI WINBOOL WINAPI Print_ਖਿੜਕੀ(HWND hwnd,HDC hdcBlt,UINT nFlags);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Layered_ਖਿੜਕੀ_ਗੁਣ(HWND hwnd,COLORREF cr_ਕੁੰਜੀ,BYTE bAlpha,DWORD dwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LWA_COLORKEY 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LWA_ALPHA 0x00000002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULW_COLORKEY 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULW_ALPHA 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULW_OPAQUE 0x00000004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ULW_EX_NORESIZE 0x00000008

  WINUSERAPI WINBOOL WINAPI Show_ਖਿੜਕੀ_Async(HWND hWnd,ਪੂਰਨ nCmdShow);
  WINUSERAPI WINBOOL WINAPI Flash_ਖਿੜਕੀ(HWND hWnd,WINBOOL bInvert);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    UINT cb_ਮਾਪ;
    HWND hwnd;
    DWORD dwFlags;
    UINT u_ਗਿਣਤੀ;
    DWORD dwTimeout;
  } FLASHWINFO,*PFLASHWINFO;

  WINUSERAPI WINBOOL WINAPI Flash_ਖਿੜਕੀ_Ex(PFLASHWINFO pfwi);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLASHW_STOP 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLASHW_CAPTION 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLASHW_TRAY 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLASHW_TIMER 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLASHW_TIMERNOFG 0x0000000C

  WINUSERAPI WINBOOL WINAPI ShowOwnedPopups(HWND hWnd,WINBOOL fShow);
  WINUSERAPI WINBOOL WINAPI OpenIcon(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Close_ਖਿੜਕੀ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Move_ਖਿੜਕੀ(HWND hWnd,ਪੂਰਨ X,ਪੂਰਨ Y,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ,WINBOOL bRepaint);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Pos(HWND hWnd,HWND h_Wnd_ਪਾਓ_After,ਪੂਰਨ X,ਪੂਰਨ Y,ਪੂਰਨ cx,ਪੂਰਨ cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI Get_ਖਿੜਕੀ_Placement(HWND hWnd,WINDOWPLACEMENT *lpwndpl);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Placement(HWND hWnd,CONST WINDOWPLACEMENT *lpwndpl);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NODEFERWINDOWPOS
  WINUSERAPI HDWP WINAPI Begin_Defer_ਖਿੜਕੀ_Pos(ਪੂਰਨ n_ਅੰਕ_Windows);
  WINUSERAPI HDWP WINAPI Defer_ਖਿੜਕੀ_Pos(HDWP hWinPosInfo,HWND hWnd,HWND h_Wnd_ਪਾਓ_After,ਪੂਰਨ x,ਪੂਰਨ y,ਪੂਰਨ cx,ਪੂਰਨ cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI ਸਿਰਾ_Defer_ਖਿੜਕੀ_Pos(HDWP hWinPosInfo);
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI Is_ਖਿੜਕੀ_Visible(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsIconic(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AnyPopup(VOID);
  WINUSERAPI WINBOOL WINAPI Bring_ਖਿੜਕੀ_ਮੰਜ਼ਿਲ_ਸਿਖਰ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsZoomed(HWND hWnd);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_NOSIZE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_NOMOVE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_NOZORDER 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_NOREDRAW 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_NOACTIVATE 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_FRAMECHANGED 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_SHOWWINDOW 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_HIDEWINDOW 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_NOCOPYBITS 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_NOOWNERZORDER 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_NOSENDCHANGING 0x0400

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_DRAWFRAME SWP_FRAMECHANGED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_NOREPOSITION SWP_NOOWNERZORDER
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_DEFERERASE 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SWP_ASYNCWINDOWPOS 0x4000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HWND_ਸਿਖਰ ((HWND)0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HWND_BOTTOM ((HWND)1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HWND_TOPMOST ((HWND)-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HWND_NOTOPMOST ((HWND)-2)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOCTLMGR

#ਅਨ੍ਤਰ੍ਭਾਵ <pshpack2.h>

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    DWORD style;
    DWORD dwExtendedStyle;
    ਸ਼ਬਦ_3 cdit;
    ਛੋਟਾ x;
    ਛੋਟਾ y;
    ਛੋਟਾ cx;
    ਛੋਟਾ cy;
  } DLGTEMPLATE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DLGTEMPLATE *LPDLGTEMPLATEA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DLGTEMPLATE *LPDLGTEMPLATEW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDLGTEMPLATEW LPDLGTEMPLATE;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDLGTEMPLATEA LPDLGTEMPLATE;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    DWORD style;
    DWORD dwExtendedStyle;
    ਛੋਟਾ x;
    ਛੋਟਾ y;
    ਛੋਟਾ cx;
    ਛੋਟਾ cy;
    ਸ਼ਬਦ_3 id;
  } DLGITEMTEMPLATE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#ਜੇ_ਅੰਤ

#ਅਨ੍ਤਰ੍ਭਾਵ <poppack.h>

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDialogParam CreateDialogParamW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Dialog_ਅਸਿੱਧਾ_Param Create_Dialog_ਅਸਿੱਧਾ_Param_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDialog CreateDialogW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Dialog_ਅਸਿੱਧਾ Create_Dialog_ਅਸਿੱਧਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DialogBoxParam DialogBoxParamW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dialog_Box_ਅਸਿੱਧਾ_Param Dialog_Box_ਅਸਿੱਧਾ_Param_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DialogBox DialogBoxW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dialog_Box_ਅਸਿੱਧਾ Dialog_Box_ਅਸਿੱਧਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Dlg_ਵਸਤੂ_ਪਾਠ ਸੈੱਟ_Dlg_ਵਸਤੂ_ਪਾਠ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Dlg_ਵਸਤੂ_ਪਾਠ Get_Dlg_ਵਸਤੂ_ਪਾਠ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_Dlg_ਵਸਤੂ_ਸੁਨੇਹਾ Send_Dlg_ਵਸਤੂ_ਸੁਨੇਹਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DefDlgProc DefDlgProcW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDialogParam CreateDialogParamA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Dialog_ਅਸਿੱਧਾ_Param Create_Dialog_ਅਸਿੱਧਾ_Param_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDialog CreateDialogA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Dialog_ਅਸਿੱਧਾ Create_Dialog_ਅਸਿੱਧਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DialogBoxParam DialogBoxParamA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dialog_Box_ਅਸਿੱਧਾ_Param Dialog_Box_ਅਸਿੱਧਾ_Param_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DialogBox DialogBoxA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dialog_Box_ਅਸਿੱਧਾ Dialog_Box_ਅਸਿੱਧਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Dlg_ਵਸਤੂ_ਪਾਠ ਸੈੱਟ_Dlg_ਵਸਤੂ_ਪਾਠ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Dlg_ਵਸਤੂ_ਪਾਠ Get_Dlg_ਵਸਤੂ_ਪਾਠ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Send_Dlg_ਵਸਤੂ_ਸੁਨੇਹਾ Send_Dlg_ਵਸਤੂ_ਸੁਨੇਹਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DefDlgProc DefDlgProcA
#ਜੇ_ਅੰਤ

  WINUSERAPI HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_ਮਾਪਾ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_ਮਾਪਾ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_ਅਸਿੱਧਾ_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND h_Wnd_ਮਾਪਾ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_ਅਸਿੱਧਾ_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND h_Wnd_ਮਾਪਾ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDialogA(hInstance,lpName,h_Wnd_ਮਾਪਾ,lpDialogFunc) CreateDialogParamA(hInstance,lpName,h_Wnd_ਮਾਪਾ,lpDialogFunc,0L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDialogW(hInstance,lpName,h_Wnd_ਮਾਪਾ,lpDialogFunc) CreateDialogParamW(hInstance,lpName,h_Wnd_ਮਾਪਾ,lpDialogFunc,0L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Dialog_ਅਸਿੱਧਾ_A(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc) Create_Dialog_ਅਸਿੱਧਾ_Param_A(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc,0L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Dialog_ਅਸਿੱਧਾ_W(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc) Create_Dialog_ਅਸਿੱਧਾ_Param_W(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc,0L)
  WINUSERAPI INT_PTR WINAPI DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_ਮਾਪਾ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_ਮਾਪਾ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_ਅਸਿੱਧਾ_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND h_Wnd_ਮਾਪਾ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_ਅਸਿੱਧਾ_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND h_Wnd_ਮਾਪਾ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DialogBoxA(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc,0L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DialogBoxW(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc,0L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dialog_Box_ਅਸਿੱਧਾ_A(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc) Dialog_Box_ਅਸਿੱਧਾ_Param_A(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc,0L)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Dialog_Box_ਅਸਿੱਧਾ_W(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc) Dialog_Box_ਅਸਿੱਧਾ_Param_W(hInstance,lpTemplate,h_Wnd_ਮਾਪਾ,lpDialogFunc,0L)
  WINUSERAPI WINBOOL WINAPI ਸਿਰਾ_Dialog(HWND hDlg,INT_PTR n_ਨਤੀਜਾ);
  WINUSERAPI HWND WINAPI Get_Dlg_ਵਸਤੂ(HWND hDlg,ਪੂਰਨ n_IDDlg_ਵਸਤੂ);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Dlg_ਵਸਤੂ_Int(HWND hDlg,ਪੂਰਨ n_IDDlg_ਵਸਤੂ,UINT u_ਮੁੱਲ,WINBOOL bSigned);
  WINUSERAPI UINT WINAPI Get_Dlg_ਵਸਤੂ_Int(HWND hDlg,ਪੂਰਨ n_IDDlg_ਵਸਤੂ,WINBOOL *lpTranslated,WINBOOL bSigned);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Dlg_ਵਸਤੂ_ਪਾਠ_A(HWND hDlg,ਪੂਰਨ n_IDDlg_ਵਸਤੂ,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Dlg_ਵਸਤੂ_ਪਾਠ_W(HWND hDlg,ਪੂਰਨ n_IDDlg_ਵਸਤੂ,LPCWSTR lpString);
  WINUSERAPI UINT WINAPI Get_Dlg_ਵਸਤੂ_ਪਾਠ_A(HWND hDlg,ਪੂਰਨ n_IDDlg_ਵਸਤੂ,LPSTR lpString,ਪੂਰਨ cchMax);
  WINUSERAPI UINT WINAPI Get_Dlg_ਵਸਤੂ_ਪਾਠ_W(HWND hDlg,ਪੂਰਨ n_IDDlg_ਵਸਤੂ,LPWSTR lpString,ਪੂਰਨ cchMax);
  WINUSERAPI WINBOOL WINAPI CheckDlgButton(HWND hDlg,ਪੂਰਨ nIDButton,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI CheckRadioButton(HWND hDlg,ਪੂਰਨ nIDFirstButton,ਪੂਰਨ nIDLastButton,ਪੂਰਨ nIDCheckButton);
  WINUSERAPI UINT WINAPI IsDlgButtonChecked(HWND hDlg,ਪੂਰਨ nIDButton);
  WINUSERAPI LRESULT WINAPI Send_Dlg_ਵਸਤੂ_ਸੁਨੇਹਾ_A(HWND hDlg,ਪੂਰਨ n_IDDlg_ਵਸਤੂ,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_Dlg_ਵਸਤੂ_ਸੁਨੇਹਾ_W(HWND hDlg,ਪੂਰਨ n_IDDlg_ਵਸਤੂ,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI HWND WINAPI Get_ਅਗਲਾ_Dlg_ਸਮੂਹ_ਵਸਤੂ(HWND hDlg,HWND hCtl,WINBOOL b_ਪਿਛਲਾ);
  WINUSERAPI HWND WINAPI Get_ਅਗਲਾ_Dlg_Tab_ਵਸਤੂ(HWND hDlg,HWND hCtl,WINBOOL b_ਪਿਛਲਾ);
  WINUSERAPI ਪੂਰਨ WINAPI GetDlgCtrlID(HWND hWnd);
  WINUSERAPI ਲੰਮਾ WINAPI Get_Dialog_ਅਧਾਰ_Units(VOID);
  WINUSERAPI LRESULT WINAPI DefDlgProcA(HWND hDlg,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefDlgProcW(HWND hDlg,UINT ਸੁਨੇਹਾ_5,WPARAM wParam,LPARAM lParam);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGWINDOWEXTRA 30
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMSG

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Call_ਸੁਨੇਹਾ_Filter Call_ਸੁਨੇਹਾ_Filter_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Call_ਸੁਨੇਹਾ_Filter Call_ਸੁਨੇਹਾ_Filter_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI Call_ਸੁਨੇਹਾ_Filter_A(LPMSG lp_ਸੁਨੇਹਾ_2,ਪੂਰਨ n_ਕੋਡ);
  WINUSERAPI WINBOOL WINAPI Call_ਸੁਨੇਹਾ_Filter_W(LPMSG lp_ਸੁਨੇਹਾ_2,ਪੂਰਨ n_ਕੋਡ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOCLIPBOARD

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Clipboard_Format ਰਜਿਸਟਰ_Clipboard_Format_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClipboardFormatName GetClipboardFormatNameW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਰਜਿਸਟਰ_Clipboard_Format ਰਜਿਸਟਰ_Clipboard_Format_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClipboardFormatName GetClipboardFormatNameA
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI OpenClipboard(HWND hWndNewOwner);
  WINUSERAPI WINBOOL WINAPI CloseClipboard(VOID);
  WINUSERAPI DWORD WINAPI Get_Clipboard_Sequence_ਸੰਖਿਆ(VOID);
  WINUSERAPI HWND WINAPI GetClipboardOwner(VOID);
  WINUSERAPI HWND WINAPI ਸੈੱਟ_Clipboard_Viewer(HWND hWndNewViewer);
  WINUSERAPI HWND WINAPI GetClipboardViewer(VOID);
  WINUSERAPI WINBOOL WINAPI ChangeClipboardChain(HWND hWndRemove,HWND h_Wnd_New_ਅਗਲਾ);
  WINUSERAPI HANDLE WINAPI ਸੈੱਟ_Clipboard_ਅੰਕੜੇ(UINT uFormat,HANDLE hMem);
  WINUSERAPI HANDLE WINAPI Get_Clipboard_ਅੰਕੜੇ(UINT uFormat);
  WINUSERAPI UINT WINAPI ਰਜਿਸਟਰ_Clipboard_Format_A(LPCSTR lpszFormat);
  WINUSERAPI UINT WINAPI ਰਜਿਸਟਰ_Clipboard_Format_W(LPCWSTR lpszFormat);
  WINUSERAPI ਪੂਰਨ WINAPI ਗਿਣਤੀ_Clipboard_Formats(VOID);
  WINUSERAPI UINT WINAPI EnumClipboardFormats(UINT format);
  WINUSERAPI ਪੂਰਨ WINAPI GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,ਪੂਰਨ cch_Max_ਗਿਣਤੀ);
  WINUSERAPI ਪੂਰਨ WINAPI GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,ਪੂਰਨ cch_Max_ਗਿਣਤੀ);
  WINUSERAPI WINBOOL WINAPI ਖਾਲੀ_ਥਾਵਾਂ_Clipboard(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Clipboard_Format_ਉਪਲਬਧ(UINT format);
  WINUSERAPI ਪੂਰਨ WINAPI Get_ਤਰਜੀਹ_Clipboard_Format(UINT *pa_Format_ਤਰਜੀਹ_List,ਪੂਰਨ cFormats);
  WINUSERAPI HWND WINAPI Get_Open_Clipboard_ਖਿੜਕੀ(VOID);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਮੰਜ਼ਿਲ_Oem Char_ਮੰਜ਼ਿਲ_Oem_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Oem_ਮੰਜ਼ਿਲ_Char Oem_ਮੰਜ਼ਿਲ_Char_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਮੰਜ਼ਿਲ_Oem_Buff Char_ਮੰਜ਼ਿਲ_Oem_Buff_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Oem_ਮੰਜ਼ਿਲ_Char_Buff Oem_ਮੰਜ਼ਿਲ_Char_Buff_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਉੱਤਲਾ Char_ਉੱਤਲਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਉੱਤਲਾ_Buff Char_ਉੱਤਲਾ_Buff_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਹੇਠਲਾ Char_ਹੇਠਲਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਹੇਠਲਾ_Buff Char_ਹੇਠਲਾ_Buff_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਅਗਲਾ Char_ਅਗਲਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CharPrev CharPrevW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਮੰਜ਼ਿਲ_Oem Char_ਮੰਜ਼ਿਲ_Oem_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Oem_ਮੰਜ਼ਿਲ_Char Oem_ਮੰਜ਼ਿਲ_Char_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਮੰਜ਼ਿਲ_Oem_Buff Char_ਮੰਜ਼ਿਲ_Oem_Buff_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Oem_ਮੰਜ਼ਿਲ_Char_Buff Oem_ਮੰਜ਼ਿਲ_Char_Buff_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਉੱਤਲਾ Char_ਉੱਤਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਉੱਤਲਾ_Buff Char_ਉੱਤਲਾ_Buff_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਹੇਠਲਾ Char_ਹੇਠਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਹੇਠਲਾ_Buff Char_ਹੇਠਲਾ_Buff_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Char_ਅਗਲਾ Char_ਅਗਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CharPrev CharPrevA
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI Char_ਮੰਜ਼ਿਲ_Oem_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_ਮੰਜ਼ਿਲ_Oem_W(LPCWSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_ਮੰਜ਼ਿਲ_Char_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_ਮੰਜ਼ਿਲ_Char_W(LPCSTR lpszSrc,LPWSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_ਮੰਜ਼ਿਲ_Oem_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_ਲੰਮਾਈ);
  WINUSERAPI WINBOOL WINAPI Char_ਮੰਜ਼ਿਲ_Oem_Buff_W(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_ਲੰਮਾਈ);
  WINUSERAPI WINBOOL WINAPI Oem_ਮੰਜ਼ਿਲ_Char_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_ਲੰਮਾਈ);
  WINUSERAPI WINBOOL WINAPI Oem_ਮੰਜ਼ਿਲ_Char_Buff_W(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cch_Dst_ਲੰਮਾਈ);
  WINUSERAPI LPSTR WINAPI Char_ਉੱਤਲਾ_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ਉੱਤਲਾ_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_ਉੱਤਲਾ_Buff_A(LPSTR lpsz,DWORD cch_ਲੰਮਾਈ);
  WINUSERAPI DWORD WINAPI Char_ਉੱਤਲਾ_Buff_W(LPWSTR lpsz,DWORD cch_ਲੰਮਾਈ);
  WINUSERAPI LPSTR WINAPI Char_ਹੇਠਲਾ_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ਹੇਠਲਾ_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_ਹੇਠਲਾ_Buff_A(LPSTR lpsz,DWORD cch_ਲੰਮਾਈ);
  WINUSERAPI DWORD WINAPI Char_ਹੇਠਲਾ_Buff_W(LPWSTR lpsz,DWORD cch_ਲੰਮਾਈ);
  WINUSERAPI LPSTR WINAPI Char_ਅਗਲਾ_A(LPCSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ਅਗਲਾ_W(LPCWSTR lpsz);
  WINUSERAPI LPSTR WINAPI CharPrevA(LPCSTR lpsz_ਸ਼ੁਰੂ,LPCSTR lpszCurrent);
  WINUSERAPI LPWSTR WINAPI CharPrevW(LPCWSTR lpsz_ਸ਼ੁਰੂ,LPCWSTR lpszCurrent);
  WINUSERAPI LPSTR WINAPI Char_ਅਗਲਾ_Ex_A(ਸ਼ਬਦ_3 ਕੋਡ_ਪੰਨਾ,LPCSTR lpCurrentChar,DWORD dwFlags);
  WINUSERAPI LPSTR WINAPI CharPrevExA(ਸ਼ਬਦ_3 ਕੋਡ_ਪੰਨਾ,LPCSTR lp_ਸ਼ੁਰੂ,LPCSTR lpCurrentChar,DWORD dwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ansi_ਮੰਜ਼ਿਲ_Oem Char_ਮੰਜ਼ਿਲ_Oem_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Oem_ਮੰਜ਼ਿਲ_Ansi Oem_ਮੰਜ਼ਿਲ_Char_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ansi_ਮੰਜ਼ਿਲ_Oem_Buff Char_ਮੰਜ਼ਿਲ_Oem_Buff_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Oem_ਮੰਜ਼ਿਲ_Ansi_Buff Oem_ਮੰਜ਼ਿਲ_Char_Buff_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ansi_ਉੱਤਲਾ Char_ਉੱਤਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ansi_ਉੱਤਲਾ_Buff Char_ਉੱਤਲਾ_Buff_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ansi_ਹੇਠਲਾ Char_ਹੇਠਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ansi_ਹੇਠਲਾ_Buff Char_ਹੇਠਲਾ_Buff_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ansi_ਅਗਲਾ Char_ਅਗਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AnsiPrev CharPrevA

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOLANGUAGE

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsCharAlpha IsCharAlphaW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsCharAlphaNumeric IsCharAlphaNumericW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Is_Char_ਉੱਤਲਾ Is_Char_ਉੱਤਲਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Is_Char_ਹੇਠਲਾ Is_Char_ਹੇਠਲਾ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsCharAlpha IsCharAlphaA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IsCharAlphaNumeric IsCharAlphaNumericA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Is_Char_ਉੱਤਲਾ Is_Char_ਉੱਤਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Is_Char_ਹੇਠਲਾ Is_Char_ਹੇਠਲਾ_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI IsCharAlphaA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ਉੱਤਲਾ_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ਉੱਤਲਾ_W(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ਹੇਠਲਾ_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ਹੇਠਲਾ_W(WCHAR ch);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਕੁੰਜੀ_Name_ਪਾਠ Get_ਕੁੰਜੀ_Name_ਪਾਠ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Vk_ਕੁੰਜੀ_ਜਾਂਚ Vk_ਕੁੰਜੀ_ਜਾਂਚ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Vk_ਕੁੰਜੀ_ਜਾਂਚ_Ex Vk_ਕੁੰਜੀ_ਜਾਂਚ_Ex_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਕੁੰਜੀ_Name_ਪਾਠ Get_ਕੁੰਜੀ_Name_ਪਾਠ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Vk_ਕੁੰਜੀ_ਜਾਂਚ Vk_ਕੁੰਜੀ_ਜਾਂਚ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Vk_ਕੁੰਜੀ_ਜਾਂਚ_Ex Vk_ਕੁੰਜੀ_ਜਾਂਚ_Ex_A
#ਜੇ_ਅੰਤ

  WINUSERAPI HWND WINAPI ਸੈੱਟ_Focus(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_ਸਰਗਰਮ_ਖਿੜਕੀ(VOID);
  WINUSERAPI HWND WINAPI GetFocus(VOID);
  WINUSERAPI UINT WINAPI Get_KBCode_ਪੰਨਾ(VOID);
  WINUSERAPI SHORT WINAPI Get_ਕੁੰਜੀ_State(ਪੂਰਨ n_Virt_ਕੁੰਜੀ);
  WINUSERAPI SHORT WINAPI Get_Async_ਕੁੰਜੀ_State(ਪੂਰਨ v_ਕੁੰਜੀ);
  WINUSERAPI WINBOOL WINAPI GetKeyboardState(PBYTE lp_ਕੁੰਜੀ_State);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Keyboard_State(LPBYTE lp_ਕੁੰਜੀ_State);
  WINUSERAPI ਪੂਰਨ WINAPI Get_ਕੁੰਜੀ_Name_ਪਾਠ_A(LONG lParam,LPSTR lpString,ਪੂਰਨ cch_ਮਾਪ);
  WINUSERAPI ਪੂਰਨ WINAPI Get_ਕੁੰਜੀ_Name_ਪਾਠ_W(LONG lParam,LPWSTR lpString,ਪੂਰਨ cch_ਮਾਪ);
  WINUSERAPI ਪੂਰਨ WINAPI GetKeyboardType(ਪੂਰਨ nTypeFlag);
  WINUSERAPI ਪੂਰਨ WINAPI ਮੰਜ਼ਿਲ_Ascii(UINT u_Virt_ਕੁੰਜੀ,UINT u_ਜਾਂਚ_ਕੋਡ,CONST BYTE *lp_ਕੁੰਜੀ_State,LPWORD lpChar,UINT uFlags);
  WINUSERAPI ਪੂਰਨ WINAPI ਮੰਜ਼ਿਲ_Ascii_Ex(UINT u_Virt_ਕੁੰਜੀ,UINT u_ਜਾਂਚ_ਕੋਡ,CONST BYTE *lp_ਕੁੰਜੀ_State,LPWORD lpChar,UINT uFlags,HKL dwhkl);
  WINUSERAPI ਪੂਰਨ WINAPI ਮੰਜ਼ਿਲ_Unicode(UINT w_Virt_ਕੁੰਜੀ,UINT w_ਜਾਂਚ_ਕੋਡ,CONST BYTE *lp_ਕੁੰਜੀ_State,LPWSTR pwszBuff,ਪੂਰਨ cchBuff,UINT wFlags);
  WINUSERAPI DWORD WINAPI Oem_ਕੁੰਜੀ_ਜਾਂਚ(ਸ਼ਬਦ_3 wOemChar);
  WINUSERAPI SHORT WINAPI Vk_ਕੁੰਜੀ_ਜਾਂਚ_A(CHAR ch);
  WINUSERAPI SHORT WINAPI Vk_ਕੁੰਜੀ_ਜਾਂਚ_W(WCHAR ch);
  WINUSERAPI SHORT WINAPI Vk_ਕੁੰਜੀ_ਜਾਂਚ_Ex_A(CHAR ch,HKL dwhkl);
  WINUSERAPI SHORT WINAPI Vk_ਕੁੰਜੀ_ਜਾਂਚ_Ex_W(WCHAR ch,HKL dwhkl);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KEYEVENTF_EXTENDEDKEY 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KEYEVENTF_KEYUP 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KEYEVENTF_UNICODE 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KEYEVENTF_SCANCODE 0x0008

  WINUSERAPI VOID WINAPI keybd_event(BYTE bVk,BYTE b_ਜਾਂਚ,DWORD dwFlags,ULONG_PTR dwExtraInfo);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_MOVE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_LEFTDOWN 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_LEFTUP 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_RIGHTDOWN 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_RIGHTUP 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_MIDDLEDOWN 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_MIDDLEUP 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_XDOWN 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_XUP 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_WHEEL 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_VIRTUALDESK 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSEEVENTF_ABSOLUTE 0x8000

  WINUSERAPI VOID WINAPI mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dw_ਅੰਕੜੇ,ULONG_PTR dwExtraInfo);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouse_ਅੰਕੜੇ;
    DWORD dwFlags;
    DWORD ਸਮਾਂ;
    ULONG_PTR dwExtraInfo;
  } MOUSEINPUT,*PMOUSEINPUT,*LPMOUSEINPUT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_KEYBDINPUT {
    ਸ਼ਬਦ_3 wVk;
    ਸ਼ਬਦ_3 w_ਜਾਂਚ;
    DWORD dwFlags;
    DWORD ਸਮਾਂ;
    ULONG_PTR dwExtraInfo;
  } KEYBDINPUT,*PKEYBDINPUT,*LPKEYBDINPUT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HARDWAREINPUT {
    DWORD u_ਸੁਨੇਹਾ;
    ਸ਼ਬਦ_3 wParamL;
    ਸ਼ਬਦ_3 wParamH;
  } HARDWAREINPUT,*PHARDWAREINPUT,*LPHARDWAREINPUT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਵੇਸ਼_MOUSE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਵੇਸ਼_KEYBOARD 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿਵੇਸ਼_HARDWARE 2

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ਨਿਵੇਸ਼ {
    DWORD type;
    ਸੰਘ {
      MOUSEINPUT mi;
      KEYBDINPUT ki;
      HARDWAREINPUT hi;
    };
  } ਨਿਵੇਸ਼_2,*PINPUT,*LPINPUT;

  WINUSERAPI UINT WINAPI Send_ਨਿਵੇਸ਼(UINT cInputs,LPINPUT pInputs,ਪੂਰਨ cb_ਮਾਪ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LASTINPUTINFO {
    UINT cb_ਮਾਪ;
    DWORD dw_ਸਮਾਂ;
  } LASTINPUTINFO,*PLASTINPUTINFO;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Map_Virtual_ਕੁੰਜੀ Map_Virtual_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Map_Virtual_ਕੁੰਜੀ_Ex Map_Virtual_ਕੁੰਜੀ_Ex_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Map_Virtual_ਕੁੰਜੀ Map_Virtual_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Map_Virtual_ਕੁੰਜੀ_Ex Map_Virtual_ਕੁੰਜੀ_Ex_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI Get_ਆਖਰੀ_ਨਿਵੇਸ਼_Info(PLASTINPUTINFO plii);
  WINUSERAPI UINT WINAPI Map_Virtual_ਕੁੰਜੀ_A(UINT u_ਕੋਡ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_ਕੁੰਜੀ_W(UINT u_ਕੋਡ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_ਕੁੰਜੀ_Ex_A(UINT u_ਕੋਡ,UINT uMapType,HKL dwhkl);
  WINUSERAPI UINT WINAPI Map_Virtual_ਕੁੰਜੀ_Ex_W(UINT u_ਕੋਡ,UINT uMapType,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI Get_ਨਿਵੇਸ਼_State(VOID);
  WINUSERAPI DWORD WINAPI Get_ਕਤਾਰ_ਸਥਿਤੀ(UINT flags);
  WINUSERAPI HWND WINAPI GetCapture(VOID);
  WINUSERAPI HWND WINAPI ਸੈੱਟ_Capture(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ReleaseCapture(VOID);
  WINUSERAPI DWORD WINAPI ਸੁਨੇਹਾ_Wait_For_ਗੁਣਜ_Objects(DWORD n_ਗਿਣਤੀ,CONST HANDLE *pHandles,WINBOOL fWaitAll,DWORD dwMilliseconds,DWORD dw_Wake_ਨਕਾਬ);
  WINUSERAPI DWORD WINAPI ਸੁਨੇਹਾ_Wait_For_ਗੁਣਜ_Objects_Ex(DWORD n_ਗਿਣਤੀ,CONST HANDLE *pHandles,DWORD dwMilliseconds,DWORD dw_Wake_ਨਕਾਬ,DWORD dwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MWMO_WAITALL 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MWMO_ALERTABLE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MWMO_INPUTAVAILABLE 0x0004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_ਕੁੰਜੀ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_MOUSEMOVE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_MOUSEBUTTON 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_POSTMESSAGE 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_TIMER 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_PAINT 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_SENDMESSAGE 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_HOTKEY 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_ALLPOSTMESSAGE 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_RAWINPUT 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_ਨਿਵੇਸ਼ (QS_MOUSE | QS_ਕੁੰਜੀ | QS_RAWINPUT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_ALLEVENTS (QS_ਨਿਵੇਸ਼ | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QS_ALLINPUT (QS_ਨਿਵੇਸ਼ | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USER_TIMER_ਵੱਧ_ਤੋਂ_ਵੱਧ 0x7FFFFFFF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USER_TIMER_MINIMUM 0x0000000A

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Accelerators ਲੱਦੋ_Accelerators_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Accelerator_ਸਾਰਣੀ Create_Accelerator_ਸਾਰਣੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Copy_Accelerator_ਸਾਰਣੀ Copy_Accelerator_ਸਾਰਣੀ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Accelerators ਲੱਦੋ_Accelerators_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Accelerator_ਸਾਰਣੀ Create_Accelerator_ਸਾਰਣੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Copy_Accelerator_ਸਾਰਣੀ Copy_Accelerator_ਸਾਰਣੀ_A
#ਜੇ_ਅੰਤ

  WINUSERAPI UINT_PTR WINAPI ਸੈੱਟ_Timer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
  WINUSERAPI WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);
  WINUSERAPI WINBOOL WINAPI Is_ਖਿੜਕੀ_Unicode(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Enable_ਖਿੜਕੀ(HWND hWnd,WINBOOL bEnable);
  WINUSERAPI WINBOOL WINAPI Is_ਖਿੜਕੀ_Enabled(HWND hWnd);
  WINUSERAPI HACCEL WINAPI ਲੱਦੋ_Accelerators_A(HINSTANCE hInstance,LPCSTR lp_ਸਾਰਣੀ_Name);
  WINUSERAPI HACCEL WINAPI ਲੱਦੋ_Accelerators_W(HINSTANCE hInstance,LPCWSTR lp_ਸਾਰਣੀ_Name);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_ਸਾਰਣੀ_A(LPACCEL paccel,ਪੂਰਨ cAccel);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_ਸਾਰਣੀ_W(LPACCEL paccel,ਪੂਰਨ cAccel);
  WINUSERAPI WINBOOL WINAPI Destroy_Accelerator_ਸਾਰਣੀ(HACCEL hAccel);
  WINUSERAPI ਪੂਰਨ WINAPI Copy_Accelerator_ਸਾਰਣੀ_A(HACCEL hAccelSrc,LPACCEL lpAccelDst,ਪੂਰਨ cAccelEntries);
  WINUSERAPI ਪੂਰਨ WINAPI Copy_Accelerator_ਸਾਰਣੀ_W(HACCEL hAccelSrc,LPACCEL lpAccelDst,ਪੂਰਨ cAccelEntries);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMSG

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TranslateAccelerator TranslateAcceleratorW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TranslateAccelerator TranslateAcceleratorA
#ਜੇ_ਅੰਤ

  WINUSERAPI ਪੂਰਨ WINAPI TranslateAcceleratorA(HWND hWnd,HACCEL h_Acc_ਸਾਰਣੀ,LPMSG lp_ਸੁਨੇਹਾ_2);
  WINUSERAPI ਪੂਰਨ WINAPI TranslateAcceleratorW(HWND hWnd,HACCEL h_Acc_ਸਾਰਣੀ,LPMSG lp_ਸੁਨੇਹਾ_2);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOSYSMETRICS

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXSCREEN 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYSCREEN 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXVSCROLL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYHSCROLL 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYCAPTION 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXBORDER 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYBORDER 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXDLGFRAME 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYDLGFRAME 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYVTHUMB 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXHTHUMB 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXICON 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYICON 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXCURSOR 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYCURSOR 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYMENU 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXFULLSCREEN 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYFULLSCREEN 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYKANJIWINDOW 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_MOUSEPRESENT 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYVSCROLL 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXHSCROLL 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_DEBUG 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_SWAPBUTTON 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_RESERVED1 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_RESERVED2 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_RESERVED3 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_RESERVED4 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXMIN 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYMIN 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXSIZE 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYSIZE 31
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXFRAME 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYFRAME 33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXMINTRACK 34
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYMINTRACK 35
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXDOUBLECLK 36
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYDOUBLECLK 37
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXICONSPACING 38
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYICONSPACING 39
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_MENUDROPALIGNMENT 40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_PENWINDOWS 41
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_DBCSENABLED 42
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CMOUSEBUTTONS 43

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXFIXEDFRAME SM_CXDLGFRAME
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYFIXEDFRAME SM_CYDLGFRAME
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXSIZEFRAME SM_CXFRAME
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYSIZEFRAME SM_CYFRAME

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_SECURE 44
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXEDGE 45
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYEDGE 46
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXMINSPACING 47
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYMINSPACING 48
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXSMICON 49
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYSMICON 50
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYSMCAPTION 51
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXSMSIZE 52
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYSMSIZE 53
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXMENUSIZE 54
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYMENUSIZE 55
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_ARRANGE 56
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXMINIMIZED 57
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYMINIMIZED 58
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXMAXTRACK 59
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYMAXTRACK 60
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXMAXIMIZED 61
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYMAXIMIZED 62
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_ਜਾਲ 63
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CLEANBOOT 67
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXDRAG 68
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYDRAG 69
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_SHOWSOUNDS 70
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXMENUCHECK 71
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYMENUCHECK 72
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_SLOWMACHINE 73
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_MIDEASTENABLED 74
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_MOUSEWHEELPRESENT 75
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_XVIRTUALSCREEN 76
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_YVIRTUALSCREEN 77
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXVIRTUALSCREEN 78
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYVIRTUALSCREEN 79
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CMONITORS 80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_SAMEDISPLAYFORMAT 81
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_IMMENABLED 82
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CXFOCUSBORDER 83
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CYFOCUSBORDER 84
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_TABLETPC 86
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_MEDIACENTER 87
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_STARTER 88
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_SERVERR2 89
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CMETRICS 90
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_REMOTESESSION 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_SHUTTINGDOWN 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_REMOTECONTROL 0x2001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SM_CARETBLINKINGENABLED 0x2002

  WINUSERAPI ਪੂਰਨ WINAPI GetSystemMetrics(ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMENUS

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Menu ਲੱਦੋ_Menu_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Menu_ਅਸਿੱਧਾ ਲੱਦੋ_Menu_ਅਸਿੱਧਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ChangeMenu ChangeMenuW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetMenuString GetMenuStringW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਾਓ_Menu ਪਾਓ_Menu_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AppendMenu AppendMenuW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ModifyMenu ModifyMenuW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Menu ਲੱਦੋ_Menu_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Menu_ਅਸਿੱਧਾ ਲੱਦੋ_Menu_ਅਸਿੱਧਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ChangeMenu ChangeMenuA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetMenuString GetMenuStringA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਾਓ_Menu ਪਾਓ_Menu_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AppendMenu AppendMenuA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ModifyMenu ModifyMenuA
#ਜੇ_ਅੰਤ

  WINUSERAPI HMENU WINAPI ਲੱਦੋ_Menu_A(HINSTANCE hInstance,LPCSTR lpMenuName);
  WINUSERAPI HMENU WINAPI ਲੱਦੋ_Menu_W(HINSTANCE hInstance,LPCWSTR lpMenuName);
  WINUSERAPI HMENU WINAPI ਲੱਦੋ_Menu_ਅਸਿੱਧਾ_A(CONST MENUTEMPLATEA *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI ਲੱਦੋ_Menu_ਅਸਿੱਧਾ_W(CONST MENUTEMPLATEW *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI GetMenu(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Menu(HWND hWnd,HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpsz_New_ਵਸਤੂ,UINT cmd_ਪਾਓ,UINT flags);
  WINUSERAPI WINBOOL WINAPI ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpsz_New_ਵਸਤੂ,UINT cmd_ਪਾਓ,UINT flags);
  WINUSERAPI WINBOOL WINAPI Hilite_Menu_ਵਸਤੂ(HWND hWnd,HMENU hMenu,UINT u_IDHilite_ਵਸਤੂ,UINT uHilite);
  WINUSERAPI ਪੂਰਨ WINAPI GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,ਪੂਰਨ cchMax,UINT flags);
  WINUSERAPI ਪੂਰਨ WINAPI GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,ਪੂਰਨ cchMax,UINT flags);
  WINUSERAPI UINT WINAPI GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawMenuBar(HWND hWnd);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PMB_ਸਰਗਰਮ 0x00000001

  WINUSERAPI HMENU WINAPI GetSystemMenu(HWND hWnd,WINBOOL bRevert);
  WINUSERAPI HMENU WINAPI CreateMenu(VOID);
  WINUSERAPI HMENU WINAPI CreatePopupMenu(VOID);
  WINUSERAPI WINBOOL WINAPI DestroyMenu(HMENU hMenu);
  WINUSERAPI DWORD WINAPI Check_Menu_ਵਸਤੂ(HMENU hMenu,UINT u_IDCheck_ਵਸਤੂ,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI Enable_Menu_ਵਸਤੂ(HMENU hMenu,UINT u_IDEnable_ਵਸਤੂ,UINT uEnable);
  WINUSERAPI HMENU WINAPI GetSubMenu(HMENU hMenu,ਪੂਰਨ nPos);
  WINUSERAPI UINT WINAPI Get_Menu_ਵਸਤੂ_ID(HMENU hMenu,ਪੂਰਨ nPos);
  WINUSERAPI ਪੂਰਨ WINAPI Get_Menu_ਵਸਤੂ_ਗਿਣਤੀ(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ਪਾਓ_Menu_A(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_ਵਸਤੂ,LPCSTR lp_New_ਵਸਤੂ);
  WINUSERAPI WINBOOL WINAPI ਪਾਓ_Menu_W(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_ਵਸਤੂ,LPCWSTR lp_New_ਵਸਤੂ);
  WINUSERAPI WINBOOL WINAPI AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_ਵਸਤੂ,LPCSTR lp_New_ਵਸਤੂ);
  WINUSERAPI WINBOOL WINAPI AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_ਵਸਤੂ,LPCWSTR lp_New_ਵਸਤੂ);
  WINUSERAPI WINBOOL WINAPI ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_ਵਸਤੂ,LPCSTR lp_New_ਵਸਤੂ);
  WINUSERAPI WINBOOL WINAPI ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_ਵਸਤੂ,LPCWSTR lp_New_ਵਸਤੂ);
  WINUSERAPI WINBOOL WINAPI RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Menu_ਵਸਤੂ_Bitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
  WINUSERAPI LONG WINAPI GetMenuCheckMarkDimensions(VOID);
  WINUSERAPI WINBOOL WINAPI TrackPopupMenu(HMENU hMenu,UINT uFlags,ਪੂਰਨ x,ਪੂਰਨ y,ਪੂਰਨ nReserved,HWND hWnd,CONST RECT *prcRect);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNC_IGNORE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNC_CLOSE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNC_EXECUTE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNC_SELECT 3

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_TPMPARAMS {
    UINT cb_ਮਾਪ;
    RECT rcExclude;
  } TPMPARAMS;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ TPMPARAMS *LPTPMPARAMS;

  WINUSERAPI WINBOOL WINAPI TrackPopupMenuEx(HMENU,UINT,ਪੂਰਨ,ਪੂਰਨ,HWND,LPTPMPARAMS);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNS_NOCHECK 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNS_MODELESS 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNS_DRAGDROP 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNS_AUTODISMISS 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNS_NOTIFYBYPOS 0x08000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNS_CHECKORBMP 0x04000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIM_MAXHEIGHT 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIM_BACKGROUND 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIM_HELPID 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIM_MENUDATA 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIM_STYLE 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIM_APPLYTOSUBMENUS 0x80000000

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MENUINFO {
    DWORD cb_ਮਾਪ;
    DWORD f_ਨਕਾਬ;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbr_ਪਿੱਠ;
    DWORD dwContextHelpID;
    ULONG_PTR dw_Menu_ਅੰਕੜੇ;
  } MENUINFO,*LPMENUINFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MENUINFO CONST *LPCMENUINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuInfo(HMENU,LPMENUINFO);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Menu_Info(HMENU,LPCMENUINFO);
  WINUSERAPI WINBOOL WINAPI ਸਿਰਾ_Menu(VOID);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MND_CONTINUE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MND_ENDMENU 1

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MENUGETOBJECTINFO {
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
  } MENUGETOBJECTINFO,*PMENUGETOBJECTINFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNGOF_TOPGAP 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNGOF_BOTTOMGAP 0x00000002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNGO_NOINTERFACE 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MNGO_NOERROR 0x00000001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIIM_STATE 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIIM_ID 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIIM_SUBMENU 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIIM_CHECKMARKS 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIIM_TYPE 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIIM_ਅੰਕੜੇ 0x00000020

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIIM_STRING 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIIM_BITMAP 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MIIM_FTYPE 0x00000100

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_CALLBACK ((HBITMAP) -1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_SYSTEM ((HBITMAP) 1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MENUITEMINFOA {
    UINT cb_ਮਾਪ;
    UINT f_ਨਕਾਬ;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_ਵਸਤੂ_ਅੰਕੜੇ;
    LPSTR dw_Type_ਅੰਕੜੇ;
    UINT cch;
    HBITMAP hbmp_ਵਸਤੂ;
  } MENUITEMINFOA,*LPMENUITEMINFOA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MENUITEMINFOW {
    UINT cb_ਮਾਪ;
    UINT f_ਨਕਾਬ;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_ਵਸਤੂ_ਅੰਕੜੇ;
    LPWSTR dw_Type_ਅੰਕੜੇ;
    UINT cch;
    HBITMAP hbmp_ਵਸਤੂ;
  } MENUITEMINFOW,*LPMENUITEMINFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MENUITEMINFOW MENUITEMINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMENUITEMINFOW LPMENUITEMINFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MENUITEMINFOA MENUITEMINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMENUITEMINFOA LPMENUITEMINFO;
#ਜੇ_ਅੰਤ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MENUITEMINFOA CONST *LPCMENUITEMINFOA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MENUITEMINFOW CONST *LPCMENUITEMINFOW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCMENUITEMINFOW LPCMENUITEMINFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPCMENUITEMINFOA LPCMENUITEMINFO;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਾਓ_Menu_ਵਸਤੂ ਪਾਓ_Menu_ਵਸਤੂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Menu_ਵਸਤੂ_Info Get_Menu_ਵਸਤੂ_Info_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Menu_ਵਸਤੂ_Info ਸੈੱਟ_Menu_ਵਸਤੂ_Info_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਾਓ_Menu_ਵਸਤੂ ਪਾਓ_Menu_ਵਸਤੂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Menu_ਵਸਤੂ_Info Get_Menu_ਵਸਤੂ_Info_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Menu_ਵਸਤੂ_Info ਸੈੱਟ_Menu_ਵਸਤੂ_Info_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI ਪਾਓ_Menu_ਵਸਤੂ_A(HMENU hmenu,UINT ਵਸਤੂ,WINBOOL fByPosition,LPCMENUITEMINFOA lpmi);
  WINUSERAPI WINBOOL WINAPI ਪਾਓ_Menu_ਵਸਤੂ_W(HMENU hmenu,UINT ਵਸਤੂ,WINBOOL fByPosition,LPCMENUITEMINFOW lpmi);
  WINUSERAPI WINBOOL WINAPI Get_Menu_ਵਸਤੂ_Info_A(HMENU hmenu,UINT ਵਸਤੂ,WINBOOL fByPosition,LPMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI Get_Menu_ਵਸਤੂ_Info_W(HMENU hmenu,UINT ਵਸਤੂ,WINBOOL fByPosition,LPMENUITEMINFOW lpmii);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Menu_ਵਸਤੂ_Info_A(HMENU hmenu,UINT ਵਸਤੂ,WINBOOL fByPositon,LPCMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Menu_ਵਸਤੂ_Info_W(HMENU hmenu,UINT ਵਸਤੂ,WINBOOL fByPositon,LPCMENUITEMINFOW lpmii);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMDI_USEDISABLED 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GMDI_GOINTOPOPUPS 0x0002L

  WINUSERAPI UINT WINAPI Get_Menu_Default_ਵਸਤੂ(HMENU hMenu,UINT fByPos,UINT gmdiFlags);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Menu_Default_ਵਸਤੂ(HMENU hMenu,UINT u_ਵਸਤੂ,UINT fByPos);
  WINUSERAPI WINBOOL WINAPI Get_Menu_ਵਸਤੂ_Rect(HWND hWnd,HMENU hMenu,UINT u_ਵਸਤੂ,LPRECT lprc_ਵਸਤੂ);
  WINUSERAPI ਪੂਰਨ WINAPI Menu_ਵਸਤੂ_From_ਬਿੰਦੂ(HWND hWnd,HMENU hMenu,ਬਿੰਦੂ_3 ptScreen);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_LEFTBUTTON 0x0000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_RIGHTBUTTON 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_LEFTALIGN 0x0000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_CENTERALIGN 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_RIGHTALIGN 0x0008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_TOPALIGN 0x0000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_VCENTERALIGN 0x0010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_BOTTOMALIGN 0x0020L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_HORIZONTAL 0x0000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_VERTICAL 0x0040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_NONOTIFY 0x0080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_RETURNCMD 0x0100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_RECURSE 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_HORPOSANIMATION 0x0400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_HORNEGANIMATION 0x0800L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_VERPOSANIMATION 0x1000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_VERNEGANIMATION 0x2000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_NOANIMATION 0x4000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TPM_LAYOUTRTL 0x8000L
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_DROPSTRUCT {
    HWND hwnd_ਸਰੋਤ;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dw_ਅੰਕੜੇ;
    ਬਿੰਦੂ_3 ptDrop;
    DWORD dw_Control_ਅੰਕੜੇ;
  } DROPSTRUCT,*PDROPSTRUCT,*LPDROPSTRUCT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOF_EXECUTABLE 0x8001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOF_DOCUMENT 0x8002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOF_DIRECTORY 0x8003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOF_ਗੁਣਜ 0x8004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOF_PROGMAN 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOF_SHELLDATA 0x0002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DO_DROPFILE 0x454C4946L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DO_PRINTFILE 0x544E5250L

  WINUSERAPI DWORD WINAPI DragObject(HWND hwnd_ਮਾਪਾ_2,HWND hwndFrom,UINT fmt,ULONG_PTR ਅੰਕੜੇ,HCURSOR hcur);
  WINUSERAPI WINBOOL WINAPI DragDetect(HWND hwnd,ਬਿੰਦੂ_3 pt);
  WINUSERAPI WINBOOL WINAPI DrawIcon(HDC hDC,ਪੂਰਨ X,ਪੂਰਨ Y,HICON hIcon);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NODRAWTEXT

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_ਸਿਖਰ 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_ਖੱਬਾ 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_CENTER 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_ਸੱਜਾ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_VCENTER 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_BOTTOM 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_WORDBREAK 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_SINGLELINE 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_EXPANDTABS 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_TABSTOP 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_NOCLIP 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_EXTERNALLEADING 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_CALCRECT 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_NOPREFIX 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_ਅੰਦਰੂਨੀ 0x00001000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_EDITCONTROL 0x00002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_ਰਸਤਾ_ELLIPSIS 0x00004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_ਸਿਰਾ_ELLIPSIS 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_MODIFYSTRING 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_RTLREADING 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_ਸ਼ਬਦ_ELLIPSIS 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_NOFULLWIDTHCHARBREAK 0x00080000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_HIDEPREFIX 0x00100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_PREFIXONLY 0x00200000

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_DRAWTEXTPARAMS {
    UINT cb_ਮਾਪ;
    ਪੂਰਨ i_Tab_ਲੰਮਾਈ;
    ਪੂਰਨ i_ਖੱਬਾ_Margin;
    ਪੂਰਨ i_ਸੱਜਾ_Margin;
    UINT ui_ਲੰਮਾਈ_Drawn;
  } DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Draw_ਪਾਠ Draw_ਪਾਠ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Draw_ਪਾਠ_Ex Draw_ਪਾਠ_Ex_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Draw_ਪਾਠ Draw_ਪਾਠ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Draw_ਪਾਠ_Ex Draw_ਪਾਠ_Ex_A
#ਜੇ_ਅੰਤ

  WINUSERAPI ਪੂਰਨ WINAPI Draw_ਪਾਠ_A(HDC hdc,LPCSTR lpch_ਪਾਠ,ਪੂਰਨ cch_ਪਾਠ,LPRECT lprc,UINT format);
  WINUSERAPI ਪੂਰਨ WINAPI Draw_ਪਾਠ_W(HDC hdc,LPCWSTR lpch_ਪਾਠ,ਪੂਰਨ cch_ਪਾਠ,LPRECT lprc,UINT format);
  WINUSERAPI ਪੂਰਨ WINAPI Draw_ਪਾਠ_Ex_A(HDC hdc,LPSTR lpch_ਪਾਠ,ਪੂਰਨ cch_ਪਾਠ,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
  WINUSERAPI ਪੂਰਨ WINAPI Draw_ਪਾਠ_Ex_W(HDC hdc,LPWSTR lpch_ਪਾਠ,ਪੂਰਨ cch_ਪਾਠ,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਲੇਟੀ_String ਸਲੇਟੀ_String_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DrawState DrawStateW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Tabbed_ਪਾਠ_ਬਾਹਰਲਾ Tabbed_ਪਾਠ_ਬਾਹਰਲਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Tabbed_ਪਾਠ_Extent Get_Tabbed_ਪਾਠ_Extent_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਲੇਟੀ_String ਸਲੇਟੀ_String_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DrawState DrawStateA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Tabbed_ਪਾਠ_ਬਾਹਰਲਾ Tabbed_ਪਾਠ_ਬਾਹਰਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Tabbed_ਪਾਠ_Extent Get_Tabbed_ਪਾਠ_Extent_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI ਸਲੇਟੀ_String_A(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_ਅੰਕੜੇ,ਪੂਰਨ n_ਗਿਣਤੀ,ਪੂਰਨ X,ਪੂਰਨ Y,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ);
  WINUSERAPI WINBOOL WINAPI ਸਲੇਟੀ_String_W(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_ਅੰਕੜੇ,ਪੂਰਨ n_ਗਿਣਤੀ,ਪੂਰਨ X,ਪੂਰਨ Y,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DST_COMPLEX 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DST_ਪਾਠ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DST_PREFIXTEXT 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DST_ICON 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DST_BITMAP 0x0004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DSS_ਸਾਧਾਰਨ 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DSS_UNION 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DSS_DISABLED 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DSS_MONO 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DSS_HIDEPREFIX 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DSS_PREFIXONLY 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DSS_ਸੱਜਾ 0x8000

  WINUSERAPI WINBOOL WINAPI DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_ਪਿੱਠ,LPARAM l_ਅੰਕੜੇ,WPARAM w_ਅੰਕੜੇ,ਪੂਰਨ x,ਪੂਰਨ y,ਪੂਰਨ cx,ਪੂਰਨ cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_ਪਿੱਠ,LPARAM l_ਅੰਕੜੇ,WPARAM w_ਅੰਕੜੇ,ਪੂਰਨ x,ਪੂਰਨ y,ਪੂਰਨ cx,ਪੂਰਨ cy,UINT uFlags);
  WINUSERAPI LONG WINAPI Tabbed_ਪਾਠ_ਬਾਹਰਲਾ_A(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPCSTR lpString,ਪੂਰਨ ch_ਗਿਣਤੀ,ਪੂਰਨ nTabPositions,CONST INT *lpnTabStopPositions,ਪੂਰਨ nTabOrigin);
  WINUSERAPI LONG WINAPI Tabbed_ਪਾਠ_ਬਾਹਰਲਾ_W(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPCWSTR lpString,ਪੂਰਨ ch_ਗਿਣਤੀ,ਪੂਰਨ nTabPositions,CONST INT *lpnTabStopPositions,ਪੂਰਨ nTabOrigin);
  WINUSERAPI DWORD WINAPI Get_Tabbed_ਪਾਠ_Extent_A(HDC hdc,LPCSTR lpString,ਪੂਰਨ ch_ਗਿਣਤੀ,ਪੂਰਨ nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI DWORD WINAPI Get_Tabbed_ਪਾਠ_Extent_W(HDC hdc,LPCWSTR lpString,ਪੂਰਨ ch_ਗਿਣਤੀ,ਪੂਰਨ nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI WINBOOL WINAPI Update_ਖਿੜਕੀ(HWND hWnd);
  WINUSERAPI HWND WINAPI ਸੈੱਟ_ਸਰਗਰਮ_ਖਿੜਕੀ(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_Foreground_ਖਿੜਕੀ(VOID);
  WINUSERAPI WINBOOL WINAPI PaintDesktop(HDC hdc);
  WINUSERAPI VOID WINAPI Switch_ਮੰਜ਼ਿਲ_This_ਖਿੜਕੀ(HWND hwnd,WINBOOL fUnknown);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Foreground_ਖਿੜਕੀ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Allow_ਸੈੱਟ_Foreground_ਖਿੜਕੀ(DWORD dwProcessId);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ASFW_ANY ((DWORD)-1)

  WINUSERAPI WINBOOL WINAPI ਤਾਲਾ_ਸੈੱਟ_Foreground_ਖਿੜਕੀ(UINT u_ਤਾਲਾ_ਕੋਡ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LSFW_ਤਾਲਾ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LSFW_UNLOCK 2

  WINUSERAPI HWND WINAPI ਖਿੜਕੀ_From_DC(HDC hDC);
  WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
  WINUSERAPI HDC WINAPI GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_ਖਿੜਕੀ 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_CACHE 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_NORESETATTRS 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_CLIPCHILDREN 0x00000008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_CLIPSIBLINGS 0x00000010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_PARENTCLIP 0x00000020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_EXCLUDERGN 0x00000040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_INTERSECTRGN 0x00000080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_EXCLUDEUPDATE 0x00000100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_INTERSECTUPDATE 0x00000200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_LOCKWINDOWUPDATE 0x00000400L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCX_VALIDATE 0x00200000L

  WINUSERAPI HDC WINAPI Get_ਖਿੜਕੀ_DC(HWND hWnd);
  WINUSERAPI ਪੂਰਨ WINAPI ReleaseDC(HWND hWnd,HDC hDC);
  WINUSERAPI HDC WINAPI BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
  WINUSERAPI WINBOOL WINAPI ਸਿਰਾ_Paint(HWND hWnd,CONST PAINTSTRUCT *lpPaint);
  WINUSERAPI WINBOOL WINAPI GetUpdateRect(HWND hWnd,LPRECT lpRect,WINBOOL bErase);
  WINUSERAPI ਪੂਰਨ WINAPI GetUpdateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI ਪੂਰਨ WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Rgn(HWND hWnd,HRGN hRgn,WINBOOL bRedraw);
  WINUSERAPI ਪੂਰਨ WINAPI Get_ਖਿੜਕੀ_Rgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI ਪੂਰਨ WINAPI Get_ਖਿੜਕੀ_Rgn_Box(HWND hWnd,LPRECT lprc);
  WINUSERAPI ਪੂਰਨ WINAPI ExcludeUpdateRgn(HDC hDC,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI InvalidateRect(HWND hWnd,CONST RECT *lpRect,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRect(HWND hWnd,CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI InvalidateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI WINBOOL WINAPI Redraw_ਖਿੜਕੀ(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_INVALIDATE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_INTERNALPAINT 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_ERASE 0x0004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_VALIDATE 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_NOINTERNALPAINT 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_NOERASE 0x0020

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_NOCHILDREN 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_ALLCHILDREN 0x0080

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_UPDATENOW 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_ERASENOW 0x0200

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_ਚੌਖਟਾ 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDW_NOFRAME 0x0800

  WINUSERAPI WINBOOL WINAPI ਤਾਲਾ_ਖਿੜਕੀ_Update(HWND h_Wnd_ਤਾਲਾ);
  WINUSERAPI WINBOOL WINAPI Scroll_ਖਿੜਕੀ(HWND hWnd,ਪੂਰਨ XAmount,ਪੂਰਨ YAmount,CONST RECT *lpRect,CONST RECT *lpClipRect);
  WINUSERAPI WINBOOL WINAPI ScrollDC(HDC hDC,ਪੂਰਨ dx,ਪੂਰਨ dy,CONST RECT *lprcScroll,CONST RECT *lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
  WINUSERAPI ਪੂਰਨ WINAPI Scroll_ਖਿੜਕੀ_Ex(HWND hWnd,ਪੂਰਨ dx,ਪੂਰਨ dy,CONST RECT *prcScroll,CONST RECT *prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SCROLLCHILDREN 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_INVALIDATE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_ERASE 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SW_SMOOTHSCROLL 0x0010

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOSCROLL
  WINUSERAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Scroll_Pos(HWND hWnd,ਪੂਰਨ nBar,ਪੂਰਨ nPos,WINBOOL bRedraw);
  WINUSERAPI ਪੂਰਨ WINAPI GetScrollPos(HWND hWnd,ਪੂਰਨ nBar);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Scroll_Range(HWND hWnd,ਪੂਰਨ nBar,ਪੂਰਨ nMinPos,ਪੂਰਨ nMaxPos,WINBOOL bRedraw);
  WINUSERAPI WINBOOL WINAPI GetScrollRange(HWND hWnd,ਪੂਰਨ nBar,LPINT lpMinPos,LPINT lpMaxPos);
  WINUSERAPI WINBOOL WINAPI ShowScrollBar(HWND hWnd,ਪੂਰਨ wBar,WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESB_ENABLE_BOTH 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESB_DISABLE_BOTH 0x0003

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESB_DISABLE_ਖੱਬਾ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESB_DISABLE_ਸੱਜਾ 0x0002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESB_DISABLE_ਉੱਪਰ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESB_DISABLE_ਥੱਲੇ 0x0002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESB_DISABLE_LTUP ESB_DISABLE_ਖੱਬਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ESB_DISABLE_RTDN ESB_DISABLE_ਸੱਜਾ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Prop ਸੈੱਟ_Prop_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetProp GetPropW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RemoveProp RemovePropW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumPropsEx EnumPropsExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumProps EnumPropsW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_ਪਾਠ ਸੈੱਟ_ਖਿੜਕੀ_ਪਾਠ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_ਪਾਠ Get_ਖਿੜਕੀ_ਪਾਠ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_ਪਾਠ_ਲੰਮਾਈ Get_ਖਿੜਕੀ_ਪਾਠ_ਲੰਮਾਈ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Prop ਸੈੱਟ_Prop_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetProp GetPropA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RemoveProp RemovePropA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumPropsEx EnumPropsExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumProps EnumPropsA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_ਪਾਠ ਸੈੱਟ_ਖਿੜਕੀ_ਪਾਠ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_ਪਾਠ Get_ਖਿੜਕੀ_ਪਾਠ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_ਪਾਠ_ਲੰਮਾਈ Get_ਖਿੜਕੀ_ਪਾਠ_ਲੰਮਾਈ_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Prop_A(HWND hWnd,LPCSTR lpString,HANDLE h_ਅੰਕੜੇ);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Prop_W(HWND hWnd,LPCWSTR lpString,HANDLE h_ਅੰਕੜੇ);
  WINUSERAPI HANDLE WINAPI GetPropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI GetPropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI ਪੂਰਨ WINAPI EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
  WINUSERAPI ਪੂਰਨ WINAPI EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
  WINUSERAPI ਪੂਰਨ WINAPI EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc);
  WINUSERAPI ਪੂਰਨ WINAPI EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_ਖਿੜਕੀ_ਪਾਠ_A(HWND hWnd,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_ਖਿੜਕੀ_ਪਾਠ_W(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI ਪੂਰਨ WINAPI Get_ਖਿੜਕੀ_ਪਾਠ_A(HWND hWnd,LPSTR lpString,ਪੂਰਨ n_Max_ਗਿਣਤੀ);
  WINUSERAPI ਪੂਰਨ WINAPI Get_ਖਿੜਕੀ_ਪਾਠ_W(HWND hWnd,LPWSTR lpString,ਪੂਰਨ n_Max_ਗਿਣਤੀ);
  WINUSERAPI ਪੂਰਨ WINAPI Get_ਖਿੜਕੀ_ਪਾਠ_ਲੰਮਾਈ_A(HWND hWnd);
  WINUSERAPI ਪੂਰਨ WINAPI Get_ਖਿੜਕੀ_ਪਾਠ_ਲੰਮਾਈ_W(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI GetClientRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Get_ਖਿੜਕੀ_Rect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Adjust_ਖਿੜਕੀ_Rect(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu);
  WINUSERAPI WINBOOL WINAPI Adjust_ਖਿੜਕੀ_Rect_Ex(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu,DWORD dwExStyle);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELPINFO_ਖਿੜਕੀ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELPINFO_MENUITEM 0x0002

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HELPINFO {
    UINT cb_ਮਾਪ;
    ਪੂਰਨ iContextType;
    ਪੂਰਨ iCtrlId;
    HANDLE h_ਵਸਤੂ_Handle;
    DWORD_PTR dwContextId;
    ਬਿੰਦੂ_3 MousePos;
  } HELPINFO,*LPHELPINFO;

  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Context_Help_Id(HWND,DWORD);
  WINUSERAPI DWORD WINAPI Get_ਖਿੜਕੀ_Context_Help_Id(HWND);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Menu_Context_Help_Id(HMENU,DWORD);
  WINUSERAPI DWORD WINAPI GetMenuContextHelpId(HMENU);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMB

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_OK 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_OKCANCEL 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ABORTRETRYIGNORE 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_YESNOCANCEL 0x00000003L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_YESNO 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_RETRYCANCEL 0x00000005L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_CANCELTRYCONTINUE 0x00000006L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ICONHAND 0x00000010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ICONQUESTION 0x00000020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ICONEXCLAMATION 0x00000030L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ICONASTERISK 0x00000040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_USERICON 0x00000080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ICONWARNING MB_ICONEXCLAMATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ICONERROR MB_ICONHAND
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ICONINFORMATION MB_ICONASTERISK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ICONSTOP MB_ICONHAND
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_DEFBUTTON1 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_DEFBUTTON2 0x00000100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_DEFBUTTON3 0x00000200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_DEFBUTTON4 0x00000300L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_APPLMODAL 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_SYSTEMMODAL 0x00001000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_TASKMODAL 0x00002000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_HELP 0x00004000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_NOFOCUS 0x00008000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_SETFOREGROUND 0x00010000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_TOPMOST 0x00040000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ਸੱਜਾ 0x00080000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_RTLREADING 0x00100000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_SERVICE_NOTIFICATION 0x00200000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_TYPEMASK 0x0000000FL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_ICONMASK 0x000000F0L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_DEFMASK 0x00000F00L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_MODEMASK 0x00003000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MB_MISCMASK 0x0000C000L

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_Box ਸੁਨੇਹਾ_Box_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_Box_Ex ਸੁਨੇਹਾ_Box_Ex_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_Box ਸੁਨੇਹਾ_Box_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_Box_Ex ਸੁਨੇਹਾ_Box_Ex_A
#ਜੇ_ਅੰਤ

  WINUSERAPI ਪੂਰਨ WINAPI ਸੁਨੇਹਾ_Box_A(HWND hWnd,LPCSTR lp_ਪਾਠ,LPCSTR lpCaption,UINT uType);
  WINUSERAPI ਪੂਰਨ WINAPI ਸੁਨੇਹਾ_Box_W(HWND hWnd,LPCWSTR lp_ਪਾਠ,LPCWSTR lpCaption,UINT uType);
  WINUSERAPI ਪੂਰਨ WINAPI ਸੁਨੇਹਾ_Box_Ex_A(HWND hWnd,LPCSTR lp_ਪਾਠ,LPCSTR lpCaption,UINT uType,ਸ਼ਬਦ_3 wLanguageId);
  WINUSERAPI ਪੂਰਨ WINAPI ਸੁਨੇਹਾ_Box_Ex_W(HWND hWnd,LPCWSTR lp_ਪਾਠ,LPCWSTR lpCaption,UINT uType,ਸ਼ਬਦ_3 wLanguageId);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MSGBOXPARAMSA {
    UINT cb_ਮਾਪ;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpsz_ਪਾਠ;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_ਸੁਨੇਹਾ_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSA,*PMSGBOXPARAMSA,*LPMSGBOXPARAMSA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MSGBOXPARAMSW {
    UINT cb_ਮਾਪ;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpsz_ਪਾਠ;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_ਸੁਨੇਹਾ_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSW,*PMSGBOXPARAMSW,*LPMSGBOXPARAMSW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MSGBOXPARAMSW MSGBOXPARAMS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PMSGBOXPARAMSW PMSGBOXPARAMS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MSGBOXPARAMSA MSGBOXPARAMS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PMSGBOXPARAMSA PMSGBOXPARAMS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_Box_ਅਸਿੱਧਾ ਸੁਨੇਹਾ_Box_ਅਸਿੱਧਾ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੁਨੇਹਾ_Box_ਅਸਿੱਧਾ ਸੁਨੇਹਾ_Box_ਅਸਿੱਧਾ_A
#ਜੇ_ਅੰਤ

  WINUSERAPI ਪੂਰਨ WINAPI ਸੁਨੇਹਾ_Box_ਅਸਿੱਧਾ_A(CONST MSGBOXPARAMSA *lpmbp);
  WINUSERAPI ਪੂਰਨ WINAPI ਸੁਨੇਹਾ_Box_ਅਸਿੱਧਾ_W(CONST MSGBOXPARAMSW *lpmbp);
  WINUSERAPI WINBOOL WINAPI ਸੁਨੇਹਾ_Beep(UINT uType);
#ਜੇ_ਅੰਤ

  WINUSERAPI ਪੂਰਨ WINAPI ShowCursor(WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Cursor_Pos(ਪੂਰਨ X,ਪੂਰਨ Y);
  WINUSERAPI HCURSOR WINAPI ਸੈੱਟ_Cursor(HCURSOR hCursor);
  WINUSERAPI WINBOOL WINAPI GetCursorPos(LPPOINT lp_ਬਿੰਦੂ);
  WINUSERAPI WINBOOL WINAPI ClipCursor(CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI GetClipCursor(LPRECT lpRect);
  WINUSERAPI HCURSOR WINAPI GetCursor(VOID);
  WINUSERAPI WINBOOL WINAPI CreateCaret(HWND hWnd,HBITMAP hBitmap,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ);
  WINUSERAPI UINT WINAPI Get_Caret_Blink_ਸਮਾਂ(VOID);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Caret_Blink_ਸਮਾਂ(UINT uMSeconds);
  WINUSERAPI WINBOOL WINAPI DestroyCaret(VOID);
  WINUSERAPI WINBOOL WINAPI HideCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Caret_Pos(ਪੂਰਨ X,ਪੂਰਨ Y);
  WINUSERAPI WINBOOL WINAPI GetCaretPos(LPPOINT lp_ਬਿੰਦੂ);
  WINUSERAPI WINBOOL WINAPI Client_ਮੰਜ਼ਿਲ_Screen(HWND hWnd,LPPOINT lp_ਬਿੰਦੂ);
  WINUSERAPI WINBOOL WINAPI Screen_ਮੰਜ਼ਿਲ_Client(HWND hWnd,LPPOINT lp_ਬਿੰਦੂ);
  WINUSERAPI ਪੂਰਨ WINAPI Map_ਖਿੜਕੀ_Points(HWND hWndFrom,HWND h_Wnd_ਮੰਜ਼ਿਲ,LPPOINT lpPoints,UINT cPoints);
  WINUSERAPI HWND WINAPI ਖਿੜਕੀ_From_ਬਿੰਦੂ(ਬਿੰਦੂ_3 ਬਿੰਦੂ_2);
  WINUSERAPI HWND WINAPI ਬੱਚਾ_ਖਿੜਕੀ_From_ਬਿੰਦੂ(HWND h_Wnd_ਮਾਪਾ,ਬਿੰਦੂ_3 ਬਿੰਦੂ_2);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CWP_ALL 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CWP_SKIPINVISIBLE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CWP_SKIPDISABLED 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CWP_SKIPTRANSPARENT 0x0004

  WINUSERAPI HWND WINAPI ਬੱਚਾ_ਖਿੜਕੀ_From_ਬਿੰਦੂ_Ex(HWND hwnd,ਬਿੰਦੂ_3 pt,UINT flags);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOCOLOR

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTLCOLOR_MSGBOX 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTLCOLOR_EDIT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTLCOLOR_LISTBOX 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTLCOLOR_BTN 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTLCOLOR_DLG 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTLCOLOR_SCROLLBAR 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTLCOLOR_STATIC 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CTLCOLOR_MAX 7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_SCROLLBAR 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_BACKGROUND 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_ACTIVECAPTION 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_INACTIVECAPTION 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_MENU 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_ਖਿੜਕੀ 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_WINDOWFRAME 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_MENUTEXT 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_WINDOWTEXT 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_CAPTIONTEXT 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_ACTIVEBORDER 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_INACTIVEBORDER 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_APPWORKSPACE 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_HIGHLIGHT 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_HIGHLIGHTTEXT 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_BTNFACE 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_BTNSHADOW 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_GRAYTEXT 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_BTNTEXT 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_INACTIVECAPTIONTEXT 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_BTNHIGHLIGHT 20

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_3DDKSHADOW 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_3DLIGHT 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_INFOTEXT 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_INFOBK 24

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_HOTLIGHT 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_GRADIENTACTIVECAPTION 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_GRADIENTINACTIVECAPTION 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_MENUHILIGHT 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_MENUBAR 30

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_DESKTOP COLOR_BACKGROUND
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_3DFACE COLOR_BTNFACE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_3DSHADOW COLOR_BTNSHADOW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

  WINUSERAPI DWORD WINAPI GetSysColor(ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI HBRUSH WINAPI GetSysColorBrush(ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Sys_Colors(ਪੂਰਨ cElements,CONST INT *lpaElements,CONST COLORREF *lpa_Rgb_ਮੁੱਲਾਂ);
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI DrawFocusRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI ਪੂਰਨ WINAPI FillRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI ਪੂਰਨ WINAPI ਚੌਖਟਾ_Rect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI WINBOOL WINAPI InvertRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Rect(LPRECT lprc,ਪੂਰਨ x_ਖੱਬਾ,ਪੂਰਨ y_ਸਿਖਰ,ਪੂਰਨ x_ਸੱਜਾ,ਪੂਰਨ yBottom);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Rect_ਖਾਲੀ_ਥਾਵਾਂ(LPRECT lprc);
  WINUSERAPI WINBOOL WINAPI CopyRect(LPRECT lprcDst,CONST RECT *lprcSrc);
  WINUSERAPI WINBOOL WINAPI InflateRect(LPRECT lprc,ਪੂਰਨ dx,ਪੂਰਨ dy);
  WINUSERAPI WINBOOL WINAPI IntersectRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI UnionRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI ਘਟਾਓ_Rect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI ਵਿੱਥ_Rect(LPRECT lprc,ਪੂਰਨ dx,ਪੂਰਨ dy);
  WINUSERAPI WINBOOL WINAPI Is_Rect_ਖਾਲੀ_ਥਾਵਾਂ(CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI EqualRect(CONST RECT *lprc1,CONST RECT *lprc2);
  WINUSERAPI WINBOOL WINAPI Pt_ਵਿੱਚ_Rect(CONST RECT *lprc,ਬਿੰਦੂ_3 pt);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINOFFSETS

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Long Get_ਖਿੜਕੀ_Long_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_Long ਸੈੱਟ_ਖਿੜਕੀ_Long_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Long Get_ਖਿੜਕੀ_Long_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_Long ਸੈੱਟ_ਖਿੜਕੀ_Long_A
#ਜੇ_ਅੰਤ

  WINUSERAPI ਸ਼ਬਦ_3 WINAPI Get_ਖਿੜਕੀ_ਸ਼ਬਦ(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI ਸ਼ਬਦ_3 WINAPI ਸੈੱਟ_ਖਿੜਕੀ_ਸ਼ਬਦ(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,ਸ਼ਬਦ_3 w_New_ਸ਼ਬਦ);
  WINUSERAPI LONG WINAPI Get_ਖਿੜਕੀ_Long_A(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI LONG WINAPI Get_ਖਿੜਕੀ_Long_W(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI LONG WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Long_A(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,LONG dwNewLong);
  WINUSERAPI LONG WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Long_W(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,LONG dwNewLong);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Long_Ptr Get_ਖਿੜਕੀ_Long_Ptr_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Long_Ptr Get_ਖਿੜਕੀ_Long_Ptr_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr_A
#ਜੇ_ਅੰਤ

  WINUSERAPI LONG_PTR WINAPI Get_ਖਿੜਕੀ_Long_Ptr_A(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI LONG_PTR WINAPI Get_ਖਿੜਕੀ_Long_Ptr_W(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI LONG_PTR WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr_A(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,LONG_PTR dwNewLong);
  WINUSERAPI LONG_PTR WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr_W(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,LONG_PTR dwNewLong);
#ਨਹੀਂਤਾਂ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Long_Ptr Get_ਖਿੜਕੀ_Long_Ptr_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Long_Ptr Get_ਖਿੜਕੀ_Long_Ptr_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr_A
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Long_Ptr_A Get_ਖਿੜਕੀ_Long_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Long_Ptr_W Get_ਖਿੜਕੀ_Long_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr_A ਸੈੱਟ_ਖਿੜਕੀ_Long_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਖਿੜਕੀ_Long_Ptr_W ਸੈੱਟ_ਖਿੜਕੀ_Long_W
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassLong GetClassLongW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Class_Long ਸੈੱਟ_Class_Long_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassLong GetClassLongA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Class_Long ਸੈੱਟ_Class_Long_A
#ਜੇ_ਅੰਤ

  WINUSERAPI ਸ਼ਬਦ_3 WINAPI Get_Class_ਸ਼ਬਦ(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI ਸ਼ਬਦ_3 WINAPI ਸੈੱਟ_Class_ਸ਼ਬਦ(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,ਸ਼ਬਦ_3 w_New_ਸ਼ਬਦ);
  WINUSERAPI DWORD WINAPI GetClassLongA(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI DWORD WINAPI GetClassLongW(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI DWORD WINAPI ਸੈੱਟ_Class_Long_A(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,LONG dwNewLong);
  WINUSERAPI DWORD WINAPI ਸੈੱਟ_Class_Long_W(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,LONG dwNewLong);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassLongPtr GetClassLongPtrW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Class_Long_Ptr ਸੈੱਟ_Class_Long_Ptr_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassLongPtr GetClassLongPtrA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Class_Long_Ptr ਸੈੱਟ_Class_Long_Ptr_A
#ਜੇ_ਅੰਤ

  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ);
  WINUSERAPI ULONG_PTR WINAPI ਸੈੱਟ_Class_Long_Ptr_A(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,LONG_PTR dwNewLong);
  WINUSERAPI ULONG_PTR WINAPI ਸੈੱਟ_Class_Long_Ptr_W(HWND hWnd,ਪੂਰਨ n_ਸੂਚਕਾਂਕ,LONG_PTR dwNewLong);
#ਨਹੀਂਤਾਂ
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassLongPtr GetClassLongPtrW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Class_Long_Ptr ਸੈੱਟ_Class_Long_Ptr_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassLongPtr GetClassLongPtrA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Class_Long_Ptr ਸੈੱਟ_Class_Long_Ptr_A
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassLongPtrA GetClassLongA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassLongPtrW GetClassLongW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Class_Long_Ptr_A ਸੈੱਟ_Class_Long_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Class_Long_Ptr_W ਸੈੱਟ_Class_Long_W
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਖਿੜਕੀ ਲੱਭੋ_ਖਿੜਕੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਖਿੜਕੀ_Ex ਲੱਭੋ_ਖਿੜਕੀ_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassName GetClassNameW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਖਿੜਕੀ ਲੱਭੋ_ਖਿੜਕੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਭੋ_ਖਿੜਕੀ_Ex ਲੱਭੋ_ਖਿੜਕੀ_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetClassName GetClassNameA
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI GetProcessDefaultLayout(DWORD *pdwDefaultLayout);
  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_Process_Default_Layout(DWORD dwDefaultLayout);
  WINUSERAPI HWND WINAPI Get_Desktop_ਖਿੜਕੀ(VOID);
  WINUSERAPI HWND WINAPI Get_ਮਾਪਾ(HWND hWnd);
  WINUSERAPI HWND WINAPI ਸੈੱਟ_ਮਾਪਾ(HWND h_Wnd_ਬੱਚਾ,HWND h_Wnd_New_ਮਾਪਾ);
  WINUSERAPI WINBOOL WINAPI Enum_ਬੱਚਾ_Windows(HWND h_Wnd_ਮਾਪਾ,WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI HWND WINAPI ਲੱਭੋ_ਖਿੜਕੀ_A(LPCSTR lpClassName,LPCSTR lp_ਖਿੜਕੀ_Name);
  WINUSERAPI HWND WINAPI ਲੱਭੋ_ਖਿੜਕੀ_W(LPCWSTR lpClassName,LPCWSTR lp_ਖਿੜਕੀ_Name);
  WINUSERAPI HWND WINAPI ਲੱਭੋ_ਖਿੜਕੀ_Ex_A(HWND h_Wnd_ਮਾਪਾ,HWND h_Wnd_ਬੱਚਾ_After,LPCSTR lpszClass,LPCSTR lpsz_ਖਿੜਕੀ);
  WINUSERAPI HWND WINAPI ਲੱਭੋ_ਖਿੜਕੀ_Ex_W(HWND h_Wnd_ਮਾਪਾ,HWND h_Wnd_ਬੱਚਾ_After,LPCWSTR lpszClass,LPCWSTR lpsz_ਖਿੜਕੀ);
  WINUSERAPI HWND WINAPI Get_Shell_ਖਿੜਕੀ(VOID);
  WINUSERAPI WINBOOL WINAPI ਰਜਿਸਟਰ_Shell_Hook_ਖਿੜਕੀ(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI Deregister_Shell_Hook_ਖਿੜਕੀ(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(Handle_ਮੰਜ਼ਿਲ_Ulong(hTask),lpfn,lParam)

  WINUSERAPI ਪੂਰਨ WINAPI GetClassNameA(HWND hWnd,LPSTR lpClassName,ਪੂਰਨ n_Max_ਗਿਣਤੀ);
  WINUSERAPI ਪੂਰਨ WINAPI GetClassNameW(HWND hWnd,LPWSTR lpClassName,ਪੂਰਨ n_Max_ਗਿਣਤੀ);
  WINUSERAPI HWND WINAPI Get_ਸਿਖਰ_ਖਿੜਕੀ(HWND hWnd);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਅਗਲਾ_ਖਿੜਕੀ(hWnd,wCmd) Get_ਖਿੜਕੀ(hWnd,wCmd)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Sys_Modal_ਖਿੜਕੀ() (ਨਿਰਾ)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Sys_Modal_ਖਿੜਕੀ(hWnd) (ਨਿਰਾ)

  WINUSERAPI DWORD WINAPI Get_ਖਿੜਕੀ_Thread_Process_Id(HWND hWnd,LPDWORD lpdwProcessId);
  WINUSERAPI WINBOOL WINAPI IsGUIThread(WINBOOL bConvert);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Task(hWnd) ((HANDLE)(DWORD_PTR)Get_ਖਿੜਕੀ_Thread_Process_Id(hWnd,ਨਿਰਾ))

  WINUSERAPI HWND WINAPI Get_ਆਖਰੀ_ਸਰਗਰਮ_Popup(HWND hWnd);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GW_HWNDFIRST 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GW_HWNDLAST 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GW_HWNDNEXT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GW_HWNDPREV 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GW_OWNER 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GW_ਬੱਚਾ 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GW_ENABLEDPOPUP 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GW_MAX 6

  WINUSERAPI HWND WINAPI Get_ਖਿੜਕੀ(HWND hWnd,UINT uCmd);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWH

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Windows_Hook ਸੈੱਟ_Windows_Hook_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Windows_Hook_Ex ਸੈੱਟ_Windows_Hook_Ex_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Windows_Hook ਸੈੱਟ_Windows_Hook_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_Windows_Hook_Ex ਸੈੱਟ_Windows_Hook_Ex_A
#ਜੇ_ਅੰਤ

  WINUSERAPI HHOOK WINAPI ਸੈੱਟ_Windows_Hook_A(ਪੂਰਨ nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI ਸੈੱਟ_Windows_Hook_W(ਪੂਰਨ nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHook(ਪੂਰਨ n_ਕੋਡ,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI ਸੈੱਟ_Windows_Hook_Ex_A(ਪੂਰਨ idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI HHOOK WINAPI ਸੈੱਟ_Windows_Hook_Ex_W(ਪੂਰਨ idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);
  WINUSERAPI LRESULT WINAPI Call_ਅਗਲਾ_Hook_Ex(HHOOK hhk,ਪੂਰਨ n_ਕੋਡ,WPARAM wParam,LPARAM lParam);
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DefHookProc(n_ਕੋਡ,wParam,lParam,phhk) Call_ਅਗਲਾ_Hook_Ex(*phhk,n_ਕੋਡ,wParam,lParam)
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMENUS

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_ਪਾਓ 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_CHANGE 0x00000080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_APPEND 0x00000100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_DELETE 0x00000200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_REMOVE 0x00001000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_BYCOMMAND 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_BYPOSITION 0x00000400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_SEPARATOR 0x00000800L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_ENABLED 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_GRAYED 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_DISABLED 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_UNCHECKED 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_CHECKED 0x00000008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_USECHECKBITMAPS 0x00000200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_STRING 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_BITMAP 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_OWNERDRAW 0x00000100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_POPUP 0x00000010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_MENUBARBREAK 0x00000020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_MENUBREAK 0x00000040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_UNHILITE 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_HILITE 0x00000080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_DEFAULT 0x00001000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_SYSMENU 0x00002000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_HELP 0x00004000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_RIGHTJUSTIFY 0x00004000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_MOUSESELECT 0x00008000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_ਸਿਰਾ 0x00000080L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFT_STRING MF_STRING
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFT_BITMAP MF_BITMAP
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFT_MENUBARBREAK MF_MENUBARBREAK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFT_MENUBREAK MF_MENUBREAK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFT_OWNERDRAW MF_OWNERDRAW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFT_RADIOCHECK 0x00000200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFT_SEPARATOR MF_SEPARATOR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFT_RIGHTORDER 0x00002000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFS_GRAYED 0x00000003L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFS_DISABLED MFS_GRAYED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFS_CHECKED MF_CHECKED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFS_HILITE MF_HILITE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFS_ENABLED MF_ENABLED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFS_UNCHECKED MF_UNCHECKED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFS_UNHILITE MF_UNHILITE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFS_DEFAULT MF_DEFAULT

  WINUSERAPI WINBOOL WINAPI Check_Menu_Radio_ਵਸਤੂ(HMENU hmenu,UINT ਪਹਿਲਾ,UINT ਆਖਰੀ,UINT check,UINT flags);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਸ਼ਬਦ_3 ਸੰਸਕਰਣ_ਸੰਖਿਆ;
    ਸ਼ਬਦ_3 ਵਿੱਥ;
  } MENUITEMTEMPLATEHEADER,*PMENUITEMTEMPLATEHEADER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    ਸ਼ਬਦ_3 mtOption;
    ਸ਼ਬਦ_3 mtID;
    WCHAR mtString[1];
  } MENUITEMTEMPLATE,*PMENUITEMTEMPLATE;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MF_ਸਿਰਾ 0x00000080L
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOSYSCOMMANDS

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_ਮਾਪ 0xF000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_MOVE 0xF010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_MINIMIZE 0xF020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_MAXIMIZE 0xF030
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_NEXTWINDOW 0xF040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_PREVWINDOW 0xF050
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_CLOSE 0xF060
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_VSCROLL 0xF070
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_HSCROLL 0xF080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_MOUSEMENU 0xF090
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_KEYMENU 0xF100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_ARRANGE 0xF110
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_RESTORE 0xF120
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_TASKLIST 0xF130
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_SCREENSAVE 0xF140
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_HOTKEY 0xF150
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_DEFAULT 0xF160
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_MONITORPOWER 0xF170
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_CONTEXTHELP 0xF180
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_SEPARATOR 0xF00F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_ICON SC_MINIMIZE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SC_ZOOM SC_MAXIMIZE
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Bitmap ਲੱਦੋ_Bitmap_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Cursor ਲੱਦੋ_Cursor_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Cursor_From_File ਲੱਦੋ_Cursor_From_File_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Bitmap ਲੱਦੋ_Bitmap_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Cursor ਲੱਦੋ_Cursor_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Cursor_From_File ਲੱਦੋ_Cursor_From_File_A
#ਜੇ_ਅੰਤ

  WINUSERAPI HBITMAP WINAPI ਲੱਦੋ_Bitmap_A(HINSTANCE hInstance,LPCSTR lpBitmapName);
  WINUSERAPI HBITMAP WINAPI ਲੱਦੋ_Bitmap_W(HINSTANCE hInstance,LPCWSTR lpBitmapName);
  WINUSERAPI HCURSOR WINAPI ਲੱਦੋ_Cursor_A(HINSTANCE hInstance,LPCSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI ਲੱਦੋ_Cursor_W(HINSTANCE hInstance,LPCWSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI ਲੱਦੋ_Cursor_From_File_A(LPCSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI ਲੱਦੋ_Cursor_From_File_W(LPCWSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI CreateCursor(HINSTANCE hInst,ਪੂਰਨ xHotSpot,ਪੂਰਨ yHotSpot,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ,CONST VOID *pvANDPlane,CONST VOID *pvXORPlane);
  WINUSERAPI WINBOOL WINAPI DestroyCursor(HCURSOR hCursor);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_ARROW MAKEINTRESOURCE(32512)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_IBEAM MAKEINTRESOURCE(32513)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_WAIT MAKEINTRESOURCE(32514)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_CROSS MAKEINTRESOURCE(32515)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_UPARROW MAKEINTRESOURCE(32516)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_ਮਾਪ MAKEINTRESOURCE(32640)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_ICON MAKEINTRESOURCE(32641)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_SIZENWSE MAKEINTRESOURCE(32642)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_SIZENESW MAKEINTRESOURCE(32643)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_SIZEWE MAKEINTRESOURCE(32644)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_SIZENS MAKEINTRESOURCE(32645)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_SIZEALL MAKEINTRESOURCE(32646)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_NO MAKEINTRESOURCE(32648)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_HAND MAKEINTRESOURCE(32649)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_APPSTARTING MAKEINTRESOURCE(32650)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDC_HELP MAKEINTRESOURCE(32651)

  WINUSERAPI WINBOOL WINAPI ਸੈੱਟ_System_Cursor(HCURSOR hcur,DWORD id);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ICONINFO {
    WINBOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbm_ਨਕਾਬ;
    HBITMAP hbmColor;
  } ICONINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ICONINFO *PICONINFO;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Icon ਲੱਦੋ_Icon_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿੱਜੀ_ਕੱਢੋ_Icons ਨਿੱਜੀ_ਕੱਢੋ_Icons_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Icon ਲੱਦੋ_Icon_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਨਿੱਜੀ_ਕੱਢੋ_Icons ਨਿੱਜੀ_ਕੱਢੋ_Icons_A
#ਜੇ_ਅੰਤ

  WINUSERAPI HICON WINAPI ਲੱਦੋ_Icon_A(HINSTANCE hInstance,LPCSTR lpIconName);
  WINUSERAPI HICON WINAPI ਲੱਦੋ_Icon_W(HINSTANCE hInstance,LPCWSTR lpIconName);
  WINUSERAPI UINT WINAPI ਨਿੱਜੀ_ਕੱਢੋ_Icons_A(LPCSTR szFileName,ਪੂਰਨ n_Icon_ਸੂਚਕਾਂਕ,ਪੂਰਨ cxIcon,ਪੂਰਨ cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI UINT WINAPI ਨਿੱਜੀ_ਕੱਢੋ_Icons_W(LPCWSTR szFileName,ਪੂਰਨ n_Icon_ਸੂਚਕਾਂਕ,ਪੂਰਨ cxIcon,ਪੂਰਨ cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI HICON WINAPI CreateIcon(HINSTANCE hInstance,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ,BYTE cPlanes,BYTE c_ਬਿੱਟ_Pixel,CONST BYTE *lpbANDbits,CONST BYTE *lpbXORbits);
  WINUSERAPI WINBOOL WINAPI DestroyIcon(HICON hIcon);
  WINUSERAPI ਪੂਰਨ WINAPI LookupIconIdFromDirectory(PBYTE presbits,WINBOOL fIcon);
  WINUSERAPI ਪੂਰਨ WINAPI LookupIconIdFromDirectoryEx(PBYTE presbits,WINBOOL fIcon,ਪੂਰਨ cxDesired,ਪੂਰਨ cyDesired,UINT Flags);
  WINUSERAPI HICON WINAPI CreateIconFromResource(PBYTE presbits,DWORD dw_Res_ਮਾਪ,WINBOOL fIcon,DWORD dwVer);
  WINUSERAPI HICON WINAPI CreateIconFromResourceEx(PBYTE presbits,DWORD dw_Res_ਮਾਪ,WINBOOL fIcon,DWORD dwVer,ਪੂਰਨ cxDesired,ਪੂਰਨ cyDesired,UINT Flags);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CURSORSHAPE {
    ਪੂਰਨ xHotSpot;
    ਪੂਰਨ yHotSpot;
    ਪੂਰਨ cx;
    ਪੂਰਨ cy;
    ਪੂਰਨ cb_ਚੌੜਾਈ;
    BYTE Planes;
    BYTE ਬਿੱਟ_Pixel;
  } CURSORSHAPE,*LPCURSORSHAPE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_BITMAP 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ICON 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_CURSOR 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IMAGE_ENHMETAFILE 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_DEFAULTCOLOR 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_MONOCHROME 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_COLOR 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_COPYRETURNORG 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_COPYDELETEORG 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_LOADFROMFILE 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_LOADTRANSPARENT 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_DEFAULTSIZE 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_VGACOLOR 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_LOADMAP3DCOLORS 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_CREATEDIBSECTION 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_COPYFROMRESOURCE 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LR_SHARED 0x8000

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Image ਲੱਦੋ_Image_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_Image ਲੱਦੋ_Image_A
#ਜੇ_ਅੰਤ

  WINUSERAPI HANDLE WINAPI ਲੱਦੋ_Image_A(HINSTANCE hInst,LPCSTR name,UINT type,ਪੂਰਨ cx,ਪੂਰਨ cy,UINT fu_ਲੱਦੋ);
  WINUSERAPI HANDLE WINAPI ਲੱਦੋ_Image_W(HINSTANCE hInst,LPCWSTR name,UINT type,ਪੂਰਨ cx,ਪੂਰਨ cy,UINT fu_ਲੱਦੋ);
  WINUSERAPI HANDLE WINAPI CopyImage(HANDLE h,UINT type,ਪੂਰਨ cx,ਪੂਰਨ cy,UINT flags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DI_ਨਕਾਬ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DI_IMAGE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DI_ਸਾਧਾਰਨ 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DI_COMPAT 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DI_DEFAULTSIZE 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DI_NOMIRROR 0x0010

  WINUSERAPI WINBOOL WINAPI DrawIconEx(HDC hdc,ਪੂਰਨ x_ਖੱਬਾ,ਪੂਰਨ y_ਸਿਖਰ,HICON hIcon,ਪੂਰਨ cx_ਚੌੜਾਈ,ਪੂਰਨ cy_ਚੌੜਾਈ,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
  WINUSERAPI HICON WINAPI Create_Icon_ਅਸਿੱਧਾ(PICONINFO piconinfo);
  WINUSERAPI HICON WINAPI CopyIcon(HICON hIcon);
  WINUSERAPI WINBOOL WINAPI GetIconInfo(HICON hIcon,PICONINFO piconinfo);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RES_ICON 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RES_CURSOR 2

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ OEMRESOURCE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_CLOSE 32754
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_UPARROW 32753
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_DNARROW 32752
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_RGARROW 32751
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_LFARROW 32750
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_REDUCE 32749
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_ZOOM 32748
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_RESTORE 32747
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_REDUCED 32746
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_ZOOMD 32745
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_RESTORED 32744
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_UPARROWD 32743
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_DNARROWD 32742
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_RGARROWD 32741
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_LFARROWD 32740
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_MNARROW 32739
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_COMBO 32738
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_UPARROWI 32737
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_DNARROWI 32736
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_RGARROWI 32735
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_LFARROWI 32734

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_OLD_CLOSE 32767
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_ਮਾਪ 32766
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_OLD_UPARROW 32765
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_OLD_DNARROW 32764
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_OLD_RGARROW 32763
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_OLD_LFARROW 32762
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_BTSIZE 32761
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_CHECK 32760
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_CHECKBOXES 32759
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_BTNCORNERS 32758
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_OLD_REDUCE 32757
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_OLD_ZOOM 32756
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBM_OLD_RESTORE 32755

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_ਸਾਧਾਰਨ 32512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_IBEAM 32513
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_WAIT 32514
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_CROSS 32515
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_ਉੱਪਰ 32516
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_ਮਾਪ 32640
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_ICON 32641
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_SIZENWSE 32642
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_SIZENESW 32643
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_SIZEWE 32644
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_SIZENS 32645
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_SIZEALL 32646
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_ICOCUR 32647
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_NO 32648
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_HAND 32649
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OCR_APPSTARTING 32650

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OIC_SAMPLE 32512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OIC_HAND 32513
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OIC_QUES 32514
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OIC_BANG 32515
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OIC_NOTE 32516
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OIC_WINLOGO 32517
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OIC_WARNING OIC_BANG
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OIC_ERROR OIC_HAND
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OIC_INFORMATION OIC_NOTE
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ORD_LANGDRIVER 1

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOICONS

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ RC_INVOKED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_APPLICATION 32512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_HAND 32513
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_QUESTION 32514
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_EXCLAMATION 32515
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_ASTERISK 32516
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_WINLOGO 32517
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_APPLICATION MAKEINTRESOURCE(32512)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_HAND MAKEINTRESOURCE(32513)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_QUESTION MAKEINTRESOURCE(32514)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_ASTERISK MAKEINTRESOURCE(32516)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_WINLOGO MAKEINTRESOURCE(32517)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_WARNING IDI_EXCLAMATION
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_ERROR IDI_HAND
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDI_INFORMATION IDI_ASTERISK
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_String ਲੱਦੋ_String_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੱਦੋ_String ਲੱਦੋ_String_A
#ਜੇ_ਅੰਤ

  WINUSERAPI ਪੂਰਨ WINAPI ਲੱਦੋ_String_A(HINSTANCE hInstance,UINT uID,LPSTR lp_ਬਫਰ,ਪੂਰਨ cch_ਬਫਰ_Max);
  WINUSERAPI ਪੂਰਨ WINAPI ਲੱਦੋ_String_W(HINSTANCE hInstance,UINT uID,LPWSTR lp_ਬਫਰ,ਪੂਰਨ cch_ਬਫਰ_Max);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDOK 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDCANCEL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDABORT 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDRETRY 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDIGNORE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDYES 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDNO 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDCLOSE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDHELP 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDTRYAGAIN 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDCONTINUE 11

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ IDTIMEOUT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDTIMEOUT 32000
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOCTLMGR

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINSTYLES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_ਖੱਬਾ 0x0000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_CENTER 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_ਸੱਜਾ 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_MULTILINE 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_UPPERCASE 0x0008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_LOWERCASE 0x0010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_PASSWORD 0x0020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_AUTOVSCROLL 0x0040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_AUTOHSCROLL 0x0080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_NOHIDESEL 0x0100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_OEMCONVERT 0x0400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_READONLY 0x0800L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_WANTRETURN 0x1000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ES_ਸੰਖਿਆ 0x2000L
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_SETFOCUS 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_KILLFOCUS 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_CHANGE 0x0300
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_UPDATE 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_ERRSPACE 0x0500
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_MAXTEXT 0x0501
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_HSCROLL 0x0601
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_VSCROLL 0x0602
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_ALIGN_LTR_EC 0x0700
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EN_ALIGN_RTL_EC 0x0701

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EC_LEFTMARGIN 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EC_RIGHTMARGIN 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EC_USEFONTINFO 0xffff

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMSIS_COMPOSITIONSTRING 0x0001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EIMES_GETCOMPSTRATONCE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EIMES_CANCELCOMPSTRINFOCUS 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINMESSAGES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETSEL 0x00B0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETSEL 0x00B1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETRECT 0x00B2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETRECT 0x00B3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETRECTNP 0x00B4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SCROLL 0x00B5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_LINESCROLL 0x00B6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SCROLLCARET 0x00B7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETMODIFY 0x00B8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETMODIFY 0x00B9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETLINECOUNT 0x00BA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_LINEINDEX 0x00BB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETHANDLE 0x00BC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETHANDLE 0x00BD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETTHUMB 0x00BE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_LINELENGTH 0x00C1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_REPLACESEL 0x00C2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETLINE 0x00C4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_LIMITTEXT 0x00C5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_CANUNDO 0x00C6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_UNDO 0x00C7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_FMTLINES 0x00C8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_LINEFROMCHAR 0x00C9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETTABSTOPS 0x00CB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETPASSWORDCHAR 0x00CC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_EMPTYUNDOBUFFER 0x00CD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETFIRSTVISIBLELINE 0x00CE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETREADONLY 0x00CF
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETWORDBREAKPROC 0x00D0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETWORDBREAKPROC 0x00D1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETPASSWORDCHAR 0x00D2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETMARGINS 0x00D3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETMARGINS 0x00D4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETLIMITTEXT EM_LIMITTEXT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETLIMITTEXT 0x00D5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_POSFROMCHAR 0x00D6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_CHARFROMPOS 0x00D7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_SETIMESTATUS 0x00D8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EM_GETIMESTATUS 0x00D9
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WB_ਖੱਬਾ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WB_ਸੱਜਾ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WB_ISDELIMITER 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_PUSHBUTTON 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_DEFPUSHBUTTON 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_CHECKBOX 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_AUTOCHECKBOX 0x00000003L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_RADIOBUTTON 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_3STATE 0x00000005L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_AUTO3STATE 0x00000006L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_GROUPBOX 0x00000007L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_USERBUTTON 0x00000008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_AUTORADIOBUTTON 0x00000009L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_PUSHBOX 0x0000000AL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_OWNERDRAW 0x0000000BL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_TYPEMASK 0x0000000FL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_LEFTTEXT 0x00000020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_ਪਾਠ 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_ICON 0x00000040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_BITMAP 0x00000080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_ਖੱਬਾ 0x00000100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_ਸੱਜਾ 0x00000200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_CENTER 0x00000300L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_ਸਿਖਰ 0x00000400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_BOTTOM 0x00000800L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_VCENTER 0x00000C00L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_PUSHLIKE 0x00001000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_MULTILINE 0x00002000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_NOTIFY 0x00004000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_FLAT 0x00008000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_RIGHTBUTTON BS_LEFTTEXT

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_CLICKED 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_PAINT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_HILITE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_UNHILITE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_DISABLE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_DOUBLECLICKED 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_PUSHED BN_HILITE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_UNPUSHED BN_UNHILITE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_DBLCLK BN_DOUBLECLICKED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_SETFOCUS 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BN_KILLFOCUS 7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BM_GETCHECK 0x00F0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BM_SETCHECK 0x00F1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BM_GETSTATE 0x00F2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BM_SETSTATE 0x00F3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BM_SETSTYLE 0x00F4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BM_CLICK 0x00F5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BM_GETIMAGE 0x00F6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BM_SETIMAGE 0x00F7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BST_UNCHECKED 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BST_CHECKED 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BST_INDETERMINATE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BST_PUSHED 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BST_FOCUS 0x0008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ਖੱਬਾ 0x00000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_CENTER 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ਸੱਜਾ 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ICON 0x00000003L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_BLACKRECT 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_GRAYRECT 0x00000005L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_WHITERECT 0x00000006L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_BLACKFRAME 0x00000007L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_GRAYFRAME 0x00000008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_WHITEFRAME 0x00000009L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_USERITEM 0x0000000AL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_SIMPLE 0x0000000BL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_LEFTNOWORDWRAP 0x0000000CL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_OWNERDRAW 0x0000000DL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_BITMAP 0x0000000EL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ENHMETAFILE 0x0000000FL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ETCHEDHORZ 0x00000010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ETCHEDVERT 0x00000011L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ETCHEDFRAME 0x00000012L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_TYPEMASK 0x0000001FL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_REALSIZECONTROL 0x00000040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_NOPREFIX 0x00000080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_NOTIFY 0x00000100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_CENTERIMAGE 0x00000200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_RIGHTJUST 0x00000400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_REALSIZEIMAGE 0x00000800L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_SUNKEN 0x00001000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_EDITCONTROL 0x00002000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ENDELLIPSIS 0x00004000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_PATHELLIPSIS 0x00008000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_WORDELLIPSIS 0x0000C000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SS_ELLIPSISMASK 0x0000C000L

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINMESSAGES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STM_SETICON 0x0170
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STM_GETICON 0x0171
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STM_SETIMAGE 0x0172
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STM_GETIMAGE 0x0173
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STN_CLICKED 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STN_DBLCLK 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STN_ENABLE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STN_DISABLE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STM_MSGMAX 0x0174
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WC_DIALOG (MAKEINTATOM(0x8002))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DWL_MSGRESULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DWL_DLGPROC 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DWL_USER 8

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64

#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ DWL_MSGRESULT
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ DWL_DLGPROC
#ਪਰਿਭਾਸ਼ਾ_ਰੱਦ DWL_USER
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DWLP_MSGRESULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DWLP_DLGPROC DWLP_MSGRESULT + ਆਕਾਰ(LRESULT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DWLP_USER DWLP_DLGPROC + ਆਕਾਰ(DLGPROC)

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMSG

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Is_Dialog_ਸੁਨੇਹਾ Is_Dialog_ਸੁਨੇਹਾ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Is_Dialog_ਸੁਨੇਹਾ Is_Dialog_ਸੁਨੇਹਾ_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI Is_Dialog_ਸੁਨੇਹਾ_A(HWND hDlg,LPMSG lp_ਸੁਨੇਹਾ_2);
  WINUSERAPI WINBOOL WINAPI Is_Dialog_ਸੁਨੇਹਾ_W(HWND hDlg,LPMSG lp_ਸੁਨੇਹਾ_2);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DlgDirList DlgDirListW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DlgDirSelectEx DlgDirSelectExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DlgDirListComboBox DlgDirListComboBoxW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DlgDirList DlgDirListA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DlgDirSelectEx DlgDirSelectExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DlgDirListComboBox DlgDirListComboBoxA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI MapDialogRect(HWND hDlg,LPRECT lpRect);
  WINUSERAPI ਪੂਰਨ WINAPI DlgDirListA(HWND hDlg,LPSTR lp_ਰਸਤਾ_Spec,ਪੂਰਨ nIDListBox,ਪੂਰਨ n_IDStatic_ਰਸਤਾ,UINT uFileType);
  WINUSERAPI ਪੂਰਨ WINAPI DlgDirListW(HWND hDlg,LPWSTR lp_ਰਸਤਾ_Spec,ਪੂਰਨ nIDListBox,ਪੂਰਨ n_IDStatic_ਰਸਤਾ,UINT uFileType);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDL_READWRITE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDL_READONLY 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDL_HIDDEN 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDL_SYSTEM 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDL_DIRECTORY 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDL_ARCHIVE 0x0020

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDL_POSTMSGS 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDL_DRIVES 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DDL_EXCLUSIVE 0x8000

  WINUSERAPI WINBOOL WINAPI DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,ਪੂਰਨ ch_ਗਿਣਤੀ,ਪੂਰਨ idListBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,ਪੂਰਨ ch_ਗਿਣਤੀ,ਪੂਰਨ idListBox);
  WINUSERAPI ਪੂਰਨ WINAPI DlgDirListComboBoxA(HWND hDlg,LPSTR lp_ਰਸਤਾ_Spec,ਪੂਰਨ nIDComboBox,ਪੂਰਨ n_IDStatic_ਰਸਤਾ,UINT uFiletype);
  WINUSERAPI ਪੂਰਨ WINAPI DlgDirListComboBoxW(HWND hDlg,LPWSTR lp_ਰਸਤਾ_Spec,ਪੂਰਨ nIDComboBox,ਪੂਰਨ n_IDStatic_ਰਸਤਾ,UINT uFiletype);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,ਪੂਰਨ cch_ਬਾਹਰਲਾ,ਪੂਰਨ idComboBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,ਪੂਰਨ cch_ਬਾਹਰਲਾ,ਪੂਰਨ idComboBox);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_ABSALIGN 0x01L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_SYSMODAL 0x02L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_LOCALEDIT 0x20L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_SETFONT 0x40L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_MODALFRAME 0x80L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_NOIDLEMSG 0x100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_SETFOREGROUND 0x200L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_3DLOOK 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_FIXEDSYS 0x0008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_NOFAILCREATE 0x0010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_CONTROL 0x0400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_CENTER 0x0800L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_CENTERMOUSE 0x1000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_CONTEXTHELP 0x2000L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#ਜੇ(_WIN32_WCE >= 0x0500)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DS_USEPIXELS 0x8000L
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_GETDEFID (WM_USER+0)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_SETDEFID (WM_USER+1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_REPOSITION (WM_USER+2)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_HASDEFID 0x534B

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_WANTARROWS 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_WANTTAB 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_WANTALLKEYS 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_WANTMESSAGE 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_HASSETSEL 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_DEFPUSHBUTTON 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_UNDEFPUSHBUTTON 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_RADIOBUTTON 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_WANTCHARS 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_STATIC 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DLGC_BUTTON 0x2000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_CTLCODE 0L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_OKAY 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_ERR (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_ERRSPACE (-2)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBN_ERRSPACE (-2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBN_SELCHANGE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBN_DBLCLK 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBN_SELCANCEL 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBN_SETFOCUS 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBN_KILLFOCUS 5

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINMESSAGES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_ADDSTRING 0x0180
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_INSERTSTRING 0x0181
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_DELETESTRING 0x0182
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SELITEMRANGEEX 0x0183
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_RESETCONTENT 0x0184
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETSEL 0x0185
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETCURSEL 0x0186
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETSEL 0x0187
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETCURSEL 0x0188
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETTEXT 0x0189
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETTEXTLEN 0x018A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETCOUNT 0x018B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SELECTSTRING 0x018C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_DIR 0x018D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETTOPINDEX 0x018E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_FINDSTRING 0x018F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETSELCOUNT 0x0190
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETSELITEMS 0x0191
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETTABSTOPS 0x0192
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETHORIZONTALEXTENT 0x0193
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETHORIZONTALEXTENT 0x0194
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETCOLUMNWIDTH 0x0195
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_ADDFILE 0x0196
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETTOPINDEX 0x0197
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETITEMRECT 0x0198
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETITEMDATA 0x0199
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETITEMDATA 0x019A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SELITEMRANGE 0x019B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETANCHORINDEX 0x019C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETANCHORINDEX 0x019D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETCARETINDEX 0x019E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETCARETINDEX 0x019F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETITEMHEIGHT 0x01A0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETITEMHEIGHT 0x01A1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_FINDSTRINGEXACT 0x01A2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETLOCALE 0x01A5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETLOCALE 0x01A6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_SETCOUNT 0x01A7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_INITSTORAGE 0x01A8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_ITEMFROMPOINT 0x01A9
#ਜੇ(_WIN32_WCE >= 0x0400)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_MULTIPLEADDSTRING 0x01B1
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_GETLISTBOXINFO 0x01B2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LB_MSGMAX 0x01B3
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINSTYLES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_NOTIFY 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_ਛਾਂਟੋ 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_NOREDRAW 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_MULTIPLESEL 0x0008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_OWNERDRAWFIXED 0x0010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_OWNERDRAWVARIABLE 0x0020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_HASSTRINGS 0x0040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_USETABSTOPS 0x0080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_NOINTEGRALHEIGHT 0x0100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_MULTICOLUMN 0x0200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_WANTKEYBOARDINPUT 0x0400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_EXTENDEDSEL 0x0800L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_DISABLENOSCROLL 0x1000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_NODATA 0x2000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_NOSEL 0x4000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_COMBOBOX 0x8000L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LBS_STANDARD (LBS_NOTIFY | LBS_ਛਾਂਟੋ | WS_VSCROLL | WS_BORDER)
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_OKAY 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_ERR (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_ERRSPACE (-2)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_ERRSPACE (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_SELCHANGE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_DBLCLK 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_SETFOCUS 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_KILLFOCUS 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_EDITCHANGE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_EDITUPDATE 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_DROPDOWN 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_CLOSEUP 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_SELENDOK 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBN_SELENDCANCEL 10

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINSTYLES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_SIMPLE 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_DROPDOWN 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_DROPDOWNLIST 0x0003L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_OWNERDRAWFIXED 0x0010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_OWNERDRAWVARIABLE 0x0020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_AUTOHSCROLL 0x0040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_OEMCONVERT 0x0080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_ਛਾਂਟੋ 0x0100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_HASSTRINGS 0x0200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_NOINTEGRALHEIGHT 0x0400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_DISABLENOSCROLL 0x0800L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_UPPERCASE 0x2000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBS_LOWERCASE 0x4000L
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINMESSAGES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETEDITSEL 0x0140
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_LIMITTEXT 0x0141
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SETEDITSEL 0x0142
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_ADDSTRING 0x0143
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_DELETESTRING 0x0144
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_DIR 0x0145
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETCOUNT 0x0146
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETCURSEL 0x0147
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETLBTEXT 0x0148
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETLBTEXTLEN 0x0149
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_INSERTSTRING 0x014A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_RESETCONTENT 0x014B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_FINDSTRING 0x014C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SELECTSTRING 0x014D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SETCURSEL 0x014E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SHOWDROPDOWN 0x014F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETITEMDATA 0x0150
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SETITEMDATA 0x0151
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETDROPPEDCONTROLRECT 0x0152
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SETITEMHEIGHT 0x0153
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETITEMHEIGHT 0x0154
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SETEXTENDEDUI 0x0155
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETEXTENDEDUI 0x0156
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETDROPPEDSTATE 0x0157
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_FINDSTRINGEXACT 0x0158
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SETLOCALE 0x0159
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETLOCALE 0x015A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETTOPINDEX 0x015b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SETTOPINDEX 0x015c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETHORIZONTALEXTENT 0x015d
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SETHORIZONTALEXTENT 0x015e
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETDROPPEDWIDTH 0x015f
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_SETDROPPEDWIDTH 0x0160
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_INITSTORAGE 0x0161
#ਜੇ(_WIN32_WCE >= 0x0400)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_MULTIPLEADDSTRING 0x0163
#ਜੇ_ਅੰਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_GETCOMBOBOXINFO 0x0164
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CB_MSGMAX 0x0165
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINSTYLES

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_HORZ 0x0000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_VERT 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_TOPALIGN 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_LEFTALIGN 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_BOTTOMALIGN 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_RIGHTALIGN 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_SIZEBOX 0x0008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBS_SIZEGRIP 0x0010L
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINMESSAGES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBM_SETPOS 0x00E0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBM_GETPOS 0x00E1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBM_SETRANGE 0x00E2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBM_SETRANGEREDRAW 0x00E6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBM_GETRANGE 0x00E3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBM_ENABLE_ARROWS 0x00E4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBM_SETSCROLLINFO 0x00E9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBM_GETSCROLLINFO 0x00EA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SBM_GETSCROLLBARINFO 0x00EB

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIF_RANGE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIF_ਪੰਨਾ 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIF_POS 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIF_DISABLENOSCROLL 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIF_TRACKPOS 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIF_ALL (SIF_RANGE | SIF_ਪੰਨਾ | SIF_POS | SIF_TRACKPOS)

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_SCROLLINFO {
    UINT cb_ਮਾਪ;
    UINT f_ਨਕਾਬ;
    ਪੂਰਨ nMin;
    ਪੂਰਨ nMax;
    UINT n_ਪੰਨਾ;
    ਪੂਰਨ nPos;
    ਪੂਰਨ nTrackPos;
  } SCROLLINFO,*LPSCROLLINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SCROLLINFO CONST *LPCSCROLLINFO;

  WINUSERAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Scroll_Info(HWND hwnd,ਪੂਰਨ nBar,LPCSCROLLINFO lpsi,WINBOOL redraw);
  WINUSERAPI WINBOOL WINAPI GetScrollInfo(HWND hwnd,ਪੂਰਨ nBar,LPSCROLLINFO lpsi);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMDI

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MDIS_ALLCHILDSTYLES 0x0001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MDITILE_VERTICAL 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MDITILE_HORIZONTAL 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MDITILE_SKIPDISABLED 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MDITILE_ZORDER 0x0004

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MDICREATESTRUCTA {
    LPCSTR szClass;
    LPCSTR szTitle;
    HANDLE hOwner;
    ਪੂਰਨ x;
    ਪੂਰਨ y;
    ਪੂਰਨ cx;
    ਪੂਰਨ cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTA,*LPMDICREATESTRUCTA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MDICREATESTRUCTW {
    LPCWSTR szClass;
    LPCWSTR szTitle;
    HANDLE hOwner;
    ਪੂਰਨ x;
    ਪੂਰਨ y;
    ਪੂਰਨ cx;
    ਪੂਰਨ cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTW,*LPMDICREATESTRUCTW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MDICREATESTRUCTW MDICREATESTRUCT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MDICREATESTRUCTA MDICREATESTRUCT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CLIENTCREATESTRUCT {
    HANDLE h_ਖਿੜਕੀ_Menu;
    UINT id_ਪਹਿਲਾ_ਬੱਚਾ;
  } CLIENTCREATESTRUCT,*LPCLIENTCREATESTRUCT;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Def_ਚੌਖਟਾ_Proc Def_ਚੌਖਟਾ_Proc_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DefMDIChildProc DefMDIChildProcW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateMDIWindow CreateMDIWindowW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Def_ਚੌਖਟਾ_Proc Def_ਚੌਖਟਾ_Proc_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DefMDIChildProc DefMDIChildProcA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateMDIWindow CreateMDIWindowA
#ਜੇ_ਅੰਤ

  WINUSERAPI LRESULT WINAPI Def_ਚੌਖਟਾ_Proc_A(HWND hWnd,HWND hWndMDIClient,UINT u_ਸੁਨੇਹਾ,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_ਚੌਖਟਾ_Proc_W(HWND hWnd,HWND hWndMDIClient,UINT u_ਸੁਨੇਹਾ,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcA(HWND hWnd,UINT u_ਸੁਨੇਹਾ,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcW(HWND hWnd,UINT u_ਸੁਨੇਹਾ,WPARAM wParam,LPARAM lParam);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMSG
  WINUSERAPI WINBOOL WINAPI TranslateMDISysAccel(HWND hWndClient,LPMSG lp_ਸੁਨੇਹਾ_2);
#ਜੇ_ਅੰਤ

  WINUSERAPI UINT WINAPI ArrangeIconicWindows(HWND hWnd);
  WINUSERAPI HWND WINAPI CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lp_ਖਿੜਕੀ_Name,DWORD dwStyle,ਪੂਰਨ X,ਪੂਰਨ Y,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ,HWND h_Wnd_ਮਾਪਾ,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI HWND WINAPI CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lp_ਖਿੜਕੀ_Name,DWORD dwStyle,ਪੂਰਨ X,ਪੂਰਨ Y,ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ,HWND h_Wnd_ਮਾਪਾ,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI ਸ਼ਬਦ_3 WINAPI TileWindows(HWND hwnd_ਮਾਪਾ_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ਅਚਲ HWND *lpKids);
  WINUSERAPI ਸ਼ਬਦ_3 WINAPI CascadeWindows(HWND hwnd_ਮਾਪਾ_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ਅਚਲ HWND *lpKids);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOHELP

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD HELPPOLY;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MULTIKEYHELPA {
    DWORD mk_ਮਾਪ;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
  } MULTIKEYHELPA,*PMULTIKEYHELPA,*LPMULTIKEYHELPA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MULTIKEYHELPW {
    DWORD mk_ਮਾਪ;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
  } MULTIKEYHELPW,*PMULTIKEYHELPW,*LPMULTIKEYHELPW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MULTIKEYHELPW MULTIKEYHELP;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PMULTIKEYHELPW PMULTIKEYHELP;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMULTIKEYHELPW LPMULTIKEYHELP;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MULTIKEYHELPA MULTIKEYHELP;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PMULTIKEYHELPA PMULTIKEYHELP;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMULTIKEYHELPA LPMULTIKEYHELP;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HELPWININFOA {
    ਪੂਰਨ w_Struct_ਮਾਪ;
    ਪੂਰਨ x;
    ਪੂਰਨ y;
    ਪੂਰਨ dx;
    ਪੂਰਨ dy;
    ਪੂਰਨ wMax;
    CHAR rgchMember[2];
  } HELPWININFOA,*PHELPWININFOA,*LPHELPWININFOA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HELPWININFOW {
    ਪੂਰਨ w_Struct_ਮਾਪ;
    ਪੂਰਨ x;
    ਪੂਰਨ y;
    ਪੂਰਨ dx;
    ਪੂਰਨ dy;
    ਪੂਰਨ wMax;
    WCHAR rgchMember[2];
  } HELPWININFOW,*PHELPWININFOW,*LPHELPWININFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HELPWININFOW HELPWININFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PHELPWININFOW PHELPWININFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPHELPWININFOW LPHELPWININFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HELPWININFOA HELPWININFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PHELPWININFOA PHELPWININFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPHELPWININFOA LPHELPWININFO;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_CONTEXT 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_QUIT 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_ਸੂਚਕਾਂਕ 0x0003L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_CONTENTS 0x0003L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_HELPONHELP 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_SETINDEX 0x0005L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_SETCONTENTS 0x0005L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_CONTEXTPOPUP 0x0008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_FORCEFILE 0x0009L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_ਕੁੰਜੀ 0x0101L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_COMMAND 0x0102L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_PARTIALKEY 0x0105L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_MULTIKEY 0x0201L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_SETWINPOS 0x0203L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_CONTEXTMENU 0x000a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_FINDER 0x000b
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_WM_HELP 0x000c
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_SETPOPUP_POS 0x000d

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_TCARD 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_TCARD_ਅੰਕੜੇ 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HELP_TCARD_OTHER_CALLER 0x0011

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDH_NO_HELP 28440
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDH_MISSING_CONTEXT 28441
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDH_GENERIC_HELP_BUTTON 28442
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDH_OK 28443
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDH_CANCEL 28444
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ IDH_HELP 28445

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WinHelp WinHelpW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WinHelp WinHelpA
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dw_ਅੰਕੜੇ);
  WINUSERAPI WINBOOL WINAPI WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dw_ਅੰਕੜੇ);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GR_GDIOBJECTS 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GR_USEROBJECTS 1

  WINUSERAPI DWORD WINAPI GetGuiResources(HANDLE hProcess,DWORD uiFlags);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOSYSPARAMSINFO

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETBEEP 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETBEEP 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSE 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSE 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETBORDER 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETBORDER 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETKEYBOARDSPEED 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETKEYBOARDSPEED 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_LANGDRIVER 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_ICONHORIZONTALSPACING 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSCREENSAVETIMEOUT 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSCREENSAVETIMEOUT 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSCREENSAVEACTIVE 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSCREENSAVEACTIVE 0x0011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETGRIDGRANULARITY 0x0012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETGRIDGRANULARITY 0x0013
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDESKWALLPAPER 0x0014
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDESKPATTERN 0x0015
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETKEYBOARDDELAY 0x0016
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETKEYBOARDDELAY 0x0017
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_ICONVERTICALSPACING 0x0018
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETICONTITLEWRAP 0x0019
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETICONTITLEWRAP 0x001A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMENUDROPALIGNMENT 0x001B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMENUDROPALIGNMENT 0x001C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDOUBLECLKWIDTH 0x001D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDOUBLECLKHEIGHT 0x001E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETICONTITLELOGFONT 0x001F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDOUBLECLICKTIME 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSEBUTTONSWAP 0x0021
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETICONTITLELOGFONT 0x0022
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFASTTASKSWITCH 0x0023
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFASTTASKSWITCH 0x0024
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDRAGFULLWINDOWS 0x0025
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETDRAGFULLWINDOWS 0x0026
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETNONCLIENTMETRICS 0x0029
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETNONCLIENTMETRICS 0x002A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMINIMIZEDMETRICS 0x002B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMINIMIZEDMETRICS 0x002C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETICONMETRICS 0x002D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETICONMETRICS 0x002E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETWORKAREA 0x002F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETWORKAREA 0x0030
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETPENWINDOWS 0x0031

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETHIGHCONTRAST 0x0042
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETHIGHCONTRAST 0x0043
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETKEYBOARDPREF 0x0044
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETKEYBOARDPREF 0x0045
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSCREENREADER 0x0046
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSCREENREADER 0x0047
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETANIMATION 0x0048
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETANIMATION 0x0049
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFONTSMOOTHING 0x004A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFONTSMOOTHING 0x004B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDRAGWIDTH 0x004C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDRAGHEIGHT 0x004D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETHANDHELD 0x004E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETLOWPOWERTIMEOUT 0x004F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETPOWEROFFTIMEOUT 0x0050
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETLOWPOWERTIMEOUT 0x0051
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETPOWEROFFTIMEOUT 0x0052
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETLOWPOWERACTIVE 0x0053
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETPOWEROFFACTIVE 0x0054
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETLOWPOWERACTIVE 0x0055
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETPOWEROFFACTIVE 0x0056
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETCURSORS 0x0057
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETICONS 0x0058
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETDEFAULTINPUTLANG 0x0059
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDEFAULTINPUTLANG 0x005A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETLANGTOGGLE 0x005B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETWINDOWSEXTENSION 0x005C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSETRAILS 0x005D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSETRAILS 0x005E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSCREENSAVERRUNNING 0x0061
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFILTERKEYS 0x0032
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFILTERKEYS 0x0033
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETTOGGLEKEYS 0x0034
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETTOGGLEKEYS 0x0035
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSEKEYS 0x0036
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSEKEYS 0x0037
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSHOWSOUNDS 0x0038
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSHOWSOUNDS 0x0039
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSTICKYKEYS 0x003A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSTICKYKEYS 0x003B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETACCESSTIMEOUT 0x003C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETACCESSTIMEOUT 0x003D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSERIALKEYS 0x003E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSERIALKEYS 0x003F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSOUNDSENTRY 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSOUNDSENTRY 0x0041
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSNAPTODEFBUTTON 0x005F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSNAPTODEFBUTTON 0x0060
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSEHOVERWIDTH 0x0062
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSEHOVERWIDTH 0x0063
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSEHOVERHEIGHT 0x0064
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSEHOVERHEIGHT 0x0065
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSEHOVERTIME 0x0066
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSEHOVERTIME 0x0067
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETWHEELSCROLLLINES 0x0068
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETWHEELSCROLLLINES 0x0069
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMENUSHOWDELAY 0x006A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMENUSHOWDELAY 0x006B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSHOWIMEUI 0x006E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSHOWIMEUI 0x006F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSESPEED 0x0070
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSESPEED 0x0071
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSCREENSAVERRUNNING 0x0072
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETDESKWALLPAPER 0x0073

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETACTIVEWINDOWTRACKING 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETACTIVEWINDOWTRACKING 0x1001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMENUANIMATION 0x1002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMENUANIMATION 0x1003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETCOMBOBOXANIMATION 0x1004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETCOMBOBOXANIMATION 0x1005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETGRADIENTCAPTIONS 0x1008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETGRADIENTCAPTIONS 0x1009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETKEYBOARDCUES 0x100A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETKEYBOARDCUES 0x100B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETACTIVEWNDTRKZORDER 0x100C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETACTIVEWNDTRKZORDER 0x100D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETHOTTRACKING 0x100E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETHOTTRACKING 0x100F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMENUFADE 0x1012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMENUFADE 0x1013
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETSELECTIONFADE 0x1014
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETSELECTIONFADE 0x1015
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETTOOLTIPANIMATION 0x1016
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETTOOLTIPANIMATION 0x1017
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETTOOLTIPFADE 0x1018
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETTOOLTIPFADE 0x1019
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETCURSORSHADOW 0x101A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETCURSORSHADOW 0x101B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSESONAR 0x101C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSESONAR 0x101D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSECLICKLOCK 0x101E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSECLICKLOCK 0x101F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSEVANISH 0x1020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSEVANISH 0x1021
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFLATMENU 0x1022
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFLATMENU 0x1023
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETDROPSHADOW 0x1024
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETDROPSHADOW 0x1025
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETBLOCKSENDINPUTRESETS 0x1026
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETBLOCKSENDINPUTRESETS 0x1027
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETUIEFFECTS 0x103E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETUIEFFECTS 0x103F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETCARETWIDTH 0x2006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETCARETWIDTH 0x2007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETMOUSECLICKLOCKTIME 0x2008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETMOUSECLICKLOCKTIME 0x2009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFONTSMOOTHINGTYPE 0x200A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFONTSMOOTHINGTYPE 0x200B

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_FONTSMOOTHINGSTANDARD 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_FONTSMOOTHINGCLEARTYPE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_FONTSMOOTHINGDOCKING 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFOCUSBORDERWIDTH 0x200E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFOCUSBORDERWIDTH 0x200F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFOCUSBORDERHEIGHT 0x2010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFOCUSBORDERHEIGHT 0x2011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPIF_UPDATEINIFILE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPIF_SENDWININICHANGE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ METRICS_USEDEFAULT -1
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WINGDI_
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOGDI
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_NONCLIENTMETRICSA {
    UINT cb_ਮਾਪ;
    ਪੂਰਨ i_Border_ਚੌੜਾਈ;
    ਪੂਰਨ i_Scroll_ਚੌੜਾਈ;
    ਪੂਰਨ i_Scroll_ਉਚਾਈ;
    ਪੂਰਨ i_Caption_ਚੌੜਾਈ;
    ਪੂਰਨ i_Caption_ਉਚਾਈ;
    LOGFONTA lfCaptionFont;
    ਪੂਰਨ i_Sm_Caption_ਚੌੜਾਈ;
    ਪੂਰਨ i_Sm_Caption_ਉਚਾਈ;
    LOGFONTA lfSmCaptionFont;
    ਪੂਰਨ i_Menu_ਚੌੜਾਈ;
    ਪੂਰਨ i_Menu_ਉਚਾਈ;
    LOGFONTA lfMenuFont;
    LOGFONTA lf_ਸਥਿਤੀ_Font;
    LOGFONTA lf_ਸੁਨੇਹਾ_Font;
  } NONCLIENTMETRICSA,*PNONCLIENTMETRICSA,*LPNONCLIENTMETRICSA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_NONCLIENTMETRICSW {
    UINT cb_ਮਾਪ;
    ਪੂਰਨ i_Border_ਚੌੜਾਈ;
    ਪੂਰਨ i_Scroll_ਚੌੜਾਈ;
    ਪੂਰਨ i_Scroll_ਉਚਾਈ;
    ਪੂਰਨ i_Caption_ਚੌੜਾਈ;
    ਪੂਰਨ i_Caption_ਉਚਾਈ;
    LOGFONTW lfCaptionFont;
    ਪੂਰਨ i_Sm_Caption_ਚੌੜਾਈ;
    ਪੂਰਨ i_Sm_Caption_ਉਚਾਈ;
    LOGFONTW lfSmCaptionFont;
    ਪੂਰਨ i_Menu_ਚੌੜਾਈ;
    ਪੂਰਨ i_Menu_ਉਚਾਈ;
    LOGFONTW lfMenuFont;
    LOGFONTW lf_ਸਥਿਤੀ_Font;
    LOGFONTW lf_ਸੁਨੇਹਾ_Font;
  } NONCLIENTMETRICSW,*PNONCLIENTMETRICSW,*LPNONCLIENTMETRICSW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NONCLIENTMETRICSW NONCLIENTMETRICS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PNONCLIENTMETRICSW PNONCLIENTMETRICS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NONCLIENTMETRICSA NONCLIENTMETRICS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PNONCLIENTMETRICSA PNONCLIENTMETRICS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_BOTTOMLEFT 0x0000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_BOTTOMRIGHT 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_TOPLEFT 0x0002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_TOPRIGHT 0x0003L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_STARTMASK 0x0003L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_STARTRIGHT 0x0001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_STARTTOP 0x0002L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_ਖੱਬਾ 0x0000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_ਸੱਜਾ 0x0000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_ਉੱਪਰ 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_ਥੱਲੇ 0x0004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARW_HIDE 0x0008L

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MINIMIZEDMETRICS {
    UINT cb_ਮਾਪ;
    ਪੂਰਨ i_ਚੌੜਾਈ;
    ਪੂਰਨ iHorzGap;
    ਪੂਰਨ iVertGap;
    ਪੂਰਨ iArrange;
  } MINIMIZEDMETRICS,*PMINIMIZEDMETRICS,*LPMINIMIZEDMETRICS;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WINGDI_
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOGDI
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ICONMETRICSA {
    UINT cb_ਮਾਪ;
    ਪੂਰਨ iHorzSpacing;
    ਪੂਰਨ iVertSpacing;
    ਪੂਰਨ iTitleWrap;
    LOGFONTA lfFont;
  } ICONMETRICSA,*PICONMETRICSA,*LPICONMETRICSA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ICONMETRICSW {
    UINT cb_ਮਾਪ;
    ਪੂਰਨ iHorzSpacing;
    ਪੂਰਨ iVertSpacing;
    ਪੂਰਨ iTitleWrap;
    LOGFONTW lfFont;
  } ICONMETRICSW,*PICONMETRICSW,*LPICONMETRICSW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ICONMETRICSW ICONMETRICS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PICONMETRICSW PICONMETRICS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPICONMETRICSW LPICONMETRICS;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ICONMETRICSA ICONMETRICS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PICONMETRICSA PICONMETRICS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPICONMETRICSA LPICONMETRICS;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ANIMATIONINFO {
    UINT cb_ਮਾਪ;
    ਪੂਰਨ iMinAnimate;
  } ANIMATIONINFO,*LPANIMATIONINFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_SERIALKEYSA {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
    LPSTR lpsz_ਸਰਗਰਮ_ਪੋਰਟ;
    LPSTR lpsz_ਪੋਰਟ;
    UINT i_Baud_ਦਰ;
    UINT i_ਪੋਰਟ_State;
    UINT i_ਸਰਗਰਮ;
  } SERIALKEYSA,*LPSERIALKEYSA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_SERIALKEYSW {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
    LPWSTR lpsz_ਸਰਗਰਮ_ਪੋਰਟ;
    LPWSTR lpsz_ਪੋਰਟ;
    UINT i_Baud_ਦਰ;
    UINT i_ਪੋਰਟ_State;
    UINT i_ਸਰਗਰਮ;
  } SERIALKEYSW,*LPSERIALKEYSW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SERIALKEYSW SERIALKEYS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPSERIALKEYSW LPSERIALKEYS;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SERIALKEYSA SERIALKEYS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPSERIALKEYSA LPSERIALKEYS;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERKF_SERIALKEYSON 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERKF_ਉਪਲਬਧ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SERKF_INDICATOR 0x00000004

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HIGHCONTRASTA {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
  } HIGHCONTRASTA,*LPHIGHCONTRASTA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HIGHCONTRASTW {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
  } HIGHCONTRASTW,*LPHIGHCONTRASTW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HIGHCONTRASTW HIGHCONTRAST;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPHIGHCONTRASTW LPHIGHCONTRAST;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ HIGHCONTRASTA HIGHCONTRAST;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPHIGHCONTRASTA LPHIGHCONTRAST;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCF_HIGHCONTRASTON 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCF_ਉਪਲਬਧ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCF_HOTKEYACTIVE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCF_CONFIRMHOTKEY 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCF_HOTKEYSOUND 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCF_INDICATOR 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCF_HOTKEYAVAILABLE 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCF_LOGONDESKTOP 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HCF_DEFAULTDESKTOP 0x00000200

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CDS_UPDATEREGISTRY 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CDS_TEST 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CDS_FULLSCREEN 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CDS_GLOBAL 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CDS_ਸੈੱਟ_PRIMARY 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CDS_VIDEOPARAMETERS 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CDS_RESET 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CDS_NORESET 0x10000000

//gr #include <tvout.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISP_CHANGE_SUCCESSFUL 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISP_CHANGE_RESTART 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISP_CHANGE_FAILED -1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISP_CHANGE_BADMODE -2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISP_CHANGE_NOTUPDATED -3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISP_CHANGE_BADFLAGS -4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISP_CHANGE_BADPARAM -5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISP_CHANGE_BADDUALVIEW -6

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WINGDI_
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOGDI

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ChangeDisplaySettings ChangeDisplaySettingsW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumDisplaySettings EnumDisplaySettingsW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumDisplaySettingsEx EnumDisplaySettingsExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumDisplayDevices EnumDisplayDevicesW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ChangeDisplaySettings ChangeDisplaySettingsA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumDisplaySettings EnumDisplaySettingsA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumDisplaySettingsEx EnumDisplaySettingsExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumDisplayDevices EnumDisplayDevicesA
#ਜੇ_ਅੰਤ

  WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lp_Dev_ਬਹੁਲਕ,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsW(LPDEVMODEW lp_Dev_ਬਹੁਲਕ,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,LPDEVMODEA lp_Dev_ਬਹੁਲਕ,HWND hwnd,DWORD dwflags,LPVOID lParam);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,LPDEVMODEW lp_Dev_ਬਹੁਲਕ,HWND hwnd,DWORD dwflags,LPVOID lParam);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUM_CURRENT_SETTINGS ((DWORD)-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUM_REGISTRY_SETTINGS ((DWORD)-2)

  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD i_ਬਹੁਲਕ_ਅੰਕ,LPDEVMODEA lp_Dev_ਬਹੁਲਕ);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD i_ਬਹੁਲਕ_ਅੰਕ,LPDEVMODEW lp_Dev_ਬਹੁਲਕ);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD i_ਬਹੁਲਕ_ਅੰਕ,LPDEVMODEA lp_Dev_ਬਹੁਲਕ,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD i_ਬਹੁਲਕ_ਅੰਕ,LPDEVMODEW lp_Dev_ਬਹੁਲਕ,DWORD dwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EDS_RAWMODE 0x00000002

  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesA(LPCSTR lpDevice,DWORD i_Dev_ਅੰਕ,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD i_Dev_ਅੰਕ,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SystemParametersInfo SystemParametersInfoW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SystemParametersInfo SystemParametersInfoA
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
  WINUSERAPI WINBOOL WINAPI SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_FILTERKEYS {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
  } FILTERKEYS,*LPFILTERKEYS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FKF_FILTERKEYSON 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FKF_ਉਪਲਬਧ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FKF_HOTKEYACTIVE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FKF_CONFIRMHOTKEY 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FKF_HOTKEYSOUND 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FKF_INDICATOR 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FKF_CLICKON 0x00000040

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_STICKYKEYS {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
  } STICKYKEYS,*LPSTICKYKEYS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_STICKYKEYSON 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_ਉਪਲਬਧ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_HOTKEYACTIVE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_CONFIRMHOTKEY 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_HOTKEYSOUND 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_INDICATOR 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_AUDIBLEFEEDBACK 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_TRISTATE 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_TWOKEYSOFF 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_LALTLATCHED 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_LCTLLATCHED 0x04000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_LSHIFTLATCHED 0x01000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_RALTLATCHED 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_RCTLLATCHED 0x08000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_RSHIFTLATCHED 0x02000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_LWINLATCHED 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_RWINLATCHED 0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_LALTLOCKED 0x00100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_LCTLLOCKED 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_LSHIFTLOCKED 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_RALTLOCKED 0x00200000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_RCTLLOCKED 0x00080000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_RSHIFTLOCKED 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_LWINLOCKED 0x00400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SKF_RWINLOCKED 0x00800000

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MOUSEKEYS {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
    DWORD i_Max_ਰਫਤਾਰ;
    DWORD i_ਸਮਾਂ_ਮੰਜ਼ਿਲ_Max_ਰਫਤਾਰ;
    DWORD i_Ctrl_ਰਫਤਾਰ;
    DWORD dwReserved1;
    DWORD dwReserved2;
  } MOUSEKEYS,*LPMOUSEKEYS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_MOUSEKEYSON 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_ਉਪਲਬਧ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_HOTKEYACTIVE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_CONFIRMHOTKEY 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_HOTKEYSOUND 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_INDICATOR 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_MODIFIERS 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_REPLACENUMBERS 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_LEFTBUTTONSEL 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_RIGHTBUTTONSEL 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_LEFTBUTTONDOWN 0x01000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_RIGHTBUTTONDOWN 0x02000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKF_MOUSEMODE 0x80000000

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ACCESSTIMEOUT {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
    DWORD i_ਸਮਾਂ_ਬਾਹਰਲਾ_MSec;
  } ACCESSTIMEOUT,*LPACCESSTIMEOUT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATF_TIMEOUTON 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ATF_ONOFFFEEDBACK 0x00000002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSGF_NONE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSGF_DISPLAY 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSTF_NONE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSTF_CHARS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSTF_BORDER 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSTF_DISPLAY 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSWF_NONE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSWF_TITLE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSWF_ਖਿੜਕੀ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSWF_DISPLAY 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSWF_CUSTOM 4

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_SOUNDSENTRYA {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_ਬਿੱਟ;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYA,*LPSOUNDSENTRYA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_SOUNDSENTRYW {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_ਬਿੱਟ;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYW,*LPSOUNDSENTRYW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SOUNDSENTRYW SOUNDSENTRY;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPSOUNDSENTRYW LPSOUNDSENTRY;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ SOUNDSENTRYA SOUNDSENTRY;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPSOUNDSENTRYA LPSOUNDSENTRY;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSF_SOUNDSENTRYON 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSF_ਉਪਲਬਧ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SSF_INDICATOR 0x00000004

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_TOGGLEKEYS {
    UINT cb_ਮਾਪ;
    DWORD dwFlags;
  } TOGGLEKEYS,*LPTOGGLEKEYS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TKF_TOGGLEKEYSON 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TKF_ਉਪਲਬਧ 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TKF_HOTKEYACTIVE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TKF_CONFIRMHOTKEY 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TKF_HOTKEYSOUND 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TKF_INDICATOR 0x00000020

  WINUSERAPI VOID WINAPI ਸੈੱਟ_Debug_Error_Level(DWORD dwLevel);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SLE_ERROR 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SLE_MINORERROR 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SLE_WARNING 0x00000003

  WINUSERAPI VOID WINAPI ਸੈੱਟ_ਆਖਰੀ_Error_Ex(DWORD dw_Err_ਕੋਡ,DWORD dwType);
  WINUSERAPI ਪੂਰਨ WINAPI ਅੰਦਰੂਨੀ_Get_ਖਿੜਕੀ_ਪਾਠ(HWND hWnd,LPWSTR pString,ਪੂਰਨ cch_Max_ਗਿਣਤੀ);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ WINNT
  WINUSERAPI WINBOOL WINAPI ਸਿਰਾ_Task(HWND hWnd,WINBOOL f_Shut_ਥੱਲੇ,WINBOOL fForce);
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MONITOR_DEFAULTTONULL 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MONITOR_DEFAULTTOPRIMARY 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MONITOR_DEFAULTTONEAREST 0x00000002

  WINUSERAPI HMONITOR WINAPI Monitor_From_ਬਿੰਦੂ(ਬਿੰਦੂ_3 pt,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromRect(LPCRECT lprc,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI Monitor_From_ਖਿੜਕੀ(HWND hwnd,DWORD dwFlags);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MONITORINFOF_PRIMARY 0x00000001

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ CCHDEVICENAME
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CCHDEVICENAME 32
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MONITORINFO {
    DWORD cb_ਮਾਪ;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
  } MONITORINFO,*LPMONITORINFO;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MONITORINFOEXA : ਜਨਤਕ ਟੈਗ_MONITORINFO {
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MONITORINFOEXW : ਜਨਤਕ ਟੈਗ_MONITORINFO {
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MONITORINFOEXW MONITORINFOEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMONITORINFOEXW LPMONITORINFOEX;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MONITORINFOEXA MONITORINFOEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMONITORINFOEXA LPMONITORINFOEX;
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MONITORINFOEXA {
    MONITORINFO mi;
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MONITORINFOEXW {
    MONITORINFO mi;
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MONITORINFOEXW MONITORINFOEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMONITORINFOEXW LPMONITORINFOEX;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ MONITORINFOEXA MONITORINFOEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPMONITORINFOEXA LPMONITORINFOEX;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE 
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetMonitorInfo GetMonitorInfoW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetMonitorInfo GetMonitorInfoA
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
  WINUSERAPI WINBOOL WINAPI GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

  WINUSERAPI WINBOOL WINAPI EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dw_ਅੰਕੜੇ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOWINABLE
  WINUSERAPI VOID WINAPI NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG id_ਬੱਚਾ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK hWinEventHook,DWORD event,HWND hwnd,LONG idObject,LONG id_ਬੱਚਾ,DWORD idEventThread,DWORD dwms_Event_ਸਮਾਂ);

  WINUSERAPI HWINEVENTHOOK WINAPI ਸੈੱਟ_Win_Event_Hook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI IsWinEventHookInstalled(DWORD event);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINEVENT_OUTOFCONTEXT 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINEVENT_SKIPOWNTHREAD 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINEVENT_SKIPOWNPROCESS 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINEVENT_INCONTEXT 0x0004

  WINUSERAPI WINBOOL WINAPI UnhookWinEvent(HWINEVENTHOOK hWinEventHook);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHILDID_SELF 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INDEXID_OBJECT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ INDEXID_CONTAINER 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_ਖਿੜਕੀ ((LONG)0x00000000)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_MENU ((LONG)0xFFFFFFFD)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_CLIENT ((LONG)0xFFFFFFFC)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_CARET ((LONG)0xFFFFFFF8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_CURSOR ((LONG)0xFFFFFFF7)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_ALERT ((LONG)0xFFFFFFF6)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_SOUND ((LONG)0xFFFFFFF5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_MIN 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_MAX 0x7FFFFFFF

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_SOUND 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_ALERT 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_FOREGROUND 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_MENUSTART 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_MENUEND 0x0005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_MENUPOPUPEND 0x0007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_CAPTURESTART 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_CAPTUREEND 0x0009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_MOVESIZESTART 0x000A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_MOVESIZEEND 0x000B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_DRAGDROPSTART 0x000E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_DRAGDROPEND 0x000F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_DIALOGSTART 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_DIALOGEND 0x0011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_SCROLLINGSTART 0x0012
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_SCROLLINGEND 0x0013
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_SWITCHSTART 0x0014
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_SWITCHEND 0x0015
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_MINIMIZESTART 0x0016
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_SYSTEM_MINIMIZEEND 0x0017

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_CONSOLE_CARET 0x4001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_CONSOLE_UPDATE_REGION 0x4002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_CONSOLE_LAYOUT 0x4005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_CONSOLE_ਸ਼ੁਰੂ_APPLICATION 0x4006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_CONSOLE_ਸਿਰਾ_APPLICATION 0x4007

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_APPLICATION_16_ਦੋਆਧਾਰੀ_ਅੰਕ 0x0001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_CARET_SELECTION 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONSOLE_CARET_VISIBLE 0x0002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_CREATE 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_DESTROY 0x8001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_SHOW 0x8002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_HIDE 0x8003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_REORDER 0x8004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_FOCUS 0x8005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_SELECTION 0x8006
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_SELECTIONADD 0x8007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_SELECTIONREMOVE 0x8008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_SELECTIONWITHIN 0x8009

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_STATECHANGE 0x800A

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_LOCATIONCHANGE 0x800B

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_NAMECHANGE 0x800C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_VALUECHANGE 0x800E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_PARENTCHANGE 0x800F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_HELPCHANGE 0x8010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EVENT_OBJECT_ACCELERATORCHANGE 0x8012

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_STARTUP 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_SHUTDOWN 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_BEEP 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_ERROR 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_QUESTION 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_WARNING 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_INFORMATION 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_MAXIMIZE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_MINIMIZE 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_RESTOREUP 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_RESTOREDOWN 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_APPSTART 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_FAULT 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_APPEND 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_MENUCOMMAND 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SOUND_SYSTEM_MENUPOPUP 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CSOUND_SYSTEM 16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALERT_SYSTEM_INFORMATIONAL 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALERT_SYSTEM_WARNING 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALERT_SYSTEM_ERROR 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALERT_SYSTEM_QUERY 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALERT_SYSTEM_CRITICAL 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CALERT_SYSTEM 6

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_GUITHREADINFO {
    DWORD cb_ਮਾਪ;
    DWORD flags;
    HWND hwnd_ਸਰਗਰਮ;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwnd_Move_ਮਾਪ;
    HWND hwndCaret;
    RECT rcCaret;
  } GUITHREADINFO,*PGUITHREADINFO,*LPGUITHREADINFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GUI_CARETBLINKING 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GUI_INMOVESIZE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GUI_INMENUMODE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GUI_SYSTEMMENUMODE 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GUI_POPUPMENUMODE 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GUI_16BITTASK 0x00000020

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Module_File_Name Get_ਖਿੜਕੀ_Module_File_Name_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਖਿੜਕੀ_Module_File_Name Get_ਖਿੜਕੀ_Module_File_Name_A
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui);
  WINUSERAPI UINT WINAPI Get_ਖਿੜਕੀ_Module_File_Name_A(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
  WINUSERAPI UINT WINAPI Get_ਖਿੜਕੀ_Module_File_Name_W(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NO_STATE_FLAGS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_UNAVAILABLE 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_SELECTED 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_FOCUSED 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_PRESSED 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_CHECKED 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_MIXED 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_READONLY 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_HOTTRACKED 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_DEFAULT 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_EXPANDED 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_COLLAPSED 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_BUSY 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_FLOATING 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_MARQUEED 0x00002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_ANIMATED 0x00004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_INVISIBLE 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_OFFSCREEN 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_SIZEABLE 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_MOVEABLE 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_SELFVOICING 0x00080000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_FOCUSABLE 0x00100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_SELECTABLE 0x00200000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_LINKED 0x00400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_TRAVERSED 0x00800000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_MULTISELECTABLE 0x01000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_EXTSELECTABLE 0x02000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_ALERT_ਨੀਵਾਂ 0x04000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_ALERT_ਉੱਚਾ 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_PROTECTED 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STATE_SYSTEM_VALID 0x3FFFFFFF
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CCHILDREN_TITLEBAR 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CCHILDREN_SCROLLBAR 5

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CURSORINFO {
    DWORD cb_ਮਾਪ;
    DWORD flags;
    HCURSOR hCursor;
    ਬਿੰਦੂ_3 ptScreenPos;
  } CURSORINFO,*PCURSORINFO,*LPCURSORINFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CURSOR_SHOWING 0x00000001

  WINUSERAPI WINBOOL WINAPI GetCursorInfo(PCURSORINFO pci);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_WINDOWINFO {
    DWORD cb_ਮਾਪ;
    RECT rc_ਖਿੜਕੀ;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dw_ਖਿੜਕੀ_ਸਥਿਤੀ;
    UINT cx_ਖਿੜਕੀ_Borders;
    UINT cy_ਖਿੜਕੀ_Borders;
    ATOM atom_ਖਿੜਕੀ_Type;
    ਸ਼ਬਦ_3 w_Creator_ਸੰਸਕਰਣ;
  } WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WS_ACTIVECAPTION 0x0001

  WINUSERAPI WINBOOL WINAPI Get_ਖਿੜਕੀ_Info(HWND hwnd,PWINDOWINFO pwi);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_TITLEBARINFO {
    DWORD cb_ਮਾਪ;
    RECT rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  } TITLEBARINFO,*PTITLEBARINFO,*LPTITLEBARINFO;

  WINUSERAPI WINBOOL WINAPI GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_MENUBARINFO {
    DWORD cb_ਮਾਪ;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    WINBOOL fBarFocused:1;
    WINBOOL fFocused:1;
  } MENUBARINFO,*PMENUBARINFO,*LPMENUBARINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuBarInfo(HWND hwnd,LONG idObject,LONG id_ਵਸਤੂ,PMENUBARINFO pmbi);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_SCROLLBARINFO {
    DWORD cb_ਮਾਪ;
    RECT rcScrollBar;
    ਪੂਰਨ dxy_ਸਤਰ_Button;
    ਪੂਰਨ xy_Thumb_ਸਿਖਰ;
    ਪੂਰਨ xyThumbBottom;
    ਪੂਰਨ reserved;
    DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
  } SCROLLBARINFO,*PSCROLLBARINFO,*LPSCROLLBARINFO;

  WINUSERAPI WINBOOL WINAPI GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_COMBOBOXINFO {
    DWORD cb_ਮਾਪ;
    RECT rc_ਵਸਤੂ;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwnd_ਵਸਤੂ;
    HWND hwndList;
  } COMBOBOXINFO,*PCOMBOBOXINFO,*LPCOMBOBOXINFO;

  WINUSERAPI WINBOOL WINAPI GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GA_ਮਾਪਾ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GA_ਜੜ੍ਹ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GA_ROOTOWNER 3

  WINUSERAPI HWND WINAPI GetAncestor(HWND hwnd,UINT gaFlags);
  WINUSERAPI HWND WINAPI Real_ਬੱਚਾ_ਖਿੜਕੀ_From_ਬਿੰਦੂ(HWND hwnd_ਮਾਪਾ_2,ਬਿੰਦੂ_3 pt_ਮਾਪਾ_Client_Coords);
  WINUSERAPI UINT WINAPI Real_Get_ਖਿੜਕੀ_Class_A(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
  WINUSERAPI UINT WINAPI Real_Get_ਖਿੜਕੀ_Class_W(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Real_Get_ਖਿੜਕੀ_Class Real_Get_ਖਿੜਕੀ_Class_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Real_Get_ਖਿੜਕੀ_Class Real_Get_ਖਿੜਕੀ_Class_A
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ALTTABINFO {
    DWORD cb_ਮਾਪ;
    ਪੂਰਨ c_ਚੀਜ਼ਾਂ;
    ਪੂਰਨ cColumns;
    ਪੂਰਨ c_ਪੰਕਤੀਆਂ;
    ਪੂਰਨ i_ਖਾਨਾ_Focus;
    ਪੂਰਨ i_ਪੰਕਤੀ_Focus;
    ਪੂਰਨ cx_ਵਸਤੂ;
    ਪੂਰਨ cy_ਵਸਤੂ;
    ਬਿੰਦੂ_3 pt_ਸ਼ੁਰੂ;
  } ALTTABINFO,*PALTTABINFO,*LPALTTABINFO;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetAltTabInfo GetAltTabInfoW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetAltTabInfo GetAltTabInfoA
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI GetAltTabInfoA(HWND hwnd,ਪੂਰਨ i_ਵਸਤੂ,PALTTABINFO pati,LPSTR psz_ਵਸਤੂ_ਪਾਠ,UINT cch_ਵਸਤੂ_ਪਾਠ);
  WINUSERAPI WINBOOL WINAPI GetAltTabInfoW(HWND hwnd,ਪੂਰਨ i_ਵਸਤੂ,PALTTABINFO pati,LPWSTR psz_ਵਸਤੂ_ਪਾਠ,UINT cch_ਵਸਤੂ_ਪਾਠ);
  WINUSERAPI DWORD WINAPI GetListBoxInfo(HWND hwnd);
#ਜੇ_ਅੰਤ

  WINUSERAPI WINBOOL WINAPI ਤਾਲਾ_Work_Station(VOID);
  WINUSERAPI WINBOOL WINAPI UserHandleGrantAccess(HANDLE hUserHandle,HANDLE h_ਕੰਮ,WINBOOL bGrant);

  DECLARE_HANDLE(HRAWINPUT);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_RAWINPUT_ਕੋਡ_WPARAM(wParam) ((wParam) & 0xff)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIM_ਨਿਵੇਸ਼ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIM_INPUTSINK 1

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RAWINPUTHEADER {
    DWORD dwType;
    DWORD dw_ਮਾਪ;
    HANDLE hDevice;
    WPARAM wParam;
  } RAWINPUTHEADER,*PRAWINPUTHEADER,*LPRAWINPUTHEADER;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIM_TYPEMOUSE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIM_TYPEKEYBOARD 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIM_TYPEHID 2

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RAWMOUSE {
    USHORT usFlags;
    ਸੰਘ {
      ULONG ulButtons;
      ਬਣਤਰ {
	USHORT usButtonFlags;
	USHORT us_Button_ਅੰਕੜੇ;
      };
    };
    ULONG ulRawButtons;
    LONG l_ਆਖਰੀ_X;
    LONG l_ਆਖਰੀ_Y;
    ULONG ulExtraInformation;
  } RAWMOUSE,*PRAWMOUSE,*LPRAWMOUSE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_ਖੱਬਾ_BUTTON_ਥੱਲੇ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_ਖੱਬਾ_BUTTON_ਉੱਪਰ 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_ਸੱਜਾ_BUTTON_ਥੱਲੇ 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_ਸੱਜਾ_BUTTON_ਉੱਪਰ 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_ਵਿਚਕਾਰ_BUTTON_ਥੱਲੇ 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_ਵਿਚਕਾਰ_BUTTON_ਉੱਪਰ 0x0020

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_1_ਥੱਲੇ RI_MOUSE_ਖੱਬਾ_BUTTON_ਥੱਲੇ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_1_ਉੱਪਰ RI_MOUSE_ਖੱਬਾ_BUTTON_ਉੱਪਰ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_2_ਥੱਲੇ RI_MOUSE_ਸੱਜਾ_BUTTON_ਥੱਲੇ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_2_ਉੱਪਰ RI_MOUSE_ਸੱਜਾ_BUTTON_ਉੱਪਰ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_3_ਥੱਲੇ RI_MOUSE_ਵਿਚਕਾਰ_BUTTON_ਥੱਲੇ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_3_ਉੱਪਰ RI_MOUSE_ਵਿਚਕਾਰ_BUTTON_ਉੱਪਰ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_4_ਥੱਲੇ 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_4_ਉੱਪਰ 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_5_ਥੱਲੇ 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_BUTTON_5_ਉੱਪਰ 0x0200

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_MOUSE_WHEEL 0x0400

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSE_MOVE_RELATIVE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSE_MOVE_ABSOLUTE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSE_VIRTUAL_DESKTOP 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSE_ਗੁਣ_ਬਦਲਿਆ 0x04

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RAWKEYBOARD {
    USHORT Make_ਕੋਡ;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT ਸੁਨੇਹਾ_6;
    ULONG ExtraInformation;
  } RAWKEYBOARD,*PRAWKEYBOARD,*LPRAWKEYBOARD;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ KEYBOARD_OVERRUN_MAKE_ਕੋਡ 0xFF

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_ਕੁੰਜੀ_MAKE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_ਕੁੰਜੀ_BREAK 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_ਕੁੰਜੀ_E0 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_ਕੁੰਜੀ_E1 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_ਕੁੰਜੀ_TERMSRV_ਸੈੱਟ_LED 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RI_ਕੁੰਜੀ_TERMSRV_SHADOW 0x10

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RAWHID {
    DWORD dw_ਮਾਪ_Hid;
    DWORD dw_ਗਿਣਤੀ;
    BYTE b_Raw_ਅੰਕੜੇ[1];
  } RAWHID,*PRAWHID,*LPRAWHID;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RAWINPUT {
    RAWINPUTHEADER ਸਿਰਲੇਖ;
    ਸੰਘ {
      RAWMOUSE mouse;
      RAWKEYBOARD keyboard;
      RAWHID hid;
    } ਅੰਕੜੇ;
  } RAWINPUT,*PRAWINPUT,*LPRAWINPUT;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ _WIN64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RAWINPUT_ALIGN(x) (((x) + ਆਕਾਰ(QWORD) - 1) & ~(ਆਕਾਰ(QWORD) - 1))
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RAWINPUT_ALIGN(x) (((x) + ਆਕਾਰ(DWORD) - 1) & ~(ਆਕਾਰ(DWORD) - 1))
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->ਸਿਰਲੇਖ.dw_ਮਾਪ)))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RID_ਨਿਵੇਸ਼ 0x10000003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RID_ਸਿਰਲੇਖ 0x10000005

  WINUSERAPI UINT WINAPI Get_Raw_ਨਿਵੇਸ਼_ਅੰਕੜੇ(HRAWINPUT h_Raw_ਨਿਵੇਸ਼,UINT uiCommand,LPVOID p_ਅੰਕੜੇ,PUINT pcb_ਮਾਪ,UINT cb_ਮਾਪ_ਸਿਰਲੇਖ);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDI_PREPARSEDDATA 0x20000005
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDI_DEVICENAME 0x20000007
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDI_DEVICEINFO 0x2000000b

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dw_ਸੰਖਿਆ_ਦਾ_Buttons;
    DWORD dw_Sample_ਦਰ;
  } RID_DEVICE_INFO_MOUSE,*PRID_DEVICE_INFO_MOUSE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dw_Keyboard_ਬਹੁਲਕ;
    DWORD dw_ਸੰਖਿਆ_ਦਾ_Function_ਕੁੰਜੀਆਂ;
    DWORD dw_ਸੰਖਿਆ_ਦਾ_Indicators;
    DWORD dw_ਸੰਖਿਆ_ਦਾ_ਕੁੰਜੀਆਂ_ਕੁੱਲ;
  } RID_DEVICE_INFO_KEYBOARD,*PRID_DEVICE_INFO_KEYBOARD;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dw_ਗੁਣਨਫਲ_Id;
    DWORD dw_ਸੰਸਕਰਣ_ਸੰਖਿਆ;
    USHORT us_Usage_ਪੰਨਾ;
    USHORT usUsage;
  } RID_DEVICE_INFO_HID,*PRID_DEVICE_INFO_HID;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RID_DEVICE_INFO {
    DWORD cb_ਮਾਪ;
    DWORD dwType;
    ਸੰਘ {
      RID_DEVICE_INFO_MOUSE mouse;
      RID_DEVICE_INFO_KEYBOARD keyboard;
      RID_DEVICE_INFO_HID hid;
    };
  } RID_DEVICE_INFO,*PRID_DEVICE_INFO,*LPRID_DEVICE_INFO;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Raw_ਨਿਵੇਸ਼_Device_Info Get_Raw_ਨਿਵੇਸ਼_Device_Info_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Raw_ਨਿਵੇਸ਼_Device_Info Get_Raw_ਨਿਵੇਸ਼_Device_Info_A
#ਜੇ_ਅੰਤ

  WINUSERAPI UINT WINAPI Get_Raw_ਨਿਵੇਸ਼_Device_Info_A(HANDLE hDevice,UINT uiCommand,LPVOID p_ਅੰਕੜੇ,PUINT pcb_ਮਾਪ);
  WINUSERAPI UINT WINAPI Get_Raw_ਨਿਵੇਸ਼_Device_Info_W(HANDLE hDevice,UINT uiCommand,LPVOID p_ਅੰਕੜੇ,PUINT pcb_ਮਾਪ);
  WINUSERAPI UINT WINAPI Get_Raw_ਨਿਵੇਸ਼_ਬਫਰ(PRAWINPUT p_ਅੰਕੜੇ,PUINT pcb_ਮਾਪ,UINT cb_ਮਾਪ_ਸਿਰਲੇਖ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RAWINPUTDEVICE {
    USHORT us_Usage_ਪੰਨਾ;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwnd_ਨਿਸ਼ਾਨਾ;
  } RAWINPUTDEVICE,*PRAWINPUTDEVICE,*LPRAWINPUTDEVICE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CONST RAWINPUTDEVICE *PCRAWINPUTDEVICE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_REMOVE 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_EXCLUDE 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_PAGEONLY 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_NOLEGACY 0x00000030
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_INPUTSINK 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_CAPTUREMOUSE 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_NOHOTKEYS 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_APPKEYS 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_EXMODEMASK 0x000000F0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RIDEV_EXMODE(ਬਹੁਲਕ) ((ਬਹੁਲਕ) & RIDEV_EXMODEMASK)

  WINUSERAPI WINBOOL WINAPI ਰਜਿਸਟਰ_Raw_ਨਿਵੇਸ਼_Devices(PCRAWINPUTDEVICE p_Raw_ਨਿਵੇਸ਼_Devices,UINT ui_ਅੰਕ_Devices,UINT cb_ਮਾਪ);
  WINUSERAPI UINT WINAPI Get_Registered_Raw_ਨਿਵੇਸ਼_Devices(PRAWINPUTDEVICE p_Raw_ਨਿਵੇਸ਼_Devices,PUINT pui_ਅੰਕ_Devices,UINT cb_ਮਾਪ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
  } RAWINPUTDEVICELIST,*PRAWINPUTDEVICELIST;

  WINUSERAPI UINT WINAPI Get_Raw_ਨਿਵੇਸ਼_Device_List(PRAWINPUTDEVICELIST p_Raw_ਨਿਵੇਸ਼_Device_List,PUINT pui_ਅੰਕ_Devices,UINT cb_ਮਾਪ);
  WINUSERAPI LRESULT WINAPI Def_Raw_ਨਿਵੇਸ਼_Proc(PRAWINPUT *pa_Raw_ਨਿਵੇਸ਼,INT n_ਨਿਵੇਸ਼,UINT cb_ਮਾਪ_ਸਿਰਲੇਖ);

#ਜੇ_ਅੰਤ /* NOUSER */

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
