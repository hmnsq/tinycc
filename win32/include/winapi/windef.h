/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _WINDEF_
#تعریف_کرو _WINDEF_

#جے_بنا_تعریف STRICT
#تعریف_کرو STRICT 1
#جے_انت

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف WINVER
#تعریف_کرو WINVER 0x0502
#جے_انت

#جے_بنا_تعریف BASETYPES
#تعریف_کرو BASETYPES
  تعريفنوع بنانشانی لما ULONG;
  تعريفنوع ULONG *PULONG;
  تعريفنوع بنانشانی چھوٹا USHORT;
  تعريفنوع USHORT *PUSHORT;
  تعريفنوع بنانشانی حرف UCHAR;
  تعريفنوع UCHAR *PUCHAR;
  تعريفنوع حرف *PSZ;
#جے_انت

#تعریف_کرو MAX_رستہ 260

#جے_بنا_تعریف عدم
#جے_تعریف_شدہ __cplusplus
#تعریف_کرو عدم 0
#وإلا
#تعریف_کرو عدم ((فراغ *)0)
#جے_انت
#جے_انت

#جے_بنا_تعریف FALSE
#تعریف_کرو FALSE 0
#جے_انت

#جے_بنا_تعریف TRUE
#تعریف_کرو TRUE 1
#جے_انت

#جے_بنا_تعریف وچ_2
#تعریف_کرو وچ_2
#جے_انت

#جے_بنا_تعریف باہرلا_2
#تعریف_کرو باہرلا_2
#جے_انت

#جے_بنا_تعریف OPTIONAL
#تعریف_کرو OPTIONAL
#جے_انت

#تعریف_رد far
#تعریف_رد near
#تعریف_رد pascal

#تعریف_کرو far
#تعریف_کرو near
#تعریف_کرو pascal __stdcall

#تعریف_کرو cdecl
#جے_بنا_تعریف CDECL
#تعریف_کرو CDECL
#جے_انت
#جے_بنا_تعریف CALLBACK
#تعریف_کرو CALLBACK __stdcall
#جے_انت
#جے_بنا_تعریف WINAPI
#تعریف_کرو WINAPI __stdcall
#جے_انت
#تعریف_کرو WINAPIV __cdecl
#تعریف_کرو APIENTRY WINAPI
#تعریف_کرو APIPRIVATE WINAPI
#تعریف_کرو PASCAL WINAPI
#تعریف_کرو WINAPI_INLINE WINAPI

#تعریف_رد FAR
#تعریف_رد NEAR
#تعریف_کرو FAR
#تعریف_کرو NEAR
#جے_بنا_تعریف CONST
#تعریف_کرو CONST ثابت
#جے_انت

  تعريفنوع بنانشانی لما DWORD;
  تعريفنوع صحيح WINBOOL;
#تعریف_کرو BOOL WINBOOL
  تعريفنوع بنانشانی حرف BYTE;
  تعريفنوع بنانشانی چھوٹا لفظ_3;
  تعريفنوع عائم FLOAT;
  تعريفنوع FLOAT *PFLOAT;
  تعريفنوع WINBOOL *PBOOL;
  تعريفنوع WINBOOL *LPBOOL;
  تعريفنوع BYTE *PBYTE;
  تعريفنوع BYTE *LPBYTE;
  تعريفنوع صحيح *PINT;
  تعريفنوع صحيح *LPINT;
  تعريفنوع لفظ_3 *PWORD;
  تعريفنوع لفظ_3 *LPWORD;
  تعريفنوع لما *LPLONG;
  تعريفنوع DWORD *PDWORD;
  تعريفنوع DWORD *LPDWORD;
  تعريفنوع فراغ *LPVOID;
# ifndef _LPCVOID_DEFINED
#تعریف_کرو _LPCVOID_DEFINED
تعريفنوع CONST فراغ *LPCVOID;
#جے_انت
  تعريفنوع صحيح INT;
  تعريفنوع بنانشانی صحيح UINT;
  تعريفنوع بنانشانی صحيح *PUINT;

#جے_بنا_تعریف NT_INCLUDED
#ضمن <winnt.h>
#جے_انت

//gr #include <specstrings.h>

  تعريفنوع UINT_PTR WPARAM;
  تعريفنوع LONG_PTR LPARAM;
  تعريفنوع LONG_PTR LRESULT;

#جے_بنا_تعریف __cplusplus
#جے_بنا_تعریف NOMINMAX
#جے_بنا_تعریف max
#تعریف_کرو max(a,b) (((a) > (b)) ? (a) : (b))
#جے_انت

#جے_بنا_تعریف min
#تعریف_کرو min(a,b) (((a) < (b)) ? (a) : (b))
#جے_انت
#جے_انت
#جے_انت

#تعریف_کرو MAKEWORD(a,b) ((لفظ_3)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((لفظ_3)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#تعریف_کرو MAKELONG(a,b) ((LONG)(((لفظ_3)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((لفظ_3)((DWORD_PTR)(b) & 0xffff))) << 16))
#تعریف_کرو LOWORD(l) ((لفظ_3)((DWORD_PTR)(l) & 0xffff))
#تعریف_کرو HIWORD(l) ((لفظ_3)((DWORD_PTR)(l) >> 16))
#تعریف_کرو LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#تعریف_کرو HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#جے_بنا_تعریف WIN_اندرونی
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#جے_تعریف_شدہ WINABLE
  DECLARE_HANDLE (HEVENT);
#جے_انت
#جے_انت

  تعريفنوع لفظ_3 ATOM;

  تعريفنوع HANDLE *SPHANDLE;
  تعريفنوع HANDLE *LPHANDLE;
  تعريفنوع HANDLE HGLOBAL;
  تعريفنوع HANDLE HLOCAL;
  تعريفنوع HANDLE GLOBALHANDLE;
  تعريفنوع HANDLE LOCALHANDLE;
#جے_تعریف_شدہ _WIN64
  تعريفنوع INT_PTR (WINAPI *FARPROC)();
  تعريفنوع INT_PTR (WINAPI *NEARPROC)();
  تعريفنوع INT_PTR (WINAPI *PROC)();
#وإلا
  تعريفنوع صحيح (WINAPI *FARPROC)();
  تعريفنوع صحيح (WINAPI *NEARPROC)();
  تعريفنوع صحيح (WINAPI *PROC)();
#جے_انت

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

#تعریف_کرو HFILE_ERROR ((HFILE)-1)

  تعريفنوع بنية ٹیگ_RECT {
    LONG بایاں;
    LONG چوٹی;
    LONG دایاں;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  تعريفنوع ثابت RECT *LPCRECT;

  تعريفنوع بنية _RECTL {
    LONG بایاں;
    LONG چوٹی;
    LONG دایاں;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  تعريفنوع ثابت RECTL *LPCRECTL;

  تعريفنوع بنية ٹیگ_نقطہ {
    LONG x;
    LONG y;
  } نقطہ_3,*PPOINT,*NPPOINT,*LPPOINT;

  تعريفنوع بنية _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  تعريفنوع بنية ٹیگ_ناپ {
    LONG cx;
    LONG cy;
  } ناپ_2,*PSIZE,*LPSIZE;

  تعريفنوع ناپ_2 SIZEL;
  تعريفنوع ناپ_2 *PSIZEL,*LPSIZEL;

  تعريفنوع بنية ٹیگ_POINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  تعريفنوع بنية _FILETIME {
    DWORD dw_کم_Date_ویلا;
    DWORD dw_بلند_Date_ویلا;
  } FILETIME,*PFILETIME,*LPFILETIME;
#تعریف_کرو _FILETIME_

#تعریف_کرو DM_UPDATE 1
#تعریف_کرو DM_COPY 2
#تعریف_کرو DM_PROMPT 4
#تعریف_کرو DM_MODIFY 8

#تعریف_کرو DM_وچ_بفر DM_MODIFY
#تعریف_کرو DM_وچ_PROMPT DM_PROMPT
#تعریف_کرو DM_باہرلا_بفر DM_COPY
#تعریف_کرو DM_باہرلا_DEFAULT DM_UPDATE

#تعریف_کرو DC_FIELDS 1
#تعریف_کرو DC_PAPERS 2
#تعریف_کرو DC_PAPERSIZE 3
#تعریف_کرو DC_MINEXTENT 4
#تعریف_کرو DC_MAXEXTENT 5
#تعریف_کرو DC_BINS 6
#تعریف_کرو DC_DUPLEX 7
#تعریف_کرو DC_ناپ 8
#تعریف_کرو DC_EXTRA 9
#تعریف_کرو DC_نسخہ 10
#تعریف_کرو DC_DRIVER 11
#تعریف_کرو DC_BINNAMES 12
#تعریف_کرو DC_ENUMRESOLUTIONS 13
#تعریف_کرو DC_FILEDEPENDENCIES 14
#تعریف_کرو DC_TRUETYPE 15
#تعریف_کرو DC_PAPERNAMES 16
#تعریف_کرو DC_ORIENTATION 17
#تعریف_کرو DC_COPIES 18

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
