/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ _WINNLS_
#تعریف_کرو _WINNLS_

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#اگر_غیر_تعریف_شدہ NONLS

#تعریف_کرو MAX_LEADBYTES 12
#تعریف_کرو MAX_DEFAULTCHAR 2

#تعریف_کرو MB_PRECOMPOSED 0x00000001
#تعریف_کرو MB_مرکب 0x00000002
#تعریف_کرو MB_USEGLYPHCHARS 0x00000004
#تعریف_کرو MB_ERR_INVALID_CHARS 0x00000008

#تعریف_کرو WC_COMPOSITECHECK 0x00000200
#تعریف_کرو WC_DISCARDNS 0x00000010
#تعریف_کرو WC_SEPCHARS 0x00000020
#تعریف_کرو WC_DEFAULTCHAR 0x00000040
#تعریف_کرو WC_NO_بہترین_FIT_CHARS 0x00000400

#تعریف_کرو CT_CTYPE1 0x00000001
#تعریف_کرو CT_CTYPE2 0x00000002
#تعریف_کرو CT_CTYPE3 0x00000004

#تعریف_کرو C1_بالائی 0x0001
#تعریف_کرو C1_زیریں 0x0002
#تعریف_کرو C1_DIGIT 0x0004
#تعریف_کرو C1_SPACE 0x0008
#تعریف_کرو C1_PUNCT 0x0010
#تعریف_کرو C1_CNTRL 0x0020
#تعریف_کرو C1_BLANK 0x0040
#تعریف_کرو C1_XDIGIT 0x0080
#تعریف_کرو C1_ALPHA 0x0100
#تعریف_کرو C1_DEFINED 0x0200

#تعریف_کرو C2_LEFTTORIGHT 0x0001
#تعریف_کرو C2_RIGHTTOLEFT 0x0002

#تعریف_کرو C2_EUROPENUMBER 0x0003
#تعریف_کرو C2_EUROPESEPARATOR 0x0004
#تعریف_کرو C2_EUROPETERMINATOR 0x0005
#تعریف_کرو C2_ARABICNUMBER 0x0006
#تعریف_کرو C2_COMMONSEPARATOR 0x0007

#تعریف_کرو C2_BLOCKSEPARATOR 0x0008
#تعریف_کرو C2_SEGMENTSEPARATOR 0x0009
#تعریف_کرو C2_WHITESPACE 0x000A
#تعریف_کرو C2_OTHERNEUTRAL 0x000B

#تعریف_کرو C2_NOTAPPLICABLE 0x0000

#تعریف_کرو C3_NONSPACING 0x0001
#تعریف_کرو C3_DIACRITIC 0x0002
#تعریف_کرو C3_VOWELMARK 0x0004
#تعریف_کرو C3_علامت 0x0008

#تعریف_کرو C3_KATAKANA 0x0010
#تعریف_کرو C3_HIRAGANA 0x0020
#تعریف_کرو C3_HALFWIDTH 0x0040
#تعریف_کرو C3_FULLWIDTH 0x0080
#تعریف_کرو C3_IDEOGRAPH 0x0100
#تعریف_کرو C3_KASHIDA 0x0200
#تعریف_کرو C3_LEXICAL 0x0400

#تعریف_کرو C3_ALPHA 0x8000

#تعریف_کرو C3_NOTAPPLICABLE 0x0000

#تعریف_کرو NORM_IGNORECASE 0x00000001
#تعریف_کرو NORM_IGNORENONSPACE 0x00000002
#تعریف_کرو NORM_IGNORESYMBOLS 0x00000004

#تعریف_کرو NORM_IGNOREKANATYPE 0x00010000
#تعریف_کرو NORM_IGNOREWIDTH 0x00020000

#تعریف_کرو MAP_FOLDCZONE 0x00000010
#تعریف_کرو MAP_PRECOMPOSED 0x00000020
#تعریف_کرو MAP_مرکب 0x00000040
#تعریف_کرو MAP_FOLDDIGITS 0x00000080
#تعریف_کرو MAP_EXPAND_LIGATURES 0x00002000

#تعریف_کرو LCMAP_LOWERCASE 0x00000100
#تعریف_کرو LCMAP_UPPERCASE 0x00000200
#تعریف_کرو LCMAP_SORTKEY 0x00000400
#تعریف_کرو LCMAP_BYTEREV 0x00000800

#تعریف_کرو LCMAP_HIRAGANA 0x00100000
#تعریف_کرو LCMAP_KATAKANA 0x00200000
#تعریف_کرو LCMAP_HALFWIDTH 0x00400000
#تعریف_کرو LCMAP_FULLWIDTH 0x00800000

#تعریف_کرو LCMAP_LINGUISTIC_CASING 0x01000000

#تعریف_کرو LCMAP_SIMPLIFIED_CHINESE 0x02000000
#تعریف_کرو LCMAP_TRADITIONAL_CHINESE 0x04000000

#تعریف_کرو LGRPID_INSTALLED 0x00000001
#تعریف_کرو LGRPID_SUPPORTED 0x00000002

#تعریف_کرو LCID_INSTALLED 0x00000001
#تعریف_کرو LCID_SUPPORTED 0x00000002
#تعریف_کرو LCID_ALTERNATE_SORTS 0x00000004

#تعریف_کرو CP_INSTALLED 0x00000001
#تعریف_کرو CP_SUPPORTED 0x00000002

#تعریف_کرو ترتیب_دو_STRINGSORT 0x00001000

#تعریف_کرو CSTR_LESS_THAN 1
#تعریف_کرو CSTR_EQUAL 2
#تعریف_کرو CSTR_GREATER_THAN 3

#تعریف_کرو CP_ACP 0
#تعریف_کرو CP_OEMCP 1
#تعریف_کرو CP_MACCP 2
#تعریف_کرو CP_THREAD_ACP 3
#تعریف_کرو CP_علامت 42

#تعریف_کرو CP_UTF7 65000
#تعریف_کرو CP_UTF8 65001

#تعریف_کرو CTRY_DEFAULT 0

#تعریف_کرو CTRY_ALBANIA 355
#تعریف_کرو CTRY_ALGERIA 213
#تعریف_کرو CTRY_ARGENTINA 54
#تعریف_کرو CTRY_ARMENIA 374
#تعریف_کرو CTRY_AUSTRALIA 61
#تعریف_کرو CTRY_AUSTRIA 43
#تعریف_کرو CTRY_AZERBAIJAN 994
#تعریف_کرو CTRY_BAHRAIN 973
#تعریف_کرو CTRY_BELARUS 375
#تعریف_کرو CTRY_BELGIUM 32
#تعریف_کرو CTRY_BELIZE 501
#تعریف_کرو CTRY_BOLIVIA 591
#تعریف_کرو CTRY_BRAZIL 55
#تعریف_کرو CTRY_BRUNEI_DARUSSALAM 673
#تعریف_کرو CTRY_BULGARIA 359
#تعریف_کرو CTRY_CANADA 2
#تعریف_کرو CTRY_CARIBBEAN 1
#تعریف_کرو CTRY_CHILE 56
#تعریف_کرو CTRY_COLOMBIA 57
#تعریف_کرو CTRY_COSTA_RICA 506
#تعریف_کرو CTRY_CROATIA 385
#تعریف_کرو CTRY_CZECH 420
#تعریف_کرو CTRY_DENMARK 45
#تعریف_کرو CTRY_DOMINICAN_REPUBLIC 1
#تعریف_کرو CTRY_ECUADOR 593
#تعریف_کرو CTRY_EGYPT 20
#تعریف_کرو CTRY_EL_SALVADOR 503
#تعریف_کرو CTRY_ESTONIA 372
#تعریف_کرو CTRY_FAEROE_ISLANDS 298
#تعریف_کرو CTRY_FINLAND 358
#تعریف_کرو CTRY_FRANCE 33
#تعریف_کرو CTRY_GEORGIA 995
#تعریف_کرو CTRY_GERMANY 49
#تعریف_کرو CTRY_GREECE 30
#تعریف_کرو CTRY_GUATEMALA 502
#تعریف_کرو CTRY_HONDURAS 504
#تعریف_کرو CTRY_HONG_KONG 852
#تعریف_کرو CTRY_HUNGARY 36
#تعریف_کرو CTRY_ICELAND 354
#تعریف_کرو CTRY_INDIA 91
#تعریف_کرو CTRY_INDONESIA 62
#تعریف_کرو CTRY_IRAN 981
#تعریف_کرو CTRY_IRAQ 964
#تعریف_کرو CTRY_IRELAND 353
#تعریف_کرو CTRY_ISRAEL 972
#تعریف_کرو CTRY_ITALY 39
#تعریف_کرو CTRY_JAMAICA 1
#تعریف_کرو CTRY_JAPAN 81
#تعریف_کرو CTRY_JORDAN 962
#تعریف_کرو CTRY_KAZAKSTAN 7
#تعریف_کرو CTRY_KENYA 254
#تعریف_کرو CTRY_KUWAIT 965
#تعریف_کرو CTRY_KYRGYZSTAN 996
#تعریف_کرو CTRY_LATVIA 371
#تعریف_کرو CTRY_LEBANON 961
#تعریف_کرو CTRY_LIBYA 218
#تعریف_کرو CTRY_LIECHTENSTEIN 41
#تعریف_کرو CTRY_LITHUANIA 370
#تعریف_کرو CTRY_LUXEMBOURG 352
#تعریف_کرو CTRY_MACAU 853
#تعریف_کرو CTRY_MACEDONIA 389
#تعریف_کرو CTRY_MALAYSIA 60
#تعریف_کرو CTRY_MALDIVES 960
#تعریف_کرو CTRY_MEXICO 52
#تعریف_کرو CTRY_MONACO 33
#تعریف_کرو CTRY_MONGOLIA 976
#تعریف_کرو CTRY_MOROCCO 212
#تعریف_کرو CTRY_NETHERLANDS 31
#تعریف_کرو CTRY_NEW_ZEALAND 64
#تعریف_کرو CTRY_NICARAGUA 505
#تعریف_کرو CTRY_NORWAY 47
#تعریف_کرو CTRY_OMAN 968
#تعریف_کرو CTRY_PAKISTAN 92
#تعریف_کرو CTRY_PANAMA 507
#تعریف_کرو CTRY_PARAGUAY 595
#تعریف_کرو CTRY_PERU 51
#تعریف_کرو CTRY_PHILIPPINES 63
#تعریف_کرو CTRY_POLAND 48
#تعریف_کرو CTRY_PORTUGAL 351
#تعریف_کرو CTRY_PRCHINA 86
#تعریف_کرو CTRY_PUERTO_RICO 1
#تعریف_کرو CTRY_QATAR 974
#تعریف_کرو CTRY_ROMANIA 40
#تعریف_کرو CTRY_RUSSIA 7
#تعریف_کرو CTRY_SAUDI_ARABIA 966
#تعریف_کرو CTRY_SERBIA 381
#تعریف_کرو CTRY_SINGAPORE 65
#تعریف_کرو CTRY_SLOVAK 421
#تعریف_کرو CTRY_SLOVENIA 386
#تعریف_کرو CTRY_SOUTH_AFRICA 27
#تعریف_کرو CTRY_SOUTH_KOREA 82
#تعریف_کرو CTRY_SPAIN 34
#تعریف_کرو CTRY_SWEDEN 46
#تعریف_کرو CTRY_SWITZERLAND 41
#تعریف_کرو CTRY_SYRIA 963
#تعریف_کرو CTRY_TAIWAN 886
#تعریف_کرو CTRY_TATARSTAN 7
#تعریف_کرو CTRY_THAILAND 66
#تعریف_کرو CTRY_TRINIDAD_Y_TOBAGO 1
#تعریف_کرو CTRY_TUNISIA 216
#تعریف_کرو CTRY_TURKEY 90
#تعریف_کرو CTRY_UAE 971
#تعریف_کرو CTRY_UKRAINE 380
#تعریف_کرو CTRY_UNITED_KINGDOM 44
#تعریف_کرو CTRY_UNITED_حالتیں 1
#تعریف_کرو CTRY_URUGUAY 598
#تعریف_کرو CTRY_UZBEKISTAN 7
#تعریف_کرو CTRY_VENEZUELA 58
#تعریف_کرو CTRY_VIET_NAM 84
#تعریف_کرو CTRY_YEMEN 967
#تعریف_کرو CTRY_ZIMBABWE 263

#تعریف_کرو LOCALE_NOUSEROVERRIDE 0x80000000
#تعریف_کرو LOCALE_USE_CP_ACP 0x40000000
#تعریف_کرو LOCALE_RETURN_نمبر 0x20000000

#تعریف_کرو LOCALE_ILANGUAGE 0x00000001
#تعریف_کرو LOCALE_SLANGUAGE 0x00000002
#تعریف_کرو LOCALE_SENGLANGUAGE 0x00001001
#تعریف_کرو LOCALE_SABBREVLANGNAME 0x00000003
#تعریف_کرو LOCALE_SNATIVELANGNAME 0x00000004

#تعریف_کرو LOCALE_ICOUNTRY 0x00000005
#تعریف_کرو LOCALE_SCOUNTRY 0x00000006
#تعریف_کرو LOCALE_SENGCOUNTRY 0x00001002
#تعریف_کرو LOCALE_SABBREVCTRYNAME 0x00000007
#تعریف_کرو LOCALE_SNATIVECTRYNAME 0x00000008

#تعریف_کرو LOCALE_IDEFAULTLANGUAGE 0x00000009
#تعریف_کرو LOCALE_IDEFAULTCOUNTRY 0x0000000A
#تعریف_کرو LOCALE_IDEFAULTCODEPAGE 0x0000000B
#تعریف_کرو LOCALE_IDEFAULTANSICODEPAGE 0x00001004
#تعریف_کرو LOCALE_IDEFAULTMACCODEPAGE 0x00001011

#تعریف_کرو LOCALE_SLIST 0x0000000C
#تعریف_کرو LOCALE_IMEASURE 0x0000000D

#تعریف_کرو LOCALE_SDECIMAL 0x0000000E
#تعریف_کرو LOCALE_STHOUSAND 0x0000000F
#تعریف_کرو LOCALE_SGROUPING 0x00000010
#تعریف_کرو LOCALE_IDIGITS 0x00000011
#تعریف_کرو LOCALE_ILZERO 0x00000012
#تعریف_کرو LOCALE_INEGNUMBER 0x00001010
#تعریف_کرو LOCALE_SNATIVEDIGITS 0x00000013

#تعریف_کرو LOCALE_SCURRENCY 0x00000014
#تعریف_کرو LOCALE_SINTLSYMBOL 0x00000015
#تعریف_کرو LOCALE_SMONDECIMALSEP 0x00000016
#تعریف_کرو LOCALE_SMONTHOUSANDSEP 0x00000017
#تعریف_کرو LOCALE_SMONGROUPING 0x00000018
#تعریف_کرو LOCALE_ICURRDIGITS 0x00000019
#تعریف_کرو LOCALE_IINTLCURRDIGITS 0x0000001A
#تعریف_کرو LOCALE_ICURRENCY 0x0000001B
#تعریف_کرو LOCALE_INEGCURR 0x0000001C

#تعریف_کرو LOCALE_SDATE 0x0000001D
#تعریف_کرو LOCALE_STIME 0x0000001E
#تعریف_کرو LOCALE_SSHORTDATE 0x0000001F
#تعریف_کرو LOCALE_SLONGDATE 0x00000020
#تعریف_کرو LOCALE_STIMEFORMAT 0x00001003
#تعریف_کرو LOCALE_IDATE 0x00000021
#تعریف_کرو LOCALE_ILDATE 0x00000022
#تعریف_کرو LOCALE_ITIME 0x00000023
#تعریف_کرو LOCALE_ITIMEMARKPOSN 0x00001005
#تعریف_کرو LOCALE_ICENTURY 0x00000024
#تعریف_کرو LOCALE_ITLZERO 0x00000025
#تعریف_کرو LOCALE_IDAYLZERO 0x00000026
#تعریف_کرو LOCALE_IMONLZERO 0x00000027
#تعریف_کرو LOCALE_S1159 0x00000028
#تعریف_کرو LOCALE_S2359 0x00000029

#تعریف_کرو LOCALE_ICALENDARTYPE 0x00001009
#تعریف_کرو LOCALE_IOPTIONALCALENDAR 0x0000100B
#تعریف_کرو LOCALE_IFIRSTDAYOFWEEK 0x0000100C
#تعریف_کرو LOCALE_IFIRSTWEEKOFYEAR 0x0000100D

#تعریف_کرو LOCALE_SDAYNAME1 0x0000002A
#تعریف_کرو LOCALE_SDAYNAME2 0x0000002B
#تعریف_کرو LOCALE_SDAYNAME3 0x0000002C
#تعریف_کرو LOCALE_SDAYNAME4 0x0000002D
#تعریف_کرو LOCALE_SDAYNAME5 0x0000002E
#تعریف_کرو LOCALE_SDAYNAME6 0x0000002F
#تعریف_کرو LOCALE_SDAYNAME7 0x00000030
#تعریف_کرو LOCALE_SABBREVDAYNAME1 0x00000031
#تعریف_کرو LOCALE_SABBREVDAYNAME2 0x00000032
#تعریف_کرو LOCALE_SABBREVDAYNAME3 0x00000033
#تعریف_کرو LOCALE_SABBREVDAYNAME4 0x00000034
#تعریف_کرو LOCALE_SABBREVDAYNAME5 0x00000035
#تعریف_کرو LOCALE_SABBREVDAYNAME6 0x00000036
#تعریف_کرو LOCALE_SABBREVDAYNAME7 0x00000037
#تعریف_کرو LOCALE_SMONTHNAME1 0x00000038
#تعریف_کرو LOCALE_SMONTHNAME2 0x00000039
#تعریف_کرو LOCALE_SMONTHNAME3 0x0000003A
#تعریف_کرو LOCALE_SMONTHNAME4 0x0000003B
#تعریف_کرو LOCALE_SMONTHNAME5 0x0000003C
#تعریف_کرو LOCALE_SMONTHNAME6 0x0000003D
#تعریف_کرو LOCALE_SMONTHNAME7 0x0000003E
#تعریف_کرو LOCALE_SMONTHNAME8 0x0000003F
#تعریف_کرو LOCALE_SMONTHNAME9 0x00000040
#تعریف_کرو LOCALE_SMONTHNAME10 0x00000041
#تعریف_کرو LOCALE_SMONTHNAME11 0x00000042
#تعریف_کرو LOCALE_SMONTHNAME12 0x00000043
#تعریف_کرو LOCALE_SMONTHNAME13 0x0000100E
#تعریف_کرو LOCALE_SABBREVMONTHNAME1 0x00000044
#تعریف_کرو LOCALE_SABBREVMONTHNAME2 0x00000045
#تعریف_کرو LOCALE_SABBREVMONTHNAME3 0x00000046
#تعریف_کرو LOCALE_SABBREVMONTHNAME4 0x00000047
#تعریف_کرو LOCALE_SABBREVMONTHNAME5 0x00000048
#تعریف_کرو LOCALE_SABBREVMONTHNAME6 0x00000049
#تعریف_کرو LOCALE_SABBREVMONTHNAME7 0x0000004A
#تعریف_کرو LOCALE_SABBREVMONTHNAME8 0x0000004B
#تعریف_کرو LOCALE_SABBREVMONTHNAME9 0x0000004C
#تعریف_کرو LOCALE_SABBREVMONTHNAME10 0x0000004D
#تعریف_کرو LOCALE_SABBREVMONTHNAME11 0x0000004E
#تعریف_کرو LOCALE_SABBREVMONTHNAME12 0x0000004F
#تعریف_کرو LOCALE_SABBREVMONTHNAME13 0x0000100F

#تعریف_کرو LOCALE_SPOSITIVESIGN 0x00000050
#تعریف_کرو LOCALE_SNEGATIVESIGN 0x00000051
#تعریف_کرو LOCALE_IPOSSIGNPOSN 0x00000052
#تعریف_کرو LOCALE_INEGSIGNPOSN 0x00000053
#تعریف_کرو LOCALE_IPOSSYMPRECEDES 0x00000054
#تعریف_کرو LOCALE_IPOSSEPBYSPACE 0x00000055
#تعریف_کرو LOCALE_INEGSYMPRECEDES 0x00000056
#تعریف_کرو LOCALE_INEGSEPBYSPACE 0x00000057
#تعریف_کرو LOCALE_FONTSIGNATURE 0x00000058
#تعریف_کرو LOCALE_SISO639LANGNAME 0x00000059
#تعریف_کرو LOCALE_SISO3166CTRYNAME 0x0000005A

#تعریف_کرو LOCALE_IDEFAULTEBCDICCODEPAGE 0x00001012
#تعریف_کرو LOCALE_IPAPERSIZE 0x0000100A
#تعریف_کرو LOCALE_SENGCURRNAME 0x00001007
#تعریف_کرو LOCALE_SNATIVECURRNAME 0x00001008
#تعریف_کرو LOCALE_SYEARMONTH 0x00001006
#تعریف_کرو LOCALE_SSORTNAME 0x00001013
#تعریف_کرو LOCALE_IDIGITSUBSTITUTION 0x00001014

#تعریف_کرو وقت_NOMINUTESORSECONDS 0x00000001
#تعریف_کرو وقت_NOSECONDS 0x00000002
#تعریف_کرو وقت_NOTIMEMARKER 0x00000004
#تعریف_کرو وقت_FORCE24_HOURFORMAT 0x00000008

#تعریف_کرو DATE_SHORTDATE 0x00000001
#تعریف_کرو DATE_LONGDATE 0x00000002
#تعریف_کرو DATE_USE_ALT_CALENDAR 0x00000004
#تعریف_کرو DATE_YEARMONTH 0x00000008
#تعریف_کرو DATE_LTRREADING 0x00000010
#تعریف_کرو DATE_RTLREADING 0x00000020

#تعریف_کرو CAL_NOUSEROVERRIDE LOCALE_NOUSEROVERRIDE
#تعریف_کرو CAL_USE_CP_ACP LOCALE_USE_CP_ACP
#تعریف_کرو CAL_RETURN_نمبر LOCALE_RETURN_نمبر

#تعریف_کرو CAL_ICALINTVALUE 0x00000001
#تعریف_کرو CAL_SCALNAME 0x00000002
#تعریف_کرو CAL_IYEAROFFSETRANGE 0x00000003
#تعریف_کرو CAL_SERASTRING 0x00000004
#تعریف_کرو CAL_SSHORTDATE 0x00000005
#تعریف_کرو CAL_SLONGDATE 0x00000006
#تعریف_کرو CAL_SDAYNAME1 0x00000007
#تعریف_کرو CAL_SDAYNAME2 0x00000008
#تعریف_کرو CAL_SDAYNAME3 0x00000009
#تعریف_کرو CAL_SDAYNAME4 0x0000000a
#تعریف_کرو CAL_SDAYNAME5 0x0000000b
#تعریف_کرو CAL_SDAYNAME6 0x0000000c
#تعریف_کرو CAL_SDAYNAME7 0x0000000d
#تعریف_کرو CAL_SABBREVDAYNAME1 0x0000000e
#تعریف_کرو CAL_SABBREVDAYNAME2 0x0000000f
#تعریف_کرو CAL_SABBREVDAYNAME3 0x00000010
#تعریف_کرو CAL_SABBREVDAYNAME4 0x00000011
#تعریف_کرو CAL_SABBREVDAYNAME5 0x00000012
#تعریف_کرو CAL_SABBREVDAYNAME6 0x00000013
#تعریف_کرو CAL_SABBREVDAYNAME7 0x00000014
#تعریف_کرو CAL_SMONTHNAME1 0x00000015
#تعریف_کرو CAL_SMONTHNAME2 0x00000016
#تعریف_کرو CAL_SMONTHNAME3 0x00000017
#تعریف_کرو CAL_SMONTHNAME4 0x00000018
#تعریف_کرو CAL_SMONTHNAME5 0x00000019
#تعریف_کرو CAL_SMONTHNAME6 0x0000001a
#تعریف_کرو CAL_SMONTHNAME7 0x0000001b
#تعریف_کرو CAL_SMONTHNAME8 0x0000001c
#تعریف_کرو CAL_SMONTHNAME9 0x0000001d
#تعریف_کرو CAL_SMONTHNAME10 0x0000001e
#تعریف_کرو CAL_SMONTHNAME11 0x0000001f
#تعریف_کرو CAL_SMONTHNAME12 0x00000020
#تعریف_کرو CAL_SMONTHNAME13 0x00000021
#تعریف_کرو CAL_SABBREVMONTHNAME1 0x00000022
#تعریف_کرو CAL_SABBREVMONTHNAME2 0x00000023
#تعریف_کرو CAL_SABBREVMONTHNAME3 0x00000024
#تعریف_کرو CAL_SABBREVMONTHNAME4 0x00000025
#تعریف_کرو CAL_SABBREVMONTHNAME5 0x00000026
#تعریف_کرو CAL_SABBREVMONTHNAME6 0x00000027
#تعریف_کرو CAL_SABBREVMONTHNAME7 0x00000028
#تعریف_کرو CAL_SABBREVMONTHNAME8 0x00000029
#تعریف_کرو CAL_SABBREVMONTHNAME9 0x0000002a
#تعریف_کرو CAL_SABBREVMONTHNAME10 0x0000002b
#تعریف_کرو CAL_SABBREVMONTHNAME11 0x0000002c
#تعریف_کرو CAL_SABBREVMONTHNAME12 0x0000002d
#تعریف_کرو CAL_SABBREVMONTHNAME13 0x0000002e
#تعریف_کرو CAL_SYEARMONTH 0x0000002f
#تعریف_کرو CAL_ITWODIGITYEARMAX 0x00000030

#تعریف_کرو ENUM_ALL_CALENDARS 0xffffffff

#تعریف_کرو CAL_GREGORIAN 1
#تعریف_کرو CAL_GREGORIAN_US 2
#تعریف_کرو CAL_JAPAN 3
#تعریف_کرو CAL_TAIWAN 4
#تعریف_کرو CAL_KOREA 5
#تعریف_کرو CAL_HIJRI 6
#تعریف_کرو CAL_THAI 7
#تعریف_کرو CAL_HEBREW 8
#تعریف_کرو CAL_GREGORIAN_ME_FRENCH 9
#تعریف_کرو CAL_GREGORIAN_ARABIC 10
#تعریف_کرو CAL_GREGORIAN_XLIT_ENGLISH 11
#تعریف_کرو CAL_GREGORIAN_XLIT_FRENCH 12

#تعریف_کرو LGRPID_WESTERN_EUROPE 0x0001
#تعریف_کرو LGRPID_CENTRAL_EUROPE 0x0002
#تعریف_کرو LGRPID_BALTIC 0x0003
#تعریف_کرو LGRPID_GREEK 0x0004
#تعریف_کرو LGRPID_CYRILLIC 0x0005
#تعریف_کرو LGRPID_TURKISH 0x0006
#تعریف_کرو LGRPID_JAPANESE 0x0007
#تعریف_کرو LGRPID_KOREAN 0x0008
#تعریف_کرو LGRPID_TRADITIONAL_CHINESE 0x0009
#تعریف_کرو LGRPID_SIMPLIFIED_CHINESE 0x000a
#تعریف_کرو LGRPID_THAI 0x000b
#تعریف_کرو LGRPID_HEBREW 0x000c
#تعریف_کرو LGRPID_ARABIC 0x000d
#تعریف_کرو LGRPID_VIETNAMESE 0x000e
#تعریف_کرو LGRPID_INDIC 0x000f
#تعریف_کرو LGRPID_GEORGIAN 0x0010
#تعریف_کرو LGRPID_ARMENIAN 0x0011

  قسمتعریف DWORD LGRPID;
  قسمتعریف DWORD LCTYPE;
  قسمتعریف DWORD CALTYPE;
  قسمتعریف DWORD CALID;

  قسمتعریف ساخت _cpinfo {
    UINT Max_Char_سائز;
    BYTE DefaultChar[MAX_DEFAULTCHAR];
    BYTE LeadByte[MAX_LEADBYTES];
  } CPINFO,*LPCPINFO;

  قسمتعریف ساخت _cpinfoexA {
    UINT Max_Char_سائز;
    BYTE DefaultChar[MAX_DEFAULTCHAR];
    BYTE LeadByte[MAX_LEADBYTES];
    WCHAR UnicodeDefaultChar;
    UINT رمز_صفحہ;
    CHAR رمز_صفحہ_Name[MAX_راستہ];
  } CPINFOEXA,*LPCPINFOEXA;

  قسمتعریف ساخت _cpinfoexW {
    UINT Max_Char_سائز;
    BYTE DefaultChar[MAX_DEFAULTCHAR];
    BYTE LeadByte[MAX_LEADBYTES];
    WCHAR UnicodeDefaultChar;
    UINT رمز_صفحہ;
    WCHAR رمز_صفحہ_Name[MAX_راستہ];
  } CPINFOEXW,*LPCPINFOEXW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف CPINFOEXW CPINFOEX;
  قسمتعریف LPCPINFOEXW LPCPINFOEX;
#ورنہ
  قسمتعریف CPINFOEXA CPINFOEX;
  قسمتعریف LPCPINFOEXA LPCPINFOEX;
#اگر_ختم

  قسمتعریف ساخت _numberfmtA {
    UINT عدد_Digits;
    UINT LeadingZero;
    UINT Grouping;
    LPSTR lpDecimalSep;
    LPSTR lpThousandSep;
    UINT Negative_ترتیب;
  } NUMBERFMTA,*LPNUMBERFMTA;

  قسمتعریف ساخت _numberfmtW {
    UINT عدد_Digits;
    UINT LeadingZero;
    UINT Grouping;
    LPWSTR lpDecimalSep;
    LPWSTR lpThousandSep;
    UINT Negative_ترتیب;
  } NUMBERFMTW,*LPNUMBERFMTW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف NUMBERFMTW NUMBERFMT;
  قسمتعریف LPNUMBERFMTW LPNUMBERFMT;
#ورنہ
  قسمتعریف NUMBERFMTA NUMBERFMT;
  قسمتعریف LPNUMBERFMTA LPNUMBERFMT;
#اگر_ختم

  قسمتعریف ساخت _currencyfmtA {
    UINT عدد_Digits;
    UINT LeadingZero;
    UINT Grouping;
    LPSTR lpDecimalSep;
    LPSTR lpThousandSep;
    UINT Negative_ترتیب;
    UINT مثبت_ترتیب;
    LPSTR lp_Currency_علامت;
  } CURRENCYFMTA,*LPCURRENCYFMTA;

  قسمتعریف ساخت _currencyfmtW {
    UINT عدد_Digits;
    UINT LeadingZero;
    UINT Grouping;
    LPWSTR lpDecimalSep;
    LPWSTR lpThousandSep;
    UINT Negative_ترتیب;
    UINT مثبت_ترتیب;
    LPWSTR lp_Currency_علامت;
  } CURRENCYFMTW,*LPCURRENCYFMTW;

#اگر_تعریف_شدہ UNICODE
  قسمتعریف CURRENCYFMTW CURRENCYFMT;
  قسمتعریف LPCURRENCYFMTW LPCURRENCYFMT;
#ورنہ
  قسمتعریف CURRENCYFMTA CURRENCYFMT;
  قسمتعریف LPCURRENCYFMTA LPCURRENCYFMT;
#اگر_ختم

  شمار SYSNLS_FUNCTION {
    COMPARE_STRING = 0x0001
  };

  قسمتعریف DWORD NLS_FUNCTION;

  قسمتعریف ساخت _nlsversioninfo{
    DWORD dw_NLSVersion_Info_سائز;
    DWORD dwNLSVersion;
    DWORD dw_Defined_نسخہ;
  } NLSVERSIONINFO,*LPNLSVERSIONINFO;

  قسمتعریف LONG GEOID;
  قسمتعریف DWORD GEOTYPE;
  قسمتعریف DWORD GEOCLASS;

#تعریف_کرو GEOID_NOT_دستیاب -1

  شمار SYSGEOTYPE {
    GEO_NATION = 0x0001,GEO_LATITUDE = 0x0002,GEO_LONGITUDE = 0x0003,GEO_ISO2 = 0x0004,GEO_ISO3 = 0x0005,GEO_RFC1766 = 0x0006,GEO_LCID = 0x0007,
    GEO_FRIENDLYNAME= 0x0008,GEO_OFFICIALNAME= 0x0009,GEO_TIMEZONES = 0x000A,GEO_OFFICIALLANGUAGES = 0x000B
  };

  شمار SYSGEOCLASS {
    GEOCLASS_NATION = 16,GEOCLASS_REGION = 14
  };
  
  قسمتعریف شمار  _NORM_FORM  {
  NormalizationOther   = 0,
  NormalizationC       = 0x1,
  NormalizationD       = 0x2,
  NormalizationKC      = 0x5,
  NormalizationKD      = 0x6 
} NORM_FORM;

  قسمتعریف WINBOOL (CALLBACK *LANGUAGEGROUP_ENUMPROCA)(LGRPID,LPSTR,LPSTR,DWORD,LONG_PTR);
  قسمتعریف WINBOOL (CALLBACK *LANGGROUPLOCALE_ENUMPROCA)(LGRPID,LCID,LPSTR,LONG_PTR);
  قسمتعریف WINBOOL (CALLBACK *UILANGUAGE_ENUMPROCA)(LPSTR,LONG_PTR);
  قسمتعریف WINBOOL (CALLBACK *LOCALE_ENUMPROCA)(LPSTR);
  قسمتعریف WINBOOL (CALLBACK *CODEPAGE_ENUMPROCA)(LPSTR);
  قسمتعریف WINBOOL (CALLBACK *DATEFMT_ENUMPROCA)(LPSTR);
  قسمتعریف WINBOOL (CALLBACK *DATEFMT_ENUMPROCEXA)(LPSTR,CALID);
  قسمتعریف WINBOOL (CALLBACK *TIMEFMT_ENUMPROCA)(LPSTR);
  قسمتعریف WINBOOL (CALLBACK *CALINFO_ENUMPROCA)(LPSTR);
  قسمتعریف WINBOOL (CALLBACK *CALINFO_ENUMPROCEXA)(LPSTR,CALID);
  قسمتعریف WINBOOL (CALLBACK *LANGUAGEGROUP_ENUMPROCW)(LGRPID,LPWSTR,LPWSTR,DWORD,LONG_PTR);
  قسمتعریف WINBOOL (CALLBACK *LANGGROUPLOCALE_ENUMPROCW)(LGRPID,LCID,LPWSTR,LONG_PTR);
  قسمتعریف WINBOOL (CALLBACK *UILANGUAGE_ENUMPROCW)(LPWSTR,LONG_PTR);
  قسمتعریف WINBOOL (CALLBACK *LOCALE_ENUMPROCW)(LPWSTR);
  قسمتعریف WINBOOL (CALLBACK *CODEPAGE_ENUMPROCW)(LPWSTR);
  قسمتعریف WINBOOL (CALLBACK *DATEFMT_ENUMPROCW)(LPWSTR);
  قسمتعریف WINBOOL (CALLBACK *DATEFMT_ENUMPROCEXW)(LPWSTR,CALID);
  قسمتعریف WINBOOL (CALLBACK *TIMEFMT_ENUMPROCW)(LPWSTR);
  قسمتعریف WINBOOL (CALLBACK *CALINFO_ENUMPROCW)(LPWSTR);
  قسمتعریف WINBOOL (CALLBACK *CALINFO_ENUMPROCEXW)(LPWSTR,CALID);
  قسمتعریف WINBOOL (CALLBACK *GEO_ENUMPROC)(GEOID);

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو LANGUAGEGROUP_ENUMPROC LANGUAGEGROUP_ENUMPROCW
#تعریف_کرو LANGGROUPLOCALE_ENUMPROC LANGGROUPLOCALE_ENUMPROCW
#تعریف_کرو UILANGUAGE_ENUMPROC UILANGUAGE_ENUMPROCW
#تعریف_کرو LOCALE_ENUMPROC LOCALE_ENUMPROCW
#تعریف_کرو CODEPAGE_ENUMPROC CODEPAGE_ENUMPROCW
#تعریف_کرو DATEFMT_ENUMPROC DATEFMT_ENUMPROCW
#تعریف_کرو DATEFMT_ENUMPROCEX DATEFMT_ENUMPROCEXW
#تعریف_کرو TIMEFMT_ENUMPROC TIMEFMT_ENUMPROCW
#تعریف_کرو CALINFO_ENUMPROC CALINFO_ENUMPROCW
#تعریف_کرو CALINFO_ENUMPROCEX CALINFO_ENUMPROCEXW
#ورنہ
#تعریف_کرو LANGUAGEGROUP_ENUMPROC LANGUAGEGROUP_ENUMPROCA
#تعریف_کرو LANGGROUPLOCALE_ENUMPROC LANGGROUPLOCALE_ENUMPROCA
#تعریف_کرو UILANGUAGE_ENUMPROC UILANGUAGE_ENUMPROCA
#تعریف_کرو LOCALE_ENUMPROC LOCALE_ENUMPROCA
#تعریف_کرو CODEPAGE_ENUMPROC CODEPAGE_ENUMPROCA
#تعریف_کرو DATEFMT_ENUMPROC DATEFMT_ENUMPROCA
#تعریف_کرو DATEFMT_ENUMPROCEX DATEFMT_ENUMPROCEXA
#تعریف_کرو TIMEFMT_ENUMPROC TIMEFMT_ENUMPROCA
#تعریف_کرو CALINFO_ENUMPROC CALINFO_ENUMPROCA
#تعریف_کرو CALINFO_ENUMPROCEX CALINFO_ENUMPROCEXA
#اگر_ختم

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو GetCPInfoEx GetCPInfoExW
#تعریف_کرو CompareString CompareStringW
#تعریف_کرو LCMapString LCMapStringW
#تعریف_کرو GetLocaleInfo GetLocaleInfoW
#تعریف_کرو سیٹ_Locale_Info سیٹ_Locale_Info_W
#تعریف_کرو GetCalendarInfo GetCalendarInfoW
#تعریف_کرو سیٹ_Calendar_Info سیٹ_Calendar_Info_W
#تعریف_کرو Get_وقت_Format Get_وقت_Format_W
#تعریف_کرو GetDateFormat GetDateFormatW
#تعریف_کرو Get_نمبر_Format Get_نمبر_Format_W
#تعریف_کرو GetCurrencyFormat GetCurrencyFormatW
#تعریف_کرو EnumCalendarInfo EnumCalendarInfoW
#تعریف_کرو EnumCalendarInfoEx EnumCalendarInfoExW
#تعریف_کرو Enum_وقت_Formats Enum_وقت_Formats_W
#تعریف_کرو EnumDateFormats EnumDateFormatsW
#تعریف_کرو EnumDateFormatsEx EnumDateFormatsExW
#تعریف_کرو GetGeoInfo GetGeoInfoW
#تعریف_کرو GetStringTypeEx GetStringTypeExW
#تعریف_کرو FoldString FoldStringW
#تعریف_کرو EnumSystemLanguageGroups EnumSystemLanguageGroupsW
#تعریف_کرو Enum_Language_گروہ_Locales Enum_Language_گروہ_Locales_W
#تعریف_کرو EnumUILanguages EnumUILanguagesW
#تعریف_کرو EnumSystemLocales EnumSystemLocalesW
#تعریف_کرو Enum_System_رمز_صفحات Enum_System_رمز_صفحات_W
#ورنہ
#تعریف_کرو GetCPInfoEx GetCPInfoExA
#تعریف_کرو CompareString CompareStringA
#تعریف_کرو LCMapString LCMapStringA
#تعریف_کرو GetLocaleInfo GetLocaleInfoA
#تعریف_کرو سیٹ_Locale_Info سیٹ_Locale_Info_A
#تعریف_کرو GetCalendarInfo GetCalendarInfoA
#تعریف_کرو سیٹ_Calendar_Info سیٹ_Calendar_Info_A
#تعریف_کرو Get_وقت_Format Get_وقت_Format_A
#تعریف_کرو GetDateFormat GetDateFormatA
#تعریف_کرو Get_نمبر_Format Get_نمبر_Format_A
#تعریف_کرو GetCurrencyFormat GetCurrencyFormatA
#تعریف_کرو EnumCalendarInfo EnumCalendarInfoA
#تعریف_کرو EnumCalendarInfoEx EnumCalendarInfoExA
#تعریف_کرو Enum_وقت_Formats Enum_وقت_Formats_A
#تعریف_کرو EnumDateFormats EnumDateFormatsA
#تعریف_کرو EnumDateFormatsEx EnumDateFormatsExA
#تعریف_کرو GetGeoInfo GetGeoInfoA
#تعریف_کرو GetStringTypeEx GetStringTypeExA
#تعریف_کرو FoldString FoldStringA
#تعریف_کرو EnumSystemLanguageGroups EnumSystemLanguageGroupsA
#تعریف_کرو Enum_Language_گروہ_Locales Enum_Language_گروہ_Locales_A
#تعریف_کرو EnumUILanguages EnumUILanguagesA
#تعریف_کرو EnumSystemLocales EnumSystemLocalesA
#تعریف_کرو Enum_System_رمز_صفحات Enum_System_رمز_صفحات_A
#اگر_ختم

  WINBASEAPI WINBOOL WINAPI Is_Valid_رمز_صفحہ(UINT رمز_صفحہ);
  WINBASEAPI UINT WINAPI GetACP(خالی);
  WINBASEAPI UINT WINAPI GetOEMCP(خالی);
  WINBASEAPI WINBOOL WINAPI GetCPInfo(UINT رمز_صفحہ,LPCPINFO lpCPInfo);
  WINBASEAPI WINBOOL WINAPI GetCPInfoExA(UINT رمز_صفحہ,DWORD dwFlags,LPCPINFOEXA lpCPInfoEx);
  WINBASEAPI WINBOOL WINAPI GetCPInfoExW(UINT رمز_صفحہ,DWORD dwFlags,LPCPINFOEXW lpCPInfoEx);
  WINBASEAPI WINBOOL WINAPI IsDBCSLeadByte(BYTE TestChar);
  WINBASEAPI WINBOOL WINAPI IsDBCSLeadByteEx(UINT رمز_صفحہ,BYTE TestChar);
  WINBASEAPI صحیح WINAPI Multi_Byte_مقصد_Wide_Char(UINT رمز_صفحہ,DWORD dwFlags,LPCSTR lpMultiByteStr,صحیح cbMultiByte,LPWSTR lpWideCharStr,صحیح cchWideChar);
  WINBASEAPI صحیح WINAPI Wide_Char_مقصد_Multi_Byte(UINT رمز_صفحہ,DWORD dwFlags,LPCWSTR lpWideCharStr,صحیح cchWideChar,LPSTR lpMultiByteStr,صحیح cbMultiByte,LPCSTR lpDefaultChar,LPBOOL lp_مستعمل_Default_Char);
  WINBASEAPI صحیح WINAPI CompareStringA(LCID Locale,DWORD dwCmpFlags,LPCSTR lpString1,صحیح cchCount1,LPCSTR lpString2,صحیح cchCount2);
  WINBASEAPI صحیح WINAPI CompareStringW(LCID Locale,DWORD dwCmpFlags,LPCWSTR lpString1,صحیح cchCount1,LPCWSTR lpString2,صحیح cchCount2);
  WINBASEAPI صحیح WINAPI LCMapStringA(LCID Locale,DWORD dwMapFlags,LPCSTR lpSrcStr,صحیح cchSrc,LPSTR lpDestStr,صحیح cchDest);
  WINBASEAPI صحیح WINAPI LCMapStringW(LCID Locale,DWORD dwMapFlags,LPCWSTR lpSrcStr,صحیح cchSrc,LPWSTR lpDestStr,صحیح cchDest);
  WINBASEAPI صحیح WINAPI GetLocaleInfoA(LCID Locale,LCTYPE LCType,LPSTR lpLCData,صحیح cch_ڈیٹا);
  WINBASEAPI صحیح WINAPI GetLocaleInfoW(LCID Locale,LCTYPE LCType,LPWSTR lpLCData,صحیح cch_ڈیٹا);
  WINBASEAPI WINBOOL WINAPI سیٹ_Locale_Info_A(LCID Locale,LCTYPE LCType,LPCSTR lpLCData);
  WINBASEAPI WINBOOL WINAPI سیٹ_Locale_Info_W(LCID Locale,LCTYPE LCType,LPCWSTR lpLCData);
  WINBASEAPI صحیح WINAPI GetCalendarInfoA(LCID Locale,CALID Calendar,CALTYPE CalType,LPSTR lp_Cal_ڈیٹا,صحیح cch_ڈیٹا,LPDWORD lp_قدر);
  WINBASEAPI صحیح WINAPI GetCalendarInfoW(LCID Locale,CALID Calendar,CALTYPE CalType,LPWSTR lp_Cal_ڈیٹا,صحیح cch_ڈیٹا,LPDWORD lp_قدر);
  WINBASEAPI WINBOOL WINAPI سیٹ_Calendar_Info_A(LCID Locale,CALID Calendar,CALTYPE CalType,LPCSTR lp_Cal_ڈیٹا);
  WINBASEAPI WINBOOL WINAPI سیٹ_Calendar_Info_W(LCID Locale,CALID Calendar,CALTYPE CalType,LPCWSTR lp_Cal_ڈیٹا);
  WINBASEAPI صحیح WINAPI Get_وقت_Format_A(LCID Locale,DWORD dwFlags,CONST SYSTEMTIME *lp_وقت,LPCSTR lpFormat,LPSTR lp_وقت_Str,صحیح cch_وقت);
  WINBASEAPI صحیح WINAPI Get_وقت_Format_W(LCID Locale,DWORD dwFlags,CONST SYSTEMTIME *lp_وقت,LPCWSTR lpFormat,LPWSTR lp_وقت_Str,صحیح cch_وقت);
  WINBASEAPI صحیح WINAPI GetDateFormatA(LCID Locale,DWORD dwFlags,CONST SYSTEMTIME *lpDate,LPCSTR lpFormat,LPSTR lpDateStr,صحیح cchDate);
  WINBASEAPI صحیح WINAPI GetDateFormatW(LCID Locale,DWORD dwFlags,CONST SYSTEMTIME *lpDate,LPCWSTR lpFormat,LPWSTR lpDateStr,صحیح cchDate);
  WINBASEAPI صحیح WINAPI Get_نمبر_Format_A(LCID Locale,DWORD dwFlags,LPCSTR lp_قدر,CONST NUMBERFMTA *lpFormat,LPSTR lp_نمبر_Str,صحیح cch_نمبر);
  WINBASEAPI صحیح WINAPI Get_نمبر_Format_W(LCID Locale,DWORD dwFlags,LPCWSTR lp_قدر,CONST NUMBERFMTW *lpFormat,LPWSTR lp_نمبر_Str,صحیح cch_نمبر);
  WINBASEAPI صحیح WINAPI GetCurrencyFormatA(LCID Locale,DWORD dwFlags,LPCSTR lp_قدر,CONST CURRENCYFMTA *lpFormat,LPSTR lpCurrencyStr,صحیح cchCurrency);
  WINBASEAPI صحیح WINAPI GetCurrencyFormatW(LCID Locale,DWORD dwFlags,LPCWSTR lp_قدر,CONST CURRENCYFMTW *lpFormat,LPWSTR lpCurrencyStr,صحیح cchCurrency);
  WINBASEAPI WINBOOL WINAPI EnumCalendarInfoA(CALINFO_ENUMPROCA lpCalInfoEnumProc,LCID Locale,CALID Calendar,CALTYPE CalType);
  WINBASEAPI WINBOOL WINAPI EnumCalendarInfoW(CALINFO_ENUMPROCW lpCalInfoEnumProc,LCID Locale,CALID Calendar,CALTYPE CalType);
  WINBASEAPI WINBOOL WINAPI EnumCalendarInfoExA(CALINFO_ENUMPROCEXA lpCalInfoEnumProcEx,LCID Locale,CALID Calendar,CALTYPE CalType);
  WINBASEAPI WINBOOL WINAPI EnumCalendarInfoExW(CALINFO_ENUMPROCEXW lpCalInfoEnumProcEx,LCID Locale,CALID Calendar,CALTYPE CalType);
  WINBASEAPI WINBOOL WINAPI Enum_وقت_Formats_A(TIMEFMT_ENUMPROCA lp_وقت_Fmt_Enum_Proc,LCID Locale,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Enum_وقت_Formats_W(TIMEFMT_ENUMPROCW lp_وقت_Fmt_Enum_Proc,LCID Locale,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI EnumDateFormatsA(DATEFMT_ENUMPROCA lpDateFmtEnumProc,LCID Locale,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI EnumDateFormatsW(DATEFMT_ENUMPROCW lpDateFmtEnumProc,LCID Locale,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI EnumDateFormatsExA(DATEFMT_ENUMPROCEXA lpDateFmtEnumProcEx,LCID Locale,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI EnumDateFormatsExW(DATEFMT_ENUMPROCEXW lpDateFmtEnumProcEx,LCID Locale,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Is_Valid_Language_گروہ(LGRPID Language_گروہ,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI GetNLSVersion(NLS_FUNCTION Function,LCID Locale,LPNLSVERSIONINFO lp_نسخہ_Information);
  WINBASEAPI WINBOOL WINAPI IsNLSDefinedString(NLS_FUNCTION Function,DWORD dwFlags,LPNLSVERSIONINFO lp_نسخہ_Information,LPCWSTR lpString,INT cchStr);
  WINBASEAPI WINBOOL WINAPI IsValidLocale(LCID Locale,DWORD dwFlags);
  WINBASEAPI صحیح WINAPI GetGeoInfoA(GEOID Location,GEOTYPE GeoType,LPSTR lp_Geo_ڈیٹا,صحیح cch_ڈیٹا,LANGID LangId);
  WINBASEAPI صحیح WINAPI GetGeoInfoW(GEOID Location,GEOTYPE GeoType,LPWSTR lp_Geo_ڈیٹا,صحیح cch_ڈیٹا,LANGID LangId);
  WINBASEAPI WINBOOL WINAPI EnumSystemGeoID(GEOCLASS GeoClass,GEOID والد_Geo_Id,GEO_ENUMPROC lpGeoEnumProc);
  WINBASEAPI GEOID WINAPI GetUserGeoID(GEOCLASS GeoClass);
  WINBASEAPI WINBOOL WINAPI سیٹ_User_Geo_ID(GEOID GeoId);
  WINBASEAPI LCID WINAPI ConvertDefaultLocale(LCID Locale);
  WINBASEAPI LCID WINAPI GetThreadLocale(خالی);
  WINBASEAPI WINBOOL WINAPI سیٹ_Thread_Locale(LCID Locale);
  WINBASEAPI LANGID WINAPI GetSystemDefaultUILanguage(خالی);
  WINBASEAPI LANGID WINAPI GetUserDefaultUILanguage(خالی);
  WINBASEAPI LANGID WINAPI GetSystemDefaultLangID(خالی);
  WINBASEAPI LANGID WINAPI GetUserDefaultLangID(خالی);
  WINBASEAPI LCID WINAPI GetSystemDefaultLCID(خالی);
  WINBASEAPI LCID WINAPI GetUserDefaultLCID(خالی);
  WINBASEAPI WINBOOL WINAPI GetStringTypeExA(LCID Locale,DWORD dwInfoType,LPCSTR lpSrcStr,صحیح cchSrc,LPWORD lpCharType);
  WINBASEAPI WINBOOL WINAPI GetStringTypeExW(LCID Locale,DWORD dwInfoType,LPCWSTR lpSrcStr,صحیح cchSrc,LPWORD lpCharType);
  WINBASEAPI WINBOOL WINAPI GetStringTypeA(LCID Locale,DWORD dwInfoType,LPCSTR lpSrcStr,صحیح cchSrc,LPWORD lpCharType);
  WINBASEAPI WINBOOL WINAPI GetStringTypeW(DWORD dwInfoType,LPCWSTR lpSrcStr,صحیح cchSrc,LPWORD lpCharType);
  WINBASEAPI صحیح WINAPI FoldStringA(DWORD dwMapFlags,LPCSTR lpSrcStr,صحیح cchSrc,LPSTR lpDestStr,صحیح cchDest);
  WINBASEAPI صحیح WINAPI FoldStringW(DWORD dwMapFlags,LPCWSTR lpSrcStr,صحیح cchSrc,LPWSTR lpDestStr,صحیح cchDest);
  WINBASEAPI WINBOOL WINAPI EnumSystemLanguageGroupsA(LANGUAGEGROUP_ENUMPROCA lp_Language_گروہ_Enum_Proc,DWORD dwFlags,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumSystemLanguageGroupsW(LANGUAGEGROUP_ENUMPROCW lp_Language_گروہ_Enum_Proc,DWORD dwFlags,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Language_گروہ_Locales_A(LANGGROUPLOCALE_ENUMPROCA lp_Lang_گروہ_Locale_Enum_Proc,LGRPID Language_گروہ,DWORD dwFlags,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI Enum_Language_گروہ_Locales_W(LANGGROUPLOCALE_ENUMPROCW lp_Lang_گروہ_Locale_Enum_Proc,LGRPID Language_گروہ,DWORD dwFlags,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumUILanguagesA(UILANGUAGE_ENUMPROCA lpUILanguageEnumProc,DWORD dwFlags,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumUILanguagesW(UILANGUAGE_ENUMPROCW lpUILanguageEnumProc,DWORD dwFlags,LONG_PTR lParam);
  WINBASEAPI WINBOOL WINAPI EnumSystemLocalesA(LOCALE_ENUMPROCA lpLocaleEnumProc,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI EnumSystemLocalesW(LOCALE_ENUMPROCW lpLocaleEnumProc,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Enum_System_رمز_صفحات_A(CODEPAGE_ENUMPROCA lp_رمز_صفحہ_Enum_Proc,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI Enum_System_رمز_صفحات_W(CODEPAGE_ENUMPROCW lp_رمز_صفحہ_Enum_Proc,DWORD dwFlags);
  WINBASEAPI WINBOOL WINAPI IsNormalizedString(NORM_FORM NormForm,LPCWSTR lpString,صحیح cw_لمبائی);
  WINBASEAPI صحیح WINAPI NormalizeString(NORM_FORM NormForm,LPCWSTR lpSrcString,صحیح cw_Src_لمبائی,LPWSTR lpDstString,صحیح cw_Dst_لمبائی);
  WINBASEAPI صحیح WINAPI Idn_مقصد_Ascii(DWORD dwFlags,LPCWSTR lpUnicodeCharStr,صحیح cchUnicodeChar,LPWSTR lpASCIICharStr,صحیح cchASCIIChar);
  WINBASEAPI صحیح WINAPI Idn_مقصد_Nameprep_Unicode(DWORD dwFlags,LPCWSTR lpUnicodeCharStr,صحیح cchUnicodeChar,LPWSTR lpNameprepCharStr,صحیح cchNameprepChar);
  WINBASEAPI صحیح WINAPI Idn_مقصد_Unicode(DWORD dwFlags,LPCWSTR lpASCIICharStr,صحیح cchASCIIChar,LPWSTR lpUnicodeCharStr,صحیح cchUnicodeChar);

#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
