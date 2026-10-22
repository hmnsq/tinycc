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
  प्रकारव्याख्या अचिन्हित दीर्घ ULONG;
  प्रकारव्याख्या ULONG *PULONG;
  प्रकारव्याख्या अचिन्हित लघु USHORT;
  प्रकारव्याख्या USHORT *PUSHORT;
  प्रकारव्याख्या अचिन्हित अक्षर UCHAR;
  प्रकारव्याख्या UCHAR *PUCHAR;
  प्रकारव्याख्या अक्षर *PSZ;
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
#define CONST स्थिरांक
#endif

  प्रकारव्याख्या अचिन्हित दीर्घ DWORD;
  प्रकारव्याख्या पूर्णांक WINBOOL;
#define BOOL WINBOOL
  प्रकारव्याख्या अचिन्हित अक्षर BYTE;
  प्रकारव्याख्या अचिन्हित लघु WORD;
  प्रकारव्याख्या दशांश FLOAT;
  प्रकारव्याख्या FLOAT *PFLOAT;
  प्रकारव्याख्या WINBOOL *PBOOL;
  प्रकारव्याख्या WINBOOL *LPBOOL;
  प्रकारव्याख्या BYTE *PBYTE;
  प्रकारव्याख्या BYTE *LPBYTE;
  प्रकारव्याख्या पूर्णांक *PINT;
  प्रकारव्याख्या पूर्णांक *LPINT;
  प्रकारव्याख्या WORD *PWORD;
  प्रकारव्याख्या WORD *LPWORD;
  प्रकारव्याख्या दीर्घ *LPLONG;
  प्रकारव्याख्या DWORD *PDWORD;
  प्रकारव्याख्या DWORD *LPDWORD;
  प्रकारव्याख्या शून्य *LPVOID;
# ifndef _LPCVOID_DEFINED
#define _LPCVOID_DEFINED
प्रकारव्याख्या CONST शून्य *LPCVOID;
#endif
  प्रकारव्याख्या पूर्णांक INT;
  प्रकारव्याख्या अचिन्हित पूर्णांक UINT;
  प्रकारव्याख्या अचिन्हित पूर्णांक *PUINT;

#ifndef NT_INCLUDED
#अन्तर्भाव <winnt.h>
#endif

//gr #include <specstrings.h>

  प्रकारव्याख्या UINT_PTR WPARAM;
  प्रकारव्याख्या LONG_PTR LPARAM;
  प्रकारव्याख्या LONG_PTR LRESULT;

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

  प्रकारव्याख्या WORD ATOM;

  प्रकारव्याख्या HANDLE *SPHANDLE;
  प्रकारव्याख्या HANDLE *LPHANDLE;
  प्रकारव्याख्या HANDLE HGLOBAL;
  प्रकारव्याख्या HANDLE HLOCAL;
  प्रकारव्याख्या HANDLE GLOBALHANDLE;
  प्रकारव्याख्या HANDLE LOCALHANDLE;
#ifdef _WIN64
  प्रकारव्याख्या INT_PTR (WINAPI *FARPROC)();
  प्रकारव्याख्या INT_PTR (WINAPI *NEARPROC)();
  प्रकारव्याख्या INT_PTR (WINAPI *PROC)();
#अन्यथा
  प्रकारव्याख्या पूर्णांक (WINAPI *FARPROC)();
  प्रकारव्याख्या पूर्णांक (WINAPI *NEARPROC)();
  प्रकारव्याख्या पूर्णांक (WINAPI *PROC)();
#endif

  प्रकारव्याख्या शून्य *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  प्रकारव्याख्या HKEY *PHKEY;

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
  प्रकारव्याख्या HINSTANCE HMODULE;
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

  प्रकारव्याख्या पूर्णांक HFILE;
  प्रकारव्याख्या HICON HCURSOR;
  प्रकारव्याख्या DWORD COLORREF;
  प्रकारव्याख्या DWORD *LPCOLORREF;

#define HFILE_ERROR ((HFILE)-1)

  प्रकारव्याख्या संरचना tagRECT {
    LONG डावा;
    LONG शीर्ष;
    LONG उजवा;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  प्रकारव्याख्या स्थिरांक RECT *LPCRECT;

  प्रकारव्याख्या संरचना _RECTL {
    LONG डावा;
    LONG शीर्ष;
    LONG उजवा;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  प्रकारव्याख्या स्थिरांक RECTL *LPCRECTL;

  प्रकारव्याख्या संरचना tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  प्रकारव्याख्या संरचना _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  प्रकारव्याख्या संरचना tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  प्रकारव्याख्या SIZE SIZEL;
  प्रकारव्याख्या SIZE *PSIZEL,*LPSIZEL;

  प्रकारव्याख्या संरचना tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  प्रकारव्याख्या संरचना _FILETIME {
    DWORD dw_खालचा_Date_Time;
    DWORD dw_वरचा_Date_Time;
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
