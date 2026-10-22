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
ಬಾಹ್ಯ "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef BASETYPES
#define BASETYPES
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long ULONG;
  ಪ್ರಕಾರನಿರ್ದೇಶ ULONG *PULONG;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short USHORT;
  ಪ್ರಕಾರನಿರ್ದೇಶ USHORT *PUSHORT;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ವರ್ಣ UCHAR;
  ಪ್ರಕಾರನಿರ್ದೇಶ UCHAR *PUCHAR;
  ಪ್ರಕಾರನಿರ್ದೇಶ ವರ್ಣ *PSZ;
#endif

#define MAX_PATH 260

#ifndef ರಿಕ್ತ
#ifdef __cplusplus
#define ರಿಕ್ತ 0
#ಅನ್ಯಥಾ
#define ರಿಕ್ತ ((ಶೂನ್ಯ *)0)
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
#define CONST ಧ್ರುವ
#endif

  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned long DWORD;
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ WINBOOL;
#define BOOL WINBOOL
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ವರ್ಣ BYTE;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned short WORD;
  ಪ್ರಕಾರನಿರ್ದೇಶ ಭಿನ್ನ FLOAT;
  ಪ್ರಕಾರನಿರ್ದೇಶ FLOAT *PFLOAT;
  ಪ್ರಕಾರನಿರ್ದೇಶ WINBOOL *PBOOL;
  ಪ್ರಕಾರನಿರ್ದೇಶ WINBOOL *LPBOOL;
  ಪ್ರಕಾರನಿರ್ದೇಶ BYTE *PBYTE;
  ಪ್ರಕಾರನಿರ್ದೇಶ BYTE *LPBYTE;
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ *PINT;
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ *LPINT;
  ಪ್ರಕಾರನಿರ್ದೇಶ WORD *PWORD;
  ಪ್ರಕಾರನಿರ್ದೇಶ WORD *LPWORD;
  ಪ್ರಕಾರನಿರ್ದೇಶ long *LPLONG;
  ಪ್ರಕಾರನಿರ್ದೇಶ DWORD *PDWORD;
  ಪ್ರಕಾರನಿರ್ದೇಶ DWORD *LPDWORD;
  ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
ಪ್ರಕಾರನಿರ್ದೇಶ CONST ಶೂನ್ಯ *LPCVOID;
#endif
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ INT;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ UINT;
  ಪ್ರಕಾರನಿರ್ದೇಶ unsigned ಪೂರ್ಣಾಙ್ಕ *PUINT;

#ifndef NT_INCLUDED
#ಅನ್ತರ್ಭಾವ <winnt.h>
#endif

//gr #include <specstrings.h>

  ಪ್ರಕಾರನಿರ್ದೇಶ UINT_PTR WPARAM;
  ಪ್ರಕಾರನಿರ್ದೇಶ LONG_PTR LPARAM;
  ಪ್ರಕಾರನಿರ್ದೇಶ LONG_PTR LRESULT;

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

  ಪ್ರಕಾರನಿರ್ದೇಶ WORD ATOM;

  ಪ್ರಕಾರನಿರ್ದೇಶ HANDLE *SPHANDLE;
  ಪ್ರಕಾರನಿರ್ದೇಶ HANDLE *LPHANDLE;
  ಪ್ರಕಾರನಿರ್ದೇಶ HANDLE HGLOBAL;
  ಪ್ರಕಾರನಿರ್ದೇಶ HANDLE HLOCAL;
  ಪ್ರಕಾರನಿರ್ದೇಶ HANDLE GLOBALHANDLE;
  ಪ್ರಕಾರನಿರ್ದೇಶ HANDLE LOCALHANDLE;
#ifdef _WIN64
  ಪ್ರಕಾರನಿರ್ದೇಶ INT_PTR (WINAPI *FARPROC)();
  ಪ್ರಕಾರನಿರ್ದೇಶ INT_PTR (WINAPI *NEARPROC)();
  ಪ್ರಕಾರನಿರ್ದೇಶ INT_PTR (WINAPI *PROC)();
#ಅನ್ಯಥಾ
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (WINAPI *FARPROC)();
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (WINAPI *NEARPROC)();
  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ (WINAPI *PROC)();
#endif

  ಪ್ರಕಾರನಿರ್ದೇಶ ಶೂನ್ಯ *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  ಪ್ರಕಾರನಿರ್ದೇಶ HKEY *PHKEY;

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
  ಪ್ರಕಾರನಿರ್ದೇಶ HINSTANCE HMODULE;
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

  ಪ್ರಕಾರನಿರ್ದೇಶ ಪೂರ್ಣಾಙ್ಕ HFILE;
  ಪ್ರಕಾರನಿರ್ದೇಶ HICON HCURSOR;
  ಪ್ರಕಾರನಿರ್ದೇಶ DWORD COLORREF;
  ಪ್ರಕಾರನಿರ್ದೇಶ DWORD *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ tagRECT {
    LONG ಎಡ;
    LONG ತುದಿ;
    LONG ಬಲ;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಧ್ರುವ RECT *LPCRECT;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _RECTL {
    LONG ಎಡ;
    LONG ತುದಿ;
    LONG ಬಲ;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಧ್ರುವ RECTL *LPCRECTL;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  ಪ್ರಕಾರನಿರ್ದೇಶ SIZE SIZEL;
  ಪ್ರಕಾರನಿರ್ದೇಶ SIZE *PSIZEL,*LPSIZEL;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ _FILETIME {
    DWORD dw_ಕೆಳಗಿನ_Date_Time;
    DWORD dw_ಮೇಲಿನ_Date_Time;
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
