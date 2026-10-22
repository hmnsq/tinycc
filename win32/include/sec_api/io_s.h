/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _INC_IO_S
#घोषणा _INC_IO_S

#समावेश <io.h>

#अगर defined(MINGW_HAS_SECURE_API)

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

  _CRTIMP errno_t __cdecl _access_s(स्थिर अक्षर *_Filename,पूर्णांक _AccessMode);
  _CRTIMP errno_t __cdecl _chsize_s(पूर्णांक _FileHandle,__int64 आकार_4);
  _CRTIMP errno_t __cdecl _mktemp_s(अक्षर *_TemplateName,माप_प्रकार आकार_4);
  _CRTIMP errno_t __cdecl _umask_s(पूर्णांक _NewMode,पूर्णांक *_OldMode);

#अगर_अघोषित _WIO_S_DEFINED
#घोषणा _WIO_S_DEFINED
  _CRTIMP errno_t __cdecl _waccess_s(स्थिर ब_अक्षर_प्रकार *_Filename,पूर्णांक _AccessMode);
  _CRTIMP errno_t __cdecl _wmktemp_s(ब_अक्षर_प्रकार *_TemplateName,माप_प्रकार आकार_In_शब्दगण);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
}
#पूर्ण_अगर

#पूर्ण_अगर
#पूर्ण_अगर
