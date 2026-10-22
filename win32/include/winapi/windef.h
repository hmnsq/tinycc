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
বাহ্য "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef BASETYPES
#define BASETYPES
  প্রকারনির্দেশ unsigned long ULONG;
  প্রকারনির্দেশ ULONG *PULONG;
  প্রকারনির্দেশ unsigned short USHORT;
  প্রকারনির্দেশ USHORT *PUSHORT;
  প্রকারনির্দেশ unsigned বর্ণ UCHAR;
  প্রকারনির্দেশ UCHAR *PUCHAR;
  প্রকারনির্দেশ বর্ণ *PSZ;
#endif

#define MAX_PATH 260

#ifndef রিক্ত
#ifdef __cplusplus
#define রিক্ত 0
#অন্যথা
#define রিক্ত ((শূন্য *)0)
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
#define CONST ধ্রুব
#endif

  প্রকারনির্দেশ unsigned long DWORD;
  প্রকারনির্দেশ পূর্ণাঙ্ক WINBOOL;
#define BOOL WINBOOL
  প্রকারনির্দেশ unsigned বর্ণ BYTE;
  প্রকারনির্দেশ unsigned short WORD;
  প্রকারনির্দেশ ভিন্ন FLOAT;
  প্রকারনির্দেশ FLOAT *PFLOAT;
  প্রকারনির্দেশ WINBOOL *PBOOL;
  প্রকারনির্দেশ WINBOOL *LPBOOL;
  প্রকারনির্দেশ BYTE *PBYTE;
  প্রকারনির্দেশ BYTE *LPBYTE;
  প্রকারনির্দেশ পূর্ণাঙ্ক *PINT;
  প্রকারনির্দেশ পূর্ণাঙ্ক *LPINT;
  প্রকারনির্দেশ WORD *PWORD;
  প্রকারনির্দেশ WORD *LPWORD;
  প্রকারনির্দেশ long *LPLONG;
  প্রকারনির্দেশ DWORD *PDWORD;
  প্রকারনির্দেশ DWORD *LPDWORD;
  প্রকারনির্দেশ শূন্য *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
প্রকারনির্দেশ CONST শূন্য *LPCVOID;
#endif
  প্রকারনির্দেশ পূর্ণাঙ্ক INT;
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক UINT;
  প্রকারনির্দেশ unsigned পূর্ণাঙ্ক *PUINT;

#ifndef NT_INCLUDED
#অন্তর্ভাব <winnt.h>
#endif

//gr #include <specstrings.h>

  প্রকারনির্দেশ UINT_PTR WPARAM;
  প্রকারনির্দেশ LONG_PTR LPARAM;
  প্রকারনির্দেশ LONG_PTR LRESULT;

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

  প্রকারনির্দেশ WORD ATOM;

  প্রকারনির্দেশ HANDLE *SPHANDLE;
  প্রকারনির্দেশ HANDLE *LPHANDLE;
  প্রকারনির্দেশ HANDLE HGLOBAL;
  প্রকারনির্দেশ HANDLE HLOCAL;
  প্রকারনির্দেশ HANDLE GLOBALHANDLE;
  প্রকারনির্দেশ HANDLE LOCALHANDLE;
#ifdef _WIN64
  প্রকারনির্দেশ INT_PTR (WINAPI *FARPROC)();
  প্রকারনির্দেশ INT_PTR (WINAPI *NEARPROC)();
  প্রকারনির্দেশ INT_PTR (WINAPI *PROC)();
#অন্যথা
  প্রকারনির্দেশ পূর্ণাঙ্ক (WINAPI *FARPROC)();
  প্রকারনির্দেশ পূর্ণাঙ্ক (WINAPI *NEARPROC)();
  প্রকারনির্দেশ পূর্ণাঙ্ক (WINAPI *PROC)();
#endif

  প্রকারনির্দেশ শূন্য *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  প্রকারনির্দেশ HKEY *PHKEY;

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
  প্রকারনির্দেশ HINSTANCE HMODULE;
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

  প্রকারনির্দেশ পূর্ণাঙ্ক HFILE;
  প্রকারনির্দেশ HICON HCURSOR;
  প্রকারনির্দেশ DWORD COLORREF;
  প্রকারনির্দেশ DWORD *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

  প্রকারনির্দেশ সংরচনা tagRECT {
    LONG বাম;
    LONG শীর্ষ;
    LONG ডান;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  প্রকারনির্দেশ ধ্রুব RECT *LPCRECT;

  প্রকারনির্দেশ সংরচনা _RECTL {
    LONG বাম;
    LONG শীর্ষ;
    LONG ডান;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  প্রকারনির্দেশ ধ্রুব RECTL *LPCRECTL;

  প্রকারনির্দেশ সংরচনা tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  প্রকারনির্দেশ সংরচনা _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  প্রকারনির্দেশ সংরচনা tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  প্রকারনির্দেশ SIZE SIZEL;
  প্রকারনির্দেশ SIZE *PSIZEL,*LPSIZEL;

  প্রকারনির্দেশ সংরচনা tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  প্রকারনির্দেশ সংরচনা _FILETIME {
    DWORD dw_নিচের_Date_Time;
    DWORD dw_উপরের_Date_Time;
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
