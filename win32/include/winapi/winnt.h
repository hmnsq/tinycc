/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#अगर_अघोषित _WINNT_
#घोषणा _WINNT_

#अगर_घोषित __cplusplus
बाह्य "C" {
#पूर्ण_अगर

#समावेश <ctype.h>
#घोषणा ANYSIZE_ARRAY 1

//gr #include <specstrings.h>

#घोषणा RESTRICTED_POINTER

#अगर_अघोषित __CRT_UNALIGNED
#घोषणा __CRT_UNALIGNED
#पूर्ण_अगर

#अगर defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#घोषणा UNALIGNED __CRT_UNALIGNED
#अगर_घोषित _WIN64
#घोषणा UNALIGNED64 __CRT_UNALIGNED
#अन्यथा
#घोषणा UNALIGNED64
#पूर्ण_अगर
#अन्यथा
#घोषणा UNALIGNED
#घोषणा UNALIGNED64
#पूर्ण_अगर

#अगर !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#घोषणा I_X86_
#पूर्ण_अगर

#अगर !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#घोषणा _AMD64_
#पूर्ण_अगर

#अगर !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#अगर !defined(_IA64_)
#घोषणा _IA64_
#पूर्ण_अगर
#पूर्ण_अगर


#अगर_घोषित _WIN64
#घोषणा MAX_NATURAL_ALIGNMENT माप(ULONGLONG)
#घोषणा MEMORY_ALLOCATION_ALIGNMENT 16
#अन्यथा
#घोषणा MAX_NATURAL_ALIGNMENT माप(DWORD)
#घोषणा MEMORY_ALLOCATION_ALIGNMENT 8
#पूर्ण_अगर

#अगर_घोषित __cplusplus
#घोषणा TYPE_ALIGNMENT(t) __alignof__ (t)
#अन्यथा
#घोषणा TYPE_ALIGNMENT(t) FIELD_OFFSET(काष्ठा { अक्षर x; t test; },test)
#पूर्ण_अगर

#अगर_घोषित _WIN64
#अगर_घोषित _AMD64_
#घोषणा PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#या_अगर defined(_IA64_) || defined(_ARM64_)
#घोषणा PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#अन्यथा
#त्रुटि No Target Architecture
#पूर्ण_अगर
#घोषणा PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#अन्यथा
#घोषणा PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#पूर्ण_अगर

#घोषणा C_ASSERT(e) प्रकार अक्षर __C_ASSERT__[(e)?1:-1]

#समावेश <basetsd.h>

#अगर defined(_X86_) || defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#घोषणा DECLSPEC_IMPORT __declspec(dllimport)
#अन्यथा
#घोषणा DECLSPEC_IMPORT
#पूर्ण_अगर

#अगर_अघोषित DECLSPEC_NORETURN
#घोषणा DECLSPEC_NORETURN __declspec(noreturn)
#पूर्ण_अगर

#अगर_अघोषित DECLSPEC_ALIGN
#घोषणा DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#पूर्ण_अगर

#अगर_अघोषित SYSTEM_CACHE_ALIGNMENT_आकार
#अगर defined(_AMD64_) || defined(I_X86_)
#घोषणा SYSTEM_CACHE_ALIGNMENT_आकार 64
#अन्यथा
#घोषणा SYSTEM_CACHE_ALIGNMENT_आकार 128
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_अघोषित DECLSPEC_CACHEALIGN
#घोषणा DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_आकार)
#पूर्ण_अगर

#अगर_अघोषित DECLSPEC_UUID
#घोषणा DECLSPEC_UUID(x)
#पूर्ण_अगर

#अगर_अघोषित DECLSPEC_NOVTABLE
#घोषणा DECLSPEC_NOVTABLE
#पूर्ण_अगर

#अगर_अघोषित DECLSPEC_SELECTANY
#घोषणा DECLSPEC_SELECTANY __declspec(selectany)
#पूर्ण_अगर

#अगर_अघोषित NOP_FUNCTION
#घोषणा NOP_FUNCTION (व्योम)0
#पूर्ण_अगर

#अगर_अघोषित DECLSPEC_NOINLINE
#घोषणा DECLSPEC_NOINLINE
#पूर्ण_अगर

#अगर_अघोषित FORCEINLINE
#घोषणा FORCEINLINE अटल __inline__
#पूर्ण_अगर

#अगर_अघोषित DECLSPEC_DEPRECATED
#घोषणा DECLSPEC_DEPRECATED __declspec(deprecated)
#घोषणा DEPRECATE_SUPPORTED
#पूर्ण_अगर

#घोषणा DECLSPEC_DEPRECATED_DDK
#घोषणा PRAGMA_DEPRECATED_DDK 0

  प्रकार व्योम *PVOID;
  प्रकार व्योम *PVOID64;

#घोषणा NTAPI __stdcall
#घोषणा NTSYSAPI DECLSPEC_IMPORT
#घोषणा NTSYSCALLAPI DECLSPEC_IMPORT

#अगर_अघोषित VOID
#घोषणा VOID व्योम
  प्रकार अक्षर CHAR;
  प्रकार लघु SHORT;
  प्रकार दीर्घ LONG;
#पूर्ण_अगर

  प्रकार ब_अक्षर_प्रकार WCHAR;
  प्रकार WCHAR *PWCHAR,*LPWCH,*PWCH;
  प्रकार CONST WCHAR *LPCWCH,*PCWCH;
  प्रकार WCHAR *NWPSTR,*LPWSTR,*PWSTR;
  प्रकार PWSTR *PZPWSTR;
  प्रकार CONST PWSTR *PCZPWSTR;
  प्रकार WCHAR UNALIGNED *LPUWSTR,*PUWSTR;
  प्रकार CONST WCHAR *LPCWSTR,*PCWSTR;
  प्रकार PCWSTR *PZPCWSTR;
  प्रकार CONST WCHAR UNALIGNED *LPCUWSTR,*PCUWSTR;
  प्रकार CHAR *PCHAR,*LPCH,*PCH;
  प्रकार CONST CHAR *LPCCH,*PCCH;
  प्रकार CHAR *NPSTR,*LPSTR,*PSTR;
  प्रकार PSTR *PZPSTR;
  प्रकार CONST PSTR *PCZPSTR;
  प्रकार CONST CHAR *LPCSTR,*PCSTR;
  प्रकार PCSTR *PZPCSTR;

#अगर_घोषित UNICODE
#अगर_अघोषित _TCHAR_DEFINED
#घोषणा _TCHAR_DEFINED
  प्रकार WCHAR TCHAR,*PTCHAR;
  प्रकार WCHAR TBYTE ,*PTBYTE;
#पूर्ण_अगर

  प्रकार LPWSTR LPTCH,PTCH;
  प्रकार LPWSTR PTSTR,LPTSTR;
  प्रकार LPCWSTR PCTSTR,LPCTSTR;
  प्रकार LPUWSTR PUTSTR,LPUTSTR;
  प्रकार LPCUWSTR PCUTSTR,LPCUTSTR;
  प्रकार LPWSTR LP;
#घोषणा __TEXT(quote) L##quote
#अन्यथा
#अगर_अघोषित _TCHAR_DEFINED
#घोषणा _TCHAR_DEFINED
  प्रकार अक्षर TCHAR,*PTCHAR;
  प्रकार अचिन्हित अक्षर TBYTE ,*PTBYTE;
#पूर्ण_अगर

  प्रकार LPSTR LPTCH,PTCH;
  प्रकार LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  प्रकार LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#घोषणा __TEXT(quote) quote
#पूर्ण_अगर

#घोषणा TEXT(quote) __TEXT(quote)

  प्रकार SHORT *PSHORT;
  प्रकार LONG *PLONG;

  प्रकार व्योम *HANDLE;
#घोषणा DECLARE_HANDLE(name) काष्ठा name##__ { पूर्णांक unused; }; प्रकार काष्ठा name##__ *name
  प्रकार HANDLE *PHANDLE;

  प्रकार BYTE FCHAR;
  प्रकार WORD FSHORT;
  प्रकार DWORD FLONG;

#अगर_अघोषित _HRESULT_DEFINED
#घोषणा _HRESULT_DEFINED
  प्रकार LONG HRESULT;
#पूर्ण_अगर

#अगर_घोषित __cplusplus
#घोषणा EXTERN_C बाह्य "C"
#अन्यथा
#घोषणा EXTERN_C बाह्य
#पूर्ण_अगर

#घोषणा STDMETHODCALLTYPE WINAPI
#घोषणा STDMETHODVCALLTYPE __cdecl
#घोषणा STDAPICALLTYPE WINAPI
#घोषणा STDAPIVCALLTYPE __cdecl
#घोषणा STDAPI EXTERN_C HRESULT WINAPI
#घोषणा STDAPI_(type) EXTERN_C type WINAPI
#घोषणा STDMETHODIMP HRESULT WINAPI
#घोषणा STDMETHODIMP_(type) type WINAPI
#घोषणा STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#घोषणा STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#घोषणा STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#घोषणा STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  प्रकार अक्षर CCHAR;
#अगर_अघोषित _LCID_DEFINED
#घोषणा _LCID_DEFINED
प्रकार DWORD LCID;
#पूर्ण_अगर
  प्रकार PDWORD PLCID;
#अगर_अघोषित _LANGID_DEFINED
#घोषणा _LANGID_DEFINED
  प्रकार WORD LANGID;
#पूर्ण_अगर
#घोषणा APPLICATION_ERROR_MASK 0x20000000
#घोषणा ERROR_SEVERITY_SUCCESS 0x00000000
#घोषणा ERROR_SEVERITY_INFORMATIONAL 0x40000000
#घोषणा ERROR_SEVERITY_WARNING 0x80000000
#घोषणा ERROR_SEVERITY_ERROR 0xC0000000

#अगर_घोषित __ia64__
  __declspec(align(16))
#पूर्ण_अगर
    प्रकार काष्ठा _FLOAT128 {
      __int64 निचला_Part;
      __int64 ऊपरी_Part;
  } FLOAT128;

  प्रकार FLOAT128 *PFLOAT128;

#घोषणा _ULONGLONG_
#अगर((!(defined(_X86_) && !defined(__x86_64)) || (defined(_INTEGRAL_MAX_BITS) && _INTEGRAL_MAX_BITS >= 64)))
  प्रकार __int64 LONGLONG;
  प्रकार अचिन्हित __int64 ULONGLONG;

#घोषणा MAXLONGLONG (0x7fffffffffffffff)
#अन्यथा

  प्रकार द्विगुन LONGLONG;
  प्रकार द्विगुन ULONGLONG;
#पूर्ण_अगर

  प्रकार LONGLONG *PLONGLONG;
  प्रकार ULONGLONG *PULONGLONG;

  प्रकार LONGLONG USN;

  प्रकार जोड़ _LARGE_INTEGER {
    काष्ठा {
      DWORD निचला_Part;
      LONG ऊपरी_Part;
    };
    काष्ठा {
      DWORD निचला_Part;
      LONG ऊपरी_Part;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  प्रकार LARGE_INTEGER *PLARGE_INTEGER;

  प्रकार जोड़ _ULARGE_INTEGER {
    काष्ठा {
      DWORD निचला_Part;
      DWORD ऊपरी_Part;
    };
    काष्ठा {
      DWORD निचला_Part;
      DWORD ऊपरी_Part;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  प्रकार ULARGE_INTEGER *PULARGE_INTEGER;

  प्रकार काष्ठा _LUID {
    DWORD निचला_Part;
    LONG ऊपरी_Part;
  } LUID,*PLUID;

#घोषणा _DWORDLONG_
  प्रकार ULONGLONG DWORDLONG;
  प्रकार DWORDLONG *PDWORDLONG;

#अगर_घोषित RC_INVOKED
#घोषणा Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#घोषणा UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#घोषणा Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#या_अगर (defined(_X86_) && !defined(__x86_64))
#घोषणा Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#घोषणा UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#घोषणा Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#या_अगर defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#घोषणा Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#घोषणा UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#घोषणा Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#अन्यथा
#त्रुटि Must define a target architecture.
#पूर्ण_अगर

#घोषणा Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#घोषणा Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#अगर_घोषित __cplusplus
  बाह्य "C" {
#पूर्ण_अगर

#अगर_घोषित __x86_64

#घोषणा RotateLeft8 _rotl8
#घोषणा RotateLeft16 _rotl16
#घोषणा RotateRight8 _rotr8
#घोषणा RotateRight16 _rotr16

    अचिन्हित अक्षर __cdecl _rotl8(अचिन्हित अक्षर मूल्य_3,अचिन्हित अक्षर Shift);
    अचिन्हित लघु __cdecl _rotl16(अचिन्हित लघु मूल्य_3,अचिन्हित अक्षर Shift);
    अचिन्हित अक्षर __cdecl _rotr8(अचिन्हित अक्षर मूल्य_3,अचिन्हित अक्षर Shift);
    अचिन्हित लघु __cdecl _rotr16(अचिन्हित लघु मूल्य_3,अचिन्हित अक्षर Shift);
#पूर्ण_अगर

#घोषणा RotateLeft32 _rotl
#घोषणा RotateLeft64 _rotl64
#घोषणा RotateRight32 _rotr
#घोषणा RotateRight64 _rotr64

    अचिन्हित पूर्णांक __cdecl _rotl(अचिन्हित पूर्णांक मूल्य_3,पूर्णांक Shift);
    अचिन्हित __int64 __cdecl _rotl64(अचिन्हित __int64 मूल्य_3,पूर्णांक Shift);
    अचिन्हित पूर्णांक __cdecl _rotr(अचिन्हित पूर्णांक मूल्य_3,पूर्णांक Shift);
    अचिन्हित __int64 __cdecl _rotr64(अचिन्हित __int64 मूल्य_3,पूर्णांक Shift);
#अगर_घोषित __cplusplus
  }
#पूर्ण_अगर

#घोषणा ANSI_NULL ((CHAR)0)
#घोषणा UNICODE_NULL ((WCHAR)0)
#घोषणा UNICODE_STRING_MAX_BYTES ((WORD) 65534)
#घोषणा UNICODE_STRING_MAX_CHARS (32767)

#अगर_अघोषित _BOOLEAN_
#घोषणा _BOOLEAN_
  प्रकार BYTE BOOLEAN;
#पूर्ण_अगर
  प्रकार BOOLEAN *PBOOLEAN;

  प्रकार काष्ठा _LIST_ENTRY {
    काष्ठा _LIST_ENTRY *Flink;
    काष्ठा _LIST_ENTRY *Blink;
  } LIST_ENTRY,*PLIST_ENTRY,*RESTRICTED_POINTER PRLIST_ENTRY;

  प्रकार काष्ठा _SINGLE_LIST_ENTRY {
    काष्ठा _SINGLE_LIST_ENTRY *अग्र_2;
  } SINGLE_LIST_ENTRY,*PSINGLE_LIST_ENTRY;

  प्रकार काष्ठा LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
  } LIST_ENTRY32;
  प्रकार LIST_ENTRY32 *PLIST_ENTRY32;

  प्रकार काष्ठा LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
  } LIST_ENTRY64;
  प्रकार LIST_ENTRY64 *PLIST_ENTRY64;

#समावेश <guiddef.h>

#अगर_अघोषित __OBJECTID_DEFINED
#घोषणा __OBJECTID_DEFINED
  प्रकार काष्ठा _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#पूर्ण_अगर

#घोषणा MINCHAR 0x80
#घोषणा MAXCHAR 0x7f
#घोषणा MINSHORT 0x8000
#घोषणा MAXSHORT 0x7fff
#घोषणा MINLONG 0x80000000
#घोषणा MAXLONG 0x7fffffff
#घोषणा MAXBYTE 0xff
#घोषणा MAXWORD 0xffff
#घोषणा MAXDWORD 0xffffffff

#घोषणा FIELD_OFFSET(type,field) ((LONG)(LONG_PTR)&(((type *)0)->field))
#घोषणा RTL_FIELD_आकार(type,field) (माप(((type *)0)->field))
#घोषणा RTL_SIZEOF_THROUGH_FIELD(type,field) (FIELD_OFFSET(type,field) + RTL_FIELD_आकार(type,field))
#घोषणा RTL_CONTAINS_FIELD(Struct,आकार_3,Field) ((((PCHAR)(&(Struct)->Field)) + माप((Struct)->Field)) <= (((PCHAR)(Struct))+(आकार_3)))
#घोषणा RTL_संख्या_OF_V1(A) (माप(A)/माप((A)[0]))
#घोषणा RTL_संख्या_OF_V2(A) RTL_संख्या_OF_V1(A)

#अगर_घोषित ENABLE_RTL_संख्या_OF_V2
#घोषणा RTL_संख्या_OF(A) RTL_संख्या_OF_V2(A)
#अन्यथा
#घोषणा RTL_संख्या_OF(A) RTL_संख्या_OF_V1(A)
#पूर्ण_अगर

#घोषणा ARRAYSIZE(A) RTL_संख्या_OF_V2(A)
#घोषणा _ARRAYSIZE(A) RTL_संख्या_OF_V1(A)

#घोषणा RTL_FIELD_TYPE(type,field) (((type*)0)->field)
#घोषणा RTL_संख्या_OF_FIELD(type,field) (RTL_संख्या_OF(RTL_FIELD_TYPE(type,field)))
#घोषणा RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((FIELD_OFFSET(T,F2) > FIELD_OFFSET(T,F1)) ? (FIELD_OFFSET(T,F2) - FIELD_OFFSET(T,F1) - RTL_FIELD_आकार(T,F1)) : (FIELD_OFFSET(T,F1) - FIELD_OFFSET(T,F2) - RTL_FIELD_आकार(T,F2)))

#अगर_घोषित __cplusplus
#घोषणा RTL_CONST_CAST(type) const_cast<type>
#अन्यथा
#घोषणा RTL_CONST_CAST(type) (type)
#पूर्ण_अगर

#घोषणा RTL_BITS_OF(आकार_Of_Arg) (माप(आकार_Of_Arg) *8)
#घोषणा RTL_BITS_OF_FIELD(type,field) (RTL_BITS_OF(RTL_FIELD_TYPE(type,field)))
#घोषणा CONTAINING_RECORD(address,type,field) ((type *)((PCHAR)(address) - (ULONG_PTR)(&((type *)0)->field)))

#घोषणा VER_SERVER_NT 0x80000000
#घोषणा VER_WORKSTATION_NT 0x40000000
#घोषणा VER_SUITE_SMALLBUSINESS 0x00000001
#घोषणा VER_SUITE_ENTERPRISE 0x00000002
#घोषणा VER_SUITE_BACKOFFICE 0x00000004
#घोषणा VER_SUITE_COMMUNICATIONS 0x00000008
#घोषणा VER_SUITE_TERMINAL 0x00000010
#घोषणा VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#घोषणा VER_SUITE_EMBEDDEDNT 0x00000040
#घोषणा VER_SUITE_DATACENTER 0x00000080
#घोषणा VER_SUITE_SINGLEUSERTS 0x00000100
#घोषणा VER_SUITE_PERSONAL 0x00000200
#घोषणा VER_SUITE_BLADE 0x00000400
#घोषणा VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#घोषणा VER_SUITE_SECURITY_APPLIANCE 0x00001000
#घोषणा VER_SUITE_STORAGE_SERVER 0x00002000
#घोषणा VER_SUITE_COMPUTE_SERVER 0x00004000

#घोषणा PRODUCT_UNDEFINED                       0x0

#घोषणा PRODUCT_ULTIMATE                        0x1
#घोषणा PRODUCT_HOME_BASIC                      0x2
#घोषणा PRODUCT_HOME_PREMIUM                    0x3
#घोषणा PRODUCT_ENTERPRISE                      0x4
#घोषणा PRODUCT_HOME_BASIC_N                    0x5
#घोषणा PRODUCT_BUSINESS                        0x6
#घोषणा PRODUCT_STANDARD_SERVER                 0x7
#घोषणा PRODUCT_DATACENTER_SERVER               0x8
#घोषणा PRODUCT_SMALLBUSINESS_SERVER            0x9
#घोषणा PRODUCT_ENTERPRISE_SERVER               0xa
#घोषणा PRODUCT_STARTER                         0xb
#घोषणा PRODUCT_DATACENTER_SERVER_CORE          0xc
#घोषणा PRODUCT_STANDARD_SERVER_CORE            0xd
#घोषणा PRODUCT_ENTERPRISE_SERVER_CORE          0xe
#घोषणा PRODUCT_ENTERPRISE_SERVER_IA64          0xf
#घोषणा PRODUCT_BUSINESS_N                      0x10
#घोषणा PRODUCT_WEB_SERVER                      0x11
#घोषणा PRODUCT_CLUSTER_SERVER                  0x12
#घोषणा PRODUCT_HOME_SERVER                     0x13
#घोषणा PRODUCT_STORAGE_EXPRESS_SERVER          0x14
#घोषणा PRODUCT_STORAGE_STANDARD_SERVER         0x15
#घोषणा PRODUCT_STORAGE_WORKGROUP_SERVER        0x16
#घोषणा PRODUCT_STORAGE_ENTERPRISE_SERVER       0x17
#घोषणा PRODUCT_SERVER_FOR_SMALLBUSINESS        0x18
#घोषणा PRODUCT_SMALLBUSINESS_SERVER_PREMIUM    0x19

#घोषणा PRODUCT_UNLICENSED                      0xabcdabcd

#घोषणा LANG_NEUTRAL 0x00
#घोषणा LANG_INVARIANT 0x7f

#घोषणा LANG_AFRIKAANS 0x36
#घोषणा LANG_ALBANIAN 0x1c
#घोषणा LANG_ALSATIAN 0x84
#घोषणा LANG_AMHARIC 0x5e
#घोषणा LANG_ARABIC 0x01
#घोषणा LANG_ARMENIAN 0x2b
#घोषणा LANG_ASSAMESE 0x4d
#घोषणा LANG_AZERI 0x2c
#घोषणा LANG_BASHKIR 0x6d
#घोषणा LANG_BASQUE 0x2d
#घोषणा LANG_BELARUSIAN 0x23
#घोषणा LANG_BENGALI 0x45
#घोषणा LANG_BRETON 0x7e
#घोषणा LANG_BOSNIAN 0x1a
#घोषणा LANG_BOSNIAN_NEUTRAL 0x781a
#घोषणा LANG_BULGARIAN 0x02
#घोषणा LANG_CATALAN 0x03
#घोषणा LANG_CHINESE 0x04
#घोषणा LANG_CHINESE_SIMPLIFIED 0x04
#घोषणा LANG_CHINESE_TRADITIONAL 0x7c04
#घोषणा LANG_CORSICAN 0x83
#घोषणा LANG_CROATIAN 0x1a
#घोषणा LANG_CZECH 0x05
#घोषणा LANG_DANISH 0x06
#घोषणा LANG_DARI 0x8c
#घोषणा LANG_DIVEHI 0x65
#घोषणा LANG_DUTCH 0x13
#घोषणा LANG_ENGLISH 0x09
#घोषणा LANG_ESTONIAN 0x25
#घोषणा LANG_FAEROESE 0x38
#घोषणा LANG_FARSI 0x29
#घोषणा LANG_FILIPINO 0x64
#घोषणा LANG_FINNISH 0x0b
#घोषणा LANG_FRENCH 0x0c
#घोषणा LANG_FRISIAN 0x62
#घोषणा LANG_GALICIAN 0x56
#घोषणा LANG_GEORGIAN 0x37
#घोषणा LANG_GERMAN 0x07
#घोषणा LANG_GREEK 0x08
#घोषणा LANG_GREENLANDIC 0x6f
#घोषणा LANG_GUJARATI 0x47
#घोषणा LANG_HAUSA 0x68
#घोषणा LANG_HEBREW 0x0d
#घोषणा LANG_HINDI 0x39
#घोषणा LANG_HUNGARIAN 0x0e
#घोषणा LANG_ICELANDIC 0x0f
#घोषणा LANG_IGBO 0x70
#घोषणा LANG_INDONESIAN 0x21
#घोषणा LANG_INUKTITUT 0x5d
#घोषणा LANG_IRISH 0x3c
#घोषणा LANG_ITALIAN 0x10
#घोषणा LANG_JAPANESE 0x11
#घोषणा LANG_KANNADA 0x4b
#घोषणा LANG_KASHMIRI 0x60
#घोषणा LANG_KAZAK 0x3f
#घोषणा LANG_KHMER 0x53
#घोषणा LANG_KICHE 0x86
#घोषणा LANG_KINYARWANDA 0x87
#घोषणा LANG_KONKANI 0x57
#घोषणा LANG_KOREAN 0x12
#घोषणा LANG_KYRGYZ 0x40
#घोषणा LANG_LAO 0x54
#घोषणा LANG_LATVIAN 0x26
#घोषणा LANG_LITHUANIAN 0x27
#घोषणा LANG_LOWER_SORBIAN 0x2e
#घोषणा LANG_LUXEMBOURGISH 0x6e
#घोषणा LANG_MACEDONIAN 0x2f
#घोषणा LANG_MALAY 0x3e
#घोषणा LANG_MALAYALAM 0x4c
#घोषणा LANG_MALTESE 0x3a
#घोषणा LANG_MANIPURI 0x58
#घोषणा LANG_MAORI 0x81
#घोषणा LANG_MAPUDUNGUN 0x7a
#घोषणा LANG_MARATHI 0x4e
#घोषणा LANG_MOHAWK 0x7c
#घोषणा LANG_MONGOLIAN 0x50
#घोषणा LANG_NEPALI 0x61
#घोषणा LANG_NORWEGIAN 0x14
#घोषणा LANG_OCCITAN 0x82
#घोषणा LANG_ORIYA 0x48
#घोषणा LANG_PASHTO 0x63
#घोषणा LANG_PERSIAN 0x29
#घोषणा LANG_POLISH 0x15
#घोषणा LANG_PORTUGUESE 0x16
#घोषणा LANG_PUNJABI 0x46
#घोषणा LANG_QUECHUA 0x6b
#घोषणा LANG_ROMANIAN 0x18
#घोषणा LANG_RUSSIAN 0x19
#घोषणा LANG_SAMI 0x3b
#घोषणा LANG_ROMANSH 0x17
#घोषणा LANG_SANSKRIT 0x4f
#घोषणा LANG_SERBIAN 0x1a
#घोषणा LANG_SERBIAN_NEUTRAL 0x7c1a
#घोषणा LANG_SINDHI 0x59
#घोषणा LANG_SINHALESE 0x5b
#घोषणा LANG_SLOVAK 0x1b
#घोषणा LANG_SLOVENIAN 0x24
#घोषणा LANG_SOTHO 0x6c
#घोषणा LANG_SPANISH 0x0a
#घोषणा LANG_SWAHILI 0x41
#घोषणा LANG_SWEDISH 0x1d
#घोषणा LANG_SYRIAC 0x5a
#घोषणा LANG_TAJIK 0x28
#घोषणा LANG_TAMAZIGHT 0x5f
#घोषणा LANG_TAMIL 0x49
#घोषणा LANG_TATAR 0x44
#घोषणा LANG_TELUGU 0x4a
#घोषणा LANG_THAI 0x1e
#घोषणा LANG_TIBETAN 0x51
#घोषणा LANG_TIGRIGNA 0x73
#घोषणा LANG_TSWANA 0x32
#घोषणा LANG_TURKISH 0x1f
#घोषणा LANG_TURKMEN 0x42
#घोषणा LANG_UIGHUR 0x80
#घोषणा LANG_UKRAINIAN 0x22
#घोषणा LANG_UPPER_SORBIAN 0x2e
#घोषणा LANG_URDU 0x20
#घोषणा LANG_UZBEK 0x43
#घोषणा LANG_VIETNAMESE 0x2a
#घोषणा LANG_WELSH 0x52
#घोषणा LANG_WOLOF 0x88
#घोषणा LANG_XHOSA 0x34
#घोषणा LANG_YAKUT 0x85
#घोषणा LANG_YI 0x78
#घोषणा LANG_YORUBA 0x6a
#घोषणा LANG_ZULU 0x35

#घोषणा SUBLANG_NEUTRAL 0x0
#घोषणा SUBLANG_DEFAULT 0x1
#घोषणा SUBLANG_SYS_DEFAULT 0x2
#घोषणा SUBLANG_CUSTOM_DEFAULT 0x3
#घोषणा SUBLANG_CUSTOM_UNSPECIFIED 0x4
#घोषणा SUBLANG_UI_CUSTOM_DEFAULT 0x5

#घोषणा SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#घोषणा SUBLANG_ARABIC_IRAQ 0x02
#घोषणा SUBLANG_ARABIC_EGYPT 0x03
#घोषणा SUBLANG_ARABIC_LIBYA 0x04
#घोषणा SUBLANG_ARABIC_ALGERIA 0x05
#घोषणा SUBLANG_ARABIC_MOROCCO 0x06
#घोषणा SUBLANG_ARABIC_TUNISIA 0x07
#घोषणा SUBLANG_ARABIC_OMAN 0x08
#घोषणा SUBLANG_ARABIC_YEMEN 0x09
#घोषणा SUBLANG_ARABIC_SYRIA 0x0a
#घोषणा SUBLANG_ARABIC_JORDAN 0x0b
#घोषणा SUBLANG_ARABIC_LEBANON 0x0c
#घोषणा SUBLANG_ARABIC_KUWAIT 0x0d
#घोषणा SUBLANG_ARABIC_UAE 0x0e
#घोषणा SUBLANG_ARABIC_BAHRAIN 0x0f
#घोषणा SUBLANG_ARABIC_QATAR 0x10
#घोषणा SUBLANG_AZERI_LATIN 0x01
#घोषणा SUBLANG_AZERI_CYRILLIC 0x02
#घोषणा SUBLANG_CHINESE_TRADITIONAL 0x01
#घोषणा SUBLANG_CHINESE_SIMPLIFIED 0x02
#घोषणा SUBLANG_CHINESE_HONGKONG 0x03
#घोषणा SUBLANG_CHINESE_SINGAPORE 0x04
#घोषणा SUBLANG_CHINESE_MACAU 0x05
#घोषणा SUBLANG_DUTCH 0x01
#घोषणा SUBLANG_DUTCH_BELGIAN 0x02
#घोषणा SUBLANG_ENGLISH_US 0x01
#घोषणा SUBLANG_ENGLISH_UK 0x02
#घोषणा SUBLANG_ENGLISH_AUS 0x03
#घोषणा SUBLANG_ENGLISH_CAN 0x04
#घोषणा SUBLANG_ENGLISH_NZ 0x05
#घोषणा SUBLANG_ENGLISH_EIRE 0x06
#घोषणा SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#घोषणा SUBLANG_ENGLISH_JAMAICA 0x08
#घोषणा SUBLANG_ENGLISH_CARIBBEAN 0x09
#घोषणा SUBLANG_ENGLISH_BELIZE 0x0a
#घोषणा SUBLANG_ENGLISH_TRINIDAD 0x0b
#घोषणा SUBLANG_ENGLISH_ZIMBABWE 0x0c
#घोषणा SUBLANG_ENGLISH_PHILIPPINES 0x0d
#घोषणा SUBLANG_FRENCH 0x01
#घोषणा SUBLANG_FRENCH_BELGIAN 0x02
#घोषणा SUBLANG_FRENCH_CANADIAN 0x03
#घोषणा SUBLANG_FRENCH_SWISS 0x04
#घोषणा SUBLANG_FRENCH_LUXEMBOURG 0x05
#घोषणा SUBLANG_FRENCH_MONACO 0x06
#घोषणा SUBLANG_GERMAN 0x01
#घोषणा SUBLANG_GERMAN_SWISS 0x02
#घोषणा SUBLANG_GERMAN_AUSTRIAN 0x03
#घोषणा SUBLANG_GERMAN_LUXEMBOURG 0x04
#घोषणा SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#घोषणा SUBLANG_ITALIAN 0x01
#घोषणा SUBLANG_ITALIAN_SWISS 0x02
#घोषणा SUBLANG_KASHMIRI_SASIA 0x02
#घोषणा SUBLANG_KASHMIRI_INDIA 0x02
#घोषणा SUBLANG_KOREAN 0x01
#घोषणा SUBLANG_LITHUANIAN 0x01
#घोषणा SUBLANG_MALAY_MALAYSIA 0x01
#घोषणा SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#घोषणा SUBLANG_NEPALI_INDIA 0x02
#घोषणा SUBLANG_NORWEGIAN_BOKMAL 0x01
#घोषणा SUBLANG_NORWEGIAN_NYNORSK 0x02
#घोषणा SUBLANG_PORTUGUESE 0x02
#घोषणा SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#घोषणा SUBLANG_SERBIAN_LATIN 0x02
#घोषणा SUBLANG_SERBIAN_CYRILLIC 0x03
#घोषणा SUBLANG_SPANISH 0x01
#घोषणा SUBLANG_SPANISH_MEXICAN 0x02
#घोषणा SUBLANG_SPANISH_MODERN 0x03
#घोषणा SUBLANG_SPANISH_GUATEMALA 0x04
#घोषणा SUBLANG_SPANISH_COSTA_RICA 0x05
#घोषणा SUBLANG_SPANISH_PANAMA 0x06
#घोषणा SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#घोषणा SUBLANG_SPANISH_VENEZUELA 0x08
#घोषणा SUBLANG_SPANISH_COLOMBIA 0x09
#घोषणा SUBLANG_SPANISH_PERU 0x0a
#घोषणा SUBLANG_SPANISH_ARGENTINA 0x0b
#घोषणा SUBLANG_SPANISH_ECUADOR 0x0c
#घोषणा SUBLANG_SPANISH_CHILE 0x0d
#घोषणा SUBLANG_SPANISH_URUGUAY 0x0e
#घोषणा SUBLANG_SPANISH_PARAGUAY 0x0f
#घोषणा SUBLANG_SPANISH_BOLIVIA 0x10
#घोषणा SUBLANG_SPANISH_EL_SALVADOR 0x11
#घोषणा SUBLANG_SPANISH_HONDURAS 0x12
#घोषणा SUBLANG_SPANISH_NICARAGUA 0x13
#घोषणा SUBLANG_SPANISH_PUERTO_RICO 0x14
#घोषणा SUBLANG_SWEDISH 0x01
#घोषणा SUBLANG_SWEDISH_FINLAND 0x02
#घोषणा SUBLANG_URDU_PAKISTAN 0x01
#घोषणा SUBLANG_URDU_INDIA 0x02
#घोषणा SUBLANG_UZBEK_LATIN 0x01
#घोषणा SUBLANG_UZBEK_CYRILLIC 0x02

#घोषणा SORT_DEFAULT 0x0
#घोषणा SORT_INVARIANT_MATH 0x1

#घोषणा SORT_JAPANESE_XJIS 0x0
#घोषणा SORT_JAPANESE_UNICODE 0x1
#घोषणा SORT_JAPANESE_RADICALSTROKE 0x4

#घोषणा SORT_CHINESE_BIG5 0x0
#घोषणा SORT_CHINESE_PRCP 0x0
#घोषणा SORT_CHINESE_UNICODE 0x1
#घोषणा SORT_CHINESE_PRC 0x2
#घोषणा SORT_CHINESE_BOPOMOFO 0x3

#घोषणा SORT_KOREAN_KSC 0x0
#घोषणा SORT_KOREAN_UNICODE 0x1

#घोषणा SORT_GERMAN_PHONE_BOOK 0x1

#घोषणा SORT_HUNGARIAN_DEFAULT 0x0
#घोषणा SORT_HUNGARIAN_TECHNICAL 0x1

#घोषणा SORT_GEORGIAN_TRADITIONAL 0x0
#घोषणा SORT_GEORGIAN_MODERN 0x1

#घोषणा MAKELANGID(p,s) ((((WORD)(s)) << 10) | (WORD)(p))
#घोषणा PRIMARYLANGID(lgid) ((WORD)(lgid) & 0x3ff)
#घोषणा SUBLANGID(lgid) ((WORD)(lgid) >> 10)

#घोषणा NLS_VALID_LOCALE_MASK 0x000fffff

#घोषणा MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((WORD)(srtid))) << 16) | ((DWORD)((WORD)(lgid)))))
#घोषणा MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((WORD)(ver))) << 20)))
#घोषणा LANGIDFROMLCID(lcid) ((WORD)(lcid))
#घोषणा SORTIDFROMLCID(lcid) ((WORD)((((DWORD)(lcid)) >> 16) & 0xf))
#घोषणा SORTVERSIONFROMLCID(lcid) ((WORD)((((DWORD)(lcid)) >> 20) & 0xf))

#घोषणा LOCALE_NAME_MAX_लंबाई 85
#घोषणा LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#घोषणा LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#घोषणा LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,SORT_DEFAULT))
#घोषणा LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,SORT_DEFAULT))

#घोषणा LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),SORT_DEFAULT))

#घोषणा LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), SORT_DEFAULT))
#घोषणा LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), SORT_DEFAULT))
#घोषणा LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), SORT_DEFAULT))

#घोषणा LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),SORT_DEFAULT))

#घोषणा UNREFERENCED_PARAMETER(P) (P)
#घोषणा DBG_UNREFERENCED_PARAMETER(P) (P)
#घोषणा DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#घोषणा DEFAULT_UNREACHABLE

#अगर_अघोषित WIN32_NO_STATUS
#घोषणा STATUS_WAIT_0 ((DWORD)0x00000000L)
#घोषणा STATUS_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#घोषणा STATUS_USER_APC ((DWORD)0x000000C0L)
#घोषणा STATUS_TIMEOUT ((DWORD)0x00000102L)
#घोषणा STATUS_PENDING ((DWORD)0x00000103L)
#घोषणा DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#घोषणा DBG_CONTINUE ((DWORD)0x00010002L)
#घोषणा STATUS_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#घोषणा DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#घोषणा DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#घोषणा DBG_CONTROL_C ((DWORD)0x40010005L)
#घोषणा DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#घोषणा DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#घोषणा STATUS_GUARD_PAGE_VIOLATION ((DWORD)0x80000001L)
#घोषणा STATUS_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#घोषणा STATUS_BREAKPOINT ((DWORD)0x80000003L)
#घोषणा STATUS_SINGLE_STEP ((DWORD)0x80000004L)
#घोषणा DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#घोषणा STATUS_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#घोषणा STATUS_IN_PAGE_ERROR ((DWORD)0xC0000006L)
#घोषणा STATUS_INVALID_HANDLE ((DWORD)0xC0000008L)
#घोषणा STATUS_NO_MEMORY ((DWORD)0xC0000017L)
#घोषणा STATUS_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#घोषणा STATUS_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#घोषणा STATUS_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#घोषणा STATUS_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#घोषणा STATUS_FLOAT_DENORMAL_OPERAND ((DWORD)0xC000008DL)
#घोषणा STATUS_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#घोषणा STATUS_FLOAT_INEXACT_परिणाम ((DWORD)0xC000008FL)
#घोषणा STATUS_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#घोषणा STATUS_FLOAT_OVERFLOW ((DWORD)0xC0000091L)
#घोषणा STATUS_FLOAT_ढेर_CHECK ((DWORD)0xC0000092L)
#घोषणा STATUS_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#घोषणा STATUS_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#घोषणा STATUS_INTEGER_OVERFLOW ((DWORD)0xC0000095L)
#घोषणा STATUS_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#घोषणा STATUS_ढेर_OVERFLOW ((DWORD)0xC00000FDL)
#घोषणा STATUS_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#घोषणा STATUS_FLOAT_MULTIPLE_FAULTS ((DWORD)0xC00002B4L)
#घोषणा STATUS_FLOAT_MULTIPLE_TRAPS ((DWORD)0xC00002B5L)
#घोषणा STATUS_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#घोषणा STATUS_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#घोषणा STATUS_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#पूर्ण_अगर

#घोषणा MAXIMUM_WAIT_OBJECTS 64
#घोषणा MAXIMUM_SUSPEND_गिनती MAXCHAR

  प्रकार ULONG_PTR KSPIN_LOCK;
  प्रकार KSPIN_LOCK *PKSPIN_LOCK;

#अगर defined(__x86_64) && !defined(RC_INVOKED)

#अगर_घोषित __cplusplus
  बाह्य "C" {
#पूर्ण_अगर

#घोषणा BitTest _bittest
#घोषणा BitTestAndComplement _bittestandcomplement
#घोषणा BitTestAndSet _bittestandset
#घोषणा BitTestAndReset _bittestandreset
#घोषणा InterlockedBitTestAndSet _interlockedbittestandset
#घोषणा InterlockedBitTestAndReset _interlockedbittestandreset
#घोषणा BitTest64 _bittest64
#घोषणा BitTestAndComplement64 _bittestandcomplement64
#घोषणा BitTestAndSet64 _bittestandset64
#घोषणा BitTestAndReset64 _bittestandreset64
#घोषणा InterlockedBitTestAndSet64 _interlockedbittestandset64
#घोषणा InterlockedBitTestAndReset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG स्थिर *Base,LONG Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *Base,LONG Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement(LONG *Base,LONG Bit) {
      पूर्णांक old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Bit));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *Base,LONG Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *Base,LONG Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *Base,LONG Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *Base,LONG Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 स्थिर *Base,LONG64 Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *Base,LONG64 Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *Base,LONG64 Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *Base,LONG64 Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *Base,LONG64 Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *Base,LONG64 Offset) {
      पूर्णांक old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ दीर्घ *) Base))
	:"Ir" (Offset));
      वापस (BOOLEAN) (old!=0);
    }
#घोषणा BitScanForward _BitScanForward
#घोषणा BitScanReverse _BitScanReverse
#घोषणा BitScanForward64 _BitScanForward64
#घोषणा BitScanReverse64 _BitScanReverse64

    __CRT_INLINE BOOLEAN _BitScanForward(DWORD *सूचकांक_3,DWORD Mask) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (Mask),"=m" ((*(अस्थिर दीर्घ *)सूचकांक_3)));
      वापस Mask!=0;
    }
    __CRT_INLINE BOOLEAN _BitScanReverse(DWORD *सूचकांक_3,DWORD Mask) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (Mask),"=m" ((*(अस्थिर दीर्घ *)सूचकांक_3)));
      वापस Mask!=0;
    }
    __CRT_INLINE BOOLEAN _BitScanForward64(DWORD *सूचकांक_3,DWORD64 Mask) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (Mask),"=m" ((*(अस्थिर दीर्घ दीर्घ *)सूचकांक_3)));
      वापस Mask!=0;
    }
    __CRT_INLINE BOOLEAN _BitScanReverse64(DWORD *सूचकांक_3,DWORD64 Mask) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (Mask),"=m" ((*(अस्थिर दीर्घ दीर्घ *)सूचकांक_3)));
      वापस Mask!=0;
    }

#घोषणा InterlockedIncrement16 _InterlockedIncrement16
#घोषणा InterlockedDecrement16 _InterlockedDecrement16
#घोषणा InterlockedCompareExchange16 _InterlockedCompareExchange16

#घोषणा InterlockedAnd _InterlockedAnd
#घोषणा InterlockedOr _InterlockedOr
#घोषणा InterlockedXor _InterlockedXor
#घोषणा InterlockedIncrement _InterlockedIncrement
#घोषणा InterlockedIncrementAcquire InterlockedIncrement
#घोषणा InterlockedIncrementRelease InterlockedIncrement
#घोषणा InterlockedDecrement _InterlockedDecrement
#घोषणा InterlockedDecrementAcquire InterlockedDecrement
#घोषणा InterlockedDecrementRelease InterlockedDecrement
#घोषणा InterlockedAdd _InterlockedAdd
#घोषणा InterlockedExchange _InterlockedExchange
#घोषणा InterlockedExchangeAdd _InterlockedExchangeAdd
#घोषणा InterlockedCompareExchange _InterlockedCompareExchange
#घोषणा InterlockedCompareExchangeAcquire InterlockedCompareExchange
#घोषणा InterlockedCompareExchangeRelease InterlockedCompareExchange

#घोषणा InterlockedAnd64 _InterlockedAnd64
#घोषणा InterlockedAndAffinity InterlockedAnd64
#घोषणा InterlockedOr64 _InterlockedOr64
#घोषणा InterlockedOrAffinity InterlockedOr64
#घोषणा InterlockedXor64 _InterlockedXor64
#घोषणा InterlockedIncrement64 _InterlockedIncrement64
#घोषणा InterlockedDecrement64 _InterlockedDecrement64
#घोषणा InterlockedAdd64 _InterlockedAdd64
#घोषणा InterlockedExchange64 _InterlockedExchange64
#घोषणा InterlockedExchangeAcquire64 InterlockedExchange64
#घोषणा InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#घोषणा InterlockedCompareExchange64 _InterlockedCompareExchange64
#घोषणा InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#घोषणा InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#घोषणा InterlockedExchangePointer _InterlockedExchangePointer
#घोषणा InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#घोषणा InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#घोषणा InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer

#घोषणा Interlocked_Exchange_Add_आकार_T(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#घोषणा Interlocked_Increment_आकार_T(a) InterlockedIncrement64((LONG64 *)a)
#घोषणा Interlocked_Decrement_आकार_T(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT अस्थिर *Addend) {
      अचिन्हित अक्षर c;
      अचिन्हित अक्षर s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      वापस (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT अस्थिर *Addend) {
      अचिन्हित अक्षर c;
      अचिन्हित अक्षर s;
      __asm__ __volatile__(
	"lock ; subw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      वापस (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedCompareExchange16(SHORT अस्थिर *Destination,SHORT ExChange,SHORT Comperand) {
      SHORT पूर्व;
      __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
	:"=a"(पूर्व)
	:"q"(ExChange), "m"(*Destination), "0"(Comperand)
	: "memory");
      वापस पूर्व;
    }
    __CRT_INLINE LONG InterlockedAnd(LONG अस्थिर *Destination,LONG मूल्य_3) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(मूल्य_3),"m"(*Destination)
	: "memory");
      वापस *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG अस्थिर *Destination,LONG मूल्य_3) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(मूल्य_3),"m"(*Destination) : "memory");
      वापस *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG अस्थिर *Destination,LONG मूल्य_3) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(मूल्य_3),"m"(*Destination) : "memory");
      वापस *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 अस्थिर *Destination,LONG64 मूल्य_3) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(मूल्य_3),"m"(*Destination) : "memory");
      वापस *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 अस्थिर *Destination,LONG64 मूल्य_3) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(मूल्य_3),"m"(*Destination) : "memory");
      वापस *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 अस्थिर *Destination,LONG64 मूल्य_3) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(मूल्य_3),"m"(*Destination) : "memory");
      वापस *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG अस्थिर *Addend) {
      अचिन्हित अक्षर c;
      अचिन्हित अक्षर s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      वापस (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG अस्थिर *Addend) {
      अचिन्हित अक्षर c;
      अचिन्हित अक्षर s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      वापस (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG अस्थिर *Target,LONG मूल्य_3) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(मूल्य_3)
	: "m"(*Target),"0"(मूल्य_3)
	: "memory");
      वापस मूल्य_3;
    }
    LONG InterlockedExchangeAdd(LONG अस्थिर *Addend,LONG मूल्य_3);

#अगर_अघोषित _X86AMD64_
    __CRT_INLINE LONG InterlockedAdd(LONG अस्थिर *Addend,LONG मूल्य_3) { वापस InterlockedExchangeAdd(Addend,मूल्य_3) + मूल्य_3; }
#पूर्ण_अगर
    __CRT_INLINE LONG InterlockedCompareExchange(LONG अस्थिर *Destination,LONG ExChange,LONG Comperand) {
      LONG पूर्व;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (पूर्व) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      वापस पूर्व;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 अस्थिर *Addend) {
      अचिन्हित अक्षर c;
      अचिन्हित अक्षर s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      वापस (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 अस्थिर *Addend) {
      अचिन्हित अक्षर c;
      अचिन्हित अक्षर s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      वापस (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 अस्थिर *Target,LONG64 मूल्य_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(मूल्य_3)
	: "m"(*Target),"0"(मूल्य_3)
	: "memory");
      वापस मूल्य_3;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 अस्थिर *Addend,LONG64 मूल्य_3);

#अगर_अघोषित _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 अस्थिर *Addend,LONG64 मूल्य_3) { वापस InterlockedExchangeAdd64(Addend,मूल्य_3) + मूल्य_3; }
#पूर्ण_अगर

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 अस्थिर *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 पूर्व;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (पूर्व) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      वापस पूर्व;
    }
    __CRT_INLINE PVOID InterlockedCompareExchangePointer(PVOID अस्थिर *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID पूर्व;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (पूर्व) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      वापस पूर्व;
    }
    __CRT_INLINE PVOID InterlockedExchangePointer(PVOID अस्थिर *Target,PVOID मूल्य_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(मूल्य_3)
	: "m"(*Target),"0"(मूल्य_3)
	: "memory");
      वापस मूल्य_3;
    }

#घोषणा Cache_पंक्ति_Flush(Address) _mm_clflush(Address)

    VOID _ReadWriteBarrier(VOID);

#घोषणा FastFence __faststorefence
#घोषणा LoadFence _mm_lfence
#घोषणा MemoryFence _mm_mfence
#घोषणा StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(अस्थिर CONST VOID *Source);

//!__TINYC__: #include <intrin.h>

#घोषणा YieldProcessor _mm_pause
#घोषणा MemoryBarrier __faststorefence
#घोषणा Pre_Fetch_Cache_पंक्ति(l,a) _mm_prefetch((CHAR CONST *) a,l)
#घोषणा PrefetchForWrite(p) _m_prefetchw(p)
#घोषणा ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#घोषणा PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#घोषणा PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#घोषणा PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#घोषणा PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#घोषणा ReadMxCsr _mm_getcsr
#घोषणा WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#घोषणा DbgRaiseAssertionFailure() __int2c()
#घोषणा GetCallersEflags() __getcallerseflags()

    अचिन्हित __int32 __getcallerseflags(VOID);

#घोषणा GetSegmentLimit __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#घोषणा Read_Time_Stamp_गणक() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE स्थिर *Source,आकार_T गिनती_3);
    VOID __movsw(PWORD Destination,WORD स्थिर *Source,आकार_T गिनती_3);
    VOID __movsd(PDWORD Destination,DWORD स्थिर *Source,आकार_T गिनती_3);
    VOID __movsq(PDWORD64 Destination,DWORD64 स्थिर *Source,आकार_T गिनती_3);
    VOID __stosb(PBYTE Destination,BYTE मूल्य_3,आकार_T गिनती_3);
    VOID __stosw(PWORD Destination,WORD मूल्य_3,आकार_T गिनती_3);
    VOID __stosd(PDWORD Destination,DWORD मूल्य_3,आकार_T गिनती_3);
    VOID __stosq(PDWORD64 Destination,DWORD64 मूल्य_3,आकार_T गिनती_3);

#घोषणा Multiply_ऊपरी __mulh
#घोषणा Unsigned_Multiply_ऊपरी __umulh

    LONGLONG Multiply_ऊपरी(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG Unsigned_Multiply_ऊपरी(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#घोषणा ShiftLeft128 __shiftleft128
#घोषणा ShiftRight128 __shiftright128

    DWORD64 ShiftLeft128(DWORD64 निचला_Part,DWORD64 ऊपरी_Part,BYTE Shift);
    DWORD64 ShiftRight128(DWORD64 निचला_Part,DWORD64 ऊपरी_Part,BYTE Shift);

#घोषणा Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *ऊपरी_Product);

#घोषणा UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *ऊपरी_Product);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE Shift) {
      LONG64 extractedProduct;
      LONG64 ऊपरी_Product_2;
      LONG64 निचला_Product;
      निचला_Product = Multiply128(Multiplier,Multiplicand,&ऊपरी_Product_2);
      extractedProduct = (LONG64)ShiftRight128((LONG64)निचला_Product,(LONG64)ऊपरी_Product_2,Shift);
      वापस extractedProduct;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE Shift) {
      DWORD64 extractedProduct;
      DWORD64 ऊपरी_Product_2;
      DWORD64 निचला_Product;
      निचला_Product = UnsignedMultiply128(Multiplier,Multiplicand,&ऊपरी_Product_2);
      extractedProduct = ShiftRight128(निचला_Product,ऊपरी_Product_2,Shift);
      वापस extractedProduct;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD Offset) {
      BYTE ret;
      __asm__ अस्थिर ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(अस्थिर दीर्घ *) (DWORD64) Offset)));
      वापस ret;
    }
    __CRT_INLINE WORD __readgsword(DWORD Offset) {
      WORD ret;
      __asm__ अस्थिर ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(अस्थिर दीर्घ *) (DWORD64) Offset)));
      वापस ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD Offset) {
      DWORD ret;
      __asm__ अस्थिर ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(अस्थिर दीर्घ *) (DWORD64) Offset)));
      वापस ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD Offset) {
      व्योम *ret;
      __asm__ अस्थिर ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(अस्थिर दीर्घ *) (DWORD64) Offset)));
      वापस (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD Offset,BYTE तथ्य_3) {
      __asm__ अस्थिर ("movb	%0,%%gs:%1"
	: "=r" (तथ्य_3) ,"=m" ((*(अस्थिर दीर्घ *) (DWORD64) Offset)));
    }
    __CRT_INLINE VOID __writegsword(DWORD Offset,WORD तथ्य_3) {
      __asm__ अस्थिर ("movw	%0,%%gs:%1"
	: "=r" (तथ्य_3) ,"=m" ((*(अस्थिर दीर्घ *) (DWORD64) Offset)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD Offset,DWORD तथ्य_3) {
      __asm__ अस्थिर ("movl	%0,%%gs:%1"
	: "=r" (तथ्य_3) ,"=m" ((*(अस्थिर दीर्घ *) (DWORD64) Offset)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD Offset,DWORD64 तथ्य_3) {
      __asm__ अस्थिर ("movq	%0,%%gs:%1"
	: "=r" (तथ्य_3) ,"=m" ((*(अस्थिर दीर्घ *) (DWORD64) Offset)));
    }

#अगर_घोषित __cplusplus
  }
#पूर्ण_अगर

#घोषणा EXCEPTION_READ_FAULT 0
#घोषणा EXCEPTION_WRITE_FAULT 1
#घोषणा EXCEPTION_EXECUTE_FAULT 8

#अगर !defined(RC_INVOKED)

#घोषणा CONTEXT_AMD64 0x100000

#घोषणा CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#घोषणा CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#घोषणा CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#घोषणा CONTEXT_FLOATING_POINT (CONTEXT_AMD64 | 0x8L)
#घोषणा CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#घोषणा CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
#घोषणा CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS)

#घोषणा CONTEXT_EXCEPTION_ACTIVE 0x8000000
#घोषणा CONTEXT_SERVICE_ACTIVE 0x10000000
#घोषणा CONTEXT_EXCEPTION_REQUEST 0x40000000
#घोषणा CONTEXT_EXCEPTION_REPORTING 0x80000000
#पूर्ण_अगर

#घोषणा INITIAL_MXCSR 0x1f80
#घोषणा INITIAL_FPCSR 0x027f

  प्रकार काष्ठा DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG निचला_3;
    LONGLONG ऊपरी_3;
  } M128A,*PM128A;

  प्रकार काष्ठा _XMM_SAVE_AREA32 {
    WORD ControlWord;
    WORD StatusWord;
    BYTE TagWord;
    BYTE Reserved1;
    WORD ErrorOpcode;
    DWORD ErrorOffset;
    WORD ErrorSelector;
    WORD Reserved2;
    DWORD तथ्य_Offset;
    WORD तथ्य_Selector;
    WORD Reserved3;
    DWORD MxCsr;
    DWORD MxCsr_Mask;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#घोषणा LEGACY_SAVE_AREA_लंबाई माप(XMM_SAVE_AREA32)

  प्रकार काष्ठा DECLSPEC_ALIGN(16) _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    WORD SegCs;
    WORD SegDs;
    WORD SegEs;
    WORD SegFs;
    WORD SegGs;
    WORD SegSs;
    DWORD EFlags;
    DWORD64 Dr0;
    DWORD64 Dr1;
    DWORD64 Dr2;
    DWORD64 Dr3;
    DWORD64 Dr6;
    DWORD64 Dr7;
    DWORD64 Rax;
    DWORD64 Rcx;
    DWORD64 Rdx;
    DWORD64 Rbx;
    DWORD64 Rsp;
    DWORD64 Rbp;
    DWORD64 Rsi;
    DWORD64 Rdi;
    DWORD64 R8;
    DWORD64 R9;
    DWORD64 R10;
    DWORD64 R11;
    DWORD64 R12;
    DWORD64 R13;
    DWORD64 R14;
    DWORD64 R15;
    DWORD64 Rip;
    जोड़ {
      XMM_SAVE_AREA32 FltSave;
      XMM_SAVE_AREA32 FloatSave;
      काष्ठा {
	M128A Header[2];
	M128A Legacy[8];
	M128A Xmm0;
	M128A Xmm1;
	M128A Xmm2;
	M128A Xmm3;
	M128A Xmm4;
	M128A Xmm5;
	M128A Xmm6;
	M128A Xmm7;
	M128A Xmm8;
	M128A Xmm9;
	M128A Xmm10;
	M128A Xmm11;
	M128A Xmm12;
	M128A Xmm13;
	M128A Xmm14;
	M128A Xmm15;
      };
    };
    M128A VectorRegister[26];
    DWORD64 VectorControl;
    DWORD64 DebugControl;
    DWORD64 LastBranchToRip;
    DWORD64 LastBranchFromRip;
    DWORD64 LastExceptionToRip;
    DWORD64 LastExceptionFromRip;
  } CONTEXT,*PCONTEXT;

#घोषणा RUNTIME_FUNCTION_INDIRECT 0x1

  प्रकार काष्ठा _RUNTIME_FUNCTION {
    DWORD BeginAddress;
    DWORD EndAddress;
    DWORD Unwind_तथ्य;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  प्रकार PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  प्रकार DWORD (*POUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK)(HANDLE Process,PVOID TableAddress,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#घोषणा OUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"
#पूर्ण_अगर /* defined(__x86_64) && !defined(RC_INVOKED) */

#अगर defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED)

#घोषणा __TCC_WINNT_ATOMIC_SEQ_CST 5
/* TCC lowers __atomic_compare_exchange's fourth argument as weak, but the
   ARM64 helper reads it as success_memorder.  Strong CAS passes weak == 0,
   so keep Interlocked's barriers explicit here. */
#घोषणा __TCC_WINNT_MEMORY_BARRIER() __asm__ __volatile__("dmb ish" : : : "memory")

/* This covers the LONG operations needed by TCC's semaphore code and the
   pointer helpers that winbase.h exposes through Interlocked pointer macros.
   Add local helpers before relying on increment/decrement, add/exchange-add,
   bitwise, or 64-bit Interlocked forms on Windows ARM64 with TCC. */

    __CRT_INLINE LONG InterlockedExchange(LONG अस्थिर *Target,LONG मूल्य_3) {
      LONG Old;
      __atomic_load(Target,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      जबतक (!__atomic_compare_exchange(Target,&Old,&मूल्य_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      वापस Old;
    }
    __CRT_INLINE LONG InterlockedCompareExchange(LONG अस्थिर *Destination,LONG ExChange,LONG Comperand) {
      LONG Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      वापस Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedExchangePointer(PVOID अस्थिर *Target,PVOID मूल्य_3) {
      PVOID Old;
      __atomic_load(Target,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      जबतक (!__atomic_compare_exchange(Target,&Old,&मूल्य_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      वापस Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedCompareExchangePointer(PVOID अस्थिर *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      वापस Old;
    }

#घोषणा InterlockedExchangePointer __TCC_WINNT_InterlockedExchangePointer
#घोषणा InterlockedCompareExchangePointer __TCC_WINNT_InterlockedCompareExchangePointer
#घोषणा InterlockedCompareExchangePointerAcquire InterlockedCompareExchangePointer
#घोषणा InterlockedCompareExchangePointerRelease InterlockedCompareExchangePointer

#घोषणा InterlockedCompareExchangeAcquire InterlockedCompareExchange
#घोषणा InterlockedCompareExchangeRelease InterlockedCompareExchange

#अघोषित __TCC_WINNT_MEMORY_BARRIER
#अघोषित __TCC_WINNT_ATOMIC_SEQ_CST

#पूर्ण_अगर /* defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED) */

#अगर defined(_ARM64_)

/* ARM64 Context Definition */
#घोषणा CONTEXT_ARM64 0x00400000
#घोषणा CONTEXT_CONTROL (CONTEXT_ARM64 | 0x00000001L)
#घोषणा CONTEXT_INTEGER (CONTEXT_ARM64 | 0x00000002L)
#घोषणा CONTEXT_FLOATING_POINT (CONTEXT_ARM64 | 0x00000004L)
#घोषणा CONTEXT_DEBUG (CONTEXT_ARM64 | 0x00000008L)
#घोषणा CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
#घोषणा CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG)
#घोषणा ARM64_MAX_BREAKPOINTS 8
#घोषणा ARM64_MAX_WATCHPOINTS 2

  प्रकार जोड़ _ARM64_NT_NEON128 {
    काष्ठा {
      ULONGLONG निचला_3;
      LONGLONG ऊपरी_3;
    } DUMMYSTRUCTNAME;
    द्विगुन D[2];
    भग्न S[4];
    WORD H[8];
    BYTE B[16];
  } ARM64_NT_NEON128,*PARM64_NT_NEON128;

  प्रकार काष्ठा DECLSPEC_ALIGN(16) _ARM64_NT_CONTEXT {
    ULONG ContextFlags;
    ULONG Cpsr;
    जोड़ {
      काष्ठा {
        DWORD64 X0;
        DWORD64 X1;
        DWORD64 X2;
        DWORD64 X3;
        DWORD64 X4;
        DWORD64 X5;
        DWORD64 X6;
        DWORD64 X7;
        DWORD64 X8;
        DWORD64 X9;
        DWORD64 X10;
        DWORD64 X11;
        DWORD64 X12;
        DWORD64 X13;
        DWORD64 X14;
        DWORD64 X15;
        DWORD64 X16;
        DWORD64 X17;
        DWORD64 X18;
        DWORD64 X19;
        DWORD64 X20;
        DWORD64 X21;
        DWORD64 X22;
        DWORD64 X23;
        DWORD64 X24;
        DWORD64 X25;
        DWORD64 X26;
        DWORD64 X27;
        DWORD64 X28;
        DWORD64 Fp;
        DWORD64 Lr;
      } DUMMYSTRUCTNAME;
      DWORD64 X[31];
    } DUMMYUNIONNAME;
    DWORD64 Sp;
    DWORD64 Pc;
    ARM64_NT_NEON128 V[32];
    DWORD Fpcr;
    DWORD Fpsr;
    DWORD Bcr[ARM64_MAX_BREAKPOINTS];
    DWORD64 Bvr[ARM64_MAX_BREAKPOINTS];
    DWORD Wcr[ARM64_MAX_WATCHPOINTS];
    DWORD64 Wvr[ARM64_MAX_WATCHPOINTS];
  } ARM64_NT_CONTEXT,*PARM64_NT_CONTEXT;

  C_ASSERT(माप(ARM64_NT_CONTEXT) == 0x390);

  प्रकार ARM64_NT_CONTEXT CONTEXT,*PCONTEXT;

  प्रकार काष्ठा _RUNTIME_FUNCTION {
    DWORD BeginAddress;
    DWORD Unwind_तथ्य;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  प्रकार PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  प्रकार DWORD (*POUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK)(HANDLE Process,PVOID TableAddress,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#पूर्ण_अगर /* _ARM64_ */

#अगर (defined _ARM64_ || defined _AMD64_) && !defined RC_INVOKED
  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT ContextRecord,काष्ठा _EXCEPTION_RECORD *ExceptionRecord);
  NTSYSAPI BOOLEAN __cdecl RtlAddFunctionTable(PRUNTIME_FUNCTION FunctionTable,DWORD Entry_गिनती,DWORD64 BaseAddress);
  NTSYSAPI BOOLEAN __cdecl RtlInstallFunctionTableCallback(DWORD64 TableIdentifier,DWORD64 BaseAddress,DWORD लंबाई_2,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR OutOfProcessCallbackDll);
  NTSYSAPI BOOLEAN __cdecl RtlDeleteFunctionTable(PRUNTIME_FUNCTION FunctionTable);
#पूर्ण_अगर

#अगर_घोषित I_X86_
#अगर(defined(_X86_) && !defined(__x86_64)) && !defined(RC_INVOKED)
#अगर_घोषित __cplusplus
  बाह्य "C" {
#पूर्ण_अगर

    __CRT_INLINE BOOLEAN InterlockedBitTestAndSet(LONG *Base,LONG Bit) {
      पूर्णांक old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Bit));
      वापस (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN InterlockedBitTestAndReset(LONG *Base,LONG Bit) {
      पूर्णांक old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Bit));
      वापस (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement(LONG *Base,LONG Bit) {
      पूर्णांक old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(अस्थिर दीर्घ *) Base))
	:"Ir" (Bit));
      वापस (BOOLEAN) (old!=0);
    }

#अगर_घोषित _PREFIX_
    BYTE __readfsbyte(DWORD Offset);
    WORD __readfsword(DWORD Offset);
    DWORD __readfsdword(DWORD Offset);
    VOID __writefsbyte(DWORD Offset,BYTE तथ्य_3);
    VOID __writefsword(DWORD Offset,WORD तथ्य_3);
    VOID __writefsdword(DWORD Offset,DWORD तथ्य_3);
#पूर्ण_अगर

#अगर_घोषित __cplusplus
  }
#पूर्ण_अगर
#पूर्ण_अगर

#अगर(defined(_X86_) && !defined(__x86_64))
  __CRT_INLINE VOID MemoryBarrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
  }
#घोषणा YieldProcessor() __asm__ __volatile__("rep nop ");

#घोषणा Pre_Fetch_Cache_पंक्ति(l,a)
#घोषणा ReadForWriteAccess(p) (*(p))

#घोषणा PF_TEMPORAL_LEVEL_1
#घोषणा PF_NON_TEMPORAL_LEVEL_ALL

  __CRT_INLINE VOID DbgRaiseAssertionFailure(व्योम) {
    __asm__ __volatile__("int $0x2c ");
  }
  PVOID GetCurrentFiber(व्योम);
  __CRT_INLINE PVOID GetCurrentFiber(व्योम)
  {
    व्योम *ret;
    __asm__ अस्थिर ("movl	%%fs:0x10,%0"
	: "=r" (ret));
    वापस ret;
  }
  PVOID Get_Fiber_तथ्य(व्योम);
  __CRT_INLINE PVOID Get_Fiber_तथ्य(व्योम)
  {
    व्योम *ret;
    __asm__ अस्थिर ("movl	%%fs:0x10,%0\n"
	"movl	(%0),%0"
	: "=r" (ret));
    वापस ret;
  }
#पूर्ण_अगर

#घोषणा EXCEPTION_READ_FAULT 0
#घोषणा EXCEPTION_WRITE_FAULT 1
#घोषणा EXCEPTION_EXECUTE_FAULT 8

#घोषणा आकार_OF_80387_REGISTERS 80

#अगर !defined(RC_INVOKED)

#घोषणा CONTEXT_i386 0x00010000
#घोषणा CONTEXT_i486 0x00010000

#घोषणा CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#घोषणा CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#घोषणा CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#घोषणा CONTEXT_FLOATING_POINT (CONTEXT_i386 | 0x00000008L)
#घोषणा CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#घोषणा CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#घोषणा CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#घोषणा CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#पूर्ण_अगर

#घोषणा MAXIMUM_SUPPORTED_EXTENSION 512

    प्रकार काष्ठा _FLOATING_SAVE_AREA {
      DWORD ControlWord;
      DWORD StatusWord;
      DWORD TagWord;
      DWORD ErrorOffset;
      DWORD ErrorSelector;
      DWORD तथ्य_Offset;
      DWORD तथ्य_Selector;
      BYTE RegisterArea[आकार_OF_80387_REGISTERS];
      DWORD Cr0NpxState;
    } FLOATING_SAVE_AREA;

    प्रकार FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;

    प्रकार काष्ठा _CONTEXT {
      DWORD ContextFlags;
      DWORD Dr0;
      DWORD Dr1;
      DWORD Dr2;
      DWORD Dr3;
      DWORD Dr6;
      DWORD Dr7;
      FLOATING_SAVE_AREA FloatSave;
      DWORD SegGs;
      DWORD SegFs;
      DWORD SegEs;
      DWORD SegDs;

      DWORD Edi;
      DWORD Esi;
      DWORD Ebx;
      DWORD Edx;
      DWORD Ecx;
      DWORD Eax;
      DWORD Ebp;
      DWORD Eip;
      DWORD SegCs;
      DWORD EFlags;
      DWORD Esp;
      DWORD SegSs;
      BYTE ExtendedRegisters[MAXIMUM_SUPPORTED_EXTENSION];
    } CONTEXT;

    प्रकार CONTEXT *PCONTEXT;
#पूर्ण_अगर

#अगर_अघोषित _LDT_ENTRY_DEFINED
#घोषणा _LDT_ENTRY_DEFINED

    प्रकार काष्ठा _LDT_ENTRY {
      WORD Limit_निचला;
      WORD Base_निचला;
      जोड़ {
	काष्ठा {
	  BYTE BaseMid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE BaseHi;
	} Bytes;
	काष्ठा {
	  DWORD BaseMid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD LimitHi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD BaseHi : 8;
	} Bits;
      } ऊपरी_Word;
    } LDT_ENTRY,*PLDT_ENTRY;
#पूर्ण_अगर

#अगर defined(__ia64__) && !defined(RC_INVOKED)

#अगर_घोषित __cplusplus
    बाह्य "C" {
#पूर्ण_अगर

      BOOLEAN BitScanForward64(DWORD *सूचकांक_3,DWORD64 Mask);
      BOOLEAN BitScanReverse64(DWORD *सूचकांक_3,DWORD64 Mask);

#अगर_घोषित __cplusplus
    }
#पूर्ण_अगर
#पूर्ण_अगर

#अगर !defined(GENUTIL) && !defined(_GENIA64_) && defined(_IA64_)

    व्योम *_cdecl _rdteb(व्योम);
#अगर_घोषित __ia64__

#घोषणा NtCurrentTeb() ((काष्ठा _TEB *)_rdteb())
#घोषणा GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->Fiber_तथ्य)
#घोषणा Get_Fiber_तथ्य() (*(PVOID *)(GetCurrentFiber()))

#अगर_घोषित __cplusplus
    बाह्य "C" {
#पूर्ण_अगर

      व्योम __break(पूर्णांक);
      व्योम __yield(व्योम);
      व्योम __mf(व्योम);
      व्योम __lfetch(पूर्णांक Level,VOID CONST *Address);
      व्योम __lfetchfault(पूर्णांक Level,VOID CONST *Address);
      व्योम __lfetch_excl(पूर्णांक Level,VOID CONST *Address);
      व्योम __lfetchfault_excl(पूर्णांक Level,VOID CONST *Address);

#घोषणा MD_LFHINT_NONE 0x00
#घोषणा MD_LFHINT_NT1 0x01
#घोषणा MD_LFHINT_NT2 0x02
#घोषणा MD_LFHINT_NTA 0x03

#अगर_घोषित __cplusplus
    }
#पूर्ण_अगर

#घोषणा YieldProcessor __yield
#घोषणा MemoryBarrier __mf
#घोषणा Pre_Fetch_Cache_पंक्ति __lfetch
#घोषणा ReadForWriteAccess(p) (*(p))
#घोषणा DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#घोषणा PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#घोषणा PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#घोषणा Unsigned_Multiply_ऊपरी __UMULH

    ULONGLONG Unsigned_Multiply_ऊपरी(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#अन्यथा
    काष्ठा _TEB *NtCurrentTeb(व्योम);
#पूर्ण_अगर
#पूर्ण_अगर

#अगर_घोषित _IA64_

#घोषणा EXCEPTION_READ_FAULT 0
#घोषणा EXCEPTION_WRITE_FAULT 1
#घोषणा EXCEPTION_EXECUTE_FAULT 2

#अगर !defined(RC_INVOKED)

#घोषणा CONTEXT_IA64 0x00080000

#घोषणा CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#घोषणा CONTEXT_LOWER_FLOATING_POINT (CONTEXT_IA64 | 0x00000002L)
#घोषणा CONTEXT_HIGHER_FLOATING_POINT (CONTEXT_IA64 | 0x00000004L)
#घोषणा CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#घोषणा CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#घोषणा CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#घोषणा CONTEXT_FLOATING_POINT (CONTEXT_LOWER_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT)
#घोषणा CONTEXT_FULL (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#घोषणा CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#घोषणा CONTEXT_EXCEPTION_ACTIVE 0x8000000
#घोषणा CONTEXT_SERVICE_ACTIVE 0x10000000
#घोषणा CONTEXT_EXCEPTION_REQUEST 0x40000000
#घोषणा CONTEXT_EXCEPTION_REPORTING 0x80000000
#पूर्ण_अगर

    प्रकार काष्ठा _CONTEXT {
      DWORD ContextFlags;
      DWORD Fill1[3];
      ULONGLONG DbI0;
      ULONGLONG DbI1;
      ULONGLONG DbI2;
      ULONGLONG DbI3;
      ULONGLONG DbI4;
      ULONGLONG DbI5;
      ULONGLONG DbI6;
      ULONGLONG DbI7;
      ULONGLONG DbD0;
      ULONGLONG DbD1;
      ULONGLONG DbD2;
      ULONGLONG DbD3;
      ULONGLONG DbD4;
      ULONGLONG DbD5;
      ULONGLONG DbD6;
      ULONGLONG DbD7;
      FLOAT128 FltS0;
      FLOAT128 FltS1;
      FLOAT128 FltS2;
      FLOAT128 FltS3;
      FLOAT128 FltT0;
      FLOAT128 FltT1;
      FLOAT128 FltT2;
      FLOAT128 FltT3;
      FLOAT128 FltT4;
      FLOAT128 FltT5;
      FLOAT128 FltT6;
      FLOAT128 FltT7;
      FLOAT128 FltT8;
      FLOAT128 FltT9;
      FLOAT128 FltS4;
      FLOAT128 FltS5;
      FLOAT128 FltS6;
      FLOAT128 FltS7;
      FLOAT128 FltS8;
      FLOAT128 FltS9;
      FLOAT128 FltS10;
      FLOAT128 FltS11;
      FLOAT128 FltS12;
      FLOAT128 FltS13;
      FLOAT128 FltS14;
      FLOAT128 FltS15;
      FLOAT128 FltS16;
      FLOAT128 FltS17;
      FLOAT128 FltS18;
      FLOAT128 FltS19;
      FLOAT128 FltF32;
      FLOAT128 FltF33;
      FLOAT128 FltF34;
      FLOAT128 FltF35;
      FLOAT128 FltF36;
      FLOAT128 FltF37;
      FLOAT128 FltF38;
      FLOAT128 FltF39;
      FLOAT128 FltF40;
      FLOAT128 FltF41;
      FLOAT128 FltF42;
      FLOAT128 FltF43;
      FLOAT128 FltF44;
      FLOAT128 FltF45;
      FLOAT128 FltF46;
      FLOAT128 FltF47;
      FLOAT128 FltF48;
      FLOAT128 FltF49;
      FLOAT128 FltF50;
      FLOAT128 FltF51;
      FLOAT128 FltF52;
      FLOAT128 FltF53;
      FLOAT128 FltF54;
      FLOAT128 FltF55;
      FLOAT128 FltF56;
      FLOAT128 FltF57;
      FLOAT128 FltF58;
      FLOAT128 FltF59;
      FLOAT128 FltF60;
      FLOAT128 FltF61;
      FLOAT128 FltF62;
      FLOAT128 FltF63;
      FLOAT128 FltF64;
      FLOAT128 FltF65;
      FLOAT128 FltF66;
      FLOAT128 FltF67;
      FLOAT128 FltF68;
      FLOAT128 FltF69;
      FLOAT128 FltF70;
      FLOAT128 FltF71;
      FLOAT128 FltF72;
      FLOAT128 FltF73;
      FLOAT128 FltF74;
      FLOAT128 FltF75;
      FLOAT128 FltF76;
      FLOAT128 FltF77;
      FLOAT128 FltF78;
      FLOAT128 FltF79;
      FLOAT128 FltF80;
      FLOAT128 FltF81;
      FLOAT128 FltF82;
      FLOAT128 FltF83;
      FLOAT128 FltF84;
      FLOAT128 FltF85;
      FLOAT128 FltF86;
      FLOAT128 FltF87;
      FLOAT128 FltF88;
      FLOAT128 FltF89;
      FLOAT128 FltF90;
      FLOAT128 FltF91;
      FLOAT128 FltF92;
      FLOAT128 FltF93;
      FLOAT128 FltF94;
      FLOAT128 FltF95;
      FLOAT128 FltF96;
      FLOAT128 FltF97;
      FLOAT128 FltF98;
      FLOAT128 FltF99;
      FLOAT128 FltF100;
      FLOAT128 FltF101;
      FLOAT128 FltF102;
      FLOAT128 FltF103;
      FLOAT128 FltF104;
      FLOAT128 FltF105;
      FLOAT128 FltF106;
      FLOAT128 FltF107;
      FLOAT128 FltF108;
      FLOAT128 FltF109;
      FLOAT128 FltF110;
      FLOAT128 FltF111;
      FLOAT128 FltF112;
      FLOAT128 FltF113;
      FLOAT128 FltF114;
      FLOAT128 FltF115;
      FLOAT128 FltF116;
      FLOAT128 FltF117;
      FLOAT128 FltF118;
      FLOAT128 FltF119;
      FLOAT128 FltF120;
      FLOAT128 FltF121;
      FLOAT128 FltF122;
      FLOAT128 FltF123;
      FLOAT128 FltF124;
      FLOAT128 FltF125;
      FLOAT128 FltF126;
      FLOAT128 FltF127;
      ULONGLONG StFPSR;
      ULONGLONG IntGp;
      ULONGLONG IntT0;
      ULONGLONG IntT1;
      ULONGLONG IntS0;
      ULONGLONG IntS1;
      ULONGLONG IntS2;
      ULONGLONG IntS3;
      ULONGLONG IntV0;
      ULONGLONG IntT2;
      ULONGLONG IntT3;
      ULONGLONG IntT4;
      ULONGLONG IntSp;
      ULONGLONG IntTeb;
      ULONGLONG IntT5;
      ULONGLONG IntT6;
      ULONGLONG IntT7;
      ULONGLONG IntT8;
      ULONGLONG IntT9;
      ULONGLONG IntT10;
      ULONGLONG IntT11;
      ULONGLONG IntT12;
      ULONGLONG IntT13;
      ULONGLONG IntT14;
      ULONGLONG IntT15;
      ULONGLONG IntT16;
      ULONGLONG IntT17;
      ULONGLONG IntT18;
      ULONGLONG IntT19;
      ULONGLONG IntT20;
      ULONGLONG IntT21;
      ULONGLONG IntT22;
      ULONGLONG IntNats;
      ULONGLONG Preds;
      ULONGLONG BrRp;
      ULONGLONG BrS0;
      ULONGLONG BrS1;
      ULONGLONG BrS2;
      ULONGLONG BrS3;
      ULONGLONG BrS4;
      ULONGLONG BrT0;
      ULONGLONG BrT1;
      ULONGLONG ApUNAT;
      ULONGLONG ApLC;
      ULONGLONG ApEC;
      ULONGLONG ApCCV;
      ULONGLONG ApDCR;
      ULONGLONG RsPFS;
      ULONGLONG RsBSP;
      ULONGLONG RsBSPSTORE;
      ULONGLONG RsRSC;
      ULONGLONG RsRNAT;
      ULONGLONG StIPSR;
      ULONGLONG StIIP;
      ULONGLONG StIFS;
      ULONGLONG StFCR;
      ULONGLONG Eflag;
      ULONGLONG SegCSD;
      ULONGLONG SegSSD;
      ULONGLONG Cflag;
      ULONGLONG StFSR;
      ULONGLONG StFIR;
      ULONGLONG StFDR;
      ULONGLONG UNUSEDPACK;
    } CONTEXT,*PCONTEXT;

    प्रकार काष्ठा _PLABEL_DESCRIPTOR {
      ULONGLONG EntryPoint;
      ULONGLONG GlobalPointer;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    प्रकार काष्ठा _RUNTIME_FUNCTION {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindInfoAddress;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    प्रकार PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    प्रकार DWORD (*POUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK)(HANDLE Process,PVOID TableAddress,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#घोषणा OUT_OF_PROCESS_FUNCTION_TABLE_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN RtlAddFunctionTable(PRUNTIME_FUNCTION FunctionTable,DWORD Entry_गिनती,ULONGLONG BaseAddress,ULONGLONG TargetGp);
    BOOLEAN RtlInstallFunctionTableCallback(DWORD64 TableIdentifier,DWORD64 BaseAddress,DWORD लंबाई_2,DWORD64 TargetGp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR OutOfProcessCallbackDll);
    BOOLEAN RtlDeleteFunctionTable(PRUNTIME_FUNCTION FunctionTable);
    VOID RtlRestoreContext (PCONTEXT ContextRecord,काष्ठा _EXCEPTION_RECORD *ExceptionRecord);
    VOID __jump_unwind(ULONGLONG TargetMsFrame,ULONGLONG TargetBsFrame,ULONGLONG TargetPc);
#पूर्ण_अगर

#घोषणा EXCEPTION_NONCONTINUABLE 0x1
#घोषणा EXCEPTION_MAXIMUM_PARAMETERS 15

    प्रकार काष्ठा _EXCEPTION_RECORD {
      DWORD ExceptionCode;
      DWORD ExceptionFlags;
      काष्ठा _EXCEPTION_RECORD *ExceptionRecord;
      PVOID ExceptionAddress;
      DWORD संख्या_Parameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
    } EXCEPTION_RECORD;

    प्रकार EXCEPTION_RECORD *PEXCEPTION_RECORD;

    प्रकार काष्ठा _EXCEPTION_RECORD32 {
      DWORD ExceptionCode;
      DWORD ExceptionFlags;
      DWORD ExceptionRecord;
      DWORD ExceptionAddress;
      DWORD संख्या_Parameters;
      DWORD ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    प्रकार काष्ठा _EXCEPTION_RECORD64 {
      DWORD ExceptionCode;
      DWORD ExceptionFlags;
      DWORD64 ExceptionRecord;
      DWORD64 ExceptionAddress;
      DWORD संख्या_Parameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_MAXIMUM_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    प्रकार काष्ठा _EXCEPTION_POINTERS {
      PEXCEPTION_RECORD ExceptionRecord;
      PCONTEXT ContextRecord;
    } EXCEPTION_POINTERS,*PEXCEPTION_POINTERS;

#अगर_घोषित __x86_64

    प्रकार EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (काष्ठा _EXCEPTION_RECORD *ExceptionRecord, PVOID EstablisherFrame, काष्ठा _CONTEXT *ContextRecord, PVOID DispatcherContext);
#अगर_अघोषित __PEXCEPTION_ROUTINE_DEFINED
#घोषणा __PEXCEPTION_ROUTINE_DEFINED
    प्रकार EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#पूर्ण_अगर

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#घोषणा UNWIND_HISTORY_TABLE_आकार 12

  प्रकार काष्ठा _UNWIND_HISTORY_TABLE_ENTRY {
    ULONG64 ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
  } UNWIND_HISTORY_TABLE_ENTRY, *PUNWIND_HISTORY_TABLE_ENTRY;

#घोषणा UNWIND_HISTORY_TABLE_NONE    0
#घोषणा UNWIND_HISTORY_TABLE_GLOBAL  1
#घोषणा UNWIND_HISTORY_TABLE_LOCAL   2

  प्रकार काष्ठा _UNWIND_HISTORY_TABLE {
    ULONG गिनती_3;
    UCHAR खोज;
    ULONG64 निचला_Address;
    ULONG64 ऊपरी_Address;
    UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_आकार];
  } UNWIND_HISTORY_TABLE, *PUNWIND_HISTORY_TABLE;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  काष्ठा _DISPATCHER_CONTEXT;
  प्रकार काष्ठा _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  प्रकार काष्ठा _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  काष्ठा _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 ImageBase;
    PRUNTIME_FUNCTION FunctionEntry;
    ULONG64 EstablisherFrame;
    ULONG64 TargetIp;
    PCONTEXT ContextRecord;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID Handler_तथ्य;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_TABLE HistoryTable;
    ULONG Scope_सूचकांक;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  प्रकार काष्ठा _KNONVOLATILE_CONTEXT_POINTERS
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_POINTERS, *PKNONVOLATILE_CONTEXT_POINTERS;
#पूर्ण_अगर /* defined(__x86_64) */

    प्रकार PVOID PACCESS_TOKEN;
    प्रकार PVOID PSECURITY_DESCRIPTOR;
    प्रकार PVOID PSID;

    प्रकार DWORD ACCESS_MASK;
    प्रकार ACCESS_MASK *PACCESS_MASK;

#घोषणा DELETE (0x00010000L)
#घोषणा READ_CONTROL (0x00020000L)
#घोषणा WRITE_DAC (0x00040000L)
#घोषणा WRITE_OWNER (0x00080000L)
#घोषणा SYNCHRONIZE (0x00100000L)

#घोषणा STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#घोषणा STANDARD_RIGHTS_READ (READ_CONTROL)
#घोषणा STANDARD_RIGHTS_WRITE (READ_CONTROL)
#घोषणा STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#घोषणा STANDARD_RIGHTS_ALL (0x001F0000L)

#घोषणा SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#घोषणा ACCESS_SYSTEM_SECURITY (0x01000000L)

#घोषणा MAXIMUM_ALLOWED (0x02000000L)

#घोषणा GENERIC_READ (0x80000000L)
#घोषणा GENERIC_WRITE (0x40000000L)
#घोषणा GENERIC_EXECUTE (0x20000000L)
#घोषणा GENERIC_ALL (0x10000000L)

    प्रकार काष्ठा _GENERIC_MAPPING {
      ACCESS_MASK GenericRead;
      ACCESS_MASK GenericWrite;
      ACCESS_MASK GenericExecute;
      ACCESS_MASK GenericAll;
    } GENERIC_MAPPING;
    प्रकार GENERIC_MAPPING *PGENERIC_MAPPING;

#समावेश <pshpack4.h>

    प्रकार काष्ठा _LUID_AND_ATTRIBUTES {
      LUID Luid;
      DWORD Attributes;
    } LUID_AND_ATTRIBUTES,*PLUID_AND_ATTRIBUTES;
    प्रकार LUID_AND_ATTRIBUTES LUID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
    प्रकार LUID_AND_ATTRIBUTES_ARRAY *PLUID_AND_ATTRIBUTES_ARRAY;

#समावेश <poppack.h>

#अगर_अघोषित SID_IDENTIFIER_AUTHORITY_DEFINED
#घोषणा SID_IDENTIFIER_AUTHORITY_DEFINED
    प्रकार काष्ठा _SID_IDENTIFIER_AUTHORITY {
      BYTE मूल्य_3[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#पूर्ण_अगर

#अगर_अघोषित SID_DEFINED
#घोषणा SID_DEFINED
    प्रकार काष्ठा _SID {
      BYTE Revision;
      BYTE Sub_Authority_गिनती;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#पूर्ण_अगर

#घोषणा SID_REVISION (1)
#घोषणा SID_MAX_SUB_AUTHORITIES (15)
#घोषणा SID_RECOMMENDED_SUB_AUTHORITIES (1)

#घोषणा SECURITY_MAX_SID_आकार (माप(SID) - माप(DWORD) + (SID_MAX_SUB_AUTHORITIES *माप(DWORD)))

    प्रकार क्रमागत _SID_NAME_USE {
      SidTypeUser = 1,SidTypeGroup,SidTypeDomain,SidTypeAlias,SidTypeWellKnownGroup,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    प्रकार काष्ठा _SID_AND_ATTRIBUTES {
      PSID Sid;
      DWORD Attributes;
    } SID_AND_ATTRIBUTES,*PSID_AND_ATTRIBUTES;

    प्रकार SID_AND_ATTRIBUTES SID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
    प्रकार SID_AND_ATTRIBUTES_ARRAY *PSID_AND_ATTRIBUTES_ARRAY;

#घोषणा SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#घोषणा SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#घोषणा SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#घोषणा SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#घोषणा SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#घोषणा SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#घोषणा SECURITY_NULL_RID (0x00000000L)
#घोषणा SECURITY_WORLD_RID (0x00000000L)
#घोषणा SECURITY_LOCAL_RID (0x00000000L)

#घोषणा SECURITY_CREATOR_OWNER_RID (0x00000000L)
#घोषणा SECURITY_CREATOR_GROUP_RID (0x00000001L)

#घोषणा SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#घोषणा SECURITY_CREATOR_GROUP_SERVER_RID (0x00000003L)

#घोषणा SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#घोषणा SECURITY_DIALUP_RID (0x00000001L)
#घोषणा SECURITY_NETWORK_RID (0x00000002L)
#घोषणा SECURITY_BATCH_RID (0x00000003L)
#घोषणा SECURITY_INTERACTIVE_RID (0x00000004L)
#घोषणा SECURITY_LOGON_IDS_RID (0x00000005L)
#घोषणा SECURITY_LOGON_IDS_RID_गिनती (3L)
#घोषणा SECURITY_SERVICE_RID (0x00000006L)
#घोषणा SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#घोषणा SECURITY_PROXY_RID (0x00000008L)
#घोषणा SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#घोषणा SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#घोषणा SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#घोषणा SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#घोषणा SECURITY_RESTRICTED_CODE_RID (0x0000000CL)
#घोषणा SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#घोषणा SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#घोषणा SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#घोषणा SECURITY_IUSER_RID (0x00000011L)

#घोषणा SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#घोषणा SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#घोषणा SECURITY_NETWORK_SERVICE_RID (0x00000014L)

#घोषणा SECURITY_NT_NON_UNIQUE (0x00000015L)
#घोषणा SECURITY_NT_NON_UNIQUE_SUB_AUTH_गिनती (3L)

#घोषणा SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#घोषणा SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#घोषणा SECURITY_WRITE_RESTRICTED_CODE_RID (0x00000021L)

#घोषणा SECURITY_PACKAGE_BASE_RID (0x00000040L)
#घोषणा SECURITY_PACKAGE_RID_गिनती (2L)
#घोषणा SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#घोषणा SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#घोषणा SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#घोषणा SECURITY_SERVICE_ID_BASE_RID (0x00000050L)
#घोषणा SECURITY_SERVICE_ID_RID_गिनती (6L)

#घोषणा SECURITY_RESERVED_ID_BASE_RID (0x00000051L)

#घोषणा SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#घोषणा SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#घोषणा SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#घोषणा FOREST_USER_RID_MAX (0x000001F3L)

#घोषणा DOMAIN_USER_RID_ADMIN (0x000001F4L)
#घोषणा DOMAIN_USER_RID_GUEST (0x000001F5L)
#घोषणा DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#घोषणा DOMAIN_USER_RID_MAX (0x000003E7L)

#घोषणा DOMAIN_GROUP_RID_ADMINS (0x00000200L)
#घोषणा DOMAIN_GROUP_RID_USERS (0x00000201L)
#घोषणा DOMAIN_GROUP_RID_GUESTS (0x00000202L)
#घोषणा DOMAIN_GROUP_RID_COMPUTERS (0x00000203L)
#घोषणा DOMAIN_GROUP_RID_CONTROLLERS (0x00000204L)
#घोषणा DOMAIN_GROUP_RID_CERT_ADMINS (0x00000205L)
#घोषणा DOMAIN_GROUP_RID_SCHEMA_ADMINS (0x00000206L)
#घोषणा DOMAIN_GROUP_RID_ENTERPRISE_ADMINS (0x00000207L)
#घोषणा DOMAIN_GROUP_RID_POLICY_ADMINS (0x00000208L)
#घोषणा DOMAIN_GROUP_RID_READONLY_CONTROLLERS (0x00000209L)

#घोषणा DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#घोषणा DOMAIN_ALIAS_RID_USERS (0x00000221L)
#घोषणा DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#घोषणा DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#घोषणा DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#घोषणा DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#घोषणा DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#घोषणा DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#घोषणा DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#घोषणा DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#घोषणा DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#घोषणा DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#घोषणा DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS (0x0000022CL)
#घोषणा DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#घोषणा DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#घोषणा DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#घोषणा DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#घोषणा DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#घोषणा DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#घोषणा DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#घोषणा DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#घोषणा DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP (0x0000023BL)
#घोषणा DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP (0x0000023CL)
#घोषणा DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP (0x0000023DL)

#घोषणा SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#घोषणा SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#घोषणा SECURITY_MANDATORY_निचला_RID (0x00001000L)
#घोषणा SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#घोषणा SECURITY_MANDATORY_ऊपरी_RID (0x00003000L)
#घोषणा SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#घोषणा SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#घोषणा SECURITY_MANDATORY_MAXIMUM_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#घोषणा MANDATORY_LEVEL_TO_MANDATORY_RID(IL) (IL * 0x1000)

    प्रकार क्रमागत {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,WinCreatorGroupSid = 4,WinCreatorOwnerServerSid = 5,WinCreatorGroupServerSid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,WinNetworkSid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,WinRestrictedCodeSid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,WinNetworkServiceSid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,WinBuiltinNetworkConfigurationOperatorsSid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_KNOWN_SID_TYPE;

#घोषणा SYSTEM_LUID { 0x3E7,0x0 }
#घोषणा ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#घोषणा LOCALSERVICE_LUID { 0x3e5,0x0 }
#घोषणा NETWORKSERVICE_LUID { 0x3e4,0x0 }
#घोषणा IUSER_LUID { 0x3e3, 0x0 }

#घोषणा SE_GROUP_MANDATORY (0x00000001L)
#घोषणा SE_GROUP_ENABLED_BY_DEFAULT (0x00000002L)
#घोषणा SE_GROUP_ENABLED (0x00000004L)
#घोषणा SE_GROUP_OWNER (0x00000008L)
#घोषणा SE_GROUP_USE_FOR_DENY_ONLY (0x00000010L)
#घोषणा SE_GROUP_INTEGRITY (0x00000020L)
#घोषणा SE_GROUP_INTEGRITY_ENABLED (0x00000040L)
#घोषणा SE_GROUP_LOGON_ID (0xC0000000L)
#घोषणा SE_GROUP_RESOURCE (0x20000000L)

#घोषणा ACL_REVISION (2)
#घोषणा ACL_REVISION_DS (4)

#घोषणा ACL_REVISION1 (1)
#घोषणा MIN_ACL_REVISION ACL_REVISION2
#घोषणा ACL_REVISION2 (2)
#घोषणा ACL_REVISION3 (3)
#घोषणा ACL_REVISION4 (4)
#घोषणा MAX_ACL_REVISION ACL_REVISION4

    प्रकार काष्ठा _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      WORD Acl_आकार;
      WORD Ace_गिनती;
      WORD Sbz2;
    } ACL;
    प्रकार ACL *PACL;

    प्रकार काष्ठा _ACE_HEADER {
      BYTE AceType;
      BYTE AceFlags;
      WORD Ace_आकार;
    } ACE_HEADER;
    प्रकार ACE_HEADER *PACE_HEADER;

#घोषणा ACCESS_MIN_MS_ACE_TYPE (0x0)
#घोषणा ACCESS_ALLOWED_ACE_TYPE (0x0)
#घोषणा ACCESS_DENIED_ACE_TYPE (0x1)
#घोषणा SYSTEM_AUDIT_ACE_TYPE (0x2)
#घोषणा SYSTEM_ALARM_ACE_TYPE (0x3)
#घोषणा ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#घोषणा ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#घोषणा ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#घोषणा ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#घोषणा ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#घोषणा ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#घोषणा SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#घोषणा SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#घोषणा ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#घोषणा ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#घोषणा ACCESS_MAX_MS_ACE_TYPE (0x8)

#घोषणा ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#घोषणा ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#घोषणा ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#घोषणा ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#घोषणा SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#घोषणा SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#घोषणा SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#घोषणा SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#घोषणा SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#घोषणा ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#घोषणा OBJECT_INHERIT_ACE (0x1)
#घोषणा CONTAINER_INHERIT_ACE (0x2)
#घोषणा NO_PROPAGATE_INHERIT_ACE (0x4)
#घोषणा INHERIT_ONLY_ACE (0x8)
#घोषणा INHERITED_ACE (0x10)
#घोषणा VALID_INHERIT_FLAGS (0x1F)

#घोषणा SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#घोषणा FAILED_ACCESS_ACE_FLAG (0x80)

    प्रकार काष्ठा _ACCESS_ALLOWED_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;
    } ACCESS_ALLOWED_ACE;

    प्रकार ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    प्रकार काष्ठा _ACCESS_DENIED_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;
    } ACCESS_DENIED_ACE;
    प्रकार ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    प्रकार काष्ठा _SYSTEM_AUDIT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;
    } SYSTEM_AUDIT_ACE;
    प्रकार SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    प्रकार काष्ठा _SYSTEM_ALARM_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;
    } SYSTEM_ALARM_ACE;
    प्रकार SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    प्रकार काष्ठा _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    प्रकार काष्ठा _ACCESS_DENIED_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    प्रकार काष्ठा _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    प्रकार काष्ठा _SYSTEM_ALARM_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    प्रकार काष्ठा _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    प्रकार काष्ठा _ACCESS_DENIED_CALLBACK_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    प्रकार काष्ठा _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    प्रकार काष्ठा _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD SidStart;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    प्रकार काष्ठा _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    प्रकार काष्ठा _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    प्रकार काष्ठा _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    प्रकार काष्ठा _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_HEADER Header;
      ACCESS_MASK Mask;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#घोषणा ACE_OBJECT_TYPE_PRESENT 0x1
#घोषणा ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    प्रकार क्रमागत _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,Acl_आकार_Information
    } ACL_INFORMATION_CLASS;

    प्रकार काष्ठा _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    प्रकार ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    प्रकार काष्ठा ACL_आकार_INFORMATION {
      DWORD Ace_गिनती;
      DWORD AclBytesInUse;
      DWORD AclBytesFree;
    } ACL_आकार_INFORMATION_2;
    प्रकार ACL_आकार_INFORMATION_2 *PACL_आकार_INFORMATION;

#घोषणा SECURITY_DESCRIPTOR_REVISION (1)
#घोषणा SECURITY_DESCRIPTOR_REVISION1 (1)

#घोषणा SECURITY_DESCRIPTOR_MIN_लंबाई (माप(SECURITY_DESCRIPTOR))

    प्रकार WORD SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#घोषणा SE_OWNER_DEFAULTED (0x0001)
#घोषणा SE_GROUP_DEFAULTED (0x0002)
#घोषणा SE_DACL_PRESENT (0x0004)
#घोषणा SE_DACL_DEFAULTED (0x0008)
#घोषणा SE_SACL_PRESENT (0x0010)
#घोषणा SE_SACL_DEFAULTED (0x0020)
#घोषणा SE_DACL_AUTO_INHERIT_REQ (0x0100)
#घोषणा SE_SACL_AUTO_INHERIT_REQ (0x0200)
#घोषणा SE_DACL_AUTO_INHERITED (0x0400)
#घोषणा SE_SACL_AUTO_INHERITED (0x0800)
#घोषणा SE_DACL_PROTECTED (0x1000)
#घोषणा SE_SACL_PROTECTED (0x2000)
#घोषणा SE_RM_CONTROL_VALID (0x4000)
#घोषणा SE_SELF_RELATIVE (0x8000)

    प्रकार काष्ठा _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD Group;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    प्रकार काष्ठा _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID Group;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    प्रकार काष्ठा _OBJECT_TYPE_LIST {
      WORD Level;
      WORD Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#घोषणा ACCESS_OBJECT_GUID 0
#घोषणा ACCESS_PROPERTY_SET_GUID 1
#घोषणा ACCESS_PROPERTY_GUID 2

#घोषणा ACCESS_MAX_LEVEL 4

    प्रकार क्रमागत _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#घोषणा AUDIT_ALLOW_NO_PRIVILEGE 0x1

#घोषणा ACCESS_DS_SOURCE_A "DS"
#घोषणा ACCESS_DS_SOURCE_W L"DS"
#घोषणा ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#घोषणा ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#घोषणा SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#घोषणा SE_PRIVILEGE_ENABLED (0x00000002L)
#घोषणा SE_PRIVILEGE_REMOVED (0X00000004L)
#घोषणा SE_PRIVILEGE_USED_FOR_ACCESS (0x80000000L)

#घोषणा PRIVILEGE_SET_ALL_NECESSARY (1)

    प्रकार काष्ठा _PRIVILEGE_SET {
      DWORD Privilege_गिनती;
      DWORD Control;
      LUID_AND_ATTRIBUTES Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_SET,*PPRIVILEGE_SET;

#घोषणा SE_CREATE_TOKEN_NAME TEXT("SeCreateTokenPrivilege")
#घोषणा SE_ASSIGNPRIMARYTOKEN_NAME TEXT("SeAssignPrimaryTokenPrivilege")
#घोषणा SE_LOCK_MEMORY_NAME TEXT("SeLockMemoryPrivilege")
#घोषणा SE_INCREASE_QUOTA_NAME TEXT("SeIncreaseQuotaPrivilege")
#घोषणा SE_UNSOLICITED_निवेश_NAME TEXT("SeUnsolicitedInputPrivilege")
#घोषणा SE_MACHINE_ACCOUNT_NAME TEXT("SeMachineAccountPrivilege")
#घोषणा SE_TCB_NAME TEXT("SeTcbPrivilege")
#घोषणा SE_SECURITY_NAME TEXT("SeSecurityPrivilege")
#घोषणा SE_TAKE_OWNERSHIP_NAME TEXT("SeTakeOwnershipPrivilege")
#घोषणा SE_LOAD_DRIVER_NAME TEXT("SeLoadDriverPrivilege")
#घोषणा SE_SYSTEM_PROFILE_NAME TEXT("SeSystemProfilePrivilege")
#घोषणा SE_SYSTEMTIME_NAME TEXT("SeSystemtimePrivilege")
#घोषणा SE_PROF_SINGLE_PROCESS_NAME TEXT("SeProfileSingleProcessPrivilege")
#घोषणा SE_INC_BASE_PRIORITY_NAME TEXT("SeIncreaseBasePriorityPrivilege")
#घोषणा SE_CREATE_PAGEFILE_NAME TEXT("SeCreatePagefilePrivilege")
#घोषणा SE_CREATE_PERMANENT_NAME TEXT("SeCreatePermanentPrivilege")
#घोषणा SE_BACKUP_NAME TEXT("SeBackupPrivilege")
#घोषणा SE_RESTORE_NAME TEXT("SeRestorePrivilege")
#घोषणा SE_SHUTDOWN_NAME TEXT("SeShutdownPrivilege")
#घोषणा SE_DEBUG_NAME TEXT("SeDebugPrivilege")
#घोषणा SE_AUDIT_NAME TEXT("SeAuditPrivilege")
#घोषणा SE_SYSTEM_ENVIRONMENT_NAME TEXT("SeSystemEnvironmentPrivilege")
#घोषणा SE_CHANGE_NOTIFY_NAME TEXT("SeChangeNotifyPrivilege")
#घोषणा SE_REMOTE_SHUTDOWN_NAME TEXT("SeRemoteShutdownPrivilege")
#घोषणा SE_UNDOCK_NAME TEXT("SeUndockPrivilege")
#घोषणा SE_SYNC_AGENT_NAME TEXT("SeSyncAgentPrivilege")
#घोषणा SE_ENABLE_DELEGATION_NAME TEXT("SeEnableDelegationPrivilege")
#घोषणा SE_MANAGE_VOLUME_NAME TEXT("SeManageVolumePrivilege")
#घोषणा SE_IMPERSONATE_NAME TEXT("SeImpersonatePrivilege")
#घोषणा SE_CREATE_GLOBAL_NAME TEXT("SeCreateGlobalPrivilege")

    प्रकार क्रमागत _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#घोषणा SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#घोषणा SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#घोषणा DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#घोषणा VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#घोषणा TOKEN_ASSIGN_PRIMARY (0x0001)
#घोषणा TOKEN_DUPLICATE (0x0002)
#घोषणा TOKEN_IMPERSONATE (0x0004)
#घोषणा TOKEN_QUERY (0x0008)
#घोषणा TOKEN_QUERY_SOURCE (0x0010)
#घोषणा TOKEN_ADJUST_PRIVILEGES (0x0020)
#घोषणा TOKEN_ADJUST_GROUPS (0x0040)
#घोषणा TOKEN_ADJUST_DEFAULT (0x0080)
#घोषणा TOKEN_ADJUST_SESSIONID (0x0100)

#घोषणा TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_ASSIGN_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_SOURCE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#घोषणा TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#घोषणा TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#घोषणा TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#घोषणा TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    प्रकार क्रमागत _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    प्रकार TOKEN_TYPE *PTOKEN_TYPE;

    प्रकार क्रमागत _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,TokenPrimaryGroup,TokenDefaultDacl,TokenSource,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    प्रकार काष्ठा _TOKEN_USER {
      SID_AND_ATTRIBUTES User;
    } TOKEN_USER,*PTOKEN_USER;

    प्रकार काष्ठा _TOKEN_GROUPS {
      DWORD Group_गिनती;
      SID_AND_ATTRIBUTES Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    प्रकार काष्ठा _TOKEN_PRIVILEGES {
      DWORD Privilege_गिनती;
      LUID_AND_ATTRIBUTES Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    प्रकार काष्ठा _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    प्रकार काष्ठा _TOKEN_PRIMARY_GROUP {
      PSID PrimaryGroup;
    } TOKEN_PRIMARY_GROUP,*PTOKEN_PRIMARY_GROUP;

    प्रकार काष्ठा _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    प्रकार काष्ठा _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD Sid_गिनती;
      DWORD Sid_लंबाई;
      PSID_AND_ATTRIBUTES Sids;
      DWORD Restricted_Sid_गिनती;
      DWORD Restricted_Sid_लंबाई;
      PSID_AND_ATTRIBUTES RestrictedSids;
      DWORD Privilege_गिनती;
      DWORD Privilege_लंबाई;
      PLUID_AND_ATTRIBUTES Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#घोषणा TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#घोषणा TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#घोषणा TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#घोषणा TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#घोषणा VALID_AUDIT_POLICY_BITS (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#घोषणा VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).PolicyMask & ~VALID_AUDIT_POLICY_BITS)==0) && ((P).Category <= AuditEventMaxType))

    प्रकार काष्ठा _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD PolicyMask;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    प्रकार काष्ठा _TOKEN_AUDIT_POLICY {
      DWORD Policy_गिनती;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#घोषणा PER_USER_AUDITING_POLICY_आकार(p) (माप(TOKEN_AUDIT_POLICY) + (((p)->Policy_गिनती > ANYSIZE_ARRAY) ? (माप(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->Policy_गिनती - ANYSIZE_ARRAY)) : 0))
#घोषणा PER_USER_AUDITING_POLICY_आकार_BY_गिनती(C) (माप(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (माप(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#घोषणा TOKEN_SOURCE_लंबाई 8

    प्रकार काष्ठा _TOKEN_SOURCE {
      CHAR SourceName[TOKEN_SOURCE_लंबाई];
      LUID SourceIdentifier;
    } TOKEN_SOURCE,*PTOKEN_SOURCE;

    प्रकार काष्ठा _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER ExpirationTime;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD DynamicAvailable;
      DWORD Group_गिनती;
      DWORD Privilege_गिनती;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    प्रकार काष्ठा _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_SOURCE TokenSource;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    प्रकार काष्ठा _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#घोषणा SECURITY_DYNAMIC_TRACKING (TRUE)
#घोषणा SECURITY_STATIC_TRACKING (FALSE)

    प्रकार BOOLEAN SECURITY_CONTEXT_TRACKING_MODE,*PSECURITY_CONTEXT_TRACKING_MODE;

    प्रकार काष्ठा _SECURITY_QUALITY_OF_SERVICE {
      DWORD लंबाई_2;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_MODE ContextTrackingMode;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_OF_SERVICE,*PSECURITY_QUALITY_OF_SERVICE;

    प्रकार काष्ठा _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#घोषणा DISABLE_MAX_PRIVILEGE 0x1
#घोषणा SANDBOX_INERT 0x2

    प्रकार DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#घोषणा OWNER_SECURITY_INFORMATION (0x00000001L)
#घोषणा GROUP_SECURITY_INFORMATION (0x00000002L)
#घोषणा DACL_SECURITY_INFORMATION (0x00000004L)
#घोषणा SACL_SECURITY_INFORMATION (0x00000008L)

#घोषणा PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#घोषणा PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#घोषणा UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#घोषणा UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#घोषणा PROCESS_TERMINATE (0x0001)
#घोषणा PROCESS_CREATE_THREAD (0x0002)
#घोषणा PROCESS_SET_SESSIONID (0x0004)
#घोषणा PROCESS_VM_OPERATION (0x0008)
#घोषणा PROCESS_VM_READ (0x0010)
#घोषणा PROCESS_VM_WRITE (0x0020)
#घोषणा PROCESS_DUP_HANDLE (0x0040)
#घोषणा PROCESS_CREATE_PROCESS (0x0080)
#घोषणा PROCESS_SET_QUOTA (0x0100)
#घोषणा PROCESS_SET_INFORMATION (0x0200)
#घोषणा PROCESS_QUERY_INFORMATION (0x0400)
#घोषणा PROCESS_SUSPEND_RESUME (0x0800)
#घोषणा PROCESS_QUERY_LIMITED_INFORMATION (0x1000)
#घोषणा PROCESS_SET_LIMITED_INFORMATION (0x2000)
#घोषणा PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#अगर_घोषित _WIN64
#घोषणा MAXIMUM_PROCESSORS 64
#अन्यथा
#घोषणा MAXIMUM_PROCESSORS 32
#पूर्ण_अगर

#घोषणा THREAD_TERMINATE (0x0001)
#घोषणा THREAD_SUSPEND_RESUME (0x0002)
#घोषणा THREAD_GET_CONTEXT (0x0008)
#घोषणा THREAD_SET_CONTEXT (0x0010)
#घोषणा THREAD_SET_INFORMATION (0x0020)
#घोषणा THREAD_QUERY_INFORMATION (0x0040)
#घोषणा THREAD_SET_THREAD_TOKEN (0x0080)
#घोषणा THREAD_IMPERSONATE (0x0100)
#घोषणा THREAD_DIRECT_IMPERSONATION (0x0200)

#घोषणा THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#घोषणा JOB_OBJECT_ASSIGN_PROCESS (0x0001)
#घोषणा JOB_OBJECT_SET_ATTRIBUTES (0x0002)
#घोषणा JOB_OBJECT_QUERY (0x0004)
#घोषणा JOB_OBJECT_TERMINATE (0x0008)
#घोषणा JOB_OBJECT_SET_SECURITY_ATTRIBUTES (0x0010)
#घोषणा JOB_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    प्रकार काष्ठा _JOB_SET_ARRAY {
      HANDLE JobHandle;
      DWORD MemberLevel;
      DWORD Flags;
    } JOB_SET_ARRAY,*PJOB_SET_ARRAY;

#घोषणा FLS_MAXIMUM_AVAILABLE 128
#घोषणा TLS_MINIMUM_AVAILABLE 64

#अगर_अघोषित _NT_TIB_DEFINED
#घोषणा _NT_TIB_DEFINED
    प्रकार काष्ठा _NT_TIB {
      काष्ठा _EXCEPTION_REGISTRATION_RECORD *ExceptionList;
      PVOID ढेर_Base;
      PVOID ढेर_Limit;
      PVOID SubSystemTib;
      जोड़ {
	PVOID Fiber_तथ्य;
	DWORD Version;
      };
      PVOID ArbitraryUserPointer;
      काष्ठा _NT_TIB *Self;
    } NT_TIB;
    प्रकार NT_TIB *PNT_TIB;
#पूर्ण_अगर

    प्रकार काष्ठा _NT_TIB32 {
      DWORD ExceptionList;
      DWORD ढेर_Base;
      DWORD ढेर_Limit;
      DWORD SubSystemTib;
      जोड़ {
	DWORD Fiber_तथ्य;
	DWORD Version;
      };
      DWORD ArbitraryUserPointer;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    प्रकार काष्ठा _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 ढेर_Base;
      DWORD64 ढेर_Limit;
      DWORD64 SubSystemTib;
      जोड़ {
	DWORD64 Fiber_तथ्य;
	DWORD Version;
      };
      DWORD64 ArbitraryUserPointer;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#अगर !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_)
#घोषणा WX86
#पूर्ण_अगर

#घोषणा THREAD_BASE_PRIORITY_LOWRT 15
#घोषणा THREAD_BASE_PRIORITY_MAX 2
#घोषणा THREAD_BASE_PRIORITY_MIN (-2)
#घोषणा THREAD_BASE_PRIORITY_IDLE (-15)

    प्रकार काष्ठा _QUOTA_LIMITS {
      आकार_T PagedPoolLimit;
      आकार_T NonPagedPoolLimit;
      आकार_T Minimum_Working_Set_आकार;
      आकार_T Maximum_Working_Set_आकार;
      आकार_T PagefileLimit;
      LARGE_INTEGER TimeLimit;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#घोषणा QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#घोषणा QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#घोषणा QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#घोषणा QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    प्रकार काष्ठा _QUOTA_LIMITS_EX {
      आकार_T PagedPoolLimit;
      आकार_T NonPagedPoolLimit;
      आकार_T Minimum_Working_Set_आकार;
      आकार_T Maximum_Working_Set_आकार;
      आकार_T PagefileLimit;
      LARGE_INTEGER TimeLimit;
      आकार_T Reserved1;
      आकार_T Reserved2;
      आकार_T Reserved3;
      आकार_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    प्रकार काष्ठा _IO_COUNTERS {
      ULONGLONG Read_Operation_गिनती;
      ULONGLONG Write_Operation_गिनती;
      ULONGLONG Other_Operation_गिनती;
      ULONGLONG Read_Transfer_गिनती;
      ULONGLONG Write_Transfer_गिनती;
      ULONGLONG Other_Transfer_गिनती;
    } IO_COUNTERS;
    प्रकार IO_COUNTERS *PIO_COUNTERS;

    प्रकार काष्ठा _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER योग_User_Time;
      LARGE_INTEGER योग_Kernel_Time;
      LARGE_INTEGER This_Period_योग_User_Time;
      LARGE_INTEGER This_Period_योग_Kernel_Time;
      DWORD योग_Page_Fault_गिनती;
      DWORD योग_Processes;
      DWORD ActiveProcesses;
      DWORD योग_Terminated_Processes;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    प्रकार काष्ठा _JOBOBJECT_BASIC_LIMIT_INFORMATION {
      LARGE_INTEGER PerProcessUserTimeLimit;
      LARGE_INTEGER PerJobUserTimeLimit;
      DWORD LimitFlags;
      आकार_T Minimum_Working_Set_आकार;
      आकार_T Maximum_Working_Set_आकार;
      DWORD ActiveProcessLimit;
      ULONG_PTR Affinity;
      DWORD PriorityClass;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_LIMIT_INFORMATION,*PJOBOBJECT_BASIC_LIMIT_INFORMATION;

    प्रकार काष्ठा _JOBOBJECT_EXTENDED_LIMIT_INFORMATION {
      JOBOBJECT_BASIC_LIMIT_INFORMATION BasicLimitInformation;
      IO_COUNTERS IoInfo;
      आकार_T ProcessMemoryLimit;
      आकार_T JobMemoryLimit;
      आकार_T PeakProcessMemoryUsed;
      आकार_T PeakJobMemoryUsed;
    } JOBOBJECT_EXTENDED_LIMIT_INFORMATION,*PJOBOBJECT_EXTENDED_LIMIT_INFORMATION;

    प्रकार काष्ठा _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD संख्या_Of_Assigned_Processes;
      DWORD संख्या_Of_Process_Ids_In_List;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    प्रकार काष्ठा _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    प्रकार काष्ठा _JOBOBJECT_SECURITY_LIMIT_INFORMATION {
      DWORD SecurityLimitFlags;
      HANDLE JobToken;
      PTOKEN_GROUPS SidsToDisable;
      PTOKEN_PRIVILEGES PrivilegesToDelete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_LIMIT_INFORMATION,*PJOBOBJECT_SECURITY_LIMIT_INFORMATION;

    प्रकार काष्ठा _JOBOBJECT_END_OF_JOB_TIME_INFORMATION {
      DWORD EndOfJobTimeAction;
    } JOBOBJECT_END_OF_JOB_TIME_INFORMATION,*PJOBOBJECT_END_OF_JOB_TIME_INFORMATION;

    प्रकार काष्ठा _JOBOBJECT_ASSOCIATE_COMPLETION_PORT {
      PVOID Completion_कुंजी;
      HANDLE CompletionPort;
    } JOBOBJECT_ASSOCIATE_COMPLETION_PORT,*PJOBOBJECT_ASSOCIATE_COMPLETION_PORT;

    प्रकार काष्ठा _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    प्रकार काष्ठा _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#घोषणा JOB_OBJECT_TERMINATE_AT_END_OF_JOB 0
#घोषणा JOB_OBJECT_POST_AT_END_OF_JOB 1

#घोषणा JOB_OBJECT_संदेश_END_OF_JOB_TIME 1
#घोषणा JOB_OBJECT_संदेश_END_OF_PROCESS_TIME 2
#घोषणा JOB_OBJECT_संदेश_ACTIVE_PROCESS_LIMIT 3
#घोषणा JOB_OBJECT_संदेश_ACTIVE_PROCESS_ZERO 4
#घोषणा JOB_OBJECT_संदेश_NEW_PROCESS 6
#घोषणा JOB_OBJECT_संदेश_EXIT_PROCESS 7
#घोषणा JOB_OBJECT_संदेश_ABNORMAL_EXIT_PROCESS 8
#घोषणा JOB_OBJECT_संदेश_PROCESS_MEMORY_LIMIT 9
#घोषणा JOB_OBJECT_संदेश_JOB_MEMORY_LIMIT 10

#घोषणा JOB_OBJECT_LIMIT_WORKINGSET 0x00000001
#घोषणा JOB_OBJECT_LIMIT_PROCESS_TIME 0x00000002
#घोषणा JOB_OBJECT_LIMIT_JOB_TIME 0x00000004
#घोषणा JOB_OBJECT_LIMIT_ACTIVE_PROCESS 0x00000008
#घोषणा JOB_OBJECT_LIMIT_AFFINITY 0x00000010
#घोषणा JOB_OBJECT_LIMIT_PRIORITY_CLASS 0x00000020
#घोषणा JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME 0x00000040
#घोषणा JOB_OBJECT_LIMIT_SCHEDULING_CLASS 0x00000080

#घोषणा JOB_OBJECT_LIMIT_PROCESS_MEMORY 0x00000100
#घोषणा JOB_OBJECT_LIMIT_JOB_MEMORY 0x00000200
#घोषणा JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#घोषणा JOB_OBJECT_LIMIT_BREAKAWAY_OK 0x00000800
#घोषणा JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK 0x00001000
#घोषणा JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE 0x00002000

#घोषणा JOB_OBJECT_LIMIT_RESERVED2 0x00004000
#घोषणा JOB_OBJECT_LIMIT_RESERVED3 0x00008000
#घोषणा JOB_OBJECT_LIMIT_RESERVED4 0x00010000
#घोषणा JOB_OBJECT_LIMIT_RESERVED5 0x00020000
#घोषणा JOB_OBJECT_LIMIT_RESERVED6 0x00040000

#घोषणा JOB_OBJECT_LIMIT_VALID_FLAGS 0x0007ffff

#घोषणा JOB_OBJECT_BASIC_LIMIT_VALID_FLAGS 0x000000ff
#घोषणा JOB_OBJECT_EXTENDED_LIMIT_VALID_FLAGS 0x00003fff
#घोषणा JOB_OBJECT_RESERVED_LIMIT_VALID_FLAGS 0x0007ffff

#घोषणा JOB_OBJECT_UILIMIT_NONE 0x00000000

#घोषणा JOB_OBJECT_UILIMIT_HANDLES 0x00000001
#घोषणा JOB_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#घोषणा JOB_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#घोषणा JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#घोषणा JOB_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#घोषणा JOB_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#घोषणा JOB_OBJECT_UILIMIT_DESKTOP 0x00000040
#घोषणा JOB_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#घोषणा JOB_OBJECT_UILIMIT_ALL 0x000000FF

#घोषणा JOB_OBJECT_UI_VALID_FLAGS 0x000000FF

#घोषणा JOB_OBJECT_SECURITY_NO_ADMIN 0x00000001
#घोषणा JOB_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#घोषणा JOB_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#घोषणा JOB_OBJECT_SECURITY_FILTER_TOKENS 0x00000008

#घोषणा JOB_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    प्रकार क्रमागत _JOBOBJECTINFOCLASS {
      JobObjectBasicAccountingInformation = 1,JobObjectBasicLimitInformation,JobObjectBasicProcessIdList,JobObjectBasicUIRestrictions,
      JobObjectSecurityLimitInformation,JobObjectEndOfJobTimeInformation,JobObjectAssociateCompletionPortInformation,
      JobObjectBasicAndIoAccountingInformation,JobObjectExtendedLimitInformation,JobObjectJobSetInformation,MaxJobObjectInfoClass
    } JOBOBJECTINFOCLASS;

#घोषणा EVENT_MODIFY_STATE 0x0002
#घोषणा EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#घोषणा MUTANT_QUERY_STATE 0x0001

#घोषणा MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#घोषणा SEMAPHORE_MODIFY_STATE 0x0002
#घोषणा SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#घोषणा TIMER_QUERY_STATE 0x0001
#घोषणा TIMER_MODIFY_STATE 0x0002

#घोषणा TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#घोषणा TIME_ZONE_ID_UNKNOWN 0
#घोषणा TIME_ZONE_ID_STANDARD 1
#घोषणा TIME_ZONE_ID_DAYLIGHT 2

    प्रकार क्रमागत _LOGICAL_PROCESSOR_RELATIONSHIP {
      RelationProcessorCore,Relation_Numa_गाँठ,RelationCache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#घोषणा LTP_PC_SMT 0x1

    प्रकार क्रमागत _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,Cache_तथ्य,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#घोषणा CACHE_FULLY_ASSOCIATIVE 0xFF

    प्रकार काष्ठा _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      WORD पंक्ति_आकार_2;
      DWORD आकार_3;
      PROCESSOR_CACHE_TYPE Type;
    } CACHE_DESCRIPTOR,*PCACHE_DESCRIPTOR;

    प्रकार काष्ठा _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
      ULONG_PTR ProcessorMask;
      LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
      जोड़ {
	काष्ठा {
	  BYTE Flags;
	} ProcessorCore;
	काष्ठा {
	  DWORD गाँठ_संख्या;
	} Numa_गाँठ;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#घोषणा PROCESSOR_INTEL_386 386
#घोषणा PROCESSOR_INTEL_486 486
#घोषणा PROCESSOR_INTEL_PENTIUM 586
#घोषणा PROCESSOR_INTEL_IA64 2200
#घोषणा PROCESSOR_AMD_X8664 8664
#घोषणा PROCESSOR_MIPS_R4000 4000
#घोषणा PROCESSOR_ALPHA_21064 21064
#घोषणा PROCESSOR_PPC_601 601
#घोषणा PROCESSOR_PPC_603 603
#घोषणा PROCESSOR_PPC_604 604
#घोषणा PROCESSOR_PPC_620 620
#घोषणा PROCESSOR_HITACHI_SH3 10003
#घोषणा PROCESSOR_HITACHI_SH3E 10004
#घोषणा PROCESSOR_HITACHI_SH4 10005
#घोषणा PROCESSOR_MOTOROLA_821 821
#घोषणा PROCESSOR_SHx_SH3 103
#घोषणा PROCESSOR_SHx_SH4 104
#घोषणा PROCESSOR_STRONGARM 2577
#घोषणा PROCESSOR_ARM720 1824
#घोषणा PROCESSOR_ARM820 2080
#घोषणा PROCESSOR_ARM920 2336
#घोषणा PROCESSOR_ARM_7TDMI 70001
#घोषणा PROCESSOR_OPTIL 0x494f

#घोषणा PROCESSOR_ARCHITECTURE_INTEL 0
#घोषणा PROCESSOR_ARCHITECTURE_MIPS 1
#घोषणा PROCESSOR_ARCHITECTURE_ALPHA 2
#घोषणा PROCESSOR_ARCHITECTURE_PPC 3
#घोषणा PROCESSOR_ARCHITECTURE_SHX 4
#घोषणा PROCESSOR_ARCHITECTURE_ARM 5
#घोषणा PROCESSOR_ARCHITECTURE_IA64 6
#घोषणा PROCESSOR_ARCHITECTURE_ALPHA64 7
#घोषणा PROCESSOR_ARCHITECTURE_MSIL 8
#घोषणा PROCESSOR_ARCHITECTURE_AMD64 9
#घोषणा PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#घोषणा PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#घोषणा PF_FLOATING_POINT_PRECISION_ERRATA 0
#घोषणा PF_FLOATING_POINT_EMULATED 1
#घोषणा PF_COMPARE_EXCHANGE_DOUBLE 2
#घोषणा PF_MMX_INSTRUCTIONS_AVAILABLE 3
#घोषणा PF_PPC_MOVEMEM_64BIT_OK 4
#घोषणा PF_ALPHA_BYTE_INSTRUCTIONS 5
#घोषणा PF_XMMI_INSTRUCTIONS_AVAILABLE 6
#घोषणा PF_3DNOW_INSTRUCTIONS_AVAILABLE 7
#घोषणा PF_RDTSC_INSTRUCTION_AVAILABLE 8
#घोषणा PF_PAE_ENABLED 9
#घोषणा PF_XMMI64_INSTRUCTIONS_AVAILABLE 10
#घोषणा PF_SSE_DAZ_MODE_AVAILABLE 11
#घोषणा PF_NX_ENABLED 12

    प्रकार काष्ठा _MEMORY_BASIC_INFORMATION {
      PVOID BaseAddress;
      PVOID AllocationBase;
      DWORD AllocationProtect;
      आकार_T Region_आकार;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } MEMORY_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    प्रकार काष्ठा _MEMORY_BASIC_INFORMATION32 {
      DWORD BaseAddress;
      DWORD AllocationBase;
      DWORD AllocationProtect;
      DWORD Region_आकार;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } MEMORY_BASIC_INFORMATION32,*PMEMORY_BASIC_INFORMATION32;

    प्रकार काष्ठा DECLSPEC_ALIGN(16) _MEMORY_BASIC_INFORMATION64 {
      ULONGLONG BaseAddress;
      ULONGLONG AllocationBase;
      DWORD AllocationProtect;
      DWORD __alignment1;
      ULONGLONG Region_आकार;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } MEMORY_BASIC_INFORMATION64,*PMEMORY_BASIC_INFORMATION64;

#घोषणा SECTION_QUERY 0x0001
#घोषणा SECTION_MAP_WRITE 0x0002
#घोषणा SECTION_MAP_READ 0x0004
#घोषणा SECTION_MAP_EXECUTE 0x0008
#घोषणा SECTION_EXTEND_आकार 0x0010
#घोषणा SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#घोषणा SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_आकार)
#घोषणा PAGE_NOACCESS 0x01
#घोषणा PAGE_READONLY 0x02
#घोषणा PAGE_READWRITE 0x04
#घोषणा PAGE_WRITECOPY 0x08
#घोषणा PAGE_EXECUTE 0x10
#घोषणा PAGE_EXECUTE_READ 0x20
#घोषणा PAGE_EXECUTE_READWRITE 0x40
#घोषणा PAGE_EXECUTE_WRITECOPY 0x80
#घोषणा PAGE_GUARD 0x100
#घोषणा PAGE_NOCACHE 0x200
#घोषणा PAGE_WRITECOMBINE 0x400
#घोषणा MEM_COMMIT 0x1000
#घोषणा MEM_RESERVE 0x2000
#घोषणा MEM_DECOMMIT 0x4000
#घोषणा MEM_RELEASE 0x8000
#घोषणा MEM_FREE 0x10000
#घोषणा MEM_PRIVATE 0x20000
#घोषणा MEM_MAPPED 0x40000
#घोषणा MEM_RESET 0x80000
#घोषणा MEM_शीर्ष_DOWN 0x100000
#घोषणा MEM_WRITE_WATCH 0x200000
#घोषणा MEM_PHYSICAL 0x400000
#घोषणा MEM_LARGE_PAGES 0x20000000
#घोषणा MEM_4MB_PAGES 0x80000000
#घोषणा SEC_FILE 0x800000
#घोषणा SEC_IMAGE 0x1000000
#घोषणा SEC_RESERVE 0x4000000
#घोषणा SEC_COMMIT 0x8000000
#घोषणा SEC_NOCACHE 0x10000000
#घोषणा SEC_LARGE_PAGES 0x80000000
#घोषणा MEM_IMAGE SEC_IMAGE
#घोषणा WRITE_WATCH_FLAG_RESET 0x01

#घोषणा FILE_READ_तथ्य (0x0001)
#घोषणा FILE_LIST_DIRECTORY (0x0001)

#घोषणा FILE_WRITE_तथ्य (0x0002)
#घोषणा FILE_ADD_FILE (0x0002)

#घोषणा FILE_APPEND_तथ्य (0x0004)
#घोषणा FILE_ADD_SUBDIRECTORY (0x0004)
#घोषणा FILE_CREATE_PIPE_INSTANCE (0x0004)

#घोषणा FILE_READ_EA (0x0008)

#घोषणा FILE_WRITE_EA (0x0010)

#घोषणा FILE_EXECUTE (0x0020)
#घोषणा FILE_TRAVERSE (0x0020)

#घोषणा FILE_DELETE_CHILD (0x0040)

#घोषणा FILE_READ_ATTRIBUTES (0x0080)

#घोषणा FILE_WRITE_ATTRIBUTES (0x0100)

#घोषणा FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#घोषणा FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_तथ्य | FILE_READ_ATTRIBUTES | FILE_READ_EA | SYNCHRONIZE)
#घोषणा FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_तथ्य | FILE_WRITE_ATTRIBUTES | FILE_WRITE_EA | FILE_APPEND_तथ्य | SYNCHRONIZE)
#घोषणा FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_ATTRIBUTES | FILE_EXECUTE | SYNCHRONIZE)

#घोषणा FILE_SHARE_READ 0x00000001
#घोषणा FILE_SHARE_WRITE 0x00000002
#घोषणा FILE_SHARE_DELETE 0x00000004
#घोषणा FILE_ATTRIBUTE_READONLY 0x00000001
#घोषणा FILE_ATTRIBUTE_HIDDEN 0x00000002
#घोषणा FILE_ATTRIBUTE_SYSTEM 0x00000004
#घोषणा FILE_ATTRIBUTE_DIRECTORY 0x00000010
#घोषणा FILE_ATTRIBUTE_ARCHIVE 0x00000020
#घोषणा FILE_ATTRIBUTE_DEVICE 0x00000040
#घोषणा FILE_ATTRIBUTE_NORMAL 0x00000080
#घोषणा FILE_ATTRIBUTE_TEMPORARY 0x00000100
#घोषणा FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#घोषणा FILE_ATTRIBUTE_REPARSE_POINT 0x00000400
#घोषणा FILE_ATTRIBUTE_COMPRESSED 0x00000800
#घोषणा FILE_ATTRIBUTE_OFFLINE 0x00001000
#घोषणा FILE_ATTRIBUTE_NOT_CONTENT_INDEXED 0x00002000
#घोषणा FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#घोषणा FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#घोषणा FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#घोषणा FILE_NOTIFY_CHANGE_ATTRIBUTES 0x00000004
#घोषणा FILE_NOTIFY_CHANGE_आकार 0x00000008
#घोषणा FILE_NOTIFY_CHANGE_LAST_WRITE 0x00000010
#घोषणा FILE_NOTIFY_CHANGE_LAST_ACCESS 0x00000020
#घोषणा FILE_NOTIFY_CHANGE_CREATION 0x00000040
#घोषणा FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#घोषणा FILE_ACTION_ADDED 0x00000001
#घोषणा FILE_ACTION_REMOVED 0x00000002
#घोषणा FILE_ACTION_MODIFIED 0x00000003
#घोषणा FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#घोषणा FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#घोषणा MAILSLOT_NO_MESSAGE ((DWORD)-1)
#घोषणा MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#घोषणा FILE_CASE_SENSITIVE_खोज 0x00000001
#घोषणा FILE_CASE_PRESERVED_NAMES 0x00000002
#घोषणा FILE_UNICODE_ON_DISK 0x00000004
#घोषणा FILE_PERSISTENT_ACLS 0x00000008
#घोषणा FILE_FILE_COMPRESSION 0x00000010
#घोषणा FILE_VOLUME_QUOTAS 0x00000020
#घोषणा FILE_SUPPORTS_SPARSE_FILES 0x00000040
#घोषणा FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#घोषणा FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#घोषणा FILE_VOLUME_IS_COMPRESSED 0x00008000
#घोषणा FILE_SUPPORTS_OBJECT_IDS 0x00010000
#घोषणा FILE_SUPPORTS_ENCRYPTION 0x00020000
#घोषणा FILE_NAMED_STREAMS 0x00040000
#घोषणा FILE_READ_ONLY_VOLUME 0x00080000

    प्रकार काष्ठा _FILE_NOTIFY_INFORMATION {
      DWORD अग्र_Entry_Offset;
      DWORD Action;
      DWORD File_Name_लंबाई;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    प्रकार जोड़ _FILE_SEGMENT_ELEMENT {
      PVOID64 बफर_3;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    प्रकार काष्ठा REPARSE_GUID_तथ्य_बफर {
      DWORD ReparseTag;
      WORD Reparse_तथ्य_लंबाई;
      WORD Reserved;
      GUID ReparseGuid;
      काष्ठा {
	BYTE तथ्य_बफर[1];
      } Generic_Reparse_बफर;
    } REPARSE_GUID_तथ्य_बफर_2,*PREPARSE_GUID_तथ्य_बफर;

#घोषणा REPARSE_GUID_तथ्य_बफर_HEADER_आकार FIELD_OFFSET(REPARSE_GUID_तथ्य_बफर_2,Generic_Reparse_बफर)

#घोषणा MAXIMUM_REPARSE_तथ्य_बफर_आकार (16 *1024)

#घोषणा IO_REPARSE_TAG_RESERVED_ZERO (0)
#घोषणा IO_REPARSE_TAG_RESERVED_ONE (1)

#घोषणा IO_REPARSE_TAG_RESERVED_RANGE IO_REPARSE_TAG_RESERVED_ONE

#घोषणा IsReparseTagMicrosoft(_tag) (((_tag) & 0x80000000))
#घोषणा IsReparseTagNameSurrogate(_tag) (((_tag) & 0x20000000))

#घोषणा IO_REPARSE_TAG_MOUNT_POINT (0xA0000003L)
#घोषणा IO_REPARSE_TAG_HSM (0xC0000004L)
#घोषणा IO_REPARSE_TAG_SIS (0x80000007L)
#घोषणा IO_REPARSE_TAG_DFS (0x8000000AL)
#घोषणा IO_REPARSE_TAG_FILTER_MANAGER (0x8000000BL)
#घोषणा IO_COMPLETION_MODIFY_STATE 0x0002
#घोषणा IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#घोषणा DUPLICATE_CLOSE_SOURCE 0x00000001
#घोषणा DUPLICATE_SAME_ACCESS 0x00000002

    प्रकार क्रमागत _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,PowerSystemMaximum = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#घोषणा POWER_SYSTEM_MAXIMUM 7

    प्रकार क्रमागत {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    प्रकार क्रमागत _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,PowerDeviceMaximum
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#घोषणा ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#घोषणा ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#घोषणा ES_USER_PRESENT ((DWORD)0x00000004)
#घोषणा ES_CONTINUOUS ((DWORD)0x80000000)

    प्रकार DWORD EXECUTION_STATE;

    प्रकार क्रमागत {
      LT_DONT_CARE,LT_LOWEST_LATENCY
    } LATENCY_TIME;

#घोषणा PDCAP_D0_SUPPORTED 0x00000001
#घोषणा PDCAP_D1_SUPPORTED 0x00000002
#घोषणा PDCAP_D2_SUPPORTED 0x00000004
#घोषणा PDCAP_D3_SUPPORTED 0x00000008
#घोषणा PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#घोषणा PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#घोषणा PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#घोषणा PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#घोषणा PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    प्रकार काष्ठा CM_Power_तथ्य_s {
      DWORD PD_आकार;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_MAXIMUM];
      SYSTEM_POWER_STATE PD_DeepestSystemWake;
    } CM_POWER_तथ्य,*PCM_POWER_तथ्य;

    प्रकार क्रमागत {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,LastWakeTime,LastSleepTime,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,SystemPowerLoggingEntry
    } POWER_INFORMATION_LEVEL;

    प्रकार काष्ठा {
      DWORD Granularity;
      DWORD Capacity;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    प्रकार काष्ठा {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD EventCode;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#घोषणा POWER_ACTION_QUERY_ALLOWED 0x00000001
#घोषणा POWER_ACTION_UI_ALLOWED 0x00000002
#घोषणा POWER_ACTION_OVERRIDE_APPS 0x00000004
#घोषणा POWER_ACTION_LIGHTEST_FIRST 0x10000000
#घोषणा POWER_ACTION_LOCK_CONSOLE 0x20000000
#घोषणा POWER_ACTION_DISABLE_WAKES 0x40000000
#घोषणा POWER_ACTION_CRITICAL 0x80000000

#घोषणा POWER_LEVEL_USER_NOTIFY_TEXT 0x00000001
#घोषणा POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#घोषणा POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#घोषणा POWER_USER_NOTIFY_BUTTON 0x00000008
#घोषणा POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#घोषणा POWER_FORCE_TRIGGER_RESET 0x80000000

    प्रकार काष्ठा {
      BOOLEAN Enable;
      BYTE Spare[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#घोषणा अंक_DISCHARGE_POLICIES 4
#घोषणा DISCHARGE_POLICY_CRITICAL 0
#घोषणा DISCHARGE_POLICY_निचला 1

#घोषणा PO_THROTTLE_NONE 0
#घोषणा PO_THROTTLE_CONSTANT 1
#घोषणा PO_THROTTLE_DEGRADE 2
#घोषणा PO_THROTTLE_ADAPTIVE 3
#घोषणा PO_THROTTLE_MAXIMUM 4

    प्रकार काष्ठा _SYSTEM_POWER_POLICY {
      DWORD Revision;
      POWER_ACTION_POLICY PowerButton;
      POWER_ACTION_POLICY SleepButton;
      POWER_ACTION_POLICY LidClose;
      SYSTEM_POWER_STATE LidOpenWake;
      DWORD Reserved;
      POWER_ACTION_POLICY Idle;
      DWORD IdleTimeout;
      BYTE IdleSensitivity;
      BYTE DynamicThrottle;
      BYTE Spare2[2];
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      SYSTEM_POWER_STATE ReducedLatencySleep;
      DWORD WinLogonFlags;
      DWORD Spare3;
      DWORD DozeS4Timeout;
      DWORD BroadcastCapacityResolution;
      SYSTEM_POWER_LEVEL DischargePolicy[अंक_DISCHARGE_POLICIES];
      DWORD VideoTimeout;
      BOOLEAN VideoDimDisplay;
      DWORD VideoReserved[3];
      DWORD SpindownTimeout;
      BOOLEAN OptimizeForPower;
      BYTE FanThrottleTolerance;
      BYTE ForcedThrottle;
      BYTE MinThrottle;
      POWER_ACTION_POLICY OverThrottled;
    } SYSTEM_POWER_POLICY,*PSYSTEM_POWER_POLICY;

    प्रकार काष्ठा _PROCESSOR_POWER_POLICY_INFO {
      DWORD TimeCheck;
      DWORD DemoteLimit;
      DWORD PromoteLimit;
      BYTE DemotePercent;
      BYTE PromotePercent;
      BYTE Spare[2];
      DWORD AllowDemotion:1;
      DWORD AllowPromotion:1;
      DWORD Reserved:30;
    } PROCESSOR_POWER_POLICY_INFO,*PPROCESSOR_POWER_POLICY_INFO;

    प्रकार काष्ठा _PROCESSOR_POWER_POLICY {
      DWORD Revision;
      BYTE DynamicThrottle;
      BYTE Spare[3];
      DWORD DisableCStates:1;
      DWORD Reserved:31;
      DWORD Policy_गिनती;
      PROCESSOR_POWER_POLICY_INFO Policy[3];
    } PROCESSOR_POWER_POLICY,*PPROCESSOR_POWER_POLICY;

    प्रकार काष्ठा _ADMINISTRATOR_POWER_POLICY {
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      DWORD MinVideoTimeout;
      DWORD MaxVideoTimeout;
      DWORD MinSpindownTimeout;
      DWORD MaxSpindownTimeout;
    } ADMINISTRATOR_POWER_POLICY,*PADMINISTRATOR_POWER_POLICY;

    प्रकार काष्ठा {
      BOOLEAN PowerButtonPresent;
      BOOLEAN SleepButtonPresent;
      BOOLEAN LidPresent;
      BOOLEAN SystemS1;
      BOOLEAN SystemS2;
      BOOLEAN SystemS3;
      BOOLEAN SystemS4;
      BOOLEAN SystemS5;
      BOOLEAN HiberFilePresent;
      BOOLEAN FullWake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN DiskSpinDown;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN BatteriesAreShortTerm;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE Ac_On_पंक्ति_Wake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE Default_निचला_Latency_Wake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    प्रकार काष्ठा {
      BOOLEAN Ac_On_पंक्ति;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD MaxCapacity;
      DWORD RemainingCapacity;
      DWORD Rate;
      DWORD EstimatedTime;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#समावेश "pshpack4.h"

#घोषणा IMAGE_DOS_SIGNATURE 0x5A4D
#घोषणा IMAGE_OS2_SIGNATURE 0x454E
#घोषणा IMAGE_OS2_SIGNATURE_LE 0x454C
#घोषणा IMAGE_VXD_SIGNATURE 0x454C
#घोषणा IMAGE_NT_SIGNATURE 0x00004550

#समावेश "pshpack2.h"

    प्रकार काष्ठा _IMAGE_DOS_HEADER {
      WORD e_magic;
      WORD e_cblp;
      WORD e_cp;
      WORD e_crlc;
      WORD e_cparhdr;
      WORD e_minalloc;
      WORD e_maxalloc;
      WORD e_ss;
      WORD e_sp;
      WORD e_csum;
      WORD e_ip;
      WORD e_cs;
      WORD e_lfarlc;
      WORD e_ovno;
      WORD e_res[4];
      WORD e_oemid;
      WORD e_oeminfo;
      WORD e_res2[10];
      LONG e_lfanew;
    } IMAGE_DOS_HEADER,*PIMAGE_DOS_HEADER;

    प्रकार काष्ठा _IMAGE_OS2_HEADER {
      WORD ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      WORD ne_enttab;
      WORD ne_cbenttab;
      LONG ne_crc;
      WORD ne_flags;
      WORD ne_autodata;
      WORD ne_heap;
      WORD ne_ढेर;
      LONG ne_csip;
      LONG ne_sssp;
      WORD ne_cseg;
      WORD ne_cmod;
      WORD ne_cbnrestab;
      WORD ne_segtab;
      WORD ne_rsrctab;
      WORD ne_restab;
      WORD ne_modtab;
      WORD ne_imptab;
      LONG ne_nrestab;
      WORD ne_cmovent;
      WORD ne_align;
      WORD ne_cres;
      BYTE ne_exetyp;
      BYTE ne_flagsothers;
      WORD ne_pretthunks;
      WORD ne_psegrefbytes;
      WORD ne_swaparea;
      WORD ne_expver;
    } IMAGE_OS2_HEADER,*PIMAGE_OS2_HEADER;

    प्रकार काष्ठा _IMAGE_VXD_HEADER {
      WORD e32_magic;
      BYTE e32_border;
      BYTE e32_worder;
      DWORD e32_level;
      WORD e32_cpu;
      WORD e32_os;
      DWORD e32_ver;
      DWORD e32_mflags;
      DWORD e32_mpages;
      DWORD e32_startobj;
      DWORD e32_eip;
      DWORD e32_stackobj;
      DWORD e32_esp;
      DWORD e32_pagesize;
      DWORD e32_lastpagesize;
      DWORD e32_fixupsize;
      DWORD e32_fixupsum;
      DWORD e32_ldrsize;
      DWORD e32_ldrsum;
      DWORD e32_objtab;
      DWORD e32_objcnt;
      DWORD e32_objmap;
      DWORD e32_itermap;
      DWORD e32_rsrctab;
      DWORD e32_rsrccnt;
      DWORD e32_restab;
      DWORD e32_enttab;
      DWORD e32_dirtab;
      DWORD e32_dircnt;
      DWORD e32_fpagetab;
      DWORD e32_frectab;
      DWORD e32_impmod;
      DWORD e32_impmodcnt;
      DWORD e32_impproc;
      DWORD e32_pagesum;
      DWORD e32_datapage;
      DWORD e32_preload;
      DWORD e32_nrestab;
      DWORD e32_cbnrestab;
      DWORD e32_nressum;
      DWORD e32_autodata;
      DWORD e32_debuginfo;
      DWORD e32_debuglen;
      DWORD e32_instpreload;
      DWORD e32_instdemand;
      DWORD e32_heapsize;
      BYTE e32_res3[12];
      DWORD e32_winresoff;
      DWORD e32_winreslen;
      WORD e32_devid;
      WORD e32_ddkver;
    } IMAGE_VXD_HEADER,*PIMAGE_VXD_HEADER;

#समावेश "poppack.h"

    प्रकार काष्ठा _IMAGE_FILE_HEADER {
      WORD Machine;
      WORD संख्या_Of_Sections;
      DWORD TimeDateStamp;
      DWORD Pointer_To_प्रतीक_Table;
      DWORD संख्या_Of_Symbols;
      WORD आकार_Of_Optional_Header;
      WORD Characteristics;
    } IMAGE_FILE_HEADER,*PIMAGE_FILE_HEADER;

#घोषणा IMAGE_SIZEOF_FILE_HEADER 20

#घोषणा IMAGE_FILE_RELOCS_STRIPPED 0x0001
#घोषणा IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#घोषणा IMAGE_FILE_पंक्ति_NUMS_STRIPPED 0x0004
#घोषणा IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#घोषणा IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#घोषणा IMAGE_FILE_LARGE_ADDRESS_AWARE 0x0020
#घोषणा IMAGE_FILE_BYTES_REVERSED_LO 0x0080
#घोषणा IMAGE_FILE_32BIT_MACHINE 0x0100
#घोषणा IMAGE_FILE_DEBUG_STRIPPED 0x0200
#घोषणा IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP 0x0400
#घोषणा IMAGE_FILE_NET_RUN_FROM_SWAP 0x0800
#घोषणा IMAGE_FILE_SYSTEM 0x1000
#घोषणा IMAGE_FILE_DLL 0x2000
#घोषणा IMAGE_FILE_UP_SYSTEM_ONLY 0x4000
#घोषणा IMAGE_FILE_BYTES_REVERSED_HI 0x8000

#घोषणा IMAGE_FILE_MACHINE_UNKNOWN 0
#घोषणा IMAGE_FILE_MACHINE_I386 0x014c
#घोषणा IMAGE_FILE_MACHINE_R3000 0x0162
#घोषणा IMAGE_FILE_MACHINE_R4000 0x0166
#घोषणा IMAGE_FILE_MACHINE_R10000 0x0168
#घोषणा IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#घोषणा IMAGE_FILE_MACHINE_ALPHA 0x0184
#घोषणा IMAGE_FILE_MACHINE_SH3 0x01a2
#घोषणा IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#घोषणा IMAGE_FILE_MACHINE_SH3E 0x01a4
#घोषणा IMAGE_FILE_MACHINE_SH4 0x01a6
#घोषणा IMAGE_FILE_MACHINE_SH5 0x01a8
#घोषणा IMAGE_FILE_MACHINE_ARM 0x01c0
#घोषणा IMAGE_FILE_MACHINE_THUMB 0x01c2
#घोषणा IMAGE_FILE_MACHINE_AM33 0x01d3
#घोषणा IMAGE_FILE_MACHINE_POWERPC 0x01F0
#घोषणा IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#घोषणा IMAGE_FILE_MACHINE_IA64 0x0200
#घोषणा IMAGE_FILE_MACHINE_MIPS16 0x0266
#घोषणा IMAGE_FILE_MACHINE_ALPHA64 0x0284
#घोषणा IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#घोषणा IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#घोषणा IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#घोषणा IMAGE_FILE_MACHINE_TRICORE 0x0520
#घोषणा IMAGE_FILE_MACHINE_CEF 0x0CEF
#घोषणा IMAGE_FILE_MACHINE_EBC 0x0EBC
#घोषणा IMAGE_FILE_MACHINE_AMD64 0x8664
#घोषणा IMAGE_FILE_MACHINE_ARM64 0xAA64
#घोषणा IMAGE_FILE_MACHINE_M32R 0x9041
#घोषणा IMAGE_FILE_MACHINE_CEE 0xC0EE

    प्रकार काष्ठा IMAGE_तथ्य_DIRECTORY {
      DWORD VirtualAddress;
      DWORD आकार_3;
    } IMAGE_तथ्य_DIRECTORY_2,*PIMAGE_तथ्य_DIRECTORY;

#घोषणा IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    प्रकार काष्ठा _IMAGE_OPTIONAL_HEADER {

      WORD Magic;
      BYTE MajorLinkerVersion;
      BYTE MinorLinkerVersion;
      DWORD आकार_Of_Code;
      DWORD आकार_Of_Initialized_तथ्य;
      DWORD आकार_Of_Uninitialized_तथ्य;
      DWORD AddressOfEntryPoint;
      DWORD BaseOfCode;
      DWORD Base_Of_तथ्य;
      DWORD ImageBase;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      WORD MajorOperatingSystemVersion;
      WORD MinorOperatingSystemVersion;
      WORD MajorImageVersion;
      WORD MinorImageVersion;
      WORD MajorSubsystemVersion;
      WORD MinorSubsystemVersion;
      DWORD Win32_Version_मूल्य;
      DWORD आकार_Of_Image;
      DWORD आकार_Of_Headers;
      DWORD Check_योग;
      WORD Subsystem;
      WORD DllCharacteristics;
      DWORD आकार_Of_ढेर_Reserve;
      DWORD आकार_Of_ढेर_Commit;
      DWORD आकार_Of_Heap_Reserve;
      DWORD आकार_Of_Heap_Commit;
      DWORD LoaderFlags;
      DWORD संख्या_Of_Rva_And_Sizes;
      IMAGE_तथ्य_DIRECTORY_2 तथ्य_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    प्रकार काष्ठा _IMAGE_ROM_OPTIONAL_HEADER {
      WORD Magic;
      BYTE MajorLinkerVersion;
      BYTE MinorLinkerVersion;
      DWORD आकार_Of_Code;
      DWORD आकार_Of_Initialized_तथ्य;
      DWORD आकार_Of_Uninitialized_तथ्य;
      DWORD AddressOfEntryPoint;
      DWORD BaseOfCode;
      DWORD Base_Of_तथ्य;
      DWORD BaseOfBss;
      DWORD GprMask;
      DWORD CprMask[4];
      DWORD Gp_मूल्य;
    } IMAGE_ROM_OPTIONAL_HEADER,*PIMAGE_ROM_OPTIONAL_HEADER;

    प्रकार काष्ठा _IMAGE_OPTIONAL_HEADER64 {
      WORD Magic;
      BYTE MajorLinkerVersion;
      BYTE MinorLinkerVersion;
      DWORD आकार_Of_Code;
      DWORD आकार_Of_Initialized_तथ्य;
      DWORD आकार_Of_Uninitialized_तथ्य;
      DWORD AddressOfEntryPoint;
      DWORD BaseOfCode;
      ULONGLONG ImageBase;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      WORD MajorOperatingSystemVersion;
      WORD MinorOperatingSystemVersion;
      WORD MajorImageVersion;
      WORD MinorImageVersion;
      WORD MajorSubsystemVersion;
      WORD MinorSubsystemVersion;
      DWORD Win32_Version_मूल्य;
      DWORD आकार_Of_Image;
      DWORD आकार_Of_Headers;
      DWORD Check_योग;
      WORD Subsystem;
      WORD DllCharacteristics;
      ULONGLONG आकार_Of_ढेर_Reserve;
      ULONGLONG आकार_Of_ढेर_Commit;
      ULONGLONG आकार_Of_Heap_Reserve;
      ULONGLONG आकार_Of_Heap_Commit;
      DWORD LoaderFlags;
      DWORD संख्या_Of_Rva_And_Sizes;
      IMAGE_तथ्य_DIRECTORY_2 तथ्य_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#घोषणा IMAGE_SIZEOF_ROM_OPTIONAL_HEADER 56
#घोषणा IMAGE_SIZEOF_STD_OPTIONAL_HEADER 28
#घोषणा IMAGE_SIZEOF_NT_OPTIONAL32_HEADER 224
#घोषणा IMAGE_SIZEOF_NT_OPTIONAL64_HEADER 240

#घोषणा IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#घोषणा IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#घोषणा IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#अगर_घोषित _WIN64
    प्रकार IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_HEADER;
    प्रकार PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_HEADER;
#घोषणा IMAGE_SIZEOF_NT_OPTIONAL_HEADER IMAGE_SIZEOF_NT_OPTIONAL64_HEADER
#घोषणा IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#अन्यथा
    प्रकार IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_HEADER;
    प्रकार PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_HEADER;
#घोषणा IMAGE_SIZEOF_NT_OPTIONAL_HEADER IMAGE_SIZEOF_NT_OPTIONAL32_HEADER
#घोषणा IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#पूर्ण_अगर

    प्रकार काष्ठा _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_HEADER FileHeader;
      IMAGE_OPTIONAL_HEADER64 OptionalHeader;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    प्रकार काष्ठा _IMAGE_NT_HEADERS {
      DWORD Signature;
      IMAGE_FILE_HEADER FileHeader;
      IMAGE_OPTIONAL_HEADER32 OptionalHeader;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    प्रकार काष्ठा _IMAGE_ROM_HEADERS {
      IMAGE_FILE_HEADER FileHeader;
      IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
    } IMAGE_ROM_HEADERS,*PIMAGE_ROM_HEADERS;

#अगर_घोषित _WIN64
    प्रकार IMAGE_NT_HEADERS64 IMAGE_NT_HEADERS;
    प्रकार PIMAGE_NT_HEADERS64 PIMAGE_NT_HEADERS;
#अन्यथा
    प्रकार IMAGE_NT_HEADERS32 IMAGE_NT_HEADERS;
    प्रकार PIMAGE_NT_HEADERS32 PIMAGE_NT_HEADERS;
#पूर्ण_अगर

#घोषणा IMAGE_FIRST_SECTION(ntheader) ((PIMAGE_SECTION_HEADER) ((ULONG_PTR)ntheader + FIELD_OFFSET(IMAGE_NT_HEADERS,OptionalHeader) + ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.आकार_Of_Optional_Header))

#घोषणा IMAGE_SUBSYSTEM_UNKNOWN 0
#घोषणा IMAGE_SUBSYSTEM_NATIVE 1
#घोषणा IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#घोषणा IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#घोषणा IMAGE_SUBSYSTEM_OS2_CUI 5
#घोषणा IMAGE_SUBSYSTEM_POSIX_CUI 7
#घोषणा IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#घोषणा IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#घोषणा IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#घोषणा IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#घोषणा IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#घोषणा IMAGE_SUBSYSTEM_EFI_ROM 13
#घोषणा IMAGE_SUBSYSTEM_XBOX 14

#घोषणा IMAGE_DLLCHARACTERISTICS_ऊपरी_ENTROPY_VA 0x0020
#घोषणा IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE 0x0040
#घोषणा IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#घोषणा IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#घोषणा IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#घोषणा IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#घोषणा IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#घोषणा IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#घोषणा IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#घोषणा IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#घोषणा IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#घोषणा IMAGE_DIRECTORY_ENTRY_EXPORT 0
#घोषणा IMAGE_DIRECTORY_ENTRY_IMPORT 1
#घोषणा IMAGE_DIRECTORY_ENTRY_RESOURCE 2
#घोषणा IMAGE_DIRECTORY_ENTRY_EXCEPTION 3
#घोषणा IMAGE_DIRECTORY_ENTRY_SECURITY 4
#घोषणा IMAGE_DIRECTORY_ENTRY_BASERELOC 5
#घोषणा IMAGE_DIRECTORY_ENTRY_DEBUG 6

#घोषणा IMAGE_DIRECTORY_ENTRY_ARCHITECTURE 7
#घोषणा IMAGE_DIRECTORY_ENTRY_GLOBALPTR 8
#घोषणा IMAGE_DIRECTORY_ENTRY_TLS 9
#घोषणा IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG 10
#घोषणा IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT 11
#घोषणा IMAGE_DIRECTORY_ENTRY_IAT 12
#घोषणा IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT 13
#घोषणा IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR 14

    प्रकार काष्ठा ANON_OBJECT_HEADER {
      WORD Sig1;
      WORD Sig2;
      WORD Version;
      WORD Machine;
      DWORD TimeDateStamp;
      CLSID ClassID;
      DWORD आकार_Of_तथ्य;
    } ANON_OBJECT_HEADER;

#घोषणा IMAGE_SIZEOF_SHORT_NAME 8

    प्रकार काष्ठा _IMAGE_SECTION_HEADER {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      जोड़ {
	DWORD PhysicalAddress;
	DWORD Virtual_आकार;
      } Misc;
      DWORD VirtualAddress;
      DWORD आकार_Of_Raw_तथ्य;
      DWORD Pointer_To_Raw_तथ्य;
      DWORD PointerToRelocations;
      DWORD PointerToLinenumbers;
      WORD संख्या_Of_Relocations;
      WORD संख्या_Of_Linenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_HEADER,*PIMAGE_SECTION_HEADER;

#घोषणा IMAGE_SIZEOF_SECTION_HEADER 40

#घोषणा IMAGE_SCN_TYPE_NO_PAD 0x00000008

#घोषणा IMAGE_SCN_CNT_CODE 0x00000020
#घोषणा IMAGE_SCN_CNT_INITIALIZED_तथ्य 0x00000040
#घोषणा IMAGE_SCN_CNT_UNINITIALIZED_तथ्य 0x00000080
#घोषणा IMAGE_SCN_LNK_OTHER 0x00000100
#घोषणा IMAGE_SCN_LNK_INFO 0x00000200
#घोषणा IMAGE_SCN_LNK_REMOVE 0x00000800
#घोषणा IMAGE_SCN_LNK_COMDAT 0x00001000
#घोषणा IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#घोषणा IMAGE_SCN_GPREL 0x00008000
#घोषणा IMAGE_SCN_MEM_FARDATA 0x00008000
#घोषणा IMAGE_SCN_MEM_PURGEABLE 0x00020000
#घोषणा IMAGE_SCN_MEM_16BIT 0x00020000
#घोषणा IMAGE_SCN_MEM_LOCKED 0x00040000
#घोषणा IMAGE_SCN_MEM_PRELOAD 0x00080000

#घोषणा IMAGE_SCN_ALIGN_1BYTES 0x00100000
#घोषणा IMAGE_SCN_ALIGN_2BYTES 0x00200000
#घोषणा IMAGE_SCN_ALIGN_4BYTES 0x00300000
#घोषणा IMAGE_SCN_ALIGN_8BYTES 0x00400000
#घोषणा IMAGE_SCN_ALIGN_16BYTES 0x00500000
#घोषणा IMAGE_SCN_ALIGN_32BYTES 0x00600000
#घोषणा IMAGE_SCN_ALIGN_64BYTES 0x00700000
#घोषणा IMAGE_SCN_ALIGN_128BYTES 0x00800000
#घोषणा IMAGE_SCN_ALIGN_256BYTES 0x00900000
#घोषणा IMAGE_SCN_ALIGN_512BYTES 0x00A00000
#घोषणा IMAGE_SCN_ALIGN_1024BYTES 0x00B00000
#घोषणा IMAGE_SCN_ALIGN_2048BYTES 0x00C00000
#घोषणा IMAGE_SCN_ALIGN_4096BYTES 0x00D00000
#घोषणा IMAGE_SCN_ALIGN_8192BYTES 0x00E00000

#घोषणा IMAGE_SCN_ALIGN_MASK 0x00F00000

#घोषणा IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#घोषणा IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#घोषणा IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#घोषणा IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#घोषणा IMAGE_SCN_MEM_SHARED 0x10000000
#घोषणा IMAGE_SCN_MEM_EXECUTE 0x20000000
#घोषणा IMAGE_SCN_MEM_READ 0x40000000
#घोषणा IMAGE_SCN_MEM_WRITE 0x80000000

#घोषणा IMAGE_SCN_SCALE_सूचकांक 0x00000001

#समावेश "pshpack2.h"

    प्रकार काष्ठा IMAGE_प्रतीक {
      जोड़ {
	BYTE ShortName[8];
	काष्ठा {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD मूल्य_3;
      SHORT Section_संख्या;
      WORD Type;
      BYTE StorageClass;
      BYTE संख्या_Of_Aux_Symbols;
    } IMAGE_प्रतीक_2;
    प्रकार IMAGE_प्रतीक_2 UNALIGNED *PIMAGE_प्रतीक;

#घोषणा IMAGE_SIZEOF_प्रतीक 18

#घोषणा IMAGE_SYM_UNDEFINED (SHORT)0
#घोषणा IMAGE_SYM_ABSOLUTE (SHORT)-1
#घोषणा IMAGE_SYM_DEBUG (SHORT)-2
#घोषणा IMAGE_SYM_SECTION_MAX 0xFEFF

#घोषणा IMAGE_SYM_TYPE_NULL 0x0000
#घोषणा IMAGE_SYM_TYPE_VOID 0x0001
#घोषणा IMAGE_SYM_TYPE_CHAR 0x0002
#घोषणा IMAGE_SYM_TYPE_SHORT 0x0003
#घोषणा IMAGE_SYM_TYPE_INT 0x0004
#घोषणा IMAGE_SYM_TYPE_LONG 0x0005
#घोषणा IMAGE_SYM_TYPE_FLOAT 0x0006
#घोषणा IMAGE_SYM_TYPE_DOUBLE 0x0007
#घोषणा IMAGE_SYM_TYPE_STRUCT 0x0008
#घोषणा IMAGE_SYM_TYPE_UNION 0x0009
#घोषणा IMAGE_SYM_TYPE_ENUM 0x000A
#घोषणा IMAGE_SYM_TYPE_MOE 0x000B
#घोषणा IMAGE_SYM_TYPE_BYTE 0x000C
#घोषणा IMAGE_SYM_TYPE_WORD 0x000D
#घोषणा IMAGE_SYM_TYPE_UINT 0x000E
#घोषणा IMAGE_SYM_TYPE_DWORD 0x000F
#घोषणा IMAGE_SYM_TYPE_PCODE 0x8000

#घोषणा IMAGE_SYM_DTYPE_NULL 0
#घोषणा IMAGE_SYM_DTYPE_POINTER 1
#घोषणा IMAGE_SYM_DTYPE_FUNCTION 2
#घोषणा IMAGE_SYM_DTYPE_ARRAY 3

#घोषणा IMAGE_SYM_CLASS_END_OF_FUNCTION (BYTE)-1
#घोषणा IMAGE_SYM_CLASS_NULL 0x0000
#घोषणा IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#घोषणा IMAGE_SYM_CLASS_EXTERNAL 0x0002
#घोषणा IMAGE_SYM_CLASS_STATIC 0x0003
#घोषणा IMAGE_SYM_CLASS_REGISTER 0x0004
#घोषणा IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#घोषणा IMAGE_SYM_CLASS_LABEL 0x0006
#घोषणा IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#घोषणा IMAGE_SYM_CLASS_MEMBER_OF_STRUCT 0x0008
#घोषणा IMAGE_SYM_CLASS_ARGUMENT 0x0009
#घोषणा IMAGE_SYM_CLASS_STRUCT_TAG 0x000A
#घोषणा IMAGE_SYM_CLASS_MEMBER_OF_UNION 0x000B
#घोषणा IMAGE_SYM_CLASS_UNION_TAG 0x000C
#घोषणा IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#घोषणा IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#घोषणा IMAGE_SYM_CLASS_ENUM_TAG 0x000F
#घोषणा IMAGE_SYM_CLASS_MEMBER_OF_ENUM 0x0010
#घोषणा IMAGE_SYM_CLASS_REGISTER_PARAM 0x0011
#घोषणा IMAGE_SYM_CLASS_BIT_FIELD 0x0012
#घोषणा IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#घोषणा IMAGE_SYM_CLASS_BLOCK 0x0064
#घोषणा IMAGE_SYM_CLASS_FUNCTION 0x0065
#घोषणा IMAGE_SYM_CLASS_END_OF_STRUCT 0x0066
#घोषणा IMAGE_SYM_CLASS_FILE 0x0067
#घोषणा IMAGE_SYM_CLASS_SECTION 0x0068
#घोषणा IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#घोषणा IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#घोषणा N_BTMASK 0x000F
#घोषणा N_TMASK 0x0030
#घोषणा N_TMASK1 0x00C0
#घोषणा N_TMASK2 0x00F0
#घोषणा N_BTSHFT 4
#घोषणा N_TSHIFT 2

#घोषणा BTYPE(x) ((x) & N_BTMASK)

#अगर_अघोषित ISPTR
#घोषणा ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_POINTER << N_BTSHFT))
#पूर्ण_अगर

#अगर_अघोषित ISFCN
#घोषणा ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#पूर्ण_अगर

#अगर_अघोषित ISARY
#घोषणा ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#पूर्ण_अगर

#अगर_अघोषित ISTAG
#घोषणा ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_TAG || (x)==IMAGE_SYM_CLASS_UNION_TAG || (x)==IMAGE_SYM_CLASS_ENUM_TAG)
#पूर्ण_अगर

#अगर_अघोषित INCREF
#घोषणा INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_POINTER<<N_BTSHFT)|((x)&N_BTMASK))
#पूर्ण_अगर
#अगर_अघोषित DECREF
#घोषणा DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#पूर्ण_अगर

    प्रकार जोड़ IMAGE_AUX_प्रतीक {
      काष्ठा {
	DWORD Tag_सूचकांक;
	जोड़ {
	  काष्ठा {
	    WORD Linenumber;
	    WORD आकार_3;
	  } LnSz;
	  DWORD योग_आकार;
	} Misc;
	जोड़ {
	  काष्ठा {
	    DWORD PointerToLinenumber;
	    DWORD Pointer_To_अग्र_Function;
	  } Function;
	  काष्ठा {
	    WORD Dimension[4];
	  } Array;
	} FcnAry;
	WORD Tv_सूचकांक;
      } Sym;
      काष्ठा {
	BYTE Name[IMAGE_SIZEOF_प्रतीक];
      } File;
      काष्ठा {
	DWORD लंबाई_2;
	WORD संख्या_Of_Relocations;
	WORD संख्या_Of_Linenumbers;
	DWORD Check_योग;
	SHORT संख्या_2;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_प्रतीक_2;
    प्रकार IMAGE_AUX_प्रतीक_2 UNALIGNED *PIMAGE_AUX_प्रतीक;

#घोषणा IMAGE_SIZEOF_AUX_प्रतीक 18

    प्रकार क्रमागत IMAGE_AUX_प्रतीक_TYPE {
      IMAGE_AUX_प्रतीक_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_प्रतीक_TYPE;

#समावेश <pshpack2.h>

    प्रकार काष्ठा IMAGE_AUX_प्रतीक_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD प्रतीक_Table_सूचकांक;
      BYTE rgbReserved[12];
    } IMAGE_AUX_प्रतीक_TOKEN_DEF;

    प्रकार IMAGE_AUX_प्रतीक_TOKEN_DEF UNALIGNED *PIMAGE_AUX_प्रतीक_TOKEN_DEF;

#समावेश <poppack.h>

#घोषणा IMAGE_COMDAT_SELECT_NODUPLICATES 1
#घोषणा IMAGE_COMDAT_SELECT_ANY 2
#घोषणा IMAGE_COMDAT_SELECT_SAME_आकार 3
#घोषणा IMAGE_COMDAT_SELECT_EXACT_MATCH 4
#घोषणा IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#घोषणा IMAGE_COMDAT_SELECT_LARGEST 6
#घोषणा IMAGE_COMDAT_SELECT_NEWEST 7

#घोषणा IMAGE_WEAK_EXTERN_खोज_NOLIBRARY 1
#घोषणा IMAGE_WEAK_EXTERN_खोज_LIBRARY 2
#घोषणा IMAGE_WEAK_EXTERN_खोज_ALIAS 3

    प्रकार काष्ठा _IMAGE_RELOCATION {
      जोड़ {
	DWORD VirtualAddress;
	DWORD Reloc_गिनती;
      };
      DWORD प्रतीक_Table_सूचकांक;
      WORD Type;
    } IMAGE_RELOCATION;
    प्रकार IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#घोषणा IMAGE_SIZEOF_RELOCATION 10

#घोषणा IMAGE_REL_I386_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_I386_DIR16 0x0001
#घोषणा IMAGE_REL_I386_REL16 0x0002
#घोषणा IMAGE_REL_I386_DIR32 0x0006
#घोषणा IMAGE_REL_I386_DIR32NB 0x0007
#घोषणा IMAGE_REL_I386_SEG12 0x0009
#घोषणा IMAGE_REL_I386_SECTION 0x000A
#घोषणा IMAGE_REL_I386_SECREL 0x000B
#घोषणा IMAGE_REL_I386_TOKEN 0x000C
#घोषणा IMAGE_REL_I386_SECREL7 0x000D
#घोषणा IMAGE_REL_I386_REL32 0x0014

#घोषणा IMAGE_REL_MIPS_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_MIPS_REFHALF 0x0001
#घोषणा IMAGE_REL_MIPS_REFWORD 0x0002
#घोषणा IMAGE_REL_MIPS_JMPADDR 0x0003
#घोषणा IMAGE_REL_MIPS_REFHI 0x0004
#घोषणा IMAGE_REL_MIPS_REFLO 0x0005
#घोषणा IMAGE_REL_MIPS_GPREL 0x0006
#घोषणा IMAGE_REL_MIPS_LITERAL 0x0007
#घोषणा IMAGE_REL_MIPS_SECTION 0x000A
#घोषणा IMAGE_REL_MIPS_SECREL 0x000B
#घोषणा IMAGE_REL_MIPS_SECRELLO 0x000C
#घोषणा IMAGE_REL_MIPS_SECRELHI 0x000D
#घोषणा IMAGE_REL_MIPS_TOKEN 0x000E
#घोषणा IMAGE_REL_MIPS_JMPADDR16 0x0010
#घोषणा IMAGE_REL_MIPS_REFWORDNB 0x0022
#घोषणा IMAGE_REL_MIPS_PAIR 0x0025

#घोषणा IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_ALPHA_REFLONG 0x0001
#घोषणा IMAGE_REL_ALPHA_REFQUAD 0x0002
#घोषणा IMAGE_REL_ALPHA_GPREL32 0x0003
#घोषणा IMAGE_REL_ALPHA_LITERAL 0x0004
#घोषणा IMAGE_REL_ALPHA_LITUSE 0x0005
#घोषणा IMAGE_REL_ALPHA_GPDISP 0x0006
#घोषणा IMAGE_REL_ALPHA_BRADDR 0x0007
#घोषणा IMAGE_REL_ALPHA_HINT 0x0008
#घोषणा IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#घोषणा IMAGE_REL_ALPHA_REFHI 0x000A
#घोषणा IMAGE_REL_ALPHA_REFLO 0x000B
#घोषणा IMAGE_REL_ALPHA_PAIR 0x000C
#घोषणा IMAGE_REL_ALPHA_MATCH 0x000D
#घोषणा IMAGE_REL_ALPHA_SECTION 0x000E
#घोषणा IMAGE_REL_ALPHA_SECREL 0x000F
#घोषणा IMAGE_REL_ALPHA_REFLONGNB 0x0010
#घोषणा IMAGE_REL_ALPHA_SECRELLO 0x0011
#घोषणा IMAGE_REL_ALPHA_SECRELHI 0x0012
#घोषणा IMAGE_REL_ALPHA_REFQ3 0x0013
#घोषणा IMAGE_REL_ALPHA_REFQ2 0x0014
#घोषणा IMAGE_REL_ALPHA_REFQ1 0x0015
#घोषणा IMAGE_REL_ALPHA_GPRELLO 0x0016
#घोषणा IMAGE_REL_ALPHA_GPRELHI 0x0017

#घोषणा IMAGE_REL_PPC_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_PPC_ADDR64 0x0001
#घोषणा IMAGE_REL_PPC_ADDR32 0x0002
#घोषणा IMAGE_REL_PPC_ADDR24 0x0003
#घोषणा IMAGE_REL_PPC_ADDR16 0x0004
#घोषणा IMAGE_REL_PPC_ADDR14 0x0005
#घोषणा IMAGE_REL_PPC_REL24 0x0006
#घोषणा IMAGE_REL_PPC_REL14 0x0007
#घोषणा IMAGE_REL_PPC_TOCREL16 0x0008
#घोषणा IMAGE_REL_PPC_TOCREL14 0x0009
#घोषणा IMAGE_REL_PPC_ADDR32NB 0x000A
#घोषणा IMAGE_REL_PPC_SECREL 0x000B
#घोषणा IMAGE_REL_PPC_SECTION 0x000C
#घोषणा IMAGE_REL_PPC_IFGLUE 0x000D
#घोषणा IMAGE_REL_PPC_IMGLUE 0x000E
#घोषणा IMAGE_REL_PPC_SECREL16 0x000F
#घोषणा IMAGE_REL_PPC_REFHI 0x0010
#घोषणा IMAGE_REL_PPC_REFLO 0x0011
#घोषणा IMAGE_REL_PPC_PAIR 0x0012
#घोषणा IMAGE_REL_PPC_SECRELLO 0x0013
#घोषणा IMAGE_REL_PPC_SECRELHI 0x0014
#घोषणा IMAGE_REL_PPC_GPREL 0x0015
#घोषणा IMAGE_REL_PPC_TOKEN 0x0016
#घोषणा IMAGE_REL_PPC_TYPEMASK 0x00FF
#घोषणा IMAGE_REL_PPC_NEG 0x0100
#घोषणा IMAGE_REL_PPC_BRTAKEN 0x0200
#घोषणा IMAGE_REL_PPC_BRNTAKEN 0x0400
#घोषणा IMAGE_REL_PPC_TOCDEFN 0x0800

#घोषणा IMAGE_REL_SH3_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_SH3_DIRECT16 0x0001
#घोषणा IMAGE_REL_SH3_DIRECT32 0x0002
#घोषणा IMAGE_REL_SH3_DIRECT8 0x0003
#घोषणा IMAGE_REL_SH3_DIRECT8_WORD 0x0004
#घोषणा IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#घोषणा IMAGE_REL_SH3_DIRECT4 0x0006
#घोषणा IMAGE_REL_SH3_DIRECT4_WORD 0x0007
#घोषणा IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#घोषणा IMAGE_REL_SH3_PCREL8_WORD 0x0009
#घोषणा IMAGE_REL_SH3_PCREL8_LONG 0x000A
#घोषणा IMAGE_REL_SH3_PCREL12_WORD 0x000B
#घोषणा IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#घोषणा IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#घोषणा IMAGE_REL_SH3_SECTION 0x000E
#घोषणा IMAGE_REL_SH3_SECREL 0x000F
#घोषणा IMAGE_REL_SH3_DIRECT32_NB 0x0010
#घोषणा IMAGE_REL_SH3_GPREL4_LONG 0x0011
#घोषणा IMAGE_REL_SH3_TOKEN 0x0012

#घोषणा IMAGE_REL_SHM_PCRELPT 0x0013
#घोषणा IMAGE_REL_SHM_REFLO 0x0014
#घोषणा IMAGE_REL_SHM_REFHALF 0x0015
#घोषणा IMAGE_REL_SHM_RELLO 0x0016
#घोषणा IMAGE_REL_SHM_RELHALF 0x0017
#घोषणा IMAGE_REL_SHM_PAIR 0x0018

#घोषणा IMAGE_REL_SH_NOMODE 0x8000

#घोषणा IMAGE_REL_ARM_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_ARM_ADDR32 0x0001
#घोषणा IMAGE_REL_ARM_ADDR32NB 0x0002
#घोषणा IMAGE_REL_ARM_BRANCH24 0x0003
#घोषणा IMAGE_REL_ARM_BRANCH11 0x0004
#घोषणा IMAGE_REL_ARM_TOKEN 0x0005
#घोषणा IMAGE_REL_ARM_GPREL12 0x0006
#घोषणा IMAGE_REL_ARM_GPREL7 0x0007
#घोषणा IMAGE_REL_ARM_BLX24 0x0008
#घोषणा IMAGE_REL_ARM_BLX11 0x0009
#घोषणा IMAGE_REL_ARM_SECTION 0x000E
#घोषणा IMAGE_REL_ARM_SECREL 0x000F

#घोषणा IMAGE_REL_AM_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_AM_ADDR32 0x0001
#घोषणा IMAGE_REL_AM_ADDR32NB 0x0002
#घोषणा IMAGE_REL_AM_CALL32 0x0003
#घोषणा IMAGE_REL_AM_FUNCINFO 0x0004
#घोषणा IMAGE_REL_AM_REL32_1 0x0005
#घोषणा IMAGE_REL_AM_REL32_2 0x0006
#घोषणा IMAGE_REL_AM_SECREL 0x0007
#घोषणा IMAGE_REL_AM_SECTION 0x0008
#घोषणा IMAGE_REL_AM_TOKEN 0x0009

#घोषणा IMAGE_REL_AMD64_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_AMD64_ADDR64 0x0001
#घोषणा IMAGE_REL_AMD64_ADDR32 0x0002
#घोषणा IMAGE_REL_AMD64_ADDR32NB 0x0003
#घोषणा IMAGE_REL_AMD64_REL32 0x0004
#घोषणा IMAGE_REL_AMD64_REL32_1 0x0005
#घोषणा IMAGE_REL_AMD64_REL32_2 0x0006
#घोषणा IMAGE_REL_AMD64_REL32_3 0x0007
#घोषणा IMAGE_REL_AMD64_REL32_4 0x0008
#घोषणा IMAGE_REL_AMD64_REL32_5 0x0009
#घोषणा IMAGE_REL_AMD64_SECTION 0x000A
#घोषणा IMAGE_REL_AMD64_SECREL 0x000B
#घोषणा IMAGE_REL_AMD64_SECREL7 0x000C
#घोषणा IMAGE_REL_AMD64_TOKEN 0x000D
#घोषणा IMAGE_REL_AMD64_SREL32 0x000E
#घोषणा IMAGE_REL_AMD64_PAIR 0x000F
#घोषणा IMAGE_REL_AMD64_SSPAN32 0x0010

#घोषणा IMAGE_REL_IA64_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_IA64_IMM14 0x0001
#घोषणा IMAGE_REL_IA64_IMM22 0x0002
#घोषणा IMAGE_REL_IA64_IMM64 0x0003
#घोषणा IMAGE_REL_IA64_DIR32 0x0004
#घोषणा IMAGE_REL_IA64_DIR64 0x0005
#घोषणा IMAGE_REL_IA64_PCREL21B 0x0006
#घोषणा IMAGE_REL_IA64_PCREL21M 0x0007
#घोषणा IMAGE_REL_IA64_PCREL21F 0x0008
#घोषणा IMAGE_REL_IA64_GPREL22 0x0009
#घोषणा IMAGE_REL_IA64_LTOFF22 0x000A
#घोषणा IMAGE_REL_IA64_SECTION 0x000B
#घोषणा IMAGE_REL_IA64_SECREL22 0x000C
#घोषणा IMAGE_REL_IA64_SECREL64I 0x000D
#घोषणा IMAGE_REL_IA64_SECREL32 0x000E

#घोषणा IMAGE_REL_IA64_DIR32NB 0x0010
#घोषणा IMAGE_REL_IA64_SREL14 0x0011
#घोषणा IMAGE_REL_IA64_SREL22 0x0012
#घोषणा IMAGE_REL_IA64_SREL32 0x0013
#घोषणा IMAGE_REL_IA64_UREL32 0x0014
#घोषणा IMAGE_REL_IA64_PCREL60X 0x0015
#घोषणा IMAGE_REL_IA64_PCREL60B 0x0016
#घोषणा IMAGE_REL_IA64_PCREL60F 0x0017
#घोषणा IMAGE_REL_IA64_PCREL60I 0x0018
#घोषणा IMAGE_REL_IA64_PCREL60M 0x0019
#घोषणा IMAGE_REL_IA64_IMMGPREL64 0x001A
#घोषणा IMAGE_REL_IA64_TOKEN 0x001B
#घोषणा IMAGE_REL_IA64_GPREL32 0x001C
#घोषणा IMAGE_REL_IA64_ADDEND 0x001F

#घोषणा IMAGE_REL_CEF_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_CEF_ADDR32 0x0001
#घोषणा IMAGE_REL_CEF_ADDR64 0x0002
#घोषणा IMAGE_REL_CEF_ADDR32NB 0x0003
#घोषणा IMAGE_REL_CEF_SECTION 0x0004
#घोषणा IMAGE_REL_CEF_SECREL 0x0005
#घोषणा IMAGE_REL_CEF_TOKEN 0x0006

#घोषणा IMAGE_REL_CEE_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_CEE_ADDR32 0x0001
#घोषणा IMAGE_REL_CEE_ADDR64 0x0002
#घोषणा IMAGE_REL_CEE_ADDR32NB 0x0003
#घोषणा IMAGE_REL_CEE_SECTION 0x0004
#घोषणा IMAGE_REL_CEE_SECREL 0x0005
#घोषणा IMAGE_REL_CEE_TOKEN 0x0006

#घोषणा IMAGE_REL_M32R_ABSOLUTE 0x0000
#घोषणा IMAGE_REL_M32R_ADDR32 0x0001
#घोषणा IMAGE_REL_M32R_ADDR32NB 0x0002
#घोषणा IMAGE_REL_M32R_ADDR24 0x0003
#घोषणा IMAGE_REL_M32R_GPREL16 0x0004
#घोषणा IMAGE_REL_M32R_PCREL24 0x0005
#घोषणा IMAGE_REL_M32R_PCREL16 0x0006
#घोषणा IMAGE_REL_M32R_PCREL8 0x0007
#घोषणा IMAGE_REL_M32R_REFHALF 0x0008
#घोषणा IMAGE_REL_M32R_REFHI 0x0009
#घोषणा IMAGE_REL_M32R_REFLO 0x000A
#घोषणा IMAGE_REL_M32R_PAIR 0x000B
#घोषणा IMAGE_REL_M32R_SECTION 0x000C
#घोषणा IMAGE_REL_M32R_SECREL32 0x000D
#घोषणा IMAGE_REL_M32R_TOKEN 0x000E

#घोषणा EXT_IMM64(मूल्य_3,Address,आकार_3,InstPos,ValPos) मूल्य_3 |= (((ULONGLONG)((*(Address) >> InstPos) & (((ULONGLONG)1 << आकार_3) - 1))) << ValPos)
#घोषणा INS_IMM64(मूल्य_3,Address,आकार_3,InstPos,ValPos) *(PDWORD)Address = (*(PDWORD)Address & ~(((1 << आकार_3) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)मूल्य_3 >> ValPos) & (((ULONGLONG)1 << आकार_3) - 1))) << InstPos)

#घोषणा EMARCH_ENC_I17_IMM7B_INST_WORD_X 3
#घोषणा EMARCH_ENC_I17_IMM7_B_आकार_X 7
#घोषणा EMARCH_ENC_I17_IMM7B_INST_WORD_POS_X 4
#घोषणा EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#घोषणा EMARCH_ENC_I17_IMM9D_INST_WORD_X 3
#घोषणा EMARCH_ENC_I17_IMM9_D_आकार_X 9
#घोषणा EMARCH_ENC_I17_IMM9D_INST_WORD_POS_X 18
#घोषणा EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#घोषणा EMARCH_ENC_I17_IMM5C_INST_WORD_X 3
#घोषणा EMARCH_ENC_I17_IMM5_C_आकार_X 5
#घोषणा EMARCH_ENC_I17_IMM5C_INST_WORD_POS_X 13
#घोषणा EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#घोषणा EMARCH_ENC_I17_IC_INST_WORD_X 3
#घोषणा EMARCH_ENC_I17_IC_आकार_X 1
#घोषणा EMARCH_ENC_I17_IC_INST_WORD_POS_X 12
#घोषणा EMARCH_ENC_I17_IC_VAL_POS_X 21

#घोषणा EMARCH_ENC_I17_IMM41a_INST_WORD_X 1
#घोषणा EMARCH_ENC_I17_IMM41a_आकार_X 10
#घोषणा EMARCH_ENC_I17_IMM41a_INST_WORD_POS_X 14
#घोषणा EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#घोषणा EMARCH_ENC_I17_IMM41b_INST_WORD_X 1
#घोषणा EMARCH_ENC_I17_IMM41b_आकार_X 8
#घोषणा EMARCH_ENC_I17_IMM41b_INST_WORD_POS_X 24
#घोषणा EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#घोषणा EMARCH_ENC_I17_IMM41c_INST_WORD_X 2
#घोषणा EMARCH_ENC_I17_IMM41c_आकार_X 23
#घोषणा EMARCH_ENC_I17_IMM41c_INST_WORD_POS_X 0
#घोषणा EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#घोषणा EMARCH_ENC_I17_SIGN_INST_WORD_X 3
#घोषणा EMARCH_ENC_I17_SIGN_आकार_X 1
#घोषणा EMARCH_ENC_I17_SIGN_INST_WORD_POS_X 27
#घोषणा EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#घोषणा X3_OPCODE_INST_WORD_X 3
#घोषणा X3_OPCODE_आकार_X 4
#घोषणा X3_OPCODE_INST_WORD_POS_X 28
#घोषणा X3_OPCODE_SIGN_VAL_POS_X 0

#घोषणा X3_I_INST_WORD_X 3
#घोषणा X3_I_आकार_X 1
#घोषणा X3_I_INST_WORD_POS_X 27
#घोषणा X3_I_SIGN_VAL_POS_X 59

#घोषणा X3_D_WH_INST_WORD_X 3
#घोषणा X3_D_WH_आकार_X 3
#घोषणा X3_D_WH_INST_WORD_POS_X 24
#घोषणा X3_D_WH_SIGN_VAL_POS_X 0

#घोषणा X3_IMM20_INST_WORD_X 3
#घोषणा X3_IMM20_आकार_X 20
#घोषणा X3_IMM20_INST_WORD_POS_X 4
#घोषणा X3_IMM20_SIGN_VAL_POS_X 0

#घोषणा X3_IMM39_1_INST_WORD_X 2
#घोषणा X3_IMM39_1_आकार_X 23
#घोषणा X3_IMM39_1_INST_WORD_POS_X 0
#घोषणा X3_IMM39_1_SIGN_VAL_POS_X 36

#घोषणा X3_IMM39_2_INST_WORD_X 1
#घोषणा X3_IMM39_2_आकार_X 16
#घोषणा X3_IMM39_2_INST_WORD_POS_X 16
#घोषणा X3_IMM39_2_SIGN_VAL_POS_X 20

#घोषणा X3_P_INST_WORD_X 3
#घोषणा X3_P_आकार_X 4
#घोषणा X3_P_INST_WORD_POS_X 0
#घोषणा X3_P_SIGN_VAL_POS_X 0

#घोषणा X3_TMPLT_INST_WORD_X 0
#घोषणा X3_TMPLT_आकार_X 4
#घोषणा X3_TMPLT_INST_WORD_POS_X 0
#घोषणा X3_TMPLT_SIGN_VAL_POS_X 0

#घोषणा X3_BTYPE_QP_INST_WORD_X 2
#घोषणा X3_BTYPE_QP_आकार_X 9
#घोषणा X3_BTYPE_QP_INST_WORD_POS_X 23
#घोषणा X3_BTYPE_QP_INST_VAL_POS_X 0

#घोषणा X3_EMPTY_INST_WORD_X 1
#घोषणा X3_EMPTY_आकार_X 2
#घोषणा X3_EMPTY_INST_WORD_POS_X 14
#घोषणा X3_EMPTY_INST_VAL_POS_X 0

    प्रकार काष्ठा _IMAGE_LINENUMBER {
      जोड़ {
	DWORD प्रतीक_Table_सूचकांक;
	DWORD VirtualAddress;
      } Type;
      WORD Linenumber;
    } IMAGE_LINENUMBER;
    प्रकार IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#घोषणा IMAGE_SIZEOF_LINENUMBER 6

#समावेश "poppack.h"

    प्रकार काष्ठा _IMAGE_BASE_RELOCATION {
      DWORD VirtualAddress;
      DWORD आकार_Of_Block;

    } IMAGE_BASE_RELOCATION;
    प्रकार IMAGE_BASE_RELOCATION UNALIGNED *PIMAGE_BASE_RELOCATION;

#घोषणा IMAGE_SIZEOF_BASE_RELOCATION 8

#घोषणा IMAGE_REL_BASED_ABSOLUTE 0
#घोषणा IMAGE_REL_BASED_ऊपरी 1
#घोषणा IMAGE_REL_BASED_निचला 2
#घोषणा IMAGE_REL_BASED_HIGHLOW 3
#घोषणा IMAGE_REL_BASED_HIGHADJ 4
#घोषणा IMAGE_REL_BASED_MIPS_JMPADDR 5
#घोषणा IMAGE_REL_BASED_MIPS_JMPADDR16 9
#घोषणा IMAGE_REL_BASED_IA64_IMM64 9
#घोषणा IMAGE_REL_BASED_DIR64 10

#घोषणा IMAGE_ARCHIVE_START_आकार 8
#घोषणा IMAGE_ARCHIVE_START "!<arch>\n"
#घोषणा IMAGE_ARCHIVE_END "`\n"
#घोषणा IMAGE_ARCHIVE_PAD "\n"
#घोषणा IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#घोषणा IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    प्रकार काष्ठा _IMAGE_ARCHIVE_MEMBER_HEADER {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE GroupID[6];
      BYTE Mode[8];
      BYTE आकार_3[10];
      BYTE EndHeader[2];
    } IMAGE_ARCHIVE_MEMBER_HEADER,*PIMAGE_ARCHIVE_MEMBER_HEADER;

#घोषणा IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    प्रकार काष्ठा _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      DWORD Name;
      DWORD Base;
      DWORD संख्या_Of_Functions;
      DWORD संख्या_Of_Names;
      DWORD AddressOfFunctions;
      DWORD AddressOfNames;
      DWORD AddressOfNameOrdinals;
    } IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

    प्रकार काष्ठा _IMAGE_IMPORT_BY_NAME {
      WORD Hint;
      BYTE Name[1];
    } IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#समावेश "pshpack8.h"

    प्रकार काष्ठा _IMAGE_THUNK_DATA64 {
      जोड़ {
	ULONGLONG ForwarderString;
	ULONGLONG Function;
	ULONGLONG Ordinal;
	ULONGLONG Address_Of_तथ्य;
      } u1;
    } IMAGE_THUNK_DATA64;
    प्रकार IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#समावेश "poppack.h"

    प्रकार काष्ठा _IMAGE_THUNK_DATA32 {
      जोड़ {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD Address_Of_तथ्य;
      } u1;
    } IMAGE_THUNK_DATA32;
    प्रकार IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#घोषणा IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#घोषणा IMAGE_ORDINAL_FLAG32 0x80000000
#घोषणा IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#घोषणा IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#घोषणा IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#घोषणा IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    प्रकार VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    प्रकार काष्ठा _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG Start_Address_Of_Raw_तथ्य;
      ULONGLONG End_Address_Of_Raw_तथ्य;
      ULONGLONG Address_Of_सूचकांक;
      ULONGLONG AddressOfCallBacks;
      DWORD आकार_Of_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    प्रकार IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    प्रकार काष्ठा _IMAGE_TLS_DIRECTORY32 {
      DWORD Start_Address_Of_Raw_तथ्य;
      DWORD End_Address_Of_Raw_तथ्य;
      DWORD Address_Of_सूचकांक;
      DWORD AddressOfCallBacks;
      DWORD आकार_Of_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    प्रकार IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#अगर_घोषित _WIN64
#घोषणा IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#घोषणा IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    प्रकार IMAGE_THUNK_DATA64 IMAGE_THUNK_तथ्य;
    प्रकार PIMAGE_THUNK_DATA64 PIMAGE_THUNK_तथ्य;
#घोषणा IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    प्रकार IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    प्रकार PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#अन्यथा
#घोषणा IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#घोषणा IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    प्रकार IMAGE_THUNK_DATA32 IMAGE_THUNK_तथ्य;
    प्रकार PIMAGE_THUNK_DATA32 PIMAGE_THUNK_तथ्य;
#घोषणा IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    प्रकार IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    प्रकार PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#पूर्ण_अगर

    प्रकार काष्ठा _IMAGE_IMPORT_DESCRIPTOR {
      जोड़ {
	DWORD Characteristics;
	DWORD OriginalFirstThunk;
      };
      DWORD TimeDateStamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD FirstThunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    प्रकार IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    प्रकार काष्ठा _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD TimeDateStamp;
      WORD OffsetModuleName;
      WORD संख्या_Of_Module_Forwarder_Refs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    प्रकार काष्ठा _IMAGE_BOUND_FORWARDER_REF {
      DWORD TimeDateStamp;
      WORD OffsetModuleName;
      WORD Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    प्रकार काष्ठा _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      WORD संख्या_Of_Named_Entries;
      WORD संख्या_Of_Id_Entries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#घोषणा IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#घोषणा IMAGE_RESOURCE_तथ्य_IS_DIRECTORY 0x80000000

    प्रकार काष्ठा _IMAGE_RESOURCE_DIRECTORY_ENTRY {
      जोड़ {
	काष्ठा {
	  DWORD NameOffset:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	WORD Id;
      };
      जोड़ {
	DWORD Offset_To_तथ्य;
	काष्ठा {
	  DWORD OffsetToDirectory:31;
	  DWORD तथ्य_Is_Directory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_ENTRY,*PIMAGE_RESOURCE_DIRECTORY_ENTRY;

    प्रकार काष्ठा _IMAGE_RESOURCE_DIRECTORY_STRING {
      WORD लंबाई_2;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    प्रकार काष्ठा _IMAGE_RESOURCE_DIR_STRING_U {
      WORD लंबाई_2;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    प्रकार काष्ठा IMAGE_RESOURCE_तथ्य_ENTRY {
      DWORD Offset_To_तथ्य;
      DWORD आकार_3;
      DWORD CodePage;
      DWORD Reserved;
    } IMAGE_RESOURCE_तथ्य_ENTRY_2,*PIMAGE_RESOURCE_तथ्य_ENTRY;

    प्रकार काष्ठा {
      DWORD आकार_3;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      DWORD GlobalFlagsClear;
      DWORD GlobalFlagsSet;
      DWORD CriticalSectionDefaultTimeout;
      DWORD DeCommitFreeBlockThreshold;
      DWORD De_Commit_योग_Free_Threshold;
      DWORD LockPrefixTable;
      DWORD Maximum_Allocation_आकार;
      DWORD VirtualMemoryThreshold;
      DWORD ProcessHeapFlags;
      DWORD ProcessAffinityMask;
      WORD CSDVersion;
      WORD Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandlerTable;
      DWORD SEHandler_गिनती;
    } IMAGE_LOAD_CONFIG_DIRECTORY32,*PIMAGE_LOAD_CONFIG_DIRECTORY32;

    प्रकार काष्ठा {
      DWORD आकार_3;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      DWORD GlobalFlagsClear;
      DWORD GlobalFlagsSet;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG DeCommitFreeBlockThreshold;
      ULONGLONG De_Commit_योग_Free_Threshold;
      ULONGLONG LockPrefixTable;
      ULONGLONG Maximum_Allocation_आकार;
      ULONGLONG VirtualMemoryThreshold;
      ULONGLONG ProcessAffinityMask;
      DWORD ProcessHeapFlags;
      WORD CSDVersion;
      WORD Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandlerTable;
      ULONGLONG SEHandler_गिनती;
    } IMAGE_LOAD_CONFIG_DIRECTORY64,*PIMAGE_LOAD_CONFIG_DIRECTORY64;

#अगर_घोषित _WIN64
    प्रकार IMAGE_LOAD_CONFIG_DIRECTORY64 IMAGE_LOAD_CONFIG_DIRECTORY;
    प्रकार PIMAGE_LOAD_CONFIG_DIRECTORY64 PIMAGE_LOAD_CONFIG_DIRECTORY;
#अन्यथा
    प्रकार IMAGE_LOAD_CONFIG_DIRECTORY32 IMAGE_LOAD_CONFIG_DIRECTORY;
    प्रकार PIMAGE_LOAD_CONFIG_DIRECTORY32 PIMAGE_LOAD_CONFIG_DIRECTORY;
#पूर्ण_अगर

    प्रकार काष्ठा _IMAGE_CE_RUNTIME_FUNCTION_ENTRY {
      DWORD FuncStart;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD ThirtyTwoBit : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_ENTRY,*PIMAGE_CE_RUNTIME_FUNCTION_ENTRY;

    प्रकार काष्ठा _IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY {
      ULONGLONG BeginAddress;
      ULONGLONG EndAddress;
      ULONGLONG ExceptionHandler;
      ULONGLONG Handler_तथ्य;
      ULONGLONG PrologEndAddress;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY;

    प्रकार काष्ठा _IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD ExceptionHandler;
      DWORD Handler_तथ्य;
      DWORD PrologEndAddress;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY,*PIMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY;

    प्रकार काष्ठा _IMAGE_RUNTIME_FUNCTION_ENTRY {
      DWORD BeginAddress;
      DWORD EndAddress;
      DWORD UnwindInfoAddress;
    } _IMAGE_RUNTIME_FUNCTION_ENTRY,*_PIMAGE_RUNTIME_FUNCTION_ENTRY;

    प्रकार _IMAGE_RUNTIME_FUNCTION_ENTRY IMAGE_IA64_RUNTIME_FUNCTION_ENTRY;
    प्रकार _PIMAGE_RUNTIME_FUNCTION_ENTRY PIMAGE_IA64_RUNTIME_FUNCTION_ENTRY;

    प्रकार _IMAGE_RUNTIME_FUNCTION_ENTRY IMAGE_RUNTIME_FUNCTION_ENTRY;
    प्रकार _PIMAGE_RUNTIME_FUNCTION_ENTRY PIMAGE_RUNTIME_FUNCTION_ENTRY;

    प्रकार काष्ठा _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD TimeDateStamp;
      WORD MajorVersion;
      WORD MinorVersion;
      DWORD Type;
      DWORD आकार_Of_तथ्य;
      DWORD Address_Of_Raw_तथ्य;
      DWORD Pointer_To_Raw_तथ्य;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#घोषणा IMAGE_DEBUG_TYPE_UNKNOWN 0
#घोषणा IMAGE_DEBUG_TYPE_COFF 1
#घोषणा IMAGE_DEBUG_TYPE_CODEVIEW 2
#घोषणा IMAGE_DEBUG_TYPE_FPO 3
#घोषणा IMAGE_DEBUG_TYPE_MISC 4
#घोषणा IMAGE_DEBUG_TYPE_EXCEPTION 5
#घोषणा IMAGE_DEBUG_TYPE_FIXUP 6
#घोषणा IMAGE_DEBUG_TYPE_OMAP_TO_SRC 7
#घोषणा IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#घोषणा IMAGE_DEBUG_TYPE_BORLAND 9
#घोषणा IMAGE_DEBUG_TYPE_RESERVED10 10
#घोषणा IMAGE_DEBUG_TYPE_CLSID 11

    प्रकार काष्ठा _IMAGE_COFF_SYMBOLS_HEADER {
      DWORD संख्या_Of_Symbols;
      DWORD Lva_To_First_प्रतीक;
      DWORD संख्या_Of_Linenumbers;
      DWORD LvaToFirstLinenumber;
      DWORD RvaToFirstByteOfCode;
      DWORD RvaToLastByteOfCode;
      DWORD Rva_To_First_Byte_Of_तथ्य;
      DWORD Rva_To_Last_Byte_Of_तथ्य;
    } IMAGE_COFF_SYMBOLS_HEADER,*PIMAGE_COFF_SYMBOLS_HEADER;

#घोषणा FRAME_FPO 0
#घोषणा FRAME_TRAP 1
#घोषणा FRAME_TSS 2
#घोषणा FRAME_NONFPO 3

    प्रकार काष्ठा FPO_तथ्य {
      DWORD ulOffStart;
      DWORD cb_Proc_आकार;
      DWORD cdwLocals;
      WORD cdwParams;
      WORD cbProlog : 8;
      WORD cbRegs : 3;
      WORD fHasSEH : 1;
      WORD fUseBP : 1;
      WORD reserved : 1;
      WORD cbFrame : 2;
    } FPO_तथ्य_2,*PFPO_तथ्य;
#घोषणा SIZEOF_RFPO_तथ्य 16

#घोषणा IMAGE_DEBUG_MISC_EXENAME 1

    प्रकार काष्ठा _IMAGE_DEBUG_MISC {
      DWORD तथ्य_Type;
      DWORD लंबाई_2;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE तथ्य_3[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    प्रकार काष्ठा _IMAGE_FUNCTION_ENTRY {
      DWORD StartingAddress;
      DWORD EndingAddress;
      DWORD EndOfPrologue;
    } IMAGE_FUNCTION_ENTRY,*PIMAGE_FUNCTION_ENTRY;

    प्रकार काष्ठा _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG StartingAddress;
      ULONGLONG EndingAddress;
      जोड़ {
	ULONGLONG EndOfPrologue;
	ULONGLONG UnwindInfoAddress;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    प्रकार काष्ठा _IMAGE_SEPARATE_DEBUG_HEADER {
      WORD Signature;
      WORD Flags;
      WORD Machine;
      WORD Characteristics;
      DWORD TimeDateStamp;
      DWORD Check_योग;
      DWORD ImageBase;
      DWORD आकार_Of_Image;
      DWORD संख्या_Of_Sections;
      DWORD Exported_Names_आकार;
      DWORD Debug_Directory_आकार;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_HEADER,*PIMAGE_SEPARATE_DEBUG_HEADER;

    प्रकार काष्ठा _NON_PAGED_DEBUG_INFO {
      WORD Signature;
      WORD Flags;
      DWORD आकार_3;
      WORD Machine;
      WORD Characteristics;
      DWORD TimeDateStamp;
      DWORD Check_योग;
      DWORD आकार_Of_Image;
      ULONGLONG ImageBase;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#घोषणा IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#घोषणा NON_PAGED_DEBUG_SIGNATURE 0x494E

#घोषणा IMAGE_SEPARATE_DEBUG_FLAGS_MASK 0x8000
#घोषणा IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    प्रकार काष्ठा _ImageArchitectureHeader {
      अचिन्हित पूर्णांक Amask_मूल्य: 1;
      पूर्णांक Adummy1 :7;
      अचिन्हित पूर्णांक AmaskShift: 8;
      पूर्णांक Adummy2 :16;
      DWORD FirstEntryRVA;
    } IMAGE_ARCHITECTURE_HEADER,*PIMAGE_ARCHITECTURE_HEADER;

    प्रकार काष्ठा _ImageArchitectureEntry {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_ENTRY,*PIMAGE_ARCHITECTURE_ENTRY;

#समावेश "poppack.h"

#घोषणा IMPORT_OBJECT_HDR_SIG2 0xffff

    प्रकार काष्ठा IMPORT_OBJECT_HEADER {
      WORD Sig1;
      WORD Sig2;
      WORD Version;
      WORD Machine;
      DWORD TimeDateStamp;
      DWORD आकार_Of_तथ्य;
      जोड़ {
	WORD Ordinal;
	WORD Hint;
      };
      WORD Type : 2;
      WORD NameType : 3;
      WORD Reserved : 11;
    } IMPORT_OBJECT_HEADER;

    प्रकार क्रमागत IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_CODE = 0,IMPORT_OBJECT_तथ्य = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    प्रकार क्रमागत IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_PREFIX = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#अगर_अघोषित __IMAGE_COR20_HEADER_DEFINED__
#घोषणा __IMAGE_COR20_HEADER_DEFINED__
    प्रकार क्रमागत ReplacesCorHdrNumericDefines {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_VERSION_MAJOR_V2 =2,
      COR_VERSION_MAJOR =COR_VERSION_MAJOR_V2,COR_VERSION_MINOR =0,COR_DELETED_NAME_लंबाई =8,COR_VTABLEGAP_NAME_लंबाई =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32BIT =0x01,COR_VTABLE_64BIT =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_आकार =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } ReplacesCorHdrNumericDefines;

    प्रकार काष्ठा IMAGE_COR20_HEADER {
      DWORD cb;
      WORD MajorRuntimeVersion;
      WORD MinorRuntimeVersion;
      IMAGE_तथ्य_DIRECTORY_2 Meta_तथ्य;
      DWORD Flags;
      DWORD EntryPointToken;
      IMAGE_तथ्य_DIRECTORY_2 Resources;
      IMAGE_तथ्य_DIRECTORY_2 StrongNameSignature;
      IMAGE_तथ्य_DIRECTORY_2 CodeManagerTable;
      IMAGE_तथ्य_DIRECTORY_2 VTableFixups;
      IMAGE_तथ्य_DIRECTORY_2 ExportAddressTableJumps;
      IMAGE_तथ्य_DIRECTORY_2 ManagedNativeHeader;
    } IMAGE_COR20_HEADER,*PIMAGE_COR20_HEADER;
#पूर्ण_अगर

#अगर defined (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI RtlLookupFunctionEntry (DWORD64 ControlPc, PDWORD64 ImageBase, PUNWIND_HISTORY_TABLE HistoryTable);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID Return_मूल्य_2, PCONTEXT ContextRecord, PUNWIND_HISTORY_TABLE HistoryTable);
#पूर्ण_अगर

#समावेश <string.h>

#अगर_अघोषित _SLIST_HEADER_
#घोषणा _SLIST_HEADER_

#अगर_घोषित _WIN64
    प्रकार काष्ठा _SLIST_ENTRY *PSLIST_ENTRY;
    प्रकार काष्ठा DECLSPEC_ALIGN(16) _SLIST_ENTRY {
      PSLIST_ENTRY अग्र_2;
    } SLIST_ENTRY;
#अन्यथा

#घोषणा SLIST_ENTRY SINGLE_LIST_ENTRY
#घोषणा _SLIST_ENTRY _SINGLE_LIST_ENTRY
#घोषणा PSLIST_ENTRY PSINGLE_LIST_ENTRY
#पूर्ण_अगर

#अगर defined(_WIN64)

    प्रकार काष्ठा DECLSPEC_ALIGN(16) _SLIST_HEADER {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_HEADER;

    प्रकार काष्ठा _SLIST_HEADER *PSLIST_HEADER;
#अन्यथा

    प्रकार जोड़ _SLIST_HEADER {
      ULONGLONG Alignment;
      काष्ठा {
	SLIST_ENTRY अग्र_2;
	WORD Depth;
	WORD Sequence;
      };
    } SLIST_HEADER,*PSLIST_HEADER;
#पूर्ण_अगर
#पूर्ण_अगर

    NTSYSAPI VOID NTAPI Rtl_Initialize_SList_शीर्ष(PSLIST_HEADER List_शीर्ष);
    NTSYSAPI PSLIST_ENTRY NTAPI RtlFirstEntrySList(स्थिर SLIST_HEADER *List_शीर्ष);
    NTSYSAPI PSLIST_ENTRY NTAPI Rtl_Interlocked_निकालो_Entry_SList(PSLIST_HEADER List_शीर्ष);
    NTSYSAPI PSLIST_ENTRY NTAPI Rtl_Interlocked_धकेलो_Entry_SList(PSLIST_HEADER List_शीर्ष,PSLIST_ENTRY ListEntry);
    NTSYSAPI PSLIST_ENTRY NTAPI RtlInterlockedFlushSList(PSLIST_HEADER List_शीर्ष);
    NTSYSAPI WORD NTAPI RtlQueryDepthSList(PSLIST_HEADER List_शीर्ष);

#घोषणा HEAP_NO_SERIALIZE 0x00000001
#घोषणा HEAP_GROWABLE 0x00000002
#घोषणा HEAP_GENERATE_EXCEPTIONS 0x00000004
#घोषणा HEAP_ZERO_MEMORY 0x00000008
#घोषणा HEAP_REALLOC_IN_PLACE_ONLY 0x00000010
#घोषणा HEAP_पुच्छ_CHECKING_ENABLED 0x00000020
#घोषणा HEAP_FREE_CHECKING_ENABLED 0x00000040
#घोषणा HEAP_DISABLE_COALESCE_ON_FREE 0x00000080
#घोषणा HEAP_CREATE_ALIGN_16 0x00010000
#घोषणा HEAP_CREATE_ENABLE_TRACING 0x00020000
#घोषणा HEAP_CREATE_ENABLE_EXECUTE 0x00040000
#घोषणा HEAP_MAXIMUM_TAG 0x0FFF
#घोषणा HEAP_PSEUDO_TAG_FLAG 0x8000
#घोषणा HEAP_TAG_SHIFT 18
#घोषणा HEAP_MAKE_TAG_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT ContextRecord);

#घोषणा IS_TEXT_UNICODE_ASCII16 0x0001
#घोषणा IS_TEXT_UNICODE_REVERSE_ASCII16 0x0010

#घोषणा IS_TEXT_UNICODE_STATISTICS 0x0002
#घोषणा IS_TEXT_UNICODE_REVERSE_STATISTICS 0x0020

#घोषणा IS_TEXT_UNICODE_CONTROLS 0x0004
#घोषणा IS_TEXT_UNICODE_REVERSE_CONTROLS 0x0040

#घोषणा IS_TEXT_UNICODE_SIGNATURE 0x0008
#घोषणा IS_TEXT_UNICODE_REVERSE_SIGNATURE 0x0080

#घोषणा IS_TEXT_UNICODE_ILLEGAL_CHARS 0x0100
#घोषणा IS_TEXT_UNICODE_ODD_लंबाई 0x0200
#घोषणा IS_TEXT_UNICODE_DBCS_LEADBYTE 0x0400
#घोषणा IS_TEXT_UNICODE_NULL_BYTES 0x1000

#घोषणा IS_TEXT_UNICODE_UNICODE_MASK 0x000F
#घोषणा IS_TEXT_UNICODE_REVERSE_MASK 0x00F0
#घोषणा IS_TEXT_UNICODE_NOT_UNICODE_MASK 0x0F00
#घोषणा IS_TEXT_UNICODE_NOT_ASCII_MASK 0xF000

#घोषणा COMPRESSION_FORMAT_NONE (0x0000)
#घोषणा COMPRESSION_FORMAT_DEFAULT (0x0001)
#घोषणा COMPRESSION_FORMAT_LZNT1 (0x0002)
#घोषणा COMPRESSION_ENGINE_STANDARD (0x0000)
#घोषणा COMPRESSION_ENGINE_MAXIMUM (0x0100)
#घोषणा COMPRESSION_ENGINE_HIBER (0x0200)

#अगर _DBG_MEMCPY_INLINE_ && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
#घोषणा _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(व्योम *dst,स्थिर व्योम *src,माप_प्रकार आकार) {
      अगर(((अक्षर *)dst > (अक्षर *)src) && ((अक्षर *)dst < ((अक्षर *)src + आकार))) {
	__debugbreak();
      }
      वापस स_नकल(dst,src,आकार);
    }
#घोषणा स_नकल memcpy_inline
#पूर्ण_अगर

    NTSYSAPI आकार_T NTAPI RtlCompareMemory(स्थिर VOID *Source1,स्थिर VOID *Source2,आकार_T लंबाई_2);

#घोषणा RtlEqualMemory(Destination,Source,लंबाई_2) (!स_भेद((Destination),(Source),(लंबाई_2)))
#घोषणा RtlMoveMemory(Destination,Source,लंबाई_2) स_हटाओ((Destination),(Source),(लंबाई_2))
#घोषणा RtlCopyMemory(Destination,Source,लंबाई_2) स_नकल((Destination),(Source),(लंबाई_2))
#घोषणा RtlFillMemory(Destination,लंबाई_2,Fill) स_रखो((Destination),(Fill),(लंबाई_2))
#घोषणा RtlZeroMemory(Destination,लंबाई_2) स_रखो((Destination),0,(लंबाई_2))

    __CRT_INLINE PVOID RtlSecureZeroMemory(PVOID ptr,आकार_T cnt) {
      अस्थिर अक्षर *vptr =(अस्थिर अक्षर *)ptr;
#अगर_घोषित __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#अन्यथा
      जबतक(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#पूर्ण_अगर
      वापस ptr;
    }

    प्रकार काष्ठा _MESSAGE_RESOURCE_ENTRY {
      WORD लंबाई_2;
      WORD Flags;
      BYTE Text[1];
    } MESSAGE_RESOURCE_ENTRY,*PMESSAGE_RESOURCE_ENTRY;

#घोषणा MESSAGE_RESOURCE_UNICODE 0x0001

    प्रकार काष्ठा _MESSAGE_RESOURCE_BLOCK {
      DWORD निचला_Id;
      DWORD ऊपरी_Id;
      DWORD OffsetToEntries;
    } MESSAGE_RESOURCE_BLOCK,*PMESSAGE_RESOURCE_BLOCK;

    प्रकार काष्ठा MESSAGE_RESOURCE_तथ्य {
      DWORD संख्या_Of_Blocks;
      MESSAGE_RESOURCE_BLOCK Blocks[1];
    } MESSAGE_RESOURCE_तथ्य_2,*PMESSAGE_RESOURCE_तथ्य;

    प्रकार काष्ठा _OSVERSIONINFOA {
      DWORD dw_OSVersion_Info_आकार;
      DWORD dwMajorVersion;
      DWORD dwMinorVersion;
      DWORD dw_Build_संख्या;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    प्रकार काष्ठा _OSVERSIONINFOW {
      DWORD dw_OSVersion_Info_आकार;
      DWORD dwMajorVersion;
      DWORD dwMinorVersion;
      DWORD dw_Build_संख्या;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#अगर_घोषित UNICODE
    प्रकार OSVERSIONINFOW OSVERSIONINFO;
    प्रकार POSVERSIONINFOW POSVERSIONINFO;
    प्रकार LPOSVERSIONINFOW LPOSVERSIONINFO;
#अन्यथा
    प्रकार OSVERSIONINFOA OSVERSIONINFO;
    प्रकार POSVERSIONINFOA POSVERSIONINFO;
    प्रकार LPOSVERSIONINFOA LPOSVERSIONINFO;
#पूर्ण_अगर

    प्रकार काष्ठा _OSVERSIONINFOEXA {
      DWORD dw_OSVersion_Info_आकार;
      DWORD dwMajorVersion;
      DWORD dwMinorVersion;
      DWORD dw_Build_संख्या;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      WORD wServicePackMajor;
      WORD wServicePackMinor;
      WORD wSuiteMask;
      BYTE wProductType;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    प्रकार काष्ठा _OSVERSIONINFOEXW {
      DWORD dw_OSVersion_Info_आकार;
      DWORD dwMajorVersion;
      DWORD dwMinorVersion;
      DWORD dw_Build_संख्या;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      WORD wServicePackMajor;
      WORD wServicePackMinor;
      WORD wSuiteMask;
      BYTE wProductType;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#अगर_घोषित UNICODE
    प्रकार OSVERSIONINFOEXW OSVERSIONINFOEX;
    प्रकार POSVERSIONINFOEXW POSVERSIONINFOEX;
    प्रकार LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#अन्यथा
    प्रकार OSVERSIONINFOEXA OSVERSIONINFOEX;
    प्रकार POSVERSIONINFOEXA POSVERSIONINFOEX;
    प्रकार LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#पूर्ण_अगर

#घोषणा VER_EQUAL 1
#घोषणा VER_GREATER 2
#घोषणा VER_GREATER_EQUAL 3
#घोषणा VER_LESS 4
#घोषणा VER_LESS_EQUAL 5
#घोषणा VER_AND 6
#घोषणा VER_OR 7

#घोषणा VER_CONDITION_MASK 7
#घोषणा VER_अंक_BITS_PER_CONDITION_MASK 3

#घोषणा VER_MINORVERSION 0x0000001
#घोषणा VER_MAJORVERSION 0x0000002
#घोषणा VER_BUILDNUMBER 0x0000004
#घोषणा VER_PLATFORMID 0x0000008
#घोषणा VER_SERVICEPACKMINOR 0x0000010
#घोषणा VER_SERVICEPACKMAJOR 0x0000020
#घोषणा VER_SUITENAME 0x0000040
#घोषणा VER_PRODUCT_TYPE 0x0000080

#घोषणा VER_NT_WORKSTATION 0x0000001
#घोषणा VER_NT_DOMAIN_CONTROLLER 0x0000002
#घोषणा VER_NT_SERVER 0x0000003

#घोषणा VER_PLATFORM_WIN32s 0
#घोषणा VER_PLATFORM_WIN32_WINDOWS 1
#घोषणा VER_PLATFORM_WIN32_NT 2

#घोषणा VER_SET_CONDITION(_m_,_t_,_c_) ((_m_)=VerSetConditionMask((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI VerSetConditionMask(ULONGLONG ConditionMask,DWORD TypeMask,BYTE Condition);

    प्रकार काष्ठा _RTL_CRITICAL_SECTION_DEBUG {
      WORD Type;
      WORD Creator_Back_Trace_सूचकांक;
      काष्ठा _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_ENTRY ProcessLocksList;
      DWORD Entry_गिनती;
      DWORD Contention_गिनती;
      DWORD Spare[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#घोषणा RTL_CRITSECT_TYPE 0
#घोषणा RTL_RESOURCE_TYPE 1

    प्रकार काष्ठा _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG Lock_गिनती;
      LONG Recursion_गिनती;
      HANDLE OwningThread;
      HANDLE LockSemaphore;
      ULONG_PTR Spin_गिनती;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    प्रकार VOID (NTAPI *RTL_VERIFIER_DLL_LOAD_CALLBACK) (PWSTR DllName,PVOID DllBase,आकार_T Dll_आकार,PVOID Reserved);
    प्रकार VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID DllBase,आकार_T Dll_आकार,PVOID Reserved);
    प्रकार VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID AllocationBase,आकार_T Allocation_आकार);

    प्रकार काष्ठा _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID ThunkOldAddress;
      PVOID ThunkNewAddress;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    प्रकार काष्ठा _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID DllAddress;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    प्रकार काष्ठा _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD लंबाई_2;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_LOAD_CALLBACK ProviderDllLoadCallback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID Rtlp_Get_ढेर_Trace_Address;
      PVOID RtlpDebugPageHeapCreate;
      PVOID RtlpDebugPageHeapDestroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK ProviderNtdllHeapFreeCallback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#घोषणा RTL_VRF_FLG_FULL_PAGE_HEAP 0x00000001
#घोषणा RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#घोषणा RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#घोषणा RTL_VRF_FLG_ढेर_CHECKS 0x00000008
#घोषणा RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#घोषणा RTL_VRF_FLG_TLS_CHECKS 0x00000020
#घोषणा RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#घोषणा RTL_VRF_FLG_RPC_CHECKS 0x00000080
#घोषणा RTL_VRF_FLG_COM_CHECKS 0x00000100
#घोषणा RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#घोषणा RTL_VRF_FLG_RACE_CHECKS 0x00000400
#घोषणा RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#घोषणा RTL_VRF_FLG_FIRST_CHANCE_EXCEPTION_CHECKS 0x00001000
#घोषणा RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#घोषणा RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#घोषणा RTL_VRF_FLG_FAST_FILL_HEAP 0x00008000
#घोषणा RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#घोषणा RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#घोषणा RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#घोषणा RTL_VRF_FLG_LOCK_CHECKS 0x00040000

#घोषणा APPLICATION_VERIFIER_INTERNAL_ERROR 0x80000000
#घोषणा APPLICATION_VERIFIER_INTERNAL_WARNING 0x40000000
#घोषणा APPLICATION_VERIFIER_NO_BREAK 0x20000000
#घोषणा APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#घोषणा APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#घोषणा APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#घोषणा APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#घोषणा APPLICATION_VERIFIER_EXTREME_आकार_REQUEST 0x0004
#घोषणा APPLICATION_VERIFIER_BAD_HEAP_HANDLE 0x0005
#घोषणा APPLICATION_VERIFIER_SWITCHED_HEAP_HANDLE 0x0006
#घोषणा APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#घोषणा APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK 0x0008
#घोषणा APPLICATION_VERIFIER_DESTROY_PROCESS_HEAP 0x0009
#घोषणा APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#घोषणा APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_EXCEPTION_RAISED_FOR_HEADER 0x000B
#घोषणा APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_EXCEPTION_RAISED_FOR_PROBING 0x000C
#घोषणा APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_HEADER 0x000D
#घोषणा APPLICATION_VERIFIER_CORRUPTED_FREED_HEAP_BLOCK 0x000E
#घोषणा APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_SUFFIX 0x000F
#घोषणा APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_START_STAMP 0x0010
#घोषणा APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_END_STAMP 0x0011
#घोषणा APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_PREFIX 0x0012
#घोषणा APPLICATION_VERIFIER_FIRST_CHANCE_ACCESS_VIOLATION 0x0013
#घोषणा APPLICATION_VERIFIER_CORRUPTED_HEAP_LIST 0x0014

#घोषणा APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#घोषणा APPLICATION_VERIFIER_ढेर_OVERFLOW 0x0101
#घोषणा APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#घोषणा APPLICATION_VERIFIER_EXIT_THREAD_OWNS_LOCK 0x0200
#घोषणा APPLICATION_VERIFIER_LOCK_IN_UNLOADED_DLL 0x0201
#घोषणा APPLICATION_VERIFIER_LOCK_IN_FREED_HEAP 0x0202
#घोषणा APPLICATION_VERIFIER_LOCK_DOUBLE_INITIALIZE 0x0203
#घोषणा APPLICATION_VERIFIER_LOCK_IN_FREED_MEMORY 0x0204
#घोषणा APPLICATION_VERIFIER_LOCK_CORRUPTED 0x0205
#घोषणा APPLICATION_VERIFIER_LOCK_INVALID_OWNER 0x0206
#घोषणा APPLICATION_VERIFIER_LOCK_INVALID_RECURSION_गिनती 0x0207
#घोषणा APPLICATION_VERIFIER_LOCK_INVALID_LOCK_गिनती 0x0208
#घोषणा APPLICATION_VERIFIER_LOCK_OVER_RELEASED 0x0209
#घोषणा APPLICATION_VERIFIER_LOCK_NOT_INITIALIZED 0x0210
#घोषणा APPLICATION_VERIFIER_LOCK_ALREADY_INITIALIZED 0x0211
#घोषणा APPLICATION_VERIFIER_LOCK_IN_FREED_VMEM 0x0212
#घोषणा APPLICATION_VERIFIER_LOCK_IN_UNMAPPED_MEM 0x0213
#घोषणा APPLICATION_VERIFIER_THREAD_NOT_LOCK_OWNER 0x0214

#घोषणा APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#घोषणा APPLICATION_VERIFIER_INVALID_TLS_मूल्य 0x0301
#घोषणा APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#घोषणा APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#घोषणा APPLICATION_VERIFIER_WAIT_IN_DLLMAIN 0x0304

#घोषणा APPLICATION_VERIFIER_COM_ERROR 0x0400
#घोषणा APPLICATION_VERIFIER_COM_API_IN_DLLMAIN 0x0401
#घोषणा APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#घोषणा APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#घोषणा APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#घोषणा APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#घोषणा APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#घोषणा APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#घोषणा APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#घोषणा APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#घोषणा APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#घोषणा APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#घोषणा APPLICATION_VERIFIER_COM_OBJECT_IN_FREED_MEMORY 0x040C
#घोषणा APPLICATION_VERIFIER_COM_OBJECT_IN_UNLOADED_DLL 0x040D
#घोषणा APPLICATION_VERIFIER_COM_VTBL_IN_FREED_MEMORY 0x040E
#घोषणा APPLICATION_VERIFIER_COM_VTBL_IN_UNLOADED_DLL 0x040F
#घोषणा APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#घोषणा APPLICATION_VERIFIER_RPC_ERROR 0x0500

#घोषणा APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#घोषणा APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#घोषणा APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#घोषणा APPLICATION_VERIFIER_PROBE_INVALID_ADDRESS 0x0603
#घोषणा APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#घोषणा APPLICATION_VERIFIER_PROBE_GUARD_PAGE 0x0605
#घोषणा APPLICATION_VERIFIER_PROBE_NULL 0x0606
#घोषणा APPLICATION_VERIFIER_PROBE_INVALID_START_OR_आकार 0x0607
#घोषणा APPLICATION_VERIFIER_आकार_HEAP_UNEXPECTED_EXCEPTION 0x0618

#घोषणा VERIFIER_STOP(Code,संदेश_3,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((Code),(संदेश_3),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR Code,PSTR Message,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    प्रकार LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(काष्ठा _EXCEPTION_POINTERS *ExceptionInfo);
#घोषणा SEF_DACL_AUTO_INHERIT 0x01
#घोषणा SEF_SACL_AUTO_INHERIT 0x02
#घोषणा SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#घोषणा SEF_AVOID_PRIVILEGE_CHECK 0x08
#घोषणा SEF_AVOID_OWNER_CHECK 0x10
#घोषणा SEF_DEFAULT_OWNER_FROM_PARENT 0x20
#घोषणा SEF_DEFAULT_GROUP_FROM_PARENT 0x40

    प्रकार क्रमागत _HEAP_INFORMATION_CLASS {
      HeapCompatibilityInformation
    } HEAP_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI RtlSetHeapInformation(PVOID HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,आकार_T Heap_Information_लंबाई);
    NTSYSAPI DWORD NTAPI RtlQueryHeapInformation(PVOID HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,आकार_T Heap_Information_लंबाई,PSIZE_T Return_लंबाई);
    DWORD NTAPI RtlMultipleAllocateHeap(PVOID HeapHandle,DWORD Flags,आकार_T आकार_3,DWORD गिनती_3,PVOID *Array);
    DWORD NTAPI RtlMultipleFreeHeap(PVOID HeapHandle,DWORD Flags,DWORD गिनती_3,PVOID *Array);

#घोषणा WT_EXECUTEDEFAULT 0x00000000
#घोषणा WT_EXECUTEINIOTHREAD 0x00000001
#घोषणा WT_EXECUTEINUITHREAD 0x00000002
#घोषणा WT_EXECUTEINWAITTHREAD 0x00000004
#घोषणा WT_EXECUTEONLYONCE 0x00000008
#घोषणा WT_EXECUTEINTIMERTHREAD 0x00000020
#घोषणा WT_EXECUTELONGFUNCTION 0x00000010
#घोषणा WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#घोषणा WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#घोषणा WT_TRANSFER_IMPERSONATION 0x00000100
#घोषणा WT_SET_MAX_THREADPOOL_THREADS(Flags,Limit) ((Flags) |= (Limit)<<16)
    प्रकार VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    प्रकार VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    प्रकार VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    प्रकार
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lp_Fls_तथ्य);
#घोषणा WT_EXECUTEINLONGTHREAD 0x00000010
#घोषणा WT_EXECUTEDELETEWAIT 0x00000008

    प्रकार क्रमागत _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,AssemblyDetailedInformationInActivationContext = 3,FileInformationInAssemblyOfAssemblyInActivationContext = 4,MaxActivationContextInfoClass,AssemblyDetailedInformationInActivationContxt = 3,FileInformationInAssemblyOfAssemblyInActivationContxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#घोषणा ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    प्रकार काष्ठा ACTIVATION_CONTEXT_QUERY_सूचकांक {
      DWORD ul_Assembly_सूचकांक;
      DWORD ul_File_सूचकांक_In_Assembly;
    } ACTIVATION_CONTEXT_QUERY_सूचकांक_2,*PACTIVATION_CONTEXT_QUERY_सूचकांक;

    प्रकार स्थिर काष्ठा ACTIVATION_CONTEXT_QUERY_सूचकांक *PCACTIVATION_CONTEXT_QUERY_सूचकांक;

#घोषणा ACTIVATION_CONTEXT_PATH_TYPE_NONE (1)
#घोषणा ACTIVATION_CONTEXT_PATH_TYPE_WIN32_FILE (2)
#घोषणा ACTIVATION_CONTEXT_PATH_TYPE_URL (3)
#घोषणा ACTIVATION_CONTEXT_PATH_TYPE_ASSEMBLYREF (4)

    प्रकार काष्ठा _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Filename_लंबाई;
      DWORD ul_Path_लंबाई;

      PCWSTR lpFileName;
      PCWSTR lpFilePath;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    प्रकार स्थिर ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#घोषणा _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#घोषणा ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#घोषणा PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#घोषणा PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    प्रकार काष्ठा _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Encoded_Assembly_Identity_लंबाई;
      DWORD ulManifestPathType;
      DWORD ul_Manifest_Path_लंबाई;
      LARGE_INTEGER liManifestLastWriteTime;
      DWORD ulPolicyPathType;
      DWORD ul_Policy_Path_लंबाई;
      LARGE_INTEGER liPolicyLastWriteTime;
      DWORD ul_Metadata_Satellite_Roster_सूचकांक;
      DWORD ulManifestVersionMajor;
      DWORD ulManifestVersionMinor;
      DWORD ulPolicyVersionMajor;
      DWORD ulPolicyVersionMinor;
      DWORD ul_Assembly_Directory_Name_लंबाई;
      PCWSTR lpAssemblyEncodedAssemblyIdentity;
      PCWSTR lpAssemblyManifestPath;
      PCWSTR lpAssemblyPolicyPath;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ul_File_गिनती;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    प्रकार स्थिर काष्ठा _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    प्रकार काष्ठा _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ulFormatVersion;
      DWORD ul_Assembly_गिनती;
      DWORD ul_मूल_Manifest_Path_Type;
      DWORD ul_मूल_Manifest_Path_Chars;
      DWORD ul_मूल_Configuration_Path_Type;
      DWORD ul_मूल_Configuration_Path_Chars;
      DWORD ulAppDirPathType;
      DWORD ulAppDirPathChars;
      PCWSTR lp_मूल_Manifest_Path;
      PCWSTR lp_मूल_Configuration_Path;
      PCWSTR lpAppDirPath;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    प्रकार स्थिर काष्ठा _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#घोषणा DLL_PROCESS_ATTACH 1
#घोषणा DLL_THREAD_ATTACH 2
#घोषणा DLL_THREAD_DETACH 3
#घोषणा DLL_PROCESS_DETACH 0
#घोषणा DLL_PROCESS_VERIFIER 4

#घोषणा EVENTLOG_SEQUENTIAL_READ 0x0001
#घोषणा EVENTLOG_SEEK_READ 0x0002
#घोषणा EVENTLOG_FORWARDS_READ 0x0004
#घोषणा EVENTLOG_BACKWARDS_READ 0x0008

#घोषणा EVENTLOG_SUCCESS 0x0000
#घोषणा EVENTLOG_ERROR_TYPE 0x0001
#घोषणा EVENTLOG_WARNING_TYPE 0x0002
#घोषणा EVENTLOG_INFORMATION_TYPE 0x0004
#घोषणा EVENTLOG_AUDIT_SUCCESS 0x0008
#घोषणा EVENTLOG_AUDIT_FAILURE 0x0010

#घोषणा EVENTLOG_START_PAIRED_EVENT 0x0001
#घोषणा EVENTLOG_END_PAIRED_EVENT 0x0002
#घोषणा EVENTLOG_END_ALL_PAIRED_EVENTS 0x0004
#घोषणा EVENTLOG_PAIRED_EVENT_ACTIVE 0x0008
#घोषणा EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    प्रकार काष्ठा _EVENTLOGRECORD {
      DWORD लंबाई_2;
      DWORD Reserved;
      DWORD Record_संख्या;
      DWORD TimeGenerated;
      DWORD TimeWritten;
      DWORD EventID;
      WORD EventType;
      WORD अंक_Strings;
      WORD EventCategory;
      WORD ReservedFlags;
      DWORD Closing_Record_संख्या;
      DWORD StringOffset;
      DWORD User_Sid_लंबाई;
      DWORD UserSidOffset;
      DWORD तथ्य_लंबाई;
      DWORD तथ्य_Offset;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#घोषणा MAXLOGICALLOGNAMESIZE 256

    प्रकार काष्ठा _EVENTSFORLOGFILE{
      DWORD ul_आकार;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ul_अंक_Records;
      EVENTLOGRECORD pEventLogRecords[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    प्रकार काष्ठा _PACKEDEVENTINFO{
      DWORD ul_आकार;
      DWORD ul_अंक_Events_For_Log_File;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#घोषणा कुंजी_QUERY_मूल्य (0x0001)
#घोषणा कुंजी_SET_मूल्य (0x0002)
#घोषणा कुंजी_CREATE_SUB_कुंजी (0x0004)
#घोषणा कुंजी_ENUMERATE_SUB_कुंजियाँ (0x0008)
#घोषणा कुंजी_NOTIFY (0x0010)
#घोषणा कुंजी_CREATE_LINK (0x0020)
#घोषणा कुंजी_WOW64_32_कुंजी (0x0200)
#घोषणा कुंजी_WOW64_64_कुंजी (0x0100)
#घोषणा कुंजी_WOW64_RES (0x0300)

#घोषणा कुंजी_READ ((STANDARD_RIGHTS_READ | कुंजी_QUERY_मूल्य | कुंजी_ENUMERATE_SUB_कुंजियाँ | कुंजी_NOTIFY) & (~SYNCHRONIZE))
#घोषणा कुंजी_WRITE ((STANDARD_RIGHTS_WRITE | कुंजी_SET_मूल्य | कुंजी_CREATE_SUB_कुंजी) & (~SYNCHRONIZE))
#घोषणा कुंजी_EXECUTE ((कुंजी_READ) & (~SYNCHRONIZE))
#घोषणा कुंजी_ALL_ACCESS ((STANDARD_RIGHTS_ALL | कुंजी_QUERY_मूल्य | कुंजी_SET_मूल्य | कुंजी_CREATE_SUB_कुंजी | कुंजी_ENUMERATE_SUB_कुंजियाँ | कुंजी_NOTIFY | कुंजी_CREATE_LINK) & (~SYNCHRONIZE))
#घोषणा REG_OPTION_RESERVED (0x00000000L)

#घोषणा REG_OPTION_NON_VOLATILE (0x00000000L)
#घोषणा REG_OPTION_VOLATILE (0x00000001L)
#घोषणा REG_OPTION_CREATE_LINK (0x00000002L)
#घोषणा REG_OPTION_BACKUP_RESTORE (0x00000004L)
#घोषणा REG_OPTION_OPEN_LINK (0x00000008L)
#घोषणा REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#घोषणा REG_CREATED_NEW_कुंजी (0x00000001L)
#घोषणा REG_OPENED_EXISTING_कुंजी (0x00000002L)
#घोषणा REG_STANDARD_FORMAT 1
#घोषणा REG_LATEST_FORMAT 2
#घोषणा REG_NO_COMPRESSION 4
#घोषणा REG_WHOLE_HIVE_VOLATILE (0x00000001L)
#घोषणा REG_REFRESH_HIVE (0x00000002L)
#घोषणा REG_NO_LAZY_FLUSH (0x00000004L)
#घोषणा REG_FORCE_RESTORE (0x00000008L)
#घोषणा REG_FORCE_UNLOAD 1

#घोषणा REG_NOTIFY_CHANGE_NAME (0x00000001L)
#घोषणा REG_NOTIFY_CHANGE_ATTRIBUTES (0x00000002L)
#घोषणा REG_NOTIFY_CHANGE_LAST_SET (0x00000004L)
#घोषणा REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#घोषणा REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_ATTRIBUTES | REG_NOTIFY_CHANGE_LAST_SET | REG_NOTIFY_CHANGE_SECURITY)

#घोषणा REG_NONE (0)
#घोषणा REG_SZ (1)
#घोषणा REG_EXPAND_SZ (2)

#घोषणा REG_द्विआधारी (3)
#घोषणा REG_DWORD (4)
#घोषणा REG_DWORD_LITTLE_ENDIAN (4)
#घोषणा REG_DWORD_BIG_ENDIAN (5)
#घोषणा REG_LINK (6)
#घोषणा REG_MULTI_SZ (7)
#घोषणा REG_RESOURCE_LIST (8)
#घोषणा REG_FULL_RESOURCE_DESCRIPTOR (9)
#घोषणा REG_RESOURCE_REQUIREMENTS_LIST (10)
#घोषणा REG_QWORD (11)
#घोषणा REG_QWORD_LITTLE_ENDIAN (11)

#घोषणा SERVICE_KERNEL_DRIVER 0x00000001
#घोषणा SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#घोषणा SERVICE_ADAPTER 0x00000004
#घोषणा SERVICE_RECOGNIZER_DRIVER 0x00000008

#घोषणा SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#घोषणा SERVICE_WIN32_OWN_PROCESS 0x00000010
#घोषणा SERVICE_WIN32_SHARE_PROCESS 0x00000020
#घोषणा SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#घोषणा SERVICE_INTERACTIVE_PROCESS 0x00000100

#घोषणा SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#घोषणा SERVICE_BOOT_START 0x00000000
#घोषणा SERVICE_SYSTEM_START 0x00000001
#घोषणा SERVICE_AUTO_START 0x00000002
#घोषणा SERVICE_DEMAND_START 0x00000003
#घोषणा SERVICE_DISABLED 0x00000004

#घोषणा SERVICE_ERROR_IGNORE 0x00000000
#घोषणा SERVICE_ERROR_NORMAL 0x00000001
#घोषणा SERVICE_ERROR_SEVERE 0x00000002
#घोषणा SERVICE_ERROR_CRITICAL 0x00000003

    प्रकार क्रमागत CM_SERVICE_गाँठ_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_गाँठ_TYPE;

    प्रकार क्रमागत _CM_SERVICE_LOAD_TYPE {
      BootLoad = SERVICE_BOOT_START,SystemLoad = SERVICE_SYSTEM_START,AutoLoad = SERVICE_AUTO_START,DemandLoad = SERVICE_DEMAND_START,
      DisableLoad = SERVICE_DISABLED
    } SERVICE_LOAD_TYPE;

    प्रकार क्रमागत _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,NormalError = SERVICE_ERROR_NORMAL,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#घोषणा TAPE_ERASE_SHORT 0L
#घोषणा TAPE_ERASE_LONG 1L

    प्रकार काष्ठा _TAPE_ERASE {
      DWORD Type;
      BOOLEAN Immediate;
    } TAPE_ERASE,*PTAPE_ERASE;

#घोषणा TAPE_LOAD 0L
#घोषणा TAPE_UNLOAD 1L
#घोषणा TAPE_TENSION 2L
#घोषणा TAPE_LOCK 3L
#घोषणा TAPE_UNLOCK 4L
#घोषणा TAPE_FORMAT 5L

    प्रकार काष्ठा _TAPE_PREPARE {
      DWORD Operation;
      BOOLEAN Immediate;
    } TAPE_PREPARE,*PTAPE_PREPARE;

#घोषणा TAPE_SETMARKS 0L
#घोषणा TAPE_FILEMARKS 1L
#घोषणा TAPE_SHORT_FILEMARKS 2L
#घोषणा TAPE_LONG_FILEMARKS 3L

    प्रकार काष्ठा _TAPE_WRITE_MARKS {
      DWORD Type;
      DWORD गिनती_3;
      BOOLEAN Immediate;
    } TAPE_WRITE_MARKS,*PTAPE_WRITE_MARKS;

#घोषणा TAPE_ABSOLUTE_POSITION 0L
#घोषणा TAPE_LOGICAL_POSITION 1L
#घोषणा TAPE_PSEUDO_LOGICAL_POSITION 2L

    प्रकार काष्ठा _TAPE_GET_POSITION {
      DWORD Type;
      DWORD Partition;
      LARGE_INTEGER Offset;
    } TAPE_GET_POSITION,*PTAPE_GET_POSITION;

#घोषणा TAPE_REWIND 0L
#घोषणा TAPE_ABSOLUTE_BLOCK 1L
#घोषणा TAPE_LOGICAL_BLOCK 2L
#घोषणा TAPE_PSEUDO_LOGICAL_BLOCK 3L
#घोषणा TAPE_SPACE_END_OF_तथ्य 4L
#घोषणा TAPE_SPACE_RELATIVE_BLOCKS 5L
#घोषणा TAPE_SPACE_FILEMARKS 6L
#घोषणा TAPE_SPACE_SEQUENTIAL_FMKS 7L
#घोषणा TAPE_SPACE_SETMARKS 8L
#घोषणा TAPE_SPACE_SEQUENTIAL_SMKS 9L

    प्रकार काष्ठा _TAPE_SET_POSITION {
      DWORD Method;
      DWORD Partition;
      LARGE_INTEGER Offset;
      BOOLEAN Immediate;
    } TAPE_SET_POSITION,*PTAPE_SET_POSITION;

#घोषणा TAPE_DRIVE_FIXED 0x00000001
#घोषणा TAPE_DRIVE_SELECT 0x00000002
#घोषणा TAPE_DRIVE_INITIATOR 0x00000004

#घोषणा TAPE_DRIVE_ERASE_SHORT 0x00000010
#घोषणा TAPE_DRIVE_ERASE_LONG 0x00000020
#घोषणा TAPE_DRIVE_ERASE_BOP_ONLY 0x00000040
#घोषणा TAPE_DRIVE_ERASE_IMMEDIATE 0x00000080

#घोषणा TAPE_DRIVE_TAPE_CAPACITY 0x00000100
#घोषणा TAPE_DRIVE_TAPE_REMAINING 0x00000200
#घोषणा TAPE_DRIVE_FIXED_BLOCK 0x00000400
#घोषणा TAPE_DRIVE_VARIABLE_BLOCK 0x00000800

#घोषणा TAPE_DRIVE_WRITE_PROTECT 0x00001000
#घोषणा TAPE_DRIVE_EOT_WZ_आकार 0x00002000

#घोषणा TAPE_DRIVE_ECC 0x00010000
#घोषणा TAPE_DRIVE_COMPRESSION 0x00020000
#घोषणा TAPE_DRIVE_PADDING 0x00040000
#घोषणा TAPE_DRIVE_REPORT_SMKS 0x00080000

#घोषणा TAPE_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#घोषणा TAPE_DRIVE_GET_LOGICAL_BLK 0x00200000
#घोषणा TAPE_DRIVE_SET_EOT_WZ_आकार 0x00400000

#घोषणा TAPE_DRIVE_EJECT_MEDIA 0x01000000
#घोषणा TAPE_DRIVE_CLEAN_REQUESTS 0x02000000
#घोषणा TAPE_DRIVE_SET_CMP_BOP_ONLY 0x04000000

#घोषणा TAPE_DRIVE_RESERVED_BIT 0x80000000

#घोषणा TAPE_DRIVE_LOAD_UNLOAD 0x80000001
#घोषणा TAPE_DRIVE_TENSION 0x80000002
#घोषणा TAPE_DRIVE_LOCK_UNLOCK 0x80000004
#घोषणा TAPE_DRIVE_REWIND_IMMEDIATE 0x80000008

#घोषणा TAPE_DRIVE_SET_BLOCK_आकार 0x80000010
#घोषणा TAPE_DRIVE_LOAD_UNLD_IMMED 0x80000020
#घोषणा TAPE_DRIVE_TENSION_IMMED 0x80000040
#घोषणा TAPE_DRIVE_LOCK_UNLK_IMMED 0x80000080

#घोषणा TAPE_DRIVE_SET_ECC 0x80000100
#घोषणा TAPE_DRIVE_SET_COMPRESSION 0x80000200
#घोषणा TAPE_DRIVE_SET_PADDING 0x80000400
#घोषणा TAPE_DRIVE_SET_REPORT_SMKS 0x80000800

#घोषणा TAPE_DRIVE_ABSOLUTE_BLK 0x80001000
#घोषणा TAPE_DRIVE_ABS_BLK_IMMED 0x80002000
#घोषणा TAPE_DRIVE_LOGICAL_BLK 0x80004000
#घोषणा TAPE_DRIVE_LOG_BLK_IMMED 0x80008000

#घोषणा TAPE_DRIVE_END_OF_तथ्य 0x80010000
#घोषणा TAPE_DRIVE_RELATIVE_BLKS 0x80020000
#घोषणा TAPE_DRIVE_FILEMARKS 0x80040000
#घोषणा TAPE_DRIVE_SEQUENTIAL_FMKS 0x80080000

#घोषणा TAPE_DRIVE_SETMARKS 0x80100000
#घोषणा TAPE_DRIVE_SEQUENTIAL_SMKS 0x80200000
#घोषणा TAPE_DRIVE_REVERSE_POSITION 0x80400000
#घोषणा TAPE_DRIVE_SPACE_IMMEDIATE 0x80800000

#घोषणा TAPE_DRIVE_WRITE_SETMARKS 0x81000000
#घोषणा TAPE_DRIVE_WRITE_FILEMARKS 0x82000000
#घोषणा TAPE_DRIVE_WRITE_SHORT_FMKS 0x84000000
#घोषणा TAPE_DRIVE_WRITE_LONG_FMKS 0x88000000

#घोषणा TAPE_DRIVE_WRITE_MARK_IMMED 0x90000000
#घोषणा TAPE_DRIVE_FORMAT 0xA0000000
#घोषणा TAPE_DRIVE_FORMAT_IMMEDIATE 0xC0000000
#घोषणा TAPE_DRIVE_ऊपरी_FEATURES 0x80000000

    प्रकार काष्ठा _TAPE_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN तथ्य_Padding;
      BOOLEAN ReportSetmarks;
      DWORD Default_Block_आकार;
      DWORD Maximum_Block_आकार;
      DWORD Minimum_Block_आकार;
      DWORD Maximum_Partition_गिनती;
      DWORD Features_निचला;
      DWORD Features_ऊपरी;
      DWORD EOTWarning_Zone_आकार;
    } TAPE_GET_DRIVE_PARAMETERS,*PTAPE_GET_DRIVE_PARAMETERS;

    प्रकार काष्ठा _TAPE_SET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN तथ्य_Padding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarning_Zone_आकार;
    } TAPE_SET_DRIVE_PARAMETERS,*PTAPE_SET_DRIVE_PARAMETERS;

    प्रकार काष्ठा _TAPE_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER Capacity;
      LARGE_INTEGER Remaining;
      DWORD Block_आकार;
      DWORD Partition_गिनती;
      BOOLEAN WriteProtected;
    } TAPE_GET_MEDIA_PARAMETERS,*PTAPE_GET_MEDIA_PARAMETERS;

    प्रकार काष्ठा _TAPE_SET_MEDIA_PARAMETERS {
      DWORD Block_आकार;
    } TAPE_SET_MEDIA_PARAMETERS,*PTAPE_SET_MEDIA_PARAMETERS;

#घोषणा TAPE_FIXED_PARTITIONS 0L
#घोषणा TAPE_SELECT_PARTITIONS 1L
#घोषणा TAPE_INITIATOR_PARTITIONS 2L

    प्रकार काष्ठा _TAPE_CREATE_PARTITION {
      DWORD Method;
      DWORD गिनती_3;
      DWORD आकार_3;
    } TAPE_CREATE_PARTITION,*PTAPE_CREATE_PARTITION;

#घोषणा TAPE_QUERY_DRIVE_PARAMETERS 0L
#घोषणा TAPE_QUERY_MEDIA_CAPACITY 1L
#घोषणा TAPE_CHECK_FOR_DRIVE_PROBLEM 2L
#घोषणा TAPE_QUERY_IO_ERROR_तथ्य 3L
#घोषणा TAPE_QUERY_DEVICE_ERROR_तथ्य 4L

    प्रकार काष्ठा _TAPE_WMI_OPERATIONS {
      DWORD Method;
      DWORD तथ्य_बफर_आकार;
      PVOID तथ्य_बफर;
    } TAPE_WMI_OPERATIONS,*PTAPE_WMI_OPERATIONS;

    प्रकार क्रमागत _TAPE_DRIVE_PROBLEM_TYPE {
      TapeDriveProblemNone,TapeDriveReadWriteWarning,TapeDriveReadWriteError,TapeDriveReadWarning,TapeDriveWriteWarning,TapeDriveReadError,TapeDriveWriteError,TapeDriveHardwareError,TapeDriveUnsupportedMedia,TapeDriveScsiConnectionError,TapeDriveTimetoClean,TapeDriveCleanDriveNow,TapeDriveMediaLifeExpired,TapeDriveSnappedTape
    } TAPE_DRIVE_PROBLEM_TYPE;

#अगर defined(__x86_64)
    __CRT_INLINE काष्ठा _TEB *NtCurrentTeb(VOID) { वापस (काष्ठा _TEB *)__readgsqword(FIELD_OFFSET(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { वापस(PVOID)__readgsqword(FIELD_OFFSET(NT_TIB,Fiber_तथ्य)); }
    __CRT_INLINE PVOID Get_Fiber_तथ्य(VOID) {
      वापस *(PVOID *)GetCurrentFiber();
    }
#पूर्ण_अगर

#अगर(defined(_X86_) && !defined(__x86_64))
#घोषणा PcTeb 0x18
    __CRT_INLINE काष्ठा _TEB *NtCurrentTeb(व्योम) {
      काष्ठा _TEB *ret;
      __asm__ अस्थिर ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      वापस ret;
    }
#पूर्ण_अगर

#घोषणा ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#घोषणा ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#घोषणा ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION (3)
#घोषणा ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#घोषणा ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#घोषणा ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#घोषणा ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#घोषणा ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_TABLE (8)
#घोषणा ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#घोषणा ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#अगर_घोषित __cplusplus
  }
#पूर्ण_अगर
#पूर्ण_अगर
