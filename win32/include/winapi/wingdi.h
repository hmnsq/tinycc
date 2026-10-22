/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _WINGDI_
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _WINGDI_

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINGDIAPI DECLSPEC_IMPORT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINSPOOLAPI DECLSPEC_IMPORT

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
ਬਾਹਰੀ "C" {
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ WINVER
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINVER 0x0502
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOGDI
#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NORASTEROPS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_BLACK 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_NOTMERGEPEN 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_MASKNOTPEN 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_NOTCOPYPEN 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_MASKPENNOT 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_NOT 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_XORPEN 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_NOTMASKPEN 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_MASKPEN 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_NOTXORPEN 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_NOP 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_MERGENOTPEN 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_COPYPEN 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_MERGEPENNOT 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_MERGEPEN 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_WHITE 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R2_ਆਖਰੀ 16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SRCCOPY (DWORD)0x00CC0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SRCPAINT (DWORD)0x00EE0086
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SRCAND (DWORD)0x008800C6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SRCINVERT (DWORD)0x00660046
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SRCERASE (DWORD)0x00440328
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOTSRCCOPY (DWORD)0x00330008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOTSRCERASE (DWORD)0x001100A6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MERGECOPY (DWORD)0x00C000CA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MERGEPAINT (DWORD)0x00BB0226
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PATCOPY (DWORD)0x00F00021
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PATPAINT (DWORD)0x00FB0A09
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PATINVERT (DWORD)0x005A0049
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DSTINVERT (DWORD)0x00550009
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BLACKNESS (DWORD)0x00000042
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WHITENESS (DWORD)0x00FF0062
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NOMIRRORBITMAP (DWORD)0x80000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CAPTUREBLT (DWORD)0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKEROP4(fore,ਪਿੱਠ) (DWORD)((((ਪਿੱਠ) << 8) & 0xFF000000) | (fore))
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GDI_ERROR (0xFFFFFFFFL)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HGDI_ERROR (Long_ਮੰਜ਼ਿਲ_Handle(0xFFFFFFFFL))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ERROR 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NULLREGION 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIMPLEREGION 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COMPLEXREGION 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGN_ERROR ERROR

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGN_AND 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGN_OR 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGN_XOR 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGN_DIFF 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGN_COPY 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGN_MIN RGN_AND
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGN_MAX RGN_COPY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BLACKONWHITE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WHITEONBLACK 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLORONCOLOR 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HALFTONE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAXSTRETCHBLTMODE 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STRETCH_ANDSCANS BLACKONWHITE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STRETCH_ORSCANS WHITEONBLACK
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STRETCH_DELETESCANS COLORONCOLOR
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STRETCH_HALFTONE HALFTONE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALTERNATE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WINDING 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLYFILL_ਆਖਰੀ 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LAYOUT_RTL 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LAYOUT_BTT 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LAYOUT_VBH 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LAYOUT_ORIENTATIONMASK (LAYOUT_RTL | LAYOUT_BTT | LAYOUT_VBH)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LAYOUT_BITMAPORIENTATIONPRESERVED 0x00000008

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_NOUPDATECP 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_UPDATECP 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_ਖੱਬਾ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_ਸੱਜਾ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_CENTER 6

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_ਸਿਖਰ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_BOTTOM 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_BASELINE 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_RTLREADING 256
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TA_ਨਕਾਬ (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VTA_BASELINE TA_BASELINE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VTA_ਖੱਬਾ TA_BOTTOM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VTA_ਸੱਜਾ TA_ਸਿਖਰ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VTA_CENTER TA_CENTER
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VTA_BOTTOM TA_ਸੱਜਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VTA_ਸਿਖਰ TA_ਖੱਬਾ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETO_OPAQUE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETO_CLIPPED 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETO_GLYPH_ਸੂਚਕਾਂਕ 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETO_RTLREADING 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETO_NUMERICSLOCAL 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETO_NUMERICSLATIN 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETO_IGNORELANGUAGE 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ETO_PDY 0x2000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ASPECT_FILTERING 0x0001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCB_RESET 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCB_ACCUMULATE 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCB_DIRTY DCB_ACCUMULATE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCB_ਸੈੱਟ (DCB_RESET | DCB_ACCUMULATE)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCB_ENABLE 0x0004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCB_DISABLE 0x0008

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMETAFILE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETBKCOLOR 0x0201
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETBKMODE 0x0102
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETMAPMODE 0x0103
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETROP2 0x0104
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETRELABS 0x0105
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETPOLYFILLMODE 0x0106
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETSTRETCHBLTMODE 0x0107
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETTEXTCHAREXTRA 0x0108
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETTEXTCOLOR 0x0209
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETTEXTJUSTIFICATION 0x020A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETWINDOWORG 0x020B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETWINDOWEXT 0x020C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETVIEWPORTORG 0x020D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETVIEWPORTEXT 0x020E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_OFFSETWINDOWORG 0x020F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SCALEWINDOWEXT 0x0410
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_OFFSETVIEWPORTORG 0x0211
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SCALEVIEWPORTEXT 0x0412
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_LINETO 0x0213
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_MOVETO 0x0214
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_EXCLUDECLIPRECT 0x0415
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_INTERSECTCLIPRECT 0x0416
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_ARC 0x0817
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_ELLIPSE 0x0418
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_FLOODFILL 0x0419
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_PIE 0x081A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_RECTANGLE 0x041B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_ROUNDRECT 0x061C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_PATBLT 0x061D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SAVEDC 0x001E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETPIXEL 0x041F
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_OFFSETCLIPRGN 0x0220
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_TEXTOUT 0x0521
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_BITBLT 0x0922
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_STRETCHBLT 0x0B23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_POLYGON 0x0324
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_POLYLINE 0x0325
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_ESCAPE 0x0626
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_RESTOREDC 0x0127
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_FILLREGION 0x0228
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_FRAMEREGION 0x0429
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_INVERTREGION 0x012A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_PAINTREGION 0x012B
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SELECTCLIPREGION 0x012C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SELECTOBJECT 0x012D
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETTEXTALIGN 0x012E
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_CHORD 0x0830
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETMAPPERFLAGS 0x0231
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_EXTTEXTOUT 0x0a32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETDIBTODEV 0x0d33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SELECTPALETTE 0x0234
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_REALIZEPALETTE 0x0035
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_ANIMATEPALETTE 0x0436
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETPALENTRIES 0x0037
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_POLYPOLYGON 0x0538
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_RESIZEPALETTE 0x0139
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_DIBBITBLT 0x0940
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_DIBSTRETCHBLT 0x0b41
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_DIBCREATEPATTERNBRUSH 0x0142
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_STRETCHDIB 0x0f43
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_EXTFLOODFILL 0x0548
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_SETLAYOUT 0x0149
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_DELETEOBJECT 0x01f0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_CREATEPALETTE 0x00f7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_CREATEPATTERNBRUSH 0x01F9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_CREATEPENINDIRECT 0x02FA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_CREATEFONTINDIRECT 0x02FB
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_CREATEBRUSHINDIRECT 0x02FC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ META_CREATEREGION 0x06FF

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _DRAWPATRECT {
    ਬਿੰਦੂ_3 ptPosition;
    ਬਿੰਦੂ_3 pt_ਮਾਪ;
    ਸ਼ਬਦ_3 wStyle;
    ਸ਼ਬਦ_3 w_ਨਮੂਨਾ;
  } DRAWPATRECT,*PDRAWPATRECT;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NEWFRAME 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ABORTDOC 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NEXTBAND 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETCOLORTABLE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETCOLORTABLE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLUSHOUTPUT 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRAFTMODE 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUERYESCSUPPORT 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETABORTPROC 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STARTDOC 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENDDOC 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETPHYSPAGESIZE 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETPRINTINGOFFSET 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETSCALINGFACTOR 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MFCOMMENT 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETPENWIDTH 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETCOPYCOUNT 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SELECTPAPERSOURCE 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEVICEDATA 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PASSTHROUGH 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETTECHNOLGY 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETTECHNOLOGY 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETLINECAP 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETLINEJOIN 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETMITERLIMIT 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BANDINFO 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRAWPATTERNRECT 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETVECTORPENSIZE 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETVECTORBRUSHSIZE 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLEDUPLEX 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETSETPAPERBINS 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETSETPRINTORIENT 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUMPAPERBINS 31
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETDIBSCALING 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EPSPRINTING 33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENUMPAPERMETRICS 34
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETSETPAPERMETRICS 35
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POSTSCRIPT_ਅੰਕੜੇ 37
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POSTSCRIPT_IGNORE 38
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MOUSETRAILS 39
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETDEVICEUNITS 42

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETEXTENDEDTEXTMETRICS 256
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETEXTENTTABLE 257
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETPAIRKERNTABLE 258
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETTRACKKERNTABLE 259
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXTTEXTOUT 512
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETFACENAME 513
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOWNLOADFACE 514
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLERELATIVEWIDTHS 768
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENABLEPAIRKERNING 769
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETKERNTRACK 770
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETALLJUSTVALUES 771
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETCHARSET 772

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STRETCHBLT 2048
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ METAFILE_DRIVER 2049
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GETSETSCREENPARAMS 3072
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QUERYDIBSUPPORT 3073
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BEGIN_ਰਸਤਾ 4096
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIP_ਮੰਜ਼ਿਲ_ਰਸਤਾ 4097
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਿਰਾ_ਰਸਤਾ 4098
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EXT_DEVICE_CAPS 4099
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RESTORE_CTM 4100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SAVE_CTM 4101
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ARC_DIRECTION 4102
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_BACKGROUND_COLOR 4103
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_POLY_ਬਹੁਲਕ 4104
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_SCREEN_ANGLE 4105
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ਫੈਲਾਅ 4106
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRANSFORM_CTM 4107
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_CLIP_BOX 4108
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_BOUNDS 4109
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_MIRROR_ਬਹੁਲਕ 4110
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPENCHANNEL 4110
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DOWNLOADHEADER 4111
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLOSECHANNEL 4112
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POSTSCRIPT_PASSTHROUGH 4115
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCAPSULATED_POSTSCRIPT 4116

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POSTSCRIPT_IDENTIFY 4117
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POSTSCRIPT_INJECTION 4118

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHECKJPEGFORMAT 4119
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHECKPNGFORMAT 4120

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GET_PS_FEATURESETTING 4121

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SPCLPASSTHROUGH2 4568

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSIDENT_GDICENTRIC 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSIDENT_PSCENTRIC 1

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _PSINJECTDATA {
    DWORD ਅੰਕੜੇ_ਬਾਈਟਾਂ;
    ਸ਼ਬਦ_3 Injection_ਬਿੰਦੂ;
    ਸ਼ਬਦ_3 ਪੰਨਾ_ਸੰਖਿਆ;
  } PSINJECTDATA,*PPSINJECTDATA;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_BEGINSTREAM 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_PSADOBE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_PAGESATEND 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_ਪੰਨੇ 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_DOCNEEDEDRES 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_DOCSUPPLIEDRES 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_PAGEORDER 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_ORIENTATION 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_BOUNDINGBOX 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_DOCUMENTPROCESSCOLORS 10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_COMMENTS 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_BEGINDEFAULTS 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_ENDDEFAULTS 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_BEGINPROLOG 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_ENDPROLOG 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_BEGINSETUP 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_ENDSETUP 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_TRAILER 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_EOF 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_ENDSTREAM 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_DOCUMENTPROCESSCOLORSATEND 21

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_PAGENUMBER 100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_BEGINPAGESETUP 101
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_ENDPAGESETUP 102
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_PAGETRAILER 103
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_PLATECOLOR 104

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_SHOWPAGE 105
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_PAGEBBOX 106
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_ENDPAGECOMMENTS 107

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_VMSAVE 200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSINJECT_VMRESTORE 201

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FEATURESETTING_NUP 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FEATURESETTING_OUTPUT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FEATURESETTING_PSLEVEL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FEATURESETTING_CUSTPAPER 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FEATURESETTING_MIRROR 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FEATURESETTING_NEGATIVE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FEATURESETTING_PROTOCOL 6

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FEATURESETTING_ਨਿੱਜੀ_BEGIN 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FEATURESETTING_ਨਿੱਜੀ_ਸਿਰਾ 0x1FFF

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _PSFEATURE_OUTPUT {
    WINBOOL b_ਪੰਨਾ_Independent;
    WINBOOL b_ਸੈੱਟ_ਪੰਨਾ_Device;
  } PSFEATURE_OUTPUT,*PPSFEATURE_OUTPUT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _PSFEATURE_CUSTPAPER {
    LONG lOrientation;
    LONG l_ਚੌੜਾਈ;
    LONG l_ਉਚਾਈ;
    LONG l_ਚੌੜਾਈ_ਵਿੱਥ;
    LONG l_ਉਚਾਈ_ਵਿੱਥ;
  } PSFEATURE_CUSTPAPER,*PPSFEATURE_CUSTPAPER;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSPROTOCOL_ASCII 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSPROTOCOL_BCP 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSPROTOCOL_TBCP 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PSPROTOCOL_ਦੁਆਧਾਰੀ 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QDI_SETDIBITS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QDI_GETDIBITS 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QDI_DIBTOSCREEN 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ QDI_STRETCHDIB 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_NOTREPORTED 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_ERROR (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_APPABORT (-2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_USERABORT (-3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_OUTOFDISK (-4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SP_OUTOFMEMORY (-5)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PR_JOBSTATUS 0x0000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_PEN 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_BRUSH 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_DC 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_METADC 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_PAL 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_FONT 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_BITMAP 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_REGION 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_METAFILE 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_MEMDC 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_EXTPEN 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_ENHMETADC 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_ENHMETAFILE 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OBJ_COLORSPACE 14

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MWT_ਪਛਾਣ_ਤੱਤ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MWT_LEFTMULTIPLY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MWT_RIGHTMULTIPLY 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MWT_MIN MWT_ਪਛਾਣ_ਤੱਤ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MWT_MAX MWT_RIGHTMULTIPLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _XFORM_
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_XFORM {
    FLOAT eM11;
    FLOAT eM12;
    FLOAT eM21;
    FLOAT eM22;
    FLOAT eDx;
    FLOAT eDy;
  } XFORM,*PXFORM,*LPXFORM;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_BITMAP {
    LONG bmType;
    LONG bm_ਚੌੜਾਈ;
    LONG bm_ਉਚਾਈ;
    LONG bm_ਚੌੜਾਈ_ਬਾਈਟਾਂ;
    ਸ਼ਬਦ_3 bmPlanes;
    ਸ਼ਬਦ_3 bm_ਬਿੱਟ_Pixel;
    LPVOID bm_ਬਿੱਟ;
  } BITMAP,*PBITMAP,*NPBITMAP,*LPBITMAP;

#ਅਨ੍ਤਰ੍ਭਾਵ <pshpack1.h>
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RGBTRIPLE {
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
  } RGBTRIPLE;
#ਅਨ੍ਤਰ੍ਭਾਵ <poppack.h>

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_RGBQUAD {
    BYTE rgbBlue;
    BYTE rgbGreen;
    BYTE rgbRed;
    BYTE rgbReserved;
  } RGBQUAD;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ RGBQUAD *LPRGBQUAD;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_ENABLE 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_DISABLE 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CS_DELETE_TRANSFORM 0x00000003L

//!__TINYC__: #define LCS_SIGNATURE 'PSOC'
//!__TINYC__: #define LCS_sRGB 'sRGB'
//!__TINYC__: #define LCS_WINDOWS_COLOR_SPACE 'Win '

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONG LCSCSTYPE;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LCS_CALIBRATED_RGB 0x00000000L

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LONG LCSGAMUTMATCH;
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LCS_GM_BUSINESS 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LCS_GM_GRAPHICS 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LCS_GM_IMAGES 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LCS_GM_ABS_COLORIMETRIC 0x00000008L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CM_ਬਾਹਰਲਾ_ਦਾ_GAMUT 255
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CM_ਵਿੱਚ_GAMUT 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_ADDPROFILE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_DELETEPROFILE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_QUERYPROFILE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_SETDEFAULTPROFILE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_REGISTERICMATCHER 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_UNREGISTERICMATCHER 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_QUERYMATCH 7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetKValue(cmyk) ((BYTE)(cmyk))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetYValue(cmyk) ((BYTE)((cmyk)>> 8))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetMValue(cmyk) ((BYTE)((cmyk)>>16))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCValue(cmyk) ((BYTE)((cmyk)>>24))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CMYK(c,m,y,k) ((COLORREF)((((BYTE)(k)|((ਸ਼ਬਦ_3)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ FXPT16DOT16,*LPFXPT16DOT16;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਲੰਮਾ FXPT2DOT30,*LPFXPT2DOT30;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CIEXYZ {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
  } CIEXYZ;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CIEXYZ *LPCIEXYZ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ICEXYZTRIPLE {
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
  } CIEXYZTRIPLE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ CIEXYZTRIPLE *LPCIEXYZTRIPLE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LOGCOLORSPACEA {
    DWORD lcsSignature;
    DWORD lcs_ਸੰਸਕਰਣ;
    DWORD lcs_ਮਾਪ;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    CHAR lcsFilename[MAX_ਰਸਤਾ];
  } LOGCOLORSPACEA,*LPLOGCOLORSPACEA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LOGCOLORSPACEW {
    DWORD lcsSignature;
    DWORD lcs_ਸੰਸਕਰਣ;
    DWORD lcs_ਮਾਪ;
    LCSCSTYPE lcsCSType;
    LCSGAMUTMATCH lcsIntent;
    CIEXYZTRIPLE lcsEndpoints;
    DWORD lcsGammaRed;
    DWORD lcsGammaGreen;
    DWORD lcsGammaBlue;
    WCHAR lcsFilename[MAX_ਰਸਤਾ];
  } LOGCOLORSPACEW,*LPLOGCOLORSPACEW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LOGCOLORSPACEW LOGCOLORSPACE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPLOGCOLORSPACEW LPLOGCOLORSPACE;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LOGCOLORSPACEA LOGCOLORSPACE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPLOGCOLORSPACEA LPLOGCOLORSPACE;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_BITMAPCOREHEADER {
    DWORD bc_ਮਾਪ;
    ਸ਼ਬਦ_3 bc_ਚੌੜਾਈ;
    ਸ਼ਬਦ_3 bc_ਉਚਾਈ;
    ਸ਼ਬਦ_3 bcPlanes;
    ਸ਼ਬਦ_3 bc_ਦੋਆਧਾਰੀ_ਅੰਕ_ਗਿਣਤੀ;
  } BITMAPCOREHEADER,*LPBITMAPCOREHEADER,*PBITMAPCOREHEADER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_BITMAPINFOHEADER {
    DWORD bi_ਮਾਪ;
    LONG bi_ਚੌੜਾਈ;
    LONG bi_ਉਚਾਈ;
    ਸ਼ਬਦ_3 biPlanes;
    ਸ਼ਬਦ_3 bi_ਦੋਆਧਾਰੀ_ਅੰਕ_ਗਿਣਤੀ;
    DWORD biCompression;
    DWORD bi_ਮਾਪ_Image;
    LONG bi_XPels_ਪ੍ਰਤੀ_Meter;
    LONG bi_YPels_ਪ੍ਰਤੀ_Meter;
    DWORD bi_Clr_ਵਰਤਿਆ;
    DWORD biClrImportant;
  } BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    DWORD b_V4_ਮਾਪ;
    LONG b_V4_ਚੌੜਾਈ;
    LONG b_V4_ਉਚਾਈ;
    ਸ਼ਬਦ_3 bV4Planes;
    ਸ਼ਬਦ_3 b_V4_ਦੋਆਧਾਰੀ_ਅੰਕ_ਗਿਣਤੀ;
    DWORD bV4V4Compression;
    DWORD b_V4_ਮਾਪ_Image;
    LONG b_V4_XPels_ਪ੍ਰਤੀ_Meter;
    LONG b_V4_YPels_ਪ੍ਰਤੀ_Meter;
    DWORD b_V4_Clr_ਵਰਤਿਆ;
    DWORD bV4ClrImportant;
    DWORD b_V4_Red_ਨਕਾਬ;
    DWORD b_V4_Green_ਨਕਾਬ;
    DWORD b_V4_Blue_ਨਕਾਬ;
    DWORD b_V4_Alpha_ਨਕਾਬ;
    DWORD bV4CSType;
    CIEXYZTRIPLE bV4Endpoints;
    DWORD bV4GammaRed;
    DWORD bV4GammaGreen;
    DWORD bV4GammaBlue;
  } BITMAPV4_ਸਿਰਲੇਖ,*LPBITMAPV4_ਸਿਰਲੇਖ,*PBITMAPV4_ਸਿਰਲੇਖ;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ {
    DWORD b_V5_ਮਾਪ;
    LONG b_V5_ਚੌੜਾਈ;
    LONG b_V5_ਉਚਾਈ;
    ਸ਼ਬਦ_3 bV5Planes;
    ਸ਼ਬਦ_3 b_V5_ਦੋਆਧਾਰੀ_ਅੰਕ_ਗਿਣਤੀ;
    DWORD bV5Compression;
    DWORD b_V5_ਮਾਪ_Image;
    LONG b_V5_XPels_ਪ੍ਰਤੀ_Meter;
    LONG b_V5_YPels_ਪ੍ਰਤੀ_Meter;
    DWORD b_V5_Clr_ਵਰਤਿਆ;
    DWORD bV5ClrImportant;
    DWORD b_V5_Red_ਨਕਾਬ;
    DWORD b_V5_Green_ਨਕਾਬ;
    DWORD b_V5_Blue_ਨਕਾਬ;
    DWORD b_V5_Alpha_ਨਕਾਬ;
    DWORD bV5CSType;
    CIEXYZTRIPLE bV5Endpoints;
    DWORD bV5GammaRed;
    DWORD bV5GammaGreen;
    DWORD bV5GammaBlue;
    DWORD bV5Intent;
    DWORD b_V5_Profile_ਅੰਕੜੇ;
    DWORD b_V5_Profile_ਮਾਪ;
    DWORD bV5Reserved;
  } BITMAPV5_ਸਿਰਲੇਖ,*LPBITMAPV5_ਸਿਰਲੇਖ,*PBITMAPV5_ਸਿਰਲੇਖ;

//!__TINYC__: #define PROFILE_LINKED 'LINK'
//!__TINYC__: #define PROFILE_EMBEDDED 'MBED'

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BI_RGB 0L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BI_RLE8 1L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BI_RLE4 2L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BI_BITFIELDS 3L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BI_JPEG 4L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BI_PNG 5L

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_BITMAPINFO {
    BITMAPINFOHEADER bmi_ਸਿਰਲੇਖ;
    RGBQUAD bmiColors[1];
  } BITMAPINFO,*LPBITMAPINFO,*PBITMAPINFO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_BITMAPCOREINFO {
    BITMAPCOREHEADER bmci_ਸਿਰਲੇਖ;
    RGBTRIPLE bmciColors[1];
  } BITMAPCOREINFO,*LPBITMAPCOREINFO,*PBITMAPCOREINFO;

#ਅਨ੍ਤਰ੍ਭਾਵ <pshpack2.h>
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_BITMAPFILEHEADER {
    ਸ਼ਬਦ_3 bfType;
    DWORD bf_ਮਾਪ;
    ਸ਼ਬਦ_3 bfReserved1;
    ਸ਼ਬਦ_3 bfReserved2;
    DWORD bf_Off_ਬਿੱਟ;
  } BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#ਅਨ੍ਤਰ੍ਭਾਵ <poppack.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAKEPOINTS(l) (*((POINTS *)&(l)))

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOFONTSIG
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_FONTSIGNATURE {
    DWORD fsUsb[4];
    DWORD fsCsb[2];
  } FONTSIGNATURE,*PFONTSIGNATURE,*LPFONTSIGNATURE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_CHARSETINFO {
    UINT ciCharset;
    UINT ciACP;
    FONTSIGNATURE fs;
  } CHARSETINFO,*PCHARSETINFO,*NPCHARSETINFO,*LPCHARSETINFO;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCI_SRCCHARSET 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCI_SRCCODEPAGE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCI_SRCFONTSIG 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TCI_SRCLOCALE 0x1000

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LOCALESIGNATURE {
    DWORD lsUsb[4];
    DWORD lsCsbDefault[2];
    DWORD lsCsbSupported[2];
  } LOCALESIGNATURE,*PLOCALESIGNATURE,*LPLOCALESIGNATURE;
#ਜੇ_ਅੰਤ


#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMETAFILE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_HANDLETABLE {
    HGDIOBJ objectHandle[1];
  } HANDLETABLE,*PHANDLETABLE,*LPHANDLETABLE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_METARECORD {
    DWORD rd_ਮਾਪ;
    ਸ਼ਬਦ_3 rdFunction;
    ਸ਼ਬਦ_3 rdParm[1];
  } METARECORD;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_METARECORD UNALIGNED *PMETARECORD;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_METARECORD UNALIGNED *LPMETARECORD;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_METAFILEPICT {
    LONG mm;
    LONG xExt;
    LONG yExt;
    HMETAFILE hMF;
  } METAFILEPICT,*LPMETAFILEPICT;

#ਅਨ੍ਤਰ੍ਭਾਵ <pshpack2.h>
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_METAHEADER {
    ਸ਼ਬਦ_3 mtType;
    ਸ਼ਬਦ_3 mt_ਸਿਰਲੇਖ_ਮਾਪ;
    ਸ਼ਬਦ_3 mt_ਸੰਸਕਰਣ;
    DWORD mt_ਮਾਪ;
    ਸ਼ਬਦ_3 mtNoObjects;
    DWORD mt_Max_ਰਿਕਾਰਡ;
    ਸ਼ਬਦ_3 mtNoParameters;
  } METAHEADER;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_METAHEADER UNALIGNED *PMETAHEADER;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_METAHEADER UNALIGNED *LPMETAHEADER;

#ਅਨ੍ਤਰ੍ਭਾਵ <poppack.h>

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENHMETARECORD {
    DWORD iType;
    DWORD n_ਮਾਪ;
    DWORD dParm[1];
  } ENHMETARECORD,*PENHMETARECORD,*LPENHMETARECORD;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENHMETAHEADER {
    DWORD iType;
    DWORD n_ਮਾਪ;
    RECTL rclBounds;
    RECTL rcl_ਚੌਖਟਾ;
    DWORD dSignature;
    DWORD n_ਸੰਸਕਰਣ;
    DWORD n_ਬਾਈਟਾਂ;
    DWORD n_ਰਿਕਾਰਡਾਂ;
    ਸ਼ਬਦ_3 nHandles;
    ਸ਼ਬਦ_3 sReserved;
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
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOTEXTMETRIC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TMPF_FIXED_PITCH 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TMPF_ਸਦਿਸ਼ 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TMPF_DEVICE 0x08
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TMPF_TRUETYPE 0x04

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WCHAR BCHAR;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ BYTE BCHAR;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _TEXTMETRIC_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TEXTMETRIC_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_TEXTMETRICA {
    LONG tm_ਉਚਾਈ;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_ਅੰਦਰੂਨੀ_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ਚੌੜਾਈ;
    LONG tm_Max_Char_ਚੌੜਾਈ;
    LONG tm_ਭਾਰ;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_ਪਹਿਲਾ_Char;
    BYTE tm_ਆਖਰੀ_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ਬਾਹਰਲਾ;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_ਸੈੱਟ;
  } TEXTMETRICA,*PTEXTMETRICA,*NPTEXTMETRICA,*LPTEXTMETRICA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_TEXTMETRICW {
    LONG tm_ਉਚਾਈ;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_ਅੰਦਰੂਨੀ_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ਚੌੜਾਈ;
    LONG tm_Max_Char_ਚੌੜਾਈ;
    LONG tm_ਭਾਰ;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_ਪਹਿਲਾ_Char;
    WCHAR tm_ਆਖਰੀ_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ਬਾਹਰਲਾ;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_ਸੈੱਟ;
  } TEXTMETRICW,*PTEXTMETRICW,*NPTEXTMETRICW,*LPTEXTMETRICW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ TEXTMETRICW TEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PTEXTMETRICW PTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPTEXTMETRICW NPTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPTEXTMETRICW LPTEXTMETRIC;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ TEXTMETRICA TEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PTEXTMETRICA PTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPTEXTMETRICA NPTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPTEXTMETRICA LPTEXTMETRIC;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTM_REGULAR 0x00000040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTM_BOLD 0x00000020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTM_ITALIC 0x00000001L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTM_NONNEGATIVE_AC 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTM_PS_OPENTYPE 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTM_TT_OPENTYPE 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTM_MULTIPLEMASTER 0x00080000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTM_TYPE1 0x00100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NTM_DSIG 0x00200000

#ਅਨ੍ਤਰ੍ਭਾਵ <pshpack4.h>
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_NEWTEXTMETRICA {
    LONG tm_ਉਚਾਈ;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_ਅੰਦਰੂਨੀ_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ਚੌੜਾਈ;
    LONG tm_Max_Char_ਚੌੜਾਈ;
    LONG tm_ਭਾਰ;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    BYTE tm_ਪਹਿਲਾ_Char;
    BYTE tm_ਆਖਰੀ_Char;
    BYTE tmDefaultChar;
    BYTE tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ਬਾਹਰਲਾ;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_ਸੈੱਟ;
    DWORD ntmFlags;
    UINT ntm_ਮਾਪ_EM;
    UINT ntm_Cell_ਉਚਾਈ;
    UINT ntm_Avg_ਚੌੜਾਈ;
  } NEWTEXTMETRICA,*PNEWTEXTMETRICA,*NPNEWTEXTMETRICA,*LPNEWTEXTMETRICA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_NEWTEXTMETRICW {
    LONG tm_ਉਚਾਈ;
    LONG tmAscent;
    LONG tmDescent;
    LONG tm_ਅੰਦਰੂਨੀ_Leading;
    LONG tmExternalLeading;
    LONG tm_Ave_Char_ਚੌੜਾਈ;
    LONG tm_Max_Char_ਚੌੜਾਈ;
    LONG tm_ਭਾਰ;
    LONG tmOverhang;
    LONG tmDigitizedAspectX;
    LONG tmDigitizedAspectY;
    WCHAR tm_ਪਹਿਲਾ_Char;
    WCHAR tm_ਆਖਰੀ_Char;
    WCHAR tmDefaultChar;
    WCHAR tmBreakChar;
    BYTE tmItalic;
    BYTE tmUnderlined;
    BYTE tm_Struck_ਬਾਹਰਲਾ;
    BYTE tmPitchAndFamily;
    BYTE tm_Char_ਸੈੱਟ;
    DWORD ntmFlags;
    UINT ntm_ਮਾਪ_EM;
    UINT ntm_Cell_ਉਚਾਈ;
    UINT ntm_Avg_ਚੌੜਾਈ;
  } NEWTEXTMETRICW,*PNEWTEXTMETRICW,*NPNEWTEXTMETRICW,*LPNEWTEXTMETRICW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NEWTEXTMETRICW NEWTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PNEWTEXTMETRICW PNEWTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPNEWTEXTMETRICW NPNEWTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPNEWTEXTMETRICW LPNEWTEXTMETRIC;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NEWTEXTMETRICA NEWTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PNEWTEXTMETRICA PNEWTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPNEWTEXTMETRICA NPNEWTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPNEWTEXTMETRICA LPNEWTEXTMETRIC;
#ਜੇ_ਅੰਤ
#ਅਨ੍ਤਰ੍ਭਾਵ <poppack.h>

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_NEWTEXTMETRICEXA {
    NEWTEXTMETRICA ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_NEWTEXTMETRICEXW {
    NEWTEXTMETRICW ntmTm;
    FONTSIGNATURE ntmFontSig;
  } NEWTEXTMETRICEXW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NEWTEXTMETRICEXW NEWTEXTMETRICEX;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NEWTEXTMETRICEXA NEWTEXTMETRICEX;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_PELARRAY {
    LONG paXCount;
    LONG paYCount;
    LONG paXExt;
    LONG paYExt;
    BYTE paRGBs;
  } PELARRAY,*PPELARRAY,*NPPELARRAY,*LPPELARRAY;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LOGBRUSH {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG_PTR lbHatch;
  } LOGBRUSH,*PLOGBRUSH,*NPLOGBRUSH,*LPLOGBRUSH;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LOGBRUSH32 {
    UINT lbStyle;
    COLORREF lbColor;
    ULONG lbHatch;
  } LOGBRUSH32,*PLOGBRUSH32,*NPLOGBRUSH32,*LPLOGBRUSH32;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LOGBRUSH ਨਮੂਨਾ_2;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਮੂਨਾ_2 *PPATTERN;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਮੂਨਾ_2 *NPPATTERN;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਨਮੂਨਾ_2 *LPPATTERN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LOGPEN {
    UINT lopnStyle;
    ਬਿੰਦੂ_3 lopn_ਚੌੜਾਈ;
    COLORREF lopnColor;
  } LOGPEN,*PLOGPEN,*NPLOGPEN,*LPLOGPEN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EXTLOGPEN {
    DWORD elpPenStyle;
    DWORD elp_ਚੌੜਾਈ;
    UINT elpBrushStyle;
    COLORREF elpColor;
    ULONG_PTR elpHatch;
    DWORD elp_ਅੰਕ_Entries;
    DWORD elp_Style_ਇੰਦਰਾਜ[1];
  } EXTLOGPEN,*PEXTLOGPEN,*NPEXTLOGPEN,*LPEXTLOGPEN;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _PALETTEENTRY_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _PALETTEENTRY_DEFINED
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_PALETTEENTRY {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
  } PALETTEENTRY,*PPALETTEENTRY,*LPPALETTEENTRY;
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ _LOGPALETTE_DEFINED
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _LOGPALETTE_DEFINED

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LOGPALETTE {
    ਸ਼ਬਦ_3 pal_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3 pal_ਅੰਕ_Entries;
    PALETTEENTRY pal_Pal_ਇੰਦਰਾਜ[1];
  } LOGPALETTE,*PLOGPALETTE,*NPLOGPALETTE,*LPLOGPALETTE;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LF_FACESIZE 32

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LOGFONTA {
    LONG lf_ਉਚਾਈ;
    LONG lf_ਚੌੜਾਈ;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_ਭਾਰ;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_ਬਾਹਰਲਾ;
    BYTE lf_Char_ਸੈੱਟ;
    BYTE lf_ਬਾਹਰਲਾ_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    CHAR lfFaceName[LF_FACESIZE];
  } LOGFONTA,*PLOGFONTA,*NPLOGFONTA,*LPLOGFONTA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LOGFONTW {
    LONG lf_ਉਚਾਈ;
    LONG lf_ਚੌੜਾਈ;
    LONG lfEscapement;
    LONG lfOrientation;
    LONG lf_ਭਾਰ;
    BYTE lfItalic;
    BYTE lfUnderline;
    BYTE lf_Strike_ਬਾਹਰਲਾ;
    BYTE lf_Char_ਸੈੱਟ;
    BYTE lf_ਬਾਹਰਲਾ_Precision;
    BYTE lfClipPrecision;
    BYTE lfQuality;
    BYTE lfPitchAndFamily;
    WCHAR lfFaceName[LF_FACESIZE];
  } LOGFONTW,*PLOGFONTW,*NPLOGFONTW,*LPLOGFONTW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LOGFONTW LOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PLOGFONTW PLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPLOGFONTW NPLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPLOGFONTW LPLOGFONT;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LOGFONTA LOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PLOGFONTA PLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPLOGFONTA NPLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPLOGFONTA LPLOGFONT;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LF_FULLFACESIZE 64

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENUMLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_ਭਰਿਆ_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
  } ENUMLOGFONTA,*LPENUMLOGFONTA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENUMLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_ਭਰਿਆ_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
  } ENUMLOGFONTW,*LPENUMLOGFONTW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ENUMLOGFONTW ENUMLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPENUMLOGFONTW LPENUMLOGFONT;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ENUMLOGFONTA ENUMLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPENUMLOGFONTA LPENUMLOGFONT;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENUMLOGFONTEXA {
    LOGFONTA elfLogFont;
    BYTE elf_ਭਰਿਆ_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    BYTE elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXA,*LPENUMLOGFONTEXA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENUMLOGFONTEXW {
    LOGFONTW elfLogFont;
    WCHAR elf_ਭਰਿਆ_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    WCHAR elfScript[LF_FACESIZE];
  } ENUMLOGFONTEXW,*LPENUMLOGFONTEXW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ENUMLOGFONTEXW ENUMLOGFONTEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPENUMLOGFONTEXW LPENUMLOGFONTEX;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ENUMLOGFONTEXA ENUMLOGFONTEX;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPENUMLOGFONTEXA LPENUMLOGFONTEX;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_DEFAULT_PRECIS 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_STRING_PRECIS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_CHARACTER_PRECIS 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_STROKE_PRECIS 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_TT_PRECIS 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_DEVICE_PRECIS 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_RASTER_PRECIS 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_TT_ONLY_PRECIS 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_OUTLINE_PRECIS 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_SCREEN_OUTLINE_PRECIS 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਬਾਹਰਲਾ_PS_ONLY_PRECIS 10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIP_DEFAULT_PRECIS 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIP_CHARACTER_PRECIS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIP_STROKE_PRECIS 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIP_ਨਕਾਬ 0xf
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIP_LH_ANGLES (1<<4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIP_TT_ALWAYS (2<<4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIP_DFA_DISABLE (4<<4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIP_EMBEDDED (8<<4)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFAULT_QUALITY 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRAFT_QUALITY 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PROOF_QUALITY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NONANTIALIASED_QUALITY 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ANTIALIASED_QUALITY 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLEARTYPE_QUALITY 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLEARTYPE_NATURAL_QUALITY 6

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFAULT_PITCH 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FIXED_PITCH 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VARIABLE_PITCH 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MONO_FONT 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ANSI_CHARSET 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFAULT_CHARSET 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਚਿੰਨ੍ਹ_CHARSET 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHIFTJIS_CHARSET 128
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HANGEUL_CHARSET 129
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HANGUL_CHARSET 129
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GB2312_CHARSET 134
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CHINESEBIG5_CHARSET 136
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OEM_CHARSET 255
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ JOHAB_CHARSET 130
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HEBREW_CHARSET 177
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARABIC_CHARSET 178
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GREEK_CHARSET 161
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TURKISH_CHARSET 162
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VIETNAMESE_CHARSET 163
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ THAI_CHARSET 222
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EASTEUROPE_CHARSET 238
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RUSSIAN_CHARSET 204

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MAC_CHARSET 77
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BALTIC_CHARSET 186

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_LATIN1 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_LATIN2 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_CYRILLIC 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_GREEK 0x00000008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_TURKISH 0x00000010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_HEBREW 0x00000020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_ARABIC 0x00000040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_BALTIC 0x00000080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_VIETNAMESE 0x00000100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_THAI 0x00010000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_JISJAPAN 0x00020000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_CHINESESIMP 0x00040000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_WANSUNG 0x00080000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_CHINESETRAD 0x00100000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_JOHAB 0x00200000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FS_ਚਿੰਨ੍ਹ 0x80000000L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FF_DONTCARE (0<<4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FF_ROMAN (1<<4)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FF_SWISS (2<<4)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FF_MODERN (3<<4)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FF_SCRIPT (4<<4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FF_DECORATIVE (5<<4)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_DONTCARE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_THIN 100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_EXTRALIGHT 200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_LIGHT 300
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_ਸਾਧਾਰਨ 400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_MEDIUM 500
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_SEMIBOLD 600
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_BOLD 700
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_EXTRABOLD 800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_HEAVY 900

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_ULTRALIGHT FW_EXTRALIGHT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_REGULAR FW_ਸਾਧਾਰਨ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_DEMIBOLD FW_SEMIBOLD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_ULTRABOLD FW_EXTRABOLD
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FW_BLACK FW_HEAVY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PANOSE_ਗਿਣਤੀ 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_FAMILYTYPE_ਸੂਚਕਾਂਕ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIFSTYLE_ਸੂਚਕਾਂਕ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_ਸੂਚਕਾਂਕ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_PROPORTION_ਸੂਚਕਾਂਕ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CONTRAST_ਸੂਚਕਾਂਕ 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STROKEVARIATION_ਸੂਚਕਾਂਕ 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ARMSTYLE_ਸੂਚਕਾਂਕ 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETTERFORM_ਸੂਚਕਾਂਕ 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_ਸੂਚਕਾਂਕ 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_XHEIGHT_ਸੂਚਕਾਂਕ 9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CULTURE_LATIN 0

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_PANOSE {
    BYTE bFamilyType;
    BYTE bSerifStyle;
    BYTE b_ਭਾਰ;
    BYTE bProportion;
    BYTE bContrast;
    BYTE bStrokeVariation;
    BYTE bArmStyle;
    BYTE bLetterform;
    BYTE bMidline;
    BYTE bXHeight;
  } PANOSE,*LPPANOSE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ANY 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_NO_FIT 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_FAMILY_ਪਾਠ_DISPLAY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_FAMILY_SCRIPT 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_FAMILY_DECORATIVE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_FAMILY_PICTORIAL 5

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_COVE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_OBTUSE_COVE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_ਵਰਗਫਲ_COVE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_OBTUSE_ਵਰਗਫਲ_COVE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_ਵਰਗਫਲ 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_THIN 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_BONE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_EXAGGERATED 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_TRIANGLE 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_ਸਾਧਾਰਨ_SANS 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_OBTUSE_SANS 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_PERP_SANS 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_FLARED 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_SERIF_ROUNDED 15

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_VERY_LIGHT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_LIGHT 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_THIN 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_BOOK 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_MEDIUM 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_DEMI 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_BOLD 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_HEAVY 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_BLACK 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_ਭਾਰ_NORD 11

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_PROP_OLD_STYLE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_PROP_MODERN 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_PROP_EVEN_ਚੌੜਾਈ 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_PROP_EXPANDED 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_PROP_CONDENSED 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_PROP_VERY_EXPANDED 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_PROP_VERY_CONDENSED 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_PROP_MONOSPACED 9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CONTRAST_NONE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CONTRAST_VERY_ਨੀਵਾਂ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CONTRAST_ਨੀਵਾਂ 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CONTRAST_MEDIUM_ਨੀਵਾਂ 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CONTRAST_MEDIUM 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CONTRAST_MEDIUM_ਉੱਚਾ 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CONTRAST_ਉੱਚਾ 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_CONTRAST_VERY_ਉੱਚਾ 9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STROKE_GRADUAL_DIAG 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STROKE_GRADUAL_TRAN 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STROKE_GRADUAL_VERT 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STROKE_GRADUAL_HORZ 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STROKE_RAPID_VERT 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STROKE_RAPID_HORZ 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STROKE_INSTANT_VERT 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STRAIGHT_ARMS_HORZ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STRAIGHT_ARMS_WEDGE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STRAIGHT_ARMS_VERT 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STRAIGHT_ARMS_SINGLE_SERIF 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_STRAIGHT_ARMS_DOUBLE_SERIF 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_BENT_ARMS_HORZ 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_BENT_ARMS_WEDGE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_BENT_ARMS_VERT 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_BENT_ARMS_SINGLE_SERIF 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_BENT_ARMS_DOUBLE_SERIF 11

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_ਸਾਧਾਰਨ_CONTACT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_ਸਾਧਾਰਨ_WEIGHTED 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_ਸਾਧਾਰਨ_BOXED 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_ਸਾਧਾਰਨ_FLATTENED 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_ਸਾਧਾਰਨ_ROUNDED 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_ਸਾਧਾਰਨ_OFF_CENTER 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_ਸਾਧਾਰਨ_ਵਰਗਫਲ 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_OBLIQUE_CONTACT 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_OBLIQUE_WEIGHTED 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_OBLIQUE_BOXED 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_OBLIQUE_FLATTENED 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_OBLIQUE_ROUNDED 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_OBLIQUE_OFF_CENTER 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_LETT_OBLIQUE_ਵਰਗਫਲ 15

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_STANDARD_TRIMMED 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_STANDARD_POINTED 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_STANDARD_SERIFED 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_ਉੱਚਾ_TRIMMED 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_ਉੱਚਾ_POINTED 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_ਉੱਚਾ_SERIFED 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_CONSTANT_TRIMMED 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_CONSTANT_POINTED 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_CONSTANT_SERIFED 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_ਨੀਵਾਂ_TRIMMED 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_ਨੀਵਾਂ_POINTED 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_MIDLINE_ਨੀਵਾਂ_SERIFED 13

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_XHEIGHT_CONSTANT_SMALL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_XHEIGHT_CONSTANT_STD 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_XHEIGHT_CONSTANT_LARGE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_XHEIGHT_DUCKING_SMALL 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_XHEIGHT_DUCKING_STD 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAN_XHEIGHT_DUCKING_LARGE 7

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_VENDOR_ਮਾਪ 4

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EXTLOGFONTA {
    LOGFONTA elfLogFont;
    BYTE elf_ਭਰਿਆ_Name[LF_FULLFACESIZE];
    BYTE elfStyle[LF_FACESIZE];
    DWORD elf_ਸੰਸਕਰਣ;
    DWORD elf_Style_ਮਾਪ;
    DWORD elf_ਮੇਲ;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_ਮਾਪ];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTA,*PEXTLOGFONTA,*NPEXTLOGFONTA,*LPEXTLOGFONTA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EXTLOGFONTW {
    LOGFONTW elfLogFont;
    WCHAR elf_ਭਰਿਆ_Name[LF_FULLFACESIZE];
    WCHAR elfStyle[LF_FACESIZE];
    DWORD elf_ਸੰਸਕਰਣ;
    DWORD elf_Style_ਮਾਪ;
    DWORD elf_ਮੇਲ;
    DWORD elfReserved;
    BYTE elfVendorId[ELF_VENDOR_ਮਾਪ];
    DWORD elfCulture;
    PANOSE elfPanose;
  } EXTLOGFONTW,*PEXTLOGFONTW,*NPEXTLOGFONTW,*LPEXTLOGFONTW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ EXTLOGFONTW EXTLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PEXTLOGFONTW PEXTLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPEXTLOGFONTW NPEXTLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPEXTLOGFONTW LPEXTLOGFONT;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ EXTLOGFONTA EXTLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PEXTLOGFONTA PEXTLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPEXTLOGFONTA NPEXTLOGFONT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPEXTLOGFONTA LPEXTLOGFONT;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_ਸੰਸਕਰਣ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ELF_CULTURE_LATIN 0

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RASTER_FONTTYPE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEVICE_FONTTYPE 0x002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRUETYPE_FONTTYPE 0x004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGB(r,g,b) ((COLORREF)(((BYTE)(r)|((ਸ਼ਬਦ_3)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PALETTERGB(r,g,b) (0x02000000 | RGB(r,g,b))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PALETTEINDEX(i) ((COLORREF)(0x01000000 | (DWORD)(ਸ਼ਬਦ_3)(i)))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_RESERVED 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_EXPLICIT 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_NOCOLLAPSE 0x04

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetRValue(rgb) (LOBYTE(rgb))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetGValue(rgb) (LOBYTE(((ਸ਼ਬਦ_3)(rgb)) >> 8))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetBValue(rgb) (LOBYTE((rgb)>>16))

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TRANSPARENT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OPAQUE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BKMODE_ਆਖਰੀ 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GM_COMPATIBLE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GM_ADVANCED 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GM_ਆਖਰੀ 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PT_CLOSEFIGURE 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PT_LINETO 0x02
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PT_BEZIERTO 0x04
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PT_MOVETO 0x06

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_ਪਾਠ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_LOMETRIC 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_HIMETRIC 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_LOENGLISH 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_HIENGLISH 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_TWIPS 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_ISOTROPIC 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_ANISOTROPIC 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_MIN MM_ਪਾਠ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_MAX MM_ANISOTROPIC
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_MAX_FIXEDSCALE MM_TWIPS

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ABSOLUTE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RELATIVE 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WHITE_BRUSH 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LTGRAY_BRUSH 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਲੇਟੀ_BRUSH 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DKGRAY_BRUSH 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BLACK_BRUSH 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NULL_BRUSH 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HOLLOW_BRUSH NULL_BRUSH
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WHITE_PEN 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BLACK_PEN 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NULL_PEN 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OEM_FIXED_FONT 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ANSI_FIXED_FONT 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ANSI_VAR_FONT 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_FONT 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEVICE_DEFAULT_FONT 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFAULT_PALETTE 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSTEM_FIXED_FONT 16

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DEFAULT_GUI_FONT 17

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_BRUSH 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_PEN 19

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STOCK_ਆਖਰੀ 19

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLR_INVALID 0xFFFFFFFF

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_SOLID 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_NULL 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_HOLLOW BS_NULL
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_HATCHED 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_ਨਮੂਨਾ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_ਸੂਚਕਾਂਕਿਤ 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_DIBPATTERN 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_DIBPATTERNPT 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_PATTERN8X8 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_DIBPATTERN8X8 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BS_MONOPATTERN 9

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HS_HORIZONTAL 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HS_VERTICAL 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HS_FDIAGONAL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HS_BDIAGONAL 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HS_CROSS 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HS_DIAGCROSS 5

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_SOLID 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_DASH 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_DOT 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_DASHDOT 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_DASHDOTDOT 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_NULL 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_INSIDEFRAME 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_USERSTYLE 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_ALTERNATE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_STYLE_ਨਕਾਬ 0x0000000F

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_ENDCAP_ਗੇੜਾ 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_ENDCAP_ਵਰਗਫਲ 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_ENDCAP_FLAT 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_ENDCAP_ਨਕਾਬ 0x00000F00

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_JOIN_ਗੇੜਾ 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_JOIN_BEVEL 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_JOIN_MITER 0x00002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_JOIN_ਨਕਾਬ 0x0000F000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_COSMETIC 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_GEOMETRIC 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PS_TYPE_ਨਕਾਬ 0x000F0000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AD_COUNTERCLOCKWISE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AD_CLOCKWISE 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DRIVERVERSION 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TECHNOLOGY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HORZSIZE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VERTSIZE 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ HORZRES 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VERTRES 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BITSPIXEL 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PLANES 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NUMBRUSHES 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NUMPENS 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NUMMARKERS 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NUMFONTS 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NUMCOLORS 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PDEVICESIZE 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CURVECAPS 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LINECAPS 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ POLYGONALCAPS 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TEXTCAPS 34
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CLIPCAPS 36
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RASTERCAPS 38
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ASPECTX 40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ASPECTY 42
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ASPECTXY 44

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGPIXELSX 88
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOGPIXELSY 90

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SIZEPALETTE 104
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NUMRESERVED 106
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLORRES 108

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PHYSICALWIDTH 110
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PHYSICALHEIGHT 111
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PHYSICALOFFSETX 112
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PHYSICALOFFSETY 113
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCALINGFACTORX 114
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCALINGFACTORY 115

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VREFRESH 116

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOPVERTRES 117

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DESKTOPHORZRES 118

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BLTALIGNMENT 119

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SHADEBLENDCAPS 120
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLORMGMTCAPS 121

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOGDICAPMASKS
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_PLOTTER 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_RASDISPLAY 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_RASPRINTER 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_RASCAMERA 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_CHARSTREAM 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_METAFILE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DT_DISPFILE 6

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_NONE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_CIRCLES 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_PIE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_CHORD 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_ELLIPSES 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_WIDE 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_STYLED 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_WIDESTYLED 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_INTERIORS 128
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CC_ROUNDRECT 256

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_NONE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_POLYLINE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_MARKER 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_POLYMARKER 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_WIDE 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_STYLED 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_WIDESTYLED 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LC_INTERIORS 128

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_NONE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_POLYGON 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_RECTANGLE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_WINDPOLYGON 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_TRAPEZOID 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_SCANLINE 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_WIDE 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_STYLED 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_WIDESTYLED 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_INTERIORS 128
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_POLYPOLYGON 256
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PC_PATHS 512

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CP_NONE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CP_RECTANGLE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CP_REGION 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_OP_CHARACTER 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_OP_STROKE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_CP_STROKE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_CR_90 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_CR_ANY 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_SF_X_YINDEP 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_SA_DOUBLE 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_SA_INTEGER 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_SA_CONTIN 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_EA_DOUBLE 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_IA_ABLE 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_UA_ABLE 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_SO_ABLE 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_RA_ABLE 0x00002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_VA_ABLE 0x00004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_RESERVED 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TC_SCROLLBLT 0x00010000
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_NONE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_BITBLT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_BANDING 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_SCALING 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_BITMAP64 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_GDI20_OUTPUT 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_GDI20_STATE 0x0020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_SAVEBITMAP 0x0040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_DI_BITMAP 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_PALETTE 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_DIBTODEV 0x0200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_BIGFONT 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_STRETCHBLT 0x0800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_FLOODFILL 0x1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_STRETCHDIB 0x2000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_OP_DX_OUTPUT 0x4000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RC_DEVBITS 0x8000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_NONE 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_CONST_ALPHA 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_PIXEL_ALPHA 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_PREMULT_ALPHA 0x00000004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_GRAD_RECT 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SB_GRAD_TRI 0x00000020

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CM_NONE 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CM_DEVICE_ICM 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CM_GAMMA_RAMP 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CM_CMYK_COLOR 0x00000004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DIB_RGB_COLORS 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DIB_PAL_COLORS 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSPAL_ERROR 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSPAL_STATIC 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSPAL_NOSTATIC 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSPAL_NOSTATIC256 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CBM_INIT 0x04L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLOODFILLBORDER 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLOODFILLSURFACE 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CCHDEVICENAME 32

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CCHFORMNAME 32

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _devicemodeA {
    BYTE dmDeviceName[CCHDEVICENAME];
    ਸ਼ਬਦ_3 dm_Spec_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3 dm_Driver_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3 dm_ਮਾਪ;
    ਸ਼ਬਦ_3 dmDriverExtra;
    DWORD dmFields;
    ਸੰਘ {
      ਬਣਤਰ {
        ਛੋਟਾ dmOrientation;
        ਛੋਟਾ dm_Paper_ਮਾਪ;
        ਛੋਟਾ dm_Paper_ਲੰਮਾਈ;
        ਛੋਟਾ dm_Paper_ਚੌੜਾਈ;
        ਛੋਟਾ dmScale;
        ਛੋਟਾ dmCopies;
        ਛੋਟਾ dm_Default_ਸਰੋਤ;
        ਛੋਟਾ dmPrintQuality;
      };
      ਬਣਤਰ {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    ਛੋਟਾ dmColor;
    ਛੋਟਾ dmDuplex;
    ਛੋਟਾ dmYResolution;
    ਛੋਟਾ dmTTOption;
    ਛੋਟਾ dmCollate;
    BYTE dmFormName[CCHFORMNAME];
    ਸ਼ਬਦ_3 dmLogPixels;
    DWORD dm_ਬਿੱਟ_ਪ੍ਰਤੀ_Pel;
    DWORD dm_Pels_ਚੌੜਾਈ;
    DWORD dm_Pels_ਉਚਾਈ;
    ਸੰਘ {
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
    DWORD dm_Panning_ਚੌੜਾਈ;
    DWORD dm_Panning_ਉਚਾਈ;
  } DEVMODEA,*PDEVMODEA,*NPDEVMODEA,*LPDEVMODEA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _devicemodeW {
    WCHAR dmDeviceName[CCHDEVICENAME];
    ਸ਼ਬਦ_3 dm_Spec_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3 dm_Driver_ਸੰਸਕਰਣ;
    ਸ਼ਬਦ_3 dm_ਮਾਪ;
    ਸ਼ਬਦ_3 dmDriverExtra;
    DWORD dmFields;
    ਸੰਘ {
      ਬਣਤਰ {
        ਛੋਟਾ dmOrientation;
        ਛੋਟਾ dm_Paper_ਮਾਪ;
        ਛੋਟਾ dm_Paper_ਲੰਮਾਈ;
        ਛੋਟਾ dm_Paper_ਚੌੜਾਈ;
        ਛੋਟਾ dmScale;
        ਛੋਟਾ dmCopies;
        ਛੋਟਾ dm_Default_ਸਰੋਤ;
        ਛੋਟਾ dmPrintQuality;
      };
      ਬਣਤਰ {
        POINTL dmPosition;
        DWORD dmDisplayOrientation;
        DWORD dmDisplayFixedOutput;
      };
    };
    ਛੋਟਾ dmColor;
    ਛੋਟਾ dmDuplex;
    ਛੋਟਾ dmYResolution;
    ਛੋਟਾ dmTTOption;
    ਛੋਟਾ dmCollate;
    WCHAR dmFormName[CCHFORMNAME];
    ਸ਼ਬਦ_3 dmLogPixels;
    DWORD dm_ਬਿੱਟ_ਪ੍ਰਤੀ_Pel;
    DWORD dm_Pels_ਚੌੜਾਈ;
    DWORD dm_Pels_ਉਚਾਈ;
    ਸੰਘ {
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
    DWORD dm_Panning_ਚੌੜਾਈ;
    DWORD dm_Panning_ਉਚਾਈ;
  } DEVMODEW,*PDEVMODEW,*NPDEVMODEW,*LPDEVMODEW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DEVMODEW DEVMODE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PDEVMODEW PDEVMODE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPDEVMODEW NPDEVMODE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDEVMODEW LPDEVMODE;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DEVMODEA DEVMODE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PDEVMODEA PDEVMODE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPDEVMODEA NPDEVMODE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDEVMODEA LPDEVMODE;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_SPECVERSION 0x0401

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_ORIENTATION 0x00000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_PAPERSIZE 0x00000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_PAPERLENGTH 0x00000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_PAPERWIDTH 0x00000008L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_SCALE 0x00000010L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_POSITION 0x00000020L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_NUP 0x00000040L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_DISPLAYORIENTATION 0x00000080L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_COPIES 0x00000100L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_DEFAULTSOURCE 0x00000200L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_PRINTQUALITY 0x00000400L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_COLOR 0x00000800L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_DUPLEX 0x00001000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_YRESOLUTION 0x00002000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_TTOPTION 0x00004000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_COLLATE 0x00008000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_FORMNAME 0x00010000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_LOGPIXELS 0x00020000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_BITSPERPEL 0x00040000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_PELSWIDTH 0x00080000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_PELSHEIGHT 0x00100000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_DISPLAYFLAGS 0x00200000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_DISPLAYFREQUENCY 0x00400000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_ICMMETHOD 0x00800000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_ICMINTENT 0x01000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_MEDIATYPE 0x02000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_DITHERTYPE 0x04000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_PANNINGWIDTH 0x08000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_PANNINGHEIGHT 0x10000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_DISPLAYFIXEDOUTPUT 0x20000000L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMORIENT_PORTRAIT 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMORIENT_LANDSCAPE 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ਪਹਿਲਾ DMPAPER_LETTER
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LETTER 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LETTERSMALL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_TABLOID 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LEDGER 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LEGAL 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_STATEMENT 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_EXECUTIVE 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A3 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A4 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A4SMALL 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A5 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_B4 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_B5 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_FOLIO 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_QUARTO 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_10X14 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_11X17 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_NOTE 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_9 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_10 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_11 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_12 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_14 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_CSHEET 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_DSHEET 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ESHEET 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_DL 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_C5 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_C3 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_C4 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_C6 31
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_C65 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_B4 33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_B5 34
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_B6 35
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_ITALY 36
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_MONARCH 37
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_PERSONAL 38
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_FANFOLD_US 39
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_FANFOLD_STD_GERMAN 40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_FANFOLD_LGL_GERMAN 41
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ISO_B4 42
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JAPANESE_POSTCARD 43
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_9X11 44
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_10X11 45
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_15X11 46
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ENV_INVITE 47
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_RESERVED_48 48
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_RESERVED_49 49
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LETTER_EXTRA 50
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LEGAL_EXTRA 51
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_TABLOID_EXTRA 52
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A4_EXTRA 53
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LETTER_TRANSVERSE 54
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A4_TRANSVERSE 55
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LETTER_EXTRA_TRANSVERSE 56
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A_PLUS 57
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_B_PLUS 58
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LETTER_PLUS 59
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A4_PLUS 60
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A5_TRANSVERSE 61
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_B5_TRANSVERSE 62
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A3_EXTRA 63
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A5_EXTRA 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_B5_EXTRA 65
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A2 66
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A3_TRANSVERSE 67
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A3_EXTRA_TRANSVERSE 68
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_DBL_JAPANESE_POSTCARD 69
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A6 70
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_KAKU2 71
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_KAKU3 72
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_CHOU3 73
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_CHOU4 74
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_LETTER_ROTATED 75
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A3_ROTATED 76
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A4_ROTATED 77
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A5_ROTATED 78
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_B4_JIS_ROTATED 79
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_B5_JIS_ROTATED 80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JAPANESE_POSTCARD_ROTATED 81
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED 82
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_A6_ROTATED 83
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_KAKU2_ROTATED 84
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_KAKU3_ROTATED 85
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_CHOU3_ROTATED 86
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_CHOU4_ROTATED 87
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_B6_JIS 88
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_B6_JIS_ROTATED 89
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_12X11 90
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_YOU4 91
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_JENV_YOU4_ROTATED 92
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_P16K 93
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_P32K 94
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_P32KBIG 95
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_1 96
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_2 97
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_3 98
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_4 99
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_5 100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_6 101
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_7 102
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_8 103
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_9 104
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_10 105
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_P16K_ROTATED 106
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_P32K_ROTATED 107
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_P32KBIG_ROTATED 108
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_1_ROTATED 109
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_2_ROTATED 110
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_3_ROTATED 111
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_4_ROTATED 112
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_5_ROTATED 113
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_6_ROTATED 114
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_7_ROTATED 115
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_8_ROTATED 116
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_9_ROTATED 117
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_PENV_10_ROTATED 118

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_ਆਖਰੀ DMPAPER_PENV_10_ROTATED

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMPAPER_USER 256

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_ਪਹਿਲਾ DMBIN_ਉੱਤਲਾ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_ਉੱਤਲਾ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_ONLYONE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_ਹੇਠਲਾ 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_ਵਿਚਕਾਰ 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_MANUAL 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_ENVELOPE 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_ENVMANUAL 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_AUTO 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_TRACTOR 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_SMALLFMT 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_LARGEFMT 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_LARGECAPACITY 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_CASSETTE 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_FORMSOURCE 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_ਆਖਰੀ DMBIN_FORMSOURCE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMBIN_USER 256

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMRES_DRAFT (-1)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMRES_ਨੀਵਾਂ (-2)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMRES_MEDIUM (-3)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMRES_ਉੱਚਾ (-4)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMCOLOR_MONOCHROME 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMCOLOR_COLOR 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDUP_SIMPLEX 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDUP_VERTICAL 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDUP_HORIZONTAL 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMTT_BITMAP 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMTT_DOWNLOAD 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMTT_SUBDEV 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMTT_DOWNLOAD_OUTLINE 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMCOLLATE_FALSE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMCOLLATE_TRUE 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDO_DEFAULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDO_90 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDO_180 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDO_270 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDFO_DEFAULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDFO_STRETCH 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDFO_CENTER 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDISPLAYFLAGS_TEXTMODE 0x00000004

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMNUP_SYSTEM 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMNUP_ONEUP 2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICMMETHOD_NONE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICMMETHOD_SYSTEM 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICMMETHOD_DRIVER 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICMMETHOD_DEVICE 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICMMETHOD_USER 256

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICM_SATURATE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICM_CONTRAST 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICM_COLORIMETRIC 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICM_ABS_COLORIMETRIC 4

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMICM_USER 256

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMMEDIA_STANDARD 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMMEDIA_TRANSPARENCY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMMEDIA_GLOSSY 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMMEDIA_USER 256

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_NONE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_COARSE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_FINE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_LINEART 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_ERRORDIFFUSION 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_RESERVED6 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_RESERVED7 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_RESERVED8 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_RESERVED9 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_GRAYSCALE 10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DMDITHER_USER 256

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _DISPLAY_DEVICEA {
    DWORD cb;
    CHAR DeviceName[32];
    CHAR DeviceString[128];
    DWORD StateFlags;
    CHAR DeviceID[128];
    CHAR Device_ਕੁੰਜੀ[128];
  } DISPLAY_DEVICEA,*PDISPLAY_DEVICEA,*LPDISPLAY_DEVICEA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _DISPLAY_DEVICEW {
    DWORD cb;
    WCHAR DeviceName[32];
    WCHAR DeviceString[128];
    DWORD StateFlags;
    WCHAR DeviceID[128];
    WCHAR Device_ਕੁੰਜੀ[128];
  } DISPLAY_DEVICEW,*PDISPLAY_DEVICEW,*LPDISPLAY_DEVICEW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DISPLAY_DEVICEW DISPLAY_DEVICE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PDISPLAY_DEVICEW PDISPLAY_DEVICE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDISPLAY_DEVICEW LPDISPLAY_DEVICE;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DISPLAY_DEVICEA DISPLAY_DEVICE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PDISPLAY_DEVICEA PDISPLAY_DEVICE;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDISPLAY_DEVICEA LPDISPLAY_DEVICE;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_ATTACHED_ਮੰਜ਼ਿਲ_DESKTOP 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_MULTI_DRIVER 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_PRIMARY_DEVICE 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_MIRRORING_DRIVER 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_VGA_COMPATIBLE 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_REMOVABLE 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_MODESPRUNED 0x08000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_REMOTE 0x04000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_DISCONNECT 0x02000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_ਸਰਗਰਮ 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DISPLAY_DEVICE_ATTACHED 0x00000002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RDH_RECTANGLES 1

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RGNDATAHEADER {
    DWORD dw_ਮਾਪ;
    DWORD iType;
    DWORD n_ਗਿਣਤੀ;
    DWORD n_Rgn_ਮਾਪ;
    RECT rcBound;
  } RGNDATAHEADER,*PRGNDATAHEADER;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _RGNDATA {
    RGNDATAHEADER rdh;
    ਅੱਖਰ ਬਫਰ_3[1];
  } RGNDATA,*PRGNDATA,*NPRGNDATA,*LPRGNDATA;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYSRGN 4

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ABC {
    ਪੂਰਨ abcA;
    UINT abcB;
    ਪੂਰਨ abcC;
  } ABC,*PABC,*NPABC,*LPABC;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _ABCFLOAT {
    FLOAT abcfA;
    FLOAT abcfB;
    FLOAT abcfC;
  } ABCFLOAT,*PABCFLOAT,*NPABCFLOAT,*LPABCFLOAT;

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOTEXTMETRIC

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OUTLINETEXTMETRICA {
    UINT otm_ਮਾਪ;
    TEXTMETRICA otm_ਪਾਠ_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_ਸੰਖਿਆ;
    UINT otmfsSelection;
    UINT otmfsType;
    ਪੂਰਨ otms_Char_ਢਲਾਨ_Rise;
    ਪੂਰਨ otms_Char_ਢਲਾਨ_ਲੜੀਵਾਰ;
    ਪੂਰਨ otmItalicAngle;
    UINT otmEMSquare;
    ਪੂਰਨ otmAscent;
    ਪੂਰਨ otmDescent;
    UINT otm_ਸਤਰ_Gap;
    UINT otms_Cap_Em_ਉਚਾਈ;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    ਪੂਰਨ otmMacAscent;
    ਪੂਰਨ otmMacDescent;
    UINT otm_Mac_ਸਤਰ_Gap;
    UINT otmusMinimumPPEM;
    ਬਿੰਦੂ_3 otmpt_Subscript_ਮਾਪ;
    ਬਿੰਦੂ_3 otmpt_Subscript_ਵਿੱਥ;
    ਬਿੰਦੂ_3 otmpt_Superscript_ਮਾਪ;
    ਬਿੰਦੂ_3 otmpt_Superscript_ਵਿੱਥ;
    UINT otms_Strikeout_ਮਾਪ;
    ਪੂਰਨ otmsStrikeoutPosition;
    ਪੂਰਨ otms_Underscore_ਮਾਪ;
    ਪੂਰਨ otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_ਭਰਿਆ_Name;
  } OUTLINETEXTMETRICA,*POUTLINETEXTMETRICA,*NPOUTLINETEXTMETRICA,*LPOUTLINETEXTMETRICA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _OUTLINETEXTMETRICW {
    UINT otm_ਮਾਪ;
    TEXTMETRICW otm_ਪਾਠ_Metrics;
    BYTE otmFiller;
    PANOSE otm_Panose_ਸੰਖਿਆ;
    UINT otmfsSelection;
    UINT otmfsType;
    ਪੂਰਨ otms_Char_ਢਲਾਨ_Rise;
    ਪੂਰਨ otms_Char_ਢਲਾਨ_ਲੜੀਵਾਰ;
    ਪੂਰਨ otmItalicAngle;
    UINT otmEMSquare;
    ਪੂਰਨ otmAscent;
    ਪੂਰਨ otmDescent;
    UINT otm_ਸਤਰ_Gap;
    UINT otms_Cap_Em_ਉਚਾਈ;
    UINT otmsXHeight;
    RECT otmrcFontBox;
    ਪੂਰਨ otmMacAscent;
    ਪੂਰਨ otmMacDescent;
    UINT otm_Mac_ਸਤਰ_Gap;
    UINT otmusMinimumPPEM;
    ਬਿੰਦੂ_3 otmpt_Subscript_ਮਾਪ;
    ਬਿੰਦੂ_3 otmpt_Subscript_ਵਿੱਥ;
    ਬਿੰਦੂ_3 otmpt_Superscript_ਮਾਪ;
    ਬਿੰਦੂ_3 otmpt_Superscript_ਵਿੱਥ;
    UINT otms_Strikeout_ਮਾਪ;
    ਪੂਰਨ otmsStrikeoutPosition;
    ਪੂਰਨ otms_Underscore_ਮਾਪ;
    ਪੂਰਨ otmsUnderscorePosition;
    PSTR otmpFamilyName;
    PSTR otmpFaceName;
    PSTR otmpStyleName;
    PSTR otmp_ਭਰਿਆ_Name;
  } OUTLINETEXTMETRICW,*POUTLINETEXTMETRICW,*NPOUTLINETEXTMETRICW,*LPOUTLINETEXTMETRICW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ OUTLINETEXTMETRICW OUTLINETEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ POUTLINETEXTMETRICW POUTLINETEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPOUTLINETEXTMETRICW NPOUTLINETEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPOUTLINETEXTMETRICW LPOUTLINETEXTMETRIC;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ OUTLINETEXTMETRICA OUTLINETEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ POUTLINETEXTMETRICA POUTLINETEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPOUTLINETEXTMETRICA NPOUTLINETEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPOUTLINETEXTMETRICA LPOUTLINETEXTMETRIC;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_POLYTEXTA {
    ਪੂਰਨ x;
    ਪੂਰਨ y;
    UINT n;
    LPCSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    ਪੂਰਨ *pdx;
  } POLYTEXTA,*PPOLYTEXTA,*NPPOLYTEXTA,*LPPOLYTEXTA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_POLYTEXTW {
    ਪੂਰਨ x;
    ਪੂਰਨ y;
    UINT n;
    LPCWSTR lpstr;
    UINT uiFlags;
    RECT rcl;
    ਪੂਰਨ *pdx;
  } POLYTEXTW,*PPOLYTEXTW,*NPPOLYTEXTW,*LPPOLYTEXTW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ POLYTEXTW POLYTEXT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PPOLYTEXTW PPOLYTEXT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPPOLYTEXTW NPPOLYTEXT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPPOLYTEXTW LPPOLYTEXT;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ POLYTEXTA POLYTEXT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PPOLYTEXTA PPOLYTEXT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ NPPOLYTEXTA NPPOLYTEXT;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPPOLYTEXTA LPPOLYTEXT;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _FIXED {
    ਸ਼ਬਦ_3 fract;
    ਛੋਟਾ ਮੁੱਲ;
  } FIXED;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _MAT2 {
    FIXED eM11;
    FIXED eM12;
    FIXED eM21;
    FIXED eM22;
  } MAT2,*LPMAT2;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _GLYPHMETRICS {
    UINT gmBlackBoxX;
    UINT gmBlackBoxY;
    ਬਿੰਦੂ_3 gmptGlyphOrigin;
    ਛੋਟਾ gmCellIncX;
    ਛੋਟਾ gmCellIncY;
  } GLYPHMETRICS,*LPGLYPHMETRICS;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGO_METRICS 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGO_BITMAP 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGO_NATIVE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGO_BEZIER 3

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGO_GRAY2_BITMAP 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGO_GRAY4_BITMAP 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGO_GRAY8_BITMAP 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGO_GLYPH_ਸੂਚਕਾਂਕ 0x0080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGO_UNHINTED 0x0100

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TT_POLYGON_TYPE 24

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TT_PRIM_ਸਤਰ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TT_PRIM_QSPLINE 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TT_PRIM_CSPLINE 3

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_POINTFX {
    FIXED x;
    FIXED y;
  } POINTFX,*LPPOINTFX;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_TTPOLYCURVE {
    ਸ਼ਬਦ_3 wType;
    ਸ਼ਬਦ_3 cpfx;
    POINTFX apfx[1];
  } TTPOLYCURVE,*LPTTPOLYCURVE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_TTPOLYGONHEADER {
    DWORD cb;
    DWORD dwType;
    POINTFX pfx_ਸ਼ੁਰੂ;
  } TTPOLYGONHEADER,*LPTTPOLYGONHEADER;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_DBCS 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_REORDER 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_USEKERNING 0x0008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_GLYPHSHAPE 0x0010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_LIGATE 0x0020

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_DIACRITIC 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_KASHIDA 0x0400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_ERROR 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLI_ਨਕਾਬ 0x103B

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_JUSTIFY 0x00010000L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FLI_GLYPHS 0x00040000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_CLASSIN 0x00080000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_MAXEXTENT 0x00100000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_JUSTIFYIN 0x00200000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_DISPLAYZWG 0x00400000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_SYMSWAPOFF 0x00800000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_NUMERICOVERRIDE 0x01000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_NEUTRALOVERRIDE 0x02000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_NUMERICSLATIN 0x04000000L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCP_NUMERICSLOCAL 0x08000000L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_LATIN 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_HEBREW 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_ARABIC 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_NEUTRAL 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_LOCALNUMBER 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_LATINNUMBER 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_LATINNUMERICTERMINATOR 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_LATINNUMERICSEPARATOR 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_NUMERICSEPARATOR 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_PREBOUNDLTR 0x80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_PREBOUNDRTL 0x40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_POSTBOUNDLTR 0x20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPCLASS_POSTBOUNDRTL 0x10

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPGLYPH_LINKBEFORE 0x8000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GCPGLYPH_LINKAFTER 0x4000

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_GCP_RESULTSA {
    DWORD l_Struct_ਮਾਪ;
    LPSTR lp_ਬਾਹਰਲਾ_String;
    UINT *lp_ਕ੍ਰਮ;
    ਪੂਰਨ *lpDx;
    ਪੂਰਨ *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    ਪੂਰਨ nMaxFit;
  } GCP_RESULTSA,*LPGCP_RESULTSA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_GCP_RESULTSW {
    DWORD l_Struct_ਮਾਪ;
    LPWSTR lp_ਬਾਹਰਲਾ_String;
    UINT *lp_ਕ੍ਰਮ;
    ਪੂਰਨ *lpDx;
    ਪੂਰਨ *lpCaretPos;
    LPSTR lpClass;
    LPWSTR lpGlyphs;
    UINT nGlyphs;
    ਪੂਰਨ nMaxFit;
  } GCP_RESULTSW,*LPGCP_RESULTSW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ GCP_RESULTSW GCP_RESULTS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPGCP_RESULTSW LPGCP_RESULTS;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ GCP_RESULTSA GCP_RESULTS;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPGCP_RESULTSA LPGCP_RESULTS;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ RASTERIZER_ਸਥਿਤੀ {
    ਛੋਟਾ n_ਮਾਪ;
    ਛੋਟਾ wFlags;
    ਛੋਟਾ nLanguageID;
  } RASTERIZER_ਸਥਿਤੀ_2,*LPRASTERIZER_ਸਥਿਤੀ;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TT_ਉਪਲਬਧ 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ TT_ENABLED 0x0002

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_PIXELFORMATDESCRIPTOR {
    ਸ਼ਬਦ_3 n_ਮਾਪ;
    ਸ਼ਬਦ_3 n_ਸੰਸਕਰਣ;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_ਬਿੱਟ;
    BYTE c_Red_ਬਿੱਟ;
    BYTE c_Red_ਖਿਸਕਾਓ;
    BYTE c_Green_ਬਿੱਟ;
    BYTE c_Green_ਖਿਸਕਾਓ;
    BYTE c_Blue_ਬਿੱਟ;
    BYTE c_Blue_ਖਿਸਕਾਓ;
    BYTE c_Alpha_ਬਿੱਟ;
    BYTE c_Alpha_ਖਿਸਕਾਓ;
    BYTE c_Accum_ਬਿੱਟ;
    BYTE c_Accum_Red_ਬਿੱਟ;
    BYTE c_Accum_Green_ਬਿੱਟ;
    BYTE c_Accum_Blue_ਬਿੱਟ;
    BYTE c_Accum_Alpha_ਬਿੱਟ;
    BYTE c_ਡੂੰਘਾਈ_ਬਿੱਟ;
    BYTE c_Stencil_ਬਿੱਟ;
    BYTE cAuxBuffers;
    BYTE iLayerType;
    BYTE bReserved;
    DWORD dw_Layer_ਨਕਾਬ;
    DWORD dw_Visible_ਨਕਾਬ;
    DWORD dw_Damage_ਨਕਾਬ;
  } PIXELFORMATDESCRIPTOR,*PPIXELFORMATDESCRIPTOR,*LPPIXELFORMATDESCRIPTOR;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_TYPE_RGBA 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_TYPE_COLORINDEX 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_MAIN_PLANE 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_OVERLAY_PLANE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_UNDERLAY_PLANE (-1)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_DOUBLEBUFFER 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_STEREO 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_DRAW_ਮੰਜ਼ਿਲ_ਖਿੜਕੀ 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_DRAW_ਮੰਜ਼ਿਲ_BITMAP 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_SUPPORT_GDI 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_SUPPORT_OPENGL 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_GENERIC_FORMAT 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_NEED_PALETTE 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_NEED_SYSTEM_PALETTE 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_ਅਦਲਾ_ਬਦਲੀ_EXCHANGE 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_ਅਦਲਾ_ਬਦਲੀ_COPY 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_ਅਦਲਾ_ਬਦਲੀ_LAYER_BUFFERS 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_GENERIC_ACCELERATED 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_SUPPORT_DIRECTDRAW 0x00002000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_ਡੂੰਘਾਈ_DONTCARE 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_DOUBLEBUFFER_DONTCARE 0x40000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PFD_STEREO_DONTCARE 0x80000000

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOTEXTMETRIC
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST TEXTMETRICA *,DWORD,LPARAM);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST TEXTMETRICW *,DWORD,LPARAM);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OLDFONTENUMPROC OLDFONTENUMPROCW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OLDFONTENUMPROC OLDFONTENUMPROCA
#ਜੇ_ਅੰਤ
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *OLDFONTENUMPROCA)(CONST LOGFONTA *,CONST VOID *,DWORD,LPARAM);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *OLDFONTENUMPROCW)(CONST LOGFONTW *,CONST VOID *,DWORD,LPARAM);
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OLDFONTENUMPROC OLDFONTENUMPROCW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OLDFONTENUMPROC OLDFONTENUMPROCA
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ OLDFONTENUMPROCA FONTENUMPROCA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ OLDFONTENUMPROCW FONTENUMPROCW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ FONTENUMPROCW FONTENUMPROC;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ FONTENUMPROCA FONTENUMPROC;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *GOBJENUMPROC)(LPVOID,LPARAM);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ VOID (CALLBACK *LINEDDAPROC)(ਪੂਰਨ,ਪੂਰਨ,LPARAM);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Font_Resource ਜੋੜੋ_Font_Resource_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CopyMetaFile CopyMetaFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDC CreateDCW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Font_ਅਸਿੱਧਾ Create_Font_ਅਸਿੱਧਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateFont CreateFontW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateIC CreateICW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateMetaFile CreateMetaFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateScalableFontResource CreateScalableFontResourceW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Font_Resource ਜੋੜੋ_Font_Resource_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CopyMetaFile CopyMetaFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateDC CreateDCA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Font_ਅਸਿੱਧਾ Create_Font_ਅਸਿੱਧਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateFont CreateFontA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateIC CreateICA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateMetaFile CreateMetaFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateScalableFontResource CreateScalableFontResourceA
#ਜੇ_ਅੰਤ

  WINGDIAPI ਪੂਰਨ WINAPI ਜੋੜੋ_Font_Resource_A(LPCSTR);
  WINGDIAPI ਪੂਰਨ WINAPI ਜੋੜੋ_Font_Resource_W(LPCWSTR);
  WINGDIAPI WINBOOL WINAPI AnimatePalette(HPALETTE hPal,UINT i_ਸ਼ੁਰੂ_ਸੂਚਕਾਂਕ,UINT cEntries,CONST PALETTEENTRY *ppe);
  WINGDIAPI WINBOOL WINAPI Arc(HDC hdc,ਪੂਰਨ x1,ਪੂਰਨ y1,ਪੂਰਨ x2,ਪੂਰਨ y2,ਪੂਰਨ x3,ਪੂਰਨ y3,ਪੂਰਨ x4,ਪੂਰਨ y4);
  WINGDIAPI WINBOOL WINAPI ਦੋਆਧਾਰੀ_ਅੰਕ_Blt(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,ਪੂਰਨ cx,ਪੂਰਨ cy,HDC hdcSrc,ਪੂਰਨ x1,ਪੂਰਨ y1,DWORD rop);
  WINGDIAPI WINBOOL WINAPI CancelDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Chord(HDC hdc,ਪੂਰਨ x1,ਪੂਰਨ y1,ਪੂਰਨ x2,ਪੂਰਨ y2,ਪੂਰਨ x3,ਪੂਰਨ y3,ਪੂਰਨ x4,ਪੂਰਨ y4);
  WINGDIAPI ਪੂਰਨ WINAPI ਚੁਣੋ_Pixel_Format(HDC hdc,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI HMETAFILE WINAPI CloseMetaFile(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI CombineRgn(HRGN hrgnDst,HRGN hrgnSrc1,HRGN hrgnSrc2,ਪੂਰਨ i_ਬਹੁਲਕ);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileA(HMETAFILE,LPCSTR);
  WINGDIAPI HMETAFILE WINAPI CopyMetaFileW(HMETAFILE,LPCWSTR);
  WINGDIAPI HBITMAP WINAPI CreateBitmap(ਪੂਰਨ n_ਚੌੜਾਈ,ਪੂਰਨ n_ਉਚਾਈ,UINT nPlanes,UINT n_ਦੋਆਧਾਰੀ_ਅੰਕ_ਗਿਣਤੀ,CONST VOID *lp_ਬਿੱਟ);
  WINGDIAPI HBITMAP WINAPI Create_Bitmap_ਅਸਿੱਧਾ(CONST BITMAP *pbm);
  WINGDIAPI HBRUSH WINAPI Create_Brush_ਅਸਿੱਧਾ(CONST LOGBRUSH *plbrush);
  WINGDIAPI HBITMAP WINAPI CreateCompatibleBitmap(HDC hdc,ਪੂਰਨ cx,ਪੂਰਨ cy);
  WINGDIAPI HBITMAP WINAPI CreateDiscardableBitmap(HDC hdc,ਪੂਰਨ cx,ਪੂਰਨ cy);
  WINGDIAPI HDC WINAPI CreateCompatibleDC(HDC hdc);
  WINGDIAPI HDC WINAPI CreateDCA(LPCSTR pwszDriver,LPCSTR pwszDevice,LPCSTR psz_ਪੋਰਟ,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateDCW(LPCWSTR pwszDriver,LPCWSTR pwszDevice,LPCWSTR psz_ਪੋਰਟ,CONST DEVMODEW *pdm);
  WINGDIAPI HBITMAP WINAPI CreateDIBitmap(HDC hdc,CONST BITMAPINFOHEADER *pbmih,DWORD flInit,CONST VOID *pj_ਬਿੱਟ,CONST BITMAPINFO *pbmi,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrush(HGLOBAL h,UINT iUsage);
  WINGDIAPI HBRUSH WINAPI CreateDIBPatternBrushPt(CONST VOID *lpPackedDIB,UINT iUsage);
  WINGDIAPI HRGN WINAPI CreateEllipticRgn(ਪੂਰਨ x1,ਪੂਰਨ y1,ਪੂਰਨ x2,ਪੂਰਨ y2);
  WINGDIAPI HRGN WINAPI Create_Elliptic_Rgn_ਅਸਿੱਧਾ(CONST RECT *lprect);
  WINGDIAPI HFONT WINAPI Create_Font_ਅਸਿੱਧਾ_A(CONST LOGFONTA *lplf);
  WINGDIAPI HFONT WINAPI Create_Font_ਅਸਿੱਧਾ_W(CONST LOGFONTW *lplf);
  WINGDIAPI HFONT WINAPI CreateFontA(ਪੂਰਨ c_ਉਚਾਈ,ਪੂਰਨ c_ਚੌੜਾਈ,ਪੂਰਨ cEscapement,ਪੂਰਨ cOrientation,ਪੂਰਨ c_ਭਾਰ,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_ਬਾਹਰਲਾ,DWORD i_Char_ਸੈੱਟ,DWORD i_ਬਾਹਰਲਾ_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCSTR pszFaceName);
  WINGDIAPI HFONT WINAPI CreateFontW(ਪੂਰਨ c_ਉਚਾਈ,ਪੂਰਨ c_ਚੌੜਾਈ,ਪੂਰਨ cEscapement,ਪੂਰਨ cOrientation,ਪੂਰਨ c_ਭਾਰ,DWORD bItalic,DWORD bUnderline,DWORD b_Strike_ਬਾਹਰਲਾ,DWORD i_Char_ਸੈੱਟ,DWORD i_ਬਾਹਰਲਾ_Precision,DWORD iClipPrecision,DWORD iQuality,DWORD iPitchAndFamily,LPCWSTR pszFaceName);
  WINGDIAPI HBRUSH WINAPI CreateHatchBrush(ਪੂਰਨ iHatch,COLORREF color);
  WINGDIAPI HDC WINAPI CreateICA(LPCSTR pszDriver,LPCSTR pszDevice,LPCSTR psz_ਪੋਰਟ,CONST DEVMODEA *pdm);
  WINGDIAPI HDC WINAPI CreateICW(LPCWSTR pszDriver,LPCWSTR pszDevice,LPCWSTR psz_ਪੋਰਟ,CONST DEVMODEW *pdm);
  WINGDIAPI HDC WINAPI CreateMetaFileA(LPCSTR pszFile);
  WINGDIAPI HDC WINAPI CreateMetaFileW(LPCWSTR pszFile);
  WINGDIAPI HPALETTE WINAPI CreatePalette(CONST LOGPALETTE *plpal);
  WINGDIAPI HPEN WINAPI CreatePen(ਪੂਰਨ iStyle,ਪੂਰਨ c_ਚੌੜਾਈ,COLORREF color);
  WINGDIAPI HPEN WINAPI Create_Pen_ਅਸਿੱਧਾ(CONST LOGPEN *plpen);
  WINGDIAPI HRGN WINAPI CreatePolyPolygonRgn(CONST ਬਿੰਦੂ_3 *pptl,CONST INT *pc,ਪੂਰਨ cPoly,ਪੂਰਨ i_ਬਹੁਲਕ);
  WINGDIAPI HBRUSH WINAPI Create_ਨਮੂਨਾ_Brush(HBITMAP hbm);
  WINGDIAPI HRGN WINAPI CreateRectRgn(ਪੂਰਨ x1,ਪੂਰਨ y1,ਪੂਰਨ x2,ਪੂਰਨ y2);
  WINGDIAPI HRGN WINAPI Create_Rect_Rgn_ਅਸਿੱਧਾ(CONST RECT *lprect);
  WINGDIAPI HRGN WINAPI Create_ਗੇੜਾ_Rect_Rgn(ਪੂਰਨ x1,ਪੂਰਨ y1,ਪੂਰਨ x2,ਪੂਰਨ y2,ਪੂਰਨ w,ਪੂਰਨ h);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceA(DWORD fdwHidden,LPCSTR lpszFont,LPCSTR lpszFile,LPCSTR lpsz_ਰਸਤਾ);
  WINGDIAPI WINBOOL WINAPI CreateScalableFontResourceW(DWORD fdwHidden,LPCWSTR lpszFont,LPCWSTR lpszFile,LPCWSTR lpsz_ਰਸਤਾ);
  WINGDIAPI HBRUSH WINAPI CreateSolidBrush(COLORREF color);
  WINGDIAPI WINBOOL WINAPI DeleteDC(HDC hdc);
  WINGDIAPI WINBOOL WINAPI DeleteMetaFile(HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI DeleteObject(HGDIOBJ ho);
  WINGDIAPI ਪੂਰਨ WINAPI DescribePixelFormat(HDC hdc,ਪੂਰਨ iPixelFormat,UINT n_ਬਾਈਟਾਂ,LPPIXELFORMATDESCRIPTOR ppfd);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ UINT (CALLBACK *LPFNDEVMODE)(HWND,HMODULE,LPDEVMODE,LPSTR,LPSTR,LPDEVMODE,LPSTR,UINT);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DWORD (CALLBACK *LPFNDEVCAPS)(LPSTR,LPSTR,UINT,LPSTR,LPDEVMODE);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_UPDATE 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_COPY 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_PROMPT 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_MODIFY 8

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_ਵਿੱਚ_ਬਫਰ DM_MODIFY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_ਵਿੱਚ_PROMPT DM_PROMPT
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_ਬਾਹਰਲਾ_ਬਫਰ DM_COPY
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DM_ਬਾਹਰਲਾ_DEFAULT DM_UPDATE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_FIELDS 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_PAPERS 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_PAPERSIZE 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_MINEXTENT 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_MAXEXTENT 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_BINS 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_DUPLEX 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_ਮਾਪ 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_EXTRA 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_ਸੰਸਕਰਣ 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_DRIVER 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_BINNAMES 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_ENUMRESOLUTIONS 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_FILEDEPENDENCIES 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_TRUETYPE 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_PAPERNAMES 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_ORIENTATION 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_COPIES 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_BINADJUST 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_EMF_COMPLIANT 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_DATATYPE_PRODUCED 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_COLLATE 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_MANUFACTURER 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_MODEL 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_PERSONALITY 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_PRINTRATE 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_PRINTRATEUNIT 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRINTRATEUNIT_PPM 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRINTRATEUNIT_CPS 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRINTRATEUNIT_LPM 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PRINTRATEUNIT_IPM 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_PRINTERMEM 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_MEDIAREADY 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_STAPLE 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_PRINTRATEPPM 31
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_COLORDEVICE 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_NUP 33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_MEDIATYPENAMES 34
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DC_MEDIATYPES 35

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCTT_BITMAP 0x0000001L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCTT_DOWNLOAD 0x0000002L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCTT_SUBDEV 0x0000004L
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCTT_DOWNLOAD_OUTLINE 0x0000008L

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCBA_FACEUPNONE 0x0000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCBA_FACEUPCENTER 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCBA_FACEUPLEFT 0x0002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCBA_FACEUPRIGHT 0x0003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCBA_FACEDOWNNONE 0x0100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCBA_FACEDOWNCENTER 0x0101
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCBA_FACEDOWNLEFT 0x0102
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DCBA_FACEDOWNRIGHT 0x0103

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DeviceCapabilities DeviceCapabilitiesW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumFontFamiliesEx EnumFontFamiliesExW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumFontFamilies EnumFontFamiliesW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumFonts EnumFontsW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Char_ਚੌੜਾਈ Get_Char_ਚੌੜਾਈ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCharWidth32 GetCharWidth32W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Char_ਚੌੜਾਈ_Float Get_Char_ਚੌੜਾਈ_Float_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCharABCWidths GetCharABCWidthsW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCharABCWidthsFloat GetCharABCWidthsFloatW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetGlyphOutline GetGlyphOutlineW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetMetaFile GetMetaFileW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DeviceCapabilities DeviceCapabilitiesA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumFontFamiliesEx EnumFontFamiliesExA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumFontFamilies EnumFontFamiliesA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumFonts EnumFontsA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Char_ਚੌੜਾਈ Get_Char_ਚੌੜਾਈ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCharWidth32 GetCharWidth32A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Char_ਚੌੜਾਈ_Float Get_Char_ਚੌੜਾਈ_Float_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCharABCWidths GetCharABCWidthsA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCharABCWidthsFloat GetCharABCWidthsFloatA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetGlyphOutline GetGlyphOutlineA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetMetaFile GetMetaFileA
#ਜੇ_ਅੰਤ

  WINSPOOLAPI ਪੂਰਨ WINAPI DeviceCapabilitiesA(LPCSTR pDevice,LPCSTR p_ਪੋਰਟ,ਸ਼ਬਦ_3 fwCapability,LPSTR pOutput,CONST DEVMODEA *p_Dev_ਬਹੁਲਕ);
  WINSPOOLAPI ਪੂਰਨ WINAPI DeviceCapabilitiesW(LPCWSTR pDevice,LPCWSTR p_ਪੋਰਟ,ਸ਼ਬਦ_3 fwCapability,LPWSTR pOutput,CONST DEVMODEW *p_Dev_ਬਹੁਲਕ);
  WINGDIAPI ਪੂਰਨ WINAPI DrawEscape(HDC hdc,ਪੂਰਨ iEscape,ਪੂਰਨ cj_ਵਿੱਚ,LPCSTR lp_ਵਿੱਚ);
  WINGDIAPI WINBOOL WINAPI Ellipse(HDC hdc,ਪੂਰਨ ਖੱਬਾ,ਪੂਰਨ ਸਿਖਰ,ਪੂਰਨ ਸੱਜਾ,ਪੂਰਨ bottom);
  WINGDIAPI ਪੂਰਨ WINAPI EnumFontFamiliesExA(HDC hdc,LPLOGFONTA lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI ਪੂਰਨ WINAPI EnumFontFamiliesExW(HDC hdc,LPLOGFONTW lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam,DWORD dwFlags);
  WINGDIAPI ਪੂਰਨ WINAPI EnumFontFamiliesA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI ਪੂਰਨ WINAPI EnumFontFamiliesW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI ਪੂਰਨ WINAPI EnumFontsA(HDC hdc,LPCSTR lpLogfont,FONTENUMPROCA lpProc,LPARAM lParam);
  WINGDIAPI ਪੂਰਨ WINAPI EnumFontsW(HDC hdc,LPCWSTR lpLogfont,FONTENUMPROCW lpProc,LPARAM lParam);
  WINGDIAPI ਪੂਰਨ WINAPI EnumObjects(HDC hdc,ਪੂਰਨ nType,GOBJENUMPROC lpFunc,LPARAM lParam);
  WINGDIAPI WINBOOL WINAPI EqualRgn(HRGN hrgn1,HRGN hrgn2);
  WINGDIAPI ਪੂਰਨ WINAPI Escape(HDC hdc,ਪੂਰਨ iEscape,ਪੂਰਨ cj_ਵਿੱਚ,LPCSTR pv_ਵਿੱਚ,LPVOID pv_ਬਾਹਰਲਾ);
  WINGDIAPI ਪੂਰਨ WINAPI ExtEscape(HDC hdc,ਪੂਰਨ iEscape,ਪੂਰਨ cj_ਨਿਵੇਸ਼,LPCSTR lp_ਵਿੱਚ_ਅੰਕੜੇ,ਪੂਰਨ cjOutput,LPSTR lp_ਬਾਹਰਲਾ_ਅੰਕੜੇ);
  WINGDIAPI ਪੂਰਨ WINAPI ExcludeClipRect(HDC hdc,ਪੂਰਨ ਖੱਬਾ,ਪੂਰਨ ਸਿਖਰ,ਪੂਰਨ ਸੱਜਾ,ਪੂਰਨ bottom);
  WINGDIAPI HRGN WINAPI ExtCreateRegion(CONST XFORM *lpx,DWORD n_ਗਿਣਤੀ,CONST RGNDATA *lp_ਅੰਕੜੇ);
  WINGDIAPI WINBOOL WINAPI ExtFloodFill(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,COLORREF color,UINT type);
  WINGDIAPI WINBOOL WINAPI FillRgn(HDC hdc,HRGN hrgn,HBRUSH hbr);
  WINGDIAPI WINBOOL WINAPI FloodFill(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI ਚੌਖਟਾ_Rgn(HDC hdc,HRGN hrgn,HBRUSH hbr,ਪੂਰਨ w,ਪੂਰਨ h);
  WINGDIAPI ਪੂਰਨ WINAPI GetROP2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_Aspect_ਅਨੁਪਾਤ_Filter_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI COLORREF WINAPI GetBkColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCBrushColor(HDC hdc);
  WINGDIAPI COLORREF WINAPI GetDCPenColor(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI Get_Bk_ਬਹੁਲਕ(HDC hdc);
  WINGDIAPI LONG WINAPI Get_Bitmap_ਬਿੱਟ(HBITMAP hbit,LONG cb,LPVOID lpv_ਬਿੱਟ);
  WINGDIAPI WINBOOL WINAPI GetBitmapDimensionEx(HBITMAP hbit,LPSIZE lpsize);
  WINGDIAPI UINT WINAPI GetBoundsRect(HDC hdc,LPRECT lprect,UINT flags);
  WINGDIAPI WINBOOL WINAPI GetBrushOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI Get_Char_ਚੌੜਾਈ_A(HDC hdc,UINT i_ਪਹਿਲਾ,UINT i_ਆਖਰੀ,LPINT lp_ਬਫਰ);
  WINGDIAPI WINBOOL WINAPI Get_Char_ਚੌੜਾਈ_W(HDC hdc,UINT i_ਪਹਿਲਾ,UINT i_ਆਖਰੀ,LPINT lp_ਬਫਰ);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32A(HDC hdc,UINT i_ਪਹਿਲਾ,UINT i_ਆਖਰੀ,LPINT lp_ਬਫਰ);
  WINGDIAPI WINBOOL WINAPI GetCharWidth32W(HDC hdc,UINT i_ਪਹਿਲਾ,UINT i_ਆਖਰੀ,LPINT lp_ਬਫਰ);
  WINGDIAPI WINBOOL WINAPI Get_Char_ਚੌੜਾਈ_Float_A(HDC hdc,UINT i_ਪਹਿਲਾ,UINT i_ਆਖਰੀ,PFLOAT lp_ਬਫਰ);
  WINGDIAPI WINBOOL WINAPI Get_Char_ਚੌੜਾਈ_Float_W(HDC hdc,UINT i_ਪਹਿਲਾ,UINT i_ਆਖਰੀ,PFLOAT lp_ਬਫਰ);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsA(HDC hdc,UINT w_ਪਹਿਲਾ,UINT w_ਆਖਰੀ,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsW(HDC hdc,UINT w_ਪਹਿਲਾ,UINT w_ਆਖਰੀ,LPABC lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatA(HDC hdc,UINT i_ਪਹਿਲਾ,UINT i_ਆਖਰੀ,LPABCFLOAT lpABC);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsFloatW(HDC hdc,UINT i_ਪਹਿਲਾ,UINT i_ਆਖਰੀ,LPABCFLOAT lpABC);
  WINGDIAPI ਪੂਰਨ WINAPI GetClipBox(HDC hdc,LPRECT lprect);
  WINGDIAPI ਪੂਰਨ WINAPI GetClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI ਪੂਰਨ WINAPI GetMetaRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI HGDIOBJ WINAPI GetCurrentObject(HDC hdc,UINT type);
  WINGDIAPI WINBOOL WINAPI GetCurrentPositionEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI ਪੂਰਨ WINAPI GetDeviceCaps(HDC hdc,ਪੂਰਨ ਸੂਚਕਾਂਕ);
  WINGDIAPI ਪੂਰਨ WINAPI GetDIBits(HDC hdc,HBITMAP hbm,UINT ਸ਼ੁਰੂ,UINT c_ਸਤਰਾਂ,LPVOID lpv_ਬਿੱਟ,LPBITMAPINFO lpbmi,UINT usage);
  WINGDIAPI DWORD WINAPI Get_Font_ਅੰਕੜੇ (HDC hdc,DWORD dw_ਸਾਰਣੀ,DWORD dw_ਵਿੱਥ,PVOID pv_ਬਫਰ,DWORD cj_ਬਫਰ);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineA(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_ਬਫਰ,LPVOID pv_ਬਫਰ,CONST MAT2 *lpmat2);
  WINGDIAPI DWORD WINAPI GetGlyphOutlineW(HDC hdc,UINT uChar,UINT fuFormat,LPGLYPHMETRICS lpgm,DWORD cj_ਬਫਰ,LPVOID pv_ਬਫਰ,CONST MAT2 *lpmat2);
  WINGDIAPI ਪੂਰਨ WINAPI Get_Graphics_ਬਹੁਲਕ(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI Get_Map_ਬਹੁਲਕ(HDC hdc);
  WINGDIAPI UINT WINAPI Get_Meta_File_ਬਿੱਟ_Ex(HMETAFILE hMF,UINT cb_ਬਫਰ,LPVOID lp_ਅੰਕੜੇ);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileA(LPCSTR lpName);
  WINGDIAPI HMETAFILE WINAPI GetMetaFileW(LPCWSTR lpName);
  WINGDIAPI COLORREF WINAPI Get_ਸਭ_ਤੋਂ_ਨੇੜੇ_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI Get_ਸਭ_ਤੋਂ_ਨੇੜੇ_Palette_ਸੂਚਕਾਂਕ(HPALETTE h,COLORREF color);
  WINGDIAPI DWORD WINAPI GetObjectType(HGDIOBJ h);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOTEXTMETRIC
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Outline_ਪਾਠ_Metrics Get_Outline_ਪਾਠ_Metrics_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Outline_ਪਾਠ_Metrics Get_Outline_ਪਾਠ_Metrics_A
#ਜੇ_ਅੰਤ

  WINGDIAPI UINT WINAPI Get_Outline_ਪਾਠ_Metrics_A(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICA potm);
  WINGDIAPI UINT WINAPI Get_Outline_ਪਾਠ_Metrics_W(HDC hdc,UINT cjCopy,LPOUTLINETEXTMETRICW potm);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Extent_ਬਿੰਦੂ Get_ਪਾਠ_Extent_ਬਿੰਦੂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Extent_Point32 Get_ਪਾਠ_Extent_Point32_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Extent_Ex_ਬਿੰਦੂ Get_ਪਾਠ_Extent_Ex_ਬਿੰਦੂ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCharacterPlacement GetCharacterPlacementW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Extent_ਬਿੰਦੂ Get_ਪਾਠ_Extent_ਬਿੰਦੂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Extent_Point32 Get_ਪਾਠ_Extent_Point32_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Extent_Ex_ਬਿੰਦੂ Get_ਪਾਠ_Extent_Ex_ਬਿੰਦੂ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetCharacterPlacement GetCharacterPlacementA
#ਜੇ_ਅੰਤ

  WINGDIAPI UINT WINAPI GetPaletteEntries(HPALETTE hpal,UINT i_ਸ਼ੁਰੂ,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI COLORREF WINAPI GetPixel(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y);
  WINGDIAPI ਪੂਰਨ WINAPI GetPixelFormat(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI Get_Poly_Fill_ਬਹੁਲਕ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetRasterizerCaps(LPRASTERIZER_ਸਥਿਤੀ lpraststat,UINT cj_ਬਾਈਟਾਂ);
  WINGDIAPI ਪੂਰਨ WINAPI GetRandomRgn (HDC hdc,HRGN hrgn,INT i);
  WINGDIAPI DWORD WINAPI Get_Region_ਅੰਕੜੇ(HRGN hrgn,DWORD n_ਗਿਣਤੀ,LPRGNDATA lp_Rgn_ਅੰਕੜੇ);
  WINGDIAPI ਪੂਰਨ WINAPI GetRgnBox(HRGN hrgn,LPRECT lprc);
  WINGDIAPI HGDIOBJ WINAPI GetStockObject(ਪੂਰਨ i);
  WINGDIAPI ਪੂਰਨ WINAPI Get_Stretch_Blt_ਬਹੁਲਕ(HDC hdc);
  WINGDIAPI UINT WINAPI GetSystemPaletteEntries(HDC hdc,UINT i_ਸ਼ੁਰੂ,UINT cEntries,LPPALETTEENTRY pPalEntries);
  WINGDIAPI UINT WINAPI GetSystemPaletteUse(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI Get_ਪਾਠ_Character_Extra(HDC hdc);
  WINGDIAPI UINT WINAPI Get_ਪਾਠ_Align(HDC hdc);
  WINGDIAPI COLORREF WINAPI Get_ਪਾਠ_Color(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Extent_ਬਿੰਦੂ_A(HDC hdc,LPCSTR lpString,ਪੂਰਨ c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Extent_ਬਿੰਦੂ_W(HDC hdc,LPCWSTR lpString,ਪੂਰਨ c,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Extent_Point32_A(HDC hdc,LPCSTR lpString,ਪੂਰਨ c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Extent_Point32_W(HDC hdc,LPCWSTR lpString,ਪੂਰਨ c,LPSIZE psizl);
  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Extent_Ex_ਬਿੰਦੂ_A(HDC hdc,LPCSTR lpszString,ਪੂਰਨ cchString,ਪੂਰਨ nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_ਮਾਪ);
  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Extent_Ex_ਬਿੰਦੂ_W(HDC hdc,LPCWSTR lpszString,ਪੂਰਨ cchString,ਪੂਰਨ nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_ਮਾਪ);
  WINGDIAPI ਪੂਰਨ WINAPI Get_ਪਾਠ_Charset(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI Get_ਪਾਠ_Charset_Info(HDC hdc,LPFONTSIGNATURE lpSig,DWORD dwFlags);
  WINGDIAPI WINBOOL WINAPI TranslateCharsetInfo(DWORD *lpSrc,LPCHARSETINFO lpCs,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetFontLanguageInfo(HDC hdc);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementA(HDC hdc,LPCSTR lpString,ਪੂਰਨ n_ਗਿਣਤੀ,ਪੂਰਨ nMexExtent,LPGCP_RESULTSA lpResults,DWORD dwFlags);
  WINGDIAPI DWORD WINAPI GetCharacterPlacementW(HDC hdc,LPCWSTR lpString,ਪੂਰਨ n_ਗਿਣਤੀ,ਪੂਰਨ nMexExtent,LPGCP_RESULTSW lpResults,DWORD dwFlags);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_WCRANGE {
    WCHAR wc_ਨੀਵਾਂ;
    USHORT cGlyphs;
  } WCRANGE,*PWCRANGE,*LPWCRANGE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_GLYPHSET {
    DWORD cbThis;
    DWORD flAccel;
    DWORD cGlyphsSupported;
    DWORD cRanges;
    WCRANGE ranges[1];
  } GLYPHSET,*PGLYPHSET,*LPGLYPHSET;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GS_8_ਦੋਆਧਾਰੀ_ਅੰਕ_INDICES 0x00000001

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GGI_MARK_NONEXISTING_GLYPHS 0X0001

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetGlyphIndices GetGlyphIndicesW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetGlyphIndices GetGlyphIndicesA
#ਜੇ_ਅੰਤ

  WINGDIAPI DWORD WINAPI GetFontUnicodeRanges(HDC hdc,LPGLYPHSET lpgs);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesA(HDC hdc,LPCSTR lpstr,ਪੂਰਨ c,LPWORD pgi,DWORD fl);
  WINGDIAPI DWORD WINAPI GetGlyphIndicesW(HDC hdc,LPCWSTR lpstr,ਪੂਰਨ c,LPWORD pgi,DWORD fl);
  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Extent_ਬਿੰਦੂ_I(HDC hdc,LPWORD pgi_ਵਿੱਚ,ਪੂਰਨ cgi,LPSIZE psize);
  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Extent_Ex_ਬਿੰਦੂ_I (HDC hdc,LPWORD lpwszString,ਪੂਰਨ cwchString,ਪੂਰਨ nMaxExtent,LPINT lpnFit,LPINT lpnDx,LPSIZE lp_ਮਾਪ);
  WINGDIAPI WINBOOL WINAPI Get_Char_ਚੌੜਾਈ_I(HDC hdc,UINT gi_ਪਹਿਲਾ,UINT cgi,LPWORD pgi,LPINT piWidths);
  WINGDIAPI WINBOOL WINAPI GetCharABCWidthsI(HDC hdc,UINT gi_ਪਹਿਲਾ,UINT cgi,LPWORD pgi,LPABC pabc);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STAMP_DESIGNVECTOR (0x8000000 + 'd' + ('v' << 8))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STAMP_AXESLIST (0x8000000 + 'a' + ('l' << 8))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_MAX_NUMAXES 16

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_DESIGNVECTOR {
    DWORD dvReserved;
    DWORD dv_ਅੰਕ_Axes;
    LONG dv_ਮੁੱਲਾਂ[MM_MAX_NUMAXES];
  } DESIGNVECTOR,*PDESIGNVECTOR,*LPDESIGNVECTOR;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Font_Resource_Ex ਜੋੜੋ_Font_Resource_Ex_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RemoveFontResourceEx RemoveFontResourceExW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਜੋੜੋ_Font_Resource_Ex ਜੋੜੋ_Font_Resource_Ex_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RemoveFontResourceEx RemoveFontResourceExA
#ਜੇ_ਅੰਤ

  WINGDIAPI ਪੂਰਨ WINAPI ਜੋੜੋ_Font_Resource_Ex_A(LPCSTR name,DWORD fl,PVOID res);
  WINGDIAPI ਪੂਰਨ WINAPI ਜੋੜੋ_Font_Resource_Ex_W(LPCWSTR name,DWORD fl,PVOID res);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExA(LPCSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceExW(LPCWSTR name,DWORD fl,PVOID pdv);
  WINGDIAPI HANDLE WINAPI ਜੋੜੋ_Font_Mem_Resource_Ex(PVOID pFileView,DWORD cj_ਮਾਪ,PVOID pvResrved,DWORD *p_ਅੰਕ_Fonts);
  WINGDIAPI WINBOOL WINAPI RemoveFontMemResourceEx(HANDLE h);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FR_ਨਿੱਜੀ 0x10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FR_NOT_ENUM 0x20

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MM_MAX_AXES_NAMELEN 16

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_AXISINFOA {
    LONG ax_Min_ਮੁੱਲ;
    LONG ax_Max_ਮੁੱਲ;
    BYTE axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOA,*PAXISINFOA,*LPAXISINFOA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_AXISINFOW {
    LONG ax_Min_ਮੁੱਲ;
    LONG ax_Max_ਮੁੱਲ;
    WCHAR axAxisName[MM_MAX_AXES_NAMELEN];
  } AXISINFOW,*PAXISINFOW,*LPAXISINFOW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ AXISINFOW AXISINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PAXISINFOW PAXISINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPAXISINFOW LPAXISINFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ AXISINFOA AXISINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PAXISINFOA PAXISINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPAXISINFOA LPAXISINFO;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_AXESLISTA {
    DWORD axlReserved;
    DWORD axl_ਅੰਕ_Axes;
    AXISINFOA axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTA,*PAXESLISTA,*LPAXESLISTA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_AXESLISTW {
    DWORD axlReserved;
    DWORD axl_ਅੰਕ_Axes;
    AXISINFOW axlAxisInfo[MM_MAX_NUMAXES];
  } AXESLISTW,*PAXESLISTW,*LPAXESLISTW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ AXESLISTW AXESLIST;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PAXESLISTW PAXESLIST;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPAXESLISTW LPAXESLIST;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ AXESLISTA AXESLIST;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PAXESLISTA PAXESLIST;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPAXESLISTA LPAXESLIST;
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENUMLOGFONTEXDVA {
    ENUMLOGFONTEXA elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_ਸਦਿਸ਼;
  } ENUMLOGFONTEXDVA,*PENUMLOGFONTEXDVA,*LPENUMLOGFONTEXDVA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENUMLOGFONTEXDVW {
    ENUMLOGFONTEXW elfEnumLogfontEx;
    DESIGNVECTOR elf_Design_ਸਦਿਸ਼;
  } ENUMLOGFONTEXDVW,*PENUMLOGFONTEXDVW,*LPENUMLOGFONTEXDVW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ENUMLOGFONTEXDVW ENUMLOGFONTEXDV;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PENUMLOGFONTEXDVW PENUMLOGFONTEXDV;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPENUMLOGFONTEXDVW LPENUMLOGFONTEXDV;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ENUMLOGFONTEXDVA ENUMLOGFONTEXDV;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PENUMLOGFONTEXDVA PENUMLOGFONTEXDV;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPENUMLOGFONTEXDVA LPENUMLOGFONTEXDV;
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Font_ਅਸਿੱਧਾ_Ex Create_Font_ਅਸਿੱਧਾ_Ex_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Create_Font_ਅਸਿੱਧਾ_Ex Create_Font_ਅਸਿੱਧਾ_Ex_A
#ਜੇ_ਅੰਤ

  WINGDIAPI HFONT WINAPI Create_Font_ਅਸਿੱਧਾ_Ex_A(CONST ENUMLOGFONTEXDVA *);
  WINGDIAPI HFONT WINAPI Create_Font_ਅਸਿੱਧਾ_Ex_W(CONST ENUMLOGFONTEXDVW *);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOTEXTMETRIC
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENUMTEXTMETRICA {
    NEWTEXTMETRICEXA etm_New_ਪਾਠ_Metric_Ex;
    AXESLISTA etmAxesList;
  } ENUMTEXTMETRICA,*PENUMTEXTMETRICA,*LPENUMTEXTMETRICA;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ENUMTEXTMETRICW
  {
    NEWTEXTMETRICEXW etm_New_ਪਾਠ_Metric_Ex;
    AXESLISTW etmAxesList;
  } ENUMTEXTMETRICW,*PENUMTEXTMETRICW,*LPENUMTEXTMETRICW;
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ENUMTEXTMETRICW ENUMTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PENUMTEXTMETRICW PENUMTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPENUMTEXTMETRICW LPENUMTEXTMETRIC;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ENUMTEXTMETRICA ENUMTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ PENUMTEXTMETRICA PENUMTEXTMETRIC;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPENUMTEXTMETRICA LPENUMTEXTMETRIC;
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ResetDC ResetDCW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RemoveFontResource RemoveFontResourceW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ResetDC ResetDCA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RemoveFontResource RemoveFontResourceA
#ਜੇ_ਅੰਤ

  WINGDIAPI WINBOOL WINAPI GetViewportExtEx(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI GetViewportOrgEx(HDC hdc,LPPOINT lppoint);
  WINGDIAPI WINBOOL WINAPI Get_ਖਿੜਕੀ_Ext_Ex(HDC hdc,LPSIZE lpsize);
  WINGDIAPI WINBOOL WINAPI Get_ਖਿੜਕੀ_Org_Ex(HDC hdc,LPPOINT lppoint);
  WINGDIAPI ਪੂਰਨ WINAPI IntersectClipRect(HDC hdc,ਪੂਰਨ ਖੱਬਾ,ਪੂਰਨ ਸਿਖਰ,ਪੂਰਨ ਸੱਜਾ,ਪੂਰਨ bottom);
  WINGDIAPI WINBOOL WINAPI InvertRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI ਸਤਰ_DDA(ਪੂਰਨ x_ਸ਼ੁਰੂ,ਪੂਰਨ y_ਸ਼ੁਰੂ,ਪੂਰਨ x_ਸਿਰਾ,ਪੂਰਨ y_ਸਿਰਾ,LINEDDAPROC lpProc,LPARAM ਅੰਕੜੇ);
  WINGDIAPI WINBOOL WINAPI ਸਤਰ_ਮੰਜ਼ਿਲ(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y);
  WINGDIAPI WINBOOL WINAPI ਨਕਾਬ_Blt(HDC hdcDest,ਪੂਰਨ xDest,ਪੂਰਨ yDest,ਪੂਰਨ ਚੌੜਾਈ,ਪੂਰਨ ਉਚਾਈ,HDC hdcSrc,ਪੂਰਨ xSrc,ਪੂਰਨ ySrc,HBITMAP hbm_ਨਕਾਬ,ਪੂਰਨ x_ਨਕਾਬ,ਪੂਰਨ y_ਨਕਾਬ,DWORD rop);
  WINGDIAPI WINBOOL WINAPI PlgBlt(HDC hdcDest,CONST ਬਿੰਦੂ_3 *lp_ਬਿੰਦੂ,HDC hdcSrc,ਪੂਰਨ xSrc,ਪੂਰਨ ySrc,ਪੂਰਨ ਚੌੜਾਈ,ਪੂਰਨ ਉਚਾਈ,HBITMAP hbm_ਨਕਾਬ,ਪੂਰਨ x_ਨਕਾਬ,ਪੂਰਨ y_ਨਕਾਬ);
  WINGDIAPI ਪੂਰਨ WINAPI ਵਿੱਥ_Clip_Rgn(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y);
  WINGDIAPI ਪੂਰਨ WINAPI ਵਿੱਥ_Rgn(HRGN hrgn,ਪੂਰਨ x,ਪੂਰਨ y);
  WINGDIAPI WINBOOL WINAPI PatBlt(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,ਪੂਰਨ w,ਪੂਰਨ h,DWORD rop);
  WINGDIAPI WINBOOL WINAPI Pie(HDC hdc,ਪੂਰਨ ਖੱਬਾ,ਪੂਰਨ ਸਿਖਰ,ਪੂਰਨ ਸੱਜਾ,ਪੂਰਨ bottom,ਪੂਰਨ xr1,ਪੂਰਨ yr1,ਪੂਰਨ xr2,ਪੂਰਨ yr2);
  WINGDIAPI WINBOOL WINAPI PlayMetaFile(HDC hdc,HMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI PaintRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI WINBOOL WINAPI PolyPolygon(HDC hdc,CONST ਬਿੰਦੂ_3 *apt,CONST INT *asz,ਪੂਰਨ csz);
  WINGDIAPI WINBOOL WINAPI Pt_ਵਿੱਚ_Region(HRGN hrgn,ਪੂਰਨ x,ਪੂਰਨ y);
  WINGDIAPI WINBOOL WINAPI PtVisible(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y);
  WINGDIAPI WINBOOL WINAPI Rect_ਵਿੱਚ_Region(HRGN hrgn,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI RectVisible(HDC hdc,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Rectangle(HDC hdc,ਪੂਰਨ ਖੱਬਾ,ਪੂਰਨ ਸਿਖਰ,ਪੂਰਨ ਸੱਜਾ,ਪੂਰਨ bottom);
  WINGDIAPI WINBOOL WINAPI RestoreDC(HDC hdc,ਪੂਰਨ nSavedDC);
  WINGDIAPI HDC WINAPI ResetDCA(HDC hdc,CONST DEVMODEA *lpdm);
  WINGDIAPI HDC WINAPI ResetDCW(HDC hdc,CONST DEVMODEW *lpdm);
  WINGDIAPI UINT WINAPI RealizePalette(HDC hdc);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceA(LPCSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI RemoveFontResourceW(LPCWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI ਗੇੜਾ_Rect(HDC hdc,ਪੂਰਨ ਖੱਬਾ,ਪੂਰਨ ਸਿਖਰ,ਪੂਰਨ ਸੱਜਾ,ਪੂਰਨ bottom,ਪੂਰਨ ਚੌੜਾਈ,ਪੂਰਨ ਉਚਾਈ);
  WINGDIAPI WINBOOL WINAPI ResizePalette(HPALETTE hpal,UINT n);
  WINGDIAPI ਪੂਰਨ WINAPI SaveDC(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI SelectClipRgn(HDC hdc,HRGN hrgn);
  WINGDIAPI ਪੂਰਨ WINAPI ExtSelectClipRgn(HDC hdc,HRGN hrgn,ਪੂਰਨ ਬਹੁਲਕ);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Meta_Rgn(HDC hdc);
  WINGDIAPI HGDIOBJ WINAPI SelectObject(HDC hdc,HGDIOBJ h);
  WINGDIAPI HPALETTE WINAPI SelectPalette(HDC hdc,HPALETTE hPal,WINBOOL bForceBkgd);
  WINGDIAPI COLORREF WINAPI ਸੈੱਟ_Bk_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI ਸੈੱਟ_DCBrush_Color(HDC hdc,COLORREF color);
  WINGDIAPI COLORREF WINAPI ਸੈੱਟ_DCPen_Color(HDC hdc,COLORREF color);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Bk_ਬਹੁਲਕ(HDC hdc,ਪੂਰਨ ਬਹੁਲਕ);
  WINGDIAPI LONG WINAPI ਸੈੱਟ_Bitmap_ਬਿੱਟ(HBITMAP hbm,DWORD cb,CONST VOID *pv_ਬਿੱਟ);
  WINGDIAPI UINT WINAPI ਸੈੱਟ_Bounds_Rect(HDC hdc,CONST RECT *lprect,UINT flags);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_DIBits(HDC hdc,HBITMAP hbm,UINT ਸ਼ੁਰੂ,UINT c_ਸਤਰਾਂ,CONST VOID *lp_ਬਿੱਟ,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_DIBits_ਮੰਜ਼ਿਲ_Device(HDC hdc,ਪੂਰਨ xDest,ਪੂਰਨ yDest,DWORD w,DWORD h,ਪੂਰਨ xSrc,ਪੂਰਨ ySrc,UINT ਸ਼ੁਰੂ_ਜਾਂਚ,UINT c_ਸਤਰਾਂ,CONST VOID *lpv_ਬਿੱਟ,CONST BITMAPINFO *lpbmi,UINT ColorUse);
  WINGDIAPI DWORD WINAPI ਸੈੱਟ_Mapper_Flags(HDC hdc,DWORD flags);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Graphics_ਬਹੁਲਕ(HDC hdc,ਪੂਰਨ i_ਬਹੁਲਕ);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Map_ਬਹੁਲਕ(HDC hdc,ਪੂਰਨ i_ਬਹੁਲਕ);
  WINGDIAPI DWORD WINAPI ਸੈੱਟ_Layout(HDC hdc,DWORD l);
  WINGDIAPI DWORD WINAPI GetLayout(HDC hdc);
  WINGDIAPI HMETAFILE WINAPI ਸੈੱਟ_Meta_File_ਬਿੱਟ_Ex(UINT cb_ਬਫਰ,CONST BYTE *lp_ਅੰਕੜੇ);
  WINGDIAPI UINT WINAPI ਸੈੱਟ_Palette_Entries(HPALETTE hpal,UINT i_ਸ਼ੁਰੂ,UINT cEntries,CONST PALETTEENTRY *pPalEntries);
  WINGDIAPI COLORREF WINAPI ਸੈੱਟ_Pixel(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Pixel_V(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,COLORREF color);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Pixel_Format(HDC hdc,ਪੂਰਨ format,CONST PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Poly_Fill_ਬਹੁਲਕ(HDC hdc,ਪੂਰਨ ਬਹੁਲਕ);
  WINGDIAPI WINBOOL WINAPI StretchBlt(HDC hdcDest,ਪੂਰਨ xDest,ਪੂਰਨ yDest,ਪੂਰਨ wDest,ਪੂਰਨ hDest,HDC hdcSrc,ਪੂਰਨ xSrc,ਪੂਰਨ ySrc,ਪੂਰਨ wSrc,ਪੂਰਨ hSrc,DWORD rop);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Rect_Rgn(HRGN hrgn,ਪੂਰਨ ਖੱਬਾ,ਪੂਰਨ ਸਿਖਰ,ਪੂਰਨ ਸੱਜਾ,ਪੂਰਨ bottom);
  WINGDIAPI ਪੂਰਨ WINAPI StretchDIBits(HDC hdc,ਪੂਰਨ xDest,ਪੂਰਨ yDest,ਪੂਰਨ Dest_ਚੌੜਾਈ,ਪੂਰਨ Dest_ਉਚਾਈ,ਪੂਰਨ xSrc,ਪੂਰਨ ySrc,ਪੂਰਨ Src_ਚੌੜਾਈ,ਪੂਰਨ Src_ਉਚਾਈ,CONST VOID *lp_ਬਿੱਟ,CONST BITMAPINFO *lpbmi,UINT iUsage,DWORD rop);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_ROP2(HDC hdc,ਪੂਰਨ rop2);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Stretch_Blt_ਬਹੁਲਕ(HDC hdc,ਪੂਰਨ ਬਹੁਲਕ);
  WINGDIAPI UINT WINAPI ਸੈੱਟ_System_Palette_Use(HDC hdc,UINT use);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_ਪਾਠ_Character_Extra(HDC hdc,ਪੂਰਨ extra);
  WINGDIAPI COLORREF WINAPI ਸੈੱਟ_ਪਾਠ_Color(HDC hdc,COLORREF color);
  WINGDIAPI UINT WINAPI ਸੈੱਟ_ਪਾਠ_Align(HDC hdc,UINT align);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_ਪਾਠ_Justification(HDC hdc,ਪੂਰਨ extra,ਪੂਰਨ ਗਿਣਤੀ_3);
  WINGDIAPI WINBOOL WINAPI UpdateColors(HDC hdc);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ USHORT COLOR16;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _TRIVERTEX {
    LONG x;
    LONG y;
    COLOR16 Red;
    COLOR16 Green;
    COLOR16 Blue;
    COLOR16 Alpha;
  } TRIVERTEX,*PTRIVERTEX,*LPTRIVERTEX;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _GRADIENT_TRIANGLE {
    ULONG Vertex1;
    ULONG Vertex2;
    ULONG Vertex3;
  } GRADIENT_TRIANGLE,*PGRADIENT_TRIANGLE,*LPGRADIENT_TRIANGLE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _GRADIENT_RECT {
    ULONG ਉੱਤਲਾ_ਖੱਬਾ;
    ULONG ਹੇਠਲਾ_ਸੱਜਾ;
  } GRADIENT_RECT,*PGRADIENT_RECT,*LPGRADIENT_RECT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _BLENDFUNCTION {
    BYTE BlendOp;
    BYTE BlendFlags;
    BYTE ਸਰੋਤ_Constant_Alpha;
    BYTE AlphaFormat;
  } BLENDFUNCTION,*PBLENDFUNCTION;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AC_SRC_OVER 0x00
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AC_SRC_ALPHA 0x01

  WINGDIAPI WINBOOL WINAPI AlphaBlend(HDC hdcDest,ਪੂਰਨ xoriginDest,ਪੂਰਨ yoriginDest,ਪੂਰਨ wDest,ਪੂਰਨ hDest,HDC hdcSrc,ਪੂਰਨ xoriginSrc,ਪੂਰਨ yoriginSrc,ਪੂਰਨ wSrc,ਪੂਰਨ hSrc,BLENDFUNCTION ftn);
  WINGDIAPI WINBOOL WINAPI TransparentBlt(HDC hdcDest,ਪੂਰਨ xoriginDest,ਪੂਰਨ yoriginDest,ਪੂਰਨ wDest,ਪੂਰਨ hDest,HDC hdcSrc,ਪੂਰਨ xoriginSrc,ਪੂਰਨ yoriginSrc,ਪੂਰਨ wSrc,ਪੂਰਨ hSrc,UINT crTransparent);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GRADIENT_FILL_RECT_H 0x00000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GRADIENT_FILL_RECT_V 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GRADIENT_FILL_TRIANGLE 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GRADIENT_FILL_OP_FLAG 0x000000ff

  WINGDIAPI WINBOOL WINAPI GradientFill(HDC hdc,PTRIVERTEX p_ਸ਼ੀਰਸ਼,ULONG n_ਸ਼ੀਰਸ਼,PVOID pMesh,ULONG nMesh,ULONG ul_ਬਹੁਲਕ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMETAFILE

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CopyEnhMetaFile CopyEnhMetaFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateEnhMetaFile CreateEnhMetaFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetEnhMetaFile GetEnhMetaFileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CopyEnhMetaFile CopyEnhMetaFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateEnhMetaFile CreateEnhMetaFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetEnhMetaFile GetEnhMetaFileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
#ਜੇ_ਅੰਤ

  WINGDIAPI WINBOOL WINAPI Play_Meta_File_ਰਿਕਾਰਡ(HDC hdc,LPHANDLETABLE lp_Handle_ਸਾਰਣੀ,LPMETARECORD lpMR,UINT noObjs);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *MFENUMPROC)(HDC hdc,HANDLETABLE *lpht,METARECORD *lpMR,ਪੂਰਨ nObj,LPARAM param);

  WINGDIAPI WINBOOL WINAPI EnumMetaFile(HDC hdc,HMETAFILE hmf,MFENUMPROC proc,LPARAM param);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *ENHMFENUMPROC)(HDC hdc,HANDLETABLE *lpht,CONST ENHMETARECORD *lpmr,ਪੂਰਨ hHandles,LPARAM ਅੰਕੜੇ);

  WINGDIAPI HENHMETAFILE WINAPI CloseEnhMetaFile(HDC hdc);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileA(HENHMETAFILE hEnh,LPCSTR lpFileName);
  WINGDIAPI HENHMETAFILE WINAPI CopyEnhMetaFileW(HENHMETAFILE hEnh,LPCWSTR lpFileName);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileA(HDC hdc,LPCSTR lpFilename,CONST RECT *lprc,LPCSTR lpDesc);
  WINGDIAPI HDC WINAPI CreateEnhMetaFileW(HDC hdc,LPCWSTR lpFilename,CONST RECT *lprc,LPCWSTR lpDesc);
  WINGDIAPI WINBOOL WINAPI DeleteEnhMetaFile(HENHMETAFILE hmf);
  WINGDIAPI WINBOOL WINAPI EnumEnhMetaFile(HDC hdc,HENHMETAFILE hmf,ENHMFENUMPROC proc,LPVOID param,CONST RECT *lpRect);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileA(LPCSTR lpName);
  WINGDIAPI HENHMETAFILE WINAPI GetEnhMetaFileW(LPCWSTR lpName);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_ਬਿੱਟ(HENHMETAFILE hEMF,UINT n_ਮਾਪ,LPBYTE lp_ਅੰਕੜੇ);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionA(HENHMETAFILE hemf,UINT cch_ਬਫਰ,LPSTR lpDescription);
  WINGDIAPI UINT WINAPI GetEnhMetaFileDescriptionW(HENHMETAFILE hemf,UINT cch_ਬਫਰ,LPWSTR lpDescription);
  WINGDIAPI UINT WINAPI Get_Enh_Meta_File_ਸਿਰਲੇਖ(HENHMETAFILE hemf,UINT n_ਮਾਪ,LPENHMETAHEADER lp_Enh_Meta_ਸਿਰਲੇਖ);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePaletteEntries(HENHMETAFILE hemf,UINT n_ਅੰਕ_Entries,LPPALETTEENTRY lpPaletteEntries);
  WINGDIAPI UINT WINAPI GetEnhMetaFilePixelFormat(HENHMETAFILE hemf,UINT cb_ਬਫਰ,PIXELFORMATDESCRIPTOR *ppfd);
  WINGDIAPI UINT WINAPI Get_Win_Meta_File_ਬਿੱਟ(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT i_Map_ਬਹੁਲਕ,HDC hdcRef);
  WINGDIAPI WINBOOL WINAPI PlayEnhMetaFile(HDC hdc,HENHMETAFILE hmf,CONST RECT *lprect);
  WINGDIAPI WINBOOL WINAPI Play_Enh_Meta_File_ਰਿਕਾਰਡ(HDC hdc,LPHANDLETABLE pht,CONST ENHMETARECORD *pmr,UINT cht);
  WINGDIAPI HENHMETAFILE WINAPI ਸੈੱਟ_Enh_Meta_File_ਬਿੱਟ(UINT n_ਮਾਪ,CONST BYTE *pb);
  WINGDIAPI HENHMETAFILE WINAPI ਸੈੱਟ_Win_Meta_File_ਬਿੱਟ(UINT n_ਮਾਪ,CONST BYTE *lp_Meta16_ਅੰਕੜੇ,HDC hdcRef,CONST METAFILEPICT *lpMFP);
  WINGDIAPI WINBOOL WINAPI GdiComment(HDC hdc,UINT n_ਮਾਪ,CONST BYTE *lp_ਅੰਕੜੇ);
#ਜੇ_ਅੰਤ

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOTEXTMETRIC
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Metrics Get_ਪਾਠ_Metrics_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Metrics Get_ਪਾਠ_Metrics_A
#ਜੇ_ਅੰਤ

  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Metrics_A(HDC hdc,LPTEXTMETRICA lptm);
  WINGDIAPI WINBOOL WINAPI Get_ਪਾਠ_Metrics_W(HDC hdc,LPTEXTMETRICW lptm);
#ਜੇ_ਅੰਤ

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_DIBSECTION {
    BITMAP dsBm;
    BITMAPINFOHEADER dsBmih;
    DWORD dsBitfields[3];
    HANDLE dshSection;
    DWORD ds_ਵਿੱਥ;
  } DIBSECTION,*LPDIBSECTION,*PDIBSECTION;

  WINGDIAPI WINBOOL WINAPI AngleArc(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,DWORD r,FLOAT ਸ਼ੁਰੂ_Angle,FLOAT SweepAngle);
  WINGDIAPI WINBOOL WINAPI PolyPolyline(HDC hdc,CONST ਬਿੰਦੂ_3 *apt,CONST DWORD *asz,DWORD csz);
  WINGDIAPI WINBOOL WINAPI GetWorldTransform(HDC hdc,LPXFORM lpxf);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_World_Transform(HDC hdc,CONST XFORM *lpxf);
  WINGDIAPI WINBOOL WINAPI ModifyWorldTransform(HDC hdc,CONST XFORM *lpxf,DWORD ਬਹੁਲਕ);
  WINGDIAPI WINBOOL WINAPI CombineTransform(LPXFORM lpxf_ਬਾਹਰਲਾ,CONST XFORM *lpxf1,CONST XFORM *lpxf2);
  WINGDIAPI HBITMAP WINAPI CreateDIBSection(HDC hdc,CONST BITMAPINFO *lpbmi,UINT usage,VOID **ppv_ਬਿੱਟ,HANDLE hSection,DWORD ਵਿੱਥ);
  WINGDIAPI UINT WINAPI Get_DIBColor_ਸਾਰਣੀ(HDC hdc,UINT i_ਸ਼ੁਰੂ,UINT cEntries,RGBQUAD *prgbq);
  WINGDIAPI UINT WINAPI ਸੈੱਟ_DIBColor_ਸਾਰਣੀ(HDC hdc,UINT i_ਸ਼ੁਰੂ,UINT cEntries,CONST RGBQUAD *prgbq);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CA_NEGATIVE 0x0001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CA_LOG_FILTER 0x0002

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_DEVICE_DEFAULT 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_A 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_B 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_C 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_D50 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_D55 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_D65 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_D75 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_F2 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_MAX_ਸੂਚਕਾਂਕ ILLUMINANT_F2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_TUNGSTEN ILLUMINANT_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_DAYLIGHT ILLUMINANT_C
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_FLUORESCENT ILLUMINANT_F2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ILLUMINANT_NTSC ILLUMINANT_C

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGB_GAMMA_MIN (ਸ਼ਬਦ_3)02500
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RGB_GAMMA_MAX (ਸ਼ਬਦ_3)65000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFERENCE_WHITE_MIN (ਸ਼ਬਦ_3)6000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFERENCE_WHITE_MAX (ਸ਼ਬਦ_3)10000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFERENCE_BLACK_MIN (ਸ਼ਬਦ_3)0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REFERENCE_BLACK_MAX (ਸ਼ਬਦ_3)4000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_ADJ_MIN (SHORT)-100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLOR_ADJ_MAX (SHORT)100

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_COLORADJUSTMENT {
    ਸ਼ਬਦ_3 ca_ਮਾਪ;
    ਸ਼ਬਦ_3 caFlags;
    ਸ਼ਬਦ_3 ca_Illuminant_ਸੂਚਕਾਂਕ;
    ਸ਼ਬਦ_3 caRedGamma;
    ਸ਼ਬਦ_3 caGreenGamma;
    ਸ਼ਬਦ_3 caBlueGamma;
    ਸ਼ਬਦ_3 caReferenceBlack;
    ਸ਼ਬਦ_3 caReferenceWhite;
    SHORT caContrast;
    SHORT caBrightness;
    SHORT caColorfulness;
    SHORT caRedGreenTint;
  } COLORADJUSTMENT,*PCOLORADJUSTMENT,*LPCOLORADJUSTMENT;

  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Color_Adjustment(HDC hdc,CONST COLORADJUSTMENT *lpca);
  WINGDIAPI WINBOOL WINAPI GetColorAdjustment(HDC hdc,LPCOLORADJUSTMENT lpca);
  WINGDIAPI HPALETTE WINAPI CreateHalftonePalette(HDC hdc);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ WINBOOL (CALLBACK *ABORTPROC)(HDC,ਪੂਰਨ);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _DOCINFOA {
    ਪੂਰਨ cb_ਮਾਪ;
    LPCSTR lpszDocName;
    LPCSTR lpszOutput;
    LPCSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOA,*LPDOCINFOA;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _DOCINFOW {
    ਪੂਰਨ cb_ਮਾਪ;
    LPCWSTR lpszDocName;
    LPCWSTR lpszOutput;
    LPCWSTR lpszDatatype;
    DWORD fwType;
  } DOCINFOW,*LPDOCINFOW;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DOCINFOW DOCINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDOCINFOW LPDOCINFO;
#ਨਹੀਂਤਾਂ
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ DOCINFOA DOCINFO;
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ LPDOCINFOA LPDOCINFO;
#ਜੇ_ਅੰਤ

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DI_APPBANDING 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ DI_ROPS_READ_DESTINATION 0x00000002

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸ਼ੁਰੂ_Doc ਸ਼ੁਰੂ_Doc_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetObject GetObjectW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਾਠ_ਬਾਹਰਲਾ ਪਾਠ_ਬਾਹਰਲਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ext_ਪਾਠ_ਬਾਹਰਲਾ Ext_ਪਾਠ_ਬਾਹਰਲਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Poly_ਪਾਠ_ਬਾਹਰਲਾ Poly_ਪਾਠ_ਬਾਹਰਲਾ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Face Get_ਪਾਠ_Face_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸ਼ੁਰੂ_Doc ਸ਼ੁਰੂ_Doc_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetObject GetObjectA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਪਾਠ_ਬਾਹਰਲਾ ਪਾਠ_ਬਾਹਰਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Ext_ਪਾਠ_ਬਾਹਰਲਾ Ext_ਪਾਠ_ਬਾਹਰਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Poly_ਪਾਠ_ਬਾਹਰਲਾ Poly_ਪਾਠ_ਬਾਹਰਲਾ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_ਪਾਠ_Face Get_ਪਾਠ_Face_A
#ਜੇ_ਅੰਤ

  WINGDIAPI ਪੂਰਨ WINAPI ਸ਼ੁਰੂ_Doc_A(HDC hdc,CONST DOCINFOA *lpdi);
  WINGDIAPI ਪੂਰਨ WINAPI ਸ਼ੁਰੂ_Doc_W(HDC hdc,CONST DOCINFOW *lpdi);
  WINGDIAPI ਪੂਰਨ WINAPI ਸਿਰਾ_Doc(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI ਸ਼ੁਰੂ_ਪੰਨਾ(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI ਸਿਰਾ_ਪੰਨਾ(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI AbortDoc(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Abort_Proc(HDC hdc,ABORTPROC proc);
  WINGDIAPI WINBOOL WINAPI Abort_ਰਸਤਾ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Arc_ਮੰਜ਼ਿਲ(HDC hdc,ਪੂਰਨ ਖੱਬਾ,ਪੂਰਨ ਸਿਖਰ,ਪੂਰਨ ਸੱਜਾ,ਪੂਰਨ bottom,ਪੂਰਨ xr1,ਪੂਰਨ yr1,ਪੂਰਨ xr2,ਪੂਰਨ yr2);
  WINGDIAPI WINBOOL WINAPI Begin_ਰਸਤਾ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI CloseFigure(HDC hdc);
  WINGDIAPI WINBOOL WINAPI ਸਿਰਾ_ਰਸਤਾ_2(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Fill_ਰਸਤਾ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Flatten_ਰਸਤਾ(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI Get_ਰਸਤਾ(HDC hdc,LPPOINT apt,LPBYTE aj,ਪੂਰਨ cpt);
  WINGDIAPI HRGN WINAPI ਰਸਤਾ_ਮੰਜ਼ਿਲ_Region(HDC hdc);
  WINGDIAPI WINBOOL WINAPI PolyDraw(HDC hdc,CONST ਬਿੰਦੂ_3 *apt,CONST BYTE *aj,ਪੂਰਨ cpt);
  WINGDIAPI WINBOOL WINAPI Select_Clip_ਰਸਤਾ(HDC hdc,ਪੂਰਨ ਬਹੁਲਕ);
  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_Arc_Direction(HDC hdc,ਪੂਰਨ dir);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Miter_ਹੱਦਬੰਦੀ(HDC hdc,FLOAT ਹੱਦਬੰਦੀ,PFLOAT old);
  WINGDIAPI WINBOOL WINAPI Stroke_And_Fill_ਰਸਤਾ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Stroke_ਰਸਤਾ(HDC hdc);
  WINGDIAPI WINBOOL WINAPI Widen_ਰਸਤਾ(HDC hdc);
  WINGDIAPI HPEN WINAPI ExtCreatePen(DWORD iPenStyle,DWORD c_ਚੌੜਾਈ,CONST LOGBRUSH *plbrush,DWORD cStyle,CONST DWORD *pstyle);
  WINGDIAPI WINBOOL WINAPI Get_Miter_ਹੱਦਬੰਦੀ(HDC hdc,PFLOAT plimit);
  WINGDIAPI ਪੂਰਨ WINAPI GetArcDirection(HDC hdc);
  WINGDIAPI ਪੂਰਨ WINAPI GetObjectA(HANDLE h,ਪੂਰਨ c,LPVOID pv);
  WINGDIAPI ਪੂਰਨ WINAPI GetObjectW(HANDLE h,ਪੂਰਨ c,LPVOID pv);
  WINGDIAPI WINBOOL WINAPI Move_ਮੰਜ਼ਿਲ_Ex(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ਪਾਠ_ਬਾਹਰਲਾ_A(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPCSTR lpString,ਪੂਰਨ c);
  WINGDIAPI WINBOOL WINAPI ਪਾਠ_ਬਾਹਰਲਾ_W(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPCWSTR lpString,ਪੂਰਨ c);
  WINGDIAPI WINBOOL WINAPI Ext_ਪਾਠ_ਬਾਹਰਲਾ_A(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,UINT options,CONST RECT *lprect,LPCSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Ext_ਪਾਠ_ਬਾਹਰਲਾ_W(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,UINT options,CONST RECT *lprect,LPCWSTR lpString,UINT c,CONST INT *lpDx);
  WINGDIAPI WINBOOL WINAPI Poly_ਪਾਠ_ਬਾਹਰਲਾ_A(HDC hdc,CONST POLYTEXTA *ppt,ਪੂਰਨ nstrings);
  WINGDIAPI WINBOOL WINAPI Poly_ਪਾਠ_ਬਾਹਰਲਾ_W(HDC hdc,CONST POLYTEXTW *ppt,ਪੂਰਨ nstrings);
  WINGDIAPI HRGN WINAPI CreatePolygonRgn(CONST ਬਿੰਦੂ_3 *pptl,ਪੂਰਨ c_ਬਿੰਦੂ,ਪੂਰਨ i_ਬਹੁਲਕ);
  WINGDIAPI WINBOOL WINAPI DPtoLP(HDC hdc,LPPOINT lppt,ਪੂਰਨ c);
  WINGDIAPI WINBOOL WINAPI LPtoDP(HDC hdc,LPPOINT lppt,ਪੂਰਨ c);
  WINGDIAPI WINBOOL WINAPI Polygon(HDC hdc,CONST ਬਿੰਦੂ_3 *apt,ਪੂਰਨ cpt);
  WINGDIAPI WINBOOL WINAPI Polyline(HDC hdc,CONST ਬਿੰਦੂ_3 *apt,ਪੂਰਨ cpt);
  WINGDIAPI WINBOOL WINAPI PolyBezier(HDC hdc,CONST ਬਿੰਦੂ_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Poly_Bezier_ਮੰਜ਼ਿਲ(HDC hdc,CONST ਬਿੰਦੂ_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI Polyline_ਮੰਜ਼ਿਲ(HDC hdc,CONST ਬਿੰਦੂ_3 *apt,DWORD cpt);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Viewport_Ext_Ex(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Viewport_Org_Ex(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Ext_Ex(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_ਖਿੜਕੀ_Org_Ex(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ਵਿੱਥ_Viewport_Org_Ex(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ਵਿੱਥ_ਖਿੜਕੀ_Org_Ex(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI ScaleViewportExtEx(HDC hdc,ਪੂਰਨ xn,ਪੂਰਨ dx,ਪੂਰਨ yn,ਪੂਰਨ yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI Scale_ਖਿੜਕੀ_Ext_Ex(HDC hdc,ਪੂਰਨ xn,ਪੂਰਨ xd,ਪੂਰਨ yn,ਪੂਰਨ yd,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Bitmap_Dimension_Ex(HBITMAP hbm,ਪੂਰਨ w,ਪੂਰਨ h,LPSIZE lpsz);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Brush_Org_Ex(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPPOINT lppt);
  WINGDIAPI ਪੂਰਨ WINAPI Get_ਪਾਠ_Face_A(HDC hdc,ਪੂਰਨ c,LPSTR lpName);
  WINGDIAPI ਪੂਰਨ WINAPI Get_ਪਾਠ_Face_W(HDC hdc,ਪੂਰਨ c,LPWSTR lpName);

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FONTMAPPER_MAX 10

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_KERNINGPAIR {
    ਸ਼ਬਦ_3 w_ਪਹਿਲਾ;
    ਸ਼ਬਦ_3 w_ਦੂਜਾ;
    ਪੂਰਨ iKernAmount;
  } KERNINGPAIR,*LPKERNINGPAIR;

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Kerning_ਜੋੜੇ Get_Kerning_ਜੋੜੇ_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Get_Kerning_ਜੋੜੇ Get_Kerning_ਜੋੜੇ_A
#ਜੇ_ਅੰਤ

  WINGDIAPI DWORD WINAPI Get_Kerning_ਜੋੜੇ_A(HDC hdc,DWORD n_ਜੋੜੇ,LPKERNINGPAIR lpKernPair);
  WINGDIAPI DWORD WINAPI Get_Kerning_ਜੋੜੇ_W(HDC hdc,DWORD n_ਜੋੜੇ,LPKERNINGPAIR lpKernPair);
  WINGDIAPI WINBOOL WINAPI GetDCOrgEx(HDC hdc,LPPOINT lppt);
  WINGDIAPI WINBOOL WINAPI FixBrushOrgEx(HDC hdc,ਪੂਰਨ x,ਪੂਰਨ y,LPPOINT ptl);
  WINGDIAPI WINBOOL WINAPI UnrealizeObject(HGDIOBJ h);
  WINGDIAPI WINBOOL WINAPI GdiFlush();
  WINGDIAPI DWORD WINAPI Gdi_ਸੈੱਟ_Batch_ਹੱਦਬੰਦੀ(DWORD dw);
  WINGDIAPI DWORD WINAPI Gdi_Get_Batch_ਹੱਦਬੰਦੀ();

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_OFF 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_ON 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_QUERY 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICM_ਪੂਰਾ_OUTSIDEDC 4

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *ICMENUMPROCA)(LPSTR,LPARAM);
  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਪੂਰਨ (CALLBACK *ICMENUMPROCW)(LPWSTR,LPARAM);

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICMENUMPROC ICMENUMPROCW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumICMProfiles EnumICMProfilesW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Update_ICMReg_ਕੁੰਜੀ Update_ICMReg_ਕੁੰਜੀ_W
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetLogColorSpace GetLogColorSpaceW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateColorSpace CreateColorSpaceW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetICMProfile GetICMProfileW
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ICMProfile ਸੈੱਟ_ICMProfile_W
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ICMENUMPROC ICMENUMPROCA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EnumICMProfiles EnumICMProfilesA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Update_ICMReg_ਕੁੰਜੀ Update_ICMReg_ਕੁੰਜੀ_A
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetLogColorSpace GetLogColorSpaceA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CreateColorSpace CreateColorSpaceA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GetICMProfile GetICMProfileA
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸੈੱਟ_ICMProfile ਸੈੱਟ_ICMProfile_A
#ਜੇ_ਅੰਤ

  WINGDIAPI ਪੂਰਨ WINAPI ਸੈੱਟ_ICMMode(HDC hdc,ਪੂਰਨ ਬਹੁਲਕ);
  WINGDIAPI WINBOOL WINAPI Check_Colors_ਵਿੱਚ_Gamut(HDC hdc,LPVOID lpRGBTriple,LPVOID dlp_ਬਫਰ,DWORD n_ਗਿਣਤੀ);
  WINGDIAPI HCOLORSPACE WINAPI GetColorSpace(HDC hdc);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceA(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEA lp_ਬਫਰ,DWORD n_ਮਾਪ);
  WINGDIAPI WINBOOL WINAPI GetLogColorSpaceW(HCOLORSPACE hColorSpace,LPLOGCOLORSPACEW lp_ਬਫਰ,DWORD n_ਮਾਪ);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceA(LPLOGCOLORSPACEA lplcs);
  WINGDIAPI HCOLORSPACE WINAPI CreateColorSpaceW(LPLOGCOLORSPACEW lplcs);
  WINGDIAPI HCOLORSPACE WINAPI ਸੈੱਟ_Color_Space(HDC hdc,HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI DeleteColorSpace(HCOLORSPACE hcs);
  WINGDIAPI WINBOOL WINAPI GetICMProfileA(HDC hdc,LPDWORD p_Buf_ਮਾਪ,LPSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI GetICMProfileW(HDC hdc,LPDWORD p_Buf_ਮਾਪ,LPWSTR pszFilename);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_ICMProfile_A(HDC hdc,LPSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_ICMProfile_W(HDC hdc,LPWSTR lpFileName);
  WINGDIAPI WINBOOL WINAPI GetDeviceGammaRamp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI ਸੈੱਟ_Device_Gamma_Ramp(HDC hdc,LPVOID lpRamp);
  WINGDIAPI WINBOOL WINAPI Color_ਮੇਲ_ਮੰਜ਼ਿਲ_ਨਿਸ਼ਾਨਾ(HDC hdc,HDC hdc_ਨਿਸ਼ਾਨਾ,DWORD action);
  WINGDIAPI ਪੂਰਨ WINAPI EnumICMProfilesA(HDC hdc,ICMENUMPROCA proc,LPARAM param);
  WINGDIAPI ਪੂਰਨ WINAPI EnumICMProfilesW(HDC hdc,ICMENUMPROCW proc,LPARAM param);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_ਕੁੰਜੀ_A(DWORD reserved,LPSTR lpszCMID,LPSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI Update_ICMReg_ਕੁੰਜੀ_W(DWORD reserved,LPWSTR lpszCMID,LPWSTR lpszFileName,UINT command);
  WINGDIAPI WINBOOL WINAPI ColorCorrectPalette(HDC hdc,HPALETTE hPal,DWORD de_ਪਹਿਲਾ,DWORD ਅੰਕ);

#ਜੇ_ਅਪਰਿਭਾਸ਼ਿਤ NOMETAFILE

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENHMETA_SIGNATURE 0x464D4520
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENHMETA_STOCK_OBJECT 0x80000000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_ਸਿਰਲੇਖ 1
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYBEZIER 2
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYGON 3
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYLINE 4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYBEZIERTO 5
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYLINETO 6
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYPOLYLINE 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYPOLYGON 8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETWINDOWEXTEX 9
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETWINDOWORGEX 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETVIEWPORTEXTEX 11
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETVIEWPORTORGEX 12
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETBRUSHORGEX 13
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_EOF 14
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETPIXELV 15
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETMAPPERFLAGS 16
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETMAPMODE 17
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETBKMODE 18
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETPOLYFILLMODE 19
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETROP2 20
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETSTRETCHBLTMODE 21
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETTEXTALIGN 22
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETCOLORADJUSTMENT 23
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETTEXTCOLOR 24
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETBKCOLOR 25
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_OFFSETCLIPRGN 26
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_MOVETOEX 27
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETMETARGN 28
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_EXCLUDECLIPRECT 29
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_INTERSECTCLIPRECT 30
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SCALEVIEWPORTEXTEX 31
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SCALEWINDOWEXTEX 32
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SAVEDC 33
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESTOREDC 34
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETWORLDTRANSFORM 35
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_MODIFYWORLDTRANSFORM 36
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SELECTOBJECT 37
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_CREATEPEN 38
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_CREATEBRUSHINDIRECT 39
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_DELETEOBJECT 40
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_ANGLEARC 41
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_ELLIPSE 42
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RECTANGLE 43
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_ROUNDRECT 44
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_ARC 45
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_CHORD 46
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_PIE 47
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SELECTPALETTE 48
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_CREATEPALETTE 49
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETPALETTEENTRIES 50
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESIZEPALETTE 51
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_REALIZEPALETTE 52
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_EXTFLOODFILL 53
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_LINETO 54
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_ARCTO 55
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYDRAW 56
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETARCDIRECTION 57
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETMITERLIMIT 58
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_BEGINPATH 59
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_ENDPATH 60
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_CLOSEFIGURE 61
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_FILLPATH 62
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_STROKEANDFILLPATH 63
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_STROKEPATH 64
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_FLATTENPATH 65
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_WIDENPATH 66
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SELECTCLIPPATH 67
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_ABORTPATH 68

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_GDICOMMENT 70
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_FILLRGN 71
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_FRAMERGN 72
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_INVERTRGN 73
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_PAINTRGN 74
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_EXTSELECTCLIPRGN 75
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_BITBLT 76
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_STRETCHBLT 77
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_MASKBLT 78
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_PLGBLT 79
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETDIBITSTODEVICE 80
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_STRETCHDIBITS 81
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_EXTCREATEFONTINDIRECTW 82
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_EXTTEXTOUTA 83
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_EXTTEXTOUTW 84
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYBEZIER16 85
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYGON16 86
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYLINE16 87
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYBEZIERTO16 88
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYLINETO16 89
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYPOLYLINE16 90
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYPOLYGON16 91
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYDRAW16 92
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_CREATEMONOBRUSH 93
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_CREATEDIBPATTERNBRUSHPT 94
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_EXTCREATEPEN 95
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYTEXTOUTA 96
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_POLYTEXTOUTW 97

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETICMMODE 98
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_CREATECOLORSPACE 99
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETCOLORSPACE 100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_DELETECOLORSPACE 101
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_GLSRECORD 102
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_GLSBOUNDEDRECORD 103
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_PIXELFORMAT 104
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESERVED_105 105
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESERVED_106 106
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESERVED_107 107
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESERVED_108 108
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESERVED_109 109
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESERVED_110 110
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_COLORCORRECTPALETTE 111
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETICMPROFILEA 112
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETICMPROFILEW 113
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_ALPHABLEND 114
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_SETLAYOUT 115
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_TRANSPARENTBLT 116
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESERVED_117 117
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_GRADIENTFILL 118
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESERVED_119 119
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_RESERVED_120 120
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_COLORMATCHTOTARGETW 121
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_CREATECOLORSPACEW 122

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_MIN 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EMR_MAX 122

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMR {
    DWORD iType;
    DWORD n_ਮਾਪ;
  } EMR,*PEMR;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRTEXT {
    POINTL ptlReference;
    DWORD nChars;
    DWORD offString;
    DWORD fOptions;
    RECTL rcl;
    DWORD offDx;
  } EMRTEXT,*PEMRTEXT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_ABORTPATH {
    EMR emr;
  } EMRABORTPATH,*PEMRABORTPATH,EMRBEGINPATH,*PEMRBEGINPATH,EMRENDPATH,*PEMRENDPATH,EMRCLOSEFIGURE,*PEMRCLOSEFIGURE,EMRFLATTENPATH,*PEMRFLATTENPATH,EMRWIDENPATH,*PEMRWIDENPATH,EMRSETMETARGN,*PEMRSETMETARGN,EMRSAVEDC,*PEMRSAVEDC,EMRREALIZEPALETTE,*PEMRREALIZEPALETTE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSELECTCLIPPATH {
    EMR emr;
    DWORD i_ਬਹੁਲਕ;
  } EMRSELECTCLIPPATH,*PEMRSELECTCLIPPATH,EMRSETBKMODE,*PEMRSETBKMODE,EMRSETMAPMODE,*PEMRSETMAPMODE,EMRSETLAYOUT,*PEMRSETLAYOUT,
    EMRSETPOLYFILLMODE,*PEMRSETPOLYFILLMODE,EMRSETROP2,*PEMRSETROP2,EMRSETSTRETCHBLTMODE,*PEMRSETSTRETCHBLTMODE,EMRSETICMMODE,
    *PEMRSETICMMODE,EMRSETTEXTALIGN,*PEMRSETTEXTALIGN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETMITERLIMIT {
    EMR emr;
    FLOAT e_Miter_ਹੱਦਬੰਦੀ;
  } EMRSETMITERLIMIT,*PEMRSETMITERLIMIT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRRESTOREDC {
    EMR emr;
    LONG iRelative;
  } EMRRESTOREDC,*PEMRRESTOREDC;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETARCDIRECTION {
    EMR emr;
    DWORD iArcDirection;

  } EMRSETARCDIRECTION,*PEMRSETARCDIRECTION;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETMAPPERFLAGS {
    EMR emr;
    DWORD dwFlags;
  } EMRSETMAPPERFLAGS,*PEMRSETMAPPERFLAGS;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETTEXTCOLOR {
    EMR emr;
    COLORREF crColor;
  } EMRSETBKCOLOR,*PEMRSETBKCOLOR,EMRSETTEXTCOLOR,*PEMRSETTEXTCOLOR;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSELECTOBJECT {
    EMR emr;
    DWORD ihObject;
  } EMRSELECTOBJECT,*PEMRSELECTOBJECT,EMRDELETEOBJECT,*PEMRDELETEOBJECT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSELECTPALETTE {
    EMR emr;
    DWORD ihPal;
  } EMRSELECTPALETTE,*PEMRSELECTPALETTE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRRESIZEPALETTE {
    EMR emr;
    DWORD ihPal;
    DWORD cEntries;
  } EMRRESIZEPALETTE,*PEMRRESIZEPALETTE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETPALETTEENTRIES {
    EMR emr;
    DWORD ihPal;
    DWORD i_ਸ਼ੁਰੂ;
    DWORD cEntries;
    PALETTEENTRY aPalEntries[1];
  } EMRSETPALETTEENTRIES,*PEMRSETPALETTEENTRIES;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETCOLORADJUSTMENT {
    EMR emr;
    COLORADJUSTMENT ColorAdjustment;
  } EMRSETCOLORADJUSTMENT,*PEMRSETCOLORADJUSTMENT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRGDICOMMENT {
    EMR emr;
    DWORD cb_ਅੰਕੜੇ;
    BYTE ਅੰਕੜੇ_3[1];
  } EMRGDICOMMENT,*PEMRGDICOMMENT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMREOF {
    EMR emr;
    DWORD nPalEntries;
    DWORD offPalEntries;
    DWORD n_ਮਾਪ_ਆਖਰੀ;
  } EMREOF,*PEMREOF;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRLINETO {
    EMR emr;
    POINTL ptl;
  } EMRLINETO,*PEMRLINETO,EMRMOVETOEX,*PEMRMOVETOEX;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMROFFSETCLIPRGN {
    EMR emr;
    POINTL ptl_ਵਿੱਥ;
  } EMROFFSETCLIPRGN,*PEMROFFSETCLIPRGN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRFILLPATH {
    EMR emr;
    RECTL rclBounds;
  } EMRFILLPATH,*PEMRFILLPATH,EMRSTROKEANDFILLPATH,*PEMRSTROKEANDFILLPATH,EMRSTROKEPATH,*PEMRSTROKEPATH;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMREXCLUDECLIPRECT {
    EMR emr;
    RECTL rclClip;
  } EMREXCLUDECLIPRECT,*PEMREXCLUDECLIPRECT,EMRINTERSECTCLIPRECT,*PEMRINTERSECTCLIPRECT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETVIEWPORTORGEX {
    EMR emr;
    POINTL ptlOrigin;
  } EMRSETVIEWPORTORGEX,*PEMRSETVIEWPORTORGEX,EMRSETWINDOWORGEX,*PEMRSETWINDOWORGEX,EMRSETBRUSHORGEX,*PEMRSETBRUSHORGEX;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETVIEWPORTEXTEX {
    EMR emr;
    SIZEL szlExtent;
  } EMRSETVIEWPORTEXTEX,*PEMRSETVIEWPORTEXTEX,EMRSETWINDOWEXTEX,*PEMRSETWINDOWEXTEX;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSCALEVIEWPORTEXTEX {
    EMR emr;
    LONG x_ਅੰਕ;
    LONG xDenom;
    LONG y_ਅੰਕ;
    LONG yDenom;
  } EMRSCALEVIEWPORTEXTEX,*PEMRSCALEVIEWPORTEXTEX,EMRSCALEWINDOWEXTEX,*PEMRSCALEWINDOWEXTEX;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
  } EMRSETWORLDTRANSFORM,*PEMRSETWORLDTRANSFORM;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRMODIFYWORLDTRANSFORM {
    EMR emr;
    XFORM xform;
    DWORD i_ਬਹੁਲਕ;
  } EMRMODIFYWORLDTRANSFORM,*PEMRMODIFYWORLDTRANSFORM;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETPIXELV {
    EMR emr;
    POINTL ptlPixel;
    COLORREF crColor;
  } EMRSETPIXELV,*PEMRSETPIXELV;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMREXTFLOODFILL {
    EMR emr;
    POINTL ptl_ਸ਼ੁਰੂ;
    COLORREF crColor;
    DWORD i_ਬਹੁਲਕ;
  } EMREXTFLOODFILL,*PEMREXTFLOODFILL;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRELLIPSE {
    EMR emr;
    RECTL rclBox;
  } EMRELLIPSE,*PEMRELLIPSE,EMRRECTANGLE,*PEMRRECTANGLE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRROUNDRECT {
    EMR emr;
    RECTL rclBox;
    SIZEL szl_ਕੋਨਾ;
  } EMRROUNDRECT,*PEMRROUNDRECT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRARC {
    EMR emr;
    RECTL rclBox;
    POINTL ptl_ਸ਼ੁਰੂ;
    POINTL ptl_ਸਿਰਾ;
  } EMRARC,*PEMRARC,EMRARCTO,*PEMRARCTO,EMRCHORD,*PEMRCHORD,EMRPIE,*PEMRPIE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRANGLEARC {
    EMR emr;
    POINTL ptlCenter;
    DWORD nRadius;
    FLOAT e_ਸ਼ੁਰੂ_Angle;
    FLOAT eSweepAngle;
  } EMRANGLEARC,*PEMRANGLEARC;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
  } EMRPOLYLINE,*PEMRPOLYLINE,EMRPOLYBEZIER,*PEMRPOLYBEZIER,EMRPOLYGON,*PEMRPOLYGON,EMRPOLYBEZIERTO,*PEMRPOLYBEZIERTO,EMRPOLYLINETO,*PEMRPOLYLINETO;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
  } EMRPOLYLINE16,*PEMRPOLYLINE16,EMRPOLYBEZIER16,*PEMRPOLYBEZIER16,EMRPOLYGON16,*PEMRPOLYGON16,EMRPOLYBEZIERTO16,*PEMRPOLYBEZIERTO16,EMRPOLYLINETO16,*PEMRPOLYLINETO16;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRPOLYDRAW {
    EMR emr;
    RECTL rclBounds;
    DWORD cptl;
    POINTL aptl[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW,*PEMRPOLYDRAW;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRPOLYDRAW16 {
    EMR emr;
    RECTL rclBounds;
    DWORD cpts;
    POINTS apts[1];
    BYTE abTypes[1];
  } EMRPOLYDRAW16,*PEMRPOLYDRAW16;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRPOLYPOLYLINE {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cptl;
    DWORD aPolyCounts[1];
    POINTL aptl[1];
  } EMRPOLYPOLYLINE,*PEMRPOLYPOLYLINE,EMRPOLYPOLYGON,*PEMRPOLYPOLYGON;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRPOLYPOLYLINE16 {
    EMR emr;
    RECTL rclBounds;
    DWORD nPolys;
    DWORD cpts;
    DWORD aPolyCounts[1];
    POINTS apts[1];
  } EMRPOLYPOLYLINE16,*PEMRPOLYPOLYLINE16,EMRPOLYPOLYGON16,*PEMRPOLYPOLYGON16;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRINVERTRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_ਅੰਕੜੇ;
    BYTE Rgn_ਅੰਕੜੇ[1];
  } EMRINVERTRGN,*PEMRINVERTRGN,EMRPAINTRGN,*PEMRPAINTRGN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRFILLRGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_ਅੰਕੜੇ;
    DWORD ihBrush;
    BYTE Rgn_ਅੰਕੜੇ[1];
  } EMRFILLRGN,*PEMRFILLRGN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRFRAMERGN {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_Rgn_ਅੰਕੜੇ;
    DWORD ihBrush;
    SIZEL szlStroke;
    BYTE Rgn_ਅੰਕੜੇ[1];
  } EMRFRAMERGN,*PEMRFRAMERGN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMREXTSELECTCLIPRGN {
    EMR emr;
    DWORD cb_Rgn_ਅੰਕੜੇ;
    DWORD i_ਬਹੁਲਕ;
    BYTE Rgn_ਅੰਕੜੇ[1];
  } EMREXTSELECTCLIPRGN,*PEMREXTSELECTCLIPRGN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMREXTTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_ਬਹੁਲਕ;
    FLOAT exScale;
    FLOAT eyScale;
    EMRTEXT emrtext;
  } EMREXTTEXTOUTA,*PEMREXTTEXTOUTA,EMREXTTEXTOUTW,*PEMREXTTEXTOUTW;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRPOLYTEXTOUTA {
    EMR emr;
    RECTL rclBounds;
    DWORD i_Graphics_ਬਹੁਲਕ;
    FLOAT exScale;
    FLOAT eyScale;
    LONG c_ਲੜੀਆਂ;
    EMRTEXT aemrtext[1];
  } EMRPOLYTEXTOUTA,*PEMRPOLYTEXTOUTA,EMRPOLYTEXTOUTW,*PEMRPOLYTEXTOUTW;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRBITBLT {
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
    DWORD off_ਬਿੱਟ_Src;
    DWORD cb_ਬਿੱਟ_Src;
  } EMRBITBLT,*PEMRBITBLT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSTRETCHBLT {
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
    DWORD off_ਬਿੱਟ_Src;
    DWORD cb_ਬਿੱਟ_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRSTRETCHBLT,*PEMRSTRETCHBLT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRMASKBLT {
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
    DWORD off_ਬਿੱਟ_Src;
    DWORD cb_ਬਿੱਟ_Src;
    LONG x_ਨਕਾਬ;
    LONG y_ਨਕਾਬ;
    DWORD i_Usage_ਨਕਾਬ;
    DWORD off_Bmi_ਨਕਾਬ;
    DWORD cb_Bmi_ਨਕਾਬ;
    DWORD off_ਬਿੱਟ_ਨਕਾਬ;
    DWORD cb_ਬਿੱਟ_ਨਕਾਬ;
  } EMRMASKBLT,*PEMRMASKBLT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRPLGBLT {
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
    DWORD off_ਬਿੱਟ_Src;
    DWORD cb_ਬਿੱਟ_Src;
    LONG x_ਨਕਾਬ;
    LONG y_ਨਕਾਬ;
    DWORD i_Usage_ਨਕਾਬ;
    DWORD off_Bmi_ਨਕਾਬ;
    DWORD cb_Bmi_ਨਕਾਬ;
    DWORD off_ਬਿੱਟ_ਨਕਾਬ;
    DWORD cb_ਬਿੱਟ_ਨਕਾਬ;
  } EMRPLGBLT,*PEMRPLGBLT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETDIBITSTODEVICE {
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
    DWORD off_ਬਿੱਟ_Src;
    DWORD cb_ਬਿੱਟ_Src;
    DWORD iUsageSrc;
    DWORD i_ਸ਼ੁਰੂ_ਜਾਂਚ;
    DWORD cScans;
  } EMRSETDIBITSTODEVICE,*PEMRSETDIBITSTODEVICE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSTRETCHDIBITS {
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
    DWORD off_ਬਿੱਟ_Src;
    DWORD cb_ਬਿੱਟ_Src;
    DWORD iUsageSrc;
    DWORD dwRop;
    LONG cxDest;
    LONG cyDest;
  } EMRSTRETCHDIBITS,*PEMRSTRETCHDIBITS;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMREXTCREATEFONTINDIRECTW {
    EMR emr;
    DWORD ihFont;
    EXTLOGFONTW elfw;
  } EMREXTCREATEFONTINDIRECTW,*PEMREXTCREATEFONTINDIRECTW;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRCREATEPALETTE {
    EMR emr;
    DWORD ihPal;
    LOGPALETTE lgpl;
  } EMRCREATEPALETTE,*PEMRCREATEPALETTE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRCREATEPEN {
    EMR emr;
    DWORD ihPen;
    LOGPEN lopn;
  } EMRCREATEPEN,*PEMRCREATEPEN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMREXTCREATEPEN {
    EMR emr;
    DWORD ihPen;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_ਬਿੱਟ;
    DWORD cb_ਬਿੱਟ;
    EXTLOGPEN elp;
  } EMREXTCREATEPEN,*PEMREXTCREATEPEN;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRCREATEBRUSHINDIRECT {
    EMR emr;
    DWORD ihBrush;
    LOGBRUSH32 lb;
  } EMRCREATEBRUSHINDIRECT,*PEMRCREATEBRUSHINDIRECT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRCREATEMONOBRUSH {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_ਬਿੱਟ;
    DWORD cb_ਬਿੱਟ;
  } EMRCREATEMONOBRUSH,*PEMRCREATEMONOBRUSH;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRCREATEDIBPATTERNBRUSHPT {
    EMR emr;
    DWORD ihBrush;
    DWORD iUsage;
    DWORD offBmi;
    DWORD cbBmi;
    DWORD off_ਬਿੱਟ;
    DWORD cb_ਬਿੱਟ;
  } EMRCREATEDIBPATTERNBRUSHPT,*PEMRCREATEDIBPATTERNBRUSHPT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRFORMAT {
    DWORD dSignature;
    DWORD n_ਸੰਸਕਰਣ;
    DWORD cb_ਅੰਕੜੇ;
    DWORD off_ਅੰਕੜੇ;
  } EMRFORMAT,*PEMRFORMAT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRGLSRECORD {
    EMR emr;
    DWORD cb_ਅੰਕੜੇ;
    BYTE ਅੰਕੜੇ_3[1];
  } EMRGLSRECORD,*PEMRGLSRECORD;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRGLSBOUNDEDRECORD {
    EMR emr;
    RECTL rclBounds;
    DWORD cb_ਅੰਕੜੇ;
    BYTE ਅੰਕੜੇ_3[1];
  } EMRGLSBOUNDEDRECORD,*PEMRGLSBOUNDEDRECORD;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRPIXELFORMAT {
    EMR emr;
    PIXELFORMATDESCRIPTOR pfd;
  } EMRPIXELFORMAT,*PEMRPIXELFORMAT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRCREATECOLORSPACE {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEA lcs;
  } EMRCREATECOLORSPACE,*PEMRCREATECOLORSPACE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETCOLORSPACE {
    EMR emr;
    DWORD ihCS;
  } EMRSETCOLORSPACE,*PEMRSETCOLORSPACE,EMRSELECTCOLORSPACE,*PEMRSELECTCOLORSPACE,EMRDELETECOLORSPACE,*PEMRDELETECOLORSPACE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMREXTESCAPE {
    EMR emr;
    INT iEscape;
    INT cb_Esc_ਅੰਕੜੇ;
    BYTE Esc_ਅੰਕੜੇ[1];
  } EMREXTESCAPE,*PEMREXTESCAPE,EMRDRAWESCAPE,*PEMRDRAWESCAPE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRNAMEDESCAPE {
    EMR emr;
    INT iEscape;
    INT cbDriver;
    INT cb_Esc_ਅੰਕੜੇ;
    BYTE Esc_ਅੰਕੜੇ[1];
  } EMRNAMEDESCAPE,*PEMRNAMEDESCAPE;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SETICMPROFILE_EMBEDED 0x00000001

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRSETICMPROFILE {
    EMR emr;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_ਅੰਕੜੇ;
    BYTE ਅੰਕੜੇ_3[1];
  } EMRSETICMPROFILE,*PEMRSETICMPROFILE,EMRSETICMPROFILEA,*PEMRSETICMPROFILEA,EMRSETICMPROFILEW,*PEMRSETICMPROFILEW;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CREATECOLORSPACE_EMBEDED 0x00000001

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRCREATECOLORSPACEW {
    EMR emr;
    DWORD ihCS;
    LOGCOLORSPACEW lcs;
    DWORD dwFlags;
    DWORD cb_ਅੰਕੜੇ;
    BYTE ਅੰਕੜੇ_3[1];
  } EMRCREATECOLORSPACEW,*PEMRCREATECOLORSPACEW;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COLORMATCHTOTARGET_EMBEDED 0x00000001

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_COLORMATCHTOTARGET {
    EMR emr;
    DWORD dwAction;
    DWORD dwFlags;
    DWORD cbName;
    DWORD cb_ਅੰਕੜੇ;
    BYTE ਅੰਕੜੇ_3[1];
  } EMRCOLORMATCHTOTARGET,*PEMRCOLORMATCHTOTARGET;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_COLORCORRECTPALETTE {
    EMR emr;
    DWORD ihPalette;
    DWORD n_ਪਹਿਲਾ_ਇੰਦਰਾਜ;
    DWORD nPalEntries;
    DWORD nReserved;
  } EMRCOLORCORRECTPALETTE,*PEMRCOLORCORRECTPALETTE;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRALPHABLEND {
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
    DWORD off_ਬਿੱਟ_Src;
    DWORD cb_ਬਿੱਟ_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRALPHABLEND,*PEMRALPHABLEND;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRGRADIENTFILL {
    EMR emr;
    RECTL rclBounds;
    DWORD nVer;
    DWORD nTri;
    ULONG ul_ਬਹੁਲਕ;
    TRIVERTEX Ver[1];
  } EMRGRADIENTFILL,*PEMRGRADIENTFILL;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_EMRTRANSPARENTBLT {
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
    DWORD off_ਬਿੱਟ_Src;
    DWORD cb_ਬਿੱਟ_Src;
    LONG cxSrc;
    LONG cySrc;
  } EMRTRANSPARENTBLT,*PEMRTRANSPARENTBLT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GDICOMMENT_IDENTIFIER 0x43494447
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GDICOMMENT_WINDOWS_METAFILE 0x80000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GDICOMMENT_BEGINGROUP 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GDICOMMENT_ENDGROUP 0x00000003
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GDICOMMENT_MULTIFORMATS 0x40000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ EPS_SIGNATURE 0x46535045
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GDICOMMENT_UNICODE_STRING 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ GDICOMMENT_UNICODE_ਸਿਰਾ 0x00000080
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wglUseFontBitmaps wglUseFontBitmapsW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wglUseFontBitmaps wglUseFontBitmapsA
#ਜੇ_ਅੰਤ

  WINGDIAPI WINBOOL WINAPI wglCopyContext(HGLRC,HGLRC,UINT);
  WINGDIAPI HGLRC WINAPI wglCreateContext(HDC);
  WINGDIAPI HGLRC WINAPI wglCreateLayerContext(HDC,ਪੂਰਨ);
  WINGDIAPI WINBOOL WINAPI wglDeleteContext(HGLRC);
  WINGDIAPI HGLRC WINAPI wglGetCurrentContext(VOID);
  WINGDIAPI HDC WINAPI wglGetCurrentDC(VOID);
  WINGDIAPI PROC WINAPI wgl_Get_Proc_ਪਤਾ(LPCSTR);
  WINGDIAPI WINBOOL WINAPI wglMakeCurrent(HDC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglShareLists(HGLRC,HGLRC);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsA(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI wglUseFontBitmapsW(HDC,DWORD,DWORD,DWORD);
  WINGDIAPI WINBOOL WINAPI ਅਦਲਾ_ਬਦਲੀ_Buffers(HDC);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _POINTFLOAT {
    FLOAT x;
    FLOAT y;
  } POINTFLOAT,*PPOINTFLOAT;

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _GLYPHMETRICSFLOAT {
    FLOAT gmfBlackBoxX;
    FLOAT gmfBlackBoxY;
    POINTFLOAT gmfptGlyphOrigin;
    FLOAT gmfCellIncX;
    FLOAT gmfCellIncY;
  } GLYPHMETRICSFLOAT,*PGLYPHMETRICSFLOAT,*LPGLYPHMETRICSFLOAT;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_FONT_ਸਤਰਾਂ 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_FONT_POLYGONS 1

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ UNICODE
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wglUseFontOutlines wglUseFontOutlinesW
#ਨਹੀਂਤਾਂ
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ wglUseFontOutlines wglUseFontOutlinesA
#ਜੇ_ਅੰਤ

  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesA(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,ਪੂਰਨ,LPGLYPHMETRICSFLOAT);
  WINGDIAPI WINBOOL WINAPI wglUseFontOutlinesW(HDC,DWORD,DWORD,DWORD,FLOAT,FLOAT,ਪੂਰਨ,LPGLYPHMETRICSFLOAT);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਟੈਗ_LAYERPLANEDESCRIPTOR {
    ਸ਼ਬਦ_3 n_ਮਾਪ;
    ਸ਼ਬਦ_3 n_ਸੰਸਕਰਣ;
    DWORD dwFlags;
    BYTE iPixelType;
    BYTE c_Color_ਬਿੱਟ;
    BYTE c_Red_ਬਿੱਟ;
    BYTE c_Red_ਖਿਸਕਾਓ;
    BYTE c_Green_ਬਿੱਟ;
    BYTE c_Green_ਖਿਸਕਾਓ;
    BYTE c_Blue_ਬਿੱਟ;
    BYTE c_Blue_ਖਿਸਕਾਓ;
    BYTE c_Alpha_ਬਿੱਟ;
    BYTE c_Alpha_ਖਿਸਕਾਓ;
    BYTE c_Accum_ਬਿੱਟ;
    BYTE c_Accum_Red_ਬਿੱਟ;
    BYTE c_Accum_Green_ਬਿੱਟ;
    BYTE c_Accum_Blue_ਬਿੱਟ;
    BYTE c_Accum_Alpha_ਬਿੱਟ;
    BYTE c_ਡੂੰਘਾਈ_ਬਿੱਟ;
    BYTE c_Stencil_ਬਿੱਟ;
    BYTE cAuxBuffers;
    BYTE iLayerPlane;
    BYTE bReserved;
    COLORREF crTransparent;
  } LAYERPLANEDESCRIPTOR,*PLAYERPLANEDESCRIPTOR,*LPLAYERPLANEDESCRIPTOR;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_DOUBLEBUFFER 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_STEREO 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_SUPPORT_GDI 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_SUPPORT_OPENGL 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_SHARE_ਡੂੰਘਾਈ 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_SHARE_STENCIL 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_SHARE_ACCUM 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_ਅਦਲਾ_ਬਦਲੀ_EXCHANGE 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_ਅਦਲਾ_ਬਦਲੀ_COPY 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_TRANSPARENT 0x00001000

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_TYPE_RGBA 0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LPD_TYPE_COLORINDEX 1

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_MAIN_PLANE 0x00000001
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY1 0x00000002
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY2 0x00000004
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY3 0x00000008
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY4 0x00000010
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY5 0x00000020
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY6 0x00000040
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY7 0x00000080
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY8 0x00000100
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY9 0x00000200
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY10 0x00000400
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY11 0x00000800
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY12 0x00001000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY13 0x00002000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY14 0x00004000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_OVERLAY15 0x00008000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY1 0x00010000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY2 0x00020000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY3 0x00040000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY4 0x00080000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY5 0x00100000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY6 0x00200000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY7 0x00400000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY8 0x00800000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY9 0x01000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY10 0x02000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY11 0x04000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY12 0x08000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY13 0x10000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY14 0x20000000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_ਅਦਲਾ_ਬਦਲੀ_UNDERLAY15 0x40000000

  WINGDIAPI WINBOOL WINAPI wglDescribeLayerPlane(HDC,ਪੂਰਨ,ਪੂਰਨ,UINT,LPLAYERPLANEDESCRIPTOR);
  WINGDIAPI ਪੂਰਨ WINAPI wgl_ਸੈੱਟ_Layer_Palette_Entries(HDC,ਪੂਰਨ,ਪੂਰਨ,ਪੂਰਨ,CONST COLORREF *);
  WINGDIAPI ਪੂਰਨ WINAPI wglGetLayerPaletteEntries(HDC,ਪੂਰਨ,ਪੂਰਨ,ਪੂਰਨ,COLORREF *);
  WINGDIAPI WINBOOL WINAPI wglRealizeLayerPalette(HDC,ਪੂਰਨ,WINBOOL);
  WINGDIAPI WINBOOL WINAPI wgl_ਅਦਲਾ_ਬਦਲੀ_Layer_Buffers(HDC,UINT);

  ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ _WGLSWAP {
    HDC hdc;
    UINT uiFlags;
  } WGLSWAP,*PWGLSWAP,*LPWGLSWAP;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ WGL_SWAPMULTIPLE_MAX 16

  WINGDIAPI DWORD WINAPI wgl_ਅਦਲਾ_ਬਦਲੀ_ਗੁਣਜ_Buffers(UINT,CONST WGLSWAP *);
#ਜੇ_ਅੰਤ

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ __cplusplus
}
#ਜੇ_ਅੰਤ
#ਜੇ_ਅੰਤ
