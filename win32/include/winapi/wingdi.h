/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _WINGDI_
#परिभाषय _WINGDI_

#परिभाषय WINGDIAPI DECLSPEC_IMPORT
#परिभाषय WINSPOOLAPI DECLSPEC_IMPORT

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#यदि_अपरिभाषितम् WINVER
#परिभाषय WINVER 0x0502
#यदि_अन्तः

#यदि_अपरिभाषितम् NOGDI
#यदि_अपरिभाषितम् NORASTEROPS
#परिभाषय R2_BLACK 1
#परिभाषय R2_NOTMERGEPEN 2
#परिभाषय R2_MASKNOTPEN 3
#परिभाषय R2_NOTCOPYPEN 4
#परिभाषय R2_MASKPENNOT 5
#परिभाषय R2_NOT 6
#परिभाषय R2_XORPEN 7
#परिभाषय R2_NOTMASKPEN 8
#परिभाषय R2_MASKPEN 9
#परिभाषय R2_NOTXORPEN 10
#परिभाषय R2_NOP 11
#परिभाषय R2_MERGENOTPEN 12
#परिभाषय R2_COPYPEN 13
#परिभाषय R2_MERGEPENNOT 14
#परिभाषय R2_MERGEPEN 15
#परिभाषय R2_WHITE 16
#परिभाषय R2_चरमः 16

#परिभाषय SRCCOPY (DWORD)0x00CC0020
#परिभाषय SRCPAINT (DWORD)0x00EE0086
#परिभाषय SRCAND (DWORD)0x008800C6
#परिभाषय SRCINVERT (DWORD)0x00660046
#परिभाषय SRCERASE (DWORD)0x00440328
#परिभाषय NOTSRCCOPY (DWORD)0x00330008
#परिभाषय NOTSRCERASE (DWORD)0x001100A6
#परिभाषय MERGECOPY (DWORD)0x00C000CA
#परिभाषय MERGEPAINT (DWORD)0x00BB0226
#परिभाषय PATCOPY (DWORD)0x00F00021
#परिभाषय PATPAINT (DWORD)0x00FB0A09
#परिभाषय PATINVERT (DWORD)0x005A0049
#परिभाषय DSTINVERT (DWORD)0x00550009
#परिभाषय BLACKNESS (DWORD)0x00000042
#परिभाषय WHITENESS (DWORD)0x00FF0062
#परिभाषय NOMIRRORBITMAP (DWORD)0x80000000
#परिभाषय CAPTUREBLT (DWORD)0x40000000
#परिभाषय MAKEROP4(fore,पृष्ठभागः) (DWORD)((((पृष्ठभागः) << 8) & 0xFF000000) | (fore))
#यदि_अन्तः

#परिभाषय GDI_ERROR (0xFFFFFFFFL)
#परिभाषय HGDI_ERROR (Long_गन्तव्यम्_Handle(0xFFFFFFFFL))

#परिभाषय ERROR 0
#परिभाषय NULLREGION 1
#परिभाषय SIMPLEREGION 2
#परिभाषय COMPLEXREGION 3
#परिभाषय RGN_ERROR ERROR

#परिभाषय RGN_AND 1
#परिभाषय RGN_OR 2
#परिभाषय RGN_XOR 3
#परिभाषय RGN_DIFF 4
#परिभाषय RGN_COPY 5
#परिभाषय RGN_MIN RGN_AND
#परिभाषय RGN_MAX RGN_COPY

#परिभाषय BLACKONWHITE 1
#परिभाषय WHITEONBLACK 2
#परिभाषय COLORONCOLOR 3
#परिभाषय HALFTONE 4
#परिभाषय MAXSTRETCHBLTMODE 4

#परिभाषय STRETCH_ANDSCANS BLACKONWHITE
#परिभाषय STRETCH_ORSCANS WHITEONBLACK
#परिभाषय STRETCH_DELETESCANS COLORONCOLOR
#परिभाषय STRETCH_HALFTONE HALFTONE

#परिभाषय ALTERNATE 1
#परिभाषय WINDING 2
#परिभाषय POLYFILL_चरमः 2

#परिभाषय LAYOUT_RTL 0x00000001
#परिभाषय LAYOUT_BTT 0x00000002
#परिभाषय LAYOUT_VBH 0x00000004
#परिभाषय LAYOUT_ORIENTATIONMASK (LAYOUT_RTL | LAYOUT_BTT | LAYOUT_VBH)
#परिभाषय LAYOUT_BITMAPORIENTATIONPRESERVED 0x00000008

#परिभाषय TA_NOUPDATECP 0
#परिभाषय TA_UPDATECP 1

#परिभाषय TA_वामः 0
#परिभाषय TA_दक्षिणः 2
#परिभाषय TA_CENTER 6

#परिभाषय TA_शिखरम् 0
#परिभाषय TA_BOTTOM 8
#परिभाषय TA_BASELINE 24
#परिभाषय TA_RTLREADING 256
#परिभाषय TA_आवरणम् (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)

#परिभाषय VTA_BASELINE TA_BASELINE
#परिभाषय VTA_वामः TA_BOTTOM
#परिभाषय VTA_दक्षिणः TA_शिखरम्
#परिभाषय VTA_CENTER TA_CENTER
#परिभाषय VTA_BOTTOM TA_दक्षिणः
#परिभाषय VTA_शिखरम् TA_वामः

#परिभाषय ETO_OPAQUE 0x0002
#परिभाषय ETO_CLIPPED 0x0004
#परिभाषय ETO_GLYPH_सूचकांक 0x0010
#परिभाषय ETO_RTLREADING 0x0080
#परिभाषय ETO_NUMERICSLOCAL 0x0400
#परिभाषय ETO_NUMERICSLATIN 0x0800
#परिभाषय ETO_IGNORELANGUAGE 0x1000
#परिभाषय ETO_PDY 0x2000

#परिभाषय ASPECT_FILTERING 0x0001

#परिभाषय DCB_RESET 0x0001
#परिभाषय DCB_ACCUMULATE 0x0002
#परिभाषय DCB_DIRTY DCB_ACCUMULATE
#परिभाषय DCB_समुच्चयः (DCB_RESET | DCB_ACCUMULATE)
#परिभाषय DCB_ENABLE 0x0004
#परिभाषय DCB_DISABLE 0x0008

#यदि_अपरिभाषितम् NOMETAFILE

#परिभाषय META_SETBKCOLOR 0x0201
#परिभाषय META_SETBKMODE 0x0102
#परिभाषय META_SETMAPMODE 0x0103
#परिभाषय META_SETROP2 0x0104
#परिभाषय META_SETRELABS 0x0105
#परिभाषय META_SETPOLYFILLMODE 0x0106
#परिभाषय META_SETSTRETCHBLTMODE 0x0107
#परिभाषय META_SETTEXTCHAREXTRA 0x0108
#परिभाषय META_SETTEXTCOLOR 0x0209
#परिभाषय META_SETTEXTJUSTIFICATION 0x020A
#परिभाषय META_SETWINDOWORG 0x020B
#परिभाषय META_SETWINDOWEXT 0x020C
#परिभाषय META_SETVIEWPORTORG 0x020D
#परिभाषय META_SETVIEWPORTEXT 0x020E
#परिभाषय META_OFFSETWINDOWORG 0x020F
#परिभाषय META_SCALEWINDOWEXT 0x0410
#परिभाषय META_OFFSETVIEWPORTORG 0x0211
#परिभाषय META_SCALEVIEWPORTEXT 0x0412
#परिभाषय META_LINETO 0x0213
#परिभाषय META_MOVETO 0x0214
#परिभाषय META_EXCLUDECLIPRECT 0x0415
#परिभाषय META_INTERSECTCLIPRECT 0x0416
#परिभाषय META_ARC 0x0817
#परिभाषय META_ELLIPSE 0x0418
#परिभाषय META_FLOODFILL 0x0419
#परिभाषय META_PIE 0x081A
#परिभाषय META_RECTANGLE 0x041B
#परिभाषय META_ROUNDRECT 0x061C
#परिभाषय META_PATBLT 0x061D
#परिभाषय META_SAVEDC 0x001E
#परिभाषय META_SETPIXEL 0x041F
#परिभाषय META_OFFSETCLIPRGN 0x0220
#परिभाषय META_TEXTOUT 0x0521
#परिभाषय META_BITBLT 0x0922
#परिभाषय META_STRETCHBLT 0x0B23
#परिभाषय META_POLYGON 0x0324
#परिभाषय META_POLYLINE 0x0325
#परिभाषय META_ESCAPE 0x0626
#परिभाषय META_RESTOREDC 0x0127
#परिभाषय META_FILLREGION 0x0228
#परिभाषय META_FRAMEREGION 0x0429
#परिभाषय META_INVERTREGION 0x012A
#परिभाषय META_PAINTREGION 0x012B
#परिभाषय META_SELECTCLIPREGION 0x012C
#परिभाषय META_SELECTOBJECT 0x012D
#परिभाषय META_SETTEXTALIGN 0x012E
#परिभाषय META_CHORD 0x0830
#परिभाषय META_SETMAPPERFLAGS 0x0231
#परिभाषय META_EXTTEXTOUT 0x0a32
#परिभाषय META_SETDIBTODEV 0x0d33
#परिभाषय META_SELECTPALETTE 0x0234
#परिभाषय META_REALIZEPALETTE 0x0035
#परिभाषय META_ANIMATEPALETTE 0x0436
#परिभाषय META_SETPALENTRIES 0x0037
#परिभाषय META_POLYPOLYGON 0x0538
#परिभाषय META_RESIZEPALETTE 0x0139
#परिभाषय META_DIBBITBLT 0x0940
#परिभाषय META_DIBSTRETCHBLT 0x0b41
#परिभाषय META_DIBCREATEPATTERNBRUSH 0x0142
#परिभाषय META_STRETCHDIB 0x0f43
#परिभाषय META_EXTFLOODFILL 0x0548
#परिभाषय META_SETLAYOUT 0x0149
#परिभाषय META_DELETEOBJECT 0x01f0
#परिभाषय META_CREATEPALETTE 0x00f7
#परिभाषय META_CREATEPATTERNBRUSH 0x01F9
#परिभाषय META_CREATEPENINDIRECT 0x02FA
#परिभाषय META_CREATEFONTINDIRECT 0x02FB
#परिभाषय META_CREATEBRUSHINDIRECT 0x02FC
#परिभाषय META_CREATEREGION 0x06FF

  प्रकारनिर्देश संरचना _DRAWPATRECT {
    POINT ptPosition;
    POINT pt_आकार;
    WORD wStyle;
    WORD w_आदर्शः;
  } DRAWPATRECT,*PDRAWPATRECT;
#यदि_अन्तः

#परिभाषय NEWFRAME 1
#परिभाषय ABORTDOC 2
#परिभाषय NEXTBAND 3
#परिभाषय SETCOLORTABLE 4
#परिभाषय GETCOLORTABLE 5
#परिभाषय FLUSHOUTPUT 6
#परिभाषय DRAFTMODE 7
#परिभाषय QUERYESCSUPPORT 8
#परिभाषय SETABORTPROC 9
#परिभाषय STARTDOC 10
#परिभाषय ENDDOC 11
#परिभाषय GETPHYSPAGESIZE 12
#परिभाषय GETPRINTINGOFFSET 13
#परिभाषय GETSCALINGFACTOR 14
#परिभाषय MFCOMMENT 15
#परिभाषय GETPENWIDTH 16
#परिभाषय SETCOPYCOUNT 17
#परिभाषय SELECTPAPERSOURCE 18
#परिभाषय DEVICEDATA 19
#परिभाषय PASSTHROUGH 19
#परिभाषय GETTECHNOLGY 20
#परिभाषय GETTECHNOLOGY 20
#परिभाषय SETLINECAP 21
#परिभाषय SETLINEJOIN 22
#परिभाषय SETMITERLIMIT 23
#परिभाषय BANDINFO 24
#परिभाषय DRAWPATTERNRECT 25
#परिभाषय GETVECTORPENSIZE 26
#परिभाषय GETVECTORBRUSHSIZE 27
#परिभाषय ENABLEDUPLEX 28
#परिभाषय GETSETPAPERBINS 29
#परिभाषय GETSETPRINTORIENT 30
#परिभाषय ENUMPAPERBINS 31
#परिभाषय SETDIBSCALING 32
#परिभाषय EPSPRINTING 33
#परिभाषय ENUMPAPERMETRICS 34
#परिभाषय GETSETPAPERMETRICS 35
#परिभाषय POSTSCRIPT_दत्त 37
#परिभाषय POSTSCRIPT_IGNORE 38
#परिभाषय MOUSETRAILS 39
#परिभाषय GETDEVICEUNITS 42

#परिभाषय GETEXTENDEDTEXTMETRICS 256
#परिभाषय GETEXTENTTABLE 257
#परिभाषय GETPAIRKERNTABLE 258
#परिभाषय GETTRACKKERNTABLE 259
#परिभाषय EXTTEXTOUT 512
#परिभाषय GETFACENAME 513
#परिभाषय DOWNLOADFACE 514
#परिभाषय ENABLERELATIVEWIDTHS 768
#परिभाषय ENABLEPAIRKERNING 769
#परिभाषय SETKERNTRACK 770
#परिभाषय SETALLJUSTVALUES 771
#परिभाषय SETCHARSET 772

#परिभाषय STRETCHBLT 2048
#परिभाषय METAFILE_DRIVER 2049
#परिभाषय GETSETSCREENPARAMS 3072
#परिभाषय QUERYDIBSUPPORT 3073
#परिभाषय BEGIN_मार्गः 4096
#परिभाषय CLIP_गन्तव्यम्_मार्गः 4097
#परिभाषय अन्तः_मार्गः 4098
#परिभाषय EXT_DEVICE_CAPS 4099
#परिभाषय RESTORE_CTM 4100
#परिभाषय SAVE_CTM 4101
#परिभाषय समुच्चयः_ARC_DIRECTION 4102
#परिभाषय समुच्चयः_BACKGROUND_COLOR 4103
#परिभाषय समुच्चयः_POLY_बहुलकम् 4104
#परिभाषय समुच्चयः_SCREEN_ANGLE 4105
#परिभाषय समुच्चयः_प्रसारः 4106
#परिभाषय TRANSFORM_CTM 4107
#परिभाषय समुच्चयः_CLIP_BOX 4108
#परिभाषय समुच्चयः_BOUNDS 4109
#परिभाषय समुच्चयः_MIRROR_बहुलकम् 4110
#परिभाषय OPENCHANNEL 4110
#परिभाषय DOWNLOADHEADER 4111
#परिभाषय CLOSECHANNEL 4112
#परिभाषय POSTSCRIPT_PASSTHROUGH 4115
#परिभाषय ENCAPSULATED_POSTSCRIPT 4116

#परिभाषय POSTSCRIPT_IDENTIFY 4117
#परिभाषय POSTSCRIPT_INJECTION 4118

#परिभाषय CHECKJPEGFORMAT 4119
#परिभाषय CHECKPNGFORMAT 4120

#परिभाषय GET_PS_FEATURESETTING 4121

#परिभाषय SPCLPASSTHROUGH2 4568

#परिभाषय PSIDENT_GDICENTRIC 0
#परिभाषय PSIDENT_PSCENTRIC 1

  प्रकारनिर्देश संरचना _PSINJECTDATA {
    DWORD दत्त_अष्टकानि;
    WORD InjectionPoint;
    WORD Page_सङ्ख्या;
  } PSINJECTDATA,*PPSINJECTDATA;

#परिभाषय PSINJECT_BEGINSTREAM 1
#परिभाषय PSINJECT_PSADOBE 2
#परिभाषय PSINJECT_PAGESATEND 3
#परिभाषय PSINJECT_पृष्ठानि 4

#परिभाषय PSINJECT_DOCNEEDEDRES 5
#परिभाषय PSINJECT_DOCSUPPLIEDRES 6
#परिभाषय PSINJECT_PAGEORDER 7
#परिभाषय PSINJECT_ORIENTATION 8
#परिभाषय PSINJECT_BOUNDINGBOX 9
#परिभाषय PSINJECT_DOCUMENTPROCESSCOLORS 10

#परिभाषय PSINJECT_COMMENTS 11
#परिभाषय PSINJECT_BEGINDEFAULTS 12
#परिभाषय PSINJECT_ENDDEFAULTS 13
#परिभाषय PSINJECT_BEGINPROLOG 14
#परिभाषय PSINJECT_ENDPROLOG 15
#परिभाषय PSINJECT_BEGINSETUP 16
#परिभाषय PSINJECT_ENDSETUP 17
#परिभाषय PSINJECT_TRAILER 18
#परिभाषय PSINJECT_EOF 19
#परिभाषय PSINJECT_ENDSTREAM 20
#परिभाषय PSINJECT_DOCUMENTPROCESSCOLORSATEND 21

#परिभाषय PSINJECT_PAGENUMBER 100
#परिभाषय PSINJECT_BEGINPAGESETUP 101
#परिभाषय PSINJECT_ENDPAGESETUP 102
#परिभाषय PSINJECT_PAGETRAILER 103
#परिभाषय PSINJECT_PLATECOLOR 104

#परिभाषय PSINJECT_SHOWPAGE 105
#परिभाषय PSINJECT_PAGEBBOX 106
#परिभाषय PSINJECT_ENDPAGECOMMENTS 107

#परिभाषय PSINJECT_VMSAVE 200
#परिभाषय PSINJECT_VMRESTORE 201

#परिभाषय FEATURESETTING_NUP 0
#परिभाषय FEATURESETTING_OUTPUT 1
#परिभाषय FEATURESETTING_PSLEVEL 2
#परिभाषय FEATURESETTING_CUSTPAPER 3
#परिभाषय FEATURESETTING_MIRROR 4
#परिभाषय FEATURESETTING_NEGATIVE 5
#परिभाषय FEATURESETTING_PROTOCOL 6

#परिभाषय FEATURESETTING_वैयक्तिकम्_BEGIN 0x1000
#परिभाषय FEATURESETTING_वैयक्तिकम्_अन्तः 0x1FFF

  प्रकारनिर्देश संरचना _PSFEATURE_OUTPUT {
    WINBOOL bPageIndependent;
    WINBOOL b_समुच्चयः_Page_Device;
  } PSFEATURE_OUTPUT,*PPSFEATURE_OUTPUT;

  प्रकारनिर्देश संरचना _PSFEATURE_CUSTPAPER {
    LONG lOrientation;
    LONG l_विस्तारः;
    LONG lHeight;
    LONG l_विस्तारः_विस्थापनम्;
    LONG l_Height_विस्थापनम्;
  } PSFEATURE_CUSTPAPER,*PPSFEATURE_CUSTPAPER;

#परिभाषय PSPROTOCOL_ASCII 0
#परिभाषय PSPROTOCOL_BCP 1
#परिभाषय PSPROTOCOL_TBCP 2
#परिभाषय PSPROTOCOL_द्विमान 3

#परिभाषय QDI_SETDIBITS 1
#परिभाषय QDI_GETDIBITS 2
#परिभाषय QDI_DIBTOSCREEN 4
#परिभाषय QDI_STRETCHDIB 8

#परिभाषय SP_NOTREPORTED 0x4000
#परिभाषय SP_ERROR (-1)
#परिभाषय SP_APPABORT (-2)
#परिभाषय SP_USERABORT (-3)
#परिभाषय SP_OUTOFDISK (-4)
#परिभाषय SP_OUTOFMEMORY (-5)

#परिभाषय PR_JOBSTATUS 0x0000

#परिभाषय OBJ_PEN 1
#परिभाषय OBJ_BRUSH 2
#परिभाषय OBJ_DC 3
#परिभाषय OBJ_METADC 4
#परिभाषय OBJ_PAL 5
#परिभाषय OBJ_FONT 6
#परिभाषय OBJ_BITMAP 7
#परिभाषय OBJ_REGION 8
#परिभाषय OBJ_METAFILE 9
#परिभाषय OBJ_MEMDC 10
#परिभाषय OBJ_EXTPEN 11
#परिभाषय OBJ_ENHMETADC 12
#परिभाषय OBJ_ENHMETAFILE 13
#परिभाषय OBJ_COLORSPACE 14

#परिभाषय MWT_तटस्थः 1
#परिभाषय MWT_LEFTMULTIPLY 2
#परिभाषय MWT_RIGHTMULTIPLY 3

#परिभाषय MWT_MIN MWT_तटस्थः
#परिभाषय MWT_MAX MWT_RIGHTMULTIPLY

#परिभाषय _XFORM_
  प्रकारनिर्देश संरचना चिह्नकम्_XFORM {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
  } XFORM,*PXFORM,*LPXFORM;

  प्रकारनिर्देश संरचना चिह्नकम्_BITMAP {
    LONG bmType;
    LONG bm_विस्तारः;
    LONG bmHeight;
    LONG bm_विस्तारः_अष्टकानि;
    WORD bmPlanes;
    WORD bm_द्वयङ्काः_Pixel;
    LPVOID bm_द्वयङ्काः;
  } BITMAP,*PBITMAP,*NPBITMAP,*LPBITMAP;

#अन्तर्भाव <pshpack1.h>
  प्रकारनिर्देश संरचना चिह्नकम्_RGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
  } RGBTRIPLE;
#अन्तर्भाव <poppack.h>

  प्रकारनिर्देश संरचना चिह्नकम्_RGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
  } RGBQUAD;
  प्रकारनिर्देश RGBQUAD *LPRGBQUAD;

#परिभाषय CS_ENABLE 0x00000001L
#परिभाषय CS_DISABLE 0x00000002L
#परिभाषय CS_DELETE_TRANSFORM 0x00000003L

//!__TINYC__: #define LCS_SIGNATURE 'PSOC'
//!__TINYC__: #define LCS_sRGB 'sRGB'
//!__TINYC__: #define LCS_WINDOWS_COLOR_SPACE 'Win '

  प्रकारनिर्देश LONG LCSCSTYPE;
#परिभाषय LCS_CALIBRATED_RGB 0x00000000L

  प्रकारनिर्देश LONG LCSGAMUTMATCH;
#परिभाषय LCS_GM_BUSINESS 0x00000001L
#परिभाषय LCS_GM_GRAPHICS 0x00000002L
#परिभाषय LCS_GM_IMAGES 0x00000004L
#परिभाषय LCS_GM_ABS_COLORIMETRIC 0x00000008L

#परिभाषय CM_बहिर्गमनम्_सम्बन्धि_GAMUT 255
#परिभाषय CM_अन्तर्_GAMUT 0

#परिभाषय ICM_ADDPROFILE 1
#परिभाषय ICM_DELETEPROFILE 2
#परिभाषय ICM_QUERYPROFILE 3
#परिभाषय ICM_SETDEFAULTPROFILE 4
#परिभाषय ICM_REGISTERICMATCHER 5
#परिभाषय ICM_UNREGISTERICMATCHER 6
#परिभाषय ICM_QUERYMATCH 7

#परिभाषय GetKValue(cmyk) ((BYTE)(cmyk))
#परिभाषय GetYValue(cmyk) ((BYTE)((cmyk)>> 8))
#परिभाषय GetMValue(cmyk) ((BYTE)((cmyk)>>16))
#परिभाषय GetCValue(cmyk) ((BYTE)((cmyk)>>24))

#परिभाषय CMYK(c,m,y,k) ((COLORREF)((((BYTE)(k)|((WORD)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

  प्रकारनिर्देश दीर्घ FXPT16DOT16,*LPFXPT16DOT16;
  प्रकारनिर्देश दीर्घ FXPT2DOT30,*LPFXPT2DOT30;

  प्रकारनिर्देश संरचना चिह्नकम्_CIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
  } CIEXYZ;
  प्रकारनिर्देश CIEXYZ *LPCIEXYZ;

  प्रकारनिर्देश संरचना चिह्नकम्_ICEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
  } CIEXYZTRIPLE;

  प्रकारनिर्देश CIEXYZTRIPLE *LPCIEXYZTRIPLE;

  प्रकारनिर्देश संरचना चिह्नकम्_LOGCOLORSPACEA {
    DWORD lcsSignature;
    DWORD lcs_संस्करणम्;
    DWORD lcs_आकार;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    CHAR lcsFilename[MAX_मार्गः];
  } LOGCOLORSPACEA,*LPLOGCOLORSPACEA;

  प्रकारनिर्देश संरचना चिह्नकम्_LOGCOLORSPACEW {
    DWORD lcsSignature;
    DWORD lcs_संस्करणम्;
    DWORD lcs_आकार;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    WCHAR lcsFilename[MAX_मार्गः];
  } LOGCOLORSPACEW,*LPLOGCOLORSPACEW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश LOGCOLORSPACEW LOGCOLORSPACE;
  प्रकारनिर्देश LPLOGCOLORSPACEW LPLOGCOLORSPACE;
#अन्यथा
  प्रकारनिर्देश LOGCOLORSPACEA LOGCOLORSPACE;
  प्रकारनिर्देश LPLOGCOLORSPACEA LPLOGCOLORSPACE;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_BITMAPCOREHEADER {
    DWORD bc_आकार;
    WORD bc_विस्तारः;
    WORD bcHeight;
    WORD bcPlanes;
    WORD bc_Bit_गणनम्;
  } BITMAPCOREHEADER,*LPBITMAPCOREHEADER,*PBITMAPCOREHEADER;

  प्रकारनिर्देश संरचना चिह्नकम्_BITMAPINFOHEADER {
    DWORD bi_आकार;
    LONG bi_विस्तारः;
    LONG biHeight;
    WORD biPlanes;
    WORD bi_Bit_गणनम्;
    DWORD biCompression;
    DWORD bi_आकार_Image;
    LONG bi_XPels_प्रत्येकम्_Meter;
    LONG bi_YPels_प्रत्येकम्_Meter;
    DWORD bi_Clr_प्रयुक्तम्;
    DWORD biClrImportant;
  } BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

  प्रकारनिर्देश संरचना {
    DWORD b_V4_आकार;
    LONG b_V4_विस्तारः;
    LONG bV4Height;
    WORD bV4Planes;
    WORD b_V4_Bit_गणनम्;
    DWORD bV4V4Compression;
    DWORD b_V4_आकार_Image;
    LONG b_V4_XPels_प्रत्येकम्_Meter;
    LONG b_V4_YPels_प्रत्येकम्_Meter;
    DWORD b_V4_Clr_प्रयुक्तम्;
    DWORD bV4ClrImportant;
    DWORD b_V4_Red_आवरणम्;
    DWORD b_V4_Green_आवरणम्;
    DWORD b_V4_Blue_आवरणम्;
    DWORD b_V4_Alpha_आवरणम्;
    DWORD bV4CSType;
    CIEXYZTRIPLE bV4Endpoints;
    DWORD bV4GammaRed;
    DWORD bV4GammaGreen;
    DWORD bV4GammaBlue;
  } BITMAPV4_शीर्षकम्,*LPBITMAPV4_शीर्षकम्,*PBITMAPV4_शीर्षकम्;

  प्रकारनिर्देश संरचना {
    DWORD b_V5_आकार;
    LONG b_V5_विस्तारः;
    LONG bV5Height;
    WORD bV5Planes;
    WORD b_V5_Bit_गणनम्;
    DWORD bV5Compression;
    DWORD b_V5_आकार_Image;
    LONG b_V5_XPels_प्रत्येकम्_Meter;
    LONG b_V5_YPels_प्रत्येकम्_Meter;
    DWORD b_V5_Clr_प्रयुक्तम्;
    DWORD bV5ClrImportant;
    DWORD b_V5_Red_आवरणम्;
    DWORD b_V5_Green_आवरणम्;
    DWORD b_V5_Blue_आवरणम्;
    DWORD b_V5_Alpha_आवरणम्;
    DWORD bV5CSType;
    CIEXYZTRIPLE bV5Endpoints;
    DWORD bV5GammaRed;
    DWORD bV5GammaGreen;
    DWORD bV5GammaBlue;
    DWORD bV5Intent;
    DWORD b_V5_Profile_दत्त;
    DWORD b_V5_Profile_आकार;
    DWORD bV5Reserved;
  } BITMAPV5_शीर्षकम्,*LPBITMAPV5_शीर्षकम्,*PBITMAPV5_शीर्षकम्;

//!__TINYC__: #define PROFILE_LINKED 'LINK'
//!__TINYC__: #define PROFILE_EMBEDDED 'MBED'

#परिभाषय BI_RGB 0L
#परिभाषय BI_RLE8 1L
#परिभाषय BI_RLE4 2L
#परिभाषय BI_BITFIELDS 3L
#परिभाषय BI_JPEG 4L
#परिभाषय BI_PNG 5L

  प्रकारनिर्देश संरचना चिह्नकम्_BITMAPINFO {
    BITMAPINFOHEADER bmi_शीर्षकम्;
    RGBQUAD bmiColors[1];
  } BITMAPINFO,*LPBITMAPINFO,*PBITMAPINFO;

  प्रकारनिर्देश संरचना चिह्नकम्_BITMAPCOREINFO {
    BITMAPCOREHEADER bmci_शीर्षकम्;
    RGBTRIPLE bmciColors[1];
  } BITMAPCOREINFO,*LPBITMAPCOREINFO,*PBITMAPCOREINFO;

#अन्तर्भाव <pshpack2.h>
  प्रकारनिर्देश संरचना चिह्नकम्_BITMAPFILEHEADER {
    WORD bfType;
    DWORD bf_आकार;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bf_Off_द्वयङ्काः;
  } BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#अन्तर्भाव <poppack.h>

#परिभाषय MAKEPOINTS(l) (*((POINTS *)&(l)))

#यदि_अपरिभाषितम् NOFONTSIG
  प्रकारनिर्देश संरचना चिह्नकम्_FONTSIGNATURE {
    DWORD fsUsb[4];
    DWORD fsCsb[2];
  } FONTSIGNATURE,*PFONTSIGNATURE,*LPFONTSIGNATURE;

  प्रकारनिर्देश संरचना चिह्नकम्_CHARSETINFO {
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
  } CHARSETINFO,*PCHARSETINFO,*NPCHARSETINFO,*LPCHARSETINFO;

#परिभाषय TCI_SRCCHARSET 1
#परिभाषय TCI_SRCCODEPAGE 2
#परिभाषय TCI_SRCFONTSIG 3
#परिभाषय TCI_SRCLOCALE 0x1000

  प्रकारनिर्देश संरचना चिह्नकम्_LOCALESIGNATURE {
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
  } LOCALESIGNATURE,*PLOCALESIGNATURE,*LPLOCALESIGNATURE;
#यदि_अन्तः


#यदि_अपरिभाषितम् NOMETAFILE
  प्रकारनिर्देश संरचना चिह्नकम्_HANDLETABLE {
    HGDIOBJ objectHandle[1];
  } HANDLETABLE,*PHANDLETABLE,*LPHANDLETABLE;

  प्रकारनिर्देश संरचना चिह्नकम्_METARECORD {
    DWORD rd_आकार;
    WORD rdFunction;
    WORD rdParm[1];
  } METARECORD;
  प्रकारनिर्देश संरचना चिह्नकम्_METARECORD UNALIGNED *PMETARECORD;
  प्रकारनिर्देश संरचना चिह्नकम्_METARECORD UNALIGNED *LPMETARECORD;

  प्रकारनिर्देश संरचना चिह्नकम्_METAFILEPICT {
    LONG mm;
    LONG xExt;
    LONG yExt;
    HMETAFILE hMF;
  } METAFILEPICT,*LPMETAFILEPICT;

#अन्तर्भाव <pshpack2.h>
  प्रकारनिर्देश संरचना चिह्नकम्_METAHEADER {
    WORD mtType;
    WORD mt_शीर्षकम्_आकार;
    WORD mt_संस्करणम्;
    DWORD mt_आकार;
    WORD mtNoObjects;
    DWORD mt_Max_लेखः;
    WORD mtNoParameters;
  } METAHEADER;
  प्रकारनिर्देश संरचना चिह्नकम्_METAHEADER UNALIGNED *PMETAHEADER;
  प्रकारनिर्देश संरचना चिह्नकम्_METAHEADER UNALIGNED *LPMETAHEADER;

#अन्तर्भाव <poppack.h>

  प्रकारनिर्देश संरचना चिह्नकम्_ENHMETARECORD {
    DWORD iType;
    DWORD n_आकार;
    DWORD dParm[1];
  } ENHMETARECORD,*PENHMETARECORD,*LPENHMETARECORD;

  प्रकारनिर्देश संरचना चिह्नकम्_ENHMETAHEADER {
    DWORD iType;
    DWORD n_आकार;
    RECTL rclBounds;
    RECTL rclFrame;
    DWORD dSignature;
    DWORD n_संस्करणम्;
    DWORD n_अष्टकानि;
    DWORD n_लेखाः;
    WORD nHandles;
    WORD sReserved;
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
#यदि_अन्तः

#यदि_अपरिभाषितम् NOTEXTMETRIC
#परिभाषय TMPF_FIXED_PITCH 0x01
#परिभाषय TMPF_सदिशम् 0x02
#परिभाषय TMPF_DEVICE 0x08
#परिभाषय TMPF_TRUETYPE 0x04

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश WCHAR BCHAR;
#अन्यथा
  प्रकारनिर्देश BYTE BCHAR;
#यदि_अन्तः

#यदि_अपरिभाषितम् _TEXTMETRIC_DEFINED
#परिभाषय _TEXTMETRIC_DEFINED
  प्रकारनिर्देश संरचना चिह्नकम्_TEXTMETRICA {
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_आन्तरिकम्_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_विस्तारः;
    LONG tm_Max_Char_विस्तारः;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tmFirstChar;
    BYTE tm_चरमः_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_बहिर्गमनम्;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_समुच्चयः;
  } TEXTMETRICA,*PTEXTMETRICA,*NPTEXTMETRICA,*LPTEXTMETRICA;

  प्रकारनिर्देश संरचना चिह्नकम्_TEXTMETRICW {
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_आन्तरिकम्_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_विस्तारः;
    LONG tm_Max_Char_विस्तारः;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tmFirstChar;
    WCHAR tm_चरमः_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_बहिर्गमनम्;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_समुच्चयः;
  } TEXTMETRICW,*PTEXTMETRICW,*NPTEXTMETRICW,*LPTEXTMETRICW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश TEXTMETRICW TEXTMETRIC;
  प्रकारनिर्देश PTEXTMETRICW PTEXTMETRIC;
  प्रकारनिर्देश NPTEXTMETRICW NPTEXTMETRIC;
  प्रकारनिर्देश LPTEXTMETRICW LPTEXTMETRIC;
#अन्यथा
  प्रकारनिर्देश TEXTMETRICA TEXTMETRIC;
  प्रकारनिर्देश PTEXTMETRICA PTEXTMETRIC;
  प्रकारनिर्देश NPTEXTMETRICA NPTEXTMETRIC;
  प्रकारनिर्देश LPTEXTMETRICA LPTEXTMETRIC;
#यदि_अन्तः
#यदि_अन्तः

#परिभाषय NTM_REGULAR 0x00000040L
#परिभाषय NTM_BOLD 0x00000020L
#परिभाषय NTM_ITALIC 0x00000001L

#परिभाषय NTM_NONNEGATIVE_AC 0x00010000
#परिभाषय NTM_PS_OPENTYPE 0x00020000
#परिभाषय NTM_TT_OPENTYPE 0x00040000
#परिभाषय NTM_MULTIPLEMASTER 0x00080000
#परिभाषय NTM_TYPE1 0x00100000
#परिभाषय NTM_DSIG 0x00200000

#अन्तर्भाव <pshpack4.h>
  प्रकारनिर्देश संरचना चिह्नकम्_NEWTEXTMETRICA {
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_आन्तरिकम्_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_विस्तारः;
    LONG tm_Max_Char_विस्तारः;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tmFirstChar;
    BYTE tm_चरमः_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_बहिर्गमनम्;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_समुच्चयः;
    DWORD ntmFlags;
    UINT ntm_आकार_EM;
    UINT ntmCellHeight;
    UINT ntm_Avg_विस्तारः;
  } NEWTEXTMETRICA,*PNEWTEXTMETRICA,*NPNEWTEXTMETRICA,*LPNEWTEXTMETRICA;

  प्रकारनिर्देश संरचना चिह्नकम्_NEWTEXTMETRICW {
    LONG tmHeight;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_आन्तरिकम्_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_विस्तारः;
    LONG tm_Max_Char_विस्तारः;
    LONG tmWeight;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tmFirstChar;
    WCHAR tm_चरमः_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_बहिर्गमनम्;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_समुच्चयः;
    DWORD ntmFlags;
    UINT ntm_आकार_EM;
    UINT ntmCellHeight;
    UINT ntm_Avg_विस्तारः;
  } NEWTEXTMETRICW,*PNEWTEXTMETRICW,*NPNEWTEXTMETRICW,*LPNEWTEXTMETRICW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश NEWTEXTMETRICW NEWTEXTMETRIC;
  प्रकारनिर्देश PNEWTEXTMETRICW PNEWTEXTMETRIC;
  प्रकारनिर्देश NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
  प्रकारनिर्देश LPNEWTEXTMETRICW LPNEWTEXTMETRIC;
#अन्यथा
  प्रकारनिर्देश NEWTEXTMETRICA NEWTEXTMETRIC;
  प्रकारनिर्देश PNEWTEXTMETRICA PNEWTEXTMETRIC;
  प्रकारनिर्देश NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
  प्रकारनिर्देश LPNEWTEXTMETRICA LPNEWTEXTMETRIC;
#यदि_अन्तः
#अन्तर्भाव <poppack.h>

  प्रकारनिर्देश संरचना चिह्नकम्_NEWTEXTMETRICEXA {
    NEWTEXTMETRICA ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXA;

  प्रकारनिर्देश संरचना चिह्नकम्_NEWTEXTMETRICEXW {
    NEWTEXTMETRICW ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश NEWTEXTMETRICEXW NEWTEXTMETRICEX;
#अन्यथा
  प्रकारनिर्देश NEWTEXTMETRICEXA NEWTEXTMETRICEX;
#यदि_अन्तः
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_PELARRAY {
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
  } PELARRAY,*PPELARRAY,*NPPELARRAY,*LPPELARRAY;

  प्रकारनिर्देश संरचना चिह्नकम्_LOGBRUSH {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
  } LOGBRUSH,*PLOGBRUSH,*NPLOGBRUSH,*LPLOGBRUSH;

  प्रकारनिर्देश संरचना चिह्नकम्_LOGBRUSH32 {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG lbHatch;
  } LOGBRUSH32,*PLOGBRUSH32,*NPLOGBRUSH32,*LPLOGBRUSH32;

  प्रकारनिर्देश LOGBRUSH आदर्शः_2;
  प्रकारनिर्देश आदर्शः_2 *PPATTERN;
  प्रकारनिर्देश आदर्शः_2 *NPPATTERN;
  प्रकारनिर्देश आदर्शः_2 *LPPATTERN;

  प्रकारनिर्देश संरचना चिह्नकम्_LOGPEN {
    UINT lopnStyle;
    POINT lopn_विस्तारः;
    COLORREF lopnColor;
  } LOGPEN,*PLOGPEN,*NPLOGPEN,*LPLOGPEN;

  प्रकारनिर्देश संरचना चिह्नकम्_EXTLOGPEN {
    DWORD elpPenStyle;
    DWORD elp_विस्तारः;
    UINT elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elp_अङ्कः_Entries;
    DWORD elp_Style_प्रविष्टिः[1];
  } EXTLOGPEN,*PEXTLOGPEN,*NPEXTLOGPEN,*LPEXTLOGPEN;

#यदि_अपरिभाषितम् _PALETTEENTRY_DEFINED
#परिभाषय _PALETTEENTRY_DEFINED
  प्रकारनिर्देश संरचना चिह्नकम्_PALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
  } PALETTEENTRY,*PPALETTEENTRY,*LPPALETTEENTRY;
#यदि_अन्तः

#यदि_अपरिभाषितम् _LOGPALETTE_DEFINED
#परिभाषय _LOGPALETTE_DEFINED

  प्रकारनिर्देश संरचना चिह्नकम्_LOGPALETTE {
    WORD pal_संस्करणम्;
    WORD pal_अङ्कः_Entries;
    PALETTEENTRY pal_Pal_प्रविष्टिः[1];
  } LOGPALETTE,*PLOGPALETTE,*NPLOGPALETTE,*LPLOGPALETTE;
#यदि_अन्तः

#परिभाषय LF_FACESIZE 32

  प्रकारनिर्देश संरचना चिह्नकम्_LOGFONTA {
    LONG lfHeight;
    LONG lf_विस्तारः;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_बहिर्गमनम्;
    BYTE lf_Char_समुच्चयः;
    BYTE lf_बहिर्गमनम्_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[LF_FACESIZE];
  } LOGFONTA,*PLOGFONTA,*NPLOGFONTA,*LPLOGFONTA;

  प्रकारनिर्देश संरचना चिह्नकम्_LOGFONTW {
    LONG lfHeight;
    LONG lf_विस्तारः;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lfWeight;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_बहिर्गमनम्;
    BYTE lf_Char_समुच्चयः;
    BYTE lf_बहिर्गमनम्_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[LF_FACESIZE];
  } LOGFONTW,*PLOGFONTW,*NPLOGFONTW,*LPLOGFONTW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश LOGFONTW LOGFONT;
  प्रकारनिर्देश PLOGFONTW PLOGFONT;
  प्रकारनिर्देश NPLOGFONTW NPLOGFONT;
  प्रकारनिर्देश LPLOGFONTW LPLOGFONT;
#अन्यथा
  प्रकारनिर्देश LOGFONTA LOGFONT;
  प्रकारनिर्देश PLOGFONTA PLOGFONT;
  प्रकारनिर्देश NPLOGFONTA NPLOGFONT;
  प्रकारनिर्देश LPLOGFONTA LPLOGFONT;
#यदि_अन्तः

#परिभाषय LF_FULLFACESIZE 64

  प्रकारनिर्देश संरचना चिह्नकम्_ENUMLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_पूर्णम्_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
  } ENUMLOGFONTA,*LPENUMLOGFONTA;

  प्रकारनिर्देश संरचना चिह्नकम्_ENUMLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_पूर्णम्_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
  } ENUMLOGFONTW,*LPENUMLOGFONTW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश ENUMLOGFONTW ENUMLOGFONT;
  प्रकारनिर्देश LPENUMLOGFONTW LPENUMLOGFONT;
#अन्यथा
  प्रकारनिर्देश ENUMLOGFONTA ENUMLOGFONT;
  प्रकारनिर्देश LPENUMLOGFONTA LPENUMLOGFONT;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_ENUMLOGFONTEXA {
    LOGFONTA elfLogFont;
    BYTE elf_पूर्णम्_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    BYTE elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXA,*LPENUMLOGFONTEXA;

  प्रकारनिर्देश संरचना चिह्नकम्_ENUMLOGFONTEXW {
    LOGFONTW elfLogFont;
    WCHAR elf_पूर्णम्_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    WCHAR elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXW,*LPENUMLOGFONTEXW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश ENUMLOGFONTEXW ENUMLOGFONTEX;
  प्रकारनिर्देश LPENUMLOGFONTEXW LPENUMLOGFONTEX;
#अन्यथा
  प्रकारनिर्देश ENUMLOGFONTEXA ENUMLOGFONTEX;
  प्रकारनिर्देश LPENUMLOGFONTEXA LPENUMLOGFONTEX;
#यदि_अन्तः

#परिभाषय बहिर्गमनम्_DEFAULT_PRECIS 0
#परिभाषय बहिर्गमनम्_STRING_PRECIS 1
#परिभाषय बहिर्गमनम्_CHARACTER_PRECIS 2
#परिभाषय बहिर्गमनम्_STROKE_PRECIS 3
#परिभाषय बहिर्गमनम्_TT_PRECIS 4
#परिभाषय बहिर्गमनम्_DEVICE_PRECIS 5
#परिभाषय बहिर्गमनम्_RASTER_PRECIS 6
#परिभाषय बहिर्गमनम्_TT_ONLY_PRECIS 7
#परिभाषय बहिर्गमनम्_OUTLINE_PRECIS 8
#परिभाषय बहिर्गमनम्_SCREEN_OUTLINE_PRECIS 9
#परिभाषय बहिर्गमनम्_PS_ONLY_PRECIS 10

#परिभाषय CLIP_DEFAULT_PRECIS 0
#परिभाषय CLIP_CHARACTER_PRECIS 1
#परिभाषय CLIP_STROKE_PRECIS 2
#परिभाषय CLIP_आवरणम् 0xf
#परिभाषय CLIP_LH_ANGLES (1<<4)
#परिभाषय CLIP_TT_ALWAYS (2<<4)
#परिभाषय CLIP_DFA_DISABLE (4<<4)
#परिभाषय CLIP_EMBEDDED (8<<4)

#परिभाषय DEFAULT_QUALITY 0
#परिभाषय DRAFT_QUALITY 1
#परिभाषय PROOF_QUALITY 2
#परिभाषय NONANTIALIASED_QUALITY 3
#परिभाषय ANTIALIASED_QUALITY 4

#परिभाषय CLEARTYPE_QUALITY 5
#परिभाषय CLEARTYPE_NATURAL_QUALITY 6

#परिभाषय DEFAULT_PITCH 0
#परिभाषय FIXED_PITCH 1
#परिभाषय VARIABLE_PITCH 2
#परिभाषय MONO_FONT 8

#परिभाषय ANSI_CHARSET 0
#परिभाषय DEFAULT_CHARSET 1
#परिभाषय चिह्नम्_CHARSET 2
#परिभाषय SHIFTJIS_CHARSET 128
#परिभाषय HANGEUL_CHARSET 129
#परिभाषय HANGUL_CHARSET 129
#परिभाषय GB2312_CHARSET 134
#परिभाषय CHINESEBIG5_CHARSET 136
#परिभाषय OEM_CHARSET 255
#परिभाषय JOHAB_CHARSET 130
#परिभाषय HEBREW_CHARSET 177
#परिभाषय ARABIC_CHARSET 178
#परिभाषय GREEK_CHARSET 161
#परिभाषय TURKISH_CHARSET 162
#परिभाषय VIETNAMESE_CHARSET 163
#परिभाषय THAI_CHARSET 222
#परिभाषय EASTEUROPE_CHARSET 238
#परिभाषय RUSSIAN_CHARSET 204

#परिभाषय MAC_CHARSET 77
#परिभाषय BALTIC_CHARSET 186

#परिभाषय FS_LATIN1 0x00000001L
#परिभाषय FS_LATIN2 0x00000002L
#परिभाषय FS_CYRILLIC 0x00000004L
#परिभाषय FS_GREEK 0x00000008L
#परिभाषय FS_TURKISH 0x00000010L
#परिभाषय FS_HEBREW 0x00000020L
#परिभाषय FS_ARABIC 0x00000040L
#परिभाषय FS_BALTIC 0x00000080L
#परिभाषय FS_VIETNAMESE 0x00000100L
#परिभाषय FS_THAI 0x00010000L
#परिभाषय FS_JISJAPAN 0x00020000L
#परिभाषय FS_CHINESESIMP 0x00040000L
#परिभाषय FS_WANSUNG 0x00080000L
#परिभाषय FS_CHINESETRAD 0x00100000L
#परिभाषय FS_JOHAB 0x00200000L
#परिभाषय FS_चिह्नम् 0x80000000L

#परिभाषय FF_DONTCARE (0<<4)
#परिभाषय FF_ROMAN (1<<4)

#परिभाषय FF_SWISS (2<<4)

#परिभाषय FF_MODERN (3<<4)

#परिभाषय FF_SCRIPT (4<<4)
#परिभाषय FF_DECORATIVE (5<<4)

#परिभाषय FW_DONTCARE 0
#परिभाषय FW_THIN 100
#परिभाषय FW_EXTRALIGHT 200
#परिभाषय FW_LIGHT 300
#परिभाषय FW_प्रसामान्यम् 400
#परिभाषय FW_MEDIUM 500
#परिभाषय FW_SEMIBOLD 600
#परिभाषय FW_BOLD 700
#परिभाषय FW_EXTRABOLD 800
#परिभाषय FW_HEAVY 900

#परिभाषय FW_ULTRALIGHT FW_EXTRALIGHT
#परिभाषय FW_REGULAR FW_प्रसामान्यम्
#परिभाषय FW_DEMIBOLD FW_SEMIBOLD
#परिभाषय FW_ULTRABOLD FW_EXTRABOLD
#परिभाषय FW_BLACK FW_HEAVY

#परिभाषय PANOSE_गणनम् 10
#परिभाषय PAN_FAMILYTYPE_सूचकांक 0
#परिभाषय PAN_SERIFSTYLE_सूचकांक 1
#परिभाषय PAN_WEIGHT_सूचकांक 2
#परिभाषय PAN_PROPORTION_सूचकांक 3
#परिभाषय PAN_CONTRAST_सूचकांक 4
#परिभाषय PAN_STROKEVARIATION_सूचकांक 5
#परिभाषय PAN_ARMSTYLE_सूचकांक 6
#परिभाषय PAN_LETTERFORM_सूचकांक 7
#परिभाषय PAN_MIDLINE_सूचकांक 8
#परिभाषय PAN_XHEIGHT_सूचकांक 9

#परिभाषय PAN_CULTURE_LATIN 0

  प्रकारनिर्देश संरचना चिह्नकम्_PANOSE {
    BYTE bFamilyType;
    BYTE bSerifStyle;
    BYTE bWeight;
    BYTE bProportion;
    BYTE bContrast;
    BYTE bStrokeVariation;
    BYTE bArmStyle;
    BYTE bLetterform;
    BYTE bMidline;
    BYTE bXHeight;
  } PANOSE,*LPPANOSE;

#परिभाषय PAN_ANY 0
#परिभाषय PAN_NO_FIT 1

#परिभाषय PAN_FAMILY_TEXT_DISPLAY 2
#परिभाषय PAN_FAMILY_SCRIPT 3
#परिभाषय PAN_FAMILY_DECORATIVE 4
#परिभाषय PAN_FAMILY_PICTORIAL 5

#परिभाषय PAN_SERIF_COVE 2
#परिभाषय PAN_SERIF_OBTUSE_COVE 3
#परिभाषय PAN_SERIF_वर्गफलम्_COVE 4
#परिभाषय PAN_SERIF_OBTUSE_वर्गफलम्_COVE 5
#परिभाषय PAN_SERIF_वर्गफलम् 6
#परिभाषय PAN_SERIF_THIN 7
#परिभाषय PAN_SERIF_BONE 8
#परिभाषय PAN_SERIF_EXAGGERATED 9
#परिभाषय PAN_SERIF_TRIANGLE 10
#परिभाषय PAN_SERIF_प्रसामान्यम्_SANS 11
#परिभाषय PAN_SERIF_OBTUSE_SANS 12
#परिभाषय PAN_SERIF_PERP_SANS 13
#परिभाषय PAN_SERIF_FLARED 14
#परिभाषय PAN_SERIF_ROUNDED 15

#परिभाषय PAN_WEIGHT_VERY_LIGHT 2
#परिभाषय PAN_WEIGHT_LIGHT 3
#परिभाषय PAN_WEIGHT_THIN 4
#परिभाषय PAN_WEIGHT_BOOK 5
#परिभाषय PAN_WEIGHT_MEDIUM 6
#परिभाषय PAN_WEIGHT_DEMI 7
#परिभाषय PAN_WEIGHT_BOLD 8
#परिभाषय PAN_WEIGHT_HEAVY 9
#परिभाषय PAN_WEIGHT_BLACK 10
#परिभाषय PAN_WEIGHT_NORD 11

#परिभाषय PAN_PROP_OLD_STYLE 2
#परिभाषय PAN_PROP_MODERN 3
#परिभाषय PAN_PROP_EVEN_विस्तारः 4
#परिभाषय PAN_PROP_EXPANDED 5
#परिभाषय PAN_PROP_CONDENSED 6
#परिभाषय PAN_PROP_VERY_EXPANDED 7
#परिभाषय PAN_PROP_VERY_CONDENSED 8
#परिभाषय PAN_PROP_MONOSPACED 9

#परिभाषय PAN_CONTRAST_NONE 2
#परिभाषय PAN_CONTRAST_VERY_नीचः 3
#परिभाषय PAN_CONTRAST_नीचः 4
#परिभाषय PAN_CONTRAST_MEDIUM_नीचः 5
#परिभाषय PAN_CONTRAST_MEDIUM 6
#परिभाषय PAN_CONTRAST_MEDIUM_उच्चः 7
#परिभाषय PAN_CONTRAST_उच्चः 8
#परिभाषय PAN_CONTRAST_VERY_उच्चः 9

#परिभाषय PAN_STROKE_GRADUAL_DIAG 2
#परिभाषय PAN_STROKE_GRADUAL_TRAN 3
#परिभाषय PAN_STROKE_GRADUAL_VERT 4
#परिभाषय PAN_STROKE_GRADUAL_HORZ 5
#परिभाषय PAN_STROKE_RAPID_VERT 6
#परिभाषय PAN_STROKE_RAPID_HORZ 7
#परिभाषय PAN_STROKE_INSTANT_VERT 8

#परिभाषय PAN_STRAIGHT_ARMS_HORZ 2
#परिभाषय PAN_STRAIGHT_ARMS_WEDGE 3
#परिभाषय PAN_STRAIGHT_ARMS_VERT 4
#परिभाषय PAN_STRAIGHT_ARMS_SINGLE_SERIF 5
#परिभाषय PAN_STRAIGHT_ARMS_DOUBLE_SERIF 6
#परिभाषय PAN_BENT_ARMS_HORZ 7
#परिभाषय PAN_BENT_ARMS_WEDGE 8
#परिभाषय PAN_BENT_ARMS_VERT 9
#परिभाषय PAN_BENT_ARMS_SINGLE_SERIF 10
#परिभाषय PAN_BENT_ARMS_DOUBLE_SERIF 11

#परिभाषय PAN_LETT_प्रसामान्यम्_CONTACT 2
#परिभाषय PAN_LETT_प्रसामान्यम्_WEIGHTED 3
#परिभाषय PAN_LETT_प्रसामान्यम्_BOXED 4
#परिभाषय PAN_LETT_प्रसामान्यम्_FLATTENED 5
#परिभाषय PAN_LETT_प्रसामान्यम्_ROUNDED 6
#परिभाषय PAN_LETT_प्रसामान्यम्_OFF_CENTER 7
#परिभाषय PAN_LETT_प्रसामान्यम्_वर्गफलम् 8
#परिभाषय PAN_LETT_OBLIQUE_CONTACT 9
#परिभाषय PAN_LETT_OBLIQUE_WEIGHTED 10
#परिभाषय PAN_LETT_OBLIQUE_BOXED 11
#परिभाषय PAN_LETT_OBLIQUE_FLATTENED 12
#परिभाषय PAN_LETT_OBLIQUE_ROUNDED 13
#परिभाषय PAN_LETT_OBLIQUE_OFF_CENTER 14
#परिभाषय PAN_LETT_OBLIQUE_वर्गफलम् 15

#परिभाषय PAN_MIDLINE_STANDARD_TRIMMED 2
#परिभाषय PAN_MIDLINE_STANDARD_POINTED 3
#परिभाषय PAN_MIDLINE_STANDARD_SERIFED 4
#परिभाषय PAN_MIDLINE_उच्चः_TRIMMED 5
#परिभाषय PAN_MIDLINE_उच्चः_POINTED 6
#परिभाषय PAN_MIDLINE_उच्चः_SERIFED 7
#परिभाषय PAN_MIDLINE_CONSTANT_TRIMMED 8
#परिभाषय PAN_MIDLINE_CONSTANT_POINTED 9
#परिभाषय PAN_MIDLINE_CONSTANT_SERIFED 10
#परिभाषय PAN_MIDLINE_नीचः_TRIMMED 11
#परिभाषय PAN_MIDLINE_नीचः_POINTED 12
#परिभाषय PAN_MIDLINE_नीचः_SERIFED 13

#परिभाषय PAN_XHEIGHT_CONSTANT_SMALL 2
#परिभाषय PAN_XHEIGHT_CONSTANT_STD 3
#परिभाषय PAN_XHEIGHT_CONSTANT_LARGE 4
#परिभाषय PAN_XHEIGHT_DUCKING_SMALL 5
#परिभाषय PAN_XHEIGHT_DUCKING_STD 6
#परिभाषय PAN_XHEIGHT_DUCKING_LARGE 7

#परिभाषय ELF_VENDOR_आकार 4

  प्रकारनिर्देश संरचना चिह्नकम्_EXTLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_पूर्णम्_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    DWORD elf_संस्करणम्;
    DWORD elf_Style_आकार;
    DWORD elf_मेलनम्;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_आकार];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTA,*PEXTLOGFONTA,*NPEXTLOGFONTA,*LPEXTLOGFONTA;

  प्रकारनिर्देश संरचना चिह्नकम्_EXTLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_पूर्णम्_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    DWORD elf_संस्करणम्;
    DWORD elf_Style_आकार;
    DWORD elf_मेलनम्;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_आकार];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTW,*PEXTLOGFONTW,*NPEXTLOGFONTW,*LPEXTLOGFONTW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश EXTLOGFONTW EXTLOGFONT;
  प्रकारनिर्देश PEXTLOGFONTW PEXTLOGFONT;
  प्रकारनिर्देश NPEXTLOGFONTW NPEXTLOGFONT;
  प्रकारनिर्देश LPEXTLOGFONTW LPEXTLOGFONT;
#अन्यथा
  प्रकारनिर्देश EXTLOGFONTA EXTLOGFONT;
  प्रकारनिर्देश PEXTLOGFONTA PEXTLOGFONT;
  प्रकारनिर्देश NPEXTLOGFONTA NPEXTLOGFONT;
  प्रकारनिर्देश LPEXTLOGFONTA LPEXTLOGFONT;
#यदि_अन्तः

#परिभाषय ELF_संस्करणम् 0
#परिभाषय ELF_CULTURE_LATIN 0

#परिभाषय RASTER_FONTTYPE 0x0001
#परिभाषय DEVICE_FONTTYPE 0x002
#परिभाषय TRUETYPE_FONTTYPE 0x004

#परिभाषय RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#परिभाषय PALETTERGB(r,g,b) (0x02000000 | RGB(r,g,b))
#परिभाषय PALETTEINDEX(i) ((COLORREF)(0x01000000 | (DWORD)(WORD)(i)))

#परिभाषय PC_RESERVED 0x01
#परिभाषय PC_EXPLICIT 0x02
#परिभाषय PC_NOCOLLAPSE 0x04

#परिभाषय GetRValue(rgb) (LOBYTE(rgb))
#परिभाषय GetGValue(rgb) (LOBYTE(((WORD)(rgb)) >> 8))
#परिभाषय GetBValue(rgb) (LOBYTE((rgb)>>16))

#परिभाषय TRANSPARENT 1
#परिभाषय OPAQUE 2
#परिभाषय BKMODE_चरमः 2

#परिभाषय GM_COMPATIBLE 1
#परिभाषय GM_ADVANCED 2
#परिभाषय GM_चरमः 2

#परिभाषय PT_CLOSEFIGURE 0x01
#परिभाषय PT_LINETO 0x02
#परिभाषय PT_BEZIERTO 0x04
#परिभाषय PT_MOVETO 0x06

#परिभाषय MM_TEXT 1
#परिभाषय MM_LOMETRIC 2
#परिभाषय MM_HIMETRIC 3
#परिभाषय MM_LOENGLISH 4
#परिभाषय MM_HIENGLISH 5
#परिभाषय MM_TWIPS 6
#परिभाषय MM_ISOTROPIC 7
#परिभाषय MM_ANISOTROPIC 8

#परिभाषय MM_MIN MM_TEXT
#परिभाषय MM_MAX MM_ANISOTROPIC
#परिभाषय MM_MAX_FIXEDSCALE MM_TWIPS

#परिभाषय ABSOLUTE 1
#परिभाषय RELATIVE 2

#परिभाषय WHITE_BRUSH 0
#परिभाषय LTGRAY_BRUSH 1
#परिभाषय GRAY_BRUSH 2
#परिभाषय DKGRAY_BRUSH 3
#परिभाषय BLACK_BRUSH 4
#परिभाषय NULL_BRUSH 5
#परिभाषय HOLLOW_BRUSH NULL_BRUSH
#परिभाषय WHITE_PEN 6
#परिभाषय BLACK_PEN 7
#परिभाषय NULL_PEN 8
#परिभाषय OEM_FIXED_FONT 10
#परिभाषय ANSI_FIXED_FONT 11
#परिभाषय ANSI_VAR_FONT 12
#परिभाषय SYSTEM_FONT 13
#परिभाषय DEVICE_DEFAULT_FONT 14
#परिभाषय DEFAULT_PALETTE 15
#परिभाषय SYSTEM_FIXED_FONT 16

#परिभाषय DEFAULT_GUI_FONT 17

#परिभाषय DC_BRUSH 18
#परिभाषय DC_PEN 19

#परिभाषय STOCK_चरमः 19

#परिभाषय CLR_INVALID 0xFFFFFFFF

#परिभाषय BS_SOLID 0
#परिभाषय BS_NULL 1
#परिभाषय BS_HOLLOW BS_NULL
#परिभाषय BS_HATCHED 2
#परिभाषय BS_आदर्शः 3
#परिभाषय BS_अनुक्रमितम् 4
#परिभाषय BS_DIBPATTERN 5
#परिभाषय BS_DIBPATTERNPT 6
#परिभाषय BS_PATTERN8X8 7
#परिभाषय BS_DIBPATTERN8X8 8
#परिभाषय BS_MONOPATTERN 9

#परिभाषय HS_HORIZONTAL 0
#परिभाषय HS_VERTICAL 1
#परिभाषय HS_FDIAGONAL 2
#परिभाषय HS_BDIAGONAL 3
#परिभाषय HS_CROSS 4
#परिभाषय HS_DIAGCROSS 5

#परिभाषय PS_SOLID 0
#परिभाषय PS_DASH 1
#परिभाषय PS_DOT 2
#परिभाषय PS_DASHDOT 3
#परिभाषय PS_DASHDOTDOT 4
#परिभाषय PS_NULL 5
#परिभाषय PS_INSIDEFRAME 6
#परिभाषय PS_USERSTYLE 7
#परिभाषय PS_ALTERNATE 8
#परिभाषय PS_STYLE_आवरणम् 0x0000000F

#परिभाषय PS_ENDCAP_आवर्तनम् 0x00000000
#परिभाषय PS_ENDCAP_वर्गफलम् 0x00000100
#परिभाषय PS_ENDCAP_FLAT 0x00000200
#परिभाषय PS_ENDCAP_आवरणम् 0x00000F00

#परिभाषय PS_JOIN_आवर्तनम् 0x00000000
#परिभाषय PS_JOIN_BEVEL 0x00001000
#परिभाषय PS_JOIN_MITER 0x00002000
#परिभाषय PS_JOIN_आवरणम् 0x0000F000

#परिभाषय PS_COSMETIC 0x00000000
#परिभाषय PS_GEOMETRIC 0x00010000
#परिभाषय PS_TYPE_आवरणम् 0x000F0000

#परिभाषय AD_COUNTERCLOCKWISE 1
#परिभाषय AD_CLOCKWISE 2

#परिभाषय DRIVERVERSION 0
#परिभाषय TECHNOLOGY 2
#परिभाषय HORZSIZE 4
#परिभाषय VERTSIZE 6
#परिभाषय HORZRES 8
#परिभाषय VERTRES 10
#परिभाषय BITSPIXEL 12
#परिभाषय PLANES 14
#परिभाषय NUMBRUSHES 16
#परिभाषय NUMPENS 18
#परिभाषय NUMMARKERS 20
#परिभाषय NUMFONTS 22
#परिभाषय NUMCOLORS 24
#परिभाषय PDEVICESIZE 26
#परिभाषय CURVECAPS 28
#परिभाषय LINECAPS 30
#परिभाषय POLYGONALCAPS 32
#परिभाषय TEXTCAPS 34
#परिभाषय CLIPCAPS 36
#परिभाषय RASTERCAPS 38
#परिभाषय ASPECTX 40
#परिभाषय ASPECTY 42
#परिभाषय ASPECTXY 44

#परिभाषय LOGPIXELSX 88
#परिभाषय LOGPIXELSY 90

#परिभाषय SIZEPALETTE 104
#परिभाषय NUMRESERVED 106
#परिभाषय COLORRES 108

#परिभाषय PHYSICALWIDTH 110
#परिभाषय PHYSICALHEIGHT 111
#परिभाषय PHYSICALOFFSETX 112
#परिभाषय PHYSICALOFFSETY 113
#परिभाषय SCALINGFACTORX 114
#परिभाषय SCALINGFACTORY 115

#परिभाषय VREFRESH 116

#परिभाषय DESKTOPVERTRES 117

#परिभाषय DESKTOPHORZRES 118

#परिभाषय BLTALIGNMENT 119

#परिभाषय SHADEBLENDCAPS 120
#परिभाषय COLORMGMTCAPS 121

#यदि_अपरिभाषितम् NOGDICAPMASKS
#परिभाषय DT_PLOTTER 0
#परिभाषय DT_RASDISPLAY 1
#परिभाषय DT_RASPRINTER 2
#परिभाषय DT_RASCAMERA 3
#परिभाषय DT_CHARSTREAM 4
#परिभाषय DT_METAFILE 5
#परिभाषय DT_DISPFILE 6

#परिभाषय CC_NONE 0
#परिभाषय CC_CIRCLES 1
#परिभाषय CC_PIE 2
#परिभाषय CC_CHORD 4
#परिभाषय CC_ELLIPSES 8
#परिभाषय CC_WIDE 16
#परिभाषय CC_STYLED 32
#परिभाषय CC_WIDESTYLED 64
#परिभाषय CC_INTERIORS 128
#परिभाषय CC_ROUNDRECT 256

#परिभाषय LC_NONE 0
#परिभाषय LC_POLYLINE 2
#परिभाषय LC_MARKER 4
#परिभाषय LC_POLYMARKER 8
#परिभाषय LC_WIDE 16
#परिभाषय LC_STYLED 32
#परिभाषय LC_WIDESTYLED 64
#परिभाषय LC_INTERIORS 128

#परिभाषय PC_NONE 0
#परिभाषय PC_POLYGON 1
#परिभाषय PC_RECTANGLE 2
#परिभाषय PC_WINDPOLYGON 4
#परिभाषय PC_TRAPEZOID 4
#परिभाषय PC_SCANLINE 8
#परिभाषय PC_WIDE 16
#परिभाषय PC_STYLED 32
#परिभाषय PC_WIDESTYLED 64
#परिभाषय PC_INTERIORS 128
#परिभाषय PC_POLYPOLYGON 256
#परिभाषय PC_PATHS 512

#परिभाषय CP_NONE 0
#परिभाषय CP_RECTANGLE 1
#परिभाषय CP_REGION 2

#परिभाषय TC_OP_CHARACTER 0x00000001
#परिभाषय TC_OP_STROKE 0x00000002
#परिभाषय TC_CP_STROKE 0x00000004
#परिभाषय TC_CR_90 0x00000008
#परिभाषय TC_CR_ANY 0x00000010
#परिभाषय TC_SF_X_YINDEP 0x00000020
#परिभाषय TC_SA_DOUBLE 0x00000040
#परिभाषय TC_SA_INTEGER 0x00000080
#परिभाषय TC_SA_CONTIN 0x00000100
#परिभाषय TC_EA_DOUBLE 0x00000200
#परिभाषय TC_IA_ABLE 0x00000400
#परिभाषय TC_UA_ABLE 0x00000800
#परिभाषय TC_SO_ABLE 0x00001000
#परिभाषय TC_RA_ABLE 0x00002000
#परिभाषय TC_VA_ABLE 0x00004000
#परिभाषय TC_RESERVED 0x00008000
#परिभाषय TC_SCROLLBLT 0x00010000
#यदि_अन्तः

#परिभाषय RC_NONE
#परिभाषय RC_BITBLT 1
#परिभाषय RC_BANDING 2
#परिभाषय RC_SCALING 4
#परिभाषय RC_BITMAP64 8
#परिभाषय RC_GDI20_OUTPUT 0x0010
#परिभाषय RC_GDI20_STATE 0x0020
#परिभाषय RC_SAVEBITMAP 0x0040
#परिभाषय RC_DI_BITMAP 0x0080
#परिभाषय RC_PALETTE 0x0100
#परिभाषय RC_DIBTODEV 0x0200
#परिभाषय RC_BIGFONT 0x0400
#परिभाषय RC_STRETCHBLT 0x0800
#परिभाषय RC_FLOODFILL 0x1000
#परिभाषय RC_STRETCHDIB 0x2000
#परिभाषय RC_OP_DX_OUTPUT 0x4000
#परिभाषय RC_DEVBITS 0x8000

#परिभाषय SB_NONE 0x00000000
#परिभाषय SB_CONST_ALPHA 0x00000001
#परिभाषय SB_PIXEL_ALPHA 0x00000002
#परिभाषय SB_PREMULT_ALPHA 0x00000004

#परिभाषय SB_GRAD_RECT 0x00000010
#परिभाषय SB_GRAD_TRI 0x00000020

#परिभाषय CM_NONE 0x00000000
#परिभाषय CM_DEVICE_ICM 0x00000001
#परिभाषय CM_GAMMA_RAMP 0x00000002
#परिभाषय CM_CMYK_COLOR 0x00000004

#परिभाषय DIB_RGB_COLORS 0
#परिभाषय DIB_PAL_COLORS 1

#परिभाषय SYSPAL_ERROR 0
#परिभाषय SYSPAL_STATIC 1
#परिभाषय SYSPAL_NOSTATIC 2
#परिभाषय SYSPAL_NOSTATIC256 3

#परिभाषय CBM_INIT 0x04L

#परिभाषय FLOODFILLBORDER 0
#परिभाषय FLOODFILLSURFACE 1

#परिभाषय CCHDEVICENAME 32

#परिभाषय CCHFORMNAME 32

  प्रकारनिर्देश संरचना _devicemodeA {
    BYTE dmDeviceName[CCHDEVICENAME];
    WORD dm_Spec_संस्करणम्;
    WORD dm_Driver_संस्करणम्;
    WORD dm_आकार;
    WORD dmDriverExtra;
    DWORD dmFields;
    सङ्घ {
      संरचना {
        ह्रस्व dmOrientation;
        ह्रस्व dm_Paper_आकार;
        ह्रस्व dm_Paper_दीर्घता;
        ह्रस्व dm_Paper_विस्तारः;
        ह्रस्व dmScale;
        ह्रस्व dmCopies;
        ह्रस्व dmDefaultSource;
        ह्रस्व dmPrintQuality;
      };
      संरचना {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    ह्रस्व dmColor;
    ह्रस्व dmDuplex;
    ह्रस्व dmYResolution;
    ह्रस्व dmTTOption;
    ह्रस्व dmCollate;
    BYTE dmFormName[CCHFORMNAME];
    WORD dmLogPixels;
    DWORD dm_द्वयङ्काः_प्रत्येकम्_Pel;
    DWORD dm_Pels_विस्तारः;
    DWORD dmPelsHeight;
    सङ्घ {
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
    DWORD dm_Panning_विस्तारः;
    DWORD dmPanningHeight;
  } DEVMODEA,*PDEVMODEA,*NPDEVMODEA,*LPDEVMODEA;

  प्रकारनिर्देश संरचना _devicemodeW {
    WCHAR dmDeviceName[CCHDEVICENAME];
    WORD dm_Spec_संस्करणम्;
    WORD dm_Driver_संस्करणम्;
    WORD dm_आकार;
    WORD dmDriverExtra;
    DWORD dmFields;
    सङ्घ {
      संरचना {
        ह्रस्व dmOrientation;
        ह्रस्व dm_Paper_आकार;
        ह्रस्व dm_Paper_दीर्घता;
        ह्रस्व dm_Paper_विस्तारः;
        ह्रस्व dmScale;
        ह्रस्व dmCopies;
        ह्रस्व dmDefaultSource;
        ह्रस्व dmPrintQuality;
      };
      संरचना {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    ह्रस्व dmColor;
    ह्रस्व dmDuplex;
    ह्रस्व dmYResolution;
    ह्रस्व dmTTOption;
    ह्रस्व dmCollate;
    WCHAR dmFormName[CCHFORMNAME];
    WORD dmLogPixels;
    DWORD dm_द्वयङ्काः_प्रत्येकम्_Pel;
    DWORD dm_Pels_विस्तारः;
    DWORD dmPelsHeight;
    सङ्घ {
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
    DWORD dm_Panning_विस्तारः;
    DWORD dmPanningHeight;
  } DEVMODEW,*PDEVMODEW,*NPDEVMODEW,*LPDEVMODEW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश DEVMODEW DEVMODE;
  प्रकारनिर्देश PDEVMODEW PDEVMODE;
  प्रकारनिर्देश NPDEVMODEW NPDEVMODE;
  प्रकारनिर्देश LPDEVMODEW LPDEVMODE;
#अन्यथा
  प्रकारनिर्देश DEVMODEA DEVMODE;
  प्रकारनिर्देश PDEVMODEA PDEVMODE;
  प्रकारनिर्देश NPDEVMODEA NPDEVMODE;
  प्रकारनिर्देश LPDEVMODEA LPDEVMODE;
#यदि_अन्तः

#परिभाषय DM_SPECVERSION 0x0401

#परिभाषय DM_ORIENTATION 0x00000001L
#परिभाषय DM_PAPERSIZE 0x00000002L
#परिभाषय DM_PAPERLENGTH 0x00000004L
#परिभाषय DM_PAPERWIDTH 0x00000008L
#परिभाषय DM_SCALE 0x00000010L
#परिभाषय DM_POSITION 0x00000020L
#परिभाषय DM_NUP 0x00000040L
#परिभाषय DM_DISPLAYORIENTATION 0x00000080L
#परिभाषय DM_COPIES 0x00000100L
#परिभाषय DM_DEFAULTSOURCE 0x00000200L
#परिभाषय DM_PRINTQUALITY 0x00000400L
#परिभाषय DM_COLOR 0x00000800L
#परिभाषय DM_DUPLEX 0x00001000L
#परिभाषय DM_YRESOLUTION 0x00002000L
#परिभाषय DM_TTOPTION 0x00004000L
#परिभाषय DM_COLLATE 0x00008000L
#परिभाषय DM_FORMNAME 0x00010000L
#परिभाषय DM_LOGPIXELS 0x00020000L
#परिभाषय DM_BITSPERPEL 0x00040000L
#परिभाषय DM_PELSWIDTH 0x00080000L
#परिभाषय DM_PELSHEIGHT 0x00100000L
#परिभाषय DM_DISPLAYFLAGS 0x00200000L
#परिभाषय DM_DISPLAYFREQUENCY 0x00400000L
#परिभाषय DM_ICMMETHOD 0x00800000L
#परिभाषय DM_ICMINTENT 0x01000000L
#परिभाषय DM_MEDIATYPE 0x02000000L
#परिभाषय DM_DITHERTYPE 0x04000000L
#परिभाषय DM_PANNINGWIDTH 0x08000000L
#परिभाषय DM_PANNINGHEIGHT 0x10000000L
#परिभाषय DM_DISPLAYFIXEDOUTPUT 0x20000000L

#परिभाषय DMORIENT_PORTRAIT 1
#परिभाषय DMORIENT_LANDSCAPE 2

#परिभाषय DMPAPER_FIRST DMPAPER_LETTER
#परिभाषय DMPAPER_LETTER 1
#परिभाषय DMPAPER_LETTERSMALL 2
#परिभाषय DMPAPER_TABLOID 3
#परिभाषय DMPAPER_LEDGER 4
#परिभाषय DMPAPER_LEGAL 5
#परिभाषय DMPAPER_STATEMENT 6
#परिभाषय DMPAPER_EXECUTIVE 7
#परिभाषय DMPAPER_A3 8
#परिभाषय DMPAPER_A4 9
#परिभाषय DMPAPER_A4SMALL 10
#परिभाषय DMPAPER_A5 11
#परिभाषय DMPAPER_B4 12
#परिभाषय DMPAPER_B5 13
#परिभाषय DMPAPER_FOLIO 14
#परिभाषय DMPAPER_QUARTO 15
#परिभाषय DMPAPER_10X14 16
#परिभाषय DMPAPER_11X17 17
#परिभाषय DMPAPER_NOTE 18
#परिभाषय DMPAPER_ENV_9 19
#परिभाषय DMPAPER_ENV_10 20
#परिभाषय DMPAPER_ENV_11 21
#परिभाषय DMPAPER_ENV_12 22
#परिभाषय DMPAPER_ENV_14 23
#परिभाषय DMPAPER_CSHEET 24
#परिभाषय DMPAPER_DSHEET 25
#परिभाषय DMPAPER_ESHEET 26
#परिभाषय DMPAPER_ENV_DL 27
#परिभाषय DMPAPER_ENV_C5 28
#परिभाषय DMPAPER_ENV_C3 29
#परिभाषय DMPAPER_ENV_C4 30
#परिभाषय DMPAPER_ENV_C6 31
#परिभाषय DMPAPER_ENV_C65 32
#परिभाषय DMPAPER_ENV_B4 33
#परिभाषय DMPAPER_ENV_B5 34
#परिभाषय DMPAPER_ENV_B6 35
#परिभाषय DMPAPER_ENV_ITALY 36
#परिभाषय DMPAPER_ENV_MONARCH 37
#परिभाषय DMPAPER_ENV_PERSONAL 38
#परिभाषय DMPAPER_FANFOLD_US 39
#परिभाषय DMPAPER_FANFOLD_STD_GERMAN 40
#परिभाषय DMPAPER_FANFOLD_LGL_GERMAN 41
#परिभाषय DMPAPER_ISO_B4 42
#परिभाषय DMPAPER_JAPANESE_POSTCARD 43
#परिभाषय DMPAPER_9X11 44
#परिभाषय DMPAPER_10X11 45
#परिभाषय DMPAPER_15X11 46
#परिभाषय DMPAPER_ENV_INVITE 47
#परिभाषय DMPAPER_RESERVED_48 48
#परिभाषय DMPAPER_RESERVED_49 49
#परिभाषय DMPAPER_LETTER_EXTRA 50
#परिभाषय DMPAPER_LEGAL_EXTRA 51
#परिभाषय DMPAPER_TABLOID_EXTRA 52
#परिभाषय DMPAPER_A4_EXTRA 53
#परिभाषय DMPAPER_LETTER_TRANSVERSE 54
#परिभाषय DMPAPER_A4_TRANSVERSE 55
#परिभाषय DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#परिभाषय DMPAPER_A_PLUS 57
#परिभाषय DMPAPER_B_PLUS 58
#परिभाषय DMPAPER_LETTER_PLUS 59
#परिभाषय DMPAPER_A4_PLUS 60
#परिभाषय DMPAPER_A5_TRANSVERSE 61
#परिभाषय DMPAPER_B5_TRANSVERSE 62
#परिभाषय DMPAPER_A3_EXTRA 63
#परिभाषय DMPAPER_A5_EXTRA 64
#परिभाषय DMPAPER_B5_EXTRA 65
#परिभाषय DMPAPER_A2 66
#परिभाषय DMPAPER_A3_TRANSVERSE 67
#परिभाषय DMPAPER_A3_EXTRA_TRANSVERSE 68
#परिभाषय DMPAPER_DBL_JAPANESE_POSTCARD 69
#परिभाषय DMPAPER_A6 70
#परिभाषय DMPAPER_JENV_KAKU2 71
#परिभाषय DMPAPER_JENV_KAKU3 72
#परिभाषय DMPAPER_JENV_CHOU3 73
#परिभाषय DMPAPER_JENV_CHOU4 74
#परिभाषय DMPAPER_LETTER_ROTATED 75
#परिभाषय DMPAPER_A3_ROTATED 76
#परिभाषय DMPAPER_A4_ROTATED 77
#परिभाषय DMPAPER_A5_ROTATED 78
#परिभाषय DMPAPER_B4_JIS_ROTATED 79
#परिभाषय DMPAPER_B5_JIS_ROTATED 80
#परिभाषय DMPAPER_JAPANESE_POSTCARD_ROTATED 81
#परिभाषय DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#परिभाषय DMPAPER_A6_ROTATED 83
#परिभाषय DMPAPER_JENV_KAKU2_ROTATED 84
#परिभाषय DMPAPER_JENV_KAKU3_ROTATED 85
#परिभाषय DMPAPER_JENV_CHOU3_ROTATED 86
#परिभाषय DMPAPER_JENV_CHOU4_ROTATED 87
#परिभाषय DMPAPER_B6_JIS 88
#परिभाषय DMPAPER_B6_JIS_ROTATED 89
#परिभाषय DMPAPER_12X11 90
#परिभाषय DMPAPER_JENV_YOU4 91
#परिभाषय DMPAPER_JENV_YOU4_ROTATED 92
#परिभाषय DMPAPER_P16K 93
#परिभाषय DMPAPER_P32K 94
#परिभाषय DMPAPER_P32KBIG 95
#परिभाषय DMPAPER_PENV_1 96
#परिभाषय DMPAPER_PENV_2 97
#परिभाषय DMPAPER_PENV_3 98
#परिभाषय DMPAPER_PENV_4 99
#परिभाषय DMPAPER_PENV_5 100
#परिभाषय DMPAPER_PENV_6 101
#परिभाषय DMPAPER_PENV_7 102
#परिभाषय DMPAPER_PENV_8 103
#परिभाषय DMPAPER_PENV_9 104
#परिभाषय DMPAPER_PENV_10 105
#परिभाषय DMPAPER_P16K_ROTATED 106
#परिभाषय DMPAPER_P32K_ROTATED 107
#परिभाषय DMPAPER_P32KBIG_ROTATED 108
#परिभाषय DMPAPER_PENV_1_ROTATED 109
#परिभाषय DMPAPER_PENV_2_ROTATED 110
#परिभाषय DMPAPER_PENV_3_ROTATED 111
#परिभाषय DMPAPER_PENV_4_ROTATED 112
#परिभाषय DMPAPER_PENV_5_ROTATED 113
#परिभाषय DMPAPER_PENV_6_ROTATED 114
#परिभाषय DMPAPER_PENV_7_ROTATED 115
#परिभाषय DMPAPER_PENV_8_ROTATED 116
#परिभाषय DMPAPER_PENV_9_ROTATED 117
#परिभाषय DMPAPER_PENV_10_ROTATED 118

#परिभाषय DMPAPER_चरमः DMPAPER_PENV_10_ROTATED

#परिभाषय DMPAPER_USER 256

#परिभाषय DMBIN_FIRST DMBIN_ऊर्ध्वस्थम्
#परिभाषय DMBIN_ऊर्ध्वस्थम् 1
#परिभाषय DMBIN_ONLYONE 1
#परिभाषय DMBIN_अधस्तनम् 2
#परिभाषय DMBIN_मध्यः 3
#परिभाषय DMBIN_MANUAL 4
#परिभाषय DMBIN_ENVELOPE 5
#परिभाषय DMBIN_ENVMANUAL 6
#परिभाषय DMBIN_AUTO 7
#परिभाषय DMBIN_TRACTOR 8
#परिभाषय DMBIN_SMALLFMT 9
#परिभाषय DMBIN_LARGEFMT 10
#परिभाषय DMBIN_LARGECAPACITY 11
#परिभाषय DMBIN_CASSETTE 14
#परिभाषय DMBIN_FORMSOURCE 15
#परिभाषय DMBIN_चरमः DMBIN_FORMSOURCE

#परिभाषय DMBIN_USER 256

#परिभाषय DMRES_DRAFT (-1)
#परिभाषय DMRES_नीचः (-2)
#परिभाषय DMRES_MEDIUM (-3)
#परिभाषय DMRES_उच्चः (-4)

#परिभाषय DMCOLOR_MONOCHROME 1
#परिभाषय DMCOLOR_COLOR 2

#परिभाषय DMDUP_SIMPLEX 1
#परिभाषय DMDUP_VERTICAL 2
#परिभाषय DMDUP_HORIZONTAL 3

#परिभाषय DMTT_BITMAP 1
#परिभाषय DMTT_DOWNLOAD 2
#परिभाषय DMTT_SUBDEV 3
#परिभाषय DMTT_DOWNLOAD_OUTLINE 4

#परिभाषय DMCOLLATE_FALSE 0
#परिभाषय DMCOLLATE_TRUE 1

#परिभाषय DMDO_DEFAULT 0
#परिभाषय DMDO_90 1
#परिभाषय DMDO_180 2
#परिभाषय DMDO_270 3

#परिभाषय DMDFO_DEFAULT 0
#परिभाषय DMDFO_STRETCH 1
#परिभाषय DMDFO_CENTER 2

#परिभाषय DMDISPLAYFLAGS_TEXTMODE 0x00000004

#परिभाषय DMNUP_SYSTEM 1
#परिभाषय DMNUP_ONEUP 2

#परिभाषय DMICMMETHOD_NONE 1
#परिभाषय DMICMMETHOD_SYSTEM 2
#परिभाषय DMICMMETHOD_DRIVER 3
#परिभाषय DMICMMETHOD_DEVICE 4

#परिभाषय DMICMMETHOD_USER 256

#परिभाषय DMICM_SATURATE 1
#परिभाषय DMICM_CONTRAST 2
#परिभाषय DMICM_COLORIMETRIC 3
#परिभाषय DMICM_ABS_COLORIMETRIC 4

#परिभाषय DMICM_USER 256

#परिभाषय DMMEDIA_STANDARD 1
#परिभाषय DMMEDIA_TRANSPARENCY 2
#परिभाषय DMMEDIA_GLOSSY 3

#परिभाषय DMMEDIA_USER 256

#परिभाषय DMDITHER_NONE 1
#परिभाषय DMDITHER_COARSE 2
#परिभाषय DMDITHER_FINE 3
#परिभाषय DMDITHER_LINEART 4
#परिभाषय DMDITHER_ERRORDIFFUSION 5
#परिभाषय DMDITHER_RESERVED6 6
#परिभाषय DMDITHER_RESERVED7 7
#परिभाषय DMDITHER_RESERVED8 8
#परिभाषय DMDITHER_RESERVED9 9
#परिभाषय DMDITHER_GRAYSCALE 10

#परिभाषय DMDITHER_USER 256

  प्रकारनिर्देश संरचना _DISPLAY_DEVICEA {
    DWORD cb;
    CHAR DeviceName[32];
    CHAR DeviceString[128];
    DWORD StateFlags;
    CHAR DeviceID[128];
    CHAR Device_कुञ्चिका[128];
  } DISPLAY_DEVICEA,*PDISPLAY_DEVICEA,*LPDISPLAY_DEVICEA;
  प्रकारनिर्देश संरचना _DISPLAY_DEVICEW {
    DWORD cb;
    WCHAR DeviceName[32];
    WCHAR DeviceString[128];
    DWORD StateFlags;
    WCHAR DeviceID[128];
    WCHAR Device_कुञ्चिका[128];
  } DISPLAY_DEVICEW,*PDISPLAY_DEVICEW,*LPDISPLAY_DEVICEW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश DISPLAY_DEVICEW DISPLAY_DEVICE;
  प्रकारनिर्देश PDISPLAY_DEVICEW PDISPLAY_DEVICE;
  प्रकारनिर्देश LPDISPLAY_DEVICEW LPDISPLAY_DEVICE;
#अन्यथा
  प्रकारनिर्देश DISPLAY_DEVICEA DISPLAY_DEVICE;
  प्रकारनिर्देश PDISPLAY_DEVICEA PDISPLAY_DEVICE;
  प्रकारनिर्देश LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
#यदि_अन्तः

#परिभाषय DISPLAY_DEVICE_ATTACHED_गन्तव्यम्_DESKTOP 0x00000001
#परिभाषय DISPLAY_DEVICE_MULTI_DRIVER 0x00000002
#परिभाषय DISPLAY_DEVICE_PRIMARY_DEVICE 0x00000004
#परिभाषय DISPLAY_DEVICE_MIRRORING_DRIVER 0x00000008
#परिभाषय DISPLAY_DEVICE_VGA_COMPATIBLE 0x00000010
#परिभाषय DISPLAY_DEVICE_REMOVABLE 0x00000020
#परिभाषय DISPLAY_DEVICE_MODESPRUNED 0x08000000
#परिभाषय DISPLAY_DEVICE_REMOTE 0x04000000
#परिभाषय DISPLAY_DEVICE_DISCONNECT 0x02000000

#परिभाषय DISPLAY_DEVICE_सक्रिय 0x00000001
#परिभाषय DISPLAY_DEVICE_ATTACHED 0x00000002

#परिभाषय RDH_RECTANGLES 1

  प्रकारनिर्देश संरचना _RGNDATAHEADER {
    DWORD dw_आकार;
    DWORD iType;
    DWORD n_गणनम्;
    DWORD n_Rgn_आकार;
    RECT rcBound;
  } RGNDATAHEADER,*PRGNDATAHEADER;

  प्रकारनिर्देश संरचना _RGNDATA {
    RGNDATAHEADER rdh;
    वर्ण बफर_3[1];
  } RGNDATA,*PRGNDATA,*NPRGNDATA,*LPRGNDATA;

#परिभाषय SYSRGN 4

  प्रकारनिर्देश संरचना _ABC {
    पूर्णाङ्क abcA;
    UINT abcB;
    पूर्णाङ्क abcC;
  } ABC,*PABC,*NPABC,*LPABC;

  प्रकारनिर्देश संरचना _ABCFLOAT {
    FLOAT abcfA;
    FLOAT abcfB;
    FLOAT abcfC;
  } ABCFLOAT,*PABCFLOAT,*NPABCFLOAT,*LPABCFLOAT;

#यदि_अपरिभाषितम् NOTEXTMETRIC

  प्रकारनिर्देश संरचना _OUTLINETEXTMETRICA {
    UINT otm_आकार;
    TEXTMETRICA otmTextMetrics;
    BYTE otmFiller;
    PANOSE otm_Panose_सङ्ख्या;
    UINT otmfsSelection;
    UINT otmfsType;
    पूर्णाङ्क otms_Char_नतिः_Rise;
    पूर्णाङ्क otms_Char_नतिः_सततम्;
    पूर्णाङ्क otmItalicAngle;
    UINT otmEMSquare;
    पूर्णाङ्क otmAscent;
    पूर्णाङ्क otmDescent;
    UINT otm_पङ्क्तिः_Gap;
    UINT otmsCapEmHeight;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    पूर्णाङ्क otmMacAscent;
    पूर्णाङ्क otmMacDescent;
    UINT otm_Mac_पङ्क्तिः_Gap;
    UINT otmusMinimumPPEM;
    POINT otmpt_Subscript_आकार;
    POINT otmpt_Subscript_विस्थापनम्;
    POINT otmpt_Superscript_आकार;
    POINT otmpt_Superscript_विस्थापनम्;
    UINT otms_Strikeout_आकार;
    पूर्णाङ्क otmsStrikeoutPosition;
    पूर्णाङ्क otms_Underscore_आकार;
    पूर्णाङ्क otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_पूर्णम्_Name;
  } OUTLINETEXTMETRICA,*POUTLINETEXTMETRICA,*NPOUTLINETEXTMETRICA,*LPOUTLINETEXTMETRICA;

  प्रकारनिर्देश संरचना _OUTLINETEXTMETRICW {
    UINT otm_आकार;
    TEXTMETRICW otmTextMetrics;
    BYTE otmFiller;
    PANOSE otm_Panose_सङ्ख्या;
    UINT otmfsSelection;
    UINT otmfsType;
    पूर्णाङ्क otms_Char_नतिः_Rise;
    पूर्णाङ्क otms_Char_नतिः_सततम्;
    पूर्णाङ्क otmItalicAngle;
    UINT otmEMSquare;
    पूर्णाङ्क otmAscent;
    पूर्णाङ्क otmDescent;
    UINT otm_पङ्क्तिः_Gap;
    UINT otmsCapEmHeight;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    पूर्णाङ्क otmMacAscent;
    पूर्णाङ्क otmMacDescent;
    UINT otm_Mac_पङ्क्तिः_Gap;
    UINT otmusMinimumPPEM;
    POINT otmpt_Subscript_आकार;
    POINT otmpt_Subscript_विस्थापनम्;
    POINT otmpt_Superscript_आकार;
    POINT otmpt_Superscript_विस्थापनम्;
    UINT otms_Strikeout_आकार;
    पूर्णाङ्क otmsStrikeoutPosition;
    पूर्णाङ्क otms_Underscore_आकार;
    पूर्णाङ्क otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_पूर्णम्_Name;
  } OUTLINETEXTMETRICW,*POUTLINETEXTMETRICW,*NPOUTLINETEXTMETRICW,*LPOUTLINETEXTMETRICW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश OUTLINETEXTMETRICW OUTLINETEXTMETRIC;
  प्रकारनिर्देश POUTLINETEXTMETRICW POUTLINETEXTMETRIC;
  प्रकारनिर्देश NPOUTLINETEXTMETRICW NPOUTLINETEXTMETRIC;
  प्रकारनिर्देश LPOUTLINETEXTMETRICW LPOUTLINETEXTMETRIC;
#अन्यथा
  प्रकारनिर्देश OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
  प्रकारनिर्देश POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
  प्रकारनिर्देश NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
  प्रकारनिर्देश LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
#यदि_अन्तः
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_POLYTEXTA {
    पूर्णाङ्क x;
    पूर्णाङ्क y;
    UINT n;
    LPCSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    पूर्णाङ्क *pdx;
  } POLYTEXTA,*PPOLYTEXTA,*NPPOLYTEXTA,*LPPOLYTEXTA;

  प्रकारनिर्देश संरचना चिह्नकम्_POLYTEXTW {
    पूर्णाङ्क x;
    पूर्णाङ्क y;
    UINT n;
    LPCWSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    पूर्णाङ्क *pdx;
  } POLYTEXTW,*PPOLYTEXTW,*NPPOLYTEXTW,*LPPOLYTEXTW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश POLYTEXTW POLYTEXT;
  प्रकारनिर्देश PPOLYTEXTW PPOLYTEXT;
  प्रकारनिर्देश NPPOLYTEXTW NPPOLYTEXT;
  प्रकारनिर्देश LPPOLYTEXTW LPPOLYTEXT;
#अन्यथा
  प्रकारनिर्देश POLYTEXTA POLYTEXT;
  प्रकारनिर्देश PPOLYTEXTA PPOLYTEXT;
  प्रकारनिर्देश NPPOLYTEXTA NPPOLYTEXT;
  प्रकारनिर्देश LPPOLYTEXTA LPPOLYTEXT;
#यदि_अन्तः

  प्रकारनिर्देश संरचना _FIXED {
    WORD fract;
    ह्रस्व मानम्;
  } FIXED;

  प्रकारनिर्देश संरचना _MAT2 {
    FIXED eM11;
    FIXED eM12;
    FIXED eM21;
    FIXED eM22;
  } MAT2,*LPMAT2;

  प्रकारनिर्देश संरचना _GLYPHMETRICS {
    UINT gmBlackBoxX;
    UINT gmBlackBoxY;
    POINT gmptGlyphOrigin;
    ह्रस्व gmCellIncX;
    ह्रस्व gmCellIncY;
  } GLYPHMETRICS,*LPGLYPHMETRICS;

#परिभाषय GGO_METRICS 0
#परिभाषय GGO_BITMAP 1
#परिभाषय GGO_NATIVE 2
#परिभाषय GGO_BEZIER 3

#परिभाषय GGO_GRAY2_BITMAP 4
#परिभाषय GGO_GRAY4_BITMAP 5
#परिभाषय GGO_GRAY8_BITMAP 6
#परिभाषय GGO_GLYPH_सूचकांक 0x0080
#परिभाषय GGO_UNHINTED 0x0100

#परिभाषय TT_POLYGON_TYPE 24

#परिभाषय TT_PRIM_पङ्क्तिः 1
#परिभाषय TT_PRIM_QSPLINE 2
#परिभाषय TT_PRIM_CSPLINE 3

  प्रकारनिर्देश संरचना चिह्नकम्_POINTFX {
    FIXED x;
    FIXED y;
  } POINTFX,*LPPOINTFX;

  प्रकारनिर्देश संरचना चिह्नकम्_TTPOLYCURVE {
    WORD wType;
    WORD cpfx;
    POINTFX apfx[1];
  } TTPOLYCURVE,*LPTTPOLYCURVE;

  प्रकारनिर्देश संरचना चिह्नकम्_TTPOLYGONHEADER {
    DWORD cb;
    DWORD dwType;
    POINTFX pfxStart;
  } TTPOLYGONHEADER,*LPTTPOLYGONHEADER;

#परिभाषय GCP_DBCS 0x0001
#परिभाषय GCP_REORDER 0x0002
#परिभाषय GCP_USEKERNING 0x0008
#परिभाषय GCP_GLYPHSHAPE 0x0010
#परिभाषय GCP_LIGATE 0x0020

#परिभाषय GCP_DIACRITIC 0x0100
#परिभाषय GCP_KASHIDA 0x0400
#परिभाषय GCP_ERROR 0x8000
#परिभाषय FLI_आवरणम् 0x103B

#परिभाषय GCP_JUSTIFY 0x00010000L

#परिभाषय FLI_GLYPHS 0x00040000L
#परिभाषय GCP_CLASSIN 0x00080000L
#परिभाषय GCP_MAXEXTENT 0x00100000L
#परिभाषय GCP_JUSTIFYIN 0x00200000L
#परिभाषय GCP_DISPLAYZWG 0x00400000L
#परिभाषय GCP_SYMSWAPOFF 0x00800000L
#परिभाषय GCP_NUMERICOVERRIDE 0x01000000L
#परिभाषय GCP_NEUTRALOVERRIDE 0x02000000L
#परिभाषय GCP_NUMERICSLATIN 0x04000000L
#परिभाषय GCP_NUMERICSLOCAL 0x08000000L

#परिभाषय GCPCLASS_LATIN 1
#परिभाषय GCPCLASS_HEBREW 2
#परिभाषय GCPCLASS_ARABIC 2
#परिभाषय GCPCLASS_NEUTRAL 3
#परिभाषय GCPCLASS_LOCALNUMBER 4
#परिभाषय GCPCLASS_LATINNUMBER 5
#परिभाषय GCPCLASS_LATINNUMERICTERMINATOR 6
#परिभाषय GCPCLASS_LATINNUMERICSEPARATOR 7
#परिभाषय GCPCLASS_NUMERICSEPARATOR 8
#परिभाषय GCPCLASS_PREBOUNDLTR 0x80
#परिभाषय GCPCLASS_PREBOUNDRTL 0x40
#परिभाषय GCPCLASS_POSTBOUNDLTR 0x20
#परिभाषय GCPCLASS_POSTBOUNDRTL 0x10

#परिभाषय GCPGLYPH_LINKBEFORE 0x8000
#परिभाषय GCPGLYPH_LINKAFTER 0x4000

  प्रकारनिर्देश संरचना चिह्नकम्_GCP_RESULTSA {
    DWORD l_Struct_आकार;
    LPSTR lp_बहिर्गमनम्_String;
    UINT *lp_क्रमः;
    पूर्णाङ्क *lpDx;
    पूर्णाङ्क *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    पूर्णाङ्क nMaxFit;
  } GCP_RESULTSA,*LPGCP_RESULTSA;
  प्रकारनिर्देश संरचना चिह्नकम्_GCP_RESULTSW {
    DWORD l_Struct_आकार;
    LPWSTR lp_बहिर्गमनम्_String;
    UINT *lp_क्रमः;
    पूर्णाङ्क *lpDx;
    पूर्णाङ्क *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    पूर्णाङ्क nMaxFit;
  } GCP_RESULTSW,*LPGCP_RESULTSW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश GCP_RESULTSW GCP_RESULTS;
  प्रकारनिर्देश LPGCP_RESULTSW LPGCP_RESULTS;
#अन्यथा
  प्रकारनिर्देश GCP_RESULTSA GCP_RESULTS;
  प्रकारनिर्देश LPGCP_RESULTSA LPGCP_RESULTS;
#यदि_अन्तः

  प्रकारनिर्देश संरचना RASTERIZER_स्थितिः {
    ह्रस्व n_आकार;
    ह्रस्व wFlags;
    ह्रस्व nLanguageID;
  } RASTERIZER_स्थितिः_2,*LPRASTERIZER_स्थितिः;

#परिभाषय TT_उपलब्धम् 0x0001
#परिभाषय TT_ENABLED 0x0002

  प्रकारनिर्देश संरचना चिह्नकम्_PIXELFORMATDESCRIPTOR {
    WORD n_आकार;
    WORD n_संस्करणम्;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_द्वयङ्काः;
    BYTE c_Red_द्वयङ्काः;
    BYTE c_Red_सरणम्;
    BYTE c_Green_द्वयङ्काः;
    BYTE c_Green_सरणम्;
    BYTE c_Blue_द्वयङ्काः;
    BYTE c_Blue_सरणम्;
    BYTE c_Alpha_द्वयङ्काः;
    BYTE c_Alpha_सरणम्;
    BYTE c_Accum_द्वयङ्काः;
    BYTE c_Accum_Red_द्वयङ्काः;
    BYTE c_Accum_Green_द्वयङ्काः;
    BYTE c_Accum_Blue_द्वयङ्काः;
    BYTE c_Accum_Alpha_द्वयङ्काः;
    BYTE c_गभीरता_द्वयङ्काः;
    BYTE c_Stencil_द्वयङ्काः;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dw_Layer_आवरणम्;
    DWORD dw_Visible_आवरणम्;
    DWORD dw_Damage_आवरणम्;
  } PIXELFORMATDESCRIPTOR,*PPIXELFORMATDESCRIPTOR,*LPPIXELFORMATDESCRIPTOR;

#परिभाषय PFD_TYPE_RGBA 0
#परिभाषय PFD_TYPE_COLORINDEX 1

#परिभाषय PFD_MAIN_PLANE 0
#परिभाषय PFD_OVERLAY_PLANE 1
#परिभाषय PFD_UNDERLAY_PLANE (-1)

#परिभाषय PFD_DOUBLEBUFFER 0x00000001
#परिभाषय PFD_STEREO 0x00000002
#परिभाषय PFD_DRAW_गन्तव्यम्_गवाक्षः 0x00000004
#परिभाषय PFD_DRAW_गन्तव्यम्_BITMAP 0x00000008
#परिभाषय PFD_SUPPORT_GDI 0x00000010
#परिभाषय PFD_SUPPORT_OPENGL 0x00000020
#परिभाषय PFD_GENERIC_FORMAT 0x00000040
#परिभाषय PFD_NEED_PALETTE 0x00000080
#परिभाषय PFD_NEED_SYSTEM_PALETTE 0x00000100
#परिभाषय PFD_SWAP_EXCHANGE 0x00000200
#परिभाषय PFD_SWAP_COPY 0x00000400
#परिभाषय PFD_SWAP_LAYER_BUFFERS 0x00000800
#परिभाषय PFD_GENERIC_ACCELERATED 0x00001000
#परिभाषय PFD_SUPPORT_DIRECTDRAW 0x00002000

#परिभाषय PFD_गभीरता_DONTCARE 0x20000000
#परिभाषय PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#परिभाषय PFD_STEREO_DONTCARE 0x80000000

#यदि_अपरिभाषितम् NOTEXTMETRIC
  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST TEXTMETRICA *,DWORD,LPARAM);
  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST TEXTMETRICW *,DWORD,LPARAM);
#यदि_परिभाषितम् UNICODE
#परिभाषय OLDFONTENUMPROC OLDFONTENUMPROCW
#अन्यथा
#परिभाषय OLDFONTENUMPROC OLDFONTENUMPROCA
#यदि_अन्तः
#अन्यथा
  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST VOID *,DWORD,LPARAM);
  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST VOID *,DWORD,LPARAM);
#यदि_परिभाषितम् UNICODE
#परिभाषय OLDFONTENUMPROC OLDFONTENUMPROCW
#अन्यथा
#परिभाषय OLDFONTENUMPROC OLDFONTENUMPROCA
#यदि_अन्तः
#यदि_अन्तः

  प्रकारनिर्देश OLDFONTENUMPROCA FONTENUMPROCA;
  प्रकारनिर्देश OLDFONTENUMPROCW FONTENUMPROCW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश FONTENUMPROCW FONTENUMPROC;
#अन्यथा
  प्रकारनिर्देश FONTENUMPROCA FONTENUMPROC;
#यदि_अन्तः

  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *GOBJENUMPROC)(LPVOID,LPARAM);
  प्रकारनिर्देश VOID (CALLBACK *LINEDDAPROC)(पूर्णाङ्क,पूर्णाङ्क,LPARAM);

#यदि_परिभाषितम् UNICODE
#परिभाषय सङ्कलय_Font_Resource सङ्कलय_Font_Resource_W
#परिभाषय CopyMetaFile CopyMetaFileW
#परिभाषय CreateDC CreateDCW
#परिभाषय Create_Font_परोक्षम् Create_Font_परोक्षम्_W
#परिभाषय CreateFont CreateFontW
#परिभाषय CreateIC CreateICW
#परिभाषय CreateMetaFile CreateMetaFileW
#परिभाषय CreateScalableFontResource CreateScalableFontResourceW
#अन्यथा
#परिभाषय सङ्कलय_Font_Resource सङ्कलय_Font_Resource_A
#परिभाषय CopyMetaFile CopyMetaFileA
#परिभाषय CreateDC CreateDCA
#परिभाषय Create_Font_परोक्षम् Create_Font_परोक्षम्_A
#परिभाषय CreateFont CreateFontA
#परिभाषय CreateIC CreateICA
#परिभाषय CreateMetaFile CreateMetaFileA
#परिभाषय CreateScalableFontResource CreateScalableFontResourceA
#यदि_अन्तः

  WINGDIAPI पूर्णाङ्क WINAPI सङ्कलय_Font_Resource_A(LPCSTR);
  WINGDIAPI पूर्णाङ्क WINAPI सङ्कलय_Font_Resource_W(LPCWSTR);
  WINGDIAPI WINBOOL WINAPI AnimatePalette(HPALETTE hPal,UINT i_Start_सूचकांक,UINT cEntries,CONST PALETTEENTRY *ppe);
  WINGDIAPI WINBOOL WINAPI Arc(HDC hdc,पूर्णाङ्क x1,पूर्णाङ्क y1,पूर्णाङ्क x2,पूर्णाङ्क y2,पूर्णाङ्क x3,पूर्णाङ्क y3,पूर्णाङ्क x4,पूर्णाङ्क y4);
  WINGDIAPI WINBOOL WINAPI BitBlt(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,पूर्णाङ्क cx,पूर्णाङ्क cy,HDC hdcSrc,पूर्णाङ्क x1,पूर्णाङ्क y1,DWORD rop);
  WINGDIAPI WINBOOL WINAPI CancelDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Chord(HDC hdc,पूर्णाङ्क x1,पूर्णाङ्क y1,पूर्णाङ्क x2,पूर्णाङ्क y2,पूर्णाङ्क x3,पूर्णाङ्क y3,पूर्णाङ्क x4,पूर्णाङ्क y4);
  WINGDIAPI पूर्णाङ्क WINAPI वृणु_Pixel_Format(HDC hdc,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI HMETAFILE WINAPI CloseMetaFile(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,पूर्णाङ्क i_बहुलकम्);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
  WINGDIAPI HBITMAP WINAPI CreateBitmap(पूर्णाङ्क n_विस्तारः,पूर्णाङ्क nHeight,UINT nPlanes,UINT n_Bit_गणनम्,CONST VOID *lp_द्वयङ्काः);
  WINGDIAPI HBITMAP WINAPI Create_Bitmap_परोक्षम्(CONST BITMAP *pbm);
  WINGDIAPI HBRUSH WINAPI Create_Brush_परोक्षम्(CONST LOGBRUSH *plbrush);
  WINGDIAPI HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc,पूर्णाङ्क cx,पूर्णाङ्क cy);
  WINGDIAPI HBITMAP WINAPI CreateDiscardableBitmap(HDC hdc,पूर्णाङ्क cx,पूर्णाङ्क cy);
  WINGDIAPI HDC WINAPI CreateCompatibleDC(HDC hdc);
  WINGDIAPI HDC WINAPI CreateDCA(LPCSTR pwszDriver,LPCSTR pwszDevice,LPCSTR psz_पत्तनम्,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateDCW(LPCWSTR pwszDriver,LPCWSTR pwszDevice,LPCWSTR psz_पत्तनम्,CONST DEVMODEW *pdm);
  WINGDIAPI HBITMAP WINAPI CreateDIBitmap(HDC hdc,CONST BITMAPINFOHEADER *pbmih,DWORD flInit,CONST VOID *pj_द्वयङ्काः,CONST BITMAPINFO *pbmi,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL h,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB,UINT iUsage);
  WINGDIAPI HRGN WINAPI CreateEllipticRgn(पूर्णाङ्क x1,पूर्णाङ्क y1,पूर्णाङ्क x2,पूर्णाङ्क y2);
  WINGDIAPI HRGN WINAPI Create_Elliptic_Rgn_परोक्षम्(CONST RECT *lprect);
  WINGDIAPI HFONT WINAPI Create_Font_परोक्षम्_A(CONST LOGFONTA *lplf);
  WINGDIAPI HFONT WINAPI Create_Font_परोक्षम्_W(CONST LOGFONTW *lplf);
  WINGDIAPI HFONT WINAPI CreateFontA(पूर्णाङ्क cHeight,पूर्णाङ्क c_विस्तारः,पूर्णाङ्क cEscapement,पूर्णाङ्क cOrientation,पूर्णाङ्क cWeight,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_बहिर्गमनम्,DWORD i_Char_समुच्चयः,DWORD i_बहिर्गमनम्_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCSTR pszFaceName);
  WINGDIAPI HFONT WINAPI CreateFontW(पूर्णाङ्क cHeight,पूर्णाङ्क c_विस्तारः,पूर्णाङ्क cEscapement,पूर्णाङ्क cOrientation,पूर्णाङ्क cWeight,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_बहिर्गमनम्,DWORD i_Char_समुच्चयः,DWORD i_बहिर्गमनम्_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCWSTR pszFaceName);
  WINGDIAPI HBRUSH WINAPI CreateHatchBrush(पूर्णाङ्क iHatch,COLORREF color);
  WINGDIAPI HDC WINAPI CreateICA(LPCSTR pszDriver,LPCSTR pszDevice,LPCSTR psz_पत्तनम्,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateICW(LPCWSTR pszDriver,LPCWSTR pszDevice,LPCWSTR psz_पत्तनम्,CONST DEVMODEW *pdm);
  WINGDIAPI HDC WINAPI CreateMetaFileA(LPCSTR pszFile);
  WINGDIAPI HDC WINAPI CreateMetaFileW(LPCWSTR pszFile);
  WINGDIAPI HPALETTE WINAPI CreatePalette(CONST LOGPALETTE *plpal);
  WINGDIAPI HPEN WINAPI CreatePen(पूर्णाङ्क iStyle,पूर्णाङ्क c_विस्तारः,COLORREF color);
  WINGDIAPI HPEN WINAPI Create_Pen_परोक्षम्(CONST LOGPEN *plpen);
  WINGDIAPI HRGN WINAPI CreatePolyPolygonRgn(CONST POINT *pptl,CONST INT *pc,पूर्णाङ्क cPoly,पूर्णाङ्क i_बहुलकम्);
  WINGDIAPI HBRUSH WINAPI Create_आदर्शः_Brush(HBITMAP hbm);
  WINGDIAPI HRGN WINAPI CreateRectRgn(पूर्णाङ्क x1,पूर्णाङ्क y1,पूर्णाङ्क x2,पूर्णाङ्क y2);
  WINGDIAPI HRGN WINAPI Create_Rect_Rgn_परोक्षम्(CONST RECT *lprect);
  WINGDIAPI HRGN WINAPI Create_आवर्तनम्_Rect_Rgn(पूर्णाङ्क x1,पूर्णाङ्क y1,पूर्णाङ्क x2,पूर्णाङ्क y2,पूर्णाङ्क w,पूर्णाङ्क h);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceA(DWORD fdwHidden,LPCSTR lpszFont,LPCSTR lpszFile,LPCSTR lpsz_मार्गः);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceW(DWORD fdwHidden,LPCWSTR lpszFont,LPCWSTR lpszFile,LPCWSTR lpsz_मार्गः);
  WINGDIAPI HBRUSH WINAPI CreateSolidBrush(COLORREF color);
  WINGDIAPI WINBOOL WINAPI DeleteDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI DeleteMetaFile(HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI DeleteObject(HGDIOBJ ho);
  WINGDIAPI पूर्णाङ्क WINAPI DescribePixelFormat(HDC hdc,पूर्णाङ्क iPixelFormat,UINT n_अष्टकानि,LPPIXELFORMATDESCRIPTOR ppfd);

  प्रकारनिर्देश UINT (CALLBACK *LPFNDEVMODE)(HWND,HMODULE,LPDEVMODE,LPSTR,LPSTR,LPDEVMODE,LPSTR,UINT);
  प्रकारनिर्देश DWORD (CALLBACK *LPFNDEVCAPS)(LPSTR,LPSTR,UINT,LPSTR,LPDEVMODE);

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
#परिभाषय DC_BINADJUST 19
#परिभाषय DC_EMF_COMPLIANT 20
#परिभाषय DC_DATATYPE_PRODUCED 21
#परिभाषय DC_COLLATE 22
#परिभाषय DC_MANUFACTURER 23
#परिभाषय DC_MODEL 24
#परिभाषय DC_PERSONALITY 25
#परिभाषय DC_PRINTRATE 26
#परिभाषय DC_PRINTRATEUNIT 27
#परिभाषय PRINTRATEUNIT_PPM 1
#परिभाषय PRINTRATEUNIT_CPS 2
#परिभाषय PRINTRATEUNIT_LPM 3
#परिभाषय PRINTRATEUNIT_IPM 4
#परिभाषय DC_PRINTERMEM 28
#परिभाषय DC_MEDIAREADY 29
#परिभाषय DC_STAPLE 30
#परिभाषय DC_PRINTRATEPPM 31
#परिभाषय DC_COLORDEVICE 32
#परिभाषय DC_NUP 33
#परिभाषय DC_MEDIATYPENAMES 34
#परिभाषय DC_MEDIATYPES 35

#परिभाषय DCTT_BITMAP 0x0000001L
#परिभाषय DCTT_DOWNLOAD 0x0000002L
#परिभाषय DCTT_SUBDEV 0x0000004L
#परिभाषय DCTT_DOWNLOAD_OUTLINE 0x0000008L

#परिभाषय DCBA_FACEUPNONE 0x0000
#परिभाषय DCBA_FACEUPCENTER 0x0001
#परिभाषय DCBA_FACEUPLEFT 0x0002
#परिभाषय DCBA_FACEUPRIGHT 0x0003
#परिभाषय DCBA_FACEDOWNNONE 0x0100
#परिभाषय DCBA_FACEDOWNCENTER 0x0101
#परिभाषय DCBA_FACEDOWNLEFT 0x0102
#परिभाषय DCBA_FACEDOWNRIGHT 0x0103

#यदि_परिभाषितम् UNICODE
#परिभाषय DeviceCapabilities DeviceCapabilitiesW
#परिभाषय EnumFontFamiliesEx EnumFontFamiliesExW
#परिभाषय EnumFontFamilies EnumFontFamiliesW
#परिभाषय EnumFonts EnumFontsW
#परिभाषय Get_Char_विस्तारः Get_Char_विस्तारः_W
#परिभाषय GetCharWidth32 GetCharWidth32W
#परिभाषय Get_Char_विस्तारः_Float Get_Char_विस्तारः_Float_W
#परिभाषय GetCharABCWidths GetCharABCWidthsW
#परिभाषय GetCharABCWidthsFloat GetCharABCWidthsFloatW
#परिभाषय GetGlyphOutline GetGlyphOutlineW
#परिभाषय GetMetaFile GetMetaFileW
#अन्यथा
#परिभाषय DeviceCapabilities DeviceCapabilitiesA
#परिभाषय EnumFontFamiliesEx EnumFontFamiliesExA
#परिभाषय EnumFontFamilies EnumFontFamiliesA
#परिभाषय EnumFonts EnumFontsA
#परिभाषय Get_Char_विस्तारः Get_Char_विस्तारः_A
#परिभाषय GetCharWidth32 GetCharWidth32A
#परिभाषय Get_Char_विस्तारः_Float Get_Char_विस्तारः_Float_A
#परिभाषय GetCharABCWidths GetCharABCWidthsA
#परिभाषय GetCharABCWidthsFloat GetCharABCWidthsFloatA
#परिभाषय GetGlyphOutline GetGlyphOutlineA
#परिभाषय GetMetaFile GetMetaFileA
#यदि_अन्तः

  WINSPOOLAPI पूर्णाङ्क WINAPI DeviceCapabilitiesA(LPCSTR pDevice,LPCSTR p_पत्तनम्,WORD fwCapability,LPSTR pOutput,CONST DEVMODEA *p_Dev_बहुलकम्);
  WINSPOOLAPI पूर्णाङ्क WINAPI DeviceCapabilitiesW(LPCWSTR pDevice,LPCWSTR p_पत्तनम्,WORD fwCapability,LPWSTR pOutput,CONST DEVMODEW *p_Dev_बहुलकम्);
  WINGDIAPI पूर्णाङ्क WINAPI DrawEscape(HDC hdc,पूर्णाङ्क iEscape,पूर्णाङ्क cj_अन्तर्,LPCSTR lp_अन्तर्);
  WINGDIAPI WINBOOL WINAPI Ellipse(HDC hdc,पूर्णाङ्क वामः,पूर्णाङ्क शिखरम्,पूर्णाङ्क दक्षिणः,पूर्णाङ्क bottom);
  WINGDIAPI पूर्णाङ्क WINAPI EnumFontFamiliesExA(HDC hdc,LPLOGFONTA lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI पूर्णाङ्क WINAPI EnumFontFamiliesExW(HDC hdc,LPLOGFONTW lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI पूर्णाङ्क WINAPI EnumFontFamiliesA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI पूर्णाङ्क WINAPI EnumFontFamiliesW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI पूर्णाङ्क WINAPI EnumFontsA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI पूर्णाङ्क WINAPI EnumFontsW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI पूर्णाङ्क WINAPI EnumObjects(HDC hdc,पूर्णाङ्क nType,GOBJENUMPROC lpFunc,LPARAM lParam);
  WINGDIAPI WINBOOL WINAPI EqualRgn(HRGN hrgn1,HRGN hrgn2);
  WINGDIAPI पूर्णाङ्क WINAPI Escape(HDC hdc,पूर्णाङ्क iEscape,पूर्णाङ्क cj_अन्तर्,LPCSTR pv_अन्तर्,LPVOID pv_बहिर्गमनम्);
  WINGDIAPI पूर्णाङ्क WINAPI ExtEscape(HDC hdc,पूर्णाङ्क iEscape,पूर्णाङ्क cj_निवेशः,LPCSTR lp_अन्तर्_दत्त,पूर्णाङ्क cjOutput,LPSTR lp_बहिर्गमनम्_दत्त);
  WINGDIAPI पूर्णाङ्क WINAPI ExcludeClipRect(HDC hdc,पूर्णाङ्क वामः,पूर्णाङ्क शिखरम्,पूर्णाङ्क दक्षिणः,पूर्णाङ्क bottom);
  WINGDIAPI HRGN WINAPI ExtCreateRegion(CONST XFORM *lpx,DWORD n_गणनम्,CONST RGNDATA *lp_दत्त);
  WINGDIAPI WINBOOL WINAPI ExtFloodFill(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,COLORREF color,UINT type);
  WINGDIAPI WINBOOL WINAPI FillRgn(HDC hdc,HRGN hrgn,HBRUSH hbr);
  WINGDIAPI WINBOOL WINAPI FloodFill(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI FrameRgn(HDC hdc,HRGN hrgn,HBRUSH hbr,पूर्णाङ्क w,पूर्णाङ्क h);
  WINGDIAPI पूर्णाङ्क WINAPI GetROP2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_Aspect_अनुपातः_Filter_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI COLORREF WINAPI GetBkColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCBrushColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCPenColor(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI Get_Bk_बहुलकम्(HDC hdc);
  WINGDIAPI LONG WINAPI Get_Bitmap_द्वयङ्काः(HBITMAP hbit,LONG cb,LPVOID lpv_द्वयङ्काः);
  WINGDIAPI WINBOOL WINAPI GetBitmapDimensionEx(HBITMAP hbit,LPSIZE lpsize);
  WINGDIAPI UINT WINAPI GetBoundsRect(HDC hdc,LPRECT lprect,UINT flags);
  WINGDIAPI WINBOOL WINAPI GetBrushOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI Get_Char_विस्तारः_A(HDC hdc,UINT iFirst,UINT i_चरमः,LPINT lp_बफर);
  WINGDIAPI WINBOOL WINAPI Get_Char_विस्तारः_W(HDC hdc,UINT iFirst,UINT i_चरमः,LPINT lp_बफर);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32A(HDC hdc,UINT iFirst,UINT i_चरमः,LPINT lp_बफर);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32W(HDC hdc,UINT iFirst,UINT i_चरमः,LPINT lp_बफर);
  WINGDIAPI WINBOOL WINAPI Get_Char_विस्तारः_Float_A(HDC hdc,UINT iFirst,UINT i_चरमः,PFLOAT lp_बफर);
  WINGDIAPI WINBOOL WINAPI Get_Char_विस्तारः_Float_W(HDC hdc,UINT iFirst,UINT i_चरमः,PFLOAT lp_बफर);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsA(HDC hdc,UINT wFirst,UINT w_चरमः,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsW(HDC hdc,UINT wFirst,UINT w_चरमः,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatA(HDC hdc,UINT iFirst,UINT i_चरमः,LPABCFLOAT lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatW(HDC hdc,UINT iFirst,UINT i_चरमः,LPABCFLOAT lpABC);
  WINGDIAPI पूर्णाङ्क WINAPI GetClipBox(HDC hdc,LPRECT lprect);
  WINGDIAPI पूर्णाङ्क WINAPI GetClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI पूर्णाङ्क WINAPI GetMetaRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI HGDIOBJ WINAPI GetCurrentObject(HDC hdc,UINT type);
  WINGDIAPI WINBOOL WINAPI GetCurrentPositionEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI पूर्णाङ्क WINAPI GetDeviceCaps(HDC hdc,पूर्णाङ्क सूचकांक);
  WINGDIAPI पूर्णाङ्क WINAPI GetDIBits(HDC hdc,HBITMAP hbm,UINT start,UINT c_पङ्क्तयः,LPVOID lpv_द्वयङ्काः,LPBITMAPINFO lpbmi,UINT usage);
  WINGDIAPI DWORD WINAPI Get_Font_दत्त (HDC hdc,DWORD dw_सारणी,DWORD dw_विस्थापनम्,PVOID pv_बफर,DWORD cj_बफर);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineA(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_बफर,LPVOID pv_बफर,CONST MAT2 *lpmat2);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineW(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_बफर,LPVOID pv_बफर,CONST MAT2 *lpmat2);
  WINGDIAPI पूर्णाङ्क WINAPI Get_Graphics_बहुलकम्(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI Get_Map_बहुलकम्(HDC hdc);
  WINGDIAPI UINT WINAPI Get_Meta_File_द्वयङ्काः_Ex(HMETAFILE hMF,UINT cb_बफर,LPVOID lp_दत्त);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileA(LPCSTR lpName);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileW(LPCWSTR lpName);
  WINGDIAPI COLORREF WINAPI Get_निकटतमः_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI Get_निकटतमः_Palette_सूचकांक(HPALETTE h,COLORREF color);
  WINGDIAPI DWORD WINAPI GetObjectType(HGDIOBJ h);

#यदि_अपरिभाषितम् NOTEXTMETRIC
#यदि_परिभाषितम् UNICODE
#परिभाषय GetOutlineTextMetrics GetOutlineTextMetricsW
#अन्यथा
#परिभाषय GetOutlineTextMetrics GetOutlineTextMetricsA
#यदि_अन्तः

  WINGDIAPI UINT WINAPI GetOutlineTextMetricsA(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICA potm);
  WINGDIAPI UINT WINAPI GetOutlineTextMetricsW(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICW potm);
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय GetTextExtentPoint GetTextExtentPointW
#परिभाषय GetTextExtentPoint32 GetTextExtentPoint32W
#परिभाषय GetTextExtentExPoint GetTextExtentExPointW
#परिभाषय GetCharacterPlacement GetCharacterPlacementW
#अन्यथा
#परिभाषय GetTextExtentPoint GetTextExtentPointA
#परिभाषय GetTextExtentPoint32 GetTextExtentPoint32A
#परिभाषय GetTextExtentExPoint GetTextExtentExPointA
#परिभाषय GetCharacterPlacement GetCharacterPlacementA
#यदि_अन्तः

  WINGDIAPI UINT WINAPI GetPaletteEntries(HPALETTE hpal,UINT iStart,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI COLORREF WINAPI GetPixel(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y);
  WINGDIAPI पूर्णाङ्क WINAPI GetPixelFormat(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI Get_Poly_Fill_बहुलकम्(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetRasterizerCaps(LPRASTERIZER_स्थितिः lpraststat,UINT cj_अष्टकानि);
  WINGDIAPI पूर्णाङ्क WINAPI GetRandomRgn (HDC hdc,HRGN hrgn,INT i);
  WINGDIAPI DWORD WINAPI Get_Region_दत्त(HRGN hrgn,DWORD n_गणनम्,LPRGNDATA lp_Rgn_दत्त);
  WINGDIAPI पूर्णाङ्क WINAPI GetRgnBox(HRGN hrgn,LPRECT lprc);
  WINGDIAPI HGDIOBJ WINAPI GetStockObject(पूर्णाङ्क i);
  WINGDIAPI पूर्णाङ्क WINAPI Get_Stretch_Blt_बहुलकम्(HDC hdc);
  WINGDIAPI UINT WINAPI GetSystemPaletteEntries(HDC hdc,UINT iStart,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI UINT WINAPI GetSystemPaletteUse(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI GetTextCharacterExtra(HDC hdc);
  WINGDIAPI UINT WINAPI GetTextAlign(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetTextColor(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetTextExtentPointA(HDC hdc,LPCSTR lpString,पूर्णाङ्क c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI GetTextExtentPointW(HDC hdc,LPCWSTR lpString,पूर्णाङ्क c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI GetTextExtentPoint32A(HDC hdc,LPCSTR lpString,पूर्णाङ्क c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI GetTextExtentPoint32W(HDC hdc,LPCWSTR lpString,पूर्णाङ्क c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI GetTextExtentExPointA(HDC hdc,LPCSTR lpszString,पूर्णाङ्क cchString,पूर्णाङ्क nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_आकार);
  WINGDIAPI WINBOOL WINAPI GetTextExtentExPointW(HDC hdc,LPCWSTR lpszString,पूर्णाङ्क cchString,पूर्णाङ्क nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_आकार);
  WINGDIAPI पूर्णाङ्क WINAPI GetTextCharset(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI GetTextCharsetInfo(HDC hdc,LPFONTSIGNATURE lpSig,DWORD dwFlags);
  WINGDIAPI WINBOOL WINAPI TranslateCharsetInfo(DWORD *lpSrc,LPCHARSETINFO lpCs,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetFontLanguageInfo(HDC hdc);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementA(HDC hdc,LPCSTR lpString,पूर्णाङ्क n_गणनम्,पूर्णाङ्क nMexExtent,LPGCP_RESULTSA lpResults,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementW(HDC hdc,LPCWSTR lpString,पूर्णाङ्क n_गणनम्,पूर्णाङ्क nMexExtent,LPGCP_RESULTSW lpResults,DWORD dwFlags);

  प्रकारनिर्देश संरचना चिह्नकम्_WCRANGE {
    WCHAR wc_नीचः;
    USHORT cGlyphs;
  } WCRANGE,*PWCRANGE,*LPWCRANGE;

  प्रकारनिर्देश संरचना चिह्नकम्_GLYPHSET {
    DWORD cbThis;
    DWORD flAccel;
    DWORD cGlyphsSupported;
    DWORD cRanges;
    WCRANGE ranges[1];
  } GLYPHSET,*PGLYPHSET,*LPGLYPHSET;

#परिभाषय GS_8BIT_INDICES 0x00000001

#परिभाषय GGI_MARK_NONEXISTING_GLYPHS 0X0001

#यदि_परिभाषितम् UNICODE
#परिभाषय GetGlyphIndices GetGlyphIndicesW
#अन्यथा
#परिभाषय GetGlyphIndices GetGlyphIndicesA
#यदि_अन्तः

  WINGDIAPI DWORD WINAPI GetFontUnicodeRanges(HDC hdc,LPGLYPHSET lpgs);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesA(HDC hdc,LPCSTR lpstr,पूर्णाङ्क c,LPWORD pgi,DWORD fl);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesW(HDC hdc,LPCWSTR lpstr,पूर्णाङ्क c,LPWORD pgi,DWORD fl);
  WINGDIAPI WINBOOL WINAPI GetTextExtentPointI(HDC hdc,LPWORD pgi_अन्तर्,पूर्णाङ्क cgi,LPSIZE psize);
  WINGDIAPI WINBOOL WINAPI GetTextExtentExPointI (HDC hdc,LPWORD lpwszString,पूर्णाङ्क cwchString,पूर्णाङ्क nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_आकार);
  WINGDIAPI WINBOOL WINAPI Get_Char_विस्तारः_I(HDC hdc,UINT giFirst,UINT cgi,LPWORD pgi,LPINT piWidths);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsI(HDC hdc,UINT giFirst,UINT cgi,LPWORD pgi,LPABC pabc);

#परिभाषय STAMP_DESIGNVECTOR (0x8000000 + 'd' + ('v' << 8))
#परिभाषय STAMP_AXESLIST (0x8000000 + 'a' + ('l' << 8))
#परिभाषय MM_MAX_NUMAXES 16

  प्रकारनिर्देश संरचना चिह्नकम्_DESIGNVECTOR {
    DWORD dvReserved;
    DWORD dv_अङ्कः_Axes;
    LONG dv_मानानि[MM_MAX_NUMAXES];
  } DESIGNVECTOR,*PDESIGNVECTOR,*LPDESIGNVECTOR;

#यदि_परिभाषितम् UNICODE
#परिभाषय सङ्कलय_Font_Resource_Ex सङ्कलय_Font_Resource_Ex_W
#परिभाषय RemoveFontResourceEx RemoveFontResourceExW
#अन्यथा
#परिभाषय सङ्कलय_Font_Resource_Ex सङ्कलय_Font_Resource_Ex_A
#परिभाषय RemoveFontResourceEx RemoveFontResourceExA
#यदि_अन्तः

  WINGDIAPI पूर्णाङ्क WINAPI सङ्कलय_Font_Resource_Ex_A(LPCSTR name,DWORD fl,PVOID res);
  WINGDIAPI पूर्णाङ्क WINAPI सङ्कलय_Font_Resource_Ex_W(LPCWSTR name,DWORD fl,PVOID res);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExA(LPCSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExW(LPCWSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI HANDLE WINAPI सङ्कलय_Font_Mem_Resource_Ex(PVOID pFileView,DWORD cj_आकार,PVOID pvResrved,DWORD *p_अङ्कः_Fonts);
  WINGDIAPI WINBOOL WINAPI RemoveFontMemResourceEx(HANDLE h);

#परिभाषय FR_वैयक्तिकम् 0x10
#परिभाषय FR_NOT_ENUM 0x20

#परिभाषय MM_MAX_AXES_NAMELEN 16

  प्रकारनिर्देश संरचना चिह्नकम्_AXISINFOA {
    LONG ax_Min_मानम्;
    LONG ax_Max_मानम्;
    BYTE axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOA,*PAXISINFOA,*LPAXISINFOA;

  प्रकारनिर्देश संरचना चिह्नकम्_AXISINFOW {
    LONG ax_Min_मानम्;
    LONG ax_Max_मानम्;
    WCHAR axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOW,*PAXISINFOW,*LPAXISINFOW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश AXISINFOW AXISINFO;
  प्रकारनिर्देश PAXISINFOW PAXISINFO;
  प्रकारनिर्देश LPAXISINFOW LPAXISINFO;
#अन्यथा
  प्रकारनिर्देश AXISINFOA AXISINFO;
  प्रकारनिर्देश PAXISINFOA PAXISINFO;
  प्रकारनिर्देश LPAXISINFOA LPAXISINFO;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_AXESLISTA {
    DWORD axlReserved;
    DWORD axl_अङ्कः_Axes;
    AXISINFOA axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTA,*PAXESLISTA,*LPAXESLISTA;

  प्रकारनिर्देश संरचना चिह्नकम्_AXESLISTW {
    DWORD axlReserved;
    DWORD axl_अङ्कः_Axes;
    AXISINFOW axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTW,*PAXESLISTW,*LPAXESLISTW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश AXESLISTW AXESLIST;
  प्रकारनिर्देश PAXESLISTW PAXESLIST;
  प्रकारनिर्देश LPAXESLISTW LPAXESLIST;
#अन्यथा
  प्रकारनिर्देश AXESLISTA AXESLIST;
  प्रकारनिर्देश PAXESLISTA PAXESLIST;
  प्रकारनिर्देश LPAXESLISTA LPAXESLIST;
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_ENUMLOGFONTEXDVA {
    ENUMLOGFONTEXA elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_सदिशम्;
  } ENUMLOGFONTEXDVA,*PENUMLOGFONTEXDVA,*LPENUMLOGFONTEXDVA;

  प्रकारनिर्देश संरचना चिह्नकम्_ENUMLOGFONTEXDVW {
    ENUMLOGFONTEXW elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_सदिशम्;
  } ENUMLOGFONTEXDVW,*PENUMLOGFONTEXDVW,*LPENUMLOGFONTEXDVW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश ENUMLOGFONTEXDVW ENUMLOGFONTEXDV;
  प्रकारनिर्देश PENUMLOGFONTEXDVW PENUMLOGFONTEXDV;
  प्रकारनिर्देश LPENUMLOGFONTEXDVW LPENUMLOGFONTEXDV;
#अन्यथा
  प्रकारनिर्देश ENUMLOGFONTEXDVA ENUMLOGFONTEXDV;
  प्रकारनिर्देश PENUMLOGFONTEXDVA PENUMLOGFONTEXDV;
  प्रकारनिर्देश LPENUMLOGFONTEXDVA LPENUMLOGFONTEXDV;
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय Create_Font_परोक्षम्_Ex Create_Font_परोक्षम्_Ex_W
#अन्यथा
#परिभाषय Create_Font_परोक्षम्_Ex Create_Font_परोक्षम्_Ex_A
#यदि_अन्तः

  WINGDIAPI HFONT WINAPI Create_Font_परोक्षम्_Ex_A(CONST ENUMLOGFONTEXDVA *);
  WINGDIAPI HFONT WINAPI Create_Font_परोक्षम्_Ex_W(CONST ENUMLOGFONTEXDVW *);

#यदि_अपरिभाषितम् NOTEXTMETRIC
  प्रकारनिर्देश संरचना चिह्नकम्_ENUMTEXTMETRICA {
    NEWTEXTMETRICEXA etmNewTextMetricEx;
    AXESLISTA etmAxesList;
  } ENUMTEXTMETRICA,*PENUMTEXTMETRICA,*LPENUMTEXTMETRICA;
  प्रकारनिर्देश संरचना चिह्नकम्_ENUMTEXTMETRICW
  {
    NEWTEXTMETRICEXW etmNewTextMetricEx;
    AXESLISTW etmAxesList;
  } ENUMTEXTMETRICW,*PENUMTEXTMETRICW,*LPENUMTEXTMETRICW;
#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश ENUMTEXTMETRICW ENUMTEXTMETRIC;
  प्रकारनिर्देश PENUMTEXTMETRICW PENUMTEXTMETRIC;
  प्रकारनिर्देश LPENUMTEXTMETRICW LPENUMTEXTMETRIC;
#अन्यथा
  प्रकारनिर्देश ENUMTEXTMETRICA ENUMTEXTMETRIC;
  प्रकारनिर्देश PENUMTEXTMETRICA PENUMTEXTMETRIC;
  प्रकारनिर्देश LPENUMTEXTMETRICA LPENUMTEXTMETRIC;
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय ResetDC ResetDCW
#परिभाषय RemoveFontResource RemoveFontResourceW
#अन्यथा
#परिभाषय ResetDC ResetDCA
#परिभाषय RemoveFontResource RemoveFontResourceA
#यदि_अन्तः

  WINGDIAPI WINBOOL WINAPI GetViewportExtEx(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI GetViewportOrgEx(HDC hdc,LPPOINT lppoint);
  WINGDIAPI WINBOOL WINAPI Get_गवाक्षः_Ext_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI Get_गवाक्षः_Org_Ex(HDC hdc,LPPOINT lppoint);
  WINGDIAPI पूर्णाङ्क WINAPI IntersectClipRect(HDC hdc,पूर्णाङ्क वामः,पूर्णाङ्क शिखरम्,पूर्णाङ्क दक्षिणः,पूर्णाङ्क bottom);
  WINGDIAPI WINBOOL WINAPI InvertRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI पङ्क्तिः_DDA(पूर्णाङ्क xStart,पूर्णाङ्क yStart,पूर्णाङ्क x_अन्तः,पूर्णाङ्क y_अन्तः,LINEDDAPROC lpProc,LPARAM दत्त);
  WINGDIAPI WINBOOL WINAPI पङ्क्तिः_गन्तव्यम्(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y);
  WINGDIAPI WINBOOL WINAPI आवरणम्_Blt(HDC hdcDest,पूर्णाङ्क xDest,पूर्णाङ्क yDest,पूर्णाङ्क विस्तारः,पूर्णाङ्क height,HDC hdcSrc,पूर्णाङ्क xSrc,पूर्णाङ्क ySrc,HBITMAP hbm_आवरणम्,पूर्णाङ्क x_आवरणम्,पूर्णाङ्क y_आवरणम्,DWORD rop);
  WINGDIAPI WINBOOL WINAPI PlgBlt(HDC hdcDest,CONST POINT *lpPoint,HDC hdcSrc,पूर्णाङ्क xSrc,पूर्णाङ्क ySrc,पूर्णाङ्क विस्तारः,पूर्णाङ्क height,HBITMAP hbm_आवरणम्,पूर्णाङ्क x_आवरणम्,पूर्णाङ्क y_आवरणम्);
  WINGDIAPI पूर्णाङ्क WINAPI विस्थापनम्_Clip_Rgn(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y);
  WINGDIAPI पूर्णाङ्क WINAPI विस्थापनम्_Rgn(HRGN hrgn,पूर्णाङ्क x,पूर्णाङ्क y);
  WINGDIAPI WINBOOL WINAPI PatBlt(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,पूर्णाङ्क w,पूर्णाङ्क h,DWORD rop);
  WINGDIAPI WINBOOL WINAPI Pie(HDC hdc,पूर्णाङ्क वामः,पूर्णाङ्क शिखरम्,पूर्णाङ्क दक्षिणः,पूर्णाङ्क bottom,पूर्णाङ्क xr1,पूर्णाङ्क yr1,पूर्णाङ्क xr2,पूर्णाङ्क yr2);
  WINGDIAPI WINBOOL WINAPI PlayMetaFile(HDC hdc,HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI PaintRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI PolyPolygon(HDC hdc,CONST POINT *apt,CONST INT *asz,पूर्णाङ्क csz);
  WINGDIAPI WINBOOL WINAPI Pt_अन्तर्_Region(HRGN hrgn,पूर्णाङ्क x,पूर्णाङ्क y);
  WINGDIAPI WINBOOL WINAPI PtVisible(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y);
  WINGDIAPI WINBOOL WINAPI Rect_अन्तर्_Region(HRGN hrgn,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI RectVisible(HDC hdc,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Rectangle(HDC hdc,पूर्णाङ्क वामः,पूर्णाङ्क शिखरम्,पूर्णाङ्क दक्षिणः,पूर्णाङ्क bottom);
  WINGDIAPI WINBOOL WINAPI RestoreDC(HDC hdc,पूर्णाङ्क nSavedDC);
  WINGDIAPI HDC WINAPI ResetDCA(HDC hdc,CONST DEVMODEA *lpdm);
  WINGDIAPI HDC WINAPI ResetDCW(HDC hdc,CONST DEVMODEW *lpdm);
  WINGDIAPI UINT WINAPI RealizePalette(HDC hdc);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceA(LPCSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceW(LPCWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI आवर्तनम्_Rect(HDC hdc,पूर्णाङ्क वामः,पूर्णाङ्क शिखरम्,पूर्णाङ्क दक्षिणः,पूर्णाङ्क bottom,पूर्णाङ्क विस्तारः,पूर्णाङ्क height);
  WINGDIAPI WINBOOL WINAPI ResizePalette(HPALETTE hpal,UINT n);
  WINGDIAPI पूर्णाङ्क WINAPI SaveDC(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI SelectClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI पूर्णाङ्क WINAPI ExtSelectClipRgn(HDC hdc,HRGN hrgn,पूर्णाङ्क बहुलकम्);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_Meta_Rgn(HDC hdc);
  WINGDIAPI HGDIOBJ WINAPI SelectObject(HDC hdc,HGDIOBJ h);
  WINGDIAPI HPALETTE WINAPI SelectPalette(HDC hdc,HPALETTE hPal,WINBOOL bForceBkgd);
  WINGDIAPI COLORREF WINAPI समुच्चयः_Bk_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI समुच्चयः_DCBrush_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI समुच्चयः_DCPen_Color(HDC hdc,COLORREF color);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_Bk_बहुलकम्(HDC hdc,पूर्णाङ्क बहुलकम्);
  WINGDIAPI LONG WINAPI समुच्चयः_Bitmap_द्वयङ्काः(HBITMAP hbm,DWORD cb,CONST VOID *pv_द्वयङ्काः);
  WINGDIAPI UINT WINAPI समुच्चयः_Bounds_Rect(HDC hdc,CONST RECT *lprect,UINT flags);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_DIBits(HDC hdc,HBITMAP hbm,UINT start,UINT c_पङ्क्तयः,CONST VOID *lp_द्वयङ्काः,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_DIBits_गन्तव्यम्_Device(HDC hdc,पूर्णाङ्क xDest,पूर्णाङ्क yDest,DWORD w,DWORD h,पूर्णाङ्क xSrc,पूर्णाङ्क ySrc,UINT Start_अवलोकनम्,UINT c_पङ्क्तयः,CONST VOID *lpv_द्वयङ्काः,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI DWORD WINAPI समुच्चयः_Mapper_Flags(HDC hdc,DWORD flags);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_Graphics_बहुलकम्(HDC hdc,पूर्णाङ्क i_बहुलकम्);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_Map_बहुलकम्(HDC hdc,पूर्णाङ्क i_बहुलकम्);
  WINGDIAPI DWORD WINAPI समुच्चयः_Layout(HDC hdc,DWORD l);
  WINGDIAPI DWORD WINAPI GetLayout(HDC hdc);
  WINGDIAPI HMETAFILE WINAPI समुच्चयः_Meta_File_द्वयङ्काः_Ex(UINT cb_बफर,CONST BYTE *lp_दत्त);
  WINGDIAPI UINT WINAPI समुच्चयः_Palette_Entries(HPALETTE hpal,UINT iStart,UINT cEntries,CONST PALETTEENTRY *pPalEntries);
  WINGDIAPI COLORREF WINAPI समुच्चयः_Pixel(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Pixel_V(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Pixel_Format(HDC hdc,पूर्णाङ्क format,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_Poly_Fill_बहुलकम्(HDC hdc,पूर्णाङ्क बहुलकम्);
  WINGDIAPI WINBOOL WINAPI StretchBlt(HDC hdcDest,पूर्णाङ्क xDest,पूर्णाङ्क yDest,पूर्णाङ्क wDest,पूर्णाङ्क hDest,HDC hdcSrc,पूर्णाङ्क xSrc,पूर्णाङ्क ySrc,पूर्णाङ्क wSrc,पूर्णाङ्क hSrc,DWORD rop);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Rect_Rgn(HRGN hrgn,पूर्णाङ्क वामः,पूर्णाङ्क शिखरम्,पूर्णाङ्क दक्षिणः,पूर्णाङ्क bottom);
  WINGDIAPI पूर्णाङ्क WINAPI StretchDIBits(HDC hdc,पूर्णाङ्क xDest,पूर्णाङ्क yDest,पूर्णाङ्क Dest_विस्तारः,पूर्णाङ्क DestHeight,पूर्णाङ्क xSrc,पूर्णाङ्क ySrc,पूर्णाङ्क Src_विस्तारः,पूर्णाङ्क SrcHeight,CONST VOID *lp_द्वयङ्काः,CONST BITMAPINFO *lpbmi,UINT iUsage,DWORD rop);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_ROP2(HDC hdc,पूर्णाङ्क rop2);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_Stretch_Blt_बहुलकम्(HDC hdc,पूर्णाङ्क बहुलकम्);
  WINGDIAPI UINT WINAPI समुच्चयः_System_Palette_Use(HDC hdc,UINT use);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_Text_Character_Extra(HDC hdc,पूर्णाङ्क extra);
  WINGDIAPI COLORREF WINAPI समुच्चयः_Text_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI समुच्चयः_Text_Align(HDC hdc,UINT align);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Text_Justification(HDC hdc,पूर्णाङ्क extra,पूर्णाङ्क गणनम्_2);
  WINGDIAPI WINBOOL WINAPI UpdateColors(HDC hdc);

  प्रकारनिर्देश USHORT COLOR16;

  प्रकारनिर्देश संरचना _TRIVERTEX {
    LONG x;
    LONG y;
    COLOR16 Red;
    COLOR16 Green;
    COLOR16 Blue;
    COLOR16 Alpha;
  } TRIVERTEX,*PTRIVERTEX,*LPTRIVERTEX;

  प्रकारनिर्देश संरचना _GRADIENT_TRIANGLE {
    ULONG Vertex1;
    ULONG Vertex2;
    ULONG Vertex3;
  } GRADIENT_TRIANGLE,*PGRADIENT_TRIANGLE,*LPGRADIENT_TRIANGLE;

  प्रकारनिर्देश संरचना _GRADIENT_RECT {
    ULONG ऊर्ध्वस्थम्_वामः;
    ULONG अधस्तनम्_दक्षिणः;
  } GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;

  प्रकारनिर्देश संरचना _BLENDFUNCTION {
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE SourceConstantAlpha;
    BYTE AlphaFormat;
  } BLENDFUNCTION,*PBLENDFUNCTION;

#परिभाषय AC_SRC_OVER 0x00
#परिभाषय AC_SRC_ALPHA 0x01

  WINGDIAPI WINBOOL WINAPI AlphaBlend(HDC hdcDest,पूर्णाङ्क xoriginDest,पूर्णाङ्क yoriginDest,पूर्णाङ्क wDest,पूर्णाङ्क hDest,HDC hdcSrc,पूर्णाङ्क xoriginSrc,पूर्णाङ्क yoriginSrc,पूर्णाङ्क wSrc,पूर्णाङ्क hSrc,BLENDFUNCTION ftn);
  WINGDIAPI WINBOOL WINAPI TransparentBlt(HDC hdcDest,पूर्णाङ्क xoriginDest,पूर्णाङ्क yoriginDest,पूर्णाङ्क wDest,पूर्णाङ्क hDest,HDC hdcSrc,पूर्णाङ्क xoriginSrc,पूर्णाङ्क yoriginSrc,पूर्णाङ्क wSrc,पूर्णाङ्क hSrc,UINT crTransparent);

#परिभाषय GRADIENT_FILL_RECT_H 0x00000000
#परिभाषय GRADIENT_FILL_RECT_V 0x00000001
#परिभाषय GRADIENT_FILL_TRIANGLE 0x00000002
#परिभाषय GRADIENT_FILL_OP_FLAG 0x000000ff

  WINGDIAPI WINBOOL WINAPI GradientFill(HDC hdc,PTRIVERTEX pVertex,ULONG nVertex,PVOID pMesh,ULONG nMesh,ULONG ul_बहुलकम्);

#यदि_अपरिभाषितम् NOMETAFILE

#यदि_परिभाषितम् UNICODE
#परिभाषय CopyEnhMetaFile CopyEnhMetaFileW
#परिभाषय CreateEnhMetaFile CreateEnhMetaFileW
#परिभाषय GetEnhMetaFile GetEnhMetaFileW
#परिभाषय GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#अन्यथा
#परिभाषय CopyEnhMetaFile CopyEnhMetaFileA
#परिभाषय CreateEnhMetaFile CreateEnhMetaFileA
#परिभाषय GetEnhMetaFile GetEnhMetaFileA
#परिभाषय GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#यदि_अन्तः

  WINGDIAPI WINBOOL WINAPI Play_Meta_File_लेखः(HDC hdc,LPHANDLETABLE lp_Handle_सारणी,LPMETARECORD lpMR,UINT noObjs);

  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *MFENUMPROC)(HDC hdc,HANDLETABLE *lpht,METARECORD *lpMR,पूर्णाङ्क nObj,LPARAM param);

  WINGDIAPI WINBOOL WINAPI EnumMetaFile(HDC hdc,HMETAFILE hmf,MFENUMPROC proc,LPARAM param);

  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *ENHMFENUMPROC)(HDC hdc,HANDLETABLE *lpht,CONST ENHMETARECORD *lpmr,पूर्णाङ्क hHandles,LPARAM दत्त);

  WINGDIAPI HENHMETAFILE WINAPI CloseEnhMetaFile(HDC hdc);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileA(HENHMETAFILE hEnh,LPCSTR lpFileName);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileW(HENHMETAFILE hEnh,LPCWSTR lpFileName);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileA(HDC hdc,LPCSTR lpFilename,CONST RECT *lprc,LPCSTR lpDesc);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileW(HDC hdc,LPCWSTR lpFilename,CONST RECT *lprc,LPCWSTR lpDesc);
  WINGDIAPI WINBOOL WINAPI DeleteEnhMetaFile(HENHMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI EnumEnhMetaFile(HDC hdc,HENHMETAFILE hmf,ENHMFENUMPROC proc,LPVOID param,CONST RECT *lpRect);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileA(LPCSTR lpName);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileW(LPCWSTR lpName);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_द्वयङ्काः(HENHMETAFILE hEMF,UINT n_आकार,LPBYTE lp_दत्त);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE hemf,UINT cch_बफर,LPSTR lpDescription);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE hemf,UINT cch_बफर,LPWSTR lpDescription);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_शीर्षकम्(HENHMETAFILE hemf,UINT n_आकार,LPENHMETAHEADER lp_Enh_Meta_शीर्षकम्);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT n_अङ्कः_Entries,LPPALETTEENTRY lpPaletteEntries);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePixelFormat(HENHMETAFILE hemf,UINT cb_बफर,PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI UINT WINAPI Get_Win_Meta_File_द्वयङ्काः(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT i_Map_बहुलकम्,HDC hdcRef);
  WINGDIAPI WINBOOL WINAPI PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Play_Enh_Meta_File_लेखः(HDC hdc,LPHANDLETABLE pht,CONST ENHMETARECORD *pmr,UINT cht);
  WINGDIAPI HENHMETAFILE WINAPI समुच्चयः_Enh_Meta_File_द्वयङ्काः(UINT n_आकार,CONST BYTE *pb);
  WINGDIAPI HENHMETAFILE WINAPI समुच्चयः_Win_Meta_File_द्वयङ्काः(UINT n_आकार,CONST BYTE *lp_Meta16_दत्त,HDC hdcRef,CONST METAFILEPICT *lpMFP);
  WINGDIAPI WINBOOL WINAPI GdiComment(HDC hdc,UINT n_आकार,CONST BYTE *lp_दत्त);
#यदि_अन्तः

#यदि_अपरिभाषितम् NOTEXTMETRIC
#यदि_परिभाषितम् UNICODE
#परिभाषय GetTextMetrics GetTextMetricsW
#अन्यथा
#परिभाषय GetTextMetrics GetTextMetricsA
#यदि_अन्तः

  WINGDIAPI WINBOOL WINAPI GetTextMetricsA(HDC hdc,LPTEXTMETRICA lptm);
  WINGDIAPI WINBOOL WINAPI GetTextMetricsW(HDC hdc,LPTEXTMETRICW lptm);
#यदि_अन्तः

  प्रकारनिर्देश संरचना चिह्नकम्_DIBSECTION {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD ds_विस्थापनम्;
  } DIBSECTION,*LPDIBSECTION,*PDIBSECTION;

  WINGDIAPI WINBOOL WINAPI AngleArc(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,DWORD r,FLOAT StartAngle,FLOAT SweepAngle);
  WINGDIAPI WINBOOL WINAPI PolyPolyline(HDC hdc,CONST POINT *apt,CONST DWORD *asz,DWORD csz);
  WINGDIAPI WINBOOL WINAPI GetWorldTransform(HDC hdc,LPXFORM lpxf);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_World_Transform(HDC hdc,CONST XFORM *lpxf);
  WINGDIAPI WINBOOL WINAPI ModifyWorldTransform(HDC hdc,CONST XFORM *lpxf,DWORD बहुलकम्);
  WINGDIAPI WINBOOL WINAPI CombineTransform(LPXFORM lpxf_बहिर्गमनम्,CONST XFORM *lpxf1,CONST XFORM *lpxf2);
  WINGDIAPI HBITMAP WINAPI CreateDIBSection(HDC hdc,CONST BITMAPINFO *lpbmi,UINT usage,VOID **ppv_द्वयङ्काः,HANDLE hSection,DWORD विस्थापनम्);
  WINGDIAPI UINT WINAPI Get_DIBColor_सारणी(HDC hdc,UINT iStart,UINT cEntries,RGBQUAD *prgbq);
  WINGDIAPI UINT WINAPI समुच्चयः_DIBColor_सारणी(HDC hdc,UINT iStart,UINT cEntries,CONST RGBQUAD *prgbq);

#परिभाषय CA_NEGATIVE 0x0001
#परिभाषय CA_LOG_FILTER 0x0002

#परिभाषय ILLUMINANT_DEVICE_DEFAULT 0
#परिभाषय ILLUMINANT_A 1
#परिभाषय ILLUMINANT_B 2
#परिभाषय ILLUMINANT_C 3
#परिभाषय ILLUMINANT_D50 4
#परिभाषय ILLUMINANT_D55 5
#परिभाषय ILLUMINANT_D65 6
#परिभाषय ILLUMINANT_D75 7
#परिभाषय ILLUMINANT_F2 8
#परिभाषय ILLUMINANT_MAX_सूचकांक ILLUMINANT_F2

#परिभाषय ILLUMINANT_TUNGSTEN ILLUMINANT_A
#परिभाषय ILLUMINANT_DAYLIGHT ILLUMINANT_C
#परिभाषय ILLUMINANT_FLUORESCENT ILLUMINANT_F2
#परिभाषय ILLUMINANT_NTSC ILLUMINANT_C

#परिभाषय RGB_GAMMA_MIN (WORD)02500
#परिभाषय RGB_GAMMA_MAX (WORD)65000

#परिभाषय REFERENCE_WHITE_MIN (WORD)6000
#परिभाषय REFERENCE_WHITE_MAX (WORD)10000
#परिभाषय REFERENCE_BLACK_MIN (WORD)0
#परिभाषय REFERENCE_BLACK_MAX (WORD)4000

#परिभाषय COLOR_ADJ_MIN (SHORT)-100
#परिभाषय COLOR_ADJ_MAX (SHORT)100

  प्रकारनिर्देश संरचना चिह्नकम्_COLORADJUSTMENT {
    WORD ca_आकार;
    WORD caFlags;
    WORD ca_Illuminant_सूचकांक;
    WORD caRedGamma;
    WORD caGreenGamma;
    WORD caBlueGamma;
    WORD caReferenceBlack;
    WORD caReferenceWhite;
    SHORT caContrast;
    SHORT caBrightness;
    SHORT caColorfulness;
    SHORT caRedGreenTint;
  } COLORADJUSTMENT,*PCOLORADJUSTMENT,*LPCOLORADJUSTMENT;

  WINGDIAPI WINBOOL WINAPI समुच्चयः_Color_Adjustment(HDC hdc,CONST COLORADJUSTMENT *lpca);
  WINGDIAPI WINBOOL WINAPI GetColorAdjustment(HDC hdc,LPCOLORADJUSTMENT lpca);
  WINGDIAPI HPALETTE WINAPI CreateHalftonePalette(HDC hdc);

  प्रकारनिर्देश WINBOOL (CALLBACK *ABORTPROC)(HDC,पूर्णाङ्क);

  प्रकारनिर्देश संरचना _DOCINFOA {
    पूर्णाङ्क cb_आकार;
    LPCSTR lpszDocName;
    LPCSTR lpszOutput;
    LPCSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOA,*LPDOCINFOA;

  प्रकारनिर्देश संरचना _DOCINFOW {
    पूर्णाङ्क cb_आकार;
    LPCWSTR lpszDocName;
    LPCWSTR lpszOutput;
    LPCWSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOW,*LPDOCINFOW;

#यदि_परिभाषितम् UNICODE
  प्रकारनिर्देश DOCINFOW DOCINFO;
  प्रकारनिर्देश LPDOCINFOW LPDOCINFO;
#अन्यथा
  प्रकारनिर्देश DOCINFOA DOCINFO;
  प्रकारनिर्देश LPDOCINFOA LPDOCINFO;
#यदि_अन्तः

#परिभाषय DI_APPBANDING 0x00000001
#परिभाषय DI_ROPS_READ_DESTINATION 0x00000002

#यदि_परिभाषितम् UNICODE
#परिभाषय StartDoc StartDocW
#परिभाषय GetObject GetObjectW
#परिभाषय Text_बहिर्गमनम् Text_बहिर्गमनम्_W
#परिभाषय Ext_Text_बहिर्गमनम् Ext_Text_बहिर्गमनम्_W
#परिभाषय Poly_Text_बहिर्गमनम् Poly_Text_बहिर्गमनम्_W
#परिभाषय GetTextFace GetTextFaceW
#अन्यथा
#परिभाषय StartDoc StartDocA
#परिभाषय GetObject GetObjectA
#परिभाषय Text_बहिर्गमनम् Text_बहिर्गमनम्_A
#परिभाषय Ext_Text_बहिर्गमनम् Ext_Text_बहिर्गमनम्_A
#परिभाषय Poly_Text_बहिर्गमनम् Poly_Text_बहिर्गमनम्_A
#परिभाषय GetTextFace GetTextFaceA
#यदि_अन्तः

  WINGDIAPI पूर्णाङ्क WINAPI StartDocA(HDC hdc,CONST DOCINFOA *lpdi);
  WINGDIAPI पूर्णाङ्क WINAPI StartDocW(HDC hdc,CONST DOCINFOW *lpdi);
  WINGDIAPI पूर्णाङ्क WINAPI अन्तः_Doc(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI StartPage(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI अन्तः_Page(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI AbortDoc(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_Abort_Proc(HDC hdc,ABORTPROC proc);
  WINGDIAPI WINBOOL WINAPI Abort_मार्गः(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Arc_गन्तव्यम्(HDC hdc,पूर्णाङ्क वामः,पूर्णाङ्क शिखरम्,पूर्णाङ्क दक्षिणः,पूर्णाङ्क bottom,पूर्णाङ्क xr1,पूर्णाङ्क yr1,पूर्णाङ्क xr2,पूर्णाङ्क yr2);
  WINGDIAPI WINBOOL WINAPI Begin_मार्गः(HDC hdc);
  WINGDIAPI WINBOOL WINAPI CloseFigure(HDC hdc);
  WINGDIAPI WINBOOL WINAPI अन्तः_मार्गः_2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Fill_मार्गः(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Flatten_मार्गः(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI Get_मार्गः(HDC hdc,LPPOINT apt,LPBYTE aj,पूर्णाङ्क cpt);
  WINGDIAPI HRGN WINAPI मार्गः_गन्तव्यम्_Region(HDC hdc);
  WINGDIAPI WINBOOL WINAPI PolyDraw(HDC hdc,CONST POINT *apt,CONST BYTE *aj,पूर्णाङ्क cpt);
  WINGDIAPI WINBOOL WINAPI Select_Clip_मार्गः(HDC hdc,पूर्णाङ्क बहुलकम्);
  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_Arc_Direction(HDC hdc,पूर्णाङ्क dir);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Miter_सीमा(HDC hdc,FLOAT सीमा,PFLOAT old);
  WINGDIAPI WINBOOL WINAPI Stroke_And_Fill_मार्गः(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Stroke_मार्गः(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Widen_मार्गः(HDC hdc);
  WINGDIAPI HPEN WINAPI ExtCreatePen(DWORD iPenStyle,DWORD c_विस्तारः,CONST LOGBRUSH *plbrush,DWORD cStyle,CONST DWORD *pstyle);
  WINGDIAPI WINBOOL WINAPI Get_Miter_सीमा(HDC hdc,PFLOAT plimit);
  WINGDIAPI पूर्णाङ्क WINAPI GetArcDirection(HDC hdc);
  WINGDIAPI पूर्णाङ्क WINAPI GetObjectA(HANDLE h,पूर्णाङ्क c,LPVOID pv);
  WINGDIAPI पूर्णाङ्क WINAPI GetObjectW(HANDLE h,पूर्णाङ्क c,LPVOID pv);
  WINGDIAPI WINBOOL WINAPI Move_गन्तव्यम्_Ex(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI Text_बहिर्गमनम्_A(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPCSTR lpString,पूर्णाङ्क c);
  WINGDIAPI WINBOOL WINAPI Text_बहिर्गमनम्_W(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPCWSTR lpString,पूर्णाङ्क c);
  WINGDIAPI WINBOOL WINAPI Ext_Text_बहिर्गमनम्_A(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,UINT options,CONST RECT *lprect,LPCSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Ext_Text_बहिर्गमनम्_W(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,UINT options,CONST RECT *lprect,LPCWSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Poly_Text_बहिर्गमनम्_A(HDC hdc,CONST POLYTEXTA *ppt,पूर्णाङ्क nstrings);
  WINGDIAPI WINBOOL WINAPI Poly_Text_बहिर्गमनम्_W(HDC hdc,CONST POLYTEXTW *ppt,पूर्णाङ्क nstrings);
  WINGDIAPI HRGN WINAPI CreatePolygonRgn(CONST POINT *pptl,पूर्णाङ्क cPoint,पूर्णाङ्क i_बहुलकम्);
  WINGDIAPI WINBOOL WINAPI DPtoLP(HDC hdc,LPPOINT lppt,पूर्णाङ्क c);
  WINGDIAPI WINBOOL WINAPI LPtoDP(HDC hdc,LPPOINT lppt,पूर्णाङ्क c);
  WINGDIAPI WINBOOL WINAPI Polygon(HDC hdc,CONST POINT *apt,पूर्णाङ्क cpt);
  WINGDIAPI WINBOOL WINAPI Polyline(HDC hdc,CONST POINT *apt,पूर्णाङ्क cpt);
  WINGDIAPI WINBOOL WINAPI PolyBezier(HDC hdc,CONST POINT *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Poly_Bezier_गन्तव्यम्(HDC hdc,CONST POINT *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Polyline_गन्तव्यम्(HDC hdc,CONST POINT *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Viewport_Ext_Ex(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Viewport_Org_Ex(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_गवाक्षः_Ext_Ex(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_गवाक्षः_Org_Ex(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI विस्थापनम्_Viewport_Org_Ex(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI विस्थापनम्_गवाक्षः_Org_Ex(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ScaleViewportExtEx(HDC hdc,पूर्णाङ्क xn,पूर्णाङ्क dx,पूर्णाङ्क yn,पूर्णाङ्क yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Scale_गवाक्षः_Ext_Ex(HDC hdc,पूर्णाङ्क xn,पूर्णाङ्क xd,पूर्णाङ्क yn,पूर्णाङ्क yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Bitmap_Dimension_Ex(HBITMAP hbm,पूर्णाङ्क w,पूर्णाङ्क h,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Brush_Org_Ex(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPPOINT lppt);
  WINGDIAPI पूर्णाङ्क WINAPI GetTextFaceA(HDC hdc,पूर्णाङ्क c,LPSTR lpName);
  WINGDIAPI पूर्णाङ्क WINAPI GetTextFaceW(HDC hdc,पूर्णाङ्क c,LPWSTR lpName);

#परिभाषय FONTMAPPER_MAX 10

  प्रकारनिर्देश संरचना चिह्नकम्_KERNINGPAIR {
    WORD wFirst;
    WORD wSecond;
    पूर्णाङ्क iKernAmount;
  } KERNINGPAIR,*LPKERNINGPAIR;

#यदि_परिभाषितम् UNICODE
#परिभाषय Get_Kerning_युग्मानि Get_Kerning_युग्मानि_W
#अन्यथा
#परिभाषय Get_Kerning_युग्मानि Get_Kerning_युग्मानि_A
#यदि_अन्तः

  WINGDIAPI DWORD WINAPI Get_Kerning_युग्मानि_A(HDC hdc,DWORD n_युग्मानि,LPKERNINGPAIR lpKernPair);
  WINGDIAPI DWORD WINAPI Get_Kerning_युग्मानि_W(HDC hdc,DWORD n_युग्मानि,LPKERNINGPAIR lpKernPair);
  WINGDIAPI WINBOOL WINAPI GetDCOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI FixBrushOrgEx(HDC hdc,पूर्णाङ्क x,पूर्णाङ्क y,LPPOINT ptl);
  WINGDIAPI WINBOOL WINAPI UnrealizeObject(HGDIOBJ h);
  WINGDIAPI WINBOOL WINAPI GdiFlush();
  WINGDIAPI DWORD WINAPI Gdi_समुच्चयः_Batch_सीमा(DWORD dw);
  WINGDIAPI DWORD WINAPI Gdi_Get_Batch_सीमा();

#परिभाषय ICM_OFF 1
#परिभाषय ICM_ON 2
#परिभाषय ICM_QUERY 3
#परिभाषय ICM_समाप्तम्_OUTSIDEDC 4

  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *ICMENUMPROCA)(LPSTR,LPARAM);
  प्रकारनिर्देश पूर्णाङ्क (CALLBACK *ICMENUMPROCW)(LPWSTR,LPARAM);

#यदि_परिभाषितम् UNICODE
#परिभाषय ICMENUMPROC ICMENUMPROCW
#परिभाषय EnumICMProfiles EnumICMProfilesW
#परिभाषय Update_ICMReg_कुञ्चिका Update_ICMReg_कुञ्चिका_W
#परिभाषय GetLogColorSpace GetLogColorSpaceW
#परिभाषय CreateColorSpace CreateColorSpaceW
#परिभाषय GetICMProfile GetICMProfileW
#परिभाषय समुच्चयः_ICMProfile समुच्चयः_ICMProfile_W
#अन्यथा
#परिभाषय ICMENUMPROC ICMENUMPROCA
#परिभाषय EnumICMProfiles EnumICMProfilesA
#परिभाषय Update_ICMReg_कुञ्चिका Update_ICMReg_कुञ्चिका_A
#परिभाषय GetLogColorSpace GetLogColorSpaceA
#परिभाषय CreateColorSpace CreateColorSpaceA
#परिभाषय GetICMProfile GetICMProfileA
#परिभाषय समुच्चयः_ICMProfile समुच्चयः_ICMProfile_A
#यदि_अन्तः

  WINGDIAPI पूर्णाङ्क WINAPI समुच्चयः_ICMMode(HDC hdc,पूर्णाङ्क बहुलकम्);
  WINGDIAPI WINBOOL WINAPI Check_Colors_अन्तर्_Gamut(HDC hdc,LPVOID lpRGBTriple,LPVOID dlp_बफर,DWORD n_गणनम्);
  WINGDIAPI HCOLORSPACE WINAPI GetColorSpace(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceA(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEA lp_बफर,DWORD n_आकार);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceW(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEW lp_बफर,DWORD n_आकार);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA lplcs);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW lplcs);
  WINGDIAPI HCOLORSPACE WINAPI समुच्चयः_Color_Space(HDC hdc,HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI DeleteColorSpace(HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI GetICMProfileA(HDC hdc,LPDWORD p_Buf_आकार,LPSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI GetICMProfileW(HDC hdc,LPDWORD p_Buf_आकार,LPWSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_ICMProfile_A(HDC hdc,LPSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_ICMProfile_W(HDC hdc,LPWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI GetDeviceGammaRamp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI समुच्चयः_Device_Gamma_Ramp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI Color_मेलनम्_गन्तव्यम्_Target(HDC hdc,HDC hdcTarget,DWORD action);
  WINGDIAPI पूर्णाङ्क WINAPI EnumICMProfilesA(HDC hdc,ICMENUMPROCA proc,LPARAM param);
  WINGDIAPI पूर्णाङ्क WINAPI EnumICMProfilesW(HDC hdc,ICMENUMPROCW proc,LPARAM param);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_कुञ्चिका_A(DWORD reserved,LPSTR lpszCMID,LPSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_कुञ्चिका_W(DWORD reserved,LPWSTR lpszCMID,LPWSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI ColorCorrectPalette(HDC hdc,HPALETTE hPal,DWORD deFirst,DWORD अङ्कः);

#यदि_अपरिभाषितम् NOMETAFILE

#परिभाषय ENHMETA_SIGNATURE 0x464D4520
#परिभाषय ENHMETA_STOCK_OBJECT 0x80000000

#परिभाषय EMR_शीर्षकम् 1
#परिभाषय EMR_POLYBEZIER 2
#परिभाषय EMR_POLYGON 3
#परिभाषय EMR_POLYLINE 4
#परिभाषय EMR_POLYBEZIERTO 5
#परिभाषय EMR_POLYLINETO 6
#परिभाषय EMR_POLYPOLYLINE 7
#परिभाषय EMR_POLYPOLYGON 8
#परिभाषय EMR_SETWINDOWEXTEX 9
#परिभाषय EMR_SETWINDOWORGEX 10
#परिभाषय EMR_SETVIEWPORTEXTEX 11
#परिभाषय EMR_SETVIEWPORTORGEX 12
#परिभाषय EMR_SETBRUSHORGEX 13
#परिभाषय EMR_EOF 14
#परिभाषय EMR_SETPIXELV 15
#परिभाषय EMR_SETMAPPERFLAGS 16
#परिभाषय EMR_SETMAPMODE 17
#परिभाषय EMR_SETBKMODE 18
#परिभाषय EMR_SETPOLYFILLMODE 19
#परिभाषय EMR_SETROP2 20
#परिभाषय EMR_SETSTRETCHBLTMODE 21
#परिभाषय EMR_SETTEXTALIGN 22
#परिभाषय EMR_SETCOLORADJUSTMENT 23
#परिभाषय EMR_SETTEXTCOLOR 24
#परिभाषय EMR_SETBKCOLOR 25
#परिभाषय EMR_OFFSETCLIPRGN 26
#परिभाषय EMR_MOVETOEX 27
#परिभाषय EMR_SETMETARGN 28
#परिभाषय EMR_EXCLUDECLIPRECT 29
#परिभाषय EMR_INTERSECTCLIPRECT 30
#परिभाषय EMR_SCALEVIEWPORTEXTEX 31
#परिभाषय EMR_SCALEWINDOWEXTEX 32
#परिभाषय EMR_SAVEDC 33
#परिभाषय EMR_RESTOREDC 34
#परिभाषय EMR_SETWORLDTRANSFORM 35
#परिभाषय EMR_MODIFYWORLDTRANSFORM 36
#परिभाषय EMR_SELECTOBJECT 37
#परिभाषय EMR_CREATEPEN 38
#परिभाषय EMR_CREATEBRUSHINDIRECT 39
#परिभाषय EMR_DELETEOBJECT 40
#परिभाषय EMR_ANGLEARC 41
#परिभाषय EMR_ELLIPSE 42
#परिभाषय EMR_RECTANGLE 43
#परिभाषय EMR_ROUNDRECT 44
#परिभाषय EMR_ARC 45
#परिभाषय EMR_CHORD 46
#परिभाषय EMR_PIE 47
#परिभाषय EMR_SELECTPALETTE 48
#परिभाषय EMR_CREATEPALETTE 49
#परिभाषय EMR_SETPALETTEENTRIES 50
#परिभाषय EMR_RESIZEPALETTE 51
#परिभाषय EMR_REALIZEPALETTE 52
#परिभाषय EMR_EXTFLOODFILL 53
#परिभाषय EMR_LINETO 54
#परिभाषय EMR_ARCTO 55
#परिभाषय EMR_POLYDRAW 56
#परिभाषय EMR_SETARCDIRECTION 57
#परिभाषय EMR_SETMITERLIMIT 58
#परिभाषय EMR_BEGINPATH 59
#परिभाषय EMR_ENDPATH 60
#परिभाषय EMR_CLOSEFIGURE 61
#परिभाषय EMR_FILLPATH 62
#परिभाषय EMR_STROKEANDFILLPATH 63
#परिभाषय EMR_STROKEPATH 64
#परिभाषय EMR_FLATTENPATH 65
#परिभाषय EMR_WIDENPATH 66
#परिभाषय EMR_SELECTCLIPPATH 67
#परिभाषय EMR_ABORTPATH 68

#परिभाषय EMR_GDICOMMENT 70
#परिभाषय EMR_FILLRGN 71
#परिभाषय EMR_FRAMERGN 72
#परिभाषय EMR_INVERTRGN 73
#परिभाषय EMR_PAINTRGN 74
#परिभाषय EMR_EXTSELECTCLIPRGN 75
#परिभाषय EMR_BITBLT 76
#परिभाषय EMR_STRETCHBLT 77
#परिभाषय EMR_MASKBLT 78
#परिभाषय EMR_PLGBLT 79
#परिभाषय EMR_SETDIBITSTODEVICE 80
#परिभाषय EMR_STRETCHDIBITS 81
#परिभाषय EMR_EXTCREATEFONTINDIRECTW 82
#परिभाषय EMR_EXTTEXTOUTA 83
#परिभाषय EMR_EXTTEXTOUTW 84
#परिभाषय EMR_POLYBEZIER16 85
#परिभाषय EMR_POLYGON16 86
#परिभाषय EMR_POLYLINE16 87
#परिभाषय EMR_POLYBEZIERTO16 88
#परिभाषय EMR_POLYLINETO16 89
#परिभाषय EMR_POLYPOLYLINE16 90
#परिभाषय EMR_POLYPOLYGON16 91
#परिभाषय EMR_POLYDRAW16 92
#परिभाषय EMR_CREATEMONOBRUSH 93
#परिभाषय EMR_CREATEDIBPATTERNBRUSHPT 94
#परिभाषय EMR_EXTCREATEPEN 95
#परिभाषय EMR_POLYTEXTOUTA 96
#परिभाषय EMR_POLYTEXTOUTW 97

#परिभाषय EMR_SETICMMODE 98
#परिभाषय EMR_CREATECOLORSPACE 99
#परिभाषय EMR_SETCOLORSPACE 100
#परिभाषय EMR_DELETECOLORSPACE 101
#परिभाषय EMR_GLSRECORD 102
#परिभाषय EMR_GLSBOUNDEDRECORD 103
#परिभाषय EMR_PIXELFORMAT 104
#परिभाषय EMR_RESERVED_105 105
#परिभाषय EMR_RESERVED_106 106
#परिभाषय EMR_RESERVED_107 107
#परिभाषय EMR_RESERVED_108 108
#परिभाषय EMR_RESERVED_109 109
#परिभाषय EMR_RESERVED_110 110
#परिभाषय EMR_COLORCORRECTPALETTE 111
#परिभाषय EMR_SETICMPROFILEA 112
#परिभाषय EMR_SETICMPROFILEW 113
#परिभाषय EMR_ALPHABLEND 114
#परिभाषय EMR_SETLAYOUT 115
#परिभाषय EMR_TRANSPARENTBLT 116
#परिभाषय EMR_RESERVED_117 117
#परिभाषय EMR_GRADIENTFILL 118
#परिभाषय EMR_RESERVED_119 119
#परिभाषय EMR_RESERVED_120 120
#परिभाषय EMR_COLORMATCHTOTARGETW 121
#परिभाषय EMR_CREATECOLORSPACEW 122

#परिभाषय EMR_MIN 1

#परिभाषय EMR_MAX 122

  प्रकारनिर्देश संरचना चिह्नकम्_EMR {
    DWORD iType;
    DWORD n_आकार;
  } EMR,*PEMR;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRTEXT {
    POINTL ptlReference;
    DWORD nChars;
    DWORD offString;
    DWORD fOptions;
    RECTL rcl;
    DWORD offDx;
  } EMRTEXT,*PEMRTEXT;

  प्रकारनिर्देश संरचना चिह्नकम्_ABORTPATH {
    EMR emr;
  } EMRABORTPATH,*PEMRABORTPATH,EMRBEGINPATH,*PEMRBEGINPATH,EMRENDPATH,*PEMRENDPATH,EMRCLOSEFIGURE,*PEMRCLOSEFIGURE,EMRFLATTENPATH,*PEMRFLATTENPATH,EMRWIDENPATH,*PEMRWIDENPATH,EMRSETMETARGN,*PEMRSETMETARGN,EMRSAVEDC,*PEMRSAVEDC,EMRREALIZEPALETTE,*PEMRREALIZEPALETTE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSELECTCLIPPATH {
    EMR emr;
    DWORD i_बहुलकम्;
  } EMRSELECTCLIPPATH,*PEMRSELECTCLIPPATH,EMRSETBKMODE,*PEMRSETBKMODE,EMRSETMAPMODE,*PEMRSETMAPMODE,EMRSETLAYOUT,*PEMRSETLAYOUT,
    EMRSETPOLYFILLMODE,*PEMRSETPOLYFILLMODE,EMRSETROP2,*PEMRSETROP2,EMRSETSTRETCHBLTMODE,*PEMRSETSTRETCHBLTMODE,EMRSETICMMODE,
    *PEMRSETICMMODE,EMRSETTEXTALIGN,*PEMRSETTEXTALIGN;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETMITERLIMIT {
    EMR emr;
    FLOAT e_Miter_सीमा;
  } EMRSETMITERLIMIT,*PEMRSETMITERLIMIT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRRESTOREDC {
    EMR emr;
    LONG iRelative;
  } EMRRESTOREDC,*PEMRRESTOREDC;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETARCDIRECTION {
    EMR emr;
    DWORD iArcDirection;

  } EMRSETARCDIRECTION,*PEMRSETARCDIRECTION;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETMAPPERFLAGS {
    EMR emr;
    DWORD dwFlags;
  } EMRSETMAPPERFLAGS,*PEMRSETMAPPERFLAGS;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETTEXTCOLOR {
    EMR emr;
    COLORREF crColor;
  } EMRSETBKCOLOR,*PEMRSETBKCOLOR,EMRSETTEXTCOLOR,*PEMRSETTEXTCOLOR;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSELECTOBJECT {
    EMR emr;
    DWORD ihObject;
  } EMRSELECTOBJECT,*PEMRSELECTOBJECT,EMRDELETEOBJECT,*PEMRDELETEOBJECT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSELECTPALETTE {
    EMR emr;
    DWORD ihPal;
  } EMRSELECTPALETTE,*PEMRSELECTPALETTE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRRESIZEPALETTE {
    EMR emr;
    DWORD ihPal;
    DWORD cEntries;
  } EMRRESIZEPALETTE,*PEMRRESIZEPALETTE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETPALETTEENTRIES {
    EMR emr;
    DWORD ihPal;
    DWORD iStart;
    DWORD cEntries;
    PALETTEENTRY aPalEntries[1];
  } EMRSETPALETTEENTRIES,*PEMRSETPALETTEENTRIES;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETCOLORADJUSTMENT {
    EMR emr;
    COLORADJUSTMENT ColorAdjustment;
  } EMRSETCOLORADJUSTMENT,*PEMRSETCOLORADJUSTMENT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRGDICOMMENT {
    EMR emr;
    DWORD cb_दत्त;
    BYTE दत्त_3[1];
  } EMRGDICOMMENT,*PEMRGDICOMMENT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMREOF {
    EMR emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD n_आकार_चरमः;
  } EMREOF,*PEMREOF;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRLINETO {
    EMR emr;
    POINTL ptl;
  } EMRLINETO,*PEMRLINETO,EMRMOVETOEX,*PEMRMOVETOEX;

  प्रकारनिर्देश संरचना चिह्नकम्_EMROFFSETCLIPRGN {
    EMR emr;
    POINTL ptl_विस्थापनम्;
  } EMROFFSETCLIPRGN,*PEMROFFSETCLIPRGN;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRFILLPATH {
    EMR emr;
    RECTL rclBounds;
  } EMRFILLPATH,*PEMRFILLPATH,EMRSTROKEANDFILLPATH,*PEMRSTROKEANDFILLPATH,EMRSTROKEPATH,*PEMRSTROKEPATH;

  प्रकारनिर्देश संरचना चिह्नकम्_EMREXCLUDECLIPRECT {
    EMR emr;
    RECTL rclClip;
  } EMREXCLUDECLIPRECT,*PEMREXCLUDECLIPRECT,EMRINTERSECTCLIPRECT,*PEMRINTERSECTCLIPRECT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETVIEWPORTORGEX {
    EMR emr;
    POINTL ptlOrigin;
  } EMRSETVIEWPORTORGEX,*PEMRSETVIEWPORTORGEX,EMRSETWINDOWORGEX,*PEMRSETWINDOWORGEX,EMRSETBRUSHORGEX,*PEMRSETBRUSHORGEX;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETVIEWPORTEXTEX {
    EMR emr;
    SIZEL szlExtent;
  } EMRSETVIEWPORTEXTEX,*PEMRSETVIEWPORTEXTEX,EMRSETWINDOWEXTEX,*PEMRSETWINDOWEXTEX;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSCALEVIEWPORTEXTEX {
    EMR emr;
    LONG x_अङ्कः;
    LONG xDenom;
    LONG y_अङ्कः;
    LONG yDenom;
  } EMRSCALEVIEWPORTEXTEX,*PEMRSCALEVIEWPORTEXTEX,EMRSCALEWINDOWEXTEX,*PEMRSCALEWINDOWEXTEX;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
  } EMRSETWORLDTRANSFORM,*PEMRSETWORLDTRANSFORM;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRMODIFYWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
    DWORD i_बहुलकम्;
  } EMRMODIFYWORLDTRANSFORM,*PEMRMODIFYWORLDTRANSFORM;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETPIXELV {
    EMR emr;
    POINTL ptlPixel;
    COLORREF crColor;
  } EMRSETPIXELV,*PEMRSETPIXELV;

  प्रकारनिर्देश संरचना चिह्नकम्_EMREXTFLOODFILL {
    EMR emr;
    POINTL ptlStart;
    COLORREF crColor;
    DWORD i_बहुलकम्;
  } EMREXTFLOODFILL,*PEMREXTFLOODFILL;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRELLIPSE {
    EMR emr;
    RECTL rclBox;
  } EMRELLIPSE,*PEMRELLIPSE,EMRRECTANGLE,*PEMRRECTANGLE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRROUNDRECT {
    EMR emr;
    RECTL rclBox;
    SIZEL szlCorner;
  } EMRROUNDRECT,*PEMRROUNDRECT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRARC {
    EMR emr;
    RECTL rclBox;
    POINTL ptlStart;
    POINTL ptl_अन्तः;
  } EMRARC,*PEMRARC,EMRARCTO,*PEMRARCTO,EMRCHORD,*PEMRCHORD,EMRPIE,*PEMRPIE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRANGLEARC {
    EMR emr;
    POINTL ptlCenter;
    DWORD nRadius;
    FLOAT eStartAngle;
    FLOAT eSweepAngle;
  } EMRANGLEARC,*PEMRANGLEARC;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
  } EMRPOLYLINE,*PEMRPOLYLINE,EMRPOLYBEZIER,*PEMRPOLYBEZIER,EMRPOLYGON,*PEMRPOLYGON,EMRPOLYBEZIERTO,*PEMRPOLYBEZIERTO,EMRPOLYLINETO,*PEMRPOLYLINETO;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
  } EMRPOLYLINE16,*PEMRPOLYLINE16,EMRPOLYBEZIER16,*PEMRPOLYBEZIER16,EMRPOLYGON16,*PEMRPOLYGON16,EMRPOLYBEZIERTO16,*PEMRPOLYBEZIERTO16,EMRPOLYLINETO16,*PEMRPOLYLINETO16;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRPOLYDRAW {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW,*PEMRPOLYDRAW;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRPOLYDRAW16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW16,*PEMRPOLYDRAW16;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRPOLYPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cptl;
    DWORD aPolyCounts[1];
    POINTL aptl[1];
  } EMRPOLYPOLYLINE,*PEMRPOLYPOLYLINE,EMRPOLYPOLYGON,*PEMRPOLYPOLYGON;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRPOLYPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cpts;
    DWORD aPolyCounts[1];
    POINTS apts[1];
  } EMRPOLYPOLYLINE16,*PEMRPOLYPOLYLINE16,EMRPOLYPOLYGON16,*PEMRPOLYPOLYGON16;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRINVERTRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_दत्त;
    BYTE Rgn_दत्त[1];
  } EMRINVERTRGN,*PEMRINVERTRGN,EMRPAINTRGN,*PEMRPAINTRGN;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRFILLRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_दत्त;
    DWORD ihBrush;
    BYTE Rgn_दत्त[1];
  } EMRFILLRGN,*PEMRFILLRGN;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRFRAMERGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_दत्त;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE Rgn_दत्त[1];
  } EMRFRAMERGN,*PEMRFRAMERGN;

  प्रकारनिर्देश संरचना चिह्नकम्_EMREXTSELECTCLIPRGN {
    EMR emr;
    DWORD cb_Rgn_दत्त;
    DWORD i_बहुलकम्;
    BYTE Rgn_दत्त[1];
  } EMREXTSELECTCLIPRGN,*PEMREXTSELECTCLIPRGN;

  प्रकारनिर्देश संरचना चिह्नकम्_EMREXTTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_बहुलकम्;
    FLOAT exScale;
    FLOAT eyScale;
    EMRTEXT emrtext;
  } EMREXTTEXTOUTA,*PEMREXTTEXTOUTA,EMREXTTEXTOUTW,*PEMREXTTEXTOUTW;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRPOLYTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_बहुलकम्;
    FLOAT exScale;
    FLOAT eyScale;
    LONG c_वाक्यानि;
    EMRTEXT aemrtext[1];
  } EMRPOLYTEXTOUTA,*PEMRPOLYTEXTOUTA,EMRPOLYTEXTOUTW,*PEMRPOLYTEXTOUTW;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRBITBLT {
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
    DWORD off_द्वयङ्काः_Src;
    DWORD cb_द्वयङ्काः_Src;
  } EMRBITBLT,*PEMRBITBLT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSTRETCHBLT {
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
    DWORD off_द्वयङ्काः_Src;
    DWORD cb_द्वयङ्काः_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRSTRETCHBLT,*PEMRSTRETCHBLT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRMASKBLT {
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
    DWORD off_द्वयङ्काः_Src;
    DWORD cb_द्वयङ्काः_Src;
    LONG x_आवरणम्;
    LONG y_आवरणम्;
    DWORD i_Usage_आवरणम्;
    DWORD off_Bmi_आवरणम्;
    DWORD cb_Bmi_आवरणम्;
    DWORD off_द्वयङ्काः_आवरणम्;
    DWORD cb_द्वयङ्काः_आवरणम्;
  } EMRMASKBLT,*PEMRMASKBLT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRPLGBLT {
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
    DWORD off_द्वयङ्काः_Src;
    DWORD cb_द्वयङ्काः_Src;
    LONG x_आवरणम्;
    LONG y_आवरणम्;
    DWORD i_Usage_आवरणम्;
    DWORD off_Bmi_आवरणम्;
    DWORD cb_Bmi_आवरणम्;
    DWORD off_द्वयङ्काः_आवरणम्;
    DWORD cb_द्वयङ्काः_आवरणम्;
  } EMRPLGBLT,*PEMRPLGBLT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETDIBITSTODEVICE {
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
    DWORD off_द्वयङ्काः_Src;
    DWORD cb_द्वयङ्काः_Src;
    DWORD iUsageSrc;
    DWORD i_Start_अवलोकनम्;
    DWORD cScans;
  } EMRSETDIBITSTODEVICE,*PEMRSETDIBITSTODEVICE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSTRETCHDIBITS {
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
    DWORD off_द्वयङ्काः_Src;
    DWORD cb_द्वयङ्काः_Src;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG cxDest;
    LONG cyDest;
  } EMRSTRETCHDIBITS,*PEMRSTRETCHDIBITS;

  प्रकारनिर्देश संरचना चिह्नकम्_EMREXTCREATEFONTINDIRECTW {
    EMR emr;
    DWORD ihFont;
    EXTLOGFONTW elfw;
  } EMREXTCREATEFONTINDIRECTW,*PEMREXTCREATEFONTINDIRECTW;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRCREATEPALETTE {
    EMR emr;
    DWORD ihPal;
    LOGPALETTE lgpl;
  } EMRCREATEPALETTE,*PEMRCREATEPALETTE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRCREATEPEN {
    EMR emr;
    DWORD ihPen;
    LOGPEN lopn;
  } EMRCREATEPEN,*PEMRCREATEPEN;

  प्रकारनिर्देश संरचना चिह्नकम्_EMREXTCREATEPEN {
    EMR emr;
    DWORD ihPen;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_द्वयङ्काः;
    DWORD cb_द्वयङ्काः;
    EXTLOGPEN elp;
  } EMREXTCREATEPEN,*PEMREXTCREATEPEN;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRCREATEBRUSHINDIRECT {
    EMR emr;
    DWORD ihBrush;
    LOGBRUSH32 lb;
  } EMRCREATEBRUSHINDIRECT,*PEMRCREATEBRUSHINDIRECT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRCREATEMONOBRUSH {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_द्वयङ्काः;
    DWORD cb_द्वयङ्काः;
  } EMRCREATEMONOBRUSH,*PEMRCREATEMONOBRUSH;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRCREATEDIBPATTERNBRUSHPT {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_द्वयङ्काः;
    DWORD cb_द्वयङ्काः;
  } EMRCREATEDIBPATTERNBRUSHPT,*PEMRCREATEDIBPATTERNBRUSHPT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRFORMAT {
    DWORD dSignature;
    DWORD n_संस्करणम्;
    DWORD cb_दत्त;
    DWORD off_दत्त;
  } EMRFORMAT,*PEMRFORMAT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRGLSRECORD {
    EMR emr;
    DWORD cb_दत्त;
    BYTE दत्त_3[1];
  } EMRGLSRECORD,*PEMRGLSRECORD;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRGLSBOUNDEDRECORD {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_दत्त;
    BYTE दत्त_3[1];
  } EMRGLSBOUNDEDRECORD,*PEMRGLSBOUNDEDRECORD;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRPIXELFORMAT {
    EMR emr;
    PIXELFORMATDESCRIPTOR pfd;
  } EMRPIXELFORMAT,*PEMRPIXELFORMAT;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRCREATECOLORSPACE {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEA lcs;
  } EMRCREATECOLORSPACE,*PEMRCREATECOLORSPACE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETCOLORSPACE {
    EMR emr;
    DWORD ihCS;
  } EMRSETCOLORSPACE,*PEMRSETCOLORSPACE,EMRSELECTCOLORSPACE,*PEMRSELECTCOLORSPACE,EMRDELETECOLORSPACE,*PEMRDELETECOLORSPACE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMREXTESCAPE {
    EMR emr;
    INT iEscape;
    INT cb_Esc_दत्त;
    BYTE Esc_दत्त[1];
  } EMREXTESCAPE,*PEMREXTESCAPE,EMRDRAWESCAPE,*PEMRDRAWESCAPE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRNAMEDESCAPE {
    EMR emr;
    INT iEscape;
    INT cbDriver;
    INT cb_Esc_दत्त;
    BYTE Esc_दत्त[1];
  } EMRNAMEDESCAPE,*PEMRNAMEDESCAPE;

#परिभाषय SETICMPROFILE_EMBEDED 0x00000001

  प्रकारनिर्देश संरचना चिह्नकम्_EMRSETICMPROFILE {
    EMR emr;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_दत्त;
    BYTE दत्त_3[1];
  } EMRSETICMPROFILE,*PEMRSETICMPROFILE,EMRSETICMPROFILEA,*PEMRSETICMPROFILEA,EMRSETICMPROFILEW,*PEMRSETICMPROFILEW;

#परिभाषय CREATECOLORSPACE_EMBEDED 0x00000001

  प्रकारनिर्देश संरचना चिह्नकम्_EMRCREATECOLORSPACEW {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEW lcs;
    DWORD dwFlags;
    DWORD cb_दत्त;
    BYTE दत्त_3[1];
  } EMRCREATECOLORSPACEW,*PEMRCREATECOLORSPACEW;

#परिभाषय COLORMATCHTOTARGET_EMBEDED 0x00000001

  प्रकारनिर्देश संरचना चिह्नकम्_COLORMATCHTOTARGET {
    EMR emr;
    DWORD dwAction;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_दत्त;
    BYTE दत्त_3[1];
  } EMRCOLORMATCHTOTARGET,*PEMRCOLORMATCHTOTARGET;

  प्रकारनिर्देश संरचना चिह्नकम्_COLORCORRECTPALETTE {
    EMR emr;
    DWORD ihPalette;
    DWORD n_First_प्रविष्टिः;
    DWORD nPalEntries;
    DWORD nReserved;
  } EMRCOLORCORRECTPALETTE,*PEMRCOLORCORRECTPALETTE;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRALPHABLEND {
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
    DWORD off_द्वयङ्काः_Src;
    DWORD cb_द्वयङ्काः_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRALPHABLEND,*PEMRALPHABLEND;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRGRADIENTFILL {
    EMR emr;
    RECTL rclBounds;
    DWORD nVer;
    DWORD nTri;
    ULONG ul_बहुलकम्;
    TRIVERTEX Ver[1];
  } EMRGRADIENTFILL,*PEMRGRADIENTFILL;

  प्रकारनिर्देश संरचना चिह्नकम्_EMRTRANSPARENTBLT {
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
    DWORD off_द्वयङ्काः_Src;
    DWORD cb_द्वयङ्काः_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRTRANSPARENTBLT,*PEMRTRANSPARENTBLT;

#परिभाषय GDICOMMENT_IDENTIFIER 0x43494447
#परिभाषय GDICOMMENT_WINDOWS_METAFILE 0x80000001
#परिभाषय GDICOMMENT_BEGINGROUP 0x00000002
#परिभाषय GDICOMMENT_ENDGROUP 0x00000003
#परिभाषय GDICOMMENT_MULTIFORMATS 0x40000004
#परिभाषय EPS_SIGNATURE 0x46535045
#परिभाषय GDICOMMENT_UNICODE_STRING 0x00000040
#परिभाषय GDICOMMENT_UNICODE_अन्तः 0x00000080
#यदि_अन्तः

#यदि_परिभाषितम् UNICODE
#परिभाषय wglUseFontBitmaps wglUseFontBitmapsW
#अन्यथा
#परिभाषय wglUseFontBitmaps wglUseFontBitmapsA
#यदि_अन्तः

  WINGDIAPI WINBOOL WINAPI wglCopyContext(HGLRC,HGLRC,UINT);
  WINGDIAPI HGLRC WINAPI wglCreateContext(HDC);
  WINGDIAPI HGLRC WINAPI wglCreateLayerContext(HDC,पूर्णाङ्क);
  WINGDIAPI WINBOOL WINAPI wglDeleteContext(HGLRC);
  WINGDIAPI HGLRC WINAPI wglGetCurrentContext(VOID);
  WINGDIAPI HDC WINAPI wglGetCurrentDC(VOID);
  WINGDIAPI PROC WINAPI wgl_Get_Proc_स्थानाङ्कः(LPCSTR);
  WINGDIAPI WINBOOL WINAPI wglMakeCurrent(HDC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglShareLists(HGLRC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsA(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsW(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI SwapBuffers(HDC);

  प्रकारनिर्देश संरचना _POINTFLOAT {
    FLOAT x;
    FLOAT y;
  } POINTFLOAT,*PPOINTFLOAT;

  प्रकारनिर्देश संरचना _GLYPHMETRICSFLOAT {
    FLOAT gmfBlackBoxX;
    FLOAT gmfBlackBoxY;
    POINTFLOAT gmfptGlyphOrigin;
    FLOAT gmfCellIncX;
    FLOAT gmfCellIncY;
  } GLYPHMETRICSFLOAT,*PGLYPHMETRICSFLOAT,*LPGLYPHMETRICSFLOAT;

#परिभाषय WGL_FONT_पङ्क्तयः 0
#परिभाषय WGL_FONT_POLYGONS 1

#यदि_परिभाषितम् UNICODE
#परिभाषय wglUseFontOutlines wglUseFontOutlinesW
#अन्यथा
#परिभाषय wglUseFontOutlines wglUseFontOutlinesA
#यदि_अन्तः

  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesA(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,पूर्णाङ्क,LPGLYPHMETRICSFLOAT);
  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesW(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,पूर्णाङ्क,LPGLYPHMETRICSFLOAT);

  प्रकारनिर्देश संरचना चिह्नकम्_LAYERPLANEDESCRIPTOR {
    WORD n_आकार;
    WORD n_संस्करणम्;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_द्वयङ्काः;
    BYTE c_Red_द्वयङ्काः;
    BYTE c_Red_सरणम्;
    BYTE c_Green_द्वयङ्काः;
    BYTE c_Green_सरणम्;
    BYTE c_Blue_द्वयङ्काः;
    BYTE c_Blue_सरणम्;
    BYTE c_Alpha_द्वयङ्काः;
    BYTE c_Alpha_सरणम्;
    BYTE c_Accum_द्वयङ्काः;
    BYTE c_Accum_Red_द्वयङ्काः;
    BYTE c_Accum_Green_द्वयङ्काः;
    BYTE c_Accum_Blue_द्वयङ्काः;
    BYTE c_Accum_Alpha_द्वयङ्काः;
    BYTE c_गभीरता_द्वयङ्काः;
    BYTE c_Stencil_द्वयङ्काः;
    BYTE cAuxBuffers;
    BYTE iLayerPlane;
    BYTE bReserved;
    COLORREF crTransparent;
  } LAYERPLANEDESCRIPTOR,*PLAYERPLANEDESCRIPTOR,*LPLAYERPLANEDESCRIPTOR;

#परिभाषय LPD_DOUBLEBUFFER 0x00000001
#परिभाषय LPD_STEREO 0x00000002
#परिभाषय LPD_SUPPORT_GDI 0x00000010
#परिभाषय LPD_SUPPORT_OPENGL 0x00000020
#परिभाषय LPD_SHARE_गभीरता 0x00000040
#परिभाषय LPD_SHARE_STENCIL 0x00000080
#परिभाषय LPD_SHARE_ACCUM 0x00000100
#परिभाषय LPD_SWAP_EXCHANGE 0x00000200
#परिभाषय LPD_SWAP_COPY 0x00000400
#परिभाषय LPD_TRANSPARENT 0x00001000

#परिभाषय LPD_TYPE_RGBA 0
#परिभाषय LPD_TYPE_COLORINDEX 1

#परिभाषय WGL_SWAP_MAIN_PLANE 0x00000001
#परिभाषय WGL_SWAP_OVERLAY1 0x00000002
#परिभाषय WGL_SWAP_OVERLAY2 0x00000004
#परिभाषय WGL_SWAP_OVERLAY3 0x00000008
#परिभाषय WGL_SWAP_OVERLAY4 0x00000010
#परिभाषय WGL_SWAP_OVERLAY5 0x00000020
#परिभाषय WGL_SWAP_OVERLAY6 0x00000040
#परिभाषय WGL_SWAP_OVERLAY7 0x00000080
#परिभाषय WGL_SWAP_OVERLAY8 0x00000100
#परिभाषय WGL_SWAP_OVERLAY9 0x00000200
#परिभाषय WGL_SWAP_OVERLAY10 0x00000400
#परिभाषय WGL_SWAP_OVERLAY11 0x00000800
#परिभाषय WGL_SWAP_OVERLAY12 0x00001000
#परिभाषय WGL_SWAP_OVERLAY13 0x00002000
#परिभाषय WGL_SWAP_OVERLAY14 0x00004000
#परिभाषय WGL_SWAP_OVERLAY15 0x00008000
#परिभाषय WGL_SWAP_UNDERLAY1 0x00010000
#परिभाषय WGL_SWAP_UNDERLAY2 0x00020000
#परिभाषय WGL_SWAP_UNDERLAY3 0x00040000
#परिभाषय WGL_SWAP_UNDERLAY4 0x00080000
#परिभाषय WGL_SWAP_UNDERLAY5 0x00100000
#परिभाषय WGL_SWAP_UNDERLAY6 0x00200000
#परिभाषय WGL_SWAP_UNDERLAY7 0x00400000
#परिभाषय WGL_SWAP_UNDERLAY8 0x00800000
#परिभाषय WGL_SWAP_UNDERLAY9 0x01000000
#परिभाषय WGL_SWAP_UNDERLAY10 0x02000000
#परिभाषय WGL_SWAP_UNDERLAY11 0x04000000
#परिभाषय WGL_SWAP_UNDERLAY12 0x08000000
#परिभाषय WGL_SWAP_UNDERLAY13 0x10000000
#परिभाषय WGL_SWAP_UNDERLAY14 0x20000000
#परिभाषय WGL_SWAP_UNDERLAY15 0x40000000

  WINGDIAPI WINBOOL WINAPI wglDescribeLayerPlane(HDC,पूर्णाङ्क,पूर्णाङ्क,UINT,LPLAYERPLANEDESCRIPTOR);
  WINGDIAPI पूर्णाङ्क WINAPI wgl_समुच्चयः_Layer_Palette_Entries(HDC,पूर्णाङ्क,पूर्णाङ्क,पूर्णाङ्क,CONST COLORREF *);
  WINGDIAPI पूर्णाङ्क WINAPI wglGetLayerPaletteEntries(HDC,पूर्णाङ्क,पूर्णाङ्क,पूर्णाङ्क,COLORREF *);
  WINGDIAPI WINBOOL WINAPI wglRealizeLayerPalette(HDC,पूर्णाङ्क,WINBOOL);
  WINGDIAPI WINBOOL WINAPI wglSwapLayerBuffers(HDC,UINT);

  प्रकारनिर्देश संरचना _WGLSWAP {
    HDC hdc;
    UINT uiFlags;
  } WGLSWAP,*PWGLSWAP,*LPWGLSWAP;

#परिभाषय WGL_SWAPMULTIPLE_MAX 16

  WINGDIAPI DWORD WINAPI wgl_Swap_गुणजः_Buffers(UINT,CONST WGLSWAP *);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
