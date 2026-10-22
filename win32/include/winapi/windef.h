/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _WINDEF_
#నిర్వచించు _WINDEF_

#నిర్వచితం_కాకపోతే STRICT
#నిర్వచించు STRICT 1
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WINVER
#నిర్వచించు WINVER 0x0502
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే BASETYPES
#నిర్వచించు BASETYPES
  రకనిర్వచనం గుర్తులేని దీర్ఘ ULONG;
  రకనిర్వచనం ULONG *PULONG;
  రకనిర్వచనం గుర్తులేని పొట్టి USHORT;
  రకనిర్వచనం USHORT *PUSHORT;
  రకనిర్వచనం గుర్తులేని అక్షరం UCHAR;
  రకనిర్వచనం UCHAR *PUCHAR;
  రకనిర్వచనం అక్షరం *PSZ;
#అయితే_ముగింపు

#నిర్వచించు MAX_మార్గం 260

#నిర్వచితం_కాకపోతే ఖాళీ
#నిర్వచితమైతే __cplusplus
#నిర్వచించు ఖాళీ 0
#లేకపోతే
#నిర్వచించు ఖాళీ ((శూన్య *)0)
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే FALSE
#నిర్వచించు FALSE 0
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే TRUE
#నిర్వచించు TRUE 1
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే లోపల_2
#నిర్వచించు లోపల_2
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే బహిర్గతం_2
#నిర్వచించు బహిర్గతం_2
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే OPTIONAL
#నిర్వచించు OPTIONAL
#అయితే_ముగింపు

#నిర్వచనం_రద్దు far
#నిర్వచనం_రద్దు near
#నిర్వచనం_రద్దు pascal

#నిర్వచించు far
#నిర్వచించు near
#నిర్వచించు pascal __stdcall

#నిర్వచించు cdecl
#నిర్వచితం_కాకపోతే CDECL
#నిర్వచించు CDECL
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే CALLBACK
#నిర్వచించు CALLBACK __stdcall
#అయితే_ముగింపు
#నిర్వచితం_కాకపోతే WINAPI
#నిర్వచించు WINAPI __stdcall
#అయితే_ముగింపు
#నిర్వచించు WINAPIV __cdecl
#నిర్వచించు APIENTRY WINAPI
#నిర్వచించు APIPRIVATE WINAPI
#నిర్వచించు PASCAL WINAPI
#నిర్వచించు WINAPI_INLINE WINAPI

#నిర్వచనం_రద్దు FAR
#నిర్వచనం_రద్దు NEAR
#నిర్వచించు FAR
#నిర్వచించు NEAR
#నిర్వచితం_కాకపోతే CONST
#నిర్వచించు CONST స్థిరరాశి
#అయితే_ముగింపు

  రకనిర్వచనం గుర్తులేని దీర్ఘ DWORD;
  రకనిర్వచనం పూర్ణాంకం WINBOOL;
#నిర్వచించు BOOL WINBOOL
  రకనిర్వచనం గుర్తులేని అక్షరం BYTE;
  రకనిర్వచనం గుర్తులేని పొట్టి మాట_3;
  రకనిర్వచనం దశాంశం FLOAT;
  రకనిర్వచనం FLOAT *PFLOAT;
  రకనిర్వచనం WINBOOL *PBOOL;
  రకనిర్వచనం WINBOOL *LPBOOL;
  రకనిర్వచనం BYTE *PBYTE;
  రకనిర్వచనం BYTE *LPBYTE;
  రకనిర్వచనం పూర్ణాంకం *PINT;
  రకనిర్వచనం పూర్ణాంకం *LPINT;
  రకనిర్వచనం మాట_3 *PWORD;
  రకనిర్వచనం మాట_3 *LPWORD;
  రకనిర్వచనం దీర్ఘ *LPLONG;
  రకనిర్వచనం DWORD *PDWORD;
  రకనిర్వచనం DWORD *LPDWORD;
  రకనిర్వచనం శూన్య *LPVOID;
# ifndef _LPCVOID_DEFINED
#నిర్వచించు _LPCVOID_DEFINED
రకనిర్వచనం CONST శూన్య *LPCVOID;
#అయితే_ముగింపు
  రకనిర్వచనం పూర్ణాంకం INT;
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం UINT;
  రకనిర్వచనం గుర్తులేని పూర్ణాంకం *PUINT;

#నిర్వచితం_కాకపోతే NT_INCLUDED
#అన్తర్భావ <winnt.h>
#అయితే_ముగింపు

//gr #include <specstrings.h>

  రకనిర్వచనం UINT_PTR WPARAM;
  రకనిర్వచనం LONG_PTR LPARAM;
  రకనిర్వచనం LONG_PTR LRESULT;

#నిర్వచితం_కాకపోతే __cplusplus
#నిర్వచితం_కాకపోతే NOMINMAX
#నిర్వచితం_కాకపోతే max
#నిర్వచించు max(a,b) (((a) > (b)) ? (a) : (b))
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే min
#నిర్వచించు min(a,b) (((a) < (b)) ? (a) : (b))
#అయితే_ముగింపు
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు MAKEWORD(a,b) ((మాట_3)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((మాట_3)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#నిర్వచించు MAKELONG(a,b) ((LONG)(((మాట_3)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((మాట_3)((DWORD_PTR)(b) & 0xffff))) << 16))
#నిర్వచించు LOWORD(l) ((మాట_3)((DWORD_PTR)(l) & 0xffff))
#నిర్వచించు HIWORD(l) ((మాట_3)((DWORD_PTR)(l) >> 16))
#నిర్వచించు LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#నిర్వచించు HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#నిర్వచితం_కాకపోతే WIN_అంతర్గత
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#నిర్వచితమైతే WINABLE
  DECLARE_HANDLE (HEVENT);
#అయితే_ముగింపు
#అయితే_ముగింపు

  రకనిర్వచనం మాట_3 ATOM;

  రకనిర్వచనం HANDLE *SPHANDLE;
  రకనిర్వచనం HANDLE *LPHANDLE;
  రకనిర్వచనం HANDLE HGLOBAL;
  రకనిర్వచనం HANDLE HLOCAL;
  రకనిర్వచనం HANDLE GLOBALHANDLE;
  రకనిర్వచనం HANDLE LOCALHANDLE;
#నిర్వచితమైతే _WIN64
  రకనిర్వచనం INT_PTR (WINAPI *FARPROC)();
  రకనిర్వచనం INT_PTR (WINAPI *NEARPROC)();
  రకనిర్వచనం INT_PTR (WINAPI *PROC)();
#లేకపోతే
  రకనిర్వచనం పూర్ణాంకం (WINAPI *FARPROC)();
  రకనిర్వచనం పూర్ణాంకం (WINAPI *NEARPROC)();
  రకనిర్వచనం పూర్ణాంకం (WINAPI *PROC)();
#అయితే_ముగింపు

  రకనిర్వచనం శూన్య *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  రకనిర్వచనం HKEY *PHKEY;

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
  రకనిర్వచనం HINSTANCE HMODULE;
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

  రకనిర్వచనం పూర్ణాంకం HFILE;
  రకనిర్వచనం HICON HCURSOR;
  రకనిర్వచనం DWORD COLORREF;
  రకనిర్వచనం DWORD *LPCOLORREF;

#నిర్వచించు HFILE_ERROR ((HFILE)-1)

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RECT {
    LONG ఎడమ;
    LONG శిఖరం;
    LONG కుడి;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  రకనిర్వచనం స్థిరరాశి RECT *LPCRECT;

  రకనిర్వచనం నిర్మాణం _RECTL {
    LONG ఎడమ;
    LONG శిఖరం;
    LONG కుడి;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  రకనిర్వచనం స్థిరరాశి RECTL *LPCRECTL;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_బిందువు {
    LONG x;
    LONG y;
  } బిందువు_3,*PPOINT,*NPPOINT,*LPPOINT;

  రకనిర్వచనం నిర్మాణం _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_కొలత {
    LONG cx;
    LONG cy;
  } కొలత_2,*PSIZE,*LPSIZE;

  రకనిర్వచనం కొలత_2 SIZEL;
  రకనిర్వచనం కొలత_2 *PSIZEL,*LPSIZEL;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_POINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  రకనిర్వచనం నిర్మాణం _FILETIME {
    DWORD dw_దిగువ_Date_సమయం;
    DWORD dw_ఎగువ_Date_సమయం;
  } FILETIME,*PFILETIME,*LPFILETIME;
#నిర్వచించు _FILETIME_

#నిర్వచించు DM_UPDATE 1
#నిర్వచించు DM_COPY 2
#నిర్వచించు DM_PROMPT 4
#నిర్వచించు DM_MODIFY 8

#నిర్వచించు DM_లోపల_బఫరు DM_MODIFY
#నిర్వచించు DM_లోపల_PROMPT DM_PROMPT
#నిర్వచించు DM_బహిర్గతం_బఫరు DM_COPY
#నిర్వచించు DM_బహిర్గతం_DEFAULT DM_UPDATE

#నిర్వచించు DC_FIELDS 1
#నిర్వచించు DC_PAPERS 2
#నిర్వచించు DC_PAPERSIZE 3
#నిర్వచించు DC_MINEXTENT 4
#నిర్వచించు DC_MAXEXTENT 5
#నిర్వచించు DC_BINS 6
#నిర్వచించు DC_DUPLEX 7
#నిర్వచించు DC_కొలత 8
#నిర్వచించు DC_EXTRA 9
#నిర్వచించు DC_సంస్కరణ 10
#నిర్వచించు DC_DRIVER 11
#నిర్వచించు DC_BINNAMES 12
#నిర్వచించు DC_ENUMRESOLUTIONS 13
#నిర్వచించు DC_FILEDEPENDENCIES 14
#నిర్వచించు DC_TRUETYPE 15
#నిర్వచించు DC_PAPERNAMES 16
#నిర్వచించు DC_ORIENTATION 17
#నిర్వచించు DC_COPIES 18

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
