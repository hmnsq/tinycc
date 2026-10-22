/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _WINDEF_
#تعریف_کن _WINDEF_

#اگر_تعریف_نشده STRICT
#تعریف_کن STRICT 1
#پایان_اگر

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده WINVER
#تعریف_کن WINVER 0x0502
#پایان_اگر

#اگر_تعریف_نشده BASETYPES
#تعریف_کن BASETYPES
  تعريفنوع بیعلامت دراز ULONG;
  تعريفنوع ULONG *PULONG;
  تعريفنوع بیعلامت کوتاه USHORT;
  تعريفنوع USHORT *PUSHORT;
  تعريفنوع بیعلامت حرف UCHAR;
  تعريفنوع UCHAR *PUCHAR;
  تعريفنوع حرف *PSZ;
#پایان_اگر

#تعریف_کن MAX_مسیر 260

#اگر_تعریف_نشده عدم
#اگر_تعریف_شده __cplusplus
#تعریف_کن عدم 0
#وإلا
#تعریف_کن عدم ((فراغ *)0)
#پایان_اگر
#پایان_اگر

#اگر_تعریف_نشده FALSE
#تعریف_کن FALSE 0
#پایان_اگر

#اگر_تعریف_نشده TRUE
#تعریف_کن TRUE 1
#پایان_اگر

#اگر_تعریف_نشده درون_2
#تعریف_کن درون_2
#پایان_اگر

#اگر_تعریف_نشده بیرون_2
#تعریف_کن بیرون_2
#پایان_اگر

#اگر_تعریف_نشده OPTIONAL
#تعریف_کن OPTIONAL
#پایان_اگر

#لغو_تعریف far
#لغو_تعریف near
#لغو_تعریف pascal

#تعریف_کن far
#تعریف_کن near
#تعریف_کن pascal __stdcall

#تعریف_کن cdecl
#اگر_تعریف_نشده CDECL
#تعریف_کن CDECL
#پایان_اگر
#اگر_تعریف_نشده CALLBACK
#تعریف_کن CALLBACK __stdcall
#پایان_اگر
#اگر_تعریف_نشده WINAPI
#تعریف_کن WINAPI __stdcall
#پایان_اگر
#تعریف_کن WINAPIV __cdecl
#تعریف_کن APIENTRY WINAPI
#تعریف_کن APIPRIVATE WINAPI
#تعریف_کن PASCAL WINAPI
#تعریف_کن WINAPI_INLINE WINAPI

#لغو_تعریف FAR
#لغو_تعریف NEAR
#تعریف_کن FAR
#تعریف_کن NEAR
#اگر_تعریف_نشده CONST
#تعریف_کن CONST ثابت
#پایان_اگر

  تعريفنوع بیعلامت دراز DWORD;
  تعريفنوع صحيح WINBOOL;
#تعریف_کن BOOL WINBOOL
  تعريفنوع بیعلامت حرف BYTE;
  تعريفنوع بیعلامت کوتاه کلمه_3;
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
  تعريفنوع دراز *LPLONG;
  تعريفنوع DWORD *PDWORD;
  تعريفنوع DWORD *LPDWORD;
  تعريفنوع فراغ *LPVOID;
# ifndef _LPCVOID_DEFINED
#تعریف_کن _LPCVOID_DEFINED
تعريفنوع CONST فراغ *LPCVOID;
#پایان_اگر
  تعريفنوع صحيح INT;
  تعريفنوع بیعلامت صحيح UINT;
  تعريفنوع بیعلامت صحيح *PUINT;

#اگر_تعریف_نشده NT_INCLUDED
#ضمن <winnt.h>
#پایان_اگر

//gr #include <specstrings.h>

  تعريفنوع UINT_PTR WPARAM;
  تعريفنوع LONG_PTR LPARAM;
  تعريفنوع LONG_PTR LRESULT;

#اگر_تعریف_نشده __cplusplus
#اگر_تعریف_نشده NOMINMAX
#اگر_تعریف_نشده max
#تعریف_کن max(a,b) (((a) > (b)) ? (a) : (b))
#پایان_اگر

#اگر_تعریف_نشده min
#تعریف_کن min(a,b) (((a) < (b)) ? (a) : (b))
#پایان_اگر
#پایان_اگر
#پایان_اگر

#تعریف_کن MAKEWORD(a,b) ((کلمه_3)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((کلمه_3)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#تعریف_کن MAKELONG(a,b) ((LONG)(((کلمه_3)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((کلمه_3)((DWORD_PTR)(b) & 0xffff))) << 16))
#تعریف_کن LOWORD(l) ((کلمه_3)((DWORD_PTR)(l) & 0xffff))
#تعریف_کن HIWORD(l) ((کلمه_3)((DWORD_PTR)(l) >> 16))
#تعریف_کن LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#تعریف_کن HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#اگر_تعریف_نشده WIN_داخلی
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#اگر_تعریف_شده WINABLE
  DECLARE_HANDLE (HEVENT);
#پایان_اگر
#پایان_اگر

  تعريفنوع کلمه_3 ATOM;

  تعريفنوع HANDLE *SPHANDLE;
  تعريفنوع HANDLE *LPHANDLE;
  تعريفنوع HANDLE HGLOBAL;
  تعريفنوع HANDLE HLOCAL;
  تعريفنوع HANDLE GLOBALHANDLE;
  تعريفنوع HANDLE LOCALHANDLE;
#اگر_تعریف_شده _WIN64
  تعريفنوع INT_PTR (WINAPI *FARPROC)();
  تعريفنوع INT_PTR (WINAPI *NEARPROC)();
  تعريفنوع INT_PTR (WINAPI *PROC)();
#وإلا
  تعريفنوع صحيح (WINAPI *FARPROC)();
  تعريفنوع صحيح (WINAPI *NEARPROC)();
  تعريفنوع صحيح (WINAPI *PROC)();
#پایان_اگر

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

#تعریف_کن HFILE_ERROR ((HFILE)-1)

  تعريفنوع بنية برچسب_RECT {
    LONG چپ;
    LONG بالاترین;
    LONG راست;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  تعريفنوع ثابت RECT *LPCRECT;

  تعريفنوع بنية _RECTL {
    LONG چپ;
    LONG بالاترین;
    LONG راست;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  تعريفنوع ثابت RECTL *LPCRECTL;

  تعريفنوع بنية برچسب_نقطه {
    LONG x;
    LONG y;
  } نقطه_3,*PPOINT,*NPPOINT,*LPPOINT;

  تعريفنوع بنية _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  تعريفنوع بنية برچسب_اندازه {
    LONG cx;
    LONG cy;
  } اندازه_2,*PSIZE,*LPSIZE;

  تعريفنوع اندازه_2 SIZEL;
  تعريفنوع اندازه_2 *PSIZEL,*LPSIZEL;

  تعريفنوع بنية برچسب_POINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  تعريفنوع بنية _FILETIME {
    DWORD dw_کم_Date_زمان;
    DWORD dw_بالا_Date_زمان;
  } FILETIME,*PFILETIME,*LPFILETIME;
#تعریف_کن _FILETIME_

#تعریف_کن DM_UPDATE 1
#تعریف_کن DM_COPY 2
#تعریف_کن DM_PROMPT 4
#تعریف_کن DM_MODIFY 8

#تعریف_کن DM_درون_میانگیر DM_MODIFY
#تعریف_کن DM_درون_PROMPT DM_PROMPT
#تعریف_کن DM_بیرون_میانگیر DM_COPY
#تعریف_کن DM_بیرون_DEFAULT DM_UPDATE

#تعریف_کن DC_FIELDS 1
#تعریف_کن DC_PAPERS 2
#تعریف_کن DC_PAPERSIZE 3
#تعریف_کن DC_MINEXTENT 4
#تعریف_کن DC_MAXEXTENT 5
#تعریف_کن DC_BINS 6
#تعریف_کن DC_DUPLEX 7
#تعریف_کن DC_اندازه 8
#تعریف_کن DC_EXTRA 9
#تعریف_کن DC_نسخه 10
#تعریف_کن DC_DRIVER 11
#تعریف_کن DC_BINNAMES 12
#تعریف_کن DC_ENUMRESOLUTIONS 13
#تعریف_کن DC_FILEDEPENDENCIES 14
#تعریف_کن DC_TRUETYPE 15
#تعریف_کن DC_PAPERNAMES 16
#تعریف_کن DC_ORIENTATION 17
#تعریف_کن DC_COPIES 18

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
