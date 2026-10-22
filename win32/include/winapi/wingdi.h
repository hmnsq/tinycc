/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جے_بنا_تعریف _WINGDI_
#تعریف_کرو _WINGDI_

#تعریف_کرو WINGDIAPI DECLSPEC_IMPORT
#تعریف_کرو WINSPOOLAPI DECLSPEC_IMPORT

#جے_تعریف_شدہ __cplusplus
خارجي "C" {
#جے_انت

#جے_بنا_تعریف WINVER
#تعریف_کرو WINVER 0x0502
#جے_انت

#جے_بنا_تعریف NOGDI
#جے_بنا_تعریف NORASTEROPS
#تعریف_کرو R2_BLACK 1
#تعریف_کرو R2_NOTMERGEPEN 2
#تعریف_کرو R2_MASKNOTPEN 3
#تعریف_کرو R2_NOTCOPYPEN 4
#تعریف_کرو R2_MASKPENNOT 5
#تعریف_کرو R2_NOT 6
#تعریف_کرو R2_XORPEN 7
#تعریف_کرو R2_NOTMASKPEN 8
#تعریف_کرو R2_MASKPEN 9
#تعریف_کرو R2_NOTXORPEN 10
#تعریف_کرو R2_NOP 11
#تعریف_کرو R2_MERGENOTPEN 12
#تعریف_کرو R2_COPYPEN 13
#تعریف_کرو R2_MERGEPENNOT 14
#تعریف_کرو R2_MERGEPEN 15
#تعریف_کرو R2_WHITE 16
#تعریف_کرو R2_آخری 16

#تعریف_کرو SRCCOPY (DWORD)0x00CC0020
#تعریف_کرو SRCPAINT (DWORD)0x00EE0086
#تعریف_کرو SRCAND (DWORD)0x008800C6
#تعریف_کرو SRCINVERT (DWORD)0x00660046
#تعریف_کرو SRCERASE (DWORD)0x00440328
#تعریف_کرو NOTSRCCOPY (DWORD)0x00330008
#تعریف_کرو NOTSRCERASE (DWORD)0x001100A6
#تعریف_کرو MERGECOPY (DWORD)0x00C000CA
#تعریف_کرو MERGEPAINT (DWORD)0x00BB0226
#تعریف_کرو PATCOPY (DWORD)0x00F00021
#تعریف_کرو PATPAINT (DWORD)0x00FB0A09
#تعریف_کرو PATINVERT (DWORD)0x005A0049
#تعریف_کرو DSTINVERT (DWORD)0x00550009
#تعریف_کرو BLACKNESS (DWORD)0x00000042
#تعریف_کرو WHITENESS (DWORD)0x00FF0062
#تعریف_کرو NOMIRRORBITMAP (DWORD)0x80000000
#تعریف_کرو CAPTUREBLT (DWORD)0x40000000
#تعریف_کرو MAKEROP4(fore,پٹھ) (DWORD)((((پٹھ) << 8) & 0xFF000000) | (fore))
#جے_انت

#تعریف_کرو GDI_ERROR (0xFFFFFFFFL)
#تعریف_کرو HGDI_ERROR (Long_منزل_Handle(0xFFFFFFFFL))

#تعریف_کرو ERROR 0
#تعریف_کرو NULLREGION 1
#تعریف_کرو SIMPLEREGION 2
#تعریف_کرو COMPLEXREGION 3
#تعریف_کرو RGN_ERROR ERROR

#تعریف_کرو RGN_AND 1
#تعریف_کرو RGN_OR 2
#تعریف_کرو RGN_XOR 3
#تعریف_کرو RGN_DIFF 4
#تعریف_کرو RGN_COPY 5
#تعریف_کرو RGN_MIN RGN_AND
#تعریف_کرو RGN_MAX RGN_COPY

#تعریف_کرو BLACKONWHITE 1
#تعریف_کرو WHITEONBLACK 2
#تعریف_کرو COLORONCOLOR 3
#تعریف_کرو HALFTONE 4
#تعریف_کرو MAXSTRETCHBLTMODE 4

#تعریف_کرو STRETCH_ANDSCANS BLACKONWHITE
#تعریف_کرو STRETCH_ORSCANS WHITEONBLACK
#تعریف_کرو STRETCH_DELETESCANS COLORONCOLOR
#تعریف_کرو STRETCH_HALFTONE HALFTONE

#تعریف_کرو ALTERNATE 1
#تعریف_کرو WINDING 2
#تعریف_کرو POLYFILL_آخری 2

#تعریف_کرو LAYOUT_RTL 0x00000001
#تعریف_کرو LAYOUT_BTT 0x00000002
#تعریف_کرو LAYOUT_VBH 0x00000004
#تعریف_کرو LAYOUT_ORIENTATIONMASK (LAYOUT_RTL | LAYOUT_BTT | LAYOUT_VBH)
#تعریف_کرو LAYOUT_BITMAPORIENTATIONPRESERVED 0x00000008

#تعریف_کرو TA_NOUPDATECP 0
#تعریف_کرو TA_UPDATECP 1

#تعریف_کرو TA_بایاں 0
#تعریف_کرو TA_دایاں 2
#تعریف_کرو TA_CENTER 6

#تعریف_کرو TA_چوٹی 0
#تعریف_کرو TA_BOTTOM 8
#تعریف_کرو TA_BASELINE 24
#تعریف_کرو TA_RTLREADING 256
#تعریف_کرو TA_نقاب (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)

#تعریف_کرو VTA_BASELINE TA_BASELINE
#تعریف_کرو VTA_بایاں TA_BOTTOM
#تعریف_کرو VTA_دایاں TA_چوٹی
#تعریف_کرو VTA_CENTER TA_CENTER
#تعریف_کرو VTA_BOTTOM TA_دایاں
#تعریف_کرو VTA_چوٹی TA_بایاں

#تعریف_کرو ETO_OPAQUE 0x0002
#تعریف_کرو ETO_CLIPPED 0x0004
#تعریف_کرو ETO_GLYPH_اشاریہ 0x0010
#تعریف_کرو ETO_RTLREADING 0x0080
#تعریف_کرو ETO_NUMERICSLOCAL 0x0400
#تعریف_کرو ETO_NUMERICSLATIN 0x0800
#تعریف_کرو ETO_IGNORELANGUAGE 0x1000
#تعریف_کرو ETO_PDY 0x2000

#تعریف_کرو ASPECT_FILTERING 0x0001

#تعریف_کرو DCB_RESET 0x0001
#تعریف_کرو DCB_ACCUMULATE 0x0002
#تعریف_کرو DCB_DIRTY DCB_ACCUMULATE
#تعریف_کرو DCB_سیٹ (DCB_RESET | DCB_ACCUMULATE)
#تعریف_کرو DCB_ENABLE 0x0004
#تعریف_کرو DCB_DISABLE 0x0008

#جے_بنا_تعریف NOMETAFILE

#تعریف_کرو META_SETBKCOLOR 0x0201
#تعریف_کرو META_SETBKMODE 0x0102
#تعریف_کرو META_SETMAPMODE 0x0103
#تعریف_کرو META_SETROP2 0x0104
#تعریف_کرو META_SETRELABS 0x0105
#تعریف_کرو META_SETPOLYFILLMODE 0x0106
#تعریف_کرو META_SETSTRETCHBLTMODE 0x0107
#تعریف_کرو META_SETTEXTCHAREXTRA 0x0108
#تعریف_کرو META_SETTEXTCOLOR 0x0209
#تعریف_کرو META_SETTEXTJUSTIFICATION 0x020A
#تعریف_کرو META_SETWINDOWORG 0x020B
#تعریف_کرو META_SETWINDOWEXT 0x020C
#تعریف_کرو META_SETVIEWPORTORG 0x020D
#تعریف_کرو META_SETVIEWPORTEXT 0x020E
#تعریف_کرو META_OFFSETWINDOWORG 0x020F
#تعریف_کرو META_SCALEWINDOWEXT 0x0410
#تعریف_کرو META_OFFSETVIEWPORTORG 0x0211
#تعریف_کرو META_SCALEVIEWPORTEXT 0x0412
#تعریف_کرو META_LINETO 0x0213
#تعریف_کرو META_MOVETO 0x0214
#تعریف_کرو META_EXCLUDECLIPRECT 0x0415
#تعریف_کرو META_INTERSECTCLIPRECT 0x0416
#تعریف_کرو META_ARC 0x0817
#تعریف_کرو META_ELLIPSE 0x0418
#تعریف_کرو META_FLOODFILL 0x0419
#تعریف_کرو META_PIE 0x081A
#تعریف_کرو META_RECTANGLE 0x041B
#تعریف_کرو META_ROUNDRECT 0x061C
#تعریف_کرو META_PATBLT 0x061D
#تعریف_کرو META_SAVEDC 0x001E
#تعریف_کرو META_SETPIXEL 0x041F
#تعریف_کرو META_OFFSETCLIPRGN 0x0220
#تعریف_کرو META_TEXTOUT 0x0521
#تعریف_کرو META_BITBLT 0x0922
#تعریف_کرو META_STRETCHBLT 0x0B23
#تعریف_کرو META_POLYGON 0x0324
#تعریف_کرو META_POLYLINE 0x0325
#تعریف_کرو META_ESCAPE 0x0626
#تعریف_کرو META_RESTOREDC 0x0127
#تعریف_کرو META_FILLREGION 0x0228
#تعریف_کرو META_FRAMEREGION 0x0429
#تعریف_کرو META_INVERTREGION 0x012A
#تعریف_کرو META_PAINTREGION 0x012B
#تعریف_کرو META_SELECTCLIPREGION 0x012C
#تعریف_کرو META_SELECTOBJECT 0x012D
#تعریف_کرو META_SETTEXTALIGN 0x012E
#تعریف_کرو META_CHORD 0x0830
#تعریف_کرو META_SETMAPPERFLAGS 0x0231
#تعریف_کرو META_EXTTEXTOUT 0x0a32
#تعریف_کرو META_SETDIBTODEV 0x0d33
#تعریف_کرو META_SELECTPALETTE 0x0234
#تعریف_کرو META_REALIZEPALETTE 0x0035
#تعریف_کرو META_ANIMATEPALETTE 0x0436
#تعریف_کرو META_SETPALENTRIES 0x0037
#تعریف_کرو META_POLYPOLYGON 0x0538
#تعریف_کرو META_RESIZEPALETTE 0x0139
#تعریف_کرو META_DIBBITBLT 0x0940
#تعریف_کرو META_DIBSTRETCHBLT 0x0b41
#تعریف_کرو META_DIBCREATEPATTERNBRUSH 0x0142
#تعریف_کرو META_STRETCHDIB 0x0f43
#تعریف_کرو META_EXTFLOODFILL 0x0548
#تعریف_کرو META_SETLAYOUT 0x0149
#تعریف_کرو META_DELETEOBJECT 0x01f0
#تعریف_کرو META_CREATEPALETTE 0x00f7
#تعریف_کرو META_CREATEPATTERNBRUSH 0x01F9
#تعریف_کرو META_CREATEPENINDIRECT 0x02FA
#تعریف_کرو META_CREATEFONTINDIRECT 0x02FB
#تعریف_کرو META_CREATEBRUSHINDIRECT 0x02FC
#تعریف_کرو META_CREATEREGION 0x06FF

  تعريفنوع بنية _DRAWPATRECT {
    نقطہ_3 ptPosition;
    نقطہ_3 pt_ناپ;
    لفظ_3 wStyle;
    لفظ_3 w_نمونہ;
  } DRAWPATRECT,*PDRAWPATRECT;
#جے_انت

#تعریف_کرو NEWFRAME 1
#تعریف_کرو ABORTDOC 2
#تعریف_کرو NEXTBAND 3
#تعریف_کرو SETCOLORTABLE 4
#تعریف_کرو GETCOLORTABLE 5
#تعریف_کرو FLUSHOUTPUT 6
#تعریف_کرو DRAFTMODE 7
#تعریف_کرو QUERYESCSUPPORT 8
#تعریف_کرو SETABORTPROC 9
#تعریف_کرو STARTDOC 10
#تعریف_کرو ENDDOC 11
#تعریف_کرو GETPHYSPAGESIZE 12
#تعریف_کرو GETPRINTINGOFFSET 13
#تعریف_کرو GETSCALINGFACTOR 14
#تعریف_کرو MFCOMMENT 15
#تعریف_کرو GETPENWIDTH 16
#تعریف_کرو SETCOPYCOUNT 17
#تعریف_کرو SELECTPAPERSOURCE 18
#تعریف_کرو DEVICEDATA 19
#تعریف_کرو PASSTHROUGH 19
#تعریف_کرو GETTECHNOLGY 20
#تعریف_کرو GETTECHNOLOGY 20
#تعریف_کرو SETLINECAP 21
#تعریف_کرو SETLINEJOIN 22
#تعریف_کرو SETMITERLIMIT 23
#تعریف_کرو BANDINFO 24
#تعریف_کرو DRAWPATTERNRECT 25
#تعریف_کرو GETVECTORPENSIZE 26
#تعریف_کرو GETVECTORBRUSHSIZE 27
#تعریف_کرو ENABLEDUPLEX 28
#تعریف_کرو GETSETPAPERBINS 29
#تعریف_کرو GETSETPRINTORIENT 30
#تعریف_کرو ENUMPAPERBINS 31
#تعریف_کرو SETDIBSCALING 32
#تعریف_کرو EPSPRINTING 33
#تعریف_کرو ENUMPAPERMETRICS 34
#تعریف_کرو GETSETPAPERMETRICS 35
#تعریف_کرو POSTSCRIPT_انکڑے 37
#تعریف_کرو POSTSCRIPT_IGNORE 38
#تعریف_کرو MOUSETRAILS 39
#تعریف_کرو GETDEVICEUNITS 42

#تعریف_کرو GETEXTENDEDTEXTMETRICS 256
#تعریف_کرو GETEXTENTTABLE 257
#تعریف_کرو GETPAIRKERNTABLE 258
#تعریف_کرو GETTRACKKERNTABLE 259
#تعریف_کرو EXTTEXTOUT 512
#تعریف_کرو GETFACENAME 513
#تعریف_کرو DOWNLOADFACE 514
#تعریف_کرو ENABLERELATIVEWIDTHS 768
#تعریف_کرو ENABLEPAIRKERNING 769
#تعریف_کرو SETKERNTRACK 770
#تعریف_کرو SETALLJUSTVALUES 771
#تعریف_کرو SETCHARSET 772

#تعریف_کرو STRETCHBLT 2048
#تعریف_کرو METAFILE_DRIVER 2049
#تعریف_کرو GETSETSCREENPARAMS 3072
#تعریف_کرو QUERYDIBSUPPORT 3073
#تعریف_کرو BEGIN_رستہ 4096
#تعریف_کرو CLIP_منزل_رستہ 4097
#تعریف_کرو سرا_رستہ 4098
#تعریف_کرو EXT_DEVICE_CAPS 4099
#تعریف_کرو RESTORE_CTM 4100
#تعریف_کرو SAVE_CTM 4101
#تعریف_کرو سیٹ_ARC_DIRECTION 4102
#تعریف_کرو سیٹ_BACKGROUND_COLOR 4103
#تعریف_کرو سیٹ_POLY_منوال 4104
#تعریف_کرو سیٹ_SCREEN_ANGLE 4105
#تعریف_کرو سیٹ_پھیلاؤ 4106
#تعریف_کرو TRANSFORM_CTM 4107
#تعریف_کرو سیٹ_CLIP_BOX 4108
#تعریف_کرو سیٹ_BOUNDS 4109
#تعریف_کرو سیٹ_MIRROR_منوال 4110
#تعریف_کرو OPENCHANNEL 4110
#تعریف_کرو DOWNLOADHEADER 4111
#تعریف_کرو CLOSECHANNEL 4112
#تعریف_کرو POSTSCRIPT_PASSTHROUGH 4115
#تعریف_کرو ENCAPSULATED_POSTSCRIPT 4116

#تعریف_کرو POSTSCRIPT_IDENTIFY 4117
#تعریف_کرو POSTSCRIPT_INJECTION 4118

#تعریف_کرو CHECKJPEGFORMAT 4119
#تعریف_کرو CHECKPNGFORMAT 4120

#تعریف_کرو GET_PS_FEATURESETTING 4121

#تعریف_کرو SPCLPASSTHROUGH2 4568

#تعریف_کرو PSIDENT_GDICENTRIC 0
#تعریف_کرو PSIDENT_PSCENTRIC 1

  تعريفنوع بنية _PSINJECTDATA {
    DWORD انکڑے_بائٹاں;
    لفظ_3 Injection_نقطہ;
    لفظ_3 ورقہ_نمبر;
  } PSINJECTDATA,*PPSINJECTDATA;

#تعریف_کرو PSINJECT_BEGINSTREAM 1
#تعریف_کرو PSINJECT_PSADOBE 2
#تعریف_کرو PSINJECT_PAGESATEND 3
#تعریف_کرو PSINJECT_ورقے 4

#تعریف_کرو PSINJECT_DOCNEEDEDRES 5
#تعریف_کرو PSINJECT_DOCSUPPLIEDRES 6
#تعریف_کرو PSINJECT_PAGEORDER 7
#تعریف_کرو PSINJECT_ORIENTATION 8
#تعریف_کرو PSINJECT_BOUNDINGBOX 9
#تعریف_کرو PSINJECT_DOCUMENTPROCESSCOLORS 10

#تعریف_کرو PSINJECT_COMMENTS 11
#تعریف_کرو PSINJECT_BEGINDEFAULTS 12
#تعریف_کرو PSINJECT_ENDDEFAULTS 13
#تعریف_کرو PSINJECT_BEGINPROLOG 14
#تعریف_کرو PSINJECT_ENDPROLOG 15
#تعریف_کرو PSINJECT_BEGINSETUP 16
#تعریف_کرو PSINJECT_ENDSETUP 17
#تعریف_کرو PSINJECT_TRAILER 18
#تعریف_کرو PSINJECT_EOF 19
#تعریف_کرو PSINJECT_ENDSTREAM 20
#تعریف_کرو PSINJECT_DOCUMENTPROCESSCOLORSATEND 21

#تعریف_کرو PSINJECT_PAGENUMBER 100
#تعریف_کرو PSINJECT_BEGINPAGESETUP 101
#تعریف_کرو PSINJECT_ENDPAGESETUP 102
#تعریف_کرو PSINJECT_PAGETRAILER 103
#تعریف_کرو PSINJECT_PLATECOLOR 104

#تعریف_کرو PSINJECT_SHOWPAGE 105
#تعریف_کرو PSINJECT_PAGEBBOX 106
#تعریف_کرو PSINJECT_ENDPAGECOMMENTS 107

#تعریف_کرو PSINJECT_VMSAVE 200
#تعریف_کرو PSINJECT_VMRESTORE 201

#تعریف_کرو FEATURESETTING_NUP 0
#تعریف_کرو FEATURESETTING_OUTPUT 1
#تعریف_کرو FEATURESETTING_PSLEVEL 2
#تعریف_کرو FEATURESETTING_CUSTPAPER 3
#تعریف_کرو FEATURESETTING_MIRROR 4
#تعریف_کرو FEATURESETTING_NEGATIVE 5
#تعریف_کرو FEATURESETTING_PROTOCOL 6

#تعریف_کرو FEATURESETTING_نجی_BEGIN 0x1000
#تعریف_کرو FEATURESETTING_نجی_سرا 0x1FFF

  تعريفنوع بنية _PSFEATURE_OUTPUT {
    WINBOOL b_ورقہ_Independent;
    WINBOOL b_سیٹ_ورقہ_Device;
  } PSFEATURE_OUTPUT,*PPSFEATURE_OUTPUT;

  تعريفنوع بنية _PSFEATURE_CUSTPAPER {
    LONG lOrientation;
    LONG l_چوڑائی;
    LONG l_اچائی;
    LONG l_چوڑائی_وتھ;
    LONG l_اچائی_وتھ;
  } PSFEATURE_CUSTPAPER,*PPSFEATURE_CUSTPAPER;

#تعریف_کرو PSPROTOCOL_ASCII 0
#تعریف_کرو PSPROTOCOL_BCP 1
#تعریف_کرو PSPROTOCOL_TBCP 2
#تعریف_کرو PSPROTOCOL_ثنائی 3

#تعریف_کرو QDI_SETDIBITS 1
#تعریف_کرو QDI_GETDIBITS 2
#تعریف_کرو QDI_DIBTOSCREEN 4
#تعریف_کرو QDI_STRETCHDIB 8

#تعریف_کرو SP_NOTREPORTED 0x4000
#تعریف_کرو SP_ERROR (-1)
#تعریف_کرو SP_APPABORT (-2)
#تعریف_کرو SP_USERABORT (-3)
#تعریف_کرو SP_OUTOFDISK (-4)
#تعریف_کرو SP_OUTOFMEMORY (-5)

#تعریف_کرو PR_JOBSTATUS 0x0000

#تعریف_کرو OBJ_PEN 1
#تعریف_کرو OBJ_BRUSH 2
#تعریف_کرو OBJ_DC 3
#تعریف_کرو OBJ_METADC 4
#تعریف_کرو OBJ_PAL 5
#تعریف_کرو OBJ_FONT 6
#تعریف_کرو OBJ_BITMAP 7
#تعریف_کرو OBJ_REGION 8
#تعریف_کرو OBJ_METAFILE 9
#تعریف_کرو OBJ_MEMDC 10
#تعریف_کرو OBJ_EXTPEN 11
#تعریف_کرو OBJ_ENHMETADC 12
#تعریف_کرو OBJ_ENHMETAFILE 13
#تعریف_کرو OBJ_COLORSPACE 14

#تعریف_کرو MWT_پچھان_تت 1
#تعریف_کرو MWT_LEFTMULTIPLY 2
#تعریف_کرو MWT_RIGHTMULTIPLY 3

#تعریف_کرو MWT_MIN MWT_پچھان_تت
#تعریف_کرو MWT_MAX MWT_RIGHTMULTIPLY

#تعریف_کرو _XFORM_
  تعريفنوع بنية ٹیگ_XFORM {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
  } XFORM,*PXFORM,*LPXFORM;

  تعريفنوع بنية ٹیگ_BITMAP {
    LONG bmType;
    LONG bm_چوڑائی;
    LONG bm_اچائی;
    LONG bm_چوڑائی_بائٹاں;
    لفظ_3 bmPlanes;
    لفظ_3 bm_بٹ_Pixel;
    LPVOID bm_بٹ;
  } BITMAP,*PBITMAP,*NPBITMAP,*LPBITMAP;

#ضمن <pshpack1.h>
  تعريفنوع بنية ٹیگ_RGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
  } RGBTRIPLE;
#ضمن <poppack.h>

  تعريفنوع بنية ٹیگ_RGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
  } RGBQUAD;
  تعريفنوع RGBQUAD *LPRGBQUAD;

#تعریف_کرو CS_ENABLE 0x00000001L
#تعریف_کرو CS_DISABLE 0x00000002L
#تعریف_کرو CS_DELETE_TRANSFORM 0x00000003L

//!__TINYC__: #define LCS_SIGNATURE 'PSOC'
//!__TINYC__: #define LCS_sRGB 'sRGB'
//!__TINYC__: #define LCS_WINDOWS_COLOR_SPACE 'Win '

  تعريفنوع LONG LCSCSTYPE;
#تعریف_کرو LCS_CALIBRATED_RGB 0x00000000L

  تعريفنوع LONG LCSGAMUTMATCH;
#تعریف_کرو LCS_GM_BUSINESS 0x00000001L
#تعریف_کرو LCS_GM_GRAPHICS 0x00000002L
#تعریف_کرو LCS_GM_IMAGES 0x00000004L
#تعریف_کرو LCS_GM_ABS_COLORIMETRIC 0x00000008L

#تعریف_کرو CM_باہرلا_دا_GAMUT 255
#تعریف_کرو CM_وچ_GAMUT 0

#تعریف_کرو ICM_ADDPROFILE 1
#تعریف_کرو ICM_DELETEPROFILE 2
#تعریف_کرو ICM_QUERYPROFILE 3
#تعریف_کرو ICM_SETDEFAULTPROFILE 4
#تعریف_کرو ICM_REGISTERICMATCHER 5
#تعریف_کرو ICM_UNREGISTERICMATCHER 6
#تعریف_کرو ICM_QUERYMATCH 7

#تعریف_کرو GetKValue(cmyk) ((BYTE)(cmyk))
#تعریف_کرو GetYValue(cmyk) ((BYTE)((cmyk)>> 8))
#تعریف_کرو GetMValue(cmyk) ((BYTE)((cmyk)>>16))
#تعریف_کرو GetCValue(cmyk) ((BYTE)((cmyk)>>24))

#تعریف_کرو CMYK(c,m,y,k) ((COLORREF)((((BYTE)(k)|((لفظ_3)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

  تعريفنوع لما FXPT16DOT16,*LPFXPT16DOT16;
  تعريفنوع لما FXPT2DOT30,*LPFXPT2DOT30;

  تعريفنوع بنية ٹیگ_CIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
  } CIEXYZ;
  تعريفنوع CIEXYZ *LPCIEXYZ;

  تعريفنوع بنية ٹیگ_ICEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
  } CIEXYZTRIPLE;

  تعريفنوع CIEXYZTRIPLE *LPCIEXYZTRIPLE;

  تعريفنوع بنية ٹیگ_LOGCOLORSPACEA {
    DWORD lcsSignature;
    DWORD lcs_نسخہ;
    DWORD lcs_ناپ;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    CHAR lcsFilename[MAX_رستہ];
  } LOGCOLORSPACEA,*LPLOGCOLORSPACEA;

  تعريفنوع بنية ٹیگ_LOGCOLORSPACEW {
    DWORD lcsSignature;
    DWORD lcs_نسخہ;
    DWORD lcs_ناپ;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    WCHAR lcsFilename[MAX_رستہ];
  } LOGCOLORSPACEW,*LPLOGCOLORSPACEW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع LOGCOLORSPACEW LOGCOLORSPACE;
  تعريفنوع LPLOGCOLORSPACEW LPLOGCOLORSPACE;
#وإلا
  تعريفنوع LOGCOLORSPACEA LOGCOLORSPACE;
  تعريفنوع LPLOGCOLORSPACEA LPLOGCOLORSPACE;
#جے_انت

  تعريفنوع بنية ٹیگ_BITMAPCOREHEADER {
    DWORD bc_ناپ;
    لفظ_3 bc_چوڑائی;
    لفظ_3 bc_اچائی;
    لفظ_3 bcPlanes;
    لفظ_3 bc_ثنائی_ہندسہ_گنتی;
  } BITMAPCOREHEADER,*LPBITMAPCOREHEADER,*PBITMAPCOREHEADER;

  تعريفنوع بنية ٹیگ_BITMAPINFOHEADER {
    DWORD bi_ناپ;
    LONG bi_چوڑائی;
    LONG bi_اچائی;
    لفظ_3 biPlanes;
    لفظ_3 bi_ثنائی_ہندسہ_گنتی;
    DWORD biCompression;
    DWORD bi_ناپ_Image;
    LONG bi_XPels_فی_Meter;
    LONG bi_YPels_فی_Meter;
    DWORD bi_Clr_ورتیا;
    DWORD biClrImportant;
  } BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

  تعريفنوع بنية {
    DWORD b_V4_ناپ;
    LONG b_V4_چوڑائی;
    LONG b_V4_اچائی;
    لفظ_3 bV4Planes;
    لفظ_3 b_V4_ثنائی_ہندسہ_گنتی;
    DWORD bV4V4Compression;
    DWORD b_V4_ناپ_Image;
    LONG b_V4_XPels_فی_Meter;
    LONG b_V4_YPels_فی_Meter;
    DWORD b_V4_Clr_ورتیا;
    DWORD bV4ClrImportant;
    DWORD b_V4_Red_نقاب;
    DWORD b_V4_Green_نقاب;
    DWORD b_V4_Blue_نقاب;
    DWORD b_V4_Alpha_نقاب;
    DWORD bV4CSType;
    CIEXYZTRIPLE bV4Endpoints;
    DWORD bV4GammaRed;
    DWORD bV4GammaGreen;
    DWORD bV4GammaBlue;
  } BITMAPV4_سرخی,*LPBITMAPV4_سرخی,*PBITMAPV4_سرخی;

  تعريفنوع بنية {
    DWORD b_V5_ناپ;
    LONG b_V5_چوڑائی;
    LONG b_V5_اچائی;
    لفظ_3 bV5Planes;
    لفظ_3 b_V5_ثنائی_ہندسہ_گنتی;
    DWORD bV5Compression;
    DWORD b_V5_ناپ_Image;
    LONG b_V5_XPels_فی_Meter;
    LONG b_V5_YPels_فی_Meter;
    DWORD b_V5_Clr_ورتیا;
    DWORD bV5ClrImportant;
    DWORD b_V5_Red_نقاب;
    DWORD b_V5_Green_نقاب;
    DWORD b_V5_Blue_نقاب;
    DWORD b_V5_Alpha_نقاب;
    DWORD bV5CSType;
    CIEXYZTRIPLE bV5Endpoints;
    DWORD bV5GammaRed;
    DWORD bV5GammaGreen;
    DWORD bV5GammaBlue;
    DWORD bV5Intent;
    DWORD b_V5_Profile_انکڑے;
    DWORD b_V5_Profile_ناپ;
    DWORD bV5Reserved;
  } BITMAPV5_سرخی,*LPBITMAPV5_سرخی,*PBITMAPV5_سرخی;

//!__TINYC__: #define PROFILE_LINKED 'LINK'
//!__TINYC__: #define PROFILE_EMBEDDED 'MBED'

#تعریف_کرو BI_RGB 0L
#تعریف_کرو BI_RLE8 1L
#تعریف_کرو BI_RLE4 2L
#تعریف_کرو BI_BITFIELDS 3L
#تعریف_کرو BI_JPEG 4L
#تعریف_کرو BI_PNG 5L

  تعريفنوع بنية ٹیگ_BITMAPINFO {
    BITMAPINFOHEADER bmi_سرخی;
    RGBQUAD bmiColors[1];
  } BITMAPINFO,*LPBITMAPINFO,*PBITMAPINFO;

  تعريفنوع بنية ٹیگ_BITMAPCOREINFO {
    BITMAPCOREHEADER bmci_سرخی;
    RGBTRIPLE bmciColors[1];
  } BITMAPCOREINFO,*LPBITMAPCOREINFO,*PBITMAPCOREINFO;

#ضمن <pshpack2.h>
  تعريفنوع بنية ٹیگ_BITMAPFILEHEADER {
    لفظ_3 bfType;
    DWORD bf_ناپ;
    لفظ_3 bfReserved1;
    لفظ_3 bfReserved2;
    DWORD bf_Off_بٹ;
  } BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#ضمن <poppack.h>

#تعریف_کرو MAKEPOINTS(l) (*((POINTS *)&(l)))

#جے_بنا_تعریف NOFONTSIG
  تعريفنوع بنية ٹیگ_FONTSIGNATURE {
    DWORD fsUsb[4];
    DWORD fsCsb[2];
  } FONTSIGNATURE,*PFONTSIGNATURE,*LPFONTSIGNATURE;

  تعريفنوع بنية ٹیگ_CHARSETINFO {
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
  } CHARSETINFO,*PCHARSETINFO,*NPCHARSETINFO,*LPCHARSETINFO;

#تعریف_کرو TCI_SRCCHARSET 1
#تعریف_کرو TCI_SRCCODEPAGE 2
#تعریف_کرو TCI_SRCFONTSIG 3
#تعریف_کرو TCI_SRCLOCALE 0x1000

  تعريفنوع بنية ٹیگ_LOCALESIGNATURE {
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
  } LOCALESIGNATURE,*PLOCALESIGNATURE,*LPLOCALESIGNATURE;
#جے_انت


#جے_بنا_تعریف NOMETAFILE
  تعريفنوع بنية ٹیگ_HANDLETABLE {
    HGDIOBJ objectHandle[1];
  } HANDLETABLE,*PHANDLETABLE,*LPHANDLETABLE;

  تعريفنوع بنية ٹیگ_METARECORD {
    DWORD rd_ناپ;
    لفظ_3 rdFunction;
    لفظ_3 rdParm[1];
  } METARECORD;
  تعريفنوع بنية ٹیگ_METARECORD UNALIGNED *PMETARECORD;
  تعريفنوع بنية ٹیگ_METARECORD UNALIGNED *LPMETARECORD;

  تعريفنوع بنية ٹیگ_METAFILEPICT {
    LONG mm;
    LONG xExt;
    LONG yExt;
    HMETAFILE hMF;
  } METAFILEPICT,*LPMETAFILEPICT;

#ضمن <pshpack2.h>
  تعريفنوع بنية ٹیگ_METAHEADER {
    لفظ_3 mtType;
    لفظ_3 mt_سرخی_ناپ;
    لفظ_3 mt_نسخہ;
    DWORD mt_ناپ;
    لفظ_3 mtNoObjects;
    DWORD mt_Max_ریکارڈ;
    لفظ_3 mtNoParameters;
  } METAHEADER;
  تعريفنوع بنية ٹیگ_METAHEADER UNALIGNED *PMETAHEADER;
  تعريفنوع بنية ٹیگ_METAHEADER UNALIGNED *LPMETAHEADER;

#ضمن <poppack.h>

  تعريفنوع بنية ٹیگ_ENHMETARECORD {
    DWORD iType;
    DWORD n_ناپ;
    DWORD dParm[1];
  } ENHMETARECORD,*PENHMETARECORD,*LPENHMETARECORD;

  تعريفنوع بنية ٹیگ_ENHMETAHEADER {
    DWORD iType;
    DWORD n_ناپ;
    RECTL rclBounds;
    RECTL rcl_چوکھٹا;
    DWORD dSignature;
    DWORD n_نسخہ;
    DWORD n_بائٹاں;
    DWORD n_ریکارڈاں;
    لفظ_3 nHandles;
    لفظ_3 sReserved;
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
#جے_انت

#جے_بنا_تعریف NOTEXTMETRIC
#تعریف_کرو TMPF_FIXED_PITCH 0x01
#تعریف_کرو TMPF_سمتیہ 0x02
#تعریف_کرو TMPF_DEVICE 0x08
#تعریف_کرو TMPF_TRUETYPE 0x04

#جے_تعریف_شدہ UNICODE
  تعريفنوع WCHAR BCHAR;
#وإلا
  تعريفنوع BYTE BCHAR;
#جے_انت

#جے_بنا_تعریف _TEXTMETRIC_DEFINED
#تعریف_کرو _TEXTMETRIC_DEFINED
  تعريفنوع بنية ٹیگ_TEXTMETRICA {
    LONG tm_اچائی;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_اندرونی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_چوڑائی;
    LONG tm_Max_Char_چوڑائی;
    LONG tm_بھار;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_پہلا_Char;
    BYTE tm_آخری_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_باہرلا;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سیٹ;
  } TEXTMETRICA,*PTEXTMETRICA,*NPTEXTMETRICA,*LPTEXTMETRICA;

  تعريفنوع بنية ٹیگ_TEXTMETRICW {
    LONG tm_اچائی;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_اندرونی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_چوڑائی;
    LONG tm_Max_Char_چوڑائی;
    LONG tm_بھار;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_پہلا_Char;
    WCHAR tm_آخری_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_باہرلا;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سیٹ;
  } TEXTMETRICW,*PTEXTMETRICW,*NPTEXTMETRICW,*LPTEXTMETRICW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع TEXTMETRICW TEXTMETRIC;
  تعريفنوع PTEXTMETRICW PTEXTMETRIC;
  تعريفنوع NPTEXTMETRICW NPTEXTMETRIC;
  تعريفنوع LPTEXTMETRICW LPTEXTMETRIC;
#وإلا
  تعريفنوع TEXTMETRICA TEXTMETRIC;
  تعريفنوع PTEXTMETRICA PTEXTMETRIC;
  تعريفنوع NPTEXTMETRICA NPTEXTMETRIC;
  تعريفنوع LPTEXTMETRICA LPTEXTMETRIC;
#جے_انت
#جے_انت

#تعریف_کرو NTM_REGULAR 0x00000040L
#تعریف_کرو NTM_BOLD 0x00000020L
#تعریف_کرو NTM_ITALIC 0x00000001L

#تعریف_کرو NTM_NONNEGATIVE_AC 0x00010000
#تعریف_کرو NTM_PS_OPENTYPE 0x00020000
#تعریف_کرو NTM_TT_OPENTYPE 0x00040000
#تعریف_کرو NTM_MULTIPLEMASTER 0x00080000
#تعریف_کرو NTM_TYPE1 0x00100000
#تعریف_کرو NTM_DSIG 0x00200000

#ضمن <pshpack4.h>
  تعريفنوع بنية ٹیگ_NEWTEXTMETRICA {
    LONG tm_اچائی;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_اندرونی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_چوڑائی;
    LONG tm_Max_Char_چوڑائی;
    LONG tm_بھار;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_پہلا_Char;
    BYTE tm_آخری_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_باہرلا;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سیٹ;
    DWORD ntmFlags;
    UINT ntm_ناپ_EM;
    UINT ntm_Cell_اچائی;
    UINT ntm_Avg_چوڑائی;
  } NEWTEXTMETRICA,*PNEWTEXTMETRICA,*NPNEWTEXTMETRICA,*LPNEWTEXTMETRICA;

  تعريفنوع بنية ٹیگ_NEWTEXTMETRICW {
    LONG tm_اچائی;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_اندرونی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_چوڑائی;
    LONG tm_Max_Char_چوڑائی;
    LONG tm_بھار;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_پہلا_Char;
    WCHAR tm_آخری_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_باہرلا;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سیٹ;
    DWORD ntmFlags;
    UINT ntm_ناپ_EM;
    UINT ntm_Cell_اچائی;
    UINT ntm_Avg_چوڑائی;
  } NEWTEXTMETRICW,*PNEWTEXTMETRICW,*NPNEWTEXTMETRICW,*LPNEWTEXTMETRICW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع NEWTEXTMETRICW NEWTEXTMETRIC;
  تعريفنوع PNEWTEXTMETRICW PNEWTEXTMETRIC;
  تعريفنوع NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
  تعريفنوع LPNEWTEXTMETRICW LPNEWTEXTMETRIC;
#وإلا
  تعريفنوع NEWTEXTMETRICA NEWTEXTMETRIC;
  تعريفنوع PNEWTEXTMETRICA PNEWTEXTMETRIC;
  تعريفنوع NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
  تعريفنوع LPNEWTEXTMETRICA LPNEWTEXTMETRIC;
#جے_انت
#ضمن <poppack.h>

  تعريفنوع بنية ٹیگ_NEWTEXTMETRICEXA {
    NEWTEXTMETRICA ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXA;

  تعريفنوع بنية ٹیگ_NEWTEXTMETRICEXW {
    NEWTEXTMETRICW ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع NEWTEXTMETRICEXW NEWTEXTMETRICEX;
#وإلا
  تعريفنوع NEWTEXTMETRICEXA NEWTEXTMETRICEX;
#جے_انت
#جے_انت

  تعريفنوع بنية ٹیگ_PELARRAY {
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
  } PELARRAY,*PPELARRAY,*NPPELARRAY,*LPPELARRAY;

  تعريفنوع بنية ٹیگ_LOGBRUSH {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
  } LOGBRUSH,*PLOGBRUSH,*NPLOGBRUSH,*LPLOGBRUSH;

  تعريفنوع بنية ٹیگ_LOGBRUSH32 {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG lbHatch;
  } LOGBRUSH32,*PLOGBRUSH32,*NPLOGBRUSH32,*LPLOGBRUSH32;

  تعريفنوع LOGBRUSH نمونہ_2;
  تعريفنوع نمونہ_2 *PPATTERN;
  تعريفنوع نمونہ_2 *NPPATTERN;
  تعريفنوع نمونہ_2 *LPPATTERN;

  تعريفنوع بنية ٹیگ_LOGPEN {
    UINT lopnStyle;
    نقطہ_3 lopn_چوڑائی;
    COLORREF lopnColor;
  } LOGPEN,*PLOGPEN,*NPLOGPEN,*LPLOGPEN;

  تعريفنوع بنية ٹیگ_EXTLOGPEN {
    DWORD elpPenStyle;
    DWORD elp_چوڑائی;
    UINT elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elp_عدد_Entries;
    DWORD elp_Style_اندراج[1];
  } EXTLOGPEN,*PEXTLOGPEN,*NPEXTLOGPEN,*LPEXTLOGPEN;

#جے_بنا_تعریف _PALETTEENTRY_DEFINED
#تعریف_کرو _PALETTEENTRY_DEFINED
  تعريفنوع بنية ٹیگ_PALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
  } PALETTEENTRY,*PPALETTEENTRY,*LPPALETTEENTRY;
#جے_انت

#جے_بنا_تعریف _LOGPALETTE_DEFINED
#تعریف_کرو _LOGPALETTE_DEFINED

  تعريفنوع بنية ٹیگ_LOGPALETTE {
    لفظ_3 pal_نسخہ;
    لفظ_3 pal_عدد_Entries;
    PALETTEENTRY pal_Pal_اندراج[1];
  } LOGPALETTE,*PLOGPALETTE,*NPLOGPALETTE,*LPLOGPALETTE;
#جے_انت

#تعریف_کرو LF_FACESIZE 32

  تعريفنوع بنية ٹیگ_LOGFONTA {
    LONG lf_اچائی;
    LONG lf_چوڑائی;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_بھار;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_باہرلا;
    BYTE lf_Char_سیٹ;
    BYTE lf_باہرلا_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[LF_FACESIZE];
  } LOGFONTA,*PLOGFONTA,*NPLOGFONTA,*LPLOGFONTA;

  تعريفنوع بنية ٹیگ_LOGFONTW {
    LONG lf_اچائی;
    LONG lf_چوڑائی;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_بھار;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_باہرلا;
    BYTE lf_Char_سیٹ;
    BYTE lf_باہرلا_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[LF_FACESIZE];
  } LOGFONTW,*PLOGFONTW,*NPLOGFONTW,*LPLOGFONTW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع LOGFONTW LOGFONT;
  تعريفنوع PLOGFONTW PLOGFONT;
  تعريفنوع NPLOGFONTW NPLOGFONT;
  تعريفنوع LPLOGFONTW LPLOGFONT;
#وإلا
  تعريفنوع LOGFONTA LOGFONT;
  تعريفنوع PLOGFONTA PLOGFONT;
  تعريفنوع NPLOGFONTA NPLOGFONT;
  تعريفنوع LPLOGFONTA LPLOGFONT;
#جے_انت

#تعریف_کرو LF_FULLFACESIZE 64

  تعريفنوع بنية ٹیگ_ENUMLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_بھریا_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
  } ENUMLOGFONTA,*LPENUMLOGFONTA;

  تعريفنوع بنية ٹیگ_ENUMLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_بھریا_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
  } ENUMLOGFONTW,*LPENUMLOGFONTW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع ENUMLOGFONTW ENUMLOGFONT;
  تعريفنوع LPENUMLOGFONTW LPENUMLOGFONT;
#وإلا
  تعريفنوع ENUMLOGFONTA ENUMLOGFONT;
  تعريفنوع LPENUMLOGFONTA LPENUMLOGFONT;
#جے_انت

  تعريفنوع بنية ٹیگ_ENUMLOGFONTEXA {
    LOGFONTA elfLogFont;
    BYTE elf_بھریا_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    BYTE elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXA,*LPENUMLOGFONTEXA;

  تعريفنوع بنية ٹیگ_ENUMLOGFONTEXW {
    LOGFONTW elfLogFont;
    WCHAR elf_بھریا_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    WCHAR elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXW,*LPENUMLOGFONTEXW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع ENUMLOGFONTEXW ENUMLOGFONTEX;
  تعريفنوع LPENUMLOGFONTEXW LPENUMLOGFONTEX;
#وإلا
  تعريفنوع ENUMLOGFONTEXA ENUMLOGFONTEX;
  تعريفنوع LPENUMLOGFONTEXA LPENUMLOGFONTEX;
#جے_انت

#تعریف_کرو باہرلا_DEFAULT_PRECIS 0
#تعریف_کرو باہرلا_STRING_PRECIS 1
#تعریف_کرو باہرلا_CHARACTER_PRECIS 2
#تعریف_کرو باہرلا_STROKE_PRECIS 3
#تعریف_کرو باہرلا_TT_PRECIS 4
#تعریف_کرو باہرلا_DEVICE_PRECIS 5
#تعریف_کرو باہرلا_RASTER_PRECIS 6
#تعریف_کرو باہرلا_TT_ONLY_PRECIS 7
#تعریف_کرو باہرلا_OUTLINE_PRECIS 8
#تعریف_کرو باہرلا_SCREEN_OUTLINE_PRECIS 9
#تعریف_کرو باہرلا_PS_ONLY_PRECIS 10

#تعریف_کرو CLIP_DEFAULT_PRECIS 0
#تعریف_کرو CLIP_CHARACTER_PRECIS 1
#تعریف_کرو CLIP_STROKE_PRECIS 2
#تعریف_کرو CLIP_نقاب 0xf
#تعریف_کرو CLIP_LH_ANGLES (1<<4)
#تعریف_کرو CLIP_TT_ALWAYS (2<<4)
#تعریف_کرو CLIP_DFA_DISABLE (4<<4)
#تعریف_کرو CLIP_EMBEDDED (8<<4)

#تعریف_کرو DEFAULT_QUALITY 0
#تعریف_کرو DRAFT_QUALITY 1
#تعریف_کرو PROOF_QUALITY 2
#تعریف_کرو NONANTIALIASED_QUALITY 3
#تعریف_کرو ANTIALIASED_QUALITY 4

#تعریف_کرو CLEARTYPE_QUALITY 5
#تعریف_کرو CLEARTYPE_NATURAL_QUALITY 6

#تعریف_کرو DEFAULT_PITCH 0
#تعریف_کرو FIXED_PITCH 1
#تعریف_کرو VARIABLE_PITCH 2
#تعریف_کرو MONO_FONT 8

#تعریف_کرو ANSI_CHARSET 0
#تعریف_کرو DEFAULT_CHARSET 1
#تعریف_کرو علامت_CHARSET 2
#تعریف_کرو SHIFTJIS_CHARSET 128
#تعریف_کرو HANGEUL_CHARSET 129
#تعریف_کرو HANGUL_CHARSET 129
#تعریف_کرو GB2312_CHARSET 134
#تعریف_کرو CHINESEBIG5_CHARSET 136
#تعریف_کرو OEM_CHARSET 255
#تعریف_کرو JOHAB_CHARSET 130
#تعریف_کرو HEBREW_CHARSET 177
#تعریف_کرو ARABIC_CHARSET 178
#تعریف_کرو GREEK_CHARSET 161
#تعریف_کرو TURKISH_CHARSET 162
#تعریف_کرو VIETNAMESE_CHARSET 163
#تعریف_کرو THAI_CHARSET 222
#تعریف_کرو EASTEUROPE_CHARSET 238
#تعریف_کرو RUSSIAN_CHARSET 204

#تعریف_کرو MAC_CHARSET 77
#تعریف_کرو BALTIC_CHARSET 186

#تعریف_کرو FS_LATIN1 0x00000001L
#تعریف_کرو FS_LATIN2 0x00000002L
#تعریف_کرو FS_CYRILLIC 0x00000004L
#تعریف_کرو FS_GREEK 0x00000008L
#تعریف_کرو FS_TURKISH 0x00000010L
#تعریف_کرو FS_HEBREW 0x00000020L
#تعریف_کرو FS_ARABIC 0x00000040L
#تعریف_کرو FS_BALTIC 0x00000080L
#تعریف_کرو FS_VIETNAMESE 0x00000100L
#تعریف_کرو FS_THAI 0x00010000L
#تعریف_کرو FS_JISJAPAN 0x00020000L
#تعریف_کرو FS_CHINESESIMP 0x00040000L
#تعریف_کرو FS_WANSUNG 0x00080000L
#تعریف_کرو FS_CHINESETRAD 0x00100000L
#تعریف_کرو FS_JOHAB 0x00200000L
#تعریف_کرو FS_علامت 0x80000000L

#تعریف_کرو FF_DONTCARE (0<<4)
#تعریف_کرو FF_ROMAN (1<<4)

#تعریف_کرو FF_SWISS (2<<4)

#تعریف_کرو FF_MODERN (3<<4)

#تعریف_کرو FF_SCRIPT (4<<4)
#تعریف_کرو FF_DECORATIVE (5<<4)

#تعریف_کرو FW_DONTCARE 0
#تعریف_کرو FW_THIN 100
#تعریف_کرو FW_EXTRALIGHT 200
#تعریف_کرو FW_LIGHT 300
#تعریف_کرو FW_عام 400
#تعریف_کرو FW_MEDIUM 500
#تعریف_کرو FW_SEMIBOLD 600
#تعریف_کرو FW_BOLD 700
#تعریف_کرو FW_EXTRABOLD 800
#تعریف_کرو FW_HEAVY 900

#تعریف_کرو FW_ULTRALIGHT FW_EXTRALIGHT
#تعریف_کرو FW_REGULAR FW_عام
#تعریف_کرو FW_DEMIBOLD FW_SEMIBOLD
#تعریف_کرو FW_ULTRABOLD FW_EXTRABOLD
#تعریف_کرو FW_BLACK FW_HEAVY

#تعریف_کرو PANOSE_گنتی 10
#تعریف_کرو PAN_FAMILYTYPE_اشاریہ 0
#تعریف_کرو PAN_SERIFSTYLE_اشاریہ 1
#تعریف_کرو PAN_بھار_اشاریہ 2
#تعریف_کرو PAN_PROPORTION_اشاریہ 3
#تعریف_کرو PAN_CONTRAST_اشاریہ 4
#تعریف_کرو PAN_STROKEVARIATION_اشاریہ 5
#تعریف_کرو PAN_ARMSTYLE_اشاریہ 6
#تعریف_کرو PAN_LETTERFORM_اشاریہ 7
#تعریف_کرو PAN_MIDLINE_اشاریہ 8
#تعریف_کرو PAN_XHEIGHT_اشاریہ 9

#تعریف_کرو PAN_CULTURE_LATIN 0

  تعريفنوع بنية ٹیگ_PANOSE {
    BYTE bFamilyType;
    BYTE bSerifStyle;
    BYTE b_بھار;
    BYTE bProportion;
    BYTE bContrast;
    BYTE bStrokeVariation;
    BYTE bArmStyle;
    BYTE bLetterform;
    BYTE bMidline;
    BYTE bXHeight;
  } PANOSE,*LPPANOSE;

#تعریف_کرو PAN_ANY 0
#تعریف_کرو PAN_NO_FIT 1

#تعریف_کرو PAN_FAMILY_متن_DISPLAY 2
#تعریف_کرو PAN_FAMILY_SCRIPT 3
#تعریف_کرو PAN_FAMILY_DECORATIVE 4
#تعریف_کرو PAN_FAMILY_PICTORIAL 5

#تعریف_کرو PAN_SERIF_COVE 2
#تعریف_کرو PAN_SERIF_OBTUSE_COVE 3
#تعریف_کرو PAN_SERIF_مربع_COVE 4
#تعریف_کرو PAN_SERIF_OBTUSE_مربع_COVE 5
#تعریف_کرو PAN_SERIF_مربع 6
#تعریف_کرو PAN_SERIF_THIN 7
#تعریف_کرو PAN_SERIF_BONE 8
#تعریف_کرو PAN_SERIF_EXAGGERATED 9
#تعریف_کرو PAN_SERIF_TRIANGLE 10
#تعریف_کرو PAN_SERIF_عام_SANS 11
#تعریف_کرو PAN_SERIF_OBTUSE_SANS 12
#تعریف_کرو PAN_SERIF_PERP_SANS 13
#تعریف_کرو PAN_SERIF_FLARED 14
#تعریف_کرو PAN_SERIF_ROUNDED 15

#تعریف_کرو PAN_بھار_VERY_LIGHT 2
#تعریف_کرو PAN_بھار_LIGHT 3
#تعریف_کرو PAN_بھار_THIN 4
#تعریف_کرو PAN_بھار_BOOK 5
#تعریف_کرو PAN_بھار_MEDIUM 6
#تعریف_کرو PAN_بھار_DEMI 7
#تعریف_کرو PAN_بھار_BOLD 8
#تعریف_کرو PAN_بھار_HEAVY 9
#تعریف_کرو PAN_بھار_BLACK 10
#تعریف_کرو PAN_بھار_NORD 11

#تعریف_کرو PAN_PROP_OLD_STYLE 2
#تعریف_کرو PAN_PROP_MODERN 3
#تعریف_کرو PAN_PROP_EVEN_چوڑائی 4
#تعریف_کرو PAN_PROP_EXPANDED 5
#تعریف_کرو PAN_PROP_CONDENSED 6
#تعریف_کرو PAN_PROP_VERY_EXPANDED 7
#تعریف_کرو PAN_PROP_VERY_CONDENSED 8
#تعریف_کرو PAN_PROP_MONOSPACED 9

#تعریف_کرو PAN_CONTRAST_NONE 2
#تعریف_کرو PAN_CONTRAST_VERY_کم 3
#تعریف_کرو PAN_CONTRAST_کم 4
#تعریف_کرو PAN_CONTRAST_MEDIUM_کم 5
#تعریف_کرو PAN_CONTRAST_MEDIUM 6
#تعریف_کرو PAN_CONTRAST_MEDIUM_بلند 7
#تعریف_کرو PAN_CONTRAST_بلند 8
#تعریف_کرو PAN_CONTRAST_VERY_بلند 9

#تعریف_کرو PAN_STROKE_GRADUAL_DIAG 2
#تعریف_کرو PAN_STROKE_GRADUAL_TRAN 3
#تعریف_کرو PAN_STROKE_GRADUAL_VERT 4
#تعریف_کرو PAN_STROKE_GRADUAL_HORZ 5
#تعریف_کرو PAN_STROKE_RAPID_VERT 6
#تعریف_کرو PAN_STROKE_RAPID_HORZ 7
#تعریف_کرو PAN_STROKE_INSTANT_VERT 8

#تعریف_کرو PAN_STRAIGHT_ARMS_HORZ 2
#تعریف_کرو PAN_STRAIGHT_ARMS_WEDGE 3
#تعریف_کرو PAN_STRAIGHT_ARMS_VERT 4
#تعریف_کرو PAN_STRAIGHT_ARMS_SINGLE_SERIF 5
#تعریف_کرو PAN_STRAIGHT_ARMS_DOUBLE_SERIF 6
#تعریف_کرو PAN_BENT_ARMS_HORZ 7
#تعریف_کرو PAN_BENT_ARMS_WEDGE 8
#تعریف_کرو PAN_BENT_ARMS_VERT 9
#تعریف_کرو PAN_BENT_ARMS_SINGLE_SERIF 10
#تعریف_کرو PAN_BENT_ARMS_DOUBLE_SERIF 11

#تعریف_کرو PAN_LETT_عام_CONTACT 2
#تعریف_کرو PAN_LETT_عام_WEIGHTED 3
#تعریف_کرو PAN_LETT_عام_BOXED 4
#تعریف_کرو PAN_LETT_عام_FLATTENED 5
#تعریف_کرو PAN_LETT_عام_ROUNDED 6
#تعریف_کرو PAN_LETT_عام_OFF_CENTER 7
#تعریف_کرو PAN_LETT_عام_مربع 8
#تعریف_کرو PAN_LETT_OBLIQUE_CONTACT 9
#تعریف_کرو PAN_LETT_OBLIQUE_WEIGHTED 10
#تعریف_کرو PAN_LETT_OBLIQUE_BOXED 11
#تعریف_کرو PAN_LETT_OBLIQUE_FLATTENED 12
#تعریف_کرو PAN_LETT_OBLIQUE_ROUNDED 13
#تعریف_کرو PAN_LETT_OBLIQUE_OFF_CENTER 14
#تعریف_کرو PAN_LETT_OBLIQUE_مربع 15

#تعریف_کرو PAN_MIDLINE_STANDARD_TRIMMED 2
#تعریف_کرو PAN_MIDLINE_STANDARD_POINTED 3
#تعریف_کرو PAN_MIDLINE_STANDARD_SERIFED 4
#تعریف_کرو PAN_MIDLINE_بلند_TRIMMED 5
#تعریف_کرو PAN_MIDLINE_بلند_POINTED 6
#تعریف_کرو PAN_MIDLINE_بلند_SERIFED 7
#تعریف_کرو PAN_MIDLINE_CONSTANT_TRIMMED 8
#تعریف_کرو PAN_MIDLINE_CONSTANT_POINTED 9
#تعریف_کرو PAN_MIDLINE_CONSTANT_SERIFED 10
#تعریف_کرو PAN_MIDLINE_کم_TRIMMED 11
#تعریف_کرو PAN_MIDLINE_کم_POINTED 12
#تعریف_کرو PAN_MIDLINE_کم_SERIFED 13

#تعریف_کرو PAN_XHEIGHT_CONSTANT_SMALL 2
#تعریف_کرو PAN_XHEIGHT_CONSTANT_STD 3
#تعریف_کرو PAN_XHEIGHT_CONSTANT_LARGE 4
#تعریف_کرو PAN_XHEIGHT_DUCKING_SMALL 5
#تعریف_کرو PAN_XHEIGHT_DUCKING_STD 6
#تعریف_کرو PAN_XHEIGHT_DUCKING_LARGE 7

#تعریف_کرو ELF_VENDOR_ناپ 4

  تعريفنوع بنية ٹیگ_EXTLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_بھریا_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    DWORD elf_نسخہ;
    DWORD elf_Style_ناپ;
    DWORD elf_میل;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_ناپ];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTA,*PEXTLOGFONTA,*NPEXTLOGFONTA,*LPEXTLOGFONTA;

  تعريفنوع بنية ٹیگ_EXTLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_بھریا_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    DWORD elf_نسخہ;
    DWORD elf_Style_ناپ;
    DWORD elf_میل;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_ناپ];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTW,*PEXTLOGFONTW,*NPEXTLOGFONTW,*LPEXTLOGFONTW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع EXTLOGFONTW EXTLOGFONT;
  تعريفنوع PEXTLOGFONTW PEXTLOGFONT;
  تعريفنوع NPEXTLOGFONTW NPEXTLOGFONT;
  تعريفنوع LPEXTLOGFONTW LPEXTLOGFONT;
#وإلا
  تعريفنوع EXTLOGFONTA EXTLOGFONT;
  تعريفنوع PEXTLOGFONTA PEXTLOGFONT;
  تعريفنوع NPEXTLOGFONTA NPEXTLOGFONT;
  تعريفنوع LPEXTLOGFONTA LPEXTLOGFONT;
#جے_انت

#تعریف_کرو ELF_نسخہ 0
#تعریف_کرو ELF_CULTURE_LATIN 0

#تعریف_کرو RASTER_FONTTYPE 0x0001
#تعریف_کرو DEVICE_FONTTYPE 0x002
#تعریف_کرو TRUETYPE_FONTTYPE 0x004

#تعریف_کرو RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((لفظ_3)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#تعریف_کرو PALETTERGB(r,g,b) (0x02000000 | RGB(r,g,b))
#تعریف_کرو PALETTEINDEX(i) ((COLORREF)(0x01000000 | (DWORD)(لفظ_3)(i)))

#تعریف_کرو PC_RESERVED 0x01
#تعریف_کرو PC_EXPLICIT 0x02
#تعریف_کرو PC_NOCOLLAPSE 0x04

#تعریف_کرو GetRValue(rgb) (LOBYTE(rgb))
#تعریف_کرو GetGValue(rgb) (LOBYTE(((لفظ_3)(rgb)) >> 8))
#تعریف_کرو GetBValue(rgb) (LOBYTE((rgb)>>16))

#تعریف_کرو TRANSPARENT 1
#تعریف_کرو OPAQUE 2
#تعریف_کرو BKMODE_آخری 2

#تعریف_کرو GM_COMPATIBLE 1
#تعریف_کرو GM_ADVANCED 2
#تعریف_کرو GM_آخری 2

#تعریف_کرو PT_CLOSEFIGURE 0x01
#تعریف_کرو PT_LINETO 0x02
#تعریف_کرو PT_BEZIERTO 0x04
#تعریف_کرو PT_MOVETO 0x06

#تعریف_کرو MM_متن 1
#تعریف_کرو MM_LOMETRIC 2
#تعریف_کرو MM_HIMETRIC 3
#تعریف_کرو MM_LOENGLISH 4
#تعریف_کرو MM_HIENGLISH 5
#تعریف_کرو MM_TWIPS 6
#تعریف_کرو MM_ISOTROPIC 7
#تعریف_کرو MM_ANISOTROPIC 8

#تعریف_کرو MM_MIN MM_متن
#تعریف_کرو MM_MAX MM_ANISOTROPIC
#تعریف_کرو MM_MAX_FIXEDSCALE MM_TWIPS

#تعریف_کرو ABSOLUTE 1
#تعریف_کرو RELATIVE 2

#تعریف_کرو WHITE_BRUSH 0
#تعریف_کرو LTGRAY_BRUSH 1
#تعریف_کرو سلیٹی_BRUSH 2
#تعریف_کرو DKGRAY_BRUSH 3
#تعریف_کرو BLACK_BRUSH 4
#تعریف_کرو NULL_BRUSH 5
#تعریف_کرو HOLLOW_BRUSH NULL_BRUSH
#تعریف_کرو WHITE_PEN 6
#تعریف_کرو BLACK_PEN 7
#تعریف_کرو NULL_PEN 8
#تعریف_کرو OEM_FIXED_FONT 10
#تعریف_کرو ANSI_FIXED_FONT 11
#تعریف_کرو ANSI_VAR_FONT 12
#تعریف_کرو SYSTEM_FONT 13
#تعریف_کرو DEVICE_DEFAULT_FONT 14
#تعریف_کرو DEFAULT_PALETTE 15
#تعریف_کرو SYSTEM_FIXED_FONT 16

#تعریف_کرو DEFAULT_GUI_FONT 17

#تعریف_کرو DC_BRUSH 18
#تعریف_کرو DC_PEN 19

#تعریف_کرو STOCK_آخری 19

#تعریف_کرو CLR_INVALID 0xFFFFFFFF

#تعریف_کرو BS_SOLID 0
#تعریف_کرو BS_NULL 1
#تعریف_کرو BS_HOLLOW BS_NULL
#تعریف_کرو BS_HATCHED 2
#تعریف_کرو BS_نمونہ 3
#تعریف_کرو BS_اشاریہ_دار 4
#تعریف_کرو BS_DIBPATTERN 5
#تعریف_کرو BS_DIBPATTERNPT 6
#تعریف_کرو BS_PATTERN8X8 7
#تعریف_کرو BS_DIBPATTERN8X8 8
#تعریف_کرو BS_MONOPATTERN 9

#تعریف_کرو HS_HORIZONTAL 0
#تعریف_کرو HS_VERTICAL 1
#تعریف_کرو HS_FDIAGONAL 2
#تعریف_کرو HS_BDIAGONAL 3
#تعریف_کرو HS_CROSS 4
#تعریف_کرو HS_DIAGCROSS 5

#تعریف_کرو PS_SOLID 0
#تعریف_کرو PS_DASH 1
#تعریف_کرو PS_DOT 2
#تعریف_کرو PS_DASHDOT 3
#تعریف_کرو PS_DASHDOTDOT 4
#تعریف_کرو PS_NULL 5
#تعریف_کرو PS_INSIDEFRAME 6
#تعریف_کرو PS_USERSTYLE 7
#تعریف_کرو PS_ALTERNATE 8
#تعریف_کرو PS_STYLE_نقاب 0x0000000F

#تعریف_کرو PS_ENDCAP_گیڑا 0x00000000
#تعریف_کرو PS_ENDCAP_مربع 0x00000100
#تعریف_کرو PS_ENDCAP_FLAT 0x00000200
#تعریف_کرو PS_ENDCAP_نقاب 0x00000F00

#تعریف_کرو PS_JOIN_گیڑا 0x00000000
#تعریف_کرو PS_JOIN_BEVEL 0x00001000
#تعریف_کرو PS_JOIN_MITER 0x00002000
#تعریف_کرو PS_JOIN_نقاب 0x0000F000

#تعریف_کرو PS_COSMETIC 0x00000000
#تعریف_کرو PS_GEOMETRIC 0x00010000
#تعریف_کرو PS_TYPE_نقاب 0x000F0000

#تعریف_کرو AD_COUNTERCLOCKWISE 1
#تعریف_کرو AD_CLOCKWISE 2

#تعریف_کرو DRIVERVERSION 0
#تعریف_کرو TECHNOLOGY 2
#تعریف_کرو HORZSIZE 4
#تعریف_کرو VERTSIZE 6
#تعریف_کرو HORZRES 8
#تعریف_کرو VERTRES 10
#تعریف_کرو BITSPIXEL 12
#تعریف_کرو PLANES 14
#تعریف_کرو NUMBRUSHES 16
#تعریف_کرو NUMPENS 18
#تعریف_کرو NUMMARKERS 20
#تعریف_کرو NUMFONTS 22
#تعریف_کرو NUMCOLORS 24
#تعریف_کرو PDEVICESIZE 26
#تعریف_کرو CURVECAPS 28
#تعریف_کرو LINECAPS 30
#تعریف_کرو POLYGONALCAPS 32
#تعریف_کرو TEXTCAPS 34
#تعریف_کرو CLIPCAPS 36
#تعریف_کرو RASTERCAPS 38
#تعریف_کرو ASPECTX 40
#تعریف_کرو ASPECTY 42
#تعریف_کرو ASPECTXY 44

#تعریف_کرو LOGPIXELSX 88
#تعریف_کرو LOGPIXELSY 90

#تعریف_کرو SIZEPALETTE 104
#تعریف_کرو NUMRESERVED 106
#تعریف_کرو COLORRES 108

#تعریف_کرو PHYSICALWIDTH 110
#تعریف_کرو PHYSICALHEIGHT 111
#تعریف_کرو PHYSICALOFFSETX 112
#تعریف_کرو PHYSICALOFFSETY 113
#تعریف_کرو SCALINGFACTORX 114
#تعریف_کرو SCALINGFACTORY 115

#تعریف_کرو VREFRESH 116

#تعریف_کرو DESKTOPVERTRES 117

#تعریف_کرو DESKTOPHORZRES 118

#تعریف_کرو BLTALIGNMENT 119

#تعریف_کرو SHADEBLENDCAPS 120
#تعریف_کرو COLORMGMTCAPS 121

#جے_بنا_تعریف NOGDICAPMASKS
#تعریف_کرو DT_PLOTTER 0
#تعریف_کرو DT_RASDISPLAY 1
#تعریف_کرو DT_RASPRINTER 2
#تعریف_کرو DT_RASCAMERA 3
#تعریف_کرو DT_CHARSTREAM 4
#تعریف_کرو DT_METAFILE 5
#تعریف_کرو DT_DISPFILE 6

#تعریف_کرو CC_NONE 0
#تعریف_کرو CC_CIRCLES 1
#تعریف_کرو CC_PIE 2
#تعریف_کرو CC_CHORD 4
#تعریف_کرو CC_ELLIPSES 8
#تعریف_کرو CC_WIDE 16
#تعریف_کرو CC_STYLED 32
#تعریف_کرو CC_WIDESTYLED 64
#تعریف_کرو CC_INTERIORS 128
#تعریف_کرو CC_ROUNDRECT 256

#تعریف_کرو LC_NONE 0
#تعریف_کرو LC_POLYLINE 2
#تعریف_کرو LC_MARKER 4
#تعریف_کرو LC_POLYMARKER 8
#تعریف_کرو LC_WIDE 16
#تعریف_کرو LC_STYLED 32
#تعریف_کرو LC_WIDESTYLED 64
#تعریف_کرو LC_INTERIORS 128

#تعریف_کرو PC_NONE 0
#تعریف_کرو PC_POLYGON 1
#تعریف_کرو PC_RECTANGLE 2
#تعریف_کرو PC_WINDPOLYGON 4
#تعریف_کرو PC_TRAPEZOID 4
#تعریف_کرو PC_SCANLINE 8
#تعریف_کرو PC_WIDE 16
#تعریف_کرو PC_STYLED 32
#تعریف_کرو PC_WIDESTYLED 64
#تعریف_کرو PC_INTERIORS 128
#تعریف_کرو PC_POLYPOLYGON 256
#تعریف_کرو PC_PATHS 512

#تعریف_کرو CP_NONE 0
#تعریف_کرو CP_RECTANGLE 1
#تعریف_کرو CP_REGION 2

#تعریف_کرو TC_OP_CHARACTER 0x00000001
#تعریف_کرو TC_OP_STROKE 0x00000002
#تعریف_کرو TC_CP_STROKE 0x00000004
#تعریف_کرو TC_CR_90 0x00000008
#تعریف_کرو TC_CR_ANY 0x00000010
#تعریف_کرو TC_SF_X_YINDEP 0x00000020
#تعریف_کرو TC_SA_DOUBLE 0x00000040
#تعریف_کرو TC_SA_INTEGER 0x00000080
#تعریف_کرو TC_SA_CONTIN 0x00000100
#تعریف_کرو TC_EA_DOUBLE 0x00000200
#تعریف_کرو TC_IA_ABLE 0x00000400
#تعریف_کرو TC_UA_ABLE 0x00000800
#تعریف_کرو TC_SO_ABLE 0x00001000
#تعریف_کرو TC_RA_ABLE 0x00002000
#تعریف_کرو TC_VA_ABLE 0x00004000
#تعریف_کرو TC_RESERVED 0x00008000
#تعریف_کرو TC_SCROLLBLT 0x00010000
#جے_انت

#تعریف_کرو RC_NONE
#تعریف_کرو RC_BITBLT 1
#تعریف_کرو RC_BANDING 2
#تعریف_کرو RC_SCALING 4
#تعریف_کرو RC_BITMAP64 8
#تعریف_کرو RC_GDI20_OUTPUT 0x0010
#تعریف_کرو RC_GDI20_STATE 0x0020
#تعریف_کرو RC_SAVEBITMAP 0x0040
#تعریف_کرو RC_DI_BITMAP 0x0080
#تعریف_کرو RC_PALETTE 0x0100
#تعریف_کرو RC_DIBTODEV 0x0200
#تعریف_کرو RC_BIGFONT 0x0400
#تعریف_کرو RC_STRETCHBLT 0x0800
#تعریف_کرو RC_FLOODFILL 0x1000
#تعریف_کرو RC_STRETCHDIB 0x2000
#تعریف_کرو RC_OP_DX_OUTPUT 0x4000
#تعریف_کرو RC_DEVBITS 0x8000

#تعریف_کرو SB_NONE 0x00000000
#تعریف_کرو SB_CONST_ALPHA 0x00000001
#تعریف_کرو SB_PIXEL_ALPHA 0x00000002
#تعریف_کرو SB_PREMULT_ALPHA 0x00000004

#تعریف_کرو SB_GRAD_RECT 0x00000010
#تعریف_کرو SB_GRAD_TRI 0x00000020

#تعریف_کرو CM_NONE 0x00000000
#تعریف_کرو CM_DEVICE_ICM 0x00000001
#تعریف_کرو CM_GAMMA_RAMP 0x00000002
#تعریف_کرو CM_CMYK_COLOR 0x00000004

#تعریف_کرو DIB_RGB_COLORS 0
#تعریف_کرو DIB_PAL_COLORS 1

#تعریف_کرو SYSPAL_ERROR 0
#تعریف_کرو SYSPAL_STATIC 1
#تعریف_کرو SYSPAL_NOSTATIC 2
#تعریف_کرو SYSPAL_NOSTATIC256 3

#تعریف_کرو CBM_INIT 0x04L

#تعریف_کرو FLOODFILLBORDER 0
#تعریف_کرو FLOODFILLSURFACE 1

#تعریف_کرو CCHDEVICENAME 32

#تعریف_کرو CCHFORMNAME 32

  تعريفنوع بنية _devicemodeA {
    BYTE dmDeviceName[CCHDEVICENAME];
    لفظ_3 dm_Spec_نسخہ;
    لفظ_3 dm_Driver_نسخہ;
    لفظ_3 dm_ناپ;
    لفظ_3 dmDriverExtra;
    DWORD dmFields;
    اتحاد {
      بنية {
        چھوٹا dmOrientation;
        چھوٹا dm_Paper_ناپ;
        چھوٹا dm_Paper_لمائی;
        چھوٹا dm_Paper_چوڑائی;
        چھوٹا dmScale;
        چھوٹا dmCopies;
        چھوٹا dm_Default_سروت;
        چھوٹا dmPrintQuality;
      };
      بنية {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    چھوٹا dmColor;
    چھوٹا dmDuplex;
    چھوٹا dmYResolution;
    چھوٹا dmTTOption;
    چھوٹا dmCollate;
    BYTE dmFormName[CCHFORMNAME];
    لفظ_3 dmLogPixels;
    DWORD dm_بٹ_فی_Pel;
    DWORD dm_Pels_چوڑائی;
    DWORD dm_Pels_اچائی;
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
    DWORD dm_Panning_چوڑائی;
    DWORD dm_Panning_اچائی;
  } DEVMODEA,*PDEVMODEA,*NPDEVMODEA,*LPDEVMODEA;

  تعريفنوع بنية _devicemodeW {
    WCHAR dmDeviceName[CCHDEVICENAME];
    لفظ_3 dm_Spec_نسخہ;
    لفظ_3 dm_Driver_نسخہ;
    لفظ_3 dm_ناپ;
    لفظ_3 dmDriverExtra;
    DWORD dmFields;
    اتحاد {
      بنية {
        چھوٹا dmOrientation;
        چھوٹا dm_Paper_ناپ;
        چھوٹا dm_Paper_لمائی;
        چھوٹا dm_Paper_چوڑائی;
        چھوٹا dmScale;
        چھوٹا dmCopies;
        چھوٹا dm_Default_سروت;
        چھوٹا dmPrintQuality;
      };
      بنية {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    چھوٹا dmColor;
    چھوٹا dmDuplex;
    چھوٹا dmYResolution;
    چھوٹا dmTTOption;
    چھوٹا dmCollate;
    WCHAR dmFormName[CCHFORMNAME];
    لفظ_3 dmLogPixels;
    DWORD dm_بٹ_فی_Pel;
    DWORD dm_Pels_چوڑائی;
    DWORD dm_Pels_اچائی;
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
    DWORD dm_Panning_چوڑائی;
    DWORD dm_Panning_اچائی;
  } DEVMODEW,*PDEVMODEW,*NPDEVMODEW,*LPDEVMODEW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع DEVMODEW DEVMODE;
  تعريفنوع PDEVMODEW PDEVMODE;
  تعريفنوع NPDEVMODEW NPDEVMODE;
  تعريفنوع LPDEVMODEW LPDEVMODE;
#وإلا
  تعريفنوع DEVMODEA DEVMODE;
  تعريفنوع PDEVMODEA PDEVMODE;
  تعريفنوع NPDEVMODEA NPDEVMODE;
  تعريفنوع LPDEVMODEA LPDEVMODE;
#جے_انت

#تعریف_کرو DM_SPECVERSION 0x0401

#تعریف_کرو DM_ORIENTATION 0x00000001L
#تعریف_کرو DM_PAPERSIZE 0x00000002L
#تعریف_کرو DM_PAPERLENGTH 0x00000004L
#تعریف_کرو DM_PAPERWIDTH 0x00000008L
#تعریف_کرو DM_SCALE 0x00000010L
#تعریف_کرو DM_POSITION 0x00000020L
#تعریف_کرو DM_NUP 0x00000040L
#تعریف_کرو DM_DISPLAYORIENTATION 0x00000080L
#تعریف_کرو DM_COPIES 0x00000100L
#تعریف_کرو DM_DEFAULTSOURCE 0x00000200L
#تعریف_کرو DM_PRINTQUALITY 0x00000400L
#تعریف_کرو DM_COLOR 0x00000800L
#تعریف_کرو DM_DUPLEX 0x00001000L
#تعریف_کرو DM_YRESOLUTION 0x00002000L
#تعریف_کرو DM_TTOPTION 0x00004000L
#تعریف_کرو DM_COLLATE 0x00008000L
#تعریف_کرو DM_FORMNAME 0x00010000L
#تعریف_کرو DM_LOGPIXELS 0x00020000L
#تعریف_کرو DM_BITSPERPEL 0x00040000L
#تعریف_کرو DM_PELSWIDTH 0x00080000L
#تعریف_کرو DM_PELSHEIGHT 0x00100000L
#تعریف_کرو DM_DISPLAYFLAGS 0x00200000L
#تعریف_کرو DM_DISPLAYFREQUENCY 0x00400000L
#تعریف_کرو DM_ICMMETHOD 0x00800000L
#تعریف_کرو DM_ICMINTENT 0x01000000L
#تعریف_کرو DM_MEDIATYPE 0x02000000L
#تعریف_کرو DM_DITHERTYPE 0x04000000L
#تعریف_کرو DM_PANNINGWIDTH 0x08000000L
#تعریف_کرو DM_PANNINGHEIGHT 0x10000000L
#تعریف_کرو DM_DISPLAYFIXEDOUTPUT 0x20000000L

#تعریف_کرو DMORIENT_PORTRAIT 1
#تعریف_کرو DMORIENT_LANDSCAPE 2

#تعریف_کرو DMPAPER_پہلا DMPAPER_LETTER
#تعریف_کرو DMPAPER_LETTER 1
#تعریف_کرو DMPAPER_LETTERSMALL 2
#تعریف_کرو DMPAPER_TABLOID 3
#تعریف_کرو DMPAPER_LEDGER 4
#تعریف_کرو DMPAPER_LEGAL 5
#تعریف_کرو DMPAPER_STATEMENT 6
#تعریف_کرو DMPAPER_EXECUTIVE 7
#تعریف_کرو DMPAPER_A3 8
#تعریف_کرو DMPAPER_A4 9
#تعریف_کرو DMPAPER_A4SMALL 10
#تعریف_کرو DMPAPER_A5 11
#تعریف_کرو DMPAPER_B4 12
#تعریف_کرو DMPAPER_B5 13
#تعریف_کرو DMPAPER_FOLIO 14
#تعریف_کرو DMPAPER_QUARTO 15
#تعریف_کرو DMPAPER_10X14 16
#تعریف_کرو DMPAPER_11X17 17
#تعریف_کرو DMPAPER_NOTE 18
#تعریف_کرو DMPAPER_ENV_9 19
#تعریف_کرو DMPAPER_ENV_10 20
#تعریف_کرو DMPAPER_ENV_11 21
#تعریف_کرو DMPAPER_ENV_12 22
#تعریف_کرو DMPAPER_ENV_14 23
#تعریف_کرو DMPAPER_CSHEET 24
#تعریف_کرو DMPAPER_DSHEET 25
#تعریف_کرو DMPAPER_ESHEET 26
#تعریف_کرو DMPAPER_ENV_DL 27
#تعریف_کرو DMPAPER_ENV_C5 28
#تعریف_کرو DMPAPER_ENV_C3 29
#تعریف_کرو DMPAPER_ENV_C4 30
#تعریف_کرو DMPAPER_ENV_C6 31
#تعریف_کرو DMPAPER_ENV_C65 32
#تعریف_کرو DMPAPER_ENV_B4 33
#تعریف_کرو DMPAPER_ENV_B5 34
#تعریف_کرو DMPAPER_ENV_B6 35
#تعریف_کرو DMPAPER_ENV_ITALY 36
#تعریف_کرو DMPAPER_ENV_MONARCH 37
#تعریف_کرو DMPAPER_ENV_PERSONAL 38
#تعریف_کرو DMPAPER_FANFOLD_US 39
#تعریف_کرو DMPAPER_FANFOLD_STD_GERMAN 40
#تعریف_کرو DMPAPER_FANFOLD_LGL_GERMAN 41
#تعریف_کرو DMPAPER_ISO_B4 42
#تعریف_کرو DMPAPER_JAPANESE_POSTCARD 43
#تعریف_کرو DMPAPER_9X11 44
#تعریف_کرو DMPAPER_10X11 45
#تعریف_کرو DMPAPER_15X11 46
#تعریف_کرو DMPAPER_ENV_INVITE 47
#تعریف_کرو DMPAPER_RESERVED_48 48
#تعریف_کرو DMPAPER_RESERVED_49 49
#تعریف_کرو DMPAPER_LETTER_EXTRA 50
#تعریف_کرو DMPAPER_LEGAL_EXTRA 51
#تعریف_کرو DMPAPER_TABLOID_EXTRA 52
#تعریف_کرو DMPAPER_A4_EXTRA 53
#تعریف_کرو DMPAPER_LETTER_TRANSVERSE 54
#تعریف_کرو DMPAPER_A4_TRANSVERSE 55
#تعریف_کرو DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#تعریف_کرو DMPAPER_A_PLUS 57
#تعریف_کرو DMPAPER_B_PLUS 58
#تعریف_کرو DMPAPER_LETTER_PLUS 59
#تعریف_کرو DMPAPER_A4_PLUS 60
#تعریف_کرو DMPAPER_A5_TRANSVERSE 61
#تعریف_کرو DMPAPER_B5_TRANSVERSE 62
#تعریف_کرو DMPAPER_A3_EXTRA 63
#تعریف_کرو DMPAPER_A5_EXTRA 64
#تعریف_کرو DMPAPER_B5_EXTRA 65
#تعریف_کرو DMPAPER_A2 66
#تعریف_کرو DMPAPER_A3_TRANSVERSE 67
#تعریف_کرو DMPAPER_A3_EXTRA_TRANSVERSE 68
#تعریف_کرو DMPAPER_DBL_JAPANESE_POSTCARD 69
#تعریف_کرو DMPAPER_A6 70
#تعریف_کرو DMPAPER_JENV_KAKU2 71
#تعریف_کرو DMPAPER_JENV_KAKU3 72
#تعریف_کرو DMPAPER_JENV_CHOU3 73
#تعریف_کرو DMPAPER_JENV_CHOU4 74
#تعریف_کرو DMPAPER_LETTER_ROTATED 75
#تعریف_کرو DMPAPER_A3_ROTATED 76
#تعریف_کرو DMPAPER_A4_ROTATED 77
#تعریف_کرو DMPAPER_A5_ROTATED 78
#تعریف_کرو DMPAPER_B4_JIS_ROTATED 79
#تعریف_کرو DMPAPER_B5_JIS_ROTATED 80
#تعریف_کرو DMPAPER_JAPANESE_POSTCARD_ROTATED 81
#تعریف_کرو DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#تعریف_کرو DMPAPER_A6_ROTATED 83
#تعریف_کرو DMPAPER_JENV_KAKU2_ROTATED 84
#تعریف_کرو DMPAPER_JENV_KAKU3_ROTATED 85
#تعریف_کرو DMPAPER_JENV_CHOU3_ROTATED 86
#تعریف_کرو DMPAPER_JENV_CHOU4_ROTATED 87
#تعریف_کرو DMPAPER_B6_JIS 88
#تعریف_کرو DMPAPER_B6_JIS_ROTATED 89
#تعریف_کرو DMPAPER_12X11 90
#تعریف_کرو DMPAPER_JENV_YOU4 91
#تعریف_کرو DMPAPER_JENV_YOU4_ROTATED 92
#تعریف_کرو DMPAPER_P16K 93
#تعریف_کرو DMPAPER_P32K 94
#تعریف_کرو DMPAPER_P32KBIG 95
#تعریف_کرو DMPAPER_PENV_1 96
#تعریف_کرو DMPAPER_PENV_2 97
#تعریف_کرو DMPAPER_PENV_3 98
#تعریف_کرو DMPAPER_PENV_4 99
#تعریف_کرو DMPAPER_PENV_5 100
#تعریف_کرو DMPAPER_PENV_6 101
#تعریف_کرو DMPAPER_PENV_7 102
#تعریف_کرو DMPAPER_PENV_8 103
#تعریف_کرو DMPAPER_PENV_9 104
#تعریف_کرو DMPAPER_PENV_10 105
#تعریف_کرو DMPAPER_P16K_ROTATED 106
#تعریف_کرو DMPAPER_P32K_ROTATED 107
#تعریف_کرو DMPAPER_P32KBIG_ROTATED 108
#تعریف_کرو DMPAPER_PENV_1_ROTATED 109
#تعریف_کرو DMPAPER_PENV_2_ROTATED 110
#تعریف_کرو DMPAPER_PENV_3_ROTATED 111
#تعریف_کرو DMPAPER_PENV_4_ROTATED 112
#تعریف_کرو DMPAPER_PENV_5_ROTATED 113
#تعریف_کرو DMPAPER_PENV_6_ROTATED 114
#تعریف_کرو DMPAPER_PENV_7_ROTATED 115
#تعریف_کرو DMPAPER_PENV_8_ROTATED 116
#تعریف_کرو DMPAPER_PENV_9_ROTATED 117
#تعریف_کرو DMPAPER_PENV_10_ROTATED 118

#تعریف_کرو DMPAPER_آخری DMPAPER_PENV_10_ROTATED

#تعریف_کرو DMPAPER_USER 256

#تعریف_کرو DMBIN_پہلا DMBIN_اتلا
#تعریف_کرو DMBIN_اتلا 1
#تعریف_کرو DMBIN_ONLYONE 1
#تعریف_کرو DMBIN_ہیٹھلا 2
#تعریف_کرو DMBIN_درمیان 3
#تعریف_کرو DMBIN_MANUAL 4
#تعریف_کرو DMBIN_ENVELOPE 5
#تعریف_کرو DMBIN_ENVMANUAL 6
#تعریف_کرو DMBIN_AUTO 7
#تعریف_کرو DMBIN_TRACTOR 8
#تعریف_کرو DMBIN_SMALLFMT 9
#تعریف_کرو DMBIN_LARGEFMT 10
#تعریف_کرو DMBIN_LARGECAPACITY 11
#تعریف_کرو DMBIN_CASSETTE 14
#تعریف_کرو DMBIN_FORMSOURCE 15
#تعریف_کرو DMBIN_آخری DMBIN_FORMSOURCE

#تعریف_کرو DMBIN_USER 256

#تعریف_کرو DMRES_DRAFT (-1)
#تعریف_کرو DMRES_کم (-2)
#تعریف_کرو DMRES_MEDIUM (-3)
#تعریف_کرو DMRES_بلند (-4)

#تعریف_کرو DMCOLOR_MONOCHROME 1
#تعریف_کرو DMCOLOR_COLOR 2

#تعریف_کرو DMDUP_SIMPLEX 1
#تعریف_کرو DMDUP_VERTICAL 2
#تعریف_کرو DMDUP_HORIZONTAL 3

#تعریف_کرو DMTT_BITMAP 1
#تعریف_کرو DMTT_DOWNLOAD 2
#تعریف_کرو DMTT_SUBDEV 3
#تعریف_کرو DMTT_DOWNLOAD_OUTLINE 4

#تعریف_کرو DMCOLLATE_FALSE 0
#تعریف_کرو DMCOLLATE_TRUE 1

#تعریف_کرو DMDO_DEFAULT 0
#تعریف_کرو DMDO_90 1
#تعریف_کرو DMDO_180 2
#تعریف_کرو DMDO_270 3

#تعریف_کرو DMDFO_DEFAULT 0
#تعریف_کرو DMDFO_STRETCH 1
#تعریف_کرو DMDFO_CENTER 2

#تعریف_کرو DMDISPLAYFLAGS_TEXTMODE 0x00000004

#تعریف_کرو DMNUP_SYSTEM 1
#تعریف_کرو DMNUP_ONEUP 2

#تعریف_کرو DMICMMETHOD_NONE 1
#تعریف_کرو DMICMMETHOD_SYSTEM 2
#تعریف_کرو DMICMMETHOD_DRIVER 3
#تعریف_کرو DMICMMETHOD_DEVICE 4

#تعریف_کرو DMICMMETHOD_USER 256

#تعریف_کرو DMICM_SATURATE 1
#تعریف_کرو DMICM_CONTRAST 2
#تعریف_کرو DMICM_COLORIMETRIC 3
#تعریف_کرو DMICM_ABS_COLORIMETRIC 4

#تعریف_کرو DMICM_USER 256

#تعریف_کرو DMMEDIA_STANDARD 1
#تعریف_کرو DMMEDIA_TRANSPARENCY 2
#تعریف_کرو DMMEDIA_GLOSSY 3

#تعریف_کرو DMMEDIA_USER 256

#تعریف_کرو DMDITHER_NONE 1
#تعریف_کرو DMDITHER_COARSE 2
#تعریف_کرو DMDITHER_FINE 3
#تعریف_کرو DMDITHER_LINEART 4
#تعریف_کرو DMDITHER_ERRORDIFFUSION 5
#تعریف_کرو DMDITHER_RESERVED6 6
#تعریف_کرو DMDITHER_RESERVED7 7
#تعریف_کرو DMDITHER_RESERVED8 8
#تعریف_کرو DMDITHER_RESERVED9 9
#تعریف_کرو DMDITHER_GRAYSCALE 10

#تعریف_کرو DMDITHER_USER 256

  تعريفنوع بنية _DISPLAY_DEVICEA {
    DWORD cb;
    CHAR DeviceName[32];
    CHAR DeviceString[128];
    DWORD StateFlags;
    CHAR DeviceID[128];
    CHAR Device_کلید[128];
  } DISPLAY_DEVICEA,*PDISPLAY_DEVICEA,*LPDISPLAY_DEVICEA;
  تعريفنوع بنية _DISPLAY_DEVICEW {
    DWORD cb;
    WCHAR DeviceName[32];
    WCHAR DeviceString[128];
    DWORD StateFlags;
    WCHAR DeviceID[128];
    WCHAR Device_کلید[128];
  } DISPLAY_DEVICEW,*PDISPLAY_DEVICEW,*LPDISPLAY_DEVICEW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع DISPLAY_DEVICEW DISPLAY_DEVICE;
  تعريفنوع PDISPLAY_DEVICEW PDISPLAY_DEVICE;
  تعريفنوع LPDISPLAY_DEVICEW LPDISPLAY_DEVICE;
#وإلا
  تعريفنوع DISPLAY_DEVICEA DISPLAY_DEVICE;
  تعريفنوع PDISPLAY_DEVICEA PDISPLAY_DEVICE;
  تعريفنوع LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
#جے_انت

#تعریف_کرو DISPLAY_DEVICE_ATTACHED_منزل_DESKTOP 0x00000001
#تعریف_کرو DISPLAY_DEVICE_MULTI_DRIVER 0x00000002
#تعریف_کرو DISPLAY_DEVICE_PRIMARY_DEVICE 0x00000004
#تعریف_کرو DISPLAY_DEVICE_MIRRORING_DRIVER 0x00000008
#تعریف_کرو DISPLAY_DEVICE_VGA_COMPATIBLE 0x00000010
#تعریف_کرو DISPLAY_DEVICE_REMOVABLE 0x00000020
#تعریف_کرو DISPLAY_DEVICE_MODESPRUNED 0x08000000
#تعریف_کرو DISPLAY_DEVICE_REMOTE 0x04000000
#تعریف_کرو DISPLAY_DEVICE_DISCONNECT 0x02000000

#تعریف_کرو DISPLAY_DEVICE_سرگرم 0x00000001
#تعریف_کرو DISPLAY_DEVICE_ATTACHED 0x00000002

#تعریف_کرو RDH_RECTANGLES 1

  تعريفنوع بنية _RGNDATAHEADER {
    DWORD dw_ناپ;
    DWORD iType;
    DWORD n_گنتی;
    DWORD n_Rgn_ناپ;
    RECT rcBound;
  } RGNDATAHEADER,*PRGNDATAHEADER;

  تعريفنوع بنية _RGNDATA {
    RGNDATAHEADER rdh;
    حرف بفر_3[1];
  } RGNDATA,*PRGNDATA,*NPRGNDATA,*LPRGNDATA;

#تعریف_کرو SYSRGN 4

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

#جے_بنا_تعریف NOTEXTMETRIC

  تعريفنوع بنية _OUTLINETEXTMETRICA {
    UINT otm_ناپ;
    TEXTMETRICA otm_متن_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_نمبر;
    UINT otmfsSelection;
    UINT otmfsType;
    صحيح otms_Char_ڈھلوان_Rise;
    صحيح otms_Char_ڈھلوان_لگاتار;
    صحيح otmItalicAngle;
    UINT otmEMSquare;
    صحيح otmAscent;
    صحيح otmDescent;
    UINT otm_سطر_Gap;
    UINT otms_Cap_Em_اچائی;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    صحيح otmMacAscent;
    صحيح otmMacDescent;
    UINT otm_Mac_سطر_Gap;
    UINT otmusMinimumPPEM;
    نقطہ_3 otmpt_Subscript_ناپ;
    نقطہ_3 otmpt_Subscript_وتھ;
    نقطہ_3 otmpt_Superscript_ناپ;
    نقطہ_3 otmpt_Superscript_وتھ;
    UINT otms_Strikeout_ناپ;
    صحيح otmsStrikeoutPosition;
    صحيح otms_Underscore_ناپ;
    صحيح otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_بھریا_Name;
  } OUTLINETEXTMETRICA,*POUTLINETEXTMETRICA,*NPOUTLINETEXTMETRICA,*LPOUTLINETEXTMETRICA;

  تعريفنوع بنية _OUTLINETEXTMETRICW {
    UINT otm_ناپ;
    TEXTMETRICW otm_متن_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_نمبر;
    UINT otmfsSelection;
    UINT otmfsType;
    صحيح otms_Char_ڈھلوان_Rise;
    صحيح otms_Char_ڈھلوان_لگاتار;
    صحيح otmItalicAngle;
    UINT otmEMSquare;
    صحيح otmAscent;
    صحيح otmDescent;
    UINT otm_سطر_Gap;
    UINT otms_Cap_Em_اچائی;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    صحيح otmMacAscent;
    صحيح otmMacDescent;
    UINT otm_Mac_سطر_Gap;
    UINT otmusMinimumPPEM;
    نقطہ_3 otmpt_Subscript_ناپ;
    نقطہ_3 otmpt_Subscript_وتھ;
    نقطہ_3 otmpt_Superscript_ناپ;
    نقطہ_3 otmpt_Superscript_وتھ;
    UINT otms_Strikeout_ناپ;
    صحيح otmsStrikeoutPosition;
    صحيح otms_Underscore_ناپ;
    صحيح otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_بھریا_Name;
  } OUTLINETEXTMETRICW,*POUTLINETEXTMETRICW,*NPOUTLINETEXTMETRICW,*LPOUTLINETEXTMETRICW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع OUTLINETEXTMETRICW OUTLINETEXTMETRIC;
  تعريفنوع POUTLINETEXTMETRICW POUTLINETEXTMETRIC;
  تعريفنوع NPOUTLINETEXTMETRICW NPOUTLINETEXTMETRIC;
  تعريفنوع LPOUTLINETEXTMETRICW LPOUTLINETEXTMETRIC;
#وإلا
  تعريفنوع OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
  تعريفنوع POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
  تعريفنوع NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
  تعريفنوع LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
#جے_انت
#جے_انت

  تعريفنوع بنية ٹیگ_POLYTEXTA {
    صحيح x;
    صحيح y;
    UINT n;
    LPCSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    صحيح *pdx;
  } POLYTEXTA,*PPOLYTEXTA,*NPPOLYTEXTA,*LPPOLYTEXTA;

  تعريفنوع بنية ٹیگ_POLYTEXTW {
    صحيح x;
    صحيح y;
    UINT n;
    LPCWSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    صحيح *pdx;
  } POLYTEXTW,*PPOLYTEXTW,*NPPOLYTEXTW,*LPPOLYTEXTW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع POLYTEXTW POLYTEXT;
  تعريفنوع PPOLYTEXTW PPOLYTEXT;
  تعريفنوع NPPOLYTEXTW NPPOLYTEXT;
  تعريفنوع LPPOLYTEXTW LPPOLYTEXT;
#وإلا
  تعريفنوع POLYTEXTA POLYTEXT;
  تعريفنوع PPOLYTEXTA PPOLYTEXT;
  تعريفنوع NPPOLYTEXTA NPPOLYTEXT;
  تعريفنوع LPPOLYTEXTA LPPOLYTEXT;
#جے_انت

  تعريفنوع بنية _FIXED {
    لفظ_3 fract;
    چھوٹا قدر;
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
    نقطہ_3 gmptGlyphOrigin;
    چھوٹا gmCellIncX;
    چھوٹا gmCellIncY;
  } GLYPHMETRICS,*LPGLYPHMETRICS;

#تعریف_کرو GGO_METRICS 0
#تعریف_کرو GGO_BITMAP 1
#تعریف_کرو GGO_NATIVE 2
#تعریف_کرو GGO_BEZIER 3

#تعریف_کرو GGO_GRAY2_BITMAP 4
#تعریف_کرو GGO_GRAY4_BITMAP 5
#تعریف_کرو GGO_GRAY8_BITMAP 6
#تعریف_کرو GGO_GLYPH_اشاریہ 0x0080
#تعریف_کرو GGO_UNHINTED 0x0100

#تعریف_کرو TT_POLYGON_TYPE 24

#تعریف_کرو TT_PRIM_سطر 1
#تعریف_کرو TT_PRIM_QSPLINE 2
#تعریف_کرو TT_PRIM_CSPLINE 3

  تعريفنوع بنية ٹیگ_POINTFX {
    FIXED x;
    FIXED y;
  } POINTFX,*LPPOINTFX;

  تعريفنوع بنية ٹیگ_TTPOLYCURVE {
    لفظ_3 wType;
    لفظ_3 cpfx;
    POINTFX apfx[1];
  } TTPOLYCURVE,*LPTTPOLYCURVE;

  تعريفنوع بنية ٹیگ_TTPOLYGONHEADER {
    DWORD cb;
    DWORD dwType;
    POINTFX pfx_شروع;
  } TTPOLYGONHEADER,*LPTTPOLYGONHEADER;

#تعریف_کرو GCP_DBCS 0x0001
#تعریف_کرو GCP_REORDER 0x0002
#تعریف_کرو GCP_USEKERNING 0x0008
#تعریف_کرو GCP_GLYPHSHAPE 0x0010
#تعریف_کرو GCP_LIGATE 0x0020

#تعریف_کرو GCP_DIACRITIC 0x0100
#تعریف_کرو GCP_KASHIDA 0x0400
#تعریف_کرو GCP_ERROR 0x8000
#تعریف_کرو FLI_نقاب 0x103B

#تعریف_کرو GCP_JUSTIFY 0x00010000L

#تعریف_کرو FLI_GLYPHS 0x00040000L
#تعریف_کرو GCP_CLASSIN 0x00080000L
#تعریف_کرو GCP_MAXEXTENT 0x00100000L
#تعریف_کرو GCP_JUSTIFYIN 0x00200000L
#تعریف_کرو GCP_DISPLAYZWG 0x00400000L
#تعریف_کرو GCP_SYMSWAPOFF 0x00800000L
#تعریف_کرو GCP_NUMERICOVERRIDE 0x01000000L
#تعریف_کرو GCP_NEUTRALOVERRIDE 0x02000000L
#تعریف_کرو GCP_NUMERICSLATIN 0x04000000L
#تعریف_کرو GCP_NUMERICSLOCAL 0x08000000L

#تعریف_کرو GCPCLASS_LATIN 1
#تعریف_کرو GCPCLASS_HEBREW 2
#تعریف_کرو GCPCLASS_ARABIC 2
#تعریف_کرو GCPCLASS_NEUTRAL 3
#تعریف_کرو GCPCLASS_LOCALNUMBER 4
#تعریف_کرو GCPCLASS_LATINNUMBER 5
#تعریف_کرو GCPCLASS_LATINNUMERICTERMINATOR 6
#تعریف_کرو GCPCLASS_LATINNUMERICSEPARATOR 7
#تعریف_کرو GCPCLASS_NUMERICSEPARATOR 8
#تعریف_کرو GCPCLASS_PREBOUNDLTR 0x80
#تعریف_کرو GCPCLASS_PREBOUNDRTL 0x40
#تعریف_کرو GCPCLASS_POSTBOUNDLTR 0x20
#تعریف_کرو GCPCLASS_POSTBOUNDRTL 0x10

#تعریف_کرو GCPGLYPH_LINKBEFORE 0x8000
#تعریف_کرو GCPGLYPH_LINKAFTER 0x4000

  تعريفنوع بنية ٹیگ_GCP_RESULTSA {
    DWORD l_Struct_ناپ;
    LPSTR lp_باہرلا_String;
    UINT *lp_ترتیب;
    صحيح *lpDx;
    صحيح *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    صحيح nMaxFit;
  } GCP_RESULTSA,*LPGCP_RESULTSA;
  تعريفنوع بنية ٹیگ_GCP_RESULTSW {
    DWORD l_Struct_ناپ;
    LPWSTR lp_باہرلا_String;
    UINT *lp_ترتیب;
    صحيح *lpDx;
    صحيح *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    صحيح nMaxFit;
  } GCP_RESULTSW,*LPGCP_RESULTSW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع GCP_RESULTSW GCP_RESULTS;
  تعريفنوع LPGCP_RESULTSW LPGCP_RESULTS;
#وإلا
  تعريفنوع GCP_RESULTSA GCP_RESULTS;
  تعريفنوع LPGCP_RESULTSA LPGCP_RESULTS;
#جے_انت

  تعريفنوع بنية RASTERIZER_حالت {
    چھوٹا n_ناپ;
    چھوٹا wFlags;
    چھوٹا nLanguageID;
  } RASTERIZER_حالت_2,*LPRASTERIZER_حالت;

#تعریف_کرو TT_دستیاب 0x0001
#تعریف_کرو TT_ENABLED 0x0002

  تعريفنوع بنية ٹیگ_PIXELFORMATDESCRIPTOR {
    لفظ_3 n_ناپ;
    لفظ_3 n_نسخہ;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_بٹ;
    BYTE c_Red_بٹ;
    BYTE c_Red_کھسکاؤ;
    BYTE c_Green_بٹ;
    BYTE c_Green_کھسکاؤ;
    BYTE c_Blue_بٹ;
    BYTE c_Blue_کھسکاؤ;
    BYTE c_Alpha_بٹ;
    BYTE c_Alpha_کھسکاؤ;
    BYTE c_Accum_بٹ;
    BYTE c_Accum_Red_بٹ;
    BYTE c_Accum_Green_بٹ;
    BYTE c_Accum_Blue_بٹ;
    BYTE c_Accum_Alpha_بٹ;
    BYTE c_ڈونگھائی_بٹ;
    BYTE c_Stencil_بٹ;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dw_Layer_نقاب;
    DWORD dw_Visible_نقاب;
    DWORD dw_Damage_نقاب;
  } PIXELFORMATDESCRIPTOR,*PPIXELFORMATDESCRIPTOR,*LPPIXELFORMATDESCRIPTOR;

#تعریف_کرو PFD_TYPE_RGBA 0
#تعریف_کرو PFD_TYPE_COLORINDEX 1

#تعریف_کرو PFD_MAIN_PLANE 0
#تعریف_کرو PFD_OVERLAY_PLANE 1
#تعریف_کرو PFD_UNDERLAY_PLANE (-1)

#تعریف_کرو PFD_DOUBLEBUFFER 0x00000001
#تعریف_کرو PFD_STEREO 0x00000002
#تعریف_کرو PFD_DRAW_منزل_کھڑکی 0x00000004
#تعریف_کرو PFD_DRAW_منزل_BITMAP 0x00000008
#تعریف_کرو PFD_SUPPORT_GDI 0x00000010
#تعریف_کرو PFD_SUPPORT_OPENGL 0x00000020
#تعریف_کرو PFD_GENERIC_FORMAT 0x00000040
#تعریف_کرو PFD_NEED_PALETTE 0x00000080
#تعریف_کرو PFD_NEED_SYSTEM_PALETTE 0x00000100
#تعریف_کرو PFD_وٹاندرا_EXCHANGE 0x00000200
#تعریف_کرو PFD_وٹاندرا_COPY 0x00000400
#تعریف_کرو PFD_وٹاندرا_LAYER_BUFFERS 0x00000800
#تعریف_کرو PFD_GENERIC_ACCELERATED 0x00001000
#تعریف_کرو PFD_SUPPORT_DIRECTDRAW 0x00002000

#تعریف_کرو PFD_ڈونگھائی_DONTCARE 0x20000000
#تعریف_کرو PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#تعریف_کرو PFD_STEREO_DONTCARE 0x80000000

#جے_بنا_تعریف NOTEXTMETRIC
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST TEXTMETRICA *,DWORD,LPARAM);
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST TEXTMETRICW *,DWORD,LPARAM);
#جے_تعریف_شدہ UNICODE
#تعریف_کرو OLDFONTENUMPROC OLDFONTENUMPROCW
#وإلا
#تعریف_کرو OLDFONTENUMPROC OLDFONTENUMPROCA
#جے_انت
#وإلا
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST VOID *,DWORD,LPARAM);
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST VOID *,DWORD,LPARAM);
#جے_تعریف_شدہ UNICODE
#تعریف_کرو OLDFONTENUMPROC OLDFONTENUMPROCW
#وإلا
#تعریف_کرو OLDFONTENUMPROC OLDFONTENUMPROCA
#جے_انت
#جے_انت

  تعريفنوع OLDFONTENUMPROCA FONTENUMPROCA;
  تعريفنوع OLDFONTENUMPROCW FONTENUMPROCW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع FONTENUMPROCW FONTENUMPROC;
#وإلا
  تعريفنوع FONTENUMPROCA FONTENUMPROC;
#جے_انت

  تعريفنوع صحيح (CALLBACK *GOBJENUMPROC)(LPVOID,LPARAM);
  تعريفنوع VOID (CALLBACK *LINEDDAPROC)(صحيح,صحيح,LPARAM);

#جے_تعریف_شدہ UNICODE
#تعریف_کرو جوڑو_Font_Resource جوڑو_Font_Resource_W
#تعریف_کرو CopyMetaFile CopyMetaFileW
#تعریف_کرو CreateDC CreateDCW
#تعریف_کرو Create_Font_اسدھا Create_Font_اسدھا_W
#تعریف_کرو CreateFont CreateFontW
#تعریف_کرو CreateIC CreateICW
#تعریف_کرو CreateMetaFile CreateMetaFileW
#تعریف_کرو CreateScalableFontResource CreateScalableFontResourceW
#وإلا
#تعریف_کرو جوڑو_Font_Resource جوڑو_Font_Resource_A
#تعریف_کرو CopyMetaFile CopyMetaFileA
#تعریف_کرو CreateDC CreateDCA
#تعریف_کرو Create_Font_اسدھا Create_Font_اسدھا_A
#تعریف_کرو CreateFont CreateFontA
#تعریف_کرو CreateIC CreateICA
#تعریف_کرو CreateMetaFile CreateMetaFileA
#تعریف_کرو CreateScalableFontResource CreateScalableFontResourceA
#جے_انت

  WINGDIAPI صحيح WINAPI جوڑو_Font_Resource_A(LPCSTR);
  WINGDIAPI صحيح WINAPI جوڑو_Font_Resource_W(LPCWSTR);
  WINGDIAPI WINBOOL WINAPI AnimatePalette(HPALETTE hPal,UINT i_شروع_اشاریہ,UINT cEntries,CONST PALETTEENTRY *ppe);
  WINGDIAPI WINBOOL WINAPI Arc(HDC hdc,صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح x3,صحيح y3,صحيح x4,صحيح y4);
  WINGDIAPI WINBOOL WINAPI ثنائی_ہندسہ_Blt(HDC hdc,صحيح x,صحيح y,صحيح cx,صحيح cy,HDC hdcSrc,صحيح x1,صحيح y1,DWORD rop);
  WINGDIAPI WINBOOL WINAPI CancelDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Chord(HDC hdc,صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح x3,صحيح y3,صحيح x4,صحيح y4);
  WINGDIAPI صحيح WINAPI چنو_Pixel_Format(HDC hdc,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI HMETAFILE WINAPI CloseMetaFile(HDC hdc);
  WINGDIAPI صحيح WINAPI CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,صحيح i_منوال);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
  WINGDIAPI HBITMAP WINAPI CreateBitmap(صحيح n_چوڑائی,صحيح n_اچائی,UINT nPlanes,UINT n_ثنائی_ہندسہ_گنتی,CONST VOID *lp_بٹ);
  WINGDIAPI HBITMAP WINAPI Create_Bitmap_اسدھا(CONST BITMAP *pbm);
  WINGDIAPI HBRUSH WINAPI Create_Brush_اسدھا(CONST LOGBRUSH *plbrush);
  WINGDIAPI HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc,صحيح cx,صحيح cy);
  WINGDIAPI HBITMAP WINAPI CreateDiscardableBitmap(HDC hdc,صحيح cx,صحيح cy);
  WINGDIAPI HDC WINAPI CreateCompatibleDC(HDC hdc);
  WINGDIAPI HDC WINAPI CreateDCA(LPCSTR pwszDriver,LPCSTR pwszDevice,LPCSTR psz_پورٹ,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateDCW(LPCWSTR pwszDriver,LPCWSTR pwszDevice,LPCWSTR psz_پورٹ,CONST DEVMODEW *pdm);
  WINGDIAPI HBITMAP WINAPI CreateDIBitmap(HDC hdc,CONST BITMAPINFOHEADER *pbmih,DWORD flInit,CONST VOID *pj_بٹ,CONST BITMAPINFO *pbmi,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL h,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB,UINT iUsage);
  WINGDIAPI HRGN WINAPI CreateEllipticRgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2);
  WINGDIAPI HRGN WINAPI Create_Elliptic_Rgn_اسدھا(CONST RECT *lprect);
  WINGDIAPI HFONT WINAPI Create_Font_اسدھا_A(CONST LOGFONTA *lplf);
  WINGDIAPI HFONT WINAPI Create_Font_اسدھا_W(CONST LOGFONTW *lplf);
  WINGDIAPI HFONT WINAPI CreateFontA(صحيح c_اچائی,صحيح c_چوڑائی,صحيح cEscapement,صحيح cOrientation,صحيح c_بھار,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_باہرلا,DWORD i_Char_سیٹ,DWORD i_باہرلا_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCSTR pszFaceName);
  WINGDIAPI HFONT WINAPI CreateFontW(صحيح c_اچائی,صحيح c_چوڑائی,صحيح cEscapement,صحيح cOrientation,صحيح c_بھار,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_باہرلا,DWORD i_Char_سیٹ,DWORD i_باہرلا_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCWSTR pszFaceName);
  WINGDIAPI HBRUSH WINAPI CreateHatchBrush(صحيح iHatch,COLORREF color);
  WINGDIAPI HDC WINAPI CreateICA(LPCSTR pszDriver,LPCSTR pszDevice,LPCSTR psz_پورٹ,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateICW(LPCWSTR pszDriver,LPCWSTR pszDevice,LPCWSTR psz_پورٹ,CONST DEVMODEW *pdm);
  WINGDIAPI HDC WINAPI CreateMetaFileA(LPCSTR pszFile);
  WINGDIAPI HDC WINAPI CreateMetaFileW(LPCWSTR pszFile);
  WINGDIAPI HPALETTE WINAPI CreatePalette(CONST LOGPALETTE *plpal);
  WINGDIAPI HPEN WINAPI CreatePen(صحيح iStyle,صحيح c_چوڑائی,COLORREF color);
  WINGDIAPI HPEN WINAPI Create_Pen_اسدھا(CONST LOGPEN *plpen);
  WINGDIAPI HRGN WINAPI CreatePolyPolygonRgn(CONST نقطہ_3 *pptl,CONST INT *pc,صحيح cPoly,صحيح i_منوال);
  WINGDIAPI HBRUSH WINAPI Create_نمونہ_Brush(HBITMAP hbm);
  WINGDIAPI HRGN WINAPI CreateRectRgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2);
  WINGDIAPI HRGN WINAPI Create_Rect_Rgn_اسدھا(CONST RECT *lprect);
  WINGDIAPI HRGN WINAPI Create_گیڑا_Rect_Rgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح w,صحيح h);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceA(DWORD fdwHidden,LPCSTR lpszFont,LPCSTR lpszFile,LPCSTR lpsz_رستہ);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceW(DWORD fdwHidden,LPCWSTR lpszFont,LPCWSTR lpszFile,LPCWSTR lpsz_رستہ);
  WINGDIAPI HBRUSH WINAPI CreateSolidBrush(COLORREF color);
  WINGDIAPI WINBOOL WINAPI DeleteDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI DeleteMetaFile(HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI DeleteObject(HGDIOBJ ho);
  WINGDIAPI صحيح WINAPI DescribePixelFormat(HDC hdc,صحيح iPixelFormat,UINT n_بائٹاں,LPPIXELFORMATDESCRIPTOR ppfd);

  تعريفنوع UINT (CALLBACK *LPFNDEVMODE)(HWND,HMODULE,LPDEVMODE,LPSTR,LPSTR,LPDEVMODE,LPSTR,UINT);
  تعريفنوع DWORD (CALLBACK *LPFNDEVCAPS)(LPSTR,LPSTR,UINT,LPSTR,LPDEVMODE);

#تعریف_کرو DM_UPDATE 1
#تعریف_کرو DM_COPY 2
#تعریف_کرو DM_PROMPT 4
#تعریف_کرو DM_MODIFY 8

#تعریف_کرو DM_وچ_بفر DM_MODIFY
#تعریف_کرو DM_وچ_PROMPT DM_PROMPT
#تعریف_کرو DM_باہرلا_بفر DM_COPY
#تعریف_کرو DM_باہرلا_DEFAULT DM_UPDATE

#تعریف_کرو DC_FIELDS 1
#تعریف_کرو DC_PAPERS 2
#تعریف_کرو DC_PAPERSIZE 3
#تعریف_کرو DC_MINEXTENT 4
#تعریف_کرو DC_MAXEXTENT 5
#تعریف_کرو DC_BINS 6
#تعریف_کرو DC_DUPLEX 7
#تعریف_کرو DC_ناپ 8
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
#تعریف_کرو DC_BINADJUST 19
#تعریف_کرو DC_EMF_COMPLIANT 20
#تعریف_کرو DC_DATATYPE_PRODUCED 21
#تعریف_کرو DC_COLLATE 22
#تعریف_کرو DC_MANUFACTURER 23
#تعریف_کرو DC_MODEL 24
#تعریف_کرو DC_PERSONALITY 25
#تعریف_کرو DC_PRINTRATE 26
#تعریف_کرو DC_PRINTRATEUNIT 27
#تعریف_کرو PRINTRATEUNIT_PPM 1
#تعریف_کرو PRINTRATEUNIT_CPS 2
#تعریف_کرو PRINTRATEUNIT_LPM 3
#تعریف_کرو PRINTRATEUNIT_IPM 4
#تعریف_کرو DC_PRINTERMEM 28
#تعریف_کرو DC_MEDIAREADY 29
#تعریف_کرو DC_STAPLE 30
#تعریف_کرو DC_PRINTRATEPPM 31
#تعریف_کرو DC_COLORDEVICE 32
#تعریف_کرو DC_NUP 33
#تعریف_کرو DC_MEDIATYPENAMES 34
#تعریف_کرو DC_MEDIATYPES 35

#تعریف_کرو DCTT_BITMAP 0x0000001L
#تعریف_کرو DCTT_DOWNLOAD 0x0000002L
#تعریف_کرو DCTT_SUBDEV 0x0000004L
#تعریف_کرو DCTT_DOWNLOAD_OUTLINE 0x0000008L

#تعریف_کرو DCBA_FACEUPNONE 0x0000
#تعریف_کرو DCBA_FACEUPCENTER 0x0001
#تعریف_کرو DCBA_FACEUPLEFT 0x0002
#تعریف_کرو DCBA_FACEUPRIGHT 0x0003
#تعریف_کرو DCBA_FACEDOWNNONE 0x0100
#تعریف_کرو DCBA_FACEDOWNCENTER 0x0101
#تعریف_کرو DCBA_FACEDOWNLEFT 0x0102
#تعریف_کرو DCBA_FACEDOWNRIGHT 0x0103

#جے_تعریف_شدہ UNICODE
#تعریف_کرو DeviceCapabilities DeviceCapabilitiesW
#تعریف_کرو EnumFontFamiliesEx EnumFontFamiliesExW
#تعریف_کرو EnumFontFamilies EnumFontFamiliesW
#تعریف_کرو EnumFonts EnumFontsW
#تعریف_کرو Get_Char_چوڑائی Get_Char_چوڑائی_W
#تعریف_کرو GetCharWidth32 GetCharWidth32W
#تعریف_کرو Get_Char_چوڑائی_Float Get_Char_چوڑائی_Float_W
#تعریف_کرو GetCharABCWidths GetCharABCWidthsW
#تعریف_کرو GetCharABCWidthsFloat GetCharABCWidthsFloatW
#تعریف_کرو GetGlyphOutline GetGlyphOutlineW
#تعریف_کرو GetMetaFile GetMetaFileW
#وإلا
#تعریف_کرو DeviceCapabilities DeviceCapabilitiesA
#تعریف_کرو EnumFontFamiliesEx EnumFontFamiliesExA
#تعریف_کرو EnumFontFamilies EnumFontFamiliesA
#تعریف_کرو EnumFonts EnumFontsA
#تعریف_کرو Get_Char_چوڑائی Get_Char_چوڑائی_A
#تعریف_کرو GetCharWidth32 GetCharWidth32A
#تعریف_کرو Get_Char_چوڑائی_Float Get_Char_چوڑائی_Float_A
#تعریف_کرو GetCharABCWidths GetCharABCWidthsA
#تعریف_کرو GetCharABCWidthsFloat GetCharABCWidthsFloatA
#تعریف_کرو GetGlyphOutline GetGlyphOutlineA
#تعریف_کرو GetMetaFile GetMetaFileA
#جے_انت

  WINSPOOLAPI صحيح WINAPI DeviceCapabilitiesA(LPCSTR pDevice,LPCSTR p_پورٹ,لفظ_3 fwCapability,LPSTR pOutput,CONST DEVMODEA *p_Dev_منوال);
  WINSPOOLAPI صحيح WINAPI DeviceCapabilitiesW(LPCWSTR pDevice,LPCWSTR p_پورٹ,لفظ_3 fwCapability,LPWSTR pOutput,CONST DEVMODEW *p_Dev_منوال);
  WINGDIAPI صحيح WINAPI DrawEscape(HDC hdc,صحيح iEscape,صحيح cj_وچ,LPCSTR lp_وچ);
  WINGDIAPI WINBOOL WINAPI Ellipse(HDC hdc,صحيح بایاں,صحيح چوٹی,صحيح دایاں,صحيح bottom);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesExA(HDC hdc,LPLOGFONTA lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesExW(HDC hdc,LPLOGFONTW lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontsA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontsW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumObjects(HDC hdc,صحيح nType,GOBJENUMPROC lpFunc,LPARAM lParam);
  WINGDIAPI WINBOOL WINAPI EqualRgn(HRGN hrgn1,HRGN hrgn2);
  WINGDIAPI صحيح WINAPI Escape(HDC hdc,صحيح iEscape,صحيح cj_وچ,LPCSTR pv_وچ,LPVOID pv_باہرلا);
  WINGDIAPI صحيح WINAPI ExtEscape(HDC hdc,صحيح iEscape,صحيح cj_داخلہ,LPCSTR lp_وچ_انکڑے,صحيح cjOutput,LPSTR lp_باہرلا_انکڑے);
  WINGDIAPI صحيح WINAPI ExcludeClipRect(HDC hdc,صحيح بایاں,صحيح چوٹی,صحيح دایاں,صحيح bottom);
  WINGDIAPI HRGN WINAPI ExtCreateRegion(CONST XFORM *lpx,DWORD n_گنتی,CONST RGNDATA *lp_انکڑے);
  WINGDIAPI WINBOOL WINAPI ExtFloodFill(HDC hdc,صحيح x,صحيح y,COLORREF color,UINT type);
  WINGDIAPI WINBOOL WINAPI FillRgn(HDC hdc,HRGN hrgn,HBRUSH hbr);
  WINGDIAPI WINBOOL WINAPI FloodFill(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI چوکھٹا_Rgn(HDC hdc,HRGN hrgn,HBRUSH hbr,صحيح w,صحيح h);
  WINGDIAPI صحيح WINAPI GetROP2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_Aspect_تناسب_Filter_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI COLORREF WINAPI GetBkColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCBrushColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCPenColor(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Bk_منوال(HDC hdc);
  WINGDIAPI LONG WINAPI Get_Bitmap_بٹ(HBITMAP hbit,LONG cb,LPVOID lpv_بٹ);
  WINGDIAPI WINBOOL WINAPI GetBitmapDimensionEx(HBITMAP hbit,LPSIZE lpsize);
  WINGDIAPI UINT WINAPI GetBoundsRect(HDC hdc,LPRECT lprect,UINT flags);
  WINGDIAPI WINBOOL WINAPI GetBrushOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI Get_Char_چوڑائی_A(HDC hdc,UINT i_پہلا,UINT i_آخری,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI Get_Char_چوڑائی_W(HDC hdc,UINT i_پہلا,UINT i_آخری,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32A(HDC hdc,UINT i_پہلا,UINT i_آخری,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32W(HDC hdc,UINT i_پہلا,UINT i_آخری,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI Get_Char_چوڑائی_Float_A(HDC hdc,UINT i_پہلا,UINT i_آخری,PFLOAT lp_بفر);
  WINGDIAPI WINBOOL WINAPI Get_Char_چوڑائی_Float_W(HDC hdc,UINT i_پہلا,UINT i_آخری,PFLOAT lp_بفر);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsA(HDC hdc,UINT w_پہلا,UINT w_آخری,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsW(HDC hdc,UINT w_پہلا,UINT w_آخری,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatA(HDC hdc,UINT i_پہلا,UINT i_آخری,LPABCFLOAT lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatW(HDC hdc,UINT i_پہلا,UINT i_آخری,LPABCFLOAT lpABC);
  WINGDIAPI صحيح WINAPI GetClipBox(HDC hdc,LPRECT lprect);
  WINGDIAPI صحيح WINAPI GetClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI صحيح WINAPI GetMetaRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI HGDIOBJ WINAPI GetCurrentObject(HDC hdc,UINT type);
  WINGDIAPI WINBOOL WINAPI GetCurrentPositionEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI صحيح WINAPI GetDeviceCaps(HDC hdc,صحيح اشاریہ);
  WINGDIAPI صحيح WINAPI GetDIBits(HDC hdc,HBITMAP hbm,UINT شروع,UINT c_سطریں,LPVOID lpv_بٹ,LPBITMAPINFO lpbmi,UINT usage);
  WINGDIAPI DWORD WINAPI Get_Font_انکڑے (HDC hdc,DWORD dw_جدول,DWORD dw_وتھ,PVOID pv_بفر,DWORD cj_بفر);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineA(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_بفر,LPVOID pv_بفر,CONST MAT2 *lpmat2);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineW(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_بفر,LPVOID pv_بفر,CONST MAT2 *lpmat2);
  WINGDIAPI صحيح WINAPI Get_Graphics_منوال(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Map_منوال(HDC hdc);
  WINGDIAPI UINT WINAPI Get_Meta_File_بٹ_Ex(HMETAFILE hMF,UINT cb_بفر,LPVOID lp_انکڑے);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileA(LPCSTR lpName);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileW(LPCWSTR lpName);
  WINGDIAPI COLORREF WINAPI Get_سبھ_توں_نیڑے_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI Get_سبھ_توں_نیڑے_Palette_اشاریہ(HPALETTE h,COLORREF color);
  WINGDIAPI DWORD WINAPI GetObjectType(HGDIOBJ h);

#جے_بنا_تعریف NOTEXTMETRIC
#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_Outline_متن_Metrics Get_Outline_متن_Metrics_W
#وإلا
#تعریف_کرو Get_Outline_متن_Metrics Get_Outline_متن_Metrics_A
#جے_انت

  WINGDIAPI UINT WINAPI Get_Outline_متن_Metrics_A(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICA potm);
  WINGDIAPI UINT WINAPI Get_Outline_متن_Metrics_W(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICW potm);
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_متن_Extent_نقطہ Get_متن_Extent_نقطہ_W
#تعریف_کرو Get_متن_Extent_Point32 Get_متن_Extent_Point32_W
#تعریف_کرو Get_متن_Extent_Ex_نقطہ Get_متن_Extent_Ex_نقطہ_W
#تعریف_کرو GetCharacterPlacement GetCharacterPlacementW
#وإلا
#تعریف_کرو Get_متن_Extent_نقطہ Get_متن_Extent_نقطہ_A
#تعریف_کرو Get_متن_Extent_Point32 Get_متن_Extent_Point32_A
#تعریف_کرو Get_متن_Extent_Ex_نقطہ Get_متن_Extent_Ex_نقطہ_A
#تعریف_کرو GetCharacterPlacement GetCharacterPlacementA
#جے_انت

  WINGDIAPI UINT WINAPI GetPaletteEntries(HPALETTE hpal,UINT i_شروع,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI COLORREF WINAPI GetPixel(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI صحيح WINAPI GetPixelFormat(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Poly_Fill_منوال(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetRasterizerCaps(LPRASTERIZER_حالت lpraststat,UINT cj_بائٹاں);
  WINGDIAPI صحيح WINAPI GetRandomRgn (HDC hdc,HRGN hrgn,INT i);
  WINGDIAPI DWORD WINAPI Get_Region_انکڑے(HRGN hrgn,DWORD n_گنتی,LPRGNDATA lp_Rgn_انکڑے);
  WINGDIAPI صحيح WINAPI GetRgnBox(HRGN hrgn,LPRECT lprc);
  WINGDIAPI HGDIOBJ WINAPI GetStockObject(صحيح i);
  WINGDIAPI صحيح WINAPI Get_Stretch_Blt_منوال(HDC hdc);
  WINGDIAPI UINT WINAPI GetSystemPaletteEntries(HDC hdc,UINT i_شروع,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI UINT WINAPI GetSystemPaletteUse(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_متن_Character_Extra(HDC hdc);
  WINGDIAPI UINT WINAPI Get_متن_Align(HDC hdc);
  WINGDIAPI COLORREF WINAPI Get_متن_Color(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_نقطہ_A(HDC hdc,LPCSTR lpString,صحيح c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_نقطہ_W(HDC hdc,LPCWSTR lpString,صحيح c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Point32_A(HDC hdc,LPCSTR lpString,صحيح c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Point32_W(HDC hdc,LPCWSTR lpString,صحيح c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_نقطہ_A(HDC hdc,LPCSTR lpszString,صحيح cchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_ناپ);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_نقطہ_W(HDC hdc,LPCWSTR lpszString,صحيح cchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_ناپ);
  WINGDIAPI صحيح WINAPI Get_متن_Charset(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_متن_Charset_Info(HDC hdc,LPFONTSIGNATURE lpSig,DWORD dwFlags);
  WINGDIAPI WINBOOL WINAPI TranslateCharsetInfo(DWORD *lpSrc,LPCHARSETINFO lpCs,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetFontLanguageInfo(HDC hdc);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementA(HDC hdc,LPCSTR lpString,صحيح n_گنتی,صحيح nMexExtent,LPGCP_RESULTSA lpResults,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementW(HDC hdc,LPCWSTR lpString,صحيح n_گنتی,صحيح nMexExtent,LPGCP_RESULTSW lpResults,DWORD dwFlags);

  تعريفنوع بنية ٹیگ_WCRANGE {
    WCHAR wc_کم;
    USHORT cGlyphs;
  } WCRANGE,*PWCRANGE,*LPWCRANGE;

  تعريفنوع بنية ٹیگ_GLYPHSET {
    DWORD cbThis;
    DWORD flAccel;
    DWORD cGlyphsSupported;
    DWORD cRanges;
    WCRANGE ranges[1];
  } GLYPHSET,*PGLYPHSET,*LPGLYPHSET;

#تعریف_کرو GS_8_ثنائی_ہندسہ_INDICES 0x00000001

#تعریف_کرو GGI_MARK_NONEXISTING_GLYPHS 0X0001

#جے_تعریف_شدہ UNICODE
#تعریف_کرو GetGlyphIndices GetGlyphIndicesW
#وإلا
#تعریف_کرو GetGlyphIndices GetGlyphIndicesA
#جے_انت

  WINGDIAPI DWORD WINAPI GetFontUnicodeRanges(HDC hdc,LPGLYPHSET lpgs);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesA(HDC hdc,LPCSTR lpstr,صحيح c,LPWORD pgi,DWORD fl);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesW(HDC hdc,LPCWSTR lpstr,صحيح c,LPWORD pgi,DWORD fl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_نقطہ_I(HDC hdc,LPWORD pgi_وچ,صحيح cgi,LPSIZE psize);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_نقطہ_I (HDC hdc,LPWORD lpwszString,صحيح cwchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_ناپ);
  WINGDIAPI WINBOOL WINAPI Get_Char_چوڑائی_I(HDC hdc,UINT gi_پہلا,UINT cgi,LPWORD pgi,LPINT piWidths);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsI(HDC hdc,UINT gi_پہلا,UINT cgi,LPWORD pgi,LPABC pabc);

#تعریف_کرو STAMP_DESIGNVECTOR (0x8000000 + 'd' + ('v' << 8))
#تعریف_کرو STAMP_AXESLIST (0x8000000 + 'a' + ('l' << 8))
#تعریف_کرو MM_MAX_NUMAXES 16

  تعريفنوع بنية ٹیگ_DESIGNVECTOR {
    DWORD dvReserved;
    DWORD dv_عدد_Axes;
    LONG dv_اقدار[MM_MAX_NUMAXES];
  } DESIGNVECTOR,*PDESIGNVECTOR,*LPDESIGNVECTOR;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو جوڑو_Font_Resource_Ex جوڑو_Font_Resource_Ex_W
#تعریف_کرو RemoveFontResourceEx RemoveFontResourceExW
#وإلا
#تعریف_کرو جوڑو_Font_Resource_Ex جوڑو_Font_Resource_Ex_A
#تعریف_کرو RemoveFontResourceEx RemoveFontResourceExA
#جے_انت

  WINGDIAPI صحيح WINAPI جوڑو_Font_Resource_Ex_A(LPCSTR name,DWORD fl,PVOID res);
  WINGDIAPI صحيح WINAPI جوڑو_Font_Resource_Ex_W(LPCWSTR name,DWORD fl,PVOID res);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExA(LPCSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExW(LPCWSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI HANDLE WINAPI جوڑو_Font_Mem_Resource_Ex(PVOID pFileView,DWORD cj_ناپ,PVOID pvResrved,DWORD *p_عدد_Fonts);
  WINGDIAPI WINBOOL WINAPI RemoveFontMemResourceEx(HANDLE h);

#تعریف_کرو FR_نجی 0x10
#تعریف_کرو FR_NOT_ENUM 0x20

#تعریف_کرو MM_MAX_AXES_NAMELEN 16

  تعريفنوع بنية ٹیگ_AXISINFOA {
    LONG ax_Min_قدر;
    LONG ax_Max_قدر;
    BYTE axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOA,*PAXISINFOA,*LPAXISINFOA;

  تعريفنوع بنية ٹیگ_AXISINFOW {
    LONG ax_Min_قدر;
    LONG ax_Max_قدر;
    WCHAR axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOW,*PAXISINFOW,*LPAXISINFOW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع AXISINFOW AXISINFO;
  تعريفنوع PAXISINFOW PAXISINFO;
  تعريفنوع LPAXISINFOW LPAXISINFO;
#وإلا
  تعريفنوع AXISINFOA AXISINFO;
  تعريفنوع PAXISINFOA PAXISINFO;
  تعريفنوع LPAXISINFOA LPAXISINFO;
#جے_انت

  تعريفنوع بنية ٹیگ_AXESLISTA {
    DWORD axlReserved;
    DWORD axl_عدد_Axes;
    AXISINFOA axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTA,*PAXESLISTA,*LPAXESLISTA;

  تعريفنوع بنية ٹیگ_AXESLISTW {
    DWORD axlReserved;
    DWORD axl_عدد_Axes;
    AXISINFOW axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTW,*PAXESLISTW,*LPAXESLISTW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع AXESLISTW AXESLIST;
  تعريفنوع PAXESLISTW PAXESLIST;
  تعريفنوع LPAXESLISTW LPAXESLIST;
#وإلا
  تعريفنوع AXESLISTA AXESLIST;
  تعريفنوع PAXESLISTA PAXESLIST;
  تعريفنوع LPAXESLISTA LPAXESLIST;
#جے_انت

  تعريفنوع بنية ٹیگ_ENUMLOGFONTEXDVA {
    ENUMLOGFONTEXA elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_سمتیہ;
  } ENUMLOGFONTEXDVA,*PENUMLOGFONTEXDVA,*LPENUMLOGFONTEXDVA;

  تعريفنوع بنية ٹیگ_ENUMLOGFONTEXDVW {
    ENUMLOGFONTEXW elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_سمتیہ;
  } ENUMLOGFONTEXDVW,*PENUMLOGFONTEXDVW,*LPENUMLOGFONTEXDVW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع ENUMLOGFONTEXDVW ENUMLOGFONTEXDV;
  تعريفنوع PENUMLOGFONTEXDVW PENUMLOGFONTEXDV;
  تعريفنوع LPENUMLOGFONTEXDVW LPENUMLOGFONTEXDV;
#وإلا
  تعريفنوع ENUMLOGFONTEXDVA ENUMLOGFONTEXDV;
  تعريفنوع PENUMLOGFONTEXDVA PENUMLOGFONTEXDV;
  تعريفنوع LPENUMLOGFONTEXDVA LPENUMLOGFONTEXDV;
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Create_Font_اسدھا_Ex Create_Font_اسدھا_Ex_W
#وإلا
#تعریف_کرو Create_Font_اسدھا_Ex Create_Font_اسدھا_Ex_A
#جے_انت

  WINGDIAPI HFONT WINAPI Create_Font_اسدھا_Ex_A(CONST ENUMLOGFONTEXDVA *);
  WINGDIAPI HFONT WINAPI Create_Font_اسدھا_Ex_W(CONST ENUMLOGFONTEXDVW *);

#جے_بنا_تعریف NOTEXTMETRIC
  تعريفنوع بنية ٹیگ_ENUMTEXTMETRICA {
    NEWTEXTMETRICEXA etm_New_متن_Metric_Ex;
    AXESLISTA etmAxesList;
  } ENUMTEXTMETRICA,*PENUMTEXTMETRICA,*LPENUMTEXTMETRICA;
  تعريفنوع بنية ٹیگ_ENUMTEXTMETRICW
  {
    NEWTEXTMETRICEXW etm_New_متن_Metric_Ex;
    AXESLISTW etmAxesList;
  } ENUMTEXTMETRICW,*PENUMTEXTMETRICW,*LPENUMTEXTMETRICW;
#جے_تعریف_شدہ UNICODE
  تعريفنوع ENUMTEXTMETRICW ENUMTEXTMETRIC;
  تعريفنوع PENUMTEXTMETRICW PENUMTEXTMETRIC;
  تعريفنوع LPENUMTEXTMETRICW LPENUMTEXTMETRIC;
#وإلا
  تعريفنوع ENUMTEXTMETRICA ENUMTEXTMETRIC;
  تعريفنوع PENUMTEXTMETRICA PENUMTEXTMETRIC;
  تعريفنوع LPENUMTEXTMETRICA LPENUMTEXTMETRIC;
#جے_انت
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو ResetDC ResetDCW
#تعریف_کرو RemoveFontResource RemoveFontResourceW
#وإلا
#تعریف_کرو ResetDC ResetDCA
#تعریف_کرو RemoveFontResource RemoveFontResourceA
#جے_انت

  WINGDIAPI WINBOOL WINAPI GetViewportExtEx(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI GetViewportOrgEx(HDC hdc,LPPOINT lppoint);
  WINGDIAPI WINBOOL WINAPI Get_کھڑکی_Ext_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI Get_کھڑکی_Org_Ex(HDC hdc,LPPOINT lppoint);
  WINGDIAPI صحيح WINAPI IntersectClipRect(HDC hdc,صحيح بایاں,صحيح چوٹی,صحيح دایاں,صحيح bottom);
  WINGDIAPI WINBOOL WINAPI InvertRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI سطر_DDA(صحيح x_شروع,صحيح y_شروع,صحيح x_سرا,صحيح y_سرا,LINEDDAPROC lpProc,LPARAM انکڑے);
  WINGDIAPI WINBOOL WINAPI سطر_منزل(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI نقاب_Blt(HDC hdcDest,صحيح xDest,صحيح yDest,صحيح چوڑائی,صحيح اچائی,HDC hdcSrc,صحيح xSrc,صحيح ySrc,HBITMAP hbm_نقاب,صحيح x_نقاب,صحيح y_نقاب,DWORD rop);
  WINGDIAPI WINBOOL WINAPI PlgBlt(HDC hdcDest,CONST نقطہ_3 *lp_نقطہ,HDC hdcSrc,صحيح xSrc,صحيح ySrc,صحيح چوڑائی,صحيح اچائی,HBITMAP hbm_نقاب,صحيح x_نقاب,صحيح y_نقاب);
  WINGDIAPI صحيح WINAPI وتھ_Clip_Rgn(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI صحيح WINAPI وتھ_Rgn(HRGN hrgn,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI PatBlt(HDC hdc,صحيح x,صحيح y,صحيح w,صحيح h,DWORD rop);
  WINGDIAPI WINBOOL WINAPI Pie(HDC hdc,صحيح بایاں,صحيح چوٹی,صحيح دایاں,صحيح bottom,صحيح xr1,صحيح yr1,صحيح xr2,صحيح yr2);
  WINGDIAPI WINBOOL WINAPI PlayMetaFile(HDC hdc,HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI PaintRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI PolyPolygon(HDC hdc,CONST نقطہ_3 *apt,CONST INT *asz,صحيح csz);
  WINGDIAPI WINBOOL WINAPI Pt_وچ_Region(HRGN hrgn,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI PtVisible(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI Rect_وچ_Region(HRGN hrgn,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI RectVisible(HDC hdc,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Rectangle(HDC hdc,صحيح بایاں,صحيح چوٹی,صحيح دایاں,صحيح bottom);
  WINGDIAPI WINBOOL WINAPI RestoreDC(HDC hdc,صحيح nSavedDC);
  WINGDIAPI HDC WINAPI ResetDCA(HDC hdc,CONST DEVMODEA *lpdm);
  WINGDIAPI HDC WINAPI ResetDCW(HDC hdc,CONST DEVMODEW *lpdm);
  WINGDIAPI UINT WINAPI RealizePalette(HDC hdc);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceA(LPCSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceW(LPCWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI گیڑا_Rect(HDC hdc,صحيح بایاں,صحيح چوٹی,صحيح دایاں,صحيح bottom,صحيح چوڑائی,صحيح اچائی);
  WINGDIAPI WINBOOL WINAPI ResizePalette(HPALETTE hpal,UINT n);
  WINGDIAPI صحيح WINAPI SaveDC(HDC hdc);
  WINGDIAPI صحيح WINAPI SelectClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI صحيح WINAPI ExtSelectClipRgn(HDC hdc,HRGN hrgn,صحيح منوال);
  WINGDIAPI صحيح WINAPI سیٹ_Meta_Rgn(HDC hdc);
  WINGDIAPI HGDIOBJ WINAPI SelectObject(HDC hdc,HGDIOBJ h);
  WINGDIAPI HPALETTE WINAPI SelectPalette(HDC hdc,HPALETTE hPal,WINBOOL bForceBkgd);
  WINGDIAPI COLORREF WINAPI سیٹ_Bk_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI سیٹ_DCBrush_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI سیٹ_DCPen_Color(HDC hdc,COLORREF color);
  WINGDIAPI صحيح WINAPI سیٹ_Bk_منوال(HDC hdc,صحيح منوال);
  WINGDIAPI LONG WINAPI سیٹ_Bitmap_بٹ(HBITMAP hbm,DWORD cb,CONST VOID *pv_بٹ);
  WINGDIAPI UINT WINAPI سیٹ_Bounds_Rect(HDC hdc,CONST RECT *lprect,UINT flags);
  WINGDIAPI صحيح WINAPI سیٹ_DIBits(HDC hdc,HBITMAP hbm,UINT شروع,UINT c_سطریں,CONST VOID *lp_بٹ,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI صحيح WINAPI سیٹ_DIBits_منزل_Device(HDC hdc,صحيح xDest,صحيح yDest,DWORD w,DWORD h,صحيح xSrc,صحيح ySrc,UINT شروع_جانچ,UINT c_سطریں,CONST VOID *lpv_بٹ,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI DWORD WINAPI سیٹ_Mapper_Flags(HDC hdc,DWORD flags);
  WINGDIAPI صحيح WINAPI سیٹ_Graphics_منوال(HDC hdc,صحيح i_منوال);
  WINGDIAPI صحيح WINAPI سیٹ_Map_منوال(HDC hdc,صحيح i_منوال);
  WINGDIAPI DWORD WINAPI سیٹ_Layout(HDC hdc,DWORD l);
  WINGDIAPI DWORD WINAPI GetLayout(HDC hdc);
  WINGDIAPI HMETAFILE WINAPI سیٹ_Meta_File_بٹ_Ex(UINT cb_بفر,CONST BYTE *lp_انکڑے);
  WINGDIAPI UINT WINAPI سیٹ_Palette_Entries(HPALETTE hpal,UINT i_شروع,UINT cEntries,CONST PALETTEENTRY *pPalEntries);
  WINGDIAPI COLORREF WINAPI سیٹ_Pixel(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI سیٹ_Pixel_V(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI سیٹ_Pixel_Format(HDC hdc,صحيح format,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI صحيح WINAPI سیٹ_Poly_Fill_منوال(HDC hdc,صحيح منوال);
  WINGDIAPI WINBOOL WINAPI StretchBlt(HDC hdcDest,صحيح xDest,صحيح yDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xSrc,صحيح ySrc,صحيح wSrc,صحيح hSrc,DWORD rop);
  WINGDIAPI WINBOOL WINAPI سیٹ_Rect_Rgn(HRGN hrgn,صحيح بایاں,صحيح چوٹی,صحيح دایاں,صحيح bottom);
  WINGDIAPI صحيح WINAPI StretchDIBits(HDC hdc,صحيح xDest,صحيح yDest,صحيح Dest_چوڑائی,صحيح Dest_اچائی,صحيح xSrc,صحيح ySrc,صحيح Src_چوڑائی,صحيح Src_اچائی,CONST VOID *lp_بٹ,CONST BITMAPINFO *lpbmi,UINT iUsage,DWORD rop);
  WINGDIAPI صحيح WINAPI سیٹ_ROP2(HDC hdc,صحيح rop2);
  WINGDIAPI صحيح WINAPI سیٹ_Stretch_Blt_منوال(HDC hdc,صحيح منوال);
  WINGDIAPI UINT WINAPI سیٹ_System_Palette_Use(HDC hdc,UINT use);
  WINGDIAPI صحيح WINAPI سیٹ_متن_Character_Extra(HDC hdc,صحيح extra);
  WINGDIAPI COLORREF WINAPI سیٹ_متن_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI سیٹ_متن_Align(HDC hdc,UINT align);
  WINGDIAPI WINBOOL WINAPI سیٹ_متن_Justification(HDC hdc,صحيح extra,صحيح گنتی_2);
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
    ULONG اتلا_بایاں;
    ULONG ہیٹھلا_دایاں;
  } GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;

  تعريفنوع بنية _BLENDFUNCTION {
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE سروت_Constant_Alpha;
    BYTE AlphaFormat;
  } BLENDFUNCTION,*PBLENDFUNCTION;

#تعریف_کرو AC_SRC_OVER 0x00
#تعریف_کرو AC_SRC_ALPHA 0x01

  WINGDIAPI WINBOOL WINAPI AlphaBlend(HDC hdcDest,صحيح xoriginDest,صحيح yoriginDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xoriginSrc,صحيح yoriginSrc,صحيح wSrc,صحيح hSrc,BLENDFUNCTION ftn);
  WINGDIAPI WINBOOL WINAPI TransparentBlt(HDC hdcDest,صحيح xoriginDest,صحيح yoriginDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xoriginSrc,صحيح yoriginSrc,صحيح wSrc,صحيح hSrc,UINT crTransparent);

#تعریف_کرو GRADIENT_FILL_RECT_H 0x00000000
#تعریف_کرو GRADIENT_FILL_RECT_V 0x00000001
#تعریف_کرو GRADIENT_FILL_TRIANGLE 0x00000002
#تعریف_کرو GRADIENT_FILL_OP_FLAG 0x000000ff

  WINGDIAPI WINBOOL WINAPI GradientFill(HDC hdc,PTRIVERTEX p_راس,ULONG n_راس,PVOID pMesh,ULONG nMesh,ULONG ul_منوال);

#جے_بنا_تعریف NOMETAFILE

#جے_تعریف_شدہ UNICODE
#تعریف_کرو CopyEnhMetaFile CopyEnhMetaFileW
#تعریف_کرو CreateEnhMetaFile CreateEnhMetaFileW
#تعریف_کرو GetEnhMetaFile GetEnhMetaFileW
#تعریف_کرو GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#وإلا
#تعریف_کرو CopyEnhMetaFile CopyEnhMetaFileA
#تعریف_کرو CreateEnhMetaFile CreateEnhMetaFileA
#تعریف_کرو GetEnhMetaFile GetEnhMetaFileA
#تعریف_کرو GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#جے_انت

  WINGDIAPI WINBOOL WINAPI Play_Meta_File_ریکارڈ(HDC hdc,LPHANDLETABLE lp_Handle_جدول,LPMETARECORD lpMR,UINT noObjs);

  تعريفنوع صحيح (CALLBACK *MFENUMPROC)(HDC hdc,HANDLETABLE *lpht,METARECORD *lpMR,صحيح nObj,LPARAM param);

  WINGDIAPI WINBOOL WINAPI EnumMetaFile(HDC hdc,HMETAFILE hmf,MFENUMPROC proc,LPARAM param);

  تعريفنوع صحيح (CALLBACK *ENHMFENUMPROC)(HDC hdc,HANDLETABLE *lpht,CONST ENHMETARECORD *lpmr,صحيح hHandles,LPARAM انکڑے);

  WINGDIAPI HENHMETAFILE WINAPI CloseEnhMetaFile(HDC hdc);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileA(HENHMETAFILE hEnh,LPCSTR lpFileName);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileW(HENHMETAFILE hEnh,LPCWSTR lpFileName);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileA(HDC hdc,LPCSTR lpFilename,CONST RECT *lprc,LPCSTR lpDesc);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileW(HDC hdc,LPCWSTR lpFilename,CONST RECT *lprc,LPCWSTR lpDesc);
  WINGDIAPI WINBOOL WINAPI DeleteEnhMetaFile(HENHMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI EnumEnhMetaFile(HDC hdc,HENHMETAFILE hmf,ENHMFENUMPROC proc,LPVOID param,CONST RECT *lpRect);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileA(LPCSTR lpName);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileW(LPCWSTR lpName);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_بٹ(HENHMETAFILE hEMF,UINT n_ناپ,LPBYTE lp_انکڑے);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE hemf,UINT cch_بفر,LPSTR lpDescription);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE hemf,UINT cch_بفر,LPWSTR lpDescription);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_سرخی(HENHMETAFILE hemf,UINT n_ناپ,LPENHMETAHEADER lp_Enh_Meta_سرخی);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT n_عدد_Entries,LPPALETTEENTRY lpPaletteEntries);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePixelFormat(HENHMETAFILE hemf,UINT cb_بفر,PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI UINT WINAPI Get_Win_Meta_File_بٹ(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT i_Map_منوال,HDC hdcRef);
  WINGDIAPI WINBOOL WINAPI PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Play_Enh_Meta_File_ریکارڈ(HDC hdc,LPHANDLETABLE pht,CONST ENHMETARECORD *pmr,UINT cht);
  WINGDIAPI HENHMETAFILE WINAPI سیٹ_Enh_Meta_File_بٹ(UINT n_ناپ,CONST BYTE *pb);
  WINGDIAPI HENHMETAFILE WINAPI سیٹ_Win_Meta_File_بٹ(UINT n_ناپ,CONST BYTE *lp_Meta16_انکڑے,HDC hdcRef,CONST METAFILEPICT *lpMFP);
  WINGDIAPI WINBOOL WINAPI GdiComment(HDC hdc,UINT n_ناپ,CONST BYTE *lp_انکڑے);
#جے_انت

#جے_بنا_تعریف NOTEXTMETRIC
#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_متن_Metrics Get_متن_Metrics_W
#وإلا
#تعریف_کرو Get_متن_Metrics Get_متن_Metrics_A
#جے_انت

  WINGDIAPI WINBOOL WINAPI Get_متن_Metrics_A(HDC hdc,LPTEXTMETRICA lptm);
  WINGDIAPI WINBOOL WINAPI Get_متن_Metrics_W(HDC hdc,LPTEXTMETRICW lptm);
#جے_انت

  تعريفنوع بنية ٹیگ_DIBSECTION {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD ds_وتھ;
  } DIBSECTION,*LPDIBSECTION,*PDIBSECTION;

  WINGDIAPI WINBOOL WINAPI AngleArc(HDC hdc,صحيح x,صحيح y,DWORD r,FLOAT شروع_Angle,FLOAT SweepAngle);
  WINGDIAPI WINBOOL WINAPI PolyPolyline(HDC hdc,CONST نقطہ_3 *apt,CONST DWORD *asz,DWORD csz);
  WINGDIAPI WINBOOL WINAPI GetWorldTransform(HDC hdc,LPXFORM lpxf);
  WINGDIAPI WINBOOL WINAPI سیٹ_World_Transform(HDC hdc,CONST XFORM *lpxf);
  WINGDIAPI WINBOOL WINAPI ModifyWorldTransform(HDC hdc,CONST XFORM *lpxf,DWORD منوال);
  WINGDIAPI WINBOOL WINAPI CombineTransform(LPXFORM lpxf_باہرلا,CONST XFORM *lpxf1,CONST XFORM *lpxf2);
  WINGDIAPI HBITMAP WINAPI CreateDIBSection(HDC hdc,CONST BITMAPINFO *lpbmi,UINT usage,VOID **ppv_بٹ,HANDLE hSection,DWORD وتھ);
  WINGDIAPI UINT WINAPI Get_DIBColor_جدول(HDC hdc,UINT i_شروع,UINT cEntries,RGBQUAD *prgbq);
  WINGDIAPI UINT WINAPI سیٹ_DIBColor_جدول(HDC hdc,UINT i_شروع,UINT cEntries,CONST RGBQUAD *prgbq);

#تعریف_کرو CA_NEGATIVE 0x0001
#تعریف_کرو CA_LOG_FILTER 0x0002

#تعریف_کرو ILLUMINANT_DEVICE_DEFAULT 0
#تعریف_کرو ILLUMINANT_A 1
#تعریف_کرو ILLUMINANT_B 2
#تعریف_کرو ILLUMINANT_C 3
#تعریف_کرو ILLUMINANT_D50 4
#تعریف_کرو ILLUMINANT_D55 5
#تعریف_کرو ILLUMINANT_D65 6
#تعریف_کرو ILLUMINANT_D75 7
#تعریف_کرو ILLUMINANT_F2 8
#تعریف_کرو ILLUMINANT_MAX_اشاریہ ILLUMINANT_F2

#تعریف_کرو ILLUMINANT_TUNGSTEN ILLUMINANT_A
#تعریف_کرو ILLUMINANT_DAYLIGHT ILLUMINANT_C
#تعریف_کرو ILLUMINANT_FLUORESCENT ILLUMINANT_F2
#تعریف_کرو ILLUMINANT_NTSC ILLUMINANT_C

#تعریف_کرو RGB_GAMMA_MIN (لفظ_3)02500
#تعریف_کرو RGB_GAMMA_MAX (لفظ_3)65000

#تعریف_کرو REFERENCE_WHITE_MIN (لفظ_3)6000
#تعریف_کرو REFERENCE_WHITE_MAX (لفظ_3)10000
#تعریف_کرو REFERENCE_BLACK_MIN (لفظ_3)0
#تعریف_کرو REFERENCE_BLACK_MAX (لفظ_3)4000

#تعریف_کرو COLOR_ADJ_MIN (SHORT)-100
#تعریف_کرو COLOR_ADJ_MAX (SHORT)100

  تعريفنوع بنية ٹیگ_COLORADJUSTMENT {
    لفظ_3 ca_ناپ;
    لفظ_3 caFlags;
    لفظ_3 ca_Illuminant_اشاریہ;
    لفظ_3 caRedGamma;
    لفظ_3 caGreenGamma;
    لفظ_3 caBlueGamma;
    لفظ_3 caReferenceBlack;
    لفظ_3 caReferenceWhite;
    SHORT caContrast;
    SHORT caBrightness;
    SHORT caColorfulness;
    SHORT caRedGreenTint;
  } COLORADJUSTMENT,*PCOLORADJUSTMENT,*LPCOLORADJUSTMENT;

  WINGDIAPI WINBOOL WINAPI سیٹ_Color_Adjustment(HDC hdc,CONST COLORADJUSTMENT *lpca);
  WINGDIAPI WINBOOL WINAPI GetColorAdjustment(HDC hdc,LPCOLORADJUSTMENT lpca);
  WINGDIAPI HPALETTE WINAPI CreateHalftonePalette(HDC hdc);

  تعريفنوع WINBOOL (CALLBACK *ABORTPROC)(HDC,صحيح);

  تعريفنوع بنية _DOCINFOA {
    صحيح cb_ناپ;
    LPCSTR lpszDocName;
    LPCSTR lpszOutput;
    LPCSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOA,*LPDOCINFOA;

  تعريفنوع بنية _DOCINFOW {
    صحيح cb_ناپ;
    LPCWSTR lpszDocName;
    LPCWSTR lpszOutput;
    LPCWSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOW,*LPDOCINFOW;

#جے_تعریف_شدہ UNICODE
  تعريفنوع DOCINFOW DOCINFO;
  تعريفنوع LPDOCINFOW LPDOCINFO;
#وإلا
  تعريفنوع DOCINFOA DOCINFO;
  تعريفنوع LPDOCINFOA LPDOCINFO;
#جے_انت

#تعریف_کرو DI_APPBANDING 0x00000001
#تعریف_کرو DI_ROPS_READ_DESTINATION 0x00000002

#جے_تعریف_شدہ UNICODE
#تعریف_کرو شروع_Doc شروع_Doc_W
#تعریف_کرو GetObject GetObjectW
#تعریف_کرو متن_باہرلا متن_باہرلا_W
#تعریف_کرو Ext_متن_باہرلا Ext_متن_باہرلا_W
#تعریف_کرو Poly_متن_باہرلا Poly_متن_باہرلا_W
#تعریف_کرو Get_متن_Face Get_متن_Face_W
#وإلا
#تعریف_کرو شروع_Doc شروع_Doc_A
#تعریف_کرو GetObject GetObjectA
#تعریف_کرو متن_باہرلا متن_باہرلا_A
#تعریف_کرو Ext_متن_باہرلا Ext_متن_باہرلا_A
#تعریف_کرو Poly_متن_باہرلا Poly_متن_باہرلا_A
#تعریف_کرو Get_متن_Face Get_متن_Face_A
#جے_انت

  WINGDIAPI صحيح WINAPI شروع_Doc_A(HDC hdc,CONST DOCINFOA *lpdi);
  WINGDIAPI صحيح WINAPI شروع_Doc_W(HDC hdc,CONST DOCINFOW *lpdi);
  WINGDIAPI صحيح WINAPI سرا_Doc(HDC hdc);
  WINGDIAPI صحيح WINAPI شروع_ورقہ(HDC hdc);
  WINGDIAPI صحيح WINAPI سرا_ورقہ(HDC hdc);
  WINGDIAPI صحيح WINAPI AbortDoc(HDC hdc);
  WINGDIAPI صحيح WINAPI سیٹ_Abort_Proc(HDC hdc,ABORTPROC proc);
  WINGDIAPI WINBOOL WINAPI Abort_رستہ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Arc_منزل(HDC hdc,صحيح بایاں,صحيح چوٹی,صحيح دایاں,صحيح bottom,صحيح xr1,صحيح yr1,صحيح xr2,صحيح yr2);
  WINGDIAPI WINBOOL WINAPI Begin_رستہ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI CloseFigure(HDC hdc);
  WINGDIAPI WINBOOL WINAPI سرا_رستہ_2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Fill_رستہ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Flatten_رستہ(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_رستہ(HDC hdc,LPPOINT apt,LPBYTE aj,صحيح cpt);
  WINGDIAPI HRGN WINAPI رستہ_منزل_Region(HDC hdc);
  WINGDIAPI WINBOOL WINAPI PolyDraw(HDC hdc,CONST نقطہ_3 *apt,CONST BYTE *aj,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI Select_Clip_رستہ(HDC hdc,صحيح منوال);
  WINGDIAPI صحيح WINAPI سیٹ_Arc_Direction(HDC hdc,صحيح dir);
  WINGDIAPI WINBOOL WINAPI سیٹ_Miter_حد_بندی(HDC hdc,FLOAT حد_بندی,PFLOAT old);
  WINGDIAPI WINBOOL WINAPI Stroke_And_Fill_رستہ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Stroke_رستہ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Widen_رستہ(HDC hdc);
  WINGDIAPI HPEN WINAPI ExtCreatePen(DWORD iPenStyle,DWORD c_چوڑائی,CONST LOGBRUSH *plbrush,DWORD cStyle,CONST DWORD *pstyle);
  WINGDIAPI WINBOOL WINAPI Get_Miter_حد_بندی(HDC hdc,PFLOAT plimit);
  WINGDIAPI صحيح WINAPI GetArcDirection(HDC hdc);
  WINGDIAPI صحيح WINAPI GetObjectA(HANDLE h,صحيح c,LPVOID pv);
  WINGDIAPI صحيح WINAPI GetObjectW(HANDLE h,صحيح c,LPVOID pv);
  WINGDIAPI WINBOOL WINAPI Move_منزل_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI متن_باہرلا_A(HDC hdc,صحيح x,صحيح y,LPCSTR lpString,صحيح c);
  WINGDIAPI WINBOOL WINAPI متن_باہرلا_W(HDC hdc,صحيح x,صحيح y,LPCWSTR lpString,صحيح c);
  WINGDIAPI WINBOOL WINAPI Ext_متن_باہرلا_A(HDC hdc,صحيح x,صحيح y,UINT options,CONST RECT *lprect,LPCSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Ext_متن_باہرلا_W(HDC hdc,صحيح x,صحيح y,UINT options,CONST RECT *lprect,LPCWSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Poly_متن_باہرلا_A(HDC hdc,CONST POLYTEXTA *ppt,صحيح nstrings);
  WINGDIAPI WINBOOL WINAPI Poly_متن_باہرلا_W(HDC hdc,CONST POLYTEXTW *ppt,صحيح nstrings);
  WINGDIAPI HRGN WINAPI CreatePolygonRgn(CONST نقطہ_3 *pptl,صحيح c_نقطہ,صحيح i_منوال);
  WINGDIAPI WINBOOL WINAPI DPtoLP(HDC hdc,LPPOINT lppt,صحيح c);
  WINGDIAPI WINBOOL WINAPI LPtoDP(HDC hdc,LPPOINT lppt,صحيح c);
  WINGDIAPI WINBOOL WINAPI Polygon(HDC hdc,CONST نقطہ_3 *apt,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI Polyline(HDC hdc,CONST نقطہ_3 *apt,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI PolyBezier(HDC hdc,CONST نقطہ_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Poly_Bezier_منزل(HDC hdc,CONST نقطہ_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Polyline_منزل(HDC hdc,CONST نقطہ_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI سیٹ_Viewport_Ext_Ex(HDC hdc,صحيح x,صحيح y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سیٹ_Viewport_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI سیٹ_کھڑکی_Ext_Ex(HDC hdc,صحيح x,صحيح y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سیٹ_کھڑکی_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI وتھ_Viewport_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI وتھ_کھڑکی_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ScaleViewportExtEx(HDC hdc,صحيح xn,صحيح dx,صحيح yn,صحيح yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Scale_کھڑکی_Ext_Ex(HDC hdc,صحيح xn,صحيح xd,صحيح yn,صحيح yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سیٹ_Bitmap_Dimension_Ex(HBITMAP hbm,صحيح w,صحيح h,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سیٹ_Brush_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI صحيح WINAPI Get_متن_Face_A(HDC hdc,صحيح c,LPSTR lpName);
  WINGDIAPI صحيح WINAPI Get_متن_Face_W(HDC hdc,صحيح c,LPWSTR lpName);

#تعریف_کرو FONTMAPPER_MAX 10

  تعريفنوع بنية ٹیگ_KERNINGPAIR {
    لفظ_3 w_پہلا;
    لفظ_3 w_دوجا;
    صحيح iKernAmount;
  } KERNINGPAIR,*LPKERNINGPAIR;

#جے_تعریف_شدہ UNICODE
#تعریف_کرو Get_Kerning_جوڑے Get_Kerning_جوڑے_W
#وإلا
#تعریف_کرو Get_Kerning_جوڑے Get_Kerning_جوڑے_A
#جے_انت

  WINGDIAPI DWORD WINAPI Get_Kerning_جوڑے_A(HDC hdc,DWORD n_جوڑے,LPKERNINGPAIR lpKernPair);
  WINGDIAPI DWORD WINAPI Get_Kerning_جوڑے_W(HDC hdc,DWORD n_جوڑے,LPKERNINGPAIR lpKernPair);
  WINGDIAPI WINBOOL WINAPI GetDCOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI FixBrushOrgEx(HDC hdc,صحيح x,صحيح y,LPPOINT ptl);
  WINGDIAPI WINBOOL WINAPI UnrealizeObject(HGDIOBJ h);
  WINGDIAPI WINBOOL WINAPI GdiFlush();
  WINGDIAPI DWORD WINAPI Gdi_سیٹ_Batch_حد_بندی(DWORD dw);
  WINGDIAPI DWORD WINAPI Gdi_Get_Batch_حد_بندی();

#تعریف_کرو ICM_OFF 1
#تعریف_کرو ICM_ON 2
#تعریف_کرو ICM_QUERY 3
#تعریف_کرو ICM_پورا_OUTSIDEDC 4

  تعريفنوع صحيح (CALLBACK *ICMENUMPROCA)(LPSTR,LPARAM);
  تعريفنوع صحيح (CALLBACK *ICMENUMPROCW)(LPWSTR,LPARAM);

#جے_تعریف_شدہ UNICODE
#تعریف_کرو ICMENUMPROC ICMENUMPROCW
#تعریف_کرو EnumICMProfiles EnumICMProfilesW
#تعریف_کرو Update_ICMReg_کلید Update_ICMReg_کلید_W
#تعریف_کرو GetLogColorSpace GetLogColorSpaceW
#تعریف_کرو CreateColorSpace CreateColorSpaceW
#تعریف_کرو GetICMProfile GetICMProfileW
#تعریف_کرو سیٹ_ICMProfile سیٹ_ICMProfile_W
#وإلا
#تعریف_کرو ICMENUMPROC ICMENUMPROCA
#تعریف_کرو EnumICMProfiles EnumICMProfilesA
#تعریف_کرو Update_ICMReg_کلید Update_ICMReg_کلید_A
#تعریف_کرو GetLogColorSpace GetLogColorSpaceA
#تعریف_کرو CreateColorSpace CreateColorSpaceA
#تعریف_کرو GetICMProfile GetICMProfileA
#تعریف_کرو سیٹ_ICMProfile سیٹ_ICMProfile_A
#جے_انت

  WINGDIAPI صحيح WINAPI سیٹ_ICMMode(HDC hdc,صحيح منوال);
  WINGDIAPI WINBOOL WINAPI Check_Colors_وچ_Gamut(HDC hdc,LPVOID lpRGBTriple,LPVOID dlp_بفر,DWORD n_گنتی);
  WINGDIAPI HCOLORSPACE WINAPI GetColorSpace(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceA(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEA lp_بفر,DWORD n_ناپ);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceW(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEW lp_بفر,DWORD n_ناپ);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA lplcs);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW lplcs);
  WINGDIAPI HCOLORSPACE WINAPI سیٹ_Color_Space(HDC hdc,HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI DeleteColorSpace(HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI GetICMProfileA(HDC hdc,LPDWORD p_Buf_ناپ,LPSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI GetICMProfileW(HDC hdc,LPDWORD p_Buf_ناپ,LPWSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI سیٹ_ICMProfile_A(HDC hdc,LPSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI سیٹ_ICMProfile_W(HDC hdc,LPWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI GetDeviceGammaRamp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI سیٹ_Device_Gamma_Ramp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI Color_میل_منزل_نشانہ(HDC hdc,HDC hdc_نشانہ,DWORD action);
  WINGDIAPI صحيح WINAPI EnumICMProfilesA(HDC hdc,ICMENUMPROCA proc,LPARAM param);
  WINGDIAPI صحيح WINAPI EnumICMProfilesW(HDC hdc,ICMENUMPROCW proc,LPARAM param);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_کلید_A(DWORD reserved,LPSTR lpszCMID,LPSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_کلید_W(DWORD reserved,LPWSTR lpszCMID,LPWSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI ColorCorrectPalette(HDC hdc,HPALETTE hPal,DWORD de_پہلا,DWORD عدد);

#جے_بنا_تعریف NOMETAFILE

#تعریف_کرو ENHMETA_SIGNATURE 0x464D4520
#تعریف_کرو ENHMETA_STOCK_OBJECT 0x80000000

#تعریف_کرو EMR_سرخی 1
#تعریف_کرو EMR_POLYBEZIER 2
#تعریف_کرو EMR_POLYGON 3
#تعریف_کرو EMR_POLYLINE 4
#تعریف_کرو EMR_POLYBEZIERTO 5
#تعریف_کرو EMR_POLYLINETO 6
#تعریف_کرو EMR_POLYPOLYLINE 7
#تعریف_کرو EMR_POLYPOLYGON 8
#تعریف_کرو EMR_SETWINDOWEXTEX 9
#تعریف_کرو EMR_SETWINDOWORGEX 10
#تعریف_کرو EMR_SETVIEWPORTEXTEX 11
#تعریف_کرو EMR_SETVIEWPORTORGEX 12
#تعریف_کرو EMR_SETBRUSHORGEX 13
#تعریف_کرو EMR_EOF 14
#تعریف_کرو EMR_SETPIXELV 15
#تعریف_کرو EMR_SETMAPPERFLAGS 16
#تعریف_کرو EMR_SETMAPMODE 17
#تعریف_کرو EMR_SETBKMODE 18
#تعریف_کرو EMR_SETPOLYFILLMODE 19
#تعریف_کرو EMR_SETROP2 20
#تعریف_کرو EMR_SETSTRETCHBLTMODE 21
#تعریف_کرو EMR_SETTEXTALIGN 22
#تعریف_کرو EMR_SETCOLORADJUSTMENT 23
#تعریف_کرو EMR_SETTEXTCOLOR 24
#تعریف_کرو EMR_SETBKCOLOR 25
#تعریف_کرو EMR_OFFSETCLIPRGN 26
#تعریف_کرو EMR_MOVETOEX 27
#تعریف_کرو EMR_SETMETARGN 28
#تعریف_کرو EMR_EXCLUDECLIPRECT 29
#تعریف_کرو EMR_INTERSECTCLIPRECT 30
#تعریف_کرو EMR_SCALEVIEWPORTEXTEX 31
#تعریف_کرو EMR_SCALEWINDOWEXTEX 32
#تعریف_کرو EMR_SAVEDC 33
#تعریف_کرو EMR_RESTOREDC 34
#تعریف_کرو EMR_SETWORLDTRANSFORM 35
#تعریف_کرو EMR_MODIFYWORLDTRANSFORM 36
#تعریف_کرو EMR_SELECTOBJECT 37
#تعریف_کرو EMR_CREATEPEN 38
#تعریف_کرو EMR_CREATEBRUSHINDIRECT 39
#تعریف_کرو EMR_DELETEOBJECT 40
#تعریف_کرو EMR_ANGLEARC 41
#تعریف_کرو EMR_ELLIPSE 42
#تعریف_کرو EMR_RECTANGLE 43
#تعریف_کرو EMR_ROUNDRECT 44
#تعریف_کرو EMR_ARC 45
#تعریف_کرو EMR_CHORD 46
#تعریف_کرو EMR_PIE 47
#تعریف_کرو EMR_SELECTPALETTE 48
#تعریف_کرو EMR_CREATEPALETTE 49
#تعریف_کرو EMR_SETPALETTEENTRIES 50
#تعریف_کرو EMR_RESIZEPALETTE 51
#تعریف_کرو EMR_REALIZEPALETTE 52
#تعریف_کرو EMR_EXTFLOODFILL 53
#تعریف_کرو EMR_LINETO 54
#تعریف_کرو EMR_ARCTO 55
#تعریف_کرو EMR_POLYDRAW 56
#تعریف_کرو EMR_SETARCDIRECTION 57
#تعریف_کرو EMR_SETMITERLIMIT 58
#تعریف_کرو EMR_BEGINPATH 59
#تعریف_کرو EMR_ENDPATH 60
#تعریف_کرو EMR_CLOSEFIGURE 61
#تعریف_کرو EMR_FILLPATH 62
#تعریف_کرو EMR_STROKEANDFILLPATH 63
#تعریف_کرو EMR_STROKEPATH 64
#تعریف_کرو EMR_FLATTENPATH 65
#تعریف_کرو EMR_WIDENPATH 66
#تعریف_کرو EMR_SELECTCLIPPATH 67
#تعریف_کرو EMR_ABORTPATH 68

#تعریف_کرو EMR_GDICOMMENT 70
#تعریف_کرو EMR_FILLRGN 71
#تعریف_کرو EMR_FRAMERGN 72
#تعریف_کرو EMR_INVERTRGN 73
#تعریف_کرو EMR_PAINTRGN 74
#تعریف_کرو EMR_EXTSELECTCLIPRGN 75
#تعریف_کرو EMR_BITBLT 76
#تعریف_کرو EMR_STRETCHBLT 77
#تعریف_کرو EMR_MASKBLT 78
#تعریف_کرو EMR_PLGBLT 79
#تعریف_کرو EMR_SETDIBITSTODEVICE 80
#تعریف_کرو EMR_STRETCHDIBITS 81
#تعریف_کرو EMR_EXTCREATEFONTINDIRECTW 82
#تعریف_کرو EMR_EXTTEXTOUTA 83
#تعریف_کرو EMR_EXTTEXTOUTW 84
#تعریف_کرو EMR_POLYBEZIER16 85
#تعریف_کرو EMR_POLYGON16 86
#تعریف_کرو EMR_POLYLINE16 87
#تعریف_کرو EMR_POLYBEZIERTO16 88
#تعریف_کرو EMR_POLYLINETO16 89
#تعریف_کرو EMR_POLYPOLYLINE16 90
#تعریف_کرو EMR_POLYPOLYGON16 91
#تعریف_کرو EMR_POLYDRAW16 92
#تعریف_کرو EMR_CREATEMONOBRUSH 93
#تعریف_کرو EMR_CREATEDIBPATTERNBRUSHPT 94
#تعریف_کرو EMR_EXTCREATEPEN 95
#تعریف_کرو EMR_POLYTEXTOUTA 96
#تعریف_کرو EMR_POLYTEXTOUTW 97

#تعریف_کرو EMR_SETICMMODE 98
#تعریف_کرو EMR_CREATECOLORSPACE 99
#تعریف_کرو EMR_SETCOLORSPACE 100
#تعریف_کرو EMR_DELETECOLORSPACE 101
#تعریف_کرو EMR_GLSRECORD 102
#تعریف_کرو EMR_GLSBOUNDEDRECORD 103
#تعریف_کرو EMR_PIXELFORMAT 104
#تعریف_کرو EMR_RESERVED_105 105
#تعریف_کرو EMR_RESERVED_106 106
#تعریف_کرو EMR_RESERVED_107 107
#تعریف_کرو EMR_RESERVED_108 108
#تعریف_کرو EMR_RESERVED_109 109
#تعریف_کرو EMR_RESERVED_110 110
#تعریف_کرو EMR_COLORCORRECTPALETTE 111
#تعریف_کرو EMR_SETICMPROFILEA 112
#تعریف_کرو EMR_SETICMPROFILEW 113
#تعریف_کرو EMR_ALPHABLEND 114
#تعریف_کرو EMR_SETLAYOUT 115
#تعریف_کرو EMR_TRANSPARENTBLT 116
#تعریف_کرو EMR_RESERVED_117 117
#تعریف_کرو EMR_GRADIENTFILL 118
#تعریف_کرو EMR_RESERVED_119 119
#تعریف_کرو EMR_RESERVED_120 120
#تعریف_کرو EMR_COLORMATCHTOTARGETW 121
#تعریف_کرو EMR_CREATECOLORSPACEW 122

#تعریف_کرو EMR_MIN 1

#تعریف_کرو EMR_MAX 122

  تعريفنوع بنية ٹیگ_EMR {
    DWORD iType;
    DWORD n_ناپ;
  } EMR,*PEMR;

  تعريفنوع بنية ٹیگ_EMRTEXT {
    POINTL ptlReference;
    DWORD nChars;
    DWORD offString;
    DWORD fOptions;
    RECTL rcl;
    DWORD offDx;
  } EMRTEXT,*PEMRTEXT;

  تعريفنوع بنية ٹیگ_ABORTPATH {
    EMR emr;
  } EMRABORTPATH,*PEMRABORTPATH,EMRBEGINPATH,*PEMRBEGINPATH,EMRENDPATH,*PEMRENDPATH,EMRCLOSEFIGURE,*PEMRCLOSEFIGURE,EMRFLATTENPATH,*PEMRFLATTENPATH,EMRWIDENPATH,*PEMRWIDENPATH,EMRSETMETARGN,*PEMRSETMETARGN,EMRSAVEDC,*PEMRSAVEDC,EMRREALIZEPALETTE,*PEMRREALIZEPALETTE;

  تعريفنوع بنية ٹیگ_EMRSELECTCLIPPATH {
    EMR emr;
    DWORD i_منوال;
  } EMRSELECTCLIPPATH,*PEMRSELECTCLIPPATH,EMRSETBKMODE,*PEMRSETBKMODE,EMRSETMAPMODE,*PEMRSETMAPMODE,EMRSETLAYOUT,*PEMRSETLAYOUT,
    EMRSETPOLYFILLMODE,*PEMRSETPOLYFILLMODE,EMRSETROP2,*PEMRSETROP2,EMRSETSTRETCHBLTMODE,*PEMRSETSTRETCHBLTMODE,EMRSETICMMODE,
    *PEMRSETICMMODE,EMRSETTEXTALIGN,*PEMRSETTEXTALIGN;

  تعريفنوع بنية ٹیگ_EMRSETMITERLIMIT {
    EMR emr;
    FLOAT e_Miter_حد_بندی;
  } EMRSETMITERLIMIT,*PEMRSETMITERLIMIT;

  تعريفنوع بنية ٹیگ_EMRRESTOREDC {
    EMR emr;
    LONG iRelative;
  } EMRRESTOREDC,*PEMRRESTOREDC;

  تعريفنوع بنية ٹیگ_EMRSETARCDIRECTION {
    EMR emr;
    DWORD iArcDirection;

  } EMRSETARCDIRECTION,*PEMRSETARCDIRECTION;

  تعريفنوع بنية ٹیگ_EMRSETMAPPERFLAGS {
    EMR emr;
    DWORD dwFlags;
  } EMRSETMAPPERFLAGS,*PEMRSETMAPPERFLAGS;

  تعريفنوع بنية ٹیگ_EMRSETTEXTCOLOR {
    EMR emr;
    COLORREF crColor;
  } EMRSETBKCOLOR,*PEMRSETBKCOLOR,EMRSETTEXTCOLOR,*PEMRSETTEXTCOLOR;

  تعريفنوع بنية ٹیگ_EMRSELECTOBJECT {
    EMR emr;
    DWORD ihObject;
  } EMRSELECTOBJECT,*PEMRSELECTOBJECT,EMRDELETEOBJECT,*PEMRDELETEOBJECT;

  تعريفنوع بنية ٹیگ_EMRSELECTPALETTE {
    EMR emr;
    DWORD ihPal;
  } EMRSELECTPALETTE,*PEMRSELECTPALETTE;

  تعريفنوع بنية ٹیگ_EMRRESIZEPALETTE {
    EMR emr;
    DWORD ihPal;
    DWORD cEntries;
  } EMRRESIZEPALETTE,*PEMRRESIZEPALETTE;

  تعريفنوع بنية ٹیگ_EMRSETPALETTEENTRIES {
    EMR emr;
    DWORD ihPal;
    DWORD i_شروع;
    DWORD cEntries;
    PALETTEENTRY aPalEntries[1];
  } EMRSETPALETTEENTRIES,*PEMRSETPALETTEENTRIES;

  تعريفنوع بنية ٹیگ_EMRSETCOLORADJUSTMENT {
    EMR emr;
    COLORADJUSTMENT ColorAdjustment;
  } EMRSETCOLORADJUSTMENT,*PEMRSETCOLORADJUSTMENT;

  تعريفنوع بنية ٹیگ_EMRGDICOMMENT {
    EMR emr;
    DWORD cb_انکڑے;
    BYTE انکڑے_3[1];
  } EMRGDICOMMENT,*PEMRGDICOMMENT;

  تعريفنوع بنية ٹیگ_EMREOF {
    EMR emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD n_ناپ_آخری;
  } EMREOF,*PEMREOF;

  تعريفنوع بنية ٹیگ_EMRLINETO {
    EMR emr;
    POINTL ptl;
  } EMRLINETO,*PEMRLINETO,EMRMOVETOEX,*PEMRMOVETOEX;

  تعريفنوع بنية ٹیگ_EMROFFSETCLIPRGN {
    EMR emr;
    POINTL ptl_وتھ;
  } EMROFFSETCLIPRGN,*PEMROFFSETCLIPRGN;

  تعريفنوع بنية ٹیگ_EMRFILLPATH {
    EMR emr;
    RECTL rclBounds;
  } EMRFILLPATH,*PEMRFILLPATH,EMRSTROKEANDFILLPATH,*PEMRSTROKEANDFILLPATH,EMRSTROKEPATH,*PEMRSTROKEPATH;

  تعريفنوع بنية ٹیگ_EMREXCLUDECLIPRECT {
    EMR emr;
    RECTL rclClip;
  } EMREXCLUDECLIPRECT,*PEMREXCLUDECLIPRECT,EMRINTERSECTCLIPRECT,*PEMRINTERSECTCLIPRECT;

  تعريفنوع بنية ٹیگ_EMRSETVIEWPORTORGEX {
    EMR emr;
    POINTL ptlOrigin;
  } EMRSETVIEWPORTORGEX,*PEMRSETVIEWPORTORGEX,EMRSETWINDOWORGEX,*PEMRSETWINDOWORGEX,EMRSETBRUSHORGEX,*PEMRSETBRUSHORGEX;

  تعريفنوع بنية ٹیگ_EMRSETVIEWPORTEXTEX {
    EMR emr;
    SIZEL szlExtent;
  } EMRSETVIEWPORTEXTEX,*PEMRSETVIEWPORTEXTEX,EMRSETWINDOWEXTEX,*PEMRSETWINDOWEXTEX;

  تعريفنوع بنية ٹیگ_EMRSCALEVIEWPORTEXTEX {
    EMR emr;
    LONG x_عدد;
    LONG xDenom;
    LONG y_عدد;
    LONG yDenom;
  } EMRSCALEVIEWPORTEXTEX,*PEMRSCALEVIEWPORTEXTEX,EMRSCALEWINDOWEXTEX,*PEMRSCALEWINDOWEXTEX;

  تعريفنوع بنية ٹیگ_EMRSETWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
  } EMRSETWORLDTRANSFORM,*PEMRSETWORLDTRANSFORM;

  تعريفنوع بنية ٹیگ_EMRMODIFYWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
    DWORD i_منوال;
  } EMRMODIFYWORLDTRANSFORM,*PEMRMODIFYWORLDTRANSFORM;

  تعريفنوع بنية ٹیگ_EMRSETPIXELV {
    EMR emr;
    POINTL ptlPixel;
    COLORREF crColor;
  } EMRSETPIXELV,*PEMRSETPIXELV;

  تعريفنوع بنية ٹیگ_EMREXTFLOODFILL {
    EMR emr;
    POINTL ptl_شروع;
    COLORREF crColor;
    DWORD i_منوال;
  } EMREXTFLOODFILL,*PEMREXTFLOODFILL;

  تعريفنوع بنية ٹیگ_EMRELLIPSE {
    EMR emr;
    RECTL rclBox;
  } EMRELLIPSE,*PEMRELLIPSE,EMRRECTANGLE,*PEMRRECTANGLE;

  تعريفنوع بنية ٹیگ_EMRROUNDRECT {
    EMR emr;
    RECTL rclBox;
    SIZEL szl_کونا;
  } EMRROUNDRECT,*PEMRROUNDRECT;

  تعريفنوع بنية ٹیگ_EMRARC {
    EMR emr;
    RECTL rclBox;
    POINTL ptl_شروع;
    POINTL ptl_سرا;
  } EMRARC,*PEMRARC,EMRARCTO,*PEMRARCTO,EMRCHORD,*PEMRCHORD,EMRPIE,*PEMRPIE;

  تعريفنوع بنية ٹیگ_EMRANGLEARC {
    EMR emr;
    POINTL ptlCenter;
    DWORD nRadius;
    FLOAT e_شروع_Angle;
    FLOAT eSweepAngle;
  } EMRANGLEARC,*PEMRANGLEARC;

  تعريفنوع بنية ٹیگ_EMRPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
  } EMRPOLYLINE,*PEMRPOLYLINE,EMRPOLYBEZIER,*PEMRPOLYBEZIER,EMRPOLYGON,*PEMRPOLYGON,EMRPOLYBEZIERTO,*PEMRPOLYBEZIERTO,EMRPOLYLINETO,*PEMRPOLYLINETO;

  تعريفنوع بنية ٹیگ_EMRPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
  } EMRPOLYLINE16,*PEMRPOLYLINE16,EMRPOLYBEZIER16,*PEMRPOLYBEZIER16,EMRPOLYGON16,*PEMRPOLYGON16,EMRPOLYBEZIERTO16,*PEMRPOLYBEZIERTO16,EMRPOLYLINETO16,*PEMRPOLYLINETO16;

  تعريفنوع بنية ٹیگ_EMRPOLYDRAW {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW,*PEMRPOLYDRAW;

  تعريفنوع بنية ٹیگ_EMRPOLYDRAW16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW16,*PEMRPOLYDRAW16;

  تعريفنوع بنية ٹیگ_EMRPOLYPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cptl;
    DWORD aPolyCounts[1];
    POINTL aptl[1];
  } EMRPOLYPOLYLINE,*PEMRPOLYPOLYLINE,EMRPOLYPOLYGON,*PEMRPOLYPOLYGON;

  تعريفنوع بنية ٹیگ_EMRPOLYPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cpts;
    DWORD aPolyCounts[1];
    POINTS apts[1];
  } EMRPOLYPOLYLINE16,*PEMRPOLYPOLYLINE16,EMRPOLYPOLYGON16,*PEMRPOLYPOLYGON16;

  تعريفنوع بنية ٹیگ_EMRINVERTRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_انکڑے;
    BYTE Rgn_انکڑے[1];
  } EMRINVERTRGN,*PEMRINVERTRGN,EMRPAINTRGN,*PEMRPAINTRGN;

  تعريفنوع بنية ٹیگ_EMRFILLRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_انکڑے;
    DWORD ihBrush;
    BYTE Rgn_انکڑے[1];
  } EMRFILLRGN,*PEMRFILLRGN;

  تعريفنوع بنية ٹیگ_EMRFRAMERGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_انکڑے;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE Rgn_انکڑے[1];
  } EMRFRAMERGN,*PEMRFRAMERGN;

  تعريفنوع بنية ٹیگ_EMREXTSELECTCLIPRGN {
    EMR emr;
    DWORD cb_Rgn_انکڑے;
    DWORD i_منوال;
    BYTE Rgn_انکڑے[1];
  } EMREXTSELECTCLIPRGN,*PEMREXTSELECTCLIPRGN;

  تعريفنوع بنية ٹیگ_EMREXTTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_منوال;
    FLOAT exScale;
    FLOAT eyScale;
    EMRTEXT emrtext;
  } EMREXTTEXTOUTA,*PEMREXTTEXTOUTA,EMREXTTEXTOUTW,*PEMREXTTEXTOUTW;

  تعريفنوع بنية ٹیگ_EMRPOLYTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_منوال;
    FLOAT exScale;
    FLOAT eyScale;
    LONG c_لڑیاں;
    EMRTEXT aemrtext[1];
  } EMRPOLYTEXTOUTA,*PEMRPOLYTEXTOUTA,EMRPOLYTEXTOUTW,*PEMRPOLYTEXTOUTW;

  تعريفنوع بنية ٹیگ_EMRBITBLT {
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
    DWORD off_بٹ_Src;
    DWORD cb_بٹ_Src;
  } EMRBITBLT,*PEMRBITBLT;

  تعريفنوع بنية ٹیگ_EMRSTRETCHBLT {
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
    DWORD off_بٹ_Src;
    DWORD cb_بٹ_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRSTRETCHBLT,*PEMRSTRETCHBLT;

  تعريفنوع بنية ٹیگ_EMRMASKBLT {
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
    DWORD off_بٹ_Src;
    DWORD cb_بٹ_Src;
    LONG x_نقاب;
    LONG y_نقاب;
    DWORD i_Usage_نقاب;
    DWORD off_Bmi_نقاب;
    DWORD cb_Bmi_نقاب;
    DWORD off_بٹ_نقاب;
    DWORD cb_بٹ_نقاب;
  } EMRMASKBLT,*PEMRMASKBLT;

  تعريفنوع بنية ٹیگ_EMRPLGBLT {
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
    DWORD off_بٹ_Src;
    DWORD cb_بٹ_Src;
    LONG x_نقاب;
    LONG y_نقاب;
    DWORD i_Usage_نقاب;
    DWORD off_Bmi_نقاب;
    DWORD cb_Bmi_نقاب;
    DWORD off_بٹ_نقاب;
    DWORD cb_بٹ_نقاب;
  } EMRPLGBLT,*PEMRPLGBLT;

  تعريفنوع بنية ٹیگ_EMRSETDIBITSTODEVICE {
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
    DWORD off_بٹ_Src;
    DWORD cb_بٹ_Src;
    DWORD iUsageSrc;
    DWORD i_شروع_جانچ;
    DWORD cScans;
  } EMRSETDIBITSTODEVICE,*PEMRSETDIBITSTODEVICE;

  تعريفنوع بنية ٹیگ_EMRSTRETCHDIBITS {
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
    DWORD off_بٹ_Src;
    DWORD cb_بٹ_Src;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG cxDest;
    LONG cyDest;
  } EMRSTRETCHDIBITS,*PEMRSTRETCHDIBITS;

  تعريفنوع بنية ٹیگ_EMREXTCREATEFONTINDIRECTW {
    EMR emr;
    DWORD ihFont;
    EXTLOGFONTW elfw;
  } EMREXTCREATEFONTINDIRECTW,*PEMREXTCREATEFONTINDIRECTW;

  تعريفنوع بنية ٹیگ_EMRCREATEPALETTE {
    EMR emr;
    DWORD ihPal;
    LOGPALETTE lgpl;
  } EMRCREATEPALETTE,*PEMRCREATEPALETTE;

  تعريفنوع بنية ٹیگ_EMRCREATEPEN {
    EMR emr;
    DWORD ihPen;
    LOGPEN lopn;
  } EMRCREATEPEN,*PEMRCREATEPEN;

  تعريفنوع بنية ٹیگ_EMREXTCREATEPEN {
    EMR emr;
    DWORD ihPen;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بٹ;
    DWORD cb_بٹ;
    EXTLOGPEN elp;
  } EMREXTCREATEPEN,*PEMREXTCREATEPEN;

  تعريفنوع بنية ٹیگ_EMRCREATEBRUSHINDIRECT {
    EMR emr;
    DWORD ihBrush;
    LOGBRUSH32 lb;
  } EMRCREATEBRUSHINDIRECT,*PEMRCREATEBRUSHINDIRECT;

  تعريفنوع بنية ٹیگ_EMRCREATEMONOBRUSH {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بٹ;
    DWORD cb_بٹ;
  } EMRCREATEMONOBRUSH,*PEMRCREATEMONOBRUSH;

  تعريفنوع بنية ٹیگ_EMRCREATEDIBPATTERNBRUSHPT {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بٹ;
    DWORD cb_بٹ;
  } EMRCREATEDIBPATTERNBRUSHPT,*PEMRCREATEDIBPATTERNBRUSHPT;

  تعريفنوع بنية ٹیگ_EMRFORMAT {
    DWORD dSignature;
    DWORD n_نسخہ;
    DWORD cb_انکڑے;
    DWORD off_انکڑے;
  } EMRFORMAT,*PEMRFORMAT;

  تعريفنوع بنية ٹیگ_EMRGLSRECORD {
    EMR emr;
    DWORD cb_انکڑے;
    BYTE انکڑے_3[1];
  } EMRGLSRECORD,*PEMRGLSRECORD;

  تعريفنوع بنية ٹیگ_EMRGLSBOUNDEDRECORD {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_انکڑے;
    BYTE انکڑے_3[1];
  } EMRGLSBOUNDEDRECORD,*PEMRGLSBOUNDEDRECORD;

  تعريفنوع بنية ٹیگ_EMRPIXELFORMAT {
    EMR emr;
    PIXELFORMATDESCRIPTOR pfd;
  } EMRPIXELFORMAT,*PEMRPIXELFORMAT;

  تعريفنوع بنية ٹیگ_EMRCREATECOLORSPACE {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEA lcs;
  } EMRCREATECOLORSPACE,*PEMRCREATECOLORSPACE;

  تعريفنوع بنية ٹیگ_EMRSETCOLORSPACE {
    EMR emr;
    DWORD ihCS;
  } EMRSETCOLORSPACE,*PEMRSETCOLORSPACE,EMRSELECTCOLORSPACE,*PEMRSELECTCOLORSPACE,EMRDELETECOLORSPACE,*PEMRDELETECOLORSPACE;

  تعريفنوع بنية ٹیگ_EMREXTESCAPE {
    EMR emr;
    INT iEscape;
    INT cb_Esc_انکڑے;
    BYTE Esc_انکڑے[1];
  } EMREXTESCAPE,*PEMREXTESCAPE,EMRDRAWESCAPE,*PEMRDRAWESCAPE;

  تعريفنوع بنية ٹیگ_EMRNAMEDESCAPE {
    EMR emr;
    INT iEscape;
    INT cbDriver;
    INT cb_Esc_انکڑے;
    BYTE Esc_انکڑے[1];
  } EMRNAMEDESCAPE,*PEMRNAMEDESCAPE;

#تعریف_کرو SETICMPROFILE_EMBEDED 0x00000001

  تعريفنوع بنية ٹیگ_EMRSETICMPROFILE {
    EMR emr;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_انکڑے;
    BYTE انکڑے_3[1];
  } EMRSETICMPROFILE,*PEMRSETICMPROFILE,EMRSETICMPROFILEA,*PEMRSETICMPROFILEA,EMRSETICMPROFILEW,*PEMRSETICMPROFILEW;

#تعریف_کرو CREATECOLORSPACE_EMBEDED 0x00000001

  تعريفنوع بنية ٹیگ_EMRCREATECOLORSPACEW {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEW lcs;
    DWORD dwFlags;
    DWORD cb_انکڑے;
    BYTE انکڑے_3[1];
  } EMRCREATECOLORSPACEW,*PEMRCREATECOLORSPACEW;

#تعریف_کرو COLORMATCHTOTARGET_EMBEDED 0x00000001

  تعريفنوع بنية ٹیگ_COLORMATCHTOTARGET {
    EMR emr;
    DWORD dwAction;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_انکڑے;
    BYTE انکڑے_3[1];
  } EMRCOLORMATCHTOTARGET,*PEMRCOLORMATCHTOTARGET;

  تعريفنوع بنية ٹیگ_COLORCORRECTPALETTE {
    EMR emr;
    DWORD ihPalette;
    DWORD n_پہلا_اندراج;
    DWORD nPalEntries;
    DWORD nReserved;
  } EMRCOLORCORRECTPALETTE,*PEMRCOLORCORRECTPALETTE;

  تعريفنوع بنية ٹیگ_EMRALPHABLEND {
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
    DWORD off_بٹ_Src;
    DWORD cb_بٹ_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRALPHABLEND,*PEMRALPHABLEND;

  تعريفنوع بنية ٹیگ_EMRGRADIENTFILL {
    EMR emr;
    RECTL rclBounds;
    DWORD nVer;
    DWORD nTri;
    ULONG ul_منوال;
    TRIVERTEX Ver[1];
  } EMRGRADIENTFILL,*PEMRGRADIENTFILL;

  تعريفنوع بنية ٹیگ_EMRTRANSPARENTBLT {
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
    DWORD off_بٹ_Src;
    DWORD cb_بٹ_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRTRANSPARENTBLT,*PEMRTRANSPARENTBLT;

#تعریف_کرو GDICOMMENT_IDENTIFIER 0x43494447
#تعریف_کرو GDICOMMENT_WINDOWS_METAFILE 0x80000001
#تعریف_کرو GDICOMMENT_BEGINGROUP 0x00000002
#تعریف_کرو GDICOMMENT_ENDGROUP 0x00000003
#تعریف_کرو GDICOMMENT_MULTIFORMATS 0x40000004
#تعریف_کرو EPS_SIGNATURE 0x46535045
#تعریف_کرو GDICOMMENT_UNICODE_STRING 0x00000040
#تعریف_کرو GDICOMMENT_UNICODE_سرا 0x00000080
#جے_انت

#جے_تعریف_شدہ UNICODE
#تعریف_کرو wglUseFontBitmaps wglUseFontBitmapsW
#وإلا
#تعریف_کرو wglUseFontBitmaps wglUseFontBitmapsA
#جے_انت

  WINGDIAPI WINBOOL WINAPI wglCopyContext(HGLRC,HGLRC,UINT);
  WINGDIAPI HGLRC WINAPI wglCreateContext(HDC);
  WINGDIAPI HGLRC WINAPI wglCreateLayerContext(HDC,صحيح);
  WINGDIAPI WINBOOL WINAPI wglDeleteContext(HGLRC);
  WINGDIAPI HGLRC WINAPI wglGetCurrentContext(VOID);
  WINGDIAPI HDC WINAPI wglGetCurrentDC(VOID);
  WINGDIAPI PROC WINAPI wgl_Get_Proc_پتہ(LPCSTR);
  WINGDIAPI WINBOOL WINAPI wglMakeCurrent(HDC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglShareLists(HGLRC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsA(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsW(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI وٹاندرا_Buffers(HDC);

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

#تعریف_کرو WGL_FONT_سطریں 0
#تعریف_کرو WGL_FONT_POLYGONS 1

#جے_تعریف_شدہ UNICODE
#تعریف_کرو wglUseFontOutlines wglUseFontOutlinesW
#وإلا
#تعریف_کرو wglUseFontOutlines wglUseFontOutlinesA
#جے_انت

  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesA(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,صحيح,LPGLYPHMETRICSFLOAT);
  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesW(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,صحيح,LPGLYPHMETRICSFLOAT);

  تعريفنوع بنية ٹیگ_LAYERPLANEDESCRIPTOR {
    لفظ_3 n_ناپ;
    لفظ_3 n_نسخہ;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_بٹ;
    BYTE c_Red_بٹ;
    BYTE c_Red_کھسکاؤ;
    BYTE c_Green_بٹ;
    BYTE c_Green_کھسکاؤ;
    BYTE c_Blue_بٹ;
    BYTE c_Blue_کھسکاؤ;
    BYTE c_Alpha_بٹ;
    BYTE c_Alpha_کھسکاؤ;
    BYTE c_Accum_بٹ;
    BYTE c_Accum_Red_بٹ;
    BYTE c_Accum_Green_بٹ;
    BYTE c_Accum_Blue_بٹ;
    BYTE c_Accum_Alpha_بٹ;
    BYTE c_ڈونگھائی_بٹ;
    BYTE c_Stencil_بٹ;
    BYTE cAuxBuffers;
    BYTE iLayerPlane;
    BYTE bReserved;
    COLORREF crTransparent;
  } LAYERPLANEDESCRIPTOR,*PLAYERPLANEDESCRIPTOR,*LPLAYERPLANEDESCRIPTOR;

#تعریف_کرو LPD_DOUBLEBUFFER 0x00000001
#تعریف_کرو LPD_STEREO 0x00000002
#تعریف_کرو LPD_SUPPORT_GDI 0x00000010
#تعریف_کرو LPD_SUPPORT_OPENGL 0x00000020
#تعریف_کرو LPD_SHARE_ڈونگھائی 0x00000040
#تعریف_کرو LPD_SHARE_STENCIL 0x00000080
#تعریف_کرو LPD_SHARE_ACCUM 0x00000100
#تعریف_کرو LPD_وٹاندرا_EXCHANGE 0x00000200
#تعریف_کرو LPD_وٹاندرا_COPY 0x00000400
#تعریف_کرو LPD_TRANSPARENT 0x00001000

#تعریف_کرو LPD_TYPE_RGBA 0
#تعریف_کرو LPD_TYPE_COLORINDEX 1

#تعریف_کرو WGL_وٹاندرا_MAIN_PLANE 0x00000001
#تعریف_کرو WGL_وٹاندرا_OVERLAY1 0x00000002
#تعریف_کرو WGL_وٹاندرا_OVERLAY2 0x00000004
#تعریف_کرو WGL_وٹاندرا_OVERLAY3 0x00000008
#تعریف_کرو WGL_وٹاندرا_OVERLAY4 0x00000010
#تعریف_کرو WGL_وٹاندرا_OVERLAY5 0x00000020
#تعریف_کرو WGL_وٹاندرا_OVERLAY6 0x00000040
#تعریف_کرو WGL_وٹاندرا_OVERLAY7 0x00000080
#تعریف_کرو WGL_وٹاندرا_OVERLAY8 0x00000100
#تعریف_کرو WGL_وٹاندرا_OVERLAY9 0x00000200
#تعریف_کرو WGL_وٹاندرا_OVERLAY10 0x00000400
#تعریف_کرو WGL_وٹاندرا_OVERLAY11 0x00000800
#تعریف_کرو WGL_وٹاندرا_OVERLAY12 0x00001000
#تعریف_کرو WGL_وٹاندرا_OVERLAY13 0x00002000
#تعریف_کرو WGL_وٹاندرا_OVERLAY14 0x00004000
#تعریف_کرو WGL_وٹاندرا_OVERLAY15 0x00008000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY1 0x00010000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY2 0x00020000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY3 0x00040000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY4 0x00080000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY5 0x00100000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY6 0x00200000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY7 0x00400000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY8 0x00800000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY9 0x01000000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY10 0x02000000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY11 0x04000000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY12 0x08000000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY13 0x10000000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY14 0x20000000
#تعریف_کرو WGL_وٹاندرا_UNDERLAY15 0x40000000

  WINGDIAPI WINBOOL WINAPI wglDescribeLayerPlane(HDC,صحيح,صحيح,UINT,LPLAYERPLANEDESCRIPTOR);
  WINGDIAPI صحيح WINAPI wgl_سیٹ_Layer_Palette_Entries(HDC,صحيح,صحيح,صحيح,CONST COLORREF *);
  WINGDIAPI صحيح WINAPI wglGetLayerPaletteEntries(HDC,صحيح,صحيح,صحيح,COLORREF *);
  WINGDIAPI WINBOOL WINAPI wglRealizeLayerPalette(HDC,صحيح,WINBOOL);
  WINGDIAPI WINBOOL WINAPI wgl_وٹاندرا_Layer_Buffers(HDC,UINT);

  تعريفنوع بنية _WGLSWAP {
    HDC hdc;
    UINT uiFlags;
  } WGLSWAP,*PWGLSWAP,*LPWGLSWAP;

#تعریف_کرو WGL_SWAPMULTIPLE_MAX 16

  WINGDIAPI DWORD WINAPI wgl_وٹاندرا_مضرب_Buffers(UINT,CONST WGLSWAP *);
#جے_انت

#جے_تعریف_شدہ __cplusplus
}
#جے_انت
#جے_انت
