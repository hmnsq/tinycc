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
ബാഹ്യ "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef BASETYPES
#define BASETYPES
  തരനിർവചനം unsigned long ULONG;
  തരനിർവചനം ULONG *PULONG;
  തരനിർവചനം unsigned short USHORT;
  തരനിർവചനം USHORT *PUSHORT;
  തരനിർവചനം unsigned അക്ഷരം UCHAR;
  തരനിർവചനം UCHAR *PUCHAR;
  തരനിർവചനം അക്ഷരം *PSZ;
#endif

#define MAX_PATH 260

#ifndef ശൂന്യ
#ifdef __cplusplus
#define ശൂന്യ 0
#അല്ലെങ്കിൽ
#define ശൂന്യ ((ശൂന്യം *)0)
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
#define CONST സ്ഥിരം
#endif

  തരനിർവചനം unsigned long DWORD;
  തരനിർവചനം പൂർണ്ണസംഖ്യ WINBOOL;
#define BOOL WINBOOL
  തരനിർവചനം unsigned അക്ഷരം BYTE;
  തരനിർവചനം unsigned short WORD;
  തരനിർവചനം ദശാംശം FLOAT;
  തരനിർവചനം FLOAT *PFLOAT;
  തരനിർവചനം WINBOOL *PBOOL;
  തരനിർവചനം WINBOOL *LPBOOL;
  തരനിർവചനം BYTE *PBYTE;
  തരനിർവചനം BYTE *LPBYTE;
  തരനിർവചനം പൂർണ്ണസംഖ്യ *PINT;
  തരനിർവചനം പൂർണ്ണസംഖ്യ *LPINT;
  തരനിർവചനം WORD *PWORD;
  തരനിർവചനം WORD *LPWORD;
  തരനിർവചനം long *LPLONG;
  തരനിർവചനം DWORD *PDWORD;
  തരനിർവചനം DWORD *LPDWORD;
  തരനിർവചനം ശൂന്യം *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
തരനിർവചനം CONST ശൂന്യം *LPCVOID;
#endif
  തരനിർവചനം പൂർണ്ണസംഖ്യ INT;
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ UINT;
  തരനിർവചനം unsigned പൂർണ്ണസംഖ്യ *PUINT;

#ifndef NT_INCLUDED
#അന്തര്ഭാവ <winnt.h>
#endif

//gr #include <specstrings.h>

  തരനിർവചനം UINT_PTR WPARAM;
  തരനിർവചനം LONG_PTR LPARAM;
  തരനിർവചനം LONG_PTR LRESULT;

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

  തരനിർവചനം WORD ATOM;

  തരനിർവചനം HANDLE *SPHANDLE;
  തരനിർവചനം HANDLE *LPHANDLE;
  തരനിർവചനം HANDLE HGLOBAL;
  തരനിർവചനം HANDLE HLOCAL;
  തരനിർവചനം HANDLE GLOBALHANDLE;
  തരനിർവചനം HANDLE LOCALHANDLE;
#ifdef _WIN64
  തരനിർവചനം INT_PTR (WINAPI *FARPROC)();
  തരനിർവചനം INT_PTR (WINAPI *NEARPROC)();
  തരനിർവചനം INT_PTR (WINAPI *PROC)();
#അല്ലെങ്കിൽ
  തരനിർവചനം പൂർണ്ണസംഖ്യ (WINAPI *FARPROC)();
  തരനിർവചനം പൂർണ്ണസംഖ്യ (WINAPI *NEARPROC)();
  തരനിർവചനം പൂർണ്ണസംഖ്യ (WINAPI *PROC)();
#endif

  തരനിർവചനം ശൂന്യം *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  തരനിർവചനം HKEY *PHKEY;

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
  തരനിർവചനം HINSTANCE HMODULE;
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

  തരനിർവചനം പൂർണ്ണസംഖ്യ HFILE;
  തരനിർവചനം HICON HCURSOR;
  തരനിർവചനം DWORD COLORREF;
  തരനിർവചനം DWORD *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

  തരനിർവചനം ഘടന tagRECT {
    LONG ഇടത്;
    LONG മുകൾ;
    LONG വലത്;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  തരനിർവചനം സ്ഥിരം RECT *LPCRECT;

  തരനിർവചനം ഘടന _RECTL {
    LONG ഇടത്;
    LONG മുകൾ;
    LONG വലത്;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  തരനിർവചനം സ്ഥിരം RECTL *LPCRECTL;

  തരനിർവചനം ഘടന tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  തരനിർവചനം ഘടന _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  തരനിർവചനം ഘടന tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  തരനിർവചനം SIZE SIZEL;
  തരനിർവചനം SIZE *PSIZEL,*LPSIZEL;

  തരനിർവചനം ഘടന tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  തരനിർവചനം ഘടന _FILETIME {
    DWORD dw_താഴെയുള്ള_Date_Time;
    DWORD dw_മുകളിലെ_Date_Time;
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
