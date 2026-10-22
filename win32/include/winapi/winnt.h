/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#यदि_अपरिभाषितम् _WINNT_
#परिभाषय _WINNT_

#यदि_परिभाषितम् __cplusplus
बाह्य "C" {
#यदि_अन्तः

#अन्तर्भाव <ctype.h>
#परिभाषय ANYSIZE_ARRAY 1

//gr #include <specstrings.h>

#परिभाषय RESTRICTED_POINTER

#यदि_अपरिभाषितम् __CRT_UNALIGNED
#परिभाषय __CRT_UNALIGNED
#यदि_अन्तः

#यदि defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#परिभाषय UNALIGNED __CRT_UNALIGNED
#यदि_परिभाषितम् _WIN64
#परिभाषय UNALIGNED64 __CRT_UNALIGNED
#अन्यथा
#परिभाषय UNALIGNED64
#यदि_अन्तः
#अन्यथा
#परिभाषय UNALIGNED
#परिभाषय UNALIGNED64
#यदि_अन्तः

#यदि !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && (defined(_X86_) && !defined(__x86_64))
#परिभाषय I_X86_
#यदि_अन्तः

#यदि !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_) && defined(__x86_64)
#परिभाषय _AMD64_
#यदि_अन्तः

#यदि !defined(I_X86_) && !(defined(_X86_) && !defined(__x86_64)) && !defined(_AMD64_) && defined(__ia64__)
#यदि !defined(_IA64_)
#परिभाषय _IA64_
#यदि_अन्तः
#यदि_अन्तः


#यदि_परिभाषितम् _WIN64
#परिभाषय MAX_NATURAL_ALIGNMENT परिमाण(ULONGLONG)
#परिभाषय स्मृतिः_आवण्टनम्_ALIGNMENT 16
#अन्यथा
#परिभाषय MAX_NATURAL_ALIGNMENT परिमाण(DWORD)
#परिभाषय स्मृतिः_आवण्टनम्_ALIGNMENT 8
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
#परिभाषय TYPE_ALIGNMENT(t) __alignof__ (t)
#अन्यथा
#परिभाषय TYPE_ALIGNMENT(t) क्षेत्रम्_विस्थापनम्(संरचना { वर्ण x; t test; },test)
#यदि_अन्तः

#यदि_परिभाषितम् _WIN64
#यदि_परिभाषितम् _AMD64_
#परिभाषय PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#नोचेद्यदि defined(_IA64_) || defined(_ARM64_)
#परिभाषय PROBE_ALIGNMENT(_s) (TYPE_ALIGNMENT(_s) > TYPE_ALIGNMENT(DWORD) ? TYPE_ALIGNMENT(_s) : TYPE_ALIGNMENT(DWORD))
#अन्यथा
#दोषः No Target Architecture
#यदि_अन्तः
#परिभाषय PROBE_ALIGNMENT32(_s) TYPE_ALIGNMENT(DWORD)
#अन्यथा
#परिभाषय PROBE_ALIGNMENT(_s) TYPE_ALIGNMENT(DWORD)
#यदि_अन्तः

#परिभाषय C_ASSERT(e) प्रकारनिर्देश वर्ण __C_ASSERT__[(e)?1:-1]

#अन्तर्भाव <basetsd.h>

#यदि defined(_X86_) || defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#परिभाषय DECLSPEC_IMPORT __declspec(dllimport)
#अन्यथा
#परिभाषय DECLSPEC_IMPORT
#यदि_अन्तः

#यदि_अपरिभाषितम् DECLSPEC_NORETURN
#परिभाषय DECLSPEC_NORETURN __declspec(noreturn)
#यदि_अन्तः

#यदि_अपरिभाषितम् DECLSPEC_ALIGN
#परिभाषय DECLSPEC_ALIGN(x) __attribute__ ((aligned(x)))
#यदि_अन्तः

#यदि_अपरिभाषितम् SYSTEM_CACHE_ALIGNMENT_आकार
#यदि defined(_AMD64_) || defined(I_X86_)
#परिभाषय SYSTEM_CACHE_ALIGNMENT_आकार 64
#अन्यथा
#परिभाषय SYSTEM_CACHE_ALIGNMENT_आकार 128
#यदि_अन्तः
#यदि_अन्तः

#यदि_अपरिभाषितम् DECLSPEC_CACHEALIGN
#परिभाषय DECLSPEC_CACHEALIGN DECLSPEC_ALIGN(SYSTEM_CACHE_ALIGNMENT_आकार)
#यदि_अन्तः

#यदि_अपरिभाषितम् DECLSPEC_UUID
#परिभाषय DECLSPEC_UUID(x)
#यदि_अन्तः

#यदि_अपरिभाषितम् DECLSPEC_NOVTABLE
#परिभाषय DECLSPEC_NOVTABLE
#यदि_अन्तः

#यदि_अपरिभाषितम् DECLSPEC_SELECTANY
#परिभाषय DECLSPEC_SELECTANY __declspec(selectany)
#यदि_अन्तः

#यदि_अपरिभाषितम् NOP_FUNCTION
#परिभाषय NOP_FUNCTION (शून्य)0
#यदि_अन्तः

#यदि_अपरिभाषितम् DECLSPEC_NOINLINE
#परिभाषय DECLSPEC_NOINLINE
#यदि_अन्तः

#यदि_अपरिभाषितम् FORCEINLINE
#परिभाषय FORCEINLINE स्थिर __inline__
#यदि_अन्तः

#यदि_अपरिभाषितम् DECLSPEC_DEPRECATED
#परिभाषय DECLSPEC_DEPRECATED __declspec(deprecated)
#परिभाषय DEPRECATE_SUPPORTED
#यदि_अन्तः

#परिभाषय DECLSPEC_DEPRECATED_DDK
#परिभाषय PRAGMA_DEPRECATED_DDK 0

  प्रकारनिर्देश शून्य *PVOID;
  प्रकारनिर्देश शून्य *PVOID64;

#परिभाषय NTAPI __stdcall
#परिभाषय NTSYSAPI DECLSPEC_IMPORT
#परिभाषय NTSYSCALLAPI DECLSPEC_IMPORT

#यदि_अपरिभाषितम् VOID
#परिभाषय VOID शून्य
  प्रकारनिर्देश वर्ण CHAR;
  प्रकारनिर्देश ह्रस्व SHORT;
  प्रकारनिर्देश दीर्घ LONG;
#यदि_अन्तः

  प्रकारनिर्देश wchar_t WCHAR;
  प्रकारनिर्देश WCHAR *PWCHAR,*LPWCH,*PWCH;
  प्रकारनिर्देश CONST WCHAR *LPCWCH,*PCWCH;
  प्रकारनिर्देश WCHAR *NWPSTR,*LPWSTR,*PWSTR;
  प्रकारनिर्देश PWSTR *PZPWSTR;
  प्रकारनिर्देश CONST PWSTR *PCZPWSTR;
  प्रकारनिर्देश WCHAR UNALIGNED *LPUWSTR,*PUWSTR;
  प्रकारनिर्देश CONST WCHAR *LPCWSTR,*PCWSTR;
  प्रकारनिर्देश PCWSTR *PZPCWSTR;
  प्रकारनिर्देश CONST WCHAR UNALIGNED *LPCUWSTR,*PCUWSTR;
  प्रकारनिर्देश CHAR *PCHAR,*LPCH,*PCH;
  प्रकारनिर्देश CONST CHAR *LPCCH,*PCCH;
  प्रकारनिर्देश CHAR *NPSTR,*LPSTR,*PSTR;
  प्रकारनिर्देश PSTR *PZPSTR;
  प्रकारनिर्देश CONST PSTR *PCZPSTR;
  प्रकारनिर्देश CONST CHAR *LPCSTR,*PCSTR;
  प्रकारनिर्देश PCSTR *PZPCSTR;

#यदि_परिभाषितम् UNICODE
#यदि_अपरिभाषितम् _TCHAR_DEFINED
#परिभाषय _TCHAR_DEFINED
  प्रकारनिर्देश WCHAR TCHAR,*PTCHAR;
  प्रकारनिर्देश WCHAR TBYTE ,*PTBYTE;
#यदि_अन्तः

  प्रकारनिर्देश LPWSTR LPTCH,PTCH;
  प्रकारनिर्देश LPWSTR PTSTR,LPTSTR;
  प्रकारनिर्देश LPCWSTR PCTSTR,LPCTSTR;
  प्रकारनिर्देश LPUWSTR PUTSTR,LPUTSTR;
  प्रकारनिर्देश LPCUWSTR PCUTSTR,LPCUTSTR;
  प्रकारनिर्देश LPWSTR LP;
#परिभाषय __TEXT(quote) L##quote
#अन्यथा
#यदि_अपरिभाषितम् _TCHAR_DEFINED
#परिभाषय _TCHAR_DEFINED
  प्रकारनिर्देश वर्ण TCHAR,*PTCHAR;
  प्रकारनिर्देश अचिह्नित वर्ण TBYTE ,*PTBYTE;
#यदि_अन्तः

  प्रकारनिर्देश LPSTR LPTCH,PTCH;
  प्रकारनिर्देश LPSTR PTSTR,LPTSTR,PUTSTR,LPUTSTR;
  प्रकारनिर्देश LPCSTR PCTSTR,LPCTSTR,PCUTSTR,LPCUTSTR;
#परिभाषय __TEXT(quote) quote
#यदि_अन्तः

#परिभाषय TEXT(quote) __TEXT(quote)

  प्रकारनिर्देश SHORT *PSHORT;
  प्रकारनिर्देश LONG *PLONG;

  प्रकारनिर्देश शून्य *HANDLE;
#परिभाषय DECLARE_HANDLE(name) संरचना name##__ { पूर्णाङ्क अप्रयुक्तम्; }; प्रकारनिर्देश संरचना name##__ *name
  प्रकारनिर्देश HANDLE *PHANDLE;

  प्रकारनिर्देश BYTE FCHAR;
  प्रकारनिर्देश WORD FSHORT;
  प्रकारनिर्देश DWORD FLONG;

#यदि_अपरिभाषितम् _HRESULT_DEFINED
#परिभाषय _HRESULT_DEFINED
  प्रकारनिर्देश LONG HRESULT;
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
#परिभाषय EXTERN_C बाह्य "C"
#अन्यथा
#परिभाषय EXTERN_C बाह्य
#यदि_अन्तः

#परिभाषय STDMETHODCALLTYPE WINAPI
#परिभाषय STDMETHODVCALLTYPE __cdecl
#परिभाषय STDAPICALLTYPE WINAPI
#परिभाषय STDAPIVCALLTYPE __cdecl
#परिभाषय STDAPI EXTERN_C HRESULT WINAPI
#परिभाषय STDAPI_(type) EXTERN_C type WINAPI
#परिभाषय STDMETHODIMP HRESULT WINAPI
#परिभाषय STDMETHODIMP_(type) type WINAPI
#परिभाषय STDAPIV EXTERN_C HRESULT STDAPIVCALLTYPE
#परिभाषय STDAPIV_(type) EXTERN_C type STDAPIVCALLTYPE
#परिभाषय STDMETHODIMPV HRESULT STDMETHODVCALLTYPE
#परिभाषय STDMETHODIMPV_(type) type STDMETHODVCALLTYPE

  प्रकारनिर्देश वर्ण CCHAR;
#यदि_अपरिभाषितम् _LCID_DEFINED
#परिभाषय _LCID_DEFINED
प्रकारनिर्देश DWORD LCID;
#यदि_अन्तः
  प्रकारनिर्देश PDWORD PLCID;
#यदि_अपरिभाषितम् _LANGID_DEFINED
#परिभाषय _LANGID_DEFINED
  प्रकारनिर्देश WORD LANGID;
#यदि_अन्तः
#परिभाषय APPLICATION_ERROR_आवरणम् 0x20000000
#परिभाषय ERROR_SEVERITY_SUCCESS 0x00000000
#परिभाषय ERROR_SEVERITY_INFORMATIONAL 0x40000000
#परिभाषय ERROR_SEVERITY_WARNING 0x80000000
#परिभाषय ERROR_SEVERITY_ERROR 0xC0000000

#यदि_परिभाषितम् __ia64__
  __declspec(align(16))
#यदि_अन्तः
    प्रकारनिर्देश संरचना _FLOAT128 {
      __int64 नीचः_Part;
      __int64 उच्चः_Part;
  } FLOAT128;

  प्रकारनिर्देश FLOAT128 *PFLOAT128;

#परिभाषय _ULONGLONG_
#यदि((!(defined(_X86_) && !defined(__x86_64)) || (defined(INTEGRAL_MAX_द्वयङ्काः) && INTEGRAL_MAX_द्वयङ्काः >= 64)))
  प्रकारनिर्देश __int64 LONGLONG;
  प्रकारनिर्देश अचिह्नित __int64 ULONGLONG;

#परिभाषय MAXLONGLONG (0x7fffffffffffffff)
#अन्यथा

  प्रकारनिर्देश द्विगुण LONGLONG;
  प्रकारनिर्देश द्विगुण ULONGLONG;
#यदि_अन्तः

  प्रकारनिर्देश LONGLONG *PLONGLONG;
  प्रकारनिर्देश ULONGLONG *PULONGLONG;

  प्रकारनिर्देश LONGLONG USN;

  प्रकारनिर्देश सङ्घ _LARGE_INTEGER {
    संरचना {
      DWORD नीचः_Part;
      LONG उच्चः_Part;
    };
    संरचना {
      DWORD नीचः_Part;
      LONG उच्चः_Part;
    } u;
    LONGLONG QuadPart;
  } LARGE_INTEGER;

  प्रकारनिर्देश LARGE_INTEGER *PLARGE_INTEGER;

  प्रकारनिर्देश सङ्घ _ULARGE_INTEGER {
    संरचना {
      DWORD नीचः_Part;
      DWORD उच्चः_Part;
    };
    संरचना {
      DWORD नीचः_Part;
      DWORD उच्चः_Part;
    } u;
    ULONGLONG QuadPart;
  } ULARGE_INTEGER;

  प्रकारनिर्देश ULARGE_INTEGER *PULARGE_INTEGER;

  प्रकारनिर्देश संरचना _LUID {
    DWORD नीचः_Part;
    LONG उच्चः_Part;
  } LUID,*PLUID;

#परिभाषय _DWORDLONG_
  प्रकारनिर्देश ULONGLONG DWORDLONG;
  प्रकारनिर्देश DWORDLONG *PDWORDLONG;

#यदि_परिभाषितम् RC_INVOKED
#परिभाषय Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#परिभाषय UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#परिभाषय Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#नोचेद्यदि (defined(_X86_) && !defined(__x86_64))
#परिभाषय Int32x32To64(a,b) (LONGLONG)((LONGLONG)(LONG)(a) *(LONG)(b))
#परिभाषय UInt32x32To64(a,b) (ULONGLONG)((ULONGLONG)(DWORD)(a) *(DWORD)(b))
#परिभाषय Int64ShrlMod32(a,b) ((DWORDLONG)(a)>>(b))
#नोचेद्यदि defined(__ia64__) || defined(__x86_64) || defined(__aarch64__)
#परिभाषय Int32x32To64(a,b) ((LONGLONG)((LONG)(a)) *(LONGLONG)((LONG)(b)))
#परिभाषय UInt32x32To64(a,b) ((ULONGLONG)((DWORD)(a)) *(ULONGLONG)((DWORD)(b)))
#परिभाषय Int64ShrlMod32(a,b) ((ULONGLONG)(a) >> (b))
#अन्यथा
#दोषः Must define a target architecture.
#यदि_अन्तः

#परिभाषय Int64ShraMod32(a,b) ((LONGLONG)(a) >> (b))
#परिभाषय Int64ShllMod32(a,b) ((ULONGLONG)(a) << (b))

#यदि_परिभाषितम् __cplusplus
  बाह्य "C" {
#यदि_अन्तः

#यदि_परिभाषितम् __x86_64

#परिभाषय RotateLeft8 _rotl8
#परिभाषय RotateLeft16 _rotl16
#परिभाषय RotateRight8 _rotr8
#परिभाषय RotateRight16 _rotr16

    अचिह्नित वर्ण __cdecl _rotl8(अचिह्नित वर्ण मानम्_3,अचिह्नित वर्ण सरणम्_3);
    अचिह्नित ह्रस्व __cdecl _rotl16(अचिह्नित ह्रस्व मानम्_3,अचिह्नित वर्ण सरणम्_3);
    अचिह्नित वर्ण __cdecl _rotr8(अचिह्नित वर्ण मानम्_3,अचिह्नित वर्ण सरणम्_3);
    अचिह्नित ह्रस्व __cdecl _rotr16(अचिह्नित ह्रस्व मानम्_3,अचिह्नित वर्ण सरणम्_3);
#यदि_अन्तः

#परिभाषय RotateLeft32 _rotl
#परिभाषय RotateLeft64 _rotl64
#परिभाषय RotateRight32 _rotr
#परिभाषय RotateRight64 _rotr64

    अचिह्नित पूर्णाङ्क __cdecl _rotl(अचिह्नित पूर्णाङ्क मानम्_3,पूर्णाङ्क सरणम्_3);
    अचिह्नित __int64 __cdecl _rotl64(अचिह्नित __int64 मानम्_3,पूर्णाङ्क सरणम्_3);
    अचिह्नित पूर्णाङ्क __cdecl _rotr(अचिह्नित पूर्णाङ्क मानम्_3,पूर्णाङ्क सरणम्_3);
    अचिह्नित __int64 __cdecl _rotr64(अचिह्नित __int64 मानम्_3,पूर्णाङ्क सरणम्_3);
#यदि_परिभाषितम् __cplusplus
  }
#यदि_अन्तः

#परिभाषय ANSI_NULL ((CHAR)0)
#परिभाषय UNICODE_NULL ((WCHAR)0)
#परिभाषय UNICODE_STRING_MAX_अष्टकानि ((WORD) 65534)
#परिभाषय UNICODE_STRING_MAX_CHARS (32767)

#यदि_अपरिभाषितम् _BOOLEAN_
#परिभाषय _BOOLEAN_
  प्रकारनिर्देश BYTE BOOLEAN;
#यदि_अन्तः
  प्रकारनिर्देश BOOLEAN *PBOOLEAN;

  प्रकारनिर्देश संरचना LIST_प्रविष्टिः {
    संरचना LIST_प्रविष्टिः *Flink;
    संरचना LIST_प्रविष्टिः *Blink;
  } LIST_प्रविष्टिः_2,*PLIST_प्रविष्टिः,*RESTRICTED_POINTER PRLIST_प्रविष्टिः;

  प्रकारनिर्देश संरचना SINGLE_LIST_प्रविष्टिः {
    संरचना SINGLE_LIST_प्रविष्टिः *अग्र_2;
  } SINGLE_LIST_प्रविष्टिः_2,*PSINGLE_LIST_प्रविष्टिः;

  प्रकारनिर्देश संरचना LIST_ENTRY32 {
    DWORD Flink;
    DWORD Blink;
  } LIST_ENTRY32;
  प्रकारनिर्देश LIST_ENTRY32 *PLIST_ENTRY32;

  प्रकारनिर्देश संरचना LIST_ENTRY64 {
    ULONGLONG Flink;
    ULONGLONG Blink;
  } LIST_ENTRY64;
  प्रकारनिर्देश LIST_ENTRY64 *PLIST_ENTRY64;

#अन्तर्भाव <guiddef.h>

#यदि_अपरिभाषितम् __OBJECTID_DEFINED
#परिभाषय __OBJECTID_DEFINED
  प्रकारनिर्देश संरचना _OBJECTID {
    GUID Lineage;
    DWORD Uniquifier;
  } OBJECTID;
#यदि_अन्तः

#परिभाषय MINCHAR 0x80
#परिभाषय MAXCHAR 0x7f
#परिभाषय MINSHORT 0x8000
#परिभाषय MAXSHORT 0x7fff
#परिभाषय MINLONG 0x80000000
#परिभाषय MAXLONG 0x7fffffff
#परिभाषय MAXBYTE 0xff
#परिभाषय MAXWORD 0xffff
#परिभाषय MAXDWORD 0xffffffff

#परिभाषय क्षेत्रम्_विस्थापनम्(type,क्षेत्रम्) ((LONG)(LONG_PTR)&(((type *)0)->क्षेत्रम्))
#परिभाषय RTL_क्षेत्रम्_आकार(type,क्षेत्रम्) (परिमाण(((type *)0)->क्षेत्रम्))
#परिभाषय RTL_SIZEOF_THROUGH_क्षेत्रम्(type,क्षेत्रम्) (क्षेत्रम्_विस्थापनम्(type,क्षेत्रम्) + RTL_क्षेत्रम्_आकार(type,क्षेत्रम्))
#परिभाषय RTL_अन्तर्भवति_क्षेत्रम्(Struct,आकार_3,क्षेत्रम्_2) ((((PCHAR)(&(Struct)->क्षेत्रम्_2)) + परिमाण((Struct)->क्षेत्रम्_2)) <= (((PCHAR)(Struct))+(आकार_3)))
#परिभाषय RTL_सङ्ख्या_सम्बन्धि_V1(A) (परिमाण(A)/परिमाण((A)[0]))
#परिभाषय RTL_सङ्ख्या_सम्बन्धि_V2(A) RTL_सङ्ख्या_सम्बन्धि_V1(A)

#यदि_परिभाषितम् ENABLE_RTL_सङ्ख्या_सम्बन्धि_V2
#परिभाषय RTL_सङ्ख्या_सम्बन्धि(A) RTL_सङ्ख्या_सम्बन्धि_V2(A)
#अन्यथा
#परिभाषय RTL_सङ्ख्या_सम्बन्धि(A) RTL_सङ्ख्या_सम्बन्धि_V1(A)
#यदि_अन्तः

#परिभाषय ARRAYSIZE(A) RTL_सङ्ख्या_सम्बन्धि_V2(A)
#परिभाषय _ARRAYSIZE(A) RTL_सङ्ख्या_सम्बन्धि_V1(A)

#परिभाषय RTL_क्षेत्रम्_TYPE(type,क्षेत्रम्) (((type*)0)->क्षेत्रम्)
#परिभाषय RTL_सङ्ख्या_सम्बन्धि_क्षेत्रम्(type,क्षेत्रम्) (RTL_सङ्ख्या_सम्बन्धि(RTL_क्षेत्रम्_TYPE(type,क्षेत्रम्)))
#परिभाषय RTL_PADDING_BETWEEN_FIELDS(T,F1,F2) ((क्षेत्रम्_विस्थापनम्(T,F2) > क्षेत्रम्_विस्थापनम्(T,F1)) ? (क्षेत्रम्_विस्थापनम्(T,F2) - क्षेत्रम्_विस्थापनम्(T,F1) - RTL_क्षेत्रम्_आकार(T,F1)) : (क्षेत्रम्_विस्थापनम्(T,F1) - क्षेत्रम्_विस्थापनम्(T,F2) - RTL_क्षेत्रम्_आकार(T,F2)))

#यदि_परिभाषितम् __cplusplus
#परिभाषय RTL_CONST_CAST(type) const_cast<type>
#अन्यथा
#परिभाषय RTL_CONST_CAST(type) (type)
#यदि_अन्तः

#परिभाषय RTL_द्वयङ्काः_सम्बन्धि(आकार_सम्बन्धि_Arg) (परिमाण(आकार_सम्बन्धि_Arg) *8)
#परिभाषय RTL_द्वयङ्काः_सम्बन्धि_क्षेत्रम्(type,क्षेत्रम्) (RTL_द्वयङ्काः_सम्बन्धि(RTL_क्षेत्रम्_TYPE(type,क्षेत्रम्)))
#परिभाषय CONTAINING_लेखः(स्थानाङ्कः,type,क्षेत्रम्) ((type *)((PCHAR)(स्थानाङ्कः) - (ULONG_PTR)(&((type *)0)->क्षेत्रम्)))

#परिभाषय VER_SERVER_NT 0x80000000
#परिभाषय VER_WORKSTATION_NT 0x40000000
#परिभाषय VER_SUITE_SMALLBUSINESS 0x00000001
#परिभाषय VER_SUITE_ENTERPRISE 0x00000002
#परिभाषय VER_SUITE_BACKOFFICE 0x00000004
#परिभाषय VER_SUITE_COMMUNICATIONS 0x00000008
#परिभाषय VER_SUITE_TERMINAL 0x00000010
#परिभाषय VER_SUITE_SMALLBUSINESS_RESTRICTED 0x00000020
#परिभाषय VER_SUITE_EMBEDDEDNT 0x00000040
#परिभाषय VER_SUITE_DATACENTER 0x00000080
#परिभाषय VER_SUITE_SINGLEUSERTS 0x00000100
#परिभाषय VER_SUITE_PERSONAL 0x00000200
#परिभाषय VER_SUITE_BLADE 0x00000400
#परिभाषय VER_SUITE_EMBEDDED_RESTRICTED 0x00000800
#परिभाषय VER_SUITE_SECURITY_APPLIANCE 0x00001000
#परिभाषय VER_SUITE_STORAGE_SERVER 0x00002000
#परिभाषय VER_SUITE_COMPUTE_SERVER 0x00004000

#परिभाषय गुणनफलम्_UNDEFINED                       0x0

#परिभाषय गुणनफलम्_ULTIMATE                        0x1
#परिभाषय गुणनफलम्_HOME_BASIC                      0x2
#परिभाषय गुणनफलम्_HOME_PREMIUM                    0x3
#परिभाषय गुणनफलम्_ENTERPRISE                      0x4
#परिभाषय गुणनफलम्_HOME_BASIC_N                    0x5
#परिभाषय गुणनफलम्_BUSINESS                        0x6
#परिभाषय गुणनफलम्_STANDARD_SERVER                 0x7
#परिभाषय गुणनफलम्_DATACENTER_SERVER               0x8
#परिभाषय गुणनफलम्_SMALLBUSINESS_SERVER            0x9
#परिभाषय गुणनफलम्_ENTERPRISE_SERVER               0xa
#परिभाषय गुणनफलम्_STARTER                         0xb
#परिभाषय गुणनफलम्_DATACENTER_SERVER_CORE          0xc
#परिभाषय गुणनफलम्_STANDARD_SERVER_CORE            0xd
#परिभाषय गुणनफलम्_ENTERPRISE_SERVER_CORE          0xe
#परिभाषय गुणनफलम्_ENTERPRISE_SERVER_IA64          0xf
#परिभाषय गुणनफलम्_BUSINESS_N                      0x10
#परिभाषय गुणनफलम्_WEB_SERVER                      0x11
#परिभाषय गुणनफलम्_CLUSTER_SERVER                  0x12
#परिभाषय गुणनफलम्_HOME_SERVER                     0x13
#परिभाषय गुणनफलम्_STORAGE_EXPRESS_SERVER          0x14
#परिभाषय गुणनफलम्_STORAGE_STANDARD_SERVER         0x15
#परिभाषय गुणनफलम्_STORAGE_WORKGROUP_SERVER        0x16
#परिभाषय गुणनफलम्_STORAGE_ENTERPRISE_SERVER       0x17
#परिभाषय गुणनफलम्_SERVER_FOR_SMALLBUSINESS        0x18
#परिभाषय गुणनफलम्_SMALLBUSINESS_SERVER_PREMIUM    0x19

#परिभाषय गुणनफलम्_UNLICENSED                      0xabcdabcd

#परिभाषय LANG_NEUTRAL 0x00
#परिभाषय LANG_INVARIANT 0x7f

#परिभाषय LANG_AFRIKAANS 0x36
#परिभाषय LANG_ALBANIAN 0x1c
#परिभाषय LANG_ALSATIAN 0x84
#परिभाषय LANG_AMHARIC 0x5e
#परिभाषय LANG_ARABIC 0x01
#परिभाषय LANG_ARMENIAN 0x2b
#परिभाषय LANG_ASSAMESE 0x4d
#परिभाषय LANG_AZERI 0x2c
#परिभाषय LANG_BASHKIR 0x6d
#परिभाषय LANG_BASQUE 0x2d
#परिभाषय LANG_BELARUSIAN 0x23
#परिभाषय LANG_BENGALI 0x45
#परिभाषय LANG_BRETON 0x7e
#परिभाषय LANG_BOSNIAN 0x1a
#परिभाषय LANG_BOSNIAN_NEUTRAL 0x781a
#परिभाषय LANG_BULGARIAN 0x02
#परिभाषय LANG_कातालान 0x03
#परिभाषय LANG_CHINESE 0x04
#परिभाषय LANG_CHINESE_SIMPLIFIED 0x04
#परिभाषय LANG_CHINESE_TRADITIONAL 0x7c04
#परिभाषय LANG_CORSICAN 0x83
#परिभाषय LANG_CROATIAN 0x1a
#परिभाषय LANG_CZECH 0x05
#परिभाषय LANG_DANISH 0x06
#परिभाषय LANG_DARI 0x8c
#परिभाषय LANG_DIVEHI 0x65
#परिभाषय LANG_DUTCH 0x13
#परिभाषय LANG_ENGLISH 0x09
#परिभाषय LANG_ESTONIAN 0x25
#परिभाषय LANG_FAEROESE 0x38
#परिभाषय LANG_FARSI 0x29
#परिभाषय LANG_FILIPINO 0x64
#परिभाषय LANG_FINNISH 0x0b
#परिभाषय LANG_FRENCH 0x0c
#परिभाषय LANG_FRISIAN 0x62
#परिभाषय LANG_GALICIAN 0x56
#परिभाषय LANG_GEORGIAN 0x37
#परिभाषय LANG_GERMAN 0x07
#परिभाषय LANG_GREEK 0x08
#परिभाषय LANG_GREENLANDIC 0x6f
#परिभाषय LANG_GUJARATI 0x47
#परिभाषय LANG_HAUSA 0x68
#परिभाषय LANG_HEBREW 0x0d
#परिभाषय LANG_HINDI 0x39
#परिभाषय LANG_HUNGARIAN 0x0e
#परिभाषय LANG_ICELANDIC 0x0f
#परिभाषय LANG_IGBO 0x70
#परिभाषय LANG_INDONESIAN 0x21
#परिभाषय LANG_INUKTITUT 0x5d
#परिभाषय LANG_IRISH 0x3c
#परिभाषय LANG_ITALIAN 0x10
#परिभाषय LANG_JAPANESE 0x11
#परिभाषय LANG_KANNADA 0x4b
#परिभाषय LANG_KASHMIRI 0x60
#परिभाषय LANG_KAZAK 0x3f
#परिभाषय LANG_KHMER 0x53
#परिभाषय LANG_KICHE 0x86
#परिभाषय LANG_KINYARWANDA 0x87
#परिभाषय LANG_KONKANI 0x57
#परिभाषय LANG_KOREAN 0x12
#परिभाषय LANG_KYRGYZ 0x40
#परिभाषय LANG_LAO 0x54
#परिभाषय LANG_LATVIAN 0x26
#परिभाषय LANG_LITHUANIAN 0x27
#परिभाषय LANG_अधस्तनम्_SORBIAN 0x2e
#परिभाषय LANG_LUXEMBOURGISH 0x6e
#परिभाषय LANG_MACEDONIAN 0x2f
#परिभाषय LANG_MALAY 0x3e
#परिभाषय LANG_MALAYALAM 0x4c
#परिभाषय LANG_MALTESE 0x3a
#परिभाषय LANG_MANIPURI 0x58
#परिभाषय LANG_MAORI 0x81
#परिभाषय LANG_MAPUDUNGUN 0x7a
#परिभाषय LANG_MARATHI 0x4e
#परिभाषय LANG_MOHAWK 0x7c
#परिभाषय LANG_MONGOLIAN 0x50
#परिभाषय LANG_NEPALI 0x61
#परिभाषय LANG_NORWEGIAN 0x14
#परिभाषय LANG_OCCITAN 0x82
#परिभाषय LANG_ORIYA 0x48
#परिभाषय LANG_PASHTO 0x63
#परिभाषय LANG_PERSIAN 0x29
#परिभाषय LANG_POLISH 0x15
#परिभाषय LANG_PORTUGUESE 0x16
#परिभाषय LANG_PUNJABI 0x46
#परिभाषय LANG_QUECHUA 0x6b
#परिभाषय LANG_ROMANIAN 0x18
#परिभाषय LANG_RUSSIAN 0x19
#परिभाषय LANG_SAMI 0x3b
#परिभाषय LANG_ROMANSH 0x17
#परिभाषय LANG_SANSKRIT 0x4f
#परिभाषय LANG_SERBIAN 0x1a
#परिभाषय LANG_SERBIAN_NEUTRAL 0x7c1a
#परिभाषय LANG_SINDHI 0x59
#परिभाषय LANG_SINHALESE 0x5b
#परिभाषय LANG_SLOVAK 0x1b
#परिभाषय LANG_SLOVENIAN 0x24
#परिभाषय LANG_SOTHO 0x6c
#परिभाषय LANG_SPANISH 0x0a
#परिभाषय LANG_SWAHILI 0x41
#परिभाषय LANG_SWEDISH 0x1d
#परिभाषय LANG_SYRIAC 0x5a
#परिभाषय LANG_TAJIK 0x28
#परिभाषय LANG_TAMAZIGHT 0x5f
#परिभाषय LANG_TAMIL 0x49
#परिभाषय LANG_TATAR 0x44
#परिभाषय LANG_TELUGU 0x4a
#परिभाषय LANG_THAI 0x1e
#परिभाषय LANG_TIBETAN 0x51
#परिभाषय LANG_TIGRIGNA 0x73
#परिभाषय LANG_TSWANA 0x32
#परिभाषय LANG_TURKISH 0x1f
#परिभाषय LANG_TURKMEN 0x42
#परिभाषय LANG_UIGHUR 0x80
#परिभाषय LANG_UKRAINIAN 0x22
#परिभाषय LANG_ऊर्ध्वस्थम्_SORBIAN 0x2e
#परिभाषय LANG_URDU 0x20
#परिभाषय LANG_UZBEK 0x43
#परिभाषय LANG_VIETNAMESE 0x2a
#परिभाषय LANG_WELSH 0x52
#परिभाषय LANG_WOLOF 0x88
#परिभाषय LANG_XHOSA 0x34
#परिभाषय LANG_YAKUT 0x85
#परिभाषय LANG_YI 0x78
#परिभाषय LANG_YORUBA 0x6a
#परिभाषय LANG_ZULU 0x35

#परिभाषय SUBLANG_NEUTRAL 0x0
#परिभाषय SUBLANG_DEFAULT 0x1
#परिभाषय SUBLANG_SYS_DEFAULT 0x2
#परिभाषय SUBLANG_CUSTOM_DEFAULT 0x3
#परिभाषय SUBLANG_CUSTOM_UNSPECIFIED 0x4
#परिभाषय SUBLANG_UI_CUSTOM_DEFAULT 0x5

#परिभाषय SUBLANG_ARABIC_SAUDI_ARABIA 0x01
#परिभाषय SUBLANG_ARABIC_IRAQ 0x02
#परिभाषय SUBLANG_ARABIC_EGYPT 0x03
#परिभाषय SUBLANG_ARABIC_LIBYA 0x04
#परिभाषय SUBLANG_ARABIC_ALGERIA 0x05
#परिभाषय SUBLANG_ARABIC_MOROCCO 0x06
#परिभाषय SUBLANG_ARABIC_TUNISIA 0x07
#परिभाषय SUBLANG_ARABIC_OMAN 0x08
#परिभाषय SUBLANG_ARABIC_YEMEN 0x09
#परिभाषय SUBLANG_ARABIC_SYRIA 0x0a
#परिभाषय SUBLANG_ARABIC_JORDAN 0x0b
#परिभाषय SUBLANG_ARABIC_LEBANON 0x0c
#परिभाषय SUBLANG_ARABIC_KUWAIT 0x0d
#परिभाषय SUBLANG_ARABIC_UAE 0x0e
#परिभाषय SUBLANG_ARABIC_BAHRAIN 0x0f
#परिभाषय SUBLANG_ARABIC_QATAR 0x10
#परिभाषय SUBLANG_AZERI_LATIN 0x01
#परिभाषय SUBLANG_AZERI_CYRILLIC 0x02
#परिभाषय SUBLANG_CHINESE_TRADITIONAL 0x01
#परिभाषय SUBLANG_CHINESE_SIMPLIFIED 0x02
#परिभाषय SUBLANG_CHINESE_HONGKONG 0x03
#परिभाषय SUBLANG_CHINESE_SINGAPORE 0x04
#परिभाषय SUBLANG_CHINESE_MACAU 0x05
#परिभाषय SUBLANG_DUTCH 0x01
#परिभाषय SUBLANG_DUTCH_BELGIAN 0x02
#परिभाषय SUBLANG_ENGLISH_US 0x01
#परिभाषय SUBLANG_ENGLISH_UK 0x02
#परिभाषय SUBLANG_ENGLISH_AUS 0x03
#परिभाषय SUBLANG_ENGLISH_CAN 0x04
#परिभाषय SUBLANG_ENGLISH_NZ 0x05
#परिभाषय SUBLANG_ENGLISH_EIRE 0x06
#परिभाषय SUBLANG_ENGLISH_SOUTH_AFRICA 0x07
#परिभाषय SUBLANG_ENGLISH_JAMAICA 0x08
#परिभाषय SUBLANG_ENGLISH_CARIBBEAN 0x09
#परिभाषय SUBLANG_ENGLISH_BELIZE 0x0a
#परिभाषय SUBLANG_ENGLISH_TRINIDAD 0x0b
#परिभाषय SUBLANG_ENGLISH_ZIMBABWE 0x0c
#परिभाषय SUBLANG_ENGLISH_PHILIPPINES 0x0d
#परिभाषय SUBLANG_FRENCH 0x01
#परिभाषय SUBLANG_FRENCH_BELGIAN 0x02
#परिभाषय SUBLANG_FRENCH_CANADIAN 0x03
#परिभाषय SUBLANG_FRENCH_SWISS 0x04
#परिभाषय SUBLANG_FRENCH_LUXEMBOURG 0x05
#परिभाषय SUBLANG_FRENCH_MONACO 0x06
#परिभाषय SUBLANG_GERMAN 0x01
#परिभाषय SUBLANG_GERMAN_SWISS 0x02
#परिभाषय SUBLANG_GERMAN_AUSTRIAN 0x03
#परिभाषय SUBLANG_GERMAN_LUXEMBOURG 0x04
#परिभाषय SUBLANG_GERMAN_LIECHTENSTEIN 0x05
#परिभाषय SUBLANG_ITALIAN 0x01
#परिभाषय SUBLANG_ITALIAN_SWISS 0x02
#परिभाषय SUBLANG_KASHMIRI_SASIA 0x02
#परिभाषय SUBLANG_KASHMIRI_INDIA 0x02
#परिभाषय SUBLANG_KOREAN 0x01
#परिभाषय SUBLANG_LITHUANIAN 0x01
#परिभाषय SUBLANG_MALAY_MALAYSIA 0x01
#परिभाषय SUBLANG_MALAY_BRUNEI_DARUSSALAM 0x02
#परिभाषय SUBLANG_NEPALI_INDIA 0x02
#परिभाषय SUBLANG_NORWEGIAN_BOKMAL 0x01
#परिभाषय SUBLANG_NORWEGIAN_NYNORSK 0x02
#परिभाषय SUBLANG_PORTUGUESE 0x02
#परिभाषय SUBLANG_PORTUGUESE_BRAZILIAN 0x01
#परिभाषय SUBLANG_SERBIAN_LATIN 0x02
#परिभाषय SUBLANG_SERBIAN_CYRILLIC 0x03
#परिभाषय SUBLANG_SPANISH 0x01
#परिभाषय SUBLANG_SPANISH_MEXICAN 0x02
#परिभाषय SUBLANG_SPANISH_MODERN 0x03
#परिभाषय SUBLANG_SPANISH_GUATEMALA 0x04
#परिभाषय SUBLANG_SPANISH_COSTA_RICA 0x05
#परिभाषय SUBLANG_SPANISH_PANAMA 0x06
#परिभाषय SUBLANG_SPANISH_DOMINICAN_REPUBLIC 0x07
#परिभाषय SUBLANG_SPANISH_VENEZUELA 0x08
#परिभाषय SUBLANG_SPANISH_COLOMBIA 0x09
#परिभाषय SUBLANG_SPANISH_PERU 0x0a
#परिभाषय SUBLANG_SPANISH_ARGENTINA 0x0b
#परिभाषय SUBLANG_SPANISH_ECUADOR 0x0c
#परिभाषय SUBLANG_SPANISH_CHILE 0x0d
#परिभाषय SUBLANG_SPANISH_URUGUAY 0x0e
#परिभाषय SUBLANG_SPANISH_PARAGUAY 0x0f
#परिभाषय SUBLANG_SPANISH_BOLIVIA 0x10
#परिभाषय SUBLANG_SPANISH_EL_SALVADOR 0x11
#परिभाषय SUBLANG_SPANISH_HONDURAS 0x12
#परिभाषय SUBLANG_SPANISH_NICARAGUA 0x13
#परिभाषय SUBLANG_SPANISH_PUERTO_RICO 0x14
#परिभाषय SUBLANG_SWEDISH 0x01
#परिभाषय SUBLANG_SWEDISH_FINLAND 0x02
#परिभाषय SUBLANG_URDU_PAKISTAN 0x01
#परिभाषय SUBLANG_URDU_INDIA 0x02
#परिभाषय SUBLANG_UZBEK_LATIN 0x01
#परिभाषय SUBLANG_UZBEK_CYRILLIC 0x02

#परिभाषय क्रमय_DEFAULT 0x0
#परिभाषय क्रमय_INVARIANT_MATH 0x1

#परिभाषय क्रमय_JAPANESE_XJIS 0x0
#परिभाषय क्रमय_JAPANESE_UNICODE 0x1
#परिभाषय क्रमय_JAPANESE_RADICALSTROKE 0x4

#परिभाषय क्रमय_CHINESE_BIG5 0x0
#परिभाषय क्रमय_CHINESE_PRCP 0x0
#परिभाषय क्रमय_CHINESE_UNICODE 0x1
#परिभाषय क्रमय_CHINESE_PRC 0x2
#परिभाषय क्रमय_CHINESE_BOPOMOFO 0x3

#परिभाषय क्रमय_KOREAN_KSC 0x0
#परिभाषय क्रमय_KOREAN_UNICODE 0x1

#परिभाषय क्रमय_GERMAN_PHONE_BOOK 0x1

#परिभाषय क्रमय_HUNGARIAN_DEFAULT 0x0
#परिभाषय क्रमय_HUNGARIAN_TECHNICAL 0x1

#परिभाषय क्रमय_GEORGIAN_TRADITIONAL 0x0
#परिभाषय क्रमय_GEORGIAN_MODERN 0x1

#परिभाषय MAKELANGID(p,s) ((((WORD)(s)) << 10) | (WORD)(p))
#परिभाषय PRIMARYLANGID(lgid) ((WORD)(lgid) & 0x3ff)
#परिभाषय SUBLANGID(lgid) ((WORD)(lgid) >> 10)

#परिभाषय NLS_VALID_LOCALE_आवरणम् 0x000fffff

#परिभाषय MAKELCID(lgid,srtid) ((DWORD)((((DWORD)((WORD)(srtid))) << 16) | ((DWORD)((WORD)(lgid)))))
#परिभाषय MAKESORTLCID(lgid,srtid,ver) ((DWORD)((MAKELCID(lgid,srtid)) | (((DWORD)((WORD)(ver))) << 20)))
#परिभाषय LANGIDFROMLCID(lcid) ((WORD)(lcid))
#परिभाषय SORTIDFROMLCID(lcid) ((WORD)((((DWORD)(lcid)) >> 16) & 0xf))
#परिभाषय SORTVERSIONFROMLCID(lcid) ((WORD)((((DWORD)(lcid)) >> 20) & 0xf))

#परिभाषय LOCALE_NAME_MAX_दीर्घता 85
#परिभाषय LANG_SYSTEM_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_SYS_DEFAULT))
#परिभाषय LANG_USER_DEFAULT (MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT))

#परिभाषय LOCALE_SYSTEM_DEFAULT (MAKELCID(LANG_SYSTEM_DEFAULT,क्रमय_DEFAULT))
#परिभाषय LOCALE_USER_DEFAULT (MAKELCID(LANG_USER_DEFAULT,क्रमय_DEFAULT))

#परिभाषय LOCALE_NEUTRAL (MAKELCID(MAKELANGID(LANG_NEUTRAL,SUBLANG_NEUTRAL),क्रमय_DEFAULT))

#परिभाषय LOCALE_CUSTOM_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), क्रमय_DEFAULT))
#परिभाषय LOCALE_CUSTOM_UNSPECIFIED (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), क्रमय_DEFAULT))
#परिभाषय LOCALE_CUSTOM_UI_DEFAULT (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), क्रमय_DEFAULT))

#परिभाषय LOCALE_INVARIANT (MAKELCID(MAKELANGID(LANG_INVARIANT,SUBLANG_NEUTRAL),क्रमय_DEFAULT))

#परिभाषय UNREFERENCED_PARAMETER(P) (P)
#परिभाषय DBG_UNREFERENCED_PARAMETER(P) (P)
#परिभाषय DBG_UNREFERENCED_LOCAL_VARIABLE(V) (V)

#परिभाषय DEFAULT_UNREACHABLE

#यदि_अपरिभाषितम् WIN32_NO_स्थितिः
#परिभाषय स्थितिः_WAIT_0 ((DWORD)0x00000000L)
#परिभाषय स्थितिः_ABANDONED_WAIT_0 ((DWORD)0x00000080L)
#परिभाषय स्थितिः_USER_APC ((DWORD)0x000000C0L)
#परिभाषय स्थितिः_TIMEOUT ((DWORD)0x00000102L)
#परिभाषय स्थितिः_PENDING ((DWORD)0x00000103L)
#परिभाषय DBG_EXCEPTION_HANDLED ((DWORD)0x00010001L)
#परिभाषय DBG_CONTINUE ((DWORD)0x00010002L)
#परिभाषय स्थितिः_SEGMENT_NOTIFICATION ((DWORD)0x40000005L)
#परिभाषय DBG_TERMINATE_THREAD ((DWORD)0x40010003L)
#परिभाषय DBG_TERMINATE_PROCESS ((DWORD)0x40010004L)
#परिभाषय DBG_CONTROL_C ((DWORD)0x40010005L)
#परिभाषय DBG_CONTROL_BREAK ((DWORD)0x40010008L)
#परिभाषय DBG_COMMAND_EXCEPTION ((DWORD)0x40010009L)
#परिभाषय स्थितिः_GUARD_PAGE_VIOLATION ((DWORD)0x80000001L)
#परिभाषय स्थितिः_DATATYPE_MISALIGNMENT ((DWORD)0x80000002L)
#परिभाषय स्थितिः_BREAKPOINT ((DWORD)0x80000003L)
#परिभाषय स्थितिः_SINGLE_चरणः ((DWORD)0x80000004L)
#परिभाषय DBG_EXCEPTION_NOT_HANDLED ((DWORD)0x80010001L)
#परिभाषय स्थितिः_ACCESS_VIOLATION ((DWORD)0xC0000005L)
#परिभाषय स्थितिः_अन्तर्_PAGE_ERROR ((DWORD)0xC0000006L)
#परिभाषय स्थितिः_INVALID_HANDLE ((DWORD)0xC0000008L)
#परिभाषय स्थितिः_NO_स्मृतिः ((DWORD)0xC0000017L)
#परिभाषय स्थितिः_ILLEGAL_INSTRUCTION ((DWORD)0xC000001DL)
#परिभाषय स्थितिः_NONCONTINUABLE_EXCEPTION ((DWORD)0xC0000025L)
#परिभाषय स्थितिः_INVALID_DISPOSITION ((DWORD)0xC0000026L)
#परिभाषय स्थितिः_ARRAY_BOUNDS_EXCEEDED ((DWORD)0xC000008CL)
#परिभाषय स्थितिः_FLOAT_DENORMAL_सङ्कार्यम् ((DWORD)0xC000008DL)
#परिभाषय स्थितिः_FLOAT_DIVIDE_BY_ZERO ((DWORD)0xC000008EL)
#परिभाषय स्थितिः_FLOAT_INEXACT_परिणाम ((DWORD)0xC000008FL)
#परिभाषय स्थितिः_FLOAT_INVALID_OPERATION ((DWORD)0xC0000090L)
#परिभाषय स्थितिः_FLOAT_अतिप्रवाहः ((DWORD)0xC0000091L)
#परिभाषय स्थितिः_FLOAT_राशिः_CHECK ((DWORD)0xC0000092L)
#परिभाषय स्थितिः_FLOAT_UNDERFLOW ((DWORD)0xC0000093L)
#परिभाषय स्थितिः_INTEGER_DIVIDE_BY_ZERO ((DWORD)0xC0000094L)
#परिभाषय स्थितिः_INTEGER_अतिप्रवाहः ((DWORD)0xC0000095L)
#परिभाषय स्थितिः_PRIVILEGED_INSTRUCTION ((DWORD)0xC0000096L)
#परिभाषय स्थितिः_राशिः_अतिप्रवाहः ((DWORD)0xC00000FDL)
#परिभाषय स्थितिः_CONTROL_C_EXIT ((DWORD)0xC000013AL)
#परिभाषय स्थितिः_FLOAT_गुणजः_दोषाः ((DWORD)0xC00002B4L)
#परिभाषय स्थितिः_FLOAT_गुणजः_TRAPS ((DWORD)0xC00002B5L)
#परिभाषय स्थितिः_REG_NAT_CONSUMPTION ((DWORD)0xC00002C9L)
#परिभाषय स्थितिः_SXS_EARLY_DEACTIVATION ((DWORD)0xC015000FL)
#परिभाषय स्थितिः_SXS_INVALID_DEACTIVATION ((DWORD)0xC0150010L)
#यदि_अन्तः

#परिभाषय अधिकतमम्_WAIT_OBJECTS 64
#परिभाषय अधिकतमम्_SUSPEND_गणनम् MAXCHAR

  प्रकारनिर्देश ULONG_PTR KSPIN_तालकम्;
  प्रकारनिर्देश KSPIN_तालकम् *PKSPIN_तालकम्;

#यदि defined(__x86_64) && !defined(RC_INVOKED)

#यदि_परिभाषितम् __cplusplus
  बाह्य "C" {
#यदि_अन्तः

#परिभाषय BitTest _bittest
#परिभाषय BitTestAndComplement _bittestandcomplement
#परिभाषय Bit_Test_And_समुच्चयः _bittestandset
#परिभाषय BitTestAndReset _bittestandreset
#परिभाषय Interlocked_Bit_Test_And_समुच्चयः _interlockedbittestandset
#परिभाषय InterlockedBitTestAndReset _interlockedbittestandreset
#परिभाषय BitTest64 _bittest64
#परिभाषय BitTestAndComplement64 _bittestandcomplement64
#परिभाषय BitTestAndSet64 _bittestandset64
#परिभाषय BitTestAndReset64 _bittestandreset64
#परिभाषय InterlockedBitTestAndSet64 _interlockedbittestandset64
#परिभाषय InterlockedBitTestAndReset64 _interlockedbittestandreset64

    __CRT_INLINE BOOLEAN _bittest(LONG ध्रुव *आधारः_2,LONG विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement(LONG *आधारः_2,LONG विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement(LONG *आधारः_2,LONG Bit) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (Bit));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset(LONG *आधारः_2,LONG विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset(LONG *आधारः_2,LONG विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset(LONG *आधारः_2,LONG विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset(LONG *आधारः_2,LONG विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittest64(LONG64 ध्रुव *आधारः_2,LONG64 विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandcomplement64(LONG64 *आधारः_2,LONG64 विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandset64(LONG64 *आधारः_2,LONG64 विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _bittestandreset64(LONG64 *आधारः_2,LONG64 विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandset64(LONG64 *आधारः_2,LONG64 विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
    __CRT_INLINE BOOLEAN _interlockedbittestandreset64(LONG64 *आधारः_2,LONG64 विस्थापनम्_3) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ दीर्घ *) आधारः_2))
	:"Ir" (विस्थापनम्_3));
      प्रत्यागम (BOOLEAN) (old!=0);
    }
#परिभाषय Bit_अवलोकनम्_Forward Bit_अवलोकनम्_Forward_2
#परिभाषय Bit_अवलोकनम्_Reverse Bit_अवलोकनम्_Reverse_2
#परिभाषय Bit_अवलोकनम्_Forward64 Bit_अवलोकनम्_Forward64_2
#परिभाषय Bit_अवलोकनम्_Reverse64 Bit_अवलोकनम्_Reverse64_2

    __CRT_INLINE BOOLEAN Bit_अवलोकनम्_Forward_2(DWORD *सूचकांक_3,DWORD आवरणम्_3) {
      __asm__ __volatile__("bsfl %1,%0" : "=r" (आवरणम्_3),"=m" ((*(चञ्चल दीर्घ *)सूचकांक_3)));
      प्रत्यागम आवरणम्_3!=0;
    }
    __CRT_INLINE BOOLEAN Bit_अवलोकनम्_Reverse_2(DWORD *सूचकांक_3,DWORD आवरणम्_3) {
      __asm__ __volatile__("bsrl %1,%0" : "=r" (आवरणम्_3),"=m" ((*(चञ्चल दीर्घ *)सूचकांक_3)));
      प्रत्यागम आवरणम्_3!=0;
    }
    __CRT_INLINE BOOLEAN Bit_अवलोकनम्_Forward64_2(DWORD *सूचकांक_3,DWORD64 आवरणम्_3) {
      __asm__ __volatile__("bsfq %1,%0" : "=r" (आवरणम्_3),"=m" ((*(चञ्चल दीर्घ दीर्घ *)सूचकांक_3)));
      प्रत्यागम आवरणम्_3!=0;
    }
    __CRT_INLINE BOOLEAN Bit_अवलोकनम्_Reverse64_2(DWORD *सूचकांक_3,DWORD64 आवरणम्_3) {
      __asm__ __volatile__("bsrq %1,%0" : "=r" (आवरणम्_3),"=m" ((*(चञ्चल दीर्घ दीर्घ *)सूचकांक_3)));
      प्रत्यागम आवरणम्_3!=0;
    }

#परिभाषय InterlockedIncrement16 _InterlockedIncrement16
#परिभाषय InterlockedDecrement16 _InterlockedDecrement16
#परिभाषय InterlockedCompareExchange16 _InterlockedCompareExchange16

#परिभाषय InterlockedAnd _InterlockedAnd
#परिभाषय InterlockedOr _InterlockedOr
#परिभाषय InterlockedXor _InterlockedXor
#परिभाषय InterlockedIncrement _InterlockedIncrement
#परिभाषय InterlockedIncrementAcquire InterlockedIncrement
#परिभाषय InterlockedIncrementRelease InterlockedIncrement
#परिभाषय InterlockedDecrement _InterlockedDecrement
#परिभाषय InterlockedDecrementAcquire InterlockedDecrement
#परिभाषय InterlockedDecrementRelease InterlockedDecrement
#परिभाषय Interlocked_सङ्कलय Interlocked_सङ्कलय_2
#परिभाषय InterlockedExchange _InterlockedExchange
#परिभाषय Interlocked_Exchange_सङ्कलय Interlocked_Exchange_सङ्कलय_2
#परिभाषय InterlockedCompareExchange _InterlockedCompareExchange
#परिभाषय InterlockedCompareExchangeAcquire InterlockedCompareExchange
#परिभाषय InterlockedCompareExchangeRelease InterlockedCompareExchange

#परिभाषय InterlockedAnd64 _InterlockedAnd64
#परिभाषय InterlockedAndAffinity InterlockedAnd64
#परिभाषय InterlockedOr64 _InterlockedOr64
#परिभाषय InterlockedOrAffinity InterlockedOr64
#परिभाषय InterlockedXor64 _InterlockedXor64
#परिभाषय InterlockedIncrement64 _InterlockedIncrement64
#परिभाषय InterlockedDecrement64 _InterlockedDecrement64
#परिभाषय InterlockedAdd64 _InterlockedAdd64
#परिभाषय InterlockedExchange64 _InterlockedExchange64
#परिभाषय InterlockedExchangeAcquire64 InterlockedExchange64
#परिभाषय InterlockedExchangeAdd64 _InterlockedExchangeAdd64
#परिभाषय InterlockedCompareExchange64 _InterlockedCompareExchange64
#परिभाषय InterlockedCompareExchangeAcquire64 InterlockedCompareExchange64
#परिभाषय InterlockedCompareExchangeRelease64 InterlockedCompareExchange64

#परिभाषय InterlockedExchangePointer _InterlockedExchangePointer
#परिभाषय InterlockedCompareExchangePointer _InterlockedCompareExchangePointer
#परिभाषय InterlockedCompareExchangePointerAcquire _InterlockedCompareExchangePointer
#परिभाषय InterlockedCompareExchangePointerRelease _InterlockedCompareExchangePointer

#परिभाषय Interlocked_Exchange_सङ्कलय_आकार_T(a,b) InterlockedExchangeAdd64((LONG64 *)a,b)
#परिभाषय Interlocked_Increment_आकार_T(a) InterlockedIncrement64((LONG64 *)a)
#परिभाषय Interlocked_Decrement_आकार_T(a) InterlockedDecrement64((LONG64 *)a)

    __CRT_INLINE SHORT InterlockedIncrement16(SHORT चञ्चल *Addend) {
      अचिह्नित वर्ण c;
      अचिह्नित वर्ण s;
      __asm__ __volatile__(
	"lock ; addw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      प्रत्यागम (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedDecrement16(SHORT चञ्चल *Addend) {
      अचिह्नित वर्ण c;
      अचिह्नित वर्ण s;
      __asm__ __volatile__(
	"lock ; subw $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      प्रत्यागम (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE SHORT InterlockedCompareExchange16(SHORT चञ्चल *Destination,SHORT ExChange,SHORT Comperand) {
      SHORT पूर्व;
      __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
	:"=a"(पूर्व)
	:"q"(ExChange), "m"(*Destination), "0"(Comperand)
	: "memory");
      प्रत्यागम पूर्व;
    }
    __CRT_INLINE LONG InterlockedAnd(LONG चञ्चल *Destination,LONG मानम्_3) {
      __asm__ __volatile__("lock ; andl %0,%1"
	: :"r"(मानम्_3),"m"(*Destination)
	: "memory");
      प्रत्यागम *Destination;
    }
    __CRT_INLINE LONG InterlockedOr(LONG चञ्चल *Destination,LONG मानम्_3) {
      __asm__ __volatile__("lock ; orl %0,%1"
	: : "r"(मानम्_3),"m"(*Destination) : "memory");
      प्रत्यागम *Destination;
    }
    __CRT_INLINE LONG InterlockedXor(LONG चञ्चल *Destination,LONG मानम्_3) {
      __asm__ __volatile__("lock ; xorl %0,%1"
	: : "r"(मानम्_3),"m"(*Destination) : "memory");
      प्रत्यागम *Destination;
    }
    //		$$$$
    __CRT_INLINE LONG64 InterlockedAnd64(LONG64 चञ्चल *Destination,LONG64 मानम्_3) {
      __asm__ __volatile__("lock ; andq %0,%1"
	: : "r"(मानम्_3),"m"(*Destination) : "memory");
      प्रत्यागम *Destination;
    }
    __CRT_INLINE LONG64 InterlockedOr64(LONG64 चञ्चल *Destination,LONG64 मानम्_3) {
      __asm__ __volatile__("lock ; orq %0,%1"
	: : "r"(मानम्_3),"m"(*Destination) : "memory");
      प्रत्यागम *Destination;
    }
    __CRT_INLINE LONG64 InterlockedXor64(LONG64 चञ्चल *Destination,LONG64 मानम्_3) {
      __asm__ __volatile__("lock ; xorq %0,%1"
	: : "r"(मानम्_3),"m"(*Destination) : "memory");
      प्रत्यागम *Destination;
    }
    __CRT_INLINE LONG InterlockedIncrement(LONG चञ्चल *Addend) {
      अचिह्नित वर्ण c;
      अचिह्नित वर्ण s;
      __asm__ __volatile__(
	"lock ; addl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      प्रत्यागम (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedDecrement(LONG चञ्चल *Addend) {
      अचिह्नित वर्ण c;
      अचिह्नित वर्ण s;
      __asm__ __volatile__(
	"lock ; subl $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      प्रत्यागम (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG InterlockedExchange(LONG चञ्चल *Target,LONG मानम्_3) {
      __asm__ __volatile("lock ; xchgl %0,%1"
	: "=r"(मानम्_3)
	: "m"(*Target),"0"(मानम्_3)
	: "memory");
      प्रत्यागम मानम्_3;
    }
    LONG Interlocked_Exchange_सङ्कलय(LONG चञ्चल *Addend,LONG मानम्_3);

#यदि_अपरिभाषितम् _X86AMD64_
    __CRT_INLINE LONG Interlocked_सङ्कलय(LONG चञ्चल *Addend,LONG मानम्_3) { प्रत्यागम Interlocked_Exchange_सङ्कलय(Addend,मानम्_3) + मानम्_3; }
#यदि_अन्तः
    __CRT_INLINE LONG InterlockedCompareExchange(LONG चञ्चल *Destination,LONG ExChange,LONG Comperand) {
      LONG पूर्व;
      __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (पूर्व) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      प्रत्यागम पूर्व;
    }
    __CRT_INLINE LONG64 InterlockedIncrement64(LONG64 चञ्चल *Addend) {
      अचिह्नित वर्ण c;
      अचिह्नित वर्ण s;
      __asm__ __volatile__(
	"lock ; addq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      प्रत्यागम (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedDecrement64(LONG64 चञ्चल *Addend) {
      अचिह्नित वर्ण c;
      अचिह्नित वर्ण s;
      __asm__ __volatile__(
	"lock ; subq $1,%0; sete %1 ; sets %2"
	:"=m" (*Addend), "=qm" (c), "=qm" (s)
	:"m" (*Addend) : "memory");
      प्रत्यागम (c != 0 ? 0 : (s != 0 ? -1 : 1));
    }
    __CRT_INLINE LONG64 InterlockedExchange64(LONG64 चञ्चल *Target,LONG64 मानम्_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(मानम्_3)
	: "m"(*Target),"0"(मानम्_3)
	: "memory");
      प्रत्यागम मानम्_3;
    }
    LONG64 InterlockedExchangeAdd64(LONG64 चञ्चल *Addend,LONG64 मानम्_3);

#यदि_अपरिभाषितम् _X86AMD64_
    __CRT_INLINE LONG64 InterlockedAdd64(LONG64 चञ्चल *Addend,LONG64 मानम्_3) { प्रत्यागम InterlockedExchangeAdd64(Addend,मानम्_3) + मानम्_3; }
#यदि_अन्तः

    __CRT_INLINE LONG64 InterlockedCompareExchange64(LONG64 चञ्चल *Destination,LONG64 ExChange,LONG64 Comperand) {
      LONG64 पूर्व;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (पूर्व) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      प्रत्यागम पूर्व;
    }
    __CRT_INLINE PVOID InterlockedCompareExchangePointer(PVOID चञ्चल *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID पूर्व;
      __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (पूर्व) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
      प्रत्यागम पूर्व;
    }
    __CRT_INLINE PVOID InterlockedExchangePointer(PVOID चञ्चल *Target,PVOID मानम्_3) {
      __asm__ __volatile("lock ; xchgq %0,%1"
	: "=r"(मानम्_3)
	: "m"(*Target),"0"(मानम्_3)
	: "memory");
      प्रत्यागम मानम्_3;
    }

#परिभाषय Cache_पङ्क्तिः_Flush(स्थानाङ्कः_2) _mm_clflush(स्थानाङ्कः_2)

    VOID _ReadWriteBarrier(VOID);

#परिभाषय FastFence __faststorefence
#परिभाषय आरोपय_Fence _mm_lfence
#परिभाषय स्मृतिः_Fence _mm_mfence
#परिभाषय StoreFence _mm_sfence

    VOID __faststorefence(VOID);
    VOID _m_prefetchw(चञ्चल CONST VOID *Source);

//!__TINYC__: #include <intrin.h>

#परिभाषय YieldProcessor _mm_pause
#परिभाषय स्मृतिः_Barrier __faststorefence
#परिभाषय Pre_Fetch_Cache_पङ्क्तिः(l,a) _mm_prefetch((CHAR CONST *) a,l)
#परिभाषय PrefetchForWrite(p) _m_prefetchw(p)
#परिभाषय ReadForWriteAccess(p) (_m_prefetchw(p),*(p))

#परिभाषय PF_TEMPORAL_LEVEL_1 _MM_HINT_T0
#परिभाषय PF_TEMPORAL_LEVEL_2 _MM_HINT_T1
#परिभाषय PF_TEMPORAL_LEVEL_3 _MM_HINT_T2
#परिभाषय PF_NON_TEMPORAL_LEVEL_ALL _MM_HINT_NTA

#परिभाषय ReadMxCsr _mm_getcsr
#परिभाषय WriteMxCsr _mm_setcsr

    VOID __int2c(VOID);

#परिभाषय DbgRaiseAssertionFailure() __int2c()
#परिभाषय GetCallersEflags() __getcallerseflags()

    अचिह्नित __int32 __getcallerseflags(VOID);

#परिभाषय Get_Segment_सीमा __segmentlimit

    DWORD __segmentlimit(DWORD Selector);

#परिभाषय Read_Time_Stamp_गणक() __rdtsc()

    DWORD64 __rdtsc(VOID);
    VOID __movsb(PBYTE Destination,BYTE ध्रुव *Source,आकार_T गणनम्_3);
    VOID __movsw(PWORD Destination,WORD ध्रुव *Source,आकार_T गणनम्_3);
    VOID __movsd(PDWORD Destination,DWORD ध्रुव *Source,आकार_T गणनम्_3);
    VOID __movsq(PDWORD64 Destination,DWORD64 ध्रुव *Source,आकार_T गणनम्_3);
    VOID __stosb(PBYTE Destination,BYTE मानम्_3,आकार_T गणनम्_3);
    VOID __stosw(PWORD Destination,WORD मानम्_3,आकार_T गणनम्_3);
    VOID __stosd(PDWORD Destination,DWORD मानम्_3,आकार_T गणनम्_3);
    VOID __stosq(PDWORD64 Destination,DWORD64 मानम्_3,आकार_T गणनम्_3);

#परिभाषय Multiply_उच्चः __mulh
#परिभाषय Unsigned_Multiply_उच्चः __umulh

    LONGLONG Multiply_उच्चः(LONGLONG Multiplier,LONGLONG Multiplicand);
    ULONGLONG Unsigned_Multiply_उच्चः(ULONGLONG Multiplier,ULONGLONG Multiplicand);

#परिभाषय सरणम्_Left128 __shiftleft128
#परिभाषय सरणम्_Right128 __shiftright128

    DWORD64 सरणम्_Left128(DWORD64 नीचः_Part,DWORD64 उच्चः_Part,BYTE सरणम्_3);
    DWORD64 सरणम्_Right128(DWORD64 नीचः_Part,DWORD64 उच्चः_Part,BYTE सरणम्_3);

#परिभाषय Multiply128 _mul128

    LONG64 Multiply128(LONG64 Multiplier,LONG64 Multiplicand,LONG64 *उच्चः_गुणनफलम्);

#परिभाषय UnsignedMultiply128 _umul128

    DWORD64 UnsignedMultiply128(DWORD64 Multiplier,DWORD64 Multiplicand,DWORD64 *उच्चः_गुणनफलम्);

    __CRT_INLINE LONG64 MultiplyExtract128(LONG64 Multiplier,LONG64 Multiplicand,BYTE सरणम्_3) {
      LONG64 extracted_गुणनफलम्;
      LONG64 उच्चः_गुणनफलम्_2;
      LONG64 नीचः_गुणनफलम्;
      नीचः_गुणनफलम् = Multiply128(Multiplier,Multiplicand,&उच्चः_गुणनफलम्_2);
      extracted_गुणनफलम् = (LONG64)सरणम्_Right128((LONG64)नीचः_गुणनफलम्,(LONG64)उच्चः_गुणनफलम्_2,सरणम्_3);
      प्रत्यागम extracted_गुणनफलम्;
    }

    __CRT_INLINE DWORD64 UnsignedMultiplyExtract128(DWORD64 Multiplier,DWORD64 Multiplicand,BYTE सरणम्_3) {
      DWORD64 extracted_गुणनफलम्;
      DWORD64 उच्चः_गुणनफलम्_2;
      DWORD64 नीचः_गुणनफलम्;
      नीचः_गुणनफलम् = UnsignedMultiply128(Multiplier,Multiplicand,&उच्चः_गुणनफलम्_2);
      extracted_गुणनफलम् = सरणम्_Right128(नीचः_गुणनफलम्,उच्चः_गुणनफलम्_2,सरणम्_3);
      प्रत्यागम extracted_गुणनफलम्;
    }

    __CRT_INLINE BYTE __readgsbyte(DWORD विस्थापनम्_3) {
      BYTE ret;
      __asm__ चञ्चल ("movb	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(चञ्चल दीर्घ *) (DWORD64) विस्थापनम्_3)));
      प्रत्यागम ret;
    }
    __CRT_INLINE WORD __readgsword(DWORD विस्थापनम्_3) {
      WORD ret;
      __asm__ चञ्चल ("movw	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(चञ्चल दीर्घ *) (DWORD64) विस्थापनम्_3)));
      प्रत्यागम ret;
    }
    __CRT_INLINE DWORD __readgsdword(DWORD विस्थापनम्_3) {
      DWORD ret;
      __asm__ चञ्चल ("movl	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(चञ्चल दीर्घ *) (DWORD64) विस्थापनम्_3)));
      प्रत्यागम ret;
    }
    __CRT_INLINE DWORD64 __readgsqword(DWORD विस्थापनम्_3) {
      शून्य *ret;
      __asm__ चञ्चल ("movq	%%gs:%1,%0"
	: "=r" (ret) ,"=m" ((*(चञ्चल दीर्घ *) (DWORD64) विस्थापनम्_3)));
      प्रत्यागम (DWORD64) ret;
    }
    __CRT_INLINE VOID __writegsbyte(DWORD विस्थापनम्_3,BYTE दत्त_3) {
      __asm__ चञ्चल ("movb	%0,%%gs:%1"
	: "=r" (दत्त_3) ,"=m" ((*(चञ्चल दीर्घ *) (DWORD64) विस्थापनम्_3)));
    }
    __CRT_INLINE VOID __writegsword(DWORD विस्थापनम्_3,WORD दत्त_3) {
      __asm__ चञ्चल ("movw	%0,%%gs:%1"
	: "=r" (दत्त_3) ,"=m" ((*(चञ्चल दीर्घ *) (DWORD64) विस्थापनम्_3)));
    }
    __CRT_INLINE VOID __writegsdword(DWORD विस्थापनम्_3,DWORD दत्त_3) {
      __asm__ चञ्चल ("movl	%0,%%gs:%1"
	: "=r" (दत्त_3) ,"=m" ((*(चञ्चल दीर्घ *) (DWORD64) विस्थापनम्_3)));
    }
    __CRT_INLINE VOID __writegsqword(DWORD विस्थापनम्_3,DWORD64 दत्त_3) {
      __asm__ चञ्चल ("movq	%0,%%gs:%1"
	: "=r" (दत्त_3) ,"=m" ((*(चञ्चल दीर्घ *) (DWORD64) विस्थापनम्_3)));
    }

#यदि_परिभाषितम् __cplusplus
  }
#यदि_अन्तः

#परिभाषय EXCEPTION_READ_FAULT 0
#परिभाषय EXCEPTION_WRITE_FAULT 1
#परिभाषय EXCEPTION_EXECUTE_FAULT 8

#यदि !defined(RC_INVOKED)

#परिभाषय CONTEXT_AMD64 0x100000

#परिभाषय CONTEXT_CONTROL (CONTEXT_AMD64 | 0x1L)
#परिभाषय CONTEXT_INTEGER (CONTEXT_AMD64 | 0x2L)
#परिभाषय CONTEXT_SEGMENTS (CONTEXT_AMD64 | 0x4L)
#परिभाषय CONTEXT_FLOATING_POINT (CONTEXT_AMD64 | 0x8L)
#परिभाषय CONTEXT_DEBUG_REGISTERS (CONTEXT_AMD64 | 0x10L)

#परिभाषय CONTEXT_पूर्णम् (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
#परिभाषय CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS)

#परिभाषय CONTEXT_EXCEPTION_सक्रिय 0x8000000
#परिभाषय CONTEXT_SERVICE_सक्रिय 0x10000000
#परिभाषय CONTEXT_EXCEPTION_REQUEST 0x40000000
#परिभाषय CONTEXT_EXCEPTION_REPORTING 0x80000000
#यदि_अन्तः

#परिभाषय INITIAL_MXCSR 0x1f80
#परिभाषय INITIAL_FPCSR 0x027f

  प्रकारनिर्देश संरचना DECLSPEC_ALIGN(16) _M128A {
    ULONGLONG नीचः_3;
    LONGLONG उच्चः_3;
  } M128A,*PM128A;

  प्रकारनिर्देश संरचना _XMM_SAVE_AREA32 {
    WORD ControlWord;
    WORD स्थितिः_Word;
    BYTE चिह्नकम्_Word;
    BYTE Reserved1;
    WORD ErrorOpcode;
    DWORD Error_विस्थापनम्;
    WORD ErrorSelector;
    WORD Reserved2;
    DWORD दत्त_विस्थापनम्_2;
    WORD दत्त_Selector;
    WORD Reserved3;
    DWORD MxCsr;
    DWORD Mx_Csr_आवरणम्;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
  } XMM_SAVE_AREA32,*PXMM_SAVE_AREA32;

#परिभाषय LEGACY_SAVE_AREA_दीर्घता परिमाण(XMM_SAVE_AREA32)

  प्रकारनिर्देश संरचना DECLSPEC_ALIGN(16) _CONTEXT {
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
    सङ्घ {
      XMM_SAVE_AREA32 FltSave;
      XMM_SAVE_AREA32 FloatSave;
      संरचना {
	M128A शीर्षकम्_2[2];
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
    M128A सदिशम्_पञ्जिकाकोशः[26];
    DWORD64 सदिशम्_Control;
    DWORD64 DebugControl;
    DWORD64 चरमः_Branch_गन्तव्यम्_Rip;
    DWORD64 चरमः_Branch_From_Rip;
    DWORD64 चरमः_Exception_गन्तव्यम्_Rip;
    DWORD64 चरमः_Exception_From_Rip;
  } CONTEXT,*PCONTEXT;

#परिभाषय RUNTIME_FUNCTION_परोक्षम् 0x1

  प्रकारनिर्देश संरचना _RUNTIME_FUNCTION {
    DWORD Begin_स्थानाङ्कः;
    DWORD अन्तः_स्थानाङ्कः;
    DWORD Unwind_दत्त;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  प्रकारनिर्देश PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  प्रकारनिर्देश DWORD (*POUT_सम्बन्धि_PROCESS_FUNCTION_सारणी_CALLBACK)(HANDLE Process,PVOID सारणी_स्थानाङ्कः,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#परिभाषय बहिर्गमनम्_सम्बन्धि_PROCESS_FUNCTION_सारणी_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"
#यदि_अन्तः /* defined(__x86_64) && !defined(RC_INVOKED) */

#यदि defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED)

#परिभाषय __TCC_WINNT_ATOMIC_SEQ_CST 5
/* TCC lowers __atomic_compare_exchange's fourth argument as weak, but the
   ARM64 helper reads it as success_memorder.  Strong CAS passes weak == 0,
   so keep Interlocked's barriers explicit here. */
#परिभाषय __TCC_WINNT_MEMORY_BARRIER() __asm__ __volatile__("dmb ish" : : : "memory")

/* This covers the LONG operations needed by TCC's semaphore code and the
   pointer helpers that winbase.h exposes through Interlocked pointer macros.
   Add local helpers before relying on increment/decrement, add/exchange-add,
   bitwise, or 64-bit Interlocked forms on Windows ARM64 with TCC. */

    __CRT_INLINE LONG InterlockedExchange(LONG चञ्चल *Target,LONG मानम्_3) {
      LONG Old;
      __atomic_load(Target,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      यावत् (!__atomic_compare_exchange(Target,&Old,&मानम्_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      प्रत्यागम Old;
    }
    __CRT_INLINE LONG InterlockedCompareExchange(LONG चञ्चल *Destination,LONG ExChange,LONG Comperand) {
      LONG Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      प्रत्यागम Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedExchangePointer(PVOID चञ्चल *Target,PVOID मानम्_3) {
      PVOID Old;
      __atomic_load(Target,&Old,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      यावत् (!__atomic_compare_exchange(Target,&Old,&मानम्_3,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST))
	;
      __TCC_WINNT_MEMORY_BARRIER();
      प्रत्यागम Old;
    }
    __CRT_INLINE PVOID __TCC_WINNT_InterlockedCompareExchangePointer(PVOID चञ्चल *Destination,PVOID ExChange,PVOID Comperand) {
      PVOID Old = Comperand;
      __TCC_WINNT_MEMORY_BARRIER();
      __atomic_compare_exchange(Destination,&Old,&ExChange,0,
	__TCC_WINNT_ATOMIC_SEQ_CST,__TCC_WINNT_ATOMIC_SEQ_CST);
      __TCC_WINNT_MEMORY_BARRIER();
      प्रत्यागम Old;
    }

#परिभाषय InterlockedExchangePointer __TCC_WINNT_InterlockedExchangePointer
#परिभाषय InterlockedCompareExchangePointer __TCC_WINNT_InterlockedCompareExchangePointer
#परिभाषय InterlockedCompareExchangePointerAcquire InterlockedCompareExchangePointer
#परिभाषय InterlockedCompareExchangePointerRelease InterlockedCompareExchangePointer

#परिभाषय InterlockedCompareExchangeAcquire InterlockedCompareExchange
#परिभाषय InterlockedCompareExchangeRelease InterlockedCompareExchange

#अपरिभाषय __TCC_WINNT_MEMORY_BARRIER
#अपरिभाषय __TCC_WINNT_ATOMIC_SEQ_CST

#यदि_अन्तः /* defined(__TINYC__) && (defined(__aarch64__) || defined(__arm64__)) && !defined(RC_INVOKED) */

#यदि defined(_ARM64_)

/* ARM64 Context Definition */
#परिभाषय CONTEXT_ARM64 0x00400000
#परिभाषय CONTEXT_CONTROL (CONTEXT_ARM64 | 0x00000001L)
#परिभाषय CONTEXT_INTEGER (CONTEXT_ARM64 | 0x00000002L)
#परिभाषय CONTEXT_FLOATING_POINT (CONTEXT_ARM64 | 0x00000004L)
#परिभाषय CONTEXT_DEBUG (CONTEXT_ARM64 | 0x00000008L)
#परिभाषय CONTEXT_पूर्णम् (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT)
#परिभाषय CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG)
#परिभाषय ARM64_MAX_BREAKPOINTS 8
#परिभाषय ARM64_MAX_WATCHPOINTS 2

  प्रकारनिर्देश सङ्घ _ARM64_NT_NEON128 {
    संरचना {
      ULONGLONG नीचः_3;
      LONGLONG उच्चः_3;
    } DUMMYSTRUCTNAME;
    द्विगुण D[2];
    भिन्न S[4];
    WORD H[8];
    BYTE B[16];
  } ARM64_NT_NEON128,*PARM64_NT_NEON128;

  प्रकारनिर्देश संरचना DECLSPEC_ALIGN(16) _ARM64_NT_CONTEXT {
    ULONG ContextFlags;
    ULONG Cpsr;
    सङ्घ {
      संरचना {
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

  C_ASSERT(परिमाण(ARM64_NT_CONTEXT) == 0x390);

  प्रकारनिर्देश ARM64_NT_CONTEXT CONTEXT,*PCONTEXT;

  प्रकारनिर्देश संरचना _RUNTIME_FUNCTION {
    DWORD Begin_स्थानाङ्कः;
    DWORD Unwind_दत्त;
  } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

  प्रकारनिर्देश PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
  प्रकारनिर्देश DWORD (*POUT_सम्बन्धि_PROCESS_FUNCTION_सारणी_CALLBACK)(HANDLE Process,PVOID सारणी_स्थानाङ्कः,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#यदि_अन्तः /* _ARM64_ */

#यदि (defined _ARM64_ || defined _AMD64_) && !defined RC_INVOKED
  NTSYSAPI VOID __cdecl RtlRestoreContext (PCONTEXT Context_लेखः,संरचना EXCEPTION_लेखः *Exception_लेखः);
  NTSYSAPI BOOLEAN __cdecl Rtl_सङ्कलय_Function_सारणी(PRUNTIME_FUNCTION Function_सारणी,DWORD प्रविष्टिः_गणनम्,DWORD64 आधारः_स्थानाङ्कः);
  NTSYSAPI BOOLEAN __cdecl Rtl_Install_Function_सारणी_Callback(DWORD64 सारणी_Identifier,DWORD64 आधारः_स्थानाङ्कः,DWORD दीर्घता_2,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR बहिर्गमनम्_सम्बन्धि_Process_Callback_Dll);
  NTSYSAPI BOOLEAN __cdecl Rtl_Delete_Function_सारणी(PRUNTIME_FUNCTION Function_सारणी);
#यदि_अन्तः

#यदि_परिभाषितम् I_X86_
#यदि(defined(_X86_) && !defined(__x86_64)) && !defined(RC_INVOKED)
#यदि_परिभाषितम् __cplusplus
  बाह्य "C" {
#यदि_अन्तः

    __CRT_INLINE BOOLEAN Interlocked_Bit_Test_And_समुच्चयः(LONG *आधारः_2,LONG Bit) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (Bit));
      प्रत्यागम (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN InterlockedBitTestAndReset(LONG *आधारः_2,LONG Bit) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (Bit));
      प्रत्यागम (BOOLEAN) (old!=0);
    }

    __CRT_INLINE BOOLEAN InterlockedBitTestAndComplement(LONG *आधारः_2,LONG Bit) {
      पूर्णाङ्क old = 0;
      __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
	:"=r" (old),"=m" ((*(चञ्चल दीर्घ *) आधारः_2))
	:"Ir" (Bit));
      प्रत्यागम (BOOLEAN) (old!=0);
    }

#यदि_परिभाषितम् उपसर्गः_2
    BYTE __readfsbyte(DWORD विस्थापनम्_3);
    WORD __readfsword(DWORD विस्थापनम्_3);
    DWORD __readfsdword(DWORD विस्थापनम्_3);
    VOID __writefsbyte(DWORD विस्थापनम्_3,BYTE दत्त_3);
    VOID __writefsword(DWORD विस्थापनम्_3,WORD दत्त_3);
    VOID __writefsdword(DWORD विस्थापनम्_3,DWORD दत्त_3);
#यदि_अन्तः

#यदि_परिभाषितम् __cplusplus
  }
#यदि_अन्तः
#यदि_अन्तः

#यदि(defined(_X86_) && !defined(__x86_64))
  __CRT_INLINE VOID स्मृतिः_Barrier(VOID) {
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
  }
#परिभाषय YieldProcessor() __asm__ __volatile__("rep nop ");

#परिभाषय Pre_Fetch_Cache_पङ्क्तिः(l,a)
#परिभाषय ReadForWriteAccess(p) (*(p))

#परिभाषय PF_TEMPORAL_LEVEL_1
#परिभाषय PF_NON_TEMPORAL_LEVEL_ALL

  __CRT_INLINE VOID DbgRaiseAssertionFailure(शून्य) {
    __asm__ __volatile__("int $0x2c ");
  }
  PVOID GetCurrentFiber(शून्य);
  __CRT_INLINE PVOID GetCurrentFiber(शून्य)
  {
    शून्य *ret;
    __asm__ चञ्चल ("movl	%%fs:0x10,%0"
	: "=r" (ret));
    प्रत्यागम ret;
  }
  PVOID Get_Fiber_दत्त(शून्य);
  __CRT_INLINE PVOID Get_Fiber_दत्त(शून्य)
  {
    शून्य *ret;
    __asm__ चञ्चल ("movl	%%fs:0x10,%0\n"
	"movl	(%0),%0"
	: "=r" (ret));
    प्रत्यागम ret;
  }
#यदि_अन्तः

#परिभाषय EXCEPTION_READ_FAULT 0
#परिभाषय EXCEPTION_WRITE_FAULT 1
#परिभाषय EXCEPTION_EXECUTE_FAULT 8

#परिभाषय आकार_सम्बन्धि_80387_REGISTERS 80

#यदि !defined(RC_INVOKED)

#परिभाषय CONTEXT_i386 0x00010000
#परिभाषय CONTEXT_i486 0x00010000

#परिभाषय CONTEXT_CONTROL (CONTEXT_i386 | 0x00000001L)
#परिभाषय CONTEXT_INTEGER (CONTEXT_i386 | 0x00000002L)
#परिभाषय CONTEXT_SEGMENTS (CONTEXT_i386 | 0x00000004L)
#परिभाषय CONTEXT_FLOATING_POINT (CONTEXT_i386 | 0x00000008L)
#परिभाषय CONTEXT_DEBUG_REGISTERS (CONTEXT_i386 | 0x00000010L)
#परिभाषय CONTEXT_EXTENDED_REGISTERS (CONTEXT_i386 | 0x00000020L)

#परिभाषय CONTEXT_पूर्णम् (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS)

#परिभाषय CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_INTEGER | CONTEXT_SEGMENTS | CONTEXT_FLOATING_POINT | CONTEXT_DEBUG_REGISTERS | CONTEXT_EXTENDED_REGISTERS)
#यदि_अन्तः

#परिभाषय अधिकतमम्_SUPPORTED_EXTENSION 512

    प्रकारनिर्देश संरचना _FLOATING_SAVE_AREA {
      DWORD ControlWord;
      DWORD स्थितिः_Word;
      DWORD चिह्नकम्_Word;
      DWORD Error_विस्थापनम्;
      DWORD ErrorSelector;
      DWORD दत्त_विस्थापनम्_2;
      DWORD दत्त_Selector;
      BYTE पञ्जिकाकोशः_Area[आकार_सम्बन्धि_80387_REGISTERS];
      DWORD Cr0NpxState;
    } FLOATING_SAVE_AREA;

    प्रकारनिर्देश FLOATING_SAVE_AREA *PFLOATING_SAVE_AREA;

    प्रकारनिर्देश संरचना _CONTEXT {
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
      BYTE ExtendedRegisters[अधिकतमम्_SUPPORTED_EXTENSION];
    } CONTEXT;

    प्रकारनिर्देश CONTEXT *PCONTEXT;
#यदि_अन्तः

#यदि_अपरिभाषितम् LDT_प्रविष्टिः_DEFINED
#परिभाषय LDT_प्रविष्टिः_DEFINED

    प्रकारनिर्देश संरचना LDT_प्रविष्टिः {
      WORD सीमा_नीचः;
      WORD आधारः_नीचः;
      सङ्घ {
	संरचना {
	  BYTE आधारः_Mid;
	  BYTE Flags1;
	  BYTE Flags2;
	  BYTE आधारः_Hi;
	} अष्टकानि_2;
	संरचना {
	  DWORD आधारः_Mid : 8;
	  DWORD Type : 5;
	  DWORD Dpl : 2;
	  DWORD Pres : 1;
	  DWORD सीमा_Hi : 4;
	  DWORD Sys : 1;
	  DWORD Reserved_0 : 1;
	  DWORD Default_Big : 1;
	  DWORD Granularity : 1;
	  DWORD आधारः_Hi : 8;
	} द्वयङ्काः_2;
      } उच्चः_Word;
    } LDT_प्रविष्टिः_2,*PLDT_प्रविष्टिः;
#यदि_अन्तः

#यदि defined(__ia64__) && !defined(RC_INVOKED)

#यदि_परिभाषितम् __cplusplus
    बाह्य "C" {
#यदि_अन्तः

      BOOLEAN Bit_अवलोकनम्_Forward64(DWORD *सूचकांक_3,DWORD64 आवरणम्_3);
      BOOLEAN Bit_अवलोकनम्_Reverse64(DWORD *सूचकांक_3,DWORD64 आवरणम्_3);

#यदि_परिभाषितम् __cplusplus
    }
#यदि_अन्तः
#यदि_अन्तः

#यदि !defined(GENUTIL) && !defined(_GENIA64_) && defined(_IA64_)

    शून्य *_cdecl _rdteb(शून्य);
#यदि_परिभाषितम् __ia64__

#परिभाषय NtCurrentTeb() ((संरचना _TEB *)_rdteb())
#परिभाषय GetCurrentFiber() (((PNT_TIB)NtCurrentTeb())->Fiber_दत्त)
#परिभाषय Get_Fiber_दत्त() (*(PVOID *)(GetCurrentFiber()))

#यदि_परिभाषितम् __cplusplus
    बाह्य "C" {
#यदि_अन्तः

      शून्य __break(पूर्णाङ्क);
      शून्य __yield(शून्य);
      शून्य __mf(शून्य);
      शून्य __lfetch(पूर्णाङ्क Level,VOID CONST *स्थानाङ्कः_2);
      शून्य __lfetchfault(पूर्णाङ्क Level,VOID CONST *स्थानाङ्कः_2);
      शून्य __lfetch_excl(पूर्णाङ्क Level,VOID CONST *स्थानाङ्कः_2);
      शून्य __lfetchfault_excl(पूर्णाङ्क Level,VOID CONST *स्थानाङ्कः_2);

#परिभाषय MD_LFHINT_NONE 0x00
#परिभाषय MD_LFHINT_NT1 0x01
#परिभाषय MD_LFHINT_NT2 0x02
#परिभाषय MD_LFHINT_NTA 0x03

#यदि_परिभाषितम् __cplusplus
    }
#यदि_अन्तः

#परिभाषय YieldProcessor __yield
#परिभाषय स्मृतिः_Barrier __mf
#परिभाषय Pre_Fetch_Cache_पङ्क्तिः __lfetch
#परिभाषय ReadForWriteAccess(p) (*(p))
#परिभाषय DbgRaiseAssertionFailure() __break(ASSERT_BREAKPOINT)

#परिभाषय PF_TEMPORAL_LEVEL_1 MD_LFHINT_NONE
#परिभाषय PF_NON_TEMPORAL_LEVEL_ALL MD_LFHINT_NTA

#परिभाषय Unsigned_Multiply_उच्चः __UMULH

    ULONGLONG Unsigned_Multiply_उच्चः(ULONGLONG Multiplier,ULONGLONG Multiplicand);
#अन्यथा
    संरचना _TEB *NtCurrentTeb(शून्य);
#यदि_अन्तः
#यदि_अन्तः

#यदि_परिभाषितम् _IA64_

#परिभाषय EXCEPTION_READ_FAULT 0
#परिभाषय EXCEPTION_WRITE_FAULT 1
#परिभाषय EXCEPTION_EXECUTE_FAULT 2

#यदि !defined(RC_INVOKED)

#परिभाषय CONTEXT_IA64 0x00080000

#परिभाषय CONTEXT_CONTROL (CONTEXT_IA64 | 0x00000001L)
#परिभाषय CONTEXT_अधस्तनम्_FLOATING_POINT (CONTEXT_IA64 | 0x00000002L)
#परिभाषय CONTEXT_HIGHER_FLOATING_POINT (CONTEXT_IA64 | 0x00000004L)
#परिभाषय CONTEXT_INTEGER (CONTEXT_IA64 | 0x00000008L)
#परिभाषय CONTEXT_DEBUG (CONTEXT_IA64 | 0x00000010L)
#परिभाषय CONTEXT_IA32_CONTROL (CONTEXT_IA64 | 0x00000020L)

#परिभाषय CONTEXT_FLOATING_POINT (CONTEXT_अधस्तनम्_FLOATING_POINT | CONTEXT_HIGHER_FLOATING_POINT)
#परिभाषय CONTEXT_पूर्णम् (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_IA32_CONTROL)
#परिभाषय CONTEXT_ALL (CONTEXT_CONTROL | CONTEXT_FLOATING_POINT | CONTEXT_INTEGER | CONTEXT_DEBUG | CONTEXT_IA32_CONTROL)

#परिभाषय CONTEXT_EXCEPTION_सक्रिय 0x8000000
#परिभाषय CONTEXT_SERVICE_सक्रिय 0x10000000
#परिभाषय CONTEXT_EXCEPTION_REQUEST 0x40000000
#परिभाषय CONTEXT_EXCEPTION_REPORTING 0x80000000
#यदि_अन्तः

    प्रकारनिर्देश संरचना _CONTEXT {
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

    प्रकारनिर्देश संरचना _PLABEL_DESCRIPTOR {
      ULONGLONG प्रविष्टिः_Point;
      ULONGLONG GlobalPointer;
    } PLABEL_DESCRIPTOR,*PPLABEL_DESCRIPTOR;

    प्रकारनिर्देश संरचना _RUNTIME_FUNCTION {
      DWORD Begin_स्थानाङ्कः;
      DWORD अन्तः_स्थानाङ्कः;
      DWORD Unwind_Info_स्थानाङ्कः;
    } RUNTIME_FUNCTION,*PRUNTIME_FUNCTION;

    प्रकारनिर्देश PRUNTIME_FUNCTION (*PGET_RUNTIME_FUNCTION_CALLBACK)(DWORD64 ControlPc,PVOID Context);
    प्रकारनिर्देश DWORD (*POUT_सम्बन्धि_PROCESS_FUNCTION_सारणी_CALLBACK)(HANDLE Process,PVOID सारणी_स्थानाङ्कः,PDWORD Entries,PRUNTIME_FUNCTION *Functions);

#परिभाषय बहिर्गमनम्_सम्बन्धि_PROCESS_FUNCTION_सारणी_CALLBACK_EXPORT_NAME "OutOfProcessFunctionTableCallback"

    BOOLEAN Rtl_सङ्कलय_Function_सारणी(PRUNTIME_FUNCTION Function_सारणी,DWORD प्रविष्टिः_गणनम्,ULONGLONG आधारः_स्थानाङ्कः,ULONGLONG TargetGp);
    BOOLEAN Rtl_Install_Function_सारणी_Callback(DWORD64 सारणी_Identifier,DWORD64 आधारः_स्थानाङ्कः,DWORD दीर्घता_2,DWORD64 TargetGp,PGET_RUNTIME_FUNCTION_CALLBACK Callback,PVOID Context,PCWSTR बहिर्गमनम्_सम्बन्धि_Process_Callback_Dll);
    BOOLEAN Rtl_Delete_Function_सारणी(PRUNTIME_FUNCTION Function_सारणी);
    VOID RtlRestoreContext (PCONTEXT Context_लेखः,संरचना EXCEPTION_लेखः *Exception_लेखः);
    VOID __jump_unwind(ULONGLONG TargetMsFrame,ULONGLONG TargetBsFrame,ULONGLONG TargetPc);
#यदि_अन्तः

#परिभाषय EXCEPTION_NONCONTINUABLE 0x1
#परिभाषय EXCEPTION_अधिकतमम्_PARAMETERS 15

    प्रकारनिर्देश संरचना EXCEPTION_लेखः {
      DWORD Exception_संहिता;
      DWORD ExceptionFlags;
      संरचना EXCEPTION_लेखः *Exception_लेखः;
      PVOID Exception_स्थानाङ्कः;
      DWORD सङ्ख्या_Parameters;
      ULONG_PTR ExceptionInformation[EXCEPTION_अधिकतमम्_PARAMETERS];
    } EXCEPTION_लेखः_2;

    प्रकारनिर्देश EXCEPTION_लेखः_2 *PEXCEPTION_लेखः;

    प्रकारनिर्देश संरचना _EXCEPTION_RECORD32 {
      DWORD Exception_संहिता;
      DWORD ExceptionFlags;
      DWORD Exception_लेखः;
      DWORD Exception_स्थानाङ्कः;
      DWORD सङ्ख्या_Parameters;
      DWORD ExceptionInformation[EXCEPTION_अधिकतमम्_PARAMETERS];
    } EXCEPTION_RECORD32,*PEXCEPTION_RECORD32;

    प्रकारनिर्देश संरचना _EXCEPTION_RECORD64 {
      DWORD Exception_संहिता;
      DWORD ExceptionFlags;
      DWORD64 Exception_लेखः;
      DWORD64 Exception_स्थानाङ्कः;
      DWORD सङ्ख्या_Parameters;
      DWORD __unusedAlignment;
      DWORD64 ExceptionInformation[EXCEPTION_अधिकतमम्_PARAMETERS];
    } EXCEPTION_RECORD64,*PEXCEPTION_RECORD64;

    प्रकारनिर्देश संरचना EXCEPTION_सूचकाः_2 {
      PEXCEPTION_लेखः Exception_लेखः;
      PCONTEXT Context_लेखः;
    } EXCEPTION_सूचकाः,*PEXCEPTION_सूचकाः;

#यदि_परिभाषितम् __x86_64

    प्रकारनिर्देश EXCEPTION_DISPOSITION NTAPI EXCEPTION_ROUTINE (संरचना EXCEPTION_लेखः *Exception_लेखः, PVOID EstablisherFrame, संरचना _CONTEXT *Context_लेखः, PVOID DispatcherContext);
#यदि_अपरिभाषितम् __PEXCEPTION_ROUTINE_DEFINED
#परिभाषय __PEXCEPTION_ROUTINE_DEFINED
    प्रकारनिर्देश EXCEPTION_ROUTINE *PEXCEPTION_ROUTINE;
#यदि_अन्तः

    /* http://msdn.microsoft.com/en-us/library/ms680597(VS.85).aspx */

#परिभाषय UNWIND_HISTORY_सारणी_आकार 12

  प्रकारनिर्देश संरचना UNWIND_HISTORY_सारणी_प्रविष्टिः {
    ULONG64 Image_आधारः;
    PRUNTIME_FUNCTION Function_प्रविष्टिः;
  } UNWIND_HISTORY_सारणी_प्रविष्टिः_2, *PUNWIND_HISTORY_सारणी_प्रविष्टिः;

#परिभाषय UNWIND_HISTORY_सारणी_NONE    0
#परिभाषय UNWIND_HISTORY_सारणी_GLOBAL  1
#परिभाषय UNWIND_HISTORY_सारणी_LOCAL   2

  प्रकारनिर्देश संरचना UNWIND_HISTORY_सारणी {
    ULONG गणनम्_3;
    UCHAR अन्वेषणम्;
    ULONG64 नीचः_स्थानाङ्कः;
    ULONG64 उच्चः_स्थानाङ्कः;
    UNWIND_HISTORY_सारणी_प्रविष्टिः_2 प्रविष्टिः[UNWIND_HISTORY_सारणी_आकार];
  } UNWIND_HISTORY_सारणी_2, *PUNWIND_HISTORY_सारणी;

  /* http://msdn.microsoft.com/en-us/library/b6sf5kbd(VS.80).aspx */

  संरचना _DISPATCHER_CONTEXT;
  प्रकारनिर्देश संरचना _DISPATCHER_CONTEXT DISPATCHER_CONTEXT;
  प्रकारनिर्देश संरचना _DISPATCHER_CONTEXT *PDISPATCHER_CONTEXT;

  संरचना _DISPATCHER_CONTEXT {
    ULONG64 ControlPc;
    ULONG64 Image_आधारः;
    PRUNTIME_FUNCTION Function_प्रविष्टिः;
    ULONG64 EstablisherFrame;
    ULONG64 TargetIp;
    PCONTEXT Context_लेखः;
    PEXCEPTION_ROUTINE LanguageHandler;
    PVOID Handler_दत्त;
    /* http://www.nynaeve.net/?p=99 */
    PUNWIND_HISTORY_सारणी History_सारणी;
    ULONG Scope_सूचकांक;
    ULONG Fill0;
  };

  /* http://msdn.microsoft.com/en-us/library/ms680617(VS.85).aspx */

  प्रकारनिर्देश संरचना KNONVOLATILE_CONTEXT_सूचकाः
  {
    PM128A FloatingContext[16];
    PULONG64 IntegerContext[16];
  } KNONVOLATILE_CONTEXT_सूचकाः_2, *PKNONVOLATILE_CONTEXT_सूचकाः;
#यदि_अन्तः /* defined(__x86_64) */

    प्रकारनिर्देश PVOID PACCESS_TOKEN;
    प्रकारनिर्देश PVOID PSECURITY_DESCRIPTOR;
    प्रकारनिर्देश PVOID PSID;

    प्रकारनिर्देश DWORD ACCESS_आवरणम्;
    प्रकारनिर्देश ACCESS_आवरणम् *PACCESS_आवरणम्;

#परिभाषय DELETE (0x00010000L)
#परिभाषय READ_CONTROL (0x00020000L)
#परिभाषय WRITE_DAC (0x00040000L)
#परिभाषय WRITE_OWNER (0x00080000L)
#परिभाषय SYNCHRONIZE (0x00100000L)

#परिभाषय STANDARD_RIGHTS_REQUIRED (0x000F0000L)
#परिभाषय STANDARD_RIGHTS_READ (READ_CONTROL)
#परिभाषय STANDARD_RIGHTS_WRITE (READ_CONTROL)
#परिभाषय STANDARD_RIGHTS_EXECUTE (READ_CONTROL)
#परिभाषय STANDARD_RIGHTS_ALL (0x001F0000L)

#परिभाषय SPECIFIC_RIGHTS_ALL (0x0000FFFFL)

#परिभाषय ACCESS_SYSTEM_SECURITY (0x01000000L)

#परिभाषय अधिकतमम्_ALLOWED (0x02000000L)

#परिभाषय GENERIC_READ (0x80000000L)
#परिभाषय GENERIC_WRITE (0x40000000L)
#परिभाषय GENERIC_EXECUTE (0x20000000L)
#परिभाषय GENERIC_ALL (0x10000000L)

    प्रकारनिर्देश संरचना _GENERIC_MAPPING {
      ACCESS_आवरणम् GenericRead;
      ACCESS_आवरणम् GenericWrite;
      ACCESS_आवरणम् GenericExecute;
      ACCESS_आवरणम् GenericAll;
    } GENERIC_MAPPING;
    प्रकारनिर्देश GENERIC_MAPPING *PGENERIC_MAPPING;

#अन्तर्भाव <pshpack4.h>

    प्रकारनिर्देश संरचना LUID_AND_गुणाः {
      LUID Luid;
      DWORD गुणाः;
    } LUID_AND_गुणाः_2,*PLUID_AND_गुणाः;
    प्रकारनिर्देश LUID_AND_गुणाः_2 LUID_AND_गुणाः_ARRAY[ANYSIZE_ARRAY];
    प्रकारनिर्देश LUID_AND_गुणाः_ARRAY *PLUID_AND_गुणाः_ARRAY;

#अन्तर्भाव <poppack.h>

#यदि_अपरिभाषितम् SID_IDENTIFIER_AUTHORITY_DEFINED
#परिभाषय SID_IDENTIFIER_AUTHORITY_DEFINED
    प्रकारनिर्देश संरचना _SID_IDENTIFIER_AUTHORITY {
      BYTE मानम्_3[6];
    } SID_IDENTIFIER_AUTHORITY,*PSID_IDENTIFIER_AUTHORITY;
#यदि_अन्तः

#यदि_अपरिभाषितम् SID_DEFINED
#परिभाषय SID_DEFINED
    प्रकारनिर्देश संरचना _SID {
      BYTE Revision;
      BYTE Sub_Authority_गणनम्;
      SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
      DWORD SubAuthority[ANYSIZE_ARRAY];
    } SID,*PISID;
#यदि_अन्तः

#परिभाषय SID_REVISION (1)
#परिभाषय SID_MAX_SUB_AUTHORITIES (15)
#परिभाषय SID_RECOMMENDED_SUB_AUTHORITIES (1)

#परिभाषय SECURITY_MAX_SID_आकार (परिमाण(SID) - परिमाण(DWORD) + (SID_MAX_SUB_AUTHORITIES *परिमाण(DWORD)))

    प्रकारनिर्देश गणना _SID_NAME_USE {
      SidTypeUser = 1,Sid_Type_गणः,SidTypeDomain,SidTypeAlias,Sid_Type_Well_ज्ञातम्_गणः,SidTypeDeletedAccount,SidTypeInvalid,SidTypeUnknown,SidTypeComputer
    } SID_NAME_USE,*PSID_NAME_USE;

    प्रकारनिर्देश संरचना SID_AND_गुणाः {
      PSID Sid;
      DWORD गुणाः;
    } SID_AND_गुणाः_2,*PSID_AND_गुणाः;

    प्रकारनिर्देश SID_AND_गुणाः_2 SID_AND_गुणाः_ARRAY[ANYSIZE_ARRAY];
    प्रकारनिर्देश SID_AND_गुणाः_ARRAY *PSID_AND_गुणाः_ARRAY;

#परिभाषय SECURITY_NULL_SID_AUTHORITY {0,0,0,0,0,0}
#परिभाषय SECURITY_WORLD_SID_AUTHORITY {0,0,0,0,0,1}
#परिभाषय SECURITY_LOCAL_SID_AUTHORITY {0,0,0,0,0,2}
#परिभाषय SECURITY_CREATOR_SID_AUTHORITY {0,0,0,0,0,3}
#परिभाषय SECURITY_NON_UNIQUE_AUTHORITY {0,0,0,0,0,4}
#परिभाषय SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

#परिभाषय SECURITY_NULL_RID (0x00000000L)
#परिभाषय SECURITY_WORLD_RID (0x00000000L)
#परिभाषय SECURITY_LOCAL_RID (0x00000000L)

#परिभाषय SECURITY_CREATOR_OWNER_RID (0x00000000L)
#परिभाषय SECURITY_CREATOR_गणः_RID (0x00000001L)

#परिभाषय SECURITY_CREATOR_OWNER_SERVER_RID (0x00000002L)
#परिभाषय SECURITY_CREATOR_गणः_SERVER_RID (0x00000003L)

#परिभाषय SECURITY_NT_AUTHORITY {0,0,0,0,0,5}

#परिभाषय SECURITY_DIALUP_RID (0x00000001L)
#परिभाषय SECURITY_जालम्_RID (0x00000002L)
#परिभाषय SECURITY_BATCH_RID (0x00000003L)
#परिभाषय SECURITY_INTERACTIVE_RID (0x00000004L)
#परिभाषय SECURITY_LOGON_IDS_RID (0x00000005L)
#परिभाषय SECURITY_LOGON_IDS_RID_गणनम् (3L)
#परिभाषय SECURITY_SERVICE_RID (0x00000006L)
#परिभाषय SECURITY_ANONYMOUS_LOGON_RID (0x00000007L)
#परिभाषय SECURITY_PROXY_RID (0x00000008L)
#परिभाषय SECURITY_ENTERPRISE_CONTROLLERS_RID (0x00000009L)
#परिभाषय SECURITY_SERVER_LOGON_RID SECURITY_ENTERPRISE_CONTROLLERS_RID
#परिभाषय SECURITY_PRINCIPAL_SELF_RID (0x0000000AL)
#परिभाषय SECURITY_AUTHENTICATED_USER_RID (0x0000000BL)
#परिभाषय SECURITY_RESTRICTED_संहिता_RID (0x0000000CL)
#परिभाषय SECURITY_TERMINAL_SERVER_RID (0x0000000DL)
#परिभाषय SECURITY_REMOTE_LOGON_RID (0x0000000EL)
#परिभाषय SECURITY_THIS_ORGANIZATION_RID (0x0000000FL)
#परिभाषय SECURITY_IUSER_RID (0x00000011L)

#परिभाषय SECURITY_LOCAL_SYSTEM_RID (0x00000012L)
#परिभाषय SECURITY_LOCAL_SERVICE_RID (0x00000013L)
#परिभाषय SECURITY_जालम्_SERVICE_RID (0x00000014L)

#परिभाषय SECURITY_NT_NON_UNIQUE (0x00000015L)
#परिभाषय SECURITY_NT_NON_UNIQUE_SUB_AUTH_गणनम् (3L)

#परिभाषय SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID (0x00000016L)

#परिभाषय SECURITY_BUILTIN_DOMAIN_RID (0x00000020L)
#परिभाषय SECURITY_WRITE_RESTRICTED_संहिता_RID (0x00000021L)

#परिभाषय SECURITY_PACKAGE_आधारः_RID (0x00000040L)
#परिभाषय SECURITY_PACKAGE_RID_गणनम् (2L)
#परिभाषय SECURITY_PACKAGE_NTLM_RID (0x0000000AL)
#परिभाषय SECURITY_PACKAGE_SCHANNEL_RID (0x0000000EL)
#परिभाषय SECURITY_PACKAGE_DIGEST_RID (0x00000015L)

#परिभाषय SECURITY_SERVICE_ID_आधारः_RID (0x00000050L)
#परिभाषय SECURITY_SERVICE_ID_RID_गणनम् (6L)

#परिभाषय SECURITY_RESERVED_ID_आधारः_RID (0x00000051L)

#परिभाषय SECURITY_MAX_ALWAYS_FILTERED (0x000003E7L)
#परिभाषय SECURITY_MIN_NEVER_FILTERED (0x000003E8L)

#परिभाषय SECURITY_OTHER_ORGANIZATION_RID (0x000003E8L)

#परिभाषय FOREST_USER_RID_MAX (0x000001F3L)

#परिभाषय DOMAIN_USER_RID_ADMIN (0x000001F4L)
#परिभाषय DOMAIN_USER_RID_GUEST (0x000001F5L)
#परिभाषय DOMAIN_USER_RID_KRBTGT (0x000001F6L)

#परिभाषय DOMAIN_USER_RID_MAX (0x000003E7L)

#परिभाषय DOMAIN_गणः_RID_ADMINS (0x00000200L)
#परिभाषय DOMAIN_गणः_RID_USERS (0x00000201L)
#परिभाषय DOMAIN_गणः_RID_GUESTS (0x00000202L)
#परिभाषय DOMAIN_गणः_RID_COMPUTERS (0x00000203L)
#परिभाषय DOMAIN_गणः_RID_CONTROLLERS (0x00000204L)
#परिभाषय DOMAIN_गणः_RID_CERT_ADMINS (0x00000205L)
#परिभाषय DOMAIN_गणः_RID_SCHEMA_ADMINS (0x00000206L)
#परिभाषय DOMAIN_गणः_RID_ENTERPRISE_ADMINS (0x00000207L)
#परिभाषय DOMAIN_गणः_RID_POLICY_ADMINS (0x00000208L)
#परिभाषय DOMAIN_गणः_RID_READONLY_CONTROLLERS (0x00000209L)

#परिभाषय DOMAIN_ALIAS_RID_ADMINS (0x00000220L)
#परिभाषय DOMAIN_ALIAS_RID_USERS (0x00000221L)
#परिभाषय DOMAIN_ALIAS_RID_GUESTS (0x00000222L)
#परिभाषय DOMAIN_ALIAS_RID_POWER_USERS (0x00000223L)

#परिभाषय DOMAIN_ALIAS_RID_ACCOUNT_OPS (0x00000224L)
#परिभाषय DOMAIN_ALIAS_RID_SYSTEM_OPS (0x00000225L)
#परिभाषय DOMAIN_ALIAS_RID_PRINT_OPS (0x00000226L)
#परिभाषय DOMAIN_ALIAS_RID_BACKUP_OPS (0x00000227L)

#परिभाषय DOMAIN_ALIAS_RID_REPLICATOR (0x00000228L)
#परिभाषय DOMAIN_ALIAS_RID_RAS_SERVERS (0x00000229L)
#परिभाषय DOMAIN_ALIAS_RID_PREW2KCOMPACCESS (0x0000022AL)
#परिभाषय DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS (0x0000022BL)
#परिभाषय DOMAIN_ALIAS_RID_जालम्_CONFIGURATION_OPS (0x0000022CL)
#परिभाषय DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS (0x0000022DL)

#परिभाषय DOMAIN_ALIAS_RID_MONITORING_USERS (0x0000022EL)
#परिभाषय DOMAIN_ALIAS_RID_LOGGING_USERS (0x0000022FL)
#परिभाषय DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS (0x00000230L)
#परिभाषय DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS (0x00000231L)
#परिभाषय DOMAIN_ALIAS_RID_DCOM_USERS (0x00000232L)

#परिभाषय DOMAIN_ALIAS_RID_IUSERS (0x00000238L)
#परिभाषय DOMAIN_ALIAS_RID_CRYPTO_OPERATORS (0x00000239L)
#परिभाषय DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_गणः (0x0000023BL)
#परिभाषय DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_गणः (0x0000023CL)
#परिभाषय DOMAIN_ALIAS_RID_EVENT_LOG_READERS_गणः (0x0000023DL)

#परिभाषय SECURITY_MANDATORY_LABEL_AUTHORITY {0,0,0,0,0,16}
#परिभाषय SECURITY_MANDATORY_UNTRUSTED_RID (0x00000000L)
#परिभाषय SECURITY_MANDATORY_नीचः_RID (0x00001000L)
#परिभाषय SECURITY_MANDATORY_MEDIUM_RID (0x00002000L)
#परिभाषय SECURITY_MANDATORY_उच्चः_RID (0x00003000L)
#परिभाषय SECURITY_MANDATORY_SYSTEM_RID (0x00004000L)
#परिभाषय SECURITY_MANDATORY_PROTECTED_PROCESS_RID (0x00005000L)

#परिभाषय SECURITY_MANDATORY_अधिकतमम्_USER_RID SECURITY_MANDATORY_SYSTEM_RID

#परिभाषय MANDATORY_LEVEL_गन्तव्यम्_MANDATORY_RID(IL) (IL * 0x1000)

    प्रकारनिर्देश गणना {
      WinNullSid = 0,WinWorldSid = 1,WinLocalSid = 2,WinCreatorOwnerSid = 3,Win_Creator_गणः_Sid = 4,WinCreatorOwnerServerSid = 5,Win_Creator_गणः_Server_Sid = 6,WinNtAuthoritySid = 7,WinDialupSid = 8,Win_जालम्_Sid = 9,WinBatchSid = 10,WinInteractiveSid = 11,WinServiceSid = 12,WinAnonymousSid = 13,WinProxySid = 14,WinEnterpriseControllersSid = 15,WinSelfSid = 16,WinAuthenticatedUserSid = 17,Win_Restricted_संहिता_Sid = 18,WinTerminalServerSid = 19,WinRemoteLogonIdSid = 20,WinLogonIdsSid = 21,WinLocalSystemSid = 22,WinLocalServiceSid = 23,Win_जालम्_Service_Sid = 24,WinBuiltinDomainSid = 25,WinBuiltinAdministratorsSid = 26,WinBuiltinUsersSid = 27,WinBuiltinGuestsSid = 28,WinBuiltinPowerUsersSid = 29,WinBuiltinAccountOperatorsSid = 30,WinBuiltinSystemOperatorsSid = 31,WinBuiltinPrintOperatorsSid = 32,WinBuiltinBackupOperatorsSid = 33,WinBuiltinReplicatorSid = 34,WinBuiltinPreWindows2000CompatibleAccessSid = 35,WinBuiltinRemoteDesktopUsersSid = 36,Win_Builtin_जालम्_Configuration_Operators_Sid = 37,WinAccountAdministratorSid = 38,WinAccountGuestSid = 39,WinAccountKrbtgtSid = 40,WinAccountDomainAdminsSid = 41,WinAccountDomainUsersSid = 42,WinAccountDomainGuestsSid = 43,WinAccountComputersSid = 44,WinAccountControllersSid = 45,WinAccountCertAdminsSid = 46,WinAccountSchemaAdminsSid = 47,WinAccountEnterpriseAdminsSid = 48,WinAccountPolicyAdminsSid = 49,WinAccountRasAndIasServersSid = 50,WinNTLMAuthenticationSid = 51,WinDigestAuthenticationSid = 52,WinSChannelAuthenticationSid = 53,WinThisOrganizationSid = 54,WinOtherOrganizationSid = 55,WinBuiltinIncomingForestTrustBuildersSid = 56,WinBuiltinPerfMonitoringUsersSid = 57,WinBuiltinPerfLoggingUsersSid = 58,WinBuiltinAuthorizationAccessSid = 59,WinBuiltinTerminalServerLicenseServersSid = 60,WinBuiltinDCOMUsersSid = 61
    } WELL_ज्ञातम्_SID_TYPE;

#परिभाषय SYSTEM_LUID { 0x3E7,0x0 }
#परिभाषय ANONYMOUS_LOGON_LUID { 0x3e6,0x0 }
#परिभाषय LOCALSERVICE_LUID { 0x3e5,0x0 }
#परिभाषय NETWORKSERVICE_LUID { 0x3e4,0x0 }
#परिभाषय IUSER_LUID { 0x3e3, 0x0 }

#परिभाषय SE_गणः_MANDATORY (0x00000001L)
#परिभाषय SE_गणः_ENABLED_BY_DEFAULT (0x00000002L)
#परिभाषय SE_गणः_ENABLED (0x00000004L)
#परिभाषय SE_गणः_OWNER (0x00000008L)
#परिभाषय SE_गणः_USE_FOR_DENY_ONLY (0x00000010L)
#परिभाषय SE_गणः_INTEGRITY (0x00000020L)
#परिभाषय SE_गणः_INTEGRITY_ENABLED (0x00000040L)
#परिभाषय SE_गणः_LOGON_ID (0xC0000000L)
#परिभाषय SE_गणः_RESOURCE (0x20000000L)

#परिभाषय ACL_REVISION (2)
#परिभाषय ACL_REVISION_DS (4)

#परिभाषय ACL_REVISION1 (1)
#परिभाषय MIN_ACL_REVISION ACL_REVISION2
#परिभाषय ACL_REVISION2 (2)
#परिभाषय ACL_REVISION3 (3)
#परिभाषय ACL_REVISION4 (4)
#परिभाषय MAX_ACL_REVISION ACL_REVISION4

    प्रकारनिर्देश संरचना _ACL {
      BYTE AclRevision;
      BYTE Sbz1;
      WORD Acl_आकार;
      WORD Ace_गणनम्;
      WORD Sbz2;
    } ACL;
    प्रकारनिर्देश ACL *PACL;

    प्रकारनिर्देश संरचना ACE_शीर्षकम् {
      BYTE AceType;
      BYTE AceFlags;
      WORD Ace_आकार;
    } ACE_शीर्षकम्_2;
    प्रकारनिर्देश ACE_शीर्षकम्_2 *PACE_शीर्षकम्;

#परिभाषय ACCESS_MIN_MS_ACE_TYPE (0x0)
#परिभाषय ACCESS_ALLOWED_ACE_TYPE (0x0)
#परिभाषय ACCESS_DENIED_ACE_TYPE (0x1)
#परिभाषय SYSTEM_AUDIT_ACE_TYPE (0x2)
#परिभाषय SYSTEM_ALARM_ACE_TYPE (0x3)
#परिभाषय ACCESS_MAX_MS_V2_ACE_TYPE (0x3)

#परिभाषय ACCESS_ALLOWED_COMPOUND_ACE_TYPE (0x4)
#परिभाषय ACCESS_MAX_MS_V3_ACE_TYPE (0x4)

#परिभाषय ACCESS_MIN_MS_OBJECT_ACE_TYPE (0x5)
#परिभाषय ACCESS_ALLOWED_OBJECT_ACE_TYPE (0x5)
#परिभाषय ACCESS_DENIED_OBJECT_ACE_TYPE (0x6)
#परिभाषय SYSTEM_AUDIT_OBJECT_ACE_TYPE (0x7)
#परिभाषय SYSTEM_ALARM_OBJECT_ACE_TYPE (0x8)
#परिभाषय ACCESS_MAX_MS_OBJECT_ACE_TYPE (0x8)

#परिभाषय ACCESS_MAX_MS_V4_ACE_TYPE (0x8)
#परिभाषय ACCESS_MAX_MS_ACE_TYPE (0x8)

#परिभाषय ACCESS_ALLOWED_CALLBACK_ACE_TYPE (0x9)
#परिभाषय ACCESS_DENIED_CALLBACK_ACE_TYPE (0xA)
#परिभाषय ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE (0xB)
#परिभाषय ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE (0xC)
#परिभाषय SYSTEM_AUDIT_CALLBACK_ACE_TYPE (0xD)
#परिभाषय SYSTEM_ALARM_CALLBACK_ACE_TYPE (0xE)
#परिभाषय SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE (0xF)
#परिभाषय SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE (0x10)

#परिभाषय SYSTEM_MANDATORY_LABEL_ACE_TYPE (0x11)
#परिभाषय ACCESS_MAX_MS_V5_ACE_TYPE (0x11)

#परिभाषय OBJECT_INHERIT_ACE (0x1)
#परिभाषय CONTAINER_INHERIT_ACE (0x2)
#परिभाषय NO_PROPAGATE_INHERIT_ACE (0x4)
#परिभाषय INHERIT_ONLY_ACE (0x8)
#परिभाषय INHERITED_ACE (0x10)
#परिभाषय VALID_INHERIT_FLAGS (0x1F)

#परिभाषय SUCCESSFUL_ACCESS_ACE_FLAG (0x40)
#परिभाषय FAILED_ACCESS_ACE_FLAG (0x80)

    प्रकारनिर्देश संरचना _ACCESS_ALLOWED_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD SidStart;
    } ACCESS_ALLOWED_ACE;

    प्रकारनिर्देश ACCESS_ALLOWED_ACE *PACCESS_ALLOWED_ACE;

    प्रकारनिर्देश संरचना _ACCESS_DENIED_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD SidStart;
    } ACCESS_DENIED_ACE;
    प्रकारनिर्देश ACCESS_DENIED_ACE *PACCESS_DENIED_ACE;

    प्रकारनिर्देश संरचना _SYSTEM_AUDIT_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD SidStart;
    } SYSTEM_AUDIT_ACE;
    प्रकारनिर्देश SYSTEM_AUDIT_ACE *PSYSTEM_AUDIT_ACE;

    प्रकारनिर्देश संरचना _SYSTEM_ALARM_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD SidStart;
    } SYSTEM_ALARM_ACE;
    प्रकारनिर्देश SYSTEM_ALARM_ACE *PSYSTEM_ALARM_ACE;

    प्रकारनिर्देश संरचना _ACCESS_ALLOWED_OBJECT_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } ACCESS_ALLOWED_OBJECT_ACE,*PACCESS_ALLOWED_OBJECT_ACE;

    प्रकारनिर्देश संरचना _ACCESS_DENIED_OBJECT_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } ACCESS_DENIED_OBJECT_ACE,*PACCESS_DENIED_OBJECT_ACE;

    प्रकारनिर्देश संरचना _SYSTEM_AUDIT_OBJECT_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } SYSTEM_AUDIT_OBJECT_ACE,*PSYSTEM_AUDIT_OBJECT_ACE;

    प्रकारनिर्देश संरचना _SYSTEM_ALARM_OBJECT_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;
    } SYSTEM_ALARM_OBJECT_ACE,*PSYSTEM_ALARM_OBJECT_ACE;

    प्रकारनिर्देश संरचना _ACCESS_ALLOWED_CALLBACK_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD SidStart;

    } ACCESS_ALLOWED_CALLBACK_ACE,*PACCESS_ALLOWED_CALLBACK_ACE;

    प्रकारनिर्देश संरचना _ACCESS_DENIED_CALLBACK_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD SidStart;

    } ACCESS_DENIED_CALLBACK_ACE,*PACCESS_DENIED_CALLBACK_ACE;

    प्रकारनिर्देश संरचना _SYSTEM_AUDIT_CALLBACK_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD SidStart;

    } SYSTEM_AUDIT_CALLBACK_ACE,*PSYSTEM_AUDIT_CALLBACK_ACE;

    प्रकारनिर्देश संरचना _SYSTEM_ALARM_CALLBACK_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD SidStart;

    } SYSTEM_ALARM_CALLBACK_ACE,*PSYSTEM_ALARM_CALLBACK_ACE;

    प्रकारनिर्देश संरचना _ACCESS_ALLOWED_CALLBACK_OBJECT_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } ACCESS_ALLOWED_CALLBACK_OBJECT_ACE,*PACCESS_ALLOWED_CALLBACK_OBJECT_ACE;

    प्रकारनिर्देश संरचना _ACCESS_DENIED_CALLBACK_OBJECT_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } ACCESS_DENIED_CALLBACK_OBJECT_ACE,*PACCESS_DENIED_CALLBACK_OBJECT_ACE;

    प्रकारनिर्देश संरचना _SYSTEM_AUDIT_CALLBACK_OBJECT_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } SYSTEM_AUDIT_CALLBACK_OBJECT_ACE,*PSYSTEM_AUDIT_CALLBACK_OBJECT_ACE;

    प्रकारनिर्देश संरचना _SYSTEM_ALARM_CALLBACK_OBJECT_ACE {
      ACE_शीर्षकम्_2 शीर्षकम्_2;
      ACCESS_आवरणम् आवरणम्_3;
      DWORD Flags;
      GUID ObjectType;
      GUID InheritedObjectType;
      DWORD SidStart;

    } SYSTEM_ALARM_CALLBACK_OBJECT_ACE,*PSYSTEM_ALARM_CALLBACK_OBJECT_ACE;

#परिभाषय ACE_OBJECT_TYPE_PRESENT 0x1
#परिभाषय ACE_INHERITED_OBJECT_TYPE_PRESENT 0x2

    प्रकारनिर्देश गणना _ACL_INFORMATION_CLASS {
      AclRevisionInformation = 1,Acl_आकार_Information
    } ACL_INFORMATION_CLASS;

    प्रकारनिर्देश संरचना _ACL_REVISION_INFORMATION {
      DWORD AclRevision;
    } ACL_REVISION_INFORMATION;
    प्रकारनिर्देश ACL_REVISION_INFORMATION *PACL_REVISION_INFORMATION;

    प्रकारनिर्देश संरचना ACL_आकार_INFORMATION {
      DWORD Ace_गणनम्;
      DWORD Acl_अष्टकानि_अन्तर्_Use;
      DWORD Acl_अष्टकानि_Free;
    } ACL_आकार_INFORMATION_2;
    प्रकारनिर्देश ACL_आकार_INFORMATION_2 *PACL_आकार_INFORMATION;

#परिभाषय SECURITY_DESCRIPTOR_REVISION (1)
#परिभाषय SECURITY_DESCRIPTOR_REVISION1 (1)

#परिभाषय SECURITY_DESCRIPTOR_MIN_दीर्घता (परिमाण(SECURITY_DESCRIPTOR))

    प्रकारनिर्देश WORD SECURITY_DESCRIPTOR_CONTROL,*PSECURITY_DESCRIPTOR_CONTROL;

#परिभाषय SE_OWNER_DEFAULTED (0x0001)
#परिभाषय SE_गणः_DEFAULTED (0x0002)
#परिभाषय SE_DACL_PRESENT (0x0004)
#परिभाषय SE_DACL_DEFAULTED (0x0008)
#परिभाषय SE_SACL_PRESENT (0x0010)
#परिभाषय SE_SACL_DEFAULTED (0x0020)
#परिभाषय SE_DACL_AUTO_INHERIT_REQ (0x0100)
#परिभाषय SE_SACL_AUTO_INHERIT_REQ (0x0200)
#परिभाषय SE_DACL_AUTO_INHERITED (0x0400)
#परिभाषय SE_SACL_AUTO_INHERITED (0x0800)
#परिभाषय SE_DACL_PROTECTED (0x1000)
#परिभाषय SE_SACL_PROTECTED (0x2000)
#परिभाषय SE_RM_CONTROL_VALID (0x4000)
#परिभाषय SE_SELF_RELATIVE (0x8000)

    प्रकारनिर्देश संरचना _SECURITY_DESCRIPTOR_RELATIVE {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      DWORD Owner;
      DWORD गणः_2;
      DWORD Sacl;
      DWORD Dacl;
    } SECURITY_DESCRIPTOR_RELATIVE,*PISECURITY_DESCRIPTOR_RELATIVE;

    प्रकारनिर्देश संरचना _SECURITY_DESCRIPTOR {
      BYTE Revision;
      BYTE Sbz1;
      SECURITY_DESCRIPTOR_CONTROL Control;
      PSID Owner;
      PSID गणः_2;
      PACL Sacl;
      PACL Dacl;

    } SECURITY_DESCRIPTOR,*PISECURITY_DESCRIPTOR;

    प्रकारनिर्देश संरचना _OBJECT_TYPE_LIST {
      WORD Level;
      WORD Sbz;
      GUID *ObjectType;
    } OBJECT_TYPE_LIST,*POBJECT_TYPE_LIST;

#परिभाषय ACCESS_OBJECT_GUID 0
#परिभाषय ACCESS_PROPERTY_समुच्चयः_GUID 1
#परिभाषय ACCESS_PROPERTY_GUID 2

#परिभाषय ACCESS_MAX_LEVEL 4

    प्रकारनिर्देश गणना _AUDIT_EVENT_TYPE {
      AuditEventObjectAccess,AuditEventDirectoryServiceAccess
    } AUDIT_EVENT_TYPE,*PAUDIT_EVENT_TYPE;

#परिभाषय AUDIT_ALLOW_NO_PRIVILEGE 0x1

#परिभाषय ACCESS_DS_SOURCE_A "DS"
#परिभाषय ACCESS_DS_SOURCE_W L"DS"
#परिभाषय ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#परिभाषय ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

#परिभाषय SE_PRIVILEGE_ENABLED_BY_DEFAULT (0x00000001L)
#परिभाषय SE_PRIVILEGE_ENABLED (0x00000002L)
#परिभाषय SE_PRIVILEGE_REMOVED (0X00000004L)
#परिभाषय SE_PRIVILEGE_प्रयुक्तम्_FOR_ACCESS (0x80000000L)

#परिभाषय PRIVILEGE_समुच्चयः_ALL_NECESSARY (1)

    प्रकारनिर्देश संरचना PRIVILEGE_समुच्चयः {
      DWORD Privilege_गणनम्;
      DWORD Control;
      LUID_AND_गुणाः_2 Privilege[ANYSIZE_ARRAY];
    } PRIVILEGE_समुच्चयः_2,*PPRIVILEGE_समुच्चयः;

#परिभाषय SE_CREATE_TOKEN_NAME TEXT("SeCreateTokenPrivilege")
#परिभाषय SE_ASSIGNPRIMARYTOKEN_NAME TEXT("SeAssignPrimaryTokenPrivilege")
#परिभाषय SE_तालकम्_स्मृतिः_NAME TEXT("SeLockMemoryPrivilege")
#परिभाषय SE_INCREASE_QUOTA_NAME TEXT("SeIncreaseQuotaPrivilege")
#परिभाषय SE_UNSOLICITED_निवेशः_NAME TEXT("SeUnsolicitedInputPrivilege")
#परिभाषय SE_MACHINE_ACCOUNT_NAME TEXT("SeMachineAccountPrivilege")
#परिभाषय SE_TCB_NAME TEXT("SeTcbPrivilege")
#परिभाषय SE_SECURITY_NAME TEXT("SeSecurityPrivilege")
#परिभाषय SE_TAKE_OWNERSHIP_NAME TEXT("SeTakeOwnershipPrivilege")
#परिभाषय SE_आरोपय_DRIVER_NAME TEXT("SeLoadDriverPrivilege")
#परिभाषय SE_SYSTEM_PROFILE_NAME TEXT("SeSystemProfilePrivilege")
#परिभाषय SE_SYSTEMTIME_NAME TEXT("SeSystemtimePrivilege")
#परिभाषय SE_PROF_SINGLE_PROCESS_NAME TEXT("SeProfileSingleProcessPrivilege")
#परिभाषय SE_INC_आधारः_प्राथमिकता_NAME TEXT("SeIncreaseBasePriorityPrivilege")
#परिभाषय SE_CREATE_PAGEFILE_NAME TEXT("SeCreatePagefilePrivilege")
#परिभाषय SE_CREATE_PERMANENT_NAME TEXT("SeCreatePermanentPrivilege")
#परिभाषय SE_BACKUP_NAME TEXT("SeBackupPrivilege")
#परिभाषय SE_RESTORE_NAME TEXT("SeRestorePrivilege")
#परिभाषय SE_SHUTDOWN_NAME TEXT("SeShutdownPrivilege")
#परिभाषय SE_DEBUG_NAME TEXT("SeDebugPrivilege")
#परिभाषय SE_AUDIT_NAME TEXT("SeAuditPrivilege")
#परिभाषय SE_SYSTEM_ENVIRONMENT_NAME TEXT("SeSystemEnvironmentPrivilege")
#परिभाषय SE_CHANGE_NOTIFY_NAME TEXT("SeChangeNotifyPrivilege")
#परिभाषय SE_REMOTE_SHUTDOWN_NAME TEXT("SeRemoteShutdownPrivilege")
#परिभाषय SE_UNDOCK_NAME TEXT("SeUndockPrivilege")
#परिभाषय SE_SYNC_AGENT_NAME TEXT("SeSyncAgentPrivilege")
#परिभाषय SE_ENABLE_DELEGATION_NAME TEXT("SeEnableDelegationPrivilege")
#परिभाषय SE_MANAGE_VOLUME_NAME TEXT("SeManageVolumePrivilege")
#परिभाषय SE_IMPERSONATE_NAME TEXT("SeImpersonatePrivilege")
#परिभाषय SE_CREATE_GLOBAL_NAME TEXT("SeCreateGlobalPrivilege")

    प्रकारनिर्देश गणना _SECURITY_IMPERSONATION_LEVEL {
      SecurityAnonymous,SecurityIdentification,SecurityImpersonation,SecurityDelegation
    } SECURITY_IMPERSONATION_LEVEL,*PSECURITY_IMPERSONATION_LEVEL;

#परिभाषय SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
#परिभाषय SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
#परिभाषय DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
#परिभाषय VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

#परिभाषय TOKEN_नियोजय_PRIMARY (0x0001)
#परिभाषय TOKEN_DUPLICATE (0x0002)
#परिभाषय TOKEN_IMPERSONATE (0x0004)
#परिभाषय TOKEN_QUERY (0x0008)
#परिभाषय TOKEN_QUERY_SOURCE (0x0010)
#परिभाषय TOKEN_ADJUST_PRIVILEGES (0x0020)
#परिभाषय TOKEN_ADJUST_GROUPS (0x0040)
#परिभाषय TOKEN_ADJUST_DEFAULT (0x0080)
#परिभाषय TOKEN_ADJUST_SESSIONID (0x0100)

#परिभाषय TOKEN_ALL_ACCESS_P (STANDARD_RIGHTS_REQUIRED | TOKEN_नियोजय_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_SOURCE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
#परिभाषय TOKEN_ALL_ACCESS (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
#परिभाषय TOKEN_READ (STANDARD_RIGHTS_READ | TOKEN_QUERY)

#परिभाषय TOKEN_WRITE (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)

#परिभाषय TOKEN_EXECUTE (STANDARD_RIGHTS_EXECUTE)

    प्रकारनिर्देश गणना _TOKEN_TYPE {
      TokenPrimary = 1,TokenImpersonation
    } TOKEN_TYPE;
    प्रकारनिर्देश TOKEN_TYPE *PTOKEN_TYPE;

    प्रकारनिर्देश गणना _TOKEN_INFORMATION_CLASS {
      TokenUser = 1,TokenGroups,TokenPrivileges,TokenOwner,Token_Primary_गणः,TokenDefaultDacl,TokenSource,TokenType,TokenImpersonationLevel,
      TokenStatistics,TokenRestrictedSids,TokenSessionId,TokenGroupsAndPrivileges,TokenSessionReference,TokenSandBoxInert,TokenAuditPolicy,
      TokenOrigin,MaxTokenInfoClass
    } TOKEN_INFORMATION_CLASS,*PTOKEN_INFORMATION_CLASS;

    प्रकारनिर्देश संरचना _TOKEN_USER {
      SID_AND_गुणाः_2 User;
    } TOKEN_USER,*PTOKEN_USER;

    प्रकारनिर्देश संरचना _TOKEN_GROUPS {
      DWORD गणः_गणनम्;
      SID_AND_गुणाः_2 Groups[ANYSIZE_ARRAY];
    } TOKEN_GROUPS,*PTOKEN_GROUPS;

    प्रकारनिर्देश संरचना _TOKEN_PRIVILEGES {
      DWORD Privilege_गणनम्;
      LUID_AND_गुणाः_2 Privileges[ANYSIZE_ARRAY];
    } TOKEN_PRIVILEGES,*PTOKEN_PRIVILEGES;

    प्रकारनिर्देश संरचना _TOKEN_OWNER {
      PSID Owner;
    } TOKEN_OWNER,*PTOKEN_OWNER;

    प्रकारनिर्देश संरचना TOKEN_PRIMARY_गणः {
      PSID Primary_गणः;
    } TOKEN_PRIMARY_गणः_2,*PTOKEN_PRIMARY_गणः;

    प्रकारनिर्देश संरचना _TOKEN_DEFAULT_DACL {
      PACL DefaultDacl;
    } TOKEN_DEFAULT_DACL,*PTOKEN_DEFAULT_DACL;

    प्रकारनिर्देश संरचना _TOKEN_GROUPS_AND_PRIVILEGES {
      DWORD Sid_गणनम्;
      DWORD Sid_दीर्घता;
      PSID_AND_गुणाः Sids;
      DWORD Restricted_Sid_गणनम्;
      DWORD Restricted_Sid_दीर्घता;
      PSID_AND_गुणाः RestrictedSids;
      DWORD Privilege_गणनम्;
      DWORD Privilege_दीर्घता;
      PLUID_AND_गुणाः Privileges;
      LUID AuthenticationId;
    } TOKEN_GROUPS_AND_PRIVILEGES,*PTOKEN_GROUPS_AND_PRIVILEGES;

#परिभाषय TOKEN_AUDIT_SUCCESS_INCLUDE 0x1
#परिभाषय TOKEN_AUDIT_SUCCESS_EXCLUDE 0x2
#परिभाषय TOKEN_AUDIT_FAILURE_INCLUDE 0x4
#परिभाषय TOKEN_AUDIT_FAILURE_EXCLUDE 0x8

#परिभाषय VALID_AUDIT_POLICY_द्वयङ्काः (TOKEN_AUDIT_SUCCESS_INCLUDE | TOKEN_AUDIT_SUCCESS_EXCLUDE | TOKEN_AUDIT_FAILURE_INCLUDE | TOKEN_AUDIT_FAILURE_EXCLUDE)
#परिभाषय VALID_TOKEN_AUDIT_POLICY_ELEMENT(P) ((((P).Policy_आवरणम् & ~VALID_AUDIT_POLICY_द्वयङ्काः)==0) && ((P).Category <= AuditEventMaxType))

    प्रकारनिर्देश संरचना _TOKEN_AUDIT_POLICY_ELEMENT {
      DWORD Category;
      DWORD Policy_आवरणम्;
    } TOKEN_AUDIT_POLICY_ELEMENT,*PTOKEN_AUDIT_POLICY_ELEMENT;

    प्रकारनिर्देश संरचना _TOKEN_AUDIT_POLICY {
      DWORD Policy_गणनम्;
      TOKEN_AUDIT_POLICY_ELEMENT Policy[ANYSIZE_ARRAY];
    } TOKEN_AUDIT_POLICY,*PTOKEN_AUDIT_POLICY;

#परिभाषय प्रत्येकम्_USER_AUDITING_POLICY_आकार(p) (परिमाण(TOKEN_AUDIT_POLICY) + (((p)->Policy_गणनम् > ANYSIZE_ARRAY) ? (परिमाण(TOKEN_AUDIT_POLICY_ELEMENT) *((p)->Policy_गणनम् - ANYSIZE_ARRAY)) : 0))
#परिभाषय प्रत्येकम्_USER_AUDITING_POLICY_आकार_BY_गणनम्(C) (परिमाण(TOKEN_AUDIT_POLICY) + (((C) > ANYSIZE_ARRAY) ? (परिमाण(TOKEN_AUDIT_POLICY_ELEMENT) *((C) - ANYSIZE_ARRAY)) : 0))

#परिभाषय TOKEN_SOURCE_दीर्घता 8

    प्रकारनिर्देश संरचना _TOKEN_SOURCE {
      CHAR SourceName[TOKEN_SOURCE_दीर्घता];
      LUID SourceIdentifier;
    } TOKEN_SOURCE,*PTOKEN_SOURCE;

    प्रकारनिर्देश संरचना _TOKEN_STATISTICS {
      LUID TokenId;
      LUID AuthenticationId;
      LARGE_INTEGER ExpirationTime;
      TOKEN_TYPE TokenType;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      DWORD DynamicCharged;
      DWORD Dynamic_उपलब्धम्;
      DWORD गणः_गणनम्;
      DWORD Privilege_गणनम्;
      LUID ModifiedId;
    } TOKEN_STATISTICS,*PTOKEN_STATISTICS;

    प्रकारनिर्देश संरचना _TOKEN_CONTROL {
      LUID TokenId;
      LUID AuthenticationId;
      LUID ModifiedId;
      TOKEN_SOURCE TokenSource;
    } TOKEN_CONTROL,*PTOKEN_CONTROL;

    प्रकारनिर्देश संरचना _TOKEN_ORIGIN {
      LUID OriginatingLogonSession;
    } TOKEN_ORIGIN,*PTOKEN_ORIGIN;

#परिभाषय SECURITY_DYNAMIC_TRACKING (TRUE)
#परिभाषय SECURITY_STATIC_TRACKING (FALSE)

    प्रकारनिर्देश BOOLEAN SECURITY_CONTEXT_TRACKING_बहुलकम्,*PSECURITY_CONTEXT_TRACKING_बहुलकम्;

    प्रकारनिर्देश संरचना SECURITY_QUALITY_सम्बन्धि_SERVICE {
      DWORD दीर्घता_2;
      SECURITY_IMPERSONATION_LEVEL ImpersonationLevel;
      SECURITY_CONTEXT_TRACKING_बहुलकम् Context_Tracking_बहुलकम्;
      BOOLEAN EffectiveOnly;
    } SECURITY_QUALITY_सम्बन्धि_SERVICE_2,*PSECURITY_QUALITY_सम्बन्धि_SERVICE;

    प्रकारनिर्देश संरचना _SE_IMPERSONATION_STATE {
      PACCESS_TOKEN Token;
      BOOLEAN CopyOnOpen;
      BOOLEAN EffectiveOnly;
      SECURITY_IMPERSONATION_LEVEL Level;
    } SE_IMPERSONATION_STATE,*PSE_IMPERSONATION_STATE;

#परिभाषय DISABLE_MAX_PRIVILEGE 0x1
#परिभाषय SANDBOX_INERT 0x2

    प्रकारनिर्देश DWORD SECURITY_INFORMATION,*PSECURITY_INFORMATION;

#परिभाषय OWNER_SECURITY_INFORMATION (0x00000001L)
#परिभाषय गणः_SECURITY_INFORMATION (0x00000002L)
#परिभाषय DACL_SECURITY_INFORMATION (0x00000004L)
#परिभाषय SACL_SECURITY_INFORMATION (0x00000008L)

#परिभाषय PROTECTED_DACL_SECURITY_INFORMATION (0x80000000L)
#परिभाषय PROTECTED_SACL_SECURITY_INFORMATION (0x40000000L)
#परिभाषय UNPROTECTED_DACL_SECURITY_INFORMATION (0x20000000L)
#परिभाषय UNPROTECTED_SACL_SECURITY_INFORMATION (0x10000000L)

#परिभाषय PROCESS_TERMINATE (0x0001)
#परिभाषय PROCESS_CREATE_THREAD (0x0002)
#परिभाषय PROCESS_समुच्चयः_SESSIONID (0x0004)
#परिभाषय PROCESS_VM_OPERATION (0x0008)
#परिभाषय PROCESS_VM_READ (0x0010)
#परिभाषय PROCESS_VM_WRITE (0x0020)
#परिभाषय PROCESS_DUP_HANDLE (0x0040)
#परिभाषय PROCESS_CREATE_PROCESS (0x0080)
#परिभाषय PROCESS_समुच्चयः_QUOTA (0x0100)
#परिभाषय PROCESS_समुच्चयः_INFORMATION (0x0200)
#परिभाषय PROCESS_QUERY_INFORMATION (0x0400)
#परिभाषय PROCESS_SUSPEND_RESUME (0x0800)
#परिभाषय PROCESS_QUERY_LIMITED_INFORMATION (0x1000)
#परिभाषय PROCESS_समुच्चयः_LIMITED_INFORMATION (0x2000)
#परिभाषय PROCESS_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0xFFF)

#यदि_परिभाषितम् _WIN64
#परिभाषय अधिकतमम्_PROCESSORS 64
#अन्यथा
#परिभाषय अधिकतमम्_PROCESSORS 32
#यदि_अन्तः

#परिभाषय THREAD_TERMINATE (0x0001)
#परिभाषय THREAD_SUSPEND_RESUME (0x0002)
#परिभाषय THREAD_GET_CONTEXT (0x0008)
#परिभाषय THREAD_समुच्चयः_CONTEXT (0x0010)
#परिभाषय THREAD_समुच्चयः_INFORMATION (0x0020)
#परिभाषय THREAD_QUERY_INFORMATION (0x0040)
#परिभाषय THREAD_समुच्चयः_THREAD_TOKEN (0x0080)
#परिभाषय THREAD_IMPERSONATE (0x0100)
#परिभाषय THREAD_प्रत्यक्षम्_IMPERSONATION (0x0200)

#परिभाषय THREAD_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x3FF)

#परिभाषय JOB_OBJECT_नियोजय_PROCESS (0x0001)
#परिभाषय JOB_OBJECT_समुच्चयः_गुणाः (0x0002)
#परिभाषय JOB_OBJECT_QUERY (0x0004)
#परिभाषय JOB_OBJECT_TERMINATE (0x0008)
#परिभाषय JOB_OBJECT_समुच्चयः_SECURITY_गुणाः (0x0010)
#परिभाषय JOB_OBJECT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1F)

    प्रकारनिर्देश संरचना JOB_समुच्चयः_ARRAY {
      HANDLE JobHandle;
      DWORD MemberLevel;
      DWORD Flags;
    } JOB_समुच्चयः_ARRAY_2,*PJOB_समुच्चयः_ARRAY;

#परिभाषय FLS_अधिकतमम्_उपलब्धम् 128
#परिभाषय TLS_MINIMUM_उपलब्धम् 64

#यदि_अपरिभाषितम् _NT_TIB_DEFINED
#परिभाषय _NT_TIB_DEFINED
    प्रकारनिर्देश संरचना _NT_TIB {
      संरचना EXCEPTION_REGISTRATION_लेखः_2 *ExceptionList;
      PVOID राशिः_आधारः;
      PVOID राशिः_सीमा;
      PVOID SubSystemTib;
      सङ्घ {
	PVOID Fiber_दत्त;
	DWORD संस्करणम्_2;
      };
      PVOID ArbitraryUserPointer;
      संरचना _NT_TIB *Self;
    } NT_TIB;
    प्रकारनिर्देश NT_TIB *PNT_TIB;
#यदि_अन्तः

    प्रकारनिर्देश संरचना _NT_TIB32 {
      DWORD ExceptionList;
      DWORD राशिः_आधारः;
      DWORD राशिः_सीमा;
      DWORD SubSystemTib;
      सङ्घ {
	DWORD Fiber_दत्त;
	DWORD संस्करणम्_2;
      };
      DWORD ArbitraryUserPointer;
      DWORD Self;
    } NT_TIB32,*PNT_TIB32;

    प्रकारनिर्देश संरचना _NT_TIB64 {
      DWORD64 ExceptionList;
      DWORD64 राशिः_आधारः;
      DWORD64 राशिः_सीमा;
      DWORD64 SubSystemTib;
      सङ्घ {
	DWORD64 Fiber_दत्त;
	DWORD संस्करणम्_2;
      };
      DWORD64 ArbitraryUserPointer;
      DWORD64 Self;
    } NT_TIB64,*PNT_TIB64;

#यदि !defined(I_X86_) && !defined(_IA64_) && !defined(_AMD64_)
#परिभाषय WX86
#यदि_अन्तः

#परिभाषय THREAD_आधारः_प्राथमिकता_LOWRT 15
#परिभाषय THREAD_आधारः_प्राथमिकता_MAX 2
#परिभाषय THREAD_आधारः_प्राथमिकता_MIN (-2)
#परिभाषय THREAD_आधारः_प्राथमिकता_IDLE (-15)

    प्रकारनिर्देश संरचना _QUOTA_LIMITS {
      आकार_T Paged_Pool_सीमा;
      आकार_T Non_Paged_Pool_सीमा;
      आकार_T Minimum_Working_समुच्चयः_आकार;
      आकार_T अधिकतमम्_Working_समुच्चयः_आकार;
      आकार_T Pagefile_सीमा;
      LARGE_INTEGER Time_सीमा;
    } QUOTA_LIMITS,*PQUOTA_LIMITS;

#परिभाषय QUOTA_LIMITS_HARDWS_MIN_ENABLE 0x00000001
#परिभाषय QUOTA_LIMITS_HARDWS_MIN_DISABLE 0x00000002
#परिभाषय QUOTA_LIMITS_HARDWS_MAX_ENABLE 0x00000004
#परिभाषय QUOTA_LIMITS_HARDWS_MAX_DISABLE 0x00000008

    प्रकारनिर्देश संरचना _QUOTA_LIMITS_EX {
      आकार_T Paged_Pool_सीमा;
      आकार_T Non_Paged_Pool_सीमा;
      आकार_T Minimum_Working_समुच्चयः_आकार;
      आकार_T अधिकतमम्_Working_समुच्चयः_आकार;
      आकार_T Pagefile_सीमा;
      LARGE_INTEGER Time_सीमा;
      आकार_T Reserved1;
      आकार_T Reserved2;
      आकार_T Reserved3;
      आकार_T Reserved4;
      DWORD Flags;
      DWORD Reserved5;
    } QUOTA_LIMITS_EX,*PQUOTA_LIMITS_EX;

    प्रकारनिर्देश संरचना _IO_COUNTERS {
      ULONGLONG Read_Operation_गणनम्;
      ULONGLONG Write_Operation_गणनम्;
      ULONGLONG Other_Operation_गणनम्;
      ULONGLONG Read_Transfer_गणनम्;
      ULONGLONG Write_Transfer_गणनम्;
      ULONGLONG Other_Transfer_गणनम्;
    } IO_COUNTERS;
    प्रकारनिर्देश IO_COUNTERS *PIO_COUNTERS;

    प्रकारनिर्देश संरचना _JOBOBJECT_BASIC_ACCOUNTING_INFORMATION {
      LARGE_INTEGER योग_User_Time;
      LARGE_INTEGER योग_Kernel_Time;
      LARGE_INTEGER This_Period_योग_User_Time;
      LARGE_INTEGER This_Period_योग_Kernel_Time;
      DWORD योग_Page_Fault_गणनम्;
      DWORD योग_Processes;
      DWORD सक्रिय_Processes;
      DWORD योग_Terminated_Processes;
    } JOBOBJECT_BASIC_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_ACCOUNTING_INFORMATION;

    प्रकारनिर्देश संरचना JOBOBJECT_BASIC_सीमा_INFORMATION {
      LARGE_INTEGER प्रत्येकम्_Process_User_Time_सीमा;
      LARGE_INTEGER प्रत्येकम्_Job_User_Time_सीमा;
      DWORD सीमा_Flags;
      आकार_T Minimum_Working_समुच्चयः_आकार;
      आकार_T अधिकतमम्_Working_समुच्चयः_आकार;
      DWORD सक्रिय_Process_सीमा;
      ULONG_PTR Affinity;
      DWORD प्राथमिकता_Class;
      DWORD SchedulingClass;
    } JOBOBJECT_BASIC_सीमा_INFORMATION_2,*PJOBOBJECT_BASIC_सीमा_INFORMATION;

    प्रकारनिर्देश संरचना JOBOBJECT_EXTENDED_सीमा_INFORMATION {
      JOBOBJECT_BASIC_सीमा_INFORMATION_2 Basic_सीमा_Information;
      IO_COUNTERS IoInfo;
      आकार_T Process_स्मृतिः_सीमा;
      आकार_T Job_स्मृतिः_सीमा;
      आकार_T Peak_Process_स्मृतिः_प्रयुक्तम्;
      आकार_T Peak_Job_स्मृतिः_प्रयुक्तम्;
    } JOBOBJECT_EXTENDED_सीमा_INFORMATION_2,*PJOBOBJECT_EXTENDED_सीमा_INFORMATION;

    प्रकारनिर्देश संरचना _JOBOBJECT_BASIC_PROCESS_ID_LIST {
      DWORD सङ्ख्या_सम्बन्धि_Assigned_Processes;
      DWORD सङ्ख्या_सम्बन्धि_Process_Ids_अन्तर्_List;
      ULONG_PTR ProcessIdList[1];
    } JOBOBJECT_BASIC_PROCESS_ID_LIST,*PJOBOBJECT_BASIC_PROCESS_ID_LIST;

    प्रकारनिर्देश संरचना _JOBOBJECT_BASIC_UI_RESTRICTIONS {
      DWORD UIRestrictionsClass;
    } JOBOBJECT_BASIC_UI_RESTRICTIONS,*PJOBOBJECT_BASIC_UI_RESTRICTIONS;

    प्रकारनिर्देश संरचना JOBOBJECT_SECURITY_सीमा_INFORMATION {
      DWORD Security_सीमा_Flags;
      HANDLE JobToken;
      PTOKEN_GROUPS Sids_गन्तव्यम्_Disable;
      PTOKEN_PRIVILEGES Privileges_गन्तव्यम्_Delete;
      PTOKEN_GROUPS RestrictedSids;
    } JOBOBJECT_SECURITY_सीमा_INFORMATION_2,*PJOBOBJECT_SECURITY_सीमा_INFORMATION;

    प्रकारनिर्देश संरचना JOBOBJECT_अन्तः_सम्बन्धि_JOB_TIME_INFORMATION {
      DWORD अन्तः_सम्बन्धि_Job_Time_Action;
    } JOBOBJECT_अन्तः_सम्बन्धि_JOB_TIME_INFORMATION_2,*PJOBOBJECT_अन्तः_सम्बन्धि_JOB_TIME_INFORMATION;

    प्रकारनिर्देश संरचना JOBOBJECT_ASSOCIATE_COMPLETION_पत्तनम् {
      PVOID Completion_कुञ्चिका;
      HANDLE Completion_पत्तनम्;
    } JOBOBJECT_ASSOCIATE_COMPLETION_पत्तनम्_2,*PJOBOBJECT_ASSOCIATE_COMPLETION_पत्तनम्;

    प्रकारनिर्देश संरचना _JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION {
      JOBOBJECT_BASIC_ACCOUNTING_INFORMATION BasicInfo;
      IO_COUNTERS IoInfo;
    } JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION,*PJOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION;

    प्रकारनिर्देश संरचना _JOBOBJECT_JOBSET_INFORMATION {
      DWORD MemberLevel;
    } JOBOBJECT_JOBSET_INFORMATION,*PJOBOBJECT_JOBSET_INFORMATION;

#परिभाषय JOB_OBJECT_TERMINATE_AT_अन्तः_सम्बन्धि_JOB 0
#परिभाषय JOB_OBJECT_POST_AT_अन्तः_सम्बन्धि_JOB 1

#परिभाषय JOB_OBJECT_सन्देशः_अन्तः_सम्बन्धि_JOB_TIME 1
#परिभाषय JOB_OBJECT_सन्देशः_अन्तः_सम्बन्धि_PROCESS_TIME 2
#परिभाषय JOB_OBJECT_सन्देशः_सक्रिय_PROCESS_सीमा 3
#परिभाषय JOB_OBJECT_सन्देशः_सक्रिय_PROCESS_ZERO 4
#परिभाषय JOB_OBJECT_सन्देशः_NEW_PROCESS 6
#परिभाषय JOB_OBJECT_सन्देशः_EXIT_PROCESS 7
#परिभाषय JOB_OBJECT_सन्देशः_ABNORMAL_EXIT_PROCESS 8
#परिभाषय JOB_OBJECT_सन्देशः_PROCESS_स्मृतिः_सीमा 9
#परिभाषय JOB_OBJECT_सन्देशः_JOB_स्मृतिः_सीमा 10

#परिभाषय JOB_OBJECT_सीमा_WORKINGSET 0x00000001
#परिभाषय JOB_OBJECT_सीमा_PROCESS_TIME 0x00000002
#परिभाषय JOB_OBJECT_सीमा_JOB_TIME 0x00000004
#परिभाषय JOB_OBJECT_सीमा_सक्रिय_PROCESS 0x00000008
#परिभाषय JOB_OBJECT_सीमा_AFFINITY 0x00000010
#परिभाषय JOB_OBJECT_सीमा_प्राथमिकता_CLASS 0x00000020
#परिभाषय JOB_OBJECT_सीमा_PRESERVE_JOB_TIME 0x00000040
#परिभाषय JOB_OBJECT_सीमा_SCHEDULING_CLASS 0x00000080

#परिभाषय JOB_OBJECT_सीमा_PROCESS_स्मृतिः 0x00000100
#परिभाषय JOB_OBJECT_सीमा_JOB_स्मृतिः 0x00000200
#परिभाषय JOB_OBJECT_सीमा_DIE_ON_UNHANDLED_EXCEPTION 0x00000400
#परिभाषय JOB_OBJECT_सीमा_BREAKAWAY_OK 0x00000800
#परिभाषय JOB_OBJECT_सीमा_SILENT_BREAKAWAY_OK 0x00001000
#परिभाषय JOB_OBJECT_सीमा_KILL_ON_JOB_CLOSE 0x00002000

#परिभाषय JOB_OBJECT_सीमा_RESERVED2 0x00004000
#परिभाषय JOB_OBJECT_सीमा_RESERVED3 0x00008000
#परिभाषय JOB_OBJECT_सीमा_RESERVED4 0x00010000
#परिभाषय JOB_OBJECT_सीमा_RESERVED5 0x00020000
#परिभाषय JOB_OBJECT_सीमा_RESERVED6 0x00040000

#परिभाषय JOB_OBJECT_सीमा_VALID_FLAGS 0x0007ffff

#परिभाषय JOB_OBJECT_BASIC_सीमा_VALID_FLAGS 0x000000ff
#परिभाषय JOB_OBJECT_EXTENDED_सीमा_VALID_FLAGS 0x00003fff
#परिभाषय JOB_OBJECT_RESERVED_सीमा_VALID_FLAGS 0x0007ffff

#परिभाषय JOB_OBJECT_UILIMIT_NONE 0x00000000

#परिभाषय JOB_OBJECT_UILIMIT_HANDLES 0x00000001
#परिभाषय JOB_OBJECT_UILIMIT_READCLIPBOARD 0x00000002
#परिभाषय JOB_OBJECT_UILIMIT_WRITECLIPBOARD 0x00000004
#परिभाषय JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS 0x00000008
#परिभाषय JOB_OBJECT_UILIMIT_DISPLAYSETTINGS 0x00000010
#परिभाषय JOB_OBJECT_UILIMIT_GLOBALATOMS 0x00000020
#परिभाषय JOB_OBJECT_UILIMIT_DESKTOP 0x00000040
#परिभाषय JOB_OBJECT_UILIMIT_EXITWINDOWS 0x00000080

#परिभाषय JOB_OBJECT_UILIMIT_ALL 0x000000FF

#परिभाषय JOB_OBJECT_UI_VALID_FLAGS 0x000000FF

#परिभाषय JOB_OBJECT_SECURITY_NO_ADMIN 0x00000001
#परिभाषय JOB_OBJECT_SECURITY_RESTRICTED_TOKEN 0x00000002
#परिभाषय JOB_OBJECT_SECURITY_ONLY_TOKEN 0x00000004
#परिभाषय JOB_OBJECT_SECURITY_FILTER_TOKENS 0x00000008

#परिभाषय JOB_OBJECT_SECURITY_VALID_FLAGS 0x0000000f

    प्रकारनिर्देश गणना _JOBOBJECTINFOCLASS {
      JobObjectBasicAccountingInformation = 1,Job_Object_Basic_सीमा_Information,JobObjectBasicProcessIdList,JobObjectBasicUIRestrictions,
      Job_Object_Security_सीमा_Information,Job_Object_अन्तः_सम्बन्धि_Job_Time_Information,Job_Object_Associate_Completion_पत्तनम्_Information,
      JobObjectBasicAndIoAccountingInformation,Job_Object_Extended_सीमा_Information,Job_Object_Job_समुच्चयः_Information,MaxJobObjectInfoClass
    } JOBOBJECTINFOCLASS;

#परिभाषय EVENT_MODIFY_STATE 0x0002
#परिभाषय EVENT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#परिभाषय MUTANT_QUERY_STATE 0x0001

#परिभाषय MUTANT_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| MUTANT_QUERY_STATE)
#परिभाषय SEMAPHORE_MODIFY_STATE 0x0002
#परिभाषय SEMAPHORE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)

#परिभाषय TIMER_QUERY_STATE 0x0001
#परिभाषय TIMER_MODIFY_STATE 0x0002

#परिभाषय TIMER_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE| TIMER_QUERY_STATE|TIMER_MODIFY_STATE)

#परिभाषय TIME_ZONE_ID_UNKNOWN 0
#परिभाषय TIME_ZONE_ID_STANDARD 1
#परिभाषय TIME_ZONE_ID_DAYLIGHT 2

    प्रकारनिर्देश गणना _LOGICAL_PROCESSOR_RELATIONSHIP {
      सम्बन्धः_Processor_Core,सम्बन्धः_Numa_ग्रन्थिः,सम्बन्धः_Cache
    } LOGICAL_PROCESSOR_RELATIONSHIP;

#परिभाषय LTP_PC_SMT 0x1

    प्रकारनिर्देश गणना _PROCESSOR_CACHE_TYPE {
      CacheUnified,CacheInstruction,Cache_दत्त,CacheTrace
    } PROCESSOR_CACHE_TYPE;

#परिभाषय CACHE_FULLY_ASSOCIATIVE 0xFF

    प्रकारनिर्देश संरचना _CACHE_DESCRIPTOR {
      BYTE Level;
      BYTE Associativity;
      WORD पङ्क्तिः_आकार_2;
      DWORD आकार_3;
      PROCESSOR_CACHE_TYPE Type;
    } CACHE_DESCRIPTOR,*PCACHE_DESCRIPTOR;

    प्रकारनिर्देश संरचना _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
      ULONG_PTR Processor_आवरणम्;
      LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
      सङ्घ {
	संरचना {
	  BYTE Flags;
	} ProcessorCore;
	संरचना {
	  DWORD ग्रन्थिः_सङ्ख्या;
	} Numa_ग्रन्थिः;
	CACHE_DESCRIPTOR Cache;
	ULONGLONG Reserved[2];
      };
    } SYSTEM_LOGICAL_PROCESSOR_INFORMATION,*PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

#परिभाषय PROCESSOR_INTEL_386 386
#परिभाषय PROCESSOR_INTEL_486 486
#परिभाषय PROCESSOR_INTEL_PENTIUM 586
#परिभाषय PROCESSOR_INTEL_IA64 2200
#परिभाषय PROCESSOR_AMD_X8664 8664
#परिभाषय PROCESSOR_MIPS_R4000 4000
#परिभाषय PROCESSOR_ALPHA_21064 21064
#परिभाषय PROCESSOR_PPC_601 601
#परिभाषय PROCESSOR_PPC_603 603
#परिभाषय PROCESSOR_PPC_604 604
#परिभाषय PROCESSOR_PPC_620 620
#परिभाषय PROCESSOR_HITACHI_SH3 10003
#परिभाषय PROCESSOR_HITACHI_SH3E 10004
#परिभाषय PROCESSOR_HITACHI_SH4 10005
#परिभाषय PROCESSOR_MOTOROLA_821 821
#परिभाषय PROCESSOR_SHx_SH3 103
#परिभाषय PROCESSOR_SHx_SH4 104
#परिभाषय PROCESSOR_STRONGARM 2577
#परिभाषय PROCESSOR_ARM720 1824
#परिभाषय PROCESSOR_ARM820 2080
#परिभाषय PROCESSOR_ARM920 2336
#परिभाषय PROCESSOR_ARM_7TDMI 70001
#परिभाषय PROCESSOR_OPTIL 0x494f

#परिभाषय PROCESSOR_ARCHITECTURE_INTEL 0
#परिभाषय PROCESSOR_ARCHITECTURE_MIPS 1
#परिभाषय PROCESSOR_ARCHITECTURE_ALPHA 2
#परिभाषय PROCESSOR_ARCHITECTURE_PPC 3
#परिभाषय PROCESSOR_ARCHITECTURE_SHX 4
#परिभाषय PROCESSOR_ARCHITECTURE_ARM 5
#परिभाषय PROCESSOR_ARCHITECTURE_IA64 6
#परिभाषय PROCESSOR_ARCHITECTURE_ALPHA64 7
#परिभाषय PROCESSOR_ARCHITECTURE_MSIL 8
#परिभाषय PROCESSOR_ARCHITECTURE_AMD64 9
#परिभाषय PROCESSOR_ARCHITECTURE_IA32_ON_WIN64 10

#परिभाषय PROCESSOR_ARCHITECTURE_UNKNOWN 0xFFFF

#परिभाषय PF_FLOATING_POINT_PRECISION_ERRATA 0
#परिभाषय PF_FLOATING_POINT_EMULATED 1
#परिभाषय PF_COMPARE_EXCHANGE_DOUBLE 2
#परिभाषय PF_MMX_INSTRUCTIONS_उपलब्धम् 3
#परिभाषय PF_PPC_MOVEMEM_64BIT_OK 4
#परिभाषय PF_ALPHA_BYTE_INSTRUCTIONS 5
#परिभाषय PF_XMMI_INSTRUCTIONS_उपलब्धम् 6
#परिभाषय PF_3_DNOW_INSTRUCTIONS_उपलब्धम् 7
#परिभाषय PF_RDTSC_INSTRUCTION_उपलब्धम् 8
#परिभाषय PF_PAE_ENABLED 9
#परिभाषय PF_XMMI64_INSTRUCTIONS_उपलब्धम् 10
#परिभाषय PF_SSE_DAZ_बहुलकम्_उपलब्धम् 11
#परिभाषय PF_NX_ENABLED 12

    प्रकारनिर्देश संरचना स्मृतिः_BASIC_INFORMATION_2 {
      PVOID आधारः_स्थानाङ्कः;
      PVOID आवण्टनम्_आधारः;
      DWORD आवण्टनम्_Protect;
      आकार_T Region_आकार;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } स्मृतिः_BASIC_INFORMATION,*PMEMORY_BASIC_INFORMATION;

    प्रकारनिर्देश संरचना स्मृतिः_BASIC_INFORMATION32 {
      DWORD आधारः_स्थानाङ्कः;
      DWORD आवण्टनम्_आधारः;
      DWORD आवण्टनम्_Protect;
      DWORD Region_आकार;
      DWORD State;
      DWORD Protect;
      DWORD Type;
    } स्मृतिः_BASIC_INFORMATION32_2,*PMEMORY_BASIC_INFORMATION32;

    प्रकारनिर्देश संरचना DECLSPEC_ALIGN(16) स्मृतिः_BASIC_INFORMATION64 {
      ULONGLONG आधारः_स्थानाङ्कः;
      ULONGLONG आवण्टनम्_आधारः;
      DWORD आवण्टनम्_Protect;
      DWORD __alignment1;
      ULONGLONG Region_आकार;
      DWORD State;
      DWORD Protect;
      DWORD Type;
      DWORD __alignment2;
    } स्मृतिः_BASIC_INFORMATION64_2,*PMEMORY_BASIC_INFORMATION64;

#परिभाषय SECTION_QUERY 0x0001
#परिभाषय SECTION_MAP_WRITE 0x0002
#परिभाषय SECTION_MAP_READ 0x0004
#परिभाषय SECTION_MAP_EXECUTE 0x0008
#परिभाषय SECTION_EXTEND_आकार 0x0010
#परिभाषय SECTION_MAP_EXECUTE_EXPLICIT 0x0020

#परिभाषय SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY| SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_आकार)
#परिभाषय PAGE_NOACCESS 0x01
#परिभाषय PAGE_READONLY 0x02
#परिभाषय PAGE_READWRITE 0x04
#परिभाषय PAGE_WRITECOPY 0x08
#परिभाषय PAGE_EXECUTE 0x10
#परिभाषय PAGE_EXECUTE_READ 0x20
#परिभाषय PAGE_EXECUTE_READWRITE 0x40
#परिभाषय PAGE_EXECUTE_WRITECOPY 0x80
#परिभाषय PAGE_GUARD 0x100
#परिभाषय PAGE_NOCACHE 0x200
#परिभाषय PAGE_WRITECOMBINE 0x400
#परिभाषय MEM_COMMIT 0x1000
#परिभाषय MEM_RESERVE 0x2000
#परिभाषय MEM_DECOMMIT 0x4000
#परिभाषय MEM_RELEASE 0x8000
#परिभाषय MEM_FREE 0x10000
#परिभाषय MEM_वैयक्तिकम् 0x20000
#परिभाषय MEM_MAPPED 0x40000
#परिभाषय MEM_RESET 0x80000
#परिभाषय MEM_शिखरम्_अधस्तात् 0x100000
#परिभाषय MEM_WRITE_WATCH 0x200000
#परिभाषय MEM_PHYSICAL 0x400000
#परिभाषय MEM_LARGE_पृष्ठानि 0x20000000
#परिभाषय MEM_4_MB_पृष्ठानि 0x80000000
#परिभाषय SEC_FILE 0x800000
#परिभाषय SEC_IMAGE 0x1000000
#परिभाषय SEC_RESERVE 0x4000000
#परिभाषय SEC_COMMIT 0x8000000
#परिभाषय SEC_NOCACHE 0x10000000
#परिभाषय SEC_LARGE_पृष्ठानि 0x80000000
#परिभाषय MEM_IMAGE SEC_IMAGE
#परिभाषय WRITE_WATCH_FLAG_RESET 0x01

#परिभाषय FILE_READ_दत्त (0x0001)
#परिभाषय FILE_LIST_DIRECTORY (0x0001)

#परिभाषय FILE_WRITE_दत्त (0x0002)
#परिभाषय FILE_सङ्कलय_FILE (0x0002)

#परिभाषय FILE_APPEND_दत्त (0x0004)
#परिभाषय FILE_सङ्कलय_SUBDIRECTORY (0x0004)
#परिभाषय FILE_CREATE_PIPE_INSTANCE (0x0004)

#परिभाषय FILE_READ_EA (0x0008)

#परिभाषय FILE_WRITE_EA (0x0010)

#परिभाषय FILE_EXECUTE (0x0020)
#परिभाषय FILE_TRAVERSE (0x0020)

#परिभाषय FILE_DELETE_CHILD (0x0040)

#परिभाषय FILE_READ_गुणाः (0x0080)

#परिभाषय FILE_WRITE_गुणाः (0x0100)

#परिभाषय FILE_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 0x1FF)
#परिभाषय FILE_GENERIC_READ (STANDARD_RIGHTS_READ | FILE_READ_दत्त | FILE_READ_गुणाः | FILE_READ_EA | SYNCHRONIZE)
#परिभाषय FILE_GENERIC_WRITE (STANDARD_RIGHTS_WRITE | FILE_WRITE_दत्त | FILE_WRITE_गुणाः | FILE_WRITE_EA | FILE_APPEND_दत्त | SYNCHRONIZE)
#परिभाषय FILE_GENERIC_EXECUTE (STANDARD_RIGHTS_EXECUTE | FILE_READ_गुणाः | FILE_EXECUTE | SYNCHRONIZE)

#परिभाषय FILE_SHARE_READ 0x00000001
#परिभाषय FILE_SHARE_WRITE 0x00000002
#परिभाषय FILE_SHARE_DELETE 0x00000004
#परिभाषय FILE_ATTRIBUTE_READONLY 0x00000001
#परिभाषय FILE_ATTRIBUTE_HIDDEN 0x00000002
#परिभाषय FILE_ATTRIBUTE_SYSTEM 0x00000004
#परिभाषय FILE_ATTRIBUTE_DIRECTORY 0x00000010
#परिभाषय FILE_ATTRIBUTE_ARCHIVE 0x00000020
#परिभाषय FILE_ATTRIBUTE_DEVICE 0x00000040
#परिभाषय FILE_ATTRIBUTE_प्रसामान्यम् 0x00000080
#परिभाषय FILE_ATTRIBUTE_TEMPORARY 0x00000100
#परिभाषय FILE_ATTRIBUTE_SPARSE_FILE 0x00000200
#परिभाषय FILE_ATTRIBUTE_REPARSE_POINT 0x00000400
#परिभाषय FILE_ATTRIBUTE_COMPRESSED 0x00000800
#परिभाषय FILE_ATTRIBUTE_OFFLINE 0x00001000
#परिभाषय FILE_ATTRIBUTE_NOT_CONTENT_अनुक्रमितम् 0x00002000
#परिभाषय FILE_ATTRIBUTE_ENCRYPTED 0x00004000
#परिभाषय FILE_NOTIFY_CHANGE_FILE_NAME 0x00000001
#परिभाषय FILE_NOTIFY_CHANGE_DIR_NAME 0x00000002
#परिभाषय FILE_NOTIFY_CHANGE_गुणाः 0x00000004
#परिभाषय FILE_NOTIFY_CHANGE_आकार 0x00000008
#परिभाषय FILE_NOTIFY_CHANGE_चरमः_WRITE 0x00000010
#परिभाषय FILE_NOTIFY_CHANGE_चरमः_ACCESS 0x00000020
#परिभाषय FILE_NOTIFY_CHANGE_CREATION 0x00000040
#परिभाषय FILE_NOTIFY_CHANGE_SECURITY 0x00000100
#परिभाषय FILE_ACTION_ADDED 0x00000001
#परिभाषय FILE_ACTION_REMOVED 0x00000002
#परिभाषय FILE_ACTION_MODIFIED 0x00000003
#परिभाषय FILE_ACTION_RENAMED_OLD_NAME 0x00000004
#परिभाषय FILE_ACTION_RENAMED_NEW_NAME 0x00000005
#परिभाषय MAILSLOT_NO_सन्देशः ((DWORD)-1)
#परिभाषय MAILSLOT_WAIT_FOREVER ((DWORD)-1)
#परिभाषय FILE_CASE_SENSITIVE_अन्वेषणम् 0x00000001
#परिभाषय FILE_CASE_PRESERVED_नामानि 0x00000002
#परिभाषय FILE_UNICODE_ON_DISK 0x00000004
#परिभाषय FILE_PERSISTENT_ACLS 0x00000008
#परिभाषय FILE_FILE_COMPRESSION 0x00000010
#परिभाषय FILE_VOLUME_QUOTAS 0x00000020
#परिभाषय FILE_SUPPORTS_SPARSE_FILES 0x00000040
#परिभाषय FILE_SUPPORTS_REPARSE_POINTS 0x00000080
#परिभाषय FILE_SUPPORTS_REMOTE_STORAGE 0x00000100
#परिभाषय FILE_VOLUME_IS_COMPRESSED 0x00008000
#परिभाषय FILE_SUPPORTS_OBJECT_IDS 0x00010000
#परिभाषय FILE_SUPPORTS_ENCRYPTION 0x00020000
#परिभाषय FILE_NAMED_STREAMS 0x00040000
#परिभाषय FILE_READ_ONLY_VOLUME 0x00080000

    प्रकारनिर्देश संरचना _FILE_NOTIFY_INFORMATION {
      DWORD अग्र_प्रविष्टिः_विस्थापनम्;
      DWORD Action;
      DWORD File_Name_दीर्घता;
      WCHAR FileName[1];
    } FILE_NOTIFY_INFORMATION,*PFILE_NOTIFY_INFORMATION;

    प्रकारनिर्देश सङ्घ _FILE_SEGMENT_ELEMENT {
      PVOID64 बफर_3;
      ULONGLONG Alignment;
    }FILE_SEGMENT_ELEMENT,*PFILE_SEGMENT_ELEMENT;

    प्रकारनिर्देश संरचना REPARSE_GUID_दत्त_बफर {
      DWORD Reparse_चिह्नकम्;
      WORD Reparse_दत्त_दीर्घता;
      WORD Reserved;
      GUID ReparseGuid;
      संरचना {
	BYTE दत्त_बफर[1];
      } Generic_Reparse_बफर;
    } REPARSE_GUID_दत्त_बफर_2,*PREPARSE_GUID_दत्त_बफर;

#परिभाषय REPARSE_GUID_दत्त_बफर_शीर्षकम्_आकार क्षेत्रम्_विस्थापनम्(REPARSE_GUID_दत्त_बफर_2,Generic_Reparse_बफर)

#परिभाषय अधिकतमम्_REPARSE_दत्त_बफर_आकार (16 *1024)

#परिभाषय IO_REPARSE_चिह्नकम्_RESERVED_ZERO (0)
#परिभाषय IO_REPARSE_चिह्नकम्_RESERVED_ONE (1)

#परिभाषय IO_REPARSE_चिह्नकम्_RESERVED_RANGE IO_REPARSE_चिह्नकम्_RESERVED_ONE

#परिभाषय Is_Reparse_चिह्नकम्_Microsoft(चिह्नकम्_2) (((चिह्नकम्_2) & 0x80000000))
#परिभाषय Is_Reparse_चिह्नकम्_Name_Surrogate(चिह्नकम्_2) (((चिह्नकम्_2) & 0x20000000))

#परिभाषय IO_REPARSE_चिह्नकम्_MOUNT_POINT (0xA0000003L)
#परिभाषय IO_REPARSE_चिह्नकम्_HSM (0xC0000004L)
#परिभाषय IO_REPARSE_चिह्नकम्_SIS (0x80000007L)
#परिभाषय IO_REPARSE_चिह्नकम्_DFS (0x8000000AL)
#परिभाषय IO_REPARSE_चिह्नकम्_FILTER_MANAGER (0x8000000BL)
#परिभाषय IO_COMPLETION_MODIFY_STATE 0x0002
#परिभाषय IO_COMPLETION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SYNCHRONIZE|0x3)
#परिभाषय DUPLICATE_CLOSE_SOURCE 0x00000001
#परिभाषय DUPLICATE_SAME_ACCESS 0x00000002

    प्रकारनिर्देश गणना _SYSTEM_POWER_STATE {
      PowerSystemUnspecified = 0,PowerSystemWorking = 1,PowerSystemSleeping1 = 2,PowerSystemSleeping2 = 3,PowerSystemSleeping3 = 4,PowerSystemHibernate = 5,PowerSystemShutdown = 6,Power_System_अधिकतमम् = 7
    } SYSTEM_POWER_STATE,*PSYSTEM_POWER_STATE;

#परिभाषय POWER_SYSTEM_अधिकतमम् 7

    प्रकारनिर्देश गणना {
      PowerActionNone = 0,PowerActionReserved,PowerActionSleep,PowerActionHibernate,PowerActionShutdown,PowerActionShutdownReset,PowerActionShutdownOff,PowerActionWarmEject
    } POWER_ACTION,*PPOWER_ACTION;

    प्रकारनिर्देश गणना _DEVICE_POWER_STATE {
      PowerDeviceUnspecified = 0,PowerDeviceD0,PowerDeviceD1,PowerDeviceD2,PowerDeviceD3,Power_Device_अधिकतमम्
    } DEVICE_POWER_STATE,*PDEVICE_POWER_STATE;

#परिभाषय ES_SYSTEM_REQUIRED ((DWORD)0x00000001)
#परिभाषय ES_DISPLAY_REQUIRED ((DWORD)0x00000002)
#परिभाषय ES_USER_PRESENT ((DWORD)0x00000004)
#परिभाषय ES_CONTINUOUS ((DWORD)0x80000000)

    प्रकारनिर्देश DWORD EXECUTION_STATE;

    प्रकारनिर्देश गणना {
      LT_DONT_CARE,LT_निम्नतमम्_LATENCY
    } LATENCY_TIME;

#परिभाषय PDCAP_D0_SUPPORTED 0x00000001
#परिभाषय PDCAP_D1_SUPPORTED 0x00000002
#परिभाषय PDCAP_D2_SUPPORTED 0x00000004
#परिभाषय PDCAP_D3_SUPPORTED 0x00000008
#परिभाषय PDCAP_WAKE_FROM_D0_SUPPORTED 0x00000010
#परिभाषय PDCAP_WAKE_FROM_D1_SUPPORTED 0x00000020
#परिभाषय PDCAP_WAKE_FROM_D2_SUPPORTED 0x00000040
#परिभाषय PDCAP_WAKE_FROM_D3_SUPPORTED 0x00000080
#परिभाषय PDCAP_WARM_EJECT_SUPPORTED 0x00000100

    प्रकारनिर्देश संरचना CM_Power_दत्त_s {
      DWORD PD_आकार;
      DEVICE_POWER_STATE PD_MostRecentPowerState;
      DWORD PD_Capabilities;
      DWORD PD_D1Latency;
      DWORD PD_D2Latency;
      DWORD PD_D3Latency;
      DEVICE_POWER_STATE PD_PowerStateMapping[POWER_SYSTEM_अधिकतमम्];
      SYSTEM_POWER_STATE PD_गभीरतमम्_System_Wake;
    } CM_POWER_दत्त,*PCM_POWER_दत्त;

    प्रकारनिर्देश गणना {
      SystemPowerPolicyAc,SystemPowerPolicyDc,VerifySystemPolicyAc,VerifySystemPolicyDc,SystemPowerCapabilities,SystemBatteryState,SystemPowerStateHandler,ProcessorStateHandler,SystemPowerPolicyCurrent,AdministratorPowerPolicy,SystemReserveHiberFile,ProcessorInformation,SystemPowerInformation,ProcessorStateHandler2,चरमः_Wake_Time,चरमः_Sleep_Time,SystemExecutionState,SystemPowerStateNotifyHandler,ProcessorPowerPolicyAc,ProcessorPowerPolicyDc,VerifyProcessorPowerPolicyAc,VerifyProcessorPowerPolicyDc,ProcessorPowerPolicyCurrent,SystemPowerStateLogging,System_Power_Logging_प्रविष्टिः
    } POWER_INFORMATION_LEVEL;

    प्रकारनिर्देश संरचना {
      DWORD Granularity;
      DWORD क्षमता;
    } BATTERY_REPORTING_SCALE,*PBATTERY_REPORTING_SCALE;

    प्रकारनिर्देश संरचना {
      POWER_ACTION Action;
      DWORD Flags;
      DWORD Event_संहिता;
    } POWER_ACTION_POLICY,*PPOWER_ACTION_POLICY;

#परिभाषय POWER_ACTION_QUERY_ALLOWED 0x00000001
#परिभाषय POWER_ACTION_UI_ALLOWED 0x00000002
#परिभाषय POWER_ACTION_OVERRIDE_APPS 0x00000004
#परिभाषय POWER_ACTION_LIGHTEST_FIRST 0x10000000
#परिभाषय POWER_ACTION_तालकम्_CONSOLE 0x20000000
#परिभाषय POWER_ACTION_DISABLE_WAKES 0x40000000
#परिभाषय POWER_ACTION_CRITICAL 0x80000000

#परिभाषय POWER_LEVEL_USER_NOTIFY_TEXT 0x00000001
#परिभाषय POWER_LEVEL_USER_NOTIFY_SOUND 0x00000002
#परिभाषय POWER_LEVEL_USER_NOTIFY_EXEC 0x00000004
#परिभाषय POWER_USER_NOTIFY_BUTTON 0x00000008
#परिभाषय POWER_USER_NOTIFY_SHUTDOWN 0x00000010
#परिभाषय POWER_FORCE_TRIGGER_RESET 0x80000000

    प्रकारनिर्देश संरचना {
      BOOLEAN Enable;
      BYTE अतिरिक्तः_2[3];
      DWORD BatteryLevel;
      POWER_ACTION_POLICY PowerPolicy;
      SYSTEM_POWER_STATE MinSystemState;
    } SYSTEM_POWER_LEVEL,*PSYSTEM_POWER_LEVEL;

#परिभाषय अङ्कः_DISCHARGE_POLICIES 4
#परिभाषय DISCHARGE_POLICY_CRITICAL 0
#परिभाषय DISCHARGE_POLICY_नीचः 1

#परिभाषय PO_THROTTLE_NONE 0
#परिभाषय PO_THROTTLE_CONSTANT 1
#परिभाषय PO_THROTTLE_DEGRADE 2
#परिभाषय PO_THROTTLE_ADAPTIVE 3
#परिभाषय PO_THROTTLE_अधिकतमम् 4

    प्रकारनिर्देश संरचना _SYSTEM_POWER_POLICY {
      DWORD Revision;
      POWER_ACTION_POLICY PowerButton;
      POWER_ACTION_POLICY SleepButton;
      POWER_ACTION_POLICY LidClose;
      SYSTEM_POWER_STATE LidOpenWake;
      DWORD Reserved;
      POWER_ACTION_POLICY Idle;
      DWORD IdleTimeout;
      BYTE Idle_संवेदनशीलता;
      BYTE DynamicThrottle;
      BYTE Spare2[2];
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      SYSTEM_POWER_STATE ReducedLatencySleep;
      DWORD WinLogonFlags;
      DWORD Spare3;
      DWORD DozeS4Timeout;
      DWORD प्रसारणम्_क्षमता_Resolution;
      SYSTEM_POWER_LEVEL DischargePolicy[अङ्कः_DISCHARGE_POLICIES];
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

    प्रकारनिर्देश संरचना _PROCESSOR_POWER_POLICY_INFO {
      DWORD TimeCheck;
      DWORD Demote_सीमा;
      DWORD Promote_सीमा;
      BYTE DemotePercent;
      BYTE PromotePercent;
      BYTE अतिरिक्तः_2[2];
      DWORD AllowDemotion:1;
      DWORD AllowPromotion:1;
      DWORD Reserved:30;
    } PROCESSOR_POWER_POLICY_INFO,*PPROCESSOR_POWER_POLICY_INFO;

    प्रकारनिर्देश संरचना _PROCESSOR_POWER_POLICY {
      DWORD Revision;
      BYTE DynamicThrottle;
      BYTE अतिरिक्तः_2[3];
      DWORD DisableCStates:1;
      DWORD Reserved:31;
      DWORD Policy_गणनम्;
      PROCESSOR_POWER_POLICY_INFO Policy[3];
    } PROCESSOR_POWER_POLICY,*PPROCESSOR_POWER_POLICY;

    प्रकारनिर्देश संरचना _ADMINISTRATOR_POWER_POLICY {
      SYSTEM_POWER_STATE MinSleep;
      SYSTEM_POWER_STATE MaxSleep;
      DWORD MinVideoTimeout;
      DWORD MaxVideoTimeout;
      DWORD MinSpindownTimeout;
      DWORD MaxSpindownTimeout;
    } ADMINISTRATOR_POWER_POLICY,*PADMINISTRATOR_POWER_POLICY;

    प्रकारनिर्देश संरचना {
      BOOLEAN PowerButtonPresent;
      BOOLEAN SleepButtonPresent;
      BOOLEAN LidPresent;
      BOOLEAN SystemS1;
      BOOLEAN SystemS2;
      BOOLEAN SystemS3;
      BOOLEAN SystemS4;
      BOOLEAN SystemS5;
      BOOLEAN HiberFilePresent;
      BOOLEAN पूर्णम्_Wake;
      BOOLEAN VideoDimPresent;
      BOOLEAN ApmPresent;
      BOOLEAN UpsPresent;
      BOOLEAN ThermalControl;
      BOOLEAN ProcessorThrottle;
      BYTE ProcessorMinThrottle;
      BYTE ProcessorMaxThrottle;
      BYTE spare2[4];
      BOOLEAN Disk_Spin_अधस्तात्;
      BYTE spare3[8];
      BOOLEAN SystemBatteriesPresent;
      BOOLEAN Batteries_Are_Short_पदांशः;
      BATTERY_REPORTING_SCALE BatteryScale[3];
      SYSTEM_POWER_STATE Ac_On_पङ्क्तिः_Wake;
      SYSTEM_POWER_STATE SoftLidWake;
      SYSTEM_POWER_STATE RtcWake;
      SYSTEM_POWER_STATE MinDeviceWakeState;
      SYSTEM_POWER_STATE Default_नीचः_Latency_Wake;
    } SYSTEM_POWER_CAPABILITIES,*PSYSTEM_POWER_CAPABILITIES;

    प्रकारनिर्देश संरचना {
      BOOLEAN Ac_On_पङ्क्तिः;
      BOOLEAN BatteryPresent;
      BOOLEAN Charging;
      BOOLEAN Discharging;
      BOOLEAN Spare1[4];
      DWORD Max_क्षमता;
      DWORD Remaining_क्षमता;
      DWORD दरः;
      DWORD EstimatedTime;
      DWORD DefaultAlert1;
      DWORD DefaultAlert2;
    } SYSTEM_BATTERY_STATE,*PSYSTEM_BATTERY_STATE;

#अन्तर्भाव "pshpack4.h"

#परिभाषय IMAGE_DOS_SIGNATURE 0x5A4D
#परिभाषय IMAGE_OS2_SIGNATURE 0x454E
#परिभाषय IMAGE_OS2_SIGNATURE_LE 0x454C
#परिभाषय IMAGE_VXD_SIGNATURE 0x454C
#परिभाषय IMAGE_NT_SIGNATURE 0x00004550

#अन्तर्भाव "pshpack2.h"

    प्रकारनिर्देश संरचना IMAGE_DOS_शीर्षकम् {
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
    } IMAGE_DOS_शीर्षकम्_2,*PIMAGE_DOS_शीर्षकम्;

    प्रकारनिर्देश संरचना IMAGE_OS2_शीर्षकम् {
      WORD ne_magic;
      CHAR ne_ver;
      CHAR ne_rev;
      WORD ne_enttab;
      WORD ne_cbenttab;
      LONG ne_crc;
      WORD ne_flags;
      WORD ne_autodata;
      WORD ne_heap;
      WORD ne_राशिः;
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
    } IMAGE_OS2_शीर्षकम्_2,*PIMAGE_OS2_शीर्षकम्;

    प्रकारनिर्देश संरचना IMAGE_VXD_शीर्षकम् {
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
    } IMAGE_VXD_शीर्षकम्_2,*PIMAGE_VXD_शीर्षकम्;

#अन्तर्भाव "poppack.h"

    प्रकारनिर्देश संरचना IMAGE_FILE_शीर्षकम् {
      WORD Machine;
      WORD सङ्ख्या_सम्बन्धि_Sections;
      DWORD TimeDateStamp;
      DWORD Pointer_गन्तव्यम्_चिह्नम्_सारणी;
      DWORD सङ्ख्या_सम्बन्धि_Symbols;
      WORD आकार_सम्बन्धि_Optional_शीर्षकम्;
      WORD Characteristics;
    } IMAGE_FILE_शीर्षकम्_2,*PIMAGE_FILE_शीर्षकम्;

#परिभाषय IMAGE_SIZEOF_FILE_शीर्षकम् 20

#परिभाषय IMAGE_FILE_RELOCS_STRIPPED 0x0001
#परिभाषय IMAGE_FILE_EXECUTABLE_IMAGE 0x0002
#परिभाषय IMAGE_FILE_पङ्क्तिः_NUMS_STRIPPED 0x0004
#परिभाषय IMAGE_FILE_LOCAL_SYMS_STRIPPED 0x0008
#परिभाषय IMAGE_FILE_AGGRESIVE_WS_TRIM 0x0010
#परिभाषय IMAGE_FILE_LARGE_स्थानाङ्कः_AWARE 0x0020
#परिभाषय IMAGE_FILE_अष्टकानि_REVERSED_LO 0x0080
#परिभाषय IMAGE_FILE_32BIT_MACHINE 0x0100
#परिभाषय IMAGE_FILE_DEBUG_STRIPPED 0x0200
#परिभाषय IMAGE_FILE_REMOVABLE_सततम्_FROM_SWAP 0x0400
#परिभाषय IMAGE_FILE_NET_सततम्_FROM_SWAP 0x0800
#परिभाषय IMAGE_FILE_SYSTEM 0x1000
#परिभाषय IMAGE_FILE_DLL 0x2000
#परिभाषय IMAGE_FILE_ऊर्ध्वम्_SYSTEM_ONLY 0x4000
#परिभाषय IMAGE_FILE_अष्टकानि_REVERSED_HI 0x8000

#परिभाषय IMAGE_FILE_MACHINE_UNKNOWN 0
#परिभाषय IMAGE_FILE_MACHINE_I386 0x014c
#परिभाषय IMAGE_FILE_MACHINE_R3000 0x0162
#परिभाषय IMAGE_FILE_MACHINE_R4000 0x0166
#परिभाषय IMAGE_FILE_MACHINE_R10000 0x0168
#परिभाषय IMAGE_FILE_MACHINE_WCEMIPSV2 0x0169
#परिभाषय IMAGE_FILE_MACHINE_ALPHA 0x0184
#परिभाषय IMAGE_FILE_MACHINE_SH3 0x01a2
#परिभाषय IMAGE_FILE_MACHINE_SH3DSP 0x01a3
#परिभाषय IMAGE_FILE_MACHINE_SH3E 0x01a4
#परिभाषय IMAGE_FILE_MACHINE_SH4 0x01a6
#परिभाषय IMAGE_FILE_MACHINE_SH5 0x01a8
#परिभाषय IMAGE_FILE_MACHINE_ARM 0x01c0
#परिभाषय IMAGE_FILE_MACHINE_THUMB 0x01c2
#परिभाषय IMAGE_FILE_MACHINE_AM33 0x01d3
#परिभाषय IMAGE_FILE_MACHINE_POWERPC 0x01F0
#परिभाषय IMAGE_FILE_MACHINE_POWERPCFP 0x01f1
#परिभाषय IMAGE_FILE_MACHINE_IA64 0x0200
#परिभाषय IMAGE_FILE_MACHINE_MIPS16 0x0266
#परिभाषय IMAGE_FILE_MACHINE_ALPHA64 0x0284
#परिभाषय IMAGE_FILE_MACHINE_MIPSFPU 0x0366
#परिभाषय IMAGE_FILE_MACHINE_MIPSFPU16 0x0466
#परिभाषय IMAGE_FILE_MACHINE_AXP64 IMAGE_FILE_MACHINE_ALPHA64
#परिभाषय IMAGE_FILE_MACHINE_TRICORE 0x0520
#परिभाषय IMAGE_FILE_MACHINE_CEF 0x0CEF
#परिभाषय IMAGE_FILE_MACHINE_EBC 0x0EBC
#परिभाषय IMAGE_FILE_MACHINE_AMD64 0x8664
#परिभाषय IMAGE_FILE_MACHINE_ARM64 0xAA64
#परिभाषय IMAGE_FILE_MACHINE_M32R 0x9041
#परिभाषय IMAGE_FILE_MACHINE_CEE 0xC0EE

    प्रकारनिर्देश संरचना IMAGE_दत्त_DIRECTORY {
      DWORD Virtual_स्थानाङ्कः;
      DWORD आकार_3;
    } IMAGE_दत्त_DIRECTORY_2,*PIMAGE_दत्त_DIRECTORY;

#परिभाषय IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16

    प्रकारनिर्देश संरचना IMAGE_OPTIONAL_शीर्षकम् {

      WORD Magic;
      BYTE Major_Linker_संस्करणम्;
      BYTE Minor_Linker_संस्करणम्;
      DWORD आकार_सम्बन्धि_संहिता;
      DWORD आकार_सम्बन्धि_Initialized_दत्त;
      DWORD आकार_सम्बन्धि_Uninitialized_दत्त;
      DWORD स्थानाङ्कः_सम्बन्धि_प्रविष्टिः_Point;
      DWORD आधारः_सम्बन्धि_संहिता;
      DWORD आधारः_सम्बन्धि_दत्त;
      DWORD Image_आधारः;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      WORD Major_Operating_System_संस्करणम्;
      WORD Minor_Operating_System_संस्करणम्;
      WORD Major_Image_संस्करणम्;
      WORD Minor_Image_संस्करणम्;
      WORD Major_Subsystem_संस्करणम्;
      WORD Minor_Subsystem_संस्करणम्;
      DWORD Win32_संस्करणम्_मानम्;
      DWORD आकार_सम्बन्धि_Image;
      DWORD आकार_सम्बन्धि_शीर्षकाणि;
      DWORD Check_योग;
      WORD Subsystem;
      WORD DllCharacteristics;
      DWORD आकार_सम्बन्धि_राशिः_Reserve;
      DWORD आकार_सम्बन्धि_राशिः_Commit;
      DWORD आकार_सम्बन्धि_Heap_Reserve;
      DWORD आकार_सम्बन्धि_Heap_Commit;
      DWORD LoaderFlags;
      DWORD सङ्ख्या_सम्बन्धि_Rva_And_Sizes;
      IMAGE_दत्त_DIRECTORY_2 दत्त_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32,*PIMAGE_OPTIONAL_HEADER32;

    प्रकारनिर्देश संरचना IMAGE_ROM_OPTIONAL_शीर्षकम् {
      WORD Magic;
      BYTE Major_Linker_संस्करणम्;
      BYTE Minor_Linker_संस्करणम्;
      DWORD आकार_सम्बन्धि_संहिता;
      DWORD आकार_सम्बन्धि_Initialized_दत्त;
      DWORD आकार_सम्बन्धि_Uninitialized_दत्त;
      DWORD स्थानाङ्कः_सम्बन्धि_प्रविष्टिः_Point;
      DWORD आधारः_सम्बन्धि_संहिता;
      DWORD आधारः_सम्बन्धि_दत्त;
      DWORD आधारः_सम्बन्धि_Bss;
      DWORD Gpr_आवरणम्;
      DWORD Cpr_आवरणम्[4];
      DWORD Gp_मानम्;
    } IMAGE_ROM_OPTIONAL_शीर्षकम्_2,*PIMAGE_ROM_OPTIONAL_शीर्षकम्;

    प्रकारनिर्देश संरचना _IMAGE_OPTIONAL_HEADER64 {
      WORD Magic;
      BYTE Major_Linker_संस्करणम्;
      BYTE Minor_Linker_संस्करणम्;
      DWORD आकार_सम्बन्धि_संहिता;
      DWORD आकार_सम्बन्धि_Initialized_दत्त;
      DWORD आकार_सम्बन्धि_Uninitialized_दत्त;
      DWORD स्थानाङ्कः_सम्बन्धि_प्रविष्टिः_Point;
      DWORD आधारः_सम्बन्धि_संहिता;
      ULONGLONG Image_आधारः;
      DWORD SectionAlignment;
      DWORD FileAlignment;
      WORD Major_Operating_System_संस्करणम्;
      WORD Minor_Operating_System_संस्करणम्;
      WORD Major_Image_संस्करणम्;
      WORD Minor_Image_संस्करणम्;
      WORD Major_Subsystem_संस्करणम्;
      WORD Minor_Subsystem_संस्करणम्;
      DWORD Win32_संस्करणम्_मानम्;
      DWORD आकार_सम्बन्धि_Image;
      DWORD आकार_सम्बन्धि_शीर्षकाणि;
      DWORD Check_योग;
      WORD Subsystem;
      WORD DllCharacteristics;
      ULONGLONG आकार_सम्बन्धि_राशिः_Reserve;
      ULONGLONG आकार_सम्बन्धि_राशिः_Commit;
      ULONGLONG आकार_सम्बन्धि_Heap_Reserve;
      ULONGLONG आकार_सम्बन्धि_Heap_Commit;
      DWORD LoaderFlags;
      DWORD सङ्ख्या_सम्बन्धि_Rva_And_Sizes;
      IMAGE_दत्त_DIRECTORY_2 दत्त_Directory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER64,*PIMAGE_OPTIONAL_HEADER64;

#परिभाषय IMAGE_SIZEOF_ROM_OPTIONAL_शीर्षकम् 56
#परिभाषय IMAGE_SIZEOF_STD_OPTIONAL_शीर्षकम् 28
#परिभाषय IMAGE_SIZEOF_NT_OPTIONAL32_शीर्षकम् 224
#परिभाषय IMAGE_SIZEOF_NT_OPTIONAL64_शीर्षकम् 240

#परिभाषय IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#परिभाषय IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b
#परिभाषय IMAGE_ROM_OPTIONAL_HDR_MAGIC 0x107

#यदि_परिभाषितम् _WIN64
    प्रकारनिर्देश IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_शीर्षकम्_2;
    प्रकारनिर्देश PIMAGE_OPTIONAL_HEADER64 PIMAGE_OPTIONAL_शीर्षकम्;
#परिभाषय IMAGE_SIZEOF_NT_OPTIONAL_शीर्षकम् IMAGE_SIZEOF_NT_OPTIONAL64_शीर्षकम्
#परिभाषय IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR64_MAGIC
#अन्यथा
    प्रकारनिर्देश IMAGE_OPTIONAL_HEADER32 IMAGE_OPTIONAL_शीर्षकम्_2;
    प्रकारनिर्देश PIMAGE_OPTIONAL_HEADER32 PIMAGE_OPTIONAL_शीर्षकम्;
#परिभाषय IMAGE_SIZEOF_NT_OPTIONAL_शीर्षकम् IMAGE_SIZEOF_NT_OPTIONAL32_शीर्षकम्
#परिभाषय IMAGE_NT_OPTIONAL_HDR_MAGIC IMAGE_NT_OPTIONAL_HDR32_MAGIC
#यदि_अन्तः

    प्रकारनिर्देश संरचना _IMAGE_NT_HEADERS64 {
      DWORD Signature;
      IMAGE_FILE_शीर्षकम्_2 File_शीर्षकम्;
      IMAGE_OPTIONAL_HEADER64 Optional_शीर्षकम्;
    } IMAGE_NT_HEADERS64,*PIMAGE_NT_HEADERS64;

    प्रकारनिर्देश संरचना IMAGE_NT_शीर्षकाणि {
      DWORD Signature;
      IMAGE_FILE_शीर्षकम्_2 File_शीर्षकम्;
      IMAGE_OPTIONAL_HEADER32 Optional_शीर्षकम्;
    } IMAGE_NT_HEADERS32,*PIMAGE_NT_HEADERS32;

    प्रकारनिर्देश संरचना IMAGE_ROM_शीर्षकाणि {
      IMAGE_FILE_शीर्षकम्_2 File_शीर्षकम्;
      IMAGE_ROM_OPTIONAL_शीर्षकम्_2 Optional_शीर्षकम्;
    } IMAGE_ROM_शीर्षकाणि_2,*PIMAGE_ROM_शीर्षकाणि;

#यदि_परिभाषितम् _WIN64
    प्रकारनिर्देश IMAGE_NT_HEADERS64 IMAGE_NT_शीर्षकाणि_2;
    प्रकारनिर्देश PIMAGE_NT_HEADERS64 PIMAGE_NT_शीर्षकाणि;
#अन्यथा
    प्रकारनिर्देश IMAGE_NT_HEADERS32 IMAGE_NT_शीर्षकाणि_2;
    प्रकारनिर्देश PIMAGE_NT_HEADERS32 PIMAGE_NT_शीर्षकाणि;
#यदि_अन्तः

#परिभाषय IMAGE_FIRST_SECTION(ntheader) ((PIMAGE_SECTION_शीर्षकम्) ((ULONG_PTR)ntheader + क्षेत्रम्_विस्थापनम्(IMAGE_NT_शीर्षकाणि_2,Optional_शीर्षकम्) + ((PIMAGE_NT_शीर्षकाणि)(ntheader))->File_शीर्षकम्.आकार_सम्बन्धि_Optional_शीर्षकम्))

#परिभाषय IMAGE_SUBSYSTEM_UNKNOWN 0
#परिभाषय IMAGE_SUBSYSTEM_NATIVE 1
#परिभाषय IMAGE_SUBSYSTEM_WINDOWS_GUI 2
#परिभाषय IMAGE_SUBSYSTEM_WINDOWS_CUI 3
#परिभाषय IMAGE_SUBSYSTEM_OS2_CUI 5
#परिभाषय IMAGE_SUBSYSTEM_POSIX_CUI 7
#परिभाषय IMAGE_SUBSYSTEM_NATIVE_WINDOWS 8
#परिभाषय IMAGE_SUBSYSTEM_WINDOWS_CE_GUI 9
#परिभाषय IMAGE_SUBSYSTEM_EFI_APPLICATION 10
#परिभाषय IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#परिभाषय IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER 12
#परिभाषय IMAGE_SUBSYSTEM_EFI_ROM 13
#परिभाषय IMAGE_SUBSYSTEM_XBOX 14

#परिभाषय IMAGE_DLLCHARACTERISTICS_उच्चः_ENTROPY_VA 0x0020
#परिभाषय IMAGE_DLLCHARACTERISTICS_DYNAMIC_आधारः 0x0040
#परिभाषय IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY 0x0080
#परिभाषय IMAGE_DLLCHARACTERISTICS_NX_COMPAT 0x0100
#परिभाषय IMAGE_DLLCHARACTERISTICS_NO_ISOLATION 0x0200
#परिभाषय IMAGE_DLLCHARACTERISTICS_NO_SEH 0x0400
#परिभाषय IMAGE_DLLCHARACTERISTICS_NO_BIND 0x0800
#परिभाषय IMAGE_DLLCHARACTERISTICS_APPCONTAINER 0x1000
#परिभाषय IMAGE_DLLCHARACTERISTICS_WDM_DRIVER 0x2000
#परिभाषय IMAGE_DLLCHARACTERISTICS_GUARD_CF 0x4000
#परिभाषय IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_EXPORT 0
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_IMPORT 1
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_RESOURCE 2
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_EXCEPTION 3
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_SECURITY 4
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_BASERELOC 5
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_DEBUG 6

#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_ARCHITECTURE 7
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_GLOBALPTR 8
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_TLS 9
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_आरोपय_CONFIG 10
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_BOUND_IMPORT 11
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_IAT 12
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_DELAY_IMPORT 13
#परिभाषय IMAGE_DIRECTORY_प्रविष्टिः_COM_DESCRIPTOR 14

    प्रकारनिर्देश संरचना ANON_OBJECT_शीर्षकम् {
      WORD Sig1;
      WORD Sig2;
      WORD संस्करणम्_2;
      WORD Machine;
      DWORD TimeDateStamp;
      CLSID ClassID;
      DWORD आकार_सम्बन्धि_दत्त;
    } ANON_OBJECT_शीर्षकम्;

#परिभाषय IMAGE_SIZEOF_SHORT_NAME 8

    प्रकारनिर्देश संरचना IMAGE_SECTION_शीर्षकम् {
      BYTE Name[IMAGE_SIZEOF_SHORT_NAME];
      सङ्घ {
	DWORD Physical_स्थानाङ्कः;
	DWORD Virtual_आकार;
      } Misc;
      DWORD Virtual_स्थानाङ्कः;
      DWORD आकार_सम्बन्धि_Raw_दत्त;
      DWORD Pointer_गन्तव्यम्_Raw_दत्त;
      DWORD Pointer_गन्तव्यम्_Relocations;
      DWORD Pointer_गन्तव्यम्_Linenumbers;
      WORD सङ्ख्या_सम्बन्धि_Relocations;
      WORD सङ्ख्या_सम्बन्धि_Linenumbers;
      DWORD Characteristics;
    } IMAGE_SECTION_शीर्षकम्_2,*PIMAGE_SECTION_शीर्षकम्;

#परिभाषय IMAGE_SIZEOF_SECTION_शीर्षकम् 40

#परिभाषय IMAGE_SCN_TYPE_NO_PAD 0x00000008

#परिभाषय IMAGE_SCN_CNT_संहिता 0x00000020
#परिभाषय IMAGE_SCN_CNT_INITIALIZED_दत्त 0x00000040
#परिभाषय IMAGE_SCN_CNT_UNINITIALIZED_दत्त 0x00000080
#परिभाषय IMAGE_SCN_LNK_OTHER 0x00000100
#परिभाषय IMAGE_SCN_LNK_INFO 0x00000200
#परिभाषय IMAGE_SCN_LNK_REMOVE 0x00000800
#परिभाषय IMAGE_SCN_LNK_COMDAT 0x00001000
#परिभाषय IMAGE_SCN_NO_DEFER_SPEC_EXC 0x00004000
#परिभाषय IMAGE_SCN_GPREL 0x00008000
#परिभाषय IMAGE_SCN_MEM_FARDATA 0x00008000
#परिभाषय IMAGE_SCN_MEM_PURGEABLE 0x00020000
#परिभाषय IMAGE_SCN_MEM_16BIT 0x00020000
#परिभाषय IMAGE_SCN_MEM_LOCKED 0x00040000
#परिभाषय IMAGE_SCN_MEM_PRELOAD 0x00080000

#परिभाषय IMAGE_SCN_ALIGN_1_अष्टकानि 0x00100000
#परिभाषय IMAGE_SCN_ALIGN_2_अष्टकानि 0x00200000
#परिभाषय IMAGE_SCN_ALIGN_4_अष्टकानि 0x00300000
#परिभाषय IMAGE_SCN_ALIGN_8_अष्टकानि 0x00400000
#परिभाषय IMAGE_SCN_ALIGN_16_अष्टकानि 0x00500000
#परिभाषय IMAGE_SCN_ALIGN_32_अष्टकानि 0x00600000
#परिभाषय IMAGE_SCN_ALIGN_64_अष्टकानि 0x00700000
#परिभाषय IMAGE_SCN_ALIGN_128_अष्टकानि 0x00800000
#परिभाषय IMAGE_SCN_ALIGN_256_अष्टकानि 0x00900000
#परिभाषय IMAGE_SCN_ALIGN_512_अष्टकानि 0x00A00000
#परिभाषय IMAGE_SCN_ALIGN_1024_अष्टकानि 0x00B00000
#परिभाषय IMAGE_SCN_ALIGN_2048_अष्टकानि 0x00C00000
#परिभाषय IMAGE_SCN_ALIGN_4096_अष्टकानि 0x00D00000
#परिभाषय IMAGE_SCN_ALIGN_8192_अष्टकानि 0x00E00000

#परिभाषय IMAGE_SCN_ALIGN_आवरणम् 0x00F00000

#परिभाषय IMAGE_SCN_LNK_NRELOC_OVFL 0x01000000
#परिभाषय IMAGE_SCN_MEM_DISCARDABLE 0x02000000
#परिभाषय IMAGE_SCN_MEM_NOT_CACHED 0x04000000
#परिभाषय IMAGE_SCN_MEM_NOT_PAGED 0x08000000
#परिभाषय IMAGE_SCN_MEM_SHARED 0x10000000
#परिभाषय IMAGE_SCN_MEM_EXECUTE 0x20000000
#परिभाषय IMAGE_SCN_MEM_READ 0x40000000
#परिभाषय IMAGE_SCN_MEM_WRITE 0x80000000

#परिभाषय IMAGE_SCN_SCALE_सूचकांक 0x00000001

#अन्तर्भाव "pshpack2.h"

    प्रकारनिर्देश संरचना IMAGE_चिह्नम् {
      सङ्घ {
	BYTE ShortName[8];
	संरचना {
	  DWORD Short;
	  DWORD Long;
	} Name;
	DWORD LongName[2];
      } N;
      DWORD मानम्_3;
      SHORT Section_सङ्ख्या;
      WORD Type;
      BYTE StorageClass;
      BYTE सङ्ख्या_सम्बन्धि_Aux_Symbols;
    } IMAGE_चिह्नम्_2;
    प्रकारनिर्देश IMAGE_चिह्नम्_2 UNALIGNED *PIMAGE_चिह्नम्;

#परिभाषय IMAGE_SIZEOF_चिह्नम् 18

#परिभाषय IMAGE_SYM_UNDEFINED (SHORT)0
#परिभाषय IMAGE_SYM_ABSOLUTE (SHORT)-1
#परिभाषय IMAGE_SYM_DEBUG (SHORT)-2
#परिभाषय IMAGE_SYM_SECTION_MAX 0xFEFF

#परिभाषय IMAGE_SYM_TYPE_NULL 0x0000
#परिभाषय IMAGE_SYM_TYPE_VOID 0x0001
#परिभाषय IMAGE_SYM_TYPE_CHAR 0x0002
#परिभाषय IMAGE_SYM_TYPE_SHORT 0x0003
#परिभाषय IMAGE_SYM_TYPE_INT 0x0004
#परिभाषय IMAGE_SYM_TYPE_LONG 0x0005
#परिभाषय IMAGE_SYM_TYPE_FLOAT 0x0006
#परिभाषय IMAGE_SYM_TYPE_DOUBLE 0x0007
#परिभाषय IMAGE_SYM_TYPE_STRUCT 0x0008
#परिभाषय IMAGE_SYM_TYPE_UNION 0x0009
#परिभाषय IMAGE_SYM_TYPE_ENUM 0x000A
#परिभाषय IMAGE_SYM_TYPE_MOE 0x000B
#परिभाषय IMAGE_SYM_TYPE_BYTE 0x000C
#परिभाषय IMAGE_SYM_TYPE_WORD 0x000D
#परिभाषय IMAGE_SYM_TYPE_UINT 0x000E
#परिभाषय IMAGE_SYM_TYPE_DWORD 0x000F
#परिभाषय IMAGE_SYM_TYPE_PCODE 0x8000

#परिभाषय IMAGE_SYM_DTYPE_NULL 0
#परिभाषय IMAGE_SYM_DTYPE_POINTER 1
#परिभाषय IMAGE_SYM_DTYPE_FUNCTION 2
#परिभाषय IMAGE_SYM_DTYPE_ARRAY 3

#परिभाषय IMAGE_SYM_CLASS_अन्तः_सम्बन्धि_FUNCTION (BYTE)-1
#परिभाषय IMAGE_SYM_CLASS_NULL 0x0000
#परिभाषय IMAGE_SYM_CLASS_AUTOMATIC 0x0001
#परिभाषय IMAGE_SYM_CLASS_EXTERNAL 0x0002
#परिभाषय IMAGE_SYM_CLASS_STATIC 0x0003
#परिभाषय IMAGE_SYM_CLASS_पञ्जिकाकोशः 0x0004
#परिभाषय IMAGE_SYM_CLASS_EXTERNAL_DEF 0x0005
#परिभाषय IMAGE_SYM_CLASS_LABEL 0x0006
#परिभाषय IMAGE_SYM_CLASS_UNDEFINED_LABEL 0x0007
#परिभाषय IMAGE_SYM_CLASS_MEMBER_सम्बन्धि_STRUCT 0x0008
#परिभाषय IMAGE_SYM_CLASS_तर्कः 0x0009
#परिभाषय IMAGE_SYM_CLASS_STRUCT_चिह्नकम् 0x000A
#परिभाषय IMAGE_SYM_CLASS_MEMBER_सम्बन्धि_UNION 0x000B
#परिभाषय IMAGE_SYM_CLASS_UNION_चिह्नकम् 0x000C
#परिभाषय IMAGE_SYM_CLASS_TYPE_DEFINITION 0x000D
#परिभाषय IMAGE_SYM_CLASS_UNDEFINED_STATIC 0x000E
#परिभाषय IMAGE_SYM_CLASS_ENUM_चिह्नकम् 0x000F
#परिभाषय IMAGE_SYM_CLASS_MEMBER_सम्बन्धि_ENUM 0x0010
#परिभाषय IMAGE_SYM_CLASS_पञ्जिकाकोशः_PARAM 0x0011
#परिभाषय IMAGE_SYM_CLASS_BIT_क्षेत्रम् 0x0012
#परिभाषय IMAGE_SYM_CLASS_FAR_EXTERNAL 0x0044
#परिभाषय IMAGE_SYM_CLASS_खण्डम् 0x0064
#परिभाषय IMAGE_SYM_CLASS_FUNCTION 0x0065
#परिभाषय IMAGE_SYM_CLASS_अन्तः_सम्बन्धि_STRUCT 0x0066
#परिभाषय IMAGE_SYM_CLASS_FILE 0x0067
#परिभाषय IMAGE_SYM_CLASS_SECTION 0x0068
#परिभाषय IMAGE_SYM_CLASS_WEAK_EXTERNAL 0x0069
#परिभाषय IMAGE_SYM_CLASS_CLR_TOKEN 0x006B

#परिभाषय N_BTMASK 0x000F
#परिभाषय N_TMASK 0x0030
#परिभाषय N_TMASK1 0x00C0
#परिभाषय N_TMASK2 0x00F0
#परिभाषय N_BTSHFT 4
#परिभाषय N_TSHIFT 2

#परिभाषय BTYPE(x) ((x) & N_BTMASK)

#यदि_अपरिभाषितम् ISPTR
#परिभाषय ISPTR(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_POINTER << N_BTSHFT))
#यदि_अन्तः

#यदि_अपरिभाषितम् ISFCN
#परिभाषय ISFCN(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#यदि_अन्तः

#यदि_अपरिभाषितम् ISARY
#परिभाषय ISARY(x) (((x) & N_TMASK)==(IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#यदि_अन्तः

#यदि_अपरिभाषितम् ISTAG
#परिभाषय ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_चिह्नकम् || (x)==IMAGE_SYM_CLASS_UNION_चिह्नकम् || (x)==IMAGE_SYM_CLASS_ENUM_चिह्नकम्)
#यदि_अन्तः

#यदि_अपरिभाषितम् INCREF
#परिभाषय INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_POINTER<<N_BTSHFT)|((x)&N_BTMASK))
#यदि_अन्तः
#यदि_अपरिभाषितम् DECREF
#परिभाषय DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#यदि_अन्तः

    प्रकारनिर्देश सङ्घ IMAGE_AUX_चिह्नम् {
      संरचना {
	DWORD चिह्नकम्_सूचकांक;
	सङ्घ {
	  संरचना {
	    WORD Linenumber;
	    WORD आकार_3;
	  } LnSz;
	  DWORD योग_आकार;
	} Misc;
	सङ्घ {
	  संरचना {
	    DWORD Pointer_गन्तव्यम्_Linenumber;
	    DWORD Pointer_गन्तव्यम्_अग्र_Function;
	  } Function;
	  संरचना {
	    WORD Dimension[4];
	  } Array;
	} FcnAry;
	WORD Tv_सूचकांक;
      } Sym;
      संरचना {
	BYTE Name[IMAGE_SIZEOF_चिह्नम्];
      } File;
      संरचना {
	DWORD दीर्घता_2;
	WORD सङ्ख्या_सम्बन्धि_Relocations;
	WORD सङ्ख्या_सम्बन्धि_Linenumbers;
	DWORD Check_योग;
	SHORT सङ्ख्या_2;
	BYTE Selection;
      } Section;
    } IMAGE_AUX_चिह्नम्_2;
    प्रकारनिर्देश IMAGE_AUX_चिह्नम्_2 UNALIGNED *PIMAGE_AUX_चिह्नम्;

#परिभाषय IMAGE_SIZEOF_AUX_चिह्नम् 18

    प्रकारनिर्देश गणना IMAGE_AUX_चिह्नम्_TYPE {
      IMAGE_AUX_चिह्नम्_TYPE_TOKEN_DEF = 1
    } IMAGE_AUX_चिह्नम्_TYPE;

#अन्तर्भाव <pshpack2.h>

    प्रकारनिर्देश संरचना IMAGE_AUX_चिह्नम्_TOKEN_DEF {
      BYTE bAuxType;
      BYTE bReserved;
      DWORD चिह्नम्_सारणी_सूचकांक;
      BYTE rgbReserved[12];
    } IMAGE_AUX_चिह्नम्_TOKEN_DEF;

    प्रकारनिर्देश IMAGE_AUX_चिह्नम्_TOKEN_DEF UNALIGNED *PIMAGE_AUX_चिह्नम्_TOKEN_DEF;

#अन्तर्भाव <poppack.h>

#परिभाषय IMAGE_COMDAT_SELECT_NODUPLICATES 1
#परिभाषय IMAGE_COMDAT_SELECT_ANY 2
#परिभाषय IMAGE_COMDAT_SELECT_SAME_आकार 3
#परिभाषय IMAGE_COMDAT_SELECT_EXACT_मेलनम् 4
#परिभाषय IMAGE_COMDAT_SELECT_ASSOCIATIVE 5
#परिभाषय IMAGE_COMDAT_SELECT_LARGEST 6
#परिभाषय IMAGE_COMDAT_SELECT_NEWEST 7

#परिभाषय IMAGE_WEAK_EXTERN_अन्वेषणम्_NOLIBRARY 1
#परिभाषय IMAGE_WEAK_EXTERN_अन्वेषणम्_LIBRARY 2
#परिभाषय IMAGE_WEAK_EXTERN_अन्वेषणम्_ALIAS 3

    प्रकारनिर्देश संरचना _IMAGE_RELOCATION {
      सङ्घ {
	DWORD Virtual_स्थानाङ्कः;
	DWORD Reloc_गणनम्;
      };
      DWORD चिह्नम्_सारणी_सूचकांक;
      WORD Type;
    } IMAGE_RELOCATION;
    प्रकारनिर्देश IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#परिभाषय IMAGE_SIZEOF_RELOCATION 10

#परिभाषय IMAGE_REL_I386_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_I386_DIR16 0x0001
#परिभाषय IMAGE_REL_I386_REL16 0x0002
#परिभाषय IMAGE_REL_I386_DIR32 0x0006
#परिभाषय IMAGE_REL_I386_DIR32NB 0x0007
#परिभाषय IMAGE_REL_I386_SEG12 0x0009
#परिभाषय IMAGE_REL_I386_SECTION 0x000A
#परिभाषय IMAGE_REL_I386_SECREL 0x000B
#परिभाषय IMAGE_REL_I386_TOKEN 0x000C
#परिभाषय IMAGE_REL_I386_SECREL7 0x000D
#परिभाषय IMAGE_REL_I386_REL32 0x0014

#परिभाषय IMAGE_REL_MIPS_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_MIPS_REFHALF 0x0001
#परिभाषय IMAGE_REL_MIPS_REFWORD 0x0002
#परिभाषय IMAGE_REL_MIPS_JMPADDR 0x0003
#परिभाषय IMAGE_REL_MIPS_REFHI 0x0004
#परिभाषय IMAGE_REL_MIPS_REFLO 0x0005
#परिभाषय IMAGE_REL_MIPS_GPREL 0x0006
#परिभाषय IMAGE_REL_MIPS_LITERAL 0x0007
#परिभाषय IMAGE_REL_MIPS_SECTION 0x000A
#परिभाषय IMAGE_REL_MIPS_SECREL 0x000B
#परिभाषय IMAGE_REL_MIPS_SECRELLO 0x000C
#परिभाषय IMAGE_REL_MIPS_SECRELHI 0x000D
#परिभाषय IMAGE_REL_MIPS_TOKEN 0x000E
#परिभाषय IMAGE_REL_MIPS_JMPADDR16 0x0010
#परिभाषय IMAGE_REL_MIPS_REFWORDNB 0x0022
#परिभाषय IMAGE_REL_MIPS_PAIR 0x0025

#परिभाषय IMAGE_REL_ALPHA_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_ALPHA_REFLONG 0x0001
#परिभाषय IMAGE_REL_ALPHA_REFQUAD 0x0002
#परिभाषय IMAGE_REL_ALPHA_GPREL32 0x0003
#परिभाषय IMAGE_REL_ALPHA_LITERAL 0x0004
#परिभाषय IMAGE_REL_ALPHA_LITUSE 0x0005
#परिभाषय IMAGE_REL_ALPHA_GPDISP 0x0006
#परिभाषय IMAGE_REL_ALPHA_BRADDR 0x0007
#परिभाषय IMAGE_REL_ALPHA_HINT 0x0008
#परिभाषय IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#परिभाषय IMAGE_REL_ALPHA_REFHI 0x000A
#परिभाषय IMAGE_REL_ALPHA_REFLO 0x000B
#परिभाषय IMAGE_REL_ALPHA_PAIR 0x000C
#परिभाषय IMAGE_REL_ALPHA_मेलनम् 0x000D
#परिभाषय IMAGE_REL_ALPHA_SECTION 0x000E
#परिभाषय IMAGE_REL_ALPHA_SECREL 0x000F
#परिभाषय IMAGE_REL_ALPHA_REFLONGNB 0x0010
#परिभाषय IMAGE_REL_ALPHA_SECRELLO 0x0011
#परिभाषय IMAGE_REL_ALPHA_SECRELHI 0x0012
#परिभाषय IMAGE_REL_ALPHA_REFQ3 0x0013
#परिभाषय IMAGE_REL_ALPHA_REFQ2 0x0014
#परिभाषय IMAGE_REL_ALPHA_REFQ1 0x0015
#परिभाषय IMAGE_REL_ALPHA_GPRELLO 0x0016
#परिभाषय IMAGE_REL_ALPHA_GPRELHI 0x0017

#परिभाषय IMAGE_REL_PPC_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_PPC_ADDR64 0x0001
#परिभाषय IMAGE_REL_PPC_ADDR32 0x0002
#परिभाषय IMAGE_REL_PPC_ADDR24 0x0003
#परिभाषय IMAGE_REL_PPC_ADDR16 0x0004
#परिभाषय IMAGE_REL_PPC_ADDR14 0x0005
#परिभाषय IMAGE_REL_PPC_REL24 0x0006
#परिभाषय IMAGE_REL_PPC_REL14 0x0007
#परिभाषय IMAGE_REL_PPC_TOCREL16 0x0008
#परिभाषय IMAGE_REL_PPC_TOCREL14 0x0009
#परिभाषय IMAGE_REL_PPC_ADDR32NB 0x000A
#परिभाषय IMAGE_REL_PPC_SECREL 0x000B
#परिभाषय IMAGE_REL_PPC_SECTION 0x000C
#परिभाषय IMAGE_REL_PPC_IFGLUE 0x000D
#परिभाषय IMAGE_REL_PPC_IMGLUE 0x000E
#परिभाषय IMAGE_REL_PPC_SECREL16 0x000F
#परिभाषय IMAGE_REL_PPC_REFHI 0x0010
#परिभाषय IMAGE_REL_PPC_REFLO 0x0011
#परिभाषय IMAGE_REL_PPC_PAIR 0x0012
#परिभाषय IMAGE_REL_PPC_SECRELLO 0x0013
#परिभाषय IMAGE_REL_PPC_SECRELHI 0x0014
#परिभाषय IMAGE_REL_PPC_GPREL 0x0015
#परिभाषय IMAGE_REL_PPC_TOKEN 0x0016
#परिभाषय IMAGE_REL_PPC_TYPEMASK 0x00FF
#परिभाषय IMAGE_REL_PPC_NEG 0x0100
#परिभाषय IMAGE_REL_PPC_BRTAKEN 0x0200
#परिभाषय IMAGE_REL_PPC_BRNTAKEN 0x0400
#परिभाषय IMAGE_REL_PPC_TOCDEFN 0x0800

#परिभाषय IMAGE_REL_SH3_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_SH3_DIRECT16 0x0001
#परिभाषय IMAGE_REL_SH3_DIRECT32 0x0002
#परिभाषय IMAGE_REL_SH3_DIRECT8 0x0003
#परिभाषय IMAGE_REL_SH3_DIRECT8_WORD 0x0004
#परिभाषय IMAGE_REL_SH3_DIRECT8_LONG 0x0005
#परिभाषय IMAGE_REL_SH3_DIRECT4 0x0006
#परिभाषय IMAGE_REL_SH3_DIRECT4_WORD 0x0007
#परिभाषय IMAGE_REL_SH3_DIRECT4_LONG 0x0008
#परिभाषय IMAGE_REL_SH3_PCREL8_WORD 0x0009
#परिभाषय IMAGE_REL_SH3_PCREL8_LONG 0x000A
#परिभाषय IMAGE_REL_SH3_PCREL12_WORD 0x000B
#परिभाषय IMAGE_REL_SH3_STARTOF_SECTION 0x000C
#परिभाषय IMAGE_REL_SH3_SIZEOF_SECTION 0x000D
#परिभाषय IMAGE_REL_SH3_SECTION 0x000E
#परिभाषय IMAGE_REL_SH3_SECREL 0x000F
#परिभाषय IMAGE_REL_SH3_DIRECT32_NB 0x0010
#परिभाषय IMAGE_REL_SH3_GPREL4_LONG 0x0011
#परिभाषय IMAGE_REL_SH3_TOKEN 0x0012

#परिभाषय IMAGE_REL_SHM_PCRELPT 0x0013
#परिभाषय IMAGE_REL_SHM_REFLO 0x0014
#परिभाषय IMAGE_REL_SHM_REFHALF 0x0015
#परिभाषय IMAGE_REL_SHM_RELLO 0x0016
#परिभाषय IMAGE_REL_SHM_RELHALF 0x0017
#परिभाषय IMAGE_REL_SHM_PAIR 0x0018

#परिभाषय IMAGE_REL_SH_NOMODE 0x8000

#परिभाषय IMAGE_REL_ARM_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_ARM_ADDR32 0x0001
#परिभाषय IMAGE_REL_ARM_ADDR32NB 0x0002
#परिभाषय IMAGE_REL_ARM_BRANCH24 0x0003
#परिभाषय IMAGE_REL_ARM_BRANCH11 0x0004
#परिभाषय IMAGE_REL_ARM_TOKEN 0x0005
#परिभाषय IMAGE_REL_ARM_GPREL12 0x0006
#परिभाषय IMAGE_REL_ARM_GPREL7 0x0007
#परिभाषय IMAGE_REL_ARM_BLX24 0x0008
#परिभाषय IMAGE_REL_ARM_BLX11 0x0009
#परिभाषय IMAGE_REL_ARM_SECTION 0x000E
#परिभाषय IMAGE_REL_ARM_SECREL 0x000F

#परिभाषय IMAGE_REL_AM_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_AM_ADDR32 0x0001
#परिभाषय IMAGE_REL_AM_ADDR32NB 0x0002
#परिभाषय IMAGE_REL_AM_CALL32 0x0003
#परिभाषय IMAGE_REL_AM_FUNCINFO 0x0004
#परिभाषय IMAGE_REL_AM_REL32_1 0x0005
#परिभाषय IMAGE_REL_AM_REL32_2 0x0006
#परिभाषय IMAGE_REL_AM_SECREL 0x0007
#परिभाषय IMAGE_REL_AM_SECTION 0x0008
#परिभाषय IMAGE_REL_AM_TOKEN 0x0009

#परिभाषय IMAGE_REL_AMD64_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_AMD64_ADDR64 0x0001
#परिभाषय IMAGE_REL_AMD64_ADDR32 0x0002
#परिभाषय IMAGE_REL_AMD64_ADDR32NB 0x0003
#परिभाषय IMAGE_REL_AMD64_REL32 0x0004
#परिभाषय IMAGE_REL_AMD64_REL32_1 0x0005
#परिभाषय IMAGE_REL_AMD64_REL32_2 0x0006
#परिभाषय IMAGE_REL_AMD64_REL32_3 0x0007
#परिभाषय IMAGE_REL_AMD64_REL32_4 0x0008
#परिभाषय IMAGE_REL_AMD64_REL32_5 0x0009
#परिभाषय IMAGE_REL_AMD64_SECTION 0x000A
#परिभाषय IMAGE_REL_AMD64_SECREL 0x000B
#परिभाषय IMAGE_REL_AMD64_SECREL7 0x000C
#परिभाषय IMAGE_REL_AMD64_TOKEN 0x000D
#परिभाषय IMAGE_REL_AMD64_SREL32 0x000E
#परिभाषय IMAGE_REL_AMD64_PAIR 0x000F
#परिभाषय IMAGE_REL_AMD64_SSPAN32 0x0010

#परिभाषय IMAGE_REL_IA64_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_IA64_IMM14 0x0001
#परिभाषय IMAGE_REL_IA64_IMM22 0x0002
#परिभाषय IMAGE_REL_IA64_IMM64 0x0003
#परिभाषय IMAGE_REL_IA64_DIR32 0x0004
#परिभाषय IMAGE_REL_IA64_DIR64 0x0005
#परिभाषय IMAGE_REL_IA64_PCREL21B 0x0006
#परिभाषय IMAGE_REL_IA64_PCREL21M 0x0007
#परिभाषय IMAGE_REL_IA64_PCREL21F 0x0008
#परिभाषय IMAGE_REL_IA64_GPREL22 0x0009
#परिभाषय IMAGE_REL_IA64_LTOFF22 0x000A
#परिभाषय IMAGE_REL_IA64_SECTION 0x000B
#परिभाषय IMAGE_REL_IA64_SECREL22 0x000C
#परिभाषय IMAGE_REL_IA64_SECREL64I 0x000D
#परिभाषय IMAGE_REL_IA64_SECREL32 0x000E

#परिभाषय IMAGE_REL_IA64_DIR32NB 0x0010
#परिभाषय IMAGE_REL_IA64_SREL14 0x0011
#परिभाषय IMAGE_REL_IA64_SREL22 0x0012
#परिभाषय IMAGE_REL_IA64_SREL32 0x0013
#परिभाषय IMAGE_REL_IA64_UREL32 0x0014
#परिभाषय IMAGE_REL_IA64_PCREL60X 0x0015
#परिभाषय IMAGE_REL_IA64_PCREL60B 0x0016
#परिभाषय IMAGE_REL_IA64_PCREL60F 0x0017
#परिभाषय IMAGE_REL_IA64_PCREL60I 0x0018
#परिभाषय IMAGE_REL_IA64_PCREL60M 0x0019
#परिभाषय IMAGE_REL_IA64_IMMGPREL64 0x001A
#परिभाषय IMAGE_REL_IA64_TOKEN 0x001B
#परिभाषय IMAGE_REL_IA64_GPREL32 0x001C
#परिभाषय IMAGE_REL_IA64_ADDEND 0x001F

#परिभाषय IMAGE_REL_CEF_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_CEF_ADDR32 0x0001
#परिभाषय IMAGE_REL_CEF_ADDR64 0x0002
#परिभाषय IMAGE_REL_CEF_ADDR32NB 0x0003
#परिभाषय IMAGE_REL_CEF_SECTION 0x0004
#परिभाषय IMAGE_REL_CEF_SECREL 0x0005
#परिभाषय IMAGE_REL_CEF_TOKEN 0x0006

#परिभाषय IMAGE_REL_CEE_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_CEE_ADDR32 0x0001
#परिभाषय IMAGE_REL_CEE_ADDR64 0x0002
#परिभाषय IMAGE_REL_CEE_ADDR32NB 0x0003
#परिभाषय IMAGE_REL_CEE_SECTION 0x0004
#परिभाषय IMAGE_REL_CEE_SECREL 0x0005
#परिभाषय IMAGE_REL_CEE_TOKEN 0x0006

#परिभाषय IMAGE_REL_M32R_ABSOLUTE 0x0000
#परिभाषय IMAGE_REL_M32R_ADDR32 0x0001
#परिभाषय IMAGE_REL_M32R_ADDR32NB 0x0002
#परिभाषय IMAGE_REL_M32R_ADDR24 0x0003
#परिभाषय IMAGE_REL_M32R_GPREL16 0x0004
#परिभाषय IMAGE_REL_M32R_PCREL24 0x0005
#परिभाषय IMAGE_REL_M32R_PCREL16 0x0006
#परिभाषय IMAGE_REL_M32R_PCREL8 0x0007
#परिभाषय IMAGE_REL_M32R_REFHALF 0x0008
#परिभाषय IMAGE_REL_M32R_REFHI 0x0009
#परिभाषय IMAGE_REL_M32R_REFLO 0x000A
#परिभाषय IMAGE_REL_M32R_PAIR 0x000B
#परिभाषय IMAGE_REL_M32R_SECTION 0x000C
#परिभाषय IMAGE_REL_M32R_SECREL32 0x000D
#परिभाषय IMAGE_REL_M32R_TOKEN 0x000E

#परिभाषय EXT_IMM64(मानम्_3,स्थानाङ्कः_2,आकार_3,InstPos,ValPos) मानम्_3 |= (((ULONGLONG)((*(स्थानाङ्कः_2) >> InstPos) & (((ULONGLONG)1 << आकार_3) - 1))) << ValPos)
#परिभाषय INS_IMM64(मानम्_3,स्थानाङ्कः_2,आकार_3,InstPos,ValPos) *(PDWORD)स्थानाङ्कः_2 = (*(PDWORD)स्थानाङ्कः_2 & ~(((1 << आकार_3) - 1) << InstPos)) | ((DWORD)((((ULONGLONG)मानम्_3 >> ValPos) & (((ULONGLONG)1 << आकार_3) - 1))) << InstPos)

#परिभाषय EMARCH_ENC_I17_IMM7B_INST_WORD_X 3
#परिभाषय EMARCH_ENC_I17_IMM7_B_आकार_X 7
#परिभाषय EMARCH_ENC_I17_IMM7B_INST_WORD_POS_X 4
#परिभाषय EMARCH_ENC_I17_IMM7B_VAL_POS_X 0

#परिभाषय EMARCH_ENC_I17_IMM9D_INST_WORD_X 3
#परिभाषय EMARCH_ENC_I17_IMM9_D_आकार_X 9
#परिभाषय EMARCH_ENC_I17_IMM9D_INST_WORD_POS_X 18
#परिभाषय EMARCH_ENC_I17_IMM9D_VAL_POS_X 7

#परिभाषय EMARCH_ENC_I17_IMM5C_INST_WORD_X 3
#परिभाषय EMARCH_ENC_I17_IMM5_C_आकार_X 5
#परिभाषय EMARCH_ENC_I17_IMM5C_INST_WORD_POS_X 13
#परिभाषय EMARCH_ENC_I17_IMM5C_VAL_POS_X 16

#परिभाषय EMARCH_ENC_I17_IC_INST_WORD_X 3
#परिभाषय EMARCH_ENC_I17_IC_आकार_X 1
#परिभाषय EMARCH_ENC_I17_IC_INST_WORD_POS_X 12
#परिभाषय EMARCH_ENC_I17_IC_VAL_POS_X 21

#परिभाषय EMARCH_ENC_I17_IMM41a_INST_WORD_X 1
#परिभाषय EMARCH_ENC_I17_IMM41a_आकार_X 10
#परिभाषय EMARCH_ENC_I17_IMM41a_INST_WORD_POS_X 14
#परिभाषय EMARCH_ENC_I17_IMM41a_VAL_POS_X 22

#परिभाषय EMARCH_ENC_I17_IMM41b_INST_WORD_X 1
#परिभाषय EMARCH_ENC_I17_IMM41b_आकार_X 8
#परिभाषय EMARCH_ENC_I17_IMM41b_INST_WORD_POS_X 24
#परिभाषय EMARCH_ENC_I17_IMM41b_VAL_POS_X 32

#परिभाषय EMARCH_ENC_I17_IMM41c_INST_WORD_X 2
#परिभाषय EMARCH_ENC_I17_IMM41c_आकार_X 23
#परिभाषय EMARCH_ENC_I17_IMM41c_INST_WORD_POS_X 0
#परिभाषय EMARCH_ENC_I17_IMM41c_VAL_POS_X 40

#परिभाषय EMARCH_ENC_I17_SIGN_INST_WORD_X 3
#परिभाषय EMARCH_ENC_I17_SIGN_आकार_X 1
#परिभाषय EMARCH_ENC_I17_SIGN_INST_WORD_POS_X 27
#परिभाषय EMARCH_ENC_I17_SIGN_VAL_POS_X 63

#परिभाषय X3_OPCODE_INST_WORD_X 3
#परिभाषय X3_OPCODE_आकार_X 4
#परिभाषय X3_OPCODE_INST_WORD_POS_X 28
#परिभाषय X3_OPCODE_SIGN_VAL_POS_X 0

#परिभाषय X3_I_INST_WORD_X 3
#परिभाषय X3_I_आकार_X 1
#परिभाषय X3_I_INST_WORD_POS_X 27
#परिभाषय X3_I_SIGN_VAL_POS_X 59

#परिभाषय X3_D_WH_INST_WORD_X 3
#परिभाषय X3_D_WH_आकार_X 3
#परिभाषय X3_D_WH_INST_WORD_POS_X 24
#परिभाषय X3_D_WH_SIGN_VAL_POS_X 0

#परिभाषय X3_IMM20_INST_WORD_X 3
#परिभाषय X3_IMM20_आकार_X 20
#परिभाषय X3_IMM20_INST_WORD_POS_X 4
#परिभाषय X3_IMM20_SIGN_VAL_POS_X 0

#परिभाषय X3_IMM39_1_INST_WORD_X 2
#परिभाषय X3_IMM39_1_आकार_X 23
#परिभाषय X3_IMM39_1_INST_WORD_POS_X 0
#परिभाषय X3_IMM39_1_SIGN_VAL_POS_X 36

#परिभाषय X3_IMM39_2_INST_WORD_X 1
#परिभाषय X3_IMM39_2_आकार_X 16
#परिभाषय X3_IMM39_2_INST_WORD_POS_X 16
#परिभाषय X3_IMM39_2_SIGN_VAL_POS_X 20

#परिभाषय X3_P_INST_WORD_X 3
#परिभाषय X3_P_आकार_X 4
#परिभाषय X3_P_INST_WORD_POS_X 0
#परिभाषय X3_P_SIGN_VAL_POS_X 0

#परिभाषय X3_TMPLT_INST_WORD_X 0
#परिभाषय X3_TMPLT_आकार_X 4
#परिभाषय X3_TMPLT_INST_WORD_POS_X 0
#परिभाषय X3_TMPLT_SIGN_VAL_POS_X 0

#परिभाषय X3_BTYPE_QP_INST_WORD_X 2
#परिभाषय X3_BTYPE_QP_आकार_X 9
#परिभाषय X3_BTYPE_QP_INST_WORD_POS_X 23
#परिभाषय X3_BTYPE_QP_INST_VAL_POS_X 0

#परिभाषय X3_रिक्तानि_INST_WORD_X 1
#परिभाषय X3_रिक्तानि_आकार_X 2
#परिभाषय X3_रिक्तानि_INST_WORD_POS_X 14
#परिभाषय X3_रिक्तानि_INST_VAL_POS_X 0

    प्रकारनिर्देश संरचना _IMAGE_LINENUMBER {
      सङ्घ {
	DWORD चिह्नम्_सारणी_सूचकांक;
	DWORD Virtual_स्थानाङ्कः;
      } Type;
      WORD Linenumber;
    } IMAGE_LINENUMBER;
    प्रकारनिर्देश IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#परिभाषय IMAGE_SIZEOF_LINENUMBER 6

#अन्तर्भाव "poppack.h"

    प्रकारनिर्देश संरचना IMAGE_आधारः_RELOCATION {
      DWORD Virtual_स्थानाङ्कः;
      DWORD आकार_सम्बन्धि_खण्डम्;

    } IMAGE_आधारः_RELOCATION_2;
    प्रकारनिर्देश IMAGE_आधारः_RELOCATION_2 UNALIGNED *PIMAGE_आधारः_RELOCATION;

#परिभाषय IMAGE_SIZEOF_आधारः_RELOCATION 8

#परिभाषय IMAGE_REL_BASED_ABSOLUTE 0
#परिभाषय IMAGE_REL_BASED_उच्चः 1
#परिभाषय IMAGE_REL_BASED_नीचः 2
#परिभाषय IMAGE_REL_BASED_HIGHLOW 3
#परिभाषय IMAGE_REL_BASED_HIGHADJ 4
#परिभाषय IMAGE_REL_BASED_MIPS_JMPADDR 5
#परिभाषय IMAGE_REL_BASED_MIPS_JMPADDR16 9
#परिभाषय IMAGE_REL_BASED_IA64_IMM64 9
#परिभाषय IMAGE_REL_BASED_DIR64 10

#परिभाषय IMAGE_ARCHIVE_START_आकार 8
#परिभाषय IMAGE_ARCHIVE_START "!<arch>\n"
#परिभाषय IMAGE_ARCHIVE_अन्तः "`\n"
#परिभाषय IMAGE_ARCHIVE_PAD "\n"
#परिभाषय IMAGE_ARCHIVE_LINKER_MEMBER "/               "
#परिभाषय IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

    प्रकारनिर्देश संरचना IMAGE_ARCHIVE_MEMBER_शीर्षकम् {
      BYTE Name[16];
      BYTE Date[12];
      BYTE UserID[6];
      BYTE गणः_ID[6];
      BYTE बहुलकम्_4[8];
      BYTE आकार_3[10];
      BYTE अन्तः_शीर्षकम्[2];
    } IMAGE_ARCHIVE_MEMBER_शीर्षकम्_2,*PIMAGE_ARCHIVE_MEMBER_शीर्षकम्;

#परिभाषय IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR 60

    प्रकारनिर्देश संरचना _IMAGE_EXPORT_DIRECTORY {
      DWORD Characteristics;
      DWORD TimeDateStamp;
      WORD Major_संस्करणम्;
      WORD Minor_संस्करणम्;
      DWORD Name;
      DWORD आधारः_2;
      DWORD सङ्ख्या_सम्बन्धि_Functions;
      DWORD सङ्ख्या_सम्बन्धि_नामानि;
      DWORD स्थानाङ्कः_सम्बन्धि_Functions;
      DWORD स्थानाङ्कः_सम्बन्धि_नामानि;
      DWORD स्थानाङ्कः_सम्बन्धि_Name_Ordinals;
    } IMAGE_EXPORT_DIRECTORY,*PIMAGE_EXPORT_DIRECTORY;

    प्रकारनिर्देश संरचना _IMAGE_IMPORT_BY_NAME {
      WORD Hint;
      BYTE Name[1];
    } IMAGE_IMPORT_BY_NAME,*PIMAGE_IMPORT_BY_NAME;

#अन्तर्भाव "pshpack8.h"

    प्रकारनिर्देश संरचना _IMAGE_THUNK_DATA64 {
      सङ्घ {
	ULONGLONG ForwarderString;
	ULONGLONG Function;
	ULONGLONG Ordinal;
	ULONGLONG स्थानाङ्कः_सम्बन्धि_दत्त;
      } u1;
    } IMAGE_THUNK_DATA64;
    प्रकारनिर्देश IMAGE_THUNK_DATA64 *PIMAGE_THUNK_DATA64;

#अन्तर्भाव "poppack.h"

    प्रकारनिर्देश संरचना _IMAGE_THUNK_DATA32 {
      सङ्घ {
	DWORD ForwarderString;
	DWORD Function;
	DWORD Ordinal;
	DWORD स्थानाङ्कः_सम्बन्धि_दत्त;
      } u1;
    } IMAGE_THUNK_DATA32;
    प्रकारनिर्देश IMAGE_THUNK_DATA32 *PIMAGE_THUNK_DATA32;

#परिभाषय IMAGE_ORDINAL_FLAG64 0x8000000000000000ull
#परिभाषय IMAGE_ORDINAL_FLAG32 0x80000000
#परिभाषय IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffffull)
#परिभाषय IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
#परिभाषय IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64)!=0)
#परिभाषय IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32)!=0)

    प्रकारनिर्देश VOID
      (NTAPI *PIMAGE_TLS_CALLBACK)(PVOID DllHandle,DWORD Reason,PVOID Reserved);

    प्रकारनिर्देश संरचना _IMAGE_TLS_DIRECTORY64 {
      ULONGLONG Start_स्थानाङ्कः_सम्बन्धि_Raw_दत्त;
      ULONGLONG अन्तः_स्थानाङ्कः_सम्बन्धि_Raw_दत्त;
      ULONGLONG स्थानाङ्कः_सम्बन्धि_सूचकांक;
      ULONGLONG स्थानाङ्कः_सम्बन्धि_Call_Backs;
      DWORD आकार_सम्बन्धि_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY64;
    प्रकारनिर्देश IMAGE_TLS_DIRECTORY64 *PIMAGE_TLS_DIRECTORY64;

    प्रकारनिर्देश संरचना _IMAGE_TLS_DIRECTORY32 {
      DWORD Start_स्थानाङ्कः_सम्बन्धि_Raw_दत्त;
      DWORD अन्तः_स्थानाङ्कः_सम्बन्धि_Raw_दत्त;
      DWORD स्थानाङ्कः_सम्बन्धि_सूचकांक;
      DWORD स्थानाङ्कः_सम्बन्धि_Call_Backs;
      DWORD आकार_सम्बन्धि_Zero_Fill;
      DWORD Characteristics;
    } IMAGE_TLS_DIRECTORY32;
    प्रकारनिर्देश IMAGE_TLS_DIRECTORY32 *PIMAGE_TLS_DIRECTORY32;

#यदि_परिभाषितम् _WIN64
#परिभाषय IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
#परिभाषय IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL64(Ordinal)
    प्रकारनिर्देश IMAGE_THUNK_DATA64 IMAGE_THUNK_दत्त;
    प्रकारनिर्देश PIMAGE_THUNK_DATA64 PIMAGE_THUNK_दत्त;
#परिभाषय IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL64(Ordinal)
    प्रकारनिर्देश IMAGE_TLS_DIRECTORY64 IMAGE_TLS_DIRECTORY;
    प्रकारनिर्देश PIMAGE_TLS_DIRECTORY64 PIMAGE_TLS_DIRECTORY;
#अन्यथा
#परिभाषय IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
#परिभाषय IMAGE_ORDINAL(Ordinal) IMAGE_ORDINAL32(Ordinal)
    प्रकारनिर्देश IMAGE_THUNK_DATA32 IMAGE_THUNK_दत्त;
    प्रकारनिर्देश PIMAGE_THUNK_DATA32 PIMAGE_THUNK_दत्त;
#परिभाषय IMAGE_SNAP_BY_ORDINAL(Ordinal) IMAGE_SNAP_BY_ORDINAL32(Ordinal)
    प्रकारनिर्देश IMAGE_TLS_DIRECTORY32 IMAGE_TLS_DIRECTORY;
    प्रकारनिर्देश PIMAGE_TLS_DIRECTORY32 PIMAGE_TLS_DIRECTORY;
#यदि_अन्तः

    प्रकारनिर्देश संरचना _IMAGE_IMPORT_DESCRIPTOR {
      सङ्घ {
	DWORD Characteristics;
	DWORD OriginalFirstThunk;
      };
      DWORD TimeDateStamp;

      DWORD ForwarderChain;
      DWORD Name;
      DWORD FirstThunk;
    } IMAGE_IMPORT_DESCRIPTOR;
    प्रकारनिर्देश IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

    प्रकारनिर्देश संरचना _IMAGE_BOUND_IMPORT_DESCRIPTOR {
      DWORD TimeDateStamp;
      WORD विस्थापनम्_Module_Name;
      WORD सङ्ख्या_सम्बन्धि_Module_Forwarder_Refs;
    } IMAGE_BOUND_IMPORT_DESCRIPTOR,*PIMAGE_BOUND_IMPORT_DESCRIPTOR;

    प्रकारनिर्देश संरचना _IMAGE_BOUND_FORWARDER_REF {
      DWORD TimeDateStamp;
      WORD विस्थापनम्_Module_Name;
      WORD Reserved;
    } IMAGE_BOUND_FORWARDER_REF,*PIMAGE_BOUND_FORWARDER_REF;

    प्रकारनिर्देश संरचना _IMAGE_RESOURCE_DIRECTORY {
      DWORD Characteristics;
      DWORD TimeDateStamp;
      WORD Major_संस्करणम्;
      WORD Minor_संस्करणम्;
      WORD सङ्ख्या_सम्बन्धि_Named_Entries;
      WORD सङ्ख्या_सम्बन्धि_Id_Entries;
    } IMAGE_RESOURCE_DIRECTORY,*PIMAGE_RESOURCE_DIRECTORY;

#परिभाषय IMAGE_RESOURCE_NAME_IS_STRING 0x80000000
#परिभाषय IMAGE_RESOURCE_दत्त_IS_DIRECTORY 0x80000000

    प्रकारनिर्देश संरचना IMAGE_RESOURCE_DIRECTORY_प्रविष्टिः {
      सङ्घ {
	संरचना {
	  DWORD Name_विस्थापनम्:31;
	  DWORD NameIsString:1;
	};
	DWORD Name;
	WORD Id;
      };
      सङ्घ {
	DWORD विस्थापनम्_गन्तव्यम्_दत्त;
	संरचना {
	  DWORD विस्थापनम्_गन्तव्यम्_Directory:31;
	  DWORD दत्त_Is_Directory:1;
	};
      };
    } IMAGE_RESOURCE_DIRECTORY_प्रविष्टिः_2,*PIMAGE_RESOURCE_DIRECTORY_प्रविष्टिः;

    प्रकारनिर्देश संरचना _IMAGE_RESOURCE_DIRECTORY_STRING {
      WORD दीर्घता_2;
      CHAR NameString[1];
    } IMAGE_RESOURCE_DIRECTORY_STRING,*PIMAGE_RESOURCE_DIRECTORY_STRING;

    प्रकारनिर्देश संरचना _IMAGE_RESOURCE_DIR_STRING_U {
      WORD दीर्घता_2;
      WCHAR NameString[1];
    } IMAGE_RESOURCE_DIR_STRING_U,*PIMAGE_RESOURCE_DIR_STRING_U;

    प्रकारनिर्देश संरचना IMAGE_RESOURCE_दत्त_प्रविष्टिः {
      DWORD विस्थापनम्_गन्तव्यम्_दत्त;
      DWORD आकार_3;
      DWORD संहिता_Page;
      DWORD Reserved;
    } IMAGE_RESOURCE_दत्त_प्रविष्टिः_2,*PIMAGE_RESOURCE_दत्त_प्रविष्टिः;

    प्रकारनिर्देश संरचना {
      DWORD आकार_3;
      DWORD TimeDateStamp;
      WORD Major_संस्करणम्;
      WORD Minor_संस्करणम्;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_समुच्चयः;
      DWORD CriticalSectionDefaultTimeout;
      DWORD De_Commit_Free_खण्डम्_देहली;
      DWORD De_Commit_योग_Free_देहली;
      DWORD तालकम्_उपसर्गः_सारणी;
      DWORD अधिकतमम्_आवण्टनम्_आकार;
      DWORD Virtual_स्मृतिः_देहली;
      DWORD ProcessHeapFlags;
      DWORD Process_Affinity_आवरणम्;
      WORD CSDVersion;
      WORD Reserved1;
      DWORD EditList;
      DWORD SecurityCookie;
      DWORD SEHandler_सारणी;
      DWORD SEHandler_गणनम्;
    } IMAGE_आरोपय_CONFIG_DIRECTORY32,*PIMAGE_आरोपय_CONFIG_DIRECTORY32;

    प्रकारनिर्देश संरचना {
      DWORD आकार_3;
      DWORD TimeDateStamp;
      WORD Major_संस्करणम्;
      WORD Minor_संस्करणम्;
      DWORD GlobalFlagsClear;
      DWORD Global_Flags_समुच्चयः;
      DWORD CriticalSectionDefaultTimeout;
      ULONGLONG De_Commit_Free_खण्डम्_देहली;
      ULONGLONG De_Commit_योग_Free_देहली;
      ULONGLONG तालकम्_उपसर्गः_सारणी;
      ULONGLONG अधिकतमम्_आवण्टनम्_आकार;
      ULONGLONG Virtual_स्मृतिः_देहली;
      ULONGLONG Process_Affinity_आवरणम्;
      DWORD ProcessHeapFlags;
      WORD CSDVersion;
      WORD Reserved1;
      ULONGLONG EditList;
      ULONGLONG SecurityCookie;
      ULONGLONG SEHandler_सारणी;
      ULONGLONG SEHandler_गणनम्;
    } IMAGE_आरोपय_CONFIG_DIRECTORY64,*PIMAGE_आरोपय_CONFIG_DIRECTORY64;

#यदि_परिभाषितम् _WIN64
    प्रकारनिर्देश IMAGE_आरोपय_CONFIG_DIRECTORY64 IMAGE_आरोपय_CONFIG_DIRECTORY;
    प्रकारनिर्देश PIMAGE_आरोपय_CONFIG_DIRECTORY64 PIMAGE_आरोपय_CONFIG_DIRECTORY;
#अन्यथा
    प्रकारनिर्देश IMAGE_आरोपय_CONFIG_DIRECTORY32 IMAGE_आरोपय_CONFIG_DIRECTORY;
    प्रकारनिर्देश PIMAGE_आरोपय_CONFIG_DIRECTORY32 PIMAGE_आरोपय_CONFIG_DIRECTORY;
#यदि_अन्तः

    प्रकारनिर्देश संरचना IMAGE_CE_RUNTIME_FUNCTION_प्रविष्टिः {
      DWORD FuncStart;
      DWORD PrologLen : 8;
      DWORD FuncLen : 22;
      DWORD ThirtyTwoBit : 1;
      DWORD ExceptionFlag : 1;
    } IMAGE_CE_RUNTIME_FUNCTION_प्रविष्टिः_2,*PIMAGE_CE_RUNTIME_FUNCTION_प्रविष्टिः;

    प्रकारनिर्देश संरचना IMAGE_ALPHA64_RUNTIME_FUNCTION_प्रविष्टिः {
      ULONGLONG Begin_स्थानाङ्कः;
      ULONGLONG अन्तः_स्थानाङ्कः;
      ULONGLONG ExceptionHandler;
      ULONGLONG Handler_दत्त;
      ULONGLONG Prolog_अन्तः_स्थानाङ्कः;
    } IMAGE_ALPHA64_RUNTIME_FUNCTION_प्रविष्टिः_2,*PIMAGE_ALPHA64_RUNTIME_FUNCTION_प्रविष्टिः;

    प्रकारनिर्देश संरचना IMAGE_ALPHA_RUNTIME_FUNCTION_प्रविष्टिः {
      DWORD Begin_स्थानाङ्कः;
      DWORD अन्तः_स्थानाङ्कः;
      DWORD ExceptionHandler;
      DWORD Handler_दत्त;
      DWORD Prolog_अन्तः_स्थानाङ्कः;
    } IMAGE_ALPHA_RUNTIME_FUNCTION_प्रविष्टिः_2,*PIMAGE_ALPHA_RUNTIME_FUNCTION_प्रविष्टिः;

    प्रकारनिर्देश संरचना IMAGE_RUNTIME_FUNCTION_प्रविष्टिः {
      DWORD Begin_स्थानाङ्कः;
      DWORD अन्तः_स्थानाङ्कः;
      DWORD Unwind_Info_स्थानाङ्कः;
    } IMAGE_RUNTIME_FUNCTION_प्रविष्टिः,*PIMAGE_RUNTIME_FUNCTION_प्रविष्टिः;

    प्रकारनिर्देश IMAGE_RUNTIME_FUNCTION_प्रविष्टिः IMAGE_IA64_RUNTIME_FUNCTION_प्रविष्टिः;
    प्रकारनिर्देश PIMAGE_RUNTIME_FUNCTION_प्रविष्टिः PIMAGE_IA64_RUNTIME_FUNCTION_प्रविष्टिः;

    प्रकारनिर्देश IMAGE_RUNTIME_FUNCTION_प्रविष्टिः IMAGE_RUNTIME_FUNCTION_प्रविष्टिः_2;
    प्रकारनिर्देश PIMAGE_RUNTIME_FUNCTION_प्रविष्टिः PIMAGE_RUNTIME_FUNCTION_प्रविष्टिः_2;

    प्रकारनिर्देश संरचना _IMAGE_DEBUG_DIRECTORY {
      DWORD Characteristics;
      DWORD TimeDateStamp;
      WORD Major_संस्करणम्;
      WORD Minor_संस्करणम्;
      DWORD Type;
      DWORD आकार_सम्बन्धि_दत्त;
      DWORD स्थानाङ्कः_सम्बन्धि_Raw_दत्त;
      DWORD Pointer_गन्तव्यम्_Raw_दत्त;
    } IMAGE_DEBUG_DIRECTORY,*PIMAGE_DEBUG_DIRECTORY;

#परिभाषय IMAGE_DEBUG_TYPE_UNKNOWN 0
#परिभाषय IMAGE_DEBUG_TYPE_COFF 1
#परिभाषय IMAGE_DEBUG_TYPE_CODEVIEW 2
#परिभाषय IMAGE_DEBUG_TYPE_FPO 3
#परिभाषय IMAGE_DEBUG_TYPE_MISC 4
#परिभाषय IMAGE_DEBUG_TYPE_EXCEPTION 5
#परिभाषय IMAGE_DEBUG_TYPE_FIXUP 6
#परिभाषय IMAGE_DEBUG_TYPE_OMAP_गन्तव्यम्_SRC 7
#परिभाषय IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#परिभाषय IMAGE_DEBUG_TYPE_BORLAND 9
#परिभाषय IMAGE_DEBUG_TYPE_RESERVED10 10
#परिभाषय IMAGE_DEBUG_TYPE_CLSID 11

    प्रकारनिर्देश संरचना IMAGE_COFF_SYMBOLS_शीर्षकम् {
      DWORD सङ्ख्या_सम्बन्धि_Symbols;
      DWORD Lva_गन्तव्यम्_First_चिह्नम्;
      DWORD सङ्ख्या_सम्बन्धि_Linenumbers;
      DWORD Lva_गन्तव्यम्_First_Linenumber;
      DWORD Rva_गन्तव्यम्_First_Byte_सम्बन्धि_संहिता;
      DWORD Rva_गन्तव्यम्_चरमः_Byte_सम्बन्धि_संहिता;
      DWORD Rva_गन्तव्यम्_First_Byte_सम्बन्धि_दत्त;
      DWORD Rva_गन्तव्यम्_चरमः_Byte_सम्बन्धि_दत्त;
    } IMAGE_COFF_SYMBOLS_शीर्षकम्_2,*PIMAGE_COFF_SYMBOLS_शीर्षकम्;

#परिभाषय FRAME_FPO 0
#परिभाषय FRAME_TRAP 1
#परिभाषय FRAME_TSS 2
#परिभाषय FRAME_NONFPO 3

    प्रकारनिर्देश संरचना FPO_दत्त {
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
    } FPO_दत्त_2,*PFPO_दत्त;
#परिभाषय SIZEOF_RFPO_दत्त 16

#परिभाषय IMAGE_DEBUG_MISC_EXENAME 1

    प्रकारनिर्देश संरचना _IMAGE_DEBUG_MISC {
      DWORD दत्त_Type;
      DWORD दीर्घता_2;
      BOOLEAN Unicode;
      BYTE Reserved[3];
      BYTE दत्त_3[1];
    } IMAGE_DEBUG_MISC,*PIMAGE_DEBUG_MISC;

    प्रकारनिर्देश संरचना IMAGE_FUNCTION_प्रविष्टिः {
      DWORD Starting_स्थानाङ्कः;
      DWORD Ending_स्थानाङ्कः;
      DWORD अन्तः_सम्बन्धि_Prologue;
    } IMAGE_FUNCTION_प्रविष्टिः_2,*PIMAGE_FUNCTION_प्रविष्टिः;

    प्रकारनिर्देश संरचना _IMAGE_FUNCTION_ENTRY64 {
      ULONGLONG Starting_स्थानाङ्कः;
      ULONGLONG Ending_स्थानाङ्कः;
      सङ्घ {
	ULONGLONG अन्तः_सम्बन्धि_Prologue;
	ULONGLONG Unwind_Info_स्थानाङ्कः;
      };
    } IMAGE_FUNCTION_ENTRY64,*PIMAGE_FUNCTION_ENTRY64;

    प्रकारनिर्देश संरचना IMAGE_SEPARATE_DEBUG_शीर्षकम् {
      WORD Signature;
      WORD Flags;
      WORD Machine;
      WORD Characteristics;
      DWORD TimeDateStamp;
      DWORD Check_योग;
      DWORD Image_आधारः;
      DWORD आकार_सम्बन्धि_Image;
      DWORD सङ्ख्या_सम्बन्धि_Sections;
      DWORD Exported_नामानि_आकार;
      DWORD Debug_Directory_आकार;
      DWORD SectionAlignment;
      DWORD Reserved[2];
    } IMAGE_SEPARATE_DEBUG_शीर्षकम्_2,*PIMAGE_SEPARATE_DEBUG_शीर्षकम्;

    प्रकारनिर्देश संरचना _NON_PAGED_DEBUG_INFO {
      WORD Signature;
      WORD Flags;
      DWORD आकार_3;
      WORD Machine;
      WORD Characteristics;
      DWORD TimeDateStamp;
      DWORD Check_योग;
      DWORD आकार_सम्बन्धि_Image;
      ULONGLONG Image_आधारः;

    } NON_PAGED_DEBUG_INFO,*PNON_PAGED_DEBUG_INFO;

#परिभाषय IMAGE_SEPARATE_DEBUG_SIGNATURE 0x4944
#परिभाषय NON_PAGED_DEBUG_SIGNATURE 0x494E

#परिभाषय IMAGE_SEPARATE_DEBUG_FLAGS_आवरणम् 0x8000
#परिभाषय IMAGE_SEPARATE_DEBUG_MISMATCH 0x8000

    प्रकारनिर्देश संरचना Image_Architecture_शीर्षकम् {
      अचिह्नित पूर्णाङ्क Amask_मानम्: 1;
      पूर्णाङ्क Adummy1 :7;
      अचिह्नित पूर्णाङ्क Amask_सरणम्: 8;
      पूर्णाङ्क Adummy2 :16;
      DWORD First_प्रविष्टिः_RVA;
    } IMAGE_ARCHITECTURE_शीर्षकम्,*PIMAGE_ARCHITECTURE_शीर्षकम्;

    प्रकारनिर्देश संरचना Image_Architecture_प्रविष्टिः {
      DWORD FixupInstRVA;
      DWORD NewInst;
    } IMAGE_ARCHITECTURE_प्रविष्टिः,*PIMAGE_ARCHITECTURE_प्रविष्टिः;

#अन्तर्भाव "poppack.h"

#परिभाषय IMPORT_OBJECT_HDR_SIG2 0xffff

    प्रकारनिर्देश संरचना IMPORT_OBJECT_शीर्षकम् {
      WORD Sig1;
      WORD Sig2;
      WORD संस्करणम्_2;
      WORD Machine;
      DWORD TimeDateStamp;
      DWORD आकार_सम्बन्धि_दत्त;
      सङ्घ {
	WORD Ordinal;
	WORD Hint;
      };
      WORD Type : 2;
      WORD NameType : 3;
      WORD Reserved : 11;
    } IMPORT_OBJECT_शीर्षकम्;

    प्रकारनिर्देश गणना IMPORT_OBJECT_TYPE {
      IMPORT_OBJECT_संहिता = 0,IMPORT_OBJECT_दत्त = 1,IMPORT_OBJECT_CONST = 2
    } IMPORT_OBJECT_TYPE;

    प्रकारनिर्देश गणना IMPORT_OBJECT_NAME_TYPE {
      IMPORT_OBJECT_ORDINAL = 0,IMPORT_OBJECT_NAME = 1,IMPORT_OBJECT_NAME_NO_उपसर्गः = 2,IMPORT_OBJECT_NAME_UNDECORATE = 3
    } IMPORT_OBJECT_NAME_TYPE;

#यदि_अपरिभाषितम् __IMAGE_COR20_HEADER_DEFINED__
#परिभाषय __IMAGE_COR20_HEADER_DEFINED__
    प्रकारनिर्देश गणना Replaces_Cor_Hdr_Numeric_परिभाषते {
      COMIMAGE_FLAGS_ILONLY =0x00000001,COMIMAGE_FLAGS_32BITREQUIRED =0x00000002,COMIMAGE_FLAGS_IL_LIBRARY =0x00000004,
      COMIMAGE_FLAGS_STRONGNAMESIGNED =0x00000008,COMIMAGE_FLAGS_TRACKDEBUGDATA =0x00010000,COR_संस्करणम्_MAJOR_V2 =2,
      COR_संस्करणम्_MAJOR =COR_संस्करणम्_MAJOR_V2,COR_संस्करणम्_MINOR =0,COR_DELETED_NAME_दीर्घता =8,COR_VTABLEGAP_NAME_दीर्घता =8,
      NATIVE_TYPE_MAX_CB =1,COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,IMAGE_COR_MIH_METHODRVA =0x01,IMAGE_COR_MIH_EHRVA =0x02,
      IMAGE_COR_MIH_BASICBLOCK =0x08,COR_VTABLE_32BIT =0x01,COR_VTABLE_64BIT =0x02,COR_VTABLE_FROM_UNMANAGED =0x04,
      COR_VTABLE_CALL_MOST_DERIVED =0x10,IMAGE_COR_EATJ_THUNK_आकार =32,MAX_CLASS_NAME =1024,MAX_PACKAGE_NAME =1024
    } Replaces_Cor_Hdr_Numeric_परिभाषते;

    प्रकारनिर्देश संरचना IMAGE_COR20_शीर्षकम् {
      DWORD cb;
      WORD Major_Runtime_संस्करणम्;
      WORD Minor_Runtime_संस्करणम्;
      IMAGE_दत्त_DIRECTORY_2 Meta_दत्त;
      DWORD Flags;
      DWORD प्रविष्टिः_Point_Token;
      IMAGE_दत्त_DIRECTORY_2 Resources;
      IMAGE_दत्त_DIRECTORY_2 StrongNameSignature;
      IMAGE_दत्त_DIRECTORY_2 संहिता_Manager_सारणी;
      IMAGE_दत्त_DIRECTORY_2 VTableFixups;
      IMAGE_दत्त_DIRECTORY_2 Export_स्थानाङ्कः_सारणी_Jumps;
      IMAGE_दत्त_DIRECTORY_2 Managed_Native_शीर्षकम्;
    } IMAGE_COR20_शीर्षकम्,*PIMAGE_COR20_शीर्षकम्;
#यदि_अन्तः

#यदि defined (__x86_64)
    NTSYSAPI PRUNTIME_FUNCTION NTAPI Rtl_Lookup_Function_प्रविष्टिः (DWORD64 ControlPc, PDWORD64 Image_आधारः, PUNWIND_HISTORY_सारणी History_सारणी);
    NTSYSAPI VOID NTAPI RtlUnwindEx (PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_लेखः Exception_लेखः, PVOID Return_मानम्_2, PCONTEXT Context_लेखः, PUNWIND_HISTORY_सारणी History_सारणी);
#यदि_अन्तः

#अन्तर्भाव <string.h>

#यदि_अपरिभाषितम् SLIST_शीर्षकम्
#परिभाषय SLIST_शीर्षकम्

#यदि_परिभाषितम् _WIN64
    प्रकारनिर्देश संरचना SLIST_प्रविष्टिः *PSLIST_प्रविष्टिः;
    प्रकारनिर्देश संरचना DECLSPEC_ALIGN(16) SLIST_प्रविष्टिः {
      PSLIST_प्रविष्टिः अग्र_2;
    } SLIST_प्रविष्टिः_2;
#अन्यथा

#परिभाषय SLIST_प्रविष्टिः_2 SINGLE_LIST_प्रविष्टिः_2
#परिभाषय SLIST_प्रविष्टिः SINGLE_LIST_प्रविष्टिः
#परिभाषय PSLIST_प्रविष्टिः PSINGLE_LIST_प्रविष्टिः
#यदि_अन्तः

#यदि defined(_WIN64)

    प्रकारनिर्देश संरचना DECLSPEC_ALIGN(16) SLIST_शीर्षकम्_2 {
      ULONGLONG Alignment;
      ULONGLONG Region;
    } SLIST_शीर्षकम्_3;

    प्रकारनिर्देश संरचना SLIST_शीर्षकम्_2 *PSLIST_शीर्षकम्;
#अन्यथा

    प्रकारनिर्देश सङ्घ SLIST_शीर्षकम्_2 {
      ULONGLONG Alignment;
      संरचना {
	SLIST_प्रविष्टिः_2 अग्र_2;
	WORD गभीरता;
	WORD Sequence;
      };
    } SLIST_शीर्षकम्_3,*PSLIST_शीर्षकम्;
#यदि_अन्तः
#यदि_अन्तः

    NTSYSAPI VOID NTAPI Rtl_Initialize_SList_शीर्ष(PSLIST_शीर्षकम् List_शीर्ष);
    NTSYSAPI PSLIST_प्रविष्टिः NTAPI Rtl_First_प्रविष्टिः_SList(ध्रुव SLIST_शीर्षकम्_3 *List_शीर्ष);
    NTSYSAPI PSLIST_प्रविष्टिः NTAPI Rtl_Interlocked_निष्कासय_प्रविष्टिः_SList(PSLIST_शीर्षकम् List_शीर्ष);
    NTSYSAPI PSLIST_प्रविष्टिः NTAPI Rtl_Interlocked_प्रक्षिप_प्रविष्टिः_SList(PSLIST_शीर्षकम् List_शीर्ष,PSLIST_प्रविष्टिः List_प्रविष्टिः);
    NTSYSAPI PSLIST_प्रविष्टिः NTAPI RtlInterlockedFlushSList(PSLIST_शीर्षकम् List_शीर्ष);
    NTSYSAPI WORD NTAPI Rtl_Query_गभीरता_SList(PSLIST_शीर्षकम् List_शीर्ष);

#परिभाषय HEAP_NO_SERIALIZE 0x00000001
#परिभाषय HEAP_GROWABLE 0x00000002
#परिभाषय HEAP_GENERATE_EXCEPTIONS 0x00000004
#परिभाषय HEAP_ZERO_स्मृतिः 0x00000008
#परिभाषय HEAP_REALLOC_अन्तर्_PLACE_ONLY 0x00000010
#परिभाषय HEAP_पुच्छ_CHECKING_ENABLED 0x00000020
#परिभाषय HEAP_FREE_CHECKING_ENABLED 0x00000040
#परिभाषय HEAP_DISABLE_COALESCE_ON_FREE 0x00000080
#परिभाषय HEAP_CREATE_ALIGN_16 0x00010000
#परिभाषय HEAP_CREATE_ENABLE_TRACING 0x00020000
#परिभाषय HEAP_CREATE_ENABLE_EXECUTE 0x00040000
#परिभाषय HEAP_अधिकतमम्_चिह्नकम् 0x0FFF
#परिभाषय HEAP_PSEUDO_चिह्नकम्_FLAG 0x8000
#परिभाषय HEAP_चिह्नकम्_सरणम् 18
#परिभाषय HEAP_MAKE_चिह्नकम्_FLAGS(b,o) ((DWORD)((b) + ((o) << 18)))

    NTSYSAPI VOID NTAPI RtlCaptureContext(PCONTEXT Context_लेखः);

#परिभाषय IS_TEXT_UNICODE_ASCII16 0x0001
#परिभाषय IS_TEXT_UNICODE_REVERSE_ASCII16 0x0010

#परिभाषय IS_TEXT_UNICODE_STATISTICS 0x0002
#परिभाषय IS_TEXT_UNICODE_REVERSE_STATISTICS 0x0020

#परिभाषय IS_TEXT_UNICODE_CONTROLS 0x0004
#परिभाषय IS_TEXT_UNICODE_REVERSE_CONTROLS 0x0040

#परिभाषय IS_TEXT_UNICODE_SIGNATURE 0x0008
#परिभाषय IS_TEXT_UNICODE_REVERSE_SIGNATURE 0x0080

#परिभाषय IS_TEXT_UNICODE_ILLEGAL_CHARS 0x0100
#परिभाषय IS_TEXT_UNICODE_ODD_दीर्घता 0x0200
#परिभाषय IS_TEXT_UNICODE_DBCS_LEADBYTE 0x0400
#परिभाषय IS_TEXT_UNICODE_NULL_अष्टकानि 0x1000

#परिभाषय IS_TEXT_UNICODE_UNICODE_आवरणम् 0x000F
#परिभाषय IS_TEXT_UNICODE_REVERSE_आवरणम् 0x00F0
#परिभाषय IS_TEXT_UNICODE_NOT_UNICODE_आवरणम् 0x0F00
#परिभाषय IS_TEXT_UNICODE_NOT_ASCII_आवरणम् 0xF000

#परिभाषय COMPRESSION_FORMAT_NONE (0x0000)
#परिभाषय COMPRESSION_FORMAT_DEFAULT (0x0001)
#परिभाषय COMPRESSION_FORMAT_LZNT1 (0x0002)
#परिभाषय COMPRESSION_ENGINE_STANDARD (0x0000)
#परिभाषय COMPRESSION_ENGINE_अधिकतमम् (0x0100)
#परिभाषय COMPRESSION_ENGINE_HIBER (0x0200)

#यदि _DBG_MEMCPY_INLINE_ && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
#परिभाषय _MEMCPY_INLINE_
    __CRT_INLINE PVOID __cdecl memcpy_inline(शून्य *dst,ध्रुव शून्य *src,आकार_t आकार) {
      यदि(((वर्ण *)dst > (वर्ण *)src) && ((वर्ण *)dst < ((वर्ण *)src + आकार))) {
	__debugbreak();
      }
      प्रत्यागम स्मृतिं_प्रतिलिख(dst,src,आकार);
    }
#परिभाषय स्मृतिं_प्रतिलिख memcpy_inline
#यदि_अन्तः

    NTSYSAPI आकार_T NTAPI Rtl_Compare_स्मृतिः(ध्रुव VOID *Source1,ध्रुव VOID *Source2,आकार_T दीर्घता_2);

#परिभाषय Rtl_Equal_स्मृतिः(Destination,Source,दीर्घता_2) (!memcmp((Destination),(Source),(दीर्घता_2)))
#परिभाषय Rtl_Move_स्मृतिः(Destination,Source,दीर्घता_2) memmove((Destination),(Source),(दीर्घता_2))
#परिभाषय Rtl_Copy_स्मृतिः(Destination,Source,दीर्घता_2) स्मृतिं_प्रतिलिख((Destination),(Source),(दीर्घता_2))
#परिभाषय Rtl_Fill_स्मृतिः(Destination,दीर्घता_2,Fill) स्मृतिं_पूरय((Destination),(Fill),(दीर्घता_2))
#परिभाषय Rtl_Zero_स्मृतिः(Destination,दीर्घता_2) स्मृतिं_पूरय((Destination),0,(दीर्घता_2))

    __CRT_INLINE PVOID Rtl_Secure_Zero_स्मृतिः(PVOID ptr,आकार_T cnt) {
      चञ्चल वर्ण *vptr =(चञ्चल वर्ण *)ptr;
#यदि_परिभाषितम् __x86_64
      __stosb((PBYTE)((DWORD64)vptr),0,cnt);
#अन्यथा
      यावत्(cnt) {
	*vptr = 0;
	vptr++;
	cnt--;
      }
#यदि_अन्तः
      प्रत्यागम ptr;
    }

    प्रकारनिर्देश संरचना सन्देशः_RESOURCE_प्रविष्टिः {
      WORD दीर्घता_2;
      WORD Flags;
      BYTE Text[1];
    } सन्देशः_RESOURCE_प्रविष्टिः_2,*PMESSAGE_RESOURCE_प्रविष्टिः;

#परिभाषय सन्देशः_RESOURCE_UNICODE 0x0001

    प्रकारनिर्देश संरचना सन्देशः_RESOURCE_खण्डम् {
      DWORD नीचः_Id;
      DWORD उच्चः_Id;
      DWORD विस्थापनम्_गन्तव्यम्_Entries;
    } सन्देशः_RESOURCE_खण्डम्_2,*PMESSAGE_RESOURCE_खण्डम्;

    प्रकारनिर्देश संरचना सन्देशः_RESOURCE_दत्त {
      DWORD सङ्ख्या_सम्बन्धि_खण्डानि;
      सन्देशः_RESOURCE_खण्डम्_2 खण्डानि_2[1];
    } सन्देशः_RESOURCE_दत्त_2,*PMESSAGE_RESOURCE_दत्त;

    प्रकारनिर्देश संरचना _OSVERSIONINFOA {
      DWORD dw_OSVersion_Info_आकार;
      DWORD dw_Major_संस्करणम्;
      DWORD dw_Minor_संस्करणम्;
      DWORD dw_Build_सङ्ख्या;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
    } OSVERSIONINFOA,*POSVERSIONINFOA,*LPOSVERSIONINFOA;

    प्रकारनिर्देश संरचना _OSVERSIONINFOW {
      DWORD dw_OSVersion_Info_आकार;
      DWORD dw_Major_संस्करणम्;
      DWORD dw_Minor_संस्करणम्;
      DWORD dw_Build_सङ्ख्या;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
    } OSVERSIONINFOW,*POSVERSIONINFOW,*LPOSVERSIONINFOW,RTL_OSVERSIONINFOW,*PRTL_OSVERSIONINFOW;

#यदि_परिभाषितम् UNICODE
    प्रकारनिर्देश OSVERSIONINFOW OSVERSIONINFO;
    प्रकारनिर्देश POSVERSIONINFOW POSVERSIONINFO;
    प्रकारनिर्देश LPOSVERSIONINFOW LPOSVERSIONINFO;
#अन्यथा
    प्रकारनिर्देश OSVERSIONINFOA OSVERSIONINFO;
    प्रकारनिर्देश POSVERSIONINFOA POSVERSIONINFO;
    प्रकारनिर्देश LPOSVERSIONINFOA LPOSVERSIONINFO;
#यदि_अन्तः

    प्रकारनिर्देश संरचना _OSVERSIONINFOEXA {
      DWORD dw_OSVersion_Info_आकार;
      DWORD dw_Major_संस्करणम्;
      DWORD dw_Minor_संस्करणम्;
      DWORD dw_Build_सङ्ख्या;
      DWORD dwPlatformId;
      CHAR szCSDVersion[128];
      WORD wServicePackMajor;
      WORD wServicePackMinor;
      WORD w_Suite_आवरणम्;
      BYTE w_गुणनफलम्_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXA,*POSVERSIONINFOEXA,*LPOSVERSIONINFOEXA;

    प्रकारनिर्देश संरचना _OSVERSIONINFOEXW {
      DWORD dw_OSVersion_Info_आकार;
      DWORD dw_Major_संस्करणम्;
      DWORD dw_Minor_संस्करणम्;
      DWORD dw_Build_सङ्ख्या;
      DWORD dwPlatformId;
      WCHAR szCSDVersion[128];
      WORD wServicePackMajor;
      WORD wServicePackMinor;
      WORD w_Suite_आवरणम्;
      BYTE w_गुणनफलम्_Type;
      BYTE wReserved;
    } OSVERSIONINFOEXW,*POSVERSIONINFOEXW,*LPOSVERSIONINFOEXW,RTL_OSVERSIONINFOEXW,*PRTL_OSVERSIONINFOEXW;
#यदि_परिभाषितम् UNICODE
    प्रकारनिर्देश OSVERSIONINFOEXW OSVERSIONINFOEX;
    प्रकारनिर्देश POSVERSIONINFOEXW POSVERSIONINFOEX;
    प्रकारनिर्देश LPOSVERSIONINFOEXW LPOSVERSIONINFOEX;
#अन्यथा
    प्रकारनिर्देश OSVERSIONINFOEXA OSVERSIONINFOEX;
    प्रकारनिर्देश POSVERSIONINFOEXA POSVERSIONINFOEX;
    प्रकारनिर्देश LPOSVERSIONINFOEXA LPOSVERSIONINFOEX;
#यदि_अन्तः

#परिभाषय VER_EQUAL 1
#परिभाषय VER_GREATER 2
#परिभाषय VER_GREATER_EQUAL 3
#परिभाषय VER_LESS 4
#परिभाषय VER_LESS_EQUAL 5
#परिभाषय VER_AND 6
#परिभाषय VER_OR 7

#परिभाषय VER_CONDITION_आवरणम् 7
#परिभाषय VER_अङ्कः_द्वयङ्काः_प्रत्येकम्_CONDITION_आवरणम् 3

#परिभाषय VER_MINORVERSION 0x0000001
#परिभाषय VER_MAJORVERSION 0x0000002
#परिभाषय VER_BUILDNUMBER 0x0000004
#परिभाषय VER_PLATFORMID 0x0000008
#परिभाषय VER_SERVICEPACKMINOR 0x0000010
#परिभाषय VER_SERVICEPACKMAJOR 0x0000020
#परिभाषय VER_SUITENAME 0x0000040
#परिभाषय VER_गुणनफलम्_TYPE 0x0000080

#परिभाषय VER_NT_WORKSTATION 0x0000001
#परिभाषय VER_NT_DOMAIN_CONTROLLER 0x0000002
#परिभाषय VER_NT_SERVER 0x0000003

#परिभाषय VER_PLATFORM_WIN32s 0
#परिभाषय VER_PLATFORM_WIN32_WINDOWS 1
#परिभाषय VER_PLATFORM_WIN32_NT 2

#परिभाषय VER_समुच्चयः_CONDITION(_m_,_t_,_c_) ((_m_)=Ver_समुच्चयः_Condition_आवरणम्((_m_),(_t_),(_c_)))

    NTSYSAPI ULONGLONG NTAPI Ver_समुच्चयः_Condition_आवरणम्(ULONGLONG Condition_आवरणम्,DWORD Type_आवरणम्,BYTE Condition);

    प्रकारनिर्देश संरचना _RTL_CRITICAL_SECTION_DEBUG {
      WORD Type;
      WORD Creator_पृष्ठभागः_Trace_सूचकांक;
      संरचना _RTL_CRITICAL_SECTION *CriticalSection;
      LIST_प्रविष्टिः_2 ProcessLocksList;
      DWORD प्रविष्टिः_गणनम्;
      DWORD Contention_गणनम्;
      DWORD अतिरिक्तः_2[2];
    } RTL_CRITICAL_SECTION_DEBUG,*PRTL_CRITICAL_SECTION_DEBUG,RTL_RESOURCE_DEBUG,*PRTL_RESOURCE_DEBUG;

#परिभाषय RTL_CRITSECT_TYPE 0
#परिभाषय RTL_RESOURCE_TYPE 1

    प्रकारनिर्देश संरचना _RTL_CRITICAL_SECTION {
      PRTL_CRITICAL_SECTION_DEBUG DebugInfo;
      LONG तालकम्_गणनम्;
      LONG Recursion_गणनम्;
      HANDLE OwningThread;
      HANDLE तालकम्_Semaphore;
      ULONG_PTR Spin_गणनम्;
    } RTL_CRITICAL_SECTION,*PRTL_CRITICAL_SECTION;

    प्रकारनिर्देश VOID (NTAPI *RTL_VERIFIER_DLL_आरोपय_CALLBACK) (PWSTR DllName,PVOID Dll_आधारः,आकार_T Dll_आकार,PVOID Reserved);
    प्रकारनिर्देश VOID (NTAPI *RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (PWSTR DllName,PVOID Dll_आधारः,आकार_T Dll_आकार,PVOID Reserved);
    प्रकारनिर्देश VOID (NTAPI *RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK)(PVOID आवण्टनम्_आधारः,आकार_T आवण्टनम्_आकार);

    प्रकारनिर्देश संरचना _RTL_VERIFIER_THUNK_DESCRIPTOR {
      PCHAR ThunkName;
      PVOID Thunk_Old_स्थानाङ्कः;
      PVOID Thunk_New_स्थानाङ्कः;
    } RTL_VERIFIER_THUNK_DESCRIPTOR,*PRTL_VERIFIER_THUNK_DESCRIPTOR;

    प्रकारनिर्देश संरचना _RTL_VERIFIER_DLL_DESCRIPTOR {
      PWCHAR DllName;
      DWORD DllFlags;
      PVOID Dll_स्थानाङ्कः;
      PRTL_VERIFIER_THUNK_DESCRIPTOR DllThunks;
    } RTL_VERIFIER_DLL_DESCRIPTOR,*PRTL_VERIFIER_DLL_DESCRIPTOR;

    प्रकारनिर्देश संरचना _RTL_VERIFIER_PROVIDER_DESCRIPTOR {
      DWORD दीर्घता_2;
      PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
      RTL_VERIFIER_DLL_आरोपय_CALLBACK Provider_Dll_आरोपय_Callback;
      RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;
      PWSTR VerifierImage;
      DWORD VerifierFlags;
      DWORD VerifierDebug;
      PVOID Rtlp_Get_राशिः_Trace_स्थानाङ्कः;
      PVOID RtlpDebugPageHeapCreate;
      PVOID RtlpDebugPageHeapDestroy;
      RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK ProviderNtdllHeapFreeCallback;
    } RTL_VERIFIER_PROVIDER_DESCRIPTOR,*PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

#परिभाषय RTL_VRF_FLG_पूर्णम्_PAGE_HEAP 0x00000001
#परिभाषय RTL_VRF_FLG_RESERVED_DONOTUSE 0x00000002
#परिभाषय RTL_VRF_FLG_HANDLE_CHECKS 0x00000004
#परिभाषय RTL_VRF_FLG_राशिः_CHECKS 0x00000008
#परिभाषय RTL_VRF_FLG_APPCOMPAT_CHECKS 0x00000010
#परिभाषय RTL_VRF_FLG_TLS_CHECKS 0x00000020
#परिभाषय RTL_VRF_FLG_DIRTY_STACKS 0x00000040
#परिभाषय RTL_VRF_FLG_RPC_CHECKS 0x00000080
#परिभाषय RTL_VRF_FLG_COM_CHECKS 0x00000100
#परिभाषय RTL_VRF_FLG_DANGEROUS_APIS 0x00000200
#परिभाषय RTL_VRF_FLG_RACE_CHECKS 0x00000400
#परिभाषय RTL_VRF_FLG_DEADLOCK_CHECKS 0x00000800
#परिभाषय RTL_VRF_FLG_FIRST_CHANCE_EXCEPTION_CHECKS 0x00001000
#परिभाषय RTL_VRF_FLG_VIRTUAL_MEM_CHECKS 0x00002000
#परिभाषय RTL_VRF_FLG_ENABLE_LOGGING 0x00004000
#परिभाषय RTL_VRF_FLG_FAST_FILL_HEAP 0x00008000
#परिभाषय RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING 0x00010000
#परिभाषय RTL_VRF_FLG_ENABLED_SYSTEM_WIDE 0x00020000
#परिभाषय RTL_VRF_FLG_MISCELLANEOUS_CHECKS 0x00020000
#परिभाषय RTL_VRF_FLG_तालकम्_CHECKS 0x00040000

#परिभाषय APPLICATION_VERIFIER_आन्तरिकम्_ERROR 0x80000000
#परिभाषय APPLICATION_VERIFIER_आन्तरिकम्_WARNING 0x40000000
#परिभाषय APPLICATION_VERIFIER_NO_BREAK 0x20000000
#परिभाषय APPLICATION_VERIFIER_CONTINUABLE_BREAK 0x10000000

#परिभाषय APPLICATION_VERIFIER_UNKNOWN_ERROR 0x0001
#परिभाषय APPLICATION_VERIFIER_ACCESS_VIOLATION 0x0002
#परिभाषय APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS 0x0003
#परिभाषय APPLICATION_VERIFIER_EXTREME_आकार_REQUEST 0x0004
#परिभाषय APPLICATION_VERIFIER_BAD_HEAP_HANDLE 0x0005
#परिभाषय APPLICATION_VERIFIER_SWITCHED_HEAP_HANDLE 0x0006
#परिभाषय APPLICATION_VERIFIER_DOUBLE_FREE 0x0007
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_HEAP_खण्डम् 0x0008
#परिभाषय APPLICATION_VERIFIER_DESTROY_PROCESS_HEAP 0x0009
#परिभाषय APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION 0x000A
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_HEAP_खण्डम्_EXCEPTION_RAISED_FOR_शीर्षकम् 0x000B
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_HEAP_खण्डम्_EXCEPTION_RAISED_FOR_PROBING 0x000C
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_HEAP_खण्डम्_शीर्षकम् 0x000D
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_FREED_HEAP_खण्डम् 0x000E
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_HEAP_खण्डम्_SUFFIX 0x000F
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_HEAP_खण्डम्_START_STAMP 0x0010
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_HEAP_खण्डम्_अन्तः_STAMP 0x0011
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_HEAP_खण्डम्_उपसर्गः 0x0012
#परिभाषय APPLICATION_VERIFIER_FIRST_CHANCE_ACCESS_VIOLATION 0x0013
#परिभाषय APPLICATION_VERIFIER_CORRUPTED_HEAP_LIST 0x0014

#परिभाषय APPLICATION_VERIFIER_TERMINATE_THREAD_CALL 0x0100
#परिभाषय APPLICATION_VERIFIER_राशिः_अतिप्रवाहः 0x0101
#परिभाषय APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL 0x0102

#परिभाषय APPLICATION_VERIFIER_EXIT_THREAD_OWNS_तालकम् 0x0200
#परिभाषय APPLICATION_VERIFIER_तालकम्_अन्तर्_UNLOADED_DLL 0x0201
#परिभाषय APPLICATION_VERIFIER_तालकम्_अन्तर्_FREED_HEAP 0x0202
#परिभाषय APPLICATION_VERIFIER_तालकम्_DOUBLE_INITIALIZE 0x0203
#परिभाषय APPLICATION_VERIFIER_तालकम्_अन्तर्_FREED_स्मृतिः 0x0204
#परिभाषय APPLICATION_VERIFIER_तालकम्_CORRUPTED 0x0205
#परिभाषय APPLICATION_VERIFIER_तालकम्_INVALID_OWNER 0x0206
#परिभाषय APPLICATION_VERIFIER_तालकम्_INVALID_RECURSION_गणनम् 0x0207
#परिभाषय APPLICATION_VERIFIER_तालकम्_INVALID_तालकम्_गणनम् 0x0208
#परिभाषय APPLICATION_VERIFIER_तालकम्_OVER_RELEASED 0x0209
#परिभाषय APPLICATION_VERIFIER_तालकम्_NOT_INITIALIZED 0x0210
#परिभाषय APPLICATION_VERIFIER_तालकम्_ALREADY_INITIALIZED 0x0211
#परिभाषय APPLICATION_VERIFIER_तालकम्_अन्तर्_FREED_VMEM 0x0212
#परिभाषय APPLICATION_VERIFIER_तालकम्_अन्तर्_UNMAPPED_MEM 0x0213
#परिभाषय APPLICATION_VERIFIER_THREAD_NOT_तालकम्_OWNER 0x0214

#परिभाषय APPLICATION_VERIFIER_INVALID_HANDLE 0x0300
#परिभाषय APPLICATION_VERIFIER_INVALID_TLS_मानम् 0x0301
#परिभाषय APPLICATION_VERIFIER_INCORRECT_WAIT_CALL 0x0302
#परिभाषय APPLICATION_VERIFIER_NULL_HANDLE 0x0303
#परिभाषय APPLICATION_VERIFIER_WAIT_अन्तर्_DLLMAIN 0x0304

#परिभाषय APPLICATION_VERIFIER_COM_ERROR 0x0400
#परिभाषय APPLICATION_VERIFIER_COM_API_अन्तर्_DLLMAIN 0x0401
#परिभाषय APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION 0x0402
#परिभाषय APPLICATION_VERIFIER_COM_UNBALANCED_COINIT 0x0403
#परिभाषय APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT 0x0404
#परिभाषय APPLICATION_VERIFIER_COM_UNBALANCED_SWC 0x0405
#परिभाषय APPLICATION_VERIFIER_COM_NULL_DACL 0x0406
#परिभाषय APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION 0x0407
#परिभाषय APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER 0x0408
#परिभाषय APPLICATION_VERIFIER_COM_SMUGGLED_PROXY 0x0409
#परिभाषय APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL 0x040A
#परिभाषय APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL 0x040B
#परिभाषय APPLICATION_VERIFIER_COM_OBJECT_अन्तर्_FREED_स्मृतिः 0x040C
#परिभाषय APPLICATION_VERIFIER_COM_OBJECT_अन्तर्_UNLOADED_DLL 0x040D
#परिभाषय APPLICATION_VERIFIER_COM_VTBL_अन्तर्_FREED_स्मृतिः 0x040E
#परिभाषय APPLICATION_VERIFIER_COM_VTBL_अन्तर्_UNLOADED_DLL 0x040F
#परिभाषय APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL 0x0410

#परिभाषय APPLICATION_VERIFIER_RPC_ERROR 0x0500

#परिभाषय APPLICATION_VERIFIER_INVALID_FREEMEM 0x0600
#परिभाषय APPLICATION_VERIFIER_INVALID_ALLOCMEM 0x0601
#परिभाषय APPLICATION_VERIFIER_INVALID_MAPVIEW 0x0602
#परिभाषय APPLICATION_VERIFIER_PROBE_INVALID_स्थानाङ्कः 0x0603
#परिभाषय APPLICATION_VERIFIER_PROBE_FREE_MEM 0x0604
#परिभाषय APPLICATION_VERIFIER_PROBE_GUARD_PAGE 0x0605
#परिभाषय APPLICATION_VERIFIER_PROBE_NULL 0x0606
#परिभाषय APPLICATION_VERIFIER_PROBE_INVALID_START_OR_आकार 0x0607
#परिभाषय APPLICATION_VERIFIER_आकार_HEAP_UNEXPECTED_EXCEPTION 0x0618

#परिभाषय VERIFIER_STOP(संहिता_4,सन्देशः_5,P1,S1,P2,S2,P3,S3,P4,S4) { RtlApplicationVerifierStop ((संहिता_4),(सन्देशः_5),(ULONG_PTR)(P1),(S1),(ULONG_PTR)(P2),(S2),(ULONG_PTR)(P3),(S3),(ULONG_PTR)(P4),(S4)); }

    VOID NTAPI RtlApplicationVerifierStop(ULONG_PTR संहिता_4,PSTR सन्देशः_6,ULONG_PTR Param1,PSTR Description1,ULONG_PTR Param2,PSTR Description2,ULONG_PTR Param3,PSTR Description3,ULONG_PTR Param4,PSTR Description4);

    प्रकारनिर्देश LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(संरचना EXCEPTION_सूचकाः_2 *ExceptionInfo);
#परिभाषय SEF_DACL_AUTO_INHERIT 0x01
#परिभाषय SEF_SACL_AUTO_INHERIT 0x02
#परिभाषय SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT 0x04
#परिभाषय SEF_AVOID_PRIVILEGE_CHECK 0x08
#परिभाषय SEF_AVOID_OWNER_CHECK 0x10
#परिभाषय SEF_DEFAULT_OWNER_FROM_PARENT 0x20
#परिभाषय SEF_DEFAULT_गणः_FROM_PARENT 0x40

    प्रकारनिर्देश गणना _HEAP_INFORMATION_CLASS {
      HeapCompatibilityInformation
    } HEAP_INFORMATION_CLASS;

    NTSYSAPI DWORD NTAPI Rtl_समुच्चयः_Heap_Information(PVOID HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,आकार_T Heap_Information_दीर्घता);
    NTSYSAPI DWORD NTAPI RtlQueryHeapInformation(PVOID HeapHandle,HEAP_INFORMATION_CLASS HeapInformationClass,PVOID HeapInformation,आकार_T Heap_Information_दीर्घता,PSIZE_T Return_दीर्घता);
    DWORD NTAPI Rtl_गुणजः_Allocate_Heap(PVOID HeapHandle,DWORD Flags,आकार_T आकार_3,DWORD गणनम्_3,PVOID *Array);
    DWORD NTAPI Rtl_गुणजः_Free_Heap(PVOID HeapHandle,DWORD Flags,DWORD गणनम्_3,PVOID *Array);

#परिभाषय WT_EXECUTEDEFAULT 0x00000000
#परिभाषय WT_EXECUTEINIOTHREAD 0x00000001
#परिभाषय WT_EXECUTEINUITHREAD 0x00000002
#परिभाषय WT_EXECUTEINWAITTHREAD 0x00000004
#परिभाषय WT_EXECUTEONLYONCE 0x00000008
#परिभाषय WT_EXECUTEINTIMERTHREAD 0x00000020
#परिभाषय WT_EXECUTELONGFUNCTION 0x00000010
#परिभाषय WT_EXECUTEINPERSISTENTIOTHREAD 0x00000040
#परिभाषय WT_EXECUTEINPERSISTENTTHREAD 0x00000080
#परिभाषय WT_TRANSFER_IMPERSONATION 0x00000100
#परिभाषय WT_समुच्चयः_MAX_THREADPOOL_तन्तवः(Flags,सीमा_2) ((Flags) |= (सीमा_2)<<16)
    प्रकारनिर्देश VOID (NTAPI *WAITORTIMERCALLBACKFUNC)(PVOID,BOOLEAN);
    प्रकारनिर्देश VOID (NTAPI *WORKERCALLBACKFUNC)(PVOID);
    प्रकारनिर्देश VOID (NTAPI *APC_CALLBACK_FUNCTION)(DWORD ,PVOID,PVOID);
    प्रकारनिर्देश
      VOID
      (NTAPI *PFLS_CALLBACK_FUNCTION)(PVOID lp_Fls_दत्त);
#परिभाषय WT_EXECUTEINLONGTHREAD 0x00000010
#परिभाषय WT_EXECUTEDELETEWAIT 0x00000008

    प्रकारनिर्देश गणना _ACTIVATION_CONTEXT_INFO_CLASS {
      ActivationContextBasicInformation = 1,ActivationContextDetailedInformation = 2,Assembly_Detailed_Information_अन्तर्_Activation_Context = 3,File_Information_अन्तर्_Assembly_सम्बन्धि_Assembly_अन्तर्_Activation_Context = 4,MaxActivationContextInfoClass,Assembly_Detailed_Information_अन्तर्_Activation_Contxt = 3,File_Information_अन्तर्_Assembly_सम्बन्धि_Assembly_अन्तर्_Activation_Contxt = 4
    } ACTIVATION_CONTEXT_INFO_CLASS;

#परिभाषय ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

    प्रकारनिर्देश संरचना ACTIVATION_CONTEXT_QUERY_सूचकांक {
      DWORD ul_Assembly_सूचकांक;
      DWORD ul_File_सूचकांक_अन्तर्_Assembly;
    } ACTIVATION_CONTEXT_QUERY_सूचकांक_2,*PACTIVATION_CONTEXT_QUERY_सूचकांक;

    प्रकारनिर्देश ध्रुव संरचना ACTIVATION_CONTEXT_QUERY_सूचकांक *PCACTIVATION_CONTEXT_QUERY_सूचकांक;

#परिभाषय ACTIVATION_CONTEXT_मार्गः_TYPE_NONE (1)
#परिभाषय ACTIVATION_CONTEXT_मार्गः_TYPE_WIN32_FILE (2)
#परिभाषय ACTIVATION_CONTEXT_मार्गः_TYPE_URL (3)
#परिभाषय ACTIVATION_CONTEXT_मार्गः_TYPE_ASSEMBLYREF (4)

    प्रकारनिर्देश संरचना _ASSEMBLY_FILE_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Filename_दीर्घता;
      DWORD ul_मार्गः_दीर्घता;

      PCWSTR lpFileName;
      PCWSTR lp_File_मार्गः;
    } ASSEMBLY_FILE_DETAILED_INFORMATION,*PASSEMBLY_FILE_DETAILED_INFORMATION;
    प्रकारनिर्देश ध्रुव ASSEMBLY_FILE_DETAILED_INFORMATION *PCASSEMBLY_FILE_DETAILED_INFORMATION;

#परिभाषय _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION _ASSEMBLY_FILE_DETAILED_INFORMATION
#परिभाषय ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION ASSEMBLY_FILE_DETAILED_INFORMATION
#परिभाषय PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PASSEMBLY_FILE_DETAILED_INFORMATION
#परिभाषय PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

    प्रकारनिर्देश संरचना _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
      DWORD ulFlags;
      DWORD ul_Encoded_Assembly_तटस्थः_दीर्घता;
      DWORD ul_Manifest_मार्गः_Type;
      DWORD ul_Manifest_मार्गः_दीर्घता;
      LARGE_INTEGER li_Manifest_चरमः_Write_Time;
      DWORD ul_Policy_मार्गः_Type;
      DWORD ul_Policy_मार्गः_दीर्घता;
      LARGE_INTEGER li_Policy_चरमः_Write_Time;
      DWORD ul_Metadata_Satellite_Roster_सूचकांक;
      DWORD ul_Manifest_संस्करणम्_Major;
      DWORD ul_Manifest_संस्करणम्_Minor;
      DWORD ul_Policy_संस्करणम्_Major;
      DWORD ul_Policy_संस्करणम्_Minor;
      DWORD ul_Assembly_Directory_Name_दीर्घता;
      PCWSTR lp_Assembly_Encoded_Assembly_तटस्थः;
      PCWSTR lp_Assembly_Manifest_मार्गः;
      PCWSTR lp_Assembly_Policy_मार्गः;
      PCWSTR lpAssemblyDirectoryName;
      DWORD ul_File_गणनम्;
    } ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    प्रकारनिर्देश ध्रुव संरचना _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

    प्रकारनिर्देश संरचना _ACTIVATION_CONTEXT_DETAILED_INFORMATION {
      DWORD dwFlags;
      DWORD ul_Format_संस्करणम्;
      DWORD ul_Assembly_गणनम्;
      DWORD ul_मूलम्_Manifest_मार्गः_Type;
      DWORD ul_मूलम्_Manifest_मार्गः_Chars;
      DWORD ul_मूलम्_Configuration_मार्गः_Type;
      DWORD ul_मूलम्_Configuration_मार्गः_Chars;
      DWORD ul_App_Dir_मार्गः_Type;
      DWORD ul_App_Dir_मार्गः_Chars;
      PCWSTR lp_मूलम्_Manifest_मार्गः;
      PCWSTR lp_मूलम्_Configuration_मार्गः;
      PCWSTR lp_App_Dir_मार्गः;
    } ACTIVATION_CONTEXT_DETAILED_INFORMATION,*PACTIVATION_CONTEXT_DETAILED_INFORMATION;

    प्रकारनिर्देश ध्रुव संरचना _ACTIVATION_CONTEXT_DETAILED_INFORMATION *PCACTIVATION_CONTEXT_DETAILED_INFORMATION;

#परिभाषय DLL_PROCESS_ATTACH 1
#परिभाषय DLL_THREAD_ATTACH 2
#परिभाषय DLL_THREAD_DETACH 3
#परिभाषय DLL_PROCESS_DETACH 0
#परिभाषय DLL_PROCESS_VERIFIER 4

#परिभाषय EVENTLOG_SEQUENTIAL_READ 0x0001
#परिभाषय EVENTLOG_SEEK_READ 0x0002
#परिभाषय EVENTLOG_FORWARDS_READ 0x0004
#परिभाषय EVENTLOG_BACKWARDS_READ 0x0008

#परिभाषय EVENTLOG_SUCCESS 0x0000
#परिभाषय EVENTLOG_ERROR_TYPE 0x0001
#परिभाषय EVENTLOG_WARNING_TYPE 0x0002
#परिभाषय EVENTLOG_INFORMATION_TYPE 0x0004
#परिभाषय EVENTLOG_AUDIT_SUCCESS 0x0008
#परिभाषय EVENTLOG_AUDIT_FAILURE 0x0010

#परिभाषय EVENTLOG_START_PAIRED_EVENT 0x0001
#परिभाषय EVENTLOG_अन्तः_PAIRED_EVENT 0x0002
#परिभाषय EVENTLOG_अन्तः_ALL_PAIRED_EVENTS 0x0004
#परिभाषय EVENTLOG_PAIRED_EVENT_सक्रिय 0x0008
#परिभाषय EVENTLOG_PAIRED_EVENT_INACTIVE 0x0010

    प्रकारनिर्देश संरचना _EVENTLOGRECORD {
      DWORD दीर्घता_2;
      DWORD Reserved;
      DWORD लेखः_सङ्ख्या;
      DWORD TimeGenerated;
      DWORD TimeWritten;
      DWORD EventID;
      WORD EventType;
      WORD अङ्कः_वाक्यानि;
      WORD EventCategory;
      WORD ReservedFlags;
      DWORD Closing_लेखः_सङ्ख्या;
      DWORD String_विस्थापनम्;
      DWORD User_Sid_दीर्घता;
      DWORD User_Sid_विस्थापनम्;
      DWORD दत्त_दीर्घता;
      DWORD दत्त_विस्थापनम्_2;
    } EVENTLOGRECORD,*PEVENTLOGRECORD;

#परिभाषय MAXLOGICALLOGNAMESIZE 256

    प्रकारनिर्देश संरचना _EVENTSFORLOGFILE{
      DWORD ul_आकार;
      WCHAR szLogicalLogFile[MAXLOGICALLOGNAMESIZE];
      DWORD ul_अङ्कः_लेखाः;
      EVENTLOGRECORD p_Event_Log_लेखाः[];
    } EVENTSFORLOGFILE,*PEVENTSFORLOGFILE;

    प्रकारनिर्देश संरचना _PACKEDEVENTINFO{
      DWORD ul_आकार;
      DWORD ul_अङ्कः_Events_For_Log_File;
      DWORD ulOffsets[];
    } PACKEDEVENTINFO,*PPACKEDEVENTINFO;

#परिभाषय कुञ्चिका_QUERY_मानम् (0x0001)
#परिभाषय कुञ्चिका_समुच्चयः_मानम् (0x0002)
#परिभाषय कुञ्चिका_CREATE_SUB_कुञ्चिका (0x0004)
#परिभाषय कुञ्चिका_ENUMERATE_SUB_कुञ्चिकाः (0x0008)
#परिभाषय कुञ्चिका_NOTIFY (0x0010)
#परिभाषय कुञ्चिका_CREATE_LINK (0x0020)
#परिभाषय कुञ्चिका_WOW64_32_कुञ्चिका (0x0200)
#परिभाषय कुञ्चिका_WOW64_64_कुञ्चिका (0x0100)
#परिभाषय कुञ्चिका_WOW64_RES (0x0300)

#परिभाषय कुञ्चिका_READ ((STANDARD_RIGHTS_READ | कुञ्चिका_QUERY_मानम् | कुञ्चिका_ENUMERATE_SUB_कुञ्चिकाः | कुञ्चिका_NOTIFY) & (~SYNCHRONIZE))
#परिभाषय कुञ्चिका_WRITE ((STANDARD_RIGHTS_WRITE | कुञ्चिका_समुच्चयः_मानम् | कुञ्चिका_CREATE_SUB_कुञ्चिका) & (~SYNCHRONIZE))
#परिभाषय कुञ्चिका_EXECUTE ((कुञ्चिका_READ) & (~SYNCHRONIZE))
#परिभाषय कुञ्चिका_ALL_ACCESS ((STANDARD_RIGHTS_ALL | कुञ्चिका_QUERY_मानम् | कुञ्चिका_समुच्चयः_मानम् | कुञ्चिका_CREATE_SUB_कुञ्चिका | कुञ्चिका_ENUMERATE_SUB_कुञ्चिकाः | कुञ्चिका_NOTIFY | कुञ्चिका_CREATE_LINK) & (~SYNCHRONIZE))
#परिभाषय REG_OPTION_RESERVED (0x00000000L)

#परिभाषय REG_OPTION_NON_VOLATILE (0x00000000L)
#परिभाषय REG_OPTION_VOLATILE (0x00000001L)
#परिभाषय REG_OPTION_CREATE_LINK (0x00000002L)
#परिभाषय REG_OPTION_BACKUP_RESTORE (0x00000004L)
#परिभाषय REG_OPTION_OPEN_LINK (0x00000008L)
#परिभाषय REG_LEGAL_OPTION (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)
#परिभाषय REG_CREATED_NEW_कुञ्चिका (0x00000001L)
#परिभाषय REG_OPENED_EXISTING_कुञ्चिका (0x00000002L)
#परिभाषय REG_STANDARD_FORMAT 1
#परिभाषय REG_LATEST_FORMAT 2
#परिभाषय REG_NO_COMPRESSION 4
#परिभाषय REG_सम्पूर्णम्_HIVE_VOLATILE (0x00000001L)
#परिभाषय REG_REFRESH_HIVE (0x00000002L)
#परिभाषय REG_NO_LAZY_FLUSH (0x00000004L)
#परिभाषय REG_FORCE_RESTORE (0x00000008L)
#परिभाषय REG_FORCE_UNLOAD 1

#परिभाषय REG_NOTIFY_CHANGE_NAME (0x00000001L)
#परिभाषय REG_NOTIFY_CHANGE_गुणाः (0x00000002L)
#परिभाषय REG_NOTIFY_CHANGE_चरमः_समुच्चयः (0x00000004L)
#परिभाषय REG_NOTIFY_CHANGE_SECURITY (0x00000008L)

#परिभाषय REG_LEGAL_CHANGE_FILTER (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_गुणाः | REG_NOTIFY_CHANGE_चरमः_समुच्चयः | REG_NOTIFY_CHANGE_SECURITY)

#परिभाषय REG_NONE (0)
#परिभाषय REG_SZ (1)
#परिभाषय REG_EXPAND_SZ (2)

#परिभाषय REG_द्विमान (3)
#परिभाषय REG_DWORD (4)
#परिभाषय REG_DWORD_LITTLE_ENDIAN (4)
#परिभाषय REG_DWORD_BIG_ENDIAN (5)
#परिभाषय REG_LINK (6)
#परिभाषय REG_MULTI_SZ (7)
#परिभाषय REG_RESOURCE_LIST (8)
#परिभाषय REG_पूर्णम्_RESOURCE_DESCRIPTOR (9)
#परिभाषय REG_RESOURCE_REQUIREMENTS_LIST (10)
#परिभाषय REG_QWORD (11)
#परिभाषय REG_QWORD_LITTLE_ENDIAN (11)

#परिभाषय SERVICE_KERNEL_DRIVER 0x00000001
#परिभाषय SERVICE_FILE_SYSTEM_DRIVER 0x00000002
#परिभाषय SERVICE_ADAPTER 0x00000004
#परिभाषय SERVICE_RECOGNIZER_DRIVER 0x00000008

#परिभाषय SERVICE_DRIVER (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

#परिभाषय SERVICE_WIN32_OWN_PROCESS 0x00000010
#परिभाषय SERVICE_WIN32_SHARE_PROCESS 0x00000020
#परिभाषय SERVICE_WIN32 (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

#परिभाषय SERVICE_INTERACTIVE_PROCESS 0x00000100

#परिभाषय SERVICE_TYPE_ALL (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

#परिभाषय SERVICE_BOOT_START 0x00000000
#परिभाषय SERVICE_SYSTEM_START 0x00000001
#परिभाषय SERVICE_AUTO_START 0x00000002
#परिभाषय SERVICE_DEMAND_START 0x00000003
#परिभाषय SERVICE_DISABLED 0x00000004

#परिभाषय SERVICE_ERROR_IGNORE 0x00000000
#परिभाषय SERVICE_ERROR_प्रसामान्यम् 0x00000001
#परिभाषय SERVICE_ERROR_SEVERE 0x00000002
#परिभाषय SERVICE_ERROR_CRITICAL 0x00000003

    प्रकारनिर्देश गणना CM_SERVICE_ग्रन्थिः_TYPE {
      DriverType = SERVICE_KERNEL_DRIVER,FileSystemType = SERVICE_FILE_SYSTEM_DRIVER,Win32ServiceOwnProcess = SERVICE_WIN32_OWN_PROCESS,
      Win32ServiceShareProcess = SERVICE_WIN32_SHARE_PROCESS,AdapterType = SERVICE_ADAPTER,RecognizerType = SERVICE_RECOGNIZER_DRIVER
    } SERVICE_ग्रन्थिः_TYPE;

    प्रकारनिर्देश गणना CM_SERVICE_आरोपय_TYPE {
      Boot_आरोपय = SERVICE_BOOT_START,System_आरोपय = SERVICE_SYSTEM_START,Auto_आरोपय = SERVICE_AUTO_START,Demand_आरोपय = SERVICE_DEMAND_START,
      Disable_आरोपय = SERVICE_DISABLED
    } SERVICE_आरोपय_TYPE;

    प्रकारनिर्देश गणना _CM_ERROR_CONTROL_TYPE {
      IgnoreError = SERVICE_ERROR_IGNORE,प्रसामान्यम्_Error = SERVICE_ERROR_प्रसामान्यम्,SevereError = SERVICE_ERROR_SEVERE,CriticalError = SERVICE_ERROR_CRITICAL
    } SERVICE_ERROR_TYPE;

#परिभाषय पट्टिका_ERASE_SHORT 0L
#परिभाषय पट्टिका_ERASE_LONG 1L

    प्रकारनिर्देश संरचना पट्टिका_ERASE {
      DWORD Type;
      BOOLEAN तात्कालिकम्_2;
    } पट्टिका_ERASE_2,*PTAPE_ERASE;

#परिभाषय पट्टिका_आरोपय 0L
#परिभाषय पट्टिका_UNLOAD 1L
#परिभाषय पट्टिका_TENSION 2L
#परिभाषय पट्टिका_तालकम् 3L
#परिभाषय पट्टिका_UNLOCK 4L
#परिभाषय पट्टिका_FORMAT 5L

    प्रकारनिर्देश संरचना पट्टिका_PREPARE {
      DWORD Operation;
      BOOLEAN तात्कालिकम्_2;
    } पट्टिका_PREPARE_2,*PTAPE_PREPARE;

#परिभाषय पट्टिका_SETMARKS 0L
#परिभाषय पट्टिका_FILEMARKS 1L
#परिभाषय पट्टिका_SHORT_FILEMARKS 2L
#परिभाषय पट्टिका_LONG_FILEMARKS 3L

    प्रकारनिर्देश संरचना पट्टिका_WRITE_MARKS {
      DWORD Type;
      DWORD गणनम्_3;
      BOOLEAN तात्कालिकम्_2;
    } पट्टिका_WRITE_MARKS_2,*PTAPE_WRITE_MARKS;

#परिभाषय पट्टिका_ABSOLUTE_POSITION 0L
#परिभाषय पट्टिका_LOGICAL_POSITION 1L
#परिभाषय पट्टिका_PSEUDO_LOGICAL_POSITION 2L

    प्रकारनिर्देश संरचना पट्टिका_GET_POSITION {
      DWORD Type;
      DWORD Partition;
      LARGE_INTEGER विस्थापनम्_3;
    } पट्टिका_GET_POSITION_2,*PTAPE_GET_POSITION;

#परिभाषय पट्टिका_REWIND 0L
#परिभाषय पट्टिका_ABSOLUTE_खण्डम् 1L
#परिभाषय पट्टिका_LOGICAL_खण्डम् 2L
#परिभाषय पट्टिका_PSEUDO_LOGICAL_खण्डम् 3L
#परिभाषय पट्टिका_SPACE_अन्तः_सम्बन्धि_दत्त 4L
#परिभाषय पट्टिका_SPACE_RELATIVE_खण्डानि 5L
#परिभाषय पट्टिका_SPACE_FILEMARKS 6L
#परिभाषय पट्टिका_SPACE_SEQUENTIAL_FMKS 7L
#परिभाषय पट्टिका_SPACE_SETMARKS 8L
#परिभाषय पट्टिका_SPACE_SEQUENTIAL_SMKS 9L

    प्रकारनिर्देश संरचना पट्टिका_समुच्चयः_POSITION {
      DWORD विधानम्_2;
      DWORD Partition;
      LARGE_INTEGER विस्थापनम्_3;
      BOOLEAN तात्कालिकम्_2;
    } पट्टिका_समुच्चयः_POSITION_2,*PTAPE_समुच्चयः_POSITION;

#परिभाषय पट्टिका_DRIVE_FIXED 0x00000001
#परिभाषय पट्टिका_DRIVE_SELECT 0x00000002
#परिभाषय पट्टिका_DRIVE_INITIATOR 0x00000004

#परिभाषय पट्टिका_DRIVE_ERASE_SHORT 0x00000010
#परिभाषय पट्टिका_DRIVE_ERASE_LONG 0x00000020
#परिभाषय पट्टिका_DRIVE_ERASE_BOP_ONLY 0x00000040
#परिभाषय पट्टिका_DRIVE_ERASE_तात्कालिकम् 0x00000080

#परिभाषय पट्टिका_DRIVE_पट्टिका_क्षमता 0x00000100
#परिभाषय पट्टिका_DRIVE_पट्टिका_REMAINING 0x00000200
#परिभाषय पट्टिका_DRIVE_FIXED_खण्डम् 0x00000400
#परिभाषय पट्टिका_DRIVE_VARIABLE_खण्डम् 0x00000800

#परिभाषय पट्टिका_DRIVE_WRITE_PROTECT 0x00001000
#परिभाषय पट्टिका_DRIVE_EOT_WZ_आकार 0x00002000

#परिभाषय पट्टिका_DRIVE_ECC 0x00010000
#परिभाषय पट्टिका_DRIVE_COMPRESSION 0x00020000
#परिभाषय पट्टिका_DRIVE_PADDING 0x00040000
#परिभाषय पट्टिका_DRIVE_REPORT_SMKS 0x00080000

#परिभाषय पट्टिका_DRIVE_GET_ABSOLUTE_BLK 0x00100000
#परिभाषय पट्टिका_DRIVE_GET_LOGICAL_BLK 0x00200000
#परिभाषय पट्टिका_DRIVE_समुच्चयः_EOT_WZ_आकार 0x00400000

#परिभाषय पट्टिका_DRIVE_EJECT_MEDIA 0x01000000
#परिभाषय पट्टिका_DRIVE_CLEAN_अनुरोधाः 0x02000000
#परिभाषय पट्टिका_DRIVE_समुच्चयः_CMP_BOP_ONLY 0x04000000

#परिभाषय पट्टिका_DRIVE_RESERVED_BIT 0x80000000

#परिभाषय पट्टिका_DRIVE_आरोपय_UNLOAD 0x80000001
#परिभाषय पट्टिका_DRIVE_TENSION 0x80000002
#परिभाषय पट्टिका_DRIVE_तालकम्_UNLOCK 0x80000004
#परिभाषय पट्टिका_DRIVE_REWIND_तात्कालिकम् 0x80000008

#परिभाषय पट्टिका_DRIVE_समुच्चयः_खण्डम्_आकार 0x80000010
#परिभाषय पट्टिका_DRIVE_आरोपय_UNLD_IMMED 0x80000020
#परिभाषय पट्टिका_DRIVE_TENSION_IMMED 0x80000040
#परिभाषय पट्टिका_DRIVE_तालकम्_UNLK_IMMED 0x80000080

#परिभाषय पट्टिका_DRIVE_समुच्चयः_ECC 0x80000100
#परिभाषय पट्टिका_DRIVE_समुच्चयः_COMPRESSION 0x80000200
#परिभाषय पट्टिका_DRIVE_समुच्चयः_PADDING 0x80000400
#परिभाषय पट्टिका_DRIVE_समुच्चयः_REPORT_SMKS 0x80000800

#परिभाषय पट्टिका_DRIVE_ABSOLUTE_BLK 0x80001000
#परिभाषय पट्टिका_DRIVE_ABS_BLK_IMMED 0x80002000
#परिभाषय पट्टिका_DRIVE_LOGICAL_BLK 0x80004000
#परिभाषय पट्टिका_DRIVE_LOG_BLK_IMMED 0x80008000

#परिभाषय पट्टिका_DRIVE_अन्तः_सम्बन्धि_दत्त 0x80010000
#परिभाषय पट्टिका_DRIVE_RELATIVE_BLKS 0x80020000
#परिभाषय पट्टिका_DRIVE_FILEMARKS 0x80040000
#परिभाषय पट्टिका_DRIVE_SEQUENTIAL_FMKS 0x80080000

#परिभाषय पट्टिका_DRIVE_SETMARKS 0x80100000
#परिभाषय पट्टिका_DRIVE_SEQUENTIAL_SMKS 0x80200000
#परिभाषय पट्टिका_DRIVE_REVERSE_POSITION 0x80400000
#परिभाषय पट्टिका_DRIVE_SPACE_तात्कालिकम् 0x80800000

#परिभाषय पट्टिका_DRIVE_WRITE_SETMARKS 0x81000000
#परिभाषय पट्टिका_DRIVE_WRITE_FILEMARKS 0x82000000
#परिभाषय पट्टिका_DRIVE_WRITE_SHORT_FMKS 0x84000000
#परिभाषय पट्टिका_DRIVE_WRITE_LONG_FMKS 0x88000000

#परिभाषय पट्टिका_DRIVE_WRITE_MARK_IMMED 0x90000000
#परिभाषय पट्टिका_DRIVE_FORMAT 0xA0000000
#परिभाषय पट्टिका_DRIVE_FORMAT_तात्कालिकम् 0xC0000000
#परिभाषय पट्टिका_DRIVE_उच्चः_FEATURES 0x80000000

    प्रकारनिर्देश संरचना पट्टिका_GET_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN दत्त_Padding;
      BOOLEAN ReportSetmarks;
      DWORD Default_खण्डम्_आकार;
      DWORD अधिकतमम्_खण्डम्_आकार;
      DWORD Minimum_खण्डम्_आकार;
      DWORD अधिकतमम्_Partition_गणनम्;
      DWORD Features_नीचः;
      DWORD Features_उच्चः;
      DWORD EOTWarning_Zone_आकार;
    } पट्टिका_GET_DRIVE_PARAMETERS_2,*PTAPE_GET_DRIVE_PARAMETERS;

    प्रकारनिर्देश संरचना पट्टिका_समुच्चयः_DRIVE_PARAMETERS {
      BOOLEAN ECC;
      BOOLEAN Compression;
      BOOLEAN दत्त_Padding;
      BOOLEAN ReportSetmarks;
      DWORD EOTWarning_Zone_आकार;
    } पट्टिका_समुच्चयः_DRIVE_PARAMETERS_2,*PTAPE_समुच्चयः_DRIVE_PARAMETERS;

    प्रकारनिर्देश संरचना पट्टिका_GET_MEDIA_PARAMETERS {
      LARGE_INTEGER क्षमता;
      LARGE_INTEGER Remaining;
      DWORD खण्डम्_आकार;
      DWORD Partition_गणनम्;
      BOOLEAN WriteProtected;
    } पट्टिका_GET_MEDIA_PARAMETERS_2,*PTAPE_GET_MEDIA_PARAMETERS;

    प्रकारनिर्देश संरचना पट्टिका_समुच्चयः_MEDIA_PARAMETERS {
      DWORD खण्डम्_आकार;
    } पट्टिका_समुच्चयः_MEDIA_PARAMETERS_2,*PTAPE_समुच्चयः_MEDIA_PARAMETERS;

#परिभाषय पट्टिका_FIXED_PARTITIONS 0L
#परिभाषय पट्टिका_SELECT_PARTITIONS 1L
#परिभाषय पट्टिका_INITIATOR_PARTITIONS 2L

    प्रकारनिर्देश संरचना पट्टिका_CREATE_PARTITION {
      DWORD विधानम्_2;
      DWORD गणनम्_3;
      DWORD आकार_3;
    } पट्टिका_CREATE_PARTITION_2,*PTAPE_CREATE_PARTITION;

#परिभाषय पट्टिका_QUERY_DRIVE_PARAMETERS 0L
#परिभाषय पट्टिका_QUERY_MEDIA_क्षमता 1L
#परिभाषय पट्टिका_CHECK_FOR_DRIVE_PROBLEM 2L
#परिभाषय पट्टिका_QUERY_IO_ERROR_दत्त 3L
#परिभाषय पट्टिका_QUERY_DEVICE_ERROR_दत्त 4L

    प्रकारनिर्देश संरचना पट्टिका_WMI_OPERATIONS {
      DWORD विधानम्_2;
      DWORD दत्त_बफर_आकार;
      PVOID दत्त_बफर;
    } पट्टिका_WMI_OPERATIONS_2,*PTAPE_WMI_OPERATIONS;

    प्रकारनिर्देश गणना पट्टिका_DRIVE_PROBLEM_TYPE {
      पट्टिका_Drive_Problem_None,पट्टिका_Drive_Read_Write_Warning,पट्टिका_Drive_Read_Write_Error,पट्टिका_Drive_Read_Warning,पट्टिका_Drive_Write_Warning,पट्टिका_Drive_Read_Error,पट्टिका_Drive_Write_Error,पट्टिका_Drive_Hardware_Error,पट्टिका_Drive_Unsupported_Media,पट्टिका_Drive_Scsi_Connection_Error,पट्टिका_Drive_Timeto_Clean,पट्टिका_Drive_Clean_Drive_Now,पट्टिका_Drive_Media_Life_Expired,पट्टिका_Drive_Snapped_पट्टिका
    } पट्टिका_DRIVE_PROBLEM_TYPE_2;

#यदि defined(__x86_64)
    __CRT_INLINE संरचना _TEB *NtCurrentTeb(VOID) { प्रत्यागम (संरचना _TEB *)__readgsqword(क्षेत्रम्_विस्थापनम्(NT_TIB,Self)); }
    __CRT_INLINE PVOID GetCurrentFiber(VOID) { प्रत्यागम(PVOID)__readgsqword(क्षेत्रम्_विस्थापनम्(NT_TIB,Fiber_दत्त)); }
    __CRT_INLINE PVOID Get_Fiber_दत्त(VOID) {
      प्रत्यागम *(PVOID *)GetCurrentFiber();
    }
#यदि_अन्तः

#यदि(defined(_X86_) && !defined(__x86_64))
#परिभाषय PcTeb 0x18
    __CRT_INLINE संरचना _TEB *NtCurrentTeb(शून्य) {
      संरचना _TEB *ret;
      __asm__ चञ्चल ("movl	%%fs:0x18,%0"
	: "=r" (ret));
      प्रत्यागम ret;
    }
#यदि_अन्तः

#परिभाषय ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION (1)
#परिभाषय ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION (2)
#परिभाषय ACTIVATION_CONTEXT_SECTION_गवाक्षः_CLASS_REDIRECTION (3)
#परिभाषय ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION (4)
#परिभाषय ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION (5)
#परिभाषय ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION (6)
#परिभाषय ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION (7)
#परिभाषय ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_सारणी (8)
#परिभाषय ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES (9)
#परिभाषय ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS (10)

#यदि_परिभाषितम् __cplusplus
  }
#यदि_अन्तः
#यदि_अन्तः
