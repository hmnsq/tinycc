/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _WINDEF_
#घोषणा _WINDEF_

#अगर_अघोषित STRICT
#घोषणा STRICT 1
#पूर्ण_अगर

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#अगर_अघोषित WINVER
#घोषणा WINVER 0x0502
#पूर्ण_अगर

#अगर_अघोषित BASETYPES
#घोषणा BASETYPES
  प्रकार अचिन्हित दीर्घ ULONG;
  प्रकार ULONG *PULONG;
  प्रकार अचिन्हित लघु USHORT;
  प्रकार USHORT *PUSHORT;
  प्रकार अचिन्हित अक्षर UCHAR;
  प्रकार UCHAR *PUCHAR;
  प्रकार अक्षर *PSZ;
#पूर्ण_अगर

#घोषणा MAX_PATH 260

#अगर_अघोषित शून्य
#अगर_घोषित __cplusplus
#घोषणा शून्य 0
#अन्यथा
#घोषणा शून्य ((व्योम *)0)
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित FALSE
#घोषणा FALSE 0
#पूर्ण_अगर

#अगर_अघोषित TRUE
#घोषणा TRUE 1
#पूर्ण_अगर

#अगर_अघोषित IN
#घोषणा IN
#पूर्ण_अगर

#अगर_अघोषित OUT
#घोषणा OUT
#पूर्ण_अगर

#अगर_अघोषित OPTIONAL
#घोषणा OPTIONAL
#पूर्ण_अगर

#अघोषित far
#अघोषित near
#अघोषित pascal

#घोषणा far
#घोषणा near
#घोषणा pascal __stdcall

#घोषणा cdecl
#अगर_अघोषित CDECL
#घोषणा CDECL
#पूर्ण_अगर
#अगर_अघोषित CALLBACK
#घोषणा CALLBACK __stdcall
#पूर्ण_अगर
#अगर_अघोषित WINAPI
#घोषणा WINAPI __stdcall
#पूर्ण_अगर
#घोषणा WINAPIV __cdecl
#घोषणा APIENTRY WINAPI
#घोषणा APIPRIVATE WINAPI
#घोषणा PASCAL WINAPI
#घोषणा WINAPI_INLINE WINAPI

#अघोषित FAR
#अघोषित NEAR
#घोषणा FAR
#घोषणा NEAR
#अगर_अघोषित CONST
#घोषणा CONST स्थिर
#पूर्ण_अगर

  प्रकार अचिन्हित दीर्घ DWORD;
  प्रकार पूर्णांक WINBOOL;
#घोषणा BOOL WINBOOL
  प्रकार अचिन्हित अक्षर BYTE;
  प्रकार अचिन्हित लघु WORD;
  प्रकार भग्न FLOAT;
  प्रकार FLOAT *PFLOAT;
  प्रकार WINBOOL *PBOOL;
  प्रकार WINBOOL *LPBOOL;
  प्रकार BYTE *PBYTE;
  प्रकार BYTE *LPBYTE;
  प्रकार पूर्णांक *PINT;
  प्रकार पूर्णांक *LPINT;
  प्रकार WORD *PWORD;
  प्रकार WORD *LPWORD;
  प्रकार दीर्घ *LPLONG;
  प्रकार DWORD *PDWORD;
  प्रकार DWORD *LPDWORD;
  प्रकार व्योम *LPVOID;
# ifndef _LPCVOID_DEFINED
#घोषणा _LPCVOID_DEFINED
प्रकार CONST व्योम *LPCVOID;
#पूर्ण_अगर
  प्रकार पूर्णांक INT;
  प्रकार अचिन्हित पूर्णांक UINT;
  प्रकार अचिन्हित पूर्णांक *PUINT;

#अगर_अघोषित NT_INCLUDED
#समावेश <winnt.h>
#पूर्ण_अगर

//gr #include <specstrings.h>

  प्रकार UINT_PTR WPARAM;
  प्रकार LONG_PTR LPARAM;
  प्रकार LONG_PTR LRESULT;

#अगर_अघोषित __cplusplus
#अगर_अघोषित NOMINMAX
#अगर_अघोषित max
#घोषणा max(a,b) (((a) > (b)) ? (a) : (b))
#पूर्ण_अगर

#अगर_अघोषित min
#घोषणा min(a,b) (((a) < (b)) ? (a) : (b))
#पूर्ण_अगर
#पूर्ण_अगर
#पूर्ण_अगर

#घोषणा MAKEWORD(a,b) ((WORD)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((WORD)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#घोषणा MAKELONG(a,b) ((LONG)(((WORD)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((WORD)((DWORD_PTR)(b) & 0xffff))) << 16))
#घोषणा LOWORD(l) ((WORD)((DWORD_PTR)(l) & 0xffff))
#घोषणा HIWORD(l) ((WORD)((DWORD_PTR)(l) >> 16))
#घोषणा LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#घोषणा HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#अगर_अघोषित WIN_INTERNAL
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#अगर_घोषित WINABLE
  DECLARE_HANDLE (HEVENT);
#पूर्ण_अगर
#पूर्ण_अगर

  प्रकार WORD ATOM;

  प्रकार HANDLE *SPHANDLE;
  प्रकार HANDLE *LPHANDLE;
  प्रकार HANDLE HGLOBAL;
  प्रकार HANDLE HLOCAL;
  प्रकार HANDLE GLOBALHANDLE;
  प्रकार HANDLE LOCALHANDLE;
#अगर_घोषित _WIN64
  प्रकार INT_PTR (WINAPI *FARPROC)();
  प्रकार INT_PTR (WINAPI *NEARPROC)();
  प्रकार INT_PTR (WINAPI *PROC)();
#अन्यथा
  प्रकार पूर्णांक (WINAPI *FARPROC)();
  प्रकार पूर्णांक (WINAPI *NEARPROC)();
  प्रकार पूर्णांक (WINAPI *PROC)();
#पूर्ण_अगर

  प्रकार व्योम *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  प्रकार HKEY *PHKEY;

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
  प्रकार HINSTANCE HMODULE;
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

  प्रकार पूर्णांक HFILE;
  प्रकार HICON HCURSOR;
  प्रकार DWORD COLORREF;
  प्रकार DWORD *LPCOLORREF;

#घोषणा HFILE_ERROR ((HFILE)-1)

  प्रकार काष्ठा tagRECT {
    LONG बायाँ;
    LONG शीर्ष;
    LONG दायाँ;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  प्रकार स्थिर RECT *LPCRECT;

  प्रकार काष्ठा _RECTL {
    LONG बायाँ;
    LONG शीर्ष;
    LONG दायाँ;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  प्रकार स्थिर RECTL *LPCRECTL;

  प्रकार काष्ठा tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  प्रकार काष्ठा _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  प्रकार काष्ठा tag_आकार {
    LONG cx;
    LONG cy;
  } आकार_2,*PSIZE,*LPSIZE;

  प्रकार आकार_2 SIZEL;
  प्रकार आकार_2 *PSIZEL,*LPSIZEL;

  प्रकार काष्ठा tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  प्रकार काष्ठा _FILETIME {
    DWORD dw_निचला_Date_Time;
    DWORD dw_ऊपरी_Date_Time;
  } FILETIME,*PFILETIME,*LPFILETIME;
#घोषणा _FILETIME_

#घोषणा DM_UPDATE 1
#घोषणा DM_COPY 2
#घोषणा DM_PROMPT 4
#घोषणा DM_MODIFY 8

#घोषणा DM_IN_बफर DM_MODIFY
#घोषणा DM_IN_PROMPT DM_PROMPT
#घोषणा DM_OUT_बफर DM_COPY
#घोषणा DM_OUT_DEFAULT DM_UPDATE

#घोषणा DC_FIELDS 1
#घोषणा DC_PAPERS 2
#घोषणा DC_PAPERSIZE 3
#घोषणा DC_MINEXTENT 4
#घोषणा DC_MAXEXTENT 5
#घोषणा DC_BINS 6
#घोषणा DC_DUPLEX 7
#घोषणा DC_आकार 8
#घोषणा DC_EXTRA 9
#घोषणा DC_VERSION 10
#घोषणा DC_DRIVER 11
#घोषणा DC_BINNAMES 12
#घोषणा DC_ENUMRESOLUTIONS 13
#घोषणा DC_FILEDEPENDENCIES 14
#घोषणा DC_TRUETYPE 15
#घोषणा DC_PAPERNAMES 16
#घोषणा DC_ORIENTATION 17
#घोषणा DC_COPIES 18

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
