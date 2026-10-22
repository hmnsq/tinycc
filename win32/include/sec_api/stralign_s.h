/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#که_نه_تعریف_شوی __STRALIGN_H_S_
#تعریف_کړه __STRALIGN_H_S_

#ضمن <stralign.h>

#إذا defined(MINGW_HAS_SECURE_API)

#که_تعریف_شوی __cplusplus
خارجي "C" {
#د_که_پای

#إذا !defined(I_X86_) && defined(_WSTRING_S_DEFINED)
#إذا defined(__cplusplus) && defined(_WConst_Return)
  ساكن __inline PUWSTR ua_wcscpy_s(PUWSTR Destination,اندازه_t Destination_اندازه,PCUWSTR سرچینه_2) {
    إذا(WSTR_ALIGNED(سرچینه_2) && WSTR_ALIGNED(Destination)) أرجع (wcscpy_s((PWSTR)Destination,Destination_اندازه,(PCWSTR)سرچینه_2)==0 ? Destination : عدم);
    أرجع uaw_wcscpy((PCUWSTR)String,Character);
  }
#د_که_پای
#د_که_پای

#که_تعریف_شوی __cplusplus
}
#د_که_پای
#د_که_پای
#د_که_پای
