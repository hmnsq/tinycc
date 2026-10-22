/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _WINDEF_
#وصف_ڪريو _WINDEF_

#جيڪڏهن_وصف_نه_ٿيل STRICT
#وصف_ڪريو STRICT 1
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WINVER
#وصف_ڪريو WINVER 0x0502
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل BASETYPES
#وصف_ڪريو BASETYPES
  تعريفنوع بنانشان ڊگهو ULONG;
  تعريفنوع ULONG *PULONG;
  تعريفنوع بنانشان ننڍو USHORT;
  تعريفنوع USHORT *PUSHORT;
  تعريفنوع بنانشان حرف UCHAR;
  تعريفنوع UCHAR *PUCHAR;
  تعريفنوع حرف *PSZ;
#جيڪڏهن_پورو

#وصف_ڪريو MAX_رستو 260

#جيڪڏهن_وصف_نه_ٿيل عدم
#جيڪڏهن_وصف_ٿيل __cplusplus
#وصف_ڪريو عدم 0
#وإلا
#وصف_ڪريو عدم ((فراغ *)0)
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل FALSE
#وصف_ڪريو FALSE 0
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل TRUE
#وصف_ڪريو TRUE 1
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل اندريون_2
#وصف_ڪريو اندريون_2
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل ٻاهريون_2
#وصف_ڪريو ٻاهريون_2
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل OPTIONAL
#وصف_ڪريو OPTIONAL
#جيڪڏهن_پورو

#وصف_رد far
#وصف_رد near
#وصف_رد pascal

#وصف_ڪريو far
#وصف_ڪريو near
#وصف_ڪريو pascal __stdcall

#وصف_ڪريو cdecl
#جيڪڏهن_وصف_نه_ٿيل CDECL
#وصف_ڪريو CDECL
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل CALLBACK
#وصف_ڪريو CALLBACK __stdcall
#جيڪڏهن_پورو
#جيڪڏهن_وصف_نه_ٿيل WINAPI
#وصف_ڪريو WINAPI __stdcall
#جيڪڏهن_پورو
#وصف_ڪريو WINAPIV __cdecl
#وصف_ڪريو APIENTRY WINAPI
#وصف_ڪريو APIPRIVATE WINAPI
#وصف_ڪريو PASCAL WINAPI
#وصف_ڪريو WINAPI_INLINE WINAPI

#وصف_رد FAR
#وصف_رد NEAR
#وصف_ڪريو FAR
#وصف_ڪريو NEAR
#جيڪڏهن_وصف_نه_ٿيل CONST
#وصف_ڪريو CONST ثابت
#جيڪڏهن_پورو

  تعريفنوع بنانشان ڊگهو DWORD;
  تعريفنوع صحيح WINBOOL;
#وصف_ڪريو BOOL WINBOOL
  تعريفنوع بنانشان حرف BYTE;
  تعريفنوع بنانشان ننڍو لفظ_3;
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
  تعريفنوع ڊگهو *LPLONG;
  تعريفنوع DWORD *PDWORD;
  تعريفنوع DWORD *LPDWORD;
  تعريفنوع فراغ *LPVOID;
# ifndef _LPCVOID_DEFINED
#وصف_ڪريو _LPCVOID_DEFINED
تعريفنوع CONST فراغ *LPCVOID;
#جيڪڏهن_پورو
  تعريفنوع صحيح INT;
  تعريفنوع بنانشان صحيح UINT;
  تعريفنوع بنانشان صحيح *PUINT;

#جيڪڏهن_وصف_نه_ٿيل NT_INCLUDED
#ضمن <winnt.h>
#جيڪڏهن_پورو

//gr #include <specstrings.h>

  تعريفنوع UINT_PTR WPARAM;
  تعريفنوع LONG_PTR LPARAM;
  تعريفنوع LONG_PTR LRESULT;

#جيڪڏهن_وصف_نه_ٿيل __cplusplus
#جيڪڏهن_وصف_نه_ٿيل NOMINMAX
#جيڪڏهن_وصف_نه_ٿيل max
#وصف_ڪريو max(a,b) (((a) > (b)) ? (a) : (b))
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل min
#وصف_ڪريو min(a,b) (((a) < (b)) ? (a) : (b))
#جيڪڏهن_پورو
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو MAKEWORD(a,b) ((لفظ_3)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((لفظ_3)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#وصف_ڪريو MAKELONG(a,b) ((LONG)(((لفظ_3)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((لفظ_3)((DWORD_PTR)(b) & 0xffff))) << 16))
#وصف_ڪريو LOWORD(l) ((لفظ_3)((DWORD_PTR)(l) & 0xffff))
#وصف_ڪريو HIWORD(l) ((لفظ_3)((DWORD_PTR)(l) >> 16))
#وصف_ڪريو LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#وصف_ڪريو HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#جيڪڏهن_وصف_نه_ٿيل WIN_اندروني
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#جيڪڏهن_وصف_ٿيل WINABLE
  DECLARE_HANDLE (HEVENT);
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  تعريفنوع لفظ_3 ATOM;

  تعريفنوع HANDLE *SPHANDLE;
  تعريفنوع HANDLE *LPHANDLE;
  تعريفنوع HANDLE HGLOBAL;
  تعريفنوع HANDLE HLOCAL;
  تعريفنوع HANDLE GLOBALHANDLE;
  تعريفنوع HANDLE LOCALHANDLE;
#جيڪڏهن_وصف_ٿيل _WIN64
  تعريفنوع INT_PTR (WINAPI *FARPROC)();
  تعريفنوع INT_PTR (WINAPI *NEARPROC)();
  تعريفنوع INT_PTR (WINAPI *PROC)();
#وإلا
  تعريفنوع صحيح (WINAPI *FARPROC)();
  تعريفنوع صحيح (WINAPI *NEARPROC)();
  تعريفنوع صحيح (WINAPI *PROC)();
#جيڪڏهن_پورو

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

#وصف_ڪريو HFILE_ERROR ((HFILE)-1)

  تعريفنوع بنية ٽيگ_RECT {
    LONG کاٻو;
    LONG چوٽي;
    LONG ساڄو;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  تعريفنوع ثابت RECT *LPCRECT;

  تعريفنوع بنية _RECTL {
    LONG کاٻو;
    LONG چوٽي;
    LONG ساڄو;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  تعريفنوع ثابت RECTL *LPCRECTL;

  تعريفنوع بنية ٽيگ_نقطو {
    LONG x;
    LONG y;
  } نقطو_3,*PPOINT,*NPPOINT,*LPPOINT;

  تعريفنوع بنية _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  تعريفنوع بنية ٽيگ_سائيز {
    LONG cx;
    LONG cy;
  } سائيز_2,*PSIZE,*LPSIZE;

  تعريفنوع سائيز_2 SIZEL;
  تعريفنوع سائيز_2 *PSIZEL,*LPSIZEL;

  تعريفنوع بنية ٽيگ_POINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  تعريفنوع بنية _FILETIME {
    DWORD dw_هيٺيون_Date_وقت;
    DWORD dw_مٿاهون_Date_وقت;
  } FILETIME,*PFILETIME,*LPFILETIME;
#وصف_ڪريو _FILETIME_

#وصف_ڪريو DM_UPDATE 1
#وصف_ڪريو DM_COPY 2
#وصف_ڪريو DM_PROMPT 4
#وصف_ڪريو DM_MODIFY 8

#وصف_ڪريو DM_اندريون_بفر DM_MODIFY
#وصف_ڪريو DM_اندريون_PROMPT DM_PROMPT
#وصف_ڪريو DM_ٻاهريون_بفر DM_COPY
#وصف_ڪريو DM_ٻاهريون_DEFAULT DM_UPDATE

#وصف_ڪريو DC_FIELDS 1
#وصف_ڪريو DC_PAPERS 2
#وصف_ڪريو DC_PAPERSIZE 3
#وصف_ڪريو DC_MINEXTENT 4
#وصف_ڪريو DC_MAXEXTENT 5
#وصف_ڪريو DC_BINS 6
#وصف_ڪريو DC_DUPLEX 7
#وصف_ڪريو DC_سائيز 8
#وصف_ڪريو DC_EXTRA 9
#وصف_ڪريو DC_نسخو 10
#وصف_ڪريو DC_DRIVER 11
#وصف_ڪريو DC_BINNAMES 12
#وصف_ڪريو DC_ENUMRESOLUTIONS 13
#وصف_ڪريو DC_FILEDEPENDENCIES 14
#وصف_ڪريو DC_TRUETYPE 15
#وصف_ڪريو DC_PAPERNAMES 16
#وصف_ڪريو DC_ORIENTATION 17
#وصف_ڪريو DC_COPIES 18

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
