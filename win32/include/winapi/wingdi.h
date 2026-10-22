/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#جيڪڏهن_وصف_نه_ٿيل _WINGDI_
#وصف_ڪريو _WINGDI_

#وصف_ڪريو WINGDIAPI DECLSPEC_IMPORT
#وصف_ڪريو WINSPOOLAPI DECLSPEC_IMPORT

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل WINVER
#وصف_ڪريو WINVER 0x0502
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOGDI
#جيڪڏهن_وصف_نه_ٿيل NORASTEROPS
#وصف_ڪريو R2_BLACK 1
#وصف_ڪريو R2_NOTMERGEPEN 2
#وصف_ڪريو R2_MASKNOTPEN 3
#وصف_ڪريو R2_NOTCOPYPEN 4
#وصف_ڪريو R2_MASKPENNOT 5
#وصف_ڪريو R2_NOT 6
#وصف_ڪريو R2_XORPEN 7
#وصف_ڪريو R2_NOTMASKPEN 8
#وصف_ڪريو R2_MASKPEN 9
#وصف_ڪريو R2_NOTXORPEN 10
#وصف_ڪريو R2_NOP 11
#وصف_ڪريو R2_MERGENOTPEN 12
#وصف_ڪريو R2_COPYPEN 13
#وصف_ڪريو R2_MERGEPENNOT 14
#وصف_ڪريو R2_MERGEPEN 15
#وصف_ڪريو R2_WHITE 16
#وصف_ڪريو R2_آخري 16

#وصف_ڪريو SRCCOPY (DWORD)0x00CC0020
#وصف_ڪريو SRCPAINT (DWORD)0x00EE0086
#وصف_ڪريو SRCAND (DWORD)0x008800C6
#وصف_ڪريو SRCINVERT (DWORD)0x00660046
#وصف_ڪريو SRCERASE (DWORD)0x00440328
#وصف_ڪريو NOTSRCCOPY (DWORD)0x00330008
#وصف_ڪريو NOTSRCERASE (DWORD)0x001100A6
#وصف_ڪريو MERGECOPY (DWORD)0x00C000CA
#وصف_ڪريو MERGEPAINT (DWORD)0x00BB0226
#وصف_ڪريو PATCOPY (DWORD)0x00F00021
#وصف_ڪريو PATPAINT (DWORD)0x00FB0A09
#وصف_ڪريو PATINVERT (DWORD)0x005A0049
#وصف_ڪريو DSTINVERT (DWORD)0x00550009
#وصف_ڪريو BLACKNESS (DWORD)0x00000042
#وصف_ڪريو WHITENESS (DWORD)0x00FF0062
#وصف_ڪريو NOMIRRORBITMAP (DWORD)0x80000000
#وصف_ڪريو CAPTUREBLT (DWORD)0x40000000
#وصف_ڪريو MAKEROP4(fore,پٺ) (DWORD)((((پٺ) << 8) & 0xFF000000) | (fore))
#جيڪڏهن_پورو

#وصف_ڪريو GDI_ERROR (0xFFFFFFFFL)
#وصف_ڪريو HGDI_ERROR (Long_منزل_Handle(0xFFFFFFFFL))

#وصف_ڪريو ERROR 0
#وصف_ڪريو NULLREGION 1
#وصف_ڪريو SIMPLEREGION 2
#وصف_ڪريو COMPLEXREGION 3
#وصف_ڪريو RGN_ERROR ERROR

#وصف_ڪريو RGN_AND 1
#وصف_ڪريو RGN_OR 2
#وصف_ڪريو RGN_XOR 3
#وصف_ڪريو RGN_DIFF 4
#وصف_ڪريو RGN_COPY 5
#وصف_ڪريو RGN_MIN RGN_AND
#وصف_ڪريو RGN_MAX RGN_COPY

#وصف_ڪريو BLACKONWHITE 1
#وصف_ڪريو WHITEONBLACK 2
#وصف_ڪريو COLORONCOLOR 3
#وصف_ڪريو HALFTONE 4
#وصف_ڪريو MAXSTRETCHBLTMODE 4

#وصف_ڪريو STRETCH_ANDSCANS BLACKONWHITE
#وصف_ڪريو STRETCH_ORSCANS WHITEONBLACK
#وصف_ڪريو STRETCH_DELETESCANS COLORONCOLOR
#وصف_ڪريو STRETCH_HALFTONE HALFTONE

#وصف_ڪريو ALTERNATE 1
#وصف_ڪريو WINDING 2
#وصف_ڪريو POLYFILL_آخري 2

#وصف_ڪريو LAYOUT_RTL 0x00000001
#وصف_ڪريو LAYOUT_BTT 0x00000002
#وصف_ڪريو LAYOUT_VBH 0x00000004
#وصف_ڪريو LAYOUT_ORIENTATIONMASK (LAYOUT_RTL | LAYOUT_BTT | LAYOUT_VBH)
#وصف_ڪريو LAYOUT_BITMAPORIENTATIONPRESERVED 0x00000008

#وصف_ڪريو TA_NOUPDATECP 0
#وصف_ڪريو TA_UPDATECP 1

#وصف_ڪريو TA_کاٻو 0
#وصف_ڪريو TA_ساڄو 2
#وصف_ڪريو TA_CENTER 6

#وصف_ڪريو TA_چوٽي 0
#وصف_ڪريو TA_BOTTOM 8
#وصف_ڪريو TA_BASELINE 24
#وصف_ڪريو TA_RTLREADING 256
#وصف_ڪريو TA_نقاب (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)

#وصف_ڪريو VTA_BASELINE TA_BASELINE
#وصف_ڪريو VTA_کاٻو TA_BOTTOM
#وصف_ڪريو VTA_ساڄو TA_چوٽي
#وصف_ڪريو VTA_CENTER TA_CENTER
#وصف_ڪريو VTA_BOTTOM TA_ساڄو
#وصف_ڪريو VTA_چوٽي TA_کاٻو

#وصف_ڪريو ETO_OPAQUE 0x0002
#وصف_ڪريو ETO_CLIPPED 0x0004
#وصف_ڪريو ETO_GLYPH_اشاريو 0x0010
#وصف_ڪريو ETO_RTLREADING 0x0080
#وصف_ڪريو ETO_NUMERICSLOCAL 0x0400
#وصف_ڪريو ETO_NUMERICSLATIN 0x0800
#وصف_ڪريو ETO_IGNORELANGUAGE 0x1000
#وصف_ڪريو ETO_PDY 0x2000

#وصف_ڪريو ASPECT_FILTERING 0x0001

#وصف_ڪريو DCB_RESET 0x0001
#وصف_ڪريو DCB_ACCUMULATE 0x0002
#وصف_ڪريو DCB_DIRTY DCB_ACCUMULATE
#وصف_ڪريو DCB_سيٽ (DCB_RESET | DCB_ACCUMULATE)
#وصف_ڪريو DCB_ENABLE 0x0004
#وصف_ڪريو DCB_DISABLE 0x0008

#جيڪڏهن_وصف_نه_ٿيل NOMETAFILE

#وصف_ڪريو META_SETBKCOLOR 0x0201
#وصف_ڪريو META_SETBKMODE 0x0102
#وصف_ڪريو META_SETMAPMODE 0x0103
#وصف_ڪريو META_SETROP2 0x0104
#وصف_ڪريو META_SETRELABS 0x0105
#وصف_ڪريو META_SETPOLYFILLMODE 0x0106
#وصف_ڪريو META_SETSTRETCHBLTMODE 0x0107
#وصف_ڪريو META_SETTEXTCHAREXTRA 0x0108
#وصف_ڪريو META_SETTEXTCOLOR 0x0209
#وصف_ڪريو META_SETTEXTJUSTIFICATION 0x020A
#وصف_ڪريو META_SETWINDOWORG 0x020B
#وصف_ڪريو META_SETWINDOWEXT 0x020C
#وصف_ڪريو META_SETVIEWPORTORG 0x020D
#وصف_ڪريو META_SETVIEWPORTEXT 0x020E
#وصف_ڪريو META_OFFSETWINDOWORG 0x020F
#وصف_ڪريو META_SCALEWINDOWEXT 0x0410
#وصف_ڪريو META_OFFSETVIEWPORTORG 0x0211
#وصف_ڪريو META_SCALEVIEWPORTEXT 0x0412
#وصف_ڪريو META_LINETO 0x0213
#وصف_ڪريو META_MOVETO 0x0214
#وصف_ڪريو META_EXCLUDECLIPRECT 0x0415
#وصف_ڪريو META_INTERSECTCLIPRECT 0x0416
#وصف_ڪريو META_ARC 0x0817
#وصف_ڪريو META_ELLIPSE 0x0418
#وصف_ڪريو META_FLOODFILL 0x0419
#وصف_ڪريو META_PIE 0x081A
#وصف_ڪريو META_RECTANGLE 0x041B
#وصف_ڪريو META_ROUNDRECT 0x061C
#وصف_ڪريو META_PATBLT 0x061D
#وصف_ڪريو META_SAVEDC 0x001E
#وصف_ڪريو META_SETPIXEL 0x041F
#وصف_ڪريو META_OFFSETCLIPRGN 0x0220
#وصف_ڪريو META_TEXTOUT 0x0521
#وصف_ڪريو META_BITBLT 0x0922
#وصف_ڪريو META_STRETCHBLT 0x0B23
#وصف_ڪريو META_POLYGON 0x0324
#وصف_ڪريو META_POLYLINE 0x0325
#وصف_ڪريو META_ESCAPE 0x0626
#وصف_ڪريو META_RESTOREDC 0x0127
#وصف_ڪريو META_FILLREGION 0x0228
#وصف_ڪريو META_FRAMEREGION 0x0429
#وصف_ڪريو META_INVERTREGION 0x012A
#وصف_ڪريو META_PAINTREGION 0x012B
#وصف_ڪريو META_SELECTCLIPREGION 0x012C
#وصف_ڪريو META_SELECTOBJECT 0x012D
#وصف_ڪريو META_SETTEXTALIGN 0x012E
#وصف_ڪريو META_CHORD 0x0830
#وصف_ڪريو META_SETMAPPERFLAGS 0x0231
#وصف_ڪريو META_EXTTEXTOUT 0x0a32
#وصف_ڪريو META_SETDIBTODEV 0x0d33
#وصف_ڪريو META_SELECTPALETTE 0x0234
#وصف_ڪريو META_REALIZEPALETTE 0x0035
#وصف_ڪريو META_ANIMATEPALETTE 0x0436
#وصف_ڪريو META_SETPALENTRIES 0x0037
#وصف_ڪريو META_POLYPOLYGON 0x0538
#وصف_ڪريو META_RESIZEPALETTE 0x0139
#وصف_ڪريو META_DIBBITBLT 0x0940
#وصف_ڪريو META_DIBSTRETCHBLT 0x0b41
#وصف_ڪريو META_DIBCREATEPATTERNBRUSH 0x0142
#وصف_ڪريو META_STRETCHDIB 0x0f43
#وصف_ڪريو META_EXTFLOODFILL 0x0548
#وصف_ڪريو META_SETLAYOUT 0x0149
#وصف_ڪريو META_DELETEOBJECT 0x01f0
#وصف_ڪريو META_CREATEPALETTE 0x00f7
#وصف_ڪريو META_CREATEPATTERNBRUSH 0x01F9
#وصف_ڪريو META_CREATEPENINDIRECT 0x02FA
#وصف_ڪريو META_CREATEFONTINDIRECT 0x02FB
#وصف_ڪريو META_CREATEBRUSHINDIRECT 0x02FC
#وصف_ڪريو META_CREATEREGION 0x06FF

  تعريفنوع بنية _DRAWPATRECT {
    نقطو_3 ptPosition;
    نقطو_3 pt_سائيز;
    لفظ_3 wStyle;
    لفظ_3 w_نمونو;
  } DRAWPATRECT,*PDRAWPATRECT;
#جيڪڏهن_پورو

#وصف_ڪريو NEWFRAME 1
#وصف_ڪريو ABORTDOC 2
#وصف_ڪريو NEXTBAND 3
#وصف_ڪريو SETCOLORTABLE 4
#وصف_ڪريو GETCOLORTABLE 5
#وصف_ڪريو FLUSHOUTPUT 6
#وصف_ڪريو DRAFTMODE 7
#وصف_ڪريو QUERYESCSUPPORT 8
#وصف_ڪريو SETABORTPROC 9
#وصف_ڪريو STARTDOC 10
#وصف_ڪريو ENDDOC 11
#وصف_ڪريو GETPHYSPAGESIZE 12
#وصف_ڪريو GETPRINTINGOFFSET 13
#وصف_ڪريو GETSCALINGFACTOR 14
#وصف_ڪريو MFCOMMENT 15
#وصف_ڪريو GETPENWIDTH 16
#وصف_ڪريو SETCOPYCOUNT 17
#وصف_ڪريو SELECTPAPERSOURCE 18
#وصف_ڪريو DEVICEDATA 19
#وصف_ڪريو PASSTHROUGH 19
#وصف_ڪريو GETTECHNOLGY 20
#وصف_ڪريو GETTECHNOLOGY 20
#وصف_ڪريو SETLINECAP 21
#وصف_ڪريو SETLINEJOIN 22
#وصف_ڪريو SETMITERLIMIT 23
#وصف_ڪريو BANDINFO 24
#وصف_ڪريو DRAWPATTERNRECT 25
#وصف_ڪريو GETVECTORPENSIZE 26
#وصف_ڪريو GETVECTORBRUSHSIZE 27
#وصف_ڪريو ENABLEDUPLEX 28
#وصف_ڪريو GETSETPAPERBINS 29
#وصف_ڪريو GETSETPRINTORIENT 30
#وصف_ڪريو ENUMPAPERBINS 31
#وصف_ڪريو SETDIBSCALING 32
#وصف_ڪريو EPSPRINTING 33
#وصف_ڪريو ENUMPAPERMETRICS 34
#وصف_ڪريو GETSETPAPERMETRICS 35
#وصف_ڪريو POSTSCRIPT_معلومات 37
#وصف_ڪريو POSTSCRIPT_IGNORE 38
#وصف_ڪريو MOUSETRAILS 39
#وصف_ڪريو GETDEVICEUNITS 42

#وصف_ڪريو GETEXTENDEDTEXTMETRICS 256
#وصف_ڪريو GETEXTENTTABLE 257
#وصف_ڪريو GETPAIRKERNTABLE 258
#وصف_ڪريو GETTRACKKERNTABLE 259
#وصف_ڪريو EXTTEXTOUT 512
#وصف_ڪريو GETFACENAME 513
#وصف_ڪريو DOWNLOADFACE 514
#وصف_ڪريو ENABLERELATIVEWIDTHS 768
#وصف_ڪريو ENABLEPAIRKERNING 769
#وصف_ڪريو SETKERNTRACK 770
#وصف_ڪريو SETALLJUSTVALUES 771
#وصف_ڪريو SETCHARSET 772

#وصف_ڪريو STRETCHBLT 2048
#وصف_ڪريو METAFILE_DRIVER 2049
#وصف_ڪريو GETSETSCREENPARAMS 3072
#وصف_ڪريو QUERYDIBSUPPORT 3073
#وصف_ڪريو BEGIN_رستو 4096
#وصف_ڪريو CLIP_منزل_رستو 4097
#وصف_ڪريو پڇاڙي_رستو 4098
#وصف_ڪريو EXT_DEVICE_CAPS 4099
#وصف_ڪريو RESTORE_CTM 4100
#وصف_ڪريو SAVE_CTM 4101
#وصف_ڪريو سيٽ_ARC_DIRECTION 4102
#وصف_ڪريو سيٽ_BACKGROUND_COLOR 4103
#وصف_ڪريو سيٽ_POLY_گهڻائي 4104
#وصف_ڪريو سيٽ_SCREEN_ANGLE 4105
#وصف_ڪريو سيٽ_پکيڙ 4106
#وصف_ڪريو TRANSFORM_CTM 4107
#وصف_ڪريو سيٽ_CLIP_BOX 4108
#وصف_ڪريو سيٽ_BOUNDS 4109
#وصف_ڪريو سيٽ_MIRROR_گهڻائي 4110
#وصف_ڪريو OPENCHANNEL 4110
#وصف_ڪريو DOWNLOADHEADER 4111
#وصف_ڪريو CLOSECHANNEL 4112
#وصف_ڪريو POSTSCRIPT_PASSTHROUGH 4115
#وصف_ڪريو ENCAPSULATED_POSTSCRIPT 4116

#وصف_ڪريو POSTSCRIPT_IDENTIFY 4117
#وصف_ڪريو POSTSCRIPT_INJECTION 4118

#وصف_ڪريو CHECKJPEGFORMAT 4119
#وصف_ڪريو CHECKPNGFORMAT 4120

#وصف_ڪريو GET_PS_FEATURESETTING 4121

#وصف_ڪريو SPCLPASSTHROUGH2 4568

#وصف_ڪريو PSIDENT_GDICENTRIC 0
#وصف_ڪريو PSIDENT_PSCENTRIC 1

  تعريفنوع بنية _PSINJECTDATA {
    DWORD معلومات_بائيٽون;
    لفظ_3 Injection_نقطو;
    لفظ_3 صفحو_عدد;
  } PSINJECTDATA,*PPSINJECTDATA;

#وصف_ڪريو PSINJECT_BEGINSTREAM 1
#وصف_ڪريو PSINJECT_PSADOBE 2
#وصف_ڪريو PSINJECT_PAGESATEND 3
#وصف_ڪريو PSINJECT_صفحا 4

#وصف_ڪريو PSINJECT_DOCNEEDEDRES 5
#وصف_ڪريو PSINJECT_DOCSUPPLIEDRES 6
#وصف_ڪريو PSINJECT_PAGEORDER 7
#وصف_ڪريو PSINJECT_ORIENTATION 8
#وصف_ڪريو PSINJECT_BOUNDINGBOX 9
#وصف_ڪريو PSINJECT_DOCUMENTPROCESSCOLORS 10

#وصف_ڪريو PSINJECT_COMMENTS 11
#وصف_ڪريو PSINJECT_BEGINDEFAULTS 12
#وصف_ڪريو PSINJECT_ENDDEFAULTS 13
#وصف_ڪريو PSINJECT_BEGINPROLOG 14
#وصف_ڪريو PSINJECT_ENDPROLOG 15
#وصف_ڪريو PSINJECT_BEGINSETUP 16
#وصف_ڪريو PSINJECT_ENDSETUP 17
#وصف_ڪريو PSINJECT_TRAILER 18
#وصف_ڪريو PSINJECT_EOF 19
#وصف_ڪريو PSINJECT_ENDSTREAM 20
#وصف_ڪريو PSINJECT_DOCUMENTPROCESSCOLORSATEND 21

#وصف_ڪريو PSINJECT_PAGENUMBER 100
#وصف_ڪريو PSINJECT_BEGINPAGESETUP 101
#وصف_ڪريو PSINJECT_ENDPAGESETUP 102
#وصف_ڪريو PSINJECT_PAGETRAILER 103
#وصف_ڪريو PSINJECT_PLATECOLOR 104

#وصف_ڪريو PSINJECT_SHOWPAGE 105
#وصف_ڪريو PSINJECT_PAGEBBOX 106
#وصف_ڪريو PSINJECT_ENDPAGECOMMENTS 107

#وصف_ڪريو PSINJECT_VMSAVE 200
#وصف_ڪريو PSINJECT_VMRESTORE 201

#وصف_ڪريو FEATURESETTING_NUP 0
#وصف_ڪريو FEATURESETTING_OUTPUT 1
#وصف_ڪريو FEATURESETTING_PSLEVEL 2
#وصف_ڪريو FEATURESETTING_CUSTPAPER 3
#وصف_ڪريو FEATURESETTING_MIRROR 4
#وصف_ڪريو FEATURESETTING_NEGATIVE 5
#وصف_ڪريو FEATURESETTING_PROTOCOL 6

#وصف_ڪريو FEATURESETTING_ذاتي_BEGIN 0x1000
#وصف_ڪريو FEATURESETTING_ذاتي_پڇاڙي 0x1FFF

  تعريفنوع بنية _PSFEATURE_OUTPUT {
    WINBOOL b_صفحو_Independent;
    WINBOOL b_سيٽ_صفحو_Device;
  } PSFEATURE_OUTPUT,*PPSFEATURE_OUTPUT;

  تعريفنوع بنية _PSFEATURE_CUSTPAPER {
    LONG lOrientation;
    LONG l_ويڪر;
    LONG l_اوچائي;
    LONG l_ويڪر_وٿي;
    LONG l_اوچائي_وٿي;
  } PSFEATURE_CUSTPAPER,*PPSFEATURE_CUSTPAPER;

#وصف_ڪريو PSPROTOCOL_ASCII 0
#وصف_ڪريو PSPROTOCOL_BCP 1
#وصف_ڪريو PSPROTOCOL_TBCP 2
#وصف_ڪريو PSPROTOCOL_ٻٽو 3

#وصف_ڪريو QDI_SETDIBITS 1
#وصف_ڪريو QDI_GETDIBITS 2
#وصف_ڪريو QDI_DIBTOSCREEN 4
#وصف_ڪريو QDI_STRETCHDIB 8

#وصف_ڪريو SP_NOTREPORTED 0x4000
#وصف_ڪريو SP_ERROR (-1)
#وصف_ڪريو SP_APPABORT (-2)
#وصف_ڪريو SP_USERABORT (-3)
#وصف_ڪريو SP_OUTOFDISK (-4)
#وصف_ڪريو SP_OUTOFMEMORY (-5)

#وصف_ڪريو PR_JOBSTATUS 0x0000

#وصف_ڪريو OBJ_PEN 1
#وصف_ڪريو OBJ_BRUSH 2
#وصف_ڪريو OBJ_DC 3
#وصف_ڪريو OBJ_METADC 4
#وصف_ڪريو OBJ_PAL 5
#وصف_ڪريو OBJ_FONT 6
#وصف_ڪريو OBJ_BITMAP 7
#وصف_ڪريو OBJ_REGION 8
#وصف_ڪريو OBJ_METAFILE 9
#وصف_ڪريو OBJ_MEMDC 10
#وصف_ڪريو OBJ_EXTPEN 11
#وصف_ڪريو OBJ_ENHMETADC 12
#وصف_ڪريو OBJ_ENHMETAFILE 13
#وصف_ڪريو OBJ_COLORSPACE 14

#وصف_ڪريو MWT_سڃاڻپ_عنصر 1
#وصف_ڪريو MWT_LEFTMULTIPLY 2
#وصف_ڪريو MWT_RIGHTMULTIPLY 3

#وصف_ڪريو MWT_MIN MWT_سڃاڻپ_عنصر
#وصف_ڪريو MWT_MAX MWT_RIGHTMULTIPLY

#وصف_ڪريو _XFORM_
  تعريفنوع بنية ٽيگ_XFORM {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
  } XFORM,*PXFORM,*LPXFORM;

  تعريفنوع بنية ٽيگ_BITMAP {
    LONG bmType;
    LONG bm_ويڪر;
    LONG bm_اوچائي;
    LONG bm_ويڪر_بائيٽون;
    لفظ_3 bmPlanes;
    لفظ_3 bm_بٽ_Pixel;
    LPVOID bm_بٽ;
  } BITMAP,*PBITMAP,*NPBITMAP,*LPBITMAP;

#ضمن <pshpack1.h>
  تعريفنوع بنية ٽيگ_RGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
  } RGBTRIPLE;
#ضمن <poppack.h>

  تعريفنوع بنية ٽيگ_RGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
  } RGBQUAD;
  تعريفنوع RGBQUAD *LPRGBQUAD;

#وصف_ڪريو CS_ENABLE 0x00000001L
#وصف_ڪريو CS_DISABLE 0x00000002L
#وصف_ڪريو CS_DELETE_TRANSFORM 0x00000003L

//!__TINYC__: #define LCS_SIGNATURE 'PSOC'
//!__TINYC__: #define LCS_sRGB 'sRGB'
//!__TINYC__: #define LCS_WINDOWS_COLOR_SPACE 'Win '

  تعريفنوع LONG LCSCSTYPE;
#وصف_ڪريو LCS_CALIBRATED_RGB 0x00000000L

  تعريفنوع LONG LCSGAMUTMATCH;
#وصف_ڪريو LCS_GM_BUSINESS 0x00000001L
#وصف_ڪريو LCS_GM_GRAPHICS 0x00000002L
#وصف_ڪريو LCS_GM_IMAGES 0x00000004L
#وصف_ڪريو LCS_GM_ABS_COLORIMETRIC 0x00000008L

#وصف_ڪريو CM_ٻاهريون_جو_GAMUT 255
#وصف_ڪريو CM_اندريون_GAMUT 0

#وصف_ڪريو ICM_ADDPROFILE 1
#وصف_ڪريو ICM_DELETEPROFILE 2
#وصف_ڪريو ICM_QUERYPROFILE 3
#وصف_ڪريو ICM_SETDEFAULTPROFILE 4
#وصف_ڪريو ICM_REGISTERICMATCHER 5
#وصف_ڪريو ICM_UNREGISTERICMATCHER 6
#وصف_ڪريو ICM_QUERYMATCH 7

#وصف_ڪريو GetKValue(cmyk) ((BYTE)(cmyk))
#وصف_ڪريو GetYValue(cmyk) ((BYTE)((cmyk)>> 8))
#وصف_ڪريو GetMValue(cmyk) ((BYTE)((cmyk)>>16))
#وصف_ڪريو GetCValue(cmyk) ((BYTE)((cmyk)>>24))

#وصف_ڪريو CMYK(c,m,y,k) ((COLORREF)((((BYTE)(k)|((لفظ_3)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

  تعريفنوع ڊگهو FXPT16DOT16,*LPFXPT16DOT16;
  تعريفنوع ڊگهو FXPT2DOT30,*LPFXPT2DOT30;

  تعريفنوع بنية ٽيگ_CIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
  } CIEXYZ;
  تعريفنوع CIEXYZ *LPCIEXYZ;

  تعريفنوع بنية ٽيگ_ICEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
  } CIEXYZTRIPLE;

  تعريفنوع CIEXYZTRIPLE *LPCIEXYZTRIPLE;

  تعريفنوع بنية ٽيگ_LOGCOLORSPACEA {
    DWORD lcsSignature;
    DWORD lcs_نسخو;
    DWORD lcs_سائيز;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    CHAR lcsFilename[MAX_رستو];
  } LOGCOLORSPACEA,*LPLOGCOLORSPACEA;

  تعريفنوع بنية ٽيگ_LOGCOLORSPACEW {
    DWORD lcsSignature;
    DWORD lcs_نسخو;
    DWORD lcs_سائيز;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    WCHAR lcsFilename[MAX_رستو];
  } LOGCOLORSPACEW,*LPLOGCOLORSPACEW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع LOGCOLORSPACEW LOGCOLORSPACE;
  تعريفنوع LPLOGCOLORSPACEW LPLOGCOLORSPACE;
#وإلا
  تعريفنوع LOGCOLORSPACEA LOGCOLORSPACE;
  تعريفنوع LPLOGCOLORSPACEA LPLOGCOLORSPACE;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_BITMAPCOREHEADER {
    DWORD bc_سائيز;
    لفظ_3 bc_ويڪر;
    لفظ_3 bc_اوچائي;
    لفظ_3 bcPlanes;
    لفظ_3 bc_ٻٽو_انگ_ڳڻپ;
  } BITMAPCOREHEADER,*LPBITMAPCOREHEADER,*PBITMAPCOREHEADER;

  تعريفنوع بنية ٽيگ_BITMAPINFOHEADER {
    DWORD bi_سائيز;
    LONG bi_ويڪر;
    LONG bi_اوچائي;
    لفظ_3 biPlanes;
    لفظ_3 bi_ٻٽو_انگ_ڳڻپ;
    DWORD biCompression;
    DWORD bi_سائيز_Image;
    LONG bi_XPels_في_Meter;
    LONG bi_YPels_في_Meter;
    DWORD bi_Clr_استعمال_ٿيل;
    DWORD biClrImportant;
  } BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

  تعريفنوع بنية {
    DWORD b_V4_سائيز;
    LONG b_V4_ويڪر;
    LONG b_V4_اوچائي;
    لفظ_3 bV4Planes;
    لفظ_3 b_V4_ٻٽو_انگ_ڳڻپ;
    DWORD bV4V4Compression;
    DWORD b_V4_سائيز_Image;
    LONG b_V4_XPels_في_Meter;
    LONG b_V4_YPels_في_Meter;
    DWORD b_V4_Clr_استعمال_ٿيل;
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
  } BITMAPV4_سرو,*LPBITMAPV4_سرو,*PBITMAPV4_سرو;

  تعريفنوع بنية {
    DWORD b_V5_سائيز;
    LONG b_V5_ويڪر;
    LONG b_V5_اوچائي;
    لفظ_3 bV5Planes;
    لفظ_3 b_V5_ٻٽو_انگ_ڳڻپ;
    DWORD bV5Compression;
    DWORD b_V5_سائيز_Image;
    LONG b_V5_XPels_في_Meter;
    LONG b_V5_YPels_في_Meter;
    DWORD b_V5_Clr_استعمال_ٿيل;
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
    DWORD b_V5_Profile_معلومات;
    DWORD b_V5_Profile_سائيز;
    DWORD bV5Reserved;
  } BITMAPV5_سرو,*LPBITMAPV5_سرو,*PBITMAPV5_سرو;

//!__TINYC__: #define PROFILE_LINKED 'LINK'
//!__TINYC__: #define PROFILE_EMBEDDED 'MBED'

#وصف_ڪريو BI_RGB 0L
#وصف_ڪريو BI_RLE8 1L
#وصف_ڪريو BI_RLE4 2L
#وصف_ڪريو BI_BITFIELDS 3L
#وصف_ڪريو BI_JPEG 4L
#وصف_ڪريو BI_PNG 5L

  تعريفنوع بنية ٽيگ_BITMAPINFO {
    BITMAPINFOHEADER bmi_سرو;
    RGBQUAD bmiColors[1];
  } BITMAPINFO,*LPBITMAPINFO,*PBITMAPINFO;

  تعريفنوع بنية ٽيگ_BITMAPCOREINFO {
    BITMAPCOREHEADER bmci_سرو;
    RGBTRIPLE bmciColors[1];
  } BITMAPCOREINFO,*LPBITMAPCOREINFO,*PBITMAPCOREINFO;

#ضمن <pshpack2.h>
  تعريفنوع بنية ٽيگ_BITMAPFILEHEADER {
    لفظ_3 bfType;
    DWORD bf_سائيز;
    لفظ_3 bfReserved1;
    لفظ_3 bfReserved2;
    DWORD bf_Off_بٽ;
  } BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#ضمن <poppack.h>

#وصف_ڪريو MAKEPOINTS(l) (*((POINTS *)&(l)))

#جيڪڏهن_وصف_نه_ٿيل NOFONTSIG
  تعريفنوع بنية ٽيگ_FONTSIGNATURE {
    DWORD fsUsb[4];
    DWORD fsCsb[2];
  } FONTSIGNATURE,*PFONTSIGNATURE,*LPFONTSIGNATURE;

  تعريفنوع بنية ٽيگ_CHARSETINFO {
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
  } CHARSETINFO,*PCHARSETINFO,*NPCHARSETINFO,*LPCHARSETINFO;

#وصف_ڪريو TCI_SRCCHARSET 1
#وصف_ڪريو TCI_SRCCODEPAGE 2
#وصف_ڪريو TCI_SRCFONTSIG 3
#وصف_ڪريو TCI_SRCLOCALE 0x1000

  تعريفنوع بنية ٽيگ_LOCALESIGNATURE {
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
  } LOCALESIGNATURE,*PLOCALESIGNATURE,*LPLOCALESIGNATURE;
#جيڪڏهن_پورو


#جيڪڏهن_وصف_نه_ٿيل NOMETAFILE
  تعريفنوع بنية ٽيگ_HANDLETABLE {
    HGDIOBJ objectHandle[1];
  } HANDLETABLE,*PHANDLETABLE,*LPHANDLETABLE;

  تعريفنوع بنية ٽيگ_METARECORD {
    DWORD rd_سائيز;
    لفظ_3 rdFunction;
    لفظ_3 rdParm[1];
  } METARECORD;
  تعريفنوع بنية ٽيگ_METARECORD UNALIGNED *PMETARECORD;
  تعريفنوع بنية ٽيگ_METARECORD UNALIGNED *LPMETARECORD;

  تعريفنوع بنية ٽيگ_METAFILEPICT {
    LONG mm;
    LONG xExt;
    LONG yExt;
    HMETAFILE hMF;
  } METAFILEPICT,*LPMETAFILEPICT;

#ضمن <pshpack2.h>
  تعريفنوع بنية ٽيگ_METAHEADER {
    لفظ_3 mtType;
    لفظ_3 mt_سرو_سائيز;
    لفظ_3 mt_نسخو;
    DWORD mt_سائيز;
    لفظ_3 mtNoObjects;
    DWORD mt_Max_رڪارڊ;
    لفظ_3 mtNoParameters;
  } METAHEADER;
  تعريفنوع بنية ٽيگ_METAHEADER UNALIGNED *PMETAHEADER;
  تعريفنوع بنية ٽيگ_METAHEADER UNALIGNED *LPMETAHEADER;

#ضمن <poppack.h>

  تعريفنوع بنية ٽيگ_ENHMETARECORD {
    DWORD iType;
    DWORD n_سائيز;
    DWORD dParm[1];
  } ENHMETARECORD,*PENHMETARECORD,*LPENHMETARECORD;

  تعريفنوع بنية ٽيگ_ENHMETAHEADER {
    DWORD iType;
    DWORD n_سائيز;
    RECTL rclBounds;
    RECTL rcl_چوکٺو;
    DWORD dSignature;
    DWORD n_نسخو;
    DWORD n_بائيٽون;
    DWORD n_رڪارڊون;
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
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOTEXTMETRIC
#وصف_ڪريو TMPF_FIXED_PITCH 0x01
#وصف_ڪريو TMPF_ويڪٽر 0x02
#وصف_ڪريو TMPF_DEVICE 0x08
#وصف_ڪريو TMPF_TRUETYPE 0x04

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع WCHAR BCHAR;
#وإلا
  تعريفنوع BYTE BCHAR;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _TEXTMETRIC_DEFINED
#وصف_ڪريو _TEXTMETRIC_DEFINED
  تعريفنوع بنية ٽيگ_TEXTMETRICA {
    LONG tm_اوچائي;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_اندروني_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ويڪر;
    LONG tm_Max_Char_ويڪر;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_پهريون_Char;
    BYTE tm_آخري_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ٻاهريون;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سيٽ;
  } TEXTMETRICA,*PTEXTMETRICA,*NPTEXTMETRICA,*LPTEXTMETRICA;

  تعريفنوع بنية ٽيگ_TEXTMETRICW {
    LONG tm_اوچائي;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_اندروني_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ويڪر;
    LONG tm_Max_Char_ويڪر;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_پهريون_Char;
    WCHAR tm_آخري_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ٻاهريون;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سيٽ;
  } TEXTMETRICW,*PTEXTMETRICW,*NPTEXTMETRICW,*LPTEXTMETRICW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع TEXTMETRICW TEXTMETRIC;
  تعريفنوع PTEXTMETRICW PTEXTMETRIC;
  تعريفنوع NPTEXTMETRICW NPTEXTMETRIC;
  تعريفنوع LPTEXTMETRICW LPTEXTMETRIC;
#وإلا
  تعريفنوع TEXTMETRICA TEXTMETRIC;
  تعريفنوع PTEXTMETRICA PTEXTMETRIC;
  تعريفنوع NPTEXTMETRICA NPTEXTMETRIC;
  تعريفنوع LPTEXTMETRICA LPTEXTMETRIC;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#وصف_ڪريو NTM_REGULAR 0x00000040L
#وصف_ڪريو NTM_BOLD 0x00000020L
#وصف_ڪريو NTM_ITALIC 0x00000001L

#وصف_ڪريو NTM_NONNEGATIVE_AC 0x00010000
#وصف_ڪريو NTM_PS_OPENTYPE 0x00020000
#وصف_ڪريو NTM_TT_OPENTYPE 0x00040000
#وصف_ڪريو NTM_MULTIPLEMASTER 0x00080000
#وصف_ڪريو NTM_TYPE1 0x00100000
#وصف_ڪريو NTM_DSIG 0x00200000

#ضمن <pshpack4.h>
  تعريفنوع بنية ٽيگ_NEWTEXTMETRICA {
    LONG tm_اوچائي;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_اندروني_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ويڪر;
    LONG tm_Max_Char_ويڪر;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_پهريون_Char;
    BYTE tm_آخري_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ٻاهريون;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سيٽ;
    DWORD ntmFlags;
    UINT ntm_سائيز_EM;
    UINT ntm_Cell_اوچائي;
    UINT ntm_Avg_ويڪر;
  } NEWTEXTMETRICA,*PNEWTEXTMETRICA,*NPNEWTEXTMETRICA,*LPNEWTEXTMETRICA;

  تعريفنوع بنية ٽيگ_NEWTEXTMETRICW {
    LONG tm_اوچائي;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_اندروني_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ويڪر;
    LONG tm_Max_Char_ويڪر;
    LONG tm_وزن;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_پهريون_Char;
    WCHAR tm_آخري_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ٻاهريون;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_سيٽ;
    DWORD ntmFlags;
    UINT ntm_سائيز_EM;
    UINT ntm_Cell_اوچائي;
    UINT ntm_Avg_ويڪر;
  } NEWTEXTMETRICW,*PNEWTEXTMETRICW,*NPNEWTEXTMETRICW,*LPNEWTEXTMETRICW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع NEWTEXTMETRICW NEWTEXTMETRIC;
  تعريفنوع PNEWTEXTMETRICW PNEWTEXTMETRIC;
  تعريفنوع NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
  تعريفنوع LPNEWTEXTMETRICW LPNEWTEXTMETRIC;
#وإلا
  تعريفنوع NEWTEXTMETRICA NEWTEXTMETRIC;
  تعريفنوع PNEWTEXTMETRICA PNEWTEXTMETRIC;
  تعريفنوع NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
  تعريفنوع LPNEWTEXTMETRICA LPNEWTEXTMETRIC;
#جيڪڏهن_پورو
#ضمن <poppack.h>

  تعريفنوع بنية ٽيگ_NEWTEXTMETRICEXA {
    NEWTEXTMETRICA ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXA;

  تعريفنوع بنية ٽيگ_NEWTEXTMETRICEXW {
    NEWTEXTMETRICW ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع NEWTEXTMETRICEXW NEWTEXTMETRICEX;
#وإلا
  تعريفنوع NEWTEXTMETRICEXA NEWTEXTMETRICEX;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_PELARRAY {
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
  } PELARRAY,*PPELARRAY,*NPPELARRAY,*LPPELARRAY;

  تعريفنوع بنية ٽيگ_LOGBRUSH {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
  } LOGBRUSH,*PLOGBRUSH,*NPLOGBRUSH,*LPLOGBRUSH;

  تعريفنوع بنية ٽيگ_LOGBRUSH32 {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG lbHatch;
  } LOGBRUSH32,*PLOGBRUSH32,*NPLOGBRUSH32,*LPLOGBRUSH32;

  تعريفنوع LOGBRUSH نمونو_2;
  تعريفنوع نمونو_2 *PPATTERN;
  تعريفنوع نمونو_2 *NPPATTERN;
  تعريفنوع نمونو_2 *LPPATTERN;

  تعريفنوع بنية ٽيگ_LOGPEN {
    UINT lopnStyle;
    نقطو_3 lopn_ويڪر;
    COLORREF lopnColor;
  } LOGPEN,*PLOGPEN,*NPLOGPEN,*LPLOGPEN;

  تعريفنوع بنية ٽيگ_EXTLOGPEN {
    DWORD elpPenStyle;
    DWORD elp_ويڪر;
    UINT elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elp_انگ_Entries;
    DWORD elp_Style_داخلا[1];
  } EXTLOGPEN,*PEXTLOGPEN,*NPEXTLOGPEN,*LPEXTLOGPEN;

#جيڪڏهن_وصف_نه_ٿيل _PALETTEENTRY_DEFINED
#وصف_ڪريو _PALETTEENTRY_DEFINED
  تعريفنوع بنية ٽيگ_PALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
  } PALETTEENTRY,*PPALETTEENTRY,*LPPALETTEENTRY;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل _LOGPALETTE_DEFINED
#وصف_ڪريو _LOGPALETTE_DEFINED

  تعريفنوع بنية ٽيگ_LOGPALETTE {
    لفظ_3 pal_نسخو;
    لفظ_3 pal_انگ_Entries;
    PALETTEENTRY pal_Pal_داخلا[1];
  } LOGPALETTE,*PLOGPALETTE,*NPLOGPALETTE,*LPLOGPALETTE;
#جيڪڏهن_پورو

#وصف_ڪريو LF_FACESIZE 32

  تعريفنوع بنية ٽيگ_LOGFONTA {
    LONG lf_اوچائي;
    LONG lf_ويڪر;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_وزن;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_ٻاهريون;
    BYTE lf_Char_سيٽ;
    BYTE lf_ٻاهريون_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[LF_FACESIZE];
  } LOGFONTA,*PLOGFONTA,*NPLOGFONTA,*LPLOGFONTA;

  تعريفنوع بنية ٽيگ_LOGFONTW {
    LONG lf_اوچائي;
    LONG lf_ويڪر;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_وزن;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_ٻاهريون;
    BYTE lf_Char_سيٽ;
    BYTE lf_ٻاهريون_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[LF_FACESIZE];
  } LOGFONTW,*PLOGFONTW,*NPLOGFONTW,*LPLOGFONTW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع LOGFONTW LOGFONT;
  تعريفنوع PLOGFONTW PLOGFONT;
  تعريفنوع NPLOGFONTW NPLOGFONT;
  تعريفنوع LPLOGFONTW LPLOGFONT;
#وإلا
  تعريفنوع LOGFONTA LOGFONT;
  تعريفنوع PLOGFONTA PLOGFONT;
  تعريفنوع NPLOGFONTA NPLOGFONT;
  تعريفنوع LPLOGFONTA LPLOGFONT;
#جيڪڏهن_پورو

#وصف_ڪريو LF_FULLFACESIZE 64

  تعريفنوع بنية ٽيگ_ENUMLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_ڀريل_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
  } ENUMLOGFONTA,*LPENUMLOGFONTA;

  تعريفنوع بنية ٽيگ_ENUMLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_ڀريل_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
  } ENUMLOGFONTW,*LPENUMLOGFONTW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع ENUMLOGFONTW ENUMLOGFONT;
  تعريفنوع LPENUMLOGFONTW LPENUMLOGFONT;
#وإلا
  تعريفنوع ENUMLOGFONTA ENUMLOGFONT;
  تعريفنوع LPENUMLOGFONTA LPENUMLOGFONT;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_ENUMLOGFONTEXA {
    LOGFONTA elfLogFont;
    BYTE elf_ڀريل_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    BYTE elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXA,*LPENUMLOGFONTEXA;

  تعريفنوع بنية ٽيگ_ENUMLOGFONTEXW {
    LOGFONTW elfLogFont;
    WCHAR elf_ڀريل_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    WCHAR elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXW,*LPENUMLOGFONTEXW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع ENUMLOGFONTEXW ENUMLOGFONTEX;
  تعريفنوع LPENUMLOGFONTEXW LPENUMLOGFONTEX;
#وإلا
  تعريفنوع ENUMLOGFONTEXA ENUMLOGFONTEX;
  تعريفنوع LPENUMLOGFONTEXA LPENUMLOGFONTEX;
#جيڪڏهن_پورو

#وصف_ڪريو ٻاهريون_DEFAULT_PRECIS 0
#وصف_ڪريو ٻاهريون_STRING_PRECIS 1
#وصف_ڪريو ٻاهريون_CHARACTER_PRECIS 2
#وصف_ڪريو ٻاهريون_STROKE_PRECIS 3
#وصف_ڪريو ٻاهريون_TT_PRECIS 4
#وصف_ڪريو ٻاهريون_DEVICE_PRECIS 5
#وصف_ڪريو ٻاهريون_RASTER_PRECIS 6
#وصف_ڪريو ٻاهريون_TT_ONLY_PRECIS 7
#وصف_ڪريو ٻاهريون_OUTLINE_PRECIS 8
#وصف_ڪريو ٻاهريون_SCREEN_OUTLINE_PRECIS 9
#وصف_ڪريو ٻاهريون_PS_ONLY_PRECIS 10

#وصف_ڪريو CLIP_DEFAULT_PRECIS 0
#وصف_ڪريو CLIP_CHARACTER_PRECIS 1
#وصف_ڪريو CLIP_STROKE_PRECIS 2
#وصف_ڪريو CLIP_نقاب 0xf
#وصف_ڪريو CLIP_LH_ANGLES (1<<4)
#وصف_ڪريو CLIP_TT_ALWAYS (2<<4)
#وصف_ڪريو CLIP_DFA_DISABLE (4<<4)
#وصف_ڪريو CLIP_EMBEDDED (8<<4)

#وصف_ڪريو DEFAULT_QUALITY 0
#وصف_ڪريو DRAFT_QUALITY 1
#وصف_ڪريو PROOF_QUALITY 2
#وصف_ڪريو NONANTIALIASED_QUALITY 3
#وصف_ڪريو ANTIALIASED_QUALITY 4

#وصف_ڪريو CLEARTYPE_QUALITY 5
#وصف_ڪريو CLEARTYPE_NATURAL_QUALITY 6

#وصف_ڪريو DEFAULT_PITCH 0
#وصف_ڪريو FIXED_PITCH 1
#وصف_ڪريو VARIABLE_PITCH 2
#وصف_ڪريو MONO_FONT 8

#وصف_ڪريو ANSI_CHARSET 0
#وصف_ڪريو DEFAULT_CHARSET 1
#وصف_ڪريو نشان_CHARSET 2
#وصف_ڪريو SHIFTJIS_CHARSET 128
#وصف_ڪريو HANGEUL_CHARSET 129
#وصف_ڪريو HANGUL_CHARSET 129
#وصف_ڪريو GB2312_CHARSET 134
#وصف_ڪريو CHINESEBIG5_CHARSET 136
#وصف_ڪريو OEM_CHARSET 255
#وصف_ڪريو JOHAB_CHARSET 130
#وصف_ڪريو HEBREW_CHARSET 177
#وصف_ڪريو ARABIC_CHARSET 178
#وصف_ڪريو GREEK_CHARSET 161
#وصف_ڪريو TURKISH_CHARSET 162
#وصف_ڪريو VIETNAMESE_CHARSET 163
#وصف_ڪريو THAI_CHARSET 222
#وصف_ڪريو EASTEUROPE_CHARSET 238
#وصف_ڪريو RUSSIAN_CHARSET 204

#وصف_ڪريو MAC_CHARSET 77
#وصف_ڪريو BALTIC_CHARSET 186

#وصف_ڪريو FS_LATIN1 0x00000001L
#وصف_ڪريو FS_LATIN2 0x00000002L
#وصف_ڪريو FS_CYRILLIC 0x00000004L
#وصف_ڪريو FS_GREEK 0x00000008L
#وصف_ڪريو FS_TURKISH 0x00000010L
#وصف_ڪريو FS_HEBREW 0x00000020L
#وصف_ڪريو FS_ARABIC 0x00000040L
#وصف_ڪريو FS_BALTIC 0x00000080L
#وصف_ڪريو FS_VIETNAMESE 0x00000100L
#وصف_ڪريو FS_THAI 0x00010000L
#وصف_ڪريو FS_JISJAPAN 0x00020000L
#وصف_ڪريو FS_CHINESESIMP 0x00040000L
#وصف_ڪريو FS_WANSUNG 0x00080000L
#وصف_ڪريو FS_CHINESETRAD 0x00100000L
#وصف_ڪريو FS_JOHAB 0x00200000L
#وصف_ڪريو FS_نشان 0x80000000L

#وصف_ڪريو FF_DONTCARE (0<<4)
#وصف_ڪريو FF_ROMAN (1<<4)

#وصف_ڪريو FF_SWISS (2<<4)

#وصف_ڪريو FF_MODERN (3<<4)

#وصف_ڪريو FF_SCRIPT (4<<4)
#وصف_ڪريو FF_DECORATIVE (5<<4)

#وصف_ڪريو FW_DONTCARE 0
#وصف_ڪريو FW_THIN 100
#وصف_ڪريو FW_EXTRALIGHT 200
#وصف_ڪريو FW_LIGHT 300
#وصف_ڪريو FW_عام 400
#وصف_ڪريو FW_MEDIUM 500
#وصف_ڪريو FW_SEMIBOLD 600
#وصف_ڪريو FW_BOLD 700
#وصف_ڪريو FW_EXTRABOLD 800
#وصف_ڪريو FW_HEAVY 900

#وصف_ڪريو FW_ULTRALIGHT FW_EXTRALIGHT
#وصف_ڪريو FW_REGULAR FW_عام
#وصف_ڪريو FW_DEMIBOLD FW_SEMIBOLD
#وصف_ڪريو FW_ULTRABOLD FW_EXTRABOLD
#وصف_ڪريو FW_BLACK FW_HEAVY

#وصف_ڪريو PANOSE_ڳڻپ 10
#وصف_ڪريو PAN_FAMILYTYPE_اشاريو 0
#وصف_ڪريو PAN_SERIFSTYLE_اشاريو 1
#وصف_ڪريو PAN_وزن_اشاريو 2
#وصف_ڪريو PAN_PROPORTION_اشاريو 3
#وصف_ڪريو PAN_CONTRAST_اشاريو 4
#وصف_ڪريو PAN_STROKEVARIATION_اشاريو 5
#وصف_ڪريو PAN_ARMSTYLE_اشاريو 6
#وصف_ڪريو PAN_LETTERFORM_اشاريو 7
#وصف_ڪريو PAN_MIDLINE_اشاريو 8
#وصف_ڪريو PAN_XHEIGHT_اشاريو 9

#وصف_ڪريو PAN_CULTURE_LATIN 0

  تعريفنوع بنية ٽيگ_PANOSE {
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

#وصف_ڪريو PAN_ANY 0
#وصف_ڪريو PAN_NO_FIT 1

#وصف_ڪريو PAN_FAMILY_متن_DISPLAY 2
#وصف_ڪريو PAN_FAMILY_SCRIPT 3
#وصف_ڪريو PAN_FAMILY_DECORATIVE 4
#وصف_ڪريو PAN_FAMILY_PICTORIAL 5

#وصف_ڪريو PAN_SERIF_COVE 2
#وصف_ڪريو PAN_SERIF_OBTUSE_COVE 3
#وصف_ڪريو PAN_SERIF_چورس_COVE 4
#وصف_ڪريو PAN_SERIF_OBTUSE_چورس_COVE 5
#وصف_ڪريو PAN_SERIF_چورس 6
#وصف_ڪريو PAN_SERIF_THIN 7
#وصف_ڪريو PAN_SERIF_BONE 8
#وصف_ڪريو PAN_SERIF_EXAGGERATED 9
#وصف_ڪريو PAN_SERIF_TRIANGLE 10
#وصف_ڪريو PAN_SERIF_عام_SANS 11
#وصف_ڪريو PAN_SERIF_OBTUSE_SANS 12
#وصف_ڪريو PAN_SERIF_PERP_SANS 13
#وصف_ڪريو PAN_SERIF_FLARED 14
#وصف_ڪريو PAN_SERIF_ROUNDED 15

#وصف_ڪريو PAN_وزن_VERY_LIGHT 2
#وصف_ڪريو PAN_وزن_LIGHT 3
#وصف_ڪريو PAN_وزن_THIN 4
#وصف_ڪريو PAN_وزن_BOOK 5
#وصف_ڪريو PAN_وزن_MEDIUM 6
#وصف_ڪريو PAN_وزن_DEMI 7
#وصف_ڪريو PAN_وزن_BOLD 8
#وصف_ڪريو PAN_وزن_HEAVY 9
#وصف_ڪريو PAN_وزن_BLACK 10
#وصف_ڪريو PAN_وزن_NORD 11

#وصف_ڪريو PAN_PROP_OLD_STYLE 2
#وصف_ڪريو PAN_PROP_MODERN 3
#وصف_ڪريو PAN_PROP_EVEN_ويڪر 4
#وصف_ڪريو PAN_PROP_EXPANDED 5
#وصف_ڪريو PAN_PROP_CONDENSED 6
#وصف_ڪريو PAN_PROP_VERY_EXPANDED 7
#وصف_ڪريو PAN_PROP_VERY_CONDENSED 8
#وصف_ڪريو PAN_PROP_MONOSPACED 9

#وصف_ڪريو PAN_CONTRAST_NONE 2
#وصف_ڪريو PAN_CONTRAST_VERY_هيٺيون 3
#وصف_ڪريو PAN_CONTRAST_هيٺيون 4
#وصف_ڪريو PAN_CONTRAST_MEDIUM_هيٺيون 5
#وصف_ڪريو PAN_CONTRAST_MEDIUM 6
#وصف_ڪريو PAN_CONTRAST_MEDIUM_مٿاهون 7
#وصف_ڪريو PAN_CONTRAST_مٿاهون 8
#وصف_ڪريو PAN_CONTRAST_VERY_مٿاهون 9

#وصف_ڪريو PAN_STROKE_GRADUAL_DIAG 2
#وصف_ڪريو PAN_STROKE_GRADUAL_TRAN 3
#وصف_ڪريو PAN_STROKE_GRADUAL_VERT 4
#وصف_ڪريو PAN_STROKE_GRADUAL_HORZ 5
#وصف_ڪريو PAN_STROKE_RAPID_VERT 6
#وصف_ڪريو PAN_STROKE_RAPID_HORZ 7
#وصف_ڪريو PAN_STROKE_INSTANT_VERT 8

#وصف_ڪريو PAN_STRAIGHT_ARMS_HORZ 2
#وصف_ڪريو PAN_STRAIGHT_ARMS_WEDGE 3
#وصف_ڪريو PAN_STRAIGHT_ARMS_VERT 4
#وصف_ڪريو PAN_STRAIGHT_ARMS_SINGLE_SERIF 5
#وصف_ڪريو PAN_STRAIGHT_ARMS_DOUBLE_SERIF 6
#وصف_ڪريو PAN_BENT_ARMS_HORZ 7
#وصف_ڪريو PAN_BENT_ARMS_WEDGE 8
#وصف_ڪريو PAN_BENT_ARMS_VERT 9
#وصف_ڪريو PAN_BENT_ARMS_SINGLE_SERIF 10
#وصف_ڪريو PAN_BENT_ARMS_DOUBLE_SERIF 11

#وصف_ڪريو PAN_LETT_عام_CONTACT 2
#وصف_ڪريو PAN_LETT_عام_WEIGHTED 3
#وصف_ڪريو PAN_LETT_عام_BOXED 4
#وصف_ڪريو PAN_LETT_عام_FLATTENED 5
#وصف_ڪريو PAN_LETT_عام_ROUNDED 6
#وصف_ڪريو PAN_LETT_عام_OFF_CENTER 7
#وصف_ڪريو PAN_LETT_عام_چورس 8
#وصف_ڪريو PAN_LETT_OBLIQUE_CONTACT 9
#وصف_ڪريو PAN_LETT_OBLIQUE_WEIGHTED 10
#وصف_ڪريو PAN_LETT_OBLIQUE_BOXED 11
#وصف_ڪريو PAN_LETT_OBLIQUE_FLATTENED 12
#وصف_ڪريو PAN_LETT_OBLIQUE_ROUNDED 13
#وصف_ڪريو PAN_LETT_OBLIQUE_OFF_CENTER 14
#وصف_ڪريو PAN_LETT_OBLIQUE_چورس 15

#وصف_ڪريو PAN_MIDLINE_STANDARD_TRIMMED 2
#وصف_ڪريو PAN_MIDLINE_STANDARD_POINTED 3
#وصف_ڪريو PAN_MIDLINE_STANDARD_SERIFED 4
#وصف_ڪريو PAN_MIDLINE_مٿاهون_TRIMMED 5
#وصف_ڪريو PAN_MIDLINE_مٿاهون_POINTED 6
#وصف_ڪريو PAN_MIDLINE_مٿاهون_SERIFED 7
#وصف_ڪريو PAN_MIDLINE_CONSTANT_TRIMMED 8
#وصف_ڪريو PAN_MIDLINE_CONSTANT_POINTED 9
#وصف_ڪريو PAN_MIDLINE_CONSTANT_SERIFED 10
#وصف_ڪريو PAN_MIDLINE_هيٺيون_TRIMMED 11
#وصف_ڪريو PAN_MIDLINE_هيٺيون_POINTED 12
#وصف_ڪريو PAN_MIDLINE_هيٺيون_SERIFED 13

#وصف_ڪريو PAN_XHEIGHT_CONSTANT_SMALL 2
#وصف_ڪريو PAN_XHEIGHT_CONSTANT_STD 3
#وصف_ڪريو PAN_XHEIGHT_CONSTANT_LARGE 4
#وصف_ڪريو PAN_XHEIGHT_DUCKING_SMALL 5
#وصف_ڪريو PAN_XHEIGHT_DUCKING_STD 6
#وصف_ڪريو PAN_XHEIGHT_DUCKING_LARGE 7

#وصف_ڪريو ELF_VENDOR_سائيز 4

  تعريفنوع بنية ٽيگ_EXTLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_ڀريل_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    DWORD elf_نسخو;
    DWORD elf_Style_سائيز;
    DWORD elf_ميلاپ;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_سائيز];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTA,*PEXTLOGFONTA,*NPEXTLOGFONTA,*LPEXTLOGFONTA;

  تعريفنوع بنية ٽيگ_EXTLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_ڀريل_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    DWORD elf_نسخو;
    DWORD elf_Style_سائيز;
    DWORD elf_ميلاپ;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_سائيز];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTW,*PEXTLOGFONTW,*NPEXTLOGFONTW,*LPEXTLOGFONTW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع EXTLOGFONTW EXTLOGFONT;
  تعريفنوع PEXTLOGFONTW PEXTLOGFONT;
  تعريفنوع NPEXTLOGFONTW NPEXTLOGFONT;
  تعريفنوع LPEXTLOGFONTW LPEXTLOGFONT;
#وإلا
  تعريفنوع EXTLOGFONTA EXTLOGFONT;
  تعريفنوع PEXTLOGFONTA PEXTLOGFONT;
  تعريفنوع NPEXTLOGFONTA NPEXTLOGFONT;
  تعريفنوع LPEXTLOGFONTA LPEXTLOGFONT;
#جيڪڏهن_پورو

#وصف_ڪريو ELF_نسخو 0
#وصف_ڪريو ELF_CULTURE_LATIN 0

#وصف_ڪريو RASTER_FONTTYPE 0x0001
#وصف_ڪريو DEVICE_FONTTYPE 0x002
#وصف_ڪريو TRUETYPE_FONTTYPE 0x004

#وصف_ڪريو RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((لفظ_3)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#وصف_ڪريو PALETTERGB(r,g,b) (0x02000000 | RGB(r,g,b))
#وصف_ڪريو PALETTEINDEX(i) ((COLORREF)(0x01000000 | (DWORD)(لفظ_3)(i)))

#وصف_ڪريو PC_RESERVED 0x01
#وصف_ڪريو PC_EXPLICIT 0x02
#وصف_ڪريو PC_NOCOLLAPSE 0x04

#وصف_ڪريو GetRValue(rgb) (LOBYTE(rgb))
#وصف_ڪريو GetGValue(rgb) (LOBYTE(((لفظ_3)(rgb)) >> 8))
#وصف_ڪريو GetBValue(rgb) (LOBYTE((rgb)>>16))

#وصف_ڪريو TRANSPARENT 1
#وصف_ڪريو OPAQUE 2
#وصف_ڪريو BKMODE_آخري 2

#وصف_ڪريو GM_COMPATIBLE 1
#وصف_ڪريو GM_ADVANCED 2
#وصف_ڪريو GM_آخري 2

#وصف_ڪريو PT_CLOSEFIGURE 0x01
#وصف_ڪريو PT_LINETO 0x02
#وصف_ڪريو PT_BEZIERTO 0x04
#وصف_ڪريو PT_MOVETO 0x06

#وصف_ڪريو MM_متن 1
#وصف_ڪريو MM_LOMETRIC 2
#وصف_ڪريو MM_HIMETRIC 3
#وصف_ڪريو MM_LOENGLISH 4
#وصف_ڪريو MM_HIENGLISH 5
#وصف_ڪريو MM_TWIPS 6
#وصف_ڪريو MM_ISOTROPIC 7
#وصف_ڪريو MM_ANISOTROPIC 8

#وصف_ڪريو MM_MIN MM_متن
#وصف_ڪريو MM_MAX MM_ANISOTROPIC
#وصف_ڪريو MM_MAX_FIXEDSCALE MM_TWIPS

#وصف_ڪريو ABSOLUTE 1
#وصف_ڪريو RELATIVE 2

#وصف_ڪريو WHITE_BRUSH 0
#وصف_ڪريو LTGRAY_BRUSH 1
#وصف_ڪريو ناسي_BRUSH 2
#وصف_ڪريو DKGRAY_BRUSH 3
#وصف_ڪريو BLACK_BRUSH 4
#وصف_ڪريو NULL_BRUSH 5
#وصف_ڪريو HOLLOW_BRUSH NULL_BRUSH
#وصف_ڪريو WHITE_PEN 6
#وصف_ڪريو BLACK_PEN 7
#وصف_ڪريو NULL_PEN 8
#وصف_ڪريو OEM_FIXED_FONT 10
#وصف_ڪريو ANSI_FIXED_FONT 11
#وصف_ڪريو ANSI_VAR_FONT 12
#وصف_ڪريو SYSTEM_FONT 13
#وصف_ڪريو DEVICE_DEFAULT_FONT 14
#وصف_ڪريو DEFAULT_PALETTE 15
#وصف_ڪريو SYSTEM_FIXED_FONT 16

#وصف_ڪريو DEFAULT_GUI_FONT 17

#وصف_ڪريو DC_BRUSH 18
#وصف_ڪريو DC_PEN 19

#وصف_ڪريو STOCK_آخري 19

#وصف_ڪريو CLR_INVALID 0xFFFFFFFF

#وصف_ڪريو BS_SOLID 0
#وصف_ڪريو BS_NULL 1
#وصف_ڪريو BS_HOLLOW BS_NULL
#وصف_ڪريو BS_HATCHED 2
#وصف_ڪريو BS_نمونو 3
#وصف_ڪريو BS_اشاريي_وارو 4
#وصف_ڪريو BS_DIBPATTERN 5
#وصف_ڪريو BS_DIBPATTERNPT 6
#وصف_ڪريو BS_PATTERN8X8 7
#وصف_ڪريو BS_DIBPATTERN8X8 8
#وصف_ڪريو BS_MONOPATTERN 9

#وصف_ڪريو HS_HORIZONTAL 0
#وصف_ڪريو HS_VERTICAL 1
#وصف_ڪريو HS_FDIAGONAL 2
#وصف_ڪريو HS_BDIAGONAL 3
#وصف_ڪريو HS_CROSS 4
#وصف_ڪريو HS_DIAGCROSS 5

#وصف_ڪريو PS_SOLID 0
#وصف_ڪريو PS_DASH 1
#وصف_ڪريو PS_DOT 2
#وصف_ڪريو PS_DASHDOT 3
#وصف_ڪريو PS_DASHDOTDOT 4
#وصف_ڪريو PS_NULL 5
#وصف_ڪريو PS_INSIDEFRAME 6
#وصف_ڪريو PS_USERSTYLE 7
#وصف_ڪريو PS_ALTERNATE 8
#وصف_ڪريو PS_STYLE_نقاب 0x0000000F

#وصف_ڪريو PS_ENDCAP_ڦيرو 0x00000000
#وصف_ڪريو PS_ENDCAP_چورس 0x00000100
#وصف_ڪريو PS_ENDCAP_FLAT 0x00000200
#وصف_ڪريو PS_ENDCAP_نقاب 0x00000F00

#وصف_ڪريو PS_JOIN_ڦيرو 0x00000000
#وصف_ڪريو PS_JOIN_BEVEL 0x00001000
#وصف_ڪريو PS_JOIN_MITER 0x00002000
#وصف_ڪريو PS_JOIN_نقاب 0x0000F000

#وصف_ڪريو PS_COSMETIC 0x00000000
#وصف_ڪريو PS_GEOMETRIC 0x00010000
#وصف_ڪريو PS_TYPE_نقاب 0x000F0000

#وصف_ڪريو AD_COUNTERCLOCKWISE 1
#وصف_ڪريو AD_CLOCKWISE 2

#وصف_ڪريو DRIVERVERSION 0
#وصف_ڪريو TECHNOLOGY 2
#وصف_ڪريو HORZSIZE 4
#وصف_ڪريو VERTSIZE 6
#وصف_ڪريو HORZRES 8
#وصف_ڪريو VERTRES 10
#وصف_ڪريو BITSPIXEL 12
#وصف_ڪريو PLANES 14
#وصف_ڪريو NUMBRUSHES 16
#وصف_ڪريو NUMPENS 18
#وصف_ڪريو NUMMARKERS 20
#وصف_ڪريو NUMFONTS 22
#وصف_ڪريو NUMCOLORS 24
#وصف_ڪريو PDEVICESIZE 26
#وصف_ڪريو CURVECAPS 28
#وصف_ڪريو LINECAPS 30
#وصف_ڪريو POLYGONALCAPS 32
#وصف_ڪريو TEXTCAPS 34
#وصف_ڪريو CLIPCAPS 36
#وصف_ڪريو RASTERCAPS 38
#وصف_ڪريو ASPECTX 40
#وصف_ڪريو ASPECTY 42
#وصف_ڪريو ASPECTXY 44

#وصف_ڪريو LOGPIXELSX 88
#وصف_ڪريو LOGPIXELSY 90

#وصف_ڪريو SIZEPALETTE 104
#وصف_ڪريو NUMRESERVED 106
#وصف_ڪريو COLORRES 108

#وصف_ڪريو PHYSICALWIDTH 110
#وصف_ڪريو PHYSICALHEIGHT 111
#وصف_ڪريو PHYSICALOFFSETX 112
#وصف_ڪريو PHYSICALOFFSETY 113
#وصف_ڪريو SCALINGFACTORX 114
#وصف_ڪريو SCALINGFACTORY 115

#وصف_ڪريو VREFRESH 116

#وصف_ڪريو DESKTOPVERTRES 117

#وصف_ڪريو DESKTOPHORZRES 118

#وصف_ڪريو BLTALIGNMENT 119

#وصف_ڪريو SHADEBLENDCAPS 120
#وصف_ڪريو COLORMGMTCAPS 121

#جيڪڏهن_وصف_نه_ٿيل NOGDICAPMASKS
#وصف_ڪريو DT_PLOTTER 0
#وصف_ڪريو DT_RASDISPLAY 1
#وصف_ڪريو DT_RASPRINTER 2
#وصف_ڪريو DT_RASCAMERA 3
#وصف_ڪريو DT_CHARSTREAM 4
#وصف_ڪريو DT_METAFILE 5
#وصف_ڪريو DT_DISPFILE 6

#وصف_ڪريو CC_NONE 0
#وصف_ڪريو CC_CIRCLES 1
#وصف_ڪريو CC_PIE 2
#وصف_ڪريو CC_CHORD 4
#وصف_ڪريو CC_ELLIPSES 8
#وصف_ڪريو CC_WIDE 16
#وصف_ڪريو CC_STYLED 32
#وصف_ڪريو CC_WIDESTYLED 64
#وصف_ڪريو CC_INTERIORS 128
#وصف_ڪريو CC_ROUNDRECT 256

#وصف_ڪريو LC_NONE 0
#وصف_ڪريو LC_POLYLINE 2
#وصف_ڪريو LC_MARKER 4
#وصف_ڪريو LC_POLYMARKER 8
#وصف_ڪريو LC_WIDE 16
#وصف_ڪريو LC_STYLED 32
#وصف_ڪريو LC_WIDESTYLED 64
#وصف_ڪريو LC_INTERIORS 128

#وصف_ڪريو PC_NONE 0
#وصف_ڪريو PC_POLYGON 1
#وصف_ڪريو PC_RECTANGLE 2
#وصف_ڪريو PC_WINDPOLYGON 4
#وصف_ڪريو PC_TRAPEZOID 4
#وصف_ڪريو PC_SCANLINE 8
#وصف_ڪريو PC_WIDE 16
#وصف_ڪريو PC_STYLED 32
#وصف_ڪريو PC_WIDESTYLED 64
#وصف_ڪريو PC_INTERIORS 128
#وصف_ڪريو PC_POLYPOLYGON 256
#وصف_ڪريو PC_PATHS 512

#وصف_ڪريو CP_NONE 0
#وصف_ڪريو CP_RECTANGLE 1
#وصف_ڪريو CP_REGION 2

#وصف_ڪريو TC_OP_CHARACTER 0x00000001
#وصف_ڪريو TC_OP_STROKE 0x00000002
#وصف_ڪريو TC_CP_STROKE 0x00000004
#وصف_ڪريو TC_CR_90 0x00000008
#وصف_ڪريو TC_CR_ANY 0x00000010
#وصف_ڪريو TC_SF_X_YINDEP 0x00000020
#وصف_ڪريو TC_SA_DOUBLE 0x00000040
#وصف_ڪريو TC_SA_INTEGER 0x00000080
#وصف_ڪريو TC_SA_CONTIN 0x00000100
#وصف_ڪريو TC_EA_DOUBLE 0x00000200
#وصف_ڪريو TC_IA_ABLE 0x00000400
#وصف_ڪريو TC_UA_ABLE 0x00000800
#وصف_ڪريو TC_SO_ABLE 0x00001000
#وصف_ڪريو TC_RA_ABLE 0x00002000
#وصف_ڪريو TC_VA_ABLE 0x00004000
#وصف_ڪريو TC_RESERVED 0x00008000
#وصف_ڪريو TC_SCROLLBLT 0x00010000
#جيڪڏهن_پورو

#وصف_ڪريو RC_NONE
#وصف_ڪريو RC_BITBLT 1
#وصف_ڪريو RC_BANDING 2
#وصف_ڪريو RC_SCALING 4
#وصف_ڪريو RC_BITMAP64 8
#وصف_ڪريو RC_GDI20_OUTPUT 0x0010
#وصف_ڪريو RC_GDI20_STATE 0x0020
#وصف_ڪريو RC_SAVEBITMAP 0x0040
#وصف_ڪريو RC_DI_BITMAP 0x0080
#وصف_ڪريو RC_PALETTE 0x0100
#وصف_ڪريو RC_DIBTODEV 0x0200
#وصف_ڪريو RC_BIGFONT 0x0400
#وصف_ڪريو RC_STRETCHBLT 0x0800
#وصف_ڪريو RC_FLOODFILL 0x1000
#وصف_ڪريو RC_STRETCHDIB 0x2000
#وصف_ڪريو RC_OP_DX_OUTPUT 0x4000
#وصف_ڪريو RC_DEVBITS 0x8000

#وصف_ڪريو SB_NONE 0x00000000
#وصف_ڪريو SB_CONST_ALPHA 0x00000001
#وصف_ڪريو SB_PIXEL_ALPHA 0x00000002
#وصف_ڪريو SB_PREMULT_ALPHA 0x00000004

#وصف_ڪريو SB_GRAD_RECT 0x00000010
#وصف_ڪريو SB_GRAD_TRI 0x00000020

#وصف_ڪريو CM_NONE 0x00000000
#وصف_ڪريو CM_DEVICE_ICM 0x00000001
#وصف_ڪريو CM_GAMMA_RAMP 0x00000002
#وصف_ڪريو CM_CMYK_COLOR 0x00000004

#وصف_ڪريو DIB_RGB_COLORS 0
#وصف_ڪريو DIB_PAL_COLORS 1

#وصف_ڪريو SYSPAL_ERROR 0
#وصف_ڪريو SYSPAL_STATIC 1
#وصف_ڪريو SYSPAL_NOSTATIC 2
#وصف_ڪريو SYSPAL_NOSTATIC256 3

#وصف_ڪريو CBM_INIT 0x04L

#وصف_ڪريو FLOODFILLBORDER 0
#وصف_ڪريو FLOODFILLSURFACE 1

#وصف_ڪريو CCHDEVICENAME 32

#وصف_ڪريو CCHFORMNAME 32

  تعريفنوع بنية _devicemodeA {
    BYTE dmDeviceName[CCHDEVICENAME];
    لفظ_3 dm_Spec_نسخو;
    لفظ_3 dm_Driver_نسخو;
    لفظ_3 dm_سائيز;
    لفظ_3 dmDriverExtra;
    DWORD dmFields;
    اتحاد {
      بنية {
        ننڍو dmOrientation;
        ننڍو dm_Paper_سائيز;
        ننڍو dm_Paper_ڊيگهائي;
        ننڍو dm_Paper_ويڪر;
        ننڍو dmScale;
        ننڍو dmCopies;
        ننڍو dm_Default_ذريعو;
        ننڍو dmPrintQuality;
      };
      بنية {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    ننڍو dmColor;
    ننڍو dmDuplex;
    ننڍو dmYResolution;
    ننڍو dmTTOption;
    ننڍو dmCollate;
    BYTE dmFormName[CCHFORMNAME];
    لفظ_3 dmLogPixels;
    DWORD dm_بٽ_في_Pel;
    DWORD dm_Pels_ويڪر;
    DWORD dm_Pels_اوچائي;
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
    DWORD dm_Panning_ويڪر;
    DWORD dm_Panning_اوچائي;
  } DEVMODEA,*PDEVMODEA,*NPDEVMODEA,*LPDEVMODEA;

  تعريفنوع بنية _devicemodeW {
    WCHAR dmDeviceName[CCHDEVICENAME];
    لفظ_3 dm_Spec_نسخو;
    لفظ_3 dm_Driver_نسخو;
    لفظ_3 dm_سائيز;
    لفظ_3 dmDriverExtra;
    DWORD dmFields;
    اتحاد {
      بنية {
        ننڍو dmOrientation;
        ننڍو dm_Paper_سائيز;
        ننڍو dm_Paper_ڊيگهائي;
        ننڍو dm_Paper_ويڪر;
        ننڍو dmScale;
        ننڍو dmCopies;
        ننڍو dm_Default_ذريعو;
        ننڍو dmPrintQuality;
      };
      بنية {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    ننڍو dmColor;
    ننڍو dmDuplex;
    ننڍو dmYResolution;
    ننڍو dmTTOption;
    ننڍو dmCollate;
    WCHAR dmFormName[CCHFORMNAME];
    لفظ_3 dmLogPixels;
    DWORD dm_بٽ_في_Pel;
    DWORD dm_Pels_ويڪر;
    DWORD dm_Pels_اوچائي;
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
    DWORD dm_Panning_ويڪر;
    DWORD dm_Panning_اوچائي;
  } DEVMODEW,*PDEVMODEW,*NPDEVMODEW,*LPDEVMODEW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع DEVMODEW DEVMODE;
  تعريفنوع PDEVMODEW PDEVMODE;
  تعريفنوع NPDEVMODEW NPDEVMODE;
  تعريفنوع LPDEVMODEW LPDEVMODE;
#وإلا
  تعريفنوع DEVMODEA DEVMODE;
  تعريفنوع PDEVMODEA PDEVMODE;
  تعريفنوع NPDEVMODEA NPDEVMODE;
  تعريفنوع LPDEVMODEA LPDEVMODE;
#جيڪڏهن_پورو

#وصف_ڪريو DM_SPECVERSION 0x0401

#وصف_ڪريو DM_ORIENTATION 0x00000001L
#وصف_ڪريو DM_PAPERSIZE 0x00000002L
#وصف_ڪريو DM_PAPERLENGTH 0x00000004L
#وصف_ڪريو DM_PAPERWIDTH 0x00000008L
#وصف_ڪريو DM_SCALE 0x00000010L
#وصف_ڪريو DM_POSITION 0x00000020L
#وصف_ڪريو DM_NUP 0x00000040L
#وصف_ڪريو DM_DISPLAYORIENTATION 0x00000080L
#وصف_ڪريو DM_COPIES 0x00000100L
#وصف_ڪريو DM_DEFAULTSOURCE 0x00000200L
#وصف_ڪريو DM_PRINTQUALITY 0x00000400L
#وصف_ڪريو DM_COLOR 0x00000800L
#وصف_ڪريو DM_DUPLEX 0x00001000L
#وصف_ڪريو DM_YRESOLUTION 0x00002000L
#وصف_ڪريو DM_TTOPTION 0x00004000L
#وصف_ڪريو DM_COLLATE 0x00008000L
#وصف_ڪريو DM_FORMNAME 0x00010000L
#وصف_ڪريو DM_LOGPIXELS 0x00020000L
#وصف_ڪريو DM_BITSPERPEL 0x00040000L
#وصف_ڪريو DM_PELSWIDTH 0x00080000L
#وصف_ڪريو DM_PELSHEIGHT 0x00100000L
#وصف_ڪريو DM_DISPLAYFLAGS 0x00200000L
#وصف_ڪريو DM_DISPLAYFREQUENCY 0x00400000L
#وصف_ڪريو DM_ICMMETHOD 0x00800000L
#وصف_ڪريو DM_ICMINTENT 0x01000000L
#وصف_ڪريو DM_MEDIATYPE 0x02000000L
#وصف_ڪريو DM_DITHERTYPE 0x04000000L
#وصف_ڪريو DM_PANNINGWIDTH 0x08000000L
#وصف_ڪريو DM_PANNINGHEIGHT 0x10000000L
#وصف_ڪريو DM_DISPLAYFIXEDOUTPUT 0x20000000L

#وصف_ڪريو DMORIENT_PORTRAIT 1
#وصف_ڪريو DMORIENT_LANDSCAPE 2

#وصف_ڪريو DMPAPER_پهريون DMPAPER_LETTER
#وصف_ڪريو DMPAPER_LETTER 1
#وصف_ڪريو DMPAPER_LETTERSMALL 2
#وصف_ڪريو DMPAPER_TABLOID 3
#وصف_ڪريو DMPAPER_LEDGER 4
#وصف_ڪريو DMPAPER_LEGAL 5
#وصف_ڪريو DMPAPER_STATEMENT 6
#وصف_ڪريو DMPAPER_EXECUTIVE 7
#وصف_ڪريو DMPAPER_A3 8
#وصف_ڪريو DMPAPER_A4 9
#وصف_ڪريو DMPAPER_A4SMALL 10
#وصف_ڪريو DMPAPER_A5 11
#وصف_ڪريو DMPAPER_B4 12
#وصف_ڪريو DMPAPER_B5 13
#وصف_ڪريو DMPAPER_FOLIO 14
#وصف_ڪريو DMPAPER_QUARTO 15
#وصف_ڪريو DMPAPER_10X14 16
#وصف_ڪريو DMPAPER_11X17 17
#وصف_ڪريو DMPAPER_NOTE 18
#وصف_ڪريو DMPAPER_ENV_9 19
#وصف_ڪريو DMPAPER_ENV_10 20
#وصف_ڪريو DMPAPER_ENV_11 21
#وصف_ڪريو DMPAPER_ENV_12 22
#وصف_ڪريو DMPAPER_ENV_14 23
#وصف_ڪريو DMPAPER_CSHEET 24
#وصف_ڪريو DMPAPER_DSHEET 25
#وصف_ڪريو DMPAPER_ESHEET 26
#وصف_ڪريو DMPAPER_ENV_DL 27
#وصف_ڪريو DMPAPER_ENV_C5 28
#وصف_ڪريو DMPAPER_ENV_C3 29
#وصف_ڪريو DMPAPER_ENV_C4 30
#وصف_ڪريو DMPAPER_ENV_C6 31
#وصف_ڪريو DMPAPER_ENV_C65 32
#وصف_ڪريو DMPAPER_ENV_B4 33
#وصف_ڪريو DMPAPER_ENV_B5 34
#وصف_ڪريو DMPAPER_ENV_B6 35
#وصف_ڪريو DMPAPER_ENV_ITALY 36
#وصف_ڪريو DMPAPER_ENV_MONARCH 37
#وصف_ڪريو DMPAPER_ENV_PERSONAL 38
#وصف_ڪريو DMPAPER_FANFOLD_US 39
#وصف_ڪريو DMPAPER_FANFOLD_STD_GERMAN 40
#وصف_ڪريو DMPAPER_FANFOLD_LGL_GERMAN 41
#وصف_ڪريو DMPAPER_ISO_B4 42
#وصف_ڪريو DMPAPER_JAPANESE_POSTCARD 43
#وصف_ڪريو DMPAPER_9X11 44
#وصف_ڪريو DMPAPER_10X11 45
#وصف_ڪريو DMPAPER_15X11 46
#وصف_ڪريو DMPAPER_ENV_INVITE 47
#وصف_ڪريو DMPAPER_RESERVED_48 48
#وصف_ڪريو DMPAPER_RESERVED_49 49
#وصف_ڪريو DMPAPER_LETTER_EXTRA 50
#وصف_ڪريو DMPAPER_LEGAL_EXTRA 51
#وصف_ڪريو DMPAPER_TABLOID_EXTRA 52
#وصف_ڪريو DMPAPER_A4_EXTRA 53
#وصف_ڪريو DMPAPER_LETTER_TRANSVERSE 54
#وصف_ڪريو DMPAPER_A4_TRANSVERSE 55
#وصف_ڪريو DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#وصف_ڪريو DMPAPER_A_PLUS 57
#وصف_ڪريو DMPAPER_B_PLUS 58
#وصف_ڪريو DMPAPER_LETTER_PLUS 59
#وصف_ڪريو DMPAPER_A4_PLUS 60
#وصف_ڪريو DMPAPER_A5_TRANSVERSE 61
#وصف_ڪريو DMPAPER_B5_TRANSVERSE 62
#وصف_ڪريو DMPAPER_A3_EXTRA 63
#وصف_ڪريو DMPAPER_A5_EXTRA 64
#وصف_ڪريو DMPAPER_B5_EXTRA 65
#وصف_ڪريو DMPAPER_A2 66
#وصف_ڪريو DMPAPER_A3_TRANSVERSE 67
#وصف_ڪريو DMPAPER_A3_EXTRA_TRANSVERSE 68
#وصف_ڪريو DMPAPER_DBL_JAPANESE_POSTCARD 69
#وصف_ڪريو DMPAPER_A6 70
#وصف_ڪريو DMPAPER_JENV_KAKU2 71
#وصف_ڪريو DMPAPER_JENV_KAKU3 72
#وصف_ڪريو DMPAPER_JENV_CHOU3 73
#وصف_ڪريو DMPAPER_JENV_CHOU4 74
#وصف_ڪريو DMPAPER_LETTER_ROTATED 75
#وصف_ڪريو DMPAPER_A3_ROTATED 76
#وصف_ڪريو DMPAPER_A4_ROTATED 77
#وصف_ڪريو DMPAPER_A5_ROTATED 78
#وصف_ڪريو DMPAPER_B4_JIS_ROTATED 79
#وصف_ڪريو DMPAPER_B5_JIS_ROTATED 80
#وصف_ڪريو DMPAPER_JAPANESE_POSTCARD_ROTATED 81
#وصف_ڪريو DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#وصف_ڪريو DMPAPER_A6_ROTATED 83
#وصف_ڪريو DMPAPER_JENV_KAKU2_ROTATED 84
#وصف_ڪريو DMPAPER_JENV_KAKU3_ROTATED 85
#وصف_ڪريو DMPAPER_JENV_CHOU3_ROTATED 86
#وصف_ڪريو DMPAPER_JENV_CHOU4_ROTATED 87
#وصف_ڪريو DMPAPER_B6_JIS 88
#وصف_ڪريو DMPAPER_B6_JIS_ROTATED 89
#وصف_ڪريو DMPAPER_12X11 90
#وصف_ڪريو DMPAPER_JENV_YOU4 91
#وصف_ڪريو DMPAPER_JENV_YOU4_ROTATED 92
#وصف_ڪريو DMPAPER_P16K 93
#وصف_ڪريو DMPAPER_P32K 94
#وصف_ڪريو DMPAPER_P32KBIG 95
#وصف_ڪريو DMPAPER_PENV_1 96
#وصف_ڪريو DMPAPER_PENV_2 97
#وصف_ڪريو DMPAPER_PENV_3 98
#وصف_ڪريو DMPAPER_PENV_4 99
#وصف_ڪريو DMPAPER_PENV_5 100
#وصف_ڪريو DMPAPER_PENV_6 101
#وصف_ڪريو DMPAPER_PENV_7 102
#وصف_ڪريو DMPAPER_PENV_8 103
#وصف_ڪريو DMPAPER_PENV_9 104
#وصف_ڪريو DMPAPER_PENV_10 105
#وصف_ڪريو DMPAPER_P16K_ROTATED 106
#وصف_ڪريو DMPAPER_P32K_ROTATED 107
#وصف_ڪريو DMPAPER_P32KBIG_ROTATED 108
#وصف_ڪريو DMPAPER_PENV_1_ROTATED 109
#وصف_ڪريو DMPAPER_PENV_2_ROTATED 110
#وصف_ڪريو DMPAPER_PENV_3_ROTATED 111
#وصف_ڪريو DMPAPER_PENV_4_ROTATED 112
#وصف_ڪريو DMPAPER_PENV_5_ROTATED 113
#وصف_ڪريو DMPAPER_PENV_6_ROTATED 114
#وصف_ڪريو DMPAPER_PENV_7_ROTATED 115
#وصف_ڪريو DMPAPER_PENV_8_ROTATED 116
#وصف_ڪريو DMPAPER_PENV_9_ROTATED 117
#وصف_ڪريو DMPAPER_PENV_10_ROTATED 118

#وصف_ڪريو DMPAPER_آخري DMPAPER_PENV_10_ROTATED

#وصف_ڪريو DMPAPER_USER 256

#وصف_ڪريو DMBIN_پهريون DMBIN_مٿانهون
#وصف_ڪريو DMBIN_مٿانهون 1
#وصف_ڪريو DMBIN_ONLYONE 1
#وصف_ڪريو DMBIN_هيٺاهون 2
#وصف_ڪريو DMBIN_وچ 3
#وصف_ڪريو DMBIN_MANUAL 4
#وصف_ڪريو DMBIN_ENVELOPE 5
#وصف_ڪريو DMBIN_ENVMANUAL 6
#وصف_ڪريو DMBIN_AUTO 7
#وصف_ڪريو DMBIN_TRACTOR 8
#وصف_ڪريو DMBIN_SMALLFMT 9
#وصف_ڪريو DMBIN_LARGEFMT 10
#وصف_ڪريو DMBIN_LARGECAPACITY 11
#وصف_ڪريو DMBIN_CASSETTE 14
#وصف_ڪريو DMBIN_FORMSOURCE 15
#وصف_ڪريو DMBIN_آخري DMBIN_FORMSOURCE

#وصف_ڪريو DMBIN_USER 256

#وصف_ڪريو DMRES_DRAFT (-1)
#وصف_ڪريو DMRES_هيٺيون (-2)
#وصف_ڪريو DMRES_MEDIUM (-3)
#وصف_ڪريو DMRES_مٿاهون (-4)

#وصف_ڪريو DMCOLOR_MONOCHROME 1
#وصف_ڪريو DMCOLOR_COLOR 2

#وصف_ڪريو DMDUP_SIMPLEX 1
#وصف_ڪريو DMDUP_VERTICAL 2
#وصف_ڪريو DMDUP_HORIZONTAL 3

#وصف_ڪريو DMTT_BITMAP 1
#وصف_ڪريو DMTT_DOWNLOAD 2
#وصف_ڪريو DMTT_SUBDEV 3
#وصف_ڪريو DMTT_DOWNLOAD_OUTLINE 4

#وصف_ڪريو DMCOLLATE_FALSE 0
#وصف_ڪريو DMCOLLATE_TRUE 1

#وصف_ڪريو DMDO_DEFAULT 0
#وصف_ڪريو DMDO_90 1
#وصف_ڪريو DMDO_180 2
#وصف_ڪريو DMDO_270 3

#وصف_ڪريو DMDFO_DEFAULT 0
#وصف_ڪريو DMDFO_STRETCH 1
#وصف_ڪريو DMDFO_CENTER 2

#وصف_ڪريو DMDISPLAYFLAGS_TEXTMODE 0x00000004

#وصف_ڪريو DMNUP_SYSTEM 1
#وصف_ڪريو DMNUP_ONEUP 2

#وصف_ڪريو DMICMMETHOD_NONE 1
#وصف_ڪريو DMICMMETHOD_SYSTEM 2
#وصف_ڪريو DMICMMETHOD_DRIVER 3
#وصف_ڪريو DMICMMETHOD_DEVICE 4

#وصف_ڪريو DMICMMETHOD_USER 256

#وصف_ڪريو DMICM_SATURATE 1
#وصف_ڪريو DMICM_CONTRAST 2
#وصف_ڪريو DMICM_COLORIMETRIC 3
#وصف_ڪريو DMICM_ABS_COLORIMETRIC 4

#وصف_ڪريو DMICM_USER 256

#وصف_ڪريو DMMEDIA_STANDARD 1
#وصف_ڪريو DMMEDIA_TRANSPARENCY 2
#وصف_ڪريو DMMEDIA_GLOSSY 3

#وصف_ڪريو DMMEDIA_USER 256

#وصف_ڪريو DMDITHER_NONE 1
#وصف_ڪريو DMDITHER_COARSE 2
#وصف_ڪريو DMDITHER_FINE 3
#وصف_ڪريو DMDITHER_LINEART 4
#وصف_ڪريو DMDITHER_ERRORDIFFUSION 5
#وصف_ڪريو DMDITHER_RESERVED6 6
#وصف_ڪريو DMDITHER_RESERVED7 7
#وصف_ڪريو DMDITHER_RESERVED8 8
#وصف_ڪريو DMDITHER_RESERVED9 9
#وصف_ڪريو DMDITHER_GRAYSCALE 10

#وصف_ڪريو DMDITHER_USER 256

  تعريفنوع بنية _DISPLAY_DEVICEA {
    DWORD cb;
    CHAR DeviceName[32];
    CHAR DeviceString[128];
    DWORD StateFlags;
    CHAR DeviceID[128];
    CHAR Device_ڪنجي[128];
  } DISPLAY_DEVICEA,*PDISPLAY_DEVICEA,*LPDISPLAY_DEVICEA;
  تعريفنوع بنية _DISPLAY_DEVICEW {
    DWORD cb;
    WCHAR DeviceName[32];
    WCHAR DeviceString[128];
    DWORD StateFlags;
    WCHAR DeviceID[128];
    WCHAR Device_ڪنجي[128];
  } DISPLAY_DEVICEW,*PDISPLAY_DEVICEW,*LPDISPLAY_DEVICEW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع DISPLAY_DEVICEW DISPLAY_DEVICE;
  تعريفنوع PDISPLAY_DEVICEW PDISPLAY_DEVICE;
  تعريفنوع LPDISPLAY_DEVICEW LPDISPLAY_DEVICE;
#وإلا
  تعريفنوع DISPLAY_DEVICEA DISPLAY_DEVICE;
  تعريفنوع PDISPLAY_DEVICEA PDISPLAY_DEVICE;
  تعريفنوع LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
#جيڪڏهن_پورو

#وصف_ڪريو DISPLAY_DEVICE_ATTACHED_منزل_DESKTOP 0x00000001
#وصف_ڪريو DISPLAY_DEVICE_MULTI_DRIVER 0x00000002
#وصف_ڪريو DISPLAY_DEVICE_PRIMARY_DEVICE 0x00000004
#وصف_ڪريو DISPLAY_DEVICE_MIRRORING_DRIVER 0x00000008
#وصف_ڪريو DISPLAY_DEVICE_VGA_COMPATIBLE 0x00000010
#وصف_ڪريو DISPLAY_DEVICE_REMOVABLE 0x00000020
#وصف_ڪريو DISPLAY_DEVICE_MODESPRUNED 0x08000000
#وصف_ڪريو DISPLAY_DEVICE_REMOTE 0x04000000
#وصف_ڪريو DISPLAY_DEVICE_DISCONNECT 0x02000000

#وصف_ڪريو DISPLAY_DEVICE_سرگرم 0x00000001
#وصف_ڪريو DISPLAY_DEVICE_ATTACHED 0x00000002

#وصف_ڪريو RDH_RECTANGLES 1

  تعريفنوع بنية _RGNDATAHEADER {
    DWORD dw_سائيز;
    DWORD iType;
    DWORD n_ڳڻپ;
    DWORD n_Rgn_سائيز;
    RECT rcBound;
  } RGNDATAHEADER,*PRGNDATAHEADER;

  تعريفنوع بنية _RGNDATA {
    RGNDATAHEADER rdh;
    حرف بفر_3[1];
  } RGNDATA,*PRGNDATA,*NPRGNDATA,*LPRGNDATA;

#وصف_ڪريو SYSRGN 4

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

#جيڪڏهن_وصف_نه_ٿيل NOTEXTMETRIC

  تعريفنوع بنية _OUTLINETEXTMETRICA {
    UINT otm_سائيز;
    TEXTMETRICA otm_متن_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_عدد;
    UINT otmfsSelection;
    UINT otmfsType;
    صحيح otms_Char_لاهي_Rise;
    صحيح otms_Char_لاهي_لاڳيتو;
    صحيح otmItalicAngle;
    UINT otmEMSquare;
    صحيح otmAscent;
    صحيح otmDescent;
    UINT otm_سٽ_Gap;
    UINT otms_Cap_Em_اوچائي;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    صحيح otmMacAscent;
    صحيح otmMacDescent;
    UINT otm_Mac_سٽ_Gap;
    UINT otmusMinimumPPEM;
    نقطو_3 otmpt_Subscript_سائيز;
    نقطو_3 otmpt_Subscript_وٿي;
    نقطو_3 otmpt_Superscript_سائيز;
    نقطو_3 otmpt_Superscript_وٿي;
    UINT otms_Strikeout_سائيز;
    صحيح otmsStrikeoutPosition;
    صحيح otms_Underscore_سائيز;
    صحيح otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_ڀريل_Name;
  } OUTLINETEXTMETRICA,*POUTLINETEXTMETRICA,*NPOUTLINETEXTMETRICA,*LPOUTLINETEXTMETRICA;

  تعريفنوع بنية _OUTLINETEXTMETRICW {
    UINT otm_سائيز;
    TEXTMETRICW otm_متن_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_عدد;
    UINT otmfsSelection;
    UINT otmfsType;
    صحيح otms_Char_لاهي_Rise;
    صحيح otms_Char_لاهي_لاڳيتو;
    صحيح otmItalicAngle;
    UINT otmEMSquare;
    صحيح otmAscent;
    صحيح otmDescent;
    UINT otm_سٽ_Gap;
    UINT otms_Cap_Em_اوچائي;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    صحيح otmMacAscent;
    صحيح otmMacDescent;
    UINT otm_Mac_سٽ_Gap;
    UINT otmusMinimumPPEM;
    نقطو_3 otmpt_Subscript_سائيز;
    نقطو_3 otmpt_Subscript_وٿي;
    نقطو_3 otmpt_Superscript_سائيز;
    نقطو_3 otmpt_Superscript_وٿي;
    UINT otms_Strikeout_سائيز;
    صحيح otmsStrikeoutPosition;
    صحيح otms_Underscore_سائيز;
    صحيح otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_ڀريل_Name;
  } OUTLINETEXTMETRICW,*POUTLINETEXTMETRICW,*NPOUTLINETEXTMETRICW,*LPOUTLINETEXTMETRICW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع OUTLINETEXTMETRICW OUTLINETEXTMETRIC;
  تعريفنوع POUTLINETEXTMETRICW POUTLINETEXTMETRIC;
  تعريفنوع NPOUTLINETEXTMETRICW NPOUTLINETEXTMETRIC;
  تعريفنوع LPOUTLINETEXTMETRICW LPOUTLINETEXTMETRIC;
#وإلا
  تعريفنوع OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
  تعريفنوع POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
  تعريفنوع NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
  تعريفنوع LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_POLYTEXTA {
    صحيح x;
    صحيح y;
    UINT n;
    LPCSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    صحيح *pdx;
  } POLYTEXTA,*PPOLYTEXTA,*NPPOLYTEXTA,*LPPOLYTEXTA;

  تعريفنوع بنية ٽيگ_POLYTEXTW {
    صحيح x;
    صحيح y;
    UINT n;
    LPCWSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    صحيح *pdx;
  } POLYTEXTW,*PPOLYTEXTW,*NPPOLYTEXTW,*LPPOLYTEXTW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع POLYTEXTW POLYTEXT;
  تعريفنوع PPOLYTEXTW PPOLYTEXT;
  تعريفنوع NPPOLYTEXTW NPPOLYTEXT;
  تعريفنوع LPPOLYTEXTW LPPOLYTEXT;
#وإلا
  تعريفنوع POLYTEXTA POLYTEXT;
  تعريفنوع PPOLYTEXTA PPOLYTEXT;
  تعريفنوع NPPOLYTEXTA NPPOLYTEXT;
  تعريفنوع LPPOLYTEXTA LPPOLYTEXT;
#جيڪڏهن_پورو

  تعريفنوع بنية _FIXED {
    لفظ_3 fract;
    ننڍو قدر;
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
    نقطو_3 gmptGlyphOrigin;
    ننڍو gmCellIncX;
    ننڍو gmCellIncY;
  } GLYPHMETRICS,*LPGLYPHMETRICS;

#وصف_ڪريو GGO_METRICS 0
#وصف_ڪريو GGO_BITMAP 1
#وصف_ڪريو GGO_NATIVE 2
#وصف_ڪريو GGO_BEZIER 3

#وصف_ڪريو GGO_GRAY2_BITMAP 4
#وصف_ڪريو GGO_GRAY4_BITMAP 5
#وصف_ڪريو GGO_GRAY8_BITMAP 6
#وصف_ڪريو GGO_GLYPH_اشاريو 0x0080
#وصف_ڪريو GGO_UNHINTED 0x0100

#وصف_ڪريو TT_POLYGON_TYPE 24

#وصف_ڪريو TT_PRIM_سٽ 1
#وصف_ڪريو TT_PRIM_QSPLINE 2
#وصف_ڪريو TT_PRIM_CSPLINE 3

  تعريفنوع بنية ٽيگ_POINTFX {
    FIXED x;
    FIXED y;
  } POINTFX,*LPPOINTFX;

  تعريفنوع بنية ٽيگ_TTPOLYCURVE {
    لفظ_3 wType;
    لفظ_3 cpfx;
    POINTFX apfx[1];
  } TTPOLYCURVE,*LPTTPOLYCURVE;

  تعريفنوع بنية ٽيگ_TTPOLYGONHEADER {
    DWORD cb;
    DWORD dwType;
    POINTFX pfx_شروعات;
  } TTPOLYGONHEADER,*LPTTPOLYGONHEADER;

#وصف_ڪريو GCP_DBCS 0x0001
#وصف_ڪريو GCP_REORDER 0x0002
#وصف_ڪريو GCP_USEKERNING 0x0008
#وصف_ڪريو GCP_GLYPHSHAPE 0x0010
#وصف_ڪريو GCP_LIGATE 0x0020

#وصف_ڪريو GCP_DIACRITIC 0x0100
#وصف_ڪريو GCP_KASHIDA 0x0400
#وصف_ڪريو GCP_ERROR 0x8000
#وصف_ڪريو FLI_نقاب 0x103B

#وصف_ڪريو GCP_JUSTIFY 0x00010000L

#وصف_ڪريو FLI_GLYPHS 0x00040000L
#وصف_ڪريو GCP_CLASSIN 0x00080000L
#وصف_ڪريو GCP_MAXEXTENT 0x00100000L
#وصف_ڪريو GCP_JUSTIFYIN 0x00200000L
#وصف_ڪريو GCP_DISPLAYZWG 0x00400000L
#وصف_ڪريو GCP_SYMSWAPOFF 0x00800000L
#وصف_ڪريو GCP_NUMERICOVERRIDE 0x01000000L
#وصف_ڪريو GCP_NEUTRALOVERRIDE 0x02000000L
#وصف_ڪريو GCP_NUMERICSLATIN 0x04000000L
#وصف_ڪريو GCP_NUMERICSLOCAL 0x08000000L

#وصف_ڪريو GCPCLASS_LATIN 1
#وصف_ڪريو GCPCLASS_HEBREW 2
#وصف_ڪريو GCPCLASS_ARABIC 2
#وصف_ڪريو GCPCLASS_NEUTRAL 3
#وصف_ڪريو GCPCLASS_LOCALNUMBER 4
#وصف_ڪريو GCPCLASS_LATINNUMBER 5
#وصف_ڪريو GCPCLASS_LATINNUMERICTERMINATOR 6
#وصف_ڪريو GCPCLASS_LATINNUMERICSEPARATOR 7
#وصف_ڪريو GCPCLASS_NUMERICSEPARATOR 8
#وصف_ڪريو GCPCLASS_PREBOUNDLTR 0x80
#وصف_ڪريو GCPCLASS_PREBOUNDRTL 0x40
#وصف_ڪريو GCPCLASS_POSTBOUNDLTR 0x20
#وصف_ڪريو GCPCLASS_POSTBOUNDRTL 0x10

#وصف_ڪريو GCPGLYPH_LINKBEFORE 0x8000
#وصف_ڪريو GCPGLYPH_LINKAFTER 0x4000

  تعريفنوع بنية ٽيگ_GCP_RESULTSA {
    DWORD l_Struct_سائيز;
    LPSTR lp_ٻاهريون_String;
    UINT *lp_ترتيب;
    صحيح *lpDx;
    صحيح *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    صحيح nMaxFit;
  } GCP_RESULTSA,*LPGCP_RESULTSA;
  تعريفنوع بنية ٽيگ_GCP_RESULTSW {
    DWORD l_Struct_سائيز;
    LPWSTR lp_ٻاهريون_String;
    UINT *lp_ترتيب;
    صحيح *lpDx;
    صحيح *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    صحيح nMaxFit;
  } GCP_RESULTSW,*LPGCP_RESULTSW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع GCP_RESULTSW GCP_RESULTS;
  تعريفنوع LPGCP_RESULTSW LPGCP_RESULTS;
#وإلا
  تعريفنوع GCP_RESULTSA GCP_RESULTS;
  تعريفنوع LPGCP_RESULTSA LPGCP_RESULTS;
#جيڪڏهن_پورو

  تعريفنوع بنية RASTERIZER_حالت {
    ننڍو n_سائيز;
    ننڍو wFlags;
    ننڍو nLanguageID;
  } RASTERIZER_حالت_2,*LPRASTERIZER_حالت;

#وصف_ڪريو TT_موجود 0x0001
#وصف_ڪريو TT_ENABLED 0x0002

  تعريفنوع بنية ٽيگ_PIXELFORMATDESCRIPTOR {
    لفظ_3 n_سائيز;
    لفظ_3 n_نسخو;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_بٽ;
    BYTE c_Red_بٽ;
    BYTE c_Red_سرڪايو;
    BYTE c_Green_بٽ;
    BYTE c_Green_سرڪايو;
    BYTE c_Blue_بٽ;
    BYTE c_Blue_سرڪايو;
    BYTE c_Alpha_بٽ;
    BYTE c_Alpha_سرڪايو;
    BYTE c_Accum_بٽ;
    BYTE c_Accum_Red_بٽ;
    BYTE c_Accum_Green_بٽ;
    BYTE c_Accum_Blue_بٽ;
    BYTE c_Accum_Alpha_بٽ;
    BYTE c_اونهائي_بٽ;
    BYTE c_Stencil_بٽ;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dw_Layer_نقاب;
    DWORD dw_Visible_نقاب;
    DWORD dw_Damage_نقاب;
  } PIXELFORMATDESCRIPTOR,*PPIXELFORMATDESCRIPTOR,*LPPIXELFORMATDESCRIPTOR;

#وصف_ڪريو PFD_TYPE_RGBA 0
#وصف_ڪريو PFD_TYPE_COLORINDEX 1

#وصف_ڪريو PFD_MAIN_PLANE 0
#وصف_ڪريو PFD_OVERLAY_PLANE 1
#وصف_ڪريو PFD_UNDERLAY_PLANE (-1)

#وصف_ڪريو PFD_DOUBLEBUFFER 0x00000001
#وصف_ڪريو PFD_STEREO 0x00000002
#وصف_ڪريو PFD_DRAW_منزل_دري 0x00000004
#وصف_ڪريو PFD_DRAW_منزل_BITMAP 0x00000008
#وصف_ڪريو PFD_SUPPORT_GDI 0x00000010
#وصف_ڪريو PFD_SUPPORT_OPENGL 0x00000020
#وصف_ڪريو PFD_GENERIC_FORMAT 0x00000040
#وصف_ڪريو PFD_NEED_PALETTE 0x00000080
#وصف_ڪريو PFD_NEED_SYSTEM_PALETTE 0x00000100
#وصف_ڪريو PFD_مٽا_سٽا_EXCHANGE 0x00000200
#وصف_ڪريو PFD_مٽا_سٽا_COPY 0x00000400
#وصف_ڪريو PFD_مٽا_سٽا_LAYER_BUFFERS 0x00000800
#وصف_ڪريو PFD_GENERIC_ACCELERATED 0x00001000
#وصف_ڪريو PFD_SUPPORT_DIRECTDRAW 0x00002000

#وصف_ڪريو PFD_اونهائي_DONTCARE 0x20000000
#وصف_ڪريو PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#وصف_ڪريو PFD_STEREO_DONTCARE 0x80000000

#جيڪڏهن_وصف_نه_ٿيل NOTEXTMETRIC
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST TEXTMETRICA *,DWORD,LPARAM);
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST TEXTMETRICW *,DWORD,LPARAM);
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو OLDFONTENUMPROC OLDFONTENUMPROCW
#وإلا
#وصف_ڪريو OLDFONTENUMPROC OLDFONTENUMPROCA
#جيڪڏهن_پورو
#وإلا
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST VOID *,DWORD,LPARAM);
  تعريفنوع صحيح (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST VOID *,DWORD,LPARAM);
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو OLDFONTENUMPROC OLDFONTENUMPROCW
#وإلا
#وصف_ڪريو OLDFONTENUMPROC OLDFONTENUMPROCA
#جيڪڏهن_پورو
#جيڪڏهن_پورو

  تعريفنوع OLDFONTENUMPROCA FONTENUMPROCA;
  تعريفنوع OLDFONTENUMPROCW FONTENUMPROCW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع FONTENUMPROCW FONTENUMPROC;
#وإلا
  تعريفنوع FONTENUMPROCA FONTENUMPROC;
#جيڪڏهن_پورو

  تعريفنوع صحيح (CALLBACK *GOBJENUMPROC)(LPVOID,LPARAM);
  تعريفنوع VOID (CALLBACK *LINEDDAPROC)(صحيح,صحيح,LPARAM);

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو جوڙيو_Font_Resource جوڙيو_Font_Resource_W
#وصف_ڪريو CopyMetaFile CopyMetaFileW
#وصف_ڪريو CreateDC CreateDCW
#وصف_ڪريو Create_Font_اڻسڌو Create_Font_اڻسڌو_W
#وصف_ڪريو CreateFont CreateFontW
#وصف_ڪريو CreateIC CreateICW
#وصف_ڪريو CreateMetaFile CreateMetaFileW
#وصف_ڪريو CreateScalableFontResource CreateScalableFontResourceW
#وإلا
#وصف_ڪريو جوڙيو_Font_Resource جوڙيو_Font_Resource_A
#وصف_ڪريو CopyMetaFile CopyMetaFileA
#وصف_ڪريو CreateDC CreateDCA
#وصف_ڪريو Create_Font_اڻسڌو Create_Font_اڻسڌو_A
#وصف_ڪريو CreateFont CreateFontA
#وصف_ڪريو CreateIC CreateICA
#وصف_ڪريو CreateMetaFile CreateMetaFileA
#وصف_ڪريو CreateScalableFontResource CreateScalableFontResourceA
#جيڪڏهن_پورو

  WINGDIAPI صحيح WINAPI جوڙيو_Font_Resource_A(LPCSTR);
  WINGDIAPI صحيح WINAPI جوڙيو_Font_Resource_W(LPCWSTR);
  WINGDIAPI WINBOOL WINAPI AnimatePalette(HPALETTE hPal,UINT i_شروعات_اشاريو,UINT cEntries,CONST PALETTEENTRY *ppe);
  WINGDIAPI WINBOOL WINAPI Arc(HDC hdc,صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح x3,صحيح y3,صحيح x4,صحيح y4);
  WINGDIAPI WINBOOL WINAPI ٻٽو_انگ_Blt(HDC hdc,صحيح x,صحيح y,صحيح cx,صحيح cy,HDC hdcSrc,صحيح x1,صحيح y1,DWORD rop);
  WINGDIAPI WINBOOL WINAPI CancelDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Chord(HDC hdc,صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح x3,صحيح y3,صحيح x4,صحيح y4);
  WINGDIAPI صحيح WINAPI چونڊيو_Pixel_Format(HDC hdc,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI HMETAFILE WINAPI CloseMetaFile(HDC hdc);
  WINGDIAPI صحيح WINAPI CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,صحيح i_گهڻائي);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
  WINGDIAPI HBITMAP WINAPI CreateBitmap(صحيح n_ويڪر,صحيح n_اوچائي,UINT nPlanes,UINT n_ٻٽو_انگ_ڳڻپ,CONST VOID *lp_بٽ);
  WINGDIAPI HBITMAP WINAPI Create_Bitmap_اڻسڌو(CONST BITMAP *pbm);
  WINGDIAPI HBRUSH WINAPI Create_Brush_اڻسڌو(CONST LOGBRUSH *plbrush);
  WINGDIAPI HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc,صحيح cx,صحيح cy);
  WINGDIAPI HBITMAP WINAPI CreateDiscardableBitmap(HDC hdc,صحيح cx,صحيح cy);
  WINGDIAPI HDC WINAPI CreateCompatibleDC(HDC hdc);
  WINGDIAPI HDC WINAPI CreateDCA(LPCSTR pwszDriver,LPCSTR pwszDevice,LPCSTR psz_پورٽ,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateDCW(LPCWSTR pwszDriver,LPCWSTR pwszDevice,LPCWSTR psz_پورٽ,CONST DEVMODEW *pdm);
  WINGDIAPI HBITMAP WINAPI CreateDIBitmap(HDC hdc,CONST BITMAPINFOHEADER *pbmih,DWORD flInit,CONST VOID *pj_بٽ,CONST BITMAPINFO *pbmi,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL h,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB,UINT iUsage);
  WINGDIAPI HRGN WINAPI CreateEllipticRgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2);
  WINGDIAPI HRGN WINAPI Create_Elliptic_Rgn_اڻسڌو(CONST RECT *lprect);
  WINGDIAPI HFONT WINAPI Create_Font_اڻسڌو_A(CONST LOGFONTA *lplf);
  WINGDIAPI HFONT WINAPI Create_Font_اڻسڌو_W(CONST LOGFONTW *lplf);
  WINGDIAPI HFONT WINAPI CreateFontA(صحيح c_اوچائي,صحيح c_ويڪر,صحيح cEscapement,صحيح cOrientation,صحيح c_وزن,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_ٻاهريون,DWORD i_Char_سيٽ,DWORD i_ٻاهريون_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCSTR pszFaceName);
  WINGDIAPI HFONT WINAPI CreateFontW(صحيح c_اوچائي,صحيح c_ويڪر,صحيح cEscapement,صحيح cOrientation,صحيح c_وزن,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_ٻاهريون,DWORD i_Char_سيٽ,DWORD i_ٻاهريون_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCWSTR pszFaceName);
  WINGDIAPI HBRUSH WINAPI CreateHatchBrush(صحيح iHatch,COLORREF color);
  WINGDIAPI HDC WINAPI CreateICA(LPCSTR pszDriver,LPCSTR pszDevice,LPCSTR psz_پورٽ,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateICW(LPCWSTR pszDriver,LPCWSTR pszDevice,LPCWSTR psz_پورٽ,CONST DEVMODEW *pdm);
  WINGDIAPI HDC WINAPI CreateMetaFileA(LPCSTR pszFile);
  WINGDIAPI HDC WINAPI CreateMetaFileW(LPCWSTR pszFile);
  WINGDIAPI HPALETTE WINAPI CreatePalette(CONST LOGPALETTE *plpal);
  WINGDIAPI HPEN WINAPI CreatePen(صحيح iStyle,صحيح c_ويڪر,COLORREF color);
  WINGDIAPI HPEN WINAPI Create_Pen_اڻسڌو(CONST LOGPEN *plpen);
  WINGDIAPI HRGN WINAPI CreatePolyPolygonRgn(CONST نقطو_3 *pptl,CONST INT *pc,صحيح cPoly,صحيح i_گهڻائي);
  WINGDIAPI HBRUSH WINAPI Create_نمونو_Brush(HBITMAP hbm);
  WINGDIAPI HRGN WINAPI CreateRectRgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2);
  WINGDIAPI HRGN WINAPI Create_Rect_Rgn_اڻسڌو(CONST RECT *lprect);
  WINGDIAPI HRGN WINAPI Create_ڦيرو_Rect_Rgn(صحيح x1,صحيح y1,صحيح x2,صحيح y2,صحيح w,صحيح h);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceA(DWORD fdwHidden,LPCSTR lpszFont,LPCSTR lpszFile,LPCSTR lpsz_رستو);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceW(DWORD fdwHidden,LPCWSTR lpszFont,LPCWSTR lpszFile,LPCWSTR lpsz_رستو);
  WINGDIAPI HBRUSH WINAPI CreateSolidBrush(COLORREF color);
  WINGDIAPI WINBOOL WINAPI DeleteDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI DeleteMetaFile(HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI DeleteObject(HGDIOBJ ho);
  WINGDIAPI صحيح WINAPI DescribePixelFormat(HDC hdc,صحيح iPixelFormat,UINT n_بائيٽون,LPPIXELFORMATDESCRIPTOR ppfd);

  تعريفنوع UINT (CALLBACK *LPFNDEVMODE)(HWND,HMODULE,LPDEVMODE,LPSTR,LPSTR,LPDEVMODE,LPSTR,UINT);
  تعريفنوع DWORD (CALLBACK *LPFNDEVCAPS)(LPSTR,LPSTR,UINT,LPSTR,LPDEVMODE);

#وصف_ڪريو DM_UPDATE 1
#وصف_ڪريو DM_COPY 2
#وصف_ڪريو DM_PROMPT 4
#وصف_ڪريو DM_MODIFY 8

#وصف_ڪريو DM_اندريون_بفر DM_MODIFY
#وصف_ڪريو DM_اندريون_PROMPT DM_PROMPT
#وصف_ڪريو DM_ٻاهريون_بفر DM_COPY
#وصف_ڪريو DM_ٻاهريون_DEFAULT DM_UPDATE

#وصف_ڪريو DC_FIELDS 1
#وصف_ڪريو DC_PAPERS 2
#وصف_ڪريو DC_PAPERSIZE 3
#وصف_ڪريو DC_MINEXTENT 4
#وصف_ڪريو DC_MAXEXTENT 5
#وصف_ڪريو DC_BINS 6
#وصف_ڪريو DC_DUPLEX 7
#وصف_ڪريو DC_سائيز 8
#وصف_ڪريو DC_EXTRA 9
#وصف_ڪريو DC_نسخو 10
#وصف_ڪريو DC_DRIVER 11
#وصف_ڪريو DC_BINNAMES 12
#وصف_ڪريو DC_ENUMRESOLUTIONS 13
#وصف_ڪريو DC_FILEDEPENDENCIES 14
#وصف_ڪريو DC_TRUETYPE 15
#وصف_ڪريو DC_PAPERNAMES 16
#وصف_ڪريو DC_ORIENTATION 17
#وصف_ڪريو DC_COPIES 18
#وصف_ڪريو DC_BINADJUST 19
#وصف_ڪريو DC_EMF_COMPLIANT 20
#وصف_ڪريو DC_DATATYPE_PRODUCED 21
#وصف_ڪريو DC_COLLATE 22
#وصف_ڪريو DC_MANUFACTURER 23
#وصف_ڪريو DC_MODEL 24
#وصف_ڪريو DC_PERSONALITY 25
#وصف_ڪريو DC_PRINTRATE 26
#وصف_ڪريو DC_PRINTRATEUNIT 27
#وصف_ڪريو PRINTRATEUNIT_PPM 1
#وصف_ڪريو PRINTRATEUNIT_CPS 2
#وصف_ڪريو PRINTRATEUNIT_LPM 3
#وصف_ڪريو PRINTRATEUNIT_IPM 4
#وصف_ڪريو DC_PRINTERMEM 28
#وصف_ڪريو DC_MEDIAREADY 29
#وصف_ڪريو DC_STAPLE 30
#وصف_ڪريو DC_PRINTRATEPPM 31
#وصف_ڪريو DC_COLORDEVICE 32
#وصف_ڪريو DC_NUP 33
#وصف_ڪريو DC_MEDIATYPENAMES 34
#وصف_ڪريو DC_MEDIATYPES 35

#وصف_ڪريو DCTT_BITMAP 0x0000001L
#وصف_ڪريو DCTT_DOWNLOAD 0x0000002L
#وصف_ڪريو DCTT_SUBDEV 0x0000004L
#وصف_ڪريو DCTT_DOWNLOAD_OUTLINE 0x0000008L

#وصف_ڪريو DCBA_FACEUPNONE 0x0000
#وصف_ڪريو DCBA_FACEUPCENTER 0x0001
#وصف_ڪريو DCBA_FACEUPLEFT 0x0002
#وصف_ڪريو DCBA_FACEUPRIGHT 0x0003
#وصف_ڪريو DCBA_FACEDOWNNONE 0x0100
#وصف_ڪريو DCBA_FACEDOWNCENTER 0x0101
#وصف_ڪريو DCBA_FACEDOWNLEFT 0x0102
#وصف_ڪريو DCBA_FACEDOWNRIGHT 0x0103

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو DeviceCapabilities DeviceCapabilitiesW
#وصف_ڪريو EnumFontFamiliesEx EnumFontFamiliesExW
#وصف_ڪريو EnumFontFamilies EnumFontFamiliesW
#وصف_ڪريو EnumFonts EnumFontsW
#وصف_ڪريو Get_Char_ويڪر Get_Char_ويڪر_W
#وصف_ڪريو GetCharWidth32 GetCharWidth32W
#وصف_ڪريو Get_Char_ويڪر_Float Get_Char_ويڪر_Float_W
#وصف_ڪريو GetCharABCWidths GetCharABCWidthsW
#وصف_ڪريو GetCharABCWidthsFloat GetCharABCWidthsFloatW
#وصف_ڪريو GetGlyphOutline GetGlyphOutlineW
#وصف_ڪريو GetMetaFile GetMetaFileW
#وإلا
#وصف_ڪريو DeviceCapabilities DeviceCapabilitiesA
#وصف_ڪريو EnumFontFamiliesEx EnumFontFamiliesExA
#وصف_ڪريو EnumFontFamilies EnumFontFamiliesA
#وصف_ڪريو EnumFonts EnumFontsA
#وصف_ڪريو Get_Char_ويڪر Get_Char_ويڪر_A
#وصف_ڪريو GetCharWidth32 GetCharWidth32A
#وصف_ڪريو Get_Char_ويڪر_Float Get_Char_ويڪر_Float_A
#وصف_ڪريو GetCharABCWidths GetCharABCWidthsA
#وصف_ڪريو GetCharABCWidthsFloat GetCharABCWidthsFloatA
#وصف_ڪريو GetGlyphOutline GetGlyphOutlineA
#وصف_ڪريو GetMetaFile GetMetaFileA
#جيڪڏهن_پورو

  WINSPOOLAPI صحيح WINAPI DeviceCapabilitiesA(LPCSTR pDevice,LPCSTR p_پورٽ,لفظ_3 fwCapability,LPSTR pOutput,CONST DEVMODEA *p_Dev_گهڻائي);
  WINSPOOLAPI صحيح WINAPI DeviceCapabilitiesW(LPCWSTR pDevice,LPCWSTR p_پورٽ,لفظ_3 fwCapability,LPWSTR pOutput,CONST DEVMODEW *p_Dev_گهڻائي);
  WINGDIAPI صحيح WINAPI DrawEscape(HDC hdc,صحيح iEscape,صحيح cj_اندريون,LPCSTR lp_اندريون);
  WINGDIAPI WINBOOL WINAPI Ellipse(HDC hdc,صحيح کاٻو,صحيح چوٽي,صحيح ساڄو,صحيح bottom);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesExA(HDC hdc,LPLOGFONTA lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesExW(HDC hdc,LPLOGFONTW lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontFamiliesW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontsA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumFontsW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI صحيح WINAPI EnumObjects(HDC hdc,صحيح nType,GOBJENUMPROC lpFunc,LPARAM lParam);
  WINGDIAPI WINBOOL WINAPI EqualRgn(HRGN hrgn1,HRGN hrgn2);
  WINGDIAPI صحيح WINAPI Escape(HDC hdc,صحيح iEscape,صحيح cj_اندريون,LPCSTR pv_اندريون,LPVOID pv_ٻاهريون);
  WINGDIAPI صحيح WINAPI ExtEscape(HDC hdc,صحيح iEscape,صحيح cj_داخلا,LPCSTR lp_اندريون_معلومات,صحيح cjOutput,LPSTR lp_ٻاهريون_معلومات);
  WINGDIAPI صحيح WINAPI ExcludeClipRect(HDC hdc,صحيح کاٻو,صحيح چوٽي,صحيح ساڄو,صحيح bottom);
  WINGDIAPI HRGN WINAPI ExtCreateRegion(CONST XFORM *lpx,DWORD n_ڳڻپ,CONST RGNDATA *lp_معلومات);
  WINGDIAPI WINBOOL WINAPI ExtFloodFill(HDC hdc,صحيح x,صحيح y,COLORREF color,UINT type);
  WINGDIAPI WINBOOL WINAPI FillRgn(HDC hdc,HRGN hrgn,HBRUSH hbr);
  WINGDIAPI WINBOOL WINAPI FloodFill(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI چوکٺو_Rgn(HDC hdc,HRGN hrgn,HBRUSH hbr,صحيح w,صحيح h);
  WINGDIAPI صحيح WINAPI GetROP2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_Aspect_تناسب_Filter_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI COLORREF WINAPI GetBkColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCBrushColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCPenColor(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Bk_گهڻائي(HDC hdc);
  WINGDIAPI LONG WINAPI Get_Bitmap_بٽ(HBITMAP hbit,LONG cb,LPVOID lpv_بٽ);
  WINGDIAPI WINBOOL WINAPI GetBitmapDimensionEx(HBITMAP hbit,LPSIZE lpsize);
  WINGDIAPI UINT WINAPI GetBoundsRect(HDC hdc,LPRECT lprect,UINT flags);
  WINGDIAPI WINBOOL WINAPI GetBrushOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI Get_Char_ويڪر_A(HDC hdc,UINT i_پهريون,UINT i_آخري,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI Get_Char_ويڪر_W(HDC hdc,UINT i_پهريون,UINT i_آخري,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32A(HDC hdc,UINT i_پهريون,UINT i_آخري,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32W(HDC hdc,UINT i_پهريون,UINT i_آخري,LPINT lp_بفر);
  WINGDIAPI WINBOOL WINAPI Get_Char_ويڪر_Float_A(HDC hdc,UINT i_پهريون,UINT i_آخري,PFLOAT lp_بفر);
  WINGDIAPI WINBOOL WINAPI Get_Char_ويڪر_Float_W(HDC hdc,UINT i_پهريون,UINT i_آخري,PFLOAT lp_بفر);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsA(HDC hdc,UINT w_پهريون,UINT w_آخري,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsW(HDC hdc,UINT w_پهريون,UINT w_آخري,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatA(HDC hdc,UINT i_پهريون,UINT i_آخري,LPABCFLOAT lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatW(HDC hdc,UINT i_پهريون,UINT i_آخري,LPABCFLOAT lpABC);
  WINGDIAPI صحيح WINAPI GetClipBox(HDC hdc,LPRECT lprect);
  WINGDIAPI صحيح WINAPI GetClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI صحيح WINAPI GetMetaRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI HGDIOBJ WINAPI GetCurrentObject(HDC hdc,UINT type);
  WINGDIAPI WINBOOL WINAPI GetCurrentPositionEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI صحيح WINAPI GetDeviceCaps(HDC hdc,صحيح اشاريو);
  WINGDIAPI صحيح WINAPI GetDIBits(HDC hdc,HBITMAP hbm,UINT شروعات,UINT c_سٽون,LPVOID lpv_بٽ,LPBITMAPINFO lpbmi,UINT usage);
  WINGDIAPI DWORD WINAPI Get_Font_معلومات (HDC hdc,DWORD dw_جدول,DWORD dw_وٿي,PVOID pv_بفر,DWORD cj_بفر);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineA(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_بفر,LPVOID pv_بفر,CONST MAT2 *lpmat2);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineW(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_بفر,LPVOID pv_بفر,CONST MAT2 *lpmat2);
  WINGDIAPI صحيح WINAPI Get_Graphics_گهڻائي(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Map_گهڻائي(HDC hdc);
  WINGDIAPI UINT WINAPI Get_Meta_File_بٽ_Ex(HMETAFILE hMF,UINT cb_بفر,LPVOID lp_معلومات);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileA(LPCSTR lpName);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileW(LPCWSTR lpName);
  WINGDIAPI COLORREF WINAPI Get_سڀ_کان_ويجهو_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI Get_سڀ_کان_ويجهو_Palette_اشاريو(HPALETTE h,COLORREF color);
  WINGDIAPI DWORD WINAPI GetObjectType(HGDIOBJ h);

#جيڪڏهن_وصف_نه_ٿيل NOTEXTMETRIC
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_Outline_متن_Metrics Get_Outline_متن_Metrics_W
#وإلا
#وصف_ڪريو Get_Outline_متن_Metrics Get_Outline_متن_Metrics_A
#جيڪڏهن_پورو

  WINGDIAPI UINT WINAPI Get_Outline_متن_Metrics_A(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICA potm);
  WINGDIAPI UINT WINAPI Get_Outline_متن_Metrics_W(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICW potm);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_متن_Extent_نقطو Get_متن_Extent_نقطو_W
#وصف_ڪريو Get_متن_Extent_Point32 Get_متن_Extent_Point32_W
#وصف_ڪريو Get_متن_Extent_Ex_نقطو Get_متن_Extent_Ex_نقطو_W
#وصف_ڪريو GetCharacterPlacement GetCharacterPlacementW
#وإلا
#وصف_ڪريو Get_متن_Extent_نقطو Get_متن_Extent_نقطو_A
#وصف_ڪريو Get_متن_Extent_Point32 Get_متن_Extent_Point32_A
#وصف_ڪريو Get_متن_Extent_Ex_نقطو Get_متن_Extent_Ex_نقطو_A
#وصف_ڪريو GetCharacterPlacement GetCharacterPlacementA
#جيڪڏهن_پورو

  WINGDIAPI UINT WINAPI GetPaletteEntries(HPALETTE hpal,UINT i_شروعات,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI COLORREF WINAPI GetPixel(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI صحيح WINAPI GetPixelFormat(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_Poly_Fill_گهڻائي(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetRasterizerCaps(LPRASTERIZER_حالت lpraststat,UINT cj_بائيٽون);
  WINGDIAPI صحيح WINAPI GetRandomRgn (HDC hdc,HRGN hrgn,INT i);
  WINGDIAPI DWORD WINAPI Get_Region_معلومات(HRGN hrgn,DWORD n_ڳڻپ,LPRGNDATA lp_Rgn_معلومات);
  WINGDIAPI صحيح WINAPI GetRgnBox(HRGN hrgn,LPRECT lprc);
  WINGDIAPI HGDIOBJ WINAPI GetStockObject(صحيح i);
  WINGDIAPI صحيح WINAPI Get_Stretch_Blt_گهڻائي(HDC hdc);
  WINGDIAPI UINT WINAPI GetSystemPaletteEntries(HDC hdc,UINT i_شروعات,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI UINT WINAPI GetSystemPaletteUse(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_متن_Character_Extra(HDC hdc);
  WINGDIAPI UINT WINAPI Get_متن_Align(HDC hdc);
  WINGDIAPI COLORREF WINAPI Get_متن_Color(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_نقطو_A(HDC hdc,LPCSTR lpString,صحيح c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_نقطو_W(HDC hdc,LPCWSTR lpString,صحيح c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Point32_A(HDC hdc,LPCSTR lpString,صحيح c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Point32_W(HDC hdc,LPCWSTR lpString,صحيح c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_نقطو_A(HDC hdc,LPCSTR lpszString,صحيح cchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_سائيز);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_نقطو_W(HDC hdc,LPCWSTR lpszString,صحيح cchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_سائيز);
  WINGDIAPI صحيح WINAPI Get_متن_Charset(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_متن_Charset_Info(HDC hdc,LPFONTSIGNATURE lpSig,DWORD dwFlags);
  WINGDIAPI WINBOOL WINAPI TranslateCharsetInfo(DWORD *lpSrc,LPCHARSETINFO lpCs,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetFontLanguageInfo(HDC hdc);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementA(HDC hdc,LPCSTR lpString,صحيح n_ڳڻپ,صحيح nMexExtent,LPGCP_RESULTSA lpResults,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementW(HDC hdc,LPCWSTR lpString,صحيح n_ڳڻپ,صحيح nMexExtent,LPGCP_RESULTSW lpResults,DWORD dwFlags);

  تعريفنوع بنية ٽيگ_WCRANGE {
    WCHAR wc_هيٺيون;
    USHORT cGlyphs;
  } WCRANGE,*PWCRANGE,*LPWCRANGE;

  تعريفنوع بنية ٽيگ_GLYPHSET {
    DWORD cbThis;
    DWORD flAccel;
    DWORD cGlyphsSupported;
    DWORD cRanges;
    WCRANGE ranges[1];
  } GLYPHSET,*PGLYPHSET,*LPGLYPHSET;

#وصف_ڪريو GS_8_ٻٽو_انگ_INDICES 0x00000001

#وصف_ڪريو GGI_MARK_NONEXISTING_GLYPHS 0X0001

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو GetGlyphIndices GetGlyphIndicesW
#وإلا
#وصف_ڪريو GetGlyphIndices GetGlyphIndicesA
#جيڪڏهن_پورو

  WINGDIAPI DWORD WINAPI GetFontUnicodeRanges(HDC hdc,LPGLYPHSET lpgs);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesA(HDC hdc,LPCSTR lpstr,صحيح c,LPWORD pgi,DWORD fl);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesW(HDC hdc,LPCWSTR lpstr,صحيح c,LPWORD pgi,DWORD fl);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_نقطو_I(HDC hdc,LPWORD pgi_اندريون,صحيح cgi,LPSIZE psize);
  WINGDIAPI WINBOOL WINAPI Get_متن_Extent_Ex_نقطو_I (HDC hdc,LPWORD lpwszString,صحيح cwchString,صحيح nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_سائيز);
  WINGDIAPI WINBOOL WINAPI Get_Char_ويڪر_I(HDC hdc,UINT gi_پهريون,UINT cgi,LPWORD pgi,LPINT piWidths);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsI(HDC hdc,UINT gi_پهريون,UINT cgi,LPWORD pgi,LPABC pabc);

#وصف_ڪريو STAMP_DESIGNVECTOR (0x8000000 + 'd' + ('v' << 8))
#وصف_ڪريو STAMP_AXESLIST (0x8000000 + 'a' + ('l' << 8))
#وصف_ڪريو MM_MAX_NUMAXES 16

  تعريفنوع بنية ٽيگ_DESIGNVECTOR {
    DWORD dvReserved;
    DWORD dv_انگ_Axes;
    LONG dv_قدرون[MM_MAX_NUMAXES];
  } DESIGNVECTOR,*PDESIGNVECTOR,*LPDESIGNVECTOR;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو جوڙيو_Font_Resource_Ex جوڙيو_Font_Resource_Ex_W
#وصف_ڪريو RemoveFontResourceEx RemoveFontResourceExW
#وإلا
#وصف_ڪريو جوڙيو_Font_Resource_Ex جوڙيو_Font_Resource_Ex_A
#وصف_ڪريو RemoveFontResourceEx RemoveFontResourceExA
#جيڪڏهن_پورو

  WINGDIAPI صحيح WINAPI جوڙيو_Font_Resource_Ex_A(LPCSTR name,DWORD fl,PVOID res);
  WINGDIAPI صحيح WINAPI جوڙيو_Font_Resource_Ex_W(LPCWSTR name,DWORD fl,PVOID res);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExA(LPCSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExW(LPCWSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI HANDLE WINAPI جوڙيو_Font_Mem_Resource_Ex(PVOID pFileView,DWORD cj_سائيز,PVOID pvResrved,DWORD *p_انگ_Fonts);
  WINGDIAPI WINBOOL WINAPI RemoveFontMemResourceEx(HANDLE h);

#وصف_ڪريو FR_ذاتي 0x10
#وصف_ڪريو FR_NOT_ENUM 0x20

#وصف_ڪريو MM_MAX_AXES_NAMELEN 16

  تعريفنوع بنية ٽيگ_AXISINFOA {
    LONG ax_Min_قدر;
    LONG ax_Max_قدر;
    BYTE axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOA,*PAXISINFOA,*LPAXISINFOA;

  تعريفنوع بنية ٽيگ_AXISINFOW {
    LONG ax_Min_قدر;
    LONG ax_Max_قدر;
    WCHAR axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOW,*PAXISINFOW,*LPAXISINFOW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع AXISINFOW AXISINFO;
  تعريفنوع PAXISINFOW PAXISINFO;
  تعريفنوع LPAXISINFOW LPAXISINFO;
#وإلا
  تعريفنوع AXISINFOA AXISINFO;
  تعريفنوع PAXISINFOA PAXISINFO;
  تعريفنوع LPAXISINFOA LPAXISINFO;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_AXESLISTA {
    DWORD axlReserved;
    DWORD axl_انگ_Axes;
    AXISINFOA axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTA,*PAXESLISTA,*LPAXESLISTA;

  تعريفنوع بنية ٽيگ_AXESLISTW {
    DWORD axlReserved;
    DWORD axl_انگ_Axes;
    AXISINFOW axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTW,*PAXESLISTW,*LPAXESLISTW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع AXESLISTW AXESLIST;
  تعريفنوع PAXESLISTW PAXESLIST;
  تعريفنوع LPAXESLISTW LPAXESLIST;
#وإلا
  تعريفنوع AXESLISTA AXESLIST;
  تعريفنوع PAXESLISTA PAXESLIST;
  تعريفنوع LPAXESLISTA LPAXESLIST;
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_ENUMLOGFONTEXDVA {
    ENUMLOGFONTEXA elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_ويڪٽر;
  } ENUMLOGFONTEXDVA,*PENUMLOGFONTEXDVA,*LPENUMLOGFONTEXDVA;

  تعريفنوع بنية ٽيگ_ENUMLOGFONTEXDVW {
    ENUMLOGFONTEXW elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_ويڪٽر;
  } ENUMLOGFONTEXDVW,*PENUMLOGFONTEXDVW,*LPENUMLOGFONTEXDVW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع ENUMLOGFONTEXDVW ENUMLOGFONTEXDV;
  تعريفنوع PENUMLOGFONTEXDVW PENUMLOGFONTEXDV;
  تعريفنوع LPENUMLOGFONTEXDVW LPENUMLOGFONTEXDV;
#وإلا
  تعريفنوع ENUMLOGFONTEXDVA ENUMLOGFONTEXDV;
  تعريفنوع PENUMLOGFONTEXDVA PENUMLOGFONTEXDV;
  تعريفنوع LPENUMLOGFONTEXDVA LPENUMLOGFONTEXDV;
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Create_Font_اڻسڌو_Ex Create_Font_اڻسڌو_Ex_W
#وإلا
#وصف_ڪريو Create_Font_اڻسڌو_Ex Create_Font_اڻسڌو_Ex_A
#جيڪڏهن_پورو

  WINGDIAPI HFONT WINAPI Create_Font_اڻسڌو_Ex_A(CONST ENUMLOGFONTEXDVA *);
  WINGDIAPI HFONT WINAPI Create_Font_اڻسڌو_Ex_W(CONST ENUMLOGFONTEXDVW *);

#جيڪڏهن_وصف_نه_ٿيل NOTEXTMETRIC
  تعريفنوع بنية ٽيگ_ENUMTEXTMETRICA {
    NEWTEXTMETRICEXA etm_New_متن_Metric_Ex;
    AXESLISTA etmAxesList;
  } ENUMTEXTMETRICA,*PENUMTEXTMETRICA,*LPENUMTEXTMETRICA;
  تعريفنوع بنية ٽيگ_ENUMTEXTMETRICW
  {
    NEWTEXTMETRICEXW etm_New_متن_Metric_Ex;
    AXESLISTW etmAxesList;
  } ENUMTEXTMETRICW,*PENUMTEXTMETRICW,*LPENUMTEXTMETRICW;
#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع ENUMTEXTMETRICW ENUMTEXTMETRIC;
  تعريفنوع PENUMTEXTMETRICW PENUMTEXTMETRIC;
  تعريفنوع LPENUMTEXTMETRICW LPENUMTEXTMETRIC;
#وإلا
  تعريفنوع ENUMTEXTMETRICA ENUMTEXTMETRIC;
  تعريفنوع PENUMTEXTMETRICA PENUMTEXTMETRIC;
  تعريفنوع LPENUMTEXTMETRICA LPENUMTEXTMETRIC;
#جيڪڏهن_پورو
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ResetDC ResetDCW
#وصف_ڪريو RemoveFontResource RemoveFontResourceW
#وإلا
#وصف_ڪريو ResetDC ResetDCA
#وصف_ڪريو RemoveFontResource RemoveFontResourceA
#جيڪڏهن_پورو

  WINGDIAPI WINBOOL WINAPI GetViewportExtEx(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI GetViewportOrgEx(HDC hdc,LPPOINT lppoint);
  WINGDIAPI WINBOOL WINAPI Get_دري_Ext_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI Get_دري_Org_Ex(HDC hdc,LPPOINT lppoint);
  WINGDIAPI صحيح WINAPI IntersectClipRect(HDC hdc,صحيح کاٻو,صحيح چوٽي,صحيح ساڄو,صحيح bottom);
  WINGDIAPI WINBOOL WINAPI InvertRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI سٽ_DDA(صحيح x_شروعات,صحيح y_شروعات,صحيح x_پڇاڙي,صحيح y_پڇاڙي,LINEDDAPROC lpProc,LPARAM معلومات);
  WINGDIAPI WINBOOL WINAPI سٽ_منزل(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI نقاب_Blt(HDC hdcDest,صحيح xDest,صحيح yDest,صحيح ويڪر,صحيح اوچائي,HDC hdcSrc,صحيح xSrc,صحيح ySrc,HBITMAP hbm_نقاب,صحيح x_نقاب,صحيح y_نقاب,DWORD rop);
  WINGDIAPI WINBOOL WINAPI PlgBlt(HDC hdcDest,CONST نقطو_3 *lp_نقطو,HDC hdcSrc,صحيح xSrc,صحيح ySrc,صحيح ويڪر,صحيح اوچائي,HBITMAP hbm_نقاب,صحيح x_نقاب,صحيح y_نقاب);
  WINGDIAPI صحيح WINAPI وٿي_Clip_Rgn(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI صحيح WINAPI وٿي_Rgn(HRGN hrgn,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI PatBlt(HDC hdc,صحيح x,صحيح y,صحيح w,صحيح h,DWORD rop);
  WINGDIAPI WINBOOL WINAPI Pie(HDC hdc,صحيح کاٻو,صحيح چوٽي,صحيح ساڄو,صحيح bottom,صحيح xr1,صحيح yr1,صحيح xr2,صحيح yr2);
  WINGDIAPI WINBOOL WINAPI PlayMetaFile(HDC hdc,HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI PaintRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI PolyPolygon(HDC hdc,CONST نقطو_3 *apt,CONST INT *asz,صحيح csz);
  WINGDIAPI WINBOOL WINAPI Pt_اندريون_Region(HRGN hrgn,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI PtVisible(HDC hdc,صحيح x,صحيح y);
  WINGDIAPI WINBOOL WINAPI Rect_اندريون_Region(HRGN hrgn,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI RectVisible(HDC hdc,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Rectangle(HDC hdc,صحيح کاٻو,صحيح چوٽي,صحيح ساڄو,صحيح bottom);
  WINGDIAPI WINBOOL WINAPI RestoreDC(HDC hdc,صحيح nSavedDC);
  WINGDIAPI HDC WINAPI ResetDCA(HDC hdc,CONST DEVMODEA *lpdm);
  WINGDIAPI HDC WINAPI ResetDCW(HDC hdc,CONST DEVMODEW *lpdm);
  WINGDIAPI UINT WINAPI RealizePalette(HDC hdc);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceA(LPCSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceW(LPCWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI ڦيرو_Rect(HDC hdc,صحيح کاٻو,صحيح چوٽي,صحيح ساڄو,صحيح bottom,صحيح ويڪر,صحيح اوچائي);
  WINGDIAPI WINBOOL WINAPI ResizePalette(HPALETTE hpal,UINT n);
  WINGDIAPI صحيح WINAPI SaveDC(HDC hdc);
  WINGDIAPI صحيح WINAPI SelectClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI صحيح WINAPI ExtSelectClipRgn(HDC hdc,HRGN hrgn,صحيح گهڻائي);
  WINGDIAPI صحيح WINAPI سيٽ_Meta_Rgn(HDC hdc);
  WINGDIAPI HGDIOBJ WINAPI SelectObject(HDC hdc,HGDIOBJ h);
  WINGDIAPI HPALETTE WINAPI SelectPalette(HDC hdc,HPALETTE hPal,WINBOOL bForceBkgd);
  WINGDIAPI COLORREF WINAPI سيٽ_Bk_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI سيٽ_DCBrush_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI سيٽ_DCPen_Color(HDC hdc,COLORREF color);
  WINGDIAPI صحيح WINAPI سيٽ_Bk_گهڻائي(HDC hdc,صحيح گهڻائي);
  WINGDIAPI LONG WINAPI سيٽ_Bitmap_بٽ(HBITMAP hbm,DWORD cb,CONST VOID *pv_بٽ);
  WINGDIAPI UINT WINAPI سيٽ_Bounds_Rect(HDC hdc,CONST RECT *lprect,UINT flags);
  WINGDIAPI صحيح WINAPI سيٽ_DIBits(HDC hdc,HBITMAP hbm,UINT شروعات,UINT c_سٽون,CONST VOID *lp_بٽ,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI صحيح WINAPI سيٽ_DIBits_منزل_Device(HDC hdc,صحيح xDest,صحيح yDest,DWORD w,DWORD h,صحيح xSrc,صحيح ySrc,UINT شروعات_جاچ,UINT c_سٽون,CONST VOID *lpv_بٽ,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI DWORD WINAPI سيٽ_Mapper_Flags(HDC hdc,DWORD flags);
  WINGDIAPI صحيح WINAPI سيٽ_Graphics_گهڻائي(HDC hdc,صحيح i_گهڻائي);
  WINGDIAPI صحيح WINAPI سيٽ_Map_گهڻائي(HDC hdc,صحيح i_گهڻائي);
  WINGDIAPI DWORD WINAPI سيٽ_Layout(HDC hdc,DWORD l);
  WINGDIAPI DWORD WINAPI GetLayout(HDC hdc);
  WINGDIAPI HMETAFILE WINAPI سيٽ_Meta_File_بٽ_Ex(UINT cb_بفر,CONST BYTE *lp_معلومات);
  WINGDIAPI UINT WINAPI سيٽ_Palette_Entries(HPALETTE hpal,UINT i_شروعات,UINT cEntries,CONST PALETTEENTRY *pPalEntries);
  WINGDIAPI COLORREF WINAPI سيٽ_Pixel(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI سيٽ_Pixel_V(HDC hdc,صحيح x,صحيح y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI سيٽ_Pixel_Format(HDC hdc,صحيح format,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI صحيح WINAPI سيٽ_Poly_Fill_گهڻائي(HDC hdc,صحيح گهڻائي);
  WINGDIAPI WINBOOL WINAPI StretchBlt(HDC hdcDest,صحيح xDest,صحيح yDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xSrc,صحيح ySrc,صحيح wSrc,صحيح hSrc,DWORD rop);
  WINGDIAPI WINBOOL WINAPI سيٽ_Rect_Rgn(HRGN hrgn,صحيح کاٻو,صحيح چوٽي,صحيح ساڄو,صحيح bottom);
  WINGDIAPI صحيح WINAPI StretchDIBits(HDC hdc,صحيح xDest,صحيح yDest,صحيح Dest_ويڪر,صحيح Dest_اوچائي,صحيح xSrc,صحيح ySrc,صحيح Src_ويڪر,صحيح Src_اوچائي,CONST VOID *lp_بٽ,CONST BITMAPINFO *lpbmi,UINT iUsage,DWORD rop);
  WINGDIAPI صحيح WINAPI سيٽ_ROP2(HDC hdc,صحيح rop2);
  WINGDIAPI صحيح WINAPI سيٽ_Stretch_Blt_گهڻائي(HDC hdc,صحيح گهڻائي);
  WINGDIAPI UINT WINAPI سيٽ_System_Palette_Use(HDC hdc,UINT use);
  WINGDIAPI صحيح WINAPI سيٽ_متن_Character_Extra(HDC hdc,صحيح extra);
  WINGDIAPI COLORREF WINAPI سيٽ_متن_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI سيٽ_متن_Align(HDC hdc,UINT align);
  WINGDIAPI WINBOOL WINAPI سيٽ_متن_Justification(HDC hdc,صحيح extra,صحيح ڳڻپ_2);
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
    ULONG مٿانهون_کاٻو;
    ULONG هيٺاهون_ساڄو;
  } GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;

  تعريفنوع بنية _BLENDFUNCTION {
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE ذريعو_Constant_Alpha;
    BYTE AlphaFormat;
  } BLENDFUNCTION,*PBLENDFUNCTION;

#وصف_ڪريو AC_SRC_OVER 0x00
#وصف_ڪريو AC_SRC_ALPHA 0x01

  WINGDIAPI WINBOOL WINAPI AlphaBlend(HDC hdcDest,صحيح xoriginDest,صحيح yoriginDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xoriginSrc,صحيح yoriginSrc,صحيح wSrc,صحيح hSrc,BLENDFUNCTION ftn);
  WINGDIAPI WINBOOL WINAPI TransparentBlt(HDC hdcDest,صحيح xoriginDest,صحيح yoriginDest,صحيح wDest,صحيح hDest,HDC hdcSrc,صحيح xoriginSrc,صحيح yoriginSrc,صحيح wSrc,صحيح hSrc,UINT crTransparent);

#وصف_ڪريو GRADIENT_FILL_RECT_H 0x00000000
#وصف_ڪريو GRADIENT_FILL_RECT_V 0x00000001
#وصف_ڪريو GRADIENT_FILL_TRIANGLE 0x00000002
#وصف_ڪريو GRADIENT_FILL_OP_FLAG 0x000000ff

  WINGDIAPI WINBOOL WINAPI GradientFill(HDC hdc,PTRIVERTEX p_راس,ULONG n_راس,PVOID pMesh,ULONG nMesh,ULONG ul_گهڻائي);

#جيڪڏهن_وصف_نه_ٿيل NOMETAFILE

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو CopyEnhMetaFile CopyEnhMetaFileW
#وصف_ڪريو CreateEnhMetaFile CreateEnhMetaFileW
#وصف_ڪريو GetEnhMetaFile GetEnhMetaFileW
#وصف_ڪريو GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#وإلا
#وصف_ڪريو CopyEnhMetaFile CopyEnhMetaFileA
#وصف_ڪريو CreateEnhMetaFile CreateEnhMetaFileA
#وصف_ڪريو GetEnhMetaFile GetEnhMetaFileA
#وصف_ڪريو GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#جيڪڏهن_پورو

  WINGDIAPI WINBOOL WINAPI Play_Meta_File_رڪارڊ(HDC hdc,LPHANDLETABLE lp_Handle_جدول,LPMETARECORD lpMR,UINT noObjs);

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
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_بٽ(HENHMETAFILE hEMF,UINT n_سائيز,LPBYTE lp_معلومات);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE hemf,UINT cch_بفر,LPSTR lpDescription);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE hemf,UINT cch_بفر,LPWSTR lpDescription);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_سرو(HENHMETAFILE hemf,UINT n_سائيز,LPENHMETAHEADER lp_Enh_Meta_سرو);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT n_انگ_Entries,LPPALETTEENTRY lpPaletteEntries);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePixelFormat(HENHMETAFILE hemf,UINT cb_بفر,PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI UINT WINAPI Get_Win_Meta_File_بٽ(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT i_Map_گهڻائي,HDC hdcRef);
  WINGDIAPI WINBOOL WINAPI PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Play_Enh_Meta_File_رڪارڊ(HDC hdc,LPHANDLETABLE pht,CONST ENHMETARECORD *pmr,UINT cht);
  WINGDIAPI HENHMETAFILE WINAPI سيٽ_Enh_Meta_File_بٽ(UINT n_سائيز,CONST BYTE *pb);
  WINGDIAPI HENHMETAFILE WINAPI سيٽ_Win_Meta_File_بٽ(UINT n_سائيز,CONST BYTE *lp_Meta16_معلومات,HDC hdcRef,CONST METAFILEPICT *lpMFP);
  WINGDIAPI WINBOOL WINAPI GdiComment(HDC hdc,UINT n_سائيز,CONST BYTE *lp_معلومات);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_نه_ٿيل NOTEXTMETRIC
#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_متن_Metrics Get_متن_Metrics_W
#وإلا
#وصف_ڪريو Get_متن_Metrics Get_متن_Metrics_A
#جيڪڏهن_پورو

  WINGDIAPI WINBOOL WINAPI Get_متن_Metrics_A(HDC hdc,LPTEXTMETRICA lptm);
  WINGDIAPI WINBOOL WINAPI Get_متن_Metrics_W(HDC hdc,LPTEXTMETRICW lptm);
#جيڪڏهن_پورو

  تعريفنوع بنية ٽيگ_DIBSECTION {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD ds_وٿي;
  } DIBSECTION,*LPDIBSECTION,*PDIBSECTION;

  WINGDIAPI WINBOOL WINAPI AngleArc(HDC hdc,صحيح x,صحيح y,DWORD r,FLOAT شروعات_Angle,FLOAT SweepAngle);
  WINGDIAPI WINBOOL WINAPI PolyPolyline(HDC hdc,CONST نقطو_3 *apt,CONST DWORD *asz,DWORD csz);
  WINGDIAPI WINBOOL WINAPI GetWorldTransform(HDC hdc,LPXFORM lpxf);
  WINGDIAPI WINBOOL WINAPI سيٽ_World_Transform(HDC hdc,CONST XFORM *lpxf);
  WINGDIAPI WINBOOL WINAPI ModifyWorldTransform(HDC hdc,CONST XFORM *lpxf,DWORD گهڻائي);
  WINGDIAPI WINBOOL WINAPI CombineTransform(LPXFORM lpxf_ٻاهريون,CONST XFORM *lpxf1,CONST XFORM *lpxf2);
  WINGDIAPI HBITMAP WINAPI CreateDIBSection(HDC hdc,CONST BITMAPINFO *lpbmi,UINT usage,VOID **ppv_بٽ,HANDLE hSection,DWORD وٿي);
  WINGDIAPI UINT WINAPI Get_DIBColor_جدول(HDC hdc,UINT i_شروعات,UINT cEntries,RGBQUAD *prgbq);
  WINGDIAPI UINT WINAPI سيٽ_DIBColor_جدول(HDC hdc,UINT i_شروعات,UINT cEntries,CONST RGBQUAD *prgbq);

#وصف_ڪريو CA_NEGATIVE 0x0001
#وصف_ڪريو CA_LOG_FILTER 0x0002

#وصف_ڪريو ILLUMINANT_DEVICE_DEFAULT 0
#وصف_ڪريو ILLUMINANT_A 1
#وصف_ڪريو ILLUMINANT_B 2
#وصف_ڪريو ILLUMINANT_C 3
#وصف_ڪريو ILLUMINANT_D50 4
#وصف_ڪريو ILLUMINANT_D55 5
#وصف_ڪريو ILLUMINANT_D65 6
#وصف_ڪريو ILLUMINANT_D75 7
#وصف_ڪريو ILLUMINANT_F2 8
#وصف_ڪريو ILLUMINANT_MAX_اشاريو ILLUMINANT_F2

#وصف_ڪريو ILLUMINANT_TUNGSTEN ILLUMINANT_A
#وصف_ڪريو ILLUMINANT_DAYLIGHT ILLUMINANT_C
#وصف_ڪريو ILLUMINANT_FLUORESCENT ILLUMINANT_F2
#وصف_ڪريو ILLUMINANT_NTSC ILLUMINANT_C

#وصف_ڪريو RGB_GAMMA_MIN (لفظ_3)02500
#وصف_ڪريو RGB_GAMMA_MAX (لفظ_3)65000

#وصف_ڪريو REFERENCE_WHITE_MIN (لفظ_3)6000
#وصف_ڪريو REFERENCE_WHITE_MAX (لفظ_3)10000
#وصف_ڪريو REFERENCE_BLACK_MIN (لفظ_3)0
#وصف_ڪريو REFERENCE_BLACK_MAX (لفظ_3)4000

#وصف_ڪريو COLOR_ADJ_MIN (SHORT)-100
#وصف_ڪريو COLOR_ADJ_MAX (SHORT)100

  تعريفنوع بنية ٽيگ_COLORADJUSTMENT {
    لفظ_3 ca_سائيز;
    لفظ_3 caFlags;
    لفظ_3 ca_Illuminant_اشاريو;
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

  WINGDIAPI WINBOOL WINAPI سيٽ_Color_Adjustment(HDC hdc,CONST COLORADJUSTMENT *lpca);
  WINGDIAPI WINBOOL WINAPI GetColorAdjustment(HDC hdc,LPCOLORADJUSTMENT lpca);
  WINGDIAPI HPALETTE WINAPI CreateHalftonePalette(HDC hdc);

  تعريفنوع WINBOOL (CALLBACK *ABORTPROC)(HDC,صحيح);

  تعريفنوع بنية _DOCINFOA {
    صحيح cb_سائيز;
    LPCSTR lpszDocName;
    LPCSTR lpszOutput;
    LPCSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOA,*LPDOCINFOA;

  تعريفنوع بنية _DOCINFOW {
    صحيح cb_سائيز;
    LPCWSTR lpszDocName;
    LPCWSTR lpszOutput;
    LPCWSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOW,*LPDOCINFOW;

#جيڪڏهن_وصف_ٿيل UNICODE
  تعريفنوع DOCINFOW DOCINFO;
  تعريفنوع LPDOCINFOW LPDOCINFO;
#وإلا
  تعريفنوع DOCINFOA DOCINFO;
  تعريفنوع LPDOCINFOA LPDOCINFO;
#جيڪڏهن_پورو

#وصف_ڪريو DI_APPBANDING 0x00000001
#وصف_ڪريو DI_ROPS_READ_DESTINATION 0x00000002

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو شروعات_Doc شروعات_Doc_W
#وصف_ڪريو GetObject GetObjectW
#وصف_ڪريو متن_ٻاهريون متن_ٻاهريون_W
#وصف_ڪريو Ext_متن_ٻاهريون Ext_متن_ٻاهريون_W
#وصف_ڪريو Poly_متن_ٻاهريون Poly_متن_ٻاهريون_W
#وصف_ڪريو Get_متن_Face Get_متن_Face_W
#وإلا
#وصف_ڪريو شروعات_Doc شروعات_Doc_A
#وصف_ڪريو GetObject GetObjectA
#وصف_ڪريو متن_ٻاهريون متن_ٻاهريون_A
#وصف_ڪريو Ext_متن_ٻاهريون Ext_متن_ٻاهريون_A
#وصف_ڪريو Poly_متن_ٻاهريون Poly_متن_ٻاهريون_A
#وصف_ڪريو Get_متن_Face Get_متن_Face_A
#جيڪڏهن_پورو

  WINGDIAPI صحيح WINAPI شروعات_Doc_A(HDC hdc,CONST DOCINFOA *lpdi);
  WINGDIAPI صحيح WINAPI شروعات_Doc_W(HDC hdc,CONST DOCINFOW *lpdi);
  WINGDIAPI صحيح WINAPI پڇاڙي_Doc(HDC hdc);
  WINGDIAPI صحيح WINAPI شروعات_صفحو(HDC hdc);
  WINGDIAPI صحيح WINAPI پڇاڙي_صفحو(HDC hdc);
  WINGDIAPI صحيح WINAPI AbortDoc(HDC hdc);
  WINGDIAPI صحيح WINAPI سيٽ_Abort_Proc(HDC hdc,ABORTPROC proc);
  WINGDIAPI WINBOOL WINAPI Abort_رستو(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Arc_منزل(HDC hdc,صحيح کاٻو,صحيح چوٽي,صحيح ساڄو,صحيح bottom,صحيح xr1,صحيح yr1,صحيح xr2,صحيح yr2);
  WINGDIAPI WINBOOL WINAPI Begin_رستو(HDC hdc);
  WINGDIAPI WINBOOL WINAPI CloseFigure(HDC hdc);
  WINGDIAPI WINBOOL WINAPI پڇاڙي_رستو_2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Fill_رستو(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Flatten_رستو(HDC hdc);
  WINGDIAPI صحيح WINAPI Get_رستو(HDC hdc,LPPOINT apt,LPBYTE aj,صحيح cpt);
  WINGDIAPI HRGN WINAPI رستو_منزل_Region(HDC hdc);
  WINGDIAPI WINBOOL WINAPI PolyDraw(HDC hdc,CONST نقطو_3 *apt,CONST BYTE *aj,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI Select_Clip_رستو(HDC hdc,صحيح گهڻائي);
  WINGDIAPI صحيح WINAPI سيٽ_Arc_Direction(HDC hdc,صحيح dir);
  WINGDIAPI WINBOOL WINAPI سيٽ_Miter_حد_بندي(HDC hdc,FLOAT حد_بندي,PFLOAT old);
  WINGDIAPI WINBOOL WINAPI Stroke_And_Fill_رستو(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Stroke_رستو(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Widen_رستو(HDC hdc);
  WINGDIAPI HPEN WINAPI ExtCreatePen(DWORD iPenStyle,DWORD c_ويڪر,CONST LOGBRUSH *plbrush,DWORD cStyle,CONST DWORD *pstyle);
  WINGDIAPI WINBOOL WINAPI Get_Miter_حد_بندي(HDC hdc,PFLOAT plimit);
  WINGDIAPI صحيح WINAPI GetArcDirection(HDC hdc);
  WINGDIAPI صحيح WINAPI GetObjectA(HANDLE h,صحيح c,LPVOID pv);
  WINGDIAPI صحيح WINAPI GetObjectW(HANDLE h,صحيح c,LPVOID pv);
  WINGDIAPI WINBOOL WINAPI Move_منزل_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI متن_ٻاهريون_A(HDC hdc,صحيح x,صحيح y,LPCSTR lpString,صحيح c);
  WINGDIAPI WINBOOL WINAPI متن_ٻاهريون_W(HDC hdc,صحيح x,صحيح y,LPCWSTR lpString,صحيح c);
  WINGDIAPI WINBOOL WINAPI Ext_متن_ٻاهريون_A(HDC hdc,صحيح x,صحيح y,UINT options,CONST RECT *lprect,LPCSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Ext_متن_ٻاهريون_W(HDC hdc,صحيح x,صحيح y,UINT options,CONST RECT *lprect,LPCWSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Poly_متن_ٻاهريون_A(HDC hdc,CONST POLYTEXTA *ppt,صحيح nstrings);
  WINGDIAPI WINBOOL WINAPI Poly_متن_ٻاهريون_W(HDC hdc,CONST POLYTEXTW *ppt,صحيح nstrings);
  WINGDIAPI HRGN WINAPI CreatePolygonRgn(CONST نقطو_3 *pptl,صحيح c_نقطو,صحيح i_گهڻائي);
  WINGDIAPI WINBOOL WINAPI DPtoLP(HDC hdc,LPPOINT lppt,صحيح c);
  WINGDIAPI WINBOOL WINAPI LPtoDP(HDC hdc,LPPOINT lppt,صحيح c);
  WINGDIAPI WINBOOL WINAPI Polygon(HDC hdc,CONST نقطو_3 *apt,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI Polyline(HDC hdc,CONST نقطو_3 *apt,صحيح cpt);
  WINGDIAPI WINBOOL WINAPI PolyBezier(HDC hdc,CONST نقطو_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Poly_Bezier_منزل(HDC hdc,CONST نقطو_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Polyline_منزل(HDC hdc,CONST نقطو_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI سيٽ_Viewport_Ext_Ex(HDC hdc,صحيح x,صحيح y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سيٽ_Viewport_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI سيٽ_دري_Ext_Ex(HDC hdc,صحيح x,صحيح y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سيٽ_دري_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI وٿي_Viewport_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI وٿي_دري_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ScaleViewportExtEx(HDC hdc,صحيح xn,صحيح dx,صحيح yn,صحيح yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Scale_دري_Ext_Ex(HDC hdc,صحيح xn,صحيح xd,صحيح yn,صحيح yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سيٽ_Bitmap_Dimension_Ex(HBITMAP hbm,صحيح w,صحيح h,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI سيٽ_Brush_Org_Ex(HDC hdc,صحيح x,صحيح y,LPPOINT lppt);
  WINGDIAPI صحيح WINAPI Get_متن_Face_A(HDC hdc,صحيح c,LPSTR lpName);
  WINGDIAPI صحيح WINAPI Get_متن_Face_W(HDC hdc,صحيح c,LPWSTR lpName);

#وصف_ڪريو FONTMAPPER_MAX 10

  تعريفنوع بنية ٽيگ_KERNINGPAIR {
    لفظ_3 w_پهريون;
    لفظ_3 w_ٻيو;
    صحيح iKernAmount;
  } KERNINGPAIR,*LPKERNINGPAIR;

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو Get_Kerning_جوڙا Get_Kerning_جوڙا_W
#وإلا
#وصف_ڪريو Get_Kerning_جوڙا Get_Kerning_جوڙا_A
#جيڪڏهن_پورو

  WINGDIAPI DWORD WINAPI Get_Kerning_جوڙا_A(HDC hdc,DWORD n_جوڙا,LPKERNINGPAIR lpKernPair);
  WINGDIAPI DWORD WINAPI Get_Kerning_جوڙا_W(HDC hdc,DWORD n_جوڙا,LPKERNINGPAIR lpKernPair);
  WINGDIAPI WINBOOL WINAPI GetDCOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI FixBrushOrgEx(HDC hdc,صحيح x,صحيح y,LPPOINT ptl);
  WINGDIAPI WINBOOL WINAPI UnrealizeObject(HGDIOBJ h);
  WINGDIAPI WINBOOL WINAPI GdiFlush();
  WINGDIAPI DWORD WINAPI Gdi_سيٽ_Batch_حد_بندي(DWORD dw);
  WINGDIAPI DWORD WINAPI Gdi_Get_Batch_حد_بندي();

#وصف_ڪريو ICM_OFF 1
#وصف_ڪريو ICM_ON 2
#وصف_ڪريو ICM_QUERY 3
#وصف_ڪريو ICM_پورو_OUTSIDEDC 4

  تعريفنوع صحيح (CALLBACK *ICMENUMPROCA)(LPSTR,LPARAM);
  تعريفنوع صحيح (CALLBACK *ICMENUMPROCW)(LPWSTR,LPARAM);

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو ICMENUMPROC ICMENUMPROCW
#وصف_ڪريو EnumICMProfiles EnumICMProfilesW
#وصف_ڪريو Update_ICMReg_ڪنجي Update_ICMReg_ڪنجي_W
#وصف_ڪريو GetLogColorSpace GetLogColorSpaceW
#وصف_ڪريو CreateColorSpace CreateColorSpaceW
#وصف_ڪريو GetICMProfile GetICMProfileW
#وصف_ڪريو سيٽ_ICMProfile سيٽ_ICMProfile_W
#وإلا
#وصف_ڪريو ICMENUMPROC ICMENUMPROCA
#وصف_ڪريو EnumICMProfiles EnumICMProfilesA
#وصف_ڪريو Update_ICMReg_ڪنجي Update_ICMReg_ڪنجي_A
#وصف_ڪريو GetLogColorSpace GetLogColorSpaceA
#وصف_ڪريو CreateColorSpace CreateColorSpaceA
#وصف_ڪريو GetICMProfile GetICMProfileA
#وصف_ڪريو سيٽ_ICMProfile سيٽ_ICMProfile_A
#جيڪڏهن_پورو

  WINGDIAPI صحيح WINAPI سيٽ_ICMMode(HDC hdc,صحيح گهڻائي);
  WINGDIAPI WINBOOL WINAPI Check_Colors_اندريون_Gamut(HDC hdc,LPVOID lpRGBTriple,LPVOID dlp_بفر,DWORD n_ڳڻپ);
  WINGDIAPI HCOLORSPACE WINAPI GetColorSpace(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceA(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEA lp_بفر,DWORD n_سائيز);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceW(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEW lp_بفر,DWORD n_سائيز);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA lplcs);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW lplcs);
  WINGDIAPI HCOLORSPACE WINAPI سيٽ_Color_Space(HDC hdc,HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI DeleteColorSpace(HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI GetICMProfileA(HDC hdc,LPDWORD p_Buf_سائيز,LPSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI GetICMProfileW(HDC hdc,LPDWORD p_Buf_سائيز,LPWSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI سيٽ_ICMProfile_A(HDC hdc,LPSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI سيٽ_ICMProfile_W(HDC hdc,LPWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI GetDeviceGammaRamp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI سيٽ_Device_Gamma_Ramp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI Color_ميلاپ_منزل_هدف(HDC hdc,HDC hdc_هدف,DWORD action);
  WINGDIAPI صحيح WINAPI EnumICMProfilesA(HDC hdc,ICMENUMPROCA proc,LPARAM param);
  WINGDIAPI صحيح WINAPI EnumICMProfilesW(HDC hdc,ICMENUMPROCW proc,LPARAM param);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_ڪنجي_A(DWORD reserved,LPSTR lpszCMID,LPSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_ڪنجي_W(DWORD reserved,LPWSTR lpszCMID,LPWSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI ColorCorrectPalette(HDC hdc,HPALETTE hPal,DWORD de_پهريون,DWORD انگ);

#جيڪڏهن_وصف_نه_ٿيل NOMETAFILE

#وصف_ڪريو ENHMETA_SIGNATURE 0x464D4520
#وصف_ڪريو ENHMETA_STOCK_OBJECT 0x80000000

#وصف_ڪريو EMR_سرو 1
#وصف_ڪريو EMR_POLYBEZIER 2
#وصف_ڪريو EMR_POLYGON 3
#وصف_ڪريو EMR_POLYLINE 4
#وصف_ڪريو EMR_POLYBEZIERTO 5
#وصف_ڪريو EMR_POLYLINETO 6
#وصف_ڪريو EMR_POLYPOLYLINE 7
#وصف_ڪريو EMR_POLYPOLYGON 8
#وصف_ڪريو EMR_SETWINDOWEXTEX 9
#وصف_ڪريو EMR_SETWINDOWORGEX 10
#وصف_ڪريو EMR_SETVIEWPORTEXTEX 11
#وصف_ڪريو EMR_SETVIEWPORTORGEX 12
#وصف_ڪريو EMR_SETBRUSHORGEX 13
#وصف_ڪريو EMR_EOF 14
#وصف_ڪريو EMR_SETPIXELV 15
#وصف_ڪريو EMR_SETMAPPERFLAGS 16
#وصف_ڪريو EMR_SETMAPMODE 17
#وصف_ڪريو EMR_SETBKMODE 18
#وصف_ڪريو EMR_SETPOLYFILLMODE 19
#وصف_ڪريو EMR_SETROP2 20
#وصف_ڪريو EMR_SETSTRETCHBLTMODE 21
#وصف_ڪريو EMR_SETTEXTALIGN 22
#وصف_ڪريو EMR_SETCOLORADJUSTMENT 23
#وصف_ڪريو EMR_SETTEXTCOLOR 24
#وصف_ڪريو EMR_SETBKCOLOR 25
#وصف_ڪريو EMR_OFFSETCLIPRGN 26
#وصف_ڪريو EMR_MOVETOEX 27
#وصف_ڪريو EMR_SETMETARGN 28
#وصف_ڪريو EMR_EXCLUDECLIPRECT 29
#وصف_ڪريو EMR_INTERSECTCLIPRECT 30
#وصف_ڪريو EMR_SCALEVIEWPORTEXTEX 31
#وصف_ڪريو EMR_SCALEWINDOWEXTEX 32
#وصف_ڪريو EMR_SAVEDC 33
#وصف_ڪريو EMR_RESTOREDC 34
#وصف_ڪريو EMR_SETWORLDTRANSFORM 35
#وصف_ڪريو EMR_MODIFYWORLDTRANSFORM 36
#وصف_ڪريو EMR_SELECTOBJECT 37
#وصف_ڪريو EMR_CREATEPEN 38
#وصف_ڪريو EMR_CREATEBRUSHINDIRECT 39
#وصف_ڪريو EMR_DELETEOBJECT 40
#وصف_ڪريو EMR_ANGLEARC 41
#وصف_ڪريو EMR_ELLIPSE 42
#وصف_ڪريو EMR_RECTANGLE 43
#وصف_ڪريو EMR_ROUNDRECT 44
#وصف_ڪريو EMR_ARC 45
#وصف_ڪريو EMR_CHORD 46
#وصف_ڪريو EMR_PIE 47
#وصف_ڪريو EMR_SELECTPALETTE 48
#وصف_ڪريو EMR_CREATEPALETTE 49
#وصف_ڪريو EMR_SETPALETTEENTRIES 50
#وصف_ڪريو EMR_RESIZEPALETTE 51
#وصف_ڪريو EMR_REALIZEPALETTE 52
#وصف_ڪريو EMR_EXTFLOODFILL 53
#وصف_ڪريو EMR_LINETO 54
#وصف_ڪريو EMR_ARCTO 55
#وصف_ڪريو EMR_POLYDRAW 56
#وصف_ڪريو EMR_SETARCDIRECTION 57
#وصف_ڪريو EMR_SETMITERLIMIT 58
#وصف_ڪريو EMR_BEGINPATH 59
#وصف_ڪريو EMR_ENDPATH 60
#وصف_ڪريو EMR_CLOSEFIGURE 61
#وصف_ڪريو EMR_FILLPATH 62
#وصف_ڪريو EMR_STROKEANDFILLPATH 63
#وصف_ڪريو EMR_STROKEPATH 64
#وصف_ڪريو EMR_FLATTENPATH 65
#وصف_ڪريو EMR_WIDENPATH 66
#وصف_ڪريو EMR_SELECTCLIPPATH 67
#وصف_ڪريو EMR_ABORTPATH 68

#وصف_ڪريو EMR_GDICOMMENT 70
#وصف_ڪريو EMR_FILLRGN 71
#وصف_ڪريو EMR_FRAMERGN 72
#وصف_ڪريو EMR_INVERTRGN 73
#وصف_ڪريو EMR_PAINTRGN 74
#وصف_ڪريو EMR_EXTSELECTCLIPRGN 75
#وصف_ڪريو EMR_BITBLT 76
#وصف_ڪريو EMR_STRETCHBLT 77
#وصف_ڪريو EMR_MASKBLT 78
#وصف_ڪريو EMR_PLGBLT 79
#وصف_ڪريو EMR_SETDIBITSTODEVICE 80
#وصف_ڪريو EMR_STRETCHDIBITS 81
#وصف_ڪريو EMR_EXTCREATEFONTINDIRECTW 82
#وصف_ڪريو EMR_EXTTEXTOUTA 83
#وصف_ڪريو EMR_EXTTEXTOUTW 84
#وصف_ڪريو EMR_POLYBEZIER16 85
#وصف_ڪريو EMR_POLYGON16 86
#وصف_ڪريو EMR_POLYLINE16 87
#وصف_ڪريو EMR_POLYBEZIERTO16 88
#وصف_ڪريو EMR_POLYLINETO16 89
#وصف_ڪريو EMR_POLYPOLYLINE16 90
#وصف_ڪريو EMR_POLYPOLYGON16 91
#وصف_ڪريو EMR_POLYDRAW16 92
#وصف_ڪريو EMR_CREATEMONOBRUSH 93
#وصف_ڪريو EMR_CREATEDIBPATTERNBRUSHPT 94
#وصف_ڪريو EMR_EXTCREATEPEN 95
#وصف_ڪريو EMR_POLYTEXTOUTA 96
#وصف_ڪريو EMR_POLYTEXTOUTW 97

#وصف_ڪريو EMR_SETICMMODE 98
#وصف_ڪريو EMR_CREATECOLORSPACE 99
#وصف_ڪريو EMR_SETCOLORSPACE 100
#وصف_ڪريو EMR_DELETECOLORSPACE 101
#وصف_ڪريو EMR_GLSRECORD 102
#وصف_ڪريو EMR_GLSBOUNDEDRECORD 103
#وصف_ڪريو EMR_PIXELFORMAT 104
#وصف_ڪريو EMR_RESERVED_105 105
#وصف_ڪريو EMR_RESERVED_106 106
#وصف_ڪريو EMR_RESERVED_107 107
#وصف_ڪريو EMR_RESERVED_108 108
#وصف_ڪريو EMR_RESERVED_109 109
#وصف_ڪريو EMR_RESERVED_110 110
#وصف_ڪريو EMR_COLORCORRECTPALETTE 111
#وصف_ڪريو EMR_SETICMPROFILEA 112
#وصف_ڪريو EMR_SETICMPROFILEW 113
#وصف_ڪريو EMR_ALPHABLEND 114
#وصف_ڪريو EMR_SETLAYOUT 115
#وصف_ڪريو EMR_TRANSPARENTBLT 116
#وصف_ڪريو EMR_RESERVED_117 117
#وصف_ڪريو EMR_GRADIENTFILL 118
#وصف_ڪريو EMR_RESERVED_119 119
#وصف_ڪريو EMR_RESERVED_120 120
#وصف_ڪريو EMR_COLORMATCHTOTARGETW 121
#وصف_ڪريو EMR_CREATECOLORSPACEW 122

#وصف_ڪريو EMR_MIN 1

#وصف_ڪريو EMR_MAX 122

  تعريفنوع بنية ٽيگ_EMR {
    DWORD iType;
    DWORD n_سائيز;
  } EMR,*PEMR;

  تعريفنوع بنية ٽيگ_EMRTEXT {
    POINTL ptlReference;
    DWORD nChars;
    DWORD offString;
    DWORD fOptions;
    RECTL rcl;
    DWORD offDx;
  } EMRTEXT,*PEMRTEXT;

  تعريفنوع بنية ٽيگ_ABORTPATH {
    EMR emr;
  } EMRABORTPATH,*PEMRABORTPATH,EMRBEGINPATH,*PEMRBEGINPATH,EMRENDPATH,*PEMRENDPATH,EMRCLOSEFIGURE,*PEMRCLOSEFIGURE,EMRFLATTENPATH,*PEMRFLATTENPATH,EMRWIDENPATH,*PEMRWIDENPATH,EMRSETMETARGN,*PEMRSETMETARGN,EMRSAVEDC,*PEMRSAVEDC,EMRREALIZEPALETTE,*PEMRREALIZEPALETTE;

  تعريفنوع بنية ٽيگ_EMRSELECTCLIPPATH {
    EMR emr;
    DWORD i_گهڻائي;
  } EMRSELECTCLIPPATH,*PEMRSELECTCLIPPATH,EMRSETBKMODE,*PEMRSETBKMODE,EMRSETMAPMODE,*PEMRSETMAPMODE,EMRSETLAYOUT,*PEMRSETLAYOUT,
    EMRSETPOLYFILLMODE,*PEMRSETPOLYFILLMODE,EMRSETROP2,*PEMRSETROP2,EMRSETSTRETCHBLTMODE,*PEMRSETSTRETCHBLTMODE,EMRSETICMMODE,
    *PEMRSETICMMODE,EMRSETTEXTALIGN,*PEMRSETTEXTALIGN;

  تعريفنوع بنية ٽيگ_EMRSETMITERLIMIT {
    EMR emr;
    FLOAT e_Miter_حد_بندي;
  } EMRSETMITERLIMIT,*PEMRSETMITERLIMIT;

  تعريفنوع بنية ٽيگ_EMRRESTOREDC {
    EMR emr;
    LONG iRelative;
  } EMRRESTOREDC,*PEMRRESTOREDC;

  تعريفنوع بنية ٽيگ_EMRSETARCDIRECTION {
    EMR emr;
    DWORD iArcDirection;

  } EMRSETARCDIRECTION,*PEMRSETARCDIRECTION;

  تعريفنوع بنية ٽيگ_EMRSETMAPPERFLAGS {
    EMR emr;
    DWORD dwFlags;
  } EMRSETMAPPERFLAGS,*PEMRSETMAPPERFLAGS;

  تعريفنوع بنية ٽيگ_EMRSETTEXTCOLOR {
    EMR emr;
    COLORREF crColor;
  } EMRSETBKCOLOR,*PEMRSETBKCOLOR,EMRSETTEXTCOLOR,*PEMRSETTEXTCOLOR;

  تعريفنوع بنية ٽيگ_EMRSELECTOBJECT {
    EMR emr;
    DWORD ihObject;
  } EMRSELECTOBJECT,*PEMRSELECTOBJECT,EMRDELETEOBJECT,*PEMRDELETEOBJECT;

  تعريفنوع بنية ٽيگ_EMRSELECTPALETTE {
    EMR emr;
    DWORD ihPal;
  } EMRSELECTPALETTE,*PEMRSELECTPALETTE;

  تعريفنوع بنية ٽيگ_EMRRESIZEPALETTE {
    EMR emr;
    DWORD ihPal;
    DWORD cEntries;
  } EMRRESIZEPALETTE,*PEMRRESIZEPALETTE;

  تعريفنوع بنية ٽيگ_EMRSETPALETTEENTRIES {
    EMR emr;
    DWORD ihPal;
    DWORD i_شروعات;
    DWORD cEntries;
    PALETTEENTRY aPalEntries[1];
  } EMRSETPALETTEENTRIES,*PEMRSETPALETTEENTRIES;

  تعريفنوع بنية ٽيگ_EMRSETCOLORADJUSTMENT {
    EMR emr;
    COLORADJUSTMENT ColorAdjustment;
  } EMRSETCOLORADJUSTMENT,*PEMRSETCOLORADJUSTMENT;

  تعريفنوع بنية ٽيگ_EMRGDICOMMENT {
    EMR emr;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRGDICOMMENT,*PEMRGDICOMMENT;

  تعريفنوع بنية ٽيگ_EMREOF {
    EMR emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD n_سائيز_آخري;
  } EMREOF,*PEMREOF;

  تعريفنوع بنية ٽيگ_EMRLINETO {
    EMR emr;
    POINTL ptl;
  } EMRLINETO,*PEMRLINETO,EMRMOVETOEX,*PEMRMOVETOEX;

  تعريفنوع بنية ٽيگ_EMROFFSETCLIPRGN {
    EMR emr;
    POINTL ptl_وٿي;
  } EMROFFSETCLIPRGN,*PEMROFFSETCLIPRGN;

  تعريفنوع بنية ٽيگ_EMRFILLPATH {
    EMR emr;
    RECTL rclBounds;
  } EMRFILLPATH,*PEMRFILLPATH,EMRSTROKEANDFILLPATH,*PEMRSTROKEANDFILLPATH,EMRSTROKEPATH,*PEMRSTROKEPATH;

  تعريفنوع بنية ٽيگ_EMREXCLUDECLIPRECT {
    EMR emr;
    RECTL rclClip;
  } EMREXCLUDECLIPRECT,*PEMREXCLUDECLIPRECT,EMRINTERSECTCLIPRECT,*PEMRINTERSECTCLIPRECT;

  تعريفنوع بنية ٽيگ_EMRSETVIEWPORTORGEX {
    EMR emr;
    POINTL ptlOrigin;
  } EMRSETVIEWPORTORGEX,*PEMRSETVIEWPORTORGEX,EMRSETWINDOWORGEX,*PEMRSETWINDOWORGEX,EMRSETBRUSHORGEX,*PEMRSETBRUSHORGEX;

  تعريفنوع بنية ٽيگ_EMRSETVIEWPORTEXTEX {
    EMR emr;
    SIZEL szlExtent;
  } EMRSETVIEWPORTEXTEX,*PEMRSETVIEWPORTEXTEX,EMRSETWINDOWEXTEX,*PEMRSETWINDOWEXTEX;

  تعريفنوع بنية ٽيگ_EMRSCALEVIEWPORTEXTEX {
    EMR emr;
    LONG x_انگ;
    LONG xDenom;
    LONG y_انگ;
    LONG yDenom;
  } EMRSCALEVIEWPORTEXTEX,*PEMRSCALEVIEWPORTEXTEX,EMRSCALEWINDOWEXTEX,*PEMRSCALEWINDOWEXTEX;

  تعريفنوع بنية ٽيگ_EMRSETWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
  } EMRSETWORLDTRANSFORM,*PEMRSETWORLDTRANSFORM;

  تعريفنوع بنية ٽيگ_EMRMODIFYWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
    DWORD i_گهڻائي;
  } EMRMODIFYWORLDTRANSFORM,*PEMRMODIFYWORLDTRANSFORM;

  تعريفنوع بنية ٽيگ_EMRSETPIXELV {
    EMR emr;
    POINTL ptlPixel;
    COLORREF crColor;
  } EMRSETPIXELV,*PEMRSETPIXELV;

  تعريفنوع بنية ٽيگ_EMREXTFLOODFILL {
    EMR emr;
    POINTL ptl_شروعات;
    COLORREF crColor;
    DWORD i_گهڻائي;
  } EMREXTFLOODFILL,*PEMREXTFLOODFILL;

  تعريفنوع بنية ٽيگ_EMRELLIPSE {
    EMR emr;
    RECTL rclBox;
  } EMRELLIPSE,*PEMRELLIPSE,EMRRECTANGLE,*PEMRRECTANGLE;

  تعريفنوع بنية ٽيگ_EMRROUNDRECT {
    EMR emr;
    RECTL rclBox;
    SIZEL szl_ڪنڊ;
  } EMRROUNDRECT,*PEMRROUNDRECT;

  تعريفنوع بنية ٽيگ_EMRARC {
    EMR emr;
    RECTL rclBox;
    POINTL ptl_شروعات;
    POINTL ptl_پڇاڙي;
  } EMRARC,*PEMRARC,EMRARCTO,*PEMRARCTO,EMRCHORD,*PEMRCHORD,EMRPIE,*PEMRPIE;

  تعريفنوع بنية ٽيگ_EMRANGLEARC {
    EMR emr;
    POINTL ptlCenter;
    DWORD nRadius;
    FLOAT e_شروعات_Angle;
    FLOAT eSweepAngle;
  } EMRANGLEARC,*PEMRANGLEARC;

  تعريفنوع بنية ٽيگ_EMRPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
  } EMRPOLYLINE,*PEMRPOLYLINE,EMRPOLYBEZIER,*PEMRPOLYBEZIER,EMRPOLYGON,*PEMRPOLYGON,EMRPOLYBEZIERTO,*PEMRPOLYBEZIERTO,EMRPOLYLINETO,*PEMRPOLYLINETO;

  تعريفنوع بنية ٽيگ_EMRPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
  } EMRPOLYLINE16,*PEMRPOLYLINE16,EMRPOLYBEZIER16,*PEMRPOLYBEZIER16,EMRPOLYGON16,*PEMRPOLYGON16,EMRPOLYBEZIERTO16,*PEMRPOLYBEZIERTO16,EMRPOLYLINETO16,*PEMRPOLYLINETO16;

  تعريفنوع بنية ٽيگ_EMRPOLYDRAW {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW,*PEMRPOLYDRAW;

  تعريفنوع بنية ٽيگ_EMRPOLYDRAW16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW16,*PEMRPOLYDRAW16;

  تعريفنوع بنية ٽيگ_EMRPOLYPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cptl;
    DWORD aPolyCounts[1];
    POINTL aptl[1];
  } EMRPOLYPOLYLINE,*PEMRPOLYPOLYLINE,EMRPOLYPOLYGON,*PEMRPOLYPOLYGON;

  تعريفنوع بنية ٽيگ_EMRPOLYPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cpts;
    DWORD aPolyCounts[1];
    POINTS apts[1];
  } EMRPOLYPOLYLINE16,*PEMRPOLYPOLYLINE16,EMRPOLYPOLYGON16,*PEMRPOLYPOLYGON16;

  تعريفنوع بنية ٽيگ_EMRINVERTRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_معلومات;
    BYTE Rgn_معلومات[1];
  } EMRINVERTRGN,*PEMRINVERTRGN,EMRPAINTRGN,*PEMRPAINTRGN;

  تعريفنوع بنية ٽيگ_EMRFILLRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_معلومات;
    DWORD ihBrush;
    BYTE Rgn_معلومات[1];
  } EMRFILLRGN,*PEMRFILLRGN;

  تعريفنوع بنية ٽيگ_EMRFRAMERGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_معلومات;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE Rgn_معلومات[1];
  } EMRFRAMERGN,*PEMRFRAMERGN;

  تعريفنوع بنية ٽيگ_EMREXTSELECTCLIPRGN {
    EMR emr;
    DWORD cb_Rgn_معلومات;
    DWORD i_گهڻائي;
    BYTE Rgn_معلومات[1];
  } EMREXTSELECTCLIPRGN,*PEMREXTSELECTCLIPRGN;

  تعريفنوع بنية ٽيگ_EMREXTTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_گهڻائي;
    FLOAT exScale;
    FLOAT eyScale;
    EMRTEXT emrtext;
  } EMREXTTEXTOUTA,*PEMREXTTEXTOUTA,EMREXTTEXTOUTW,*PEMREXTTEXTOUTW;

  تعريفنوع بنية ٽيگ_EMRPOLYTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_گهڻائي;
    FLOAT exScale;
    FLOAT eyScale;
    LONG c_لڙيون;
    EMRTEXT aemrtext[1];
  } EMRPOLYTEXTOUTA,*PEMRPOLYTEXTOUTA,EMRPOLYTEXTOUTW,*PEMRPOLYTEXTOUTW;

  تعريفنوع بنية ٽيگ_EMRBITBLT {
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
    DWORD off_بٽ_Src;
    DWORD cb_بٽ_Src;
  } EMRBITBLT,*PEMRBITBLT;

  تعريفنوع بنية ٽيگ_EMRSTRETCHBLT {
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
    DWORD off_بٽ_Src;
    DWORD cb_بٽ_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRSTRETCHBLT,*PEMRSTRETCHBLT;

  تعريفنوع بنية ٽيگ_EMRMASKBLT {
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
    DWORD off_بٽ_Src;
    DWORD cb_بٽ_Src;
    LONG x_نقاب;
    LONG y_نقاب;
    DWORD i_Usage_نقاب;
    DWORD off_Bmi_نقاب;
    DWORD cb_Bmi_نقاب;
    DWORD off_بٽ_نقاب;
    DWORD cb_بٽ_نقاب;
  } EMRMASKBLT,*PEMRMASKBLT;

  تعريفنوع بنية ٽيگ_EMRPLGBLT {
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
    DWORD off_بٽ_Src;
    DWORD cb_بٽ_Src;
    LONG x_نقاب;
    LONG y_نقاب;
    DWORD i_Usage_نقاب;
    DWORD off_Bmi_نقاب;
    DWORD cb_Bmi_نقاب;
    DWORD off_بٽ_نقاب;
    DWORD cb_بٽ_نقاب;
  } EMRPLGBLT,*PEMRPLGBLT;

  تعريفنوع بنية ٽيگ_EMRSETDIBITSTODEVICE {
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
    DWORD off_بٽ_Src;
    DWORD cb_بٽ_Src;
    DWORD iUsageSrc;
    DWORD i_شروعات_جاچ;
    DWORD cScans;
  } EMRSETDIBITSTODEVICE,*PEMRSETDIBITSTODEVICE;

  تعريفنوع بنية ٽيگ_EMRSTRETCHDIBITS {
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
    DWORD off_بٽ_Src;
    DWORD cb_بٽ_Src;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG cxDest;
    LONG cyDest;
  } EMRSTRETCHDIBITS,*PEMRSTRETCHDIBITS;

  تعريفنوع بنية ٽيگ_EMREXTCREATEFONTINDIRECTW {
    EMR emr;
    DWORD ihFont;
    EXTLOGFONTW elfw;
  } EMREXTCREATEFONTINDIRECTW,*PEMREXTCREATEFONTINDIRECTW;

  تعريفنوع بنية ٽيگ_EMRCREATEPALETTE {
    EMR emr;
    DWORD ihPal;
    LOGPALETTE lgpl;
  } EMRCREATEPALETTE,*PEMRCREATEPALETTE;

  تعريفنوع بنية ٽيگ_EMRCREATEPEN {
    EMR emr;
    DWORD ihPen;
    LOGPEN lopn;
  } EMRCREATEPEN,*PEMRCREATEPEN;

  تعريفنوع بنية ٽيگ_EMREXTCREATEPEN {
    EMR emr;
    DWORD ihPen;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بٽ;
    DWORD cb_بٽ;
    EXTLOGPEN elp;
  } EMREXTCREATEPEN,*PEMREXTCREATEPEN;

  تعريفنوع بنية ٽيگ_EMRCREATEBRUSHINDIRECT {
    EMR emr;
    DWORD ihBrush;
    LOGBRUSH32 lb;
  } EMRCREATEBRUSHINDIRECT,*PEMRCREATEBRUSHINDIRECT;

  تعريفنوع بنية ٽيگ_EMRCREATEMONOBRUSH {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بٽ;
    DWORD cb_بٽ;
  } EMRCREATEMONOBRUSH,*PEMRCREATEMONOBRUSH;

  تعريفنوع بنية ٽيگ_EMRCREATEDIBPATTERNBRUSHPT {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_بٽ;
    DWORD cb_بٽ;
  } EMRCREATEDIBPATTERNBRUSHPT,*PEMRCREATEDIBPATTERNBRUSHPT;

  تعريفنوع بنية ٽيگ_EMRFORMAT {
    DWORD dSignature;
    DWORD n_نسخو;
    DWORD cb_معلومات;
    DWORD off_معلومات;
  } EMRFORMAT,*PEMRFORMAT;

  تعريفنوع بنية ٽيگ_EMRGLSRECORD {
    EMR emr;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRGLSRECORD,*PEMRGLSRECORD;

  تعريفنوع بنية ٽيگ_EMRGLSBOUNDEDRECORD {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRGLSBOUNDEDRECORD,*PEMRGLSBOUNDEDRECORD;

  تعريفنوع بنية ٽيگ_EMRPIXELFORMAT {
    EMR emr;
    PIXELFORMATDESCRIPTOR pfd;
  } EMRPIXELFORMAT,*PEMRPIXELFORMAT;

  تعريفنوع بنية ٽيگ_EMRCREATECOLORSPACE {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEA lcs;
  } EMRCREATECOLORSPACE,*PEMRCREATECOLORSPACE;

  تعريفنوع بنية ٽيگ_EMRSETCOLORSPACE {
    EMR emr;
    DWORD ihCS;
  } EMRSETCOLORSPACE,*PEMRSETCOLORSPACE,EMRSELECTCOLORSPACE,*PEMRSELECTCOLORSPACE,EMRDELETECOLORSPACE,*PEMRDELETECOLORSPACE;

  تعريفنوع بنية ٽيگ_EMREXTESCAPE {
    EMR emr;
    INT iEscape;
    INT cb_Esc_معلومات;
    BYTE Esc_معلومات[1];
  } EMREXTESCAPE,*PEMREXTESCAPE,EMRDRAWESCAPE,*PEMRDRAWESCAPE;

  تعريفنوع بنية ٽيگ_EMRNAMEDESCAPE {
    EMR emr;
    INT iEscape;
    INT cbDriver;
    INT cb_Esc_معلومات;
    BYTE Esc_معلومات[1];
  } EMRNAMEDESCAPE,*PEMRNAMEDESCAPE;

#وصف_ڪريو SETICMPROFILE_EMBEDED 0x00000001

  تعريفنوع بنية ٽيگ_EMRSETICMPROFILE {
    EMR emr;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRSETICMPROFILE,*PEMRSETICMPROFILE,EMRSETICMPROFILEA,*PEMRSETICMPROFILEA,EMRSETICMPROFILEW,*PEMRSETICMPROFILEW;

#وصف_ڪريو CREATECOLORSPACE_EMBEDED 0x00000001

  تعريفنوع بنية ٽيگ_EMRCREATECOLORSPACEW {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEW lcs;
    DWORD dwFlags;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRCREATECOLORSPACEW,*PEMRCREATECOLORSPACEW;

#وصف_ڪريو COLORMATCHTOTARGET_EMBEDED 0x00000001

  تعريفنوع بنية ٽيگ_COLORMATCHTOTARGET {
    EMR emr;
    DWORD dwAction;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_معلومات;
    BYTE معلومات_3[1];
  } EMRCOLORMATCHTOTARGET,*PEMRCOLORMATCHTOTARGET;

  تعريفنوع بنية ٽيگ_COLORCORRECTPALETTE {
    EMR emr;
    DWORD ihPalette;
    DWORD n_پهريون_داخلا;
    DWORD nPalEntries;
    DWORD nReserved;
  } EMRCOLORCORRECTPALETTE,*PEMRCOLORCORRECTPALETTE;

  تعريفنوع بنية ٽيگ_EMRALPHABLEND {
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
    DWORD off_بٽ_Src;
    DWORD cb_بٽ_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRALPHABLEND,*PEMRALPHABLEND;

  تعريفنوع بنية ٽيگ_EMRGRADIENTFILL {
    EMR emr;
    RECTL rclBounds;
    DWORD nVer;
    DWORD nTri;
    ULONG ul_گهڻائي;
    TRIVERTEX Ver[1];
  } EMRGRADIENTFILL,*PEMRGRADIENTFILL;

  تعريفنوع بنية ٽيگ_EMRTRANSPARENTBLT {
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
    DWORD off_بٽ_Src;
    DWORD cb_بٽ_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRTRANSPARENTBLT,*PEMRTRANSPARENTBLT;

#وصف_ڪريو GDICOMMENT_IDENTIFIER 0x43494447
#وصف_ڪريو GDICOMMENT_WINDOWS_METAFILE 0x80000001
#وصف_ڪريو GDICOMMENT_BEGINGROUP 0x00000002
#وصف_ڪريو GDICOMMENT_ENDGROUP 0x00000003
#وصف_ڪريو GDICOMMENT_MULTIFORMATS 0x40000004
#وصف_ڪريو EPS_SIGNATURE 0x46535045
#وصف_ڪريو GDICOMMENT_UNICODE_STRING 0x00000040
#وصف_ڪريو GDICOMMENT_UNICODE_پڇاڙي 0x00000080
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو wglUseFontBitmaps wglUseFontBitmapsW
#وإلا
#وصف_ڪريو wglUseFontBitmaps wglUseFontBitmapsA
#جيڪڏهن_پورو

  WINGDIAPI WINBOOL WINAPI wglCopyContext(HGLRC,HGLRC,UINT);
  WINGDIAPI HGLRC WINAPI wglCreateContext(HDC);
  WINGDIAPI HGLRC WINAPI wglCreateLayerContext(HDC,صحيح);
  WINGDIAPI WINBOOL WINAPI wglDeleteContext(HGLRC);
  WINGDIAPI HGLRC WINAPI wglGetCurrentContext(VOID);
  WINGDIAPI HDC WINAPI wglGetCurrentDC(VOID);
  WINGDIAPI PROC WINAPI wgl_Get_Proc_پتو(LPCSTR);
  WINGDIAPI WINBOOL WINAPI wglMakeCurrent(HDC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglShareLists(HGLRC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsA(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsW(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI مٽا_سٽا_Buffers(HDC);

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

#وصف_ڪريو WGL_FONT_سٽون 0
#وصف_ڪريو WGL_FONT_POLYGONS 1

#جيڪڏهن_وصف_ٿيل UNICODE
#وصف_ڪريو wglUseFontOutlines wglUseFontOutlinesW
#وإلا
#وصف_ڪريو wglUseFontOutlines wglUseFontOutlinesA
#جيڪڏهن_پورو

  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesA(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,صحيح,LPGLYPHMETRICSFLOAT);
  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesW(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,صحيح,LPGLYPHMETRICSFLOAT);

  تعريفنوع بنية ٽيگ_LAYERPLANEDESCRIPTOR {
    لفظ_3 n_سائيز;
    لفظ_3 n_نسخو;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_بٽ;
    BYTE c_Red_بٽ;
    BYTE c_Red_سرڪايو;
    BYTE c_Green_بٽ;
    BYTE c_Green_سرڪايو;
    BYTE c_Blue_بٽ;
    BYTE c_Blue_سرڪايو;
    BYTE c_Alpha_بٽ;
    BYTE c_Alpha_سرڪايو;
    BYTE c_Accum_بٽ;
    BYTE c_Accum_Red_بٽ;
    BYTE c_Accum_Green_بٽ;
    BYTE c_Accum_Blue_بٽ;
    BYTE c_Accum_Alpha_بٽ;
    BYTE c_اونهائي_بٽ;
    BYTE c_Stencil_بٽ;
    BYTE cAuxBuffers;
    BYTE iLayerPlane;
    BYTE bReserved;
    COLORREF crTransparent;
  } LAYERPLANEDESCRIPTOR,*PLAYERPLANEDESCRIPTOR,*LPLAYERPLANEDESCRIPTOR;

#وصف_ڪريو LPD_DOUBLEBUFFER 0x00000001
#وصف_ڪريو LPD_STEREO 0x00000002
#وصف_ڪريو LPD_SUPPORT_GDI 0x00000010
#وصف_ڪريو LPD_SUPPORT_OPENGL 0x00000020
#وصف_ڪريو LPD_SHARE_اونهائي 0x00000040
#وصف_ڪريو LPD_SHARE_STENCIL 0x00000080
#وصف_ڪريو LPD_SHARE_ACCUM 0x00000100
#وصف_ڪريو LPD_مٽا_سٽا_EXCHANGE 0x00000200
#وصف_ڪريو LPD_مٽا_سٽا_COPY 0x00000400
#وصف_ڪريو LPD_TRANSPARENT 0x00001000

#وصف_ڪريو LPD_TYPE_RGBA 0
#وصف_ڪريو LPD_TYPE_COLORINDEX 1

#وصف_ڪريو WGL_مٽا_سٽا_MAIN_PLANE 0x00000001
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY1 0x00000002
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY2 0x00000004
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY3 0x00000008
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY4 0x00000010
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY5 0x00000020
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY6 0x00000040
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY7 0x00000080
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY8 0x00000100
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY9 0x00000200
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY10 0x00000400
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY11 0x00000800
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY12 0x00001000
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY13 0x00002000
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY14 0x00004000
#وصف_ڪريو WGL_مٽا_سٽا_OVERLAY15 0x00008000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY1 0x00010000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY2 0x00020000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY3 0x00040000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY4 0x00080000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY5 0x00100000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY6 0x00200000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY7 0x00400000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY8 0x00800000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY9 0x01000000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY10 0x02000000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY11 0x04000000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY12 0x08000000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY13 0x10000000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY14 0x20000000
#وصف_ڪريو WGL_مٽا_سٽا_UNDERLAY15 0x40000000

  WINGDIAPI WINBOOL WINAPI wglDescribeLayerPlane(HDC,صحيح,صحيح,UINT,LPLAYERPLANEDESCRIPTOR);
  WINGDIAPI صحيح WINAPI wgl_سيٽ_Layer_Palette_Entries(HDC,صحيح,صحيح,صحيح,CONST COLORREF *);
  WINGDIAPI صحيح WINAPI wglGetLayerPaletteEntries(HDC,صحيح,صحيح,صحيح,COLORREF *);
  WINGDIAPI WINBOOL WINAPI wglRealizeLayerPalette(HDC,صحيح,WINBOOL);
  WINGDIAPI WINBOOL WINAPI wgl_مٽا_سٽا_Layer_Buffers(HDC,UINT);

  تعريفنوع بنية _WGLSWAP {
    HDC hdc;
    UINT uiFlags;
  } WGLSWAP,*PWGLSWAP,*LPWGLSWAP;

#وصف_ڪريو WGL_SWAPMULTIPLE_MAX 16

  WINGDIAPI DWORD WINAPI wgl_مٽا_سٽا_گڻو_Buffers(UINT,CONST WGLSWAP *);
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو
#جيڪڏهن_پورو
