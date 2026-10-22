/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _WINDEF_
#تعریف_کړه _WINDEF_

#که_نه_تعریف_شوی STRICT
#تعریف_کړه STRICT 1
#د_که_پای

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی WINVER
#تعریف_کړه WINVER 0x0502
#د_که_پای

#که_نه_تعریف_شوی BASETYPES
#تعریف_کړه BASETYPES
  تعريفنوع بینښه اوږد ULONG;
  تعريفنوع ULONG *PULONG;
  تعريفنوع بینښه لنډ USHORT;
  تعريفنوع USHORT *PUSHORT;
  تعريفنوع بینښه حرف UCHAR;
  تعريفنوع UCHAR *PUCHAR;
  تعريفنوع حرف *PSZ;
#د_که_پای

#تعریف_کړه MAX_لار 260

#که_نه_تعریف_شوی عدم
#که_تعریف_شوی __cplusplus
#تعریف_کړه عدم 0
#وإلا
#تعریف_کړه عدم ((فراغ *)0)
#د_که_پای
#د_که_پای

#که_نه_تعریف_شوی FALSE
#تعریف_کړه FALSE 0
#د_که_پای

#که_نه_تعریف_شوی TRUE
#تعریف_کړه TRUE 1
#د_که_پای

#که_نه_تعریف_شوی دننه_2
#تعریف_کړه دننه_2
#د_که_پای

#که_نه_تعریف_شوی بهر_2
#تعریف_کړه بهر_2
#د_که_پای

#که_نه_تعریف_شوی OPTIONAL
#تعریف_کړه OPTIONAL
#د_که_پای

#تعریف_لغوه far
#تعریف_لغوه near
#تعریف_لغوه pascal

#تعریف_کړه far
#تعریف_کړه near
#تعریف_کړه pascal __stdcall

#تعریف_کړه cdecl
#که_نه_تعریف_شوی CDECL
#تعریف_کړه CDECL
#د_که_پای
#که_نه_تعریف_شوی CALLBACK
#تعریف_کړه CALLBACK __stdcall
#د_که_پای
#که_نه_تعریف_شوی WINAPI
#تعریف_کړه WINAPI __stdcall
#د_که_پای
#تعریف_کړه WINAPIV __cdecl
#تعریف_کړه APIENTRY WINAPI
#تعریف_کړه APIPRIVATE WINAPI
#تعریف_کړه PASCAL WINAPI
#تعریف_کړه WINAPI_INLINE WINAPI

#تعریف_لغوه FAR
#تعریف_لغوه NEAR
#تعریف_کړه FAR
#تعریف_کړه NEAR
#که_نه_تعریف_شوی CONST
#تعریف_کړه CONST ثابت
#د_که_پای

  تعريفنوع بینښه اوږد DWORD;
  تعريفنوع صحيح WINBOOL;
#تعریف_کړه BOOL WINBOOL
  تعريفنوع بینښه حرف BYTE;
  تعريفنوع بینښه لنډ کلمه_3;
  تعريفنوع عائم FLOAT;
  تعريفنوع FLOAT *PFLOAT;
  تعريفنوع WINBOOL *PBOOL;
  تعريفنوع WINBOOL *LPBOOL;
  تعريفنوع BYTE *PBYTE;
  تعريفنوع BYTE *LPBYTE;
  تعريفنوع صحيح *PINT;
  تعريفنوع صحيح *LPINT;
  تعريفنوع کلمه_3 *PWORD;
  تعريفنوع کلمه_3 *LPWORD;
  تعريفنوع اوږد *LPLONG;
  تعريفنوع DWORD *PDWORD;
  تعريفنوع DWORD *LPDWORD;
  تعريفنوع فراغ *LPVOID;
# ifndef _LPCVOID_DEFINED
#تعریف_کړه _LPCVOID_DEFINED
تعريفنوع CONST فراغ *LPCVOID;
#د_که_پای
  تعريفنوع صحيح INT;
  تعريفنوع بینښه صحيح UINT;
  تعريفنوع بینښه صحيح *PUINT;

#که_نه_تعریف_شوی NT_INCLUDED
#ضمن <winnt.h>
#د_که_پای

//gr #include <specstrings.h>

  تعريفنوع UINT_PTR WPARAM;
  تعريفنوع LONG_PTR LPARAM;
  تعريفنوع LONG_PTR LRESULT;

#که_نه_تعریف_شوی __cplusplus
#که_نه_تعریف_شوی NOMINMAX
#که_نه_تعریف_شوی max
#تعریف_کړه max(a,b) (((a) > (b)) ? (a) : (b))
#د_که_پای

#که_نه_تعریف_شوی min
#تعریف_کړه min(a,b) (((a) < (b)) ? (a) : (b))
#د_که_پای
#د_که_پای
#د_که_پای

#تعریف_کړه MAKEWORD(a,b) ((کلمه_3)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((کلمه_3)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#تعریف_کړه MAKELONG(a,b) ((LONG)(((کلمه_3)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((کلمه_3)((DWORD_PTR)(b) & 0xffff))) << 16))
#تعریف_کړه LOWORD(l) ((کلمه_3)((DWORD_PTR)(l) & 0xffff))
#تعریف_کړه HIWORD(l) ((کلمه_3)((DWORD_PTR)(l) >> 16))
#تعریف_کړه LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#تعریف_کړه HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#که_نه_تعریف_شوی WIN_دننی
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#که_تعریف_شوی WINABLE
  DECLARE_HANDLE (HEVENT);
#د_که_پای
#د_که_پای

  تعريفنوع کلمه_3 ATOM;

  تعريفنوع HANDLE *SPHANDLE;
  تعريفنوع HANDLE *LPHANDLE;
  تعريفنوع HANDLE HGLOBAL;
  تعريفنوع HANDLE HLOCAL;
  تعريفنوع HANDLE GLOBALHANDLE;
  تعريفنوع HANDLE LOCALHANDLE;
#که_تعریف_شوی _WIN64
  تعريفنوع INT_PTR (WINAPI *FARPROC)();
  تعريفنوع INT_PTR (WINAPI *NEARPROC)();
  تعريفنوع INT_PTR (WINAPI *PROC)();
#وإلا
  تعريفنوع صحيح (WINAPI *FARPROC)();
  تعريفنوع صحيح (WINAPI *NEARPROC)();
  تعريفنوع صحيح (WINAPI *PROC)();
#د_که_پای

  تعريفنوع فراغ *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  تعريفنوع HKEY *PHKEY;

  DECLARE_HANDLE(HACCEL);
  DECLARE_HANDLE(HBITMAP);
  DECLARE_HANDLE(HBRUSH);
  DECLARE_HANDLE(HCOLORSPACE);
  DECLARE_HANDLE(HDC);
  DECLARE_HANDLE(HGLRC);
  DECLARE_HANDLE(HDESK);
  DECLARE_HANDLE(HENHMETAFILE);
  DECLARE_HANDLE(HFONT);
  DECLARE_HANDLE(HICON);
  DECLARE_HANDLE(HMENU);
  DECLARE_HANDLE(HMETAFILE);
  DECLARE_HANDLE(HINSTANCE);
  تعريفنوع HINSTANCE HMODULE;
  DECLARE_HANDLE(HPALETTE);
  DECLARE_HANDLE(HPEN);
  DECLARE_HANDLE(HRGN);
  DECLARE_HANDLE(HRSRC);
  DECLARE_HANDLE(HSTR);
  DECLARE_HANDLE(HTASK);
  DECLARE_HANDLE(HWINSTA);
  DECLARE_HANDLE(HKL);
  DECLARE_HANDLE(HMONITOR);
  DECLARE_HANDLE(HWINEVENTHOOK);
  DECLARE_HANDLE(HUMPD);

  تعريفنوع صحيح HFILE;
  تعريفنوع HICON HCURSOR;
  تعريفنوع DWORD COLORREF;
  تعريفنوع DWORD *LPCOLORREF;

#تعریف_کړه HFILE_ERROR ((HFILE)-1)

  تعريفنوع بنية نښان_RECT {
    LONG کیڼ;
    LONG سر;
    LONG ښی;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  تعريفنوع ثابت RECT *LPCRECT;

  تعريفنوع بنية _RECTL {
    LONG کیڼ;
    LONG سر;
    LONG ښی;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  تعريفنوع ثابت RECTL *LPCRECTL;

  تعريفنوع بنية نښان_ټکی {
    LONG x;
    LONG y;
  } ټکی_3,*PPOINT,*NPPOINT,*LPPOINT;

  تعريفنوع بنية _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  تعريفنوع بنية نښان_اندازه {
    LONG cx;
    LONG cy;
  } اندازه_2,*PSIZE,*LPSIZE;

  تعريفنوع اندازه_2 SIZEL;
  تعريفنوع اندازه_2 *PSIZEL,*LPSIZEL;

  تعريفنوع بنية نښان_POINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  تعريفنوع بنية _FILETIME {
    DWORD dw_ټیټ_Date_وخت;
    DWORD dw_لوړ_Date_وخت;
  } FILETIME,*PFILETIME,*LPFILETIME;
#تعریف_کړه _FILETIME_

#تعریف_کړه DM_UPDATE 1
#تعریف_کړه DM_COPY 2
#تعریف_کړه DM_PROMPT 4
#تعریف_کړه DM_MODIFY 8

#تعریف_کړه DM_دننه_بفر DM_MODIFY
#تعریف_کړه DM_دننه_PROMPT DM_PROMPT
#تعریف_کړه DM_بهر_بفر DM_COPY
#تعریف_کړه DM_بهر_DEFAULT DM_UPDATE

#تعریف_کړه DC_FIELDS 1
#تعریف_کړه DC_PAPERS 2
#تعریف_کړه DC_PAPERSIZE 3
#تعریف_کړه DC_MINEXTENT 4
#تعریف_کړه DC_MAXEXTENT 5
#تعریف_کړه DC_BINS 6
#تعریف_کړه DC_DUPLEX 7
#تعریف_کړه DC_اندازه 8
#تعریف_کړه DC_EXTRA 9
#تعریف_کړه DC_نسخه 10
#تعریف_کړه DC_DRIVER 11
#تعریف_کړه DC_BINNAMES 12
#تعریف_کړه DC_ENUMRESOLUTIONS 13
#تعریف_کړه DC_FILEDEPENDENCIES 14
#تعریف_کړه DC_TRUETYPE 15
#تعریف_کړه DC_PAPERNAMES 16
#تعریف_کړه DC_ORIENTATION 17
#تعریف_کړه DC_COPIES 18

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
