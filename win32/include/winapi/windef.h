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
બાહ્ય "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef BASETYPES
#define BASETYPES
  પ્રકારવ્યાખ્યા unsigned long ULONG;
  પ્રકારવ્યાખ્યા ULONG *PULONG;
  પ્રકારવ્યાખ્યા unsigned short USHORT;
  પ્રકારવ્યાખ્યા USHORT *PUSHORT;
  પ્રકારવ્યાખ્યા unsigned અક્ષર UCHAR;
  પ્રકારવ્યાખ્યા UCHAR *PUCHAR;
  પ્રકારવ્યાખ્યા અક્ષર *PSZ;
#endif

#define MAX_PATH 260

#ifndef ખાલી
#ifdef __cplusplus
#define ખાલી 0
#નહીંતર
#define ખાલી ((શૂન્ય *)0)
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
#define CONST અચલ
#endif

  પ્રકારવ્યાખ્યા unsigned long DWORD;
  પ્રકારવ્યાખ્યા પૂર્ણાંક WINBOOL;
#define BOOL WINBOOL
  પ્રકારવ્યાખ્યા unsigned અક્ષર BYTE;
  પ્રકારવ્યાખ્યા unsigned short WORD;
  પ્રકારવ્યાખ્યા દશાંશ FLOAT;
  પ્રકારવ્યાખ્યા FLOAT *PFLOAT;
  પ્રકારવ્યાખ્યા WINBOOL *PBOOL;
  પ્રકારવ્યાખ્યા WINBOOL *LPBOOL;
  પ્રકારવ્યાખ્યા BYTE *PBYTE;
  પ્રકારવ્યાખ્યા BYTE *LPBYTE;
  પ્રકારવ્યાખ્યા પૂર્ણાંક *PINT;
  પ્રકારવ્યાખ્યા પૂર્ણાંક *LPINT;
  પ્રકારવ્યાખ્યા WORD *PWORD;
  પ્રકારવ્યાખ્યા WORD *LPWORD;
  પ્રકારવ્યાખ્યા long *LPLONG;
  પ્રકારવ્યાખ્યા DWORD *PDWORD;
  પ્રકારવ્યાખ્યા DWORD *LPDWORD;
  પ્રકારવ્યાખ્યા શૂન્ય *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
પ્રકારવ્યાખ્યા CONST શૂન્ય *LPCVOID;
#endif
  પ્રકારવ્યાખ્યા પૂર્ણાંક INT;
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક UINT;
  પ્રકારવ્યાખ્યા unsigned પૂર્ણાંક *PUINT;

#ifndef NT_INCLUDED
#અન્તર્ભાવ <winnt.h>
#endif

//gr #include <specstrings.h>

  પ્રકારવ્યાખ્યા UINT_PTR WPARAM;
  પ્રકારવ્યાખ્યા LONG_PTR LPARAM;
  પ્રકારવ્યાખ્યા LONG_PTR LRESULT;

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

  પ્રકારવ્યાખ્યા WORD ATOM;

  પ્રકારવ્યાખ્યા HANDLE *SPHANDLE;
  પ્રકારવ્યાખ્યા HANDLE *LPHANDLE;
  પ્રકારવ્યાખ્યા HANDLE HGLOBAL;
  પ્રકારવ્યાખ્યા HANDLE HLOCAL;
  પ્રકારવ્યાખ્યા HANDLE GLOBALHANDLE;
  પ્રકારવ્યાખ્યા HANDLE LOCALHANDLE;
#ifdef _WIN64
  પ્રકારવ્યાખ્યા INT_PTR (WINAPI *FARPROC)();
  પ્રકારવ્યાખ્યા INT_PTR (WINAPI *NEARPROC)();
  પ્રકારવ્યાખ્યા INT_PTR (WINAPI *PROC)();
#નહીંતર
  પ્રકારવ્યાખ્યા પૂર્ણાંક (WINAPI *FARPROC)();
  પ્રકારવ્યાખ્યા પૂર્ણાંક (WINAPI *NEARPROC)();
  પ્રકારવ્યાખ્યા પૂર્ણાંક (WINAPI *PROC)();
#endif

  પ્રકારવ્યાખ્યા શૂન્ય *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  પ્રકારવ્યાખ્યા HKEY *PHKEY;

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
  પ્રકારવ્યાખ્યા HINSTANCE HMODULE;
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

  પ્રકારવ્યાખ્યા પૂર્ણાંક HFILE;
  પ્રકારવ્યાખ્યા HICON HCURSOR;
  પ્રકારવ્યાખ્યા DWORD COLORREF;
  પ્રકારવ્યાખ્યા DWORD *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

  પ્રકારવ્યાખ્યા સંરચના tagRECT {
    LONG ડાબું;
    LONG ટોચ;
    LONG જમણું;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  પ્રકારવ્યાખ્યા અચલ RECT *LPCRECT;

  પ્રકારવ્યાખ્યા સંરચના _RECTL {
    LONG ડાબું;
    LONG ટોચ;
    LONG જમણું;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  પ્રકારવ્યાખ્યા અચલ RECTL *LPCRECTL;

  પ્રકારવ્યાખ્યા સંરચના tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  પ્રકારવ્યાખ્યા સંરચના _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  પ્રકારવ્યાખ્યા સંરચના tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  પ્રકારવ્યાખ્યા SIZE SIZEL;
  પ્રકારવ્યાખ્યા SIZE *PSIZEL,*LPSIZEL;

  પ્રકારવ્યાખ્યા સંરચના tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  પ્રકારવ્યાખ્યા સંરચના _FILETIME {
    DWORD dw_નીચલું_Date_Time;
    DWORD dw_ઉપલું_Date_Time;
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
