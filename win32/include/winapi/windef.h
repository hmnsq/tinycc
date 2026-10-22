/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _WINDEF_
#define _WINDEF_

#ifndef STRICT
#define STRICT 1
#endif

#ifdef __cplusplus
خارجي "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef BASETYPES
#define BASETYPES
  تعريفنوع unsigned long ULONG;
  تعريفنوع ULONG *PULONG;
  تعريفنوع unsigned short USHORT;
  تعريفنوع USHORT *PUSHORT;
  تعريفنوع unsigned حرف UCHAR;
  تعريفنوع UCHAR *PUCHAR;
  تعريفنوع حرف *PSZ;
#endif

#define MAX_PATH 260

#ifndef عدم
#ifdef __cplusplus
#define عدم 0
#ܐܚܪܢܐ
#define عدم ((فراغ *)0)
#endif
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif

#undef far
#undef near
#undef pascal

#define far
#define near
#define pascal __stdcall

#define cdecl
#ifndef CDECL
#define CDECL
#endif
#ifndef CALLBACK
#define CALLBACK __stdcall
#endif
#ifndef WINAPI
#define WINAPI __stdcall
#endif
#define WINAPIV __cdecl
#define APIENTRY WINAPI
#define APIPRIVATE WINAPI
#define PASCAL WINAPI
#define WINAPI_INLINE WINAPI

#undef FAR
#undef NEAR
#define FAR
#define NEAR
#ifndef CONST
#define CONST ثابت
#endif

  تعريفنوع unsigned long DWORD;
  تعريفنوع صحيح WINBOOL;
#define BOOL WINBOOL
  تعريفنوع unsigned حرف BYTE;
  تعريفنوع unsigned short WORD;
  تعريفنوع عائم FLOAT;
  تعريفنوع FLOAT *PFLOAT;
  تعريفنوع WINBOOL *PBOOL;
  تعريفنوع WINBOOL *LPBOOL;
  تعريفنوع BYTE *PBYTE;
  تعريفنوع BYTE *LPBYTE;
  تعريفنوع صحيح *PINT;
  تعريفنوع صحيح *LPINT;
  تعريفنوع WORD *PWORD;
  تعريفنوع WORD *LPWORD;
  تعريفنوع long *LPLONG;
  تعريفنوع DWORD *PDWORD;
  تعريفنوع DWORD *LPDWORD;
  تعريفنوع فراغ *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
تعريفنوع CONST فراغ *LPCVOID;
#endif
  تعريفنوع صحيح INT;
  تعريفنوع unsigned صحيح UINT;
  تعريفنوع unsigned صحيح *PUINT;

#ifndef NT_INCLUDED
#ضمن <winnt.h>
#endif

//gr #include <specstrings.h>

  تعريفنوع UINT_PTR WPARAM;
  تعريفنوع LONG_PTR LPARAM;
  تعريفنوع LONG_PTR LRESULT;

#ifndef __cplusplus
#ifndef NOMINMAX
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif
#endif
#endif

#define MAKEWORD(a,b) ((WORD)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((WORD)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#define MAKELONG(a,b) ((LONG)(((WORD)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((WORD)((DWORD_PTR)(b) & 0xffff))) << 16))
#define LOWORD(l) ((WORD)((DWORD_PTR)(l) & 0xffff))
#define HIWORD(l) ((WORD)((DWORD_PTR)(l) >> 16))
#define LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#define HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#ifndef WIN_INTERNAL
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#ifdef WINABLE
  DECLARE_HANDLE (HEVENT);
#endif
#endif

  تعريفنوع WORD ATOM;

  تعريفنوع HANDLE *SPHANDLE;
  تعريفنوع HANDLE *LPHANDLE;
  تعريفنوع HANDLE HGLOBAL;
  تعريفنوع HANDLE HLOCAL;
  تعريفنوع HANDLE GLOBALHANDLE;
  تعريفنوع HANDLE LOCALHANDLE;
#ifdef _WIN64
  تعريفنوع INT_PTR (WINAPI *FARPROC)();
  تعريفنوع INT_PTR (WINAPI *NEARPROC)();
  تعريفنوع INT_PTR (WINAPI *PROC)();
#ܐܚܪܢܐ
  تعريفنوع صحيح (WINAPI *FARPROC)();
  تعريفنوع صحيح (WINAPI *NEARPROC)();
  تعريفنوع صحيح (WINAPI *PROC)();
#endif

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

#define HFILE_ERROR ((HFILE)-1)

  تعريفنوع بنية tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  تعريفنوع ثابت RECT *LPCRECT;

  تعريفنوع بنية _RECTL {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  تعريفنوع ثابت RECTL *LPCRECTL;

  تعريفنوع بنية tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  تعريفنوع بنية _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  تعريفنوع بنية tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  تعريفنوع SIZE SIZEL;
  تعريفنوع SIZE *PSIZEL,*LPSIZEL;

  تعريفنوع بنية tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  تعريفنوع بنية _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
  } FILETIME,*PFILETIME,*LPFILETIME;
#define _FILETIME_

#define DM_UPDATE 1
#define DM_COPY 2
#define DM_PROMPT 4
#define DM_MODIFY 8

#define DM_IN_BUFFER DM_MODIFY
#define DM_IN_PROMPT DM_PROMPT
#define DM_OUT_BUFFER DM_COPY
#define DM_OUT_DEFAULT DM_UPDATE

#define DC_FIELDS 1
#define DC_PAPERS 2
#define DC_PAPERSIZE 3
#define DC_MINEXTENT 4
#define DC_MAXEXTENT 5
#define DC_BINS 6
#define DC_DUPLEX 7
#define DC_SIZE 8
#define DC_EXTRA 9
#define DC_VERSION 10
#define DC_DRIVER 11
#define DC_BINNAMES 12
#define DC_ENUMRESOLUTIONS 13
#define DC_FILEDEPENDENCIES 14
#define DC_TRUETYPE 15
#define DC_PAPERNAMES 16
#define DC_ORIENTATION 17
#define DC_COPIES 18

#ifdef __cplusplus
}
#endif
#endif
