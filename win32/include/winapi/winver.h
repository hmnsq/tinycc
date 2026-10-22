/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित VER_H
#घोषणा VER_H

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#घोषणा VS_FILE_INFO RT_VERSION
#घोषणा VS_VERSION_INFO 1
#घोषणा VS_USER_DEFINED 100

#घोषणा VS_FFI_SIGNATURE 0xFEEF04BDL
#घोषणा VS_FFI_STRUCVERSION 0x00010000L
#घोषणा VS_FFI_FILEFLAGSMASK 0x0000003FL

#घोषणा VS_FF_DEBUG 0x00000001L
#घोषणा VS_FF_PRERELEASE 0x00000002L
#घोषणा VS_FF_PATCHED 0x00000004L
#घोषणा VS_FF_PRIVATEBUILD 0x00000008L
#घोषणा VS_FF_INFOINFERRED 0x00000010L
#घोषणा VS_FF_SPECIALBUILD 0x00000020L

#घोषणा VOS_UNKNOWN 0x00000000L
#घोषणा VOS_DOS 0x00010000L
#घोषणा VOS_OS216 0x00020000L
#घोषणा VOS_OS232 0x00030000L
#घोषणा VOS_NT 0x00040000L
#घोषणा VOS_WINCE 0x00050000L

#घोषणा VOS__BASE 0x00000000L
#घोषणा VOS__WINDOWS16 0x00000001L
#घोषणा VOS__PM16 0x00000002L
#घोषणा VOS__PM32 0x00000003L
#घोषणा VOS__WINDOWS32 0x00000004L

#घोषणा VOS_DOS_WINDOWS16 0x00010001L
#घोषणा VOS_DOS_WINDOWS32 0x00010004L
#घोषणा VOS_OS216_PM16 0x00020002L
#घोषणा VOS_OS232_PM32 0x00030003L
#घोषणा VOS_NT_WINDOWS32 0x00040004L

#घोषणा VFT_UNKNOWN 0x00000000L
#घोषणा VFT_APP 0x00000001L
#घोषणा VFT_DLL 0x00000002L
#घोषणा VFT_DRV 0x00000003L
#घोषणा VFT_FONT 0x00000004L
#घोषणा VFT_VXD 0x00000005L
#घोषणा VFT_STATIC_LIB 0x00000007L

#घोषणा VFT2_UNKNOWN 0x00000000L
#घोषणा VFT2_DRV_PRINTER 0x00000001L
#घोषणा VFT2_DRV_KEYBOARD 0x00000002L
#घोषणा VFT2_DRV_LANGUAGE 0x00000003L
#घोषणा VFT2_DRV_DISPLAY 0x00000004L
#घोषणा VFT2_DRV_MOUSE 0x00000005L
#घोषणा VFT2_DRV_NETWORK 0x00000006L
#घोषणा VFT2_DRV_SYSTEM 0x00000007L
#घोषणा VFT2_DRV_INSTALLABLE 0x00000008L
#घोषणा VFT2_DRV_SOUND 0x00000009L
#घोषणा VFT2_DRV_COMM 0x0000000AL
#घोषणा VFT2_DRV_INPUTMETHOD 0x0000000BL
#घोषणा VFT2_DRV_VERSIONED_PRINTER 0x0000000CL

#घोषणा VFT2_FONT_RASTER 0x00000001L
#घोषणा VFT2_FONT_VECTOR 0x00000002L
#घोषणा VFT2_FONT_TRUETYPE 0x00000003L

#घोषणा VFFF_ISSHAREDFILE 0x0001

#घोषणा VFF_CURNEDEST 0x0001
#घोषणा VFF_FILEINUSE 0x0002
#घोषणा VFF_BUFFTOOSMALL 0x0004

#घोषणा VIFF_FORCEINSTALL 0x0001
#घोषणा VIFF_DONTDELETEOLD 0x0002

#घोषणा VIF_TEMPFILE 0x00000001L
#घोषणा VIF_MISMATCH 0x00000002L
#घोषणा VIF_SRCOLD 0x00000004L

#घोषणा VIF_DIFFLANG 0x00000008L
#घोषणा VIF_DIFFCODEPG 0x00000010L
#घोषणा VIF_DIFFTYPE 0x00000020L

#घोषणा VIF_WRITEPROT 0x00000040L
#घोषणा VIF_FILEINUSE 0x00000080L
#घोषणा VIF_OUTOFSPACE 0x00000100L
#घोषणा VIF_ACCESSVIOLATION 0x00000200L
#घोषणा VIF_SHARINGVIOLATION 0x00000400L
#घोषणा VIF_CANNOTCREATE 0x00000800L
#घोषणा VIF_CANNOTDELETE 0x00001000L
#घोषणा VIF_CANNOTRENAME 0x00002000L
#घोषणा VIF_CANNOTDELETECUR 0x00004000L
#घोषणा VIF_OUTOFMEMORY 0x00008000L

#घोषणा VIF_CANNOTREADSRC 0x00010000L
#घोषणा VIF_CANNOTREADDST 0x00020000L

#घोषणा VIF_BUFFTOOSMALL 0x00040000L
#घोषणा VIF_CANNOTLOADLZ32 0x00080000L
#घोषणा VIF_CANNOTLOADCABINET 0x00100000L

#अगर_अघोषित RC_INVOKED

  प्रकार काष्ठा tagVS_FIXEDFILEINFO
  {
    DWORD dwSignature;
    DWORD dwStrucVersion;
    DWORD dwFileVersionMS;
    DWORD dwFileVersionLS;
    DWORD dwProductVersionMS;
    DWORD dwProductVersionLS;
    DWORD dwFileFlagsMask;
    DWORD dwFileFlags;
    DWORD dwFileOS;
    DWORD dwFileType;
    DWORD dwFileSubtype;
    DWORD dwFileDateMS;
    DWORD dwFileDateLS;
  } VS_FIXEDFILEINFO;

#अगर_घोषित UNICODE
#घोषणा VerFindFile VerFindFileW
#घोषणा VerInstallFile VerInstallFileW
#घोषणा Get_File_Version_Info_आकार Get_File_Version_Info_आकार_W
#घोषणा GetFileVersionInfo GetFileVersionInfoW
#घोषणा VerLanguageName VerLanguageNameW
#घोषणा Ver_Query_मूल्य Ver_Query_मूल्य_W
#अन्यथा
#घोषणा VerFindFile VerFindFileA
#घोषणा VerInstallFile VerInstallFileA
#घोषणा Get_File_Version_Info_आकार Get_File_Version_Info_आकार_A
#घोषणा GetFileVersionInfo GetFileVersionInfoA
#घोषणा VerLanguageName VerLanguageNameA
#घोषणा Ver_Query_मूल्य Ver_Query_मूल्य_A
#पूर्ण_अगर

  DWORD WINAPI VerFindFileA(DWORD uFlags,LPSTR szFileName,LPSTR szWinDir,LPSTR szAppDir,LPSTR szCurDir,PUINT lpuCurDirLen,LPSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI VerFindFileW(DWORD uFlags,LPWSTR szFileName,LPWSTR szWinDir,LPWSTR szAppDir,LPWSTR szCurDir,PUINT lpuCurDirLen,LPWSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI VerInstallFileA(DWORD uFlags,LPSTR szSrcFileName,LPSTR szDestFileName,LPSTR szSrcDir,LPSTR szDestDir,LPSTR szCurDir,LPSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI VerInstallFileW(DWORD uFlags,LPWSTR szSrcFileName,LPWSTR szDestFileName,LPWSTR szSrcDir,LPWSTR szDestDir,LPWSTR szCurDir,LPWSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI Get_File_Version_Info_आकार_A(LPCSTR lptstrFilename,LPDWORD lpdwHandle);
  DWORD WINAPI Get_File_Version_Info_आकार_W(LPCWSTR lptstrFilename,LPDWORD lpdwHandle);
  WINBOOL WINAPI GetFileVersionInfoA(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lp_तथ्य);
  WINBOOL WINAPI GetFileVersionInfoW(LPCWSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lp_तथ्य);
  DWORD WINAPI VerLanguageNameA(DWORD wLang,LPSTR szLang,DWORD n_आकार);
  DWORD WINAPI VerLanguageNameW(DWORD wLang,LPWSTR szLang,DWORD n_आकार);
  WINBOOL WINAPI Ver_Query_मूल्य_A(स्थिर LPVOID pBlock,LPSTR lpSubBlock,LPVOID *lplp_बफर,PUINT puLen);
  WINBOOL WINAPI Ver_Query_मूल्य_W(स्थिर LPVOID pBlock,LPWSTR lpSubBlock,LPVOID *lplp_बफर,PUINT puLen);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर
#पूर्ण_अगर
