/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् VER_H
#परिभाषय VER_H

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#परिभाषय VS_FILE_INFO RT_संस्करणम्
#परिभाषय VS_संस्करणम्_INFO 1
#परिभाषय VS_USER_DEFINED 100

#परिभाषय VS_FFI_SIGNATURE 0xFEEF04BDL
#परिभाषय VS_FFI_STRUCVERSION 0x00010000L
#परिभाषय VS_FFI_FILEFLAGSMASK 0x0000003FL

#परिभाषय VS_FF_DEBUG 0x00000001L
#परिभाषय VS_FF_PRERELEASE 0x00000002L
#परिभाषय VS_FF_PATCHED 0x00000004L
#परिभाषय VS_FF_PRIVATEBUILD 0x00000008L
#परिभाषय VS_FF_INFOINFERRED 0x00000010L
#परिभाषय VS_FF_SPECIALBUILD 0x00000020L

#परिभाषय VOS_UNKNOWN 0x00000000L
#परिभाषय VOS_DOS 0x00010000L
#परिभाषय VOS_OS216 0x00020000L
#परिभाषय VOS_OS232 0x00030000L
#परिभाषय VOS_NT 0x00040000L
#परिभाषय VOS_WINCE 0x00050000L

#परिभाषय VOS_आधारः 0x00000000L
#परिभाषय VOS__WINDOWS16 0x00000001L
#परिभाषय VOS__PM16 0x00000002L
#परिभाषय VOS__PM32 0x00000003L
#परिभाषय VOS__WINDOWS32 0x00000004L

#परिभाषय VOS_DOS_WINDOWS16 0x00010001L
#परिभाषय VOS_DOS_WINDOWS32 0x00010004L
#परिभाषय VOS_OS216_PM16 0x00020002L
#परिभाषय VOS_OS232_PM32 0x00030003L
#परिभाषय VOS_NT_WINDOWS32 0x00040004L

#परिभाषय VFT_UNKNOWN 0x00000000L
#परिभाषय VFT_APP 0x00000001L
#परिभाषय VFT_DLL 0x00000002L
#परिभाषय VFT_DRV 0x00000003L
#परिभाषय VFT_FONT 0x00000004L
#परिभाषय VFT_VXD 0x00000005L
#परिभाषय VFT_STATIC_LIB 0x00000007L

#परिभाषय VFT2_UNKNOWN 0x00000000L
#परिभाषय VFT2_DRV_PRINTER 0x00000001L
#परिभाषय VFT2_DRV_KEYBOARD 0x00000002L
#परिभाषय VFT2_DRV_LANGUAGE 0x00000003L
#परिभाषय VFT2_DRV_DISPLAY 0x00000004L
#परिभाषय VFT2_DRV_MOUSE 0x00000005L
#परिभाषय VFT2_DRV_जालम् 0x00000006L
#परिभाषय VFT2_DRV_SYSTEM 0x00000007L
#परिभाषय VFT2_DRV_INSTALLABLE 0x00000008L
#परिभाषय VFT2_DRV_SOUND 0x00000009L
#परिभाषय VFT2_DRV_COMM 0x0000000AL
#परिभाषय VFT2_DRV_INPUTMETHOD 0x0000000BL
#परिभाषय VFT2_DRV_VERSIONED_PRINTER 0x0000000CL

#परिभाषय VFT2_FONT_RASTER 0x00000001L
#परिभाषय VFT2_FONT_सदिशम् 0x00000002L
#परिभाषय VFT2_FONT_TRUETYPE 0x00000003L

#परिभाषय VFFF_ISSHAREDFILE 0x0001

#परिभाषय VFF_CURNEDEST 0x0001
#परिभाषय VFF_FILEINUSE 0x0002
#परिभाषय VFF_BUFFTOOSMALL 0x0004

#परिभाषय VIFF_FORCEINSTALL 0x0001
#परिभाषय VIFF_DONTDELETEOLD 0x0002

#परिभाषय VIF_TEMPFILE 0x00000001L
#परिभाषय VIF_MISMATCH 0x00000002L
#परिभाषय VIF_SRCOLD 0x00000004L

#परिभाषय VIF_DIFFLANG 0x00000008L
#परिभाषय VIF_DIFFCODEPG 0x00000010L
#परिभाषय VIF_DIFFTYPE 0x00000020L

#परिभाषय VIF_WRITEPROT 0x00000040L
#परिभाषय VIF_FILEINUSE 0x00000080L
#परिभाषय VIF_OUTOFSPACE 0x00000100L
#परिभाषय VIF_ACCESSVIOLATION 0x00000200L
#परिभाषय VIF_SHARINGVIOLATION 0x00000400L
#परिभाषय VIF_CANNOTCREATE 0x00000800L
#परिभाषय VIF_CANNOTDELETE 0x00001000L
#परिभाषय VIF_CANNOTRENAME 0x00002000L
#परिभाषय VIF_CANNOTDELETECUR 0x00004000L
#परिभाषय VIF_OUTOFMEMORY 0x00008000L

#परिभाषय VIF_CANNOTREADSRC 0x00010000L
#परिभाषय VIF_CANNOTREADDST 0x00020000L

#परिभाषय VIF_BUFFTOOSMALL 0x00040000L
#परिभाषय VIF_CANNOTLOADLZ32 0x00080000L
#परिभाषय VIF_CANNOTLOADCABINET 0x00100000L

#यदि_अपरिभाषितम् RC_INVOKED

  प्रकारनिर्देश संरचना चिह्नकम्_VS_FIXEDFILEINFO
  {
    DWORD dwSignature;
    DWORD dw_Struc_संस्करणम्;
    DWORD dw_File_संस्करणम्_MS;
    DWORD dw_File_संस्करणम्_LS;
    DWORD dw_गुणनफलम्_संस्करणम्_MS;
    DWORD dw_गुणनफलम्_संस्करणम्_LS;
    DWORD dw_File_Flags_आवरणम्;
    DWORD dwFileFlags;
    DWORD dwFileOS;
    DWORD dwFileType;
    DWORD dwFileSubtype;
    DWORD dwFileDateMS;
    DWORD dwFileDateLS;
  } VS_FIXEDFILEINFO;

#यदि_परिभाषितम् UNICODE
#परिभाषय VerFindFile VerFindFileW
#परिभाषय VerInstallFile VerInstallFileW
#परिभाषय Get_File_संस्करणम्_Info_आकार Get_File_संस्करणम्_Info_आकार_W
#परिभाषय Get_File_संस्करणम्_Info Get_File_संस्करणम्_Info_W
#परिभाषय VerLanguageName VerLanguageNameW
#परिभाषय Ver_Query_मानम् Ver_Query_मानम्_W
#अन्यथा
#परिभाषय VerFindFile VerFindFileA
#परिभाषय VerInstallFile VerInstallFileA
#परिभाषय Get_File_संस्करणम्_Info_आकार Get_File_संस्करणम्_Info_आकार_A
#परिभाषय Get_File_संस्करणम्_Info Get_File_संस्करणम्_Info_A
#परिभाषय VerLanguageName VerLanguageNameA
#परिभाषय Ver_Query_मानम् Ver_Query_मानम्_A
#यदि_अन्तः

  DWORD WINAPI VerFindFileA(DWORD uFlags,LPSTR szFileName,LPSTR szWinDir,LPSTR szAppDir,LPSTR szCurDir,PUINT lpuCurDirLen,LPSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI VerFindFileW(DWORD uFlags,LPWSTR szFileName,LPWSTR szWinDir,LPWSTR szAppDir,LPWSTR szCurDir,PUINT lpuCurDirLen,LPWSTR szDestDir,PUINT lpuDestDirLen);
  DWORD WINAPI VerInstallFileA(DWORD uFlags,LPSTR szSrcFileName,LPSTR szDestFileName,LPSTR szSrcDir,LPSTR szDestDir,LPSTR szCurDir,LPSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI VerInstallFileW(DWORD uFlags,LPWSTR szSrcFileName,LPWSTR szDestFileName,LPWSTR szSrcDir,LPWSTR szDestDir,LPWSTR szCurDir,LPWSTR szTmpFile,PUINT lpuTmpFileLen);
  DWORD WINAPI Get_File_संस्करणम्_Info_आकार_A(LPCSTR lptstrFilename,LPDWORD lpdwHandle);
  DWORD WINAPI Get_File_संस्करणम्_Info_आकार_W(LPCWSTR lptstrFilename,LPDWORD lpdwHandle);
  WINBOOL WINAPI Get_File_संस्करणम्_Info_A(LPCSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lp_दत्त);
  WINBOOL WINAPI Get_File_संस्करणम्_Info_W(LPCWSTR lptstrFilename,DWORD dwHandle,DWORD dwLen,LPVOID lp_दत्त);
  DWORD WINAPI VerLanguageNameA(DWORD wLang,LPSTR szLang,DWORD n_आकार);
  DWORD WINAPI VerLanguageNameW(DWORD wLang,LPWSTR szLang,DWORD n_आकार);
  WINBOOL WINAPI Ver_Query_मानम्_A(ध्रुव LPVOID p_खण्डम्,LPSTR lp_Sub_खण्डम्,LPVOID *lplp_बफर,PUINT puLen);
  WINBOOL WINAPI Ver_Query_मानम्_W(ध्रुव LPVOID p_खण्डम्,LPWSTR lp_Sub_खण्डम्,LPVOID *lplp_बफर,PUINT puLen);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
}
#यदि_अन्तः
#यदि_अन्तः
