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
বাহ্যিক "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef BASETYPES
#define BASETYPES
  প্রকারলেখ unsigned long ULONG;
  প্রকারলেখ ULONG *PULONG;
  প্রকারলেখ unsigned short USHORT;
  প্রকারলেখ USHORT *PUSHORT;
  প্রকারলেখ unsigned অক্ষর UCHAR;
  প্রকারলেখ UCHAR *PUCHAR;
  প্রকারলেখ অক্ষর *PSZ;
#endif

#define MAX_PATH 260

#ifndef ফাঁকা
#ifdef __cplusplus
#define ফাঁকা 0
#অন্যথা
#define ফাঁকা ((শূন্য *)0)
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
#define CONST ধ্রুবক
#endif

  প্রকারলেখ unsigned long DWORD;
  প্রকারলেখ পূর্ণসংখ্যা WINBOOL;
#define BOOL WINBOOL
  প্রকারলেখ unsigned অক্ষর BYTE;
  প্রকারলেখ unsigned short WORD;
  প্রকারলেখ দশমিক FLOAT;
  প্রকারলেখ FLOAT *PFLOAT;
  প্রকারলেখ WINBOOL *PBOOL;
  প্রকারলেখ WINBOOL *LPBOOL;
  প্রকারলেখ BYTE *PBYTE;
  প্রকারলেখ BYTE *LPBYTE;
  প্রকারলেখ পূর্ণসংখ্যা *PINT;
  প্রকারলেখ পূর্ণসংখ্যা *LPINT;
  প্রকারলেখ WORD *PWORD;
  প্রকারলেখ WORD *LPWORD;
  প্রকারলেখ long *LPLONG;
  প্রকারলেখ DWORD *PDWORD;
  প্রকারলেখ DWORD *LPDWORD;
  প্রকারলেখ শূন্য *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
প্রকারলেখ CONST শূন্য *LPCVOID;
#endif
  প্রকারলেখ পূর্ণসংখ্যা INT;
  প্রকারলেখ unsigned পূর্ণসংখ্যা UINT;
  প্রকারলেখ unsigned পূর্ণসংখ্যা *PUINT;

#ifndef NT_INCLUDED
#অন্তর্ভাব <winnt.h>
#endif

//gr #include <specstrings.h>

  প্রকারলেখ UINT_PTR WPARAM;
  প্রকারলেখ LONG_PTR LPARAM;
  প্রকারলেখ LONG_PTR LRESULT;

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

  প্রকারলেখ WORD ATOM;

  প্রকারলেখ HANDLE *SPHANDLE;
  প্রকারলেখ HANDLE *LPHANDLE;
  প্রকারলেখ HANDLE HGLOBAL;
  প্রকারলেখ HANDLE HLOCAL;
  প্রকারলেখ HANDLE GLOBALHANDLE;
  প্রকারলেখ HANDLE LOCALHANDLE;
#ifdef _WIN64
  প্রকারলেখ INT_PTR (WINAPI *FARPROC)();
  প্রকারলেখ INT_PTR (WINAPI *NEARPROC)();
  প্রকারলেখ INT_PTR (WINAPI *PROC)();
#অন্যথা
  প্রকারলেখ পূর্ণসংখ্যা (WINAPI *FARPROC)();
  প্রকারলেখ পূর্ণসংখ্যা (WINAPI *NEARPROC)();
  প্রকারলেখ পূর্ণসংখ্যা (WINAPI *PROC)();
#endif

  প্রকারলেখ শূন্য *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  প্রকারলেখ HKEY *PHKEY;

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
  প্রকারলেখ HINSTANCE HMODULE;
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

  প্রকারলেখ পূর্ণসংখ্যা HFILE;
  প্রকারলেখ HICON HCURSOR;
  প্রকারলেখ DWORD COLORREF;
  প্রকারলেখ DWORD *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

  প্রকারলেখ কাঠামো tagRECT {
    LONG বাম;
    LONG শীর্ষ;
    LONG ডান;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  প্রকারলেখ ধ্রুবক RECT *LPCRECT;

  প্রকারলেখ কাঠামো _RECTL {
    LONG বাম;
    LONG শীর্ষ;
    LONG ডান;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  প্রকারলেখ ধ্রুবক RECTL *LPCRECTL;

  প্রকারলেখ কাঠামো tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  প্রকারলেখ কাঠামো _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  প্রকারলেখ কাঠামো tag_আকার {
    LONG cx;
    LONG cy;
  } আকার_3,*PSIZE,*LPSIZE;

  প্রকারলেখ আকার_3 SIZEL;
  প্রকারলেখ আকার_3 *PSIZEL,*LPSIZEL;

  প্রকারলেখ কাঠামো tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  প্রকারলেখ কাঠামো _FILETIME {
    DWORD dw_নিচের_Date_Time;
    DWORD dw_উপরের_Date_Time;
  } FILETIME,*PFILETIME,*LPFILETIME;
#define _FILETIME_

#define DM_UPDATE 1
#define DM_COPY 2
#define DM_PROMPT 4
#define DM_MODIFY 8

#define DM_IN_বাফার DM_MODIFY
#define DM_IN_PROMPT DM_PROMPT
#define DM_OUT_বাফার DM_COPY
#define DM_OUT_DEFAULT DM_UPDATE

#define DC_FIELDS 1
#define DC_PAPERS 2
#define DC_PAPERSIZE 3
#define DC_MINEXTENT 4
#define DC_MAXEXTENT 5
#define DC_BINS 6
#define DC_DUPLEX 7
#define DC_আকার 8
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
