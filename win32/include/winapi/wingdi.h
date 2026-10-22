/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _WINGDI_
#ವ್ಯಾಖ್ಯಾನಿಸು _WINGDI_

#ವ್ಯಾಖ್ಯಾನಿಸು WINGDIAPI DECLSPEC_IMPORT
#ವ್ಯಾಖ್ಯಾನಿಸು WINSPOOLAPI DECLSPEC_IMPORT

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
ಬಾಹ್ಯ "C" {
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ WINVER
#ವ್ಯಾಖ್ಯಾನಿಸು WINVER 0x0502
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOGDI
#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NORASTEROPS
#ವ್ಯಾಖ್ಯಾನಿಸು R2_BLACK 1
#ವ್ಯಾಖ್ಯಾನಿಸು R2_NOTMERGEPEN 2
#ವ್ಯಾಖ್ಯಾನಿಸು R2_MASKNOTPEN 3
#ವ್ಯಾಖ್ಯಾನಿಸು R2_NOTCOPYPEN 4
#ವ್ಯಾಖ್ಯಾನಿಸು R2_MASKPENNOT 5
#ವ್ಯಾಖ್ಯಾನಿಸು R2_NOT 6
#ವ್ಯಾಖ್ಯಾನಿಸು R2_XORPEN 7
#ವ್ಯಾಖ್ಯಾನಿಸು R2_NOTMASKPEN 8
#ವ್ಯಾಖ್ಯಾನಿಸು R2_MASKPEN 9
#ವ್ಯಾಖ್ಯಾನಿಸು R2_NOTXORPEN 10
#ವ್ಯಾಖ್ಯಾನಿಸು R2_NOP 11
#ವ್ಯಾಖ್ಯಾನಿಸು R2_MERGENOTPEN 12
#ವ್ಯಾಖ್ಯಾನಿಸು R2_COPYPEN 13
#ವ್ಯಾಖ್ಯಾನಿಸು R2_MERGEPENNOT 14
#ವ್ಯಾಖ್ಯಾನಿಸು R2_MERGEPEN 15
#ವ್ಯಾಖ್ಯಾನಿಸು R2_WHITE 16
#ವ್ಯಾಖ್ಯಾನಿಸು R2_ಕೊನೆಯ 16

#ವ್ಯಾಖ್ಯಾನಿಸು SRCCOPY (DWORD)0x00CC0020
#ವ್ಯಾಖ್ಯಾನಿಸು SRCPAINT (DWORD)0x00EE0086
#ವ್ಯಾಖ್ಯಾನಿಸು SRCAND (DWORD)0x008800C6
#ವ್ಯಾಖ್ಯಾನಿಸು SRCINVERT (DWORD)0x00660046
#ವ್ಯಾಖ್ಯಾನಿಸು SRCERASE (DWORD)0x00440328
#ವ್ಯಾಖ್ಯಾನಿಸು NOTSRCCOPY (DWORD)0x00330008
#ವ್ಯಾಖ್ಯಾನಿಸು NOTSRCERASE (DWORD)0x001100A6
#ವ್ಯಾಖ್ಯಾನಿಸು MERGECOPY (DWORD)0x00C000CA
#ವ್ಯಾಖ್ಯಾನಿಸು MERGEPAINT (DWORD)0x00BB0226
#ವ್ಯಾಖ್ಯಾನಿಸು PATCOPY (DWORD)0x00F00021
#ವ್ಯಾಖ್ಯಾನಿಸು PATPAINT (DWORD)0x00FB0A09
#ವ್ಯಾಖ್ಯಾನಿಸು PATINVERT (DWORD)0x005A0049
#ವ್ಯಾಖ್ಯಾನಿಸು DSTINVERT (DWORD)0x00550009
#ವ್ಯಾಖ್ಯಾನಿಸು BLACKNESS (DWORD)0x00000042
#ವ್ಯಾಖ್ಯಾನಿಸು WHITENESS (DWORD)0x00FF0062
#ವ್ಯಾಖ್ಯಾನಿಸು NOMIRRORBITMAP (DWORD)0x80000000
#ವ್ಯಾಖ್ಯಾನಿಸು CAPTUREBLT (DWORD)0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು MAKEROP4(fore,ಹಿಂಭಾಗ) (DWORD)((((ಹಿಂಭಾಗ) << 8) & 0xFF000000) | (fore))
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು GDI_ERROR (0xFFFFFFFFL)
#ವ್ಯಾಖ್ಯಾನಿಸು HGDI_ERROR (Long_ಗಮ್ಯ_Handle(0xFFFFFFFFL))

#ವ್ಯಾಖ್ಯಾನಿಸು ERROR 0
#ವ್ಯಾಖ್ಯಾನಿಸು NULLREGION 1
#ವ್ಯಾಖ್ಯಾನಿಸು SIMPLEREGION 2
#ವ್ಯಾಖ್ಯಾನಿಸು COMPLEXREGION 3
#ವ್ಯಾಖ್ಯಾನಿಸು RGN_ERROR ERROR

#ವ್ಯಾಖ್ಯಾನಿಸು RGN_AND 1
#ವ್ಯಾಖ್ಯಾನಿಸು RGN_OR 2
#ವ್ಯಾಖ್ಯಾನಿಸು RGN_XOR 3
#ವ್ಯಾಖ್ಯಾನಿಸು RGN_DIFF 4
#ವ್ಯಾಖ್ಯಾನಿಸು RGN_COPY 5
#ವ್ಯಾಖ್ಯಾನಿಸು RGN_MIN RGN_AND
#ವ್ಯಾಖ್ಯಾನಿಸು RGN_MAX RGN_COPY

#ವ್ಯಾಖ್ಯಾನಿಸು BLACKONWHITE 1
#ವ್ಯಾಖ್ಯಾನಿಸು WHITEONBLACK 2
#ವ್ಯಾಖ್ಯಾನಿಸು COLORONCOLOR 3
#ವ್ಯಾಖ್ಯಾನಿಸು HALFTONE 4
#ವ್ಯಾಖ್ಯಾನಿಸು MAXSTRETCHBLTMODE 4

#ವ್ಯಾಖ್ಯಾನಿಸು STRETCH_ANDSCANS BLACKONWHITE
#ವ್ಯಾಖ್ಯಾನಿಸು STRETCH_ORSCANS WHITEONBLACK
#ವ್ಯಾಖ್ಯಾನಿಸು STRETCH_DELETESCANS COLORONCOLOR
#ವ್ಯಾಖ್ಯಾನಿಸು STRETCH_HALFTONE HALFTONE

#ವ್ಯಾಖ್ಯಾನಿಸು ALTERNATE 1
#ವ್ಯಾಖ್ಯಾನಿಸು WINDING 2
#ವ್ಯಾಖ್ಯಾನಿಸು POLYFILL_ಕೊನೆಯ 2

#ವ್ಯಾಖ್ಯಾನಿಸು LAYOUT_RTL 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು LAYOUT_BTT 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು LAYOUT_VBH 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು LAYOUT_ORIENTATIONMASK (LAYOUT_RTL | LAYOUT_BTT | LAYOUT_VBH)
#ವ್ಯಾಖ್ಯಾನಿಸು LAYOUT_BITMAPORIENTATIONPRESERVED 0x00000008

#ವ್ಯಾಖ್ಯಾನಿಸು TA_NOUPDATECP 0
#ವ್ಯಾಖ್ಯಾನಿಸು TA_UPDATECP 1

#ವ್ಯಾಖ್ಯಾನಿಸು TA_ಎಡ 0
#ವ್ಯಾಖ್ಯಾನಿಸು TA_ಬಲ 2
#ವ್ಯಾಖ್ಯಾನಿಸು TA_CENTER 6

#ವ್ಯಾಖ್ಯಾನಿಸು TA_ತುದಿ 0
#ವ್ಯಾಖ್ಯಾನಿಸು TA_BOTTOM 8
#ವ್ಯಾಖ್ಯಾನಿಸು TA_BASELINE 24
#ವ್ಯಾಖ್ಯಾನಿಸು TA_RTLREADING 256
#ವ್ಯಾಖ್ಯಾನಿಸು TA_ಮುಖವಾಡ (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)

#ವ್ಯಾಖ್ಯಾನಿಸು VTA_BASELINE TA_BASELINE
#ವ್ಯಾಖ್ಯಾನಿಸು VTA_ಎಡ TA_BOTTOM
#ವ್ಯಾಖ್ಯಾನಿಸು VTA_ಬಲ TA_ತುದಿ
#ವ್ಯಾಖ್ಯಾನಿಸು VTA_CENTER TA_CENTER
#ವ್ಯಾಖ್ಯಾನಿಸು VTA_BOTTOM TA_ಬಲ
#ವ್ಯಾಖ್ಯಾನಿಸು VTA_ತುದಿ TA_ಎಡ

#ವ್ಯಾಖ್ಯಾನಿಸು ETO_OPAQUE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು ETO_CLIPPED 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು ETO_GLYPH_ಸೂಚ್ಯಂಕ 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು ETO_RTLREADING 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು ETO_NUMERICSLOCAL 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು ETO_NUMERICSLATIN 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು ETO_IGNORELANGUAGE 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು ETO_PDY 0x2000

#ವ್ಯಾಖ್ಯಾನಿಸು ASPECT_FILTERING 0x0001

#ವ್ಯಾಖ್ಯಾನಿಸು DCB_RESET 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DCB_ACCUMULATE 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DCB_DIRTY DCB_ACCUMULATE
#ವ್ಯಾಖ್ಯಾನಿಸು DCB_ಗಣ (DCB_RESET | DCB_ACCUMULATE)
#ವ್ಯಾಖ್ಯಾನಿಸು DCB_ENABLE 0x0004
#ವ್ಯಾಖ್ಯಾನಿಸು DCB_DISABLE 0x0008

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMETAFILE

#ವ್ಯಾಖ್ಯಾನಿಸು META_SETBKCOLOR 0x0201
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETBKMODE 0x0102
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETMAPMODE 0x0103
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETROP2 0x0104
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETRELABS 0x0105
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETPOLYFILLMODE 0x0106
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETSTRETCHBLTMODE 0x0107
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETTEXTCHAREXTRA 0x0108
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETTEXTCOLOR 0x0209
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETTEXTJUSTIFICATION 0x020A
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETWINDOWORG 0x020B
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETWINDOWEXT 0x020C
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETVIEWPORTORG 0x020D
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETVIEWPORTEXT 0x020E
#ವ್ಯಾಖ್ಯಾನಿಸು META_OFFSETWINDOWORG 0x020F
#ವ್ಯಾಖ್ಯಾನಿಸು META_SCALEWINDOWEXT 0x0410
#ವ್ಯಾಖ್ಯಾನಿಸು META_OFFSETVIEWPORTORG 0x0211
#ವ್ಯಾಖ್ಯಾನಿಸು META_SCALEVIEWPORTEXT 0x0412
#ವ್ಯಾಖ್ಯಾನಿಸು META_LINETO 0x0213
#ವ್ಯಾಖ್ಯಾನಿಸು META_MOVETO 0x0214
#ವ್ಯಾಖ್ಯಾನಿಸು META_EXCLUDECLIPRECT 0x0415
#ವ್ಯಾಖ್ಯಾನಿಸು META_INTERSECTCLIPRECT 0x0416
#ವ್ಯಾಖ್ಯಾನಿಸು META_ARC 0x0817
#ವ್ಯಾಖ್ಯಾನಿಸು META_ELLIPSE 0x0418
#ವ್ಯಾಖ್ಯಾನಿಸು META_FLOODFILL 0x0419
#ವ್ಯಾಖ್ಯಾನಿಸು META_PIE 0x081A
#ವ್ಯಾಖ್ಯಾನಿಸು META_RECTANGLE 0x041B
#ವ್ಯಾಖ್ಯಾನಿಸು META_ROUNDRECT 0x061C
#ವ್ಯಾಖ್ಯಾನಿಸು META_PATBLT 0x061D
#ವ್ಯಾಖ್ಯಾನಿಸು META_SAVEDC 0x001E
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETPIXEL 0x041F
#ವ್ಯಾಖ್ಯಾನಿಸು META_OFFSETCLIPRGN 0x0220
#ವ್ಯಾಖ್ಯಾನಿಸು META_TEXTOUT 0x0521
#ವ್ಯಾಖ್ಯಾನಿಸು META_BITBLT 0x0922
#ವ್ಯಾಖ್ಯಾನಿಸು META_STRETCHBLT 0x0B23
#ವ್ಯಾಖ್ಯಾನಿಸು META_POLYGON 0x0324
#ವ್ಯಾಖ್ಯಾನಿಸು META_POLYLINE 0x0325
#ವ್ಯಾಖ್ಯಾನಿಸು META_ESCAPE 0x0626
#ವ್ಯಾಖ್ಯಾನಿಸು META_RESTOREDC 0x0127
#ವ್ಯಾಖ್ಯಾನಿಸು META_FILLREGION 0x0228
#ವ್ಯಾಖ್ಯಾನಿಸು META_FRAMEREGION 0x0429
#ವ್ಯಾಖ್ಯಾನಿಸು META_INVERTREGION 0x012A
#ವ್ಯಾಖ್ಯಾನಿಸು META_PAINTREGION 0x012B
#ವ್ಯಾಖ್ಯಾನಿಸು META_SELECTCLIPREGION 0x012C
#ವ್ಯಾಖ್ಯಾನಿಸು META_SELECTOBJECT 0x012D
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETTEXTALIGN 0x012E
#ವ್ಯಾಖ್ಯಾನಿಸು META_CHORD 0x0830
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETMAPPERFLAGS 0x0231
#ವ್ಯಾಖ್ಯಾನಿಸು META_EXTTEXTOUT 0x0a32
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETDIBTODEV 0x0d33
#ವ್ಯಾಖ್ಯಾನಿಸು META_SELECTPALETTE 0x0234
#ವ್ಯಾಖ್ಯಾನಿಸು META_REALIZEPALETTE 0x0035
#ವ್ಯಾಖ್ಯಾನಿಸು META_ANIMATEPALETTE 0x0436
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETPALENTRIES 0x0037
#ವ್ಯಾಖ್ಯಾನಿಸು META_POLYPOLYGON 0x0538
#ವ್ಯಾಖ್ಯಾನಿಸು META_RESIZEPALETTE 0x0139
#ವ್ಯಾಖ್ಯಾನಿಸು META_DIBBITBLT 0x0940
#ವ್ಯಾಖ್ಯಾನಿಸು META_DIBSTRETCHBLT 0x0b41
#ವ್ಯಾಖ್ಯಾನಿಸು META_DIBCREATEPATTERNBRUSH 0x0142
#ವ್ಯಾಖ್ಯಾನಿಸು META_STRETCHDIB 0x0f43
#ವ್ಯಾಖ್ಯಾನಿಸು META_EXTFLOODFILL 0x0548
#ವ್ಯಾಖ್ಯಾನಿಸು META_SETLAYOUT 0x0149
#ವ್ಯಾಖ್ಯಾನಿಸು META_DELETEOBJECT 0x01f0
#ವ್ಯಾಖ್ಯಾನಿಸು META_CREATEPALETTE 0x00f7
#ವ್ಯಾಖ್ಯಾನಿಸು META_CREATEPATTERNBRUSH 0x01F9
#ವ್ಯಾಖ್ಯಾನಿಸು META_CREATEPENINDIRECT 0x02FA
#ವ್ಯಾಖ್ಯಾನಿಸು META_CREATEFONTINDIRECT 0x02FB
#ವ್ಯಾಖ್ಯಾನಿಸು META_CREATEBRUSHINDIRECT 0x02FC
#ವ್ಯಾಖ್ಯಾನಿಸು META_CREATEREGION 0x06FF

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _DRAWPATRECT {
    ಬಿಂದು_3 ptPosition;
    ಬಿಂದು_3 pt_ಗಾತ್ರ;
    ಶಬ್ದ_3 wStyle;
    ಶಬ್ದ_3 w_ನಮೂನೆ;
  } DRAWPATRECT,*PDRAWPATRECT;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು NEWFRAME 1
#ವ್ಯಾಖ್ಯಾನಿಸು ABORTDOC 2
#ವ್ಯಾಖ್ಯಾನಿಸು NEXTBAND 3
#ವ್ಯಾಖ್ಯಾನಿಸು SETCOLORTABLE 4
#ವ್ಯಾಖ್ಯಾನಿಸು GETCOLORTABLE 5
#ವ್ಯಾಖ್ಯಾನಿಸು FLUSHOUTPUT 6
#ವ್ಯಾಖ್ಯಾನಿಸು DRAFTMODE 7
#ವ್ಯಾಖ್ಯಾನಿಸು QUERYESCSUPPORT 8
#ವ್ಯಾಖ್ಯಾನಿಸು SETABORTPROC 9
#ವ್ಯಾಖ್ಯಾನಿಸು STARTDOC 10
#ವ್ಯಾಖ್ಯಾನಿಸು ENDDOC 11
#ವ್ಯಾಖ್ಯಾನಿಸು GETPHYSPAGESIZE 12
#ವ್ಯಾಖ್ಯಾನಿಸು GETPRINTINGOFFSET 13
#ವ್ಯಾಖ್ಯಾನಿಸು GETSCALINGFACTOR 14
#ವ್ಯಾಖ್ಯಾನಿಸು MFCOMMENT 15
#ವ್ಯಾಖ್ಯಾನಿಸು GETPENWIDTH 16
#ವ್ಯಾಖ್ಯಾನಿಸು SETCOPYCOUNT 17
#ವ್ಯಾಖ್ಯಾನಿಸು SELECTPAPERSOURCE 18
#ವ್ಯಾಖ್ಯಾನಿಸು DEVICEDATA 19
#ವ್ಯಾಖ್ಯಾನಿಸು PASSTHROUGH 19
#ವ್ಯಾಖ್ಯಾನಿಸು GETTECHNOLGY 20
#ವ್ಯಾಖ್ಯಾನಿಸು GETTECHNOLOGY 20
#ವ್ಯಾಖ್ಯಾನಿಸು SETLINECAP 21
#ವ್ಯಾಖ್ಯಾನಿಸು SETLINEJOIN 22
#ವ್ಯಾಖ್ಯಾನಿಸು SETMITERLIMIT 23
#ವ್ಯಾಖ್ಯಾನಿಸು BANDINFO 24
#ವ್ಯಾಖ್ಯಾನಿಸು DRAWPATTERNRECT 25
#ವ್ಯಾಖ್ಯಾನಿಸು GETVECTORPENSIZE 26
#ವ್ಯಾಖ್ಯಾನಿಸು GETVECTORBRUSHSIZE 27
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLEDUPLEX 28
#ವ್ಯಾಖ್ಯಾನಿಸು GETSETPAPERBINS 29
#ವ್ಯಾಖ್ಯಾನಿಸು GETSETPRINTORIENT 30
#ವ್ಯಾಖ್ಯಾನಿಸು ENUMPAPERBINS 31
#ವ್ಯಾಖ್ಯಾನಿಸು SETDIBSCALING 32
#ವ್ಯಾಖ್ಯಾನಿಸು EPSPRINTING 33
#ವ್ಯಾಖ್ಯಾನಿಸು ENUMPAPERMETRICS 34
#ವ್ಯಾಖ್ಯಾನಿಸು GETSETPAPERMETRICS 35
#ವ್ಯಾಖ್ಯಾನಿಸು POSTSCRIPT_ದತ್ತಾಂಶ 37
#ವ್ಯಾಖ್ಯಾನಿಸು POSTSCRIPT_IGNORE 38
#ವ್ಯಾಖ್ಯಾನಿಸು MOUSETRAILS 39
#ವ್ಯಾಖ್ಯಾನಿಸು GETDEVICEUNITS 42

#ವ್ಯಾಖ್ಯಾನಿಸು GETEXTENDEDTEXTMETRICS 256
#ವ್ಯಾಖ್ಯಾನಿಸು GETEXTENTTABLE 257
#ವ್ಯಾಖ್ಯಾನಿಸು GETPAIRKERNTABLE 258
#ವ್ಯಾಖ್ಯಾನಿಸು GETTRACKKERNTABLE 259
#ವ್ಯಾಖ್ಯಾನಿಸು EXTTEXTOUT 512
#ವ್ಯಾಖ್ಯಾನಿಸು GETFACENAME 513
#ವ್ಯಾಖ್ಯಾನಿಸು DOWNLOADFACE 514
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLERELATIVEWIDTHS 768
#ವ್ಯಾಖ್ಯಾನಿಸು ENABLEPAIRKERNING 769
#ವ್ಯಾಖ್ಯಾನಿಸು SETKERNTRACK 770
#ವ್ಯಾಖ್ಯಾನಿಸು SETALLJUSTVALUES 771
#ವ್ಯಾಖ್ಯಾನಿಸು SETCHARSET 772

#ವ್ಯಾಖ್ಯಾನಿಸು STRETCHBLT 2048
#ವ್ಯಾಖ್ಯಾನಿಸು METAFILE_DRIVER 2049
#ವ್ಯಾಖ್ಯಾನಿಸು GETSETSCREENPARAMS 3072
#ವ್ಯಾಖ್ಯಾನಿಸು QUERYDIBSUPPORT 3073
#ವ್ಯಾಖ್ಯಾನಿಸು BEGIN_ಮಾರ್ಗ 4096
#ವ್ಯಾಖ್ಯಾನಿಸು CLIP_ಗಮ್ಯ_ಮಾರ್ಗ 4097
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೊನೆ_ಮಾರ್ಗ 4098
#ವ್ಯಾಖ್ಯಾನಿಸು EXT_DEVICE_CAPS 4099
#ವ್ಯಾಖ್ಯಾನಿಸು RESTORE_CTM 4100
#ವ್ಯಾಖ್ಯಾನಿಸು SAVE_CTM 4101
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ARC_DIRECTION 4102
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_BACKGROUND_COLOR 4103
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_POLY_ಬಹುಲಕ 4104
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_SCREEN_ANGLE 4105
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ಹರಡುವಿಕೆ 4106
#ವ್ಯಾಖ್ಯಾನಿಸು TRANSFORM_CTM 4107
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_CLIP_BOX 4108
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_BOUNDS 4109
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_MIRROR_ಬಹುಲಕ 4110
#ವ್ಯಾಖ್ಯಾನಿಸು OPENCHANNEL 4110
#ವ್ಯಾಖ್ಯಾನಿಸು DOWNLOADHEADER 4111
#ವ್ಯಾಖ್ಯಾನಿಸು CLOSECHANNEL 4112
#ವ್ಯಾಖ್ಯಾನಿಸು POSTSCRIPT_PASSTHROUGH 4115
#ವ್ಯಾಖ್ಯಾನಿಸು ENCAPSULATED_POSTSCRIPT 4116

#ವ್ಯಾಖ್ಯಾನಿಸು POSTSCRIPT_IDENTIFY 4117
#ವ್ಯಾಖ್ಯಾನಿಸು POSTSCRIPT_INJECTION 4118

#ವ್ಯಾಖ್ಯಾನಿಸು CHECKJPEGFORMAT 4119
#ವ್ಯಾಖ್ಯಾನಿಸು CHECKPNGFORMAT 4120

#ವ್ಯಾಖ್ಯಾನಿಸು GET_PS_FEATURESETTING 4121

#ವ್ಯಾಖ್ಯಾನಿಸು SPCLPASSTHROUGH2 4568

#ವ್ಯಾಖ್ಯಾನಿಸು PSIDENT_GDICENTRIC 0
#ವ್ಯಾಖ್ಯಾನಿಸು PSIDENT_PSCENTRIC 1

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _PSINJECTDATA {
    DWORD ದತ್ತಾಂಶ_ಬೈಟುಗಳು;
    ಶಬ್ದ_3 Injection_ಬಿಂದು;
    ಶಬ್ದ_3 ಪುಟ_ಸಂಖ್ಯೆ;
  } PSINJECTDATA,*PPSINJECTDATA;

#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_BEGINSTREAM 1
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_PSADOBE 2
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_PAGESATEND 3
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_ಪುಟಗಳು 4

#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_DOCNEEDEDRES 5
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_DOCSUPPLIEDRES 6
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_PAGEORDER 7
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_ORIENTATION 8
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_BOUNDINGBOX 9
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_DOCUMENTPROCESSCOLORS 10

#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_COMMENTS 11
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_BEGINDEFAULTS 12
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_ENDDEFAULTS 13
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_BEGINPROLOG 14
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_ENDPROLOG 15
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_BEGINSETUP 16
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_ENDSETUP 17
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_TRAILER 18
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_EOF 19
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_ENDSTREAM 20
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_DOCUMENTPROCESSCOLORSATEND 21

#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_PAGENUMBER 100
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_BEGINPAGESETUP 101
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_ENDPAGESETUP 102
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_PAGETRAILER 103
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_PLATECOLOR 104

#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_SHOWPAGE 105
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_PAGEBBOX 106
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_ENDPAGECOMMENTS 107

#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_VMSAVE 200
#ವ್ಯಾಖ್ಯಾನಿಸು PSINJECT_VMRESTORE 201

#ವ್ಯಾಖ್ಯಾನಿಸು FEATURESETTING_NUP 0
#ವ್ಯಾಖ್ಯಾನಿಸು FEATURESETTING_OUTPUT 1
#ವ್ಯಾಖ್ಯಾನಿಸು FEATURESETTING_PSLEVEL 2
#ವ್ಯಾಖ್ಯಾನಿಸು FEATURESETTING_CUSTPAPER 3
#ವ್ಯಾಖ್ಯಾನಿಸು FEATURESETTING_MIRROR 4
#ವ್ಯಾಖ್ಯಾನಿಸು FEATURESETTING_NEGATIVE 5
#ವ್ಯಾಖ್ಯಾನಿಸು FEATURESETTING_PROTOCOL 6

#ವ್ಯಾಖ್ಯಾನಿಸು FEATURESETTING_ಖಾಸಗಿ_BEGIN 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು FEATURESETTING_ಖಾಸಗಿ_ಕೊನೆ 0x1FFF

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _PSFEATURE_OUTPUT {
    WINBOOL b_ಪುಟ_Independent;
    WINBOOL b_ಗಣ_ಪುಟ_Device;
  } PSFEATURE_OUTPUT,*PPSFEATURE_OUTPUT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _PSFEATURE_CUSTPAPER {
    LONG lOrientation;
    LONG l_ಅಗಲ;
    LONG l_ಎತ್ತರ;
    LONG l_ಅಗಲ_ಸ್ಥಾನಾಂತರ;
    LONG l_ಎತ್ತರ_ಸ್ಥಾನಾಂತರ;
  } PSFEATURE_CUSTPAPER,*PPSFEATURE_CUSTPAPER;

#ವ್ಯಾಖ್ಯಾನಿಸು PSPROTOCOL_ASCII 0
#ವ್ಯಾಖ್ಯಾನಿಸು PSPROTOCOL_BCP 1
#ವ್ಯಾಖ್ಯಾನಿಸು PSPROTOCOL_TBCP 2
#ವ್ಯಾಖ್ಯಾನಿಸು PSPROTOCOL_ದ್ವಿಮಾನ 3

#ವ್ಯಾಖ್ಯಾನಿಸು QDI_SETDIBITS 1
#ವ್ಯಾಖ್ಯಾನಿಸು QDI_GETDIBITS 2
#ವ್ಯಾಖ್ಯಾನಿಸು QDI_DIBTOSCREEN 4
#ವ್ಯಾಖ್ಯಾನಿಸು QDI_STRETCHDIB 8

#ವ್ಯಾಖ್ಯಾನಿಸು SP_NOTREPORTED 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು SP_ERROR (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_APPABORT (-2)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_USERABORT (-3)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_OUTOFDISK (-4)
#ವ್ಯಾಖ್ಯಾನಿಸು SP_OUTOFMEMORY (-5)

#ವ್ಯಾಖ್ಯಾನಿಸು PR_JOBSTATUS 0x0000

#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_PEN 1
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_BRUSH 2
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_DC 3
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_METADC 4
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_PAL 5
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_FONT 6
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_BITMAP 7
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_REGION 8
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_METAFILE 9
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_MEMDC 10
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_EXTPEN 11
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_ENHMETADC 12
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_ENHMETAFILE 13
#ವ್ಯಾಖ್ಯಾನಿಸು OBJ_COLORSPACE 14

#ವ್ಯಾಖ್ಯಾನಿಸು MWT_ತಟಸ್ಥ 1
#ವ್ಯಾಖ್ಯಾನಿಸು MWT_LEFTMULTIPLY 2
#ವ್ಯಾಖ್ಯಾನಿಸು MWT_RIGHTMULTIPLY 3

#ವ್ಯಾಖ್ಯಾನಿಸು MWT_MIN MWT_ತಟಸ್ಥ
#ವ್ಯಾಖ್ಯಾನಿಸು MWT_MAX MWT_RIGHTMULTIPLY

#ವ್ಯಾಖ್ಯಾನಿಸು _XFORM_
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_XFORM {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
  } XFORM,*PXFORM,*LPXFORM;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_BITMAP {
    LONG bmType;
    LONG bm_ಅಗಲ;
    LONG bm_ಎತ್ತರ;
    LONG bm_ಅಗಲ_ಬೈಟುಗಳು;
    ಶಬ್ದ_3 bmPlanes;
    ಶಬ್ದ_3 bm_ಬಿಟ್ಟುಗಳು_Pixel;
    LPVOID bm_ಬಿಟ್ಟುಗಳು;
  } BITMAP,*PBITMAP,*NPBITMAP,*LPBITMAP;

#ಅನ್ತರ್ಭಾವ <pshpack1.h>
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
  } RGBTRIPLE;
#ಅನ್ತರ್ಭಾವ <poppack.h>

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_RGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
  } RGBQUAD;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ RGBQUAD *LPRGBQUAD;

#ವ್ಯಾಖ್ಯಾನಿಸು CS_ENABLE 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು CS_DISABLE 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು CS_DELETE_TRANSFORM 0x00000003L

//!__TINYC__: #define LCS_SIGNATURE 'PSOC'
//!__TINYC__: #define LCS_sRGB 'sRGB'
//!__TINYC__: #define LCS_WINDOWS_COLOR_SPACE 'Win '

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LONG LCSCSTYPE;
#ವ್ಯಾಖ್ಯಾನಿಸು LCS_CALIBRATED_RGB 0x00000000L

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LONG LCSGAMUTMATCH;
#ವ್ಯಾಖ್ಯಾನಿಸು LCS_GM_BUSINESS 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು LCS_GM_GRAPHICS 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು LCS_GM_IMAGES 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು LCS_GM_ABS_COLORIMETRIC 0x00000008L

#ವ್ಯಾಖ್ಯಾನಿಸು CM_ಹೊರಹೋಗು_ದ_GAMUT 255
#ವ್ಯಾಖ್ಯಾನಿಸು CM_ಒಳ_GAMUT 0

#ವ್ಯಾಖ್ಯಾನಿಸು ICM_ADDPROFILE 1
#ವ್ಯಾಖ್ಯಾನಿಸು ICM_DELETEPROFILE 2
#ವ್ಯಾಖ್ಯಾನಿಸು ICM_QUERYPROFILE 3
#ವ್ಯಾಖ್ಯಾನಿಸು ICM_SETDEFAULTPROFILE 4
#ವ್ಯಾಖ್ಯಾನಿಸು ICM_REGISTERICMATCHER 5
#ವ್ಯಾಖ್ಯಾನಿಸು ICM_UNREGISTERICMATCHER 6
#ವ್ಯಾಖ್ಯಾನಿಸು ICM_QUERYMATCH 7

#ವ್ಯಾಖ್ಯಾನಿಸು GetKValue(cmyk) ((BYTE)(cmyk))
#ವ್ಯಾಖ್ಯಾನಿಸು GetYValue(cmyk) ((BYTE)((cmyk)>> 8))
#ವ್ಯಾಖ್ಯಾನಿಸು GetMValue(cmyk) ((BYTE)((cmyk)>>16))
#ವ್ಯಾಖ್ಯಾನಿಸು GetCValue(cmyk) ((BYTE)((cmyk)>>24))

#ವ್ಯಾಖ್ಯಾನಿಸು CMYK(c,m,y,k) ((COLORREF)((((BYTE)(k)|((ಶಬ್ದ_3)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ FXPT16DOT16,*LPFXPT16DOT16;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ದೀರ್ಘ FXPT2DOT30,*LPFXPT2DOT30;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
  } CIEXYZ;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CIEXYZ *LPCIEXYZ;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ICEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
  } CIEXYZTRIPLE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ CIEXYZTRIPLE *LPCIEXYZTRIPLE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LOGCOLORSPACEA {
    DWORD lcsSignature;
    DWORD lcs_ಆವೃತ್ತಿ;
    DWORD lcs_ಗಾತ್ರ;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    CHAR lcsFilename[MAX_ಮಾರ್ಗ];
  } LOGCOLORSPACEA,*LPLOGCOLORSPACEA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LOGCOLORSPACEW {
    DWORD lcsSignature;
    DWORD lcs_ಆವೃತ್ತಿ;
    DWORD lcs_ಗಾತ್ರ;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    WCHAR lcsFilename[MAX_ಮಾರ್ಗ];
  } LOGCOLORSPACEW,*LPLOGCOLORSPACEW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LOGCOLORSPACEW LOGCOLORSPACE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPLOGCOLORSPACEW LPLOGCOLORSPACE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LOGCOLORSPACEA LOGCOLORSPACE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPLOGCOLORSPACEA LPLOGCOLORSPACE;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_BITMAPCOREHEADER {
    DWORD bc_ಗಾತ್ರ;
    ಶಬ್ದ_3 bc_ಅಗಲ;
    ಶಬ್ದ_3 bc_ಎತ್ತರ;
    ಶಬ್ದ_3 bcPlanes;
    ಶಬ್ದ_3 bc_ಬಿಟ್_ಎಣಿಕೆ;
  } BITMAPCOREHEADER,*LPBITMAPCOREHEADER,*PBITMAPCOREHEADER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_BITMAPINFOHEADER {
    DWORD bi_ಗಾತ್ರ;
    LONG bi_ಅಗಲ;
    LONG bi_ಎತ್ತರ;
    ಶಬ್ದ_3 biPlanes;
    ಶಬ್ದ_3 bi_ಬಿಟ್_ಎಣಿಕೆ;
    DWORD biCompression;
    DWORD bi_ಗಾತ್ರ_Image;
    LONG bi_XPels_ಪ್ರತಿ_Meter;
    LONG bi_YPels_ಪ್ರತಿ_Meter;
    DWORD bi_Clr_ಬಳಸಿದ;
    DWORD biClrImportant;
  } BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    DWORD b_V4_ಗಾತ್ರ;
    LONG b_V4_ಅಗಲ;
    LONG b_V4_ಎತ್ತರ;
    ಶಬ್ದ_3 bV4Planes;
    ಶಬ್ದ_3 b_V4_ಬಿಟ್_ಎಣಿಕೆ;
    DWORD bV4V4Compression;
    DWORD b_V4_ಗಾತ್ರ_Image;
    LONG b_V4_XPels_ಪ್ರತಿ_Meter;
    LONG b_V4_YPels_ಪ್ರತಿ_Meter;
    DWORD b_V4_Clr_ಬಳಸಿದ;
    DWORD bV4ClrImportant;
    DWORD b_V4_Red_ಮುಖವಾಡ;
    DWORD b_V4_Green_ಮುಖವಾಡ;
    DWORD b_V4_Blue_ಮುಖವಾಡ;
    DWORD b_V4_Alpha_ಮುಖವಾಡ;
    DWORD bV4CSType;
    CIEXYZTRIPLE bV4Endpoints;
    DWORD bV4GammaRed;
    DWORD bV4GammaGreen;
    DWORD bV4GammaBlue;
  } BITMAPV4_ಶೀರ್ಷಿಕೆ,*LPBITMAPV4_ಶೀರ್ಷಿಕೆ,*PBITMAPV4_ಶೀರ್ಷಿಕೆ;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ {
    DWORD b_V5_ಗಾತ್ರ;
    LONG b_V5_ಅಗಲ;
    LONG b_V5_ಎತ್ತರ;
    ಶಬ್ದ_3 bV5Planes;
    ಶಬ್ದ_3 b_V5_ಬಿಟ್_ಎಣಿಕೆ;
    DWORD bV5Compression;
    DWORD b_V5_ಗಾತ್ರ_Image;
    LONG b_V5_XPels_ಪ್ರತಿ_Meter;
    LONG b_V5_YPels_ಪ್ರತಿ_Meter;
    DWORD b_V5_Clr_ಬಳಸಿದ;
    DWORD bV5ClrImportant;
    DWORD b_V5_Red_ಮುಖವಾಡ;
    DWORD b_V5_Green_ಮುಖವಾಡ;
    DWORD b_V5_Blue_ಮುಖವಾಡ;
    DWORD b_V5_Alpha_ಮುಖವಾಡ;
    DWORD bV5CSType;
    CIEXYZTRIPLE bV5Endpoints;
    DWORD bV5GammaRed;
    DWORD bV5GammaGreen;
    DWORD bV5GammaBlue;
    DWORD bV5Intent;
    DWORD b_V5_Profile_ದತ್ತಾಂಶ;
    DWORD b_V5_Profile_ಗಾತ್ರ;
    DWORD bV5Reserved;
  } BITMAPV5_ಶೀರ್ಷಿಕೆ,*LPBITMAPV5_ಶೀರ್ಷಿಕೆ,*PBITMAPV5_ಶೀರ್ಷಿಕೆ;

//!__TINYC__: #define PROFILE_LINKED 'LINK'
//!__TINYC__: #define PROFILE_EMBEDDED 'MBED'

#ವ್ಯಾಖ್ಯಾನಿಸು BI_RGB 0L
#ವ್ಯಾಖ್ಯಾನಿಸು BI_RLE8 1L
#ವ್ಯಾಖ್ಯಾನಿಸು BI_RLE4 2L
#ವ್ಯಾಖ್ಯಾನಿಸು BI_BITFIELDS 3L
#ವ್ಯಾಖ್ಯಾನಿಸು BI_JPEG 4L
#ವ್ಯಾಖ್ಯಾನಿಸು BI_PNG 5L

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_BITMAPINFO {
    BITMAPINFOHEADER bmi_ಶೀರ್ಷಿಕೆ;
    RGBQUAD bmiColors[1];
  } BITMAPINFO,*LPBITMAPINFO,*PBITMAPINFO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_BITMAPCOREINFO {
    BITMAPCOREHEADER bmci_ಶೀರ್ಷಿಕೆ;
    RGBTRIPLE bmciColors[1];
  } BITMAPCOREINFO,*LPBITMAPCOREINFO,*PBITMAPCOREINFO;

#ಅನ್ತರ್ಭಾವ <pshpack2.h>
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_BITMAPFILEHEADER {
    ಶಬ್ದ_3 bfType;
    DWORD bf_ಗಾತ್ರ;
    ಶಬ್ದ_3 bfReserved1;
    ಶಬ್ದ_3 bfReserved2;
    DWORD bf_Off_ಬಿಟ್ಟುಗಳು;
  } BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#ಅನ್ತರ್ಭಾವ <poppack.h>

#ವ್ಯಾಖ್ಯಾನಿಸು MAKEPOINTS(l) (*((POINTS *)&(l)))

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOFONTSIG
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_FONTSIGNATURE {
    DWORD fsUsb[4];
    DWORD fsCsb[2];
  } FONTSIGNATURE,*PFONTSIGNATURE,*LPFONTSIGNATURE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_CHARSETINFO {
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
  } CHARSETINFO,*PCHARSETINFO,*NPCHARSETINFO,*LPCHARSETINFO;

#ವ್ಯಾಖ್ಯಾನಿಸು TCI_SRCCHARSET 1
#ವ್ಯಾಖ್ಯಾನಿಸು TCI_SRCCODEPAGE 2
#ವ್ಯಾಖ್ಯಾನಿಸು TCI_SRCFONTSIG 3
#ವ್ಯಾಖ್ಯಾನಿಸು TCI_SRCLOCALE 0x1000

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LOCALESIGNATURE {
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
  } LOCALESIGNATURE,*PLOCALESIGNATURE,*LPLOCALESIGNATURE;
#ಆದರೆ_ಅಂತ್ಯ


#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMETAFILE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_HANDLETABLE {
    HGDIOBJ objectHandle[1];
  } HANDLETABLE,*PHANDLETABLE,*LPHANDLETABLE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_METARECORD {
    DWORD rd_ಗಾತ್ರ;
    ಶಬ್ದ_3 rdFunction;
    ಶಬ್ದ_3 rdParm[1];
  } METARECORD;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_METARECORD UNALIGNED *PMETARECORD;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_METARECORD UNALIGNED *LPMETARECORD;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_METAFILEPICT {
    LONG mm;
    LONG xExt;
    LONG yExt;
    HMETAFILE hMF;
  } METAFILEPICT,*LPMETAFILEPICT;

#ಅನ್ತರ್ಭಾವ <pshpack2.h>
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_METAHEADER {
    ಶಬ್ದ_3 mtType;
    ಶಬ್ದ_3 mt_ಶೀರ್ಷಿಕೆ_ಗಾತ್ರ;
    ಶಬ್ದ_3 mt_ಆವೃತ್ತಿ;
    DWORD mt_ಗಾತ್ರ;
    ಶಬ್ದ_3 mtNoObjects;
    DWORD mt_Max_ದಾಖಲೆ;
    ಶಬ್ದ_3 mtNoParameters;
  } METAHEADER;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_METAHEADER UNALIGNED *PMETAHEADER;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_METAHEADER UNALIGNED *LPMETAHEADER;

#ಅನ್ತರ್ಭಾವ <poppack.h>

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENHMETARECORD {
    DWORD iType;
    DWORD n_ಗಾತ್ರ;
    DWORD dParm[1];
  } ENHMETARECORD,*PENHMETARECORD,*LPENHMETARECORD;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENHMETAHEADER {
    DWORD iType;
    DWORD n_ಗಾತ್ರ;
    RECTL rclBounds;
    RECTL rcl_ಚೌಕಟ್ಟು;
    DWORD dSignature;
    DWORD n_ಆವೃತ್ತಿ;
    DWORD n_ಬೈಟುಗಳು;
    DWORD n_ದಾಖಲೆಗಳು;
    ಶಬ್ದ_3 nHandles;
    ಶಬ್ದ_3 sReserved;
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
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOTEXTMETRIC
#ವ್ಯಾಖ್ಯಾನಿಸು TMPF_FIXED_PITCH 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು TMPF_ಸದಿಶ 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು TMPF_DEVICE 0x08
#ವ್ಯಾಖ್ಯಾನಿಸು TMPF_TRUETYPE 0x04

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WCHAR BCHAR;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ BYTE BCHAR;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _TEXTMETRIC_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _TEXTMETRIC_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_TEXTMETRICA {
    LONG tm_ಎತ್ತರ;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_ಆಂತರಿಕ_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ಅಗಲ;
    LONG tm_Max_Char_ಅಗಲ;
    LONG tm_ತೂಕ;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_ಮೊದಲ_Char;
    BYTE tm_ಕೊನೆಯ_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ಹೊರಹೋಗು;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_ಗಣ;
  } TEXTMETRICA,*PTEXTMETRICA,*NPTEXTMETRICA,*LPTEXTMETRICA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_TEXTMETRICW {
    LONG tm_ಎತ್ತರ;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_ಆಂತರಿಕ_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ಅಗಲ;
    LONG tm_Max_Char_ಅಗಲ;
    LONG tm_ತೂಕ;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_ಮೊದಲ_Char;
    WCHAR tm_ಕೊನೆಯ_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ಹೊರಹೋಗು;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_ಗಣ;
  } TEXTMETRICW,*PTEXTMETRICW,*NPTEXTMETRICW,*LPTEXTMETRICW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ TEXTMETRICW TEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PTEXTMETRICW PTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPTEXTMETRICW NPTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPTEXTMETRICW LPTEXTMETRIC;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ TEXTMETRICA TEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PTEXTMETRICA PTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPTEXTMETRICA NPTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPTEXTMETRICA LPTEXTMETRIC;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು NTM_REGULAR 0x00000040L
#ವ್ಯಾಖ್ಯಾನಿಸು NTM_BOLD 0x00000020L
#ವ್ಯಾಖ್ಯಾನಿಸು NTM_ITALIC 0x00000001L

#ವ್ಯಾಖ್ಯಾನಿಸು NTM_NONNEGATIVE_AC 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು NTM_PS_OPENTYPE 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು NTM_TT_OPENTYPE 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು NTM_MULTIPLEMASTER 0x00080000
#ವ್ಯಾಖ್ಯಾನಿಸು NTM_TYPE1 0x00100000
#ವ್ಯಾಖ್ಯಾನಿಸು NTM_DSIG 0x00200000

#ಅನ್ತರ್ಭಾವ <pshpack4.h>
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_NEWTEXTMETRICA {
    LONG tm_ಎತ್ತರ;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_ಆಂತರಿಕ_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ಅಗಲ;
    LONG tm_Max_Char_ಅಗಲ;
    LONG tm_ತೂಕ;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_ಮೊದಲ_Char;
    BYTE tm_ಕೊನೆಯ_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ಹೊರಹೋಗು;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_ಗಣ;
    DWORD ntmFlags;
    UINT ntm_ಗಾತ್ರ_EM;
    UINT ntm_Cell_ಎತ್ತರ;
    UINT ntm_Avg_ಅಗಲ;
  } NEWTEXTMETRICA,*PNEWTEXTMETRICA,*NPNEWTEXTMETRICA,*LPNEWTEXTMETRICA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_NEWTEXTMETRICW {
    LONG tm_ಎತ್ತರ;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_ಆಂತರಿಕ_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ಅಗಲ;
    LONG tm_Max_Char_ಅಗಲ;
    LONG tm_ತೂಕ;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_ಮೊದಲ_Char;
    WCHAR tm_ಕೊನೆಯ_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ಹೊರಹೋಗು;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_ಗಣ;
    DWORD ntmFlags;
    UINT ntm_ಗಾತ್ರ_EM;
    UINT ntm_Cell_ಎತ್ತರ;
    UINT ntm_Avg_ಅಗಲ;
  } NEWTEXTMETRICW,*PNEWTEXTMETRICW,*NPNEWTEXTMETRICW,*LPNEWTEXTMETRICW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NEWTEXTMETRICW NEWTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PNEWTEXTMETRICW PNEWTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPNEWTEXTMETRICW LPNEWTEXTMETRIC;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NEWTEXTMETRICA NEWTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PNEWTEXTMETRICA PNEWTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPNEWTEXTMETRICA LPNEWTEXTMETRIC;
#ಆದರೆ_ಅಂತ್ಯ
#ಅನ್ತರ್ಭಾವ <poppack.h>

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_NEWTEXTMETRICEXA {
    NEWTEXTMETRICA ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_NEWTEXTMETRICEXW {
    NEWTEXTMETRICW ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NEWTEXTMETRICEXW NEWTEXTMETRICEX;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NEWTEXTMETRICEXA NEWTEXTMETRICEX;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_PELARRAY {
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
  } PELARRAY,*PPELARRAY,*NPPELARRAY,*LPPELARRAY;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LOGBRUSH {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
  } LOGBRUSH,*PLOGBRUSH,*NPLOGBRUSH,*LPLOGBRUSH;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LOGBRUSH32 {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG lbHatch;
  } LOGBRUSH32,*PLOGBRUSH32,*NPLOGBRUSH32,*LPLOGBRUSH32;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LOGBRUSH ನಮೂನೆ_2;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ನಮೂನೆ_2 *PPATTERN;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ನಮೂನೆ_2 *NPPATTERN;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ನಮೂನೆ_2 *LPPATTERN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LOGPEN {
    UINT lopnStyle;
    ಬಿಂದು_3 lopn_ಅಗಲ;
    COLORREF lopnColor;
  } LOGPEN,*PLOGPEN,*NPLOGPEN,*LPLOGPEN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EXTLOGPEN {
    DWORD elpPenStyle;
    DWORD elp_ಅಗಲ;
    UINT elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elp_ಅಂಕೆ_Entries;
    DWORD elp_Style_ನಮೂದು[1];
  } EXTLOGPEN,*PEXTLOGPEN,*NPEXTLOGPEN,*LPEXTLOGPEN;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _PALETTEENTRY_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _PALETTEENTRY_DEFINED
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_PALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
  } PALETTEENTRY,*PPALETTEENTRY,*LPPALETTEENTRY;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ _LOGPALETTE_DEFINED
#ವ್ಯಾಖ್ಯಾನಿಸು _LOGPALETTE_DEFINED

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LOGPALETTE {
    ಶಬ್ದ_3 pal_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3 pal_ಅಂಕೆ_Entries;
    PALETTEENTRY pal_Pal_ನಮೂದು[1];
  } LOGPALETTE,*PLOGPALETTE,*NPLOGPALETTE,*LPLOGPALETTE;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು LF_FACESIZE 32

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LOGFONTA {
    LONG lf_ಎತ್ತರ;
    LONG lf_ಅಗಲ;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_ತೂಕ;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_ಹೊರಹೋಗು;
    BYTE lf_Char_ಗಣ;
    BYTE lf_ಹೊರಹೋಗು_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[LF_FACESIZE];
  } LOGFONTA,*PLOGFONTA,*NPLOGFONTA,*LPLOGFONTA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LOGFONTW {
    LONG lf_ಎತ್ತರ;
    LONG lf_ಅಗಲ;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_ತೂಕ;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_ಹೊರಹೋಗು;
    BYTE lf_Char_ಗಣ;
    BYTE lf_ಹೊರಹೋಗು_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[LF_FACESIZE];
  } LOGFONTW,*PLOGFONTW,*NPLOGFONTW,*LPLOGFONTW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LOGFONTW LOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PLOGFONTW PLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPLOGFONTW NPLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPLOGFONTW LPLOGFONT;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LOGFONTA LOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PLOGFONTA PLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPLOGFONTA NPLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPLOGFONTA LPLOGFONT;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು LF_FULLFACESIZE 64

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENUMLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_ತುಂಬಿದ_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
  } ENUMLOGFONTA,*LPENUMLOGFONTA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENUMLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_ತುಂಬಿದ_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
  } ENUMLOGFONTW,*LPENUMLOGFONTW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ENUMLOGFONTW ENUMLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPENUMLOGFONTW LPENUMLOGFONT;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ENUMLOGFONTA ENUMLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPENUMLOGFONTA LPENUMLOGFONT;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENUMLOGFONTEXA {
    LOGFONTA elfLogFont;
    BYTE elf_ತುಂಬಿದ_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    BYTE elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXA,*LPENUMLOGFONTEXA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENUMLOGFONTEXW {
    LOGFONTW elfLogFont;
    WCHAR elf_ತುಂಬಿದ_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    WCHAR elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXW,*LPENUMLOGFONTEXW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ENUMLOGFONTEXW ENUMLOGFONTEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPENUMLOGFONTEXW LPENUMLOGFONTEX;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ENUMLOGFONTEXA ENUMLOGFONTEX;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPENUMLOGFONTEXA LPENUMLOGFONTEX;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_DEFAULT_PRECIS 0
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_STRING_PRECIS 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_CHARACTER_PRECIS 2
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_STROKE_PRECIS 3
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_TT_PRECIS 4
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_DEVICE_PRECIS 5
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_RASTER_PRECIS 6
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_TT_ONLY_PRECIS 7
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_OUTLINE_PRECIS 8
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_SCREEN_OUTLINE_PRECIS 9
#ವ್ಯಾಖ್ಯಾನಿಸು ಹೊರಹೋಗು_PS_ONLY_PRECIS 10

#ವ್ಯಾಖ್ಯಾನಿಸು CLIP_DEFAULT_PRECIS 0
#ವ್ಯಾಖ್ಯಾನಿಸು CLIP_CHARACTER_PRECIS 1
#ವ್ಯಾಖ್ಯಾನಿಸು CLIP_STROKE_PRECIS 2
#ವ್ಯಾಖ್ಯಾನಿಸು CLIP_ಮುಖವಾಡ 0xf
#ವ್ಯಾಖ್ಯಾನಿಸು CLIP_LH_ANGLES (1<<4)
#ವ್ಯಾಖ್ಯಾನಿಸು CLIP_TT_ALWAYS (2<<4)
#ವ್ಯಾಖ್ಯಾನಿಸು CLIP_DFA_DISABLE (4<<4)
#ವ್ಯಾಖ್ಯಾನಿಸು CLIP_EMBEDDED (8<<4)

#ವ್ಯಾಖ್ಯಾನಿಸು DEFAULT_QUALITY 0
#ವ್ಯಾಖ್ಯಾನಿಸು DRAFT_QUALITY 1
#ವ್ಯಾಖ್ಯಾನಿಸು PROOF_QUALITY 2
#ವ್ಯಾಖ್ಯಾನಿಸು NONANTIALIASED_QUALITY 3
#ವ್ಯಾಖ್ಯಾನಿಸು ANTIALIASED_QUALITY 4

#ವ್ಯಾಖ್ಯಾನಿಸು CLEARTYPE_QUALITY 5
#ವ್ಯಾಖ್ಯಾನಿಸು CLEARTYPE_NATURAL_QUALITY 6

#ವ್ಯಾಖ್ಯಾನಿಸು DEFAULT_PITCH 0
#ವ್ಯಾಖ್ಯಾನಿಸು FIXED_PITCH 1
#ವ್ಯಾಖ್ಯಾನಿಸು VARIABLE_PITCH 2
#ವ್ಯಾಖ್ಯಾನಿಸು MONO_FONT 8

#ವ್ಯಾಖ್ಯಾನಿಸು ANSI_CHARSET 0
#ವ್ಯಾಖ್ಯಾನಿಸು DEFAULT_CHARSET 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಚಿಹ್ನೆ_CHARSET 2
#ವ್ಯಾಖ್ಯಾನಿಸು SHIFTJIS_CHARSET 128
#ವ್ಯಾಖ್ಯಾನಿಸು HANGEUL_CHARSET 129
#ವ್ಯಾಖ್ಯಾನಿಸು HANGUL_CHARSET 129
#ವ್ಯಾಖ್ಯಾನಿಸು GB2312_CHARSET 134
#ವ್ಯಾಖ್ಯಾನಿಸು CHINESEBIG5_CHARSET 136
#ವ್ಯಾಖ್ಯಾನಿಸು OEM_CHARSET 255
#ವ್ಯಾಖ್ಯಾನಿಸು JOHAB_CHARSET 130
#ವ್ಯಾಖ್ಯಾನಿಸು HEBREW_CHARSET 177
#ವ್ಯಾಖ್ಯಾನಿಸು ARABIC_CHARSET 178
#ವ್ಯಾಖ್ಯಾನಿಸು GREEK_CHARSET 161
#ವ್ಯಾಖ್ಯಾನಿಸು TURKISH_CHARSET 162
#ವ್ಯಾಖ್ಯಾನಿಸು VIETNAMESE_CHARSET 163
#ವ್ಯಾಖ್ಯಾನಿಸು THAI_CHARSET 222
#ವ್ಯಾಖ್ಯಾನಿಸು EASTEUROPE_CHARSET 238
#ವ್ಯಾಖ್ಯಾನಿಸು RUSSIAN_CHARSET 204

#ವ್ಯಾಖ್ಯಾನಿಸು MAC_CHARSET 77
#ವ್ಯಾಖ್ಯಾನಿಸು BALTIC_CHARSET 186

#ವ್ಯಾಖ್ಯಾನಿಸು FS_LATIN1 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_LATIN2 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_CYRILLIC 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_GREEK 0x00000008L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_TURKISH 0x00000010L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_HEBREW 0x00000020L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_ARABIC 0x00000040L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_BALTIC 0x00000080L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_VIETNAMESE 0x00000100L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_THAI 0x00010000L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_JISJAPAN 0x00020000L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_CHINESESIMP 0x00040000L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_WANSUNG 0x00080000L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_CHINESETRAD 0x00100000L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_JOHAB 0x00200000L
#ವ್ಯಾಖ್ಯಾನಿಸು FS_ಚಿಹ್ನೆ 0x80000000L

#ವ್ಯಾಖ್ಯಾನಿಸು FF_DONTCARE (0<<4)
#ವ್ಯಾಖ್ಯಾನಿಸು FF_ROMAN (1<<4)

#ವ್ಯಾಖ್ಯಾನಿಸು FF_SWISS (2<<4)

#ವ್ಯಾಖ್ಯಾನಿಸು FF_MODERN (3<<4)

#ವ್ಯಾಖ್ಯಾನಿಸು FF_SCRIPT (4<<4)
#ವ್ಯಾಖ್ಯಾನಿಸು FF_DECORATIVE (5<<4)

#ವ್ಯಾಖ್ಯಾನಿಸು FW_DONTCARE 0
#ವ್ಯಾಖ್ಯಾನಿಸು FW_THIN 100
#ವ್ಯಾಖ್ಯಾನಿಸು FW_EXTRALIGHT 200
#ವ್ಯಾಖ್ಯಾನಿಸು FW_LIGHT 300
#ವ್ಯಾಖ್ಯಾನಿಸು FW_ಸಾಮಾನ್ಯ 400
#ವ್ಯಾಖ್ಯಾನಿಸು FW_MEDIUM 500
#ವ್ಯಾಖ್ಯಾನಿಸು FW_SEMIBOLD 600
#ವ್ಯಾಖ್ಯಾನಿಸು FW_BOLD 700
#ವ್ಯಾಖ್ಯಾನಿಸು FW_EXTRABOLD 800
#ವ್ಯಾಖ್ಯಾನಿಸು FW_HEAVY 900

#ವ್ಯಾಖ್ಯಾನಿಸು FW_ULTRALIGHT FW_EXTRALIGHT
#ವ್ಯಾಖ್ಯಾನಿಸು FW_REGULAR FW_ಸಾಮಾನ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು FW_DEMIBOLD FW_SEMIBOLD
#ವ್ಯಾಖ್ಯಾನಿಸು FW_ULTRABOLD FW_EXTRABOLD
#ವ್ಯಾಖ್ಯಾನಿಸು FW_BLACK FW_HEAVY

#ವ್ಯಾಖ್ಯಾನಿಸು PANOSE_ಎಣಿಕೆ 10
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_FAMILYTYPE_ಸೂಚ್ಯಂಕ 0
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIFSTYLE_ಸೂಚ್ಯಂಕ 1
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_ಸೂಚ್ಯಂಕ 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_PROPORTION_ಸೂಚ್ಯಂಕ 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CONTRAST_ಸೂಚ್ಯಂಕ 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STROKEVARIATION_ಸೂಚ್ಯಂಕ 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ARMSTYLE_ಸೂಚ್ಯಂಕ 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETTERFORM_ಸೂಚ್ಯಂಕ 7
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_ಸೂಚ್ಯಂಕ 8
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_XHEIGHT_ಸೂಚ್ಯಂಕ 9

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CULTURE_LATIN 0

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_PANOSE {
    BYTE bFamilyType;
    BYTE bSerifStyle;
    BYTE b_ತೂಕ;
    BYTE bProportion;
    BYTE bContrast;
    BYTE bStrokeVariation;
    BYTE bArmStyle;
    BYTE bLetterform;
    BYTE bMidline;
    BYTE bXHeight;
  } PANOSE,*LPPANOSE;

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ANY 0
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_NO_FIT 1

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_FAMILY_ಪಠ್ಯ_DISPLAY 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_FAMILY_SCRIPT 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_FAMILY_DECORATIVE 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_FAMILY_PICTORIAL 5

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_COVE 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_OBTUSE_COVE 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_ವರ್ಗಫಲ_COVE 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_OBTUSE_ವರ್ಗಫಲ_COVE 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_ವರ್ಗಫಲ 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_THIN 7
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_BONE 8
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_EXAGGERATED 9
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_TRIANGLE 10
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_ಸಾಮಾನ್ಯ_SANS 11
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_OBTUSE_SANS 12
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_PERP_SANS 13
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_FLARED 14
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_SERIF_ROUNDED 15

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_VERY_LIGHT 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_LIGHT 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_THIN 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_BOOK 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_MEDIUM 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_DEMI 7
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_BOLD 8
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_HEAVY 9
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_BLACK 10
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_ತೂಕ_NORD 11

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_PROP_OLD_STYLE 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_PROP_MODERN 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_PROP_EVEN_ಅಗಲ 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_PROP_EXPANDED 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_PROP_CONDENSED 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_PROP_VERY_EXPANDED 7
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_PROP_VERY_CONDENSED 8
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_PROP_MONOSPACED 9

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CONTRAST_NONE 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CONTRAST_VERY_ಕೆಳಗಿನ 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CONTRAST_ಕೆಳಗಿನ 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CONTRAST_MEDIUM_ಕೆಳಗಿನ 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CONTRAST_MEDIUM 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CONTRAST_MEDIUM_ಮೇಲಿನ 7
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CONTRAST_ಮೇಲಿನ 8
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_CONTRAST_VERY_ಮೇಲಿನ 9

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STROKE_GRADUAL_DIAG 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STROKE_GRADUAL_TRAN 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STROKE_GRADUAL_VERT 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STROKE_GRADUAL_HORZ 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STROKE_RAPID_VERT 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STROKE_RAPID_HORZ 7
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STROKE_INSTANT_VERT 8

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STRAIGHT_ARMS_HORZ 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STRAIGHT_ARMS_WEDGE 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STRAIGHT_ARMS_VERT 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STRAIGHT_ARMS_SINGLE_SERIF 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_STRAIGHT_ARMS_DOUBLE_SERIF 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_BENT_ARMS_HORZ 7
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_BENT_ARMS_WEDGE 8
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_BENT_ARMS_VERT 9
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_BENT_ARMS_SINGLE_SERIF 10
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_BENT_ARMS_DOUBLE_SERIF 11

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_ಸಾಮಾನ್ಯ_CONTACT 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_ಸಾಮಾನ್ಯ_WEIGHTED 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_ಸಾಮಾನ್ಯ_BOXED 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_ಸಾಮಾನ್ಯ_FLATTENED 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_ಸಾಮಾನ್ಯ_ROUNDED 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_ಸಾಮಾನ್ಯ_OFF_CENTER 7
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_ಸಾಮಾನ್ಯ_ವರ್ಗಫಲ 8
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_OBLIQUE_CONTACT 9
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_OBLIQUE_WEIGHTED 10
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_OBLIQUE_BOXED 11
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_OBLIQUE_FLATTENED 12
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_OBLIQUE_ROUNDED 13
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_OBLIQUE_OFF_CENTER 14
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_LETT_OBLIQUE_ವರ್ಗಫಲ 15

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_STANDARD_TRIMMED 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_STANDARD_POINTED 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_STANDARD_SERIFED 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_ಮೇಲಿನ_TRIMMED 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_ಮೇಲಿನ_POINTED 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_ಮೇಲಿನ_SERIFED 7
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_CONSTANT_TRIMMED 8
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_CONSTANT_POINTED 9
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_CONSTANT_SERIFED 10
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_ಕೆಳಗಿನ_TRIMMED 11
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_ಕೆಳಗಿನ_POINTED 12
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_MIDLINE_ಕೆಳಗಿನ_SERIFED 13

#ವ್ಯಾಖ್ಯಾನಿಸು PAN_XHEIGHT_CONSTANT_SMALL 2
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_XHEIGHT_CONSTANT_STD 3
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_XHEIGHT_CONSTANT_LARGE 4
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_XHEIGHT_DUCKING_SMALL 5
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_XHEIGHT_DUCKING_STD 6
#ವ್ಯಾಖ್ಯಾನಿಸು PAN_XHEIGHT_DUCKING_LARGE 7

#ವ್ಯಾಖ್ಯಾನಿಸು ELF_VENDOR_ಗಾತ್ರ 4

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EXTLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_ತುಂಬಿದ_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    DWORD elf_ಆವೃತ್ತಿ;
    DWORD elf_Style_ಗಾತ್ರ;
    DWORD elf_ಹೊಂದಿಕೆ;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_ಗಾತ್ರ];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTA,*PEXTLOGFONTA,*NPEXTLOGFONTA,*LPEXTLOGFONTA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EXTLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_ತುಂಬಿದ_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    DWORD elf_ಆವೃತ್ತಿ;
    DWORD elf_Style_ಗಾತ್ರ;
    DWORD elf_ಹೊಂದಿಕೆ;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_ಗಾತ್ರ];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTW,*PEXTLOGFONTW,*NPEXTLOGFONTW,*LPEXTLOGFONTW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ EXTLOGFONTW EXTLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PEXTLOGFONTW PEXTLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPEXTLOGFONTW NPEXTLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPEXTLOGFONTW LPEXTLOGFONT;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ EXTLOGFONTA EXTLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PEXTLOGFONTA PEXTLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPEXTLOGFONTA NPEXTLOGFONT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPEXTLOGFONTA LPEXTLOGFONT;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು ELF_ಆವೃತ್ತಿ 0
#ವ್ಯಾಖ್ಯಾನಿಸು ELF_CULTURE_LATIN 0

#ವ್ಯಾಖ್ಯಾನಿಸು RASTER_FONTTYPE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DEVICE_FONTTYPE 0x002
#ವ್ಯಾಖ್ಯಾನಿಸು TRUETYPE_FONTTYPE 0x004

#ವ್ಯಾಖ್ಯಾನಿಸು RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((ಶಬ್ದ_3)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#ವ್ಯಾಖ್ಯಾನಿಸು PALETTERGB(r,g,b) (0x02000000 | RGB(r,g,b))
#ವ್ಯಾಖ್ಯಾನಿಸು PALETTEINDEX(i) ((COLORREF)(0x01000000 | (DWORD)(ಶಬ್ದ_3)(i)))

#ವ್ಯಾಖ್ಯಾನಿಸು PC_RESERVED 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು PC_EXPLICIT 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು PC_NOCOLLAPSE 0x04

#ವ್ಯಾಖ್ಯಾನಿಸು GetRValue(rgb) (LOBYTE(rgb))
#ವ್ಯಾಖ್ಯಾನಿಸು GetGValue(rgb) (LOBYTE(((ಶಬ್ದ_3)(rgb)) >> 8))
#ವ್ಯಾಖ್ಯಾನಿಸು GetBValue(rgb) (LOBYTE((rgb)>>16))

#ವ್ಯಾಖ್ಯಾನಿಸು TRANSPARENT 1
#ವ್ಯಾಖ್ಯಾನಿಸು OPAQUE 2
#ವ್ಯಾಖ್ಯಾನಿಸು BKMODE_ಕೊನೆಯ 2

#ವ್ಯಾಖ್ಯಾನಿಸು GM_COMPATIBLE 1
#ವ್ಯಾಖ್ಯಾನಿಸು GM_ADVANCED 2
#ವ್ಯಾಖ್ಯಾನಿಸು GM_ಕೊನೆಯ 2

#ವ್ಯಾಖ್ಯಾನಿಸು PT_CLOSEFIGURE 0x01
#ವ್ಯಾಖ್ಯಾನಿಸು PT_LINETO 0x02
#ವ್ಯಾಖ್ಯಾನಿಸು PT_BEZIERTO 0x04
#ವ್ಯಾಖ್ಯಾನಿಸು PT_MOVETO 0x06

#ವ್ಯಾಖ್ಯಾನಿಸು MM_ಪಠ್ಯ 1
#ವ್ಯಾಖ್ಯಾನಿಸು MM_LOMETRIC 2
#ವ್ಯಾಖ್ಯಾನಿಸು MM_HIMETRIC 3
#ವ್ಯಾಖ್ಯಾನಿಸು MM_LOENGLISH 4
#ವ್ಯಾಖ್ಯಾನಿಸು MM_HIENGLISH 5
#ವ್ಯಾಖ್ಯಾನಿಸು MM_TWIPS 6
#ವ್ಯಾಖ್ಯಾನಿಸು MM_ISOTROPIC 7
#ವ್ಯಾಖ್ಯಾನಿಸು MM_ANISOTROPIC 8

#ವ್ಯಾಖ್ಯಾನಿಸು MM_MIN MM_ಪಠ್ಯ
#ವ್ಯಾಖ್ಯಾನಿಸು MM_MAX MM_ANISOTROPIC
#ವ್ಯಾಖ್ಯಾನಿಸು MM_MAX_FIXEDSCALE MM_TWIPS

#ವ್ಯಾಖ್ಯಾನಿಸು ABSOLUTE 1
#ವ್ಯಾಖ್ಯಾನಿಸು RELATIVE 2

#ವ್ಯಾಖ್ಯಾನಿಸು WHITE_BRUSH 0
#ವ್ಯಾಖ್ಯಾನಿಸು LTGRAY_BRUSH 1
#ವ್ಯಾಖ್ಯಾನಿಸು ಬೂದು_BRUSH 2
#ವ್ಯಾಖ್ಯಾನಿಸು DKGRAY_BRUSH 3
#ವ್ಯಾಖ್ಯಾನಿಸು BLACK_BRUSH 4
#ವ್ಯಾಖ್ಯಾನಿಸು NULL_BRUSH 5
#ವ್ಯಾಖ್ಯಾನಿಸು HOLLOW_BRUSH NULL_BRUSH
#ವ್ಯಾಖ್ಯಾನಿಸು WHITE_PEN 6
#ವ್ಯಾಖ್ಯಾನಿಸು BLACK_PEN 7
#ವ್ಯಾಖ್ಯಾನಿಸು NULL_PEN 8
#ವ್ಯಾಖ್ಯಾನಿಸು OEM_FIXED_FONT 10
#ವ್ಯಾಖ್ಯಾನಿಸು ANSI_FIXED_FONT 11
#ವ್ಯಾಖ್ಯಾನಿಸು ANSI_VAR_FONT 12
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_FONT 13
#ವ್ಯಾಖ್ಯಾನಿಸು DEVICE_DEFAULT_FONT 14
#ವ್ಯಾಖ್ಯಾನಿಸು DEFAULT_PALETTE 15
#ವ್ಯಾಖ್ಯಾನಿಸು SYSTEM_FIXED_FONT 16

#ವ್ಯಾಖ್ಯಾನಿಸು DEFAULT_GUI_FONT 17

#ವ್ಯಾಖ್ಯಾನಿಸು DC_BRUSH 18
#ವ್ಯಾಖ್ಯಾನಿಸು DC_PEN 19

#ವ್ಯಾಖ್ಯಾನಿಸು STOCK_ಕೊನೆಯ 19

#ವ್ಯಾಖ್ಯಾನಿಸು CLR_INVALID 0xFFFFFFFF

#ವ್ಯಾಖ್ಯಾನಿಸು BS_SOLID 0
#ವ್ಯಾಖ್ಯಾನಿಸು BS_NULL 1
#ವ್ಯಾಖ್ಯಾನಿಸು BS_HOLLOW BS_NULL
#ವ್ಯಾಖ್ಯಾನಿಸು BS_HATCHED 2
#ವ್ಯಾಖ್ಯಾನಿಸು BS_ನಮೂನೆ 3
#ವ್ಯಾಖ್ಯಾನಿಸು BS_ಸೂಚ್ಯಂಕಿತ 4
#ವ್ಯಾಖ್ಯಾನಿಸು BS_DIBPATTERN 5
#ವ್ಯಾಖ್ಯಾನಿಸು BS_DIBPATTERNPT 6
#ವ್ಯಾಖ್ಯಾನಿಸು BS_PATTERN8X8 7
#ವ್ಯಾಖ್ಯಾನಿಸು BS_DIBPATTERN8X8 8
#ವ್ಯಾಖ್ಯಾನಿಸು BS_MONOPATTERN 9

#ವ್ಯಾಖ್ಯಾನಿಸು HS_HORIZONTAL 0
#ವ್ಯಾಖ್ಯಾನಿಸು HS_VERTICAL 1
#ವ್ಯಾಖ್ಯಾನಿಸು HS_FDIAGONAL 2
#ವ್ಯಾಖ್ಯಾನಿಸು HS_BDIAGONAL 3
#ವ್ಯಾಖ್ಯಾನಿಸು HS_CROSS 4
#ವ್ಯಾಖ್ಯಾನಿಸು HS_DIAGCROSS 5

#ವ್ಯಾಖ್ಯಾನಿಸು PS_SOLID 0
#ವ್ಯಾಖ್ಯಾನಿಸು PS_DASH 1
#ವ್ಯಾಖ್ಯಾನಿಸು PS_DOT 2
#ವ್ಯಾಖ್ಯಾನಿಸು PS_DASHDOT 3
#ವ್ಯಾಖ್ಯಾನಿಸು PS_DASHDOTDOT 4
#ವ್ಯಾಖ್ಯಾನಿಸು PS_NULL 5
#ವ್ಯಾಖ್ಯಾನಿಸು PS_INSIDEFRAME 6
#ವ್ಯಾಖ್ಯಾನಿಸು PS_USERSTYLE 7
#ವ್ಯಾಖ್ಯಾನಿಸು PS_ALTERNATE 8
#ವ್ಯಾಖ್ಯಾನಿಸು PS_STYLE_ಮುಖವಾಡ 0x0000000F

#ವ್ಯಾಖ್ಯಾನಿಸು PS_ENDCAP_ಸುತ್ತು 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು PS_ENDCAP_ವರ್ಗಫಲ 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು PS_ENDCAP_FLAT 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು PS_ENDCAP_ಮುಖವಾಡ 0x00000F00

#ವ್ಯಾಖ್ಯಾನಿಸು PS_JOIN_ಸುತ್ತು 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು PS_JOIN_BEVEL 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು PS_JOIN_MITER 0x00002000
#ವ್ಯಾಖ್ಯಾನಿಸು PS_JOIN_ಮುಖವಾಡ 0x0000F000

#ವ್ಯಾಖ್ಯಾನಿಸು PS_COSMETIC 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು PS_GEOMETRIC 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು PS_TYPE_ಮುಖವಾಡ 0x000F0000

#ವ್ಯಾಖ್ಯಾನಿಸು AD_COUNTERCLOCKWISE 1
#ವ್ಯಾಖ್ಯಾನಿಸು AD_CLOCKWISE 2

#ವ್ಯಾಖ್ಯಾನಿಸು DRIVERVERSION 0
#ವ್ಯಾಖ್ಯಾನಿಸು TECHNOLOGY 2
#ವ್ಯಾಖ್ಯಾನಿಸು HORZSIZE 4
#ವ್ಯಾಖ್ಯಾನಿಸು VERTSIZE 6
#ವ್ಯಾಖ್ಯಾನಿಸು HORZRES 8
#ವ್ಯಾಖ್ಯಾನಿಸು VERTRES 10
#ವ್ಯಾಖ್ಯಾನಿಸು BITSPIXEL 12
#ವ್ಯಾಖ್ಯಾನಿಸು PLANES 14
#ವ್ಯಾಖ್ಯಾನಿಸು NUMBRUSHES 16
#ವ್ಯಾಖ್ಯಾನಿಸು NUMPENS 18
#ವ್ಯಾಖ್ಯಾನಿಸು NUMMARKERS 20
#ವ್ಯಾಖ್ಯಾನಿಸು NUMFONTS 22
#ವ್ಯಾಖ್ಯಾನಿಸು NUMCOLORS 24
#ವ್ಯಾಖ್ಯಾನಿಸು PDEVICESIZE 26
#ವ್ಯಾಖ್ಯಾನಿಸು CURVECAPS 28
#ವ್ಯಾಖ್ಯಾನಿಸು LINECAPS 30
#ವ್ಯಾಖ್ಯಾನಿಸು POLYGONALCAPS 32
#ವ್ಯಾಖ್ಯಾನಿಸು TEXTCAPS 34
#ವ್ಯಾಖ್ಯಾನಿಸು CLIPCAPS 36
#ವ್ಯಾಖ್ಯಾನಿಸು RASTERCAPS 38
#ವ್ಯಾಖ್ಯಾನಿಸು ASPECTX 40
#ವ್ಯಾಖ್ಯಾನಿಸು ASPECTY 42
#ವ್ಯಾಖ್ಯಾನಿಸು ASPECTXY 44

#ವ್ಯಾಖ್ಯಾನಿಸು LOGPIXELSX 88
#ವ್ಯಾಖ್ಯಾನಿಸು LOGPIXELSY 90

#ವ್ಯಾಖ್ಯಾನಿಸು SIZEPALETTE 104
#ವ್ಯಾಖ್ಯಾನಿಸು NUMRESERVED 106
#ವ್ಯಾಖ್ಯಾನಿಸು COLORRES 108

#ವ್ಯಾಖ್ಯಾನಿಸು PHYSICALWIDTH 110
#ವ್ಯಾಖ್ಯಾನಿಸು PHYSICALHEIGHT 111
#ವ್ಯಾಖ್ಯಾನಿಸು PHYSICALOFFSETX 112
#ವ್ಯಾಖ್ಯಾನಿಸು PHYSICALOFFSETY 113
#ವ್ಯಾಖ್ಯಾನಿಸು SCALINGFACTORX 114
#ವ್ಯಾಖ್ಯಾನಿಸು SCALINGFACTORY 115

#ವ್ಯಾಖ್ಯಾನಿಸು VREFRESH 116

#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOPVERTRES 117

#ವ್ಯಾಖ್ಯಾನಿಸು DESKTOPHORZRES 118

#ವ್ಯಾಖ್ಯಾನಿಸು BLTALIGNMENT 119

#ವ್ಯಾಖ್ಯಾನಿಸು SHADEBLENDCAPS 120
#ವ್ಯಾಖ್ಯಾನಿಸು COLORMGMTCAPS 121

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOGDICAPMASKS
#ವ್ಯಾಖ್ಯಾನಿಸು DT_PLOTTER 0
#ವ್ಯಾಖ್ಯಾನಿಸು DT_RASDISPLAY 1
#ವ್ಯಾಖ್ಯಾನಿಸು DT_RASPRINTER 2
#ವ್ಯಾಖ್ಯಾನಿಸು DT_RASCAMERA 3
#ವ್ಯಾಖ್ಯಾನಿಸು DT_CHARSTREAM 4
#ವ್ಯಾಖ್ಯಾನಿಸು DT_METAFILE 5
#ವ್ಯಾಖ್ಯಾನಿಸು DT_DISPFILE 6

#ವ್ಯಾಖ್ಯಾನಿಸು CC_NONE 0
#ವ್ಯಾಖ್ಯಾನಿಸು CC_CIRCLES 1
#ವ್ಯಾಖ್ಯಾನಿಸು CC_PIE 2
#ವ್ಯಾಖ್ಯಾನಿಸು CC_CHORD 4
#ವ್ಯಾಖ್ಯಾನಿಸು CC_ELLIPSES 8
#ವ್ಯಾಖ್ಯಾನಿಸು CC_WIDE 16
#ವ್ಯಾಖ್ಯಾನಿಸು CC_STYLED 32
#ವ್ಯಾಖ್ಯಾನಿಸು CC_WIDESTYLED 64
#ವ್ಯಾಖ್ಯಾನಿಸು CC_INTERIORS 128
#ವ್ಯಾಖ್ಯಾನಿಸು CC_ROUNDRECT 256

#ವ್ಯಾಖ್ಯಾನಿಸು LC_NONE 0
#ವ್ಯಾಖ್ಯಾನಿಸು LC_POLYLINE 2
#ವ್ಯಾಖ್ಯಾನಿಸು LC_MARKER 4
#ವ್ಯಾಖ್ಯಾನಿಸು LC_POLYMARKER 8
#ವ್ಯಾಖ್ಯಾನಿಸು LC_WIDE 16
#ವ್ಯಾಖ್ಯಾನಿಸು LC_STYLED 32
#ವ್ಯಾಖ್ಯಾನಿಸು LC_WIDESTYLED 64
#ವ್ಯಾಖ್ಯಾನಿಸು LC_INTERIORS 128

#ವ್ಯಾಖ್ಯಾನಿಸು PC_NONE 0
#ವ್ಯಾಖ್ಯಾನಿಸು PC_POLYGON 1
#ವ್ಯಾಖ್ಯಾನಿಸು PC_RECTANGLE 2
#ವ್ಯಾಖ್ಯಾನಿಸು PC_WINDPOLYGON 4
#ವ್ಯಾಖ್ಯಾನಿಸು PC_TRAPEZOID 4
#ವ್ಯಾಖ್ಯಾನಿಸು PC_SCANLINE 8
#ವ್ಯಾಖ್ಯಾನಿಸು PC_WIDE 16
#ವ್ಯಾಖ್ಯಾನಿಸು PC_STYLED 32
#ವ್ಯಾಖ್ಯಾನಿಸು PC_WIDESTYLED 64
#ವ್ಯಾಖ್ಯಾನಿಸು PC_INTERIORS 128
#ವ್ಯಾಖ್ಯಾನಿಸು PC_POLYPOLYGON 256
#ವ್ಯಾಖ್ಯಾನಿಸು PC_PATHS 512

#ವ್ಯಾಖ್ಯಾನಿಸು CP_NONE 0
#ವ್ಯಾಖ್ಯಾನಿಸು CP_RECTANGLE 1
#ವ್ಯಾಖ್ಯಾನಿಸು CP_REGION 2

#ವ್ಯಾಖ್ಯಾನಿಸು TC_OP_CHARACTER 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು TC_OP_STROKE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು TC_CP_STROKE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು TC_CR_90 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು TC_CR_ANY 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು TC_SF_X_YINDEP 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು TC_SA_DOUBLE 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು TC_SA_INTEGER 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು TC_SA_CONTIN 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು TC_EA_DOUBLE 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು TC_IA_ABLE 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು TC_UA_ABLE 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು TC_SO_ABLE 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು TC_RA_ABLE 0x00002000
#ವ್ಯಾಖ್ಯಾನಿಸು TC_VA_ABLE 0x00004000
#ವ್ಯಾಖ್ಯಾನಿಸು TC_RESERVED 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು TC_SCROLLBLT 0x00010000
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು RC_NONE
#ವ್ಯಾಖ್ಯಾನಿಸು RC_BITBLT 1
#ವ್ಯಾಖ್ಯಾನಿಸು RC_BANDING 2
#ವ್ಯಾಖ್ಯಾನಿಸು RC_SCALING 4
#ವ್ಯಾಖ್ಯಾನಿಸು RC_BITMAP64 8
#ವ್ಯಾಖ್ಯಾನಿಸು RC_GDI20_OUTPUT 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು RC_GDI20_STATE 0x0020
#ವ್ಯಾಖ್ಯಾನಿಸು RC_SAVEBITMAP 0x0040
#ವ್ಯಾಖ್ಯಾನಿಸು RC_DI_BITMAP 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು RC_PALETTE 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು RC_DIBTODEV 0x0200
#ವ್ಯಾಖ್ಯಾನಿಸು RC_BIGFONT 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು RC_STRETCHBLT 0x0800
#ವ್ಯಾಖ್ಯಾನಿಸು RC_FLOODFILL 0x1000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_STRETCHDIB 0x2000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_OP_DX_OUTPUT 0x4000
#ವ್ಯಾಖ್ಯಾನಿಸು RC_DEVBITS 0x8000

#ವ್ಯಾಖ್ಯಾನಿಸು SB_NONE 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು SB_CONST_ALPHA 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು SB_PIXEL_ALPHA 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು SB_PREMULT_ALPHA 0x00000004

#ವ್ಯಾಖ್ಯಾನಿಸು SB_GRAD_RECT 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು SB_GRAD_TRI 0x00000020

#ವ್ಯಾಖ್ಯಾನಿಸು CM_NONE 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು CM_DEVICE_ICM 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು CM_GAMMA_RAMP 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು CM_CMYK_COLOR 0x00000004

#ವ್ಯಾಖ್ಯಾನಿಸು DIB_RGB_COLORS 0
#ವ್ಯಾಖ್ಯಾನಿಸು DIB_PAL_COLORS 1

#ವ್ಯಾಖ್ಯಾನಿಸು SYSPAL_ERROR 0
#ವ್ಯಾಖ್ಯಾನಿಸು SYSPAL_STATIC 1
#ವ್ಯಾಖ್ಯಾನಿಸು SYSPAL_NOSTATIC 2
#ವ್ಯಾಖ್ಯಾನಿಸು SYSPAL_NOSTATIC256 3

#ವ್ಯಾಖ್ಯಾನಿಸು CBM_INIT 0x04L

#ವ್ಯಾಖ್ಯಾನಿಸು FLOODFILLBORDER 0
#ವ್ಯಾಖ್ಯಾನಿಸು FLOODFILLSURFACE 1

#ವ್ಯಾಖ್ಯಾನಿಸು CCHDEVICENAME 32

#ವ್ಯಾಖ್ಯಾನಿಸು CCHFORMNAME 32

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _devicemodeA {
    BYTE dmDeviceName[CCHDEVICENAME];
    ಶಬ್ದ_3 dm_Spec_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3 dm_Driver_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3 dm_ಗಾತ್ರ;
    ಶಬ್ದ_3 dmDriverExtra;
    DWORD dmFields;
    ಒಕ್ಕೂಟ {
      ರಚನೆ {
        ಗಿಡ್ಡ dmOrientation;
        ಗಿಡ್ಡ dm_Paper_ಗಾತ್ರ;
        ಗಿಡ್ಡ dm_Paper_ಉದ್ದಳತೆ;
        ಗಿಡ್ಡ dm_Paper_ಅಗಲ;
        ಗಿಡ್ಡ dmScale;
        ಗಿಡ್ಡ dmCopies;
        ಗಿಡ್ಡ dm_Default_ಮೂಲ;
        ಗಿಡ್ಡ dmPrintQuality;
      };
      ರಚನೆ {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    ಗಿಡ್ಡ dmColor;
    ಗಿಡ್ಡ dmDuplex;
    ಗಿಡ್ಡ dmYResolution;
    ಗಿಡ್ಡ dmTTOption;
    ಗಿಡ್ಡ dmCollate;
    BYTE dmFormName[CCHFORMNAME];
    ಶಬ್ದ_3 dmLogPixels;
    DWORD dm_ಬಿಟ್ಟುಗಳು_ಪ್ರತಿ_Pel;
    DWORD dm_Pels_ಅಗಲ;
    DWORD dm_Pels_ಎತ್ತರ;
    ಒಕ್ಕೂಟ {
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
    DWORD dm_Panning_ಅಗಲ;
    DWORD dm_Panning_ಎತ್ತರ;
  } DEVMODEA,*PDEVMODEA,*NPDEVMODEA,*LPDEVMODEA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _devicemodeW {
    WCHAR dmDeviceName[CCHDEVICENAME];
    ಶಬ್ದ_3 dm_Spec_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3 dm_Driver_ಆವೃತ್ತಿ;
    ಶಬ್ದ_3 dm_ಗಾತ್ರ;
    ಶಬ್ದ_3 dmDriverExtra;
    DWORD dmFields;
    ಒಕ್ಕೂಟ {
      ರಚನೆ {
        ಗಿಡ್ಡ dmOrientation;
        ಗಿಡ್ಡ dm_Paper_ಗಾತ್ರ;
        ಗಿಡ್ಡ dm_Paper_ಉದ್ದಳತೆ;
        ಗಿಡ್ಡ dm_Paper_ಅಗಲ;
        ಗಿಡ್ಡ dmScale;
        ಗಿಡ್ಡ dmCopies;
        ಗಿಡ್ಡ dm_Default_ಮೂಲ;
        ಗಿಡ್ಡ dmPrintQuality;
      };
      ರಚನೆ {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    ಗಿಡ್ಡ dmColor;
    ಗಿಡ್ಡ dmDuplex;
    ಗಿಡ್ಡ dmYResolution;
    ಗಿಡ್ಡ dmTTOption;
    ಗಿಡ್ಡ dmCollate;
    WCHAR dmFormName[CCHFORMNAME];
    ಶಬ್ದ_3 dmLogPixels;
    DWORD dm_ಬಿಟ್ಟುಗಳು_ಪ್ರತಿ_Pel;
    DWORD dm_Pels_ಅಗಲ;
    DWORD dm_Pels_ಎತ್ತರ;
    ಒಕ್ಕೂಟ {
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
    DWORD dm_Panning_ಅಗಲ;
    DWORD dm_Panning_ಎತ್ತರ;
  } DEVMODEW,*PDEVMODEW,*NPDEVMODEW,*LPDEVMODEW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DEVMODEW DEVMODE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PDEVMODEW PDEVMODE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPDEVMODEW NPDEVMODE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDEVMODEW LPDEVMODE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DEVMODEA DEVMODE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PDEVMODEA PDEVMODE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPDEVMODEA NPDEVMODE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDEVMODEA LPDEVMODE;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು DM_SPECVERSION 0x0401

#ವ್ಯಾಖ್ಯಾನಿಸು DM_ORIENTATION 0x00000001L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_PAPERSIZE 0x00000002L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_PAPERLENGTH 0x00000004L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_PAPERWIDTH 0x00000008L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_SCALE 0x00000010L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_POSITION 0x00000020L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_NUP 0x00000040L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_DISPLAYORIENTATION 0x00000080L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_COPIES 0x00000100L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_DEFAULTSOURCE 0x00000200L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_PRINTQUALITY 0x00000400L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_COLOR 0x00000800L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_DUPLEX 0x00001000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_YRESOLUTION 0x00002000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_TTOPTION 0x00004000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_COLLATE 0x00008000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_FORMNAME 0x00010000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_LOGPIXELS 0x00020000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_BITSPERPEL 0x00040000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_PELSWIDTH 0x00080000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_PELSHEIGHT 0x00100000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_DISPLAYFLAGS 0x00200000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_DISPLAYFREQUENCY 0x00400000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_ICMMETHOD 0x00800000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_ICMINTENT 0x01000000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_MEDIATYPE 0x02000000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_DITHERTYPE 0x04000000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_PANNINGWIDTH 0x08000000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_PANNINGHEIGHT 0x10000000L
#ವ್ಯಾಖ್ಯಾನಿಸು DM_DISPLAYFIXEDOUTPUT 0x20000000L

#ವ್ಯಾಖ್ಯಾನಿಸು DMORIENT_PORTRAIT 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMORIENT_LANDSCAPE 2

#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ಮೊದಲ DMPAPER_LETTER
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LETTER 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LETTERSMALL 2
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_TABLOID 3
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LEDGER 4
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LEGAL 5
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_STATEMENT 6
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_EXECUTIVE 7
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A3 8
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A4 9
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A4SMALL 10
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A5 11
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_B4 12
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_B5 13
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_FOLIO 14
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_QUARTO 15
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_10X14 16
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_11X17 17
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_NOTE 18
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_9 19
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_10 20
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_11 21
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_12 22
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_14 23
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_CSHEET 24
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_DSHEET 25
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ESHEET 26
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_DL 27
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_C5 28
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_C3 29
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_C4 30
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_C6 31
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_C65 32
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_B4 33
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_B5 34
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_B6 35
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_ITALY 36
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_MONARCH 37
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_PERSONAL 38
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_FANFOLD_US 39
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_FANFOLD_STD_GERMAN 40
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_FANFOLD_LGL_GERMAN 41
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ISO_B4 42
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JAPANESE_POSTCARD 43
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_9X11 44
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_10X11 45
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_15X11 46
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ENV_INVITE 47
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_RESERVED_48 48
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_RESERVED_49 49
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LETTER_EXTRA 50
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LEGAL_EXTRA 51
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_TABLOID_EXTRA 52
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A4_EXTRA 53
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LETTER_TRANSVERSE 54
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A4_TRANSVERSE 55
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A_PLUS 57
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_B_PLUS 58
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LETTER_PLUS 59
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A4_PLUS 60
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A5_TRANSVERSE 61
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_B5_TRANSVERSE 62
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A3_EXTRA 63
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A5_EXTRA 64
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_B5_EXTRA 65
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A2 66
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A3_TRANSVERSE 67
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A3_EXTRA_TRANSVERSE 68
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_DBL_JAPANESE_POSTCARD 69
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A6 70
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_KAKU2 71
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_KAKU3 72
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_CHOU3 73
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_CHOU4 74
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_LETTER_ROTATED 75
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A3_ROTATED 76
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A4_ROTATED 77
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A5_ROTATED 78
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_B4_JIS_ROTATED 79
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_B5_JIS_ROTATED 80
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JAPANESE_POSTCARD_ROTATED 81
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_A6_ROTATED 83
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_KAKU2_ROTATED 84
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_KAKU3_ROTATED 85
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_CHOU3_ROTATED 86
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_CHOU4_ROTATED 87
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_B6_JIS 88
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_B6_JIS_ROTATED 89
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_12X11 90
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_YOU4 91
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_JENV_YOU4_ROTATED 92
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_P16K 93
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_P32K 94
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_P32KBIG 95
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_1 96
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_2 97
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_3 98
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_4 99
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_5 100
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_6 101
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_7 102
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_8 103
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_9 104
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_10 105
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_P16K_ROTATED 106
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_P32K_ROTATED 107
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_P32KBIG_ROTATED 108
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_1_ROTATED 109
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_2_ROTATED 110
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_3_ROTATED 111
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_4_ROTATED 112
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_5_ROTATED 113
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_6_ROTATED 114
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_7_ROTATED 115
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_8_ROTATED 116
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_9_ROTATED 117
#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_PENV_10_ROTATED 118

#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_ಕೊನೆಯ DMPAPER_PENV_10_ROTATED

#ವ್ಯಾಖ್ಯಾನಿಸು DMPAPER_USER 256

#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_ಮೊದಲ DMBIN_ಊರ್ಧ್ವ
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_ಊರ್ಧ್ವ 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_ONLYONE 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_ಅಧೋ 2
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_ಮಧ್ಯ 3
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_MANUAL 4
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_ENVELOPE 5
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_ENVMANUAL 6
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_AUTO 7
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_TRACTOR 8
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_SMALLFMT 9
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_LARGEFMT 10
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_LARGECAPACITY 11
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_CASSETTE 14
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_FORMSOURCE 15
#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_ಕೊನೆಯ DMBIN_FORMSOURCE

#ವ್ಯಾಖ್ಯಾನಿಸು DMBIN_USER 256

#ವ್ಯಾಖ್ಯಾನಿಸು DMRES_DRAFT (-1)
#ವ್ಯಾಖ್ಯಾನಿಸು DMRES_ಕೆಳಗಿನ (-2)
#ವ್ಯಾಖ್ಯಾನಿಸು DMRES_MEDIUM (-3)
#ವ್ಯಾಖ್ಯಾನಿಸು DMRES_ಮೇಲಿನ (-4)

#ವ್ಯಾಖ್ಯಾನಿಸು DMCOLOR_MONOCHROME 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMCOLOR_COLOR 2

#ವ್ಯಾಖ್ಯಾನಿಸು DMDUP_SIMPLEX 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMDUP_VERTICAL 2
#ವ್ಯಾಖ್ಯಾನಿಸು DMDUP_HORIZONTAL 3

#ವ್ಯಾಖ್ಯಾನಿಸು DMTT_BITMAP 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMTT_DOWNLOAD 2
#ವ್ಯಾಖ್ಯಾನಿಸು DMTT_SUBDEV 3
#ವ್ಯಾಖ್ಯಾನಿಸು DMTT_DOWNLOAD_OUTLINE 4

#ವ್ಯಾಖ್ಯಾನಿಸು DMCOLLATE_FALSE 0
#ವ್ಯಾಖ್ಯಾನಿಸು DMCOLLATE_TRUE 1

#ವ್ಯಾಖ್ಯಾನಿಸು DMDO_DEFAULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು DMDO_90 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMDO_180 2
#ವ್ಯಾಖ್ಯಾನಿಸು DMDO_270 3

#ವ್ಯಾಖ್ಯಾನಿಸು DMDFO_DEFAULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು DMDFO_STRETCH 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMDFO_CENTER 2

#ವ್ಯಾಖ್ಯಾನಿಸು DMDISPLAYFLAGS_TEXTMODE 0x00000004

#ವ್ಯಾಖ್ಯಾನಿಸು DMNUP_SYSTEM 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMNUP_ONEUP 2

#ವ್ಯಾಖ್ಯಾನಿಸು DMICMMETHOD_NONE 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMICMMETHOD_SYSTEM 2
#ವ್ಯಾಖ್ಯಾನಿಸು DMICMMETHOD_DRIVER 3
#ವ್ಯಾಖ್ಯಾನಿಸು DMICMMETHOD_DEVICE 4

#ವ್ಯಾಖ್ಯಾನಿಸು DMICMMETHOD_USER 256

#ವ್ಯಾಖ್ಯಾನಿಸು DMICM_SATURATE 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMICM_CONTRAST 2
#ವ್ಯಾಖ್ಯಾನಿಸು DMICM_COLORIMETRIC 3
#ವ್ಯಾಖ್ಯಾನಿಸು DMICM_ABS_COLORIMETRIC 4

#ವ್ಯಾಖ್ಯಾನಿಸು DMICM_USER 256

#ವ್ಯಾಖ್ಯಾನಿಸು DMMEDIA_STANDARD 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMMEDIA_TRANSPARENCY 2
#ವ್ಯಾಖ್ಯಾನಿಸು DMMEDIA_GLOSSY 3

#ವ್ಯಾಖ್ಯಾನಿಸು DMMEDIA_USER 256

#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_NONE 1
#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_COARSE 2
#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_FINE 3
#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_LINEART 4
#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_ERRORDIFFUSION 5
#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_RESERVED6 6
#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_RESERVED7 7
#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_RESERVED8 8
#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_RESERVED9 9
#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_GRAYSCALE 10

#ವ್ಯಾಖ್ಯಾನಿಸು DMDITHER_USER 256

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _DISPLAY_DEVICEA {
    DWORD cb;
    CHAR DeviceName[32];
    CHAR DeviceString[128];
    DWORD StateFlags;
    CHAR DeviceID[128];
    CHAR Device_ಕೀಲಿ[128];
  } DISPLAY_DEVICEA,*PDISPLAY_DEVICEA,*LPDISPLAY_DEVICEA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _DISPLAY_DEVICEW {
    DWORD cb;
    WCHAR DeviceName[32];
    WCHAR DeviceString[128];
    DWORD StateFlags;
    WCHAR DeviceID[128];
    WCHAR Device_ಕೀಲಿ[128];
  } DISPLAY_DEVICEW,*PDISPLAY_DEVICEW,*LPDISPLAY_DEVICEW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DISPLAY_DEVICEW DISPLAY_DEVICE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PDISPLAY_DEVICEW PDISPLAY_DEVICE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDISPLAY_DEVICEW LPDISPLAY_DEVICE;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DISPLAY_DEVICEA DISPLAY_DEVICE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PDISPLAY_DEVICEA PDISPLAY_DEVICE;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_ATTACHED_ಗಮ್ಯ_DESKTOP 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_MULTI_DRIVER 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_PRIMARY_DEVICE 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_MIRRORING_DRIVER 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_VGA_COMPATIBLE 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_REMOVABLE 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_MODESPRUNED 0x08000000
#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_REMOTE 0x04000000
#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_DISCONNECT 0x02000000

#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_ಸಕ್ರಿಯ 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು DISPLAY_DEVICE_ATTACHED 0x00000002

#ವ್ಯಾಖ್ಯಾನಿಸು RDH_RECTANGLES 1

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RGNDATAHEADER {
    DWORD dw_ಗಾತ್ರ;
    DWORD iType;
    DWORD n_ಎಣಿಕೆ;
    DWORD n_Rgn_ಗಾತ್ರ;
    RECT rcBound;
  } RGNDATAHEADER,*PRGNDATAHEADER;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _RGNDATA {
    RGNDATAHEADER rdh;
    ಅಕ್ಷರ ಬಫರ್_3[1];
  } RGNDATA,*PRGNDATA,*NPRGNDATA,*LPRGNDATA;

#ವ್ಯಾಖ್ಯಾನಿಸು SYSRGN 4

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ABC {
    ಪೂರ್ಣಾಂಕ abcA;
    UINT abcB;
    ಪೂರ್ಣಾಂಕ abcC;
  } ABC,*PABC,*NPABC,*LPABC;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _ABCFLOAT {
    FLOAT abcfA;
    FLOAT abcfB;
    FLOAT abcfC;
  } ABCFLOAT,*PABCFLOAT,*NPABCFLOAT,*LPABCFLOAT;

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOTEXTMETRIC

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OUTLINETEXTMETRICA {
    UINT otm_ಗಾತ್ರ;
    TEXTMETRICA otm_ಪಠ್ಯ_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_ಸಂಖ್ಯೆ;
    UINT otmfsSelection;
    UINT otmfsType;
    ಪೂರ್ಣಾಂಕ otms_Char_ಇಳಿಜಾರು_Rise;
    ಪೂರ್ಣಾಂಕ otms_Char_ಇಳಿಜಾರು_ಸತತ;
    ಪೂರ್ಣಾಂಕ otmItalicAngle;
    UINT otmEMSquare;
    ಪೂರ್ಣಾಂಕ otmAscent;
    ಪೂರ್ಣಾಂಕ otmDescent;
    UINT otm_ಸಾಲು_Gap;
    UINT otms_Cap_Em_ಎತ್ತರ;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    ಪೂರ್ಣಾಂಕ otmMacAscent;
    ಪೂರ್ಣಾಂಕ otmMacDescent;
    UINT otm_Mac_ಸಾಲು_Gap;
    UINT otmusMinimumPPEM;
    ಬಿಂದು_3 otmpt_Subscript_ಗಾತ್ರ;
    ಬಿಂದು_3 otmpt_Subscript_ಸ್ಥಾನಾಂತರ;
    ಬಿಂದು_3 otmpt_Superscript_ಗಾತ್ರ;
    ಬಿಂದು_3 otmpt_Superscript_ಸ್ಥಾನಾಂತರ;
    UINT otms_Strikeout_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ otmsStrikeoutPosition;
    ಪೂರ್ಣಾಂಕ otms_Underscore_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_ತುಂಬಿದ_Name;
  } OUTLINETEXTMETRICA,*POUTLINETEXTMETRICA,*NPOUTLINETEXTMETRICA,*LPOUTLINETEXTMETRICA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _OUTLINETEXTMETRICW {
    UINT otm_ಗಾತ್ರ;
    TEXTMETRICW otm_ಪಠ್ಯ_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_ಸಂಖ್ಯೆ;
    UINT otmfsSelection;
    UINT otmfsType;
    ಪೂರ್ಣಾಂಕ otms_Char_ಇಳಿಜಾರು_Rise;
    ಪೂರ್ಣಾಂಕ otms_Char_ಇಳಿಜಾರು_ಸತತ;
    ಪೂರ್ಣಾಂಕ otmItalicAngle;
    UINT otmEMSquare;
    ಪೂರ್ಣಾಂಕ otmAscent;
    ಪೂರ್ಣಾಂಕ otmDescent;
    UINT otm_ಸಾಲು_Gap;
    UINT otms_Cap_Em_ಎತ್ತರ;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    ಪೂರ್ಣಾಂಕ otmMacAscent;
    ಪೂರ್ಣಾಂಕ otmMacDescent;
    UINT otm_Mac_ಸಾಲು_Gap;
    UINT otmusMinimumPPEM;
    ಬಿಂದು_3 otmpt_Subscript_ಗಾತ್ರ;
    ಬಿಂದು_3 otmpt_Subscript_ಸ್ಥಾನಾಂತರ;
    ಬಿಂದು_3 otmpt_Superscript_ಗಾತ್ರ;
    ಬಿಂದು_3 otmpt_Superscript_ಸ್ಥಾನಾಂತರ;
    UINT otms_Strikeout_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ otmsStrikeoutPosition;
    ಪೂರ್ಣಾಂಕ otms_Underscore_ಗಾತ್ರ;
    ಪೂರ್ಣಾಂಕ otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_ತುಂಬಿದ_Name;
  } OUTLINETEXTMETRICW,*POUTLINETEXTMETRICW,*NPOUTLINETEXTMETRICW,*LPOUTLINETEXTMETRICW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ OUTLINETEXTMETRICW OUTLINETEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ POUTLINETEXTMETRICW POUTLINETEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPOUTLINETEXTMETRICW NPOUTLINETEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPOUTLINETEXTMETRICW LPOUTLINETEXTMETRIC;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_POLYTEXTA {
    ಪೂರ್ಣಾಂಕ x;
    ಪೂರ್ಣಾಂಕ y;
    UINT n;
    LPCSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    ಪೂರ್ಣಾಂಕ *pdx;
  } POLYTEXTA,*PPOLYTEXTA,*NPPOLYTEXTA,*LPPOLYTEXTA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_POLYTEXTW {
    ಪೂರ್ಣಾಂಕ x;
    ಪೂರ್ಣಾಂಕ y;
    UINT n;
    LPCWSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    ಪೂರ್ಣಾಂಕ *pdx;
  } POLYTEXTW,*PPOLYTEXTW,*NPPOLYTEXTW,*LPPOLYTEXTW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ POLYTEXTW POLYTEXT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PPOLYTEXTW PPOLYTEXT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPPOLYTEXTW NPPOLYTEXT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPPOLYTEXTW LPPOLYTEXT;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ POLYTEXTA POLYTEXT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PPOLYTEXTA PPOLYTEXT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ NPPOLYTEXTA NPPOLYTEXT;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPPOLYTEXTA LPPOLYTEXT;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _FIXED {
    ಶಬ್ದ_3 fract;
    ಗಿಡ್ಡ ಮೌಲ್ಯ;
  } FIXED;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _MAT2 {
    FIXED eM11;
    FIXED eM12;
    FIXED eM21;
    FIXED eM22;
  } MAT2,*LPMAT2;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _GLYPHMETRICS {
    UINT gmBlackBoxX;
    UINT gmBlackBoxY;
    ಬಿಂದು_3 gmptGlyphOrigin;
    ಗಿಡ್ಡ gmCellIncX;
    ಗಿಡ್ಡ gmCellIncY;
  } GLYPHMETRICS,*LPGLYPHMETRICS;

#ವ್ಯಾಖ್ಯಾನಿಸು GGO_METRICS 0
#ವ್ಯಾಖ್ಯಾನಿಸು GGO_BITMAP 1
#ವ್ಯಾಖ್ಯಾನಿಸು GGO_NATIVE 2
#ವ್ಯಾಖ್ಯಾನಿಸು GGO_BEZIER 3

#ವ್ಯಾಖ್ಯಾನಿಸು GGO_GRAY2_BITMAP 4
#ವ್ಯಾಖ್ಯಾನಿಸು GGO_GRAY4_BITMAP 5
#ವ್ಯಾಖ್ಯಾನಿಸು GGO_GRAY8_BITMAP 6
#ವ್ಯಾಖ್ಯಾನಿಸು GGO_GLYPH_ಸೂಚ್ಯಂಕ 0x0080
#ವ್ಯಾಖ್ಯಾನಿಸು GGO_UNHINTED 0x0100

#ವ್ಯಾಖ್ಯಾನಿಸು TT_POLYGON_TYPE 24

#ವ್ಯಾಖ್ಯಾನಿಸು TT_PRIM_ಸಾಲು 1
#ವ್ಯಾಖ್ಯಾನಿಸು TT_PRIM_QSPLINE 2
#ವ್ಯಾಖ್ಯಾನಿಸು TT_PRIM_CSPLINE 3

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_POINTFX {
    FIXED x;
    FIXED y;
  } POINTFX,*LPPOINTFX;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_TTPOLYCURVE {
    ಶಬ್ದ_3 wType;
    ಶಬ್ದ_3 cpfx;
    POINTFX apfx[1];
  } TTPOLYCURVE,*LPTTPOLYCURVE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_TTPOLYGONHEADER {
    DWORD cb;
    DWORD dwType;
    POINTFX pfx_ಆರಂಭ;
  } TTPOLYGONHEADER,*LPTTPOLYGONHEADER;

#ವ್ಯಾಖ್ಯಾನಿಸು GCP_DBCS 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_REORDER 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_USEKERNING 0x0008
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_GLYPHSHAPE 0x0010
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_LIGATE 0x0020

#ವ್ಯಾಖ್ಯಾನಿಸು GCP_DIACRITIC 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_KASHIDA 0x0400
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_ERROR 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು FLI_ಮುಖವಾಡ 0x103B

#ವ್ಯಾಖ್ಯಾನಿಸು GCP_JUSTIFY 0x00010000L

#ವ್ಯಾಖ್ಯಾನಿಸು FLI_GLYPHS 0x00040000L
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_CLASSIN 0x00080000L
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_MAXEXTENT 0x00100000L
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_JUSTIFYIN 0x00200000L
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_DISPLAYZWG 0x00400000L
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_SYMSWAPOFF 0x00800000L
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_NUMERICOVERRIDE 0x01000000L
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_NEUTRALOVERRIDE 0x02000000L
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_NUMERICSLATIN 0x04000000L
#ವ್ಯಾಖ್ಯಾನಿಸು GCP_NUMERICSLOCAL 0x08000000L

#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_LATIN 1
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_HEBREW 2
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_ARABIC 2
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_NEUTRAL 3
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_LOCALNUMBER 4
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_LATINNUMBER 5
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_LATINNUMERICTERMINATOR 6
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_LATINNUMERICSEPARATOR 7
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_NUMERICSEPARATOR 8
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_PREBOUNDLTR 0x80
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_PREBOUNDRTL 0x40
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_POSTBOUNDLTR 0x20
#ವ್ಯಾಖ್ಯಾನಿಸು GCPCLASS_POSTBOUNDRTL 0x10

#ವ್ಯಾಖ್ಯಾನಿಸು GCPGLYPH_LINKBEFORE 0x8000
#ವ್ಯಾಖ್ಯಾನಿಸು GCPGLYPH_LINKAFTER 0x4000

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_GCP_RESULTSA {
    DWORD l_Struct_ಗಾತ್ರ;
    LPSTR lp_ಹೊರಹೋಗು_String;
    UINT *lp_ಕ್ರಮ;
    ಪೂರ್ಣಾಂಕ *lpDx;
    ಪೂರ್ಣಾಂಕ *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    ಪೂರ್ಣಾಂಕ nMaxFit;
  } GCP_RESULTSA,*LPGCP_RESULTSA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_GCP_RESULTSW {
    DWORD l_Struct_ಗಾತ್ರ;
    LPWSTR lp_ಹೊರಹೋಗು_String;
    UINT *lp_ಕ್ರಮ;
    ಪೂರ್ಣಾಂಕ *lpDx;
    ಪೂರ್ಣಾಂಕ *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    ಪೂರ್ಣಾಂಕ nMaxFit;
  } GCP_RESULTSW,*LPGCP_RESULTSW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ GCP_RESULTSW GCP_RESULTS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPGCP_RESULTSW LPGCP_RESULTS;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ GCP_RESULTSA GCP_RESULTS;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPGCP_RESULTSA LPGCP_RESULTS;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ RASTERIZER_ಸ್ಥಿತಿ {
    ಗಿಡ್ಡ n_ಗಾತ್ರ;
    ಗಿಡ್ಡ wFlags;
    ಗಿಡ್ಡ nLanguageID;
  } RASTERIZER_ಸ್ಥಿತಿ_2,*LPRASTERIZER_ಸ್ಥಿತಿ;

#ವ್ಯಾಖ್ಯಾನಿಸು TT_ಲಭ್ಯ 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು TT_ENABLED 0x0002

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_PIXELFORMATDESCRIPTOR {
    ಶಬ್ದ_3 n_ಗಾತ್ರ;
    ಶಬ್ದ_3 n_ಆವೃತ್ತಿ;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_ಬಿಟ್ಟುಗಳು;
    BYTE c_Red_ಬಿಟ್ಟುಗಳು;
    BYTE c_Red_ಸರಿಸು;
    BYTE c_Green_ಬಿಟ್ಟುಗಳು;
    BYTE c_Green_ಸರಿಸು;
    BYTE c_Blue_ಬಿಟ್ಟುಗಳು;
    BYTE c_Blue_ಸರಿಸು;
    BYTE c_Alpha_ಬಿಟ್ಟುಗಳು;
    BYTE c_Alpha_ಸರಿಸು;
    BYTE c_Accum_ಬಿಟ್ಟುಗಳು;
    BYTE c_Accum_Red_ಬಿಟ್ಟುಗಳು;
    BYTE c_Accum_Green_ಬಿಟ್ಟುಗಳು;
    BYTE c_Accum_Blue_ಬಿಟ್ಟುಗಳು;
    BYTE c_Accum_Alpha_ಬಿಟ್ಟುಗಳು;
    BYTE c_ಆಳ_ಬಿಟ್ಟುಗಳು;
    BYTE c_Stencil_ಬಿಟ್ಟುಗಳು;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dw_Layer_ಮುಖವಾಡ;
    DWORD dw_Visible_ಮುಖವಾಡ;
    DWORD dw_Damage_ಮುಖವಾಡ;
  } PIXELFORMATDESCRIPTOR,*PPIXELFORMATDESCRIPTOR,*LPPIXELFORMATDESCRIPTOR;

#ವ್ಯಾಖ್ಯಾನಿಸು PFD_TYPE_RGBA 0
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_TYPE_COLORINDEX 1

#ವ್ಯಾಖ್ಯಾನಿಸು PFD_MAIN_PLANE 0
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_OVERLAY_PLANE 1
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_UNDERLAY_PLANE (-1)

#ವ್ಯಾಖ್ಯಾನಿಸು PFD_DOUBLEBUFFER 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_STEREO 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_DRAW_ಗಮ್ಯ_ಕಿಟಕಿ 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_DRAW_ಗಮ್ಯ_BITMAP 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_SUPPORT_GDI 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_SUPPORT_OPENGL 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_GENERIC_FORMAT 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_NEED_PALETTE 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_NEED_SYSTEM_PALETTE 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_ಅದಲುಬದಲು_EXCHANGE 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_ಅದಲುಬದಲು_COPY 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_ಅದಲುಬದಲು_LAYER_BUFFERS 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_GENERIC_ACCELERATED 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_SUPPORT_DIRECTDRAW 0x00002000

#ವ್ಯಾಖ್ಯಾನಿಸು PFD_ಆಳ_DONTCARE 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#ವ್ಯಾಖ್ಯಾನಿಸು PFD_STEREO_DONTCARE 0x80000000

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOTEXTMETRIC
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST TEXTMETRICA *,DWORD,LPARAM);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST TEXTMETRICW *,DWORD,LPARAM);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು OLDFONTENUMPROC OLDFONTENUMPROCW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು OLDFONTENUMPROC OLDFONTENUMPROCA
#ಆದರೆ_ಅಂತ್ಯ
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST VOID *,DWORD,LPARAM);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST VOID *,DWORD,LPARAM);
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು OLDFONTENUMPROC OLDFONTENUMPROCW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು OLDFONTENUMPROC OLDFONTENUMPROCA
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ OLDFONTENUMPROCA FONTENUMPROCA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ OLDFONTENUMPROCW FONTENUMPROCW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ FONTENUMPROCW FONTENUMPROC;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ FONTENUMPROCA FONTENUMPROC;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *GOBJENUMPROC)(LPVOID,LPARAM);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ VOID (CALLBACK *LINEDDAPROC)(ಪೂರ್ಣಾಂಕ,ಪೂರ್ಣಾಂಕ,LPARAM);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Font_Resource ಕೂಡಿಸು_Font_Resource_W
#ವ್ಯಾಖ್ಯಾನಿಸು CopyMetaFile CopyMetaFileW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDC CreateDCW
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Font_ಪರೋಕ್ಷ Create_Font_ಪರೋಕ್ಷ_W
#ವ್ಯಾಖ್ಯಾನಿಸು CreateFont CreateFontW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateIC CreateICW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateMetaFile CreateMetaFileW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateScalableFontResource CreateScalableFontResourceW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Font_Resource ಕೂಡಿಸು_Font_Resource_A
#ವ್ಯಾಖ್ಯಾನಿಸು CopyMetaFile CopyMetaFileA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateDC CreateDCA
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Font_ಪರೋಕ್ಷ Create_Font_ಪರೋಕ್ಷ_A
#ವ್ಯಾಖ್ಯಾನಿಸು CreateFont CreateFontA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateIC CreateICA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateMetaFile CreateMetaFileA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateScalableFontResource CreateScalableFontResourceA
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಕೂಡಿಸು_Font_Resource_A(LPCSTR);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಕೂಡಿಸು_Font_Resource_W(LPCWSTR);
  WINGDIAPI WINBOOL WINAPI AnimatePalette(HPALETTE hPal,UINT i_ಆರಂಭ_ಸೂಚ್ಯಂಕ,UINT cEntries,CONST PALETTEENTRY *ppe);
  WINGDIAPI WINBOOL WINAPI Arc(HDC hdc,ಪೂರ್ಣಾಂಕ x1,ಪೂರ್ಣಾಂಕ y1,ಪೂರ್ಣಾಂಕ x2,ಪೂರ್ಣಾಂಕ y2,ಪೂರ್ಣಾಂಕ x3,ಪೂರ್ಣಾಂಕ y3,ಪೂರ್ಣಾಂಕ x4,ಪೂರ್ಣಾಂಕ y4);
  WINGDIAPI WINBOOL WINAPI ಬಿಟ್_Blt(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy,HDC hdcSrc,ಪೂರ್ಣಾಂಕ x1,ಪೂರ್ಣಾಂಕ y1,DWORD rop);
  WINGDIAPI WINBOOL WINAPI CancelDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Chord(HDC hdc,ಪೂರ್ಣಾಂಕ x1,ಪೂರ್ಣಾಂಕ y1,ಪೂರ್ಣಾಂಕ x2,ಪೂರ್ಣಾಂಕ y2,ಪೂರ್ಣಾಂಕ x3,ಪೂರ್ಣಾಂಕ y3,ಪೂರ್ಣಾಂಕ x4,ಪೂರ್ಣಾಂಕ y4);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಆರಿಸು_Pixel_Format(HDC hdc,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI HMETAFILE WINAPI CloseMetaFile(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,ಪೂರ್ಣಾಂಕ i_ಬಹುಲಕ);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
  WINGDIAPI HBITMAP WINAPI CreateBitmap(ಪೂರ್ಣಾಂಕ n_ಅಗಲ,ಪೂರ್ಣಾಂಕ n_ಎತ್ತರ,UINT nPlanes,UINT n_ಬಿಟ್_ಎಣಿಕೆ,CONST VOID *lp_ಬಿಟ್ಟುಗಳು);
  WINGDIAPI HBITMAP WINAPI Create_Bitmap_ಪರೋಕ್ಷ(CONST BITMAP *pbm);
  WINGDIAPI HBRUSH WINAPI Create_Brush_ಪರೋಕ್ಷ(CONST LOGBRUSH *plbrush);
  WINGDIAPI HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy);
  WINGDIAPI HBITMAP WINAPI CreateDiscardableBitmap(HDC hdc,ಪೂರ್ಣಾಂಕ cx,ಪೂರ್ಣಾಂಕ cy);
  WINGDIAPI HDC WINAPI CreateCompatibleDC(HDC hdc);
  WINGDIAPI HDC WINAPI CreateDCA(LPCSTR pwszDriver,LPCSTR pwszDevice,LPCSTR psz_ಪೋರ್ಟ್,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateDCW(LPCWSTR pwszDriver,LPCWSTR pwszDevice,LPCWSTR psz_ಪೋರ್ಟ್,CONST DEVMODEW *pdm);
  WINGDIAPI HBITMAP WINAPI CreateDIBitmap(HDC hdc,CONST BITMAPINFOHEADER *pbmih,DWORD flInit,CONST VOID *pj_ಬಿಟ್ಟುಗಳು,CONST BITMAPINFO *pbmi,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL h,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB,UINT iUsage);
  WINGDIAPI HRGN WINAPI CreateEllipticRgn(ಪೂರ್ಣಾಂಕ x1,ಪೂರ್ಣಾಂಕ y1,ಪೂರ್ಣಾಂಕ x2,ಪೂರ್ಣಾಂಕ y2);
  WINGDIAPI HRGN WINAPI Create_Elliptic_Rgn_ಪರೋಕ್ಷ(CONST RECT *lprect);
  WINGDIAPI HFONT WINAPI Create_Font_ಪರೋಕ್ಷ_A(CONST LOGFONTA *lplf);
  WINGDIAPI HFONT WINAPI Create_Font_ಪರೋಕ್ಷ_W(CONST LOGFONTW *lplf);
  WINGDIAPI HFONT WINAPI CreateFontA(ಪೂರ್ಣಾಂಕ c_ಎತ್ತರ,ಪೂರ್ಣಾಂಕ c_ಅಗಲ,ಪೂರ್ಣಾಂಕ cEscapement,ಪೂರ್ಣಾಂಕ cOrientation,ಪೂರ್ಣಾಂಕ c_ತೂಕ,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_ಹೊರಹೋಗು,DWORD i_Char_ಗಣ,DWORD i_ಹೊರಹೋಗು_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCSTR pszFaceName);
  WINGDIAPI HFONT WINAPI CreateFontW(ಪೂರ್ಣಾಂಕ c_ಎತ್ತರ,ಪೂರ್ಣಾಂಕ c_ಅಗಲ,ಪೂರ್ಣಾಂಕ cEscapement,ಪೂರ್ಣಾಂಕ cOrientation,ಪೂರ್ಣಾಂಕ c_ತೂಕ,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_ಹೊರಹೋಗು,DWORD i_Char_ಗಣ,DWORD i_ಹೊರಹೋಗು_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCWSTR pszFaceName);
  WINGDIAPI HBRUSH WINAPI CreateHatchBrush(ಪೂರ್ಣಾಂಕ iHatch,COLORREF color);
  WINGDIAPI HDC WINAPI CreateICA(LPCSTR pszDriver,LPCSTR pszDevice,LPCSTR psz_ಪೋರ್ಟ್,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateICW(LPCWSTR pszDriver,LPCWSTR pszDevice,LPCWSTR psz_ಪೋರ್ಟ್,CONST DEVMODEW *pdm);
  WINGDIAPI HDC WINAPI CreateMetaFileA(LPCSTR pszFile);
  WINGDIAPI HDC WINAPI CreateMetaFileW(LPCWSTR pszFile);
  WINGDIAPI HPALETTE WINAPI CreatePalette(CONST LOGPALETTE *plpal);
  WINGDIAPI HPEN WINAPI CreatePen(ಪೂರ್ಣಾಂಕ iStyle,ಪೂರ್ಣಾಂಕ c_ಅಗಲ,COLORREF color);
  WINGDIAPI HPEN WINAPI Create_Pen_ಪರೋಕ್ಷ(CONST LOGPEN *plpen);
  WINGDIAPI HRGN WINAPI CreatePolyPolygonRgn(CONST ಬಿಂದು_3 *pptl,CONST INT *pc,ಪೂರ್ಣಾಂಕ cPoly,ಪೂರ್ಣಾಂಕ i_ಬಹುಲಕ);
  WINGDIAPI HBRUSH WINAPI Create_ನಮೂನೆ_Brush(HBITMAP hbm);
  WINGDIAPI HRGN WINAPI CreateRectRgn(ಪೂರ್ಣಾಂಕ x1,ಪೂರ್ಣಾಂಕ y1,ಪೂರ್ಣಾಂಕ x2,ಪೂರ್ಣಾಂಕ y2);
  WINGDIAPI HRGN WINAPI Create_Rect_Rgn_ಪರೋಕ್ಷ(CONST RECT *lprect);
  WINGDIAPI HRGN WINAPI Create_ಸುತ್ತು_Rect_Rgn(ಪೂರ್ಣಾಂಕ x1,ಪೂರ್ಣಾಂಕ y1,ಪೂರ್ಣಾಂಕ x2,ಪೂರ್ಣಾಂಕ y2,ಪೂರ್ಣಾಂಕ w,ಪೂರ್ಣಾಂಕ h);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceA(DWORD fdwHidden,LPCSTR lpszFont,LPCSTR lpszFile,LPCSTR lpsz_ಮಾರ್ಗ);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceW(DWORD fdwHidden,LPCWSTR lpszFont,LPCWSTR lpszFile,LPCWSTR lpsz_ಮಾರ್ಗ);
  WINGDIAPI HBRUSH WINAPI CreateSolidBrush(COLORREF color);
  WINGDIAPI WINBOOL WINAPI DeleteDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI DeleteMetaFile(HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI DeleteObject(HGDIOBJ ho);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI DescribePixelFormat(HDC hdc,ಪೂರ್ಣಾಂಕ iPixelFormat,UINT n_ಬೈಟುಗಳು,LPPIXELFORMATDESCRIPTOR ppfd);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ UINT (CALLBACK *LPFNDEVMODE)(HWND,HMODULE,LPDEVMODE,LPSTR,LPSTR,LPDEVMODE,LPSTR,UINT);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DWORD (CALLBACK *LPFNDEVCAPS)(LPSTR,LPSTR,UINT,LPSTR,LPDEVMODE);

#ವ್ಯಾಖ್ಯಾನಿಸು DM_UPDATE 1
#ವ್ಯಾಖ್ಯಾನಿಸು DM_COPY 2
#ವ್ಯಾಖ್ಯಾನಿಸು DM_PROMPT 4
#ವ್ಯಾಖ್ಯಾನಿಸು DM_MODIFY 8

#ವ್ಯಾಖ್ಯಾನಿಸು DM_ಒಳ_ಬಫರ್ DM_MODIFY
#ವ್ಯಾಖ್ಯಾನಿಸು DM_ಒಳ_PROMPT DM_PROMPT
#ವ್ಯಾಖ್ಯಾನಿಸು DM_ಹೊರಹೋಗು_ಬಫರ್ DM_COPY
#ವ್ಯಾಖ್ಯಾನಿಸು DM_ಹೊರಹೋಗು_DEFAULT DM_UPDATE

#ವ್ಯಾಖ್ಯಾನಿಸು DC_FIELDS 1
#ವ್ಯಾಖ್ಯಾನಿಸು DC_PAPERS 2
#ವ್ಯಾಖ್ಯಾನಿಸು DC_PAPERSIZE 3
#ವ್ಯಾಖ್ಯಾನಿಸು DC_MINEXTENT 4
#ವ್ಯಾಖ್ಯಾನಿಸು DC_MAXEXTENT 5
#ವ್ಯಾಖ್ಯಾನಿಸು DC_BINS 6
#ವ್ಯಾಖ್ಯಾನಿಸು DC_DUPLEX 7
#ವ್ಯಾಖ್ಯಾನಿಸು DC_ಗಾತ್ರ 8
#ವ್ಯಾಖ್ಯಾನಿಸು DC_EXTRA 9
#ವ್ಯಾಖ್ಯಾನಿಸು DC_ಆವೃತ್ತಿ 10
#ವ್ಯಾಖ್ಯಾನಿಸು DC_DRIVER 11
#ವ್ಯಾಖ್ಯಾನಿಸು DC_BINNAMES 12
#ವ್ಯಾಖ್ಯಾನಿಸು DC_ENUMRESOLUTIONS 13
#ವ್ಯಾಖ್ಯಾನಿಸು DC_FILEDEPENDENCIES 14
#ವ್ಯಾಖ್ಯಾನಿಸು DC_TRUETYPE 15
#ವ್ಯಾಖ್ಯಾನಿಸು DC_PAPERNAMES 16
#ವ್ಯಾಖ್ಯಾನಿಸು DC_ORIENTATION 17
#ವ್ಯಾಖ್ಯಾನಿಸು DC_COPIES 18
#ವ್ಯಾಖ್ಯಾನಿಸು DC_BINADJUST 19
#ವ್ಯಾಖ್ಯಾನಿಸು DC_EMF_COMPLIANT 20
#ವ್ಯಾಖ್ಯಾನಿಸು DC_DATATYPE_PRODUCED 21
#ವ್ಯಾಖ್ಯಾನಿಸು DC_COLLATE 22
#ವ್ಯಾಖ್ಯಾನಿಸು DC_MANUFACTURER 23
#ವ್ಯಾಖ್ಯಾನಿಸು DC_MODEL 24
#ವ್ಯಾಖ್ಯಾನಿಸು DC_PERSONALITY 25
#ವ್ಯಾಖ್ಯಾನಿಸು DC_PRINTRATE 26
#ವ್ಯಾಖ್ಯಾನಿಸು DC_PRINTRATEUNIT 27
#ವ್ಯಾಖ್ಯಾನಿಸು PRINTRATEUNIT_PPM 1
#ವ್ಯಾಖ್ಯಾನಿಸು PRINTRATEUNIT_CPS 2
#ವ್ಯಾಖ್ಯಾನಿಸು PRINTRATEUNIT_LPM 3
#ವ್ಯಾಖ್ಯಾನಿಸು PRINTRATEUNIT_IPM 4
#ವ್ಯಾಖ್ಯಾನಿಸು DC_PRINTERMEM 28
#ವ್ಯಾಖ್ಯಾನಿಸು DC_MEDIAREADY 29
#ವ್ಯಾಖ್ಯಾನಿಸು DC_STAPLE 30
#ವ್ಯಾಖ್ಯಾನಿಸು DC_PRINTRATEPPM 31
#ವ್ಯಾಖ್ಯಾನಿಸು DC_COLORDEVICE 32
#ವ್ಯಾಖ್ಯಾನಿಸು DC_NUP 33
#ವ್ಯಾಖ್ಯಾನಿಸು DC_MEDIATYPENAMES 34
#ವ್ಯಾಖ್ಯಾನಿಸು DC_MEDIATYPES 35

#ವ್ಯಾಖ್ಯಾನಿಸು DCTT_BITMAP 0x0000001L
#ವ್ಯಾಖ್ಯಾನಿಸು DCTT_DOWNLOAD 0x0000002L
#ವ್ಯಾಖ್ಯಾನಿಸು DCTT_SUBDEV 0x0000004L
#ವ್ಯಾಖ್ಯಾನಿಸು DCTT_DOWNLOAD_OUTLINE 0x0000008L

#ವ್ಯಾಖ್ಯಾನಿಸು DCBA_FACEUPNONE 0x0000
#ವ್ಯಾಖ್ಯಾನಿಸು DCBA_FACEUPCENTER 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು DCBA_FACEUPLEFT 0x0002
#ವ್ಯಾಖ್ಯಾನಿಸು DCBA_FACEUPRIGHT 0x0003
#ವ್ಯಾಖ್ಯಾನಿಸು DCBA_FACEDOWNNONE 0x0100
#ವ್ಯಾಖ್ಯಾನಿಸು DCBA_FACEDOWNCENTER 0x0101
#ವ್ಯಾಖ್ಯಾನಿಸು DCBA_FACEDOWNLEFT 0x0102
#ವ್ಯಾಖ್ಯಾನಿಸು DCBA_FACEDOWNRIGHT 0x0103

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು DeviceCapabilities DeviceCapabilitiesW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumFontFamiliesEx EnumFontFamiliesExW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumFontFamilies EnumFontFamiliesW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumFonts EnumFontsW
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Char_ಅಗಲ Get_Char_ಅಗಲ_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetCharWidth32 GetCharWidth32W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Char_ಅಗಲ_Float Get_Char_ಅಗಲ_Float_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetCharABCWidths GetCharABCWidthsW
#ವ್ಯಾಖ್ಯಾನಿಸು GetCharABCWidthsFloat GetCharABCWidthsFloatW
#ವ್ಯಾಖ್ಯಾನಿಸು GetGlyphOutline GetGlyphOutlineW
#ವ್ಯಾಖ್ಯಾನಿಸು GetMetaFile GetMetaFileW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು DeviceCapabilities DeviceCapabilitiesA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumFontFamiliesEx EnumFontFamiliesExA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumFontFamilies EnumFontFamiliesA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumFonts EnumFontsA
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Char_ಅಗಲ Get_Char_ಅಗಲ_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetCharWidth32 GetCharWidth32A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Char_ಅಗಲ_Float Get_Char_ಅಗಲ_Float_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetCharABCWidths GetCharABCWidthsA
#ವ್ಯಾಖ್ಯಾನಿಸು GetCharABCWidthsFloat GetCharABCWidthsFloatA
#ವ್ಯಾಖ್ಯಾನಿಸು GetGlyphOutline GetGlyphOutlineA
#ವ್ಯಾಖ್ಯಾನಿಸು GetMetaFile GetMetaFileA
#ಆದರೆ_ಅಂತ್ಯ

  WINSPOOLAPI ಪೂರ್ಣಾಂಕ WINAPI DeviceCapabilitiesA(LPCSTR pDevice,LPCSTR p_ಪೋರ್ಟ್,ಶಬ್ದ_3 fwCapability,LPSTR pOutput,CONST DEVMODEA *p_Dev_ಬಹುಲಕ);
  WINSPOOLAPI ಪೂರ್ಣಾಂಕ WINAPI DeviceCapabilitiesW(LPCWSTR pDevice,LPCWSTR p_ಪೋರ್ಟ್,ಶಬ್ದ_3 fwCapability,LPWSTR pOutput,CONST DEVMODEW *p_Dev_ಬಹುಲಕ);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI DrawEscape(HDC hdc,ಪೂರ್ಣಾಂಕ iEscape,ಪೂರ್ಣಾಂಕ cj_ಒಳ,LPCSTR lp_ಒಳ);
  WINGDIAPI WINBOOL WINAPI Ellipse(HDC hdc,ಪೂರ್ಣಾಂಕ ಎಡ,ಪೂರ್ಣಾಂಕ ತುದಿ,ಪೂರ್ಣಾಂಕ ಬಲ,ಪೂರ್ಣಾಂಕ bottom);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI EnumFontFamiliesExA(HDC hdc,LPLOGFONTA lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI EnumFontFamiliesExW(HDC hdc,LPLOGFONTW lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI EnumFontFamiliesA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI EnumFontFamiliesW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI EnumFontsA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI EnumFontsW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI EnumObjects(HDC hdc,ಪೂರ್ಣಾಂಕ nType,GOBJENUMPROC lpFunc,LPARAM lParam);
  WINGDIAPI WINBOOL WINAPI EqualRgn(HRGN hrgn1,HRGN hrgn2);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Escape(HDC hdc,ಪೂರ್ಣಾಂಕ iEscape,ಪೂರ್ಣಾಂಕ cj_ಒಳ,LPCSTR pv_ಒಳ,LPVOID pv_ಹೊರಹೋಗು);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ExtEscape(HDC hdc,ಪೂರ್ಣಾಂಕ iEscape,ಪೂರ್ಣಾಂಕ cj_ಒಳಹರಿವು,LPCSTR lp_ಒಳ_ದತ್ತಾಂಶ,ಪೂರ್ಣಾಂಕ cjOutput,LPSTR lp_ಹೊರಹೋಗು_ದತ್ತಾಂಶ);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ExcludeClipRect(HDC hdc,ಪೂರ್ಣಾಂಕ ಎಡ,ಪೂರ್ಣಾಂಕ ತುದಿ,ಪೂರ್ಣಾಂಕ ಬಲ,ಪೂರ್ಣಾಂಕ bottom);
  WINGDIAPI HRGN WINAPI ExtCreateRegion(CONST XFORM *lpx,DWORD n_ಎಣಿಕೆ,CONST RGNDATA *lp_ದತ್ತಾಂಶ);
  WINGDIAPI WINBOOL WINAPI ExtFloodFill(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,COLORREF color,UINT type);
  WINGDIAPI WINBOOL WINAPI FillRgn(HDC hdc,HRGN hrgn,HBRUSH hbr);
  WINGDIAPI WINBOOL WINAPI FloodFill(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI ಚೌಕಟ್ಟು_Rgn(HDC hdc,HRGN hrgn,HBRUSH hbr,ಪೂರ್ಣಾಂಕ w,ಪೂರ್ಣಾಂಕ h);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetROP2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_Aspect_ಅನುಪಾತ_Filter_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI COLORREF WINAPI GetBkColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCBrushColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCPenColor(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_Bk_ಬಹುಲಕ(HDC hdc);
  WINGDIAPI LONG WINAPI Get_Bitmap_ಬಿಟ್ಟುಗಳು(HBITMAP hbit,LONG cb,LPVOID lpv_ಬಿಟ್ಟುಗಳು);
  WINGDIAPI WINBOOL WINAPI GetBitmapDimensionEx(HBITMAP hbit,LPSIZE lpsize);
  WINGDIAPI UINT WINAPI GetBoundsRect(HDC hdc,LPRECT lprect,UINT flags);
  WINGDIAPI WINBOOL WINAPI GetBrushOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI Get_Char_ಅಗಲ_A(HDC hdc,UINT i_ಮೊದಲ,UINT i_ಕೊನೆಯ,LPINT lp_ಬಫರ್);
  WINGDIAPI WINBOOL WINAPI Get_Char_ಅಗಲ_W(HDC hdc,UINT i_ಮೊದಲ,UINT i_ಕೊನೆಯ,LPINT lp_ಬಫರ್);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32A(HDC hdc,UINT i_ಮೊದಲ,UINT i_ಕೊನೆಯ,LPINT lp_ಬಫರ್);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32W(HDC hdc,UINT i_ಮೊದಲ,UINT i_ಕೊನೆಯ,LPINT lp_ಬಫರ್);
  WINGDIAPI WINBOOL WINAPI Get_Char_ಅಗಲ_Float_A(HDC hdc,UINT i_ಮೊದಲ,UINT i_ಕೊನೆಯ,PFLOAT lp_ಬಫರ್);
  WINGDIAPI WINBOOL WINAPI Get_Char_ಅಗಲ_Float_W(HDC hdc,UINT i_ಮೊದಲ,UINT i_ಕೊನೆಯ,PFLOAT lp_ಬಫರ್);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsA(HDC hdc,UINT w_ಮೊದಲ,UINT w_ಕೊನೆಯ,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsW(HDC hdc,UINT w_ಮೊದಲ,UINT w_ಕೊನೆಯ,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatA(HDC hdc,UINT i_ಮೊದಲ,UINT i_ಕೊನೆಯ,LPABCFLOAT lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatW(HDC hdc,UINT i_ಮೊದಲ,UINT i_ಕೊನೆಯ,LPABCFLOAT lpABC);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetClipBox(HDC hdc,LPRECT lprect);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetMetaRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI HGDIOBJ WINAPI GetCurrentObject(HDC hdc,UINT type);
  WINGDIAPI WINBOOL WINAPI GetCurrentPositionEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetDeviceCaps(HDC hdc,ಪೂರ್ಣಾಂಕ ಸೂಚ್ಯಂಕ);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetDIBits(HDC hdc,HBITMAP hbm,UINT ಆರಂಭ,UINT c_ಸಾಲುಗಳು,LPVOID lpv_ಬಿಟ್ಟುಗಳು,LPBITMAPINFO lpbmi,UINT usage);
  WINGDIAPI DWORD WINAPI Get_Font_ದತ್ತಾಂಶ (HDC hdc,DWORD dw_ಕೋಷ್ಟಕ,DWORD dw_ಸ್ಥಾನಾಂತರ,PVOID pv_ಬಫರ್,DWORD cj_ಬಫರ್);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineA(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_ಬಫರ್,LPVOID pv_ಬಫರ್,CONST MAT2 *lpmat2);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineW(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_ಬಫರ್,LPVOID pv_ಬಫರ್,CONST MAT2 *lpmat2);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_Graphics_ಬಹುಲಕ(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_Map_ಬಹುಲಕ(HDC hdc);
  WINGDIAPI UINT WINAPI Get_Meta_File_ಬಿಟ್ಟುಗಳು_Ex(HMETAFILE hMF,UINT cb_ಬಫರ್,LPVOID lp_ದತ್ತಾಂಶ);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileA(LPCSTR lpName);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileW(LPCWSTR lpName);
  WINGDIAPI COLORREF WINAPI Get_ಹತ್ತಿರದ_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI Get_ಹತ್ತಿರದ_Palette_ಸೂಚ್ಯಂಕ(HPALETTE h,COLORREF color);
  WINGDIAPI DWORD WINAPI GetObjectType(HGDIOBJ h);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOTEXTMETRIC
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Outline_ಪಠ್ಯ_Metrics Get_Outline_ಪಠ್ಯ_Metrics_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Outline_ಪಠ್ಯ_Metrics Get_Outline_ಪಠ್ಯ_Metrics_A
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI UINT WINAPI Get_Outline_ಪಠ್ಯ_Metrics_A(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICA potm);
  WINGDIAPI UINT WINAPI Get_Outline_ಪಠ್ಯ_Metrics_W(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICW potm);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Extent_ಬಿಂದು Get_ಪಠ್ಯ_Extent_ಬಿಂದು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Extent_Point32 Get_ಪಠ್ಯ_Extent_Point32_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Extent_Ex_ಬಿಂದು Get_ಪಠ್ಯ_Extent_Ex_ಬಿಂದು_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetCharacterPlacement GetCharacterPlacementW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Extent_ಬಿಂದು Get_ಪಠ್ಯ_Extent_ಬಿಂದು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Extent_Point32 Get_ಪಠ್ಯ_Extent_Point32_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Extent_Ex_ಬಿಂದು Get_ಪಠ್ಯ_Extent_Ex_ಬಿಂದು_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetCharacterPlacement GetCharacterPlacementA
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI UINT WINAPI GetPaletteEntries(HPALETTE hpal,UINT i_ಆರಂಭ,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI COLORREF WINAPI GetPixel(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetPixelFormat(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_Poly_Fill_ಬಹುಲಕ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetRasterizerCaps(LPRASTERIZER_ಸ್ಥಿತಿ lpraststat,UINT cj_ಬೈಟುಗಳು);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetRandomRgn (HDC hdc,HRGN hrgn,INT i);
  WINGDIAPI DWORD WINAPI Get_Region_ದತ್ತಾಂಶ(HRGN hrgn,DWORD n_ಎಣಿಕೆ,LPRGNDATA lp_Rgn_ದತ್ತಾಂಶ);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetRgnBox(HRGN hrgn,LPRECT lprc);
  WINGDIAPI HGDIOBJ WINAPI GetStockObject(ಪೂರ್ಣಾಂಕ i);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_Stretch_Blt_ಬಹುಲಕ(HDC hdc);
  WINGDIAPI UINT WINAPI GetSystemPaletteEntries(HDC hdc,UINT i_ಆರಂಭ,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI UINT WINAPI GetSystemPaletteUse(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಪಠ್ಯ_Character_Extra(HDC hdc);
  WINGDIAPI UINT WINAPI Get_ಪಠ್ಯ_Align(HDC hdc);
  WINGDIAPI COLORREF WINAPI Get_ಪಠ್ಯ_Color(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Extent_ಬಿಂದು_A(HDC hdc,LPCSTR lpString,ಪೂರ್ಣಾಂಕ c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Extent_ಬಿಂದು_W(HDC hdc,LPCWSTR lpString,ಪೂರ್ಣಾಂಕ c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Extent_Point32_A(HDC hdc,LPCSTR lpString,ಪೂರ್ಣಾಂಕ c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Extent_Point32_W(HDC hdc,LPCWSTR lpString,ಪೂರ್ಣಾಂಕ c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Extent_Ex_ಬಿಂದು_A(HDC hdc,LPCSTR lpszString,ಪೂರ್ಣಾಂಕ cchString,ಪೂರ್ಣಾಂಕ nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_ಗಾತ್ರ);
  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Extent_Ex_ಬಿಂದು_W(HDC hdc,LPCWSTR lpszString,ಪೂರ್ಣಾಂಕ cchString,ಪೂರ್ಣಾಂಕ nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_ಗಾತ್ರ);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಪಠ್ಯ_Charset(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಪಠ್ಯ_Charset_Info(HDC hdc,LPFONTSIGNATURE lpSig,DWORD dwFlags);
  WINGDIAPI WINBOOL WINAPI TranslateCharsetInfo(DWORD *lpSrc,LPCHARSETINFO lpCs,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetFontLanguageInfo(HDC hdc);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementA(HDC hdc,LPCSTR lpString,ಪೂರ್ಣಾಂಕ n_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ nMexExtent,LPGCP_RESULTSA lpResults,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementW(HDC hdc,LPCWSTR lpString,ಪೂರ್ಣಾಂಕ n_ಎಣಿಕೆ,ಪೂರ್ಣಾಂಕ nMexExtent,LPGCP_RESULTSW lpResults,DWORD dwFlags);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_WCRANGE {
    WCHAR wc_ಕೆಳಗಿನ;
    USHORT cGlyphs;
  } WCRANGE,*PWCRANGE,*LPWCRANGE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_GLYPHSET {
    DWORD cbThis;
    DWORD flAccel;
    DWORD cGlyphsSupported;
    DWORD cRanges;
    WCRANGE ranges[1];
  } GLYPHSET,*PGLYPHSET,*LPGLYPHSET;

#ವ್ಯಾಖ್ಯಾನಿಸು GS_8_ಬಿಟ್_INDICES 0x00000001

#ವ್ಯಾಖ್ಯಾನಿಸು GGI_MARK_NONEXISTING_GLYPHS 0X0001

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು GetGlyphIndices GetGlyphIndicesW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು GetGlyphIndices GetGlyphIndicesA
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI DWORD WINAPI GetFontUnicodeRanges(HDC hdc,LPGLYPHSET lpgs);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesA(HDC hdc,LPCSTR lpstr,ಪೂರ್ಣಾಂಕ c,LPWORD pgi,DWORD fl);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesW(HDC hdc,LPCWSTR lpstr,ಪೂರ್ಣಾಂಕ c,LPWORD pgi,DWORD fl);
  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Extent_ಬಿಂದು_I(HDC hdc,LPWORD pgi_ಒಳ,ಪೂರ್ಣಾಂಕ cgi,LPSIZE psize);
  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Extent_Ex_ಬಿಂದು_I (HDC hdc,LPWORD lpwszString,ಪೂರ್ಣಾಂಕ cwchString,ಪೂರ್ಣಾಂಕ nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_ಗಾತ್ರ);
  WINGDIAPI WINBOOL WINAPI Get_Char_ಅಗಲ_I(HDC hdc,UINT gi_ಮೊದಲ,UINT cgi,LPWORD pgi,LPINT piWidths);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsI(HDC hdc,UINT gi_ಮೊದಲ,UINT cgi,LPWORD pgi,LPABC pabc);

#ವ್ಯಾಖ್ಯಾನಿಸು STAMP_DESIGNVECTOR (0x8000000 + 'd' + ('v' << 8))
#ವ್ಯಾಖ್ಯಾನಿಸು STAMP_AXESLIST (0x8000000 + 'a' + ('l' << 8))
#ವ್ಯಾಖ್ಯಾನಿಸು MM_MAX_NUMAXES 16

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_DESIGNVECTOR {
    DWORD dvReserved;
    DWORD dv_ಅಂಕೆ_Axes;
    LONG dv_ಮೌಲ್ಯಗಳು[MM_MAX_NUMAXES];
  } DESIGNVECTOR,*PDESIGNVECTOR,*LPDESIGNVECTOR;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Font_Resource_Ex ಕೂಡಿಸು_Font_Resource_Ex_W
#ವ್ಯಾಖ್ಯಾನಿಸು RemoveFontResourceEx RemoveFontResourceExW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೂಡಿಸು_Font_Resource_Ex ಕೂಡಿಸು_Font_Resource_Ex_A
#ವ್ಯಾಖ್ಯಾನಿಸು RemoveFontResourceEx RemoveFontResourceExA
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಕೂಡಿಸು_Font_Resource_Ex_A(LPCSTR name,DWORD fl,PVOID res);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಕೂಡಿಸು_Font_Resource_Ex_W(LPCWSTR name,DWORD fl,PVOID res);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExA(LPCSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExW(LPCWSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI HANDLE WINAPI ಕೂಡಿಸು_Font_Mem_Resource_Ex(PVOID pFileView,DWORD cj_ಗಾತ್ರ,PVOID pvResrved,DWORD *p_ಅಂಕೆ_Fonts);
  WINGDIAPI WINBOOL WINAPI RemoveFontMemResourceEx(HANDLE h);

#ವ್ಯಾಖ್ಯಾನಿಸು FR_ಖಾಸಗಿ 0x10
#ವ್ಯಾಖ್ಯಾನಿಸು FR_NOT_ENUM 0x20

#ವ್ಯಾಖ್ಯಾನಿಸು MM_MAX_AXES_NAMELEN 16

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_AXISINFOA {
    LONG ax_Min_ಮೌಲ್ಯ;
    LONG ax_Max_ಮೌಲ್ಯ;
    BYTE axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOA,*PAXISINFOA,*LPAXISINFOA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_AXISINFOW {
    LONG ax_Min_ಮೌಲ್ಯ;
    LONG ax_Max_ಮೌಲ್ಯ;
    WCHAR axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOW,*PAXISINFOW,*LPAXISINFOW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ AXISINFOW AXISINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PAXISINFOW PAXISINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPAXISINFOW LPAXISINFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ AXISINFOA AXISINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PAXISINFOA PAXISINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPAXISINFOA LPAXISINFO;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_AXESLISTA {
    DWORD axlReserved;
    DWORD axl_ಅಂಕೆ_Axes;
    AXISINFOA axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTA,*PAXESLISTA,*LPAXESLISTA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_AXESLISTW {
    DWORD axlReserved;
    DWORD axl_ಅಂಕೆ_Axes;
    AXISINFOW axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTW,*PAXESLISTW,*LPAXESLISTW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ AXESLISTW AXESLIST;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PAXESLISTW PAXESLIST;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPAXESLISTW LPAXESLIST;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ AXESLISTA AXESLIST;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PAXESLISTA PAXESLIST;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPAXESLISTA LPAXESLIST;
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENUMLOGFONTEXDVA {
    ENUMLOGFONTEXA elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_ಸದಿಶ;
  } ENUMLOGFONTEXDVA,*PENUMLOGFONTEXDVA,*LPENUMLOGFONTEXDVA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENUMLOGFONTEXDVW {
    ENUMLOGFONTEXW elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_ಸದಿಶ;
  } ENUMLOGFONTEXDVW,*PENUMLOGFONTEXDVW,*LPENUMLOGFONTEXDVW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ENUMLOGFONTEXDVW ENUMLOGFONTEXDV;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PENUMLOGFONTEXDVW PENUMLOGFONTEXDV;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPENUMLOGFONTEXDVW LPENUMLOGFONTEXDV;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ENUMLOGFONTEXDVA ENUMLOGFONTEXDV;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PENUMLOGFONTEXDVA PENUMLOGFONTEXDV;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPENUMLOGFONTEXDVA LPENUMLOGFONTEXDV;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Font_ಪರೋಕ್ಷ_Ex Create_Font_ಪರೋಕ್ಷ_Ex_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Create_Font_ಪರೋಕ್ಷ_Ex Create_Font_ಪರೋಕ್ಷ_Ex_A
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI HFONT WINAPI Create_Font_ಪರೋಕ್ಷ_Ex_A(CONST ENUMLOGFONTEXDVA *);
  WINGDIAPI HFONT WINAPI Create_Font_ಪರೋಕ್ಷ_Ex_W(CONST ENUMLOGFONTEXDVW *);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOTEXTMETRIC
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENUMTEXTMETRICA {
    NEWTEXTMETRICEXA etm_New_ಪಠ್ಯ_Metric_Ex;
    AXESLISTA etmAxesList;
  } ENUMTEXTMETRICA,*PENUMTEXTMETRICA,*LPENUMTEXTMETRICA;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ENUMTEXTMETRICW
  {
    NEWTEXTMETRICEXW etm_New_ಪಠ್ಯ_Metric_Ex;
    AXESLISTW etmAxesList;
  } ENUMTEXTMETRICW,*PENUMTEXTMETRICW,*LPENUMTEXTMETRICW;
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ENUMTEXTMETRICW ENUMTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PENUMTEXTMETRICW PENUMTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPENUMTEXTMETRICW LPENUMTEXTMETRIC;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ENUMTEXTMETRICA ENUMTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ PENUMTEXTMETRICA PENUMTEXTMETRIC;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPENUMTEXTMETRICA LPENUMTEXTMETRIC;
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ResetDC ResetDCW
#ವ್ಯಾಖ್ಯಾನಿಸು RemoveFontResource RemoveFontResourceW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ResetDC ResetDCA
#ವ್ಯಾಖ್ಯಾನಿಸು RemoveFontResource RemoveFontResourceA
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI WINBOOL WINAPI GetViewportExtEx(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI GetViewportOrgEx(HDC hdc,LPPOINT lppoint);
  WINGDIAPI WINBOOL WINAPI Get_ಕಿಟಕಿ_Ext_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI Get_ಕಿಟಕಿ_Org_Ex(HDC hdc,LPPOINT lppoint);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI IntersectClipRect(HDC hdc,ಪೂರ್ಣಾಂಕ ಎಡ,ಪೂರ್ಣಾಂಕ ತುದಿ,ಪೂರ್ಣಾಂಕ ಬಲ,ಪೂರ್ಣಾಂಕ bottom);
  WINGDIAPI WINBOOL WINAPI InvertRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI ಸಾಲು_DDA(ಪೂರ್ಣಾಂಕ x_ಆರಂಭ,ಪೂರ್ಣಾಂಕ y_ಆರಂಭ,ಪೂರ್ಣಾಂಕ x_ಕೊನೆ,ಪೂರ್ಣಾಂಕ y_ಕೊನೆ,LINEDDAPROC lpProc,LPARAM ದತ್ತಾಂಶ);
  WINGDIAPI WINBOOL WINAPI ಸಾಲು_ಗಮ್ಯ(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y);
  WINGDIAPI WINBOOL WINAPI ಮುಖವಾಡ_Blt(HDC hdcDest,ಪೂರ್ಣಾಂಕ xDest,ಪೂರ್ಣಾಂಕ yDest,ಪೂರ್ಣಾಂಕ ಅಗಲ,ಪೂರ್ಣಾಂಕ ಎತ್ತರ,HDC hdcSrc,ಪೂರ್ಣಾಂಕ xSrc,ಪೂರ್ಣಾಂಕ ySrc,HBITMAP hbm_ಮುಖವಾಡ,ಪೂರ್ಣಾಂಕ x_ಮುಖವಾಡ,ಪೂರ್ಣಾಂಕ y_ಮುಖವಾಡ,DWORD rop);
  WINGDIAPI WINBOOL WINAPI PlgBlt(HDC hdcDest,CONST ಬಿಂದು_3 *lp_ಬಿಂದು,HDC hdcSrc,ಪೂರ್ಣಾಂಕ xSrc,ಪೂರ್ಣಾಂಕ ySrc,ಪೂರ್ಣಾಂಕ ಅಗಲ,ಪೂರ್ಣಾಂಕ ಎತ್ತರ,HBITMAP hbm_ಮುಖವಾಡ,ಪೂರ್ಣಾಂಕ x_ಮುಖವಾಡ,ಪೂರ್ಣಾಂಕ y_ಮುಖವಾಡ);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಸ್ಥಾನಾಂತರ_Clip_Rgn(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಸ್ಥಾನಾಂತರ_Rgn(HRGN hrgn,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y);
  WINGDIAPI WINBOOL WINAPI PatBlt(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,ಪೂರ್ಣಾಂಕ w,ಪೂರ್ಣಾಂಕ h,DWORD rop);
  WINGDIAPI WINBOOL WINAPI Pie(HDC hdc,ಪೂರ್ಣಾಂಕ ಎಡ,ಪೂರ್ಣಾಂಕ ತುದಿ,ಪೂರ್ಣಾಂಕ ಬಲ,ಪೂರ್ಣಾಂಕ bottom,ಪೂರ್ಣಾಂಕ xr1,ಪೂರ್ಣಾಂಕ yr1,ಪೂರ್ಣಾಂಕ xr2,ಪೂರ್ಣಾಂಕ yr2);
  WINGDIAPI WINBOOL WINAPI PlayMetaFile(HDC hdc,HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI PaintRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI PolyPolygon(HDC hdc,CONST ಬಿಂದು_3 *apt,CONST INT *asz,ಪೂರ್ಣಾಂಕ csz);
  WINGDIAPI WINBOOL WINAPI Pt_ಒಳ_Region(HRGN hrgn,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y);
  WINGDIAPI WINBOOL WINAPI PtVisible(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y);
  WINGDIAPI WINBOOL WINAPI Rect_ಒಳ_Region(HRGN hrgn,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI RectVisible(HDC hdc,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Rectangle(HDC hdc,ಪೂರ್ಣಾಂಕ ಎಡ,ಪೂರ್ಣಾಂಕ ತುದಿ,ಪೂರ್ಣಾಂಕ ಬಲ,ಪೂರ್ಣಾಂಕ bottom);
  WINGDIAPI WINBOOL WINAPI RestoreDC(HDC hdc,ಪೂರ್ಣಾಂಕ nSavedDC);
  WINGDIAPI HDC WINAPI ResetDCA(HDC hdc,CONST DEVMODEA *lpdm);
  WINGDIAPI HDC WINAPI ResetDCW(HDC hdc,CONST DEVMODEW *lpdm);
  WINGDIAPI UINT WINAPI RealizePalette(HDC hdc);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceA(LPCSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceW(LPCWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI ಸುತ್ತು_Rect(HDC hdc,ಪೂರ್ಣಾಂಕ ಎಡ,ಪೂರ್ಣಾಂಕ ತುದಿ,ಪೂರ್ಣಾಂಕ ಬಲ,ಪೂರ್ಣಾಂಕ bottom,ಪೂರ್ಣಾಂಕ ಅಗಲ,ಪೂರ್ಣಾಂಕ ಎತ್ತರ);
  WINGDIAPI WINBOOL WINAPI ResizePalette(HPALETTE hpal,UINT n);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI SaveDC(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI SelectClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ExtSelectClipRgn(HDC hdc,HRGN hrgn,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Meta_Rgn(HDC hdc);
  WINGDIAPI HGDIOBJ WINAPI SelectObject(HDC hdc,HGDIOBJ h);
  WINGDIAPI HPALETTE WINAPI SelectPalette(HDC hdc,HPALETTE hPal,WINBOOL bForceBkgd);
  WINGDIAPI COLORREF WINAPI ಗಣ_Bk_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI ಗಣ_DCBrush_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI ಗಣ_DCPen_Color(HDC hdc,COLORREF color);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Bk_ಬಹುಲಕ(HDC hdc,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ);
  WINGDIAPI LONG WINAPI ಗಣ_Bitmap_ಬಿಟ್ಟುಗಳು(HBITMAP hbm,DWORD cb,CONST VOID *pv_ಬಿಟ್ಟುಗಳು);
  WINGDIAPI UINT WINAPI ಗಣ_Bounds_Rect(HDC hdc,CONST RECT *lprect,UINT flags);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_DIBits(HDC hdc,HBITMAP hbm,UINT ಆರಂಭ,UINT c_ಸಾಲುಗಳು,CONST VOID *lp_ಬಿಟ್ಟುಗಳು,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_DIBits_ಗಮ್ಯ_Device(HDC hdc,ಪೂರ್ಣಾಂಕ xDest,ಪೂರ್ಣಾಂಕ yDest,DWORD w,DWORD h,ಪೂರ್ಣಾಂಕ xSrc,ಪೂರ್ಣಾಂಕ ySrc,UINT ಆರಂಭ_ಪರಿಶೀಲನೆ,UINT c_ಸಾಲುಗಳು,CONST VOID *lpv_ಬಿಟ್ಟುಗಳು,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI DWORD WINAPI ಗಣ_Mapper_Flags(HDC hdc,DWORD flags);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Graphics_ಬಹುಲಕ(HDC hdc,ಪೂರ್ಣಾಂಕ i_ಬಹುಲಕ);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Map_ಬಹುಲಕ(HDC hdc,ಪೂರ್ಣಾಂಕ i_ಬಹುಲಕ);
  WINGDIAPI DWORD WINAPI ಗಣ_Layout(HDC hdc,DWORD l);
  WINGDIAPI DWORD WINAPI GetLayout(HDC hdc);
  WINGDIAPI HMETAFILE WINAPI ಗಣ_Meta_File_ಬಿಟ್ಟುಗಳು_Ex(UINT cb_ಬಫರ್,CONST BYTE *lp_ದತ್ತಾಂಶ);
  WINGDIAPI UINT WINAPI ಗಣ_Palette_Entries(HPALETTE hpal,UINT i_ಆರಂಭ,UINT cEntries,CONST PALETTEENTRY *pPalEntries);
  WINGDIAPI COLORREF WINAPI ಗಣ_Pixel(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI ಗಣ_Pixel_V(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI ಗಣ_Pixel_Format(HDC hdc,ಪೂರ್ಣಾಂಕ format,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Poly_Fill_ಬಹುಲಕ(HDC hdc,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ);
  WINGDIAPI WINBOOL WINAPI StretchBlt(HDC hdcDest,ಪೂರ್ಣಾಂಕ xDest,ಪೂರ್ಣಾಂಕ yDest,ಪೂರ್ಣಾಂಕ wDest,ಪೂರ್ಣಾಂಕ hDest,HDC hdcSrc,ಪೂರ್ಣಾಂಕ xSrc,ಪೂರ್ಣಾಂಕ ySrc,ಪೂರ್ಣಾಂಕ wSrc,ಪೂರ್ಣಾಂಕ hSrc,DWORD rop);
  WINGDIAPI WINBOOL WINAPI ಗಣ_Rect_Rgn(HRGN hrgn,ಪೂರ್ಣಾಂಕ ಎಡ,ಪೂರ್ಣಾಂಕ ತುದಿ,ಪೂರ್ಣಾಂಕ ಬಲ,ಪೂರ್ಣಾಂಕ bottom);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI StretchDIBits(HDC hdc,ಪೂರ್ಣಾಂಕ xDest,ಪೂರ್ಣಾಂಕ yDest,ಪೂರ್ಣಾಂಕ Dest_ಅಗಲ,ಪೂರ್ಣಾಂಕ Dest_ಎತ್ತರ,ಪೂರ್ಣಾಂಕ xSrc,ಪೂರ್ಣಾಂಕ ySrc,ಪೂರ್ಣಾಂಕ Src_ಅಗಲ,ಪೂರ್ಣಾಂಕ Src_ಎತ್ತರ,CONST VOID *lp_ಬಿಟ್ಟುಗಳು,CONST BITMAPINFO *lpbmi,UINT iUsage,DWORD rop);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_ROP2(HDC hdc,ಪೂರ್ಣಾಂಕ rop2);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Stretch_Blt_ಬಹುಲಕ(HDC hdc,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ);
  WINGDIAPI UINT WINAPI ಗಣ_System_Palette_Use(HDC hdc,UINT use);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_ಪಠ್ಯ_Character_Extra(HDC hdc,ಪೂರ್ಣಾಂಕ extra);
  WINGDIAPI COLORREF WINAPI ಗಣ_ಪಠ್ಯ_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI ಗಣ_ಪಠ್ಯ_Align(HDC hdc,UINT align);
  WINGDIAPI WINBOOL WINAPI ಗಣ_ಪಠ್ಯ_Justification(HDC hdc,ಪೂರ್ಣಾಂಕ extra,ಪೂರ್ಣಾಂಕ ಎಣಿಕೆ_3);
  WINGDIAPI WINBOOL WINAPI UpdateColors(HDC hdc);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ USHORT COLOR16;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _TRIVERTEX {
    LONG x;
    LONG y;
    COLOR16 Red;
    COLOR16 Green;
    COLOR16 Blue;
    COLOR16 Alpha;
  } TRIVERTEX,*PTRIVERTEX,*LPTRIVERTEX;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _GRADIENT_TRIANGLE {
    ULONG Vertex1;
    ULONG Vertex2;
    ULONG Vertex3;
  } GRADIENT_TRIANGLE,*PGRADIENT_TRIANGLE,*LPGRADIENT_TRIANGLE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _GRADIENT_RECT {
    ULONG ಊರ್ಧ್ವ_ಎಡ;
    ULONG ಅಧೋ_ಬಲ;
  } GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _BLENDFUNCTION {
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE ಮೂಲ_Constant_Alpha;
    BYTE AlphaFormat;
  } BLENDFUNCTION,*PBLENDFUNCTION;

#ವ್ಯಾಖ್ಯಾನಿಸು AC_SRC_OVER 0x00
#ವ್ಯಾಖ್ಯಾನಿಸು AC_SRC_ALPHA 0x01

  WINGDIAPI WINBOOL WINAPI AlphaBlend(HDC hdcDest,ಪೂರ್ಣಾಂಕ xoriginDest,ಪೂರ್ಣಾಂಕ yoriginDest,ಪೂರ್ಣಾಂಕ wDest,ಪೂರ್ಣಾಂಕ hDest,HDC hdcSrc,ಪೂರ್ಣಾಂಕ xoriginSrc,ಪೂರ್ಣಾಂಕ yoriginSrc,ಪೂರ್ಣಾಂಕ wSrc,ಪೂರ್ಣಾಂಕ hSrc,BLENDFUNCTION ftn);
  WINGDIAPI WINBOOL WINAPI TransparentBlt(HDC hdcDest,ಪೂರ್ಣಾಂಕ xoriginDest,ಪೂರ್ಣಾಂಕ yoriginDest,ಪೂರ್ಣಾಂಕ wDest,ಪೂರ್ಣಾಂಕ hDest,HDC hdcSrc,ಪೂರ್ಣಾಂಕ xoriginSrc,ಪೂರ್ಣಾಂಕ yoriginSrc,ಪೂರ್ಣಾಂಕ wSrc,ಪೂರ್ಣಾಂಕ hSrc,UINT crTransparent);

#ವ್ಯಾಖ್ಯಾನಿಸು GRADIENT_FILL_RECT_H 0x00000000
#ವ್ಯಾಖ್ಯಾನಿಸು GRADIENT_FILL_RECT_V 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು GRADIENT_FILL_TRIANGLE 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು GRADIENT_FILL_OP_FLAG 0x000000ff

  WINGDIAPI WINBOOL WINAPI GradientFill(HDC hdc,PTRIVERTEX p_ಶೃಂಗ,ULONG n_ಶೃಂಗ,PVOID pMesh,ULONG nMesh,ULONG ul_ಬಹುಲಕ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMETAFILE

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು CopyEnhMetaFile CopyEnhMetaFileW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateEnhMetaFile CreateEnhMetaFileW
#ವ್ಯಾಖ್ಯಾನಿಸು GetEnhMetaFile GetEnhMetaFileW
#ವ್ಯಾಖ್ಯಾನಿಸು GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು CopyEnhMetaFile CopyEnhMetaFileA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateEnhMetaFile CreateEnhMetaFileA
#ವ್ಯಾಖ್ಯಾನಿಸು GetEnhMetaFile GetEnhMetaFileA
#ವ್ಯಾಖ್ಯಾನಿಸು GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI WINBOOL WINAPI Play_Meta_File_ದಾಖಲೆ(HDC hdc,LPHANDLETABLE lp_Handle_ಕೋಷ್ಟಕ,LPMETARECORD lpMR,UINT noObjs);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *MFENUMPROC)(HDC hdc,HANDLETABLE *lpht,METARECORD *lpMR,ಪೂರ್ಣಾಂಕ nObj,LPARAM param);

  WINGDIAPI WINBOOL WINAPI EnumMetaFile(HDC hdc,HMETAFILE hmf,MFENUMPROC proc,LPARAM param);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *ENHMFENUMPROC)(HDC hdc,HANDLETABLE *lpht,CONST ENHMETARECORD *lpmr,ಪೂರ್ಣಾಂಕ hHandles,LPARAM ದತ್ತಾಂಶ);

  WINGDIAPI HENHMETAFILE WINAPI CloseEnhMetaFile(HDC hdc);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileA(HENHMETAFILE hEnh,LPCSTR lpFileName);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileW(HENHMETAFILE hEnh,LPCWSTR lpFileName);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileA(HDC hdc,LPCSTR lpFilename,CONST RECT *lprc,LPCSTR lpDesc);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileW(HDC hdc,LPCWSTR lpFilename,CONST RECT *lprc,LPCWSTR lpDesc);
  WINGDIAPI WINBOOL WINAPI DeleteEnhMetaFile(HENHMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI EnumEnhMetaFile(HDC hdc,HENHMETAFILE hmf,ENHMFENUMPROC proc,LPVOID param,CONST RECT *lpRect);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileA(LPCSTR lpName);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileW(LPCWSTR lpName);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_ಬಿಟ್ಟುಗಳು(HENHMETAFILE hEMF,UINT n_ಗಾತ್ರ,LPBYTE lp_ದತ್ತಾಂಶ);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE hemf,UINT cch_ಬಫರ್,LPSTR lpDescription);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE hemf,UINT cch_ಬಫರ್,LPWSTR lpDescription);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_ಶೀರ್ಷಿಕೆ(HENHMETAFILE hemf,UINT n_ಗಾತ್ರ,LPENHMETAHEADER lp_Enh_Meta_ಶೀರ್ಷಿಕೆ);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT n_ಅಂಕೆ_Entries,LPPALETTEENTRY lpPaletteEntries);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePixelFormat(HENHMETAFILE hemf,UINT cb_ಬಫರ್,PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI UINT WINAPI Get_Win_Meta_File_ಬಿಟ್ಟುಗಳು(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT i_Map_ಬಹುಲಕ,HDC hdcRef);
  WINGDIAPI WINBOOL WINAPI PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Play_Enh_Meta_File_ದಾಖಲೆ(HDC hdc,LPHANDLETABLE pht,CONST ENHMETARECORD *pmr,UINT cht);
  WINGDIAPI HENHMETAFILE WINAPI ಗಣ_Enh_Meta_File_ಬಿಟ್ಟುಗಳು(UINT n_ಗಾತ್ರ,CONST BYTE *pb);
  WINGDIAPI HENHMETAFILE WINAPI ಗಣ_Win_Meta_File_ಬಿಟ್ಟುಗಳು(UINT n_ಗಾತ್ರ,CONST BYTE *lp_Meta16_ದತ್ತಾಂಶ,HDC hdcRef,CONST METAFILEPICT *lpMFP);
  WINGDIAPI WINBOOL WINAPI GdiComment(HDC hdc,UINT n_ಗಾತ್ರ,CONST BYTE *lp_ದತ್ತಾಂಶ);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOTEXTMETRIC
#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Metrics Get_ಪಠ್ಯ_Metrics_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Metrics Get_ಪಠ್ಯ_Metrics_A
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Metrics_A(HDC hdc,LPTEXTMETRICA lptm);
  WINGDIAPI WINBOOL WINAPI Get_ಪಠ್ಯ_Metrics_W(HDC hdc,LPTEXTMETRICW lptm);
#ಆದರೆ_ಅಂತ್ಯ

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_DIBSECTION {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD ds_ಸ್ಥಾನಾಂತರ;
  } DIBSECTION,*LPDIBSECTION,*PDIBSECTION;

  WINGDIAPI WINBOOL WINAPI AngleArc(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,DWORD r,FLOAT ಆರಂಭ_Angle,FLOAT SweepAngle);
  WINGDIAPI WINBOOL WINAPI PolyPolyline(HDC hdc,CONST ಬಿಂದು_3 *apt,CONST DWORD *asz,DWORD csz);
  WINGDIAPI WINBOOL WINAPI GetWorldTransform(HDC hdc,LPXFORM lpxf);
  WINGDIAPI WINBOOL WINAPI ಗಣ_World_Transform(HDC hdc,CONST XFORM *lpxf);
  WINGDIAPI WINBOOL WINAPI ModifyWorldTransform(HDC hdc,CONST XFORM *lpxf,DWORD ಬಹುಲಕ);
  WINGDIAPI WINBOOL WINAPI CombineTransform(LPXFORM lpxf_ಹೊರಹೋಗು,CONST XFORM *lpxf1,CONST XFORM *lpxf2);
  WINGDIAPI HBITMAP WINAPI CreateDIBSection(HDC hdc,CONST BITMAPINFO *lpbmi,UINT usage,VOID **ppv_ಬಿಟ್ಟುಗಳು,HANDLE hSection,DWORD ಸ್ಥಾನಾಂತರ);
  WINGDIAPI UINT WINAPI Get_DIBColor_ಕೋಷ್ಟಕ(HDC hdc,UINT i_ಆರಂಭ,UINT cEntries,RGBQUAD *prgbq);
  WINGDIAPI UINT WINAPI ಗಣ_DIBColor_ಕೋಷ್ಟಕ(HDC hdc,UINT i_ಆರಂಭ,UINT cEntries,CONST RGBQUAD *prgbq);

#ವ್ಯಾಖ್ಯಾನಿಸು CA_NEGATIVE 0x0001
#ವ್ಯಾಖ್ಯಾನಿಸು CA_LOG_FILTER 0x0002

#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_DEVICE_DEFAULT 0
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_A 1
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_B 2
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_C 3
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_D50 4
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_D55 5
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_D65 6
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_D75 7
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_F2 8
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_MAX_ಸೂಚ್ಯಂಕ ILLUMINANT_F2

#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_TUNGSTEN ILLUMINANT_A
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_DAYLIGHT ILLUMINANT_C
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_FLUORESCENT ILLUMINANT_F2
#ವ್ಯಾಖ್ಯಾನಿಸು ILLUMINANT_NTSC ILLUMINANT_C

#ವ್ಯಾಖ್ಯಾನಿಸು RGB_GAMMA_MIN (ಶಬ್ದ_3)02500
#ವ್ಯಾಖ್ಯಾನಿಸು RGB_GAMMA_MAX (ಶಬ್ದ_3)65000

#ವ್ಯಾಖ್ಯಾನಿಸು REFERENCE_WHITE_MIN (ಶಬ್ದ_3)6000
#ವ್ಯಾಖ್ಯಾನಿಸು REFERENCE_WHITE_MAX (ಶಬ್ದ_3)10000
#ವ್ಯಾಖ್ಯಾನಿಸು REFERENCE_BLACK_MIN (ಶಬ್ದ_3)0
#ವ್ಯಾಖ್ಯಾನಿಸು REFERENCE_BLACK_MAX (ಶಬ್ದ_3)4000

#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_ADJ_MIN (SHORT)-100
#ವ್ಯಾಖ್ಯಾನಿಸು COLOR_ADJ_MAX (SHORT)100

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_COLORADJUSTMENT {
    ಶಬ್ದ_3 ca_ಗಾತ್ರ;
    ಶಬ್ದ_3 caFlags;
    ಶಬ್ದ_3 ca_Illuminant_ಸೂಚ್ಯಂಕ;
    ಶಬ್ದ_3 caRedGamma;
    ಶಬ್ದ_3 caGreenGamma;
    ಶಬ್ದ_3 caBlueGamma;
    ಶಬ್ದ_3 caReferenceBlack;
    ಶಬ್ದ_3 caReferenceWhite;
    SHORT caContrast;
    SHORT caBrightness;
    SHORT caColorfulness;
    SHORT caRedGreenTint;
  } COLORADJUSTMENT,*PCOLORADJUSTMENT,*LPCOLORADJUSTMENT;

  WINGDIAPI WINBOOL WINAPI ಗಣ_Color_Adjustment(HDC hdc,CONST COLORADJUSTMENT *lpca);
  WINGDIAPI WINBOOL WINAPI GetColorAdjustment(HDC hdc,LPCOLORADJUSTMENT lpca);
  WINGDIAPI HPALETTE WINAPI CreateHalftonePalette(HDC hdc);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ WINBOOL (CALLBACK *ABORTPROC)(HDC,ಪೂರ್ಣಾಂಕ);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _DOCINFOA {
    ಪೂರ್ಣಾಂಕ cb_ಗಾತ್ರ;
    LPCSTR lpszDocName;
    LPCSTR lpszOutput;
    LPCSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOA,*LPDOCINFOA;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _DOCINFOW {
    ಪೂರ್ಣಾಂಕ cb_ಗಾತ್ರ;
    LPCWSTR lpszDocName;
    LPCWSTR lpszOutput;
    LPCWSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOW,*LPDOCINFOW;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DOCINFOW DOCINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDOCINFOW LPDOCINFO;
#ಇಲ್ಲದಿದ್ದರೆ
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ DOCINFOA DOCINFO;
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ LPDOCINFOA LPDOCINFO;
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿಸು DI_APPBANDING 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು DI_ROPS_READ_DESTINATION 0x00000002

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ಆರಂಭ_Doc ಆರಂಭ_Doc_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetObject GetObjectW
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಠ್ಯ_ಹೊರಹೋಗು ಪಠ್ಯ_ಹೊರಹೋಗು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Ext_ಪಠ್ಯ_ಹೊರಹೋಗು Ext_ಪಠ್ಯ_ಹೊರಹೋಗು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Poly_ಪಠ್ಯ_ಹೊರಹೋಗು Poly_ಪಠ್ಯ_ಹೊರಹೋಗು_W
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Face Get_ಪಠ್ಯ_Face_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ಆರಂಭ_Doc ಆರಂಭ_Doc_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetObject GetObjectA
#ವ್ಯಾಖ್ಯಾನಿಸು ಪಠ್ಯ_ಹೊರಹೋಗು ಪಠ್ಯ_ಹೊರಹೋಗು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Ext_ಪಠ್ಯ_ಹೊರಹೋಗು Ext_ಪಠ್ಯ_ಹೊರಹೋಗು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Poly_ಪಠ್ಯ_ಹೊರಹೋಗು Poly_ಪಠ್ಯ_ಹೊರಹೋಗು_A
#ವ್ಯಾಖ್ಯಾನಿಸು Get_ಪಠ್ಯ_Face Get_ಪಠ್ಯ_Face_A
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಆರಂಭ_Doc_A(HDC hdc,CONST DOCINFOA *lpdi);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಆರಂಭ_Doc_W(HDC hdc,CONST DOCINFOW *lpdi);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಕೊನೆ_Doc(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಆರಂಭ_ಪುಟ(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಕೊನೆ_ಪುಟ(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI AbortDoc(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Abort_Proc(HDC hdc,ABORTPROC proc);
  WINGDIAPI WINBOOL WINAPI Abort_ಮಾರ್ಗ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Arc_ಗಮ್ಯ(HDC hdc,ಪೂರ್ಣಾಂಕ ಎಡ,ಪೂರ್ಣಾಂಕ ತುದಿ,ಪೂರ್ಣಾಂಕ ಬಲ,ಪೂರ್ಣಾಂಕ bottom,ಪೂರ್ಣಾಂಕ xr1,ಪೂರ್ಣಾಂಕ yr1,ಪೂರ್ಣಾಂಕ xr2,ಪೂರ್ಣಾಂಕ yr2);
  WINGDIAPI WINBOOL WINAPI Begin_ಮಾರ್ಗ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI CloseFigure(HDC hdc);
  WINGDIAPI WINBOOL WINAPI ಕೊನೆ_ಮಾರ್ಗ_2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Fill_ಮಾರ್ಗ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Flatten_ಮಾರ್ಗ(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಮಾರ್ಗ(HDC hdc,LPPOINT apt,LPBYTE aj,ಪೂರ್ಣಾಂಕ cpt);
  WINGDIAPI HRGN WINAPI ಮಾರ್ಗ_ಗಮ್ಯ_Region(HDC hdc);
  WINGDIAPI WINBOOL WINAPI PolyDraw(HDC hdc,CONST ಬಿಂದು_3 *apt,CONST BYTE *aj,ಪೂರ್ಣಾಂಕ cpt);
  WINGDIAPI WINBOOL WINAPI Select_Clip_ಮಾರ್ಗ(HDC hdc,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_Arc_Direction(HDC hdc,ಪೂರ್ಣಾಂಕ dir);
  WINGDIAPI WINBOOL WINAPI ಗಣ_Miter_ಎಲ್ಲೆ(HDC hdc,FLOAT ಎಲ್ಲೆ,PFLOAT old);
  WINGDIAPI WINBOOL WINAPI Stroke_And_Fill_ಮಾರ್ಗ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Stroke_ಮಾರ್ಗ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Widen_ಮಾರ್ಗ(HDC hdc);
  WINGDIAPI HPEN WINAPI ExtCreatePen(DWORD iPenStyle,DWORD c_ಅಗಲ,CONST LOGBRUSH *plbrush,DWORD cStyle,CONST DWORD *pstyle);
  WINGDIAPI WINBOOL WINAPI Get_Miter_ಎಲ್ಲೆ(HDC hdc,PFLOAT plimit);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetArcDirection(HDC hdc);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetObjectA(HANDLE h,ಪೂರ್ಣಾಂಕ c,LPVOID pv);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI GetObjectW(HANDLE h,ಪೂರ್ಣಾಂಕ c,LPVOID pv);
  WINGDIAPI WINBOOL WINAPI Move_ಗಮ್ಯ_Ex(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ಪಠ್ಯ_ಹೊರಹೋಗು_A(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPCSTR lpString,ಪೂರ್ಣಾಂಕ c);
  WINGDIAPI WINBOOL WINAPI ಪಠ್ಯ_ಹೊರಹೋಗು_W(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPCWSTR lpString,ಪೂರ್ಣಾಂಕ c);
  WINGDIAPI WINBOOL WINAPI Ext_ಪಠ್ಯ_ಹೊರಹೋಗು_A(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,UINT options,CONST RECT *lprect,LPCSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Ext_ಪಠ್ಯ_ಹೊರಹೋಗು_W(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,UINT options,CONST RECT *lprect,LPCWSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Poly_ಪಠ್ಯ_ಹೊರಹೋಗು_A(HDC hdc,CONST POLYTEXTA *ppt,ಪೂರ್ಣಾಂಕ nstrings);
  WINGDIAPI WINBOOL WINAPI Poly_ಪಠ್ಯ_ಹೊರಹೋಗು_W(HDC hdc,CONST POLYTEXTW *ppt,ಪೂರ್ಣಾಂಕ nstrings);
  WINGDIAPI HRGN WINAPI CreatePolygonRgn(CONST ಬಿಂದು_3 *pptl,ಪೂರ್ಣಾಂಕ c_ಬಿಂದು,ಪೂರ್ಣಾಂಕ i_ಬಹುಲಕ);
  WINGDIAPI WINBOOL WINAPI DPtoLP(HDC hdc,LPPOINT lppt,ಪೂರ್ಣಾಂಕ c);
  WINGDIAPI WINBOOL WINAPI LPtoDP(HDC hdc,LPPOINT lppt,ಪೂರ್ಣಾಂಕ c);
  WINGDIAPI WINBOOL WINAPI Polygon(HDC hdc,CONST ಬಿಂದು_3 *apt,ಪೂರ್ಣಾಂಕ cpt);
  WINGDIAPI WINBOOL WINAPI Polyline(HDC hdc,CONST ಬಿಂದು_3 *apt,ಪೂರ್ಣಾಂಕ cpt);
  WINGDIAPI WINBOOL WINAPI PolyBezier(HDC hdc,CONST ಬಿಂದು_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Poly_Bezier_ಗಮ್ಯ(HDC hdc,CONST ಬಿಂದು_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Polyline_ಗಮ್ಯ(HDC hdc,CONST ಬಿಂದು_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI ಗಣ_Viewport_Ext_Ex(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI ಗಣ_Viewport_Org_Ex(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ಗಣ_ಕಿಟಕಿ_Ext_Ex(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI ಗಣ_ಕಿಟಕಿ_Org_Ex(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ಸ್ಥಾನಾಂತರ_Viewport_Org_Ex(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ಸ್ಥಾನಾಂತರ_ಕಿಟಕಿ_Org_Ex(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ScaleViewportExtEx(HDC hdc,ಪೂರ್ಣಾಂಕ xn,ಪೂರ್ಣಾಂಕ dx,ಪೂರ್ಣಾಂಕ yn,ಪೂರ್ಣಾಂಕ yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Scale_ಕಿಟಕಿ_Ext_Ex(HDC hdc,ಪೂರ್ಣಾಂಕ xn,ಪೂರ್ಣಾಂಕ xd,ಪೂರ್ಣಾಂಕ yn,ಪೂರ್ಣಾಂಕ yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI ಗಣ_Bitmap_Dimension_Ex(HBITMAP hbm,ಪೂರ್ಣಾಂಕ w,ಪೂರ್ಣಾಂಕ h,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI ಗಣ_Brush_Org_Ex(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPPOINT lppt);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಪಠ್ಯ_Face_A(HDC hdc,ಪೂರ್ಣಾಂಕ c,LPSTR lpName);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI Get_ಪಠ್ಯ_Face_W(HDC hdc,ಪೂರ್ಣಾಂಕ c,LPWSTR lpName);

#ವ್ಯಾಖ್ಯಾನಿಸು FONTMAPPER_MAX 10

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_KERNINGPAIR {
    ಶಬ್ದ_3 w_ಮೊದಲ;
    ಶಬ್ದ_3 w_ಎರಡನೇ;
    ಪೂರ್ಣಾಂಕ iKernAmount;
  } KERNINGPAIR,*LPKERNINGPAIR;

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Kerning_ಜೋಡಿಗಳು Get_Kerning_ಜೋಡಿಗಳು_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು Get_Kerning_ಜೋಡಿಗಳು Get_Kerning_ಜೋಡಿಗಳು_A
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI DWORD WINAPI Get_Kerning_ಜೋಡಿಗಳು_A(HDC hdc,DWORD n_ಜೋಡಿಗಳು,LPKERNINGPAIR lpKernPair);
  WINGDIAPI DWORD WINAPI Get_Kerning_ಜೋಡಿಗಳು_W(HDC hdc,DWORD n_ಜೋಡಿಗಳು,LPKERNINGPAIR lpKernPair);
  WINGDIAPI WINBOOL WINAPI GetDCOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI FixBrushOrgEx(HDC hdc,ಪೂರ್ಣಾಂಕ x,ಪೂರ್ಣಾಂಕ y,LPPOINT ptl);
  WINGDIAPI WINBOOL WINAPI UnrealizeObject(HGDIOBJ h);
  WINGDIAPI WINBOOL WINAPI GdiFlush();
  WINGDIAPI DWORD WINAPI Gdi_ಗಣ_Batch_ಎಲ್ಲೆ(DWORD dw);
  WINGDIAPI DWORD WINAPI Gdi_Get_Batch_ಎಲ್ಲೆ();

#ವ್ಯಾಖ್ಯಾನಿಸು ICM_OFF 1
#ವ್ಯಾಖ್ಯಾನಿಸು ICM_ON 2
#ವ್ಯಾಖ್ಯಾನಿಸು ICM_QUERY 3
#ವ್ಯಾಖ್ಯಾನಿಸು ICM_ಮುಗಿದ_OUTSIDEDC 4

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *ICMENUMPROCA)(LPSTR,LPARAM);
  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ಪೂರ್ಣಾಂಕ (CALLBACK *ICMENUMPROCW)(LPWSTR,LPARAM);

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು ICMENUMPROC ICMENUMPROCW
#ವ್ಯಾಖ್ಯಾನಿಸು EnumICMProfiles EnumICMProfilesW
#ವ್ಯಾಖ್ಯಾನಿಸು Update_ICMReg_ಕೀಲಿ Update_ICMReg_ಕೀಲಿ_W
#ವ್ಯಾಖ್ಯಾನಿಸು GetLogColorSpace GetLogColorSpaceW
#ವ್ಯಾಖ್ಯಾನಿಸು CreateColorSpace CreateColorSpaceW
#ವ್ಯಾಖ್ಯಾನಿಸು GetICMProfile GetICMProfileW
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ICMProfile ಗಣ_ICMProfile_W
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು ICMENUMPROC ICMENUMPROCA
#ವ್ಯಾಖ್ಯಾನಿಸು EnumICMProfiles EnumICMProfilesA
#ವ್ಯಾಖ್ಯಾನಿಸು Update_ICMReg_ಕೀಲಿ Update_ICMReg_ಕೀಲಿ_A
#ವ್ಯಾಖ್ಯಾನಿಸು GetLogColorSpace GetLogColorSpaceA
#ವ್ಯಾಖ್ಯಾನಿಸು CreateColorSpace CreateColorSpaceA
#ವ್ಯಾಖ್ಯಾನಿಸು GetICMProfile GetICMProfileA
#ವ್ಯಾಖ್ಯಾನಿಸು ಗಣ_ICMProfile ಗಣ_ICMProfile_A
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI ಗಣ_ICMMode(HDC hdc,ಪೂರ್ಣಾಂಕ ಬಹುಲಕ);
  WINGDIAPI WINBOOL WINAPI Check_Colors_ಒಳ_Gamut(HDC hdc,LPVOID lpRGBTriple,LPVOID dlp_ಬಫರ್,DWORD n_ಎಣಿಕೆ);
  WINGDIAPI HCOLORSPACE WINAPI GetColorSpace(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceA(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEA lp_ಬಫರ್,DWORD n_ಗಾತ್ರ);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceW(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEW lp_ಬಫರ್,DWORD n_ಗಾತ್ರ);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA lplcs);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW lplcs);
  WINGDIAPI HCOLORSPACE WINAPI ಗಣ_Color_Space(HDC hdc,HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI DeleteColorSpace(HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI GetICMProfileA(HDC hdc,LPDWORD p_Buf_ಗಾತ್ರ,LPSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI GetICMProfileW(HDC hdc,LPDWORD p_Buf_ಗಾತ್ರ,LPWSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI ಗಣ_ICMProfile_A(HDC hdc,LPSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI ಗಣ_ICMProfile_W(HDC hdc,LPWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI GetDeviceGammaRamp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI ಗಣ_Device_Gamma_Ramp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI Color_ಹೊಂದಿಕೆ_ಗಮ್ಯ_ಗುರಿ(HDC hdc,HDC hdc_ಗುರಿ,DWORD action);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI EnumICMProfilesA(HDC hdc,ICMENUMPROCA proc,LPARAM param);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI EnumICMProfilesW(HDC hdc,ICMENUMPROCW proc,LPARAM param);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_ಕೀಲಿ_A(DWORD reserved,LPSTR lpszCMID,LPSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_ಕೀಲಿ_W(DWORD reserved,LPWSTR lpszCMID,LPWSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI ColorCorrectPalette(HDC hdc,HPALETTE hPal,DWORD de_ಮೊದಲ,DWORD ಅಂಕೆ);

#ವ್ಯಾಖ್ಯಾನಿತವಾಗದಿದ್ದರೆ NOMETAFILE

#ವ್ಯಾಖ್ಯಾನಿಸು ENHMETA_SIGNATURE 0x464D4520
#ವ್ಯಾಖ್ಯಾನಿಸು ENHMETA_STOCK_OBJECT 0x80000000

#ವ್ಯಾಖ್ಯಾನಿಸು EMR_ಶೀರ್ಷಿಕೆ 1
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYBEZIER 2
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYGON 3
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYLINE 4
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYBEZIERTO 5
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYLINETO 6
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYPOLYLINE 7
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYPOLYGON 8
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETWINDOWEXTEX 9
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETWINDOWORGEX 10
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETVIEWPORTEXTEX 11
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETVIEWPORTORGEX 12
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETBRUSHORGEX 13
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_EOF 14
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETPIXELV 15
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETMAPPERFLAGS 16
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETMAPMODE 17
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETBKMODE 18
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETPOLYFILLMODE 19
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETROP2 20
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETSTRETCHBLTMODE 21
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETTEXTALIGN 22
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETCOLORADJUSTMENT 23
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETTEXTCOLOR 24
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETBKCOLOR 25
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_OFFSETCLIPRGN 26
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_MOVETOEX 27
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETMETARGN 28
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_EXCLUDECLIPRECT 29
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_INTERSECTCLIPRECT 30
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SCALEVIEWPORTEXTEX 31
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SCALEWINDOWEXTEX 32
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SAVEDC 33
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESTOREDC 34
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETWORLDTRANSFORM 35
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_MODIFYWORLDTRANSFORM 36
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SELECTOBJECT 37
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_CREATEPEN 38
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_CREATEBRUSHINDIRECT 39
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_DELETEOBJECT 40
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_ANGLEARC 41
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_ELLIPSE 42
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RECTANGLE 43
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_ROUNDRECT 44
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_ARC 45
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_CHORD 46
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_PIE 47
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SELECTPALETTE 48
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_CREATEPALETTE 49
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETPALETTEENTRIES 50
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESIZEPALETTE 51
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_REALIZEPALETTE 52
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_EXTFLOODFILL 53
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_LINETO 54
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_ARCTO 55
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYDRAW 56
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETARCDIRECTION 57
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETMITERLIMIT 58
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_BEGINPATH 59
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_ENDPATH 60
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_CLOSEFIGURE 61
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_FILLPATH 62
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_STROKEANDFILLPATH 63
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_STROKEPATH 64
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_FLATTENPATH 65
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_WIDENPATH 66
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SELECTCLIPPATH 67
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_ABORTPATH 68

#ವ್ಯಾಖ್ಯಾನಿಸು EMR_GDICOMMENT 70
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_FILLRGN 71
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_FRAMERGN 72
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_INVERTRGN 73
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_PAINTRGN 74
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_EXTSELECTCLIPRGN 75
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_BITBLT 76
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_STRETCHBLT 77
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_MASKBLT 78
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_PLGBLT 79
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETDIBITSTODEVICE 80
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_STRETCHDIBITS 81
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_EXTCREATEFONTINDIRECTW 82
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_EXTTEXTOUTA 83
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_EXTTEXTOUTW 84
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYBEZIER16 85
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYGON16 86
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYLINE16 87
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYBEZIERTO16 88
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYLINETO16 89
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYPOLYLINE16 90
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYPOLYGON16 91
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYDRAW16 92
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_CREATEMONOBRUSH 93
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_CREATEDIBPATTERNBRUSHPT 94
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_EXTCREATEPEN 95
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYTEXTOUTA 96
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_POLYTEXTOUTW 97

#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETICMMODE 98
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_CREATECOLORSPACE 99
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETCOLORSPACE 100
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_DELETECOLORSPACE 101
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_GLSRECORD 102
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_GLSBOUNDEDRECORD 103
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_PIXELFORMAT 104
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESERVED_105 105
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESERVED_106 106
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESERVED_107 107
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESERVED_108 108
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESERVED_109 109
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESERVED_110 110
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_COLORCORRECTPALETTE 111
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETICMPROFILEA 112
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETICMPROFILEW 113
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_ALPHABLEND 114
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_SETLAYOUT 115
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_TRANSPARENTBLT 116
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESERVED_117 117
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_GRADIENTFILL 118
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESERVED_119 119
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_RESERVED_120 120
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_COLORMATCHTOTARGETW 121
#ವ್ಯಾಖ್ಯಾನಿಸು EMR_CREATECOLORSPACEW 122

#ವ್ಯಾಖ್ಯಾನಿಸು EMR_MIN 1

#ವ್ಯಾಖ್ಯಾನಿಸು EMR_MAX 122

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMR {
    DWORD iType;
    DWORD n_ಗಾತ್ರ;
  } EMR,*PEMR;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRTEXT {
    POINTL ptlReference;
    DWORD nChars;
    DWORD offString;
    DWORD fOptions;
    RECTL rcl;
    DWORD offDx;
  } EMRTEXT,*PEMRTEXT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_ABORTPATH {
    EMR emr;
  } EMRABORTPATH,*PEMRABORTPATH,EMRBEGINPATH,*PEMRBEGINPATH,EMRENDPATH,*PEMRENDPATH,EMRCLOSEFIGURE,*PEMRCLOSEFIGURE,EMRFLATTENPATH,*PEMRFLATTENPATH,EMRWIDENPATH,*PEMRWIDENPATH,EMRSETMETARGN,*PEMRSETMETARGN,EMRSAVEDC,*PEMRSAVEDC,EMRREALIZEPALETTE,*PEMRREALIZEPALETTE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSELECTCLIPPATH {
    EMR emr;
    DWORD i_ಬಹುಲಕ;
  } EMRSELECTCLIPPATH,*PEMRSELECTCLIPPATH,EMRSETBKMODE,*PEMRSETBKMODE,EMRSETMAPMODE,*PEMRSETMAPMODE,EMRSETLAYOUT,*PEMRSETLAYOUT,
    EMRSETPOLYFILLMODE,*PEMRSETPOLYFILLMODE,EMRSETROP2,*PEMRSETROP2,EMRSETSTRETCHBLTMODE,*PEMRSETSTRETCHBLTMODE,EMRSETICMMODE,
    *PEMRSETICMMODE,EMRSETTEXTALIGN,*PEMRSETTEXTALIGN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETMITERLIMIT {
    EMR emr;
    FLOAT e_Miter_ಎಲ್ಲೆ;
  } EMRSETMITERLIMIT,*PEMRSETMITERLIMIT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRRESTOREDC {
    EMR emr;
    LONG iRelative;
  } EMRRESTOREDC,*PEMRRESTOREDC;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETARCDIRECTION {
    EMR emr;
    DWORD iArcDirection;

  } EMRSETARCDIRECTION,*PEMRSETARCDIRECTION;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETMAPPERFLAGS {
    EMR emr;
    DWORD dwFlags;
  } EMRSETMAPPERFLAGS,*PEMRSETMAPPERFLAGS;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETTEXTCOLOR {
    EMR emr;
    COLORREF crColor;
  } EMRSETBKCOLOR,*PEMRSETBKCOLOR,EMRSETTEXTCOLOR,*PEMRSETTEXTCOLOR;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSELECTOBJECT {
    EMR emr;
    DWORD ihObject;
  } EMRSELECTOBJECT,*PEMRSELECTOBJECT,EMRDELETEOBJECT,*PEMRDELETEOBJECT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSELECTPALETTE {
    EMR emr;
    DWORD ihPal;
  } EMRSELECTPALETTE,*PEMRSELECTPALETTE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRRESIZEPALETTE {
    EMR emr;
    DWORD ihPal;
    DWORD cEntries;
  } EMRRESIZEPALETTE,*PEMRRESIZEPALETTE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETPALETTEENTRIES {
    EMR emr;
    DWORD ihPal;
    DWORD i_ಆರಂಭ;
    DWORD cEntries;
    PALETTEENTRY aPalEntries[1];
  } EMRSETPALETTEENTRIES,*PEMRSETPALETTEENTRIES;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETCOLORADJUSTMENT {
    EMR emr;
    COLORADJUSTMENT ColorAdjustment;
  } EMRSETCOLORADJUSTMENT,*PEMRSETCOLORADJUSTMENT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRGDICOMMENT {
    EMR emr;
    DWORD cb_ದತ್ತಾಂಶ;
    BYTE ದತ್ತಾಂಶ_3[1];
  } EMRGDICOMMENT,*PEMRGDICOMMENT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMREOF {
    EMR emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD n_ಗಾತ್ರ_ಕೊನೆಯ;
  } EMREOF,*PEMREOF;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRLINETO {
    EMR emr;
    POINTL ptl;
  } EMRLINETO,*PEMRLINETO,EMRMOVETOEX,*PEMRMOVETOEX;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMROFFSETCLIPRGN {
    EMR emr;
    POINTL ptl_ಸ್ಥಾನಾಂತರ;
  } EMROFFSETCLIPRGN,*PEMROFFSETCLIPRGN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRFILLPATH {
    EMR emr;
    RECTL rclBounds;
  } EMRFILLPATH,*PEMRFILLPATH,EMRSTROKEANDFILLPATH,*PEMRSTROKEANDFILLPATH,EMRSTROKEPATH,*PEMRSTROKEPATH;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMREXCLUDECLIPRECT {
    EMR emr;
    RECTL rclClip;
  } EMREXCLUDECLIPRECT,*PEMREXCLUDECLIPRECT,EMRINTERSECTCLIPRECT,*PEMRINTERSECTCLIPRECT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETVIEWPORTORGEX {
    EMR emr;
    POINTL ptlOrigin;
  } EMRSETVIEWPORTORGEX,*PEMRSETVIEWPORTORGEX,EMRSETWINDOWORGEX,*PEMRSETWINDOWORGEX,EMRSETBRUSHORGEX,*PEMRSETBRUSHORGEX;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETVIEWPORTEXTEX {
    EMR emr;
    SIZEL szlExtent;
  } EMRSETVIEWPORTEXTEX,*PEMRSETVIEWPORTEXTEX,EMRSETWINDOWEXTEX,*PEMRSETWINDOWEXTEX;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSCALEVIEWPORTEXTEX {
    EMR emr;
    LONG x_ಅಂಕೆ;
    LONG xDenom;
    LONG y_ಅಂಕೆ;
    LONG yDenom;
  } EMRSCALEVIEWPORTEXTEX,*PEMRSCALEVIEWPORTEXTEX,EMRSCALEWINDOWEXTEX,*PEMRSCALEWINDOWEXTEX;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
  } EMRSETWORLDTRANSFORM,*PEMRSETWORLDTRANSFORM;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRMODIFYWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
    DWORD i_ಬಹುಲಕ;
  } EMRMODIFYWORLDTRANSFORM,*PEMRMODIFYWORLDTRANSFORM;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETPIXELV {
    EMR emr;
    POINTL ptlPixel;
    COLORREF crColor;
  } EMRSETPIXELV,*PEMRSETPIXELV;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMREXTFLOODFILL {
    EMR emr;
    POINTL ptl_ಆರಂಭ;
    COLORREF crColor;
    DWORD i_ಬಹುಲಕ;
  } EMREXTFLOODFILL,*PEMREXTFLOODFILL;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRELLIPSE {
    EMR emr;
    RECTL rclBox;
  } EMRELLIPSE,*PEMRELLIPSE,EMRRECTANGLE,*PEMRRECTANGLE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRROUNDRECT {
    EMR emr;
    RECTL rclBox;
    SIZEL szl_ಮೂಲೆ;
  } EMRROUNDRECT,*PEMRROUNDRECT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRARC {
    EMR emr;
    RECTL rclBox;
    POINTL ptl_ಆರಂಭ;
    POINTL ptl_ಕೊನೆ;
  } EMRARC,*PEMRARC,EMRARCTO,*PEMRARCTO,EMRCHORD,*PEMRCHORD,EMRPIE,*PEMRPIE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRANGLEARC {
    EMR emr;
    POINTL ptlCenter;
    DWORD nRadius;
    FLOAT e_ಆರಂಭ_Angle;
    FLOAT eSweepAngle;
  } EMRANGLEARC,*PEMRANGLEARC;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
  } EMRPOLYLINE,*PEMRPOLYLINE,EMRPOLYBEZIER,*PEMRPOLYBEZIER,EMRPOLYGON,*PEMRPOLYGON,EMRPOLYBEZIERTO,*PEMRPOLYBEZIERTO,EMRPOLYLINETO,*PEMRPOLYLINETO;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
  } EMRPOLYLINE16,*PEMRPOLYLINE16,EMRPOLYBEZIER16,*PEMRPOLYBEZIER16,EMRPOLYGON16,*PEMRPOLYGON16,EMRPOLYBEZIERTO16,*PEMRPOLYBEZIERTO16,EMRPOLYLINETO16,*PEMRPOLYLINETO16;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRPOLYDRAW {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW,*PEMRPOLYDRAW;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRPOLYDRAW16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW16,*PEMRPOLYDRAW16;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRPOLYPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cptl;
    DWORD aPolyCounts[1];
    POINTL aptl[1];
  } EMRPOLYPOLYLINE,*PEMRPOLYPOLYLINE,EMRPOLYPOLYGON,*PEMRPOLYPOLYGON;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRPOLYPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cpts;
    DWORD aPolyCounts[1];
    POINTS apts[1];
  } EMRPOLYPOLYLINE16,*PEMRPOLYPOLYLINE16,EMRPOLYPOLYGON16,*PEMRPOLYPOLYGON16;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRINVERTRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_ದತ್ತಾಂಶ;
    BYTE Rgn_ದತ್ತಾಂಶ[1];
  } EMRINVERTRGN,*PEMRINVERTRGN,EMRPAINTRGN,*PEMRPAINTRGN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRFILLRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_ದತ್ತಾಂಶ;
    DWORD ihBrush;
    BYTE Rgn_ದತ್ತಾಂಶ[1];
  } EMRFILLRGN,*PEMRFILLRGN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRFRAMERGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_ದತ್ತಾಂಶ;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE Rgn_ದತ್ತಾಂಶ[1];
  } EMRFRAMERGN,*PEMRFRAMERGN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMREXTSELECTCLIPRGN {
    EMR emr;
    DWORD cb_Rgn_ದತ್ತಾಂಶ;
    DWORD i_ಬಹುಲಕ;
    BYTE Rgn_ದತ್ತಾಂಶ[1];
  } EMREXTSELECTCLIPRGN,*PEMREXTSELECTCLIPRGN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMREXTTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_ಬಹುಲಕ;
    FLOAT exScale;
    FLOAT eyScale;
    EMRTEXT emrtext;
  } EMREXTTEXTOUTA,*PEMREXTTEXTOUTA,EMREXTTEXTOUTW,*PEMREXTTEXTOUTW;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRPOLYTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_ಬಹುಲಕ;
    FLOAT exScale;
    FLOAT eyScale;
    LONG c_ಅಕ್ಷರಸರಣಿಗಳು;
    EMRTEXT aemrtext[1];
  } EMRPOLYTEXTOUTA,*PEMRPOLYTEXTOUTA,EMRPOLYTEXTOUTW,*PEMRPOLYTEXTOUTW;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRBITBLT {
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
    DWORD off_ಬಿಟ್ಟುಗಳು_Src;
    DWORD cb_ಬಿಟ್ಟುಗಳು_Src;
  } EMRBITBLT,*PEMRBITBLT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSTRETCHBLT {
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
    DWORD off_ಬಿಟ್ಟುಗಳು_Src;
    DWORD cb_ಬಿಟ್ಟುಗಳು_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRSTRETCHBLT,*PEMRSTRETCHBLT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRMASKBLT {
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
    DWORD off_ಬಿಟ್ಟುಗಳು_Src;
    DWORD cb_ಬಿಟ್ಟುಗಳು_Src;
    LONG x_ಮುಖವಾಡ;
    LONG y_ಮುಖವಾಡ;
    DWORD i_Usage_ಮುಖವಾಡ;
    DWORD off_Bmi_ಮುಖವಾಡ;
    DWORD cb_Bmi_ಮುಖವಾಡ;
    DWORD off_ಬಿಟ್ಟುಗಳು_ಮುಖವಾಡ;
    DWORD cb_ಬಿಟ್ಟುಗಳು_ಮುಖವಾಡ;
  } EMRMASKBLT,*PEMRMASKBLT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRPLGBLT {
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
    DWORD off_ಬಿಟ್ಟುಗಳು_Src;
    DWORD cb_ಬಿಟ್ಟುಗಳು_Src;
    LONG x_ಮುಖವಾಡ;
    LONG y_ಮುಖವಾಡ;
    DWORD i_Usage_ಮುಖವಾಡ;
    DWORD off_Bmi_ಮುಖವಾಡ;
    DWORD cb_Bmi_ಮುಖವಾಡ;
    DWORD off_ಬಿಟ್ಟುಗಳು_ಮುಖವಾಡ;
    DWORD cb_ಬಿಟ್ಟುಗಳು_ಮುಖವಾಡ;
  } EMRPLGBLT,*PEMRPLGBLT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETDIBITSTODEVICE {
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
    DWORD off_ಬಿಟ್ಟುಗಳು_Src;
    DWORD cb_ಬಿಟ್ಟುಗಳು_Src;
    DWORD iUsageSrc;
    DWORD i_ಆರಂಭ_ಪರಿಶೀಲನೆ;
    DWORD cScans;
  } EMRSETDIBITSTODEVICE,*PEMRSETDIBITSTODEVICE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSTRETCHDIBITS {
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
    DWORD off_ಬಿಟ್ಟುಗಳು_Src;
    DWORD cb_ಬಿಟ್ಟುಗಳು_Src;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG cxDest;
    LONG cyDest;
  } EMRSTRETCHDIBITS,*PEMRSTRETCHDIBITS;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMREXTCREATEFONTINDIRECTW {
    EMR emr;
    DWORD ihFont;
    EXTLOGFONTW elfw;
  } EMREXTCREATEFONTINDIRECTW,*PEMREXTCREATEFONTINDIRECTW;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRCREATEPALETTE {
    EMR emr;
    DWORD ihPal;
    LOGPALETTE lgpl;
  } EMRCREATEPALETTE,*PEMRCREATEPALETTE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRCREATEPEN {
    EMR emr;
    DWORD ihPen;
    LOGPEN lopn;
  } EMRCREATEPEN,*PEMRCREATEPEN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMREXTCREATEPEN {
    EMR emr;
    DWORD ihPen;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_ಬಿಟ್ಟುಗಳು;
    DWORD cb_ಬಿಟ್ಟುಗಳು;
    EXTLOGPEN elp;
  } EMREXTCREATEPEN,*PEMREXTCREATEPEN;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRCREATEBRUSHINDIRECT {
    EMR emr;
    DWORD ihBrush;
    LOGBRUSH32 lb;
  } EMRCREATEBRUSHINDIRECT,*PEMRCREATEBRUSHINDIRECT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRCREATEMONOBRUSH {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_ಬಿಟ್ಟುಗಳು;
    DWORD cb_ಬಿಟ್ಟುಗಳು;
  } EMRCREATEMONOBRUSH,*PEMRCREATEMONOBRUSH;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRCREATEDIBPATTERNBRUSHPT {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_ಬಿಟ್ಟುಗಳು;
    DWORD cb_ಬಿಟ್ಟುಗಳು;
  } EMRCREATEDIBPATTERNBRUSHPT,*PEMRCREATEDIBPATTERNBRUSHPT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRFORMAT {
    DWORD dSignature;
    DWORD n_ಆವೃತ್ತಿ;
    DWORD cb_ದತ್ತಾಂಶ;
    DWORD off_ದತ್ತಾಂಶ;
  } EMRFORMAT,*PEMRFORMAT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRGLSRECORD {
    EMR emr;
    DWORD cb_ದತ್ತಾಂಶ;
    BYTE ದತ್ತಾಂಶ_3[1];
  } EMRGLSRECORD,*PEMRGLSRECORD;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRGLSBOUNDEDRECORD {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_ದತ್ತಾಂಶ;
    BYTE ದತ್ತಾಂಶ_3[1];
  } EMRGLSBOUNDEDRECORD,*PEMRGLSBOUNDEDRECORD;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRPIXELFORMAT {
    EMR emr;
    PIXELFORMATDESCRIPTOR pfd;
  } EMRPIXELFORMAT,*PEMRPIXELFORMAT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRCREATECOLORSPACE {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEA lcs;
  } EMRCREATECOLORSPACE,*PEMRCREATECOLORSPACE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETCOLORSPACE {
    EMR emr;
    DWORD ihCS;
  } EMRSETCOLORSPACE,*PEMRSETCOLORSPACE,EMRSELECTCOLORSPACE,*PEMRSELECTCOLORSPACE,EMRDELETECOLORSPACE,*PEMRDELETECOLORSPACE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMREXTESCAPE {
    EMR emr;
    INT iEscape;
    INT cb_Esc_ದತ್ತಾಂಶ;
    BYTE Esc_ದತ್ತಾಂಶ[1];
  } EMREXTESCAPE,*PEMREXTESCAPE,EMRDRAWESCAPE,*PEMRDRAWESCAPE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRNAMEDESCAPE {
    EMR emr;
    INT iEscape;
    INT cbDriver;
    INT cb_Esc_ದತ್ತಾಂಶ;
    BYTE Esc_ದತ್ತಾಂಶ[1];
  } EMRNAMEDESCAPE,*PEMRNAMEDESCAPE;

#ವ್ಯಾಖ್ಯಾನಿಸು SETICMPROFILE_EMBEDED 0x00000001

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRSETICMPROFILE {
    EMR emr;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_ದತ್ತಾಂಶ;
    BYTE ದತ್ತಾಂಶ_3[1];
  } EMRSETICMPROFILE,*PEMRSETICMPROFILE,EMRSETICMPROFILEA,*PEMRSETICMPROFILEA,EMRSETICMPROFILEW,*PEMRSETICMPROFILEW;

#ವ್ಯಾಖ್ಯಾನಿಸು CREATECOLORSPACE_EMBEDED 0x00000001

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRCREATECOLORSPACEW {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEW lcs;
    DWORD dwFlags;
    DWORD cb_ದತ್ತಾಂಶ;
    BYTE ದತ್ತಾಂಶ_3[1];
  } EMRCREATECOLORSPACEW,*PEMRCREATECOLORSPACEW;

#ವ್ಯಾಖ್ಯಾನಿಸು COLORMATCHTOTARGET_EMBEDED 0x00000001

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_COLORMATCHTOTARGET {
    EMR emr;
    DWORD dwAction;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_ದತ್ತಾಂಶ;
    BYTE ದತ್ತಾಂಶ_3[1];
  } EMRCOLORMATCHTOTARGET,*PEMRCOLORMATCHTOTARGET;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_COLORCORRECTPALETTE {
    EMR emr;
    DWORD ihPalette;
    DWORD n_ಮೊದಲ_ನಮೂದು;
    DWORD nPalEntries;
    DWORD nReserved;
  } EMRCOLORCORRECTPALETTE,*PEMRCOLORCORRECTPALETTE;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRALPHABLEND {
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
    DWORD off_ಬಿಟ್ಟುಗಳು_Src;
    DWORD cb_ಬಿಟ್ಟುಗಳು_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRALPHABLEND,*PEMRALPHABLEND;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRGRADIENTFILL {
    EMR emr;
    RECTL rclBounds;
    DWORD nVer;
    DWORD nTri;
    ULONG ul_ಬಹುಲಕ;
    TRIVERTEX Ver[1];
  } EMRGRADIENTFILL,*PEMRGRADIENTFILL;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_EMRTRANSPARENTBLT {
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
    DWORD off_ಬಿಟ್ಟುಗಳು_Src;
    DWORD cb_ಬಿಟ್ಟುಗಳು_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRTRANSPARENTBLT,*PEMRTRANSPARENTBLT;

#ವ್ಯಾಖ್ಯಾನಿಸು GDICOMMENT_IDENTIFIER 0x43494447
#ವ್ಯಾಖ್ಯಾನಿಸು GDICOMMENT_WINDOWS_METAFILE 0x80000001
#ವ್ಯಾಖ್ಯಾನಿಸು GDICOMMENT_BEGINGROUP 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು GDICOMMENT_ENDGROUP 0x00000003
#ವ್ಯಾಖ್ಯಾನಿಸು GDICOMMENT_MULTIFORMATS 0x40000004
#ವ್ಯಾಖ್ಯಾನಿಸು EPS_SIGNATURE 0x46535045
#ವ್ಯಾಖ್ಯಾನಿಸು GDICOMMENT_UNICODE_STRING 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು GDICOMMENT_UNICODE_ಕೊನೆ 0x00000080
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು wglUseFontBitmaps wglUseFontBitmapsW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು wglUseFontBitmaps wglUseFontBitmapsA
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI WINBOOL WINAPI wglCopyContext(HGLRC,HGLRC,UINT);
  WINGDIAPI HGLRC WINAPI wglCreateContext(HDC);
  WINGDIAPI HGLRC WINAPI wglCreateLayerContext(HDC,ಪೂರ್ಣಾಂಕ);
  WINGDIAPI WINBOOL WINAPI wglDeleteContext(HGLRC);
  WINGDIAPI HGLRC WINAPI wglGetCurrentContext(VOID);
  WINGDIAPI HDC WINAPI wglGetCurrentDC(VOID);
  WINGDIAPI PROC WINAPI wgl_Get_Proc_ವಿಳಾಸ(LPCSTR);
  WINGDIAPI WINBOOL WINAPI wglMakeCurrent(HDC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglShareLists(HGLRC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsA(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsW(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI ಅದಲುಬದಲು_Buffers(HDC);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _POINTFLOAT {
    FLOAT x;
    FLOAT y;
  } POINTFLOAT,*PPOINTFLOAT;

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _GLYPHMETRICSFLOAT {
    FLOAT gmfBlackBoxX;
    FLOAT gmfBlackBoxY;
    POINTFLOAT gmfptGlyphOrigin;
    FLOAT gmfCellIncX;
    FLOAT gmfCellIncY;
  } GLYPHMETRICSFLOAT,*PGLYPHMETRICSFLOAT,*LPGLYPHMETRICSFLOAT;

#ವ್ಯಾಖ್ಯಾನಿಸು WGL_FONT_ಸಾಲುಗಳು 0
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_FONT_POLYGONS 1

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ UNICODE
#ವ್ಯಾಖ್ಯಾನಿಸು wglUseFontOutlines wglUseFontOutlinesW
#ಇಲ್ಲದಿದ್ದರೆ
#ವ್ಯಾಖ್ಯಾನಿಸು wglUseFontOutlines wglUseFontOutlinesA
#ಆದರೆ_ಅಂತ್ಯ

  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesA(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,ಪೂರ್ಣಾಂಕ,LPGLYPHMETRICSFLOAT);
  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesW(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,ಪೂರ್ಣಾಂಕ,LPGLYPHMETRICSFLOAT);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ ಟ್ಯಾಗ್_LAYERPLANEDESCRIPTOR {
    ಶಬ್ದ_3 n_ಗಾತ್ರ;
    ಶಬ್ದ_3 n_ಆವೃತ್ತಿ;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_ಬಿಟ್ಟುಗಳು;
    BYTE c_Red_ಬಿಟ್ಟುಗಳು;
    BYTE c_Red_ಸರಿಸು;
    BYTE c_Green_ಬಿಟ್ಟುಗಳು;
    BYTE c_Green_ಸರಿಸು;
    BYTE c_Blue_ಬಿಟ್ಟುಗಳು;
    BYTE c_Blue_ಸರಿಸು;
    BYTE c_Alpha_ಬಿಟ್ಟುಗಳು;
    BYTE c_Alpha_ಸರಿಸು;
    BYTE c_Accum_ಬಿಟ್ಟುಗಳು;
    BYTE c_Accum_Red_ಬಿಟ್ಟುಗಳು;
    BYTE c_Accum_Green_ಬಿಟ್ಟುಗಳು;
    BYTE c_Accum_Blue_ಬಿಟ್ಟುಗಳು;
    BYTE c_Accum_Alpha_ಬಿಟ್ಟುಗಳು;
    BYTE c_ಆಳ_ಬಿಟ್ಟುಗಳು;
    BYTE c_Stencil_ಬಿಟ್ಟುಗಳು;
    BYTE cAuxBuffers;
    BYTE iLayerPlane;
    BYTE bReserved;
    COLORREF crTransparent;
  } LAYERPLANEDESCRIPTOR,*PLAYERPLANEDESCRIPTOR,*LPLAYERPLANEDESCRIPTOR;

#ವ್ಯಾಖ್ಯಾನಿಸು LPD_DOUBLEBUFFER 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_STEREO 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_SUPPORT_GDI 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_SUPPORT_OPENGL 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_SHARE_ಆಳ 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_SHARE_STENCIL 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_SHARE_ACCUM 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_ಅದಲುಬದಲು_EXCHANGE 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_ಅದಲುಬದಲು_COPY 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_TRANSPARENT 0x00001000

#ವ್ಯಾಖ್ಯಾನಿಸು LPD_TYPE_RGBA 0
#ವ್ಯಾಖ್ಯಾನಿಸು LPD_TYPE_COLORINDEX 1

#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_MAIN_PLANE 0x00000001
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY1 0x00000002
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY2 0x00000004
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY3 0x00000008
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY4 0x00000010
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY5 0x00000020
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY6 0x00000040
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY7 0x00000080
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY8 0x00000100
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY9 0x00000200
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY10 0x00000400
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY11 0x00000800
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY12 0x00001000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY13 0x00002000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY14 0x00004000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_OVERLAY15 0x00008000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY1 0x00010000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY2 0x00020000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY3 0x00040000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY4 0x00080000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY5 0x00100000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY6 0x00200000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY7 0x00400000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY8 0x00800000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY9 0x01000000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY10 0x02000000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY11 0x04000000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY12 0x08000000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY13 0x10000000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY14 0x20000000
#ವ್ಯಾಖ್ಯಾನಿಸು WGL_ಅದಲುಬದಲು_UNDERLAY15 0x40000000

  WINGDIAPI WINBOOL WINAPI wglDescribeLayerPlane(HDC,ಪೂರ್ಣಾಂಕ,ಪೂರ್ಣಾಂಕ,UINT,LPLAYERPLANEDESCRIPTOR);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI wgl_ಗಣ_Layer_Palette_Entries(HDC,ಪೂರ್ಣಾಂಕ,ಪೂರ್ಣಾಂಕ,ಪೂರ್ಣಾಂಕ,CONST COLORREF *);
  WINGDIAPI ಪೂರ್ಣಾಂಕ WINAPI wglGetLayerPaletteEntries(HDC,ಪೂರ್ಣಾಂಕ,ಪೂರ್ಣಾಂಕ,ಪೂರ್ಣಾಂಕ,COLORREF *);
  WINGDIAPI WINBOOL WINAPI wglRealizeLayerPalette(HDC,ಪೂರ್ಣಾಂಕ,WINBOOL);
  WINGDIAPI WINBOOL WINAPI wgl_ಅದಲುಬದಲು_Layer_Buffers(HDC,UINT);

  ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ _WGLSWAP {
    HDC hdc;
    UINT uiFlags;
  } WGLSWAP,*PWGLSWAP,*LPWGLSWAP;

#ವ್ಯಾಖ್ಯಾನಿಸು WGL_SWAPMULTIPLE_MAX 16

  WINGDIAPI DWORD WINAPI wgl_ಅದಲುಬದಲು_ಅಪವರ್ತ್ಯ_Buffers(UINT,CONST WGLSWAP *);
#ಆದರೆ_ಅಂತ್ಯ

#ವ್ಯಾಖ್ಯಾನಿತವಾದರೆ __cplusplus
}
#ಆದರೆ_ಅಂತ್ಯ
#ಆದರೆ_ಅಂತ್ಯ
