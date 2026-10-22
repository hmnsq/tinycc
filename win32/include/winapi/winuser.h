/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINUSER_
#ವ್ಯಾಖ್ಯಾನಿಸು _WINUSER_

#ವ್ಯಾಖ್ಯಾನಿಸು WINUSERAPI DECLSPEC_IMPORT

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WINVER
#ವ್ಯಾಖ್ಯಾನಿಸು WINVER 0x0502
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <stdarg.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOUSER
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HANDLE HDWP;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID MENUTEMPLATEA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID MENUTEMPLATEW;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVOID LPMENUTEMPLATEA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVOID LPMENUTEMPLATEW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MENUTEMPLATEW MENUTEMPLATE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMENUTEMPLATEW LPMENUTEMPLATE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MENUTEMPLATEA MENUTEMPLATE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMENUTEMPLATEA LPMENUTEMPLATE;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LRESULT (CALLBACK *WNDPROC)(HWND,UINT,WPARAM,LPARAM);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ INT_PTR (CALLBACK *DLGPROC)(HWND,UINT,WPARAM,LPARAM);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (CALLBACK *TIMERPROC)(HWND,UINT,UINT_PTR,DWORD);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *GRAYSTRINGPROC)(HDC,LPARAM,ಪೂರ್ಣಾಂಕ);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *WNDENUMPROC)(HWND,LPARAM);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LRESULT (CALLBACK *HOOKPROC)(ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_2,WPARAM wParam,LPARAM lParam);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (CALLBACK *SENDASYNCPROC)(HWND,UINT,ULONG_PTR,LRESULT);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *PROPENUMPROCA)(HWND,LPCSTR,HANDLE);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *PROPENUMPROCW)(HWND,LPCWSTR,HANDLE);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *PROPENUMPROCEXA)(HWND,LPSTR,HANDLE,ULONG_PTR);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *PROPENUMPROCEXW)(HWND,LPWSTR,HANDLE,ULONG_PTR);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *EDITWORDBREAKPROCA)(LPSTR lpch,ಪೂರ್ಣಾಂಕ ichCurrent,ಪೂರ್ಣಾಂಕ cch,ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_2);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *EDITWORDBREAKPROCW)(LPWSTR lpch,ಪೂರ್ಣಾಂಕ ichCurrent,ಪೂರ್ಣಾಂಕ cch,ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_2);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *DRAWSTATEPROC)(HDC hdc,LPARAM l_ದತ್ತಾಂಶ,WPARAM w_ದತ್ತಾಂಶ,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PROPENUMPROCW PROPENUMPROC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PROPENUMPROCEXW PROPENUMPROCEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ EDITWORDBREAKPROCW EDITWORDBREAKPROC;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PROPENUMPROCA PROPENUMPROC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PROPENUMPROCEXA PROPENUMPROCEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ EDITWORDBREAKPROCA EDITWORDBREAKPROC;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *NAMEENUMPROCA)(LPSTR,LPARAM);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *NAMEENUMPROCW)(LPWSTR,LPARAM);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NAMEENUMPROCA WINSTAENUMPROCA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NAMEENUMPROCA DESKTOPENUMPROCA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NAMEENUMPROCW WINSTAENUMPROCW;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NAMEENUMPROCW DESKTOPENUMPROCW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINSTAENUMPROCW WINSTAENUMPROC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DESKTOPENUMPROCW DESKTOPENUMPROC;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINSTAENUMPROCA WINSTAENUMPROC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DESKTOPENUMPROCA DESKTOPENUMPROC;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16)==0)
#ವ್ಯಾಖ್ಯಾನಿಸು MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((ಶಬ್ದ_3)(i))))
#ವ್ಯಾಖ್ಯಾನಿಸು MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((ಶಬ್ದ_3)(i))))
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು MAKEINTRESOURCE MAKEINTRESOURCEW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು MAKEINTRESOURCE MAKEINTRESOURCEA
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NORESOURCE

#ವ್ಯಾಖ್ಯಾನಿಸು RT_CURSOR MAKEINTRESOURCE(1)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_BITMAP MAKEINTRESOURCE(2)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_ICON MAKEINTRESOURCE(3)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_MENU MAKEINTRESOURCE(4)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_DIALOG MAKEINTRESOURCE(5)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_STRING MAKEINTRESOURCE(6)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_FONTDIR MAKEINTRESOURCE(7)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_FONT MAKEINTRESOURCE(8)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_ACCELERATOR MAKEINTRESOURCE(9)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_RCDATA MAKEINTRESOURCE(10)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_MESSAGETABLE MAKEINTRESOURCE(11)

#ವ್ಯಾಖ್ಯಾನಿಸು DIFFERENCE 11
#ವ್ಯಾಖ್ಯಾನಿಸು RT_ಗುಂಪು_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_ಗುಂಪು_ICON MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_ಆವೃತ್ತಿ MAKEINTRESOURCE(16)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_DLGINCLUDE MAKEINTRESOURCE(17)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_PLUGPLAY MAKEINTRESOURCE(19)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_VXD MAKEINTRESOURCE(20)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_ANICURSOR MAKEINTRESOURCE(21)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_ANIICON MAKEINTRESOURCE(22)
#ವ್ಯಾಖ್ಯಾನಿಸು RT_HTML MAKEINTRESOURCE(23)
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿಸು RT_MANIFEST 24
#ವ್ಯಾಖ್ಯಾನಿಸು CREATEPROCESS_MANIFEST_RESOURCE_ID 1
#ವ್ಯಾಖ್ಯಾನಿಸು ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
#ವ್ಯಾಖ್ಯಾನಿಸು ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
#ವ್ಯಾಖ್ಯಾನಿಸು MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_RESERVED_MANIFEST_RESOURCE_ID 16
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RT_MANIFEST MAKEINTRESOURCE(24)
#ವ್ಯಾಖ್ಯಾನಿಸು CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#ವ್ಯಾಖ್ಯಾನಿಸು ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
#ವ್ಯಾಖ್ಯಾನಿಸು ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
#ವ್ಯಾಖ್ಯಾನಿಸು MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(1)
#ವ್ಯಾಖ್ಯಾನಿಸು ಗರಿಷ್ಠ_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16)
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು wvsprintf wvsprintfW
#ವ್ಯಾಖ್ಯಾನಿಸು wsprintf wsprintfW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು wvsprintf wvsprintfA
#ವ್ಯಾಖ್ಯಾನಿಸು wsprintf wsprintfA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI wvsprintfA(LPSTR,LPCSTR,va_list arglist);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI wvsprintfW(LPWSTR,LPCWSTR,va_list arglist);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPIV wsprintfA(LPSTR,LPCSTR,...);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPIV wsprintfW(LPWSTR,LPCWSTR,...);

#ವ್ಯಾಖ್ಯಾನಿಸು SETWALLPAPER_DEFAULT ((LPWSTR)-1)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOSCROLL
#ವ್ಯಾಖ್ಯಾನಿಸು SB_HORZ 0
#ವ್ಯಾಖ್ಯಾನಿಸು SB_VERT 1
#ವ್ಯಾಖ್ಯಾನಿಸು SB_CTL 2
#ವ್ಯಾಖ್ಯಾನಿಸು SB_BOTH 3

#ವ್ಯಾಖ್ಯಾನಿಸು SB_LINEUP 0
#ವ್ಯಾಖ್ಯಾನಿಸು SB_LINELEFT 0
#ವ್ಯಾಖ್ಯಾನಿಸು SB_LINEDOWN 1
#ವ್ಯಾಖ್ಯಾನಿಸು SB_LINERIGHT 1
#ವ್ಯಾಖ್ಯಾನಿಸು SB_PAGEUP 2
#ವ್ಯಾಖ್ಯಾನಿಸು SB_PAGELEFT 2
#ವ್ಯಾಖ್ಯಾನಿಸು SB_PAGEDOWN 3
#ವ್ಯಾಖ್ಯಾನಿಸು SB_PAGERIGHT 3
#ವ್ಯಾಖ್ಯಾನಿಸು SB_THUMBPOSITION 4
#ವ್ಯಾಖ್ಯಾನಿಸು SB_THUMBTRACK 5
#ವ್ಯಾಖ್ಯಾನಿಸು SB_ತುದಿ 6
#ವ್ಯಾಖ್ಯಾನಿಸು SB_ಎಡ 6
#ವ್ಯಾಖ್ಯಾನಿಸು SB_BOTTOM 7
#ವ್ಯಾಖ್ಯಾನಿಸು SB_ಬಲ 7
#ವ್ಯಾಖ್ಯಾನಿಸು SB_ENDSCROLL 8
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOSHOWWINDOW
#ವ್ಯಾಖ್ಯಾನಿಸು SW_HIDE 0
#ವ್ಯಾಖ್ಯಾನಿಸು SW_SHOWNORMAL 1
#ವ್ಯಾಖ್ಯಾನಿಸು SW_ಸಾಮಾನ್ಯ 1
#ವ್ಯಾಖ್ಯಾನಿಸು SW_SHOWMINIMIZED 2
#ವ್ಯಾಖ್ಯಾನಿಸು SW_SHOWMAXIMIZED 3
#ವ್ಯಾಖ್ಯಾನಿಸು SW_MAXIMIZE 3
#ವ್ಯಾಖ್ಯಾನಿಸು SW_SHOWNOACTIVATE 4
#ವ್ಯಾಖ್ಯಾನಿಸು SW_SHOW 5
#ವ್ಯಾಖ್ಯಾನಿಸು SW_MINIMIZE 6
#ವ್ಯಾಖ್ಯಾನಿಸು SW_SHOWMINNOACTIVE 7
#ವ್ಯಾಖ್ಯಾನಿಸು SW_SHOWNA 8
#ವ್ಯಾಖ್ಯಾನಿಸು SW_RESTORE 9
#ವ್ಯಾಖ್ಯಾನಿಸು SW_SHOWDEFAULT 10
#ವ್ಯಾಖ್ಯಾನಿಸು SW_FORCEMINIMIZE 11
#ವ್ಯಾಖ್ಯಾನಿಸು SW_MAX 11

#ವ್ಯಾಖ್ಯಾನಿಸು HIDE_ಕಿಟಕಿ 0
#ವ್ಯಾಖ್ಯಾನಿಸು SHOW_OPENWINDOW 1
#ವ್ಯಾಖ್ಯಾನಿಸು SHOW_ICONWINDOW 2
#ವ್ಯಾಖ್ಯಾನಿಸು SHOW_FULLSCREEN 3
#ವ್ಯಾಖ್ಯಾನಿಸು SHOW_OPENNOACTIVATE 4

#ವ್ಯಾಖ್ಯಾನಿಸು SW_PARENTCLOSING 1
#ವ್ಯಾಖ್ಯಾನಿಸು SW_OTHERZOOM 2
#ವ್ಯಾಖ್ಯಾನಿಸು SW_PARENTOPENING 3
#ವ್ಯಾಖ್ಯಾನಿಸು SW_OTHERUNZOOM 4
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು AW_HOR_ಧನಾತ್ಮಕ 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು AW_HOR_NEGATIVE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು AW_VER_ಧನಾತ್ಮಕ 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು AW_VER_NEGATIVE 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು AW_CENTER 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು AW_HIDE 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು AW_ACTIVATE 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು AW_SLIDE 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು AW_BLEND 0x00080000

#ವ್ಯಾಖ್ಯಾನಿಸು KF_EXTENDED 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು KF_DLGMODE 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು KF_MENUMODE 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು KF_ALTDOWN 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು KF_REPEAT 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು KF_ಮೇಲೆ 0x8000

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOVIRTUALKEYCODES

#ವ್ಯಾಖ್ಯಾನಿಸು VK_LBUTTON 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು VK_RBUTTON 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು VK_CANCEL 0x03
#ವ್ಯಾಖ್ಯಾನಿಸು VK_MBUTTON 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು VK_XBUTTON1 0x05
#ವ್ಯಾಖ್ಯಾನಿಸು VK_XBUTTON2 0x06
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಹಿಂಭಾಗ 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು VK_TAB 0x09
#ವ್ಯಾಖ್ಯಾನಿಸು VK_CLEAR 0x0C
#ವ್ಯಾಖ್ಯಾನಿಸು VK_RETURN 0x0D
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಸರಿಸು 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು VK_CONTROL 0x11
#ವ್ಯಾಖ್ಯಾನಿಸು VK_MENU 0x12
#ವ್ಯಾಖ್ಯಾನಿಸು VK_PAUSE 0x13
#ವ್ಯಾಖ್ಯಾನಿಸು VK_CAPITAL 0x14
#ವ್ಯಾಖ್ಯಾನಿಸು VK_KANA 0x15
#ವ್ಯಾಖ್ಯಾನಿಸು VK_HANGEUL 0x15
#ವ್ಯಾಖ್ಯಾನಿಸು VK_HANGUL 0x15
#ವ್ಯಾಖ್ಯಾನಿಸು VK_JUNJA 0x17
#ವ್ಯಾಖ್ಯಾನಿಸು VK_FINAL 0x18
#ವ್ಯಾಖ್ಯಾನಿಸು VK_HANJA 0x19
#ವ್ಯಾಖ್ಯಾನಿಸು VK_KANJI 0x19
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ESCAPE 0x1B
#ವ್ಯಾಖ್ಯಾನಿಸು VK_CONVERT 0x1C
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NONCONVERT 0x1D
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ACCEPT 0x1E
#ವ್ಯಾಖ್ಯಾನಿಸು VK_MODECHANGE 0x1F
#ವ್ಯಾಖ್ಯಾನಿಸು VK_SPACE 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಪೂರ್ವ 0x21
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಮುಂದಿನ 0x22
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಕೊನೆ 0x23
#ವ್ಯಾಖ್ಯಾನಿಸು VK_HOME 0x24
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಎಡ 0x25
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಮೇಲೆ 0x26
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಬಲ 0x27
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಕೆಳಕ್ಕೆ 0x28
#ವ್ಯಾಖ್ಯಾನಿಸು VK_SELECT 0x29
#ವ್ಯಾಖ್ಯಾನಿಸು VK_PRINT 0x2A
#ವ್ಯಾಖ್ಯಾನಿಸು VK_EXECUTE 0x2B
#ವ್ಯಾಖ್ಯಾನಿಸು VK_SNAPSHOT 0x2C
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಸೇರಿಸು 0x2D
#ವ್ಯಾಖ್ಯಾನಿಸು VK_DELETE 0x2E
#ವ್ಯಾಖ್ಯಾನಿಸು VK_HELP 0x2F

#ವ್ಯಾಖ್ಯಾನಿಸು VK_LWIN 0x5B
#ವ್ಯಾಖ್ಯಾನಿಸು VK_RWIN 0x5C
#ವ್ಯಾಖ್ಯಾನಿಸು VK_APPS 0x5D
#ವ್ಯಾಖ್ಯಾನಿಸು VK_SLEEP 0x5F
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD0 0x60
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD1 0x61
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD2 0x62
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD3 0x63
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD4 0x64
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD5 0x65
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD6 0x66
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD7 0x67
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD8 0x68
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMPAD9 0x69
#ವ್ಯಾಖ್ಯಾನಿಸು VK_MULTIPLY 0x6A
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಕೂಡಿಸು 0x6B
#ವ್ಯಾಖ್ಯಾನಿಸು VK_SEPARATOR 0x6C
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ಕಳೆ 0x6D
#ವ್ಯಾಖ್ಯಾನಿಸು VK_DECIMAL 0x6E
#ವ್ಯಾಖ್ಯಾನಿಸು VK_DIVIDE 0x6F
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F1 0x70
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F2 0x71
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F3 0x72
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F4 0x73
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F5 0x74
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F6 0x75
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F7 0x76
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F8 0x77
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F9 0x78
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F10 0x79
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F11 0x7A
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F12 0x7B
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F13 0x7C
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F14 0x7D
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F15 0x7E
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F16 0x7F
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F17 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F18 0x81
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F19 0x82
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F20 0x83
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F21 0x84
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F22 0x85
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F23 0x86
#ವ್ಯಾಖ್ಯಾನಿಸು VK_F24 0x87
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NUMLOCK 0x90
#ವ್ಯಾಖ್ಯಾನಿಸು VK_SCROLL 0x91
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_NEC_EQUAL 0x92
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_FJ_JISHO 0x92
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_FJ_MASSHOU 0x93
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_FJ_TOUROKU 0x94
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_FJ_LOYA 0x95
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_FJ_ROYA 0x96
#ವ್ಯಾಖ್ಯಾನಿಸು VK_LSHIFT 0xA0
#ವ್ಯಾಖ್ಯಾನಿಸು VK_RSHIFT 0xA1
#ವ್ಯಾಖ್ಯಾನಿಸು VK_LCONTROL 0xA2
#ವ್ಯಾಖ್ಯಾನಿಸು VK_RCONTROL 0xA3
#ವ್ಯಾಖ್ಯಾನಿಸು VK_LMENU 0xA4
#ವ್ಯಾಖ್ಯಾನಿಸು VK_RMENU 0xA5
#ವ್ಯಾಖ್ಯಾನಿಸು VK_BROWSER_ಹಿಂಭಾಗ 0xA6
#ವ್ಯಾಖ್ಯಾನಿಸು VK_BROWSER_FORWARD 0xA7
#ವ್ಯಾಖ್ಯಾನಿಸು VK_BROWSER_REFRESH 0xA8
#ವ್ಯಾಖ್ಯಾನಿಸು VK_BROWSER_STOP 0xA9
#ವ್ಯಾಖ್ಯಾನಿಸು VK_BROWSER_ಹುಡುಕು 0xAA
#ವ್ಯಾಖ್ಯಾನಿಸು VK_BROWSER_FAVORITES 0xAB
#ವ್ಯಾಖ್ಯಾನಿಸು VK_BROWSER_HOME 0xAC
#ವ್ಯಾಖ್ಯಾನಿಸು VK_VOLUME_MUTE 0xAD
#ವ್ಯಾಖ್ಯಾನಿಸು VK_VOLUME_ಕೆಳಕ್ಕೆ 0xAE
#ವ್ಯಾಖ್ಯಾನಿಸು VK_VOLUME_ಮೇಲೆ 0xAF
#ವ್ಯಾಖ್ಯಾನಿಸು VK_MEDIA_ಮುಂದಿನ_TRACK 0xB0
#ವ್ಯಾಖ್ಯಾನಿಸು VK_MEDIA_PREV_TRACK 0xB1
#ವ್ಯಾಖ್ಯಾನಿಸು VK_MEDIA_STOP 0xB2
#ವ್ಯಾಖ್ಯಾನಿಸು VK_MEDIA_PLAY_PAUSE 0xB3
#ವ್ಯಾಖ್ಯಾನಿಸು VK_LAUNCH_MAIL 0xB4
#ವ್ಯಾಖ್ಯಾನಿಸು VK_LAUNCH_MEDIA_SELECT 0xB5
#ವ್ಯಾಖ್ಯಾನಿಸು VK_LAUNCH_APP1 0xB6
#ವ್ಯಾಖ್ಯಾನಿಸು VK_LAUNCH_APP2 0xB7
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_1 0xBA
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_PLUS 0xBB
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_COMMA 0xBC
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_MINUS 0xBD
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_PERIOD 0xBE
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_2 0xBF
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_3 0xC0
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_4 0xDB
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_5 0xDC
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_6 0xDD
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_7 0xDE
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_8 0xDF
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_AX 0xE1
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_102 0xE2
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ICO_HELP 0xE3
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ICO_00 0xE4
#ವ್ಯಾಖ್ಯಾನಿಸು VK_PROCESSKEY 0xE5
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ICO_CLEAR 0xE6
#ವ್ಯಾಖ್ಯಾನಿಸು VK_PACKET 0xE7
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_RESET 0xE9
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_JUMP 0xEA
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_PA1 0xEB
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_PA2 0xEC
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_PA3 0xED
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_WSCTRL 0xEE
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_CUSEL 0xEF
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_ATTN 0xF0
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_ಮುಕ್ತಾಯ 0xF1
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_COPY 0xF2
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_AUTO 0xF3
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_ENLW 0xF4
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_BACKTAB 0xF5
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ATTN 0xF6
#ವ್ಯಾಖ್ಯಾನಿಸು VK_CRSEL 0xF7
#ವ್ಯಾಖ್ಯಾನಿಸು VK_EXSEL 0xF8
#ವ್ಯಾಖ್ಯಾನಿಸು VK_EREOF 0xF9
#ವ್ಯಾಖ್ಯಾನಿಸು VK_PLAY 0xFA
#ವ್ಯಾಖ್ಯಾನಿಸು VK_ZOOM 0xFB
#ವ್ಯಾಖ್ಯಾನಿಸು VK_NONAME 0xFC
#ವ್ಯಾಖ್ಯಾನಿಸು VK_PA1 0xFD
#ವ್ಯಾಖ್ಯಾನಿಸು VK_OEM_CLEAR 0xFE
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWH

#ವ್ಯಾಖ್ಯಾನಿಸು WH_MIN (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು WH_MSGFILTER (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು WH_JOURNALRECORD 0
#ವ್ಯಾಖ್ಯಾನಿಸು WH_JOURNALPLAYBACK 1
#ವ್ಯಾಖ್ಯಾನಿಸು WH_KEYBOARD 2
#ವ್ಯಾಖ್ಯಾನಿಸು WH_GETMESSAGE 3
#ವ್ಯಾಖ್ಯಾನಿಸು WH_CALLWNDPROC 4
#ವ್ಯಾಖ್ಯಾನಿಸು WH_CBT 5
#ವ್ಯಾಖ್ಯಾನಿಸು WH_SYSMSGFILTER 6
#ವ್ಯಾಖ್ಯಾನಿಸು WH_MOUSE 7
#ವ್ಯಾಖ್ಯಾನಿಸು WH_HARDWARE 8
#ವ್ಯಾಖ್ಯಾನಿಸು WH_DEBUG 9
#ವ್ಯಾಖ್ಯಾನಿಸು WH_SHELL 10
#ವ್ಯಾಖ್ಯಾನಿಸು WH_FOREGROUNDIDLE 11
#ವ್ಯಾಖ್ಯಾನಿಸು WH_CALLWNDPROCRET 12

#ವ್ಯಾಖ್ಯಾನಿಸು WH_KEYBOARD_LL 13
#ವ್ಯಾಖ್ಯಾನಿಸು WH_MOUSE_LL 14

#ವ್ಯಾಖ್ಯಾನಿಸು WH_MAX 14

#ವ್ಯಾಖ್ಯಾನಿಸು WH_MINHOOK WH_MIN
#ವ್ಯಾಖ್ಯಾನಿಸು WH_MAXHOOK WH_MAX

#ವ್ಯಾಖ್ಯಾನಿಸು HC_ACTION 0
#ವ್ಯಾಖ್ಯಾನಿಸು HC_GETNEXT 1
#ವ್ಯಾಖ್ಯಾನಿಸು HC_SKIP 2
#ವ್ಯಾಖ್ಯಾನಿಸು HC_NOREMOVE 3
#ವ್ಯಾಖ್ಯಾನಿಸು HC_NOREM HC_NOREMOVE
#ವ್ಯಾಖ್ಯಾನಿಸು HC_SYSMODALON 4
#ವ್ಯಾಖ್ಯಾನಿಸು HC_SYSMODALOFF 5

#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_MOVESIZE 0
#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_MINMAX 1
#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_QS 2
#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_CREATEWND 3
#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_DESTROYWND 4
#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_ACTIVATE 5
#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_CLICKSKIPPED 6
#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_KEYSKIPPED 7
#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_SYSCOMMAND 8
#ವ್ಯಾಖ್ಯಾನಿಸು HCBT_SETFOCUS 9

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CBT_CREATEWNDA {
    ರಚನೆ ಟ್ಯಾಗ್_CREATESTRUCTA *lpcs;
    HWND hwnd_ಸೇರಿಸು_After;
  } CBT_CREATEWNDA,*LPCBT_CREATEWNDA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CBT_CREATEWNDW {
    ರಚನೆ ಟ್ಯಾಗ್_CREATESTRUCTW *lpcs;
    HWND hwnd_ಸೇರಿಸು_After;
  } CBT_CREATEWNDW,*LPCBT_CREATEWNDW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CBT_CREATEWNDW CBT_CREATEWND;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCBT_CREATEWNDW LPCBT_CREATEWND;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CBT_CREATEWNDA CBT_CREATEWND;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCBT_CREATEWNDA LPCBT_CREATEWND;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CBTACTIVATESTRUCT
  {
    WINBOOL fMouse;
    HWND h_Wnd_ಸಕ್ರಿಯ;
  } CBTACTIVATESTRUCT,*LPCBTACTIVATESTRUCT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_WTSSESSION_NOTIFICATION {
    DWORD cb_ಗಾತ್ರ;
    DWORD dwSessionId;

  } WTSSESSION_NOTIFICATION,*PWTSSESSION_NOTIFICATION;

#ವ್ಯಾಖ್ಯಾನಿಸು WTS_CONSOLE_CONNECT 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು WTS_CONSOLE_DISCONNECT 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು WTS_REMOTE_CONNECT 0x3
#ವ್ಯಾಖ್ಯಾನಿಸು WTS_REMOTE_DISCONNECT 0x4
#ವ್ಯಾಖ್ಯಾನಿಸು WTS_SESSION_LOGON 0x5
#ವ್ಯಾಖ್ಯಾನಿಸು WTS_SESSION_LOGOFF 0x6
#ವ್ಯಾಖ್ಯಾನಿಸು WTS_SESSION_ಬೀಗ 0x7
#ವ್ಯಾಖ್ಯಾನಿಸು WTS_SESSION_UNLOCK 0x8
#ವ್ಯಾಖ್ಯಾನಿಸು WTS_SESSION_REMOTE_CONTROL 0x9

#ವ್ಯಾಖ್ಯಾನಿಸು MSGF_DIALOGBOX 0
#ವ್ಯಾಖ್ಯಾನಿಸು MSGF_MESSAGEBOX 1
#ವ್ಯಾಖ್ಯಾನಿಸು MSGF_MENU 2
#ವ್ಯಾಖ್ಯಾನಿಸು MSGF_SCROLLBAR 5
#ವ್ಯಾಖ್ಯಾನಿಸು MSGF_NEXTWINDOW 6
#ವ್ಯಾಖ್ಯಾನಿಸು MSGF_MAX 8
#ವ್ಯಾಖ್ಯಾನಿಸು MSGF_USER 4096

#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_WINDOWCREATED 1
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_WINDOWDESTROYED 2
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_ACTIVATESHELLWINDOW 3

#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_WINDOWACTIVATED 4
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_GETMINRECT 5
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_REDRAW 6
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_TASKMAN 7
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_LANGUAGE 8
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_SYSMENU 9
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_ENDTASK 10
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_ACCESSIBILITYSTATE 11
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_APPCOMMAND 12
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_WINDOWREPLACED 13
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_WINDOWREPLACING 14
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_HIGHBIT 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_FLASH (HSHELL_REDRAW|HSHELL_HIGHBIT)
#ವ್ಯಾಖ್ಯಾನಿಸು HSHELL_RUDEAPPACTIVATED (HSHELL_WINDOWACTIVATED|HSHELL_HIGHBIT)

#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_STICKYKEYS 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_FILTERKEYS 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು ACCESS_MOUSEKEYS 0x0003

#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BROWSER_BACKWARD 1
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BROWSER_FORWARD 2
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BROWSER_REFRESH 3
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BROWSER_STOP 4
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BROWSER_ಹುಡುಕು 5
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BROWSER_FAVORITES 6
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BROWSER_HOME 7
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_VOLUME_MUTE 8
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_VOLUME_ಕೆಳಕ್ಕೆ 9
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_VOLUME_ಮೇಲೆ 10
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_NEXTTRACK 11
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_PREVIOUSTRACK 12
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_STOP 13
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_PLAY_PAUSE 14
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_LAUNCH_MAIL 15
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_LAUNCH_MEDIA_SELECT 16
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_LAUNCH_APP1 17
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_LAUNCH_APP2 18
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BASS_ಕೆಳಕ್ಕೆ 19
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BASS_BOOST 20
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_BASS_ಮೇಲೆ 21
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_TREBLE_ಕೆಳಕ್ಕೆ 22
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_TREBLE_ಮೇಲೆ 23
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MICROPHONE_VOLUME_MUTE 24
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MICROPHONE_VOLUME_ಕೆಳಕ್ಕೆ 25
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MICROPHONE_VOLUME_ಮೇಲೆ 26
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_HELP 27
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_ಕಂಡುಹಿಡಿ 28
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_NEW 29
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_OPEN 30
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_CLOSE 31
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_SAVE 32
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_PRINT 33
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_UNDO 34
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_REDO 35
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_COPY 36
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_CUT 37
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_PASTE 38
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_ಉತ್ತರ_ಗಮ್ಯ_MAIL 39
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_FORWARD_MAIL 40
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_SEND_MAIL 41
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_SPELL_CHECK 42
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE 43
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MIC_ON_OFF_TOGGLE 44
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_CORRECTION_LIST 45
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_PLAY 46
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_PAUSE 47
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_ದಾಖಲೆ 48
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_FAST_FORWARD 49
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_REWIND 50
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_CHANNEL_ಮೇಲೆ 51
#ವ್ಯಾಖ್ಯಾನಿಸು APPCOMMAND_MEDIA_CHANNEL_ಕೆಳಕ್ಕೆ 52

#ವ್ಯಾಖ್ಯಾನಿಸು FAPPCOMMAND_MOUSE 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು FAPPCOMMAND_ಕೀಲಿ 0
#ವ್ಯಾಖ್ಯಾನಿಸು FAPPCOMMAND_OEM 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು FAPPCOMMAND_ಮುಖವಾಡ 0xF000

#ವ್ಯಾಖ್ಯಾನಿಸು GET_APPCOMMAND_LPARAM(lParam) ((ಗಿಡ್ಡ)(HIWORD(lParam) & ~FAPPCOMMAND_ಮುಖವಾಡ))
#ವ್ಯಾಖ್ಯಾನಿಸು GET_DEVICE_LPARAM(lParam) ((ಶಬ್ದ_3)(HIWORD(lParam) & FAPPCOMMAND_ಮುಖವಾಡ))
#ವ್ಯಾಖ್ಯಾನಿಸು GET_MOUSEORKEY_LPARAM GET_DEVICE_LPARAM
#ವ್ಯಾಖ್ಯಾನಿಸು GET_FLAGS_LPARAM(lParam) (LOWORD(lParam))
#ವ್ಯಾಖ್ಯಾನಿಸು GET_KEYSTATE_LPARAM(lParam) GET_FLAGS_LPARAM(lParam)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    HWND hwnd;
    RECT rc;
  } SHELLHOOKINFO,*LPSHELLHOOKINFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EVENTMSG {
    UINT ಸಂದೇಶ_2;
    UINT paramL;
    UINT paramH;
    DWORD ಸಮಯ;
    HWND hwnd;
  } EVENTMSG,*PEVENTMSGMSG,*NPEVENTMSGMSG,*LPEVENTMSGMSG;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EVENTMSG *PEVENTMSG,*NPEVENTMSG,*LPEVENTMSG;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CWPSTRUCT {
    LPARAM lParam;
    WPARAM wParam;
    UINT ಸಂದೇಶ_2;
    HWND hwnd;
  } CWPSTRUCT,*PCWPSTRUCT,*NPCWPSTRUCT,*LPCWPSTRUCT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CWPRETSTRUCT {
    LRESULT l_ಫಲಿತಾಂಶ;
    LPARAM lParam;
    WPARAM wParam;
    UINT ಸಂದೇಶ_2;
    HWND hwnd;
  } CWPRETSTRUCT,*PCWPRETSTRUCT,*NPCWPRETSTRUCT,*LPCWPRETSTRUCT;

#ವ್ಯಾಖ್ಯಾನಿಸು LLKHF_EXTENDED (KF_EXTENDED >> 8)
#ವ್ಯಾಖ್ಯಾನಿಸು LLKHF_INJECTED 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು LLKHF_ALTDOWN (KF_ALTDOWN >> 8)
#ವ್ಯಾಖ್ಯಾನಿಸು LLKHF_ಮೇಲೆ (KF_ಮೇಲೆ >> 8)

#ವ್ಯಾಖ್ಯಾನಿಸು LLMHF_INJECTED 0x00000001

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_KBDLLHOOKSTRUCT {
    DWORD vk_ಸಂಕೇತ;
    DWORD ಪರಿಶೀಲನೆ_ಸಂಕೇತ;
    DWORD flags;
    DWORD ಸಮಯ;
    ULONG_PTR dwExtraInfo;
  } KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MSLLHOOKSTRUCT {
    ಬಿಂದು_3 pt;
    DWORD mouse_ದತ್ತಾಂಶ;
    DWORD flags;
    DWORD ಸಮಯ;
    ULONG_PTR dwExtraInfo;
  } MSLLHOOKSTRUCT,*LPMSLLHOOKSTRUCT,*PMSLLHOOKSTRUCT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_DEBUGHOOKINFO {
    DWORD idThread;
    DWORD idThreadInstaller;
    LPARAM lParam;
    WPARAM wParam;
    ಪೂರ್ಣಾಂಕ ಸಂಕೇತ_2;
  } DEBUGHOOKINFO,*PDEBUGHOOKINFO,*NPDEBUGHOOKINFO,*LPDEBUGHOOKINFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MOUSEHOOKSTRUCT {
    ಬಿಂದು_3 pt;
    HWND hwnd;
    UINT w_ದೊರಕಿತು_Test_ಸಂಕೇತ;
    ULONG_PTR dwExtraInfo;
  } MOUSEHOOKSTRUCT,*LPMOUSEHOOKSTRUCT,*PMOUSEHOOKSTRUCT;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MOUSEHOOKSTRUCTEX : ಸಾರ್ವಜನಿಕ ಟ್ಯಾಗ್_MOUSEHOOKSTRUCT {
    DWORD mouse_ದತ್ತಾಂಶ;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MOUSEHOOKSTRUCTEX {
    MOUSEHOOKSTRUCT _unnamed;
    DWORD mouse_ದತ್ತಾಂಶ;
  } MOUSEHOOKSTRUCTEX,*LPMOUSEHOOKSTRUCTEX,*PMOUSEHOOKSTRUCTEX;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HARDWAREHOOKSTRUCT {
    HWND hwnd;
    UINT ಸಂದೇಶ_2;
    WPARAM wParam;
    LPARAM lParam;
  } HARDWAREHOOKSTRUCT,*LPHARDWAREHOOKSTRUCT,*PHARDWAREHOOKSTRUCT;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು HKL_PREV 0
#ವ್ಯಾಖ್ಯಾನಿಸು HKL_ಮುಂದಿನ 1

#ವ್ಯಾಖ್ಯಾನಿಸು KLF_ACTIVATE 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು KLF_SUBSTITUTE_OK 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು KLF_REORDER 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು KLF_REPLACELANG 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು KLF_NOTELLSHELL 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು KLF_SETFORPROCESS 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು KLF_SHIFTLOCK 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು KLF_RESET 0x40000000

#ವ್ಯಾಖ್ಯಾನಿಸು INPUTLANGCHANGE_SYSCHARSET 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು INPUTLANGCHANGE_FORWARD 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು INPUTLANGCHANGE_BACKWARD 0x0004

#ವ್ಯಾಖ್ಯಾನಿಸು KL_NAMELENGTH 9

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Keyboard_Layout ತುಂಬು_Keyboard_Layout_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetKeyboardLayoutName GetKeyboardLayoutNameW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Keyboard_Layout ತುಂಬು_Keyboard_Layout_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetKeyboardLayoutName GetKeyboardLayoutNameA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HKL WINAPI ತುಂಬು_Keyboard_Layout_A(LPCSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ತುಂಬು_Keyboard_Layout_W(LPCWSTR pwszKLID,UINT Flags);
  WINUSERAPI HKL WINAPI ActivateKeyboardLayout(HKL hkl,UINT Flags);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಮ್ಯ_Unicode_Ex(UINT w_Virt_ಕೀಲಿ,UINT w_ಪರಿಶೀಲನೆ_ಸಂಕೇತ,CONST BYTE *lp_ಕೀಲಿ_State,LPWSTR pwszBuff,ಪೂರ್ಣಾಂಕ cchBuff,UINT wFlags,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI UnloadKeyboardLayout(HKL hkl);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameA(LPSTR pwszKLID);
  WINUSERAPI WINBOOL WINAPI GetKeyboardLayoutNameW(LPWSTR pwszKLID);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetKeyboardLayoutList(ಪೂರ್ಣಾಂಕ nBuff,HKL *lpList);
  WINUSERAPI HKL WINAPI GetKeyboardLayout(DWORD idThread);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MOUSEMOVEPOINT {
    ಪೂರ್ಣಾಂಕ x;
    ಪೂರ್ಣಾಂಕ y;
    DWORD ಸಮಯ;
    ULONG_PTR dwExtraInfo;
  } MOUSEMOVEPOINT,*PMOUSEMOVEPOINT,*LPMOUSEMOVEPOINT;

#ವ್ಯಾಖ್ಯಾನಿಸು GMMP_USE_DISPLAY_POINTS 1
#ವ್ಯಾಖ್ಯಾನಿಸು GMMP_USE_ಮೇಲಿನ_RESOLUTION_POINTS 2

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetMouseMovePointsEx(UINT cb_ಗಾತ್ರ,LPMOUSEMOVEPOINT lppt,LPMOUSEMOVEPOINT lpptBuf,ಪೂರ್ಣಾಂಕ nBufPoints,DWORD resolution);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NODESKTOP

#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOP_READOBJECTS 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOP_CREATEWINDOW 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOP_CREATEMENU 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOP_HOOKCONTROL 0x0008L
#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOP_JOURNALRECORD 0x0010L
#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOP_JOURNALPLAYBACK 0x0020L
#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOP_ENUMERATE 0x0040L
#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOP_WRITEOBJECTS 0x0080L
#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOP_SWITCHDESKTOP 0x0100L

#ವ್ಯಾಖ್ಯಾನಿಸು DF_ALLOWOTHERACCOUNTHOOK 0x0001L

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WINGDI_
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOGDI
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDesktop CreateDesktopW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDesktop CreateDesktopA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HDESK WINAPI CreateDesktopA(LPCSTR lpszDesktop,LPCSTR lpszDevice,LPDEVMODEA pDevmode,DWORD dwFlags,ACCESS_ಮುಖವಾಡ dwDesiredAccess,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lpsa);
  WINUSERAPI HDESK WINAPI CreateDesktopW(LPCWSTR lpszDesktop,LPCWSTR lpszDevice,LPDEVMODEW pDevmode,DWORD dwFlags,ACCESS_ಮುಖವಾಡ dwDesiredAccess,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lpsa);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು OpenDesktop OpenDesktopW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumDesktops EnumDesktopsW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು OpenDesktop OpenDesktopA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumDesktops EnumDesktopsA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HDESK WINAPI OpenDesktopA(LPCSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ಮುಖವಾಡ dwDesiredAccess);
  WINUSERAPI HDESK WINAPI OpenDesktopW(LPCWSTR lpszDesktop,DWORD dwFlags,WINBOOL fInherit,ACCESS_ಮುಖವಾಡ dwDesiredAccess);
  WINUSERAPI HDESK WINAPI Open_ಒಳಹರಿವು_Desktop(DWORD dwFlags,WINBOOL fInherit,ACCESS_ಮುಖವಾಡ dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsA(HWINSTA hwinsta,DESKTOPENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopsW(HWINSTA hwinsta,DESKTOPENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumDesktopWindows(HDESK hDesktop,WNDENUMPROC lpfn,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI SwitchDesktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Thread_Desktop(HDESK hDesktop);
  WINUSERAPI WINBOOL WINAPI CloseDesktop(HDESK hDesktop);
  WINUSERAPI HDESK WINAPI GetThreadDesktop(DWORD dwThreadId);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINDOWSTATION
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_ENUMDESKTOPS 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_READATTRIBUTES 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_ACCESSCLIPBOARD 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_CREATEDESKTOP 0x0008L
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_WRITEATTRIBUTES 0x0010L
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_ACCESSGLOBALATOMS 0x0020L
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_EXITWINDOWS 0x0040L
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_ENUMERATE 0x0100L
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_READSCREEN 0x0200L
#ವ್ಯಾಖ್ಯಾನಿಸು WINSTA_ALL_ACCESS (WINSTA_ENUMDESKTOPS | WINSTA_READATTRIBUTES | WINSTA_ACCESSCLIPBOARD | WINSTA_CREATEDESKTOP | WINSTA_WRITEATTRIBUTES | WINSTA_ACCESSGLOBALATOMS | WINSTA_EXITWINDOWS | WINSTA_ENUMERATE | WINSTA_READSCREEN)

#ವ್ಯಾಖ್ಯಾನಿಸು CWF_CREATE_ONLY 0x0001L

#ವ್ಯಾಖ್ಯಾನಿಸು WSF_VISIBLE 0x0001L

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕಿಟಕಿ_Station Create_ಕಿಟಕಿ_Station_W
#ವ್ಯಾಖ್ಯಾನಿಸು Open_ಕಿಟಕಿ_Station Open_ಕಿಟಕಿ_Station_W
#ವ್ಯಾಖ್ಯಾನಿಸು Enum_ಕಿಟಕಿ_Stations Enum_ಕಿಟಕಿ_Stations_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕಿಟಕಿ_Station Create_ಕಿಟಕಿ_Station_A
#ವ್ಯಾಖ್ಯಾನಿಸು Open_ಕಿಟಕಿ_Station Open_ಕಿಟಕಿ_Station_A
#ವ್ಯಾಖ್ಯಾನಿಸು Enum_ಕಿಟಕಿ_Stations Enum_ಕಿಟಕಿ_Stations_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HWINSTA WINAPI Create_ಕಿಟಕಿ_Station_A(LPCSTR lpwinsta,DWORD dwFlags,ACCESS_ಮುಖವಾಡ dwDesiredAccess,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lpsa);
  WINUSERAPI HWINSTA WINAPI Create_ಕಿಟಕಿ_Station_W(LPCWSTR lpwinsta,DWORD dwFlags,ACCESS_ಮುಖವಾಡ dwDesiredAccess,LPSECURITY_ಗುಣಲಕ್ಷಣಗಳು lpsa);
  WINUSERAPI HWINSTA WINAPI Open_ಕಿಟಕಿ_Station_A(LPCSTR lpszWinSta,WINBOOL fInherit,ACCESS_ಮುಖವಾಡ dwDesiredAccess);
  WINUSERAPI HWINSTA WINAPI Open_ಕಿಟಕಿ_Station_W(LPCWSTR lpszWinSta,WINBOOL fInherit,ACCESS_ಮುಖವಾಡ dwDesiredAccess);
  WINUSERAPI WINBOOL WINAPI Enum_ಕಿಟಕಿ_Stations_A(WINSTAENUMPROCA lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Enum_ಕಿಟಕಿ_Stations_W(WINSTAENUMPROCW lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Close_ಕಿಟಕಿ_Station(HWINSTA hWinSta);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Process_ಕಿಟಕಿ_Station(HWINSTA hWinSta);
  WINUSERAPI HWINSTA WINAPI Get_Process_ಕಿಟಕಿ_Station(VOID);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOSECURITY
  WINUSERAPI WINBOOL WINAPI ಗಣ_User_Object_Security(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID);
  WINUSERAPI WINBOOL WINAPI GetUserObjectSecurity(HANDLE hObj,PSECURITY_INFORMATION pSIRequested,PSECURITY_DESCRIPTOR pSID,DWORD n_ಉದ್ದಳತೆ,LPDWORD lpn_ಉದ್ದಳತೆ_Needed);

#ವ್ಯಾಖ್ಯಾನಿಸು UOI_FLAGS 1
#ವ್ಯಾಖ್ಯಾನಿಸು UOI_NAME 2
#ವ್ಯಾಖ್ಯಾನಿಸು UOI_TYPE 3
#ವ್ಯಾಖ್ಯಾನಿಸು UOI_USER_SID 4

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_USEROBJECTFLAGS {
    WINBOOL fInherit;
    WINBOOL fReserved;
    DWORD dwFlags;
  } USEROBJECTFLAGS,*PUSEROBJECTFLAGS;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetUserObjectInformation GetUserObjectInformationW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_User_Object_Information ಗಣ_User_Object_Information_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetUserObjectInformation GetUserObjectInformationA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_User_Object_Information ಗಣ_User_Object_Information_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationA(HANDLE hObj,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,PVOID pvInfo,DWORD n_ಉದ್ದಳತೆ,LPDWORD lpn_ಉದ್ದಳತೆ_Needed);
  WINUSERAPI WINBOOL WINAPI GetUserObjectInformationW(HANDLE hObj,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,PVOID pvInfo,DWORD n_ಉದ್ದಳತೆ,LPDWORD lpn_ಉದ್ದಳತೆ_Needed);
  WINUSERAPI WINBOOL WINAPI ಗಣ_User_Object_Information_A(HANDLE hObj,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,PVOID pvInfo,DWORD n_ಉದ್ದಳತೆ);
  WINUSERAPI WINBOOL WINAPI ಗಣ_User_Object_Information_W(HANDLE hObj,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,PVOID pvInfo,DWORD n_ಉದ್ದಳತೆ);
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_WNDCLASSEXA {
    UINT cb_ಗಾತ್ರ;
    UINT style;
    WNDPROC lpfnWndProc;
    ಪೂರ್ಣಾಂಕ cbClsExtra;
    ಪೂರ್ಣಾಂಕ cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
    HICON hIconSm;
  } WNDCLASSEXA,*PWNDCLASSEXA,*NPWNDCLASSEXA,*LPWNDCLASSEXA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_WNDCLASSEXW {
    UINT cb_ಗಾತ್ರ;
    UINT style;
    WNDPROC lpfnWndProc;
    ಪೂರ್ಣಾಂಕ cbClsExtra;
    ಪೂರ್ಣಾಂಕ cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;

    HICON hIconSm;
  } WNDCLASSEXW,*PWNDCLASSEXW,*NPWNDCLASSEXW,*LPWNDCLASSEXW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WNDCLASSEXW WNDCLASSEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWNDCLASSEXW PWNDCLASSEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPWNDCLASSEXW NPWNDCLASSEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWNDCLASSEXW LPWNDCLASSEX;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WNDCLASSEXA WNDCLASSEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWNDCLASSEXA PWNDCLASSEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPWNDCLASSEXA NPWNDCLASSEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWNDCLASSEXA LPWNDCLASSEX;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_WNDCLASSA {
    UINT style;
    WNDPROC lpfnWndProc;
    ಪೂರ್ಣಾಂಕ cbClsExtra;
    ಪೂರ್ಣಾಂಕ cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCSTR lpszMenuName;
    LPCSTR lpszClassName;
  } WNDCLASSA,*PWNDCLASSA,*NPWNDCLASSA,*LPWNDCLASSA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_WNDCLASSW {
    UINT style;
    WNDPROC lpfnWndProc;
    ಪೂರ್ಣಾಂಕ cbClsExtra;
    ಪೂರ್ಣಾಂಕ cbWndExtra;
    HINSTANCE hInstance;
    HICON hIcon;
    HCURSOR hCursor;
    HBRUSH hbrBackground;
    LPCWSTR lpszMenuName;
    LPCWSTR lpszClassName;
  } WNDCLASSW,*PWNDCLASSW,*NPWNDCLASSW,*LPWNDCLASSW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WNDCLASSW WNDCLASS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWNDCLASSW PWNDCLASS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPWNDCLASSW NPWNDCLASS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWNDCLASSW LPWNDCLASS;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WNDCLASSA WNDCLASS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PWNDCLASSA PWNDCLASS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPWNDCLASSA NPWNDCLASS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPWNDCLASSA LPWNDCLASS;
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI Is_Hung_App_ಕಿಟಕಿ(HWND hwnd);
  WINUSERAPI VOID WINAPI DisableProcessWindowsGhosting(VOID);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMSG
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ಸಂದೇಶ {
    HWND hwnd;
    UINT ಸಂದೇಶ_2;
    WPARAM wParam;
    LPARAM lParam;
    DWORD ಸಮಯ;
    ಬಿಂದು_3 pt;
  } ಸಂದೇಶ_3,*PMSG,*NPMSG,*LPMSG;

#ವ್ಯಾಖ್ಯಾನಿಸು POINTSTOPOINT(pt,pts) { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts); (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

#ವ್ಯಾಖ್ಯಾನಿಸು POINTTOPOINTS(pt) (MAKELONG((ಗಿಡ್ಡ)((pt).x),(ಗಿಡ್ಡ)((pt).y)))
#ವ್ಯಾಖ್ಯಾನಿಸು MAKEWPARAM(l,h) ((WPARAM)(DWORD)MAKELONG(l,h))
#ವ್ಯಾಖ್ಯಾನಿಸು MAKELPARAM(l,h) ((LPARAM)(DWORD)MAKELONG(l,h))
#ವ್ಯಾಖ್ಯಾನಿಸು MAKELRESULT(l,h) ((LRESULT)(DWORD)MAKELONG(l,h))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINOFFSETS
#ವ್ಯಾಖ್ಯಾನಿಸು GWL_WNDPROC (-4)
#ವ್ಯಾಖ್ಯಾನಿಸು GWL_HINSTANCE (-6)
#ವ್ಯಾಖ್ಯಾನಿಸು GWL_HWNDPARENT (-8)
#ವ್ಯಾಖ್ಯಾನಿಸು GWL_STYLE (-16)
#ವ್ಯಾಖ್ಯಾನಿಸು GWL_EXSTYLE (-20)
#ವ್ಯಾಖ್ಯಾನಿಸು GWL_USERDATA (-21)
#ವ್ಯಾಖ್ಯಾನಿಸು GWL_ID (-12)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GWL_WNDPROC
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GWL_HINSTANCE
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GWL_HWNDPARENT
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GWL_USERDATA
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು GWLP_WNDPROC (-4)
#ವ್ಯಾಖ್ಯಾನಿಸು GWLP_HINSTANCE (-6)
#ವ್ಯಾಖ್ಯಾನಿಸು GWLP_HWNDPARENT (-8)
#ವ್ಯಾಖ್ಯಾನಿಸು GWLP_USERDATA (-21)
#ವ್ಯಾಖ್ಯಾನಿಸು GWLP_ID (-12)

#ವ್ಯಾಖ್ಯಾನಿಸು GCL_MENUNAME (-8)
#ವ್ಯಾಖ್ಯಾನಿಸು GCL_HBRBACKGROUND (-10)
#ವ್ಯಾಖ್ಯಾನಿಸು GCL_HCURSOR (-12)
#ವ್ಯಾಖ್ಯಾನಿಸು GCL_HICON (-14)
#ವ್ಯಾಖ್ಯಾನಿಸು GCL_HMODULE (-16)
#ವ್ಯಾಖ್ಯಾನಿಸು GCL_CBWNDEXTRA (-18)
#ವ್ಯಾಖ್ಯಾನಿಸು GCL_CBCLSEXTRA (-20)
#ವ್ಯಾಖ್ಯಾನಿಸು GCL_WNDPROC (-24)
#ವ್ಯಾಖ್ಯಾನಿಸು GCL_STYLE (-26)
#ವ್ಯಾಖ್ಯಾನಿಸು GCW_ATOM (-32)
#ವ್ಯಾಖ್ಯಾನಿಸು GCL_HICONSM (-34)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GCL_MENUNAME
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GCL_HBRBACKGROUND
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GCL_HCURSOR
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GCL_HICON
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GCL_HMODULE
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GCL_WNDPROC
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು GCL_HICONSM
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು GCLP_MENUNAME (-8)
#ವ್ಯಾಖ್ಯಾನಿಸು GCLP_HBRBACKGROUND (-10)
#ವ್ಯಾಖ್ಯಾನಿಸು GCLP_HCURSOR (-12)
#ವ್ಯಾಖ್ಯಾನಿಸು GCLP_HICON (-14)
#ವ್ಯಾಖ್ಯಾನಿಸು GCLP_HMODULE (-16)
#ವ್ಯಾಖ್ಯಾನಿಸು GCLP_WNDPROC (-24)
#ವ್ಯಾಖ್ಯಾನಿಸು GCLP_HICONSM (-34)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINMESSAGES

#ವ್ಯಾಖ್ಯಾನಿಸು WM_NULL 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CREATE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು WM_DESTROY 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOVE 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ಗಾತ್ರ 0x0005

#ವ್ಯಾಖ್ಯಾನಿಸು WM_ACTIVATE 0x0006

#ವ್ಯಾಖ್ಯಾನಿಸು WA_INACTIVE 0
#ವ್ಯಾಖ್ಯಾನಿಸು WA_ಸಕ್ರಿಯ 1
#ವ್ಯಾಖ್ಯಾನಿಸು WA_CLICKACTIVE 2

#ವ್ಯಾಖ್ಯಾನಿಸು WM_SETFOCUS 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು WM_KILLFOCUS 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ENABLE 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SETREDRAW 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SETTEXT 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು WM_GETTEXT 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು WM_GETTEXTLENGTH 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು WM_PAINT 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CLOSE 0x0010
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32_WCE
#ವ್ಯಾಖ್ಯಾನಿಸು WM_QUERYENDSESSION 0x0011
#ವ್ಯಾಖ್ಯಾನಿಸು WM_QUERYOPEN 0x0013
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ENDSESSION 0x0016
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು WM_QUIT 0x0012
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ERASEBKGND 0x0014
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SYSCOLORCHANGE 0x0015
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SHOWWINDOW 0x0018
#ವ್ಯಾಖ್ಯಾನಿಸು WM_WININICHANGE 0x001A
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SETTINGCHANGE WM_WININICHANGE
#ವ್ಯಾಖ್ಯಾನಿಸು WM_DEVMODECHANGE 0x001B
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ACTIVATEAPP 0x001C
#ವ್ಯಾಖ್ಯಾನಿಸು WM_FONTCHANGE 0x001D
#ವ್ಯಾಖ್ಯಾನಿಸು WM_TIMECHANGE 0x001E
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CANCELMODE 0x001F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SETCURSOR 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOUSEACTIVATE 0x0021
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CHILDACTIVATE 0x0022
#ವ್ಯಾಖ್ಯಾನಿಸು WM_QUEUESYNC 0x0023

#ವ್ಯಾಖ್ಯಾನಿಸು WM_GETMINMAXINFO 0x0024

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MINMAXINFO {
    ಬಿಂದು_3 ptReserved;
    ಬಿಂದು_3 pt_Max_ಗಾತ್ರ;
    ಬಿಂದು_3 ptMaxPosition;
    ಬಿಂದು_3 pt_Min_Track_ಗಾತ್ರ;
    ಬಿಂದು_3 pt_Max_Track_ಗಾತ್ರ;
  } MINMAXINFO,*PMINMAXINFO,*LPMINMAXINFO;

#ವ್ಯಾಖ್ಯಾನಿಸು WM_PAINTICON 0x0026
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ICONERASEBKGND 0x0027
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NEXTDLGCTL 0x0028
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SPOOLERSTATUS 0x002A
#ವ್ಯಾಖ್ಯಾನಿಸು WM_DRAWITEM 0x002B
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MEASUREITEM 0x002C
#ವ್ಯಾಖ್ಯಾನಿಸು WM_DELETEITEM 0x002D
#ವ್ಯಾಖ್ಯಾನಿಸು WM_VKEYTOITEM 0x002E
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CHARTOITEM 0x002F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SETFONT 0x0030
#ವ್ಯಾಖ್ಯಾನಿಸು WM_GETFONT 0x0031
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SETHOTKEY 0x0032
#ವ್ಯಾಖ್ಯಾನಿಸು WM_GETHOTKEY 0x0033
#ವ್ಯಾಖ್ಯಾನಿಸು WM_QUERYDRAGICON 0x0037
#ವ್ಯಾಖ್ಯಾನಿಸು WM_COMPAREITEM 0x0039
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32_WCE
#ವ್ಯಾಖ್ಯಾನಿಸು WM_GETOBJECT 0x003D
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು WM_COMPACTING 0x0041
#ವ್ಯಾಖ್ಯಾನಿಸು WM_COMMNOTIFY 0x0044
#ವ್ಯಾಖ್ಯಾನಿಸು WM_WINDOWPOSCHANGING 0x0046
#ವ್ಯಾಖ್ಯಾನಿಸು WM_WINDOWPOSCHANGED 0x0047

#ವ್ಯಾಖ್ಯಾನಿಸು WM_POWER 0x0048

#ವ್ಯಾಖ್ಯಾನಿಸು PWR_OK 1
#ವ್ಯಾಖ್ಯಾನಿಸು PWR_FAIL (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು PWR_SUSPENDREQUEST 1
#ವ್ಯಾಖ್ಯಾನಿಸು PWR_SUSPENDRESUME 2
#ವ್ಯಾಖ್ಯಾನಿಸು PWR_CRITICALRESUME 3

#ವ್ಯಾಖ್ಯಾನಿಸು WM_COPYDATA 0x004A
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CANCELJOURNAL 0x004B

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_COPYDATASTRUCT {
    ULONG_PTR dw_ದತ್ತಾಂಶ;
    DWORD cb_ದತ್ತಾಂಶ;
    PVOID lp_ದತ್ತಾಂಶ;
  } COPYDATASTRUCT,*PCOPYDATASTRUCT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MDINEXTMENU {
    HMENU hmenu_ಒಳ;
    HMENU hmenu_ಮುಂದಿನ;
    HWND hwnd_ಮುಂದಿನ;
  } MDINEXTMENU,*PMDINEXTMENU,*LPMDINEXTMENU;

#ವ್ಯಾಖ್ಯಾನಿಸು WM_NOTIFY 0x004E
#ವ್ಯಾಖ್ಯಾನಿಸು WM_INPUTLANGCHANGEREQUEST 0x0050
#ವ್ಯಾಖ್ಯಾನಿಸು WM_INPUTLANGCHANGE 0x0051
#ವ್ಯಾಖ್ಯಾನಿಸು WM_TCARD 0x0052
#ವ್ಯಾಖ್ಯಾನಿಸು WM_HELP 0x0053
#ವ್ಯಾಖ್ಯಾನಿಸು WM_USERCHANGED 0x0054
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NOTIFYFORMAT 0x0055

#ವ್ಯಾಖ್ಯಾನಿಸು NFR_ANSI 1
#ವ್ಯಾಖ್ಯಾನಿಸು NFR_UNICODE 2
#ವ್ಯಾಖ್ಯಾನಿಸು NF_QUERY 3
#ವ್ಯಾಖ್ಯಾನಿಸು NF_REQUERY 4

#ವ್ಯಾಖ್ಯಾನಿಸು WM_CONTEXTMENU 0x007B
#ವ್ಯಾಖ್ಯಾನಿಸು WM_STYLECHANGING 0x007C
#ವ್ಯಾಖ್ಯಾನಿಸು WM_STYLECHANGED 0x007D
#ವ್ಯಾಖ್ಯಾನಿಸು WM_DISPLAYCHANGE 0x007E
#ವ್ಯಾಖ್ಯಾನಿಸು WM_GETICON 0x007F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SETICON 0x0080

#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCCREATE 0x0081
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCDESTROY 0x0082
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCCALCSIZE 0x0083
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCHITTEST 0x0084
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCPAINT 0x0085
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCACTIVATE 0x0086
#ವ್ಯಾಖ್ಯಾನಿಸು WM_GETDLGCODE 0x0087
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32_WCE
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SYNCPAINT 0x0088
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCMOUSEMOVE 0x00A0
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCLBUTTONDOWN 0x00A1
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCLBUTTONUP 0x00A2
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCLBUTTONDBLCLK 0x00A3
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCRBUTTONDOWN 0x00A4
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCRBUTTONUP 0x00A5
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCRBUTTONDBLCLK 0x00A6
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCMBUTTONDOWN 0x00A7
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCMBUTTONUP 0x00A8
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCMBUTTONDBLCLK 0x00A9

#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCXBUTTONDOWN 0x00AB
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCXBUTTONUP 0x00AC
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCXBUTTONDBLCLK 0x00AD
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ಒಳಹರಿವು 0x00FF
#ವ್ಯಾಖ್ಯಾನಿಸು WM_KEYFIRST 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು WM_KEYDOWN 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು WM_KEYUP 0x0101
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CHAR 0x0102
#ವ್ಯಾಖ್ಯಾನಿಸು WM_DEADCHAR 0x0103
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SYSKEYDOWN 0x0104
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SYSKEYUP 0x0105
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SYSCHAR 0x0106
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SYSDEADCHAR 0x0107
#ವ್ಯಾಖ್ಯಾನಿಸು WM_UNICHAR 0x0109
#ವ್ಯಾಖ್ಯಾನಿಸು WM_KEYLAST 0x0109
#ವ್ಯಾಖ್ಯಾನಿಸು UNICODE_NOCHAR 0xFFFF
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_STARTCOMPOSITION 0x010D
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_ENDCOMPOSITION 0x010E
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_COMPOSITION 0x010F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_KEYLAST 0x010F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_INITDIALOG 0x0110
#ವ್ಯಾಖ್ಯಾನಿಸು WM_COMMAND 0x0111
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SYSCOMMAND 0x0112
#ವ್ಯಾಖ್ಯಾನಿಸು WM_TIMER 0x0113
#ವ್ಯಾಖ್ಯಾನಿಸು WM_HSCROLL 0x0114
#ವ್ಯಾಖ್ಯಾನಿಸು WM_VSCROLL 0x0115
#ವ್ಯಾಖ್ಯಾನಿಸು WM_INITMENU 0x0116
#ವ್ಯಾಖ್ಯಾನಿಸು WM_INITMENUPOPUP 0x0117
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MENUSELECT 0x011F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MENUCHAR 0x0120
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ENTERIDLE 0x0121
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32_WCE
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MENURBUTTONUP 0x0122
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MENUDRAG 0x0123
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MENUGETOBJECT 0x0124
#ವ್ಯಾಖ್ಯಾನಿಸು WM_UNINITMENUPOPUP 0x0125
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MENUCOMMAND 0x0126

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32_WCE
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CHANGEUISTATE 0x0127
#ವ್ಯಾಖ್ಯಾನಿಸು WM_UPDATEUISTATE 0x0128
#ವ್ಯಾಖ್ಯಾನಿಸು WM_QUERYUISTATE 0x0129

#ವ್ಯಾಖ್ಯಾನಿಸು UIS_ಗಣ 1
#ವ್ಯಾಖ್ಯಾನಿಸು UIS_CLEAR 2
#ವ್ಯಾಖ್ಯಾನಿಸು UIS_INITIALIZE 3

#ವ್ಯಾಖ್ಯಾನಿಸು UISF_HIDEFOCUS 0x1
#ವ್ಯಾಖ್ಯಾನಿಸು UISF_HIDEACCEL 0x2
#ವ್ಯಾಖ್ಯಾನಿಸು UISF_ಸಕ್ರಿಯ 0x4
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು WM_CTLCOLORMSGBOX 0x0132
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CTLCOLOREDIT 0x0133
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CTLCOLORLISTBOX 0x0134
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CTLCOLORBTN 0x0135
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CTLCOLORDLG 0x0136
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CTLCOLORSCROLLBAR 0x0137
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CTLCOLORSTATIC 0x0138
#ವ್ಯಾಖ್ಯಾನಿಸು MN_GETHMENU 0x01E1

#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOUSEFIRST 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOUSEMOVE 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು WM_LBUTTONDOWN 0x0201
#ವ್ಯಾಖ್ಯಾನಿಸು WM_LBUTTONUP 0x0202
#ವ್ಯಾಖ್ಯಾನಿಸು WM_LBUTTONDBLCLK 0x0203
#ವ್ಯಾಖ್ಯಾನಿಸು WM_RBUTTONDOWN 0x0204
#ವ್ಯಾಖ್ಯಾನಿಸು WM_RBUTTONUP 0x0205
#ವ್ಯಾಖ್ಯಾನಿಸು WM_RBUTTONDBLCLK 0x0206
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MBUTTONDOWN 0x0207
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MBUTTONUP 0x0208
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MBUTTONDBLCLK 0x0209
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOUSEWHEEL 0x020A
#ವ್ಯಾಖ್ಯಾನಿಸು WM_XBUTTONDOWN 0x020B
#ವ್ಯಾಖ್ಯಾನಿಸು WM_XBUTTONUP 0x020C
#ವ್ಯಾಖ್ಯಾನಿಸು WM_XBUTTONDBLCLK 0x020D
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOUSEHWHEEL 0x020E
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOUSELAST 0x020E

#ವ್ಯಾಖ್ಯಾನಿಸು WHEEL_DELTA 120
#ವ್ಯಾಖ್ಯಾನಿಸು GET_WHEEL_DELTA_WPARAM(wParam) ((ಗಿಡ್ಡ)HIWORD(wParam))

#ವ್ಯಾಖ್ಯಾನಿಸು WHEEL_PAGESCROLL (UINT_MAX)

#ವ್ಯಾಖ್ಯಾನಿಸು GET_KEYSTATE_WPARAM(wParam) (LOWORD(wParam))
#ವ್ಯಾಖ್ಯಾನಿಸು GET_NCHITTEST_WPARAM(wParam) ((ಗಿಡ್ಡ)LOWORD(wParam))
#ವ್ಯಾಖ್ಯಾನಿಸು GET_XBUTTON_WPARAM(wParam) (HIWORD(wParam))

#ವ್ಯಾಖ್ಯಾನಿಸು XBUTTON1 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು XBUTTON2 0x0002

#ವ್ಯಾಖ್ಯಾನಿಸು WM_PARENTNOTIFY 0x0210
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ENTERMENULOOP 0x0211
#ವ್ಯಾಖ್ಯಾನಿಸು WM_EXITMENULOOP 0x0212

#ವ್ಯಾಖ್ಯಾನಿಸು WM_NEXTMENU 0x0213
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SIZING 0x0214
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CAPTURECHANGED 0x0215
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOVING 0x0216

#ವ್ಯಾಖ್ಯಾನಿಸು WM_POWERBROADCAST 0x0218

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WIN32_WCE
#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMQUERYSUSPEND 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMQUERYSTANDBY 0x0001

#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMQUERYSUSPENDFAILED 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMQUERYSTANDBYFAILED 0x0003

#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMSUSPEND 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMSTANDBY 0x0005

#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMRESUMECRITICAL 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMRESUMESUSPEND 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMRESUMESTANDBY 0x0008

#ವ್ಯಾಖ್ಯಾನಿಸು PBTF_APMRESUMEFROMFAILURE 0x00000001

#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMBATTERYLOW 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMPOWERSTATUSCHANGE 0x000A

#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMOEMEVENT 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು PBT_APMRESUMEAUTOMATIC 0x0012
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು WM_DEVICECHANGE 0x0219

#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDICREATE 0x0220
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDIDESTROY 0x0221
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDIACTIVATE 0x0222
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDIRESTORE 0x0223
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDINEXT 0x0224
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDIMAXIMIZE 0x0225
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDITILE 0x0226
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDICASCADE 0x0227
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDIICONARRANGE 0x0228
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDIGETACTIVE 0x0229

#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDISETMENU 0x0230
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ENTERSIZEMOVE 0x0231
#ವ್ಯಾಖ್ಯಾನಿಸು WM_EXITSIZEMOVE 0x0232
#ವ್ಯಾಖ್ಯಾನಿಸು WM_DROPFILES 0x0233
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MDIREFRESHMENU 0x0234

#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_SETCONTEXT 0x0281
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_NOTIFY 0x0282
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_CONTROL 0x0283
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_COMPOSITIONFULL 0x0284
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_SELECT 0x0285
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_CHAR 0x0286
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_REQUEST 0x0288
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_KEYDOWN 0x0290
#ವ್ಯಾಖ್ಯಾನಿಸು WM_IME_KEYUP 0x0291

#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOUSEHOVER 0x02A1
#ವ್ಯಾಖ್ಯಾನಿಸು WM_MOUSELEAVE 0x02A3
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCMOUSEHOVER 0x02A0
#ವ್ಯಾಖ್ಯಾನಿಸು WM_NCMOUSELEAVE 0x02A2
#ವ್ಯಾಖ್ಯಾನಿಸು WM_WTSSESSION_CHANGE 0x02B1
#ವ್ಯಾಖ್ಯಾನಿಸು WM_TABLET_ಮೊದಲ 0x02c0
#ವ್ಯಾಖ್ಯಾನಿಸು WM_TABLET_ಕೊನೆಯ 0x02df
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CUT 0x0300
#ವ್ಯಾಖ್ಯಾನಿಸು WM_COPY 0x0301
#ವ್ಯಾಖ್ಯಾನಿಸು WM_PASTE 0x0302
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CLEAR 0x0303
#ವ್ಯಾಖ್ಯಾನಿಸು WM_UNDO 0x0304
#ವ್ಯಾಖ್ಯಾನಿಸು WM_RENDERFORMAT 0x0305
#ವ್ಯಾಖ್ಯಾನಿಸು WM_RENDERALLFORMATS 0x0306
#ವ್ಯಾಖ್ಯಾನಿಸು WM_DESTROYCLIPBOARD 0x0307
#ವ್ಯಾಖ್ಯಾನಿಸು WM_DRAWCLIPBOARD 0x0308
#ವ್ಯಾಖ್ಯಾನಿಸು WM_PAINTCLIPBOARD 0x0309
#ವ್ಯಾಖ್ಯಾನಿಸು WM_VSCROLLCLIPBOARD 0x030A
#ವ್ಯಾಖ್ಯಾನಿಸು WM_SIZECLIPBOARD 0x030B
#ವ್ಯಾಖ್ಯಾನಿಸು WM_ASKCBFORMATNAME 0x030C
#ವ್ಯಾಖ್ಯಾನಿಸು WM_CHANGECBCHAIN 0x030D
#ವ್ಯಾಖ್ಯಾನಿಸು WM_HSCROLLCLIPBOARD 0x030E
#ವ್ಯಾಖ್ಯಾನಿಸು WM_QUERYNEWPALETTE 0x030F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_PALETTEISCHANGING 0x0310
#ವ್ಯಾಖ್ಯಾನಿಸು WM_PALETTECHANGED 0x0311
#ವ್ಯಾಖ್ಯಾನಿಸು WM_HOTKEY 0x0312
#ವ್ಯಾಖ್ಯಾನಿಸು WM_PRINT 0x0317
#ವ್ಯಾಖ್ಯಾನಿಸು WM_PRINTCLIENT 0x0318
#ವ್ಯಾಖ್ಯಾನಿಸು WM_APPCOMMAND 0x0319
#ವ್ಯಾಖ್ಯಾನಿಸು WM_THEMECHANGED 0x031A
#ವ್ಯಾಖ್ಯಾನಿಸು WM_HANDHELDFIRST 0x0358
#ವ್ಯಾಖ್ಯಾನಿಸು WM_HANDHELDLAST 0x035F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_AFXFIRST 0x0360
#ವ್ಯಾಖ್ಯಾನಿಸು WM_AFXLAST 0x037F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_PENWINFIRST 0x0380
#ವ್ಯಾಖ್ಯಾನಿಸು WM_PENWINLAST 0x038F
#ವ್ಯಾಖ್ಯಾನಿಸು WM_APP 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು WM_USER 0x0400

#ವ್ಯಾಖ್ಯಾನಿಸು WMSZ_ಎಡ 1
#ವ್ಯಾಖ್ಯಾನಿಸು WMSZ_ಬಲ 2
#ವ್ಯಾಖ್ಯಾನಿಸು WMSZ_ತುದಿ 3
#ವ್ಯಾಖ್ಯಾನಿಸು WMSZ_TOPLEFT 4
#ವ್ಯಾಖ್ಯಾನಿಸು WMSZ_TOPRIGHT 5
#ವ್ಯಾಖ್ಯಾನಿಸು WMSZ_BOTTOM 6
#ವ್ಯಾಖ್ಯಾನಿಸು WMSZ_BOTTOMLEFT 7
#ವ್ಯಾಖ್ಯಾನಿಸು WMSZ_BOTTOMRIGHT 8

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NONCMESSAGES

#ವ್ಯಾಖ್ಯಾನಿಸು HTERROR (-2)
#ವ್ಯಾಖ್ಯಾನಿಸು HTTRANSPARENT (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು HTNOWHERE 0
#ವ್ಯಾಖ್ಯಾನಿಸು HTCLIENT 1
#ವ್ಯಾಖ್ಯಾನಿಸು HTCAPTION 2
#ವ್ಯಾಖ್ಯಾನಿಸು HTSYSMENU 3
#ವ್ಯಾಖ್ಯಾನಿಸು HTGROWBOX 4
#ವ್ಯಾಖ್ಯಾನಿಸು HTSIZE HTGROWBOX
#ವ್ಯಾಖ್ಯಾನಿಸು HTMENU 5
#ವ್ಯಾಖ್ಯಾನಿಸು HTHSCROLL 6
#ವ್ಯಾಖ್ಯಾನಿಸು HTVSCROLL 7
#ವ್ಯಾಖ್ಯಾನಿಸು HTMINBUTTON 8
#ವ್ಯಾಖ್ಯಾನಿಸು HTMAXBUTTON 9
#ವ್ಯಾಖ್ಯಾನಿಸು HTLEFT 10
#ವ್ಯಾಖ್ಯಾನಿಸು HTRIGHT 11
#ವ್ಯಾಖ್ಯಾನಿಸು HTTOP 12
#ವ್ಯಾಖ್ಯಾನಿಸು HTTOPLEFT 13
#ವ್ಯಾಖ್ಯಾನಿಸು HTTOPRIGHT 14
#ವ್ಯಾಖ್ಯಾನಿಸು HTBOTTOM 15
#ವ್ಯಾಖ್ಯಾನಿಸು HTBOTTOMLEFT 16
#ವ್ಯಾಖ್ಯಾನಿಸು HTBOTTOMRIGHT 17
#ವ್ಯಾಖ್ಯಾನಿಸು HTBORDER 18
#ವ್ಯಾಖ್ಯಾನಿಸು HTREDUCE HTMINBUTTON
#ವ್ಯಾಖ್ಯಾನಿಸು HTZOOM HTMAXBUTTON
#ವ್ಯಾಖ್ಯಾನಿಸು HTSIZEFIRST HTLEFT
#ವ್ಯಾಖ್ಯಾನಿಸು HTSIZELAST HTBOTTOMRIGHT
#ವ್ಯಾಖ್ಯಾನಿಸು HTOBJECT 19
#ವ್ಯಾಖ್ಯಾನಿಸು HTCLOSE 20
#ವ್ಯಾಖ್ಯಾನಿಸು HTHELP 21

#ವ್ಯಾಖ್ಯಾನಿಸು SMTO_ಸಾಮಾನ್ಯ 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು SMTO_ಖಂಡ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು SMTO_ABORTIFHUNG 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು SMTO_NOTIMEOUTIFNOTHUNG 0x0008
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು MA_ACTIVATE 1
#ವ್ಯಾಖ್ಯಾನಿಸು MA_ACTIVATEANDEAT 2
#ವ್ಯಾಖ್ಯಾನಿಸು MA_NOACTIVATE 3
#ವ್ಯಾಖ್ಯಾನಿಸು MA_NOACTIVATEANDEAT 4

#ವ್ಯಾಖ್ಯಾನಿಸು ICON_SMALL 0
#ವ್ಯಾಖ್ಯಾನಿಸು ICON_BIG 1
#ವ್ಯಾಖ್ಯಾನಿಸು ICON_SMALL2 2

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_ಕಿಟಕಿ_ಸಂದೇಶ ರಿಜಿಸ್ಟರ್_ಕಿಟಕಿ_ಸಂದೇಶ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_ಕಿಟಕಿ_ಸಂದೇಶ ರಿಜಿಸ್ಟರ್_ಕಿಟಕಿ_ಸಂದೇಶ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI UINT WINAPI ರಿಜಿಸ್ಟರ್_ಕಿಟಕಿ_ಸಂದೇಶ_A(LPCSTR lpString);
  WINUSERAPI UINT WINAPI ರಿಜಿಸ್ಟರ್_ಕಿಟಕಿ_ಸಂದೇಶ_W(LPCWSTR lpString);

#ವ್ಯಾಖ್ಯಾನಿಸು ಗಾತ್ರ_RESTORED 0
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಾತ್ರ_MINIMIZED 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಾತ್ರ_MAXIMIZED 2
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಾತ್ರ_MAXSHOW 3
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಾತ್ರ_MAXHIDE 4

#ವ್ಯಾಖ್ಯಾನಿಸು SIZENORMAL ಗಾತ್ರ_RESTORED
#ವ್ಯಾಖ್ಯಾನಿಸು SIZEICONIC ಗಾತ್ರ_MINIMIZED
#ವ್ಯಾಖ್ಯಾನಿಸು SIZEFULLSCREEN ಗಾತ್ರ_MAXIMIZED
#ವ್ಯಾಖ್ಯಾನಿಸು SIZEZOOMSHOW ಗಾತ್ರ_MAXSHOW
#ವ್ಯಾಖ್ಯಾನಿಸು SIZEZOOMHIDE ಗಾತ್ರ_MAXHIDE

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_WINDOWPOS {
    HWND hwnd;
    HWND hwnd_ಸೇರಿಸು_After;
    ಪೂರ್ಣಾಂಕ x;
    ಪೂರ್ಣಾಂಕ y;
    ಪೂರ್ಣಾಂಕ cx;
    ಪೂರ್ಣಾಂಕ cy;
    UINT flags;
  } WINDOWPOS,*LPWINDOWPOS,*PWINDOWPOS;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_NCCALCSIZE_PARAMS {
    RECT rgrc[3];
    PWINDOWPOS lppos;
  } NCCALCSIZE_PARAMS,*LPNCCALCSIZE_PARAMS;

#ವ್ಯಾಖ್ಯಾನಿಸು WVR_ALIGNTOP 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು WVR_ALIGNLEFT 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು WVR_ALIGNBOTTOM 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು WVR_ALIGNRIGHT 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು WVR_HREDRAW 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು WVR_VREDRAW 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು WVR_REDRAW (WVR_HREDRAW | WVR_VREDRAW)
#ವ್ಯಾಖ್ಯಾನಿಸು WVR_VALIDRECTS 0x0400

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOKEYSTATES

#ವ್ಯಾಖ್ಯಾನಿಸು MK_LBUTTON 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು MK_RBUTTON 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು MK_ಸರಿಸು 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು MK_CONTROL 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು MK_MBUTTON 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು MK_XBUTTON1 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು MK_XBUTTON2 0x0040
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOTRACKMOUSEEVENT
#ವ್ಯಾಖ್ಯಾನಿಸು TME_HOVER 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು TME_LEAVE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು TME_NONCLIENT 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು TME_QUERY 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು TME_CANCEL 0x80000000

#ವ್ಯಾಖ್ಯಾನಿಸು HOVER_DEFAULT 0xFFFFFFFF
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_TRACKMOUSEEVENT {
    DWORD cb_ಗಾತ್ರ;
    DWORD dwFlags;
    HWND hwndTrack;
    DWORD dw_Hover_ಸಮಯ;
  } TRACKMOUSEEVENT,*LPTRACKMOUSEEVENT;

  WINUSERAPI WINBOOL WINAPI TrackMouseEvent(LPTRACKMOUSEEVENT lpEventTrack);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINSTYLES

#ವ್ಯಾಖ್ಯಾನಿಸು WS_OVERLAPPED 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_POPUP 0x80000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_ಮಗು 0x40000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_MINIMIZE 0x20000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_VISIBLE 0x10000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_DISABLED 0x08000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_CLIPSIBLINGS 0x04000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_CLIPCHILDREN 0x02000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_MAXIMIZE 0x01000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_CAPTION 0x00C00000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_BORDER 0x00800000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_DLGFRAME 0x00400000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_VSCROLL 0x00200000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_HSCROLL 0x00100000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_SYSMENU 0x00080000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_THICKFRAME 0x00040000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_ಗುಂಪು 0x00020000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_TABSTOP 0x00010000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_MINIMIZEBOX 0x00020000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_MAXIMIZEBOX 0x00010000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_TILED WS_OVERLAPPED
#ವ್ಯಾಖ್ಯಾನಿಸು WS_ICONIC WS_MINIMIZE
#ವ್ಯಾಖ್ಯಾನಿಸು WS_SIZEBOX WS_THICKFRAME
#ವ್ಯಾಖ್ಯಾನಿಸು WS_TILEDWINDOW WS_OVERLAPPEDWINDOW
#ವ್ಯಾಖ್ಯಾನಿಸು WS_OVERLAPPEDWINDOW (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX)
#ವ್ಯಾಖ್ಯಾನಿಸು WS_POPUPWINDOW (WS_POPUP | WS_BORDER | WS_SYSMENU)
#ವ್ಯಾಖ್ಯಾನಿಸು WS_CHILDWINDOW (WS_ಮಗು)

#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_DLGMODALFRAME 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_NOPARENTNOTIFY 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_TOPMOST 0x00000008L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_ACCEPTFILES 0x00000010L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_TRANSPARENT 0x00000020L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_MDICHILD 0x00000040L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_TOOLWINDOW 0x00000080L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_WINDOWEDGE 0x00000100L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_CLIENTEDGE 0x00000200L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_CONTEXTHELP 0x00000400L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_ಬಲ 0x00001000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_ಎಡ 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_RTLREADING 0x00002000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_LTRREADING 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_LEFTSCROLLBAR 0x00004000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_RIGHTSCROLLBAR 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_CONTROLPARENT 0x00010000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_STATICEDGE 0x00020000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_APPWINDOW 0x00040000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_OVERLAPPEDWINDOW (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_PALETTEWINDOW (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_LAYERED 0x00080000
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_NOINHERITLAYOUT 0x00100000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_LAYOUTRTL 0x00400000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_COMPOSITED 0x02000000L
#ವ್ಯಾಖ್ಯಾನಿಸು WS_EX_NOACTIVATE 0x08000000L

#ವ್ಯಾಖ್ಯಾನಿಸು CS_VREDRAW 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು CS_HREDRAW 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು CS_DBLCLKS 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು CS_OWNDC 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು CS_CLASSDC 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು CS_PARENTDC 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು CS_NOCLOSE 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು CS_SAVEBITS 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು CS_BYTEALIGNCLIENT 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು CS_BYTEALIGNWINDOW 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು CS_GLOBALCLASS 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು CS_IME 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು CS_DROPSHADOW 0x00020000
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು PRF_CHECKVISIBLE 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು PRF_NONCLIENT 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು PRF_CLIENT 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು PRF_ERASEBKGND 0x00000008L
#ವ್ಯಾಖ್ಯಾನಿಸು PRF_CHILDREN 0x00000010L
#ವ್ಯಾಖ್ಯಾನಿಸು PRF_OWNED 0x00000020L

#ವ್ಯಾಖ್ಯಾನಿಸು BDR_RAISEDOUTER 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು BDR_SUNKENOUTER 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು BDR_RAISEDINNER 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು BDR_SUNKENINNER 0x0008

#ವ್ಯಾಖ್ಯಾನಿಸು BDR_OUTER (BDR_RAISEDOUTER | BDR_SUNKENOUTER)
#ವ್ಯಾಖ್ಯಾನಿಸು BDR_INNER (BDR_RAISEDINNER | BDR_SUNKENINNER)
#ವ್ಯಾಖ್ಯಾನಿಸು BDR_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#ವ್ಯಾಖ್ಯಾನಿಸು BDR_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)

#ವ್ಯಾಖ್ಯಾನಿಸು ಅಂಚು_RAISED (BDR_RAISEDOUTER | BDR_RAISEDINNER)
#ವ್ಯಾಖ್ಯಾನಿಸು ಅಂಚು_SUNKEN (BDR_SUNKENOUTER | BDR_SUNKENINNER)
#ವ್ಯಾಖ್ಯಾನಿಸು ಅಂಚು_ETCHED (BDR_SUNKENOUTER | BDR_RAISEDINNER)
#ವ್ಯಾಖ್ಯಾನಿಸು ಅಂಚು_BUMP (BDR_RAISEDOUTER | BDR_SUNKENINNER)

#ವ್ಯಾಖ್ಯಾನಿಸು BF_ಎಡ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು BF_ತುದಿ 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು BF_ಬಲ 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು BF_BOTTOM 0x0008

#ವ್ಯಾಖ್ಯಾನಿಸು BF_TOPLEFT (BF_ತುದಿ | BF_ಎಡ)
#ವ್ಯಾಖ್ಯಾನಿಸು BF_TOPRIGHT (BF_ತುದಿ | BF_ಬಲ)
#ವ್ಯಾಖ್ಯಾನಿಸು BF_BOTTOMLEFT (BF_BOTTOM | BF_ಎಡ)
#ವ್ಯಾಖ್ಯಾನಿಸು BF_BOTTOMRIGHT (BF_BOTTOM | BF_ಬಲ)
#ವ್ಯಾಖ್ಯಾನಿಸು BF_RECT (BF_ಎಡ | BF_ತುದಿ | BF_ಬಲ | BF_BOTTOM)

#ವ್ಯಾಖ್ಯಾನಿಸು BF_DIAGONAL 0x0010

#ವ್ಯಾಖ್ಯಾನಿಸು BF_DIAGONAL_ENDTOPRIGHT (BF_DIAGONAL | BF_ತುದಿ | BF_ಬಲ)
#ವ್ಯಾಖ್ಯಾನಿಸು BF_DIAGONAL_ENDTOPLEFT (BF_DIAGONAL | BF_ತುದಿ | BF_ಎಡ)
#ವ್ಯಾಖ್ಯಾನಿಸು BF_DIAGONAL_ENDBOTTOMLEFT (BF_DIAGONAL | BF_BOTTOM | BF_ಎಡ)
#ವ್ಯಾಖ್ಯಾನಿಸು BF_DIAGONAL_ENDBOTTOMRIGHT (BF_DIAGONAL | BF_BOTTOM | BF_ಬಲ)

#ವ್ಯಾಖ್ಯಾನಿಸು BF_ಮಧ್ಯ 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು BF_SOFT 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು BF_ADJUST 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು BF_FLAT 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು BF_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_ಅಂಚು(HDC hdc,LPRECT qrc,UINT ಅಂಚು,UINT grfFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು DFC_CAPTION 1
#ವ್ಯಾಖ್ಯಾನಿಸು DFC_MENU 2
#ವ್ಯಾಖ್ಯಾನಿಸು DFC_SCROLL 3
#ವ್ಯಾಖ್ಯಾನಿಸು DFC_BUTTON 4
#ವ್ಯಾಖ್ಯಾನಿಸು DFC_POPUPMENU 5

#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_CAPTIONCLOSE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_CAPTIONMIN 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_CAPTIONMAX 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_CAPTIONRESTORE 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_CAPTIONHELP 0x0004

#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_MENUARROW 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_MENUCHECK 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_MENUBULLET 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_MENUARROWRIGHT 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_SCROLLUP 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_SCROLLDOWN 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_SCROLLLEFT 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_SCROLLRIGHT 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_SCROLLCOMBOBOX 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_SCROLLSIZEGRIP 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_SCROLLSIZEGRIPRIGHT 0x0010

#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_BUTTONCHECK 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_BUTTONRADIOIMAGE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_BUTTONRADIOMASK 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_BUTTONRADIO 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_BUTTON3STATE 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_BUTTONPUSH 0x0010

#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_INACTIVE 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_PUSHED 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_CHECKED 0x0400

#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_TRANSPARENT 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_HOT 0x1000

#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_ADJUSTRECT 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_FLAT 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು DFCS_MONO 0x8000

  WINUSERAPI WINBOOL WINAPI Draw_ಚೌಕಟ್ಟು_Control(HDC,LPRECT,UINT,UINT);

#ವ್ಯಾಖ್ಯಾನಿಸು DC_ಸಕ್ರಿಯ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DC_SMALLCAP 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DC_ICON 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು DC_ಪಠ್ಯ 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು DC_INBUTTON 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು DC_GRADIENT 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು DC_BUTTONS 0x1000

  WINUSERAPI WINBOOL WINAPI DrawCaption(HWND hwnd,HDC hdc,CONST RECT *lprect,UINT flags);

#ವ್ಯಾಖ್ಯಾನಿಸು IDANI_OPEN 1
#ವ್ಯಾಖ್ಯಾನಿಸು IDANI_CAPTION 3

  WINUSERAPI WINBOOL WINAPI DrawAnimatedRects(HWND hwnd,ಪೂರ್ಣಾಂಕ idAni,CONST RECT *lprcFrom,CONST RECT *lprc_ಗಮ್ಯ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOCLIPBOARD

#ವ್ಯಾಖ್ಯಾನಿಸು CF_ಪಠ್ಯ 1
#ವ್ಯಾಖ್ಯಾನಿಸು CF_BITMAP 2
#ವ್ಯಾಖ್ಯಾನಿಸು CF_METAFILEPICT 3
#ವ್ಯಾಖ್ಯಾನಿಸು CF_SYLK 4
#ವ್ಯಾಖ್ಯಾನಿಸು CF_DIF 5
#ವ್ಯಾಖ್ಯಾನಿಸು CF_TIFF 6
#ವ್ಯಾಖ್ಯಾನಿಸು CF_OEMTEXT 7
#ವ್ಯಾಖ್ಯಾನಿಸು CF_DIB 8
#ವ್ಯಾಖ್ಯಾನಿಸು CF_PALETTE 9
#ವ್ಯಾಖ್ಯಾನಿಸು CF_PENDATA 10
#ವ್ಯಾಖ್ಯಾನಿಸು CF_RIFF 11
#ವ್ಯಾಖ್ಯಾನಿಸು CF_WAVE 12
#ವ್ಯಾಖ್ಯಾನಿಸು CF_UNICODETEXT 13
#ವ್ಯಾಖ್ಯಾನಿಸು CF_ENHMETAFILE 14
#ವ್ಯಾಖ್ಯಾನಿಸು CF_HDROP 15
#ವ್ಯಾಖ್ಯಾನಿಸು CF_LOCALE 16
#ವ್ಯಾಖ್ಯಾನಿಸು CF_DIBV5 17
#ವ್ಯಾಖ್ಯಾನಿಸು CF_MAX 18

#ವ್ಯಾಖ್ಯಾನಿಸು CF_OWNERDISPLAY 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು CF_DSPTEXT 0x0081
#ವ್ಯಾಖ್ಯಾನಿಸು CF_DSPBITMAP 0x0082
#ವ್ಯಾಖ್ಯಾನಿಸು CF_DSPMETAFILEPICT 0x0083
#ವ್ಯಾಖ್ಯಾನಿಸು CF_DSPENHMETAFILE 0x008E

#ವ್ಯಾಖ್ಯಾನಿಸು CF_PRIVATEFIRST 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು CF_PRIVATELAST 0x02FF

#ವ್ಯಾಖ್ಯಾನಿಸು CF_GDIOBJFIRST 0x0300
#ವ್ಯಾಖ್ಯಾನಿಸು CF_GDIOBJLAST 0x03FF
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು FVIRTKEY TRUE
#ವ್ಯಾಖ್ಯಾನಿಸು FNOINVERT 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು FSHIFT 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು FCONTROL 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು FALT 0x10

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ACCEL {
    BYTE fVirt;
    ಶಬ್ದ_3 ಕೀಲಿ;
    ಶಬ್ದ_3 cmd;
  } ACCEL,*LPACCEL;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_PAINTSTRUCT {
    HDC hdc;
    WINBOOL fErase;
    RECT rcPaint;
    WINBOOL fRestore;
    WINBOOL fIncUpdate;
    BYTE rgbReserved[32];
  } PAINTSTRUCT,*PPAINTSTRUCT,*NPPAINTSTRUCT,*LPPAINTSTRUCT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CREATESTRUCTA {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_ಪೋಷಕ_2;
    ಪೂರ್ಣಾಂಕ cy;
    ಪೂರ್ಣಾಂಕ cx;
    ಪೂರ್ಣಾಂಕ y;
    ಪೂರ್ಣಾಂಕ x;
    LONG style;
    LPCSTR lpszName;
    LPCSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTA,*LPCREATESTRUCTA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CREATESTRUCTW {
    LPVOID lpCreateParams;
    HINSTANCE hInstance;
    HMENU hMenu;
    HWND hwnd_ಪೋಷಕ_2;
    ಪೂರ್ಣಾಂಕ cy;
    ಪೂರ್ಣಾಂಕ cx;
    ಪೂರ್ಣಾಂಕ y;
    ಪೂರ್ಣಾಂಕ x;
    LONG style;
    LPCWSTR lpszName;
    LPCWSTR lpszClass;
    DWORD dwExStyle;
  } CREATESTRUCTW,*LPCREATESTRUCTW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CREATESTRUCTW CREATESTRUCT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCREATESTRUCTW LPCREATESTRUCT;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CREATESTRUCTA CREATESTRUCT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCREATESTRUCTA LPCREATESTRUCT;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_WINDOWPLACEMENT {
    UINT ಉದ್ದಳತೆ;
    UINT flags;
    UINT showCmd;
    ಬಿಂದು_3 ptMinPosition;
    ಬಿಂದು_3 ptMaxPosition;
    RECT rc_ಸಾಮಾನ್ಯ_Position;
  } WINDOWPLACEMENT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINDOWPLACEMENT *PWINDOWPLACEMENT,*LPWINDOWPLACEMENT;

#ವ್ಯಾಖ್ಯಾನಿಸು WPF_SETMINPOSITION 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು WPF_RESTORETOMAXIMIZED 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು WPF_ASYNCWINDOWPLACEMENT 0x0004

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_NMHDR {
    HWND hwndFrom;
    UINT_PTR idFrom;
    UINT ಸಂಕೇತ_2;
  } NMHDR;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NMHDR *LPNMHDR;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_STYLESTRUCT {
    DWORD styleOld;
    DWORD styleNew;
  } STYLESTRUCT,*LPSTYLESTRUCT;

#ವ್ಯಾಖ್ಯಾನಿಸು ODT_MENU 1
#ವ್ಯಾಖ್ಯಾನಿಸು ODT_LISTBOX 2
#ವ್ಯಾಖ್ಯಾನಿಸು ODT_COMBOBOX 3
#ವ್ಯಾಖ್ಯಾನಿಸು ODT_BUTTON 4
#ವ್ಯಾಖ್ಯಾನಿಸು ODT_STATIC 5

#ವ್ಯಾಖ್ಯಾನಿಸು ODA_DRAWENTIRE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು ODA_SELECT 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು ODA_FOCUS 0x0004

#ವ್ಯಾಖ್ಯಾನಿಸು ODS_SELECTED 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_GRAYED 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_DISABLED 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_CHECKED 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_FOCUS 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_DEFAULT 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_COMBOBOXEDIT 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_HOTLIGHT 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_INACTIVE 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_NOACCEL 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು ODS_NOFOCUSRECT 0x0200

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MEASUREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT ಅಂಶ_ID;
    UINT ಅಂಶ_ಅಗಲ;
    UINT ಅಂಶ_ಎತ್ತರ;
    ULONG_PTR ಅಂಶ_ದತ್ತಾಂಶ;
  } MEASUREITEMSTRUCT,*PMEASUREITEMSTRUCT,*LPMEASUREITEMSTRUCT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_DRAWITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT ಅಂಶ_ID;
    UINT ಅಂಶ_Action;
    UINT ಅಂಶ_State;
    HWND hwnd_ಅಂಶ;
    HDC hDC;
    RECT rc_ಅಂಶ;
    ULONG_PTR ಅಂಶ_ದತ್ತಾಂಶ;
  } DRAWITEMSTRUCT,*PDRAWITEMSTRUCT,*LPDRAWITEMSTRUCT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_DELETEITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    UINT ಅಂಶ_ID;
    HWND hwnd_ಅಂಶ;
    ULONG_PTR ಅಂಶ_ದತ್ತಾಂಶ;
  } DELETEITEMSTRUCT,*PDELETEITEMSTRUCT,*LPDELETEITEMSTRUCT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_COMPAREITEMSTRUCT {
    UINT CtlType;
    UINT CtlID;
    HWND hwnd_ಅಂಶ;
    UINT ಅಂಶ_ID1;
    ULONG_PTR ಅಂಶ_Data1;
    UINT ಅಂಶ_ID2;
    ULONG_PTR ಅಂಶ_Data2;
    DWORD dwLocaleId;
  } COMPAREITEMSTRUCT,*PCOMPAREITEMSTRUCT,*LPCOMPAREITEMSTRUCT;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMSG
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಸಂದೇಶ Get_ಸಂದೇಶ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Dispatch_ಸಂದೇಶ Dispatch_ಸಂದೇಶ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Peek_ಸಂದೇಶ Peek_ಸಂದೇಶ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಸಂದೇಶ Get_ಸಂದೇಶ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Dispatch_ಸಂದೇಶ Dispatch_ಸಂದೇಶ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Peek_ಸಂದೇಶ Peek_ಸಂದೇಶ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI Get_ಸಂದೇಶ_A(LPMSG lp_ಸಂದೇಶ_2,HWND hWnd,UINT w_ಸಂದೇಶ_Filter_Min,UINT w_ಸಂದೇಶ_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Get_ಸಂದೇಶ_W(LPMSG lp_ಸಂದೇಶ_2,HWND hWnd,UINT w_ಸಂದೇಶ_Filter_Min,UINT w_ಸಂದೇಶ_Filter_Max);
  WINUSERAPI WINBOOL WINAPI Translate_ಸಂದೇಶ(CONST ಸಂದೇಶ_3 *lp_ಸಂದೇಶ_2);
  WINUSERAPI LRESULT WINAPI Dispatch_ಸಂದೇಶ_A(CONST ಸಂದೇಶ_3 *lp_ಸಂದೇಶ_2);
  WINUSERAPI LRESULT WINAPI Dispatch_ಸಂದೇಶ_W(CONST ಸಂದೇಶ_3 *lp_ಸಂದೇಶ_2);
  WINUSERAPI WINBOOL WINAPI ಗಣ_ಸಂದೇಶ_ಸರತಿ(ಪೂರ್ಣಾಂಕ cMessagesMax);
  WINUSERAPI WINBOOL WINAPI Peek_ಸಂದೇಶ_A(LPMSG lp_ಸಂದೇಶ_2,HWND hWnd,UINT w_ಸಂದೇಶ_Filter_Min,UINT w_ಸಂದೇಶ_Filter_Max,UINT w_Remove_ಸಂದೇಶ);
  WINUSERAPI WINBOOL WINAPI Peek_ಸಂದೇಶ_W(LPMSG lp_ಸಂದೇಶ_2,HWND hWnd,UINT w_ಸಂದೇಶ_Filter_Min,UINT w_ಸಂದೇಶ_Filter_Max,UINT w_Remove_ಸಂದೇಶ);

#ವ್ಯಾಖ್ಯಾನಿಸು PM_NOREMOVE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು PM_REMOVE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು PM_NOYIELD 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು PM_QS_ಒಳಹರಿವು (QS_ಒಳಹರಿವು << 16)
#ವ್ಯಾಖ್ಯಾನಿಸು PM_QS_POSTMESSAGE ((QS_POSTMESSAGE | QS_HOTKEY | QS_TIMER) << 16)
#ವ್ಯಾಖ್ಯಾನಿಸು PM_QS_PAINT (QS_PAINT << 16)
#ವ್ಯಾಖ್ಯಾನಿಸು PM_QS_SENDMESSAGE (QS_SENDMESSAGE << 16)
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI ರಿಜಿಸ್ಟರ್_Hot_ಕೀಲಿ(HWND hWnd,ಪೂರ್ಣಾಂಕ id,UINT fsModifiers,UINT vk);
  WINUSERAPI WINBOOL WINAPI Unregister_Hot_ಕೀಲಿ(HWND hWnd,ಪೂರ್ಣಾಂಕ id);

#ವ್ಯಾಖ್ಯಾನಿಸು MOD_ALT 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು MOD_CONTROL 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು MOD_ಸರಿಸು 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು MOD_WIN 0x0008

#ವ್ಯಾಖ್ಯಾನಿಸು IDHOT_SNAPWINDOW (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು IDHOT_SNAPDESKTOP (-2)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ WIN_ಆಂತರಿಕ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ LSTRING
#ವ್ಯಾಖ್ಯಾನಿಸು NOLSTRING
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ LFILEIO
#ವ್ಯಾಖ್ಯಾನಿಸು NOLFILEIO
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ENDSESSION_LOGOFF 0x80000000

#ವ್ಯಾಖ್ಯಾನಿಸು EWX_LOGOFF 0
#ವ್ಯಾಖ್ಯಾನಿಸು EWX_SHUTDOWN 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು EWX_REBOOT 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು EWX_FORCE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು EWX_POWEROFF 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು EWX_FORCEIFHUNG 0x00000010

#ವ್ಯಾಖ್ಯಾನಿಸು ExitWindows(dwReserved,ಸಂಕೇತ_5) ExitWindowsEx(EWX_LOGOFF,0xFFFFFFFF)

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Send_ಸಂದೇಶ Send_ಸಂದೇಶ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Send_ಸಂದೇಶ_Timeout Send_ಸಂದೇಶ_Timeout_W
#ವ್ಯಾಖ್ಯಾನಿಸು Send_Notify_ಸಂದೇಶ Send_Notify_ಸಂದೇಶ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Send_ಸಂದೇಶ_Callback Send_ಸಂದೇಶ_Callback_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Send_ಸಂದೇಶ Send_ಸಂದೇಶ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Send_ಸಂದೇಶ_Timeout Send_ಸಂದೇಶ_Timeout_A
#ವ್ಯಾಖ್ಯಾನಿಸು Send_Notify_ಸಂದೇಶ Send_Notify_ಸಂದೇಶ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Send_ಸಂದೇಶ_Callback Send_ಸಂದೇಶ_Callback_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI ExitWindowsEx(UINT uFlags,DWORD dwReason);
  WINUSERAPI WINBOOL WINAPI ಅದಲುಬದಲು_Mouse_Button(WINBOOL f_ಅದಲುಬದಲು);
  WINUSERAPI DWORD WINAPI Get_ಸಂದೇಶ_Pos(VOID);
  WINUSERAPI LONG WINAPI Get_ಸಂದೇಶ_ಸಮಯ(VOID);
  WINUSERAPI LPARAM WINAPI Get_ಸಂದೇಶ_Extra_Info(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Wow64_ಸಂದೇಶ(VOID);
  WINUSERAPI LPARAM WINAPI ಗಣ_ಸಂದೇಶ_Extra_Info(LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_ಸಂದೇಶ_A(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_ಸಂದೇಶ_W(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_ಸಂದೇಶ_Timeout_A(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_ಫಲಿತಾಂಶ);
  WINUSERAPI LRESULT WINAPI Send_ಸಂದೇಶ_Timeout_W(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam,UINT fuFlags,UINT uTimeout,PDWORD_PTR lpdw_ಫಲಿತಾಂಶ);
  WINUSERAPI WINBOOL WINAPI Send_Notify_ಸಂದೇಶ_A(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_Notify_ಸಂದೇಶ_W(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Send_ಸಂದೇಶ_Callback_A(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_ಫಲಿತಾಂಶ_Call_ಹಿಂಭಾಗ,ULONG_PTR dw_ದತ್ತಾಂಶ);
  WINUSERAPI WINBOOL WINAPI Send_ಸಂದೇಶ_Callback_W(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam,SENDASYNCPROC lp_ಫಲಿತಾಂಶ_Call_ಹಿಂಭಾಗ,ULONG_PTR dw_ದತ್ತಾಂಶ);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    UINT cb_ಗಾತ್ರ;
    HDESK hdesk;
    HWND hwnd;
    LUID luid;
  } BSMINFO,*PBSMINFO;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರಸಾರ_System_ಸಂದೇಶ_Ex ಪ್ರಸಾರ_System_ಸಂದೇಶ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರಸಾರ_System_ಸಂದೇಶ ಪ್ರಸಾರ_System_ಸಂದೇಶ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರಸಾರ_System_ಸಂದೇಶ_Ex ಪ್ರಸಾರ_System_ಸಂದೇಶ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರಸಾರ_System_ಸಂದೇಶ ಪ್ರಸಾರ_System_ಸಂದೇಶ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ದೀರ್ಘ WINAPI ಪ್ರಸಾರ_System_ಸಂದೇಶ_Ex_A(DWORD flags,LPDWORD lpInfo,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI ದೀರ್ಘ WINAPI ಪ್ರಸಾರ_System_ಸಂದೇಶ_Ex_W(DWORD flags,LPDWORD lpInfo,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam,PBSMINFO pbsmInfo);
  WINUSERAPI ದೀರ್ಘ WINAPI ಪ್ರಸಾರ_System_ಸಂದೇಶ_A(DWORD flags,LPDWORD lpInfo,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI ದೀರ್ಘ WINAPI ಪ್ರಸಾರ_System_ಸಂದೇಶ_W(DWORD flags,LPDWORD lpInfo,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);

#ವ್ಯಾಖ್ಯಾನಿಸು BSM_ALLCOMPONENTS 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು BSM_VXDS 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು BSM_NETDRIVER 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು BSM_INSTALLABLEDRIVERS 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು BSM_APPLICATIONS 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು BSM_ALLDESKTOPS 0x00000010

#ವ್ಯಾಖ್ಯಾನಿಸು BSF_QUERY 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_IGNORECURRENTTASK 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_FLUSHDISK 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_NOHANG 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_POSTMESSAGE 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_FORCEIFHUNG 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_NOTIMEOUTIFNOTHUNG 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_ALLOWSFW 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_SENDNOTIFYMESSAGE 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_RETURNHDESK 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು BSF_LUID 0x00000400

#ವ್ಯಾಖ್ಯಾನಿಸು ಪ್ರಸಾರ_QUERY_DENY 0x424D5144

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PVOID HDEVNOTIFY;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HDEVNOTIFY *PHDEVNOTIFY;

#ವ್ಯಾಖ್ಯಾನಿಸು DEVICE_NOTIFY_ಕಿಟಕಿ_HANDLE 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು DEVICE_NOTIFY_SERVICE_HANDLE 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು DEVICE_NOTIFY_ALL_INTERFACE_CLASSES 0x00000004

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Device_Notification ರಿಜಿಸ್ಟರ್_Device_Notification_W
#ವ್ಯಾಖ್ಯಾನಿಸು Post_ಸಂದೇಶ Post_ಸಂದೇಶ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Post_Thread_ಸಂದೇಶ Post_Thread_ಸಂದೇಶ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Post_App_ಸಂದೇಶ Post_App_ಸಂದೇಶ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Def_ಕಿಟಕಿ_Proc Def_ಕಿಟಕಿ_Proc_W
#ವ್ಯಾಖ್ಯಾನಿಸು Call_ಕಿಟಕಿ_Proc Call_ಕಿಟಕಿ_Proc_W
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Class ರಿಜಿಸ್ಟರ್_Class_W
#ವ್ಯಾಖ್ಯಾನಿಸು UnregisterClass UnregisterClassW
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassInfo GetClassInfoW
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Class_Ex ರಿಜಿಸ್ಟರ್_Class_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassInfoEx GetClassInfoExW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Device_Notification ರಿಜಿಸ್ಟರ್_Device_Notification_A
#ವ್ಯಾಖ್ಯಾನಿಸು Post_ಸಂದೇಶ Post_ಸಂದೇಶ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Post_Thread_ಸಂದೇಶ Post_Thread_ಸಂದೇಶ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Post_App_ಸಂದೇಶ Post_App_ಸಂದೇಶ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Def_ಕಿಟಕಿ_Proc Def_ಕಿಟಕಿ_Proc_A
#ವ್ಯಾಖ್ಯಾನಿಸು Call_ಕಿಟಕಿ_Proc Call_ಕಿಟಕಿ_Proc_A
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Class ರಿಜಿಸ್ಟರ್_Class_A
#ವ್ಯಾಖ್ಯಾನಿಸು UnregisterClass UnregisterClassA
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassInfo GetClassInfoA
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Class_Ex ರಿಜಿಸ್ಟರ್_Class_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassInfoEx GetClassInfoExA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HDEVNOTIFY WINAPI ರಿಜಿಸ್ಟರ್_Device_Notification_A(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI HDEVNOTIFY WINAPI ರಿಜಿಸ್ಟರ್_Device_Notification_W(HANDLE hRecipient,LPVOID NotificationFilter,DWORD Flags);
  WINUSERAPI WINBOOL WINAPI UnregisterDeviceNotification(HDEVNOTIFY Handle);
  WINUSERAPI WINBOOL WINAPI Post_ಸಂದೇಶ_A(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_ಸಂದೇಶ_W(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_ಸಂದೇಶ_A(DWORD idThread,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI Post_Thread_ಸಂದೇಶ_W(DWORD idThread,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
#ವ್ಯಾಖ್ಯಾನಿಸು Post_App_ಸಂದೇಶ_A(idThread,w_ಸಂದೇಶ,wParam,lParam) Post_Thread_ಸಂದೇಶ_A((DWORD)idThread,w_ಸಂದೇಶ,wParam,lParam)
#ವ್ಯಾಖ್ಯಾನಿಸು Post_App_ಸಂದೇಶ_W(idThread,w_ಸಂದೇಶ,wParam,lParam) Post_Thread_ಸಂದೇಶ_W((DWORD)idThread,w_ಸಂದೇಶ,wParam,lParam)

#ವ್ಯಾಖ್ಯಾನಿಸು HWND_ಪ್ರಸಾರ ((HWND)0xffff)
#ವ್ಯಾಖ್ಯಾನಿಸು HWND_ಸಂದೇಶ ((HWND)-3)

  WINUSERAPI WINBOOL WINAPI Attach_Thread_ಒಳಹರಿವು(DWORD idAttach,DWORD id_Attach_ಗಮ್ಯ,WINBOOL fAttach);
  WINUSERAPI WINBOOL WINAPI ಉತ್ತರ_ಸಂದೇಶ(LRESULT l_ಫಲಿತಾಂಶ);
  WINUSERAPI WINBOOL WINAPI Wait_ಸಂದೇಶ(VOID);
  WINUSERAPI DWORD WINAPI Wait_For_ಒಳಹರಿವು_Idle(HANDLE hProcess,DWORD dwMilliseconds);
  WINUSERAPI LRESULT WINAPI Def_ಕಿಟಕಿ_Proc_A(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_ಕಿಟಕಿ_Proc_W(HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI VOID WINAPI Post_Quit_ಸಂದೇಶ(ಪೂರ್ಣಾಂಕ n_Exit_ಸಂಕೇತ);
  WINUSERAPI LRESULT WINAPI Call_ಕಿಟಕಿ_Proc_A(WNDPROC lpPrevWndFunc,HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Call_ಕಿಟಕಿ_Proc_W(WNDPROC lpPrevWndFunc,HWND hWnd,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI ಒಳ_Send_ಸಂದೇಶ(VOID);
  WINUSERAPI DWORD WINAPI ಒಳ_Send_ಸಂದೇಶ_Ex(LPVOID lpReserved);

#ವ್ಯಾಖ್ಯಾನಿಸು ISMEX_NOSEND 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು ISMEX_SEND 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು ISMEX_NOTIFY 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು ISMEX_CALLBACK 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು ISMEX_REPLIED 0x00000008

  WINUSERAPI UINT WINAPI Get_Double_Click_ಸಮಯ(VOID);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Double_Click_ಸಮಯ(UINT);
  WINUSERAPI ATOM WINAPI ರಿಜಿಸ್ಟರ್_Class_A(CONST WNDCLASSA *lpWndClass);
  WINUSERAPI ATOM WINAPI ರಿಜಿಸ್ಟರ್_Class_W(CONST WNDCLASSW *lpWndClass);
  WINUSERAPI WINBOOL WINAPI UnregisterClassA(LPCSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI UnregisterClassW(LPCWSTR lpClassName,HINSTANCE hInstance);
  WINUSERAPI WINBOOL WINAPI GetClassInfoA(HINSTANCE hInstance,LPCSTR lpClassName,LPWNDCLASSA lpWndClass);
  WINUSERAPI WINBOOL WINAPI GetClassInfoW(HINSTANCE hInstance,LPCWSTR lpClassName,LPWNDCLASSW lpWndClass);
  WINUSERAPI ATOM WINAPI ರಿಜಿಸ್ಟರ್_Class_Ex_A(CONST WNDCLASSEXA *);
  WINUSERAPI ATOM WINAPI ರಿಜಿಸ್ಟರ್_Class_Ex_W(CONST WNDCLASSEXW *);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExA(HINSTANCE hInstance,LPCSTR lpszClass,LPWNDCLASSEXA lpwcx);
  WINUSERAPI WINBOOL WINAPI GetClassInfoExW(HINSTANCE hInstance,LPCWSTR lpszClass,LPWNDCLASSEXW lpwcx);

#ವ್ಯಾಖ್ಯಾನಿಸು CW_USEDEFAULT ((ಪೂರ್ಣಾಂಕ)0x80000000)

#ವ್ಯಾಖ್ಯಾನಿಸು HWND_DESKTOP ((HWND)0)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ BOOLEAN (WINAPI *PREGISTERCLASSNAMEW)(LPCWSTR);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕಿಟಕಿ_Ex Create_ಕಿಟಕಿ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕಿಟಕಿ Create_ಕಿಟಕಿ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕಿಟಕಿ_Ex Create_ಕಿಟಕಿ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕಿಟಕಿ Create_ಕಿಟಕಿ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HWND WINAPI Create_ಕಿಟಕಿ_Ex_A(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lp_ಕಿಟಕಿ_Name,DWORD dwStyle,ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ,HWND h_Wnd_ಪೋಷಕ,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
  WINUSERAPI HWND WINAPI Create_ಕಿಟಕಿ_Ex_W(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lp_ಕಿಟಕಿ_Name,DWORD dwStyle,ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ,HWND h_Wnd_ಪೋಷಕ,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕಿಟಕಿ_A(lpClassName,lp_ಕಿಟಕಿ_Name,dwStyle,x,y,n_ಅಗಲ,n_ಎತ್ತರ,h_Wnd_ಪೋಷಕ,hMenu,hInstance,lpParam) Create_ಕಿಟಕಿ_Ex_A(0L,lpClassName,lp_ಕಿಟಕಿ_Name,dwStyle,x,y,n_ಅಗಲ,n_ಎತ್ತರ,h_Wnd_ಪೋಷಕ,hMenu,hInstance,lpParam)
#ವ್ಯಾಖ್ಯಾನಿಸು Create_ಕಿಟಕಿ_W(lpClassName,lp_ಕಿಟಕಿ_Name,dwStyle,x,y,n_ಅಗಲ,n_ಎತ್ತರ,h_Wnd_ಪೋಷಕ,hMenu,hInstance,lpParam) Create_ಕಿಟಕಿ_Ex_W(0L,lpClassName,lp_ಕಿಟಕಿ_Name,dwStyle,x,y,n_ಅಗಲ,n_ಎತ್ತರ,h_Wnd_ಪೋಷಕ,hMenu,hInstance,lpParam)
  WINUSERAPI WINBOOL WINAPI Is_ಕಿಟಕಿ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsMenu(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI Is_ಮಗು(HWND h_Wnd_ಪೋಷಕ,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Destroy_ಕಿಟಕಿ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Show_ಕಿಟಕಿ(HWND hWnd,ಪೂರ್ಣಾಂಕ nCmdShow);
  WINUSERAPI WINBOOL WINAPI Animate_ಕಿಟಕಿ(HWND hWnd,DWORD dw_ಸಮಯ,DWORD dwFlags);

#ಆದರೆ defined(_WINGDI_) && !defined(NOGDI)
  WINUSERAPI WINBOOL WINAPI Update_Layered_ಕಿಟಕಿ(HWND hWnd,HDC hdcDst,ಬಿಂದು_3 *pptDst,ಗಾತ್ರ_3 *psize,HDC hdcSrc,ಬಿಂದು_3 *pptSrc,COLORREF cr_ಕೀಲಿ,BLENDFUNCTION *pblend,DWORD dwFlags);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_UPDATELAYEREDWINDOWINFO {
    DWORD cb_ಗಾತ್ರ;
    HDC hdcDst;
    ಬಿಂದು_3 CONST *pptDst;
    ಗಾತ್ರ_3 CONST *psize;
    HDC hdcSrc;
    ಬಿಂದು_3 CONST *pptSrc;
    COLORREF cr_ಕೀಲಿ;
    BLENDFUNCTION CONST *pblend;
    DWORD dwFlags;
    RECT CONST *prcDirty;
  } UPDATELAYEREDWINDOWINFO,*PUPDATELAYEREDWINDOWINFO;

  WINUSERAPI WINBOOL WINAPI Update_Layered_ಕಿಟಕಿ_ಪರೋಕ್ಷ(HWND hWnd,UPDATELAYEREDWINDOWINFO CONST *pULWInfo);
  WINUSERAPI WINBOOL WINAPI Get_Layered_ಕಿಟಕಿ_ಗುಣಲಕ್ಷಣಗಳು(HWND hwnd,COLORREF *pcr_ಕೀಲಿ,BYTE *pbAlpha,DWORD *pdwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು PW_CLIENTONLY 0x00000001

  WINUSERAPI WINBOOL WINAPI Print_ಕಿಟಕಿ(HWND hwnd,HDC hdcBlt,UINT nFlags);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Layered_ಕಿಟಕಿ_ಗುಣಲಕ್ಷಣಗಳು(HWND hwnd,COLORREF cr_ಕೀಲಿ,BYTE bAlpha,DWORD dwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು LWA_COLORKEY 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು LWA_ALPHA 0x00000002

#ವ್ಯಾಖ್ಯಾನಿಸು ULW_COLORKEY 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು ULW_ALPHA 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು ULW_OPAQUE 0x00000004

#ವ್ಯಾಖ್ಯಾನಿಸು ULW_EX_NORESIZE 0x00000008

  WINUSERAPI WINBOOL WINAPI Show_ಕಿಟಕಿ_Async(HWND hWnd,ಪೂರ್ಣಾಂಕ nCmdShow);
  WINUSERAPI WINBOOL WINAPI Flash_ಕಿಟಕಿ(HWND hWnd,WINBOOL bInvert);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    UINT cb_ಗಾತ್ರ;
    HWND hwnd;
    DWORD dwFlags;
    UINT u_ಎಣಿಕೆ;
    DWORD dwTimeout;
  } FLASHWINFO,*PFLASHWINFO;

  WINUSERAPI WINBOOL WINAPI Flash_ಕಿಟಕಿ_Ex(PFLASHWINFO pfwi);

#ವ್ಯಾಖ್ಯಾನಿಸು FLASHW_STOP 0
#ವ್ಯಾಖ್ಯಾನಿಸು FLASHW_CAPTION 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು FLASHW_TRAY 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು FLASHW_ALL (FLASHW_CAPTION | FLASHW_TRAY)
#ವ್ಯಾಖ್ಯಾನಿಸು FLASHW_TIMER 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು FLASHW_TIMERNOFG 0x0000000C

  WINUSERAPI WINBOOL WINAPI ShowOwnedPopups(HWND hWnd,WINBOOL fShow);
  WINUSERAPI WINBOOL WINAPI OpenIcon(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Close_ಕಿಟಕಿ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Move_ಕಿಟಕಿ(HWND hWnd,ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ,WINBOOL bRepaint);
  WINUSERAPI WINBOOL WINAPI ಗಣ_ಕಿಟಕಿ_Pos(HWND hWnd,HWND h_Wnd_ಸೇರಿಸು_After,ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI Get_ಕಿಟಕಿ_Placement(HWND hWnd,WINDOWPLACEMENT *lpwndpl);
  WINUSERAPI WINBOOL WINAPI ಗಣ_ಕಿಟಕಿ_Placement(HWND hWnd,CONST WINDOWPLACEMENT *lpwndpl);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NODEFERWINDOWPOS
  WINUSERAPI HDWP WINAPI Begin_Defer_ಕಿಟಕಿ_Pos(ಪೂರ್ಣಾಂಕ n_ಅಂಕೆ_Windows);
  WINUSERAPI HDWP WINAPI Defer_ಕಿಟಕಿ_Pos(HDWP hWinPosInfo,HWND hWnd,HWND h_Wnd_ಸೇರಿಸು_After,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI ಕೊನೆ_Defer_ಕಿಟಕಿ_Pos(HDWP hWinPosInfo);
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI Is_ಕಿಟಕಿ_Visible(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsIconic(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI AnyPopup(VOID);
  WINUSERAPI WINBOOL WINAPI Bring_ಕಿಟಕಿ_ಗಮ್ಯ_ತುದಿ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI IsZoomed(HWND hWnd);

#ವ್ಯಾಖ್ಯಾನಿಸು SWP_NOSIZE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_NOMOVE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_NOZORDER 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_NOREDRAW 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_NOACTIVATE 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_FRAMECHANGED 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_SHOWWINDOW 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_HIDEWINDOW 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_NOCOPYBITS 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_NOOWNERZORDER 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_NOSENDCHANGING 0x0400

#ವ್ಯಾಖ್ಯಾನಿಸು SWP_DRAWFRAME SWP_FRAMECHANGED
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_NOREPOSITION SWP_NOOWNERZORDER
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_DEFERERASE 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು SWP_ASYNCWINDOWPOS 0x4000

#ವ್ಯಾಖ್ಯಾನಿಸು HWND_ತುದಿ ((HWND)0)
#ವ್ಯಾಖ್ಯಾನಿಸು HWND_BOTTOM ((HWND)1)
#ವ್ಯಾಖ್ಯಾನಿಸು HWND_TOPMOST ((HWND)-1)
#ವ್ಯಾಖ್ಯಾನಿಸು HWND_NOTOPMOST ((HWND)-2)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOCTLMGR

#ಅನ್ತರ್ಭಾವ <pshpack2.h>

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    DWORD style;
    DWORD dwExtendedStyle;
    ಶಬ್ದ_3 cdit;
    ಗಿಡ್ಡ x;
    ಗಿಡ್ಡ y;
    ಗಿಡ್ಡ cx;
    ಗಿಡ್ಡ cy;
  } DLGTEMPLATE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DLGTEMPLATE *LPDLGTEMPLATEA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DLGTEMPLATE *LPDLGTEMPLATEW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDLGTEMPLATEW LPDLGTEMPLATE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDLGTEMPLATEA LPDLGTEMPLATE;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCDLGTEMPLATEW LPCDLGTEMPLATE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCDLGTEMPLATEA LPCDLGTEMPLATE;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    DWORD style;
    DWORD dwExtendedStyle;
    ಗಿಡ್ಡ x;
    ಗಿಡ್ಡ y;
    ಗಿಡ್ಡ cx;
    ಗಿಡ್ಡ cy;
    ಶಬ್ದ_3 id;
  } DLGITEMTEMPLATE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DLGITEMTEMPLATE *PDLGITEMTEMPLATEA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DLGITEMTEMPLATE *PDLGITEMTEMPLATEW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PDLGITEMTEMPLATEW PDLGITEMTEMPLATE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PDLGITEMTEMPLATEA PDLGITEMTEMPLATE;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DLGITEMTEMPLATE *LPDLGITEMTEMPLATEA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DLGITEMTEMPLATE *LPDLGITEMTEMPLATEW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDLGITEMTEMPLATEW LPDLGITEMTEMPLATE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDLGITEMTEMPLATEA LPDLGITEMTEMPLATE;
#ಆದರೆ_ಅಂತ್ಯ

#ಅನ್ತರ್ಭಾವ <poppack.h>

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDialogParam CreateDialogParamW
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Dialog_ಪರೋಕ್ಷ_Param Create_Dialog_ಪರೋಕ್ಷ_Param_W
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDialog CreateDialogW
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Dialog_ಪರೋಕ್ಷ Create_Dialog_ಪರೋಕ್ಷ_W
#ವ್ಯಾಖ್ಯಾನಿಸು DialogBoxParam DialogBoxParamW
#ವ್ಯಾಖ್ಯಾನಿಸು Dialog_Box_ಪರೋಕ್ಷ_Param Dialog_Box_ಪರೋಕ್ಷ_Param_W
#ವ್ಯಾಖ್ಯಾನಿಸು DialogBox DialogBoxW
#ವ್ಯಾಖ್ಯಾನಿಸು Dialog_Box_ಪರೋಕ್ಷ Dialog_Box_ಪರೋಕ್ಷ_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Dlg_ಅಂಶ_ಪಠ್ಯ ಗಣ_Dlg_ಅಂಶ_ಪಠ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Dlg_ಅಂಶ_ಪಠ್ಯ Get_Dlg_ಅಂಶ_ಪಠ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Send_Dlg_ಅಂಶ_ಸಂದೇಶ Send_Dlg_ಅಂಶ_ಸಂದೇಶ_W
#ವ್ಯಾಖ್ಯಾನಿಸು DefDlgProc DefDlgProcW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDialogParam CreateDialogParamA
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Dialog_ಪರೋಕ್ಷ_Param Create_Dialog_ಪರೋಕ್ಷ_Param_A
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDialog CreateDialogA
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Dialog_ಪರೋಕ್ಷ Create_Dialog_ಪರೋಕ್ಷ_A
#ವ್ಯಾಖ್ಯಾನಿಸು DialogBoxParam DialogBoxParamA
#ವ್ಯಾಖ್ಯಾನಿಸು Dialog_Box_ಪರೋಕ್ಷ_Param Dialog_Box_ಪರೋಕ್ಷ_Param_A
#ವ್ಯಾಖ್ಯಾನಿಸು DialogBox DialogBoxA
#ವ್ಯಾಖ್ಯಾನಿಸು Dialog_Box_ಪರೋಕ್ಷ Dialog_Box_ಪರೋಕ್ಷ_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Dlg_ಅಂಶ_ಪಠ್ಯ ಗಣ_Dlg_ಅಂಶ_ಪಠ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Dlg_ಅಂಶ_ಪಠ್ಯ Get_Dlg_ಅಂಶ_ಪಠ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Send_Dlg_ಅಂಶ_ಸಂದೇಶ Send_Dlg_ಅಂಶ_ಸಂದೇಶ_A
#ವ್ಯಾಖ್ಯಾನಿಸು DefDlgProc DefDlgProcA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HWND WINAPI CreateDialogParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_ಪೋಷಕ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI CreateDialogParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_ಪೋಷಕ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_ಪರೋಕ್ಷ_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA lpTemplate,HWND h_Wnd_ಪೋಷಕ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI HWND WINAPI Create_Dialog_ಪರೋಕ್ಷ_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW lpTemplate,HWND h_Wnd_ಪೋಷಕ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDialogA(hInstance,lpName,h_Wnd_ಪೋಷಕ,lpDialogFunc) CreateDialogParamA(hInstance,lpName,h_Wnd_ಪೋಷಕ,lpDialogFunc,0L)
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDialogW(hInstance,lpName,h_Wnd_ಪೋಷಕ,lpDialogFunc) CreateDialogParamW(hInstance,lpName,h_Wnd_ಪೋಷಕ,lpDialogFunc,0L)
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Dialog_ಪರೋಕ್ಷ_A(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc) Create_Dialog_ಪರೋಕ್ಷ_Param_A(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc,0L)
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Dialog_ಪರೋಕ್ಷ_W(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc) Create_Dialog_ಪರೋಕ್ಷ_Param_W(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc,0L)
  WINUSERAPI INT_PTR WINAPI DialogBoxParamA(HINSTANCE hInstance,LPCSTR lpTemplateName,HWND h_Wnd_ಪೋಷಕ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI DialogBoxParamW(HINSTANCE hInstance,LPCWSTR lpTemplateName,HWND h_Wnd_ಪೋಷಕ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_ಪರೋಕ್ಷ_Param_A(HINSTANCE hInstance,LPCDLGTEMPLATEA hDialogTemplate,HWND h_Wnd_ಪೋಷಕ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
  WINUSERAPI INT_PTR WINAPI Dialog_Box_ಪರೋಕ್ಷ_Param_W(HINSTANCE hInstance,LPCDLGTEMPLATEW hDialogTemplate,HWND h_Wnd_ಪೋಷಕ,DLGPROC lpDialogFunc,LPARAM dwInitParam);
#ವ್ಯಾಖ್ಯಾನಿಸು DialogBoxA(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc) DialogBoxParamA(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc,0L)
#ವ್ಯಾಖ್ಯಾನಿಸು DialogBoxW(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc) DialogBoxParamW(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc,0L)
#ವ್ಯಾಖ್ಯಾನಿಸು Dialog_Box_ಪರೋಕ್ಷ_A(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc) Dialog_Box_ಪರೋಕ್ಷ_Param_A(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc,0L)
#ವ್ಯಾಖ್ಯಾನಿಸು Dialog_Box_ಪರೋಕ್ಷ_W(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc) Dialog_Box_ಪರೋಕ್ಷ_Param_W(hInstance,lpTemplate,h_Wnd_ಪೋಷಕ,lpDialogFunc,0L)
  WINUSERAPI WINBOOL WINAPI ಕೊನೆ_Dialog(HWND hDlg,INT_PTR n_ಫಲಿತಾಂಶ);
  WINUSERAPI HWND WINAPI Get_Dlg_ಅಂಶ(HWND hDlg,ಪೂರ್ಣಾಂಕ n_IDDlg_ಅಂಶ);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Dlg_ಅಂಶ_Int(HWND hDlg,ಪೂರ್ಣಾಂಕ n_IDDlg_ಅಂಶ,UINT u_ಮೌಲ್ಯ,WINBOOL bSigned);
  WINUSERAPI UINT WINAPI Get_Dlg_ಅಂಶ_Int(HWND hDlg,ಪೂರ್ಣಾಂಕ n_IDDlg_ಅಂಶ,WINBOOL *lpTranslated,WINBOOL bSigned);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Dlg_ಅಂಶ_ಪಠ್ಯ_A(HWND hDlg,ಪೂರ್ಣಾಂಕ n_IDDlg_ಅಂಶ,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Dlg_ಅಂಶ_ಪಠ್ಯ_W(HWND hDlg,ಪೂರ್ಣಾಂಕ n_IDDlg_ಅಂಶ,LPCWSTR lpString);
  WINUSERAPI UINT WINAPI Get_Dlg_ಅಂಶ_ಪಠ್ಯ_A(HWND hDlg,ಪೂರ್ಣಾಂಕ n_IDDlg_ಅಂಶ,LPSTR lpString,ಪೂರ್ಣಾಂಕ cchMax);
  WINUSERAPI UINT WINAPI Get_Dlg_ಅಂಶ_ಪಠ್ಯ_W(HWND hDlg,ಪೂರ್ಣಾಂಕ n_IDDlg_ಅಂಶ,LPWSTR lpString,ಪೂರ್ಣಾಂಕ cchMax);
  WINUSERAPI WINBOOL WINAPI CheckDlgButton(HWND hDlg,ಪೂರ್ಣಾಂಕ nIDButton,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI CheckRadioButton(HWND hDlg,ಪೂರ್ಣಾಂಕ nIDFirstButton,ಪೂರ್ಣಾಂಕ nIDLastButton,ಪೂರ್ಣಾಂಕ nIDCheckButton);
  WINUSERAPI UINT WINAPI IsDlgButtonChecked(HWND hDlg,ಪೂರ್ಣಾಂಕ nIDButton);
  WINUSERAPI LRESULT WINAPI Send_Dlg_ಅಂಶ_ಸಂದೇಶ_A(HWND hDlg,ಪೂರ್ಣಾಂಕ n_IDDlg_ಅಂಶ,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Send_Dlg_ಅಂಶ_ಸಂದೇಶ_W(HWND hDlg,ಪೂರ್ಣಾಂಕ n_IDDlg_ಅಂಶ,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI HWND WINAPI Get_ಮುಂದಿನ_Dlg_ಗುಂಪು_ಅಂಶ(HWND hDlg,HWND hCtl,WINBOOL b_ಹಿಂದಿನ);
  WINUSERAPI HWND WINAPI Get_ಮುಂದಿನ_Dlg_Tab_ಅಂಶ(HWND hDlg,HWND hCtl,WINBOOL b_ಹಿಂದಿನ);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetDlgCtrlID(HWND hWnd);
  WINUSERAPI ದೀರ್ಘ WINAPI Get_Dialog_ತಳ_Units(VOID);
  WINUSERAPI LRESULT WINAPI DefDlgProcA(HWND hDlg,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefDlgProcW(HWND hDlg,UINT ಸಂದೇಶ_5,WPARAM wParam,LPARAM lParam);

#ವ್ಯಾಖ್ಯಾನಿಸು DLGWINDOWEXTRA 30
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMSG

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Call_ಸಂದೇಶ_Filter Call_ಸಂದೇಶ_Filter_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Call_ಸಂದೇಶ_Filter Call_ಸಂದೇಶ_Filter_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI Call_ಸಂದೇಶ_Filter_A(LPMSG lp_ಸಂದೇಶ_2,ಪೂರ್ಣಾಂಕ n_ಸಂಕೇತ);
  WINUSERAPI WINBOOL WINAPI Call_ಸಂದೇಶ_Filter_W(LPMSG lp_ಸಂದೇಶ_2,ಪೂರ್ಣಾಂಕ n_ಸಂಕೇತ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOCLIPBOARD

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Clipboard_Format ರಿಜಿಸ್ಟರ್_Clipboard_Format_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetClipboardFormatName GetClipboardFormatNameW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ರಿಜಿಸ್ಟರ್_Clipboard_Format ರಿಜಿಸ್ಟರ್_Clipboard_Format_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetClipboardFormatName GetClipboardFormatNameA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI OpenClipboard(HWND hWndNewOwner);
  WINUSERAPI WINBOOL WINAPI CloseClipboard(VOID);
  WINUSERAPI DWORD WINAPI Get_Clipboard_Sequence_ಸಂಖ್ಯೆ(VOID);
  WINUSERAPI HWND WINAPI GetClipboardOwner(VOID);
  WINUSERAPI HWND WINAPI ಗಣ_Clipboard_Viewer(HWND hWndNewViewer);
  WINUSERAPI HWND WINAPI GetClipboardViewer(VOID);
  WINUSERAPI WINBOOL WINAPI ChangeClipboardChain(HWND hWndRemove,HWND h_Wnd_New_ಮುಂದಿನ);
  WINUSERAPI HANDLE WINAPI ಗಣ_Clipboard_ದತ್ತಾಂಶ(UINT uFormat,HANDLE hMem);
  WINUSERAPI HANDLE WINAPI Get_Clipboard_ದತ್ತಾಂಶ(UINT uFormat);
  WINUSERAPI UINT WINAPI ರಿಜಿಸ್ಟರ್_Clipboard_Format_A(LPCSTR lpszFormat);
  WINUSERAPI UINT WINAPI ರಿಜಿಸ್ಟರ್_Clipboard_Format_W(LPCWSTR lpszFormat);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಎಣಿಕೆ_Clipboard_Formats(VOID);
  WINUSERAPI UINT WINAPI EnumClipboardFormats(UINT format);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetClipboardFormatNameA(UINT format,LPSTR lpszFormatName,ಪೂರ್ಣಾಂಕ cch_Max_ಎಣಿಕೆ);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetClipboardFormatNameW(UINT format,LPWSTR lpszFormatName,ಪೂರ್ಣಾಂಕ cch_Max_ಎಣಿಕೆ);
  WINUSERAPI WINBOOL WINAPI ಖಾಲಿಗಳು_Clipboard(VOID);
  WINUSERAPI WINBOOL WINAPI Is_Clipboard_Format_ಲಭ್ಯ(UINT format);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಆದ್ಯತೆ_Clipboard_Format(UINT *pa_Format_ಆದ್ಯತೆ_List,ಪೂರ್ಣಾಂಕ cFormats);
  WINUSERAPI HWND WINAPI Get_Open_Clipboard_ಕಿಟಕಿ(VOID);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಗಮ್ಯ_Oem Char_ಗಮ್ಯ_Oem_W
#ವ್ಯಾಖ್ಯಾನಿಸು Oem_ಗಮ್ಯ_Char Oem_ಗಮ್ಯ_Char_W
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಗಮ್ಯ_Oem_Buff Char_ಗಮ್ಯ_Oem_Buff_W
#ವ್ಯಾಖ್ಯಾನಿಸು Oem_ಗಮ್ಯ_Char_Buff Oem_ಗಮ್ಯ_Char_Buff_W
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಊರ್ಧ್ವ Char_ಊರ್ಧ್ವ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಊರ್ಧ್ವ_Buff Char_ಊರ್ಧ್ವ_Buff_W
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಅಧೋ Char_ಅಧೋ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಅಧೋ_Buff Char_ಅಧೋ_Buff_W
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಮುಂದಿನ Char_ಮುಂದಿನ_W
#ವ್ಯಾಖ್ಯಾನಿಸು CharPrev CharPrevW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಗಮ್ಯ_Oem Char_ಗಮ್ಯ_Oem_A
#ವ್ಯಾಖ್ಯಾನಿಸು Oem_ಗಮ್ಯ_Char Oem_ಗಮ್ಯ_Char_A
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಗಮ್ಯ_Oem_Buff Char_ಗಮ್ಯ_Oem_Buff_A
#ವ್ಯಾಖ್ಯಾನಿಸು Oem_ಗಮ್ಯ_Char_Buff Oem_ಗಮ್ಯ_Char_Buff_A
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಊರ್ಧ್ವ Char_ಊರ್ಧ್ವ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಊರ್ಧ್ವ_Buff Char_ಊರ್ಧ್ವ_Buff_A
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಅಧೋ Char_ಅಧೋ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಅಧೋ_Buff Char_ಅಧೋ_Buff_A
#ವ್ಯಾಖ್ಯಾನಿಸು Char_ಮುಂದಿನ Char_ಮುಂದಿನ_A
#ವ್ಯಾಖ್ಯಾನಿಸು CharPrev CharPrevA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI Char_ಗಮ್ಯ_Oem_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_ಗಮ್ಯ_Oem_W(LPCWSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_ಗಮ್ಯ_Char_A(LPCSTR lpszSrc,LPSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Oem_ಗಮ್ಯ_Char_W(LPCSTR lpszSrc,LPWSTR lpszDst);
  WINUSERAPI WINBOOL WINAPI Char_ಗಮ್ಯ_Oem_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_ಉದ್ದಳತೆ);
  WINUSERAPI WINBOOL WINAPI Char_ಗಮ್ಯ_Oem_Buff_W(LPCWSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_ಉದ್ದಳತೆ);
  WINUSERAPI WINBOOL WINAPI Oem_ಗಮ್ಯ_Char_Buff_A(LPCSTR lpszSrc,LPSTR lpszDst,DWORD cch_Dst_ಉದ್ದಳತೆ);
  WINUSERAPI WINBOOL WINAPI Oem_ಗಮ್ಯ_Char_Buff_W(LPCSTR lpszSrc,LPWSTR lpszDst,DWORD cch_Dst_ಉದ್ದಳತೆ);
  WINUSERAPI LPSTR WINAPI Char_ಊರ್ಧ್ವ_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ಊರ್ಧ್ವ_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_ಊರ್ಧ್ವ_Buff_A(LPSTR lpsz,DWORD cch_ಉದ್ದಳತೆ);
  WINUSERAPI DWORD WINAPI Char_ಊರ್ಧ್ವ_Buff_W(LPWSTR lpsz,DWORD cch_ಉದ್ದಳತೆ);
  WINUSERAPI LPSTR WINAPI Char_ಅಧೋ_A(LPSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ಅಧೋ_W(LPWSTR lpsz);
  WINUSERAPI DWORD WINAPI Char_ಅಧೋ_Buff_A(LPSTR lpsz,DWORD cch_ಉದ್ದಳತೆ);
  WINUSERAPI DWORD WINAPI Char_ಅಧೋ_Buff_W(LPWSTR lpsz,DWORD cch_ಉದ್ದಳತೆ);
  WINUSERAPI LPSTR WINAPI Char_ಮುಂದಿನ_A(LPCSTR lpsz);
  WINUSERAPI LPWSTR WINAPI Char_ಮುಂದಿನ_W(LPCWSTR lpsz);
  WINUSERAPI LPSTR WINAPI CharPrevA(LPCSTR lpsz_ಆರಂಭ,LPCSTR lpszCurrent);
  WINUSERAPI LPWSTR WINAPI CharPrevW(LPCWSTR lpsz_ಆರಂಭ,LPCWSTR lpszCurrent);
  WINUSERAPI LPSTR WINAPI Char_ಮುಂದಿನ_Ex_A(ಶಬ್ದ_3 ಸಂಕೇತ_ಪುಟ,LPCSTR lpCurrentChar,DWORD dwFlags);
  WINUSERAPI LPSTR WINAPI CharPrevExA(ಶಬ್ದ_3 ಸಂಕೇತ_ಪುಟ,LPCSTR lp_ಆರಂಭ,LPCSTR lpCurrentChar,DWORD dwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು Ansi_ಗಮ್ಯ_Oem Char_ಗಮ್ಯ_Oem_A
#ವ್ಯಾಖ್ಯಾನಿಸು Oem_ಗಮ್ಯ_Ansi Oem_ಗಮ್ಯ_Char_A
#ವ್ಯಾಖ್ಯಾನಿಸು Ansi_ಗಮ್ಯ_Oem_Buff Char_ಗಮ್ಯ_Oem_Buff_A
#ವ್ಯಾಖ್ಯಾನಿಸು Oem_ಗಮ್ಯ_Ansi_Buff Oem_ಗಮ್ಯ_Char_Buff_A
#ವ್ಯಾಖ್ಯಾನಿಸು Ansi_ಊರ್ಧ್ವ Char_ಊರ್ಧ್ವ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Ansi_ಊರ್ಧ್ವ_Buff Char_ಊರ್ಧ್ವ_Buff_A
#ವ್ಯಾಖ್ಯಾನಿಸು Ansi_ಅಧೋ Char_ಅಧೋ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Ansi_ಅಧೋ_Buff Char_ಅಧೋ_Buff_A
#ವ್ಯಾಖ್ಯಾನಿಸು Ansi_ಮುಂದಿನ Char_ಮುಂದಿನ_A
#ವ್ಯಾಖ್ಯಾನಿಸು AnsiPrev CharPrevA

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOLANGUAGE

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು IsCharAlpha IsCharAlphaW
#ವ್ಯಾಖ್ಯಾನಿಸು IsCharAlphaNumeric IsCharAlphaNumericW
#ವ್ಯಾಖ್ಯಾನಿಸು Is_Char_ಊರ್ಧ್ವ Is_Char_ಊರ್ಧ್ವ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Is_Char_ಅಧೋ Is_Char_ಅಧೋ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು IsCharAlpha IsCharAlphaA
#ವ್ಯಾಖ್ಯಾನಿಸು IsCharAlphaNumeric IsCharAlphaNumericA
#ವ್ಯಾಖ್ಯಾನಿಸು Is_Char_ಊರ್ಧ್ವ Is_Char_ಊರ್ಧ್ವ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Is_Char_ಅಧೋ Is_Char_ಅಧೋ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI IsCharAlphaA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericA(CHAR ch);
  WINUSERAPI WINBOOL WINAPI IsCharAlphaNumericW(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ಊರ್ಧ್ವ_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ಊರ್ಧ್ವ_W(WCHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ಅಧೋ_A(CHAR ch);
  WINUSERAPI WINBOOL WINAPI Is_Char_ಅಧೋ_W(WCHAR ch);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕೀಲಿ_Name_ಪಠ್ಯ Get_ಕೀಲಿ_Name_ಪಠ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_Ex Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_Ex_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕೀಲಿ_Name_ಪಠ್ಯ Get_ಕೀಲಿ_Name_ಪಠ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_Ex Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_Ex_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HWND WINAPI ಗಣ_Focus(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_ಸಕ್ರಿಯ_ಕಿಟಕಿ(VOID);
  WINUSERAPI HWND WINAPI GetFocus(VOID);
  WINUSERAPI UINT WINAPI Get_KBCode_ಪುಟ(VOID);
  WINUSERAPI SHORT WINAPI Get_ಕೀಲಿ_State(ಪೂರ್ಣಾಂಕ n_Virt_ಕೀಲಿ);
  WINUSERAPI SHORT WINAPI Get_Async_ಕೀಲಿ_State(ಪೂರ್ಣಾಂಕ v_ಕೀಲಿ);
  WINUSERAPI WINBOOL WINAPI GetKeyboardState(PBYTE lp_ಕೀಲಿ_State);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Keyboard_State(LPBYTE lp_ಕೀಲಿ_State);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಕೀಲಿ_Name_ಪಠ್ಯ_A(LONG lParam,LPSTR lpString,ಪೂರ್ಣಾಂಕ cch_ಗಾತ್ರ);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಕೀಲಿ_Name_ಪಠ್ಯ_W(LONG lParam,LPWSTR lpString,ಪೂರ್ಣಾಂಕ cch_ಗಾತ್ರ);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetKeyboardType(ಪೂರ್ಣಾಂಕ nTypeFlag);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಮ್ಯ_Ascii(UINT u_Virt_ಕೀಲಿ,UINT u_ಪರಿಶೀಲನೆ_ಸಂಕೇತ,CONST BYTE *lp_ಕೀಲಿ_State,LPWORD lpChar,UINT uFlags);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಮ್ಯ_Ascii_Ex(UINT u_Virt_ಕೀಲಿ,UINT u_ಪರಿಶೀಲನೆ_ಸಂಕೇತ,CONST BYTE *lp_ಕೀಲಿ_State,LPWORD lpChar,UINT uFlags,HKL dwhkl);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಮ್ಯ_Unicode(UINT w_Virt_ಕೀಲಿ,UINT w_ಪರಿಶೀಲನೆ_ಸಂಕೇತ,CONST BYTE *lp_ಕೀಲಿ_State,LPWSTR pwszBuff,ಪೂರ್ಣಾಂಕ cchBuff,UINT wFlags);
  WINUSERAPI DWORD WINAPI Oem_ಕೀಲಿ_ಪರಿಶೀಲನೆ(ಶಬ್ದ_3 wOemChar);
  WINUSERAPI SHORT WINAPI Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_A(CHAR ch);
  WINUSERAPI SHORT WINAPI Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_W(WCHAR ch);
  WINUSERAPI SHORT WINAPI Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_Ex_A(CHAR ch,HKL dwhkl);
  WINUSERAPI SHORT WINAPI Vk_ಕೀಲಿ_ಪರಿಶೀಲನೆ_Ex_W(WCHAR ch,HKL dwhkl);

#ವ್ಯಾಖ್ಯಾನಿಸು KEYEVENTF_EXTENDEDKEY 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು KEYEVENTF_KEYUP 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು KEYEVENTF_UNICODE 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು KEYEVENTF_SCANCODE 0x0008

  WINUSERAPI VOID WINAPI keybd_event(BYTE bVk,BYTE b_ಪರಿಶೀಲನೆ,DWORD dwFlags,ULONG_PTR dwExtraInfo);

#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_MOVE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_LEFTDOWN 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_LEFTUP 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_RIGHTDOWN 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_RIGHTUP 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_MIDDLEDOWN 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_MIDDLEUP 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_XDOWN 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_XUP 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_WHEEL 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_VIRTUALDESK 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSEEVENTF_ABSOLUTE 0x8000

  WINUSERAPI VOID WINAPI mouse_event(DWORD dwFlags,DWORD dx,DWORD dy,DWORD dw_ದತ್ತಾಂಶ,ULONG_PTR dwExtraInfo);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MOUSEINPUT {
    LONG dx;
    LONG dy;
    DWORD mouse_ದತ್ತಾಂಶ;
    DWORD dwFlags;
    DWORD ಸಮಯ;
    ULONG_PTR dwExtraInfo;
  } MOUSEINPUT,*PMOUSEINPUT,*LPMOUSEINPUT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_KEYBDINPUT {
    ಶಬ್ದ_3 wVk;
    ಶಬ್ದ_3 w_ಪರಿಶೀಲನೆ;
    DWORD dwFlags;
    DWORD ಸಮಯ;
    ULONG_PTR dwExtraInfo;
  } KEYBDINPUT,*PKEYBDINPUT,*LPKEYBDINPUT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HARDWAREINPUT {
    DWORD u_ಸಂದೇಶ;
    ಶಬ್ದ_3 wParamL;
    ಶಬ್ದ_3 wParamH;
  } HARDWAREINPUT,*PHARDWAREINPUT,*LPHARDWAREINPUT;

#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳಹರಿವು_MOUSE 0
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳಹರಿವು_KEYBOARD 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಒಳಹರಿವು_HARDWARE 2

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ಒಳಹರಿವು {
    DWORD type;
    ಒಕ್ಕೂಟ {
      MOUSEINPUT mi;
      KEYBDINPUT ki;
      HARDWAREINPUT hi;
    };
  } ಒಳಹರಿವು_2,*PINPUT,*LPINPUT;

  WINUSERAPI UINT WINAPI Send_ಒಳಹರಿವು(UINT cInputs,LPINPUT pInputs,ಪೂರ್ಣಾಂಕ cb_ಗಾತ್ರ);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LASTINPUTINFO {
    UINT cb_ಗಾತ್ರ;
    DWORD dw_ಸಮಯ;
  } LASTINPUTINFO,*PLASTINPUTINFO;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Map_Virtual_ಕೀಲಿ Map_Virtual_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Map_Virtual_ಕೀಲಿ_Ex Map_Virtual_ಕೀಲಿ_Ex_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Map_Virtual_ಕೀಲಿ Map_Virtual_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Map_Virtual_ಕೀಲಿ_Ex Map_Virtual_ಕೀಲಿ_Ex_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI Get_ಕೊನೆಯ_ಒಳಹರಿವು_Info(PLASTINPUTINFO plii);
  WINUSERAPI UINT WINAPI Map_Virtual_ಕೀಲಿ_A(UINT u_ಸಂಕೇತ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_ಕೀಲಿ_W(UINT u_ಸಂಕೇತ,UINT uMapType);
  WINUSERAPI UINT WINAPI Map_Virtual_ಕೀಲಿ_Ex_A(UINT u_ಸಂಕೇತ,UINT uMapType,HKL dwhkl);
  WINUSERAPI UINT WINAPI Map_Virtual_ಕೀಲಿ_Ex_W(UINT u_ಸಂಕೇತ,UINT uMapType,HKL dwhkl);
  WINUSERAPI WINBOOL WINAPI Get_ಒಳಹರಿವು_State(VOID);
  WINUSERAPI DWORD WINAPI Get_ಸರತಿ_ಸ್ಥಿತಿ(UINT flags);
  WINUSERAPI HWND WINAPI GetCapture(VOID);
  WINUSERAPI HWND WINAPI ಗಣ_Capture(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ReleaseCapture(VOID);
  WINUSERAPI DWORD WINAPI ಸಂದೇಶ_Wait_For_ಅಪವರ್ತ್ಯ_Objects(DWORD n_ಎಣಿಕೆ,CONST HANDLE *pHandles,WINBOOL fWaitAll,DWORD dwMilliseconds,DWORD dw_Wake_ಮುಖವಾಡ);
  WINUSERAPI DWORD WINAPI ಸಂದೇಶ_Wait_For_ಅಪವರ್ತ್ಯ_Objects_Ex(DWORD n_ಎಣಿಕೆ,CONST HANDLE *pHandles,DWORD dwMilliseconds,DWORD dw_Wake_ಮುಖವಾಡ,DWORD dwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು MWMO_WAITALL 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು MWMO_ALERTABLE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು MWMO_INPUTAVAILABLE 0x0004

#ವ್ಯಾಖ್ಯಾನಿಸು QS_ಕೀಲಿ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು QS_MOUSEMOVE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು QS_MOUSEBUTTON 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು QS_POSTMESSAGE 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು QS_TIMER 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು QS_PAINT 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು QS_SENDMESSAGE 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು QS_HOTKEY 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು QS_ALLPOSTMESSAGE 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು QS_RAWINPUT 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು QS_MOUSE (QS_MOUSEMOVE | QS_MOUSEBUTTON)
#ವ್ಯಾಖ್ಯಾನಿಸು QS_ಒಳಹರಿವು (QS_MOUSE | QS_ಕೀಲಿ | QS_RAWINPUT)
#ವ್ಯಾಖ್ಯಾನಿಸು QS_ALLEVENTS (QS_ಒಳಹರಿವು | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY)
#ವ್ಯಾಖ್ಯಾನಿಸು QS_ALLINPUT (QS_ಒಳಹರಿವು | QS_POSTMESSAGE | QS_TIMER | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE)

#ವ್ಯಾಖ್ಯಾನಿಸು USER_TIMER_ಗರಿಷ್ಠ 0x7FFFFFFF
#ವ್ಯಾಖ್ಯಾನಿಸು USER_TIMER_MINIMUM 0x0000000A

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Accelerators ತುಂಬು_Accelerators_W
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Accelerator_ಕೋಷ್ಟಕ Create_Accelerator_ಕೋಷ್ಟಕ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Copy_Accelerator_ಕೋಷ್ಟಕ Copy_Accelerator_ಕೋಷ್ಟಕ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Accelerators ತುಂಬು_Accelerators_A
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Accelerator_ಕೋಷ್ಟಕ Create_Accelerator_ಕೋಷ್ಟಕ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Copy_Accelerator_ಕೋಷ್ಟಕ Copy_Accelerator_ಕೋಷ್ಟಕ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI UINT_PTR WINAPI ಗಣ_Timer(HWND hWnd,UINT_PTR nIDEvent,UINT uElapse,TIMERPROC lpTimerFunc);
  WINUSERAPI WINBOOL WINAPI KillTimer(HWND hWnd,UINT_PTR uIDEvent);
  WINUSERAPI WINBOOL WINAPI Is_ಕಿಟಕಿ_Unicode(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Enable_ಕಿಟಕಿ(HWND hWnd,WINBOOL bEnable);
  WINUSERAPI WINBOOL WINAPI Is_ಕಿಟಕಿ_Enabled(HWND hWnd);
  WINUSERAPI HACCEL WINAPI ತುಂಬು_Accelerators_A(HINSTANCE hInstance,LPCSTR lp_ಕೋಷ್ಟಕ_Name);
  WINUSERAPI HACCEL WINAPI ತುಂಬು_Accelerators_W(HINSTANCE hInstance,LPCWSTR lp_ಕೋಷ್ಟಕ_Name);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_ಕೋಷ್ಟಕ_A(LPACCEL paccel,ಪೂರ್ಣಾಂಕ cAccel);
  WINUSERAPI HACCEL WINAPI Create_Accelerator_ಕೋಷ್ಟಕ_W(LPACCEL paccel,ಪೂರ್ಣಾಂಕ cAccel);
  WINUSERAPI WINBOOL WINAPI Destroy_Accelerator_ಕೋಷ್ಟಕ(HACCEL hAccel);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Copy_Accelerator_ಕೋಷ್ಟಕ_A(HACCEL hAccelSrc,LPACCEL lpAccelDst,ಪೂರ್ಣಾಂಕ cAccelEntries);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Copy_Accelerator_ಕೋಷ್ಟಕ_W(HACCEL hAccelSrc,LPACCEL lpAccelDst,ಪೂರ್ಣಾಂಕ cAccelEntries);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMSG

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು TranslateAccelerator TranslateAcceleratorW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು TranslateAccelerator TranslateAcceleratorA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI TranslateAcceleratorA(HWND hWnd,HACCEL h_Acc_ಕೋಷ್ಟಕ,LPMSG lp_ಸಂದೇಶ_2);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI TranslateAcceleratorW(HWND hWnd,HACCEL h_Acc_ಕೋಷ್ಟಕ,LPMSG lp_ಸಂದೇಶ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOSYSMETRICS

#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXSCREEN 0
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYSCREEN 1
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXVSCROLL 2
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYHSCROLL 3
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYCAPTION 4
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXBORDER 5
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYBORDER 6
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXDLGFRAME 7
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYDLGFRAME 8
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYVTHUMB 9
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXHTHUMB 10
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXICON 11
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYICON 12
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXCURSOR 13
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYCURSOR 14
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYMENU 15
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXFULLSCREEN 16
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYFULLSCREEN 17
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYKANJIWINDOW 18
#ವ್ಯಾಖ್ಯಾನಿಸು SM_MOUSEPRESENT 19
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYVSCROLL 20
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXHSCROLL 21
#ವ್ಯಾಖ್ಯಾನಿಸು SM_DEBUG 22
#ವ್ಯಾಖ್ಯಾನಿಸು SM_SWAPBUTTON 23
#ವ್ಯಾಖ್ಯಾನಿಸು SM_RESERVED1 24
#ವ್ಯಾಖ್ಯಾನಿಸು SM_RESERVED2 25
#ವ್ಯಾಖ್ಯಾನಿಸು SM_RESERVED3 26
#ವ್ಯಾಖ್ಯಾನಿಸು SM_RESERVED4 27
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXMIN 28
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYMIN 29
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXSIZE 30
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYSIZE 31
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXFRAME 32
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYFRAME 33
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXMINTRACK 34
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYMINTRACK 35
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXDOUBLECLK 36
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYDOUBLECLK 37
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXICONSPACING 38
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYICONSPACING 39
#ವ್ಯಾಖ್ಯಾನಿಸು SM_MENUDROPALIGNMENT 40
#ವ್ಯಾಖ್ಯಾನಿಸು SM_PENWINDOWS 41
#ವ್ಯಾಖ್ಯಾನಿಸು SM_DBCSENABLED 42
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CMOUSEBUTTONS 43

#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXFIXEDFRAME SM_CXDLGFRAME
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYFIXEDFRAME SM_CYDLGFRAME
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXSIZEFRAME SM_CXFRAME
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYSIZEFRAME SM_CYFRAME

#ವ್ಯಾಖ್ಯಾನಿಸು SM_SECURE 44
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXEDGE 45
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYEDGE 46
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXMINSPACING 47
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYMINSPACING 48
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXSMICON 49
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYSMICON 50
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYSMCAPTION 51
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXSMSIZE 52
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYSMSIZE 53
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXMENUSIZE 54
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYMENUSIZE 55
#ವ್ಯಾಖ್ಯಾನಿಸು SM_ARRANGE 56
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXMINIMIZED 57
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYMINIMIZED 58
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXMAXTRACK 59
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYMAXTRACK 60
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXMAXIMIZED 61
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYMAXIMIZED 62
#ವ್ಯಾಖ್ಯಾನಿಸು SM_ಜಾಲ 63
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CLEANBOOT 67
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXDRAG 68
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYDRAG 69
#ವ್ಯಾಖ್ಯಾನಿಸು SM_SHOWSOUNDS 70
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXMENUCHECK 71
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYMENUCHECK 72
#ವ್ಯಾಖ್ಯಾನಿಸು SM_SLOWMACHINE 73
#ವ್ಯಾಖ್ಯಾನಿಸು SM_MIDEASTENABLED 74
#ವ್ಯಾಖ್ಯಾನಿಸು SM_MOUSEWHEELPRESENT 75
#ವ್ಯಾಖ್ಯಾನಿಸು SM_XVIRTUALSCREEN 76
#ವ್ಯಾಖ್ಯಾನಿಸು SM_YVIRTUALSCREEN 77
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXVIRTUALSCREEN 78
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYVIRTUALSCREEN 79
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CMONITORS 80
#ವ್ಯಾಖ್ಯಾನಿಸು SM_SAMEDISPLAYFORMAT 81
#ವ್ಯಾಖ್ಯಾನಿಸು SM_IMMENABLED 82
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CXFOCUSBORDER 83
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CYFOCUSBORDER 84
#ವ್ಯಾಖ್ಯಾನಿಸು SM_TABLETPC 86
#ವ್ಯಾಖ್ಯಾನಿಸು SM_MEDIACENTER 87
#ವ್ಯಾಖ್ಯಾನಿಸು SM_STARTER 88
#ವ್ಯಾಖ್ಯಾನಿಸು SM_SERVERR2 89
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CMETRICS 90
#ವ್ಯಾಖ್ಯಾನಿಸು SM_REMOTESESSION 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು SM_SHUTTINGDOWN 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು SM_REMOTECONTROL 0x2001
#ವ್ಯಾಖ್ಯಾನಿಸು SM_CARETBLINKINGENABLED 0x2002

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetSystemMetrics(ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMENUS

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Menu ತುಂಬು_Menu_W
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Menu_ಪರೋಕ್ಷ ತುಂಬು_Menu_ಪರೋಕ್ಷ_W
#ವ್ಯಾಖ್ಯಾನಿಸು ChangeMenu ChangeMenuW
#ವ್ಯಾಖ್ಯಾನಿಸು GetMenuString GetMenuStringW
#ವ್ಯಾಖ್ಯಾನಿಸು ಸೇರಿಸು_Menu ಸೇರಿಸು_Menu_W
#ವ್ಯಾಖ್ಯಾನಿಸು AppendMenu AppendMenuW
#ವ್ಯಾಖ್ಯಾನಿಸು ModifyMenu ModifyMenuW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Menu ತುಂಬು_Menu_A
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Menu_ಪರೋಕ್ಷ ತುಂಬು_Menu_ಪರೋಕ್ಷ_A
#ವ್ಯಾಖ್ಯಾನಿಸು ChangeMenu ChangeMenuA
#ವ್ಯಾಖ್ಯಾನಿಸು GetMenuString GetMenuStringA
#ವ್ಯಾಖ್ಯಾನಿಸು ಸೇರಿಸು_Menu ಸೇರಿಸು_Menu_A
#ವ್ಯಾಖ್ಯಾನಿಸು AppendMenu AppendMenuA
#ವ್ಯಾಖ್ಯಾನಿಸು ModifyMenu ModifyMenuA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HMENU WINAPI ತುಂಬು_Menu_A(HINSTANCE hInstance,LPCSTR lpMenuName);
  WINUSERAPI HMENU WINAPI ತುಂಬು_Menu_W(HINSTANCE hInstance,LPCWSTR lpMenuName);
  WINUSERAPI HMENU WINAPI ತುಂಬು_Menu_ಪರೋಕ್ಷ_A(CONST MENUTEMPLATEA *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI ತುಂಬು_Menu_ಪರೋಕ್ಷ_W(CONST MENUTEMPLATEW *lpMenuTemplate);
  WINUSERAPI HMENU WINAPI GetMenu(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Menu(HWND hWnd,HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ChangeMenuA(HMENU hMenu,UINT cmd,LPCSTR lpsz_New_ಅಂಶ,UINT cmd_ಸೇರಿಸು,UINT flags);
  WINUSERAPI WINBOOL WINAPI ChangeMenuW(HMENU hMenu,UINT cmd,LPCWSTR lpsz_New_ಅಂಶ,UINT cmd_ಸೇರಿಸು,UINT flags);
  WINUSERAPI WINBOOL WINAPI Hilite_Menu_ಅಂಶ(HWND hWnd,HMENU hMenu,UINT u_IDHilite_ಅಂಶ,UINT uHilite);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetMenuStringA(HMENU hMenu,UINT uIDItem,LPSTR lpString,ಪೂರ್ಣಾಂಕ cchMax,UINT flags);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetMenuStringW(HMENU hMenu,UINT uIDItem,LPWSTR lpString,ಪೂರ್ಣಾಂಕ cchMax,UINT flags);
  WINUSERAPI UINT WINAPI GetMenuState(HMENU hMenu,UINT uId,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawMenuBar(HWND hWnd);

#ವ್ಯಾಖ್ಯಾನಿಸು PMB_ಸಕ್ರಿಯ 0x00000001

  WINUSERAPI HMENU WINAPI GetSystemMenu(HWND hWnd,WINBOOL bRevert);
  WINUSERAPI HMENU WINAPI CreateMenu(VOID);
  WINUSERAPI HMENU WINAPI CreatePopupMenu(VOID);
  WINUSERAPI WINBOOL WINAPI DestroyMenu(HMENU hMenu);
  WINUSERAPI DWORD WINAPI Check_Menu_ಅಂಶ(HMENU hMenu,UINT u_IDCheck_ಅಂಶ,UINT uCheck);
  WINUSERAPI WINBOOL WINAPI Enable_Menu_ಅಂಶ(HMENU hMenu,UINT u_IDEnable_ಅಂಶ,UINT uEnable);
  WINUSERAPI HMENU WINAPI GetSubMenu(HMENU hMenu,ಪೂರ್ಣಾಂಕ nPos);
  WINUSERAPI UINT WINAPI Get_Menu_ಅಂಶ_ID(HMENU hMenu,ಪೂರ್ಣಾಂಕ nPos);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_Menu_ಅಂಶ_ಎಣಿಕೆ(HMENU hMenu);
  WINUSERAPI WINBOOL WINAPI ಸೇರಿಸು_Menu_A(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_ಅಂಶ,LPCSTR lp_New_ಅಂಶ);
  WINUSERAPI WINBOOL WINAPI ಸೇರಿಸು_Menu_W(HMENU hMenu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_ಅಂಶ,LPCWSTR lp_New_ಅಂಶ);
  WINUSERAPI WINBOOL WINAPI AppendMenuA(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_ಅಂಶ,LPCSTR lp_New_ಅಂಶ);
  WINUSERAPI WINBOOL WINAPI AppendMenuW(HMENU hMenu,UINT uFlags,UINT_PTR u_IDNew_ಅಂಶ,LPCWSTR lp_New_ಅಂಶ);
  WINUSERAPI WINBOOL WINAPI ModifyMenuA(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_ಅಂಶ,LPCSTR lp_New_ಅಂಶ);
  WINUSERAPI WINBOOL WINAPI ModifyMenuW(HMENU hMnu,UINT uPosition,UINT uFlags,UINT_PTR u_IDNew_ಅಂಶ,LPCWSTR lp_New_ಅಂಶ);
  WINUSERAPI WINBOOL WINAPI RemoveMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DeleteMenu(HMENU hMenu,UINT uPosition,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Menu_ಅಂಶ_Bitmaps(HMENU hMenu,UINT uPosition,UINT uFlags,HBITMAP hBitmapUnchecked,HBITMAP hBitmapChecked);
  WINUSERAPI LONG WINAPI GetMenuCheckMarkDimensions(VOID);
  WINUSERAPI WINBOOL WINAPI TrackPopupMenu(HMENU hMenu,UINT uFlags,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,ಪೂರ್ಣಾಂಕ nReserved,HWND hWnd,CONST RECT *prcRect);

#ವ್ಯಾಖ್ಯಾನಿಸು MNC_IGNORE 0
#ವ್ಯಾಖ್ಯಾನಿಸು MNC_CLOSE 1
#ವ್ಯಾಖ್ಯಾನಿಸು MNC_EXECUTE 2
#ವ್ಯಾಖ್ಯಾನಿಸು MNC_SELECT 3

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_TPMPARAMS {
    UINT cb_ಗಾತ್ರ;
    RECT rcExclude;
  } TPMPARAMS;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ TPMPARAMS *LPTPMPARAMS;

  WINUSERAPI WINBOOL WINAPI TrackPopupMenuEx(HMENU,UINT,ಪೂರ್ಣಾಂಕ,ಪೂರ್ಣಾಂಕ,HWND,LPTPMPARAMS);

#ವ್ಯಾಖ್ಯಾನಿಸು MNS_NOCHECK 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು MNS_MODELESS 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು MNS_DRAGDROP 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು MNS_AUTODISMISS 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು MNS_NOTIFYBYPOS 0x08000000
#ವ್ಯಾಖ್ಯಾನಿಸು MNS_CHECKORBMP 0x04000000

#ವ್ಯಾಖ್ಯಾನಿಸು MIM_MAXHEIGHT 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು MIM_BACKGROUND 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು MIM_HELPID 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು MIM_MENUDATA 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು MIM_STYLE 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು MIM_APPLYTOSUBMENUS 0x80000000

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MENUINFO {
    DWORD cb_ಗಾತ್ರ;
    DWORD f_ಮುಖವಾಡ;
    DWORD dwStyle;
    UINT cyMax;
    HBRUSH hbr_ಹಿಂಭಾಗ;
    DWORD dwContextHelpID;
    ULONG_PTR dw_Menu_ದತ್ತಾಂಶ;
  } MENUINFO,*LPMENUINFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MENUINFO CONST *LPCMENUINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuInfo(HMENU,LPMENUINFO);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Menu_Info(HMENU,LPCMENUINFO);
  WINUSERAPI WINBOOL WINAPI ಕೊನೆ_Menu(VOID);

#ವ್ಯಾಖ್ಯಾನಿಸು MND_CONTINUE 0
#ವ್ಯಾಖ್ಯಾನಿಸು MND_ENDMENU 1

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MENUGETOBJECTINFO {
    DWORD dwFlags;
    UINT uPos;
    HMENU hmenu;
    PVOID riid;
    PVOID pvObj;
  } MENUGETOBJECTINFO,*PMENUGETOBJECTINFO;

#ವ್ಯಾಖ್ಯಾನಿಸು MNGOF_TOPGAP 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು MNGOF_BOTTOMGAP 0x00000002

#ವ್ಯಾಖ್ಯಾನಿಸು MNGO_NOINTERFACE 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು MNGO_NOERROR 0x00000001

#ವ್ಯಾಖ್ಯಾನಿಸು MIIM_STATE 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು MIIM_ID 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು MIIM_SUBMENU 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು MIIM_CHECKMARKS 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು MIIM_TYPE 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು MIIM_ದತ್ತಾಂಶ 0x00000020

#ವ್ಯಾಖ್ಯಾನಿಸು MIIM_STRING 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು MIIM_BITMAP 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು MIIM_FTYPE 0x00000100

#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_CALLBACK ((HBITMAP) -1)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_SYSTEM ((HBITMAP) 1)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_MBAR_RESTORE ((HBITMAP) 2)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_MBAR_MINIMIZE ((HBITMAP) 3)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_MBAR_CLOSE ((HBITMAP) 5)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_MBAR_CLOSE_D ((HBITMAP) 6)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_MBAR_MINIMIZE_D ((HBITMAP) 7)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_POPUP_CLOSE ((HBITMAP) 8)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_POPUP_RESTORE ((HBITMAP) 9)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_POPUP_MAXIMIZE ((HBITMAP) 10)
#ವ್ಯಾಖ್ಯಾನಿಸು HBMMENU_POPUP_MINIMIZE ((HBITMAP) 11)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MENUITEMINFOA {
    UINT cb_ಗಾತ್ರ;
    UINT f_ಮುಖವಾಡ;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_ಅಂಶ_ದತ್ತಾಂಶ;
    LPSTR dw_Type_ದತ್ತಾಂಶ;
    UINT cch;
    HBITMAP hbmp_ಅಂಶ;
  } MENUITEMINFOA,*LPMENUITEMINFOA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MENUITEMINFOW {
    UINT cb_ಗಾತ್ರ;
    UINT f_ಮುಖವಾಡ;
    UINT fType;
    UINT fState;
    UINT wID;
    HMENU hSubMenu;
    HBITMAP hbmpChecked;
    HBITMAP hbmpUnchecked;
    ULONG_PTR dw_ಅಂಶ_ದತ್ತಾಂಶ;
    LPWSTR dw_Type_ದತ್ತಾಂಶ;
    UINT cch;
    HBITMAP hbmp_ಅಂಶ;
  } MENUITEMINFOW,*LPMENUITEMINFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MENUITEMINFOW MENUITEMINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMENUITEMINFOW LPMENUITEMINFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MENUITEMINFOA MENUITEMINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMENUITEMINFOA LPMENUITEMINFO;
#ಆದರೆ_ಅಂತ್ಯ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MENUITEMINFOA CONST *LPCMENUITEMINFOA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MENUITEMINFOW CONST *LPCMENUITEMINFOW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCMENUITEMINFOW LPCMENUITEMINFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPCMENUITEMINFOA LPCMENUITEMINFO;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಸೇರಿಸು_Menu_ಅಂಶ ಸೇರಿಸು_Menu_ಅಂಶ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Menu_ಅಂಶ_Info Get_Menu_ಅಂಶ_Info_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Menu_ಅಂಶ_Info ಗಣ_Menu_ಅಂಶ_Info_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಸೇರಿಸು_Menu_ಅಂಶ ಸೇರಿಸು_Menu_ಅಂಶ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Menu_ಅಂಶ_Info Get_Menu_ಅಂಶ_Info_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Menu_ಅಂಶ_Info ಗಣ_Menu_ಅಂಶ_Info_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI ಸೇರಿಸು_Menu_ಅಂಶ_A(HMENU hmenu,UINT ಅಂಶ,WINBOOL fByPosition,LPCMENUITEMINFOA lpmi);
  WINUSERAPI WINBOOL WINAPI ಸೇರಿಸು_Menu_ಅಂಶ_W(HMENU hmenu,UINT ಅಂಶ,WINBOOL fByPosition,LPCMENUITEMINFOW lpmi);
  WINUSERAPI WINBOOL WINAPI Get_Menu_ಅಂಶ_Info_A(HMENU hmenu,UINT ಅಂಶ,WINBOOL fByPosition,LPMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI Get_Menu_ಅಂಶ_Info_W(HMENU hmenu,UINT ಅಂಶ,WINBOOL fByPosition,LPMENUITEMINFOW lpmii);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Menu_ಅಂಶ_Info_A(HMENU hmenu,UINT ಅಂಶ,WINBOOL fByPositon,LPCMENUITEMINFOA lpmii);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Menu_ಅಂಶ_Info_W(HMENU hmenu,UINT ಅಂಶ,WINBOOL fByPositon,LPCMENUITEMINFOW lpmii);

#ವ್ಯಾಖ್ಯಾನಿಸು GMDI_USEDISABLED 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು GMDI_GOINTOPOPUPS 0x0002L

  WINUSERAPI UINT WINAPI Get_Menu_Default_ಅಂಶ(HMENU hMenu,UINT fByPos,UINT gmdiFlags);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Menu_Default_ಅಂಶ(HMENU hMenu,UINT u_ಅಂಶ,UINT fByPos);
  WINUSERAPI WINBOOL WINAPI Get_Menu_ಅಂಶ_Rect(HWND hWnd,HMENU hMenu,UINT u_ಅಂಶ,LPRECT lprc_ಅಂಶ);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Menu_ಅಂಶ_From_ಬಿಂದು(HWND hWnd,HMENU hMenu,ಬಿಂದು_3 ptScreen);

#ವ್ಯಾಖ್ಯಾನಿಸು TPM_LEFTBUTTON 0x0000L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_RIGHTBUTTON 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_LEFTALIGN 0x0000L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_CENTERALIGN 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_RIGHTALIGN 0x0008L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_TOPALIGN 0x0000L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_VCENTERALIGN 0x0010L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_BOTTOMALIGN 0x0020L

#ವ್ಯಾಖ್ಯಾನಿಸು TPM_HORIZONTAL 0x0000L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_VERTICAL 0x0040L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_NONOTIFY 0x0080L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_RETURNCMD 0x0100L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_RECURSE 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_HORPOSANIMATION 0x0400L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_HORNEGANIMATION 0x0800L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_VERPOSANIMATION 0x1000L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_VERNEGANIMATION 0x2000L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_NOANIMATION 0x4000L
#ವ್ಯಾಖ್ಯಾನಿಸು TPM_LAYOUTRTL 0x8000L
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_DROPSTRUCT {
    HWND hwnd_ಮೂಲ;
    HWND hwndSink;
    DWORD wFmt;
    ULONG_PTR dw_ದತ್ತಾಂಶ;
    ಬಿಂದು_3 ptDrop;
    DWORD dw_Control_ದತ್ತಾಂಶ;
  } DROPSTRUCT,*PDROPSTRUCT,*LPDROPSTRUCT;

#ವ್ಯಾಖ್ಯಾನಿಸು DOF_EXECUTABLE 0x8001
#ವ್ಯಾಖ್ಯಾನಿಸು DOF_DOCUMENT 0x8002
#ವ್ಯಾಖ್ಯಾನಿಸು DOF_DIRECTORY 0x8003
#ವ್ಯಾಖ್ಯಾನಿಸು DOF_ಅಪವರ್ತ್ಯ 0x8004
#ವ್ಯಾಖ್ಯಾನಿಸು DOF_PROGMAN 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DOF_SHELLDATA 0x0002

#ವ್ಯಾಖ್ಯಾನಿಸು DO_DROPFILE 0x454C4946L
#ವ್ಯಾಖ್ಯಾನಿಸು DO_PRINTFILE 0x544E5250L

  WINUSERAPI DWORD WINAPI DragObject(HWND hwnd_ಪೋಷಕ_2,HWND hwndFrom,UINT fmt,ULONG_PTR ದತ್ತಾಂಶ,HCURSOR hcur);
  WINUSERAPI WINBOOL WINAPI DragDetect(HWND hwnd,ಬಿಂದು_3 pt);
  WINUSERAPI WINBOOL WINAPI DrawIcon(HDC hDC,ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y,HICON hIcon);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NODRAWTEXT

#ವ್ಯಾಖ್ಯಾನಿಸು DT_ತುದಿ 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_ಎಡ 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_CENTER 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು DT_ಬಲ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು DT_VCENTER 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು DT_BOTTOM 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು DT_WORDBREAK 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು DT_SINGLELINE 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು DT_EXPANDTABS 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು DT_TABSTOP 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು DT_NOCLIP 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು DT_EXTERNALLEADING 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು DT_CALCRECT 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು DT_NOPREFIX 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು DT_ಆಂತರಿಕ 0x00001000

#ವ್ಯಾಖ್ಯಾನಿಸು DT_EDITCONTROL 0x00002000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_ಮಾರ್ಗ_ELLIPSIS 0x00004000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_ಕೊನೆ_ELLIPSIS 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_MODIFYSTRING 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_RTLREADING 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_ಶಬ್ದ_ELLIPSIS 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_NOFULLWIDTHCHARBREAK 0x00080000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_HIDEPREFIX 0x00100000
#ವ್ಯಾಖ್ಯಾನಿಸು DT_PREFIXONLY 0x00200000

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_DRAWTEXTPARAMS {
    UINT cb_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ i_Tab_ಉದ್ದಳತೆ;
    ಪೂರ್ಣಾಂಕ i_ಎಡ_Margin;
    ಪೂರ್ಣಾಂಕ i_ಬಲ_Margin;
    UINT ui_ಉದ್ದಳತೆ_Drawn;
  } DRAWTEXTPARAMS,*LPDRAWTEXTPARAMS;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Draw_ಪಠ್ಯ Draw_ಪಠ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Draw_ಪಠ್ಯ_Ex Draw_ಪಠ್ಯ_Ex_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Draw_ಪಠ್ಯ Draw_ಪಠ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Draw_ಪಠ್ಯ_Ex Draw_ಪಠ್ಯ_Ex_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Draw_ಪಠ್ಯ_A(HDC hdc,LPCSTR lpch_ಪಠ್ಯ,ಪೂರ್ಣಾಂಕ cch_ಪಠ್ಯ,LPRECT lprc,UINT format);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Draw_ಪಠ್ಯ_W(HDC hdc,LPCWSTR lpch_ಪಠ್ಯ,ಪೂರ್ಣಾಂಕ cch_ಪಠ್ಯ,LPRECT lprc,UINT format);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Draw_ಪಠ್ಯ_Ex_A(HDC hdc,LPSTR lpch_ಪಠ್ಯ,ಪೂರ್ಣಾಂಕ cch_ಪಠ್ಯ,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Draw_ಪಠ್ಯ_Ex_W(HDC hdc,LPWSTR lpch_ಪಠ್ಯ,ಪೂರ್ಣಾಂಕ cch_ಪಠ್ಯ,LPRECT lprc,UINT format,LPDRAWTEXTPARAMS lpdtp);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಬೂದು_String ಬೂದು_String_W
#ವ್ಯಾಖ್ಯಾನಿಸು DrawState DrawStateW
#ವ್ಯಾಖ್ಯಾನಿಸು Tabbed_ಪಠ್ಯ_ಹೊರಹೋಗು Tabbed_ಪಠ್ಯ_ಹೊರಹೋಗು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Tabbed_ಪಠ್ಯ_Extent Get_Tabbed_ಪಠ್ಯ_Extent_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಬೂದು_String ಬೂದು_String_A
#ವ್ಯಾಖ್ಯಾನಿಸು DrawState DrawStateA
#ವ್ಯಾಖ್ಯಾನಿಸು Tabbed_ಪಠ್ಯ_ಹೊರಹೋಗು Tabbed_ಪಠ್ಯ_ಹೊರಹೋಗು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Tabbed_ಪಠ್ಯ_Extent Get_Tabbed_ಪಠ್ಯ_Extent_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI ಬೂದು_String_A(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_ದತ್ತಾಂಶ,ಪೂರ್ಣಾಂಕ n_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ);
  WINUSERAPI WINBOOL WINAPI ಬೂದು_String_W(HDC hDC,HBRUSH hBrush,GRAYSTRINGPROC lpOutputFunc,LPARAM lp_ದತ್ತಾಂಶ,ಪೂರ್ಣಾಂಕ n_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ);

#ವ್ಯಾಖ್ಯಾನಿಸು DST_COMPLEX 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು DST_ಪಠ್ಯ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DST_PREFIXTEXT 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DST_ICON 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು DST_BITMAP 0x0004

#ವ್ಯಾಖ್ಯಾನಿಸು DSS_ಸಾಮಾನ್ಯ 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು DSS_UNION 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು DSS_DISABLED 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು DSS_MONO 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು DSS_HIDEPREFIX 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು DSS_PREFIXONLY 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು DSS_ಬಲ 0x8000

  WINUSERAPI WINBOOL WINAPI DrawStateA(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_ಹಿಂಭಾಗ,LPARAM l_ದತ್ತಾಂಶ,WPARAM w_ದತ್ತಾಂಶ,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy,UINT uFlags);
  WINUSERAPI WINBOOL WINAPI DrawStateW(HDC hdc,HBRUSH hbrFore,DRAWSTATEPROC qfn_Call_ಹಿಂಭಾಗ,LPARAM l_ದತ್ತಾಂಶ,WPARAM w_ದತ್ತಾಂಶ,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy,UINT uFlags);
  WINUSERAPI LONG WINAPI Tabbed_ಪಠ್ಯ_ಹೊರಹೋಗು_A(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPCSTR lpString,ಪೂರ್ಣಾಂಕ ch_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ nTabPositions,CONST INT *lpnTabStopPositions,ಪೂರ್ಣಾಂಕ nTabOrigin);
  WINUSERAPI LONG WINAPI Tabbed_ಪಠ್ಯ_ಹೊರಹೋಗು_W(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPCWSTR lpString,ಪೂರ್ಣಾಂಕ ch_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ nTabPositions,CONST INT *lpnTabStopPositions,ಪೂರ್ಣಾಂಕ nTabOrigin);
  WINUSERAPI DWORD WINAPI Get_Tabbed_ಪಠ್ಯ_Extent_A(HDC hdc,LPCSTR lpString,ಪೂರ್ಣಾಂಕ ch_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI DWORD WINAPI Get_Tabbed_ಪಠ್ಯ_Extent_W(HDC hdc,LPCWSTR lpString,ಪೂರ್ಣಾಂಕ ch_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ nTabPositions,CONST INT *lpnTabStopPositions);
  WINUSERAPI WINBOOL WINAPI Update_ಕಿಟಕಿ(HWND hWnd);
  WINUSERAPI HWND WINAPI ಗಣ_ಸಕ್ರಿಯ_ಕಿಟಕಿ(HWND hWnd);
  WINUSERAPI HWND WINAPI Get_Foreground_ಕಿಟಕಿ(VOID);
  WINUSERAPI WINBOOL WINAPI PaintDesktop(HDC hdc);
  WINUSERAPI VOID WINAPI Switch_ಗಮ್ಯ_This_ಕಿಟಕಿ(HWND hwnd,WINBOOL fUnknown);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Foreground_ಕಿಟಕಿ(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI Allow_ಗಣ_Foreground_ಕಿಟಕಿ(DWORD dwProcessId);

#ವ್ಯಾಖ್ಯಾನಿಸು ASFW_ANY ((DWORD)-1)

  WINUSERAPI WINBOOL WINAPI ಬೀಗ_ಗಣ_Foreground_ಕಿಟಕಿ(UINT u_ಬೀಗ_ಸಂಕೇತ);

#ವ್ಯಾಖ್ಯಾನಿಸು LSFW_ಬೀಗ 1
#ವ್ಯಾಖ್ಯಾನಿಸು LSFW_UNLOCK 2

  WINUSERAPI HWND WINAPI ಕಿಟಕಿ_From_DC(HDC hDC);
  WINUSERAPI HDC WINAPI GetDC(HWND hWnd);
  WINUSERAPI HDC WINAPI GetDCEx(HWND hWnd,HRGN hrgnClip,DWORD flags);

#ವ್ಯಾಖ್ಯಾನಿಸು DCX_ಕಿಟಕಿ 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_CACHE 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_NORESETATTRS 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_CLIPCHILDREN 0x00000008L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_CLIPSIBLINGS 0x00000010L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_PARENTCLIP 0x00000020L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_EXCLUDERGN 0x00000040L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_INTERSECTRGN 0x00000080L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_EXCLUDEUPDATE 0x00000100L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_INTERSECTUPDATE 0x00000200L
#ವ್ಯಾಖ್ಯಾನಿಸು DCX_LOCKWINDOWUPDATE 0x00000400L

#ವ್ಯಾಖ್ಯಾನಿಸು DCX_VALIDATE 0x00200000L

  WINUSERAPI HDC WINAPI Get_ಕಿಟಕಿ_DC(HWND hWnd);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ReleaseDC(HWND hWnd,HDC hDC);
  WINUSERAPI HDC WINAPI BeginPaint(HWND hWnd,LPPAINTSTRUCT lpPaint);
  WINUSERAPI WINBOOL WINAPI ಕೊನೆ_Paint(HWND hWnd,CONST PAINTSTRUCT *lpPaint);
  WINUSERAPI WINBOOL WINAPI GetUpdateRect(HWND hWnd,LPRECT lpRect,WINBOOL bErase);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetUpdateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_ಕಿಟಕಿ_Rgn(HWND hWnd,HRGN hRgn,WINBOOL bRedraw);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಕಿಟಕಿ_Rgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಕಿಟಕಿ_Rgn_Box(HWND hWnd,LPRECT lprc);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ExcludeUpdateRgn(HDC hDC,HWND hWnd);
  WINUSERAPI WINBOOL WINAPI InvalidateRect(HWND hWnd,CONST RECT *lpRect,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRect(HWND hWnd,CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI InvalidateRgn(HWND hWnd,HRGN hRgn,WINBOOL bErase);
  WINUSERAPI WINBOOL WINAPI ValidateRgn(HWND hWnd,HRGN hRgn);
  WINUSERAPI WINBOOL WINAPI Redraw_ಕಿಟಕಿ(HWND hWnd,CONST RECT *lprcUpdate,HRGN hrgnUpdate,UINT flags);

#ವ್ಯಾಖ್ಯಾನಿಸು RDW_INVALIDATE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು RDW_INTERNALPAINT 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು RDW_ERASE 0x0004

#ವ್ಯಾಖ್ಯಾನಿಸು RDW_VALIDATE 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು RDW_NOINTERNALPAINT 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು RDW_NOERASE 0x0020

#ವ್ಯಾಖ್ಯಾನಿಸು RDW_NOCHILDREN 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು RDW_ALLCHILDREN 0x0080

#ವ್ಯಾಖ್ಯಾನಿಸು RDW_UPDATENOW 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು RDW_ERASENOW 0x0200

#ವ್ಯಾಖ್ಯಾನಿಸು RDW_ಚೌಕಟ್ಟು 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು RDW_NOFRAME 0x0800

  WINUSERAPI WINBOOL WINAPI ಬೀಗ_ಕಿಟಕಿ_Update(HWND h_Wnd_ಬೀಗ);
  WINUSERAPI WINBOOL WINAPI Scroll_ಕಿಟಕಿ(HWND hWnd,ಪೂರ್ಣಾಂಕ XAmount,ಪೂರ್ಣಾಂಕ YAmount,CONST RECT *lpRect,CONST RECT *lpClipRect);
  WINUSERAPI WINBOOL WINAPI ScrollDC(HDC hDC,ಪೂರ್ಣಾಂಕ dx,ಪೂರ್ಣಾಂಕ dy,CONST RECT *lprcScroll,CONST RECT *lprcClip,HRGN hrgnUpdate,LPRECT lprcUpdate);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Scroll_ಕಿಟಕಿ_Ex(HWND hWnd,ಪೂರ್ಣಾಂಕ dx,ಪೂರ್ಣಾಂಕ dy,CONST RECT *prcScroll,CONST RECT *prcClip,HRGN hrgnUpdate,LPRECT prcUpdate,UINT flags);

#ವ್ಯಾಖ್ಯಾನಿಸು SW_SCROLLCHILDREN 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು SW_INVALIDATE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು SW_ERASE 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು SW_SMOOTHSCROLL 0x0010

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOSCROLL
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Scroll_Pos(HWND hWnd,ಪೂರ್ಣಾಂಕ nBar,ಪೂರ್ಣಾಂಕ nPos,WINBOOL bRedraw);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetScrollPos(HWND hWnd,ಪೂರ್ಣಾಂಕ nBar);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Scroll_Range(HWND hWnd,ಪೂರ್ಣಾಂಕ nBar,ಪೂರ್ಣಾಂಕ nMinPos,ಪೂರ್ಣಾಂಕ nMaxPos,WINBOOL bRedraw);
  WINUSERAPI WINBOOL WINAPI GetScrollRange(HWND hWnd,ಪೂರ್ಣಾಂಕ nBar,LPINT lpMinPos,LPINT lpMaxPos);
  WINUSERAPI WINBOOL WINAPI ShowScrollBar(HWND hWnd,ಪೂರ್ಣಾಂಕ wBar,WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI EnableScrollBar(HWND hWnd,UINT wSBflags,UINT wArrows);

#ವ್ಯಾಖ್ಯಾನಿಸು ESB_ENABLE_BOTH 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು ESB_DISABLE_BOTH 0x0003

#ವ್ಯಾಖ್ಯಾನಿಸು ESB_DISABLE_ಎಡ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು ESB_DISABLE_ಬಲ 0x0002

#ವ್ಯಾಖ್ಯಾನಿಸು ESB_DISABLE_ಮೇಲೆ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು ESB_DISABLE_ಕೆಳಕ್ಕೆ 0x0002

#ವ್ಯಾಖ್ಯಾನಿಸು ESB_DISABLE_LTUP ESB_DISABLE_ಎಡ
#ವ್ಯಾಖ್ಯಾನಿಸು ESB_DISABLE_RTDN ESB_DISABLE_ಬಲ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Prop ಗಣ_Prop_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetProp GetPropW
#ವ್ಯಾಖ್ಯಾನಿಸು RemoveProp RemovePropW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumPropsEx EnumPropsExW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumProps EnumPropsW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_ಪಠ್ಯ ಗಣ_ಕಿಟಕಿ_ಪಠ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_ಪಠ್ಯ Get_ಕಿಟಕಿ_ಪಠ್ಯ_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_ಪಠ್ಯ_ಉದ್ದಳತೆ Get_ಕಿಟಕಿ_ಪಠ್ಯ_ಉದ್ದಳತೆ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Prop ಗಣ_Prop_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetProp GetPropA
#ವ್ಯಾಖ್ಯಾನಿಸು RemoveProp RemovePropA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumPropsEx EnumPropsExA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumProps EnumPropsA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_ಪಠ್ಯ ಗಣ_ಕಿಟಕಿ_ಪಠ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_ಪಠ್ಯ Get_ಕಿಟಕಿ_ಪಠ್ಯ_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_ಪಠ್ಯ_ಉದ್ದಳತೆ Get_ಕಿಟಕಿ_ಪಠ್ಯ_ಉದ್ದಳತೆ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI ಗಣ_Prop_A(HWND hWnd,LPCSTR lpString,HANDLE h_ದತ್ತಾಂಶ);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Prop_W(HWND hWnd,LPCWSTR lpString,HANDLE h_ದತ್ತಾಂಶ);
  WINUSERAPI HANDLE WINAPI GetPropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI GetPropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropA(HWND hWnd,LPCSTR lpString);
  WINUSERAPI HANDLE WINAPI RemovePropW(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI EnumPropsExA(HWND hWnd,PROPENUMPROCEXA lpEnumFunc,LPARAM lParam);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI EnumPropsExW(HWND hWnd,PROPENUMPROCEXW lpEnumFunc,LPARAM lParam);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI EnumPropsA(HWND hWnd,PROPENUMPROCA lpEnumFunc);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI EnumPropsW(HWND hWnd,PROPENUMPROCW lpEnumFunc);
  WINUSERAPI WINBOOL WINAPI ಗಣ_ಕಿಟಕಿ_ಪಠ್ಯ_A(HWND hWnd,LPCSTR lpString);
  WINUSERAPI WINBOOL WINAPI ಗಣ_ಕಿಟಕಿ_ಪಠ್ಯ_W(HWND hWnd,LPCWSTR lpString);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಕಿಟಕಿ_ಪಠ್ಯ_A(HWND hWnd,LPSTR lpString,ಪೂರ್ಣಾಂಕ n_Max_ಎಣಿಕೆ);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಕಿಟಕಿ_ಪಠ್ಯ_W(HWND hWnd,LPWSTR lpString,ಪೂರ್ಣಾಂಕ n_Max_ಎಣಿಕೆ);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಕಿಟಕಿ_ಪಠ್ಯ_ಉದ್ದಳತೆ_A(HWND hWnd);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಕಿಟಕಿ_ಪಠ್ಯ_ಉದ್ದಳತೆ_W(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI GetClientRect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Get_ಕಿಟಕಿ_Rect(HWND hWnd,LPRECT lpRect);
  WINUSERAPI WINBOOL WINAPI Adjust_ಕಿಟಕಿ_Rect(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu);
  WINUSERAPI WINBOOL WINAPI Adjust_ಕಿಟಕಿ_Rect_Ex(LPRECT lpRect,DWORD dwStyle,WINBOOL bMenu,DWORD dwExStyle);

#ವ್ಯಾಖ್ಯಾನಿಸು HELPINFO_ಕಿಟಕಿ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು HELPINFO_MENUITEM 0x0002

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HELPINFO {
    UINT cb_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ iContextType;
    ಪೂರ್ಣಾಂಕ iCtrlId;
    HANDLE h_ಅಂಶ_Handle;
    DWORD_PTR dwContextId;
    ಬಿಂದು_3 MousePos;
  } HELPINFO,*LPHELPINFO;

  WINUSERAPI WINBOOL WINAPI ಗಣ_ಕಿಟಕಿ_Context_Help_Id(HWND,DWORD);
  WINUSERAPI DWORD WINAPI Get_ಕಿಟಕಿ_Context_Help_Id(HWND);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Menu_Context_Help_Id(HMENU,DWORD);
  WINUSERAPI DWORD WINAPI GetMenuContextHelpId(HMENU);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMB

#ವ್ಯಾಖ್ಯಾನಿಸು MB_OK 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_OKCANCEL 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ABORTRETRYIGNORE 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_YESNOCANCEL 0x00000003L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_YESNO 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_RETRYCANCEL 0x00000005L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_CANCELTRYCONTINUE 0x00000006L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ICONHAND 0x00000010L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ICONQUESTION 0x00000020L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ICONEXCLAMATION 0x00000030L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ICONASTERISK 0x00000040L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_USERICON 0x00000080L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ICONWARNING MB_ICONEXCLAMATION
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ICONERROR MB_ICONHAND
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ICONINFORMATION MB_ICONASTERISK
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ICONSTOP MB_ICONHAND
#ವ್ಯಾಖ್ಯಾನಿಸು MB_DEFBUTTON1 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_DEFBUTTON2 0x00000100L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_DEFBUTTON3 0x00000200L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_DEFBUTTON4 0x00000300L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_APPLMODAL 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_SYSTEMMODAL 0x00001000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_TASKMODAL 0x00002000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_HELP 0x00004000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_NOFOCUS 0x00008000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_SETFOREGROUND 0x00010000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_DEFAULT_DESKTOP_ONLY 0x00020000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_TOPMOST 0x00040000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ಬಲ 0x00080000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_RTLREADING 0x00100000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_SERVICE_NOTIFICATION 0x00200000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_SERVICE_NOTIFICATION_NT3X 0x00040000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_TYPEMASK 0x0000000FL
#ವ್ಯಾಖ್ಯಾನಿಸು MB_ICONMASK 0x000000F0L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_DEFMASK 0x00000F00L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_MODEMASK 0x00003000L
#ವ್ಯಾಖ್ಯಾನಿಸು MB_MISCMASK 0x0000C000L

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_Box ಸಂದೇಶ_Box_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_Box_Ex ಸಂದೇಶ_Box_Ex_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_Box ಸಂದೇಶ_Box_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_Box_Ex ಸಂದೇಶ_Box_Ex_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಸಂದೇಶ_Box_A(HWND hWnd,LPCSTR lp_ಪಠ್ಯ,LPCSTR lpCaption,UINT uType);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಸಂದೇಶ_Box_W(HWND hWnd,LPCWSTR lp_ಪಠ್ಯ,LPCWSTR lpCaption,UINT uType);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಸಂದೇಶ_Box_Ex_A(HWND hWnd,LPCSTR lp_ಪಠ್ಯ,LPCSTR lpCaption,UINT uType,ಶಬ್ದ_3 wLanguageId);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಸಂದೇಶ_Box_Ex_W(HWND hWnd,LPCWSTR lp_ಪಠ್ಯ,LPCWSTR lpCaption,UINT uType,ಶಬ್ದ_3 wLanguageId);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MSGBOXPARAMSA {
    UINT cb_ಗಾತ್ರ;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCSTR lpsz_ಪಠ್ಯ;
    LPCSTR lpszCaption;
    DWORD dwStyle;
    LPCSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_ಸಂದೇಶ_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSA,*PMSGBOXPARAMSA,*LPMSGBOXPARAMSA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MSGBOXPARAMSW {
    UINT cb_ಗಾತ್ರ;
    HWND hwndOwner;
    HINSTANCE hInstance;
    LPCWSTR lpsz_ಪಠ್ಯ;
    LPCWSTR lpszCaption;
    DWORD dwStyle;
    LPCWSTR lpszIcon;
    DWORD_PTR dwContextHelpId;
    MSGBOXCALLBACK lpfn_ಸಂದೇಶ_Box_Callback;
    DWORD dwLanguageId;
  } MSGBOXPARAMSW,*PMSGBOXPARAMSW,*LPMSGBOXPARAMSW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MSGBOXPARAMSW MSGBOXPARAMS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PMSGBOXPARAMSW PMSGBOXPARAMS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMSGBOXPARAMSW LPMSGBOXPARAMS;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MSGBOXPARAMSA MSGBOXPARAMS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PMSGBOXPARAMSA PMSGBOXPARAMS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMSGBOXPARAMSA LPMSGBOXPARAMS;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_Box_ಪರೋಕ್ಷ ಸಂದೇಶ_Box_ಪರೋಕ್ಷ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಸಂದೇಶ_Box_ಪರೋಕ್ಷ ಸಂದೇಶ_Box_ಪರೋಕ್ಷ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಸಂದೇಶ_Box_ಪರೋಕ್ಷ_A(CONST MSGBOXPARAMSA *lpmbp);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಸಂದೇಶ_Box_ಪರೋಕ್ಷ_W(CONST MSGBOXPARAMSW *lpmbp);
  WINUSERAPI WINBOOL WINAPI ಸಂದೇಶ_Beep(UINT uType);
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ShowCursor(WINBOOL bShow);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Cursor_Pos(ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y);
  WINUSERAPI HCURSOR WINAPI ಗಣ_Cursor(HCURSOR hCursor);
  WINUSERAPI WINBOOL WINAPI GetCursorPos(LPPOINT lp_ಬಿಂದು);
  WINUSERAPI WINBOOL WINAPI ClipCursor(CONST RECT *lpRect);
  WINUSERAPI WINBOOL WINAPI GetClipCursor(LPRECT lpRect);
  WINUSERAPI HCURSOR WINAPI GetCursor(VOID);
  WINUSERAPI WINBOOL WINAPI CreateCaret(HWND hWnd,HBITMAP hBitmap,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ);
  WINUSERAPI UINT WINAPI Get_Caret_Blink_ಸಮಯ(VOID);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Caret_Blink_ಸಮಯ(UINT uMSeconds);
  WINUSERAPI WINBOOL WINAPI DestroyCaret(VOID);
  WINUSERAPI WINBOOL WINAPI HideCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ShowCaret(HWND hWnd);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Caret_Pos(ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y);
  WINUSERAPI WINBOOL WINAPI GetCaretPos(LPPOINT lp_ಬಿಂದು);
  WINUSERAPI WINBOOL WINAPI Client_ಗಮ್ಯ_Screen(HWND hWnd,LPPOINT lp_ಬಿಂದು);
  WINUSERAPI WINBOOL WINAPI Screen_ಗಮ್ಯ_Client(HWND hWnd,LPPOINT lp_ಬಿಂದು);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI Map_ಕಿಟಕಿ_Points(HWND hWndFrom,HWND h_Wnd_ಗಮ್ಯ,LPPOINT lpPoints,UINT cPoints);
  WINUSERAPI HWND WINAPI ಕಿಟಕಿ_From_ಬಿಂದು(ಬಿಂದು_3 ಬಿಂದು_2);
  WINUSERAPI HWND WINAPI ಮಗು_ಕಿಟಕಿ_From_ಬಿಂದು(HWND h_Wnd_ಪೋಷಕ,ಬಿಂದು_3 ಬಿಂದು_2);

#ವ್ಯಾಖ್ಯಾನಿಸು CWP_ALL 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು CWP_SKIPINVISIBLE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು CWP_SKIPDISABLED 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು CWP_SKIPTRANSPARENT 0x0004

  WINUSERAPI HWND WINAPI ಮಗು_ಕಿಟಕಿ_From_ಬಿಂದು_Ex(HWND hwnd,ಬಿಂದು_3 pt,UINT flags);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOCOLOR

#ವ್ಯಾಖ್ಯಾನಿಸು CTLCOLOR_MSGBOX 0
#ವ್ಯಾಖ್ಯಾನಿಸು CTLCOLOR_EDIT 1
#ವ್ಯಾಖ್ಯಾನಿಸು CTLCOLOR_LISTBOX 2
#ವ್ಯಾಖ್ಯಾನಿಸು CTLCOLOR_BTN 3
#ವ್ಯಾಖ್ಯಾನಿಸು CTLCOLOR_DLG 4
#ವ್ಯಾಖ್ಯಾನಿಸು CTLCOLOR_SCROLLBAR 5
#ವ್ಯಾಖ್ಯಾನಿಸು CTLCOLOR_STATIC 6
#ವ್ಯಾಖ್ಯಾನಿಸು CTLCOLOR_MAX 7

#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_SCROLLBAR 0
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_BACKGROUND 1
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_ACTIVECAPTION 2
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_INACTIVECAPTION 3
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_MENU 4
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_ಕಿಟಕಿ 5
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_WINDOWFRAME 6
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_MENUTEXT 7
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_WINDOWTEXT 8
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_CAPTIONTEXT 9
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_ACTIVEBORDER 10
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_INACTIVEBORDER 11
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_APPWORKSPACE 12
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_HIGHLIGHT 13
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_HIGHLIGHTTEXT 14
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_BTNFACE 15
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_BTNSHADOW 16
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_GRAYTEXT 17
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_BTNTEXT 18
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_INACTIVECAPTIONTEXT 19
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_BTNHIGHLIGHT 20

#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_3DDKSHADOW 21
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_3DLIGHT 22
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_INFOTEXT 23
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_INFOBK 24

#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_HOTLIGHT 26
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_GRADIENTACTIVECAPTION 27
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_GRADIENTINACTIVECAPTION 28
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_MENUHILIGHT 29
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_MENUBAR 30

#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_DESKTOP COLOR_BACKGROUND
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_3DFACE COLOR_BTNFACE
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_3DSHADOW COLOR_BTNSHADOW
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_3DHIGHLIGHT COLOR_BTNHIGHLIGHT
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_3DHILIGHT COLOR_BTNHIGHLIGHT
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_BTNHILIGHT COLOR_BTNHIGHLIGHT

  WINUSERAPI DWORD WINAPI GetSysColor(ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI HBRUSH WINAPI GetSysColorBrush(ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Sys_Colors(ಪೂರ್ಣಾಂಕ cElements,CONST INT *lpaElements,CONST COLORREF *lpa_Rgb_ಮೌಲ್ಯಗಳು);
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI DrawFocusRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI FillRect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಚೌಕಟ್ಟು_Rect(HDC hDC,CONST RECT *lprc,HBRUSH hbr);
  WINUSERAPI WINBOOL WINAPI InvertRect(HDC hDC,CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Rect(LPRECT lprc,ಪೂರ್ಣಾಂಕ x_ಎಡ,ಪೂರ್ಣಾಂಕ y_ತುದಿ,ಪೂರ್ಣಾಂಕ x_ಬಲ,ಪೂರ್ಣಾಂಕ yBottom);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Rect_ಖಾಲಿಗಳು(LPRECT lprc);
  WINUSERAPI WINBOOL WINAPI CopyRect(LPRECT lprcDst,CONST RECT *lprcSrc);
  WINUSERAPI WINBOOL WINAPI InflateRect(LPRECT lprc,ಪೂರ್ಣಾಂಕ dx,ಪೂರ್ಣಾಂಕ dy);
  WINUSERAPI WINBOOL WINAPI IntersectRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI UnionRect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI ಕಳೆ_Rect(LPRECT lprcDst,CONST RECT *lprcSrc1,CONST RECT *lprcSrc2);
  WINUSERAPI WINBOOL WINAPI ಸ್ಥಾನಾಂತರ_Rect(LPRECT lprc,ಪೂರ್ಣಾಂಕ dx,ಪೂರ್ಣಾಂಕ dy);
  WINUSERAPI WINBOOL WINAPI Is_Rect_ಖಾಲಿಗಳು(CONST RECT *lprc);
  WINUSERAPI WINBOOL WINAPI EqualRect(CONST RECT *lprc1,CONST RECT *lprc2);
  WINUSERAPI WINBOOL WINAPI Pt_ಒಳ_Rect(CONST RECT *lprc,ಬಿಂದು_3 pt);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINOFFSETS

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Long Get_ಕಿಟಕಿ_Long_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_Long ಗಣ_ಕಿಟಕಿ_Long_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Long Get_ಕಿಟಕಿ_Long_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_Long ಗಣ_ಕಿಟಕಿ_Long_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ಶಬ್ದ_3 WINAPI Get_ಕಿಟಕಿ_ಶಬ್ದ(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI ಶಬ್ದ_3 WINAPI ಗಣ_ಕಿಟಕಿ_ಶಬ್ದ(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,ಶಬ್ದ_3 w_New_ಶಬ್ದ);
  WINUSERAPI LONG WINAPI Get_ಕಿಟಕಿ_Long_A(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI LONG WINAPI Get_ಕಿಟಕಿ_Long_W(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI LONG WINAPI ಗಣ_ಕಿಟಕಿ_Long_A(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,LONG dwNewLong);
  WINUSERAPI LONG WINAPI ಗಣ_ಕಿಟಕಿ_Long_W(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,LONG dwNewLong);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Long_Ptr Get_ಕಿಟಕಿ_Long_Ptr_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_Long_Ptr ಗಣ_ಕಿಟಕಿ_Long_Ptr_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Long_Ptr Get_ಕಿಟಕಿ_Long_Ptr_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_Long_Ptr ಗಣ_ಕಿಟಕಿ_Long_Ptr_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI LONG_PTR WINAPI Get_ಕಿಟಕಿ_Long_Ptr_A(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI LONG_PTR WINAPI Get_ಕಿಟಕಿ_Long_Ptr_W(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI LONG_PTR WINAPI ಗಣ_ಕಿಟಕಿ_Long_Ptr_A(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,LONG_PTR dwNewLong);
  WINUSERAPI LONG_PTR WINAPI ಗಣ_ಕಿಟಕಿ_Long_Ptr_W(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,LONG_PTR dwNewLong);
#ಇಲ್ಲದಿದ್ದರೆ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Long_Ptr Get_ಕಿಟಕಿ_Long_Ptr_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_Long_Ptr ಗಣ_ಕಿಟಕಿ_Long_Ptr_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Long_Ptr Get_ಕಿಟಕಿ_Long_Ptr_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_Long_Ptr ಗಣ_ಕಿಟಕಿ_Long_Ptr_A
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Long_Ptr_A Get_ಕಿಟಕಿ_Long_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Long_Ptr_W Get_ಕಿಟಕಿ_Long_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_Long_Ptr_A ಗಣ_ಕಿಟಕಿ_Long_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಕಿಟಕಿ_Long_Ptr_W ಗಣ_ಕಿಟಕಿ_Long_W
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassLong GetClassLongW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Class_Long ಗಣ_Class_Long_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassLong GetClassLongA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Class_Long ಗಣ_Class_Long_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ಶಬ್ದ_3 WINAPI Get_Class_ಶಬ್ದ(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI ಶಬ್ದ_3 WINAPI ಗಣ_Class_ಶಬ್ದ(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,ಶಬ್ದ_3 w_New_ಶಬ್ದ);
  WINUSERAPI DWORD WINAPI GetClassLongA(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI DWORD WINAPI GetClassLongW(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI DWORD WINAPI ಗಣ_Class_Long_A(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,LONG dwNewLong);
  WINUSERAPI DWORD WINAPI ಗಣ_Class_Long_W(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,LONG dwNewLong);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassLongPtr GetClassLongPtrW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Class_Long_Ptr ಗಣ_Class_Long_Ptr_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassLongPtr GetClassLongPtrA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Class_Long_Ptr ಗಣ_Class_Long_Ptr_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrA(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI ULONG_PTR WINAPI GetClassLongPtrW(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ);
  WINUSERAPI ULONG_PTR WINAPI ಗಣ_Class_Long_Ptr_A(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,LONG_PTR dwNewLong);
  WINUSERAPI ULONG_PTR WINAPI ಗಣ_Class_Long_Ptr_W(HWND hWnd,ಪೂರ್ಣಾಂಕ n_ಸೂಚ್ಯಂಕ,LONG_PTR dwNewLong);
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassLongPtr GetClassLongPtrW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Class_Long_Ptr ಗಣ_Class_Long_Ptr_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassLongPtr GetClassLongPtrA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Class_Long_Ptr ಗಣ_Class_Long_Ptr_A
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು GetClassLongPtrA GetClassLongA
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassLongPtrW GetClassLongW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Class_Long_Ptr_A ಗಣ_Class_Long_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Class_Long_Ptr_W ಗಣ_Class_Long_W
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_Ex ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassName GetClassNameW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_Ex ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetClassName GetClassNameA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI GetProcessDefaultLayout(DWORD *pdwDefaultLayout);
  WINUSERAPI WINBOOL WINAPI ಗಣ_Process_Default_Layout(DWORD dwDefaultLayout);
  WINUSERAPI HWND WINAPI Get_Desktop_ಕಿಟಕಿ(VOID);
  WINUSERAPI HWND WINAPI Get_ಪೋಷಕ(HWND hWnd);
  WINUSERAPI HWND WINAPI ಗಣ_ಪೋಷಕ(HWND h_Wnd_ಮಗು,HWND h_Wnd_New_ಪೋಷಕ);
  WINUSERAPI WINBOOL WINAPI Enum_ಮಗು_Windows(HWND h_Wnd_ಪೋಷಕ,WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI HWND WINAPI ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_A(LPCSTR lpClassName,LPCSTR lp_ಕಿಟಕಿ_Name);
  WINUSERAPI HWND WINAPI ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_W(LPCWSTR lpClassName,LPCWSTR lp_ಕಿಟಕಿ_Name);
  WINUSERAPI HWND WINAPI ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_Ex_A(HWND h_Wnd_ಪೋಷಕ,HWND h_Wnd_ಮಗು_After,LPCSTR lpszClass,LPCSTR lpsz_ಕಿಟಕಿ);
  WINUSERAPI HWND WINAPI ಕಂಡುಹಿಡಿ_ಕಿಟಕಿ_Ex_W(HWND h_Wnd_ಪೋಷಕ,HWND h_Wnd_ಮಗು_After,LPCWSTR lpszClass,LPCWSTR lpsz_ಕಿಟಕಿ);
  WINUSERAPI HWND WINAPI Get_Shell_ಕಿಟಕಿ(VOID);
  WINUSERAPI WINBOOL WINAPI ರಿಜಿಸ್ಟರ್_Shell_Hook_ಕಿಟಕಿ(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI Deregister_Shell_Hook_ಕಿಟಕಿ(HWND hwnd);
  WINUSERAPI WINBOOL WINAPI EnumWindows(WNDENUMPROC lpEnumFunc,LPARAM lParam);
  WINUSERAPI WINBOOL WINAPI EnumThreadWindows(DWORD dwThreadId,WNDENUMPROC lpfn,LPARAM lParam);

#ವ್ಯಾಖ್ಯಾನಿಸು EnumTaskWindows(hTask,lpfn,lParam) EnumThreadWindows(Handle_ಗಮ್ಯ_Ulong(hTask),lpfn,lParam)

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetClassNameA(HWND hWnd,LPSTR lpClassName,ಪೂರ್ಣಾಂಕ n_Max_ಎಣಿಕೆ);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI GetClassNameW(HWND hWnd,LPWSTR lpClassName,ಪೂರ್ಣಾಂಕ n_Max_ಎಣಿಕೆ);
  WINUSERAPI HWND WINAPI Get_ತುದಿ_ಕಿಟಕಿ(HWND hWnd);

#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಮುಂದಿನ_ಕಿಟಕಿ(hWnd,wCmd) Get_ಕಿಟಕಿ(hWnd,wCmd)
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Sys_Modal_ಕಿಟಕಿ() (ಖಾಲಿ)
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Sys_Modal_ಕಿಟಕಿ(hWnd) (ಖಾಲಿ)

  WINUSERAPI DWORD WINAPI Get_ಕಿಟಕಿ_Thread_Process_Id(HWND hWnd,LPDWORD lpdwProcessId);
  WINUSERAPI WINBOOL WINAPI IsGUIThread(WINBOOL bConvert);

#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Task(hWnd) ((HANDLE)(DWORD_PTR)Get_ಕಿಟಕಿ_Thread_Process_Id(hWnd,ಖಾಲಿ))

  WINUSERAPI HWND WINAPI Get_ಕೊನೆಯ_ಸಕ್ರಿಯ_Popup(HWND hWnd);

#ವ್ಯಾಖ್ಯಾನಿಸು GW_HWNDFIRST 0
#ವ್ಯಾಖ್ಯಾನಿಸು GW_HWNDLAST 1
#ವ್ಯಾಖ್ಯಾನಿಸು GW_HWNDNEXT 2
#ವ್ಯಾಖ್ಯಾನಿಸು GW_HWNDPREV 3
#ವ್ಯಾಖ್ಯಾನಿಸು GW_OWNER 4
#ವ್ಯಾಖ್ಯಾನಿಸು GW_ಮಗು 5
#ವ್ಯಾಖ್ಯಾನಿಸು GW_ENABLEDPOPUP 6
#ವ್ಯಾಖ್ಯಾನಿಸು GW_MAX 6

  WINUSERAPI HWND WINAPI Get_ಕಿಟಕಿ(HWND hWnd,UINT uCmd);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWH

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Windows_Hook ಗಣ_Windows_Hook_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Windows_Hook_Ex ಗಣ_Windows_Hook_Ex_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Windows_Hook ಗಣ_Windows_Hook_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_Windows_Hook_Ex ಗಣ_Windows_Hook_Ex_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HHOOK WINAPI ಗಣ_Windows_Hook_A(ಪೂರ್ಣಾಂಕ nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI ಗಣ_Windows_Hook_W(ಪೂರ್ಣಾಂಕ nFilterType,HOOKPROC pfnFilterProc);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHook(ಪೂರ್ಣಾಂಕ n_ಸಂಕೇತ,HOOKPROC pfnFilterProc);
  WINUSERAPI HHOOK WINAPI ಗಣ_Windows_Hook_Ex_A(ಪೂರ್ಣಾಂಕ idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI HHOOK WINAPI ಗಣ_Windows_Hook_Ex_W(ಪೂರ್ಣಾಂಕ idHook,HOOKPROC lpfn,HINSTANCE hmod,DWORD dwThreadId);
  WINUSERAPI WINBOOL WINAPI UnhookWindowsHookEx(HHOOK hhk);
  WINUSERAPI LRESULT WINAPI Call_ಮುಂದಿನ_Hook_Ex(HHOOK hhk,ಪೂರ್ಣಾಂಕ n_ಸಂಕೇತ,WPARAM wParam,LPARAM lParam);
#ವ್ಯಾಖ್ಯಾನಿಸು DefHookProc(n_ಸಂಕೇತ,wParam,lParam,phhk) Call_ಮುಂದಿನ_Hook_Ex(*phhk,n_ಸಂಕೇತ,wParam,lParam)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMENUS

#ವ್ಯಾಖ್ಯಾನಿಸು MF_ಸೇರಿಸು 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_CHANGE 0x00000080L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_APPEND 0x00000100L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_DELETE 0x00000200L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_REMOVE 0x00001000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_BYCOMMAND 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_BYPOSITION 0x00000400L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_SEPARATOR 0x00000800L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_ENABLED 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_GRAYED 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_DISABLED 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_UNCHECKED 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_CHECKED 0x00000008L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_USECHECKBITMAPS 0x00000200L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_STRING 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_BITMAP 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_OWNERDRAW 0x00000100L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_POPUP 0x00000010L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_MENUBARBREAK 0x00000020L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_MENUBREAK 0x00000040L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_UNHILITE 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_HILITE 0x00000080L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_DEFAULT 0x00001000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_SYSMENU 0x00002000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_HELP 0x00004000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_RIGHTJUSTIFY 0x00004000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_MOUSESELECT 0x00008000L
#ವ್ಯಾಖ್ಯಾನಿಸು MF_ಕೊನೆ 0x00000080L

#ವ್ಯಾಖ್ಯಾನಿಸು MFT_STRING MF_STRING
#ವ್ಯಾಖ್ಯಾನಿಸು MFT_BITMAP MF_BITMAP
#ವ್ಯಾಖ್ಯಾನಿಸು MFT_MENUBARBREAK MF_MENUBARBREAK
#ವ್ಯಾಖ್ಯಾನಿಸು MFT_MENUBREAK MF_MENUBREAK
#ವ್ಯಾಖ್ಯಾನಿಸು MFT_OWNERDRAW MF_OWNERDRAW
#ವ್ಯಾಖ್ಯಾನಿಸು MFT_RADIOCHECK 0x00000200L
#ವ್ಯಾಖ್ಯಾನಿಸು MFT_SEPARATOR MF_SEPARATOR
#ವ್ಯಾಖ್ಯಾನಿಸು MFT_RIGHTORDER 0x00002000L
#ವ್ಯಾಖ್ಯಾನಿಸು MFT_RIGHTJUSTIFY MF_RIGHTJUSTIFY

#ವ್ಯಾಖ್ಯಾನಿಸು MFS_GRAYED 0x00000003L
#ವ್ಯಾಖ್ಯಾನಿಸು MFS_DISABLED MFS_GRAYED
#ವ್ಯಾಖ್ಯಾನಿಸು MFS_CHECKED MF_CHECKED
#ವ್ಯಾಖ್ಯಾನಿಸು MFS_HILITE MF_HILITE
#ವ್ಯಾಖ್ಯಾನಿಸು MFS_ENABLED MF_ENABLED
#ವ್ಯಾಖ್ಯಾನಿಸು MFS_UNCHECKED MF_UNCHECKED
#ವ್ಯಾಖ್ಯಾನಿಸು MFS_UNHILITE MF_UNHILITE
#ವ್ಯಾಖ್ಯಾನಿಸು MFS_DEFAULT MF_DEFAULT

  WINUSERAPI WINBOOL WINAPI Check_Menu_Radio_ಅಂಶ(HMENU hmenu,UINT ಮೊದಲ,UINT ಕೊನೆಯ,UINT check,UINT flags);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಶಬ್ದ_3 ಆವೃತ್ತಿ_ಸಂಖ್ಯೆ;
    ಶಬ್ದ_3 ಸ್ಥಾನಾಂತರ;
  } MENUITEMTEMPLATEHEADER,*PMENUITEMTEMPLATEHEADER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    ಶಬ್ದ_3 mtOption;
    ಶಬ್ದ_3 mtID;
    WCHAR mtString[1];
  } MENUITEMTEMPLATE,*PMENUITEMTEMPLATE;
#ವ್ಯಾಖ್ಯಾನಿಸು MF_ಕೊನೆ 0x00000080L
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOSYSCOMMANDS

#ವ್ಯಾಖ್ಯಾನಿಸು SC_ಗಾತ್ರ 0xF000
#ವ್ಯಾಖ್ಯಾನಿಸು SC_MOVE 0xF010
#ವ್ಯಾಖ್ಯಾನಿಸು SC_MINIMIZE 0xF020
#ವ್ಯಾಖ್ಯಾನಿಸು SC_MAXIMIZE 0xF030
#ವ್ಯಾಖ್ಯಾನಿಸು SC_NEXTWINDOW 0xF040
#ವ್ಯಾಖ್ಯಾನಿಸು SC_PREVWINDOW 0xF050
#ವ್ಯಾಖ್ಯಾನಿಸು SC_CLOSE 0xF060
#ವ್ಯಾಖ್ಯಾನಿಸು SC_VSCROLL 0xF070
#ವ್ಯಾಖ್ಯಾನಿಸು SC_HSCROLL 0xF080
#ವ್ಯಾಖ್ಯಾನಿಸು SC_MOUSEMENU 0xF090
#ವ್ಯಾಖ್ಯಾನಿಸು SC_KEYMENU 0xF100
#ವ್ಯಾಖ್ಯಾನಿಸು SC_ARRANGE 0xF110
#ವ್ಯಾಖ್ಯಾನಿಸು SC_RESTORE 0xF120
#ವ್ಯಾಖ್ಯಾನಿಸು SC_TASKLIST 0xF130
#ವ್ಯಾಖ್ಯಾನಿಸು SC_SCREENSAVE 0xF140
#ವ್ಯಾಖ್ಯಾನಿಸು SC_HOTKEY 0xF150
#ವ್ಯಾಖ್ಯಾನಿಸು SC_DEFAULT 0xF160
#ವ್ಯಾಖ್ಯಾನಿಸು SC_MONITORPOWER 0xF170
#ವ್ಯಾಖ್ಯಾನಿಸು SC_CONTEXTHELP 0xF180
#ವ್ಯಾಖ್ಯಾನಿಸು SC_SEPARATOR 0xF00F
#ವ್ಯಾಖ್ಯಾನಿಸು SC_ICON SC_MINIMIZE
#ವ್ಯಾಖ್ಯಾನಿಸು SC_ZOOM SC_MAXIMIZE
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Bitmap ತುಂಬು_Bitmap_W
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Cursor ತುಂಬು_Cursor_W
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Cursor_From_File ತುಂಬು_Cursor_From_File_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Bitmap ತುಂಬು_Bitmap_A
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Cursor ತುಂಬು_Cursor_A
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Cursor_From_File ತುಂಬು_Cursor_From_File_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HBITMAP WINAPI ತುಂಬು_Bitmap_A(HINSTANCE hInstance,LPCSTR lpBitmapName);
  WINUSERAPI HBITMAP WINAPI ತುಂಬು_Bitmap_W(HINSTANCE hInstance,LPCWSTR lpBitmapName);
  WINUSERAPI HCURSOR WINAPI ತುಂಬು_Cursor_A(HINSTANCE hInstance,LPCSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI ತುಂಬು_Cursor_W(HINSTANCE hInstance,LPCWSTR lpCursorName);
  WINUSERAPI HCURSOR WINAPI ತುಂಬು_Cursor_From_File_A(LPCSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI ತುಂಬು_Cursor_From_File_W(LPCWSTR lpFileName);
  WINUSERAPI HCURSOR WINAPI CreateCursor(HINSTANCE hInst,ಪೂರ್ಣಾಂಕ xHotSpot,ಪೂರ್ಣಾಂಕ yHotSpot,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ,CONST VOID *pvANDPlane,CONST VOID *pvXORPlane);
  WINUSERAPI WINBOOL WINAPI DestroyCursor(HCURSOR hCursor);

#ವ್ಯಾಖ್ಯಾನಿಸು CopyCursor(pcur) ((HCURSOR)CopyIcon((HICON)(pcur)))

#ವ್ಯಾಖ್ಯಾನಿಸು IDC_ARROW MAKEINTRESOURCE(32512)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_IBEAM MAKEINTRESOURCE(32513)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_WAIT MAKEINTRESOURCE(32514)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_CROSS MAKEINTRESOURCE(32515)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_UPARROW MAKEINTRESOURCE(32516)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_ಗಾತ್ರ MAKEINTRESOURCE(32640)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_ICON MAKEINTRESOURCE(32641)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_SIZENWSE MAKEINTRESOURCE(32642)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_SIZENESW MAKEINTRESOURCE(32643)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_SIZEWE MAKEINTRESOURCE(32644)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_SIZENS MAKEINTRESOURCE(32645)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_SIZEALL MAKEINTRESOURCE(32646)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_NO MAKEINTRESOURCE(32648)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_HAND MAKEINTRESOURCE(32649)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_APPSTARTING MAKEINTRESOURCE(32650)
#ವ್ಯಾಖ್ಯಾನಿಸು IDC_HELP MAKEINTRESOURCE(32651)

  WINUSERAPI WINBOOL WINAPI ಗಣ_System_Cursor(HCURSOR hcur,DWORD id);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ICONINFO {
    WINBOOL fIcon;
    DWORD xHotspot;
    DWORD yHotspot;
    HBITMAP hbm_ಮುಖವಾಡ;
    HBITMAP hbmColor;
  } ICONINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ICONINFO *PICONINFO;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Icon ತುಂಬು_Icon_W
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಸಗಿ_ಹೊರತೆಗೆ_Icons ಖಾಸಗಿ_ಹೊರತೆಗೆ_Icons_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Icon ತುಂಬು_Icon_A
#ವ್ಯಾಖ್ಯಾನಿಸು ಖಾಸಗಿ_ಹೊರತೆಗೆ_Icons ಖಾಸಗಿ_ಹೊರತೆಗೆ_Icons_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HICON WINAPI ತುಂಬು_Icon_A(HINSTANCE hInstance,LPCSTR lpIconName);
  WINUSERAPI HICON WINAPI ತುಂಬು_Icon_W(HINSTANCE hInstance,LPCWSTR lpIconName);
  WINUSERAPI UINT WINAPI ಖಾಸಗಿ_ಹೊರತೆಗೆ_Icons_A(LPCSTR szFileName,ಪೂರ್ಣಾಂಕ n_Icon_ಸೂಚ್ಯಂಕ,ಪೂರ್ಣಾಂಕ cxIcon,ಪೂರ್ಣಾಂಕ cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI UINT WINAPI ಖಾಸಗಿ_ಹೊರತೆಗೆ_Icons_W(LPCWSTR szFileName,ಪೂರ್ಣಾಂಕ n_Icon_ಸೂಚ್ಯಂಕ,ಪೂರ್ಣಾಂಕ cxIcon,ಪೂರ್ಣಾಂಕ cyIcon,HICON *phicon,UINT *piconid,UINT nIcons,UINT flags);
  WINUSERAPI HICON WINAPI CreateIcon(HINSTANCE hInstance,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ,BYTE cPlanes,BYTE c_ಬಿಟ್ಟುಗಳು_Pixel,CONST BYTE *lpbANDbits,CONST BYTE *lpbXORbits);
  WINUSERAPI WINBOOL WINAPI DestroyIcon(HICON hIcon);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI LookupIconIdFromDirectory(PBYTE presbits,WINBOOL fIcon);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI LookupIconIdFromDirectoryEx(PBYTE presbits,WINBOOL fIcon,ಪೂರ್ಣಾಂಕ cxDesired,ಪೂರ್ಣಾಂಕ cyDesired,UINT Flags);
  WINUSERAPI HICON WINAPI CreateIconFromResource(PBYTE presbits,DWORD dw_Res_ಗಾತ್ರ,WINBOOL fIcon,DWORD dwVer);
  WINUSERAPI HICON WINAPI CreateIconFromResourceEx(PBYTE presbits,DWORD dw_Res_ಗಾತ್ರ,WINBOOL fIcon,DWORD dwVer,ಪೂರ್ಣಾಂಕ cxDesired,ಪೂರ್ಣಾಂಕ cyDesired,UINT Flags);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CURSORSHAPE {
    ಪೂರ್ಣಾಂಕ xHotSpot;
    ಪೂರ್ಣಾಂಕ yHotSpot;
    ಪೂರ್ಣಾಂಕ cx;
    ಪೂರ್ಣಾಂಕ cy;
    ಪೂರ್ಣಾಂಕ cb_ಅಗಲ;
    BYTE Planes;
    BYTE ಬಿಟ್ಟುಗಳು_Pixel;
  } CURSORSHAPE,*LPCURSORSHAPE;

#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_BITMAP 0
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ICON 1
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_CURSOR 2
#ವ್ಯಾಖ್ಯಾನಿಸು IMAGE_ENHMETAFILE 3

#ವ್ಯಾಖ್ಯಾನಿಸು LR_DEFAULTCOLOR 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು LR_MONOCHROME 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು LR_COLOR 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು LR_COPYRETURNORG 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು LR_COPYDELETEORG 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು LR_LOADFROMFILE 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು LR_LOADTRANSPARENT 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು LR_DEFAULTSIZE 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು LR_VGACOLOR 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು LR_LOADMAP3DCOLORS 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು LR_CREATEDIBSECTION 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು LR_COPYFROMRESOURCE 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು LR_SHARED 0x8000

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Image ತುಂಬು_Image_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_Image ತುಂಬು_Image_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI HANDLE WINAPI ತುಂಬು_Image_A(HINSTANCE hInst,LPCSTR name,UINT type,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy,UINT fu_ತುಂಬು);
  WINUSERAPI HANDLE WINAPI ತುಂಬು_Image_W(HINSTANCE hInst,LPCWSTR name,UINT type,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy,UINT fu_ತುಂಬು);
  WINUSERAPI HANDLE WINAPI CopyImage(HANDLE h,UINT type,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy,UINT flags);

#ವ್ಯಾಖ್ಯಾನಿಸು DI_ಮುಖವಾಡ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DI_IMAGE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DI_ಸಾಮಾನ್ಯ 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು DI_COMPAT 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು DI_DEFAULTSIZE 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು DI_NOMIRROR 0x0010

  WINUSERAPI WINBOOL WINAPI DrawIconEx(HDC hdc,ಪೂರ್ಣಾಂಕ x_ಎಡ,ಪೂರ್ಣಾಂಕ y_ತುದಿ,HICON hIcon,ಪೂರ್ಣಾಂಕ cx_ಅಗಲ,ಪೂರ್ಣಾಂಕ cy_ಅಗಲ,UINT istepIfAniCur,HBRUSH hbrFlickerFreeDraw,UINT diFlags);
  WINUSERAPI HICON WINAPI Create_Icon_ಪರೋಕ್ಷ(PICONINFO piconinfo);
  WINUSERAPI HICON WINAPI CopyIcon(HICON hIcon);
  WINUSERAPI WINBOOL WINAPI GetIconInfo(HICON hIcon,PICONINFO piconinfo);

#ವ್ಯಾಖ್ಯಾನಿಸು RES_ICON 1
#ವ್ಯಾಖ್ಯಾನಿಸು RES_CURSOR 2

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ OEMRESOURCE

#ವ್ಯಾಖ್ಯಾನಿಸು OBM_CLOSE 32754
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_UPARROW 32753
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_DNARROW 32752
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_RGARROW 32751
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_LFARROW 32750
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_REDUCE 32749
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_ZOOM 32748
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_RESTORE 32747
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_REDUCED 32746
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_ZOOMD 32745
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_RESTORED 32744
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_UPARROWD 32743
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_DNARROWD 32742
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_RGARROWD 32741
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_LFARROWD 32740
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_MNARROW 32739
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_COMBO 32738
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_UPARROWI 32737
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_DNARROWI 32736
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_RGARROWI 32735
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_LFARROWI 32734

#ವ್ಯಾಖ್ಯಾನಿಸು OBM_OLD_CLOSE 32767
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_ಗಾತ್ರ 32766
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_OLD_UPARROW 32765
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_OLD_DNARROW 32764
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_OLD_RGARROW 32763
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_OLD_LFARROW 32762
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_BTSIZE 32761
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_CHECK 32760
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_CHECKBOXES 32759
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_BTNCORNERS 32758
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_OLD_REDUCE 32757
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_OLD_ZOOM 32756
#ವ್ಯಾಖ್ಯಾನಿಸು OBM_OLD_RESTORE 32755

#ವ್ಯಾಖ್ಯಾನಿಸು OCR_ಸಾಮಾನ್ಯ 32512
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_IBEAM 32513
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_WAIT 32514
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_CROSS 32515
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_ಮೇಲೆ 32516
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_ಗಾತ್ರ 32640
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_ICON 32641
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_SIZENWSE 32642
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_SIZENESW 32643
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_SIZEWE 32644
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_SIZENS 32645
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_SIZEALL 32646
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_ICOCUR 32647
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_NO 32648
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_HAND 32649
#ವ್ಯಾಖ್ಯಾನಿಸು OCR_APPSTARTING 32650

#ವ್ಯಾಖ್ಯಾನಿಸು OIC_SAMPLE 32512
#ವ್ಯಾಖ್ಯಾನಿಸು OIC_HAND 32513
#ವ್ಯಾಖ್ಯಾನಿಸು OIC_QUES 32514
#ವ್ಯಾಖ್ಯಾನಿಸು OIC_BANG 32515
#ವ್ಯಾಖ್ಯಾನಿಸು OIC_NOTE 32516
#ವ್ಯಾಖ್ಯಾನಿಸು OIC_WINLOGO 32517
#ವ್ಯಾಖ್ಯಾನಿಸು OIC_WARNING OIC_BANG
#ವ್ಯಾಖ್ಯಾನಿಸು OIC_ERROR OIC_HAND
#ವ್ಯಾಖ್ಯಾನಿಸು OIC_INFORMATION OIC_NOTE
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ORD_LANGDRIVER 1

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOICONS

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ RC_INVOKED
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_APPLICATION 32512
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_HAND 32513
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_QUESTION 32514
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_EXCLAMATION 32515
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_ASTERISK 32516
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_WINLOGO 32517
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_APPLICATION MAKEINTRESOURCE(32512)
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_HAND MAKEINTRESOURCE(32513)
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_QUESTION MAKEINTRESOURCE(32514)
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_EXCLAMATION MAKEINTRESOURCE(32515)
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_ASTERISK MAKEINTRESOURCE(32516)
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_WINLOGO MAKEINTRESOURCE(32517)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು IDI_WARNING IDI_EXCLAMATION
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_ERROR IDI_HAND
#ವ್ಯಾಖ್ಯಾನಿಸು IDI_INFORMATION IDI_ASTERISK
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_String ತುಂಬು_String_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ತುಂಬು_String ತುಂಬು_String_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ತುಂಬು_String_A(HINSTANCE hInstance,UINT uID,LPSTR lp_ಬಫರ್,ಪೂರ್ಣಾಂಕ cch_ಬಫರ್_Max);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ತುಂಬು_String_W(HINSTANCE hInstance,UINT uID,LPWSTR lp_ಬಫರ್,ಪೂರ್ಣಾಂಕ cch_ಬಫರ್_Max);

#ವ್ಯಾಖ್ಯಾನಿಸು IDOK 1
#ವ್ಯಾಖ್ಯಾನಿಸು IDCANCEL 2
#ವ್ಯಾಖ್ಯಾನಿಸು IDABORT 3
#ವ್ಯಾಖ್ಯಾನಿಸು IDRETRY 4
#ವ್ಯಾಖ್ಯಾನಿಸು IDIGNORE 5
#ವ್ಯಾಖ್ಯಾನಿಸು IDYES 6
#ವ್ಯಾಖ್ಯಾನಿಸು IDNO 7
#ವ್ಯಾಖ್ಯಾನಿಸು IDCLOSE 8
#ವ್ಯಾಖ್ಯಾನಿಸು IDHELP 9
#ವ್ಯಾಖ್ಯಾನಿಸು IDTRYAGAIN 10
#ವ್ಯಾಖ್ಯಾನಿಸು IDCONTINUE 11

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ IDTIMEOUT
#ವ್ಯಾಖ್ಯಾನಿಸು IDTIMEOUT 32000
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOCTLMGR

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINSTYLES
#ವ್ಯಾಖ್ಯಾನಿಸು ES_ಎಡ 0x0000L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_CENTER 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_ಬಲ 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_MULTILINE 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_UPPERCASE 0x0008L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_LOWERCASE 0x0010L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_PASSWORD 0x0020L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_AUTOVSCROLL 0x0040L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_AUTOHSCROLL 0x0080L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_NOHIDESEL 0x0100L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_OEMCONVERT 0x0400L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_READONLY 0x0800L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_WANTRETURN 0x1000L
#ವ್ಯಾಖ್ಯಾನಿಸು ES_ಸಂಖ್ಯೆ 0x2000L
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು EN_SETFOCUS 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು EN_KILLFOCUS 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು EN_CHANGE 0x0300
#ವ್ಯಾಖ್ಯಾನಿಸು EN_UPDATE 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು EN_ERRSPACE 0x0500
#ವ್ಯಾಖ್ಯಾನಿಸು EN_MAXTEXT 0x0501
#ವ್ಯಾಖ್ಯಾನಿಸು EN_HSCROLL 0x0601
#ವ್ಯಾಖ್ಯಾನಿಸು EN_VSCROLL 0x0602
#ವ್ಯಾಖ್ಯಾನಿಸು EN_ALIGN_LTR_EC 0x0700
#ವ್ಯಾಖ್ಯಾನಿಸು EN_ALIGN_RTL_EC 0x0701

#ವ್ಯಾಖ್ಯಾನಿಸು EC_LEFTMARGIN 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು EC_RIGHTMARGIN 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು EC_USEFONTINFO 0xffff

#ವ್ಯಾಖ್ಯಾನಿಸು EMSIS_COMPOSITIONSTRING 0x0001

#ವ್ಯಾಖ್ಯಾನಿಸು EIMES_GETCOMPSTRATONCE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು EIMES_CANCELCOMPSTRINFOCUS 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು EIMES_COMPLETECOMPSTRKILLFOCUS 0x0004

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINMESSAGES

#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETSEL 0x00B0
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETSEL 0x00B1
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETRECT 0x00B2
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETRECT 0x00B3
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETRECTNP 0x00B4
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SCROLL 0x00B5
#ವ್ಯಾಖ್ಯಾನಿಸು EM_LINESCROLL 0x00B6
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SCROLLCARET 0x00B7
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETMODIFY 0x00B8
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETMODIFY 0x00B9
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETLINECOUNT 0x00BA
#ವ್ಯಾಖ್ಯಾನಿಸು EM_LINEINDEX 0x00BB
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETHANDLE 0x00BC
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETHANDLE 0x00BD
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETTHUMB 0x00BE
#ವ್ಯಾಖ್ಯಾನಿಸು EM_LINELENGTH 0x00C1
#ವ್ಯಾಖ್ಯಾನಿಸು EM_REPLACESEL 0x00C2
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETLINE 0x00C4
#ವ್ಯಾಖ್ಯಾನಿಸು EM_LIMITTEXT 0x00C5
#ವ್ಯಾಖ್ಯಾನಿಸು EM_CANUNDO 0x00C6
#ವ್ಯಾಖ್ಯಾನಿಸು EM_UNDO 0x00C7
#ವ್ಯಾಖ್ಯಾನಿಸು EM_FMTLINES 0x00C8
#ವ್ಯಾಖ್ಯಾನಿಸು EM_LINEFROMCHAR 0x00C9
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETTABSTOPS 0x00CB
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETPASSWORDCHAR 0x00CC
#ವ್ಯಾಖ್ಯಾನಿಸು EM_EMPTYUNDOBUFFER 0x00CD
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETFIRSTVISIBLELINE 0x00CE
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETREADONLY 0x00CF
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETWORDBREAKPROC 0x00D0
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETWORDBREAKPROC 0x00D1
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETPASSWORDCHAR 0x00D2
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETMARGINS 0x00D3
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETMARGINS 0x00D4
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETLIMITTEXT EM_LIMITTEXT
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETLIMITTEXT 0x00D5
#ವ್ಯಾಖ್ಯಾನಿಸು EM_POSFROMCHAR 0x00D6
#ವ್ಯಾಖ್ಯಾನಿಸು EM_CHARFROMPOS 0x00D7
#ವ್ಯಾಖ್ಯಾನಿಸು EM_SETIMESTATUS 0x00D8
#ವ್ಯಾಖ್ಯಾನಿಸು EM_GETIMESTATUS 0x00D9
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು WB_ಎಡ 0
#ವ್ಯಾಖ್ಯಾನಿಸು WB_ಬಲ 1
#ವ್ಯಾಖ್ಯಾನಿಸು WB_ISDELIMITER 2

#ವ್ಯಾಖ್ಯಾನಿಸು BS_PUSHBUTTON 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_DEFPUSHBUTTON 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_CHECKBOX 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_AUTOCHECKBOX 0x00000003L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_RADIOBUTTON 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_3STATE 0x00000005L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_AUTO3STATE 0x00000006L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_GROUPBOX 0x00000007L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_USERBUTTON 0x00000008L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_AUTORADIOBUTTON 0x00000009L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_PUSHBOX 0x0000000AL
#ವ್ಯಾಖ್ಯಾನಿಸು BS_OWNERDRAW 0x0000000BL
#ವ್ಯಾಖ್ಯಾನಿಸು BS_TYPEMASK 0x0000000FL
#ವ್ಯಾಖ್ಯಾನಿಸು BS_LEFTTEXT 0x00000020L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_ಪಠ್ಯ 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_ICON 0x00000040L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_BITMAP 0x00000080L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_ಎಡ 0x00000100L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_ಬಲ 0x00000200L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_CENTER 0x00000300L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_ತುದಿ 0x00000400L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_BOTTOM 0x00000800L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_VCENTER 0x00000C00L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_PUSHLIKE 0x00001000L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_MULTILINE 0x00002000L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_NOTIFY 0x00004000L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_FLAT 0x00008000L
#ವ್ಯಾಖ್ಯಾನಿಸು BS_RIGHTBUTTON BS_LEFTTEXT

#ವ್ಯಾಖ್ಯಾನಿಸು BN_CLICKED 0
#ವ್ಯಾಖ್ಯಾನಿಸು BN_PAINT 1
#ವ್ಯಾಖ್ಯಾನಿಸು BN_HILITE 2
#ವ್ಯಾಖ್ಯಾನಿಸು BN_UNHILITE 3
#ವ್ಯಾಖ್ಯಾನಿಸು BN_DISABLE 4
#ವ್ಯಾಖ್ಯಾನಿಸು BN_DOUBLECLICKED 5
#ವ್ಯಾಖ್ಯಾನಿಸು BN_PUSHED BN_HILITE
#ವ್ಯಾಖ್ಯಾನಿಸು BN_UNPUSHED BN_UNHILITE
#ವ್ಯಾಖ್ಯಾನಿಸು BN_DBLCLK BN_DOUBLECLICKED
#ವ್ಯಾಖ್ಯಾನಿಸು BN_SETFOCUS 6
#ವ್ಯಾಖ್ಯಾನಿಸು BN_KILLFOCUS 7

#ವ್ಯಾಖ್ಯಾನಿಸು BM_GETCHECK 0x00F0
#ವ್ಯಾಖ್ಯಾನಿಸು BM_SETCHECK 0x00F1
#ವ್ಯಾಖ್ಯಾನಿಸು BM_GETSTATE 0x00F2
#ವ್ಯಾಖ್ಯಾನಿಸು BM_SETSTATE 0x00F3
#ವ್ಯಾಖ್ಯಾನಿಸು BM_SETSTYLE 0x00F4
#ವ್ಯಾಖ್ಯಾನಿಸು BM_CLICK 0x00F5
#ವ್ಯಾಖ್ಯಾನಿಸು BM_GETIMAGE 0x00F6
#ವ್ಯಾಖ್ಯಾನಿಸು BM_SETIMAGE 0x00F7

#ವ್ಯಾಖ್ಯಾನಿಸು BST_UNCHECKED 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು BST_CHECKED 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು BST_INDETERMINATE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು BST_PUSHED 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು BST_FOCUS 0x0008

#ವ್ಯಾಖ್ಯಾನಿಸು SS_ಎಡ 0x00000000L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_CENTER 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_ಬಲ 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_ICON 0x00000003L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_BLACKRECT 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_GRAYRECT 0x00000005L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_WHITERECT 0x00000006L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_BLACKFRAME 0x00000007L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_GRAYFRAME 0x00000008L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_WHITEFRAME 0x00000009L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_USERITEM 0x0000000AL
#ವ್ಯಾಖ್ಯಾನಿಸು SS_SIMPLE 0x0000000BL
#ವ್ಯಾಖ್ಯಾನಿಸು SS_LEFTNOWORDWRAP 0x0000000CL
#ವ್ಯಾಖ್ಯಾನಿಸು SS_OWNERDRAW 0x0000000DL
#ವ್ಯಾಖ್ಯಾನಿಸು SS_BITMAP 0x0000000EL
#ವ್ಯಾಖ್ಯಾನಿಸು SS_ENHMETAFILE 0x0000000FL
#ವ್ಯಾಖ್ಯಾನಿಸು SS_ETCHEDHORZ 0x00000010L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_ETCHEDVERT 0x00000011L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_ETCHEDFRAME 0x00000012L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_TYPEMASK 0x0000001FL
#ವ್ಯಾಖ್ಯಾನಿಸು SS_REALSIZECONTROL 0x00000040L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_NOPREFIX 0x00000080L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_NOTIFY 0x00000100L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_CENTERIMAGE 0x00000200L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_RIGHTJUST 0x00000400L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_REALSIZEIMAGE 0x00000800L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_SUNKEN 0x00001000L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_EDITCONTROL 0x00002000L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_ENDELLIPSIS 0x00004000L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_PATHELLIPSIS 0x00008000L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_WORDELLIPSIS 0x0000C000L
#ವ್ಯಾಖ್ಯಾನಿಸು SS_ELLIPSISMASK 0x0000C000L

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINMESSAGES

#ವ್ಯಾಖ್ಯಾನಿಸು STM_SETICON 0x0170
#ವ್ಯಾಖ್ಯಾನಿಸು STM_GETICON 0x0171
#ವ್ಯಾಖ್ಯಾನಿಸು STM_SETIMAGE 0x0172
#ವ್ಯಾಖ್ಯಾನಿಸು STM_GETIMAGE 0x0173
#ವ್ಯಾಖ್ಯಾನಿಸು STN_CLICKED 0
#ವ್ಯಾಖ್ಯಾನಿಸು STN_DBLCLK 1
#ವ್ಯಾಖ್ಯಾನಿಸು STN_ENABLE 2
#ವ್ಯಾಖ್ಯಾನಿಸು STN_DISABLE 3
#ವ್ಯಾಖ್ಯಾನಿಸು STM_MSGMAX 0x0174
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು WC_DIALOG (MAKEINTATOM(0x8002))

#ವ್ಯಾಖ್ಯಾನಿಸು DWL_MSGRESULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು DWL_DLGPROC 4
#ವ್ಯಾಖ್ಯಾನಿಸು DWL_USER 8

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64

#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು DWL_MSGRESULT
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು DWL_DLGPROC
#ವ್ಯಾಖ್ಯಾನ_ರದ್ದು DWL_USER
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು DWLP_MSGRESULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು DWLP_DLGPROC DWLP_MSGRESULT + ಗಾತ್ರ(LRESULT)
#ವ್ಯಾಖ್ಯಾನಿಸು DWLP_USER DWLP_DLGPROC + ಗಾತ್ರ(DLGPROC)

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMSG

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Is_Dialog_ಸಂದೇಶ Is_Dialog_ಸಂದೇಶ_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Is_Dialog_ಸಂದೇಶ Is_Dialog_ಸಂದೇಶ_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI Is_Dialog_ಸಂದೇಶ_A(HWND hDlg,LPMSG lp_ಸಂದೇಶ_2);
  WINUSERAPI WINBOOL WINAPI Is_Dialog_ಸಂದೇಶ_W(HWND hDlg,LPMSG lp_ಸಂದೇಶ_2);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು DlgDirList DlgDirListW
#ವ್ಯಾಖ್ಯಾನಿಸು DlgDirSelectEx DlgDirSelectExW
#ವ್ಯಾಖ್ಯಾನಿಸು DlgDirListComboBox DlgDirListComboBoxW
#ವ್ಯಾಖ್ಯಾನಿಸು DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು DlgDirList DlgDirListA
#ವ್ಯಾಖ್ಯಾನಿಸು DlgDirSelectEx DlgDirSelectExA
#ವ್ಯಾಖ್ಯಾನಿಸು DlgDirListComboBox DlgDirListComboBoxA
#ವ್ಯಾಖ್ಯಾನಿಸು DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI MapDialogRect(HWND hDlg,LPRECT lpRect);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI DlgDirListA(HWND hDlg,LPSTR lp_ಮಾರ್ಗ_Spec,ಪೂರ್ಣಾಂಕ nIDListBox,ಪೂರ್ಣಾಂಕ n_IDStatic_ಮಾರ್ಗ,UINT uFileType);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI DlgDirListW(HWND hDlg,LPWSTR lp_ಮಾರ್ಗ_Spec,ಪೂರ್ಣಾಂಕ nIDListBox,ಪೂರ್ಣಾಂಕ n_IDStatic_ಮಾರ್ಗ,UINT uFileType);

#ವ್ಯಾಖ್ಯಾನಿಸು DDL_READWRITE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು DDL_READONLY 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DDL_HIDDEN 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DDL_SYSTEM 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು DDL_DIRECTORY 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು DDL_ARCHIVE 0x0020

#ವ್ಯಾಖ್ಯಾನಿಸು DDL_POSTMSGS 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು DDL_DRIVES 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು DDL_EXCLUSIVE 0x8000

  WINUSERAPI WINBOOL WINAPI DlgDirSelectExA(HWND hwndDlg,LPSTR lpString,ಪೂರ್ಣಾಂಕ ch_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ idListBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectExW(HWND hwndDlg,LPWSTR lpString,ಪೂರ್ಣಾಂಕ ch_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ idListBox);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI DlgDirListComboBoxA(HWND hDlg,LPSTR lp_ಮಾರ್ಗ_Spec,ಪೂರ್ಣಾಂಕ nIDComboBox,ಪೂರ್ಣಾಂಕ n_IDStatic_ಮಾರ್ಗ,UINT uFiletype);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI DlgDirListComboBoxW(HWND hDlg,LPWSTR lp_ಮಾರ್ಗ_Spec,ಪೂರ್ಣಾಂಕ nIDComboBox,ಪೂರ್ಣಾಂಕ n_IDStatic_ಮಾರ್ಗ,UINT uFiletype);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExA(HWND hwndDlg,LPSTR lpString,ಪೂರ್ಣಾಂಕ cch_ಹೊರಹೋಗು,ಪೂರ್ಣಾಂಕ idComboBox);
  WINUSERAPI WINBOOL WINAPI DlgDirSelectComboBoxExW(HWND hwndDlg,LPWSTR lpString,ಪೂರ್ಣಾಂಕ cch_ಹೊರಹೋಗು,ಪೂರ್ಣಾಂಕ idComboBox);

#ವ್ಯಾಖ್ಯಾನಿಸು DS_ABSALIGN 0x01L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_SYSMODAL 0x02L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_LOCALEDIT 0x20L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_SETFONT 0x40L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_MODALFRAME 0x80L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_NOIDLEMSG 0x100L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_SETFOREGROUND 0x200L

#ವ್ಯಾಖ್ಯಾನಿಸು DS_3DLOOK 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_FIXEDSYS 0x0008L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_NOFAILCREATE 0x0010L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_CONTROL 0x0400L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_CENTER 0x0800L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_CENTERMOUSE 0x1000L
#ವ್ಯಾಖ್ಯಾನಿಸು DS_CONTEXTHELP 0x2000L

#ವ್ಯಾಖ್ಯಾನಿಸು DS_SHELLFONT (DS_SETFONT | DS_FIXEDSYS)

#ಆದರೆ(_WIN32_WCE >= 0x0500)
#ವ್ಯಾಖ್ಯಾನಿಸು DS_USEPIXELS 0x8000L
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು DM_GETDEFID (WM_USER+0)
#ವ್ಯಾಖ್ಯಾನಿಸು DM_SETDEFID (WM_USER+1)
#ವ್ಯಾಖ್ಯಾನಿಸು DM_REPOSITION (WM_USER+2)

#ವ್ಯಾಖ್ಯಾನಿಸು DC_HASDEFID 0x534B

#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_WANTARROWS 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_WANTTAB 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_WANTALLKEYS 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_WANTMESSAGE 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_HASSETSEL 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_DEFPUSHBUTTON 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_UNDEFPUSHBUTTON 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_RADIOBUTTON 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_WANTCHARS 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_STATIC 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು DLGC_BUTTON 0x2000

#ವ್ಯಾಖ್ಯಾನಿಸು LB_CTLCODE 0L

#ವ್ಯಾಖ್ಯಾನಿಸು LB_OKAY 0
#ವ್ಯಾಖ್ಯಾನಿಸು LB_ERR (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು LB_ERRSPACE (-2)

#ವ್ಯಾಖ್ಯಾನಿಸು LBN_ERRSPACE (-2)
#ವ್ಯಾಖ್ಯಾನಿಸು LBN_SELCHANGE 1
#ವ್ಯಾಖ್ಯಾನಿಸು LBN_DBLCLK 2
#ವ್ಯಾಖ್ಯಾನಿಸು LBN_SELCANCEL 3
#ವ್ಯಾಖ್ಯಾನಿಸು LBN_SETFOCUS 4
#ವ್ಯಾಖ್ಯಾನಿಸು LBN_KILLFOCUS 5

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINMESSAGES

#ವ್ಯಾಖ್ಯಾನಿಸು LB_ADDSTRING 0x0180
#ವ್ಯಾಖ್ಯಾನಿಸು LB_INSERTSTRING 0x0181
#ವ್ಯಾಖ್ಯಾನಿಸು LB_DELETESTRING 0x0182
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SELITEMRANGEEX 0x0183
#ವ್ಯಾಖ್ಯಾನಿಸು LB_RESETCONTENT 0x0184
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETSEL 0x0185
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETCURSEL 0x0186
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETSEL 0x0187
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETCURSEL 0x0188
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETTEXT 0x0189
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETTEXTLEN 0x018A
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETCOUNT 0x018B
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SELECTSTRING 0x018C
#ವ್ಯಾಖ್ಯಾನಿಸು LB_DIR 0x018D
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETTOPINDEX 0x018E
#ವ್ಯಾಖ್ಯಾನಿಸು LB_FINDSTRING 0x018F
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETSELCOUNT 0x0190
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETSELITEMS 0x0191
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETTABSTOPS 0x0192
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETHORIZONTALEXTENT 0x0193
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETHORIZONTALEXTENT 0x0194
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETCOLUMNWIDTH 0x0195
#ವ್ಯಾಖ್ಯಾನಿಸು LB_ADDFILE 0x0196
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETTOPINDEX 0x0197
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETITEMRECT 0x0198
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETITEMDATA 0x0199
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETITEMDATA 0x019A
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SELITEMRANGE 0x019B
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETANCHORINDEX 0x019C
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETANCHORINDEX 0x019D
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETCARETINDEX 0x019E
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETCARETINDEX 0x019F
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETITEMHEIGHT 0x01A0
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETITEMHEIGHT 0x01A1
#ವ್ಯಾಖ್ಯಾನಿಸು LB_FINDSTRINGEXACT 0x01A2
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETLOCALE 0x01A5
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETLOCALE 0x01A6
#ವ್ಯಾಖ್ಯಾನಿಸು LB_SETCOUNT 0x01A7
#ವ್ಯಾಖ್ಯಾನಿಸು LB_INITSTORAGE 0x01A8
#ವ್ಯಾಖ್ಯಾನಿಸು LB_ITEMFROMPOINT 0x01A9
#ಆದರೆ(_WIN32_WCE >= 0x0400)
#ವ್ಯಾಖ್ಯಾನಿಸು LB_MULTIPLEADDSTRING 0x01B1
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು LB_GETLISTBOXINFO 0x01B2
#ವ್ಯಾಖ್ಯಾನಿಸು LB_MSGMAX 0x01B3
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINSTYLES

#ವ್ಯಾಖ್ಯಾನಿಸು LBS_NOTIFY 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_ವಿಂಗಡಿಸು 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_NOREDRAW 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_MULTIPLESEL 0x0008L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_OWNERDRAWFIXED 0x0010L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_OWNERDRAWVARIABLE 0x0020L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_HASSTRINGS 0x0040L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_USETABSTOPS 0x0080L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_NOINTEGRALHEIGHT 0x0100L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_MULTICOLUMN 0x0200L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_WANTKEYBOARDINPUT 0x0400L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_EXTENDEDSEL 0x0800L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_DISABLENOSCROLL 0x1000L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_NODATA 0x2000L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_NOSEL 0x4000L
#ವ್ಯಾಖ್ಯಾನಿಸು LBS_COMBOBOX 0x8000L

#ವ್ಯಾಖ್ಯಾನಿಸು LBS_STANDARD (LBS_NOTIFY | LBS_ವಿಂಗಡಿಸು | WS_VSCROLL | WS_BORDER)
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು CB_OKAY 0
#ವ್ಯಾಖ್ಯಾನಿಸು CB_ERR (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು CB_ERRSPACE (-2)

#ವ್ಯಾಖ್ಯಾನಿಸು CBN_ERRSPACE (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_SELCHANGE 1
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_DBLCLK 2
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_SETFOCUS 3
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_KILLFOCUS 4
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_EDITCHANGE 5
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_EDITUPDATE 6
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_DROPDOWN 7
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_CLOSEUP 8
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_SELENDOK 9
#ವ್ಯಾಖ್ಯಾನಿಸು CBN_SELENDCANCEL 10

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINSTYLES

#ವ್ಯಾಖ್ಯಾನಿಸು CBS_SIMPLE 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_DROPDOWN 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_DROPDOWNLIST 0x0003L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_OWNERDRAWFIXED 0x0010L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_OWNERDRAWVARIABLE 0x0020L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_AUTOHSCROLL 0x0040L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_OEMCONVERT 0x0080L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_ವಿಂಗಡಿಸು 0x0100L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_HASSTRINGS 0x0200L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_NOINTEGRALHEIGHT 0x0400L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_DISABLENOSCROLL 0x0800L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_UPPERCASE 0x2000L
#ವ್ಯಾಖ್ಯಾನಿಸು CBS_LOWERCASE 0x4000L
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINMESSAGES
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETEDITSEL 0x0140
#ವ್ಯಾಖ್ಯಾನಿಸು CB_LIMITTEXT 0x0141
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SETEDITSEL 0x0142
#ವ್ಯಾಖ್ಯಾನಿಸು CB_ADDSTRING 0x0143
#ವ್ಯಾಖ್ಯಾನಿಸು CB_DELETESTRING 0x0144
#ವ್ಯಾಖ್ಯಾನಿಸು CB_DIR 0x0145
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETCOUNT 0x0146
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETCURSEL 0x0147
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETLBTEXT 0x0148
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETLBTEXTLEN 0x0149
#ವ್ಯಾಖ್ಯಾನಿಸು CB_INSERTSTRING 0x014A
#ವ್ಯಾಖ್ಯಾನಿಸು CB_RESETCONTENT 0x014B
#ವ್ಯಾಖ್ಯಾನಿಸು CB_FINDSTRING 0x014C
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SELECTSTRING 0x014D
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SETCURSEL 0x014E
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SHOWDROPDOWN 0x014F
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETITEMDATA 0x0150
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SETITEMDATA 0x0151
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETDROPPEDCONTROLRECT 0x0152
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SETITEMHEIGHT 0x0153
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETITEMHEIGHT 0x0154
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SETEXTENDEDUI 0x0155
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETEXTENDEDUI 0x0156
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETDROPPEDSTATE 0x0157
#ವ್ಯಾಖ್ಯಾನಿಸು CB_FINDSTRINGEXACT 0x0158
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SETLOCALE 0x0159
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETLOCALE 0x015A
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETTOPINDEX 0x015b
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SETTOPINDEX 0x015c
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETHORIZONTALEXTENT 0x015d
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SETHORIZONTALEXTENT 0x015e
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETDROPPEDWIDTH 0x015f
#ವ್ಯಾಖ್ಯಾನಿಸು CB_SETDROPPEDWIDTH 0x0160
#ವ್ಯಾಖ್ಯಾನಿಸು CB_INITSTORAGE 0x0161
#ಆದರೆ(_WIN32_WCE >= 0x0400)
#ವ್ಯಾಖ್ಯಾನಿಸು CB_MULTIPLEADDSTRING 0x0163
#ಆದರೆ_ಅಂತ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು CB_GETCOMBOBOXINFO 0x0164
#ವ್ಯಾಖ್ಯಾನಿಸು CB_MSGMAX 0x0165
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINSTYLES

#ವ್ಯಾಖ್ಯಾನಿಸು SBS_HORZ 0x0000L
#ವ್ಯಾಖ್ಯಾನಿಸು SBS_VERT 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು SBS_TOPALIGN 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು SBS_LEFTALIGN 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು SBS_BOTTOMALIGN 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು SBS_RIGHTALIGN 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು SBS_SIZEBOXTOPLEFTALIGN 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು SBS_SIZEBOX 0x0008L
#ವ್ಯಾಖ್ಯಾನಿಸು SBS_SIZEGRIP 0x0010L
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINMESSAGES
#ವ್ಯಾಖ್ಯಾನಿಸು SBM_SETPOS 0x00E0
#ವ್ಯಾಖ್ಯಾನಿಸು SBM_GETPOS 0x00E1
#ವ್ಯಾಖ್ಯಾನಿಸು SBM_SETRANGE 0x00E2
#ವ್ಯಾಖ್ಯಾನಿಸು SBM_SETRANGEREDRAW 0x00E6
#ವ್ಯಾಖ್ಯಾನಿಸು SBM_GETRANGE 0x00E3
#ವ್ಯಾಖ್ಯಾನಿಸು SBM_ENABLE_ARROWS 0x00E4
#ವ್ಯಾಖ್ಯಾನಿಸು SBM_SETSCROLLINFO 0x00E9
#ವ್ಯಾಖ್ಯಾನಿಸು SBM_GETSCROLLINFO 0x00EA
#ವ್ಯಾಖ್ಯಾನಿಸು SBM_GETSCROLLBARINFO 0x00EB

#ವ್ಯಾಖ್ಯಾನಿಸು SIF_RANGE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು SIF_ಪುಟ 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು SIF_POS 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು SIF_DISABLENOSCROLL 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು SIF_TRACKPOS 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು SIF_ALL (SIF_RANGE | SIF_ಪುಟ | SIF_POS | SIF_TRACKPOS)

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_SCROLLINFO {
    UINT cb_ಗಾತ್ರ;
    UINT f_ಮುಖವಾಡ;
    ಪೂರ್ಣಾಂಕ nMin;
    ಪೂರ್ಣಾಂಕ nMax;
    UINT n_ಪುಟ;
    ಪೂರ್ಣಾಂಕ nPos;
    ಪೂರ್ಣಾಂಕ nTrackPos;
  } SCROLLINFO,*LPSCROLLINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SCROLLINFO CONST *LPCSCROLLINFO;

  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Scroll_Info(HWND hwnd,ಪೂರ್ಣಾಂಕ nBar,LPCSCROLLINFO lpsi,WINBOOL redraw);
  WINUSERAPI WINBOOL WINAPI GetScrollInfo(HWND hwnd,ಪೂರ್ಣಾಂಕ nBar,LPSCROLLINFO lpsi);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMDI

#ವ್ಯಾಖ್ಯಾನಿಸು MDIS_ALLCHILDSTYLES 0x0001

#ವ್ಯಾಖ್ಯಾನಿಸು MDITILE_VERTICAL 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು MDITILE_HORIZONTAL 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು MDITILE_SKIPDISABLED 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು MDITILE_ZORDER 0x0004

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MDICREATESTRUCTA {
    LPCSTR szClass;
    LPCSTR szTitle;
    HANDLE hOwner;
    ಪೂರ್ಣಾಂಕ x;
    ಪೂರ್ಣಾಂಕ y;
    ಪೂರ್ಣಾಂಕ cx;
    ಪೂರ್ಣಾಂಕ cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTA,*LPMDICREATESTRUCTA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MDICREATESTRUCTW {
    LPCWSTR szClass;
    LPCWSTR szTitle;
    HANDLE hOwner;
    ಪೂರ್ಣಾಂಕ x;
    ಪೂರ್ಣಾಂಕ y;
    ಪೂರ್ಣಾಂಕ cx;
    ಪೂರ್ಣಾಂಕ cy;
    DWORD style;
    LPARAM lParam;
  } MDICREATESTRUCTW,*LPMDICREATESTRUCTW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MDICREATESTRUCTW MDICREATESTRUCT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMDICREATESTRUCTW LPMDICREATESTRUCT;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MDICREATESTRUCTA MDICREATESTRUCT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMDICREATESTRUCTA LPMDICREATESTRUCT;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CLIENTCREATESTRUCT {
    HANDLE h_ಕಿಟಕಿ_Menu;
    UINT id_ಮೊದಲ_ಮಗು;
  } CLIENTCREATESTRUCT,*LPCLIENTCREATESTRUCT;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Def_ಚೌಕಟ್ಟು_Proc Def_ಚೌಕಟ್ಟು_Proc_W
#ವ್ಯಾಖ್ಯಾನಿಸು DefMDIChildProc DefMDIChildProcW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateMDIWindow CreateMDIWindowW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Def_ಚೌಕಟ್ಟು_Proc Def_ಚೌಕಟ್ಟು_Proc_A
#ವ್ಯಾಖ್ಯಾನಿಸು DefMDIChildProc DefMDIChildProcA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateMDIWindow CreateMDIWindowA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI LRESULT WINAPI Def_ಚೌಕಟ್ಟು_Proc_A(HWND hWnd,HWND hWndMDIClient,UINT u_ಸಂದೇಶ,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI Def_ಚೌಕಟ್ಟು_Proc_W(HWND hWnd,HWND hWndMDIClient,UINT u_ಸಂದೇಶ,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcA(HWND hWnd,UINT u_ಸಂದೇಶ,WPARAM wParam,LPARAM lParam);
  WINUSERAPI LRESULT WINAPI DefMDIChildProcW(HWND hWnd,UINT u_ಸಂದೇಶ,WPARAM wParam,LPARAM lParam);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMSG
  WINUSERAPI WINBOOL WINAPI TranslateMDISysAccel(HWND hWndClient,LPMSG lp_ಸಂದೇಶ_2);
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI UINT WINAPI ArrangeIconicWindows(HWND hWnd);
  WINUSERAPI HWND WINAPI CreateMDIWindowA(LPCSTR lpClassName,LPCSTR lp_ಕಿಟಕಿ_Name,DWORD dwStyle,ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ,HWND h_Wnd_ಪೋಷಕ,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI HWND WINAPI CreateMDIWindowW(LPCWSTR lpClassName,LPCWSTR lp_ಕಿಟಕಿ_Name,DWORD dwStyle,ಪೂರ್ಣಾಂಕ X,ಪೂರ್ಣಾಂಕ Y,ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ,HWND h_Wnd_ಪೋಷಕ,HINSTANCE hInstance,LPARAM lParam);
  WINUSERAPI ಶಬ್ದ_3 WINAPI TileWindows(HWND hwnd_ಪೋಷಕ_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ಸ್ಥಿರಾಂಕ HWND *lpKids);
  WINUSERAPI ಶಬ್ದ_3 WINAPI CascadeWindows(HWND hwnd_ಪೋಷಕ_2,UINT wHow,CONST RECT *lpRect,UINT cKids,ಸ್ಥಿರಾಂಕ HWND *lpKids);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOHELP

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD HELPPOLY;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MULTIKEYHELPA {
    DWORD mk_ಗಾತ್ರ;
    CHAR mkKeylist;
    CHAR szKeyphrase[1];
  } MULTIKEYHELPA,*PMULTIKEYHELPA,*LPMULTIKEYHELPA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MULTIKEYHELPW {
    DWORD mk_ಗಾತ್ರ;
    WCHAR mkKeylist;
    WCHAR szKeyphrase[1];
  } MULTIKEYHELPW,*PMULTIKEYHELPW,*LPMULTIKEYHELPW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MULTIKEYHELPW MULTIKEYHELP;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PMULTIKEYHELPW PMULTIKEYHELP;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMULTIKEYHELPW LPMULTIKEYHELP;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MULTIKEYHELPA MULTIKEYHELP;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PMULTIKEYHELPA PMULTIKEYHELP;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMULTIKEYHELPA LPMULTIKEYHELP;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HELPWININFOA {
    ಪೂರ್ಣಾಂಕ w_Struct_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ x;
    ಪೂರ್ಣಾಂಕ y;
    ಪೂರ್ಣಾಂಕ dx;
    ಪೂರ್ಣಾಂಕ dy;
    ಪೂರ್ಣಾಂಕ wMax;
    CHAR rgchMember[2];
  } HELPWININFOA,*PHELPWININFOA,*LPHELPWININFOA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HELPWININFOW {
    ಪೂರ್ಣಾಂಕ w_Struct_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ x;
    ಪೂರ್ಣಾಂಕ y;
    ಪೂರ್ಣಾಂಕ dx;
    ಪೂರ್ಣಾಂಕ dy;
    ಪೂರ್ಣಾಂಕ wMax;
    WCHAR rgchMember[2];
  } HELPWININFOW,*PHELPWININFOW,*LPHELPWININFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HELPWININFOW HELPWININFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PHELPWININFOW PHELPWININFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPHELPWININFOW LPHELPWININFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HELPWININFOA HELPWININFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PHELPWININFOA PHELPWININFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPHELPWININFOA LPHELPWININFO;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು HELP_CONTEXT 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_QUIT 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_ಸೂಚ್ಯಂಕ 0x0003L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_CONTENTS 0x0003L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_HELPONHELP 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_SETINDEX 0x0005L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_SETCONTENTS 0x0005L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_CONTEXTPOPUP 0x0008L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_FORCEFILE 0x0009L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_ಕೀಲಿ 0x0101L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_COMMAND 0x0102L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_PARTIALKEY 0x0105L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_MULTIKEY 0x0201L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_SETWINPOS 0x0203L
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_CONTEXTMENU 0x000a
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_FINDER 0x000b
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_WM_HELP 0x000c
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_SETPOPUP_POS 0x000d

#ವ್ಯಾಖ್ಯಾನಿಸು HELP_TCARD 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_TCARD_ದತ್ತಾಂಶ 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು HELP_TCARD_OTHER_CALLER 0x0011

#ವ್ಯಾಖ್ಯಾನಿಸು IDH_NO_HELP 28440
#ವ್ಯಾಖ್ಯಾನಿಸು IDH_MISSING_CONTEXT 28441
#ವ್ಯಾಖ್ಯಾನಿಸು IDH_GENERIC_HELP_BUTTON 28442
#ವ್ಯಾಖ್ಯಾನಿಸು IDH_OK 28443
#ವ್ಯಾಖ್ಯಾನಿಸು IDH_CANCEL 28444
#ವ್ಯಾಖ್ಯಾನಿಸು IDH_HELP 28445

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು WinHelp WinHelpW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು WinHelp WinHelpA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI WinHelpA(HWND hWndMain,LPCSTR lpszHelp,UINT uCommand,ULONG_PTR dw_ದತ್ತಾಂಶ);
  WINUSERAPI WINBOOL WINAPI WinHelpW(HWND hWndMain,LPCWSTR lpszHelp,UINT uCommand,ULONG_PTR dw_ದತ್ತಾಂಶ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು GR_GDIOBJECTS 0
#ವ್ಯಾಖ್ಯಾನಿಸು GR_USEROBJECTS 1

  WINUSERAPI DWORD WINAPI GetGuiResources(HANDLE hProcess,DWORD uiFlags);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOSYSPARAMSINFO

#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETBEEP 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETBEEP 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSE 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSE 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETBORDER 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETBORDER 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETKEYBOARDSPEED 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETKEYBOARDSPEED 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_LANGDRIVER 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_ICONHORIZONTALSPACING 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSCREENSAVETIMEOUT 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSCREENSAVETIMEOUT 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSCREENSAVEACTIVE 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSCREENSAVEACTIVE 0x0011
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETGRIDGRANULARITY 0x0012
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETGRIDGRANULARITY 0x0013
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDESKWALLPAPER 0x0014
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDESKPATTERN 0x0015
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETKEYBOARDDELAY 0x0016
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETKEYBOARDDELAY 0x0017
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_ICONVERTICALSPACING 0x0018
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETICONTITLEWRAP 0x0019
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETICONTITLEWRAP 0x001A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMENUDROPALIGNMENT 0x001B
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMENUDROPALIGNMENT 0x001C
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDOUBLECLKWIDTH 0x001D
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDOUBLECLKHEIGHT 0x001E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETICONTITLELOGFONT 0x001F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDOUBLECLICKTIME 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSEBUTTONSWAP 0x0021
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETICONTITLELOGFONT 0x0022
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFASTTASKSWITCH 0x0023
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFASTTASKSWITCH 0x0024
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDRAGFULLWINDOWS 0x0025
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETDRAGFULLWINDOWS 0x0026
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETNONCLIENTMETRICS 0x0029
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETNONCLIENTMETRICS 0x002A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMINIMIZEDMETRICS 0x002B
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMINIMIZEDMETRICS 0x002C
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETICONMETRICS 0x002D
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETICONMETRICS 0x002E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETWORKAREA 0x002F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETWORKAREA 0x0030
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETPENWINDOWS 0x0031

#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETHIGHCONTRAST 0x0042
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETHIGHCONTRAST 0x0043
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETKEYBOARDPREF 0x0044
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETKEYBOARDPREF 0x0045
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSCREENREADER 0x0046
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSCREENREADER 0x0047
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETANIMATION 0x0048
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETANIMATION 0x0049
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFONTSMOOTHING 0x004A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFONTSMOOTHING 0x004B
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDRAGWIDTH 0x004C
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDRAGHEIGHT 0x004D
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETHANDHELD 0x004E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETLOWPOWERTIMEOUT 0x004F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETPOWEROFFTIMEOUT 0x0050
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETLOWPOWERTIMEOUT 0x0051
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETPOWEROFFTIMEOUT 0x0052
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETLOWPOWERACTIVE 0x0053
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETPOWEROFFACTIVE 0x0054
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETLOWPOWERACTIVE 0x0055
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETPOWEROFFACTIVE 0x0056
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETCURSORS 0x0057
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETICONS 0x0058
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETDEFAULTINPUTLANG 0x0059
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDEFAULTINPUTLANG 0x005A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETLANGTOGGLE 0x005B
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETWINDOWSEXTENSION 0x005C
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSETRAILS 0x005D
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSETRAILS 0x005E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSCREENSAVERRUNNING 0x0061
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SCREENSAVERRUNNING SPI_SETSCREENSAVERRUNNING
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFILTERKEYS 0x0032
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFILTERKEYS 0x0033
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETTOGGLEKEYS 0x0034
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETTOGGLEKEYS 0x0035
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSEKEYS 0x0036
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSEKEYS 0x0037
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSHOWSOUNDS 0x0038
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSHOWSOUNDS 0x0039
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSTICKYKEYS 0x003A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSTICKYKEYS 0x003B
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETACCESSTIMEOUT 0x003C
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETACCESSTIMEOUT 0x003D
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSERIALKEYS 0x003E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSERIALKEYS 0x003F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSOUNDSENTRY 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSOUNDSENTRY 0x0041
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSNAPTODEFBUTTON 0x005F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSNAPTODEFBUTTON 0x0060
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSEHOVERWIDTH 0x0062
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSEHOVERWIDTH 0x0063
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSEHOVERHEIGHT 0x0064
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSEHOVERHEIGHT 0x0065
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSEHOVERTIME 0x0066
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSEHOVERTIME 0x0067
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETWHEELSCROLLLINES 0x0068
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETWHEELSCROLLLINES 0x0069
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMENUSHOWDELAY 0x006A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMENUSHOWDELAY 0x006B
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSHOWIMEUI 0x006E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSHOWIMEUI 0x006F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSESPEED 0x0070
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSESPEED 0x0071
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSCREENSAVERRUNNING 0x0072
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETDESKWALLPAPER 0x0073

#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETACTIVEWINDOWTRACKING 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETACTIVEWINDOWTRACKING 0x1001
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMENUANIMATION 0x1002
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMENUANIMATION 0x1003
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETCOMBOBOXANIMATION 0x1004
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETCOMBOBOXANIMATION 0x1005
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETLISTBOXSMOOTHSCROLLING 0x1006
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETLISTBOXSMOOTHSCROLLING 0x1007
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETGRADIENTCAPTIONS 0x1008
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETGRADIENTCAPTIONS 0x1009
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETKEYBOARDCUES 0x100A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETKEYBOARDCUES 0x100B
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMENUUNDERLINES SPI_GETKEYBOARDCUES
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMENUUNDERLINES SPI_SETKEYBOARDCUES
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETACTIVEWNDTRKZORDER 0x100C
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETACTIVEWNDTRKZORDER 0x100D
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETHOTTRACKING 0x100E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETHOTTRACKING 0x100F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMENUFADE 0x1012
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMENUFADE 0x1013
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETSELECTIONFADE 0x1014
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETSELECTIONFADE 0x1015
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETTOOLTIPANIMATION 0x1016
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETTOOLTIPANIMATION 0x1017
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETTOOLTIPFADE 0x1018
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETTOOLTIPFADE 0x1019
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETCURSORSHADOW 0x101A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETCURSORSHADOW 0x101B
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSESONAR 0x101C
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSESONAR 0x101D
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSECLICKLOCK 0x101E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSECLICKLOCK 0x101F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSEVANISH 0x1020
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSEVANISH 0x1021
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFLATMENU 0x1022
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFLATMENU 0x1023
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETDROPSHADOW 0x1024
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETDROPSHADOW 0x1025
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETBLOCKSENDINPUTRESETS 0x1026
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETBLOCKSENDINPUTRESETS 0x1027
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETUIEFFECTS 0x103E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETUIEFFECTS 0x103F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFOREGROUNDLOCKTIMEOUT 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFOREGROUNDLOCKTIMEOUT 0x2001
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETACTIVEWNDTRKTIMEOUT 0x2002
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETACTIVEWNDTRKTIMEOUT 0x2003
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFOREGROUNDFLASHCOUNT 0x2004
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFOREGROUNDFLASHCOUNT 0x2005
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETCARETWIDTH 0x2006
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETCARETWIDTH 0x2007
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETMOUSECLICKLOCKTIME 0x2008
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETMOUSECLICKLOCKTIME 0x2009
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFONTSMOOTHINGTYPE 0x200A
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFONTSMOOTHINGTYPE 0x200B

#ವ್ಯಾಖ್ಯಾನಿಸು FE_FONTSMOOTHINGSTANDARD 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು FE_FONTSMOOTHINGCLEARTYPE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು FE_FONTSMOOTHINGDOCKING 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFONTSMOOTHINGCONTRAST 0x200C
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFONTSMOOTHINGCONTRAST 0x200D
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFOCUSBORDERWIDTH 0x200E
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFOCUSBORDERWIDTH 0x200F
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFOCUSBORDERHEIGHT 0x2010
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFOCUSBORDERHEIGHT 0x2011
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_GETFONTSMOOTHINGORIENTATION 0x2012
#ವ್ಯಾಖ್ಯಾನಿಸು SPI_SETFONTSMOOTHINGORIENTATION 0x2013

#ವ್ಯಾಖ್ಯಾನಿಸು FE_FONTSMOOTHINGORIENTATIONBGR 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು FE_FONTSMOOTHINGORIENTATIONRGB 0x0001

#ವ್ಯಾಖ್ಯಾನಿಸು SPIF_UPDATEINIFILE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು SPIF_SENDWININICHANGE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು SPIF_SENDCHANGE SPIF_SENDWININICHANGE

#ವ್ಯಾಖ್ಯಾನಿಸು METRICS_USEDEFAULT -1
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WINGDI_
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOGDI
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_NONCLIENTMETRICSA {
    UINT cb_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ i_Border_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Scroll_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Scroll_ಎತ್ತರ;
    ಪೂರ್ಣಾಂಕ i_Caption_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Caption_ಎತ್ತರ;
    LOGFONTA lfCaptionFont;
    ಪೂರ್ಣಾಂಕ i_Sm_Caption_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Sm_Caption_ಎತ್ತರ;
    LOGFONTA lfSmCaptionFont;
    ಪೂರ್ಣಾಂಕ i_Menu_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Menu_ಎತ್ತರ;
    LOGFONTA lfMenuFont;
    LOGFONTA lf_ಸ್ಥಿತಿ_Font;
    LOGFONTA lf_ಸಂದೇಶ_Font;
  } NONCLIENTMETRICSA,*PNONCLIENTMETRICSA,*LPNONCLIENTMETRICSA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_NONCLIENTMETRICSW {
    UINT cb_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ i_Border_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Scroll_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Scroll_ಎತ್ತರ;
    ಪೂರ್ಣಾಂಕ i_Caption_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Caption_ಎತ್ತರ;
    LOGFONTW lfCaptionFont;
    ಪೂರ್ಣಾಂಕ i_Sm_Caption_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Sm_Caption_ಎತ್ತರ;
    LOGFONTW lfSmCaptionFont;
    ಪೂರ್ಣಾಂಕ i_Menu_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ i_Menu_ಎತ್ತರ;
    LOGFONTW lfMenuFont;
    LOGFONTW lf_ಸ್ಥಿತಿ_Font;
    LOGFONTW lf_ಸಂದೇಶ_Font;
  } NONCLIENTMETRICSW,*PNONCLIENTMETRICSW,*LPNONCLIENTMETRICSW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NONCLIENTMETRICSW NONCLIENTMETRICS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PNONCLIENTMETRICSW PNONCLIENTMETRICS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPNONCLIENTMETRICSW LPNONCLIENTMETRICS;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NONCLIENTMETRICSA NONCLIENTMETRICS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PNONCLIENTMETRICSA PNONCLIENTMETRICS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPNONCLIENTMETRICSA LPNONCLIENTMETRICS;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ARW_BOTTOMLEFT 0x0000L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_BOTTOMRIGHT 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_TOPLEFT 0x0002L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_TOPRIGHT 0x0003L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_STARTMASK 0x0003L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_STARTRIGHT 0x0001L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_STARTTOP 0x0002L

#ವ್ಯಾಖ್ಯಾನಿಸು ARW_ಎಡ 0x0000L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_ಬಲ 0x0000L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_ಮೇಲೆ 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_ಕೆಳಕ್ಕೆ 0x0004L
#ವ್ಯಾಖ್ಯಾನಿಸು ARW_HIDE 0x0008L

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MINIMIZEDMETRICS {
    UINT cb_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ i_ಅಗಲ;
    ಪೂರ್ಣಾಂಕ iHorzGap;
    ಪೂರ್ಣಾಂಕ iVertGap;
    ಪೂರ್ಣಾಂಕ iArrange;
  } MINIMIZEDMETRICS,*PMINIMIZEDMETRICS,*LPMINIMIZEDMETRICS;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WINGDI_
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOGDI
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ICONMETRICSA {
    UINT cb_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ iHorzSpacing;
    ಪೂರ್ಣಾಂಕ iVertSpacing;
    ಪೂರ್ಣಾಂಕ iTitleWrap;
    LOGFONTA lfFont;
  } ICONMETRICSA,*PICONMETRICSA,*LPICONMETRICSA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ICONMETRICSW {
    UINT cb_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ iHorzSpacing;
    ಪೂರ್ಣಾಂಕ iVertSpacing;
    ಪೂರ್ಣಾಂಕ iTitleWrap;
    LOGFONTW lfFont;
  } ICONMETRICSW,*PICONMETRICSW,*LPICONMETRICSW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ICONMETRICSW ICONMETRICS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PICONMETRICSW PICONMETRICS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPICONMETRICSW LPICONMETRICS;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ICONMETRICSA ICONMETRICS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PICONMETRICSA PICONMETRICS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPICONMETRICSA LPICONMETRICS;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ANIMATIONINFO {
    UINT cb_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ iMinAnimate;
  } ANIMATIONINFO,*LPANIMATIONINFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_SERIALKEYSA {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
    LPSTR lpsz_ಸಕ್ರಿಯ_ಪೋರ್ಟ್;
    LPSTR lpsz_ಪೋರ್ಟ್;
    UINT i_Baud_ದರ;
    UINT i_ಪೋರ್ಟ್_State;
    UINT i_ಸಕ್ರಿಯ;
  } SERIALKEYSA,*LPSERIALKEYSA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_SERIALKEYSW {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
    LPWSTR lpsz_ಸಕ್ರಿಯ_ಪೋರ್ಟ್;
    LPWSTR lpsz_ಪೋರ್ಟ್;
    UINT i_Baud_ದರ;
    UINT i_ಪೋರ್ಟ್_State;
    UINT i_ಸಕ್ರಿಯ;
  } SERIALKEYSW,*LPSERIALKEYSW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SERIALKEYSW SERIALKEYS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPSERIALKEYSW LPSERIALKEYS;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SERIALKEYSA SERIALKEYS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPSERIALKEYSA LPSERIALKEYS;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು SERKF_SERIALKEYSON 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು SERKF_ಲಭ್ಯ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು SERKF_INDICATOR 0x00000004

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HIGHCONTRASTA {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
    LPSTR lpszDefaultScheme;
  } HIGHCONTRASTA,*LPHIGHCONTRASTA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HIGHCONTRASTW {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
    LPWSTR lpszDefaultScheme;
  } HIGHCONTRASTW,*LPHIGHCONTRASTW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HIGHCONTRASTW HIGHCONTRAST;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPHIGHCONTRASTW LPHIGHCONTRAST;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ HIGHCONTRASTA HIGHCONTRAST;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPHIGHCONTRASTA LPHIGHCONTRAST;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು HCF_HIGHCONTRASTON 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು HCF_ಲಭ್ಯ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು HCF_HOTKEYACTIVE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು HCF_CONFIRMHOTKEY 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು HCF_HOTKEYSOUND 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು HCF_INDICATOR 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು HCF_HOTKEYAVAILABLE 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು HCF_LOGONDESKTOP 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು HCF_DEFAULTDESKTOP 0x00000200

#ವ್ಯಾಖ್ಯಾನಿಸು CDS_UPDATEREGISTRY 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು CDS_TEST 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು CDS_FULLSCREEN 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು CDS_GLOBAL 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು CDS_ಗಣ_PRIMARY 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು CDS_VIDEOPARAMETERS 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು CDS_RESET 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು CDS_NORESET 0x10000000

//gr #include <tvout.h>

#ವ್ಯಾಖ್ಯಾನಿಸು DISP_CHANGE_SUCCESSFUL 0
#ವ್ಯಾಖ್ಯಾನಿಸು DISP_CHANGE_RESTART 1
#ವ್ಯಾಖ್ಯಾನಿಸು DISP_CHANGE_FAILED -1
#ವ್ಯಾಖ್ಯಾನಿಸು DISP_CHANGE_BADMODE -2
#ವ್ಯಾಖ್ಯಾನಿಸು DISP_CHANGE_NOTUPDATED -3
#ವ್ಯಾಖ್ಯಾನಿಸು DISP_CHANGE_BADFLAGS -4
#ವ್ಯಾಖ್ಯಾನಿಸು DISP_CHANGE_BADPARAM -5
#ವ್ಯಾಖ್ಯಾನಿಸು DISP_CHANGE_BADDUALVIEW -6

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WINGDI_
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOGDI

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ChangeDisplaySettings ChangeDisplaySettingsW
#ವ್ಯಾಖ್ಯಾನಿಸು ChangeDisplaySettingsEx ChangeDisplaySettingsExW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumDisplaySettings EnumDisplaySettingsW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumDisplaySettingsEx EnumDisplaySettingsExW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumDisplayDevices EnumDisplayDevicesW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ChangeDisplaySettings ChangeDisplaySettingsA
#ವ್ಯಾಖ್ಯಾನಿಸು ChangeDisplaySettingsEx ChangeDisplaySettingsExA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumDisplaySettings EnumDisplaySettingsA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumDisplaySettingsEx EnumDisplaySettingsExA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumDisplayDevices EnumDisplayDevicesA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI LONG WINAPI ChangeDisplaySettingsA(LPDEVMODEA lp_Dev_ಬಹುಲಕ,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsW(LPDEVMODEW lp_Dev_ಬಹುಲಕ,DWORD dwFlags);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExA(LPCSTR lpszDeviceName,LPDEVMODEA lp_Dev_ಬಹುಲಕ,HWND hwnd,DWORD dwflags,LPVOID lParam);
  WINUSERAPI LONG WINAPI ChangeDisplaySettingsExW(LPCWSTR lpszDeviceName,LPDEVMODEW lp_Dev_ಬಹುಲಕ,HWND hwnd,DWORD dwflags,LPVOID lParam);

#ವ್ಯಾಖ್ಯಾನಿಸು ENUM_CURRENT_SETTINGS ((DWORD)-1)
#ವ್ಯಾಖ್ಯಾನಿಸು ENUM_REGISTRY_SETTINGS ((DWORD)-2)

  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsA(LPCSTR lpszDeviceName,DWORD i_ಬಹುಲಕ_ಅಂಕೆ,LPDEVMODEA lp_Dev_ಬಹುಲಕ);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsW(LPCWSTR lpszDeviceName,DWORD i_ಬಹುಲಕ_ಅಂಕೆ,LPDEVMODEW lp_Dev_ಬಹುಲಕ);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExA(LPCSTR lpszDeviceName,DWORD i_ಬಹುಲಕ_ಅಂಕೆ,LPDEVMODEA lp_Dev_ಬಹುಲಕ,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplaySettingsExW(LPCWSTR lpszDeviceName,DWORD i_ಬಹುಲಕ_ಅಂಕೆ,LPDEVMODEW lp_Dev_ಬಹುಲಕ,DWORD dwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು EDS_RAWMODE 0x00000002

  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesA(LPCSTR lpDevice,DWORD i_Dev_ಅಂಕೆ,PDISPLAY_DEVICEA lpDisplayDevice,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI EnumDisplayDevicesW(LPCWSTR lpDevice,DWORD i_Dev_ಅಂಕೆ,PDISPLAY_DEVICEW lpDisplayDevice,DWORD dwFlags);
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು SystemParametersInfo SystemParametersInfoW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು SystemParametersInfo SystemParametersInfoA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI SystemParametersInfoA(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
  WINUSERAPI WINBOOL WINAPI SystemParametersInfoW(UINT uiAction,UINT uiParam,PVOID pvParam,UINT fWinIni);
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_FILTERKEYS {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
    DWORD iWaitMSec;
    DWORD iDelayMSec;
    DWORD iRepeatMSec;
    DWORD iBounceMSec;
  } FILTERKEYS,*LPFILTERKEYS;

#ವ್ಯಾಖ್ಯಾನಿಸು FKF_FILTERKEYSON 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು FKF_ಲಭ್ಯ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು FKF_HOTKEYACTIVE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು FKF_CONFIRMHOTKEY 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು FKF_HOTKEYSOUND 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು FKF_INDICATOR 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು FKF_CLICKON 0x00000040

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_STICKYKEYS {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
  } STICKYKEYS,*LPSTICKYKEYS;

#ವ್ಯಾಖ್ಯಾನಿಸು SKF_STICKYKEYSON 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_ಲಭ್ಯ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_HOTKEYACTIVE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_CONFIRMHOTKEY 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_HOTKEYSOUND 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_INDICATOR 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_AUDIBLEFEEDBACK 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_TRISTATE 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_TWOKEYSOFF 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_LALTLATCHED 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_LCTLLATCHED 0x04000000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_LSHIFTLATCHED 0x01000000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_RALTLATCHED 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_RCTLLATCHED 0x08000000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_RSHIFTLATCHED 0x02000000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_LWINLATCHED 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_RWINLATCHED 0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_LALTLOCKED 0x00100000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_LCTLLOCKED 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_LSHIFTLOCKED 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_RALTLOCKED 0x00200000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_RCTLLOCKED 0x00080000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_RSHIFTLOCKED 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_LWINLOCKED 0x00400000
#ವ್ಯಾಖ್ಯಾನಿಸು SKF_RWINLOCKED 0x00800000

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MOUSEKEYS {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
    DWORD i_Max_ವೇಗ;
    DWORD i_ಸಮಯ_ಗಮ್ಯ_Max_ವೇಗ;
    DWORD i_Ctrl_ವೇಗ;
    DWORD dwReserved1;
    DWORD dwReserved2;
  } MOUSEKEYS,*LPMOUSEKEYS;

#ವ್ಯಾಖ್ಯಾನಿಸು MKF_MOUSEKEYSON 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_ಲಭ್ಯ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_HOTKEYACTIVE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_CONFIRMHOTKEY 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_HOTKEYSOUND 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_INDICATOR 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_MODIFIERS 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_REPLACENUMBERS 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_LEFTBUTTONSEL 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_RIGHTBUTTONSEL 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_LEFTBUTTONDOWN 0x01000000
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_RIGHTBUTTONDOWN 0x02000000
#ವ್ಯಾಖ್ಯಾನಿಸು MKF_MOUSEMODE 0x80000000

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ACCESSTIMEOUT {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
    DWORD i_ಸಮಯ_ಹೊರಹೋಗು_MSec;
  } ACCESSTIMEOUT,*LPACCESSTIMEOUT;

#ವ್ಯಾಖ್ಯಾನಿಸು ATF_TIMEOUTON 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು ATF_ONOFFFEEDBACK 0x00000002

#ವ್ಯಾಖ್ಯಾನಿಸು SSGF_NONE 0
#ವ್ಯಾಖ್ಯಾನಿಸು SSGF_DISPLAY 3

#ವ್ಯಾಖ್ಯಾನಿಸು SSTF_NONE 0
#ವ್ಯಾಖ್ಯಾನಿಸು SSTF_CHARS 1
#ವ್ಯಾಖ್ಯಾನಿಸು SSTF_BORDER 2
#ವ್ಯಾಖ್ಯಾನಿಸು SSTF_DISPLAY 3

#ವ್ಯಾಖ್ಯಾನಿಸು SSWF_NONE 0
#ವ್ಯಾಖ್ಯಾನಿಸು SSWF_TITLE 1
#ವ್ಯಾಖ್ಯಾನಿಸು SSWF_ಕಿಟಕಿ 2
#ವ್ಯಾಖ್ಯಾನಿಸು SSWF_DISPLAY 3
#ವ್ಯಾಖ್ಯಾನಿಸು SSWF_CUSTOM 4

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_SOUNDSENTRYA {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_ಬಿಟ್ಟುಗಳು;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYA,*LPSOUNDSENTRYA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_SOUNDSENTRYW {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
    DWORD iFSTextEffect;
    DWORD iFSTextEffectMSec;
    DWORD i_FSText_Effect_Color_ಬಿಟ್ಟುಗಳು;
    DWORD iFSGrafEffect;
    DWORD iFSGrafEffectMSec;
    DWORD iFSGrafEffectColor;
    DWORD iWindowsEffect;
    DWORD iWindowsEffectMSec;
    LPWSTR lpszWindowsEffectDLL;
    DWORD iWindowsEffectOrdinal;
  } SOUNDSENTRYW,*LPSOUNDSENTRYW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SOUNDSENTRYW SOUNDSENTRY;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPSOUNDSENTRYW LPSOUNDSENTRY;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ SOUNDSENTRYA SOUNDSENTRY;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPSOUNDSENTRYA LPSOUNDSENTRY;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು SSF_SOUNDSENTRYON 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು SSF_ಲಭ್ಯ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು SSF_INDICATOR 0x00000004

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_TOGGLEKEYS {
    UINT cb_ಗಾತ್ರ;
    DWORD dwFlags;
  } TOGGLEKEYS,*LPTOGGLEKEYS;

#ವ್ಯಾಖ್ಯಾನಿಸು TKF_TOGGLEKEYSON 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು TKF_ಲಭ್ಯ 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು TKF_HOTKEYACTIVE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು TKF_CONFIRMHOTKEY 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು TKF_HOTKEYSOUND 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು TKF_INDICATOR 0x00000020

  WINUSERAPI VOID WINAPI ಗಣ_Debug_Error_Level(DWORD dwLevel);

#ವ್ಯಾಖ್ಯಾನಿಸು SLE_ERROR 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು SLE_MINORERROR 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು SLE_WARNING 0x00000003

  WINUSERAPI VOID WINAPI ಗಣ_ಕೊನೆಯ_Error_Ex(DWORD dw_Err_ಸಂಕೇತ,DWORD dwType);
  WINUSERAPI ಪೂರ್ಣಾಂಕ WINAPI ಆಂತರಿಕ_Get_ಕಿಟಕಿ_ಪಠ್ಯ(HWND hWnd,LPWSTR pString,ಪೂರ್ಣಾಂಕ cch_Max_ಎಣಿಕೆ);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ WINNT
  WINUSERAPI WINBOOL WINAPI ಕೊನೆ_Task(HWND hWnd,WINBOOL f_Shut_ಕೆಳಕ್ಕೆ,WINBOOL fForce);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು MONITOR_DEFAULTTONULL 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು MONITOR_DEFAULTTOPRIMARY 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು MONITOR_DEFAULTTONEAREST 0x00000002

  WINUSERAPI HMONITOR WINAPI Monitor_From_ಬಿಂದು(ಬಿಂದು_3 pt,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI MonitorFromRect(LPCRECT lprc,DWORD dwFlags);
  WINUSERAPI HMONITOR WINAPI Monitor_From_ಕಿಟಕಿ(HWND hwnd,DWORD dwFlags);

#ವ್ಯಾಖ್ಯಾನಿಸು MONITORINFOF_PRIMARY 0x00000001

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ CCHDEVICENAME
#ವ್ಯಾಖ್ಯಾನಿಸು CCHDEVICENAME 32
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MONITORINFO {
    DWORD cb_ಗಾತ್ರ;
    RECT rcMonitor;
    RECT rcWork;
    DWORD dwFlags;
  } MONITORINFO,*LPMONITORINFO;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MONITORINFOEXA : ಸಾರ್ವಜನಿಕ ಟ್ಯಾಗ್_MONITORINFO {
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MONITORINFOEXW : ಸಾರ್ವಜನಿಕ ಟ್ಯಾಗ್_MONITORINFO {
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MONITORINFOEXW MONITORINFOEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMONITORINFOEXW LPMONITORINFOEX;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MONITORINFOEXA MONITORINFOEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMONITORINFOEXA LPMONITORINFOEX;
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MONITORINFOEXA {
    MONITORINFO mi;
    CHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXA,*LPMONITORINFOEXA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MONITORINFOEXW {
    MONITORINFO mi;
    WCHAR szDevice[CCHDEVICENAME];
  } MONITORINFOEXW,*LPMONITORINFOEXW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MONITORINFOEXW MONITORINFOEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMONITORINFOEXW LPMONITORINFOEX;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ MONITORINFOEXA MONITORINFOEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPMONITORINFOEXA LPMONITORINFOEX;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE 
#ವ್ಯಾಖ್ಯಾನಿಸು GetMonitorInfo GetMonitorInfoW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetMonitorInfo GetMonitorInfoA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI GetMonitorInfoA(HMONITOR hMonitor,LPMONITORINFO lpmi);
  WINUSERAPI WINBOOL WINAPI GetMonitorInfoW(HMONITOR hMonitor,LPMONITORINFO lpmi);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *MONITORENUMPROC)(HMONITOR,HDC,LPRECT,LPARAM);

  WINUSERAPI WINBOOL WINAPI EnumDisplayMonitors(HDC hdc,LPCRECT lprcClip,MONITORENUMPROC lpfnEnum,LPARAM dw_ದತ್ತಾಂಶ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOWINABLE
  WINUSERAPI VOID WINAPI NotifyWinEvent(DWORD event,HWND hwnd,LONG idObject,LONG id_ಮಗು);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (CALLBACK *WINEVENTPROC)(HWINEVENTHOOK hWinEventHook,DWORD event,HWND hwnd,LONG idObject,LONG id_ಮಗು,DWORD idEventThread,DWORD dwms_Event_ಸಮಯ);

  WINUSERAPI HWINEVENTHOOK WINAPI ಗಣ_Win_Event_Hook(DWORD eventMin,DWORD eventMax,HMODULE hmodWinEventProc,WINEVENTPROC pfnWinEventProc,DWORD idProcess,DWORD idThread,DWORD dwFlags);
  WINUSERAPI WINBOOL WINAPI IsWinEventHookInstalled(DWORD event);

#ವ್ಯಾಖ್ಯಾನಿಸು WINEVENT_OUTOFCONTEXT 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು WINEVENT_SKIPOWNTHREAD 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು WINEVENT_SKIPOWNPROCESS 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು WINEVENT_INCONTEXT 0x0004

  WINUSERAPI WINBOOL WINAPI UnhookWinEvent(HWINEVENTHOOK hWinEventHook);

#ವ್ಯಾಖ್ಯಾನಿಸು CHILDID_SELF 0
#ವ್ಯಾಖ್ಯಾನಿಸು INDEXID_OBJECT 0
#ವ್ಯಾಖ್ಯಾನಿಸು INDEXID_CONTAINER 0

#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_ಕಿಟಕಿ ((LONG)0x00000000)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_SYSMENU ((LONG)0xFFFFFFFF)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_TITLEBAR ((LONG)0xFFFFFFFE)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_MENU ((LONG)0xFFFFFFFD)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_CLIENT ((LONG)0xFFFFFFFC)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_VSCROLL ((LONG)0xFFFFFFFB)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_HSCROLL ((LONG)0xFFFFFFFA)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_SIZEGRIP ((LONG)0xFFFFFFF9)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_CARET ((LONG)0xFFFFFFF8)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_CURSOR ((LONG)0xFFFFFFF7)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_ALERT ((LONG)0xFFFFFFF6)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_SOUND ((LONG)0xFFFFFFF5)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_QUERYCLASSNAMEIDX ((LONG)0xFFFFFFF4)
#ವ್ಯಾಖ್ಯಾನಿಸು OBJID_NATIVEOM ((LONG)0xFFFFFFF0)

#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_MIN 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_MAX 0x7FFFFFFF

#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_SOUND 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_ALERT 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_FOREGROUND 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_MENUSTART 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_MENUEND 0x0005
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_MENUPOPUPSTART 0x0006
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_MENUPOPUPEND 0x0007
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_CAPTURESTART 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_CAPTUREEND 0x0009
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_MOVESIZESTART 0x000A
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_MOVESIZEEND 0x000B
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_CONTEXTHELPSTART 0x000C
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_CONTEXTHELPEND 0x000D
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_DRAGDROPSTART 0x000E
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_DRAGDROPEND 0x000F
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_DIALOGSTART 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_DIALOGEND 0x0011
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_SCROLLINGSTART 0x0012
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_SCROLLINGEND 0x0013
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_SWITCHSTART 0x0014
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_SWITCHEND 0x0015
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_MINIMIZESTART 0x0016
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_SYSTEM_MINIMIZEEND 0x0017

#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_CONSOLE_CARET 0x4001
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_CONSOLE_UPDATE_REGION 0x4002
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_CONSOLE_UPDATE_SIMPLE 0x4003
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_CONSOLE_UPDATE_SCROLL 0x4004
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_CONSOLE_LAYOUT 0x4005
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_CONSOLE_ಆರಂಭ_APPLICATION 0x4006
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_CONSOLE_ಕೊನೆ_APPLICATION 0x4007

#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_APPLICATION_16_ಬಿಟ್ 0x0001

#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_CARET_SELECTION 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು CONSOLE_CARET_VISIBLE 0x0002

#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_CREATE 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_DESTROY 0x8001
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_SHOW 0x8002
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_HIDE 0x8003
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_REORDER 0x8004

#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_FOCUS 0x8005
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_SELECTION 0x8006
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_SELECTIONADD 0x8007
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_SELECTIONREMOVE 0x8008
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_SELECTIONWITHIN 0x8009

#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_STATECHANGE 0x800A

#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_LOCATIONCHANGE 0x800B

#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_NAMECHANGE 0x800C
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_DESCRIPTIONCHANGE 0x800D
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_VALUECHANGE 0x800E
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_PARENTCHANGE 0x800F
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_HELPCHANGE 0x8010
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_DEFACTIONCHANGE 0x8011
#ವ್ಯಾಖ್ಯಾನಿಸು EVENT_OBJECT_ACCELERATORCHANGE 0x8012

#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_STARTUP 1
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_SHUTDOWN 2
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_BEEP 3
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_ERROR 4
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_QUESTION 5
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_WARNING 6
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_INFORMATION 7
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_MAXIMIZE 8
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_MINIMIZE 9
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_RESTOREUP 10
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_RESTOREDOWN 11
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_APPSTART 12
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_FAULT 13
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_APPEND 14
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_MENUCOMMAND 15
#ವ್ಯಾಖ್ಯಾನಿಸು SOUND_SYSTEM_MENUPOPUP 16
#ವ್ಯಾಖ್ಯಾನಿಸು CSOUND_SYSTEM 16

#ವ್ಯಾಖ್ಯಾನಿಸು ALERT_SYSTEM_INFORMATIONAL 1
#ವ್ಯಾಖ್ಯಾನಿಸು ALERT_SYSTEM_WARNING 2
#ವ್ಯಾಖ್ಯಾನಿಸು ALERT_SYSTEM_ERROR 3
#ವ್ಯಾಖ್ಯಾನಿಸು ALERT_SYSTEM_QUERY 4
#ವ್ಯಾಖ್ಯಾನಿಸು ALERT_SYSTEM_CRITICAL 5
#ವ್ಯಾಖ್ಯಾನಿಸು CALERT_SYSTEM 6

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_GUITHREADINFO {
    DWORD cb_ಗಾತ್ರ;
    DWORD flags;
    HWND hwnd_ಸಕ್ರಿಯ;
    HWND hwndFocus;
    HWND hwndCapture;
    HWND hwndMenuOwner;
    HWND hwnd_Move_ಗಾತ್ರ;
    HWND hwndCaret;
    RECT rcCaret;
  } GUITHREADINFO,*PGUITHREADINFO,*LPGUITHREADINFO;

#ವ್ಯಾಖ್ಯಾನಿಸು GUI_CARETBLINKING 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು GUI_INMOVESIZE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು GUI_INMENUMODE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು GUI_SYSTEMMENUMODE 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು GUI_POPUPMENUMODE 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು GUI_16BITTASK 0x00000020

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Module_File_Name Get_ಕಿಟಕಿ_Module_File_Name_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಕಿಟಕಿ_Module_File_Name Get_ಕಿಟಕಿ_Module_File_Name_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI GetGUIThreadInfo(DWORD idThread,PGUITHREADINFO pgui);
  WINUSERAPI UINT WINAPI Get_ಕಿಟಕಿ_Module_File_Name_A(HWND hwnd,LPSTR pszFileName,UINT cchFileNameMax);
  WINUSERAPI UINT WINAPI Get_ಕಿಟಕಿ_Module_File_Name_W(HWND hwnd,LPWSTR pszFileName,UINT cchFileNameMax);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NO_STATE_FLAGS
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_UNAVAILABLE 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_SELECTED 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_FOCUSED 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_PRESSED 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_CHECKED 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_MIXED 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_INDETERMINATE STATE_SYSTEM_MIXED
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_READONLY 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_HOTTRACKED 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_DEFAULT 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_EXPANDED 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_COLLAPSED 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_BUSY 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_FLOATING 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_MARQUEED 0x00002000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_ANIMATED 0x00004000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_INVISIBLE 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_OFFSCREEN 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_SIZEABLE 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_MOVEABLE 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_SELFVOICING 0x00080000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_FOCUSABLE 0x00100000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_SELECTABLE 0x00200000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_LINKED 0x00400000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_TRAVERSED 0x00800000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_MULTISELECTABLE 0x01000000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_EXTSELECTABLE 0x02000000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_ALERT_ಕೆಳಗಿನ 0x04000000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_ALERT_MEDIUM 0x08000000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_ALERT_ಮೇಲಿನ 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_PROTECTED 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು STATE_SYSTEM_VALID 0x3FFFFFFF
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು CCHILDREN_TITLEBAR 5
#ವ್ಯಾಖ್ಯಾನಿಸು CCHILDREN_SCROLLBAR 5

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CURSORINFO {
    DWORD cb_ಗಾತ್ರ;
    DWORD flags;
    HCURSOR hCursor;
    ಬಿಂದು_3 ptScreenPos;
  } CURSORINFO,*PCURSORINFO,*LPCURSORINFO;

#ವ್ಯಾಖ್ಯಾನಿಸು CURSOR_SHOWING 0x00000001

  WINUSERAPI WINBOOL WINAPI GetCursorInfo(PCURSORINFO pci);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_WINDOWINFO {
    DWORD cb_ಗಾತ್ರ;
    RECT rc_ಕಿಟಕಿ;
    RECT rcClient;
    DWORD dwStyle;
    DWORD dwExStyle;
    DWORD dw_ಕಿಟಕಿ_ಸ್ಥಿತಿ;
    UINT cx_ಕಿಟಕಿ_Borders;
    UINT cy_ಕಿಟಕಿ_Borders;
    ATOM atom_ಕಿಟಕಿ_Type;
    ಶಬ್ದ_3 w_Creator_ಆವೃತ್ತಿ;
  } WINDOWINFO,*PWINDOWINFO,*LPWINDOWINFO;

#ವ್ಯಾಖ್ಯಾನಿಸು WS_ACTIVECAPTION 0x0001

  WINUSERAPI WINBOOL WINAPI Get_ಕಿಟಕಿ_Info(HWND hwnd,PWINDOWINFO pwi);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_TITLEBARINFO {
    DWORD cb_ಗಾತ್ರ;
    RECT rcTitleBar;
    DWORD rgstate[CCHILDREN_TITLEBAR + 1];
  } TITLEBARINFO,*PTITLEBARINFO,*LPTITLEBARINFO;

  WINUSERAPI WINBOOL WINAPI GetTitleBarInfo(HWND hwnd,PTITLEBARINFO pti);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_MENUBARINFO {
    DWORD cb_ಗಾತ್ರ;
    RECT rcBar;
    HMENU hMenu;
    HWND hwndMenu;
    WINBOOL fBarFocused:1;
    WINBOOL fFocused:1;
  } MENUBARINFO,*PMENUBARINFO,*LPMENUBARINFO;

  WINUSERAPI WINBOOL WINAPI GetMenuBarInfo(HWND hwnd,LONG idObject,LONG id_ಅಂಶ,PMENUBARINFO pmbi);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_SCROLLBARINFO {
    DWORD cb_ಗಾತ್ರ;
    RECT rcScrollBar;
    ಪೂರ್ಣಾಂಕ dxy_ಸಾಲು_Button;
    ಪೂರ್ಣಾಂಕ xy_Thumb_ತುದಿ;
    ಪೂರ್ಣಾಂಕ xyThumbBottom;
    ಪೂರ್ಣಾಂಕ reserved;
    DWORD rgstate[CCHILDREN_SCROLLBAR + 1];
  } SCROLLBARINFO,*PSCROLLBARINFO,*LPSCROLLBARINFO;

  WINUSERAPI WINBOOL WINAPI GetScrollBarInfo(HWND hwnd,LONG idObject,PSCROLLBARINFO psbi);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_COMBOBOXINFO {
    DWORD cb_ಗಾತ್ರ;
    RECT rc_ಅಂಶ;
    RECT rcButton;
    DWORD stateButton;
    HWND hwndCombo;
    HWND hwnd_ಅಂಶ;
    HWND hwndList;
  } COMBOBOXINFO,*PCOMBOBOXINFO,*LPCOMBOBOXINFO;

  WINUSERAPI WINBOOL WINAPI GetComboBoxInfo(HWND hwndCombo,PCOMBOBOXINFO pcbi);

#ವ್ಯಾಖ್ಯಾನಿಸು GA_ಪೋಷಕ 1
#ವ್ಯಾಖ್ಯಾನಿಸು GA_ಬೇರು 2
#ವ್ಯಾಖ್ಯಾನಿಸು GA_ROOTOWNER 3

  WINUSERAPI HWND WINAPI GetAncestor(HWND hwnd,UINT gaFlags);
  WINUSERAPI HWND WINAPI Real_ಮಗು_ಕಿಟಕಿ_From_ಬಿಂದು(HWND hwnd_ಪೋಷಕ_2,ಬಿಂದು_3 pt_ಪೋಷಕ_Client_Coords);
  WINUSERAPI UINT WINAPI Real_Get_ಕಿಟಕಿ_Class_A(HWND hwnd,LPSTR ptszClassName,UINT cchClassNameMax);
  WINUSERAPI UINT WINAPI Real_Get_ಕಿಟಕಿ_Class_W(HWND hwnd,LPWSTR ptszClassName,UINT cchClassNameMax);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Real_Get_ಕಿಟಕಿ_Class Real_Get_ಕಿಟಕಿ_Class_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Real_Get_ಕಿಟಕಿ_Class Real_Get_ಕಿಟಕಿ_Class_A
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ALTTABINFO {
    DWORD cb_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ c_ವಸ್ತುಗಳು;
    ಪೂರ್ಣಾಂಕ cColumns;
    ಪೂರ್ಣಾಂಕ c_ಅಡ್ಡಸಾಲುಗಳು;
    ಪೂರ್ಣಾಂಕ i_ಲಂಬಸಾಲು_Focus;
    ಪೂರ್ಣಾಂಕ i_ಅಡ್ಡಸಾಲು_Focus;
    ಪೂರ್ಣಾಂಕ cx_ಅಂಶ;
    ಪೂರ್ಣಾಂಕ cy_ಅಂಶ;
    ಬಿಂದು_3 pt_ಆರಂಭ;
  } ALTTABINFO,*PALTTABINFO,*LPALTTABINFO;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetAltTabInfo GetAltTabInfoW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetAltTabInfo GetAltTabInfoA
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI GetAltTabInfoA(HWND hwnd,ಪೂರ್ಣಾಂಕ i_ಅಂಶ,PALTTABINFO pati,LPSTR psz_ಅಂಶ_ಪಠ್ಯ,UINT cch_ಅಂಶ_ಪಠ್ಯ);
  WINUSERAPI WINBOOL WINAPI GetAltTabInfoW(HWND hwnd,ಪೂರ್ಣಾಂಕ i_ಅಂಶ,PALTTABINFO pati,LPWSTR psz_ಅಂಶ_ಪಠ್ಯ,UINT cch_ಅಂಶ_ಪಠ್ಯ);
  WINUSERAPI DWORD WINAPI GetListBoxInfo(HWND hwnd);
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI WINBOOL WINAPI ಬೀಗ_Work_Station(VOID);
  WINUSERAPI WINBOOL WINAPI UserHandleGrantAccess(HANDLE hUserHandle,HANDLE h_ಕೆಲಸ,WINBOOL bGrant);

  DECLARE_HANDLE(HRAWINPUT);

#ವ್ಯಾಖ್ಯಾನಿಸು GET_RAWINPUT_ಸಂಕೇತ_WPARAM(wParam) ((wParam) & 0xff)

#ವ್ಯಾಖ್ಯಾನಿಸು RIM_ಒಳಹರಿವು 0
#ವ್ಯಾಖ್ಯಾನಿಸು RIM_INPUTSINK 1

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RAWINPUTHEADER {
    DWORD dwType;
    DWORD dw_ಗಾತ್ರ;
    HANDLE hDevice;
    WPARAM wParam;
  } RAWINPUTHEADER,*PRAWINPUTHEADER,*LPRAWINPUTHEADER;

#ವ್ಯಾಖ್ಯಾನಿಸು RIM_TYPEMOUSE 0
#ವ್ಯಾಖ್ಯಾನಿಸು RIM_TYPEKEYBOARD 1
#ವ್ಯಾಖ್ಯಾನಿಸು RIM_TYPEHID 2

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RAWMOUSE {
    USHORT usFlags;
    ಒಕ್ಕೂಟ {
      ULONG ulButtons;
      ರಚನೆ {
	USHORT usButtonFlags;
	USHORT us_Button_ದತ್ತಾಂಶ;
      };
    };
    ULONG ulRawButtons;
    LONG l_ಕೊನೆಯ_X;
    LONG l_ಕೊನೆಯ_Y;
    ULONG ulExtraInformation;
  } RAWMOUSE,*PRAWMOUSE,*LPRAWMOUSE;

#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_ಎಡ_BUTTON_ಕೆಳಕ್ಕೆ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_ಎಡ_BUTTON_ಮೇಲೆ 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_ಬಲ_BUTTON_ಕೆಳಕ್ಕೆ 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_ಬಲ_BUTTON_ಮೇಲೆ 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_ಮಧ್ಯ_BUTTON_ಕೆಳಕ್ಕೆ 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_ಮಧ್ಯ_BUTTON_ಮೇಲೆ 0x0020

#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_1_ಕೆಳಕ್ಕೆ RI_MOUSE_ಎಡ_BUTTON_ಕೆಳಕ್ಕೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_1_ಮೇಲೆ RI_MOUSE_ಎಡ_BUTTON_ಮೇಲೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_2_ಕೆಳಕ್ಕೆ RI_MOUSE_ಬಲ_BUTTON_ಕೆಳಕ್ಕೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_2_ಮೇಲೆ RI_MOUSE_ಬಲ_BUTTON_ಮೇಲೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_3_ಕೆಳಕ್ಕೆ RI_MOUSE_ಮಧ್ಯ_BUTTON_ಕೆಳಕ್ಕೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_3_ಮೇಲೆ RI_MOUSE_ಮಧ್ಯ_BUTTON_ಮೇಲೆ

#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_4_ಕೆಳಕ್ಕೆ 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_4_ಮೇಲೆ 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_5_ಕೆಳಕ್ಕೆ 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_BUTTON_5_ಮೇಲೆ 0x0200

#ವ್ಯಾಖ್ಯಾನಿಸು RI_MOUSE_WHEEL 0x0400

#ವ್ಯಾಖ್ಯಾನಿಸು MOUSE_MOVE_RELATIVE 0
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSE_MOVE_ABSOLUTE 1
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSE_VIRTUAL_DESKTOP 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSE_ಗುಣಲಕ್ಷಣಗಳು_ಬದಲಾಯಿತು 0x04

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RAWKEYBOARD {
    USHORT Make_ಸಂಕೇತ;
    USHORT Flags;
    USHORT Reserved;
    USHORT VKey;
    UINT ಸಂದೇಶ_6;
    ULONG ExtraInformation;
  } RAWKEYBOARD,*PRAWKEYBOARD,*LPRAWKEYBOARD;

#ವ್ಯಾಖ್ಯಾನಿಸು KEYBOARD_OVERRUN_MAKE_ಸಂಕೇತ 0xFF

#ವ್ಯಾಖ್ಯಾನಿಸು RI_ಕೀಲಿ_MAKE 0
#ವ್ಯಾಖ್ಯಾನಿಸು RI_ಕೀಲಿ_BREAK 1
#ವ್ಯಾಖ್ಯಾನಿಸು RI_ಕೀಲಿ_E0 2
#ವ್ಯಾಖ್ಯಾನಿಸು RI_ಕೀಲಿ_E1 4
#ವ್ಯಾಖ್ಯಾನಿಸು RI_ಕೀಲಿ_TERMSRV_ಗಣ_LED 8
#ವ್ಯಾಖ್ಯಾನಿಸು RI_ಕೀಲಿ_TERMSRV_SHADOW 0x10

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RAWHID {
    DWORD dw_ಗಾತ್ರ_Hid;
    DWORD dw_ಎಣಿಕೆ;
    BYTE b_Raw_ದತ್ತಾಂಶ[1];
  } RAWHID,*PRAWHID,*LPRAWHID;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RAWINPUT {
    RAWINPUTHEADER ಶೀರ್ಷಿಕೆ;
    ಒಕ್ಕೂಟ {
      RAWMOUSE mouse;
      RAWKEYBOARD keyboard;
      RAWHID hid;
    } ದತ್ತಾಂಶ;
  } RAWINPUT,*PRAWINPUT,*LPRAWINPUT;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ _WIN64
#ವ್ಯಾಖ್ಯಾನಿಸು RAWINPUT_ALIGN(x) (((x) + ಗಾತ್ರ(QWORD) - 1) & ~(ಗಾತ್ರ(QWORD) - 1))
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು RAWINPUT_ALIGN(x) (((x) + ಗಾತ್ರ(DWORD) - 1) & ~(ಗಾತ್ರ(DWORD) - 1))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->ಶೀರ್ಷಿಕೆ.dw_ಗಾತ್ರ)))

#ವ್ಯಾಖ್ಯಾನಿಸು RID_ಒಳಹರಿವು 0x10000003
#ವ್ಯಾಖ್ಯಾನಿಸು RID_ಶೀರ್ಷಿಕೆ 0x10000005

  WINUSERAPI UINT WINAPI Get_Raw_ಒಳಹರಿವು_ದತ್ತಾಂಶ(HRAWINPUT h_Raw_ಒಳಹರಿವು,UINT uiCommand,LPVOID p_ದತ್ತಾಂಶ,PUINT pcb_ಗಾತ್ರ,UINT cb_ಗಾತ್ರ_ಶೀರ್ಷಿಕೆ);

#ವ್ಯಾಖ್ಯಾನಿಸು RIDI_PREPARSEDDATA 0x20000005
#ವ್ಯಾಖ್ಯಾನಿಸು RIDI_DEVICENAME 0x20000007
#ವ್ಯಾಖ್ಯಾನಿಸು RIDI_DEVICEINFO 0x2000000b

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RID_DEVICE_INFO_MOUSE {
    DWORD dwId;
    DWORD dw_ಸಂಖ್ಯೆ_ದ_Buttons;
    DWORD dw_Sample_ದರ;
  } RID_DEVICE_INFO_MOUSE,*PRID_DEVICE_INFO_MOUSE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RID_DEVICE_INFO_KEYBOARD {
    DWORD dwType;
    DWORD dwSubType;
    DWORD dw_Keyboard_ಬಹುಲಕ;
    DWORD dw_ಸಂಖ್ಯೆ_ದ_Function_ಕೀಲಿಗಳು;
    DWORD dw_ಸಂಖ್ಯೆ_ದ_Indicators;
    DWORD dw_ಸಂಖ್ಯೆ_ದ_ಕೀಲಿಗಳು_ಒಟ್ಟು;
  } RID_DEVICE_INFO_KEYBOARD,*PRID_DEVICE_INFO_KEYBOARD;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RID_DEVICE_INFO_HID {
    DWORD dwVendorId;
    DWORD dw_ಗುಣಲಬ್ಧ_Id;
    DWORD dw_ಆವೃತ್ತಿ_ಸಂಖ್ಯೆ;
    USHORT us_Usage_ಪುಟ;
    USHORT usUsage;
  } RID_DEVICE_INFO_HID,*PRID_DEVICE_INFO_HID;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RID_DEVICE_INFO {
    DWORD cb_ಗಾತ್ರ;
    DWORD dwType;
    ಒಕ್ಕೂಟ {
      RID_DEVICE_INFO_MOUSE mouse;
      RID_DEVICE_INFO_KEYBOARD keyboard;
      RID_DEVICE_INFO_HID hid;
    };
  } RID_DEVICE_INFO,*PRID_DEVICE_INFO,*LPRID_DEVICE_INFO;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Raw_ಒಳಹರಿವು_Device_Info Get_Raw_ಒಳಹರಿವು_Device_Info_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Raw_ಒಳಹರಿವು_Device_Info Get_Raw_ಒಳಹರಿವು_Device_Info_A
#ಆದರೆ_ಅಂತ್ಯ

  WINUSERAPI UINT WINAPI Get_Raw_ಒಳಹರಿವು_Device_Info_A(HANDLE hDevice,UINT uiCommand,LPVOID p_ದತ್ತಾಂಶ,PUINT pcb_ಗಾತ್ರ);
  WINUSERAPI UINT WINAPI Get_Raw_ಒಳಹರಿವು_Device_Info_W(HANDLE hDevice,UINT uiCommand,LPVOID p_ದತ್ತಾಂಶ,PUINT pcb_ಗಾತ್ರ);
  WINUSERAPI UINT WINAPI Get_Raw_ಒಳಹರಿವು_ಬಫರ್(PRAWINPUT p_ದತ್ತಾಂಶ,PUINT pcb_ಗಾತ್ರ,UINT cb_ಗಾತ್ರ_ಶೀರ್ಷಿಕೆ);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RAWINPUTDEVICE {
    USHORT us_Usage_ಪುಟ;
    USHORT usUsage;
    DWORD dwFlags;
    HWND hwnd_ಗುರಿ;
  } RAWINPUTDEVICE,*PRAWINPUTDEVICE,*LPRAWINPUTDEVICE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CONST RAWINPUTDEVICE *PCRAWINPUTDEVICE;

#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_REMOVE 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_EXCLUDE 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_PAGEONLY 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_NOLEGACY 0x00000030
#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_INPUTSINK 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_CAPTUREMOUSE 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_NOHOTKEYS 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_APPKEYS 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_EXMODEMASK 0x000000F0
#ವ್ಯಾಖ್ಯಾನಿಸು RIDEV_EXMODE(ಬಹುಲಕ) ((ಬಹುಲಕ) & RIDEV_EXMODEMASK)

  WINUSERAPI WINBOOL WINAPI ರಿಜಿಸ್ಟರ್_Raw_ಒಳಹರಿವು_Devices(PCRAWINPUTDEVICE p_Raw_ಒಳಹರಿವು_Devices,UINT ui_ಅಂಕೆ_Devices,UINT cb_ಗಾತ್ರ);
  WINUSERAPI UINT WINAPI Get_Registered_Raw_ಒಳಹರಿವು_Devices(PRAWINPUTDEVICE p_Raw_ಒಳಹರಿವು_Devices,PUINT pui_ಅಂಕೆ_Devices,UINT cb_ಗಾತ್ರ);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RAWINPUTDEVICELIST {
    HANDLE hDevice;
    DWORD dwType;
  } RAWINPUTDEVICELIST,*PRAWINPUTDEVICELIST;

  WINUSERAPI UINT WINAPI Get_Raw_ಒಳಹರಿವು_Device_List(PRAWINPUTDEVICELIST p_Raw_ಒಳಹರಿವು_Device_List,PUINT pui_ಅಂಕೆ_Devices,UINT cb_ಗಾತ್ರ);
  WINUSERAPI LRESULT WINAPI Def_Raw_ಒಳಹರಿವು_Proc(PRAWINPUT *pa_Raw_ಒಳಹರಿವು,INT n_ಒಳಹರಿವು,UINT cb_ಗಾತ್ರ_ಶೀರ್ಷಿಕೆ);

#ಆದರೆ_ಅಂತ್ಯ /* NOUSER */

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
