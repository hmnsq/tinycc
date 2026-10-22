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
बाह्य "C" {
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef BASETYPES
#define BASETYPES
  प्रकारनिर्देश unsigned long ULONG;
  प्रकारनिर्देश ULONG *PULONG;
  प्रकारनिर्देश unsigned short USHORT;
  प्रकारनिर्देश USHORT *PUSHORT;
  प्रकारनिर्देश unsigned वर्ण UCHAR;
  प्रकारनिर्देश UCHAR *PUCHAR;
  प्रकारनिर्देश वर्ण *PSZ;
#endif

#define MAX_PATH 260

#ifndef रिक्त
#ifdef __cplusplus
#define रिक्त 0
#अन्यथा
#define रिक्त ((शून्य *)0)
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
#define CONST ध्रुव
#endif

  प्रकारनिर्देश unsigned long DWORD;
  प्रकारनिर्देश पूर्णाङ्क WINBOOL;
#define BOOL WINBOOL
  प्रकारनिर्देश unsigned वर्ण BYTE;
  प्रकारनिर्देश unsigned short WORD;
  प्रकारनिर्देश भिन्न FLOAT;
  प्रकारनिर्देश FLOAT *PFLOAT;
  प्रकारनिर्देश WINBOOL *PBOOL;
  प्रकारनिर्देश WINBOOL *LPBOOL;
  प्रकारनिर्देश BYTE *PBYTE;
  प्रकारनिर्देश BYTE *LPBYTE;
  प्रकारनिर्देश पूर्णाङ्क *PINT;
  प्रकारनिर्देश पूर्णाङ्क *LPINT;
  प्रकारनिर्देश WORD *PWORD;
  प्रकारनिर्देश WORD *LPWORD;
  प्रकारनिर्देश long *LPLONG;
  प्रकारनिर्देश DWORD *PDWORD;
  प्रकारनिर्देश DWORD *LPDWORD;
  प्रकारनिर्देश शून्य *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
प्रकारनिर्देश CONST शून्य *LPCVOID;
#endif
  प्रकारनिर्देश पूर्णाङ्क INT;
  प्रकारनिर्देश unsigned पूर्णाङ्क UINT;
  प्रकारनिर्देश unsigned पूर्णाङ्क *PUINT;

#ifndef NT_INCLUDED
#अन्तर्भाव <winnt.h>
#endif

//gr #include <specstrings.h>

  प्रकारनिर्देश UINT_PTR WPARAM;
  प्रकारनिर्देश LONG_PTR LPARAM;
  प्रकारनिर्देश LONG_PTR LRESULT;

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

  प्रकारनिर्देश WORD ATOM;

  प्रकारनिर्देश HANDLE *SPHANDLE;
  प्रकारनिर्देश HANDLE *LPHANDLE;
  प्रकारनिर्देश HANDLE HGLOBAL;
  प्रकारनिर्देश HANDLE HLOCAL;
  प्रकारनिर्देश HANDLE GLOBALHANDLE;
  प्रकारनिर्देश HANDLE LOCALHANDLE;
#ifdef _WIN64
  प्रकारनिर्देश INT_PTR (WINAPI *FARPROC)();
  प्रकारनिर्देश INT_PTR (WINAPI *NEARPROC)();
  प्रकारनिर्देश INT_PTR (WINAPI *PROC)();
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क (WINAPI *FARPROC)();
  प्रकारनिर्देश पूर्णाङ्क (WINAPI *NEARPROC)();
  प्रकारनिर्देश पूर्णाङ्क (WINAPI *PROC)();
#endif

  प्रकारनिर्देश शून्य *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  प्रकारनिर्देश HKEY *PHKEY;

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
  प्रकारनिर्देश HINSTANCE HMODULE;
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

  प्रकारनिर्देश पूर्णाङ्क HFILE;
  प्रकारनिर्देश HICON HCURSOR;
  प्रकारनिर्देश DWORD COLORREF;
  प्रकारनिर्देश DWORD *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

  प्रकारनिर्देश संरचना tagRECT {
    LONG बायाँ;
    LONG शीर्ष;
    LONG दायाँ;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  प्रकारनिर्देश ध्रुव RECT *LPCRECT;

  प्रकारनिर्देश संरचना _RECTL {
    LONG बायाँ;
    LONG शीर्ष;
    LONG दायाँ;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  प्रकारनिर्देश ध्रुव RECTL *LPCRECTL;

  प्रकारनिर्देश संरचना tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  प्रकारनिर्देश संरचना _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  प्रकारनिर्देश संरचना tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  प्रकारनिर्देश SIZE SIZEL;
  प्रकारनिर्देश SIZE *PSIZEL,*LPSIZEL;

  प्रकारनिर्देश संरचना tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  प्रकारनिर्देश संरचना _FILETIME {
    DWORD dw_निचला_Date_Time;
    DWORD dw_ऊपरी_Date_Time;
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
