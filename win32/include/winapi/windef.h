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
வெளி "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef BASETYPES
#define BASETYPES
  வகைவரை unsigned long ULONG;
  வகைவரை ULONG *PULONG;
  வகைவரை unsigned short USHORT;
  வகைவரை USHORT *PUSHORT;
  வகைவரை unsigned எழுத்து UCHAR;
  வகைவரை UCHAR *PUCHAR;
  வகைவரை எழுத்து *PSZ;
#endif

#define MAX_PATH 260

#ifndef வெற்று
#ifdef __cplusplus
#define வெற்று 0
#இல்லையெனில்
#define வெற்று ((வெறுமை *)0)
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
#define CONST மாறிலி
#endif

  வகைவரை unsigned long DWORD;
  வகைவரை முழு WINBOOL;
#define BOOL WINBOOL
  வகைவரை unsigned எழுத்து BYTE;
  வகைவரை unsigned short WORD;
  வகைவரை தசம FLOAT;
  வகைவரை FLOAT *PFLOAT;
  வகைவரை WINBOOL *PBOOL;
  வகைவரை WINBOOL *LPBOOL;
  வகைவரை BYTE *PBYTE;
  வகைவரை BYTE *LPBYTE;
  வகைவரை முழு *PINT;
  வகைவரை முழு *LPINT;
  வகைவரை WORD *PWORD;
  வகைவரை WORD *LPWORD;
  வகைவரை long *LPLONG;
  வகைவரை DWORD *PDWORD;
  வகைவரை DWORD *LPDWORD;
  வகைவரை வெறுமை *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
வகைவரை CONST வெறுமை *LPCVOID;
#endif
  வகைவரை முழு INT;
  வகைவரை unsigned முழு UINT;
  வகைவரை unsigned முழு *PUINT;

#ifndef NT_INCLUDED
#அந்தர்பாவ <winnt.h>
#endif

//gr #include <specstrings.h>

  வகைவரை UINT_PTR WPARAM;
  வகைவரை LONG_PTR LPARAM;
  வகைவரை LONG_PTR LRESULT;

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

  வகைவரை WORD ATOM;

  வகைவரை HANDLE *SPHANDLE;
  வகைவரை HANDLE *LPHANDLE;
  வகைவரை HANDLE HGLOBAL;
  வகைவரை HANDLE HLOCAL;
  வகைவரை HANDLE GLOBALHANDLE;
  வகைவரை HANDLE LOCALHANDLE;
#ifdef _WIN64
  வகைவரை INT_PTR (WINAPI *FARPROC)();
  வகைவரை INT_PTR (WINAPI *NEARPROC)();
  வகைவரை INT_PTR (WINAPI *PROC)();
#இல்லையெனில்
  வகைவரை முழு (WINAPI *FARPROC)();
  வகைவரை முழு (WINAPI *NEARPROC)();
  வகைவரை முழு (WINAPI *PROC)();
#endif

  வகைவரை வெறுமை *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  வகைவரை HKEY *PHKEY;

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
  வகைவரை HINSTANCE HMODULE;
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

  வகைவரை முழு HFILE;
  வகைவரை HICON HCURSOR;
  வகைவரை DWORD COLORREF;
  வகைவரை DWORD *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

  வகைவரை கட்டமைப்பு tagRECT {
    LONG இடது;
    LONG உச்சி;
    LONG வலது;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  வகைவரை மாறிலி RECT *LPCRECT;

  வகைவரை கட்டமைப்பு _RECTL {
    LONG இடது;
    LONG உச்சி;
    LONG வலது;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  வகைவரை மாறிலி RECTL *LPCRECTL;

  வகைவரை கட்டமைப்பு tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  வகைவரை கட்டமைப்பு _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  வகைவரை கட்டமைப்பு tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  வகைவரை SIZE SIZEL;
  வகைவரை SIZE *PSIZEL,*LPSIZEL;

  வகைவரை கட்டமைப்பு tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  வகைவரை கட்டமைப்பு _FILETIME {
    DWORD dw_கீழ்_Date_Time;
    DWORD dw_உயர்வு_Date_Time;
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
