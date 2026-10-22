/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی _WINGDI_
#تعریف_کړه _WINGDI_

#تعریف_کړه WINGDIAPI DECLSPEC_IMPORT
#تعریف_کړه WINSPOOLAPI DECLSPEC_IMPORT

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#که_نه_تعریف_شوی WINVER
#تعریف_کړه WINVER 0x0502
#د_که_پای

#که_نه_تعریف_شوی NOGDI
#که_نه_تعریف_شوی NORASTEROPS
#تعریف_کړه R2_BLACK 1
#تعریف_کړه R2_NOTMERGEPEN 2
#تعریف_کړه R2_MASKNOTPEN 3
#تعریف_کړه R2_NOTCOPYPEN 4
#تعریف_کړه R2_MASKPENNOT 5
#تعریف_کړه R2_NOT 6
#تعریف_کړه R2_XORPEN 7
#تعریف_کړه R2_NOTMASKPEN 8
#تعریف_کړه R2_MASKPEN 9
#تعریف_کړه R2_NOTXORPEN 10
#تعریف_کړه R2_NOP 11
#تعریف_کړه R2_MERGENOTPEN 12
#تعریف_کړه R2_COPYPEN 13
#تعریف_کړه R2_MERGEPENNOT 14
#تعریف_کړه R2_MERGEPEN 15
#تعریف_کړه R2_WHITE 16
#تعریف_کړه R2_وروستی 16

#تعریف_کړه SRCCOPY (DWORD)0x00CC0020
#تعریف_کړه SRCPAINT (DWORD)0x00EE0086
#تعریف_کړه SRCAND (DWORD)0x008800C6
#تعریف_کړه SRCINVERT (DWORD)0x00660046
#تعریف_کړه SRCERASE (DWORD)0x00440328
#تعریف_کړه NOTSRCCOPY (DWORD)0x00330008
#تعریف_کړه NOTSRCERASE (DWORD)0x001100A6
#تعریف_کړه MERGECOPY (DWORD)0x00C000CA
#تعریف_کړه MERGEPAINT (DWORD)0x00BB0226
#تعریف_کړه PATCOPY (DWORD)0x00F00021
#تعریف_کړه PATPAINT (DWORD)0x00FB0A09
#تعریف_کړه PATINVERT (DWORD)0x005A0049
#تعریف_کړه DSTINVERT (DWORD)0x00550009
#تعریف_کړه BLACKNESS (DWORD)0x00000042
#تعریف_کړه WHITENESS (DWORD)0x00FF0062
#تعریف_کړه NOMIRRORBITMAP (DWORD)0x80000000
#تعریف_کړه CAPTUREBLT (DWORD)0x40000000
#تعریف_کړه MAKEROP4(fore,شا) (DWORD)((((شا) << 8) & 0xFF000000) | (fore))
#د_که_پای

#تعریف_کړه GDI_ERROR (0xFFFFFFFFL)
#تعریف_کړه HGDI_ERROR (Long_منزل_Handle(0xFFFFFFFFL))

#تعریف_کړه ERROR 0
#تعریف_کړه NULLREGION 1
#تعریف_کړه SIMPLEREGION 2
#تعریف_کړه COMPLEXREGION 3
#تعریف_کړه RGN_ERROR ERROR

#تعریف_کړه RGN_AND 1
#تعریف_کړه RGN_OR 2
#تعریف_کړه RGN_XOR 3
#تعریف_کړه RGN_DIFF 4
#تعریف_کړه RGN_COPY 5
#تعریف_کړه RGN_MIN RGN_AND
#تعریف_کړه RGN_MAX RGN_COPY

#تعریف_کړه BLACKONWHITE 1
#تعریف_کړه WHITEONBLACK 2
#تعریف_کړه COLORONCOLOR 3
#تعریف_کړه HALFTONE 4
#تعریف_کړه MAXSTRETCHBLTMODE 4

#تعریف_کړه STRETCH_ANDSCANS BLACKONWHITE
#تعریف_کړه STRETCH_ORSCANS WHITEONBLACK
#تعریف_کړه STRETCH_DELETESCANS COLORONCOLOR
#تعریف_کړه STRETCH_HALFTONE HALFTONE

#تعریف_کړه ALTERNATE 1
#تعریف_کړه WINDING 2
#تعریف_کړه POLYFILL_وروستی 2

#تعریف_کړه LAYOUT_RTL 0x00000001
#تعریف_کړه LAYOUT_BTT 0x00000002
#تعریف_کړه LAYOUT_VBH 0x00000004
#تعریف_کړه LAYOUT_ORIENTATIONMASK (LAYOUT_RTL | LAYOUT_BTT | LAYOUT_VBH)
#تعریف_کړه LAYOUT_BITMAPORIENTATIONPRESERVED 0x00000008

#تعریف_کړه TA_NOUPDATECP 0
#تعریف_کړه TA_UPDATECP 1

#تعریف_کړه TA_کیڼ 0
#تعریف_کړه TA_ښی 2
#تعریف_کړه TA_CENTER 6

#تعریف_کړه TA_سر 0
#تعریف_کړه TA_BOTTOM 8
#تعریف_کړه TA_BASELINE 24
#تعریف_کړه TA_RTLREADING 256
#تعریف_کړه TA_ماسک (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)

#تعریف_کړه VTA_BASELINE TA_BASELINE
#تعریف_کړه VTA_کیڼ TA_BOTTOM
#تعریف_کړه VTA_ښی TA_سر
#تعریف_کړه VTA_CENTER TA_CENTER
#تعریف_کړه VTA_BOTTOM TA_ښی
#تعریف_کړه VTA_سر TA_کیڼ

#تعریف_کړه ETO_OPAQUE 0x0002
#تعریف_کړه ETO_CLIPPED 0x0004
#تعریف_کړه ETO_GLYPH_شاخص 0x0010
#تعریف_کړه ETO_RTLREADING 0x0080
#تعریف_کړه ETO_NUMERICSLOCAL 0x0400
#تعریف_کړه ETO_NUMERICSLATIN 0x0800
#تعریف_کړه ETO_IGNORELANGUAGE 0x1000
#تعریف_کړه ETO_PDY 0x2000

#تعریف_کړه ASPECT_FILTERING 0x0001

#تعریف_کړه DCB_RESET 0x0001
#تعریف_کړه DCB_ACCUMULATE 0x0002
#تعریف_کړه DCB_DIRTY DCB_ACCUMULATE
#تعریف_کړه DCB_سېټ (DCB_RESET | DCB_ACCUMULATE)
#تعریف_کړه DCB_ENABLE 0x0004
#تعریف_کړه DCB_DISABLE 0x0008

#که_نه_تعریف_شوی NOMETAFILE

#تعریف_کړه META_SETBKCOLOR 0x0201
#تعریف_کړه META_SETBKMODE 0x0102
#تعریف_کړه META_SETMAPMODE 0x0103
#تعریف_کړه META_SETROP2 0x0104
#تعریف_کړه META_SETRELABS 0x0105
#تعریف_کړه META_SETPOLYFILLMODE 0x0106
#تعریف_کړه META_SETSTRETCHBLTMODE 0x0107
#تعریف_کړه META_SETTEXTCHAREXTRA 0x0108
#تعریف_کړه META_SETTEXTCOLOR 0x0209
#تعریف_کړه META_SETTEXTJUSTIFICATION 0x020A
#تعریف_کړه META_SETWINDOWORG 0x020B
#تعریف_کړه META_SETWINDOWEXT 0x020C
#تعریف_کړه META_SETVIEWPORTORG 0x020D
#تعریف_کړه META_SETVIEWPORTEXT 0x020E
#تعریف_کړه META_OFFSETWINDOWORG 0x020F
#تعریف_کړه META_SCALEWINDOWEXT 0x0410
#تعریف_کړه META_OFFSETVIEWPORTORG 0x0211
#تعریف_کړه META_SCALEVIEWPORTEXT 0x0412
#تعریف_کړه META_LINETO 0x0213
#تعریف_کړه META_MOVETO 0x0214
#تعریف_کړه META_EXCLUDECLIPRECT 0x0415
#تعریف_کړه META_INTERSECTCLIPRECT 0x0416
#تعریف_کړه META_ARC 0x0817
#تعریف_کړه META_ELLIPSE 0x0418
#تعریف_کړه META_FLOODFILL 0x0419
#تعریف_کړه META_PIE 0x081A
#تعریف_کړه META_RECTANGLE 0x041B
#تعریف_کړه META_ROUNDRECT 0x061C
#تعریف_کړه META_PATBLT 0x061D
#تعریف_کړه META_SAVEDC 0x001E
#تعریف_کړه META_SETPIXEL 0x041F
#تعریف_کړه META_OFFSETCLIPRGN 0x0220
#تعریف_کړه META_TEXTOUT 0x0521
#تعریف_کړه META_BITBLT 0x0922
#تعریف_کړه META_STRETCHBLT 0x0B23
#تعریف_کړه META_POLYGON 0x0324
#تعریف_کړه META_POLYLINE 0x0325
#تعریف_کړه META_ESCAPE 0x0626
#تعریف_کړه META_RESTOREDC 0x0127
#تعریف_کړه META_FILLREGION 0x0228
#تعریف_کړه META_FRAMEREGION 0x0429
#تعریف_کړه META_INVERTREGION 0x012A
#تعریف_کړه META_PAINTREGION 0x012B
#تعریف_کړه META_SELECTCLIPREGION 0x012C
#تعریف_کړه META_SELECTOBJECT 0x012D
#تعریف_کړه META_SETTEXTALIGN 0x012E
#تعریف_کړه META_CHORD 0x0830
#تعریف_کړه META_SETMAPPERFLAGS 0x0231
#تعریف_کړه META_EXTTEXTOUT 0x0a32
#تعریف_کړه META_SETDIBTODEV 0x0d33
#تعریف_کړه META_SELECTPALETTE 0x0234
#تعریف_کړه META_REALIZEPALETTE 0x0035
#تعریف_کړه META_ANIMATEPALETTE 0x0436
#تعریف_کړه META_SETPALENTRIES 0x0037
#تعریف_کړه META_POLYPOLYGON 0x0538
#تعریف_کړه META_RESIZEPALETTE 0x0139
#تعریف_کړه META_DIBBITBLT 0x0940
#تعریف_کړه META_DIBSTRETCHBLT 0x0b41
#تعریف_کړه META_DIBCREATEPATTERNBRUSH 0x0142
#تعریف_کړه META_STRETCHDIB 0x0f43
#تعریف_کړه META_EXTFLOODFILL 0x0548
#تعریف_کړه META_SETLAYOUT 0x0149
#تعریف_کړه META_DELETEOBJECT 0x01f0
#تعریف_کړه META_CREATEPALETTE 0x00f7
#تعریف_کړه META_CREATEPATTERNBRUSH 0x01F9
#تعریف_کړه META_CREATEPENINDIRECT 0x02FA
#تعریف_کړه META_CREATEFONTINDIRECT 0x02FB
#تعریف_کړه META_CREATEBRUSHINDIRECT 0x02FC
#تعریف_کړه META_CREATEREGION 0x06FF

  تعريفنوع بنية _DRAWPATRECT {
    ټکی_3 ptPosition;
    ټکی_3 pt_اندازه;
    کلمه_3 wStyle;
    کلمه_3 w_نمونه;
  } DRAWPATRECT,*PDRAWPATRECT;
#د_که_پای

#تعریف_کړه NEWFRAME 1
#تعریف_کړه ABORTDOC 2
#تعریف_کړه NEXTBAND 3
#تعریف_کړه SETCOLORTABLE 4
#تعریف_کړه GETCOLORTABLE 5
#تعریف_کړه FLUSHOUTPUT 6
#تعریف_کړه DRAFTMODE 7
#تعریف_کړه QUERYESCSUPPORT 8
#تعریف_کړه SETABORTPROC 9
#تعریف_کړه STARTDOC 10
#تعریف_کړه ENDDOC 11
#تعریف_کړه GETPHYSPAGESIZE 12
#تعریف_کړه GETPRINTINGOFFSET 13
#تعریف_کړه GETSCALINGFACTOR 14
#تعریف_کړه MFCOMMENT 15
#تعریف_کړه GETPENWIDTH 16
#تعریف_کړه SETCOPYCOUNT 17
#تعریف_کړه SELECTPAPERSOURCE 18
#تعریف_کړه DEVICEDATA 19
#تعریف_کړه PASSTHROUGH 19
#تعریف_کړه GETTECHNOLGY 20
#تعریف_کړه GETTECHNOLOGY 20
#تعریف_کړه SETLINECAP 21
#تعریف_کړه SETLINEJOIN 22
#تعریف_کړه SETMITERLIMIT 23
#تعریف_کړه BANDINFO 24
#تعریف_کړه DRAWPATTERNRECT 25
#تعریف_کړه GETVECTORPENSIZE 26
#تعریف_کړه GETVECTORBRUSHSIZE 27
#تعریف_کړه ENABLEDUPLEX 28
#تعریف_کړه GETSETPAPERBINS 29
#تعریف_کړه GETSETPRINTORIENT 30
#تعریف_کړه ENUMPAPERBINS 31
#تعریف_کړه SETDIBSCALING 32
#تعریف_کړه EPSPRINTING 33
#تعریف_کړه ENUMPAPERMETRICS 34
#تعریف_کړه GETSETPAPERMETRICS 35
#تعریف_کړه POSTSCRIPT_معلومات 37
#تعریف_کړه POSTSCRIPT_IGNORE 38
#تعریف_کړه MOUSETRAILS 39
#تعریف_کړه GETDEVICEUNITS 42

#تعریف_کړه GETEXTENDEDTEXTMETRICS 256
#تعریف_کړه GETEXTENTTABLE 257
#تعریف_کړه GETPAIRKERNTABLE 258
#تعریف_کړه GETTRACKKERNTABLE 259
#تعریف_کړه EXTTEXTOUT 512
#تعریف_کړه GETFACENAME 513
#تعریف_کړه DOWNLOADFACE 514
#تعریف_کړه ENABLERELATIVEWIDTHS 768
#تعریف_کړه ENABLEPAIRKERNING 769
#تعریف_کړه SETKERNTRACK 770
#تعریف_کړه SETALLJUSTVALUES 771
#تعریف_کړه SETCHARSET 772

#تعریف_کړه STRETCHBLT 2048
#تعریف_کړه METAFILE_DRIVER 2049
#تعریف_کړه GETSETSCREENPARAMS 3072
#تعریف_کړه QUERYDIBSUPPORT 3073
#تعریف_کړه BEGIN_لار 4096
#تعریف_کړه CLIP_منزل_لار 4097
#تعریف_کړه پای_ټکی_لار 4098
#تعریف_کړه EXT_DEVICE_CAPS 4099
#تعریف_کړه RESTORE_CTM 4100
#تعریف_کړه SAVE_CTM 4101
#تعریف_کړه سېټ_ARC_DIRECTION 4102
#تعریف_کړه سېټ_BACKGROUND_COLOR 4103
#تعریف_کړه سېټ_POLY_ډېرپېښ 4104
#تعریف_کړه سېټ_SCREEN_ANGLE 4105
#تعریف_کړه سېټ_خپرېدنه 4106
#تعریف_کړه TRANSFORM_CTM 4107
#تعریف_کړه سېټ_CLIP_BOX 4108
#تعریف_کړه سېټ_BOUNDS 4109
#تعریف_کړه سېټ_MIRROR_ډېرپېښ 4110
#تعریف_کړه OPENCHANNEL 4110
#تعریف_کړه DOWNLOADHEADER 4111
#تعریف_کړه CLOSECHANNEL 4112
#تعریف_کړه POSTSCRIPT_PASSTHROUGH 4115
#تعریف_کړه ENCAPSULATED_POSTSCRIPT 4116

#تعریف_کړه POSTSCRIPT_IDENTIFY 4117
#تعریف_کړه POSTSCRIPT_INJECTION 4118

#تعریف_کړه CHECKJPEGFORMAT 4119
#تعریف_کړه CHECKPNGFORMAT 4120

#تعریف_کړه GET_PS_FEATURESETTING 4121

#تعریف_کړه SPCLPASSTHROUGH2 4568

#تعریف_کړه PSIDENT_GDICENTRIC 0
#تعریف_کړه PSIDENT_PSCENTRIC 1

  تعريفنوع بنية _PSINJECTDATA {
    DWORD معلومات_بایټونه;
    کلمه_3 Injection_ټکی;
    کلمه_3 پاڼه_شمېره;
  } PSINJECTDATA,*PPSINJECTDATA;

#تعریف_کړه PSINJECT_BEGINSTREAM 1
#تعریف_کړه PSINJECT_PSADOBE 2
#تعریف_کړه PSINJECT_PAGESATEND 3
#تعریف_کړه PSINJECT_پاڼې 4

#تعریف_کړه PSINJECT_DOCNEEDEDRES 5
#تعریف_کړه PSINJECT_DOCSUPPLIEDRES 6
#تعریف_کړه PSINJECT_PAGEORDER 7
#تعریف_کړه PSINJECT_ORIENTATION 8
#تعریف_کړه PSINJECT_BOUNDINGBOX 9
#تعریف_کړه PSINJECT_DOCUMENTPROCESSCOLORS 10

#تعریف_کړه PSINJECT_COMMENTS 11
#تعریف_کړه PSINJECT_BEGINDEFAULTS 12
#تعریف_کړه PSINJECT_ENDDEFAULTS 13
#تعریف_کړه PSINJECT_BEGINPROLOG 14
#تعریف_کړه PSINJECT_ENDPROLOG 15
#تعریف_کړه PSINJECT_BEGINSETUP 16
#تعریف_کړه PSINJECT_ENDSETUP 17
#تعریف_کړه PSINJECT_TRAILER 18
#تعریف_کړه PSINJECT_EOF 19
#تعریف_کړه PSINJECT_ENDSTREAM 20
#تعریف_کړه PSINJECT_DOCUMENTPROCESSCOLORSATEND 21

#تعریف_کړه PSINJECT_PAGENUMBER 100
#تعریف_کړه PSINJECT_BEGINPAGESETUP 101
#تعریف_کړه PSINJECT_ENDPAGESETUP 102
#تعریف_کړه PSINJECT_PAGETRAILER 103
#تعریف_کړه PSINJECT_PLATECOLOR 104

#تعریف_کړه PSINJECT_SHOWPAGE 105
#تعریف_کړه PSINJECT_PAGEBBOX 106
#تعریف_کړه PSINJECT_ENDPAGECOMMENTS 107

#تعریف_کړه PSINJECT_VMSAVE 200
#تعریف_کړه PSINJECT_VMRESTORE 201

#تعریف_کړه FEATURESETTING_NUP 0
#تعریف_کړه FEATURESETTING_OUTPUT 1
#تعریف_کړه FEATURESETTING_PSLEVEL 2
#تعریف_کړه FEATURESETTING_CUSTPAPER 3
#تعریف_کړه FEATURESETTING_MIRROR 4
#تعریف_کړه FEATURESETTING_NEGATIVE 5
#تعریف_کړه FEATURESETTING_PROTOCOL 6

#تعریف_کړه FEATURESETTING_شخصي_BEGIN 0x1000
#تعریف_کړه FEATURESETTING_شخصي_پای_ټکی 0x1FFF

  تعريفنوع بنية _PSFEATURE_OUTPUT {
    WINBOOL b_پاڼه_Independent;
    WINBOOL b_سېټ_پاڼه_Device;
  } PSFEATURE_OUTPUT,*PPSFEATURE_OUTPUT;

  تعريفنوع بنية _PSFEATURE_CUSTPAPER {
    LONG lOrientation;
    LONG l_پلنوالی;
    LONG l_لوړوالی;
    LONG l_پلنوالی_دننه_واټن;
    LONG l_لوړوالی_دننه_واټن;
  } PSFEATURE_CUSTPAPER,*PPSFEATURE_CUSTPAPER;

#تعریف_کړه PSPROTOCOL_ASCII 0
#تعریف_کړه PSPROTOCOL_BCP 1
#تعریف_کړه PSPROTOCOL_TBCP 2
#تعریف_کړه PSPROTOCOL_دوګونی 3

#تعریف_کړه QDI_SETDIBITS 1
#تعریف_کړه QDI_GETDIBITS 2
#تعریف_کړه QDI_DIBTOSCREEN 4
#تعریف_کړه QDI_STRETCHDIB 8

#تعریف_کړه SP_NOTREPORTED 0x4000
#تعریف_کړه SP_ERROR (-1)
#تعریف_کړه SP_APPABORT (-2)
#تعریف_کړه SP_USERABORT (-3)
#تعریف_کړه SP_OUTOFDISK (-4)
#تعریف_کړه SP_OUTOFMEMORY (-5)

#تعریف_کړه PR_JOBSTATUS 0x0000

#تعریف_کړه OBJ_PEN 1
#تعریف_کړه OBJ_BRUSH 2
#تعریف_کړه OBJ_DC 3
#تعریف_کړه OBJ_METADC 4
#تعریف_کړه OBJ_PAL 5
#تعریف_کړه OBJ_FONT 6
#تعریف_کړه OBJ_BITMAP 7
#تعریف_کړه OBJ_REGION 8
#تعریف_کړه OBJ_METAFILE 9
#تعریف_کړه OBJ_MEMDC 10
#تعریف_کړه OBJ_EXTPEN 11
#تعریف_کړه OBJ_ENHMETADC 12
#تعریف_کړه OBJ_ENHMETAFILE 13
#تعریف_کړه OBJ_COLORSPACE 14

#تعریف_کړه MWT_بې_اغېزه_عنصر 1
#تعریف_کړه MWT_LEFTMULTIPLY 2
#تعریف_کړه MWT_RIGHTMULTIPLY 3

#تعریف_کړه MWT_MIN MWT_بې_اغېزه_عنصر
#تعریف_کړه MWT_MAX MWT_RIGHTMULTIPLY

#تعریف_کړه _XFORM_
  تعريفنوع بنية نښان_XFORM {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
  } XFORM,*PXFORM,*LPXFORM;

  تعريفنوع بنية نښان_BITMAP {
    LONG bmType;
    LONG bm_پلنوالی;
    LONG bm_لوړوالی;
    LONG bm_پلنوالی_بایټونه;
    کلمه_3 bmPlanes;
    کلمه_3 bm_بټونه_Pixel;
    LPVOID bm_بټونه;
  } BITMAP,*PBITMAP,*NPBITMAP,*LPBITMAP;

#ضمن <pshpack1.h>
  تعريفنوع بنية نښان_RGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
  } RGBTRIPLE;
#ضمن <poppack.h>

  تعريفنوع بنية نښان_RGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
  } RGBQUAD;
  تعريفنوع RGBQUAD *LPRGBQUAD;

#تعریف_کړه CS_ENABLE 0x00000001L
#تعریف_کړه CS_DISABLE 0x00000002L
#تعریف_کړه CS_DELETE_TRANSFORM 0x00000003L

//!__TINYC__: #define LCS_SIGNATURE 'PSOC'
//!__TINYC__: #define LCS_sRGB 'sRGB'
//!__TINYC__: #define LCS_WINDOWS_COLOR_SPACE 'Win '

  تعريفنوع LONG LCSCSTYPE;
#تعریف_کړه LCS_CALIBRATED_RGB 0x00000000L

  تعريفنوع LONG LCSGAMUTMATCH;
#تعریف_کړه LCS_GM_BUSINESS 0x00000001L
#تعریف_کړه LCS_GM_GRAPHICS 0x00000002L
#تعریف_کړه LCS_GM_IMAGES 0x00000004L
#تعریف_کړه LCS_GM_ABS_COLORIMETRIC 0x00000008L

#تعریف_کړه CM_بهر_د_GAMUT 255
#تعریف_کړه CM_دننه_GAMUT 0

#تعریف_کړه ICM_ADDPROFILE 1
#تعریف_کړه ICM_DELETEPROFILE 2
#تعریف_کړه ICM_QUERYPROFILE 3
#تعریف_کړه ICM_SETDEFAULTPROFILE 4
#تعریف_کړه ICM_REGISTERICMATCHER 5
#تعریف_کړه ICM_UNREGISTERICMATCHER 6
#تعریف_کړه ICM_QUERYMATCH 7

#تعریف_کړه GetKValue(cmyk) ((BYTE)(cmyk))
#تعریف_کړه GetYValue(cmyk) ((BYTE)((cmyk)>> 8))
#تعریف_کړه GetMValue(cmyk) ((BYTE)((cmyk)>>16))
#تعریف_کړه GetCValue(cmyk) ((BYTE)((cmyk)>>24))

#تعریف_کړه CMYK(c,m,y,k) ((COLORREF)((((BYTE)(k)|((کلمه_3)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

  تعريفنوع اوږد FXPT16DOT16,*LPFXPT16DOT16;
  تعريفنوع اوږد FXPT2DOT30,*LPFXPT2DOT30;

  تعريفنوع بنية نښان_CIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
  } CIEXYZ;
  تعريفنوع CIEXYZ *LPCIEXYZ;

  تعريفنوع بنية نښان_ICEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
  } CIEXYZTRIPLE;

  تعريفنوع CIEXYZTRIPLE *LPCIEXYZTRIPLE;

  تعريفنوع بنية نښان_LOGCOLORSPACEA {
    DWORD lcsSignature;
    DWORD lcs_نسخه;
    DWORD lcs_اندازه;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    CHAR lcsFilename[MAX_لار];
  } LOGCOLORSPACEA,*LPLOGCOLORSPACEA;

  تعريفنوع بنية نښان_LOGCOLORSPACEW {
    DWORD lcsSignature;
    DWORD lcs_نسخه;
    DWORD lcs_اندازه;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    WCHAR lcsFilename[MAX_لار];
  } LOGCOLORSPACEW,*LPLOGCOLORSPACEW;

#که_تعریف_شوی UNICODE
  تعريفنوع LOGCOLORSPACEW LOGCOLORSPACE;
  تعريفنوع LPLOGCOLORSPACEW LPLOGCOLORSPACE;
#وإلا
  تعريفنوع LOGCOLORSPACEA LOGCOLORSPACE;
  تعريفنوع LPLOGCOLORSPACEA LPLOGCOLORSPACE;
#د_که_پای

  تعريفنوع بنية نښان_BITMAPCOREHEADER {
    DWORD bc_اندازه;
    کلمه_3 bc_پلنوالی;
    کلمه_3 bc_لوړوالی;
    کلمه_3 bcPlanes;
    کلمه_3 bc_بټ_شمېر;
  } BITMAPCOREHEADER,*LPBITMAPCOREHEADER,*PBITMAPCOREHEADER;

  تعريفنوع بنية نښان_BITMAPINFOHEADER {
    DWORD bi_اندازه;
    LONG bi_پلنوالی;
    LONG bi_لوړوالی;
    کلمه_3 biPlanes;
    کلمه_3 bi_بټ_شمېر;
    DWORD biCompression;
    DWORD bi_اندازه_Image;
    LONG bi_XPels_فی_Meter;
    LONG bi_YPels_فی_Meter;
    DWORD bi_Clr_کارول_شوی;
    DWORD biClrImportant;
  } BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

  تعريفنوع بنية {
    DWORD b_V4_اندازه;
    LONG b_V4_پلنوالی;
    LONG b_V4_لوړوالی;
    کلمه_3 bV4Planes;
    کلمه_3 b_V4_بټ_شمېر;
    DWORD bV4V4Compression;
    DWORD b_V4_اندازه_Image;
    LONG b_V4_XPels_فی_Meter;
    LONG b_V4_YPels_فی_Meter;
    DWORD b_V4_Clr_کارول_شوی;
    DWORD bV4ClrImportant;
    DWORD b_V4_Red_ماسک;
    DWORD b_V4_Green_ماسک;
    DWORD b_V4_Blue_ماسک;
    DWORD b_V4_Alpha_ماسک;
    DWORD bV4CSType;
    CIEXYZTRIPLE bV4Endpoints;
    DWORD bV4GammaRed;
    DWORD bV4GammaGreen;
    DWORD bV4GammaBlue;
  } BITMAPV4_سرلیک,*LPBITMAPV4_سرلیک,*PBITMAPV4_سرلیک;

  تعريفنوع بنية {
    DWORD b_V5_اندازه;
    LONG b_V5_پلنوالی;
    LONG b_V5_لوړوالی;
    کلمه_3 bV5Planes;
    کلمه_3 b_V5_بټ_شمېر;
    DWORD bV5Compression;
    DWORD b_V5_اندازه_Image;
    LONG b_V5_XPels_فی_Meter;
    LONG b_V5_YPels_فی_Meter;
    DWORD b_V5_Clr_کارول_شوی;
    DWORD bV5ClrImportant;
    DWORD b_V5_Red_ماسک;
    DWORD b_V5_Green_ماسک;
    DWORD b_V5_Blue_ماسک;
    DWORD b_V5_Alpha_ماسک;
    DWORD bV5CSType;
    CIEXYZTRIPLE bV5Endpoints;
    DWORD bV5GammaRed;
    DWORD bV5GammaGreen;
    DWORD bV5GammaBlue;
    DWORD bV5Intent;
    DWORD b_V5_Profile_معلومات;
    DWORD b_V5_Profile_اندازه;
    DWORD bV5Reserved;
  } BITMAPV5_سرلیک,*LPBITMAPV5_سرلیک,*PBITMAPV5_سرلیک;

//!__TINYC__: #define PROFILE_LINKED 'LINK'
//!__TINYC__: #define PROFILE_EMBEDDED 'MBED'

#تعریف_کړه BI_RGB 0L
#تعریف_کړه BI_RLE8 1L
#تعریف_کړه BI_RLE4 2L
#تعریف_کړه BI_BITFIELDS 3L
#تعریف_کړه BI_JPEG 4L
#تعریف_کړه BI_PNG 5L

  تعريفنوع بنية نښان_BITMAPINFO {
    BITMAPINFOHEADER bmi_سرلیک;
    RGBQUAD bmiColors[1];
  } BITMAPINFO,*LPBITMAPINFO,*PBITMAPINFO;

  تعريفنوع بنية نښان_BITMAPCOREINFO {
    BITMAPCOREHEADER bmci_سرلیک;
    RGBTRIPLE bmciColors[1];
  } BITMAPCOREINFO,*LPBITMAPCOREINFO,*PBITMAPCOREINFO;

#ضمن <pshpack2.h>
  تعريفنوع بنية نښان_BITMAPFILEHEADER {
    کلمه_3 bfType;
    DWORD bf_اندازه;
    کلمه_3 bfReserved1;
    کلمه_3 bfReserved2;
    DWORD bf_Off_بټونه;
  } BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#ضمن <poppack.h>

#تعریف_کړه MAKEPOINTS(l) (*((POINTS *)&(l)))

#که_نه_تعریف_شوی NOFONTSIG
  تعريفنوع بنية نښان_FONTSIGNATURE {
    DWORD fsUsb[4];
    DWORD fsCsb[2];
  } FONTSIGNATURE,*PFONTSIGNATURE,*LPFONTSIGNATURE;

  تعريفنوع بنية نښان_CHARSETINFO {
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
  } CHARSETINFO,*PCHARSETINFO,*NPCHARSETINFO,*LPCHARSETINFO;

#تعریف_کړه TCI_SRCCHARSET 1
#تعریف_کړه TCI_SRCCODEPAGE 2
#تعریف_کړه TCI_SRCFONTSIG 3
#تعریف_کړه TCI_SRCLOCALE 0x1000

  تعريفنوع بنية نښان_LOCALESIGNATURE {
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
  } LOCALESIGNATURE,*PLOCALESIGNATURE,*LPLOCALESIGNATURE;
#د_که_پای


#که_نه_تعریف_شوی NOMETAFILE
  تعريفنوع بنية نښان_HANDLETABLE {
    HGDIOBJ objectHandle[1];
  } HANDLETABLE,*PHANDLETABLE,*LPHANDLETABLE;

  تعريفنوع بنية نښان_METARECORD {
    DWORD rd_اندازه;
    کلمه_3 rdFunction;
    کلمه_3 rdParm[1];
  } METARECORD;
  تعريفنوع بنية نښان_METARECORD UNALIGNED *PMETARECORD;
  تعريفنوع بنية نښان_METARECORD UNALIGNED *LPMETARECORD;

  تعريفنوع بنية نښان_METAFILEPICT {
    LONG mm;
    LONG xExt;
    LONG yExt;
    HMETAFILE hMF;
  } METAFILEPICT,*LPMETAFILEPICT;

#ضمن <pshpack2.h>
  تعريفنوع بنية نښان_METAHEADER {
    کلمه_3 mtType;
    کلمه_3 mt_سرلیک_اندازه;
    کلمه_3 mt_نسخه;
    DWORD mt_اندازه;
    کلمه_3 mtNoObjects;
    DWORD mt_Max_ریکارډ;
    کلمه_3 mtNoParameters;
  } METAHEADER;
  تعريفنوع بنية نښان_METAHEADER UNALIGNED *PMETAHEADER;
  تعريفنوع بنية نښان_METAHEADER UNALIGNED *LPMETAHEADER;

#ضمن <poppack.h>

  تعريفنوع بنية نښان_ENHMETARECORD {
    DWORD iType;
    DWORD n_اندازه;
    DWORD dParm[1];
  } ENHMETARECORD,*PENHMETARECORD,*LPENHMETARECORD;

  تعريفنوع بنية نښان_ENHMETAHEADER {
    DWORD iType;
    DWORD n_اندازه;
    RECTL rclBounds;
    RECTL rcl_چوکاټ;
    DWORD dSignature;
    DWORD n_نسخه;
    DWORD n_بایټونه;
    DWORD n_ریکارډونه;
    کلمه_3 nHandles;
    کلمه_3 sReserved;
    DWORD nDescription;
    DWORD offDescription;
    DWORD nPalEntries;
    SIZEL szlDevice;
    SIZEL szlMillimeters;
    DWORD cbPixelFormat;
    DWORD offPixelFormat;
    DWORD bOpenGL;
    SIZEL szlMicrometers;
  } ENHMETAHEADER,*PENHMETAHEADER,*LPENHMETAHEADER;
#د_که_پای

#که_نه_تعریف_شوی NOTEXTMETRIC
#تعریف_کړه TMPF_FIXED_PITCH 0x01
#تعریف_کړه TMPF_ویکټور 0x02
#تعریف_کړه TMPF_DEVICE 0x08
#تعریف_کړه TMPF_TRUETYPE 0x04

#که_تعریف_شوی UNICODE
  تعريفنوع WCHAR BCHAR;
#وإلا
  تعريفنوع BYTE BCHAR;
#د_که_پای

#که_نه_تعریف_شوی _TEXTMETRIC_DEFINED
#تعریف_کړه _TEXTMETRIC_DEFINED
  تعريفنوع بنية نښان_TEXTMETRICA {
    LONG tm_لوړوالی;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_دننی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_پلنوالی;
    LONG tm_Max_Char_پلنوالی;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_لومړی_Char;
    BYTE tm_وروستی_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_بهر;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سېټ;
  } TEXTMETRICA,*PTEXTMETRICA,*NPTEXTMETRICA,*LPTEXTMETRICA;

  تعريفنوع بنية نښان_TEXTMETRICW {
    LONG tm_لوړوالی;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_دننی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_پلنوالی;
    LONG tm_Max_Char_پلنوالی;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_لومړی_Char;
    WCHAR tm_وروستی_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_بهر;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سېټ;
  } TEXTMETRICW,*PTEXTMETRICW,*NPTEXTMETRICW,*LPTEXTMETRICW;
#که_تعریف_شوی UNICODE
  تعريفنوع TEXTMETRICW TEXTMETRIC;
  تعريفنوع PTEXTMETRICW PTEXTMETRIC;
  تعريفنوع NPTEXTMETRICW NPTEXTMETRIC;
  تعريفنوع LPTEXTMETRICW LPTEXTMETRIC;
#وإلا
  تعريفنوع TEXTMETRICA TEXTMETRIC;
  تعريفنوع PTEXTMETRICA PTEXTMETRIC;
  تعريفنوع NPTEXTMETRICA NPTEXTMETRIC;
  تعريفنوع LPTEXTMETRICA LPTEXTMETRIC;
#د_که_پای
#د_که_پای

#تعریف_کړه NTM_REGULAR 0x00000040L
#تعریف_کړه NTM_BOLD 0x00000020L
#تعریف_کړه NTM_ITALIC 0x00000001L

#تعریف_کړه NTM_NONNEGATIVE_AC 0x00010000
#تعریف_کړه NTM_PS_OPENTYPE 0x00020000
#تعریف_کړه NTM_TT_OPENTYPE 0x00040000
#تعریف_کړه NTM_MULTIPLEMASTER 0x00080000
#تعریف_کړه NTM_TYPE1 0x00100000
#تعریف_کړه NTM_DSIG 0x00200000

#ضمن <pshpack4.h>
  تعريفنوع بنية نښان_NEWTEXTMETRICA {
    LONG tm_لوړوالی;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_دننی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_پلنوالی;
    LONG tm_Max_Char_پلنوالی;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_لومړی_Char;
    BYTE tm_وروستی_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_بهر;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سېټ;
    DWORD ntmFlags;
    UINT ntm_اندازه_EM;
    UINT ntm_Cell_لوړوالی;
    UINT ntm_Avg_پلنوالی;
  } NEWTEXTMETRICA,*PNEWTEXTMETRICA,*NPNEWTEXTMETRICA,*LPNEWTEXTMETRICA;

  تعريفنوع بنية نښان_NEWTEXTMETRICW {
    LONG tm_لوړوالی;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_دننی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_پلنوالی;
    LONG tm_Max_Char_پلنوالی;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_لومړی_Char;
    WCHAR tm_وروستی_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_بهر;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سېټ;
    DWORD ntmFlags;
    UINT ntm_اندازه_EM;
    UINT ntm_Cell_لوړوالی;
    UINT ntm_Avg_پلنوالی;
  } NEWTEXTMETRICW,*PNEWTEXTMETRICW,*NPNEWTEXTMETRICW,*LPNEWTEXTMETRICW;
#که_تعریف_شوی UNICODE
  تعريفنوع NEWTEXTMETRICW NEWTEXTMETRIC;
  تعريفنوع PNEWTEXTMETRICW PNEWTEXTMETRIC;
  تعريفنوع NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
  تعريفنوع LPNEWTEXTMETRICW LPNEWTEXTMETRIC;
#وإلا
  تعريفنوع NEWTEXTMETRICA NEWTEXTMETRIC;
  تعريفنوع PNEWTEXTMETRICA PNEWTEXTMETRIC;
  تعريفنوع NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
  تعريفنوع LPNEWTEXTMETRICA LPNEWTEXTMETRIC;
#د_که_پای
#ضمن <poppack.h>

  تعريفنوع بنية نښان_NEWTEXTMETRICEXA {
    NEWTEXTMETRICA ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXA;

  تعريفنوع بنية نښان_NEWTEXTMETRICEXW {
    NEWTEXTMETRICW ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXW;
#که_تعریف_شوی UNICODE
  تعريفنوع NEWTEXTMETRICEXW NEWTEXTMETRICEX;
#وإلا
  تعريفنوع NEWTEXTMETRICEXA NEWTEXTMETRICEX;
#د_که_پای
#د_که_پای

  تعريفنوع بنية نښان_PELARRAY {
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
  } PELARRAY,*PPELARRAY,*NPPELARRAY,*LPPELARRAY;

  تعريفنوع بنية نښان_LOGBRUSH {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
  } LOGBRUSH,*PLOGBRUSH,*NPLOGBRUSH,*LPLOGBRUSH;

  تعريفنوع بنية نښان_LOGBRUSH32 {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG lbHatch;
  } LOGBRUSH32,*PLOGBRUSH32,*NPLOGBRUSH32,*LPLOGBRUSH32;

  تعريفنوع LOGBRUSH نمونه_2;
  تعريفنوع نمونه_2 *PPATTERN;
  تعريفنوع نمونه_2 *NPPATTERN;
  تعريفنوع نمونه_2 *LPPATTERN;

  تعريفنوع بنية نښان_LOGPEN {
    UINT lopnStyle;
    ټکی_3 lopn_پلنوالی;
    COLORREF lopnColor;
  } LOGPEN,*PLOGPEN,*NPLOGPEN,*LPLOGPEN;

  تعريفنوع بنية نښان_EXTLOGPEN {
    DWORD elpPenStyle;
    DWORD elp_پلنوالی;
    UINT elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elp_عدد_Entries;
    DWORD elp_Style_ثبت[1];
  } EXTLOGPEN,*PEXTLOGPEN,*NPEXTLOGPEN,*LPEXTLOGPEN;

#که_نه_تعریف_شوی _PALETTEENTRY_DEFINED
#تعریف_کړه _PALETTEENTRY_DEFINED
  تعريفنوع بنية نښان_PALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
  } PALETTEENTRY,*PPALETTEENTRY,*LPPALETTEENTRY;
#د_که_پای

#که_نه_تعریف_شوی _LOGPALETTE_DEFINED
#تعریف_کړه _LOGPALETTE_DEFINED

  تعريفنوع بنية نښان_LOGPALETTE {
    کلمه_3 pal_نسخه;
    کلمه_3 pal_عدد_Entries;
    PALETTEENTRY pal_Pal_ثبت[1];
  } LOGPALETTE,*PLOGPALETTE,*NPLOGPALETTE,*LPLOGPALETTE;
#د_که_پای

#تعریف_کړه LF_FACESIZE 32

  تعريفنوع بنية نښان_LOGFONTA {
    LONG lf_لوړوالی;
    LONG lf_پلنوالی;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_وزن;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_بهر;
    BYTE lf_Char_سېټ;
    BYTE lf_بهر_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[LF_FACESIZE];
  } LOGFONTA,*PLOGFONTA,*NPLOGFONTA,*LPLOGFONTA;

  تعريفنوع بنية نښان_LOGFONTW {
    LONG lf_لوړوالی;
    LONG lf_پلنوالی;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_وزن;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_بهر;
    BYTE lf_Char_سېټ;
    BYTE lf_بهر_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[LF_FACESIZE];
  } LOGFONTW,*PLOGFONTW,*NPLOGFONTW,*LPLOGFONTW;
#که_تعریف_شوی UNICODE
  تعريفنوع LOGFONTW LOGFONT;
  تعريفنوع PLOGFONTW PLOGFONT;
  تعريفنوع NPLOGFONTW NPLOGFONT;
  تعريفنوع LPLOGFONTW LPLOGFONT;
#وإلا
  تعريفنوع LOGFONTA LOGFONT;
  تعريفنوع PLOGFONTA PLOGFONT;
  تعريفنوع NPLOGFONTA NPLOGFONT;
  تعريفنوع LPLOGFONTA LPLOGFONT;
#د_که_پای

#تعریف_کړه LF_FULLFACESIZE 64

  تعريفنوع بنية نښان_ENUMLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_ډک_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
  } ENUMLOGFONTA,*LPENUMLOGFONTA;

  تعريفنوع بنية نښان_ENUMLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_ډک_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
  } ENUMLOGFONTW,*LPENUMLOGFONTW;
#که_تعریف_شوی UNICODE
  تعريفنوع ENUMLOGFONTW ENUMLOGFONT;
  تعريفنوع LPENUMLOGFONTW LPENUMLOGFONT;
#وإلا
  تعريفنوع ENUMLOGFONTA ENUMLOGFONT;
  تعريفنوع LPENUMLOGFONTA LPENUMLOGFONT;
#د_که_پای

  تعريفنوع بنية نښان_ENUMLOGFONTEXA {
    LOGFONTA elfLogFont;
    BYTE elf_ډک_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    BYTE elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXA,*LPENUMLOGFONTEXA;

  تعريفنوع بنية نښان_ENUMLOGFONTEXW {
    LOGFONTW elfLogFont;
    WCHAR elf_ډک_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    WCHAR elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXW,*LPENUMLOGFONTEXW;
#که_تعریف_شوی UNICODE
  تعريفنوع ENUMLOGFONTEXW ENUMLOGFONTEX;
  تعريفنوع LPENUMLOGFONTEXW LPENUMLOGFONTEX;
#وإلا
  تعريفنوع ENUMLOGFONTEXA ENUMLOGFONTEX;
  تعريفنوع LPENUMLOGFONTEXA LPENUMLOGFONTEX;
#د_که_پای

#تعریف_کړه بهر_DEFAULT_PRECIS 0
#تعریف_کړه بهر_STRING_PRECIS 1
#تعریف_کړه بهر_CHARACTER_PRECIS 2
#تعریف_کړه بهر_STROKE_PRECIS 3
#تعریف_کړه بهر_TT_PRECIS 4
#تعریف_کړه بهر_DEVICE_PRECIS 5
#تعریف_کړه بهر_RASTER_PRECIS 6
#تعریف_کړه بهر_TT_ONLY_PRECIS 7
#تعریف_کړه بهر_OUTLINE_PRECIS 8
#تعریف_کړه بهر_SCREEN_OUTLINE_PRECIS 9
#تعریف_کړه بهر_PS_ONLY_PRECIS 10

#تعریف_کړه CLIP_DEFAULT_PRECIS 0
#تعریف_کړه CLIP_CHARACTER_PRECIS 1
#تعریف_کړه CLIP_STROKE_PRECIS 2
#تعریف_کړه CLIP_ماسک 0xf
#تعریف_کړه CLIP_LH_ANGLES (1<<4)
#تعریف_کړه CLIP_TT_ALWAYS (2<<4)
#تعریف_کړه CLIP_DFA_DISABLE (4<<4)
#تعریف_کړه CLIP_EMBEDDED (8<<4)

#تعریف_کړه DEFAULT_QUALITY 0
#تعریف_کړه DRAFT_QUALITY 1
#تعریف_کړه PROOF_QUALITY 2
#تعریف_کړه NONANTIALIASED_QUALITY 3
#تعریف_کړه ANTIALIASED_QUALITY 4

#تعریف_کړه CLEARTYPE_QUALITY 5
#تعریف_کړه CLEARTYPE_NATURAL_QUALITY 6

#تعریف_کړه DEFAULT_PITCH 0
#تعریف_کړه FIXED_PITCH 1
#تعریف_کړه VARIABLE_PITCH 2
#تعریف_کړه MONO_FONT 8

#تعریف_کړه ANSI_CHARSET 0
#تعریف_کړه DEFAULT_CHARSET 1
#تعریف_کړه نښه_CHARSET 2
#تعریف_کړه SHIFTJIS_CHARSET 128
#تعریف_کړه HANGEUL_CHARSET 129
#تعریف_کړه HANGUL_CHARSET 129
#تعریف_کړه GB2312_CHARSET 134
#تعریف_کړه CHINESEBIG5_CHARSET 136
#تعریف_کړه OEM_CHARSET 255
#تعریف_کړه JOHAB_CHARSET 130
#تعریف_کړه HEBREW_CHARSET 177
#تعریف_کړه ARABIC_CHARSET 178
#تعریف_کړه GREEK_CHARSET 161
#تعریف_کړه TURKISH_CHARSET 162
#تعریف_کړه VIETNAMESE_CHARSET 163
#تعریف_کړه THAI_CHARSET 222
#تعریف_کړه EASTEUROPE_CHARSET 238
#تعریف_کړه RUSSIAN_CHARSET 204

#تعریف_کړه MAC_CHARSET 77
#تعریف_کړه BALTIC_CHARSET 186

#تعریف_کړه FS_LATIN1 0x00000001L
#تعریف_کړه FS_LATIN2 0x00000002L
#تعریف_کړه FS_CYRILLIC 0x00000004L
#تعریف_کړه FS_GREEK 0x00000008L
#تعریف_کړه FS_TURKISH 0x00000010L
#تعریف_کړه FS_HEBREW 0x00000020L
#تعریف_کړه FS_ARABIC 0x00000040L
#تعریف_کړه FS_BALTIC 0x00000080L
#تعریف_کړه FS_VIETNAMESE 0x00000100L
#تعریف_کړه FS_THAI 0x00010000L
#تعریف_کړه FS_JISJAPAN 0x00020000L
#تعریف_کړه FS_CHINESESIMP 0x00040000L
#تعریف_کړه FS_WANSUNG 0x00080000L
#تعریف_کړه FS_CHINESETRAD 0x00100000L
#تعریف_کړه FS_JOHAB 0x00200000L
#تعریف_کړه FS_نښه 0x80000000L

#تعریف_کړه FF_DONTCARE (0<<4)
#تعریف_کړه FF_ROMAN (1<<4)

#تعریف_کړه FF_SWISS (2<<4)

#تعریف_کړه FF_MODERN (3<<4)

#تعریف_کړه FF_SCRIPT (4<<4)
#تعریف_کړه FF_DECORATIVE (5<<4)

#تعریف_کړه FW_DONTCARE 0
#تعریف_کړه FW_THIN 100
#تعریف_کړه FW_EXTRALIGHT 200
#تعریف_کړه FW_LIGHT 300
#تعریف_کړه FW_نورمال 400
#تعریف_کړه FW_MEDIUM 500
#تعریف_کړه FW_SEMIBOLD 600
#تعریف_کړه FW_BOLD 700
#تعریف_کړه FW_EXTRABOLD 800
#تعریف_کړه FW_HEAVY 900

#تعریف_کړه FW_ULTRALIGHT FW_EXTRALIGHT
#تعریف_کړه FW_REGULAR FW_نورمال
#تعریف_کړه FW_DEMIBOLD FW_SEMIBOLD
#تعریف_کړه FW_ULTRABOLD FW_EXTRABOLD
#تعریف_کړه FW_BLACK FW_HEAVY

#تعریف_کړه PANOSE_شمېر 10
#تعریف_کړه PAN_FAMILYTYPE_شاخص 0
#تعریف_کړه PAN_SERIFSTYLE_شاخص 1
#تعریف_کړه PAN_وزن_شاخص 2
#تعریف_کړه PAN_PROPORTION_شاخص 3
#تعریف_کړه PAN_CONTRAST_شاخص 4
#تعریف_کړه PAN_STROKEVARIATION_شاخص 5
#تعریف_کړه PAN_ARMSTYLE_شاخص 6
#تعریف_کړه PAN_LETTERFORM_شاخص 7
#تعریف_کړه PAN_MIDLINE_شاخص 8
#تعریف_کړه PAN_XHEIGHT_شاخص 9

#تعریف_کړه PAN_CULTURE_LATIN 0

  تعريفنوع بنية نښان_PANOSE {
    BYTE bFamilyType;
    BYTE bSerifStyle;
    BYTE b_وزن;
    BYTE bProportion;
    BYTE bContrast;
    BYTE bStrokeVariation;
    BYTE bArmStyle;
    BYTE bLetterform;
    BYTE bMidline;
    BYTE bXHeight;
  } PANOSE,*LPPANOSE;

#تعریف_کړه PAN_ANY 0
#تعریف_کړه PAN_NO_FIT 1

#تعریف_کړه PAN_FAMILY_متن_DISPLAY 2
#تعریف_کړه PAN_FAMILY_SCRIPT 3
#تعریف_کړه PAN_FAMILY_DECORATIVE 4
#تعریف_کړه PAN_FAMILY_PICTORIAL 5

#تعریف_کړه PAN_SERIF_COVE 2
#تعریف_کړه PAN_SERIF_OBTUSE_COVE 3
#تعریف_کړه PAN_SERIF_مربع_COVE 4
#تعریف_کړه PAN_SERIF_OBTUSE_مربع_COVE 5
#تعریف_کړه PAN_SERIF_مربع 6
#تعریف_کړه PAN_SERIF_THIN 7
#تعریف_کړه PAN_SERIF_BONE 8
#تعریف_کړه PAN_SERIF_EXAGGERATED 9
#تعریف_کړه PAN_SERIF_TRIANGLE 10
#تعریف_کړه PAN_SERIF_نورمال_SANS 11
#تعریف_کړه PAN_SERIF_OBTUSE_SANS 12
#تعریف_کړه PAN_SERIF_PERP_SANS 13
#تعریف_کړه PAN_SERIF_FLARED 14
#تعریف_کړه PAN_SERIF_ROUNDED 15

#تعریف_کړه PAN_وزن_VERY_LIGHT 2
#تعریف_کړه PAN_وزن_LIGHT 3
#تعریف_کړه PAN_وزن_THIN 4
#تعریف_کړه PAN_وزن_BOOK 5
#تعریف_کړه PAN_وزن_MEDIUM 6
#تعریف_کړه PAN_وزن_DEMI 7
#تعریف_کړه PAN_وزن_BOLD 8
#تعریف_کړه PAN_وزن_HEAVY 9
#تعریف_کړه PAN_وزن_BLACK 10
#تعریف_کړه PAN_وزن_NORD 11

#تعریف_کړه PAN_PROP_OLD_STYLE 2
#تعریف_کړه PAN_PROP_MODERN 3
#تعریف_کړه PAN_PROP_EVEN_پلنوالی 4
#تعریف_کړه PAN_PROP_EXPANDED 5
#تعریف_کړه PAN_PROP_CONDENSED 6
#تعریف_کړه PAN_PROP_VERY_EXPANDED 7
#تعریف_کړه PAN_PROP_VERY_CONDENSED 8
#تعریف_کړه PAN_PROP_MONOSPACED 9

#تعریف_کړه PAN_CONTRAST_NONE 2
#تعریف_کړه PAN_CONTRAST_VERY_ټیټ 3
#تعریف_کړه PAN_CONTRAST_ټیټ 4
#تعریف_کړه PAN_CONTRAST_MEDIUM_ټیټ 5
#تعریف_کړه PAN_CONTRAST_MEDIUM 6
#تعریف_کړه PAN_CONTRAST_MEDIUM_لوړ 7
#تعریف_کړه PAN_CONTRAST_لوړ 8
#تعریف_کړه PAN_CONTRAST_VERY_لوړ 9

#تعریف_کړه PAN_STROKE_GRADUAL_DIAG 2
#تعریف_کړه PAN_STROKE_GRADUAL_TRAN 3
#تعریف_کړه PAN_STROKE_GRADUAL_VERT 4
#تعریف_کړه PAN_STROKE_GRADUAL_HORZ 5
#تعریف_کړه PAN_STROKE_RAPID_VERT 6
#تعریف_کړه PAN_STROKE_RAPID_HORZ 7
#تعریف_کړه PAN_STROKE_INSTANT_VERT 8

#تعریف_کړه PAN_STRAIGHT_ARMS_HORZ 2
#تعریف_کړه PAN_STRAIGHT_ARMS_WEDGE 3
#تعریف_کړه PAN_STRAIGHT_ARMS_VERT 4
#تعریف_کړه PAN_STRAIGHT_ARMS_SINGLE_SERIF 5
#تعریف_کړه PAN_STRAIGHT_ARMS_DOUBLE_SERIF 6
#تعریف_کړه PAN_BENT_ARMS_HORZ 7
#تعریف_کړه PAN_BENT_ARMS_WEDGE 8
#تعریف_کړه PAN_BENT_ARMS_VERT 9
#تعریف_کړه PAN_BENT_ARMS_SINGLE_SERIF 10
#تعریف_کړه PAN_BENT_ARMS_DOUBLE_SERIF 11

#تعریف_کړه PAN_LETT_نورمال_CONTACT 2
#تعریف_کړه PAN_LETT_نورمال_WEIGHTED 3
#تعریف_کړه PAN_LETT_نورمال_BOXED 4
#تعریف_کړه PAN_LETT_نورمال_FLATTENED 5
#تعریف_کړه PAN_LETT_نورمال_ROUNDED 6
#تعریف_کړه PAN_LETT_نورمال_OFF_CENTER 7
#تعریف_کړه PAN_LETT_نورمال_مربع 8
#تعریف_کړه PAN_LETT_OBLIQUE_CONTACT 9
#تعریف_کړه PAN_LETT_OBLIQUE_WEIGHTED 10
#تعریف_کړه PAN_LETT_OBLIQUE_BOXED 11
#تعریف_کړه PAN_LETT_OBLIQUE_FLATTENED 12
#تعریف_کړه PAN_LETT_OBLIQUE_ROUNDED 13
#تعریف_کړه PAN_LETT_OBLIQUE_OFF_CENTER 14
#تعریف_کړه PAN_LETT_OBLIQUE_مربع 15

#تعریف_کړه PAN_MIDLINE_STANDARD_TRIMMED 2
#تعریف_کړه PAN_MIDLINE_STANDARD_POINTED 3
#تعریف_کړه PAN_MIDLINE_STANDARD_SERIFED 4
#تعریف_کړه PAN_MIDLINE_لوړ_TRIMMED 5
#تعریف_کړه PAN_MIDLINE_لوړ_POINTED 6
#تعریف_کړه PAN_MIDLINE_لوړ_SERIFED 7
#تعریف_کړه PAN_MIDLINE_CONSTANT_TRIMMED 8
#تعریف_کړه PAN_MIDLINE_CONSTANT_POINTED 9
#تعریف_کړه PAN_MIDLINE_CONSTANT_SERIFED 10
#تعریف_کړه PAN_MIDLINE_ټیټ_TRIMMED 11
#تعریف_کړه PAN_MIDLINE_ټیټ_POINTED 12
#تعریف_کړه PAN_MIDLINE_ټیټ_SERIFED 13

#تعریف_کړه PAN_XHEIGHT_CONSTANT_SMALL 2
#تعریف_کړه PAN_XHEIGHT_CONSTANT_STD 3
#تعریف_کړه PAN_XHEIGHT_CONSTANT_LARGE 4
#تعریف_کړه PAN_XHEIGHT_DUCKING_SMALL 5
#تعریف_کړه PAN_XHEIGHT_DUCKING_STD 6
#تعریف_کړه PAN_XHEIGHT_DUCKING_LARGE 7

#تعریف_کړه ELF_VENDOR_اندازه 4

  تعريفنوع بنية نښان_EXTLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_ډک_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    DWORD elf_نسخه;
    DWORD elf_Style_اندازه;
    DWORD elf_سمون;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_اندازه];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTA,*PEXTLOGFONTA,*NPEXTLOGFONTA,*LPEXTLOGFONTA;

  تعريفنوع بنية نښان_EXTLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_ډک_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    DWORD elf_نسخه;
    DWORD elf_Style_اندازه;
    DWORD elf_سمون;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_اندازه];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTW,*PEXTLOGFONTW,*NPEXTLOGFONTW,*LPEXTLOGFONTW;
#که_تعریف_شوی UNICODE
  تعريفنوع EXTLOGFONTW EXTLOGFONT;
  تعريفنوع PEXTLOGFONTW PEXTLOGFONT;
  تعريفنوع NPEXTLOGFONTW NPEXTLOGFONT;
  تعريفنوع LPEXTLOGFONTW LPEXTLOGFONT;
#وإلا
  تعريفنوع EXTLOGFONTA EXTLOGFONT;
  تعريفنوع PEXTLOGFONTA PEXTLOGFONT;
  تعريفنوع NPEXTLOGFONTA NPEXTLOGFONT;
  تعريفنوع LPEXTLOGFONTA LPEXTLOGFONT;
#د_که_پای

#تعریف_کړه ELF_نسخه 0
#تعریف_کړه ELF_CULTURE_LATIN 0

#تعریف_کړه RASTER_FONTTYPE 0x0001
#تعریف_کړه DEVICE_FONTTYPE 0x002
#تعریف_کړه TRUETYPE_FONTTYPE 0x004

#تعریف_کړه RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((کلمه_3)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#تعریف_کړه PALETTERGB(r,g,b) (0x02000000 | RGB(r,g,b))
#تعریف_کړه PALETTEINDEX(i) ((COLORREF)(0x01000000 | (DWORD)(کلمه_3)(i)))

#تعریف_کړه PC_RESERVED 0x01
#تعریف_کړه PC_EXPLICIT 0x02
#تعریف_کړه PC_NOCOLLAPSE 0x04

#تعریف_کړه GetRValue(rgb) (LOBYTE(rgb))
#تعریف_کړه GetGValue(rgb) (LOBYTE(((کلمه_3)(rgb)) >> 8))
#تعریف_کړه GetBValue(rgb) (LOBYTE((rgb)>>16))

#تعریف_کړه TRANSPARENT 1
#تعریف_کړه OPAQUE 2
#تعریف_کړه BKMODE_وروستی 2

#تعریف_کړه GM_COMPATIBLE 1
#تعریف_کړه GM_ADVANCED 2
#تعریف_کړه GM_وروستی 2

#تعریف_کړه PT_CLOSEFIGURE 0x01
#تعریف_کړه PT_LINETO 0x02
#تعریف_کړه PT_BEZIERTO 0x04
#تعریف_کړه PT_MOVETO 0x06

#تعریف_کړه MM_متن 1
#تعریف_کړه MM_LOMETRIC 2
#تعریف_کړه MM_HIMETRIC 3
#تعریف_کړه MM_LOENGLISH 4
#تعریف_کړه MM_HIENGLISH 5
#تعریف_کړه MM_TWIPS 6
#تعریف_کړه MM_ISOTROPIC 7
#تعریف_کړه MM_ANISOTROPIC 8

#تعریف_کړه MM_MIN MM_متن
#تعریف_کړه MM_MAX MM_ANISOTROPIC
#تعریف_کړه MM_MAX_FIXEDSCALE MM_TWIPS

#تعریف_کړه ABSOLUTE 1
#تعریف_کړه RELATIVE 2

#تعریف_کړه WHITE_BRUSH 0
#تعریف_کړه LTGRAY_BRUSH 1
#تعریف_کړه خړ_BRUSH 2
#تعریف_کړه DKGRAY_BRUSH 3
#تعریف_کړه BLACK_BRUSH 4
#تعریف_کړه NULL_BRUSH 5
#تعریف_کړه HOLLOW_BRUSH NULL_BRUSH
#تعریف_کړه WHITE_PEN 6
#تعریف_کړه BLACK_PEN 7
#تعریف_کړه NULL_PEN 8
#تعریف_کړه OEM_FIXED_FONT 10
#تعریف_کړه ANSI_FIXED_FONT 11
#تعریف_کړه ANSI_VAR_FONT 12
#تعریف_کړه SYSTEM_FONT 13
#تعریف_کړه DEVICE_DEFAULT_FONT 14
#تعریف_کړه DEFAULT_PALETTE 15
#تعریف_کړه SYSTEM_FIXED_FONT 16

#تعریف_کړه DEFAULT_GUI_FONT 17

#تعریف_کړه DC_BRUSH 18
#تعریف_کړه DC_PEN 19

#تعریف_کړه STOCK_وروستی 19

#تعریف_کړه CLR_INVALID 0xFFFFFFFF

#تعریف_کړه BS_SOLID 0
#تعریف_کړه BS_NULL 1
#تعریف_کړه BS_HOLLOW BS_NULL
#تعریف_کړه BS_HATCHED 2
#تعریف_کړه BS_نمونه 3
#تعریف_کړه BS_شاخصي 4
#تعریف_کړه BS_DIBPATTERN 5
#تعریف_کړه BS_DIBPATTERNPT 6
#تعریف_کړه BS_PATTERN8X8 7
#تعریف_کړه BS_DIBPATTERN8X8 8
#تعریف_کړه BS_MONOPATTERN 9

#تعریف_کړه HS_HORIZONTAL 0
#تعریف_کړه HS_VERTICAL 1
#تعریف_کړه HS_FDIAGONAL 2
#تعریف_کړه HS_BDIAGONAL 3
#تعریف_کړه HS_CROSS 4
#تعریف_کړه HS_DIAGCROSS 5

#تعریف_کړه PS_SOLID 0
#تعریف_کړه PS_DASH 1
#تعریف_کړه PS_DOT 2
#تعریف_کړه PS_DASHDOT 3
#تعریف_کړه PS_DASHDOTDOT 4
#تعریف_کړه PS_NULL 5
#تعریف_کړه PS_INSIDEFRAME 6
#تعریف_کړه PS_USERSTYLE 7
#تعریف_کړه PS_ALTERNATE 8
#تعریف_کړه PS_STYLE_ماسک 0x0000000F

#تعریف_کړه PS_ENDCAP_پړاو 0x00000000
#تعریف_کړه PS_ENDCAP_مربع 0x00000100
#تعریف_کړه PS_ENDCAP_FLAT 0x00000200
#تعریف_کړه PS_ENDCAP_ماسک 0x00000F00

#تعریف_کړه PS_JOIN_پړاو 0x00000000
#تعریف_کړه PS_JOIN_BEVEL 0x00001000
#تعریف_کړه PS_JOIN_MITER 0x00002000
#تعریف_کړه PS_JOIN_ماسک 0x0000F000

#تعریف_کړه PS_COSMETIC 0x00000000
#تعریف_کړه PS_GEOMETRIC 0x00010000
#تعریف_کړه PS_TYPE_ماسک 0x000F0000

#تعریف_کړه AD_COUNTERCLOCKWISE 1
#تعریف_کړه AD_CLOCKWISE 2

#تعریف_کړه DRIVERVERSION 0
#تعریف_کړه TECHNOLOGY 2
#تعریف_کړه HORZSIZE 4
#تعریف_کړه VERTSIZE 6
#تعریف_کړه HORZRES 8
#تعریف_کړه VERTRES 10
#تعریف_کړه BITSPIXEL 12
#تعریف_کړه PLANES 14
#تعریف_کړه NUMBRUSHES 16
#تعریف_کړه NUMPENS 18
#تعریف_کړه NUMMARKERS 20
#تعریف_کړه NUMFONTS 22
#تعریف_کړه NUMCOLORS 24
#تعریف_کړه PDEVICESIZE 26
#تعریف_کړه CURVECAPS 28
#تعریف_کړه LINECAPS 30
#تعریف_کړه POLYGONALCAPS 32
#تعریف_کړه TEXTCAPS 34
#تعریف_کړه CLIPCAPS 36
#تعریف_کړه RASTERCAPS 38
#تعریف_کړه ASPECTX 40
#تعریف_کړه ASPECTY 42
#تعریف_کړه ASPECTXY 44

#تعریف_کړه LOGPIXELSX 88
#تعریف_کړه LOGPIXELSY 90

#تعریف_کړه SIZEPALETTE 104
#تعریف_کړه NUMRESERVED 106
#تعریف_کړه COLORRES 108

#تعریف_کړه PHYSICALWIDTH 110
#تعریف_کړه PHYSICALHEIGHT 111
#تعریف_کړه PHYSICALOFFSETX 112
#تعریف_کړه PHYSICALOFFSETY 113
#تعریف_کړه SCALINGFACTORX 114
#تعریف_کړه SCALINGFACTORY 115

#تعریف_کړه VREFRESH 116

#تعریف_کړه DESKTOPVERTRES 117

#تعریف_کړه DESKTOPHORZRES 118

#تعریف_کړه BLTALIGNMENT 119

#تعریف_کړه SHADEBLENDCAPS 120
#تعریف_کړه COLORMGMTCAPS 121

#که_نه_تعریف_شوی NOGDICAPMASKS
#تعریف_کړه DT_PLOTTER 0
#تعریف_کړه DT_RASDISPLAY 1
#تعریف_کړه DT_RASPRINTER 2
#تعریف_کړه DT_RASCAMERA 3
#تعریف_کړه DT_CHARSTREAM 4
#تعریف_کړه DT_METAFILE 5
#تعریف_کړه DT_DISPFILE 6

#تعریف_کړه CC_NONE 0
#تعریف_کړه CC_CIRCLES 1
#تعریف_کړه CC_PIE 2
#تعریف_کړه CC_CHORD 4
#تعریف_کړه CC_ELLIPSES 8
#تعریف_کړه CC_WIDE 16
#تعریف_کړه CC_STYLED 32
#تعریف_کړه CC_WIDESTYLED 64
#تعریف_کړه CC_INTERIORS 128
#تعریف_کړه CC_ROUNDRECT 256

#تعریف_کړه LC_NONE 0
#تعریف_کړه LC_POLYLINE 2
#تعریف_کړه LC_MARKER 4
#تعریف_کړه LC_POLYMARKER 8
#تعریف_کړه LC_WIDE 16
#تعریف_کړه LC_STYLED 32
#تعریف_کړه LC_WIDESTYLED 64
#تعریف_کړه LC_INTERIORS 128

#تعریف_کړه PC_NONE 0
#تعریف_کړه PC_POLYGON 1
#تعریف_کړه PC_RECTANGLE 2
#تعریف_کړه PC_WINDPOLYGON 4
#تعریف_کړه PC_TRAPEZOID 4
#تعریف_کړه PC_SCANLINE 8
#تعریف_کړه PC_WIDE 16
#تعریف_کړه PC_STYLED 32
#تعریف_کړه PC_WIDESTYLED 64
#تعریف_کړه PC_INTERIORS 128
#تعریف_کړه PC_POLYPOLYGON 256
#تعریف_کړه PC_PATHS 512

#تعریف_کړه CP_NONE 0
#تعریف_کړه CP_RECTANGLE 1
#تعریف_کړه CP_REGION 2

#تعریف_کړه TC_OP_CHARACTER 0x00000001
#تعریف_کړه TC_OP_STROKE 0x00000002
#تعریف_کړه TC_CP_STROKE 0x00000004
#تعریف_کړه TC_CR_90 0x00000008
#تعریف_کړه TC_CR_ANY 0x00000010
#تعریف_کړه TC_SF_X_YINDEP 0x00000020
#تعریف_کړه TC_SA_DOUBLE 0x00000040
#تعریف_کړه TC_SA_INTEGER 0x00000080
#تعریف_کړه TC_SA_CONTIN 0x00000100
#تعریف_کړه TC_EA_DOUBLE 0x00000200
#تعریف_کړه TC_IA_ABLE 0x00000400
#تعریف_کړه TC_UA_ABLE 0x00000800
#تعریف_کړه TC_SO_ABLE 0x00001000
#تعریف_کړه TC_RA_ABLE 0x00002000
#تعریف_کړه TC_VA_ABLE 0x00004000
#تعریف_کړه TC_RESERVED 0x00008000
#تعریف_کړه TC_SCROLLBLT 0x00010000
#د_که_پای

#تعریف_کړه RC_NONE
#تعریف_کړه RC_BITBLT 1
#تعریف_کړه RC_BANDING 2
#تعریف_کړه RC_SCALING 4
#تعریف_کړه RC_BITMAP64 8
#تعریف_کړه RC_GDI20_OUTPUT 0x0010
#تعریف_کړه RC_GDI20_STATE 0x0020
#تعریف_کړه RC_SAVEBITMAP 0x0040
#تعریف_کړه RC_DI_BITMAP 0x0080
#تعریف_کړه RC_PALETTE 0x0100
#تعریف_کړه RC_DIBTODEV 0x0200
#تعریف_کړه RC_BIGFONT 0x0400
#تعریف_کړه RC_STRETCHBLT 0x0800
#تعریف_کړه RC_FLOODFILL 0x1000
#تعریف_کړه RC_STRETCHDIB 0x2000
#تعریف_کړه RC_OP_DX_OUTPUT 0x4000
#تعریف_کړه RC_DEVBITS 0x8000

#تعریف_کړه SB_NONE 0x00000000
#تعریف_کړه SB_CONST_ALPHA 0x00000001
#تعریف_کړه SB_PIXEL_ALPHA 0x00000002
#تعریف_کړه SB_PREMULT_ALPHA 0x00000004

#تعریف_کړه SB_GRAD_RECT 0x00000010
#تعریف_کړه SB_GRAD_TRI 0x00000020

#تعریف_کړه CM_NONE 0x00000000
#تعریف_کړه CM_DEVICE_ICM 0x00000001
#تعریف_کړه CM_GAMMA_RAMP 0x00000002
#تعریف_کړه CM_CMYK_COLOR 0x00000004

#تعریف_کړه DIB_RGB_COLORS 0
#تعریف_کړه DIB_PAL_COLORS 1

#تعریف_کړه SYSPAL_ERROR 0
#تعریف_کړه SYSPAL_STATIC 1
#تعریف_کړه SYSPAL_NOSTATIC 2
#تعریف_کړه SYSPAL_NOSTATIC256 3

#تعریف_کړه CBM_INIT 0x04L

#تعریف_کړه FLOODFILLBORDER 0
#تعریف_کړه FLOODFILLSURFACE 1

#تعریف_کړه CCHDEVICENAME 32

#تعریف_کړه CCHFORMNAME 32

  تعريفنوع بنية _devicemodeA {
    BYTE dmDeviceName[CCHDEVICENAME];
    کلمه_3 dm_Spec_نسخه;
    کلمه_3 dm_Driver_نسخه;
    کلمه_3 dm_اندازه;
    کلمه_3 dmDriverExtra;
    DWORD dmFields;
    اتحاد {
      بنية {
        لنډ dmOrientation;
        لنډ dm_Paper_اندازه;
        لنډ dm_Paper_اوږدتیا;
        لنډ dm_Paper_پلنوالی;
        لنډ dmScale;
        لنډ dmCopies;
        لنډ dm_Default_سرچینه;
        لنډ dmPrintQuality;
      };
      بنية {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    لنډ dmColor;
    لنډ dmDuplex;
    لنډ dmYResolution;
    لنډ dmTTOption;
    لنډ dmCollate;
    BYTE dmFormName[CCHFORMNAME];
    کلمه_3 dmLogPixels;
    DWORD dm_بټونه_فی_Pel;
    DWORD dm_Pels_پلنوالی;
    DWORD dm_Pels_لوړوالی;
    اتحاد {
      DWORD dmDisplayFlags;
      DWORD dmNup;
    };
    DWORD dmDisplayFrequency;
    DWORD dmICMMethod;
    DWORD dmICMIntent;
    DWORD dmMediaType;
    DWORD dmDitherType;
    DWORD dmReserved1;
    DWORD dmReserved2;
    DWORD dm_Panning_پلنوالی;
    DWORD dm_Panning_لوړوالی;
  } DEVMODEA,*PDEVMODEA,*NPDEVMODEA,*LPDEVMODEA;

  تعريفنوع بنية _devicemodeW {
    WCHAR dmDeviceName[CCHDEVICENAME];
    کلمه_3 dm_Spec_نسخه;
    کلمه_3 dm_Driver_نسخه;
    کلمه_3 dm_اندازه;
    کلمه_3 dmDriverExtra;
    DWORD dmFields;
    اتحاد {
      بنية {
        لنډ dmOrientation;
        لنډ dm_Paper_اندازه;
        لنډ dm_Paper_اوږدتیا;
        لنډ dm_Paper_پلنوالی;
        لنډ dmScale;
        لنډ dmCopies;
        لنډ dm_Default_سرچینه;
        لنډ dmPrintQuality;
      };
      بنية {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    لنډ dmColor;
    لنډ dmDuplex;
    لنډ dmYResolution;
    لنډ dmTTOption;
    لنډ dmCollate;
    WCHAR dmFormName[CCHFORMNAME];
    کلمه_3 dmLogPixels;
    DWORD dm_بټونه_فی_Pel;
    DWORD dm_Pels_پلنوالی;
    DWORD dm_Pels_لوړوالی;
    اتحاد {
      DWORD dmDisplayFlags;
      DWORD dmNup;
    };
    DWORD dmDisplayFrequency;
    DWORD dmICMMethod;
    DWORD dmICMIntent;
    DWORD dmMediaType;
    DWORD dmDitherType;
    DWORD dmReserved1;
    DWORD dmReserved2;
    DWORD dm_Panning_پلنوالی;
    DWORD dm_Panning_لوړوالی;
  } DEVMODEW,*PDEVMODEW,*NPDEVMODEW,*LPDEVMODEW;
#که_تعریف_شوی UNICODE
  تعريفنوع DEVMODEW DEVMODE;
  تعريفنوع PDEVMODEW PDEVMODE;
  تعريفنوع NPDEVMODEW NPDEVMODE;
  تعريفنوع LPDEVMODEW LPDEVMODE;
#وإلا
  تعريفنوع DEVMODEA DEVMODE;
  تعريفنوع PDEVMODEA PDEVMODE;
  تعريفنوع NPDEVMODEA NPDEVMODE;
  تعريفنوع LPDEVMODEA LPDEVMODE;
#د_که_پای

#تعریف_کړه DM_SPECVERSION 0x0401

#تعریف_کړه DM_ORIENTATION 0x00000001L
#تعریف_کړه DM_PAPERSIZE 0x00000002L
#تعریف_کړه DM_PAPERLENGTH 0x00000004L
#تعریف_کړه DM_PAPERWIDTH 0x00000008L
#تعریف_کړه DM_SCALE 0x00000010L
#تعریف_کړه DM_POSITION 0x00000020L
#تعریف_کړه DM_NUP 0x00000040L
#تعریف_کړه DM_DISPLAYORIENTATION 0x00000080L
#تعریف_کړه DM_COPIES 0x00000100L
#تعریف_کړه DM_DEFAULTSOURCE 0x00000200L
#تعریف_کړه DM_PRINTQUALITY 0x00000400L
#تعریف_کړه DM_COLOR 0x00000800L
#تعریف_کړه DM_DUPLEX 0x00001000L
#تعریف_کړه DM_YRESOLUTION 0x00002000L
#تعریف_کړه DM_TTOPTION 0x00004000L
#تعریف_کړه DM_COLLATE 0x00008000L
#تعریف_کړه DM_FORMNAME 0x00010000L
#تعریف_کړه DM_LOGPIXELS 0x00020000L
#تعریف_کړه DM_BITSPERPEL 0x00040000L
#تعریف_کړه DM_PELSWIDTH 0x00080000L
#تعریف_کړه DM_PELSHEIGHT 0x00100000L
#تعریف_کړه DM_DISPLAYFLAGS 0x00200000L
#تعریف_کړه DM_DISPLAYFREQUENCY 0x00400000L
#تعریف_کړه DM_ICMMETHOD 0x00800000L
#تعریف_کړه DM_ICMINTENT 0x01000000L
#تعریف_کړه DM_MEDIATYPE 0x02000000L
#تعریف_کړه DM_DITHERTYPE 0x04000000L
#تعریف_کړه DM_PANNINGWIDTH 0x08000000L
#تعریف_کړه DM_PANNINGHEIGHT 0x10000000L
#تعریف_کړه DM_DISPLAYFIXEDOUTPUT 0x20000000L

#تعریف_کړه DMORIENT_PORTRAIT 1
#تعریف_کړه DMORIENT_LANDSCAPE 2

#تعریف_کړه DMPAPER_لومړی DMPAPER_LETTER
#تعریف_کړه DMPAPER_LETTER 1
#تعریف_کړه DMPAPER_LETTERSMALL 2
#تعریف_کړه DMPAPER_TABLOID 3
#تعریف_کړه DMPAPER_LEDGER 4
#تعریف_کړه DMPAPER_LEGAL 5
#تعریف_کړه DMPAPER_STATEMENT 6
#تعریف_کړه DMPAPER_EXECUTIVE 7
#تعریف_کړه DMPAPER_A3 8
#تعریف_کړه DMPAPER_A4 9
#تعریف_کړه DMPAPER_A4SMALL 10
#تعریف_کړه DMPAPER_A5 11
#تعریف_کړه DMPAPER_B4 12
#تعریف_کړه DMPAPER_B5 13
#تعریف_کړه DMPAPER_FOLIO 14
#تعریف_کړه DMPAPER_QUARTO 15
#تعریف_کړه DMPAPER_10X14 16
#تعریف_کړه DMPAPER_11X17 17
#تعریف_کړه DMPAPER_NOTE 18
#تعریف_کړه DMPAPER_ENV_9 19
#تعریف_کړه DMPAPER_ENV_10 20
#تعریف_کړه DMPAPER_ENV_11 21
#تعریف_کړه DMPAPER_ENV_12 22
#تعریف_کړه DMPAPER_ENV_14 23
#تعریف_کړه DMPAPER_CSHEET 24
#تعریف_کړه DMPAPER_DSHEET 25
#تعریف_کړه DMPAPER_ESHEET 26
#تعریف_کړه DMPAPER_ENV_DL 27
#تعریف_کړه DMPAPER_ENV_C5 28
#تعریف_کړه DMPAPER_ENV_C3 29
#تعریف_کړه DMPAPER_ENV_C4 30
#تعریف_کړه DMPAPER_ENV_C6 31
#تعریف_کړه DMPAPER_ENV_C65 32
#تعریف_کړه DMPAPER_ENV_B4 33
#تعریف_کړه DMPAPER_ENV_B5 34
#تعریف_کړه DMPAPER_ENV_B6 35
#تعریف_کړه DMPAPER_ENV_ITALY 36
#تعریف_کړه DMPAPER_ENV_MONARCH 37
#تعریف_کړه DMPAPER_ENV_PERSONAL 38
#تعریف_کړه DMPAPER_FANFOLD_US 39
#تعریف_کړه DMPAPER_FANFOLD_STD_GERMAN 40
#تعریف_کړه DMPAPER_FANFOLD_LGL_GERMAN 41
#تعریف_کړه DMPAPER_ISO_B4 42
#تعریف_کړه DMPAPER_JAPANESE_POSTCARD 43
#تعریف_کړه DMPAPER_9X11 44
#تعریف_کړه DMPAPER_10X11 45
#تعریف_کړه DMPAPER_15X11 46
#تعریف_کړه DMPAPER_ENV_INVITE 47
#تعریف_کړه DMPAPER_RESERVED_48 48
#تعریف_کړه DMPAPER_RESERVED_49 49
#تعریف_کړه DMPAPER_LETTER_EXTRA 50
#تعریف_کړه DMPAPER_LEGAL_EXTRA 51
#تعریف_کړه DMPAPER_TABLOID_EXTRA 52
#تعریف_کړه DMPAPER_A4_EXTRA 53
#تعریف_کړه DMPAPER_LETTER_TRANSVERSE 54
#تعریف_کړه DMPAPER_A4_TRANSVERSE 55
#تعریف_کړه DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#تعریف_کړه DMPAPER_A_PLUS 57
#تعریف_کړه DMPAPER_B_PLUS 58
#تعریف_کړه DMPAPER_LETTER_PLUS 59
#تعریف_کړه DMPAPER_A4_PLUS 60
#تعریف_کړه DMPAPER_A5_TRANSVERSE 61
#تعریف_کړه DMPAPER_B5_TRANSVERSE 62
#تعریف_کړه DMPAPER_A3_EXTRA 63
#تعریف_کړه DMPAPER_A5_EXTRA 64
#تعریف_کړه DMPAPER_B5_EXTRA 65
#تعریف_کړه DMPAPER_A2 66
#تعریف_کړه DMPAPER_A3_TRANSVERSE 67
#تعریف_کړه DMPAPER_A3_EXTRA_TRANSVERSE 68
#تعریف_کړه DMPAPER_DBL_JAPANESE_POSTCARD 69
#تعریف_کړه DMPAPER_A6 70
#تعریف_کړه DMPAPER_JENV_KAKU2 71
#تعریف_کړه DMPAPER_JENV_KAKU3 72
#تعریف_کړه DMPAPER_JENV_CHOU3 73
#تعریف_کړه DMPAPER_JENV_CHOU4 74
#تعریف_کړه DMPAPER_LETTER_ROTATED 75
#تعریف_کړه DMPAPER_A3_ROTATED 76
#تعریف_کړه DMPAPER_A4_ROTATED 77
#تعریف_کړه DMPAPER_A5_ROTATED 78
#تعریف_کړه DMPAPER_B4_JIS_ROTATED 79
#تعریف_کړه DMPAPER_B5_JIS_ROTATED 80
#تعریف_کړه DMPAPER_JAPANESE_POSTCARD_ROTATED 81
#تعریف_کړه DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#تعریف_کړه DMPAPER_A6_ROTATED 83
#تعریف_کړه DMPAPER_JENV_KAKU2_ROTATED 84
#تعریف_کړه DMPAPER_JENV_KAKU3_ROTATED 85
#تعریف_کړه DMPAPER_JENV_CHOU3_ROTATED 86
#تعریف_کړه DMPAPER_JENV_CHOU4_ROTATED 87
#تعریف_کړه DMPAPER_B6_JIS 88
#تعریف_کړه DMPAPER_B6_JIS_ROTATED 89
#تعریف_کړه DMPAPER_12X11 90
#تعریف_کړه DMPAPER_JENV_YOU4 91
#تعریف_کړه DMPAPER_JENV_YOU4_ROTATED 92
#تعریف_کړه DMPAPER_P16K 93
#تعریف_کړه DMPAPER_P32K 94
#تعریف_کړه DMPAPER_P32KBIG 95
#تعریف_کړه DMPAPER_PENV_1 96
#تعریف_کړه DMPAPER_PENV_2 97
#تعریف_کړه DMPAPER_PENV_3 98
#تعریف_کړه DMPAPER_PENV_4 99
#تعریف_کړه DMPAPER_PENV_5 100
#تعریف_کړه DMPAPER_PENV_6 101
#تعریف_کړه DMPAPER_PENV_7 102
#تعریف_کړه DMPAPER_PENV_8 103
#تعریف_کړه DMPAPER_PENV_9 104
#تعریف_کړه DMPAPER_PENV_10 105
#تعریف_کړه DMPAPER_P16K_ROTATED 106
#تعریف_کړه DMPAPER_P32K_ROTATED 107
#تعریف_کړه DMPAPER_P32KBIG_ROTATED 108
#تعریف_کړه DMPAPER_PENV_1_ROTATED 109
#تعریف_کړه DMPAPER_PENV_2_ROTATED 110
#تعریف_کړه DMPAPER_PENV_3_ROTATED 111
#تعریف_کړه DMPAPER_PENV_4_ROTATED 112
#تعریف_کړه DMPAPER_PENV_5_ROTATED 113
#تعریف_کړه DMPAPER_PENV_6_ROTATED 114
#تعریف_کړه DMPAPER_PENV_7_ROTATED 115
#تعریف_کړه DMPAPER_PENV_8_ROTATED 116
#تعریف_کړه DMPAPER_PENV_9_ROTATED 117
#تعریف_کړه DMPAPER_PENV_10_ROTATED 118

#تعریف_کړه DMPAPER_وروستی DMPAPER_PENV_10_ROTATED

#تعریف_کړه DMPAPER_USER 256

#تعریف_کړه DMBIN_لومړی DMBIN_پاسنی
#تعریف_کړه DMBIN_پاسنی 1
#تعریف_کړه DMBIN_ONLYONE 1
#تعریف_کړه DMBIN_ښکتنی 2
#تعریف_کړه DMBIN_منځ 3
#تعریف_کړه DMBIN_MANUAL 4
#تعریف_کړه DMBIN_ENVELOPE 5
#تعریف_کړه DMBIN_ENVMANUAL 6
#تعریف_کړه DMBIN_AUTO 7
#تعریف_کړه DMBIN_TRACTOR 8
#تعریف_کړه DMBIN_SMALLFMT 9
#تعریف_کړه DMBIN_LARGEFMT 10
#تعریف_کړه DMBIN_LARGECAPACITY 11
#تعریف_کړه DMBIN_CASSETTE 14
#تعریف_کړه DMBIN_FORMSOURCE 15
#تعریف_کړه DMBIN_وروستی DMBIN_FORMSOURCE

#تعریف_کړه DMBIN_USER 256

#تعریف_کړه DMRES_DRAFT (-1)
#تعریف_کړه DMRES_ټیټ (-2)
#تعریف_کړه DMRES_MEDIUM (-3)
#تعریف_کړه DMRES_لوړ (-4)

#تعریف_کړه DMCOLOR_MONOCHROME 1
#تعریف_کړه DMCOLOR_COLOR 2

#تعریف_کړه DMDUP_SIMPLEX 1
#تعریف_کړه DMDUP_VERTICAL 2
#تعریف_کړه DMDUP_HORIZONTAL 3

#تعریف_کړه DMTT_BITMAP 1
#تعریف_کړه DMTT_DOWNLOAD 2
#تعریف_کړه DMTT_SUBDEV 3
#تعریف_کړه DMTT_DOWNLOAD_OUTLINE 4

#تعریف_کړه DMCOLLATE_FALSE 0
#تعریف_کړه DMCOLLATE_TRUE 1

#تعریف_کړه DMDO_DEFAULT 0
#تعریف_کړه DMDO_90 1
#تعریف_کړه DMDO_180 2
#تعریف_کړه DMDO_270 3

#تعریف_کړه DMDFO_DEFAULT 0
#تعریف_کړه DMDFO_STRETCH 1
#تعریف_کړه DMDFO_CENTER 2

#تعریف_کړه DMDISPLAYFLAGS_TEXTMODE 0x00000004

#تعریف_کړه DMNUP_SYSTEM 1
#تعریف_کړه DMNUP_ONEUP 2

#تعریف_کړه DMICMMETHOD_NONE 1
#تعریف_کړه DMICMMETHOD_SYSTEM 2
#تعریف_کړه DMICMMETHOD_DRIVER 3
#تعریف_کړه DMICMMETHOD_DEVICE 4

#تعریف_کړه DMICMMETHOD_USER 256

#تعریف_کړه DMICM_SATURATE 1
#تعریف_کړه DMICM_CONTRAST 2
#تعریف_کړه DMICM_COLORIMETRIC 3
#تعریف_کړه DMICM_ABS_COLORIMETRIC 4

#تعریف_کړه DMICM_USER 256

#تعریف_کړه DMMEDIA_STANDARD 1
#تعریف_کړه DMMEDIA_TRANSPARENCY 2
#تعریف_کړه DMMEDIA_GLOSSY 3

#تعریف_کړه DMMEDIA_USER 256

#تعریف_کړه DMDITHER_NONE 1
#تعریف_کړه DMDITHER_COARSE 2
#تعریف_کړه DMDITHER_FINE 3
#تعریف_کړه DMDITHER_LINEART 4
#تعریف_کړه DMDITHER_ERRORDIFFUSION 5
#تعریف_کړه DMDITHER_RESERVED6 6
#تعریف_کړه DMDITHER_RESERVED7 7
#تعریف_کړه DMDITHER_RESERVED8 8
#تعریف_کړه DMDITHER_RESERVED9 9
#تعریف_کړه DMDITHER_GRAYSCALE 10

#تعریف_کړه DMDITHER_USER 256

  تعريفنوع بنية _DISPLAY_DEVICEA {
    DWORD cb;
    CHAR DeviceName[32];
    CHAR DeviceString[128];
    DWORD StateFlags;
    CHAR DeviceID[128];
    CHAR Device_کلی[128];
  } DISPLAY_DEVICEA,*PDISPLAY_DEVICEA,*LPDISPLAY_DEVICEA;
  تعريفنوع بنية _DISPLAY_DEVICEW {
    DWORD cb;
    WCHAR DeviceName[32];
    WCHAR DeviceString[128];
    DWORD StateFlags;
    WCHAR DeviceID[128];
    WCHAR Device_کلی[128];
  } DISPLAY_DEVICEW,*PDISPLAY_DEVICEW,*LPDISPLAY_DEVICEW;
#که_تعریف_شوی UNICODE
  تعريفنوع DISPLAY_DEVICEW DISPLAY_DEVICE;
  تعريفنوع PDISPLAY_DEVICEW PDISPLAY_DEVICE;
  تعريفنوع LPDISPLAY_DEVICEW LPDISPLAY_DEVICE;
#وإلا
  تعريفنوع DISPLAY_DEVICEA DISPLAY_DEVICE;
  تعريفنوع PDISPLAY_DEVICEA PDISPLAY_DEVICE;
  تعريفنوع LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
#د_که_پای

#تعریف_کړه DISPLAY_DEVICE_ATTACHED_منزل_DESKTOP 0x00000001
#تعریف_کړه DISPLAY_DEVICE_MULTI_DRIVER 0x00000002
#تعریف_کړه DISPLAY_DEVICE_PRIMARY_DEVICE 0x00000004
#تعریف_کړه DISPLAY_DEVICE_MIRRORING_DRIVER 0x00000008
#تعریف_کړه DISPLAY_DEVICE_VGA_COMPATIBLE 0x00000010
#تعریف_کړه DISPLAY_DEVICE_REMOVABLE 0x00000020
#تعریف_کړه DISPLAY_DEVICE_MODESPRUNED 0x08000000
#تعریف_کړه DISPLAY_DEVICE_REMOTE 0x04000000
#تعریف_کړه DISPLAY_DEVICE_DISCONNECT 0x02000000

#تعریف_کړه DISPLAY_DEVICE_فعال 0x00000001
#تعریف_کړه DISPLAY_DEVICE_ATTACHED 0x00000002

#تعریف_کړه RDH_RECTANGLES 1

  تعريفنوع بنية _RGNDATAHEADER {
    DWORD dw_اندازه;
    DWORD iType;
    DWORD n_شمېر;
    DWORD n_Rgn_اندازه;
    RECT rcBound;
  } RGNDATAHEADER,*PRGNDATAHEADER;

  تعريفنوع بنية _RGNDATA {
    RGNDATAHEADER rdh;
    حرف بفر_3[1];
  } RGNDATA,*PRGNDATA,*NPRGNDATA,*LPRGNDATA;

#تعریف_کړه SYSRGN 4

  تعريفنوع بنية _ABC {
    صحيح abcA;
    UINT abcB;
    صحيح abcC;
  } ABC,*PABC,*NPABC,*LPABC;

  تعريفنوع بنية _ABCFLOAT {
    FLOAT abcfA;
    FLOAT abcfB;
    FLOAT abcfC;
  } ABCFLOAT,*PABCFLOAT,*NPABCFLOAT,*LPABCFLOAT;

#که_نه_تعریف_شوی NOTEXTMETRIC

  تعريفنوع بنية _OUTLINETEXTMETRICA {
    UINT otm_اندازه;
    TEXTMETRICA otm_متن_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_شمېره;
    UINT otmfsSelection;
    UINT otmfsType;
    صحيح otms_Char_میلان_Rise;
    صحيح otms_Char_میلان_پرلپسې;
    صحيح otmItalicAngle;
    UINT otmEMSquare;
    صحيح otmAscent;
    صحيح otmDescent;
    UINT otm_کرښه_Gap;
    UINT otms_Cap_Em_لوړوالی;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    صحيح otmMacAscent;
    صحيح otmMacDescent;
    UINT otm_Mac_کرښه_Gap;
    UINT otmusMinimumPPEM;
    ټکی_3 otmpt_Subscript_اندازه;
    ټکی_3 otmpt_Subscript_دننه_واټن;
    ټکی_3 otmpt_Superscript_اندازه;
    ټکی_3 otmpt_Superscript_دننه_واټن;
    UINT otms_Strikeout_اندازه;
    صحيح otmsStrikeoutPosition;
    صحيح otms_Underscore_اندازه;
    صحيح otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_ډک_Name;
  } OUTLINETEXTMETRICA,*POUTLINETEXTMETRICA,*NPOUTLINETEXTMETRICA,*LPOUTLINETEXTMETRICA;

  تعريفنوع بنية _OUTLINETEXTMETRICW {
    UINT otm_اندازه;
    TEXTMETRICW otm_متن_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_شمېره;
    UINT otmfsSelection;
    UINT otmfsType;
    صحيح otms_Char_میلان_Rise;
    صحيح otms_Char_میلان_پرلپسې;
    صحيح otmItalicAngle;
    UINT otmEMSquare;
    صحيح otmAscent;
    صحيح otmDescent;
    UINT otm_کرښه_Gap;
    UINT otms_Cap_Em_لوړوالی;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    صحيح otmMacAscent;
    صحيح otmMacDescent;
    UINT otm_Mac_کرښه_Gap;
    UINT otmusMinimumPPEM;
    ټکی_3 otmpt_Subscript_اندازه;
    ټکی_3 otmpt_Subscript_دننه_واټن;
    ټکی_3 otmpt_Superscript_اندازه;
    ټکی_3 otmpt_Superscript_دننه_واټن;
    UINT otms_Strikeout_اندازه;
    صحيح otmsStrikeoutPosition;
    صحيح otms_Underscore_اندازه;
    صحيح otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_ډک_Name;
  } OUTLINETEXTMETRICW,*POUTLINETEXTMETRICW,*NPOUTLINETEXTMETRICW,*LPOUTLINETEXTMETRICW;
#که_تعریف_شوی UNICODE
  تعريفنوع OUTLINETEXTMETRICW OUTLINETEXTMETRIC;
  تعريفنوع POUTLINETEXTMETRICW POUTLINETEXTMETRIC;
  تعريفنوع NPOUTLINETEXTMETRICW NPOUTLINETEXTMETRIC;
  تعريفنوع LPOUTLINETEXTMETRICW LPOUTLINETEXTMETRIC;
#وإلا
  تعريفنوع OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
  تعريفنوع POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
  تعريفنوع NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
  تعريفنوع LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
#د_که_پای
#د_که_پای

  تعريفنوع بنية نښان_POLYTEXTA {
    صحيح x;
    صحيح y;
    UINT n;
    LPCSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    صحيح *pdx;
  } POLYTEXTA,*PPOLYTEXTA,*NPPOLYTEXTA,*LPPOLYTEXTA;

  تعريفنوع بنية نښان_POLYTEXTW {
    صحيح x;
    صحيح y;
    UINT n;
    LPCWSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    صحيح *pdx;
  } POLYTEXTW,*PPOLYTEXTW,*NPPOLYTEXTW,*LPPOLYTEXTW;
#که_تعریف_شوی UNICODE
  تعريفنوع POLYTEXTW POLYTEXT;
  تعريفنوع PPOLYTEXTW PPOLYTEXT;
  تعريفنوع NPPOLYTEXTW NPPOLYTEXT;
  تعريفنوع LPPOLYTEXTW LPPOLYTEXT;
#وإلا
  تعريفنوع POLYTEXTA POLYTEXT;
  تعريفنوع PPOLYTEXTA PPOLYTEXT;
  تعريفنوع NPPOLYTEXTA NPPOLYTEXT;
  تعريفنوع LPPOLYTEXTA LPPOLYTEXT;
#د_که_پای

  تعريفنوع بنية _FIXED {
    کلمه_3 fract;
    لنډ ارزښت;
  } FIXED;

  تعريفنوع بنية _MAT2 {
    FIXED eM11;
    FIXED eM12;
    FIXED eM21;
    FIXED eM22;
  } MAT2,*LPMAT2;

  تعريفنوع بنية _GLYPHMETRICS {
    UINT gmBlackBoxX;
    UINT gmBlackBoxY;
    ټکی_3 gmptGlyphOrigin;
    لنډ gmCellIncX;
    لنډ gmCellIncY;
  } GLYPHMETRICS,*LPGLYPHMETRICS;

#تعریف_کړه GGO_METRICS 0
#تعریف_کړه GGO_BITMAP 1
#تعریف_کړه GGO_NATIVE 2
#تعریف_کړه GGO_BEZIER 3

#تعریف_کړه GGO_GRAY2_BITMAP 4
#تعریف_کړه GGO_GRAY4_BITMAP 5
#تعریف_کړه GGO_GRAY8_BITMAP 6
#تعریف_کړه GGO_GLYPH_شاخص 0x0080
#تعریف_کړه GGO_UNHINTED 0x0100

#تعریف_کړه TT_POLYGON_TYPE 24

#تعریف_کړه TT_PRIM_کرښه 1
#تعریف_کړه TT_PRIM_QSPLINE 2
#تعریف_کړه TT_PRIM_CSPLINE 3

  تعريفنوع بنية نښان_POINTFX {
    FIXED x;
    FIXED y;
  } POINTFX,*LPPOINTFX;

  تعريفنوع بنية نښان_TTPOLYCURVE {
    کلمه_3 wType;
    کلمه_3 cpfx;
    POINTFX apfx[1];
  } TTPOLYCURVE,*LPTTPOLYCURVE;

  تعريفنوع بنية نښان_TTPOLYGONHEADER {
    DWORD cb;
    DWORD dwType;
    POINTFX pfx_پیل;
  } TTPOLYGONHEADER,*LPTTPOLYGONHEADER;

#تعریف_کړه GCP_DBCS 0x0001
#تعریف_کړه GCP_REORDER 0x0002
#تعریف_کړه GCP_USEKERNING 0x0008
#تعریف_کړه GCP_GLYPHSHAPE 0x0010
#تعریف_کړه GCP_LIGATE 0x0020

#تعریف_کړه GCP_DIACRITIC 0x0100
#تعریف_کړه GCP_KASHIDA 0x0400
#تعریف_کړه GCP_ERROR 0x8000
#تعریف_کړه FLI_ماسک 0x103B

#تعریف_کړه GCP_JUSTIFY 0x00010000L

#تعریف_کړه FLI_GLYPHS 0x00040000L
#تعریف_کړه GCP_CLASSIN 0x00080000L
#تعریف_کړه GCP_MAXEXTENT 0x00100000L
#تعریف_کړه GCP_JUSTIFYIN 0x00200000L
#تعریف_کړه GCP_DISPLAYZWG 0x00400000L
#تعریف_کړه GCP_SYMSWAPOFF 0x00800000L
#تعریف_کړه GCP_NUMERICOVERRIDE 0x01000000L
#تعریف_کړه GCP_NEUTRALOVERRIDE 0x02000000L
#تعریف_کړه GCP_NUMERICSLATIN 0x04000000L
#تعریف_کړه GCP_NUMERICSLOCAL 0x08000000L

#تعریف_کړه GCPCLASS_LATIN 1
#تعریف_کړه GCPCLASS_HEBREW 2
#تعریف_کړه GCPCLASS_ARABIC 2
#تعریف_کړه GCPCLASS_NEUTRAL 3
#تعریف_کړه GCPCLASS_LOCALNUMBER 4
#تعریف_کړه GCPCLASS_LATINNUMBER 5
#تعریف_کړه GCPCLASS_LATINNUMERICTERMINATOR 6
#تعریف_کړه GCPCLASS_LATINNUMERICSEPARATOR 7
#تعریف_کړه GCPCLASS_NUMERICSEPARATOR 8
#تعریف_کړه GCPCLASS_PREBOUNDLTR 0x80
#تعریف_کړه GCPCLASS_PREBOUNDRTL 0x40
#تعریف_کړه GCPCLASS_POSTBOUNDLTR 0x20
#تعریف_کړه GCPCLASS_POSTBOUNDRTL 0x10

#تعریف_کړه GCPGLYPH_LINKBEFORE 0x8000
#تعریف_کړه GCPGLYPH_LINKAFTER 0x4000

  تعريفنوع بنية نښان_GCP_RESULTSA {
    DWORD l_Struct_اندازه;
    LPSTR lp_بهر_String;
    UINT *lp_ترتیب;
    صحيح *lpDx;
    صحيح *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    صحيح nMaxFit;
  } GCP_RESULTSA,*LPGCP_RESULTSA;
  تعريفنوع بنية نښان_GCP_RESULTSW {
    DWORD l_Struct_اندازه;
    LPWSTR lp_بهر_String;
    UINT *lp_ترتیب;
    صحيح *lpDx;
    صحيح *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    صحيح nMaxFit;
  } GCP_RESULTSW,*LPGCP_RESULTSW;
#که_تعریف_شوی UNICODE
  تعريفنوع GCP_RESULTSW GCP_RESULTS;
  تعريفنوع LPGCP_RESULTSW LPGCP_RESULTS;
#وإلا
  تعريفنوع GCP_RESULTSA GCP_RESULTS;
  تعريفنوع LPGCP_RESULTSA LPGCP_RESULTS;
#د_که_پای

  تعريفنوع بنية RASTERIZER_حالت {
    لنډ n_اندازه;
    لنډ wFlags;
    لنډ nLanguageID;
  } RASTERIZER_حالت_2,*LPRASTERIZER_حالت;

#تعریف_کړه TT_شته 0x0001
#تعریف_کړه TT_ENABLED 0x0002

  تعريفنوع بنية نښان_PIXELFORMATDESCRIPTOR {
    کلمه_3 n_اندازه;
    کلمه_3 n_نسخه;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_بټونه;
    BYTE c_Red_بټونه;
    BYTE c_Red_ښويدنه;
    BYTE c_Green_بټونه;
    BYTE c_Green_ښويدنه;
    BYTE c_Blue_بټونه;
    BYTE c_Blue_ښويدنه;
    BYTE c_Alpha_بټونه;
    BYTE c_Alpha_ښويدنه;
    BYTE c_Accum_بټونه;
    BYTE c_Accum_Red_بټونه;
    BYTE c_Accum_Green_بټونه;
    BYTE c_Accum_Blue_بټونه;
    BYTE c_Accum_Alpha_بټونه;
    BYTE c_ژوروالی_بټونه;
    BYTE c_Stencil_بټونه;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dw_Layer_ماسک;
    DWORD dw_Visible_ماسک;
    DWORD dw_Damage_ماسک;
  } PIXELFORMATDESCRIPTOR,*PPIXELFORMATDESCRIPTOR,*LPPIXELFORMATDESCRIPTOR;

#تعریف_کړه PFD_TYPE_RGBA 0
#تعریف_کړه PFD_TYPE_COLORINDEX 1

#تعریف_کړه PFD_MAIN_PLANE 0
#تعریف_کړه PFD_OVERLAY_PLANE 1
#تعریف_کړه PFD_UNDERLAY_PLANE (-1)

#تعریف_کړه PFD_DOUBLEBUFFER 0x00000001
#تعریف_کړه PFD_STEREO 0x00000002
#تعریف_کړه PFD_DRAW_منزل_کړکۍ 0x00000004
#تعریف_کړه PFD_DRAW_منزل_BITMAP 0x00000008
#تعریف_کړه PFD_SUPPORT_GDI 0x00000010
#تعریف_کړه PFD_SUPPORT_OPENGL 0x00000020
#تعریف_کړه PFD_GENERIC_FORMAT 0x00000040
#تعریف_کړه PFD_NEED_PALETTE 0x00000080
#تعریف_کړه PFD_NEED_SYSTEM_PALETTE 0x00000100
#تعریف_کړه PFD_بدلون_EXCHANGE 0x00000200
#تعریف_کړه PFD_بدلون_COPY 0x00000400
#تعریف_کړه PFD_بدلون_LAYER_BUFFERS 0x00000800
#تعریف_کړه PFD_GENERIC_ACCELERATED 0x00001000
#تعریف_کړه PFD_SUPPORT_DIRECTDRAW 0x00002000

#تعریف_کړه PFD_ژوروالی_DONTCARE 0x20000000
#تعریف_کړه PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#تعریف_کړه PFD_STEREO_DONTCARE 0x80000000

#که_نه_تعریف_شوی NOTEXTMETRIC
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST TEXTMETRICA *,DWORD,LPARAM);
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST TEXTMETRICW *,DWORD,LPARAM);
#که_تعریف_شوی UNICODE
#تعریف_کړه OLDFONTENUMPROC OLDFONTENUMPROCW
#وإلا
#تعریف_کړه OLDFONTENUMPROC OLDFONTENUMPROCA
#د_که_پای
#وإلا
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST VOID *,DWORD,LPARAM);
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST VOID *,DWORD,LPARAM);
#که_تعریف_شوی UNICODE
#تعریف_کړه OLDFONTENUMPROC OLDFONTENUMPROCW
#وإلا
#تعریف_کړه OLDFONTENUMPROC OLDFONTENUMPROCA
#د_که_پای
#د_که_پای

  تعريفنوع OLDFONTENUMPROCA FONTENUMPROCA;
  تعريفنوع OLDFONTENUMPROCW FONTENUMPROCW;
#که_تعریف_شوی UNICODE
  تعريفنوع FONTENUMPROCW FONTENUMPROC;
#وإلا
  تعريفنوع FONTENUMPROCA FONTENUMPROC;
#د_که_پای

  تعريفنوع صحيح (CALLBACK *GOBJENUMPROC)(LPVOID,LPARAM);
  تعريفنوع VOID (CALLBACK *LINEDDAPROC)(صحيح,صحيح,LPARAM);

#که_تعریف_شوی UNICODE
#تعریف_کړه جمع_کړه_Font_Resource جمع_کړه_Font_Resource_W
#تعریف_کړه CopyMetaFile CopyMetaFileW
#تعریف_کړه CreateDC CreateDCW
#تعریف_کړه Create_Font_غیرمستقیم Create_Font_غیرمستقیم_W
#تعریف_کړه CreateFont CreateFontW
#تعریف_کړه CreateIC CreateICW
#تعریف_کړه CreateMetaFile CreateMetaFileW
#تعریف_کړه CreateScalableFontResource CreateScalableFontResourceW
#وإلا
#تعریف_کړه جمع_کړه_Font_Resource جمع_کړه_Font_Resource_A
#تعریف_کړه CopyMetaFile CopyMetaFileA
#تعریف_کړه CreateDC CreateDCA
#تعریف_کړه Create_Font_غیرمستقیم Create_Font_غیرمستقیم_A
#تعریف_کړه CreateFont CreateFontA
#تعریف_کړه CreateIC CreateICA
#تعریف_کړه CreateMetaFile CreateMetaFileA
#تعریف_کړه CreateScalableFontResource CreateScalableFontResourceA
#د_که_پای

  WINGDIAPI صحيح WINAPI جمع_کړه_Font_Resource_A(LPCSTR);
  WINGDIAPI صحيح WINAPI جمع_کړه_Font_Resource_W(LPCWSTR);
  WINGDIAPI WINBOOL WINAPI AnimatePalette(HPALETTE hPal,UINT i_پیل_شاخص,UINT cEntries,CONST PALETTEENTRY *ppe);
  WINGDIAPI WINBOOL WINAPI Arc(HDC hdc,صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح x3,صحيح y3,صحيح x4,صحيح y4);
  WINGDIAPI WINBOOL WINAPI بټ_Blt(HDC hdc,صحيح x,صحيح y,صحيح cx,صحيح cy,HDC hdcSrc,صحيح x1,صحيح y1,DWORD rop);
  WINGDIAPI WINBOOL WINAPI CancelDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Chord(HDC hdc,صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح x3,صحيح y3,صحيح x4,صحيح y4);
  WINGDIAPI صحيح WINAPI ټاکنه_Pixel_Format(HDC hdc,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI HMETAFILE WINAPI CloseMetaFile(HDC hdc);
  WINGDIAPI صحيح WINAPI CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,صحيح i_ډېرپېښ);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
  WINGDIAPI HBITMAP WINAPI CreateBitmap(صحيح n_پلنوالی,صحيح n_لوړوالی,UINT nPlanes,UINT n_بټ_شمېر,CONST VOID *lp_بټونه);
  WINGDIAPI HBITMAP WINAPI Create_Bitmap_غیرمستقیم(CONST BITMAP *pbm);
  WINGDIAPI HBRUSH WINAPI Create_Brush_غیرمستقیم(CONST LOGBRUSH *plbrush);
  WINGDIAPI HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc,صحيح cx,صحيح cy);
  WINGDIAPI HBITMAP WINAPI CreateDiscardableBitmap(HDC hdc,صحيح cx,صحيح cy);
  WINGDIAPI HDC WINAPI CreateCompatibleDC(HDC hdc);
  WINGDIAPI HDC WINAPI CreateDCA(LPCSTR pwszDriver,LPCSTR pwszDevice,LPCSTR psz_پورټ,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateDCW(LPCWSTR pwszDriver,LPCWSTR pwszDevice,LPCWSTR psz_پورټ,CONST DEVMODEW *pdm);
  WINGDIAPI HBITMAP WINAPI CreateDIBitmap(HDC hdc,CONST BITMAPINFOHEADER *pbmih,DWORD flInit,CONST VOID *pj_بټونه,CONST BITMAPINFO *pbmi,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL h,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB,UINT iUsage);
  WINGDIAPI HRGN WINAPI CreateEllipticRgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2);
  WINGDIAPI HRGN WINAPI Create_Elliptic_Rgn_غیرمستقیم(CONST RECT *lprect);
  WINGDIAPI HFONT WINAPI Create_Font_غیرمستقیم_A(CONST LOGFONTA *lplf);
  WINGDIAPI HFONT WINAPI Create_Font_غیرمستقیم_W(CONST LOGFONTW *lplf);
  WINGDIAPI HFONT WINAPI CreateFontA(صحيح c_لوړوالی,صحيح c_پلنوالی,صحيح cEscapement,صحيح cOrientation,صحيح c_وزن,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_بهر,DWORD i_Char_سېټ,DWORD i_بهر_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCSTR pszFaceName);
  WINGDIAPI HFONT WINAPI CreateFontW(صحيح c_لوړوالی,صحيح c_پلنوالی,صحيح cEscapement,صحيح cOrientation,صحيح c_وزن,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_بهر,DWORD i_Char_سېټ,DWORD i_بهر_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCWSTR pszFaceName);
  WINGDIAPI HBRUSH WINAPI CreateHatchBrush(صحيح iHatch,COLORREF color);
  WINGDIAPI HDC WINAPI CreateICA(LPCSTR pszDriver,LPCSTR pszDevice,LPCSTR psz_پورټ,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateICW(LPCWSTR pszDriver,LPCWSTR pszDevice,LPCWSTR psz_پورټ,CONST DEVMODEW *pdm);
  WINGDIAPI HDC WINAPI CreateMetaFileA(LPCSTR pszFile);
  WINGDIAPI HDC WINAPI CreateMetaFileW(LPCWSTR pszFile);
  WINGDIAPI HPALETTE WINAPI CreatePalette(CONST LOGPALETTE *plpal);
  WINGDIAPI HPEN WINAPI CreatePen(صحيح iStyle,صحيح c_پلنوالی,COLORREF color);
  WINGDIAPI HPEN WINAPI Create_Pen_غیرمستقیم(CONST LOGPEN *plpen);
  WINGDIAPI HRGN WINAPI CreatePolyPolygonRgn(CONST ټکی_3 *pptl,CONST INT *pc,صحيح cPoly,صحيح i_ډېرپېښ);
  WINGDIAPI HBRUSH WINAPI Create_نمونه_Brush(HBITMAP hbm);
  WINGDIAPI HRGN WINAPI CreateRectRgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2);
  WINGDIAPI HRGN WINAPI Create_Rect_Rgn_غیرمستقیم(CONST RECT *lprect);
  WINGDIAPI HRGN WINAPI Create_پړاو_Rect_Rgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح w,صحيح h);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceA(DWORD fdwHidden,LPCSTR lpszFont,LPCSTR lpszFile,LPCSTR lpsz_لار);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceW(DWORD fdwHidden,LPCWSTR lpszFont,LPCWSTR lpszFile,LPCWSTR lpsz_لار);
  WINGDIAPI HBRUSH WINAPI CreateSolidBrush(COLORREF color);
  WINGDIAPI WINBOOL WINAPI DeleteDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI DeleteMetaFile(HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI DeleteObject(HGDIOBJ ho);
  WINGDIAPI صحيح WINAPI DescribePixelFormat(HDC hdc,صحيح iPixelFormat,UINT n_بایټونه,LPPIXELFORMATDESCRIPTOR ppfd);

  تعريفنوع UINT (CALLBACK *LPFNDEVMODE)(HWND,HMODULE,LPDEVMODE,LPSTR,LPSTR,LPDEVMODE,LPSTR,UINT);
  تعريفنوع DWORD (CALLBACK *LPFNDEVCAPS)(LPSTR,LPSTR,UINT,LPSTR,LPDEVMODE);

#تعریف_کړه DM_UPDATE 1
#تعریف_کړه DM_COPY 2
#تعریف_کړه DM_PROMPT 4
#تعریف_کړه DM_MODIFY 8

#تعریف_کړه DM_دننه_بفر DM_MODIFY
#تعریف_کړه DM_دننه_PROMPT DM_PROMPT
#تعریف_کړه DM_بهر_بفر DM_COPY
#تعریف_کړه DM_بهر_DEFAULT DM_UPDATE

#تعریف_کړه DC_FIELDS 1
#تعریف_کړه DC_PAPERS 2
#تعریف_کړه DC_PAPERSIZE 3
#تعریف_کړه DC_MINEXTENT 4
#تعریف_کړه DC_MAXEXTENT 5
#تعریف_کړه DC_BINS 6
#تعریف_کړه DC_DUPLEX 7
#تعریف_کړه DC_اندازه 8
#تعریف_کړه DC_EXTRA 9
#تعریف_کړه DC_نسخه 10
#تعریف_کړه DC_DRIVER 11
#تعریف_کړه DC_BINNAMES 12
#تعریف_کړه DC_ENUMRESOLUTIONS 13
#تعریف_کړه DC_FILEDEPENDENCIES 14
#تعریف_کړه DC_TRUETYPE 15
#تعریف_کړه DC_PAPERNAMES 16
#تعریف_کړه DC_ORIENTATION 17
#تعریف_کړه DC_COPIES 18
#تعریف_کړه DC_BINADJUST 19
#تعریف_کړه DC_EMF_COMPLIANT 20
#تعریف_کړه DC_DATATYPE_PRODUCED 21
#تعریف_کړه DC_COLLATE 22
#تعریف_کړه DC_MANUFACTURER 23
#تعریف_کړه DC_MODEL 24
#تعریف_کړه DC_PERSONALITY 25
#تعریف_کړه DC_PRINTRATE 26
#تعریف_کړه DC_PRINTRATEUNIT 27
#تعریف_کړه PRINTRATEUNIT_PPM 1
#تعریف_کړه PRINTRATEUNIT_CPS 2
#تعریف_کړه PRINTRATEUNIT_LPM 3
#تعریف_کړه PRINTRATEUNIT_IPM 4
#تعریف_کړه DC_PRINTERMEM 28
#تعریف_کړه DC_MEDIAREADY 29
#تعریف_کړه DC_STAPLE 30
#تعریف_کړه DC_PRINTRATEPPM 31
#تعریف_کړه DC_COLORDEVICE 32
#تعریف_کړه DC_NUP 33
#تعریف_کړه DC_MEDIATYPENAMES 34
#تعریف_کړه DC_MEDIATYPES 35

#تعریف_کړه DCTT_BITMAP 0x0000001L
#تعریف_کړه DCTT_DOWNLOAD 0x0000002L
#تعریف_کړه DCTT_SUBDEV 0x0000004L
#تعریف_کړه DCTT_DOWNLOAD_OUTLINE 0x0000008L

#تعریف_کړه DCBA_FACEUPNONE 0x0000
#تعریف_کړه DCBA_FACEUPCENTER 0x0001
#تعریف_کړه DCBA_FACEUPLEFT 0x0002
#تعریف_کړه DCBA_FACEUPRIGHT 0x0003
#تعریف_کړه DCBA_FACEDOWNNONE 0x0100
#تعریف_کړه DCBA_FACEDOWNCENTER 0x0101
#تعریف_کړه DCBA_FACEDOWNLEFT 0x0102
#تعریف_کړه DCBA_FACEDOWNRIGHT 0x0103

#که_تعریف_شوی UNICODE
#تعریف_کړه DeviceCapabilities DeviceCapabilitiesW
#تعریف_کړه EnumFontFamiliesEx EnumFontFamiliesExW
#تعریف_کړه EnumFontFamilies EnumFontFamiliesW
#تعریف_کړه EnumFonts EnumFontsW
#تعریف_کړه Get_Char_پلنوالی Get_Char_پلنوالی_W
#تعریف_کړه GetCharWidth32 GetCharWidth32W
#تعریف_کړه Get_Char_پلنوالی_Float Get_Char_پلنوالی_Float_W
#تعریف_کړه GetCharABCWidths GetCharABCWidthsW
#تعریف_کړه GetCharABCWidthsFloat GetCharABCWidthsFloatW
#تعریف_کړه GetGlyphOutline GetGlyphOutlineW
#تعریف_کړه GetMetaFile GetMetaFileW
#وإلا
#تعریف_کړه DeviceCapabilities DeviceCapabilitiesA
#تعریف_کړه EnumFontFamiliesEx EnumFontFamiliesExA
#تعریف_کړه EnumFontFamilies EnumFontFamiliesA
#تعریف_کړه EnumFonts EnumFontsA
#تعریف_کړه Get_Char_پلنوالی Get_Char_پلنوالی_A
#تعریف_کړه GetCharWidth32 GetCharWidth32A
#تعریف_کړه Get_Char_پلنوالی_Float Get_Char_پلنوالی_Float_A
#تعریف_کړه GetCharABCWidths GetCharABCWidthsA
#تعریف_کړه GetCharABCWidthsFloat GetCharABCWidthsFloatA
#تعریف_کړه GetGlyphOutline GetGlyphOutlineA
#تعریف_کړه GetMetaFile GetMetaFileA
#د_که_پای

  WINSPOOLAPI صحيح WINAPI DeviceCapabilitiesA(LPCSTR pDevice,LPCSTR p_پورټ,کلمه_3 fwCapability,LPSTR pOutput,CONST DEVMODEA *p_Dev_ډېرپېښ);
  WINSPOOLAPI صحيح WINAPI DeviceCapabilitiesW(LPCWSTR pDevice,LPCWSTR p_پورټ,کلمه_3 fwCapability,LPWSTR pOutput,CONST DEVMODEW *p_Dev_ډېرپېښ);
  WINGDIAPI صحيح WINAPI DrawEscape(HDC hdc,صحيح iEscape,صحيح cj_دننه,LPCSTR lp_دننه);
  WINGDIAPI WINBOOL WINAPI Ellipse(HDC hdc,صحيح کیڼ,صحيح سر,صحيح ښی,صحيح bottom);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesExA(HDC hdc,LPLOGFONTA lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesExW(HDC hdc,LPLOGFONTW lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontsA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontsW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumObjects(HDC hdc,صحيح nType,GOBJENUMPROC lpFunc,LPARAM lParam);
  WINGDIAPI WINBOOL WINAPI EqualRgn(HRGN hrgn1,HRGN hrgn2);
  WINGDIAPI صحيح WINAPI Escape(HDC hdc,صحيح iEscape,صحيح cj_دننه,LPCSTR pv_دننه,LPVOID pv_بهر);
  WINGDIAPI صحيح WINAPI ExtEscape(HDC hdc,صحيح iEscape,صحيح cj_ننوت,LPCSTR lp_دننه_معلومات,صحيح cjOutput,LPSTR lp_بهر_معلومات);
  WINGDIAPI صحيح WINAPI ExcludeClipRect(HDC hdc,صحيح کیڼ,صحيح سر,صحيح ښی,صحيح bottom);
  WINGDIAPI HRGN WINAPI ExtCreateRegion(CONST XFORM *lpx,DWORD n_شمېر,CONST RGNDATA *lp_معلومات);
  WINGDIAPI WINBOOL WINAPI ExtFloodFill(HDC hdc,صحيح x,صحيح y,COLORREF color,UINT type);
  WINGDIAPI WINBOOL WINAPI FillRgn(HDC hdc,HRGN hrgn,HBRUSH hbr);
  WINGDIAPI WINBOOL WINAPI FloodFill(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI چوکاټ_Rgn(HDC hdc,HRGN hrgn,HBRUSH hbr,صحيح w,صحيح h);
  WINGDIAPI صحيح WINAPI GetROP2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_Aspect_نسبت_Filter_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI COLORREF WINAPI GetBkColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCBrushColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCPenColor(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Bk_ډېرپېښ(HDC hdc);
  WINGDIAPI LONG WINAPI Get_Bitmap_بټونه(HBITMAP hbit,LONG cb,LPVOID lpv_بټونه);
  WINGDIAPI WINBOOL WINAPI GetBitmapDimensionEx(HBITMAP hbit,LPSIZE lpsize);
  WINGDIAPI UINT WINAPI GetBoundsRect(HDC hdc,LPRECT lprect,UINT flags);
  WINGDIAPI WINBOOL WINAPI GetBrushOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI Get_Char_پلنوالی_A(HDC hdc,UINT i_لومړی,UINT i_وروستی,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI Get_Char_پلنوالی_W(HDC hdc,UINT i_لومړی,UINT i_وروستی,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32A(HDC hdc,UINT i_لومړی,UINT i_وروستی,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32W(HDC hdc,UINT i_لومړی,UINT i_وروستی,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI Get_Char_پلنوالی_Float_A(HDC hdc,UINT i_لومړی,UINT i_وروستی,PFLOAT lp_بفر);
  WINGDIAPI WINBOOL WINAPI Get_Char_پلنوالی_Float_W(HDC hdc,UINT i_لومړی,UINT i_وروستی,PFLOAT lp_بفر);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsA(HDC hdc,UINT w_لومړی,UINT w_وروستی,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsW(HDC hdc,UINT w_لومړی,UINT w_وروستی,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatA(HDC hdc,UINT i_لومړی,UINT i_وروستی,LPABCFLOAT lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatW(HDC hdc,UINT i_لومړی,UINT i_وروستی,LPABCFLOAT lpABC);
  WINGDIAPI صحيح WINAPI GetClipBox(HDC hdc,LPRECT lprect);
  WINGDIAPI صحيح WINAPI GetClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI صحيح WINAPI GetMetaRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI HGDIOBJ WINAPI GetCurrentObject(HDC hdc,UINT type);
  WINGDIAPI WINBOOL WINAPI GetCurrentPositionEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI صحيح WINAPI GetDeviceCaps(HDC hdc,صحيح شاخص);
  WINGDIAPI صحيح WINAPI GetDIBits(HDC hdc,HBITMAP hbm,UINT پیل,UINT c_کرښې,LPVOID lpv_بټونه,LPBITMAPINFO lpbmi,UINT usage);
  WINGDIAPI DWORD WINAPI Get_Font_معلومات (HDC hdc,DWORD dw_جدول,DWORD dw_دننه_واټن,PVOID pv_بفر,DWORD cj_بفر);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineA(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_بفر,LPVOID pv_بفر,CONST MAT2 *lpmat2);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineW(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_بفر,LPVOID pv_بفر,CONST MAT2 *lpmat2);
  WINGDIAPI صحيح WINAPI Get_Graphics_ډېرپېښ(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Map_ډېرپېښ(HDC hdc);
  WINGDIAPI UINT WINAPI Get_Meta_File_بټونه_Ex(HMETAFILE hMF,UINT cb_بفر,LPVOID lp_معلومات);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileA(LPCSTR lpName);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileW(LPCWSTR lpName);
  WINGDIAPI COLORREF WINAPI Get_تر_ټولو_نږدې_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI Get_تر_ټولو_نږدې_Palette_شاخص(HPALETTE h,COLORREF color);
  WINGDIAPI DWORD WINAPI GetObjectType(HGDIOBJ h);

#که_نه_تعریف_شوی NOTEXTMETRIC
#که_تعریف_شوی UNICODE
#تعریف_کړه Get_Outline_متن_Metrics Get_Outline_متن_Metrics_W
#وإلا
#تعریف_کړه Get_Outline_متن_Metrics Get_Outline_متن_Metrics_A
#د_که_پای

  WINGDIAPI UINT WINAPI Get_Outline_متن_Metrics_A(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICA potm);
  WINGDIAPI UINT WINAPI Get_Outline_متن_Metrics_W(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICW potm);
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_متن_Extent_ټکی Get_متن_Extent_ټکی_W
#تعریف_کړه Get_متن_Extent_Point32 Get_متن_Extent_Point32_W
#تعریف_کړه Get_متن_Extent_Ex_ټکی Get_متن_Extent_Ex_ټکی_W
#تعریف_کړه GetCharacterPlacement GetCharacterPlacementW
#وإلا
#تعریف_کړه Get_متن_Extent_ټکی Get_متن_Extent_ټکی_A
#تعریف_کړه Get_متن_Extent_Point32 Get_متن_Extent_Point32_A
#تعریف_کړه Get_متن_Extent_Ex_ټکی Get_متن_Extent_Ex_ټکی_A
#تعریف_کړه GetCharacterPlacement GetCharacterPlacementA
#د_که_پای

  WINGDIAPI UINT WINAPI GetPaletteEntries(HPALETTE hpal,UINT i_پیل,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI COLORREF WINAPI GetPixel(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI صحيح WINAPI GetPixelFormat(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Poly_Fill_ډېرپېښ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetRasterizerCaps(LPRASTERIZER_حالت lpraststat,UINT cj_بایټونه);
  WINGDIAPI صحيح WINAPI GetRandomRgn (HDC hdc,HRGN hrgn,INT i);
  WINGDIAPI DWORD WINAPI Get_Region_معلومات(HRGN hrgn,DWORD n_شمېر,LPRGNDATA lp_Rgn_معلومات);
  WINGDIAPI صحيح WINAPI GetRgnBox(HRGN hrgn,LPRECT lprc);
  WINGDIAPI HGDIOBJ WINAPI GetStockObject(صحيح i);
  WINGDIAPI صحيح WINAPI Get_Stretch_Blt_ډېرپېښ(HDC hdc);
  WINGDIAPI UINT WINAPI GetSystemPaletteEntries(HDC hdc,UINT i_پیل,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI UINT WINAPI GetSystemPaletteUse(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_متن_Character_Extra(HDC hdc);
  WINGDIAPI UINT WINAPI Get_متن_Align(HDC hdc);
  WINGDIAPI COLORREF WINAPI Get_متن_Color(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_ټکی_A(HDC hdc,LPCSTR lpString,صحيح c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_ټکی_W(HDC hdc,LPCWSTR lpString,صحيح c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Point32_A(HDC hdc,LPCSTR lpString,صحيح c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Point32_W(HDC hdc,LPCWSTR lpString,صحيح c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_ټکی_A(HDC hdc,LPCSTR lpszString,صحيح cchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_اندازه);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_ټکی_W(HDC hdc,LPCWSTR lpszString,صحيح cchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_اندازه);
  WINGDIAPI صحيح WINAPI Get_متن_Charset(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_متن_Charset_Info(HDC hdc,LPFONTSIGNATURE lpSig,DWORD dwFlags);
  WINGDIAPI WINBOOL WINAPI TranslateCharsetInfo(DWORD *lpSrc,LPCHARSETINFO lpCs,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetFontLanguageInfo(HDC hdc);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementA(HDC hdc,LPCSTR lpString,صحيح n_شمېر,صحيح nMexExtent,LPGCP_RESULTSA lpResults,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementW(HDC hdc,LPCWSTR lpString,صحيح n_شمېر,صحيح nMexExtent,LPGCP_RESULTSW lpResults,DWORD dwFlags);

  تعريفنوع بنية نښان_WCRANGE {
    WCHAR wc_ټیټ;
    USHORT cGlyphs;
  } WCRANGE,*PWCRANGE,*LPWCRANGE;

  تعريفنوع بنية نښان_GLYPHSET {
    DWORD cbThis;
    DWORD flAccel;
    DWORD cGlyphsSupported;
    DWORD cRanges;
    WCRANGE ranges[1];
  } GLYPHSET,*PGLYPHSET,*LPGLYPHSET;

#تعریف_کړه GS_8_بټ_INDICES 0x00000001

#تعریف_کړه GGI_MARK_NONEXISTING_GLYPHS 0X0001

#که_تعریف_شوی UNICODE
#تعریف_کړه GetGlyphIndices GetGlyphIndicesW
#وإلا
#تعریف_کړه GetGlyphIndices GetGlyphIndicesA
#د_که_پای

  WINGDIAPI DWORD WINAPI GetFontUnicodeRanges(HDC hdc,LPGLYPHSET lpgs);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesA(HDC hdc,LPCSTR lpstr,صحيح c,LPWORD pgi,DWORD fl);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesW(HDC hdc,LPCWSTR lpstr,صحيح c,LPWORD pgi,DWORD fl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_ټکی_I(HDC hdc,LPWORD pgi_دننه,صحيح cgi,LPSIZE psize);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_ټکی_I (HDC hdc,LPWORD lpwszString,صحيح cwchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_اندازه);
  WINGDIAPI WINBOOL WINAPI Get_Char_پلنوالی_I(HDC hdc,UINT gi_لومړی,UINT cgi,LPWORD pgi,LPINT piWidths);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsI(HDC hdc,UINT gi_لومړی,UINT cgi,LPWORD pgi,LPABC pabc);

#تعریف_کړه STAMP_DESIGNVECTOR (0x8000000 + 'd' + ('v' << 8))
#تعریف_کړه STAMP_AXESLIST (0x8000000 + 'a' + ('l' << 8))
#تعریف_کړه MM_MAX_NUMAXES 16

  تعريفنوع بنية نښان_DESIGNVECTOR {
    DWORD dvReserved;
    DWORD dv_عدد_Axes;
    LONG dv_ارزښتونه[MM_MAX_NUMAXES];
  } DESIGNVECTOR,*PDESIGNVECTOR,*LPDESIGNVECTOR;

#که_تعریف_شوی UNICODE
#تعریف_کړه جمع_کړه_Font_Resource_Ex جمع_کړه_Font_Resource_Ex_W
#تعریف_کړه RemoveFontResourceEx RemoveFontResourceExW
#وإلا
#تعریف_کړه جمع_کړه_Font_Resource_Ex جمع_کړه_Font_Resource_Ex_A
#تعریف_کړه RemoveFontResourceEx RemoveFontResourceExA
#د_که_پای

  WINGDIAPI صحيح WINAPI جمع_کړه_Font_Resource_Ex_A(LPCSTR name,DWORD fl,PVOID res);
  WINGDIAPI صحيح WINAPI جمع_کړه_Font_Resource_Ex_W(LPCWSTR name,DWORD fl,PVOID res);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExA(LPCSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExW(LPCWSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI HANDLE WINAPI جمع_کړه_Font_Mem_Resource_Ex(PVOID pFileView,DWORD cj_اندازه,PVOID pvResrved,DWORD *p_عدد_Fonts);
  WINGDIAPI WINBOOL WINAPI RemoveFontMemResourceEx(HANDLE h);

#تعریف_کړه FR_شخصي 0x10
#تعریف_کړه FR_NOT_ENUM 0x20

#تعریف_کړه MM_MAX_AXES_NAMELEN 16

  تعريفنوع بنية نښان_AXISINFOA {
    LONG ax_Min_ارزښت;
    LONG ax_Max_ارزښت;
    BYTE axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOA,*PAXISINFOA,*LPAXISINFOA;

  تعريفنوع بنية نښان_AXISINFOW {
    LONG ax_Min_ارزښت;
    LONG ax_Max_ارزښت;
    WCHAR axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOW,*PAXISINFOW,*LPAXISINFOW;
#که_تعریف_شوی UNICODE
  تعريفنوع AXISINFOW AXISINFO;
  تعريفنوع PAXISINFOW PAXISINFO;
  تعريفنوع LPAXISINFOW LPAXISINFO;
#وإلا
  تعريفنوع AXISINFOA AXISINFO;
  تعريفنوع PAXISINFOA PAXISINFO;
  تعريفنوع LPAXISINFOA LPAXISINFO;
#د_که_پای

  تعريفنوع بنية نښان_AXESLISTA {
    DWORD axlReserved;
    DWORD axl_عدد_Axes;
    AXISINFOA axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTA,*PAXESLISTA,*LPAXESLISTA;

  تعريفنوع بنية نښان_AXESLISTW {
    DWORD axlReserved;
    DWORD axl_عدد_Axes;
    AXISINFOW axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTW,*PAXESLISTW,*LPAXESLISTW;
#که_تعریف_شوی UNICODE
  تعريفنوع AXESLISTW AXESLIST;
  تعريفنوع PAXESLISTW PAXESLIST;
  تعريفنوع LPAXESLISTW LPAXESLIST;
#وإلا
  تعريفنوع AXESLISTA AXESLIST;
  تعريفنوع PAXESLISTA PAXESLIST;
  تعريفنوع LPAXESLISTA LPAXESLIST;
#د_که_پای

  تعريفنوع بنية نښان_ENUMLOGFONTEXDVA {
    ENUMLOGFONTEXA elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_ویکټور;
  } ENUMLOGFONTEXDVA,*PENUMLOGFONTEXDVA,*LPENUMLOGFONTEXDVA;

  تعريفنوع بنية نښان_ENUMLOGFONTEXDVW {
    ENUMLOGFONTEXW elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_ویکټور;
  } ENUMLOGFONTEXDVW,*PENUMLOGFONTEXDVW,*LPENUMLOGFONTEXDVW;
#که_تعریف_شوی UNICODE
  تعريفنوع ENUMLOGFONTEXDVW ENUMLOGFONTEXDV;
  تعريفنوع PENUMLOGFONTEXDVW PENUMLOGFONTEXDV;
  تعريفنوع LPENUMLOGFONTEXDVW LPENUMLOGFONTEXDV;
#وإلا
  تعريفنوع ENUMLOGFONTEXDVA ENUMLOGFONTEXDV;
  تعريفنوع PENUMLOGFONTEXDVA PENUMLOGFONTEXDV;
  تعريفنوع LPENUMLOGFONTEXDVA LPENUMLOGFONTEXDV;
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه Create_Font_غیرمستقیم_Ex Create_Font_غیرمستقیم_Ex_W
#وإلا
#تعریف_کړه Create_Font_غیرمستقیم_Ex Create_Font_غیرمستقیم_Ex_A
#د_که_پای

  WINGDIAPI HFONT WINAPI Create_Font_غیرمستقیم_Ex_A(CONST ENUMLOGFONTEXDVA *);
  WINGDIAPI HFONT WINAPI Create_Font_غیرمستقیم_Ex_W(CONST ENUMLOGFONTEXDVW *);

#که_نه_تعریف_شوی NOTEXTMETRIC
  تعريفنوع بنية نښان_ENUMTEXTMETRICA {
    NEWTEXTMETRICEXA etm_New_متن_Metric_Ex;
    AXESLISTA etmAxesList;
  } ENUMTEXTMETRICA,*PENUMTEXTMETRICA,*LPENUMTEXTMETRICA;
  تعريفنوع بنية نښان_ENUMTEXTMETRICW
  {
    NEWTEXTMETRICEXW etm_New_متن_Metric_Ex;
    AXESLISTW etmAxesList;
  } ENUMTEXTMETRICW,*PENUMTEXTMETRICW,*LPENUMTEXTMETRICW;
#که_تعریف_شوی UNICODE
  تعريفنوع ENUMTEXTMETRICW ENUMTEXTMETRIC;
  تعريفنوع PENUMTEXTMETRICW PENUMTEXTMETRIC;
  تعريفنوع LPENUMTEXTMETRICW LPENUMTEXTMETRIC;
#وإلا
  تعريفنوع ENUMTEXTMETRICA ENUMTEXTMETRIC;
  تعريفنوع PENUMTEXTMETRICA PENUMTEXTMETRIC;
  تعريفنوع LPENUMTEXTMETRICA LPENUMTEXTMETRIC;
#د_که_پای
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه ResetDC ResetDCW
#تعریف_کړه RemoveFontResource RemoveFontResourceW
#وإلا
#تعریف_کړه ResetDC ResetDCA
#تعریف_کړه RemoveFontResource RemoveFontResourceA
#د_که_پای

  WINGDIAPI WINBOOL WINAPI GetViewportExtEx(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI GetViewportOrgEx(HDC hdc,LPPOINT lppoint);
  WINGDIAPI WINBOOL WINAPI Get_کړکۍ_Ext_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI Get_کړکۍ_Org_Ex(HDC hdc,LPPOINT lppoint);
  WINGDIAPI صحيح WINAPI IntersectClipRect(HDC hdc,صحيح کیڼ,صحيح سر,صحيح ښی,صحيح bottom);
  WINGDIAPI WINBOOL WINAPI InvertRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI کرښه_DDA(صحيح x_پیل,صحيح y_پیل,صحيح x_پای_ټکی,صحيح y_پای_ټکی,LINEDDAPROC lpProc,LPARAM معلومات);
  WINGDIAPI WINBOOL WINAPI کرښه_منزل(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI ماسک_Blt(HDC hdcDest,صحيح xDest,صحيح yDest,صحيح پلنوالی,صحيح لوړوالی,HDC hdcSrc,صحيح xSrc,صحيح ySrc,HBITMAP hbm_ماسک,صحيح x_ماسک,صحيح y_ماسک,DWORD rop);
  WINGDIAPI WINBOOL WINAPI PlgBlt(HDC hdcDest,CONST ټکی_3 *lp_ټکی,HDC hdcSrc,صحيح xSrc,صحيح ySrc,صحيح پلنوالی,صحيح لوړوالی,HBITMAP hbm_ماسک,صحيح x_ماسک,صحيح y_ماسک);
  WINGDIAPI صحيح WINAPI دننه_واټن_Clip_Rgn(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI صحيح WINAPI دننه_واټن_Rgn(HRGN hrgn,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI PatBlt(HDC hdc,صحيح x,صحيح y,صحيح w,صحيح h,DWORD rop);
  WINGDIAPI WINBOOL WINAPI Pie(HDC hdc,صحيح کیڼ,صحيح سر,صحيح ښی,صحيح bottom,صحيح xr1,صحيح yr1,صحيح xr2,صحيح yr2);
  WINGDIAPI WINBOOL WINAPI PlayMetaFile(HDC hdc,HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI PaintRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI PolyPolygon(HDC hdc,CONST ټکی_3 *apt,CONST INT *asz,صحيح csz);
  WINGDIAPI WINBOOL WINAPI Pt_دننه_Region(HRGN hrgn,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI PtVisible(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI Rect_دننه_Region(HRGN hrgn,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI RectVisible(HDC hdc,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Rectangle(HDC hdc,صحيح کیڼ,صحيح سر,صحيح ښی,صحيح bottom);
  WINGDIAPI WINBOOL WINAPI RestoreDC(HDC hdc,صحيح nSavedDC);
  WINGDIAPI HDC WINAPI ResetDCA(HDC hdc,CONST DEVMODEA *lpdm);
  WINGDIAPI HDC WINAPI ResetDCW(HDC hdc,CONST DEVMODEW *lpdm);
  WINGDIAPI UINT WINAPI RealizePalette(HDC hdc);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceA(LPCSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceW(LPCWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI پړاو_Rect(HDC hdc,صحيح کیڼ,صحيح سر,صحيح ښی,صحيح bottom,صحيح پلنوالی,صحيح لوړوالی);
  WINGDIAPI WINBOOL WINAPI ResizePalette(HPALETTE hpal,UINT n);
  WINGDIAPI صحيح WINAPI SaveDC(HDC hdc);
  WINGDIAPI صحيح WINAPI SelectClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI صحيح WINAPI ExtSelectClipRgn(HDC hdc,HRGN hrgn,صحيح ډېرپېښ);
  WINGDIAPI صحيح WINAPI سېټ_Meta_Rgn(HDC hdc);
  WINGDIAPI HGDIOBJ WINAPI SelectObject(HDC hdc,HGDIOBJ h);
  WINGDIAPI HPALETTE WINAPI SelectPalette(HDC hdc,HPALETTE hPal,WINBOOL bForceBkgd);
  WINGDIAPI COLORREF WINAPI سېټ_Bk_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI سېټ_DCBrush_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI سېټ_DCPen_Color(HDC hdc,COLORREF color);
  WINGDIAPI صحيح WINAPI سېټ_Bk_ډېرپېښ(HDC hdc,صحيح ډېرپېښ);
  WINGDIAPI LONG WINAPI سېټ_Bitmap_بټونه(HBITMAP hbm,DWORD cb,CONST VOID *pv_بټونه);
  WINGDIAPI UINT WINAPI سېټ_Bounds_Rect(HDC hdc,CONST RECT *lprect,UINT flags);
  WINGDIAPI صحيح WINAPI سېټ_DIBits(HDC hdc,HBITMAP hbm,UINT پیل,UINT c_کرښې,CONST VOID *lp_بټونه,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI صحيح WINAPI سېټ_DIBits_منزل_Device(HDC hdc,صحيح xDest,صحيح yDest,DWORD w,DWORD h,صحيح xSrc,صحيح ySrc,UINT پیل_لټون,UINT c_کرښې,CONST VOID *lpv_بټونه,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI DWORD WINAPI سېټ_Mapper_Flags(HDC hdc,DWORD flags);
  WINGDIAPI صحيح WINAPI سېټ_Graphics_ډېرپېښ(HDC hdc,صحيح i_ډېرپېښ);
  WINGDIAPI صحيح WINAPI سېټ_Map_ډېرپېښ(HDC hdc,صحيح i_ډېرپېښ);
  WINGDIAPI DWORD WINAPI سېټ_Layout(HDC hdc,DWORD l);
  WINGDIAPI DWORD WINAPI GetLayout(HDC hdc);
  WINGDIAPI HMETAFILE WINAPI سېټ_Meta_File_بټونه_Ex(UINT cb_بفر,CONST BYTE *lp_معلومات);
  WINGDIAPI UINT WINAPI سېټ_Palette_Entries(HPALETTE hpal,UINT i_پیل,UINT cEntries,CONST PALETTEENTRY *pPalEntries);
  WINGDIAPI COLORREF WINAPI سېټ_Pixel(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI سېټ_Pixel_V(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI سېټ_Pixel_Format(HDC hdc,صحيح format,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI صحيح WINAPI سېټ_Poly_Fill_ډېرپېښ(HDC hdc,صحيح ډېرپېښ);
  WINGDIAPI WINBOOL WINAPI StretchBlt(HDC hdcDest,صحيح xDest,صحيح yDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xSrc,صحيح ySrc,صحيح wSrc,صحيح hSrc,DWORD rop);
  WINGDIAPI WINBOOL WINAPI سېټ_Rect_Rgn(HRGN hrgn,صحيح کیڼ,صحيح سر,صحيح ښی,صحيح bottom);
  WINGDIAPI صحيح WINAPI StretchDIBits(HDC hdc,صحيح xDest,صحيح yDest,صحيح Dest_پلنوالی,صحيح Dest_لوړوالی,صحيح xSrc,صحيح ySrc,صحيح Src_پلنوالی,صحيح Src_لوړوالی,CONST VOID *lp_بټونه,CONST BITMAPINFO *lpbmi,UINT iUsage,DWORD rop);
  WINGDIAPI صحيح WINAPI سېټ_ROP2(HDC hdc,صحيح rop2);
  WINGDIAPI صحيح WINAPI سېټ_Stretch_Blt_ډېرپېښ(HDC hdc,صحيح ډېرپېښ);
  WINGDIAPI UINT WINAPI سېټ_System_Palette_Use(HDC hdc,UINT use);
  WINGDIAPI صحيح WINAPI سېټ_متن_Character_Extra(HDC hdc,صحيح extra);
  WINGDIAPI COLORREF WINAPI سېټ_متن_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI سېټ_متن_Align(HDC hdc,UINT align);
  WINGDIAPI WINBOOL WINAPI سېټ_متن_Justification(HDC hdc,صحيح extra,صحيح شمېر_2);
  WINGDIAPI WINBOOL WINAPI UpdateColors(HDC hdc);

  تعريفنوع USHORT COLOR16;

  تعريفنوع بنية _TRIVERTEX {
    LONG x;
    LONG y;
    COLOR16 Red;
    COLOR16 Green;
    COLOR16 Blue;
    COLOR16 Alpha;
  } TRIVERTEX,*PTRIVERTEX,*LPTRIVERTEX;

  تعريفنوع بنية _GRADIENT_TRIANGLE {
    ULONG Vertex1;
    ULONG Vertex2;
    ULONG Vertex3;
  } GRADIENT_TRIANGLE,*PGRADIENT_TRIANGLE,*LPGRADIENT_TRIANGLE;

  تعريفنوع بنية _GRADIENT_RECT {
    ULONG پاسنی_کیڼ;
    ULONG ښکتنی_ښی;
  } GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;

  تعريفنوع بنية _BLENDFUNCTION {
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE سرچینه_Constant_Alpha;
    BYTE AlphaFormat;
  } BLENDFUNCTION,*PBLENDFUNCTION;

#تعریف_کړه AC_SRC_OVER 0x00
#تعریف_کړه AC_SRC_ALPHA 0x01

  WINGDIAPI WINBOOL WINAPI AlphaBlend(HDC hdcDest,صحيح xoriginDest,صحيح yoriginDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xoriginSrc,صحيح yoriginSrc,صحيح wSrc,صحيح hSrc,BLENDFUNCTION ftn);
  WINGDIAPI WINBOOL WINAPI TransparentBlt(HDC hdcDest,صحيح xoriginDest,صحيح yoriginDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xoriginSrc,صحيح yoriginSrc,صحيح wSrc,صحيح hSrc,UINT crTransparent);

#تعریف_کړه GRADIENT_FILL_RECT_H 0x00000000
#تعریف_کړه GRADIENT_FILL_RECT_V 0x00000001
#تعریف_کړه GRADIENT_FILL_TRIANGLE 0x00000002
#تعریف_کړه GRADIENT_FILL_OP_FLAG 0x000000ff

  WINGDIAPI WINBOOL WINAPI GradientFill(HDC hdc,PTRIVERTEX p_راس,ULONG n_راس,PVOID pMesh,ULONG nMesh,ULONG ul_ډېرپېښ);

#که_نه_تعریف_شوی NOMETAFILE

#که_تعریف_شوی UNICODE
#تعریف_کړه CopyEnhMetaFile CopyEnhMetaFileW
#تعریف_کړه CreateEnhMetaFile CreateEnhMetaFileW
#تعریف_کړه GetEnhMetaFile GetEnhMetaFileW
#تعریف_کړه GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#وإلا
#تعریف_کړه CopyEnhMetaFile CopyEnhMetaFileA
#تعریف_کړه CreateEnhMetaFile CreateEnhMetaFileA
#تعریف_کړه GetEnhMetaFile GetEnhMetaFileA
#تعریف_کړه GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#د_که_پای

  WINGDIAPI WINBOOL WINAPI Play_Meta_File_ریکارډ(HDC hdc,LPHANDLETABLE lp_Handle_جدول,LPMETARECORD lpMR,UINT noObjs);

  تعريفنوع صحيح (CALLBACK *MFENUMPROC)(HDC hdc,HANDLETABLE *lpht,METARECORD *lpMR,صحيح nObj,LPARAM param);

  WINGDIAPI WINBOOL WINAPI EnumMetaFile(HDC hdc,HMETAFILE hmf,MFENUMPROC proc,LPARAM param);

  تعريفنوع صحيح (CALLBACK *ENHMFENUMPROC)(HDC hdc,HANDLETABLE *lpht,CONST ENHMETARECORD *lpmr,صحيح hHandles,LPARAM معلومات);

  WINGDIAPI HENHMETAFILE WINAPI CloseEnhMetaFile(HDC hdc);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileA(HENHMETAFILE hEnh,LPCSTR lpFileName);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileW(HENHMETAFILE hEnh,LPCWSTR lpFileName);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileA(HDC hdc,LPCSTR lpFilename,CONST RECT *lprc,LPCSTR lpDesc);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileW(HDC hdc,LPCWSTR lpFilename,CONST RECT *lprc,LPCWSTR lpDesc);
  WINGDIAPI WINBOOL WINAPI DeleteEnhMetaFile(HENHMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI EnumEnhMetaFile(HDC hdc,HENHMETAFILE hmf,ENHMFENUMPROC proc,LPVOID param,CONST RECT *lpRect);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileA(LPCSTR lpName);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileW(LPCWSTR lpName);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_بټونه(HENHMETAFILE hEMF,UINT n_اندازه,LPBYTE lp_معلومات);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE hemf,UINT cch_بفر,LPSTR lpDescription);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE hemf,UINT cch_بفر,LPWSTR lpDescription);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_سرلیک(HENHMETAFILE hemf,UINT n_اندازه,LPENHMETAHEADER lp_Enh_Meta_سرلیک);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT n_عدد_Entries,LPPALETTEENTRY lpPaletteEntries);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePixelFormat(HENHMETAFILE hemf,UINT cb_بفر,PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI UINT WINAPI Get_Win_Meta_File_بټونه(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT i_Map_ډېرپېښ,HDC hdcRef);
  WINGDIAPI WINBOOL WINAPI PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Play_Enh_Meta_File_ریکارډ(HDC hdc,LPHANDLETABLE pht,CONST ENHMETARECORD *pmr,UINT cht);
  WINGDIAPI HENHMETAFILE WINAPI سېټ_Enh_Meta_File_بټونه(UINT n_اندازه,CONST BYTE *pb);
  WINGDIAPI HENHMETAFILE WINAPI سېټ_Win_Meta_File_بټونه(UINT n_اندازه,CONST BYTE *lp_Meta16_معلومات,HDC hdcRef,CONST METAFILEPICT *lpMFP);
  WINGDIAPI WINBOOL WINAPI GdiComment(HDC hdc,UINT n_اندازه,CONST BYTE *lp_معلومات);
#د_که_پای

#که_نه_تعریف_شوی NOTEXTMETRIC
#که_تعریف_شوی UNICODE
#تعریف_کړه Get_متن_Metrics Get_متن_Metrics_W
#وإلا
#تعریف_کړه Get_متن_Metrics Get_متن_Metrics_A
#د_که_پای

  WINGDIAPI WINBOOL WINAPI Get_متن_Metrics_A(HDC hdc,LPTEXTMETRICA lptm);
  WINGDIAPI WINBOOL WINAPI Get_متن_Metrics_W(HDC hdc,LPTEXTMETRICW lptm);
#د_که_پای

  تعريفنوع بنية نښان_DIBSECTION {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD ds_دننه_واټن;
  } DIBSECTION,*LPDIBSECTION,*PDIBSECTION;

  WINGDIAPI WINBOOL WINAPI AngleArc(HDC hdc,صحيح x,صحيح y,DWORD r,FLOAT پیل_Angle,FLOAT SweepAngle);
  WINGDIAPI WINBOOL WINAPI PolyPolyline(HDC hdc,CONST ټکی_3 *apt,CONST DWORD *asz,DWORD csz);
  WINGDIAPI WINBOOL WINAPI GetWorldTransform(HDC hdc,LPXFORM lpxf);
  WINGDIAPI WINBOOL WINAPI سېټ_World_Transform(HDC hdc,CONST XFORM *lpxf);
  WINGDIAPI WINBOOL WINAPI ModifyWorldTransform(HDC hdc,CONST XFORM *lpxf,DWORD ډېرپېښ);
  WINGDIAPI WINBOOL WINAPI CombineTransform(LPXFORM lpxf_بهر,CONST XFORM *lpxf1,CONST XFORM *lpxf2);
  WINGDIAPI HBITMAP WINAPI CreateDIBSection(HDC hdc,CONST BITMAPINFO *lpbmi,UINT usage,VOID **ppv_بټونه,HANDLE hSection,DWORD دننه_واټن);
  WINGDIAPI UINT WINAPI Get_DIBColor_جدول(HDC hdc,UINT i_پیل,UINT cEntries,RGBQUAD *prgbq);
  WINGDIAPI UINT WINAPI سېټ_DIBColor_جدول(HDC hdc,UINT i_پیل,UINT cEntries,CONST RGBQUAD *prgbq);

#تعریف_کړه CA_NEGATIVE 0x0001
#تعریف_کړه CA_LOG_FILTER 0x0002

#تعریف_کړه ILLUMINANT_DEVICE_DEFAULT 0
#تعریف_کړه ILLUMINANT_A 1
#تعریف_کړه ILLUMINANT_B 2
#تعریف_کړه ILLUMINANT_C 3
#تعریف_کړه ILLUMINANT_D50 4
#تعریف_کړه ILLUMINANT_D55 5
#تعریف_کړه ILLUMINANT_D65 6
#تعریف_کړه ILLUMINANT_D75 7
#تعریف_کړه ILLUMINANT_F2 8
#تعریف_کړه ILLUMINANT_MAX_شاخص ILLUMINANT_F2

#تعریف_کړه ILLUMINANT_TUNGSTEN ILLUMINANT_A
#تعریف_کړه ILLUMINANT_DAYLIGHT ILLUMINANT_C
#تعریف_کړه ILLUMINANT_FLUORESCENT ILLUMINANT_F2
#تعریف_کړه ILLUMINANT_NTSC ILLUMINANT_C

#تعریف_کړه RGB_GAMMA_MIN (کلمه_3)02500
#تعریف_کړه RGB_GAMMA_MAX (کلمه_3)65000

#تعریف_کړه REFERENCE_WHITE_MIN (کلمه_3)6000
#تعریف_کړه REFERENCE_WHITE_MAX (کلمه_3)10000
#تعریف_کړه REFERENCE_BLACK_MIN (کلمه_3)0
#تعریف_کړه REFERENCE_BLACK_MAX (کلمه_3)4000

#تعریف_کړه COLOR_ADJ_MIN (SHORT)-100
#تعریف_کړه COLOR_ADJ_MAX (SHORT)100

  تعريفنوع بنية نښان_COLORADJUSTMENT {
    کلمه_3 ca_اندازه;
    کلمه_3 caFlags;
    کلمه_3 ca_Illuminant_شاخص;
    کلمه_3 caRedGamma;
    کلمه_3 caGreenGamma;
    کلمه_3 caBlueGamma;
    کلمه_3 caReferenceBlack;
    کلمه_3 caReferenceWhite;
    SHORT caContrast;
    SHORT caBrightness;
    SHORT caColorfulness;
    SHORT caRedGreenTint;
  } COLORADJUSTMENT,*PCOLORADJUSTMENT,*LPCOLORADJUSTMENT;

  WINGDIAPI WINBOOL WINAPI سېټ_Color_Adjustment(HDC hdc,CONST COLORADJUSTMENT *lpca);
  WINGDIAPI WINBOOL WINAPI GetColorAdjustment(HDC hdc,LPCOLORADJUSTMENT lpca);
  WINGDIAPI HPALETTE WINAPI CreateHalftonePalette(HDC hdc);

  تعريفنوع WINBOOL (CALLBACK *ABORTPROC)(HDC,صحيح);

  تعريفنوع بنية _DOCINFOA {
    صحيح cb_اندازه;
    LPCSTR lpszDocName;
    LPCSTR lpszOutput;
    LPCSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOA,*LPDOCINFOA;

  تعريفنوع بنية _DOCINFOW {
    صحيح cb_اندازه;
    LPCWSTR lpszDocName;
    LPCWSTR lpszOutput;
    LPCWSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOW,*LPDOCINFOW;

#که_تعریف_شوی UNICODE
  تعريفنوع DOCINFOW DOCINFO;
  تعريفنوع LPDOCINFOW LPDOCINFO;
#وإلا
  تعريفنوع DOCINFOA DOCINFO;
  تعريفنوع LPDOCINFOA LPDOCINFO;
#د_که_پای

#تعریف_کړه DI_APPBANDING 0x00000001
#تعریف_کړه DI_ROPS_READ_DESTINATION 0x00000002

#که_تعریف_شوی UNICODE
#تعریف_کړه پیل_Doc پیل_Doc_W
#تعریف_کړه GetObject GetObjectW
#تعریف_کړه متن_بهر متن_بهر_W
#تعریف_کړه Ext_متن_بهر Ext_متن_بهر_W
#تعریف_کړه Poly_متن_بهر Poly_متن_بهر_W
#تعریف_کړه Get_متن_Face Get_متن_Face_W
#وإلا
#تعریف_کړه پیل_Doc پیل_Doc_A
#تعریف_کړه GetObject GetObjectA
#تعریف_کړه متن_بهر متن_بهر_A
#تعریف_کړه Ext_متن_بهر Ext_متن_بهر_A
#تعریف_کړه Poly_متن_بهر Poly_متن_بهر_A
#تعریف_کړه Get_متن_Face Get_متن_Face_A
#د_که_پای

  WINGDIAPI صحيح WINAPI پیل_Doc_A(HDC hdc,CONST DOCINFOA *lpdi);
  WINGDIAPI صحيح WINAPI پیل_Doc_W(HDC hdc,CONST DOCINFOW *lpdi);
  WINGDIAPI صحيح WINAPI پای_ټکی_Doc(HDC hdc);
  WINGDIAPI صحيح WINAPI پیل_پاڼه(HDC hdc);
  WINGDIAPI صحيح WINAPI پای_ټکی_پاڼه(HDC hdc);
  WINGDIAPI صحيح WINAPI AbortDoc(HDC hdc);
  WINGDIAPI صحيح WINAPI سېټ_Abort_Proc(HDC hdc,ABORTPROC proc);
  WINGDIAPI WINBOOL WINAPI Abort_لار(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Arc_منزل(HDC hdc,صحيح کیڼ,صحيح سر,صحيح ښی,صحيح bottom,صحيح xr1,صحيح yr1,صحيح xr2,صحيح yr2);
  WINGDIAPI WINBOOL WINAPI Begin_لار(HDC hdc);
  WINGDIAPI WINBOOL WINAPI CloseFigure(HDC hdc);
  WINGDIAPI WINBOOL WINAPI پای_ټکی_لار_2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Fill_لار(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Flatten_لار(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_لار(HDC hdc,LPPOINT apt,LPBYTE aj,صحيح cpt);
  WINGDIAPI HRGN WINAPI لار_منزل_Region(HDC hdc);
  WINGDIAPI WINBOOL WINAPI PolyDraw(HDC hdc,CONST ټکی_3 *apt,CONST BYTE *aj,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI Select_Clip_لار(HDC hdc,صحيح ډېرپېښ);
  WINGDIAPI صحيح WINAPI سېټ_Arc_Direction(HDC hdc,صحيح dir);
  WINGDIAPI WINBOOL WINAPI سېټ_Miter_حد(HDC hdc,FLOAT حد,PFLOAT old);
  WINGDIAPI WINBOOL WINAPI Stroke_And_Fill_لار(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Stroke_لار(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Widen_لار(HDC hdc);
  WINGDIAPI HPEN WINAPI ExtCreatePen(DWORD iPenStyle,DWORD c_پلنوالی,CONST LOGBRUSH *plbrush,DWORD cStyle,CONST DWORD *pstyle);
  WINGDIAPI WINBOOL WINAPI Get_Miter_حد(HDC hdc,PFLOAT plimit);
  WINGDIAPI صحيح WINAPI GetArcDirection(HDC hdc);
  WINGDIAPI صحيح WINAPI GetObjectA(HANDLE h,صحيح c,LPVOID pv);
  WINGDIAPI صحيح WINAPI GetObjectW(HANDLE h,صحيح c,LPVOID pv);
  WINGDIAPI WINBOOL WINAPI Move_منزل_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI متن_بهر_A(HDC hdc,صحيح x,صحيح y,LPCSTR lpString,صحيح c);
  WINGDIAPI WINBOOL WINAPI متن_بهر_W(HDC hdc,صحيح x,صحيح y,LPCWSTR lpString,صحيح c);
  WINGDIAPI WINBOOL WINAPI Ext_متن_بهر_A(HDC hdc,صحيح x,صحيح y,UINT options,CONST RECT *lprect,LPCSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Ext_متن_بهر_W(HDC hdc,صحيح x,صحيح y,UINT options,CONST RECT *lprect,LPCWSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Poly_متن_بهر_A(HDC hdc,CONST POLYTEXTA *ppt,صحيح nstrings);
  WINGDIAPI WINBOOL WINAPI Poly_متن_بهر_W(HDC hdc,CONST POLYTEXTW *ppt,صحيح nstrings);
  WINGDIAPI HRGN WINAPI CreatePolygonRgn(CONST ټکی_3 *pptl,صحيح c_ټکی,صحيح i_ډېرپېښ);
  WINGDIAPI WINBOOL WINAPI DPtoLP(HDC hdc,LPPOINT lppt,صحيح c);
  WINGDIAPI WINBOOL WINAPI LPtoDP(HDC hdc,LPPOINT lppt,صحيح c);
  WINGDIAPI WINBOOL WINAPI Polygon(HDC hdc,CONST ټکی_3 *apt,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI Polyline(HDC hdc,CONST ټکی_3 *apt,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI PolyBezier(HDC hdc,CONST ټکی_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Poly_Bezier_منزل(HDC hdc,CONST ټکی_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Polyline_منزل(HDC hdc,CONST ټکی_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI سېټ_Viewport_Ext_Ex(HDC hdc,صحيح x,صحيح y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سېټ_Viewport_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI سېټ_کړکۍ_Ext_Ex(HDC hdc,صحيح x,صحيح y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سېټ_کړکۍ_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI دننه_واټن_Viewport_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI دننه_واټن_کړکۍ_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ScaleViewportExtEx(HDC hdc,صحيح xn,صحيح dx,صحيح yn,صحيح yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Scale_کړکۍ_Ext_Ex(HDC hdc,صحيح xn,صحيح xd,صحيح yn,صحيح yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سېټ_Bitmap_Dimension_Ex(HBITMAP hbm,صحيح w,صحيح h,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سېټ_Brush_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI صحيح WINAPI Get_متن_Face_A(HDC hdc,صحيح c,LPSTR lpName);
  WINGDIAPI صحيح WINAPI Get_متن_Face_W(HDC hdc,صحيح c,LPWSTR lpName);

#تعریف_کړه FONTMAPPER_MAX 10

  تعريفنوع بنية نښان_KERNINGPAIR {
    کلمه_3 w_لومړی;
    کلمه_3 w_دوهم;
    صحيح iKernAmount;
  } KERNINGPAIR,*LPKERNINGPAIR;

#که_تعریف_شوی UNICODE
#تعریف_کړه Get_Kerning_جوړې Get_Kerning_جوړې_W
#وإلا
#تعریف_کړه Get_Kerning_جوړې Get_Kerning_جوړې_A
#د_که_پای

  WINGDIAPI DWORD WINAPI Get_Kerning_جوړې_A(HDC hdc,DWORD n_جوړې,LPKERNINGPAIR lpKernPair);
  WINGDIAPI DWORD WINAPI Get_Kerning_جوړې_W(HDC hdc,DWORD n_جوړې,LPKERNINGPAIR lpKernPair);
  WINGDIAPI WINBOOL WINAPI GetDCOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI FixBrushOrgEx(HDC hdc,صحيح x,صحيح y,LPPOINT ptl);
  WINGDIAPI WINBOOL WINAPI UnrealizeObject(HGDIOBJ h);
  WINGDIAPI WINBOOL WINAPI GdiFlush();
  WINGDIAPI DWORD WINAPI Gdi_سېټ_Batch_حد(DWORD dw);
  WINGDIAPI DWORD WINAPI Gdi_Get_Batch_حد();

#تعریف_کړه ICM_OFF 1
#تعریف_کړه ICM_ON 2
#تعریف_کړه ICM_QUERY 3
#تعریف_کړه ICM_بشپړ_OUTSIDEDC 4

  تعريفنوع صحيح (CALLBACK *ICMENUMPROCA)(LPSTR,LPARAM);
  تعريفنوع صحيح (CALLBACK *ICMENUMPROCW)(LPWSTR,LPARAM);

#که_تعریف_شوی UNICODE
#تعریف_کړه ICMENUMPROC ICMENUMPROCW
#تعریف_کړه EnumICMProfiles EnumICMProfilesW
#تعریف_کړه Update_ICMReg_کلی Update_ICMReg_کلی_W
#تعریف_کړه GetLogColorSpace GetLogColorSpaceW
#تعریف_کړه CreateColorSpace CreateColorSpaceW
#تعریف_کړه GetICMProfile GetICMProfileW
#تعریف_کړه سېټ_ICMProfile سېټ_ICMProfile_W
#وإلا
#تعریف_کړه ICMENUMPROC ICMENUMPROCA
#تعریف_کړه EnumICMProfiles EnumICMProfilesA
#تعریف_کړه Update_ICMReg_کلی Update_ICMReg_کلی_A
#تعریف_کړه GetLogColorSpace GetLogColorSpaceA
#تعریف_کړه CreateColorSpace CreateColorSpaceA
#تعریف_کړه GetICMProfile GetICMProfileA
#تعریف_کړه سېټ_ICMProfile سېټ_ICMProfile_A
#د_که_پای

  WINGDIAPI صحيح WINAPI سېټ_ICMMode(HDC hdc,صحيح ډېرپېښ);
  WINGDIAPI WINBOOL WINAPI Check_Colors_دننه_Gamut(HDC hdc,LPVOID lpRGBTriple,LPVOID dlp_بفر,DWORD n_شمېر);
  WINGDIAPI HCOLORSPACE WINAPI GetColorSpace(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceA(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEA lp_بفر,DWORD n_اندازه);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceW(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEW lp_بفر,DWORD n_اندازه);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA lplcs);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW lplcs);
  WINGDIAPI HCOLORSPACE WINAPI سېټ_Color_Space(HDC hdc,HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI DeleteColorSpace(HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI GetICMProfileA(HDC hdc,LPDWORD p_Buf_اندازه,LPSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI GetICMProfileW(HDC hdc,LPDWORD p_Buf_اندازه,LPWSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI سېټ_ICMProfile_A(HDC hdc,LPSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI سېټ_ICMProfile_W(HDC hdc,LPWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI GetDeviceGammaRamp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI سېټ_Device_Gamma_Ramp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI Color_سمون_منزل_موخه(HDC hdc,HDC hdc_موخه,DWORD action);
  WINGDIAPI صحيح WINAPI EnumICMProfilesA(HDC hdc,ICMENUMPROCA proc,LPARAM param);
  WINGDIAPI صحيح WINAPI EnumICMProfilesW(HDC hdc,ICMENUMPROCW proc,LPARAM param);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_کلی_A(DWORD reserved,LPSTR lpszCMID,LPSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_کلی_W(DWORD reserved,LPWSTR lpszCMID,LPWSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI ColorCorrectPalette(HDC hdc,HPALETTE hPal,DWORD de_لومړی,DWORD عدد);

#که_نه_تعریف_شوی NOMETAFILE

#تعریف_کړه ENHMETA_SIGNATURE 0x464D4520
#تعریف_کړه ENHMETA_STOCK_OBJECT 0x80000000

#تعریف_کړه EMR_سرلیک 1
#تعریف_کړه EMR_POLYBEZIER 2
#تعریف_کړه EMR_POLYGON 3
#تعریف_کړه EMR_POLYLINE 4
#تعریف_کړه EMR_POLYBEZIERTO 5
#تعریف_کړه EMR_POLYLINETO 6
#تعریف_کړه EMR_POLYPOLYLINE 7
#تعریف_کړه EMR_POLYPOLYGON 8
#تعریف_کړه EMR_SETWINDOWEXTEX 9
#تعریف_کړه EMR_SETWINDOWORGEX 10
#تعریف_کړه EMR_SETVIEWPORTEXTEX 11
#تعریف_کړه EMR_SETVIEWPORTORGEX 12
#تعریف_کړه EMR_SETBRUSHORGEX 13
#تعریف_کړه EMR_EOF 14
#تعریف_کړه EMR_SETPIXELV 15
#تعریف_کړه EMR_SETMAPPERFLAGS 16
#تعریف_کړه EMR_SETMAPMODE 17
#تعریف_کړه EMR_SETBKMODE 18
#تعریف_کړه EMR_SETPOLYFILLMODE 19
#تعریف_کړه EMR_SETROP2 20
#تعریف_کړه EMR_SETSTRETCHBLTMODE 21
#تعریف_کړه EMR_SETTEXTALIGN 22
#تعریف_کړه EMR_SETCOLORADJUSTMENT 23
#تعریف_کړه EMR_SETTEXTCOLOR 24
#تعریف_کړه EMR_SETBKCOLOR 25
#تعریف_کړه EMR_OFFSETCLIPRGN 26
#تعریف_کړه EMR_MOVETOEX 27
#تعریف_کړه EMR_SETMETARGN 28
#تعریف_کړه EMR_EXCLUDECLIPRECT 29
#تعریف_کړه EMR_INTERSECTCLIPRECT 30
#تعریف_کړه EMR_SCALEVIEWPORTEXTEX 31
#تعریف_کړه EMR_SCALEWINDOWEXTEX 32
#تعریف_کړه EMR_SAVEDC 33
#تعریف_کړه EMR_RESTOREDC 34
#تعریف_کړه EMR_SETWORLDTRANSFORM 35
#تعریف_کړه EMR_MODIFYWORLDTRANSFORM 36
#تعریف_کړه EMR_SELECTOBJECT 37
#تعریف_کړه EMR_CREATEPEN 38
#تعریف_کړه EMR_CREATEBRUSHINDIRECT 39
#تعریف_کړه EMR_DELETEOBJECT 40
#تعریف_کړه EMR_ANGLEARC 41
#تعریف_کړه EMR_ELLIPSE 42
#تعریف_کړه EMR_RECTANGLE 43
#تعریف_کړه EMR_ROUNDRECT 44
#تعریف_کړه EMR_ARC 45
#تعریف_کړه EMR_CHORD 46
#تعریف_کړه EMR_PIE 47
#تعریف_کړه EMR_SELECTPALETTE 48
#تعریف_کړه EMR_CREATEPALETTE 49
#تعریف_کړه EMR_SETPALETTEENTRIES 50
#تعریف_کړه EMR_RESIZEPALETTE 51
#تعریف_کړه EMR_REALIZEPALETTE 52
#تعریف_کړه EMR_EXTFLOODFILL 53
#تعریف_کړه EMR_LINETO 54
#تعریف_کړه EMR_ARCTO 55
#تعریف_کړه EMR_POLYDRAW 56
#تعریف_کړه EMR_SETARCDIRECTION 57
#تعریف_کړه EMR_SETMITERLIMIT 58
#تعریف_کړه EMR_BEGINPATH 59
#تعریف_کړه EMR_ENDPATH 60
#تعریف_کړه EMR_CLOSEFIGURE 61
#تعریف_کړه EMR_FILLPATH 62
#تعریف_کړه EMR_STROKEANDFILLPATH 63
#تعریف_کړه EMR_STROKEPATH 64
#تعریف_کړه EMR_FLATTENPATH 65
#تعریف_کړه EMR_WIDENPATH 66
#تعریف_کړه EMR_SELECTCLIPPATH 67
#تعریف_کړه EMR_ABORTPATH 68

#تعریف_کړه EMR_GDICOMMENT 70
#تعریف_کړه EMR_FILLRGN 71
#تعریف_کړه EMR_FRAMERGN 72
#تعریف_کړه EMR_INVERTRGN 73
#تعریف_کړه EMR_PAINTRGN 74
#تعریف_کړه EMR_EXTSELECTCLIPRGN 75
#تعریف_کړه EMR_BITBLT 76
#تعریف_کړه EMR_STRETCHBLT 77
#تعریف_کړه EMR_MASKBLT 78
#تعریف_کړه EMR_PLGBLT 79
#تعریف_کړه EMR_SETDIBITSTODEVICE 80
#تعریف_کړه EMR_STRETCHDIBITS 81
#تعریف_کړه EMR_EXTCREATEFONTINDIRECTW 82
#تعریف_کړه EMR_EXTTEXTOUTA 83
#تعریف_کړه EMR_EXTTEXTOUTW 84
#تعریف_کړه EMR_POLYBEZIER16 85
#تعریف_کړه EMR_POLYGON16 86
#تعریف_کړه EMR_POLYLINE16 87
#تعریف_کړه EMR_POLYBEZIERTO16 88
#تعریف_کړه EMR_POLYLINETO16 89
#تعریف_کړه EMR_POLYPOLYLINE16 90
#تعریف_کړه EMR_POLYPOLYGON16 91
#تعریف_کړه EMR_POLYDRAW16 92
#تعریف_کړه EMR_CREATEMONOBRUSH 93
#تعریف_کړه EMR_CREATEDIBPATTERNBRUSHPT 94
#تعریف_کړه EMR_EXTCREATEPEN 95
#تعریف_کړه EMR_POLYTEXTOUTA 96
#تعریف_کړه EMR_POLYTEXTOUTW 97

#تعریف_کړه EMR_SETICMMODE 98
#تعریف_کړه EMR_CREATECOLORSPACE 99
#تعریف_کړه EMR_SETCOLORSPACE 100
#تعریف_کړه EMR_DELETECOLORSPACE 101
#تعریف_کړه EMR_GLSRECORD 102
#تعریف_کړه EMR_GLSBOUNDEDRECORD 103
#تعریف_کړه EMR_PIXELFORMAT 104
#تعریف_کړه EMR_RESERVED_105 105
#تعریف_کړه EMR_RESERVED_106 106
#تعریف_کړه EMR_RESERVED_107 107
#تعریف_کړه EMR_RESERVED_108 108
#تعریف_کړه EMR_RESERVED_109 109
#تعریف_کړه EMR_RESERVED_110 110
#تعریف_کړه EMR_COLORCORRECTPALETTE 111
#تعریف_کړه EMR_SETICMPROFILEA 112
#تعریف_کړه EMR_SETICMPROFILEW 113
#تعریف_کړه EMR_ALPHABLEND 114
#تعریف_کړه EMR_SETLAYOUT 115
#تعریف_کړه EMR_TRANSPARENTBLT 116
#تعریف_کړه EMR_RESERVED_117 117
#تعریف_کړه EMR_GRADIENTFILL 118
#تعریف_کړه EMR_RESERVED_119 119
#تعریف_کړه EMR_RESERVED_120 120
#تعریف_کړه EMR_COLORMATCHTOTARGETW 121
#تعریف_کړه EMR_CREATECOLORSPACEW 122

#تعریف_کړه EMR_MIN 1

#تعریف_کړه EMR_MAX 122

  تعريفنوع بنية نښان_EMR {
    DWORD iType;
    DWORD n_اندازه;
  } EMR,*PEMR;

  تعريفنوع بنية نښان_EMRTEXT {
    POINTL ptlReference;
    DWORD nChars;
    DWORD offString;
    DWORD fOptions;
    RECTL rcl;
    DWORD offDx;
  } EMRTEXT,*PEMRTEXT;

  تعريفنوع بنية نښان_ABORTPATH {
    EMR emr;
  } EMRABORTPATH,*PEMRABORTPATH,EMRBEGINPATH,*PEMRBEGINPATH,EMRENDPATH,*PEMRENDPATH,EMRCLOSEFIGURE,*PEMRCLOSEFIGURE,EMRFLATTENPATH,*PEMRFLATTENPATH,EMRWIDENPATH,*PEMRWIDENPATH,EMRSETMETARGN,*PEMRSETMETARGN,EMRSAVEDC,*PEMRSAVEDC,EMRREALIZEPALETTE,*PEMRREALIZEPALETTE;

  تعريفنوع بنية نښان_EMRSELECTCLIPPATH {
    EMR emr;
    DWORD i_ډېرپېښ;
  } EMRSELECTCLIPPATH,*PEMRSELECTCLIPPATH,EMRSETBKMODE,*PEMRSETBKMODE,EMRSETMAPMODE,*PEMRSETMAPMODE,EMRSETLAYOUT,*PEMRSETLAYOUT,
    EMRSETPOLYFILLMODE,*PEMRSETPOLYFILLMODE,EMRSETROP2,*PEMRSETROP2,EMRSETSTRETCHBLTMODE,*PEMRSETSTRETCHBLTMODE,EMRSETICMMODE,
    *PEMRSETICMMODE,EMRSETTEXTALIGN,*PEMRSETTEXTALIGN;

  تعريفنوع بنية نښان_EMRSETMITERLIMIT {
    EMR emr;
    FLOAT e_Miter_حد;
  } EMRSETMITERLIMIT,*PEMRSETMITERLIMIT;

  تعريفنوع بنية نښان_EMRRESTOREDC {
    EMR emr;
    LONG iRelative;
  } EMRRESTOREDC,*PEMRRESTOREDC;

  تعريفنوع بنية نښان_EMRSETARCDIRECTION {
    EMR emr;
    DWORD iArcDirection;

  } EMRSETARCDIRECTION,*PEMRSETARCDIRECTION;

  تعريفنوع بنية نښان_EMRSETMAPPERFLAGS {
    EMR emr;
    DWORD dwFlags;
  } EMRSETMAPPERFLAGS,*PEMRSETMAPPERFLAGS;

  تعريفنوع بنية نښان_EMRSETTEXTCOLOR {
    EMR emr;
    COLORREF crColor;
  } EMRSETBKCOLOR,*PEMRSETBKCOLOR,EMRSETTEXTCOLOR,*PEMRSETTEXTCOLOR;

  تعريفنوع بنية نښان_EMRSELECTOBJECT {
    EMR emr;
    DWORD ihObject;
  } EMRSELECTOBJECT,*PEMRSELECTOBJECT,EMRDELETEOBJECT,*PEMRDELETEOBJECT;

  تعريفنوع بنية نښان_EMRSELECTPALETTE {
    EMR emr;
    DWORD ihPal;
  } EMRSELECTPALETTE,*PEMRSELECTPALETTE;

  تعريفنوع بنية نښان_EMRRESIZEPALETTE {
    EMR emr;
    DWORD ihPal;
    DWORD cEntries;
  } EMRRESIZEPALETTE,*PEMRRESIZEPALETTE;

  تعريفنوع بنية نښان_EMRSETPALETTEENTRIES {
    EMR emr;
    DWORD ihPal;
    DWORD i_پیل;
    DWORD cEntries;
    PALETTEENTRY aPalEntries[1];
  } EMRSETPALETTEENTRIES,*PEMRSETPALETTEENTRIES;

  تعريفنوع بنية نښان_EMRSETCOLORADJUSTMENT {
    EMR emr;
    COLORADJUSTMENT ColorAdjustment;
  } EMRSETCOLORADJUSTMENT,*PEMRSETCOLORADJUSTMENT;

  تعريفنوع بنية نښان_EMRGDICOMMENT {
    EMR emr;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRGDICOMMENT,*PEMRGDICOMMENT;

  تعريفنوع بنية نښان_EMREOF {
    EMR emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD n_اندازه_وروستی;
  } EMREOF,*PEMREOF;

  تعريفنوع بنية نښان_EMRLINETO {
    EMR emr;
    POINTL ptl;
  } EMRLINETO,*PEMRLINETO,EMRMOVETOEX,*PEMRMOVETOEX;

  تعريفنوع بنية نښان_EMROFFSETCLIPRGN {
    EMR emr;
    POINTL ptl_دننه_واټن;
  } EMROFFSETCLIPRGN,*PEMROFFSETCLIPRGN;

  تعريفنوع بنية نښان_EMRFILLPATH {
    EMR emr;
    RECTL rclBounds;
  } EMRFILLPATH,*PEMRFILLPATH,EMRSTROKEANDFILLPATH,*PEMRSTROKEANDFILLPATH,EMRSTROKEPATH,*PEMRSTROKEPATH;

  تعريفنوع بنية نښان_EMREXCLUDECLIPRECT {
    EMR emr;
    RECTL rclClip;
  } EMREXCLUDECLIPRECT,*PEMREXCLUDECLIPRECT,EMRINTERSECTCLIPRECT,*PEMRINTERSECTCLIPRECT;

  تعريفنوع بنية نښان_EMRSETVIEWPORTORGEX {
    EMR emr;
    POINTL ptlOrigin;
  } EMRSETVIEWPORTORGEX,*PEMRSETVIEWPORTORGEX,EMRSETWINDOWORGEX,*PEMRSETWINDOWORGEX,EMRSETBRUSHORGEX,*PEMRSETBRUSHORGEX;

  تعريفنوع بنية نښان_EMRSETVIEWPORTEXTEX {
    EMR emr;
    SIZEL szlExtent;
  } EMRSETVIEWPORTEXTEX,*PEMRSETVIEWPORTEXTEX,EMRSETWINDOWEXTEX,*PEMRSETWINDOWEXTEX;

  تعريفنوع بنية نښان_EMRSCALEVIEWPORTEXTEX {
    EMR emr;
    LONG x_عدد;
    LONG xDenom;
    LONG y_عدد;
    LONG yDenom;
  } EMRSCALEVIEWPORTEXTEX,*PEMRSCALEVIEWPORTEXTEX,EMRSCALEWINDOWEXTEX,*PEMRSCALEWINDOWEXTEX;

  تعريفنوع بنية نښان_EMRSETWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
  } EMRSETWORLDTRANSFORM,*PEMRSETWORLDTRANSFORM;

  تعريفنوع بنية نښان_EMRMODIFYWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
    DWORD i_ډېرپېښ;
  } EMRMODIFYWORLDTRANSFORM,*PEMRMODIFYWORLDTRANSFORM;

  تعريفنوع بنية نښان_EMRSETPIXELV {
    EMR emr;
    POINTL ptlPixel;
    COLORREF crColor;
  } EMRSETPIXELV,*PEMRSETPIXELV;

  تعريفنوع بنية نښان_EMREXTFLOODFILL {
    EMR emr;
    POINTL ptl_پیل;
    COLORREF crColor;
    DWORD i_ډېرپېښ;
  } EMREXTFLOODFILL,*PEMREXTFLOODFILL;

  تعريفنوع بنية نښان_EMRELLIPSE {
    EMR emr;
    RECTL rclBox;
  } EMRELLIPSE,*PEMRELLIPSE,EMRRECTANGLE,*PEMRRECTANGLE;

  تعريفنوع بنية نښان_EMRROUNDRECT {
    EMR emr;
    RECTL rclBox;
    SIZEL szl_کونج;
  } EMRROUNDRECT,*PEMRROUNDRECT;

  تعريفنوع بنية نښان_EMRARC {
    EMR emr;
    RECTL rclBox;
    POINTL ptl_پیل;
    POINTL ptl_پای_ټکی;
  } EMRARC,*PEMRARC,EMRARCTO,*PEMRARCTO,EMRCHORD,*PEMRCHORD,EMRPIE,*PEMRPIE;

  تعريفنوع بنية نښان_EMRANGLEARC {
    EMR emr;
    POINTL ptlCenter;
    DWORD nRadius;
    FLOAT e_پیل_Angle;
    FLOAT eSweepAngle;
  } EMRANGLEARC,*PEMRANGLEARC;

  تعريفنوع بنية نښان_EMRPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
  } EMRPOLYLINE,*PEMRPOLYLINE,EMRPOLYBEZIER,*PEMRPOLYBEZIER,EMRPOLYGON,*PEMRPOLYGON,EMRPOLYBEZIERTO,*PEMRPOLYBEZIERTO,EMRPOLYLINETO,*PEMRPOLYLINETO;

  تعريفنوع بنية نښان_EMRPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
  } EMRPOLYLINE16,*PEMRPOLYLINE16,EMRPOLYBEZIER16,*PEMRPOLYBEZIER16,EMRPOLYGON16,*PEMRPOLYGON16,EMRPOLYBEZIERTO16,*PEMRPOLYBEZIERTO16,EMRPOLYLINETO16,*PEMRPOLYLINETO16;

  تعريفنوع بنية نښان_EMRPOLYDRAW {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW,*PEMRPOLYDRAW;

  تعريفنوع بنية نښان_EMRPOLYDRAW16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW16,*PEMRPOLYDRAW16;

  تعريفنوع بنية نښان_EMRPOLYPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cptl;
    DWORD aPolyCounts[1];
    POINTL aptl[1];
  } EMRPOLYPOLYLINE,*PEMRPOLYPOLYLINE,EMRPOLYPOLYGON,*PEMRPOLYPOLYGON;

  تعريفنوع بنية نښان_EMRPOLYPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cpts;
    DWORD aPolyCounts[1];
    POINTS apts[1];
  } EMRPOLYPOLYLINE16,*PEMRPOLYPOLYLINE16,EMRPOLYPOLYGON16,*PEMRPOLYPOLYGON16;

  تعريفنوع بنية نښان_EMRINVERTRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_معلومات;
    BYTE Rgn_معلومات[1];
  } EMRINVERTRGN,*PEMRINVERTRGN,EMRPAINTRGN,*PEMRPAINTRGN;

  تعريفنوع بنية نښان_EMRFILLRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_معلومات;
    DWORD ihBrush;
    BYTE Rgn_معلومات[1];
  } EMRFILLRGN,*PEMRFILLRGN;

  تعريفنوع بنية نښان_EMRFRAMERGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_معلومات;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE Rgn_معلومات[1];
  } EMRFRAMERGN,*PEMRFRAMERGN;

  تعريفنوع بنية نښان_EMREXTSELECTCLIPRGN {
    EMR emr;
    DWORD cb_Rgn_معلومات;
    DWORD i_ډېرپېښ;
    BYTE Rgn_معلومات[1];
  } EMREXTSELECTCLIPRGN,*PEMREXTSELECTCLIPRGN;

  تعريفنوع بنية نښان_EMREXTTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_ډېرپېښ;
    FLOAT exScale;
    FLOAT eyScale;
    EMRTEXT emrtext;
  } EMREXTTEXTOUTA,*PEMREXTTEXTOUTA,EMREXTTEXTOUTW,*PEMREXTTEXTOUTW;

  تعريفنوع بنية نښان_EMRPOLYTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_ډېرپېښ;
    FLOAT exScale;
    FLOAT eyScale;
    LONG c_مزي_ګانې;
    EMRTEXT aemrtext[1];
  } EMRPOLYTEXTOUTA,*PEMRPOLYTEXTOUTA,EMRPOLYTEXTOUTW,*PEMRPOLYTEXTOUTW;

  تعريفنوع بنية نښان_EMRBITBLT {
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD off_بټونه_Src;
    DWORD cb_بټونه_Src;
  } EMRBITBLT,*PEMRBITBLT;

  تعريفنوع بنية نښان_EMRSTRETCHBLT {
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD off_بټونه_Src;
    DWORD cb_بټونه_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRSTRETCHBLT,*PEMRSTRETCHBLT;

  تعريفنوع بنية نښان_EMRMASKBLT {
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD off_بټونه_Src;
    DWORD cb_بټونه_Src;
    LONG x_ماسک;
    LONG y_ماسک;
    DWORD i_Usage_ماسک;
    DWORD off_Bmi_ماسک;
    DWORD cb_Bmi_ماسک;
    DWORD off_بټونه_ماسک;
    DWORD cb_بټونه_ماسک;
  } EMRMASKBLT,*PEMRMASKBLT;

  تعريفنوع بنية نښان_EMRPLGBLT {
    EMR emr;
    RECTL rclBounds;
    POINTL aptlDest[3];
    LONG xSrc;
    LONG ySrc;
    LONG cxSrc;
    LONG cySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD off_بټونه_Src;
    DWORD cb_بټونه_Src;
    LONG x_ماسک;
    LONG y_ماسک;
    DWORD i_Usage_ماسک;
    DWORD off_Bmi_ماسک;
    DWORD cb_Bmi_ماسک;
    DWORD off_بټونه_ماسک;
    DWORD cb_بټونه_ماسک;
  } EMRPLGBLT,*PEMRPLGBLT;

  تعريفنوع بنية نښان_EMRSETDIBITSTODEVICE {
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG xSrc;
    LONG ySrc;
    LONG cxSrc;
    LONG cySrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD off_بټونه_Src;
    DWORD cb_بټونه_Src;
    DWORD iUsageSrc;
    DWORD i_پیل_لټون;
    DWORD cScans;
  } EMRSETDIBITSTODEVICE,*PEMRSETDIBITSTODEVICE;

  تعريفنوع بنية نښان_EMRSTRETCHDIBITS {
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG xSrc;
    LONG ySrc;
    LONG cxSrc;
    LONG cySrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD off_بټونه_Src;
    DWORD cb_بټونه_Src;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG cxDest;
    LONG cyDest;
  } EMRSTRETCHDIBITS,*PEMRSTRETCHDIBITS;

  تعريفنوع بنية نښان_EMREXTCREATEFONTINDIRECTW {
    EMR emr;
    DWORD ihFont;
    EXTLOGFONTW elfw;
  } EMREXTCREATEFONTINDIRECTW,*PEMREXTCREATEFONTINDIRECTW;

  تعريفنوع بنية نښان_EMRCREATEPALETTE {
    EMR emr;
    DWORD ihPal;
    LOGPALETTE lgpl;
  } EMRCREATEPALETTE,*PEMRCREATEPALETTE;

  تعريفنوع بنية نښان_EMRCREATEPEN {
    EMR emr;
    DWORD ihPen;
    LOGPEN lopn;
  } EMRCREATEPEN,*PEMRCREATEPEN;

  تعريفنوع بنية نښان_EMREXTCREATEPEN {
    EMR emr;
    DWORD ihPen;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بټونه;
    DWORD cb_بټونه;
    EXTLOGPEN elp;
  } EMREXTCREATEPEN,*PEMREXTCREATEPEN;

  تعريفنوع بنية نښان_EMRCREATEBRUSHINDIRECT {
    EMR emr;
    DWORD ihBrush;
    LOGBRUSH32 lb;
  } EMRCREATEBRUSHINDIRECT,*PEMRCREATEBRUSHINDIRECT;

  تعريفنوع بنية نښان_EMRCREATEMONOBRUSH {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بټونه;
    DWORD cb_بټونه;
  } EMRCREATEMONOBRUSH,*PEMRCREATEMONOBRUSH;

  تعريفنوع بنية نښان_EMRCREATEDIBPATTERNBRUSHPT {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بټونه;
    DWORD cb_بټونه;
  } EMRCREATEDIBPATTERNBRUSHPT,*PEMRCREATEDIBPATTERNBRUSHPT;

  تعريفنوع بنية نښان_EMRFORMAT {
    DWORD dSignature;
    DWORD n_نسخه;
    DWORD cb_معلومات;
    DWORD off_معلومات;
  } EMRFORMAT,*PEMRFORMAT;

  تعريفنوع بنية نښان_EMRGLSRECORD {
    EMR emr;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRGLSRECORD,*PEMRGLSRECORD;

  تعريفنوع بنية نښان_EMRGLSBOUNDEDRECORD {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRGLSBOUNDEDRECORD,*PEMRGLSBOUNDEDRECORD;

  تعريفنوع بنية نښان_EMRPIXELFORMAT {
    EMR emr;
    PIXELFORMATDESCRIPTOR pfd;
  } EMRPIXELFORMAT,*PEMRPIXELFORMAT;

  تعريفنوع بنية نښان_EMRCREATECOLORSPACE {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEA lcs;
  } EMRCREATECOLORSPACE,*PEMRCREATECOLORSPACE;

  تعريفنوع بنية نښان_EMRSETCOLORSPACE {
    EMR emr;
    DWORD ihCS;
  } EMRSETCOLORSPACE,*PEMRSETCOLORSPACE,EMRSELECTCOLORSPACE,*PEMRSELECTCOLORSPACE,EMRDELETECOLORSPACE,*PEMRDELETECOLORSPACE;

  تعريفنوع بنية نښان_EMREXTESCAPE {
    EMR emr;
    INT iEscape;
    INT cb_Esc_معلومات;
    BYTE Esc_معلومات[1];
  } EMREXTESCAPE,*PEMREXTESCAPE,EMRDRAWESCAPE,*PEMRDRAWESCAPE;

  تعريفنوع بنية نښان_EMRNAMEDESCAPE {
    EMR emr;
    INT iEscape;
    INT cbDriver;
    INT cb_Esc_معلومات;
    BYTE Esc_معلومات[1];
  } EMRNAMEDESCAPE,*PEMRNAMEDESCAPE;

#تعریف_کړه SETICMPROFILE_EMBEDED 0x00000001

  تعريفنوع بنية نښان_EMRSETICMPROFILE {
    EMR emr;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRSETICMPROFILE,*PEMRSETICMPROFILE,EMRSETICMPROFILEA,*PEMRSETICMPROFILEA,EMRSETICMPROFILEW,*PEMRSETICMPROFILEW;

#تعریف_کړه CREATECOLORSPACE_EMBEDED 0x00000001

  تعريفنوع بنية نښان_EMRCREATECOLORSPACEW {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEW lcs;
    DWORD dwFlags;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRCREATECOLORSPACEW,*PEMRCREATECOLORSPACEW;

#تعریف_کړه COLORMATCHTOTARGET_EMBEDED 0x00000001

  تعريفنوع بنية نښان_COLORMATCHTOTARGET {
    EMR emr;
    DWORD dwAction;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRCOLORMATCHTOTARGET,*PEMRCOLORMATCHTOTARGET;

  تعريفنوع بنية نښان_COLORCORRECTPALETTE {
    EMR emr;
    DWORD ihPalette;
    DWORD n_لومړی_ثبت;
    DWORD nPalEntries;
    DWORD nReserved;
  } EMRCOLORCORRECTPALETTE,*PEMRCOLORCORRECTPALETTE;

  تعريفنوع بنية نښان_EMRALPHABLEND {
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD off_بټونه_Src;
    DWORD cb_بټونه_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRALPHABLEND,*PEMRALPHABLEND;

  تعريفنوع بنية نښان_EMRGRADIENTFILL {
    EMR emr;
    RECTL rclBounds;
    DWORD nVer;
    DWORD nTri;
    ULONG ul_ډېرپېښ;
    TRIVERTEX Ver[1];
  } EMRGRADIENTFILL,*PEMRGRADIENTFILL;

  تعريفنوع بنية نښان_EMRTRANSPARENTBLT {
    EMR emr;
    RECTL rclBounds;
    LONG xDest;
    LONG yDest;
    LONG cxDest;
    LONG cyDest;
    DWORD dwRop;
    LONG xSrc;
    LONG ySrc;
    XFORM xformSrc;
    COLORREF crBkColorSrc;
    DWORD iUsageSrc;
    DWORD offBmiSrc;
    DWORD cbBmiSrc;
    DWORD off_بټونه_Src;
    DWORD cb_بټونه_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRTRANSPARENTBLT,*PEMRTRANSPARENTBLT;

#تعریف_کړه GDICOMMENT_IDENTIFIER 0x43494447
#تعریف_کړه GDICOMMENT_WINDOWS_METAFILE 0x80000001
#تعریف_کړه GDICOMMENT_BEGINGROUP 0x00000002
#تعریف_کړه GDICOMMENT_ENDGROUP 0x00000003
#تعریف_کړه GDICOMMENT_MULTIFORMATS 0x40000004
#تعریف_کړه EPS_SIGNATURE 0x46535045
#تعریف_کړه GDICOMMENT_UNICODE_STRING 0x00000040
#تعریف_کړه GDICOMMENT_UNICODE_پای_ټکی 0x00000080
#د_که_پای

#که_تعریف_شوی UNICODE
#تعریف_کړه wglUseFontBitmaps wglUseFontBitmapsW
#وإلا
#تعریف_کړه wglUseFontBitmaps wglUseFontBitmapsA
#د_که_پای

  WINGDIAPI WINBOOL WINAPI wglCopyContext(HGLRC,HGLRC,UINT);
  WINGDIAPI HGLRC WINAPI wglCreateContext(HDC);
  WINGDIAPI HGLRC WINAPI wglCreateLayerContext(HDC,صحيح);
  WINGDIAPI WINBOOL WINAPI wglDeleteContext(HGLRC);
  WINGDIAPI HGLRC WINAPI wglGetCurrentContext(VOID);
  WINGDIAPI HDC WINAPI wglGetCurrentDC(VOID);
  WINGDIAPI PROC WINAPI wgl_Get_Proc_پته(LPCSTR);
  WINGDIAPI WINBOOL WINAPI wglMakeCurrent(HDC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglShareLists(HGLRC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsA(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsW(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI بدلون_Buffers(HDC);

  تعريفنوع بنية _POINTFLOAT {
    FLOAT x;
    FLOAT y;
  } POINTFLOAT,*PPOINTFLOAT;

  تعريفنوع بنية _GLYPHMETRICSFLOAT {
    FLOAT gmfBlackBoxX;
    FLOAT gmfBlackBoxY;
    POINTFLOAT gmfptGlyphOrigin;
    FLOAT gmfCellIncX;
    FLOAT gmfCellIncY;
  } GLYPHMETRICSFLOAT,*PGLYPHMETRICSFLOAT,*LPGLYPHMETRICSFLOAT;

#تعریف_کړه WGL_FONT_کرښې 0
#تعریف_کړه WGL_FONT_POLYGONS 1

#که_تعریف_شوی UNICODE
#تعریف_کړه wglUseFontOutlines wglUseFontOutlinesW
#وإلا
#تعریف_کړه wglUseFontOutlines wglUseFontOutlinesA
#د_که_پای

  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesA(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,صحيح,LPGLYPHMETRICSFLOAT);
  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesW(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,صحيح,LPGLYPHMETRICSFLOAT);

  تعريفنوع بنية نښان_LAYERPLANEDESCRIPTOR {
    کلمه_3 n_اندازه;
    کلمه_3 n_نسخه;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_بټونه;
    BYTE c_Red_بټونه;
    BYTE c_Red_ښويدنه;
    BYTE c_Green_بټونه;
    BYTE c_Green_ښويدنه;
    BYTE c_Blue_بټونه;
    BYTE c_Blue_ښويدنه;
    BYTE c_Alpha_بټونه;
    BYTE c_Alpha_ښويدنه;
    BYTE c_Accum_بټونه;
    BYTE c_Accum_Red_بټونه;
    BYTE c_Accum_Green_بټونه;
    BYTE c_Accum_Blue_بټونه;
    BYTE c_Accum_Alpha_بټونه;
    BYTE c_ژوروالی_بټونه;
    BYTE c_Stencil_بټونه;
    BYTE cAuxBuffers;
    BYTE iLayerPlane;
    BYTE bReserved;
    COLORREF crTransparent;
  } LAYERPLANEDESCRIPTOR,*PLAYERPLANEDESCRIPTOR,*LPLAYERPLANEDESCRIPTOR;

#تعریف_کړه LPD_DOUBLEBUFFER 0x00000001
#تعریف_کړه LPD_STEREO 0x00000002
#تعریف_کړه LPD_SUPPORT_GDI 0x00000010
#تعریف_کړه LPD_SUPPORT_OPENGL 0x00000020
#تعریف_کړه LPD_SHARE_ژوروالی 0x00000040
#تعریف_کړه LPD_SHARE_STENCIL 0x00000080
#تعریف_کړه LPD_SHARE_ACCUM 0x00000100
#تعریف_کړه LPD_بدلون_EXCHANGE 0x00000200
#تعریف_کړه LPD_بدلون_COPY 0x00000400
#تعریف_کړه LPD_TRANSPARENT 0x00001000

#تعریف_کړه LPD_TYPE_RGBA 0
#تعریف_کړه LPD_TYPE_COLORINDEX 1

#تعریف_کړه WGL_بدلون_MAIN_PLANE 0x00000001
#تعریف_کړه WGL_بدلون_OVERLAY1 0x00000002
#تعریف_کړه WGL_بدلون_OVERLAY2 0x00000004
#تعریف_کړه WGL_بدلون_OVERLAY3 0x00000008
#تعریف_کړه WGL_بدلون_OVERLAY4 0x00000010
#تعریف_کړه WGL_بدلون_OVERLAY5 0x00000020
#تعریف_کړه WGL_بدلون_OVERLAY6 0x00000040
#تعریف_کړه WGL_بدلون_OVERLAY7 0x00000080
#تعریف_کړه WGL_بدلون_OVERLAY8 0x00000100
#تعریف_کړه WGL_بدلون_OVERLAY9 0x00000200
#تعریف_کړه WGL_بدلون_OVERLAY10 0x00000400
#تعریف_کړه WGL_بدلون_OVERLAY11 0x00000800
#تعریف_کړه WGL_بدلون_OVERLAY12 0x00001000
#تعریف_کړه WGL_بدلون_OVERLAY13 0x00002000
#تعریف_کړه WGL_بدلون_OVERLAY14 0x00004000
#تعریف_کړه WGL_بدلون_OVERLAY15 0x00008000
#تعریف_کړه WGL_بدلون_UNDERLAY1 0x00010000
#تعریف_کړه WGL_بدلون_UNDERLAY2 0x00020000
#تعریف_کړه WGL_بدلون_UNDERLAY3 0x00040000
#تعریف_کړه WGL_بدلون_UNDERLAY4 0x00080000
#تعریف_کړه WGL_بدلون_UNDERLAY5 0x00100000
#تعریف_کړه WGL_بدلون_UNDERLAY6 0x00200000
#تعریف_کړه WGL_بدلون_UNDERLAY7 0x00400000
#تعریف_کړه WGL_بدلون_UNDERLAY8 0x00800000
#تعریف_کړه WGL_بدلون_UNDERLAY9 0x01000000
#تعریف_کړه WGL_بدلون_UNDERLAY10 0x02000000
#تعریف_کړه WGL_بدلون_UNDERLAY11 0x04000000
#تعریف_کړه WGL_بدلون_UNDERLAY12 0x08000000
#تعریف_کړه WGL_بدلون_UNDERLAY13 0x10000000
#تعریف_کړه WGL_بدلون_UNDERLAY14 0x20000000
#تعریف_کړه WGL_بدلون_UNDERLAY15 0x40000000

  WINGDIAPI WINBOOL WINAPI wglDescribeLayerPlane(HDC,صحيح,صحيح,UINT,LPLAYERPLANEDESCRIPTOR);
  WINGDIAPI صحيح WINAPI wgl_سېټ_Layer_Palette_Entries(HDC,صحيح,صحيح,صحيح,CONST COLORREF *);
  WINGDIAPI صحيح WINAPI wglGetLayerPaletteEntries(HDC,صحيح,صحيح,صحيح,COLORREF *);
  WINGDIAPI WINBOOL WINAPI wglRealizeLayerPalette(HDC,صحيح,WINBOOL);
  WINGDIAPI WINBOOL WINAPI wgl_بدلون_Layer_Buffers(HDC,UINT);

  تعريفنوع بنية _WGLSWAP {
    HDC hdc;
    UINT uiFlags;
  } WGLSWAP,*PWGLSWAP,*LPWGLSWAP;

#تعریف_کړه WGL_SWAPMULTIPLE_MAX 16

  WINGDIAPI DWORD WINAPI wgl_بدلون_مضرب_Buffers(UINT,CONST WGLSWAP *);
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
