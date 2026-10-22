/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _WINDEF_
#تعریف_کرو _WINDEF_

#اگر_غیر_تعریف_شدہ STRICT
#تعریف_کرو STRICT 1
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ WINVER
#تعریف_کرو WINVER 0x0502
#اگر_ختم

#اگر_غیر_تعریف_شدہ BASETYPES
#تعریف_کرو BASETYPES
  قسمتعریف غیرعلامتی طویل ULONG;
  قسمتعریف ULONG *PULONG;
  قسمتعریف غیرعلامتی مختصر USHORT;
  قسمتعریف USHORT *PUSHORT;
  قسمتعریف غیرعلامتی حرف UCHAR;
  قسمتعریف UCHAR *PUCHAR;
  قسمتعریف حرف *PSZ;
#اگر_ختم

#تعریف_کرو MAX_راستہ 260

#اگر_غیر_تعریف_شدہ تہی
#اگر_تعریف_شدہ __cplusplus
#تعریف_کرو تہی 0
#ورنہ
#تعریف_کرو تہی ((خالی *)0)
#اگر_ختم
#اگر_ختم

#اگر_غیر_تعریف_شدہ FALSE
#تعریف_کرو FALSE 0
#اگر_ختم

#اگر_غیر_تعریف_شدہ TRUE
#تعریف_کرو TRUE 1
#اگر_ختم

#اگر_غیر_تعریف_شدہ اندر_2
#تعریف_کرو اندر_2
#اگر_ختم

#اگر_غیر_تعریف_شدہ برآمد_2
#تعریف_کرو برآمد_2
#اگر_ختم

#اگر_غیر_تعریف_شدہ OPTIONAL
#تعریف_کرو OPTIONAL
#اگر_ختم

#تعریف_منسوخ far
#تعریف_منسوخ near
#تعریف_منسوخ pascal

#تعریف_کرو far
#تعریف_کرو near
#تعریف_کرو pascal __stdcall

#تعریف_کرو cdecl
#اگر_غیر_تعریف_شدہ CDECL
#تعریف_کرو CDECL
#اگر_ختم
#اگر_غیر_تعریف_شدہ CALLBACK
#تعریف_کرو CALLBACK __stdcall
#اگر_ختم
#اگر_غیر_تعریف_شدہ WINAPI
#تعریف_کرو WINAPI __stdcall
#اگر_ختم
#تعریف_کرو WINAPIV __cdecl
#تعریف_کرو APIENTRY WINAPI
#تعریف_کرو APIPRIVATE WINAPI
#تعریف_کرو PASCAL WINAPI
#تعریف_کرو WINAPI_INLINE WINAPI

#تعریف_منسوخ FAR
#تعریف_منسوخ NEAR
#تعریف_کرو FAR
#تعریف_کرو NEAR
#اگر_غیر_تعریف_شدہ CONST
#تعریف_کرو CONST ثابت
#اگر_ختم

  قسمتعریف غیرعلامتی طویل DWORD;
  قسمتعریف صحیح WINBOOL;
#تعریف_کرو BOOL WINBOOL
  قسمتعریف غیرعلامتی حرف BYTE;
  قسمتعریف غیرعلامتی مختصر لفظ_3;
  قسمتعریف اعشاری FLOAT;
  قسمتعریف FLOAT *PFLOAT;
  قسمتعریف WINBOOL *PBOOL;
  قسمتعریف WINBOOL *LPBOOL;
  قسمتعریف BYTE *PBYTE;
  قسمتعریف BYTE *LPBYTE;
  قسمتعریف صحیح *PINT;
  قسمتعریف صحیح *LPINT;
  قسمتعریف لفظ_3 *PWORD;
  قسمتعریف لفظ_3 *LPWORD;
  قسمتعریف طویل *LPLONG;
  قسمتعریف DWORD *PDWORD;
  قسمتعریف DWORD *LPDWORD;
  قسمتعریف خالی *LPVOID;
# ifndef _LPCVOID_DEFINED
#تعریف_کرو _LPCVOID_DEFINED
قسمتعریف CONST خالی *LPCVOID;
#اگر_ختم
  قسمتعریف صحیح INT;
  قسمتعریف غیرعلامتی صحیح UINT;
  قسمتعریف غیرعلامتی صحیح *PUINT;

#اگر_غیر_تعریف_شدہ NT_INCLUDED
#شامل <winnt.h>
#اگر_ختم

//gr #include <specstrings.h>

  قسمتعریف UINT_PTR WPARAM;
  قسمتعریف LONG_PTR LPARAM;
  قسمتعریف LONG_PTR LRESULT;

#اگر_غیر_تعریف_شدہ __cplusplus
#اگر_غیر_تعریف_شدہ NOMINMAX
#اگر_غیر_تعریف_شدہ max
#تعریف_کرو max(a,b) (((a) > (b)) ? (a) : (b))
#اگر_ختم

#اگر_غیر_تعریف_شدہ min
#تعریف_کرو min(a,b) (((a) < (b)) ? (a) : (b))
#اگر_ختم
#اگر_ختم
#اگر_ختم

#تعریف_کرو MAKEWORD(a,b) ((لفظ_3)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((لفظ_3)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#تعریف_کرو MAKELONG(a,b) ((LONG)(((لفظ_3)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((لفظ_3)((DWORD_PTR)(b) & 0xffff))) << 16))
#تعریف_کرو LOWORD(l) ((لفظ_3)((DWORD_PTR)(l) & 0xffff))
#تعریف_کرو HIWORD(l) ((لفظ_3)((DWORD_PTR)(l) >> 16))
#تعریف_کرو LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#تعریف_کرو HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#اگر_غیر_تعریف_شدہ WIN_اندرونی
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#اگر_تعریف_شدہ WINABLE
  DECLARE_HANDLE (HEVENT);
#اگر_ختم
#اگر_ختم

  قسمتعریف لفظ_3 ATOM;

  قسمتعریف HANDLE *SPHANDLE;
  قسمتعریف HANDLE *LPHANDLE;
  قسمتعریف HANDLE HGLOBAL;
  قسمتعریف HANDLE HLOCAL;
  قسمتعریف HANDLE GLOBALHANDLE;
  قسمتعریف HANDLE LOCALHANDLE;
#اگر_تعریف_شدہ _WIN64
  قسمتعریف INT_PTR (WINAPI *FARPROC)();
  قسمتعریف INT_PTR (WINAPI *NEARPROC)();
  قسمتعریف INT_PTR (WINAPI *PROC)();
#ورنہ
  قسمتعریف صحیح (WINAPI *FARPROC)();
  قسمتعریف صحیح (WINAPI *NEARPROC)();
  قسمتعریف صحیح (WINAPI *PROC)();
#اگر_ختم

  قسمتعریف خالی *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  قسمتعریف HKEY *PHKEY;

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
  قسمتعریف HINSTANCE HMODULE;
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

  قسمتعریف صحیح HFILE;
  قسمتعریف HICON HCURSOR;
  قسمتعریف DWORD COLORREF;
  قسمتعریف DWORD *LPCOLORREF;

#تعریف_کرو HFILE_ERROR ((HFILE)-1)

  قسمتعریف ساخت لیبل_RECT {
    LONG بایاں;
    LONG چوٹی;
    LONG دایاں;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  قسمتعریف ثابت RECT *LPCRECT;

  قسمتعریف ساخت _RECTL {
    LONG بایاں;
    LONG چوٹی;
    LONG دایاں;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  قسمتعریف ثابت RECTL *LPCRECTL;

  قسمتعریف ساخت لیبل_نقطہ {
    LONG x;
    LONG y;
  } نقطہ_3,*PPOINT,*NPPOINT,*LPPOINT;

  قسمتعریف ساخت _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  قسمتعریف ساخت لیبل_سائز {
    LONG cx;
    LONG cy;
  } سائز_2,*PSIZE,*LPSIZE;

  قسمتعریف سائز_2 SIZEL;
  قسمتعریف سائز_2 *PSIZEL,*LPSIZEL;

  قسمتعریف ساخت لیبل_POINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  قسمتعریف ساخت _FILETIME {
    DWORD dw_کم_Date_وقت;
    DWORD dw_بلند_Date_وقت;
  } FILETIME,*PFILETIME,*LPFILETIME;
#تعریف_کرو _FILETIME_

#تعریف_کرو DM_UPDATE 1
#تعریف_کرو DM_COPY 2
#تعریف_کرو DM_PROMPT 4
#تعریف_کرو DM_MODIFY 8

#تعریف_کرو DM_اندر_بفر DM_MODIFY
#تعریف_کرو DM_اندر_PROMPT DM_PROMPT
#تعریف_کرو DM_برآمد_بفر DM_COPY
#تعریف_کرو DM_برآمد_DEFAULT DM_UPDATE

#تعریف_کرو DC_FIELDS 1
#تعریف_کرو DC_PAPERS 2
#تعریف_کرو DC_PAPERSIZE 3
#تعریف_کرو DC_MINEXTENT 4
#تعریف_کرو DC_MAXEXTENT 5
#تعریف_کرو DC_BINS 6
#تعریف_کرو DC_DUPLEX 7
#تعریف_کرو DC_سائز 8
#تعریف_کرو DC_EXTRA 9
#تعریف_کرو DC_نسخہ 10
#تعریف_کرو DC_DRIVER 11
#تعریف_کرو DC_BINNAMES 12
#تعریف_کرو DC_ENUMRESOLUTIONS 13
#تعریف_کرو DC_FILEDEPENDENCIES 14
#تعریف_کرو DC_TRUETYPE 15
#تعریف_کرو DC_PAPERNAMES 16
#تعریف_کرو DC_ORIENTATION 17
#تعریف_کرو DC_COPIES 18

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
