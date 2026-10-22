/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _WINDEF_
#परिभाषय _WINDEF_

#यदि_अपरिभाषितम् STRICT
#परिभाषय STRICT 1
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् WINVER
#परिभाषय WINVER 0x0502
#यदि_अन्तः

#यदि_अपरिभाषितम् BASETYPES
#परिभाषय BASETYPES
  प्रकारनिर्देश अचिह्नित दीर्घ ULONG;
  प्रकारनिर्देश ULONG *PULONG;
  प्रकारनिर्देश अचिह्नित ह्रस्व USHORT;
  प्रकारनिर्देश USHORT *PUSHORT;
  प्रकारनिर्देश अचिह्नित वर्ण UCHAR;
  प्रकारनिर्देश UCHAR *PUCHAR;
  प्रकारनिर्देश वर्ण *PSZ;
#यदि_अन्तः

#परिभाषय MAX_मार्गः 260

#यदि_अपरिभाषितम् रिक्त
#यदि_परिभाषितम् __cplusplus
#परिभाषय रिक्त 0
#अन्यथा
#परिभाषय रिक्त ((शून्य *)0)
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् FALSE
#परिभाषय FALSE 0
#यदि_अन्तः

#यदि_अपरिभाषितम् TRUE
#परिभाषय TRUE 1
#यदि_अन्तः

#यदि_अपरिभाषितम् अन्तर्_2
#परिभाषय अन्तर्_2
#यदि_अन्तः

#यदि_अपरिभाषितम् बहिर्गमनम्_2
#परिभाषय बहिर्गमनम्_2
#यदि_अन्तः

#यदि_अपरिभाषितम् OPTIONAL
#परिभाषय OPTIONAL
#यदि_अन्तः

#अपरिभाषय far
#अपरिभाषय near
#अपरिभाषय pascal

#परिभाषय far
#परिभाषय near
#परिभाषय pascal __stdcall

#परिभाषय cdecl
#यदि_अपरिभाषितम् CDECL
#परिभाषय CDECL
#यदि_अन्तः
#यदि_अपरिभाषितम् CALLBACK
#परिभाषय CALLBACK __stdcall
#यदि_अन्तः
#यदि_अपरिभाषितम् WINAPI
#परिभाषय WINAPI __stdcall
#यदि_अन्तः
#परिभाषय WINAPIV __cdecl
#परिभाषय APIENTRY WINAPI
#परिभाषय APIPRIVATE WINAPI
#परिभाषय PASCAL WINAPI
#परिभाषय WINAPI_INLINE WINAPI

#अपरिभाषय FAR
#अपरिभाषय NEAR
#परिभाषय FAR
#परिभाषय NEAR
#यदि_अपरिभाषितम् CONST
#परिभाषय CONST ध्रुव
#यदि_अन्तः

  प्रकारनिर्देश अचिह्नित दीर्घ DWORD;
  प्रकारनिर्देश पूर्णाङ्क WINBOOL;
#परिभाषय BOOL WINBOOL
  प्रकारनिर्देश अचिह्नित वर्ण BYTE;
  प्रकारनिर्देश अचिह्नित ह्रस्व WORD;
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
  प्रकारनिर्देश दीर्घ *LPLONG;
  प्रकारनिर्देश DWORD *PDWORD;
  प्रकारनिर्देश DWORD *LPDWORD;
  प्रकारनिर्देश शून्य *LPVOID;
# ifndef _LPCVOID_DEFINED
#परिभाषय _LPCVOID_DEFINED
प्रकारनिर्देश CONST शून्य *LPCVOID;
#यदि_अन्तः
  प्रकारनिर्देश पूर्णाङ्क INT;
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क UINT;
  प्रकारनिर्देश अचिह्नित पूर्णाङ्क *PUINT;

#यदि_अपरिभाषितम् NT_INCLUDED
#अन्तर्भाव <winnt.h>
#यदि_अन्तः

//gr #include <specstrings.h>

  प्रकारनिर्देश UINT_PTR WPARAM;
  प्रकारनिर्देश LONG_PTR LPARAM;
  प्रकारनिर्देश LONG_PTR LRESULT;

#यदि_अपरिभाषितम् __cplusplus
#यदि_अपरिभाषितम् NOMINMAX
#यदि_अपरिभाषितम् max
#परिभाषय max(a,b) (((a) > (b)) ? (a) : (b))
#यदि_अन्तः

#यदि_अपरिभाषितम् min
#परिभाषय min(a,b) (((a) < (b)) ? (a) : (b))
#यदि_अन्तः
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय MAKEWORD(a,b) ((WORD)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((WORD)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#परिभाषय MAKELONG(a,b) ((LONG)(((WORD)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((WORD)((DWORD_PTR)(b) & 0xffff))) << 16))
#परिभाषय LOWORD(l) ((WORD)((DWORD_PTR)(l) & 0xffff))
#परिभाषय HIWORD(l) ((WORD)((DWORD_PTR)(l) >> 16))
#परिभाषय LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#परिभाषय HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#यदि_अपरिभाषितम् WIN_आन्तरिकम्
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#यदि_परिभाषितम् WINABLE
  DECLARE_HANDLE (HEVENT);
#यदि_अन्तः
#यदि_अन्तः

  प्रकारनिर्देश WORD ATOM;

  प्रकारनिर्देश HANDLE *SPHANDLE;
  प्रकारनिर्देश HANDLE *LPHANDLE;
  प्रकारनिर्देश HANDLE HGLOBAL;
  प्रकारनिर्देश HANDLE HLOCAL;
  प्रकारनिर्देश HANDLE GLOBALHANDLE;
  प्रकारनिर्देश HANDLE LOCALHANDLE;
#यदि_परिभाषितम् _WIN64
  प्रकारनिर्देश INT_PTR (WINAPI *FARPROC)();
  प्रकारनिर्देश INT_PTR (WINAPI *NEARPROC)();
  प्रकारनिर्देश INT_PTR (WINAPI *PROC)();
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क (WINAPI *FARPROC)();
  प्रकारनिर्देश पूर्णाङ्क (WINAPI *NEARPROC)();
  प्रकारनिर्देश पूर्णाङ्क (WINAPI *PROC)();
#यदि_अन्तः

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

#परिभाषय HFILE_ERROR ((HFILE)-1)

  प्रकारनिर्देश संरचना चिह्नकम्_RECT {
    LONG वामः;
    LONG शिखरम्;
    LONG दक्षिणः;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  प्रकारनिर्देश ध्रुव RECT *LPCRECT;

  प्रकारनिर्देश संरचना _RECTL {
    LONG वामः;
    LONG शिखरम्;
    LONG दक्षिणः;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  प्रकारनिर्देश ध्रुव RECTL *LPCRECTL;

  प्रकारनिर्देश संरचना चिह्नकम्_POINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  प्रकारनिर्देश संरचना _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  प्रकारनिर्देश संरचना चिह्नकम्_आकार {
    LONG cx;
    LONG cy;
  } आकार_2,*PSIZE,*LPSIZE;

  प्रकारनिर्देश आकार_2 SIZEL;
  प्रकारनिर्देश आकार_2 *PSIZEL,*LPSIZEL;

  प्रकारनिर्देश संरचना चिह्नकम्_POINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  प्रकारनिर्देश संरचना _FILETIME {
    DWORD dw_नीचः_Date_Time;
    DWORD dw_उच्चः_Date_Time;
  } FILETIME,*PFILETIME,*LPFILETIME;
#परिभाषय _FILETIME_

#परिभाषय DM_UPDATE 1
#परिभाषय DM_COPY 2
#परिभाषय DM_PROMPT 4
#परिभाषय DM_MODIFY 8

#परिभाषय DM_अन्तर्_बफर DM_MODIFY
#परिभाषय DM_अन्तर्_PROMPT DM_PROMPT
#परिभाषय DM_बहिर्गमनम्_बफर DM_COPY
#परिभाषय DM_बहिर्गमनम्_DEFAULT DM_UPDATE

#परिभाषय DC_FIELDS 1
#परिभाषय DC_PAPERS 2
#परिभाषय DC_PAPERSIZE 3
#परिभाषय DC_MINEXTENT 4
#परिभाषय DC_MAXEXTENT 5
#परिभाषय DC_BINS 6
#परिभाषय DC_DUPLEX 7
#परिभाषय DC_आकार 8
#परिभाषय DC_EXTRA 9
#परिभाषय DC_संस्करणम् 10
#परिभाषय DC_DRIVER 11
#परिभाषय DC_BINNAMES 12
#परिभाषय DC_ENUMRESOLUTIONS 13
#परिभाषय DC_FILEDEPENDENCIES 14
#परिभाषय DC_TRUETYPE 15
#परिभाषय DC_PAPERNAMES 16
#परिभाषय DC_ORIENTATION 17
#परिभाषय DC_COPIES 18

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
