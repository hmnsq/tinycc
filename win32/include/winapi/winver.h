/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#اگر_غیر_تعریف_شدہ VER_H
#تعریف_کرو VER_H

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

#تعریف_کرو VS_FILE_INFO RT_نسخہ
#تعریف_کرو VS_نسخہ_INFO 1
#تعریف_کرو VS_USER_DEFINED 100

#تعریف_کرو VS_FFI_SIGNATURE 0xFEEF04BDL
#تعریف_کرو VS_FFI_STRUCVERSION 0x00010000L
#تعریف_کرو VS_FFI_FILEFLAGSMASK 0x0000003FL

#تعریف_کرو VS_FF_DEBUG 0x00000001L
#تعریف_کرو VS_FF_PRERELEASE 0x00000002L
#تعریف_کرو VS_FF_PATCHED 0x00000004L
#تعریف_کرو VS_FF_PRIVATEBUILD 0x00000008L
#تعریف_کرو VS_FF_INFOINFERRED 0x00000010L
#تعریف_کرو VS_FF_SPECIALBUILD 0x00000020L

#تعریف_کرو VOS_UNKNOWN 0x00000000L
#تعریف_کرو VOS_DOS 0x00010000L
#تعریف_کرو VOS_OS216 0x00020000L
#تعریف_کرو VOS_OS232 0x00030000L
#تعریف_کرو VOS_NT 0x00040000L
#تعریف_کرو VOS_WINCE 0x00050000L

#تعریف_کرو VOS_بنیاد 0x00000000L
#تعریف_کرو VOS__WINDOWS16 0x00000001L
#تعریف_کرو VOS__PM16 0x00000002L
#تعریف_کرو VOS__PM32 0x00000003L
#تعریف_کرو VOS__WINDOWS32 0x00000004L

#تعریف_کرو VOS_DOS_WINDOWS16 0x00010001L
#تعریف_کرو VOS_DOS_WINDOWS32 0x00010004L
#تعریف_کرو VOS_OS216_PM16 0x00020002L
#تعریف_کرو VOS_OS232_PM32 0x00030003L
#تعریف_کرو VOS_NT_WINDOWS32 0x00040004L

#تعریف_کرو VFT_UNKNOWN 0x00000000L
#تعریف_کرو VFT_APP 0x00000001L
#تعریف_کرو VFT_DLL 0x00000002L
#تعریف_کرو VFT_DRV 0x00000003L
#تعریف_کرو VFT_FONT 0x00000004L
#تعریف_کرو VFT_VXD 0x00000005L
#تعریف_کرو VFT_STATIC_LIB 0x00000007L

#تعریف_کرو VFT2_UNKNOWN 0x00000000L
#تعریف_کرو VFT2_DRV_PRINTER 0x00000001L
#تعریف_کرو VFT2_DRV_KEYBOARD 0x00000002L
#تعریف_کرو VFT2_DRV_LANGUAGE 0x00000003L
#تعریف_کرو VFT2_DRV_DISPLAY 0x00000004L
#تعریف_کرو VFT2_DRV_MOUSE 0x00000005L
#تعریف_کرو VFT2_DRV_جال 0x00000006L
#تعریف_کرو VFT2_DRV_SYSTEM 0x00000007L
#تعریف_کرو VFT2_DRV_INSTALLABLE 0x00000008L
#تعریف_کرو VFT2_DRV_SOUND 0x00000009L
#تعریف_کرو VFT2_DRV_COMM 0x0000000AL
#تعریف_کرو VFT2_DRV_INPUTMETHOD 0x0000000BL
#تعریف_کرو VFT2_DRV_VERSIONED_PRINTER 0x0000000CL

#تعریف_کرو VFT2_FONT_RASTER 0x00000001L
#تعریف_کرو VFT2_FONT_سمتیہ 0x00000002L
#تعریف_کرو VFT2_FONT_TRUETYPE 0x00000003L

#تعریف_کرو VFFF_ISSHAREDFILE 0x0001

#تعریف_کرو VFF_CURNEDEST 0x0001
#تعریف_کرو VFF_FILEINUSE 0x0002
#تعریف_کرو VFF_BUFFTOOSMALL 0x0004

#تعریف_کرو VIFF_FORCEINSTALL 0x0001
#تعریف_کرو VIFF_DONTDELETEOLD 0x0002

#تعریف_کرو VIF_TEMPFILE 0x00000001L
#تعریف_کرو VIF_MISMATCH 0x00000002L
#تعریف_کرو VIF_SRCOLD 0x00000004L

#تعریف_کرو VIF_DIFFLANG 0x00000008L
#تعریف_کرو VIF_DIFFCODEPG 0x00000010L
#تعریف_کرو VIF_DIFFTYPE 0x00000020L

#تعریف_کرو VIF_WRITEPROT 0x00000040L
#تعریف_کرو VIF_FILEINUSE 0x00000080L
#تعریف_کرو VIF_OUTOFSPACE 0x00000100L
#تعریف_کرو VIF_ACCESSVIOLATION 0x00000200L
#تعریف_کرو VIF_SHARINGVIOLATION 0x00000400L
#تعریف_کرو VIF_CANNOTCREATE 0x00000800L
#تعریف_کرو VIF_CANNOTDELETE 0x00001000L
#تعریف_کرو VIF_CANNOTRENAME 0x00002000L
#تعریف_کرو VIF_CANNOTDELETECUR 0x00004000L
#تعریف_کرو VIF_OUTOFMEMORY 0x00008000L

#تعریف_کرو VIF_CANNOTREADSRC 0x00010000L
#تعریف_کرو VIF_CANNOTREADDST 0x00020000L

#تعریف_کرو VIF_BUFFTOOSMALL 0x00040000L
#تعریف_کرو VIF_CANNOTLOADLZ32 0x00080000L
#تعریف_کرو VIF_CANNOTLOADCABINET 0x00100000L

#اگر_غیر_تعریف_شدہ RC_INVOKED

  قسمتعریف ساخت لیبل_VS_FIXEDFILEINFO
  {
    DWORD dwSignature;
    DWORD dw_Struc_نسخہ;
    DWORD dw_File_نسخہ_MS;
    DWORD dw_File_نسخہ_LS;
    DWORD dw_حاصل_ضرب_نسخہ_MS;
    DWORD dw_حاصل_ضرب_نسخہ_LS;
    DWORD dw_File_Flags_نقاب;
    DWORD dwFileFlags;
    DWORD dwFileOS;
    DWORD dwFileType;
    DWORD dwFileSubtype;
    DWORD dwFileDateMS;
    DWORD dwFileDateLS;
  } VS_FIXEDFILEINFO;

#اگر_تعریف_شدہ UNICODE
#تعریف_کرو Ver_ڈھونڈو_File Ver_ڈھونڈو_File_W
#تعریف_کرو VerInstallFile VerInstallFileW
#تعریف_کرو Get_File_نسخہ_Info_سائز Get_File_نسخہ_Info_سائز_W
#تعریف_کرو Get_File_نسخہ_Info Get_File_نسخہ_Info_W
#تعریف_کرو VerLanguageName VerLanguageNameW
#تعریف_کرو Ver_Query_قدر Ver_Query_قدر_W
#ورنہ
#تعریف_کرو Ver_ڈھونڈو_File Ver_ڈھونڈو_File_A
#تعریف_کرو VerInstallFile VerInstallFileA
#تعریف_کرو Get_File_نسخہ_Info_سائز Get_File_نسخہ_Info_سائز_A
#تعریف_کرو Get_File_نسخہ_Info Get_File_نسخہ_Info_A
#تعریف_کرو VerLanguageName VerLanguageNameA
#تعریف_کرو Ver_Query_قدر Ver_Query_قدر_A
#اگر_ختم

  DWORD WINAPI Ver_ڈھونڈو_File_A(DWORD uFlags,LPSTR szFileName,LPSTR szWinDir,LPSTR szAppDir,LPSTR szCurDir,PUINT lpuCurDirLen,LPSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI Ver_ڈھونڈو_File_W(DWORD uFlags,LPWSTR szFileName,LPWSTR szWinDir,LPWSTR szAppDir,LPWSTR szCurDir,PUINT lpuCurDirLen,LPWSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI VerInstallFileA(DWORD uFlags,LPSTR szSrcFileName,LPSTR szDestFileName,LPSTR szSrcDir,LPSTR szDestDir,LPSTR szCurDir,LPSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI VerInstallFileW(DWORD uFlags,LPWSTR szSrcFileName,LPWSTR szDestFileName,LPWSTR szSrcDir,LPWSTR szDestDir,LPWSTR szCurDir,LPWSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI Get_File_نسخہ_Info_سائز_A(LPCSTR lptstrFilename,LPDWORD lpdwHandle);
  DWORD WINAPI Get_File_نسخہ_Info_سائز_W(LPCWSTR lptstrFilename,LPDWORD lpdwHandle);
  WINBOOL WINAPI Get_File_نسخہ_Info_A(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lp_ڈیٹا);
  WINBOOL WINAPI Get_File_نسخہ_Info_W(LPCWSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lp_ڈیٹا);
  DWORD WINAPI VerLanguageNameA(DWORD wLang,LPSTR szLang,DWORD n_سائز);
  DWORD WINAPI VerLanguageNameW(DWORD wLang,LPWSTR szLang,DWORD n_سائز);
  WINBOOL WINAPI Ver_Query_قدر_A(ثابت LPVOID p_بلاک,LPSTR lp_Sub_بلاک,LPVOID *lplp_بفر,PUINT puLen);
  WINBOOL WINAPI Ver_Query_قدر_W(ثابت LPVOID p_بلاک,LPWSTR lp_Sub_بلاک,LPVOID *lplp_بفر,PUINT puLen);
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم
#اگر_ختم
