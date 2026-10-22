/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#నిర్వచితం_కాకపోతే _WINGDI_
#నిర్వచించు _WINGDI_

#నిర్వచించు WINGDIAPI DECLSPEC_IMPORT
#నిర్వచించు WINSPOOLAPI DECLSPEC_IMPORT

#నిర్వచితమైతే __cplusplus
బాహ్య "C" {
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే WINVER
#నిర్వచించు WINVER 0x0502
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOGDI
#నిర్వచితం_కాకపోతే NORASTEROPS
#నిర్వచించు R2_BLACK 1
#నిర్వచించు R2_NOTMERGEPEN 2
#నిర్వచించు R2_MASKNOTPEN 3
#నిర్వచించు R2_NOTCOPYPEN 4
#నిర్వచించు R2_MASKPENNOT 5
#నిర్వచించు R2_NOT 6
#నిర్వచించు R2_XORPEN 7
#నిర్వచించు R2_NOTMASKPEN 8
#నిర్వచించు R2_MASKPEN 9
#నిర్వచించు R2_NOTXORPEN 10
#నిర్వచించు R2_NOP 11
#నిర్వచించు R2_MERGENOTPEN 12
#నిర్వచించు R2_COPYPEN 13
#నిర్వచించు R2_MERGEPENNOT 14
#నిర్వచించు R2_MERGEPEN 15
#నిర్వచించు R2_WHITE 16
#నిర్వచించు R2_చివరి 16

#నిర్వచించు SRCCOPY (DWORD)0x00CC0020
#నిర్వచించు SRCPAINT (DWORD)0x00EE0086
#నిర్వచించు SRCAND (DWORD)0x008800C6
#నిర్వచించు SRCINVERT (DWORD)0x00660046
#నిర్వచించు SRCERASE (DWORD)0x00440328
#నిర్వచించు NOTSRCCOPY (DWORD)0x00330008
#నిర్వచించు NOTSRCERASE (DWORD)0x001100A6
#నిర్వచించు MERGECOPY (DWORD)0x00C000CA
#నిర్వచించు MERGEPAINT (DWORD)0x00BB0226
#నిర్వచించు PATCOPY (DWORD)0x00F00021
#నిర్వచించు PATPAINT (DWORD)0x00FB0A09
#నిర్వచించు PATINVERT (DWORD)0x005A0049
#నిర్వచించు DSTINVERT (DWORD)0x00550009
#నిర్వచించు BLACKNESS (DWORD)0x00000042
#నిర్వచించు WHITENESS (DWORD)0x00FF0062
#నిర్వచించు NOMIRRORBITMAP (DWORD)0x80000000
#నిర్వచించు CAPTUREBLT (DWORD)0x40000000
#నిర్వచించు MAKEROP4(fore,వెనుక) (DWORD)((((వెనుక) << 8) & 0xFF000000) | (fore))
#అయితే_ముగింపు

#నిర్వచించు GDI_ERROR (0xFFFFFFFFL)
#నిర్వచించు HGDI_ERROR (Long_గమ్యం_Handle(0xFFFFFFFFL))

#నిర్వచించు ERROR 0
#నిర్వచించు NULLREGION 1
#నిర్వచించు SIMPLEREGION 2
#నిర్వచించు COMPLEXREGION 3
#నిర్వచించు RGN_ERROR ERROR

#నిర్వచించు RGN_AND 1
#నిర్వచించు RGN_OR 2
#నిర్వచించు RGN_XOR 3
#నిర్వచించు RGN_DIFF 4
#నిర్వచించు RGN_COPY 5
#నిర్వచించు RGN_MIN RGN_AND
#నిర్వచించు RGN_MAX RGN_COPY

#నిర్వచించు BLACKONWHITE 1
#నిర్వచించు WHITEONBLACK 2
#నిర్వచించు COLORONCOLOR 3
#నిర్వచించు HALFTONE 4
#నిర్వచించు MAXSTRETCHBLTMODE 4

#నిర్వచించు STRETCH_ANDSCANS BLACKONWHITE
#నిర్వచించు STRETCH_ORSCANS WHITEONBLACK
#నిర్వచించు STRETCH_DELETESCANS COLORONCOLOR
#నిర్వచించు STRETCH_HALFTONE HALFTONE

#నిర్వచించు ALTERNATE 1
#నిర్వచించు WINDING 2
#నిర్వచించు POLYFILL_చివరి 2

#నిర్వచించు LAYOUT_RTL 0x00000001
#నిర్వచించు LAYOUT_BTT 0x00000002
#నిర్వచించు LAYOUT_VBH 0x00000004
#నిర్వచించు LAYOUT_ORIENTATIONMASK (LAYOUT_RTL | LAYOUT_BTT | LAYOUT_VBH)
#నిర్వచించు LAYOUT_BITMAPORIENTATIONPRESERVED 0x00000008

#నిర్వచించు TA_NOUPDATECP 0
#నిర్వచించు TA_UPDATECP 1

#నిర్వచించు TA_ఎడమ 0
#నిర్వచించు TA_కుడి 2
#నిర్వచించు TA_CENTER 6

#నిర్వచించు TA_శిఖరం 0
#నిర్వచించు TA_BOTTOM 8
#నిర్వచించు TA_BASELINE 24
#నిర్వచించు TA_RTLREADING 256
#నిర్వచించు TA_ముసుగు (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)

#నిర్వచించు VTA_BASELINE TA_BASELINE
#నిర్వచించు VTA_ఎడమ TA_BOTTOM
#నిర్వచించు VTA_కుడి TA_శిఖరం
#నిర్వచించు VTA_CENTER TA_CENTER
#నిర్వచించు VTA_BOTTOM TA_కుడి
#నిర్వచించు VTA_శిఖరం TA_ఎడమ

#నిర్వచించు ETO_OPAQUE 0x0002
#నిర్వచించు ETO_CLIPPED 0x0004
#నిర్వచించు ETO_GLYPH_సూచీ 0x0010
#నిర్వచించు ETO_RTLREADING 0x0080
#నిర్వచించు ETO_NUMERICSLOCAL 0x0400
#నిర్వచించు ETO_NUMERICSLATIN 0x0800
#నిర్వచించు ETO_IGNORELANGUAGE 0x1000
#నిర్వచించు ETO_PDY 0x2000

#నిర్వచించు ASPECT_FILTERING 0x0001

#నిర్వచించు DCB_RESET 0x0001
#నిర్వచించు DCB_ACCUMULATE 0x0002
#నిర్వచించు DCB_DIRTY DCB_ACCUMULATE
#నిర్వచించు DCB_సమితి (DCB_RESET | DCB_ACCUMULATE)
#నిర్వచించు DCB_ENABLE 0x0004
#నిర్వచించు DCB_DISABLE 0x0008

#నిర్వచితం_కాకపోతే NOMETAFILE

#నిర్వచించు META_SETBKCOLOR 0x0201
#నిర్వచించు META_SETBKMODE 0x0102
#నిర్వచించు META_SETMAPMODE 0x0103
#నిర్వచించు META_SETROP2 0x0104
#నిర్వచించు META_SETRELABS 0x0105
#నిర్వచించు META_SETPOLYFILLMODE 0x0106
#నిర్వచించు META_SETSTRETCHBLTMODE 0x0107
#నిర్వచించు META_SETTEXTCHAREXTRA 0x0108
#నిర్వచించు META_SETTEXTCOLOR 0x0209
#నిర్వచించు META_SETTEXTJUSTIFICATION 0x020A
#నిర్వచించు META_SETWINDOWORG 0x020B
#నిర్వచించు META_SETWINDOWEXT 0x020C
#నిర్వచించు META_SETVIEWPORTORG 0x020D
#నిర్వచించు META_SETVIEWPORTEXT 0x020E
#నిర్వచించు META_OFFSETWINDOWORG 0x020F
#నిర్వచించు META_SCALEWINDOWEXT 0x0410
#నిర్వచించు META_OFFSETVIEWPORTORG 0x0211
#నిర్వచించు META_SCALEVIEWPORTEXT 0x0412
#నిర్వచించు META_LINETO 0x0213
#నిర్వచించు META_MOVETO 0x0214
#నిర్వచించు META_EXCLUDECLIPRECT 0x0415
#నిర్వచించు META_INTERSECTCLIPRECT 0x0416
#నిర్వచించు META_ARC 0x0817
#నిర్వచించు META_ELLIPSE 0x0418
#నిర్వచించు META_FLOODFILL 0x0419
#నిర్వచించు META_PIE 0x081A
#నిర్వచించు META_RECTANGLE 0x041B
#నిర్వచించు META_ROUNDRECT 0x061C
#నిర్వచించు META_PATBLT 0x061D
#నిర్వచించు META_SAVEDC 0x001E
#నిర్వచించు META_SETPIXEL 0x041F
#నిర్వచించు META_OFFSETCLIPRGN 0x0220
#నిర్వచించు META_TEXTOUT 0x0521
#నిర్వచించు META_BITBLT 0x0922
#నిర్వచించు META_STRETCHBLT 0x0B23
#నిర్వచించు META_POLYGON 0x0324
#నిర్వచించు META_POLYLINE 0x0325
#నిర్వచించు META_ESCAPE 0x0626
#నిర్వచించు META_RESTOREDC 0x0127
#నిర్వచించు META_FILLREGION 0x0228
#నిర్వచించు META_FRAMEREGION 0x0429
#నిర్వచించు META_INVERTREGION 0x012A
#నిర్వచించు META_PAINTREGION 0x012B
#నిర్వచించు META_SELECTCLIPREGION 0x012C
#నిర్వచించు META_SELECTOBJECT 0x012D
#నిర్వచించు META_SETTEXTALIGN 0x012E
#నిర్వచించు META_CHORD 0x0830
#నిర్వచించు META_SETMAPPERFLAGS 0x0231
#నిర్వచించు META_EXTTEXTOUT 0x0a32
#నిర్వచించు META_SETDIBTODEV 0x0d33
#నిర్వచించు META_SELECTPALETTE 0x0234
#నిర్వచించు META_REALIZEPALETTE 0x0035
#నిర్వచించు META_ANIMATEPALETTE 0x0436
#నిర్వచించు META_SETPALENTRIES 0x0037
#నిర్వచించు META_POLYPOLYGON 0x0538
#నిర్వచించు META_RESIZEPALETTE 0x0139
#నిర్వచించు META_DIBBITBLT 0x0940
#నిర్వచించు META_DIBSTRETCHBLT 0x0b41
#నిర్వచించు META_DIBCREATEPATTERNBRUSH 0x0142
#నిర్వచించు META_STRETCHDIB 0x0f43
#నిర్వచించు META_EXTFLOODFILL 0x0548
#నిర్వచించు META_SETLAYOUT 0x0149
#నిర్వచించు META_DELETEOBJECT 0x01f0
#నిర్వచించు META_CREATEPALETTE 0x00f7
#నిర్వచించు META_CREATEPATTERNBRUSH 0x01F9
#నిర్వచించు META_CREATEPENINDIRECT 0x02FA
#నిర్వచించు META_CREATEFONTINDIRECT 0x02FB
#నిర్వచించు META_CREATEBRUSHINDIRECT 0x02FC
#నిర్వచించు META_CREATEREGION 0x06FF

  రకనిర్వచనం నిర్మాణం _DRAWPATRECT {
    బిందువు_3 ptPosition;
    బిందువు_3 pt_కొలత;
    మాట_3 wStyle;
    మాట_3 w_నమూనా;
  } DRAWPATRECT,*PDRAWPATRECT;
#అయితే_ముగింపు

#నిర్వచించు NEWFRAME 1
#నిర్వచించు ABORTDOC 2
#నిర్వచించు NEXTBAND 3
#నిర్వచించు SETCOLORTABLE 4
#నిర్వచించు GETCOLORTABLE 5
#నిర్వచించు FLUSHOUTPUT 6
#నిర్వచించు DRAFTMODE 7
#నిర్వచించు QUERYESCSUPPORT 8
#నిర్వచించు SETABORTPROC 9
#నిర్వచించు STARTDOC 10
#నిర్వచించు ENDDOC 11
#నిర్వచించు GETPHYSPAGESIZE 12
#నిర్వచించు GETPRINTINGOFFSET 13
#నిర్వచించు GETSCALINGFACTOR 14
#నిర్వచించు MFCOMMENT 15
#నిర్వచించు GETPENWIDTH 16
#నిర్వచించు SETCOPYCOUNT 17
#నిర్వచించు SELECTPAPERSOURCE 18
#నిర్వచించు DEVICEDATA 19
#నిర్వచించు PASSTHROUGH 19
#నిర్వచించు GETTECHNOLGY 20
#నిర్వచించు GETTECHNOLOGY 20
#నిర్వచించు SETLINECAP 21
#నిర్వచించు SETLINEJOIN 22
#నిర్వచించు SETMITERLIMIT 23
#నిర్వచించు BANDINFO 24
#నిర్వచించు DRAWPATTERNRECT 25
#నిర్వచించు GETVECTORPENSIZE 26
#నిర్వచించు GETVECTORBRUSHSIZE 27
#నిర్వచించు ENABLEDUPLEX 28
#నిర్వచించు GETSETPAPERBINS 29
#నిర్వచించు GETSETPRINTORIENT 30
#నిర్వచించు ENUMPAPERBINS 31
#నిర్వచించు SETDIBSCALING 32
#నిర్వచించు EPSPRINTING 33
#నిర్వచించు ENUMPAPERMETRICS 34
#నిర్వచించు GETSETPAPERMETRICS 35
#నిర్వచించు POSTSCRIPT_దత్తాంశం 37
#నిర్వచించు POSTSCRIPT_IGNORE 38
#నిర్వచించు MOUSETRAILS 39
#నిర్వచించు GETDEVICEUNITS 42

#నిర్వచించు GETEXTENDEDTEXTMETRICS 256
#నిర్వచించు GETEXTENTTABLE 257
#నిర్వచించు GETPAIRKERNTABLE 258
#నిర్వచించు GETTRACKKERNTABLE 259
#నిర్వచించు EXTTEXTOUT 512
#నిర్వచించు GETFACENAME 513
#నిర్వచించు DOWNLOADFACE 514
#నిర్వచించు ENABLERELATIVEWIDTHS 768
#నిర్వచించు ENABLEPAIRKERNING 769
#నిర్వచించు SETKERNTRACK 770
#నిర్వచించు SETALLJUSTVALUES 771
#నిర్వచించు SETCHARSET 772

#నిర్వచించు STRETCHBLT 2048
#నిర్వచించు METAFILE_DRIVER 2049
#నిర్వచించు GETSETSCREENPARAMS 3072
#నిర్వచించు QUERYDIBSUPPORT 3073
#నిర్వచించు BEGIN_మార్గం 4096
#నిర్వచించు CLIP_గమ్యం_మార్గం 4097
#నిర్వచించు చివర_మార్గం 4098
#నిర్వచించు EXT_DEVICE_CAPS 4099
#నిర్వచించు RESTORE_CTM 4100
#నిర్వచించు SAVE_CTM 4101
#నిర్వచించు సమితి_ARC_DIRECTION 4102
#నిర్వచించు సమితి_BACKGROUND_COLOR 4103
#నిర్వచించు సమితి_POLY_బహుళకం 4104
#నిర్వచించు సమితి_SCREEN_ANGLE 4105
#నిర్వచించు సమితి_విస్తరణ 4106
#నిర్వచించు TRANSFORM_CTM 4107
#నిర్వచించు సమితి_CLIP_BOX 4108
#నిర్వచించు సమితి_BOUNDS 4109
#నిర్వచించు సమితి_MIRROR_బహుళకం 4110
#నిర్వచించు OPENCHANNEL 4110
#నిర్వచించు DOWNLOADHEADER 4111
#నిర్వచించు CLOSECHANNEL 4112
#నిర్వచించు POSTSCRIPT_PASSTHROUGH 4115
#నిర్వచించు ENCAPSULATED_POSTSCRIPT 4116

#నిర్వచించు POSTSCRIPT_IDENTIFY 4117
#నిర్వచించు POSTSCRIPT_INJECTION 4118

#నిర్వచించు CHECKJPEGFORMAT 4119
#నిర్వచించు CHECKPNGFORMAT 4120

#నిర్వచించు GET_PS_FEATURESETTING 4121

#నిర్వచించు SPCLPASSTHROUGH2 4568

#నిర్వచించు PSIDENT_GDICENTRIC 0
#నిర్వచించు PSIDENT_PSCENTRIC 1

  రకనిర్వచనం నిర్మాణం _PSINJECTDATA {
    DWORD దత్తాంశం_బైట్లు;
    మాట_3 Injection_బిందువు;
    మాట_3 పుట_సంఖ్య;
  } PSINJECTDATA,*PPSINJECTDATA;

#నిర్వచించు PSINJECT_BEGINSTREAM 1
#నిర్వచించు PSINJECT_PSADOBE 2
#నిర్వచించు PSINJECT_PAGESATEND 3
#నిర్వచించు PSINJECT_పుటలు 4

#నిర్వచించు PSINJECT_DOCNEEDEDRES 5
#నిర్వచించు PSINJECT_DOCSUPPLIEDRES 6
#నిర్వచించు PSINJECT_PAGEORDER 7
#నిర్వచించు PSINJECT_ORIENTATION 8
#నిర్వచించు PSINJECT_BOUNDINGBOX 9
#నిర్వచించు PSINJECT_DOCUMENTPROCESSCOLORS 10

#నిర్వచించు PSINJECT_COMMENTS 11
#నిర్వచించు PSINJECT_BEGINDEFAULTS 12
#నిర్వచించు PSINJECT_ENDDEFAULTS 13
#నిర్వచించు PSINJECT_BEGINPROLOG 14
#నిర్వచించు PSINJECT_ENDPROLOG 15
#నిర్వచించు PSINJECT_BEGINSETUP 16
#నిర్వచించు PSINJECT_ENDSETUP 17
#నిర్వచించు PSINJECT_TRAILER 18
#నిర్వచించు PSINJECT_EOF 19
#నిర్వచించు PSINJECT_ENDSTREAM 20
#నిర్వచించు PSINJECT_DOCUMENTPROCESSCOLORSATEND 21

#నిర్వచించు PSINJECT_PAGENUMBER 100
#నిర్వచించు PSINJECT_BEGINPAGESETUP 101
#నిర్వచించు PSINJECT_ENDPAGESETUP 102
#నిర్వచించు PSINJECT_PAGETRAILER 103
#నిర్వచించు PSINJECT_PLATECOLOR 104

#నిర్వచించు PSINJECT_SHOWPAGE 105
#నిర్వచించు PSINJECT_PAGEBBOX 106
#నిర్వచించు PSINJECT_ENDPAGECOMMENTS 107

#నిర్వచించు PSINJECT_VMSAVE 200
#నిర్వచించు PSINJECT_VMRESTORE 201

#నిర్వచించు FEATURESETTING_NUP 0
#నిర్వచించు FEATURESETTING_OUTPUT 1
#నిర్వచించు FEATURESETTING_PSLEVEL 2
#నిర్వచించు FEATURESETTING_CUSTPAPER 3
#నిర్వచించు FEATURESETTING_MIRROR 4
#నిర్వచించు FEATURESETTING_NEGATIVE 5
#నిర్వచించు FEATURESETTING_PROTOCOL 6

#నిర్వచించు FEATURESETTING_వ్యక్తిగత_BEGIN 0x1000
#నిర్వచించు FEATURESETTING_వ్యక్తిగత_చివర 0x1FFF

  రకనిర్వచనం నిర్మాణం _PSFEATURE_OUTPUT {
    WINBOOL b_పుట_Independent;
    WINBOOL b_సమితి_పుట_Device;
  } PSFEATURE_OUTPUT,*PPSFEATURE_OUTPUT;

  రకనిర్వచనం నిర్మాణం _PSFEATURE_CUSTPAPER {
    LONG lOrientation;
    LONG l_వెడల్పు;
    LONG l_ఎత్తు;
    LONG l_వెడల్పు_స్థానభ్రంశం;
    LONG l_ఎత్తు_స్థానభ్రంశం;
  } PSFEATURE_CUSTPAPER,*PPSFEATURE_CUSTPAPER;

#నిర్వచించు PSPROTOCOL_ASCII 0
#నిర్వచించు PSPROTOCOL_BCP 1
#నిర్వచించు PSPROTOCOL_TBCP 2
#నిర్వచించు PSPROTOCOL_ద్విమాన 3

#నిర్వచించు QDI_SETDIBITS 1
#నిర్వచించు QDI_GETDIBITS 2
#నిర్వచించు QDI_DIBTOSCREEN 4
#నిర్వచించు QDI_STRETCHDIB 8

#నిర్వచించు SP_NOTREPORTED 0x4000
#నిర్వచించు SP_ERROR (-1)
#నిర్వచించు SP_APPABORT (-2)
#నిర్వచించు SP_USERABORT (-3)
#నిర్వచించు SP_OUTOFDISK (-4)
#నిర్వచించు SP_OUTOFMEMORY (-5)

#నిర్వచించు PR_JOBSTATUS 0x0000

#నిర్వచించు OBJ_PEN 1
#నిర్వచించు OBJ_BRUSH 2
#నిర్వచించు OBJ_DC 3
#నిర్వచించు OBJ_METADC 4
#నిర్వచించు OBJ_PAL 5
#నిర్వచించు OBJ_FONT 6
#నిర్వచించు OBJ_BITMAP 7
#నిర్వచించు OBJ_REGION 8
#నిర్వచించు OBJ_METAFILE 9
#నిర్వచించు OBJ_MEMDC 10
#నిర్వచించు OBJ_EXTPEN 11
#నిర్వచించు OBJ_ENHMETADC 12
#నిర్వచించు OBJ_ENHMETAFILE 13
#నిర్వచించు OBJ_COLORSPACE 14

#నిర్వచించు MWT_తటస్థం 1
#నిర్వచించు MWT_LEFTMULTIPLY 2
#నిర్వచించు MWT_RIGHTMULTIPLY 3

#నిర్వచించు MWT_MIN MWT_తటస్థం
#నిర్వచించు MWT_MAX MWT_RIGHTMULTIPLY

#నిర్వచించు _XFORM_
  రకనిర్వచనం నిర్మాణం ట్యాగ్_XFORM {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
  } XFORM,*PXFORM,*LPXFORM;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_BITMAP {
    LONG bmType;
    LONG bm_వెడల్పు;
    LONG bm_ఎత్తు;
    LONG bm_వెడల్పు_బైట్లు;
    మాట_3 bmPlanes;
    మాట_3 bm_బిట్లు_Pixel;
    LPVOID bm_బిట్లు;
  } BITMAP,*PBITMAP,*NPBITMAP,*LPBITMAP;

#అన్తర్భావ <pshpack1.h>
  రకనిర్వచనం నిర్మాణం ట్యాగ్_RGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
  } RGBTRIPLE;
#అన్తర్భావ <poppack.h>

  రకనిర్వచనం నిర్మాణం ట్యాగ్_RGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
  } RGBQUAD;
  రకనిర్వచనం RGBQUAD *LPRGBQUAD;

#నిర్వచించు CS_ENABLE 0x00000001L
#నిర్వచించు CS_DISABLE 0x00000002L
#నిర్వచించు CS_DELETE_TRANSFORM 0x00000003L

//!__TINYC__: #define LCS_SIGNATURE 'PSOC'
//!__TINYC__: #define LCS_sRGB 'sRGB'
//!__TINYC__: #define LCS_WINDOWS_COLOR_SPACE 'Win '

  రకనిర్వచనం LONG LCSCSTYPE;
#నిర్వచించు LCS_CALIBRATED_RGB 0x00000000L

  రకనిర్వచనం LONG LCSGAMUTMATCH;
#నిర్వచించు LCS_GM_BUSINESS 0x00000001L
#నిర్వచించు LCS_GM_GRAPHICS 0x00000002L
#నిర్వచించు LCS_GM_IMAGES 0x00000004L
#నిర్వచించు LCS_GM_ABS_COLORIMETRIC 0x00000008L

#నిర్వచించు CM_బహిర్గతం_యొక్క_GAMUT 255
#నిర్వచించు CM_లోపల_GAMUT 0

#నిర్వచించు ICM_ADDPROFILE 1
#నిర్వచించు ICM_DELETEPROFILE 2
#నిర్వచించు ICM_QUERYPROFILE 3
#నిర్వచించు ICM_SETDEFAULTPROFILE 4
#నిర్వచించు ICM_REGISTERICMATCHER 5
#నిర్వచించు ICM_UNREGISTERICMATCHER 6
#నిర్వచించు ICM_QUERYMATCH 7

#నిర్వచించు GetKValue(cmyk) ((BYTE)(cmyk))
#నిర్వచించు GetYValue(cmyk) ((BYTE)((cmyk)>> 8))
#నిర్వచించు GetMValue(cmyk) ((BYTE)((cmyk)>>16))
#నిర్వచించు GetCValue(cmyk) ((BYTE)((cmyk)>>24))

#నిర్వచించు CMYK(c,m,y,k) ((COLORREF)((((BYTE)(k)|((మాట_3)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

  రకనిర్వచనం దీర్ఘ FXPT16DOT16,*LPFXPT16DOT16;
  రకనిర్వచనం దీర్ఘ FXPT2DOT30,*LPFXPT2DOT30;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
  } CIEXYZ;
  రకనిర్వచనం CIEXYZ *LPCIEXYZ;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ICEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
  } CIEXYZTRIPLE;

  రకనిర్వచనం CIEXYZTRIPLE *LPCIEXYZTRIPLE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LOGCOLORSPACEA {
    DWORD lcsSignature;
    DWORD lcs_సంస్కరణ;
    DWORD lcs_కొలత;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    CHAR lcsFilename[MAX_మార్గం];
  } LOGCOLORSPACEA,*LPLOGCOLORSPACEA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LOGCOLORSPACEW {
    DWORD lcsSignature;
    DWORD lcs_సంస్కరణ;
    DWORD lcs_కొలత;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    WCHAR lcsFilename[MAX_మార్గం];
  } LOGCOLORSPACEW,*LPLOGCOLORSPACEW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం LOGCOLORSPACEW LOGCOLORSPACE;
  రకనిర్వచనం LPLOGCOLORSPACEW LPLOGCOLORSPACE;
#లేకపోతే
  రకనిర్వచనం LOGCOLORSPACEA LOGCOLORSPACE;
  రకనిర్వచనం LPLOGCOLORSPACEA LPLOGCOLORSPACE;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_BITMAPCOREHEADER {
    DWORD bc_కొలత;
    మాట_3 bc_వెడల్పు;
    మాట_3 bc_ఎత్తు;
    మాట_3 bcPlanes;
    మాట_3 bc_బిట్టు_లెక్క;
  } BITMAPCOREHEADER,*LPBITMAPCOREHEADER,*PBITMAPCOREHEADER;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_BITMAPINFOHEADER {
    DWORD bi_కొలత;
    LONG bi_వెడల్పు;
    LONG bi_ఎత్తు;
    మాట_3 biPlanes;
    మాట_3 bi_బిట్టు_లెక్క;
    DWORD biCompression;
    DWORD bi_కొలత_Image;
    LONG bi_XPels_చొప్పున_Meter;
    LONG bi_YPels_చొప్పున_Meter;
    DWORD bi_Clr_వాడిన;
    DWORD biClrImportant;
  } BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

  రకనిర్వచనం నిర్మాణం {
    DWORD b_V4_కొలత;
    LONG b_V4_వెడల్పు;
    LONG b_V4_ఎత్తు;
    మాట_3 bV4Planes;
    మాట_3 b_V4_బిట్టు_లెక్క;
    DWORD bV4V4Compression;
    DWORD b_V4_కొలత_Image;
    LONG b_V4_XPels_చొప్పున_Meter;
    LONG b_V4_YPels_చొప్పున_Meter;
    DWORD b_V4_Clr_వాడిన;
    DWORD bV4ClrImportant;
    DWORD b_V4_Red_ముసుగు;
    DWORD b_V4_Green_ముసుగు;
    DWORD b_V4_Blue_ముసుగు;
    DWORD b_V4_Alpha_ముసుగు;
    DWORD bV4CSType;
    CIEXYZTRIPLE bV4Endpoints;
    DWORD bV4GammaRed;
    DWORD bV4GammaGreen;
    DWORD bV4GammaBlue;
  } BITMAPV4_శీర్షిక,*LPBITMAPV4_శీర్షిక,*PBITMAPV4_శీర్షిక;

  రకనిర్వచనం నిర్మాణం {
    DWORD b_V5_కొలత;
    LONG b_V5_వెడల్పు;
    LONG b_V5_ఎత్తు;
    మాట_3 bV5Planes;
    మాట_3 b_V5_బిట్టు_లెక్క;
    DWORD bV5Compression;
    DWORD b_V5_కొలత_Image;
    LONG b_V5_XPels_చొప్పున_Meter;
    LONG b_V5_YPels_చొప్పున_Meter;
    DWORD b_V5_Clr_వాడిన;
    DWORD bV5ClrImportant;
    DWORD b_V5_Red_ముసుగు;
    DWORD b_V5_Green_ముసుగు;
    DWORD b_V5_Blue_ముసుగు;
    DWORD b_V5_Alpha_ముసుగు;
    DWORD bV5CSType;
    CIEXYZTRIPLE bV5Endpoints;
    DWORD bV5GammaRed;
    DWORD bV5GammaGreen;
    DWORD bV5GammaBlue;
    DWORD bV5Intent;
    DWORD b_V5_Profile_దత్తాంశం;
    DWORD b_V5_Profile_కొలత;
    DWORD bV5Reserved;
  } BITMAPV5_శీర్షిక,*LPBITMAPV5_శీర్షిక,*PBITMAPV5_శీర్షిక;

//!__TINYC__: #define PROFILE_LINKED 'LINK'
//!__TINYC__: #define PROFILE_EMBEDDED 'MBED'

#నిర్వచించు BI_RGB 0L
#నిర్వచించు BI_RLE8 1L
#నిర్వచించు BI_RLE4 2L
#నిర్వచించు BI_BITFIELDS 3L
#నిర్వచించు BI_JPEG 4L
#నిర్వచించు BI_PNG 5L

  రకనిర్వచనం నిర్మాణం ట్యాగ్_BITMAPINFO {
    BITMAPINFOHEADER bmi_శీర్షిక;
    RGBQUAD bmiColors[1];
  } BITMAPINFO,*LPBITMAPINFO,*PBITMAPINFO;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_BITMAPCOREINFO {
    BITMAPCOREHEADER bmci_శీర్షిక;
    RGBTRIPLE bmciColors[1];
  } BITMAPCOREINFO,*LPBITMAPCOREINFO,*PBITMAPCOREINFO;

#అన్తర్భావ <pshpack2.h>
  రకనిర్వచనం నిర్మాణం ట్యాగ్_BITMAPFILEHEADER {
    మాట_3 bfType;
    DWORD bf_కొలత;
    మాట_3 bfReserved1;
    మాట_3 bfReserved2;
    DWORD bf_Off_బిట్లు;
  } BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#అన్తర్భావ <poppack.h>

#నిర్వచించు MAKEPOINTS(l) (*((POINTS *)&(l)))

#నిర్వచితం_కాకపోతే NOFONTSIG
  రకనిర్వచనం నిర్మాణం ట్యాగ్_FONTSIGNATURE {
    DWORD fsUsb[4];
    DWORD fsCsb[2];
  } FONTSIGNATURE,*PFONTSIGNATURE,*LPFONTSIGNATURE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_CHARSETINFO {
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
  } CHARSETINFO,*PCHARSETINFO,*NPCHARSETINFO,*LPCHARSETINFO;

#నిర్వచించు TCI_SRCCHARSET 1
#నిర్వచించు TCI_SRCCODEPAGE 2
#నిర్వచించు TCI_SRCFONTSIG 3
#నిర్వచించు TCI_SRCLOCALE 0x1000

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LOCALESIGNATURE {
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
  } LOCALESIGNATURE,*PLOCALESIGNATURE,*LPLOCALESIGNATURE;
#అయితే_ముగింపు


#నిర్వచితం_కాకపోతే NOMETAFILE
  రకనిర్వచనం నిర్మాణం ట్యాగ్_HANDLETABLE {
    HGDIOBJ objectHandle[1];
  } HANDLETABLE,*PHANDLETABLE,*LPHANDLETABLE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_METARECORD {
    DWORD rd_కొలత;
    మాట_3 rdFunction;
    మాట_3 rdParm[1];
  } METARECORD;
  రకనిర్వచనం నిర్మాణం ట్యాగ్_METARECORD UNALIGNED *PMETARECORD;
  రకనిర్వచనం నిర్మాణం ట్యాగ్_METARECORD UNALIGNED *LPMETARECORD;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_METAFILEPICT {
    LONG mm;
    LONG xExt;
    LONG yExt;
    HMETAFILE hMF;
  } METAFILEPICT,*LPMETAFILEPICT;

#అన్తర్భావ <pshpack2.h>
  రకనిర్వచనం నిర్మాణం ట్యాగ్_METAHEADER {
    మాట_3 mtType;
    మాట_3 mt_శీర్షిక_కొలత;
    మాట_3 mt_సంస్కరణ;
    DWORD mt_కొలత;
    మాట_3 mtNoObjects;
    DWORD mt_Max_రికార్డు;
    మాట_3 mtNoParameters;
  } METAHEADER;
  రకనిర్వచనం నిర్మాణం ట్యాగ్_METAHEADER UNALIGNED *PMETAHEADER;
  రకనిర్వచనం నిర్మాణం ట్యాగ్_METAHEADER UNALIGNED *LPMETAHEADER;

#అన్తర్భావ <poppack.h>

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENHMETARECORD {
    DWORD iType;
    DWORD n_కొలత;
    DWORD dParm[1];
  } ENHMETARECORD,*PENHMETARECORD,*LPENHMETARECORD;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENHMETAHEADER {
    DWORD iType;
    DWORD n_కొలత;
    RECTL rclBounds;
    RECTL rcl_చట్రం;
    DWORD dSignature;
    DWORD n_సంస్కరణ;
    DWORD n_బైట్లు;
    DWORD n_రికార్డులు;
    మాట_3 nHandles;
    మాట_3 sReserved;
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
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOTEXTMETRIC
#నిర్వచించు TMPF_FIXED_PITCH 0x01
#నిర్వచించు TMPF_సదిశ 0x02
#నిర్వచించు TMPF_DEVICE 0x08
#నిర్వచించు TMPF_TRUETYPE 0x04

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం WCHAR BCHAR;
#లేకపోతే
  రకనిర్వచనం BYTE BCHAR;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _TEXTMETRIC_DEFINED
#నిర్వచించు _TEXTMETRIC_DEFINED
  రకనిర్వచనం నిర్మాణం ట్యాగ్_TEXTMETRICA {
    LONG tm_ఎత్తు;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_అంతర్గత_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_వెడల్పు;
    LONG tm_Max_Char_వెడల్పు;
    LONG tm_బరువు;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_మొదటి_Char;
    BYTE tm_చివరి_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_బహిర్గతం;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_సమితి;
  } TEXTMETRICA,*PTEXTMETRICA,*NPTEXTMETRICA,*LPTEXTMETRICA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_TEXTMETRICW {
    LONG tm_ఎత్తు;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_అంతర్గత_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_వెడల్పు;
    LONG tm_Max_Char_వెడల్పు;
    LONG tm_బరువు;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_మొదటి_Char;
    WCHAR tm_చివరి_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_బహిర్గతం;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_సమితి;
  } TEXTMETRICW,*PTEXTMETRICW,*NPTEXTMETRICW,*LPTEXTMETRICW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం TEXTMETRICW TEXTMETRIC;
  రకనిర్వచనం PTEXTMETRICW PTEXTMETRIC;
  రకనిర్వచనం NPTEXTMETRICW NPTEXTMETRIC;
  రకనిర్వచనం LPTEXTMETRICW LPTEXTMETRIC;
#లేకపోతే
  రకనిర్వచనం TEXTMETRICA TEXTMETRIC;
  రకనిర్వచనం PTEXTMETRICA PTEXTMETRIC;
  రకనిర్వచనం NPTEXTMETRICA NPTEXTMETRIC;
  రకనిర్వచనం LPTEXTMETRICA LPTEXTMETRIC;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచించు NTM_REGULAR 0x00000040L
#నిర్వచించు NTM_BOLD 0x00000020L
#నిర్వచించు NTM_ITALIC 0x00000001L

#నిర్వచించు NTM_NONNEGATIVE_AC 0x00010000
#నిర్వచించు NTM_PS_OPENTYPE 0x00020000
#నిర్వచించు NTM_TT_OPENTYPE 0x00040000
#నిర్వచించు NTM_MULTIPLEMASTER 0x00080000
#నిర్వచించు NTM_TYPE1 0x00100000
#నిర్వచించు NTM_DSIG 0x00200000

#అన్తర్భావ <pshpack4.h>
  రకనిర్వచనం నిర్మాణం ట్యాగ్_NEWTEXTMETRICA {
    LONG tm_ఎత్తు;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_అంతర్గత_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_వెడల్పు;
    LONG tm_Max_Char_వెడల్పు;
    LONG tm_బరువు;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_మొదటి_Char;
    BYTE tm_చివరి_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_బహిర్గతం;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_సమితి;
    DWORD ntmFlags;
    UINT ntm_కొలత_EM;
    UINT ntm_Cell_ఎత్తు;
    UINT ntm_Avg_వెడల్పు;
  } NEWTEXTMETRICA,*PNEWTEXTMETRICA,*NPNEWTEXTMETRICA,*LPNEWTEXTMETRICA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_NEWTEXTMETRICW {
    LONG tm_ఎత్తు;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_అంతర్గత_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_వెడల్పు;
    LONG tm_Max_Char_వెడల్పు;
    LONG tm_బరువు;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_మొదటి_Char;
    WCHAR tm_చివరి_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_బహిర్గతం;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_సమితి;
    DWORD ntmFlags;
    UINT ntm_కొలత_EM;
    UINT ntm_Cell_ఎత్తు;
    UINT ntm_Avg_వెడల్పు;
  } NEWTEXTMETRICW,*PNEWTEXTMETRICW,*NPNEWTEXTMETRICW,*LPNEWTEXTMETRICW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం NEWTEXTMETRICW NEWTEXTMETRIC;
  రకనిర్వచనం PNEWTEXTMETRICW PNEWTEXTMETRIC;
  రకనిర్వచనం NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
  రకనిర్వచనం LPNEWTEXTMETRICW LPNEWTEXTMETRIC;
#లేకపోతే
  రకనిర్వచనం NEWTEXTMETRICA NEWTEXTMETRIC;
  రకనిర్వచనం PNEWTEXTMETRICA PNEWTEXTMETRIC;
  రకనిర్వచనం NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
  రకనిర్వచనం LPNEWTEXTMETRICA LPNEWTEXTMETRIC;
#అయితే_ముగింపు
#అన్తర్భావ <poppack.h>

  రకనిర్వచనం నిర్మాణం ట్యాగ్_NEWTEXTMETRICEXA {
    NEWTEXTMETRICA ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_NEWTEXTMETRICEXW {
    NEWTEXTMETRICW ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం NEWTEXTMETRICEXW NEWTEXTMETRICEX;
#లేకపోతే
  రకనిర్వచనం NEWTEXTMETRICEXA NEWTEXTMETRICEX;
#అయితే_ముగింపు
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_PELARRAY {
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
  } PELARRAY,*PPELARRAY,*NPPELARRAY,*LPPELARRAY;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LOGBRUSH {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
  } LOGBRUSH,*PLOGBRUSH,*NPLOGBRUSH,*LPLOGBRUSH;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LOGBRUSH32 {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG lbHatch;
  } LOGBRUSH32,*PLOGBRUSH32,*NPLOGBRUSH32,*LPLOGBRUSH32;

  రకనిర్వచనం LOGBRUSH నమూనా_2;
  రకనిర్వచనం నమూనా_2 *PPATTERN;
  రకనిర్వచనం నమూనా_2 *NPPATTERN;
  రకనిర్వచనం నమూనా_2 *LPPATTERN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LOGPEN {
    UINT lopnStyle;
    బిందువు_3 lopn_వెడల్పు;
    COLORREF lopnColor;
  } LOGPEN,*PLOGPEN,*NPLOGPEN,*LPLOGPEN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EXTLOGPEN {
    DWORD elpPenStyle;
    DWORD elp_వెడల్పు;
    UINT elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elp_అంకె_Entries;
    DWORD elp_Style_నమోదు[1];
  } EXTLOGPEN,*PEXTLOGPEN,*NPEXTLOGPEN,*LPEXTLOGPEN;

#నిర్వచితం_కాకపోతే _PALETTEENTRY_DEFINED
#నిర్వచించు _PALETTEENTRY_DEFINED
  రకనిర్వచనం నిర్మాణం ట్యాగ్_PALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
  } PALETTEENTRY,*PPALETTEENTRY,*LPPALETTEENTRY;
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే _LOGPALETTE_DEFINED
#నిర్వచించు _LOGPALETTE_DEFINED

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LOGPALETTE {
    మాట_3 pal_సంస్కరణ;
    మాట_3 pal_అంకె_Entries;
    PALETTEENTRY pal_Pal_నమోదు[1];
  } LOGPALETTE,*PLOGPALETTE,*NPLOGPALETTE,*LPLOGPALETTE;
#అయితే_ముగింపు

#నిర్వచించు LF_FACESIZE 32

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LOGFONTA {
    LONG lf_ఎత్తు;
    LONG lf_వెడల్పు;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_బరువు;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_బహిర్గతం;
    BYTE lf_Char_సమితి;
    BYTE lf_బహిర్గతం_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[LF_FACESIZE];
  } LOGFONTA,*PLOGFONTA,*NPLOGFONTA,*LPLOGFONTA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LOGFONTW {
    LONG lf_ఎత్తు;
    LONG lf_వెడల్పు;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_బరువు;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_బహిర్గతం;
    BYTE lf_Char_సమితి;
    BYTE lf_బహిర్గతం_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[LF_FACESIZE];
  } LOGFONTW,*PLOGFONTW,*NPLOGFONTW,*LPLOGFONTW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం LOGFONTW LOGFONT;
  రకనిర్వచనం PLOGFONTW PLOGFONT;
  రకనిర్వచనం NPLOGFONTW NPLOGFONT;
  రకనిర్వచనం LPLOGFONTW LPLOGFONT;
#లేకపోతే
  రకనిర్వచనం LOGFONTA LOGFONT;
  రకనిర్వచనం PLOGFONTA PLOGFONT;
  రకనిర్వచనం NPLOGFONTA NPLOGFONT;
  రకనిర్వచనం LPLOGFONTA LPLOGFONT;
#అయితే_ముగింపు

#నిర్వచించు LF_FULLFACESIZE 64

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENUMLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_నిండిన_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
  } ENUMLOGFONTA,*LPENUMLOGFONTA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENUMLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_నిండిన_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
  } ENUMLOGFONTW,*LPENUMLOGFONTW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం ENUMLOGFONTW ENUMLOGFONT;
  రకనిర్వచనం LPENUMLOGFONTW LPENUMLOGFONT;
#లేకపోతే
  రకనిర్వచనం ENUMLOGFONTA ENUMLOGFONT;
  రకనిర్వచనం LPENUMLOGFONTA LPENUMLOGFONT;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENUMLOGFONTEXA {
    LOGFONTA elfLogFont;
    BYTE elf_నిండిన_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    BYTE elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXA,*LPENUMLOGFONTEXA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENUMLOGFONTEXW {
    LOGFONTW elfLogFont;
    WCHAR elf_నిండిన_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    WCHAR elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXW,*LPENUMLOGFONTEXW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం ENUMLOGFONTEXW ENUMLOGFONTEX;
  రకనిర్వచనం LPENUMLOGFONTEXW LPENUMLOGFONTEX;
#లేకపోతే
  రకనిర్వచనం ENUMLOGFONTEXA ENUMLOGFONTEX;
  రకనిర్వచనం LPENUMLOGFONTEXA LPENUMLOGFONTEX;
#అయితే_ముగింపు

#నిర్వచించు బహిర్గతం_DEFAULT_PRECIS 0
#నిర్వచించు బహిర్గతం_STRING_PRECIS 1
#నిర్వచించు బహిర్గతం_CHARACTER_PRECIS 2
#నిర్వచించు బహిర్గతం_STROKE_PRECIS 3
#నిర్వచించు బహిర్గతం_TT_PRECIS 4
#నిర్వచించు బహిర్గతం_DEVICE_PRECIS 5
#నిర్వచించు బహిర్గతం_RASTER_PRECIS 6
#నిర్వచించు బహిర్గతం_TT_ONLY_PRECIS 7
#నిర్వచించు బహిర్గతం_OUTLINE_PRECIS 8
#నిర్వచించు బహిర్గతం_SCREEN_OUTLINE_PRECIS 9
#నిర్వచించు బహిర్గతం_PS_ONLY_PRECIS 10

#నిర్వచించు CLIP_DEFAULT_PRECIS 0
#నిర్వచించు CLIP_CHARACTER_PRECIS 1
#నిర్వచించు CLIP_STROKE_PRECIS 2
#నిర్వచించు CLIP_ముసుగు 0xf
#నిర్వచించు CLIP_LH_ANGLES (1<<4)
#నిర్వచించు CLIP_TT_ALWAYS (2<<4)
#నిర్వచించు CLIP_DFA_DISABLE (4<<4)
#నిర్వచించు CLIP_EMBEDDED (8<<4)

#నిర్వచించు DEFAULT_QUALITY 0
#నిర్వచించు DRAFT_QUALITY 1
#నిర్వచించు PROOF_QUALITY 2
#నిర్వచించు NONANTIALIASED_QUALITY 3
#నిర్వచించు ANTIALIASED_QUALITY 4

#నిర్వచించు CLEARTYPE_QUALITY 5
#నిర్వచించు CLEARTYPE_NATURAL_QUALITY 6

#నిర్వచించు DEFAULT_PITCH 0
#నిర్వచించు FIXED_PITCH 1
#నిర్వచించు VARIABLE_PITCH 2
#నిర్వచించు MONO_FONT 8

#నిర్వచించు ANSI_CHARSET 0
#నిర్వచించు DEFAULT_CHARSET 1
#నిర్వచించు చిహ్నం_CHARSET 2
#నిర్వచించు SHIFTJIS_CHARSET 128
#నిర్వచించు HANGEUL_CHARSET 129
#నిర్వచించు HANGUL_CHARSET 129
#నిర్వచించు GB2312_CHARSET 134
#నిర్వచించు CHINESEBIG5_CHARSET 136
#నిర్వచించు OEM_CHARSET 255
#నిర్వచించు JOHAB_CHARSET 130
#నిర్వచించు HEBREW_CHARSET 177
#నిర్వచించు ARABIC_CHARSET 178
#నిర్వచించు GREEK_CHARSET 161
#నిర్వచించు TURKISH_CHARSET 162
#నిర్వచించు VIETNAMESE_CHARSET 163
#నిర్వచించు THAI_CHARSET 222
#నిర్వచించు EASTEUROPE_CHARSET 238
#నిర్వచించు RUSSIAN_CHARSET 204

#నిర్వచించు MAC_CHARSET 77
#నిర్వచించు BALTIC_CHARSET 186

#నిర్వచించు FS_LATIN1 0x00000001L
#నిర్వచించు FS_LATIN2 0x00000002L
#నిర్వచించు FS_CYRILLIC 0x00000004L
#నిర్వచించు FS_GREEK 0x00000008L
#నిర్వచించు FS_TURKISH 0x00000010L
#నిర్వచించు FS_HEBREW 0x00000020L
#నిర్వచించు FS_ARABIC 0x00000040L
#నిర్వచించు FS_BALTIC 0x00000080L
#నిర్వచించు FS_VIETNAMESE 0x00000100L
#నిర్వచించు FS_THAI 0x00010000L
#నిర్వచించు FS_JISJAPAN 0x00020000L
#నిర్వచించు FS_CHINESESIMP 0x00040000L
#నిర్వచించు FS_WANSUNG 0x00080000L
#నిర్వచించు FS_CHINESETRAD 0x00100000L
#నిర్వచించు FS_JOHAB 0x00200000L
#నిర్వచించు FS_చిహ్నం 0x80000000L

#నిర్వచించు FF_DONTCARE (0<<4)
#నిర్వచించు FF_ROMAN (1<<4)

#నిర్వచించు FF_SWISS (2<<4)

#నిర్వచించు FF_MODERN (3<<4)

#నిర్వచించు FF_SCRIPT (4<<4)
#నిర్వచించు FF_DECORATIVE (5<<4)

#నిర్వచించు FW_DONTCARE 0
#నిర్వచించు FW_THIN 100
#నిర్వచించు FW_EXTRALIGHT 200
#నిర్వచించు FW_LIGHT 300
#నిర్వచించు FW_సాధారణ 400
#నిర్వచించు FW_MEDIUM 500
#నిర్వచించు FW_SEMIBOLD 600
#నిర్వచించు FW_BOLD 700
#నిర్వచించు FW_EXTRABOLD 800
#నిర్వచించు FW_HEAVY 900

#నిర్వచించు FW_ULTRALIGHT FW_EXTRALIGHT
#నిర్వచించు FW_REGULAR FW_సాధారణ
#నిర్వచించు FW_DEMIBOLD FW_SEMIBOLD
#నిర్వచించు FW_ULTRABOLD FW_EXTRABOLD
#నిర్వచించు FW_BLACK FW_HEAVY

#నిర్వచించు PANOSE_లెక్క 10
#నిర్వచించు PAN_FAMILYTYPE_సూచీ 0
#నిర్వచించు PAN_SERIFSTYLE_సూచీ 1
#నిర్వచించు PAN_బరువు_సూచీ 2
#నిర్వచించు PAN_PROPORTION_సూచీ 3
#నిర్వచించు PAN_CONTRAST_సూచీ 4
#నిర్వచించు PAN_STROKEVARIATION_సూచీ 5
#నిర్వచించు PAN_ARMSTYLE_సూచీ 6
#నిర్వచించు PAN_LETTERFORM_సూచీ 7
#నిర్వచించు PAN_MIDLINE_సూచీ 8
#నిర్వచించు PAN_XHEIGHT_సూచీ 9

#నిర్వచించు PAN_CULTURE_LATIN 0

  రకనిర్వచనం నిర్మాణం ట్యాగ్_PANOSE {
    BYTE bFamilyType;
    BYTE bSerifStyle;
    BYTE b_బరువు;
    BYTE bProportion;
    BYTE bContrast;
    BYTE bStrokeVariation;
    BYTE bArmStyle;
    BYTE bLetterform;
    BYTE bMidline;
    BYTE bXHeight;
  } PANOSE,*LPPANOSE;

#నిర్వచించు PAN_ANY 0
#నిర్వచించు PAN_NO_FIT 1

#నిర్వచించు PAN_FAMILY_పాఠ్యం_DISPLAY 2
#నిర్వచించు PAN_FAMILY_SCRIPT 3
#నిర్వచించు PAN_FAMILY_DECORATIVE 4
#నిర్వచించు PAN_FAMILY_PICTORIAL 5

#నిర్వచించు PAN_SERIF_COVE 2
#నిర్వచించు PAN_SERIF_OBTUSE_COVE 3
#నిర్వచించు PAN_SERIF_వర్గం_COVE 4
#నిర్వచించు PAN_SERIF_OBTUSE_వర్గం_COVE 5
#నిర్వచించు PAN_SERIF_వర్గం 6
#నిర్వచించు PAN_SERIF_THIN 7
#నిర్వచించు PAN_SERIF_BONE 8
#నిర్వచించు PAN_SERIF_EXAGGERATED 9
#నిర్వచించు PAN_SERIF_TRIANGLE 10
#నిర్వచించు PAN_SERIF_సాధారణ_SANS 11
#నిర్వచించు PAN_SERIF_OBTUSE_SANS 12
#నిర్వచించు PAN_SERIF_PERP_SANS 13
#నిర్వచించు PAN_SERIF_FLARED 14
#నిర్వచించు PAN_SERIF_ROUNDED 15

#నిర్వచించు PAN_బరువు_VERY_LIGHT 2
#నిర్వచించు PAN_బరువు_LIGHT 3
#నిర్వచించు PAN_బరువు_THIN 4
#నిర్వచించు PAN_బరువు_BOOK 5
#నిర్వచించు PAN_బరువు_MEDIUM 6
#నిర్వచించు PAN_బరువు_DEMI 7
#నిర్వచించు PAN_బరువు_BOLD 8
#నిర్వచించు PAN_బరువు_HEAVY 9
#నిర్వచించు PAN_బరువు_BLACK 10
#నిర్వచించు PAN_బరువు_NORD 11

#నిర్వచించు PAN_PROP_OLD_STYLE 2
#నిర్వచించు PAN_PROP_MODERN 3
#నిర్వచించు PAN_PROP_EVEN_వెడల్పు 4
#నిర్వచించు PAN_PROP_EXPANDED 5
#నిర్వచించు PAN_PROP_CONDENSED 6
#నిర్వచించు PAN_PROP_VERY_EXPANDED 7
#నిర్వచించు PAN_PROP_VERY_CONDENSED 8
#నిర్వచించు PAN_PROP_MONOSPACED 9

#నిర్వచించు PAN_CONTRAST_NONE 2
#నిర్వచించు PAN_CONTRAST_VERY_దిగువ 3
#నిర్వచించు PAN_CONTRAST_దిగువ 4
#నిర్వచించు PAN_CONTRAST_MEDIUM_దిగువ 5
#నిర్వచించు PAN_CONTRAST_MEDIUM 6
#నిర్వచించు PAN_CONTRAST_MEDIUM_ఎగువ 7
#నిర్వచించు PAN_CONTRAST_ఎగువ 8
#నిర్వచించు PAN_CONTRAST_VERY_ఎగువ 9

#నిర్వచించు PAN_STROKE_GRADUAL_DIAG 2
#నిర్వచించు PAN_STROKE_GRADUAL_TRAN 3
#నిర్వచించు PAN_STROKE_GRADUAL_VERT 4
#నిర్వచించు PAN_STROKE_GRADUAL_HORZ 5
#నిర్వచించు PAN_STROKE_RAPID_VERT 6
#నిర్వచించు PAN_STROKE_RAPID_HORZ 7
#నిర్వచించు PAN_STROKE_INSTANT_VERT 8

#నిర్వచించు PAN_STRAIGHT_ARMS_HORZ 2
#నిర్వచించు PAN_STRAIGHT_ARMS_WEDGE 3
#నిర్వచించు PAN_STRAIGHT_ARMS_VERT 4
#నిర్వచించు PAN_STRAIGHT_ARMS_SINGLE_SERIF 5
#నిర్వచించు PAN_STRAIGHT_ARMS_DOUBLE_SERIF 6
#నిర్వచించు PAN_BENT_ARMS_HORZ 7
#నిర్వచించు PAN_BENT_ARMS_WEDGE 8
#నిర్వచించు PAN_BENT_ARMS_VERT 9
#నిర్వచించు PAN_BENT_ARMS_SINGLE_SERIF 10
#నిర్వచించు PAN_BENT_ARMS_DOUBLE_SERIF 11

#నిర్వచించు PAN_LETT_సాధారణ_CONTACT 2
#నిర్వచించు PAN_LETT_సాధారణ_WEIGHTED 3
#నిర్వచించు PAN_LETT_సాధారణ_BOXED 4
#నిర్వచించు PAN_LETT_సాధారణ_FLATTENED 5
#నిర్వచించు PAN_LETT_సాధారణ_ROUNDED 6
#నిర్వచించు PAN_LETT_సాధారణ_OFF_CENTER 7
#నిర్వచించు PAN_LETT_సాధారణ_వర్గం 8
#నిర్వచించు PAN_LETT_OBLIQUE_CONTACT 9
#నిర్వచించు PAN_LETT_OBLIQUE_WEIGHTED 10
#నిర్వచించు PAN_LETT_OBLIQUE_BOXED 11
#నిర్వచించు PAN_LETT_OBLIQUE_FLATTENED 12
#నిర్వచించు PAN_LETT_OBLIQUE_ROUNDED 13
#నిర్వచించు PAN_LETT_OBLIQUE_OFF_CENTER 14
#నిర్వచించు PAN_LETT_OBLIQUE_వర్గం 15

#నిర్వచించు PAN_MIDLINE_STANDARD_TRIMMED 2
#నిర్వచించు PAN_MIDLINE_STANDARD_POINTED 3
#నిర్వచించు PAN_MIDLINE_STANDARD_SERIFED 4
#నిర్వచించు PAN_MIDLINE_ఎగువ_TRIMMED 5
#నిర్వచించు PAN_MIDLINE_ఎగువ_POINTED 6
#నిర్వచించు PAN_MIDLINE_ఎగువ_SERIFED 7
#నిర్వచించు PAN_MIDLINE_CONSTANT_TRIMMED 8
#నిర్వచించు PAN_MIDLINE_CONSTANT_POINTED 9
#నిర్వచించు PAN_MIDLINE_CONSTANT_SERIFED 10
#నిర్వచించు PAN_MIDLINE_దిగువ_TRIMMED 11
#నిర్వచించు PAN_MIDLINE_దిగువ_POINTED 12
#నిర్వచించు PAN_MIDLINE_దిగువ_SERIFED 13

#నిర్వచించు PAN_XHEIGHT_CONSTANT_SMALL 2
#నిర్వచించు PAN_XHEIGHT_CONSTANT_STD 3
#నిర్వచించు PAN_XHEIGHT_CONSTANT_LARGE 4
#నిర్వచించు PAN_XHEIGHT_DUCKING_SMALL 5
#నిర్వచించు PAN_XHEIGHT_DUCKING_STD 6
#నిర్వచించు PAN_XHEIGHT_DUCKING_LARGE 7

#నిర్వచించు ELF_VENDOR_కొలత 4

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EXTLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_నిండిన_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    DWORD elf_సంస్కరణ;
    DWORD elf_Style_కొలత;
    DWORD elf_సరిపోలిక;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_కొలత];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTA,*PEXTLOGFONTA,*NPEXTLOGFONTA,*LPEXTLOGFONTA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EXTLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_నిండిన_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    DWORD elf_సంస్కరణ;
    DWORD elf_Style_కొలత;
    DWORD elf_సరిపోలిక;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_కొలత];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTW,*PEXTLOGFONTW,*NPEXTLOGFONTW,*LPEXTLOGFONTW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం EXTLOGFONTW EXTLOGFONT;
  రకనిర్వచనం PEXTLOGFONTW PEXTLOGFONT;
  రకనిర్వచనం NPEXTLOGFONTW NPEXTLOGFONT;
  రకనిర్వచనం LPEXTLOGFONTW LPEXTLOGFONT;
#లేకపోతే
  రకనిర్వచనం EXTLOGFONTA EXTLOGFONT;
  రకనిర్వచనం PEXTLOGFONTA PEXTLOGFONT;
  రకనిర్వచనం NPEXTLOGFONTA NPEXTLOGFONT;
  రకనిర్వచనం LPEXTLOGFONTA LPEXTLOGFONT;
#అయితే_ముగింపు

#నిర్వచించు ELF_సంస్కరణ 0
#నిర్వచించు ELF_CULTURE_LATIN 0

#నిర్వచించు RASTER_FONTTYPE 0x0001
#నిర్వచించు DEVICE_FONTTYPE 0x002
#నిర్వచించు TRUETYPE_FONTTYPE 0x004

#నిర్వచించు RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((మాట_3)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#నిర్వచించు PALETTERGB(r,g,b) (0x02000000 | RGB(r,g,b))
#నిర్వచించు PALETTEINDEX(i) ((COLORREF)(0x01000000 | (DWORD)(మాట_3)(i)))

#నిర్వచించు PC_RESERVED 0x01
#నిర్వచించు PC_EXPLICIT 0x02
#నిర్వచించు PC_NOCOLLAPSE 0x04

#నిర్వచించు GetRValue(rgb) (LOBYTE(rgb))
#నిర్వచించు GetGValue(rgb) (LOBYTE(((మాట_3)(rgb)) >> 8))
#నిర్వచించు GetBValue(rgb) (LOBYTE((rgb)>>16))

#నిర్వచించు TRANSPARENT 1
#నిర్వచించు OPAQUE 2
#నిర్వచించు BKMODE_చివరి 2

#నిర్వచించు GM_COMPATIBLE 1
#నిర్వచించు GM_ADVANCED 2
#నిర్వచించు GM_చివరి 2

#నిర్వచించు PT_CLOSEFIGURE 0x01
#నిర్వచించు PT_LINETO 0x02
#నిర్వచించు PT_BEZIERTO 0x04
#నిర్వచించు PT_MOVETO 0x06

#నిర్వచించు MM_పాఠ్యం 1
#నిర్వచించు MM_LOMETRIC 2
#నిర్వచించు MM_HIMETRIC 3
#నిర్వచించు MM_LOENGLISH 4
#నిర్వచించు MM_HIENGLISH 5
#నిర్వచించు MM_TWIPS 6
#నిర్వచించు MM_ISOTROPIC 7
#నిర్వచించు MM_ANISOTROPIC 8

#నిర్వచించు MM_MIN MM_పాఠ్యం
#నిర్వచించు MM_MAX MM_ANISOTROPIC
#నిర్వచించు MM_MAX_FIXEDSCALE MM_TWIPS

#నిర్వచించు ABSOLUTE 1
#నిర్వచించు RELATIVE 2

#నిర్వచించు WHITE_BRUSH 0
#నిర్వచించు LTGRAY_BRUSH 1
#నిర్వచించు బూడిద_BRUSH 2
#నిర్వచించు DKGRAY_BRUSH 3
#నిర్వచించు BLACK_BRUSH 4
#నిర్వచించు NULL_BRUSH 5
#నిర్వచించు HOLLOW_BRUSH NULL_BRUSH
#నిర్వచించు WHITE_PEN 6
#నిర్వచించు BLACK_PEN 7
#నిర్వచించు NULL_PEN 8
#నిర్వచించు OEM_FIXED_FONT 10
#నిర్వచించు ANSI_FIXED_FONT 11
#నిర్వచించు ANSI_VAR_FONT 12
#నిర్వచించు SYSTEM_FONT 13
#నిర్వచించు DEVICE_DEFAULT_FONT 14
#నిర్వచించు DEFAULT_PALETTE 15
#నిర్వచించు SYSTEM_FIXED_FONT 16

#నిర్వచించు DEFAULT_GUI_FONT 17

#నిర్వచించు DC_BRUSH 18
#నిర్వచించు DC_PEN 19

#నిర్వచించు STOCK_చివరి 19

#నిర్వచించు CLR_INVALID 0xFFFFFFFF

#నిర్వచించు BS_SOLID 0
#నిర్వచించు BS_NULL 1
#నిర్వచించు BS_HOLLOW BS_NULL
#నిర్వచించు BS_HATCHED 2
#నిర్వచించు BS_నమూనా 3
#నిర్వచించు BS_సూచీకృత 4
#నిర్వచించు BS_DIBPATTERN 5
#నిర్వచించు BS_DIBPATTERNPT 6
#నిర్వచించు BS_PATTERN8X8 7
#నిర్వచించు BS_DIBPATTERN8X8 8
#నిర్వచించు BS_MONOPATTERN 9

#నిర్వచించు HS_HORIZONTAL 0
#నిర్వచించు HS_VERTICAL 1
#నిర్వచించు HS_FDIAGONAL 2
#నిర్వచించు HS_BDIAGONAL 3
#నిర్వచించు HS_CROSS 4
#నిర్వచించు HS_DIAGCROSS 5

#నిర్వచించు PS_SOLID 0
#నిర్వచించు PS_DASH 1
#నిర్వచించు PS_DOT 2
#నిర్వచించు PS_DASHDOT 3
#నిర్వచించు PS_DASHDOTDOT 4
#నిర్వచించు PS_NULL 5
#నిర్వచించు PS_INSIDEFRAME 6
#నిర్వచించు PS_USERSTYLE 7
#నిర్వచించు PS_ALTERNATE 8
#నిర్వచించు PS_STYLE_ముసుగు 0x0000000F

#నిర్వచించు PS_ENDCAP_విడత 0x00000000
#నిర్వచించు PS_ENDCAP_వర్గం 0x00000100
#నిర్వచించు PS_ENDCAP_FLAT 0x00000200
#నిర్వచించు PS_ENDCAP_ముసుగు 0x00000F00

#నిర్వచించు PS_JOIN_విడత 0x00000000
#నిర్వచించు PS_JOIN_BEVEL 0x00001000
#నిర్వచించు PS_JOIN_MITER 0x00002000
#నిర్వచించు PS_JOIN_ముసుగు 0x0000F000

#నిర్వచించు PS_COSMETIC 0x00000000
#నిర్వచించు PS_GEOMETRIC 0x00010000
#నిర్వచించు PS_TYPE_ముసుగు 0x000F0000

#నిర్వచించు AD_COUNTERCLOCKWISE 1
#నిర్వచించు AD_CLOCKWISE 2

#నిర్వచించు DRIVERVERSION 0
#నిర్వచించు TECHNOLOGY 2
#నిర్వచించు HORZSIZE 4
#నిర్వచించు VERTSIZE 6
#నిర్వచించు HORZRES 8
#నిర్వచించు VERTRES 10
#నిర్వచించు BITSPIXEL 12
#నిర్వచించు PLANES 14
#నిర్వచించు NUMBRUSHES 16
#నిర్వచించు NUMPENS 18
#నిర్వచించు NUMMARKERS 20
#నిర్వచించు NUMFONTS 22
#నిర్వచించు NUMCOLORS 24
#నిర్వచించు PDEVICESIZE 26
#నిర్వచించు CURVECAPS 28
#నిర్వచించు LINECAPS 30
#నిర్వచించు POLYGONALCAPS 32
#నిర్వచించు TEXTCAPS 34
#నిర్వచించు CLIPCAPS 36
#నిర్వచించు RASTERCAPS 38
#నిర్వచించు ASPECTX 40
#నిర్వచించు ASPECTY 42
#నిర్వచించు ASPECTXY 44

#నిర్వచించు LOGPIXELSX 88
#నిర్వచించు LOGPIXELSY 90

#నిర్వచించు SIZEPALETTE 104
#నిర్వచించు NUMRESERVED 106
#నిర్వచించు COLORRES 108

#నిర్వచించు PHYSICALWIDTH 110
#నిర్వచించు PHYSICALHEIGHT 111
#నిర్వచించు PHYSICALOFFSETX 112
#నిర్వచించు PHYSICALOFFSETY 113
#నిర్వచించు SCALINGFACTORX 114
#నిర్వచించు SCALINGFACTORY 115

#నిర్వచించు VREFRESH 116

#నిర్వచించు DESKTOPVERTRES 117

#నిర్వచించు DESKTOPHORZRES 118

#నిర్వచించు BLTALIGNMENT 119

#నిర్వచించు SHADEBLENDCAPS 120
#నిర్వచించు COLORMGMTCAPS 121

#నిర్వచితం_కాకపోతే NOGDICAPMASKS
#నిర్వచించు DT_PLOTTER 0
#నిర్వచించు DT_RASDISPLAY 1
#నిర్వచించు DT_RASPRINTER 2
#నిర్వచించు DT_RASCAMERA 3
#నిర్వచించు DT_CHARSTREAM 4
#నిర్వచించు DT_METAFILE 5
#నిర్వచించు DT_DISPFILE 6

#నిర్వచించు CC_NONE 0
#నిర్వచించు CC_CIRCLES 1
#నిర్వచించు CC_PIE 2
#నిర్వచించు CC_CHORD 4
#నిర్వచించు CC_ELLIPSES 8
#నిర్వచించు CC_WIDE 16
#నిర్వచించు CC_STYLED 32
#నిర్వచించు CC_WIDESTYLED 64
#నిర్వచించు CC_INTERIORS 128
#నిర్వచించు CC_ROUNDRECT 256

#నిర్వచించు LC_NONE 0
#నిర్వచించు LC_POLYLINE 2
#నిర్వచించు LC_MARKER 4
#నిర్వచించు LC_POLYMARKER 8
#నిర్వచించు LC_WIDE 16
#నిర్వచించు LC_STYLED 32
#నిర్వచించు LC_WIDESTYLED 64
#నిర్వచించు LC_INTERIORS 128

#నిర్వచించు PC_NONE 0
#నిర్వచించు PC_POLYGON 1
#నిర్వచించు PC_RECTANGLE 2
#నిర్వచించు PC_WINDPOLYGON 4
#నిర్వచించు PC_TRAPEZOID 4
#నిర్వచించు PC_SCANLINE 8
#నిర్వచించు PC_WIDE 16
#నిర్వచించు PC_STYLED 32
#నిర్వచించు PC_WIDESTYLED 64
#నిర్వచించు PC_INTERIORS 128
#నిర్వచించు PC_POLYPOLYGON 256
#నిర్వచించు PC_PATHS 512

#నిర్వచించు CP_NONE 0
#నిర్వచించు CP_RECTANGLE 1
#నిర్వచించు CP_REGION 2

#నిర్వచించు TC_OP_CHARACTER 0x00000001
#నిర్వచించు TC_OP_STROKE 0x00000002
#నిర్వచించు TC_CP_STROKE 0x00000004
#నిర్వచించు TC_CR_90 0x00000008
#నిర్వచించు TC_CR_ANY 0x00000010
#నిర్వచించు TC_SF_X_YINDEP 0x00000020
#నిర్వచించు TC_SA_DOUBLE 0x00000040
#నిర్వచించు TC_SA_INTEGER 0x00000080
#నిర్వచించు TC_SA_CONTIN 0x00000100
#నిర్వచించు TC_EA_DOUBLE 0x00000200
#నిర్వచించు TC_IA_ABLE 0x00000400
#నిర్వచించు TC_UA_ABLE 0x00000800
#నిర్వచించు TC_SO_ABLE 0x00001000
#నిర్వచించు TC_RA_ABLE 0x00002000
#నిర్వచించు TC_VA_ABLE 0x00004000
#నిర్వచించు TC_RESERVED 0x00008000
#నిర్వచించు TC_SCROLLBLT 0x00010000
#అయితే_ముగింపు

#నిర్వచించు RC_NONE
#నిర్వచించు RC_BITBLT 1
#నిర్వచించు RC_BANDING 2
#నిర్వచించు RC_SCALING 4
#నిర్వచించు RC_BITMAP64 8
#నిర్వచించు RC_GDI20_OUTPUT 0x0010
#నిర్వచించు RC_GDI20_STATE 0x0020
#నిర్వచించు RC_SAVEBITMAP 0x0040
#నిర్వచించు RC_DI_BITMAP 0x0080
#నిర్వచించు RC_PALETTE 0x0100
#నిర్వచించు RC_DIBTODEV 0x0200
#నిర్వచించు RC_BIGFONT 0x0400
#నిర్వచించు RC_STRETCHBLT 0x0800
#నిర్వచించు RC_FLOODFILL 0x1000
#నిర్వచించు RC_STRETCHDIB 0x2000
#నిర్వచించు RC_OP_DX_OUTPUT 0x4000
#నిర్వచించు RC_DEVBITS 0x8000

#నిర్వచించు SB_NONE 0x00000000
#నిర్వచించు SB_CONST_ALPHA 0x00000001
#నిర్వచించు SB_PIXEL_ALPHA 0x00000002
#నిర్వచించు SB_PREMULT_ALPHA 0x00000004

#నిర్వచించు SB_GRAD_RECT 0x00000010
#నిర్వచించు SB_GRAD_TRI 0x00000020

#నిర్వచించు CM_NONE 0x00000000
#నిర్వచించు CM_DEVICE_ICM 0x00000001
#నిర్వచించు CM_GAMMA_RAMP 0x00000002
#నిర్వచించు CM_CMYK_COLOR 0x00000004

#నిర్వచించు DIB_RGB_COLORS 0
#నిర్వచించు DIB_PAL_COLORS 1

#నిర్వచించు SYSPAL_ERROR 0
#నిర్వచించు SYSPAL_STATIC 1
#నిర్వచించు SYSPAL_NOSTATIC 2
#నిర్వచించు SYSPAL_NOSTATIC256 3

#నిర్వచించు CBM_INIT 0x04L

#నిర్వచించు FLOODFILLBORDER 0
#నిర్వచించు FLOODFILLSURFACE 1

#నిర్వచించు CCHDEVICENAME 32

#నిర్వచించు CCHFORMNAME 32

  రకనిర్వచనం నిర్మాణం _devicemodeA {
    BYTE dmDeviceName[CCHDEVICENAME];
    మాట_3 dm_Spec_సంస్కరణ;
    మాట_3 dm_Driver_సంస్కరణ;
    మాట_3 dm_కొలత;
    మాట_3 dmDriverExtra;
    DWORD dmFields;
    సంఘం {
      నిర్మాణం {
        పొట్టి dmOrientation;
        పొట్టి dm_Paper_కొలత;
        పొట్టి dm_Paper_నిడివి;
        పొట్టి dm_Paper_వెడల్పు;
        పొట్టి dmScale;
        పొట్టి dmCopies;
        పొట్టి dm_Default_ఆధారం;
        పొట్టి dmPrintQuality;
      };
      నిర్మాణం {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    పొట్టి dmColor;
    పొట్టి dmDuplex;
    పొట్టి dmYResolution;
    పొట్టి dmTTOption;
    పొట్టి dmCollate;
    BYTE dmFormName[CCHFORMNAME];
    మాట_3 dmLogPixels;
    DWORD dm_బిట్లు_చొప్పున_Pel;
    DWORD dm_Pels_వెడల్పు;
    DWORD dm_Pels_ఎత్తు;
    సంఘం {
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
    DWORD dm_Panning_వెడల్పు;
    DWORD dm_Panning_ఎత్తు;
  } DEVMODEA,*PDEVMODEA,*NPDEVMODEA,*LPDEVMODEA;

  రకనిర్వచనం నిర్మాణం _devicemodeW {
    WCHAR dmDeviceName[CCHDEVICENAME];
    మాట_3 dm_Spec_సంస్కరణ;
    మాట_3 dm_Driver_సంస్కరణ;
    మాట_3 dm_కొలత;
    మాట_3 dmDriverExtra;
    DWORD dmFields;
    సంఘం {
      నిర్మాణం {
        పొట్టి dmOrientation;
        పొట్టి dm_Paper_కొలత;
        పొట్టి dm_Paper_నిడివి;
        పొట్టి dm_Paper_వెడల్పు;
        పొట్టి dmScale;
        పొట్టి dmCopies;
        పొట్టి dm_Default_ఆధారం;
        పొట్టి dmPrintQuality;
      };
      నిర్మాణం {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    పొట్టి dmColor;
    పొట్టి dmDuplex;
    పొట్టి dmYResolution;
    పొట్టి dmTTOption;
    పొట్టి dmCollate;
    WCHAR dmFormName[CCHFORMNAME];
    మాట_3 dmLogPixels;
    DWORD dm_బిట్లు_చొప్పున_Pel;
    DWORD dm_Pels_వెడల్పు;
    DWORD dm_Pels_ఎత్తు;
    సంఘం {
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
    DWORD dm_Panning_వెడల్పు;
    DWORD dm_Panning_ఎత్తు;
  } DEVMODEW,*PDEVMODEW,*NPDEVMODEW,*LPDEVMODEW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం DEVMODEW DEVMODE;
  రకనిర్వచనం PDEVMODEW PDEVMODE;
  రకనిర్వచనం NPDEVMODEW NPDEVMODE;
  రకనిర్వచనం LPDEVMODEW LPDEVMODE;
#లేకపోతే
  రకనిర్వచనం DEVMODEA DEVMODE;
  రకనిర్వచనం PDEVMODEA PDEVMODE;
  రకనిర్వచనం NPDEVMODEA NPDEVMODE;
  రకనిర్వచనం LPDEVMODEA LPDEVMODE;
#అయితే_ముగింపు

#నిర్వచించు DM_SPECVERSION 0x0401

#నిర్వచించు DM_ORIENTATION 0x00000001L
#నిర్వచించు DM_PAPERSIZE 0x00000002L
#నిర్వచించు DM_PAPERLENGTH 0x00000004L
#నిర్వచించు DM_PAPERWIDTH 0x00000008L
#నిర్వచించు DM_SCALE 0x00000010L
#నిర్వచించు DM_POSITION 0x00000020L
#నిర్వచించు DM_NUP 0x00000040L
#నిర్వచించు DM_DISPLAYORIENTATION 0x00000080L
#నిర్వచించు DM_COPIES 0x00000100L
#నిర్వచించు DM_DEFAULTSOURCE 0x00000200L
#నిర్వచించు DM_PRINTQUALITY 0x00000400L
#నిర్వచించు DM_COLOR 0x00000800L
#నిర్వచించు DM_DUPLEX 0x00001000L
#నిర్వచించు DM_YRESOLUTION 0x00002000L
#నిర్వచించు DM_TTOPTION 0x00004000L
#నిర్వచించు DM_COLLATE 0x00008000L
#నిర్వచించు DM_FORMNAME 0x00010000L
#నిర్వచించు DM_LOGPIXELS 0x00020000L
#నిర్వచించు DM_BITSPERPEL 0x00040000L
#నిర్వచించు DM_PELSWIDTH 0x00080000L
#నిర్వచించు DM_PELSHEIGHT 0x00100000L
#నిర్వచించు DM_DISPLAYFLAGS 0x00200000L
#నిర్వచించు DM_DISPLAYFREQUENCY 0x00400000L
#నిర్వచించు DM_ICMMETHOD 0x00800000L
#నిర్వచించు DM_ICMINTENT 0x01000000L
#నిర్వచించు DM_MEDIATYPE 0x02000000L
#నిర్వచించు DM_DITHERTYPE 0x04000000L
#నిర్వచించు DM_PANNINGWIDTH 0x08000000L
#నిర్వచించు DM_PANNINGHEIGHT 0x10000000L
#నిర్వచించు DM_DISPLAYFIXEDOUTPUT 0x20000000L

#నిర్వచించు DMORIENT_PORTRAIT 1
#నిర్వచించు DMORIENT_LANDSCAPE 2

#నిర్వచించు DMPAPER_మొదటి DMPAPER_LETTER
#నిర్వచించు DMPAPER_LETTER 1
#నిర్వచించు DMPAPER_LETTERSMALL 2
#నిర్వచించు DMPAPER_TABLOID 3
#నిర్వచించు DMPAPER_LEDGER 4
#నిర్వచించు DMPAPER_LEGAL 5
#నిర్వచించు DMPAPER_STATEMENT 6
#నిర్వచించు DMPAPER_EXECUTIVE 7
#నిర్వచించు DMPAPER_A3 8
#నిర్వచించు DMPAPER_A4 9
#నిర్వచించు DMPAPER_A4SMALL 10
#నిర్వచించు DMPAPER_A5 11
#నిర్వచించు DMPAPER_B4 12
#నిర్వచించు DMPAPER_B5 13
#నిర్వచించు DMPAPER_FOLIO 14
#నిర్వచించు DMPAPER_QUARTO 15
#నిర్వచించు DMPAPER_10X14 16
#నిర్వచించు DMPAPER_11X17 17
#నిర్వచించు DMPAPER_NOTE 18
#నిర్వచించు DMPAPER_ENV_9 19
#నిర్వచించు DMPAPER_ENV_10 20
#నిర్వచించు DMPAPER_ENV_11 21
#నిర్వచించు DMPAPER_ENV_12 22
#నిర్వచించు DMPAPER_ENV_14 23
#నిర్వచించు DMPAPER_CSHEET 24
#నిర్వచించు DMPAPER_DSHEET 25
#నిర్వచించు DMPAPER_ESHEET 26
#నిర్వచించు DMPAPER_ENV_DL 27
#నిర్వచించు DMPAPER_ENV_C5 28
#నిర్వచించు DMPAPER_ENV_C3 29
#నిర్వచించు DMPAPER_ENV_C4 30
#నిర్వచించు DMPAPER_ENV_C6 31
#నిర్వచించు DMPAPER_ENV_C65 32
#నిర్వచించు DMPAPER_ENV_B4 33
#నిర్వచించు DMPAPER_ENV_B5 34
#నిర్వచించు DMPAPER_ENV_B6 35
#నిర్వచించు DMPAPER_ENV_ITALY 36
#నిర్వచించు DMPAPER_ENV_MONARCH 37
#నిర్వచించు DMPAPER_ENV_PERSONAL 38
#నిర్వచించు DMPAPER_FANFOLD_US 39
#నిర్వచించు DMPAPER_FANFOLD_STD_GERMAN 40
#నిర్వచించు DMPAPER_FANFOLD_LGL_GERMAN 41
#నిర్వచించు DMPAPER_ISO_B4 42
#నిర్వచించు DMPAPER_JAPANESE_POSTCARD 43
#నిర్వచించు DMPAPER_9X11 44
#నిర్వచించు DMPAPER_10X11 45
#నిర్వచించు DMPAPER_15X11 46
#నిర్వచించు DMPAPER_ENV_INVITE 47
#నిర్వచించు DMPAPER_RESERVED_48 48
#నిర్వచించు DMPAPER_RESERVED_49 49
#నిర్వచించు DMPAPER_LETTER_EXTRA 50
#నిర్వచించు DMPAPER_LEGAL_EXTRA 51
#నిర్వచించు DMPAPER_TABLOID_EXTRA 52
#నిర్వచించు DMPAPER_A4_EXTRA 53
#నిర్వచించు DMPAPER_LETTER_TRANSVERSE 54
#నిర్వచించు DMPAPER_A4_TRANSVERSE 55
#నిర్వచించు DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#నిర్వచించు DMPAPER_A_PLUS 57
#నిర్వచించు DMPAPER_B_PLUS 58
#నిర్వచించు DMPAPER_LETTER_PLUS 59
#నిర్వచించు DMPAPER_A4_PLUS 60
#నిర్వచించు DMPAPER_A5_TRANSVERSE 61
#నిర్వచించు DMPAPER_B5_TRANSVERSE 62
#నిర్వచించు DMPAPER_A3_EXTRA 63
#నిర్వచించు DMPAPER_A5_EXTRA 64
#నిర్వచించు DMPAPER_B5_EXTRA 65
#నిర్వచించు DMPAPER_A2 66
#నిర్వచించు DMPAPER_A3_TRANSVERSE 67
#నిర్వచించు DMPAPER_A3_EXTRA_TRANSVERSE 68
#నిర్వచించు DMPAPER_DBL_JAPANESE_POSTCARD 69
#నిర్వచించు DMPAPER_A6 70
#నిర్వచించు DMPAPER_JENV_KAKU2 71
#నిర్వచించు DMPAPER_JENV_KAKU3 72
#నిర్వచించు DMPAPER_JENV_CHOU3 73
#నిర్వచించు DMPAPER_JENV_CHOU4 74
#నిర్వచించు DMPAPER_LETTER_ROTATED 75
#నిర్వచించు DMPAPER_A3_ROTATED 76
#నిర్వచించు DMPAPER_A4_ROTATED 77
#నిర్వచించు DMPAPER_A5_ROTATED 78
#నిర్వచించు DMPAPER_B4_JIS_ROTATED 79
#నిర్వచించు DMPAPER_B5_JIS_ROTATED 80
#నిర్వచించు DMPAPER_JAPANESE_POSTCARD_ROTATED 81
#నిర్వచించు DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#నిర్వచించు DMPAPER_A6_ROTATED 83
#నిర్వచించు DMPAPER_JENV_KAKU2_ROTATED 84
#నిర్వచించు DMPAPER_JENV_KAKU3_ROTATED 85
#నిర్వచించు DMPAPER_JENV_CHOU3_ROTATED 86
#నిర్వచించు DMPAPER_JENV_CHOU4_ROTATED 87
#నిర్వచించు DMPAPER_B6_JIS 88
#నిర్వచించు DMPAPER_B6_JIS_ROTATED 89
#నిర్వచించు DMPAPER_12X11 90
#నిర్వచించు DMPAPER_JENV_YOU4 91
#నిర్వచించు DMPAPER_JENV_YOU4_ROTATED 92
#నిర్వచించు DMPAPER_P16K 93
#నిర్వచించు DMPAPER_P32K 94
#నిర్వచించు DMPAPER_P32KBIG 95
#నిర్వచించు DMPAPER_PENV_1 96
#నిర్వచించు DMPAPER_PENV_2 97
#నిర్వచించు DMPAPER_PENV_3 98
#నిర్వచించు DMPAPER_PENV_4 99
#నిర్వచించు DMPAPER_PENV_5 100
#నిర్వచించు DMPAPER_PENV_6 101
#నిర్వచించు DMPAPER_PENV_7 102
#నిర్వచించు DMPAPER_PENV_8 103
#నిర్వచించు DMPAPER_PENV_9 104
#నిర్వచించు DMPAPER_PENV_10 105
#నిర్వచించు DMPAPER_P16K_ROTATED 106
#నిర్వచించు DMPAPER_P32K_ROTATED 107
#నిర్వచించు DMPAPER_P32KBIG_ROTATED 108
#నిర్వచించు DMPAPER_PENV_1_ROTATED 109
#నిర్వచించు DMPAPER_PENV_2_ROTATED 110
#నిర్వచించు DMPAPER_PENV_3_ROTATED 111
#నిర్వచించు DMPAPER_PENV_4_ROTATED 112
#నిర్వచించు DMPAPER_PENV_5_ROTATED 113
#నిర్వచించు DMPAPER_PENV_6_ROTATED 114
#నిర్వచించు DMPAPER_PENV_7_ROTATED 115
#నిర్వచించు DMPAPER_PENV_8_ROTATED 116
#నిర్వచించు DMPAPER_PENV_9_ROTATED 117
#నిర్వచించు DMPAPER_PENV_10_ROTATED 118

#నిర్వచించు DMPAPER_చివరి DMPAPER_PENV_10_ROTATED

#నిర్వచించు DMPAPER_USER 256

#నిర్వచించు DMBIN_మొదటి DMBIN_పై
#నిర్వచించు DMBIN_పై 1
#నిర్వచించు DMBIN_ONLYONE 1
#నిర్వచించు DMBIN_క్రింది 2
#నిర్వచించు DMBIN_మధ్య 3
#నిర్వచించు DMBIN_MANUAL 4
#నిర్వచించు DMBIN_ENVELOPE 5
#నిర్వచించు DMBIN_ENVMANUAL 6
#నిర్వచించు DMBIN_AUTO 7
#నిర్వచించు DMBIN_TRACTOR 8
#నిర్వచించు DMBIN_SMALLFMT 9
#నిర్వచించు DMBIN_LARGEFMT 10
#నిర్వచించు DMBIN_LARGECAPACITY 11
#నిర్వచించు DMBIN_CASSETTE 14
#నిర్వచించు DMBIN_FORMSOURCE 15
#నిర్వచించు DMBIN_చివరి DMBIN_FORMSOURCE

#నిర్వచించు DMBIN_USER 256

#నిర్వచించు DMRES_DRAFT (-1)
#నిర్వచించు DMRES_దిగువ (-2)
#నిర్వచించు DMRES_MEDIUM (-3)
#నిర్వచించు DMRES_ఎగువ (-4)

#నిర్వచించు DMCOLOR_MONOCHROME 1
#నిర్వచించు DMCOLOR_COLOR 2

#నిర్వచించు DMDUP_SIMPLEX 1
#నిర్వచించు DMDUP_VERTICAL 2
#నిర్వచించు DMDUP_HORIZONTAL 3

#నిర్వచించు DMTT_BITMAP 1
#నిర్వచించు DMTT_DOWNLOAD 2
#నిర్వచించు DMTT_SUBDEV 3
#నిర్వచించు DMTT_DOWNLOAD_OUTLINE 4

#నిర్వచించు DMCOLLATE_FALSE 0
#నిర్వచించు DMCOLLATE_TRUE 1

#నిర్వచించు DMDO_DEFAULT 0
#నిర్వచించు DMDO_90 1
#నిర్వచించు DMDO_180 2
#నిర్వచించు DMDO_270 3

#నిర్వచించు DMDFO_DEFAULT 0
#నిర్వచించు DMDFO_STRETCH 1
#నిర్వచించు DMDFO_CENTER 2

#నిర్వచించు DMDISPLAYFLAGS_TEXTMODE 0x00000004

#నిర్వచించు DMNUP_SYSTEM 1
#నిర్వచించు DMNUP_ONEUP 2

#నిర్వచించు DMICMMETHOD_NONE 1
#నిర్వచించు DMICMMETHOD_SYSTEM 2
#నిర్వచించు DMICMMETHOD_DRIVER 3
#నిర్వచించు DMICMMETHOD_DEVICE 4

#నిర్వచించు DMICMMETHOD_USER 256

#నిర్వచించు DMICM_SATURATE 1
#నిర్వచించు DMICM_CONTRAST 2
#నిర్వచించు DMICM_COLORIMETRIC 3
#నిర్వచించు DMICM_ABS_COLORIMETRIC 4

#నిర్వచించు DMICM_USER 256

#నిర్వచించు DMMEDIA_STANDARD 1
#నిర్వచించు DMMEDIA_TRANSPARENCY 2
#నిర్వచించు DMMEDIA_GLOSSY 3

#నిర్వచించు DMMEDIA_USER 256

#నిర్వచించు DMDITHER_NONE 1
#నిర్వచించు DMDITHER_COARSE 2
#నిర్వచించు DMDITHER_FINE 3
#నిర్వచించు DMDITHER_LINEART 4
#నిర్వచించు DMDITHER_ERRORDIFFUSION 5
#నిర్వచించు DMDITHER_RESERVED6 6
#నిర్వచించు DMDITHER_RESERVED7 7
#నిర్వచించు DMDITHER_RESERVED8 8
#నిర్వచించు DMDITHER_RESERVED9 9
#నిర్వచించు DMDITHER_GRAYSCALE 10

#నిర్వచించు DMDITHER_USER 256

  రకనిర్వచనం నిర్మాణం _DISPLAY_DEVICEA {
    DWORD cb;
    CHAR DeviceName[32];
    CHAR DeviceString[128];
    DWORD StateFlags;
    CHAR DeviceID[128];
    CHAR Device_కీలకం[128];
  } DISPLAY_DEVICEA,*PDISPLAY_DEVICEA,*LPDISPLAY_DEVICEA;
  రకనిర్వచనం నిర్మాణం _DISPLAY_DEVICEW {
    DWORD cb;
    WCHAR DeviceName[32];
    WCHAR DeviceString[128];
    DWORD StateFlags;
    WCHAR DeviceID[128];
    WCHAR Device_కీలకం[128];
  } DISPLAY_DEVICEW,*PDISPLAY_DEVICEW,*LPDISPLAY_DEVICEW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం DISPLAY_DEVICEW DISPLAY_DEVICE;
  రకనిర్వచనం PDISPLAY_DEVICEW PDISPLAY_DEVICE;
  రకనిర్వచనం LPDISPLAY_DEVICEW LPDISPLAY_DEVICE;
#లేకపోతే
  రకనిర్వచనం DISPLAY_DEVICEA DISPLAY_DEVICE;
  రకనిర్వచనం PDISPLAY_DEVICEA PDISPLAY_DEVICE;
  రకనిర్వచనం LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
#అయితే_ముగింపు

#నిర్వచించు DISPLAY_DEVICE_ATTACHED_గమ్యం_DESKTOP 0x00000001
#నిర్వచించు DISPLAY_DEVICE_MULTI_DRIVER 0x00000002
#నిర్వచించు DISPLAY_DEVICE_PRIMARY_DEVICE 0x00000004
#నిర్వచించు DISPLAY_DEVICE_MIRRORING_DRIVER 0x00000008
#నిర్వచించు DISPLAY_DEVICE_VGA_COMPATIBLE 0x00000010
#నిర్వచించు DISPLAY_DEVICE_REMOVABLE 0x00000020
#నిర్వచించు DISPLAY_DEVICE_MODESPRUNED 0x08000000
#నిర్వచించు DISPLAY_DEVICE_REMOTE 0x04000000
#నిర్వచించు DISPLAY_DEVICE_DISCONNECT 0x02000000

#నిర్వచించు DISPLAY_DEVICE_చురుకైన 0x00000001
#నిర్వచించు DISPLAY_DEVICE_ATTACHED 0x00000002

#నిర్వచించు RDH_RECTANGLES 1

  రకనిర్వచనం నిర్మాణం _RGNDATAHEADER {
    DWORD dw_కొలత;
    DWORD iType;
    DWORD n_లెక్క;
    DWORD n_Rgn_కొలత;
    RECT rcBound;
  } RGNDATAHEADER,*PRGNDATAHEADER;

  రకనిర్వచనం నిర్మాణం _RGNDATA {
    RGNDATAHEADER rdh;
    అక్షరం బఫరు_3[1];
  } RGNDATA,*PRGNDATA,*NPRGNDATA,*LPRGNDATA;

#నిర్వచించు SYSRGN 4

  రకనిర్వచనం నిర్మాణం _ABC {
    పూర్ణాంకం abcA;
    UINT abcB;
    పూర్ణాంకం abcC;
  } ABC,*PABC,*NPABC,*LPABC;

  రకనిర్వచనం నిర్మాణం _ABCFLOAT {
    FLOAT abcfA;
    FLOAT abcfB;
    FLOAT abcfC;
  } ABCFLOAT,*PABCFLOAT,*NPABCFLOAT,*LPABCFLOAT;

#నిర్వచితం_కాకపోతే NOTEXTMETRIC

  రకనిర్వచనం నిర్మాణం _OUTLINETEXTMETRICA {
    UINT otm_కొలత;
    TEXTMETRICA otm_పాఠ్యం_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_సంఖ్య;
    UINT otmfsSelection;
    UINT otmfsType;
    పూర్ణాంకం otms_Char_వాలు_Rise;
    పూర్ణాంకం otms_Char_వాలు_నిరంతరం;
    పూర్ణాంకం otmItalicAngle;
    UINT otmEMSquare;
    పూర్ణాంకం otmAscent;
    పూర్ణాంకం otmDescent;
    UINT otm_పంక్తి_Gap;
    UINT otms_Cap_Em_ఎత్తు;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    పూర్ణాంకం otmMacAscent;
    పూర్ణాంకం otmMacDescent;
    UINT otm_Mac_పంక్తి_Gap;
    UINT otmusMinimumPPEM;
    బిందువు_3 otmpt_Subscript_కొలత;
    బిందువు_3 otmpt_Subscript_స్థానభ్రంశం;
    బిందువు_3 otmpt_Superscript_కొలత;
    బిందువు_3 otmpt_Superscript_స్థానభ్రంశం;
    UINT otms_Strikeout_కొలత;
    పూర్ణాంకం otmsStrikeoutPosition;
    పూర్ణాంకం otms_Underscore_కొలత;
    పూర్ణాంకం otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_నిండిన_Name;
  } OUTLINETEXTMETRICA,*POUTLINETEXTMETRICA,*NPOUTLINETEXTMETRICA,*LPOUTLINETEXTMETRICA;

  రకనిర్వచనం నిర్మాణం _OUTLINETEXTMETRICW {
    UINT otm_కొలత;
    TEXTMETRICW otm_పాఠ్యం_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_సంఖ్య;
    UINT otmfsSelection;
    UINT otmfsType;
    పూర్ణాంకం otms_Char_వాలు_Rise;
    పూర్ణాంకం otms_Char_వాలు_నిరంతరం;
    పూర్ణాంకం otmItalicAngle;
    UINT otmEMSquare;
    పూర్ణాంకం otmAscent;
    పూర్ణాంకం otmDescent;
    UINT otm_పంక్తి_Gap;
    UINT otms_Cap_Em_ఎత్తు;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    పూర్ణాంకం otmMacAscent;
    పూర్ణాంకం otmMacDescent;
    UINT otm_Mac_పంక్తి_Gap;
    UINT otmusMinimumPPEM;
    బిందువు_3 otmpt_Subscript_కొలత;
    బిందువు_3 otmpt_Subscript_స్థానభ్రంశం;
    బిందువు_3 otmpt_Superscript_కొలత;
    బిందువు_3 otmpt_Superscript_స్థానభ్రంశం;
    UINT otms_Strikeout_కొలత;
    పూర్ణాంకం otmsStrikeoutPosition;
    పూర్ణాంకం otms_Underscore_కొలత;
    పూర్ణాంకం otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_నిండిన_Name;
  } OUTLINETEXTMETRICW,*POUTLINETEXTMETRICW,*NPOUTLINETEXTMETRICW,*LPOUTLINETEXTMETRICW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం OUTLINETEXTMETRICW OUTLINETEXTMETRIC;
  రకనిర్వచనం POUTLINETEXTMETRICW POUTLINETEXTMETRIC;
  రకనిర్వచనం NPOUTLINETEXTMETRICW NPOUTLINETEXTMETRIC;
  రకనిర్వచనం LPOUTLINETEXTMETRICW LPOUTLINETEXTMETRIC;
#లేకపోతే
  రకనిర్వచనం OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
  రకనిర్వచనం POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
  రకనిర్వచనం NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
  రకనిర్వచనం LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
#అయితే_ముగింపు
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_POLYTEXTA {
    పూర్ణాంకం x;
    పూర్ణాంకం y;
    UINT n;
    LPCSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    పూర్ణాంకం *pdx;
  } POLYTEXTA,*PPOLYTEXTA,*NPPOLYTEXTA,*LPPOLYTEXTA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_POLYTEXTW {
    పూర్ణాంకం x;
    పూర్ణాంకం y;
    UINT n;
    LPCWSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    పూర్ణాంకం *pdx;
  } POLYTEXTW,*PPOLYTEXTW,*NPPOLYTEXTW,*LPPOLYTEXTW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం POLYTEXTW POLYTEXT;
  రకనిర్వచనం PPOLYTEXTW PPOLYTEXT;
  రకనిర్వచనం NPPOLYTEXTW NPPOLYTEXT;
  రకనిర్వచనం LPPOLYTEXTW LPPOLYTEXT;
#లేకపోతే
  రకనిర్వచనం POLYTEXTA POLYTEXT;
  రకనిర్వచనం PPOLYTEXTA PPOLYTEXT;
  రకనిర్వచనం NPPOLYTEXTA NPPOLYTEXT;
  రకనిర్వచనం LPPOLYTEXTA LPPOLYTEXT;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం _FIXED {
    మాట_3 fract;
    పొట్టి విలువ;
  } FIXED;

  రకనిర్వచనం నిర్మాణం _MAT2 {
    FIXED eM11;
    FIXED eM12;
    FIXED eM21;
    FIXED eM22;
  } MAT2,*LPMAT2;

  రకనిర్వచనం నిర్మాణం _GLYPHMETRICS {
    UINT gmBlackBoxX;
    UINT gmBlackBoxY;
    బిందువు_3 gmptGlyphOrigin;
    పొట్టి gmCellIncX;
    పొట్టి gmCellIncY;
  } GLYPHMETRICS,*LPGLYPHMETRICS;

#నిర్వచించు GGO_METRICS 0
#నిర్వచించు GGO_BITMAP 1
#నిర్వచించు GGO_NATIVE 2
#నిర్వచించు GGO_BEZIER 3

#నిర్వచించు GGO_GRAY2_BITMAP 4
#నిర్వచించు GGO_GRAY4_BITMAP 5
#నిర్వచించు GGO_GRAY8_BITMAP 6
#నిర్వచించు GGO_GLYPH_సూచీ 0x0080
#నిర్వచించు GGO_UNHINTED 0x0100

#నిర్వచించు TT_POLYGON_TYPE 24

#నిర్వచించు TT_PRIM_పంక్తి 1
#నిర్వచించు TT_PRIM_QSPLINE 2
#నిర్వచించు TT_PRIM_CSPLINE 3

  రకనిర్వచనం నిర్మాణం ట్యాగ్_POINTFX {
    FIXED x;
    FIXED y;
  } POINTFX,*LPPOINTFX;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_TTPOLYCURVE {
    మాట_3 wType;
    మాట_3 cpfx;
    POINTFX apfx[1];
  } TTPOLYCURVE,*LPTTPOLYCURVE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_TTPOLYGONHEADER {
    DWORD cb;
    DWORD dwType;
    POINTFX pfx_ప్రారంభం;
  } TTPOLYGONHEADER,*LPTTPOLYGONHEADER;

#నిర్వచించు GCP_DBCS 0x0001
#నిర్వచించు GCP_REORDER 0x0002
#నిర్వచించు GCP_USEKERNING 0x0008
#నిర్వచించు GCP_GLYPHSHAPE 0x0010
#నిర్వచించు GCP_LIGATE 0x0020

#నిర్వచించు GCP_DIACRITIC 0x0100
#నిర్వచించు GCP_KASHIDA 0x0400
#నిర్వచించు GCP_ERROR 0x8000
#నిర్వచించు FLI_ముసుగు 0x103B

#నిర్వచించు GCP_JUSTIFY 0x00010000L

#నిర్వచించు FLI_GLYPHS 0x00040000L
#నిర్వచించు GCP_CLASSIN 0x00080000L
#నిర్వచించు GCP_MAXEXTENT 0x00100000L
#నిర్వచించు GCP_JUSTIFYIN 0x00200000L
#నిర్వచించు GCP_DISPLAYZWG 0x00400000L
#నిర్వచించు GCP_SYMSWAPOFF 0x00800000L
#నిర్వచించు GCP_NUMERICOVERRIDE 0x01000000L
#నిర్వచించు GCP_NEUTRALOVERRIDE 0x02000000L
#నిర్వచించు GCP_NUMERICSLATIN 0x04000000L
#నిర్వచించు GCP_NUMERICSLOCAL 0x08000000L

#నిర్వచించు GCPCLASS_LATIN 1
#నిర్వచించు GCPCLASS_HEBREW 2
#నిర్వచించు GCPCLASS_ARABIC 2
#నిర్వచించు GCPCLASS_NEUTRAL 3
#నిర్వచించు GCPCLASS_LOCALNUMBER 4
#నిర్వచించు GCPCLASS_LATINNUMBER 5
#నిర్వచించు GCPCLASS_LATINNUMERICTERMINATOR 6
#నిర్వచించు GCPCLASS_LATINNUMERICSEPARATOR 7
#నిర్వచించు GCPCLASS_NUMERICSEPARATOR 8
#నిర్వచించు GCPCLASS_PREBOUNDLTR 0x80
#నిర్వచించు GCPCLASS_PREBOUNDRTL 0x40
#నిర్వచించు GCPCLASS_POSTBOUNDLTR 0x20
#నిర్వచించు GCPCLASS_POSTBOUNDRTL 0x10

#నిర్వచించు GCPGLYPH_LINKBEFORE 0x8000
#నిర్వచించు GCPGLYPH_LINKAFTER 0x4000

  రకనిర్వచనం నిర్మాణం ట్యాగ్_GCP_RESULTSA {
    DWORD l_Struct_కొలత;
    LPSTR lp_బహిర్గతం_String;
    UINT *lp_క్రమం;
    పూర్ణాంకం *lpDx;
    పూర్ణాంకం *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    పూర్ణాంకం nMaxFit;
  } GCP_RESULTSA,*LPGCP_RESULTSA;
  రకనిర్వచనం నిర్మాణం ట్యాగ్_GCP_RESULTSW {
    DWORD l_Struct_కొలత;
    LPWSTR lp_బహిర్గతం_String;
    UINT *lp_క్రమం;
    పూర్ణాంకం *lpDx;
    పూర్ణాంకం *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    పూర్ణాంకం nMaxFit;
  } GCP_RESULTSW,*LPGCP_RESULTSW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం GCP_RESULTSW GCP_RESULTS;
  రకనిర్వచనం LPGCP_RESULTSW LPGCP_RESULTS;
#లేకపోతే
  రకనిర్వచనం GCP_RESULTSA GCP_RESULTS;
  రకనిర్వచనం LPGCP_RESULTSA LPGCP_RESULTS;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం RASTERIZER_స్థితి {
    పొట్టి n_కొలత;
    పొట్టి wFlags;
    పొట్టి nLanguageID;
  } RASTERIZER_స్థితి_2,*LPRASTERIZER_స్థితి;

#నిర్వచించు TT_అందుబాటు 0x0001
#నిర్వచించు TT_ENABLED 0x0002

  రకనిర్వచనం నిర్మాణం ట్యాగ్_PIXELFORMATDESCRIPTOR {
    మాట_3 n_కొలత;
    మాట_3 n_సంస్కరణ;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_బిట్లు;
    BYTE c_Red_బిట్లు;
    BYTE c_Red_జరుపు;
    BYTE c_Green_బిట్లు;
    BYTE c_Green_జరుపు;
    BYTE c_Blue_బిట్లు;
    BYTE c_Blue_జరుపు;
    BYTE c_Alpha_బిట్లు;
    BYTE c_Alpha_జరుపు;
    BYTE c_Accum_బిట్లు;
    BYTE c_Accum_Red_బిట్లు;
    BYTE c_Accum_Green_బిట్లు;
    BYTE c_Accum_Blue_బిట్లు;
    BYTE c_Accum_Alpha_బిట్లు;
    BYTE c_లోతు_బిట్లు;
    BYTE c_Stencil_బిట్లు;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dw_Layer_ముసుగు;
    DWORD dw_Visible_ముసుగు;
    DWORD dw_Damage_ముసుగు;
  } PIXELFORMATDESCRIPTOR,*PPIXELFORMATDESCRIPTOR,*LPPIXELFORMATDESCRIPTOR;

#నిర్వచించు PFD_TYPE_RGBA 0
#నిర్వచించు PFD_TYPE_COLORINDEX 1

#నిర్వచించు PFD_MAIN_PLANE 0
#నిర్వచించు PFD_OVERLAY_PLANE 1
#నిర్వచించు PFD_UNDERLAY_PLANE (-1)

#నిర్వచించు PFD_DOUBLEBUFFER 0x00000001
#నిర్వచించు PFD_STEREO 0x00000002
#నిర్వచించు PFD_DRAW_గమ్యం_కిటికీ 0x00000004
#నిర్వచించు PFD_DRAW_గమ్యం_BITMAP 0x00000008
#నిర్వచించు PFD_SUPPORT_GDI 0x00000010
#నిర్వచించు PFD_SUPPORT_OPENGL 0x00000020
#నిర్వచించు PFD_GENERIC_FORMAT 0x00000040
#నిర్వచించు PFD_NEED_PALETTE 0x00000080
#నిర్వచించు PFD_NEED_SYSTEM_PALETTE 0x00000100
#నిర్వచించు PFD_మార్పిడి_EXCHANGE 0x00000200
#నిర్వచించు PFD_మార్పిడి_COPY 0x00000400
#నిర్వచించు PFD_మార్పిడి_LAYER_BUFFERS 0x00000800
#నిర్వచించు PFD_GENERIC_ACCELERATED 0x00001000
#నిర్వచించు PFD_SUPPORT_DIRECTDRAW 0x00002000

#నిర్వచించు PFD_లోతు_DONTCARE 0x20000000
#నిర్వచించు PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#నిర్వచించు PFD_STEREO_DONTCARE 0x80000000

#నిర్వచితం_కాకపోతే NOTEXTMETRIC
  రకనిర్వచనం పూర్ణాంకం (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST TEXTMETRICA *,DWORD,LPARAM);
  రకనిర్వచనం పూర్ణాంకం (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST TEXTMETRICW *,DWORD,LPARAM);
#నిర్వచితమైతే UNICODE
#నిర్వచించు OLDFONTENUMPROC OLDFONTENUMPROCW
#లేకపోతే
#నిర్వచించు OLDFONTENUMPROC OLDFONTENUMPROCA
#అయితే_ముగింపు
#లేకపోతే
  రకనిర్వచనం పూర్ణాంకం (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST VOID *,DWORD,LPARAM);
  రకనిర్వచనం పూర్ణాంకం (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST VOID *,DWORD,LPARAM);
#నిర్వచితమైతే UNICODE
#నిర్వచించు OLDFONTENUMPROC OLDFONTENUMPROCW
#లేకపోతే
#నిర్వచించు OLDFONTENUMPROC OLDFONTENUMPROCA
#అయితే_ముగింపు
#అయితే_ముగింపు

  రకనిర్వచనం OLDFONTENUMPROCA FONTENUMPROCA;
  రకనిర్వచనం OLDFONTENUMPROCW FONTENUMPROCW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం FONTENUMPROCW FONTENUMPROC;
#లేకపోతే
  రకనిర్వచనం FONTENUMPROCA FONTENUMPROC;
#అయితే_ముగింపు

  రకనిర్వచనం పూర్ణాంకం (CALLBACK *GOBJENUMPROC)(LPVOID,LPARAM);
  రకనిర్వచనం VOID (CALLBACK *LINEDDAPROC)(పూర్ణాంకం,పూర్ణాంకం,LPARAM);

#నిర్వచితమైతే UNICODE
#నిర్వచించు కూడు_Font_Resource కూడు_Font_Resource_W
#నిర్వచించు CopyMetaFile CopyMetaFileW
#నిర్వచించు CreateDC CreateDCW
#నిర్వచించు Create_Font_పరోక్ష Create_Font_పరోక్ష_W
#నిర్వచించు CreateFont CreateFontW
#నిర్వచించు CreateIC CreateICW
#నిర్వచించు CreateMetaFile CreateMetaFileW
#నిర్వచించు CreateScalableFontResource CreateScalableFontResourceW
#లేకపోతే
#నిర్వచించు కూడు_Font_Resource కూడు_Font_Resource_A
#నిర్వచించు CopyMetaFile CopyMetaFileA
#నిర్వచించు CreateDC CreateDCA
#నిర్వచించు Create_Font_పరోక్ష Create_Font_పరోక్ష_A
#నిర్వచించు CreateFont CreateFontA
#నిర్వచించు CreateIC CreateICA
#నిర్వచించు CreateMetaFile CreateMetaFileA
#నిర్వచించు CreateScalableFontResource CreateScalableFontResourceA
#అయితే_ముగింపు

  WINGDIAPI పూర్ణాంకం WINAPI కూడు_Font_Resource_A(LPCSTR);
  WINGDIAPI పూర్ణాంకం WINAPI కూడు_Font_Resource_W(LPCWSTR);
  WINGDIAPI WINBOOL WINAPI AnimatePalette(HPALETTE hPal,UINT i_ప్రారంభం_సూచీ,UINT cEntries,CONST PALETTEENTRY *ppe);
  WINGDIAPI WINBOOL WINAPI Arc(HDC hdc,పూర్ణాంకం x1,పూర్ణాంకం y1,పూర్ణాంకం x2,పూర్ణాంకం y2,పూర్ణాంకం x3,పూర్ణాంకం y3,పూర్ణాంకం x4,పూర్ణాంకం y4);
  WINGDIAPI WINBOOL WINAPI బిట్టు_Blt(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,పూర్ణాంకం cx,పూర్ణాంకం cy,HDC hdcSrc,పూర్ణాంకం x1,పూర్ణాంకం y1,DWORD rop);
  WINGDIAPI WINBOOL WINAPI CancelDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Chord(HDC hdc,పూర్ణాంకం x1,పూర్ణాంకం y1,పూర్ణాంకం x2,పూర్ణాంకం y2,పూర్ణాంకం x3,పూర్ణాంకం y3,పూర్ణాంకం x4,పూర్ణాంకం y4);
  WINGDIAPI పూర్ణాంకం WINAPI ఎంచుకో_Pixel_Format(HDC hdc,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI HMETAFILE WINAPI CloseMetaFile(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,పూర్ణాంకం i_బహుళకం);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
  WINGDIAPI HBITMAP WINAPI CreateBitmap(పూర్ణాంకం n_వెడల్పు,పూర్ణాంకం n_ఎత్తు,UINT nPlanes,UINT n_బిట్టు_లెక్క,CONST VOID *lp_బిట్లు);
  WINGDIAPI HBITMAP WINAPI Create_Bitmap_పరోక్ష(CONST BITMAP *pbm);
  WINGDIAPI HBRUSH WINAPI Create_Brush_పరోక్ష(CONST LOGBRUSH *plbrush);
  WINGDIAPI HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc,పూర్ణాంకం cx,పూర్ణాంకం cy);
  WINGDIAPI HBITMAP WINAPI CreateDiscardableBitmap(HDC hdc,పూర్ణాంకం cx,పూర్ణాంకం cy);
  WINGDIAPI HDC WINAPI CreateCompatibleDC(HDC hdc);
  WINGDIAPI HDC WINAPI CreateDCA(LPCSTR pwszDriver,LPCSTR pwszDevice,LPCSTR psz_పోర్టు,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateDCW(LPCWSTR pwszDriver,LPCWSTR pwszDevice,LPCWSTR psz_పోర్టు,CONST DEVMODEW *pdm);
  WINGDIAPI HBITMAP WINAPI CreateDIBitmap(HDC hdc,CONST BITMAPINFOHEADER *pbmih,DWORD flInit,CONST VOID *pj_బిట్లు,CONST BITMAPINFO *pbmi,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL h,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB,UINT iUsage);
  WINGDIAPI HRGN WINAPI CreateEllipticRgn(పూర్ణాంకం x1,పూర్ణాంకం y1,పూర్ణాంకం x2,పూర్ణాంకం y2);
  WINGDIAPI HRGN WINAPI Create_Elliptic_Rgn_పరోక్ష(CONST RECT *lprect);
  WINGDIAPI HFONT WINAPI Create_Font_పరోక్ష_A(CONST LOGFONTA *lplf);
  WINGDIAPI HFONT WINAPI Create_Font_పరోక్ష_W(CONST LOGFONTW *lplf);
  WINGDIAPI HFONT WINAPI CreateFontA(పూర్ణాంకం c_ఎత్తు,పూర్ణాంకం c_వెడల్పు,పూర్ణాంకం cEscapement,పూర్ణాంకం cOrientation,పూర్ణాంకం c_బరువు,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_బహిర్గతం,DWORD i_Char_సమితి,DWORD i_బహిర్గతం_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCSTR pszFaceName);
  WINGDIAPI HFONT WINAPI CreateFontW(పూర్ణాంకం c_ఎత్తు,పూర్ణాంకం c_వెడల్పు,పూర్ణాంకం cEscapement,పూర్ణాంకం cOrientation,పూర్ణాంకం c_బరువు,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_బహిర్గతం,DWORD i_Char_సమితి,DWORD i_బహిర్గతం_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCWSTR pszFaceName);
  WINGDIAPI HBRUSH WINAPI CreateHatchBrush(పూర్ణాంకం iHatch,COLORREF color);
  WINGDIAPI HDC WINAPI CreateICA(LPCSTR pszDriver,LPCSTR pszDevice,LPCSTR psz_పోర్టు,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateICW(LPCWSTR pszDriver,LPCWSTR pszDevice,LPCWSTR psz_పోర్టు,CONST DEVMODEW *pdm);
  WINGDIAPI HDC WINAPI CreateMetaFileA(LPCSTR pszFile);
  WINGDIAPI HDC WINAPI CreateMetaFileW(LPCWSTR pszFile);
  WINGDIAPI HPALETTE WINAPI CreatePalette(CONST LOGPALETTE *plpal);
  WINGDIAPI HPEN WINAPI CreatePen(పూర్ణాంకం iStyle,పూర్ణాంకం c_వెడల్పు,COLORREF color);
  WINGDIAPI HPEN WINAPI Create_Pen_పరోక్ష(CONST LOGPEN *plpen);
  WINGDIAPI HRGN WINAPI CreatePolyPolygonRgn(CONST బిందువు_3 *pptl,CONST INT *pc,పూర్ణాంకం cPoly,పూర్ణాంకం i_బహుళకం);
  WINGDIAPI HBRUSH WINAPI Create_నమూనా_Brush(HBITMAP hbm);
  WINGDIAPI HRGN WINAPI CreateRectRgn(పూర్ణాంకం x1,పూర్ణాంకం y1,పూర్ణాంకం x2,పూర్ణాంకం y2);
  WINGDIAPI HRGN WINAPI Create_Rect_Rgn_పరోక్ష(CONST RECT *lprect);
  WINGDIAPI HRGN WINAPI Create_విడత_Rect_Rgn(పూర్ణాంకం x1,పూర్ణాంకం y1,పూర్ణాంకం x2,పూర్ణాంకం y2,పూర్ణాంకం w,పూర్ణాంకం h);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceA(DWORD fdwHidden,LPCSTR lpszFont,LPCSTR lpszFile,LPCSTR lpsz_మార్గం);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceW(DWORD fdwHidden,LPCWSTR lpszFont,LPCWSTR lpszFile,LPCWSTR lpsz_మార్గం);
  WINGDIAPI HBRUSH WINAPI CreateSolidBrush(COLORREF color);
  WINGDIAPI WINBOOL WINAPI DeleteDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI DeleteMetaFile(HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI DeleteObject(HGDIOBJ ho);
  WINGDIAPI పూర్ణాంకం WINAPI DescribePixelFormat(HDC hdc,పూర్ణాంకం iPixelFormat,UINT n_బైట్లు,LPPIXELFORMATDESCRIPTOR ppfd);

  రకనిర్వచనం UINT (CALLBACK *LPFNDEVMODE)(HWND,HMODULE,LPDEVMODE,LPSTR,LPSTR,LPDEVMODE,LPSTR,UINT);
  రకనిర్వచనం DWORD (CALLBACK *LPFNDEVCAPS)(LPSTR,LPSTR,UINT,LPSTR,LPDEVMODE);

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
#నిర్వచించు DC_BINADJUST 19
#నిర్వచించు DC_EMF_COMPLIANT 20
#నిర్వచించు DC_DATATYPE_PRODUCED 21
#నిర్వచించు DC_COLLATE 22
#నిర్వచించు DC_MANUFACTURER 23
#నిర్వచించు DC_MODEL 24
#నిర్వచించు DC_PERSONALITY 25
#నిర్వచించు DC_PRINTRATE 26
#నిర్వచించు DC_PRINTRATEUNIT 27
#నిర్వచించు PRINTRATEUNIT_PPM 1
#నిర్వచించు PRINTRATEUNIT_CPS 2
#నిర్వచించు PRINTRATEUNIT_LPM 3
#నిర్వచించు PRINTRATEUNIT_IPM 4
#నిర్వచించు DC_PRINTERMEM 28
#నిర్వచించు DC_MEDIAREADY 29
#నిర్వచించు DC_STAPLE 30
#నిర్వచించు DC_PRINTRATEPPM 31
#నిర్వచించు DC_COLORDEVICE 32
#నిర్వచించు DC_NUP 33
#నిర్వచించు DC_MEDIATYPENAMES 34
#నిర్వచించు DC_MEDIATYPES 35

#నిర్వచించు DCTT_BITMAP 0x0000001L
#నిర్వచించు DCTT_DOWNLOAD 0x0000002L
#నిర్వచించు DCTT_SUBDEV 0x0000004L
#నిర్వచించు DCTT_DOWNLOAD_OUTLINE 0x0000008L

#నిర్వచించు DCBA_FACEUPNONE 0x0000
#నిర్వచించు DCBA_FACEUPCENTER 0x0001
#నిర్వచించు DCBA_FACEUPLEFT 0x0002
#నిర్వచించు DCBA_FACEUPRIGHT 0x0003
#నిర్వచించు DCBA_FACEDOWNNONE 0x0100
#నిర్వచించు DCBA_FACEDOWNCENTER 0x0101
#నిర్వచించు DCBA_FACEDOWNLEFT 0x0102
#నిర్వచించు DCBA_FACEDOWNRIGHT 0x0103

#నిర్వచితమైతే UNICODE
#నిర్వచించు DeviceCapabilities DeviceCapabilitiesW
#నిర్వచించు EnumFontFamiliesEx EnumFontFamiliesExW
#నిర్వచించు EnumFontFamilies EnumFontFamiliesW
#నిర్వచించు EnumFonts EnumFontsW
#నిర్వచించు Get_Char_వెడల్పు Get_Char_వెడల్పు_W
#నిర్వచించు GetCharWidth32 GetCharWidth32W
#నిర్వచించు Get_Char_వెడల్పు_Float Get_Char_వెడల్పు_Float_W
#నిర్వచించు GetCharABCWidths GetCharABCWidthsW
#నిర్వచించు GetCharABCWidthsFloat GetCharABCWidthsFloatW
#నిర్వచించు GetGlyphOutline GetGlyphOutlineW
#నిర్వచించు GetMetaFile GetMetaFileW
#లేకపోతే
#నిర్వచించు DeviceCapabilities DeviceCapabilitiesA
#నిర్వచించు EnumFontFamiliesEx EnumFontFamiliesExA
#నిర్వచించు EnumFontFamilies EnumFontFamiliesA
#నిర్వచించు EnumFonts EnumFontsA
#నిర్వచించు Get_Char_వెడల్పు Get_Char_వెడల్పు_A
#నిర్వచించు GetCharWidth32 GetCharWidth32A
#నిర్వచించు Get_Char_వెడల్పు_Float Get_Char_వెడల్పు_Float_A
#నిర్వచించు GetCharABCWidths GetCharABCWidthsA
#నిర్వచించు GetCharABCWidthsFloat GetCharABCWidthsFloatA
#నిర్వచించు GetGlyphOutline GetGlyphOutlineA
#నిర్వచించు GetMetaFile GetMetaFileA
#అయితే_ముగింపు

  WINSPOOLAPI పూర్ణాంకం WINAPI DeviceCapabilitiesA(LPCSTR pDevice,LPCSTR p_పోర్టు,మాట_3 fwCapability,LPSTR pOutput,CONST DEVMODEA *p_Dev_బహుళకం);
  WINSPOOLAPI పూర్ణాంకం WINAPI DeviceCapabilitiesW(LPCWSTR pDevice,LPCWSTR p_పోర్టు,మాట_3 fwCapability,LPWSTR pOutput,CONST DEVMODEW *p_Dev_బహుళకం);
  WINGDIAPI పూర్ణాంకం WINAPI DrawEscape(HDC hdc,పూర్ణాంకం iEscape,పూర్ణాంకం cj_లోపల,LPCSTR lp_లోపల);
  WINGDIAPI WINBOOL WINAPI Ellipse(HDC hdc,పూర్ణాంకం ఎడమ,పూర్ణాంకం శిఖరం,పూర్ణాంకం కుడి,పూర్ణాంకం bottom);
  WINGDIAPI పూర్ణాంకం WINAPI EnumFontFamiliesExA(HDC hdc,LPLOGFONTA lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI పూర్ణాంకం WINAPI EnumFontFamiliesExW(HDC hdc,LPLOGFONTW lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI పూర్ణాంకం WINAPI EnumFontFamiliesA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI పూర్ణాంకం WINAPI EnumFontFamiliesW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI పూర్ణాంకం WINAPI EnumFontsA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI పూర్ణాంకం WINAPI EnumFontsW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI పూర్ణాంకం WINAPI EnumObjects(HDC hdc,పూర్ణాంకం nType,GOBJENUMPROC lpFunc,LPARAM lParam);
  WINGDIAPI WINBOOL WINAPI EqualRgn(HRGN hrgn1,HRGN hrgn2);
  WINGDIAPI పూర్ణాంకం WINAPI Escape(HDC hdc,పూర్ణాంకం iEscape,పూర్ణాంకం cj_లోపల,LPCSTR pv_లోపల,LPVOID pv_బహిర్గతం);
  WINGDIAPI పూర్ణాంకం WINAPI ExtEscape(HDC hdc,పూర్ణాంకం iEscape,పూర్ణాంకం cj_ఆదానం,LPCSTR lp_లోపల_దత్తాంశం,పూర్ణాంకం cjOutput,LPSTR lp_బహిర్గతం_దత్తాంశం);
  WINGDIAPI పూర్ణాంకం WINAPI ExcludeClipRect(HDC hdc,పూర్ణాంకం ఎడమ,పూర్ణాంకం శిఖరం,పూర్ణాంకం కుడి,పూర్ణాంకం bottom);
  WINGDIAPI HRGN WINAPI ExtCreateRegion(CONST XFORM *lpx,DWORD n_లెక్క,CONST RGNDATA *lp_దత్తాంశం);
  WINGDIAPI WINBOOL WINAPI ExtFloodFill(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,COLORREF color,UINT type);
  WINGDIAPI WINBOOL WINAPI FillRgn(HDC hdc,HRGN hrgn,HBRUSH hbr);
  WINGDIAPI WINBOOL WINAPI FloodFill(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI చట్రం_Rgn(HDC hdc,HRGN hrgn,HBRUSH hbr,పూర్ణాంకం w,పూర్ణాంకం h);
  WINGDIAPI పూర్ణాంకం WINAPI GetROP2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_Aspect_నిష్పత్తి_Filter_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI COLORREF WINAPI GetBkColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCBrushColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCPenColor(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI Get_Bk_బహుళకం(HDC hdc);
  WINGDIAPI LONG WINAPI Get_Bitmap_బిట్లు(HBITMAP hbit,LONG cb,LPVOID lpv_బిట్లు);
  WINGDIAPI WINBOOL WINAPI GetBitmapDimensionEx(HBITMAP hbit,LPSIZE lpsize);
  WINGDIAPI UINT WINAPI GetBoundsRect(HDC hdc,LPRECT lprect,UINT flags);
  WINGDIAPI WINBOOL WINAPI GetBrushOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI Get_Char_వెడల్పు_A(HDC hdc,UINT i_మొదటి,UINT i_చివరి,LPINT lp_బఫరు);
  WINGDIAPI WINBOOL WINAPI Get_Char_వెడల్పు_W(HDC hdc,UINT i_మొదటి,UINT i_చివరి,LPINT lp_బఫరు);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32A(HDC hdc,UINT i_మొదటి,UINT i_చివరి,LPINT lp_బఫరు);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32W(HDC hdc,UINT i_మొదటి,UINT i_చివరి,LPINT lp_బఫరు);
  WINGDIAPI WINBOOL WINAPI Get_Char_వెడల్పు_Float_A(HDC hdc,UINT i_మొదటి,UINT i_చివరి,PFLOAT lp_బఫరు);
  WINGDIAPI WINBOOL WINAPI Get_Char_వెడల్పు_Float_W(HDC hdc,UINT i_మొదటి,UINT i_చివరి,PFLOAT lp_బఫరు);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsA(HDC hdc,UINT w_మొదటి,UINT w_చివరి,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsW(HDC hdc,UINT w_మొదటి,UINT w_చివరి,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatA(HDC hdc,UINT i_మొదటి,UINT i_చివరి,LPABCFLOAT lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatW(HDC hdc,UINT i_మొదటి,UINT i_చివరి,LPABCFLOAT lpABC);
  WINGDIAPI పూర్ణాంకం WINAPI GetClipBox(HDC hdc,LPRECT lprect);
  WINGDIAPI పూర్ణాంకం WINAPI GetClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI పూర్ణాంకం WINAPI GetMetaRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI HGDIOBJ WINAPI GetCurrentObject(HDC hdc,UINT type);
  WINGDIAPI WINBOOL WINAPI GetCurrentPositionEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI పూర్ణాంకం WINAPI GetDeviceCaps(HDC hdc,పూర్ణాంకం సూచీ);
  WINGDIAPI పూర్ణాంకం WINAPI GetDIBits(HDC hdc,HBITMAP hbm,UINT ప్రారంభం,UINT c_పంక్తులు,LPVOID lpv_బిట్లు,LPBITMAPINFO lpbmi,UINT usage);
  WINGDIAPI DWORD WINAPI Get_Font_దత్తాంశం (HDC hdc,DWORD dw_పట్టిక,DWORD dw_స్థానభ్రంశం,PVOID pv_బఫరు,DWORD cj_బఫరు);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineA(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_బఫరు,LPVOID pv_బఫరు,CONST MAT2 *lpmat2);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineW(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_బఫరు,LPVOID pv_బఫరు,CONST MAT2 *lpmat2);
  WINGDIAPI పూర్ణాంకం WINAPI Get_Graphics_బహుళకం(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI Get_Map_బహుళకం(HDC hdc);
  WINGDIAPI UINT WINAPI Get_Meta_File_బిట్లు_Ex(HMETAFILE hMF,UINT cb_బఫరు,LPVOID lp_దత్తాంశం);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileA(LPCSTR lpName);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileW(LPCWSTR lpName);
  WINGDIAPI COLORREF WINAPI Get_సమీప_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI Get_సమీప_Palette_సూచీ(HPALETTE h,COLORREF color);
  WINGDIAPI DWORD WINAPI GetObjectType(HGDIOBJ h);

#నిర్వచితం_కాకపోతే NOTEXTMETRIC
#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_Outline_పాఠ్యం_Metrics Get_Outline_పాఠ్యం_Metrics_W
#లేకపోతే
#నిర్వచించు Get_Outline_పాఠ్యం_Metrics Get_Outline_పాఠ్యం_Metrics_A
#అయితే_ముగింపు

  WINGDIAPI UINT WINAPI Get_Outline_పాఠ్యం_Metrics_A(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICA potm);
  WINGDIAPI UINT WINAPI Get_Outline_పాఠ్యం_Metrics_W(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICW potm);
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_పాఠ్యం_Extent_బిందువు Get_పాఠ్యం_Extent_బిందువు_W
#నిర్వచించు Get_పాఠ్యం_Extent_Point32 Get_పాఠ్యం_Extent_Point32_W
#నిర్వచించు Get_పాఠ్యం_Extent_Ex_బిందువు Get_పాఠ్యం_Extent_Ex_బిందువు_W
#నిర్వచించు GetCharacterPlacement GetCharacterPlacementW
#లేకపోతే
#నిర్వచించు Get_పాఠ్యం_Extent_బిందువు Get_పాఠ్యం_Extent_బిందువు_A
#నిర్వచించు Get_పాఠ్యం_Extent_Point32 Get_పాఠ్యం_Extent_Point32_A
#నిర్వచించు Get_పాఠ్యం_Extent_Ex_బిందువు Get_పాఠ్యం_Extent_Ex_బిందువు_A
#నిర్వచించు GetCharacterPlacement GetCharacterPlacementA
#అయితే_ముగింపు

  WINGDIAPI UINT WINAPI GetPaletteEntries(HPALETTE hpal,UINT i_ప్రారంభం,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI COLORREF WINAPI GetPixel(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y);
  WINGDIAPI పూర్ణాంకం WINAPI GetPixelFormat(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI Get_Poly_Fill_బహుళకం(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetRasterizerCaps(LPRASTERIZER_స్థితి lpraststat,UINT cj_బైట్లు);
  WINGDIAPI పూర్ణాంకం WINAPI GetRandomRgn (HDC hdc,HRGN hrgn,INT i);
  WINGDIAPI DWORD WINAPI Get_Region_దత్తాంశం(HRGN hrgn,DWORD n_లెక్క,LPRGNDATA lp_Rgn_దత్తాంశం);
  WINGDIAPI పూర్ణాంకం WINAPI GetRgnBox(HRGN hrgn,LPRECT lprc);
  WINGDIAPI HGDIOBJ WINAPI GetStockObject(పూర్ణాంకం i);
  WINGDIAPI పూర్ణాంకం WINAPI Get_Stretch_Blt_బహుళకం(HDC hdc);
  WINGDIAPI UINT WINAPI GetSystemPaletteEntries(HDC hdc,UINT i_ప్రారంభం,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI UINT WINAPI GetSystemPaletteUse(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI Get_పాఠ్యం_Character_Extra(HDC hdc);
  WINGDIAPI UINT WINAPI Get_పాఠ్యం_Align(HDC hdc);
  WINGDIAPI COLORREF WINAPI Get_పాఠ్యం_Color(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Extent_బిందువు_A(HDC hdc,LPCSTR lpString,పూర్ణాంకం c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Extent_బిందువు_W(HDC hdc,LPCWSTR lpString,పూర్ణాంకం c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Extent_Point32_A(HDC hdc,LPCSTR lpString,పూర్ణాంకం c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Extent_Point32_W(HDC hdc,LPCWSTR lpString,పూర్ణాంకం c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Extent_Ex_బిందువు_A(HDC hdc,LPCSTR lpszString,పూర్ణాంకం cchString,పూర్ణాంకం nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_కొలత);
  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Extent_Ex_బిందువు_W(HDC hdc,LPCWSTR lpszString,పూర్ణాంకం cchString,పూర్ణాంకం nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_కొలత);
  WINGDIAPI పూర్ణాంకం WINAPI Get_పాఠ్యం_Charset(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI Get_పాఠ్యం_Charset_Info(HDC hdc,LPFONTSIGNATURE lpSig,DWORD dwFlags);
  WINGDIAPI WINBOOL WINAPI TranslateCharsetInfo(DWORD *lpSrc,LPCHARSETINFO lpCs,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetFontLanguageInfo(HDC hdc);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementA(HDC hdc,LPCSTR lpString,పూర్ణాంకం n_లెక్క,పూర్ణాంకం nMexExtent,LPGCP_RESULTSA lpResults,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementW(HDC hdc,LPCWSTR lpString,పూర్ణాంకం n_లెక్క,పూర్ణాంకం nMexExtent,LPGCP_RESULTSW lpResults,DWORD dwFlags);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_WCRANGE {
    WCHAR wc_దిగువ;
    USHORT cGlyphs;
  } WCRANGE,*PWCRANGE,*LPWCRANGE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_GLYPHSET {
    DWORD cbThis;
    DWORD flAccel;
    DWORD cGlyphsSupported;
    DWORD cRanges;
    WCRANGE ranges[1];
  } GLYPHSET,*PGLYPHSET,*LPGLYPHSET;

#నిర్వచించు GS_8_బిట్టు_INDICES 0x00000001

#నిర్వచించు GGI_MARK_NONEXISTING_GLYPHS 0X0001

#నిర్వచితమైతే UNICODE
#నిర్వచించు GetGlyphIndices GetGlyphIndicesW
#లేకపోతే
#నిర్వచించు GetGlyphIndices GetGlyphIndicesA
#అయితే_ముగింపు

  WINGDIAPI DWORD WINAPI GetFontUnicodeRanges(HDC hdc,LPGLYPHSET lpgs);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesA(HDC hdc,LPCSTR lpstr,పూర్ణాంకం c,LPWORD pgi,DWORD fl);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesW(HDC hdc,LPCWSTR lpstr,పూర్ణాంకం c,LPWORD pgi,DWORD fl);
  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Extent_బిందువు_I(HDC hdc,LPWORD pgi_లోపల,పూర్ణాంకం cgi,LPSIZE psize);
  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Extent_Ex_బిందువు_I (HDC hdc,LPWORD lpwszString,పూర్ణాంకం cwchString,పూర్ణాంకం nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_కొలత);
  WINGDIAPI WINBOOL WINAPI Get_Char_వెడల్పు_I(HDC hdc,UINT gi_మొదటి,UINT cgi,LPWORD pgi,LPINT piWidths);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsI(HDC hdc,UINT gi_మొదటి,UINT cgi,LPWORD pgi,LPABC pabc);

#నిర్వచించు STAMP_DESIGNVECTOR (0x8000000 + 'd' + ('v' << 8))
#నిర్వచించు STAMP_AXESLIST (0x8000000 + 'a' + ('l' << 8))
#నిర్వచించు MM_MAX_NUMAXES 16

  రకనిర్వచనం నిర్మాణం ట్యాగ్_DESIGNVECTOR {
    DWORD dvReserved;
    DWORD dv_అంకె_Axes;
    LONG dv_విలువలు[MM_MAX_NUMAXES];
  } DESIGNVECTOR,*PDESIGNVECTOR,*LPDESIGNVECTOR;

#నిర్వచితమైతే UNICODE
#నిర్వచించు కూడు_Font_Resource_Ex కూడు_Font_Resource_Ex_W
#నిర్వచించు RemoveFontResourceEx RemoveFontResourceExW
#లేకపోతే
#నిర్వచించు కూడు_Font_Resource_Ex కూడు_Font_Resource_Ex_A
#నిర్వచించు RemoveFontResourceEx RemoveFontResourceExA
#అయితే_ముగింపు

  WINGDIAPI పూర్ణాంకం WINAPI కూడు_Font_Resource_Ex_A(LPCSTR name,DWORD fl,PVOID res);
  WINGDIAPI పూర్ణాంకం WINAPI కూడు_Font_Resource_Ex_W(LPCWSTR name,DWORD fl,PVOID res);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExA(LPCSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExW(LPCWSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI HANDLE WINAPI కూడు_Font_Mem_Resource_Ex(PVOID pFileView,DWORD cj_కొలత,PVOID pvResrved,DWORD *p_అంకె_Fonts);
  WINGDIAPI WINBOOL WINAPI RemoveFontMemResourceEx(HANDLE h);

#నిర్వచించు FR_వ్యక్తిగత 0x10
#నిర్వచించు FR_NOT_ENUM 0x20

#నిర్వచించు MM_MAX_AXES_NAMELEN 16

  రకనిర్వచనం నిర్మాణం ట్యాగ్_AXISINFOA {
    LONG ax_Min_విలువ;
    LONG ax_Max_విలువ;
    BYTE axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOA,*PAXISINFOA,*LPAXISINFOA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_AXISINFOW {
    LONG ax_Min_విలువ;
    LONG ax_Max_విలువ;
    WCHAR axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOW,*PAXISINFOW,*LPAXISINFOW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం AXISINFOW AXISINFO;
  రకనిర్వచనం PAXISINFOW PAXISINFO;
  రకనిర్వచనం LPAXISINFOW LPAXISINFO;
#లేకపోతే
  రకనిర్వచనం AXISINFOA AXISINFO;
  రకనిర్వచనం PAXISINFOA PAXISINFO;
  రకనిర్వచనం LPAXISINFOA LPAXISINFO;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_AXESLISTA {
    DWORD axlReserved;
    DWORD axl_అంకె_Axes;
    AXISINFOA axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTA,*PAXESLISTA,*LPAXESLISTA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_AXESLISTW {
    DWORD axlReserved;
    DWORD axl_అంకె_Axes;
    AXISINFOW axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTW,*PAXESLISTW,*LPAXESLISTW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం AXESLISTW AXESLIST;
  రకనిర్వచనం PAXESLISTW PAXESLIST;
  రకనిర్వచనం LPAXESLISTW LPAXESLIST;
#లేకపోతే
  రకనిర్వచనం AXESLISTA AXESLIST;
  రకనిర్వచనం PAXESLISTA PAXESLIST;
  రకనిర్వచనం LPAXESLISTA LPAXESLIST;
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENUMLOGFONTEXDVA {
    ENUMLOGFONTEXA elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_సదిశ;
  } ENUMLOGFONTEXDVA,*PENUMLOGFONTEXDVA,*LPENUMLOGFONTEXDVA;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENUMLOGFONTEXDVW {
    ENUMLOGFONTEXW elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_సదిశ;
  } ENUMLOGFONTEXDVW,*PENUMLOGFONTEXDVW,*LPENUMLOGFONTEXDVW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం ENUMLOGFONTEXDVW ENUMLOGFONTEXDV;
  రకనిర్వచనం PENUMLOGFONTEXDVW PENUMLOGFONTEXDV;
  రకనిర్వచనం LPENUMLOGFONTEXDVW LPENUMLOGFONTEXDV;
#లేకపోతే
  రకనిర్వచనం ENUMLOGFONTEXDVA ENUMLOGFONTEXDV;
  రకనిర్వచనం PENUMLOGFONTEXDVA PENUMLOGFONTEXDV;
  రకనిర్వచనం LPENUMLOGFONTEXDVA LPENUMLOGFONTEXDV;
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు Create_Font_పరోక్ష_Ex Create_Font_పరోక్ష_Ex_W
#లేకపోతే
#నిర్వచించు Create_Font_పరోక్ష_Ex Create_Font_పరోక్ష_Ex_A
#అయితే_ముగింపు

  WINGDIAPI HFONT WINAPI Create_Font_పరోక్ష_Ex_A(CONST ENUMLOGFONTEXDVA *);
  WINGDIAPI HFONT WINAPI Create_Font_పరోక్ష_Ex_W(CONST ENUMLOGFONTEXDVW *);

#నిర్వచితం_కాకపోతే NOTEXTMETRIC
  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENUMTEXTMETRICA {
    NEWTEXTMETRICEXA etm_New_పాఠ్యం_Metric_Ex;
    AXESLISTA etmAxesList;
  } ENUMTEXTMETRICA,*PENUMTEXTMETRICA,*LPENUMTEXTMETRICA;
  రకనిర్వచనం నిర్మాణం ట్యాగ్_ENUMTEXTMETRICW
  {
    NEWTEXTMETRICEXW etm_New_పాఠ్యం_Metric_Ex;
    AXESLISTW etmAxesList;
  } ENUMTEXTMETRICW,*PENUMTEXTMETRICW,*LPENUMTEXTMETRICW;
#నిర్వచితమైతే UNICODE
  రకనిర్వచనం ENUMTEXTMETRICW ENUMTEXTMETRIC;
  రకనిర్వచనం PENUMTEXTMETRICW PENUMTEXTMETRIC;
  రకనిర్వచనం LPENUMTEXTMETRICW LPENUMTEXTMETRIC;
#లేకపోతే
  రకనిర్వచనం ENUMTEXTMETRICA ENUMTEXTMETRIC;
  రకనిర్వచనం PENUMTEXTMETRICA PENUMTEXTMETRIC;
  రకనిర్వచనం LPENUMTEXTMETRICA LPENUMTEXTMETRIC;
#అయితే_ముగింపు
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు ResetDC ResetDCW
#నిర్వచించు RemoveFontResource RemoveFontResourceW
#లేకపోతే
#నిర్వచించు ResetDC ResetDCA
#నిర్వచించు RemoveFontResource RemoveFontResourceA
#అయితే_ముగింపు

  WINGDIAPI WINBOOL WINAPI GetViewportExtEx(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI GetViewportOrgEx(HDC hdc,LPPOINT lppoint);
  WINGDIAPI WINBOOL WINAPI Get_కిటికీ_Ext_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI Get_కిటికీ_Org_Ex(HDC hdc,LPPOINT lppoint);
  WINGDIAPI పూర్ణాంకం WINAPI IntersectClipRect(HDC hdc,పూర్ణాంకం ఎడమ,పూర్ణాంకం శిఖరం,పూర్ణాంకం కుడి,పూర్ణాంకం bottom);
  WINGDIAPI WINBOOL WINAPI InvertRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI పంక్తి_DDA(పూర్ణాంకం x_ప్రారంభం,పూర్ణాంకం y_ప్రారంభం,పూర్ణాంకం x_చివర,పూర్ణాంకం y_చివర,LINEDDAPROC lpProc,LPARAM దత్తాంశం);
  WINGDIAPI WINBOOL WINAPI పంక్తి_గమ్యం(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y);
  WINGDIAPI WINBOOL WINAPI ముసుగు_Blt(HDC hdcDest,పూర్ణాంకం xDest,పూర్ణాంకం yDest,పూర్ణాంకం వెడల్పు,పూర్ణాంకం ఎత్తు,HDC hdcSrc,పూర్ణాంకం xSrc,పూర్ణాంకం ySrc,HBITMAP hbm_ముసుగు,పూర్ణాంకం x_ముసుగు,పూర్ణాంకం y_ముసుగు,DWORD rop);
  WINGDIAPI WINBOOL WINAPI PlgBlt(HDC hdcDest,CONST బిందువు_3 *lp_బిందువు,HDC hdcSrc,పూర్ణాంకం xSrc,పూర్ణాంకం ySrc,పూర్ణాంకం వెడల్పు,పూర్ణాంకం ఎత్తు,HBITMAP hbm_ముసుగు,పూర్ణాంకం x_ముసుగు,పూర్ణాంకం y_ముసుగు);
  WINGDIAPI పూర్ణాంకం WINAPI స్థానభ్రంశం_Clip_Rgn(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y);
  WINGDIAPI పూర్ణాంకం WINAPI స్థానభ్రంశం_Rgn(HRGN hrgn,పూర్ణాంకం x,పూర్ణాంకం y);
  WINGDIAPI WINBOOL WINAPI PatBlt(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,పూర్ణాంకం w,పూర్ణాంకం h,DWORD rop);
  WINGDIAPI WINBOOL WINAPI Pie(HDC hdc,పూర్ణాంకం ఎడమ,పూర్ణాంకం శిఖరం,పూర్ణాంకం కుడి,పూర్ణాంకం bottom,పూర్ణాంకం xr1,పూర్ణాంకం yr1,పూర్ణాంకం xr2,పూర్ణాంకం yr2);
  WINGDIAPI WINBOOL WINAPI PlayMetaFile(HDC hdc,HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI PaintRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI PolyPolygon(HDC hdc,CONST బిందువు_3 *apt,CONST INT *asz,పూర్ణాంకం csz);
  WINGDIAPI WINBOOL WINAPI Pt_లోపల_Region(HRGN hrgn,పూర్ణాంకం x,పూర్ణాంకం y);
  WINGDIAPI WINBOOL WINAPI PtVisible(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y);
  WINGDIAPI WINBOOL WINAPI Rect_లోపల_Region(HRGN hrgn,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI RectVisible(HDC hdc,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Rectangle(HDC hdc,పూర్ణాంకం ఎడమ,పూర్ణాంకం శిఖరం,పూర్ణాంకం కుడి,పూర్ణాంకం bottom);
  WINGDIAPI WINBOOL WINAPI RestoreDC(HDC hdc,పూర్ణాంకం nSavedDC);
  WINGDIAPI HDC WINAPI ResetDCA(HDC hdc,CONST DEVMODEA *lpdm);
  WINGDIAPI HDC WINAPI ResetDCW(HDC hdc,CONST DEVMODEW *lpdm);
  WINGDIAPI UINT WINAPI RealizePalette(HDC hdc);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceA(LPCSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceW(LPCWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI విడత_Rect(HDC hdc,పూర్ణాంకం ఎడమ,పూర్ణాంకం శిఖరం,పూర్ణాంకం కుడి,పూర్ణాంకం bottom,పూర్ణాంకం వెడల్పు,పూర్ణాంకం ఎత్తు);
  WINGDIAPI WINBOOL WINAPI ResizePalette(HPALETTE hpal,UINT n);
  WINGDIAPI పూర్ణాంకం WINAPI SaveDC(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI SelectClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI పూర్ణాంకం WINAPI ExtSelectClipRgn(HDC hdc,HRGN hrgn,పూర్ణాంకం బహుళకం);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_Meta_Rgn(HDC hdc);
  WINGDIAPI HGDIOBJ WINAPI SelectObject(HDC hdc,HGDIOBJ h);
  WINGDIAPI HPALETTE WINAPI SelectPalette(HDC hdc,HPALETTE hPal,WINBOOL bForceBkgd);
  WINGDIAPI COLORREF WINAPI సమితి_Bk_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI సమితి_DCBrush_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI సమితి_DCPen_Color(HDC hdc,COLORREF color);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_Bk_బహుళకం(HDC hdc,పూర్ణాంకం బహుళకం);
  WINGDIAPI LONG WINAPI సమితి_Bitmap_బిట్లు(HBITMAP hbm,DWORD cb,CONST VOID *pv_బిట్లు);
  WINGDIAPI UINT WINAPI సమితి_Bounds_Rect(HDC hdc,CONST RECT *lprect,UINT flags);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_DIBits(HDC hdc,HBITMAP hbm,UINT ప్రారంభం,UINT c_పంక్తులు,CONST VOID *lp_బిట్లు,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_DIBits_గమ్యం_Device(HDC hdc,పూర్ణాంకం xDest,పూర్ణాంకం yDest,DWORD w,DWORD h,పూర్ణాంకం xSrc,పూర్ణాంకం ySrc,UINT ప్రారంభం_పరిశీలన,UINT c_పంక్తులు,CONST VOID *lpv_బిట్లు,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI DWORD WINAPI సమితి_Mapper_Flags(HDC hdc,DWORD flags);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_Graphics_బహుళకం(HDC hdc,పూర్ణాంకం i_బహుళకం);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_Map_బహుళకం(HDC hdc,పూర్ణాంకం i_బహుళకం);
  WINGDIAPI DWORD WINAPI సమితి_Layout(HDC hdc,DWORD l);
  WINGDIAPI DWORD WINAPI GetLayout(HDC hdc);
  WINGDIAPI HMETAFILE WINAPI సమితి_Meta_File_బిట్లు_Ex(UINT cb_బఫరు,CONST BYTE *lp_దత్తాంశం);
  WINGDIAPI UINT WINAPI సమితి_Palette_Entries(HPALETTE hpal,UINT i_ప్రారంభం,UINT cEntries,CONST PALETTEENTRY *pPalEntries);
  WINGDIAPI COLORREF WINAPI సమితి_Pixel(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI సమితి_Pixel_V(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI సమితి_Pixel_Format(HDC hdc,పూర్ణాంకం format,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_Poly_Fill_బహుళకం(HDC hdc,పూర్ణాంకం బహుళకం);
  WINGDIAPI WINBOOL WINAPI StretchBlt(HDC hdcDest,పూర్ణాంకం xDest,పూర్ణాంకం yDest,పూర్ణాంకం wDest,పూర్ణాంకం hDest,HDC hdcSrc,పూర్ణాంకం xSrc,పూర్ణాంకం ySrc,పూర్ణాంకం wSrc,పూర్ణాంకం hSrc,DWORD rop);
  WINGDIAPI WINBOOL WINAPI సమితి_Rect_Rgn(HRGN hrgn,పూర్ణాంకం ఎడమ,పూర్ణాంకం శిఖరం,పూర్ణాంకం కుడి,పూర్ణాంకం bottom);
  WINGDIAPI పూర్ణాంకం WINAPI StretchDIBits(HDC hdc,పూర్ణాంకం xDest,పూర్ణాంకం yDest,పూర్ణాంకం Dest_వెడల్పు,పూర్ణాంకం Dest_ఎత్తు,పూర్ణాంకం xSrc,పూర్ణాంకం ySrc,పూర్ణాంకం Src_వెడల్పు,పూర్ణాంకం Src_ఎత్తు,CONST VOID *lp_బిట్లు,CONST BITMAPINFO *lpbmi,UINT iUsage,DWORD rop);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_ROP2(HDC hdc,పూర్ణాంకం rop2);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_Stretch_Blt_బహుళకం(HDC hdc,పూర్ణాంకం బహుళకం);
  WINGDIAPI UINT WINAPI సమితి_System_Palette_Use(HDC hdc,UINT use);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_పాఠ్యం_Character_Extra(HDC hdc,పూర్ణాంకం extra);
  WINGDIAPI COLORREF WINAPI సమితి_పాఠ్యం_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI సమితి_పాఠ్యం_Align(HDC hdc,UINT align);
  WINGDIAPI WINBOOL WINAPI సమితి_పాఠ్యం_Justification(HDC hdc,పూర్ణాంకం extra,పూర్ణాంకం లెక్క_2);
  WINGDIAPI WINBOOL WINAPI UpdateColors(HDC hdc);

  రకనిర్వచనం USHORT COLOR16;

  రకనిర్వచనం నిర్మాణం _TRIVERTEX {
    LONG x;
    LONG y;
    COLOR16 Red;
    COLOR16 Green;
    COLOR16 Blue;
    COLOR16 Alpha;
  } TRIVERTEX,*PTRIVERTEX,*LPTRIVERTEX;

  రకనిర్వచనం నిర్మాణం _GRADIENT_TRIANGLE {
    ULONG Vertex1;
    ULONG Vertex2;
    ULONG Vertex3;
  } GRADIENT_TRIANGLE,*PGRADIENT_TRIANGLE,*LPGRADIENT_TRIANGLE;

  రకనిర్వచనం నిర్మాణం _GRADIENT_RECT {
    ULONG పై_ఎడమ;
    ULONG క్రింది_కుడి;
  } GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;

  రకనిర్వచనం నిర్మాణం _BLENDFUNCTION {
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE ఆధారం_Constant_Alpha;
    BYTE AlphaFormat;
  } BLENDFUNCTION,*PBLENDFUNCTION;

#నిర్వచించు AC_SRC_OVER 0x00
#నిర్వచించు AC_SRC_ALPHA 0x01

  WINGDIAPI WINBOOL WINAPI AlphaBlend(HDC hdcDest,పూర్ణాంకం xoriginDest,పూర్ణాంకం yoriginDest,పూర్ణాంకం wDest,పూర్ణాంకం hDest,HDC hdcSrc,పూర్ణాంకం xoriginSrc,పూర్ణాంకం yoriginSrc,పూర్ణాంకం wSrc,పూర్ణాంకం hSrc,BLENDFUNCTION ftn);
  WINGDIAPI WINBOOL WINAPI TransparentBlt(HDC hdcDest,పూర్ణాంకం xoriginDest,పూర్ణాంకం yoriginDest,పూర్ణాంకం wDest,పూర్ణాంకం hDest,HDC hdcSrc,పూర్ణాంకం xoriginSrc,పూర్ణాంకం yoriginSrc,పూర్ణాంకం wSrc,పూర్ణాంకం hSrc,UINT crTransparent);

#నిర్వచించు GRADIENT_FILL_RECT_H 0x00000000
#నిర్వచించు GRADIENT_FILL_RECT_V 0x00000001
#నిర్వచించు GRADIENT_FILL_TRIANGLE 0x00000002
#నిర్వచించు GRADIENT_FILL_OP_FLAG 0x000000ff

  WINGDIAPI WINBOOL WINAPI GradientFill(HDC hdc,PTRIVERTEX p_శీర్షం,ULONG n_శీర్షం,PVOID pMesh,ULONG nMesh,ULONG ul_బహుళకం);

#నిర్వచితం_కాకపోతే NOMETAFILE

#నిర్వచితమైతే UNICODE
#నిర్వచించు CopyEnhMetaFile CopyEnhMetaFileW
#నిర్వచించు CreateEnhMetaFile CreateEnhMetaFileW
#నిర్వచించు GetEnhMetaFile GetEnhMetaFileW
#నిర్వచించు GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#లేకపోతే
#నిర్వచించు CopyEnhMetaFile CopyEnhMetaFileA
#నిర్వచించు CreateEnhMetaFile CreateEnhMetaFileA
#నిర్వచించు GetEnhMetaFile GetEnhMetaFileA
#నిర్వచించు GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#అయితే_ముగింపు

  WINGDIAPI WINBOOL WINAPI Play_Meta_File_రికార్డు(HDC hdc,LPHANDLETABLE lp_Handle_పట్టిక,LPMETARECORD lpMR,UINT noObjs);

  రకనిర్వచనం పూర్ణాంకం (CALLBACK *MFENUMPROC)(HDC hdc,HANDLETABLE *lpht,METARECORD *lpMR,పూర్ణాంకం nObj,LPARAM param);

  WINGDIAPI WINBOOL WINAPI EnumMetaFile(HDC hdc,HMETAFILE hmf,MFENUMPROC proc,LPARAM param);

  రకనిర్వచనం పూర్ణాంకం (CALLBACK *ENHMFENUMPROC)(HDC hdc,HANDLETABLE *lpht,CONST ENHMETARECORD *lpmr,పూర్ణాంకం hHandles,LPARAM దత్తాంశం);

  WINGDIAPI HENHMETAFILE WINAPI CloseEnhMetaFile(HDC hdc);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileA(HENHMETAFILE hEnh,LPCSTR lpFileName);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileW(HENHMETAFILE hEnh,LPCWSTR lpFileName);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileA(HDC hdc,LPCSTR lpFilename,CONST RECT *lprc,LPCSTR lpDesc);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileW(HDC hdc,LPCWSTR lpFilename,CONST RECT *lprc,LPCWSTR lpDesc);
  WINGDIAPI WINBOOL WINAPI DeleteEnhMetaFile(HENHMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI EnumEnhMetaFile(HDC hdc,HENHMETAFILE hmf,ENHMFENUMPROC proc,LPVOID param,CONST RECT *lpRect);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileA(LPCSTR lpName);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileW(LPCWSTR lpName);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_బిట్లు(HENHMETAFILE hEMF,UINT n_కొలత,LPBYTE lp_దత్తాంశం);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE hemf,UINT cch_బఫరు,LPSTR lpDescription);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE hemf,UINT cch_బఫరు,LPWSTR lpDescription);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_శీర్షిక(HENHMETAFILE hemf,UINT n_కొలత,LPENHMETAHEADER lp_Enh_Meta_శీర్షిక);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT n_అంకె_Entries,LPPALETTEENTRY lpPaletteEntries);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePixelFormat(HENHMETAFILE hemf,UINT cb_బఫరు,PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI UINT WINAPI Get_Win_Meta_File_బిట్లు(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT i_Map_బహుళకం,HDC hdcRef);
  WINGDIAPI WINBOOL WINAPI PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Play_Enh_Meta_File_రికార్డు(HDC hdc,LPHANDLETABLE pht,CONST ENHMETARECORD *pmr,UINT cht);
  WINGDIAPI HENHMETAFILE WINAPI సమితి_Enh_Meta_File_బిట్లు(UINT n_కొలత,CONST BYTE *pb);
  WINGDIAPI HENHMETAFILE WINAPI సమితి_Win_Meta_File_బిట్లు(UINT n_కొలత,CONST BYTE *lp_Meta16_దత్తాంశం,HDC hdcRef,CONST METAFILEPICT *lpMFP);
  WINGDIAPI WINBOOL WINAPI GdiComment(HDC hdc,UINT n_కొలత,CONST BYTE *lp_దత్తాంశం);
#అయితే_ముగింపు

#నిర్వచితం_కాకపోతే NOTEXTMETRIC
#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_పాఠ్యం_Metrics Get_పాఠ్యం_Metrics_W
#లేకపోతే
#నిర్వచించు Get_పాఠ్యం_Metrics Get_పాఠ్యం_Metrics_A
#అయితే_ముగింపు

  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Metrics_A(HDC hdc,LPTEXTMETRICA lptm);
  WINGDIAPI WINBOOL WINAPI Get_పాఠ్యం_Metrics_W(HDC hdc,LPTEXTMETRICW lptm);
#అయితే_ముగింపు

  రకనిర్వచనం నిర్మాణం ట్యాగ్_DIBSECTION {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD ds_స్థానభ్రంశం;
  } DIBSECTION,*LPDIBSECTION,*PDIBSECTION;

  WINGDIAPI WINBOOL WINAPI AngleArc(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,DWORD r,FLOAT ప్రారంభం_Angle,FLOAT SweepAngle);
  WINGDIAPI WINBOOL WINAPI PolyPolyline(HDC hdc,CONST బిందువు_3 *apt,CONST DWORD *asz,DWORD csz);
  WINGDIAPI WINBOOL WINAPI GetWorldTransform(HDC hdc,LPXFORM lpxf);
  WINGDIAPI WINBOOL WINAPI సమితి_World_Transform(HDC hdc,CONST XFORM *lpxf);
  WINGDIAPI WINBOOL WINAPI ModifyWorldTransform(HDC hdc,CONST XFORM *lpxf,DWORD బహుళకం);
  WINGDIAPI WINBOOL WINAPI CombineTransform(LPXFORM lpxf_బహిర్గతం,CONST XFORM *lpxf1,CONST XFORM *lpxf2);
  WINGDIAPI HBITMAP WINAPI CreateDIBSection(HDC hdc,CONST BITMAPINFO *lpbmi,UINT usage,VOID **ppv_బిట్లు,HANDLE hSection,DWORD స్థానభ్రంశం);
  WINGDIAPI UINT WINAPI Get_DIBColor_పట్టిక(HDC hdc,UINT i_ప్రారంభం,UINT cEntries,RGBQUAD *prgbq);
  WINGDIAPI UINT WINAPI సమితి_DIBColor_పట్టిక(HDC hdc,UINT i_ప్రారంభం,UINT cEntries,CONST RGBQUAD *prgbq);

#నిర్వచించు CA_NEGATIVE 0x0001
#నిర్వచించు CA_LOG_FILTER 0x0002

#నిర్వచించు ILLUMINANT_DEVICE_DEFAULT 0
#నిర్వచించు ILLUMINANT_A 1
#నిర్వచించు ILLUMINANT_B 2
#నిర్వచించు ILLUMINANT_C 3
#నిర్వచించు ILLUMINANT_D50 4
#నిర్వచించు ILLUMINANT_D55 5
#నిర్వచించు ILLUMINANT_D65 6
#నిర్వచించు ILLUMINANT_D75 7
#నిర్వచించు ILLUMINANT_F2 8
#నిర్వచించు ILLUMINANT_MAX_సూచీ ILLUMINANT_F2

#నిర్వచించు ILLUMINANT_TUNGSTEN ILLUMINANT_A
#నిర్వచించు ILLUMINANT_DAYLIGHT ILLUMINANT_C
#నిర్వచించు ILLUMINANT_FLUORESCENT ILLUMINANT_F2
#నిర్వచించు ILLUMINANT_NTSC ILLUMINANT_C

#నిర్వచించు RGB_GAMMA_MIN (మాట_3)02500
#నిర్వచించు RGB_GAMMA_MAX (మాట_3)65000

#నిర్వచించు REFERENCE_WHITE_MIN (మాట_3)6000
#నిర్వచించు REFERENCE_WHITE_MAX (మాట_3)10000
#నిర్వచించు REFERENCE_BLACK_MIN (మాట_3)0
#నిర్వచించు REFERENCE_BLACK_MAX (మాట_3)4000

#నిర్వచించు COLOR_ADJ_MIN (SHORT)-100
#నిర్వచించు COLOR_ADJ_MAX (SHORT)100

  రకనిర్వచనం నిర్మాణం ట్యాగ్_COLORADJUSTMENT {
    మాట_3 ca_కొలత;
    మాట_3 caFlags;
    మాట_3 ca_Illuminant_సూచీ;
    మాట_3 caRedGamma;
    మాట_3 caGreenGamma;
    మాట_3 caBlueGamma;
    మాట_3 caReferenceBlack;
    మాట_3 caReferenceWhite;
    SHORT caContrast;
    SHORT caBrightness;
    SHORT caColorfulness;
    SHORT caRedGreenTint;
  } COLORADJUSTMENT,*PCOLORADJUSTMENT,*LPCOLORADJUSTMENT;

  WINGDIAPI WINBOOL WINAPI సమితి_Color_Adjustment(HDC hdc,CONST COLORADJUSTMENT *lpca);
  WINGDIAPI WINBOOL WINAPI GetColorAdjustment(HDC hdc,LPCOLORADJUSTMENT lpca);
  WINGDIAPI HPALETTE WINAPI CreateHalftonePalette(HDC hdc);

  రకనిర్వచనం WINBOOL (CALLBACK *ABORTPROC)(HDC,పూర్ణాంకం);

  రకనిర్వచనం నిర్మాణం _DOCINFOA {
    పూర్ణాంకం cb_కొలత;
    LPCSTR lpszDocName;
    LPCSTR lpszOutput;
    LPCSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOA,*LPDOCINFOA;

  రకనిర్వచనం నిర్మాణం _DOCINFOW {
    పూర్ణాంకం cb_కొలత;
    LPCWSTR lpszDocName;
    LPCWSTR lpszOutput;
    LPCWSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOW,*LPDOCINFOW;

#నిర్వచితమైతే UNICODE
  రకనిర్వచనం DOCINFOW DOCINFO;
  రకనిర్వచనం LPDOCINFOW LPDOCINFO;
#లేకపోతే
  రకనిర్వచనం DOCINFOA DOCINFO;
  రకనిర్వచనం LPDOCINFOA LPDOCINFO;
#అయితే_ముగింపు

#నిర్వచించు DI_APPBANDING 0x00000001
#నిర్వచించు DI_ROPS_READ_DESTINATION 0x00000002

#నిర్వచితమైతే UNICODE
#నిర్వచించు ప్రారంభం_Doc ప్రారంభం_Doc_W
#నిర్వచించు GetObject GetObjectW
#నిర్వచించు పాఠ్యం_బహిర్గతం పాఠ్యం_బహిర్గతం_W
#నిర్వచించు Ext_పాఠ్యం_బహిర్గతం Ext_పాఠ్యం_బహిర్గతం_W
#నిర్వచించు Poly_పాఠ్యం_బహిర్గతం Poly_పాఠ్యం_బహిర్గతం_W
#నిర్వచించు Get_పాఠ్యం_Face Get_పాఠ్యం_Face_W
#లేకపోతే
#నిర్వచించు ప్రారంభం_Doc ప్రారంభం_Doc_A
#నిర్వచించు GetObject GetObjectA
#నిర్వచించు పాఠ్యం_బహిర్గతం పాఠ్యం_బహిర్గతం_A
#నిర్వచించు Ext_పాఠ్యం_బహిర్గతం Ext_పాఠ్యం_బహిర్గతం_A
#నిర్వచించు Poly_పాఠ్యం_బహిర్గతం Poly_పాఠ్యం_బహిర్గతం_A
#నిర్వచించు Get_పాఠ్యం_Face Get_పాఠ్యం_Face_A
#అయితే_ముగింపు

  WINGDIAPI పూర్ణాంకం WINAPI ప్రారంభం_Doc_A(HDC hdc,CONST DOCINFOA *lpdi);
  WINGDIAPI పూర్ణాంకం WINAPI ప్రారంభం_Doc_W(HDC hdc,CONST DOCINFOW *lpdi);
  WINGDIAPI పూర్ణాంకం WINAPI చివర_Doc(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI ప్రారంభం_పుట(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI చివర_పుట(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI AbortDoc(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_Abort_Proc(HDC hdc,ABORTPROC proc);
  WINGDIAPI WINBOOL WINAPI Abort_మార్గం(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Arc_గమ్యం(HDC hdc,పూర్ణాంకం ఎడమ,పూర్ణాంకం శిఖరం,పూర్ణాంకం కుడి,పూర్ణాంకం bottom,పూర్ణాంకం xr1,పూర్ణాంకం yr1,పూర్ణాంకం xr2,పూర్ణాంకం yr2);
  WINGDIAPI WINBOOL WINAPI Begin_మార్గం(HDC hdc);
  WINGDIAPI WINBOOL WINAPI CloseFigure(HDC hdc);
  WINGDIAPI WINBOOL WINAPI చివర_మార్గం_2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Fill_మార్గం(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Flatten_మార్గం(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI Get_మార్గం(HDC hdc,LPPOINT apt,LPBYTE aj,పూర్ణాంకం cpt);
  WINGDIAPI HRGN WINAPI మార్గం_గమ్యం_Region(HDC hdc);
  WINGDIAPI WINBOOL WINAPI PolyDraw(HDC hdc,CONST బిందువు_3 *apt,CONST BYTE *aj,పూర్ణాంకం cpt);
  WINGDIAPI WINBOOL WINAPI Select_Clip_మార్గం(HDC hdc,పూర్ణాంకం బహుళకం);
  WINGDIAPI పూర్ణాంకం WINAPI సమితి_Arc_Direction(HDC hdc,పూర్ణాంకం dir);
  WINGDIAPI WINBOOL WINAPI సమితి_Miter_హద్దు(HDC hdc,FLOAT హద్దు,PFLOAT old);
  WINGDIAPI WINBOOL WINAPI Stroke_And_Fill_మార్గం(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Stroke_మార్గం(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Widen_మార్గం(HDC hdc);
  WINGDIAPI HPEN WINAPI ExtCreatePen(DWORD iPenStyle,DWORD c_వెడల్పు,CONST LOGBRUSH *plbrush,DWORD cStyle,CONST DWORD *pstyle);
  WINGDIAPI WINBOOL WINAPI Get_Miter_హద్దు(HDC hdc,PFLOAT plimit);
  WINGDIAPI పూర్ణాంకం WINAPI GetArcDirection(HDC hdc);
  WINGDIAPI పూర్ణాంకం WINAPI GetObjectA(HANDLE h,పూర్ణాంకం c,LPVOID pv);
  WINGDIAPI పూర్ణాంకం WINAPI GetObjectW(HANDLE h,పూర్ణాంకం c,LPVOID pv);
  WINGDIAPI WINBOOL WINAPI Move_గమ్యం_Ex(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI పాఠ్యం_బహిర్గతం_A(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPCSTR lpString,పూర్ణాంకం c);
  WINGDIAPI WINBOOL WINAPI పాఠ్యం_బహిర్గతం_W(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPCWSTR lpString,పూర్ణాంకం c);
  WINGDIAPI WINBOOL WINAPI Ext_పాఠ్యం_బహిర్గతం_A(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,UINT options,CONST RECT *lprect,LPCSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Ext_పాఠ్యం_బహిర్గతం_W(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,UINT options,CONST RECT *lprect,LPCWSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Poly_పాఠ్యం_బహిర్గతం_A(HDC hdc,CONST POLYTEXTA *ppt,పూర్ణాంకం nstrings);
  WINGDIAPI WINBOOL WINAPI Poly_పాఠ్యం_బహిర్గతం_W(HDC hdc,CONST POLYTEXTW *ppt,పూర్ణాంకం nstrings);
  WINGDIAPI HRGN WINAPI CreatePolygonRgn(CONST బిందువు_3 *pptl,పూర్ణాంకం c_బిందువు,పూర్ణాంకం i_బహుళకం);
  WINGDIAPI WINBOOL WINAPI DPtoLP(HDC hdc,LPPOINT lppt,పూర్ణాంకం c);
  WINGDIAPI WINBOOL WINAPI LPtoDP(HDC hdc,LPPOINT lppt,పూర్ణాంకం c);
  WINGDIAPI WINBOOL WINAPI Polygon(HDC hdc,CONST బిందువు_3 *apt,పూర్ణాంకం cpt);
  WINGDIAPI WINBOOL WINAPI Polyline(HDC hdc,CONST బిందువు_3 *apt,పూర్ణాంకం cpt);
  WINGDIAPI WINBOOL WINAPI PolyBezier(HDC hdc,CONST బిందువు_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Poly_Bezier_గమ్యం(HDC hdc,CONST బిందువు_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Polyline_గమ్యం(HDC hdc,CONST బిందువు_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI సమితి_Viewport_Ext_Ex(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI సమితి_Viewport_Org_Ex(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI సమితి_కిటికీ_Ext_Ex(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI సమితి_కిటికీ_Org_Ex(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI స్థానభ్రంశం_Viewport_Org_Ex(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI స్థానభ్రంశం_కిటికీ_Org_Ex(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ScaleViewportExtEx(HDC hdc,పూర్ణాంకం xn,పూర్ణాంకం dx,పూర్ణాంకం yn,పూర్ణాంకం yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Scale_కిటికీ_Ext_Ex(HDC hdc,పూర్ణాంకం xn,పూర్ణాంకం xd,పూర్ణాంకం yn,పూర్ణాంకం yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI సమితి_Bitmap_Dimension_Ex(HBITMAP hbm,పూర్ణాంకం w,పూర్ణాంకం h,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI సమితి_Brush_Org_Ex(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPPOINT lppt);
  WINGDIAPI పూర్ణాంకం WINAPI Get_పాఠ్యం_Face_A(HDC hdc,పూర్ణాంకం c,LPSTR lpName);
  WINGDIAPI పూర్ణాంకం WINAPI Get_పాఠ్యం_Face_W(HDC hdc,పూర్ణాంకం c,LPWSTR lpName);

#నిర్వచించు FONTMAPPER_MAX 10

  రకనిర్వచనం నిర్మాణం ట్యాగ్_KERNINGPAIR {
    మాట_3 w_మొదటి;
    మాట_3 w_రెండవ;
    పూర్ణాంకం iKernAmount;
  } KERNINGPAIR,*LPKERNINGPAIR;

#నిర్వచితమైతే UNICODE
#నిర్వచించు Get_Kerning_జతలు Get_Kerning_జతలు_W
#లేకపోతే
#నిర్వచించు Get_Kerning_జతలు Get_Kerning_జతలు_A
#అయితే_ముగింపు

  WINGDIAPI DWORD WINAPI Get_Kerning_జతలు_A(HDC hdc,DWORD n_జతలు,LPKERNINGPAIR lpKernPair);
  WINGDIAPI DWORD WINAPI Get_Kerning_జతలు_W(HDC hdc,DWORD n_జతలు,LPKERNINGPAIR lpKernPair);
  WINGDIAPI WINBOOL WINAPI GetDCOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI FixBrushOrgEx(HDC hdc,పూర్ణాంకం x,పూర్ణాంకం y,LPPOINT ptl);
  WINGDIAPI WINBOOL WINAPI UnrealizeObject(HGDIOBJ h);
  WINGDIAPI WINBOOL WINAPI GdiFlush();
  WINGDIAPI DWORD WINAPI Gdi_సమితి_Batch_హద్దు(DWORD dw);
  WINGDIAPI DWORD WINAPI Gdi_Get_Batch_హద్దు();

#నిర్వచించు ICM_OFF 1
#నిర్వచించు ICM_ON 2
#నిర్వచించు ICM_QUERY 3
#నిర్వచించు ICM_పూర్తి_OUTSIDEDC 4

  రకనిర్వచనం పూర్ణాంకం (CALLBACK *ICMENUMPROCA)(LPSTR,LPARAM);
  రకనిర్వచనం పూర్ణాంకం (CALLBACK *ICMENUMPROCW)(LPWSTR,LPARAM);

#నిర్వచితమైతే UNICODE
#నిర్వచించు ICMENUMPROC ICMENUMPROCW
#నిర్వచించు EnumICMProfiles EnumICMProfilesW
#నిర్వచించు Update_ICMReg_కీలకం Update_ICMReg_కీలకం_W
#నిర్వచించు GetLogColorSpace GetLogColorSpaceW
#నిర్వచించు CreateColorSpace CreateColorSpaceW
#నిర్వచించు GetICMProfile GetICMProfileW
#నిర్వచించు సమితి_ICMProfile సమితి_ICMProfile_W
#లేకపోతే
#నిర్వచించు ICMENUMPROC ICMENUMPROCA
#నిర్వచించు EnumICMProfiles EnumICMProfilesA
#నిర్వచించు Update_ICMReg_కీలకం Update_ICMReg_కీలకం_A
#నిర్వచించు GetLogColorSpace GetLogColorSpaceA
#నిర్వచించు CreateColorSpace CreateColorSpaceA
#నిర్వచించు GetICMProfile GetICMProfileA
#నిర్వచించు సమితి_ICMProfile సమితి_ICMProfile_A
#అయితే_ముగింపు

  WINGDIAPI పూర్ణాంకం WINAPI సమితి_ICMMode(HDC hdc,పూర్ణాంకం బహుళకం);
  WINGDIAPI WINBOOL WINAPI Check_Colors_లోపల_Gamut(HDC hdc,LPVOID lpRGBTriple,LPVOID dlp_బఫరు,DWORD n_లెక్క);
  WINGDIAPI HCOLORSPACE WINAPI GetColorSpace(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceA(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEA lp_బఫరు,DWORD n_కొలత);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceW(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEW lp_బఫరు,DWORD n_కొలత);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA lplcs);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW lplcs);
  WINGDIAPI HCOLORSPACE WINAPI సమితి_Color_Space(HDC hdc,HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI DeleteColorSpace(HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI GetICMProfileA(HDC hdc,LPDWORD p_Buf_కొలత,LPSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI GetICMProfileW(HDC hdc,LPDWORD p_Buf_కొలత,LPWSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI సమితి_ICMProfile_A(HDC hdc,LPSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI సమితి_ICMProfile_W(HDC hdc,LPWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI GetDeviceGammaRamp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI సమితి_Device_Gamma_Ramp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI Color_సరిపోలిక_గమ్యం_లక్ష్యం(HDC hdc,HDC hdc_లక్ష్యం,DWORD action);
  WINGDIAPI పూర్ణాంకం WINAPI EnumICMProfilesA(HDC hdc,ICMENUMPROCA proc,LPARAM param);
  WINGDIAPI పూర్ణాంకం WINAPI EnumICMProfilesW(HDC hdc,ICMENUMPROCW proc,LPARAM param);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_కీలకం_A(DWORD reserved,LPSTR lpszCMID,LPSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_కీలకం_W(DWORD reserved,LPWSTR lpszCMID,LPWSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI ColorCorrectPalette(HDC hdc,HPALETTE hPal,DWORD de_మొదటి,DWORD అంకె);

#నిర్వచితం_కాకపోతే NOMETAFILE

#నిర్వచించు ENHMETA_SIGNATURE 0x464D4520
#నిర్వచించు ENHMETA_STOCK_OBJECT 0x80000000

#నిర్వచించు EMR_శీర్షిక 1
#నిర్వచించు EMR_POLYBEZIER 2
#నిర్వచించు EMR_POLYGON 3
#నిర్వచించు EMR_POLYLINE 4
#నిర్వచించు EMR_POLYBEZIERTO 5
#నిర్వచించు EMR_POLYLINETO 6
#నిర్వచించు EMR_POLYPOLYLINE 7
#నిర్వచించు EMR_POLYPOLYGON 8
#నిర్వచించు EMR_SETWINDOWEXTEX 9
#నిర్వచించు EMR_SETWINDOWORGEX 10
#నిర్వచించు EMR_SETVIEWPORTEXTEX 11
#నిర్వచించు EMR_SETVIEWPORTORGEX 12
#నిర్వచించు EMR_SETBRUSHORGEX 13
#నిర్వచించు EMR_EOF 14
#నిర్వచించు EMR_SETPIXELV 15
#నిర్వచించు EMR_SETMAPPERFLAGS 16
#నిర్వచించు EMR_SETMAPMODE 17
#నిర్వచించు EMR_SETBKMODE 18
#నిర్వచించు EMR_SETPOLYFILLMODE 19
#నిర్వచించు EMR_SETROP2 20
#నిర్వచించు EMR_SETSTRETCHBLTMODE 21
#నిర్వచించు EMR_SETTEXTALIGN 22
#నిర్వచించు EMR_SETCOLORADJUSTMENT 23
#నిర్వచించు EMR_SETTEXTCOLOR 24
#నిర్వచించు EMR_SETBKCOLOR 25
#నిర్వచించు EMR_OFFSETCLIPRGN 26
#నిర్వచించు EMR_MOVETOEX 27
#నిర్వచించు EMR_SETMETARGN 28
#నిర్వచించు EMR_EXCLUDECLIPRECT 29
#నిర్వచించు EMR_INTERSECTCLIPRECT 30
#నిర్వచించు EMR_SCALEVIEWPORTEXTEX 31
#నిర్వచించు EMR_SCALEWINDOWEXTEX 32
#నిర్వచించు EMR_SAVEDC 33
#నిర్వచించు EMR_RESTOREDC 34
#నిర్వచించు EMR_SETWORLDTRANSFORM 35
#నిర్వచించు EMR_MODIFYWORLDTRANSFORM 36
#నిర్వచించు EMR_SELECTOBJECT 37
#నిర్వచించు EMR_CREATEPEN 38
#నిర్వచించు EMR_CREATEBRUSHINDIRECT 39
#నిర్వచించు EMR_DELETEOBJECT 40
#నిర్వచించు EMR_ANGLEARC 41
#నిర్వచించు EMR_ELLIPSE 42
#నిర్వచించు EMR_RECTANGLE 43
#నిర్వచించు EMR_ROUNDRECT 44
#నిర్వచించు EMR_ARC 45
#నిర్వచించు EMR_CHORD 46
#నిర్వచించు EMR_PIE 47
#నిర్వచించు EMR_SELECTPALETTE 48
#నిర్వచించు EMR_CREATEPALETTE 49
#నిర్వచించు EMR_SETPALETTEENTRIES 50
#నిర్వచించు EMR_RESIZEPALETTE 51
#నిర్వచించు EMR_REALIZEPALETTE 52
#నిర్వచించు EMR_EXTFLOODFILL 53
#నిర్వచించు EMR_LINETO 54
#నిర్వచించు EMR_ARCTO 55
#నిర్వచించు EMR_POLYDRAW 56
#నిర్వచించు EMR_SETARCDIRECTION 57
#నిర్వచించు EMR_SETMITERLIMIT 58
#నిర్వచించు EMR_BEGINPATH 59
#నిర్వచించు EMR_ENDPATH 60
#నిర్వచించు EMR_CLOSEFIGURE 61
#నిర్వచించు EMR_FILLPATH 62
#నిర్వచించు EMR_STROKEANDFILLPATH 63
#నిర్వచించు EMR_STROKEPATH 64
#నిర్వచించు EMR_FLATTENPATH 65
#నిర్వచించు EMR_WIDENPATH 66
#నిర్వచించు EMR_SELECTCLIPPATH 67
#నిర్వచించు EMR_ABORTPATH 68

#నిర్వచించు EMR_GDICOMMENT 70
#నిర్వచించు EMR_FILLRGN 71
#నిర్వచించు EMR_FRAMERGN 72
#నిర్వచించు EMR_INVERTRGN 73
#నిర్వచించు EMR_PAINTRGN 74
#నిర్వచించు EMR_EXTSELECTCLIPRGN 75
#నిర్వచించు EMR_BITBLT 76
#నిర్వచించు EMR_STRETCHBLT 77
#నిర్వచించు EMR_MASKBLT 78
#నిర్వచించు EMR_PLGBLT 79
#నిర్వచించు EMR_SETDIBITSTODEVICE 80
#నిర్వచించు EMR_STRETCHDIBITS 81
#నిర్వచించు EMR_EXTCREATEFONTINDIRECTW 82
#నిర్వచించు EMR_EXTTEXTOUTA 83
#నిర్వచించు EMR_EXTTEXTOUTW 84
#నిర్వచించు EMR_POLYBEZIER16 85
#నిర్వచించు EMR_POLYGON16 86
#నిర్వచించు EMR_POLYLINE16 87
#నిర్వచించు EMR_POLYBEZIERTO16 88
#నిర్వచించు EMR_POLYLINETO16 89
#నిర్వచించు EMR_POLYPOLYLINE16 90
#నిర్వచించు EMR_POLYPOLYGON16 91
#నిర్వచించు EMR_POLYDRAW16 92
#నిర్వచించు EMR_CREATEMONOBRUSH 93
#నిర్వచించు EMR_CREATEDIBPATTERNBRUSHPT 94
#నిర్వచించు EMR_EXTCREATEPEN 95
#నిర్వచించు EMR_POLYTEXTOUTA 96
#నిర్వచించు EMR_POLYTEXTOUTW 97

#నిర్వచించు EMR_SETICMMODE 98
#నిర్వచించు EMR_CREATECOLORSPACE 99
#నిర్వచించు EMR_SETCOLORSPACE 100
#నిర్వచించు EMR_DELETECOLORSPACE 101
#నిర్వచించు EMR_GLSRECORD 102
#నిర్వచించు EMR_GLSBOUNDEDRECORD 103
#నిర్వచించు EMR_PIXELFORMAT 104
#నిర్వచించు EMR_RESERVED_105 105
#నిర్వచించు EMR_RESERVED_106 106
#నిర్వచించు EMR_RESERVED_107 107
#నిర్వచించు EMR_RESERVED_108 108
#నిర్వచించు EMR_RESERVED_109 109
#నిర్వచించు EMR_RESERVED_110 110
#నిర్వచించు EMR_COLORCORRECTPALETTE 111
#నిర్వచించు EMR_SETICMPROFILEA 112
#నిర్వచించు EMR_SETICMPROFILEW 113
#నిర్వచించు EMR_ALPHABLEND 114
#నిర్వచించు EMR_SETLAYOUT 115
#నిర్వచించు EMR_TRANSPARENTBLT 116
#నిర్వచించు EMR_RESERVED_117 117
#నిర్వచించు EMR_GRADIENTFILL 118
#నిర్వచించు EMR_RESERVED_119 119
#నిర్వచించు EMR_RESERVED_120 120
#నిర్వచించు EMR_COLORMATCHTOTARGETW 121
#నిర్వచించు EMR_CREATECOLORSPACEW 122

#నిర్వచించు EMR_MIN 1

#నిర్వచించు EMR_MAX 122

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMR {
    DWORD iType;
    DWORD n_కొలత;
  } EMR,*PEMR;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRTEXT {
    POINTL ptlReference;
    DWORD nChars;
    DWORD offString;
    DWORD fOptions;
    RECTL rcl;
    DWORD offDx;
  } EMRTEXT,*PEMRTEXT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_ABORTPATH {
    EMR emr;
  } EMRABORTPATH,*PEMRABORTPATH,EMRBEGINPATH,*PEMRBEGINPATH,EMRENDPATH,*PEMRENDPATH,EMRCLOSEFIGURE,*PEMRCLOSEFIGURE,EMRFLATTENPATH,*PEMRFLATTENPATH,EMRWIDENPATH,*PEMRWIDENPATH,EMRSETMETARGN,*PEMRSETMETARGN,EMRSAVEDC,*PEMRSAVEDC,EMRREALIZEPALETTE,*PEMRREALIZEPALETTE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSELECTCLIPPATH {
    EMR emr;
    DWORD i_బహుళకం;
  } EMRSELECTCLIPPATH,*PEMRSELECTCLIPPATH,EMRSETBKMODE,*PEMRSETBKMODE,EMRSETMAPMODE,*PEMRSETMAPMODE,EMRSETLAYOUT,*PEMRSETLAYOUT,
    EMRSETPOLYFILLMODE,*PEMRSETPOLYFILLMODE,EMRSETROP2,*PEMRSETROP2,EMRSETSTRETCHBLTMODE,*PEMRSETSTRETCHBLTMODE,EMRSETICMMODE,
    *PEMRSETICMMODE,EMRSETTEXTALIGN,*PEMRSETTEXTALIGN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETMITERLIMIT {
    EMR emr;
    FLOAT e_Miter_హద్దు;
  } EMRSETMITERLIMIT,*PEMRSETMITERLIMIT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRRESTOREDC {
    EMR emr;
    LONG iRelative;
  } EMRRESTOREDC,*PEMRRESTOREDC;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETARCDIRECTION {
    EMR emr;
    DWORD iArcDirection;

  } EMRSETARCDIRECTION,*PEMRSETARCDIRECTION;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETMAPPERFLAGS {
    EMR emr;
    DWORD dwFlags;
  } EMRSETMAPPERFLAGS,*PEMRSETMAPPERFLAGS;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETTEXTCOLOR {
    EMR emr;
    COLORREF crColor;
  } EMRSETBKCOLOR,*PEMRSETBKCOLOR,EMRSETTEXTCOLOR,*PEMRSETTEXTCOLOR;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSELECTOBJECT {
    EMR emr;
    DWORD ihObject;
  } EMRSELECTOBJECT,*PEMRSELECTOBJECT,EMRDELETEOBJECT,*PEMRDELETEOBJECT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSELECTPALETTE {
    EMR emr;
    DWORD ihPal;
  } EMRSELECTPALETTE,*PEMRSELECTPALETTE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRRESIZEPALETTE {
    EMR emr;
    DWORD ihPal;
    DWORD cEntries;
  } EMRRESIZEPALETTE,*PEMRRESIZEPALETTE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETPALETTEENTRIES {
    EMR emr;
    DWORD ihPal;
    DWORD i_ప్రారంభం;
    DWORD cEntries;
    PALETTEENTRY aPalEntries[1];
  } EMRSETPALETTEENTRIES,*PEMRSETPALETTEENTRIES;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETCOLORADJUSTMENT {
    EMR emr;
    COLORADJUSTMENT ColorAdjustment;
  } EMRSETCOLORADJUSTMENT,*PEMRSETCOLORADJUSTMENT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRGDICOMMENT {
    EMR emr;
    DWORD cb_దత్తాంశం;
    BYTE దత్తాంశం_3[1];
  } EMRGDICOMMENT,*PEMRGDICOMMENT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMREOF {
    EMR emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD n_కొలత_చివరి;
  } EMREOF,*PEMREOF;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRLINETO {
    EMR emr;
    POINTL ptl;
  } EMRLINETO,*PEMRLINETO,EMRMOVETOEX,*PEMRMOVETOEX;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMROFFSETCLIPRGN {
    EMR emr;
    POINTL ptl_స్థానభ్రంశం;
  } EMROFFSETCLIPRGN,*PEMROFFSETCLIPRGN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRFILLPATH {
    EMR emr;
    RECTL rclBounds;
  } EMRFILLPATH,*PEMRFILLPATH,EMRSTROKEANDFILLPATH,*PEMRSTROKEANDFILLPATH,EMRSTROKEPATH,*PEMRSTROKEPATH;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMREXCLUDECLIPRECT {
    EMR emr;
    RECTL rclClip;
  } EMREXCLUDECLIPRECT,*PEMREXCLUDECLIPRECT,EMRINTERSECTCLIPRECT,*PEMRINTERSECTCLIPRECT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETVIEWPORTORGEX {
    EMR emr;
    POINTL ptlOrigin;
  } EMRSETVIEWPORTORGEX,*PEMRSETVIEWPORTORGEX,EMRSETWINDOWORGEX,*PEMRSETWINDOWORGEX,EMRSETBRUSHORGEX,*PEMRSETBRUSHORGEX;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETVIEWPORTEXTEX {
    EMR emr;
    SIZEL szlExtent;
  } EMRSETVIEWPORTEXTEX,*PEMRSETVIEWPORTEXTEX,EMRSETWINDOWEXTEX,*PEMRSETWINDOWEXTEX;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSCALEVIEWPORTEXTEX {
    EMR emr;
    LONG x_అంకె;
    LONG xDenom;
    LONG y_అంకె;
    LONG yDenom;
  } EMRSCALEVIEWPORTEXTEX,*PEMRSCALEVIEWPORTEXTEX,EMRSCALEWINDOWEXTEX,*PEMRSCALEWINDOWEXTEX;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
  } EMRSETWORLDTRANSFORM,*PEMRSETWORLDTRANSFORM;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRMODIFYWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
    DWORD i_బహుళకం;
  } EMRMODIFYWORLDTRANSFORM,*PEMRMODIFYWORLDTRANSFORM;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETPIXELV {
    EMR emr;
    POINTL ptlPixel;
    COLORREF crColor;
  } EMRSETPIXELV,*PEMRSETPIXELV;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMREXTFLOODFILL {
    EMR emr;
    POINTL ptl_ప్రారంభం;
    COLORREF crColor;
    DWORD i_బహుళకం;
  } EMREXTFLOODFILL,*PEMREXTFLOODFILL;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRELLIPSE {
    EMR emr;
    RECTL rclBox;
  } EMRELLIPSE,*PEMRELLIPSE,EMRRECTANGLE,*PEMRRECTANGLE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRROUNDRECT {
    EMR emr;
    RECTL rclBox;
    SIZEL szl_మూల;
  } EMRROUNDRECT,*PEMRROUNDRECT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRARC {
    EMR emr;
    RECTL rclBox;
    POINTL ptl_ప్రారంభం;
    POINTL ptl_చివర;
  } EMRARC,*PEMRARC,EMRARCTO,*PEMRARCTO,EMRCHORD,*PEMRCHORD,EMRPIE,*PEMRPIE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRANGLEARC {
    EMR emr;
    POINTL ptlCenter;
    DWORD nRadius;
    FLOAT e_ప్రారంభం_Angle;
    FLOAT eSweepAngle;
  } EMRANGLEARC,*PEMRANGLEARC;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
  } EMRPOLYLINE,*PEMRPOLYLINE,EMRPOLYBEZIER,*PEMRPOLYBEZIER,EMRPOLYGON,*PEMRPOLYGON,EMRPOLYBEZIERTO,*PEMRPOLYBEZIERTO,EMRPOLYLINETO,*PEMRPOLYLINETO;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
  } EMRPOLYLINE16,*PEMRPOLYLINE16,EMRPOLYBEZIER16,*PEMRPOLYBEZIER16,EMRPOLYGON16,*PEMRPOLYGON16,EMRPOLYBEZIERTO16,*PEMRPOLYBEZIERTO16,EMRPOLYLINETO16,*PEMRPOLYLINETO16;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRPOLYDRAW {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW,*PEMRPOLYDRAW;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRPOLYDRAW16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW16,*PEMRPOLYDRAW16;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRPOLYPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cptl;
    DWORD aPolyCounts[1];
    POINTL aptl[1];
  } EMRPOLYPOLYLINE,*PEMRPOLYPOLYLINE,EMRPOLYPOLYGON,*PEMRPOLYPOLYGON;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRPOLYPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cpts;
    DWORD aPolyCounts[1];
    POINTS apts[1];
  } EMRPOLYPOLYLINE16,*PEMRPOLYPOLYLINE16,EMRPOLYPOLYGON16,*PEMRPOLYPOLYGON16;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRINVERTRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_దత్తాంశం;
    BYTE Rgn_దత్తాంశం[1];
  } EMRINVERTRGN,*PEMRINVERTRGN,EMRPAINTRGN,*PEMRPAINTRGN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRFILLRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_దత్తాంశం;
    DWORD ihBrush;
    BYTE Rgn_దత్తాంశం[1];
  } EMRFILLRGN,*PEMRFILLRGN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRFRAMERGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_దత్తాంశం;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE Rgn_దత్తాంశం[1];
  } EMRFRAMERGN,*PEMRFRAMERGN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMREXTSELECTCLIPRGN {
    EMR emr;
    DWORD cb_Rgn_దత్తాంశం;
    DWORD i_బహుళకం;
    BYTE Rgn_దత్తాంశం[1];
  } EMREXTSELECTCLIPRGN,*PEMREXTSELECTCLIPRGN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMREXTTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_బహుళకం;
    FLOAT exScale;
    FLOAT eyScale;
    EMRTEXT emrtext;
  } EMREXTTEXTOUTA,*PEMREXTTEXTOUTA,EMREXTTEXTOUTW,*PEMREXTTEXTOUTW;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRPOLYTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_బహుళకం;
    FLOAT exScale;
    FLOAT eyScale;
    LONG c_అక్షరశ్రేణులు;
    EMRTEXT aemrtext[1];
  } EMRPOLYTEXTOUTA,*PEMRPOLYTEXTOUTA,EMRPOLYTEXTOUTW,*PEMRPOLYTEXTOUTW;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRBITBLT {
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
    DWORD off_బిట్లు_Src;
    DWORD cb_బిట్లు_Src;
  } EMRBITBLT,*PEMRBITBLT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSTRETCHBLT {
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
    DWORD off_బిట్లు_Src;
    DWORD cb_బిట్లు_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRSTRETCHBLT,*PEMRSTRETCHBLT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRMASKBLT {
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
    DWORD off_బిట్లు_Src;
    DWORD cb_బిట్లు_Src;
    LONG x_ముసుగు;
    LONG y_ముసుగు;
    DWORD i_Usage_ముసుగు;
    DWORD off_Bmi_ముసుగు;
    DWORD cb_Bmi_ముసుగు;
    DWORD off_బిట్లు_ముసుగు;
    DWORD cb_బిట్లు_ముసుగు;
  } EMRMASKBLT,*PEMRMASKBLT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRPLGBLT {
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
    DWORD off_బిట్లు_Src;
    DWORD cb_బిట్లు_Src;
    LONG x_ముసుగు;
    LONG y_ముసుగు;
    DWORD i_Usage_ముసుగు;
    DWORD off_Bmi_ముసుగు;
    DWORD cb_Bmi_ముసుగు;
    DWORD off_బిట్లు_ముసుగు;
    DWORD cb_బిట్లు_ముసుగు;
  } EMRPLGBLT,*PEMRPLGBLT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETDIBITSTODEVICE {
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
    DWORD off_బిట్లు_Src;
    DWORD cb_బిట్లు_Src;
    DWORD iUsageSrc;
    DWORD i_ప్రారంభం_పరిశీలన;
    DWORD cScans;
  } EMRSETDIBITSTODEVICE,*PEMRSETDIBITSTODEVICE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSTRETCHDIBITS {
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
    DWORD off_బిట్లు_Src;
    DWORD cb_బిట్లు_Src;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG cxDest;
    LONG cyDest;
  } EMRSTRETCHDIBITS,*PEMRSTRETCHDIBITS;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMREXTCREATEFONTINDIRECTW {
    EMR emr;
    DWORD ihFont;
    EXTLOGFONTW elfw;
  } EMREXTCREATEFONTINDIRECTW,*PEMREXTCREATEFONTINDIRECTW;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRCREATEPALETTE {
    EMR emr;
    DWORD ihPal;
    LOGPALETTE lgpl;
  } EMRCREATEPALETTE,*PEMRCREATEPALETTE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRCREATEPEN {
    EMR emr;
    DWORD ihPen;
    LOGPEN lopn;
  } EMRCREATEPEN,*PEMRCREATEPEN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMREXTCREATEPEN {
    EMR emr;
    DWORD ihPen;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_బిట్లు;
    DWORD cb_బిట్లు;
    EXTLOGPEN elp;
  } EMREXTCREATEPEN,*PEMREXTCREATEPEN;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRCREATEBRUSHINDIRECT {
    EMR emr;
    DWORD ihBrush;
    LOGBRUSH32 lb;
  } EMRCREATEBRUSHINDIRECT,*PEMRCREATEBRUSHINDIRECT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRCREATEMONOBRUSH {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_బిట్లు;
    DWORD cb_బిట్లు;
  } EMRCREATEMONOBRUSH,*PEMRCREATEMONOBRUSH;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRCREATEDIBPATTERNBRUSHPT {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_బిట్లు;
    DWORD cb_బిట్లు;
  } EMRCREATEDIBPATTERNBRUSHPT,*PEMRCREATEDIBPATTERNBRUSHPT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRFORMAT {
    DWORD dSignature;
    DWORD n_సంస్కరణ;
    DWORD cb_దత్తాంశం;
    DWORD off_దత్తాంశం;
  } EMRFORMAT,*PEMRFORMAT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRGLSRECORD {
    EMR emr;
    DWORD cb_దత్తాంశం;
    BYTE దత్తాంశం_3[1];
  } EMRGLSRECORD,*PEMRGLSRECORD;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRGLSBOUNDEDRECORD {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_దత్తాంశం;
    BYTE దత్తాంశం_3[1];
  } EMRGLSBOUNDEDRECORD,*PEMRGLSBOUNDEDRECORD;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRPIXELFORMAT {
    EMR emr;
    PIXELFORMATDESCRIPTOR pfd;
  } EMRPIXELFORMAT,*PEMRPIXELFORMAT;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRCREATECOLORSPACE {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEA lcs;
  } EMRCREATECOLORSPACE,*PEMRCREATECOLORSPACE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETCOLORSPACE {
    EMR emr;
    DWORD ihCS;
  } EMRSETCOLORSPACE,*PEMRSETCOLORSPACE,EMRSELECTCOLORSPACE,*PEMRSELECTCOLORSPACE,EMRDELETECOLORSPACE,*PEMRDELETECOLORSPACE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMREXTESCAPE {
    EMR emr;
    INT iEscape;
    INT cb_Esc_దత్తాంశం;
    BYTE Esc_దత్తాంశం[1];
  } EMREXTESCAPE,*PEMREXTESCAPE,EMRDRAWESCAPE,*PEMRDRAWESCAPE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRNAMEDESCAPE {
    EMR emr;
    INT iEscape;
    INT cbDriver;
    INT cb_Esc_దత్తాంశం;
    BYTE Esc_దత్తాంశం[1];
  } EMRNAMEDESCAPE,*PEMRNAMEDESCAPE;

#నిర్వచించు SETICMPROFILE_EMBEDED 0x00000001

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRSETICMPROFILE {
    EMR emr;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_దత్తాంశం;
    BYTE దత్తాంశం_3[1];
  } EMRSETICMPROFILE,*PEMRSETICMPROFILE,EMRSETICMPROFILEA,*PEMRSETICMPROFILEA,EMRSETICMPROFILEW,*PEMRSETICMPROFILEW;

#నిర్వచించు CREATECOLORSPACE_EMBEDED 0x00000001

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRCREATECOLORSPACEW {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEW lcs;
    DWORD dwFlags;
    DWORD cb_దత్తాంశం;
    BYTE దత్తాంశం_3[1];
  } EMRCREATECOLORSPACEW,*PEMRCREATECOLORSPACEW;

#నిర్వచించు COLORMATCHTOTARGET_EMBEDED 0x00000001

  రకనిర్వచనం నిర్మాణం ట్యాగ్_COLORMATCHTOTARGET {
    EMR emr;
    DWORD dwAction;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_దత్తాంశం;
    BYTE దత్తాంశం_3[1];
  } EMRCOLORMATCHTOTARGET,*PEMRCOLORMATCHTOTARGET;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_COLORCORRECTPALETTE {
    EMR emr;
    DWORD ihPalette;
    DWORD n_మొదటి_నమోదు;
    DWORD nPalEntries;
    DWORD nReserved;
  } EMRCOLORCORRECTPALETTE,*PEMRCOLORCORRECTPALETTE;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRALPHABLEND {
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
    DWORD off_బిట్లు_Src;
    DWORD cb_బిట్లు_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRALPHABLEND,*PEMRALPHABLEND;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRGRADIENTFILL {
    EMR emr;
    RECTL rclBounds;
    DWORD nVer;
    DWORD nTri;
    ULONG ul_బహుళకం;
    TRIVERTEX Ver[1];
  } EMRGRADIENTFILL,*PEMRGRADIENTFILL;

  రకనిర్వచనం నిర్మాణం ట్యాగ్_EMRTRANSPARENTBLT {
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
    DWORD off_బిట్లు_Src;
    DWORD cb_బిట్లు_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRTRANSPARENTBLT,*PEMRTRANSPARENTBLT;

#నిర్వచించు GDICOMMENT_IDENTIFIER 0x43494447
#నిర్వచించు GDICOMMENT_WINDOWS_METAFILE 0x80000001
#నిర్వచించు GDICOMMENT_BEGINGROUP 0x00000002
#నిర్వచించు GDICOMMENT_ENDGROUP 0x00000003
#నిర్వచించు GDICOMMENT_MULTIFORMATS 0x40000004
#నిర్వచించు EPS_SIGNATURE 0x46535045
#నిర్వచించు GDICOMMENT_UNICODE_STRING 0x00000040
#నిర్వచించు GDICOMMENT_UNICODE_చివర 0x00000080
#అయితే_ముగింపు

#నిర్వచితమైతే UNICODE
#నిర్వచించు wglUseFontBitmaps wglUseFontBitmapsW
#లేకపోతే
#నిర్వచించు wglUseFontBitmaps wglUseFontBitmapsA
#అయితే_ముగింపు

  WINGDIAPI WINBOOL WINAPI wglCopyContext(HGLRC,HGLRC,UINT);
  WINGDIAPI HGLRC WINAPI wglCreateContext(HDC);
  WINGDIAPI HGLRC WINAPI wglCreateLayerContext(HDC,పూర్ణాంకం);
  WINGDIAPI WINBOOL WINAPI wglDeleteContext(HGLRC);
  WINGDIAPI HGLRC WINAPI wglGetCurrentContext(VOID);
  WINGDIAPI HDC WINAPI wglGetCurrentDC(VOID);
  WINGDIAPI PROC WINAPI wgl_Get_Proc_చిరునామా(LPCSTR);
  WINGDIAPI WINBOOL WINAPI wglMakeCurrent(HDC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglShareLists(HGLRC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsA(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsW(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI మార్పిడి_Buffers(HDC);

  రకనిర్వచనం నిర్మాణం _POINTFLOAT {
    FLOAT x;
    FLOAT y;
  } POINTFLOAT,*PPOINTFLOAT;

  రకనిర్వచనం నిర్మాణం _GLYPHMETRICSFLOAT {
    FLOAT gmfBlackBoxX;
    FLOAT gmfBlackBoxY;
    POINTFLOAT gmfptGlyphOrigin;
    FLOAT gmfCellIncX;
    FLOAT gmfCellIncY;
  } GLYPHMETRICSFLOAT,*PGLYPHMETRICSFLOAT,*LPGLYPHMETRICSFLOAT;

#నిర్వచించు WGL_FONT_పంక్తులు 0
#నిర్వచించు WGL_FONT_POLYGONS 1

#నిర్వచితమైతే UNICODE
#నిర్వచించు wglUseFontOutlines wglUseFontOutlinesW
#లేకపోతే
#నిర్వచించు wglUseFontOutlines wglUseFontOutlinesA
#అయితే_ముగింపు

  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesA(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,పూర్ణాంకం,LPGLYPHMETRICSFLOAT);
  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesW(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,పూర్ణాంకం,LPGLYPHMETRICSFLOAT);

  రకనిర్వచనం నిర్మాణం ట్యాగ్_LAYERPLANEDESCRIPTOR {
    మాట_3 n_కొలత;
    మాట_3 n_సంస్కరణ;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_బిట్లు;
    BYTE c_Red_బిట్లు;
    BYTE c_Red_జరుపు;
    BYTE c_Green_బిట్లు;
    BYTE c_Green_జరుపు;
    BYTE c_Blue_బిట్లు;
    BYTE c_Blue_జరుపు;
    BYTE c_Alpha_బిట్లు;
    BYTE c_Alpha_జరుపు;
    BYTE c_Accum_బిట్లు;
    BYTE c_Accum_Red_బిట్లు;
    BYTE c_Accum_Green_బిట్లు;
    BYTE c_Accum_Blue_బిట్లు;
    BYTE c_Accum_Alpha_బిట్లు;
    BYTE c_లోతు_బిట్లు;
    BYTE c_Stencil_బిట్లు;
    BYTE cAuxBuffers;
    BYTE iLayerPlane;
    BYTE bReserved;
    COLORREF crTransparent;
  } LAYERPLANEDESCRIPTOR,*PLAYERPLANEDESCRIPTOR,*LPLAYERPLANEDESCRIPTOR;

#నిర్వచించు LPD_DOUBLEBUFFER 0x00000001
#నిర్వచించు LPD_STEREO 0x00000002
#నిర్వచించు LPD_SUPPORT_GDI 0x00000010
#నిర్వచించు LPD_SUPPORT_OPENGL 0x00000020
#నిర్వచించు LPD_SHARE_లోతు 0x00000040
#నిర్వచించు LPD_SHARE_STENCIL 0x00000080
#నిర్వచించు LPD_SHARE_ACCUM 0x00000100
#నిర్వచించు LPD_మార్పిడి_EXCHANGE 0x00000200
#నిర్వచించు LPD_మార్పిడి_COPY 0x00000400
#నిర్వచించు LPD_TRANSPARENT 0x00001000

#నిర్వచించు LPD_TYPE_RGBA 0
#నిర్వచించు LPD_TYPE_COLORINDEX 1

#నిర్వచించు WGL_మార్పిడి_MAIN_PLANE 0x00000001
#నిర్వచించు WGL_మార్పిడి_OVERLAY1 0x00000002
#నిర్వచించు WGL_మార్పిడి_OVERLAY2 0x00000004
#నిర్వచించు WGL_మార్పిడి_OVERLAY3 0x00000008
#నిర్వచించు WGL_మార్పిడి_OVERLAY4 0x00000010
#నిర్వచించు WGL_మార్పిడి_OVERLAY5 0x00000020
#నిర్వచించు WGL_మార్పిడి_OVERLAY6 0x00000040
#నిర్వచించు WGL_మార్పిడి_OVERLAY7 0x00000080
#నిర్వచించు WGL_మార్పిడి_OVERLAY8 0x00000100
#నిర్వచించు WGL_మార్పిడి_OVERLAY9 0x00000200
#నిర్వచించు WGL_మార్పిడి_OVERLAY10 0x00000400
#నిర్వచించు WGL_మార్పిడి_OVERLAY11 0x00000800
#నిర్వచించు WGL_మార్పిడి_OVERLAY12 0x00001000
#నిర్వచించు WGL_మార్పిడి_OVERLAY13 0x00002000
#నిర్వచించు WGL_మార్పిడి_OVERLAY14 0x00004000
#నిర్వచించు WGL_మార్పిడి_OVERLAY15 0x00008000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY1 0x00010000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY2 0x00020000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY3 0x00040000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY4 0x00080000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY5 0x00100000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY6 0x00200000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY7 0x00400000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY8 0x00800000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY9 0x01000000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY10 0x02000000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY11 0x04000000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY12 0x08000000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY13 0x10000000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY14 0x20000000
#నిర్వచించు WGL_మార్పిడి_UNDERLAY15 0x40000000

  WINGDIAPI WINBOOL WINAPI wglDescribeLayerPlane(HDC,పూర్ణాంకం,పూర్ణాంకం,UINT,LPLAYERPLANEDESCRIPTOR);
  WINGDIAPI పూర్ణాంకం WINAPI wgl_సమితి_Layer_Palette_Entries(HDC,పూర్ణాంకం,పూర్ణాంకం,పూర్ణాంకం,CONST COLORREF *);
  WINGDIAPI పూర్ణాంకం WINAPI wglGetLayerPaletteEntries(HDC,పూర్ణాంకం,పూర్ణాంకం,పూర్ణాంకం,COLORREF *);
  WINGDIAPI WINBOOL WINAPI wglRealizeLayerPalette(HDC,పూర్ణాంకం,WINBOOL);
  WINGDIAPI WINBOOL WINAPI wgl_మార్పిడి_Layer_Buffers(HDC,UINT);

  రకనిర్వచనం నిర్మాణం _WGLSWAP {
    HDC hdc;
    UINT uiFlags;
  } WGLSWAP,*PWGLSWAP,*LPWGLSWAP;

#నిర్వచించు WGL_SWAPMULTIPLE_MAX 16

  WINGDIAPI DWORD WINAPI wgl_మార్పిడి_గుణిజం_Buffers(UINT,CONST WGLSWAP *);
#అయితే_ముగింపు

#నిర్వచితమైతే __cplusplus
}
#అయితే_ముగింపు
#అయితే_ముగింపు
