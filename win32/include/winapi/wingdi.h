/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده _WINGDI_
#تعریف_کن _WINGDI_

#تعریف_کن WINGDIAPI DECLSPEC_IMPORT
#تعریف_کن WINSPOOLAPI DECLSPEC_IMPORT

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#اگر_تعریف_نشده WINVER
#تعریف_کن WINVER 0x0502
#پایان_اگر

#اگر_تعریف_نشده NOGDI
#اگر_تعریف_نشده NORASTEROPS
#تعریف_کن R2_BLACK 1
#تعریف_کن R2_NOTMERGEPEN 2
#تعریف_کن R2_MASKNOTPEN 3
#تعریف_کن R2_NOTCOPYPEN 4
#تعریف_کن R2_MASKPENNOT 5
#تعریف_کن R2_NOT 6
#تعریف_کن R2_XORPEN 7
#تعریف_کن R2_NOTMASKPEN 8
#تعریف_کن R2_MASKPEN 9
#تعریف_کن R2_NOTXORPEN 10
#تعریف_کن R2_NOP 11
#تعریف_کن R2_MERGENOTPEN 12
#تعریف_کن R2_COPYPEN 13
#تعریف_کن R2_MERGEPENNOT 14
#تعریف_کن R2_MERGEPEN 15
#تعریف_کن R2_WHITE 16
#تعریف_کن R2_آخرین 16

#تعریف_کن SRCCOPY (DWORD)0x00CC0020
#تعریف_کن SRCPAINT (DWORD)0x00EE0086
#تعریف_کن SRCAND (DWORD)0x008800C6
#تعریف_کن SRCINVERT (DWORD)0x00660046
#تعریف_کن SRCERASE (DWORD)0x00440328
#تعریف_کن NOTSRCCOPY (DWORD)0x00330008
#تعریف_کن NOTSRCERASE (DWORD)0x001100A6
#تعریف_کن MERGECOPY (DWORD)0x00C000CA
#تعریف_کن MERGEPAINT (DWORD)0x00BB0226
#تعریف_کن PATCOPY (DWORD)0x00F00021
#تعریف_کن PATPAINT (DWORD)0x00FB0A09
#تعریف_کن PATINVERT (DWORD)0x005A0049
#تعریف_کن DSTINVERT (DWORD)0x00550009
#تعریف_کن BLACKNESS (DWORD)0x00000042
#تعریف_کن WHITENESS (DWORD)0x00FF0062
#تعریف_کن NOMIRRORBITMAP (DWORD)0x80000000
#تعریف_کن CAPTUREBLT (DWORD)0x40000000
#تعریف_کن MAKEROP4(fore,پشت) (DWORD)((((پشت) << 8) & 0xFF000000) | (fore))
#پایان_اگر

#تعریف_کن GDI_ERROR (0xFFFFFFFFL)
#تعریف_کن HGDI_ERROR (Long_مقصد_Handle(0xFFFFFFFFL))

#تعریف_کن ERROR 0
#تعریف_کن NULLREGION 1
#تعریف_کن SIMPLEREGION 2
#تعریف_کن COMPLEXREGION 3
#تعریف_کن RGN_ERROR ERROR

#تعریف_کن RGN_AND 1
#تعریف_کن RGN_OR 2
#تعریف_کن RGN_XOR 3
#تعریف_کن RGN_DIFF 4
#تعریف_کن RGN_COPY 5
#تعریف_کن RGN_MIN RGN_AND
#تعریف_کن RGN_MAX RGN_COPY

#تعریف_کن BLACKONWHITE 1
#تعریف_کن WHITEONBLACK 2
#تعریف_کن COLORONCOLOR 3
#تعریف_کن HALFTONE 4
#تعریف_کن MAXSTRETCHBLTMODE 4

#تعریف_کن STRETCH_ANDSCANS BLACKONWHITE
#تعریف_کن STRETCH_ORSCANS WHITEONBLACK
#تعریف_کن STRETCH_DELETESCANS COLORONCOLOR
#تعریف_کن STRETCH_HALFTONE HALFTONE

#تعریف_کن ALTERNATE 1
#تعریف_کن WINDING 2
#تعریف_کن POLYFILL_آخرین 2

#تعریف_کن LAYOUT_RTL 0x00000001
#تعریف_کن LAYOUT_BTT 0x00000002
#تعریف_کن LAYOUT_VBH 0x00000004
#تعریف_کن LAYOUT_ORIENTATIONMASK (LAYOUT_RTL | LAYOUT_BTT | LAYOUT_VBH)
#تعریف_کن LAYOUT_BITMAPORIENTATIONPRESERVED 0x00000008

#تعریف_کن TA_NOUPDATECP 0
#تعریف_کن TA_UPDATECP 1

#تعریف_کن TA_چپ 0
#تعریف_کن TA_راست 2
#تعریف_کن TA_CENTER 6

#تعریف_کن TA_بالاترین 0
#تعریف_کن TA_BOTTOM 8
#تعریف_کن TA_BASELINE 24
#تعریف_کن TA_RTLREADING 256
#تعریف_کن TA_ماسک (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)

#تعریف_کن VTA_BASELINE TA_BASELINE
#تعریف_کن VTA_چپ TA_BOTTOM
#تعریف_کن VTA_راست TA_بالاترین
#تعریف_کن VTA_CENTER TA_CENTER
#تعریف_کن VTA_BOTTOM TA_راست
#تعریف_کن VTA_بالاترین TA_چپ

#تعریف_کن ETO_OPAQUE 0x0002
#تعریف_کن ETO_CLIPPED 0x0004
#تعریف_کن ETO_GLYPH_شاخص 0x0010
#تعریف_کن ETO_RTLREADING 0x0080
#تعریف_کن ETO_NUMERICSLOCAL 0x0400
#تعریف_کن ETO_NUMERICSLATIN 0x0800
#تعریف_کن ETO_IGNORELANGUAGE 0x1000
#تعریف_کن ETO_PDY 0x2000

#تعریف_کن ASPECT_FILTERING 0x0001

#تعریف_کن DCB_RESET 0x0001
#تعریف_کن DCB_ACCUMULATE 0x0002
#تعریف_کن DCB_DIRTY DCB_ACCUMULATE
#تعریف_کن DCB_مجموعه (DCB_RESET | DCB_ACCUMULATE)
#تعریف_کن DCB_ENABLE 0x0004
#تعریف_کن DCB_DISABLE 0x0008

#اگر_تعریف_نشده NOMETAFILE

#تعریف_کن META_SETBKCOLOR 0x0201
#تعریف_کن META_SETBKMODE 0x0102
#تعریف_کن META_SETMAPMODE 0x0103
#تعریف_کن META_SETROP2 0x0104
#تعریف_کن META_SETRELABS 0x0105
#تعریف_کن META_SETPOLYFILLMODE 0x0106
#تعریف_کن META_SETSTRETCHBLTMODE 0x0107
#تعریف_کن META_SETTEXTCHAREXTRA 0x0108
#تعریف_کن META_SETTEXTCOLOR 0x0209
#تعریف_کن META_SETTEXTJUSTIFICATION 0x020A
#تعریف_کن META_SETWINDOWORG 0x020B
#تعریف_کن META_SETWINDOWEXT 0x020C
#تعریف_کن META_SETVIEWPORTORG 0x020D
#تعریف_کن META_SETVIEWPORTEXT 0x020E
#تعریف_کن META_OFFSETWINDOWORG 0x020F
#تعریف_کن META_SCALEWINDOWEXT 0x0410
#تعریف_کن META_OFFSETVIEWPORTORG 0x0211
#تعریف_کن META_SCALEVIEWPORTEXT 0x0412
#تعریف_کن META_LINETO 0x0213
#تعریف_کن META_MOVETO 0x0214
#تعریف_کن META_EXCLUDECLIPRECT 0x0415
#تعریف_کن META_INTERSECTCLIPRECT 0x0416
#تعریف_کن META_ARC 0x0817
#تعریف_کن META_ELLIPSE 0x0418
#تعریف_کن META_FLOODFILL 0x0419
#تعریف_کن META_PIE 0x081A
#تعریف_کن META_RECTANGLE 0x041B
#تعریف_کن META_ROUNDRECT 0x061C
#تعریف_کن META_PATBLT 0x061D
#تعریف_کن META_SAVEDC 0x001E
#تعریف_کن META_SETPIXEL 0x041F
#تعریف_کن META_OFFSETCLIPRGN 0x0220
#تعریف_کن META_TEXTOUT 0x0521
#تعریف_کن META_BITBLT 0x0922
#تعریف_کن META_STRETCHBLT 0x0B23
#تعریف_کن META_POLYGON 0x0324
#تعریف_کن META_POLYLINE 0x0325
#تعریف_کن META_ESCAPE 0x0626
#تعریف_کن META_RESTOREDC 0x0127
#تعریف_کن META_FILLREGION 0x0228
#تعریف_کن META_FRAMEREGION 0x0429
#تعریف_کن META_INVERTREGION 0x012A
#تعریف_کن META_PAINTREGION 0x012B
#تعریف_کن META_SELECTCLIPREGION 0x012C
#تعریف_کن META_SELECTOBJECT 0x012D
#تعریف_کن META_SETTEXTALIGN 0x012E
#تعریف_کن META_CHORD 0x0830
#تعریف_کن META_SETMAPPERFLAGS 0x0231
#تعریف_کن META_EXTTEXTOUT 0x0a32
#تعریف_کن META_SETDIBTODEV 0x0d33
#تعریف_کن META_SELECTPALETTE 0x0234
#تعریف_کن META_REALIZEPALETTE 0x0035
#تعریف_کن META_ANIMATEPALETTE 0x0436
#تعریف_کن META_SETPALENTRIES 0x0037
#تعریف_کن META_POLYPOLYGON 0x0538
#تعریف_کن META_RESIZEPALETTE 0x0139
#تعریف_کن META_DIBBITBLT 0x0940
#تعریف_کن META_DIBSTRETCHBLT 0x0b41
#تعریف_کن META_DIBCREATEPATTERNBRUSH 0x0142
#تعریف_کن META_STRETCHDIB 0x0f43
#تعریف_کن META_EXTFLOODFILL 0x0548
#تعریف_کن META_SETLAYOUT 0x0149
#تعریف_کن META_DELETEOBJECT 0x01f0
#تعریف_کن META_CREATEPALETTE 0x00f7
#تعریف_کن META_CREATEPATTERNBRUSH 0x01F9
#تعریف_کن META_CREATEPENINDIRECT 0x02FA
#تعریف_کن META_CREATEFONTINDIRECT 0x02FB
#تعریف_کن META_CREATEBRUSHINDIRECT 0x02FC
#تعریف_کن META_CREATEREGION 0x06FF

  تعريفنوع بنية _DRAWPATRECT {
    نقطه_3 ptPosition;
    نقطه_3 pt_اندازه;
    کلمه_3 wStyle;
    کلمه_3 w_الگو;
  } DRAWPATRECT,*PDRAWPATRECT;
#پایان_اگر

#تعریف_کن NEWFRAME 1
#تعریف_کن ABORTDOC 2
#تعریف_کن NEXTBAND 3
#تعریف_کن SETCOLORTABLE 4
#تعریف_کن GETCOLORTABLE 5
#تعریف_کن FLUSHOUTPUT 6
#تعریف_کن DRAFTMODE 7
#تعریف_کن QUERYESCSUPPORT 8
#تعریف_کن SETABORTPROC 9
#تعریف_کن STARTDOC 10
#تعریف_کن ENDDOC 11
#تعریف_کن GETPHYSPAGESIZE 12
#تعریف_کن GETPRINTINGOFFSET 13
#تعریف_کن GETSCALINGFACTOR 14
#تعریف_کن MFCOMMENT 15
#تعریف_کن GETPENWIDTH 16
#تعریف_کن SETCOPYCOUNT 17
#تعریف_کن SELECTPAPERSOURCE 18
#تعریف_کن DEVICEDATA 19
#تعریف_کن PASSTHROUGH 19
#تعریف_کن GETTECHNOLGY 20
#تعریف_کن GETTECHNOLOGY 20
#تعریف_کن SETLINECAP 21
#تعریف_کن SETLINEJOIN 22
#تعریف_کن SETMITERLIMIT 23
#تعریف_کن BANDINFO 24
#تعریف_کن DRAWPATTERNRECT 25
#تعریف_کن GETVECTORPENSIZE 26
#تعریف_کن GETVECTORBRUSHSIZE 27
#تعریف_کن ENABLEDUPLEX 28
#تعریف_کن GETSETPAPERBINS 29
#تعریف_کن GETSETPRINTORIENT 30
#تعریف_کن ENUMPAPERBINS 31
#تعریف_کن SETDIBSCALING 32
#تعریف_کن EPSPRINTING 33
#تعریف_کن ENUMPAPERMETRICS 34
#تعریف_کن GETSETPAPERMETRICS 35
#تعریف_کن POSTSCRIPT_داده 37
#تعریف_کن POSTSCRIPT_IGNORE 38
#تعریف_کن MOUSETRAILS 39
#تعریف_کن GETDEVICEUNITS 42

#تعریف_کن GETEXTENDEDTEXTMETRICS 256
#تعریف_کن GETEXTENTTABLE 257
#تعریف_کن GETPAIRKERNTABLE 258
#تعریف_کن GETTRACKKERNTABLE 259
#تعریف_کن EXTTEXTOUT 512
#تعریف_کن GETFACENAME 513
#تعریف_کن DOWNLOADFACE 514
#تعریف_کن ENABLERELATIVEWIDTHS 768
#تعریف_کن ENABLEPAIRKERNING 769
#تعریف_کن SETKERNTRACK 770
#تعریف_کن SETALLJUSTVALUES 771
#تعریف_کن SETCHARSET 772

#تعریف_کن STRETCHBLT 2048
#تعریف_کن METAFILE_DRIVER 2049
#تعریف_کن GETSETSCREENPARAMS 3072
#تعریف_کن QUERYDIBSUPPORT 3073
#تعریف_کن BEGIN_مسیر 4096
#تعریف_کن CLIP_مقصد_مسیر 4097
#تعریف_کن انتها_مسیر 4098
#تعریف_کن EXT_DEVICE_CAPS 4099
#تعریف_کن RESTORE_CTM 4100
#تعریف_کن SAVE_CTM 4101
#تعریف_کن مجموعه_ARC_DIRECTION 4102
#تعریف_کن مجموعه_BACKGROUND_COLOR 4103
#تعریف_کن مجموعه_POLY_نما 4104
#تعریف_کن مجموعه_SCREEN_ANGLE 4105
#تعریف_کن مجموعه_پراکندگی 4106
#تعریف_کن TRANSFORM_CTM 4107
#تعریف_کن مجموعه_CLIP_BOX 4108
#تعریف_کن مجموعه_BOUNDS 4109
#تعریف_کن مجموعه_MIRROR_نما 4110
#تعریف_کن OPENCHANNEL 4110
#تعریف_کن DOWNLOADHEADER 4111
#تعریف_کن CLOSECHANNEL 4112
#تعریف_کن POSTSCRIPT_PASSTHROUGH 4115
#تعریف_کن ENCAPSULATED_POSTSCRIPT 4116

#تعریف_کن POSTSCRIPT_IDENTIFY 4117
#تعریف_کن POSTSCRIPT_INJECTION 4118

#تعریف_کن CHECKJPEGFORMAT 4119
#تعریف_کن CHECKPNGFORMAT 4120

#تعریف_کن GET_PS_FEATURESETTING 4121

#تعریف_کن SPCLPASSTHROUGH2 4568

#تعریف_کن PSIDENT_GDICENTRIC 0
#تعریف_کن PSIDENT_PSCENTRIC 1

  تعريفنوع بنية _PSINJECTDATA {
    DWORD داده_بایتها;
    کلمه_3 Injection_نقطه;
    کلمه_3 صفحه_عدد;
  } PSINJECTDATA,*PPSINJECTDATA;

#تعریف_کن PSINJECT_BEGINSTREAM 1
#تعریف_کن PSINJECT_PSADOBE 2
#تعریف_کن PSINJECT_PAGESATEND 3
#تعریف_کن PSINJECT_صفحات 4

#تعریف_کن PSINJECT_DOCNEEDEDRES 5
#تعریف_کن PSINJECT_DOCSUPPLIEDRES 6
#تعریف_کن PSINJECT_PAGEORDER 7
#تعریف_کن PSINJECT_ORIENTATION 8
#تعریف_کن PSINJECT_BOUNDINGBOX 9
#تعریف_کن PSINJECT_DOCUMENTPROCESSCOLORS 10

#تعریف_کن PSINJECT_COMMENTS 11
#تعریف_کن PSINJECT_BEGINDEFAULTS 12
#تعریف_کن PSINJECT_ENDDEFAULTS 13
#تعریف_کن PSINJECT_BEGINPROLOG 14
#تعریف_کن PSINJECT_ENDPROLOG 15
#تعریف_کن PSINJECT_BEGINSETUP 16
#تعریف_کن PSINJECT_ENDSETUP 17
#تعریف_کن PSINJECT_TRAILER 18
#تعریف_کن PSINJECT_EOF 19
#تعریف_کن PSINJECT_ENDSTREAM 20
#تعریف_کن PSINJECT_DOCUMENTPROCESSCOLORSATEND 21

#تعریف_کن PSINJECT_PAGENUMBER 100
#تعریف_کن PSINJECT_BEGINPAGESETUP 101
#تعریف_کن PSINJECT_ENDPAGESETUP 102
#تعریف_کن PSINJECT_PAGETRAILER 103
#تعریف_کن PSINJECT_PLATECOLOR 104

#تعریف_کن PSINJECT_SHOWPAGE 105
#تعریف_کن PSINJECT_PAGEBBOX 106
#تعریف_کن PSINJECT_ENDPAGECOMMENTS 107

#تعریف_کن PSINJECT_VMSAVE 200
#تعریف_کن PSINJECT_VMRESTORE 201

#تعریف_کن FEATURESETTING_NUP 0
#تعریف_کن FEATURESETTING_OUTPUT 1
#تعریف_کن FEATURESETTING_PSLEVEL 2
#تعریف_کن FEATURESETTING_CUSTPAPER 3
#تعریف_کن FEATURESETTING_MIRROR 4
#تعریف_کن FEATURESETTING_NEGATIVE 5
#تعریف_کن FEATURESETTING_PROTOCOL 6

#تعریف_کن FEATURESETTING_خصوصی_BEGIN 0x1000
#تعریف_کن FEATURESETTING_خصوصی_انتها 0x1FFF

  تعريفنوع بنية _PSFEATURE_OUTPUT {
    WINBOOL b_صفحه_Independent;
    WINBOOL b_مجموعه_صفحه_Device;
  } PSFEATURE_OUTPUT,*PPSFEATURE_OUTPUT;

  تعريفنوع بنية _PSFEATURE_CUSTPAPER {
    LONG lOrientation;
    LONG l_عرض;
    LONG l_ارتفاع;
    LONG l_عرض_جابه_جایی;
    LONG l_ارتفاع_جابه_جایی;
  } PSFEATURE_CUSTPAPER,*PPSFEATURE_CUSTPAPER;

#تعریف_کن PSPROTOCOL_ASCII 0
#تعریف_کن PSPROTOCOL_BCP 1
#تعریف_کن PSPROTOCOL_TBCP 2
#تعریف_کن PSPROTOCOL_دودویی 3

#تعریف_کن QDI_SETDIBITS 1
#تعریف_کن QDI_GETDIBITS 2
#تعریف_کن QDI_DIBTOSCREEN 4
#تعریف_کن QDI_STRETCHDIB 8

#تعریف_کن SP_NOTREPORTED 0x4000
#تعریف_کن SP_ERROR (-1)
#تعریف_کن SP_APPABORT (-2)
#تعریف_کن SP_USERABORT (-3)
#تعریف_کن SP_OUTOFDISK (-4)
#تعریف_کن SP_OUTOFMEMORY (-5)

#تعریف_کن PR_JOBSTATUS 0x0000

#تعریف_کن OBJ_PEN 1
#تعریف_کن OBJ_BRUSH 2
#تعریف_کن OBJ_DC 3
#تعریف_کن OBJ_METADC 4
#تعریف_کن OBJ_PAL 5
#تعریف_کن OBJ_FONT 6
#تعریف_کن OBJ_BITMAP 7
#تعریف_کن OBJ_REGION 8
#تعریف_کن OBJ_METAFILE 9
#تعریف_کن OBJ_MEMDC 10
#تعریف_کن OBJ_EXTPEN 11
#تعریف_کن OBJ_ENHMETADC 12
#تعریف_کن OBJ_ENHMETAFILE 13
#تعریف_کن OBJ_COLORSPACE 14

#تعریف_کن MWT_عنصر_خنثی 1
#تعریف_کن MWT_LEFTMULTIPLY 2
#تعریف_کن MWT_RIGHTMULTIPLY 3

#تعریف_کن MWT_MIN MWT_عنصر_خنثی
#تعریف_کن MWT_MAX MWT_RIGHTMULTIPLY

#تعریف_کن _XFORM_
  تعريفنوع بنية برچسب_XFORM {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
  } XFORM,*PXFORM,*LPXFORM;

  تعريفنوع بنية برچسب_BITMAP {
    LONG bmType;
    LONG bm_عرض;
    LONG bm_ارتفاع;
    LONG bm_عرض_بایتها;
    کلمه_3 bmPlanes;
    کلمه_3 bm_بیتها_Pixel;
    LPVOID bm_بیتها;
  } BITMAP,*PBITMAP,*NPBITMAP,*LPBITMAP;

#ضمن <pshpack1.h>
  تعريفنوع بنية برچسب_RGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
  } RGBTRIPLE;
#ضمن <poppack.h>

  تعريفنوع بنية برچسب_RGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
  } RGBQUAD;
  تعريفنوع RGBQUAD *LPRGBQUAD;

#تعریف_کن CS_ENABLE 0x00000001L
#تعریف_کن CS_DISABLE 0x00000002L
#تعریف_کن CS_DELETE_TRANSFORM 0x00000003L

//!__TINYC__: #define LCS_SIGNATURE 'PSOC'
//!__TINYC__: #define LCS_sRGB 'sRGB'
//!__TINYC__: #define LCS_WINDOWS_COLOR_SPACE 'Win '

  تعريفنوع LONG LCSCSTYPE;
#تعریف_کن LCS_CALIBRATED_RGB 0x00000000L

  تعريفنوع LONG LCSGAMUTMATCH;
#تعریف_کن LCS_GM_BUSINESS 0x00000001L
#تعریف_کن LCS_GM_GRAPHICS 0x00000002L
#تعریف_کن LCS_GM_IMAGES 0x00000004L
#تعریف_کن LCS_GM_ABS_COLORIMETRIC 0x00000008L

#تعریف_کن CM_بیرون_از_GAMUT 255
#تعریف_کن CM_درون_GAMUT 0

#تعریف_کن ICM_ADDPROFILE 1
#تعریف_کن ICM_DELETEPROFILE 2
#تعریف_کن ICM_QUERYPROFILE 3
#تعریف_کن ICM_SETDEFAULTPROFILE 4
#تعریف_کن ICM_REGISTERICMATCHER 5
#تعریف_کن ICM_UNREGISTERICMATCHER 6
#تعریف_کن ICM_QUERYMATCH 7

#تعریف_کن GetKValue(cmyk) ((BYTE)(cmyk))
#تعریف_کن GetYValue(cmyk) ((BYTE)((cmyk)>> 8))
#تعریف_کن GetMValue(cmyk) ((BYTE)((cmyk)>>16))
#تعریف_کن GetCValue(cmyk) ((BYTE)((cmyk)>>24))

#تعریف_کن CMYK(c,m,y,k) ((COLORREF)((((BYTE)(k)|((کلمه_3)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

  تعريفنوع دراز FXPT16DOT16,*LPFXPT16DOT16;
  تعريفنوع دراز FXPT2DOT30,*LPFXPT2DOT30;

  تعريفنوع بنية برچسب_CIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
  } CIEXYZ;
  تعريفنوع CIEXYZ *LPCIEXYZ;

  تعريفنوع بنية برچسب_ICEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
  } CIEXYZTRIPLE;

  تعريفنوع CIEXYZTRIPLE *LPCIEXYZTRIPLE;

  تعريفنوع بنية برچسب_LOGCOLORSPACEA {
    DWORD lcsSignature;
    DWORD lcs_نسخه;
    DWORD lcs_اندازه;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    CHAR lcsFilename[MAX_مسیر];
  } LOGCOLORSPACEA,*LPLOGCOLORSPACEA;

  تعريفنوع بنية برچسب_LOGCOLORSPACEW {
    DWORD lcsSignature;
    DWORD lcs_نسخه;
    DWORD lcs_اندازه;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    WCHAR lcsFilename[MAX_مسیر];
  } LOGCOLORSPACEW,*LPLOGCOLORSPACEW;

#اگر_تعریف_شده UNICODE
  تعريفنوع LOGCOLORSPACEW LOGCOLORSPACE;
  تعريفنوع LPLOGCOLORSPACEW LPLOGCOLORSPACE;
#وإلا
  تعريفنوع LOGCOLORSPACEA LOGCOLORSPACE;
  تعريفنوع LPLOGCOLORSPACEA LPLOGCOLORSPACE;
#پایان_اگر

  تعريفنوع بنية برچسب_BITMAPCOREHEADER {
    DWORD bc_اندازه;
    کلمه_3 bc_عرض;
    کلمه_3 bc_ارتفاع;
    کلمه_3 bcPlanes;
    کلمه_3 bc_بیت_شمار;
  } BITMAPCOREHEADER,*LPBITMAPCOREHEADER,*PBITMAPCOREHEADER;

  تعريفنوع بنية برچسب_BITMAPINFOHEADER {
    DWORD bi_اندازه;
    LONG bi_عرض;
    LONG bi_ارتفاع;
    کلمه_3 biPlanes;
    کلمه_3 bi_بیت_شمار;
    DWORD biCompression;
    DWORD bi_اندازه_Image;
    LONG bi_XPels_در_هر_Meter;
    LONG bi_YPels_در_هر_Meter;
    DWORD bi_Clr_استفاده_شده;
    DWORD biClrImportant;
  } BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

  تعريفنوع بنية {
    DWORD b_V4_اندازه;
    LONG b_V4_عرض;
    LONG b_V4_ارتفاع;
    کلمه_3 bV4Planes;
    کلمه_3 b_V4_بیت_شمار;
    DWORD bV4V4Compression;
    DWORD b_V4_اندازه_Image;
    LONG b_V4_XPels_در_هر_Meter;
    LONG b_V4_YPels_در_هر_Meter;
    DWORD b_V4_Clr_استفاده_شده;
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
  } BITMAPV4_سرآیند,*LPBITMAPV4_سرآیند,*PBITMAPV4_سرآیند;

  تعريفنوع بنية {
    DWORD b_V5_اندازه;
    LONG b_V5_عرض;
    LONG b_V5_ارتفاع;
    کلمه_3 bV5Planes;
    کلمه_3 b_V5_بیت_شمار;
    DWORD bV5Compression;
    DWORD b_V5_اندازه_Image;
    LONG b_V5_XPels_در_هر_Meter;
    LONG b_V5_YPels_در_هر_Meter;
    DWORD b_V5_Clr_استفاده_شده;
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
    DWORD b_V5_Profile_داده;
    DWORD b_V5_Profile_اندازه;
    DWORD bV5Reserved;
  } BITMAPV5_سرآیند,*LPBITMAPV5_سرآیند,*PBITMAPV5_سرآیند;

//!__TINYC__: #define PROFILE_LINKED 'LINK'
//!__TINYC__: #define PROFILE_EMBEDDED 'MBED'

#تعریف_کن BI_RGB 0L
#تعریف_کن BI_RLE8 1L
#تعریف_کن BI_RLE4 2L
#تعریف_کن BI_BITFIELDS 3L
#تعریف_کن BI_JPEG 4L
#تعریف_کن BI_PNG 5L

  تعريفنوع بنية برچسب_BITMAPINFO {
    BITMAPINFOHEADER bmi_سرآیند;
    RGBQUAD bmiColors[1];
  } BITMAPINFO,*LPBITMAPINFO,*PBITMAPINFO;

  تعريفنوع بنية برچسب_BITMAPCOREINFO {
    BITMAPCOREHEADER bmci_سرآیند;
    RGBTRIPLE bmciColors[1];
  } BITMAPCOREINFO,*LPBITMAPCOREINFO,*PBITMAPCOREINFO;

#ضمن <pshpack2.h>
  تعريفنوع بنية برچسب_BITMAPFILEHEADER {
    کلمه_3 bfType;
    DWORD bf_اندازه;
    کلمه_3 bfReserved1;
    کلمه_3 bfReserved2;
    DWORD bf_Off_بیتها;
  } BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#ضمن <poppack.h>

#تعریف_کن MAKEPOINTS(l) (*((POINTS *)&(l)))

#اگر_تعریف_نشده NOFONTSIG
  تعريفنوع بنية برچسب_FONTSIGNATURE {
    DWORD fsUsb[4];
    DWORD fsCsb[2];
  } FONTSIGNATURE,*PFONTSIGNATURE,*LPFONTSIGNATURE;

  تعريفنوع بنية برچسب_CHARSETINFO {
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
  } CHARSETINFO,*PCHARSETINFO,*NPCHARSETINFO,*LPCHARSETINFO;

#تعریف_کن TCI_SRCCHARSET 1
#تعریف_کن TCI_SRCCODEPAGE 2
#تعریف_کن TCI_SRCFONTSIG 3
#تعریف_کن TCI_SRCLOCALE 0x1000

  تعريفنوع بنية برچسب_LOCALESIGNATURE {
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
  } LOCALESIGNATURE,*PLOCALESIGNATURE,*LPLOCALESIGNATURE;
#پایان_اگر


#اگر_تعریف_نشده NOMETAFILE
  تعريفنوع بنية برچسب_HANDLETABLE {
    HGDIOBJ objectHandle[1];
  } HANDLETABLE,*PHANDLETABLE,*LPHANDLETABLE;

  تعريفنوع بنية برچسب_METARECORD {
    DWORD rd_اندازه;
    کلمه_3 rdFunction;
    کلمه_3 rdParm[1];
  } METARECORD;
  تعريفنوع بنية برچسب_METARECORD UNALIGNED *PMETARECORD;
  تعريفنوع بنية برچسب_METARECORD UNALIGNED *LPMETARECORD;

  تعريفنوع بنية برچسب_METAFILEPICT {
    LONG mm;
    LONG xExt;
    LONG yExt;
    HMETAFILE hMF;
  } METAFILEPICT,*LPMETAFILEPICT;

#ضمن <pshpack2.h>
  تعريفنوع بنية برچسب_METAHEADER {
    کلمه_3 mtType;
    کلمه_3 mt_سرآیند_اندازه;
    کلمه_3 mt_نسخه;
    DWORD mt_اندازه;
    کلمه_3 mtNoObjects;
    DWORD mt_Max_رکورد;
    کلمه_3 mtNoParameters;
  } METAHEADER;
  تعريفنوع بنية برچسب_METAHEADER UNALIGNED *PMETAHEADER;
  تعريفنوع بنية برچسب_METAHEADER UNALIGNED *LPMETAHEADER;

#ضمن <poppack.h>

  تعريفنوع بنية برچسب_ENHMETARECORD {
    DWORD iType;
    DWORD n_اندازه;
    DWORD dParm[1];
  } ENHMETARECORD,*PENHMETARECORD,*LPENHMETARECORD;

  تعريفنوع بنية برچسب_ENHMETAHEADER {
    DWORD iType;
    DWORD n_اندازه;
    RECTL rclBounds;
    RECTL rcl_قاب;
    DWORD dSignature;
    DWORD n_نسخه;
    DWORD n_بایتها;
    DWORD n_رکوردها;
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
#پایان_اگر

#اگر_تعریف_نشده NOTEXTMETRIC
#تعریف_کن TMPF_FIXED_PITCH 0x01
#تعریف_کن TMPF_وکتور 0x02
#تعریف_کن TMPF_DEVICE 0x08
#تعریف_کن TMPF_TRUETYPE 0x04

#اگر_تعریف_شده UNICODE
  تعريفنوع WCHAR BCHAR;
#وإلا
  تعريفنوع BYTE BCHAR;
#پایان_اگر

#اگر_تعریف_نشده _TEXTMETRIC_DEFINED
#تعریف_کن _TEXTMETRIC_DEFINED
  تعريفنوع بنية برچسب_TEXTMETRICA {
    LONG tm_ارتفاع;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_داخلی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_عرض;
    LONG tm_Max_Char_عرض;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_اولی_Char;
    BYTE tm_آخرین_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_بیرون;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_مجموعه;
  } TEXTMETRICA,*PTEXTMETRICA,*NPTEXTMETRICA,*LPTEXTMETRICA;

  تعريفنوع بنية برچسب_TEXTMETRICW {
    LONG tm_ارتفاع;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_داخلی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_عرض;
    LONG tm_Max_Char_عرض;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_اولی_Char;
    WCHAR tm_آخرین_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_بیرون;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_مجموعه;
  } TEXTMETRICW,*PTEXTMETRICW,*NPTEXTMETRICW,*LPTEXTMETRICW;
#اگر_تعریف_شده UNICODE
  تعريفنوع TEXTMETRICW TEXTMETRIC;
  تعريفنوع PTEXTMETRICW PTEXTMETRIC;
  تعريفنوع NPTEXTMETRICW NPTEXTMETRIC;
  تعريفنوع LPTEXTMETRICW LPTEXTMETRIC;
#وإلا
  تعريفنوع TEXTMETRICA TEXTMETRIC;
  تعريفنوع PTEXTMETRICA PTEXTMETRIC;
  تعريفنوع NPTEXTMETRICA NPTEXTMETRIC;
  تعريفنوع LPTEXTMETRICA LPTEXTMETRIC;
#پایان_اگر
#پایان_اگر

#تعریف_کن NTM_REGULAR 0x00000040L
#تعریف_کن NTM_BOLD 0x00000020L
#تعریف_کن NTM_ITALIC 0x00000001L

#تعریف_کن NTM_NONNEGATIVE_AC 0x00010000
#تعریف_کن NTM_PS_OPENTYPE 0x00020000
#تعریف_کن NTM_TT_OPENTYPE 0x00040000
#تعریف_کن NTM_MULTIPLEMASTER 0x00080000
#تعریف_کن NTM_TYPE1 0x00100000
#تعریف_کن NTM_DSIG 0x00200000

#ضمن <pshpack4.h>
  تعريفنوع بنية برچسب_NEWTEXTMETRICA {
    LONG tm_ارتفاع;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_داخلی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_عرض;
    LONG tm_Max_Char_عرض;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_اولی_Char;
    BYTE tm_آخرین_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_بیرون;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_مجموعه;
    DWORD ntmFlags;
    UINT ntm_اندازه_EM;
    UINT ntm_Cell_ارتفاع;
    UINT ntm_Avg_عرض;
  } NEWTEXTMETRICA,*PNEWTEXTMETRICA,*NPNEWTEXTMETRICA,*LPNEWTEXTMETRICA;

  تعريفنوع بنية برچسب_NEWTEXTMETRICW {
    LONG tm_ارتفاع;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_داخلی_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_عرض;
    LONG tm_Max_Char_عرض;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_اولی_Char;
    WCHAR tm_آخرین_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_بیرون;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_مجموعه;
    DWORD ntmFlags;
    UINT ntm_اندازه_EM;
    UINT ntm_Cell_ارتفاع;
    UINT ntm_Avg_عرض;
  } NEWTEXTMETRICW,*PNEWTEXTMETRICW,*NPNEWTEXTMETRICW,*LPNEWTEXTMETRICW;
#اگر_تعریف_شده UNICODE
  تعريفنوع NEWTEXTMETRICW NEWTEXTMETRIC;
  تعريفنوع PNEWTEXTMETRICW PNEWTEXTMETRIC;
  تعريفنوع NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
  تعريفنوع LPNEWTEXTMETRICW LPNEWTEXTMETRIC;
#وإلا
  تعريفنوع NEWTEXTMETRICA NEWTEXTMETRIC;
  تعريفنوع PNEWTEXTMETRICA PNEWTEXTMETRIC;
  تعريفنوع NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
  تعريفنوع LPNEWTEXTMETRICA LPNEWTEXTMETRIC;
#پایان_اگر
#ضمن <poppack.h>

  تعريفنوع بنية برچسب_NEWTEXTMETRICEXA {
    NEWTEXTMETRICA ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXA;

  تعريفنوع بنية برچسب_NEWTEXTMETRICEXW {
    NEWTEXTMETRICW ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXW;
#اگر_تعریف_شده UNICODE
  تعريفنوع NEWTEXTMETRICEXW NEWTEXTMETRICEX;
#وإلا
  تعريفنوع NEWTEXTMETRICEXA NEWTEXTMETRICEX;
#پایان_اگر
#پایان_اگر

  تعريفنوع بنية برچسب_PELARRAY {
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
  } PELARRAY,*PPELARRAY,*NPPELARRAY,*LPPELARRAY;

  تعريفنوع بنية برچسب_LOGBRUSH {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
  } LOGBRUSH,*PLOGBRUSH,*NPLOGBRUSH,*LPLOGBRUSH;

  تعريفنوع بنية برچسب_LOGBRUSH32 {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG lbHatch;
  } LOGBRUSH32,*PLOGBRUSH32,*NPLOGBRUSH32,*LPLOGBRUSH32;

  تعريفنوع LOGBRUSH الگو_2;
  تعريفنوع الگو_2 *PPATTERN;
  تعريفنوع الگو_2 *NPPATTERN;
  تعريفنوع الگو_2 *LPPATTERN;

  تعريفنوع بنية برچسب_LOGPEN {
    UINT lopnStyle;
    نقطه_3 lopn_عرض;
    COLORREF lopnColor;
  } LOGPEN,*PLOGPEN,*NPLOGPEN,*LPLOGPEN;

  تعريفنوع بنية برچسب_EXTLOGPEN {
    DWORD elpPenStyle;
    DWORD elp_عرض;
    UINT elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elp_رقم_Entries;
    DWORD elp_Style_مدخل[1];
  } EXTLOGPEN,*PEXTLOGPEN,*NPEXTLOGPEN,*LPEXTLOGPEN;

#اگر_تعریف_نشده _PALETTEENTRY_DEFINED
#تعریف_کن _PALETTEENTRY_DEFINED
  تعريفنوع بنية برچسب_PALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
  } PALETTEENTRY,*PPALETTEENTRY,*LPPALETTEENTRY;
#پایان_اگر

#اگر_تعریف_نشده _LOGPALETTE_DEFINED
#تعریف_کن _LOGPALETTE_DEFINED

  تعريفنوع بنية برچسب_LOGPALETTE {
    کلمه_3 pal_نسخه;
    کلمه_3 pal_رقم_Entries;
    PALETTEENTRY pal_Pal_مدخل[1];
  } LOGPALETTE,*PLOGPALETTE,*NPLOGPALETTE,*LPLOGPALETTE;
#پایان_اگر

#تعریف_کن LF_FACESIZE 32

  تعريفنوع بنية برچسب_LOGFONTA {
    LONG lf_ارتفاع;
    LONG lf_عرض;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_وزن;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_بیرون;
    BYTE lf_Char_مجموعه;
    BYTE lf_بیرون_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[LF_FACESIZE];
  } LOGFONTA,*PLOGFONTA,*NPLOGFONTA,*LPLOGFONTA;

  تعريفنوع بنية برچسب_LOGFONTW {
    LONG lf_ارتفاع;
    LONG lf_عرض;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_وزن;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_بیرون;
    BYTE lf_Char_مجموعه;
    BYTE lf_بیرون_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[LF_FACESIZE];
  } LOGFONTW,*PLOGFONTW,*NPLOGFONTW,*LPLOGFONTW;
#اگر_تعریف_شده UNICODE
  تعريفنوع LOGFONTW LOGFONT;
  تعريفنوع PLOGFONTW PLOGFONT;
  تعريفنوع NPLOGFONTW NPLOGFONT;
  تعريفنوع LPLOGFONTW LPLOGFONT;
#وإلا
  تعريفنوع LOGFONTA LOGFONT;
  تعريفنوع PLOGFONTA PLOGFONT;
  تعريفنوع NPLOGFONTA NPLOGFONT;
  تعريفنوع LPLOGFONTA LPLOGFONT;
#پایان_اگر

#تعریف_کن LF_FULLFACESIZE 64

  تعريفنوع بنية برچسب_ENUMLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_پر_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
  } ENUMLOGFONTA,*LPENUMLOGFONTA;

  تعريفنوع بنية برچسب_ENUMLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_پر_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
  } ENUMLOGFONTW,*LPENUMLOGFONTW;
#اگر_تعریف_شده UNICODE
  تعريفنوع ENUMLOGFONTW ENUMLOGFONT;
  تعريفنوع LPENUMLOGFONTW LPENUMLOGFONT;
#وإلا
  تعريفنوع ENUMLOGFONTA ENUMLOGFONT;
  تعريفنوع LPENUMLOGFONTA LPENUMLOGFONT;
#پایان_اگر

  تعريفنوع بنية برچسب_ENUMLOGFONTEXA {
    LOGFONTA elfLogFont;
    BYTE elf_پر_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    BYTE elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXA,*LPENUMLOGFONTEXA;

  تعريفنوع بنية برچسب_ENUMLOGFONTEXW {
    LOGFONTW elfLogFont;
    WCHAR elf_پر_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    WCHAR elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXW,*LPENUMLOGFONTEXW;
#اگر_تعریف_شده UNICODE
  تعريفنوع ENUMLOGFONTEXW ENUMLOGFONTEX;
  تعريفنوع LPENUMLOGFONTEXW LPENUMLOGFONTEX;
#وإلا
  تعريفنوع ENUMLOGFONTEXA ENUMLOGFONTEX;
  تعريفنوع LPENUMLOGFONTEXA LPENUMLOGFONTEX;
#پایان_اگر

#تعریف_کن بیرون_DEFAULT_PRECIS 0
#تعریف_کن بیرون_STRING_PRECIS 1
#تعریف_کن بیرون_CHARACTER_PRECIS 2
#تعریف_کن بیرون_STROKE_PRECIS 3
#تعریف_کن بیرون_TT_PRECIS 4
#تعریف_کن بیرون_DEVICE_PRECIS 5
#تعریف_کن بیرون_RASTER_PRECIS 6
#تعریف_کن بیرون_TT_ONLY_PRECIS 7
#تعریف_کن بیرون_OUTLINE_PRECIS 8
#تعریف_کن بیرون_SCREEN_OUTLINE_PRECIS 9
#تعریف_کن بیرون_PS_ONLY_PRECIS 10

#تعریف_کن CLIP_DEFAULT_PRECIS 0
#تعریف_کن CLIP_CHARACTER_PRECIS 1
#تعریف_کن CLIP_STROKE_PRECIS 2
#تعریف_کن CLIP_ماسک 0xf
#تعریف_کن CLIP_LH_ANGLES (1<<4)
#تعریف_کن CLIP_TT_ALWAYS (2<<4)
#تعریف_کن CLIP_DFA_DISABLE (4<<4)
#تعریف_کن CLIP_EMBEDDED (8<<4)

#تعریف_کن DEFAULT_QUALITY 0
#تعریف_کن DRAFT_QUALITY 1
#تعریف_کن PROOF_QUALITY 2
#تعریف_کن NONANTIALIASED_QUALITY 3
#تعریف_کن ANTIALIASED_QUALITY 4

#تعریف_کن CLEARTYPE_QUALITY 5
#تعریف_کن CLEARTYPE_NATURAL_QUALITY 6

#تعریف_کن DEFAULT_PITCH 0
#تعریف_کن FIXED_PITCH 1
#تعریف_کن VARIABLE_PITCH 2
#تعریف_کن MONO_FONT 8

#تعریف_کن ANSI_CHARSET 0
#تعریف_کن DEFAULT_CHARSET 1
#تعریف_کن نماد_CHARSET 2
#تعریف_کن SHIFTJIS_CHARSET 128
#تعریف_کن HANGEUL_CHARSET 129
#تعریف_کن HANGUL_CHARSET 129
#تعریف_کن GB2312_CHARSET 134
#تعریف_کن CHINESEBIG5_CHARSET 136
#تعریف_کن OEM_CHARSET 255
#تعریف_کن JOHAB_CHARSET 130
#تعریف_کن HEBREW_CHARSET 177
#تعریف_کن ARABIC_CHARSET 178
#تعریف_کن GREEK_CHARSET 161
#تعریف_کن TURKISH_CHARSET 162
#تعریف_کن VIETNAMESE_CHARSET 163
#تعریف_کن THAI_CHARSET 222
#تعریف_کن EASTEUROPE_CHARSET 238
#تعریف_کن RUSSIAN_CHARSET 204

#تعریف_کن MAC_CHARSET 77
#تعریف_کن BALTIC_CHARSET 186

#تعریف_کن FS_LATIN1 0x00000001L
#تعریف_کن FS_LATIN2 0x00000002L
#تعریف_کن FS_CYRILLIC 0x00000004L
#تعریف_کن FS_GREEK 0x00000008L
#تعریف_کن FS_TURKISH 0x00000010L
#تعریف_کن FS_HEBREW 0x00000020L
#تعریف_کن FS_ARABIC 0x00000040L
#تعریف_کن FS_BALTIC 0x00000080L
#تعریف_کن FS_VIETNAMESE 0x00000100L
#تعریف_کن FS_THAI 0x00010000L
#تعریف_کن FS_JISJAPAN 0x00020000L
#تعریف_کن FS_CHINESESIMP 0x00040000L
#تعریف_کن FS_WANSUNG 0x00080000L
#تعریف_کن FS_CHINESETRAD 0x00100000L
#تعریف_کن FS_JOHAB 0x00200000L
#تعریف_کن FS_نماد 0x80000000L

#تعریف_کن FF_DONTCARE (0<<4)
#تعریف_کن FF_ROMAN (1<<4)

#تعریف_کن FF_SWISS (2<<4)

#تعریف_کن FF_MODERN (3<<4)

#تعریف_کن FF_SCRIPT (4<<4)
#تعریف_کن FF_DECORATIVE (5<<4)

#تعریف_کن FW_DONTCARE 0
#تعریف_کن FW_THIN 100
#تعریف_کن FW_EXTRALIGHT 200
#تعریف_کن FW_LIGHT 300
#تعریف_کن FW_نرمال 400
#تعریف_کن FW_MEDIUM 500
#تعریف_کن FW_SEMIBOLD 600
#تعریف_کن FW_BOLD 700
#تعریف_کن FW_EXTRABOLD 800
#تعریف_کن FW_HEAVY 900

#تعریف_کن FW_ULTRALIGHT FW_EXTRALIGHT
#تعریف_کن FW_REGULAR FW_نرمال
#تعریف_کن FW_DEMIBOLD FW_SEMIBOLD
#تعریف_کن FW_ULTRABOLD FW_EXTRABOLD
#تعریف_کن FW_BLACK FW_HEAVY

#تعریف_کن PANOSE_شمار 10
#تعریف_کن PAN_FAMILYTYPE_شاخص 0
#تعریف_کن PAN_SERIFSTYLE_شاخص 1
#تعریف_کن PAN_وزن_شاخص 2
#تعریف_کن PAN_PROPORTION_شاخص 3
#تعریف_کن PAN_CONTRAST_شاخص 4
#تعریف_کن PAN_STROKEVARIATION_شاخص 5
#تعریف_کن PAN_ARMSTYLE_شاخص 6
#تعریف_کن PAN_LETTERFORM_شاخص 7
#تعریف_کن PAN_MIDLINE_شاخص 8
#تعریف_کن PAN_XHEIGHT_شاخص 9

#تعریف_کن PAN_CULTURE_LATIN 0

  تعريفنوع بنية برچسب_PANOSE {
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

#تعریف_کن PAN_ANY 0
#تعریف_کن PAN_NO_FIT 1

#تعریف_کن PAN_FAMILY_متن_DISPLAY 2
#تعریف_کن PAN_FAMILY_SCRIPT 3
#تعریف_کن PAN_FAMILY_DECORATIVE 4
#تعریف_کن PAN_FAMILY_PICTORIAL 5

#تعریف_کن PAN_SERIF_COVE 2
#تعریف_کن PAN_SERIF_OBTUSE_COVE 3
#تعریف_کن PAN_SERIF_مربع_COVE 4
#تعریف_کن PAN_SERIF_OBTUSE_مربع_COVE 5
#تعریف_کن PAN_SERIF_مربع 6
#تعریف_کن PAN_SERIF_THIN 7
#تعریف_کن PAN_SERIF_BONE 8
#تعریف_کن PAN_SERIF_EXAGGERATED 9
#تعریف_کن PAN_SERIF_TRIANGLE 10
#تعریف_کن PAN_SERIF_نرمال_SANS 11
#تعریف_کن PAN_SERIF_OBTUSE_SANS 12
#تعریف_کن PAN_SERIF_PERP_SANS 13
#تعریف_کن PAN_SERIF_FLARED 14
#تعریف_کن PAN_SERIF_ROUNDED 15

#تعریف_کن PAN_وزن_VERY_LIGHT 2
#تعریف_کن PAN_وزن_LIGHT 3
#تعریف_کن PAN_وزن_THIN 4
#تعریف_کن PAN_وزن_BOOK 5
#تعریف_کن PAN_وزن_MEDIUM 6
#تعریف_کن PAN_وزن_DEMI 7
#تعریف_کن PAN_وزن_BOLD 8
#تعریف_کن PAN_وزن_HEAVY 9
#تعریف_کن PAN_وزن_BLACK 10
#تعریف_کن PAN_وزن_NORD 11

#تعریف_کن PAN_PROP_OLD_STYLE 2
#تعریف_کن PAN_PROP_MODERN 3
#تعریف_کن PAN_PROP_EVEN_عرض 4
#تعریف_کن PAN_PROP_EXPANDED 5
#تعریف_کن PAN_PROP_CONDENSED 6
#تعریف_کن PAN_PROP_VERY_EXPANDED 7
#تعریف_کن PAN_PROP_VERY_CONDENSED 8
#تعریف_کن PAN_PROP_MONOSPACED 9

#تعریف_کن PAN_CONTRAST_NONE 2
#تعریف_کن PAN_CONTRAST_VERY_کم 3
#تعریف_کن PAN_CONTRAST_کم 4
#تعریف_کن PAN_CONTRAST_MEDIUM_کم 5
#تعریف_کن PAN_CONTRAST_MEDIUM 6
#تعریف_کن PAN_CONTRAST_MEDIUM_بالا 7
#تعریف_کن PAN_CONTRAST_بالا 8
#تعریف_کن PAN_CONTRAST_VERY_بالا 9

#تعریف_کن PAN_STROKE_GRADUAL_DIAG 2
#تعریف_کن PAN_STROKE_GRADUAL_TRAN 3
#تعریف_کن PAN_STROKE_GRADUAL_VERT 4
#تعریف_کن PAN_STROKE_GRADUAL_HORZ 5
#تعریف_کن PAN_STROKE_RAPID_VERT 6
#تعریف_کن PAN_STROKE_RAPID_HORZ 7
#تعریف_کن PAN_STROKE_INSTANT_VERT 8

#تعریف_کن PAN_STRAIGHT_ARMS_HORZ 2
#تعریف_کن PAN_STRAIGHT_ARMS_WEDGE 3
#تعریف_کن PAN_STRAIGHT_ARMS_VERT 4
#تعریف_کن PAN_STRAIGHT_ARMS_SINGLE_SERIF 5
#تعریف_کن PAN_STRAIGHT_ARMS_DOUBLE_SERIF 6
#تعریف_کن PAN_BENT_ARMS_HORZ 7
#تعریف_کن PAN_BENT_ARMS_WEDGE 8
#تعریف_کن PAN_BENT_ARMS_VERT 9
#تعریف_کن PAN_BENT_ARMS_SINGLE_SERIF 10
#تعریف_کن PAN_BENT_ARMS_DOUBLE_SERIF 11

#تعریف_کن PAN_LETT_نرمال_CONTACT 2
#تعریف_کن PAN_LETT_نرمال_WEIGHTED 3
#تعریف_کن PAN_LETT_نرمال_BOXED 4
#تعریف_کن PAN_LETT_نرمال_FLATTENED 5
#تعریف_کن PAN_LETT_نرمال_ROUNDED 6
#تعریف_کن PAN_LETT_نرمال_OFF_CENTER 7
#تعریف_کن PAN_LETT_نرمال_مربع 8
#تعریف_کن PAN_LETT_OBLIQUE_CONTACT 9
#تعریف_کن PAN_LETT_OBLIQUE_WEIGHTED 10
#تعریف_کن PAN_LETT_OBLIQUE_BOXED 11
#تعریف_کن PAN_LETT_OBLIQUE_FLATTENED 12
#تعریف_کن PAN_LETT_OBLIQUE_ROUNDED 13
#تعریف_کن PAN_LETT_OBLIQUE_OFF_CENTER 14
#تعریف_کن PAN_LETT_OBLIQUE_مربع 15

#تعریف_کن PAN_MIDLINE_STANDARD_TRIMMED 2
#تعریف_کن PAN_MIDLINE_STANDARD_POINTED 3
#تعریف_کن PAN_MIDLINE_STANDARD_SERIFED 4
#تعریف_کن PAN_MIDLINE_بالا_TRIMMED 5
#تعریف_کن PAN_MIDLINE_بالا_POINTED 6
#تعریف_کن PAN_MIDLINE_بالا_SERIFED 7
#تعریف_کن PAN_MIDLINE_CONSTANT_TRIMMED 8
#تعریف_کن PAN_MIDLINE_CONSTANT_POINTED 9
#تعریف_کن PAN_MIDLINE_CONSTANT_SERIFED 10
#تعریف_کن PAN_MIDLINE_کم_TRIMMED 11
#تعریف_کن PAN_MIDLINE_کم_POINTED 12
#تعریف_کن PAN_MIDLINE_کم_SERIFED 13

#تعریف_کن PAN_XHEIGHT_CONSTANT_SMALL 2
#تعریف_کن PAN_XHEIGHT_CONSTANT_STD 3
#تعریف_کن PAN_XHEIGHT_CONSTANT_LARGE 4
#تعریف_کن PAN_XHEIGHT_DUCKING_SMALL 5
#تعریف_کن PAN_XHEIGHT_DUCKING_STD 6
#تعریف_کن PAN_XHEIGHT_DUCKING_LARGE 7

#تعریف_کن ELF_VENDOR_اندازه 4

  تعريفنوع بنية برچسب_EXTLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_پر_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    DWORD elf_نسخه;
    DWORD elf_Style_اندازه;
    DWORD elf_تطابق;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_اندازه];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTA,*PEXTLOGFONTA,*NPEXTLOGFONTA,*LPEXTLOGFONTA;

  تعريفنوع بنية برچسب_EXTLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_پر_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    DWORD elf_نسخه;
    DWORD elf_Style_اندازه;
    DWORD elf_تطابق;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_اندازه];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTW,*PEXTLOGFONTW,*NPEXTLOGFONTW,*LPEXTLOGFONTW;
#اگر_تعریف_شده UNICODE
  تعريفنوع EXTLOGFONTW EXTLOGFONT;
  تعريفنوع PEXTLOGFONTW PEXTLOGFONT;
  تعريفنوع NPEXTLOGFONTW NPEXTLOGFONT;
  تعريفنوع LPEXTLOGFONTW LPEXTLOGFONT;
#وإلا
  تعريفنوع EXTLOGFONTA EXTLOGFONT;
  تعريفنوع PEXTLOGFONTA PEXTLOGFONT;
  تعريفنوع NPEXTLOGFONTA NPEXTLOGFONT;
  تعريفنوع LPEXTLOGFONTA LPEXTLOGFONT;
#پایان_اگر

#تعریف_کن ELF_نسخه 0
#تعریف_کن ELF_CULTURE_LATIN 0

#تعریف_کن RASTER_FONTTYPE 0x0001
#تعریف_کن DEVICE_FONTTYPE 0x002
#تعریف_کن TRUETYPE_FONTTYPE 0x004

#تعریف_کن RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((کلمه_3)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#تعریف_کن PALETTERGB(r,g,b) (0x02000000 | RGB(r,g,b))
#تعریف_کن PALETTEINDEX(i) ((COLORREF)(0x01000000 | (DWORD)(کلمه_3)(i)))

#تعریف_کن PC_RESERVED 0x01
#تعریف_کن PC_EXPLICIT 0x02
#تعریف_کن PC_NOCOLLAPSE 0x04

#تعریف_کن GetRValue(rgb) (LOBYTE(rgb))
#تعریف_کن GetGValue(rgb) (LOBYTE(((کلمه_3)(rgb)) >> 8))
#تعریف_کن GetBValue(rgb) (LOBYTE((rgb)>>16))

#تعریف_کن TRANSPARENT 1
#تعریف_کن OPAQUE 2
#تعریف_کن BKMODE_آخرین 2

#تعریف_کن GM_COMPATIBLE 1
#تعریف_کن GM_ADVANCED 2
#تعریف_کن GM_آخرین 2

#تعریف_کن PT_CLOSEFIGURE 0x01
#تعریف_کن PT_LINETO 0x02
#تعریف_کن PT_BEZIERTO 0x04
#تعریف_کن PT_MOVETO 0x06

#تعریف_کن MM_متن 1
#تعریف_کن MM_LOMETRIC 2
#تعریف_کن MM_HIMETRIC 3
#تعریف_کن MM_LOENGLISH 4
#تعریف_کن MM_HIENGLISH 5
#تعریف_کن MM_TWIPS 6
#تعریف_کن MM_ISOTROPIC 7
#تعریف_کن MM_ANISOTROPIC 8

#تعریف_کن MM_MIN MM_متن
#تعریف_کن MM_MAX MM_ANISOTROPIC
#تعریف_کن MM_MAX_FIXEDSCALE MM_TWIPS

#تعریف_کن ABSOLUTE 1
#تعریف_کن RELATIVE 2

#تعریف_کن WHITE_BRUSH 0
#تعریف_کن LTGRAY_BRUSH 1
#تعریف_کن خاکستری_BRUSH 2
#تعریف_کن DKGRAY_BRUSH 3
#تعریف_کن BLACK_BRUSH 4
#تعریف_کن NULL_BRUSH 5
#تعریف_کن HOLLOW_BRUSH NULL_BRUSH
#تعریف_کن WHITE_PEN 6
#تعریف_کن BLACK_PEN 7
#تعریف_کن NULL_PEN 8
#تعریف_کن OEM_FIXED_FONT 10
#تعریف_کن ANSI_FIXED_FONT 11
#تعریف_کن ANSI_VAR_FONT 12
#تعریف_کن SYSTEM_FONT 13
#تعریف_کن DEVICE_DEFAULT_FONT 14
#تعریف_کن DEFAULT_PALETTE 15
#تعریف_کن SYSTEM_FIXED_FONT 16

#تعریف_کن DEFAULT_GUI_FONT 17

#تعریف_کن DC_BRUSH 18
#تعریف_کن DC_PEN 19

#تعریف_کن STOCK_آخرین 19

#تعریف_کن CLR_INVALID 0xFFFFFFFF

#تعریف_کن BS_SOLID 0
#تعریف_کن BS_NULL 1
#تعریف_کن BS_HOLLOW BS_NULL
#تعریف_کن BS_HATCHED 2
#تعریف_کن BS_الگو 3
#تعریف_کن BS_نمایهای 4
#تعریف_کن BS_DIBPATTERN 5
#تعریف_کن BS_DIBPATTERNPT 6
#تعریف_کن BS_PATTERN8X8 7
#تعریف_کن BS_DIBPATTERN8X8 8
#تعریف_کن BS_MONOPATTERN 9

#تعریف_کن HS_HORIZONTAL 0
#تعریف_کن HS_VERTICAL 1
#تعریف_کن HS_FDIAGONAL 2
#تعریف_کن HS_BDIAGONAL 3
#تعریف_کن HS_CROSS 4
#تعریف_کن HS_DIAGCROSS 5

#تعریف_کن PS_SOLID 0
#تعریف_کن PS_DASH 1
#تعریف_کن PS_DOT 2
#تعریف_کن PS_DASHDOT 3
#تعریف_کن PS_DASHDOTDOT 4
#تعریف_کن PS_NULL 5
#تعریف_کن PS_INSIDEFRAME 6
#تعریف_کن PS_USERSTYLE 7
#تعریف_کن PS_ALTERNATE 8
#تعریف_کن PS_STYLE_ماسک 0x0000000F

#تعریف_کن PS_ENDCAP_دور 0x00000000
#تعریف_کن PS_ENDCAP_مربع 0x00000100
#تعریف_کن PS_ENDCAP_FLAT 0x00000200
#تعریف_کن PS_ENDCAP_ماسک 0x00000F00

#تعریف_کن PS_JOIN_دور 0x00000000
#تعریف_کن PS_JOIN_BEVEL 0x00001000
#تعریف_کن PS_JOIN_MITER 0x00002000
#تعریف_کن PS_JOIN_ماسک 0x0000F000

#تعریف_کن PS_COSMETIC 0x00000000
#تعریف_کن PS_GEOMETRIC 0x00010000
#تعریف_کن PS_TYPE_ماسک 0x000F0000

#تعریف_کن AD_COUNTERCLOCKWISE 1
#تعریف_کن AD_CLOCKWISE 2

#تعریف_کن DRIVERVERSION 0
#تعریف_کن TECHNOLOGY 2
#تعریف_کن HORZSIZE 4
#تعریف_کن VERTSIZE 6
#تعریف_کن HORZRES 8
#تعریف_کن VERTRES 10
#تعریف_کن BITSPIXEL 12
#تعریف_کن PLANES 14
#تعریف_کن NUMBRUSHES 16
#تعریف_کن NUMPENS 18
#تعریف_کن NUMMARKERS 20
#تعریف_کن NUMFONTS 22
#تعریف_کن NUMCOLORS 24
#تعریف_کن PDEVICESIZE 26
#تعریف_کن CURVECAPS 28
#تعریف_کن LINECAPS 30
#تعریف_کن POLYGONALCAPS 32
#تعریف_کن TEXTCAPS 34
#تعریف_کن CLIPCAPS 36
#تعریف_کن RASTERCAPS 38
#تعریف_کن ASPECTX 40
#تعریف_کن ASPECTY 42
#تعریف_کن ASPECTXY 44

#تعریف_کن LOGPIXELSX 88
#تعریف_کن LOGPIXELSY 90

#تعریف_کن SIZEPALETTE 104
#تعریف_کن NUMRESERVED 106
#تعریف_کن COLORRES 108

#تعریف_کن PHYSICALWIDTH 110
#تعریف_کن PHYSICALHEIGHT 111
#تعریف_کن PHYSICALOFFSETX 112
#تعریف_کن PHYSICALOFFSETY 113
#تعریف_کن SCALINGFACTORX 114
#تعریف_کن SCALINGFACTORY 115

#تعریف_کن VREFRESH 116

#تعریف_کن DESKTOPVERTRES 117

#تعریف_کن DESKTOPHORZRES 118

#تعریف_کن BLTALIGNMENT 119

#تعریف_کن SHADEBLENDCAPS 120
#تعریف_کن COLORMGMTCAPS 121

#اگر_تعریف_نشده NOGDICAPMASKS
#تعریف_کن DT_PLOTTER 0
#تعریف_کن DT_RASDISPLAY 1
#تعریف_کن DT_RASPRINTER 2
#تعریف_کن DT_RASCAMERA 3
#تعریف_کن DT_CHARSTREAM 4
#تعریف_کن DT_METAFILE 5
#تعریف_کن DT_DISPFILE 6

#تعریف_کن CC_NONE 0
#تعریف_کن CC_CIRCLES 1
#تعریف_کن CC_PIE 2
#تعریف_کن CC_CHORD 4
#تعریف_کن CC_ELLIPSES 8
#تعریف_کن CC_WIDE 16
#تعریف_کن CC_STYLED 32
#تعریف_کن CC_WIDESTYLED 64
#تعریف_کن CC_INTERIORS 128
#تعریف_کن CC_ROUNDRECT 256

#تعریف_کن LC_NONE 0
#تعریف_کن LC_POLYLINE 2
#تعریف_کن LC_MARKER 4
#تعریف_کن LC_POLYMARKER 8
#تعریف_کن LC_WIDE 16
#تعریف_کن LC_STYLED 32
#تعریف_کن LC_WIDESTYLED 64
#تعریف_کن LC_INTERIORS 128

#تعریف_کن PC_NONE 0
#تعریف_کن PC_POLYGON 1
#تعریف_کن PC_RECTANGLE 2
#تعریف_کن PC_WINDPOLYGON 4
#تعریف_کن PC_TRAPEZOID 4
#تعریف_کن PC_SCANLINE 8
#تعریف_کن PC_WIDE 16
#تعریف_کن PC_STYLED 32
#تعریف_کن PC_WIDESTYLED 64
#تعریف_کن PC_INTERIORS 128
#تعریف_کن PC_POLYPOLYGON 256
#تعریف_کن PC_PATHS 512

#تعریف_کن CP_NONE 0
#تعریف_کن CP_RECTANGLE 1
#تعریف_کن CP_REGION 2

#تعریف_کن TC_OP_CHARACTER 0x00000001
#تعریف_کن TC_OP_STROKE 0x00000002
#تعریف_کن TC_CP_STROKE 0x00000004
#تعریف_کن TC_CR_90 0x00000008
#تعریف_کن TC_CR_ANY 0x00000010
#تعریف_کن TC_SF_X_YINDEP 0x00000020
#تعریف_کن TC_SA_DOUBLE 0x00000040
#تعریف_کن TC_SA_INTEGER 0x00000080
#تعریف_کن TC_SA_CONTIN 0x00000100
#تعریف_کن TC_EA_DOUBLE 0x00000200
#تعریف_کن TC_IA_ABLE 0x00000400
#تعریف_کن TC_UA_ABLE 0x00000800
#تعریف_کن TC_SO_ABLE 0x00001000
#تعریف_کن TC_RA_ABLE 0x00002000
#تعریف_کن TC_VA_ABLE 0x00004000
#تعریف_کن TC_RESERVED 0x00008000
#تعریف_کن TC_SCROLLBLT 0x00010000
#پایان_اگر

#تعریف_کن RC_NONE
#تعریف_کن RC_BITBLT 1
#تعریف_کن RC_BANDING 2
#تعریف_کن RC_SCALING 4
#تعریف_کن RC_BITMAP64 8
#تعریف_کن RC_GDI20_OUTPUT 0x0010
#تعریف_کن RC_GDI20_STATE 0x0020
#تعریف_کن RC_SAVEBITMAP 0x0040
#تعریف_کن RC_DI_BITMAP 0x0080
#تعریف_کن RC_PALETTE 0x0100
#تعریف_کن RC_DIBTODEV 0x0200
#تعریف_کن RC_BIGFONT 0x0400
#تعریف_کن RC_STRETCHBLT 0x0800
#تعریف_کن RC_FLOODFILL 0x1000
#تعریف_کن RC_STRETCHDIB 0x2000
#تعریف_کن RC_OP_DX_OUTPUT 0x4000
#تعریف_کن RC_DEVBITS 0x8000

#تعریف_کن SB_NONE 0x00000000
#تعریف_کن SB_CONST_ALPHA 0x00000001
#تعریف_کن SB_PIXEL_ALPHA 0x00000002
#تعریف_کن SB_PREMULT_ALPHA 0x00000004

#تعریف_کن SB_GRAD_RECT 0x00000010
#تعریف_کن SB_GRAD_TRI 0x00000020

#تعریف_کن CM_NONE 0x00000000
#تعریف_کن CM_DEVICE_ICM 0x00000001
#تعریف_کن CM_GAMMA_RAMP 0x00000002
#تعریف_کن CM_CMYK_COLOR 0x00000004

#تعریف_کن DIB_RGB_COLORS 0
#تعریف_کن DIB_PAL_COLORS 1

#تعریف_کن SYSPAL_ERROR 0
#تعریف_کن SYSPAL_STATIC 1
#تعریف_کن SYSPAL_NOSTATIC 2
#تعریف_کن SYSPAL_NOSTATIC256 3

#تعریف_کن CBM_INIT 0x04L

#تعریف_کن FLOODFILLBORDER 0
#تعریف_کن FLOODFILLSURFACE 1

#تعریف_کن CCHDEVICENAME 32

#تعریف_کن CCHFORMNAME 32

  تعريفنوع بنية _devicemodeA {
    BYTE dmDeviceName[CCHDEVICENAME];
    کلمه_3 dm_Spec_نسخه;
    کلمه_3 dm_Driver_نسخه;
    کلمه_3 dm_اندازه;
    کلمه_3 dmDriverExtra;
    DWORD dmFields;
    اتحاد {
      بنية {
        کوتاه dmOrientation;
        کوتاه dm_Paper_اندازه;
        کوتاه dm_Paper_درازی;
        کوتاه dm_Paper_عرض;
        کوتاه dmScale;
        کوتاه dmCopies;
        کوتاه dm_Default_منبع;
        کوتاه dmPrintQuality;
      };
      بنية {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    کوتاه dmColor;
    کوتاه dmDuplex;
    کوتاه dmYResolution;
    کوتاه dmTTOption;
    کوتاه dmCollate;
    BYTE dmFormName[CCHFORMNAME];
    کلمه_3 dmLogPixels;
    DWORD dm_بیتها_در_هر_Pel;
    DWORD dm_Pels_عرض;
    DWORD dm_Pels_ارتفاع;
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
    DWORD dm_Panning_عرض;
    DWORD dm_Panning_ارتفاع;
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
        کوتاه dmOrientation;
        کوتاه dm_Paper_اندازه;
        کوتاه dm_Paper_درازی;
        کوتاه dm_Paper_عرض;
        کوتاه dmScale;
        کوتاه dmCopies;
        کوتاه dm_Default_منبع;
        کوتاه dmPrintQuality;
      };
      بنية {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    کوتاه dmColor;
    کوتاه dmDuplex;
    کوتاه dmYResolution;
    کوتاه dmTTOption;
    کوتاه dmCollate;
    WCHAR dmFormName[CCHFORMNAME];
    کلمه_3 dmLogPixels;
    DWORD dm_بیتها_در_هر_Pel;
    DWORD dm_Pels_عرض;
    DWORD dm_Pels_ارتفاع;
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
    DWORD dm_Panning_عرض;
    DWORD dm_Panning_ارتفاع;
  } DEVMODEW,*PDEVMODEW,*NPDEVMODEW,*LPDEVMODEW;
#اگر_تعریف_شده UNICODE
  تعريفنوع DEVMODEW DEVMODE;
  تعريفنوع PDEVMODEW PDEVMODE;
  تعريفنوع NPDEVMODEW NPDEVMODE;
  تعريفنوع LPDEVMODEW LPDEVMODE;
#وإلا
  تعريفنوع DEVMODEA DEVMODE;
  تعريفنوع PDEVMODEA PDEVMODE;
  تعريفنوع NPDEVMODEA NPDEVMODE;
  تعريفنوع LPDEVMODEA LPDEVMODE;
#پایان_اگر

#تعریف_کن DM_SPECVERSION 0x0401

#تعریف_کن DM_ORIENTATION 0x00000001L
#تعریف_کن DM_PAPERSIZE 0x00000002L
#تعریف_کن DM_PAPERLENGTH 0x00000004L
#تعریف_کن DM_PAPERWIDTH 0x00000008L
#تعریف_کن DM_SCALE 0x00000010L
#تعریف_کن DM_POSITION 0x00000020L
#تعریف_کن DM_NUP 0x00000040L
#تعریف_کن DM_DISPLAYORIENTATION 0x00000080L
#تعریف_کن DM_COPIES 0x00000100L
#تعریف_کن DM_DEFAULTSOURCE 0x00000200L
#تعریف_کن DM_PRINTQUALITY 0x00000400L
#تعریف_کن DM_COLOR 0x00000800L
#تعریف_کن DM_DUPLEX 0x00001000L
#تعریف_کن DM_YRESOLUTION 0x00002000L
#تعریف_کن DM_TTOPTION 0x00004000L
#تعریف_کن DM_COLLATE 0x00008000L
#تعریف_کن DM_FORMNAME 0x00010000L
#تعریف_کن DM_LOGPIXELS 0x00020000L
#تعریف_کن DM_BITSPERPEL 0x00040000L
#تعریف_کن DM_PELSWIDTH 0x00080000L
#تعریف_کن DM_PELSHEIGHT 0x00100000L
#تعریف_کن DM_DISPLAYFLAGS 0x00200000L
#تعریف_کن DM_DISPLAYFREQUENCY 0x00400000L
#تعریف_کن DM_ICMMETHOD 0x00800000L
#تعریف_کن DM_ICMINTENT 0x01000000L
#تعریف_کن DM_MEDIATYPE 0x02000000L
#تعریف_کن DM_DITHERTYPE 0x04000000L
#تعریف_کن DM_PANNINGWIDTH 0x08000000L
#تعریف_کن DM_PANNINGHEIGHT 0x10000000L
#تعریف_کن DM_DISPLAYFIXEDOUTPUT 0x20000000L

#تعریف_کن DMORIENT_PORTRAIT 1
#تعریف_کن DMORIENT_LANDSCAPE 2

#تعریف_کن DMPAPER_اولی DMPAPER_LETTER
#تعریف_کن DMPAPER_LETTER 1
#تعریف_کن DMPAPER_LETTERSMALL 2
#تعریف_کن DMPAPER_TABLOID 3
#تعریف_کن DMPAPER_LEDGER 4
#تعریف_کن DMPAPER_LEGAL 5
#تعریف_کن DMPAPER_STATEMENT 6
#تعریف_کن DMPAPER_EXECUTIVE 7
#تعریف_کن DMPAPER_A3 8
#تعریف_کن DMPAPER_A4 9
#تعریف_کن DMPAPER_A4SMALL 10
#تعریف_کن DMPAPER_A5 11
#تعریف_کن DMPAPER_B4 12
#تعریف_کن DMPAPER_B5 13
#تعریف_کن DMPAPER_FOLIO 14
#تعریف_کن DMPAPER_QUARTO 15
#تعریف_کن DMPAPER_10X14 16
#تعریف_کن DMPAPER_11X17 17
#تعریف_کن DMPAPER_NOTE 18
#تعریف_کن DMPAPER_ENV_9 19
#تعریف_کن DMPAPER_ENV_10 20
#تعریف_کن DMPAPER_ENV_11 21
#تعریف_کن DMPAPER_ENV_12 22
#تعریف_کن DMPAPER_ENV_14 23
#تعریف_کن DMPAPER_CSHEET 24
#تعریف_کن DMPAPER_DSHEET 25
#تعریف_کن DMPAPER_ESHEET 26
#تعریف_کن DMPAPER_ENV_DL 27
#تعریف_کن DMPAPER_ENV_C5 28
#تعریف_کن DMPAPER_ENV_C3 29
#تعریف_کن DMPAPER_ENV_C4 30
#تعریف_کن DMPAPER_ENV_C6 31
#تعریف_کن DMPAPER_ENV_C65 32
#تعریف_کن DMPAPER_ENV_B4 33
#تعریف_کن DMPAPER_ENV_B5 34
#تعریف_کن DMPAPER_ENV_B6 35
#تعریف_کن DMPAPER_ENV_ITALY 36
#تعریف_کن DMPAPER_ENV_MONARCH 37
#تعریف_کن DMPAPER_ENV_PERSONAL 38
#تعریف_کن DMPAPER_FANFOLD_US 39
#تعریف_کن DMPAPER_FANFOLD_STD_GERMAN 40
#تعریف_کن DMPAPER_FANFOLD_LGL_GERMAN 41
#تعریف_کن DMPAPER_ISO_B4 42
#تعریف_کن DMPAPER_JAPANESE_POSTCARD 43
#تعریف_کن DMPAPER_9X11 44
#تعریف_کن DMPAPER_10X11 45
#تعریف_کن DMPAPER_15X11 46
#تعریف_کن DMPAPER_ENV_INVITE 47
#تعریف_کن DMPAPER_RESERVED_48 48
#تعریف_کن DMPAPER_RESERVED_49 49
#تعریف_کن DMPAPER_LETTER_EXTRA 50
#تعریف_کن DMPAPER_LEGAL_EXTRA 51
#تعریف_کن DMPAPER_TABLOID_EXTRA 52
#تعریف_کن DMPAPER_A4_EXTRA 53
#تعریف_کن DMPAPER_LETTER_TRANSVERSE 54
#تعریف_کن DMPAPER_A4_TRANSVERSE 55
#تعریف_کن DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#تعریف_کن DMPAPER_A_PLUS 57
#تعریف_کن DMPAPER_B_PLUS 58
#تعریف_کن DMPAPER_LETTER_PLUS 59
#تعریف_کن DMPAPER_A4_PLUS 60
#تعریف_کن DMPAPER_A5_TRANSVERSE 61
#تعریف_کن DMPAPER_B5_TRANSVERSE 62
#تعریف_کن DMPAPER_A3_EXTRA 63
#تعریف_کن DMPAPER_A5_EXTRA 64
#تعریف_کن DMPAPER_B5_EXTRA 65
#تعریف_کن DMPAPER_A2 66
#تعریف_کن DMPAPER_A3_TRANSVERSE 67
#تعریف_کن DMPAPER_A3_EXTRA_TRANSVERSE 68
#تعریف_کن DMPAPER_DBL_JAPANESE_POSTCARD 69
#تعریف_کن DMPAPER_A6 70
#تعریف_کن DMPAPER_JENV_KAKU2 71
#تعریف_کن DMPAPER_JENV_KAKU3 72
#تعریف_کن DMPAPER_JENV_CHOU3 73
#تعریف_کن DMPAPER_JENV_CHOU4 74
#تعریف_کن DMPAPER_LETTER_ROTATED 75
#تعریف_کن DMPAPER_A3_ROTATED 76
#تعریف_کن DMPAPER_A4_ROTATED 77
#تعریف_کن DMPAPER_A5_ROTATED 78
#تعریف_کن DMPAPER_B4_JIS_ROTATED 79
#تعریف_کن DMPAPER_B5_JIS_ROTATED 80
#تعریف_کن DMPAPER_JAPANESE_POSTCARD_ROTATED 81
#تعریف_کن DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#تعریف_کن DMPAPER_A6_ROTATED 83
#تعریف_کن DMPAPER_JENV_KAKU2_ROTATED 84
#تعریف_کن DMPAPER_JENV_KAKU3_ROTATED 85
#تعریف_کن DMPAPER_JENV_CHOU3_ROTATED 86
#تعریف_کن DMPAPER_JENV_CHOU4_ROTATED 87
#تعریف_کن DMPAPER_B6_JIS 88
#تعریف_کن DMPAPER_B6_JIS_ROTATED 89
#تعریف_کن DMPAPER_12X11 90
#تعریف_کن DMPAPER_JENV_YOU4 91
#تعریف_کن DMPAPER_JENV_YOU4_ROTATED 92
#تعریف_کن DMPAPER_P16K 93
#تعریف_کن DMPAPER_P32K 94
#تعریف_کن DMPAPER_P32KBIG 95
#تعریف_کن DMPAPER_PENV_1 96
#تعریف_کن DMPAPER_PENV_2 97
#تعریف_کن DMPAPER_PENV_3 98
#تعریف_کن DMPAPER_PENV_4 99
#تعریف_کن DMPAPER_PENV_5 100
#تعریف_کن DMPAPER_PENV_6 101
#تعریف_کن DMPAPER_PENV_7 102
#تعریف_کن DMPAPER_PENV_8 103
#تعریف_کن DMPAPER_PENV_9 104
#تعریف_کن DMPAPER_PENV_10 105
#تعریف_کن DMPAPER_P16K_ROTATED 106
#تعریف_کن DMPAPER_P32K_ROTATED 107
#تعریف_کن DMPAPER_P32KBIG_ROTATED 108
#تعریف_کن DMPAPER_PENV_1_ROTATED 109
#تعریف_کن DMPAPER_PENV_2_ROTATED 110
#تعریف_کن DMPAPER_PENV_3_ROTATED 111
#تعریف_کن DMPAPER_PENV_4_ROTATED 112
#تعریف_کن DMPAPER_PENV_5_ROTATED 113
#تعریف_کن DMPAPER_PENV_6_ROTATED 114
#تعریف_کن DMPAPER_PENV_7_ROTATED 115
#تعریف_کن DMPAPER_PENV_8_ROTATED 116
#تعریف_کن DMPAPER_PENV_9_ROTATED 117
#تعریف_کن DMPAPER_PENV_10_ROTATED 118

#تعریف_کن DMPAPER_آخرین DMPAPER_PENV_10_ROTATED

#تعریف_کن DMPAPER_USER 256

#تعریف_کن DMBIN_اولی DMBIN_فوقانی
#تعریف_کن DMBIN_فوقانی 1
#تعریف_کن DMBIN_ONLYONE 1
#تعریف_کن DMBIN_پایینی 2
#تعریف_کن DMBIN_میانه 3
#تعریف_کن DMBIN_MANUAL 4
#تعریف_کن DMBIN_ENVELOPE 5
#تعریف_کن DMBIN_ENVMANUAL 6
#تعریف_کن DMBIN_AUTO 7
#تعریف_کن DMBIN_TRACTOR 8
#تعریف_کن DMBIN_SMALLFMT 9
#تعریف_کن DMBIN_LARGEFMT 10
#تعریف_کن DMBIN_LARGECAPACITY 11
#تعریف_کن DMBIN_CASSETTE 14
#تعریف_کن DMBIN_FORMSOURCE 15
#تعریف_کن DMBIN_آخرین DMBIN_FORMSOURCE

#تعریف_کن DMBIN_USER 256

#تعریف_کن DMRES_DRAFT (-1)
#تعریف_کن DMRES_کم (-2)
#تعریف_کن DMRES_MEDIUM (-3)
#تعریف_کن DMRES_بالا (-4)

#تعریف_کن DMCOLOR_MONOCHROME 1
#تعریف_کن DMCOLOR_COLOR 2

#تعریف_کن DMDUP_SIMPLEX 1
#تعریف_کن DMDUP_VERTICAL 2
#تعریف_کن DMDUP_HORIZONTAL 3

#تعریف_کن DMTT_BITMAP 1
#تعریف_کن DMTT_DOWNLOAD 2
#تعریف_کن DMTT_SUBDEV 3
#تعریف_کن DMTT_DOWNLOAD_OUTLINE 4

#تعریف_کن DMCOLLATE_FALSE 0
#تعریف_کن DMCOLLATE_TRUE 1

#تعریف_کن DMDO_DEFAULT 0
#تعریف_کن DMDO_90 1
#تعریف_کن DMDO_180 2
#تعریف_کن DMDO_270 3

#تعریف_کن DMDFO_DEFAULT 0
#تعریف_کن DMDFO_STRETCH 1
#تعریف_کن DMDFO_CENTER 2

#تعریف_کن DMDISPLAYFLAGS_TEXTMODE 0x00000004

#تعریف_کن DMNUP_SYSTEM 1
#تعریف_کن DMNUP_ONEUP 2

#تعریف_کن DMICMMETHOD_NONE 1
#تعریف_کن DMICMMETHOD_SYSTEM 2
#تعریف_کن DMICMMETHOD_DRIVER 3
#تعریف_کن DMICMMETHOD_DEVICE 4

#تعریف_کن DMICMMETHOD_USER 256

#تعریف_کن DMICM_SATURATE 1
#تعریف_کن DMICM_CONTRAST 2
#تعریف_کن DMICM_COLORIMETRIC 3
#تعریف_کن DMICM_ABS_COLORIMETRIC 4

#تعریف_کن DMICM_USER 256

#تعریف_کن DMMEDIA_STANDARD 1
#تعریف_کن DMMEDIA_TRANSPARENCY 2
#تعریف_کن DMMEDIA_GLOSSY 3

#تعریف_کن DMMEDIA_USER 256

#تعریف_کن DMDITHER_NONE 1
#تعریف_کن DMDITHER_COARSE 2
#تعریف_کن DMDITHER_FINE 3
#تعریف_کن DMDITHER_LINEART 4
#تعریف_کن DMDITHER_ERRORDIFFUSION 5
#تعریف_کن DMDITHER_RESERVED6 6
#تعریف_کن DMDITHER_RESERVED7 7
#تعریف_کن DMDITHER_RESERVED8 8
#تعریف_کن DMDITHER_RESERVED9 9
#تعریف_کن DMDITHER_GRAYSCALE 10

#تعریف_کن DMDITHER_USER 256

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
#اگر_تعریف_شده UNICODE
  تعريفنوع DISPLAY_DEVICEW DISPLAY_DEVICE;
  تعريفنوع PDISPLAY_DEVICEW PDISPLAY_DEVICE;
  تعريفنوع LPDISPLAY_DEVICEW LPDISPLAY_DEVICE;
#وإلا
  تعريفنوع DISPLAY_DEVICEA DISPLAY_DEVICE;
  تعريفنوع PDISPLAY_DEVICEA PDISPLAY_DEVICE;
  تعريفنوع LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
#پایان_اگر

#تعریف_کن DISPLAY_DEVICE_ATTACHED_مقصد_DESKTOP 0x00000001
#تعریف_کن DISPLAY_DEVICE_MULTI_DRIVER 0x00000002
#تعریف_کن DISPLAY_DEVICE_PRIMARY_DEVICE 0x00000004
#تعریف_کن DISPLAY_DEVICE_MIRRORING_DRIVER 0x00000008
#تعریف_کن DISPLAY_DEVICE_VGA_COMPATIBLE 0x00000010
#تعریف_کن DISPLAY_DEVICE_REMOVABLE 0x00000020
#تعریف_کن DISPLAY_DEVICE_MODESPRUNED 0x08000000
#تعریف_کن DISPLAY_DEVICE_REMOTE 0x04000000
#تعریف_کن DISPLAY_DEVICE_DISCONNECT 0x02000000

#تعریف_کن DISPLAY_DEVICE_فعال 0x00000001
#تعریف_کن DISPLAY_DEVICE_ATTACHED 0x00000002

#تعریف_کن RDH_RECTANGLES 1

  تعريفنوع بنية _RGNDATAHEADER {
    DWORD dw_اندازه;
    DWORD iType;
    DWORD n_شمار;
    DWORD n_Rgn_اندازه;
    RECT rcBound;
  } RGNDATAHEADER,*PRGNDATAHEADER;

  تعريفنوع بنية _RGNDATA {
    RGNDATAHEADER rdh;
    حرف میانگیر_3[1];
  } RGNDATA,*PRGNDATA,*NPRGNDATA,*LPRGNDATA;

#تعریف_کن SYSRGN 4

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

#اگر_تعریف_نشده NOTEXTMETRIC

  تعريفنوع بنية _OUTLINETEXTMETRICA {
    UINT otm_اندازه;
    TEXTMETRICA otm_متن_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_عدد;
    UINT otmfsSelection;
    UINT otmfsType;
    صحيح otms_Char_شیب_Rise;
    صحيح otms_Char_شیب_پیاپی;
    صحيح otmItalicAngle;
    UINT otmEMSquare;
    صحيح otmAscent;
    صحيح otmDescent;
    UINT otm_سطر_Gap;
    UINT otms_Cap_Em_ارتفاع;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    صحيح otmMacAscent;
    صحيح otmMacDescent;
    UINT otm_Mac_سطر_Gap;
    UINT otmusMinimumPPEM;
    نقطه_3 otmpt_Subscript_اندازه;
    نقطه_3 otmpt_Subscript_جابه_جایی;
    نقطه_3 otmpt_Superscript_اندازه;
    نقطه_3 otmpt_Superscript_جابه_جایی;
    UINT otms_Strikeout_اندازه;
    صحيح otmsStrikeoutPosition;
    صحيح otms_Underscore_اندازه;
    صحيح otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_پر_Name;
  } OUTLINETEXTMETRICA,*POUTLINETEXTMETRICA,*NPOUTLINETEXTMETRICA,*LPOUTLINETEXTMETRICA;

  تعريفنوع بنية _OUTLINETEXTMETRICW {
    UINT otm_اندازه;
    TEXTMETRICW otm_متن_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_عدد;
    UINT otmfsSelection;
    UINT otmfsType;
    صحيح otms_Char_شیب_Rise;
    صحيح otms_Char_شیب_پیاپی;
    صحيح otmItalicAngle;
    UINT otmEMSquare;
    صحيح otmAscent;
    صحيح otmDescent;
    UINT otm_سطر_Gap;
    UINT otms_Cap_Em_ارتفاع;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    صحيح otmMacAscent;
    صحيح otmMacDescent;
    UINT otm_Mac_سطر_Gap;
    UINT otmusMinimumPPEM;
    نقطه_3 otmpt_Subscript_اندازه;
    نقطه_3 otmpt_Subscript_جابه_جایی;
    نقطه_3 otmpt_Superscript_اندازه;
    نقطه_3 otmpt_Superscript_جابه_جایی;
    UINT otms_Strikeout_اندازه;
    صحيح otmsStrikeoutPosition;
    صحيح otms_Underscore_اندازه;
    صحيح otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_پر_Name;
  } OUTLINETEXTMETRICW,*POUTLINETEXTMETRICW,*NPOUTLINETEXTMETRICW,*LPOUTLINETEXTMETRICW;
#اگر_تعریف_شده UNICODE
  تعريفنوع OUTLINETEXTMETRICW OUTLINETEXTMETRIC;
  تعريفنوع POUTLINETEXTMETRICW POUTLINETEXTMETRIC;
  تعريفنوع NPOUTLINETEXTMETRICW NPOUTLINETEXTMETRIC;
  تعريفنوع LPOUTLINETEXTMETRICW LPOUTLINETEXTMETRIC;
#وإلا
  تعريفنوع OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
  تعريفنوع POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
  تعريفنوع NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
  تعريفنوع LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
#پایان_اگر
#پایان_اگر

  تعريفنوع بنية برچسب_POLYTEXTA {
    صحيح x;
    صحيح y;
    UINT n;
    LPCSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    صحيح *pdx;
  } POLYTEXTA,*PPOLYTEXTA,*NPPOLYTEXTA,*LPPOLYTEXTA;

  تعريفنوع بنية برچسب_POLYTEXTW {
    صحيح x;
    صحيح y;
    UINT n;
    LPCWSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    صحيح *pdx;
  } POLYTEXTW,*PPOLYTEXTW,*NPPOLYTEXTW,*LPPOLYTEXTW;
#اگر_تعریف_شده UNICODE
  تعريفنوع POLYTEXTW POLYTEXT;
  تعريفنوع PPOLYTEXTW PPOLYTEXT;
  تعريفنوع NPPOLYTEXTW NPPOLYTEXT;
  تعريفنوع LPPOLYTEXTW LPPOLYTEXT;
#وإلا
  تعريفنوع POLYTEXTA POLYTEXT;
  تعريفنوع PPOLYTEXTA PPOLYTEXT;
  تعريفنوع NPPOLYTEXTA NPPOLYTEXT;
  تعريفنوع LPPOLYTEXTA LPPOLYTEXT;
#پایان_اگر

  تعريفنوع بنية _FIXED {
    کلمه_3 fract;
    کوتاه مقدار;
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
    نقطه_3 gmptGlyphOrigin;
    کوتاه gmCellIncX;
    کوتاه gmCellIncY;
  } GLYPHMETRICS,*LPGLYPHMETRICS;

#تعریف_کن GGO_METRICS 0
#تعریف_کن GGO_BITMAP 1
#تعریف_کن GGO_NATIVE 2
#تعریف_کن GGO_BEZIER 3

#تعریف_کن GGO_GRAY2_BITMAP 4
#تعریف_کن GGO_GRAY4_BITMAP 5
#تعریف_کن GGO_GRAY8_BITMAP 6
#تعریف_کن GGO_GLYPH_شاخص 0x0080
#تعریف_کن GGO_UNHINTED 0x0100

#تعریف_کن TT_POLYGON_TYPE 24

#تعریف_کن TT_PRIM_سطر 1
#تعریف_کن TT_PRIM_QSPLINE 2
#تعریف_کن TT_PRIM_CSPLINE 3

  تعريفنوع بنية برچسب_POINTFX {
    FIXED x;
    FIXED y;
  } POINTFX,*LPPOINTFX;

  تعريفنوع بنية برچسب_TTPOLYCURVE {
    کلمه_3 wType;
    کلمه_3 cpfx;
    POINTFX apfx[1];
  } TTPOLYCURVE,*LPTTPOLYCURVE;

  تعريفنوع بنية برچسب_TTPOLYGONHEADER {
    DWORD cb;
    DWORD dwType;
    POINTFX pfx_شروع;
  } TTPOLYGONHEADER,*LPTTPOLYGONHEADER;

#تعریف_کن GCP_DBCS 0x0001
#تعریف_کن GCP_REORDER 0x0002
#تعریف_کن GCP_USEKERNING 0x0008
#تعریف_کن GCP_GLYPHSHAPE 0x0010
#تعریف_کن GCP_LIGATE 0x0020

#تعریف_کن GCP_DIACRITIC 0x0100
#تعریف_کن GCP_KASHIDA 0x0400
#تعریف_کن GCP_ERROR 0x8000
#تعریف_کن FLI_ماسک 0x103B

#تعریف_کن GCP_JUSTIFY 0x00010000L

#تعریف_کن FLI_GLYPHS 0x00040000L
#تعریف_کن GCP_CLASSIN 0x00080000L
#تعریف_کن GCP_MAXEXTENT 0x00100000L
#تعریف_کن GCP_JUSTIFYIN 0x00200000L
#تعریف_کن GCP_DISPLAYZWG 0x00400000L
#تعریف_کن GCP_SYMSWAPOFF 0x00800000L
#تعریف_کن GCP_NUMERICOVERRIDE 0x01000000L
#تعریف_کن GCP_NEUTRALOVERRIDE 0x02000000L
#تعریف_کن GCP_NUMERICSLATIN 0x04000000L
#تعریف_کن GCP_NUMERICSLOCAL 0x08000000L

#تعریف_کن GCPCLASS_LATIN 1
#تعریف_کن GCPCLASS_HEBREW 2
#تعریف_کن GCPCLASS_ARABIC 2
#تعریف_کن GCPCLASS_NEUTRAL 3
#تعریف_کن GCPCLASS_LOCALNUMBER 4
#تعریف_کن GCPCLASS_LATINNUMBER 5
#تعریف_کن GCPCLASS_LATINNUMERICTERMINATOR 6
#تعریف_کن GCPCLASS_LATINNUMERICSEPARATOR 7
#تعریف_کن GCPCLASS_NUMERICSEPARATOR 8
#تعریف_کن GCPCLASS_PREBOUNDLTR 0x80
#تعریف_کن GCPCLASS_PREBOUNDRTL 0x40
#تعریف_کن GCPCLASS_POSTBOUNDLTR 0x20
#تعریف_کن GCPCLASS_POSTBOUNDRTL 0x10

#تعریف_کن GCPGLYPH_LINKBEFORE 0x8000
#تعریف_کن GCPGLYPH_LINKAFTER 0x4000

  تعريفنوع بنية برچسب_GCP_RESULTSA {
    DWORD l_Struct_اندازه;
    LPSTR lp_بیرون_String;
    UINT *lp_ترتیب;
    صحيح *lpDx;
    صحيح *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    صحيح nMaxFit;
  } GCP_RESULTSA,*LPGCP_RESULTSA;
  تعريفنوع بنية برچسب_GCP_RESULTSW {
    DWORD l_Struct_اندازه;
    LPWSTR lp_بیرون_String;
    UINT *lp_ترتیب;
    صحيح *lpDx;
    صحيح *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    صحيح nMaxFit;
  } GCP_RESULTSW,*LPGCP_RESULTSW;
#اگر_تعریف_شده UNICODE
  تعريفنوع GCP_RESULTSW GCP_RESULTS;
  تعريفنوع LPGCP_RESULTSW LPGCP_RESULTS;
#وإلا
  تعريفنوع GCP_RESULTSA GCP_RESULTS;
  تعريفنوع LPGCP_RESULTSA LPGCP_RESULTS;
#پایان_اگر

  تعريفنوع بنية RASTERIZER_وضعیت {
    کوتاه n_اندازه;
    کوتاه wFlags;
    کوتاه nLanguageID;
  } RASTERIZER_وضعیت_2,*LPRASTERIZER_وضعیت;

#تعریف_کن TT_موجود 0x0001
#تعریف_کن TT_ENABLED 0x0002

  تعريفنوع بنية برچسب_PIXELFORMATDESCRIPTOR {
    کلمه_3 n_اندازه;
    کلمه_3 n_نسخه;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_بیتها;
    BYTE c_Red_بیتها;
    BYTE c_Red_لغزش;
    BYTE c_Green_بیتها;
    BYTE c_Green_لغزش;
    BYTE c_Blue_بیتها;
    BYTE c_Blue_لغزش;
    BYTE c_Alpha_بیتها;
    BYTE c_Alpha_لغزش;
    BYTE c_Accum_بیتها;
    BYTE c_Accum_Red_بیتها;
    BYTE c_Accum_Green_بیتها;
    BYTE c_Accum_Blue_بیتها;
    BYTE c_Accum_Alpha_بیتها;
    BYTE c_عمق_بیتها;
    BYTE c_Stencil_بیتها;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dw_Layer_ماسک;
    DWORD dw_Visible_ماسک;
    DWORD dw_Damage_ماسک;
  } PIXELFORMATDESCRIPTOR,*PPIXELFORMATDESCRIPTOR,*LPPIXELFORMATDESCRIPTOR;

#تعریف_کن PFD_TYPE_RGBA 0
#تعریف_کن PFD_TYPE_COLORINDEX 1

#تعریف_کن PFD_MAIN_PLANE 0
#تعریف_کن PFD_OVERLAY_PLANE 1
#تعریف_کن PFD_UNDERLAY_PLANE (-1)

#تعریف_کن PFD_DOUBLEBUFFER 0x00000001
#تعریف_کن PFD_STEREO 0x00000002
#تعریف_کن PFD_DRAW_مقصد_پنجره 0x00000004
#تعریف_کن PFD_DRAW_مقصد_BITMAP 0x00000008
#تعریف_کن PFD_SUPPORT_GDI 0x00000010
#تعریف_کن PFD_SUPPORT_OPENGL 0x00000020
#تعریف_کن PFD_GENERIC_FORMAT 0x00000040
#تعریف_کن PFD_NEED_PALETTE 0x00000080
#تعریف_کن PFD_NEED_SYSTEM_PALETTE 0x00000100
#تعریف_کن PFD_جابجا_EXCHANGE 0x00000200
#تعریف_کن PFD_جابجا_COPY 0x00000400
#تعریف_کن PFD_جابجا_LAYER_BUFFERS 0x00000800
#تعریف_کن PFD_GENERIC_ACCELERATED 0x00001000
#تعریف_کن PFD_SUPPORT_DIRECTDRAW 0x00002000

#تعریف_کن PFD_عمق_DONTCARE 0x20000000
#تعریف_کن PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#تعریف_کن PFD_STEREO_DONTCARE 0x80000000

#اگر_تعریف_نشده NOTEXTMETRIC
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST TEXTMETRICA *,DWORD,LPARAM);
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST TEXTMETRICW *,DWORD,LPARAM);
#اگر_تعریف_شده UNICODE
#تعریف_کن OLDFONTENUMPROC OLDFONTENUMPROCW
#وإلا
#تعریف_کن OLDFONTENUMPROC OLDFONTENUMPROCA
#پایان_اگر
#وإلا
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST VOID *,DWORD,LPARAM);
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST VOID *,DWORD,LPARAM);
#اگر_تعریف_شده UNICODE
#تعریف_کن OLDFONTENUMPROC OLDFONTENUMPROCW
#وإلا
#تعریف_کن OLDFONTENUMPROC OLDFONTENUMPROCA
#پایان_اگر
#پایان_اگر

  تعريفنوع OLDFONTENUMPROCA FONTENUMPROCA;
  تعريفنوع OLDFONTENUMPROCW FONTENUMPROCW;
#اگر_تعریف_شده UNICODE
  تعريفنوع FONTENUMPROCW FONTENUMPROC;
#وإلا
  تعريفنوع FONTENUMPROCA FONTENUMPROC;
#پایان_اگر

  تعريفنوع صحيح (CALLBACK *GOBJENUMPROC)(LPVOID,LPARAM);
  تعريفنوع VOID (CALLBACK *LINEDDAPROC)(صحيح,صحيح,LPARAM);

#اگر_تعریف_شده UNICODE
#تعریف_کن جمع_کن_Font_Resource جمع_کن_Font_Resource_W
#تعریف_کن CopyMetaFile CopyMetaFileW
#تعریف_کن CreateDC CreateDCW
#تعریف_کن Create_Font_غیرمستقیم Create_Font_غیرمستقیم_W
#تعریف_کن CreateFont CreateFontW
#تعریف_کن CreateIC CreateICW
#تعریف_کن CreateMetaFile CreateMetaFileW
#تعریف_کن CreateScalableFontResource CreateScalableFontResourceW
#وإلا
#تعریف_کن جمع_کن_Font_Resource جمع_کن_Font_Resource_A
#تعریف_کن CopyMetaFile CopyMetaFileA
#تعریف_کن CreateDC CreateDCA
#تعریف_کن Create_Font_غیرمستقیم Create_Font_غیرمستقیم_A
#تعریف_کن CreateFont CreateFontA
#تعریف_کن CreateIC CreateICA
#تعریف_کن CreateMetaFile CreateMetaFileA
#تعریف_کن CreateScalableFontResource CreateScalableFontResourceA
#پایان_اگر

  WINGDIAPI صحيح WINAPI جمع_کن_Font_Resource_A(LPCSTR);
  WINGDIAPI صحيح WINAPI جمع_کن_Font_Resource_W(LPCWSTR);
  WINGDIAPI WINBOOL WINAPI AnimatePalette(HPALETTE hPal,UINT i_شروع_شاخص,UINT cEntries,CONST PALETTEENTRY *ppe);
  WINGDIAPI WINBOOL WINAPI Arc(HDC hdc,صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح x3,صحيح y3,صحيح x4,صحيح y4);
  WINGDIAPI WINBOOL WINAPI بیت_Blt(HDC hdc,صحيح x,صحيح y,صحيح cx,صحيح cy,HDC hdcSrc,صحيح x1,صحيح y1,DWORD rop);
  WINGDIAPI WINBOOL WINAPI CancelDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Chord(HDC hdc,صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح x3,صحيح y3,صحيح x4,صحيح y4);
  WINGDIAPI صحيح WINAPI انتخاب_Pixel_Format(HDC hdc,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI HMETAFILE WINAPI CloseMetaFile(HDC hdc);
  WINGDIAPI صحيح WINAPI CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,صحيح i_نما);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
  WINGDIAPI HBITMAP WINAPI CreateBitmap(صحيح n_عرض,صحيح n_ارتفاع,UINT nPlanes,UINT n_بیت_شمار,CONST VOID *lp_بیتها);
  WINGDIAPI HBITMAP WINAPI Create_Bitmap_غیرمستقیم(CONST BITMAP *pbm);
  WINGDIAPI HBRUSH WINAPI Create_Brush_غیرمستقیم(CONST LOGBRUSH *plbrush);
  WINGDIAPI HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc,صحيح cx,صحيح cy);
  WINGDIAPI HBITMAP WINAPI CreateDiscardableBitmap(HDC hdc,صحيح cx,صحيح cy);
  WINGDIAPI HDC WINAPI CreateCompatibleDC(HDC hdc);
  WINGDIAPI HDC WINAPI CreateDCA(LPCSTR pwszDriver,LPCSTR pwszDevice,LPCSTR psz_پورت,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateDCW(LPCWSTR pwszDriver,LPCWSTR pwszDevice,LPCWSTR psz_پورت,CONST DEVMODEW *pdm);
  WINGDIAPI HBITMAP WINAPI CreateDIBitmap(HDC hdc,CONST BITMAPINFOHEADER *pbmih,DWORD flInit,CONST VOID *pj_بیتها,CONST BITMAPINFO *pbmi,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL h,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB,UINT iUsage);
  WINGDIAPI HRGN WINAPI CreateEllipticRgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2);
  WINGDIAPI HRGN WINAPI Create_Elliptic_Rgn_غیرمستقیم(CONST RECT *lprect);
  WINGDIAPI HFONT WINAPI Create_Font_غیرمستقیم_A(CONST LOGFONTA *lplf);
  WINGDIAPI HFONT WINAPI Create_Font_غیرمستقیم_W(CONST LOGFONTW *lplf);
  WINGDIAPI HFONT WINAPI CreateFontA(صحيح c_ارتفاع,صحيح c_عرض,صحيح cEscapement,صحيح cOrientation,صحيح c_وزن,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_بیرون,DWORD i_Char_مجموعه,DWORD i_بیرون_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCSTR pszFaceName);
  WINGDIAPI HFONT WINAPI CreateFontW(صحيح c_ارتفاع,صحيح c_عرض,صحيح cEscapement,صحيح cOrientation,صحيح c_وزن,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_بیرون,DWORD i_Char_مجموعه,DWORD i_بیرون_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCWSTR pszFaceName);
  WINGDIAPI HBRUSH WINAPI CreateHatchBrush(صحيح iHatch,COLORREF color);
  WINGDIAPI HDC WINAPI CreateICA(LPCSTR pszDriver,LPCSTR pszDevice,LPCSTR psz_پورت,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateICW(LPCWSTR pszDriver,LPCWSTR pszDevice,LPCWSTR psz_پورت,CONST DEVMODEW *pdm);
  WINGDIAPI HDC WINAPI CreateMetaFileA(LPCSTR pszFile);
  WINGDIAPI HDC WINAPI CreateMetaFileW(LPCWSTR pszFile);
  WINGDIAPI HPALETTE WINAPI CreatePalette(CONST LOGPALETTE *plpal);
  WINGDIAPI HPEN WINAPI CreatePen(صحيح iStyle,صحيح c_عرض,COLORREF color);
  WINGDIAPI HPEN WINAPI Create_Pen_غیرمستقیم(CONST LOGPEN *plpen);
  WINGDIAPI HRGN WINAPI CreatePolyPolygonRgn(CONST نقطه_3 *pptl,CONST INT *pc,صحيح cPoly,صحيح i_نما);
  WINGDIAPI HBRUSH WINAPI Create_الگو_Brush(HBITMAP hbm);
  WINGDIAPI HRGN WINAPI CreateRectRgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2);
  WINGDIAPI HRGN WINAPI Create_Rect_Rgn_غیرمستقیم(CONST RECT *lprect);
  WINGDIAPI HRGN WINAPI Create_دور_Rect_Rgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح w,صحيح h);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceA(DWORD fdwHidden,LPCSTR lpszFont,LPCSTR lpszFile,LPCSTR lpsz_مسیر);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceW(DWORD fdwHidden,LPCWSTR lpszFont,LPCWSTR lpszFile,LPCWSTR lpsz_مسیر);
  WINGDIAPI HBRUSH WINAPI CreateSolidBrush(COLORREF color);
  WINGDIAPI WINBOOL WINAPI DeleteDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI DeleteMetaFile(HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI DeleteObject(HGDIOBJ ho);
  WINGDIAPI صحيح WINAPI DescribePixelFormat(HDC hdc,صحيح iPixelFormat,UINT n_بایتها,LPPIXELFORMATDESCRIPTOR ppfd);

  تعريفنوع UINT (CALLBACK *LPFNDEVMODE)(HWND,HMODULE,LPDEVMODE,LPSTR,LPSTR,LPDEVMODE,LPSTR,UINT);
  تعريفنوع DWORD (CALLBACK *LPFNDEVCAPS)(LPSTR,LPSTR,UINT,LPSTR,LPDEVMODE);

#تعریف_کن DM_UPDATE 1
#تعریف_کن DM_COPY 2
#تعریف_کن DM_PROMPT 4
#تعریف_کن DM_MODIFY 8

#تعریف_کن DM_درون_میانگیر DM_MODIFY
#تعریف_کن DM_درون_PROMPT DM_PROMPT
#تعریف_کن DM_بیرون_میانگیر DM_COPY
#تعریف_کن DM_بیرون_DEFAULT DM_UPDATE

#تعریف_کن DC_FIELDS 1
#تعریف_کن DC_PAPERS 2
#تعریف_کن DC_PAPERSIZE 3
#تعریف_کن DC_MINEXTENT 4
#تعریف_کن DC_MAXEXTENT 5
#تعریف_کن DC_BINS 6
#تعریف_کن DC_DUPLEX 7
#تعریف_کن DC_اندازه 8
#تعریف_کن DC_EXTRA 9
#تعریف_کن DC_نسخه 10
#تعریف_کن DC_DRIVER 11
#تعریف_کن DC_BINNAMES 12
#تعریف_کن DC_ENUMRESOLUTIONS 13
#تعریف_کن DC_FILEDEPENDENCIES 14
#تعریف_کن DC_TRUETYPE 15
#تعریف_کن DC_PAPERNAMES 16
#تعریف_کن DC_ORIENTATION 17
#تعریف_کن DC_COPIES 18
#تعریف_کن DC_BINADJUST 19
#تعریف_کن DC_EMF_COMPLIANT 20
#تعریف_کن DC_DATATYPE_PRODUCED 21
#تعریف_کن DC_COLLATE 22
#تعریف_کن DC_MANUFACTURER 23
#تعریف_کن DC_MODEL 24
#تعریف_کن DC_PERSONALITY 25
#تعریف_کن DC_PRINTRATE 26
#تعریف_کن DC_PRINTRATEUNIT 27
#تعریف_کن PRINTRATEUNIT_PPM 1
#تعریف_کن PRINTRATEUNIT_CPS 2
#تعریف_کن PRINTRATEUNIT_LPM 3
#تعریف_کن PRINTRATEUNIT_IPM 4
#تعریف_کن DC_PRINTERMEM 28
#تعریف_کن DC_MEDIAREADY 29
#تعریف_کن DC_STAPLE 30
#تعریف_کن DC_PRINTRATEPPM 31
#تعریف_کن DC_COLORDEVICE 32
#تعریف_کن DC_NUP 33
#تعریف_کن DC_MEDIATYPENAMES 34
#تعریف_کن DC_MEDIATYPES 35

#تعریف_کن DCTT_BITMAP 0x0000001L
#تعریف_کن DCTT_DOWNLOAD 0x0000002L
#تعریف_کن DCTT_SUBDEV 0x0000004L
#تعریف_کن DCTT_DOWNLOAD_OUTLINE 0x0000008L

#تعریف_کن DCBA_FACEUPNONE 0x0000
#تعریف_کن DCBA_FACEUPCENTER 0x0001
#تعریف_کن DCBA_FACEUPLEFT 0x0002
#تعریف_کن DCBA_FACEUPRIGHT 0x0003
#تعریف_کن DCBA_FACEDOWNNONE 0x0100
#تعریف_کن DCBA_FACEDOWNCENTER 0x0101
#تعریف_کن DCBA_FACEDOWNLEFT 0x0102
#تعریف_کن DCBA_FACEDOWNRIGHT 0x0103

#اگر_تعریف_شده UNICODE
#تعریف_کن DeviceCapabilities DeviceCapabilitiesW
#تعریف_کن EnumFontFamiliesEx EnumFontFamiliesExW
#تعریف_کن EnumFontFamilies EnumFontFamiliesW
#تعریف_کن EnumFonts EnumFontsW
#تعریف_کن Get_Char_عرض Get_Char_عرض_W
#تعریف_کن GetCharWidth32 GetCharWidth32W
#تعریف_کن Get_Char_عرض_Float Get_Char_عرض_Float_W
#تعریف_کن GetCharABCWidths GetCharABCWidthsW
#تعریف_کن GetCharABCWidthsFloat GetCharABCWidthsFloatW
#تعریف_کن GetGlyphOutline GetGlyphOutlineW
#تعریف_کن GetMetaFile GetMetaFileW
#وإلا
#تعریف_کن DeviceCapabilities DeviceCapabilitiesA
#تعریف_کن EnumFontFamiliesEx EnumFontFamiliesExA
#تعریف_کن EnumFontFamilies EnumFontFamiliesA
#تعریف_کن EnumFonts EnumFontsA
#تعریف_کن Get_Char_عرض Get_Char_عرض_A
#تعریف_کن GetCharWidth32 GetCharWidth32A
#تعریف_کن Get_Char_عرض_Float Get_Char_عرض_Float_A
#تعریف_کن GetCharABCWidths GetCharABCWidthsA
#تعریف_کن GetCharABCWidthsFloat GetCharABCWidthsFloatA
#تعریف_کن GetGlyphOutline GetGlyphOutlineA
#تعریف_کن GetMetaFile GetMetaFileA
#پایان_اگر

  WINSPOOLAPI صحيح WINAPI DeviceCapabilitiesA(LPCSTR pDevice,LPCSTR p_پورت,کلمه_3 fwCapability,LPSTR pOutput,CONST DEVMODEA *p_Dev_نما);
  WINSPOOLAPI صحيح WINAPI DeviceCapabilitiesW(LPCWSTR pDevice,LPCWSTR p_پورت,کلمه_3 fwCapability,LPWSTR pOutput,CONST DEVMODEW *p_Dev_نما);
  WINGDIAPI صحيح WINAPI DrawEscape(HDC hdc,صحيح iEscape,صحيح cj_درون,LPCSTR lp_درون);
  WINGDIAPI WINBOOL WINAPI Ellipse(HDC hdc,صحيح چپ,صحيح بالاترین,صحيح راست,صحيح bottom);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesExA(HDC hdc,LPLOGFONTA lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesExW(HDC hdc,LPLOGFONTW lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontsA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontsW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumObjects(HDC hdc,صحيح nType,GOBJENUMPROC lpFunc,LPARAM lParam);
  WINGDIAPI WINBOOL WINAPI EqualRgn(HRGN hrgn1,HRGN hrgn2);
  WINGDIAPI صحيح WINAPI Escape(HDC hdc,صحيح iEscape,صحيح cj_درون,LPCSTR pv_درون,LPVOID pv_بیرون);
  WINGDIAPI صحيح WINAPI ExtEscape(HDC hdc,صحيح iEscape,صحيح cj_درون_داد,LPCSTR lp_درون_داده,صحيح cjOutput,LPSTR lp_بیرون_داده);
  WINGDIAPI صحيح WINAPI ExcludeClipRect(HDC hdc,صحيح چپ,صحيح بالاترین,صحيح راست,صحيح bottom);
  WINGDIAPI HRGN WINAPI ExtCreateRegion(CONST XFORM *lpx,DWORD n_شمار,CONST RGNDATA *lp_داده);
  WINGDIAPI WINBOOL WINAPI ExtFloodFill(HDC hdc,صحيح x,صحيح y,COLORREF color,UINT type);
  WINGDIAPI WINBOOL WINAPI FillRgn(HDC hdc,HRGN hrgn,HBRUSH hbr);
  WINGDIAPI WINBOOL WINAPI FloodFill(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI قاب_Rgn(HDC hdc,HRGN hrgn,HBRUSH hbr,صحيح w,صحيح h);
  WINGDIAPI صحيح WINAPI GetROP2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_Aspect_نسبت_Filter_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI COLORREF WINAPI GetBkColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCBrushColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCPenColor(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Bk_نما(HDC hdc);
  WINGDIAPI LONG WINAPI Get_Bitmap_بیتها(HBITMAP hbit,LONG cb,LPVOID lpv_بیتها);
  WINGDIAPI WINBOOL WINAPI GetBitmapDimensionEx(HBITMAP hbit,LPSIZE lpsize);
  WINGDIAPI UINT WINAPI GetBoundsRect(HDC hdc,LPRECT lprect,UINT flags);
  WINGDIAPI WINBOOL WINAPI GetBrushOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI Get_Char_عرض_A(HDC hdc,UINT i_اولی,UINT i_آخرین,LPINT lp_میانگیر);
  WINGDIAPI WINBOOL WINAPI Get_Char_عرض_W(HDC hdc,UINT i_اولی,UINT i_آخرین,LPINT lp_میانگیر);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32A(HDC hdc,UINT i_اولی,UINT i_آخرین,LPINT lp_میانگیر);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32W(HDC hdc,UINT i_اولی,UINT i_آخرین,LPINT lp_میانگیر);
  WINGDIAPI WINBOOL WINAPI Get_Char_عرض_Float_A(HDC hdc,UINT i_اولی,UINT i_آخرین,PFLOAT lp_میانگیر);
  WINGDIAPI WINBOOL WINAPI Get_Char_عرض_Float_W(HDC hdc,UINT i_اولی,UINT i_آخرین,PFLOAT lp_میانگیر);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsA(HDC hdc,UINT w_اولی,UINT w_آخرین,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsW(HDC hdc,UINT w_اولی,UINT w_آخرین,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatA(HDC hdc,UINT i_اولی,UINT i_آخرین,LPABCFLOAT lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatW(HDC hdc,UINT i_اولی,UINT i_آخرین,LPABCFLOAT lpABC);
  WINGDIAPI صحيح WINAPI GetClipBox(HDC hdc,LPRECT lprect);
  WINGDIAPI صحيح WINAPI GetClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI صحيح WINAPI GetMetaRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI HGDIOBJ WINAPI GetCurrentObject(HDC hdc,UINT type);
  WINGDIAPI WINBOOL WINAPI GetCurrentPositionEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI صحيح WINAPI GetDeviceCaps(HDC hdc,صحيح شاخص);
  WINGDIAPI صحيح WINAPI GetDIBits(HDC hdc,HBITMAP hbm,UINT شروع,UINT c_سطرها,LPVOID lpv_بیتها,LPBITMAPINFO lpbmi,UINT usage);
  WINGDIAPI DWORD WINAPI Get_Font_داده (HDC hdc,DWORD dw_جدول,DWORD dw_جابه_جایی,PVOID pv_میانگیر,DWORD cj_میانگیر);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineA(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_میانگیر,LPVOID pv_میانگیر,CONST MAT2 *lpmat2);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineW(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_میانگیر,LPVOID pv_میانگیر,CONST MAT2 *lpmat2);
  WINGDIAPI صحيح WINAPI Get_Graphics_نما(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Map_نما(HDC hdc);
  WINGDIAPI UINT WINAPI Get_Meta_File_بیتها_Ex(HMETAFILE hMF,UINT cb_میانگیر,LPVOID lp_داده);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileA(LPCSTR lpName);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileW(LPCWSTR lpName);
  WINGDIAPI COLORREF WINAPI Get_نزدیکترین_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI Get_نزدیکترین_Palette_شاخص(HPALETTE h,COLORREF color);
  WINGDIAPI DWORD WINAPI GetObjectType(HGDIOBJ h);

#اگر_تعریف_نشده NOTEXTMETRIC
#اگر_تعریف_شده UNICODE
#تعریف_کن Get_Outline_متن_Metrics Get_Outline_متن_Metrics_W
#وإلا
#تعریف_کن Get_Outline_متن_Metrics Get_Outline_متن_Metrics_A
#پایان_اگر

  WINGDIAPI UINT WINAPI Get_Outline_متن_Metrics_A(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICA potm);
  WINGDIAPI UINT WINAPI Get_Outline_متن_Metrics_W(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICW potm);
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_متن_Extent_نقطه Get_متن_Extent_نقطه_W
#تعریف_کن Get_متن_Extent_Point32 Get_متن_Extent_Point32_W
#تعریف_کن Get_متن_Extent_Ex_نقطه Get_متن_Extent_Ex_نقطه_W
#تعریف_کن GetCharacterPlacement GetCharacterPlacementW
#وإلا
#تعریف_کن Get_متن_Extent_نقطه Get_متن_Extent_نقطه_A
#تعریف_کن Get_متن_Extent_Point32 Get_متن_Extent_Point32_A
#تعریف_کن Get_متن_Extent_Ex_نقطه Get_متن_Extent_Ex_نقطه_A
#تعریف_کن GetCharacterPlacement GetCharacterPlacementA
#پایان_اگر

  WINGDIAPI UINT WINAPI GetPaletteEntries(HPALETTE hpal,UINT i_شروع,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI COLORREF WINAPI GetPixel(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI صحيح WINAPI GetPixelFormat(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Poly_Fill_نما(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetRasterizerCaps(LPRASTERIZER_وضعیت lpraststat,UINT cj_بایتها);
  WINGDIAPI صحيح WINAPI GetRandomRgn (HDC hdc,HRGN hrgn,INT i);
  WINGDIAPI DWORD WINAPI Get_Region_داده(HRGN hrgn,DWORD n_شمار,LPRGNDATA lp_Rgn_داده);
  WINGDIAPI صحيح WINAPI GetRgnBox(HRGN hrgn,LPRECT lprc);
  WINGDIAPI HGDIOBJ WINAPI GetStockObject(صحيح i);
  WINGDIAPI صحيح WINAPI Get_Stretch_Blt_نما(HDC hdc);
  WINGDIAPI UINT WINAPI GetSystemPaletteEntries(HDC hdc,UINT i_شروع,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI UINT WINAPI GetSystemPaletteUse(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_متن_Character_Extra(HDC hdc);
  WINGDIAPI UINT WINAPI Get_متن_Align(HDC hdc);
  WINGDIAPI COLORREF WINAPI Get_متن_Color(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_نقطه_A(HDC hdc,LPCSTR lpString,صحيح c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_نقطه_W(HDC hdc,LPCWSTR lpString,صحيح c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Point32_A(HDC hdc,LPCSTR lpString,صحيح c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Point32_W(HDC hdc,LPCWSTR lpString,صحيح c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_نقطه_A(HDC hdc,LPCSTR lpszString,صحيح cchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_اندازه);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_نقطه_W(HDC hdc,LPCWSTR lpszString,صحيح cchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_اندازه);
  WINGDIAPI صحيح WINAPI Get_متن_Charset(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_متن_Charset_Info(HDC hdc,LPFONTSIGNATURE lpSig,DWORD dwFlags);
  WINGDIAPI WINBOOL WINAPI TranslateCharsetInfo(DWORD *lpSrc,LPCHARSETINFO lpCs,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetFontLanguageInfo(HDC hdc);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementA(HDC hdc,LPCSTR lpString,صحيح n_شمار,صحيح nMexExtent,LPGCP_RESULTSA lpResults,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementW(HDC hdc,LPCWSTR lpString,صحيح n_شمار,صحيح nMexExtent,LPGCP_RESULTSW lpResults,DWORD dwFlags);

  تعريفنوع بنية برچسب_WCRANGE {
    WCHAR wc_کم;
    USHORT cGlyphs;
  } WCRANGE,*PWCRANGE,*LPWCRANGE;

  تعريفنوع بنية برچسب_GLYPHSET {
    DWORD cbThis;
    DWORD flAccel;
    DWORD cGlyphsSupported;
    DWORD cRanges;
    WCRANGE ranges[1];
  } GLYPHSET,*PGLYPHSET,*LPGLYPHSET;

#تعریف_کن GS_8_بیت_INDICES 0x00000001

#تعریف_کن GGI_MARK_NONEXISTING_GLYPHS 0X0001

#اگر_تعریف_شده UNICODE
#تعریف_کن GetGlyphIndices GetGlyphIndicesW
#وإلا
#تعریف_کن GetGlyphIndices GetGlyphIndicesA
#پایان_اگر

  WINGDIAPI DWORD WINAPI GetFontUnicodeRanges(HDC hdc,LPGLYPHSET lpgs);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesA(HDC hdc,LPCSTR lpstr,صحيح c,LPWORD pgi,DWORD fl);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesW(HDC hdc,LPCWSTR lpstr,صحيح c,LPWORD pgi,DWORD fl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_نقطه_I(HDC hdc,LPWORD pgi_درون,صحيح cgi,LPSIZE psize);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_نقطه_I (HDC hdc,LPWORD lpwszString,صحيح cwchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_اندازه);
  WINGDIAPI WINBOOL WINAPI Get_Char_عرض_I(HDC hdc,UINT gi_اولی,UINT cgi,LPWORD pgi,LPINT piWidths);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsI(HDC hdc,UINT gi_اولی,UINT cgi,LPWORD pgi,LPABC pabc);

#تعریف_کن STAMP_DESIGNVECTOR (0x8000000 + 'd' + ('v' << 8))
#تعریف_کن STAMP_AXESLIST (0x8000000 + 'a' + ('l' << 8))
#تعریف_کن MM_MAX_NUMAXES 16

  تعريفنوع بنية برچسب_DESIGNVECTOR {
    DWORD dvReserved;
    DWORD dv_رقم_Axes;
    LONG dv_مقادیر[MM_MAX_NUMAXES];
  } DESIGNVECTOR,*PDESIGNVECTOR,*LPDESIGNVECTOR;

#اگر_تعریف_شده UNICODE
#تعریف_کن جمع_کن_Font_Resource_Ex جمع_کن_Font_Resource_Ex_W
#تعریف_کن RemoveFontResourceEx RemoveFontResourceExW
#وإلا
#تعریف_کن جمع_کن_Font_Resource_Ex جمع_کن_Font_Resource_Ex_A
#تعریف_کن RemoveFontResourceEx RemoveFontResourceExA
#پایان_اگر

  WINGDIAPI صحيح WINAPI جمع_کن_Font_Resource_Ex_A(LPCSTR name,DWORD fl,PVOID res);
  WINGDIAPI صحيح WINAPI جمع_کن_Font_Resource_Ex_W(LPCWSTR name,DWORD fl,PVOID res);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExA(LPCSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExW(LPCWSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI HANDLE WINAPI جمع_کن_Font_Mem_Resource_Ex(PVOID pFileView,DWORD cj_اندازه,PVOID pvResrved,DWORD *p_رقم_Fonts);
  WINGDIAPI WINBOOL WINAPI RemoveFontMemResourceEx(HANDLE h);

#تعریف_کن FR_خصوصی 0x10
#تعریف_کن FR_NOT_ENUM 0x20

#تعریف_کن MM_MAX_AXES_NAMELEN 16

  تعريفنوع بنية برچسب_AXISINFOA {
    LONG ax_Min_مقدار;
    LONG ax_Max_مقدار;
    BYTE axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOA,*PAXISINFOA,*LPAXISINFOA;

  تعريفنوع بنية برچسب_AXISINFOW {
    LONG ax_Min_مقدار;
    LONG ax_Max_مقدار;
    WCHAR axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOW,*PAXISINFOW,*LPAXISINFOW;
#اگر_تعریف_شده UNICODE
  تعريفنوع AXISINFOW AXISINFO;
  تعريفنوع PAXISINFOW PAXISINFO;
  تعريفنوع LPAXISINFOW LPAXISINFO;
#وإلا
  تعريفنوع AXISINFOA AXISINFO;
  تعريفنوع PAXISINFOA PAXISINFO;
  تعريفنوع LPAXISINFOA LPAXISINFO;
#پایان_اگر

  تعريفنوع بنية برچسب_AXESLISTA {
    DWORD axlReserved;
    DWORD axl_رقم_Axes;
    AXISINFOA axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTA,*PAXESLISTA,*LPAXESLISTA;

  تعريفنوع بنية برچسب_AXESLISTW {
    DWORD axlReserved;
    DWORD axl_رقم_Axes;
    AXISINFOW axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTW,*PAXESLISTW,*LPAXESLISTW;
#اگر_تعریف_شده UNICODE
  تعريفنوع AXESLISTW AXESLIST;
  تعريفنوع PAXESLISTW PAXESLIST;
  تعريفنوع LPAXESLISTW LPAXESLIST;
#وإلا
  تعريفنوع AXESLISTA AXESLIST;
  تعريفنوع PAXESLISTA PAXESLIST;
  تعريفنوع LPAXESLISTA LPAXESLIST;
#پایان_اگر

  تعريفنوع بنية برچسب_ENUMLOGFONTEXDVA {
    ENUMLOGFONTEXA elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_وکتور;
  } ENUMLOGFONTEXDVA,*PENUMLOGFONTEXDVA,*LPENUMLOGFONTEXDVA;

  تعريفنوع بنية برچسب_ENUMLOGFONTEXDVW {
    ENUMLOGFONTEXW elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_وکتور;
  } ENUMLOGFONTEXDVW,*PENUMLOGFONTEXDVW,*LPENUMLOGFONTEXDVW;
#اگر_تعریف_شده UNICODE
  تعريفنوع ENUMLOGFONTEXDVW ENUMLOGFONTEXDV;
  تعريفنوع PENUMLOGFONTEXDVW PENUMLOGFONTEXDV;
  تعريفنوع LPENUMLOGFONTEXDVW LPENUMLOGFONTEXDV;
#وإلا
  تعريفنوع ENUMLOGFONTEXDVA ENUMLOGFONTEXDV;
  تعريفنوع PENUMLOGFONTEXDVA PENUMLOGFONTEXDV;
  تعريفنوع LPENUMLOGFONTEXDVA LPENUMLOGFONTEXDV;
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن Create_Font_غیرمستقیم_Ex Create_Font_غیرمستقیم_Ex_W
#وإلا
#تعریف_کن Create_Font_غیرمستقیم_Ex Create_Font_غیرمستقیم_Ex_A
#پایان_اگر

  WINGDIAPI HFONT WINAPI Create_Font_غیرمستقیم_Ex_A(CONST ENUMLOGFONTEXDVA *);
  WINGDIAPI HFONT WINAPI Create_Font_غیرمستقیم_Ex_W(CONST ENUMLOGFONTEXDVW *);

#اگر_تعریف_نشده NOTEXTMETRIC
  تعريفنوع بنية برچسب_ENUMTEXTMETRICA {
    NEWTEXTMETRICEXA etm_New_متن_Metric_Ex;
    AXESLISTA etmAxesList;
  } ENUMTEXTMETRICA,*PENUMTEXTMETRICA,*LPENUMTEXTMETRICA;
  تعريفنوع بنية برچسب_ENUMTEXTMETRICW
  {
    NEWTEXTMETRICEXW etm_New_متن_Metric_Ex;
    AXESLISTW etmAxesList;
  } ENUMTEXTMETRICW,*PENUMTEXTMETRICW,*LPENUMTEXTMETRICW;
#اگر_تعریف_شده UNICODE
  تعريفنوع ENUMTEXTMETRICW ENUMTEXTMETRIC;
  تعريفنوع PENUMTEXTMETRICW PENUMTEXTMETRIC;
  تعريفنوع LPENUMTEXTMETRICW LPENUMTEXTMETRIC;
#وإلا
  تعريفنوع ENUMTEXTMETRICA ENUMTEXTMETRIC;
  تعريفنوع PENUMTEXTMETRICA PENUMTEXTMETRIC;
  تعريفنوع LPENUMTEXTMETRICA LPENUMTEXTMETRIC;
#پایان_اگر
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن ResetDC ResetDCW
#تعریف_کن RemoveFontResource RemoveFontResourceW
#وإلا
#تعریف_کن ResetDC ResetDCA
#تعریف_کن RemoveFontResource RemoveFontResourceA
#پایان_اگر

  WINGDIAPI WINBOOL WINAPI GetViewportExtEx(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI GetViewportOrgEx(HDC hdc,LPPOINT lppoint);
  WINGDIAPI WINBOOL WINAPI Get_پنجره_Ext_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI Get_پنجره_Org_Ex(HDC hdc,LPPOINT lppoint);
  WINGDIAPI صحيح WINAPI IntersectClipRect(HDC hdc,صحيح چپ,صحيح بالاترین,صحيح راست,صحيح bottom);
  WINGDIAPI WINBOOL WINAPI InvertRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI سطر_DDA(صحيح x_شروع,صحيح y_شروع,صحيح x_انتها,صحيح y_انتها,LINEDDAPROC lpProc,LPARAM داده);
  WINGDIAPI WINBOOL WINAPI سطر_مقصد(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI ماسک_Blt(HDC hdcDest,صحيح xDest,صحيح yDest,صحيح عرض,صحيح ارتفاع,HDC hdcSrc,صحيح xSrc,صحيح ySrc,HBITMAP hbm_ماسک,صحيح x_ماسک,صحيح y_ماسک,DWORD rop);
  WINGDIAPI WINBOOL WINAPI PlgBlt(HDC hdcDest,CONST نقطه_3 *lp_نقطه,HDC hdcSrc,صحيح xSrc,صحيح ySrc,صحيح عرض,صحيح ارتفاع,HBITMAP hbm_ماسک,صحيح x_ماسک,صحيح y_ماسک);
  WINGDIAPI صحيح WINAPI جابه_جایی_Clip_Rgn(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI صحيح WINAPI جابه_جایی_Rgn(HRGN hrgn,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI PatBlt(HDC hdc,صحيح x,صحيح y,صحيح w,صحيح h,DWORD rop);
  WINGDIAPI WINBOOL WINAPI Pie(HDC hdc,صحيح چپ,صحيح بالاترین,صحيح راست,صحيح bottom,صحيح xr1,صحيح yr1,صحيح xr2,صحيح yr2);
  WINGDIAPI WINBOOL WINAPI PlayMetaFile(HDC hdc,HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI PaintRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI PolyPolygon(HDC hdc,CONST نقطه_3 *apt,CONST INT *asz,صحيح csz);
  WINGDIAPI WINBOOL WINAPI Pt_درون_Region(HRGN hrgn,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI PtVisible(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI Rect_درون_Region(HRGN hrgn,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI RectVisible(HDC hdc,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Rectangle(HDC hdc,صحيح چپ,صحيح بالاترین,صحيح راست,صحيح bottom);
  WINGDIAPI WINBOOL WINAPI RestoreDC(HDC hdc,صحيح nSavedDC);
  WINGDIAPI HDC WINAPI ResetDCA(HDC hdc,CONST DEVMODEA *lpdm);
  WINGDIAPI HDC WINAPI ResetDCW(HDC hdc,CONST DEVMODEW *lpdm);
  WINGDIAPI UINT WINAPI RealizePalette(HDC hdc);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceA(LPCSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceW(LPCWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI دور_Rect(HDC hdc,صحيح چپ,صحيح بالاترین,صحيح راست,صحيح bottom,صحيح عرض,صحيح ارتفاع);
  WINGDIAPI WINBOOL WINAPI ResizePalette(HPALETTE hpal,UINT n);
  WINGDIAPI صحيح WINAPI SaveDC(HDC hdc);
  WINGDIAPI صحيح WINAPI SelectClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI صحيح WINAPI ExtSelectClipRgn(HDC hdc,HRGN hrgn,صحيح نما);
  WINGDIAPI صحيح WINAPI مجموعه_Meta_Rgn(HDC hdc);
  WINGDIAPI HGDIOBJ WINAPI SelectObject(HDC hdc,HGDIOBJ h);
  WINGDIAPI HPALETTE WINAPI SelectPalette(HDC hdc,HPALETTE hPal,WINBOOL bForceBkgd);
  WINGDIAPI COLORREF WINAPI مجموعه_Bk_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI مجموعه_DCBrush_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI مجموعه_DCPen_Color(HDC hdc,COLORREF color);
  WINGDIAPI صحيح WINAPI مجموعه_Bk_نما(HDC hdc,صحيح نما);
  WINGDIAPI LONG WINAPI مجموعه_Bitmap_بیتها(HBITMAP hbm,DWORD cb,CONST VOID *pv_بیتها);
  WINGDIAPI UINT WINAPI مجموعه_Bounds_Rect(HDC hdc,CONST RECT *lprect,UINT flags);
  WINGDIAPI صحيح WINAPI مجموعه_DIBits(HDC hdc,HBITMAP hbm,UINT شروع,UINT c_سطرها,CONST VOID *lp_بیتها,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI صحيح WINAPI مجموعه_DIBits_مقصد_Device(HDC hdc,صحيح xDest,صحيح yDest,DWORD w,DWORD h,صحيح xSrc,صحيح ySrc,UINT شروع_پیمایش,UINT c_سطرها,CONST VOID *lpv_بیتها,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI DWORD WINAPI مجموعه_Mapper_Flags(HDC hdc,DWORD flags);
  WINGDIAPI صحيح WINAPI مجموعه_Graphics_نما(HDC hdc,صحيح i_نما);
  WINGDIAPI صحيح WINAPI مجموعه_Map_نما(HDC hdc,صحيح i_نما);
  WINGDIAPI DWORD WINAPI مجموعه_Layout(HDC hdc,DWORD l);
  WINGDIAPI DWORD WINAPI GetLayout(HDC hdc);
  WINGDIAPI HMETAFILE WINAPI مجموعه_Meta_File_بیتها_Ex(UINT cb_میانگیر,CONST BYTE *lp_داده);
  WINGDIAPI UINT WINAPI مجموعه_Palette_Entries(HPALETTE hpal,UINT i_شروع,UINT cEntries,CONST PALETTEENTRY *pPalEntries);
  WINGDIAPI COLORREF WINAPI مجموعه_Pixel(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI مجموعه_Pixel_V(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI مجموعه_Pixel_Format(HDC hdc,صحيح format,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI صحيح WINAPI مجموعه_Poly_Fill_نما(HDC hdc,صحيح نما);
  WINGDIAPI WINBOOL WINAPI StretchBlt(HDC hdcDest,صحيح xDest,صحيح yDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xSrc,صحيح ySrc,صحيح wSrc,صحيح hSrc,DWORD rop);
  WINGDIAPI WINBOOL WINAPI مجموعه_Rect_Rgn(HRGN hrgn,صحيح چپ,صحيح بالاترین,صحيح راست,صحيح bottom);
  WINGDIAPI صحيح WINAPI StretchDIBits(HDC hdc,صحيح xDest,صحيح yDest,صحيح Dest_عرض,صحيح Dest_ارتفاع,صحيح xSrc,صحيح ySrc,صحيح Src_عرض,صحيح Src_ارتفاع,CONST VOID *lp_بیتها,CONST BITMAPINFO *lpbmi,UINT iUsage,DWORD rop);
  WINGDIAPI صحيح WINAPI مجموعه_ROP2(HDC hdc,صحيح rop2);
  WINGDIAPI صحيح WINAPI مجموعه_Stretch_Blt_نما(HDC hdc,صحيح نما);
  WINGDIAPI UINT WINAPI مجموعه_System_Palette_Use(HDC hdc,UINT use);
  WINGDIAPI صحيح WINAPI مجموعه_متن_Character_Extra(HDC hdc,صحيح extra);
  WINGDIAPI COLORREF WINAPI مجموعه_متن_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI مجموعه_متن_Align(HDC hdc,UINT align);
  WINGDIAPI WINBOOL WINAPI مجموعه_متن_Justification(HDC hdc,صحيح extra,صحيح شمار_2);
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
    ULONG فوقانی_چپ;
    ULONG پایینی_راست;
  } GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;

  تعريفنوع بنية _BLENDFUNCTION {
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE منبع_Constant_Alpha;
    BYTE AlphaFormat;
  } BLENDFUNCTION,*PBLENDFUNCTION;

#تعریف_کن AC_SRC_OVER 0x00
#تعریف_کن AC_SRC_ALPHA 0x01

  WINGDIAPI WINBOOL WINAPI AlphaBlend(HDC hdcDest,صحيح xoriginDest,صحيح yoriginDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xoriginSrc,صحيح yoriginSrc,صحيح wSrc,صحيح hSrc,BLENDFUNCTION ftn);
  WINGDIAPI WINBOOL WINAPI TransparentBlt(HDC hdcDest,صحيح xoriginDest,صحيح yoriginDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xoriginSrc,صحيح yoriginSrc,صحيح wSrc,صحيح hSrc,UINT crTransparent);

#تعریف_کن GRADIENT_FILL_RECT_H 0x00000000
#تعریف_کن GRADIENT_FILL_RECT_V 0x00000001
#تعریف_کن GRADIENT_FILL_TRIANGLE 0x00000002
#تعریف_کن GRADIENT_FILL_OP_FLAG 0x000000ff

  WINGDIAPI WINBOOL WINAPI GradientFill(HDC hdc,PTRIVERTEX p_رأس,ULONG n_رأس,PVOID pMesh,ULONG nMesh,ULONG ul_نما);

#اگر_تعریف_نشده NOMETAFILE

#اگر_تعریف_شده UNICODE
#تعریف_کن CopyEnhMetaFile CopyEnhMetaFileW
#تعریف_کن CreateEnhMetaFile CreateEnhMetaFileW
#تعریف_کن GetEnhMetaFile GetEnhMetaFileW
#تعریف_کن GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#وإلا
#تعریف_کن CopyEnhMetaFile CopyEnhMetaFileA
#تعریف_کن CreateEnhMetaFile CreateEnhMetaFileA
#تعریف_کن GetEnhMetaFile GetEnhMetaFileA
#تعریف_کن GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#پایان_اگر

  WINGDIAPI WINBOOL WINAPI Play_Meta_File_رکورد(HDC hdc,LPHANDLETABLE lp_Handle_جدول,LPMETARECORD lpMR,UINT noObjs);

  تعريفنوع صحيح (CALLBACK *MFENUMPROC)(HDC hdc,HANDLETABLE *lpht,METARECORD *lpMR,صحيح nObj,LPARAM param);

  WINGDIAPI WINBOOL WINAPI EnumMetaFile(HDC hdc,HMETAFILE hmf,MFENUMPROC proc,LPARAM param);

  تعريفنوع صحيح (CALLBACK *ENHMFENUMPROC)(HDC hdc,HANDLETABLE *lpht,CONST ENHMETARECORD *lpmr,صحيح hHandles,LPARAM داده);

  WINGDIAPI HENHMETAFILE WINAPI CloseEnhMetaFile(HDC hdc);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileA(HENHMETAFILE hEnh,LPCSTR lpFileName);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileW(HENHMETAFILE hEnh,LPCWSTR lpFileName);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileA(HDC hdc,LPCSTR lpFilename,CONST RECT *lprc,LPCSTR lpDesc);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileW(HDC hdc,LPCWSTR lpFilename,CONST RECT *lprc,LPCWSTR lpDesc);
  WINGDIAPI WINBOOL WINAPI DeleteEnhMetaFile(HENHMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI EnumEnhMetaFile(HDC hdc,HENHMETAFILE hmf,ENHMFENUMPROC proc,LPVOID param,CONST RECT *lpRect);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileA(LPCSTR lpName);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileW(LPCWSTR lpName);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_بیتها(HENHMETAFILE hEMF,UINT n_اندازه,LPBYTE lp_داده);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE hemf,UINT cch_میانگیر,LPSTR lpDescription);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE hemf,UINT cch_میانگیر,LPWSTR lpDescription);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_سرآیند(HENHMETAFILE hemf,UINT n_اندازه,LPENHMETAHEADER lp_Enh_Meta_سرآیند);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT n_رقم_Entries,LPPALETTEENTRY lpPaletteEntries);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePixelFormat(HENHMETAFILE hemf,UINT cb_میانگیر,PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI UINT WINAPI Get_Win_Meta_File_بیتها(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT i_Map_نما,HDC hdcRef);
  WINGDIAPI WINBOOL WINAPI PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Play_Enh_Meta_File_رکورد(HDC hdc,LPHANDLETABLE pht,CONST ENHMETARECORD *pmr,UINT cht);
  WINGDIAPI HENHMETAFILE WINAPI مجموعه_Enh_Meta_File_بیتها(UINT n_اندازه,CONST BYTE *pb);
  WINGDIAPI HENHMETAFILE WINAPI مجموعه_Win_Meta_File_بیتها(UINT n_اندازه,CONST BYTE *lp_Meta16_داده,HDC hdcRef,CONST METAFILEPICT *lpMFP);
  WINGDIAPI WINBOOL WINAPI GdiComment(HDC hdc,UINT n_اندازه,CONST BYTE *lp_داده);
#پایان_اگر

#اگر_تعریف_نشده NOTEXTMETRIC
#اگر_تعریف_شده UNICODE
#تعریف_کن Get_متن_Metrics Get_متن_Metrics_W
#وإلا
#تعریف_کن Get_متن_Metrics Get_متن_Metrics_A
#پایان_اگر

  WINGDIAPI WINBOOL WINAPI Get_متن_Metrics_A(HDC hdc,LPTEXTMETRICA lptm);
  WINGDIAPI WINBOOL WINAPI Get_متن_Metrics_W(HDC hdc,LPTEXTMETRICW lptm);
#پایان_اگر

  تعريفنوع بنية برچسب_DIBSECTION {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD ds_جابه_جایی;
  } DIBSECTION,*LPDIBSECTION,*PDIBSECTION;

  WINGDIAPI WINBOOL WINAPI AngleArc(HDC hdc,صحيح x,صحيح y,DWORD r,FLOAT شروع_Angle,FLOAT SweepAngle);
  WINGDIAPI WINBOOL WINAPI PolyPolyline(HDC hdc,CONST نقطه_3 *apt,CONST DWORD *asz,DWORD csz);
  WINGDIAPI WINBOOL WINAPI GetWorldTransform(HDC hdc,LPXFORM lpxf);
  WINGDIAPI WINBOOL WINAPI مجموعه_World_Transform(HDC hdc,CONST XFORM *lpxf);
  WINGDIAPI WINBOOL WINAPI ModifyWorldTransform(HDC hdc,CONST XFORM *lpxf,DWORD نما);
  WINGDIAPI WINBOOL WINAPI CombineTransform(LPXFORM lpxf_بیرون,CONST XFORM *lpxf1,CONST XFORM *lpxf2);
  WINGDIAPI HBITMAP WINAPI CreateDIBSection(HDC hdc,CONST BITMAPINFO *lpbmi,UINT usage,VOID **ppv_بیتها,HANDLE hSection,DWORD جابه_جایی);
  WINGDIAPI UINT WINAPI Get_DIBColor_جدول(HDC hdc,UINT i_شروع,UINT cEntries,RGBQUAD *prgbq);
  WINGDIAPI UINT WINAPI مجموعه_DIBColor_جدول(HDC hdc,UINT i_شروع,UINT cEntries,CONST RGBQUAD *prgbq);

#تعریف_کن CA_NEGATIVE 0x0001
#تعریف_کن CA_LOG_FILTER 0x0002

#تعریف_کن ILLUMINANT_DEVICE_DEFAULT 0
#تعریف_کن ILLUMINANT_A 1
#تعریف_کن ILLUMINANT_B 2
#تعریف_کن ILLUMINANT_C 3
#تعریف_کن ILLUMINANT_D50 4
#تعریف_کن ILLUMINANT_D55 5
#تعریف_کن ILLUMINANT_D65 6
#تعریف_کن ILLUMINANT_D75 7
#تعریف_کن ILLUMINANT_F2 8
#تعریف_کن ILLUMINANT_MAX_شاخص ILLUMINANT_F2

#تعریف_کن ILLUMINANT_TUNGSTEN ILLUMINANT_A
#تعریف_کن ILLUMINANT_DAYLIGHT ILLUMINANT_C
#تعریف_کن ILLUMINANT_FLUORESCENT ILLUMINANT_F2
#تعریف_کن ILLUMINANT_NTSC ILLUMINANT_C

#تعریف_کن RGB_GAMMA_MIN (کلمه_3)02500
#تعریف_کن RGB_GAMMA_MAX (کلمه_3)65000

#تعریف_کن REFERENCE_WHITE_MIN (کلمه_3)6000
#تعریف_کن REFERENCE_WHITE_MAX (کلمه_3)10000
#تعریف_کن REFERENCE_BLACK_MIN (کلمه_3)0
#تعریف_کن REFERENCE_BLACK_MAX (کلمه_3)4000

#تعریف_کن COLOR_ADJ_MIN (SHORT)-100
#تعریف_کن COLOR_ADJ_MAX (SHORT)100

  تعريفنوع بنية برچسب_COLORADJUSTMENT {
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

  WINGDIAPI WINBOOL WINAPI مجموعه_Color_Adjustment(HDC hdc,CONST COLORADJUSTMENT *lpca);
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

#اگر_تعریف_شده UNICODE
  تعريفنوع DOCINFOW DOCINFO;
  تعريفنوع LPDOCINFOW LPDOCINFO;
#وإلا
  تعريفنوع DOCINFOA DOCINFO;
  تعريفنوع LPDOCINFOA LPDOCINFO;
#پایان_اگر

#تعریف_کن DI_APPBANDING 0x00000001
#تعریف_کن DI_ROPS_READ_DESTINATION 0x00000002

#اگر_تعریف_شده UNICODE
#تعریف_کن شروع_Doc شروع_Doc_W
#تعریف_کن GetObject GetObjectW
#تعریف_کن متن_بیرون متن_بیرون_W
#تعریف_کن Ext_متن_بیرون Ext_متن_بیرون_W
#تعریف_کن Poly_متن_بیرون Poly_متن_بیرون_W
#تعریف_کن Get_متن_Face Get_متن_Face_W
#وإلا
#تعریف_کن شروع_Doc شروع_Doc_A
#تعریف_کن GetObject GetObjectA
#تعریف_کن متن_بیرون متن_بیرون_A
#تعریف_کن Ext_متن_بیرون Ext_متن_بیرون_A
#تعریف_کن Poly_متن_بیرون Poly_متن_بیرون_A
#تعریف_کن Get_متن_Face Get_متن_Face_A
#پایان_اگر

  WINGDIAPI صحيح WINAPI شروع_Doc_A(HDC hdc,CONST DOCINFOA *lpdi);
  WINGDIAPI صحيح WINAPI شروع_Doc_W(HDC hdc,CONST DOCINFOW *lpdi);
  WINGDIAPI صحيح WINAPI انتها_Doc(HDC hdc);
  WINGDIAPI صحيح WINAPI شروع_صفحه(HDC hdc);
  WINGDIAPI صحيح WINAPI انتها_صفحه(HDC hdc);
  WINGDIAPI صحيح WINAPI AbortDoc(HDC hdc);
  WINGDIAPI صحيح WINAPI مجموعه_Abort_Proc(HDC hdc,ABORTPROC proc);
  WINGDIAPI WINBOOL WINAPI Abort_مسیر(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Arc_مقصد(HDC hdc,صحيح چپ,صحيح بالاترین,صحيح راست,صحيح bottom,صحيح xr1,صحيح yr1,صحيح xr2,صحيح yr2);
  WINGDIAPI WINBOOL WINAPI Begin_مسیر(HDC hdc);
  WINGDIAPI WINBOOL WINAPI CloseFigure(HDC hdc);
  WINGDIAPI WINBOOL WINAPI انتها_مسیر_2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Fill_مسیر(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Flatten_مسیر(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_مسیر(HDC hdc,LPPOINT apt,LPBYTE aj,صحيح cpt);
  WINGDIAPI HRGN WINAPI مسیر_مقصد_Region(HDC hdc);
  WINGDIAPI WINBOOL WINAPI PolyDraw(HDC hdc,CONST نقطه_3 *apt,CONST BYTE *aj,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI Select_Clip_مسیر(HDC hdc,صحيح نما);
  WINGDIAPI صحيح WINAPI مجموعه_Arc_Direction(HDC hdc,صحيح dir);
  WINGDIAPI WINBOOL WINAPI مجموعه_Miter_حد(HDC hdc,FLOAT حد,PFLOAT old);
  WINGDIAPI WINBOOL WINAPI Stroke_And_Fill_مسیر(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Stroke_مسیر(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Widen_مسیر(HDC hdc);
  WINGDIAPI HPEN WINAPI ExtCreatePen(DWORD iPenStyle,DWORD c_عرض,CONST LOGBRUSH *plbrush,DWORD cStyle,CONST DWORD *pstyle);
  WINGDIAPI WINBOOL WINAPI Get_Miter_حد(HDC hdc,PFLOAT plimit);
  WINGDIAPI صحيح WINAPI GetArcDirection(HDC hdc);
  WINGDIAPI صحيح WINAPI GetObjectA(HANDLE h,صحيح c,LPVOID pv);
  WINGDIAPI صحيح WINAPI GetObjectW(HANDLE h,صحيح c,LPVOID pv);
  WINGDIAPI WINBOOL WINAPI Move_مقصد_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI متن_بیرون_A(HDC hdc,صحيح x,صحيح y,LPCSTR lpString,صحيح c);
  WINGDIAPI WINBOOL WINAPI متن_بیرون_W(HDC hdc,صحيح x,صحيح y,LPCWSTR lpString,صحيح c);
  WINGDIAPI WINBOOL WINAPI Ext_متن_بیرون_A(HDC hdc,صحيح x,صحيح y,UINT options,CONST RECT *lprect,LPCSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Ext_متن_بیرون_W(HDC hdc,صحيح x,صحيح y,UINT options,CONST RECT *lprect,LPCWSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Poly_متن_بیرون_A(HDC hdc,CONST POLYTEXTA *ppt,صحيح nstrings);
  WINGDIAPI WINBOOL WINAPI Poly_متن_بیرون_W(HDC hdc,CONST POLYTEXTW *ppt,صحيح nstrings);
  WINGDIAPI HRGN WINAPI CreatePolygonRgn(CONST نقطه_3 *pptl,صحيح c_نقطه,صحيح i_نما);
  WINGDIAPI WINBOOL WINAPI DPtoLP(HDC hdc,LPPOINT lppt,صحيح c);
  WINGDIAPI WINBOOL WINAPI LPtoDP(HDC hdc,LPPOINT lppt,صحيح c);
  WINGDIAPI WINBOOL WINAPI Polygon(HDC hdc,CONST نقطه_3 *apt,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI Polyline(HDC hdc,CONST نقطه_3 *apt,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI PolyBezier(HDC hdc,CONST نقطه_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Poly_Bezier_مقصد(HDC hdc,CONST نقطه_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Polyline_مقصد(HDC hdc,CONST نقطه_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI مجموعه_Viewport_Ext_Ex(HDC hdc,صحيح x,صحيح y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI مجموعه_Viewport_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI مجموعه_پنجره_Ext_Ex(HDC hdc,صحيح x,صحيح y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI مجموعه_پنجره_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI جابه_جایی_Viewport_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI جابه_جایی_پنجره_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ScaleViewportExtEx(HDC hdc,صحيح xn,صحيح dx,صحيح yn,صحيح yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Scale_پنجره_Ext_Ex(HDC hdc,صحيح xn,صحيح xd,صحيح yn,صحيح yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI مجموعه_Bitmap_Dimension_Ex(HBITMAP hbm,صحيح w,صحيح h,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI مجموعه_Brush_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI صحيح WINAPI Get_متن_Face_A(HDC hdc,صحيح c,LPSTR lpName);
  WINGDIAPI صحيح WINAPI Get_متن_Face_W(HDC hdc,صحيح c,LPWSTR lpName);

#تعریف_کن FONTMAPPER_MAX 10

  تعريفنوع بنية برچسب_KERNINGPAIR {
    کلمه_3 w_اولی;
    کلمه_3 w_دومی;
    صحيح iKernAmount;
  } KERNINGPAIR,*LPKERNINGPAIR;

#اگر_تعریف_شده UNICODE
#تعریف_کن Get_Kerning_جفتها Get_Kerning_جفتها_W
#وإلا
#تعریف_کن Get_Kerning_جفتها Get_Kerning_جفتها_A
#پایان_اگر

  WINGDIAPI DWORD WINAPI Get_Kerning_جفتها_A(HDC hdc,DWORD n_جفتها,LPKERNINGPAIR lpKernPair);
  WINGDIAPI DWORD WINAPI Get_Kerning_جفتها_W(HDC hdc,DWORD n_جفتها,LPKERNINGPAIR lpKernPair);
  WINGDIAPI WINBOOL WINAPI GetDCOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI FixBrushOrgEx(HDC hdc,صحيح x,صحيح y,LPPOINT ptl);
  WINGDIAPI WINBOOL WINAPI UnrealizeObject(HGDIOBJ h);
  WINGDIAPI WINBOOL WINAPI GdiFlush();
  WINGDIAPI DWORD WINAPI Gdi_مجموعه_Batch_حد(DWORD dw);
  WINGDIAPI DWORD WINAPI Gdi_Get_Batch_حد();

#تعریف_کن ICM_OFF 1
#تعریف_کن ICM_ON 2
#تعریف_کن ICM_QUERY 3
#تعریف_کن ICM_انجامشده_OUTSIDEDC 4

  تعريفنوع صحيح (CALLBACK *ICMENUMPROCA)(LPSTR,LPARAM);
  تعريفنوع صحيح (CALLBACK *ICMENUMPROCW)(LPWSTR,LPARAM);

#اگر_تعریف_شده UNICODE
#تعریف_کن ICMENUMPROC ICMENUMPROCW
#تعریف_کن EnumICMProfiles EnumICMProfilesW
#تعریف_کن Update_ICMReg_کلید Update_ICMReg_کلید_W
#تعریف_کن GetLogColorSpace GetLogColorSpaceW
#تعریف_کن CreateColorSpace CreateColorSpaceW
#تعریف_کن GetICMProfile GetICMProfileW
#تعریف_کن مجموعه_ICMProfile مجموعه_ICMProfile_W
#وإلا
#تعریف_کن ICMENUMPROC ICMENUMPROCA
#تعریف_کن EnumICMProfiles EnumICMProfilesA
#تعریف_کن Update_ICMReg_کلید Update_ICMReg_کلید_A
#تعریف_کن GetLogColorSpace GetLogColorSpaceA
#تعریف_کن CreateColorSpace CreateColorSpaceA
#تعریف_کن GetICMProfile GetICMProfileA
#تعریف_کن مجموعه_ICMProfile مجموعه_ICMProfile_A
#پایان_اگر

  WINGDIAPI صحيح WINAPI مجموعه_ICMMode(HDC hdc,صحيح نما);
  WINGDIAPI WINBOOL WINAPI Check_Colors_درون_Gamut(HDC hdc,LPVOID lpRGBTriple,LPVOID dlp_میانگیر,DWORD n_شمار);
  WINGDIAPI HCOLORSPACE WINAPI GetColorSpace(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceA(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEA lp_میانگیر,DWORD n_اندازه);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceW(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEW lp_میانگیر,DWORD n_اندازه);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA lplcs);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW lplcs);
  WINGDIAPI HCOLORSPACE WINAPI مجموعه_Color_Space(HDC hdc,HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI DeleteColorSpace(HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI GetICMProfileA(HDC hdc,LPDWORD p_Buf_اندازه,LPSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI GetICMProfileW(HDC hdc,LPDWORD p_Buf_اندازه,LPWSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI مجموعه_ICMProfile_A(HDC hdc,LPSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI مجموعه_ICMProfile_W(HDC hdc,LPWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI GetDeviceGammaRamp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI مجموعه_Device_Gamma_Ramp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI Color_تطابق_مقصد_هدف(HDC hdc,HDC hdc_هدف,DWORD action);
  WINGDIAPI صحيح WINAPI EnumICMProfilesA(HDC hdc,ICMENUMPROCA proc,LPARAM param);
  WINGDIAPI صحيح WINAPI EnumICMProfilesW(HDC hdc,ICMENUMPROCW proc,LPARAM param);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_کلید_A(DWORD reserved,LPSTR lpszCMID,LPSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_کلید_W(DWORD reserved,LPWSTR lpszCMID,LPWSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI ColorCorrectPalette(HDC hdc,HPALETTE hPal,DWORD de_اولی,DWORD رقم);

#اگر_تعریف_نشده NOMETAFILE

#تعریف_کن ENHMETA_SIGNATURE 0x464D4520
#تعریف_کن ENHMETA_STOCK_OBJECT 0x80000000

#تعریف_کن EMR_سرآیند 1
#تعریف_کن EMR_POLYBEZIER 2
#تعریف_کن EMR_POLYGON 3
#تعریف_کن EMR_POLYLINE 4
#تعریف_کن EMR_POLYBEZIERTO 5
#تعریف_کن EMR_POLYLINETO 6
#تعریف_کن EMR_POLYPOLYLINE 7
#تعریف_کن EMR_POLYPOLYGON 8
#تعریف_کن EMR_SETWINDOWEXTEX 9
#تعریف_کن EMR_SETWINDOWORGEX 10
#تعریف_کن EMR_SETVIEWPORTEXTEX 11
#تعریف_کن EMR_SETVIEWPORTORGEX 12
#تعریف_کن EMR_SETBRUSHORGEX 13
#تعریف_کن EMR_EOF 14
#تعریف_کن EMR_SETPIXELV 15
#تعریف_کن EMR_SETMAPPERFLAGS 16
#تعریف_کن EMR_SETMAPMODE 17
#تعریف_کن EMR_SETBKMODE 18
#تعریف_کن EMR_SETPOLYFILLMODE 19
#تعریف_کن EMR_SETROP2 20
#تعریف_کن EMR_SETSTRETCHBLTMODE 21
#تعریف_کن EMR_SETTEXTALIGN 22
#تعریف_کن EMR_SETCOLORADJUSTMENT 23
#تعریف_کن EMR_SETTEXTCOLOR 24
#تعریف_کن EMR_SETBKCOLOR 25
#تعریف_کن EMR_OFFSETCLIPRGN 26
#تعریف_کن EMR_MOVETOEX 27
#تعریف_کن EMR_SETMETARGN 28
#تعریف_کن EMR_EXCLUDECLIPRECT 29
#تعریف_کن EMR_INTERSECTCLIPRECT 30
#تعریف_کن EMR_SCALEVIEWPORTEXTEX 31
#تعریف_کن EMR_SCALEWINDOWEXTEX 32
#تعریف_کن EMR_SAVEDC 33
#تعریف_کن EMR_RESTOREDC 34
#تعریف_کن EMR_SETWORLDTRANSFORM 35
#تعریف_کن EMR_MODIFYWORLDTRANSFORM 36
#تعریف_کن EMR_SELECTOBJECT 37
#تعریف_کن EMR_CREATEPEN 38
#تعریف_کن EMR_CREATEBRUSHINDIRECT 39
#تعریف_کن EMR_DELETEOBJECT 40
#تعریف_کن EMR_ANGLEARC 41
#تعریف_کن EMR_ELLIPSE 42
#تعریف_کن EMR_RECTANGLE 43
#تعریف_کن EMR_ROUNDRECT 44
#تعریف_کن EMR_ARC 45
#تعریف_کن EMR_CHORD 46
#تعریف_کن EMR_PIE 47
#تعریف_کن EMR_SELECTPALETTE 48
#تعریف_کن EMR_CREATEPALETTE 49
#تعریف_کن EMR_SETPALETTEENTRIES 50
#تعریف_کن EMR_RESIZEPALETTE 51
#تعریف_کن EMR_REALIZEPALETTE 52
#تعریف_کن EMR_EXTFLOODFILL 53
#تعریف_کن EMR_LINETO 54
#تعریف_کن EMR_ARCTO 55
#تعریف_کن EMR_POLYDRAW 56
#تعریف_کن EMR_SETARCDIRECTION 57
#تعریف_کن EMR_SETMITERLIMIT 58
#تعریف_کن EMR_BEGINPATH 59
#تعریف_کن EMR_ENDPATH 60
#تعریف_کن EMR_CLOSEFIGURE 61
#تعریف_کن EMR_FILLPATH 62
#تعریف_کن EMR_STROKEANDFILLPATH 63
#تعریف_کن EMR_STROKEPATH 64
#تعریف_کن EMR_FLATTENPATH 65
#تعریف_کن EMR_WIDENPATH 66
#تعریف_کن EMR_SELECTCLIPPATH 67
#تعریف_کن EMR_ABORTPATH 68

#تعریف_کن EMR_GDICOMMENT 70
#تعریف_کن EMR_FILLRGN 71
#تعریف_کن EMR_FRAMERGN 72
#تعریف_کن EMR_INVERTRGN 73
#تعریف_کن EMR_PAINTRGN 74
#تعریف_کن EMR_EXTSELECTCLIPRGN 75
#تعریف_کن EMR_BITBLT 76
#تعریف_کن EMR_STRETCHBLT 77
#تعریف_کن EMR_MASKBLT 78
#تعریف_کن EMR_PLGBLT 79
#تعریف_کن EMR_SETDIBITSTODEVICE 80
#تعریف_کن EMR_STRETCHDIBITS 81
#تعریف_کن EMR_EXTCREATEFONTINDIRECTW 82
#تعریف_کن EMR_EXTTEXTOUTA 83
#تعریف_کن EMR_EXTTEXTOUTW 84
#تعریف_کن EMR_POLYBEZIER16 85
#تعریف_کن EMR_POLYGON16 86
#تعریف_کن EMR_POLYLINE16 87
#تعریف_کن EMR_POLYBEZIERTO16 88
#تعریف_کن EMR_POLYLINETO16 89
#تعریف_کن EMR_POLYPOLYLINE16 90
#تعریف_کن EMR_POLYPOLYGON16 91
#تعریف_کن EMR_POLYDRAW16 92
#تعریف_کن EMR_CREATEMONOBRUSH 93
#تعریف_کن EMR_CREATEDIBPATTERNBRUSHPT 94
#تعریف_کن EMR_EXTCREATEPEN 95
#تعریف_کن EMR_POLYTEXTOUTA 96
#تعریف_کن EMR_POLYTEXTOUTW 97

#تعریف_کن EMR_SETICMMODE 98
#تعریف_کن EMR_CREATECOLORSPACE 99
#تعریف_کن EMR_SETCOLORSPACE 100
#تعریف_کن EMR_DELETECOLORSPACE 101
#تعریف_کن EMR_GLSRECORD 102
#تعریف_کن EMR_GLSBOUNDEDRECORD 103
#تعریف_کن EMR_PIXELFORMAT 104
#تعریف_کن EMR_RESERVED_105 105
#تعریف_کن EMR_RESERVED_106 106
#تعریف_کن EMR_RESERVED_107 107
#تعریف_کن EMR_RESERVED_108 108
#تعریف_کن EMR_RESERVED_109 109
#تعریف_کن EMR_RESERVED_110 110
#تعریف_کن EMR_COLORCORRECTPALETTE 111
#تعریف_کن EMR_SETICMPROFILEA 112
#تعریف_کن EMR_SETICMPROFILEW 113
#تعریف_کن EMR_ALPHABLEND 114
#تعریف_کن EMR_SETLAYOUT 115
#تعریف_کن EMR_TRANSPARENTBLT 116
#تعریف_کن EMR_RESERVED_117 117
#تعریف_کن EMR_GRADIENTFILL 118
#تعریف_کن EMR_RESERVED_119 119
#تعریف_کن EMR_RESERVED_120 120
#تعریف_کن EMR_COLORMATCHTOTARGETW 121
#تعریف_کن EMR_CREATECOLORSPACEW 122

#تعریف_کن EMR_MIN 1

#تعریف_کن EMR_MAX 122

  تعريفنوع بنية برچسب_EMR {
    DWORD iType;
    DWORD n_اندازه;
  } EMR,*PEMR;

  تعريفنوع بنية برچسب_EMRTEXT {
    POINTL ptlReference;
    DWORD nChars;
    DWORD offString;
    DWORD fOptions;
    RECTL rcl;
    DWORD offDx;
  } EMRTEXT,*PEMRTEXT;

  تعريفنوع بنية برچسب_ABORTPATH {
    EMR emr;
  } EMRABORTPATH,*PEMRABORTPATH,EMRBEGINPATH,*PEMRBEGINPATH,EMRENDPATH,*PEMRENDPATH,EMRCLOSEFIGURE,*PEMRCLOSEFIGURE,EMRFLATTENPATH,*PEMRFLATTENPATH,EMRWIDENPATH,*PEMRWIDENPATH,EMRSETMETARGN,*PEMRSETMETARGN,EMRSAVEDC,*PEMRSAVEDC,EMRREALIZEPALETTE,*PEMRREALIZEPALETTE;

  تعريفنوع بنية برچسب_EMRSELECTCLIPPATH {
    EMR emr;
    DWORD i_نما;
  } EMRSELECTCLIPPATH,*PEMRSELECTCLIPPATH,EMRSETBKMODE,*PEMRSETBKMODE,EMRSETMAPMODE,*PEMRSETMAPMODE,EMRSETLAYOUT,*PEMRSETLAYOUT,
    EMRSETPOLYFILLMODE,*PEMRSETPOLYFILLMODE,EMRSETROP2,*PEMRSETROP2,EMRSETSTRETCHBLTMODE,*PEMRSETSTRETCHBLTMODE,EMRSETICMMODE,
    *PEMRSETICMMODE,EMRSETTEXTALIGN,*PEMRSETTEXTALIGN;

  تعريفنوع بنية برچسب_EMRSETMITERLIMIT {
    EMR emr;
    FLOAT e_Miter_حد;
  } EMRSETMITERLIMIT,*PEMRSETMITERLIMIT;

  تعريفنوع بنية برچسب_EMRRESTOREDC {
    EMR emr;
    LONG iRelative;
  } EMRRESTOREDC,*PEMRRESTOREDC;

  تعريفنوع بنية برچسب_EMRSETARCDIRECTION {
    EMR emr;
    DWORD iArcDirection;

  } EMRSETARCDIRECTION,*PEMRSETARCDIRECTION;

  تعريفنوع بنية برچسب_EMRSETMAPPERFLAGS {
    EMR emr;
    DWORD dwFlags;
  } EMRSETMAPPERFLAGS,*PEMRSETMAPPERFLAGS;

  تعريفنوع بنية برچسب_EMRSETTEXTCOLOR {
    EMR emr;
    COLORREF crColor;
  } EMRSETBKCOLOR,*PEMRSETBKCOLOR,EMRSETTEXTCOLOR,*PEMRSETTEXTCOLOR;

  تعريفنوع بنية برچسب_EMRSELECTOBJECT {
    EMR emr;
    DWORD ihObject;
  } EMRSELECTOBJECT,*PEMRSELECTOBJECT,EMRDELETEOBJECT,*PEMRDELETEOBJECT;

  تعريفنوع بنية برچسب_EMRSELECTPALETTE {
    EMR emr;
    DWORD ihPal;
  } EMRSELECTPALETTE,*PEMRSELECTPALETTE;

  تعريفنوع بنية برچسب_EMRRESIZEPALETTE {
    EMR emr;
    DWORD ihPal;
    DWORD cEntries;
  } EMRRESIZEPALETTE,*PEMRRESIZEPALETTE;

  تعريفنوع بنية برچسب_EMRSETPALETTEENTRIES {
    EMR emr;
    DWORD ihPal;
    DWORD i_شروع;
    DWORD cEntries;
    PALETTEENTRY aPalEntries[1];
  } EMRSETPALETTEENTRIES,*PEMRSETPALETTEENTRIES;

  تعريفنوع بنية برچسب_EMRSETCOLORADJUSTMENT {
    EMR emr;
    COLORADJUSTMENT ColorAdjustment;
  } EMRSETCOLORADJUSTMENT,*PEMRSETCOLORADJUSTMENT;

  تعريفنوع بنية برچسب_EMRGDICOMMENT {
    EMR emr;
    DWORD cb_داده;
    BYTE داده_3[1];
  } EMRGDICOMMENT,*PEMRGDICOMMENT;

  تعريفنوع بنية برچسب_EMREOF {
    EMR emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD n_اندازه_آخرین;
  } EMREOF,*PEMREOF;

  تعريفنوع بنية برچسب_EMRLINETO {
    EMR emr;
    POINTL ptl;
  } EMRLINETO,*PEMRLINETO,EMRMOVETOEX,*PEMRMOVETOEX;

  تعريفنوع بنية برچسب_EMROFFSETCLIPRGN {
    EMR emr;
    POINTL ptl_جابه_جایی;
  } EMROFFSETCLIPRGN,*PEMROFFSETCLIPRGN;

  تعريفنوع بنية برچسب_EMRFILLPATH {
    EMR emr;
    RECTL rclBounds;
  } EMRFILLPATH,*PEMRFILLPATH,EMRSTROKEANDFILLPATH,*PEMRSTROKEANDFILLPATH,EMRSTROKEPATH,*PEMRSTROKEPATH;

  تعريفنوع بنية برچسب_EMREXCLUDECLIPRECT {
    EMR emr;
    RECTL rclClip;
  } EMREXCLUDECLIPRECT,*PEMREXCLUDECLIPRECT,EMRINTERSECTCLIPRECT,*PEMRINTERSECTCLIPRECT;

  تعريفنوع بنية برچسب_EMRSETVIEWPORTORGEX {
    EMR emr;
    POINTL ptlOrigin;
  } EMRSETVIEWPORTORGEX,*PEMRSETVIEWPORTORGEX,EMRSETWINDOWORGEX,*PEMRSETWINDOWORGEX,EMRSETBRUSHORGEX,*PEMRSETBRUSHORGEX;

  تعريفنوع بنية برچسب_EMRSETVIEWPORTEXTEX {
    EMR emr;
    SIZEL szlExtent;
  } EMRSETVIEWPORTEXTEX,*PEMRSETVIEWPORTEXTEX,EMRSETWINDOWEXTEX,*PEMRSETWINDOWEXTEX;

  تعريفنوع بنية برچسب_EMRSCALEVIEWPORTEXTEX {
    EMR emr;
    LONG x_رقم;
    LONG xDenom;
    LONG y_رقم;
    LONG yDenom;
  } EMRSCALEVIEWPORTEXTEX,*PEMRSCALEVIEWPORTEXTEX,EMRSCALEWINDOWEXTEX,*PEMRSCALEWINDOWEXTEX;

  تعريفنوع بنية برچسب_EMRSETWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
  } EMRSETWORLDTRANSFORM,*PEMRSETWORLDTRANSFORM;

  تعريفنوع بنية برچسب_EMRMODIFYWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
    DWORD i_نما;
  } EMRMODIFYWORLDTRANSFORM,*PEMRMODIFYWORLDTRANSFORM;

  تعريفنوع بنية برچسب_EMRSETPIXELV {
    EMR emr;
    POINTL ptlPixel;
    COLORREF crColor;
  } EMRSETPIXELV,*PEMRSETPIXELV;

  تعريفنوع بنية برچسب_EMREXTFLOODFILL {
    EMR emr;
    POINTL ptl_شروع;
    COLORREF crColor;
    DWORD i_نما;
  } EMREXTFLOODFILL,*PEMREXTFLOODFILL;

  تعريفنوع بنية برچسب_EMRELLIPSE {
    EMR emr;
    RECTL rclBox;
  } EMRELLIPSE,*PEMRELLIPSE,EMRRECTANGLE,*PEMRRECTANGLE;

  تعريفنوع بنية برچسب_EMRROUNDRECT {
    EMR emr;
    RECTL rclBox;
    SIZEL szl_گوشه;
  } EMRROUNDRECT,*PEMRROUNDRECT;

  تعريفنوع بنية برچسب_EMRARC {
    EMR emr;
    RECTL rclBox;
    POINTL ptl_شروع;
    POINTL ptl_انتها;
  } EMRARC,*PEMRARC,EMRARCTO,*PEMRARCTO,EMRCHORD,*PEMRCHORD,EMRPIE,*PEMRPIE;

  تعريفنوع بنية برچسب_EMRANGLEARC {
    EMR emr;
    POINTL ptlCenter;
    DWORD nRadius;
    FLOAT e_شروع_Angle;
    FLOAT eSweepAngle;
  } EMRANGLEARC,*PEMRANGLEARC;

  تعريفنوع بنية برچسب_EMRPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
  } EMRPOLYLINE,*PEMRPOLYLINE,EMRPOLYBEZIER,*PEMRPOLYBEZIER,EMRPOLYGON,*PEMRPOLYGON,EMRPOLYBEZIERTO,*PEMRPOLYBEZIERTO,EMRPOLYLINETO,*PEMRPOLYLINETO;

  تعريفنوع بنية برچسب_EMRPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
  } EMRPOLYLINE16,*PEMRPOLYLINE16,EMRPOLYBEZIER16,*PEMRPOLYBEZIER16,EMRPOLYGON16,*PEMRPOLYGON16,EMRPOLYBEZIERTO16,*PEMRPOLYBEZIERTO16,EMRPOLYLINETO16,*PEMRPOLYLINETO16;

  تعريفنوع بنية برچسب_EMRPOLYDRAW {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW,*PEMRPOLYDRAW;

  تعريفنوع بنية برچسب_EMRPOLYDRAW16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW16,*PEMRPOLYDRAW16;

  تعريفنوع بنية برچسب_EMRPOLYPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cptl;
    DWORD aPolyCounts[1];
    POINTL aptl[1];
  } EMRPOLYPOLYLINE,*PEMRPOLYPOLYLINE,EMRPOLYPOLYGON,*PEMRPOLYPOLYGON;

  تعريفنوع بنية برچسب_EMRPOLYPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cpts;
    DWORD aPolyCounts[1];
    POINTS apts[1];
  } EMRPOLYPOLYLINE16,*PEMRPOLYPOLYLINE16,EMRPOLYPOLYGON16,*PEMRPOLYPOLYGON16;

  تعريفنوع بنية برچسب_EMRINVERTRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_داده;
    BYTE Rgn_داده[1];
  } EMRINVERTRGN,*PEMRINVERTRGN,EMRPAINTRGN,*PEMRPAINTRGN;

  تعريفنوع بنية برچسب_EMRFILLRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_داده;
    DWORD ihBrush;
    BYTE Rgn_داده[1];
  } EMRFILLRGN,*PEMRFILLRGN;

  تعريفنوع بنية برچسب_EMRFRAMERGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_داده;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE Rgn_داده[1];
  } EMRFRAMERGN,*PEMRFRAMERGN;

  تعريفنوع بنية برچسب_EMREXTSELECTCLIPRGN {
    EMR emr;
    DWORD cb_Rgn_داده;
    DWORD i_نما;
    BYTE Rgn_داده[1];
  } EMREXTSELECTCLIPRGN,*PEMREXTSELECTCLIPRGN;

  تعريفنوع بنية برچسب_EMREXTTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_نما;
    FLOAT exScale;
    FLOAT eyScale;
    EMRTEXT emrtext;
  } EMREXTTEXTOUTA,*PEMREXTTEXTOUTA,EMREXTTEXTOUTW,*PEMREXTTEXTOUTW;

  تعريفنوع بنية برچسب_EMRPOLYTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_نما;
    FLOAT exScale;
    FLOAT eyScale;
    LONG c_رشتهها;
    EMRTEXT aemrtext[1];
  } EMRPOLYTEXTOUTA,*PEMRPOLYTEXTOUTA,EMRPOLYTEXTOUTW,*PEMRPOLYTEXTOUTW;

  تعريفنوع بنية برچسب_EMRBITBLT {
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
    DWORD off_بیتها_Src;
    DWORD cb_بیتها_Src;
  } EMRBITBLT,*PEMRBITBLT;

  تعريفنوع بنية برچسب_EMRSTRETCHBLT {
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
    DWORD off_بیتها_Src;
    DWORD cb_بیتها_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRSTRETCHBLT,*PEMRSTRETCHBLT;

  تعريفنوع بنية برچسب_EMRMASKBLT {
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
    DWORD off_بیتها_Src;
    DWORD cb_بیتها_Src;
    LONG x_ماسک;
    LONG y_ماسک;
    DWORD i_Usage_ماسک;
    DWORD off_Bmi_ماسک;
    DWORD cb_Bmi_ماسک;
    DWORD off_بیتها_ماسک;
    DWORD cb_بیتها_ماسک;
  } EMRMASKBLT,*PEMRMASKBLT;

  تعريفنوع بنية برچسب_EMRPLGBLT {
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
    DWORD off_بیتها_Src;
    DWORD cb_بیتها_Src;
    LONG x_ماسک;
    LONG y_ماسک;
    DWORD i_Usage_ماسک;
    DWORD off_Bmi_ماسک;
    DWORD cb_Bmi_ماسک;
    DWORD off_بیتها_ماسک;
    DWORD cb_بیتها_ماسک;
  } EMRPLGBLT,*PEMRPLGBLT;

  تعريفنوع بنية برچسب_EMRSETDIBITSTODEVICE {
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
    DWORD off_بیتها_Src;
    DWORD cb_بیتها_Src;
    DWORD iUsageSrc;
    DWORD i_شروع_پیمایش;
    DWORD cScans;
  } EMRSETDIBITSTODEVICE,*PEMRSETDIBITSTODEVICE;

  تعريفنوع بنية برچسب_EMRSTRETCHDIBITS {
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
    DWORD off_بیتها_Src;
    DWORD cb_بیتها_Src;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG cxDest;
    LONG cyDest;
  } EMRSTRETCHDIBITS,*PEMRSTRETCHDIBITS;

  تعريفنوع بنية برچسب_EMREXTCREATEFONTINDIRECTW {
    EMR emr;
    DWORD ihFont;
    EXTLOGFONTW elfw;
  } EMREXTCREATEFONTINDIRECTW,*PEMREXTCREATEFONTINDIRECTW;

  تعريفنوع بنية برچسب_EMRCREATEPALETTE {
    EMR emr;
    DWORD ihPal;
    LOGPALETTE lgpl;
  } EMRCREATEPALETTE,*PEMRCREATEPALETTE;

  تعريفنوع بنية برچسب_EMRCREATEPEN {
    EMR emr;
    DWORD ihPen;
    LOGPEN lopn;
  } EMRCREATEPEN,*PEMRCREATEPEN;

  تعريفنوع بنية برچسب_EMREXTCREATEPEN {
    EMR emr;
    DWORD ihPen;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بیتها;
    DWORD cb_بیتها;
    EXTLOGPEN elp;
  } EMREXTCREATEPEN,*PEMREXTCREATEPEN;

  تعريفنوع بنية برچسب_EMRCREATEBRUSHINDIRECT {
    EMR emr;
    DWORD ihBrush;
    LOGBRUSH32 lb;
  } EMRCREATEBRUSHINDIRECT,*PEMRCREATEBRUSHINDIRECT;

  تعريفنوع بنية برچسب_EMRCREATEMONOBRUSH {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بیتها;
    DWORD cb_بیتها;
  } EMRCREATEMONOBRUSH,*PEMRCREATEMONOBRUSH;

  تعريفنوع بنية برچسب_EMRCREATEDIBPATTERNBRUSHPT {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بیتها;
    DWORD cb_بیتها;
  } EMRCREATEDIBPATTERNBRUSHPT,*PEMRCREATEDIBPATTERNBRUSHPT;

  تعريفنوع بنية برچسب_EMRFORMAT {
    DWORD dSignature;
    DWORD n_نسخه;
    DWORD cb_داده;
    DWORD off_داده;
  } EMRFORMAT,*PEMRFORMAT;

  تعريفنوع بنية برچسب_EMRGLSRECORD {
    EMR emr;
    DWORD cb_داده;
    BYTE داده_3[1];
  } EMRGLSRECORD,*PEMRGLSRECORD;

  تعريفنوع بنية برچسب_EMRGLSBOUNDEDRECORD {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_داده;
    BYTE داده_3[1];
  } EMRGLSBOUNDEDRECORD,*PEMRGLSBOUNDEDRECORD;

  تعريفنوع بنية برچسب_EMRPIXELFORMAT {
    EMR emr;
    PIXELFORMATDESCRIPTOR pfd;
  } EMRPIXELFORMAT,*PEMRPIXELFORMAT;

  تعريفنوع بنية برچسب_EMRCREATECOLORSPACE {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEA lcs;
  } EMRCREATECOLORSPACE,*PEMRCREATECOLORSPACE;

  تعريفنوع بنية برچسب_EMRSETCOLORSPACE {
    EMR emr;
    DWORD ihCS;
  } EMRSETCOLORSPACE,*PEMRSETCOLORSPACE,EMRSELECTCOLORSPACE,*PEMRSELECTCOLORSPACE,EMRDELETECOLORSPACE,*PEMRDELETECOLORSPACE;

  تعريفنوع بنية برچسب_EMREXTESCAPE {
    EMR emr;
    INT iEscape;
    INT cb_Esc_داده;
    BYTE Esc_داده[1];
  } EMREXTESCAPE,*PEMREXTESCAPE,EMRDRAWESCAPE,*PEMRDRAWESCAPE;

  تعريفنوع بنية برچسب_EMRNAMEDESCAPE {
    EMR emr;
    INT iEscape;
    INT cbDriver;
    INT cb_Esc_داده;
    BYTE Esc_داده[1];
  } EMRNAMEDESCAPE,*PEMRNAMEDESCAPE;

#تعریف_کن SETICMPROFILE_EMBEDED 0x00000001

  تعريفنوع بنية برچسب_EMRSETICMPROFILE {
    EMR emr;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_داده;
    BYTE داده_3[1];
  } EMRSETICMPROFILE,*PEMRSETICMPROFILE,EMRSETICMPROFILEA,*PEMRSETICMPROFILEA,EMRSETICMPROFILEW,*PEMRSETICMPROFILEW;

#تعریف_کن CREATECOLORSPACE_EMBEDED 0x00000001

  تعريفنوع بنية برچسب_EMRCREATECOLORSPACEW {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEW lcs;
    DWORD dwFlags;
    DWORD cb_داده;
    BYTE داده_3[1];
  } EMRCREATECOLORSPACEW,*PEMRCREATECOLORSPACEW;

#تعریف_کن COLORMATCHTOTARGET_EMBEDED 0x00000001

  تعريفنوع بنية برچسب_COLORMATCHTOTARGET {
    EMR emr;
    DWORD dwAction;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_داده;
    BYTE داده_3[1];
  } EMRCOLORMATCHTOTARGET,*PEMRCOLORMATCHTOTARGET;

  تعريفنوع بنية برچسب_COLORCORRECTPALETTE {
    EMR emr;
    DWORD ihPalette;
    DWORD n_اولی_مدخل;
    DWORD nPalEntries;
    DWORD nReserved;
  } EMRCOLORCORRECTPALETTE,*PEMRCOLORCORRECTPALETTE;

  تعريفنوع بنية برچسب_EMRALPHABLEND {
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
    DWORD off_بیتها_Src;
    DWORD cb_بیتها_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRALPHABLEND,*PEMRALPHABLEND;

  تعريفنوع بنية برچسب_EMRGRADIENTFILL {
    EMR emr;
    RECTL rclBounds;
    DWORD nVer;
    DWORD nTri;
    ULONG ul_نما;
    TRIVERTEX Ver[1];
  } EMRGRADIENTFILL,*PEMRGRADIENTFILL;

  تعريفنوع بنية برچسب_EMRTRANSPARENTBLT {
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
    DWORD off_بیتها_Src;
    DWORD cb_بیتها_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRTRANSPARENTBLT,*PEMRTRANSPARENTBLT;

#تعریف_کن GDICOMMENT_IDENTIFIER 0x43494447
#تعریف_کن GDICOMMENT_WINDOWS_METAFILE 0x80000001
#تعریف_کن GDICOMMENT_BEGINGROUP 0x00000002
#تعریف_کن GDICOMMENT_ENDGROUP 0x00000003
#تعریف_کن GDICOMMENT_MULTIFORMATS 0x40000004
#تعریف_کن EPS_SIGNATURE 0x46535045
#تعریف_کن GDICOMMENT_UNICODE_STRING 0x00000040
#تعریف_کن GDICOMMENT_UNICODE_انتها 0x00000080
#پایان_اگر

#اگر_تعریف_شده UNICODE
#تعریف_کن wglUseFontBitmaps wglUseFontBitmapsW
#وإلا
#تعریف_کن wglUseFontBitmaps wglUseFontBitmapsA
#پایان_اگر

  WINGDIAPI WINBOOL WINAPI wglCopyContext(HGLRC,HGLRC,UINT);
  WINGDIAPI HGLRC WINAPI wglCreateContext(HDC);
  WINGDIAPI HGLRC WINAPI wglCreateLayerContext(HDC,صحيح);
  WINGDIAPI WINBOOL WINAPI wglDeleteContext(HGLRC);
  WINGDIAPI HGLRC WINAPI wglGetCurrentContext(VOID);
  WINGDIAPI HDC WINAPI wglGetCurrentDC(VOID);
  WINGDIAPI PROC WINAPI wgl_Get_Proc_آدرس(LPCSTR);
  WINGDIAPI WINBOOL WINAPI wglMakeCurrent(HDC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglShareLists(HGLRC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsA(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsW(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI جابجا_Buffers(HDC);

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

#تعریف_کن WGL_FONT_سطرها 0
#تعریف_کن WGL_FONT_POLYGONS 1

#اگر_تعریف_شده UNICODE
#تعریف_کن wglUseFontOutlines wglUseFontOutlinesW
#وإلا
#تعریف_کن wglUseFontOutlines wglUseFontOutlinesA
#پایان_اگر

  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesA(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,صحيح,LPGLYPHMETRICSFLOAT);
  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesW(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,صحيح,LPGLYPHMETRICSFLOAT);

  تعريفنوع بنية برچسب_LAYERPLANEDESCRIPTOR {
    کلمه_3 n_اندازه;
    کلمه_3 n_نسخه;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_بیتها;
    BYTE c_Red_بیتها;
    BYTE c_Red_لغزش;
    BYTE c_Green_بیتها;
    BYTE c_Green_لغزش;
    BYTE c_Blue_بیتها;
    BYTE c_Blue_لغزش;
    BYTE c_Alpha_بیتها;
    BYTE c_Alpha_لغزش;
    BYTE c_Accum_بیتها;
    BYTE c_Accum_Red_بیتها;
    BYTE c_Accum_Green_بیتها;
    BYTE c_Accum_Blue_بیتها;
    BYTE c_Accum_Alpha_بیتها;
    BYTE c_عمق_بیتها;
    BYTE c_Stencil_بیتها;
    BYTE cAuxBuffers;
    BYTE iLayerPlane;
    BYTE bReserved;
    COLORREF crTransparent;
  } LAYERPLANEDESCRIPTOR,*PLAYERPLANEDESCRIPTOR,*LPLAYERPLANEDESCRIPTOR;

#تعریف_کن LPD_DOUBLEBUFFER 0x00000001
#تعریف_کن LPD_STEREO 0x00000002
#تعریف_کن LPD_SUPPORT_GDI 0x00000010
#تعریف_کن LPD_SUPPORT_OPENGL 0x00000020
#تعریف_کن LPD_SHARE_عمق 0x00000040
#تعریف_کن LPD_SHARE_STENCIL 0x00000080
#تعریف_کن LPD_SHARE_ACCUM 0x00000100
#تعریف_کن LPD_جابجا_EXCHANGE 0x00000200
#تعریف_کن LPD_جابجا_COPY 0x00000400
#تعریف_کن LPD_TRANSPARENT 0x00001000

#تعریف_کن LPD_TYPE_RGBA 0
#تعریف_کن LPD_TYPE_COLORINDEX 1

#تعریف_کن WGL_جابجا_MAIN_PLANE 0x00000001
#تعریف_کن WGL_جابجا_OVERLAY1 0x00000002
#تعریف_کن WGL_جابجا_OVERLAY2 0x00000004
#تعریف_کن WGL_جابجا_OVERLAY3 0x00000008
#تعریف_کن WGL_جابجا_OVERLAY4 0x00000010
#تعریف_کن WGL_جابجا_OVERLAY5 0x00000020
#تعریف_کن WGL_جابجا_OVERLAY6 0x00000040
#تعریف_کن WGL_جابجا_OVERLAY7 0x00000080
#تعریف_کن WGL_جابجا_OVERLAY8 0x00000100
#تعریف_کن WGL_جابجا_OVERLAY9 0x00000200
#تعریف_کن WGL_جابجا_OVERLAY10 0x00000400
#تعریف_کن WGL_جابجا_OVERLAY11 0x00000800
#تعریف_کن WGL_جابجا_OVERLAY12 0x00001000
#تعریف_کن WGL_جابجا_OVERLAY13 0x00002000
#تعریف_کن WGL_جابجا_OVERLAY14 0x00004000
#تعریف_کن WGL_جابجا_OVERLAY15 0x00008000
#تعریف_کن WGL_جابجا_UNDERLAY1 0x00010000
#تعریف_کن WGL_جابجا_UNDERLAY2 0x00020000
#تعریف_کن WGL_جابجا_UNDERLAY3 0x00040000
#تعریف_کن WGL_جابجا_UNDERLAY4 0x00080000
#تعریف_کن WGL_جابجا_UNDERLAY5 0x00100000
#تعریف_کن WGL_جابجا_UNDERLAY6 0x00200000
#تعریف_کن WGL_جابجا_UNDERLAY7 0x00400000
#تعریف_کن WGL_جابجا_UNDERLAY8 0x00800000
#تعریف_کن WGL_جابجا_UNDERLAY9 0x01000000
#تعریف_کن WGL_جابجا_UNDERLAY10 0x02000000
#تعریف_کن WGL_جابجا_UNDERLAY11 0x04000000
#تعریف_کن WGL_جابجا_UNDERLAY12 0x08000000
#تعریف_کن WGL_جابجا_UNDERLAY13 0x10000000
#تعریف_کن WGL_جابجا_UNDERLAY14 0x20000000
#تعریف_کن WGL_جابجا_UNDERLAY15 0x40000000

  WINGDIAPI WINBOOL WINAPI wglDescribeLayerPlane(HDC,صحيح,صحيح,UINT,LPLAYERPLANEDESCRIPTOR);
  WINGDIAPI صحيح WINAPI wgl_مجموعه_Layer_Palette_Entries(HDC,صحيح,صحيح,صحيح,CONST COLORREF *);
  WINGDIAPI صحيح WINAPI wglGetLayerPaletteEntries(HDC,صحيح,صحيح,صحيح,COLORREF *);
  WINGDIAPI WINBOOL WINAPI wglRealizeLayerPalette(HDC,صحيح,WINBOOL);
  WINGDIAPI WINBOOL WINAPI wgl_جابجا_Layer_Buffers(HDC,UINT);

  تعريفنوع بنية _WGLSWAP {
    HDC hdc;
    UINT uiFlags;
  } WGLSWAP,*PWGLSWAP,*LPWGLSWAP;

#تعریف_کن WGL_SWAPMULTIPLE_MAX 16

  WINGDIAPI DWORD WINAPI wgl_جابجا_مضرب_Buffers(UINT,CONST WGLSWAP *);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
