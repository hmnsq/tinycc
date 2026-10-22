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
ବାହ୍ୟ "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef BASETYPES
#define BASETYPES
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned long ULONG;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ULONG *PULONG;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short USHORT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା USHORT *PUSHORT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ଅକ୍ଷର UCHAR;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା UCHAR *PUCHAR;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅକ୍ଷର *PSZ;
#endif

#define MAX_PATH 260

#ifndef ଖାଲି
#ifdef __cplusplus
#define ଖାଲି 0
#ଅନ୍ୟଥା
#define ଖାଲି ((ଶୂନ୍ୟ *)0)
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
#define CONST ଅଚଳ
#endif

  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned long DWORD;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା WINBOOL;
#define BOOL WINBOOL
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ଅକ୍ଷର BYTE;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned short WORD;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଦଶମିକ FLOAT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା FLOAT *PFLOAT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା WINBOOL *PBOOL;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା WINBOOL *LPBOOL;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା BYTE *PBYTE;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା BYTE *LPBYTE;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା *PINT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା *LPINT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା WORD *PWORD;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା WORD *LPWORD;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା long *LPLONG;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା DWORD *PDWORD;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା DWORD *LPDWORD;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
ପ୍ରକାରବ୍ୟାଖ୍ୟା CONST ଶୂନ୍ୟ *LPCVOID;
#endif
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା INT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା UINT;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା unsigned ପୂର୍ଣ୍ଣସଂଖ୍ୟା *PUINT;

#ifndef NT_INCLUDED
#ଅନ୍ତର୍ଭାଵ <winnt.h>
#endif

//gr #include <specstrings.h>

  ପ୍ରକାରବ୍ୟାଖ୍ୟା UINT_PTR WPARAM;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା LONG_PTR LPARAM;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା LONG_PTR LRESULT;

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

  ପ୍ରକାରବ୍ୟାଖ୍ୟା WORD ATOM;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା HANDLE *SPHANDLE;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା HANDLE *LPHANDLE;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା HANDLE HGLOBAL;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା HANDLE HLOCAL;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା HANDLE GLOBALHANDLE;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା HANDLE LOCALHANDLE;
#ifdef _WIN64
  ପ୍ରକାରବ୍ୟାଖ୍ୟା INT_PTR (WINAPI *FARPROC)();
  ପ୍ରକାରବ୍ୟାଖ୍ୟା INT_PTR (WINAPI *NEARPROC)();
  ପ୍ରକାରବ୍ୟାଖ୍ୟା INT_PTR (WINAPI *PROC)();
#ଅନ୍ୟଥା
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା (WINAPI *FARPROC)();
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା (WINAPI *NEARPROC)();
  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା (WINAPI *PROC)();
#endif

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  ପ୍ରକାରବ୍ୟାଖ୍ୟା HKEY *PHKEY;

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
  ପ୍ରକାରବ୍ୟାଖ୍ୟା HINSTANCE HMODULE;
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

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା HFILE;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା HICON HCURSOR;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା DWORD COLORREF;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା DWORD *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା tagRECT {
    LONG ବାମ;
    LONG ଶୀର୍ଷ;
    LONG ଡାହାଣ;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅଚଳ RECT *LPCRECT;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _RECTL {
    LONG ବାମ;
    LONG ଶୀର୍ଷ;
    LONG ଡାହାଣ;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ଅଚଳ RECTL *LPCRECTL;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା SIZE SIZEL;
  ପ୍ରକାରବ୍ୟାଖ୍ୟା SIZE *PSIZEL,*LPSIZEL;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା _FILETIME {
    DWORD dw_ତଳ_Date_Time;
    DWORD dw_ଉପର_Date_Time;
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
