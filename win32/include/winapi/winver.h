/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_تعریف_نشده VER_H
#تعریف_کن VER_H

#اگر_تعریف_شده __cplusplus
خارجي "C" {
#پایان_اگر

#تعریف_کن VS_FILE_INFO RT_نسخه
#تعریف_کن VS_نسخه_INFO 1
#تعریف_کن VS_USER_DEFINED 100

#تعریف_کن VS_FFI_SIGNATURE 0xFEEF04BDL
#تعریف_کن VS_FFI_STRUCVERSION 0x00010000L
#تعریف_کن VS_FFI_FILEFLAGSMASK 0x0000003FL

#تعریف_کن VS_FF_DEBUG 0x00000001L
#تعریف_کن VS_FF_PRERELEASE 0x00000002L
#تعریف_کن VS_FF_PATCHED 0x00000004L
#تعریف_کن VS_FF_PRIVATEBUILD 0x00000008L
#تعریف_کن VS_FF_INFOINFERRED 0x00000010L
#تعریف_کن VS_FF_SPECIALBUILD 0x00000020L

#تعریف_کن VOS_UNKNOWN 0x00000000L
#تعریف_کن VOS_DOS 0x00010000L
#تعریف_کن VOS_OS216 0x00020000L
#تعریف_کن VOS_OS232 0x00030000L
#تعریف_کن VOS_NT 0x00040000L
#تعریف_کن VOS_WINCE 0x00050000L

#تعریف_کن VOS_پایه 0x00000000L
#تعریف_کن VOS__WINDOWS16 0x00000001L
#تعریف_کن VOS__PM16 0x00000002L
#تعریف_کن VOS__PM32 0x00000003L
#تعریف_کن VOS__WINDOWS32 0x00000004L

#تعریف_کن VOS_DOS_WINDOWS16 0x00010001L
#تعریف_کن VOS_DOS_WINDOWS32 0x00010004L
#تعریف_کن VOS_OS216_PM16 0x00020002L
#تعریف_کن VOS_OS232_PM32 0x00030003L
#تعریف_کن VOS_NT_WINDOWS32 0x00040004L

#تعریف_کن VFT_UNKNOWN 0x00000000L
#تعریف_کن VFT_APP 0x00000001L
#تعریف_کن VFT_DLL 0x00000002L
#تعریف_کن VFT_DRV 0x00000003L
#تعریف_کن VFT_FONT 0x00000004L
#تعریف_کن VFT_VXD 0x00000005L
#تعریف_کن VFT_STATIC_LIB 0x00000007L

#تعریف_کن VFT2_UNKNOWN 0x00000000L
#تعریف_کن VFT2_DRV_PRINTER 0x00000001L
#تعریف_کن VFT2_DRV_KEYBOARD 0x00000002L
#تعریف_کن VFT2_DRV_LANGUAGE 0x00000003L
#تعریف_کن VFT2_DRV_DISPLAY 0x00000004L
#تعریف_کن VFT2_DRV_MOUSE 0x00000005L
#تعریف_کن VFT2_DRV_شبکه 0x00000006L
#تعریف_کن VFT2_DRV_SYSTEM 0x00000007L
#تعریف_کن VFT2_DRV_INSTALLABLE 0x00000008L
#تعریف_کن VFT2_DRV_SOUND 0x00000009L
#تعریف_کن VFT2_DRV_COMM 0x0000000AL
#تعریف_کن VFT2_DRV_INPUTMETHOD 0x0000000BL
#تعریف_کن VFT2_DRV_VERSIONED_PRINTER 0x0000000CL

#تعریف_کن VFT2_FONT_RASTER 0x00000001L
#تعریف_کن VFT2_FONT_وکتور 0x00000002L
#تعریف_کن VFT2_FONT_TRUETYPE 0x00000003L

#تعریف_کن VFFF_ISSHAREDFILE 0x0001

#تعریف_کن VFF_CURNEDEST 0x0001
#تعریف_کن VFF_FILEINUSE 0x0002
#تعریف_کن VFF_BUFFTOOSMALL 0x0004

#تعریف_کن VIFF_FORCEINSTALL 0x0001
#تعریف_کن VIFF_DONTDELETEOLD 0x0002

#تعریف_کن VIF_TEMPFILE 0x00000001L
#تعریف_کن VIF_MISMATCH 0x00000002L
#تعریف_کن VIF_SRCOLD 0x00000004L

#تعریف_کن VIF_DIFFLANG 0x00000008L
#تعریف_کن VIF_DIFFCODEPG 0x00000010L
#تعریف_کن VIF_DIFFTYPE 0x00000020L

#تعریف_کن VIF_WRITEPROT 0x00000040L
#تعریف_کن VIF_FILEINUSE 0x00000080L
#تعریف_کن VIF_OUTOFSPACE 0x00000100L
#تعریف_کن VIF_ACCESSVIOLATION 0x00000200L
#تعریف_کن VIF_SHARINGVIOLATION 0x00000400L
#تعریف_کن VIF_CANNOTCREATE 0x00000800L
#تعریف_کن VIF_CANNOTDELETE 0x00001000L
#تعریف_کن VIF_CANNOTRENAME 0x00002000L
#تعریف_کن VIF_CANNOTDELETECUR 0x00004000L
#تعریف_کن VIF_OUTOFMEMORY 0x00008000L

#تعریف_کن VIF_CANNOTREADSRC 0x00010000L
#تعریف_کن VIF_CANNOTREADDST 0x00020000L

#تعریف_کن VIF_BUFFTOOSMALL 0x00040000L
#تعریف_کن VIF_CANNOTLOADLZ32 0x00080000L
#تعریف_کن VIF_CANNOTLOADCABINET 0x00100000L

#اگر_تعریف_نشده RC_INVOKED

  تعريفنوع بنية برچسب_VS_FIXEDFILEINFO
  {
    DWORD dwSignature;
    DWORD dw_Struc_نسخه;
    DWORD dw_File_نسخه_MS;
    DWORD dw_File_نسخه_LS;
    DWORD dw_حاصلضرب_نسخه_MS;
    DWORD dw_حاصلضرب_نسخه_LS;
    DWORD dw_File_Flags_ماسک;
    DWORD dwFileFlags;
    DWORD dwFileOS;
    DWORD dwFileType;
    DWORD dwFileSubtype;
    DWORD dwFileDateMS;
    DWORD dwFileDateLS;
  } VS_FIXEDFILEINFO;

#اگر_تعریف_شده UNICODE
#تعریف_کن Ver_پیدا_کن_File Ver_پیدا_کن_File_W
#تعریف_کن VerInstallFile VerInstallFileW
#تعریف_کن Get_File_نسخه_Info_اندازه Get_File_نسخه_Info_اندازه_W
#تعریف_کن Get_File_نسخه_Info Get_File_نسخه_Info_W
#تعریف_کن VerLanguageName VerLanguageNameW
#تعریف_کن Ver_Query_مقدار Ver_Query_مقدار_W
#وإلا
#تعریف_کن Ver_پیدا_کن_File Ver_پیدا_کن_File_A
#تعریف_کن VerInstallFile VerInstallFileA
#تعریف_کن Get_File_نسخه_Info_اندازه Get_File_نسخه_Info_اندازه_A
#تعریف_کن Get_File_نسخه_Info Get_File_نسخه_Info_A
#تعریف_کن VerLanguageName VerLanguageNameA
#تعریف_کن Ver_Query_مقدار Ver_Query_مقدار_A
#پایان_اگر

  DWORD WINAPI Ver_پیدا_کن_File_A(DWORD uFlags,LPSTR szFileName,LPSTR szWinDir,LPSTR szAppDir,LPSTR szCurDir,PUINT lpuCurDirLen,LPSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI Ver_پیدا_کن_File_W(DWORD uFlags,LPWSTR szFileName,LPWSTR szWinDir,LPWSTR szAppDir,LPWSTR szCurDir,PUINT lpuCurDirLen,LPWSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI VerInstallFileA(DWORD uFlags,LPSTR szSrcFileName,LPSTR szDestFileName,LPSTR szSrcDir,LPSTR szDestDir,LPSTR szCurDir,LPSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI VerInstallFileW(DWORD uFlags,LPWSTR szSrcFileName,LPWSTR szDestFileName,LPWSTR szSrcDir,LPWSTR szDestDir,LPWSTR szCurDir,LPWSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI Get_File_نسخه_Info_اندازه_A(LPCSTR lptstrFilename,LPDWORD lpdwHandle);
  DWORD WINAPI Get_File_نسخه_Info_اندازه_W(LPCWSTR lptstrFilename,LPDWORD lpdwHandle);
  WINBOOL WINAPI Get_File_نسخه_Info_A(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lp_داده);
  WINBOOL WINAPI Get_File_نسخه_Info_W(LPCWSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lp_داده);
  DWORD WINAPI VerLanguageNameA(DWORD wLang,LPSTR szLang,DWORD n_اندازه);
  DWORD WINAPI VerLanguageNameW(DWORD wLang,LPWSTR szLang,DWORD n_اندازه);
  WINBOOL WINAPI Ver_Query_مقدار_A(ثابت LPVOID p_بلوک,LPSTR lp_Sub_بلوک,LPVOID *lplp_میانگیر,PUINT puLen);
  WINBOOL WINAPI Ver_Query_مقدار_W(ثابت LPVOID p_بلوک,LPWSTR lp_Sub_بلوک,LPVOID *lplp_میانگیر,PUINT puLen);
#پایان_اگر

#اگر_تعریف_شده __cplusplus
}
#پایان_اگر
#پایان_اگر
